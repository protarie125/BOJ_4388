#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	string a, b;
	cin >> a >> b;
	while ("0" != a || "0" != b) {
		reverse(a.begin(), a.end());
		const auto& alen = a.length();

		reverse(b.begin(), b.end());
		const auto& blen = b.length();

		auto ans = int{ 0 };
		auto carry = int{ 0 };
		if (alen < blen) {
			for (int i = 0; i < alen; ++i) {
				const auto& aval = a[i] - '0';
				const auto& bval = b[i] - '0';

				if (10 <= aval + bval + carry) {
					ans += 1;
					carry = 1;
				}
				else {
					carry = 0;
				}
			}

			auto j = alen;
			while (1 == carry) {
				if (1 == carry && 9 == b[j] - '0') {
					ans += 1;
				}
				else {
					carry = 0;
				}

				++j;
			}
		}
		else if (blen < alen) {
			for (int i = 0; i < blen; ++i) {
				const auto& aval = a[i] - '0';
				const auto& bval = b[i] - '0';

				if (10 <= aval + bval + carry) {
					ans += 1;
					carry = 1;
				}
				else {
					carry = 0;
				}
			}

			auto j = blen;
			while (1 == carry) {
				if (1 == carry && 9 == a[j] - '0') {
					ans += 1;
				}
				else {
					carry = 0;
				}

				++j;
			}
		}
		else {
			for (int i = 0; i < alen; ++i) {
				const auto& aval = a[i] - '0';
				const auto& bval = b[i] - '0';

				if (10 <= aval + bval + carry) {
					ans += 1;
					carry = 1;
				}
				else {
					carry = 0;
				}
			}
		}

		cout << ans << '\n';

		cin >> a >> b;
	}

	return 0;
}