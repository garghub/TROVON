static void F_1 ( void )
{
F_2 ( & V_1 ) ;
F_3 ( & V_2 -> V_3 , 0x556c ) ;
F_3 ( & V_2 -> V_3 , 0xaa39 ) ;
F_4 ( & V_1 ) ;
}
static void F_5 ( unsigned long V_4 )
{
F_1 () ;
F_6 ( & V_5 , V_6 + V_7 * V_8 / 2 ) ;
}
static void F_7 ( const char * V_9 )
{
F_8 ( L_1 , V_9 ,
V_10 ? L_2 : L_3 ) ;
}
static T_1 F_9 ( struct V_11 * V_11 , const char T_2 * V_12 ,
T_3 V_13 , T_4 * V_14 )
{
if ( V_13 )
F_1 () ;
return V_13 ;
}
static int F_10 ( struct V_15 * V_15 , struct V_11 * V_11 )
{
T_5 V_16 = V_17 ;
if ( F_11 ( 0 , & V_18 ) )
return - V_19 ;
if ( V_20 )
F_12 ( V_21 ) ;
if ( V_22 )
V_16 |= V_23 ;
if ( V_10 )
V_16 |= V_24 ;
V_16 |= V_25 << 16 ;
F_13 ( & V_2 -> V_26 , V_16 ) ;
F_14 ( & V_5 ) ;
return F_15 ( V_15 , V_11 ) ;
}
static int F_16 ( struct V_15 * V_15 , struct V_11 * V_11 )
{
if ( ! V_20 )
F_5 ( 0 ) ;
else
F_7 ( L_4 ) ;
F_17 ( 0 , & V_18 ) ;
return 0 ;
}
static long F_18 ( struct V_11 * V_11 , unsigned int V_27 ,
unsigned long V_4 )
{
void T_2 * V_28 = ( void T_2 * ) V_4 ;
int T_2 * V_29 = V_28 ;
static const struct V_30 V_31 = {
. V_32 = V_33 ,
. V_34 = 1 ,
. V_35 = L_5 ,
} ;
switch ( V_27 ) {
case V_36 :
return F_19 ( V_28 , & V_31 , sizeof( V_31 ) ) ? - V_37 : 0 ;
case V_38 :
case V_39 :
return F_20 ( 0 , V_29 ) ;
case V_40 :
F_1 () ;
return 0 ;
case V_41 :
return F_20 ( V_8 , V_29 ) ;
default:
return - V_42 ;
}
}
static int T_6 F_21 ( struct V_43 * V_44 )
{
int V_45 ;
const struct V_46 * V_47 ;
struct V_48 * V_49 = V_44 -> V_50 . V_51 ;
struct V_52 * V_53 ;
T_5 V_54 = F_22 () ;
bool V_55 ;
V_47 = F_23 ( V_56 , & V_44 -> V_50 ) ;
if ( ! V_47 )
return - V_57 ;
V_53 = V_47 -> V_58 ;
if ( ! V_54 || V_54 == - 1 )
return - V_57 ;
V_2 = F_24 ( V_49 , 0 ) ;
if ( ! V_2 )
return - V_59 ;
V_55 = F_25 ( & V_2 -> V_26 ) & V_17 ;
if ( ! V_55 && V_53 -> V_60 ) {
F_26 ( L_6 ) ;
V_45 = - V_61 ;
goto V_62;
}
if ( V_22 )
V_8 = ( V_25 * V_53 -> V_63 ) / V_54 ;
else
V_8 = V_25 / V_54 ;
#ifdef F_27
V_45 = F_28 () ;
if ( V_45 )
goto V_62;
#endif
F_26 ( L_7 ,
V_10 ? L_2 : L_8 , V_25 , V_8 ) ;
if ( V_55 )
F_5 ( 0 ) ;
return 0 ;
V_62:
F_29 ( V_2 ) ;
V_2 = NULL ;
return V_45 ;
}
static int T_7 F_30 ( struct V_43 * V_44 )
{
F_7 ( L_9 ) ;
F_14 ( & V_5 ) ;
F_31 ( & V_64 ) ;
F_29 ( V_2 ) ;
return 0 ;
}
static int F_28 ( void )
{
int V_45 ;
if ( ! V_2 )
return - V_65 ;
V_45 = F_32 ( & V_64 ) ;
if ( V_45 ) {
F_33 ( L_10 ,
V_66 , V_45 ) ;
return V_45 ;
}
return 0 ;
}
static int T_8 F_34 ( void )
{
return F_35 ( & V_67 ) ;
}
static void T_9 F_36 ( void )
{
F_37 ( & V_67 ) ;
}
