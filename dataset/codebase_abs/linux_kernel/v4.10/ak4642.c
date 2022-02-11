static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 -> V_8 ) ;
switch ( V_5 ) {
case V_9 :
case V_10 :
F_3 ( V_7 , V_11 , V_12 , V_12 ) ;
break;
case V_13 :
case V_14 :
F_4 ( 300 ) ;
F_3 ( V_7 , V_11 , V_12 , 0 ) ;
break;
}
return 0 ;
}
static int F_5 ( struct V_15 * V_16 ,
struct V_17 * V_18 )
{
int V_19 = V_16 -> V_20 == V_21 ;
struct V_6 * V_7 = V_18 -> V_7 ;
if ( V_19 ) {
F_6 ( V_7 , V_22 , 0x91 ) ;
F_6 ( V_7 , V_23 , 0x91 ) ;
} else {
F_3 ( V_7 , V_24 , V_25 | V_26 , V_25 | V_26 ) ;
F_6 ( V_7 , V_27 , F_7 ( 0x3 ) | F_8 ( 0x3 ) ) ;
F_6 ( V_7 , V_28 , V_29 | V_30 ) ;
F_3 ( V_7 , V_31 , V_32 , V_32 ) ;
F_3 ( V_7 , V_33 , V_34 , V_34 ) ;
}
return 0 ;
}
static void F_9 ( struct V_15 * V_16 ,
struct V_17 * V_18 )
{
int V_19 = V_16 -> V_20 == V_21 ;
struct V_6 * V_7 = V_18 -> V_7 ;
if ( V_19 ) {
} else {
F_3 ( V_7 , V_31 , V_32 , 0 ) ;
F_3 ( V_7 , V_33 , V_34 , 0 ) ;
F_3 ( V_7 , V_28 , V_29 , 0 ) ;
}
}
static int F_10 ( struct V_17 * V_35 ,
int V_36 , unsigned int V_37 , int V_38 )
{
struct V_6 * V_7 = V_35 -> V_7 ;
struct V_39 * V_40 = F_11 ( V_7 ) ;
T_1 V_41 ;
int V_42 = 0 ;
switch ( V_37 ) {
case 11289600 :
V_41 = V_43 ;
break;
case 12288000 :
V_41 = V_43 | V_44 ;
break;
case 12000000 :
V_41 = V_43 | V_45 ;
break;
case 24000000 :
V_41 = V_43 | V_45 | V_44 ;
break;
case 13500000 :
V_41 = V_46 | V_43 ;
break;
case 27000000 :
V_41 = V_46 | V_43 | V_44 ;
break;
case 19200000 :
V_41 = V_46 ;
V_42 = 1 ;
break;
case 13000000 :
V_41 = V_46 | V_43 | V_45 ;
V_42 = 1 ;
break;
case 26000000 :
V_41 = V_46 | V_43 | V_45 | V_44 ;
V_42 = 1 ;
break;
default:
return - V_47 ;
}
if ( V_42 && ! V_40 -> V_48 -> V_49 )
return - V_47 ;
F_3 ( V_7 , V_50 , V_51 , V_41 ) ;
return 0 ;
}
static int F_12 ( struct V_17 * V_18 , unsigned int V_52 )
{
struct V_6 * V_7 = V_18 -> V_7 ;
T_1 V_53 ;
T_1 V_54 ;
V_53 = V_55 | V_56 ;
V_54 = 0 ;
switch ( V_52 & V_57 ) {
case V_58 :
V_53 |= V_59 ;
V_54 = V_60 ;
break;
case V_61 :
break;
default:
return - V_47 ;
}
F_3 ( V_7 , V_62 , V_59 | V_55 | V_56 , V_53 ) ;
F_3 ( V_7 , V_50 , V_63 , V_54 ) ;
V_53 = 0 ;
switch ( V_52 & V_64 ) {
case V_65 :
V_53 = V_66 ;
break;
case V_67 :
V_53 = V_68 ;
break;
default:
return - V_47 ;
}
F_3 ( V_7 , V_50 , V_69 , V_53 ) ;
return 0 ;
}
static int F_13 ( struct V_6 * V_7 ,
T_2 V_70 )
{
T_2 V_71 [] = {
[ 0 ] = 8000 ,
[ 1 ] = 12000 ,
[ 2 ] = 16000 ,
[ 3 ] = 24000 ,
[ 4 ] = 7350 ,
[ 5 ] = 11025 ,
[ 6 ] = 14700 ,
[ 7 ] = 22050 ,
[ 10 ] = 32000 ,
[ 11 ] = 48000 ,
[ 14 ] = 29400 ,
[ 15 ] = 44100 ,
} ;
T_2 V_72 [] = {
[ 0 ] = 256 ,
[ 1 ] = 128 ,
[ 2 ] = 64 ,
[ 3 ] = 32
} ;
int V_73 , V_74 ;
for ( V_73 = 0 ; V_73 < F_14 ( V_72 ) ; V_73 ++ ) {
for ( V_74 = 0 ; V_74 < F_14 ( V_71 ) ; V_74 ++ ) {
if ( V_70 == V_72 [ V_73 ] * V_71 [ V_74 ] ) {
F_6 ( V_7 , V_75 ,
F_15 ( V_73 ) | F_16 ( V_74 ) ) ;
return 0 ;
}
}
}
return 0 ;
}
static int F_17 ( struct V_15 * V_16 ,
struct V_76 * V_77 ,
struct V_17 * V_18 )
{
struct V_6 * V_7 = V_18 -> V_7 ;
struct V_39 * V_40 = F_11 ( V_7 ) ;
T_2 V_78 = F_18 ( V_40 -> V_79 ) ;
if ( ! V_78 )
V_78 = F_19 ( V_77 ) * 256 ;
return F_13 ( V_7 , V_78 ) ;
}
static int F_20 ( struct V_6 * V_7 ,
enum V_80 V_81 )
{
switch ( V_81 ) {
case V_82 :
F_6 ( V_7 , V_31 , 0x00 ) ;
break;
default:
F_3 ( V_7 , V_31 , V_83 , V_83 ) ;
break;
}
return 0 ;
}
static int F_21 ( struct V_6 * V_7 )
{
struct V_84 * V_84 = F_22 ( V_7 -> V_85 , NULL ) ;
F_23 ( V_84 , true ) ;
F_24 ( V_84 ) ;
return 0 ;
}
static int F_25 ( struct V_6 * V_7 )
{
struct V_84 * V_84 = F_22 ( V_7 -> V_85 , NULL ) ;
F_23 ( V_84 , false ) ;
F_26 ( V_84 ) ;
return 0 ;
}
static int F_27 ( struct V_6 * V_7 )
{
struct V_39 * V_40 = F_11 ( V_7 ) ;
if ( V_40 -> V_79 )
F_13 ( V_7 , F_18 ( V_40 -> V_79 ) ) ;
return 0 ;
}
static struct V_86 * F_28 ( struct V_87 * V_85 )
{
struct V_88 * V_89 = V_85 -> V_90 ;
struct V_86 * V_86 ;
const char * V_91 = V_89 -> V_92 ;
const char * V_93 = NULL ;
T_2 V_78 ;
if ( F_29 ( V_89 , L_1 , & V_78 ) )
return NULL ;
if ( F_30 ( V_89 , L_2 ) )
V_93 = F_31 ( V_89 , 0 ) ;
F_32 ( V_89 , L_3 , & V_91 ) ;
V_86 = F_33 ( V_85 , V_91 , V_93 , 0 , V_78 ) ;
if ( ! F_34 ( V_86 ) )
F_35 ( V_89 , V_94 , V_86 ) ;
return V_86 ;
}
static int F_36 ( struct V_95 * V_96 ,
const struct V_97 * V_98 )
{
struct V_87 * V_85 = & V_96 -> V_85 ;
struct V_88 * V_89 = V_85 -> V_90 ;
const struct V_99 * V_48 = NULL ;
struct V_84 * V_84 ;
struct V_39 * V_40 ;
struct V_86 * V_79 = NULL ;
if ( V_89 ) {
const struct V_100 * V_101 ;
V_79 = F_28 ( V_85 ) ;
if ( F_34 ( V_79 ) )
V_79 = NULL ;
V_101 = F_37 ( V_102 , V_85 ) ;
if ( V_101 )
V_48 = V_101 -> V_53 ;
} else {
V_48 = ( const struct V_99 * ) V_98 -> V_103 ;
}
if ( ! V_48 ) {
F_38 ( V_85 , L_4 ) ;
return - V_47 ;
}
V_40 = F_39 ( V_85 , sizeof( * V_40 ) , V_104 ) ;
if ( ! V_40 )
return - V_105 ;
V_40 -> V_48 = V_48 ;
V_40 -> V_79 = V_79 ;
F_40 ( V_96 , V_40 ) ;
V_84 = F_41 ( V_96 , V_48 -> V_106 ) ;
if ( F_34 ( V_84 ) )
return F_42 ( V_84 ) ;
return F_43 ( V_85 ,
& V_107 , & V_108 , 1 ) ;
}
static int F_44 ( struct V_95 * V_109 )
{
F_45 ( & V_109 -> V_85 ) ;
return 0 ;
}
