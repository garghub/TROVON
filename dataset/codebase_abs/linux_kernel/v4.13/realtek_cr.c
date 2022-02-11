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
V_12 -> V_24 = ( V_9 == V_25 ) ? V_26 : 0 ;
V_12 -> V_27 = ++ V_2 -> V_28 ;
V_12 -> V_29 = V_3 ;
V_12 -> V_30 = V_5 ;
memset ( V_12 -> V_31 , 0 , sizeof( V_12 -> V_31 ) ) ;
memcpy ( V_12 -> V_31 , V_4 , V_12 -> V_30 ) ;
V_16 = F_3 ( V_2 , V_2 -> V_32 ,
V_12 , V_19 , NULL ) ;
if ( V_16 != V_33 )
return V_34 ;
if ( V_6 && V_7 ) {
unsigned int V_35 = ( V_9 == V_25 ) ?
V_2 -> V_36 : V_2 -> V_32 ;
V_16 = F_3 ( V_2 , V_35 ,
V_6 , V_7 , NULL ) ;
if ( V_16 == V_37 )
return V_34 ;
}
V_16 = F_3 ( V_2 , V_2 -> V_36 ,
V_15 , V_38 , & V_18 ) ;
if ( V_16 != V_33 )
return V_34 ;
if ( V_15 -> V_21 != F_2 ( V_39 ) ) {
F_4 ( V_2 , L_1 ,
F_5 ( V_15 -> V_21 ) , V_39 ) ;
return V_34 ;
}
V_17 = V_15 -> V_40 ;
if ( V_15 -> V_27 != V_2 -> V_28 )
return V_34 ;
if ( V_17 )
V_17 = V_17 < V_7 ? V_17 : V_7 ;
if ( V_10 )
* V_10 = V_7 - V_17 ;
switch ( V_15 -> V_41 ) {
case V_42 :
return V_43 ;
case V_44 :
return V_45 ;
case V_46 :
return V_34 ;
}
return V_34 ;
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
V_12 -> V_24 = ( V_9 == V_25 ) ? V_26 : 0 ;
V_12 -> V_27 = ++ V_2 -> V_28 ;
V_12 -> V_29 = V_3 ;
V_12 -> V_30 = V_5 ;
memset ( V_12 -> V_31 , 0 , sizeof( V_12 -> V_31 ) ) ;
memcpy ( V_12 -> V_31 , V_4 , V_12 -> V_30 ) ;
V_16 = F_3 ( V_2 , V_2 -> V_32 ,
V_12 , V_19 , NULL ) ;
if ( V_16 != V_33 )
return V_34 ;
if ( V_6 && V_7 ) {
unsigned int V_35 = ( V_9 == V_25 ) ?
V_2 -> V_36 : V_2 -> V_32 ;
V_16 = F_3 ( V_2 , V_35 ,
V_6 , V_7 , NULL ) ;
if ( V_16 == V_37 )
return V_34 ;
}
V_16 = F_7 ( V_2 -> V_47 , V_2 -> V_36 , V_15 ,
V_38 , & V_18 , 250 ) ;
return V_16 ;
}
static int F_8 ( struct V_1 * V_2 )
{
int V_16 ;
V_2 -> V_13 [ 0 ] = 0 ;
V_16 = F_9 ( V_2 , V_2 -> V_48 ,
V_49 ,
V_50 | V_51 |
V_52 ,
0 , V_2 -> V_53 , V_2 -> V_13 , 1 , 10 * V_54 ) ;
F_4 ( V_2 , L_2 ,
V_16 , V_2 -> V_13 [ 0 ] ) ;
if ( V_16 > 0 )
return V_2 -> V_13 [ 0 ] ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 , T_2 V_55 , T_1 * V_56 , T_2 V_57 )
{
int V_58 ;
T_1 V_59 [ 12 ] = { 0 } ;
T_1 * V_6 ;
V_6 = F_11 ( V_57 , V_60 ) ;
if ( V_6 == NULL )
return V_34 ;
F_4 ( V_2 , L_3 , V_55 , V_57 ) ;
V_59 [ 0 ] = 0xF0 ;
V_59 [ 1 ] = 0x0D ;
V_59 [ 2 ] = ( T_1 ) ( V_55 >> 8 ) ;
V_59 [ 3 ] = ( T_1 ) V_55 ;
V_59 [ 4 ] = ( T_1 ) ( V_57 >> 8 ) ;
V_59 [ 5 ] = ( T_1 ) V_57 ;
V_58 = F_1 ( V_2 , 0 , V_59 , 12 ,
V_6 , V_57 , V_25 , NULL ) ;
if ( V_58 != V_43 ) {
F_12 ( V_6 ) ;
return - V_61 ;
}
memcpy ( V_56 , V_6 , V_57 ) ;
F_12 ( V_6 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 , T_2 V_55 , T_1 * V_56 , T_2 V_57 )
{
int V_58 ;
T_1 V_59 [ 12 ] = { 0 } ;
T_1 * V_6 ;
V_6 = F_14 ( V_56 , V_57 , V_60 ) ;
if ( V_6 == NULL )
return V_34 ;
F_4 ( V_2 , L_3 , V_55 , V_57 ) ;
V_59 [ 0 ] = 0xF0 ;
V_59 [ 1 ] = 0x0E ;
V_59 [ 2 ] = ( T_1 ) ( V_55 >> 8 ) ;
V_59 [ 3 ] = ( T_1 ) V_55 ;
V_59 [ 4 ] = ( T_1 ) ( V_57 >> 8 ) ;
V_59 [ 5 ] = ( T_1 ) V_57 ;
V_58 = F_1 ( V_2 , 0 , V_59 , 12 ,
V_6 , V_57 , V_62 , NULL ) ;
F_12 ( V_6 ) ;
if ( V_58 != V_43 )
return - V_61 ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 * V_63 , int V_57 , int * V_64 )
{
int V_58 ;
T_1 V_59 [ 12 ] = { 0 } ;
T_1 * V_6 ;
V_6 = F_11 ( V_57 , V_60 ) ;
if ( V_6 == NULL )
return V_34 ;
F_4 ( V_2 , L_4 , V_3 ) ;
V_59 [ 0 ] = 0xF0 ;
V_59 [ 1 ] = 0x09 ;
V_58 = F_1 ( V_2 , V_3 , V_59 , 12 ,
V_6 , V_57 , V_25 , V_64 ) ;
if ( V_58 != V_43 ) {
F_12 ( V_6 ) ;
return - V_61 ;
}
memcpy ( V_63 , V_6 , V_57 ) ;
F_12 ( V_6 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_65 * V_66 = (struct V_65 * ) ( V_2 -> V_67 ) ;
int V_58 ;
T_1 V_6 [ 16 ] ;
V_58 = F_15 ( V_2 , V_3 , V_6 , 16 , & ( V_66 -> V_68 ) ) ;
if ( V_58 != V_69 )
return - V_61 ;
F_4 ( V_2 , L_5 , V_66 -> V_68 ) ;
V_66 -> V_63 [ V_3 ] . V_70 = ( ( T_2 ) V_6 [ 0 ] << 8 ) | V_6 [ 1 ] ;
V_66 -> V_63 [ V_3 ] . V_71 = ( ( T_2 ) V_6 [ 2 ] << 8 ) | V_6 [ 3 ] ;
V_66 -> V_63 [ V_3 ] . V_72 = V_6 [ 4 ] ;
V_66 -> V_63 [ V_3 ] . V_73 = V_6 [ 5 ] ;
V_66 -> V_63 [ V_3 ] . V_74 = V_6 [ 6 ] ;
V_66 -> V_63 [ V_3 ] . V_75 = ( ( T_2 ) V_6 [ 7 ] << 8 ) | V_6 [ 8 ] ;
V_66 -> V_63 [ V_3 ] . V_76 = V_6 [ 9 ] ;
V_66 -> V_63 [ V_3 ] . V_77 = V_6 [ 10 ] ;
V_66 -> V_63 [ V_3 ] . V_78 = V_6 [ 11 ] ;
V_66 -> V_63 [ V_3 ] . V_79 = V_6 [ 12 ] ;
if ( V_66 -> V_68 == 16 ) {
V_66 -> V_63 [ V_3 ] . V_80 . V_81 = V_6 [ 13 ] ;
V_66 -> V_63 [ V_3 ] . V_82 [ 0 ] = V_6 [ 14 ] ;
V_66 -> V_63 [ V_3 ] . V_82 [ 1 ] = V_6 [ 15 ] ;
}
return 0 ;
}
static int F_17 ( struct V_1 * V_2 )
{
int V_58 ;
T_1 V_83 ;
V_58 = F_10 ( V_2 , 0xFE77 , & V_83 , 1 ) ;
if ( V_58 < 0 )
return - V_61 ;
V_83 |= 0x04 ;
V_58 = F_13 ( V_2 , 0xFE77 , & V_83 , 1 ) ;
if ( V_58 < 0 )
return - V_61 ;
V_58 = F_10 ( V_2 , 0xFE77 , & V_83 , 1 ) ;
if ( V_58 < 0 )
return - V_61 ;
if ( ! ( V_83 & 0x04 ) )
return - V_61 ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 , T_1 * V_56 , T_2 V_57 )
{
int V_58 ;
T_1 V_59 [ 12 ] = { 0 } ;
T_1 * V_6 ;
F_4 ( V_2 , L_6 , V_57 ) ;
V_6 = F_14 ( V_56 , V_57 , V_60 ) ;
if ( ! V_6 )
return V_34 ;
V_59 [ 0 ] = 0xF0 ;
V_59 [ 1 ] = 0x0E ;
V_59 [ 2 ] = 0xfe ;
V_59 [ 3 ] = 0x47 ;
V_59 [ 4 ] = ( T_1 ) ( V_57 >> 8 ) ;
V_59 [ 5 ] = ( T_1 ) V_57 ;
V_58 = F_6 ( V_2 , 0 , V_59 , 12 , V_6 , V_57 , V_62 , NULL ) ;
F_12 ( V_6 ) ;
if ( V_58 != V_43 ) {
return - V_61 ;
}
return 0 ;
}
static int F_19 ( struct V_1 * V_2 , int V_84 , int V_85 )
{
int V_58 ;
T_1 V_83 ;
V_58 = F_10 ( V_2 , 0xFE47 , & V_83 , 1 ) ;
if ( V_58 < 0 )
return - V_61 ;
if ( V_84 ) {
if ( V_85 )
V_83 |= 0x03 ;
else
V_83 |= 0x01 ;
} else {
V_83 &= ~ 0x03 ;
}
F_4 ( V_2 , L_7 , V_83 ) ;
V_58 = F_18 ( V_2 , & V_83 , 1 ) ;
if ( V_58 < 0 )
return - V_61 ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 )
{
struct V_65 * V_66 = (struct V_65 * ) ( V_2 -> V_67 ) ;
int V_58 ;
T_1 V_83 ;
if ( ! F_21 ( V_66 ) )
return 0 ;
V_58 = F_10 ( V_2 , 0xFE47 , & V_83 , 1 ) ;
if ( V_58 < 0 )
return - V_61 ;
if ( V_86 ) {
F_22 ( V_83 , 0 ) ;
F_22 ( V_83 , 1 ) ;
F_23 ( V_83 , 2 ) ;
if ( F_24 ( V_66 , 0x0138 , 0x3882 ) )
F_22 ( V_83 , 2 ) ;
F_23 ( V_83 , 7 ) ;
V_58 = F_18 ( V_2 , & V_83 , 1 ) ;
if ( V_58 < 0 )
return - V_61 ;
V_58 = F_17 ( V_2 ) ;
if ( V_58 == 0 )
( void ) F_19 ( V_2 , 1 , 0 ) ;
} else {
F_23 ( V_83 , 2 ) ;
if ( F_24 ( V_66 , 0x0138 , 0x3882 ) )
F_22 ( V_83 , 2 ) ;
if ( F_24 ( V_66 , 0x0159 , 0x5889 ) ||
F_24 ( V_66 , 0x0138 , 0x3880 ) ) {
F_22 ( V_83 , 0 ) ;
F_22 ( V_83 , 7 ) ;
}
V_58 = F_18 ( V_2 , & V_83 , 1 ) ;
if ( V_58 < 0 )
return - V_61 ;
if ( F_24 ( V_66 , 0x0159 , 0x5888 ) ) {
V_83 = 0xFF ;
V_58 = F_13 ( V_2 , 0xFE79 , & V_83 , 1 ) ;
if ( V_58 < 0 )
return - V_61 ;
V_83 = 0x01 ;
V_58 = F_13 ( V_2 , 0x48 , & V_83 , 1 ) ;
if ( V_58 < 0 )
return - V_61 ;
}
}
return 0 ;
}
static int F_25 ( struct V_1 * V_2 )
{
struct V_65 * V_66 = (struct V_65 * ) ( V_2 -> V_67 ) ;
int V_58 ;
T_1 V_83 ;
if ( ! F_21 ( V_66 ) )
return 0 ;
if ( V_86 ) {
V_58 = F_10 ( V_2 , 0xFE77 , & V_83 , 1 ) ;
if ( V_58 < 0 )
return - V_61 ;
F_23 ( V_83 , 2 ) ;
V_58 = F_13 ( V_2 , 0xFE77 , & V_83 , 1 ) ;
if ( V_58 < 0 )
return - V_61 ;
if ( F_24 ( V_66 , 0x0159 , 0x5888 ) ) {
V_83 = 0x01 ;
V_58 = F_13 ( V_2 , 0x48 , & V_83 , 1 ) ;
if ( V_58 < 0 )
return - V_61 ;
}
V_58 = F_10 ( V_2 , 0xFE47 , & V_83 , 1 ) ;
if ( V_58 < 0 )
return - V_61 ;
F_23 ( V_83 , 0 ) ;
if ( F_24 ( V_66 , 0x0138 , 0x3882 ) )
F_23 ( V_83 , 2 ) ;
V_58 = F_13 ( V_2 , 0xFE77 , & V_83 , 1 ) ;
if ( V_58 < 0 )
return - V_61 ;
} else {
if ( F_24 ( V_66 , 0x0159 , 0x5889 ) ||
F_24 ( V_66 , 0x0138 , 0x3880 ) ||
F_24 ( V_66 , 0x0138 , 0x3882 ) ) {
V_58 = F_10 ( V_2 , 0xFE47 , & V_83 , 1 ) ;
if ( V_58 < 0 )
return - V_61 ;
if ( F_24 ( V_66 , 0x0159 , 0x5889 ) ||
F_24 ( V_66 , 0x0138 , 0x3880 ) ) {
F_23 ( V_83 , 0 ) ;
F_23 ( V_83 , 7 ) ;
}
if ( F_24 ( V_66 , 0x0138 , 0x3882 ) )
F_23 ( V_83 , 2 ) ;
V_58 = F_18 ( V_2 , & V_83 , 1 ) ;
if ( V_58 < 0 )
return - V_61 ;
}
if ( F_24 ( V_66 , 0x0159 , 0x5888 ) ) {
V_83 = 0x01 ;
V_58 = F_13 ( V_2 , 0x48 , & V_83 , 1 ) ;
if ( V_58 < 0 )
return - V_61 ;
}
}
return 0 ;
}
static void F_26 ( struct V_1 * V_2 )
{
struct V_65 * V_66 = (struct V_65 * ) ( V_2 -> V_67 ) ;
int V_58 ;
T_1 V_87 ;
if ( ( F_27 ( V_66 ) != 0x0158 ) || ( F_28 ( V_66 ) != 0x5895 ) ) {
F_4 ( V_2 , L_8 ) ;
} else {
V_58 = F_10 ( V_2 , 0xFD6F , & V_87 , 1 ) ;
if ( V_58 == V_69 && ( V_87 & 0x1F ) == 0 ) {
V_87 = 0x1F ;
V_58 = F_13 ( V_2 , 0xFD70 , & V_87 , 1 ) ;
if ( V_58 != V_69 )
F_4 ( V_2 , L_9 ) ;
} else {
F_4 ( V_2 , L_10 ) ;
}
}
}
static void F_29 ( struct V_1 * V_2 )
{
struct V_65 * V_66 = (struct V_65 * ) ( V_2 -> V_67 ) ;
int V_58 ;
T_1 V_6 [ 13 ] ;
if ( ( F_27 ( V_66 ) != 0x0158 ) || ( F_28 ( V_66 ) != 0x5895 ) ) {
F_4 ( V_2 , L_8 ) ;
} else {
V_58 = F_10 ( V_2 , 0xFD6F , V_6 , 1 ) ;
if ( V_58 == V_69 && ( V_6 [ 0 ] & 0x24 ) == 0x24 ) {
V_58 = F_10 ( V_2 , 0xD04E , V_6 , 1 ) ;
if ( V_58 == V_69 ) {
V_6 [ 0 ] |= 0x04 ;
V_58 = F_13 ( V_2 , 0xFD70 , V_6 , 1 ) ;
if ( V_58 != V_69 )
F_4 ( V_2 , L_9 ) ;
} else {
F_4 ( V_2 , L_11 ) ;
}
} else {
F_4 ( V_2 , L_12 ) ;
}
}
}
static void F_30 ( struct V_65 * V_66 )
{
struct V_1 * V_2 = V_66 -> V_2 ;
F_4 ( V_2 , L_13 , F_31 ( V_66 ) ) ;
V_66 -> V_88 = V_89 + F_32 ( 1000 * V_90 ) ;
F_33 ( & V_66 -> V_91 , V_66 -> V_88 ) ;
}
static void F_34 ( unsigned long V_56 )
{
struct V_65 * V_66 = (struct V_65 * ) V_56 ;
struct V_1 * V_2 = V_66 -> V_2 ;
switch ( F_31 ( V_66 ) ) {
case V_92 :
case V_93 :
F_30 ( V_66 ) ;
break;
case V_94 :
case V_95 :
F_4 ( V_2 , L_14 ,
F_35 ( & V_2 -> V_96 -> V_97 ) ,
F_35 ( & V_2 -> V_96 -> V_98 . V_99 . V_100 ) ) ;
if ( F_35 ( & V_2 -> V_96 -> V_97 ) > 0 ) {
F_4 ( V_2 , L_15 ) ;
F_36 ( V_66 , V_95 ) ;
F_37 ( & V_2 -> V_96 -> V_98 , true ) ;
F_38 ( V_2 -> V_96 ) ;
F_4 ( V_2 , L_16 ,
F_35 ( & V_2 -> V_96 -> V_97 ) ,
F_35 ( & V_2 -> V_96 -> V_98 . V_99 . V_100 ) ) ;
}
break;
default:
F_4 ( V_2 , L_17 ) ;
break;
}
}
static inline int F_39 ( struct V_101 * V_102 )
{
if ( ( V_102 -> V_59 [ 0 ] == V_103 ) ||
( V_102 -> V_59 [ 0 ] == V_104 ) ) {
return 0 ;
}
return 1 ;
}
static void F_40 ( struct V_101 * V_102 , struct V_1 * V_2 )
{
struct V_65 * V_66 = (struct V_65 * ) ( V_2 -> V_67 ) ;
static int V_105 = 1 ;
static T_1 V_106 [] = { 0x70 , 0 , 0x02 , 0 , 0 , 0 , 0 ,
10 , 0 , 0 , 0 , 0 , 0x3A , 0 , 0 , 0 , 0 , 0
} ;
static T_1 V_107 [] = { 0x70 , 0 , 0x05 , 0 , 0 , 0 , 0 ,
10 , 0 , 0 , 0 , 0 , 0x24 , 0 , 0 , 0 , 0 , 0
} ;
int V_108 ;
if ( F_39 ( V_102 ) ) {
F_4 ( V_2 , L_18 ,
F_35 ( & V_2 -> V_96 -> V_97 ) ,
F_35 ( & V_2 -> V_96 -> V_98 . V_99 . V_100 ) ) ;
if ( F_35 ( & V_2 -> V_96 -> V_97 ) <= 0 ) {
V_108 = F_41 ( V_2 -> V_96 ) ;
F_4 ( V_2 , L_19 , V_108 ) ;
}
if ( F_31 ( V_66 ) != V_93 )
F_36 ( V_66 , V_93 ) ;
V_66 -> V_109 ( V_102 , V_2 ) ;
} else {
if ( F_31 ( V_66 ) == V_95 ) {
F_4 ( V_2 , L_20 ) ;
if ( ( V_102 -> V_59 [ 0 ] == V_103 ) &&
( V_66 -> V_110 == V_111 ) ) {
if ( F_42 ( V_66 , V_102 -> V_112 -> V_3 ) ) {
V_102 -> V_16 = V_113 ;
} else {
V_102 -> V_16 = V_114 ;
memcpy ( V_102 -> V_115 ,
V_106 ,
V_116 ) ;
}
F_4 ( V_2 , L_21 ) ;
goto V_117;
}
if ( V_102 -> V_59 [ 0 ] == V_104 ) {
int V_118 = V_102 -> V_59 [ 4 ] & 0x1 ;
if ( V_118 ) {
V_102 -> V_16 = V_114 ;
memcpy ( V_102 -> V_115 ,
V_107 ,
V_116 ) ;
} else {
V_102 -> V_16 = V_113 ;
}
F_4 ( V_2 , L_22 ) ;
goto V_117;
}
} else {
F_4 ( V_2 , L_23 ) ;
V_66 -> V_109 ( V_102 , V_2 ) ;
if ( V_102 -> V_59 [ 0 ] == V_103 ) {
if ( V_102 -> V_16 == V_113 ) {
F_43 ( V_66 , V_102 -> V_112 -> V_3 ) ;
if ( V_105 ) {
V_105 = 0 ;
F_29 ( V_2 ) ;
}
} else {
F_44 ( V_66 , V_102 -> V_112 -> V_3 ) ;
V_105 = 1 ;
}
}
if ( F_31 ( V_66 ) != V_94 )
F_36 ( V_66 , V_94 ) ;
}
}
V_117:
F_4 ( V_2 , L_13 , F_31 ( V_66 ) ) ;
if ( F_31 ( V_66 ) == V_93 )
F_30 ( V_66 ) ;
}
static int F_45 ( struct V_1 * V_2 )
{
struct V_65 * V_66 ;
struct V_119 * V_63 = NULL ;
T_1 V_6 [ 16 ] ;
int V_58 ;
V_66 = (struct V_65 * ) V_2 -> V_67 ;
V_66 -> V_120 = 0 ;
V_66 -> V_110 = V_121 ;
V_66 -> V_122 = 0 ;
F_36 ( V_66 , V_92 ) ;
V_58 = F_15 ( V_2 , 0 , V_6 , 16 , & ( V_66 -> V_68 ) ) ;
if ( V_58 != V_69 ) {
F_4 ( V_2 , L_24 ) ;
return - V_61 ;
}
V_63 = V_66 -> V_63 ;
V_63 -> V_70 = ( ( T_2 ) V_6 [ 0 ] << 8 ) | V_6 [ 1 ] ;
V_63 -> V_71 = ( ( T_2 ) V_6 [ 2 ] << 8 ) | V_6 [ 3 ] ;
V_63 -> V_72 = V_6 [ 4 ] ;
V_63 -> V_73 = V_6 [ 5 ] ;
V_63 -> V_74 = V_6 [ 6 ] ;
V_63 -> V_75 = ( ( T_2 ) V_6 [ 7 ] << 8 ) | V_6 [ 8 ] ;
V_63 -> V_76 = V_6 [ 9 ] ;
V_63 -> V_77 = V_6 [ 10 ] ;
V_63 -> V_78 = V_6 [ 11 ] ;
V_63 -> V_79 = V_6 [ 12 ] ;
if ( V_66 -> V_68 == 16 ) {
V_63 -> V_80 . V_81 = V_6 [ 13 ] ;
V_63 -> V_82 [ 0 ] = V_6 [ 14 ] ;
V_63 -> V_82 [ 1 ] = V_6 [ 15 ] ;
}
V_66 = (struct V_65 * ) ( V_2 -> V_67 ) ;
V_66 -> V_109 = V_2 -> V_123 ;
F_46 ( & V_2 -> V_47 -> V_98 , 0 ) ;
V_2 -> V_123 = F_40 ;
V_66 -> V_88 = 0 ;
F_47 ( & V_66 -> V_91 , F_34 ,
( unsigned long ) V_66 ) ;
F_26 ( V_2 ) ;
F_48 ( V_2 -> V_47 ) ;
return 0 ;
}
static void F_49 ( void * V_67 )
{
struct V_65 * V_66 = V_67 ;
if ( ! V_66 )
return;
#ifdef F_50
if ( V_124 ) {
F_51 ( & V_66 -> V_91 ) ;
V_66 -> V_88 = 0 ;
}
#endif
F_12 ( V_66 -> V_63 ) ;
}
static int F_52 ( struct V_125 * V_126 , T_3 V_127 )
{
struct V_1 * V_2 = F_53 ( V_126 ) ;
F_54 ( & V_2 -> V_128 ) ;
F_25 ( V_2 ) ;
F_55 ( & V_2 -> V_128 ) ;
return 0 ;
}
static int F_56 ( struct V_125 * V_126 )
{
struct V_1 * V_2 = F_53 ( V_126 ) ;
F_26 ( V_2 ) ;
F_20 ( V_2 ) ;
return 0 ;
}
static int F_57 ( struct V_1 * V_2 )
{
struct V_65 * V_66 ;
int V_129 , V_130 , V_58 ;
V_66 = F_58 ( sizeof( struct V_65 ) , V_131 ) ;
if ( ! V_66 )
return - V_132 ;
V_2 -> V_67 = V_66 ;
V_2 -> V_133 = F_49 ;
V_2 -> V_134 = V_66 -> V_134 = F_8 ( V_2 ) ;
V_66 -> V_2 = V_2 ;
F_4 ( V_2 , L_25 , V_66 -> V_134 ) ;
V_129 = ( V_66 -> V_134 + 1 ) * sizeof( struct V_119 ) ;
V_66 -> V_63 = F_58 ( V_129 , V_131 ) ;
if ( ! V_66 -> V_63 )
goto V_135;
for ( V_130 = 0 ; V_130 <= ( int ) ( V_66 -> V_134 ) ; V_130 ++ ) {
V_58 = F_16 ( V_2 , ( T_1 ) V_130 ) ;
if ( V_58 < 0 )
goto V_135;
}
if ( F_59 ( V_66 , 0x5888 ) || F_59 ( V_66 , 0x5889 ) ||
F_59 ( V_66 , 0x5901 ) )
F_60 ( V_66 ) ;
if ( F_61 ( V_66 ) == 16 ) {
if ( F_62 ( V_66 ) )
F_60 ( V_66 ) ;
}
#ifdef F_50
if ( V_124 )
F_45 ( V_2 ) ;
#endif
F_4 ( V_2 , L_26 , V_66 -> V_136 ) ;
( void ) F_20 ( V_2 ) ;
return 0 ;
V_135:
if ( V_2 -> V_67 ) {
F_12 ( V_66 -> V_63 ) ;
F_12 ( V_2 -> V_67 ) ;
V_2 -> V_67 = NULL ;
}
return - V_61 ;
}
static int F_63 ( struct V_125 * V_137 ,
const struct V_138 * V_139 )
{
struct V_1 * V_2 ;
int V_16 ;
F_64 ( & V_137 -> V_98 , L_27 ) ;
V_16 = F_65 ( & V_2 , V_137 , V_139 ,
( V_139 - V_140 ) +
V_141 ,
& V_142 ) ;
if ( V_16 )
return V_16 ;
V_16 = F_66 ( V_2 ) ;
return V_16 ;
}
