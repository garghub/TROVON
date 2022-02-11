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
F_21 ( V_8 , V_34 ,
V_35 ) ;
F_22 ( V_8 , V_34 ) ;
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
V_39 -> V_46 ) ;
return - V_47 ;
}
if ( ! F_28 ( V_45 ) ) {
F_8 ( V_11 -> V_8 ,
L_5 ,
V_45 ) ;
return - V_47 ;
}
V_44 = F_29 ( V_39 -> V_46 ) ;
F_30 (entity, ep_node) {
if ( V_43 == V_44 )
continue;
V_42 = V_45 ;
V_41 = F_27 ( V_43 ) ;
F_31 ( V_43 ) ;
if ( ! V_41 ) {
F_32 ( V_11 -> V_8 ,
L_6 ,
V_42 ) ;
F_31 ( V_44 ) ;
F_31 ( V_42 ) ;
return - V_47 ;
}
break;
}
F_31 ( V_44 ) ;
if ( ! V_42 ) {
V_41 = V_45 ;
}
V_32 = F_33 ( V_11 , V_37 , V_42 , V_41 ) ;
if ( V_32 && V_32 != - V_48 )
F_32 ( V_11 -> V_8 ,
L_7 ,
V_42 , V_37 , V_32 ) ;
F_31 ( V_42 ) ;
F_31 ( V_41 ) ;
return V_32 ;
}
static int F_34 ( struct V_10 * V_11 )
{
struct V_40 * V_49 = V_11 -> V_8 -> V_50 ;
struct V_40 * V_43 ;
unsigned int V_51 = 0 ;
F_30 (np, ep_node) {
enum V_36 V_37 ;
struct V_38 V_39 ;
unsigned int V_3 ;
int V_32 ;
V_32 = F_35 ( V_43 , & V_39 ) ;
if ( V_32 < 0 ) {
F_31 ( V_43 ) ;
return V_32 ;
}
for ( V_3 = 0 ; V_3 < V_52 ; ++ V_3 ) {
if ( V_11 -> V_53 -> V_54 [ V_3 ] . V_55 &&
V_11 -> V_53 -> V_54 [ V_3 ] . V_56 == V_39 . V_56 ) {
V_37 = V_3 ;
break;
}
}
if ( V_3 == V_52 ) {
F_32 ( V_11 -> V_8 ,
L_8 ,
V_39 . V_56 ) ;
continue;
}
V_32 = F_26 ( V_11 , V_37 , & V_39 ) ;
if ( V_32 < 0 ) {
if ( V_32 == - V_48 ) {
F_31 ( V_43 ) ;
return V_32 ;
}
continue;
}
V_51 ++ ;
}
return V_51 ;
}
static int F_36 ( struct V_10 * V_11 )
{
V_11 -> V_57 . V_58 =
F_37 ( V_11 -> V_59 , 0 , L_9 , 0 , 255 ) ;
if ( V_11 -> V_57 . V_58 == NULL )
return - V_60 ;
V_11 -> V_57 . V_61 =
F_37 ( V_11 -> V_59 , 0 , L_10 ,
0 , 0x01ffffff ) ;
if ( V_11 -> V_57 . V_61 == NULL )
return - V_60 ;
return 0 ;
}
static int F_38 ( struct V_10 * V_11 )
{
const struct V_40 * V_49 = V_11 -> V_8 -> V_50 ;
struct V_62 args ;
struct {
struct V_40 * V_49 ;
unsigned int V_63 ;
} V_64 [ V_65 ] = { { 0 , } , } ;
unsigned int V_66 = 0 ;
unsigned int V_67 ;
unsigned int V_3 ;
int V_32 ;
V_67 = F_39 ( V_49 , L_11 ) / V_11 -> V_68 - 1 ;
if ( V_67 > 1 )
return - V_26 ;
for ( V_3 = 0 ; V_3 < V_11 -> V_68 ; ++ V_3 ) {
unsigned int V_69 ;
V_32 = F_40 ( V_49 , L_11 , V_67 , V_3 ,
& args ) ;
if ( V_32 < 0 )
goto error;
for ( V_69 = 0 ; V_69 < V_66 ; ++ V_69 ) {
if ( V_64 [ V_69 ] . V_49 == args . V_49 )
break;
}
if ( V_69 < V_66 )
F_31 ( args . V_49 ) ;
else
V_64 [ V_66 ++ ] . V_49 = args . V_49 ;
V_64 [ V_69 ] . V_63 |= F_41 ( V_3 ) ;
V_11 -> V_70 [ V_3 ] . V_71 = & V_11 -> V_64 [ V_69 ] ;
V_11 -> V_70 [ V_3 ] . V_72 = V_67 >= 1 ? args . args [ 0 ] : 0 ;
}
for ( V_3 = 0 ; V_3 < V_66 ; ++ V_3 ) {
struct V_73 * V_71 = & V_11 -> V_64 [ V_3 ] ;
V_71 -> V_74 = V_3 ;
V_71 -> V_8 = V_11 ;
V_32 = F_42 ( V_71 , V_64 [ V_3 ] . V_49 , V_64 [ V_3 ] . V_63 ) ;
if ( V_32 < 0 )
goto error;
}
return 0 ;
error:
for ( V_3 = 0 ; V_3 < F_1 ( V_64 ) ; ++ V_3 )
F_31 ( V_64 [ V_3 ] . V_49 ) ;
return V_32 ;
}
int F_43 ( struct V_10 * V_11 )
{
static const unsigned int V_75 [] = {
V_76 , V_77
} ;
struct V_7 * V_8 = V_11 -> V_59 ;
struct V_78 * V_42 ;
struct V_79 * V_29 ;
unsigned int V_51 ;
unsigned int V_80 ;
unsigned int V_3 ;
int V_32 ;
F_44 ( V_8 ) ;
V_8 -> V_81 . V_82 = 0 ;
V_8 -> V_81 . V_83 = 0 ;
V_8 -> V_81 . V_84 = 4095 ;
V_8 -> V_81 . V_85 = 2047 ;
V_8 -> V_81 . V_86 = & V_87 ;
V_8 -> V_81 . V_88 = & V_89 ;
V_11 -> V_68 = V_11 -> V_53 -> V_68 ;
V_32 = F_36 ( V_11 ) ;
if ( V_32 < 0 )
return V_32 ;
V_32 = F_45 ( V_8 , ( 1 << V_11 -> V_53 -> V_68 ) - 1 ) ;
if ( V_32 < 0 )
return V_32 ;
V_80 = F_3 ( V_11 -> V_68 , 2 ) ;
for ( V_3 = 0 ; V_3 < V_80 ; ++ V_3 ) {
struct V_90 * V_91 = & V_11 -> V_92 [ V_3 ] ;
F_46 ( & V_91 -> V_93 ) ;
V_91 -> V_8 = V_11 ;
V_91 -> V_94 = V_75 [ V_3 ] ;
V_91 -> V_74 = V_3 ;
V_91 -> V_68 = F_47 ( V_11 -> V_68 - 2 * V_3 , 2U ) ;
V_91 -> V_95 = V_91 -> V_68 > 1
? ( V_11 -> V_53 -> V_96 >= 3 ? 0x04 : 0xf0 )
: 0 ;
if ( ! F_17 ( V_11 , V_33 ) ) {
V_32 = F_48 ( V_91 ) ;
if ( V_32 < 0 )
return V_32 ;
}
}
if ( F_17 ( V_11 , V_33 ) ) {
V_32 = F_38 ( V_11 ) ;
if ( V_32 < 0 )
return V_32 ;
}
for ( V_3 = 0 ; V_3 < V_11 -> V_68 ; ++ V_3 ) {
struct V_90 * V_91 = & V_11 -> V_92 [ V_3 / 2 ] ;
V_32 = F_49 ( V_91 , V_3 ) ;
if ( V_32 < 0 )
return V_32 ;
}
V_32 = F_50 ( V_11 ) ;
if ( V_32 < 0 )
return V_32 ;
V_32 = F_34 ( V_11 ) ;
if ( V_32 < 0 )
return V_32 ;
if ( V_32 == 0 ) {
F_51 ( V_11 -> V_8 , L_12 ) ;
return - V_26 ;
}
V_51 = V_32 ;
F_52 (encoder, &dev->mode_config.encoder_list, head) {
struct V_97 * V_98 = F_53 ( V_42 ) ;
const struct V_99 * V_100 =
& V_11 -> V_53 -> V_54 [ V_98 -> V_37 ] ;
V_42 -> V_55 = V_100 -> V_55 ;
V_42 -> V_101 = ( 1 << V_51 ) - 1 ;
}
F_54 ( V_8 ) ;
F_55 ( V_8 ) ;
if ( V_8 -> V_81 . V_102 ) {
V_29 = F_56 ( V_8 , 32 ,
V_8 -> V_81 . V_102 ) ;
if ( F_57 ( V_29 ) )
return F_58 ( V_29 ) ;
V_11 -> V_29 = V_29 ;
} else {
F_59 ( V_11 -> V_8 ,
L_13 ) ;
}
return 0 ;
}
