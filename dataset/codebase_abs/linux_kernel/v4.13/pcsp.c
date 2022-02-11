static int F_1 ( struct V_1 * V_2 )
{
static struct V_3 V_4 = { } ;
unsigned int V_5 = V_6 ;
int V_7 , div , V_8 , V_9 ;
if ( ! V_10 ) {
if ( V_5 > V_11 ) {
F_2 ( V_12 L_1
L_2 , V_5 ) ;
F_2 ( V_12 L_3
L_4 ) ;
F_2 ( V_12 L_5 ) ;
V_10 = 1 ;
}
}
if ( V_13 >= V_14 && V_5 <= V_15 )
V_8 = V_16 ;
else
V_8 = V_17 ;
#if V_18
F_2 ( V_19 L_6 ,
V_13 , V_8 , V_5 ) ;
#endif
div = V_17 / V_8 ;
V_9 = F_3 ( div ) - 1 ;
V_20 . V_21 = F_4 ( V_9 , V_22 ) ;
V_20 . V_23 = F_4 ( V_20 . V_21 , V_24 ) ;
V_20 . V_25 = 0 ;
V_20 . V_26 = 0 ;
F_5 ( & V_20 . V_27 , 0 ) ;
V_20 . V_28 = 1 ;
V_20 . V_29 = 1 ;
F_6 ( & V_20 . V_30 ) ;
V_20 . V_2 = V_2 ;
V_20 . V_31 = 0x61 ;
V_20 . V_32 = - 1 ;
V_20 . V_33 = - 1 ;
V_7 = F_7 ( V_2 , V_34 , & V_20 , & V_4 ) ;
if ( V_7 < 0 )
return V_7 ;
return 0 ;
}
static int F_8 ( int V_35 , struct V_36 * V_37 )
{
struct V_1 * V_2 ;
int V_7 ;
if ( V_35 != 0 )
return - V_38 ;
F_9 ( & V_20 . V_39 , V_40 , V_41 ) ;
V_20 . V_39 . V_42 = V_43 ;
V_7 = F_10 ( V_37 , V_44 , V_45 , V_46 , 0 , & V_2 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_1 ( V_2 ) ;
if ( V_7 < 0 ) {
F_11 ( V_2 ) ;
return V_7 ;
}
if ( ! V_10 ) {
V_7 = F_12 ( & V_20 ) ;
if ( V_7 < 0 ) {
F_11 ( V_2 ) ;
return V_7 ;
}
}
V_7 = F_13 ( & V_20 , V_10 ) ;
if ( V_7 < 0 ) {
F_11 ( V_2 ) ;
return V_7 ;
}
strcpy ( V_2 -> V_47 , L_7 ) ;
strcpy ( V_2 -> V_48 , L_8 ) ;
sprintf ( V_2 -> V_49 , L_9 ,
V_20 . V_31 ) ;
V_7 = F_14 ( V_2 ) ;
if ( V_7 < 0 ) {
F_11 ( V_2 ) ;
return V_7 ;
}
return 0 ;
}
static int F_15 ( struct V_36 * V_37 )
{
int V_7 ;
V_7 = F_8 ( 0 , V_37 ) ;
if ( V_7 ) {
F_2 ( V_12 L_10 ) ;
return V_7 ;
}
if ( F_16 () ) {
F_2 ( V_50 L_11
L_12 ) ;
}
return 0 ;
}
static void F_17 ( struct V_51 * V_52 )
{
F_11 ( V_52 -> V_2 ) ;
}
static int F_18 ( struct V_53 * V_37 )
{
int V_7 ;
V_7 = F_19 ( & V_20 . V_54 , & V_37 -> V_37 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_15 ( & V_37 -> V_37 ) ;
if ( V_7 < 0 ) {
F_20 ( V_20 . V_54 ) ;
return V_7 ;
}
F_21 ( V_37 , & V_20 ) ;
return 0 ;
}
static int F_22 ( struct V_53 * V_37 )
{
struct V_51 * V_52 = F_23 ( V_37 ) ;
F_20 ( V_52 -> V_54 ) ;
F_17 ( V_52 ) ;
return 0 ;
}
static void F_24 ( struct V_51 * V_52 )
{
F_25 ( V_52 ) ;
F_26 () ;
}
static int F_27 ( struct V_36 * V_37 )
{
struct V_51 * V_52 = F_28 ( V_37 ) ;
F_24 ( V_52 ) ;
F_29 ( V_52 -> V_55 ) ;
return 0 ;
}
static void F_30 ( struct V_53 * V_37 )
{
struct V_51 * V_52 = F_23 ( V_37 ) ;
F_24 ( V_52 ) ;
}
static int T_1 F_31 ( void )
{
if ( ! V_28 )
return - V_56 ;
return F_32 ( & V_57 ) ;
}
static void T_2 F_33 ( void )
{
F_34 ( & V_57 ) ;
}
