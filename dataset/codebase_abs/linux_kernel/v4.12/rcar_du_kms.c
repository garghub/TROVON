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
static void F_19 ( struct V_30 * V_34 )
{
struct V_7 * V_8 = V_34 -> V_8 ;
F_20 ( V_8 , V_34 ) ;
F_21 ( V_8 , V_34 ) ;
F_22 ( V_8 , V_34 ,
V_35 ) ;
F_23 ( V_34 ) ;
F_24 ( V_8 , V_34 ) ;
F_25 ( V_8 , V_34 ) ;
}
static int F_26 ( struct V_10 * V_11 ,
enum V_36 V_37 ,
struct V_38 * V_39 )
{
struct V_40 * V_41 = NULL ;
struct V_40 * V_42 = NULL ;
struct V_40 * V_43 = NULL ;
struct V_40 * V_44 ;
struct V_40 * V_45 ;
int V_32 ;
V_45 = F_27 ( V_39 -> V_46 ) ;
if ( ! V_45 ) {
F_8 ( V_11 -> V_8 , L_4 ,
V_39 -> V_46 -> V_47 ) ;
return - V_48 ;
}
if ( ! F_28 ( V_45 ) ) {
F_8 ( V_11 -> V_8 ,
L_5 ,
V_45 -> V_47 ) ;
return - V_48 ;
}
V_44 = F_29 ( V_39 -> V_46 , L_6 , 0 ) ;
F_30 (entity, ep_node) {
if ( V_43 == V_44 )
continue;
V_42 = V_45 ;
V_41 = F_27 ( V_43 ) ;
F_31 ( V_43 ) ;
if ( ! V_41 ) {
F_32 ( V_11 -> V_8 ,
L_7 ,
V_42 -> V_47 ) ;
F_31 ( V_44 ) ;
F_31 ( V_42 ) ;
return - V_48 ;
}
break;
}
F_31 ( V_44 ) ;
if ( ! V_42 ) {
V_41 = V_45 ;
}
V_32 = F_33 ( V_11 , V_37 , V_42 , V_41 ) ;
if ( V_32 && V_32 != - V_49 )
F_32 ( V_11 -> V_8 ,
L_8 ,
F_34 ( V_42 ) , V_37 , V_32 ) ;
F_31 ( V_42 ) ;
F_31 ( V_41 ) ;
return V_32 ;
}
static int F_35 ( struct V_10 * V_11 )
{
struct V_40 * V_50 = V_11 -> V_8 -> V_51 ;
struct V_40 * V_43 ;
unsigned int V_52 = 0 ;
F_30 (np, ep_node) {
enum V_36 V_37 ;
struct V_38 V_39 ;
unsigned int V_3 ;
int V_32 ;
V_32 = F_36 ( V_43 , & V_39 ) ;
if ( V_32 < 0 ) {
F_31 ( V_43 ) ;
return V_32 ;
}
for ( V_3 = 0 ; V_3 < V_53 ; ++ V_3 ) {
if ( V_11 -> V_54 -> V_55 [ V_3 ] . V_56 &&
V_11 -> V_54 -> V_55 [ V_3 ] . V_57 == V_39 . V_57 ) {
V_37 = V_3 ;
break;
}
}
if ( V_3 == V_53 ) {
F_32 ( V_11 -> V_8 ,
L_9 ,
V_39 . V_57 ) ;
continue;
}
V_32 = F_26 ( V_11 , V_37 , & V_39 ) ;
if ( V_32 < 0 ) {
if ( V_32 == - V_49 ) {
F_31 ( V_43 ) ;
return V_32 ;
}
continue;
}
V_52 ++ ;
}
return V_52 ;
}
static int F_37 ( struct V_10 * V_11 )
{
V_11 -> V_58 . V_59 =
F_38 ( V_11 -> V_60 , 0 , L_10 , 0 , 255 ) ;
if ( V_11 -> V_58 . V_59 == NULL )
return - V_61 ;
V_11 -> V_58 . V_62 =
F_38 ( V_11 -> V_60 , 0 , L_11 ,
0 , 0x01ffffff ) ;
if ( V_11 -> V_58 . V_62 == NULL )
return - V_61 ;
return 0 ;
}
int F_39 ( struct V_10 * V_11 )
{
static const unsigned int V_63 [] = {
V_64 , V_65
} ;
struct V_7 * V_8 = V_11 -> V_60 ;
struct V_66 * V_42 ;
struct V_67 * V_29 ;
unsigned int V_52 ;
unsigned int V_68 ;
unsigned int V_3 ;
int V_32 ;
F_40 ( V_8 ) ;
V_8 -> V_69 . V_70 = 0 ;
V_8 -> V_69 . V_71 = 0 ;
V_8 -> V_69 . V_72 = 4095 ;
V_8 -> V_69 . V_73 = 2047 ;
V_8 -> V_69 . V_74 = & V_75 ;
V_8 -> V_69 . V_76 = & V_77 ;
V_11 -> V_78 = V_11 -> V_54 -> V_78 ;
V_32 = F_37 ( V_11 ) ;
if ( V_32 < 0 )
return V_32 ;
V_32 = F_41 ( V_8 , ( 1 << V_11 -> V_54 -> V_78 ) - 1 ) ;
if ( V_32 < 0 )
return V_32 ;
V_68 = F_3 ( V_11 -> V_78 , 2 ) ;
for ( V_3 = 0 ; V_3 < V_68 ; ++ V_3 ) {
struct V_79 * V_80 = & V_11 -> V_81 [ V_3 ] ;
F_42 ( & V_80 -> V_82 ) ;
V_80 -> V_8 = V_11 ;
V_80 -> V_83 = V_63 [ V_3 ] ;
V_80 -> V_84 = V_3 ;
V_80 -> V_78 = F_43 ( V_11 -> V_78 - 2 * V_3 , 2U ) ;
V_80 -> V_85 = V_80 -> V_78 > 1
? ( V_11 -> V_54 -> V_86 >= 3 ? 0x04 : 0xf0 )
: 0 ;
if ( ! F_17 ( V_11 , V_33 ) ) {
V_32 = F_44 ( V_80 ) ;
if ( V_32 < 0 )
return V_32 ;
}
}
if ( F_17 ( V_11 , V_33 ) ) {
for ( V_3 = 0 ; V_3 < V_11 -> V_78 ; ++ V_3 ) {
struct V_87 * V_88 = & V_11 -> V_89 [ V_3 ] ;
V_88 -> V_84 = V_3 ;
V_88 -> V_8 = V_11 ;
V_11 -> V_90 [ V_3 ] . V_88 = V_88 ;
V_32 = F_45 ( V_88 ) ;
if ( V_32 < 0 )
return V_32 ;
}
}
for ( V_3 = 0 ; V_3 < V_11 -> V_78 ; ++ V_3 ) {
struct V_79 * V_80 = & V_11 -> V_81 [ V_3 / 2 ] ;
V_32 = F_46 ( V_80 , V_3 ) ;
if ( V_32 < 0 )
return V_32 ;
}
V_32 = F_47 ( V_11 ) ;
if ( V_32 < 0 )
return V_32 ;
V_32 = F_35 ( V_11 ) ;
if ( V_32 < 0 )
return V_32 ;
if ( V_32 == 0 ) {
F_48 ( V_11 -> V_8 , L_12 ) ;
return - V_26 ;
}
V_52 = V_32 ;
F_49 (encoder, &dev->mode_config.encoder_list, head) {
struct V_91 * V_92 = F_50 ( V_42 ) ;
const struct V_93 * V_94 =
& V_11 -> V_54 -> V_55 [ V_92 -> V_37 ] ;
V_42 -> V_56 = V_94 -> V_56 ;
V_42 -> V_95 = ( 1 << V_52 ) - 1 ;
}
F_51 ( V_8 ) ;
F_52 ( V_8 ) ;
if ( V_8 -> V_69 . V_96 ) {
V_29 = F_53 ( V_8 , 32 ,
V_8 -> V_69 . V_96 ) ;
if ( F_54 ( V_29 ) )
return F_55 ( V_29 ) ;
V_11 -> V_29 = V_29 ;
} else {
F_56 ( V_11 -> V_8 ,
L_13 ) ;
}
return 0 ;
}
