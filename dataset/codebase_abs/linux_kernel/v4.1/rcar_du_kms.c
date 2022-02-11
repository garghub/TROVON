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
struct V_21 * V_22 )
{
struct V_10 * V_11 = V_8 -> V_12 ;
const struct V_1 * V_23 ;
unsigned int V_24 ;
unsigned int V_16 ;
unsigned int V_15 ;
V_23 = V_1 ( V_22 -> V_25 ) ;
if ( V_23 == NULL ) {
F_8 ( V_8 -> V_8 , L_1 ,
V_22 -> V_25 ) ;
return F_9 ( - V_26 ) ;
}
V_15 = V_23 -> V_27 == 2 ? 1 : V_23 -> V_15 / 8 ;
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
if ( V_23 -> V_27 == 2 ) {
if ( V_22 -> V_28 [ 1 ] != V_22 -> V_28 [ 0 ] ) {
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
static bool F_13 ( struct V_30 * V_31 ,
struct V_32 * V_33 )
{
const struct V_1 * V_34 ;
V_34 = F_14 ( V_31 -> V_31 . V_33 ) -> V_23 ;
return ! V_34 || V_34 -> V_27 != V_33 -> V_23 -> V_27 ;
}
static unsigned int F_15 ( struct V_32 * V_33 )
{
unsigned int V_35 ;
if ( V_33 -> V_36 == - 1 )
return 0 ;
V_35 = 1 << V_33 -> V_36 ;
if ( V_33 -> V_23 -> V_27 == 2 )
V_35 |= 1 << ( ( V_33 -> V_36 + 1 ) % 8 ) ;
return V_35 ;
}
static int F_16 ( unsigned int V_37 , unsigned int free )
{
unsigned int V_3 ;
for ( V_3 = 0 ; V_3 < V_38 ; ++ V_3 ) {
if ( ! ( free & ( 1 << V_3 ) ) )
continue;
if ( V_37 == 1 || free & ( 1 << ( ( V_3 + 1 ) % 8 ) ) )
break;
}
return V_3 == V_38 ? - V_39 : V_3 ;
}
static int F_17 ( struct V_7 * V_8 ,
struct V_40 * V_33 )
{
struct V_10 * V_11 = V_8 -> V_12 ;
unsigned int V_41 [ V_42 ] = { 0 , } ;
unsigned int V_43 [ V_42 ] = { 0 , } ;
bool V_44 = false ;
unsigned int V_45 = 0 ;
unsigned int V_3 ;
int V_46 ;
V_46 = F_18 ( V_8 , V_33 ) ;
if ( V_46 < 0 )
return V_46 ;
for ( V_3 = 0 ; V_3 < V_8 -> V_47 . V_48 ; ++ V_3 ) {
struct V_32 * V_49 ;
struct V_30 * V_31 ;
unsigned int V_50 ;
if ( ! V_33 -> V_27 [ V_3 ] )
continue;
V_31 = F_19 ( V_33 -> V_27 [ V_3 ] ) ;
V_49 = F_14 ( V_33 -> V_51 [ V_3 ] ) ;
if ( ! V_49 -> V_23 ) {
V_50 = V_31 - V_31 -> V_52 -> V_27 . V_27 ;
V_41 [ V_31 -> V_52 -> V_50 ] |= 1 << V_50 ;
V_49 -> V_36 = - 1 ;
continue;
}
if ( F_13 ( V_31 , V_49 ) ) {
V_45 |= 1 << V_31 -> V_52 -> V_50 ;
V_44 = true ;
V_50 = V_31 - V_31 -> V_52 -> V_27 . V_27 ;
V_41 [ V_31 -> V_52 -> V_50 ] |= 1 << V_50 ;
V_49 -> V_36 = - 1 ;
}
}
if ( ! V_44 )
return 0 ;
while ( V_45 ) {
unsigned int V_50 = F_20 ( V_45 ) - 1 ;
struct V_53 * V_52 = & V_11 -> V_45 [ V_50 ] ;
unsigned int V_54 = 0 ;
for ( V_3 = 0 ; V_3 < V_55 ; ++ V_3 ) {
struct V_30 * V_31 = & V_52 -> V_27 . V_27 [ V_3 ] ;
struct V_32 * V_49 ;
struct V_56 * V_57 ;
V_57 = F_21 ( V_33 , & V_31 -> V_31 ) ;
if ( F_22 ( V_57 ) )
return F_23 ( V_57 ) ;
if ( V_41 [ V_50 ] & ( 1 << V_3 ) )
continue;
V_49 = F_14 ( V_31 -> V_31 . V_33 ) ;
V_54 |= F_15 ( V_49 ) ;
}
V_43 [ V_50 ] = 0xff & ~ V_54 ;
V_45 &= ~ ( 1 << V_50 ) ;
}
for ( V_3 = 0 ; V_3 < V_8 -> V_47 . V_48 ; ++ V_3 ) {
struct V_32 * V_49 ;
struct V_30 * V_31 ;
int V_58 ;
if ( ! V_33 -> V_27 [ V_3 ] )
continue;
V_31 = F_19 ( V_33 -> V_27 [ V_3 ] ) ;
V_49 = F_14 ( V_33 -> V_51 [ V_3 ] ) ;
if ( ! V_49 -> V_23 ||
! F_13 ( V_31 , V_49 ) )
continue;
V_58 = F_16 ( V_49 -> V_23 -> V_27 ,
V_43 [ V_31 -> V_52 -> V_50 ] ) ;
if ( V_58 < 0 ) {
F_8 ( V_11 -> V_8 , L_4 ,
V_59 ) ;
return V_58 ;
}
V_49 -> V_36 = V_58 ;
V_43 [ V_31 -> V_52 -> V_50 ] &=
~ F_15 ( V_49 ) ;
}
return 0 ;
}
static void F_24 ( struct V_60 * V_61 )
{
struct V_7 * V_8 = V_61 -> V_8 ;
struct V_10 * V_11 = V_8 -> V_12 ;
struct V_40 * V_62 = V_61 -> V_33 ;
F_25 ( V_8 , V_62 ) ;
F_26 ( V_8 , V_62 ) ;
F_27 ( V_8 , V_62 ) ;
F_28 ( V_8 , V_62 ) ;
F_29 ( V_8 , V_62 ) ;
F_30 ( V_62 ) ;
F_31 ( & V_11 -> V_61 . V_63 . V_64 ) ;
V_11 -> V_61 . V_65 &= ~ V_61 -> V_66 ;
F_32 ( & V_11 -> V_61 . V_63 ) ;
F_33 ( & V_11 -> V_61 . V_63 . V_64 ) ;
F_34 ( V_61 ) ;
}
static void F_35 ( struct V_67 * V_68 )
{
struct V_60 * V_61 =
F_36 ( V_68 , struct V_60 , V_68 ) ;
F_24 ( V_61 ) ;
}
static int F_37 ( struct V_7 * V_8 ,
struct V_40 * V_33 , bool V_69 )
{
struct V_10 * V_11 = V_8 -> V_12 ;
struct V_60 * V_61 ;
unsigned int V_3 ;
int V_46 ;
V_46 = F_38 ( V_8 , V_33 ) ;
if ( V_46 )
return V_46 ;
V_61 = F_39 ( sizeof( * V_61 ) , V_70 ) ;
if ( V_61 == NULL )
return - V_71 ;
F_40 ( & V_61 -> V_68 , F_35 ) ;
V_61 -> V_8 = V_8 ;
V_61 -> V_33 = V_33 ;
for ( V_3 = 0 ; V_3 < V_8 -> V_47 . V_72 ; ++ V_3 ) {
if ( V_33 -> V_66 [ V_3 ] )
V_61 -> V_66 |= 1 << F_41 ( V_33 -> V_66 [ V_3 ] ) ;
}
F_31 ( & V_11 -> V_61 . V_63 . V_64 ) ;
V_46 = F_42 ( V_11 -> V_61 . V_63 ,
! ( V_11 -> V_61 . V_65 & V_61 -> V_66 ) ) ;
if ( V_46 == 0 )
V_11 -> V_61 . V_65 |= V_61 -> V_66 ;
F_33 ( & V_11 -> V_61 . V_63 . V_64 ) ;
if ( V_46 ) {
F_34 ( V_61 ) ;
return V_46 ;
}
F_43 ( V_8 , V_33 ) ;
if ( V_69 )
F_44 ( & V_61 -> V_68 ) ;
else
F_24 ( V_61 ) ;
return 0 ;
}
static int F_45 ( struct V_10 * V_11 ,
enum V_73 V_74 ,
struct V_75 * V_76 )
{
static const struct {
const char * V_77 ;
enum V_78 type ;
} V_79 [] = {
{ L_5 , V_80 } ,
{ L_6 , V_81 } ,
{ L_7 , V_82 } ,
} ;
enum V_78 V_83 = V_84 ;
struct V_85 * V_86 = NULL ;
struct V_85 * V_87 = NULL ;
struct V_85 * V_88 = NULL ;
struct V_85 * V_89 ;
struct V_85 * V_90 ;
int V_46 ;
V_90 = F_46 ( V_76 -> V_91 ) ;
if ( ! V_90 ) {
F_8 ( V_11 -> V_8 , L_8 ,
V_76 -> V_91 -> V_92 ) ;
return 0 ;
}
V_89 = F_47 ( V_76 -> V_91 , L_9 , 0 ) ;
F_48 (entity, ep_node) {
if ( V_88 == V_89 )
continue;
V_87 = V_90 ;
V_86 = F_46 ( V_88 ) ;
F_49 ( V_88 ) ;
if ( ! V_86 ) {
F_50 ( V_11 -> V_8 ,
L_10 ,
V_87 -> V_92 ) ;
F_49 ( V_89 ) ;
F_49 ( V_87 ) ;
return 0 ;
}
break;
}
F_49 ( V_89 ) ;
if ( V_87 ) {
unsigned int V_3 ;
for ( V_3 = 0 ; V_3 < F_1 ( V_79 ) ; ++ V_3 ) {
if ( F_51 ( V_87 ,
V_79 [ V_3 ] . V_77 ) ) {
V_83 = V_79 [ V_3 ] . type ;
break;
}
}
if ( V_3 == F_1 ( V_79 ) ) {
F_50 ( V_11 -> V_8 ,
L_11 ,
V_87 -> V_92 ) ;
F_49 ( V_87 ) ;
F_49 ( V_86 ) ;
return 0 ;
}
} else {
V_86 = V_90 ;
}
V_46 = F_52 ( V_11 , V_83 , V_74 , V_87 , V_86 ) ;
F_49 ( V_87 ) ;
F_49 ( V_86 ) ;
return V_46 < 0 ? V_46 : 1 ;
}
static int F_53 ( struct V_10 * V_11 )
{
struct V_85 * V_93 = V_11 -> V_8 -> V_94 ;
struct V_85 * V_88 ;
unsigned int V_95 = 0 ;
F_48 (np, ep_node) {
enum V_73 V_74 ;
struct V_75 V_76 ;
unsigned int V_3 ;
int V_46 ;
V_46 = F_54 ( V_88 , & V_76 ) ;
if ( V_46 < 0 ) {
F_49 ( V_88 ) ;
return V_46 ;
}
for ( V_3 = 0 ; V_3 < V_96 ; ++ V_3 ) {
if ( V_11 -> V_97 -> V_98 [ V_3 ] . V_99 &&
V_11 -> V_97 -> V_98 [ V_3 ] . V_100 == V_76 . V_100 ) {
V_74 = V_3 ;
break;
}
}
if ( V_3 == V_96 ) {
F_50 ( V_11 -> V_8 ,
L_12 ,
V_76 . V_100 ) ;
continue;
}
V_46 = F_45 ( V_11 , V_74 , & V_76 ) ;
if ( V_46 < 0 ) {
if ( V_46 == - V_101 ) {
F_49 ( V_88 ) ;
return V_46 ;
}
F_55 ( V_11 -> V_8 ,
L_13 ) ;
continue;
}
V_95 += V_46 ;
}
return V_95 ;
}
int F_56 ( struct V_10 * V_11 )
{
static const unsigned int V_102 [] = {
V_103 , V_104
} ;
struct V_7 * V_8 = V_11 -> V_105 ;
struct V_106 * V_87 ;
struct V_107 * V_29 ;
unsigned int V_95 ;
unsigned int V_108 ;
unsigned int V_3 ;
int V_46 ;
F_57 ( V_8 ) ;
V_8 -> V_47 . V_109 = 0 ;
V_8 -> V_47 . V_110 = 0 ;
V_8 -> V_47 . V_111 = 4095 ;
V_8 -> V_47 . V_112 = 2047 ;
V_8 -> V_47 . V_113 = & V_114 ;
V_11 -> V_115 = V_11 -> V_97 -> V_115 ;
V_108 = F_3 ( V_11 -> V_115 , 2 ) ;
for ( V_3 = 0 ; V_3 < V_108 ; ++ V_3 ) {
struct V_53 * V_116 = & V_11 -> V_45 [ V_3 ] ;
F_58 ( & V_116 -> V_64 ) ;
V_116 -> V_8 = V_11 ;
V_116 -> V_117 = V_102 [ V_3 ] ;
V_116 -> V_50 = V_3 ;
V_46 = F_59 ( V_116 ) ;
if ( V_46 < 0 )
return V_46 ;
}
for ( V_3 = 0 ; V_3 < V_11 -> V_115 ; ++ V_3 ) {
struct V_53 * V_116 = & V_11 -> V_45 [ V_3 / 2 ] ;
V_46 = F_60 ( V_116 , V_3 ) ;
if ( V_46 < 0 )
return V_46 ;
}
V_46 = F_61 ( V_11 ) ;
if ( V_46 < 0 )
return V_46 ;
V_46 = F_53 ( V_11 ) ;
if ( V_46 < 0 )
return V_46 ;
if ( V_46 == 0 ) {
F_62 ( V_11 -> V_8 , L_14 ) ;
return - V_26 ;
}
V_95 = V_46 ;
F_63 (encoder, &dev->mode_config.encoder_list, head) {
struct V_118 * V_119 = F_64 ( V_87 ) ;
const struct V_120 * V_121 =
& V_11 -> V_97 -> V_98 [ V_119 -> V_74 ] ;
V_87 -> V_99 = V_121 -> V_99 ;
V_87 -> V_122 = ( 1 << V_95 ) - 1 ;
}
F_65 ( V_8 ) ;
F_66 ( V_8 ) ;
if ( V_8 -> V_47 . V_123 ) {
V_29 = F_67 ( V_8 , 32 , V_8 -> V_47 . V_72 ,
V_8 -> V_47 . V_123 ) ;
if ( F_22 ( V_29 ) )
return F_23 ( V_29 ) ;
V_11 -> V_29 = V_29 ;
} else {
F_55 ( V_11 -> V_8 ,
L_15 ) ;
}
return 0 ;
}
