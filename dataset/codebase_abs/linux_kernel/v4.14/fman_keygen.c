static int F_1 ( struct V_1 T_1 * V_2 , T_2 V_3 )
{
F_2 ( V_3 , & V_2 -> V_3 ) ;
while ( V_3 & V_4 )
V_3 = F_3 ( & V_2 -> V_3 ) ;
if ( V_3 & V_5 )
return - V_6 ;
return 0 ;
}
static T_2 F_4 ( T_3 V_7 , bool V_8 , bool V_9 )
{
T_2 V_10 = ( T_2 ) ( V_9 ? V_11 : V_12 ) ;
return ( T_2 ) ( V_4 |
V_10 |
V_13 |
V_14 |
( ( T_2 ) V_7 << V_15 ) |
( V_8 ? V_16 : 0 ) ) ;
}
static T_2 F_5 ( T_3 V_17 , bool V_9 )
{
T_2 V_10 = V_9 ? ( T_2 ) V_11 : ( T_2 ) V_12 ;
return ( T_2 ) ( V_4 |
V_10 |
V_18 |
V_17 |
V_19 ) ;
}
static void F_6 ( struct V_1 T_1 * V_2 , T_2 V_20 , bool V_21 )
{
T_2 V_22 ;
V_22 = F_3 ( & V_2 -> V_23 . V_24 ) ;
if ( V_21 )
V_22 |= V_20 ;
else
V_22 &= ~ V_20 ;
F_2 ( V_22 , & V_2 -> V_23 . V_24 ) ;
}
static T_2 F_7 ( T_3 V_17 , bool V_9 )
{
T_2 V_10 = V_9 ? ( T_2 ) V_11 : ( T_2 ) V_12 ;
return ( T_2 ) ( V_4 |
V_10 |
V_18 |
V_17 |
V_25 ) ;
}
static void F_8 ( struct V_1 T_1 * V_2 , T_2 V_26 )
{
F_2 ( V_26 , & V_2 -> V_23 . V_27 ) ;
}
static int F_9 ( struct V_1 T_1 * V_2 , T_3 V_7 ,
struct V_28 * V_29 ,
bool V_8 )
{
T_2 V_30 ;
int V_31 , V_32 ;
F_2 ( V_29 -> V_33 , & V_2 -> V_34 . V_33 ) ;
F_2 ( V_29 -> V_35 , & V_2 -> V_34 . V_35 ) ;
F_2 ( V_29 -> V_36 , & V_2 -> V_34 . V_36 ) ;
F_2 ( V_29 -> V_37 , & V_2 -> V_34 . V_37 ) ;
F_2 ( V_29 -> V_38 , & V_2 -> V_34 . V_38 ) ;
F_2 ( V_29 -> V_39 , & V_2 -> V_34 . V_39 ) ;
F_2 ( V_29 -> V_40 , & V_2 -> V_34 . V_40 ) ;
F_2 ( V_29 -> V_41 , & V_2 -> V_34 . V_41 ) ;
F_2 ( V_29 -> V_42 , & V_2 -> V_34 . V_42 ) ;
F_2 ( V_29 -> V_43 , & V_2 -> V_34 . V_43 ) ;
F_2 ( V_29 -> V_44 , & V_2 -> V_34 . V_44 ) ;
F_2 ( V_29 -> V_45 , & V_2 -> V_34 . V_45 ) ;
F_2 ( V_29 -> V_46 , & V_2 -> V_34 . V_46 ) ;
F_2 ( V_29 -> V_47 , & V_2 -> V_34 . V_47 ) ;
F_2 ( V_29 -> V_48 , & V_2 -> V_34 . V_48 ) ;
for ( V_32 = 0 ; V_32 < V_49 ; V_32 ++ )
F_2 ( V_29 -> V_50 [ V_32 ] ,
& V_2 -> V_34 . V_50 [ V_32 ] ) ;
V_30 = F_4 ( V_7 , V_8 , true ) ;
V_31 = F_1 ( V_2 , V_30 ) ;
if ( V_31 != 0 ) {
F_10 ( L_1 ) ;
return V_31 ;
}
return V_31 ;
}
static int F_11 ( struct V_51 * V_52 , T_3 * V_7 )
{
T_3 V_32 ;
for ( V_32 = 0 ; V_32 < V_53 ; V_32 ++ )
if ( ! V_52 -> V_54 [ V_32 ] . V_55 ) {
* V_7 = V_32 ;
return 0 ;
}
return - V_6 ;
}
static struct V_56 * F_12 ( struct V_51 * V_52 ,
T_3 V_7 )
{
if ( V_7 >= V_53 )
return NULL ;
return & V_52 -> V_54 [ V_7 ] ;
}
static int F_13 ( struct V_51 * V_52 ,
T_3 V_7 ,
bool V_57 )
{
struct V_1 T_1 * V_58 = V_52 -> V_58 ;
struct V_56 * V_59 ;
T_2 V_30 ;
T_2 V_60 = 0 ;
int V_31 ;
V_59 = F_12 ( V_52 , V_7 ) ;
if ( ! V_59 ) {
F_10 ( L_2 ) ;
return - V_6 ;
}
if ( ! V_59 -> V_55 ) {
F_10 ( L_3 ) ;
return - V_6 ;
}
V_60 |= 1 << ( 31 - V_7 ) ;
V_30 = F_5 ( V_59 -> V_61 , false ) ;
V_31 = F_1 ( V_58 , V_30 ) ;
if ( V_31 != 0 ) {
F_10 ( L_4 ) ;
return V_31 ;
}
F_6 ( V_58 , V_60 , V_57 ) ;
V_30 = F_5 ( V_59 -> V_61 , true ) ;
V_31 = F_1 ( V_58 , V_30 ) ;
if ( V_31 != 0 ) {
F_10 ( L_1 ) ;
return V_31 ;
}
return 0 ;
}
static int F_14 ( struct V_51 * V_52 , T_3 V_7 ,
bool V_62 )
{
struct V_1 T_1 * V_58 = V_52 -> V_58 ;
struct V_28 V_29 ;
struct V_56 * V_59 ;
T_2 V_63 ;
int V_31 ;
V_59 = F_12 ( V_52 , V_7 ) ;
if ( ! V_59 ) {
F_10 ( L_2 ) ;
return - V_6 ;
}
if ( V_62 && V_59 -> V_55 ) {
F_10 ( L_5 ) ;
return - V_6 ;
}
memset ( & V_29 , 0 , sizeof( struct V_28 ) ) ;
V_63 = 0 ;
if ( V_62 ) {
V_63 |= V_64 ;
V_63 |= V_65 ;
}
V_29 . V_33 = V_63 ;
V_29 . V_46 = V_59 -> V_66 ;
V_29 . V_48 = V_67 ;
if ( V_59 -> V_68 ) {
V_29 . V_35 = V_69 ;
V_63 = 0 ;
V_63 |= ( V_70 <<
V_71 ) ;
V_63 |= ( V_72 <<
V_73 ) ;
V_29 . V_36 = V_63 ;
V_29 . V_43 = V_74 ;
V_29 . V_44 = V_75 ;
V_63 = 0 ;
V_63 |= ( ( V_59 -> V_76 - 1 ) <<
V_77 ) ;
V_63 |= V_59 -> V_78 << V_79 ;
if ( V_59 -> V_80 ) {
V_63 |= V_81 ;
}
V_29 . V_40 = V_63 ;
} else {
V_29 . V_35 = 0 ;
V_29 . V_40 = 0 ;
V_29 . V_36 = 0 ;
V_29 . V_43 = 0 ;
V_29 . V_44 = 0 ;
}
V_63 = 0 ;
V_63 |= V_59 -> V_82 ;
V_29 . V_39 = V_63 ;
V_29 . V_37 = 0 ;
V_29 . V_38 = 0 ;
V_29 . V_42 = 0 ;
V_31 = F_9 ( V_58 , V_7 , & V_29 , true ) ;
if ( V_31 != 0 ) {
F_10 ( L_6 ) ;
return V_31 ;
}
V_59 -> V_55 = V_62 ;
return 0 ;
}
struct V_51 * F_15 ( struct V_1 T_1 * V_58 )
{
struct V_51 * V_52 ;
T_2 V_83 ;
int V_32 ;
V_52 = F_16 ( sizeof( * V_52 ) , V_84 ) ;
if ( ! V_52 )
return NULL ;
V_52 -> V_58 = V_58 ;
F_2 ( V_65 , & V_58 -> V_85 ) ;
F_2 ( V_86 | V_87 ,
& V_58 -> V_88 ) ;
F_2 ( 0 , & V_58 -> V_89 ) ;
F_2 ( 0 , & V_58 -> V_90 ) ;
F_2 ( 0 , & V_58 -> V_91 ) ;
for ( V_32 = 0 ; V_32 < V_92 ; V_32 ++ ) {
F_6 ( V_58 , 0xffffffff , false ) ;
V_83 = F_5 ( V_32 , true ) ;
F_1 ( V_58 , V_83 ) ;
F_8 ( V_58 , 0 ) ;
V_83 = F_7 ( V_32 , true ) ;
F_1 ( V_58 , V_83 ) ;
}
F_2 ( 0xFFFFFFFF , & V_58 -> V_93 ) ;
F_2 ( 0xFFFFFFFF , & V_58 -> V_94 ) ;
F_2 ( F_3 ( & V_58 -> V_85 ) | V_95 ,
& V_58 -> V_85 ) ;
return V_52 ;
}
int F_17 ( struct V_51 * V_52 , T_3 V_61 ,
T_2 V_96 , T_2 V_97 )
{
struct V_56 * V_59 ;
T_3 V_7 ;
int V_31 ;
if ( V_96 == 0 || ( V_96 & ~ 0x00FFFFFF ) ) {
F_10 ( L_7 ) ;
return - V_6 ;
}
if ( V_97 == 0 || ( V_97 & ( V_97 - 1 ) ) != 0 ) {
F_10 ( L_8 ) ;
return - V_6 ;
}
V_31 = F_11 ( V_52 , & V_7 ) ;
if ( V_31 ) {
F_10 ( L_9 ) ;
return - V_6 ;
}
V_59 = F_12 ( V_52 , V_7 ) ;
if ( ! V_59 ) {
F_10 ( L_2 ) ;
return - V_6 ;
}
if ( V_59 -> V_55 ) {
F_10 ( L_5 ) ;
return - V_6 ;
}
memset ( V_59 , 0 , sizeof( struct V_56 ) ) ;
V_59 -> V_61 = V_61 ;
V_59 -> V_68 = true ;
V_59 -> V_82 = V_96 ;
V_59 -> V_76 = V_97 ;
V_59 -> V_80 = V_98 ;
V_59 -> V_78 = V_99 ;
V_59 -> V_66 = 0 ;
V_31 = F_14 ( V_52 , V_7 , true ) ;
if ( V_31 != 0 ) {
F_10 ( L_10 ) ;
return V_31 ;
}
V_31 = F_13 ( V_52 , V_7 , true ) ;
if ( V_31 != 0 ) {
F_10 ( L_11 ) ;
return V_31 ;
}
return 0 ;
}
