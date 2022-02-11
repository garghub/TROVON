static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 )
{
unsigned char V_5 [ 2 ] ;
unsigned char V_6 [ 2 ] ;
F_2 ( L_1 , V_7 , V_3 ) ;
V_5 [ 0 ] = V_3 >> 8 ;
V_5 [ 1 ] = ( unsigned char ) V_3 ;
if ( F_3 ( V_2 , V_5 , 2 , V_6 , 2 ) != 2 )
return - V_8 ;
* V_4 = ( V_6 [ 1 ] ) | ( V_6 [ 0 ] << 8 ) ;
return 0 ;
}
static void F_4 ( unsigned int type , T_1 V_9 )
{
if ( type & V_10 )
F_5 ( L_2 ) ;
if ( type & V_11 )
F_5 ( L_3 ) ;
if ( type & V_12 )
F_5 ( L_4 ) ;
if ( type & V_13 )
F_5 ( L_5 ) ;
if ( type & V_14 )
F_5 ( L_6 ) ;
if ( type & V_15 )
F_5 ( L_7 ) ;
if ( type & V_16 )
F_5 ( L_8 ) ;
if ( type & V_17 )
F_5 ( L_9 ) ;
if ( type & V_18 )
F_5 ( L_10 ) ;
if ( type & V_19 )
F_5 ( L_11 ) ;
if ( type & V_20 )
F_5 ( L_12 ) ;
if ( type & V_21 )
F_5 ( L_13 ) ;
if ( type & V_22 )
F_5 ( L_14 ) ;
if ( type & V_23 )
F_5 ( L_15 ) ;
if ( type & V_24 )
F_5 ( L_16 ) ;
if ( type & V_25 )
F_5 ( L_17 ) ;
if ( type & V_26 )
F_5 ( L_18 ) ;
if ( type & IF )
F_5 ( L_19 ) ;
if ( type & V_27 )
F_5 ( L_20 ) ;
if ( type & V_28 )
F_5 ( L_21 ) ;
if ( type & V_29 )
F_5 ( L_22 ) ;
if ( type & V_30 )
F_5 ( L_23 ) ;
if ( type & V_31 )
F_5 ( L_24 ) ;
if ( type & V_32 )
F_5 ( L_25 ) ;
if ( type & V_33 )
F_5 ( L_26 ) ;
if ( type & V_34 )
F_5 ( L_27 ) ;
if ( type & V_35 )
F_5 ( L_28 ) ;
if ( type & V_36 )
F_5 ( L_29 ) ;
if ( type & V_37 )
F_5 ( L_30 ) ;
if ( type & V_38 )
F_5 ( L_31 ) ;
if ( type & V_39 )
F_5 ( L_32 , V_9 ) ;
}
static T_2 F_6 ( void )
{
if ( strcasecmp ( V_40 , L_33 ) == 0 )
return V_41 ;
if ( strcasecmp ( V_40 , L_34 ) == 0 )
return V_42 ;
if ( strcasecmp ( V_40 , L_35 ) == 0 )
return V_43 ;
if ( strcasecmp ( V_40 , L_36 ) == 0 )
return V_44 ;
if ( strcasecmp ( V_40 , L_37 ) == 0 )
return V_45 ;
if ( strcasecmp ( V_40 , L_38 ) == 0 )
return V_46 ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_47 ) {
case V_48 :
case V_49 :
return - V_50 ;
case V_51 :
return 1 ;
case V_52 :
return 0 ;
case V_53 :
return - V_54 ;
}
return 0 ;
}
static void F_8 ( struct V_1 * V_2 )
{
int V_55 ;
F_2 ( L_39 , V_7 ) ;
if ( V_2 -> V_56 != V_57 )
F_9 ( V_2 -> V_56 ) ;
V_2 -> V_56 = NULL ;
V_2 -> V_47 = V_48 ;
memset ( & V_2 -> V_58 , 0 , sizeof( V_2 -> V_58 ) ) ;
if ( ! V_2 -> V_59 )
return;
for ( V_55 = 0 ; V_55 < V_2 -> V_60 ; V_55 ++ )
F_9 ( V_2 -> V_59 [ V_55 ] . V_61 ) ;
F_9 ( V_2 -> V_59 ) ;
V_2 -> V_59 = NULL ;
V_2 -> V_60 = 0 ;
}
static int F_10 ( struct V_62 * V_63 ,
const struct V_64 * V_65 )
{
struct V_1 * V_2 = V_63 -> V_66 ;
const unsigned char * V_67 , * V_68 ;
int V_69 = 0 ;
int V_70 , V_71 ;
char V_72 [ 33 ] ;
F_2 ( L_39 , V_7 ) ;
V_67 = V_65 -> V_73 ;
V_68 = V_67 + V_65 -> V_74 ;
if ( V_65 -> V_74 < sizeof( V_72 ) - 1 + 2 + 2 ) {
F_11 ( L_40 ,
V_2 -> V_56 ) ;
goto V_75;
}
memcpy ( V_72 , V_67 , sizeof( V_72 ) - 1 ) ;
V_72 [ sizeof( V_72 ) - 1 ] = 0 ;
V_67 += sizeof( V_72 ) - 1 ;
V_2 -> V_76 = F_12 ( V_67 ) ;
V_67 += 2 ;
V_71 = F_12 ( V_67 ) ;
V_67 += 2 ;
F_13 ( L_41 ,
V_71 , V_2 -> V_56 , V_72 ,
V_2 -> V_76 >> 8 , V_2 -> V_76 & 0xff ) ;
V_2 -> V_59 = F_14 ( V_71 , sizeof( * V_2 -> V_59 ) , V_77 ) ;
if ( V_2 -> V_59 == NULL ) {
F_11 ( L_42 ) ;
V_69 = - V_78 ;
goto V_79;
}
V_2 -> V_60 = V_71 ;
V_70 = - 1 ;
while ( V_67 < V_68 ) {
T_3 type , V_74 ;
T_2 V_80 ;
T_4 V_9 = 0 ;
V_70 ++ ;
if ( V_70 >= V_71 ) {
F_11 ( L_43
L_44 ) ;
goto V_75;
}
if ( V_68 - V_67 < sizeof( type ) + sizeof( V_80 ) + sizeof( V_74 ) )
goto V_81;
type = F_15 ( V_67 ) ;
V_67 += sizeof( type ) ;
V_80 = F_16 ( V_67 ) ;
V_67 += sizeof( V_80 ) ;
if ( type & V_39 ) {
V_9 = F_12 ( V_67 ) ;
V_67 += sizeof( V_9 ) ;
if ( V_68 - V_67 < sizeof( V_74 ) )
goto V_81;
}
V_74 = F_15 ( V_67 ) ;
V_67 += sizeof( V_74 ) ;
if ( ! V_74 || V_74 > V_68 - V_67 ) {
F_11 ( L_45 ) ;
F_17 ( type ) ;
F_5 ( L_46
L_47 ,
type , ( unsigned long long ) V_80 ,
( unsigned ) ( V_68 - V_67 ) , V_74 ) ;
goto V_75;
}
V_2 -> V_59 [ V_70 ] . V_61 = F_18 ( V_74 , V_77 ) ;
if ( V_2 -> V_59 [ V_70 ] . V_61 == NULL ) {
F_11 ( L_42 ) ;
V_69 = - V_78 ;
goto V_79;
}
F_2 ( L_48 ) ;
if ( V_82 ) {
F_4 ( type , V_9 ) ;
F_5 ( L_49 ,
type , ( unsigned long long ) V_80 , V_74 ) ;
}
memcpy ( V_2 -> V_59 [ V_70 ] . V_61 , V_67 , V_74 ) ;
V_2 -> V_59 [ V_70 ] . type = type ;
V_2 -> V_59 [ V_70 ] . V_80 = V_80 ;
V_2 -> V_59 [ V_70 ] . V_74 = V_74 ;
V_2 -> V_59 [ V_70 ] . V_9 = V_9 ;
V_67 += V_74 ;
}
if ( V_70 + 1 != V_2 -> V_60 ) {
F_11 ( L_50 ) ;
goto V_75;
}
goto V_83;
V_81:
F_11 ( L_51 ) ;
V_75:
V_69 = - V_84 ;
F_11 ( L_52 ) ;
V_79:
F_13 ( L_53 ) ;
F_8 ( V_2 ) ;
V_83:
if ( V_69 == 0 )
F_2 ( L_54 ) ;
else
V_2 -> V_47 = V_53 ;
return V_69 ;
}
static int F_19 ( struct V_62 * V_63 , unsigned int type ,
T_2 * V_80 )
{
struct V_1 * V_2 = V_63 -> V_66 ;
int V_55 , V_85 = - 1 , V_86 = 0 ;
unsigned int V_87 = 0 ;
F_2 ( L_55 , V_7 ) ;
if ( V_82 ) {
F_17 ( type ) ;
F_5 ( L_56 , type , ( unsigned long long ) * V_80 ) ;
}
if ( ! V_2 -> V_59 ) {
F_11 ( L_57 ) ;
return - V_84 ;
}
if ( ( ( type & ~ V_38 ) == 0 ) && ( * V_80 == 0 ) )
* V_80 = V_88 ;
if ( type & V_10 )
V_87 = V_89 ;
else if ( type & V_38 ) {
type &= V_90 ;
V_87 = V_90 & ~ V_39 ;
} else if ( type & V_91 )
V_87 = V_91 ;
else if ( type & V_92 )
V_87 = V_92 ;
type &= V_87 ;
if ( ! ( type & V_38 ) )
V_87 = ~ 0 ;
for ( V_55 = 0 ; V_55 < V_2 -> V_60 ; V_55 ++ ) {
if ( ( type == ( V_2 -> V_59 [ V_55 ] . type & V_87 ) ) &&
( * V_80 == V_2 -> V_59 [ V_55 ] . V_80 ) )
goto V_93;
}
for ( V_55 = 0 ; V_55 < V_2 -> V_60 ; V_55 ++ ) {
T_2 V_94 ;
int V_95 ;
if ( type != ( V_2 -> V_59 [ V_55 ] . type & V_87 ) )
continue;
V_94 = * V_80 & V_2 -> V_59 [ V_55 ] . V_80 ;
if ( ! V_94 )
continue;
if ( ( * V_80 & V_94 ) == * V_80 )
goto V_93;
V_95 = F_20 ( V_94 ) ;
if ( V_95 > V_86 ) {
V_86 = V_95 ;
V_85 = V_55 ;
}
}
if ( V_86 > 0 ) {
F_2 ( L_58
L_59 , V_86 ) ;
F_17 ( type ) ;
F_5 ( L_60 , type , ( unsigned long long ) * V_80 ) ;
V_55 = V_85 ;
goto V_93;
}
V_55 = - V_96 ;
goto V_97;
V_93:
* V_80 = V_2 -> V_59 [ V_55 ] . V_80 ;
V_97:
F_2 ( L_61 , ( V_55 < 0 ) ? L_62 : L_63 ) ;
if ( V_82 ) {
F_17 ( type ) ;
F_5 ( L_56 , type , ( unsigned long long ) * V_80 ) ;
}
return V_55 ;
}
static inline int F_21 ( struct V_62 * V_63 , int V_98 , int V_99 )
{
struct V_1 * V_2 = V_63 -> V_66 ;
return ( ! V_63 -> V_100 ) ? - V_84 :
V_63 -> V_100 ( ( ( V_63 -> V_101 ) && ( V_63 -> V_101 -> V_2 ) ) ?
V_63 -> V_101 -> V_2 : V_2 -> V_102 . V_103 -> V_104 ,
V_105 , V_98 , V_99 ) ;
}
static int F_22 ( struct V_62 * V_63 , unsigned int type ,
T_2 * V_80 )
{
struct V_1 * V_2 = V_63 -> V_66 ;
int V_106 , V_69 ;
unsigned char * V_67 , * V_68 , V_5 [ V_107 ] ;
if ( V_2 -> V_108 . V_109 > sizeof( V_5 ) )
V_2 -> V_108 . V_109 = sizeof( V_5 ) ;
F_2 ( L_39 , V_7 ) ;
V_106 = F_19 ( V_63 , type , V_80 ) ;
if ( V_106 < 0 )
return V_106 ;
F_13 ( L_64 ) ;
F_17 ( V_2 -> V_59 [ V_106 ] . type ) ;
F_5 ( L_56 , V_2 -> V_59 [ V_106 ] . type ,
( unsigned long long ) * V_80 ) ;
V_67 = V_2 -> V_59 [ V_106 ] . V_61 ;
V_68 = V_67 + V_2 -> V_59 [ V_106 ] . V_74 ;
while ( V_67 < V_68 ) {
T_4 V_74 ;
if ( V_67 + sizeof( V_74 ) > V_68 ) {
F_11 ( L_65 ) ;
return - V_84 ;
}
V_74 = F_23 ( * ( V_110 * ) V_67 ) ;
V_67 += sizeof( V_74 ) ;
if ( V_74 == 0xffff )
return 0 ;
if ( ! V_74 ) {
V_69 = F_21 ( V_63 , V_111 , 0 ) ;
if ( V_69 < 0 ) {
F_11 ( L_66 ,
( * V_67 ) & 0x7f ) ;
return - V_84 ;
}
continue;
}
if ( V_74 >= 0xff00 ) {
switch ( V_74 ) {
case 0xff00 :
V_69 = F_21 ( V_63 , V_112 , 0 ) ;
if ( V_69 < 0 ) {
F_11 ( L_66 ,
( * V_67 ) & 0x7f ) ;
return - V_84 ;
}
break;
default:
F_13 ( L_67 ,
V_74 & 0x7f ) ;
return - V_84 ;
}
continue;
}
if ( V_74 & 0x8000 ) {
F_24 ( V_74 & 0x7fff ) ;
continue;
}
if ( ( V_74 + V_67 > V_68 ) ) {
F_11 ( L_68 ,
V_74 , ( int ) ( V_68 - V_67 ) ) ;
return - V_84 ;
}
V_5 [ 0 ] = * V_67 ;
V_67 ++ ;
V_74 -- ;
while ( V_74 > 0 ) {
int V_113 = ( V_74 < V_2 -> V_108 . V_109 - 1 ) ?
V_74 : V_2 -> V_108 . V_109 - 1 ;
memcpy ( V_5 + 1 , V_67 , V_113 ) ;
V_69 = F_25 ( V_2 , V_5 , V_113 + 1 ) ;
if ( V_69 < 0 ) {
F_11 ( L_69 , V_69 ) ;
return - V_84 ;
}
V_67 += V_113 ;
V_74 -= V_113 ;
}
V_69 = F_21 ( V_63 , V_114 , 0 ) ;
if ( ( V_69 < 0 ) && ( V_69 != - V_84 ) ) {
F_11 ( L_70 , V_69 ) ;
return V_69 ;
}
}
return 0 ;
}
static int F_26 ( struct V_62 * V_63 , unsigned int type ,
T_2 * V_80 , T_4 V_9 , int V_115 )
{
struct V_1 * V_2 = V_63 -> V_66 ;
int V_106 , V_69 ;
unsigned char * V_67 ;
F_2 ( L_39 , V_7 ) ;
if ( ! V_9 ) {
V_106 = F_19 ( V_63 , type , V_80 ) ;
if ( V_106 < 0 )
return V_106 ;
} else {
for ( V_106 = 0 ; V_106 < V_2 -> V_60 ; V_106 ++ ) {
if ( ( V_2 -> V_59 [ V_106 ] . V_9 == V_9 ) &&
( V_2 -> V_59 [ V_106 ] . type & V_39 ) )
break;
}
if ( V_106 == V_2 -> V_60 )
return - V_96 ;
}
V_67 = V_2 -> V_59 [ V_106 ] . V_61 ;
if ( V_2 -> V_59 [ V_106 ] . type & V_39 ) {
if ( V_2 -> V_59 [ V_106 ] . V_74 != 12 * 16 || V_115 >= 16 )
return - V_84 ;
V_67 += 12 * V_115 ;
} else {
if ( V_2 -> V_59 [ V_106 ] . V_74 != 14 * 16 || V_115 >= 16 ||
F_23 ( * ( V_110 * ) ( V_67 + 14 * V_115 ) ) != 12 )
return - V_84 ;
V_67 += 14 * V_115 + 2 ;
}
F_13 ( L_71 ) ;
F_4 ( V_2 -> V_59 [ V_106 ] . type ,
V_2 -> V_59 [ V_106 ] . V_9 ) ;
F_5 ( L_56 , V_2 -> V_59 [ V_106 ] . type ,
( unsigned long long ) * V_80 ) ;
if ( V_2 -> V_76 < 0x0202 )
V_69 = F_27 (priv, {0x20 , 0x00 , 0x00 , 0x00}) ;
else
V_69 = F_27 (priv, {0xa0 , 0x00 , 0x00 , 0x00}) ;
if ( V_69 < 0 )
return - V_8 ;
V_69 = F_25 ( V_2 , V_67 , 12 ) ;
if ( V_69 < 0 )
return - V_8 ;
V_69 = F_27 (priv, {0x00 , 0x8c}) ;
if ( V_69 < 0 )
return - V_8 ;
return 0 ;
}
static int F_28 ( struct V_62 * V_63 , unsigned int type ,
T_2 V_116 , T_4 V_9 )
{
struct V_1 * V_2 = V_63 -> V_66 ;
struct V_117 V_118 ;
int V_69 , V_119 = 0 ;
T_1 V_120 , V_121 ;
T_2 V_122 ;
F_2 ( L_39 , V_7 ) ;
V_69 = F_7 ( V_2 ) ;
if ( V_69 < 0 )
return V_69 ;
if ( V_2 -> V_108 . V_123 && ! ( type & V_21 ) )
type |= V_13 ;
V_124:
V_118 . type = type ;
V_118 . V_80 = V_116 ;
V_118 . V_125 = V_116 ;
V_118 . V_126 = V_38 | V_2 -> V_108 . V_126 ;
V_118 . V_127 = 0 ;
V_118 . V_9 = V_9 ;
F_2 ( L_72 ) ;
if ( V_82 ) {
F_17 ( V_118 . type ) ;
F_5 ( L_73 , V_118 . type ,
( unsigned long long ) V_118 . V_125 ) ;
if ( ! V_9 ) {
F_5 ( L_74 ) ;
F_17 ( V_2 -> V_108 . V_126 ) ;
F_5 ( L_75 , V_2 -> V_108 . V_126 ) ;
} else
F_5 ( L_76 , V_118 . V_9 ) ;
F_5 ( L_77 , V_118 . V_127 ) ;
}
if ( ( V_2 -> V_47 == V_51 ) &&
( ( ( V_10 | V_118 . type ) & V_89 ) ==
( V_2 -> V_58 . type & V_89 ) ) ) {
F_2 ( L_78 ) ;
goto V_128;
}
memset ( & V_2 -> V_58 , 0 , sizeof( V_2 -> V_58 ) ) ;
V_69 = F_21 ( V_63 , V_111 , 0 ) ;
if ( V_69 < 0 )
goto V_129;
V_122 = 0 ;
V_69 = F_22 ( V_63 , V_10 | V_118 . type , & V_122 ) ;
if ( V_69 < 0 ) {
F_11 ( L_79 ,
V_69 ) ;
goto V_129;
}
F_2 ( L_80 ) ;
V_69 = F_22 ( V_63 , V_10 | V_11 | V_118 . type , & V_122 ) ;
if ( V_69 == - V_96 )
V_69 = F_22 ( V_63 , ( V_10 | V_11 | V_118 . type ) & ~ V_12 ,
& V_122 ) ;
if ( V_69 < 0 && V_69 != - V_96 ) {
F_11 ( L_81 ,
V_69 ) ;
goto V_129;
}
V_128:
if ( V_2 -> V_58 . type == ( V_10 | V_118 . type ) &&
V_2 -> V_58 . V_125 == V_116 ) {
F_2 ( L_82 ) ;
goto V_130;
}
V_2 -> V_58 . V_126 = 0 ;
V_69 = F_22 ( V_63 , V_118 . type , & V_118 . V_80 ) ;
if ( V_69 == - V_96 )
V_69 = F_22 ( V_63 , V_118 . type & ~ V_12 , & V_118 . V_80 ) ;
if ( V_69 < 0 )
goto V_129;
V_130:
if ( V_2 -> V_58 . V_126 == V_118 . V_126 &&
V_2 -> V_58 . V_127 == V_118 . V_127 ) {
F_2 ( L_83 ) ;
goto V_131;
}
if ( V_118 . type & V_21 )
goto V_131;
F_2 ( L_84 , V_118 . V_127 ) ;
V_69 = F_26 ( V_63 , V_118 . type | V_118 . V_126 , & V_118 . V_80 ,
V_118 . V_9 , V_118 . V_127 ) ;
V_131:
if ( F_1 ( V_2 , 0x0004 , & V_120 ) < 0 ||
F_1 ( V_2 , 0x0008 , & V_121 ) < 0 ) {
F_11 ( L_85 ) ;
goto V_129;
}
F_2 ( L_86
L_87 ,
V_121 , ( V_120 & 0xf000 ) >> 12 , ( V_120 & 0xf00 ) >> 8 ,
( V_120 & 0xf0 ) >> 4 , V_120 & 0xf ) ;
if ( V_2 -> V_108 . V_132 )
goto V_132;
if ( V_2 -> V_76 != ( ( V_120 & 0xf0 ) << 4 | ( V_120 & 0x0f ) ) ) {
if ( ! V_2 -> V_108 . V_132 ) {
F_11 ( L_88 ) ;
goto V_129;
} else {
F_11 ( L_89
L_90 ) ;
V_121 = 3028 ;
}
}
if ( V_2 -> V_121 == 0 && ( V_121 == 2028 || V_121 == 3028 ) ) {
V_2 -> V_121 = V_121 ;
V_2 -> V_133 = V_120 & 0xff00 ;
} else if ( V_2 -> V_121 == 0 || V_2 -> V_121 != V_121 ||
V_2 -> V_133 != ( V_120 & 0xff00 ) ) {
F_11 ( L_91
L_92 ) ;
goto V_129;
}
V_132:
V_2 -> V_58 = V_118 ;
V_2 -> V_58 . type |= V_10 ;
V_2 -> V_47 = V_51 ;
return 0 ;
V_129:
F_8 ( V_2 ) ;
if ( V_119 < 8 ) {
F_24 ( 50 ) ;
V_119 ++ ;
F_2 ( L_93 ) ;
goto V_124;
}
F_29 ( V_63 ) ;
if ( V_69 == - V_96 )
V_69 = - V_84 ;
return V_69 ;
}
static int F_30 ( struct V_62 * V_63 , T_1 * V_134 )
{
struct V_1 * V_2 = V_63 -> V_66 ;
T_1 V_135 , signal = 0 ;
int V_69 , V_55 ;
F_2 ( L_39 , V_7 ) ;
V_69 = F_7 ( V_2 ) ;
if ( V_69 < 0 )
return V_69 ;
if ( ! V_69 ) {
* V_134 = 0 ;
return 0 ;
}
F_31 ( & V_2 -> V_136 ) ;
for ( V_55 = 0 ; V_55 < 3 ; V_55 ++ ) {
V_69 = F_1 ( V_2 , V_137 , & V_135 ) ;
if ( V_69 < 0 )
goto V_97;
if ( V_135 )
break;
F_24 ( 6 ) ;
}
if ( V_135 == 2 )
goto V_97;
V_69 = F_1 ( V_2 , V_138 , & signal ) ;
if ( V_69 < 0 )
goto V_97;
signal = ( ( 1 << 12 ) - 1 ) | ( ( signal & 0x07 ) << 12 ) ;
V_97:
F_32 ( & V_2 -> V_136 ) ;
* V_134 = signal ;
F_2 ( L_94 , signal ) ;
return V_69 ;
}
static int F_33 ( struct V_62 * V_63 , T_5 * V_139 )
{
struct V_1 * V_2 = V_63 -> V_66 ;
int V_55 , V_69 ;
T_1 V_135 = 0 ;
T_6 V_140 = 0 ;
V_69 = F_7 ( V_2 ) ;
if ( V_69 < 0 )
return V_69 ;
if ( ! V_69 ) {
* V_139 = 0 ;
return 0 ;
}
F_31 ( & V_2 -> V_136 ) ;
for ( V_55 = 0 ; V_55 < 3 ; V_55 ++ ) {
V_69 = F_1 ( V_2 , V_137 , & V_135 ) ;
if ( V_69 < 0 )
goto V_97;
if ( V_135 )
break;
F_24 ( 6 ) ;
}
if ( V_135 == 2 )
goto V_97;
V_69 = F_1 ( V_2 , V_141 , & V_140 ) ;
if ( V_69 < 0 )
goto V_97;
* V_139 = V_140 * 15625 ;
F_2 ( L_95 , * V_139 ) ;
V_97:
F_32 ( & V_2 -> V_136 ) ;
return V_69 ;
}
static int F_34 ( struct V_62 * V_63 , T_7 V_142 ,
enum V_143 V_144 ,
unsigned int type ,
T_2 V_116 ,
T_1 V_9 )
{
struct V_1 * V_2 = V_63 -> V_66 ;
int V_69 = - V_84 ;
unsigned char V_5 [ 4 ] ;
T_7 div , V_145 = 0 ;
F_2 ( L_39 , V_7 ) ;
F_31 ( & V_2 -> V_136 ) ;
F_2 ( L_96 , V_142 / 1000 ) ;
if ( F_28 ( V_63 , type , V_116 , V_9 ) < 0 )
goto V_97;
switch ( V_144 ) {
case V_146 :
V_69 = F_27 (priv, {0x00 , 0x00}) ;
break;
case V_147 :
break;
case V_148 :
if ( V_2 -> V_58 . type & V_16 )
V_145 = 1750000 ;
else
V_145 = 2750000 ;
#if 0
if (priv->firm_version < 0x0302) {
if (priv->cur_fw.type & DTV7)
offset += 500000;
} else {
if (priv->cur_fw.type & DTV7)
offset -= 300000;
else if (type != ATSC)
offset += 200000;
}
#endif
break;
default:
F_11 ( L_97 , V_144 ) ;
break;
}
div = ( V_142 - V_145 + DIV / 2 ) / DIV ;
if ( V_2 -> V_76 < 0x0202 )
V_69 = F_27 (priv, {0x00 , XREG_RF_FREQ, 0x00 , 0x00}) ;
else
V_69 = F_27 (priv, {0x80 , XREG_RF_FREQ, 0x00 , 0x00}) ;
if ( V_69 < 0 )
goto V_97;
if ( V_2 -> V_108 . F_24 )
F_24 ( V_2 -> V_108 . F_24 ) ;
F_21 ( V_63 , V_112 , 1 ) ;
F_24 ( 10 ) ;
V_5 [ 0 ] = 0xff & ( div >> 24 ) ;
V_5 [ 1 ] = 0xff & ( div >> 16 ) ;
V_5 [ 2 ] = 0xff & ( div >> 8 ) ;
V_5 [ 3 ] = 0xff & ( div ) ;
V_69 = F_25 ( V_2 , V_5 , sizeof( V_5 ) ) ;
if ( V_69 < 0 )
goto V_97;
F_24 ( 100 ) ;
V_2 -> V_149 = V_142 ;
F_2 ( L_98 , 4 , V_5 ,
V_142 / 1000000 , ( V_142 % 1000000 ) / 1000 ) ;
V_69 = 0 ;
V_97:
F_32 ( & V_2 -> V_136 ) ;
return V_69 ;
}
static int F_35 ( struct V_62 * V_63 ,
struct V_150 * V_67 )
{
struct V_1 * V_2 = V_63 -> V_66 ;
unsigned int type = 0 ;
F_2 ( L_39 , V_7 ) ;
if ( V_67 -> V_151 == V_147 ) {
type |= V_21 ;
if ( V_2 -> V_108 . V_152 )
type |= V_22 ;
return F_34 ( V_63 , ( 625l * V_67 -> V_149 ) / 10 ,
V_147 , type , 0 , 0 ) ;
}
if ( ! V_67 -> V_116 )
V_67 -> V_116 = V_153 ;
if ( ! ( V_67 -> V_116 & V_153 ) )
type |= V_12 ;
V_67 -> V_116 |= F_6 () ;
return F_34 ( V_63 , 62500l * V_67 -> V_149 ,
V_146 , type , V_67 -> V_116 , 0 ) ;
}
static int F_36 ( struct V_62 * V_63 )
{
struct V_154 * V_155 = & V_63 -> V_156 ;
T_7 V_157 = V_155 -> V_158 ;
T_7 V_159 = V_155 -> V_160 ;
struct V_1 * V_2 = V_63 -> V_66 ;
int V_69 ;
unsigned int type = 0 ;
T_1 V_161 = 0 ;
F_2 ( L_39 , V_7 ) ;
V_69 = F_7 ( V_2 ) ;
if ( V_69 < 0 )
return V_69 ;
switch ( V_157 ) {
case V_162 :
case V_163 :
if ( V_159 <= 6000000 )
type |= V_17 ;
switch ( V_2 -> V_108 . type ) {
case V_164 :
type |= V_15 ;
break;
case V_165 :
type |= V_14 ;
break;
case V_166 :
default:
if ( V_2 -> V_108 . V_161 == V_167 )
type |= V_15 ;
else
type |= V_14 ;
}
break;
case V_168 :
type |= V_26 | V_15 ;
break;
default:
return - V_84 ;
}
if ( V_159 <= 6000000 ) {
type |= V_16 ;
V_2 -> V_108 . V_169 = 0 ;
V_2 -> V_108 . V_170 = 0 ;
} else if ( V_159 <= 7000000 ) {
if ( V_155 -> V_149 < 470000000 )
V_2 -> V_108 . V_169 = 1 ;
else
V_2 -> V_108 . V_170 = 0 ;
type |= ( V_2 -> V_108 . V_169 && V_2 -> V_108 . V_170 ) ? V_19 : V_18 ;
type |= V_12 ;
} else {
if ( V_155 -> V_149 < 470000000 )
V_2 -> V_108 . V_169 = 0 ;
else
V_2 -> V_108 . V_170 = 1 ;
type |= ( V_2 -> V_108 . V_169 && V_2 -> V_108 . V_170 ) ? V_19 : V_20 ;
type |= V_12 ;
}
if ( V_2 -> V_108 . V_161 ) {
V_161 = V_2 -> V_108 . V_161 ;
if ( type == V_26 || V_2 -> V_76 < 0x0302 )
V_161 += 200 ;
}
return F_34 ( V_63 , V_155 -> V_149 ,
V_148 , type , 0 , V_161 ) ;
}
static int F_29 ( struct V_62 * V_63 )
{
struct V_1 * V_2 = V_63 -> V_66 ;
int V_69 ;
V_69 = F_7 ( V_2 ) ;
if ( V_69 < 0 )
return V_69 ;
if ( ! V_69 )
return 0 ;
if ( V_171 || V_2 -> V_108 . V_172 )
return 0 ;
F_2 ( L_99 ) ;
if ( V_82 > 1 ) {
F_2 ( L_100 ) ;
F_37 () ;
}
F_31 ( & V_2 -> V_136 ) ;
if ( V_2 -> V_76 < 0x0202 )
V_69 = F_27 (priv, {0x00 , XREG_POWER_DOWN, 0x00 , 0x00}) ;
else
V_69 = F_27 (priv, {0x80 , XREG_POWER_DOWN, 0x00 , 0x00}) ;
if ( V_69 >= 0 )
V_2 -> V_47 = V_52 ;
F_32 ( & V_2 -> V_136 ) ;
return V_69 ;
}
static int F_38 ( struct V_62 * V_63 )
{
struct V_1 * V_2 = V_63 -> V_66 ;
F_2 ( L_39 , V_7 ) ;
F_31 ( & V_173 ) ;
if ( F_39 ( V_2 ) == 1 )
F_8 ( V_2 ) ;
if ( V_2 )
F_40 ( V_2 ) ;
F_32 ( & V_173 ) ;
V_63 -> V_66 = NULL ;
return 0 ;
}
static int F_41 ( struct V_62 * V_63 , T_7 * V_149 )
{
struct V_1 * V_2 = V_63 -> V_66 ;
int V_69 ;
F_2 ( L_39 , V_7 ) ;
V_69 = F_7 ( V_2 ) ;
if ( V_69 < 0 )
return V_69 ;
* V_149 = V_2 -> V_149 ;
return 0 ;
}
static void F_42 ( const struct V_64 * V_65 ,
void * V_174 )
{
struct V_62 * V_63 = V_174 ;
struct V_1 * V_2 = V_63 -> V_66 ;
int V_69 ;
F_2 ( L_101 , V_65 ? L_102 : L_103 ) ;
if ( ! V_65 ) {
F_11 ( L_104 , V_2 -> V_56 ) ;
V_2 -> V_47 = V_53 ;
return;
}
V_69 = F_10 ( V_63 , V_65 ) ;
F_43 ( V_65 ) ;
if ( V_69 < 0 )
return;
V_2 -> V_47 = V_51 ;
}
static int F_44 ( struct V_62 * V_63 , void * V_175 )
{
struct V_1 * V_2 = V_63 -> V_66 ;
struct V_176 * V_67 = V_175 ;
int V_69 = 0 ;
F_2 ( L_39 , V_7 ) ;
F_31 ( & V_2 -> V_136 ) ;
memcpy ( & V_2 -> V_108 , V_67 , sizeof( V_2 -> V_108 ) ) ;
if ( ! V_57 [ 0 ] && V_67 -> V_56 &&
V_2 -> V_56 && strcmp ( V_67 -> V_56 , V_2 -> V_56 ) )
F_8 ( V_2 ) ;
if ( V_2 -> V_108 . V_109 < 9 )
V_2 -> V_108 . V_109 = 13 ;
if ( V_2 -> V_47 == V_48 ) {
if ( ! V_57 [ 0 ] )
V_2 -> V_56 = F_45 ( V_67 -> V_56 , V_77 ) ;
else
V_2 -> V_56 = V_57 ;
if ( ! V_2 -> V_56 ) {
V_69 = - V_78 ;
goto V_177;
}
V_69 = F_46 ( V_178 , 1 ,
V_2 -> V_56 ,
V_2 -> V_102 . V_103 -> V_179 . V_180 ,
V_77 ,
V_63 , F_42 ) ;
if ( V_69 < 0 ) {
F_11 ( L_105 ,
V_2 -> V_56 ) ;
V_2 -> V_47 = V_53 ;
} else
V_2 -> V_47 = V_49 ;
}
V_177:
F_32 ( & V_2 -> V_136 ) ;
return V_69 ;
}
struct V_62 * F_47 ( struct V_62 * V_63 ,
struct V_181 * V_182 )
{
struct V_1 * V_2 ;
int V_183 ;
if ( V_82 )
F_5 ( V_184 L_106 ) ;
if ( NULL == V_182 )
return NULL ;
if ( ! V_63 ) {
F_5 ( V_185 L_107 ) ;
return NULL ;
}
F_31 ( & V_173 ) ;
V_183 = F_48 ( struct V_1 , V_2 ,
V_186 ,
V_182 -> V_187 , V_182 -> V_188 ,
L_108 ) ;
switch ( V_183 ) {
case 0 :
goto V_129;
case 1 :
V_2 -> V_108 . V_109 = 13 ;
F_49 ( & V_2 -> V_136 ) ;
V_63 -> V_66 = V_2 ;
break;
case 2 :
V_63 -> V_66 = V_2 ;
break;
}
memcpy ( & V_63 -> V_189 . V_190 , & V_191 ,
sizeof( V_191 ) ) ;
F_13 ( L_109 , L_110 ) ;
if ( V_182 -> V_108 )
F_44 ( V_63 , V_182 -> V_108 ) ;
F_32 ( & V_173 ) ;
return V_63 ;
V_129:
F_32 ( & V_173 ) ;
F_38 ( V_63 ) ;
return NULL ;
}
