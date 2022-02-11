static void T_1 F_1 ( void )
{
T_2 V_1 = F_2 ( V_2 + V_3 ) ;
char * V_4 = L_1 ;
if ( ! V_1 )
return;
if ( V_1 & V_5 )
V_4 = L_2 ;
else if ( V_1 & V_6 )
V_4 = L_3 ;
F_3 ( L_4 , V_4 ) ;
}
static void F_4 ( void )
{
F_5 ( V_7 | V_8 , V_2 + V_9 ) ;
}
static void F_6 ( void )
{
asm volatile(
".balign 32\n\t"
" ldr r6, [%2, #" __stringify(AT91_SHDW_CR) "]\n\t"
" str %1, [%0, #" __stringify(AT91_DDRSDRC_LPR) "]\n\t"
" str %3, [%2, #" __stringify(AT91_SHDW_CR) "]\n\t"
" b .\n\t"
:
: "r" (mpddrc_base),
"r" cpu_to_le32(AT91_DDRSDRC_LPDDR2_PWOFF),
"r" (at91_shdwc_base),
"r" cpu_to_le32(AT91_SHDW_KEY | AT91_SHDW_SHDW)
: "r0");
}
static int F_7 ( struct V_10 * V_11 )
{
const char * V_12 ;
unsigned int V_13 ;
int V_14 ;
V_14 = F_8 ( V_11 , L_5 , & V_12 ) ;
if ( V_14 < 0 )
return V_15 ;
for ( V_13 = 0 ; V_13 < F_9 ( V_16 ) ; V_13 ++ )
if ( ! strcasecmp ( V_12 , V_16 [ V_13 ] ) )
return V_13 ;
return - V_17 ;
}
static void F_10 ( struct V_18 * V_19 )
{
struct V_10 * V_11 = V_19 -> V_20 . V_21 ;
int V_22 ;
T_2 V_23 = 0 , V_24 ;
V_22 = F_7 ( V_11 ) ;
if ( V_22 < 0 ) {
F_11 ( & V_19 -> V_20 , L_6 ) ;
return;
}
if ( ! F_12 ( V_11 , L_7 , & V_24 ) ) {
if ( V_24 > V_25 ) {
F_11 ( & V_19 -> V_20 ,
L_8 ,
V_24 , V_25 , V_25 ) ;
V_24 = V_25 ;
}
V_23 |= F_13 ( V_24 ) ;
}
if ( F_14 ( V_11 , L_9 ) )
V_23 |= V_26 ;
if ( F_14 ( V_11 , L_10 ) )
V_23 |= V_27 ;
F_5 ( V_22 | V_23 , V_2 + V_28 ) ;
}
static int T_1 F_15 ( struct V_18 * V_19 )
{
struct V_29 * V_30 ;
struct V_10 * V_11 ;
T_2 V_31 ;
int V_32 ;
V_30 = F_16 ( V_19 , V_33 , 0 ) ;
V_2 = F_17 ( & V_19 -> V_20 , V_30 ) ;
if ( F_18 ( V_2 ) ) {
F_19 ( & V_19 -> V_20 , L_11 ) ;
return F_20 ( V_2 ) ;
}
V_34 = F_21 ( & V_19 -> V_20 , NULL ) ;
if ( F_18 ( V_34 ) )
return F_20 ( V_34 ) ;
V_32 = F_22 ( V_34 ) ;
if ( V_32 ) {
F_19 ( & V_19 -> V_20 , L_12 ) ;
return V_32 ;
}
F_1 () ;
if ( V_19 -> V_20 . V_21 )
F_10 ( V_19 ) ;
V_35 = F_4 ;
V_11 = F_23 ( NULL , NULL , L_13 ) ;
if ( ! V_11 )
return 0 ;
V_36 = F_24 ( V_11 , 0 ) ;
F_25 ( V_11 ) ;
if ( ! V_36 )
return 0 ;
V_31 = F_2 ( V_36 + V_37 ) & V_38 ;
if ( ( V_31 == V_39 ) ||
( V_31 == V_40 ) )
V_35 = F_6 ;
else
F_26 ( V_36 ) ;
return 0 ;
}
static int T_3 F_27 ( struct V_18 * V_19 )
{
if ( V_35 == F_4 ||
V_35 == F_6 )
V_35 = NULL ;
F_28 ( V_34 ) ;
return 0 ;
}
