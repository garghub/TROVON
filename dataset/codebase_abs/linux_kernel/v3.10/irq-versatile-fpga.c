static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_5 = 1 << V_2 -> V_6 ;
F_3 ( V_5 , V_4 -> V_7 + V_8 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_5 = 1 << V_2 -> V_6 ;
F_3 ( V_5 , V_4 -> V_7 + V_9 ) ;
}
static void F_5 ( unsigned int V_10 , struct V_11 * V_12 )
{
struct V_3 * V_4 = F_6 ( V_12 ) ;
T_1 V_13 = F_7 ( V_4 -> V_7 + V_14 ) ;
if ( V_13 == 0 ) {
F_8 ( V_10 , V_12 ) ;
return;
}
do {
V_10 = F_9 ( V_13 ) - 1 ;
V_13 &= ~ ( 1 << V_10 ) ;
F_10 ( F_11 ( V_4 -> V_15 , V_10 ) ) ;
} while ( V_13 );
}
static int F_12 ( struct V_3 * V_4 , struct V_16 * V_17 )
{
int V_18 = 0 ;
int V_10 ;
T_1 V_13 ;
while ( ( V_13 = F_7 ( V_4 -> V_7 + V_14 ) ) ) {
V_10 = F_9 ( V_13 ) - 1 ;
F_13 ( F_11 ( V_4 -> V_15 , V_10 ) , V_17 ) ;
V_18 = 1 ;
}
return V_18 ;
}
T_2 void T_3 F_14 ( struct V_16 * V_17 )
{
int V_19 , V_18 ;
do {
for ( V_19 = 0 , V_18 = 0 ; V_19 < V_20 ; ++ V_19 )
V_18 |= F_12 ( & V_21 [ V_19 ] , V_17 ) ;
} while ( V_18 );
}
static int F_15 ( struct V_22 * V_2 , unsigned int V_10 ,
T_4 V_6 )
{
struct V_3 * V_4 = V_2 -> V_23 ;
if ( ! ( V_4 -> V_24 & F_16 ( V_6 ) ) )
return - V_25 ;
F_17 ( V_10 , V_4 ) ;
F_18 ( V_10 , & V_4 -> V_26 ,
V_27 ) ;
F_19 ( V_10 , V_28 | V_29 ) ;
return 0 ;
}
void T_5 F_20 ( void T_6 * V_7 , const char * V_30 , int V_31 ,
int V_32 , T_1 V_24 , struct V_33 * V_34 )
{
struct V_3 * V_4 ;
int V_19 ;
if ( V_20 >= F_21 ( V_21 ) ) {
F_22 ( L_1 , V_35 ) ;
return;
}
V_4 = & V_21 [ V_20 ] ;
V_4 -> V_7 = V_7 ;
V_4 -> V_26 . V_30 = V_30 ;
V_4 -> V_26 . V_36 = F_1 ;
V_4 -> V_26 . V_37 = F_1 ;
V_4 -> V_26 . V_38 = F_4 ;
V_4 -> V_24 = V_24 ;
if ( V_32 != - 1 ) {
F_23 ( V_32 , V_4 ) ;
F_24 ( V_32 , F_5 ) ;
}
V_4 -> V_15 = F_25 ( V_34 , F_26 ( V_24 ) , V_31 ,
& V_39 , V_4 ) ;
for ( V_19 = 0 ; V_19 < F_26 ( V_24 ) ; V_19 ++ )
if ( V_24 & F_16 ( V_19 ) ) {
if ( ! V_31 )
F_27 ( V_4 -> V_15 , V_19 ) ;
V_4 -> V_40 ++ ;
}
F_28 ( L_2 ,
V_20 , V_30 , V_7 , V_4 -> V_40 ) ;
V_20 ++ ;
}
int T_5 F_29 ( struct V_33 * V_34 ,
struct V_33 * V_41 )
{
void T_6 * V_7 ;
T_1 V_42 ;
T_1 V_43 ;
if ( F_30 ( ! V_34 ) )
return - V_44 ;
V_7 = F_31 ( V_34 , 0 ) ;
F_32 ( ! V_7 , L_3 ) ;
if ( F_33 ( V_34 , L_4 , & V_42 ) )
V_42 = 0 ;
if ( F_33 ( V_34 , L_5 , & V_43 ) )
V_43 = 0 ;
F_20 ( V_7 , V_34 -> V_30 , 0 , - 1 , V_43 , V_34 ) ;
F_3 ( V_42 , V_7 + V_8 ) ;
F_3 ( V_42 , V_7 + V_45 ) ;
return 0 ;
}
