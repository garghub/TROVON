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
F_8 ( V_11 -> V_8 , L_4 , V_52 ,
V_31 -> V_53 -> V_50 , V_31 - V_31 -> V_53 -> V_27 ) ;
if ( ! V_49 -> V_23 ) {
F_8 ( V_11 -> V_8 , L_5 ,
V_52 ) ;
V_50 = V_31 - V_31 -> V_53 -> V_27 ;
V_41 [ V_31 -> V_53 -> V_50 ] |= 1 << V_50 ;
V_49 -> V_36 = - 1 ;
continue;
}
if ( F_13 ( V_31 , V_49 ) ) {
F_8 ( V_11 -> V_8 , L_6 ,
V_52 ) ;
V_45 |= 1 << V_31 -> V_53 -> V_50 ;
V_44 = true ;
V_50 = V_31 - V_31 -> V_53 -> V_27 ;
V_41 [ V_31 -> V_53 -> V_50 ] |= 1 << V_50 ;
V_49 -> V_36 = - 1 ;
}
}
if ( ! V_44 )
return 0 ;
while ( V_45 ) {
unsigned int V_50 = F_20 ( V_45 ) - 1 ;
struct V_54 * V_53 = & V_11 -> V_45 [ V_50 ] ;
unsigned int V_55 = 0 ;
F_8 ( V_11 -> V_8 , L_7 ,
V_52 , V_50 ) ;
for ( V_3 = 0 ; V_3 < V_53 -> V_37 ; ++ V_3 ) {
struct V_30 * V_31 = & V_53 -> V_27 [ V_3 ] ;
struct V_32 * V_49 ;
struct V_56 * V_57 ;
V_57 = F_21 ( V_33 , & V_31 -> V_31 ) ;
if ( F_22 ( V_57 ) )
return F_23 ( V_57 ) ;
if ( V_41 [ V_50 ] & ( 1 << V_3 ) ) {
F_8 ( V_11 -> V_8 ,
L_8 ,
V_52 , V_31 -> V_53 -> V_50 ,
V_31 - V_31 -> V_53 -> V_27 ) ;
continue;
}
V_49 = F_14 ( V_31 -> V_31 . V_33 ) ;
V_55 |= F_15 ( V_49 ) ;
F_8 ( V_11 -> V_8 ,
L_9 ,
V_52 , V_31 -> V_53 -> V_50 ,
V_31 - V_31 -> V_53 -> V_27 ,
V_49 -> V_23 ?
V_49 -> V_23 -> V_27 : 0 ,
V_49 -> V_36 ) ;
}
V_43 [ V_50 ] = 0xff & ~ V_55 ;
V_45 &= ~ ( 1 << V_50 ) ;
F_8 ( V_11 -> V_8 , L_10 ,
V_52 , V_50 , V_43 [ V_50 ] ) ;
}
for ( V_3 = 0 ; V_3 < V_8 -> V_47 . V_48 ; ++ V_3 ) {
struct V_32 * V_49 ;
struct V_30 * V_31 ;
unsigned int V_58 ;
unsigned int free ;
int V_59 ;
if ( ! V_33 -> V_27 [ V_3 ] )
continue;
V_31 = F_19 ( V_33 -> V_27 [ V_3 ] ) ;
V_49 = F_14 ( V_33 -> V_51 [ V_3 ] ) ;
F_8 ( V_11 -> V_8 , L_11 , V_52 ,
V_31 -> V_53 -> V_50 , V_31 - V_31 -> V_53 -> V_27 ) ;
if ( ! V_49 -> V_23 ||
! F_13 ( V_31 , V_49 ) )
continue;
V_58 = F_24 ( V_49 -> V_33 . V_60 ) -> V_50 % 2
? V_31 -> V_53 -> V_61
: ~ V_31 -> V_53 -> V_61 ;
free = V_43 [ V_31 -> V_53 -> V_50 ] ;
V_59 = F_16 ( V_49 -> V_23 -> V_27 ,
free & V_58 ) ;
if ( V_59 < 0 )
V_59 = F_16 ( V_49 -> V_23 -> V_27 ,
free ) ;
if ( V_59 < 0 ) {
F_8 ( V_11 -> V_8 , L_12 ,
V_52 ) ;
return V_59 ;
}
F_8 ( V_11 -> V_8 , L_13 ,
V_52 , V_49 -> V_23 -> V_27 , V_59 ) ;
V_49 -> V_36 = V_59 ;
V_43 [ V_31 -> V_53 -> V_50 ] &=
~ F_15 ( V_49 ) ;
F_8 ( V_11 -> V_8 , L_10 ,
V_52 , V_31 -> V_53 -> V_50 ,
V_43 [ V_31 -> V_53 -> V_50 ] ) ;
}
return 0 ;
}
static void F_25 ( struct V_62 * V_63 )
{
struct V_7 * V_8 = V_63 -> V_8 ;
struct V_10 * V_11 = V_8 -> V_12 ;
struct V_40 * V_64 = V_63 -> V_33 ;
F_26 ( V_8 , V_64 ) ;
F_27 ( V_8 , V_64 ) ;
F_28 ( V_8 , V_64 , false ) ;
F_29 ( V_8 , V_64 ) ;
F_30 ( V_8 , V_64 ) ;
F_31 ( V_64 ) ;
F_32 ( & V_11 -> V_63 . V_65 . V_66 ) ;
V_11 -> V_63 . V_67 &= ~ V_63 -> V_68 ;
F_33 ( & V_11 -> V_63 . V_65 ) ;
F_34 ( & V_11 -> V_63 . V_65 . V_66 ) ;
F_35 ( V_63 ) ;
}
static void F_36 ( struct V_69 * V_70 )
{
struct V_62 * V_63 =
F_37 ( V_70 , struct V_62 , V_70 ) ;
F_25 ( V_63 ) ;
}
static int F_38 ( struct V_7 * V_8 ,
struct V_40 * V_33 , bool V_71 )
{
struct V_10 * V_11 = V_8 -> V_12 ;
struct V_62 * V_63 ;
unsigned int V_3 ;
int V_46 ;
V_46 = F_39 ( V_8 , V_33 ) ;
if ( V_46 )
return V_46 ;
V_63 = F_40 ( sizeof( * V_63 ) , V_72 ) ;
if ( V_63 == NULL ) {
V_46 = - V_73 ;
goto error;
}
F_41 ( & V_63 -> V_70 , F_36 ) ;
V_63 -> V_8 = V_8 ;
V_63 -> V_33 = V_33 ;
for ( V_3 = 0 ; V_3 < V_8 -> V_47 . V_74 ; ++ V_3 ) {
if ( V_33 -> V_68 [ V_3 ] )
V_63 -> V_68 |= 1 << F_42 ( V_33 -> V_68 [ V_3 ] ) ;
}
F_32 ( & V_11 -> V_63 . V_65 . V_66 ) ;
V_46 = F_43 ( V_11 -> V_63 . V_65 ,
! ( V_11 -> V_63 . V_67 & V_63 -> V_68 ) ) ;
if ( V_46 == 0 )
V_11 -> V_63 . V_67 |= V_63 -> V_68 ;
F_34 ( & V_11 -> V_63 . V_65 . V_66 ) ;
if ( V_46 ) {
F_35 ( V_63 ) ;
goto error;
}
F_44 ( V_8 , V_33 ) ;
if ( V_71 )
F_45 ( & V_63 -> V_70 ) ;
else
F_25 ( V_63 ) ;
return 0 ;
error:
F_30 ( V_8 , V_33 ) ;
return V_46 ;
}
static int F_46 ( struct V_10 * V_11 ,
enum V_75 V_76 ,
struct V_77 * V_78 )
{
static const struct {
const char * V_79 ;
enum V_80 type ;
} V_81 [] = {
{ L_14 , V_82 } ,
{ L_15 , V_83 } ,
{ L_16 , V_84 } ,
} ;
enum V_80 V_85 = V_86 ;
struct V_87 * V_88 = NULL ;
struct V_87 * V_89 = NULL ;
struct V_87 * V_90 = NULL ;
struct V_87 * V_91 ;
struct V_87 * V_92 ;
int V_46 ;
V_92 = F_47 ( V_78 -> V_93 ) ;
if ( ! V_92 ) {
F_8 ( V_11 -> V_8 , L_17 ,
V_78 -> V_93 -> V_94 ) ;
return - V_95 ;
}
V_91 = F_48 ( V_78 -> V_93 , L_18 , 0 ) ;
F_49 (entity, ep_node) {
if ( V_90 == V_91 )
continue;
V_89 = V_92 ;
V_88 = F_47 ( V_90 ) ;
F_50 ( V_90 ) ;
if ( ! V_88 ) {
F_51 ( V_11 -> V_8 ,
L_19 ,
V_89 -> V_94 ) ;
F_50 ( V_91 ) ;
F_50 ( V_89 ) ;
return - V_95 ;
}
break;
}
F_50 ( V_91 ) ;
if ( V_89 ) {
unsigned int V_3 ;
for ( V_3 = 0 ; V_3 < F_1 ( V_81 ) ; ++ V_3 ) {
if ( F_52 ( V_89 ,
V_81 [ V_3 ] . V_79 ) ) {
V_85 = V_81 [ V_3 ] . type ;
break;
}
}
if ( V_3 == F_1 ( V_81 ) ) {
F_51 ( V_11 -> V_8 ,
L_20 ,
V_89 -> V_94 ) ;
F_50 ( V_89 ) ;
F_50 ( V_88 ) ;
return - V_26 ;
}
} else {
V_88 = V_92 ;
}
V_46 = F_53 ( V_11 , V_85 , V_76 , V_89 , V_88 ) ;
F_50 ( V_89 ) ;
F_50 ( V_88 ) ;
if ( V_46 && V_46 != - V_96 )
F_51 ( V_11 -> V_8 ,
L_21 ,
V_89 -> V_94 , V_46 ) ;
return V_46 ;
}
static int F_54 ( struct V_10 * V_11 )
{
struct V_87 * V_97 = V_11 -> V_8 -> V_98 ;
struct V_87 * V_90 ;
unsigned int V_99 = 0 ;
F_49 (np, ep_node) {
enum V_75 V_76 ;
struct V_77 V_78 ;
unsigned int V_3 ;
int V_46 ;
V_46 = F_55 ( V_90 , & V_78 ) ;
if ( V_46 < 0 ) {
F_50 ( V_90 ) ;
return V_46 ;
}
for ( V_3 = 0 ; V_3 < V_100 ; ++ V_3 ) {
if ( V_11 -> V_101 -> V_102 [ V_3 ] . V_103 &&
V_11 -> V_101 -> V_102 [ V_3 ] . V_104 == V_78 . V_104 ) {
V_76 = V_3 ;
break;
}
}
if ( V_3 == V_100 ) {
F_51 ( V_11 -> V_8 ,
L_22 ,
V_78 . V_104 ) ;
continue;
}
V_46 = F_46 ( V_11 , V_76 , & V_78 ) ;
if ( V_46 < 0 ) {
if ( V_46 == - V_96 ) {
F_50 ( V_90 ) ;
return V_46 ;
}
continue;
}
V_99 ++ ;
}
return V_99 ;
}
static int F_56 ( struct V_10 * V_11 )
{
V_11 -> V_105 . V_106 =
F_57 ( V_11 -> V_107 , 0 , L_23 , 0 , 255 ) ;
if ( V_11 -> V_105 . V_106 == NULL )
return - V_73 ;
V_11 -> V_105 . V_108 =
F_57 ( V_11 -> V_107 , 0 , L_24 ,
0 , 0x01ffffff ) ;
if ( V_11 -> V_105 . V_108 == NULL )
return - V_73 ;
V_11 -> V_105 . V_109 =
F_57 ( V_11 -> V_107 , 0 , L_25 , 1 , 7 ) ;
if ( V_11 -> V_105 . V_109 == NULL )
return - V_73 ;
return 0 ;
}
int F_58 ( struct V_10 * V_11 )
{
static const unsigned int V_110 [] = {
V_111 , V_112
} ;
struct V_7 * V_8 = V_11 -> V_107 ;
struct V_113 * V_89 ;
struct V_114 * V_29 ;
unsigned int V_99 ;
unsigned int V_115 ;
unsigned int V_3 ;
int V_46 ;
F_59 ( V_8 ) ;
V_8 -> V_47 . V_116 = 0 ;
V_8 -> V_47 . V_117 = 0 ;
V_8 -> V_47 . V_118 = 4095 ;
V_8 -> V_47 . V_119 = 2047 ;
V_8 -> V_47 . V_120 = & V_121 ;
V_11 -> V_122 = V_11 -> V_101 -> V_122 ;
V_46 = F_56 ( V_11 ) ;
if ( V_46 < 0 )
return V_46 ;
V_115 = F_3 ( V_11 -> V_122 , 2 ) ;
for ( V_3 = 0 ; V_3 < V_115 ; ++ V_3 ) {
struct V_54 * V_123 = & V_11 -> V_45 [ V_3 ] ;
F_60 ( & V_123 -> V_66 ) ;
V_123 -> V_8 = V_11 ;
V_123 -> V_124 = V_110 [ V_3 ] ;
V_123 -> V_50 = V_3 ;
V_123 -> V_122 = F_61 ( V_11 -> V_122 - 2 * V_3 , 2U ) ;
V_123 -> V_61 = V_123 -> V_122 > 1 ? 0xf0 : 0 ;
V_46 = F_62 ( V_123 ) ;
if ( V_46 < 0 )
return V_46 ;
}
for ( V_3 = 0 ; V_3 < V_11 -> V_122 ; ++ V_3 ) {
struct V_54 * V_123 = & V_11 -> V_45 [ V_3 / 2 ] ;
V_46 = F_63 ( V_123 , V_3 ) ;
if ( V_46 < 0 )
return V_46 ;
}
V_46 = F_64 ( V_11 ) ;
if ( V_46 < 0 )
return V_46 ;
V_46 = F_54 ( V_11 ) ;
if ( V_46 < 0 )
return V_46 ;
if ( V_46 == 0 ) {
F_65 ( V_11 -> V_8 , L_26 ) ;
return - V_26 ;
}
V_99 = V_46 ;
F_66 (encoder, &dev->mode_config.encoder_list, head) {
struct V_125 * V_126 = F_67 ( V_89 ) ;
const struct V_127 * V_128 =
& V_11 -> V_101 -> V_102 [ V_126 -> V_76 ] ;
V_89 -> V_103 = V_128 -> V_103 ;
V_89 -> V_129 = ( 1 << V_99 ) - 1 ;
}
F_68 ( V_8 ) ;
F_69 ( V_8 ) ;
if ( V_8 -> V_47 . V_130 ) {
V_29 = F_70 ( V_8 , 32 , V_8 -> V_47 . V_74 ,
V_8 -> V_47 . V_130 ) ;
if ( F_22 ( V_29 ) )
return F_23 ( V_29 ) ;
V_11 -> V_29 = V_29 ;
} else {
F_71 ( V_11 -> V_8 ,
L_27 ) ;
}
return 0 ;
}
