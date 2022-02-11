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
static int F_13 ( struct V_21 * V_22 , int V_32 , enum V_33 V_34 )
{
int V_9 ;
T_1 V_35 [ 8 ] = {
V_32 ? V_36 : V_37 ,
0
} ;
if ( V_38 && V_34 != V_39 )
return 0 ;
switch ( V_34 ) {
case V_40 :
V_35 [ 1 ] = 0x82 ;
break;
case V_41 :
V_35 [ 1 ] = 0x82 ;
if ( V_32 ) {
V_35 [ 2 ] = 0x02 ;
V_35 [ 3 ] = 10 ;
V_35 [ 4 ] = 10 ;
} else {
V_35 [ 2 ] = 0xff ;
V_35 [ 3 ] = 50 ;
V_35 [ 4 ] = 50 ;
}
V_35 [ 5 ] = 1 ;
break;
default:
case V_39 :
V_35 [ 1 ] = 0x80 ;
break;
}
if ( F_10 ( & V_22 -> V_23 ) < 0 )
return - V_24 ;
V_9 = F_14 ( V_22 -> V_2 , F_15 ( V_22 -> V_2 , 0 ) ,
V_32 ? V_36 : V_37 ,
V_42 | V_43 ,
0 , 0 ,
V_35 , sizeof( V_35 ) , 500 ) ;
F_11 ( & V_22 -> V_23 ) ;
return V_9 ;
}
static int F_16 ( struct V_21 * V_22 , T_1 V_32 , T_1 V_44 )
{
int V_9 ;
T_1 V_8 = 0 ;
if ( F_10 ( & V_22 -> V_23 ) < 0 )
return - V_24 ;
V_9 = F_14 ( V_22 -> V_2 , F_15 ( V_22 -> V_2 , 0 ) ,
V_45 ,
V_42 | V_43 ,
( V_32 << 8 ) | V_44 , 0 ,
& V_8 , 1 , 500 ) ;
F_11 ( & V_22 -> V_23 ) ;
return V_9 ;
}
static void F_17 ( struct V_46 * V_47 )
{
struct V_48 * V_34 =
F_18 ( V_47 , struct V_48 , V_49 . V_47 ) ;
struct V_50 * V_51 = V_34 -> V_52 -> V_30 [ 0 ] . V_53 [ 0 ] . V_51 ;
if ( V_34 -> V_54 == 0 )
goto V_55;
if ( V_51 != NULL ) {
enum V_56 V_57 ;
if ( V_51 -> V_58 . V_59 ( V_51 , & V_57 ) != 0 )
goto V_55;
if ( V_57 & V_60 ) {
T_2 V_61 ;
if ( V_51 -> V_58 . V_62 ( V_51 , & V_61 ) != 0 )
goto V_55;
if ( V_61 > 1000 )
F_13 ( V_34 -> V_52 , 0 , V_41 ) ;
else
F_13 ( V_34 -> V_52 , 0 , V_40 ) ;
} else
F_13 ( V_34 -> V_52 , 0 , V_39 ) ;
}
V_55:
F_19 ( & V_34 -> V_49 ,
F_20 ( 500 ) ) ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_63 * V_64 ,
struct V_65 * * V_66 , int * V_67 )
{
int V_9 ;
T_1 V_68 [ 3 ] ;
if ( F_22 ( V_2 , 0 , 1 ) != 0 )
F_4 ( L_11 ) ;
else
F_23 ( L_12 ) ;
* V_67 = 0 ;
V_9 = F_14 ( V_2 , F_24 ( V_2 , 0 ) ,
V_69 ,
V_42 | V_70 ,
0 , 0 ,
V_68 , sizeof( V_68 ) , 500 ) ;
if ( V_9 < 0 )
* V_67 = 1 ;
else {
F_23 ( L_13 , V_68 [ 1 ] , V_68 [ 2 ] ) ;
* V_67 = 0 ;
}
return 0 ;
}
static int F_25 ( struct V_21 * V_22 , int V_71 )
{
struct V_48 * V_34 = V_22 -> V_72 ;
V_34 -> V_54 = V_71 ;
if ( V_38 )
return 0 ;
F_13 ( V_22 , 0 , V_39 ) ;
F_13 ( V_22 , 1 , V_40 ) ;
return 0 ;
}
static T_1 F_26 ( const T_1 * V_8 , T_3 V_73 )
{
T_1 V_74 = 0 ;
while ( -- V_73 )
V_74 ^= * V_8 ++ ;
return V_74 ;
}
static int F_27 ( struct V_21 * V_22 ,
T_3 V_75 , T_1 * V_8 , T_3 V_73 , T_1 V_76 )
{
T_1 V_77 = V_75 & 0xff ;
struct V_17 V_18 [] = {
{
. V_27 = 0x50 | ( ( V_75 >> 8 ) & 0x3 ) ,
. V_28 = & V_77 ,
. V_29 = 1
} , {
. V_27 = 0x50 | ( ( V_75 >> 8 ) & 0x3 ) ,
. V_25 = V_26 ,
. V_28 = V_8 ,
. V_29 = V_73
}
} ;
while ( V_76 -- ) {
int V_57 ;
if ( F_28 ( & V_22 -> V_78 , V_18 , 2 ) != 2 )
break;
V_57 =
F_26 ( V_8 , V_73 - 1 ) == V_8 [ V_73 - 1 ] ;
if ( V_57 )
return 0 ;
}
return - V_79 ;
}
static int F_29 ( struct V_21 * V_22 ,
T_1 V_80 [] )
{
T_1 V_28 [ V_81 ] ;
if ( F_27 ( V_22 , V_82 ,
V_28 , V_81 , 4 ) != 0 )
return - V_12 ;
memcpy ( V_80 , V_28 , 6 ) ;
return 0 ;
}
static int F_30 ( struct V_50 * V_51 ,
enum V_83 V_84 )
{
int V_20 ;
T_1 V_85 [ 3 ] = { 0 } ;
V_85 [ 2 ] = 1 ;
switch ( V_84 ) {
case V_86 :
V_85 [ 0 ] = 1 ;
break;
case V_87 :
V_85 [ 0 ] = 1 ;
V_85 [ 1 ] = 1 ;
break;
default:
case V_88 :
break;
}
for ( V_20 = 0 ; V_20 < 3 ; V_20 ++ )
if ( V_89 . V_90 ( V_51 , V_20 + 2 , 0 ,
V_85 [ V_20 ] , 0 ) != 0 )
return - V_79 ;
return 0 ;
}
static int F_31 ( struct V_91 * V_92 )
{
struct V_1 * V_2 = V_92 -> V_52 -> V_2 ;
int V_9 ;
V_92 -> V_53 [ 0 ] . V_51 = F_32 ( V_93 , & V_89 ,
& V_92 -> V_52 -> V_78 , V_94 ) ;
if ( V_92 -> V_53 [ 0 ] . V_51 ) {
struct V_95 * V_96 ;
V_96 = F_32 ( V_97 ,
V_92 -> V_53 [ 0 ] . V_51 ,
& V_98 ,
& V_92 -> V_52 -> V_78 ) ;
if ( V_96 ) {
V_89 . V_99 = V_96 -> V_99 ;
V_89 . V_100 = V_96 -> V_100 ;
V_89 . V_101 = V_96 -> V_101 ;
V_89 . V_102 = V_96 -> V_102 ;
V_89 . V_103 = V_96 -> V_103 ;
V_89 . V_104 = V_96 -> V_104 ;
V_89 . V_105 = V_96 -> V_105 ;
V_89 . V_106 = V_96 -> V_106 ;
V_89 . V_107 = V_96 -> V_107 ;
V_89 . V_108 = V_96 -> V_108 ;
V_89 . V_109 = V_96 -> V_109 ;
if ( V_92 -> V_53 [ 0 ] . V_51 -> V_58 . V_110 )
V_92 -> V_53 [ 0 ] . V_51 -> V_58 . V_110 ( V_92 -> V_53 [ 0 ] . V_51 ) ;
if ( F_10 ( & V_92 -> V_52 -> V_23 ) < 0 )
return - V_24 ;
V_9 = F_14 ( V_2 , F_15 ( V_2 , 0 ) ,
V_111 ,
V_42 | V_43 ,
0 , 0 ,
NULL , 0 , 500 ) ;
F_11 ( & V_92 -> V_52 -> V_23 ) ;
if ( V_9 != 0 )
F_4 ( L_14 ) ;
V_92 -> V_53 [ 0 ] . V_51 -> V_58 . V_112 = F_30 ;
F_33 ( V_92 -> V_53 [ 0 ] . V_51 -> V_58 . F_23 . V_113 , V_92 -> V_52 -> V_66 -> V_113 ,
sizeof( V_92 -> V_53 [ 0 ] . V_51 -> V_58 . F_23 . V_113 ) ) ;
} else {
F_34 ( V_92 -> V_53 [ 0 ] . V_51 ) ;
V_92 -> V_53 [ 0 ] . V_51 = NULL ;
}
}
F_16 ( V_92 -> V_52 , 1 , 1 ) ;
return V_92 -> V_53 [ 0 ] . V_51 == NULL ? - V_12 : 0 ;
}
static int F_35 ( struct V_21 * V_22 )
{
T_1 V_28 [ 62 ] , * V_8 ;
int V_9 ;
struct V_114 V_115 ;
V_28 [ 0 ] = V_116 ;
V_28 [ 1 ] = 0x08 ;
V_28 [ 2 ] = 0x8f ;
V_28 [ 3 ] = V_117 ;
V_28 [ 4 ] = V_118 ;
if ( F_10 ( & V_22 -> V_23 ) < 0 )
return - V_24 ;
V_9 = F_14 ( V_22 -> V_2 , F_15 ( V_22 -> V_2 , 0 ) ,
V_116 ,
V_42 | V_43 ,
0 , 0 ,
V_28 , 5 , 500 ) ;
if ( V_9 < 0 )
goto V_119;
V_28 [ 1 ] = 0 ;
V_28 [ 2 ] = 0 ;
V_9 = F_14 ( V_22 -> V_2 , F_24 ( V_22 -> V_2 , 0 ) ,
V_116 ,
V_42 | V_70 ,
0x8080 , 0 ,
V_28 , sizeof( V_28 ) , 500 ) ;
V_119:
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
V_115 . V_120 = 0 ;
while ( 1 ) {
V_115 . V_120 = ! V_115 . V_120 ;
V_115 . V_121 = ( * V_8 * V_122 * V_123 ) / 1000 ;
F_36 ( V_22 -> V_124 , & V_115 ) ;
V_8 ++ ;
if ( * V_8 == 0xff ) {
V_115 . V_120 = 0 ;
V_115 . V_121 = 888888 * 2 ;
F_36 ( V_22 -> V_124 , & V_115 ) ;
break;
}
}
F_37 ( V_22 -> V_124 ) ;
return 1 ;
}
static int F_38 ( struct V_21 * V_22 )
{
int V_9 = F_35 ( V_22 ) ;
if ( V_9 < 0 )
return V_9 ;
if ( V_9 == 0 )
return 0 ;
if ( ! V_38 )
F_13 ( V_22 , 1 , V_41 ) ;
return 0 ;
}
static int F_39 ( struct V_125 * V_126 ,
const struct V_127 * V_128 )
{
struct V_21 * V_52 ;
if ( F_40 ( V_126 , & V_129 , V_130 ,
& V_52 , V_131 ) != 0 )
return - V_12 ;
if ( V_52 ) {
struct V_48 * V_34 = V_52 -> V_72 ;
V_34 -> V_52 = V_52 ;
if ( ! V_38 ) {
F_41 ( & V_34 -> V_49 ,
F_17 ) ;
F_19 ( & V_34 -> V_49 ,
F_20 ( 500 ) ) ;
}
}
return 0 ;
}
static void F_42 ( struct V_125 * V_126 )
{
struct V_21 * V_52 = F_43 ( V_126 ) ;
if ( V_52 != NULL ) {
struct V_48 * V_34 = V_52 -> V_72 ;
if ( V_34 != NULL )
F_44 ( & V_34 -> V_49 ) ;
}
F_45 ( V_126 ) ;
}
