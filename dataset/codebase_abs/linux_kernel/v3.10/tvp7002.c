static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static inline struct V_2 * F_3 ( struct V_4 * V_5 )
{
return & F_2 ( V_5 -> V_6 , struct V_1 , V_7 ) -> V_3 ;
}
static int F_4 ( struct V_2 * V_3 , T_1 V_8 , T_1 * V_9 )
{
struct V_10 * V_11 = F_5 ( V_3 ) ;
int V_12 ;
int error ;
for ( V_12 = 0 ; V_12 < V_13 ; V_12 ++ ) {
error = F_6 ( V_11 , V_8 ) ;
if ( error >= 0 ) {
* V_9 = ( T_1 ) error ;
return 0 ;
}
F_7 ( 10 ) ;
}
F_8 ( V_3 , L_1 , error ) ;
return error ;
}
static inline void F_9 ( struct V_2 * V_3 , T_1 V_14 ,
T_1 * V_9 , int * V_15 )
{
if ( ! * V_15 )
* V_15 = F_4 ( V_3 , V_14 , V_9 ) ;
}
static int F_10 ( struct V_2 * V_3 , T_1 V_8 , T_1 V_16 )
{
struct V_10 * V_11 ;
int V_12 ;
int error ;
V_11 = F_5 ( V_3 ) ;
for ( V_12 = 0 ; V_12 < V_13 ; V_12 ++ ) {
error = F_11 ( V_11 , V_8 , V_16 ) ;
if ( error >= 0 )
return 0 ;
F_12 ( V_3 , L_2 , V_12 ) ;
F_7 ( 10 ) ;
}
F_8 ( V_3 , L_3 , error ) ;
return error ;
}
static inline void F_13 ( struct V_2 * V_3 , T_1 V_14 ,
T_1 V_17 , int * V_15 )
{
if ( ! * V_15 )
* V_15 = F_10 ( V_3 , V_14 , V_17 ) ;
}
static int F_14 ( struct V_2 * V_3 ,
struct V_18 * V_19 )
{
T_1 V_20 ;
int error ;
struct V_10 * V_21 = F_5 ( V_3 ) ;
error = F_4 ( V_3 , V_22 , & V_20 ) ;
if ( error < 0 )
return error ;
return F_15 ( V_21 , V_19 , V_23 , V_20 ) ;
}
static int F_16 ( struct V_2 * V_3 ,
const struct V_24 * V_25 )
{
int error = 0 ;
while ( V_26 != V_25 -> V_14 ) {
if ( V_27 == V_25 -> type )
F_13 ( V_3 , V_25 -> V_14 , V_25 -> V_16 , & error ) ;
V_25 ++ ;
}
return error ;
}
static int F_17 ( struct V_2 * V_3 ,
struct V_28 * V_29 )
{
struct V_1 * V_30 = F_1 ( V_3 ) ;
const struct V_31 * V_32 = & V_29 -> V_32 ;
int V_33 ;
if ( V_29 -> type != V_34 )
return - V_35 ;
for ( V_33 = 0 ; V_33 < V_36 ; V_33 ++ ) {
const struct V_31 * V_37 = & V_38 [ V_33 ] . V_39 . V_32 ;
if ( ! memcmp ( V_32 , V_37 , & V_32 -> V_40 - & V_32 -> V_41 ) ) {
V_30 -> V_42 = & V_38 [ V_33 ] ;
return F_16 ( V_3 , V_38 [ V_33 ] . V_43 ) ;
}
}
return - V_35 ;
}
static int F_18 ( struct V_2 * V_3 ,
struct V_28 * V_29 )
{
struct V_1 * V_30 = F_1 ( V_3 ) ;
* V_29 = V_30 -> V_42 -> V_39 ;
return 0 ;
}
static int F_19 ( struct V_4 * V_5 )
{
struct V_2 * V_3 = F_3 ( V_5 ) ;
int error = 0 ;
switch ( V_5 -> V_44 ) {
case V_45 :
F_13 ( V_3 , V_46 , V_5 -> V_17 , & error ) ;
F_13 ( V_3 , V_47 , V_5 -> V_17 , & error ) ;
F_13 ( V_3 , V_48 , V_5 -> V_17 , & error ) ;
return error ;
}
return - V_35 ;
}
static int F_20 ( struct V_2 * V_3 , struct V_49 * V_50 )
{
struct V_1 * V_30 = F_1 ( V_3 ) ;
const struct V_31 * V_32 = & V_30 -> V_42 -> V_39 . V_32 ;
V_50 -> V_41 = V_32 -> V_41 ;
V_50 -> V_51 = V_32 -> V_51 ;
V_50 -> V_52 = V_53 ;
V_50 -> V_54 = V_30 -> V_42 -> V_55 ;
V_50 -> V_56 = V_30 -> V_42 -> V_57 ;
F_21 ( 1 , V_58 , V_3 , L_4 ,
V_50 -> V_41 , V_50 -> V_51 ) ;
return 0 ;
}
static int F_22 ( struct V_2 * V_3 , int * V_59 )
{
const struct V_60 * V_39 = V_38 ;
T_1 V_61 ;
T_2 V_62 ;
T_2 V_63 ;
int error = 0 ;
T_1 V_64 ;
T_1 V_65 ;
T_1 V_66 ;
T_1 V_67 ;
* V_59 = V_36 ;
F_9 ( V_3 , V_68 , & V_64 , & error ) ;
F_9 ( V_3 , V_69 , & V_65 , & error ) ;
if ( error < 0 )
return error ;
F_9 ( V_3 , V_70 , & V_66 , & error ) ;
F_9 ( V_3 , V_71 , & V_67 , & error ) ;
if ( error < 0 )
return error ;
V_62 = V_64 | ( ( V_72 & V_65 ) << V_73 ) ;
V_63 = V_66 | ( ( V_72 & V_67 ) << V_73 ) ;
V_61 = ( V_65 & V_74 ) >> V_75 ;
for ( * V_59 = 0 ; * V_59 < V_36 ; ( * V_59 ) ++ , V_39 ++ )
if ( V_62 == V_39 -> V_76 &&
V_61 == V_39 -> V_61 ) {
if ( V_39 -> V_77 == 0xffff )
break;
if ( V_63 >= V_39 -> V_77 && V_63 <= V_39 -> V_78 )
break;
}
if ( * V_59 == V_36 ) {
F_21 ( 1 , V_58 , V_3 , L_5 ,
V_62 , V_63 ) ;
return - V_79 ;
}
F_21 ( 1 , V_58 , V_3 , L_6 , * V_59 ) ;
return 0 ;
}
static int F_23 ( struct V_2 * V_3 ,
struct V_28 * V_39 )
{
int V_59 ;
int V_15 = F_22 ( V_3 , & V_59 ) ;
if ( V_15 )
return V_15 ;
* V_39 = V_38 [ V_59 ] . V_39 ;
return 0 ;
}
static int F_24 ( struct V_2 * V_3 ,
struct V_80 * V_14 )
{
struct V_10 * V_21 = F_5 ( V_3 ) ;
T_1 V_17 ;
int V_81 ;
if ( ! F_25 ( V_21 , & V_14 -> V_82 ) )
return - V_35 ;
if ( ! F_26 ( V_83 ) )
return - V_84 ;
V_81 = F_4 ( V_3 , V_14 -> V_14 & 0xff , & V_17 ) ;
V_14 -> V_17 = V_17 ;
return V_81 ;
}
static int F_27 ( struct V_2 * V_3 ,
const struct V_80 * V_14 )
{
struct V_10 * V_21 = F_5 ( V_3 ) ;
if ( ! F_25 ( V_21 , & V_14 -> V_82 ) )
return - V_35 ;
if ( ! F_26 ( V_83 ) )
return - V_84 ;
return F_10 ( V_3 , V_14 -> V_14 & 0xff , V_14 -> V_17 & 0xff ) ;
}
static int F_28 ( struct V_2 * V_3 , unsigned V_59 ,
enum V_85 * V_52 )
{
if ( V_59 )
return - V_35 ;
* V_52 = V_53 ;
return 0 ;
}
static int F_29 ( struct V_2 * V_3 , int V_86 )
{
struct V_1 * V_30 = F_1 ( V_3 ) ;
int error = 0 ;
if ( V_30 -> V_87 == V_86 )
return 0 ;
if ( V_86 ) {
error = F_10 ( V_3 , V_88 , 0x00 ) ;
V_30 -> V_87 = V_86 ;
} else {
error = F_10 ( V_3 , V_88 , 0x03 ) ;
if ( error )
F_21 ( 1 , V_58 , V_3 , L_7 ) ;
V_30 -> V_87 = V_86 ;
}
return error ;
}
static int F_30 ( struct V_2 * V_3 )
{
struct V_1 * V_30 = F_1 ( V_3 ) ;
const struct V_31 * V_32 ;
int V_89 ;
F_22 ( V_3 , & V_89 ) ;
V_32 = & V_30 -> V_42 -> V_39 . V_32 ;
F_31 ( V_3 , L_8 , V_32 -> V_41 , V_32 -> V_51 ) ;
if ( V_89 == V_36 ) {
F_31 ( V_3 , L_9 ) ;
} else {
V_32 = & V_38 [ V_89 ] . V_39 . V_32 ;
F_31 ( V_3 , L_10 ,
V_32 -> V_41 , V_32 -> V_51 ) ;
}
F_31 ( V_3 , L_11 ,
V_30 -> V_87 ? L_12 : L_13 ) ;
F_32 ( & V_30 -> V_7 , V_3 -> V_90 ) ;
return 0 ;
}
static int F_33 ( struct V_2 * V_3 ,
struct V_91 * V_39 )
{
if ( V_39 -> V_59 >= V_36 )
return - V_35 ;
V_39 -> V_39 = V_38 [ V_39 -> V_59 ] . V_39 ;
return 0 ;
}
static int F_34 ( struct V_10 * V_11 , const struct V_92 * V_44 )
{
struct V_2 * V_3 ;
struct V_1 * V_30 ;
struct V_28 V_39 ;
int V_93 ;
int V_94 ;
T_1 V_95 ;
int error ;
if ( ! F_35 ( V_11 -> V_96 ,
V_97 | V_98 ) )
return - V_99 ;
if ( ! V_11 -> V_100 . V_101 ) {
F_36 ( V_11 , L_14 ) ;
return - V_102 ;
}
V_30 = F_37 ( & V_11 -> V_100 , sizeof( struct V_1 ) , V_103 ) ;
if ( ! V_30 )
return - V_104 ;
V_3 = & V_30 -> V_3 ;
V_30 -> V_105 = V_11 -> V_100 . V_101 ;
V_30 -> V_42 = V_38 ;
F_38 ( V_3 , V_11 , & V_106 ) ;
F_39 ( V_11 , L_15 ,
V_11 -> V_8 , V_11 -> V_96 -> V_90 ) ;
error = F_4 ( V_3 , V_22 , & V_95 ) ;
if ( error < 0 )
return error ;
F_31 ( V_3 , L_16 , V_95 ) ;
if ( V_95 != 0x02 )
F_31 ( V_3 , L_17 ) ;
error = F_16 ( V_3 , V_107 ) ;
if ( error < 0 )
return error ;
V_93 = 0x20 | V_30 -> V_105 -> V_108 << 5
| V_30 -> V_105 -> V_109 << 2 ;
error = F_10 ( V_3 , V_110 , V_93 ) ;
if ( error < 0 )
return error ;
V_94 = 0x01 | V_30 -> V_105 -> V_111 << 2
| V_30 -> V_105 -> V_112 << 1
| V_30 -> V_105 -> V_113 ;
error = F_10 ( V_3 , V_114 , V_94 ) ;
if ( error < 0 )
return error ;
V_39 = V_30 -> V_42 -> V_39 ;
error = F_17 ( V_3 , & V_39 ) ;
F_40 ( & V_30 -> V_7 , 1 ) ;
F_41 ( & V_30 -> V_7 , & V_115 ,
V_45 , 0 , 255 , 1 , 0 ) ;
V_3 -> V_116 = & V_30 -> V_7 ;
if ( V_30 -> V_7 . error ) {
int V_15 = V_30 -> V_7 . error ;
F_42 ( & V_30 -> V_7 ) ;
return V_15 ;
}
F_43 ( & V_30 -> V_7 ) ;
return 0 ;
}
static int F_44 ( struct V_10 * V_11 )
{
struct V_2 * V_3 = F_45 ( V_11 ) ;
struct V_1 * V_30 = F_1 ( V_3 ) ;
F_21 ( 1 , V_58 , V_3 , L_18
L_19 , V_11 -> V_8 ) ;
F_46 ( V_3 ) ;
F_42 ( & V_30 -> V_7 ) ;
return 0 ;
}
