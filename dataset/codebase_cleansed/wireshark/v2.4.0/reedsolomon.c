static gf
modnn(int x)
{
while (x >= NN) {
x -= NN;
x = (x >> MM) + (x & NN);
}
return x;
}
static void
gen_ltab(void)
{
int i,j,k;
for(i=0;i<256;i++){
taltab[i] = 0;
for(j=0;j<8;j++)
for(k=0;k<8;k++){
if(i & (1<<k))
taltab[i] ^= tal[7-k] & (1<<j);
}
tal1tab[taltab[i]] = i;
}
}
static void
gen_ldec(void)
{
for(Ldec=1;(Ldec % PRIM) != 0;Ldec+= NN)
;
Ldec /= PRIM;
}
static void
generate_gf(void)
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
static void
gen_poly(void)
{
register int i, j;
Gg[0] = 1;
for (i = 0; i < NN - KK; i++) {
Gg[i+1] = 1;
for (j = i; j > 0; j--)
if (Gg[j] != 0)
Gg[j] = Gg[j - 1] ^ Alpha_to[modnn((Index_of[Gg[j]]) + (B0 + i) *PRIM)];
else
Gg[j] = Gg[j - 1];
Gg[0] = Alpha_to[modnn(Index_of[Gg[0]] + (B0 + i) * PRIM)];
}
for (i = 0; i <= NN - KK; i++)
Gg[i] = Index_of[Gg[i]];
}
int
encode_rs(dtype data[KK], dtype bb[NN-KK])
{
register int i, j;
gf feedback;
#if DEBUG >= 1 && MM != 8
for(i=0;i<KK;i++)
if(MESSAGE(i) > NN)
return -1;
#endif
if(!RS_init)
init_rs();
CLEAR(bb,NN-KK);
#ifdef CCSDS
for(i=0;i<KK;i++)
MESSAGE(i) = tal1tab[MESSAGE(i)];
#endif
for(i = KK - 1; i >= 0; i--) {
feedback = Index_of[MESSAGE(i) ^ REMAINDER(NN - KK - 1)];
if (feedback != A0) {
for (j = NN - KK - 1; j > 0; j--)
if (Gg[j] != A0)
REMAINDER(j) = REMAINDER(j - 1) ^ Alpha_to[modnn(Gg[j] + feedback)];
else
REMAINDER(j) = REMAINDER(j - 1);
REMAINDER(0) = Alpha_to[modnn(Gg[0] + feedback)];
} else {
for (j = NN - KK - 1; j > 0; j--)
REMAINDER(j) = REMAINDER(j - 1);
REMAINDER(0) = 0;
}
}
#ifdef CCSDS
for(i=0;i<NN;i++)
MESSAGE(i) = taltab[MESSAGE(i)];
#endif
return 0;
}
int
eras_dec_rs(dtype data[NN], int eras_pos[NN-KK], int no_eras)
{
int deg_lambda, el, deg_omega;
int i, j, r,k;
gf u,q,tmp,num1,num2,den,discr_r;
gf lambda[NN-KK + 1], s[NN-KK + 1];
gf b[NN-KK + 1], t[NN-KK + 1], omega[NN-KK + 1];
gf root[NN-KK], reg[NN-KK + 1], loc[NN-KK];
int syn_error, count;
if(!RS_init)
init_rs();
#ifdef CCSDS
for(i=0;i<NN;i++)
RECEIVED(i) = tal1tab[RECEIVED(i)];
#endif
#if DEBUG >= 1 && MM != 8
for(i=0;i<NN;i++)
if(RECEIVED(i) > NN)
return -1;
#endif
for(i=1;i<=NN-KK;i++){
s[i] = RECEIVED(0);
}
for(j=1;j<NN;j++){
if(RECEIVED(j) == 0)
continue;
tmp = Index_of[RECEIVED(j)];
for(i=1;i<=NN-KK;i++)
s[i] ^= Alpha_to[modnn(tmp + (B0+i-1)*PRIM*j)];
}
syn_error = 0;
for(i=1;i<=NN-KK;i++){
syn_error |= s[i];
s[i] = Index_of[s[i]];
}
if (!syn_error) {
count = 0;
goto finish;
}
CLEAR(&lambda[1],NN-KK);
lambda[0] = 1;
if (no_eras > 0) {
lambda[1] = Alpha_to[modnn(PRIM * ERAS_INDEX(0))];
for (i = 1; i < no_eras; i++) {
u = modnn(PRIM*ERAS_INDEX(i));
for (j = i+1; j > 0; j--) {
tmp = Index_of[lambda[j - 1]];
if(tmp != A0)
lambda[j] ^= Alpha_to[modnn(u + tmp)];
}
}
#if DEBUG >= 1
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
ws_debug_printf("\n lambda(x) is WRONG\n");
count = -1;
goto finish;
}
#if DEBUG >= 2
ws_debug_printf("\n Erasure positions as determined by roots of Eras Loc Poly:\n");
for (i = 0; i < count; i++)
ws_debug_printf("%d ", loc[i]);
ws_debug_printf("\n");
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
for (i = min_(deg_lambda,NN-KK-1) & ~1; i >= 0; i -=2) {
if(lambda[i+1] != A0)
den ^= Alpha_to[modnn(lambda[i+1] + i * root[j])];
}
if (den == 0) {
#if DEBUG >= 1
ws_debug_printf("\n ERROR: denominator = 0\n");
#endif
count = -1;
goto finish;
}
if (num1 != 0) {
RECEIVED(loc[j]) ^= Alpha_to[modnn(Index_of[num1] + Index_of[num2] + NN - Index_of[den])];
}
}
finish:
#ifdef CCSDS
for(i=0;i<NN;i++)
RECEIVED(i) = taltab[RECEIVED(i)];
#endif
if(eras_pos != NULL){
for(i=0;i<count;i++){
if(eras_pos!= NULL)
eras_pos[i] = INDEX_TO_POS(loc[i]);
}
}
return count;
}
static void
init_rs(void)
{
generate_gf();
gen_poly();
#ifdef CCSDS
gen_ltab();
#endif
#if PRIM != 1
gen_ldec();
#endif
RS_init = 1;
}
