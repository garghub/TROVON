static struct V_1 *
F_1 ( struct V_2 * V_3 ,
enum V_4 V_5 )
{
struct V_6 * V_7 = V_6 ( V_3 ) ;
const struct V_8 * V_9 = V_7 -> V_10 . V_11 -> V_12 ;
switch ( V_5 ) {
case V_13 :
return & V_7 -> V_3 [ V_14 ] ;
case V_15 :
return & V_7 -> V_3 [ V_16 ] ;
default:
F_2 ( V_9 , L_1 ) ;
return F_3 ( - V_17 ) ;
}
}
static void
F_4 ( struct V_2 * V_3 )
{
struct V_6 * V_7 = V_6 ( V_3 ) ;
struct V_1 * V_18 =
& V_7 -> V_3 [ V_19 ] ;
F_5 ( & V_7 -> V_10 , V_18 ) ;
}
static void
F_6 ( struct V_2 * V_3 , void * V_20 )
{
struct {
T_1 V_21 ;
T_1 V_22 ;
T_1 V_23 ;
T_1 V_24 ;
T_2 V_25 ;
T_3 V_26 ;
T_1 V_27 ;
bool V_28 ;
bool V_29 ;
struct {
T_1 V_30 ;
T_2 V_31 ;
T_3 V_32 ;
T_2 V_33 ;
T_3 V_34 ;
} V_35 ;
T_3 V_36 ;
} * args = V_20 ;
args -> V_28 = 1 ;
}
static int
F_7 ( struct V_2 * V_37 , struct V_38 * V_39 )
{
struct V_6 * V_7 = V_6 ( V_37 ) ;
struct {
struct V_40 V_10 ;
T_3 V_36 ;
T_2 V_41 ;
struct {
T_2 V_42 ;
T_2 V_43 ;
T_3 V_44 ;
T_3 V_36 ;
} V_45 [ V_46 ] ;
T_2 V_47 ;
T_2 V_48 ;
} * V_49 = ( void * ) V_39 ;
const struct V_8 * V_9 = V_37 -> V_11 -> V_12 ;
int V_50 ;
if ( V_49 -> V_10 . V_39 . V_51 != V_52 ) {
F_2 ( V_9 , L_2 ) ;
return - V_17 ;
}
if ( V_49 -> V_10 . V_53 != V_54 ) {
F_2 ( V_9 , L_3 ) ;
return - V_17 ;
}
for ( V_50 = 0 ; V_50 < V_46 ; V_50 ++ ) {
struct V_1 * V_3 = & V_7 -> V_3 [ V_50 ] ;
F_8 ( & V_3 -> V_55 ) ;
V_3 -> V_44 = V_49 -> V_45 [ V_50 ] . V_44 ;
V_3 -> V_43 = V_49 -> V_45 [ V_50 ] . V_43 ;
V_3 -> V_42 = V_49 -> V_45 [ V_50 ] . V_42 ;
if ( V_50 != V_19 ) {
V_3 -> V_56 = 0x4a0 + ( V_3 -> V_44 * 4 ) ;
V_3 -> V_57 = 0x4b0 + ( V_3 -> V_44 * 4 ) ;
} else {
V_3 -> V_56 = 0x4c8 ;
V_3 -> V_57 = 0x4cc ;
}
F_9 ( V_9 ,
L_4 ,
V_50 , V_3 -> V_44 , V_3 -> V_43 , V_3 -> V_42 ) ;
}
return F_10 ( & V_7 -> V_10 ) ;
}
static void
F_11 ( struct V_2 * V_3 ,
struct V_38 * V_39 )
{
struct {
struct V_40 V_10 ;
T_1 V_58 ;
} * V_59 = ( void * ) V_39 ;
const struct V_8 * V_9 = V_3 -> V_11 -> V_12 ;
if ( V_59 -> V_58 ) {
F_2 ( V_9 , L_5 ,
V_59 -> V_58 ) ;
return;
}
F_9 ( V_9 , L_6 ) ;
F_12 ( & V_3 -> V_60 ) ;
}
static int
F_10 ( struct V_2 * V_3 )
{
struct {
struct V_38 V_39 ;
T_3 V_61 ;
T_1 V_62 ;
T_1 V_63 ;
} V_64 ;
memset ( & V_64 , 0 , sizeof( V_64 ) ) ;
V_64 . V_39 . V_51 = V_65 ;
V_64 . V_39 . V_42 = sizeof( V_64 ) ;
V_64 . V_61 = V_66 ;
V_64 . V_62 = 0x01 ;
V_64 . V_63 = 0x00 ;
F_13 ( V_3 , V_13 , & V_64 . V_39 ,
F_11 , NULL , false ) ;
return 0 ;
}
static void
F_14 ( struct V_2 * V_7 ,
struct V_38 * V_39 )
{
struct V_67 {
struct V_40 V_10 ;
T_1 V_68 ;
} * V_59 = ( void * ) V_39 ;
const struct V_8 * V_9 = V_7 -> V_11 -> V_12 ;
T_1 V_68 = V_59 -> V_68 ;
if ( V_68 >= V_69 ) {
F_2 ( V_9 , L_7 ) ;
F_2 ( V_9 , L_8 , V_68 ) ;
return;
}
F_9 ( V_9 , L_9 , V_70 [ V_68 ] ) ;
}
static int
F_15 ( struct V_2 * V_7 , enum V_71 V_11 )
{
F_16 ( V_72 ) ;
struct {
struct V_38 V_39 ;
T_3 V_61 ;
T_1 V_73 ;
T_1 V_68 ;
} V_64 ;
memset ( & V_64 , 0 , sizeof( V_64 ) ) ;
V_64 . V_39 . V_51 = V_65 ;
V_64 . V_39 . V_42 = sizeof( V_64 ) ;
V_64 . V_61 = V_74 ;
V_64 . V_73 = V_75 ;
V_64 . V_68 = V_11 ;
F_13 ( V_7 , V_13 , & V_64 . V_39 ,
F_14 , & V_72 , true ) ;
if ( ! F_17 ( & V_72 , F_18 ( 1000 ) ) )
return - V_76 ;
return 0 ;
}
static void
F_19 ( struct V_2 * V_7 ,
struct V_38 * V_39 )
{
struct V_67 {
struct V_40 V_10 ;
T_1 V_77 ;
} * V_59 = ( void * ) V_39 ;
const struct V_8 * V_9 = V_7 -> V_11 -> V_12 ;
unsigned long V_77 = V_59 -> V_77 ;
T_1 V_68 , V_78 = 0 ;
F_20 (falcon_id, &falcon_mask, NVKM_SECBOOT_FALCON_END) {
F_9 ( V_9 , L_9 ,
V_70 [ V_68 ] ) ;
V_78 |= F_21 ( V_68 ) ;
}
if ( V_78 != V_59 -> V_77 ) {
F_2 ( V_9 , L_7 ) ;
F_2 ( V_9 , L_10 ,
V_59 -> V_77 ) ;
return;
}
}
static int
F_22 ( struct V_2 * V_7 , unsigned long V_77 )
{
F_16 ( V_72 ) ;
struct {
struct V_38 V_39 ;
T_3 V_61 ;
T_1 V_73 ;
T_1 V_77 ;
T_1 V_79 ;
T_1 V_80 ;
T_1 V_81 ;
} V_64 ;
struct V_82 * V_3 = V_82 ( V_7 ) ;
memset ( & V_64 , 0 , sizeof( V_64 ) ) ;
V_64 . V_39 . V_51 = V_65 ;
V_64 . V_39 . V_42 = sizeof( V_64 ) ;
V_64 . V_61 = V_83 ;
V_64 . V_73 = V_75 ;
V_64 . V_77 = V_77 ;
V_64 . V_80 = F_23 ( V_3 -> V_84 ) ;
V_64 . V_81 = F_24 ( V_3 -> V_84 ) ;
F_13 ( V_7 , V_13 , & V_64 . V_39 ,
F_19 , & V_72 , true ) ;
if ( ! F_17 ( & V_72 , F_18 ( 1000 ) ) )
return - V_76 ;
return 0 ;
}
static void
F_25 ( struct V_2 * V_3 )
{
F_26 ( V_6 ( V_3 ) ) ;
}
int
F_27 ( struct V_85 * V_11 , const struct V_86 * V_87 ,
struct V_2 * * V_3 )
{
struct V_6 * V_88 ;
V_88 = F_28 ( sizeof( * V_88 ) , V_89 ) ;
if ( ! V_88 )
return - V_90 ;
* V_3 = & V_88 -> V_10 ;
F_29 ( & V_91 , V_11 , & V_88 -> V_10 ) ;
return 0 ;
}
int
F_30 ( struct V_85 * V_11 , const struct V_86 * V_87 ,
struct V_2 * * V_3 )
{
struct V_82 * V_88 ;
V_88 = F_28 ( sizeof( * V_88 ) , V_89 ) ;
if ( ! V_88 )
return - V_90 ;
* V_3 = & V_88 -> V_10 . V_10 ;
F_29 ( & V_92 , V_11 , & V_88 -> V_10 . V_10 ) ;
return 0 ;
}
