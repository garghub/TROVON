static int F_1 ( struct V_1 * V_2 )
{
static struct V_3 V_4 = { } ;
struct V_5 V_6 ;
int V_7 ;
int div , V_8 , V_9 ;
if ( ! V_10 ) {
F_2 ( V_11 , & V_6 ) ;
if ( V_6 . V_12 || V_6 . V_13 > V_14 ) {
F_3 ( V_15 L_1
L_2 , V_6 . V_13 ) ;
F_3 ( V_15 L_3
L_4 ) ;
F_3 ( V_15 L_5 ) ;
V_10 = 1 ;
}
}
if ( V_16 >= V_17 && V_6 . V_13 <= V_18 )
V_8 = V_19 ;
else
V_8 = V_20 ;
#if V_21
F_3 ( V_22 L_6 ,
V_16 , V_8 , V_6 . V_13 ) ;
#endif
div = V_20 / V_8 ;
V_9 = F_4 ( div ) - 1 ;
V_23 . V_24 = F_5 ( V_9 , V_25 ) ;
V_23 . V_26 = F_5 ( V_23 . V_24 , V_27 ) ;
V_23 . V_28 = 0 ;
V_23 . V_29 = 0 ;
F_6 ( & V_23 . V_30 , 0 ) ;
V_23 . V_31 = 1 ;
V_23 . V_32 = 1 ;
F_7 ( & V_23 . V_33 ) ;
V_23 . V_2 = V_2 ;
V_23 . V_34 = 0x61 ;
V_23 . V_35 = - 1 ;
V_23 . V_36 = - 1 ;
V_7 = F_8 ( V_2 , V_37 , & V_23 , & V_4 ) ;
if ( V_7 < 0 )
return V_7 ;
return 0 ;
}
static int F_9 ( int V_38 , struct V_39 * V_40 )
{
struct V_1 * V_2 ;
int V_7 ;
if ( V_38 != 0 )
return - V_41 ;
F_10 ( & V_23 . V_42 , V_11 , V_43 ) ;
V_23 . V_42 . V_44 = V_45 ;
V_7 = F_11 ( V_46 , V_47 , V_48 , 0 , & V_2 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_1 ( V_2 ) ;
if ( V_7 < 0 ) {
F_12 ( V_2 ) ;
return V_7 ;
}
if ( ! V_10 ) {
V_7 = F_13 ( & V_23 ) ;
if ( V_7 < 0 ) {
F_12 ( V_2 ) ;
return V_7 ;
}
}
V_7 = F_14 ( & V_23 , V_10 ) ;
if ( V_7 < 0 ) {
F_12 ( V_2 ) ;
return V_7 ;
}
F_15 ( V_23 . V_2 , V_40 ) ;
strcpy ( V_2 -> V_49 , L_7 ) ;
strcpy ( V_2 -> V_50 , L_8 ) ;
sprintf ( V_2 -> V_51 , L_9 ,
V_23 . V_34 ) ;
V_7 = F_16 ( V_2 ) ;
if ( V_7 < 0 ) {
F_12 ( V_2 ) ;
return V_7 ;
}
return 0 ;
}
static int F_17 ( struct V_39 * V_40 )
{
int V_7 ;
V_7 = F_9 ( 0 , V_40 ) ;
if ( V_7 ) {
F_3 ( V_15 L_10 ) ;
return V_7 ;
}
#ifdef F_18
F_3 ( V_52 L_11
L_12 ) ;
#endif
return 0 ;
}
static void F_19 ( struct V_53 * V_54 )
{
F_12 ( V_54 -> V_2 ) ;
}
static int F_20 ( struct V_55 * V_40 )
{
int V_7 ;
V_7 = F_21 ( & V_23 . V_56 , & V_40 -> V_40 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_17 ( & V_40 -> V_40 ) ;
if ( V_7 < 0 ) {
F_22 ( V_23 . V_56 ) ;
return V_7 ;
}
F_23 ( V_40 , & V_23 ) ;
return 0 ;
}
static int F_24 ( struct V_55 * V_40 )
{
struct V_53 * V_54 = F_25 ( V_40 ) ;
F_19 ( V_54 ) ;
F_22 ( V_54 -> V_56 ) ;
F_23 ( V_40 , NULL ) ;
return 0 ;
}
static void F_26 ( struct V_53 * V_54 )
{
F_27 ( V_54 ) ;
F_28 () ;
}
static int F_29 ( struct V_39 * V_40 )
{
struct V_53 * V_54 = F_30 ( V_40 ) ;
F_26 ( V_54 ) ;
F_31 ( V_54 -> V_57 ) ;
return 0 ;
}
static void F_32 ( struct V_55 * V_40 )
{
struct V_53 * V_54 = F_25 ( V_40 ) ;
F_26 ( V_54 ) ;
}
static int T_1 F_33 ( void )
{
if ( ! V_31 )
return - V_58 ;
return F_34 ( & V_59 ) ;
}
static void T_2 F_35 ( void )
{
F_36 ( & V_59 ) ;
}
