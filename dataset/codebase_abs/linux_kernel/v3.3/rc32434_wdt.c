static int F_1 ( int V_1 )
{
int V_2 = F_2 ( ( V_3 ) - 1 ) ;
if ( V_1 < 0 || V_1 > V_2 ) {
F_3 (KERN_ERR PFX L_1 ,
max_to) ;
return - V_4 ;
}
V_5 = V_1 ;
F_4 ( & V_6 . V_7 ) ;
F_5 ( F_6 ( V_5 ) , & V_8 -> V_9 ) ;
F_7 ( & V_6 . V_7 ) ;
return 0 ;
}
static void F_8 ( void )
{
V_3 V_10 , V_11 ;
F_4 ( & V_6 . V_7 ) ;
F_5 ( 0 , & V_8 -> V_12 ) ;
V_11 = 1 << V_13 ;
V_10 = 1 << V_14 ;
V_11 |= 1 << V_15 ;
F_9 ( V_8 -> V_16 , V_10 , V_11 ) ;
F_1 ( V_5 ) ;
V_11 = 1 << V_17 ;
V_10 = 1 << V_18 ;
F_9 ( V_8 -> V_19 , V_10 , V_11 ) ;
F_7 ( & V_6 . V_7 ) ;
F_3 (KERN_INFO PFX L_2 ) ;
}
static void F_10 ( void )
{
F_4 ( & V_6 . V_7 ) ;
F_9 ( V_8 -> V_19 , 0 , 1 << V_18 ) ;
F_7 ( & V_6 . V_7 ) ;
F_3 (KERN_INFO PFX L_3 ) ;
}
static void F_11 ( void )
{
F_4 ( & V_6 . V_7 ) ;
F_5 ( 0 , & V_8 -> V_12 ) ;
F_7 ( & V_6 . V_7 ) ;
}
static int F_12 ( struct V_20 * V_20 , struct V_21 * V_21 )
{
if ( F_13 ( 0 , & V_6 . V_22 ) )
return - V_23 ;
if ( V_24 )
F_14 ( V_25 ) ;
F_8 () ;
F_11 () ;
return F_15 ( V_20 , V_21 ) ;
}
static int F_16 ( struct V_20 * V_20 , struct V_21 * V_21 )
{
if ( V_26 == 42 ) {
F_10 () ;
F_17 ( V_25 ) ;
} else {
F_3 (KERN_CRIT PFX
L_4 ) ;
F_11 () ;
}
F_18 ( 0 , & V_6 . V_22 ) ;
return 0 ;
}
static T_1 F_19 ( struct V_21 * V_21 , const char * V_27 ,
T_2 V_28 , T_3 * V_29 )
{
if ( V_28 ) {
if ( ! V_24 ) {
T_2 V_30 ;
V_26 = 0 ;
for ( V_30 = 0 ; V_30 != V_28 ; V_30 ++ ) {
char V_31 ;
if ( F_20 ( V_31 , V_27 + V_30 ) )
return - V_32 ;
if ( V_31 == 'V' )
V_26 = 42 ;
}
}
F_11 () ;
return V_28 ;
}
return 0 ;
}
static long F_21 ( struct V_21 * V_21 , unsigned int V_33 ,
unsigned long V_34 )
{
void T_4 * V_35 = ( void T_4 * ) V_34 ;
int V_1 ;
unsigned int V_36 ;
static const struct V_37 V_38 = {
. V_39 = V_40 |
V_41 |
V_42 ,
. V_43 = L_5 ,
} ;
switch ( V_33 ) {
case V_44 :
if ( F_22 ( V_35 , & V_38 , sizeof( V_38 ) ) )
return - V_32 ;
break;
case V_45 :
case V_46 :
V_36 = 0 ;
if ( F_22 ( V_35 , & V_36 , sizeof( int ) ) )
return - V_32 ;
break;
case V_47 :
if ( F_23 ( & V_36 , V_35 , sizeof( int ) ) )
return - V_32 ;
switch ( V_36 ) {
case V_48 :
F_8 () ;
break;
case V_49 :
F_10 () ;
break;
default:
return - V_4 ;
}
break;
case V_50 :
F_11 () ;
break;
case V_51 :
if ( F_23 ( & V_1 , V_35 , sizeof( int ) ) )
return - V_32 ;
if ( F_1 ( V_1 ) )
return - V_4 ;
case V_52 :
return F_22 ( V_35 , & V_5 , sizeof( int ) ) ;
default:
return - V_53 ;
}
return 0 ;
}
static int T_5 F_24 ( struct V_54 * V_55 )
{
int V_56 ;
struct V_57 * V_58 ;
V_58 = F_25 ( V_55 , V_59 , L_6 ) ;
if ( ! V_58 ) {
F_3 (KERN_ERR PFX L_7 ) ;
return - V_60 ;
}
V_8 = F_26 ( V_58 -> V_61 , F_27 ( V_58 ) ) ;
if ( ! V_8 ) {
F_3 (KERN_ERR PFX L_8 ) ;
return - V_62 ;
}
F_28 ( & V_6 . V_7 ) ;
F_10 () ;
if ( F_1 ( V_5 ) ) {
F_1 ( V_63 ) ;
F_3 (KERN_INFO PFX
L_9 ,
WTCOMP2SEC((u32)-1)) ;
}
V_56 = F_29 ( & V_64 ) ;
if ( V_56 < 0 ) {
F_3 (KERN_ERR PFX L_10 ) ;
goto V_65;
}
F_3 ( V_66 , V_5 ) ;
return 0 ;
V_65:
F_30 ( V_8 ) ;
return V_56 ;
}
static int T_6 F_31 ( struct V_54 * V_55 )
{
F_32 ( & V_64 ) ;
F_30 ( V_8 ) ;
return 0 ;
}
static void F_33 ( struct V_54 * V_55 )
{
F_10 () ;
}
