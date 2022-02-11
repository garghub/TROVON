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
T_2 V_31 ;
int V_32 ;
for ( V_32 = 0 ; V_32 < V_33 ; V_32 ++ ) {
V_31 = V_34 [ V_32 ] . V_31 ;
if ( V_31 == V_29 -> V_31 ) {
V_30 -> V_35 = & V_34 [ V_32 ] ;
return F_16 ( V_3 , V_34 [ V_32 ] . V_36 ) ;
}
}
return - V_37 ;
}
static int F_18 ( struct V_2 * V_3 ,
struct V_38 * V_39 )
{
struct V_1 * V_30 = F_1 ( V_3 ) ;
const struct V_40 * V_41 = & V_39 -> V_41 ;
int V_32 ;
if ( V_39 -> type != V_42 )
return - V_37 ;
for ( V_32 = 0 ; V_32 < V_33 ; V_32 ++ ) {
const struct V_40 * V_43 = & V_34 [ V_32 ] . V_44 . V_41 ;
if ( ! memcmp ( V_41 , V_43 , & V_41 -> V_45 - & V_41 -> V_46 ) ) {
V_30 -> V_35 = & V_34 [ V_32 ] ;
return F_16 ( V_3 , V_34 [ V_32 ] . V_36 ) ;
}
}
return - V_37 ;
}
static int F_19 ( struct V_2 * V_3 ,
struct V_38 * V_39 )
{
struct V_1 * V_30 = F_1 ( V_3 ) ;
* V_39 = V_30 -> V_35 -> V_44 ;
return 0 ;
}
static int F_20 ( struct V_4 * V_5 )
{
struct V_2 * V_3 = F_3 ( V_5 ) ;
int error = 0 ;
switch ( V_5 -> V_47 ) {
case V_48 :
F_13 ( V_3 , V_49 , V_5 -> V_17 , & error ) ;
F_13 ( V_3 , V_50 , V_5 -> V_17 , & error ) ;
F_13 ( V_3 , V_51 , V_5 -> V_17 , & error ) ;
return error ;
}
return - V_37 ;
}
static int F_21 ( struct V_2 * V_3 , struct V_52 * V_53 )
{
struct V_1 * V_30 = F_1 ( V_3 ) ;
struct V_54 V_55 ;
int error ;
error = F_22 ( V_30 -> V_35 -> V_31 , & V_55 ) ;
if ( error )
return error ;
V_53 -> V_46 = V_55 . V_46 ;
V_53 -> V_56 = V_55 . V_56 ;
V_53 -> V_57 = V_58 ;
V_53 -> V_59 = V_30 -> V_35 -> V_60 ;
V_53 -> V_61 = V_30 -> V_35 -> V_62 ;
F_23 ( 1 , V_63 , V_3 , L_4 ,
V_53 -> V_46 , V_53 -> V_56 ) ;
return 0 ;
}
static int F_24 ( struct V_2 * V_3 , int * V_64 )
{
const struct V_65 * V_66 = V_34 ;
T_1 V_67 ;
T_2 V_68 ;
T_2 V_69 ;
int error = 0 ;
T_1 V_70 ;
T_1 V_71 ;
T_1 V_72 ;
T_1 V_73 ;
* V_64 = V_33 ;
F_9 ( V_3 , V_74 , & V_70 , & error ) ;
F_9 ( V_3 , V_75 , & V_71 , & error ) ;
if ( error < 0 )
return error ;
F_9 ( V_3 , V_76 , & V_72 , & error ) ;
F_9 ( V_3 , V_77 , & V_73 , & error ) ;
if ( error < 0 )
return error ;
V_68 = V_70 | ( ( V_78 & V_71 ) << V_79 ) ;
V_69 = V_72 | ( ( V_78 & V_73 ) << V_79 ) ;
V_67 = ( V_71 & V_80 ) >> V_81 ;
for ( * V_64 = 0 ; * V_64 < V_33 ; ( * V_64 ) ++ , V_66 ++ )
if ( V_68 == V_66 -> V_82 &&
V_67 == V_66 -> V_67 ) {
if ( V_66 -> V_83 == 0xffff )
break;
if ( V_69 >= V_66 -> V_83 && V_69 <= V_66 -> V_84 )
break;
}
if ( * V_64 == V_33 ) {
F_23 ( 1 , V_63 , V_3 , L_5 ,
V_68 , V_69 ) ;
return - V_85 ;
}
F_23 ( 1 , V_63 , V_3 , L_6 , * V_64 ) ;
return 0 ;
}
static int F_25 ( struct V_2 * V_3 ,
struct V_28 * V_86 )
{
int V_64 ;
int V_15 = F_24 ( V_3 , & V_64 ) ;
if ( V_15 || V_64 == V_33 ) {
V_86 -> V_31 = V_87 ;
if ( V_15 == - V_85 )
V_15 = 0 ;
return V_15 ;
}
V_86 -> V_31 = V_34 [ V_64 ] . V_31 ;
return 0 ;
}
static int F_26 ( struct V_2 * V_3 ,
struct V_38 * V_44 )
{
int V_64 ;
int V_15 = F_24 ( V_3 , & V_64 ) ;
if ( V_15 )
return V_15 ;
* V_44 = V_34 [ V_64 ] . V_44 ;
return 0 ;
}
static int F_27 ( struct V_2 * V_3 ,
struct V_88 * V_14 )
{
struct V_10 * V_21 = F_5 ( V_3 ) ;
T_1 V_17 ;
int V_89 ;
if ( ! F_28 ( V_21 , & V_14 -> V_90 ) )
return - V_37 ;
if ( ! F_29 ( V_91 ) )
return - V_92 ;
V_89 = F_4 ( V_3 , V_14 -> V_14 & 0xff , & V_17 ) ;
V_14 -> V_17 = V_17 ;
return V_89 ;
}
static int F_30 ( struct V_2 * V_3 ,
struct V_88 * V_14 )
{
struct V_10 * V_21 = F_5 ( V_3 ) ;
if ( ! F_28 ( V_21 , & V_14 -> V_90 ) )
return - V_37 ;
if ( ! F_29 ( V_91 ) )
return - V_92 ;
return F_10 ( V_3 , V_14 -> V_14 & 0xff , V_14 -> V_17 & 0xff ) ;
}
static int F_31 ( struct V_2 * V_3 , unsigned V_64 ,
enum V_93 * V_57 )
{
if ( V_64 )
return - V_37 ;
* V_57 = V_58 ;
return 0 ;
}
static int F_32 ( struct V_2 * V_3 , int V_94 )
{
struct V_1 * V_30 = F_1 ( V_3 ) ;
int error = 0 ;
if ( V_30 -> V_95 == V_94 )
return 0 ;
if ( V_94 ) {
error = F_10 ( V_3 , V_96 , 0x00 ) ;
V_30 -> V_95 = V_94 ;
} else {
error = F_10 ( V_3 , V_96 , 0x03 ) ;
if ( error )
F_23 ( 1 , V_63 , V_3 , L_7 ) ;
V_30 -> V_95 = V_94 ;
}
return error ;
}
static int F_33 ( struct V_2 * V_3 )
{
const struct V_65 * V_66 = V_34 ;
struct V_1 * V_30 = F_1 ( V_3 ) ;
struct V_54 V_55 ;
struct V_28 V_97 ;
int V_32 ;
V_97 . V_31 = V_87 ;
F_25 ( V_3 , & V_97 ) ;
for ( V_32 = 0 ; V_32 < V_33 ; V_32 ++ , V_66 ++ )
if ( V_66 -> V_31 == V_97 . V_31 )
break;
if ( F_22 ( V_30 -> V_35 -> V_31 , & V_55 ) )
return - V_37 ;
F_34 ( V_3 , L_8 , V_55 . V_98 ) ;
F_34 ( V_3 , L_9 , V_55 . V_46 ) ;
F_34 ( V_3 , L_10 , V_55 . V_56 ) ;
if ( V_32 == V_33 ) {
F_34 ( V_3 , L_11 ) ;
} else {
if ( F_22 ( V_66 -> V_31 , & V_55 ) )
return - V_37 ;
F_34 ( V_3 , L_12 , V_55 . V_98 ) ;
F_34 ( V_3 , L_13 , V_55 . V_46 ) ;
F_34 ( V_3 , L_14 , V_55 . V_56 ) ;
}
F_34 ( V_3 , L_15 ,
V_30 -> V_95 ? L_16 : L_17 ) ;
F_35 ( & V_30 -> V_7 , V_3 -> V_98 ) ;
return 0 ;
}
static int F_36 ( struct V_2 * V_3 ,
struct V_54 * V_31 )
{
if ( V_31 -> V_64 >= V_33 )
return - V_37 ;
return F_22 ( V_34 [ V_31 -> V_64 ] . V_31 , V_31 ) ;
}
static int F_37 ( struct V_2 * V_3 ,
struct V_99 * V_44 )
{
if ( V_44 -> V_64 >= V_33 )
return - V_37 ;
V_44 -> V_44 = V_34 [ V_44 -> V_64 ] . V_44 ;
return 0 ;
}
static int F_38 ( struct V_10 * V_11 , const struct V_100 * V_47 )
{
struct V_2 * V_3 ;
struct V_1 * V_30 ;
struct V_28 V_31 ;
int V_101 ;
int V_102 ;
T_1 V_103 ;
int error ;
if ( ! F_39 ( V_11 -> V_104 ,
V_105 | V_106 ) )
return - V_107 ;
if ( ! V_11 -> V_108 . V_109 ) {
F_40 ( V_11 , L_18 ) ;
return - V_110 ;
}
V_30 = F_41 ( sizeof( struct V_1 ) , V_111 ) ;
if ( ! V_30 )
return - V_112 ;
V_3 = & V_30 -> V_3 ;
V_30 -> V_113 = V_11 -> V_108 . V_109 ;
V_30 -> V_35 = V_34 ;
F_42 ( V_3 , V_11 , & V_114 ) ;
F_43 ( V_11 , L_19 ,
V_11 -> V_8 , V_11 -> V_104 -> V_98 ) ;
error = F_4 ( V_3 , V_22 , & V_103 ) ;
if ( error < 0 )
goto V_115;
F_34 ( V_3 , L_20 , V_103 ) ;
if ( V_103 != 0x02 )
F_34 ( V_3 , L_21 ) ;
error = F_16 ( V_3 , V_116 ) ;
if ( error < 0 )
goto V_115;
V_101 = 0x20 | V_30 -> V_113 -> V_117 << 5
| V_30 -> V_113 -> V_118 << 2 ;
error = F_10 ( V_3 , V_119 , V_101 ) ;
if ( error < 0 )
goto V_115;
V_102 = 0x01 | V_30 -> V_113 -> V_120 << 2
| V_30 -> V_113 -> V_121 << 1
| V_30 -> V_113 -> V_122 ;
error = F_10 ( V_3 , V_123 , V_102 ) ;
if ( error < 0 )
goto V_115;
V_31 . V_31 = V_30 -> V_35 -> V_31 ;
error = F_17 ( V_3 , & V_31 ) ;
F_44 ( & V_30 -> V_7 , 1 ) ;
F_45 ( & V_30 -> V_7 , & V_124 ,
V_48 , 0 , 255 , 1 , 0 ) ;
V_3 -> V_125 = & V_30 -> V_7 ;
if ( V_30 -> V_7 . error ) {
int V_15 = V_30 -> V_7 . error ;
F_46 ( & V_30 -> V_7 ) ;
F_47 ( V_30 ) ;
return V_15 ;
}
F_48 ( & V_30 -> V_7 ) ;
V_115:
if ( error < 0 )
F_47 ( V_30 ) ;
return error ;
}
static int F_49 ( struct V_10 * V_11 )
{
struct V_2 * V_3 = F_50 ( V_11 ) ;
struct V_1 * V_30 = F_1 ( V_3 ) ;
F_23 ( 1 , V_63 , V_3 , L_22
L_23 , V_11 -> V_8 ) ;
F_51 ( V_3 ) ;
F_46 ( & V_30 -> V_7 ) ;
F_47 ( V_30 ) ;
return 0 ;
}
