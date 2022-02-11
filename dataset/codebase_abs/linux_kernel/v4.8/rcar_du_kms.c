const struct V_1 * V_1 ( T_1 V_2 )
{
unsigned int V_3 ;
for ( V_3 = 0 ; V_3 < F_1 ( V_4 ) ; ++ V_3 ) {
if ( V_4 [ V_3 ] . V_2 == V_2 )
return & V_4 [ V_3 ] ;
}
return NULL ;
}
int F_2 ( struct V_5 * V_6 , struct V_7 * V_8 ,
struct V_9 * args )
{
struct V_10 * V_11 = V_8 -> V_12 ;
unsigned int V_13 = F_3 ( args -> V_14 * args -> V_15 , 8 ) ;
unsigned int V_16 ;
if ( F_4 ( V_11 , V_17 ) )
V_16 = 128 ;
else
V_16 = 16 * args -> V_15 / 8 ;
args -> V_18 = F_5 ( V_13 , V_16 ) ;
return F_6 ( V_6 , V_8 , args ) ;
}
static struct V_19 *
F_7 ( struct V_7 * V_8 , struct V_5 * V_20 ,
const struct V_21 * V_22 )
{
struct V_10 * V_11 = V_8 -> V_12 ;
const struct V_1 * V_23 ;
unsigned int V_24 ;
unsigned int V_16 ;
unsigned int V_15 ;
unsigned int V_3 ;
V_23 = V_1 ( V_22 -> V_25 ) ;
if ( V_23 == NULL ) {
F_8 ( V_8 -> V_8 , L_1 ,
V_22 -> V_25 ) ;
return F_9 ( - V_26 ) ;
}
V_15 = V_23 -> V_27 == 1 ? V_23 -> V_15 / 8 : 1 ;
V_24 = 4096 * V_15 ;
if ( F_4 ( V_11 , V_17 ) )
V_16 = 128 ;
else
V_16 = 16 * V_15 ;
if ( V_22 -> V_28 [ 0 ] & ( V_16 - 1 ) ||
V_22 -> V_28 [ 0 ] >= V_24 ) {
F_8 ( V_8 -> V_8 , L_2 ,
V_22 -> V_28 [ 0 ] ) ;
return F_9 ( - V_26 ) ;
}
for ( V_3 = 1 ; V_3 < V_23 -> V_27 ; ++ V_3 ) {
if ( V_22 -> V_28 [ V_3 ] != V_22 -> V_28 [ 0 ] ) {
F_8 ( V_8 -> V_8 ,
L_3 ) ;
return F_9 ( - V_26 ) ;
}
}
return F_10 ( V_8 , V_20 , V_22 ) ;
}
static void F_11 ( struct V_7 * V_8 )
{
struct V_10 * V_11 = V_8 -> V_12 ;
F_12 ( V_11 -> V_29 ) ;
}
static int F_13 ( struct V_7 * V_8 ,
struct V_30 * V_31 )
{
struct V_10 * V_11 = V_8 -> V_12 ;
int V_32 ;
V_32 = F_14 ( V_8 , V_31 ) ;
if ( V_32 < 0 )
return V_32 ;
if ( F_15 ( V_11 , V_33 ) )
return 0 ;
return F_16 ( V_8 , V_31 ) ;
}
static void F_17 ( struct V_34 * V_35 )
{
struct V_7 * V_8 = V_35 -> V_8 ;
struct V_10 * V_11 = V_8 -> V_12 ;
struct V_30 * V_36 = V_35 -> V_31 ;
F_18 ( V_8 , V_36 ) ;
F_19 ( V_8 , V_36 ) ;
F_20 ( V_8 , V_36 , true ) ;
F_21 ( V_8 , V_36 ) ;
F_22 ( V_8 , V_36 ) ;
F_23 ( V_36 ) ;
F_24 ( & V_11 -> V_35 . V_37 . V_38 ) ;
V_11 -> V_35 . V_39 &= ~ V_35 -> V_40 ;
F_25 ( & V_11 -> V_35 . V_37 ) ;
F_26 ( & V_11 -> V_35 . V_37 . V_38 ) ;
F_27 ( V_35 ) ;
}
static void F_28 ( struct V_41 * V_42 )
{
struct V_34 * V_35 =
F_29 ( V_42 , struct V_34 , V_42 ) ;
F_17 ( V_35 ) ;
}
static int F_30 ( struct V_7 * V_8 ,
struct V_30 * V_31 ,
bool V_43 )
{
struct V_10 * V_11 = V_8 -> V_12 ;
struct V_34 * V_35 ;
struct V_44 * V_45 ;
struct V_46 * V_47 ;
unsigned int V_3 ;
int V_32 ;
V_32 = F_31 ( V_8 , V_31 ) ;
if ( V_32 )
return V_32 ;
V_35 = F_32 ( sizeof( * V_35 ) , V_48 ) ;
if ( V_35 == NULL ) {
V_32 = - V_49 ;
goto error;
}
F_33 ( & V_35 -> V_42 , F_28 ) ;
V_35 -> V_8 = V_8 ;
V_35 -> V_31 = V_31 ;
F_34 (state, crtc, crtc_state, i)
V_35 -> V_40 |= F_35 ( V_45 ) ;
F_24 ( & V_11 -> V_35 . V_37 . V_38 ) ;
V_32 = F_36 ( V_11 -> V_35 . V_37 ,
! ( V_11 -> V_35 . V_39 & V_35 -> V_40 ) ) ;
if ( V_32 == 0 )
V_11 -> V_35 . V_39 |= V_35 -> V_40 ;
F_26 ( & V_11 -> V_35 . V_37 . V_38 ) ;
if ( V_32 ) {
F_27 ( V_35 ) ;
goto error;
}
F_37 ( V_31 , true ) ;
if ( V_43 )
F_38 ( & V_35 -> V_42 ) ;
else
F_17 ( V_35 ) ;
return 0 ;
error:
F_22 ( V_8 , V_31 ) ;
return V_32 ;
}
static int F_39 ( struct V_10 * V_11 ,
enum V_50 V_51 ,
struct V_52 * V_53 )
{
static const struct {
const char * V_54 ;
enum V_55 type ;
} V_56 [] = {
{ L_4 , V_57 } ,
{ L_5 , V_58 } ,
{ L_6 , V_59 } ,
} ;
enum V_55 V_60 = V_61 ;
struct V_62 * V_63 = NULL ;
struct V_62 * V_64 = NULL ;
struct V_62 * V_65 = NULL ;
struct V_62 * V_66 ;
struct V_62 * V_67 ;
int V_32 ;
V_67 = F_40 ( V_53 -> V_68 ) ;
if ( ! V_67 ) {
F_8 ( V_11 -> V_8 , L_7 ,
V_53 -> V_68 -> V_69 ) ;
return - V_70 ;
}
V_66 = F_41 ( V_53 -> V_68 , L_8 , 0 ) ;
F_42 (entity, ep_node) {
if ( V_65 == V_66 )
continue;
V_64 = V_67 ;
V_63 = F_40 ( V_65 ) ;
F_43 ( V_65 ) ;
if ( ! V_63 ) {
F_44 ( V_11 -> V_8 ,
L_9 ,
V_64 -> V_69 ) ;
F_43 ( V_66 ) ;
F_43 ( V_64 ) ;
return - V_70 ;
}
break;
}
F_43 ( V_66 ) ;
if ( V_64 ) {
unsigned int V_3 ;
for ( V_3 = 0 ; V_3 < F_1 ( V_56 ) ; ++ V_3 ) {
if ( F_45 ( V_64 ,
V_56 [ V_3 ] . V_54 ) ) {
V_60 = V_56 [ V_3 ] . type ;
break;
}
}
if ( V_3 == F_1 ( V_56 ) ) {
F_44 ( V_11 -> V_8 ,
L_10 ,
V_64 -> V_69 ) ;
F_43 ( V_64 ) ;
F_43 ( V_63 ) ;
return - V_26 ;
}
} else {
V_63 = V_67 ;
}
V_32 = F_46 ( V_11 , V_60 , V_51 , V_64 , V_63 ) ;
F_43 ( V_64 ) ;
F_43 ( V_63 ) ;
if ( V_32 && V_32 != - V_71 )
F_44 ( V_11 -> V_8 ,
L_11 ,
V_64 -> V_69 , V_32 ) ;
return V_32 ;
}
static int F_47 ( struct V_10 * V_11 )
{
struct V_62 * V_72 = V_11 -> V_8 -> V_73 ;
struct V_62 * V_65 ;
unsigned int V_74 = 0 ;
F_42 (np, ep_node) {
enum V_50 V_51 ;
struct V_52 V_53 ;
unsigned int V_3 ;
int V_32 ;
V_32 = F_48 ( V_65 , & V_53 ) ;
if ( V_32 < 0 ) {
F_43 ( V_65 ) ;
return V_32 ;
}
for ( V_3 = 0 ; V_3 < V_75 ; ++ V_3 ) {
if ( V_11 -> V_76 -> V_77 [ V_3 ] . V_78 &&
V_11 -> V_76 -> V_77 [ V_3 ] . V_79 == V_53 . V_79 ) {
V_51 = V_3 ;
break;
}
}
if ( V_3 == V_75 ) {
F_44 ( V_11 -> V_8 ,
L_12 ,
V_53 . V_79 ) ;
continue;
}
V_32 = F_39 ( V_11 , V_51 , & V_53 ) ;
if ( V_32 < 0 ) {
if ( V_32 == - V_71 ) {
F_43 ( V_65 ) ;
return V_32 ;
}
continue;
}
V_74 ++ ;
}
return V_74 ;
}
static int F_49 ( struct V_10 * V_11 )
{
V_11 -> V_80 . V_81 =
F_50 ( V_11 -> V_82 , 0 , L_13 , 0 , 255 ) ;
if ( V_11 -> V_80 . V_81 == NULL )
return - V_49 ;
V_11 -> V_80 . V_83 =
F_50 ( V_11 -> V_82 , 0 , L_14 ,
0 , 0x01ffffff ) ;
if ( V_11 -> V_80 . V_83 == NULL )
return - V_49 ;
return 0 ;
}
int F_51 ( struct V_10 * V_11 )
{
static const unsigned int V_84 [] = {
V_85 , V_86
} ;
struct V_7 * V_8 = V_11 -> V_82 ;
struct V_87 * V_64 ;
struct V_88 * V_29 ;
unsigned int V_74 ;
unsigned int V_89 ;
unsigned int V_3 ;
int V_32 ;
F_52 ( V_8 ) ;
V_8 -> V_90 . V_91 = 0 ;
V_8 -> V_90 . V_92 = 0 ;
V_8 -> V_90 . V_93 = 4095 ;
V_8 -> V_90 . V_94 = 2047 ;
V_8 -> V_90 . V_95 = & V_96 ;
V_11 -> V_97 = V_11 -> V_76 -> V_97 ;
V_32 = F_49 ( V_11 ) ;
if ( V_32 < 0 )
return V_32 ;
V_89 = F_3 ( V_11 -> V_97 , 2 ) ;
for ( V_3 = 0 ; V_3 < V_89 ; ++ V_3 ) {
struct V_98 * V_99 = & V_11 -> V_100 [ V_3 ] ;
F_53 ( & V_99 -> V_38 ) ;
V_99 -> V_8 = V_11 ;
V_99 -> V_101 = V_84 [ V_3 ] ;
V_99 -> V_102 = V_3 ;
V_99 -> V_97 = F_54 ( V_11 -> V_97 - 2 * V_3 , 2U ) ;
V_99 -> V_103 = V_99 -> V_97 > 1
? ( V_11 -> V_76 -> V_104 >= 3 ? 0x04 : 0xf0 )
: 0 ;
if ( ! F_15 ( V_11 , V_33 ) ) {
V_32 = F_55 ( V_99 ) ;
if ( V_32 < 0 )
return V_32 ;
}
}
if ( F_15 ( V_11 , V_33 ) ) {
for ( V_3 = 0 ; V_3 < V_11 -> V_97 ; ++ V_3 ) {
struct V_105 * V_106 = & V_11 -> V_107 [ V_3 ] ;
V_106 -> V_102 = V_3 ;
V_106 -> V_8 = V_11 ;
V_11 -> V_40 [ V_3 ] . V_106 = V_106 ;
V_32 = F_56 ( V_106 ) ;
if ( V_32 < 0 )
return V_32 ;
}
}
for ( V_3 = 0 ; V_3 < V_11 -> V_97 ; ++ V_3 ) {
struct V_98 * V_99 = & V_11 -> V_100 [ V_3 / 2 ] ;
V_32 = F_57 ( V_99 , V_3 ) ;
if ( V_32 < 0 )
return V_32 ;
}
V_32 = F_58 ( V_11 ) ;
if ( V_32 < 0 )
return V_32 ;
V_32 = F_47 ( V_11 ) ;
if ( V_32 < 0 )
return V_32 ;
if ( V_32 == 0 ) {
F_59 ( V_11 -> V_8 , L_15 ) ;
return - V_26 ;
}
V_74 = V_32 ;
F_60 (encoder, &dev->mode_config.encoder_list, head) {
struct V_108 * V_109 = F_61 ( V_64 ) ;
const struct V_110 * V_111 =
& V_11 -> V_76 -> V_77 [ V_109 -> V_51 ] ;
V_64 -> V_78 = V_111 -> V_78 ;
V_64 -> V_112 = ( 1 << V_74 ) - 1 ;
}
F_62 ( V_8 ) ;
F_63 ( V_8 ) ;
if ( V_8 -> V_90 . V_113 ) {
V_29 = F_64 ( V_8 , 32 , V_8 -> V_90 . V_114 ,
V_8 -> V_90 . V_113 ) ;
if ( F_65 ( V_29 ) )
return F_66 ( V_29 ) ;
V_11 -> V_29 = V_29 ;
} else {
F_67 ( V_11 -> V_8 ,
L_16 ) ;
}
return 0 ;
}
