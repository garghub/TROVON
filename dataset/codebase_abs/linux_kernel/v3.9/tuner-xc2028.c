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
unsigned char * V_65 , * V_66 , V_5 [ V_2 -> V_106 . V_107 ] ;
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
V_72 = F_23 ( * ( T_4 * ) V_65 ) ;
V_65 += sizeof( V_72 ) ;
if ( V_72 == 0xffff )
return 0 ;
if ( ! V_72 ) {
V_67 = F_21 ( V_61 , V_108 , 0 ) ;
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
V_67 = F_21 ( V_61 , V_109 , 0 ) ;
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
int V_110 = ( V_72 < V_2 -> V_106 . V_107 - 1 ) ?
V_72 : V_2 -> V_106 . V_107 - 1 ;
memcpy ( V_5 + 1 , V_65 , V_110 ) ;
V_67 = F_25 ( V_2 , V_5 , V_110 + 1 ) ;
if ( V_67 < 0 ) {
F_11 ( L_69 , V_67 ) ;
return - V_83 ;
}
V_65 += V_110 ;
V_72 -= V_110 ;
}
V_67 = F_21 ( V_61 , V_111 , 0 ) ;
if ( ( V_67 < 0 ) && ( V_67 != - V_83 ) ) {
F_11 ( L_70 , V_67 ) ;
return V_67 ;
}
}
return 0 ;
}
static int F_26 ( struct V_60 * V_61 , unsigned int type ,
T_2 * V_79 , T_4 V_9 , int V_112 )
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
if ( V_2 -> V_56 [ V_105 ] . V_72 != 12 * 16 || V_112 >= 16 )
return - V_83 ;
V_65 += 12 * V_112 ;
} else {
if ( V_2 -> V_56 [ V_105 ] . V_72 != 14 * 16 || V_112 >= 16 ||
F_23 ( * ( T_4 * ) ( V_65 + 14 * V_112 ) ) != 12 )
return - V_83 ;
V_65 += 14 * V_112 + 2 ;
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
T_2 V_113 , T_4 V_9 )
{
struct V_1 * V_2 = V_61 -> V_64 ;
struct V_114 V_115 ;
int V_67 , V_116 = 0 ;
T_1 V_117 , V_118 ;
T_2 V_119 ;
F_2 ( L_39 , V_7 ) ;
V_67 = F_7 ( V_2 ) ;
if ( V_67 < 0 )
return V_67 ;
if ( V_2 -> V_106 . V_120 && ! ( type & V_21 ) )
type |= V_13 ;
V_121:
V_115 . type = type ;
V_115 . V_79 = V_113 ;
V_115 . V_122 = V_113 ;
V_115 . V_123 = V_38 | V_2 -> V_106 . V_123 ;
V_115 . V_124 = 0 ;
V_115 . V_9 = V_9 ;
F_2 ( L_72 ) ;
if ( V_81 ) {
F_17 ( V_115 . type ) ;
F_5 ( L_73 , V_115 . type ,
( unsigned long long ) V_115 . V_122 ) ;
if ( ! V_9 ) {
F_5 ( L_74 ) ;
F_17 ( V_2 -> V_106 . V_123 ) ;
F_5 ( L_75 , V_2 -> V_106 . V_123 ) ;
} else
F_5 ( L_76 , V_115 . V_9 ) ;
F_5 ( L_77 , V_115 . V_124 ) ;
}
if ( ( V_2 -> V_47 == V_51 ) &&
( ( ( V_10 | V_115 . type ) & V_88 ) ==
( V_2 -> V_59 . type & V_88 ) ) ) {
F_2 ( L_78 ) ;
goto V_125;
}
memset ( & V_2 -> V_59 , 0 , sizeof( V_2 -> V_59 ) ) ;
V_67 = F_21 ( V_61 , V_108 , 0 ) ;
if ( V_67 < 0 )
goto V_126;
V_119 = 0 ;
V_67 = F_22 ( V_61 , V_10 | V_115 . type , & V_119 ) ;
if ( V_67 < 0 ) {
F_11 ( L_79 ,
V_67 ) ;
goto V_126;
}
F_2 ( L_80 ) ;
V_67 = F_22 ( V_61 , V_10 | V_11 | V_115 . type , & V_119 ) ;
if ( V_67 == - V_95 )
V_67 = F_22 ( V_61 , ( V_10 | V_11 | V_115 . type ) & ~ V_12 ,
& V_119 ) ;
if ( V_67 < 0 && V_67 != - V_95 ) {
F_11 ( L_81 ,
V_67 ) ;
goto V_126;
}
V_125:
if ( V_2 -> V_59 . type == ( V_10 | V_115 . type ) &&
V_2 -> V_59 . V_122 == V_113 ) {
F_2 ( L_82 ) ;
goto V_127;
}
V_2 -> V_59 . V_123 = 0 ;
V_67 = F_22 ( V_61 , V_115 . type , & V_115 . V_79 ) ;
if ( V_67 == - V_95 )
V_67 = F_22 ( V_61 , V_115 . type & ~ V_12 , & V_115 . V_79 ) ;
if ( V_67 < 0 )
goto V_126;
V_127:
if ( V_2 -> V_59 . V_123 == V_115 . V_123 &&
V_2 -> V_59 . V_124 == V_115 . V_124 ) {
F_2 ( L_83 ) ;
goto V_128;
}
if ( V_115 . type & V_21 )
goto V_128;
F_2 ( L_84 , V_115 . V_124 ) ;
V_67 = F_26 ( V_61 , V_115 . type | V_115 . V_123 , & V_115 . V_79 ,
V_115 . V_9 , V_115 . V_124 ) ;
V_128:
if ( F_1 ( V_2 , 0x0004 , & V_117 ) < 0 ||
F_1 ( V_2 , 0x0008 , & V_118 ) < 0 ) {
F_11 ( L_85 ) ;
goto V_126;
}
F_2 ( L_86
L_87 ,
V_118 , ( V_117 & 0xf000 ) >> 12 , ( V_117 & 0xf00 ) >> 8 ,
( V_117 & 0xf0 ) >> 4 , V_117 & 0xf ) ;
if ( V_2 -> V_106 . V_129 )
goto V_129;
if ( V_2 -> V_75 != ( ( V_117 & 0xf0 ) << 4 | ( V_117 & 0x0f ) ) ) {
if ( ! V_2 -> V_106 . V_129 ) {
F_11 ( L_88 ) ;
goto V_126;
} else {
F_11 ( L_89
L_90 ) ;
V_118 = 3028 ;
}
}
if ( V_2 -> V_118 == 0 && ( V_118 == 2028 || V_118 == 3028 ) ) {
V_2 -> V_118 = V_118 ;
V_2 -> V_130 = V_117 & 0xff00 ;
} else if ( V_2 -> V_118 == 0 || V_2 -> V_118 != V_118 ||
V_2 -> V_130 != ( V_117 & 0xff00 ) ) {
F_11 ( L_91
L_92 ) ;
goto V_126;
}
V_129:
V_2 -> V_59 = V_115 ;
V_2 -> V_59 . type |= V_10 ;
V_2 -> V_47 = V_51 ;
return 0 ;
V_126:
V_2 -> V_47 = V_52 ;
memset ( & V_2 -> V_59 , 0 , sizeof( V_2 -> V_59 ) ) ;
if ( V_116 < 8 ) {
F_24 ( 50 ) ;
V_116 ++ ;
F_2 ( L_93 ) ;
goto V_121;
}
if ( V_67 == - V_95 )
V_67 = - V_83 ;
return V_67 ;
}
static int F_29 ( struct V_60 * V_61 , T_1 * V_131 )
{
struct V_1 * V_2 = V_61 -> V_64 ;
T_1 V_132 , signal = 0 ;
int V_67 , V_55 ;
F_2 ( L_39 , V_7 ) ;
V_67 = F_7 ( V_2 ) ;
if ( V_67 < 0 )
return V_67 ;
F_30 ( & V_2 -> V_133 ) ;
for ( V_55 = 0 ; V_55 < 3 ; V_55 ++ ) {
V_67 = F_1 ( V_2 , V_134 , & V_132 ) ;
if ( V_67 < 0 )
goto V_96;
if ( V_132 )
break;
F_24 ( 6 ) ;
}
if ( V_132 == 2 )
goto V_96;
V_67 = F_1 ( V_2 , V_135 , & signal ) ;
if ( V_67 < 0 )
goto V_96;
signal = ( ( 1 << 12 ) - 1 ) | ( ( signal & 0x07 ) << 12 ) ;
V_96:
F_31 ( & V_2 -> V_133 ) ;
* V_131 = signal ;
F_2 ( L_94 , signal ) ;
return V_67 ;
}
static int F_32 ( struct V_60 * V_61 , T_5 * V_136 )
{
struct V_1 * V_2 = V_61 -> V_64 ;
int V_55 , V_67 ;
T_1 V_132 = 0 ;
T_6 V_137 = 0 ;
V_67 = F_7 ( V_2 ) ;
if ( V_67 < 0 )
return V_67 ;
F_30 ( & V_2 -> V_133 ) ;
for ( V_55 = 0 ; V_55 < 3 ; V_55 ++ ) {
V_67 = F_1 ( V_2 , V_134 , & V_132 ) ;
if ( V_67 < 0 )
goto V_96;
if ( V_132 )
break;
F_24 ( 6 ) ;
}
if ( V_132 == 2 )
goto V_96;
V_67 = F_1 ( V_2 , V_138 , & V_137 ) ;
if ( V_67 < 0 )
goto V_96;
* V_136 = V_137 * 15625 ;
F_2 ( L_95 , * V_136 ) ;
V_96:
F_31 ( & V_2 -> V_133 ) ;
return V_67 ;
}
static int F_33 ( struct V_60 * V_61 , T_7 V_139 ,
enum V_140 V_141 ,
unsigned int type ,
T_2 V_113 ,
T_1 V_9 )
{
struct V_1 * V_2 = V_61 -> V_64 ;
int V_67 = - V_83 ;
unsigned char V_5 [ 4 ] ;
T_7 div , V_142 = 0 ;
F_2 ( L_39 , V_7 ) ;
F_30 ( & V_2 -> V_133 ) ;
F_2 ( L_96 , V_139 / 1000 ) ;
if ( F_28 ( V_61 , type , V_113 , V_9 ) < 0 )
goto V_96;
switch ( V_141 ) {
case V_143 :
V_67 = F_27 (priv, {0x00 , 0x00}) ;
break;
case V_144 :
break;
case V_145 :
if ( V_2 -> V_59 . type & V_16 )
V_142 = 1750000 ;
else
V_142 = 2750000 ;
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
}
div = ( V_139 - V_142 + DIV / 2 ) / DIV ;
if ( V_2 -> V_75 < 0x0202 )
V_67 = F_27 (priv, {0x00 , XREG_RF_FREQ, 0x00 , 0x00}) ;
else
V_67 = F_27 (priv, {0x80 , XREG_RF_FREQ, 0x00 , 0x00}) ;
if ( V_67 < 0 )
goto V_96;
if ( V_2 -> V_106 . F_24 )
F_24 ( V_2 -> V_106 . F_24 ) ;
F_21 ( V_61 , V_109 , 1 ) ;
F_24 ( 10 ) ;
V_5 [ 0 ] = 0xff & ( div >> 24 ) ;
V_5 [ 1 ] = 0xff & ( div >> 16 ) ;
V_5 [ 2 ] = 0xff & ( div >> 8 ) ;
V_5 [ 3 ] = 0xff & ( div ) ;
V_67 = F_25 ( V_2 , V_5 , sizeof( V_5 ) ) ;
if ( V_67 < 0 )
goto V_96;
F_24 ( 100 ) ;
V_2 -> V_146 = V_139 ;
F_2 ( L_97 , 4 , V_5 ,
V_139 / 1000000 , ( V_139 % 1000000 ) / 1000 ) ;
V_67 = 0 ;
V_96:
F_31 ( & V_2 -> V_133 ) ;
return V_67 ;
}
static int F_34 ( struct V_60 * V_61 ,
struct V_147 * V_65 )
{
struct V_1 * V_2 = V_61 -> V_64 ;
unsigned int type = 0 ;
F_2 ( L_39 , V_7 ) ;
if ( V_65 -> V_148 == V_144 ) {
type |= V_21 ;
if ( V_2 -> V_106 . V_149 )
type |= V_22 ;
return F_33 ( V_61 , ( 625l * V_65 -> V_146 ) / 10 ,
V_144 , type , 0 , 0 ) ;
}
if ( ! V_65 -> V_113 )
V_65 -> V_113 = V_150 ;
if ( ! ( V_65 -> V_113 & V_150 ) )
type |= V_12 ;
V_65 -> V_113 |= F_6 () ;
return F_33 ( V_61 , 62500l * V_65 -> V_146 ,
V_143 , type , V_65 -> V_113 , 0 ) ;
}
static int F_35 ( struct V_60 * V_61 )
{
struct V_151 * V_152 = & V_61 -> V_153 ;
T_7 V_154 = V_152 -> V_155 ;
T_7 V_156 = V_152 -> V_157 ;
struct V_1 * V_2 = V_61 -> V_64 ;
int V_67 ;
unsigned int type = 0 ;
T_1 V_158 = 0 ;
F_2 ( L_39 , V_7 ) ;
V_67 = F_7 ( V_2 ) ;
if ( V_67 < 0 )
return V_67 ;
switch ( V_154 ) {
case V_159 :
case V_160 :
if ( V_156 <= 6000000 )
type |= V_17 ;
switch ( V_2 -> V_106 . type ) {
case V_161 :
type |= V_15 ;
break;
case V_162 :
type |= V_14 ;
break;
case V_163 :
default:
if ( V_2 -> V_106 . V_158 == V_164 )
type |= V_15 ;
else
type |= V_14 ;
}
break;
case V_165 :
type |= V_26 | V_15 ;
break;
default:
return - V_83 ;
}
if ( V_156 <= 6000000 ) {
type |= V_16 ;
V_2 -> V_106 . V_166 = 0 ;
V_2 -> V_106 . V_167 = 0 ;
} else if ( V_156 <= 7000000 ) {
if ( V_152 -> V_146 < 470000000 )
V_2 -> V_106 . V_166 = 1 ;
else
V_2 -> V_106 . V_167 = 0 ;
type |= ( V_2 -> V_106 . V_166 && V_2 -> V_106 . V_167 ) ? V_19 : V_18 ;
type |= V_12 ;
} else {
if ( V_152 -> V_146 < 470000000 )
V_2 -> V_106 . V_166 = 0 ;
else
V_2 -> V_106 . V_167 = 1 ;
type |= ( V_2 -> V_106 . V_166 && V_2 -> V_106 . V_167 ) ? V_19 : V_20 ;
type |= V_12 ;
}
if ( V_2 -> V_106 . V_158 ) {
V_158 = V_2 -> V_106 . V_158 ;
if ( type == V_26 || V_2 -> V_75 < 0x0302 )
V_158 += 200 ;
}
return F_33 ( V_61 , V_152 -> V_146 ,
V_145 , type , 0 , V_158 ) ;
}
static int F_36 ( struct V_60 * V_61 )
{
struct V_1 * V_2 = V_61 -> V_64 ;
int V_67 ;
V_67 = F_7 ( V_2 ) ;
if ( V_67 < 0 )
return V_67 ;
if ( V_168 || V_2 -> V_106 . V_169 )
return 0 ;
F_2 ( L_98 ) ;
if ( V_81 > 1 ) {
F_2 ( L_99 ) ;
F_37 () ;
}
F_30 ( & V_2 -> V_133 ) ;
if ( V_2 -> V_75 < 0x0202 )
V_67 = F_27 (priv, {0x00 , XREG_POWER_DOWN, 0x00 , 0x00}) ;
else
V_67 = F_27 (priv, {0x80 , XREG_POWER_DOWN, 0x00 , 0x00}) ;
V_2 -> V_47 = V_52 ;
F_31 ( & V_2 -> V_133 ) ;
return V_67 ;
}
static int F_38 ( struct V_60 * V_61 )
{
struct V_1 * V_2 = V_61 -> V_64 ;
F_2 ( L_39 , V_7 ) ;
F_30 ( & V_170 ) ;
if ( F_39 ( V_2 ) == 1 ) {
F_8 ( V_2 ) ;
F_9 ( V_2 -> V_106 . V_73 ) ;
V_2 -> V_106 . V_73 = NULL ;
}
if ( V_2 )
F_40 ( V_2 ) ;
F_31 ( & V_170 ) ;
V_61 -> V_64 = NULL ;
return 0 ;
}
static int F_41 ( struct V_60 * V_61 , T_7 * V_146 )
{
struct V_1 * V_2 = V_61 -> V_64 ;
int V_67 ;
F_2 ( L_39 , V_7 ) ;
V_67 = F_7 ( V_2 ) ;
if ( V_67 < 0 )
return V_67 ;
* V_146 = V_2 -> V_146 ;
return 0 ;
}
static void F_42 ( const struct V_62 * V_63 ,
void * V_171 )
{
struct V_60 * V_61 = V_171 ;
struct V_1 * V_2 = V_61 -> V_64 ;
int V_67 ;
F_2 ( L_100 , V_63 ? L_101 : L_102 ) ;
if ( ! V_63 ) {
F_11 ( L_103 , V_2 -> V_73 ) ;
V_2 -> V_47 = V_53 ;
return;
}
V_67 = F_10 ( V_61 , V_63 ) ;
F_43 ( V_63 ) ;
if ( V_67 < 0 )
return;
V_2 -> V_47 = V_52 ;
}
static int F_44 ( struct V_60 * V_61 , void * V_172 )
{
struct V_1 * V_2 = V_61 -> V_64 ;
struct V_173 * V_65 = V_172 ;
int V_67 = 0 ;
F_2 ( L_39 , V_7 ) ;
F_30 ( & V_2 -> V_133 ) ;
if ( V_2 -> V_106 . V_73 )
F_9 ( V_2 -> V_106 . V_73 ) ;
memcpy ( & V_2 -> V_106 , V_65 , sizeof( V_2 -> V_106 ) ) ;
if ( V_65 -> V_73 ) {
V_2 -> V_106 . V_73 = F_45 ( V_65 -> V_73 , V_76 ) ;
if ( V_2 -> V_106 . V_73 == NULL )
V_67 = - V_77 ;
}
if ( ! V_174 [ 0 ] && V_65 -> V_73 &&
V_2 -> V_73 && strcmp ( V_65 -> V_73 , V_2 -> V_73 ) )
F_8 ( V_2 ) ;
if ( V_2 -> V_106 . V_107 < 9 )
V_2 -> V_106 . V_107 = 13 ;
if ( V_2 -> V_47 == V_48 ) {
if ( ! V_174 [ 0 ] )
V_2 -> V_73 = V_2 -> V_106 . V_73 ;
else
V_2 -> V_73 = V_174 ;
V_67 = F_46 ( V_175 , 1 ,
V_2 -> V_73 ,
V_2 -> V_101 . V_102 -> V_176 . V_177 ,
V_76 ,
V_61 , F_42 ) ;
if ( V_67 < 0 ) {
F_11 ( L_104 ,
V_2 -> V_73 ) ;
V_2 -> V_47 = V_53 ;
} else
V_2 -> V_47 = V_49 ;
}
F_31 ( & V_2 -> V_133 ) ;
return V_67 ;
}
struct V_60 * F_47 ( struct V_60 * V_61 ,
struct V_178 * V_179 )
{
struct V_1 * V_2 ;
int V_180 ;
if ( V_81 )
F_5 ( V_181 L_105 ) ;
if ( NULL == V_179 )
return NULL ;
if ( ! V_61 ) {
F_5 ( V_182 L_106 ) ;
return NULL ;
}
F_30 ( & V_170 ) ;
V_180 = F_48 ( struct V_1 , V_2 ,
V_183 ,
V_179 -> V_184 , V_179 -> V_185 ,
L_107 ) ;
switch ( V_180 ) {
case 0 :
goto V_126;
break;
case 1 :
V_2 -> V_106 . V_107 = 13 ;
F_49 ( & V_2 -> V_133 ) ;
V_61 -> V_64 = V_2 ;
break;
case 2 :
V_61 -> V_64 = V_2 ;
break;
}
memcpy ( & V_61 -> V_186 . V_187 , & V_188 ,
sizeof( V_188 ) ) ;
F_13 ( L_108 , L_109 ) ;
if ( V_179 -> V_106 )
F_44 ( V_61 , V_179 -> V_106 ) ;
F_31 ( & V_170 ) ;
return V_61 ;
V_126:
F_31 ( & V_170 ) ;
F_38 ( V_61 ) ;
return NULL ;
}
