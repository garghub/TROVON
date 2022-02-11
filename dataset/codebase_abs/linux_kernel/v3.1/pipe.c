void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
T_1 V_5 ;
V_5 = F_2 ( V_2 , V_6 ) ;
V_4 -> V_7 = ( V_5 >> 8 ) & 0xFF ;
V_4 -> V_8 = ( V_5 >> 0 ) & 0xFF ;
V_4 -> V_9 = F_2 ( V_2 , V_10 ) ;
V_4 -> V_11 = F_2 ( V_2 , V_12 ) ;
V_4 -> V_13 = F_2 ( V_2 , V_14 ) ;
}
void F_3 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_4 ( V_2 , V_6 , ( V_4 -> V_7 << 8 ) | V_4 -> V_8 ) ;
F_4 ( V_2 , V_10 , V_4 -> V_9 ) ;
F_4 ( V_2 , V_12 , V_4 -> V_11 ) ;
F_4 ( V_2 , V_14 , V_4 -> V_13 ) ;
}
static void F_5 ( struct V_15 * V_16 , T_1 V_17 , T_1 V_5 )
{
struct V_1 * V_2 = F_6 ( V_16 ) ;
int V_18 = F_7 ( V_16 ) ;
if ( F_8 ( V_16 ) )
F_9 ( V_2 , V_19 , V_17 , V_5 ) ;
else
F_9 ( V_2 , V_20 + V_18 , V_17 , V_5 ) ;
}
static T_1 F_10 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_6 ( V_16 ) ;
int V_18 = F_7 ( V_16 ) ;
if ( F_8 ( V_16 ) )
return F_2 ( V_2 , V_19 ) ;
else
return F_2 ( V_2 , V_20 + V_18 ) ;
}
static void F_11 ( struct V_15 * V_16 ,
T_1 V_21 , T_1 V_22 ,
T_1 V_17 , T_1 V_5 )
{
struct V_1 * V_2 = F_6 ( V_16 ) ;
if ( F_8 ( V_16 ) )
F_9 ( V_2 , V_21 , V_17 , V_5 ) ;
else
F_9 ( V_2 , V_22 , V_17 , V_5 ) ;
}
static T_1 F_12 ( struct V_15 * V_16 ,
T_1 V_21 , T_1 V_22 )
{
struct V_1 * V_2 = F_6 ( V_16 ) ;
if ( F_8 ( V_16 ) )
return F_2 ( V_2 , V_21 ) ;
else
return F_2 ( V_2 , V_22 ) ;
}
static void F_13 ( struct V_15 * V_16 , T_1 V_17 , T_1 V_5 )
{
F_11 ( V_16 , V_23 , V_24 , V_17 , V_5 ) ;
}
static void F_14 ( struct V_15 * V_16 , T_1 V_17 , T_1 V_5 )
{
if ( F_8 ( V_16 ) )
return;
F_11 ( V_16 , 0 , V_25 , V_17 , V_5 ) ;
}
static void F_15 ( struct V_15 * V_16 , T_1 V_17 , T_1 V_5 )
{
F_11 ( V_16 , V_26 , V_27 , V_17 , V_5 ) ;
}
static T_1 F_16 ( struct V_15 * V_16 )
{
return F_12 ( V_16 , V_26 , V_27 ) ;
}
static void F_17 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_6 ( V_16 ) ;
F_4 ( V_2 , V_28 , 0xF & F_18 ( V_16 ) ) ;
}
static int F_19 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_6 ( V_16 ) ;
int V_29 = 1024 ;
T_1 V_5 ;
F_4 ( V_2 , V_30 , 0 ) ;
F_20 ( V_16 ) ;
do {
V_5 = F_10 ( V_16 ) ;
V_5 &= V_31 | V_32 ;
if ( ! V_5 )
return 0 ;
F_21 ( 10 ) ;
} while ( V_29 -- );
return - V_33 ;
}
int F_22 ( struct V_15 * V_16 )
{
T_1 V_5 ;
V_5 = F_10 ( V_16 ) ;
if ( V_5 & V_34 )
return 0 ;
return - V_33 ;
}
static void F_23 ( struct V_15 * V_16 )
{
T_1 V_35 = F_10 ( V_16 ) ;
V_35 &= V_32 ;
switch ( V_35 ) {
case V_36 :
F_5 ( V_16 , V_32 , V_37 ) ;
case V_37 :
F_5 ( V_16 , V_32 , V_38 ) ;
}
}
void F_20 ( struct V_15 * V_16 )
{
int V_29 = 1024 ;
T_1 V_5 ;
F_23 ( V_16 ) ;
F_5 ( V_16 , V_32 , V_38 ) ;
do {
V_5 = F_10 ( V_16 ) ;
V_5 &= V_39 ;
if ( ! V_5 )
break;
F_21 ( 10 ) ;
} while ( V_29 -- );
}
void F_24 ( struct V_15 * V_16 )
{
F_23 ( V_16 ) ;
F_5 ( V_16 , V_32 , V_40 ) ;
}
void F_25 ( struct V_15 * V_16 )
{
T_1 V_35 = F_10 ( V_16 ) ;
V_35 &= V_32 ;
switch ( V_35 ) {
case V_38 :
F_5 ( V_16 , V_32 , V_37 ) ;
break;
case V_40 :
F_5 ( V_16 , V_32 , V_36 ) ;
break;
}
}
static int F_26 ( struct V_15 * V_16 )
{
if ( F_27 ( V_16 , V_41 ) ||
F_27 ( V_16 , V_42 ) )
return 1 ;
return 0 ;
}
static T_1 F_28 ( struct V_15 * V_16 ,
const struct V_43 * V_44 ,
int V_45 )
{
T_1 type = 0 ;
T_1 V_46 = 0 ;
T_1 V_47 = 0 ;
T_1 V_48 = 0 ;
T_1 V_49 = 0 ;
T_1 V_50 = 0 ;
T_1 V_51 = 0 ;
T_1 V_52 [] = {
[ V_41 ] = V_53 ,
[ V_54 ] = V_55 ,
[ V_42 ] = V_56 ,
} ;
int V_57 = F_26 ( V_16 ) ;
if ( F_8 ( V_16 ) )
return - V_58 ;
type = V_52 [ F_29 ( V_16 ) ] ;
if ( F_27 ( V_16 , V_42 ) ||
F_27 ( V_16 , V_41 ) )
V_46 = 0 ;
if ( F_27 ( V_16 , V_42 ) ||
F_27 ( V_16 , V_41 ) )
V_47 = ( V_57 ) ? V_59 : 0 ;
if ( F_27 ( V_16 , V_41 ) )
V_48 = 0 ;
if ( F_30 ( V_44 ) )
F_31 ( V_16 , V_60 ) ;
if ( ( V_45 && F_32 ( V_44 ) ) ||
( ! V_45 && F_30 ( V_44 ) ) )
V_49 |= V_61 ;
if ( ! V_49 )
F_31 ( V_16 , V_62 ) ;
if ( F_27 ( V_16 , V_41 ) &&
! V_49 )
V_51 = V_63 ;
V_50 = 0xF & F_33 ( V_44 ) ;
return type |
V_46 |
V_47 |
V_48 |
V_49 |
V_51 |
V_50 ;
}
static T_1 F_34 ( struct V_15 * V_16 ,
const struct V_43 * V_44 ,
int V_45 )
{
return V_64 & F_35 ( V_44 -> V_65 ) ;
}
static T_1 F_36 ( struct V_15 * V_16 ,
const struct V_43 * V_44 ,
int V_45 )
{
struct V_1 * V_2 = F_6 ( V_16 ) ;
struct V_66 * V_67 = F_37 ( V_2 ) ;
struct V_68 * V_69 = F_38 ( V_2 ) ;
int V_70 = F_18 ( V_16 ) ;
int V_57 = F_26 ( V_16 ) ;
T_1 V_71 ;
T_1 V_72 ;
T_1 V_73 ;
if ( F_27 ( V_16 , V_74 ) )
V_71 = 256 ;
else if ( F_27 ( V_16 , V_54 ) )
V_71 = 64 ;
else
V_71 = 512 ;
V_73 = ( V_71 / 64 ) - 1 ;
if ( F_27 ( V_16 , V_54 ) ) {
V_72 = V_70 - 2 ;
} else {
V_72 = V_67 -> V_75 ;
V_67 -> V_75 += V_73 + 1 ;
if ( V_57 )
V_67 -> V_75 += V_73 + 1 ;
}
F_39 ( V_69 , L_1 ,
V_70 , V_71 , V_72 ) ;
return ( 0x1f & V_73 ) << 10 |
( 0xff & V_72 ) << 0 ;
}
int F_40 ( struct V_15 * V_16 )
{
T_1 V_17 = F_8 ( V_16 ) ? V_76 : V_64 ;
F_17 ( V_16 ) ;
return ( int ) ( F_16 ( V_16 ) & V_17 ) ;
}
int F_41 ( struct V_15 * V_16 )
{
return F_42 ( V_16 , V_62 ) ;
}
int F_43 ( struct V_15 * V_16 )
{
return F_42 ( V_16 , V_60 ) ;
}
void F_44 ( struct V_15 * V_16 )
{
F_5 ( V_16 , V_77 , V_77 ) ;
}
void F_45 ( struct V_15 * V_16 )
{
F_5 ( V_16 , V_78 , V_78 ) ;
F_5 ( V_16 , V_78 , 0 ) ;
}
static struct V_15 * F_46 ( struct V_1 * V_2 , T_2 type )
{
struct V_15 * V_79 , * V_16 ;
int V_80 ;
V_16 = NULL ;
F_47 (pos, priv, i) {
if ( ! F_27 ( V_79 , type ) )
continue;
if ( F_42 ( V_79 , V_81 ) )
continue;
V_16 = V_79 ;
break;
}
if ( ! V_16 )
return NULL ;
F_48 ( V_16 ) ;
F_31 ( V_16 , V_81 ) ;
return V_16 ;
}
void F_49 ( struct V_1 * V_2 ,
void (* F_50)( struct V_82 * V_83 ) ,
int (* F_51)( struct V_82 * V_83 , int V_84 ) )
{
struct V_66 * V_67 = F_37 ( V_2 ) ;
struct V_68 * V_69 = F_38 ( V_2 ) ;
struct V_15 * V_16 ;
int V_80 ;
if ( ! F_50 ) {
F_52 ( V_69 , L_2 ) ;
return;
}
V_67 -> V_75 = 4 ;
F_47 (pipe, priv, i) {
if ( F_27 ( V_16 , V_54 ) )
V_67 -> V_75 ++ ;
F_48 ( V_16 ) ;
V_16 -> V_85 = NULL ;
V_16 -> V_86 = NULL ;
F_53 ( & V_16 -> V_87 ) ;
F_45 ( V_16 ) ;
}
V_67 -> F_50 = F_50 ;
V_67 -> F_51 = F_51 ;
}
struct V_15 * F_54 ( struct V_1 * V_2 ,
const struct V_43 * V_44 )
{
struct V_68 * V_69 = F_38 ( V_2 ) ;
struct V_88 * V_89 = F_55 ( V_2 ) ;
struct V_15 * V_16 ;
int V_45 = F_56 ( V_2 , V_89 ) ;
int V_90 ;
T_1 V_91 , V_92 , V_93 ;
V_16 = F_46 ( V_2 , F_57 ( V_44 ) ) ;
if ( ! V_16 ) {
F_52 ( V_69 , L_3 ,
V_94 [ F_57 ( V_44 ) ] ) ;
return NULL ;
}
F_53 ( & V_16 -> V_87 ) ;
F_20 ( V_16 ) ;
V_90 = F_19 ( V_16 ) ;
if ( V_90 < 0 ) {
F_52 ( V_69 , L_4 , F_18 ( V_16 ) ) ;
return NULL ;
}
V_91 = F_28 ( V_16 , V_44 , V_45 ) ;
V_92 = F_36 ( V_16 , V_44 , V_45 ) ;
V_93 = F_34 ( V_16 , V_44 , V_45 ) ;
F_17 ( V_16 ) ;
F_13 ( V_16 , 0xFFFF , V_91 ) ;
F_14 ( V_16 , 0xFFFF , V_92 ) ;
F_15 ( V_16 , 0xFFFF , V_93 ) ;
F_44 ( V_16 ) ;
F_39 ( V_69 , L_5 ,
F_18 ( V_16 ) ,
V_94 [ F_57 ( V_44 ) ] ,
F_41 ( V_16 ) ? L_6 : L_7 ) ;
return V_16 ;
}
void F_58 ( struct V_15 * V_16 , struct V_95 * V_85 )
{
if ( V_16 -> V_85 )
V_16 -> V_85 -> V_16 = NULL ;
V_16 -> V_85 = V_85 ;
if ( V_85 )
V_85 -> V_16 = V_16 ;
}
struct V_15 * F_59 ( struct V_1 * V_2 )
{
struct V_15 * V_16 ;
V_16 = F_46 ( V_2 , V_74 ) ;
if ( ! V_16 )
return NULL ;
F_17 ( V_16 ) ;
F_44 ( V_16 ) ;
F_53 ( & V_16 -> V_87 ) ;
return V_16 ;
}
void F_60 ( struct V_15 * V_16 )
{
F_61 ( ! F_8 ( V_16 ) ) ;
F_24 ( V_16 ) ;
F_5 ( V_16 , V_96 , V_96 ) ;
}
int F_62 ( struct V_1 * V_2 )
{
struct V_66 * V_67 = F_37 ( V_2 ) ;
struct V_15 * V_16 ;
struct V_68 * V_69 = F_38 ( V_2 ) ;
T_2 * V_97 = F_63 ( V_2 , V_97 ) ;
int V_98 = F_63 ( V_2 , V_98 ) ;
int V_80 ;
if ( V_97 [ 0 ] != V_74 ) {
F_52 ( V_69 , L_8 ) ;
return - V_58 ;
}
V_67 -> V_16 = F_64 ( sizeof( struct V_15 ) * V_98 , V_99 ) ;
if ( ! V_67 -> V_16 ) {
F_52 ( V_69 , L_9 ) ;
return - V_100 ;
}
V_67 -> V_101 = V_98 ;
F_47 (pipe, priv, i) {
V_16 -> V_2 = V_2 ;
F_29 ( V_16 ) = V_97 [ V_80 ] & V_102 ;
F_39 ( V_69 , L_10 ,
V_80 , V_94 [ V_97 [ V_80 ] ] ) ;
}
return 0 ;
}
void F_65 ( struct V_1 * V_2 )
{
struct V_66 * V_67 = F_37 ( V_2 ) ;
F_66 ( V_67 -> V_16 ) ;
}
