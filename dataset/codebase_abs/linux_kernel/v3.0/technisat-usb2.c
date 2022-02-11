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
V_5 = 62 ;
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
struct V_50 * V_51 = V_34 -> V_52 -> V_30 [ 0 ] . V_51 ;
if ( V_34 -> V_53 == 0 )
goto V_54;
if ( V_51 != NULL ) {
enum V_55 V_56 ;
if ( V_51 -> V_57 . V_58 ( V_51 , & V_56 ) != 0 )
goto V_54;
if ( V_56 & V_59 ) {
T_2 V_60 ;
if ( V_51 -> V_57 . V_61 ( V_51 , & V_60 ) != 0 )
goto V_54;
if ( V_60 > 1000 )
F_13 ( V_34 -> V_52 , 0 , V_41 ) ;
else
F_13 ( V_34 -> V_52 , 0 , V_40 ) ;
} else
F_13 ( V_34 -> V_52 , 0 , V_39 ) ;
}
V_54:
F_19 ( & V_34 -> V_49 ,
F_20 ( 500 ) ) ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_62 * V_63 ,
struct V_64 * * V_65 , int * V_66 )
{
int V_9 ;
T_1 V_67 [ 3 ] ;
if ( F_22 ( V_2 , 0 , 1 ) != 0 )
F_4 ( L_11 ) ;
else
F_23 ( L_12 ) ;
* V_66 = 0 ;
V_9 = F_14 ( V_2 , F_24 ( V_2 , 0 ) ,
V_68 ,
V_42 | V_69 ,
0 , 0 ,
V_67 , sizeof( V_67 ) , 500 ) ;
if ( V_9 < 0 )
* V_66 = 1 ;
else {
F_23 ( L_13 , V_67 [ 1 ] , V_67 [ 2 ] ) ;
* V_66 = 0 ;
}
return 0 ;
}
static int F_25 ( struct V_21 * V_22 , int V_70 )
{
struct V_48 * V_34 = V_22 -> V_71 ;
V_34 -> V_53 = V_70 ;
if ( V_38 )
return 0 ;
F_13 ( V_22 , 0 , V_39 ) ;
F_13 ( V_22 , 1 , V_40 ) ;
return 0 ;
}
static T_1 F_26 ( const T_1 * V_8 , T_3 V_72 )
{
T_1 V_73 = 0 ;
while ( -- V_72 )
V_73 ^= * V_8 ++ ;
return V_73 ;
}
static int F_27 ( struct V_21 * V_22 ,
T_3 V_74 , T_1 * V_8 , T_3 V_72 , T_1 V_75 )
{
T_1 V_76 = V_74 & 0xff ;
struct V_17 V_18 [] = {
{
. V_27 = 0x50 | ( ( V_74 >> 8 ) & 0x3 ) ,
. V_28 = & V_76 ,
. V_29 = 1
} , {
. V_27 = 0x50 | ( ( V_74 >> 8 ) & 0x3 ) ,
. V_25 = V_26 ,
. V_28 = V_8 ,
. V_29 = V_72
}
} ;
while ( V_75 -- ) {
int V_56 ;
if ( F_28 ( & V_22 -> V_77 , V_18 , 2 ) != 2 )
break;
V_56 =
F_26 ( V_8 , V_72 - 1 ) == V_8 [ V_72 - 1 ] ;
if ( V_56 )
return 0 ;
}
return - V_78 ;
}
static int F_29 ( struct V_21 * V_22 ,
T_1 V_79 [] )
{
T_1 V_28 [ V_80 ] ;
if ( F_27 ( V_22 , V_81 ,
V_28 , V_80 , 4 ) != 0 )
return - V_12 ;
memcpy ( V_79 , V_28 , 6 ) ;
return 0 ;
}
static int F_30 ( struct V_50 * V_51 ,
T_4 V_82 )
{
int V_20 ;
T_1 V_83 [ 3 ] = { 0 } ;
V_83 [ 2 ] = 1 ;
switch ( V_82 ) {
case V_84 :
V_83 [ 0 ] = 1 ;
break;
case V_85 :
V_83 [ 0 ] = 1 ;
V_83 [ 1 ] = 1 ;
break;
default:
case V_86 :
break;
}
for ( V_20 = 0 ; V_20 < 3 ; V_20 ++ )
if ( F_31 ( V_51 , V_20 + 2 , 0 , V_83 [ V_20 ] , 0 ) != 0 )
return - V_78 ;
return 0 ;
}
static int F_32 ( struct V_87 * V_88 )
{
struct V_1 * V_2 = V_88 -> V_52 -> V_2 ;
int V_9 ;
V_88 -> V_51 = F_33 ( V_89 , & V_90 ,
& V_88 -> V_52 -> V_77 , V_91 ) ;
if ( V_88 -> V_51 ) {
struct V_92 * V_93 ;
V_93 = F_33 ( V_94 ,
V_88 -> V_51 ,
& V_95 ,
& V_88 -> V_52 -> V_77 ) ;
if ( V_93 ) {
V_90 . V_96 = V_93 -> V_96 ;
V_90 . V_97 = V_93 -> V_97 ;
V_90 . V_98 = V_93 -> V_98 ;
V_90 . V_99 = V_93 -> V_99 ;
V_90 . V_100 = V_93 -> V_100 ;
V_90 . V_101 = V_93 -> V_101 ;
V_90 . V_102 = V_93 -> V_102 ;
V_90 . V_103 = V_93 -> V_103 ;
V_90 . V_104 = V_93 -> V_104 ;
V_90 . V_105 = V_93 -> V_105 ;
V_90 . V_106 = V_93 -> V_106 ;
if ( V_88 -> V_51 -> V_57 . V_107 )
V_88 -> V_51 -> V_57 . V_107 ( V_88 -> V_51 ) ;
if ( F_10 ( & V_88 -> V_52 -> V_23 ) < 0 )
return - V_24 ;
V_9 = F_14 ( V_2 , F_15 ( V_2 , 0 ) ,
V_108 ,
V_42 | V_43 ,
0 , 0 ,
NULL , 0 , 500 ) ;
F_11 ( & V_88 -> V_52 -> V_23 ) ;
if ( V_9 != 0 )
F_4 ( L_14 ) ;
V_88 -> V_51 -> V_57 . V_109 = F_30 ;
F_34 ( V_88 -> V_51 -> V_57 . F_23 . V_110 , V_88 -> V_52 -> V_65 -> V_110 ,
sizeof( V_88 -> V_51 -> V_57 . F_23 . V_110 ) ) ;
} else {
F_35 ( V_88 -> V_51 ) ;
V_88 -> V_51 = NULL ;
}
}
F_16 ( V_88 -> V_52 , 1 , 1 ) ;
return V_88 -> V_51 == NULL ? - V_12 : 0 ;
}
static int F_36 ( struct V_21 * V_22 )
{
T_1 V_28 [ 62 ] , * V_8 ;
int V_9 ;
struct V_111 V_112 ;
V_28 [ 0 ] = V_113 ;
V_28 [ 1 ] = 0x08 ;
V_28 [ 2 ] = 0x8f ;
V_28 [ 3 ] = V_114 ;
V_28 [ 4 ] = V_115 ;
if ( F_10 ( & V_22 -> V_23 ) < 0 )
return - V_24 ;
V_9 = F_14 ( V_22 -> V_2 , F_15 ( V_22 -> V_2 , 0 ) ,
V_113 ,
V_42 | V_43 ,
0 , 0 ,
V_28 , 5 , 500 ) ;
if ( V_9 < 0 )
goto V_116;
V_28 [ 1 ] = 0 ;
V_28 [ 2 ] = 0 ;
V_9 = F_14 ( V_22 -> V_2 , F_24 ( V_22 -> V_2 , 0 ) ,
V_113 ,
V_42 | V_69 ,
0x8080 , 0 ,
V_28 , sizeof( V_28 ) , 500 ) ;
V_116:
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
V_112 . V_117 = 0 ;
while ( 1 ) {
V_112 . V_117 = ! V_112 . V_117 ;
V_112 . V_118 = ( * V_8 * V_119 * V_120 ) / 1000 ;
F_37 ( V_22 -> V_121 , & V_112 ) ;
V_8 ++ ;
if ( * V_8 == 0xff ) {
V_112 . V_117 = 0 ;
V_112 . V_118 = 888888 * 2 ;
F_37 ( V_22 -> V_121 , & V_112 ) ;
break;
}
}
F_38 ( V_22 -> V_121 ) ;
return 1 ;
}
static int F_39 ( struct V_21 * V_22 )
{
int V_9 = F_36 ( V_22 ) ;
if ( V_9 < 0 )
return V_9 ;
if ( V_9 == 0 )
return 0 ;
if ( ! V_38 )
F_13 ( V_22 , 1 , V_41 ) ;
return 0 ;
}
static int F_40 ( struct V_122 * V_123 ,
const struct V_124 * V_125 )
{
struct V_21 * V_52 ;
if ( F_41 ( V_123 , & V_126 , V_127 ,
& V_52 , V_128 ) != 0 )
return - V_12 ;
if ( V_52 ) {
struct V_48 * V_34 = V_52 -> V_71 ;
V_34 -> V_52 = V_52 ;
if ( ! V_38 ) {
F_42 ( & V_34 -> V_49 ,
F_17 ) ;
F_19 ( & V_34 -> V_49 ,
F_20 ( 500 ) ) ;
}
}
return 0 ;
}
static void F_43 ( struct V_122 * V_123 )
{
struct V_21 * V_52 = F_44 ( V_123 ) ;
if ( V_52 != NULL ) {
struct V_48 * V_34 = V_52 -> V_71 ;
if ( V_34 != NULL ) {
F_45 ( & V_34 -> V_49 ) ;
F_46 () ;
}
}
F_47 ( V_123 ) ;
}
static int T_5 F_48 ( void )
{
int V_129 = F_49 ( & V_130 ) ;
if ( V_129 ) {
F_4 ( L_15 , V_129 ) ;
return V_129 ;
}
return 0 ;
}
static void T_6 F_50 ( void )
{
F_51 ( & V_130 ) ;
}
