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
static T_1 F_11 ( struct V_1 * V_2 ,
T_1 V_11 , T_1 V_12 )
{
struct V_6 * V_7 = F_4 ( V_2 ) ;
if ( F_6 ( V_2 ) )
return F_9 ( V_7 , V_11 ) ;
else
return F_9 ( V_7 , V_12 ) ;
}
static void F_12 ( struct V_1 * V_2 , T_1 V_4 , T_1 V_5 )
{
F_10 ( V_2 , V_13 , V_14 , V_4 , V_5 ) ;
}
static T_1 F_13 ( struct V_1 * V_2 )
{
return F_11 ( V_2 , V_13 , V_14 ) ;
}
static void F_14 ( struct V_1 * V_2 , T_1 V_4 , T_1 V_5 )
{
struct V_6 * V_7 = F_4 ( V_2 ) ;
struct V_15 * V_16 = F_15 ( V_7 ) ;
int V_17 = F_16 ( V_2 ) ;
T_1 V_18 ;
#define F_17 ( T_2 ) \
case 0x ## a: \
reg = PIPE ## a ## TRN; \
break;
switch ( V_17 ) {
F_17 ( 1 ) ;
F_17 ( 2 ) ;
F_17 ( 3 ) ;
F_17 ( 4 ) ;
F_17 ( 5 ) ;
F_17 ( V_19 ) ;
F_17 ( V_20 ) ;
F_17 ( V_21 ) ;
F_17 ( V_22 ) ;
F_17 ( V_23 ) ;
F_17 ( 9 ) ;
F_17 ( V_24 ) ;
default:
F_18 ( V_16 , L_1 , V_17 ) ;
return;
}
F_10 ( V_2 , 0 , V_18 , V_4 , V_5 ) ;
}
static void F_19 ( struct V_1 * V_2 , T_1 V_4 , T_1 V_5 )
{
struct V_6 * V_7 = F_4 ( V_2 ) ;
struct V_15 * V_16 = F_15 ( V_7 ) ;
int V_17 = F_16 ( V_2 ) ;
T_1 V_18 ;
#define F_20 ( T_2 ) \
case 0x ## a: \
reg = PIPE ## a ## TRE; \
break;
switch ( V_17 ) {
F_20 ( 1 ) ;
F_20 ( 2 ) ;
F_20 ( 3 ) ;
F_20 ( 4 ) ;
F_20 ( 5 ) ;
F_20 ( V_19 ) ;
F_20 ( V_20 ) ;
F_20 ( V_21 ) ;
F_20 ( V_22 ) ;
F_20 ( V_23 ) ;
F_20 ( 9 ) ;
F_20 ( V_24 ) ;
default:
F_18 ( V_16 , L_1 , V_17 ) ;
return;
}
F_10 ( V_2 , 0 , V_18 , V_4 , V_5 ) ;
}
static void F_21 ( struct V_1 * V_2 , T_1 V_4 , T_1 V_5 )
{
if ( F_6 ( V_2 ) )
return;
F_10 ( V_2 , 0 , V_25 , V_4 , V_5 ) ;
}
static void F_22 ( struct V_1 * V_2 , T_1 V_4 , T_1 V_5 )
{
F_10 ( V_2 , V_26 , V_27 , V_4 , V_5 ) ;
}
static void F_23 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_4 ( V_2 ) ;
F_24 ( V_7 , V_28 , 0xF & F_16 ( V_2 ) ) ;
}
static int F_25 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_4 ( V_2 ) ;
int V_29 = 1024 ;
T_1 V_5 ;
F_24 ( V_7 , V_30 , 0 ) ;
F_26 ( V_2 ) ;
do {
V_5 = F_8 ( V_2 ) ;
V_5 &= V_31 | V_32 ;
if ( ! V_5 )
return 0 ;
F_27 ( 10 ) ;
} while ( V_29 -- );
return - V_33 ;
}
int F_28 ( struct V_1 * V_2 )
{
T_1 V_5 ;
V_5 = F_8 ( V_2 ) ;
if ( V_5 & V_34 )
return 0 ;
return - V_33 ;
}
static void F_29 ( struct V_1 * V_2 )
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
void F_26 ( struct V_1 * V_2 )
{
int V_29 = 1024 ;
T_1 V_5 ;
F_29 ( V_2 ) ;
F_3 ( V_2 , V_32 , V_38 ) ;
do {
V_5 = F_8 ( V_2 ) ;
V_5 &= V_39 ;
if ( ! V_5 )
break;
F_27 ( 10 ) ;
} while ( V_29 -- );
}
void F_30 ( struct V_1 * V_2 )
{
F_29 ( V_2 ) ;
F_3 ( V_2 , V_32 , V_40 ) ;
}
void F_31 ( struct V_1 * V_2 )
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
int F_32 ( struct V_1 * V_2 )
{
T_1 V_35 = F_8 ( V_2 ) & V_32 ;
return ( int ) ( V_35 == V_37 || V_35 == V_36 ) ;
}
void F_33 ( struct V_1 * V_2 , int V_41 )
{
if ( ! F_34 ( V_2 , V_42 ) )
return;
F_19 ( V_2 , V_43 | V_44 , V_43 ) ;
if ( F_35 ( V_2 ) ) {
int V_45 = F_36 ( V_2 ) ;
F_14 ( V_2 , 0xffff , F_37 ( V_41 , V_45 ) ) ;
F_19 ( V_2 , V_44 , V_44 ) ;
}
}
static int F_38 ( struct V_1 * V_2 )
{
if ( F_34 ( V_2 , V_42 ) ||
F_34 ( V_2 , V_46 ) )
return 1 ;
return 0 ;
}
static T_1 F_39 ( struct V_1 * V_2 ,
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
int V_60 = F_38 ( V_2 ) ;
if ( F_6 ( V_2 ) )
return - V_61 ;
type = V_55 [ F_2 ( V_2 ) ] ;
if ( F_34 ( V_2 , V_46 ) ||
F_34 ( V_2 , V_42 ) )
V_49 = 0 ;
if ( F_34 ( V_2 , V_46 ) ||
F_34 ( V_2 , V_42 ) )
V_50 = ( V_60 ) ? V_62 : 0 ;
if ( F_34 ( V_2 , V_42 ) )
V_51 = 0 ;
if ( V_48 )
F_40 ( V_2 , V_63 ) ;
if ( ! ! V_47 ^ ! ! V_48 )
V_52 |= V_64 ;
if ( ! V_52 )
F_40 ( V_2 , V_65 ) ;
if ( F_34 ( V_2 , V_42 ) &&
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
static T_1 F_41 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_4 ( V_2 ) ;
struct V_67 * V_68 = F_42 ( V_7 ) ;
struct V_15 * V_16 = F_15 ( V_7 ) ;
int V_69 = F_16 ( V_2 ) ;
int V_60 = F_38 ( V_2 ) ;
T_1 V_70 ;
T_1 V_71 ;
T_1 V_72 ;
if ( F_34 ( V_2 , V_73 ) )
V_70 = 256 ;
else if ( F_34 ( V_2 , V_57 ) )
V_70 = 64 ;
else
V_70 = 512 ;
V_72 = ( V_70 / 64 ) - 1 ;
if ( F_34 ( V_2 , V_57 ) ) {
V_71 = V_69 - 2 ;
} else {
V_71 = V_68 -> V_74 ;
V_68 -> V_74 += V_72 + 1 ;
if ( V_60 )
V_68 -> V_74 += V_72 + 1 ;
}
F_43 ( V_16 , L_2 ,
V_69 , V_70 , V_71 ) ;
return ( 0x1f & V_72 ) << 10 |
( 0xff & V_71 ) << 0 ;
}
void F_44 ( struct V_1 * V_2 , T_1 V_75 ,
T_1 V_53 , T_1 V_45 )
{
if ( V_75 > 0xA ) {
struct V_6 * V_7 = F_4 ( V_2 ) ;
struct V_15 * V_16 = F_15 ( V_7 ) ;
F_18 ( V_16 , L_3 , V_75 ) ;
V_75 = 0 ;
}
F_25 ( V_2 ) ;
V_2 -> V_45 = V_45 ;
F_23 ( V_2 ) ;
F_22 ( V_2 , 0xFFFF ,
( V_75 << 12 ) |
V_45 ) ;
if ( ! F_6 ( V_2 ) )
F_12 ( V_2 , 0x000F , V_53 ) ;
}
int F_36 ( struct V_1 * V_2 )
{
return V_2 -> V_45 ;
}
int F_35 ( struct V_1 * V_2 )
{
return F_45 ( V_2 , V_65 ) ;
}
int F_46 ( struct V_1 * V_2 )
{
return F_45 ( V_2 , V_63 ) ;
}
int F_47 ( struct V_1 * V_2 )
{
return F_45 ( V_2 , V_76 ) ;
}
void F_48 ( struct V_1 * V_2 , int V_77 )
{
if ( V_77 )
F_40 ( V_2 , V_76 ) ;
else
F_49 ( V_2 , V_76 ) ;
}
void F_50 ( struct V_1 * V_2 , int V_78 )
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
static int F_51 ( struct V_1 * V_2 )
{
return ! ! ( F_8 ( V_2 ) & V_81 ) ;
}
void F_52 ( struct V_1 * V_2 )
{
if ( F_6 ( V_2 ) ) {
F_53 ( V_2 ) ;
} else {
F_3 ( V_2 , V_82 , V_82 ) ;
F_3 ( V_2 , V_82 , 0 ) ;
}
}
void F_54 ( struct V_1 * V_2 , int V_83 )
{
int V_78 ;
if ( F_6 ( V_2 ) )
return;
F_23 ( V_2 ) ;
if ( ! ( V_83 ^ ! ! ( F_13 ( V_2 ) & V_84 ) ) )
return;
V_78 = F_51 ( V_2 ) ;
F_12 ( V_2 , V_84 , V_83 ? V_84 : 0 ) ;
F_52 ( V_2 ) ;
F_50 ( V_2 , V_78 ) ;
}
static struct V_1 * F_55 ( struct V_6 * V_7 , T_3 type )
{
struct V_1 * V_85 , * V_2 ;
int V_86 ;
V_2 = NULL ;
F_56 (pos, priv, i) {
if ( ! F_34 ( V_85 , type ) )
continue;
if ( F_45 ( V_85 , V_87 ) )
continue;
V_2 = V_85 ;
break;
}
if ( ! V_2 )
return NULL ;
F_57 ( V_2 ) ;
F_40 ( V_2 , V_87 ) ;
return V_2 ;
}
static void F_58 ( struct V_1 * V_2 )
{
F_57 ( V_2 ) ;
}
void F_59 ( struct V_6 * V_7 ,
int (* F_60)( struct V_88 * V_89 , int V_90 ) )
{
struct V_67 * V_68 = F_42 ( V_7 ) ;
struct V_1 * V_2 ;
int V_86 ;
V_68 -> V_74 = 4 ;
F_56 (pipe, priv, i) {
if ( F_34 ( V_2 , V_57 ) )
V_68 -> V_74 ++ ;
F_57 ( V_2 ) ;
V_2 -> V_91 = NULL ;
V_2 -> V_92 = NULL ;
F_61 ( & V_2 -> V_93 ) ;
F_52 ( V_2 ) ;
}
V_68 -> F_60 = F_60 ;
}
struct V_1 * F_62 ( struct V_6 * V_7 ,
int V_94 ,
int V_48 )
{
struct V_15 * V_16 = F_15 ( V_7 ) ;
struct V_1 * V_2 ;
int V_47 = F_63 ( V_7 ) ;
int V_95 ;
T_1 V_96 , V_97 ;
V_2 = F_55 ( V_7 , V_94 ) ;
if ( ! V_2 ) {
F_18 ( V_16 , L_4 ,
V_3 [ V_94 ] ) ;
return NULL ;
}
F_61 ( & V_2 -> V_93 ) ;
F_26 ( V_2 ) ;
V_95 = F_25 ( V_2 ) ;
if ( V_95 < 0 ) {
F_18 ( V_16 , L_5 , F_16 ( V_2 ) ) ;
return NULL ;
}
V_96 = F_39 ( V_2 , V_47 , V_48 ) ;
V_97 = F_41 ( V_2 ) ;
F_23 ( V_2 ) ;
F_12 ( V_2 , 0xFFFF , V_96 ) ;
F_21 ( V_2 , 0xFFFF , V_97 ) ;
F_52 ( V_2 ) ;
F_64 ( V_2 ) ;
F_43 ( V_16 , L_6 ,
F_16 ( V_2 ) ,
F_1 ( V_2 ) ,
F_35 ( V_2 ) ? L_7 : L_8 ) ;
return V_2 ;
}
void F_65 ( struct V_1 * V_2 )
{
F_58 ( V_2 ) ;
}
void F_66 ( struct V_1 * V_2 , struct V_98 * V_91 )
{
if ( V_2 -> V_91 )
V_2 -> V_91 -> V_2 = NULL ;
V_2 -> V_91 = V_91 ;
if ( V_91 )
V_91 -> V_2 = V_2 ;
}
struct V_1 * F_67 ( struct V_6 * V_7 )
{
struct V_1 * V_2 ;
V_2 = F_55 ( V_7 , V_73 ) ;
if ( ! V_2 )
return NULL ;
F_61 ( & V_2 -> V_93 ) ;
return V_2 ;
}
void F_68 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_4 ( V_2 ) ;
F_69 ( ! F_6 ( V_2 ) ) ;
F_30 ( V_2 ) ;
if ( ! F_63 ( V_7 ) )
F_3 ( V_2 , V_99 , V_99 ) ;
}
void F_70 ( struct V_1 * V_2 , int V_100 )
{
F_12 ( V_2 , V_64 ,
V_100 ? V_64 : 0 ) ;
}
int F_71 ( struct V_6 * V_7 )
{
struct V_67 * V_68 = F_42 ( V_7 ) ;
struct V_1 * V_2 ;
struct V_15 * V_16 = F_15 ( V_7 ) ;
T_3 * V_101 = F_72 ( V_7 , V_101 ) ;
int V_102 = F_72 ( V_7 , V_102 ) ;
int V_86 ;
if ( V_101 [ 0 ] != V_73 ) {
F_18 ( V_16 , L_9 ) ;
return - V_61 ;
}
V_68 -> V_2 = F_73 ( sizeof( struct V_1 ) * V_102 , V_103 ) ;
if ( ! V_68 -> V_2 ) {
F_18 ( V_16 , L_10 ) ;
return - V_104 ;
}
V_68 -> V_105 = V_102 ;
F_56 (pipe, priv, i) {
V_2 -> V_7 = V_7 ;
F_2 ( V_2 ) =
V_101 [ V_86 ] & V_106 ;
F_43 ( V_16 , L_11 ,
V_86 , V_3 [ V_101 [ V_86 ] ] ) ;
}
return 0 ;
}
void F_74 ( struct V_6 * V_7 )
{
struct V_67 * V_68 = F_42 ( V_7 ) ;
F_75 ( V_68 -> V_2 ) ;
}
