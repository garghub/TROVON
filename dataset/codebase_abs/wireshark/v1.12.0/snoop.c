int F_1 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 )
{
int V_4 ;
char V_5 [ sizeof F_2 ] ;
struct V_6 V_7 ;
struct V_8 V_9 ;
T_3 V_10 ;
T_4 V_11 ;
static const int V_12 [] = {
V_13 ,
V_14 ,
V_15 ,
V_14 ,
V_13 ,
V_14 ,
V_14 ,
V_14 ,
V_16 ,
V_17 ,
V_14 ,
V_14 ,
V_14 ,
V_14 ,
V_17 ,
V_14 ,
V_18 ,
V_14 ,
V_19 ,
V_14 ,
V_14 ,
V_14 ,
V_14 ,
V_14 ,
V_14 ,
V_14 ,
V_20 ,
} ;
#define F_3 (sizeof snoop_encap / sizeof snoop_encap[0])
#define F_4 0x80000000
static const int V_21 [] = {
V_14 ,
V_14 ,
V_14 ,
V_14 ,
V_14 ,
V_22 ,
V_14 ,
V_14 ,
} ;
#define F_5 (sizeof snoop_private_encap / sizeof snoop_private_encap[0])
static const int V_23 [] = {
V_13 ,
V_14 ,
V_15 ,
V_14 ,
V_13 ,
V_14 ,
V_14 ,
V_14 ,
V_16 ,
V_14 ,
V_13 ,
V_15 ,
V_13 ,
V_15 ,
V_15 ,
V_14 ,
V_14 ,
V_14 ,
V_24 ,
V_13 ,
} ;
#define F_6 (sizeof shomiti_encap / sizeof shomiti_encap[0])
int V_25 ;
T_5 V_26 ;
V_27 = V_28 ;
V_4 = F_7 ( V_5 , sizeof V_5 , V_1 -> V_29 ) ;
if ( V_4 != sizeof V_5 ) {
* V_2 = F_8 ( V_1 -> V_29 , V_3 ) ;
if ( * V_2 != 0 && * V_2 != V_30 )
return - 1 ;
return 0 ;
}
if ( memcmp ( V_5 , F_2 , sizeof F_2 ) != 0 ) {
return 0 ;
}
V_27 = V_28 ;
V_4 = F_7 ( & V_7 , sizeof V_7 , V_1 -> V_29 ) ;
if ( V_4 != sizeof V_7 ) {
* V_2 = F_8 ( V_1 -> V_29 , V_3 ) ;
if ( * V_2 == 0 )
* V_2 = V_30 ;
return - 1 ;
}
V_7 . V_31 = F_9 ( V_7 . V_31 ) ;
switch ( V_7 . V_31 ) {
case 2 :
case 3 :
case 4 :
case 5 :
break;
default:
* V_2 = V_32 ;
* V_3 = F_10 ( L_1 , V_7 . V_31 ) ;
return - 1 ;
}
V_11 = FALSE ;
V_26 = F_11 ( V_1 -> V_29 ) ;
V_27 = V_28 ;
V_4 = F_7 ( & V_9 , sizeof V_9 , V_1 -> V_29 ) ;
if ( V_4 != sizeof V_9 ) {
* V_2 = F_8 ( V_1 -> V_29 , V_3 ) ;
if ( * V_2 == 0 )
* V_2 = V_30 ;
return - 1 ;
} else {
if ( F_9 ( V_9 . V_33 ) >
( sizeof V_9 + F_9 ( V_9 . V_34 ) ) ) {
V_10 = F_9 ( V_9 . V_33 ) -
( ( T_3 ) sizeof V_9 + F_9 ( V_9 . V_34 ) ) ;
V_11 =
( V_10 >= sizeof ( struct V_35 ) ) ;
}
}
if ( F_12 ( V_1 -> V_29 , V_26 , V_36 , V_2 ) == - 1 )
return - 1 ;
V_7 . V_37 = F_9 ( V_7 . V_37 ) ;
if ( V_11 ) {
if ( V_7 . V_37 >= F_6
|| V_23 [ V_7 . V_37 ] == V_14 ) {
* V_2 = V_38 ;
* V_3 = F_10 ( L_2 ,
V_7 . V_37 ) ;
return - 1 ;
}
V_25 = V_23 [ V_7 . V_37 ] ;
V_1 -> V_39 = V_40 ;
} else if ( V_7 . V_37 & F_4 ) {
if ( ( V_7 . V_37 ^ F_4 ) >= F_5
|| V_21 [ V_7 . V_37 ^ F_4 ] == V_14 ) {
* V_2 = V_38 ;
* V_3 = F_10 ( L_3 ,
V_7 . V_37 ) ;
return - 1 ;
}
V_25 = V_21 [ V_7 . V_37 ^ F_4 ] ;
V_1 -> V_39 = V_41 ;
} else {
if ( V_7 . V_37 >= F_3
|| V_12 [ V_7 . V_37 ] == V_14 ) {
* V_2 = V_38 ;
* V_3 = F_10 ( L_4 ,
V_7 . V_37 ) ;
return - 1 ;
}
V_25 = V_12 [ V_7 . V_37 ] ;
V_1 -> V_39 = V_41 ;
}
V_1 -> V_42 = V_43 ;
V_1 -> V_44 = V_45 ;
V_1 -> V_25 = V_25 ;
V_1 -> V_46 = 0 ;
V_1 -> V_47 = V_48 ;
return 1 ;
}
static T_4 V_43 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 ,
T_5 * V_49 )
{
int V_10 ;
int V_4 ;
char V_50 [ 4 ] ;
int V_51 ;
* V_49 = F_11 ( V_1 -> V_29 ) ;
V_10 = F_13 ( V_1 , V_1 -> V_29 , & V_1 -> V_52 ,
V_1 -> V_53 , V_2 , V_3 ) ;
if ( V_10 == - 1 )
return FALSE ;
while ( V_10 != 0 ) {
V_51 = V_10 ;
if ( ( unsigned ) V_51 > sizeof V_50 )
V_51 = sizeof V_50 ;
V_27 = V_28 ;
V_4 = F_7 ( V_50 , V_51 , V_1 -> V_29 ) ;
if ( V_4 != V_51 ) {
* V_2 = F_8 ( V_1 -> V_29 , V_3 ) ;
if ( * V_2 == 0 )
* V_2 = V_30 ;
return FALSE ;
}
V_10 -= V_4 ;
}
return TRUE ;
}
static T_4
V_45 ( T_1 * V_1 , T_5 V_54 ,
struct V_55 * V_52 , T_6 * V_56 , int * V_2 , T_2 * * V_3 )
{
if ( F_12 ( V_1 -> V_57 , V_54 , V_36 , V_2 ) == - 1 )
return FALSE ;
if ( F_13 ( V_1 , V_1 -> V_57 , V_52 , V_56 , V_2 , V_3 ) == - 1 ) {
if ( * V_2 == 0 )
* V_2 = V_30 ;
return FALSE ;
}
return TRUE ;
}
static int
F_13 ( T_1 * V_1 , T_7 V_29 , struct V_55 * V_52 ,
T_6 * V_56 , int * V_2 , T_2 * * V_3 )
{
struct V_8 V_7 ;
int V_4 ;
T_8 V_58 ;
T_8 V_59 ;
T_8 V_60 ;
int V_61 ;
V_27 = V_28 ;
V_4 = F_7 ( & V_7 , sizeof V_7 , V_29 ) ;
if ( V_4 != sizeof V_7 ) {
* V_2 = F_8 ( V_29 , V_3 ) ;
if ( * V_2 == 0 && V_4 != 0 )
* V_2 = V_30 ;
return - 1 ;
}
V_58 = F_9 ( V_7 . V_33 ) ;
V_60 = F_9 ( V_7 . V_62 ) ;
V_59 = F_9 ( V_7 . V_34 ) ;
if ( V_60 > V_63 ) {
* V_2 = V_64 ;
* V_3 = F_10 ( L_5 ,
V_60 , V_63 ) ;
return - 1 ;
}
if ( V_59 > V_63 ) {
* V_2 = V_64 ;
* V_3 = F_10 ( L_6 ,
V_59 , V_63 ) ;
return - 1 ;
}
if ( V_59 > V_58 ) {
* V_2 = V_64 ;
* V_3 = F_10 ( L_7 ,
V_59 , V_58 ) ;
return - 1 ;
}
switch ( V_1 -> V_25 ) {
case V_19 :
if ( V_59 < sizeof ( struct V_65 ) ) {
* V_2 = V_64 ;
* V_3 = F_10 ( L_8 ,
V_59 ) ;
return - 1 ;
}
if ( ! F_14 ( V_29 , & V_52 -> V_66 ,
V_2 , V_3 ) )
return - 1 ;
V_58 -= ( T_8 ) sizeof ( struct V_65 ) ;
V_60 -= ( T_8 ) sizeof ( struct V_65 ) ;
V_59 -= ( T_8 ) sizeof ( struct V_65 ) ;
break;
case V_13 :
if ( V_1 -> V_39 == V_40 )
V_52 -> V_66 . V_67 . V_68 = 4 ;
else
V_52 -> V_66 . V_67 . V_68 = 0 ;
break;
case V_24 :
if ( V_59 < sizeof ( V_69 ) ) {
* V_2 = V_64 ;
* V_3 = F_10 ( L_9 ,
V_59 ) ;
return - 1 ;
}
if ( ! F_15 ( V_29 ,
& V_52 -> V_66 , V_2 , V_3 , & V_61 ) )
return - 1 ;
V_58 -= V_61 ;
V_60 -= V_61 ;
V_59 -= V_61 ;
break;
}
V_52 -> V_70 = V_71 ;
V_52 -> V_72 = V_73 | V_74 ;
V_52 -> V_75 . V_76 = F_9 ( V_7 . V_77 ) ;
V_52 -> V_75 . V_78 = F_9 ( V_7 . V_79 ) * 1000 ;
V_52 -> V_80 = V_59 ;
V_52 -> V_81 = V_60 ;
if ( V_58 < ( sizeof V_7 + V_59 ) ) {
* V_2 = V_64 ;
* V_3 = F_10 ( L_10 ,
V_58 , V_59 ) ;
return - 1 ;
}
if ( ! F_16 ( V_29 , V_56 , V_59 , V_2 , V_3 ) )
return - 1 ;
if ( V_1 -> V_25 == V_19 &&
V_52 -> V_66 . V_82 . type == V_83 ) {
F_17 ( V_52 , F_18 ( V_56 ) ) ;
}
return V_58 - ( ( T_3 ) sizeof V_7 + V_59 ) ;
}
static T_4
F_14 ( T_7 V_29 , union V_84 * V_66 ,
int * V_2 , T_2 * * V_3 )
{
struct V_65 V_85 ;
int V_4 ;
T_9 V_86 ;
T_10 V_87 ;
V_27 = V_28 ;
V_4 = F_7 ( & V_85 , sizeof ( struct V_65 ) , V_29 ) ;
if ( V_4 != sizeof ( struct V_65 ) ) {
* V_2 = F_8 ( V_29 , V_3 ) ;
if ( * V_2 == 0 )
* V_2 = V_30 ;
return FALSE ;
}
V_86 = V_85 . V_86 ;
V_87 = F_19 ( & V_85 . V_87 ) ;
switch ( V_85 . V_88 & 0x0F ) {
case 0x01 :
V_66 -> V_82 . V_89 = V_90 ;
V_66 -> V_82 . type = V_83 ;
break;
case 0x02 :
V_66 -> V_82 . V_89 = V_90 ;
V_66 -> V_82 . type = V_91 ;
break;
case 0x05 :
V_66 -> V_82 . V_89 = V_90 ;
V_66 -> V_82 . type = V_92 ;
break;
case 0x06 :
V_66 -> V_82 . V_89 = V_93 ;
V_66 -> V_82 . type = V_94 ;
break;
case 0x03 :
V_66 -> V_82 . V_89 = V_90 ;
V_66 -> V_82 . type = V_94 ;
break;
case 0x04 :
V_66 -> V_82 . V_89 = V_90 ;
V_66 -> V_82 . type = V_94 ;
break;
default:
if ( V_86 == 0 && V_87 == 5 )
V_66 -> V_82 . V_89 = V_93 ;
else
V_66 -> V_82 . V_89 = V_90 ;
V_66 -> V_82 . type = V_94 ;
break;
}
V_66 -> V_82 . V_95 = V_96 ;
V_66 -> V_82 . V_86 = V_86 ;
V_66 -> V_82 . V_87 = V_87 ;
V_66 -> V_82 . V_97 = ( V_85 . V_88 & 0x80 ) ? 0 : 1 ;
V_66 -> V_82 . V_88 = 0 ;
V_66 -> V_82 . V_98 = 0 ;
V_66 -> V_82 . V_99 = 0 ;
V_66 -> V_82 . V_100 = 0 ;
V_66 -> V_82 . V_101 = 0 ;
return TRUE ;
}
static T_4
F_15 ( T_7 V_29 ,
union V_84 * V_66 , int * V_2 , T_2 * * V_3 ,
int * V_61 )
{
V_69 V_102 ;
int V_4 ;
int V_103 ;
V_27 = V_28 ;
V_4 = F_7 ( & V_102 , sizeof ( V_69 ) , V_29 ) ;
if ( V_4 != sizeof ( V_69 ) ) {
* V_2 = F_8 ( V_29 , V_3 ) ;
if ( * V_2 == 0 )
* V_2 = V_30 ;
return FALSE ;
}
if ( V_102 . V_104 [ 3 ] < 8 ) {
* V_2 = V_64 ;
* V_3 = F_10 ( L_11 ,
V_102 . V_104 [ 3 ] ) ;
return FALSE ;
}
V_103 = ( ( int ) V_102 . V_104 [ 3 ] ) - 8 ;
if ( F_12 ( V_29 , V_103 , V_105 , V_2 ) == - 1 )
return FALSE ;
V_66 -> V_106 . V_68 = 4 ;
V_66 -> V_106 . V_97 = V_102 . V_97 ;
V_66 -> V_106 . V_107 = V_102 . V_108 ;
V_66 -> V_106 . V_109 = V_102 . signal ;
* V_61 = V_103 + 8 + 4 ;
return TRUE ;
}
int F_20 ( int V_110 )
{
if ( V_110 == V_111 )
return V_112 ;
if ( V_110 < 0 || ( unsigned ) V_110 >= V_113 || V_114 [ V_110 ] == - 1 )
return V_38 ;
return 0 ;
}
T_4 F_21 ( T_11 * V_115 , int * V_2 )
{
struct V_6 V_116 ;
V_115 -> V_117 = V_118 ;
V_115 -> V_119 = NULL ;
if ( ! F_22 ( V_115 , & F_2 , sizeof F_2 , V_2 ) )
return FALSE ;
V_116 . V_31 = F_23 ( 2 ) ;
V_116 . V_37 = F_23 ( V_114 [ V_115 -> V_110 ] ) ;
if ( ! F_22 ( V_115 , & V_116 , sizeof V_116 , V_2 ) )
return FALSE ;
return TRUE ;
}
static T_4 V_118 ( T_11 * V_115 ,
const struct V_55 * V_52 ,
const T_9 * V_120 , int * V_2 )
{
const union V_84 * V_66 = & V_52 -> V_66 ;
struct V_8 V_9 ;
int V_121 ;
T_3 V_122 ;
static const char V_123 [ 4 ] = { 0 } ;
struct V_65 V_124 ;
int V_125 ;
if ( V_52 -> V_70 != V_71 ) {
* V_2 = V_126 ;
return FALSE ;
}
if ( V_115 -> V_110 == V_19 )
V_125 = sizeof ( struct V_65 ) ;
else
V_125 = 0 ;
V_121 = ( int ) sizeof V_9 + V_52 -> V_80 + V_125 ;
V_122 = ( ( V_121 + 3 ) & ~ 3 ) - V_121 ;
V_121 += V_122 ;
if ( V_52 -> V_80 + V_125 > V_63 ) {
* V_2 = V_127 ;
return FALSE ;
}
V_9 . V_62 = F_23 ( V_52 -> V_81 + V_125 ) ;
V_9 . V_34 = F_23 ( V_52 -> V_80 + V_125 ) ;
V_9 . V_33 = F_23 ( V_121 ) ;
V_9 . V_128 = 0 ;
V_9 . V_77 = F_23 ( V_52 -> V_75 . V_76 ) ;
V_9 . V_79 = F_23 ( V_52 -> V_75 . V_78 / 1000 ) ;
if ( ! F_22 ( V_115 , & V_9 , sizeof V_9 , V_2 ) )
return FALSE ;
if ( V_115 -> V_110 == V_19 ) {
V_124 . V_88 =
( V_66 -> V_82 . V_97 == 0 ) ? 0x80 : 0x00 ;
switch ( V_66 -> V_82 . V_89 ) {
case V_93 :
V_124 . V_88 |= 0x06 ;
break;
case V_90 :
switch ( V_66 -> V_82 . type ) {
case V_83 :
V_124 . V_88 |= 0x01 ;
break;
case V_91 :
V_124 . V_88 |= 0x02 ;
break;
case V_92 :
V_124 . V_88 |= 0x05 ;
break;
}
break;
}
V_124 . V_86 = ( T_9 ) V_66 -> V_82 . V_86 ;
V_124 . V_87 = F_24 ( V_66 -> V_82 . V_87 ) ;
if ( ! F_22 ( V_115 , & V_124 , sizeof V_124 , V_2 ) )
return FALSE ;
}
if ( ! F_22 ( V_115 , V_120 , V_52 -> V_80 , V_2 ) )
return FALSE ;
if ( ! F_22 ( V_115 , V_123 , V_122 , V_2 ) )
return FALSE ;
return TRUE ;
}
