static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
unsigned long V_5 = 1000 ;
T_1 V_6 ;
V_6 = F_2 ( V_7 + F_3 ( V_4 ) ) ;
if ( V_4 -> V_8 == V_9 )
V_6 |= F_4 ( V_4 -> V_10 ) ;
else
V_6 &= ~ F_4 ( V_4 -> V_10 ) ;
F_5 ( V_6 , V_7 + F_3 ( V_4 ) ) ;
do {
F_6 ( 1 ) ;
V_6 = F_2 ( V_7 + F_7 ( V_4 ) )
& F_4 ( V_4 -> V_10 ) ;
} while ( -- V_5 && ! V_6 );
if ( ! V_5 ) {
F_8 ( L_1 , V_11 , V_2 -> V_12 ) ;
return - V_13 ;
}
V_6 = F_2 ( V_7 + F_9 ( V_4 ) ) ;
V_6 |= F_4 ( V_4 -> V_10 ) ;
F_5 ( V_6 , V_7 + F_9 ( V_4 ) ) ;
F_6 ( 5 ) ;
V_6 = F_2 ( V_7 + F_10 ( V_4 ) ) ;
V_6 &= ~ F_4 ( V_4 -> V_10 ) ;
F_5 ( V_6 , V_7 + F_10 ( V_4 ) ) ;
F_6 ( 5 ) ;
V_6 = F_2 ( V_7 + F_11 ( V_4 ) ) ;
V_6 |= F_4 ( V_4 -> V_10 ) ;
F_5 ( V_6 , V_7 + F_11 ( V_4 ) ) ;
F_6 ( 5 ) ;
F_12 ( L_2 , V_2 -> V_12 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
unsigned long V_5 = 1000 ;
T_1 V_6 ;
V_6 = F_2 ( V_7 + F_11 ( V_4 ) ) ;
V_6 &= ~ F_4 ( V_4 -> V_10 ) ;
F_5 ( V_6 , V_7 + F_11 ( V_4 ) ) ;
F_6 ( 5 ) ;
V_6 = F_2 ( V_7 + F_10 ( V_4 ) ) ;
V_6 |= F_4 ( V_4 -> V_10 ) ;
F_5 ( V_6 , V_7 + F_10 ( V_4 ) ) ;
F_6 ( 5 ) ;
V_6 = F_2 ( V_7 + F_9 ( V_4 ) ) ;
V_6 &= ~ F_4 ( V_4 -> V_10 ) ;
F_5 ( V_6 , V_7 + F_9 ( V_4 ) ) ;
F_6 ( 5 ) ;
V_6 = F_2 ( V_7 + F_3 ( V_4 ) ) ;
if ( V_4 -> V_8 == V_9 )
V_6 &= ~ F_4 ( V_4 -> V_10 ) ;
else
V_6 |= F_4 ( V_4 -> V_10 ) ;
F_5 ( V_6 , V_7 + F_3 ( V_4 ) ) ;
do {
F_6 ( 1 ) ;
V_6 = F_2 ( V_7 + F_7 ( V_4 ) )
& F_4 ( V_4 -> V_10 ) ;
} while ( -- V_5 && V_6 );
if ( ! V_5 ) {
F_8 ( L_1 , V_11 , V_2 -> V_12 ) ;
return - V_13 ;
}
F_12 ( L_3 , V_2 -> V_12 ) ;
return 0 ;
}
int F_14 ( struct V_14 * V_15 ,
struct V_1 * * V_16 ,
int V_17 )
{
struct V_18 * V_19 ;
struct V_20 * V_21 ;
int V_22 ;
V_19 = F_15 ( & V_15 -> V_23 , sizeof( * V_19 ) , V_24 ) ;
if ( ! V_19 )
return - V_25 ;
V_19 -> V_26 = V_16 ;
V_19 -> V_27 = V_17 ;
V_21 = F_16 ( V_15 , V_28 , 0 ) ;
V_7 = F_17 ( & V_15 -> V_23 , V_21 ) ;
if ( F_18 ( V_7 ) )
return F_19 ( V_7 ) ;
for ( V_22 = 0 ; V_22 < V_17 ; ++ V_22 ) {
V_16 [ V_22 ] -> V_29 = F_1 ;
V_16 [ V_22 ] -> V_30 = F_13 ;
F_20 ( V_16 [ V_22 ] , NULL , false ) ;
}
F_21 ( V_15 -> V_23 . V_31 , V_19 ) ;
F_22 ( & V_15 -> V_23 , L_4 ) ;
return 0 ;
}
