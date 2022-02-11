void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
short V_5 ;
V_5 = F_2 ( 0 , V_6 , 0 , V_7 ) ;
F_3 ( V_4 -> V_8 , V_5 ) ;
V_4 -> V_8 -> V_9 |= V_10 ;
F_4 ( V_2 , V_4 ) ;
}
static int F_5 ( int V_11 , int V_12 , int V_13 , unsigned long V_14 )
{
unsigned long V_15 = V_14 ;
if ( V_11 ) {
F_6 ( V_13 , V_15 + V_16 ) ;
return 0 ;
} else {
return F_7 ( V_15 + V_17 ) ;
}
}
static int F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_18 * V_19 ,
unsigned int * V_13 )
{
if ( V_13 [ 0 ] ) {
V_4 -> V_20 &= ~ V_13 [ 0 ] ;
V_4 -> V_20 |= ( V_13 [ 0 ] & V_13 [ 1 ] ) ;
if ( V_13 [ 0 ] & 0xff )
F_2 ( 1 , V_6 , V_4 -> V_20 & 0xff ,
V_7 ) ;
}
V_13 [ 1 ] = V_4 -> V_20 & 0xff ;
V_13 [ 1 ] |= F_2 ( 0 , V_6 , 0 , V_7 ) << 8 ;
return 2 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_18 * V_19 , unsigned int * V_13 )
{
switch ( V_13 [ 0 ] ) {
case V_21 :
break;
case V_22 :
break;
case V_23 :
V_13 [ 1 ] =
( V_4 ->
V_24 & ( 1 << F_10 ( V_19 -> V_25 ) ) ) ? V_26 :
V_27 ;
return V_19 -> V_28 ;
break;
default:
return - V_29 ;
}
return 1 ;
}
static void F_11 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
return;
}
static int F_12 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_30 * V_31 )
{
int V_32 = 0 ;
unsigned int V_33 ;
V_33 = V_31 -> V_34 ;
V_31 -> V_34 &= V_35 ;
if ( ! V_31 -> V_34 || V_33 != V_31 -> V_34 )
V_32 ++ ;
V_33 = V_31 -> V_36 ;
V_31 -> V_36 &= V_37 ;
if ( ! V_31 -> V_36 || V_33 != V_31 -> V_36 )
V_32 ++ ;
V_33 = V_31 -> V_38 ;
V_31 -> V_38 &= V_39 ;
if ( ! V_31 -> V_38 || V_33 != V_31 -> V_38 )
V_32 ++ ;
V_33 = V_31 -> V_40 ;
V_31 -> V_40 &= V_41 ;
if ( ! V_31 -> V_40 || V_33 != V_31 -> V_40 )
V_32 ++ ;
V_33 = V_31 -> V_42 ;
V_31 -> V_42 &= V_43 ;
if ( ! V_31 -> V_42 || V_33 != V_31 -> V_42 )
V_32 ++ ;
if ( V_32 )
return 1 ;
if ( V_32 )
return 2 ;
if ( V_31 -> V_44 != 0 ) {
V_31 -> V_44 = 0 ;
V_32 ++ ;
}
if ( V_31 -> V_45 != 0 ) {
V_31 -> V_45 = 0 ;
V_32 ++ ;
}
if ( V_31 -> V_46 != 0 ) {
V_31 -> V_46 = 0 ;
V_32 ++ ;
}
if ( V_31 -> V_47 != 1 ) {
V_31 -> V_47 = 1 ;
V_32 ++ ;
}
if ( V_31 -> V_48 != 0 ) {
V_31 -> V_48 = 0 ;
V_32 ++ ;
}
if ( V_32 )
return 3 ;
if ( V_32 )
return 4 ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
return 0 ;
}
static int F_14 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
return 0 ;
}
int F_15 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int (* F_16) ( int , int , int , unsigned long ) , unsigned long V_14 )
{
V_4 -> type = V_49 ;
V_4 -> V_50 = V_51 | V_52 ;
V_4 -> V_53 = 16 ;
V_4 -> V_54 = & V_55 ;
V_4 -> V_56 = 1 ;
V_4 -> V_57 = F_17 ( sizeof( struct V_58 ) , V_59 ) ;
if ( ! V_4 -> V_57 )
return - V_60 ;
V_7 = V_14 ;
if ( F_16 == NULL )
F_2 = F_5 ;
else
F_2 = F_16 ;
V_4 -> V_61 = F_8 ;
V_4 -> V_62 = F_9 ;
V_4 -> V_20 = 0 ;
V_4 -> V_24 = 0x00ff ;
F_11 ( V_2 , V_4 ) ;
return 0 ;
}
int F_18 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int (* F_16) ( int , int , int , unsigned long ) ,
unsigned long V_14 )
{
int V_63 ;
V_63 = F_15 ( V_2 , V_4 , F_16 , V_14 ) ;
if ( V_63 < 0 )
return V_63 ;
V_4 -> V_64 = F_12 ;
V_4 -> V_65 = F_13 ;
V_4 -> V_66 = F_14 ;
V_67 -> V_68 = 1 ;
return 0 ;
}
void F_19 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( V_4 -> V_57 )
if ( V_67 -> V_68 )
F_20 ( V_4 -> V_57 ) ;
}
static int F_21 ( struct V_1 * V_2 , struct V_69 * V_70 )
{
struct V_3 * V_4 ;
unsigned long V_15 = 0 ;
#ifdef F_22
unsigned int V_71 = 0 ;
#endif
struct V_72 * V_73 ;
if ( F_23 ( V_2 , sizeof( struct V_74 ) ) < 0 )
return - V_60 ;
switch ( V_75 -> V_76 ) {
case V_77 :
V_73 = V_78 ;
if ( ! V_73 )
return - V_79 ;
V_15 = V_73 -> V_80 [ 0 ] -> V_81 ;
#ifdef F_22
V_71 = V_73 -> V_71 ;
#endif
break;
default:
F_24 ( V_82 L_1 ) ;
return - V_29 ;
break;
}
F_24 ( V_82 L_2 , V_2 -> V_83 ,
V_75 -> V_84 , V_15 ) ;
#ifdef F_22
if ( V_71 )
F_24 ( L_3 , V_71 ) ;
#endif
F_24 ( L_4 ) ;
if ( V_15 == 0 ) {
F_24 ( V_82 L_5 ) ;
return - V_29 ;
}
V_2 -> V_15 = V_15 ;
#ifdef F_22
V_2 -> V_71 = V_71 ;
#endif
V_2 -> V_85 = V_75 -> V_84 ;
if ( F_25 ( V_2 , 1 ) < 0 )
return - V_60 ;
V_4 = V_2 -> V_86 + 0 ;
F_15 ( V_2 , V_4 , NULL , V_2 -> V_15 ) ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 )
{
F_24 ( V_82 L_6 , V_2 -> V_83 ) ;
if ( V_2 -> V_86 )
F_19 ( V_2 , V_2 -> V_86 + 0 ) ;
if ( V_75 -> V_76 != V_77 && V_2 -> V_15 )
F_27 ( V_2 -> V_15 , V_87 ) ;
if ( V_2 -> V_71 )
F_28 ( V_2 -> V_71 , V_2 ) ;
return 0 ;
}
static int F_29 ( struct V_72 * V_73 )
{
struct V_88 * V_89 ;
F_24 ( V_90 L_7 ) ;
F_30 ( & V_73 -> V_2 , L_8 ) ;
V_89 = F_31 ( sizeof( struct V_88 ) , V_59 ) ;
if ( ! V_89 )
return - V_60 ;
V_89 -> V_73 = V_73 ;
V_73 -> V_91 = V_89 ;
V_78 = V_73 ;
F_32 ( V_73 ) ;
return 0 ;
}
static void F_33 ( struct V_72 * V_73 )
{
F_24 ( V_90 L_9 ) ;
F_30 ( & V_73 -> V_2 , L_10 ) ;
( (struct V_88 * ) V_73 -> V_91 ) -> V_92 = 1 ;
F_34 ( V_73 ) ;
F_20 ( V_73 -> V_91 ) ;
}
static int F_35 ( struct V_72 * V_93 ,
void * V_94 )
{
if ( V_93 -> V_95 == 0 )
return - V_29 ;
return F_36 ( V_93 ) ;
}
static void F_32 ( struct V_72 * V_73 )
{
int V_63 ;
F_24 ( V_90 L_11 ) ;
F_30 ( & V_73 -> V_2 , L_12 ) ;
V_73 -> V_96 |= V_97 | V_98 |
V_99 ;
V_63 = F_37 ( V_73 , F_35 , NULL ) ;
if ( V_63 ) {
F_38 ( & V_73 -> V_2 , L_13 ) ;
goto V_100;
}
if ( ! V_73 -> V_71 )
goto V_100;
V_63 = F_39 ( V_73 ) ;
if ( V_63 != 0 )
goto V_100;
return;
V_100:
F_24 ( V_90 L_14 ) ;
F_34 ( V_73 ) ;
}
static void F_34 ( struct V_72 * V_73 )
{
F_30 ( & V_73 -> V_2 , L_15 ) ;
F_40 ( V_73 ) ;
}
static int F_41 ( struct V_72 * V_73 )
{
struct V_88 * V_89 = V_73 -> V_91 ;
V_89 -> V_92 = 1 ;
return 0 ;
}
static int F_42 ( struct V_72 * V_73 )
{
struct V_88 * V_89 = V_73 -> V_91 ;
V_89 -> V_92 = 0 ;
return 0 ;
}
static int T_1 F_43 ( void )
{
F_44 ( & V_101 ) ;
return 0 ;
}
static void T_2 F_45 ( void )
{
F_46 ( L_16 ) ;
F_47 ( & V_101 ) ;
}
int T_1 F_48 ( void )
{
int V_63 ;
V_63 = F_43 () ;
if ( V_63 < 0 )
return V_63 ;
return F_49 ( & V_102 ) ;
}
void T_2 F_50 ( void )
{
F_45 () ;
F_51 ( & V_102 ) ;
}
