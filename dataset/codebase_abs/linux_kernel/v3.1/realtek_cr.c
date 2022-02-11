static int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 * V_4 , int V_5 , T_1 * V_6 , int V_7 ,
enum V_8 V_9 , int * V_10 )
{
struct V_11 * V_12 = (struct V_11 * ) V_2 -> V_13 ;
struct V_14 * V_15 = (struct V_14 * ) V_2 -> V_13 ;
int V_16 ;
unsigned int V_17 ;
unsigned int V_18 ;
unsigned int V_19 = V_20 ;
V_12 -> V_21 = F_2 ( V_22 ) ;
V_12 -> V_23 = F_2 ( V_7 ) ;
V_12 -> V_24 = ( V_9 == V_25 ) ? 1 << 7 : 0 ;
V_12 -> V_26 = ++ V_2 -> V_27 ;
V_12 -> V_28 = V_3 ;
V_12 -> V_29 = V_5 ;
memset ( V_12 -> V_30 , 0 , sizeof( V_12 -> V_30 ) ) ;
memcpy ( V_12 -> V_30 , V_4 , V_12 -> V_29 ) ;
V_16 = F_3 ( V_2 , V_2 -> V_31 ,
V_12 , V_19 , NULL ) ;
if ( V_16 != V_32 )
return V_33 ;
if ( V_6 && V_7 ) {
unsigned int V_34 = ( V_9 == V_25 ) ?
V_2 -> V_35 : V_2 -> V_31 ;
V_16 = F_3 ( V_2 , V_34 ,
V_6 , V_7 , NULL ) ;
if ( V_16 == V_36 )
return V_33 ;
}
V_16 = F_3 ( V_2 , V_2 -> V_35 ,
V_15 , V_37 , & V_18 ) ;
if ( V_16 != V_32 )
return V_33 ;
if ( V_15 -> V_21 != F_2 ( V_38 ) ) {
F_4 ( L_1 ,
F_5 ( V_15 -> V_21 ) , V_38 ) ;
return V_33 ;
}
V_17 = V_15 -> V_39 ;
if ( V_15 -> V_26 != V_2 -> V_27 )
return V_33 ;
if ( V_17 )
V_17 = V_17 < V_7 ? V_17 : V_7 ;
if ( V_10 )
* V_10 = V_7 - V_17 ;
switch ( V_15 -> V_40 ) {
case V_41 :
return V_42 ;
case V_43 :
return V_44 ;
case V_45 :
return V_33 ;
}
return V_33 ;
}
static int F_6 ( struct V_1 * V_2 )
{
int V_16 ;
V_2 -> V_13 [ 0 ] = 0 ;
V_16 = F_7 ( V_2 , V_2 -> V_46 ,
V_47 ,
V_48 | V_49 |
V_50 ,
0 , V_2 -> V_51 , V_2 -> V_13 , 1 , 10 * V_52 ) ;
F_4 ( L_2 ,
V_16 , V_2 -> V_13 [ 0 ] ) ;
if ( V_16 > 0 )
return V_2 -> V_13 [ 0 ] ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 , T_2 V_53 , T_1 * V_54 , T_2 V_55 )
{
int V_56 ;
T_1 V_57 [ 12 ] = { 0 } ;
F_4 ( L_3 , V_58 , V_53 , V_55 ) ;
V_57 [ 0 ] = 0xF0 ;
V_57 [ 1 ] = 0x0D ;
V_57 [ 2 ] = ( T_1 ) ( V_53 >> 8 ) ;
V_57 [ 3 ] = ( T_1 ) V_53 ;
V_57 [ 4 ] = ( T_1 ) ( V_55 >> 8 ) ;
V_57 [ 5 ] = ( T_1 ) V_55 ;
V_56 = F_1 ( V_2 , 0 , V_57 , 12 ,
V_54 , V_55 , V_25 , NULL ) ;
if ( V_56 != V_42 )
return - V_59 ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , T_2 V_53 , T_1 * V_54 , T_2 V_55 )
{
int V_56 ;
T_1 V_57 [ 12 ] = { 0 } ;
F_4 ( L_3 , V_58 , V_53 , V_55 ) ;
V_57 [ 0 ] = 0xF0 ;
V_57 [ 1 ] = 0x0E ;
V_57 [ 2 ] = ( T_1 ) ( V_53 >> 8 ) ;
V_57 [ 3 ] = ( T_1 ) V_53 ;
V_57 [ 4 ] = ( T_1 ) ( V_55 >> 8 ) ;
V_57 [ 5 ] = ( T_1 ) V_55 ;
V_56 = F_1 ( V_2 , 0 , V_57 , 12 ,
V_54 , V_55 , V_60 , NULL ) ;
if ( V_56 != V_42 )
return - V_59 ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 * V_61 , int V_55 , int * V_62 )
{
int V_56 ;
T_1 V_57 [ 12 ] = { 0 } ;
F_4 ( L_4 , V_58 , V_3 ) ;
V_57 [ 0 ] = 0xF0 ;
V_57 [ 1 ] = 0x09 ;
V_56 = F_1 ( V_2 , V_3 , V_57 , 12 ,
V_61 , V_55 , V_25 , V_62 ) ;
if ( V_56 != V_42 )
return - V_59 ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_63 * V_64 = (struct V_63 * ) ( V_2 -> V_65 ) ;
int V_56 ;
T_1 V_6 [ 16 ] ;
V_56 = F_10 ( V_2 , V_3 , V_6 , 16 , & ( V_64 -> V_66 ) ) ;
if ( V_56 < 0 )
return - V_59 ;
F_4 ( L_5 , V_64 -> V_66 ) ;
V_64 -> V_61 [ V_3 ] . V_67 = ( ( T_2 ) V_6 [ 0 ] << 8 ) | V_6 [ 1 ] ;
V_64 -> V_61 [ V_3 ] . V_68 = ( ( T_2 ) V_6 [ 2 ] << 8 ) | V_6 [ 3 ] ;
V_64 -> V_61 [ V_3 ] . V_69 = V_6 [ 4 ] ;
V_64 -> V_61 [ V_3 ] . V_70 = V_6 [ 5 ] ;
V_64 -> V_61 [ V_3 ] . V_71 = V_6 [ 6 ] ;
V_64 -> V_61 [ V_3 ] . V_72 = ( ( T_2 ) V_6 [ 7 ] << 8 ) | V_6 [ 8 ] ;
V_64 -> V_61 [ V_3 ] . V_73 = V_6 [ 9 ] ;
V_64 -> V_61 [ V_3 ] . V_74 = V_6 [ 10 ] ;
V_64 -> V_61 [ V_3 ] . V_75 = V_6 [ 11 ] ;
V_64 -> V_61 [ V_3 ] . V_76 = V_6 [ 12 ] ;
if ( V_64 -> V_66 == 16 ) {
V_64 -> V_61 [ V_3 ] . V_77 . V_78 = V_6 [ 13 ] ;
V_64 -> V_61 [ V_3 ] . V_79 [ 0 ] = V_6 [ 14 ] ;
V_64 -> V_61 [ V_3 ] . V_79 [ 1 ] = V_6 [ 15 ] ;
}
return 0 ;
}
static int F_12 ( struct V_1 * V_2 )
{
int V_56 ;
T_1 V_80 ;
V_56 = F_8 ( V_2 , 0xFE77 , & V_80 , 1 ) ;
if ( V_56 < 0 )
return - V_59 ;
V_80 |= 0x04 ;
V_56 = F_9 ( V_2 , 0xFE77 , & V_80 , 1 ) ;
if ( V_56 < 0 )
return - V_59 ;
V_56 = F_8 ( V_2 , 0xFE77 , & V_80 , 1 ) ;
if ( V_56 < 0 )
return - V_59 ;
if ( ! ( V_80 & 0x04 ) )
return - V_59 ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 , int V_81 , int V_82 )
{
int V_56 ;
T_1 V_80 ;
V_56 = F_8 ( V_2 , 0xFE47 , & V_80 , 1 ) ;
if ( V_56 < 0 )
return - V_59 ;
if ( V_81 ) {
if ( V_82 )
V_80 |= 0x03 ;
else
V_80 |= 0x01 ;
} else {
V_80 &= ~ 0x03 ;
}
F_4 ( L_6 , V_58 , V_80 ) ;
V_56 = F_9 ( V_2 , 0xFE47 , & V_80 , 1 ) ;
if ( V_56 < 0 )
return - V_59 ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 )
{
struct V_63 * V_64 = (struct V_63 * ) ( V_2 -> V_65 ) ;
int V_56 ;
T_1 V_80 ;
F_4 ( L_7 , V_58 ) ;
if ( ! F_15 ( V_64 ) )
return 0 ;
V_56 = F_8 ( V_2 , 0xFE47 , & V_80 , 1 ) ;
if ( V_56 < 0 )
return - V_59 ;
if ( V_83 ) {
F_16 ( V_80 , 0 ) ;
F_16 ( V_80 , 1 ) ;
F_17 ( V_80 , 2 ) ;
if ( F_18 ( V_64 , 0x0138 , 0x3882 ) )
F_16 ( V_80 , 2 ) ;
F_17 ( V_80 , 7 ) ;
V_56 = F_9 ( V_2 , 0xFE47 , & V_80 , 1 ) ;
if ( V_56 < 0 )
return - V_59 ;
V_56 = F_12 ( V_2 ) ;
if ( V_56 == 0 )
( void ) F_13 ( V_2 , 1 , 0 ) ;
} else {
F_17 ( V_80 , 2 ) ;
if ( F_18 ( V_64 , 0x0138 , 0x3882 ) )
F_16 ( V_80 , 2 ) ;
if ( F_18 ( V_64 , 0x0159 , 0x5889 ) ||
F_18 ( V_64 , 0x0138 , 0x3880 ) ) {
F_16 ( V_80 , 0 ) ;
F_16 ( V_80 , 7 ) ;
}
V_56 = F_9 ( V_2 , 0xFE47 , & V_80 , 1 ) ;
if ( V_56 < 0 )
return - V_59 ;
if ( F_18 ( V_64 , 0x0159 , 0x5888 ) ) {
V_80 = 0xFF ;
V_56 = F_9 ( V_2 , 0xFE79 , & V_80 , 1 ) ;
if ( V_56 < 0 )
return - V_59 ;
V_80 = 0x01 ;
V_56 = F_9 ( V_2 , 0x48 , & V_80 , 1 ) ;
if ( V_56 < 0 )
return - V_59 ;
}
}
F_4 ( L_8 , V_58 ) ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 )
{
struct V_63 * V_64 = (struct V_63 * ) ( V_2 -> V_65 ) ;
int V_56 ;
T_1 V_80 ;
F_4 ( L_7 , V_58 ) ;
if ( ! F_15 ( V_64 ) )
return 0 ;
if ( V_83 ) {
V_56 = F_8 ( V_2 , 0xFE77 , & V_80 , 1 ) ;
if ( V_56 < 0 )
return - V_59 ;
F_17 ( V_80 , 2 ) ;
V_56 = F_9 ( V_2 , 0xFE77 , & V_80 , 1 ) ;
if ( V_56 < 0 )
return - V_59 ;
if ( F_18 ( V_64 , 0x0159 , 0x5888 ) ) {
V_80 = 0x01 ;
V_56 = F_9 ( V_2 , 0x48 , & V_80 , 1 ) ;
if ( V_56 < 0 )
return - V_59 ;
}
V_56 = F_8 ( V_2 , 0xFE47 , & V_80 , 1 ) ;
if ( V_56 < 0 )
return - V_59 ;
F_17 ( V_80 , 0 ) ;
if ( F_18 ( V_64 , 0x0138 , 0x3882 ) )
F_17 ( V_80 , 2 ) ;
V_56 = F_9 ( V_2 , 0xFE77 , & V_80 , 1 ) ;
if ( V_56 < 0 )
return - V_59 ;
} else {
if ( F_18 ( V_64 , 0x0159 , 0x5889 ) ||
F_18 ( V_64 , 0x0138 , 0x3880 ) ||
F_18 ( V_64 , 0x0138 , 0x3882 ) ) {
V_56 = F_8 ( V_2 , 0xFE47 , & V_80 , 1 ) ;
if ( V_56 < 0 )
return - V_59 ;
if ( F_18 ( V_64 , 0x0159 , 0x5889 ) ||
F_18 ( V_64 , 0x0138 , 0x3880 ) ) {
F_17 ( V_80 , 0 ) ;
F_17 ( V_80 , 7 ) ;
}
if ( F_18 ( V_64 , 0x0138 , 0x3882 ) )
F_17 ( V_80 , 2 ) ;
V_56 = F_9 ( V_2 , 0xFE47 , & V_80 , 1 ) ;
if ( V_56 < 0 )
return - V_59 ;
}
if ( F_18 ( V_64 , 0x0159 , 0x5888 ) ) {
V_80 = 0x01 ;
V_56 = F_9 ( V_2 , 0x48 , & V_80 , 1 ) ;
if ( V_56 < 0 )
return - V_59 ;
}
}
F_4 ( L_8 , V_58 ) ;
return 0 ;
}
static void F_20 ( struct V_1 * V_2 )
{
struct V_63 * V_64 = (struct V_63 * ) ( V_2 -> V_65 ) ;
int V_56 ;
T_1 V_84 ;
F_4 ( L_7 , V_58 ) ;
if ( ( F_21 ( V_64 ) != 0x0158 ) || ( F_22 ( V_64 ) != 0x5895 ) ) {
F_4 ( L_9 ) ;
} else {
V_56 = F_8 ( V_2 , 0xFD6F , & V_84 , 1 ) ;
if ( V_56 == V_85 && ( V_84 & 0x1F ) == 0 ) {
V_84 = 0x1F ;
V_56 = F_9 ( V_2 , 0xFD70 , & V_84 , 1 ) ;
if ( V_56 != V_85 )
F_4 ( L_10 ) ;
} else {
F_4 ( L_11 ) ;
}
}
F_4 ( L_8 , V_58 ) ;
}
static void F_23 ( struct V_1 * V_2 )
{
struct V_63 * V_64 = (struct V_63 * ) ( V_2 -> V_65 ) ;
int V_56 ;
T_1 V_6 [ 13 ] ;
F_4 ( L_7 , V_58 ) ;
if ( ( F_21 ( V_64 ) != 0x0158 ) || ( F_22 ( V_64 ) != 0x5895 ) ) {
F_4 ( L_9 ) ;
} else {
V_56 = F_8 ( V_2 , 0xFD6F , V_6 , 1 ) ;
if ( V_56 == V_85 && ( V_6 [ 0 ] & 0x24 ) == 0x24 ) {
V_56 = F_8 ( V_2 , 0xD04E , V_6 , 1 ) ;
if ( V_56 == V_85 ) {
V_6 [ 0 ] |= 0x04 ;
V_56 = F_9 ( V_2 , 0xFD70 , V_6 , 1 ) ;
if ( V_56 != V_85 )
F_4 ( L_10 ) ;
} else {
F_4 ( L_12 ) ;
}
} else {
F_4 ( L_13 ) ;
}
}
F_4 ( L_8 , V_58 ) ;
}
static void F_24 ( struct V_63 * V_64 )
{
F_4 ( L_14 , V_58 , F_25 ( V_64 ) ) ;
V_64 -> V_86 = V_87 + F_26 ( 1000 * V_88 ) ;
F_27 ( & V_64 -> V_89 , V_64 -> V_86 ) ;
F_4 ( L_8 , V_58 ) ;
}
static void F_28 ( unsigned long V_54 )
{
struct V_63 * V_64 = (struct V_63 * ) V_54 ;
struct V_1 * V_2 = V_64 -> V_2 ;
F_4 ( L_7 , V_58 ) ;
switch ( F_25 ( V_64 ) ) {
case V_90 :
case V_91 :
F_24 ( V_64 ) ;
break;
case V_92 :
case V_93 :
F_4 ( L_15
L_16 , V_58 ,
F_29 ( & V_2 -> V_94 -> V_95 ) ,
F_29 ( & V_2 -> V_94 -> V_96 . V_97 . V_98 ) ) ;
if ( F_29 ( & V_2 -> V_94 -> V_95 ) > 0 ) {
F_4 ( L_17 ,
V_58 ) ;
F_30 ( V_64 , V_93 ) ;
F_31 ( & V_2 -> V_94 -> V_96 , true ) ;
F_32 ( V_2 -> V_94 ) ;
F_4 ( L_18
L_19 ,
V_58 ,
F_29 ( & V_2 -> V_94 -> V_95 ) ,
F_29 (
& V_2 -> V_94 -> V_96 . V_97 . V_98 ) ) ;
}
break;
default:
F_4 ( L_20 , V_58 ) ;
break;
}
F_4 ( L_8 , V_58 ) ;
}
static inline int F_33 ( struct V_99 * V_100 )
{
if ( ( V_100 -> V_57 [ 0 ] == V_101 ) ||
( V_100 -> V_57 [ 0 ] == V_102 ) ) {
return 0 ;
}
return 1 ;
}
void F_34 ( struct V_99 * V_100 , struct V_1 * V_2 )
{
struct V_63 * V_64 = (struct V_63 * ) ( V_2 -> V_65 ) ;
static int V_103 = 1 ;
static T_1 V_104 [] = { 0x70 , 0 , 0x02 , 0 , 0 , 0 , 0 ,
10 , 0 , 0 , 0 , 0 , 0x3A , 0 , 0 , 0 , 0 , 0
} ;
static T_1 V_105 [] = { 0x70 , 0 , 0x05 , 0 , 0 , 0 , 0 ,
10 , 0 , 0 , 0 , 0 , 0x24 , 0 , 0 , 0 , 0 , 0
} ;
int V_106 ;
F_4 ( L_7 , V_58 ) ;
if ( F_33 ( V_100 ) ) {
F_4 ( L_21
L_16 , V_58 ,
F_29 ( & V_2 -> V_94 -> V_95 ) ,
F_29 ( & V_2 -> V_94 -> V_96 . V_97 . V_98 ) ) ;
if ( F_29 ( & V_2 -> V_94 -> V_95 ) <= 0 ) {
V_106 = F_35 ( V_2 -> V_94 ) ;
F_4 ( L_22 , V_58 , V_106 ) ;
}
if ( F_25 ( V_64 ) != V_91 )
F_30 ( V_64 , V_91 ) ;
V_64 -> V_107 ( V_100 , V_2 ) ;
} else {
if ( F_25 ( V_64 ) == V_93 ) {
F_4 ( L_23 , V_58 ) ;
if ( ( V_100 -> V_57 [ 0 ] == V_101 ) &&
( V_64 -> V_108 == V_109 ) ) {
if ( F_36 ( V_64 , V_100 -> V_110 -> V_3 ) ) {
V_100 -> V_16 = V_111 ;
} else {
V_100 -> V_16 = V_112 ;
memcpy ( V_100 -> V_113 ,
V_104 ,
V_114 ) ;
}
F_4 ( L_24 ,
V_58 ) ;
goto V_115;
}
if ( V_100 -> V_57 [ 0 ] == V_102 ) {
int V_116 = V_100 -> V_57 [ 4 ] & 0x1 ;
if ( V_116 ) {
V_100 -> V_16 = V_112 ;
memcpy ( V_100 -> V_113 ,
V_105 ,
V_114 ) ;
} else {
V_100 -> V_16 = V_111 ;
}
F_4 ( L_25 ,
V_58 ) ;
goto V_115;
}
} else {
F_4 ( L_26 , V_58 ) ;
V_64 -> V_107 ( V_100 , V_2 ) ;
if ( V_100 -> V_57 [ 0 ] == V_101 ) {
if ( V_100 -> V_16 == V_111 ) {
F_37 ( V_64 , V_100 -> V_110 -> V_3 ) ;
if ( V_103 ) {
V_103 = 0 ;
F_23 ( V_2 ) ;
}
} else {
F_38 ( V_64 , V_100 -> V_110 -> V_3 ) ;
V_103 = 1 ;
}
}
if ( F_25 ( V_64 ) != V_92 )
F_30 ( V_64 , V_92 ) ;
}
}
V_115:
F_4 ( L_27 , V_58 , F_25 ( V_64 ) ) ;
if ( F_25 ( V_64 ) == V_91 )
F_24 ( V_64 ) ;
F_4 ( L_8 , V_58 ) ;
}
static int F_39 ( struct V_1 * V_2 )
{
struct V_63 * V_64 ;
struct V_117 * V_61 = NULL ;
T_1 V_6 [ 16 ] ;
int V_56 ;
V_64 = (struct V_63 * ) V_2 -> V_65 ;
V_64 -> V_118 = 0 ;
V_64 -> V_108 = V_119 ;
V_64 -> V_120 = 0 ;
F_30 ( V_64 , V_90 ) ;
V_56 = F_10 ( V_2 , 0 , V_6 , 16 , & ( V_64 -> V_66 ) ) ;
if ( V_56 != V_85 ) {
F_4 ( L_28 ) ;
return - V_59 ;
}
V_61 = V_64 -> V_61 ;
V_61 -> V_67 = ( ( T_2 ) V_6 [ 0 ] << 8 ) | V_6 [ 1 ] ;
V_61 -> V_68 = ( ( T_2 ) V_6 [ 2 ] << 8 ) | V_6 [ 3 ] ;
V_61 -> V_69 = V_6 [ 4 ] ;
V_61 -> V_70 = V_6 [ 5 ] ;
V_61 -> V_71 = V_6 [ 6 ] ;
V_61 -> V_72 = ( ( T_2 ) V_6 [ 7 ] << 8 ) | V_6 [ 8 ] ;
V_61 -> V_73 = V_6 [ 9 ] ;
V_61 -> V_74 = V_6 [ 10 ] ;
V_61 -> V_75 = V_6 [ 11 ] ;
V_61 -> V_76 = V_6 [ 12 ] ;
if ( V_64 -> V_66 == 16 ) {
V_61 -> V_77 . V_78 = V_6 [ 13 ] ;
V_61 -> V_79 [ 0 ] = V_6 [ 14 ] ;
V_61 -> V_79 [ 1 ] = V_6 [ 15 ] ;
}
V_64 = (struct V_63 * ) ( V_2 -> V_65 ) ;
V_64 -> V_107 = V_2 -> V_121 ;
F_40 ( & V_2 -> V_122 -> V_96 , 0 ) ;
V_2 -> V_121 = F_34 ;
V_64 -> V_86 = 0 ;
F_41 ( & V_64 -> V_89 , F_28 ,
( unsigned long ) V_64 ) ;
F_20 ( V_2 ) ;
F_42 ( V_2 -> V_122 ) ;
return 0 ;
}
static void F_43 ( void * V_65 )
{
struct V_63 * V_64 = (struct V_63 * ) V_65 ;
F_4 ( L_7 , V_58 ) ;
if ( ! V_64 )
return;
#ifdef F_44
if ( V_123 ) {
F_45 ( & V_64 -> V_89 ) ;
V_64 -> V_86 = 0 ;
}
#endif
F_46 ( V_64 -> V_61 ) ;
}
int F_47 ( struct V_124 * V_125 , T_3 V_126 )
{
struct V_1 * V_2 = F_48 ( V_125 ) ;
F_4 ( L_7 , V_58 ) ;
F_49 ( & V_2 -> V_127 ) ;
F_19 ( V_2 ) ;
F_50 ( & V_2 -> V_127 ) ;
F_4 ( L_8 , V_58 ) ;
return 0 ;
}
static int F_51 ( struct V_124 * V_125 )
{
struct V_1 * V_2 = F_48 ( V_125 ) ;
F_4 ( L_7 , V_58 ) ;
F_20 ( V_2 ) ;
F_14 ( V_2 ) ;
F_4 ( L_8 , V_58 ) ;
return 0 ;
}
static int F_52 ( struct V_1 * V_2 )
{
struct V_63 * V_64 ;
int V_128 , V_129 , V_56 ;
V_64 = F_53 ( sizeof( struct V_63 ) , V_130 ) ;
if ( ! V_64 )
return - V_131 ;
V_2 -> V_65 = V_64 ;
V_2 -> V_132 = F_43 ;
V_2 -> V_133 = V_64 -> V_133 = F_6 ( V_2 ) ;
F_4 ( L_29 , V_64 -> V_133 ) ;
V_128 = ( V_64 -> V_133 + 1 ) * sizeof( struct V_117 ) ;
V_64 -> V_61 = F_53 ( V_128 , V_130 ) ;
if ( ! V_64 -> V_61 )
goto V_134;
for ( V_129 = 0 ; V_129 <= ( int ) ( V_64 -> V_133 ) ; V_129 ++ ) {
V_56 = F_11 ( V_2 , ( T_1 ) V_129 ) ;
if ( V_56 < 0 )
goto V_134;
}
if ( F_54 ( V_64 , 0x5888 ) || F_54 ( V_64 , 0x5889 ) ||
F_54 ( V_64 , 0x5901 ) )
F_55 ( V_64 ) ;
if ( F_56 ( V_64 ) == 16 ) {
if ( F_57 ( V_64 ) )
F_55 ( V_64 ) ;
}
#ifdef F_44
if ( V_123 ) {
V_64 -> V_2 = V_2 ;
F_39 ( V_2 ) ;
}
#endif
F_4 ( L_30 , V_64 -> V_135 ) ;
( void ) F_14 ( V_2 ) ;
return 0 ;
V_134:
if ( V_2 -> V_65 ) {
F_46 ( V_64 -> V_61 ) ;
F_46 ( V_2 -> V_65 ) ;
V_2 -> V_65 = NULL ;
}
return - V_59 ;
}
static int F_58 ( struct V_124 * V_136 ,
const struct V_137 * V_138 )
{
struct V_1 * V_2 ;
int V_16 ;
F_4 ( L_31 ) ;
V_16 = F_59 ( & V_2 , V_136 , V_138 ,
( V_138 - V_139 ) +
V_140 ) ;
if ( V_16 )
return V_16 ;
V_16 = F_60 ( V_2 ) ;
return V_16 ;
}
static int T_4 F_61 ( void )
{
return F_62 ( & V_141 ) ;
}
static void T_5 F_63 ( void )
{
F_64 ( & V_141 ) ;
}
