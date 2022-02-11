char * F_1 ( struct V_1 * V_2 )
{
return V_3 [ F_2 ( V_2 ) ] ;
}
static struct V_4
* F_3 ( struct V_5 * V_6 , int V_7 )
{
struct V_4 * V_8 =
F_4 ( V_6 , V_8 ) ;
return & V_8 [ V_7 ] ;
}
static void F_5 ( struct V_1 * V_2 , T_1 V_9 , T_1 V_10 )
{
struct V_5 * V_6 = F_6 ( V_2 ) ;
int V_11 = F_7 ( V_2 ) ;
if ( F_8 ( V_2 ) )
F_9 ( V_6 , V_12 , V_9 , V_10 ) ;
else
F_9 ( V_6 , V_13 + V_11 , V_9 , V_10 ) ;
}
static T_1 F_10 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_6 ( V_2 ) ;
int V_11 = F_7 ( V_2 ) ;
if ( F_8 ( V_2 ) )
return F_11 ( V_6 , V_12 ) ;
else
return F_11 ( V_6 , V_13 + V_11 ) ;
}
static void F_12 ( struct V_1 * V_2 ,
T_1 V_14 , T_1 V_15 ,
T_1 V_9 , T_1 V_10 )
{
struct V_5 * V_6 = F_6 ( V_2 ) ;
if ( F_8 ( V_2 ) )
F_9 ( V_6 , V_14 , V_9 , V_10 ) ;
else
F_9 ( V_6 , V_15 , V_9 , V_10 ) ;
}
static T_1 F_13 ( struct V_1 * V_2 ,
T_1 V_14 , T_1 V_15 )
{
struct V_5 * V_6 = F_6 ( V_2 ) ;
if ( F_8 ( V_2 ) )
return F_11 ( V_6 , V_14 ) ;
else
return F_11 ( V_6 , V_15 ) ;
}
static void F_14 ( struct V_1 * V_2 , T_1 V_9 , T_1 V_10 )
{
F_12 ( V_2 , V_16 , V_17 , V_9 , V_10 ) ;
}
static T_1 F_15 ( struct V_1 * V_2 )
{
return F_13 ( V_2 , V_16 , V_17 ) ;
}
static void F_16 ( struct V_1 * V_2 , T_1 V_9 , T_1 V_10 )
{
struct V_5 * V_6 = F_6 ( V_2 ) ;
struct V_18 * V_19 = F_17 ( V_6 ) ;
int V_20 = F_18 ( V_2 ) ;
T_1 V_21 ;
#define F_19 ( T_2 ) \
case 0x ## a: \
reg = PIPE ## a ## TRN; \
break;
switch ( V_20 ) {
F_19 ( 1 ) ;
F_19 ( 2 ) ;
F_19 ( 3 ) ;
F_19 ( 4 ) ;
F_19 ( 5 ) ;
F_19 ( V_22 ) ;
F_19 ( V_23 ) ;
F_19 ( V_24 ) ;
F_19 ( V_25 ) ;
F_19 ( V_26 ) ;
F_19 ( 9 ) ;
F_19 ( V_27 ) ;
default:
F_20 ( V_19 , L_1 , V_20 ) ;
return;
}
F_12 ( V_2 , 0 , V_21 , V_9 , V_10 ) ;
}
static void F_21 ( struct V_1 * V_2 , T_1 V_9 , T_1 V_10 )
{
struct V_5 * V_6 = F_6 ( V_2 ) ;
struct V_18 * V_19 = F_17 ( V_6 ) ;
int V_20 = F_18 ( V_2 ) ;
T_1 V_21 ;
#define F_22 ( T_2 ) \
case 0x ## a: \
reg = PIPE ## a ## TRE; \
break;
switch ( V_20 ) {
F_22 ( 1 ) ;
F_22 ( 2 ) ;
F_22 ( 3 ) ;
F_22 ( 4 ) ;
F_22 ( 5 ) ;
F_22 ( V_22 ) ;
F_22 ( V_23 ) ;
F_22 ( V_24 ) ;
F_22 ( V_25 ) ;
F_22 ( V_26 ) ;
F_22 ( 9 ) ;
F_22 ( V_27 ) ;
default:
F_20 ( V_19 , L_1 , V_20 ) ;
return;
}
F_12 ( V_2 , 0 , V_21 , V_9 , V_10 ) ;
}
static void F_23 ( struct V_1 * V_2 , T_1 V_9 , T_1 V_10 )
{
if ( F_8 ( V_2 ) )
return;
F_12 ( V_2 , 0 , V_28 , V_9 , V_10 ) ;
}
static void F_24 ( struct V_1 * V_2 , T_1 V_9 , T_1 V_10 )
{
F_12 ( V_2 , V_29 , V_30 , V_9 , V_10 ) ;
}
static void F_25 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_6 ( V_2 ) ;
F_26 ( V_6 , V_31 , 0xF & F_18 ( V_2 ) ) ;
}
static int F_27 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_6 ( V_2 ) ;
int V_32 = 1024 ;
T_1 V_9 = F_28 ( V_6 ) ? ( V_33 | V_34 ) : V_34 ;
F_26 ( V_6 , V_35 , 0 ) ;
F_29 ( V_2 ) ;
do {
if ( ! ( F_10 ( V_2 ) & V_9 ) )
return 0 ;
F_30 ( 10 ) ;
} while ( V_32 -- );
return - V_36 ;
}
int F_31 ( struct V_1 * V_2 )
{
T_1 V_10 ;
V_10 = F_10 ( V_2 ) ;
if ( V_10 & V_37 )
return 0 ;
return - V_36 ;
}
static void F_32 ( struct V_1 * V_2 )
{
T_1 V_38 = F_10 ( V_2 ) ;
V_38 &= V_34 ;
switch ( V_38 ) {
case V_39 :
F_5 ( V_2 , V_34 , V_40 ) ;
case V_40 :
F_5 ( V_2 , V_34 , V_41 ) ;
}
}
void F_29 ( struct V_1 * V_2 )
{
int V_32 = 1024 ;
T_1 V_10 ;
F_32 ( V_2 ) ;
F_5 ( V_2 , V_34 , V_41 ) ;
do {
V_10 = F_10 ( V_2 ) ;
V_10 &= V_42 ;
if ( ! V_10 )
break;
F_30 ( 10 ) ;
} while ( V_32 -- );
}
void F_33 ( struct V_1 * V_2 )
{
F_32 ( V_2 ) ;
F_5 ( V_2 , V_34 , V_43 ) ;
}
void F_34 ( struct V_1 * V_2 )
{
T_1 V_38 = F_10 ( V_2 ) ;
V_38 &= V_34 ;
switch ( V_38 ) {
case V_41 :
F_5 ( V_2 , V_34 , V_40 ) ;
break;
case V_43 :
F_5 ( V_2 , V_34 , V_39 ) ;
break;
}
}
int F_35 ( struct V_1 * V_2 )
{
T_1 V_38 = F_10 ( V_2 ) & V_34 ;
return ( int ) ( V_38 == V_40 || V_38 == V_39 ) ;
}
void F_36 ( struct V_1 * V_2 , int V_44 )
{
if ( ! F_37 ( V_2 , V_45 ) )
return;
F_21 ( V_2 , V_46 | V_47 , V_46 ) ;
if ( F_38 ( V_2 ) ) {
int V_48 = F_39 ( V_2 ) ;
F_16 ( V_2 , 0xffff , F_40 ( V_44 , V_48 ) ) ;
F_21 ( V_2 , V_47 , V_47 ) ;
}
}
static int F_41 ( struct V_1 * V_2 , int V_49 ,
int V_50 , T_1 * V_51 )
{
T_1 type = 0 ;
T_1 V_52 = 0 ;
T_1 V_53 = 0 ;
T_1 V_54 = 0 ;
T_1 V_55 = 0 ;
T_1 V_56 = 0 ;
T_1 V_57 = 0 ;
T_1 V_58 [] = {
[ V_45 ] = V_59 ,
[ V_60 ] = V_61 ,
[ V_62 ] = V_63 ,
} ;
if ( F_8 ( V_2 ) )
return - V_64 ;
type = V_58 [ F_2 ( V_2 ) ] ;
if ( F_37 ( V_2 , V_62 ) ||
F_37 ( V_2 , V_45 ) )
V_52 = 0 ;
if ( F_37 ( V_2 , V_45 ) )
V_54 = 0 ;
if ( V_50 )
F_42 ( V_2 , V_65 ) ;
if ( ! ! V_49 ^ ! ! V_50 )
V_55 |= V_66 ;
if ( ! V_55 )
F_42 ( V_2 , V_67 ) ;
if ( F_37 ( V_2 , V_45 ) &&
! V_55 )
V_57 = V_68 ;
V_56 = 0 ;
* V_51 = type |
V_52 |
V_53 |
V_54 |
V_55 |
V_57 |
V_56 ;
return 0 ;
}
static T_1 F_43 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_6 ( V_2 ) ;
struct V_18 * V_19 = F_17 ( V_6 ) ;
int V_7 = F_18 ( V_2 ) ;
T_1 V_69 ;
T_1 V_70 ;
T_1 V_71 ;
struct V_4 * V_72 =
F_3 ( V_6 , V_7 ) ;
V_69 = V_72 -> V_73 ;
V_70 = V_72 -> V_74 ;
V_71 = ( V_69 / 64 ) - 1 ;
F_44 ( V_19 , L_2 ,
V_7 , V_69 , V_70 ) ;
return ( 0x1f & V_71 ) << 10 |
( 0xff & V_70 ) << 0 ;
}
void F_45 ( struct V_1 * V_2 , T_1 V_75 ,
T_1 V_56 , T_1 V_48 )
{
struct V_5 * V_6 = F_6 ( V_2 ) ;
int V_7 = F_18 ( V_2 ) ;
struct V_4 * V_72 =
F_3 ( V_6 , V_7 ) ;
T_1 V_53 = V_72 -> V_76 ? V_77 : 0 ;
if ( V_75 > 0xA ) {
struct V_18 * V_19 = F_17 ( V_6 ) ;
F_20 ( V_19 , L_3 , V_75 ) ;
V_75 = 0 ;
}
F_27 ( V_2 ) ;
V_2 -> V_48 = V_48 ;
F_25 ( V_2 ) ;
F_24 ( V_2 , 0xFFFF ,
( V_75 << 12 ) |
V_48 ) ;
if ( ! F_8 ( V_2 ) )
F_14 ( V_2 , 0x000F | V_77 , V_56 | V_53 ) ;
}
int F_39 ( struct V_1 * V_2 )
{
return V_2 -> V_48 ;
}
int F_38 ( struct V_1 * V_2 )
{
return F_46 ( V_2 , V_67 ) ;
}
int F_47 ( struct V_1 * V_2 )
{
return F_46 ( V_2 , V_65 ) ;
}
int F_48 ( struct V_1 * V_2 )
{
return F_46 ( V_2 , V_78 ) ;
}
void F_49 ( struct V_1 * V_2 , int V_79 )
{
if ( V_79 )
F_42 ( V_2 , V_78 ) ;
else
F_50 ( V_2 , V_78 ) ;
}
void F_51 ( struct V_1 * V_2 , int V_80 )
{
T_1 V_9 = ( V_81 | V_82 ) ;
T_1 V_10 ;
switch ( V_80 ) {
case 0 :
V_10 = V_81 ;
break;
case 1 :
V_10 = V_82 ;
break;
default:
return;
}
F_5 ( V_2 , V_9 , V_10 ) ;
}
static int F_52 ( struct V_1 * V_2 )
{
return ! ! ( F_10 ( V_2 ) & V_83 ) ;
}
void F_53 ( struct V_1 * V_2 )
{
if ( F_8 ( V_2 ) ) {
F_54 ( V_2 ) ;
} else {
F_5 ( V_2 , V_84 , V_84 ) ;
F_5 ( V_2 , V_84 , 0 ) ;
}
}
void F_55 ( struct V_1 * V_2 , int V_85 )
{
int V_80 ;
if ( F_8 ( V_2 ) )
return;
F_25 ( V_2 ) ;
if ( ! ( V_85 ^ ! ! ( F_15 ( V_2 ) & V_86 ) ) )
return;
V_80 = F_52 ( V_2 ) ;
F_14 ( V_2 , V_86 , V_85 ? V_86 : 0 ) ;
F_53 ( V_2 ) ;
F_51 ( V_2 , V_80 ) ;
}
static struct V_1 * F_56 ( struct V_5 * V_6 , T_3 type )
{
struct V_1 * V_87 , * V_2 ;
int V_88 ;
V_2 = NULL ;
F_57 (pos, priv, i) {
if ( ! F_37 ( V_87 , type ) )
continue;
if ( F_46 ( V_87 , V_89 ) )
continue;
V_2 = V_87 ;
break;
}
if ( ! V_2 )
return NULL ;
F_58 ( V_2 ) ;
F_42 ( V_2 , V_89 ) ;
return V_2 ;
}
static void F_59 ( struct V_1 * V_2 )
{
F_58 ( V_2 ) ;
}
void F_60 ( struct V_5 * V_6 ,
int (* F_61)( struct V_18 * V_90 ,
struct V_91 * V_92 , int V_93 ) )
{
struct V_94 * V_95 = F_62 ( V_6 ) ;
struct V_1 * V_2 ;
int V_88 ;
F_57 (pipe, priv, i) {
F_58 ( V_2 ) ;
V_2 -> V_96 = NULL ;
V_2 -> V_97 = NULL ;
F_63 ( & V_2 -> V_98 ) ;
F_53 ( V_2 ) ;
}
V_95 -> F_61 = F_61 ;
}
struct V_1 * F_64 ( struct V_5 * V_6 ,
int V_99 ,
int V_50 )
{
struct V_18 * V_19 = F_17 ( V_6 ) ;
struct V_1 * V_2 ;
int V_49 = F_28 ( V_6 ) ;
int V_100 ;
T_1 V_51 , V_101 ;
V_2 = F_56 ( V_6 , V_99 ) ;
if ( ! V_2 ) {
F_20 ( V_19 , L_4 ,
V_3 [ V_99 ] ) ;
return NULL ;
}
F_63 ( & V_2 -> V_98 ) ;
F_29 ( V_2 ) ;
V_100 = F_27 ( V_2 ) ;
if ( V_100 < 0 ) {
F_20 ( V_19 , L_5 , F_18 ( V_2 ) ) ;
return NULL ;
}
if ( F_41 ( V_2 , V_49 , V_50 , & V_51 ) ) {
F_20 ( V_19 , L_6 ) ;
return NULL ;
}
V_101 = F_43 ( V_2 ) ;
F_25 ( V_2 ) ;
F_14 ( V_2 , 0xFFFF , V_51 ) ;
F_23 ( V_2 , 0xFFFF , V_101 ) ;
F_53 ( V_2 ) ;
F_65 ( V_2 ) ;
F_44 ( V_19 , L_7 ,
F_18 ( V_2 ) ,
F_1 ( V_2 ) ,
F_38 ( V_2 ) ? L_8 : L_9 ) ;
return V_2 ;
}
void F_66 ( struct V_1 * V_2 )
{
F_59 ( V_2 ) ;
}
void F_67 ( struct V_1 * V_2 , struct V_102 * V_96 )
{
if ( V_2 -> V_96 )
V_2 -> V_96 -> V_2 = NULL ;
V_2 -> V_96 = V_96 ;
if ( V_96 )
V_96 -> V_2 = V_2 ;
}
struct V_1 * F_68 ( struct V_5 * V_6 )
{
struct V_1 * V_2 ;
V_2 = F_56 ( V_6 , V_103 ) ;
if ( ! V_2 )
return NULL ;
F_63 ( & V_2 -> V_98 ) ;
return V_2 ;
}
void F_69 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_6 ( V_2 ) ;
F_70 ( ! F_8 ( V_2 ) ) ;
F_33 ( V_2 ) ;
if ( ! F_28 ( V_6 ) )
F_5 ( V_2 , V_104 , V_104 ) ;
}
void F_71 ( struct V_1 * V_2 , int V_105 )
{
F_14 ( V_2 , V_66 ,
V_105 ? V_66 : 0 ) ;
}
int F_72 ( struct V_5 * V_6 )
{
struct V_94 * V_95 = F_62 ( V_6 ) ;
struct V_1 * V_2 ;
struct V_18 * V_19 = F_17 ( V_6 ) ;
struct V_4 * V_8 =
F_4 ( V_6 , V_8 ) ;
int V_106 = F_4 ( V_6 , V_106 ) ;
int V_88 ;
if ( V_8 [ 0 ] . type != V_103 ) {
F_20 ( V_19 , L_10 ) ;
return - V_64 ;
}
V_95 -> V_2 = F_73 ( sizeof( struct V_1 ) * V_106 , V_107 ) ;
if ( ! V_95 -> V_2 )
return - V_108 ;
V_95 -> V_109 = V_106 ;
F_57 (pipe, priv, i) {
V_2 -> V_6 = V_6 ;
F_2 ( V_2 ) =
V_8 [ V_88 ] . type & V_110 ;
F_44 ( V_19 , L_11 ,
V_88 , V_3 [ V_8 [ V_88 ] . type ] ) ;
}
return 0 ;
}
void F_74 ( struct V_5 * V_6 )
{
struct V_94 * V_95 = F_62 ( V_6 ) ;
F_75 ( V_95 -> V_2 ) ;
}
