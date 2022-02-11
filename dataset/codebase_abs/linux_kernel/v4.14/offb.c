static int F_1 ( T_1 V_1 , T_1 V_2 , T_1 V_3 , T_1 V_4 ,
T_1 V_5 , struct V_6 * V_7 )
{
struct V_8 * V_9 = (struct V_8 * ) V_7 -> V_9 ;
if ( V_7 -> V_10 . V_11 == V_12 ) {
T_2 * V_13 = V_7 -> V_14 ;
T_2 V_15 = V_2 >> ( 16 - V_7 -> V_16 . V_2 . V_17 ) ;
T_2 V_18 = V_3 >> ( 16 - V_7 -> V_16 . V_3 . V_17 ) ;
T_2 V_19 = V_4 >> ( 16 - V_7 -> V_16 . V_4 . V_17 ) ;
T_2 V_20 ;
if ( V_1 >= 16 )
return - V_21 ;
V_20 = ( V_15 << V_7 -> V_16 . V_2 . V_22 ) |
( V_18 << V_7 -> V_16 . V_3 . V_22 ) |
( V_19 << V_7 -> V_16 . V_4 . V_22 ) ;
if ( V_7 -> V_16 . V_5 . V_17 > 0 ) {
T_2 V_23 = ( 1 << V_7 -> V_16 . V_5 . V_17 ) - 1 ;
V_23 <<= V_7 -> V_16 . V_5 . V_22 ;
V_20 |= V_23 ;
}
V_13 [ V_1 ] = V_20 ;
return 0 ;
}
if ( V_1 > 255 )
return - V_21 ;
V_2 >>= 8 ;
V_3 >>= 8 ;
V_4 >>= 8 ;
if ( ! V_9 -> V_24 )
return 0 ;
switch ( V_9 -> V_25 ) {
case V_26 :
F_2 ( V_1 , V_9 -> V_24 ) ;
F_2 ( V_2 , V_9 -> V_27 ) ;
F_2 ( V_3 , V_9 -> V_27 ) ;
F_2 ( V_4 , V_9 -> V_27 ) ;
break;
case V_28 :
F_3 ( V_9 -> V_24 + 0x58 ,
F_4 ( V_9 -> V_24 + 0x58 ) & ~ 0x20 ) ;
case V_29 :
F_5 ( V_9 -> V_24 + 0xb0 , V_1 ) ;
F_3 ( V_9 -> V_24 + 0xb4 ,
( V_2 << 16 | V_3 << 8 | V_4 ) ) ;
break;
case V_30 :
F_3 ( V_9 -> V_24 + 0x58 ,
F_4 ( V_9 -> V_24 + 0x58 ) | 0x20 ) ;
F_5 ( V_9 -> V_24 + 0xb0 , V_1 ) ;
F_3 ( V_9 -> V_24 + 0xb4 , ( V_2 << 16 | V_3 << 8 | V_4 ) ) ;
break;
case V_31 :
F_5 ( V_9 -> V_24 + 0xb0 , V_1 ) ;
F_3 ( V_9 -> V_24 + 0xb4 , ( V_2 << 16 | V_3 << 8 | V_4 ) ) ;
break;
case V_32 :
F_3 ( ( ( unsigned V_33 * ) V_9 -> V_24 ) + V_1 ,
( V_2 << 16 | V_3 << 8 | V_4 ) ) ;
break;
case V_34 :
F_6 ( 1 , V_9 -> V_24 + V_35 ) ;
F_2 ( V_1 , V_9 -> V_24 + V_36 ) ;
F_6 ( ( ( V_2 ) << 22 ) | ( ( V_3 ) << 12 ) | ( ( V_4 ) << 2 ) ,
V_9 -> V_24 + V_37 ) ;
F_6 ( 0 , V_9 -> V_24 + V_35 ) ;
F_2 ( V_1 , V_9 -> V_24 + V_36 ) ;
F_6 ( ( ( V_2 ) << 22 ) | ( ( V_3 ) << 12 ) | ( ( V_4 ) << 2 ) ,
V_9 -> V_24 + V_37 ) ;
break;
}
return 0 ;
}
static int F_7 ( int V_38 , struct V_6 * V_7 )
{
struct V_8 * V_9 = (struct V_8 * ) V_7 -> V_9 ;
int V_39 , V_40 ;
if ( ! V_9 -> V_24 )
return 0 ;
if ( ! V_9 -> V_41 )
if ( ! V_38 )
return 0 ;
V_9 -> V_41 = V_38 ;
if ( V_38 )
for ( V_39 = 0 ; V_39 < 256 ; V_39 ++ ) {
switch ( V_9 -> V_25 ) {
case V_26 :
F_2 ( V_39 , V_9 -> V_24 ) ;
for ( V_40 = 0 ; V_40 < 3 ; V_40 ++ )
F_2 ( 0 , V_9 -> V_27 ) ;
break;
case V_28 :
F_3 ( V_9 -> V_24 + 0x58 ,
F_4 ( V_9 -> V_24 + 0x58 ) & ~ 0x20 ) ;
case V_29 :
F_5 ( V_9 -> V_24 + 0xb0 , V_39 ) ;
F_3 ( V_9 -> V_24 + 0xb4 , 0 ) ;
break;
case V_30 :
F_3 ( V_9 -> V_24 + 0x58 ,
F_4 ( V_9 -> V_24 + 0x58 ) | 0x20 ) ;
F_5 ( V_9 -> V_24 + 0xb0 , V_39 ) ;
F_3 ( V_9 -> V_24 + 0xb4 , 0 ) ;
break;
case V_31 :
F_5 ( V_9 -> V_24 + 0xb0 , V_39 ) ;
F_3 ( V_9 -> V_24 + 0xb4 , 0 ) ;
break;
case V_32 :
F_3 ( ( ( unsigned V_33 * ) V_9 -> V_24 ) + V_39 ,
0 ) ;
break;
case V_34 :
F_6 ( 1 , V_9 -> V_24 + V_35 ) ;
F_2 ( V_39 , V_9 -> V_24 + V_36 ) ;
F_6 ( 0 , V_9 -> V_24 + V_37 ) ;
F_6 ( 0 , V_9 -> V_24 + V_35 ) ;
F_2 ( V_39 , V_9 -> V_24 + V_36 ) ;
F_6 ( 0 , V_9 -> V_24 + V_37 ) ;
break;
}
} else
F_8 ( & V_7 -> V_42 , V_7 ) ;
return 0 ;
}
static int F_9 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = (struct V_8 * ) V_7 -> V_9 ;
if ( V_9 -> V_25 == V_34 ) {
F_6 ( 0 , V_9 -> V_24 + V_43 ) ;
F_6 ( 0 , V_9 -> V_24 + V_44 ) ;
F_6 ( 0 , V_9 -> V_24 + V_45 ) ;
F_6 ( 0 , V_9 -> V_24 + V_46 ) ;
F_6 ( 0x0000ffff , V_9 -> V_24 + V_47 ) ;
F_6 ( 0x0000ffff , V_9 -> V_24 + V_48 ) ;
F_6 ( 0x0000ffff , V_9 -> V_24 + V_49 ) ;
F_6 ( 0 , V_9 -> V_24 + V_50 ) ;
F_6 ( 0 , V_9 -> V_24 + V_51 ) ;
F_6 ( 0 , V_9 -> V_24 + V_52 ) ;
F_6 ( 0 , V_9 -> V_24 + V_53 ) ;
F_6 ( 0x0000ffff , V_9 -> V_24 + V_54 ) ;
F_6 ( 0x0000ffff , V_9 -> V_24 + V_55 ) ;
F_6 ( 0x0000ffff , V_9 -> V_24 + V_56 ) ;
F_6 ( 1 , V_9 -> V_24 + V_35 ) ;
F_6 ( 0 , V_9 -> V_24 + V_57 ) ;
F_6 ( 0x0000003f , V_9 -> V_24 + V_58 ) ;
F_6 ( 0 , V_9 -> V_24 + V_35 ) ;
F_6 ( 0 , V_9 -> V_24 + V_57 ) ;
F_6 ( 0x0000003f , V_9 -> V_24 + V_58 ) ;
}
return 0 ;
}
static void F_10 ( struct V_6 * V_7 )
{
if ( V_7 -> V_59 )
F_11 ( V_7 -> V_59 ) ;
F_12 ( V_7 -> V_60 -> V_61 [ 0 ] . V_62 , V_7 -> V_60 -> V_61 [ 0 ] . V_63 ) ;
F_13 ( V_7 ) ;
}
static void V_33 * F_14 ( struct V_64 * V_65 , int V_66 ,
unsigned long V_22 , unsigned long V_63 )
{
const T_3 * V_67 ;
T_4 V_68 , V_69 ;
unsigned int V_70 ;
V_67 = F_15 ( V_65 , V_66 , & V_68 , & V_70 ) ;
if ( V_67 == NULL )
V_67 = F_16 ( V_65 , V_66 , & V_68 , & V_70 ) ;
if ( V_67 == NULL )
return NULL ;
if ( ( V_70 & ( V_71 | V_72 ) ) == 0 )
return NULL ;
if ( ( V_22 + V_63 ) > V_68 )
return NULL ;
V_69 = F_17 ( V_65 , V_67 ) ;
if ( V_69 == V_73 )
return NULL ;
return F_18 ( V_69 + V_22 , V_63 ) ;
}
static void F_19 ( struct V_6 * V_7 , struct V_64 * V_74 ,
const char * V_75 , unsigned long V_76 )
{
struct V_8 * V_9 = (struct V_8 * ) V_7 -> V_9 ;
if ( V_74 && ! strncmp ( V_75 , L_1 , 11 ) ) {
V_9 -> V_24 = F_14 ( V_74 , 2 , 0 , 0x1fff ) ;
if ( V_9 -> V_24 )
V_9 -> V_25 = V_29 ;
} else if ( V_74 && ( ! strncmp ( V_75 , L_2 , 12 )
|| ! strncmp ( V_75 , L_3 , 14 ) ) ) {
V_9 -> V_24 = F_14 ( V_74 , 2 , 0 , 0x1fff ) ;
if ( V_9 -> V_24 )
V_9 -> V_25 = V_28 ;
} else if ( V_74 && ! strncmp ( V_75 , L_4 , 12 ) ) {
V_9 -> V_24 = F_14 ( V_74 , 2 , 0 , 0x1fff ) ;
if ( V_9 -> V_24 )
V_9 -> V_25 = V_30 ;
} else if ( V_74 && ! strncmp ( V_75 , L_5 , 9 ) ) {
V_9 -> V_24 = F_14 ( V_74 , 1 , 0 , 0x1fff ) ;
if ( V_9 -> V_24 )
V_9 -> V_25 = V_31 ;
} else if ( ! strncmp ( V_75 , L_6 , 4 ) ) {
unsigned long V_62 = V_76 & 0xff000000UL ;
V_9 -> V_24 =
F_18 ( V_62 + 0x7ff000 , 0x1000 ) + 0xcc0 ;
V_9 -> V_27 = V_9 -> V_24 + 1 ;
V_9 -> V_25 = V_26 ;
} else if ( V_74 && ( F_20 ( V_74 , L_7 ) ||
F_20 ( V_74 , L_8 ) ) ) {
V_9 -> V_24 = F_14 ( V_74 , 0 , 0x6000 , 0x1000 ) ;
if ( V_9 -> V_24 )
V_9 -> V_25 = V_32 ;
} else if ( V_74 && ! strncmp ( V_75 , L_9 , 12 ) ) {
struct V_64 * V_77 = F_21 ( V_74 ) ;
const T_2 * V_78 , * V_79 ;
V_78 = F_22 ( V_77 , L_10 , NULL ) ;
V_79 = F_22 ( V_77 , L_11 , NULL ) ;
if ( V_78 && V_79 && * V_78 == 0x1002 &&
( ( * V_79 >= 0x7100 && * V_79 < 0x7800 ) ||
( * V_79 >= 0x9400 ) ) ) {
V_9 -> V_24 = F_14 ( V_77 , 2 , 0 , 0x10000 ) ;
if ( V_9 -> V_24 )
V_9 -> V_25 = V_34 ;
}
F_23 ( V_77 ) ;
} else if ( V_74 && F_20 ( V_74 , L_12 ) ) {
#ifdef F_24
const T_3 V_80 [ 3 ] = { 0x01000000 , 0x0 , 0x0 } ;
#else
const T_3 V_80 [ 3 ] = { 0x00000001 , 0x0 , 0x0 } ;
#endif
T_4 V_81 = F_17 ( V_74 , V_80 ) ;
if ( V_81 != V_73 ) {
V_9 -> V_24 = F_18 ( V_81 + 0x3c8 , 2 ) ;
if ( V_9 -> V_24 ) {
V_9 -> V_25 = V_26 ;
V_9 -> V_27 = V_9 -> V_24 + 1 ;
}
}
}
V_7 -> V_10 . V_11 = ( V_9 -> V_25 != V_82 ) ?
V_83 : V_84 ;
}
static void T_5 F_25 ( const char * V_75 ,
int V_85 , int V_86 , int V_87 ,
int V_88 , unsigned long V_76 ,
int V_89 , struct V_64 * V_74 )
{
unsigned long V_90 = V_88 * V_86 ;
struct V_8 * V_9 = & V_91 ;
unsigned long V_92 = V_76 ;
struct V_93 * V_10 ;
struct V_94 * V_16 ;
struct V_6 * V_7 ;
if ( ! F_26 ( V_92 , V_90 , L_13 ) )
return;
F_27 ( V_95
L_14 ,
V_85 , V_86 , V_75 , V_76 , V_87 , V_88 ) ;
if ( V_87 != 8 && V_87 != 15 && V_87 != 16 && V_87 != 32 ) {
F_27 ( V_96 L_15 , V_74 , V_87 ) ;
F_12 ( V_92 , V_90 ) ;
return;
}
V_7 = F_28 ( sizeof( T_2 ) * 16 , NULL ) ;
if ( V_7 == 0 ) {
F_12 ( V_92 , V_90 ) ;
return;
}
V_10 = & V_7 -> V_10 ;
V_16 = & V_7 -> V_16 ;
V_7 -> V_9 = V_9 ;
strcpy ( V_10 -> V_97 , L_16 ) ;
strncat ( V_10 -> V_97 , V_75 , sizeof( V_10 -> V_97 ) - sizeof( L_16 ) ) ;
V_10 -> V_97 [ sizeof( V_10 -> V_97 ) - 1 ] = '\0' ;
V_16 -> V_98 = V_16 -> V_99 = V_85 ;
V_16 -> V_100 = V_16 -> V_101 = V_86 ;
V_10 -> V_102 = V_88 ;
V_10 -> V_103 = V_76 ;
V_10 -> V_104 = V_88 * V_86 ;
V_10 -> type = V_105 ;
V_10 -> V_106 = 0 ;
V_9 -> V_25 = V_82 ;
if ( V_87 == 8 )
F_19 ( V_7 , V_74 , V_75 , V_76 ) ;
else
V_10 -> V_11 = V_12 ;
V_16 -> V_107 = V_16 -> V_108 = 0 ;
switch ( V_87 ) {
case 8 :
V_16 -> V_109 = 8 ;
V_16 -> V_2 . V_22 = 0 ;
V_16 -> V_2 . V_17 = 8 ;
V_16 -> V_3 . V_22 = 0 ;
V_16 -> V_3 . V_17 = 8 ;
V_16 -> V_4 . V_22 = 0 ;
V_16 -> V_4 . V_17 = 8 ;
V_16 -> V_5 . V_22 = 0 ;
V_16 -> V_5 . V_17 = 0 ;
break;
case 15 :
V_16 -> V_109 = 16 ;
V_16 -> V_2 . V_22 = 10 ;
V_16 -> V_2 . V_17 = 5 ;
V_16 -> V_3 . V_22 = 5 ;
V_16 -> V_3 . V_17 = 5 ;
V_16 -> V_4 . V_22 = 0 ;
V_16 -> V_4 . V_17 = 5 ;
V_16 -> V_5 . V_22 = 0 ;
V_16 -> V_5 . V_17 = 0 ;
break;
case 16 :
V_16 -> V_109 = 16 ;
V_16 -> V_2 . V_22 = 11 ;
V_16 -> V_2 . V_17 = 5 ;
V_16 -> V_3 . V_22 = 5 ;
V_16 -> V_3 . V_17 = 6 ;
V_16 -> V_4 . V_22 = 0 ;
V_16 -> V_4 . V_17 = 5 ;
V_16 -> V_5 . V_22 = 0 ;
V_16 -> V_5 . V_17 = 0 ;
break;
case 32 :
V_16 -> V_109 = 32 ;
V_16 -> V_2 . V_22 = 16 ;
V_16 -> V_2 . V_17 = 8 ;
V_16 -> V_3 . V_22 = 8 ;
V_16 -> V_3 . V_17 = 8 ;
V_16 -> V_4 . V_22 = 0 ;
V_16 -> V_4 . V_17 = 8 ;
V_16 -> V_5 . V_22 = 24 ;
V_16 -> V_5 . V_17 = 8 ;
break;
}
V_16 -> V_2 . V_110 = V_16 -> V_3 . V_110 = V_16 -> V_4 . V_110 =
V_16 -> V_5 . V_110 = 0 ;
V_16 -> V_111 = 0 ;
V_16 -> V_112 = 0 ;
V_16 -> V_113 = 0 ;
V_16 -> V_86 = V_16 -> V_85 = - 1 ;
V_16 -> V_114 = 10000 ;
V_16 -> V_115 = V_16 -> V_116 = 16 ;
V_16 -> V_117 = V_16 -> V_118 = 16 ;
V_16 -> V_119 = V_16 -> V_120 = 8 ;
V_16 -> V_121 = 0 ;
V_16 -> V_122 = V_123 ;
V_7 -> V_60 = F_29 ( 1 ) ;
if ( ! V_7 -> V_60 )
goto V_124;
V_7 -> V_60 -> V_61 [ 0 ] . V_62 = V_76 ;
V_7 -> V_60 -> V_61 [ 0 ] . V_63 = V_10 -> V_104 ;
V_7 -> V_125 = & V_126 ;
V_7 -> V_59 = F_18 ( V_76 , V_10 -> V_104 ) ;
V_7 -> V_14 = ( void * ) ( V_7 + 1 ) ;
V_7 -> V_70 = V_127 | V_128 | V_89 ;
F_30 ( & V_7 -> V_42 , 256 , 0 ) ;
if ( F_31 ( V_7 ) < 0 )
goto V_129;
V_6 ( V_7 , L_17 , V_74 ) ;
return;
V_129:
F_11 ( V_7 -> V_59 ) ;
V_124:
F_11 ( V_9 -> V_24 ) ;
V_9 -> V_24 = NULL ;
F_13 ( V_7 ) ;
F_12 ( V_92 , V_90 ) ;
}
static void T_5 F_32 ( struct V_64 * V_74 , int V_130 )
{
unsigned int V_131 ;
int V_39 , V_85 = 640 , V_86 = 480 , V_87 = 8 , V_88 = 640 ;
unsigned int V_70 , V_132 , V_133 = 0 ;
unsigned long V_134 = 0 ;
T_4 V_135 , V_76 = V_73 ;
const T_3 * V_136 , * V_67 , * V_137 ;
T_4 V_68 ;
int V_89 = 0 ;
#ifdef F_24
if ( F_22 ( V_74 , L_18 , NULL ) )
V_89 = V_138 ;
#else
if ( F_22 ( V_74 , L_19 , NULL ) )
V_89 = V_138 ;
#endif
V_136 = F_22 ( V_74 , L_20 , & V_131 ) ;
if ( V_136 == NULL )
V_136 = F_22 ( V_74 , L_21 , & V_131 ) ;
if ( V_136 && V_131 == sizeof( T_2 ) )
V_87 = F_33 ( V_136 ) ;
V_136 = F_22 ( V_74 , L_22 , & V_131 ) ;
if ( V_136 == NULL )
V_136 = F_22 ( V_74 , L_23 , & V_131 ) ;
if ( V_136 && V_131 == sizeof( T_2 ) )
V_85 = F_33 ( V_136 ) ;
V_136 = F_22 ( V_74 , L_24 , & V_131 ) ;
if ( V_136 == NULL )
V_136 = F_22 ( V_74 , L_25 , & V_131 ) ;
if ( V_136 && V_131 == sizeof( T_2 ) )
V_86 = F_33 ( V_136 ) ;
V_136 = F_22 ( V_74 , L_26 , & V_131 ) ;
if ( V_136 == NULL )
V_136 = F_22 ( V_74 , L_27 , & V_131 ) ;
if ( V_136 && V_131 == sizeof( T_2 ) && ( * V_136 != 0xffffffffu ) )
V_88 = F_33 ( V_136 ) ;
else
V_88 = V_85 * ( ( V_87 + 7 ) / 8 ) ;
V_132 = ( unsigned long ) V_88 * ( unsigned long ) V_86 ;
V_137 = F_22 ( V_74 , L_28 , & V_131 ) ;
if ( V_137 == NULL )
V_137 = F_22 ( V_74 , L_29 , & V_131 ) ;
if ( V_137 && V_131 == sizeof( T_2 ) )
V_133 = * V_137 ;
if ( V_130 )
goto V_139;
for ( V_39 = 0 ; ( V_67 = F_16 ( V_74 , V_39 , & V_68 , & V_70 ) )
!= NULL ; V_39 ++ ) {
int V_140 = 0 ;
if ( ! ( V_70 & V_72 ) )
continue;
if ( V_68 < V_132 )
continue;
V_135 = F_17 ( V_74 , V_67 ) ;
if ( V_135 == V_73 )
continue;
if ( V_133 && ( V_135 <= V_133 ) &&
( ( V_135 + V_68 ) >= ( V_133 + V_132 ) ) )
V_140 = 1 ;
if ( V_140 ) {
V_76 = V_133 ;
break;
}
if ( V_132 > V_134 ) {
V_134 = V_132 ;
V_76 = V_73 ;
}
if ( V_76 == V_73 )
V_76 = V_135 ;
}
V_139:
if ( V_76 == V_73 && V_133 )
V_76 = ( T_4 ) V_133 ;
if ( V_76 != V_73 ) {
#ifdef F_34
const T_3 * V_141 , * V_142 ;
T_2 V_78 , V_79 ;
struct V_143 * V_144 ;
V_141 = F_22 ( V_74 , L_10 , NULL ) ;
V_142 = F_22 ( V_74 , L_11 , NULL ) ;
if ( V_141 && V_142 ) {
V_78 = F_33 ( V_141 ) ;
V_79 = F_33 ( V_142 ) ;
V_144 = F_35 ( V_78 , V_79 , NULL ) ;
if ( ! V_144 || F_36 ( V_144 ) )
return;
}
#endif
if ( strcmp ( V_74 -> V_75 , L_30 ) == 0 )
V_76 += 0x1000 ;
F_25 ( V_130 ? L_31 : V_74 -> V_75 ,
V_85 , V_86 , V_87 , V_88 , V_76 ,
V_89 , V_130 ? NULL : V_74 ) ;
}
}
static int T_5 F_37 ( void )
{
struct V_64 * V_74 = NULL , * V_145 = NULL ;
if ( F_38 ( L_13 , NULL ) )
return - V_146 ;
if ( F_22 ( V_147 , L_32 , NULL ) != NULL ) {
F_32 ( V_147 , 1 ) ;
}
F_39 (dp, L_33 ) {
if ( F_22 ( V_74 , L_34 , NULL ) &&
F_22 ( V_74 , L_35 , NULL ) ) {
V_145 = V_74 ;
F_32 ( V_74 , 0 ) ;
}
}
F_39 (dp, L_33 ) {
if ( F_22 ( V_74 , L_34 , NULL ) &&
V_74 != V_145 )
F_32 ( V_74 , 0 ) ;
}
return 0 ;
}
