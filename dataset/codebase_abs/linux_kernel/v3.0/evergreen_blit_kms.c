static void
F_1 ( struct V_1 * V_2 , int V_3 ,
int V_4 , int V_5 , T_1 V_6 )
{
T_2 V_7 ;
int V_8 , V_9 ;
V_5 = F_2 ( V_5 , 8 ) ;
if ( V_5 < 8 )
V_5 = 8 ;
V_7 = ( ( V_3 << 2 ) | ( 1 << 24 ) | ( 1 << 8 ) ) ;
V_8 = ( V_4 / 8 ) - 1 ;
V_9 = ( ( V_4 * V_5 ) / 64 ) - 1 ;
F_3 ( V_2 , F_4 ( V_10 , 15 ) ) ;
F_3 ( V_2 , ( V_11 - V_12 ) >> 2 ) ;
F_3 ( V_2 , V_6 >> 8 ) ;
F_3 ( V_2 , V_8 ) ;
F_3 ( V_2 , V_9 ) ;
F_3 ( V_2 , 0 ) ;
F_3 ( V_2 , V_7 ) ;
F_3 ( V_2 , ( 1 << 4 ) ) ;
F_3 ( V_2 , ( V_4 - 1 ) | ( ( V_5 - 1 ) << 16 ) ) ;
F_3 ( V_2 , 0 ) ;
F_3 ( V_2 , 0 ) ;
F_3 ( V_2 , 0 ) ;
F_3 ( V_2 , 0 ) ;
F_3 ( V_2 , 0 ) ;
F_3 ( V_2 , 0 ) ;
F_3 ( V_2 , 0 ) ;
F_3 ( V_2 , 0 ) ;
}
static void
F_5 ( struct V_1 * V_2 ,
T_2 V_13 , T_2 V_14 ,
T_1 V_15 )
{
T_2 V_16 ;
if ( V_14 == 0xffffffff )
V_16 = 0xffffffff ;
else
V_16 = ( ( V_14 + 255 ) >> 8 ) ;
F_3 ( V_2 , F_4 ( V_17 , 3 ) ) ;
F_3 ( V_2 , V_13 ) ;
F_3 ( V_2 , V_16 ) ;
F_3 ( V_2 , V_15 >> 8 ) ;
F_3 ( V_2 , 10 ) ;
}
static void
F_6 ( struct V_1 * V_2 )
{
T_1 V_6 ;
V_6 = V_2 -> V_18 . V_19 + V_2 -> V_18 . V_20 ;
F_3 ( V_2 , F_4 ( V_10 , 3 ) ) ;
F_3 ( V_2 , ( V_21 - V_12 ) >> 2 ) ;
F_3 ( V_2 , V_6 >> 8 ) ;
F_3 ( V_2 , 2 ) ;
F_3 ( V_2 , 0 ) ;
V_6 = V_2 -> V_18 . V_19 + V_2 -> V_18 . V_22 ;
F_3 ( V_2 , F_4 ( V_10 , 4 ) ) ;
F_3 ( V_2 , ( V_23 - V_12 ) >> 2 ) ;
F_3 ( V_2 , V_6 >> 8 ) ;
F_3 ( V_2 , 1 ) ;
F_3 ( V_2 , 0 ) ;
F_3 ( V_2 , 2 ) ;
V_6 = V_2 -> V_18 . V_19 + V_2 -> V_18 . V_20 ;
F_5 ( V_2 , V_24 , 512 , V_6 ) ;
}
static void
F_7 ( struct V_1 * V_2 , T_1 V_6 )
{
T_2 V_25 , V_26 ;
V_25 = ( ( F_8 ( V_6 ) & 0xff ) | ( 16 << 8 ) ) ;
#ifdef F_9
V_25 |= ( 2 << 30 ) ;
#endif
V_26 = ( 0 << 3 ) | ( 1 << 6 ) | ( 2 << 9 ) | ( 3 << 12 ) ;
F_3 ( V_2 , F_4 ( V_27 , 8 ) ) ;
F_3 ( V_2 , 0x580 ) ;
F_3 ( V_2 , V_6 & 0xffffffff ) ;
F_3 ( V_2 , 48 - 1 ) ;
F_3 ( V_2 , V_25 ) ;
F_3 ( V_2 , V_26 ) ;
F_3 ( V_2 , 0 ) ;
F_3 ( V_2 , 0 ) ;
F_3 ( V_2 , 0 ) ;
F_3 ( V_2 , V_28 << 30 ) ;
if ( ( V_2 -> V_29 == V_30 ) ||
( V_2 -> V_29 == V_31 ) ||
( V_2 -> V_29 == V_32 ) ||
( V_2 -> V_29 == V_33 ) ||
( V_2 -> V_29 == V_34 ) )
F_5 ( V_2 ,
V_35 , 48 , V_6 ) ;
else
F_5 ( V_2 ,
V_36 , 48 , V_6 ) ;
}
static void
F_10 ( struct V_1 * V_2 ,
int V_3 , int V_4 , int V_5 , int V_8 ,
T_1 V_6 )
{
T_2 V_37 , V_38 ;
T_2 V_39 , V_40 ;
if ( V_5 < 1 )
V_5 = 1 ;
V_37 = ( 1 << 0 ) ;
V_37 |= ( ( ( ( V_8 >> 3 ) - 1 ) << 6 ) |
( ( V_4 - 1 ) << 18 ) ) ;
V_38 = ( ( V_5 - 1 ) << 0 ) | ( 1 << 28 ) ;
V_39 = ( 0 << 16 ) | ( 1 << 19 ) | ( 2 << 22 ) | ( 3 << 25 ) ;
V_40 = V_3 | ( V_41 << 30 ) ;
F_3 ( V_2 , F_4 ( V_27 , 8 ) ) ;
F_3 ( V_2 , 0 ) ;
F_3 ( V_2 , V_37 ) ;
F_3 ( V_2 , V_38 ) ;
F_3 ( V_2 , V_6 >> 8 ) ;
F_3 ( V_2 , V_6 >> 8 ) ;
F_3 ( V_2 , V_39 ) ;
F_3 ( V_2 , 0 ) ;
F_3 ( V_2 , 0 ) ;
F_3 ( V_2 , V_40 ) ;
}
static void
F_11 ( struct V_1 * V_2 , int V_42 , int y1 ,
int V_43 , int V_44 )
{
if ( V_43 == 0 )
V_42 = 1 ;
if ( V_44 == 0 )
y1 = 1 ;
if ( V_2 -> V_29 == V_45 ) {
if ( ( V_43 == 1 ) && ( V_44 == 1 ) )
V_43 = 2 ;
}
F_3 ( V_2 , F_4 ( V_10 , 2 ) ) ;
F_3 ( V_2 , ( V_46 - V_12 ) >> 2 ) ;
F_3 ( V_2 , ( V_42 << 0 ) | ( y1 << 16 ) ) ;
F_3 ( V_2 , ( V_43 << 0 ) | ( V_44 << 16 ) ) ;
F_3 ( V_2 , F_4 ( V_10 , 2 ) ) ;
F_3 ( V_2 , ( V_47 - V_12 ) >> 2 ) ;
F_3 ( V_2 , ( V_42 << 0 ) | ( y1 << 16 ) | ( 1 << 31 ) ) ;
F_3 ( V_2 , ( V_43 << 0 ) | ( V_44 << 16 ) ) ;
F_3 ( V_2 , F_4 ( V_10 , 2 ) ) ;
F_3 ( V_2 , ( V_48 - V_12 ) >> 2 ) ;
F_3 ( V_2 , ( V_42 << 0 ) | ( y1 << 16 ) | ( 1 << 31 ) ) ;
F_3 ( V_2 , ( V_43 << 0 ) | ( V_44 << 16 ) ) ;
}
static void
F_12 ( struct V_1 * V_2 )
{
F_3 ( V_2 , F_4 ( V_49 , 1 ) ) ;
F_3 ( V_2 , ( V_50 - V_51 ) >> 2 ) ;
F_3 ( V_2 , V_52 ) ;
F_3 ( V_2 , F_4 ( V_53 , 0 ) ) ;
F_3 ( V_2 ,
#ifdef F_9
( 2 << 2 ) |
#endif
V_54 ) ;
F_3 ( V_2 , F_4 ( V_55 , 0 ) ) ;
F_3 ( V_2 , 1 ) ;
F_3 ( V_2 , F_4 ( V_56 , 1 ) ) ;
F_3 ( V_2 , 3 ) ;
F_3 ( V_2 , V_57 ) ;
}
static void
F_13 ( struct V_1 * V_2 )
{
T_2 V_58 , V_59 , V_60 , V_61 ;
T_2 V_62 , V_63 ;
T_2 V_64 , V_65 , V_66 ;
int V_67 , V_68 , V_69 ;
int V_70 , V_71 , V_72 , V_73 ;
int V_74 , V_75 , V_76 , V_77 ;
int V_78 , V_79 ;
int V_80 , V_81 , V_82 , V_83 ;
int V_84 , V_85 ;
T_1 V_6 ;
int V_86 ;
F_3 ( V_2 , F_4 ( V_87 , 0 ) ) ;
F_3 ( V_2 , 0 ) ;
if ( V_2 -> V_29 < V_45 ) {
switch ( V_2 -> V_29 ) {
case V_30 :
default:
V_67 = 93 ;
V_68 = 46 ;
V_69 = 4 ;
V_70 = 31 ;
V_71 = 31 ;
V_72 = 23 ;
V_73 = 23 ;
V_74 = 96 ;
V_75 = 16 ;
V_76 = 16 ;
V_77 = 16 ;
V_78 = 16 ;
V_79 = 16 ;
V_80 = 42 ;
V_81 = 42 ;
V_82 = 42 ;
V_83 = 42 ;
V_84 = 42 ;
V_85 = 42 ;
break;
case V_88 :
V_67 = 93 ;
V_68 = 46 ;
V_69 = 4 ;
V_70 = 31 ;
V_71 = 31 ;
V_72 = 23 ;
V_73 = 23 ;
V_74 = 128 ;
V_75 = 20 ;
V_76 = 20 ;
V_77 = 20 ;
V_78 = 20 ;
V_79 = 20 ;
V_80 = 42 ;
V_81 = 42 ;
V_82 = 42 ;
V_83 = 42 ;
V_84 = 42 ;
V_85 = 42 ;
break;
case V_89 :
V_67 = 93 ;
V_68 = 46 ;
V_69 = 4 ;
V_70 = 31 ;
V_71 = 31 ;
V_72 = 23 ;
V_73 = 23 ;
V_74 = 128 ;
V_75 = 20 ;
V_76 = 20 ;
V_77 = 20 ;
V_78 = 20 ;
V_79 = 20 ;
V_80 = 85 ;
V_81 = 85 ;
V_82 = 85 ;
V_83 = 85 ;
V_84 = 85 ;
V_85 = 85 ;
break;
case V_90 :
case V_91 :
V_67 = 93 ;
V_68 = 46 ;
V_69 = 4 ;
V_70 = 31 ;
V_71 = 31 ;
V_72 = 23 ;
V_73 = 23 ;
V_74 = 128 ;
V_75 = 20 ;
V_76 = 20 ;
V_77 = 20 ;
V_78 = 20 ;
V_79 = 20 ;
V_80 = 85 ;
V_81 = 85 ;
V_82 = 85 ;
V_83 = 85 ;
V_84 = 85 ;
V_85 = 85 ;
break;
case V_31 :
V_67 = 93 ;
V_68 = 46 ;
V_69 = 4 ;
V_70 = 31 ;
V_71 = 31 ;
V_72 = 23 ;
V_73 = 23 ;
V_74 = 96 ;
V_75 = 16 ;
V_76 = 16 ;
V_77 = 16 ;
V_78 = 16 ;
V_79 = 16 ;
V_80 = 42 ;
V_81 = 42 ;
V_82 = 42 ;
V_83 = 42 ;
V_84 = 42 ;
V_85 = 42 ;
break;
case V_32 :
V_67 = 93 ;
V_68 = 46 ;
V_69 = 4 ;
V_70 = 31 ;
V_71 = 31 ;
V_72 = 23 ;
V_73 = 23 ;
V_74 = 96 ;
V_75 = 25 ;
V_76 = 25 ;
V_77 = 25 ;
V_78 = 25 ;
V_79 = 25 ;
V_80 = 42 ;
V_81 = 42 ;
V_82 = 42 ;
V_83 = 42 ;
V_84 = 42 ;
V_85 = 42 ;
break;
case V_33 :
V_67 = 93 ;
V_68 = 46 ;
V_69 = 4 ;
V_70 = 31 ;
V_71 = 31 ;
V_72 = 23 ;
V_73 = 23 ;
V_74 = 96 ;
V_75 = 25 ;
V_76 = 25 ;
V_77 = 25 ;
V_78 = 25 ;
V_79 = 25 ;
V_80 = 85 ;
V_81 = 85 ;
V_82 = 85 ;
V_83 = 85 ;
V_84 = 85 ;
V_85 = 85 ;
break;
case V_92 :
V_67 = 93 ;
V_68 = 46 ;
V_69 = 4 ;
V_70 = 31 ;
V_71 = 31 ;
V_72 = 23 ;
V_73 = 23 ;
V_74 = 128 ;
V_75 = 20 ;
V_76 = 20 ;
V_77 = 20 ;
V_78 = 20 ;
V_79 = 20 ;
V_80 = 85 ;
V_81 = 85 ;
V_82 = 85 ;
V_83 = 85 ;
V_84 = 85 ;
V_85 = 85 ;
break;
case V_93 :
V_67 = 93 ;
V_68 = 46 ;
V_69 = 4 ;
V_70 = 31 ;
V_71 = 31 ;
V_72 = 23 ;
V_73 = 23 ;
V_74 = 128 ;
V_75 = 20 ;
V_76 = 20 ;
V_77 = 20 ;
V_78 = 20 ;
V_79 = 20 ;
V_80 = 42 ;
V_81 = 42 ;
V_82 = 42 ;
V_83 = 42 ;
V_84 = 42 ;
V_85 = 42 ;
break;
case V_34 :
V_67 = 93 ;
V_68 = 46 ;
V_69 = 4 ;
V_70 = 31 ;
V_71 = 31 ;
V_72 = 23 ;
V_73 = 23 ;
V_74 = 128 ;
V_75 = 10 ;
V_76 = 10 ;
V_77 = 10 ;
V_78 = 10 ;
V_79 = 10 ;
V_80 = 42 ;
V_81 = 42 ;
V_82 = 42 ;
V_83 = 42 ;
V_84 = 42 ;
V_85 = 42 ;
break;
}
if ( ( V_2 -> V_29 == V_30 ) ||
( V_2 -> V_29 == V_31 ) ||
( V_2 -> V_29 == V_32 ) ||
( V_2 -> V_29 == V_33 ) ||
( V_2 -> V_29 == V_34 ) )
V_58 = 0 ;
else
V_58 = V_94 ;
V_58 |= ( V_95 |
F_14 ( 0 ) |
F_15 ( 0 ) |
F_16 ( 0 ) |
F_17 ( 0 ) |
F_18 ( 1 ) |
F_19 ( 2 ) |
F_20 ( 3 ) ) ;
V_59 = ( F_21 ( V_67 ) |
F_22 ( V_68 ) |
F_23 ( V_69 ) ) ;
V_60 = ( F_24 ( V_70 ) |
F_25 ( V_71 ) ) ;
V_61 = ( F_26 ( V_72 ) |
F_27 ( V_73 ) ) ;
V_62 = ( F_28 ( V_74 ) |
F_29 ( V_75 ) |
F_30 ( V_76 ) |
F_31 ( V_77 ) ) ;
V_63 = ( F_32 ( V_78 ) |
F_33 ( V_79 ) ) ;
V_64 = ( F_34 ( V_80 ) |
F_35 ( V_81 ) ) ;
V_65 = ( F_36 ( V_82 ) |
F_37 ( V_83 ) ) ;
V_66 = ( F_38 ( V_84 ) |
F_39 ( V_85 ) ) ;
F_3 ( V_2 , F_4 ( V_49 , 1 ) ) ;
F_3 ( V_2 , ( V_96 - V_51 ) >> 2 ) ;
F_3 ( V_2 , 0 ) ;
F_3 ( V_2 , F_4 ( V_49 , 1 ) ) ;
F_3 ( V_2 , ( V_97 - V_51 ) >> 2 ) ;
F_3 ( V_2 , 0x10001000 ) ;
F_3 ( V_2 , F_4 ( V_49 , 11 ) ) ;
F_3 ( V_2 , ( V_98 - V_51 ) >> 2 ) ;
F_3 ( V_2 , V_58 ) ;
F_3 ( V_2 , V_59 ) ;
F_3 ( V_2 , V_60 ) ;
F_3 ( V_2 , V_61 ) ;
F_3 ( V_2 , 0 ) ;
F_3 ( V_2 , 0 ) ;
F_3 ( V_2 , V_62 ) ;
F_3 ( V_2 , V_63 ) ;
F_3 ( V_2 , V_64 ) ;
F_3 ( V_2 , V_65 ) ;
F_3 ( V_2 , V_66 ) ;
}
F_3 ( V_2 , 0xc0012800 ) ;
F_3 ( V_2 , 0x80000000 ) ;
F_3 ( V_2 , 0x80000000 ) ;
F_3 ( V_2 , 0xc0026f00 ) ;
F_3 ( V_2 , 0x00000000 ) ;
F_3 ( V_2 , 0x00000000 ) ;
F_3 ( V_2 , 0x00000000 ) ;
F_3 ( V_2 , 0xc0036e00 ) ;
F_3 ( V_2 , 0x00000000 ) ;
F_3 ( V_2 , 0x00000012 ) ;
F_3 ( V_2 , 0x00000000 ) ;
F_3 ( V_2 , 0x00000000 ) ;
F_3 ( V_2 , F_4 ( V_99 , 0 ) ) ;
F_3 ( V_2 , 1 ) ;
V_86 = F_2 ( V_2 -> V_18 . V_100 , 0x10 ) ;
V_6 = V_2 -> V_18 . V_19 + V_2 -> V_18 . V_101 ;
F_3 ( V_2 , F_4 ( V_102 , 2 ) ) ;
F_3 ( V_2 , V_6 & 0xFFFFFFFC ) ;
F_3 ( V_2 , F_8 ( V_6 ) & 0xFF ) ;
F_3 ( V_2 , V_86 ) ;
}
static inline T_3 F_40 ( T_3 V_103 )
{
T_2 V_104 , V_105 , V_106 , V_107 ;
if ( ( V_103 & 0x3fff ) == 0 )
V_104 = 0 ;
else {
V_106 = 140 ;
V_107 = ( V_103 & 0x3fff ) << 10 ;
for ( V_105 = 0 ; V_105 < 14 ; V_105 ++ ) {
if ( V_107 & 0x800000 )
break;
else {
V_107 = V_107 << 1 ;
V_106 = V_106 - 1 ;
}
}
V_104 = V_106 << 23 | ( V_107 & 0x7fffff ) ;
}
return V_104 ;
}
int F_41 ( struct V_1 * V_2 )
{
T_2 V_108 ;
int V_105 , V_109 , V_86 ;
void * V_110 ;
T_2 V_111 [ 16 ] ;
int V_112 = 0 ;
if ( V_2 -> V_18 . V_113 )
goto V_114;
F_42 ( & V_2 -> V_18 . V_115 ) ;
V_2 -> V_18 . V_101 = 0 ;
if ( V_2 -> V_29 < V_45 )
V_2 -> V_18 . V_100 = V_116 ;
else
V_2 -> V_18 . V_100 = V_117 ;
V_86 = V_2 -> V_18 . V_100 ;
while ( V_86 & 0xf ) {
V_111 [ V_112 ++ ] = F_43 ( F_44 ( 0 ) ) ;
V_86 ++ ;
}
V_108 = V_86 * 4 ;
V_108 = F_2 ( V_108 , 256 ) ;
V_2 -> V_18 . V_20 = V_108 ;
if ( V_2 -> V_29 < V_45 )
V_108 += V_118 * 4 ;
else
V_108 += V_119 * 4 ;
V_108 = F_2 ( V_108 , 256 ) ;
V_2 -> V_18 . V_22 = V_108 ;
if ( V_2 -> V_29 < V_45 )
V_108 += V_120 * 4 ;
else
V_108 += V_121 * 4 ;
V_108 = F_2 ( V_108 , 256 ) ;
V_109 = F_45 ( V_2 , V_108 , V_122 , true , V_123 ,
& V_2 -> V_18 . V_113 ) ;
if ( V_109 ) {
F_46 ( L_1 ) ;
return V_109 ;
}
F_47 ( L_2 ,
V_108 ,
V_2 -> V_18 . V_20 , V_2 -> V_18 . V_22 ) ;
V_109 = F_48 ( V_2 -> V_18 . V_113 , false ) ;
if ( F_49 ( V_109 != 0 ) )
return V_109 ;
V_109 = F_50 ( V_2 -> V_18 . V_113 , & V_110 ) ;
if ( V_109 ) {
F_46 ( L_3 , V_109 ) ;
return V_109 ;
}
if ( V_2 -> V_29 < V_45 ) {
F_51 ( V_110 + V_2 -> V_18 . V_101 ,
V_124 , V_2 -> V_18 . V_100 * 4 ) ;
if ( V_112 )
F_51 ( V_110 + V_2 -> V_18 . V_101 + ( V_2 -> V_18 . V_100 * 4 ) ,
V_111 , V_112 * 4 ) ;
for ( V_105 = 0 ; V_105 < V_118 ; V_105 ++ )
* ( T_2 * ) ( ( unsigned long ) V_110 + V_2 -> V_18 . V_20 + V_105 * 4 ) = F_43 ( V_125 [ V_105 ] ) ;
for ( V_105 = 0 ; V_105 < V_120 ; V_105 ++ )
* ( T_2 * ) ( ( unsigned long ) V_110 + V_2 -> V_18 . V_22 + V_105 * 4 ) = F_43 ( V_126 [ V_105 ] ) ;
} else {
F_51 ( V_110 + V_2 -> V_18 . V_101 ,
V_127 , V_2 -> V_18 . V_100 * 4 ) ;
if ( V_112 )
F_51 ( V_110 + V_2 -> V_18 . V_101 + ( V_2 -> V_18 . V_100 * 4 ) ,
V_111 , V_112 * 4 ) ;
for ( V_105 = 0 ; V_105 < V_119 ; V_105 ++ )
* ( T_2 * ) ( ( unsigned long ) V_110 + V_2 -> V_18 . V_20 + V_105 * 4 ) = F_43 ( V_128 [ V_105 ] ) ;
for ( V_105 = 0 ; V_105 < V_121 ; V_105 ++ )
* ( T_2 * ) ( ( unsigned long ) V_110 + V_2 -> V_18 . V_22 + V_105 * 4 ) = F_43 ( V_129 [ V_105 ] ) ;
}
F_52 ( V_2 -> V_18 . V_113 ) ;
F_53 ( V_2 -> V_18 . V_113 ) ;
V_114:
V_109 = F_48 ( V_2 -> V_18 . V_113 , false ) ;
if ( F_49 ( V_109 != 0 ) )
return V_109 ;
V_109 = F_54 ( V_2 -> V_18 . V_113 , V_123 ,
& V_2 -> V_18 . V_19 ) ;
F_53 ( V_2 -> V_18 . V_113 ) ;
if ( V_109 ) {
F_55 ( V_2 -> V_130 , L_4 , V_109 ) ;
return V_109 ;
}
F_56 ( V_2 , V_2 -> V_131 . V_132 ) ;
return 0 ;
}
void F_57 ( struct V_1 * V_2 )
{
int V_109 ;
F_56 ( V_2 , V_2 -> V_131 . V_133 ) ;
if ( V_2 -> V_18 . V_113 == NULL )
return;
V_109 = F_48 ( V_2 -> V_18 . V_113 , false ) ;
if ( ! V_109 ) {
F_58 ( V_2 -> V_18 . V_113 ) ;
F_53 ( V_2 -> V_18 . V_113 ) ;
}
F_59 ( & V_2 -> V_18 . V_113 ) ;
}
static int F_60 ( struct V_1 * V_2 )
{
int V_109 ;
V_109 = F_61 ( V_2 , & V_2 -> V_18 . V_134 ) ;
if ( V_109 ) {
F_46 ( L_5 ) ;
return V_109 ;
}
V_2 -> V_18 . V_135 = 64 * 1024 ;
V_2 -> V_18 . V_136 = 0 ;
return 0 ;
}
static void F_62 ( struct V_1 * V_2 )
{
F_63 ( V_2 , V_2 -> V_18 . V_134 -> V_137 ) ;
F_64 ( V_2 , & V_2 -> V_18 . V_134 ) ;
}
int F_65 ( struct V_1 * V_2 , int V_138 )
{
int V_109 ;
int V_139 , V_140 ;
int V_141 ;
int V_142 = 74 , V_143 ;
V_109 = F_60 ( V_2 ) ;
if ( V_109 )
return V_109 ;
if ( V_138 & 3 )
V_140 = 8192 ;
else
V_140 = 8192 * 4 ;
V_141 = 8192 * V_140 ;
V_143 = ( ( V_138 + V_141 ) / V_141 ) ;
V_143 += ( ( V_138 % V_140 ) ? 1 : 0 ) ;
V_139 = V_143 * V_142 ;
V_139 += 55 ;
V_139 += 10 ;
V_139 += 5 ;
V_139 += 10 ;
V_109 = F_66 ( V_2 , V_139 ) ;
if ( V_109 )
return V_109 ;
F_13 ( V_2 ) ;
F_6 ( V_2 ) ;
return 0 ;
}
void F_67 ( struct V_1 * V_2 , struct V_144 * V_137 )
{
int V_109 ;
if ( V_2 -> V_18 . V_134 )
F_62 ( V_2 ) ;
if ( V_137 )
V_109 = F_63 ( V_2 , V_137 ) ;
F_68 ( V_2 ) ;
}
void F_69 ( struct V_1 * V_2 ,
T_1 V_145 , T_1 V_146 ,
int V_138 )
{
int V_147 ;
T_1 V_148 ;
T_2 * V_149 ;
F_47 ( L_6 , V_145 , V_146 ,
V_138 , V_2 -> V_18 . V_136 ) ;
V_149 = ( T_2 * ) ( V_2 -> V_18 . V_134 -> V_110 + V_2 -> V_18 . V_136 ) ;
if ( ( V_138 & 3 ) || ( V_145 & 3 ) || ( V_146 & 3 ) ) {
V_147 = 8192 ;
while ( V_138 ) {
int V_150 = V_138 ;
int V_151 = V_145 & 255 ;
int V_152 = V_146 & 255 ;
int V_5 = 1 ;
V_145 = V_145 & ~ 255ULL ;
V_146 = V_146 & ~ 255ULL ;
if ( ! V_151 && ! V_152 ) {
V_5 = ( V_150 / V_147 ) ;
if ( V_5 > 8192 )
V_5 = 8192 ;
if ( V_5 == 0 )
V_5 = 1 ;
else
V_150 = V_147 ;
} else {
if ( V_150 > V_147 )
V_150 = V_147 ;
if ( V_150 > ( V_147 - V_152 ) )
V_150 = ( V_147 - V_152 ) ;
if ( V_150 > ( V_147 - V_151 ) )
V_150 = ( V_147 - V_151 ) ;
}
if ( ( V_2 -> V_18 . V_136 + 48 ) > V_2 -> V_18 . V_135 ) {
F_70 ( 1 ) ;
}
V_149 [ 0 ] = F_40 ( V_152 ) ;
V_149 [ 1 ] = 0 ;
V_149 [ 2 ] = F_40 ( V_151 ) ;
V_149 [ 3 ] = 0 ;
V_149 [ 4 ] = F_40 ( V_152 ) ;
V_149 [ 5 ] = F_40 ( V_5 ) ;
V_149 [ 6 ] = F_40 ( V_151 ) ;
V_149 [ 7 ] = F_40 ( V_5 ) ;
V_149 [ 8 ] = F_40 ( V_152 + V_150 ) ;
V_149 [ 9 ] = F_40 ( V_5 ) ;
V_149 [ 10 ] = F_40 ( V_151 + V_150 ) ;
V_149 [ 11 ] = F_40 ( V_5 ) ;
F_10 ( V_2 , V_153 ,
V_151 + V_150 , V_5 , V_151 + V_150 ,
V_145 ) ;
F_5 ( V_2 ,
V_35 , ( V_151 + V_150 * V_5 ) , V_145 ) ;
F_1 ( V_2 , V_154 ,
V_152 + V_150 , V_5 ,
V_146 ) ;
F_11 ( V_2 , V_152 , 0 , V_152 + V_150 , V_5 ) ;
V_148 = V_2 -> V_18 . V_134 -> V_6 + V_2 -> V_18 . V_136 ;
F_7 ( V_2 , V_148 ) ;
F_12 ( V_2 ) ;
F_5 ( V_2 ,
V_155 | V_156 ,
V_150 * V_5 , V_146 ) ;
V_149 += 12 ;
V_2 -> V_18 . V_136 += 12 * 4 ;
V_145 += V_150 * V_5 ;
V_146 += V_150 * V_5 ;
V_138 -= V_150 * V_5 ;
}
} else {
V_147 = 8192 * 4 ;
while ( V_138 ) {
int V_150 = V_138 ;
int V_151 = ( V_145 & 255 ) ;
int V_152 = ( V_146 & 255 ) ;
int V_5 = 1 ;
V_145 = V_145 & ~ 255ULL ;
V_146 = V_146 & ~ 255ULL ;
if ( ! V_151 && ! V_152 ) {
V_5 = ( V_150 / V_147 ) ;
if ( V_5 > 8192 )
V_5 = 8192 ;
if ( V_5 == 0 )
V_5 = 1 ;
else
V_150 = V_147 ;
} else {
if ( V_150 > V_147 )
V_150 = V_147 ;
if ( V_150 > ( V_147 - V_152 ) )
V_150 = ( V_147 - V_152 ) ;
if ( V_150 > ( V_147 - V_151 ) )
V_150 = ( V_147 - V_151 ) ;
}
if ( ( V_2 -> V_18 . V_136 + 48 ) > V_2 -> V_18 . V_135 ) {
F_70 ( 1 ) ;
}
V_149 [ 0 ] = F_40 ( V_152 / 4 ) ;
V_149 [ 1 ] = 0 ;
V_149 [ 2 ] = F_40 ( V_151 / 4 ) ;
V_149 [ 3 ] = 0 ;
V_149 [ 4 ] = F_40 ( V_152 / 4 ) ;
V_149 [ 5 ] = F_40 ( V_5 ) ;
V_149 [ 6 ] = F_40 ( V_151 / 4 ) ;
V_149 [ 7 ] = F_40 ( V_5 ) ;
V_149 [ 8 ] = F_40 ( ( V_152 + V_150 ) / 4 ) ;
V_149 [ 9 ] = F_40 ( V_5 ) ;
V_149 [ 10 ] = F_40 ( ( V_151 + V_150 ) / 4 ) ;
V_149 [ 11 ] = F_40 ( V_5 ) ;
F_10 ( V_2 , V_157 ,
( V_151 + V_150 ) / 4 ,
V_5 , ( V_151 + V_150 ) / 4 ,
V_145 ) ;
F_5 ( V_2 ,
V_35 , ( V_151 + V_150 * V_5 ) , V_145 ) ;
F_1 ( V_2 , V_158 ,
( V_152 + V_150 ) / 4 , V_5 ,
V_146 ) ;
F_11 ( V_2 , ( V_152 / 4 ) , 0 , ( V_152 + V_150 / 4 ) , V_5 ) ;
V_148 = V_2 -> V_18 . V_134 -> V_6 + V_2 -> V_18 . V_136 ;
F_7 ( V_2 , V_148 ) ;
F_12 ( V_2 ) ;
F_5 ( V_2 ,
V_155 | V_156 ,
V_150 * V_5 , V_146 ) ;
V_149 += 12 ;
V_2 -> V_18 . V_136 += 12 * 4 ;
V_145 += V_150 * V_5 ;
V_146 += V_150 * V_5 ;
V_138 -= V_150 * V_5 ;
}
}
}
