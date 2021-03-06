static inline gf
modnn(int x)
{
while (x >= NN) {
x -= NN;
x = (x >> MM) + (x & NN);
}
return x;
}
static void
generate_gf(dtype Alpha_to[NN + 1], dtype Index_of[NN + 1])
{
register int i, mask;
mask = 1;
Alpha_to[MM] = 0;
for (i = 0; i < MM; i++) {
Alpha_to[i] = mask;
Index_of[Alpha_to[i]] = i;
if (Pp[i] != 0)
Alpha_to[MM] ^= mask;
mask <<= 1;
}
Index_of[Alpha_to[MM]] = MM;
mask >>= 1;
for (i = MM + 1; i < NN; i++) {
if (Alpha_to[i - 1] >= mask)
Alpha_to[i] = Alpha_to[MM] ^ ((Alpha_to[i - 1] ^ mask) << 1);
else
Alpha_to[i] = Alpha_to[i - 1] << 1;
Index_of[Alpha_to[i]] = i;
}
Index_of[0] = A0;
Alpha_to[NN] = 0;
}
static int
eras_dec_rs(dtype Alpha_to[NN + 1], dtype Index_of[NN + 1],
gf bb[NN - KK + 1], gf eras_val[NN-KK], int eras_pos[NN-KK],
int no_eras)
{
int deg_lambda, el, deg_omega;
int i, j, r,k;
gf u,q,tmp,num1,num2,den,discr_r;
gf lambda[NN-KK + 1], s[NN-KK + 1];
gf b[NN-KK + 1], t[NN-KK + 1], omega[NN-KK + 1];
gf root[NN-KK], reg[NN-KK + 1], loc[NN-KK];
int syn_error, count;
syn_error = 0;
for(i=0;i<NN-KK;i++)
syn_error |= bb[i];
if (!syn_error) {
count = 0;
goto finish;
}
for(i=1;i<=NN-KK;i++){
s[i] = bb[0];
}
for(j=1;j<NN-KK;j++){
if(bb[j] == 0)
continue;
tmp = Index_of[bb[j]];
for(i=1;i<=NN-KK;i++)
s[i] ^= Alpha_to[modnn(tmp + (B0+i-1)*PRIM*j)];
}
for(i=1;i<=NN-KK;i++) {
tmp = Index_of[s[i]];
if (tmp != A0)
tmp = modnn(tmp + 2 * KK * (B0+i-1)*PRIM);
s[i] = tmp;
}
CLEAR(&lambda[1],NN-KK);
lambda[0] = 1;
if (no_eras > 0) {
lambda[1] = Alpha_to[modnn(PRIM * eras_pos[0])];
for (i = 1; i < no_eras; i++) {
u = modnn(PRIM*eras_pos[i]);
for (j = i+1; j > 0; j--) {
tmp = Index_of[lambda[j - 1]];
if(tmp != A0)
lambda[j] ^= Alpha_to[modnn(u + tmp)];
}
}
#if DEBUG_ECC >= 1
for(i=1;i<=no_eras;i++)
reg[i] = Index_of[lambda[i]];
count = 0;
for (i = 1,k=NN-Ldec; i <= NN; i++,k = modnn(NN+k-Ldec)) {
q = 1;
for (j = 1; j <= no_eras; j++)
if (reg[j] != A0) {
reg[j] = modnn(reg[j] + j);
q ^= Alpha_to[reg[j]];
}
if (q != 0)
continue;
root[count] = i;
loc[count] = k;
count++;
}
if (count != no_eras) {
printf("\n lambda(x) is WRONG\n");
count = -1;
goto finish;
}
#if DEBUG_ECC >= 2
printf("\n Erasure positions as determined by roots of Eras Loc Poly:\n");
for (i = 0; i < count; i++)
printf("%d ", loc[i]);
printf("\n");
#endif
#endif
}
for(i=0;i<NN-KK+1;i++)
b[i] = Index_of[lambda[i]];
r = no_eras;
el = no_eras;
while (++r <= NN-KK) {
discr_r = 0;
for (i = 0; i < r; i++){
if ((lambda[i] != 0) && (s[r - i] != A0)) {
discr_r ^= Alpha_to[modnn(Index_of[lambda[i]] + s[r - i])];
}
}
discr_r = Index_of[discr_r];
if (discr_r == A0) {
COPYDOWN(&b[1],b,NN-KK);
b[0] = A0;
} else {
t[0] = lambda[0];
for (i = 0 ; i < NN-KK; i++) {
if(b[i] != A0)
t[i+1] = lambda[i+1] ^ Alpha_to[modnn(discr_r + b[i])];
else
t[i+1] = lambda[i+1];
}
if (2 * el <= r + no_eras - 1) {
el = r + no_eras - el;
for (i = 0; i <= NN-KK; i++)
b[i] = (lambda[i] == 0) ? A0 : modnn(Index_of[lambda[i]] - discr_r + NN);
} else {
COPYDOWN(&b[1],b,NN-KK);
b[0] = A0;
}
COPY(lambda,t,NN-KK+1);
}
}
deg_lambda = 0;
for(i=0;i<NN-KK+1;i++){
lambda[i] = Index_of[lambda[i]];
if(lambda[i] != A0)
deg_lambda = i;
}
COPY(&reg[1],&lambda[1],NN-KK);
count = 0;
for (i = 1,k=NN-Ldec; i <= NN; i++,k = modnn(NN+k-Ldec)) {
q = 1;
for (j = deg_lambda; j > 0; j--){
if (reg[j] != A0) {
reg[j] = modnn(reg[j] + j);
q ^= Alpha_to[reg[j]];
}
}
if (q != 0)
continue;
root[count] = i;
loc[count] = k;
if(++count == deg_lambda)
break;
}
if (deg_lambda != count) {
count = -1;
goto finish;
}
deg_omega = 0;
for (i = 0; i < NN-KK;i++){
tmp = 0;
j = (deg_lambda < i) ? deg_lambda : i;
for(;j >= 0; j--){
if ((s[i + 1 - j] != A0) && (lambda[j] != A0))
tmp ^= Alpha_to[modnn(s[i + 1 - j] + lambda[j])];
}
if(tmp != 0)
deg_omega = i;
omega[i] = Index_of[tmp];
}
omega[NN-KK] = A0;
for (j = count-1; j >=0; j--) {
num1 = 0;
for (i = deg_omega; i >= 0; i--) {
if (omega[i] != A0)
num1 ^= Alpha_to[modnn(omega[i] + i * root[j])];
}
num2 = Alpha_to[modnn(root[j] * (B0 - 1) + NN)];
den = 0;
for (i = min(deg_lambda,NN-KK-1) & ~1; i >= 0; i -=2) {
if(lambda[i+1] != A0)
den ^= Alpha_to[modnn(lambda[i+1] + i * root[j])];
}
if (den == 0) {
#if DEBUG_ECC >= 1
printf("\n ERROR: denominator = 0\n");
#endif
count = -1;
goto finish;
}
if (num1 != 0) {
eras_val[j] = Alpha_to[modnn(Index_of[num1] + Index_of[num2] + NN - Index_of[den])];
} else {
eras_val[j] = 0;
}
}
finish:
for(i=0;i<count;i++)
eras_pos[i] = loc[i];
return count;
}
int doc_decode_ecc(unsigned char sector[SECTOR_SIZE], unsigned char ecc1[6])
{
int parity, i, nb_errors;
gf bb[NN - KK + 1];
gf error_val[NN-KK];
int error_pos[NN-KK], pos, bitpos, index, val;
dtype *Alpha_to, *Index_of;
Alpha_to = kmalloc((NN + 1) * sizeof(dtype), GFP_KERNEL);
if (!Alpha_to)
return -1;
Index_of = kmalloc((NN + 1) * sizeof(dtype), GFP_KERNEL);
if (!Index_of) {
kfree(Alpha_to);
return -1;
}
generate_gf(Alpha_to, Index_of);
parity = ecc1[1];
bb[0] = (ecc1[4] & 0xff) | ((ecc1[5] & 0x03) << 8);
bb[1] = ((ecc1[5] & 0xfc) >> 2) | ((ecc1[2] & 0x0f) << 6);
bb[2] = ((ecc1[2] & 0xf0) >> 4) | ((ecc1[3] & 0x3f) << 4);
bb[3] = ((ecc1[3] & 0xc0) >> 6) | ((ecc1[0] & 0xff) << 2);
nb_errors = eras_dec_rs(Alpha_to, Index_of, bb,
error_val, error_pos, 0);
if (nb_errors <= 0)
goto the_end;
for(i=0;i<nb_errors;i++) {
pos = error_pos[i];
if (pos >= NB_DATA && pos < KK) {
nb_errors = -1;
goto the_end;
}
if (pos < NB_DATA) {
pos = 10 * (NB_DATA - 1 - pos) - 6;
index = (pos >> 3) ^ 1;
bitpos = pos & 7;
if ((index >= 0 && index < SECTOR_SIZE) ||
index == (SECTOR_SIZE + 1)) {
val = error_val[i] >> (2 + bitpos);
parity ^= val;
if (index < SECTOR_SIZE)
sector[index] ^= val;
}
index = ((pos >> 3) + 1) ^ 1;
bitpos = (bitpos + 10) & 7;
if (bitpos == 0)
bitpos = 8;
if ((index >= 0 && index < SECTOR_SIZE) ||
index == (SECTOR_SIZE + 1)) {
val = error_val[i] << (8 - bitpos);
parity ^= val;
if (index < SECTOR_SIZE)
sector[index] ^= val;
}
}
}
if ((parity & 0xff) != 0)
nb_errors = -1;
the_end:
kfree(Alpha_to);
kfree(Index_of);
return nb_errors;
}
