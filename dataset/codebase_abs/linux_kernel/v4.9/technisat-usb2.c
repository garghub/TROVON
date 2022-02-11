static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 * V_4 , T_1 V_5 , T_1 * V_6 , T_1 V_7 )
{
T_1 * V_8 ;
int V_9 , V_10 ;
V_8 = F_2 ( 64 , V_11 ) ;
if ( ! V_8 )
return - V_12 ;
F_3 ( L_1 , V_3 ) ;
F_4 ( V_4 , V_5 , F_3 ) ;
F_3 ( L_2 ) ;
if ( V_5 > 62 ) {
F_5 ( L_3 ,
V_3 ) ;
V_5 = 62 ;
}
if ( V_7 > 62 ) {
F_5 ( L_4 ,
V_3 ) ;
V_7 = 62 ;
}
V_8 [ 0 ] = V_13 ;
V_8 [ 1 ] = V_3 << 1 ;
if ( V_6 != NULL ) {
V_8 [ 0 ] |= V_7 ;
V_8 [ 1 ] |= 1 ;
}
memcpy ( & V_8 [ 2 ] , V_4 , V_5 ) ;
V_9 = F_6 ( V_2 ,
F_7 ( V_2 , 0x01 ) ,
V_8 , 2 + V_5 ,
NULL , 1000 ) ;
if ( V_9 < 0 ) {
F_5 ( L_5 , V_3 , V_9 ) ;
goto F_5;
}
V_9 = F_6 ( V_2 ,
F_8 ( V_2 , 0x01 ) ,
V_8 , 64 , & V_10 , 1000 ) ;
if ( V_9 < 0 ) {
F_5 ( L_6 , V_3 , V_9 ) ;
goto F_5;
}
if ( V_8 [ 0 ] != V_14 ) {
F_5 ( L_7 , V_3 , V_8 [ 0 ] ) ;
if ( ! ( V_8 [ 0 ] == V_15 &&
V_3 == 0x60
) )
goto F_5;
}
F_3 ( L_8 , V_8 [ 0 ] ) ;
if ( V_6 != NULL ) {
memcpy ( V_6 , & V_8 [ 2 ] , V_7 ) ;
F_3 ( L_9 , V_7 ) ;
F_4 ( V_6 , V_7 , F_3 ) ;
}
F_3 ( L_10 ) ;
F_5:
F_9 ( V_8 ) ;
return V_9 ;
}
static int F_10 ( struct V_16 * V_17 , struct V_18 * V_19 ,
int V_20 )
{
int V_9 = 0 , V_21 ;
struct V_22 * V_23 = F_11 ( V_17 ) ;
if ( F_12 ( & V_23 -> V_24 ) < 0 )
return - V_25 ;
for ( V_21 = 0 ; V_21 < V_20 ; V_21 ++ ) {
if ( V_21 + 1 < V_20 && V_19 [ V_21 + 1 ] . V_26 & V_27 ) {
V_9 = F_1 ( V_23 -> V_2 , V_19 [ V_21 + 1 ] . V_28 ,
V_19 [ V_21 ] . V_29 , V_19 [ V_21 ] . V_30 ,
V_19 [ V_21 + 1 ] . V_29 , V_19 [ V_21 + 1 ] . V_30 ) ;
if ( V_9 != 0 )
break;
V_21 ++ ;
} else {
V_9 = F_1 ( V_23 -> V_2 , V_19 [ V_21 ] . V_28 ,
V_19 [ V_21 ] . V_29 , V_19 [ V_21 ] . V_30 ,
NULL , 0 ) ;
if ( V_9 != 0 )
break;
}
}
if ( V_9 == 0 )
V_9 = V_21 ;
F_13 ( & V_23 -> V_24 ) ;
return V_9 ;
}
static T_2 F_14 ( struct V_16 * V_31 )
{
return V_32 ;
}
static int F_15 ( struct V_22 * V_23 , int V_33 ,
enum V_34 V_35 )
{
struct V_36 * V_37 = V_23 -> V_38 ;
T_1 * V_39 = V_37 -> V_29 ;
int V_9 ;
V_39 [ 0 ] = V_33 ? V_40 : V_41 ;
if ( V_42 && V_35 != V_43 )
return 0 ;
switch ( V_35 ) {
case V_44 :
V_39 [ 1 ] = 0x82 ;
break;
case V_45 :
V_39 [ 1 ] = 0x82 ;
if ( V_33 ) {
V_39 [ 2 ] = 0x02 ;
V_39 [ 3 ] = 10 ;
V_39 [ 4 ] = 10 ;
} else {
V_39 [ 2 ] = 0xff ;
V_39 [ 3 ] = 50 ;
V_39 [ 4 ] = 50 ;
}
V_39 [ 5 ] = 1 ;
break;
default:
case V_43 :
V_39 [ 1 ] = 0x80 ;
break;
}
if ( F_12 ( & V_23 -> V_24 ) < 0 )
return - V_25 ;
V_9 = F_16 ( V_23 -> V_2 , F_17 ( V_23 -> V_2 , 0 ) ,
V_33 ? V_40 : V_41 ,
V_46 | V_47 ,
0 , 0 ,
V_39 , 8 , 500 ) ;
F_13 ( & V_23 -> V_24 ) ;
return V_9 ;
}
static int F_18 ( struct V_22 * V_23 , T_1 V_33 , T_1 V_48 )
{
struct V_36 * V_37 = V_23 -> V_38 ;
T_1 * V_8 = V_37 -> V_29 ;
int V_9 ;
V_8 [ 0 ] = 0 ;
if ( F_12 ( & V_23 -> V_24 ) < 0 )
return - V_25 ;
V_9 = F_16 ( V_23 -> V_2 , F_17 ( V_23 -> V_2 , 0 ) ,
V_49 ,
V_46 | V_47 ,
( V_33 << 8 ) | V_48 , 0 ,
V_8 , 1 , 500 ) ;
F_13 ( & V_23 -> V_24 ) ;
return V_9 ;
}
static void F_19 ( struct V_50 * V_51 )
{
struct V_36 * V_37 =
F_20 ( V_51 , struct V_36 , V_52 . V_51 ) ;
struct V_53 * V_54 = V_37 -> V_55 -> V_31 [ 0 ] . V_56 [ 0 ] . V_54 ;
if ( V_37 -> V_57 == 0 )
goto V_58;
if ( V_54 != NULL ) {
enum V_59 V_60 ;
if ( V_54 -> V_61 . V_62 ( V_54 , & V_60 ) != 0 )
goto V_58;
if ( V_60 & V_63 ) {
T_2 V_64 ;
if ( V_54 -> V_61 . V_65 ( V_54 , & V_64 ) != 0 )
goto V_58;
if ( V_64 > 1000 )
F_15 ( V_37 -> V_55 , 0 , V_45 ) ;
else
F_15 ( V_37 -> V_55 , 0 , V_44 ) ;
} else
F_15 ( V_37 -> V_55 , 0 , V_43 ) ;
}
V_58:
F_21 ( & V_37 -> V_52 ,
F_22 ( 500 ) ) ;
}
static int F_23 ( struct V_1 * V_2 ,
struct V_66 * V_67 ,
struct V_68 * * V_69 , int * V_70 )
{
int V_9 ;
T_1 * V_71 ;
V_71 = F_2 ( 3 , V_11 ) ;
if ( ! V_71 )
return - V_12 ;
if ( F_24 ( V_2 , 0 , 1 ) != 0 )
F_5 ( L_11 ) ;
else
F_25 ( L_12 ) ;
* V_70 = 0 ;
V_9 = F_16 ( V_2 , F_26 ( V_2 , 0 ) ,
V_72 ,
V_46 | V_73 ,
0 , 0 ,
V_71 , 3 , 500 ) ;
if ( V_9 < 0 )
* V_70 = 1 ;
else {
F_25 ( L_13 , V_71 [ 1 ] , V_71 [ 2 ] ) ;
* V_70 = 0 ;
}
F_9 ( V_71 ) ;
return 0 ;
}
static int F_27 ( struct V_22 * V_23 , int V_74 )
{
struct V_36 * V_37 = V_23 -> V_38 ;
V_37 -> V_57 = V_74 ;
if ( V_42 )
return 0 ;
F_15 ( V_23 , 0 , V_43 ) ;
F_15 ( V_23 , 1 , V_44 ) ;
return 0 ;
}
static T_1 F_28 ( const T_1 * V_8 , T_3 V_75 )
{
T_1 V_76 = 0 ;
while ( -- V_75 )
V_76 ^= * V_8 ++ ;
return V_76 ;
}
static int F_29 ( struct V_22 * V_23 ,
T_3 V_77 , T_1 * V_8 , T_3 V_75 , T_1 V_78 )
{
T_1 V_79 = V_77 & 0xff ;
struct V_18 V_19 [] = {
{
. V_28 = 0x50 | ( ( V_77 >> 8 ) & 0x3 ) ,
. V_29 = & V_79 ,
. V_30 = 1
} , {
. V_28 = 0x50 | ( ( V_77 >> 8 ) & 0x3 ) ,
. V_26 = V_27 ,
. V_29 = V_8 ,
. V_30 = V_75
}
} ;
while ( V_78 -- ) {
int V_60 ;
if ( F_30 ( & V_23 -> V_80 , V_19 , 2 ) != 2 )
break;
V_60 =
F_28 ( V_8 , V_75 - 1 ) == V_8 [ V_75 - 1 ] ;
if ( V_60 )
return 0 ;
}
return - V_81 ;
}
static int F_31 ( struct V_22 * V_23 ,
T_1 V_82 [] )
{
T_1 V_29 [ V_83 ] ;
if ( F_29 ( V_23 , V_84 ,
V_29 , V_83 , 4 ) != 0 )
return - V_85 ;
memcpy ( V_82 , V_29 , 6 ) ;
return 0 ;
}
static int F_32 ( struct V_53 * V_54 ,
enum V_86 V_87 )
{
int V_21 ;
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
for ( V_21 = 0 ; V_21 < 3 ; V_21 ++ )
if ( V_92 . V_93 ( V_54 , V_21 + 2 , 0 ,
V_88 [ V_21 ] , 0 ) != 0 )
return - V_81 ;
return 0 ;
}
static int F_33 ( struct V_94 * V_95 )
{
struct V_1 * V_2 = V_95 -> V_55 -> V_2 ;
int V_9 ;
V_95 -> V_56 [ 0 ] . V_54 = F_34 ( V_96 , & V_92 ,
& V_95 -> V_55 -> V_80 , V_97 ) ;
if ( V_95 -> V_56 [ 0 ] . V_54 ) {
const struct V_98 * V_99 ;
V_99 = F_34 ( V_100 ,
V_95 -> V_56 [ 0 ] . V_54 ,
& V_101 ,
& V_95 -> V_55 -> V_80 ) ;
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
if ( V_95 -> V_56 [ 0 ] . V_54 -> V_61 . V_113 )
V_95 -> V_56 [ 0 ] . V_54 -> V_61 . V_113 ( V_95 -> V_56 [ 0 ] . V_54 ) ;
if ( F_12 ( & V_95 -> V_55 -> V_24 ) < 0 )
return - V_25 ;
V_9 = F_16 ( V_2 , F_17 ( V_2 , 0 ) ,
V_114 ,
V_46 | V_47 ,
0 , 0 ,
NULL , 0 , 500 ) ;
F_13 ( & V_95 -> V_55 -> V_24 ) ;
if ( V_9 != 0 )
F_5 ( L_14 ) ;
V_95 -> V_56 [ 0 ] . V_54 -> V_61 . V_115 = F_32 ;
F_35 ( V_95 -> V_56 [ 0 ] . V_54 -> V_61 . F_25 . V_116 , V_95 -> V_55 -> V_69 -> V_116 ,
sizeof( V_95 -> V_56 [ 0 ] . V_54 -> V_61 . F_25 . V_116 ) ) ;
} else {
F_36 ( V_95 -> V_56 [ 0 ] . V_54 ) ;
V_95 -> V_56 [ 0 ] . V_54 = NULL ;
}
}
F_18 ( V_95 -> V_55 , 1 , 1 ) ;
return V_95 -> V_56 [ 0 ] . V_54 == NULL ? - V_85 : 0 ;
}
static int F_37 ( struct V_22 * V_23 )
{
struct V_36 * V_37 = V_23 -> V_38 ;
T_1 * V_29 = V_37 -> V_29 ;
T_1 * V_8 ;
int V_9 ;
struct V_117 V_118 ;
V_29 [ 0 ] = V_119 ;
V_29 [ 1 ] = 0x08 ;
V_29 [ 2 ] = 0x8f ;
V_29 [ 3 ] = V_120 ;
V_29 [ 4 ] = V_121 ;
if ( F_12 ( & V_23 -> V_24 ) < 0 )
return - V_25 ;
V_9 = F_16 ( V_23 -> V_2 , F_17 ( V_23 -> V_2 , 0 ) ,
V_119 ,
V_46 | V_47 ,
0 , 0 ,
V_29 , 5 , 500 ) ;
if ( V_9 < 0 )
goto V_122;
V_29 [ 1 ] = 0 ;
V_29 [ 2 ] = 0 ;
V_9 = F_16 ( V_23 -> V_2 , F_26 ( V_23 -> V_2 , 0 ) ,
V_119 ,
V_46 | V_73 ,
0x8080 , 0 ,
V_29 , 62 , 500 ) ;
V_122:
F_13 ( & V_23 -> V_24 ) ;
if ( V_9 < 0 )
return V_9 ;
if ( V_9 == 1 )
return 0 ;
V_8 = V_29 + 1 ;
#if 0
deb_rc("RC: %d ", ret);
debug_dump(b, ret, deb_rc);
#endif
V_118 . V_123 = 0 ;
while ( 1 ) {
V_118 . V_123 = ! V_118 . V_123 ;
V_118 . V_124 = ( * V_8 * V_125 * V_126 ) / 1000 ;
F_38 ( V_23 -> V_127 , & V_118 ) ;
V_8 ++ ;
if ( * V_8 == 0xff ) {
V_118 . V_123 = 0 ;
V_118 . V_124 = 888888 * 2 ;
F_38 ( V_23 -> V_127 , & V_118 ) ;
break;
}
}
F_39 ( V_23 -> V_127 ) ;
return 1 ;
}
static int F_40 ( struct V_22 * V_23 )
{
int V_9 = F_37 ( V_23 ) ;
if ( V_9 < 0 )
return V_9 ;
if ( V_9 == 0 )
return 0 ;
if ( ! V_42 )
F_15 ( V_23 , 1 , V_45 ) ;
return 0 ;
}
static int F_41 ( struct V_128 * V_129 ,
const struct V_130 * V_131 )
{
struct V_22 * V_55 ;
if ( F_42 ( V_129 , & V_132 , V_133 ,
& V_55 , V_134 ) != 0 )
return - V_85 ;
if ( V_55 ) {
struct V_36 * V_37 = V_55 -> V_38 ;
V_37 -> V_55 = V_55 ;
if ( ! V_42 ) {
F_43 ( & V_37 -> V_52 ,
F_19 ) ;
F_21 ( & V_37 -> V_52 ,
F_22 ( 500 ) ) ;
}
}
return 0 ;
}
static void F_44 ( struct V_128 * V_129 )
{
struct V_22 * V_55 = F_45 ( V_129 ) ;
if ( V_55 != NULL ) {
struct V_36 * V_37 = V_55 -> V_38 ;
if ( V_37 != NULL )
F_46 ( & V_37 -> V_52 ) ;
}
F_47 ( V_129 ) ;
}
