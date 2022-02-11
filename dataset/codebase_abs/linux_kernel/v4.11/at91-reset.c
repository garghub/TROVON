static int F_1 ( struct V_1 * V_2 , unsigned long V_3 ,
void * V_4 )
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
"r" cpu_to_le32(AT91_SDRAMC_LPCB_POWER_DOWN),
"r" cpu_to_le32(AT91_RSTC_KEY | AT91_RSTC_PERRST | AT91_RSTC_PROCRST));
return V_5 ;
}
static int F_2 ( struct V_1 * V_2 , unsigned long V_3 ,
void * V_4 )
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
"r" cpu_to_le32(AT91_DDRSDRC_LPCB_POWER_DOWN),
"r" cpu_to_le32(AT91_RSTC_KEY | AT91_RSTC_PERRST | AT91_RSTC_PROCRST)
: "r0");
return V_5 ;
}
static int F_3 ( struct V_1 * V_2 , unsigned long V_3 ,
void * V_4 )
{
F_4 ( F_5 ( V_6 | V_7 | V_8 ) ,
V_9 ) ;
return V_5 ;
}
static int F_6 ( struct V_1 * V_2 , unsigned long V_3 ,
void * V_4 )
{
F_4 ( F_5 ( V_6 | V_8 ) ,
V_9 ) ;
return V_5 ;
}
static void T_1 F_7 ( struct V_10 * V_11 )
{
T_2 V_12 = F_8 ( V_9 + V_13 ) ;
char * V_14 ;
switch ( ( V_12 & V_15 ) >> 8 ) {
case V_16 :
V_14 = L_1 ;
break;
case V_17 :
V_14 = L_2 ;
break;
case V_18 :
V_14 = L_3 ;
break;
case V_19 :
V_14 = L_4 ;
break;
case V_20 :
V_14 = L_5 ;
break;
default:
V_14 = L_6 ;
break;
}
F_9 ( L_7 , V_14 ) ;
}
static int T_1 F_10 ( struct V_10 * V_11 )
{
const struct V_21 * V_22 ;
struct V_23 * V_24 ;
int V_25 , V_26 = 0 ;
V_9 = F_11 ( V_11 -> V_27 . V_28 , 0 ) ;
if ( ! V_9 ) {
F_12 ( & V_11 -> V_27 , L_8 ) ;
return - V_29 ;
}
if ( ! F_13 ( V_11 -> V_27 . V_28 , L_9 ) ) {
F_14 (np, at91_ramc_of_match) {
V_30 [ V_26 ] = F_11 ( V_24 , 0 ) ;
if ( ! V_30 [ V_26 ] ) {
F_12 ( & V_11 -> V_27 , L_10 ) ;
F_15 ( V_24 ) ;
return - V_29 ;
}
V_26 ++ ;
}
}
V_22 = F_16 ( V_31 , V_11 -> V_27 . V_28 ) ;
V_32 . V_33 = V_22 -> V_34 ;
V_35 = F_17 ( & V_11 -> V_27 , NULL ) ;
if ( F_18 ( V_35 ) )
return F_19 ( V_35 ) ;
V_25 = F_20 ( V_35 ) ;
if ( V_25 ) {
F_12 ( & V_11 -> V_27 , L_11 ) ;
return V_25 ;
}
V_25 = F_21 ( & V_32 ) ;
if ( V_25 ) {
F_22 ( V_35 ) ;
return V_25 ;
}
F_7 ( V_11 ) ;
return 0 ;
}
static int T_3 F_23 ( struct V_10 * V_11 )
{
F_24 ( & V_32 ) ;
F_22 ( V_35 ) ;
return 0 ;
}
