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
if ( * V_2 != 0 )
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
if ( * V_2 != 0 )
return - 1 ;
return 0 ;
}
V_7 . V_30 = F_9 ( V_7 . V_30 ) ;
switch ( V_7 . V_30 ) {
case 2 :
case 3 :
case 4 :
case 5 :
break;
default:
* V_2 = V_31 ;
* V_3 = F_10 ( L_1 , V_7 . V_30 ) ;
return - 1 ;
}
V_11 = FALSE ;
V_26 = F_11 ( V_1 -> V_29 ) ;
V_27 = V_28 ;
V_4 = F_7 ( & V_9 , sizeof V_9 , V_1 -> V_29 ) ;
if ( V_4 != sizeof V_9 ) {
* V_2 = F_8 ( V_1 -> V_29 , V_3 ) ;
if ( * V_2 == 0 && V_4 != 0 )
* V_2 = V_32 ;
if ( * V_2 != 0 ) {
return - 1 ;
}
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
T_6 V_50 ;
T_6 V_51 ;
T_6 V_52 ;
int V_4 ;
struct V_8 V_7 ;
char V_53 [ 4 ] ;
T_3 V_10 ;
int V_54 ;
int V_55 ;
V_27 = V_28 ;
V_4 = F_7 ( & V_7 , sizeof V_7 , V_1 -> V_29 ) ;
if ( V_4 != sizeof V_7 ) {
* V_2 = F_8 ( V_1 -> V_29 , V_3 ) ;
if ( * V_2 == 0 && V_4 != 0 )
* V_2 = V_32 ;
return FALSE ;
}
V_50 = F_9 ( V_7 . V_33 ) ;
V_52 = F_9 ( V_7 . V_56 ) ;
V_51 = F_9 ( V_7 . V_34 ) ;
if ( V_52 > V_57 ) {
* V_2 = V_58 ;
* V_3 = F_10 ( L_5 ,
V_52 , V_57 ) ;
return FALSE ;
}
if ( V_51 > V_57 ) {
* V_2 = V_58 ;
* V_3 = F_10 ( L_6 ,
V_51 , V_57 ) ;
return FALSE ;
}
if ( V_51 > V_50 ) {
* V_2 = V_58 ;
* V_3 = F_10 ( L_7 ,
V_51 , V_50 ) ;
return FALSE ;
}
* V_49 = F_11 ( V_1 -> V_29 ) ;
switch ( V_1 -> V_25 ) {
case V_19 :
if ( V_51 < sizeof ( struct V_59 ) ) {
* V_2 = V_58 ;
* V_3 = F_10 ( L_8 ,
V_51 ) ;
return FALSE ;
}
if ( ! F_13 ( V_1 -> V_29 , & V_1 -> V_60 ,
V_2 , V_3 ) )
return FALSE ;
V_50 -= ( T_6 ) sizeof ( struct V_59 ) ;
V_52 -= ( T_6 ) sizeof ( struct V_59 ) ;
V_51 -= ( T_6 ) sizeof ( struct V_59 ) ;
break;
case V_13 :
if ( V_1 -> V_39 == V_40 )
V_1 -> V_60 . V_61 . V_62 = 4 ;
else
V_1 -> V_60 . V_61 . V_62 = 0 ;
break;
case V_24 :
if ( V_51 < sizeof ( V_63 ) ) {
* V_2 = V_58 ;
* V_3 = F_10 ( L_9 ,
V_51 ) ;
return FALSE ;
}
if ( ! F_14 ( V_1 -> V_29 ,
& V_1 -> V_60 , V_2 , V_3 , & V_55 ) )
return FALSE ;
V_50 -= V_55 ;
V_52 -= V_55 ;
V_51 -= V_55 ;
break;
}
F_15 ( V_1 -> V_64 , V_51 ) ;
if ( ! F_16 ( V_1 -> V_29 , F_17 ( V_1 -> V_64 ) ,
V_51 , V_2 , V_3 ) )
return FALSE ;
V_1 -> V_65 . V_66 = V_67 | V_68 ;
V_1 -> V_65 . V_69 . V_70 = F_9 ( V_7 . V_71 ) ;
V_1 -> V_65 . V_69 . V_72 = F_9 ( V_7 . V_73 ) * 1000 ;
V_1 -> V_65 . V_74 = V_51 ;
V_1 -> V_65 . V_75 = V_52 ;
if ( V_1 -> V_25 == V_19 &&
V_1 -> V_60 . V_76 . type == V_77 ) {
F_18 ( F_17 ( V_1 -> V_64 ) ,
V_1 -> V_65 . V_74 , & V_1 -> V_60 ) ;
}
if ( V_50 < ( sizeof V_7 + V_51 ) ) {
* V_2 = V_58 ;
* V_3 = F_10 ( L_10 ,
V_50 , V_51 ) ;
return FALSE ;
}
V_10 = V_50 - ( ( T_3 ) sizeof V_7 + V_51 ) ;
while ( V_10 != 0 ) {
V_54 = V_10 ;
if ( ( unsigned ) V_54 > sizeof V_53 )
V_54 = sizeof V_53 ;
V_27 = V_28 ;
V_4 = F_7 ( V_53 , V_54 , V_1 -> V_29 ) ;
if ( V_4 != V_54 ) {
* V_2 = F_8 ( V_1 -> V_29 , V_3 ) ;
if ( * V_2 == 0 )
* V_2 = V_32 ;
return FALSE ;
}
V_10 -= V_4 ;
}
return TRUE ;
}
static T_4
V_45 ( T_1 * V_1 , T_5 V_78 ,
union V_79 * V_60 , T_7 * V_80 , int V_81 ,
int * V_2 , T_2 * * V_3 )
{
if ( F_12 ( V_1 -> V_82 , V_78 , V_36 , V_2 ) == - 1 )
return FALSE ;
switch ( V_1 -> V_25 ) {
case V_19 :
if ( ! F_13 ( V_1 -> V_82 , V_60 ,
V_2 , V_3 ) ) {
return FALSE ;
}
break;
case V_13 :
if ( V_1 -> V_39 == V_40 )
V_60 -> V_61 . V_62 = 4 ;
else
V_60 -> V_61 . V_62 = 0 ;
break;
case V_24 :
if ( ! F_14 ( V_1 -> V_82 ,
V_60 , V_2 , V_3 , NULL ) ) {
return FALSE ;
}
break;
}
if ( ! F_16 ( V_1 -> V_82 , V_80 , V_81 , V_2 , V_3 ) )
return FALSE ;
if ( V_1 -> V_25 == V_19 &&
V_60 -> V_76 . type == V_77 )
F_18 ( V_80 , V_81 , V_60 ) ;
return TRUE ;
}
static T_4
F_13 ( T_8 V_29 , union V_79 * V_60 ,
int * V_2 , T_2 * * V_3 )
{
struct V_59 V_83 ;
int V_4 ;
T_7 V_84 ;
T_9 V_85 ;
V_27 = V_28 ;
V_4 = F_7 ( & V_83 , sizeof ( struct V_59 ) , V_29 ) ;
if ( V_4 != sizeof ( struct V_59 ) ) {
* V_2 = F_8 ( V_29 , V_3 ) ;
if ( * V_2 == 0 )
* V_2 = V_32 ;
return FALSE ;
}
V_84 = V_83 . V_84 ;
V_85 = F_19 ( & V_83 . V_85 ) ;
switch ( V_83 . V_86 & 0x0F ) {
case 0x01 :
V_60 -> V_76 . V_87 = V_88 ;
V_60 -> V_76 . type = V_77 ;
break;
case 0x02 :
V_60 -> V_76 . V_87 = V_88 ;
V_60 -> V_76 . type = V_89 ;
break;
case 0x05 :
V_60 -> V_76 . V_87 = V_88 ;
V_60 -> V_76 . type = V_90 ;
break;
case 0x06 :
V_60 -> V_76 . V_87 = V_91 ;
V_60 -> V_76 . type = V_92 ;
break;
case 0x03 :
V_60 -> V_76 . V_87 = V_88 ;
V_60 -> V_76 . type = V_92 ;
break;
case 0x04 :
V_60 -> V_76 . V_87 = V_88 ;
V_60 -> V_76 . type = V_92 ;
break;
default:
if ( V_84 == 0 && V_85 == 5 )
V_60 -> V_76 . V_87 = V_91 ;
else
V_60 -> V_76 . V_87 = V_88 ;
V_60 -> V_76 . type = V_92 ;
break;
}
V_60 -> V_76 . V_93 = V_94 ;
V_60 -> V_76 . V_84 = V_84 ;
V_60 -> V_76 . V_85 = V_85 ;
V_60 -> V_76 . V_95 = ( V_83 . V_86 & 0x80 ) ? 0 : 1 ;
V_60 -> V_76 . V_86 = 0 ;
V_60 -> V_76 . V_96 = 0 ;
V_60 -> V_76 . V_97 = 0 ;
V_60 -> V_76 . V_98 = 0 ;
V_60 -> V_76 . V_99 = 0 ;
return TRUE ;
}
static T_4
F_14 ( T_8 V_29 ,
union V_79 * V_60 , int * V_2 , T_2 * * V_3 ,
int * V_55 )
{
V_63 V_100 ;
int V_4 ;
int V_101 ;
V_27 = V_28 ;
V_4 = F_7 ( & V_100 , sizeof ( V_63 ) , V_29 ) ;
if ( V_4 != sizeof ( V_63 ) ) {
* V_2 = F_8 ( V_29 , V_3 ) ;
if ( * V_2 == 0 )
* V_2 = V_32 ;
return FALSE ;
}
if ( V_100 . V_102 [ 3 ] < 8 ) {
* V_2 = V_58 ;
* V_3 = F_10 ( L_11 ,
V_100 . V_102 [ 3 ] ) ;
return FALSE ;
}
V_101 = ( ( int ) V_100 . V_102 [ 3 ] ) - 8 ;
if ( F_12 ( V_29 , V_101 , V_103 , V_2 ) == - 1 )
return FALSE ;
V_60 -> V_104 . V_62 = 4 ;
V_60 -> V_104 . V_95 = V_100 . V_95 ;
V_60 -> V_104 . V_105 = V_100 . V_106 ;
V_60 -> V_104 . V_107 = V_100 . signal ;
if( V_55 != NULL )
* V_55 = V_101 + 8 + 4 ;
return TRUE ;
}
static T_4
F_16 ( T_8 V_29 , T_7 * V_80 , int V_81 , int * V_2 ,
T_2 * * V_3 )
{
int V_4 ;
V_27 = V_28 ;
V_4 = F_7 ( V_80 , V_81 , V_29 ) ;
if ( V_4 != V_81 ) {
* V_2 = F_8 ( V_29 , V_3 ) ;
if ( * V_2 == 0 )
* V_2 = V_32 ;
return FALSE ;
}
return TRUE ;
}
int F_20 ( int V_108 )
{
if ( V_108 == V_109 )
return V_110 ;
if ( V_108 < 0 || ( unsigned ) V_108 >= V_111 || V_112 [ V_108 ] == - 1 )
return V_38 ;
return 0 ;
}
T_4 F_21 ( T_10 * V_113 , int * V_2 )
{
struct V_6 V_114 ;
V_113 -> V_115 = V_116 ;
V_113 -> V_117 = NULL ;
if ( ! F_22 ( V_113 , & F_2 , sizeof F_2 , V_2 ) )
return FALSE ;
V_114 . V_30 = F_23 ( 2 ) ;
V_114 . V_37 = F_23 ( V_112 [ V_113 -> V_108 ] ) ;
if ( ! F_22 ( V_113 , & V_114 , sizeof V_114 , V_2 ) )
return FALSE ;
return TRUE ;
}
static T_4 V_116 ( T_10 * V_113 ,
const struct V_118 * V_65 ,
const union V_79 * V_60 V_119 ,
const T_7 * V_80 , int * V_2 )
{
struct V_8 V_9 ;
int V_120 ;
T_3 V_121 ;
static char V_122 [ 4 ] ;
struct V_59 V_123 ;
int V_124 ;
if ( V_113 -> V_108 == V_19 )
V_124 = sizeof ( struct V_59 ) ;
else
V_124 = 0 ;
V_120 = ( int ) sizeof V_9 + V_65 -> V_74 + V_124 ;
V_121 = ( ( V_120 + 3 ) & ~ 3 ) - V_120 ;
V_120 += V_121 ;
V_9 . V_56 = F_23 ( V_65 -> V_75 + V_124 ) ;
V_9 . V_34 = F_23 ( V_65 -> V_74 + V_124 ) ;
V_9 . V_33 = F_23 ( V_120 ) ;
V_9 . V_125 = 0 ;
V_9 . V_71 = F_23 ( V_65 -> V_69 . V_70 ) ;
V_9 . V_73 = F_23 ( V_65 -> V_69 . V_72 / 1000 ) ;
if ( ! F_22 ( V_113 , & V_9 , sizeof V_9 , V_2 ) )
return FALSE ;
if ( V_113 -> V_108 == V_19 ) {
V_123 . V_86 =
( V_60 -> V_76 . V_95 == 0 ) ? 0x80 : 0x00 ;
switch ( V_60 -> V_76 . V_87 ) {
case V_91 :
V_123 . V_86 |= 0x06 ;
break;
case V_88 :
switch ( V_60 -> V_76 . type ) {
case V_77 :
V_123 . V_86 |= 0x01 ;
break;
case V_89 :
V_123 . V_86 |= 0x02 ;
break;
case V_90 :
V_123 . V_86 |= 0x05 ;
break;
}
break;
}
V_123 . V_84 = ( T_7 ) V_60 -> V_76 . V_84 ;
V_123 . V_85 = F_24 ( V_60 -> V_76 . V_85 ) ;
if ( ! F_22 ( V_113 , & V_123 , sizeof V_123 , V_2 ) )
return FALSE ;
}
if ( ! F_22 ( V_113 , V_80 , V_65 -> V_74 , V_2 ) )
return FALSE ;
if ( ! F_22 ( V_113 , V_122 , V_121 , V_2 ) )
return FALSE ;
return TRUE ;
}
