static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 * V_4 , T_1 V_5 , T_1 * V_6 , T_1 V_7 )
{
T_1 V_8 [ 64 ] ;
int V_9 , V_10 ;
F_2 ( L_1 , V_3 ) ;
F_3 ( V_4 , V_5 , F_2 ) ;
F_2 ( L_2 ) ;
if ( V_5 > 62 ) {
F_4 ( L_3 ,
V_3 ) ;
V_5 = 62 ;
}
if ( V_7 > 62 ) {
F_4 ( L_4 ,
V_3 ) ;
V_7 = 62 ;
}
V_8 [ 0 ] = V_11 ;
V_8 [ 1 ] = V_3 << 1 ;
if ( V_6 != NULL ) {
V_8 [ 0 ] |= V_7 ;
V_8 [ 1 ] |= 1 ;
}
memcpy ( & V_8 [ 2 ] , V_4 , V_5 ) ;
V_9 = F_5 ( V_2 ,
F_6 ( V_2 , 0x01 ) ,
V_8 , 2 + V_5 ,
NULL , 1000 ) ;
if ( V_9 < 0 ) {
F_4 ( L_5 , V_3 , V_9 ) ;
return - V_12 ;
}
V_9 = F_5 ( V_2 ,
F_7 ( V_2 , 0x01 ) ,
V_8 , 64 , & V_10 , 1000 ) ;
if ( V_9 < 0 ) {
F_4 ( L_6 , V_3 , V_9 ) ;
return - V_12 ;
}
if ( V_8 [ 0 ] != V_13 ) {
F_4 ( L_7 , V_3 , V_8 [ 0 ] ) ;
if ( ! ( V_8 [ 0 ] == V_14 &&
V_3 == 0x60
) )
return - V_12 ;
}
F_2 ( L_8 , V_8 [ 0 ] ) ;
if ( V_6 != NULL ) {
memcpy ( V_6 , & V_8 [ 2 ] , V_7 ) ;
F_2 ( L_9 , V_7 ) ;
F_3 ( V_6 , V_7 , F_2 ) ;
}
F_2 ( L_10 ) ;
return 0 ;
}
static int F_8 ( struct V_15 * V_16 , struct V_17 * V_18 ,
int V_19 )
{
int V_9 = 0 , V_20 ;
struct V_21 * V_22 = F_9 ( V_16 ) ;
if ( F_10 ( & V_22 -> V_23 ) < 0 )
return - V_24 ;
for ( V_20 = 0 ; V_20 < V_19 ; V_20 ++ ) {
if ( V_20 + 1 < V_19 && V_18 [ V_20 + 1 ] . V_25 & V_26 ) {
V_9 = F_1 ( V_22 -> V_2 , V_18 [ V_20 + 1 ] . V_27 ,
V_18 [ V_20 ] . V_28 , V_18 [ V_20 ] . V_29 ,
V_18 [ V_20 + 1 ] . V_28 , V_18 [ V_20 + 1 ] . V_29 ) ;
if ( V_9 != 0 )
break;
V_20 ++ ;
} else {
V_9 = F_1 ( V_22 -> V_2 , V_18 [ V_20 ] . V_27 ,
V_18 [ V_20 ] . V_28 , V_18 [ V_20 ] . V_29 ,
NULL , 0 ) ;
if ( V_9 != 0 )
break;
}
}
if ( V_9 == 0 )
V_9 = V_20 ;
F_11 ( & V_22 -> V_23 ) ;
return V_9 ;
}
static T_2 F_12 ( struct V_15 * V_30 )
{
return V_31 ;
}
static int F_13 ( struct V_21 * V_22 , int V_32 ,
enum V_33 V_34 )
{
struct V_35 * V_36 = V_22 -> V_37 ;
T_1 * V_38 = V_36 -> V_28 ;
int V_9 ;
V_38 [ 0 ] = V_32 ? V_39 : V_40 ;
if ( V_41 && V_34 != V_42 )
return 0 ;
switch ( V_34 ) {
case V_43 :
V_38 [ 1 ] = 0x82 ;
break;
case V_44 :
V_38 [ 1 ] = 0x82 ;
if ( V_32 ) {
V_38 [ 2 ] = 0x02 ;
V_38 [ 3 ] = 10 ;
V_38 [ 4 ] = 10 ;
} else {
V_38 [ 2 ] = 0xff ;
V_38 [ 3 ] = 50 ;
V_38 [ 4 ] = 50 ;
}
V_38 [ 5 ] = 1 ;
break;
default:
case V_42 :
V_38 [ 1 ] = 0x80 ;
break;
}
if ( F_10 ( & V_22 -> V_23 ) < 0 )
return - V_24 ;
V_9 = F_14 ( V_22 -> V_2 , F_15 ( V_22 -> V_2 , 0 ) ,
V_32 ? V_39 : V_40 ,
V_45 | V_46 ,
0 , 0 ,
V_38 , 8 , 500 ) ;
F_11 ( & V_22 -> V_23 ) ;
return V_9 ;
}
static int F_16 ( struct V_21 * V_22 , T_1 V_32 , T_1 V_47 )
{
struct V_35 * V_36 = V_22 -> V_37 ;
T_1 * V_8 = V_36 -> V_28 ;
int V_9 ;
V_8 [ 0 ] = 0 ;
if ( F_10 ( & V_22 -> V_23 ) < 0 )
return - V_24 ;
V_9 = F_14 ( V_22 -> V_2 , F_15 ( V_22 -> V_2 , 0 ) ,
V_48 ,
V_45 | V_46 ,
( V_32 << 8 ) | V_47 , 0 ,
V_8 , 1 , 500 ) ;
F_11 ( & V_22 -> V_23 ) ;
return V_9 ;
}
static void F_17 ( struct V_49 * V_50 )
{
struct V_35 * V_36 =
F_18 ( V_50 , struct V_35 , V_51 . V_50 ) ;
struct V_52 * V_53 = V_36 -> V_54 -> V_30 [ 0 ] . V_55 [ 0 ] . V_53 ;
if ( V_36 -> V_56 == 0 )
goto V_57;
if ( V_53 != NULL ) {
enum V_58 V_59 ;
if ( V_53 -> V_60 . V_61 ( V_53 , & V_59 ) != 0 )
goto V_57;
if ( V_59 & V_62 ) {
T_2 V_63 ;
if ( V_53 -> V_60 . V_64 ( V_53 , & V_63 ) != 0 )
goto V_57;
if ( V_63 > 1000 )
F_13 ( V_36 -> V_54 , 0 , V_44 ) ;
else
F_13 ( V_36 -> V_54 , 0 , V_43 ) ;
} else
F_13 ( V_36 -> V_54 , 0 , V_42 ) ;
}
V_57:
F_19 ( & V_36 -> V_51 ,
F_20 ( 500 ) ) ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_65 * V_66 ,
struct V_67 * * V_68 , int * V_69 )
{
int V_9 ;
T_1 * V_70 ;
V_70 = F_22 ( 3 , V_71 ) ;
if ( ! V_70 )
return - V_72 ;
if ( F_23 ( V_2 , 0 , 1 ) != 0 )
F_4 ( L_11 ) ;
else
F_24 ( L_12 ) ;
* V_69 = 0 ;
V_9 = F_14 ( V_2 , F_25 ( V_2 , 0 ) ,
V_73 ,
V_45 | V_74 ,
0 , 0 ,
V_70 , 3 , 500 ) ;
if ( V_9 < 0 )
* V_69 = 1 ;
else {
F_24 ( L_13 , V_70 [ 1 ] , V_70 [ 2 ] ) ;
* V_69 = 0 ;
}
F_26 ( V_70 ) ;
return 0 ;
}
static int F_27 ( struct V_21 * V_22 , int V_75 )
{
struct V_35 * V_36 = V_22 -> V_37 ;
V_36 -> V_56 = V_75 ;
if ( V_41 )
return 0 ;
F_13 ( V_22 , 0 , V_42 ) ;
F_13 ( V_22 , 1 , V_43 ) ;
return 0 ;
}
static T_1 F_28 ( const T_1 * V_8 , T_3 V_76 )
{
T_1 V_77 = 0 ;
while ( -- V_76 )
V_77 ^= * V_8 ++ ;
return V_77 ;
}
static int F_29 ( struct V_21 * V_22 ,
T_3 V_78 , T_1 * V_8 , T_3 V_76 , T_1 V_79 )
{
T_1 V_80 = V_78 & 0xff ;
struct V_17 V_18 [] = {
{
. V_27 = 0x50 | ( ( V_78 >> 8 ) & 0x3 ) ,
. V_28 = & V_80 ,
. V_29 = 1
} , {
. V_27 = 0x50 | ( ( V_78 >> 8 ) & 0x3 ) ,
. V_25 = V_26 ,
. V_28 = V_8 ,
. V_29 = V_76
}
} ;
while ( V_79 -- ) {
int V_59 ;
if ( F_30 ( & V_22 -> V_81 , V_18 , 2 ) != 2 )
break;
V_59 =
F_28 ( V_8 , V_76 - 1 ) == V_8 [ V_76 - 1 ] ;
if ( V_59 )
return 0 ;
}
return - V_82 ;
}
static int F_31 ( struct V_21 * V_22 ,
T_1 V_83 [] )
{
T_1 V_28 [ V_84 ] ;
if ( F_29 ( V_22 , V_85 ,
V_28 , V_84 , 4 ) != 0 )
return - V_12 ;
memcpy ( V_83 , V_28 , 6 ) ;
return 0 ;
}
static int F_32 ( struct V_52 * V_53 ,
enum V_86 V_87 )
{
int V_20 ;
T_1 V_88 [ 3 ] = { 0 } ;
V_88 [ 2 ] = 1 ;
switch ( V_87 ) {
case V_89 :
V_88 [ 0 ] = 1 ;
break;
case V_90 :
V_88 [ 0 ] = 1 ;
V_88 [ 1 ] = 1 ;
break;
default:
case V_91 :
break;
}
for ( V_20 = 0 ; V_20 < 3 ; V_20 ++ )
if ( V_92 . V_93 ( V_53 , V_20 + 2 , 0 ,
V_88 [ V_20 ] , 0 ) != 0 )
return - V_82 ;
return 0 ;
}
static int F_33 ( struct V_94 * V_95 )
{
struct V_1 * V_2 = V_95 -> V_54 -> V_2 ;
int V_9 ;
V_95 -> V_55 [ 0 ] . V_53 = F_34 ( V_96 , & V_92 ,
& V_95 -> V_54 -> V_81 , V_97 ) ;
if ( V_95 -> V_55 [ 0 ] . V_53 ) {
const struct V_98 * V_99 ;
V_99 = F_34 ( V_100 ,
V_95 -> V_55 [ 0 ] . V_53 ,
& V_101 ,
& V_95 -> V_54 -> V_81 ) ;
if ( V_99 ) {
V_92 . V_102 = V_99 -> V_102 ;
V_92 . V_103 = V_99 -> V_103 ;
V_92 . V_104 = V_99 -> V_104 ;
V_92 . V_105 = V_99 -> V_105 ;
V_92 . V_106 = V_99 -> V_106 ;
V_92 . V_107 = V_99 -> V_107 ;
V_92 . V_108 = V_99 -> V_108 ;
V_92 . V_109 = V_99 -> V_109 ;
V_92 . V_110 = V_99 -> V_110 ;
V_92 . V_111 = V_99 -> V_111 ;
V_92 . V_112 = V_99 -> V_112 ;
if ( V_95 -> V_55 [ 0 ] . V_53 -> V_60 . V_113 )
V_95 -> V_55 [ 0 ] . V_53 -> V_60 . V_113 ( V_95 -> V_55 [ 0 ] . V_53 ) ;
if ( F_10 ( & V_95 -> V_54 -> V_23 ) < 0 )
return - V_24 ;
V_9 = F_14 ( V_2 , F_15 ( V_2 , 0 ) ,
V_114 ,
V_45 | V_46 ,
0 , 0 ,
NULL , 0 , 500 ) ;
F_11 ( & V_95 -> V_54 -> V_23 ) ;
if ( V_9 != 0 )
F_4 ( L_14 ) ;
V_95 -> V_55 [ 0 ] . V_53 -> V_60 . V_115 = F_32 ;
F_35 ( V_95 -> V_55 [ 0 ] . V_53 -> V_60 . F_24 . V_116 , V_95 -> V_54 -> V_68 -> V_116 ,
sizeof( V_95 -> V_55 [ 0 ] . V_53 -> V_60 . F_24 . V_116 ) ) ;
} else {
F_36 ( V_95 -> V_55 [ 0 ] . V_53 ) ;
V_95 -> V_55 [ 0 ] . V_53 = NULL ;
}
}
F_16 ( V_95 -> V_54 , 1 , 1 ) ;
return V_95 -> V_55 [ 0 ] . V_53 == NULL ? - V_12 : 0 ;
}
static int F_37 ( struct V_21 * V_22 )
{
struct V_35 * V_36 = V_22 -> V_37 ;
T_1 * V_28 = V_36 -> V_28 ;
T_1 * V_8 ;
int V_9 ;
struct V_117 V_118 ;
V_28 [ 0 ] = V_119 ;
V_28 [ 1 ] = 0x08 ;
V_28 [ 2 ] = 0x8f ;
V_28 [ 3 ] = V_120 ;
V_28 [ 4 ] = V_121 ;
if ( F_10 ( & V_22 -> V_23 ) < 0 )
return - V_24 ;
V_9 = F_14 ( V_22 -> V_2 , F_15 ( V_22 -> V_2 , 0 ) ,
V_119 ,
V_45 | V_46 ,
0 , 0 ,
V_28 , 5 , 500 ) ;
if ( V_9 < 0 )
goto V_122;
V_28 [ 1 ] = 0 ;
V_28 [ 2 ] = 0 ;
V_9 = F_14 ( V_22 -> V_2 , F_25 ( V_22 -> V_2 , 0 ) ,
V_119 ,
V_45 | V_74 ,
0x8080 , 0 ,
V_28 , 62 , 500 ) ;
V_122:
F_11 ( & V_22 -> V_23 ) ;
if ( V_9 < 0 )
return V_9 ;
if ( V_9 == 1 )
return 0 ;
V_8 = V_28 + 1 ;
#if 0
deb_rc("RC: %d ", ret);
debug_dump(b, ret, deb_rc);
#endif
V_118 . V_123 = 0 ;
while ( 1 ) {
V_118 . V_123 = ! V_118 . V_123 ;
V_118 . V_124 = ( * V_8 * V_125 * V_126 ) / 1000 ;
F_38 ( V_22 -> V_127 , & V_118 ) ;
V_8 ++ ;
if ( * V_8 == 0xff ) {
V_118 . V_123 = 0 ;
V_118 . V_124 = 888888 * 2 ;
F_38 ( V_22 -> V_127 , & V_118 ) ;
break;
}
}
F_39 ( V_22 -> V_127 ) ;
return 1 ;
}
static int F_40 ( struct V_21 * V_22 )
{
int V_9 = F_37 ( V_22 ) ;
if ( V_9 < 0 )
return V_9 ;
if ( V_9 == 0 )
return 0 ;
if ( ! V_41 )
F_13 ( V_22 , 1 , V_44 ) ;
return 0 ;
}
static int F_41 ( struct V_128 * V_129 ,
const struct V_130 * V_131 )
{
struct V_21 * V_54 ;
if ( F_42 ( V_129 , & V_132 , V_133 ,
& V_54 , V_134 ) != 0 )
return - V_12 ;
if ( V_54 ) {
struct V_35 * V_36 = V_54 -> V_37 ;
V_36 -> V_54 = V_54 ;
if ( ! V_41 ) {
F_43 ( & V_36 -> V_51 ,
F_17 ) ;
F_19 ( & V_36 -> V_51 ,
F_20 ( 500 ) ) ;
}
}
return 0 ;
}
static void F_44 ( struct V_128 * V_129 )
{
struct V_21 * V_54 = F_45 ( V_129 ) ;
if ( V_54 != NULL ) {
struct V_35 * V_36 = V_54 -> V_37 ;
if ( V_36 != NULL )
F_46 ( & V_36 -> V_51 ) ;
}
F_47 ( V_129 ) ;
}
