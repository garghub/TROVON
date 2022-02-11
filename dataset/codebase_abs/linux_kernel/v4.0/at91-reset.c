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
"r" (AT91_SDRAMC_LPCB_POWER_DOWN),
"r" (AT91_RSTC_KEY | AT91_RSTC_PERRST | AT91_RSTC_PROCRST));
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
"r" (AT91_DDRSDRC_LPCB_POWER_DOWN),
"r" (AT91_RSTC_KEY | AT91_RSTC_PERRST | AT91_RSTC_PROCRST)
: "r0");
return V_5 ;
}
static void T_1 F_3 ( struct V_6 * V_7 )
{
T_2 V_8 = F_4 ( V_9 + V_10 ) ;
char * V_11 ;
switch ( ( V_8 & V_12 ) >> 8 ) {
case V_13 :
V_11 = L_1 ;
break;
case V_14 :
V_11 = L_2 ;
break;
case V_15 :
V_11 = L_3 ;
break;
case V_16 :
V_11 = L_4 ;
break;
case V_17 :
V_11 = L_5 ;
break;
default:
V_11 = L_6 ;
break;
}
F_5 ( L_7 , V_11 ) ;
}
static int F_6 ( struct V_6 * V_7 )
{
const struct V_18 * V_19 ;
struct V_20 * V_21 ;
int V_22 = 0 ;
V_9 = F_7 ( V_7 -> V_23 . V_24 , 0 ) ;
if ( ! V_9 ) {
F_8 ( & V_7 -> V_23 , L_8 ) ;
return - V_25 ;
}
F_9 (np, at91_ramc_of_match) {
V_26 [ V_22 ] = F_7 ( V_21 , 0 ) ;
if ( ! V_26 [ V_22 ] ) {
F_8 ( & V_7 -> V_23 , L_9 ) ;
return - V_25 ;
}
V_22 ++ ;
}
V_19 = F_10 ( V_27 , V_7 -> V_23 . V_24 ) ;
V_28 . V_29 = V_19 -> V_30 ;
return F_11 ( & V_28 ) ;
}
static int F_12 ( struct V_6 * V_7 )
{
const struct V_31 * V_19 ;
struct V_32 * V_33 ;
int V_22 = 0 ;
V_33 = F_13 ( V_7 , V_34 , 0 ) ;
V_9 = F_14 ( & V_7 -> V_23 , V_33 ) ;
if ( F_15 ( V_9 ) ) {
F_8 ( & V_7 -> V_23 , L_8 ) ;
return F_16 ( V_9 ) ;
}
for ( V_22 = 0 ; V_22 < 2 ; V_22 ++ ) {
V_33 = F_13 ( V_7 , V_34 , V_22 + 1 ) ;
V_26 [ V_22 ] = F_17 ( & V_7 -> V_23 , V_33 -> V_35 ,
F_18 ( V_33 ) ) ;
if ( F_15 ( V_26 [ V_22 ] ) ) {
F_8 ( & V_7 -> V_23 , L_9 ) ;
return F_16 ( V_26 [ V_22 ] ) ;
}
}
V_19 = F_19 ( V_7 ) ;
V_28 . V_29 =
( int (*) (struct V_1 * ,
unsigned long , void * ) ) V_19 -> V_36 ;
return F_11 ( & V_28 ) ;
}
static int F_20 ( struct V_6 * V_7 )
{
int V_37 ;
if ( V_7 -> V_23 . V_24 )
V_37 = F_6 ( V_7 ) ;
else
V_37 = F_12 ( V_7 ) ;
if ( V_37 )
return V_37 ;
F_3 ( V_7 ) ;
return 0 ;
}
