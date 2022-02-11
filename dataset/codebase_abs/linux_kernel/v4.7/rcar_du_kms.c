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
unsigned int V_3 ;
int V_32 ;
V_32 = F_31 ( V_8 , V_31 ) ;
if ( V_32 )
return V_32 ;
V_35 = F_32 ( sizeof( * V_35 ) , V_44 ) ;
if ( V_35 == NULL ) {
V_32 = - V_45 ;
goto error;
}
F_33 ( & V_35 -> V_42 , F_28 ) ;
V_35 -> V_8 = V_8 ;
V_35 -> V_31 = V_31 ;
for ( V_3 = 0 ; V_3 < V_8 -> V_46 . V_47 ; ++ V_3 ) {
if ( V_31 -> V_40 [ V_3 ] )
V_35 -> V_40 |= 1 << F_34 ( V_31 -> V_40 [ V_3 ] ) ;
}
F_24 ( & V_11 -> V_35 . V_37 . V_38 ) ;
V_32 = F_35 ( V_11 -> V_35 . V_37 ,
! ( V_11 -> V_35 . V_39 & V_35 -> V_40 ) ) ;
if ( V_32 == 0 )
V_11 -> V_35 . V_39 |= V_35 -> V_40 ;
F_26 ( & V_11 -> V_35 . V_37 . V_38 ) ;
if ( V_32 ) {
F_27 ( V_35 ) ;
goto error;
}
F_36 ( V_8 , V_31 ) ;
if ( V_43 )
F_37 ( & V_35 -> V_42 ) ;
else
F_17 ( V_35 ) ;
return 0 ;
error:
F_22 ( V_8 , V_31 ) ;
return V_32 ;
}
static int F_38 ( struct V_10 * V_11 ,
enum V_48 V_49 ,
struct V_50 * V_51 )
{
static const struct {
const char * V_52 ;
enum V_53 type ;
} V_54 [] = {
{ L_4 , V_55 } ,
{ L_5 , V_56 } ,
{ L_6 , V_57 } ,
} ;
enum V_53 V_58 = V_59 ;
struct V_60 * V_61 = NULL ;
struct V_60 * V_62 = NULL ;
struct V_60 * V_63 = NULL ;
struct V_60 * V_64 ;
struct V_60 * V_65 ;
int V_32 ;
V_65 = F_39 ( V_51 -> V_66 ) ;
if ( ! V_65 ) {
F_8 ( V_11 -> V_8 , L_7 ,
V_51 -> V_66 -> V_67 ) ;
return - V_68 ;
}
V_64 = F_40 ( V_51 -> V_66 , L_8 , 0 ) ;
F_41 (entity, ep_node) {
if ( V_63 == V_64 )
continue;
V_62 = V_65 ;
V_61 = F_39 ( V_63 ) ;
F_42 ( V_63 ) ;
if ( ! V_61 ) {
F_43 ( V_11 -> V_8 ,
L_9 ,
V_62 -> V_67 ) ;
F_42 ( V_64 ) ;
F_42 ( V_62 ) ;
return - V_68 ;
}
break;
}
F_42 ( V_64 ) ;
if ( V_62 ) {
unsigned int V_3 ;
for ( V_3 = 0 ; V_3 < F_1 ( V_54 ) ; ++ V_3 ) {
if ( F_44 ( V_62 ,
V_54 [ V_3 ] . V_52 ) ) {
V_58 = V_54 [ V_3 ] . type ;
break;
}
}
if ( V_3 == F_1 ( V_54 ) ) {
F_43 ( V_11 -> V_8 ,
L_10 ,
V_62 -> V_67 ) ;
F_42 ( V_62 ) ;
F_42 ( V_61 ) ;
return - V_26 ;
}
} else {
V_61 = V_65 ;
}
V_32 = F_45 ( V_11 , V_58 , V_49 , V_62 , V_61 ) ;
F_42 ( V_62 ) ;
F_42 ( V_61 ) ;
if ( V_32 && V_32 != - V_69 )
F_43 ( V_11 -> V_8 ,
L_11 ,
V_62 -> V_67 , V_32 ) ;
return V_32 ;
}
static int F_46 ( struct V_10 * V_11 )
{
struct V_60 * V_70 = V_11 -> V_8 -> V_71 ;
struct V_60 * V_63 ;
unsigned int V_72 = 0 ;
F_41 (np, ep_node) {
enum V_48 V_49 ;
struct V_50 V_51 ;
unsigned int V_3 ;
int V_32 ;
V_32 = F_47 ( V_63 , & V_51 ) ;
if ( V_32 < 0 ) {
F_42 ( V_63 ) ;
return V_32 ;
}
for ( V_3 = 0 ; V_3 < V_73 ; ++ V_3 ) {
if ( V_11 -> V_74 -> V_75 [ V_3 ] . V_76 &&
V_11 -> V_74 -> V_75 [ V_3 ] . V_77 == V_51 . V_77 ) {
V_49 = V_3 ;
break;
}
}
if ( V_3 == V_73 ) {
F_43 ( V_11 -> V_8 ,
L_12 ,
V_51 . V_77 ) ;
continue;
}
V_32 = F_38 ( V_11 , V_49 , & V_51 ) ;
if ( V_32 < 0 ) {
if ( V_32 == - V_69 ) {
F_42 ( V_63 ) ;
return V_32 ;
}
continue;
}
V_72 ++ ;
}
return V_72 ;
}
static int F_48 ( struct V_10 * V_11 )
{
V_11 -> V_78 . V_79 =
F_49 ( V_11 -> V_80 , 0 , L_13 , 0 , 255 ) ;
if ( V_11 -> V_78 . V_79 == NULL )
return - V_45 ;
V_11 -> V_78 . V_81 =
F_49 ( V_11 -> V_80 , 0 , L_14 ,
0 , 0x01ffffff ) ;
if ( V_11 -> V_78 . V_81 == NULL )
return - V_45 ;
V_11 -> V_78 . V_82 =
F_49 ( V_11 -> V_80 , 0 , L_15 , 1 , 7 ) ;
if ( V_11 -> V_78 . V_82 == NULL )
return - V_45 ;
return 0 ;
}
int F_50 ( struct V_10 * V_11 )
{
static const unsigned int V_83 [] = {
V_84 , V_85
} ;
struct V_7 * V_8 = V_11 -> V_80 ;
struct V_86 * V_62 ;
struct V_87 * V_29 ;
unsigned int V_72 ;
unsigned int V_88 ;
unsigned int V_3 ;
int V_32 ;
F_51 ( V_8 ) ;
V_8 -> V_46 . V_89 = 0 ;
V_8 -> V_46 . V_90 = 0 ;
V_8 -> V_46 . V_91 = 4095 ;
V_8 -> V_46 . V_92 = 2047 ;
V_8 -> V_46 . V_93 = & V_94 ;
V_11 -> V_95 = V_11 -> V_74 -> V_95 ;
V_32 = F_48 ( V_11 ) ;
if ( V_32 < 0 )
return V_32 ;
V_88 = F_3 ( V_11 -> V_95 , 2 ) ;
for ( V_3 = 0 ; V_3 < V_88 ; ++ V_3 ) {
struct V_96 * V_97 = & V_11 -> V_98 [ V_3 ] ;
F_52 ( & V_97 -> V_38 ) ;
V_97 -> V_8 = V_11 ;
V_97 -> V_99 = V_83 [ V_3 ] ;
V_97 -> V_100 = V_3 ;
V_97 -> V_95 = F_53 ( V_11 -> V_95 - 2 * V_3 , 2U ) ;
V_97 -> V_101 = V_97 -> V_95 > 1
? ( V_11 -> V_74 -> V_102 >= 3 ? 0x04 : 0xf0 )
: 0 ;
if ( ! F_15 ( V_11 , V_33 ) ) {
V_32 = F_54 ( V_97 ) ;
if ( V_32 < 0 )
return V_32 ;
}
}
if ( F_15 ( V_11 , V_33 ) ) {
for ( V_3 = 0 ; V_3 < V_11 -> V_95 ; ++ V_3 ) {
struct V_103 * V_104 = & V_11 -> V_105 [ V_3 ] ;
V_104 -> V_100 = V_3 ;
V_104 -> V_8 = V_11 ;
V_11 -> V_40 [ V_3 ] . V_104 = V_104 ;
V_32 = F_55 ( V_104 ) ;
if ( V_32 < 0 )
return V_32 ;
}
}
for ( V_3 = 0 ; V_3 < V_11 -> V_95 ; ++ V_3 ) {
struct V_96 * V_97 = & V_11 -> V_98 [ V_3 / 2 ] ;
V_32 = F_56 ( V_97 , V_3 ) ;
if ( V_32 < 0 )
return V_32 ;
}
V_32 = F_57 ( V_11 ) ;
if ( V_32 < 0 )
return V_32 ;
V_32 = F_46 ( V_11 ) ;
if ( V_32 < 0 )
return V_32 ;
if ( V_32 == 0 ) {
F_58 ( V_11 -> V_8 , L_16 ) ;
return - V_26 ;
}
V_72 = V_32 ;
F_59 (encoder, &dev->mode_config.encoder_list, head) {
struct V_106 * V_107 = F_60 ( V_62 ) ;
const struct V_108 * V_109 =
& V_11 -> V_74 -> V_75 [ V_107 -> V_49 ] ;
V_62 -> V_76 = V_109 -> V_76 ;
V_62 -> V_110 = ( 1 << V_72 ) - 1 ;
}
F_61 ( V_8 ) ;
F_62 ( V_8 ) ;
if ( V_8 -> V_46 . V_111 ) {
V_29 = F_63 ( V_8 , 32 , V_8 -> V_46 . V_47 ,
V_8 -> V_46 . V_111 ) ;
if ( F_64 ( V_29 ) )
return F_65 ( V_29 ) ;
V_11 -> V_29 = V_29 ;
} else {
F_66 ( V_11 -> V_8 ,
L_17 ) ;
}
return 0 ;
}
