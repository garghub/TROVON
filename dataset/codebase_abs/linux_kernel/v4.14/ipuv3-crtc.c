static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static void F_3 ( struct V_2 * V_3 ,
struct V_5 * V_6 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_7 * V_8 = F_4 ( V_1 -> V_9 -> V_10 ) ;
F_5 ( V_8 ) ;
F_6 ( V_8 ) ;
F_7 ( V_1 -> V_11 ) ;
F_8 ( V_1 -> V_12 ) ;
}
static void F_9 ( struct V_1 * V_1 ,
struct V_5 * V_13 )
{
bool V_14 = false ;
bool V_15 = false ;
struct V_16 * V_17 ;
F_10 (plane, old_crtc_state) {
if ( V_17 == & V_1 -> V_17 [ 0 ] -> V_4 )
V_15 = true ;
if ( & V_1 -> V_17 [ 1 ] && V_17 == & V_1 -> V_17 [ 1 ] -> V_4 )
V_14 = true ;
}
if ( V_14 )
F_11 ( V_1 -> V_17 [ 1 ] , true ) ;
if ( V_15 )
F_11 ( V_1 -> V_17 [ 0 ] , false ) ;
}
static void F_12 ( struct V_2 * V_3 ,
struct V_5 * V_13 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_7 * V_8 = F_4 ( V_1 -> V_9 -> V_10 ) ;
F_13 ( V_1 -> V_11 ) ;
F_14 ( V_1 -> V_12 ) ;
F_9 ( V_1 , V_13 ) ;
F_15 ( V_8 ) ;
F_16 ( V_8 ) ;
F_17 ( & V_3 -> V_9 -> V_18 ) ;
if ( V_3 -> V_19 -> V_20 ) {
F_18 ( V_3 , V_3 -> V_19 -> V_20 ) ;
V_3 -> V_19 -> V_20 = NULL ;
}
F_19 ( & V_3 -> V_9 -> V_18 ) ;
F_20 ( V_3 ) ;
}
static void F_21 ( struct V_2 * V_3 )
{
struct V_21 * V_19 ;
if ( V_3 -> V_19 ) {
if ( V_3 -> V_19 -> V_22 )
F_22 ( V_3 -> V_19 -> V_22 ) ;
V_19 = F_23 ( V_3 -> V_19 ) ;
memset ( V_19 , 0 , sizeof( * V_19 ) ) ;
} else {
V_19 = F_24 ( sizeof( * V_19 ) , V_23 ) ;
if ( ! V_19 )
return;
V_3 -> V_19 = & V_19 -> V_4 ;
}
V_19 -> V_4 . V_3 = V_3 ;
}
static struct V_5 * F_25 ( struct V_2 * V_3 )
{
struct V_21 * V_19 ;
V_19 = F_24 ( sizeof( * V_19 ) , V_23 ) ;
if ( ! V_19 )
return NULL ;
F_26 ( V_3 , & V_19 -> V_4 ) ;
F_27 ( V_19 -> V_4 . V_3 != V_3 ) ;
V_19 -> V_4 . V_3 = V_3 ;
return & V_19 -> V_4 ;
}
static void F_28 ( struct V_2 * V_3 ,
struct V_5 * V_19 )
{
F_29 ( V_19 ) ;
F_30 ( F_23 ( V_19 ) ) ;
}
static int F_31 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
F_32 ( V_1 -> V_24 ) ;
return 0 ;
}
static void F_33 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
F_34 ( V_1 -> V_24 ) ;
}
static T_1 F_35 ( int V_24 , void * V_25 )
{
struct V_1 * V_1 = V_25 ;
F_36 ( & V_1 -> V_4 ) ;
return V_26 ;
}
static bool F_37 ( struct V_2 * V_3 ,
const struct V_27 * V_28 ,
struct V_27 * V_29 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_30 V_31 ;
int V_32 ;
F_38 ( V_29 , & V_31 ) ;
V_32 = F_39 ( V_1 -> V_12 , & V_31 ) ;
if ( V_32 )
return false ;
if ( ( V_31 . V_33 == 0 ) || ( V_31 . V_34 == 0 ) )
return false ;
F_40 ( & V_31 , V_29 ) ;
return true ;
}
static int F_41 ( struct V_2 * V_3 ,
struct V_5 * V_19 )
{
T_2 V_35 = 1 << F_42 ( V_3 -> V_36 ) ;
if ( V_19 -> V_37 && ( V_35 & V_19 -> V_38 ) == 0 )
return - V_39 ;
return 0 ;
}
static void F_43 ( struct V_2 * V_3 ,
struct V_5 * V_13 )
{
F_44 ( V_3 ) ;
F_17 ( & V_3 -> V_9 -> V_18 ) ;
if ( V_3 -> V_19 -> V_20 ) {
F_27 ( F_45 ( V_3 ) ) ;
F_46 ( V_3 , V_3 -> V_19 -> V_20 ) ;
V_3 -> V_19 -> V_20 = NULL ;
}
F_19 ( & V_3 -> V_9 -> V_18 ) ;
}
static void F_47 ( struct V_2 * V_3 )
{
struct V_40 * V_9 = V_3 -> V_9 ;
struct V_41 * V_42 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_27 * V_28 = & V_3 -> V_19 -> V_29 ;
struct V_21 * V_21 = F_23 ( V_3 -> V_19 ) ;
struct V_43 V_44 = {} ;
unsigned long V_45 = 0 ;
F_48 ( V_1 -> V_9 , L_1 , V_46 ,
V_28 -> V_47 ) ;
F_48 ( V_1 -> V_9 , L_2 , V_46 ,
V_28 -> V_48 ) ;
F_49 (encoder, &dev->mode_config.encoder_list, head) {
if ( V_42 -> V_3 == V_3 )
V_45 |= F_50 ( V_42 -> V_49 ) ;
}
F_48 ( V_1 -> V_9 , L_3 ,
V_46 , V_45 ) ;
if ( V_45 & ( F_50 ( V_50 ) |
F_50 ( V_51 ) ) )
V_44 . V_52 = V_53 | V_54 ;
else if ( V_45 & F_50 ( V_55 ) )
V_44 . V_52 = V_54 ;
else
V_44 . V_52 = 0 ;
V_44 . V_56 = ! ( V_21 -> V_57 & V_58 ) ;
V_44 . V_59 = ! ! ( V_21 -> V_57 &
V_60 ) ;
V_44 . V_61 = V_21 -> V_61 ;
V_44 . V_62 = 0 ;
V_44 . V_63 = V_21 -> V_64 ;
V_44 . V_65 = V_21 -> V_66 ;
F_38 ( V_28 , & V_44 . V_28 ) ;
F_51 ( V_1 -> V_11 , V_1 -> V_12 ,
V_28 -> V_67 & V_68 ,
V_21 -> V_61 , V_28 -> V_47 ) ;
F_52 ( V_1 -> V_12 , & V_44 ) ;
}
static void F_53 ( struct V_1 * V_1 )
{
if ( ! F_54 ( V_1 -> V_11 ) )
F_55 ( V_1 -> V_11 ) ;
if ( ! F_54 ( V_1 -> V_12 ) )
F_56 ( V_1 -> V_12 ) ;
}
static int F_57 ( struct V_1 * V_1 ,
struct V_69 * V_70 )
{
struct V_7 * V_8 = F_4 ( V_1 -> V_9 -> V_10 ) ;
int V_32 ;
V_1 -> V_11 = F_58 ( V_8 , V_70 -> V_11 ) ;
if ( F_59 ( V_1 -> V_11 ) ) {
V_32 = F_60 ( V_1 -> V_11 ) ;
goto V_71;
}
V_1 -> V_12 = F_61 ( V_8 , V_70 -> V_12 ) ;
if ( F_59 ( V_1 -> V_12 ) ) {
V_32 = F_60 ( V_1 -> V_12 ) ;
goto V_71;
}
return 0 ;
V_71:
F_53 ( V_1 ) ;
return V_32 ;
}
static int F_62 ( struct V_1 * V_1 ,
struct V_69 * V_70 , struct V_40 * V_72 )
{
struct V_7 * V_8 = F_4 ( V_1 -> V_9 -> V_10 ) ;
struct V_2 * V_3 = & V_1 -> V_4 ;
int V_73 = - V_39 ;
int V_32 ;
V_32 = F_57 ( V_1 , V_70 ) ;
if ( V_32 ) {
F_63 ( V_1 -> V_9 , L_4 ,
V_32 ) ;
return V_32 ;
}
if ( V_70 -> V_73 >= 0 )
V_73 = V_74 ;
V_1 -> V_17 [ 0 ] = F_64 ( V_72 , V_8 , V_70 -> V_75 [ 0 ] , V_73 , 0 ,
V_76 ) ;
if ( F_59 ( V_1 -> V_17 [ 0 ] ) ) {
V_32 = F_60 ( V_1 -> V_17 [ 0 ] ) ;
goto V_77;
}
V_3 -> V_78 = V_70 -> V_79 ;
F_65 ( V_3 , & V_80 ) ;
F_66 ( V_72 , V_3 , & V_1 -> V_17 [ 0 ] -> V_4 , NULL ,
& V_81 , NULL ) ;
V_32 = F_67 ( V_1 -> V_17 [ 0 ] ) ;
if ( V_32 ) {
F_63 ( V_1 -> V_9 , L_5 ,
V_32 ) ;
goto V_77;
}
if ( V_70 -> V_73 >= 0 && V_70 -> V_75 [ 1 ] > 0 ) {
V_1 -> V_17 [ 1 ] = F_64 ( V_72 , V_8 , V_70 -> V_75 [ 1 ] ,
V_82 ,
F_68 ( & V_1 -> V_4 ) ,
V_83 ) ;
if ( F_59 ( V_1 -> V_17 [ 1 ] ) ) {
V_1 -> V_17 [ 1 ] = NULL ;
} else {
V_32 = F_67 ( V_1 -> V_17 [ 1 ] ) ;
if ( V_32 ) {
F_63 ( V_1 -> V_9 , L_6
L_7 , V_32 ) ;
goto V_84;
}
}
}
V_1 -> V_24 = F_69 ( V_1 -> V_17 [ 0 ] ) ;
V_32 = F_70 ( V_1 -> V_9 , V_1 -> V_24 , F_35 , 0 ,
L_8 , V_1 ) ;
if ( V_32 < 0 ) {
F_63 ( V_1 -> V_9 , L_9 , V_32 ) ;
goto V_85;
}
F_71 ( V_1 -> V_24 ) ;
return 0 ;
V_85:
if ( V_1 -> V_17 [ 1 ] )
F_72 ( V_1 -> V_17 [ 1 ] ) ;
V_84:
F_72 ( V_1 -> V_17 [ 0 ] ) ;
V_77:
F_53 ( V_1 ) ;
return V_32 ;
}
static int F_73 ( struct V_86 * V_9 , struct V_86 * V_87 , void * V_88 )
{
struct V_69 * V_70 = V_9 -> V_89 ;
struct V_40 * V_72 = V_88 ;
struct V_1 * V_1 ;
int V_32 ;
V_1 = F_74 ( V_9 , sizeof( * V_1 ) , V_23 ) ;
if ( ! V_1 )
return - V_90 ;
V_1 -> V_9 = V_9 ;
V_32 = F_62 ( V_1 , V_70 , V_72 ) ;
if ( V_32 )
return V_32 ;
F_75 ( V_9 , V_1 ) ;
return 0 ;
}
static void F_76 ( struct V_86 * V_9 , struct V_86 * V_87 ,
void * V_88 )
{
struct V_1 * V_1 = F_4 ( V_9 ) ;
F_53 ( V_1 ) ;
if ( V_1 -> V_17 [ 1 ] )
F_72 ( V_1 -> V_17 [ 1 ] ) ;
F_72 ( V_1 -> V_17 [ 0 ] ) ;
}
static int F_77 ( struct V_91 * V_92 )
{
struct V_86 * V_9 = & V_92 -> V_9 ;
int V_32 ;
if ( ! V_9 -> V_89 )
return - V_39 ;
V_32 = F_78 ( V_9 , F_79 ( 32 ) ) ;
if ( V_32 )
return V_32 ;
return F_80 ( V_9 , & V_93 ) ;
}
static int F_81 ( struct V_91 * V_92 )
{
F_82 ( & V_92 -> V_9 , & V_93 ) ;
return 0 ;
}
