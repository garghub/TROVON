static int F_1 ( int V_1 , struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
F_3 ( L_1 , V_1 , V_3 ) ;
switch ( V_1 ) {
case V_6 :
V_5 -> V_7 -> V_8 |= V_9 ;
F_4 () ;
break;
case V_10 :
case V_11 :
case V_12 :
V_5 -> V_7 -> V_8 &= ~ V_9 ;
F_4 () ;
break;
default:
break;
}
return 0 ;
}
int F_5 ( struct V_4 * V_5 )
{
struct V_2 * V_13 = & V_5 -> V_13 ;
T_1 V_14 ;
int V_15 ;
if ( ! V_5 )
return - V_16 ;
if ( F_6 ( V_5 -> V_17 ) || F_7 ( V_5 -> V_17 ) ) {
if ( V_13 -> V_18 . V_19 <= 8 ) {
V_13 -> V_18 . V_20 . V_21 = 0 ;
V_13 -> V_18 . V_20 . V_22 = V_13 -> V_18 . V_19 ;
V_13 -> V_18 . V_20 . V_23 = 0 ;
V_13 -> V_18 . V_24 . V_21 = 0 ;
V_13 -> V_18 . V_24 . V_22 = V_13 -> V_18 . V_19 ;
V_13 -> V_18 . V_24 . V_23 = 0 ;
V_13 -> V_18 . V_25 . V_21 = 0 ;
V_13 -> V_18 . V_25 . V_22 = V_13 -> V_18 . V_19 ;
V_13 -> V_18 . V_25 . V_23 = 0 ;
V_13 -> V_18 . V_26 . V_21 = 0 ;
V_13 -> V_18 . V_26 . V_22 = 0 ;
V_13 -> V_18 . V_26 . V_23 = 0 ;
V_13 -> V_27 . V_28 = V_29 ;
V_13 -> V_27 . V_30 = V_13 -> V_18 . V_31 /
( 8 / V_13 -> V_18 . V_19 ) ;
} else {
V_15 = ( V_5 -> V_17 -> V_32 & V_33 ) >> V_34 ;
V_13 -> V_18 . V_20 = V_35 [ V_15 ] [ 0 ] ;
V_13 -> V_18 . V_24 = V_35 [ V_15 ] [ 1 ] ;
V_13 -> V_18 . V_25 = V_35 [ V_15 ] [ 2 ] ;
V_13 -> V_18 . V_26 = V_35 [ V_15 ] [ 3 ] ;
V_13 -> V_27 . V_28 = V_36 ;
V_13 -> V_27 . V_30 = V_13 -> V_18 . V_31 << 1 ;
}
} else {
V_13 -> V_27 . V_28 = V_37 ;
V_13 -> V_27 . V_30 = V_13 -> V_18 . V_31 / 8 ;
}
V_13 -> V_38 = V_13 -> V_27 . V_30 * V_13 -> V_18 . V_39 ;
V_13 -> V_18 . V_40 = ( ( V_5 -> V_17 -> V_32 & V_41 ) \
>> V_42 ) * 90 ;
V_5 -> V_7 -> V_8 = V_5 -> V_17 -> V_32 ;
V_5 -> V_7 -> V_43 = V_5 -> V_17 -> V_44 ;
V_5 -> V_7 -> V_45 = V_5 -> V_17 -> V_46 ;
V_5 -> V_7 -> V_47 = V_5 -> V_17 -> V_48 ;
V_5 -> V_7 -> V_49 = 0 ;
V_5 -> V_7 -> V_50 = 0 ;
V_5 -> V_7 -> V_51 = F_8 ( V_5 -> V_52 ) ;
if ( F_9 ( V_5 -> V_17 ) ) {
if ( V_13 -> V_18 . V_39 >= ( V_13 -> V_18 . V_53 << 1 ) ) {
V_5 -> V_7 -> V_54 = F_8 ( V_5 -> V_52 +
( V_13 -> V_27 . V_30 *
( V_13 -> V_18 . V_39 >> 1 ) ) ) ;
} else {
V_5 -> V_7 -> V_54 = F_8 ( V_5 -> V_52 ) ;
}
}
V_14 = V_13 -> V_27 . V_30 / sizeof( T_1 ) ;
if ( ! V_13 -> V_18 . V_40 || ( V_13 -> V_18 . V_40 == 180 ) ) {
V_14 *= V_13 -> V_18 . V_39 ;
if ( V_13 -> V_18 . V_40 ) {
V_14 -= ( V_14 % 8 ) ;
}
}
V_5 -> V_7 -> V_55 = F_10 ( V_14 ) ;
V_5 -> V_7 -> V_56 = 0 ;
V_5 -> V_7 -> V_57 = 0 ;
V_5 -> V_7 -> V_8 |= V_9 ;
F_11 ( 10 ) ;
F_1 ( V_6 , V_13 ) ;
return 0 ;
}
int F_12 ( unsigned V_58 , unsigned V_20 , unsigned V_24 , unsigned V_25 , unsigned V_26 , struct V_2 * V_3 )
{
struct V_4 * V_5 ;
T_1 * V_59 ;
T_1 V_60 ;
V_5 = F_2 ( V_3 ) ;
V_59 = V_5 -> V_7 -> V_61 ;
if ( V_58 > ( V_62 - 1 ) )
return - V_16 ;
if ( V_3 -> V_18 . V_63 ) {
V_20 = V_24 = V_25 =
( 19595 * V_20 + 38470 * V_24 + 7471 * V_25 ) >> 16 ;
}
if ( V_3 -> V_27 . V_28 == V_36 ) {
if ( V_58 > 16 )
return - V_16 ;
V_59 = ( T_1 * ) V_3 -> V_64 ;
V_20 >>= ( 16 - V_3 -> V_18 . V_20 . V_22 ) ;
V_24 >>= ( 16 - V_3 -> V_18 . V_24 . V_22 ) ;
V_25 >>= ( 16 - V_3 -> V_18 . V_25 . V_22 ) ;
V_60 = ( V_20 << V_3 -> V_18 . V_20 . V_21 ) |
( V_24 << V_3 -> V_18 . V_24 . V_21 ) |
( V_25 << V_3 -> V_18 . V_25 . V_21 ) ;
V_60 &= 0xFFFF ;
} else if ( F_6 ( V_5 -> V_17 ) ) {
V_60 = ( V_20 & 0xF800 ) | ( ( V_24 >> 5 ) & 0x07E0 ) | ( ( V_25 >> 11 ) & 0x001F ) ;
V_60 &= 0xFFFF ;
} else if ( F_7 ( V_5 -> V_17 ) ) {
V_60 = ( ( ( F_13 ( V_5 -> V_17 ) ? V_25 : V_20 ) >> 12 ) & 0x000F ) |
( ( V_24 >> 8 ) & 0x00F0 ) |
( ( ( F_13 ( V_5 -> V_17 ) ? V_20 : V_25 ) >> 4 ) & 0x0F00 ) ;
V_60 &= 0xFFF ;
} else {
V_60 = ( V_24 >> 12 ) & 0x000F ;
V_60 &= 0xF ;
}
V_59 [ V_58 ] = V_60 ;
return 0 ;
}
int F_14 ( struct V_65 * V_18 , struct V_2 * V_3 )
{
struct V_4 * V_5 ;
int V_66 ;
V_5 = F_2 ( V_3 ) ;
F_3 ( L_2 , V_18 , V_3 ) ;
if ( ! V_18 || ! V_5 ) {
return - V_16 ;
}
if ( V_18 -> V_67 - V_3 -> V_18 . V_67 ) {
return - V_16 ;
}
F_3 ( L_3 , V_18 , V_3 ) ;
V_66 = V_18 -> V_68 - V_3 -> V_18 . V_68 ;
if ( V_66 ) {
T_1 V_69 ;
F_3 ( L_4 , V_66 ) ;
V_69 = V_5 -> V_7 -> V_51 ;
V_69 += ( V_3 -> V_27 . V_30 * V_66 ) ;
V_5 -> V_7 -> V_51 = F_8 ( V_69 ) ;
if ( F_9 ( V_5 -> V_17 ) ) {
V_69 = V_5 -> V_7 -> V_54 ;
V_69 += ( V_3 -> V_27 . V_30 * V_66 ) ;
V_5 -> V_7 -> V_51 = F_8 ( V_69 ) ;
}
}
F_3 ( L_5 , V_18 , V_3 ) ;
return 0 ;
}
void F_15 ( struct V_2 * V_3 , int V_70 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
F_3 ( L_6 , V_3 , V_70 ) ;
if ( V_5 && ( V_70 > 0 ) && ! ( V_70 % 90 ) ) {
V_5 -> V_7 -> V_8 &= ~ V_9 ;
V_5 -> V_7 -> V_8 &= ~ ( V_41 ) ;
V_5 -> V_7 -> V_8 |= ( ( V_70 / 90 ) << V_42 ) ;
V_5 -> V_7 -> V_8 |= V_9 ;
}
}
int F_16 ( struct V_2 * V_3 , struct V_71 * V_72 )
{
struct V_4 * V_5 ;
V_5 = F_2 ( V_3 ) ;
V_72 -> V_73 = F_17 ( V_72 -> V_73 ) ;
F_18 ( V_72 -> V_73 ) |= ( 6 << 9 ) ;
return F_19 ( V_72 , V_5 -> V_52 , V_5 -> V_74 ) ;
}
static int F_20 ( struct V_4 * V_5 )
{
char * V_75 , * V_76 ;
int V_77 = F_21 ( V_78 ) ;
if ( V_77 <= 0 ) {
F_22 ( L_7 ) ;
return - V_79 ;
}
if ( F_23 ( V_80 , & V_76 ) )
return - V_79 ;
if ( ! V_76 )
return - V_79 ;
while ( ( V_75 = F_24 ( & V_76 , L_8 ) ) != NULL ) {
if ( ! strncmp ( V_75 , L_9 , 6 ) ) {
int V_81 ;
V_75 += 6 ;
for ( V_81 = 0 ; V_81 < V_77 ; V_81 ++ ) {
if ( ! strncmp ( V_75 , V_78 [ V_81 ] . V_82 ,
strlen ( V_75 ) ) ) {
V_5 -> V_17 = & V_78 [ V_81 ] ;
V_5 -> V_83 = V_81 ;
break;
}
}
if ( V_81 >= V_77 ) {
F_25 ( L_10 , V_75 ) ;
return - V_79 ;
}
}
else
F_25 ( L_11 , V_75 ) ;
}
F_26 ( L_12 , V_5 -> V_17 -> V_82 ) ;
return 0 ;
}
static int F_27 ( struct V_84 * V_85 )
{
struct V_4 * V_5 = NULL ;
struct V_86 * V_87 ;
unsigned long V_88 ;
T_1 V_89 ;
V_5 = F_28 ( & V_85 -> V_85 , sizeof( struct V_4 ) ,
V_90 ) ;
if ( ! V_5 ) {
F_22 ( L_13 ) ;
return - V_91 ;
}
if ( F_20 ( V_5 ) )
goto V_92;
F_29 ( V_85 , ( void * ) V_5 ) ;
V_87 = F_30 ( V_85 , V_93 , 0 ) ;
if ( ! V_87 ) {
F_22 ( L_14 ) ;
return - V_94 ;
}
V_95 . V_96 = V_87 -> V_97 ;
V_95 . V_98 = F_31 ( V_87 ) ;
if ( ! F_32 ( & V_85 -> V_85 ,
V_95 . V_96 ,
V_95 . V_98 ,
V_80 ) ) {
F_22 ( L_15 ,
V_95 . V_96 ) ;
return - V_99 ;
}
V_5 -> V_7 = (struct V_100 * ) F_33 ( V_95 . V_96 ) ;
F_3 ( L_16 , V_5 -> V_7 ) ;
F_3 ( L_17 , V_5 -> V_101 , V_5 -> V_102 ) ;
V_5 -> V_74 = V_5 -> V_17 -> V_103 * V_5 -> V_17 -> V_53 *
( V_5 -> V_17 -> V_104 >> 3 ) * V_105 ;
V_5 -> V_106 = F_34 ( & V_85 -> V_85 ,
F_35 ( V_5 -> V_74 ) ,
& V_5 -> V_52 , V_90 ) ;
if ( ! V_5 -> V_106 ) {
F_22 ( L_18 ,
V_5 -> V_74 / 1024 ) ;
return - V_91 ;
}
V_95 . V_107 = V_5 -> V_52 ;
V_95 . V_108 = V_5 -> V_74 ;
for ( V_88 = ( unsigned long ) V_5 -> V_106 ;
V_88 < F_35 ( ( unsigned long ) V_5 -> V_106 + V_5 -> V_74 ) ;
V_88 += V_109 ) {
#ifdef F_36
F_37 ( F_38 ( F_39 ( ( void * ) V_88 ) ) ) ;
#else
F_37 ( F_38 ( V_88 ) ) ;
#endif
}
F_3 ( L_19 , V_5 -> V_106 ) ;
F_3 ( L_20 , V_5 -> V_52 , V_5 -> V_74 / 1024 ) ;
V_89 = F_40 ( V_110 ) & ~ ( V_111 | V_112 | V_113 ) ;
F_41 ( ( V_89 | ( 1 << V_114 ) ) , V_110 ) ;
V_115 . V_19 = V_5 -> V_17 -> V_104 ;
V_115 . V_103 = V_5 -> V_17 -> V_103 ;
V_115 . V_31 = V_115 . V_103 ;
V_115 . V_53 = V_5 -> V_17 -> V_53 ;
V_115 . V_39 = V_115 . V_53 ;
V_5 -> V_13 . V_116 = V_5 -> V_106 ;
V_5 -> V_13 . V_117 = & V_118 ;
V_5 -> V_13 . V_27 = V_95 ;
V_5 -> V_13 . V_64 =
F_28 ( & V_85 -> V_85 , sizeof( T_1 ) * 16 , V_90 ) ;
if ( ! V_5 -> V_13 . V_64 )
return - V_91 ;
if ( F_42 ( & V_5 -> V_13 . V_119 , V_62 , 0 ) < 0 ) {
F_22 ( L_21 ,
V_62 ) ;
return - V_94 ;
}
V_5 -> V_13 . V_18 = V_115 ;
F_5 ( V_5 ) ;
if ( F_43 ( & V_5 -> V_13 ) < 0 ) {
F_22 ( L_22 ) ;
goto V_92;
}
return 0 ;
V_92:
if ( V_5 -> V_106 ) {
F_44 ( & V_85 -> V_85 , V_5 -> V_74 , V_5 -> V_106 ,
V_5 -> V_52 ) ;
}
if ( V_5 -> V_13 . V_119 . V_120 != 0 ) {
F_45 ( & V_5 -> V_13 . V_119 ) ;
}
return - V_79 ;
}
int F_46 ( struct V_84 * V_85 )
{
struct V_4 * V_5 = NULL ;
if ( ! V_85 )
return - V_79 ;
V_5 = (struct V_4 * ) F_47 ( V_85 ) ;
#if ! F_48 ( V_121 ) && F_48 ( V_122 )
F_1 ( V_12 , & V_5 -> V_13 ) ;
#endif
V_5 -> V_7 -> V_8 &= ~ V_9 ;
F_49 ( & V_5 -> V_13 ) ;
F_45 ( & V_5 -> V_13 . V_119 ) ;
return 0 ;
}
int F_50 ( struct V_84 * V_85 , T_2 V_123 )
{
struct V_4 * V_5 = F_47 ( V_85 ) ;
if ( ! V_5 )
return 0 ;
V_89 = F_40 ( V_110 ) ;
F_1 ( V_12 , & V_5 -> V_13 ) ;
F_41 ( V_89 & ~ V_111 , V_110 ) ;
memcpy ( & V_124 , V_5 -> V_7 , sizeof( struct V_100 ) ) ;
return 0 ;
}
int F_51 ( struct V_84 * V_85 )
{
struct V_4 * V_5 = F_47 ( V_85 ) ;
if ( ! V_5 )
return 0 ;
memcpy ( V_5 -> V_7 , & V_124 , sizeof( struct V_100 ) ) ;
F_41 ( V_89 , V_110 ) ;
F_1 ( V_6 , & V_5 -> V_13 ) ;
return 0 ;
}
static int T_3 F_52 ( void )
{
return F_53 ( & V_125 ) ;
}
static void T_4 F_54 ( void )
{
F_55 ( & V_125 ) ;
}
