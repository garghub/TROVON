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
F_5 ( V_11 L_2 ) ;
if ( type & V_12 )
F_5 ( V_11 L_3 ) ;
if ( type & V_13 )
F_5 ( V_11 L_4 ) ;
if ( type & V_14 )
F_5 ( V_11 L_5 ) ;
if ( type & V_15 )
F_5 ( V_11 L_6 ) ;
if ( type & V_16 )
F_5 ( V_11 L_7 ) ;
if ( type & V_17 )
F_5 ( V_11 L_8 ) ;
if ( type & V_18 )
F_5 ( V_11 L_9 ) ;
if ( type & V_19 )
F_5 ( V_11 L_10 ) ;
if ( type & V_20 )
F_5 ( V_11 L_11 ) ;
if ( type & V_21 )
F_5 ( V_11 L_12 ) ;
if ( type & V_22 )
F_5 ( V_11 L_13 ) ;
if ( type & V_23 )
F_5 ( V_11 L_14 ) ;
if ( type & V_24 )
F_5 ( V_11 L_15 ) ;
if ( type & V_25 )
F_5 ( V_11 L_16 ) ;
if ( type & V_26 )
F_5 ( V_11 L_17 ) ;
if ( type & V_27 )
F_5 ( V_11 L_18 ) ;
if ( type & IF )
F_5 ( V_11 L_19 ) ;
if ( type & V_28 )
F_5 ( V_11 L_20 ) ;
if ( type & V_29 )
F_5 ( V_11 L_21 ) ;
if ( type & V_30 )
F_5 ( V_11 L_22 ) ;
if ( type & V_31 )
F_5 ( V_11 L_23 ) ;
if ( type & V_32 )
F_5 ( V_11 L_24 ) ;
if ( type & V_33 )
F_5 ( V_11 L_25 ) ;
if ( type & V_34 )
F_5 ( V_11 L_26 ) ;
if ( type & V_35 )
F_5 ( V_11 L_27 ) ;
if ( type & V_36 )
F_5 ( V_11 L_28 ) ;
if ( type & V_37 )
F_5 ( V_11 L_29 ) ;
if ( type & V_38 )
F_5 ( V_11 L_30 ) ;
if ( type & V_39 )
F_5 ( V_11 L_31 ) ;
if ( type & V_40 )
F_5 ( V_11 L_32 , V_9 ) ;
}
static T_2 F_6 ( void )
{
if ( strcasecmp ( V_41 , L_33 ) == 0 )
return V_42 ;
if ( strcasecmp ( V_41 , L_34 ) == 0 )
return V_43 ;
if ( strcasecmp ( V_41 , L_35 ) == 0 )
return V_44 ;
if ( strcasecmp ( V_41 , L_36 ) == 0 )
return V_45 ;
if ( strcasecmp ( V_41 , L_37 ) == 0 )
return V_46 ;
if ( strcasecmp ( V_41 , L_38 ) == 0 )
return V_47 ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_48 ) {
case V_49 :
case V_50 :
return - V_51 ;
case V_52 :
return 1 ;
case V_53 :
return 0 ;
case V_54 :
return - V_55 ;
}
return 0 ;
}
static void F_8 ( struct V_1 * V_2 )
{
int V_56 ;
F_2 ( L_39 , V_7 ) ;
if ( V_2 -> V_57 != V_58 )
F_9 ( V_2 -> V_57 ) ;
V_2 -> V_57 = NULL ;
V_2 -> V_48 = V_49 ;
memset ( & V_2 -> V_59 , 0 , sizeof( V_2 -> V_59 ) ) ;
if ( ! V_2 -> V_60 )
return;
for ( V_56 = 0 ; V_56 < V_2 -> V_61 ; V_56 ++ )
F_9 ( V_2 -> V_60 [ V_56 ] . V_62 ) ;
F_9 ( V_2 -> V_60 ) ;
V_2 -> V_60 = NULL ;
V_2 -> V_61 = 0 ;
}
static int F_10 ( struct V_63 * V_64 ,
const struct V_65 * V_66 )
{
struct V_1 * V_2 = V_64 -> V_67 ;
const unsigned char * V_68 , * V_69 ;
int V_70 = 0 ;
int V_71 , V_72 ;
char V_73 [ 33 ] ;
F_2 ( L_39 , V_7 ) ;
V_68 = V_66 -> V_74 ;
V_69 = V_68 + V_66 -> V_75 ;
if ( V_66 -> V_75 < sizeof( V_73 ) - 1 + 2 + 2 ) {
F_11 ( L_40 ,
V_2 -> V_57 ) ;
goto V_76;
}
memcpy ( V_73 , V_68 , sizeof( V_73 ) - 1 ) ;
V_73 [ sizeof( V_73 ) - 1 ] = 0 ;
V_68 += sizeof( V_73 ) - 1 ;
V_2 -> V_77 = F_12 ( V_68 ) ;
V_68 += 2 ;
V_72 = F_12 ( V_68 ) ;
V_68 += 2 ;
F_13 ( L_41 ,
V_72 , V_2 -> V_57 , V_73 ,
V_2 -> V_77 >> 8 , V_2 -> V_77 & 0xff ) ;
V_2 -> V_60 = F_14 ( V_72 , sizeof( * V_2 -> V_60 ) , V_78 ) ;
if ( V_2 -> V_60 == NULL ) {
F_11 ( L_42 ) ;
V_70 = - V_79 ;
goto V_80;
}
V_2 -> V_61 = V_72 ;
V_71 = - 1 ;
while ( V_68 < V_69 ) {
T_3 type , V_75 ;
T_2 V_81 ;
T_4 V_9 = 0 ;
V_71 ++ ;
if ( V_71 >= V_72 ) {
F_11 ( L_43 ) ;
goto V_76;
}
if ( V_69 - V_68 < sizeof( type ) + sizeof( V_81 ) + sizeof( V_75 ) )
goto V_82;
type = F_15 ( V_68 ) ;
V_68 += sizeof( type ) ;
V_81 = F_16 ( V_68 ) ;
V_68 += sizeof( V_81 ) ;
if ( type & V_40 ) {
V_9 = F_12 ( V_68 ) ;
V_68 += sizeof( V_9 ) ;
if ( V_69 - V_68 < sizeof( V_75 ) )
goto V_82;
}
V_75 = F_15 ( V_68 ) ;
V_68 += sizeof( V_75 ) ;
if ( ! V_75 || V_75 > V_69 - V_68 ) {
F_11 ( L_44 ) ;
F_17 ( type ) ;
F_5 ( V_11
L_45 ,
type , ( unsigned long long ) V_81 ,
( unsigned ) ( V_69 - V_68 ) , V_75 ) ;
goto V_76;
}
V_2 -> V_60 [ V_71 ] . V_62 = F_18 ( V_75 , V_78 ) ;
if ( V_2 -> V_60 [ V_71 ] . V_62 == NULL ) {
F_11 ( L_42 ) ;
V_70 = - V_79 ;
goto V_80;
}
F_2 ( L_46 ) ;
if ( V_83 ) {
F_4 ( type , V_9 ) ;
F_5 ( V_11 L_47 ,
type , ( unsigned long long ) V_81 , V_75 ) ;
}
memcpy ( V_2 -> V_60 [ V_71 ] . V_62 , V_68 , V_75 ) ;
V_2 -> V_60 [ V_71 ] . type = type ;
V_2 -> V_60 [ V_71 ] . V_81 = V_81 ;
V_2 -> V_60 [ V_71 ] . V_75 = V_75 ;
V_2 -> V_60 [ V_71 ] . V_9 = V_9 ;
V_68 += V_75 ;
}
if ( V_71 + 1 != V_2 -> V_61 ) {
F_11 ( L_48 ) ;
goto V_76;
}
goto V_84;
V_82:
F_11 ( L_49 ) ;
V_76:
V_70 = - V_85 ;
F_11 ( L_50 ) ;
V_80:
F_13 ( L_51 ) ;
F_8 ( V_2 ) ;
V_84:
if ( V_70 == 0 )
F_2 ( L_52 ) ;
else
V_2 -> V_48 = V_54 ;
return V_70 ;
}
static int F_19 ( struct V_63 * V_64 , unsigned int type ,
T_2 * V_81 )
{
struct V_1 * V_2 = V_64 -> V_67 ;
int V_56 , V_86 = - 1 , V_87 = 0 ;
unsigned int V_88 = 0 ;
F_2 ( L_53 , V_7 ) ;
if ( V_83 ) {
F_17 ( type ) ;
F_5 ( V_11 L_54 ,
type , ( unsigned long long ) * V_81 ) ;
}
if ( ! V_2 -> V_60 ) {
F_11 ( L_55 ) ;
return - V_85 ;
}
if ( ( ( type & ~ V_39 ) == 0 ) && ( * V_81 == 0 ) )
* V_81 = V_89 ;
if ( type & V_10 )
V_88 = V_90 ;
else if ( type & V_39 ) {
type &= V_91 ;
V_88 = V_91 & ~ V_40 ;
} else if ( type & V_92 )
V_88 = V_92 ;
else if ( type & V_93 )
V_88 = V_93 ;
type &= V_88 ;
if ( ! ( type & V_39 ) )
V_88 = ~ 0 ;
for ( V_56 = 0 ; V_56 < V_2 -> V_61 ; V_56 ++ ) {
if ( ( type == ( V_2 -> V_60 [ V_56 ] . type & V_88 ) ) &&
( * V_81 == V_2 -> V_60 [ V_56 ] . V_81 ) )
goto V_94;
}
for ( V_56 = 0 ; V_56 < V_2 -> V_61 ; V_56 ++ ) {
T_2 V_95 ;
int V_96 ;
if ( type != ( V_2 -> V_60 [ V_56 ] . type & V_88 ) )
continue;
V_95 = * V_81 & V_2 -> V_60 [ V_56 ] . V_81 ;
if ( ! V_95 )
continue;
if ( ( * V_81 & V_95 ) == * V_81 )
goto V_94;
V_96 = F_20 ( V_95 ) ;
if ( V_96 > V_87 ) {
V_87 = V_96 ;
V_86 = V_56 ;
}
}
if ( V_87 > 0 ) {
F_2 ( L_56 ,
V_87 ) ;
F_17 ( type ) ;
F_5 ( V_11
L_57 , type , ( unsigned long long ) * V_81 ) ;
V_56 = V_86 ;
goto V_94;
}
V_56 = - V_97 ;
goto V_98;
V_94:
* V_81 = V_2 -> V_60 [ V_56 ] . V_81 ;
V_98:
F_2 ( L_58 , ( V_56 < 0 ) ? L_59 : L_60 ) ;
if ( V_83 ) {
F_17 ( type ) ;
F_5 ( V_11 L_54 ,
type , ( unsigned long long ) * V_81 ) ;
}
return V_56 ;
}
static inline int F_21 ( struct V_63 * V_64 , int V_99 , int V_100 )
{
struct V_1 * V_2 = V_64 -> V_67 ;
return ( ! V_64 -> V_101 ) ? - V_85 :
V_64 -> V_101 ( ( ( V_64 -> V_102 ) && ( V_64 -> V_102 -> V_2 ) ) ?
V_64 -> V_102 -> V_2 : V_2 -> V_103 . V_104 -> V_105 ,
V_106 , V_99 , V_100 ) ;
}
static int F_22 ( struct V_63 * V_64 , unsigned int type ,
T_2 * V_81 )
{
struct V_1 * V_2 = V_64 -> V_67 ;
int V_107 , V_70 ;
unsigned char * V_68 , * V_69 , V_5 [ V_108 ] ;
if ( V_2 -> V_109 . V_110 > sizeof( V_5 ) )
V_2 -> V_109 . V_110 = sizeof( V_5 ) ;
F_2 ( L_39 , V_7 ) ;
V_107 = F_19 ( V_64 , type , V_81 ) ;
if ( V_107 < 0 )
return V_107 ;
F_13 ( L_61 ) ;
F_17 ( V_2 -> V_60 [ V_107 ] . type ) ;
F_5 ( V_11 L_54 ,
V_2 -> V_60 [ V_107 ] . type , ( unsigned long long ) * V_81 ) ;
V_68 = V_2 -> V_60 [ V_107 ] . V_62 ;
V_69 = V_68 + V_2 -> V_60 [ V_107 ] . V_75 ;
while ( V_68 < V_69 ) {
T_4 V_75 ;
if ( V_68 + sizeof( V_75 ) > V_69 ) {
F_11 ( L_62 ) ;
return - V_85 ;
}
V_75 = F_23 ( * ( V_111 * ) V_68 ) ;
V_68 += sizeof( V_75 ) ;
if ( V_75 == 0xffff )
return 0 ;
if ( ! V_75 ) {
V_70 = F_21 ( V_64 , V_112 , 0 ) ;
if ( V_70 < 0 ) {
F_11 ( L_63 ,
( * V_68 ) & 0x7f ) ;
return - V_85 ;
}
continue;
}
if ( V_75 >= 0xff00 ) {
switch ( V_75 ) {
case 0xff00 :
V_70 = F_21 ( V_64 , V_113 , 0 ) ;
if ( V_70 < 0 ) {
F_11 ( L_63 ,
( * V_68 ) & 0x7f ) ;
return - V_85 ;
}
break;
default:
F_13 ( L_64 ,
V_75 & 0x7f ) ;
return - V_85 ;
}
continue;
}
if ( V_75 & 0x8000 ) {
F_24 ( V_75 & 0x7fff ) ;
continue;
}
if ( ( V_75 + V_68 > V_69 ) ) {
F_11 ( L_65 ,
V_75 , ( int ) ( V_69 - V_68 ) ) ;
return - V_85 ;
}
V_5 [ 0 ] = * V_68 ;
V_68 ++ ;
V_75 -- ;
while ( V_75 > 0 ) {
int V_114 = ( V_75 < V_2 -> V_109 . V_110 - 1 ) ?
V_75 : V_2 -> V_109 . V_110 - 1 ;
memcpy ( V_5 + 1 , V_68 , V_114 ) ;
V_70 = F_25 ( V_2 , V_5 , V_114 + 1 ) ;
if ( V_70 < 0 ) {
F_11 ( L_66 , V_70 ) ;
return - V_85 ;
}
V_68 += V_114 ;
V_75 -= V_114 ;
}
V_70 = F_21 ( V_64 , V_115 , 0 ) ;
if ( ( V_70 < 0 ) && ( V_70 != - V_85 ) ) {
F_11 ( L_67 , V_70 ) ;
return V_70 ;
}
}
return 0 ;
}
static int F_26 ( struct V_63 * V_64 , unsigned int type ,
T_2 * V_81 , T_4 V_9 , int V_116 )
{
struct V_1 * V_2 = V_64 -> V_67 ;
int V_107 , V_70 ;
unsigned char * V_68 ;
F_2 ( L_39 , V_7 ) ;
if ( ! V_9 ) {
V_107 = F_19 ( V_64 , type , V_81 ) ;
if ( V_107 < 0 )
return V_107 ;
} else {
for ( V_107 = 0 ; V_107 < V_2 -> V_61 ; V_107 ++ ) {
if ( ( V_2 -> V_60 [ V_107 ] . V_9 == V_9 ) &&
( V_2 -> V_60 [ V_107 ] . type & V_40 ) )
break;
}
if ( V_107 == V_2 -> V_61 )
return - V_97 ;
}
V_68 = V_2 -> V_60 [ V_107 ] . V_62 ;
if ( V_2 -> V_60 [ V_107 ] . type & V_40 ) {
if ( V_2 -> V_60 [ V_107 ] . V_75 != 12 * 16 || V_116 >= 16 )
return - V_85 ;
V_68 += 12 * V_116 ;
} else {
if ( V_2 -> V_60 [ V_107 ] . V_75 != 14 * 16 || V_116 >= 16 ||
F_23 ( * ( V_111 * ) ( V_68 + 14 * V_116 ) ) != 12 )
return - V_85 ;
V_68 += 14 * V_116 + 2 ;
}
F_13 ( L_68 ) ;
F_4 ( V_2 -> V_60 [ V_107 ] . type ,
V_2 -> V_60 [ V_107 ] . V_9 ) ;
F_5 ( V_11 L_54 , V_2 -> V_60 [ V_107 ] . type ,
( unsigned long long ) * V_81 ) ;
if ( V_2 -> V_77 < 0x0202 )
V_70 = F_27 (priv, {0x20 , 0x00 , 0x00 , 0x00}) ;
else
V_70 = F_27 (priv, {0xa0 , 0x00 , 0x00 , 0x00}) ;
if ( V_70 < 0 )
return - V_8 ;
V_70 = F_25 ( V_2 , V_68 , 12 ) ;
if ( V_70 < 0 )
return - V_8 ;
V_70 = F_27 (priv, {0x00 , 0x8c}) ;
if ( V_70 < 0 )
return - V_8 ;
return 0 ;
}
static int F_28 ( struct V_63 * V_64 , unsigned int type ,
T_2 V_117 , T_4 V_9 )
{
struct V_1 * V_2 = V_64 -> V_67 ;
struct V_118 V_119 ;
int V_70 , V_120 = 0 ;
T_1 V_121 , V_122 ;
T_2 V_123 ;
F_2 ( L_39 , V_7 ) ;
V_70 = F_7 ( V_2 ) ;
if ( V_70 < 0 )
return V_70 ;
if ( V_2 -> V_109 . V_124 && ! ( type & V_22 ) )
type |= V_14 ;
V_125:
V_119 . type = type ;
V_119 . V_81 = V_117 ;
V_119 . V_126 = V_117 ;
V_119 . V_127 = V_39 | V_2 -> V_109 . V_127 ;
V_119 . V_128 = 0 ;
V_119 . V_9 = V_9 ;
F_2 ( L_69 ) ;
if ( V_83 ) {
F_17 ( V_119 . type ) ;
F_5 ( V_11 L_70 , V_119 . type ,
( unsigned long long ) V_119 . V_126 ) ;
if ( ! V_9 ) {
F_5 ( V_11 L_71 ) ;
F_17 ( V_2 -> V_109 . V_127 ) ;
F_5 ( V_11 L_72 , V_2 -> V_109 . V_127 ) ;
} else
F_5 ( V_11 L_73 , V_119 . V_9 ) ;
F_5 ( V_11 L_74 , V_119 . V_128 ) ;
}
if ( ( V_2 -> V_48 == V_52 ) &&
( ( ( V_10 | V_119 . type ) & V_90 ) ==
( V_2 -> V_59 . type & V_90 ) ) ) {
F_2 ( L_75 ) ;
goto V_129;
}
memset ( & V_2 -> V_59 , 0 , sizeof( V_2 -> V_59 ) ) ;
V_70 = F_21 ( V_64 , V_112 , 0 ) ;
if ( V_70 < 0 )
goto V_130;
V_123 = 0 ;
V_70 = F_22 ( V_64 , V_10 | V_119 . type , & V_123 ) ;
if ( V_70 < 0 ) {
F_11 ( L_76 ,
V_70 ) ;
goto V_130;
}
F_2 ( L_77 ) ;
V_70 = F_22 ( V_64 , V_10 | V_12 | V_119 . type , & V_123 ) ;
if ( V_70 == - V_97 )
V_70 = F_22 ( V_64 , ( V_10 | V_12 | V_119 . type ) & ~ V_13 ,
& V_123 ) ;
if ( V_70 < 0 && V_70 != - V_97 ) {
F_11 ( L_78 ,
V_70 ) ;
goto V_130;
}
V_129:
if ( V_2 -> V_59 . type == ( V_10 | V_119 . type ) &&
V_2 -> V_59 . V_126 == V_117 ) {
F_2 ( L_79 ) ;
goto V_131;
}
V_2 -> V_59 . V_127 = 0 ;
V_70 = F_22 ( V_64 , V_119 . type , & V_119 . V_81 ) ;
if ( V_70 == - V_97 )
V_70 = F_22 ( V_64 , V_119 . type & ~ V_13 , & V_119 . V_81 ) ;
if ( V_70 < 0 )
goto V_130;
V_131:
if ( V_2 -> V_59 . V_127 == V_119 . V_127 &&
V_2 -> V_59 . V_128 == V_119 . V_128 ) {
F_2 ( L_80 ) ;
goto V_132;
}
if ( V_119 . type & V_22 )
goto V_132;
F_2 ( L_81 , V_119 . V_128 ) ;
V_70 = F_26 ( V_64 , V_119 . type | V_119 . V_127 , & V_119 . V_81 ,
V_119 . V_9 , V_119 . V_128 ) ;
V_132:
if ( F_1 ( V_2 , 0x0004 , & V_121 ) < 0 ||
F_1 ( V_2 , 0x0008 , & V_122 ) < 0 ) {
F_11 ( L_82 ) ;
goto V_130;
}
F_2 ( L_83 ,
V_122 , ( V_121 & 0xf000 ) >> 12 , ( V_121 & 0xf00 ) >> 8 ,
( V_121 & 0xf0 ) >> 4 , V_121 & 0xf ) ;
if ( V_2 -> V_109 . V_133 )
goto V_133;
if ( V_2 -> V_77 != ( ( V_121 & 0xf0 ) << 4 | ( V_121 & 0x0f ) ) ) {
if ( ! V_2 -> V_109 . V_133 ) {
F_11 ( L_84 ) ;
goto V_130;
} else {
F_11 ( L_85 ) ;
V_122 = 3028 ;
}
}
if ( V_2 -> V_122 == 0 && ( V_122 == 2028 || V_122 == 3028 ) ) {
V_2 -> V_122 = V_122 ;
V_2 -> V_134 = V_121 & 0xff00 ;
} else if ( V_2 -> V_122 == 0 || V_2 -> V_122 != V_122 ||
V_2 -> V_134 != ( V_121 & 0xff00 ) ) {
F_11 ( L_86 ) ;
goto V_130;
}
V_133:
V_2 -> V_59 = V_119 ;
V_2 -> V_59 . type |= V_10 ;
V_2 -> V_48 = V_52 ;
return 0 ;
V_130:
F_8 ( V_2 ) ;
if ( V_120 < 8 ) {
F_24 ( 50 ) ;
V_120 ++ ;
F_2 ( L_87 ) ;
goto V_125;
}
F_29 ( V_64 ) ;
if ( V_70 == - V_97 )
V_70 = - V_85 ;
return V_70 ;
}
static int F_30 ( struct V_63 * V_64 , T_1 * V_135 )
{
struct V_1 * V_2 = V_64 -> V_67 ;
T_1 V_136 , signal = 0 ;
int V_70 , V_56 ;
F_2 ( L_39 , V_7 ) ;
V_70 = F_7 ( V_2 ) ;
if ( V_70 < 0 )
return V_70 ;
if ( ! V_70 ) {
* V_135 = 0 ;
return 0 ;
}
F_31 ( & V_2 -> V_137 ) ;
for ( V_56 = 0 ; V_56 < 3 ; V_56 ++ ) {
V_70 = F_1 ( V_2 , V_138 , & V_136 ) ;
if ( V_70 < 0 )
goto V_98;
if ( V_136 )
break;
F_24 ( 6 ) ;
}
if ( V_136 == 2 )
goto V_98;
V_70 = F_1 ( V_2 , V_139 , & signal ) ;
if ( V_70 < 0 )
goto V_98;
signal = ( ( 1 << 12 ) - 1 ) | ( ( signal & 0x07 ) << 12 ) ;
V_98:
F_32 ( & V_2 -> V_137 ) ;
* V_135 = signal ;
F_2 ( L_88 , signal ) ;
return V_70 ;
}
static int F_33 ( struct V_63 * V_64 , T_5 * V_140 )
{
struct V_1 * V_2 = V_64 -> V_67 ;
int V_56 , V_70 ;
T_1 V_136 = 0 ;
T_6 V_141 = 0 ;
V_70 = F_7 ( V_2 ) ;
if ( V_70 < 0 )
return V_70 ;
if ( ! V_70 ) {
* V_140 = 0 ;
return 0 ;
}
F_31 ( & V_2 -> V_137 ) ;
for ( V_56 = 0 ; V_56 < 3 ; V_56 ++ ) {
V_70 = F_1 ( V_2 , V_138 , & V_136 ) ;
if ( V_70 < 0 )
goto V_98;
if ( V_136 )
break;
F_24 ( 6 ) ;
}
if ( V_136 == 2 )
goto V_98;
V_70 = F_1 ( V_2 , V_142 , & V_141 ) ;
if ( V_70 < 0 )
goto V_98;
* V_140 = V_141 * 15625 ;
F_2 ( L_89 , * V_140 ) ;
V_98:
F_32 ( & V_2 -> V_137 ) ;
return V_70 ;
}
static int F_34 ( struct V_63 * V_64 , T_7 V_143 ,
enum V_144 V_145 ,
unsigned int type ,
T_2 V_117 ,
T_1 V_9 )
{
struct V_1 * V_2 = V_64 -> V_67 ;
int V_70 = - V_85 ;
unsigned char V_5 [ 4 ] ;
T_7 div , V_146 = 0 ;
F_2 ( L_39 , V_7 ) ;
F_31 ( & V_2 -> V_137 ) ;
F_2 ( L_90 , V_143 / 1000 ) ;
if ( F_28 ( V_64 , type , V_117 , V_9 ) < 0 )
goto V_98;
switch ( V_145 ) {
case V_147 :
V_70 = F_27 (priv, {0x00 , 0x00}) ;
break;
case V_148 :
break;
case V_149 :
if ( V_2 -> V_59 . type & V_17 )
V_146 = 1750000 ;
else
V_146 = 2750000 ;
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
F_11 ( L_91 , V_145 ) ;
break;
}
div = ( V_143 - V_146 + DIV / 2 ) / DIV ;
if ( V_2 -> V_77 < 0x0202 )
V_70 = F_27 (priv, {0x00 , XREG_RF_FREQ, 0x00 , 0x00}) ;
else
V_70 = F_27 (priv, {0x80 , XREG_RF_FREQ, 0x00 , 0x00}) ;
if ( V_70 < 0 )
goto V_98;
if ( V_2 -> V_109 . F_24 )
F_24 ( V_2 -> V_109 . F_24 ) ;
F_21 ( V_64 , V_113 , 1 ) ;
F_24 ( 10 ) ;
V_5 [ 0 ] = 0xff & ( div >> 24 ) ;
V_5 [ 1 ] = 0xff & ( div >> 16 ) ;
V_5 [ 2 ] = 0xff & ( div >> 8 ) ;
V_5 [ 3 ] = 0xff & ( div ) ;
V_70 = F_25 ( V_2 , V_5 , sizeof( V_5 ) ) ;
if ( V_70 < 0 )
goto V_98;
F_24 ( 100 ) ;
V_2 -> V_150 = V_143 ;
F_2 ( L_92 , 4 , V_5 ,
V_143 / 1000000 , ( V_143 % 1000000 ) / 1000 ) ;
V_70 = 0 ;
V_98:
F_32 ( & V_2 -> V_137 ) ;
return V_70 ;
}
static int F_35 ( struct V_63 * V_64 ,
struct V_151 * V_68 )
{
struct V_1 * V_2 = V_64 -> V_67 ;
unsigned int type = 0 ;
F_2 ( L_39 , V_7 ) ;
if ( V_68 -> V_152 == V_148 ) {
type |= V_22 ;
if ( V_2 -> V_109 . V_153 )
type |= V_23 ;
return F_34 ( V_64 , ( 625l * V_68 -> V_150 ) / 10 ,
V_148 , type , 0 , 0 ) ;
}
if ( ! V_68 -> V_117 )
V_68 -> V_117 = V_154 ;
if ( ! ( V_68 -> V_117 & V_154 ) )
type |= V_13 ;
V_68 -> V_117 |= F_6 () ;
return F_34 ( V_64 , 62500l * V_68 -> V_150 ,
V_147 , type , V_68 -> V_117 , 0 ) ;
}
static int F_36 ( struct V_63 * V_64 )
{
struct V_155 * V_156 = & V_64 -> V_157 ;
T_7 V_158 = V_156 -> V_159 ;
T_7 V_160 = V_156 -> V_161 ;
struct V_1 * V_2 = V_64 -> V_67 ;
int V_70 ;
unsigned int type = 0 ;
T_1 V_162 = 0 ;
F_2 ( L_39 , V_7 ) ;
V_70 = F_7 ( V_2 ) ;
if ( V_70 < 0 )
return V_70 ;
switch ( V_158 ) {
case V_163 :
case V_164 :
if ( V_160 <= 6000000 )
type |= V_18 ;
switch ( V_2 -> V_109 . type ) {
case V_165 :
type |= V_16 ;
break;
case V_166 :
type |= V_15 ;
break;
case V_167 :
default:
if ( V_2 -> V_109 . V_162 == V_168 )
type |= V_16 ;
else
type |= V_15 ;
}
break;
case V_169 :
type |= V_27 | V_16 ;
break;
default:
return - V_85 ;
}
if ( V_160 <= 6000000 ) {
type |= V_17 ;
V_2 -> V_109 . V_170 = 0 ;
V_2 -> V_109 . V_171 = 0 ;
} else if ( V_160 <= 7000000 ) {
if ( V_156 -> V_150 < 470000000 )
V_2 -> V_109 . V_170 = 1 ;
else
V_2 -> V_109 . V_171 = 0 ;
type |= ( V_2 -> V_109 . V_170 && V_2 -> V_109 . V_171 ) ? V_20 : V_19 ;
type |= V_13 ;
} else {
if ( V_156 -> V_150 < 470000000 )
V_2 -> V_109 . V_170 = 0 ;
else
V_2 -> V_109 . V_171 = 1 ;
type |= ( V_2 -> V_109 . V_170 && V_2 -> V_109 . V_171 ) ? V_20 : V_21 ;
type |= V_13 ;
}
if ( V_2 -> V_109 . V_162 ) {
V_162 = V_2 -> V_109 . V_162 ;
if ( type == V_27 || V_2 -> V_77 < 0x0302 )
V_162 += 200 ;
}
return F_34 ( V_64 , V_156 -> V_150 ,
V_149 , type , 0 , V_162 ) ;
}
static int F_29 ( struct V_63 * V_64 )
{
struct V_1 * V_2 = V_64 -> V_67 ;
int V_70 ;
V_70 = F_7 ( V_2 ) ;
if ( V_70 < 0 )
return V_70 ;
if ( ! V_70 )
return 0 ;
if ( V_172 || V_2 -> V_109 . V_173 )
return 0 ;
F_2 ( L_93 ) ;
if ( V_83 > 1 ) {
F_2 ( L_94 ) ;
F_37 () ;
}
F_31 ( & V_2 -> V_137 ) ;
if ( V_2 -> V_77 < 0x0202 )
V_70 = F_27 (priv, {0x00 , XREG_POWER_DOWN, 0x00 , 0x00}) ;
else
V_70 = F_27 (priv, {0x80 , XREG_POWER_DOWN, 0x00 , 0x00}) ;
if ( V_70 >= 0 )
V_2 -> V_48 = V_53 ;
F_32 ( & V_2 -> V_137 ) ;
return V_70 ;
}
static void F_38 ( struct V_63 * V_64 )
{
struct V_1 * V_2 = V_64 -> V_67 ;
F_2 ( L_39 , V_7 ) ;
F_31 ( & V_174 ) ;
if ( F_39 ( V_2 ) == 1 )
F_8 ( V_2 ) ;
if ( V_2 )
F_40 ( V_2 ) ;
F_32 ( & V_174 ) ;
V_64 -> V_67 = NULL ;
}
static int F_41 ( struct V_63 * V_64 , T_7 * V_150 )
{
struct V_1 * V_2 = V_64 -> V_67 ;
int V_70 ;
F_2 ( L_39 , V_7 ) ;
V_70 = F_7 ( V_2 ) ;
if ( V_70 < 0 )
return V_70 ;
* V_150 = V_2 -> V_150 ;
return 0 ;
}
static void F_42 ( const struct V_65 * V_66 ,
void * V_175 )
{
struct V_63 * V_64 = V_175 ;
struct V_1 * V_2 = V_64 -> V_67 ;
int V_70 ;
F_2 ( L_95 , V_66 ? L_96 : L_97 ) ;
if ( ! V_66 ) {
F_11 ( L_98 , V_2 -> V_57 ) ;
V_2 -> V_48 = V_54 ;
return;
}
V_70 = F_10 ( V_64 , V_66 ) ;
F_43 ( V_66 ) ;
if ( V_70 < 0 )
return;
V_2 -> V_48 = V_52 ;
}
static int F_44 ( struct V_63 * V_64 , void * V_176 )
{
struct V_1 * V_2 = V_64 -> V_67 ;
struct V_177 * V_68 = V_176 ;
int V_70 = 0 ;
F_2 ( L_39 , V_7 ) ;
F_31 ( & V_2 -> V_137 ) ;
memcpy ( & V_2 -> V_109 , V_68 , sizeof( V_2 -> V_109 ) ) ;
if ( ! V_58 [ 0 ] && V_68 -> V_57 &&
V_2 -> V_57 && strcmp ( V_68 -> V_57 , V_2 -> V_57 ) )
F_8 ( V_2 ) ;
if ( V_2 -> V_109 . V_110 < 9 )
V_2 -> V_109 . V_110 = 13 ;
if ( V_2 -> V_48 == V_49 ) {
if ( ! V_58 [ 0 ] )
V_2 -> V_57 = F_45 ( V_68 -> V_57 , V_78 ) ;
else
V_2 -> V_57 = V_58 ;
if ( ! V_2 -> V_57 ) {
V_70 = - V_79 ;
goto V_178;
}
V_70 = F_46 ( V_179 , 1 ,
V_2 -> V_57 ,
V_2 -> V_103 . V_104 -> V_180 . V_181 ,
V_78 ,
V_64 , F_42 ) ;
if ( V_70 < 0 ) {
F_11 ( L_99 ,
V_2 -> V_57 ) ;
V_2 -> V_48 = V_54 ;
} else
V_2 -> V_48 = V_50 ;
}
V_178:
F_32 ( & V_2 -> V_137 ) ;
return V_70 ;
}
struct V_63 * F_47 ( struct V_63 * V_64 ,
struct V_182 * V_183 )
{
struct V_1 * V_2 ;
int V_184 ;
if ( V_83 )
F_5 ( V_185 L_100 ) ;
if ( NULL == V_183 )
return NULL ;
if ( ! V_64 ) {
F_5 ( V_186 L_101 ) ;
return NULL ;
}
F_31 ( & V_174 ) ;
V_184 = F_48 ( struct V_1 , V_2 ,
V_187 ,
V_183 -> V_188 , V_183 -> V_189 ,
L_102 ) ;
switch ( V_184 ) {
case 0 :
goto V_130;
case 1 :
V_2 -> V_109 . V_110 = 13 ;
F_49 ( & V_2 -> V_137 ) ;
V_64 -> V_67 = V_2 ;
break;
case 2 :
V_64 -> V_67 = V_2 ;
break;
}
memcpy ( & V_64 -> V_190 . V_191 , & V_192 ,
sizeof( V_192 ) ) ;
F_13 ( L_103 , L_104 ) ;
if ( V_183 -> V_109 )
F_44 ( V_64 , V_183 -> V_109 ) ;
F_32 ( & V_174 ) ;
return V_64 ;
V_130:
F_32 ( & V_174 ) ;
F_38 ( V_64 ) ;
return NULL ;
}
