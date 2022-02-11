static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static void F_3 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_5 * V_6 = F_4 ( V_1 -> V_7 -> V_8 ) ;
F_5 ( V_6 ) ;
F_6 ( V_1 -> V_9 ) ;
F_7 ( V_1 -> V_10 ) ;
}
static void F_8 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_5 * V_6 = F_4 ( V_1 -> V_7 -> V_8 ) ;
F_9 ( V_1 -> V_9 ) ;
F_10 ( V_1 -> V_10 ) ;
F_11 ( V_6 ) ;
F_12 ( & V_3 -> V_7 -> V_11 ) ;
if ( V_3 -> V_12 -> V_13 ) {
F_13 ( V_3 , V_3 -> V_12 -> V_13 ) ;
V_3 -> V_12 -> V_13 = NULL ;
}
F_14 ( & V_3 -> V_7 -> V_11 ) ;
F_15 ( V_3 ) ;
}
static void F_16 ( struct V_2 * V_3 )
{
struct V_14 * V_12 ;
if ( V_3 -> V_12 ) {
if ( V_3 -> V_12 -> V_15 )
F_17 ( V_3 -> V_12 -> V_15 ) ;
V_12 = F_18 ( V_3 -> V_12 ) ;
memset ( V_12 , 0 , sizeof( * V_12 ) ) ;
} else {
V_12 = F_19 ( sizeof( * V_12 ) , V_16 ) ;
if ( ! V_12 )
return;
V_3 -> V_12 = & V_12 -> V_4 ;
}
V_12 -> V_4 . V_3 = V_3 ;
}
static struct V_17 * F_20 ( struct V_2 * V_3 )
{
struct V_14 * V_12 ;
V_12 = F_19 ( sizeof( * V_12 ) , V_16 ) ;
if ( ! V_12 )
return NULL ;
F_21 ( V_3 , & V_12 -> V_4 ) ;
F_22 ( V_12 -> V_4 . V_3 != V_3 ) ;
V_12 -> V_4 . V_3 = V_3 ;
return & V_12 -> V_4 ;
}
static void F_23 ( struct V_2 * V_3 ,
struct V_17 * V_12 )
{
F_24 ( V_12 ) ;
F_25 ( F_18 ( V_12 ) ) ;
}
static T_1 F_26 ( int V_18 , void * V_19 )
{
struct V_1 * V_1 = V_19 ;
F_27 ( V_1 -> V_20 ) ;
return V_21 ;
}
static bool F_28 ( struct V_2 * V_3 ,
const struct V_22 * V_23 ,
struct V_22 * V_24 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_25 V_26 ;
int V_27 ;
F_29 ( V_24 , & V_26 ) ;
V_27 = F_30 ( V_1 -> V_10 , & V_26 ) ;
if ( V_27 )
return false ;
if ( ( V_26 . V_28 == 0 ) || ( V_26 . V_29 == 0 ) )
return false ;
F_31 ( & V_26 , V_24 ) ;
return true ;
}
static int F_32 ( struct V_2 * V_3 ,
struct V_17 * V_12 )
{
T_2 V_30 = 1 << F_33 ( V_3 -> V_31 ) ;
if ( V_12 -> V_32 && ( V_30 & V_12 -> V_33 ) == 0 )
return - V_34 ;
return 0 ;
}
static void F_34 ( struct V_2 * V_3 ,
struct V_17 * V_35 )
{
F_35 ( V_3 ) ;
F_12 ( & V_3 -> V_7 -> V_11 ) ;
if ( V_3 -> V_12 -> V_13 ) {
F_22 ( F_36 ( V_3 ) ) ;
F_37 ( V_3 , V_3 -> V_12 -> V_13 ) ;
V_3 -> V_12 -> V_13 = NULL ;
}
F_14 ( & V_3 -> V_7 -> V_11 ) ;
}
static void F_38 ( struct V_2 * V_3 )
{
struct V_36 * V_7 = V_3 -> V_7 ;
struct V_37 * V_38 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_22 * V_23 = & V_3 -> V_12 -> V_24 ;
struct V_14 * V_14 = F_18 ( V_3 -> V_12 ) ;
struct V_39 V_40 = {} ;
unsigned long V_41 = 0 ;
F_39 ( V_1 -> V_7 , L_1 , V_42 ,
V_23 -> V_43 ) ;
F_39 ( V_1 -> V_7 , L_2 , V_42 ,
V_23 -> V_44 ) ;
F_40 (encoder, &dev->mode_config.encoder_list, head) {
if ( V_38 -> V_3 == V_3 )
V_41 |= F_41 ( V_38 -> V_45 ) ;
}
F_39 ( V_1 -> V_7 , L_3 ,
V_42 , V_41 ) ;
if ( V_41 & ( F_41 ( V_46 ) |
F_41 ( V_47 ) ) )
V_40 . V_48 = V_49 | V_50 ;
else if ( V_41 & F_41 ( V_51 ) )
V_40 . V_48 = V_50 ;
else
V_40 . V_48 = 0 ;
V_40 . V_52 = ! ( V_14 -> V_53 & V_54 ) ;
V_40 . V_55 = ! ! ( V_14 -> V_53 &
V_56 ) ;
V_40 . V_57 = V_14 -> V_57 ;
V_40 . V_58 = 0 ;
V_40 . V_59 = V_14 -> V_60 ;
V_40 . V_61 = V_14 -> V_62 ;
F_29 ( V_23 , & V_40 . V_23 ) ;
F_42 ( V_1 -> V_9 , V_1 -> V_10 ,
V_23 -> V_63 & V_64 ,
V_14 -> V_57 , V_23 -> V_43 ) ;
F_43 ( V_1 -> V_10 , & V_40 ) ;
}
static int F_44 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
F_45 ( V_1 -> V_18 ) ;
return 0 ;
}
static void F_46 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
F_47 ( V_1 -> V_18 ) ;
}
static void F_48 ( struct V_1 * V_1 )
{
if ( ! F_49 ( V_1 -> V_9 ) )
F_50 ( V_1 -> V_9 ) ;
if ( ! F_49 ( V_1 -> V_10 ) )
F_51 ( V_1 -> V_10 ) ;
}
static int F_52 ( struct V_1 * V_1 ,
struct V_65 * V_66 )
{
struct V_5 * V_6 = F_4 ( V_1 -> V_7 -> V_8 ) ;
int V_27 ;
V_1 -> V_9 = F_53 ( V_6 , V_66 -> V_9 ) ;
if ( F_54 ( V_1 -> V_9 ) ) {
V_27 = F_55 ( V_1 -> V_9 ) ;
goto V_67;
}
V_1 -> V_10 = F_56 ( V_6 , V_66 -> V_10 ) ;
if ( F_54 ( V_1 -> V_10 ) ) {
V_27 = F_55 ( V_1 -> V_10 ) ;
goto V_67;
}
return 0 ;
V_67:
F_48 ( V_1 ) ;
return V_27 ;
}
static int F_57 ( struct V_1 * V_1 ,
struct V_65 * V_66 , struct V_36 * V_68 )
{
struct V_5 * V_6 = F_4 ( V_1 -> V_7 -> V_8 ) ;
int V_69 = - V_34 ;
int V_27 ;
V_27 = F_52 ( V_1 , V_66 ) ;
if ( V_27 ) {
F_58 ( V_1 -> V_7 , L_4 ,
V_27 ) ;
return V_27 ;
}
if ( V_66 -> V_69 >= 0 )
V_69 = V_70 ;
V_1 -> V_71 [ 0 ] = F_59 ( V_68 , V_6 , V_66 -> V_72 [ 0 ] , V_69 , 0 ,
V_73 ) ;
if ( F_54 ( V_1 -> V_71 [ 0 ] ) ) {
V_27 = F_55 ( V_1 -> V_71 [ 0 ] ) ;
goto V_74;
}
V_27 = F_60 ( V_68 , & V_1 -> V_4 , & V_1 -> V_20 ,
& V_1 -> V_71 [ 0 ] -> V_4 , & V_75 ,
V_66 -> V_76 ) ;
if ( V_27 ) {
F_58 ( V_1 -> V_7 , L_5 , V_27 ) ;
goto V_74;
}
V_27 = F_61 ( V_1 -> V_71 [ 0 ] ) ;
if ( V_27 ) {
F_58 ( V_1 -> V_7 , L_6 ,
V_27 ) ;
goto V_77;
}
if ( V_66 -> V_69 >= 0 && V_66 -> V_72 [ 1 ] > 0 ) {
V_1 -> V_71 [ 1 ] = F_59 ( V_68 , V_6 , V_66 -> V_72 [ 1 ] ,
V_78 ,
F_62 ( & V_1 -> V_4 ) ,
V_79 ) ;
if ( F_54 ( V_1 -> V_71 [ 1 ] ) ) {
V_1 -> V_71 [ 1 ] = NULL ;
} else {
V_27 = F_61 ( V_1 -> V_71 [ 1 ] ) ;
if ( V_27 ) {
F_58 ( V_1 -> V_7 , L_7
L_8 , V_27 ) ;
goto V_80;
}
}
}
V_1 -> V_18 = F_63 ( V_1 -> V_71 [ 0 ] ) ;
V_27 = F_64 ( V_1 -> V_7 , V_1 -> V_18 , F_26 , 0 ,
L_9 , V_1 ) ;
if ( V_27 < 0 ) {
F_58 ( V_1 -> V_7 , L_10 , V_27 ) ;
goto V_81;
}
F_65 ( V_1 -> V_18 ) ;
return 0 ;
V_81:
if ( V_1 -> V_71 [ 1 ] )
F_66 ( V_1 -> V_71 [ 1 ] ) ;
V_80:
F_66 ( V_1 -> V_71 [ 0 ] ) ;
V_77:
F_67 ( V_1 -> V_20 ) ;
V_74:
F_48 ( V_1 ) ;
return V_27 ;
}
static int F_68 ( struct V_82 * V_7 , struct V_82 * V_83 , void * V_84 )
{
struct V_65 * V_66 = V_7 -> V_85 ;
struct V_36 * V_68 = V_84 ;
struct V_1 * V_1 ;
int V_27 ;
V_1 = F_69 ( V_7 , sizeof( * V_1 ) , V_16 ) ;
if ( ! V_1 )
return - V_86 ;
V_1 -> V_7 = V_7 ;
V_27 = F_57 ( V_1 , V_66 , V_68 ) ;
if ( V_27 )
return V_27 ;
F_70 ( V_7 , V_1 ) ;
return 0 ;
}
static void F_71 ( struct V_82 * V_7 , struct V_82 * V_83 ,
void * V_84 )
{
struct V_1 * V_1 = F_4 ( V_7 ) ;
F_67 ( V_1 -> V_20 ) ;
F_48 ( V_1 ) ;
if ( V_1 -> V_71 [ 1 ] )
F_66 ( V_1 -> V_71 [ 1 ] ) ;
F_66 ( V_1 -> V_71 [ 0 ] ) ;
}
static int F_72 ( struct V_87 * V_88 )
{
struct V_82 * V_7 = & V_88 -> V_7 ;
int V_27 ;
if ( ! V_7 -> V_85 )
return - V_34 ;
V_27 = F_73 ( V_7 , F_74 ( 32 ) ) ;
if ( V_27 )
return V_27 ;
return F_75 ( V_7 , & V_89 ) ;
}
static int F_76 ( struct V_87 * V_88 )
{
F_77 ( & V_88 -> V_7 , & V_89 ) ;
return 0 ;
}
