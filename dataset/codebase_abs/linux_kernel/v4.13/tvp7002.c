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
static int F_18 ( struct V_2 * V_3 , int * V_43 )
{
const struct V_44 * V_33 = V_32 ;
T_1 V_45 ;
T_2 V_46 ;
T_2 V_47 ;
int error = 0 ;
T_1 V_48 ;
T_1 V_49 ;
T_1 V_50 ;
T_1 V_51 ;
* V_43 = V_30 ;
F_9 ( V_3 , V_52 , & V_48 , & error ) ;
F_9 ( V_3 , V_53 , & V_49 , & error ) ;
if ( error < 0 )
return error ;
F_9 ( V_3 , V_54 , & V_50 , & error ) ;
F_9 ( V_3 , V_55 , & V_51 , & error ) ;
if ( error < 0 )
return error ;
V_46 = V_48 | ( ( V_56 & V_49 ) << V_57 ) ;
V_47 = V_50 | ( ( V_56 & V_51 ) << V_57 ) ;
V_45 = ( V_49 & V_58 ) >> V_59 ;
for ( * V_43 = 0 ; * V_43 < V_30 ; ( * V_43 ) ++ , V_33 ++ )
if ( V_46 == V_33 -> V_60 &&
V_45 == V_33 -> V_45 ) {
if ( V_33 -> V_61 == 0xffff )
break;
if ( V_47 >= V_33 -> V_61 && V_47 <= V_33 -> V_62 )
break;
}
if ( * V_43 == V_30 ) {
F_19 ( 1 , V_63 , V_3 , L_4 ,
V_46 , V_47 ) ;
return - V_64 ;
}
F_19 ( 1 , V_63 , V_3 , L_5 , * V_43 ) ;
return 0 ;
}
static int F_20 ( struct V_2 * V_3 ,
struct V_22 * V_33 )
{
int V_43 ;
int V_15 = F_18 ( V_3 , & V_43 ) ;
if ( V_15 )
return V_15 ;
* V_33 = V_32 [ V_43 ] . V_33 ;
return 0 ;
}
static int F_21 ( struct V_2 * V_3 ,
struct V_65 * V_14 )
{
T_1 V_17 ;
int V_66 ;
V_66 = F_4 ( V_3 , V_14 -> V_14 & 0xff , & V_17 ) ;
V_14 -> V_17 = V_17 ;
V_14 -> V_67 = 1 ;
return V_66 ;
}
static int F_22 ( struct V_2 * V_3 ,
const struct V_65 * V_14 )
{
return F_10 ( V_3 , V_14 -> V_14 & 0xff , V_14 -> V_17 & 0xff ) ;
}
static int F_23 ( struct V_2 * V_3 , int V_68 )
{
struct V_1 * V_24 = F_1 ( V_3 ) ;
int error ;
if ( V_24 -> V_69 == V_68 )
return 0 ;
error = F_10 ( V_3 , V_70 , V_68 ? 0x00 : 0x03 ) ;
if ( error ) {
F_19 ( 1 , V_63 , V_3 , L_6 ) ;
return error ;
}
V_24 -> V_69 = V_68 ;
return 0 ;
}
static int F_24 ( struct V_2 * V_3 )
{
struct V_1 * V_24 = F_1 ( V_3 ) ;
const struct V_25 * V_26 ;
int V_71 ;
F_18 ( V_3 , & V_71 ) ;
V_26 = & V_24 -> V_36 -> V_33 . V_26 ;
F_25 ( V_3 , L_7 , V_26 -> V_35 , V_26 -> V_72 ) ;
if ( V_71 == V_30 ) {
F_25 ( V_3 , L_8 ) ;
} else {
V_26 = & V_32 [ V_71 ] . V_33 . V_26 ;
F_25 ( V_3 , L_9 ,
V_26 -> V_35 , V_26 -> V_72 ) ;
}
F_25 ( V_3 , L_10 ,
V_24 -> V_69 ? L_11 : L_12 ) ;
F_26 ( & V_24 -> V_7 , V_3 -> V_73 ) ;
return 0 ;
}
static int F_27 ( struct V_2 * V_3 ,
struct V_74 * V_33 )
{
if ( V_33 -> V_75 != 0 )
return - V_29 ;
if ( V_33 -> V_43 >= V_30 )
return - V_29 ;
V_33 -> V_33 = V_32 [ V_33 -> V_43 ] . V_33 ;
return 0 ;
}
static int
F_28 ( struct V_2 * V_3 , struct V_76 * V_77 ,
struct V_78 * V_79 )
{
if ( V_79 -> V_43 != 0 )
return - V_29 ;
V_79 -> V_79 = V_80 ;
return 0 ;
}
static int
F_29 ( struct V_2 * V_3 , struct V_76 * V_77 ,
struct V_81 * V_82 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
V_82 -> V_83 . V_79 = V_80 ;
V_82 -> V_83 . V_35 = V_1 -> V_36 -> V_33 . V_26 . V_35 ;
V_82 -> V_83 . V_72 = V_1 -> V_36 -> V_33 . V_26 . V_72 ;
V_82 -> V_83 . V_84 = V_1 -> V_36 -> V_85 ;
V_82 -> V_83 . V_86 = V_1 -> V_36 -> V_87 ;
return 0 ;
}
static int
F_30 ( struct V_2 * V_3 , struct V_76 * V_77 ,
struct V_81 * V_82 )
{
return F_29 ( V_3 , V_77 , V_82 ) ;
}
static struct V_88 *
F_31 ( struct V_10 * V_89 )
{
struct V_90 V_91 ;
struct V_88 * V_92 = NULL ;
struct V_93 * V_94 ;
unsigned int V_95 ;
if ( ! F_32 ( V_96 ) || ! V_89 -> V_97 . V_98 )
return V_89 -> V_97 . V_99 ;
V_94 = F_33 ( V_89 -> V_97 . V_98 , NULL ) ;
if ( ! V_94 )
return NULL ;
if ( F_34 ( F_35 ( V_94 ) , & V_91 ) )
goto V_100;
V_92 = F_36 ( & V_89 -> V_97 , sizeof( * V_92 ) , V_101 ) ;
if ( ! V_92 )
goto V_100;
V_95 = V_91 . V_102 . V_103 . V_95 ;
if ( V_95 & V_104 )
V_92 -> V_105 = 1 ;
if ( V_95 & V_106 )
V_92 -> V_107 = 1 ;
if ( V_95 & V_108 )
V_92 -> V_109 = 1 ;
if ( V_95 & V_110 )
V_92 -> V_111 = 1 ;
if ( V_95 & V_112 )
V_92 -> V_113 = 1 ;
V_100:
F_37 ( V_94 ) ;
return V_92 ;
}
static int F_38 ( struct V_10 * V_11 , const struct V_114 * V_38 )
{
struct V_88 * V_92 = F_31 ( V_11 ) ;
struct V_2 * V_3 ;
struct V_1 * V_24 ;
struct V_22 V_33 ;
int V_115 ;
int V_116 ;
T_1 V_117 ;
int error ;
if ( V_92 == NULL ) {
F_39 ( & V_11 -> V_97 , L_13 ) ;
return - V_29 ;
}
if ( ! F_40 ( V_11 -> V_118 ,
V_119 | V_120 ) )
return - V_121 ;
V_24 = F_36 ( & V_11 -> V_97 , sizeof( struct V_1 ) , V_101 ) ;
if ( ! V_24 )
return - V_122 ;
V_3 = & V_24 -> V_3 ;
V_24 -> V_92 = V_92 ;
V_24 -> V_36 = V_32 ;
F_41 ( V_3 , V_11 , & V_123 ) ;
F_42 ( V_11 , L_14 ,
V_11 -> V_8 , V_11 -> V_118 -> V_73 ) ;
error = F_4 ( V_3 , V_124 , & V_117 ) ;
if ( error < 0 )
return error ;
F_25 ( V_3 , L_15 , V_117 ) ;
if ( V_117 != 0x02 )
F_25 ( V_3 , L_16 ) ;
error = F_14 ( V_3 , V_125 ) ;
if ( error < 0 )
return error ;
V_115 = 0x20 | V_24 -> V_92 -> V_105 << 5
| V_24 -> V_92 -> V_107 << 2 ;
error = F_10 ( V_3 , V_126 , V_115 ) ;
if ( error < 0 )
return error ;
V_116 = 0x01 | V_24 -> V_92 -> V_111 << 2
| V_24 -> V_92 -> V_113 << 1
| V_24 -> V_92 -> V_109 ;
error = F_10 ( V_3 , V_127 , V_116 ) ;
if ( error < 0 )
return error ;
V_33 = V_24 -> V_36 -> V_33 ;
error = F_15 ( V_3 , & V_33 ) ;
#if F_43 ( V_128 )
V_24 -> V_75 . V_95 = V_129 ;
V_24 -> V_3 . V_95 |= V_130 ;
V_24 -> V_3 . V_131 . V_95 |= V_132 ;
error = F_44 ( & V_24 -> V_3 . V_131 , 1 , & V_24 -> V_75 ) ;
if ( error < 0 )
return error ;
#endif
F_45 ( & V_24 -> V_7 , 1 ) ;
F_46 ( & V_24 -> V_7 , & V_133 ,
V_39 , 0 , 255 , 1 , 0 ) ;
V_3 -> V_134 = & V_24 -> V_7 ;
if ( V_24 -> V_7 . error ) {
error = V_24 -> V_7 . error ;
goto error;
}
F_47 ( & V_24 -> V_7 ) ;
error = F_48 ( & V_24 -> V_3 ) ;
if ( error )
goto error;
return 0 ;
error:
F_49 ( & V_24 -> V_7 ) ;
#if F_43 ( V_128 )
F_50 ( & V_24 -> V_3 . V_131 ) ;
#endif
return error ;
}
static int F_51 ( struct V_10 * V_11 )
{
struct V_2 * V_3 = F_52 ( V_11 ) ;
struct V_1 * V_24 = F_1 ( V_3 ) ;
F_19 ( 1 , V_63 , V_3 , L_17
L_18 , V_11 -> V_8 ) ;
F_53 ( & V_24 -> V_3 ) ;
#if F_43 ( V_128 )
F_50 ( & V_24 -> V_3 . V_131 ) ;
#endif
F_49 ( & V_24 -> V_7 ) ;
return 0 ;
}
