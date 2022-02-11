static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_6 ;
struct V_7 * V_8 = F_2 ( V_6 ) ;
struct V_9 * V_10 = V_6 -> V_10 ;
F_3 ( & V_8 -> V_11 ) ;
V_8 -> V_12 -- ;
if ( V_8 -> V_12 < 0 ) {
F_4 ( V_10 , L_1 ) ;
V_8 -> V_12 = 0 ;
}
if ( ! V_8 -> V_12 )
V_8 -> V_13 = NULL ;
F_5 ( & V_8 -> V_11 ) ;
}
static void F_6 ( struct V_7 * V_8 ,
struct V_14 * V_15 )
{
static const unsigned int V_16 [] = {
32000 ,
44100 ,
48000 ,
64000 ,
88200 ,
96000 ,
176400 ,
192000 ,
} ;
struct V_17 * V_18 = & V_8 -> V_18 ;
unsigned int V_19 ;
int V_20 ;
V_18 -> V_21 = V_16 ;
V_18 -> V_22 = 0 ;
V_18 -> V_23 = 0 ;
for ( V_20 = 0 ; V_20 < F_7 ( V_16 ) ; V_20 ++ ) {
V_19 = ( V_16 [ V_20 ] <= 96000 ) ? 256 : 128 ;
if ( V_8 -> V_24 >= V_16 [ V_20 ] * V_19 )
V_18 -> V_23 = V_20 + 1 ;
}
V_17 ( V_15 , 0 ,
V_25 , V_18 ) ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_6 ;
struct V_7 * V_8 = F_2 ( V_6 ) ;
V_8 -> V_12 ++ ;
F_6 ( V_8 , V_2 -> V_15 ) ;
return 0 ;
}
static int F_9 ( struct V_3 * V_26 ,
int V_27 , unsigned int V_28 , int V_29 )
{
struct V_5 * V_6 = V_26 -> V_6 ;
struct V_7 * V_8 = F_2 ( V_6 ) ;
V_8 -> V_24 = V_28 ;
return 0 ;
}
static int F_10 ( struct V_3 * V_4 , unsigned int V_30 )
{
struct V_5 * V_6 = V_4 -> V_6 ;
struct V_7 * V_8 = F_2 ( V_6 ) ;
V_30 &= V_31 ;
switch ( V_30 ) {
case V_32 :
case V_33 :
V_8 -> V_30 = V_30 ;
break;
default:
return - V_34 ;
}
return 0 ;
}
static bool F_11 ( const struct V_35 * V_13 ,
int V_36 ,
unsigned int V_30 , unsigned int V_37 )
{
const struct V_38 * V_39 ;
V_39 = ( V_36 ) ? & V_13 -> V_40 : & V_13 -> V_41 ;
if ( V_39 -> V_30 != V_30 )
return false ;
if ( V_39 -> V_37 != V_37 )
return false ;
return true ;
}
static int F_12 ( struct V_1 * V_2 ,
struct V_42 * V_43 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_6 ;
struct V_7 * V_8 = F_2 ( V_6 ) ;
const struct V_35 * V_13 ;
struct V_9 * V_10 = V_6 -> V_10 ;
unsigned int V_37 = F_13 ( V_43 ) ;
unsigned int V_30 = V_8 -> V_30 ;
unsigned int V_44 ;
int V_36 = V_2 -> V_45 == V_46 ;
int V_20 , V_47 ;
T_1 V_48 , V_49 ;
V_44 = F_14 ( V_43 ) ;
switch ( V_44 ) {
case 32000 :
case 44100 :
case 48000 :
V_49 = V_50 ;
break;
case 64000 :
case 88200 :
case 96000 :
V_49 = V_51 ;
break;
case 176400 :
case 192000 :
V_49 = V_52 ;
break;
default:
return - V_34 ;
}
V_48 = V_53 ;
V_47 = - V_34 ;
V_13 = NULL ;
F_3 ( & V_8 -> V_11 ) ;
if ( V_8 -> V_13 ) {
if ( F_11 ( V_8 -> V_13 , V_36 , V_30 , V_37 ) )
V_13 = V_8 -> V_13 ;
} else {
for ( V_20 = F_7 ( V_54 ) - 1 ; V_20 >= 0 ; V_20 -- ) {
if ( ! F_11 ( V_54 + V_20 ,
V_36 ,
V_30 , V_37 ) )
continue;
V_13 = V_54 + V_20 ;
break;
}
}
if ( ( V_8 -> V_13 == NULL ) ||
( V_8 -> V_13 == V_13 ) ) {
V_8 -> V_13 = V_13 ;
V_47 = 0 ;
}
F_5 ( & V_8 -> V_11 ) ;
if ( V_47 < 0 )
goto V_55;
V_48 = F_15 ( V_13 ) ;
F_16 ( V_6 , V_56 , V_57 , V_48 ) ;
F_16 ( V_6 , V_58 , V_59 , V_49 ) ;
F_16 ( V_6 , V_60 , V_61 , V_8 -> V_62 ) ;
F_16 ( V_6 , V_63 , V_64 , V_8 -> V_65 ) ;
V_55:
if ( V_47 < 0 )
F_17 ( V_10 , L_2 ) ;
return V_47 ;
}
static int F_18 ( struct V_5 * V_6 ,
enum V_66 V_67 )
{
T_1 V_68 = 0 ;
switch ( V_67 ) {
case V_69 :
V_68 |= V_70 ;
case V_71 :
V_68 |= V_72 | V_73 ;
case V_74 :
V_68 |= V_75 ;
case V_76 :
default:
break;
}
F_19 ( V_6 , V_77 , V_68 ) ;
return 0 ;
}
static int F_20 ( struct V_5 * V_6 )
{
struct V_78 * V_78 = F_21 ( V_6 -> V_10 , NULL ) ;
F_22 ( V_78 , true ) ;
F_23 ( V_78 ) ;
return 0 ;
}
static int F_24 ( struct V_5 * V_6 )
{
struct V_78 * V_78 = F_21 ( V_6 -> V_10 , NULL ) ;
F_22 ( V_78 , false ) ;
return F_25 ( V_78 ) ;
}
static void F_26 ( struct V_7 * V_8 ,
struct V_9 * V_10 )
{
struct V_79 * V_80 = V_10 -> V_81 ;
char V_82 [ 32 ] ;
int V_20 ;
for ( V_20 = 0 ; V_20 < 2 ; V_20 ++ ) {
snprintf ( V_82 , sizeof( V_82 ) , L_3 , V_20 + 1 ) ;
if ( ! F_27 ( V_80 , V_82 , NULL ) )
V_8 -> V_62 |= 1 << V_20 ;
}
for ( V_20 = 0 ; V_20 < 6 ; V_20 ++ ) {
snprintf ( V_82 , sizeof( V_82 ) , L_4 , V_20 + 1 ) ;
if ( ! F_27 ( V_80 , V_82 , NULL ) )
V_8 -> V_65 |= 1 << V_20 ;
}
}
static int F_28 ( struct V_83 * V_84 ,
const struct V_85 * V_86 )
{
struct V_9 * V_10 = & V_84 -> V_10 ;
struct V_79 * V_80 = V_10 -> V_81 ;
const struct V_87 * V_88 ;
struct V_78 * V_78 ;
struct V_7 * V_8 ;
V_88 = NULL ;
if ( V_80 ) {
const struct V_89 * V_90 ;
V_90 = F_29 ( V_91 , V_10 ) ;
if ( V_90 )
V_88 = V_90 -> V_92 ;
} else {
V_88 = ( const struct V_87 * ) V_86 -> V_93 ;
}
if ( ! V_88 )
return - V_34 ;
V_8 = F_30 ( V_10 , sizeof( * V_8 ) , V_94 ) ;
if ( ! V_8 )
return - V_95 ;
F_26 ( V_8 , V_10 ) ;
V_8 -> V_13 = NULL ;
V_8 -> V_12 = 0 ;
V_8 -> V_24 = 0 ;
F_31 ( & V_8 -> V_11 ) ;
F_32 ( V_84 , V_8 ) ;
V_78 = F_33 ( V_84 , V_88 ) ;
if ( F_34 ( V_78 ) )
return F_35 ( V_78 ) ;
return F_36 ( V_10 , & V_96 ,
& V_97 , 1 ) ;
}
static int F_37 ( struct V_83 * V_98 )
{
F_38 ( & V_98 -> V_10 ) ;
return 0 ;
}
