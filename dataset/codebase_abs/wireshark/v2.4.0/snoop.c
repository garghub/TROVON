T_1 F_1 ( T_2 * V_1 , int * V_2 , T_3 * * V_3 )
{
char V_4 [ sizeof F_2 ] ;
struct V_5 V_6 ;
struct V_7 V_8 ;
T_4 V_9 ;
T_5 V_10 ;
static const int V_11 [] = {
V_12 ,
V_13 ,
V_14 ,
V_13 ,
V_12 ,
V_13 ,
V_13 ,
V_13 ,
V_15 ,
V_16 ,
V_13 ,
V_13 ,
V_13 ,
V_13 ,
V_16 ,
V_13 ,
V_17 ,
V_13 ,
V_18 ,
V_13 ,
V_13 ,
V_13 ,
V_13 ,
V_13 ,
V_13 ,
V_13 ,
V_19 ,
} ;
#define F_3 (sizeof snoop_encap / sizeof snoop_encap[0])
#define F_4 0x80000000
static const int V_20 [] = {
V_13 ,
V_13 ,
V_13 ,
V_13 ,
V_13 ,
V_21 ,
V_13 ,
V_13 ,
} ;
#define F_5 (sizeof snoop_private_encap / sizeof snoop_private_encap[0])
static const int V_22 [] = {
V_12 ,
V_13 ,
V_14 ,
V_13 ,
V_12 ,
V_13 ,
V_13 ,
V_13 ,
V_15 ,
V_13 ,
V_12 ,
V_14 ,
V_12 ,
V_14 ,
V_14 ,
V_13 ,
V_13 ,
V_13 ,
V_23 ,
V_12 ,
} ;
#define F_6 (sizeof shomiti_encap / sizeof shomiti_encap[0])
int V_24 ;
T_6 V_25 ;
if ( ! F_7 ( V_1 -> V_26 , V_4 , sizeof V_4 , V_2 , V_3 ) ) {
if ( * V_2 != V_27 )
return V_28 ;
return V_29 ;
}
if ( memcmp ( V_4 , F_2 , sizeof F_2 ) != 0 ) {
return V_29 ;
}
if ( ! F_7 ( V_1 -> V_26 , & V_6 , sizeof V_6 , V_2 , V_3 ) )
return V_28 ;
V_6 . V_30 = F_8 ( V_6 . V_30 ) ;
switch ( V_6 . V_30 ) {
case 2 :
case 3 :
case 4 :
case 5 :
break;
default:
* V_2 = V_31 ;
* V_3 = F_9 ( L_1 , V_6 . V_30 ) ;
return V_28 ;
}
V_10 = FALSE ;
V_25 = F_10 ( V_1 -> V_26 ) ;
if ( ! F_11 ( V_1 -> V_26 , & V_8 , sizeof V_8 , V_2 , V_3 ) ) {
if ( * V_2 != 0 )
return V_28 ;
} else {
if ( F_8 ( V_8 . V_32 ) >
( sizeof V_8 + F_8 ( V_8 . V_33 ) ) ) {
V_9 = F_8 ( V_8 . V_32 ) -
( ( T_4 ) sizeof V_8 + F_8 ( V_8 . V_33 ) ) ;
V_10 =
( V_9 >= sizeof ( struct V_34 ) ) ;
}
}
if ( F_12 ( V_1 -> V_26 , V_25 , V_35 , V_2 ) == - 1 )
return V_28 ;
V_6 . V_36 = F_8 ( V_6 . V_36 ) ;
if ( V_10 ) {
if ( V_6 . V_36 >= F_6
|| V_22 [ V_6 . V_36 ] == V_13 ) {
* V_2 = V_31 ;
* V_3 = F_9 ( L_2 ,
V_6 . V_36 ) ;
return V_28 ;
}
V_24 = V_22 [ V_6 . V_36 ] ;
V_1 -> V_37 = V_38 ;
} else if ( V_6 . V_36 & F_4 ) {
if ( ( V_6 . V_36 ^ F_4 ) >= F_5
|| V_20 [ V_6 . V_36 ^ F_4 ] == V_13 ) {
* V_2 = V_31 ;
* V_3 = F_9 ( L_3 ,
V_6 . V_36 ) ;
return V_28 ;
}
V_24 = V_20 [ V_6 . V_36 ^ F_4 ] ;
V_1 -> V_37 = V_39 ;
} else {
if ( V_6 . V_36 >= F_3
|| V_11 [ V_6 . V_36 ] == V_13 ) {
* V_2 = V_31 ;
* V_3 = F_9 ( L_4 ,
V_6 . V_36 ) ;
return V_28 ;
}
V_24 = V_11 [ V_6 . V_36 ] ;
V_1 -> V_37 = V_39 ;
}
V_1 -> V_40 = V_41 ;
V_1 -> V_42 = V_43 ;
V_1 -> V_24 = V_24 ;
V_1 -> V_44 = 0 ;
V_1 -> V_45 = V_46 ;
return V_47 ;
}
static T_5 V_41 ( T_2 * V_1 , int * V_2 , T_3 * * V_3 ,
T_6 * V_48 )
{
int V_9 ;
* V_48 = F_10 ( V_1 -> V_26 ) ;
V_9 = F_13 ( V_1 , V_1 -> V_26 , & V_1 -> V_49 ,
V_1 -> V_50 , V_2 , V_3 ) ;
if ( V_9 == - 1 )
return FALSE ;
if ( V_9 != 0 ) {
if ( ! F_7 ( V_1 -> V_26 , NULL , V_9 , V_2 , V_3 ) )
return FALSE ;
}
return TRUE ;
}
static T_5
V_43 ( T_2 * V_1 , T_6 V_51 ,
struct V_52 * V_49 , T_7 * V_53 , int * V_2 , T_3 * * V_3 )
{
if ( F_12 ( V_1 -> V_54 , V_51 , V_35 , V_2 ) == - 1 )
return FALSE ;
if ( F_13 ( V_1 , V_1 -> V_54 , V_49 , V_53 , V_2 , V_3 ) == - 1 ) {
if ( * V_2 == 0 )
* V_2 = V_27 ;
return FALSE ;
}
return TRUE ;
}
static int
F_13 ( T_2 * V_1 , T_8 V_26 , struct V_52 * V_49 ,
T_7 * V_53 , int * V_2 , T_3 * * V_3 )
{
struct V_7 V_6 ;
T_9 V_55 ;
T_9 V_56 ;
T_9 V_57 ;
int V_58 ;
if ( ! F_11 ( V_26 , & V_6 , sizeof V_6 , V_2 , V_3 ) )
return - 1 ;
V_55 = F_8 ( V_6 . V_32 ) ;
V_57 = F_8 ( V_6 . V_59 ) ;
V_56 = F_8 ( V_6 . V_33 ) ;
if ( V_57 > V_60 ) {
* V_2 = V_61 ;
* V_3 = F_9 ( L_5 ,
V_57 , V_60 ) ;
return - 1 ;
}
if ( V_56 > V_60 ) {
* V_2 = V_61 ;
* V_3 = F_9 ( L_6 ,
V_56 , V_60 ) ;
return - 1 ;
}
if ( V_56 > V_55 ) {
* V_2 = V_61 ;
* V_3 = F_9 ( L_7 ,
V_56 , V_55 ) ;
return - 1 ;
}
switch ( V_1 -> V_24 ) {
case V_18 :
if ( V_56 < sizeof ( struct V_62 ) ) {
* V_2 = V_61 ;
* V_3 = F_9 ( L_8 ,
V_56 ) ;
return - 1 ;
}
if ( ! F_14 ( V_26 , & V_49 -> V_63 ,
V_2 , V_3 ) )
return - 1 ;
V_55 -= ( T_9 ) sizeof ( struct V_62 ) ;
V_57 -= ( T_9 ) sizeof ( struct V_62 ) ;
V_56 -= ( T_9 ) sizeof ( struct V_62 ) ;
break;
case V_12 :
if ( V_1 -> V_37 == V_38 )
V_49 -> V_63 . V_64 . V_65 = 4 ;
else
V_49 -> V_63 . V_64 . V_65 = 0 ;
break;
case V_23 :
if ( V_56 < sizeof ( V_66 ) ) {
* V_2 = V_61 ;
* V_3 = F_9 ( L_9 ,
V_56 ) ;
return - 1 ;
}
if ( ! F_15 ( V_26 ,
& V_49 -> V_63 , V_2 , V_3 , & V_58 ) )
return - 1 ;
V_55 -= V_58 ;
V_57 -= V_58 ;
V_56 -= V_58 ;
break;
}
V_49 -> V_67 = V_68 ;
V_49 -> V_69 = V_70 | V_71 ;
V_49 -> V_72 . V_73 = F_8 ( V_6 . V_74 ) ;
V_49 -> V_72 . V_75 = F_8 ( V_6 . V_76 ) * 1000 ;
V_49 -> V_77 = V_56 ;
V_49 -> V_78 = V_57 ;
if ( V_55 < ( sizeof V_6 + V_56 ) ) {
* V_2 = V_61 ;
* V_3 = F_9 ( L_10 ,
V_55 , V_56 ) ;
return - 1 ;
}
if ( ! F_16 ( V_26 , V_53 , V_56 , V_2 , V_3 ) )
return - 1 ;
if ( V_1 -> V_24 == V_18 &&
V_49 -> V_63 . V_79 . type == V_80 ) {
F_17 ( V_49 , F_18 ( V_53 ) ) ;
}
return V_55 - ( ( T_4 ) sizeof V_6 + V_56 ) ;
}
static T_5
F_14 ( T_8 V_26 , union V_81 * V_63 ,
int * V_2 , T_3 * * V_3 )
{
struct V_62 V_82 ;
T_10 V_83 ;
T_11 V_84 ;
if ( ! F_7 ( V_26 , & V_82 , sizeof V_82 , V_2 , V_3 ) )
return FALSE ;
V_83 = V_82 . V_83 ;
V_84 = F_19 ( & V_82 . V_84 ) ;
switch ( V_82 . V_85 & 0x0F ) {
case 0x01 :
V_63 -> V_79 . V_86 = V_87 ;
V_63 -> V_79 . type = V_80 ;
break;
case 0x02 :
V_63 -> V_79 . V_86 = V_87 ;
V_63 -> V_79 . type = V_88 ;
break;
case 0x05 :
V_63 -> V_79 . V_86 = V_87 ;
V_63 -> V_79 . type = V_89 ;
break;
case 0x06 :
V_63 -> V_79 . V_86 = V_90 ;
V_63 -> V_79 . type = V_91 ;
break;
case 0x03 :
V_63 -> V_79 . V_86 = V_87 ;
V_63 -> V_79 . type = V_91 ;
break;
case 0x04 :
V_63 -> V_79 . V_86 = V_87 ;
V_63 -> V_79 . type = V_91 ;
break;
default:
if ( V_83 == 0 && V_84 == 5 )
V_63 -> V_79 . V_86 = V_90 ;
else
V_63 -> V_79 . V_86 = V_87 ;
V_63 -> V_79 . type = V_91 ;
break;
}
V_63 -> V_79 . V_92 = V_93 ;
V_63 -> V_79 . V_83 = V_83 ;
V_63 -> V_79 . V_84 = V_84 ;
V_63 -> V_79 . V_94 = ( V_82 . V_85 & 0x80 ) ? 0 : 1 ;
V_63 -> V_79 . V_85 = 0 ;
V_63 -> V_79 . V_95 = 0 ;
V_63 -> V_79 . V_96 = 0 ;
V_63 -> V_79 . V_97 = 0 ;
V_63 -> V_79 . V_98 = 0 ;
return TRUE ;
}
static T_5
F_15 ( T_8 V_26 ,
union V_81 * V_63 , int * V_2 , T_3 * * V_3 ,
int * V_58 )
{
V_66 V_99 ;
int V_100 ;
if ( ! F_7 ( V_26 , & V_99 , sizeof V_99 , V_2 , V_3 ) )
return FALSE ;
if ( V_99 . V_101 [ 3 ] < 8 ) {
* V_2 = V_61 ;
* V_3 = F_9 ( L_11 ,
V_99 . V_101 [ 3 ] ) ;
return FALSE ;
}
V_100 = ( ( int ) V_99 . V_101 [ 3 ] ) - 8 ;
if ( ! F_7 ( V_26 , NULL , V_100 , V_2 , V_3 ) )
return FALSE ;
memset ( & V_63 -> V_102 , 0 , sizeof( V_63 -> V_102 ) ) ;
V_63 -> V_102 . V_65 = 4 ;
V_63 -> V_102 . V_103 = FALSE ;
V_63 -> V_102 . V_104 = FALSE ;
V_63 -> V_102 . V_105 = V_106 ;
V_63 -> V_102 . V_107 = TRUE ;
V_63 -> V_102 . V_94 = V_99 . V_94 ;
V_63 -> V_102 . V_108 = TRUE ;
V_63 -> V_102 . V_109 = V_99 . V_110 ;
V_63 -> V_102 . V_111 = TRUE ;
V_63 -> V_102 . V_112 = V_99 . signal ;
* V_58 = V_100 + 8 + 4 ;
return TRUE ;
}
int F_20 ( int V_113 )
{
if ( V_113 == V_114 )
return V_115 ;
if ( V_113 < 0 || ( unsigned ) V_113 >= V_116 || V_117 [ V_113 ] == - 1 )
return V_118 ;
return 0 ;
}
T_5 F_21 ( T_12 * V_119 , int * V_2 )
{
struct V_5 V_120 ;
V_119 -> V_121 = V_122 ;
if ( ! F_22 ( V_119 , & F_2 , sizeof F_2 , V_2 ) )
return FALSE ;
V_120 . V_30 = F_23 ( 2 ) ;
V_120 . V_36 = F_23 ( V_117 [ V_119 -> V_113 ] ) ;
if ( ! F_22 ( V_119 , & V_120 , sizeof V_120 , V_2 ) )
return FALSE ;
return TRUE ;
}
static T_5 V_122 ( T_12 * V_119 ,
const struct V_52 * V_49 ,
const T_10 * V_123 , int * V_2 , T_3 * * V_3 V_124 )
{
const union V_81 * V_63 = & V_49 -> V_63 ;
struct V_7 V_8 ;
int V_125 ;
T_4 V_126 ;
static const char V_127 [ 4 ] = { 0 } ;
struct V_62 V_128 ;
int V_129 ;
if ( V_49 -> V_67 != V_68 ) {
* V_2 = V_130 ;
return FALSE ;
}
if ( V_119 -> V_113 == V_18 )
V_129 = sizeof ( struct V_62 ) ;
else
V_129 = 0 ;
V_125 = ( int ) sizeof V_8 + V_49 -> V_77 + V_129 ;
V_126 = ( ( V_125 + 3 ) & ~ 3 ) - V_125 ;
V_125 += V_126 ;
if ( V_49 -> V_77 + V_129 > V_60 ) {
* V_2 = V_131 ;
return FALSE ;
}
V_8 . V_59 = F_23 ( V_49 -> V_78 + V_129 ) ;
V_8 . V_33 = F_23 ( V_49 -> V_77 + V_129 ) ;
V_8 . V_32 = F_23 ( V_125 ) ;
V_8 . V_132 = 0 ;
V_8 . V_74 = F_23 ( V_49 -> V_72 . V_73 ) ;
V_8 . V_76 = F_23 ( V_49 -> V_72 . V_75 / 1000 ) ;
if ( ! F_22 ( V_119 , & V_8 , sizeof V_8 , V_2 ) )
return FALSE ;
if ( V_119 -> V_113 == V_18 ) {
V_128 . V_85 =
( V_63 -> V_79 . V_94 == 0 ) ? 0x80 : 0x00 ;
switch ( V_63 -> V_79 . V_86 ) {
case V_90 :
V_128 . V_85 |= 0x06 ;
break;
case V_87 :
switch ( V_63 -> V_79 . type ) {
case V_80 :
V_128 . V_85 |= 0x01 ;
break;
case V_88 :
V_128 . V_85 |= 0x02 ;
break;
case V_89 :
V_128 . V_85 |= 0x05 ;
break;
}
break;
}
V_128 . V_83 = ( T_10 ) V_63 -> V_79 . V_83 ;
V_128 . V_84 = F_24 ( V_63 -> V_79 . V_84 ) ;
if ( ! F_22 ( V_119 , & V_128 , sizeof V_128 , V_2 ) )
return FALSE ;
}
if ( ! F_22 ( V_119 , V_123 , V_49 -> V_77 , V_2 ) )
return FALSE ;
if ( ! F_22 ( V_119 , V_127 , V_126 , V_2 ) )
return FALSE ;
return TRUE ;
}
