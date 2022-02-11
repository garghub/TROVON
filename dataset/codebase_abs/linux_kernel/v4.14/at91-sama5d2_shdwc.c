static void T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_2 V_5 ;
char * V_6 = L_1 ;
V_5 = F_3 ( V_4 -> V_7 + V_8 ) ;
F_4 ( & V_2 -> V_9 , L_2 , V_10 , V_5 ) ;
if ( ! V_5 )
return;
if ( F_5 ( V_5 , V_4 -> V_11 ) )
V_6 = L_3 ;
else if ( F_6 ( V_5 , V_4 -> V_11 ) )
V_6 = L_4 ;
F_7 ( L_5 , V_6 ) ;
}
static void F_8 ( void )
{
F_9 ( V_12 | V_13 ,
V_14 -> V_7 + V_15 ) ;
}
static void F_10 ( void )
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
"r" (at91_shdwc->at91_shdwc_base),
"r" cpu_to_le32(AT91_SHDW_KEY | AT91_SHDW_SHDW)
: "r6");
}
static T_2 F_11 ( struct V_1 * V_2 ,
T_2 V_16 )
{
int V_17 ;
int V_18 = F_12 ( V_19 ) - 1 ;
unsigned long long V_20 ;
unsigned long long V_21 = F_13 ( V_19 [ V_18 ] ) ;
if ( V_16 > V_21 ) {
F_14 ( & V_2 -> V_9 ,
L_6 ,
V_16 , V_21 ) ;
return V_18 ;
}
for ( V_17 = V_18 - 1 ; V_17 > 0 ; V_17 -- ) {
V_20 = F_13 ( V_19 [ V_17 ] ) ;
F_4 ( & V_2 -> V_9 , L_7 ,
V_10 , V_17 , V_20 ) ;
if ( V_16 > V_20 )
break;
}
return V_17 + 1 ;
}
static T_2 F_15 ( struct V_1 * V_2 ,
struct V_22 * V_23 )
{
struct V_22 * V_24 ;
T_2 V_25 ;
T_2 V_26 = 0 ;
T_2 V_27 ;
F_16 (np, cnp) {
if ( F_17 ( V_24 , L_8 , & V_27 ) ) {
F_14 ( & V_2 -> V_9 , L_9 ,
V_24 ) ;
continue;
}
V_25 = 1 << V_27 ;
if ( ! ( V_25 & V_28 ) ) {
F_14 ( & V_2 -> V_9 ,
L_10 ,
V_27 ) ;
continue;
}
V_26 |= V_25 ;
if ( F_18 ( V_24 , L_11 ) )
V_26 |= F_19 ( V_27 ) ;
F_4 ( & V_2 -> V_9 , L_12 ,
V_10 , V_27 , V_26 ) ;
}
return V_26 ;
}
static void F_20 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_22 * V_23 = V_2 -> V_9 . V_29 ;
T_2 V_30 = 0 , V_31 , V_32 ;
if ( ! V_23 ) {
F_21 ( & V_2 -> V_9 , L_13 ) ;
return;
}
if ( ! F_17 ( V_23 , L_14 , & V_31 ) )
V_30 |= F_22 ( F_11 ( V_2 , V_31 ) ) ;
if ( F_18 ( V_23 , L_15 ) )
V_30 |= F_23 ( V_4 -> V_11 ) ;
F_4 ( & V_2 -> V_9 , L_16 , V_10 , V_30 ) ;
F_9 ( V_30 , V_4 -> V_7 + V_33 ) ;
V_32 = F_15 ( V_2 , V_23 ) ;
F_9 ( V_32 , V_4 -> V_7 + V_34 ) ;
}
static int T_1 F_24 ( struct V_1 * V_2 )
{
struct V_35 * V_36 ;
const struct V_37 * V_38 ;
struct V_22 * V_23 ;
T_2 V_39 ;
int V_40 ;
if ( ! V_2 -> V_9 . V_29 )
return - V_41 ;
V_14 = F_25 ( & V_2 -> V_9 , sizeof( * V_14 ) , V_42 ) ;
if ( ! V_14 )
return - V_43 ;
F_26 ( V_2 , V_14 ) ;
V_36 = F_27 ( V_2 , V_44 , 0 ) ;
V_14 -> V_7 = F_28 ( & V_2 -> V_9 , V_36 ) ;
if ( F_29 ( V_14 -> V_7 ) ) {
F_21 ( & V_2 -> V_9 , L_17 ) ;
return F_30 ( V_14 -> V_7 ) ;
}
V_38 = F_31 ( V_45 , V_2 -> V_9 . V_29 ) ;
V_14 -> V_11 = (struct V_46 * ) ( V_38 -> V_47 ) ;
V_48 = F_32 ( & V_2 -> V_9 , NULL ) ;
if ( F_29 ( V_48 ) )
return F_30 ( V_48 ) ;
V_40 = F_33 ( V_48 ) ;
if ( V_40 ) {
F_21 ( & V_2 -> V_9 , L_18 ) ;
return V_40 ;
}
F_1 ( V_2 ) ;
F_20 ( V_2 ) ;
V_49 = F_8 ;
V_23 = F_34 ( NULL , NULL , L_19 ) ;
if ( ! V_23 )
return 0 ;
V_50 = F_35 ( V_23 , 0 ) ;
F_36 ( V_23 ) ;
if ( ! V_50 )
return 0 ;
V_39 = F_3 ( V_50 + V_51 ) & V_52 ;
if ( ( V_39 == V_53 ) ||
( V_39 == V_54 ) )
V_49 = F_10 ;
else
F_37 ( V_50 ) ;
return 0 ;
}
static int T_3 F_38 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_49 == F_8 ||
V_49 == F_10 )
V_49 = NULL ;
F_9 ( 0 , V_4 -> V_7 + V_33 ) ;
F_9 ( 0 , V_4 -> V_7 + V_34 ) ;
F_39 ( V_48 ) ;
return 0 ;
}
