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
struct V_10 * V_29 ;
T_1 V_30 ;
if ( F_23 () )
V_7 -> V_8 |= V_31 ;
V_29 = F_24 ( V_32 ,
V_33 , NULL ) ;
if ( ! V_29 )
return 0 ;
V_30 = V_29 -> V_34 ;
if ( ( V_30 >= 0x40 ) && ( V_30 <= 0x4f ) ) {
V_7 -> V_8 |= V_35 ;
F_5 ( V_7 , L_10 ) ;
}
F_12 ( V_29 ) ;
V_29 = NULL ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_4 ( V_2 ) ;
struct V_10 * V_11 = F_8 ( V_2 -> V_3 . V_12 ) ;
int V_36 = 0 ;
if ( V_2 -> V_3 . V_12 ) {
const struct V_37 * V_38 ;
V_38 = F_26 ( V_39 , V_11 ) ;
if ( V_38 != NULL ) {
int (* F_27)( struct V_1 * V_7 );
F_27 = ( void * ) V_38 -> V_40 ;
V_36 = F_27 ( V_2 ) ;
}
}
if ( V_36 == 0 )
V_36 = F_28 ( V_2 ) ;
if ( F_29 ( & V_11 -> V_5 ) )
V_7 -> V_41 |= V_42 ;
return V_36 ;
}
static int T_2 F_30 ( void )
{
if ( F_31 () )
return - V_43 ;
F_32 ( L_11 V_44 L_12 , V_45 ) ;
F_33 ( & V_46 , & V_47 ) ;
#ifdef F_34
V_46 . V_48 = V_49 ;
V_46 . V_50 = V_51 ;
#endif
return F_35 ( & V_52 ) ;
}
static void T_3 F_36 ( void )
{
F_37 ( & V_52 ) ;
}
