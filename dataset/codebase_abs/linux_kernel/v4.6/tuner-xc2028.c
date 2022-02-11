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
if ( ! V_2 -> V_56 )
return;
for ( V_55 = 0 ; V_55 < V_2 -> V_57 ; V_55 ++ )
F_9 ( V_2 -> V_56 [ V_55 ] . V_58 ) ;
F_9 ( V_2 -> V_56 ) ;
V_2 -> V_56 = NULL ;
V_2 -> V_57 = 0 ;
V_2 -> V_47 = V_48 ;
memset ( & V_2 -> V_59 , 0 , sizeof( V_2 -> V_59 ) ) ;
}
static int F_10 ( struct V_60 * V_61 ,
const struct V_62 * V_63 )
{
struct V_1 * V_2 = V_61 -> V_64 ;
const unsigned char * V_65 , * V_66 ;
int V_67 = 0 ;
int V_68 , V_69 ;
char V_70 [ 33 ] ;
F_2 ( L_39 , V_7 ) ;
V_65 = V_63 -> V_71 ;
V_66 = V_65 + V_63 -> V_72 ;
if ( V_63 -> V_72 < sizeof( V_70 ) - 1 + 2 + 2 ) {
F_11 ( L_40 ,
V_2 -> V_73 ) ;
goto V_74;
}
memcpy ( V_70 , V_65 , sizeof( V_70 ) - 1 ) ;
V_70 [ sizeof( V_70 ) - 1 ] = 0 ;
V_65 += sizeof( V_70 ) - 1 ;
V_2 -> V_75 = F_12 ( V_65 ) ;
V_65 += 2 ;
V_69 = F_12 ( V_65 ) ;
V_65 += 2 ;
F_13 ( L_41 ,
V_69 , V_2 -> V_73 , V_70 ,
V_2 -> V_75 >> 8 , V_2 -> V_75 & 0xff ) ;
V_2 -> V_56 = F_14 ( V_69 , sizeof( * V_2 -> V_56 ) , V_76 ) ;
if ( V_2 -> V_56 == NULL ) {
F_11 ( L_42 ) ;
V_67 = - V_77 ;
goto V_78;
}
V_2 -> V_57 = V_69 ;
V_68 = - 1 ;
while ( V_65 < V_66 ) {
T_3 type , V_72 ;
T_2 V_79 ;
T_4 V_9 = 0 ;
V_68 ++ ;
if ( V_68 >= V_69 ) {
F_11 ( L_43
L_44 ) ;
goto V_74;
}
if ( V_66 - V_65 < sizeof( type ) + sizeof( V_79 ) + sizeof( V_72 ) )
goto V_80;
type = F_15 ( V_65 ) ;
V_65 += sizeof( type ) ;
V_79 = F_16 ( V_65 ) ;
V_65 += sizeof( V_79 ) ;
if ( type & V_39 ) {
V_9 = F_12 ( V_65 ) ;
V_65 += sizeof( V_9 ) ;
if ( V_66 - V_65 < sizeof( V_72 ) )
goto V_80;
}
V_72 = F_15 ( V_65 ) ;
V_65 += sizeof( V_72 ) ;
if ( ! V_72 || V_72 > V_66 - V_65 ) {
F_11 ( L_45 ) ;
F_17 ( type ) ;
F_5 ( L_46
L_47 ,
type , ( unsigned long long ) V_79 ,
( unsigned ) ( V_66 - V_65 ) , V_72 ) ;
goto V_74;
}
V_2 -> V_56 [ V_68 ] . V_58 = F_18 ( V_72 , V_76 ) ;
if ( V_2 -> V_56 [ V_68 ] . V_58 == NULL ) {
F_11 ( L_42 ) ;
V_67 = - V_77 ;
goto V_78;
}
F_2 ( L_48 ) ;
if ( V_81 ) {
F_4 ( type , V_9 ) ;
F_5 ( L_49 ,
type , ( unsigned long long ) V_79 , V_72 ) ;
}
memcpy ( V_2 -> V_56 [ V_68 ] . V_58 , V_65 , V_72 ) ;
V_2 -> V_56 [ V_68 ] . type = type ;
V_2 -> V_56 [ V_68 ] . V_79 = V_79 ;
V_2 -> V_56 [ V_68 ] . V_72 = V_72 ;
V_2 -> V_56 [ V_68 ] . V_9 = V_9 ;
V_65 += V_72 ;
}
if ( V_68 + 1 != V_2 -> V_57 ) {
F_11 ( L_50 ) ;
goto V_74;
}
goto V_82;
V_80:
F_11 ( L_51 ) ;
V_74:
V_67 = - V_83 ;
F_11 ( L_52 ) ;
V_78:
F_13 ( L_53 ) ;
F_8 ( V_2 ) ;
V_82:
if ( V_67 == 0 )
F_2 ( L_54 ) ;
else
V_2 -> V_47 = V_53 ;
return V_67 ;
}
static int F_19 ( struct V_60 * V_61 , unsigned int type ,
T_2 * V_79 )
{
struct V_1 * V_2 = V_61 -> V_64 ;
int V_55 , V_84 = - 1 , V_85 = 0 ;
unsigned int V_86 = 0 ;
F_2 ( L_55 , V_7 ) ;
if ( V_81 ) {
F_17 ( type ) ;
F_5 ( L_56 , type , ( unsigned long long ) * V_79 ) ;
}
if ( ! V_2 -> V_56 ) {
F_11 ( L_57 ) ;
return - V_83 ;
}
if ( ( ( type & ~ V_38 ) == 0 ) && ( * V_79 == 0 ) )
* V_79 = V_87 ;
if ( type & V_10 )
V_86 = V_88 ;
else if ( type & V_38 ) {
type &= V_89 ;
V_86 = V_89 & ~ V_39 ;
} else if ( type & V_90 )
V_86 = V_90 ;
else if ( type & V_91 )
V_86 = V_91 ;
type &= V_86 ;
if ( ! ( type & V_38 ) )
V_86 = ~ 0 ;
for ( V_55 = 0 ; V_55 < V_2 -> V_57 ; V_55 ++ ) {
if ( ( type == ( V_2 -> V_56 [ V_55 ] . type & V_86 ) ) &&
( * V_79 == V_2 -> V_56 [ V_55 ] . V_79 ) )
goto V_92;
}
for ( V_55 = 0 ; V_55 < V_2 -> V_57 ; V_55 ++ ) {
T_2 V_93 ;
int V_94 ;
if ( type != ( V_2 -> V_56 [ V_55 ] . type & V_86 ) )
continue;
V_93 = * V_79 & V_2 -> V_56 [ V_55 ] . V_79 ;
if ( ! V_93 )
continue;
if ( ( * V_79 & V_93 ) == * V_79 )
goto V_92;
V_94 = F_20 ( V_93 ) ;
if ( V_94 > V_85 ) {
V_85 = V_94 ;
V_84 = V_55 ;
}
}
if ( V_85 > 0 ) {
F_2 ( L_58
L_59 , V_85 ) ;
F_17 ( type ) ;
F_5 ( L_60 , type , ( unsigned long long ) * V_79 ) ;
V_55 = V_84 ;
goto V_92;
}
V_55 = - V_95 ;
goto V_96;
V_92:
* V_79 = V_2 -> V_56 [ V_55 ] . V_79 ;
V_96:
F_2 ( L_61 , ( V_55 < 0 ) ? L_62 : L_63 ) ;
if ( V_81 ) {
F_17 ( type ) ;
F_5 ( L_56 , type , ( unsigned long long ) * V_79 ) ;
}
return V_55 ;
}
static inline int F_21 ( struct V_60 * V_61 , int V_97 , int V_98 )
{
struct V_1 * V_2 = V_61 -> V_64 ;
return ( ! V_61 -> V_99 ) ? - V_83 :
V_61 -> V_99 ( ( ( V_61 -> V_100 ) && ( V_61 -> V_100 -> V_2 ) ) ?
V_61 -> V_100 -> V_2 : V_2 -> V_101 . V_102 -> V_103 ,
V_104 , V_97 , V_98 ) ;
}
static int F_22 ( struct V_60 * V_61 , unsigned int type ,
T_2 * V_79 )
{
struct V_1 * V_2 = V_61 -> V_64 ;
int V_105 , V_67 ;
unsigned char * V_65 , * V_66 , V_5 [ V_106 ] ;
if ( V_2 -> V_107 . V_108 > sizeof( V_5 ) )
V_2 -> V_107 . V_108 = sizeof( V_5 ) ;
F_2 ( L_39 , V_7 ) ;
V_105 = F_19 ( V_61 , type , V_79 ) ;
if ( V_105 < 0 )
return V_105 ;
F_13 ( L_64 ) ;
F_17 ( V_2 -> V_56 [ V_105 ] . type ) ;
F_5 ( L_56 , V_2 -> V_56 [ V_105 ] . type ,
( unsigned long long ) * V_79 ) ;
V_65 = V_2 -> V_56 [ V_105 ] . V_58 ;
V_66 = V_65 + V_2 -> V_56 [ V_105 ] . V_72 ;
while ( V_65 < V_66 ) {
T_4 V_72 ;
if ( V_65 + sizeof( V_72 ) > V_66 ) {
F_11 ( L_65 ) ;
return - V_83 ;
}
V_72 = F_23 ( * ( V_109 * ) V_65 ) ;
V_65 += sizeof( V_72 ) ;
if ( V_72 == 0xffff )
return 0 ;
if ( ! V_72 ) {
V_67 = F_21 ( V_61 , V_110 , 0 ) ;
if ( V_67 < 0 ) {
F_11 ( L_66 ,
( * V_65 ) & 0x7f ) ;
return - V_83 ;
}
continue;
}
if ( V_72 >= 0xff00 ) {
switch ( V_72 ) {
case 0xff00 :
V_67 = F_21 ( V_61 , V_111 , 0 ) ;
if ( V_67 < 0 ) {
F_11 ( L_66 ,
( * V_65 ) & 0x7f ) ;
return - V_83 ;
}
break;
default:
F_13 ( L_67 ,
V_72 & 0x7f ) ;
return - V_83 ;
}
continue;
}
if ( V_72 & 0x8000 ) {
F_24 ( V_72 & 0x7fff ) ;
continue;
}
if ( ( V_72 + V_65 > V_66 ) ) {
F_11 ( L_68 ,
V_72 , ( int ) ( V_66 - V_65 ) ) ;
return - V_83 ;
}
V_5 [ 0 ] = * V_65 ;
V_65 ++ ;
V_72 -- ;
while ( V_72 > 0 ) {
int V_112 = ( V_72 < V_2 -> V_107 . V_108 - 1 ) ?
V_72 : V_2 -> V_107 . V_108 - 1 ;
memcpy ( V_5 + 1 , V_65 , V_112 ) ;
V_67 = F_25 ( V_2 , V_5 , V_112 + 1 ) ;
if ( V_67 < 0 ) {
F_11 ( L_69 , V_67 ) ;
return - V_83 ;
}
V_65 += V_112 ;
V_72 -= V_112 ;
}
V_67 = F_21 ( V_61 , V_113 , 0 ) ;
if ( ( V_67 < 0 ) && ( V_67 != - V_83 ) ) {
F_11 ( L_70 , V_67 ) ;
return V_67 ;
}
}
return 0 ;
}
static int F_26 ( struct V_60 * V_61 , unsigned int type ,
T_2 * V_79 , T_4 V_9 , int V_114 )
{
struct V_1 * V_2 = V_61 -> V_64 ;
int V_105 , V_67 ;
unsigned char * V_65 ;
F_2 ( L_39 , V_7 ) ;
if ( ! V_9 ) {
V_105 = F_19 ( V_61 , type , V_79 ) ;
if ( V_105 < 0 )
return V_105 ;
} else {
for ( V_105 = 0 ; V_105 < V_2 -> V_57 ; V_105 ++ ) {
if ( ( V_2 -> V_56 [ V_105 ] . V_9 == V_9 ) &&
( V_2 -> V_56 [ V_105 ] . type & V_39 ) )
break;
}
if ( V_105 == V_2 -> V_57 )
return - V_95 ;
}
V_65 = V_2 -> V_56 [ V_105 ] . V_58 ;
if ( V_2 -> V_56 [ V_105 ] . type & V_39 ) {
if ( V_2 -> V_56 [ V_105 ] . V_72 != 12 * 16 || V_114 >= 16 )
return - V_83 ;
V_65 += 12 * V_114 ;
} else {
if ( V_2 -> V_56 [ V_105 ] . V_72 != 14 * 16 || V_114 >= 16 ||
F_23 ( * ( V_109 * ) ( V_65 + 14 * V_114 ) ) != 12 )
return - V_83 ;
V_65 += 14 * V_114 + 2 ;
}
F_13 ( L_71 ) ;
F_4 ( V_2 -> V_56 [ V_105 ] . type ,
V_2 -> V_56 [ V_105 ] . V_9 ) ;
F_5 ( L_56 , V_2 -> V_56 [ V_105 ] . type ,
( unsigned long long ) * V_79 ) ;
if ( V_2 -> V_75 < 0x0202 )
V_67 = F_27 (priv, {0x20 , 0x00 , 0x00 , 0x00}) ;
else
V_67 = F_27 (priv, {0xa0 , 0x00 , 0x00 , 0x00}) ;
if ( V_67 < 0 )
return - V_8 ;
V_67 = F_25 ( V_2 , V_65 , 12 ) ;
if ( V_67 < 0 )
return - V_8 ;
V_67 = F_27 (priv, {0x00 , 0x8c}) ;
if ( V_67 < 0 )
return - V_8 ;
return 0 ;
}
static int F_28 ( struct V_60 * V_61 , unsigned int type ,
T_2 V_115 , T_4 V_9 )
{
struct V_1 * V_2 = V_61 -> V_64 ;
struct V_116 V_117 ;
int V_67 , V_118 = 0 ;
T_1 V_119 , V_120 ;
T_2 V_121 ;
F_2 ( L_39 , V_7 ) ;
V_67 = F_7 ( V_2 ) ;
if ( V_67 < 0 )
return V_67 ;
if ( V_2 -> V_107 . V_122 && ! ( type & V_21 ) )
type |= V_13 ;
V_123:
V_117 . type = type ;
V_117 . V_79 = V_115 ;
V_117 . V_124 = V_115 ;
V_117 . V_125 = V_38 | V_2 -> V_107 . V_125 ;
V_117 . V_126 = 0 ;
V_117 . V_9 = V_9 ;
F_2 ( L_72 ) ;
if ( V_81 ) {
F_17 ( V_117 . type ) ;
F_5 ( L_73 , V_117 . type ,
( unsigned long long ) V_117 . V_124 ) ;
if ( ! V_9 ) {
F_5 ( L_74 ) ;
F_17 ( V_2 -> V_107 . V_125 ) ;
F_5 ( L_75 , V_2 -> V_107 . V_125 ) ;
} else
F_5 ( L_76 , V_117 . V_9 ) ;
F_5 ( L_77 , V_117 . V_126 ) ;
}
if ( ( V_2 -> V_47 == V_51 ) &&
( ( ( V_10 | V_117 . type ) & V_88 ) ==
( V_2 -> V_59 . type & V_88 ) ) ) {
F_2 ( L_78 ) ;
goto V_127;
}
memset ( & V_2 -> V_59 , 0 , sizeof( V_2 -> V_59 ) ) ;
V_67 = F_21 ( V_61 , V_110 , 0 ) ;
if ( V_67 < 0 )
goto V_128;
V_121 = 0 ;
V_67 = F_22 ( V_61 , V_10 | V_117 . type , & V_121 ) ;
if ( V_67 < 0 ) {
F_11 ( L_79 ,
V_67 ) ;
goto V_128;
}
F_2 ( L_80 ) ;
V_67 = F_22 ( V_61 , V_10 | V_11 | V_117 . type , & V_121 ) ;
if ( V_67 == - V_95 )
V_67 = F_22 ( V_61 , ( V_10 | V_11 | V_117 . type ) & ~ V_12 ,
& V_121 ) ;
if ( V_67 < 0 && V_67 != - V_95 ) {
F_11 ( L_81 ,
V_67 ) ;
goto V_128;
}
V_127:
if ( V_2 -> V_59 . type == ( V_10 | V_117 . type ) &&
V_2 -> V_59 . V_124 == V_115 ) {
F_2 ( L_82 ) ;
goto V_129;
}
V_2 -> V_59 . V_125 = 0 ;
V_67 = F_22 ( V_61 , V_117 . type , & V_117 . V_79 ) ;
if ( V_67 == - V_95 )
V_67 = F_22 ( V_61 , V_117 . type & ~ V_12 , & V_117 . V_79 ) ;
if ( V_67 < 0 )
goto V_128;
V_129:
if ( V_2 -> V_59 . V_125 == V_117 . V_125 &&
V_2 -> V_59 . V_126 == V_117 . V_126 ) {
F_2 ( L_83 ) ;
goto V_130;
}
if ( V_117 . type & V_21 )
goto V_130;
F_2 ( L_84 , V_117 . V_126 ) ;
V_67 = F_26 ( V_61 , V_117 . type | V_117 . V_125 , & V_117 . V_79 ,
V_117 . V_9 , V_117 . V_126 ) ;
V_130:
if ( F_1 ( V_2 , 0x0004 , & V_119 ) < 0 ||
F_1 ( V_2 , 0x0008 , & V_120 ) < 0 ) {
F_11 ( L_85 ) ;
goto V_128;
}
F_2 ( L_86
L_87 ,
V_120 , ( V_119 & 0xf000 ) >> 12 , ( V_119 & 0xf00 ) >> 8 ,
( V_119 & 0xf0 ) >> 4 , V_119 & 0xf ) ;
if ( V_2 -> V_107 . V_131 )
goto V_131;
if ( V_2 -> V_75 != ( ( V_119 & 0xf0 ) << 4 | ( V_119 & 0x0f ) ) ) {
if ( ! V_2 -> V_107 . V_131 ) {
F_11 ( L_88 ) ;
goto V_128;
} else {
F_11 ( L_89
L_90 ) ;
V_120 = 3028 ;
}
}
if ( V_2 -> V_120 == 0 && ( V_120 == 2028 || V_120 == 3028 ) ) {
V_2 -> V_120 = V_120 ;
V_2 -> V_132 = V_119 & 0xff00 ;
} else if ( V_2 -> V_120 == 0 || V_2 -> V_120 != V_120 ||
V_2 -> V_132 != ( V_119 & 0xff00 ) ) {
F_11 ( L_91
L_92 ) ;
goto V_128;
}
V_131:
V_2 -> V_59 = V_117 ;
V_2 -> V_59 . type |= V_10 ;
V_2 -> V_47 = V_51 ;
return 0 ;
V_128:
V_2 -> V_47 = V_48 ;
memset ( & V_2 -> V_59 , 0 , sizeof( V_2 -> V_59 ) ) ;
if ( V_118 < 8 ) {
F_24 ( 50 ) ;
V_118 ++ ;
F_2 ( L_93 ) ;
goto V_123;
}
F_29 ( V_61 ) ;
if ( V_67 == - V_95 )
V_67 = - V_83 ;
return V_67 ;
}
static int F_30 ( struct V_60 * V_61 , T_1 * V_133 )
{
struct V_1 * V_2 = V_61 -> V_64 ;
T_1 V_134 , signal = 0 ;
int V_67 , V_55 ;
F_2 ( L_39 , V_7 ) ;
V_67 = F_7 ( V_2 ) ;
if ( V_67 < 0 )
return V_67 ;
if ( ! V_67 ) {
* V_133 = 0 ;
return 0 ;
}
F_31 ( & V_2 -> V_135 ) ;
for ( V_55 = 0 ; V_55 < 3 ; V_55 ++ ) {
V_67 = F_1 ( V_2 , V_136 , & V_134 ) ;
if ( V_67 < 0 )
goto V_96;
if ( V_134 )
break;
F_24 ( 6 ) ;
}
if ( V_134 == 2 )
goto V_96;
V_67 = F_1 ( V_2 , V_137 , & signal ) ;
if ( V_67 < 0 )
goto V_96;
signal = ( ( 1 << 12 ) - 1 ) | ( ( signal & 0x07 ) << 12 ) ;
V_96:
F_32 ( & V_2 -> V_135 ) ;
* V_133 = signal ;
F_2 ( L_94 , signal ) ;
return V_67 ;
}
static int F_33 ( struct V_60 * V_61 , T_5 * V_138 )
{
struct V_1 * V_2 = V_61 -> V_64 ;
int V_55 , V_67 ;
T_1 V_134 = 0 ;
T_6 V_139 = 0 ;
V_67 = F_7 ( V_2 ) ;
if ( V_67 < 0 )
return V_67 ;
if ( ! V_67 ) {
* V_138 = 0 ;
return 0 ;
}
F_31 ( & V_2 -> V_135 ) ;
for ( V_55 = 0 ; V_55 < 3 ; V_55 ++ ) {
V_67 = F_1 ( V_2 , V_136 , & V_134 ) ;
if ( V_67 < 0 )
goto V_96;
if ( V_134 )
break;
F_24 ( 6 ) ;
}
if ( V_134 == 2 )
goto V_96;
V_67 = F_1 ( V_2 , V_140 , & V_139 ) ;
if ( V_67 < 0 )
goto V_96;
* V_138 = V_139 * 15625 ;
F_2 ( L_95 , * V_138 ) ;
V_96:
F_32 ( & V_2 -> V_135 ) ;
return V_67 ;
}
static int F_34 ( struct V_60 * V_61 , T_7 V_141 ,
enum V_142 V_143 ,
unsigned int type ,
T_2 V_115 ,
T_1 V_9 )
{
struct V_1 * V_2 = V_61 -> V_64 ;
int V_67 = - V_83 ;
unsigned char V_5 [ 4 ] ;
T_7 div , V_144 = 0 ;
F_2 ( L_39 , V_7 ) ;
F_31 ( & V_2 -> V_135 ) ;
F_2 ( L_96 , V_141 / 1000 ) ;
if ( F_28 ( V_61 , type , V_115 , V_9 ) < 0 )
goto V_96;
switch ( V_143 ) {
case V_145 :
V_67 = F_27 (priv, {0x00 , 0x00}) ;
break;
case V_146 :
break;
case V_147 :
if ( V_2 -> V_59 . type & V_16 )
V_144 = 1750000 ;
else
V_144 = 2750000 ;
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
F_11 ( L_97 , V_143 ) ;
break;
}
div = ( V_141 - V_144 + DIV / 2 ) / DIV ;
if ( V_2 -> V_75 < 0x0202 )
V_67 = F_27 (priv, {0x00 , XREG_RF_FREQ, 0x00 , 0x00}) ;
else
V_67 = F_27 (priv, {0x80 , XREG_RF_FREQ, 0x00 , 0x00}) ;
if ( V_67 < 0 )
goto V_96;
if ( V_2 -> V_107 . F_24 )
F_24 ( V_2 -> V_107 . F_24 ) ;
F_21 ( V_61 , V_111 , 1 ) ;
F_24 ( 10 ) ;
V_5 [ 0 ] = 0xff & ( div >> 24 ) ;
V_5 [ 1 ] = 0xff & ( div >> 16 ) ;
V_5 [ 2 ] = 0xff & ( div >> 8 ) ;
V_5 [ 3 ] = 0xff & ( div ) ;
V_67 = F_25 ( V_2 , V_5 , sizeof( V_5 ) ) ;
if ( V_67 < 0 )
goto V_96;
F_24 ( 100 ) ;
V_2 -> V_148 = V_141 ;
F_2 ( L_98 , 4 , V_5 ,
V_141 / 1000000 , ( V_141 % 1000000 ) / 1000 ) ;
V_67 = 0 ;
V_96:
F_32 ( & V_2 -> V_135 ) ;
return V_67 ;
}
static int F_35 ( struct V_60 * V_61 ,
struct V_149 * V_65 )
{
struct V_1 * V_2 = V_61 -> V_64 ;
unsigned int type = 0 ;
F_2 ( L_39 , V_7 ) ;
if ( V_65 -> V_150 == V_146 ) {
type |= V_21 ;
if ( V_2 -> V_107 . V_151 )
type |= V_22 ;
return F_34 ( V_61 , ( 625l * V_65 -> V_148 ) / 10 ,
V_146 , type , 0 , 0 ) ;
}
if ( ! V_65 -> V_115 )
V_65 -> V_115 = V_152 ;
if ( ! ( V_65 -> V_115 & V_152 ) )
type |= V_12 ;
V_65 -> V_115 |= F_6 () ;
return F_34 ( V_61 , 62500l * V_65 -> V_148 ,
V_145 , type , V_65 -> V_115 , 0 ) ;
}
static int F_36 ( struct V_60 * V_61 )
{
struct V_153 * V_154 = & V_61 -> V_155 ;
T_7 V_156 = V_154 -> V_157 ;
T_7 V_158 = V_154 -> V_159 ;
struct V_1 * V_2 = V_61 -> V_64 ;
int V_67 ;
unsigned int type = 0 ;
T_1 V_160 = 0 ;
F_2 ( L_39 , V_7 ) ;
V_67 = F_7 ( V_2 ) ;
if ( V_67 < 0 )
return V_67 ;
switch ( V_156 ) {
case V_161 :
case V_162 :
if ( V_158 <= 6000000 )
type |= V_17 ;
switch ( V_2 -> V_107 . type ) {
case V_163 :
type |= V_15 ;
break;
case V_164 :
type |= V_14 ;
break;
case V_165 :
default:
if ( V_2 -> V_107 . V_160 == V_166 )
type |= V_15 ;
else
type |= V_14 ;
}
break;
case V_167 :
type |= V_26 | V_15 ;
break;
default:
return - V_83 ;
}
if ( V_158 <= 6000000 ) {
type |= V_16 ;
V_2 -> V_107 . V_168 = 0 ;
V_2 -> V_107 . V_169 = 0 ;
} else if ( V_158 <= 7000000 ) {
if ( V_154 -> V_148 < 470000000 )
V_2 -> V_107 . V_168 = 1 ;
else
V_2 -> V_107 . V_169 = 0 ;
type |= ( V_2 -> V_107 . V_168 && V_2 -> V_107 . V_169 ) ? V_19 : V_18 ;
type |= V_12 ;
} else {
if ( V_154 -> V_148 < 470000000 )
V_2 -> V_107 . V_168 = 0 ;
else
V_2 -> V_107 . V_169 = 1 ;
type |= ( V_2 -> V_107 . V_168 && V_2 -> V_107 . V_169 ) ? V_19 : V_20 ;
type |= V_12 ;
}
if ( V_2 -> V_107 . V_160 ) {
V_160 = V_2 -> V_107 . V_160 ;
if ( type == V_26 || V_2 -> V_75 < 0x0302 )
V_160 += 200 ;
}
return F_34 ( V_61 , V_154 -> V_148 ,
V_147 , type , 0 , V_160 ) ;
}
static int F_29 ( struct V_60 * V_61 )
{
struct V_1 * V_2 = V_61 -> V_64 ;
int V_67 ;
V_67 = F_7 ( V_2 ) ;
if ( V_67 < 0 )
return V_67 ;
if ( ! V_67 )
return 0 ;
if ( V_170 || V_2 -> V_107 . V_171 )
return 0 ;
F_2 ( L_99 ) ;
if ( V_81 > 1 ) {
F_2 ( L_100 ) ;
F_37 () ;
}
F_31 ( & V_2 -> V_135 ) ;
if ( V_2 -> V_75 < 0x0202 )
V_67 = F_27 (priv, {0x00 , XREG_POWER_DOWN, 0x00 , 0x00}) ;
else
V_67 = F_27 (priv, {0x80 , XREG_POWER_DOWN, 0x00 , 0x00}) ;
if ( V_67 >= 0 )
V_2 -> V_47 = V_52 ;
F_32 ( & V_2 -> V_135 ) ;
return V_67 ;
}
static int F_38 ( struct V_60 * V_61 )
{
struct V_1 * V_2 = V_61 -> V_64 ;
F_2 ( L_39 , V_7 ) ;
F_31 ( & V_172 ) ;
if ( F_39 ( V_2 ) == 1 ) {
F_8 ( V_2 ) ;
F_9 ( V_2 -> V_107 . V_73 ) ;
V_2 -> V_107 . V_73 = NULL ;
}
if ( V_2 )
F_40 ( V_2 ) ;
F_32 ( & V_172 ) ;
V_61 -> V_64 = NULL ;
return 0 ;
}
static int F_41 ( struct V_60 * V_61 , T_7 * V_148 )
{
struct V_1 * V_2 = V_61 -> V_64 ;
int V_67 ;
F_2 ( L_39 , V_7 ) ;
V_67 = F_7 ( V_2 ) ;
if ( V_67 < 0 )
return V_67 ;
* V_148 = V_2 -> V_148 ;
return 0 ;
}
static void F_42 ( const struct V_62 * V_63 ,
void * V_173 )
{
struct V_60 * V_61 = V_173 ;
struct V_1 * V_2 = V_61 -> V_64 ;
int V_67 ;
F_2 ( L_101 , V_63 ? L_102 : L_103 ) ;
if ( ! V_63 ) {
F_11 ( L_104 , V_2 -> V_73 ) ;
V_2 -> V_47 = V_53 ;
return;
}
V_67 = F_10 ( V_61 , V_63 ) ;
F_43 ( V_63 ) ;
if ( V_67 < 0 )
return;
V_2 -> V_47 = V_51 ;
}
static int F_44 ( struct V_60 * V_61 , void * V_174 )
{
struct V_1 * V_2 = V_61 -> V_64 ;
struct V_175 * V_65 = V_174 ;
int V_67 = 0 ;
F_2 ( L_39 , V_7 ) ;
F_31 ( & V_2 -> V_135 ) ;
F_9 ( V_2 -> V_107 . V_73 ) ;
V_2 -> V_107 . V_73 = NULL ;
memcpy ( & V_2 -> V_107 , V_65 , sizeof( V_2 -> V_107 ) ) ;
if ( V_65 -> V_73 ) {
V_2 -> V_107 . V_73 = F_45 ( V_65 -> V_73 , V_76 ) ;
if ( V_2 -> V_107 . V_73 == NULL ) {
V_67 = - V_77 ;
goto V_176;
}
}
if ( ! V_177 [ 0 ] && V_65 -> V_73 &&
V_2 -> V_73 && strcmp ( V_65 -> V_73 , V_2 -> V_73 ) )
F_8 ( V_2 ) ;
if ( V_2 -> V_107 . V_108 < 9 )
V_2 -> V_107 . V_108 = 13 ;
if ( V_2 -> V_47 == V_48 ) {
if ( ! V_177 [ 0 ] )
V_2 -> V_73 = V_2 -> V_107 . V_73 ;
else
V_2 -> V_73 = V_177 ;
V_67 = F_46 ( V_178 , 1 ,
V_2 -> V_73 ,
V_2 -> V_101 . V_102 -> V_179 . V_180 ,
V_76 ,
V_61 , F_42 ) ;
if ( V_67 < 0 ) {
F_11 ( L_105 ,
V_2 -> V_73 ) ;
V_2 -> V_47 = V_53 ;
} else
V_2 -> V_47 = V_49 ;
}
V_176:
F_32 ( & V_2 -> V_135 ) ;
return V_67 ;
}
struct V_60 * F_47 ( struct V_60 * V_61 ,
struct V_181 * V_182 )
{
struct V_1 * V_2 ;
int V_183 ;
if ( V_81 )
F_5 ( V_184 L_106 ) ;
if ( NULL == V_182 )
return NULL ;
if ( ! V_61 ) {
F_5 ( V_185 L_107 ) ;
return NULL ;
}
F_31 ( & V_172 ) ;
V_183 = F_48 ( struct V_1 , V_2 ,
V_186 ,
V_182 -> V_187 , V_182 -> V_188 ,
L_108 ) ;
switch ( V_183 ) {
case 0 :
goto V_128;
case 1 :
V_2 -> V_107 . V_108 = 13 ;
F_49 ( & V_2 -> V_135 ) ;
V_61 -> V_64 = V_2 ;
break;
case 2 :
V_61 -> V_64 = V_2 ;
break;
}
memcpy ( & V_61 -> V_189 . V_190 , & V_191 ,
sizeof( V_191 ) ) ;
F_13 ( L_109 , L_110 ) ;
if ( V_182 -> V_107 )
F_44 ( V_61 , V_182 -> V_107 ) ;
F_32 ( & V_172 ) ;
return V_61 ;
V_128:
F_32 ( & V_172 ) ;
F_38 ( V_61 ) ;
return NULL ;
}
