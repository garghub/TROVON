int BN_kronecker(const BIGNUM *a, const BIGNUM *b, BN_CTX *ctx)
{
int i;
int ret = -2;
int err = 0;
BIGNUM *A, *B, *tmp;
static const int tab[8] = { 0, 1, 0, -1, 0, -1, 0, 1 };
bn_check_top(a);
bn_check_top(b);
BN_CTX_start(ctx);
A = BN_CTX_get(ctx);
B = BN_CTX_get(ctx);
if (B == NULL)
goto end;
err = !BN_copy(A, a);
if (err)
goto end;
err = !BN_copy(B, b);
if (err)
goto end;
if (BN_is_zero(B)) {
ret = BN_abs_is_word(A, 1);
goto end;
}
if (!BN_is_odd(A) && !BN_is_odd(B)) {
ret = 0;
goto end;
}
i = 0;
while (!BN_is_bit_set(B, i))
i++;
err = !BN_rshift(B, B, i);
if (err)
goto end;
if (i & 1) {
ret = tab[BN_lsw(A) & 7];
} else {
ret = 1;
}
if (B->neg) {
B->neg = 0;
if (A->neg)
ret = -ret;
}
while (1) {
if (BN_is_zero(A)) {
ret = BN_is_one(B) ? ret : 0;
goto end;
}
i = 0;
while (!BN_is_bit_set(A, i))
i++;
err = !BN_rshift(A, A, i);
if (err)
goto end;
if (i & 1) {
ret = ret * tab[BN_lsw(B) & 7];
}
if ((A->neg ? ~BN_lsw(A) : BN_lsw(A)) & BN_lsw(B) & 2)
ret = -ret;
err = !BN_nnmod(B, B, A, ctx);
if (err)
goto end;
tmp = A;
A = B;
B = tmp;
tmp->neg = 0;
}
end:
BN_CTX_end(ctx);
if (err)
return -2;
else
return ret;
}
