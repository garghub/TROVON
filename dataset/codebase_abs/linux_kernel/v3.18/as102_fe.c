static T_1 F_1 ( T_2 V_1 )
{
T_1 V_2 ;
switch ( V_1 ) {
case V_3 :
V_2 = V_4 ;
break;
case V_5 :
V_2 = V_6 ;
break;
case V_7 :
V_2 = V_8 ;
break;
case V_9 :
V_2 = V_10 ;
break;
case V_11 :
V_2 = V_12 ;
break;
default:
V_2 = V_13 ;
break;
}
return V_2 ;
}
static int F_2 ( struct V_14 * V_15 )
{
struct V_16 * V_17 = V_15 -> V_18 ;
struct V_19 * V_2 = & V_15 -> V_20 ;
struct V_21 V_22 = { 0 } ;
V_22 . V_23 = V_2 -> V_24 / 1000 ;
V_22 . V_25 = V_26 ;
switch ( V_2 -> V_27 ) {
case 8000000 :
V_22 . V_28 = V_29 ;
break;
case 7000000 :
V_22 . V_28 = V_30 ;
break;
case 6000000 :
V_22 . V_28 = V_31 ;
break;
default:
V_22 . V_28 = V_29 ;
}
switch ( V_2 -> V_32 ) {
case V_33 :
V_22 . V_32 = V_34 ;
break;
case V_35 :
V_22 . V_32 = V_36 ;
break;
case V_37 :
V_22 . V_32 = V_38 ;
break;
case V_39 :
V_22 . V_32 = V_40 ;
break;
case V_41 :
default:
V_22 . V_32 = V_42 ;
break;
}
switch ( V_2 -> V_43 ) {
case V_44 :
V_22 . V_43 = V_45 ;
break;
case V_46 :
V_22 . V_43 = V_47 ;
break;
case V_48 :
V_22 . V_43 = V_49 ;
break;
default:
V_22 . V_43 = V_50 ;
break;
}
switch ( V_2 -> V_51 ) {
case V_52 :
V_22 . V_51 = V_53 ;
break;
case V_54 :
V_22 . V_51 = V_55 ;
break;
default:
V_22 . V_51 = V_56 ;
}
switch ( V_2 -> V_57 ) {
case V_58 :
V_22 . V_57 = V_59 ;
break;
case V_60 :
V_22 . V_57 = V_61 ;
break;
case V_62 :
V_22 . V_57 = V_63 ;
break;
case V_64 :
V_22 . V_57 = V_65 ;
break;
case V_66 :
V_22 . V_57 = V_67 ;
break;
}
F_3 ( L_1 ,
V_2 -> V_24 ,
V_22 . V_28 ,
V_22 . V_32 ) ;
if ( ( V_22 . V_57 != V_59 ) &&
( ( V_2 -> V_68 == V_69 ) ||
( V_2 -> V_70 == V_69 ) ) ) {
if ( V_2 -> V_68 == V_69 ) {
V_22 . V_71 = V_72 ;
V_22 . V_73 =
F_1 ( V_2 -> V_70 ) ;
}
if ( V_2 -> V_70 == V_69 ) {
V_22 . V_71 = V_74 ;
V_22 . V_73 =
F_1 ( V_2 -> V_68 ) ;
}
F_3 ( L_2 ,
V_22 . V_57 ,
V_22 . V_71 == V_72 ?
L_3 : L_4 ,
V_22 . V_71 == V_72 ?
L_3 : L_4 ,
V_22 . V_73 ) ;
} else {
V_22 . V_73 =
F_1 ( V_2 -> V_70 ) ;
}
return V_17 -> V_75 -> V_76 ( V_17 -> V_77 , & V_22 ) ;
}
static int F_4 ( struct V_14 * V_15 )
{
struct V_16 * V_17 = V_15 -> V_18 ;
struct V_19 * V_2 = & V_15 -> V_20 ;
int V_78 = 0 ;
struct V_79 V_80 = { 0 } ;
V_78 = V_17 -> V_75 -> V_81 ( V_17 -> V_77 , & V_80 ) ;
if ( V_78 < 0 )
return V_78 ;
switch ( V_80 . V_43 ) {
case V_45 :
V_2 -> V_43 = V_44 ;
break;
case V_47 :
V_2 -> V_43 = V_46 ;
break;
case V_49 :
V_2 -> V_43 = V_48 ;
break;
}
switch ( V_80 . V_57 ) {
case V_59 :
V_2 -> V_57 = V_58 ;
break;
case V_61 :
V_2 -> V_57 = V_60 ;
break;
case V_63 :
V_2 -> V_57 = V_62 ;
break;
case V_65 :
V_2 -> V_57 = V_64 ;
break;
}
switch ( V_80 . V_70 ) {
case V_4 :
V_2 -> V_70 = V_3 ;
break;
case V_6 :
V_2 -> V_70 = V_5 ;
break;
case V_8 :
V_2 -> V_70 = V_7 ;
break;
case V_10 :
V_2 -> V_70 = V_9 ;
break;
case V_12 :
V_2 -> V_70 = V_11 ;
break;
}
switch ( V_80 . V_68 ) {
case V_4 :
V_2 -> V_68 = V_3 ;
break;
case V_6 :
V_2 -> V_68 = V_5 ;
break;
case V_8 :
V_2 -> V_68 = V_7 ;
break;
case V_10 :
V_2 -> V_68 = V_9 ;
break;
case V_12 :
V_2 -> V_68 = V_11 ;
break;
}
switch ( V_80 . V_32 ) {
case V_34 :
V_2 -> V_32 = V_33 ;
break;
case V_36 :
V_2 -> V_32 = V_35 ;
break;
case V_38 :
V_2 -> V_32 = V_37 ;
break;
case V_40 :
V_2 -> V_32 = V_39 ;
break;
}
switch ( V_80 . V_51 ) {
case V_53 :
V_2 -> V_51 = V_52 ;
break;
case V_55 :
V_2 -> V_51 = V_54 ;
break;
}
return 0 ;
}
static int F_5 ( struct V_14 * V_15 ,
struct V_82 * V_83 ) {
V_83 -> V_84 = 1000 ;
return 0 ;
}
static int F_6 ( struct V_14 * V_15 , T_3 * V_85 )
{
int V_78 = 0 ;
struct V_16 * V_17 = V_15 -> V_18 ;
struct V_86 V_87 = { 0 } ;
V_78 = V_17 -> V_75 -> V_88 ( V_17 -> V_77 , & V_87 ) ;
if ( V_78 < 0 )
return V_78 ;
V_17 -> V_89 = V_87 . V_89 ;
V_17 -> V_90 = V_87 . V_91 ;
switch ( V_87 . V_92 ) {
case V_93 :
* V_85 = V_94 | V_95 ;
break;
case V_96 :
* V_85 = V_94 | V_95 | V_97 |
V_98 ;
break;
case V_99 :
* V_85 = V_94 | V_95 | V_97 |
V_100 | V_98 ;
break;
default:
* V_85 = V_101 ;
}
F_3 ( L_5 ,
V_87 . V_92 , V_87 . V_89 ,
V_87 . V_102 , V_87 . V_91 ) ;
if ( ! ( * V_85 & V_100 ) ) {
memset ( & V_17 -> V_103 , 0 , sizeof( V_17 -> V_103 ) ) ;
return 0 ;
}
V_78 = V_17 -> V_75 -> V_104 ( V_17 -> V_77 , & V_17 -> V_103 ) ;
if ( V_78 < 0 )
memset ( & V_17 -> V_103 , 0 , sizeof( V_17 -> V_103 ) ) ;
return V_78 ;
}
static int F_7 ( struct V_14 * V_15 , T_4 * V_105 )
{
struct V_16 * V_17 = V_15 -> V_18 ;
* V_105 = V_17 -> V_103 . V_106 ;
return 0 ;
}
static int F_8 ( struct V_14 * V_15 , T_5 * V_90 )
{
struct V_16 * V_17 = V_15 -> V_18 ;
* V_90 = V_17 -> V_90 ;
return 0 ;
}
static int F_9 ( struct V_14 * V_15 ,
T_4 * V_107 )
{
struct V_16 * V_17 = V_15 -> V_18 ;
* V_107 = ( ( ( 0xffff * 400 ) * V_17 -> V_89 + 41000 ) * 2 ) ;
return 0 ;
}
static int F_10 ( struct V_14 * V_15 , T_5 * V_108 )
{
struct V_16 * V_17 = V_15 -> V_18 ;
if ( V_17 -> V_103 . V_109 )
* V_108 = V_17 -> V_103 . V_110 ;
else
* V_108 = 0 ;
return 0 ;
}
static int F_11 ( struct V_14 * V_15 , int V_111 )
{
struct V_16 * V_17 = V_15 -> V_18 ;
return V_17 -> V_75 -> V_112 ( V_17 -> V_77 , V_111 ,
V_17 -> V_113 ) ;
}
static void F_12 ( struct V_14 * V_15 )
{
struct V_16 * V_17 = V_15 -> V_18 ;
F_13 ( V_17 ) ;
}
struct V_14 * F_14 ( const char * V_114 ,
const struct V_115 * V_75 ,
void * V_77 ,
T_1 V_113 )
{
struct V_16 * V_17 ;
struct V_14 * V_15 ;
V_17 = F_15 ( sizeof( struct V_16 ) , V_116 ) ;
if ( V_17 == NULL ) {
F_16 ( L_6 , V_117 ) ;
return NULL ;
}
V_15 = & V_17 -> V_118 ;
V_15 -> V_18 = V_17 ;
V_17 -> V_75 = V_75 ;
V_17 -> V_77 = V_77 ;
V_17 -> V_113 = V_113 ;
memcpy ( & V_15 -> V_75 , & V_115 , sizeof( struct V_119 ) ) ;
strncpy ( V_15 -> V_75 . V_120 . V_114 , V_114 , sizeof( V_15 -> V_75 . V_120 . V_114 ) ) ;
return V_15 ;
}
