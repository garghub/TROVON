char * F_1 ( struct V_1 * V_2 )
{
return V_3 [ F_2 ( V_2 ) ] ;
}
static void F_3 ( struct V_1 * V_2 , T_1 V_4 , T_1 V_5 )
{
struct V_6 * V_7 = F_4 ( V_2 ) ;
int V_8 = F_5 ( V_2 ) ;
if ( F_6 ( V_2 ) )
F_7 ( V_7 , V_9 , V_4 , V_5 ) ;
else
F_7 ( V_7 , V_10 + V_8 , V_4 , V_5 ) ;
}
static T_1 F_8 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_4 ( V_2 ) ;
int V_8 = F_5 ( V_2 ) ;
if ( F_6 ( V_2 ) )
return F_9 ( V_7 , V_9 ) ;
else
return F_9 ( V_7 , V_10 + V_8 ) ;
}
static void F_10 ( struct V_1 * V_2 ,
T_1 V_11 , T_1 V_12 ,
T_1 V_4 , T_1 V_5 )
{
struct V_6 * V_7 = F_4 ( V_2 ) ;
if ( F_6 ( V_2 ) )
F_7 ( V_7 , V_11 , V_4 , V_5 ) ;
else
F_7 ( V_7 , V_12 , V_4 , V_5 ) ;
}
static void F_11 ( struct V_1 * V_2 , T_1 V_4 , T_1 V_5 )
{
F_10 ( V_2 , V_13 , V_14 , V_4 , V_5 ) ;
}
static void F_12 ( struct V_1 * V_2 , T_1 V_4 , T_1 V_5 )
{
struct V_6 * V_7 = F_4 ( V_2 ) ;
struct V_15 * V_16 = F_13 ( V_7 ) ;
int V_17 = F_14 ( V_2 ) ;
T_1 V_18 ;
#define F_15 ( T_2 ) \
case 0x ## a: \
reg = PIPE ## a ## TRN; \
break;
switch ( V_17 ) {
F_15 ( 1 ) ;
F_15 ( 2 ) ;
F_15 ( 3 ) ;
F_15 ( 4 ) ;
F_15 ( 5 ) ;
F_15 ( V_19 ) ;
F_15 ( V_20 ) ;
F_15 ( V_21 ) ;
F_15 ( V_22 ) ;
F_15 ( V_23 ) ;
F_15 ( 9 ) ;
F_15 ( V_24 ) ;
default:
F_16 ( V_16 , L_1 , V_17 ) ;
return;
}
F_10 ( V_2 , 0 , V_18 , V_4 , V_5 ) ;
}
static void F_17 ( struct V_1 * V_2 , T_1 V_4 , T_1 V_5 )
{
struct V_6 * V_7 = F_4 ( V_2 ) ;
struct V_15 * V_16 = F_13 ( V_7 ) ;
int V_17 = F_14 ( V_2 ) ;
T_1 V_18 ;
#define F_18 ( T_2 ) \
case 0x ## a: \
reg = PIPE ## a ## TRE; \
break;
switch ( V_17 ) {
F_18 ( 1 ) ;
F_18 ( 2 ) ;
F_18 ( 3 ) ;
F_18 ( 4 ) ;
F_18 ( 5 ) ;
F_18 ( V_19 ) ;
F_18 ( V_20 ) ;
F_18 ( V_21 ) ;
F_18 ( V_22 ) ;
F_18 ( V_23 ) ;
F_18 ( 9 ) ;
F_18 ( V_24 ) ;
default:
F_16 ( V_16 , L_1 , V_17 ) ;
return;
}
F_10 ( V_2 , 0 , V_18 , V_4 , V_5 ) ;
}
static void F_19 ( struct V_1 * V_2 , T_1 V_4 , T_1 V_5 )
{
if ( F_6 ( V_2 ) )
return;
F_10 ( V_2 , 0 , V_25 , V_4 , V_5 ) ;
}
static void F_20 ( struct V_1 * V_2 , T_1 V_4 , T_1 V_5 )
{
F_10 ( V_2 , V_26 , V_27 , V_4 , V_5 ) ;
}
static void F_21 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_4 ( V_2 ) ;
F_22 ( V_7 , V_28 , 0xF & F_14 ( V_2 ) ) ;
}
static int F_23 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_4 ( V_2 ) ;
int V_29 = 1024 ;
T_1 V_5 ;
F_22 ( V_7 , V_30 , 0 ) ;
F_24 ( V_2 ) ;
do {
V_5 = F_8 ( V_2 ) ;
V_5 &= V_31 | V_32 ;
if ( ! V_5 )
return 0 ;
F_25 ( 10 ) ;
} while ( V_29 -- );
return - V_33 ;
}
int F_26 ( struct V_1 * V_2 )
{
T_1 V_5 ;
V_5 = F_8 ( V_2 ) ;
if ( V_5 & V_34 )
return 0 ;
return - V_33 ;
}
static void F_27 ( struct V_1 * V_2 )
{
T_1 V_35 = F_8 ( V_2 ) ;
V_35 &= V_32 ;
switch ( V_35 ) {
case V_36 :
F_3 ( V_2 , V_32 , V_37 ) ;
case V_37 :
F_3 ( V_2 , V_32 , V_38 ) ;
}
}
void F_24 ( struct V_1 * V_2 )
{
int V_29 = 1024 ;
T_1 V_5 ;
F_27 ( V_2 ) ;
F_3 ( V_2 , V_32 , V_38 ) ;
do {
V_5 = F_8 ( V_2 ) ;
V_5 &= V_39 ;
if ( ! V_5 )
break;
F_25 ( 10 ) ;
} while ( V_29 -- );
}
void F_28 ( struct V_1 * V_2 )
{
F_27 ( V_2 ) ;
F_3 ( V_2 , V_32 , V_40 ) ;
}
void F_29 ( struct V_1 * V_2 )
{
T_1 V_35 = F_8 ( V_2 ) ;
V_35 &= V_32 ;
switch ( V_35 ) {
case V_38 :
F_3 ( V_2 , V_32 , V_37 ) ;
break;
case V_40 :
F_3 ( V_2 , V_32 , V_36 ) ;
break;
}
}
int F_30 ( struct V_1 * V_2 )
{
T_1 V_35 = F_8 ( V_2 ) & V_32 ;
return ( int ) ( V_35 == V_37 || V_35 == V_36 ) ;
}
void F_31 ( struct V_1 * V_2 , int V_41 )
{
if ( ! F_32 ( V_2 , V_42 ) )
return;
F_17 ( V_2 , V_43 | V_44 , V_43 ) ;
if ( F_33 ( V_2 ) ) {
int V_45 = F_34 ( V_2 ) ;
F_12 ( V_2 , 0xffff , F_35 ( V_41 , V_45 ) ) ;
F_17 ( V_2 , V_44 , V_44 ) ;
}
}
static int F_36 ( struct V_1 * V_2 )
{
if ( F_32 ( V_2 , V_42 ) ||
F_32 ( V_2 , V_46 ) )
return 1 ;
return 0 ;
}
static T_1 F_37 ( struct V_1 * V_2 ,
int V_47 ,
int V_48 )
{
T_1 type = 0 ;
T_1 V_49 = 0 ;
T_1 V_50 = 0 ;
T_1 V_51 = 0 ;
T_1 V_52 = 0 ;
T_1 V_53 = 0 ;
T_1 V_54 = 0 ;
T_1 V_55 [] = {
[ V_42 ] = V_56 ,
[ V_57 ] = V_58 ,
[ V_46 ] = V_59 ,
} ;
int V_60 = F_36 ( V_2 ) ;
if ( F_6 ( V_2 ) )
return - V_61 ;
type = V_55 [ F_2 ( V_2 ) ] ;
if ( F_32 ( V_2 , V_46 ) ||
F_32 ( V_2 , V_42 ) )
V_49 = 0 ;
if ( F_32 ( V_2 , V_46 ) ||
F_32 ( V_2 , V_42 ) )
V_50 = ( V_60 ) ? V_62 : 0 ;
if ( F_32 ( V_2 , V_42 ) )
V_51 = 0 ;
if ( V_48 )
F_38 ( V_2 , V_63 ) ;
if ( ! ! V_47 ^ ! ! V_48 )
V_52 |= V_64 ;
if ( ! V_52 )
F_38 ( V_2 , V_65 ) ;
if ( F_32 ( V_2 , V_42 ) &&
! V_52 )
V_54 = V_66 ;
V_53 = 0 ;
return type |
V_49 |
V_50 |
V_51 |
V_52 |
V_54 |
V_53 ;
}
static T_1 F_39 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_4 ( V_2 ) ;
struct V_67 * V_68 = F_40 ( V_7 ) ;
struct V_15 * V_16 = F_13 ( V_7 ) ;
int V_69 = F_14 ( V_2 ) ;
int V_60 = F_36 ( V_2 ) ;
T_1 V_70 ;
T_1 V_71 ;
T_1 V_72 ;
if ( F_32 ( V_2 , V_73 ) )
V_70 = 256 ;
else if ( F_32 ( V_2 , V_57 ) )
V_70 = 64 ;
else
V_70 = 512 ;
V_72 = ( V_70 / 64 ) - 1 ;
if ( F_32 ( V_2 , V_57 ) ) {
V_71 = V_69 - 2 ;
} else {
V_71 = V_68 -> V_74 ;
V_68 -> V_74 += V_72 + 1 ;
if ( V_60 )
V_68 -> V_74 += V_72 + 1 ;
}
F_41 ( V_16 , L_2 ,
V_69 , V_70 , V_71 ) ;
return ( 0x1f & V_72 ) << 10 |
( 0xff & V_71 ) << 0 ;
}
void F_42 ( struct V_1 * V_2 , T_1 V_75 ,
T_1 V_53 , T_1 V_45 )
{
if ( V_75 > 0xA ) {
struct V_6 * V_7 = F_4 ( V_2 ) ;
struct V_15 * V_16 = F_13 ( V_7 ) ;
F_16 ( V_16 , L_3 , V_75 ) ;
V_75 = 0 ;
}
F_23 ( V_2 ) ;
V_2 -> V_45 = V_45 ;
F_21 ( V_2 ) ;
F_20 ( V_2 , 0xFFFF ,
( V_75 << 12 ) |
V_45 ) ;
if ( ! F_6 ( V_2 ) )
F_11 ( V_2 , 0x000F , V_53 ) ;
}
int F_34 ( struct V_1 * V_2 )
{
return V_2 -> V_45 ;
}
int F_33 ( struct V_1 * V_2 )
{
return F_43 ( V_2 , V_65 ) ;
}
int F_44 ( struct V_1 * V_2 )
{
return F_43 ( V_2 , V_63 ) ;
}
int F_45 ( struct V_1 * V_2 )
{
return F_43 ( V_2 , V_76 ) ;
}
void F_46 ( struct V_1 * V_2 , int V_77 )
{
if ( V_77 )
F_38 ( V_2 , V_76 ) ;
else
F_47 ( V_2 , V_76 ) ;
}
void F_48 ( struct V_1 * V_2 , int V_78 )
{
T_1 V_4 = ( V_79 | V_80 ) ;
T_1 V_5 ;
switch ( V_78 ) {
case 0 :
V_5 = V_79 ;
break;
case 1 :
V_5 = V_80 ;
break;
default:
return;
}
F_3 ( V_2 , V_4 , V_5 ) ;
}
void F_49 ( struct V_1 * V_2 )
{
if ( F_6 ( V_2 ) ) {
F_50 ( V_2 ) ;
} else {
F_3 ( V_2 , V_81 , V_81 ) ;
F_3 ( V_2 , V_81 , 0 ) ;
}
}
static struct V_1 * F_51 ( struct V_6 * V_7 , T_3 type )
{
struct V_1 * V_82 , * V_2 ;
int V_83 ;
V_2 = NULL ;
F_52 (pos, priv, i) {
if ( ! F_32 ( V_82 , type ) )
continue;
if ( F_43 ( V_82 , V_84 ) )
continue;
V_2 = V_82 ;
break;
}
if ( ! V_2 )
return NULL ;
F_53 ( V_2 ) ;
F_38 ( V_2 , V_84 ) ;
return V_2 ;
}
static void F_54 ( struct V_1 * V_2 )
{
F_53 ( V_2 ) ;
}
void F_55 ( struct V_6 * V_7 ,
int (* F_56)( struct V_85 * V_86 , int V_87 ) )
{
struct V_67 * V_68 = F_40 ( V_7 ) ;
struct V_1 * V_2 ;
int V_83 ;
V_68 -> V_74 = 4 ;
F_52 (pipe, priv, i) {
if ( F_32 ( V_2 , V_57 ) )
V_68 -> V_74 ++ ;
F_53 ( V_2 ) ;
V_2 -> V_88 = NULL ;
V_2 -> V_89 = NULL ;
F_57 ( & V_2 -> V_90 ) ;
F_49 ( V_2 ) ;
}
V_68 -> F_56 = F_56 ;
}
struct V_1 * F_58 ( struct V_6 * V_7 ,
int V_91 ,
int V_48 )
{
struct V_15 * V_16 = F_13 ( V_7 ) ;
struct V_1 * V_2 ;
int V_47 = F_59 ( V_7 ) ;
int V_92 ;
T_1 V_93 , V_94 ;
V_2 = F_51 ( V_7 , V_91 ) ;
if ( ! V_2 ) {
F_16 ( V_16 , L_4 ,
V_3 [ V_91 ] ) ;
return NULL ;
}
F_57 ( & V_2 -> V_90 ) ;
F_24 ( V_2 ) ;
V_92 = F_23 ( V_2 ) ;
if ( V_92 < 0 ) {
F_16 ( V_16 , L_5 , F_14 ( V_2 ) ) ;
return NULL ;
}
V_93 = F_37 ( V_2 , V_47 , V_48 ) ;
V_94 = F_39 ( V_2 ) ;
F_21 ( V_2 ) ;
F_11 ( V_2 , 0xFFFF , V_93 ) ;
F_19 ( V_2 , 0xFFFF , V_94 ) ;
F_49 ( V_2 ) ;
F_60 ( V_2 ) ;
F_41 ( V_16 , L_6 ,
F_14 ( V_2 ) ,
F_1 ( V_2 ) ,
F_33 ( V_2 ) ? L_7 : L_8 ) ;
return V_2 ;
}
void F_61 ( struct V_1 * V_2 )
{
F_54 ( V_2 ) ;
}
void F_62 ( struct V_1 * V_2 , struct V_95 * V_88 )
{
if ( V_2 -> V_88 )
V_2 -> V_88 -> V_2 = NULL ;
V_2 -> V_88 = V_88 ;
if ( V_88 )
V_88 -> V_2 = V_2 ;
}
struct V_1 * F_63 ( struct V_6 * V_7 )
{
struct V_1 * V_2 ;
V_2 = F_51 ( V_7 , V_73 ) ;
if ( ! V_2 )
return NULL ;
F_57 ( & V_2 -> V_90 ) ;
return V_2 ;
}
void F_64 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_4 ( V_2 ) ;
F_65 ( ! F_6 ( V_2 ) ) ;
F_28 ( V_2 ) ;
if ( ! F_59 ( V_7 ) )
F_3 ( V_2 , V_96 , V_96 ) ;
}
void F_66 ( struct V_1 * V_2 , int V_97 )
{
F_11 ( V_2 , V_64 ,
V_97 ? V_64 : 0 ) ;
}
int F_67 ( struct V_6 * V_7 )
{
struct V_67 * V_68 = F_40 ( V_7 ) ;
struct V_1 * V_2 ;
struct V_15 * V_16 = F_13 ( V_7 ) ;
T_3 * V_98 = F_68 ( V_7 , V_98 ) ;
int V_99 = F_68 ( V_7 , V_99 ) ;
int V_83 ;
if ( V_98 [ 0 ] != V_73 ) {
F_16 ( V_16 , L_9 ) ;
return - V_61 ;
}
V_68 -> V_2 = F_69 ( sizeof( struct V_1 ) * V_99 , V_100 ) ;
if ( ! V_68 -> V_2 ) {
F_16 ( V_16 , L_10 ) ;
return - V_101 ;
}
V_68 -> V_102 = V_99 ;
F_52 (pipe, priv, i) {
V_2 -> V_7 = V_7 ;
F_2 ( V_2 ) =
V_98 [ V_83 ] & V_103 ;
F_41 ( V_16 , L_11 ,
V_83 , V_3 [ V_98 [ V_83 ] ] ) ;
}
return 0 ;
}
void F_70 ( struct V_6 * V_7 )
{
struct V_67 * V_68 = F_40 ( V_7 ) ;
F_71 ( V_68 -> V_2 ) ;
}
