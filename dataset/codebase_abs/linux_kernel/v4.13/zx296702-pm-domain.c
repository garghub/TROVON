static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
unsigned long V_5 = 1000 ;
T_1 V_6 ;
V_6 = F_2 ( V_7 + V_8 ) ;
V_6 &= ~ F_3 ( V_4 -> V_9 ) ;
F_4 ( V_6 , V_7 + V_8 ) ;
F_5 ( 5 ) ;
V_6 = F_2 ( V_7 + V_10 ) ;
V_6 &= ~ F_3 ( V_4 -> V_9 ) ;
F_4 ( V_6 | F_3 ( V_4 -> V_9 ) , V_7 + V_10 ) ;
F_5 ( 5 ) ;
V_6 = F_2 ( V_7 + V_11 ) ;
V_6 &= ~ F_3 ( V_4 -> V_9 ) ;
F_4 ( V_6 , V_7 + V_11 ) ;
F_5 ( 5 ) ;
V_6 = F_2 ( V_7 + V_12 ) ;
V_6 &= ~ F_3 ( V_4 -> V_9 ) ;
F_4 ( V_6 | F_3 ( V_4 -> V_9 ) , V_7 + V_12 ) ;
do {
V_6 = F_2 ( V_7 + V_13 ) & F_3 ( V_4 -> V_9 ) ;
} while ( -- V_5 && ! V_6 );
if ( ! V_5 ) {
F_6 ( L_1 , V_14 , V_2 -> V_15 ) ;
return - V_16 ;
}
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
unsigned long V_5 = 10000 ;
T_1 V_6 ;
V_6 = F_2 ( V_7 + V_12 ) ;
V_6 &= ~ F_3 ( V_4 -> V_9 ) ;
F_4 ( V_6 , V_7 + V_12 ) ;
do {
V_6 = F_2 ( V_7 + V_13 ) & F_3 ( V_4 -> V_9 ) ;
} while ( -- V_5 && V_6 );
if ( ! V_5 ) {
F_6 ( L_1 , V_14 , V_2 -> V_15 ) ;
return - V_16 ;
}
V_6 = F_2 ( V_7 + V_11 ) ;
V_6 &= ~ F_3 ( V_4 -> V_9 ) ;
F_4 ( V_6 | F_3 ( V_4 -> V_9 ) , V_7 + V_11 ) ;
F_5 ( 5 ) ;
V_6 = F_2 ( V_7 + V_10 ) ;
V_6 &= ~ F_3 ( V_4 -> V_9 ) ;
F_4 ( V_6 , V_7 + V_10 ) ;
F_5 ( 5 ) ;
V_6 = F_2 ( V_7 + V_8 ) ;
V_6 &= ~ F_3 ( V_4 -> V_9 ) ;
F_4 ( V_6 | F_3 ( V_4 -> V_9 ) , V_7 + V_8 ) ;
F_5 ( 5 ) ;
return 0 ;
}
static int F_8 ( struct V_17 * V_18 )
{
struct V_19 * V_20 ;
struct V_21 * V_22 ;
int V_23 ;
V_20 = F_9 ( & V_18 -> V_24 , sizeof( * V_20 ) , V_25 ) ;
if ( ! V_20 )
return - V_26 ;
V_20 -> V_27 = V_28 ;
V_20 -> V_29 = F_10 ( V_28 ) ;
V_22 = F_11 ( V_18 , V_30 , 0 ) ;
if ( ! V_22 ) {
F_12 ( & V_18 -> V_24 , L_2 ) ;
return - V_31 ;
}
V_7 = F_13 ( & V_18 -> V_24 , V_22 ) ;
if ( F_14 ( V_7 ) ) {
F_12 ( & V_18 -> V_24 , L_3 ) ;
return - V_16 ;
}
for ( V_23 = 0 ; V_23 < F_10 ( V_28 ) ; ++ V_23 )
F_15 ( V_28 [ V_23 ] , NULL , false ) ;
F_16 ( V_18 -> V_24 . V_32 , V_20 ) ;
return 0 ;
}
static int T_2 F_17 ( void )
{
return F_18 ( & V_33 ) ;
}
