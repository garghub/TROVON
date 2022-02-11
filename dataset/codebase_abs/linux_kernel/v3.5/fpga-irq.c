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
if ( ! ( V_4 -> V_24 & ( 1 << V_6 ) ) )
return - V_25 ;
F_16 ( V_10 , V_4 ) ;
F_17 ( V_10 , & V_4 -> V_26 ,
V_27 ) ;
F_18 ( V_10 , V_28 | V_29 ) ;
V_4 -> V_30 ++ ;
return 0 ;
}
void T_5 F_19 ( void T_6 * V_7 , const char * V_31 , int V_32 ,
int V_33 , T_1 V_24 , struct V_34 * V_35 )
{
struct V_3 * V_4 ;
if ( V_20 >= F_20 ( V_21 ) ) {
F_21 ( V_36 L_1 , V_37 ) ;
return;
}
V_4 = & V_21 [ V_20 ] ;
V_4 -> V_7 = V_7 ;
V_4 -> V_32 = V_32 ;
V_4 -> V_26 . V_31 = V_31 ;
V_4 -> V_26 . V_38 = F_1 ;
V_4 -> V_26 . V_39 = F_1 ;
V_4 -> V_26 . V_40 = F_4 ;
V_4 -> V_24 = V_24 ;
if ( V_33 != - 1 ) {
F_22 ( V_33 , V_4 ) ;
F_23 ( V_33 , F_5 ) ;
}
V_4 -> V_15 = F_24 ( V_35 , F_25 ( V_24 ) , V_4 -> V_32 , 0 ,
& V_41 , V_4 ) ;
F_26 ( L_2 ,
V_20 , V_31 , V_7 , V_4 -> V_30 ) ;
V_20 ++ ;
}
