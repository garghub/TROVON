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
if ( V_32 )
return V_32 ;
V_32 = F_15 ( V_8 , V_31 ) ;
if ( V_32 )
return V_32 ;
V_32 = F_16 ( V_8 , V_31 ) ;
if ( V_32 )
return V_32 ;
if ( F_17 ( V_11 , V_33 ) )
return 0 ;
return F_18 ( V_8 , V_31 ) ;
}
static void F_19 ( struct V_34 * V_35 )
{
struct V_7 * V_8 = V_35 -> V_8 ;
struct V_10 * V_11 = V_8 -> V_12 ;
struct V_30 * V_36 = V_35 -> V_31 ;
F_20 ( V_8 , V_36 ) ;
F_21 ( V_8 , V_36 ) ;
F_22 ( V_8 , V_36 ,
V_37 ) ;
F_23 ( V_8 , V_36 ) ;
F_24 ( V_8 , V_36 ) ;
F_25 ( V_36 ) ;
F_26 ( & V_11 -> V_35 . V_38 . V_39 ) ;
V_11 -> V_35 . V_40 &= ~ V_35 -> V_41 ;
F_27 ( & V_11 -> V_35 . V_38 ) ;
F_28 ( & V_11 -> V_35 . V_38 . V_39 ) ;
F_29 ( V_35 ) ;
}
static void F_30 ( struct V_42 * V_43 )
{
struct V_34 * V_35 =
F_31 ( V_43 , struct V_34 , V_43 ) ;
F_19 ( V_35 ) ;
}
static int F_32 ( struct V_7 * V_8 ,
struct V_30 * V_31 ,
bool V_44 )
{
struct V_10 * V_11 = V_8 -> V_12 ;
struct V_34 * V_35 ;
struct V_45 * V_46 ;
struct V_47 * V_48 ;
unsigned int V_3 ;
int V_32 ;
V_32 = F_33 ( V_8 , V_31 ) ;
if ( V_32 )
return V_32 ;
V_35 = F_34 ( sizeof( * V_35 ) , V_49 ) ;
if ( V_35 == NULL ) {
V_32 = - V_50 ;
goto error;
}
F_35 ( & V_35 -> V_43 , F_30 ) ;
V_35 -> V_8 = V_8 ;
V_35 -> V_31 = V_31 ;
F_36 (state, crtc, crtc_state, i)
V_35 -> V_41 |= F_37 ( V_46 ) ;
F_26 ( & V_11 -> V_35 . V_38 . V_39 ) ;
V_32 = F_38 ( V_11 -> V_35 . V_38 ,
! ( V_11 -> V_35 . V_40 & V_35 -> V_41 ) ) ;
if ( V_32 == 0 )
V_11 -> V_35 . V_40 |= V_35 -> V_41 ;
F_28 ( & V_11 -> V_35 . V_38 . V_39 ) ;
if ( V_32 ) {
F_29 ( V_35 ) ;
goto error;
}
F_39 ( V_31 , true ) ;
if ( V_44 )
F_40 ( & V_35 -> V_43 ) ;
else
F_19 ( V_35 ) ;
return 0 ;
error:
F_24 ( V_8 , V_31 ) ;
return V_32 ;
}
static int F_41 ( struct V_10 * V_11 ,
enum V_51 V_52 ,
struct V_53 * V_54 )
{
static const struct {
const char * V_55 ;
enum V_56 type ;
} V_57 [] = {
{ L_4 , V_58 } ,
{ L_5 , V_59 } ,
{ L_6 , V_60 } ,
} ;
enum V_56 V_61 = V_62 ;
struct V_63 * V_64 = NULL ;
struct V_63 * V_65 = NULL ;
struct V_63 * V_66 = NULL ;
struct V_63 * V_67 ;
struct V_63 * V_68 ;
int V_32 ;
V_68 = F_42 ( V_54 -> V_69 ) ;
if ( ! V_68 ) {
F_8 ( V_11 -> V_8 , L_7 ,
V_54 -> V_69 -> V_70 ) ;
return - V_71 ;
}
V_67 = F_43 ( V_54 -> V_69 , L_8 , 0 ) ;
F_44 (entity, ep_node) {
if ( V_66 == V_67 )
continue;
V_65 = V_68 ;
V_64 = F_42 ( V_66 ) ;
F_45 ( V_66 ) ;
if ( ! V_64 ) {
F_46 ( V_11 -> V_8 ,
L_9 ,
V_65 -> V_70 ) ;
F_45 ( V_67 ) ;
F_45 ( V_65 ) ;
return - V_71 ;
}
break;
}
F_45 ( V_67 ) ;
if ( V_65 ) {
unsigned int V_3 ;
for ( V_3 = 0 ; V_3 < F_1 ( V_57 ) ; ++ V_3 ) {
if ( F_47 ( V_65 ,
V_57 [ V_3 ] . V_55 ) ) {
V_61 = V_57 [ V_3 ] . type ;
break;
}
}
if ( V_3 == F_1 ( V_57 ) ) {
F_46 ( V_11 -> V_8 ,
L_10 ,
V_65 -> V_70 ) ;
F_45 ( V_65 ) ;
F_45 ( V_64 ) ;
return - V_26 ;
}
} else {
V_64 = V_68 ;
}
V_32 = F_48 ( V_11 , V_61 , V_52 , V_65 , V_64 ) ;
F_45 ( V_65 ) ;
F_45 ( V_64 ) ;
if ( V_32 && V_32 != - V_72 )
F_46 ( V_11 -> V_8 ,
L_11 ,
V_65 -> V_70 , V_32 ) ;
return V_32 ;
}
static int F_49 ( struct V_10 * V_11 )
{
struct V_63 * V_73 = V_11 -> V_8 -> V_74 ;
struct V_63 * V_66 ;
unsigned int V_75 = 0 ;
F_44 (np, ep_node) {
enum V_51 V_52 ;
struct V_53 V_54 ;
unsigned int V_3 ;
int V_32 ;
V_32 = F_50 ( V_66 , & V_54 ) ;
if ( V_32 < 0 ) {
F_45 ( V_66 ) ;
return V_32 ;
}
for ( V_3 = 0 ; V_3 < V_76 ; ++ V_3 ) {
if ( V_11 -> V_77 -> V_78 [ V_3 ] . V_79 &&
V_11 -> V_77 -> V_78 [ V_3 ] . V_80 == V_54 . V_80 ) {
V_52 = V_3 ;
break;
}
}
if ( V_3 == V_76 ) {
F_46 ( V_11 -> V_8 ,
L_12 ,
V_54 . V_80 ) ;
continue;
}
V_32 = F_41 ( V_11 , V_52 , & V_54 ) ;
if ( V_32 < 0 ) {
if ( V_32 == - V_72 ) {
F_45 ( V_66 ) ;
return V_32 ;
}
continue;
}
V_75 ++ ;
}
return V_75 ;
}
static int F_51 ( struct V_10 * V_11 )
{
V_11 -> V_81 . V_82 =
F_52 ( V_11 -> V_83 , 0 , L_13 , 0 , 255 ) ;
if ( V_11 -> V_81 . V_82 == NULL )
return - V_50 ;
V_11 -> V_81 . V_84 =
F_52 ( V_11 -> V_83 , 0 , L_14 ,
0 , 0x01ffffff ) ;
if ( V_11 -> V_81 . V_84 == NULL )
return - V_50 ;
return 0 ;
}
int F_53 ( struct V_10 * V_11 )
{
static const unsigned int V_85 [] = {
V_86 , V_87
} ;
struct V_7 * V_8 = V_11 -> V_83 ;
struct V_88 * V_65 ;
struct V_89 * V_29 ;
unsigned int V_75 ;
unsigned int V_90 ;
unsigned int V_3 ;
int V_32 ;
F_54 ( V_8 ) ;
V_8 -> V_91 . V_92 = 0 ;
V_8 -> V_91 . V_93 = 0 ;
V_8 -> V_91 . V_94 = 4095 ;
V_8 -> V_91 . V_95 = 2047 ;
V_8 -> V_91 . V_96 = & V_97 ;
V_11 -> V_98 = V_11 -> V_77 -> V_98 ;
V_32 = F_51 ( V_11 ) ;
if ( V_32 < 0 )
return V_32 ;
V_90 = F_3 ( V_11 -> V_98 , 2 ) ;
for ( V_3 = 0 ; V_3 < V_90 ; ++ V_3 ) {
struct V_99 * V_100 = & V_11 -> V_101 [ V_3 ] ;
F_55 ( & V_100 -> V_39 ) ;
V_100 -> V_8 = V_11 ;
V_100 -> V_102 = V_85 [ V_3 ] ;
V_100 -> V_103 = V_3 ;
V_100 -> V_98 = F_56 ( V_11 -> V_98 - 2 * V_3 , 2U ) ;
V_100 -> V_104 = V_100 -> V_98 > 1
? ( V_11 -> V_77 -> V_105 >= 3 ? 0x04 : 0xf0 )
: 0 ;
if ( ! F_17 ( V_11 , V_33 ) ) {
V_32 = F_57 ( V_100 ) ;
if ( V_32 < 0 )
return V_32 ;
}
}
if ( F_17 ( V_11 , V_33 ) ) {
for ( V_3 = 0 ; V_3 < V_11 -> V_98 ; ++ V_3 ) {
struct V_106 * V_107 = & V_11 -> V_108 [ V_3 ] ;
V_107 -> V_103 = V_3 ;
V_107 -> V_8 = V_11 ;
V_11 -> V_41 [ V_3 ] . V_107 = V_107 ;
V_32 = F_58 ( V_107 ) ;
if ( V_32 < 0 )
return V_32 ;
}
}
for ( V_3 = 0 ; V_3 < V_11 -> V_98 ; ++ V_3 ) {
struct V_99 * V_100 = & V_11 -> V_101 [ V_3 / 2 ] ;
V_32 = F_59 ( V_100 , V_3 ) ;
if ( V_32 < 0 )
return V_32 ;
}
V_32 = F_60 ( V_11 ) ;
if ( V_32 < 0 )
return V_32 ;
V_32 = F_49 ( V_11 ) ;
if ( V_32 < 0 )
return V_32 ;
if ( V_32 == 0 ) {
F_61 ( V_11 -> V_8 , L_15 ) ;
return - V_26 ;
}
V_75 = V_32 ;
F_62 (encoder, &dev->mode_config.encoder_list, head) {
struct V_109 * V_110 = F_63 ( V_65 ) ;
const struct V_111 * V_112 =
& V_11 -> V_77 -> V_78 [ V_110 -> V_52 ] ;
V_65 -> V_79 = V_112 -> V_79 ;
V_65 -> V_113 = ( 1 << V_75 ) - 1 ;
}
F_64 ( V_8 ) ;
F_65 ( V_8 ) ;
if ( V_8 -> V_91 . V_114 ) {
V_29 = F_66 ( V_8 , 32 , V_8 -> V_91 . V_115 ,
V_8 -> V_91 . V_114 ) ;
if ( F_67 ( V_29 ) )
return F_68 ( V_29 ) ;
V_11 -> V_29 = V_29 ;
} else {
F_69 ( V_11 -> V_8 ,
L_16 ) ;
}
return 0 ;
}
