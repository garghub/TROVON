static void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 = F_2 ( F_3 ( V_2 -> V_4 ) ) ;
V_3 &= ~ V_5 ;
F_4 ( V_3 , F_3 ( V_2 -> V_4 ) ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
T_1 V_3 = F_2 ( F_3 ( V_2 -> V_4 ) ) ;
V_3 |= V_5 ;
F_4 ( V_3 , F_3 ( V_2 -> V_4 ) ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
if ( V_2 -> V_4 == V_6 )
F_7 () ;
}
static void F_8 ( struct V_7 * V_8 , int V_9 , int V_10 )
{
int V_4 ;
for ( V_4 = V_9 ; V_10 > 0 ; V_4 ++ , V_10 -- ) {
struct V_1 * V_2 = F_9 ( V_4 ) ;
V_8 -> V_11 ( V_2 ) ;
if ( V_8 -> V_12 )
V_8 -> V_12 ( V_2 ) ;
F_10 ( V_4 , V_8 ) ;
F_11 ( V_4 , V_13 ) ;
F_12 ( V_4 , V_14 ) ;
}
}
void T_2 F_13 ( void )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_15 ; V_4 ++ ) {
F_1 ( F_9 ( V_4 ) ) ;
F_10 ( V_4 , & V_16 ) ;
F_11 ( V_4 , V_13 ) ;
switch ( V_4 ) {
case V_17 :
case V_18 :
case V_19 :
case V_20 :
case V_21 :
break;
default:
F_12 ( V_4 , V_14 ) ;
break;
}
}
V_22 . V_12 = F_6 ;
F_8 ( & V_22 , V_23 , 2 ) ;
F_8 ( & V_24 , V_25 , 2 ) ;
F_8 ( & V_26 , V_27 , 5 ) ;
F_8 ( & V_28 , V_29 , 15 ) ;
F_8 ( & V_30 , V_31 , 2 ) ;
F_14 ( V_17 , V_32 ) ;
F_14 ( V_18 , V_33 ) ;
F_14 ( V_19 , V_34 ) ;
F_14 ( V_20 , V_35 ) ;
F_14 ( V_21 , V_36 ) ;
}
