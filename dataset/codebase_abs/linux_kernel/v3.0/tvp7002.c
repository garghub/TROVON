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
static int F_18 ( struct V_4 * V_5 )
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
return - V_37 ;
}
static int F_19 ( struct V_2 * V_3 , struct V_43 * V_44 )
{
struct V_1 * V_30 = F_1 ( V_3 ) ;
struct V_45 V_46 ;
int error ;
error = F_20 ( V_30 -> V_35 -> V_31 , & V_46 ) ;
if ( error )
return error ;
V_44 -> V_47 = V_46 . V_47 ;
V_44 -> V_48 = V_46 . V_48 ;
V_44 -> V_49 = V_50 ;
V_44 -> V_51 = V_30 -> V_35 -> V_52 ;
V_44 -> V_53 = V_30 -> V_35 -> V_54 ;
F_21 ( 1 , V_55 , V_3 , L_4 ,
V_44 -> V_47 , V_44 -> V_48 ) ;
return 0 ;
}
static int F_22 ( struct V_2 * V_3 ,
struct V_28 * V_56 )
{
const struct V_57 * V_58 = V_34 ;
struct V_1 * V_30 ;
T_1 V_59 ;
T_2 V_60 ;
T_2 V_61 ;
int error = 0 ;
T_1 V_62 ;
T_1 V_63 ;
T_1 V_64 ;
T_1 V_65 ;
int V_66 ;
V_30 = F_1 ( V_3 ) ;
F_9 ( V_3 , V_67 , & V_62 , & error ) ;
F_9 ( V_3 , V_68 , & V_63 , & error ) ;
if ( error < 0 )
return error ;
F_9 ( V_3 , V_69 , & V_64 , & error ) ;
F_9 ( V_3 , V_70 , & V_65 , & error ) ;
if ( error < 0 )
return error ;
V_60 = V_62 | ( ( V_71 & V_63 ) << V_72 ) ;
V_61 = V_64 | ( ( V_71 & V_65 ) << V_72 ) ;
V_59 = ( V_63 & V_73 ) >> V_74 ;
for ( V_66 = 0 ; V_66 < V_33 ; V_66 ++ , V_58 ++ )
if ( V_60 == V_58 -> V_75 &&
V_59 == V_58 -> V_59 ) {
if ( V_58 -> V_76 == 0xffff )
break;
if ( V_61 >= V_58 -> V_76 && V_61 <= V_58 -> V_77 )
break;
}
if ( V_66 == V_33 ) {
F_21 ( 1 , V_55 , V_3 , L_5 ,
V_60 , V_61 ) ;
V_56 -> V_31 = V_78 ;
return 0 ;
}
V_56 -> V_31 = V_58 -> V_31 ;
F_21 ( 1 , V_55 , V_3 , L_6 , V_58 -> V_31 ) ;
return 0 ;
}
static int F_23 ( struct V_2 * V_3 ,
struct V_79 * V_14 )
{
struct V_10 * V_21 = F_5 ( V_3 ) ;
T_1 V_17 ;
int V_80 ;
if ( ! F_24 ( V_21 , & V_14 -> V_81 ) )
return - V_37 ;
if ( ! F_25 ( V_82 ) )
return - V_83 ;
V_80 = F_4 ( V_3 , V_14 -> V_14 & 0xff , & V_17 ) ;
V_14 -> V_17 = V_17 ;
return V_80 ;
}
static int F_26 ( struct V_2 * V_3 ,
struct V_79 * V_14 )
{
struct V_10 * V_21 = F_5 ( V_3 ) ;
if ( ! F_24 ( V_21 , & V_14 -> V_81 ) )
return - V_37 ;
if ( ! F_25 ( V_82 ) )
return - V_83 ;
return F_10 ( V_3 , V_14 -> V_14 & 0xff , V_14 -> V_17 & 0xff ) ;
}
static int F_27 ( struct V_2 * V_3 , unsigned V_66 ,
enum V_84 * V_49 )
{
if ( V_66 )
return - V_37 ;
* V_49 = V_50 ;
return 0 ;
}
static int F_28 ( struct V_2 * V_3 , int V_85 )
{
struct V_1 * V_30 = F_1 ( V_3 ) ;
int error = 0 ;
if ( V_30 -> V_86 == V_85 )
return 0 ;
if ( V_85 ) {
error = F_10 ( V_3 , V_87 , 0x00 ) ;
V_30 -> V_86 = V_85 ;
} else {
error = F_10 ( V_3 , V_87 , 0x03 ) ;
if ( error )
F_21 ( 1 , V_55 , V_3 , L_7 ) ;
V_30 -> V_86 = V_85 ;
}
return error ;
}
static int F_29 ( struct V_2 * V_3 )
{
const struct V_57 * V_58 = V_34 ;
struct V_1 * V_30 = F_1 ( V_3 ) ;
struct V_45 V_46 ;
struct V_28 V_88 ;
int V_32 ;
V_88 . V_31 = V_78 ;
F_22 ( V_3 , & V_88 ) ;
for ( V_32 = 0 ; V_32 < V_33 ; V_32 ++ , V_58 ++ )
if ( V_58 -> V_31 == V_88 . V_31 )
break;
if ( F_20 ( V_30 -> V_35 -> V_31 , & V_46 ) )
return - V_37 ;
F_30 ( V_3 , L_8 , V_46 . V_89 ) ;
F_30 ( V_3 , L_9 , V_46 . V_47 ) ;
F_30 ( V_3 , L_10 , V_46 . V_48 ) ;
if ( V_32 == V_33 ) {
F_30 ( V_3 , L_11 ) ;
} else {
if ( F_20 ( V_58 -> V_31 , & V_46 ) )
return - V_37 ;
F_30 ( V_3 , L_12 , V_46 . V_89 ) ;
F_30 ( V_3 , L_13 , V_46 . V_47 ) ;
F_30 ( V_3 , L_14 , V_46 . V_48 ) ;
}
F_30 ( V_3 , L_15 ,
V_30 -> V_86 ? L_16 : L_17 ) ;
F_31 ( & V_30 -> V_7 , V_3 -> V_89 ) ;
return 0 ;
}
static int F_32 ( struct V_2 * V_3 ,
struct V_45 * V_31 )
{
if ( V_31 -> V_66 >= V_33 )
return - V_37 ;
return F_20 ( V_34 [ V_31 -> V_66 ] . V_31 , V_31 ) ;
}
static int F_33 ( struct V_10 * V_11 , const struct V_90 * V_38 )
{
struct V_2 * V_3 ;
struct V_1 * V_30 ;
struct V_28 V_31 ;
int V_91 ;
int V_92 ;
T_1 V_93 ;
int error ;
if ( ! F_34 ( V_11 -> V_94 ,
V_95 | V_96 ) )
return - V_97 ;
if ( ! V_11 -> V_98 . V_99 ) {
F_35 ( V_11 , L_18 ) ;
return - V_100 ;
}
V_30 = F_36 ( sizeof( struct V_1 ) , V_101 ) ;
if ( ! V_30 )
return - V_102 ;
V_3 = & V_30 -> V_3 ;
V_30 -> V_103 = V_11 -> V_98 . V_99 ;
V_30 -> V_35 = V_34 ;
F_37 ( V_3 , V_11 , & V_104 ) ;
F_38 ( V_11 , L_19 ,
V_11 -> V_8 , V_11 -> V_94 -> V_89 ) ;
error = F_4 ( V_3 , V_22 , & V_93 ) ;
if ( error < 0 )
goto V_105;
F_30 ( V_3 , L_20 , V_93 ) ;
if ( V_93 != 0x02 )
F_30 ( V_3 , L_21 ) ;
error = F_16 ( V_3 , V_106 ) ;
if ( error < 0 )
goto V_105;
V_91 = 0x20 | V_30 -> V_103 -> V_107 << 5
| V_30 -> V_103 -> V_108 << 2 ;
error = F_10 ( V_3 , V_109 , V_91 ) ;
if ( error < 0 )
goto V_105;
V_92 = 0x01 | V_30 -> V_103 -> V_110 << 2
| V_30 -> V_103 -> V_111 << 1
| V_30 -> V_103 -> V_112 ;
error = F_10 ( V_3 , V_113 , V_92 ) ;
if ( error < 0 )
goto V_105;
V_31 . V_31 = V_30 -> V_35 -> V_31 ;
error = F_17 ( V_3 , & V_31 ) ;
F_39 ( & V_30 -> V_7 , 1 ) ;
F_40 ( & V_30 -> V_7 , & V_114 ,
V_39 , 0 , 255 , 1 , 0 ) ;
V_3 -> V_115 = & V_30 -> V_7 ;
if ( V_30 -> V_7 . error ) {
int V_15 = V_30 -> V_7 . error ;
F_41 ( & V_30 -> V_7 ) ;
F_42 ( V_30 ) ;
return V_15 ;
}
F_43 ( & V_30 -> V_7 ) ;
V_105:
if ( error < 0 )
F_42 ( V_30 ) ;
return error ;
}
static int F_44 ( struct V_10 * V_11 )
{
struct V_2 * V_3 = F_45 ( V_11 ) ;
struct V_1 * V_30 = F_1 ( V_3 ) ;
F_21 ( 1 , V_55 , V_3 , L_22
L_23 , V_11 -> V_8 ) ;
F_46 ( V_3 ) ;
F_41 ( & V_30 -> V_7 ) ;
F_42 ( V_30 ) ;
return 0 ;
}
static int T_3 F_47 ( void )
{
return F_48 ( & V_116 ) ;
}
static void T_4 F_49 ( void )
{
F_50 ( & V_116 ) ;
}
