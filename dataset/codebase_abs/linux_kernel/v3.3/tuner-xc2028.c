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
static void F_7 ( struct V_1 * V_2 )
{
int V_47 ;
F_2 ( L_39 , V_7 ) ;
if ( ! V_2 -> V_48 )
return;
for ( V_47 = 0 ; V_47 < V_2 -> V_49 ; V_47 ++ )
F_8 ( V_2 -> V_48 [ V_47 ] . V_50 ) ;
F_8 ( V_2 -> V_48 ) ;
V_2 -> V_48 = NULL ;
V_2 -> V_49 = 0 ;
memset ( & V_2 -> V_51 , 0 , sizeof( V_2 -> V_51 ) ) ;
}
static int F_9 ( struct V_52 * V_53 )
{
struct V_1 * V_2 = V_53 -> V_54 ;
const struct V_55 * V_56 = NULL ;
const unsigned char * V_57 , * V_58 ;
int V_59 = 0 ;
int V_60 , V_61 ;
char V_62 [ 33 ] ;
char * V_63 ;
F_2 ( L_39 , V_7 ) ;
if ( ! V_64 [ 0 ] )
V_63 = V_2 -> V_65 . V_63 ;
else
V_63 = V_64 ;
F_2 ( L_40 , V_63 ) ;
V_59 = F_10 ( & V_56 , V_63 , V_2 -> V_66 . V_67 -> V_68 . V_69 ) ;
if ( V_59 < 0 ) {
if ( V_59 == - V_70 )
F_11 ( L_41 ,
V_63 ) ;
else
F_11 ( L_42 ,
V_59 , V_63 ) ;
return V_59 ;
}
V_57 = V_56 -> V_71 ;
V_58 = V_57 + V_56 -> V_72 ;
if ( V_56 -> V_72 < sizeof( V_62 ) - 1 + 2 + 2 ) {
F_11 ( L_43 ,
V_63 ) ;
goto V_73;
}
memcpy ( V_62 , V_57 , sizeof( V_62 ) - 1 ) ;
V_62 [ sizeof( V_62 ) - 1 ] = 0 ;
V_57 += sizeof( V_62 ) - 1 ;
V_2 -> V_74 = F_12 ( V_57 ) ;
V_57 += 2 ;
V_61 = F_12 ( V_57 ) ;
V_57 += 2 ;
F_13 ( L_44 ,
V_61 , V_63 , V_62 ,
V_2 -> V_74 >> 8 , V_2 -> V_74 & 0xff ) ;
V_2 -> V_48 = F_14 ( V_61 , sizeof( * V_2 -> V_48 ) , V_75 ) ;
if ( V_2 -> V_48 == NULL ) {
F_11 ( L_45 ) ;
V_59 = - V_76 ;
goto V_77;
}
V_2 -> V_49 = V_61 ;
V_60 = - 1 ;
while ( V_57 < V_58 ) {
T_3 type , V_72 ;
T_2 V_78 ;
T_4 V_9 = 0 ;
V_60 ++ ;
if ( V_60 >= V_61 ) {
F_11 ( L_46
L_47 ) ;
goto V_73;
}
if ( V_58 - V_57 < sizeof( type ) + sizeof( V_78 ) + sizeof( V_72 ) )
goto V_79;
type = F_15 ( V_57 ) ;
V_57 += sizeof( type ) ;
V_78 = F_16 ( V_57 ) ;
V_57 += sizeof( V_78 ) ;
if ( type & V_39 ) {
V_9 = F_12 ( V_57 ) ;
V_57 += sizeof( V_9 ) ;
if ( V_58 - V_57 < sizeof( V_72 ) )
goto V_79;
}
V_72 = F_15 ( V_57 ) ;
V_57 += sizeof( V_72 ) ;
if ( ! V_72 || V_72 > V_58 - V_57 ) {
F_11 ( L_48 ) ;
F_17 ( type ) ;
F_5 ( L_49
L_50 ,
type , ( unsigned long long ) V_78 ,
( unsigned ) ( V_58 - V_57 ) , V_72 ) ;
goto V_73;
}
V_2 -> V_48 [ V_60 ] . V_50 = F_18 ( V_72 , V_75 ) ;
if ( V_2 -> V_48 [ V_60 ] . V_50 == NULL ) {
F_11 ( L_45 ) ;
V_59 = - V_76 ;
goto V_77;
}
F_2 ( L_51 ) ;
if ( V_80 ) {
F_4 ( type , V_9 ) ;
F_5 ( L_52 ,
type , ( unsigned long long ) V_78 , V_72 ) ;
}
memcpy ( V_2 -> V_48 [ V_60 ] . V_50 , V_57 , V_72 ) ;
V_2 -> V_48 [ V_60 ] . type = type ;
V_2 -> V_48 [ V_60 ] . V_78 = V_78 ;
V_2 -> V_48 [ V_60 ] . V_72 = V_72 ;
V_2 -> V_48 [ V_60 ] . V_9 = V_9 ;
V_57 += V_72 ;
}
if ( V_60 + 1 != V_2 -> V_49 ) {
F_11 ( L_53 ) ;
goto V_73;
}
goto V_81;
V_79:
F_11 ( L_54 ) ;
V_73:
V_59 = - V_82 ;
F_11 ( L_55 ) ;
V_77:
F_13 ( L_56 ) ;
F_7 ( V_2 ) ;
V_81:
F_19 ( V_56 ) ;
if ( V_59 == 0 )
F_2 ( L_57 ) ;
return V_59 ;
}
static int F_20 ( struct V_52 * V_53 , unsigned int type ,
T_2 * V_78 )
{
struct V_1 * V_2 = V_53 -> V_54 ;
int V_47 , V_83 = - 1 , V_84 = 0 ;
unsigned int V_85 = 0 ;
F_2 ( L_58 , V_7 ) ;
if ( V_80 ) {
F_17 ( type ) ;
F_5 ( L_59 , type , ( unsigned long long ) * V_78 ) ;
}
if ( ! V_2 -> V_48 ) {
F_11 ( L_60 ) ;
return - V_82 ;
}
if ( ( ( type & ~ V_38 ) == 0 ) && ( * V_78 == 0 ) )
* V_78 = V_86 ;
if ( type & V_10 )
V_85 = V_87 ;
else if ( type & V_38 ) {
type &= V_88 ;
V_85 = V_88 & ~ V_39 ;
} else if ( type & V_89 )
V_85 = V_89 ;
else if ( type & V_90 )
V_85 = V_90 ;
type &= V_85 ;
if ( ! ( type & V_38 ) )
V_85 = ~ 0 ;
for ( V_47 = 0 ; V_47 < V_2 -> V_49 ; V_47 ++ ) {
if ( ( type == ( V_2 -> V_48 [ V_47 ] . type & V_85 ) ) &&
( * V_78 == V_2 -> V_48 [ V_47 ] . V_78 ) )
goto V_91;
}
for ( V_47 = 0 ; V_47 < V_2 -> V_49 ; V_47 ++ ) {
T_2 V_92 ;
int V_93 ;
if ( type != ( V_2 -> V_48 [ V_47 ] . type & V_85 ) )
continue;
V_92 = * V_78 & V_2 -> V_48 [ V_47 ] . V_78 ;
if ( ! V_92 )
continue;
if ( ( * V_78 & V_92 ) == * V_78 )
goto V_91;
V_93 = F_21 ( V_92 ) ;
if ( V_93 > V_84 ) {
V_84 = V_93 ;
V_83 = V_47 ;
}
}
if ( V_84 > 0 ) {
F_2 ( L_61
L_62 , V_84 ) ;
F_17 ( type ) ;
F_5 ( L_63 , type , ( unsigned long long ) * V_78 ) ;
V_47 = V_83 ;
goto V_91;
}
V_47 = - V_70 ;
goto V_94;
V_91:
* V_78 = V_2 -> V_48 [ V_47 ] . V_78 ;
V_94:
F_2 ( L_64 , ( V_47 < 0 ) ? L_65 : L_66 ) ;
if ( V_80 ) {
F_17 ( type ) ;
F_5 ( L_59 , type , ( unsigned long long ) * V_78 ) ;
}
return V_47 ;
}
static inline int F_22 ( struct V_52 * V_53 , int V_95 , int V_96 )
{
struct V_1 * V_2 = V_53 -> V_54 ;
return ( ! V_53 -> V_97 ) ? - V_82 :
V_53 -> V_97 ( ( ( V_53 -> V_98 ) && ( V_53 -> V_98 -> V_2 ) ) ?
V_53 -> V_98 -> V_2 : V_2 -> V_66 . V_67 -> V_99 ,
V_100 , V_95 , V_96 ) ;
}
static int F_23 ( struct V_52 * V_53 , unsigned int type ,
T_2 * V_78 )
{
struct V_1 * V_2 = V_53 -> V_54 ;
int V_101 , V_59 ;
unsigned char * V_57 , * V_58 , V_5 [ V_2 -> V_65 . V_102 ] ;
F_2 ( L_39 , V_7 ) ;
V_101 = F_20 ( V_53 , type , V_78 ) ;
if ( V_101 < 0 )
return V_101 ;
F_13 ( L_67 ) ;
F_17 ( V_2 -> V_48 [ V_101 ] . type ) ;
F_5 ( L_59 , V_2 -> V_48 [ V_101 ] . type ,
( unsigned long long ) * V_78 ) ;
V_57 = V_2 -> V_48 [ V_101 ] . V_50 ;
V_58 = V_57 + V_2 -> V_48 [ V_101 ] . V_72 ;
while ( V_57 < V_58 ) {
T_4 V_72 ;
if ( V_57 + sizeof( V_72 ) > V_58 ) {
F_11 ( L_68 ) ;
return - V_82 ;
}
V_72 = F_24 ( * ( T_4 * ) V_57 ) ;
V_57 += sizeof( V_72 ) ;
if ( V_72 == 0xffff )
return 0 ;
if ( ! V_72 ) {
V_59 = F_22 ( V_53 , V_103 , 0 ) ;
if ( V_59 < 0 ) {
F_11 ( L_69 ,
( * V_57 ) & 0x7f ) ;
return - V_82 ;
}
continue;
}
if ( V_72 >= 0xff00 ) {
switch ( V_72 ) {
case 0xff00 :
V_59 = F_22 ( V_53 , V_104 , 0 ) ;
if ( V_59 < 0 ) {
F_11 ( L_69 ,
( * V_57 ) & 0x7f ) ;
return - V_82 ;
}
break;
default:
F_13 ( L_70 ,
V_72 & 0x7f ) ;
return - V_82 ;
}
continue;
}
if ( V_72 & 0x8000 ) {
F_25 ( V_72 & 0x7fff ) ;
continue;
}
if ( ( V_72 + V_57 > V_58 ) ) {
F_11 ( L_71 ,
V_72 , ( int ) ( V_58 - V_57 ) ) ;
return - V_82 ;
}
V_5 [ 0 ] = * V_57 ;
V_57 ++ ;
V_72 -- ;
while ( V_72 > 0 ) {
int V_105 = ( V_72 < V_2 -> V_65 . V_102 - 1 ) ?
V_72 : V_2 -> V_65 . V_102 - 1 ;
memcpy ( V_5 + 1 , V_57 , V_105 ) ;
V_59 = F_26 ( V_2 , V_5 , V_105 + 1 ) ;
if ( V_59 < 0 ) {
F_11 ( L_72 , V_59 ) ;
return - V_82 ;
}
V_57 += V_105 ;
V_72 -= V_105 ;
}
V_59 = F_22 ( V_53 , V_106 , 0 ) ;
if ( ( V_59 < 0 ) && ( V_59 != - V_82 ) ) {
F_11 ( L_73 , V_59 ) ;
return V_59 ;
}
}
return 0 ;
}
static int F_27 ( struct V_52 * V_53 , unsigned int type ,
T_2 * V_78 , T_4 V_9 , int V_107 )
{
struct V_1 * V_2 = V_53 -> V_54 ;
int V_101 , V_59 ;
unsigned char * V_57 ;
F_2 ( L_39 , V_7 ) ;
if ( ! V_9 ) {
V_101 = F_20 ( V_53 , type , V_78 ) ;
if ( V_101 < 0 )
return V_101 ;
} else {
for ( V_101 = 0 ; V_101 < V_2 -> V_49 ; V_101 ++ ) {
if ( ( V_2 -> V_48 [ V_101 ] . V_9 == V_9 ) &&
( V_2 -> V_48 [ V_101 ] . type & V_39 ) )
break;
}
if ( V_101 == V_2 -> V_49 )
return - V_70 ;
}
V_57 = V_2 -> V_48 [ V_101 ] . V_50 ;
if ( V_2 -> V_48 [ V_101 ] . type & V_39 ) {
if ( V_2 -> V_48 [ V_101 ] . V_72 != 12 * 16 || V_107 >= 16 )
return - V_82 ;
V_57 += 12 * V_107 ;
} else {
if ( V_2 -> V_48 [ V_101 ] . V_72 != 14 * 16 || V_107 >= 16 ||
F_24 ( * ( T_4 * ) ( V_57 + 14 * V_107 ) ) != 12 )
return - V_82 ;
V_57 += 14 * V_107 + 2 ;
}
F_13 ( L_74 ) ;
F_4 ( V_2 -> V_48 [ V_101 ] . type ,
V_2 -> V_48 [ V_101 ] . V_9 ) ;
F_5 ( L_59 , V_2 -> V_48 [ V_101 ] . type ,
( unsigned long long ) * V_78 ) ;
if ( V_2 -> V_74 < 0x0202 )
V_59 = F_28 (priv, {0x20 , 0x00 , 0x00 , 0x00}) ;
else
V_59 = F_28 (priv, {0xa0 , 0x00 , 0x00 , 0x00}) ;
if ( V_59 < 0 )
return - V_8 ;
V_59 = F_26 ( V_2 , V_57 , 12 ) ;
if ( V_59 < 0 )
return - V_8 ;
V_59 = F_28 (priv, {0x00 , 0x8c}) ;
if ( V_59 < 0 )
return - V_8 ;
return 0 ;
}
static int F_29 ( struct V_52 * V_53 , unsigned int type ,
T_2 V_108 , T_4 V_9 )
{
struct V_1 * V_2 = V_53 -> V_54 ;
struct V_109 V_110 ;
int V_59 = 0 , V_111 = 0 ;
T_1 V_112 , V_113 ;
T_2 V_114 ;
F_2 ( L_39 , V_7 ) ;
if ( ! V_2 -> V_48 ) {
if ( ! V_2 -> V_65 . V_63 ) {
F_13 ( L_75 ) ;
return - V_82 ;
}
V_59 = F_9 ( V_53 ) ;
if ( V_59 < 0 )
return V_59 ;
}
if ( V_2 -> V_65 . V_115 && ! ( type & V_21 ) )
type |= V_13 ;
V_116:
V_110 . type = type ;
V_110 . V_78 = V_108 ;
V_110 . V_117 = V_108 ;
V_110 . V_118 = V_38 | V_2 -> V_65 . V_118 ;
V_110 . V_119 = 0 ;
V_110 . V_9 = V_9 ;
F_2 ( L_76 ) ;
if ( V_80 ) {
F_17 ( V_110 . type ) ;
F_5 ( L_77 , V_110 . type ,
( unsigned long long ) V_110 . V_117 ) ;
if ( ! V_9 ) {
F_5 ( L_78 ) ;
F_17 ( V_2 -> V_65 . V_118 ) ;
F_5 ( L_79 , V_2 -> V_65 . V_118 ) ;
} else
F_5 ( L_80 , V_110 . V_9 ) ;
F_5 ( L_81 , V_110 . V_119 ) ;
}
if ( ( ( V_10 | V_110 . type ) & V_87 ) ==
( V_2 -> V_51 . type & V_87 ) ) {
F_2 ( L_82 ) ;
goto V_120;
}
memset ( & V_2 -> V_51 , 0 , sizeof( V_2 -> V_51 ) ) ;
V_59 = F_22 ( V_53 , V_103 , 0 ) ;
if ( V_59 < 0 )
goto V_121;
V_114 = 0 ;
V_59 = F_23 ( V_53 , V_10 | V_110 . type , & V_114 ) ;
if ( V_59 < 0 ) {
F_11 ( L_83 ,
V_59 ) ;
goto V_121;
}
F_2 ( L_84 ) ;
V_59 = F_23 ( V_53 , V_10 | V_11 | V_110 . type , & V_114 ) ;
if ( V_59 == - V_70 )
V_59 = F_23 ( V_53 , ( V_10 | V_11 | V_110 . type ) & ~ V_12 ,
& V_114 ) ;
if ( V_59 < 0 && V_59 != - V_70 ) {
F_11 ( L_85 ,
V_59 ) ;
goto V_121;
}
V_120:
if ( V_2 -> V_51 . type == ( V_10 | V_110 . type ) &&
V_2 -> V_51 . V_117 == V_108 ) {
F_2 ( L_86 ) ;
goto V_122;
}
V_2 -> V_51 . V_118 = 0 ;
V_59 = F_23 ( V_53 , V_110 . type , & V_110 . V_78 ) ;
if ( V_59 == - V_70 )
V_59 = F_23 ( V_53 , V_110 . type & ~ V_12 , & V_110 . V_78 ) ;
if ( V_59 < 0 )
goto V_121;
V_122:
if ( V_2 -> V_51 . V_118 == V_110 . V_118 &&
V_2 -> V_51 . V_119 == V_110 . V_119 ) {
F_2 ( L_87 ) ;
goto V_123;
}
if ( V_110 . type & V_21 )
goto V_123;
F_2 ( L_88 , V_110 . V_119 ) ;
V_59 = F_27 ( V_53 , V_110 . type | V_110 . V_118 , & V_110 . V_78 ,
V_110 . V_9 , V_110 . V_119 ) ;
V_123:
if ( F_1 ( V_2 , 0x0004 , & V_112 ) < 0 ||
F_1 ( V_2 , 0x0008 , & V_113 ) < 0 ) {
F_11 ( L_89 ) ;
goto V_121;
}
F_2 ( L_90
L_91 ,
V_113 , ( V_112 & 0xf000 ) >> 12 , ( V_112 & 0xf00 ) >> 8 ,
( V_112 & 0xf0 ) >> 4 , V_112 & 0xf ) ;
if ( V_2 -> V_65 . V_124 )
goto V_124;
if ( V_2 -> V_74 != ( ( V_112 & 0xf0 ) << 4 | ( V_112 & 0x0f ) ) ) {
if ( ! V_2 -> V_65 . V_124 ) {
F_11 ( L_92 ) ;
goto V_121;
} else {
F_11 ( L_93
L_94 ) ;
V_113 = 3028 ;
}
}
if ( V_2 -> V_113 == 0 && ( V_113 == 2028 || V_113 == 3028 ) ) {
V_2 -> V_113 = V_113 ;
V_2 -> V_125 = V_112 & 0xff00 ;
} else if ( V_2 -> V_113 == 0 || V_2 -> V_113 != V_113 ||
V_2 -> V_125 != ( V_112 & 0xff00 ) ) {
F_11 ( L_95
L_96 ) ;
goto V_121;
}
V_124:
memcpy ( & V_2 -> V_51 , & V_110 , sizeof( V_2 -> V_51 ) ) ;
V_2 -> V_51 . type |= V_10 ;
return 0 ;
V_121:
memset ( & V_2 -> V_51 , 0 , sizeof( V_2 -> V_51 ) ) ;
if ( V_111 < 8 ) {
F_25 ( 50 ) ;
V_111 ++ ;
F_2 ( L_97 ) ;
goto V_116;
}
if ( V_59 == - V_70 )
V_59 = - V_82 ;
return V_59 ;
}
static int F_30 ( struct V_52 * V_53 , T_1 * V_126 )
{
struct V_1 * V_2 = V_53 -> V_54 ;
T_1 V_127 , signal = 0 ;
int V_59 ;
F_2 ( L_39 , V_7 ) ;
F_31 ( & V_2 -> V_128 ) ;
V_59 = F_1 ( V_2 , V_129 , & V_127 ) ;
if ( V_59 < 0 )
goto V_94;
if ( V_127 == 1 )
signal = 1 << 11 ;
V_59 = F_1 ( V_2 , V_130 , & signal ) ;
if ( V_59 < 0 )
goto V_94;
signal = signal || ( ( signal & 0x07 ) << 12 ) ;
V_94:
F_32 ( & V_2 -> V_128 ) ;
* V_126 = signal ;
F_2 ( L_98 , signal ) ;
return V_59 ;
}
static int F_33 ( struct V_52 * V_53 , T_5 V_131 ,
enum V_132 V_133 ,
unsigned int type ,
T_2 V_108 ,
T_1 V_9 )
{
struct V_1 * V_2 = V_53 -> V_54 ;
int V_59 = - V_82 ;
unsigned char V_5 [ 4 ] ;
T_5 div , V_134 = 0 ;
F_2 ( L_39 , V_7 ) ;
F_31 ( & V_2 -> V_128 ) ;
F_2 ( L_99 , V_131 / 1000 ) ;
if ( F_29 ( V_53 , type , V_108 , V_9 ) < 0 )
goto V_94;
switch ( V_133 ) {
case V_135 :
V_59 = F_28 (priv, {0x00 , 0x00}) ;
break;
case V_136 :
break;
case V_137 :
if ( V_2 -> V_51 . type & V_16 )
V_134 = 1750000 ;
else
V_134 = 2750000 ;
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
div = ( V_131 - V_134 + DIV / 2 ) / DIV ;
if ( V_2 -> V_74 < 0x0202 )
V_59 = F_28 (priv, {0x00 , XREG_RF_FREQ, 0x00 , 0x00}) ;
else
V_59 = F_28 (priv, {0x80 , XREG_RF_FREQ, 0x00 , 0x00}) ;
if ( V_59 < 0 )
goto V_94;
if ( V_2 -> V_65 . F_25 )
F_25 ( V_2 -> V_65 . F_25 ) ;
F_22 ( V_53 , V_104 , 1 ) ;
F_25 ( 10 ) ;
V_5 [ 0 ] = 0xff & ( div >> 24 ) ;
V_5 [ 1 ] = 0xff & ( div >> 16 ) ;
V_5 [ 2 ] = 0xff & ( div >> 8 ) ;
V_5 [ 3 ] = 0xff & ( div ) ;
V_59 = F_26 ( V_2 , V_5 , sizeof( V_5 ) ) ;
if ( V_59 < 0 )
goto V_94;
F_25 ( 100 ) ;
V_2 -> V_138 = V_131 ;
F_2 ( L_100 ,
V_5 [ 0 ] , V_5 [ 1 ] , V_5 [ 2 ] , V_5 [ 3 ] ,
V_131 / 1000000 , ( V_131 % 1000000 ) / 1000 ) ;
V_59 = 0 ;
V_94:
F_32 ( & V_2 -> V_128 ) ;
return V_59 ;
}
static int F_34 ( struct V_52 * V_53 ,
struct V_139 * V_57 )
{
struct V_1 * V_2 = V_53 -> V_54 ;
unsigned int type = 0 ;
F_2 ( L_39 , V_7 ) ;
if ( V_57 -> V_140 == V_136 ) {
type |= V_21 ;
if ( V_2 -> V_65 . V_141 )
type |= V_22 ;
return F_33 ( V_53 , ( 625l * V_57 -> V_138 ) / 10 ,
V_136 , type , 0 , 0 ) ;
}
if ( ! V_57 -> V_108 )
V_57 -> V_108 = V_142 ;
if ( ! ( V_57 -> V_108 & V_142 ) )
type |= V_12 ;
V_57 -> V_108 |= F_6 () ;
return F_33 ( V_53 , 62500l * V_57 -> V_138 ,
V_135 , type , V_57 -> V_108 , 0 ) ;
}
static int F_35 ( struct V_52 * V_53 )
{
struct V_143 * V_144 = & V_53 -> V_145 ;
T_5 V_146 = V_144 -> V_147 ;
T_5 V_148 = V_144 -> V_149 ;
struct V_1 * V_2 = V_53 -> V_54 ;
unsigned int type = 0 ;
T_1 V_150 = 0 ;
F_2 ( L_39 , V_7 ) ;
switch ( V_146 ) {
case V_151 :
case V_152 :
if ( V_148 <= 6000000 )
type |= V_17 ;
switch ( V_2 -> V_65 . type ) {
case V_153 :
type |= V_15 ;
break;
case V_154 :
type |= V_14 ;
break;
case V_155 :
default:
if ( V_2 -> V_65 . V_150 == V_156 )
type |= V_15 ;
else
type |= V_14 ;
}
break;
case V_157 :
type |= V_26 | V_15 ;
break;
default:
return - V_82 ;
}
if ( V_148 <= 6000000 ) {
type |= V_16 ;
V_2 -> V_65 . V_158 = 0 ;
V_2 -> V_65 . V_159 = 0 ;
} else if ( V_148 <= 7000000 ) {
if ( V_144 -> V_138 < 470000000 )
V_2 -> V_65 . V_158 = 1 ;
else
V_2 -> V_65 . V_159 = 0 ;
type |= ( V_2 -> V_65 . V_158 && V_2 -> V_65 . V_159 ) ? V_19 : V_18 ;
type |= V_12 ;
} else {
if ( V_144 -> V_138 < 470000000 )
V_2 -> V_65 . V_158 = 0 ;
else
V_2 -> V_65 . V_159 = 1 ;
type |= ( V_2 -> V_65 . V_158 && V_2 -> V_65 . V_159 ) ? V_19 : V_20 ;
type |= V_12 ;
}
if ( V_2 -> V_65 . V_150 ) {
V_150 = V_2 -> V_65 . V_150 ;
if ( type == V_26 || V_2 -> V_74 < 0x0302 )
V_150 += 200 ;
}
return F_33 ( V_53 , V_144 -> V_138 ,
V_137 , type , 0 , V_150 ) ;
}
static int F_36 ( struct V_52 * V_53 )
{
struct V_1 * V_2 = V_53 -> V_54 ;
int V_59 = 0 ;
if ( V_160 || V_2 -> V_65 . V_161 )
return 0 ;
F_2 ( L_101 ) ;
if ( V_80 > 1 ) {
F_2 ( L_102 ) ;
F_37 () ;
}
F_31 ( & V_2 -> V_128 ) ;
if ( V_2 -> V_74 < 0x0202 )
V_59 = F_28 (priv, {0x00 , XREG_POWER_DOWN, 0x00 , 0x00}) ;
else
V_59 = F_28 (priv, {0x80 , XREG_POWER_DOWN, 0x00 , 0x00}) ;
V_2 -> V_51 . type = 0 ;
F_32 ( & V_2 -> V_128 ) ;
return V_59 ;
}
static int F_38 ( struct V_52 * V_53 )
{
struct V_1 * V_2 = V_53 -> V_54 ;
F_2 ( L_39 , V_7 ) ;
F_31 ( & V_162 ) ;
if ( F_39 ( V_2 ) == 1 ) {
F_8 ( V_2 -> V_65 . V_63 ) ;
F_7 ( V_2 ) ;
}
if ( V_2 )
F_40 ( V_2 ) ;
F_32 ( & V_162 ) ;
V_53 -> V_54 = NULL ;
return 0 ;
}
static int F_41 ( struct V_52 * V_53 , T_5 * V_138 )
{
struct V_1 * V_2 = V_53 -> V_54 ;
F_2 ( L_39 , V_7 ) ;
* V_138 = V_2 -> V_138 ;
return 0 ;
}
static int F_42 ( struct V_52 * V_53 , void * V_163 )
{
struct V_1 * V_2 = V_53 -> V_54 ;
struct V_164 * V_57 = V_163 ;
int V_59 = 0 ;
F_2 ( L_39 , V_7 ) ;
F_31 ( & V_2 -> V_128 ) ;
memcpy ( & V_2 -> V_65 , V_57 , sizeof( V_2 -> V_65 ) ) ;
if ( V_2 -> V_65 . V_102 < 9 )
V_2 -> V_65 . V_102 = 13 ;
if ( V_57 -> V_63 ) {
if ( V_2 -> V_65 . V_63 && strcmp ( V_57 -> V_63 , V_2 -> V_65 . V_63 ) ) {
F_8 ( V_2 -> V_65 . V_63 ) ;
F_7 ( V_2 ) ;
}
V_2 -> V_65 . V_63 = F_43 ( V_57 -> V_63 , V_75 ) ;
if ( V_2 -> V_65 . V_63 == NULL )
V_59 = - V_76 ;
}
F_32 ( & V_2 -> V_128 ) ;
return V_59 ;
}
struct V_52 * F_44 ( struct V_52 * V_53 ,
struct V_165 * V_166 )
{
struct V_1 * V_2 ;
int V_167 ;
if ( V_80 )
F_5 ( V_168 L_103 ) ;
if ( NULL == V_166 )
return NULL ;
if ( ! V_53 ) {
F_5 ( V_169 L_104 ) ;
return NULL ;
}
F_31 ( & V_162 ) ;
V_167 = F_45 ( struct V_1 , V_2 ,
V_170 ,
V_166 -> V_171 , V_166 -> V_172 ,
L_105 ) ;
switch ( V_167 ) {
case 0 :
goto V_121;
break;
case 1 :
V_2 -> V_65 . V_102 = 13 ;
F_46 ( & V_2 -> V_128 ) ;
V_53 -> V_54 = V_2 ;
break;
case 2 :
V_53 -> V_54 = V_2 ;
break;
}
memcpy ( & V_53 -> V_173 . V_174 , & V_175 ,
sizeof( V_175 ) ) ;
F_13 ( L_106 , L_107 ) ;
if ( V_166 -> V_65 )
F_42 ( V_53 , V_166 -> V_65 ) ;
F_32 ( & V_162 ) ;
return V_53 ;
V_121:
F_32 ( & V_162 ) ;
F_38 ( V_53 ) ;
return NULL ;
}
