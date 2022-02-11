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
static int F_6 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 * V_4 , int V_5 , T_1 * V_6 , int V_7 ,
enum V_8 V_9 , int * V_10 )
{
struct V_11 * V_12 = (struct V_11 * ) V_2 -> V_13 ;
struct V_14 * V_15 = (struct V_14 * ) V_2 -> V_13 ;
int V_16 ;
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
V_16 = F_7 ( V_2 -> V_46 , V_2 -> V_35 , V_15 ,
V_37 , & V_18 , 250 ) ;
return V_16 ;
}
static int F_8 ( struct V_1 * V_2 )
{
int V_16 ;
V_2 -> V_13 [ 0 ] = 0 ;
V_16 = F_9 ( V_2 , V_2 -> V_47 ,
V_48 ,
V_49 | V_50 |
V_51 ,
0 , V_2 -> V_52 , V_2 -> V_13 , 1 , 10 * V_53 ) ;
F_4 ( L_2 ,
V_16 , V_2 -> V_13 [ 0 ] ) ;
if ( V_16 > 0 )
return V_2 -> V_13 [ 0 ] ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 , T_2 V_54 , T_1 * V_55 , T_2 V_56 )
{
int V_57 ;
T_1 V_58 [ 12 ] = { 0 } ;
T_1 * V_6 ;
V_6 = F_11 ( V_56 , V_59 ) ;
if ( V_6 == NULL )
return V_33 ;
F_4 ( L_3 , V_60 , V_54 , V_56 ) ;
V_58 [ 0 ] = 0xF0 ;
V_58 [ 1 ] = 0x0D ;
V_58 [ 2 ] = ( T_1 ) ( V_54 >> 8 ) ;
V_58 [ 3 ] = ( T_1 ) V_54 ;
V_58 [ 4 ] = ( T_1 ) ( V_56 >> 8 ) ;
V_58 [ 5 ] = ( T_1 ) V_56 ;
V_57 = F_1 ( V_2 , 0 , V_58 , 12 ,
V_6 , V_56 , V_25 , NULL ) ;
if ( V_57 != V_42 ) {
F_12 ( V_6 ) ;
return - V_61 ;
}
memcpy ( V_55 , V_6 , V_56 ) ;
F_12 ( V_6 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 , T_2 V_54 , T_1 * V_55 , T_2 V_56 )
{
int V_57 ;
T_1 V_58 [ 12 ] = { 0 } ;
T_1 * V_6 ;
V_6 = F_14 ( V_55 , V_56 , V_59 ) ;
if ( V_6 == NULL )
return V_33 ;
F_4 ( L_3 , V_60 , V_54 , V_56 ) ;
V_58 [ 0 ] = 0xF0 ;
V_58 [ 1 ] = 0x0E ;
V_58 [ 2 ] = ( T_1 ) ( V_54 >> 8 ) ;
V_58 [ 3 ] = ( T_1 ) V_54 ;
V_58 [ 4 ] = ( T_1 ) ( V_56 >> 8 ) ;
V_58 [ 5 ] = ( T_1 ) V_56 ;
V_57 = F_1 ( V_2 , 0 , V_58 , 12 ,
V_6 , V_56 , V_62 , NULL ) ;
F_12 ( V_6 ) ;
if ( V_57 != V_42 )
return - V_61 ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 * V_63 , int V_56 , int * V_64 )
{
int V_57 ;
T_1 V_58 [ 12 ] = { 0 } ;
T_1 * V_6 ;
V_6 = F_11 ( V_56 , V_59 ) ;
if ( V_6 == NULL )
return V_33 ;
F_4 ( L_4 , V_60 , V_3 ) ;
V_58 [ 0 ] = 0xF0 ;
V_58 [ 1 ] = 0x09 ;
V_57 = F_1 ( V_2 , V_3 , V_58 , 12 ,
V_6 , V_56 , V_25 , V_64 ) ;
if ( V_57 != V_42 ) {
F_12 ( V_6 ) ;
return - V_61 ;
}
memcpy ( V_63 , V_6 , V_56 ) ;
F_12 ( V_6 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_65 * V_66 = (struct V_65 * ) ( V_2 -> V_67 ) ;
int V_57 ;
T_1 V_6 [ 16 ] ;
V_57 = F_15 ( V_2 , V_3 , V_6 , 16 , & ( V_66 -> V_68 ) ) ;
if ( V_57 < 0 )
return - V_61 ;
F_4 ( L_5 , V_66 -> V_68 ) ;
V_66 -> V_63 [ V_3 ] . V_69 = ( ( T_2 ) V_6 [ 0 ] << 8 ) | V_6 [ 1 ] ;
V_66 -> V_63 [ V_3 ] . V_70 = ( ( T_2 ) V_6 [ 2 ] << 8 ) | V_6 [ 3 ] ;
V_66 -> V_63 [ V_3 ] . V_71 = V_6 [ 4 ] ;
V_66 -> V_63 [ V_3 ] . V_72 = V_6 [ 5 ] ;
V_66 -> V_63 [ V_3 ] . V_73 = V_6 [ 6 ] ;
V_66 -> V_63 [ V_3 ] . V_74 = ( ( T_2 ) V_6 [ 7 ] << 8 ) | V_6 [ 8 ] ;
V_66 -> V_63 [ V_3 ] . V_75 = V_6 [ 9 ] ;
V_66 -> V_63 [ V_3 ] . V_76 = V_6 [ 10 ] ;
V_66 -> V_63 [ V_3 ] . V_77 = V_6 [ 11 ] ;
V_66 -> V_63 [ V_3 ] . V_78 = V_6 [ 12 ] ;
if ( V_66 -> V_68 == 16 ) {
V_66 -> V_63 [ V_3 ] . V_79 . V_80 = V_6 [ 13 ] ;
V_66 -> V_63 [ V_3 ] . V_81 [ 0 ] = V_6 [ 14 ] ;
V_66 -> V_63 [ V_3 ] . V_81 [ 1 ] = V_6 [ 15 ] ;
}
return 0 ;
}
static int F_17 ( struct V_1 * V_2 )
{
int V_57 ;
T_1 V_82 ;
V_57 = F_10 ( V_2 , 0xFE77 , & V_82 , 1 ) ;
if ( V_57 < 0 )
return - V_61 ;
V_82 |= 0x04 ;
V_57 = F_13 ( V_2 , 0xFE77 , & V_82 , 1 ) ;
if ( V_57 < 0 )
return - V_61 ;
V_57 = F_10 ( V_2 , 0xFE77 , & V_82 , 1 ) ;
if ( V_57 < 0 )
return - V_61 ;
if ( ! ( V_82 & 0x04 ) )
return - V_61 ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 , T_1 * V_55 , T_2 V_56 )
{
int V_57 ;
T_1 V_58 [ 12 ] = { 0 } ;
F_4 ( L_6 , V_83 , V_56 ) ;
V_58 [ 0 ] = 0xF0 ;
V_58 [ 1 ] = 0x0E ;
V_58 [ 2 ] = 0xfe ;
V_58 [ 3 ] = 0x47 ;
V_58 [ 4 ] = ( T_1 ) ( V_56 >> 8 ) ;
V_58 [ 5 ] = ( T_1 ) V_56 ;
V_57 = F_6 ( V_2 , 0 , V_58 , 12 , V_55 , V_56 , V_62 , NULL ) ;
if ( V_57 != V_42 ) {
return - V_61 ;
}
return 0 ;
}
static int F_19 ( struct V_1 * V_2 , int V_84 , int V_85 )
{
int V_57 ;
T_1 V_82 ;
V_57 = F_10 ( V_2 , 0xFE47 , & V_82 , 1 ) ;
if ( V_57 < 0 )
return - V_61 ;
if ( V_84 ) {
if ( V_85 )
V_82 |= 0x03 ;
else
V_82 |= 0x01 ;
} else {
V_82 &= ~ 0x03 ;
}
F_4 ( L_7 , V_60 , V_82 ) ;
V_57 = F_18 ( V_2 , & V_82 , 1 ) ;
if ( V_57 < 0 )
return - V_61 ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 )
{
struct V_65 * V_66 = (struct V_65 * ) ( V_2 -> V_67 ) ;
int V_57 ;
T_1 V_82 ;
F_4 ( L_8 , V_60 ) ;
if ( ! F_21 ( V_66 ) )
return 0 ;
V_57 = F_10 ( V_2 , 0xFE47 , & V_82 , 1 ) ;
if ( V_57 < 0 )
return - V_61 ;
if ( V_86 ) {
F_22 ( V_82 , 0 ) ;
F_22 ( V_82 , 1 ) ;
F_23 ( V_82 , 2 ) ;
if ( F_24 ( V_66 , 0x0138 , 0x3882 ) )
F_22 ( V_82 , 2 ) ;
F_23 ( V_82 , 7 ) ;
V_57 = F_18 ( V_2 , & V_82 , 1 ) ;
if ( V_57 < 0 )
return - V_61 ;
V_57 = F_17 ( V_2 ) ;
if ( V_57 == 0 )
( void ) F_19 ( V_2 , 1 , 0 ) ;
} else {
F_23 ( V_82 , 2 ) ;
if ( F_24 ( V_66 , 0x0138 , 0x3882 ) )
F_22 ( V_82 , 2 ) ;
if ( F_24 ( V_66 , 0x0159 , 0x5889 ) ||
F_24 ( V_66 , 0x0138 , 0x3880 ) ) {
F_22 ( V_82 , 0 ) ;
F_22 ( V_82 , 7 ) ;
}
V_57 = F_18 ( V_2 , & V_82 , 1 ) ;
if ( V_57 < 0 )
return - V_61 ;
if ( F_24 ( V_66 , 0x0159 , 0x5888 ) ) {
V_82 = 0xFF ;
V_57 = F_13 ( V_2 , 0xFE79 , & V_82 , 1 ) ;
if ( V_57 < 0 )
return - V_61 ;
V_82 = 0x01 ;
V_57 = F_13 ( V_2 , 0x48 , & V_82 , 1 ) ;
if ( V_57 < 0 )
return - V_61 ;
}
}
F_4 ( L_9 , V_60 ) ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 )
{
struct V_65 * V_66 = (struct V_65 * ) ( V_2 -> V_67 ) ;
int V_57 ;
T_1 V_82 ;
F_4 ( L_8 , V_60 ) ;
if ( ! F_21 ( V_66 ) )
return 0 ;
if ( V_86 ) {
V_57 = F_10 ( V_2 , 0xFE77 , & V_82 , 1 ) ;
if ( V_57 < 0 )
return - V_61 ;
F_23 ( V_82 , 2 ) ;
V_57 = F_13 ( V_2 , 0xFE77 , & V_82 , 1 ) ;
if ( V_57 < 0 )
return - V_61 ;
if ( F_24 ( V_66 , 0x0159 , 0x5888 ) ) {
V_82 = 0x01 ;
V_57 = F_13 ( V_2 , 0x48 , & V_82 , 1 ) ;
if ( V_57 < 0 )
return - V_61 ;
}
V_57 = F_10 ( V_2 , 0xFE47 , & V_82 , 1 ) ;
if ( V_57 < 0 )
return - V_61 ;
F_23 ( V_82 , 0 ) ;
if ( F_24 ( V_66 , 0x0138 , 0x3882 ) )
F_23 ( V_82 , 2 ) ;
V_57 = F_13 ( V_2 , 0xFE77 , & V_82 , 1 ) ;
if ( V_57 < 0 )
return - V_61 ;
} else {
if ( F_24 ( V_66 , 0x0159 , 0x5889 ) ||
F_24 ( V_66 , 0x0138 , 0x3880 ) ||
F_24 ( V_66 , 0x0138 , 0x3882 ) ) {
V_57 = F_10 ( V_2 , 0xFE47 , & V_82 , 1 ) ;
if ( V_57 < 0 )
return - V_61 ;
if ( F_24 ( V_66 , 0x0159 , 0x5889 ) ||
F_24 ( V_66 , 0x0138 , 0x3880 ) ) {
F_23 ( V_82 , 0 ) ;
F_23 ( V_82 , 7 ) ;
}
if ( F_24 ( V_66 , 0x0138 , 0x3882 ) )
F_23 ( V_82 , 2 ) ;
V_57 = F_18 ( V_2 , & V_82 , 1 ) ;
if ( V_57 < 0 )
return - V_61 ;
}
if ( F_24 ( V_66 , 0x0159 , 0x5888 ) ) {
V_82 = 0x01 ;
V_57 = F_13 ( V_2 , 0x48 , & V_82 , 1 ) ;
if ( V_57 < 0 )
return - V_61 ;
}
}
F_4 ( L_9 , V_60 ) ;
return 0 ;
}
static void F_26 ( struct V_1 * V_2 )
{
struct V_65 * V_66 = (struct V_65 * ) ( V_2 -> V_67 ) ;
int V_57 ;
T_1 V_87 ;
F_4 ( L_8 , V_60 ) ;
if ( ( F_27 ( V_66 ) != 0x0158 ) || ( F_28 ( V_66 ) != 0x5895 ) ) {
F_4 ( L_10 ) ;
} else {
V_57 = F_10 ( V_2 , 0xFD6F , & V_87 , 1 ) ;
if ( V_57 == V_88 && ( V_87 & 0x1F ) == 0 ) {
V_87 = 0x1F ;
V_57 = F_13 ( V_2 , 0xFD70 , & V_87 , 1 ) ;
if ( V_57 != V_88 )
F_4 ( L_11 ) ;
} else {
F_4 ( L_12 ) ;
}
}
F_4 ( L_9 , V_60 ) ;
}
static void F_29 ( struct V_1 * V_2 )
{
struct V_65 * V_66 = (struct V_65 * ) ( V_2 -> V_67 ) ;
int V_57 ;
T_1 V_6 [ 13 ] ;
F_4 ( L_8 , V_60 ) ;
if ( ( F_27 ( V_66 ) != 0x0158 ) || ( F_28 ( V_66 ) != 0x5895 ) ) {
F_4 ( L_10 ) ;
} else {
V_57 = F_10 ( V_2 , 0xFD6F , V_6 , 1 ) ;
if ( V_57 == V_88 && ( V_6 [ 0 ] & 0x24 ) == 0x24 ) {
V_57 = F_10 ( V_2 , 0xD04E , V_6 , 1 ) ;
if ( V_57 == V_88 ) {
V_6 [ 0 ] |= 0x04 ;
V_57 = F_13 ( V_2 , 0xFD70 , V_6 , 1 ) ;
if ( V_57 != V_88 )
F_4 ( L_11 ) ;
} else {
F_4 ( L_13 ) ;
}
} else {
F_4 ( L_14 ) ;
}
}
F_4 ( L_9 , V_60 ) ;
}
static void F_30 ( struct V_65 * V_66 )
{
F_4 ( L_15 , V_60 , F_31 ( V_66 ) ) ;
V_66 -> V_89 = V_90 + F_32 ( 1000 * V_91 ) ;
F_33 ( & V_66 -> V_92 , V_66 -> V_89 ) ;
F_4 ( L_9 , V_60 ) ;
}
static void F_34 ( unsigned long V_55 )
{
struct V_65 * V_66 = (struct V_65 * ) V_55 ;
struct V_1 * V_2 = V_66 -> V_2 ;
F_4 ( L_8 , V_60 ) ;
switch ( F_31 ( V_66 ) ) {
case V_93 :
case V_94 :
F_30 ( V_66 ) ;
break;
case V_95 :
case V_96 :
F_4 ( L_16
L_17 , V_60 ,
F_35 ( & V_2 -> V_97 -> V_98 ) ,
F_35 ( & V_2 -> V_97 -> V_99 . V_100 . V_101 ) ) ;
if ( F_35 ( & V_2 -> V_97 -> V_98 ) > 0 ) {
F_4 ( L_18 ,
V_60 ) ;
F_36 ( V_66 , V_96 ) ;
F_37 ( & V_2 -> V_97 -> V_99 , true ) ;
F_38 ( V_2 -> V_97 ) ;
F_4 ( L_19
L_20 ,
V_60 ,
F_35 ( & V_2 -> V_97 -> V_98 ) ,
F_35 (
& V_2 -> V_97 -> V_99 . V_100 . V_101 ) ) ;
}
break;
default:
F_4 ( L_21 , V_60 ) ;
break;
}
F_4 ( L_9 , V_60 ) ;
}
static inline int F_39 ( struct V_102 * V_103 )
{
if ( ( V_103 -> V_58 [ 0 ] == V_104 ) ||
( V_103 -> V_58 [ 0 ] == V_105 ) ) {
return 0 ;
}
return 1 ;
}
static void F_40 ( struct V_102 * V_103 , struct V_1 * V_2 )
{
struct V_65 * V_66 = (struct V_65 * ) ( V_2 -> V_67 ) ;
static int V_106 = 1 ;
static T_1 V_107 [] = { 0x70 , 0 , 0x02 , 0 , 0 , 0 , 0 ,
10 , 0 , 0 , 0 , 0 , 0x3A , 0 , 0 , 0 , 0 , 0
} ;
static T_1 V_108 [] = { 0x70 , 0 , 0x05 , 0 , 0 , 0 , 0 ,
10 , 0 , 0 , 0 , 0 , 0x24 , 0 , 0 , 0 , 0 , 0
} ;
int V_109 ;
F_4 ( L_8 , V_60 ) ;
if ( F_39 ( V_103 ) ) {
F_4 ( L_22
L_17 , V_60 ,
F_35 ( & V_2 -> V_97 -> V_98 ) ,
F_35 ( & V_2 -> V_97 -> V_99 . V_100 . V_101 ) ) ;
if ( F_35 ( & V_2 -> V_97 -> V_98 ) <= 0 ) {
V_109 = F_41 ( V_2 -> V_97 ) ;
F_4 ( L_23 , V_60 , V_109 ) ;
}
if ( F_31 ( V_66 ) != V_94 )
F_36 ( V_66 , V_94 ) ;
V_66 -> V_110 ( V_103 , V_2 ) ;
} else {
if ( F_31 ( V_66 ) == V_96 ) {
F_4 ( L_24 , V_60 ) ;
if ( ( V_103 -> V_58 [ 0 ] == V_104 ) &&
( V_66 -> V_111 == V_112 ) ) {
if ( F_42 ( V_66 , V_103 -> V_113 -> V_3 ) ) {
V_103 -> V_16 = V_114 ;
} else {
V_103 -> V_16 = V_115 ;
memcpy ( V_103 -> V_116 ,
V_107 ,
V_117 ) ;
}
F_4 ( L_25 ,
V_60 ) ;
goto V_118;
}
if ( V_103 -> V_58 [ 0 ] == V_105 ) {
int V_119 = V_103 -> V_58 [ 4 ] & 0x1 ;
if ( V_119 ) {
V_103 -> V_16 = V_115 ;
memcpy ( V_103 -> V_116 ,
V_108 ,
V_117 ) ;
} else {
V_103 -> V_16 = V_114 ;
}
F_4 ( L_26 ,
V_60 ) ;
goto V_118;
}
} else {
F_4 ( L_27 , V_60 ) ;
V_66 -> V_110 ( V_103 , V_2 ) ;
if ( V_103 -> V_58 [ 0 ] == V_104 ) {
if ( V_103 -> V_16 == V_114 ) {
F_43 ( V_66 , V_103 -> V_113 -> V_3 ) ;
if ( V_106 ) {
V_106 = 0 ;
F_29 ( V_2 ) ;
}
} else {
F_44 ( V_66 , V_103 -> V_113 -> V_3 ) ;
V_106 = 1 ;
}
}
if ( F_31 ( V_66 ) != V_95 )
F_36 ( V_66 , V_95 ) ;
}
}
V_118:
F_4 ( L_28 , V_60 , F_31 ( V_66 ) ) ;
if ( F_31 ( V_66 ) == V_94 )
F_30 ( V_66 ) ;
F_4 ( L_9 , V_60 ) ;
}
static int F_45 ( struct V_1 * V_2 )
{
struct V_65 * V_66 ;
struct V_120 * V_63 = NULL ;
T_1 V_6 [ 16 ] ;
int V_57 ;
V_66 = (struct V_65 * ) V_2 -> V_67 ;
V_66 -> V_121 = 0 ;
V_66 -> V_111 = V_122 ;
V_66 -> V_123 = 0 ;
F_36 ( V_66 , V_93 ) ;
V_57 = F_15 ( V_2 , 0 , V_6 , 16 , & ( V_66 -> V_68 ) ) ;
if ( V_57 != V_88 ) {
F_4 ( L_29 ) ;
return - V_61 ;
}
V_63 = V_66 -> V_63 ;
V_63 -> V_69 = ( ( T_2 ) V_6 [ 0 ] << 8 ) | V_6 [ 1 ] ;
V_63 -> V_70 = ( ( T_2 ) V_6 [ 2 ] << 8 ) | V_6 [ 3 ] ;
V_63 -> V_71 = V_6 [ 4 ] ;
V_63 -> V_72 = V_6 [ 5 ] ;
V_63 -> V_73 = V_6 [ 6 ] ;
V_63 -> V_74 = ( ( T_2 ) V_6 [ 7 ] << 8 ) | V_6 [ 8 ] ;
V_63 -> V_75 = V_6 [ 9 ] ;
V_63 -> V_76 = V_6 [ 10 ] ;
V_63 -> V_77 = V_6 [ 11 ] ;
V_63 -> V_78 = V_6 [ 12 ] ;
if ( V_66 -> V_68 == 16 ) {
V_63 -> V_79 . V_80 = V_6 [ 13 ] ;
V_63 -> V_81 [ 0 ] = V_6 [ 14 ] ;
V_63 -> V_81 [ 1 ] = V_6 [ 15 ] ;
}
V_66 = (struct V_65 * ) ( V_2 -> V_67 ) ;
V_66 -> V_110 = V_2 -> V_124 ;
F_46 ( & V_2 -> V_46 -> V_99 , 0 ) ;
V_2 -> V_124 = F_40 ;
V_66 -> V_89 = 0 ;
F_47 ( & V_66 -> V_92 , F_34 ,
( unsigned long ) V_66 ) ;
F_26 ( V_2 ) ;
F_48 ( V_2 -> V_46 ) ;
return 0 ;
}
static void F_49 ( void * V_67 )
{
struct V_65 * V_66 = (struct V_65 * ) V_67 ;
F_4 ( L_8 , V_60 ) ;
if ( ! V_66 )
return;
#ifdef F_50
if ( V_125 ) {
F_51 ( & V_66 -> V_92 ) ;
V_66 -> V_89 = 0 ;
}
#endif
F_12 ( V_66 -> V_63 ) ;
}
static int F_52 ( struct V_126 * V_127 , T_3 V_128 )
{
struct V_1 * V_2 = F_53 ( V_127 ) ;
F_4 ( L_8 , V_60 ) ;
F_54 ( & V_2 -> V_129 ) ;
F_25 ( V_2 ) ;
F_55 ( & V_2 -> V_129 ) ;
F_4 ( L_9 , V_60 ) ;
return 0 ;
}
static int F_56 ( struct V_126 * V_127 )
{
struct V_1 * V_2 = F_53 ( V_127 ) ;
F_4 ( L_8 , V_60 ) ;
F_26 ( V_2 ) ;
F_20 ( V_2 ) ;
F_4 ( L_9 , V_60 ) ;
return 0 ;
}
static int F_57 ( struct V_1 * V_2 )
{
struct V_65 * V_66 ;
int V_130 , V_131 , V_57 ;
V_66 = F_58 ( sizeof( struct V_65 ) , V_132 ) ;
if ( ! V_66 )
return - V_133 ;
V_2 -> V_67 = V_66 ;
V_2 -> V_134 = F_49 ;
V_2 -> V_135 = V_66 -> V_135 = F_8 ( V_2 ) ;
F_4 ( L_30 , V_66 -> V_135 ) ;
V_130 = ( V_66 -> V_135 + 1 ) * sizeof( struct V_120 ) ;
V_66 -> V_63 = F_58 ( V_130 , V_132 ) ;
if ( ! V_66 -> V_63 )
goto V_136;
for ( V_131 = 0 ; V_131 <= ( int ) ( V_66 -> V_135 ) ; V_131 ++ ) {
V_57 = F_16 ( V_2 , ( T_1 ) V_131 ) ;
if ( V_57 < 0 )
goto V_136;
}
if ( F_59 ( V_66 , 0x5888 ) || F_59 ( V_66 , 0x5889 ) ||
F_59 ( V_66 , 0x5901 ) )
F_60 ( V_66 ) ;
if ( F_61 ( V_66 ) == 16 ) {
if ( F_62 ( V_66 ) )
F_60 ( V_66 ) ;
}
#ifdef F_50
if ( V_125 ) {
V_66 -> V_2 = V_2 ;
F_45 ( V_2 ) ;
}
#endif
F_4 ( L_31 , V_66 -> V_137 ) ;
( void ) F_20 ( V_2 ) ;
return 0 ;
V_136:
if ( V_2 -> V_67 ) {
F_12 ( V_66 -> V_63 ) ;
F_12 ( V_2 -> V_67 ) ;
V_2 -> V_67 = NULL ;
}
return - V_61 ;
}
static int F_63 ( struct V_126 * V_138 ,
const struct V_139 * V_140 )
{
struct V_1 * V_2 ;
int V_16 ;
F_4 ( L_32 ) ;
V_16 = F_64 ( & V_2 , V_138 , V_140 ,
( V_140 - V_141 ) +
V_142 ) ;
if ( V_16 )
return V_16 ;
V_16 = F_65 ( V_2 ) ;
return V_16 ;
}
