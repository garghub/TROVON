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
const struct V_18 * V_19 )
{
int error = 0 ;
while ( V_20 != V_19 -> V_14 ) {
if ( V_21 == V_19 -> type )
F_13 ( V_3 , V_19 -> V_14 , V_19 -> V_16 , & error ) ;
V_19 ++ ;
}
return error ;
}
static int F_15 ( struct V_2 * V_3 ,
struct V_22 * V_23 )
{
struct V_1 * V_24 = F_1 ( V_3 ) ;
const struct V_25 * V_26 = & V_23 -> V_26 ;
int V_27 ;
if ( V_23 -> type != V_28 )
return - V_29 ;
for ( V_27 = 0 ; V_27 < V_30 ; V_27 ++ ) {
const struct V_25 * V_31 = & V_32 [ V_27 ] . V_33 . V_26 ;
if ( ! memcmp ( V_26 , V_31 , & V_26 -> V_34 - & V_26 -> V_35 ) ) {
V_24 -> V_36 = & V_32 [ V_27 ] ;
return F_14 ( V_3 , V_32 [ V_27 ] . V_37 ) ;
}
}
return - V_29 ;
}
static int F_16 ( struct V_2 * V_3 ,
struct V_22 * V_23 )
{
struct V_1 * V_24 = F_1 ( V_3 ) ;
* V_23 = V_24 -> V_36 -> V_33 ;
return 0 ;
}
static int F_17 ( struct V_4 * V_5 )
{
struct V_2 * V_3 = F_3 ( V_5 ) ;
int error = 0 ;
switch ( V_5 -> V_38 ) {
case V_39 :
F_13 ( V_3 , V_40 , V_5 -> V_17 , & error ) ;
F_13 ( V_3 , V_41 , V_5 -> V_17 , & error ) ;
F_13 ( V_3 , V_42 , V_5 -> V_17 , & error ) ;
return error ;
}
return - V_29 ;
}
static int F_18 ( struct V_2 * V_3 , struct V_43 * V_44 )
{
struct V_1 * V_24 = F_1 ( V_3 ) ;
const struct V_25 * V_26 = & V_24 -> V_36 -> V_33 . V_26 ;
V_44 -> V_35 = V_26 -> V_35 ;
V_44 -> V_45 = V_26 -> V_45 ;
V_44 -> V_46 = V_47 ;
V_44 -> V_48 = V_24 -> V_36 -> V_49 ;
V_44 -> V_50 = V_24 -> V_36 -> V_51 ;
F_19 ( 1 , V_52 , V_3 , L_4 ,
V_44 -> V_35 , V_44 -> V_45 ) ;
return 0 ;
}
static int F_20 ( struct V_2 * V_3 , int * V_53 )
{
const struct V_54 * V_33 = V_32 ;
T_1 V_55 ;
T_2 V_56 ;
T_2 V_57 ;
int error = 0 ;
T_1 V_58 ;
T_1 V_59 ;
T_1 V_60 ;
T_1 V_61 ;
* V_53 = V_30 ;
F_9 ( V_3 , V_62 , & V_58 , & error ) ;
F_9 ( V_3 , V_63 , & V_59 , & error ) ;
if ( error < 0 )
return error ;
F_9 ( V_3 , V_64 , & V_60 , & error ) ;
F_9 ( V_3 , V_65 , & V_61 , & error ) ;
if ( error < 0 )
return error ;
V_56 = V_58 | ( ( V_66 & V_59 ) << V_67 ) ;
V_57 = V_60 | ( ( V_66 & V_61 ) << V_67 ) ;
V_55 = ( V_59 & V_68 ) >> V_69 ;
for ( * V_53 = 0 ; * V_53 < V_30 ; ( * V_53 ) ++ , V_33 ++ )
if ( V_56 == V_33 -> V_70 &&
V_55 == V_33 -> V_55 ) {
if ( V_33 -> V_71 == 0xffff )
break;
if ( V_57 >= V_33 -> V_71 && V_57 <= V_33 -> V_72 )
break;
}
if ( * V_53 == V_30 ) {
F_19 ( 1 , V_52 , V_3 , L_5 ,
V_56 , V_57 ) ;
return - V_73 ;
}
F_19 ( 1 , V_52 , V_3 , L_6 , * V_53 ) ;
return 0 ;
}
static int F_21 ( struct V_2 * V_3 ,
struct V_22 * V_33 )
{
int V_53 ;
int V_15 = F_20 ( V_3 , & V_53 ) ;
if ( V_15 )
return V_15 ;
* V_33 = V_32 [ V_53 ] . V_33 ;
return 0 ;
}
static int F_22 ( struct V_2 * V_3 ,
struct V_74 * V_14 )
{
T_1 V_17 ;
int V_75 ;
V_75 = F_4 ( V_3 , V_14 -> V_14 & 0xff , & V_17 ) ;
V_14 -> V_17 = V_17 ;
V_14 -> V_76 = 1 ;
return V_75 ;
}
static int F_23 ( struct V_2 * V_3 ,
const struct V_74 * V_14 )
{
return F_10 ( V_3 , V_14 -> V_14 & 0xff , V_14 -> V_17 & 0xff ) ;
}
static int F_24 ( struct V_2 * V_3 , unsigned V_53 ,
enum V_77 * V_46 )
{
if ( V_53 )
return - V_29 ;
* V_46 = V_47 ;
return 0 ;
}
static int F_25 ( struct V_2 * V_3 , int V_78 )
{
struct V_1 * V_24 = F_1 ( V_3 ) ;
int error = 0 ;
if ( V_24 -> V_79 == V_78 )
return 0 ;
if ( V_78 ) {
error = F_10 ( V_3 , V_80 , 0x00 ) ;
V_24 -> V_79 = V_78 ;
} else {
error = F_10 ( V_3 , V_80 , 0x03 ) ;
if ( error )
F_19 ( 1 , V_52 , V_3 , L_7 ) ;
V_24 -> V_79 = V_78 ;
}
return error ;
}
static int F_26 ( struct V_2 * V_3 )
{
struct V_1 * V_24 = F_1 ( V_3 ) ;
const struct V_25 * V_26 ;
int V_81 ;
F_20 ( V_3 , & V_81 ) ;
V_26 = & V_24 -> V_36 -> V_33 . V_26 ;
F_27 ( V_3 , L_8 , V_26 -> V_35 , V_26 -> V_45 ) ;
if ( V_81 == V_30 ) {
F_27 ( V_3 , L_9 ) ;
} else {
V_26 = & V_32 [ V_81 ] . V_33 . V_26 ;
F_27 ( V_3 , L_10 ,
V_26 -> V_35 , V_26 -> V_45 ) ;
}
F_27 ( V_3 , L_11 ,
V_24 -> V_79 ? L_12 : L_13 ) ;
F_28 ( & V_24 -> V_7 , V_3 -> V_82 ) ;
return 0 ;
}
static int F_29 ( struct V_2 * V_3 ,
struct V_83 * V_33 )
{
if ( V_33 -> V_53 >= V_30 )
return - V_29 ;
V_33 -> V_33 = V_32 [ V_33 -> V_53 ] . V_33 ;
return 0 ;
}
static int
F_30 ( struct V_2 * V_3 , struct V_84 * V_85 ,
struct V_86 * V_46 )
{
if ( V_46 -> V_53 != 0 )
return - V_29 ;
V_46 -> V_46 = V_47 ;
return 0 ;
}
static int
F_31 ( struct V_2 * V_3 , struct V_84 * V_85 ,
struct V_87 * V_88 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
V_88 -> V_89 . V_46 = V_47 ;
V_88 -> V_89 . V_35 = V_1 -> V_36 -> V_33 . V_26 . V_35 ;
V_88 -> V_89 . V_45 = V_1 -> V_36 -> V_33 . V_26 . V_45 ;
V_88 -> V_89 . V_48 = V_1 -> V_36 -> V_49 ;
V_88 -> V_89 . V_50 = V_1 -> V_36 -> V_51 ;
return 0 ;
}
static int
F_32 ( struct V_2 * V_3 , struct V_84 * V_85 ,
struct V_87 * V_88 )
{
return F_31 ( V_3 , V_85 , V_88 ) ;
}
static int F_33 ( struct V_10 * V_11 , const struct V_90 * V_38 )
{
struct V_2 * V_3 ;
struct V_1 * V_24 ;
struct V_22 V_33 ;
int V_91 ;
int V_92 ;
T_1 V_93 ;
int error ;
if ( ! F_34 ( V_11 -> V_94 ,
V_95 | V_96 ) )
return - V_97 ;
if ( ! V_11 -> V_98 . V_99 ) {
F_35 ( V_11 , L_14 ) ;
return - V_100 ;
}
V_24 = F_36 ( & V_11 -> V_98 , sizeof( struct V_1 ) , V_101 ) ;
if ( ! V_24 )
return - V_102 ;
V_3 = & V_24 -> V_3 ;
V_24 -> V_103 = V_11 -> V_98 . V_99 ;
V_24 -> V_36 = V_32 ;
F_37 ( V_3 , V_11 , & V_104 ) ;
F_38 ( V_11 , L_15 ,
V_11 -> V_8 , V_11 -> V_94 -> V_82 ) ;
error = F_4 ( V_3 , V_105 , & V_93 ) ;
if ( error < 0 )
return error ;
F_27 ( V_3 , L_16 , V_93 ) ;
if ( V_93 != 0x02 )
F_27 ( V_3 , L_17 ) ;
error = F_14 ( V_3 , V_106 ) ;
if ( error < 0 )
return error ;
V_91 = 0x20 | V_24 -> V_103 -> V_107 << 5
| V_24 -> V_103 -> V_108 << 2 ;
error = F_10 ( V_3 , V_109 , V_91 ) ;
if ( error < 0 )
return error ;
V_92 = 0x01 | V_24 -> V_103 -> V_110 << 2
| V_24 -> V_103 -> V_111 << 1
| V_24 -> V_103 -> V_112 ;
error = F_10 ( V_3 , V_113 , V_92 ) ;
if ( error < 0 )
return error ;
V_33 = V_24 -> V_36 -> V_33 ;
error = F_15 ( V_3 , & V_33 ) ;
#if F_39 ( V_114 )
V_24 -> V_115 . V_116 = V_117 ;
V_24 -> V_3 . V_116 |= V_118 ;
V_24 -> V_3 . V_119 . V_116 |= V_120 ;
error = F_40 ( & V_24 -> V_3 . V_119 , 1 , & V_24 -> V_115 , 0 ) ;
if ( error < 0 )
return error ;
#endif
F_41 ( & V_24 -> V_7 , 1 ) ;
F_42 ( & V_24 -> V_7 , & V_121 ,
V_39 , 0 , 255 , 1 , 0 ) ;
V_3 -> V_122 = & V_24 -> V_7 ;
if ( V_24 -> V_7 . error ) {
error = V_24 -> V_7 . error ;
goto error;
}
F_43 ( & V_24 -> V_7 ) ;
return 0 ;
error:
F_44 ( & V_24 -> V_7 ) ;
#if F_39 ( V_114 )
F_45 ( & V_24 -> V_3 . V_119 ) ;
#endif
return error ;
}
static int F_46 ( struct V_10 * V_11 )
{
struct V_2 * V_3 = F_47 ( V_11 ) ;
struct V_1 * V_24 = F_1 ( V_3 ) ;
F_19 ( 1 , V_52 , V_3 , L_18
L_19 , V_11 -> V_8 ) ;
#if F_39 ( V_114 )
F_45 ( & V_24 -> V_3 . V_119 ) ;
#endif
F_48 ( V_3 ) ;
F_44 ( & V_24 -> V_7 ) ;
return 0 ;
}
