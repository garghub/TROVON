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
static T_1 F_41 ( struct V_1 * V_2 ,
int V_49 ,
int V_50 )
{
T_1 type = 0 ;
T_1 V_51 = 0 ;
T_1 V_52 = 0 ;
T_1 V_53 = 0 ;
T_1 V_54 = 0 ;
T_1 V_55 = 0 ;
T_1 V_56 = 0 ;
T_1 V_57 [] = {
[ V_45 ] = V_58 ,
[ V_59 ] = V_60 ,
[ V_61 ] = V_62 ,
} ;
if ( F_8 ( V_2 ) )
return - V_63 ;
type = V_57 [ F_2 ( V_2 ) ] ;
if ( F_37 ( V_2 , V_61 ) ||
F_37 ( V_2 , V_45 ) )
V_51 = 0 ;
if ( F_37 ( V_2 , V_45 ) )
V_53 = 0 ;
if ( V_50 )
F_42 ( V_2 , V_64 ) ;
if ( ! ! V_49 ^ ! ! V_50 )
V_54 |= V_65 ;
if ( ! V_54 )
F_42 ( V_2 , V_66 ) ;
if ( F_37 ( V_2 , V_45 ) &&
! V_54 )
V_56 = V_67 ;
V_55 = 0 ;
return type |
V_51 |
V_52 |
V_53 |
V_54 |
V_56 |
V_55 ;
}
static T_1 F_43 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_6 ( V_2 ) ;
struct V_18 * V_19 = F_17 ( V_6 ) ;
int V_7 = F_18 ( V_2 ) ;
T_1 V_68 ;
T_1 V_69 ;
T_1 V_70 ;
struct V_4 * V_71 =
F_3 ( V_6 , V_7 ) ;
V_68 = V_71 -> V_72 ;
V_69 = V_71 -> V_73 ;
V_70 = ( V_68 / 64 ) - 1 ;
F_44 ( V_19 , L_2 ,
V_7 , V_68 , V_69 ) ;
return ( 0x1f & V_70 ) << 10 |
( 0xff & V_69 ) << 0 ;
}
void F_45 ( struct V_1 * V_2 , T_1 V_74 ,
T_1 V_55 , T_1 V_48 )
{
struct V_5 * V_6 = F_6 ( V_2 ) ;
int V_7 = F_18 ( V_2 ) ;
struct V_4 * V_71 =
F_3 ( V_6 , V_7 ) ;
T_1 V_52 = V_71 -> V_75 ? V_76 : 0 ;
if ( V_74 > 0xA ) {
struct V_18 * V_19 = F_17 ( V_6 ) ;
F_20 ( V_19 , L_3 , V_74 ) ;
V_74 = 0 ;
}
F_27 ( V_2 ) ;
V_2 -> V_48 = V_48 ;
F_25 ( V_2 ) ;
F_24 ( V_2 , 0xFFFF ,
( V_74 << 12 ) |
V_48 ) ;
if ( ! F_8 ( V_2 ) )
F_14 ( V_2 , 0x000F | V_76 , V_55 | V_52 ) ;
}
int F_39 ( struct V_1 * V_2 )
{
return V_2 -> V_48 ;
}
int F_38 ( struct V_1 * V_2 )
{
return F_46 ( V_2 , V_66 ) ;
}
int F_47 ( struct V_1 * V_2 )
{
return F_46 ( V_2 , V_64 ) ;
}
int F_48 ( struct V_1 * V_2 )
{
return F_46 ( V_2 , V_77 ) ;
}
void F_49 ( struct V_1 * V_2 , int V_78 )
{
if ( V_78 )
F_42 ( V_2 , V_77 ) ;
else
F_50 ( V_2 , V_77 ) ;
}
void F_51 ( struct V_1 * V_2 , int V_79 )
{
T_1 V_9 = ( V_80 | V_81 ) ;
T_1 V_10 ;
switch ( V_79 ) {
case 0 :
V_10 = V_80 ;
break;
case 1 :
V_10 = V_81 ;
break;
default:
return;
}
F_5 ( V_2 , V_9 , V_10 ) ;
}
static int F_52 ( struct V_1 * V_2 )
{
return ! ! ( F_10 ( V_2 ) & V_82 ) ;
}
void F_53 ( struct V_1 * V_2 )
{
if ( F_8 ( V_2 ) ) {
F_54 ( V_2 ) ;
} else {
F_5 ( V_2 , V_83 , V_83 ) ;
F_5 ( V_2 , V_83 , 0 ) ;
}
}
void F_55 ( struct V_1 * V_2 , int V_84 )
{
int V_79 ;
if ( F_8 ( V_2 ) )
return;
F_25 ( V_2 ) ;
if ( ! ( V_84 ^ ! ! ( F_15 ( V_2 ) & V_85 ) ) )
return;
V_79 = F_52 ( V_2 ) ;
F_14 ( V_2 , V_85 , V_84 ? V_85 : 0 ) ;
F_53 ( V_2 ) ;
F_51 ( V_2 , V_79 ) ;
}
static struct V_1 * F_56 ( struct V_5 * V_6 , T_3 type )
{
struct V_1 * V_86 , * V_2 ;
int V_87 ;
V_2 = NULL ;
F_57 (pos, priv, i) {
if ( ! F_37 ( V_86 , type ) )
continue;
if ( F_46 ( V_86 , V_88 ) )
continue;
V_2 = V_86 ;
break;
}
if ( ! V_2 )
return NULL ;
F_58 ( V_2 ) ;
F_42 ( V_2 , V_88 ) ;
return V_2 ;
}
static void F_59 ( struct V_1 * V_2 )
{
F_58 ( V_2 ) ;
}
void F_60 ( struct V_5 * V_6 ,
int (* F_61)( struct V_89 * V_90 , int V_91 ) )
{
struct V_92 * V_93 = F_62 ( V_6 ) ;
struct V_1 * V_2 ;
int V_87 ;
F_57 (pipe, priv, i) {
F_58 ( V_2 ) ;
V_2 -> V_94 = NULL ;
V_2 -> V_95 = NULL ;
F_63 ( & V_2 -> V_96 ) ;
F_53 ( V_2 ) ;
}
V_93 -> F_61 = F_61 ;
}
struct V_1 * F_64 ( struct V_5 * V_6 ,
int V_97 ,
int V_50 )
{
struct V_18 * V_19 = F_17 ( V_6 ) ;
struct V_1 * V_2 ;
int V_49 = F_28 ( V_6 ) ;
int V_98 ;
T_1 V_99 , V_100 ;
V_2 = F_56 ( V_6 , V_97 ) ;
if ( ! V_2 ) {
F_20 ( V_19 , L_4 ,
V_3 [ V_97 ] ) ;
return NULL ;
}
F_63 ( & V_2 -> V_96 ) ;
F_29 ( V_2 ) ;
V_98 = F_27 ( V_2 ) ;
if ( V_98 < 0 ) {
F_20 ( V_19 , L_5 , F_18 ( V_2 ) ) ;
return NULL ;
}
V_99 = F_41 ( V_2 , V_49 , V_50 ) ;
V_100 = F_43 ( V_2 ) ;
F_25 ( V_2 ) ;
F_14 ( V_2 , 0xFFFF , V_99 ) ;
F_23 ( V_2 , 0xFFFF , V_100 ) ;
F_53 ( V_2 ) ;
F_65 ( V_2 ) ;
F_44 ( V_19 , L_6 ,
F_18 ( V_2 ) ,
F_1 ( V_2 ) ,
F_38 ( V_2 ) ? L_7 : L_8 ) ;
return V_2 ;
}
void F_66 ( struct V_1 * V_2 )
{
F_59 ( V_2 ) ;
}
void F_67 ( struct V_1 * V_2 , struct V_101 * V_94 )
{
if ( V_2 -> V_94 )
V_2 -> V_94 -> V_2 = NULL ;
V_2 -> V_94 = V_94 ;
if ( V_94 )
V_94 -> V_2 = V_2 ;
}
struct V_1 * F_68 ( struct V_5 * V_6 )
{
struct V_1 * V_2 ;
V_2 = F_56 ( V_6 , V_102 ) ;
if ( ! V_2 )
return NULL ;
F_63 ( & V_2 -> V_96 ) ;
return V_2 ;
}
void F_69 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_6 ( V_2 ) ;
F_70 ( ! F_8 ( V_2 ) ) ;
F_33 ( V_2 ) ;
if ( ! F_28 ( V_6 ) )
F_5 ( V_2 , V_103 , V_103 ) ;
}
void F_71 ( struct V_1 * V_2 , int V_104 )
{
F_14 ( V_2 , V_65 ,
V_104 ? V_65 : 0 ) ;
}
int F_72 ( struct V_5 * V_6 )
{
struct V_92 * V_93 = F_62 ( V_6 ) ;
struct V_1 * V_2 ;
struct V_18 * V_19 = F_17 ( V_6 ) ;
struct V_4 * V_8 =
F_4 ( V_6 , V_8 ) ;
int V_105 = F_4 ( V_6 , V_105 ) ;
int V_87 ;
if ( V_8 [ 0 ] . type != V_102 ) {
F_20 ( V_19 , L_9 ) ;
return - V_63 ;
}
V_93 -> V_2 = F_73 ( sizeof( struct V_1 ) * V_105 , V_106 ) ;
if ( ! V_93 -> V_2 ) {
F_20 ( V_19 , L_10 ) ;
return - V_107 ;
}
V_93 -> V_108 = V_105 ;
F_57 (pipe, priv, i) {
V_2 -> V_6 = V_6 ;
F_2 ( V_2 ) =
V_8 [ V_87 ] . type & V_109 ;
F_44 ( V_19 , L_11 ,
V_87 , V_3 [ V_8 [ V_87 ] . type ] ) ;
}
return 0 ;
}
void F_74 ( struct V_5 * V_6 )
{
struct V_92 * V_93 = F_62 ( V_6 ) ;
F_75 ( V_93 -> V_2 ) ;
}
