static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_4 -> V_5 )
F_3 ( V_4 -> V_5 ) ;
F_4 ( V_2 ) ;
F_5 ( V_2 ) ;
}
void F_6 ( struct V_6 * V_7 )
{
unsigned int V_8 ;
struct V_9 * V_10 ;
if ( ! V_7 -> V_11 || ! V_7 -> V_12 ) {
F_7 ( L_1 ) ;
return;
}
for ( V_8 = 0 ; V_8 < V_7 -> V_13 ; ++ V_8 ) {
if ( V_7 -> V_11 [ V_8 ] . V_10 )
continue;
V_10 = ( void * ) V_7 -> V_12 + V_8 * V_14 ;
if ( ! F_8 ( & V_7 -> V_11 [ V_8 ] ,
V_7 -> V_15 , V_10 , V_8 ) ) {
F_7 ( L_2 ) ;
return;
}
}
}
void F_9 ( struct V_6 * V_7 )
{
unsigned int V_8 ;
for ( V_8 = 0 ; V_8 < V_7 -> V_13 ; ++ V_8 )
F_10 ( & V_7 -> V_11 [ V_8 ] , V_7 -> V_15 , V_8 ) ;
}
void F_11 ( struct V_6 * V_7 )
{
T_1 V_16 = V_17 |
V_18 | V_19 ;
if ( V_7 -> V_20 )
V_16 |= V_21 ;
F_12 ( V_7 -> V_15 , V_16 ) ;
}
void F_13 ( struct V_1 * V_2 ,
struct V_22 * V_23 ,
unsigned int V_24 )
{
struct V_6 * V_7 = V_2 -> V_25 -> V_26 ;
struct V_27 * V_28 ;
unsigned int V_8 ;
F_14 ( & V_7 -> V_29 ) ;
F_15 (crtc, &fb->dev->mode_config.crtc_list, head) {
if ( F_16 ( V_28 ) != V_2 )
continue;
F_6 ( V_7 ) ;
for ( V_8 = 0 ; V_8 < V_24 ; ++ V_8 ) {
struct V_30 V_31 ;
unsigned int V_32 = F_17 ( V_28 ) -> V_32 ;
if ( ( V_23 [ V_8 ] . V_33 > V_28 -> V_34 + V_28 -> V_35 . V_36 ) ||
( V_23 [ V_8 ] . y1 > V_28 -> V_37 + V_28 -> V_35 . V_38 ) ||
( V_23 [ V_8 ] . V_39 < V_28 -> V_34 ) ||
( V_23 [ V_8 ] . V_40 < V_28 -> V_37 ) )
continue;
V_31 . V_34 = ( V_41 ) V_23 [ V_8 ] . V_33 ;
V_31 . V_37 = ( V_41 ) V_23 [ V_8 ] . y1 ;
V_31 . V_42 = ( V_43 ) V_23 [ V_8 ] . V_39 - V_23 [ V_8 ] . V_33 ;
V_31 . V_44 = ( V_43 ) V_23 [ V_8 ] . V_40 - V_23 [ V_8 ] . y1 ;
if ( ! F_18 ( & V_7 -> V_11 [ V_32 ] ,
V_7 -> V_15 ) )
continue;
F_19 ( & V_7 -> V_11 [ V_32 ] , V_7 -> V_15 ,
& V_31 , sizeof( V_31 ) ) ;
F_20 ( & V_7 -> V_11 [ V_32 ] ) ;
}
}
F_21 ( & V_7 -> V_29 ) ;
}
static int F_22 ( struct V_1 * V_2 ,
struct V_45 * V_46 ,
unsigned int V_47 , unsigned int V_48 ,
struct V_22 * V_23 ,
unsigned int V_24 )
{
F_13 ( V_2 , V_23 , V_24 ) ;
return 0 ;
}
int F_23 ( struct V_49 * V_25 ,
struct V_3 * V_4 ,
const struct V_50 * V_51 ,
struct V_52 * V_5 )
{
int V_53 ;
F_24 ( V_25 , & V_4 -> V_54 , V_51 ) ;
V_4 -> V_5 = V_5 ;
V_53 = F_25 ( V_25 , & V_4 -> V_54 , & V_55 ) ;
if ( V_53 ) {
F_7 ( L_3 , V_53 ) ;
return V_53 ;
}
return 0 ;
}
static struct V_1 * F_26 (
struct V_49 * V_25 ,
struct V_45 * V_56 ,
const struct V_57 * V_51 )
{
struct V_52 * V_5 ;
struct V_3 * V_4 ;
int V_53 = - V_58 ;
V_5 = F_27 ( V_56 , V_51 -> V_59 [ 0 ] ) ;
if ( ! V_5 )
return F_28 ( - V_60 ) ;
V_4 = F_29 ( sizeof( * V_4 ) , V_61 ) ;
if ( ! V_4 )
goto V_62;
V_53 = F_23 ( V_25 , V_4 , V_51 , V_5 ) ;
if ( V_53 )
goto V_63;
return & V_4 -> V_54 ;
V_63:
F_5 ( V_4 ) ;
V_62:
F_3 ( V_5 ) ;
return F_28 ( V_53 ) ;
}
static int F_30 ( struct V_6 * V_7 )
{
unsigned int V_8 ;
V_7 -> V_11 = F_31 ( V_7 -> V_25 -> V_25 , V_7 -> V_13 ,
sizeof( * V_7 -> V_11 ) , V_61 ) ;
if ( ! V_7 -> V_11 )
return - V_58 ;
V_7 -> V_64 -= V_7 -> V_13 * V_14 ;
V_7 -> V_12 = F_32 ( V_7 -> V_25 -> V_65 , 0 ,
V_7 -> V_64 ,
V_7 -> V_13 *
V_14 ) ;
if ( ! V_7 -> V_12 )
return - V_58 ;
for ( V_8 = 0 ; V_8 < V_7 -> V_13 ; ++ V_8 )
F_33 ( & V_7 -> V_11 [ V_8 ] ,
V_7 -> V_64 +
V_8 * V_14 ,
V_14 ) ;
return 0 ;
}
static void F_34 ( struct V_6 * V_7 )
{
F_9 ( V_7 ) ;
F_35 ( V_7 -> V_25 -> V_65 , V_7 -> V_12 ) ;
}
static bool F_36 ( struct V_6 * V_7 )
{
T_1 V_66 , V_67 ;
int V_53 ;
V_53 = F_37 ( V_7 -> V_15 ,
V_68 ,
& V_66 ) ;
if ( V_53 )
return false ;
V_53 = F_37 ( V_7 -> V_15 ,
V_69 ,
& V_67 ) ;
if ( V_53 )
return false ;
return V_66 == V_70 && V_67 == V_70 ;
}
static bool F_38 ( V_43 V_71 )
{
V_43 V_72 ;
F_39 ( V_73 , V_71 ) ;
V_72 = F_40 ( V_74 ) ;
return V_72 == V_71 ;
}
static int F_41 ( struct V_6 * V_7 )
{
int V_53 = - V_58 ;
V_7 -> V_75 = F_42 ( V_74 ) ;
V_7 -> V_76 = F_38 ( V_77 ) ;
F_43 ( L_4 , V_7 -> V_75 ) ;
V_7 -> V_78 =
F_32 ( V_7 -> V_25 -> V_65 , 0 , F_44 ( V_7 ) ,
V_79 ) ;
if ( ! V_7 -> V_78 )
return - V_58 ;
V_7 -> V_15 = F_45 ( 4 , - 1 ) ;
if ( ! V_7 -> V_15 )
goto V_80;
V_53 = F_46 ( V_7 -> V_15 ,
( unsigned long ) V_7 -> V_78 ,
F_44 ( V_7 ) ,
V_81 , - 1 ) ;
if ( V_53 )
goto V_82;
V_53 = F_47 ( V_7 -> V_15 ) ;
if ( V_53 ) {
F_7 ( L_5 ) ;
goto V_82;
}
V_7 -> V_64 = F_44 ( V_7 ) ;
F_37 ( V_7 -> V_15 , V_83 ,
& V_7 -> V_13 ) ;
V_7 -> V_13 = F_48 ( T_1 , V_7 -> V_13 , 1 , V_84 ) ;
if ( ! F_36 ( V_7 ) ) {
V_53 = - V_85 ;
goto V_82;
}
V_7 -> V_86 = F_31 ( V_7 -> V_25 -> V_25 , V_7 -> V_13 ,
sizeof( struct V_87 ) ,
V_61 ) ;
if ( ! V_7 -> V_86 ) {
V_53 = - V_58 ;
goto V_82;
}
V_53 = F_30 ( V_7 ) ;
if ( V_53 )
goto V_82;
return 0 ;
V_82:
F_49 ( V_7 -> V_15 ) ;
V_80:
F_35 ( V_7 -> V_25 -> V_65 , V_7 -> V_78 ) ;
return V_53 ;
}
static void F_50 ( struct V_6 * V_7 )
{
F_34 ( V_7 ) ;
F_49 ( V_7 -> V_15 ) ;
F_35 ( V_7 -> V_25 -> V_65 , V_7 -> V_78 ) ;
}
int F_51 ( struct V_49 * V_25 , unsigned long V_47 )
{
struct V_6 * V_7 ;
int V_53 = 0 ;
if ( ! F_38 ( V_88 ) )
return - V_89 ;
V_7 = F_52 ( V_25 -> V_25 , sizeof( * V_7 ) , V_61 ) ;
if ( ! V_7 )
return - V_58 ;
V_25 -> V_26 = V_7 ;
V_7 -> V_25 = V_25 ;
F_53 ( & V_7 -> V_29 ) ;
V_53 = F_41 ( V_7 ) ;
if ( V_53 )
return V_53 ;
V_53 = F_54 ( V_7 ) ;
if ( V_53 )
goto V_90;
F_55 ( V_25 ) ;
V_25 -> V_91 . V_92 = ( void * ) & V_93 ;
V_25 -> V_91 . V_94 = 64 ;
V_25 -> V_91 . V_95 = 64 ;
V_25 -> V_91 . V_96 = 24 ;
V_25 -> V_91 . V_97 = V_98 ;
V_25 -> V_91 . V_99 = V_100 ;
V_53 = F_56 ( V_25 ) ;
if ( V_53 )
goto V_101;
V_53 = F_57 ( V_7 ) ;
if ( V_53 )
goto V_102;
V_53 = F_58 ( V_25 ) ;
if ( V_53 )
goto V_103;
return 0 ;
V_103:
F_59 ( V_7 ) ;
V_102:
F_60 ( V_25 ) ;
V_101:
F_61 ( V_25 ) ;
F_62 ( V_7 ) ;
V_90:
F_50 ( V_7 ) ;
return V_53 ;
}
void F_63 ( struct V_49 * V_25 )
{
struct V_6 * V_7 = V_25 -> V_26 ;
F_64 ( V_25 ) ;
F_59 ( V_7 ) ;
F_60 ( V_25 ) ;
F_61 ( V_25 ) ;
F_62 ( V_7 ) ;
F_50 ( V_7 ) ;
}
void F_65 ( struct V_49 * V_25 )
{
struct V_6 * V_7 = V_25 -> V_26 ;
if ( V_7 -> V_104 )
F_66 ( & V_7 -> V_104 -> V_105 ) ;
}
int F_67 ( struct V_49 * V_25 ,
T_1 V_106 , bool V_107 , struct V_52 * * V_5 )
{
struct V_108 * V_109 ;
int V_53 ;
* V_5 = NULL ;
V_106 = F_68 ( V_106 , V_110 ) ;
if ( V_106 == 0 )
return - V_111 ;
V_53 = F_69 ( V_25 , V_106 , 0 , 0 , & V_109 ) ;
if ( V_53 ) {
if ( V_53 != - V_112 )
F_7 ( L_6 ) ;
return V_53 ;
}
* V_5 = & V_109 -> V_113 ;
return 0 ;
}
int F_70 ( struct V_45 * V_114 ,
struct V_49 * V_25 , struct V_115 * args )
{
int V_53 ;
struct V_52 * V_116 ;
T_1 V_117 ;
args -> V_118 = args -> V_119 * ( ( args -> V_120 + 7 ) / 8 ) ;
args -> V_106 = args -> V_118 * args -> V_121 ;
V_53 = F_67 ( V_25 , args -> V_106 , false , & V_116 ) ;
if ( V_53 )
return V_53 ;
V_53 = F_71 ( V_114 , V_116 , & V_117 ) ;
F_3 ( V_116 ) ;
if ( V_53 )
return V_53 ;
args -> V_117 = V_117 ;
return 0 ;
}
static void F_72 ( struct V_108 * * V_122 )
{
struct V_123 * V_124 ;
if ( ( * V_122 ) == NULL )
return;
V_124 = & ( ( * V_122 ) -> V_122 ) ;
F_73 ( & V_124 ) ;
if ( ! V_124 )
* V_122 = NULL ;
}
void F_74 ( struct V_52 * V_5 )
{
struct V_108 * V_108 = F_75 ( V_5 ) ;
F_72 ( & V_108 ) ;
}
static inline T_2 F_76 ( struct V_108 * V_122 )
{
return F_77 ( & V_122 -> V_122 . V_125 ) ;
}
int
F_78 ( struct V_45 * V_114 ,
struct V_49 * V_25 ,
T_1 V_117 , T_2 * V_126 )
{
struct V_52 * V_5 ;
int V_53 ;
struct V_108 * V_122 ;
F_14 ( & V_25 -> V_127 ) ;
V_5 = F_27 ( V_114 , V_117 ) ;
if ( ! V_5 ) {
V_53 = - V_60 ;
goto V_128;
}
V_122 = F_75 ( V_5 ) ;
* V_126 = F_76 ( V_122 ) ;
F_79 ( V_5 ) ;
V_53 = 0 ;
V_128:
F_21 ( & V_25 -> V_127 ) ;
return V_53 ;
}
