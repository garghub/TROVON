static int F_1 ( int V_1 [] , int V_2 )
{
int V_3 , V_4 ;
if ( V_2 <= 0 )
return V_1 [ 0 ] ;
if ( V_2 >= 40 )
return V_1 [ 4 ] ;
V_3 = V_2 / 10 ;
V_4 = V_2 % 10 ;
return V_1 [ V_3 ] + ( ( ( V_1 [ V_3 + 1 ] - V_1 [ V_3 ] ) * V_4 ) / 10 ) ;
}
static int F_2 ( struct V_5 * V_6 )
{
int V_7 , V_8 , V_9 , V_10 , V_11 [ 5 ] ;
if ( V_6 -> V_12 && F_3 ( V_13 , V_6 -> V_12 +
F_4 ( V_14 ) ) )
return 0 ;
if ( V_6 -> V_12 == 0 ) {
V_9 = 0 ;
V_10 = V_15 ;
} else {
V_9 = V_16 ;
V_10 = V_17 - V_9 + 1 ;
}
V_7 = F_5 ( V_6 -> V_18 , V_6 -> V_19 + V_9 , V_9 , V_10 ) ;
if ( V_7 != V_10 ) {
F_6 ( V_6 -> V_20 , L_1 ,
V_6 -> V_18 ) ;
return 1 ;
}
V_6 -> V_12 = V_13 ;
V_6 -> V_21 = ( V_6 -> V_19 [ V_16 ] << 3 ) |
( V_6 -> V_19 [ V_22 ] >> 5 ) ;
V_6 -> V_23 = V_6 -> V_21 * 4880 ;
V_6 -> V_24 =
( ( ( signed char ) V_6 -> V_19 [ V_25 ] ) << 5 ) |
( V_6 -> V_19 [ V_26 ] >> 3 ) ;
V_6 -> V_27 = V_6 -> V_24 * 625 ;
V_6 -> V_28 =
( ( ( signed char ) V_6 -> V_19 [ V_29 ] ) << 8 ) |
V_6 -> V_19 [ V_30 ] ;
V_6 -> V_31 = V_6 -> V_28 * 250 ;
V_6 -> V_32 = ( ( ( signed char ) V_6 -> V_19 [ V_33 ] ) << 3 ) |
( V_6 -> V_19 [ V_17 ] >> 5 ) ;
V_6 -> V_34 = V_6 -> V_32 + ( V_6 -> V_32 / 4 ) ;
if ( V_6 -> V_19 [ V_35 ] < F_7 ( V_36 ) )
V_6 -> V_37 = V_36 [
( unsigned int ) V_6 -> V_19 [ V_35 ] ] ;
else
V_6 -> V_37 = V_6 -> V_19 [ V_35 ] * 10 ;
V_6 -> V_37 *= 1000 ;
V_6 -> V_38 = V_6 -> V_19 [ V_39 ] << 8 |
V_6 -> V_19 [ V_39 + 1 ] ;
if ( V_6 -> V_38 == 0 )
V_6 -> V_38 = V_6 -> V_37 / 1000L ;
V_11 [ 0 ] = V_6 -> V_38 ;
for ( V_8 = 1 ; V_8 < 5 ; V_8 ++ )
V_11 [ V_8 ] = V_11 [ V_8 - 1 ] + V_6 -> V_19 [ V_39 + 1 + V_8 ] ;
V_6 -> V_38 = F_1 ( V_11 , V_6 -> V_34 / 10 ) ;
V_6 -> V_38 *= 1000 ;
V_11 [ 4 ] = V_6 -> V_19 [ V_40 + 4 ] ;
for ( V_8 = 3 ; V_8 >= 0 ; V_8 -- )
V_11 [ V_8 ] = V_11 [ V_8 + 1 ] + V_6 -> V_19 [ V_40 + V_8 ] ;
V_6 -> V_41 = F_1 ( V_11 , V_6 -> V_34 / 10 ) ;
V_6 -> V_41 *= 1000 ;
if ( V_6 -> V_38 == V_6 -> V_41 )
V_6 -> V_42 = 0 ;
else
V_6 -> V_42 = ( ( V_6 -> V_31 - V_6 -> V_41 ) * 100L ) /
( V_6 -> V_38 - V_6 -> V_41 ) ;
if ( V_6 -> V_42 < 0 )
V_6 -> V_42 = 0 ;
if ( V_6 -> V_42 > 100 )
V_6 -> V_42 = 100 ;
if ( V_6 -> V_27 < - 100L )
V_6 -> V_43 = - ( ( V_6 -> V_31 - V_6 -> V_41 ) * 36L )
/ ( V_6 -> V_27 / 100L ) ;
else
V_6 -> V_43 = 0 ;
return 0 ;
}
static void F_8 ( struct V_5 * V_6 ,
unsigned int V_44 )
{
unsigned char V_45 [ 2 ] ;
V_44 *= 4L ;
V_44 /= 1000 ;
V_45 [ 0 ] = V_44 >> 8 ;
V_45 [ 1 ] = V_44 & 0xff ;
if ( F_9 ( V_6 -> V_18 , V_45 , V_29 , 2 ) < 2 )
F_6 ( V_6 -> V_20 , L_2 ) ;
}
static void F_10 ( struct V_5 * V_6 )
{
int V_46 = V_6 -> V_47 ;
F_2 ( V_6 ) ;
if ( V_6 -> V_47 == V_48 )
V_6 -> V_49 = 0 ;
if ( F_11 ( V_6 -> V_50 ) ) {
if ( V_6 -> V_27 > 10000 ) {
V_6 -> V_47 = V_51 ;
V_6 -> V_49 = 0 ;
} else if ( V_6 -> V_27 < - 5000 ) {
if ( V_6 -> V_47 != V_52 )
F_12 ( V_6 -> V_20 , L_3
L_4 ) ;
V_6 -> V_47 = V_52 ;
V_6 -> V_49 = 0 ;
} else if ( V_6 -> V_27 < 10000 &&
V_6 -> V_47 != V_53 ) {
V_6 -> V_49 ++ ;
if ( V_6 -> V_49 < 2 ) {
V_6 -> V_47 = V_51 ;
} else {
V_6 -> V_47 = V_53 ;
F_8 ( V_6 ,
V_6 -> V_38 ) ;
}
}
} else {
V_6 -> V_47 = V_54 ;
V_6 -> V_49 = 0 ;
}
if ( V_6 -> V_47 != V_46 )
F_13 ( V_6 -> V_50 ) ;
}
static void F_14 ( struct V_5 * V_6 ,
char V_55 )
{
if ( V_55 == V_6 -> V_19 [ V_56 ] )
return;
F_9 ( V_6 -> V_18 , & V_55 , V_57 , 1 ) ;
F_15 ( V_6 -> V_18 , V_58 ) ;
F_16 ( V_6 -> V_18 , V_58 ) ;
}
static void F_17 ( struct V_5 * V_6 ,
unsigned char V_37 )
{
if ( V_37 == V_6 -> V_19 [ V_35 ] )
return;
F_9 ( V_6 -> V_18 , & V_37 , V_35 , 1 ) ;
F_15 ( V_6 -> V_18 , V_58 ) ;
F_16 ( V_6 -> V_18 , V_58 ) ;
}
static void F_18 ( struct V_5 * V_6 ,
int V_59 )
{
unsigned char V_60 [ 2 ] = {
V_59 >> 8 ,
V_59 & 0xff
} ;
if ( V_60 [ 0 ] == V_6 -> V_19 [ V_39 ] &&
V_60 [ 1 ] == V_6 -> V_19 [ V_39 + 1 ] )
return;
F_9 ( V_6 -> V_18 , V_60 , V_39 , sizeof( V_60 ) ) ;
F_15 ( V_6 -> V_18 , V_61 ) ;
F_16 ( V_6 -> V_18 , V_61 ) ;
V_6 -> V_19 [ V_39 ] = V_60 [ 0 ] ;
V_6 -> V_19 [ V_39 + 1 ] = V_60 [ 1 ] ;
}
static void F_19 ( struct V_62 * V_63 )
{
struct V_5 * V_6 = F_20 ( V_63 ,
struct V_5 , V_64 . V_63 ) ;
const int V_65 = V_66 * 60 ;
F_21 ( V_6 -> V_20 , L_5 , V_67 ) ;
F_10 ( V_6 ) ;
F_22 ( V_6 -> V_68 , & V_6 -> V_64 , V_65 ) ;
}
static void F_23 ( struct V_69 * V_70 )
{
struct V_5 * V_6 = F_24 ( V_70 ) ;
F_21 ( V_6 -> V_20 , L_5 , V_67 ) ;
F_25 ( V_6 -> V_68 , & V_6 -> V_64 , V_66 / 10 ) ;
}
static void F_26 ( struct V_62 * V_63 )
{
char V_71 ;
struct V_5 * V_6 = F_20 ( V_63 ,
struct V_5 , V_72 . V_63 ) ;
F_21 ( V_6 -> V_20 , L_5 , V_67 ) ;
F_2 ( V_6 ) ;
if ( ! F_11 ( V_6 -> V_50 ) )
return;
V_71 = ( signed char ) V_6 -> V_24 +
( signed char ) V_6 -> V_19 [ V_73 ] ;
F_21 ( V_6 -> V_20 , L_6 , V_67 , V_71 ) ;
F_9 ( V_6 -> V_18 , & V_71 , V_73 , 1 ) ;
F_15 ( V_6 -> V_18 , V_58 ) ;
F_16 ( V_6 -> V_18 , V_58 ) ;
V_6 -> V_19 [ V_73 ] = V_71 ;
}
static void F_27 ( struct V_69 * V_70 )
{
struct V_5 * V_6 = F_24 ( V_70 ) ;
F_25 ( V_6 -> V_68 , & V_6 -> V_72 , V_66 * 20 ) ;
}
static int F_28 ( struct V_69 * V_70 ,
enum V_74 V_75 ,
union V_76 * V_77 )
{
struct V_5 * V_6 = F_24 ( V_70 ) ;
switch ( V_75 ) {
case V_78 :
V_77 -> V_79 = V_6 -> V_47 ;
return 0 ;
default:
break;
}
F_2 ( V_6 ) ;
switch ( V_75 ) {
case V_80 :
V_77 -> V_79 = V_6 -> V_23 ;
break;
case V_81 :
V_77 -> V_79 = V_6 -> V_27 ;
break;
case V_82 :
V_77 -> V_79 = V_6 -> V_37 ;
break;
case V_83 :
V_77 -> V_79 = V_6 -> V_38 ;
break;
case V_84 :
V_77 -> V_79 = V_6 -> V_41 ;
break;
case V_85 :
V_77 -> V_79 = V_6 -> V_31 ;
break;
case V_86 :
V_77 -> V_79 = V_6 -> V_34 ;
break;
case V_87 :
V_77 -> V_79 = V_6 -> V_43 ;
break;
case V_88 :
V_77 -> V_79 = V_6 -> V_42 ;
break;
default:
return - V_89 ;
}
return 0 ;
}
static int F_29 ( struct V_69 * V_70 ,
enum V_74 V_75 ,
const union V_76 * V_77 )
{
struct V_5 * V_6 = F_24 ( V_70 ) ;
switch ( V_75 ) {
case V_83 :
F_18 ( V_6 , V_77 -> V_79 / 1000L ) ;
break;
case V_85 :
F_8 ( V_6 , V_77 -> V_79 ) ;
break;
default:
return - V_90 ;
}
return 0 ;
}
static int F_30 ( struct V_69 * V_70 ,
enum V_74 V_75 )
{
switch ( V_75 ) {
case V_83 :
case V_85 :
return 1 ;
default:
break;
}
return 0 ;
}
static int F_31 ( struct V_91 * V_92 )
{
struct V_93 V_94 = {} ;
char V_55 ;
int V_95 = 0 ;
struct V_5 * V_6 ;
V_6 = F_32 ( & V_92 -> V_20 , sizeof( * V_6 ) , V_96 ) ;
if ( ! V_6 ) {
V_95 = - V_97 ;
goto V_98;
}
F_33 ( V_92 , V_6 ) ;
V_6 -> V_20 = & V_92 -> V_20 ;
V_6 -> V_18 = V_92 -> V_20 . V_99 ;
V_6 -> V_100 . V_101 = F_34 ( & V_92 -> V_20 ) ;
V_6 -> V_100 . type = V_102 ;
V_6 -> V_100 . V_103 = V_104 ;
V_6 -> V_100 . V_105 = F_7 ( V_104 ) ;
V_6 -> V_100 . V_106 = F_28 ;
V_6 -> V_100 . V_107 = F_29 ;
V_6 -> V_100 . V_108 =
F_30 ;
V_6 -> V_100 . V_109 = F_27 ;
V_6 -> V_100 . V_110 =
F_23 ;
V_94 . V_111 = V_6 ;
V_6 -> V_47 = V_48 ;
F_2 ( V_6 ) ;
V_55 = V_6 -> V_19 [ V_56 ] ;
if ( V_112 )
V_55 |= V_113 ;
else
V_55 &= ~ V_113 ;
F_14 ( V_6 , V_55 ) ;
if ( V_37 )
F_17 ( V_6 , V_37 ) ;
if ( V_114 )
F_8 ( V_6 , V_114 ) ;
V_6 -> V_50 = F_35 ( & V_92 -> V_20 , & V_6 -> V_100 , & V_94 ) ;
if ( F_36 ( V_6 -> V_50 ) ) {
F_37 ( V_6 -> V_20 , L_7 ) ;
V_95 = F_38 ( V_6 -> V_50 ) ;
goto V_115;
}
F_39 ( & V_6 -> V_64 , F_19 ) ;
F_39 ( & V_6 -> V_72 ,
F_26 ) ;
V_6 -> V_68 = F_40 ( F_34 ( & V_92 -> V_20 ) ) ;
if ( ! V_6 -> V_68 ) {
V_95 = - V_116 ;
goto V_117;
}
F_22 ( V_6 -> V_68 , & V_6 -> V_64 , V_66 * 1 ) ;
goto V_118;
V_117:
F_41 ( V_6 -> V_50 ) ;
V_115:
V_98:
V_118:
return V_95 ;
}
static int F_42 ( struct V_91 * V_92 )
{
struct V_5 * V_6 = F_43 ( V_92 ) ;
F_44 ( & V_6 -> V_64 ) ;
F_44 ( & V_6 -> V_72 ) ;
F_45 ( V_6 -> V_68 ) ;
F_41 ( V_6 -> V_50 ) ;
return 0 ;
}
static int F_46 ( struct V_91 * V_92 ,
T_1 V_119 )
{
struct V_5 * V_6 = F_43 ( V_92 ) ;
V_6 -> V_47 = V_48 ;
return 0 ;
}
static int F_47 ( struct V_91 * V_92 )
{
struct V_5 * V_6 = F_43 ( V_92 ) ;
V_6 -> V_47 = V_48 ;
F_13 ( V_6 -> V_50 ) ;
F_25 ( V_6 -> V_68 , & V_6 -> V_64 , V_66 ) ;
return 0 ;
}
