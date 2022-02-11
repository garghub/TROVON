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
static int F_22 ( struct V_15 * V_16 )
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
void F_26 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_6 ( V_16 ) ;
F_9 ( V_2 , V_41 , V_42 , V_42 ) ;
}
static void F_27 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_6 ( V_16 ) ;
F_4 ( V_2 , V_41 , V_43 ) ;
}
static int F_28 ( struct V_1 * V_2 )
{
int V_29 = 1024 ;
do {
if ( F_2 ( V_2 , V_41 ) & V_44 )
return 0 ;
F_21 ( 10 ) ;
} while ( V_29 -- );
return - V_33 ;
}
static int F_29 ( struct V_1 * V_2 )
{
return F_2 ( V_2 , V_41 ) & V_45 ;
}
static int F_30 ( struct V_15 * V_16 , int V_46 )
{
struct V_1 * V_2 = F_6 ( V_16 ) ;
struct V_47 * V_48 = F_31 ( V_2 ) ;
int V_29 = 1024 ;
T_1 V_17 = ( ( 1 << 5 ) | 0xF ) ;
T_1 V_49 = F_18 ( V_16 ) ;
if ( F_8 ( V_16 ) )
V_49 |= ( 1 == V_46 ) << 5 ;
F_4 ( V_2 , V_30 , V_49 | V_50 ) ;
while ( V_29 -- ) {
if ( V_49 == ( V_17 & F_2 ( V_2 , V_30 ) ) )
return 0 ;
F_21 ( 10 ) ;
}
F_32 ( V_48 , L_1 ) ;
return - V_51 ;
}
int F_33 ( struct V_15 * V_16 )
{
return F_30 ( V_16 , 1 ) ;
}
int F_34 ( struct V_15 * V_16 , T_2 * V_52 , int V_53 )
{
struct V_1 * V_2 = F_6 ( V_16 ) ;
void T_3 * V_54 = V_2 -> V_49 + V_55 ;
int V_56 = F_35 ( V_16 ) ;
int V_57 ;
int V_58 , V_59 ;
V_59 = F_22 ( V_16 ) ;
if ( V_59 < 0 )
return V_59 ;
V_59 = F_30 ( V_16 , 1 ) ;
if ( V_59 < 0 )
return V_59 ;
V_59 = F_28 ( V_2 ) ;
if ( V_59 < 0 )
return V_59 ;
V_53 = F_36 ( V_53 , V_56 ) ;
V_57 = V_53 ;
if ( V_53 >= 4 &&
! ( ( unsigned long ) V_52 & 0x03 ) ) {
F_37 ( V_54 , V_52 , V_53 / 4 ) ;
V_53 %= 4 ;
V_52 += V_57 - V_53 ;
}
for ( V_58 = 0 ; V_58 < V_53 ; V_58 ++ )
F_38 ( V_52 [ V_58 ] , V_54 + ( 0x03 - ( V_58 & 0x03 ) ) ) ;
if ( V_57 < V_56 )
F_26 ( V_16 ) ;
return V_57 ;
}
int F_39 ( struct V_15 * V_16 )
{
int V_59 ;
V_59 = F_30 ( V_16 , 0 ) ;
if ( V_59 < 0 )
return V_59 ;
F_24 ( V_16 ) ;
return V_59 ;
}
int F_40 ( struct V_15 * V_16 , T_2 * V_52 , int V_53 )
{
struct V_1 * V_2 = F_6 ( V_16 ) ;
void T_3 * V_54 = V_2 -> V_49 + V_55 ;
int V_60 ;
int V_58 , V_59 ;
int V_57 ;
T_4 V_61 = 0 ;
V_59 = F_30 ( V_16 , 0 ) ;
if ( V_59 < 0 )
return V_59 ;
V_59 = F_28 ( V_2 ) ;
if ( V_59 < 0 )
return V_59 ;
V_60 = F_29 ( V_2 ) ;
if ( 0 == V_60 ) {
F_27 ( V_16 ) ;
return 0 ;
}
V_53 = F_36 ( V_60 , V_53 ) ;
V_57 = V_53 ;
if ( V_53 >= 4 &&
! ( ( unsigned long ) V_52 & 0x03 ) ) {
F_41 ( V_54 , V_52 , V_53 / 4 ) ;
V_53 %= 4 ;
V_52 += V_60 - V_53 ;
}
for ( V_58 = 0 ; V_58 < V_53 ; V_58 ++ ) {
if ( ! ( V_58 & 0x03 ) )
V_61 = F_42 ( V_54 ) ;
V_52 [ V_58 ] = ( V_61 >> ( ( V_58 & 0x03 ) * 8 ) ) & 0xff ;
}
return V_57 ;
}
static int F_43 ( struct V_15 * V_16 )
{
if ( F_44 ( V_16 , V_62 ) ||
F_44 ( V_16 , V_63 ) )
return 1 ;
return 0 ;
}
static T_1 F_45 ( struct V_15 * V_16 ,
const struct V_64 * V_65 ,
int V_66 )
{
T_1 type = 0 ;
T_1 V_67 = 0 ;
T_1 V_68 = 0 ;
T_1 V_69 = 0 ;
T_1 V_70 = 0 ;
T_1 V_71 = 0 ;
T_1 V_72 = 0 ;
T_1 V_73 [] = {
[ V_62 ] = V_74 ,
[ V_75 ] = V_76 ,
[ V_63 ] = V_77 ,
} ;
int V_78 = F_43 ( V_16 ) ;
if ( F_8 ( V_16 ) )
return - V_79 ;
type = V_73 [ F_46 ( V_16 ) ] ;
if ( F_44 ( V_16 , V_63 ) ||
F_44 ( V_16 , V_62 ) )
V_67 = 0 ;
if ( F_44 ( V_16 , V_63 ) ||
F_44 ( V_16 , V_62 ) )
V_68 = ( V_78 ) ? V_80 : 0 ;
if ( F_44 ( V_16 , V_62 ) )
V_69 = 0 ;
if ( F_47 ( V_65 ) )
F_48 ( V_16 , V_81 ) ;
if ( ( V_66 && F_49 ( V_65 ) ) ||
( ! V_66 && F_47 ( V_65 ) ) )
V_70 |= V_82 ;
if ( F_44 ( V_16 , V_62 ) &&
! V_70 )
V_72 = V_83 ;
V_71 = 0xF & F_50 ( V_65 ) ;
return type |
V_67 |
V_68 |
V_69 |
V_70 |
V_72 |
V_71 ;
}
static T_1 F_51 ( struct V_15 * V_16 ,
const struct V_64 * V_65 ,
int V_66 )
{
return V_84 & F_52 ( V_65 -> V_85 ) ;
}
static T_1 F_53 ( struct V_15 * V_16 ,
const struct V_64 * V_65 ,
int V_66 )
{
struct V_1 * V_2 = F_6 ( V_16 ) ;
struct V_86 * V_87 = F_54 ( V_2 ) ;
struct V_47 * V_48 = F_31 ( V_2 ) ;
int V_88 = F_18 ( V_16 ) ;
int V_78 = F_43 ( V_16 ) ;
T_1 V_89 ;
T_1 V_90 ;
T_1 V_91 ;
if ( F_44 ( V_16 , V_92 ) )
V_89 = 256 ;
else if ( F_44 ( V_16 , V_75 ) )
V_89 = 64 ;
else
V_89 = 512 ;
V_91 = ( V_89 / 64 ) - 1 ;
if ( F_44 ( V_16 , V_75 ) ) {
V_90 = V_88 - 2 ;
} else {
V_90 = V_87 -> V_93 ;
V_87 -> V_93 += V_91 + 1 ;
if ( V_78 )
V_87 -> V_93 += V_91 + 1 ;
}
F_55 ( V_48 , L_2 ,
V_88 , V_89 , V_90 ) ;
return ( 0x1f & V_91 ) << 10 |
( 0xff & V_90 ) << 0 ;
}
int F_35 ( struct V_15 * V_16 )
{
T_1 V_17 = F_8 ( V_16 ) ? V_94 : V_84 ;
F_17 ( V_16 ) ;
return ( int ) ( F_16 ( V_16 ) & V_17 ) ;
}
int F_56 ( struct V_15 * V_16 )
{
return F_57 ( V_16 , V_81 ) ;
}
void F_58 ( struct V_15 * V_16 )
{
F_5 ( V_16 , V_95 , V_95 ) ;
}
static struct V_15 * F_59 ( struct V_1 * V_2 , T_4 type )
{
struct V_15 * V_96 , * V_16 ;
int V_58 ;
V_16 = NULL ;
F_60 (pos, priv, i) {
if ( ! F_44 ( V_96 , type ) )
continue;
if ( F_57 ( V_96 , V_97 ) )
continue;
V_16 = V_96 ;
break;
}
if ( ! V_16 )
return NULL ;
F_61 ( V_16 ) ;
F_48 ( V_16 , V_97 ) ;
return V_16 ;
}
void F_62 ( struct V_1 * V_2 )
{
struct V_86 * V_87 = F_54 ( V_2 ) ;
struct V_15 * V_16 ;
int V_58 ;
V_87 -> V_93 = 4 ;
F_60 (pipe, priv, i) {
if ( F_44 ( V_16 , V_75 ) )
V_87 -> V_93 ++ ;
F_61 ( V_16 ) ;
V_16 -> V_98 = NULL ;
F_27 ( V_16 ) ;
}
}
struct V_15 * F_63 ( struct V_1 * V_2 ,
const struct V_64 * V_65 )
{
struct V_47 * V_48 = F_31 ( V_2 ) ;
struct V_99 * V_100 = F_64 ( V_2 ) ;
struct V_15 * V_16 ;
int V_66 = F_65 ( V_2 , V_100 ) ;
int V_59 ;
T_1 V_101 , V_102 , V_103 ;
V_16 = F_59 ( V_2 , F_66 ( V_65 ) ) ;
if ( ! V_16 ) {
F_32 ( V_48 , L_3 ,
V_104 [ F_66 ( V_65 ) ] ) ;
return NULL ;
}
F_20 ( V_16 ) ;
V_59 = F_19 ( V_16 ) ;
if ( V_59 < 0 ) {
F_32 ( V_48 , L_4 , F_18 ( V_16 ) ) ;
return NULL ;
}
V_101 = F_45 ( V_16 , V_65 , V_66 ) ;
V_102 = F_53 ( V_16 , V_65 , V_66 ) ;
V_103 = F_51 ( V_16 , V_65 , V_66 ) ;
F_5 ( V_16 , V_105 , V_105 ) ;
F_5 ( V_16 , V_105 , 0 ) ;
F_17 ( V_16 ) ;
F_13 ( V_16 , 0xFFFF , V_101 ) ;
F_14 ( V_16 , 0xFFFF , V_102 ) ;
F_15 ( V_16 , 0xFFFF , V_103 ) ;
F_58 ( V_16 ) ;
F_55 ( V_48 , L_5 ,
F_18 ( V_16 ) ,
V_104 [ F_66 ( V_65 ) ] ,
F_56 ( V_16 ) ? L_6 : L_7 ) ;
return V_16 ;
}
struct V_15 * F_67 ( struct V_1 * V_2 )
{
struct V_15 * V_16 ;
V_16 = F_59 ( V_2 , V_92 ) ;
if ( ! V_16 )
return NULL ;
F_17 ( V_16 ) ;
F_58 ( V_16 ) ;
return V_16 ;
}
void F_68 ( struct V_15 * V_16 )
{
F_69 ( ! F_8 ( V_16 ) ) ;
F_24 ( V_16 ) ;
F_5 ( V_16 , V_106 , V_106 ) ;
}
int F_70 ( struct V_1 * V_2 )
{
struct V_86 * V_87 = F_54 ( V_2 ) ;
struct V_15 * V_16 ;
struct V_47 * V_48 = F_31 ( V_2 ) ;
T_4 * V_107 = F_71 ( V_2 , V_107 ) ;
int V_108 = F_71 ( V_2 , V_108 ) ;
int V_58 ;
if ( V_107 [ 0 ] != V_92 ) {
F_32 ( V_48 , L_8 ) ;
return - V_79 ;
}
V_87 -> V_16 = F_72 ( sizeof( struct V_15 ) * V_108 , V_109 ) ;
if ( ! V_87 -> V_16 ) {
F_32 ( V_48 , L_9 ) ;
return - V_110 ;
}
V_87 -> V_111 = V_108 ;
F_60 (pipe, priv, i) {
V_16 -> V_2 = V_2 ;
F_46 ( V_16 ) = V_107 [ V_58 ] & V_112 ;
F_55 ( V_48 , L_10 ,
V_58 , V_104 [ V_107 [ V_58 ] ] ) ;
}
return 0 ;
}
void F_73 ( struct V_1 * V_2 )
{
struct V_86 * V_87 = F_54 ( V_2 ) ;
F_74 ( V_87 -> V_16 ) ;
}
