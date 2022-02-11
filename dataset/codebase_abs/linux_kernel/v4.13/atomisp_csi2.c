static struct V_1 * F_1 ( struct
V_2
* V_3 ,
struct
V_4 * V_5 ,
enum
V_6
V_7 , unsigned int V_8 )
{
if ( V_7 == V_9 )
return F_2 ( & V_3 -> V_10 , V_5 , V_8 ) ;
else
return & V_3 -> V_11 [ V_8 ] ;
}
static int F_3 ( struct V_12 * V_13 ,
struct V_4 * V_5 ,
struct V_14 * V_15 )
{
const struct V_16 * V_17 = V_16 ;
unsigned int V_18 = 0 ;
while ( V_17 -> V_15 ) {
if ( V_18 == V_15 -> V_19 ) {
V_15 -> V_15 = V_17 -> V_15 ;
return 0 ;
}
V_18 ++ , V_17 ++ ;
}
return - V_20 ;
}
static int F_4 ( struct V_12 * V_13 ,
struct V_4 * V_5 ,
struct V_21 * V_22 )
{
struct V_2 * V_3 = F_5 ( V_13 ) ;
struct V_1 * V_23 ;
V_23 = F_1 ( V_3 , V_5 , V_22 -> V_7 , V_22 -> V_8 ) ;
V_22 -> V_23 = * V_23 ;
return 0 ;
}
int F_6 ( struct V_12 * V_13 ,
struct V_4 * V_5 ,
unsigned int V_7 , T_1 V_8 ,
struct V_1 * V_24 )
{
struct V_2 * V_3 = F_5 ( V_13 ) ;
struct V_1 * V_25 =
#ifndef F_7
F_1 ( V_3 , V_5 , V_7 , V_8 ) ;
#else
F_1 ( V_3 , V_5 , V_7 , V_8 ) ;
#endif
if ( V_8 == V_26 ) {
const struct V_16 * V_17 ;
struct V_1 V_27 ;
V_17 = F_8 ( V_24 -> V_15 ) ;
if ( V_17 )
V_25 -> V_15 = V_17 -> V_15 ;
else
V_25 -> V_15 = V_16 [ 0 ] . V_15 ;
V_25 -> V_28 = F_9 (
V_29 , V_24 -> V_28 , V_30 ,
V_31 ) ;
V_25 -> V_32 = F_9 (
V_29 , V_24 -> V_32 , V_33 ,
V_34 ) ;
V_27 = * V_24 = * V_25 ;
return F_6 ( V_13 , V_5 , V_7 , V_35 ,
& V_27 ) ;
}
* V_25 = * V_24 =
#ifndef F_7
* F_1 ( V_3 , V_5 , V_7 , V_26 ) ;
#else
* F_1 ( V_3 , V_5 , V_7 , V_26 ) ;
#endif
return 0 ;
}
static int F_10 ( struct V_12 * V_13 ,
struct V_4 * V_5 ,
struct V_21 * V_22 )
{
return F_6 ( V_13 , V_5 , V_22 -> V_7 , V_22 -> V_8 ,
& V_22 -> V_23 ) ;
}
static int F_11 ( struct V_12 * V_13 , int V_36 )
{
return 0 ;
}
static int F_12 ( struct V_37 * V_38 ,
const struct V_39 * V_40 ,
const struct V_39 * V_41 , V_29 V_42 )
{
struct V_12 * V_13 = F_13 ( V_38 ) ;
struct V_2 * V_3 = F_5 ( V_13 ) ;
V_29 V_43 = V_40 -> V_19 | F_14 ( V_41 -> V_38 ) ;
switch ( V_43 ) {
case V_35 | V_44 :
return - V_20 ;
case V_35 | V_45 :
if ( V_42 & V_46 ) {
if ( V_3 -> V_47 & ~ V_48 )
return - V_49 ;
V_3 -> V_47 |= V_48 ;
} else {
V_3 -> V_47 &= ~ V_48 ;
}
break;
default:
return - V_20 ;
}
return 0 ;
}
static int F_15 ( struct V_2 * V_3 ,
int V_50 )
{
struct V_12 * V_13 = & V_3 -> V_10 ;
struct V_39 * V_51 = V_3 -> V_51 ;
struct V_37 * V_52 = & V_13 -> V_38 ;
int V_53 ;
F_16 ( V_13 , & V_54 ) ;
snprintf ( V_13 -> V_55 , sizeof( V_13 -> V_55 ) , L_1 , V_50 ) ;
F_17 ( V_13 , V_3 ) ;
V_13 -> V_42 |= V_56 ;
V_51 [ V_35 ] . V_42 = V_57 ;
V_51 [ V_26 ] . V_42 = V_58 ;
V_52 -> V_59 = & V_60 ;
V_52 -> V_61 = V_45 ;
V_53 = F_18 ( V_52 , V_62 , V_51 ) ;
if ( V_53 < 0 )
return V_53 ;
V_3 -> V_11 [ V_26 ] . V_15 =
V_3 -> V_11 [ V_35 ] . V_15 =
V_16 [ 0 ] . V_15 ;
return 0 ;
}
void
F_19 ( struct V_2 * V_3 )
{
F_20 ( & V_3 -> V_10 . V_38 ) ;
F_21 ( & V_3 -> V_10 ) ;
}
int F_22 ( struct V_2 * V_3 ,
struct V_63 * V_64 )
{
int V_53 ;
V_53 = F_23 ( V_64 , & V_3 -> V_10 ) ;
if ( V_53 < 0 )
goto error;
return 0 ;
error:
F_19 ( V_3 ) ;
return V_53 ;
}
static int
F_24 ( const short int V_65 [ 2 ] , int V_66 , int V_67 )
{
static const int V_68 = 16 ;
int V_69 ;
if ( V_66 >> V_70 <= 0 )
return V_67 ;
V_69 = V_68 * V_65 [ 1 ] * ( 500000000 >> V_70 ) ;
V_69 /= V_66 >> V_70 ;
V_69 += V_68 * V_65 [ 0 ] ;
return V_69 ;
}
static void F_25 ( struct V_71 * V_72 )
{
static const short int V_73 [] = { 0 , 0 } ;
static const short int V_74 [] = { 95 , - 8 } ;
static const short int V_75 [] = { 0 , 0 } ;
static const short int V_76 [] = { 85 , - 2 } ;
static const int V_77 = 0 * 0 ;
static const int V_78 = 0x480 ;
static const T_2 V_79 [] = {
[ V_80 ] = V_81 ,
[ V_82 ] = V_83 ,
[ V_84 ] = V_85 ,
} ;
static const unsigned char V_86 [] = {
[ V_80 ] = 4 ,
[ V_82 ] = 2 ,
[ V_84 ] = 2 ,
} ;
static const T_2 V_87 [] = {
V_88 ,
V_89 ,
V_90 ,
V_91 ,
V_92 ,
} ;
int V_93 ;
int V_94 ;
int V_95 ;
int V_96 ;
struct V_97 V_98 ;
struct V_99 * V_100 = V_72 -> V_100 ;
struct V_101 * V_102 ;
int V_66 = 0 ;
enum V_103 V_50 ;
int V_104 ;
V_102 = F_26 (
V_100 -> V_105 [ V_72 -> V_106 ] . V_107 ) ;
V_50 = V_102 -> V_50 ;
V_98 . V_108 = V_109 ;
if ( F_27
( V_100 -> V_105 [ V_72 -> V_106 ] . V_107 -> V_110 , & V_98 ) == 0 )
V_66 = V_98 . V_111 ;
V_93 = F_24 ( V_73 ,
V_66 , V_77 ) ;
V_94 = F_24 ( V_74 ,
V_66 , V_78 ) ;
V_95 = F_24 ( V_75 ,
V_66 , V_77 ) ;
V_96 = F_24 ( V_76 ,
V_66 , V_78 ) ;
for ( V_104 = 0 ; V_104 < V_86 [ V_50 ] + 1 ; V_104 ++ ) {
T_2 V_112 = V_79 [ V_50 ] + V_87 [ V_104 ] ;
F_28 ( V_112 + V_113 ,
V_104 == 0 ? V_93 : V_95 ) ;
F_28 ( V_112 + V_114 ,
V_104 == 0 ? V_94 : V_96 ) ;
}
}
void F_29 ( struct V_71 * V_72 )
{
if ( F_30 ( V_72 -> V_100 , V_115 ) )
F_25 ( V_72 ) ;
}
void F_31 ( struct V_99 * V_100 )
{
}
int F_32 ( struct V_99 * V_100 )
{
struct V_2 * V_116 ;
unsigned int V_18 ;
int V_53 ;
for ( V_18 = 0 ; V_18 < V_117 ; V_18 ++ ) {
V_116 = & V_100 -> V_116 [ V_18 ] ;
V_116 -> V_100 = V_100 ;
V_53 = F_15 ( V_116 , V_18 ) ;
if ( V_53 < 0 )
goto V_118;
}
return 0 ;
V_118:
F_31 ( V_100 ) ;
return V_53 ;
}
