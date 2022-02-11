static int F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_3 . V_4 -> V_5 , 0 ) ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_4 ( V_2 ) ;
V_7 -> V_8 = V_9 ;
F_5 ( V_7 , L_1 ) ;
return F_1 ( V_2 ) ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_4 ( V_2 ) ;
F_5 ( V_7 , L_2 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = F_8 ( V_2 -> V_3 . V_12 ) ;
struct V_10 * V_13 ;
V_13 = F_9 ( V_11 -> V_14 , F_10 ( F_11 ( V_11 -> V_15 ) , 1 ) ) ;
if ( V_13 && V_13 -> V_16 == V_17
&& V_13 -> V_18 == V_19 ) {
struct V_6 * V_7 = F_4 ( V_2 ) ;
V_7 -> V_8 |= V_20 ;
F_5 ( V_7 , L_3 ) ;
}
F_12 ( V_13 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_4 ( V_2 ) ;
V_7 -> V_8 |= V_21 ;
F_5 ( V_7 , L_4 ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_4 ( V_2 ) ;
#ifdef F_15
V_7 -> V_8 |= V_22 ;
F_5 ( V_7 , L_5 ) ;
return 0 ;
#else
F_16 ( V_7 , L_6 ) ;
return - V_23 ;
#endif
}
static void F_17 ( struct V_24 * V_25 )
{
struct V_6 * V_7 = F_18 ( V_25 , struct V_6 , V_26 ) ;
int V_27 ;
V_27 = F_19 ( V_7 ) ;
if ( V_27 != 0 )
F_16 ( V_7 , L_7 ,
L_8 , V_27 ) ;
}
static int F_20 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_4 ( V_2 ) ;
V_7 -> V_8 |= V_28 ;
F_21 ( & V_7 -> V_26 , F_17 ) ;
F_5 ( V_7 , L_9 ) ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_4 ( V_2 ) ;
if ( F_23 () )
V_7 -> V_8 |= V_29 ;
if ( F_24 () ) {
V_7 -> V_8 |= V_30 ;
F_5 ( V_7 , L_10 ) ;
}
V_7 -> V_8 |= V_31 ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_4 ( V_2 ) ;
V_7 -> V_8 |= V_32 ;
F_5 ( V_7 , L_11 ) ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_4 ( V_2 ) ;
struct V_10 * V_11 = F_8 ( V_2 -> V_3 . V_12 ) ;
int V_33 = 0 ;
if ( V_2 -> V_3 . V_12 ) {
const struct V_34 * V_35 ;
V_35 = F_27 ( V_36 , V_11 ) ;
if ( V_35 != NULL ) {
int (* F_28)( struct V_1 * V_7 );
F_28 = ( void * ) V_35 -> V_37 ;
V_33 = F_28 ( V_2 ) ;
}
}
if ( V_33 == 0 )
V_33 = F_29 ( V_2 ) ;
if ( F_30 ( & V_11 -> V_5 ) )
V_7 -> V_38 |= V_39 ;
return V_33 ;
}
static int T_1 F_31 ( void )
{
if ( F_32 () )
return - V_40 ;
F_33 ( L_12 V_41 L_13 , V_42 ) ;
F_34 ( & V_43 , & V_44 ) ;
#ifdef F_35
V_43 . V_45 = V_46 ;
V_43 . V_47 = V_48 ;
#endif
return F_36 ( & V_49 ) ;
}
static void T_2 F_37 ( void )
{
F_38 ( & V_49 ) ;
}
