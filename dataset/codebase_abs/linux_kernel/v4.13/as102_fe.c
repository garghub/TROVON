static T_1 F_1 ( enum V_1 V_2 )
{
T_1 V_3 ;
switch ( V_2 ) {
case V_4 :
V_3 = V_5 ;
break;
case V_6 :
V_3 = V_7 ;
break;
case V_8 :
V_3 = V_9 ;
break;
case V_10 :
V_3 = V_11 ;
break;
case V_12 :
V_3 = V_13 ;
break;
default:
V_3 = V_14 ;
break;
}
return V_3 ;
}
static int F_2 ( struct V_15 * V_16 )
{
struct V_17 * V_18 = V_16 -> V_19 ;
struct V_20 * V_3 = & V_16 -> V_21 ;
struct V_22 V_23 = { 0 } ;
V_23 . V_24 = V_3 -> V_25 / 1000 ;
V_23 . V_26 = V_27 ;
switch ( V_3 -> V_28 ) {
case 8000000 :
V_23 . V_29 = V_30 ;
break;
case 7000000 :
V_23 . V_29 = V_31 ;
break;
case 6000000 :
V_23 . V_29 = V_32 ;
break;
default:
V_23 . V_29 = V_30 ;
}
switch ( V_3 -> V_33 ) {
case V_34 :
V_23 . V_33 = V_35 ;
break;
case V_36 :
V_23 . V_33 = V_37 ;
break;
case V_38 :
V_23 . V_33 = V_39 ;
break;
case V_40 :
V_23 . V_33 = V_41 ;
break;
case V_42 :
default:
V_23 . V_33 = V_43 ;
break;
}
switch ( V_3 -> V_44 ) {
case V_45 :
V_23 . V_44 = V_46 ;
break;
case V_47 :
V_23 . V_44 = V_48 ;
break;
case V_49 :
V_23 . V_44 = V_50 ;
break;
default:
V_23 . V_44 = V_51 ;
break;
}
switch ( V_3 -> V_52 ) {
case V_53 :
V_23 . V_52 = V_54 ;
break;
case V_55 :
V_23 . V_52 = V_56 ;
break;
default:
V_23 . V_52 = V_57 ;
}
switch ( V_3 -> V_58 ) {
case V_59 :
V_23 . V_58 = V_60 ;
break;
case V_61 :
V_23 . V_58 = V_62 ;
break;
case V_63 :
V_23 . V_58 = V_64 ;
break;
case V_65 :
V_23 . V_58 = V_66 ;
break;
case V_67 :
V_23 . V_58 = V_68 ;
break;
}
F_3 ( L_1 ,
V_3 -> V_25 ,
V_23 . V_29 ,
V_23 . V_33 ) ;
if ( ( V_23 . V_58 != V_60 ) &&
( ( V_3 -> V_69 == V_70 ) ||
( V_3 -> V_71 == V_70 ) ) ) {
if ( V_3 -> V_69 == V_70 ) {
V_23 . V_72 = V_73 ;
V_23 . V_74 =
F_1 ( V_3 -> V_71 ) ;
}
if ( V_3 -> V_71 == V_70 ) {
V_23 . V_72 = V_75 ;
V_23 . V_74 =
F_1 ( V_3 -> V_69 ) ;
}
F_3 ( L_2 ,
V_23 . V_58 ,
V_23 . V_72 == V_73 ?
L_3 : L_4 ,
V_23 . V_72 == V_73 ?
L_3 : L_4 ,
V_23 . V_74 ) ;
} else {
V_23 . V_74 =
F_1 ( V_3 -> V_71 ) ;
}
return V_18 -> V_76 -> V_77 ( V_18 -> V_78 , & V_23 ) ;
}
static int F_4 ( struct V_15 * V_16 ,
struct V_20 * V_3 )
{
struct V_17 * V_18 = V_16 -> V_19 ;
int V_79 = 0 ;
struct V_80 V_81 = { 0 } ;
V_79 = V_18 -> V_76 -> V_82 ( V_18 -> V_78 , & V_81 ) ;
if ( V_79 < 0 )
return V_79 ;
switch ( V_81 . V_44 ) {
case V_46 :
V_3 -> V_44 = V_45 ;
break;
case V_48 :
V_3 -> V_44 = V_47 ;
break;
case V_50 :
V_3 -> V_44 = V_49 ;
break;
}
switch ( V_81 . V_58 ) {
case V_60 :
V_3 -> V_58 = V_59 ;
break;
case V_62 :
V_3 -> V_58 = V_61 ;
break;
case V_64 :
V_3 -> V_58 = V_63 ;
break;
case V_66 :
V_3 -> V_58 = V_65 ;
break;
}
switch ( V_81 . V_71 ) {
case V_5 :
V_3 -> V_71 = V_4 ;
break;
case V_7 :
V_3 -> V_71 = V_6 ;
break;
case V_9 :
V_3 -> V_71 = V_8 ;
break;
case V_11 :
V_3 -> V_71 = V_10 ;
break;
case V_13 :
V_3 -> V_71 = V_12 ;
break;
}
switch ( V_81 . V_69 ) {
case V_5 :
V_3 -> V_69 = V_4 ;
break;
case V_7 :
V_3 -> V_69 = V_6 ;
break;
case V_9 :
V_3 -> V_69 = V_8 ;
break;
case V_11 :
V_3 -> V_69 = V_10 ;
break;
case V_13 :
V_3 -> V_69 = V_12 ;
break;
}
switch ( V_81 . V_33 ) {
case V_35 :
V_3 -> V_33 = V_34 ;
break;
case V_37 :
V_3 -> V_33 = V_36 ;
break;
case V_39 :
V_3 -> V_33 = V_38 ;
break;
case V_41 :
V_3 -> V_33 = V_40 ;
break;
}
switch ( V_81 . V_52 ) {
case V_54 :
V_3 -> V_52 = V_53 ;
break;
case V_56 :
V_3 -> V_52 = V_55 ;
break;
}
return 0 ;
}
static int F_5 ( struct V_15 * V_16 ,
struct V_83 * V_84 ) {
V_84 -> V_85 = 1000 ;
return 0 ;
}
static int F_6 ( struct V_15 * V_16 , enum V_86 * V_87 )
{
int V_79 = 0 ;
struct V_17 * V_18 = V_16 -> V_19 ;
struct V_88 V_89 = { 0 } ;
V_79 = V_18 -> V_76 -> V_90 ( V_18 -> V_78 , & V_89 ) ;
if ( V_79 < 0 )
return V_79 ;
V_18 -> V_91 = V_89 . V_91 ;
V_18 -> V_92 = V_89 . V_93 ;
switch ( V_89 . V_94 ) {
case V_95 :
* V_87 = V_96 | V_97 ;
break;
case V_98 :
* V_87 = V_96 | V_97 | V_99 |
V_100 ;
break;
case V_101 :
* V_87 = V_96 | V_97 | V_99 |
V_102 | V_100 ;
break;
default:
* V_87 = V_103 ;
}
F_3 ( L_5 ,
V_89 . V_94 , V_89 . V_91 ,
V_89 . V_104 , V_89 . V_93 ) ;
if ( ! ( * V_87 & V_102 ) ) {
memset ( & V_18 -> V_105 , 0 , sizeof( V_18 -> V_105 ) ) ;
return 0 ;
}
V_79 = V_18 -> V_76 -> V_106 ( V_18 -> V_78 , & V_18 -> V_105 ) ;
if ( V_79 < 0 )
memset ( & V_18 -> V_105 , 0 , sizeof( V_18 -> V_105 ) ) ;
return V_79 ;
}
static int F_7 ( struct V_15 * V_16 , T_2 * V_107 )
{
struct V_17 * V_18 = V_16 -> V_19 ;
* V_107 = V_18 -> V_105 . V_108 ;
return 0 ;
}
static int F_8 ( struct V_15 * V_16 , T_3 * V_92 )
{
struct V_17 * V_18 = V_16 -> V_19 ;
* V_92 = V_18 -> V_92 ;
return 0 ;
}
static int F_9 ( struct V_15 * V_16 ,
T_2 * V_109 )
{
struct V_17 * V_18 = V_16 -> V_19 ;
* V_109 = ( ( ( 0xffff * 400 ) * V_18 -> V_91 + 41000 ) * 2 ) ;
return 0 ;
}
static int F_10 ( struct V_15 * V_16 , T_3 * V_110 )
{
struct V_17 * V_18 = V_16 -> V_19 ;
if ( V_18 -> V_105 . V_111 )
* V_110 = V_18 -> V_105 . V_112 ;
else
* V_110 = 0 ;
return 0 ;
}
static int F_11 ( struct V_15 * V_16 , int V_113 )
{
struct V_17 * V_18 = V_16 -> V_19 ;
return V_18 -> V_76 -> V_114 ( V_18 -> V_78 , V_113 ,
V_18 -> V_115 ) ;
}
static void F_12 ( struct V_15 * V_16 )
{
struct V_17 * V_18 = V_16 -> V_19 ;
F_13 ( V_18 ) ;
}
struct V_15 * F_14 ( const char * V_116 ,
const struct V_117 * V_76 ,
void * V_78 ,
T_1 V_115 )
{
struct V_17 * V_18 ;
struct V_15 * V_16 ;
V_18 = F_15 ( sizeof( struct V_17 ) , V_118 ) ;
if ( V_18 == NULL ) {
F_16 ( L_6 , V_119 ) ;
return NULL ;
}
V_16 = & V_18 -> V_120 ;
V_16 -> V_19 = V_18 ;
V_18 -> V_76 = V_76 ;
V_18 -> V_78 = V_78 ;
V_18 -> V_115 = V_115 ;
memcpy ( & V_16 -> V_76 , & V_117 , sizeof( struct V_121 ) ) ;
strncpy ( V_16 -> V_76 . V_122 . V_116 , V_116 , sizeof( V_16 -> V_76 . V_122 . V_116 ) ) ;
return V_16 ;
}
