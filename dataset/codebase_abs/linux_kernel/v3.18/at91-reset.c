static void F_1 ( enum V_1 V_2 , const char * V_3 )
{
asm volatile(
".balign 32\n\t"
"str %2, [%0, #" __stringify(AT91_SDRAMC_TR) "]\n\t"
"str %3, [%0, #" __stringify(AT91_SDRAMC_LPR) "]\n\t"
"str %4, [%1, #" __stringify(AT91_RSTC_CR) "]\n\t"
"b .\n\t"
:
: "r" (at91_ramc_base[0]),
"r" (at91_rstc_base),
"r" (1),
"r" (AT91_SDRAMC_LPCB_POWER_DOWN),
"r" (AT91_RSTC_KEY | AT91_RSTC_PERRST | AT91_RSTC_PROCRST));
}
static void F_2 ( enum V_1 V_2 , const char * V_3 )
{
asm volatile(
"cmp %1, #0\n\t"
"beq 1f\n\t"
"ldr r0, [%1]\n\t"
"cmp r0, #0\n\t"
".balign 32\n\t"
"1: str %3, [%0, #" __stringify(AT91_DDRSDRC_RTR) "]\n\t"
" str %4, [%0, #" __stringify(AT91_DDRSDRC_LPR) "]\n\t"
" strne %3, [%1, #" __stringify(AT91_DDRSDRC_RTR) "]\n\t"
" strne %4, [%1, #" __stringify(AT91_DDRSDRC_LPR) "]\n\t"
" str %5, [%2, #" __stringify(AT91_RSTC_CR) "]\n\t"
" b .\n\t"
:
: "r" (at91_ramc_base[0]),
"r" (at91_ramc_base[1]),
"r" (at91_rstc_base),
"r" (1),
"r" (AT91_DDRSDRC_LPCB_POWER_DOWN),
"r" (AT91_RSTC_KEY | AT91_RSTC_PERRST | AT91_RSTC_PROCRST)
: "r0");
}
static void T_1 F_3 ( struct V_4 * V_5 )
{
T_2 V_6 = F_4 ( V_7 + V_8 ) ;
char * V_9 ;
switch ( ( V_6 & V_10 ) >> 8 ) {
case V_11 :
V_9 = L_1 ;
break;
case V_12 :
V_9 = L_2 ;
break;
case V_13 :
V_9 = L_3 ;
break;
case V_14 :
V_9 = L_4 ;
break;
case V_15 :
V_9 = L_5 ;
break;
default:
V_9 = L_6 ;
break;
}
F_5 ( L_7 , V_9 ) ;
}
static int F_6 ( struct V_4 * V_5 )
{
const struct V_16 * V_17 ;
struct V_18 * V_19 ;
int V_20 = 0 ;
V_7 = F_7 ( V_5 -> V_21 . V_22 , 0 ) ;
if ( ! V_7 ) {
F_8 ( & V_5 -> V_21 , L_8 ) ;
return - V_23 ;
}
F_9 (np, at91_ramc_of_match) {
V_24 [ V_20 ] = F_7 ( V_19 , 0 ) ;
if ( ! V_24 [ V_20 ] ) {
F_8 ( & V_5 -> V_21 , L_9 ) ;
return - V_23 ;
}
V_20 ++ ;
}
V_17 = F_10 ( V_25 , V_5 -> V_21 . V_22 ) ;
V_26 = V_17 -> V_27 ;
return 0 ;
}
static int F_11 ( struct V_4 * V_5 )
{
const struct V_28 * V_17 ;
struct V_29 * V_30 ;
int V_20 = 0 ;
V_30 = F_12 ( V_5 , V_31 , 0 ) ;
V_7 = F_13 ( & V_5 -> V_21 , V_30 ) ;
if ( F_14 ( V_7 ) ) {
F_8 ( & V_5 -> V_21 , L_8 ) ;
return F_15 ( V_7 ) ;
}
for ( V_20 = 0 ; V_20 < 2 ; V_20 ++ ) {
V_30 = F_12 ( V_5 , V_31 , V_20 + 1 ) ;
V_24 [ V_20 ] = F_16 ( & V_5 -> V_21 , V_30 -> V_32 ,
F_17 ( V_30 ) ) ;
if ( F_14 ( V_24 [ V_20 ] ) ) {
F_8 ( & V_5 -> V_21 , L_9 ) ;
return F_15 ( V_24 [ V_20 ] ) ;
}
}
V_17 = F_18 ( V_5 ) ;
V_26 = ( void ( * ) ( enum V_1 , const char * ) )
V_17 -> V_33 ;
return 0 ;
}
static int F_19 ( struct V_4 * V_5 )
{
int V_34 ;
if ( V_5 -> V_21 . V_22 )
V_34 = F_6 ( V_5 ) ;
else
V_34 = F_11 ( V_5 ) ;
if ( V_34 )
return V_34 ;
F_3 ( V_5 ) ;
return 0 ;
}
