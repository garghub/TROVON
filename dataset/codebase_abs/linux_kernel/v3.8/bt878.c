static void F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 ) {
F_2 ( V_2 -> V_4 , V_2 -> V_5 , V_2 -> V_3 ,
V_2 -> V_6 ) ;
V_2 -> V_3 = NULL ;
}
if ( V_2 -> V_7 ) {
F_2 ( V_2 -> V_4 , V_2 -> V_8 , V_2 -> V_7 ,
V_2 -> V_9 ) ;
V_2 -> V_7 = NULL ;
}
}
static int F_3 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_3 ) {
V_2 -> V_5 = 128 * 1024 ;
V_2 -> V_3 =
F_4 ( V_2 -> V_4 , V_2 -> V_5 ,
& V_2 -> V_6 ) ;
if ( ! V_2 -> V_3 )
return - V_10 ;
memset ( V_2 -> V_3 , 0 , V_2 -> V_5 ) ;
}
if ( ! V_2 -> V_7 ) {
V_2 -> V_8 = V_11 ;
V_2 -> V_7 =
F_4 ( V_2 -> V_4 , V_2 -> V_8 ,
& V_2 -> V_9 ) ;
if ( ! V_2 -> V_7 ) {
F_1 ( V_2 ) ;
return - V_10 ;
}
memset ( V_2 -> V_7 , 0 , V_2 -> V_8 ) ;
}
return 0 ;
}
static int F_5 ( struct V_1 * V_2 )
{
V_2 -> V_12 = V_2 -> V_5 >> 4 ;
V_2 -> V_13 = 1 << 4 ;
V_2 -> V_14 = V_2 -> V_12 ;
V_2 -> V_15 = V_2 -> V_13 ;
while ( V_2 -> V_14 > 4095 ) {
V_2 -> V_14 >>= 1 ;
V_2 -> V_15 <<= 1 ;
}
if ( V_2 -> V_15 > 255 ) {
F_6 ( V_16 L_1 ) ;
return - V_17 ;
}
return 0 ;
}
static void F_7 ( struct V_1 * V_2 , T_1 V_18 )
{
T_1 V_19 = 0 ;
T_1 line ;
F_8 () ;
F_9 ( V_20 | V_21 | V_18 ) ;
F_9 ( 0 ) ;
F_10 ( L_2 ,
V_2 -> V_15 , V_2 -> V_14 ) ;
for ( line = 0 ; line < V_2 -> V_15 ; line ++ ) {
if ( ! ( V_19 % V_2 -> V_12 ) )
F_9 ( V_22 | V_23 | V_24 |
V_25 |
F_11 ( ( ( V_19 /
V_2 -> V_12 ) +
( V_2 -> V_13 -
1 ) ) %
V_2 -> V_13 ) | V_2 ->
V_14 ) ;
else
F_9 ( V_22 | V_23 | V_24 |
V_2 -> V_14 ) ;
F_9 ( V_2 -> V_6 + V_19 ) ;
V_19 += V_2 -> V_14 ;
}
F_9 ( V_20 | V_18 | V_26 ) ;
F_9 ( 0 ) ;
F_9 ( V_27 ) ;
F_9 ( V_2 -> V_9 ) ;
F_12 ( ( V_2 -> V_15 << 16 ) | V_2 -> V_14 , V_28 ) ;
}
void F_13 ( struct V_1 * V_2 , T_1 V_29 , T_1 V_18 ,
T_1 V_30 )
{
T_1 V_31 ;
F_10 ( L_3 , V_29 ) ;
F_7 ( V_2 , V_18 ) ;
V_29 &= ~ 0x1f ;
V_29 |= 0x1b ;
F_12 ( V_2 -> V_9 , V_32 ) ;
V_31 = V_33 | V_34 | V_35 |
V_36 | V_37 | V_38 | V_39 |
V_40 | V_41 ;
V_31 &= ~ V_30 ;
F_12 ( V_31 , V_42 ) ;
F_12 ( V_29 , V_43 ) ;
}
void F_14 ( struct V_1 * V_2 )
{
T_1 V_44 ;
int V_45 = 0 ;
F_10 ( L_4 ) ;
F_12 ( 0 , V_42 ) ;
F_15 ( ~ 0x13 , V_43 ) ;
do {
V_44 = F_16 ( V_46 ) ;
if ( ! ( V_44 & V_47 ) )
break;
V_45 ++ ;
} while ( V_45 < 500 );
F_10 ( L_5 ,
V_2 -> V_48 , V_45 , V_44 ) ;
}
static T_2 F_17 ( int V_49 , void * V_50 )
{
T_1 V_44 , V_51 , V_52 ;
int V_53 ;
struct V_1 * V_2 ;
V_2 = (struct V_1 * ) V_50 ;
V_53 = 0 ;
while ( 1 ) {
V_44 = F_16 ( V_46 ) ;
V_52 = F_16 ( V_42 ) ;
if ( ! ( V_51 = ( V_44 & V_52 ) ) )
return V_54 ;
F_12 ( V_51 , V_46 ) ;
if ( V_51 & ( V_33 | V_34 ) ) {
if ( V_55 ) {
F_6 ( V_56
L_6 ,
V_2 -> V_48 ,
( V_51 & V_33 ) ? L_7 :
L_8 ,
( V_51 & V_34 ) ? L_9 :
L_8 , F_16 ( V_57 ) ) ;
}
}
if ( V_51 & ( V_35 | V_36 | V_37 ) ) {
if ( V_55 ) {
F_6 ( V_56
L_10 ,
V_2 -> V_48 ,
( V_51 & V_35 ) ? L_11 :
L_8 ,
( V_51 & V_36 ) ? L_12 :
L_8 ,
( V_51 & V_37 ) ? L_13 :
L_8 , F_16 ( V_57 ) ) ;
}
}
if ( V_51 & ( V_38 | V_39 | V_40 ) ) {
if ( V_55 ) {
F_6 ( V_56
L_10 ,
V_2 -> V_48 ,
( V_51 & V_38 ) ? L_14 : L_8 ,
( V_51 & V_39 ) ? L_15 :
L_8 ,
( V_51 & V_40 ) ? L_16 : L_8 ,
F_16 ( V_57 ) ) ;
}
}
if ( V_51 & V_41 ) {
V_2 -> V_58 = ( V_44 & V_59 ) >> 28 ;
F_18 ( & V_2 -> V_60 ) ;
break;
}
V_53 ++ ;
if ( V_53 > 20 ) {
F_12 ( 0 , V_42 ) ;
F_6 ( V_16
L_17 ,
V_2 -> V_48 ) ;
break;
}
}
return V_61 ;
}
int
F_19 ( struct V_1 * V_2 , unsigned int V_62 , union V_63 * V_64 )
{
int V_65 ;
V_65 = 0 ;
if ( F_20 ( & V_2 -> V_66 ) )
return - V_67 ;
switch ( V_62 ) {
case V_68 :
V_65 = F_21 ( V_2 -> V_69 ,
V_64 -> V_70 . V_52 ,
V_64 -> V_70 . V_71 ) ;
break;
case V_72 :
V_65 = F_22 ( V_2 -> V_69 ,
V_64 -> V_73 . V_52 ,
V_64 -> V_73 . V_74 ) ;
break;
case V_75 :
V_65 = F_23 ( V_2 -> V_69 , & V_64 -> V_76 . V_77 ) ;
break;
case V_78 :
V_2 -> V_79 = V_64 -> V_80 ;
break;
default:
V_65 = - V_17 ;
break;
}
F_24 ( & V_2 -> V_66 ) ;
return V_65 ;
}
static const char * F_25 ( const struct V_81 * V_82 )
{
return V_82 -> V_83 ? ( const char * ) V_82 -> V_83 : L_18 ;
}
static int F_26 ( struct V_84 * V_4 , const struct V_81 * V_85 )
{
int V_86 = 0 ;
unsigned char V_87 ;
struct V_1 * V_2 ;
#if F_27 ( V_88 )
unsigned int V_62 ;
#endif
unsigned int V_89 ;
F_6 ( V_56 L_19 ,
V_90 ) ;
if ( V_90 >= V_91 ) {
F_6 ( V_16 L_20 ) ;
V_86 = - V_10 ;
goto V_92;
}
if ( F_28 ( V_4 ) )
return - V_93 ;
V_89 = V_4 -> V_94 << 16 ;
V_89 |= V_4 -> V_95 ;
F_6 ( V_56 L_21 ,
V_96 , V_89 , F_25 ( V_85 ) ) ;
V_2 = & V_1 [ V_90 ] ;
V_2 -> V_4 = V_4 ;
V_2 -> V_48 = V_90 ;
V_2 -> V_97 = 0 ;
V_2 -> V_82 = V_4 -> V_98 ;
V_2 -> V_49 = V_4 -> V_49 ;
V_2 -> V_99 = F_29 ( V_4 , 0 ) ;
if ( ! F_30 ( F_29 ( V_4 , 0 ) ,
F_31 ( V_4 , 0 ) , L_22 ) ) {
V_86 = - V_100 ;
goto V_92;
}
V_2 -> V_101 = V_4 -> V_101 ;
F_32 ( V_4 , V_102 , & V_87 ) ;
F_6 ( V_56 L_23 ,
V_90 , V_2 -> V_82 , V_2 -> V_101 , V_4 -> V_103 -> V_104 ,
F_33 ( V_4 -> V_105 ) , F_34 ( V_4 -> V_105 ) ) ;
F_6 ( L_24 ,
V_2 -> V_49 , V_87 , V_2 -> V_99 ) ;
#if F_27 ( V_88 )
F_35 ( V_4 , V_106 , & V_62 ) ;
V_62 = ( V_62 | V_107 ) ;
F_36 ( V_4 , V_106 , V_62 ) ;
#endif
#ifdef F_37
V_2 -> V_108 = ( unsigned char * ) V_2 -> V_99 ;
#else
V_2 -> V_108 = F_38 ( V_2 -> V_99 , 0x1000 ) ;
#endif
F_12 ( 0 , V_109 ) ;
V_86 = F_39 ( V_2 -> V_49 , F_17 ,
V_110 | V_111 , L_22 ,
( void * ) V_2 ) ;
if ( V_86 == - V_17 ) {
F_6 ( V_16 L_25 ,
V_90 ) ;
goto V_112;
}
if ( V_86 == - V_100 ) {
F_6 ( V_16
L_26 ,
V_90 , V_2 -> V_49 ) ;
goto V_112;
}
if ( V_86 < 0 )
goto V_112;
F_40 ( V_4 ) ;
F_41 ( V_4 , V_2 ) ;
if ( ( V_86 = F_3 ( V_2 ) ) ) {
F_6 ( V_16 L_27 ) ;
goto V_113;
}
F_5 ( V_2 ) ;
F_12 ( 0 , V_42 ) ;
V_90 ++ ;
return 0 ;
V_113:
F_42 ( V_2 -> V_49 , V_2 ) ;
V_112:
F_43 ( F_29 ( V_2 -> V_4 , 0 ) ,
F_31 ( V_2 -> V_4 , 0 ) ) ;
V_92:
F_44 ( V_4 ) ;
return V_86 ;
}
static void F_45 ( struct V_84 * V_84 )
{
T_3 V_114 ;
struct V_1 * V_2 = F_46 ( V_84 ) ;
if ( V_55 )
F_6 ( V_56 L_28 , V_2 -> V_48 ) ;
F_15 ( ~ 0x13 , V_43 ) ;
F_12 ( 0 , V_42 ) ;
F_12 ( ~ 0U , V_46 ) ;
F_32 ( V_2 -> V_4 , V_106 , & V_114 ) ;
V_114 &= ~ V_115 ;
F_47 ( V_2 -> V_4 , V_106 , V_114 ) ;
F_42 ( V_2 -> V_49 , V_2 ) ;
F_6 ( V_116 L_29 , V_2 -> V_108 ) ;
if ( V_2 -> V_108 )
F_48 ( V_2 -> V_108 ) ;
F_43 ( F_29 ( V_2 -> V_4 , 0 ) ,
F_31 ( V_2 -> V_4 , 0 ) ) ;
V_2 -> V_97 = 1 ;
F_1 ( V_2 ) ;
F_41 ( V_84 , NULL ) ;
F_44 ( V_84 ) ;
return;
}
static int T_4 F_49 ( void )
{
V_90 = 0 ;
F_6 ( V_56 L_30 ,
( V_117 >> 16 ) & 0xff ,
( V_117 >> 8 ) & 0xff ,
V_117 & 0xff ) ;
return F_50 ( & V_118 ) ;
}
static void T_5 F_51 ( void )
{
F_52 ( & V_118 ) ;
}
