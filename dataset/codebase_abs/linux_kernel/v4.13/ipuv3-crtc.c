static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static void F_3 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_5 * V_6 = F_4 ( V_1 -> V_7 -> V_8 ) ;
F_5 ( V_6 ) ;
F_6 ( V_6 ) ;
F_7 ( V_1 -> V_9 ) ;
F_8 ( V_1 -> V_10 ) ;
}
static void F_9 ( struct V_1 * V_1 ,
struct V_11 * V_12 )
{
bool V_13 = false ;
bool V_14 = false ;
struct V_15 * V_16 ;
F_10 (plane, old_crtc_state) {
if ( V_16 == & V_1 -> V_16 [ 0 ] -> V_4 )
V_14 = true ;
if ( & V_1 -> V_16 [ 1 ] && V_16 == & V_1 -> V_16 [ 1 ] -> V_4 )
V_13 = true ;
}
if ( V_13 )
F_11 ( V_1 -> V_16 [ 1 ] , true ) ;
if ( V_14 )
F_11 ( V_1 -> V_16 [ 0 ] , false ) ;
}
static void F_12 ( struct V_2 * V_3 ,
struct V_11 * V_12 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_5 * V_6 = F_4 ( V_1 -> V_7 -> V_8 ) ;
F_13 ( V_1 -> V_9 ) ;
F_14 ( V_1 -> V_10 ) ;
F_9 ( V_1 , V_12 ) ;
F_15 ( V_6 ) ;
F_16 ( V_6 ) ;
F_17 ( & V_3 -> V_7 -> V_17 ) ;
if ( V_3 -> V_18 -> V_19 ) {
F_18 ( V_3 , V_3 -> V_18 -> V_19 ) ;
V_3 -> V_18 -> V_19 = NULL ;
}
F_19 ( & V_3 -> V_7 -> V_17 ) ;
F_20 ( V_3 ) ;
}
static void F_21 ( struct V_2 * V_3 )
{
struct V_20 * V_18 ;
if ( V_3 -> V_18 ) {
if ( V_3 -> V_18 -> V_21 )
F_22 ( V_3 -> V_18 -> V_21 ) ;
V_18 = F_23 ( V_3 -> V_18 ) ;
memset ( V_18 , 0 , sizeof( * V_18 ) ) ;
} else {
V_18 = F_24 ( sizeof( * V_18 ) , V_22 ) ;
if ( ! V_18 )
return;
V_3 -> V_18 = & V_18 -> V_4 ;
}
V_18 -> V_4 . V_3 = V_3 ;
}
static struct V_11 * F_25 ( struct V_2 * V_3 )
{
struct V_20 * V_18 ;
V_18 = F_24 ( sizeof( * V_18 ) , V_22 ) ;
if ( ! V_18 )
return NULL ;
F_26 ( V_3 , & V_18 -> V_4 ) ;
F_27 ( V_18 -> V_4 . V_3 != V_3 ) ;
V_18 -> V_4 . V_3 = V_3 ;
return & V_18 -> V_4 ;
}
static void F_28 ( struct V_2 * V_3 ,
struct V_11 * V_18 )
{
F_29 ( V_18 ) ;
F_30 ( F_23 ( V_18 ) ) ;
}
static int F_31 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
F_32 ( V_1 -> V_23 ) ;
return 0 ;
}
static void F_33 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
F_34 ( V_1 -> V_23 ) ;
}
static T_1 F_35 ( int V_23 , void * V_24 )
{
struct V_1 * V_1 = V_24 ;
F_36 ( & V_1 -> V_4 ) ;
return V_25 ;
}
static bool F_37 ( struct V_2 * V_3 ,
const struct V_26 * V_27 ,
struct V_26 * V_28 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_29 V_30 ;
int V_31 ;
F_38 ( V_28 , & V_30 ) ;
V_31 = F_39 ( V_1 -> V_10 , & V_30 ) ;
if ( V_31 )
return false ;
if ( ( V_30 . V_32 == 0 ) || ( V_30 . V_33 == 0 ) )
return false ;
F_40 ( & V_30 , V_28 ) ;
return true ;
}
static int F_41 ( struct V_2 * V_3 ,
struct V_11 * V_18 )
{
T_2 V_34 = 1 << F_42 ( V_3 -> V_35 ) ;
if ( V_18 -> V_36 && ( V_34 & V_18 -> V_37 ) == 0 )
return - V_38 ;
return 0 ;
}
static void F_43 ( struct V_2 * V_3 ,
struct V_11 * V_12 )
{
F_44 ( V_3 ) ;
F_17 ( & V_3 -> V_7 -> V_17 ) ;
if ( V_3 -> V_18 -> V_19 ) {
F_27 ( F_45 ( V_3 ) ) ;
F_46 ( V_3 , V_3 -> V_18 -> V_19 ) ;
V_3 -> V_18 -> V_19 = NULL ;
}
F_19 ( & V_3 -> V_7 -> V_17 ) ;
}
static void F_47 ( struct V_2 * V_3 )
{
struct V_39 * V_7 = V_3 -> V_7 ;
struct V_40 * V_41 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_26 * V_27 = & V_3 -> V_18 -> V_28 ;
struct V_20 * V_20 = F_23 ( V_3 -> V_18 ) ;
struct V_42 V_43 = {} ;
unsigned long V_44 = 0 ;
F_48 ( V_1 -> V_7 , L_1 , V_45 ,
V_27 -> V_46 ) ;
F_48 ( V_1 -> V_7 , L_2 , V_45 ,
V_27 -> V_47 ) ;
F_49 (encoder, &dev->mode_config.encoder_list, head) {
if ( V_41 -> V_3 == V_3 )
V_44 |= F_50 ( V_41 -> V_48 ) ;
}
F_48 ( V_1 -> V_7 , L_3 ,
V_45 , V_44 ) ;
if ( V_44 & ( F_50 ( V_49 ) |
F_50 ( V_50 ) ) )
V_43 . V_51 = V_52 | V_53 ;
else if ( V_44 & F_50 ( V_54 ) )
V_43 . V_51 = V_53 ;
else
V_43 . V_51 = 0 ;
V_43 . V_55 = ! ( V_20 -> V_56 & V_57 ) ;
V_43 . V_58 = ! ! ( V_20 -> V_56 &
V_59 ) ;
V_43 . V_60 = V_20 -> V_60 ;
V_43 . V_61 = 0 ;
V_43 . V_62 = V_20 -> V_63 ;
V_43 . V_64 = V_20 -> V_65 ;
F_38 ( V_27 , & V_43 . V_27 ) ;
F_51 ( V_1 -> V_9 , V_1 -> V_10 ,
V_27 -> V_66 & V_67 ,
V_20 -> V_60 , V_27 -> V_46 ) ;
F_52 ( V_1 -> V_10 , & V_43 ) ;
}
static void F_53 ( struct V_1 * V_1 )
{
if ( ! F_54 ( V_1 -> V_9 ) )
F_55 ( V_1 -> V_9 ) ;
if ( ! F_54 ( V_1 -> V_10 ) )
F_56 ( V_1 -> V_10 ) ;
}
static int F_57 ( struct V_1 * V_1 ,
struct V_68 * V_69 )
{
struct V_5 * V_6 = F_4 ( V_1 -> V_7 -> V_8 ) ;
int V_31 ;
V_1 -> V_9 = F_58 ( V_6 , V_69 -> V_9 ) ;
if ( F_59 ( V_1 -> V_9 ) ) {
V_31 = F_60 ( V_1 -> V_9 ) ;
goto V_70;
}
V_1 -> V_10 = F_61 ( V_6 , V_69 -> V_10 ) ;
if ( F_59 ( V_1 -> V_10 ) ) {
V_31 = F_60 ( V_1 -> V_10 ) ;
goto V_70;
}
return 0 ;
V_70:
F_53 ( V_1 ) ;
return V_31 ;
}
static int F_62 ( struct V_1 * V_1 ,
struct V_68 * V_69 , struct V_39 * V_71 )
{
struct V_5 * V_6 = F_4 ( V_1 -> V_7 -> V_8 ) ;
struct V_2 * V_3 = & V_1 -> V_4 ;
int V_72 = - V_38 ;
int V_31 ;
V_31 = F_57 ( V_1 , V_69 ) ;
if ( V_31 ) {
F_63 ( V_1 -> V_7 , L_4 ,
V_31 ) ;
return V_31 ;
}
if ( V_69 -> V_72 >= 0 )
V_72 = V_73 ;
V_1 -> V_16 [ 0 ] = F_64 ( V_71 , V_6 , V_69 -> V_74 [ 0 ] , V_72 , 0 ,
V_75 ) ;
if ( F_59 ( V_1 -> V_16 [ 0 ] ) ) {
V_31 = F_60 ( V_1 -> V_16 [ 0 ] ) ;
goto V_76;
}
V_3 -> V_77 = V_69 -> V_78 ;
F_65 ( V_3 , & V_79 ) ;
F_66 ( V_71 , V_3 , & V_1 -> V_16 [ 0 ] -> V_4 , NULL ,
& V_80 , NULL ) ;
V_31 = F_67 ( V_1 -> V_16 [ 0 ] ) ;
if ( V_31 ) {
F_63 ( V_1 -> V_7 , L_5 ,
V_31 ) ;
goto V_76;
}
if ( V_69 -> V_72 >= 0 && V_69 -> V_74 [ 1 ] > 0 ) {
V_1 -> V_16 [ 1 ] = F_64 ( V_71 , V_6 , V_69 -> V_74 [ 1 ] ,
V_81 ,
F_68 ( & V_1 -> V_4 ) ,
V_82 ) ;
if ( F_59 ( V_1 -> V_16 [ 1 ] ) ) {
V_1 -> V_16 [ 1 ] = NULL ;
} else {
V_31 = F_67 ( V_1 -> V_16 [ 1 ] ) ;
if ( V_31 ) {
F_63 ( V_1 -> V_7 , L_6
L_7 , V_31 ) ;
goto V_83;
}
}
}
V_1 -> V_23 = F_69 ( V_1 -> V_16 [ 0 ] ) ;
V_31 = F_70 ( V_1 -> V_7 , V_1 -> V_23 , F_35 , 0 ,
L_8 , V_1 ) ;
if ( V_31 < 0 ) {
F_63 ( V_1 -> V_7 , L_9 , V_31 ) ;
goto V_84;
}
F_71 ( V_1 -> V_23 ) ;
return 0 ;
V_84:
if ( V_1 -> V_16 [ 1 ] )
F_72 ( V_1 -> V_16 [ 1 ] ) ;
V_83:
F_72 ( V_1 -> V_16 [ 0 ] ) ;
V_76:
F_53 ( V_1 ) ;
return V_31 ;
}
static int F_73 ( struct V_85 * V_7 , struct V_85 * V_86 , void * V_87 )
{
struct V_68 * V_69 = V_7 -> V_88 ;
struct V_39 * V_71 = V_87 ;
struct V_1 * V_1 ;
int V_31 ;
V_1 = F_74 ( V_7 , sizeof( * V_1 ) , V_22 ) ;
if ( ! V_1 )
return - V_89 ;
V_1 -> V_7 = V_7 ;
V_31 = F_62 ( V_1 , V_69 , V_71 ) ;
if ( V_31 )
return V_31 ;
F_75 ( V_7 , V_1 ) ;
return 0 ;
}
static void F_76 ( struct V_85 * V_7 , struct V_85 * V_86 ,
void * V_87 )
{
struct V_1 * V_1 = F_4 ( V_7 ) ;
F_53 ( V_1 ) ;
if ( V_1 -> V_16 [ 1 ] )
F_72 ( V_1 -> V_16 [ 1 ] ) ;
F_72 ( V_1 -> V_16 [ 0 ] ) ;
}
static int F_77 ( struct V_90 * V_91 )
{
struct V_85 * V_7 = & V_91 -> V_7 ;
int V_31 ;
if ( ! V_7 -> V_88 )
return - V_38 ;
V_31 = F_78 ( V_7 , F_79 ( 32 ) ) ;
if ( V_31 )
return V_31 ;
return F_80 ( V_7 , & V_92 ) ;
}
static int F_81 ( struct V_90 * V_91 )
{
F_82 ( & V_91 -> V_7 , & V_92 ) ;
return 0 ;
}
