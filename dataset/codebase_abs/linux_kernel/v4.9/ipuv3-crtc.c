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
static void F_8 ( struct V_2 * V_3 ,
struct V_11 * V_12 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_5 * V_6 = F_4 ( V_1 -> V_7 -> V_8 ) ;
F_9 ( V_1 -> V_9 ) ;
F_10 ( V_1 -> V_10 ) ;
F_11 ( V_12 , false ) ;
F_12 ( V_6 ) ;
F_13 ( & V_3 -> V_7 -> V_13 ) ;
if ( V_3 -> V_14 -> V_15 ) {
F_14 ( V_3 , V_3 -> V_14 -> V_15 ) ;
V_3 -> V_14 -> V_15 = NULL ;
}
F_15 ( & V_3 -> V_7 -> V_13 ) ;
F_16 ( V_3 ) ;
}
static void F_17 ( struct V_2 * V_3 )
{
struct V_16 * V_14 ;
if ( V_3 -> V_14 ) {
if ( V_3 -> V_14 -> V_17 )
F_18 ( V_3 -> V_14 -> V_17 ) ;
V_14 = F_19 ( V_3 -> V_14 ) ;
memset ( V_14 , 0 , sizeof( * V_14 ) ) ;
} else {
V_14 = F_20 ( sizeof( * V_14 ) , V_18 ) ;
if ( ! V_14 )
return;
V_3 -> V_14 = & V_14 -> V_4 ;
}
V_14 -> V_4 . V_3 = V_3 ;
}
static struct V_11 * F_21 ( struct V_2 * V_3 )
{
struct V_16 * V_14 ;
V_14 = F_20 ( sizeof( * V_14 ) , V_18 ) ;
if ( ! V_14 )
return NULL ;
F_22 ( V_3 , & V_14 -> V_4 ) ;
F_23 ( V_14 -> V_4 . V_3 != V_3 ) ;
V_14 -> V_4 . V_3 = V_3 ;
return & V_14 -> V_4 ;
}
static void F_24 ( struct V_2 * V_3 ,
struct V_11 * V_14 )
{
F_25 ( V_14 ) ;
F_26 ( F_19 ( V_14 ) ) ;
}
static void F_27 ( struct V_2 * V_3 )
{
F_28 ( F_1 ( V_3 ) -> V_19 ) ;
}
static T_1 F_29 ( int V_20 , void * V_21 )
{
struct V_1 * V_1 = V_21 ;
F_30 ( & V_1 -> V_4 ) ;
return V_22 ;
}
static bool F_31 ( struct V_2 * V_3 ,
const struct V_23 * V_24 ,
struct V_23 * V_25 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_26 V_27 ;
int V_28 ;
F_32 ( V_25 , & V_27 ) ;
V_28 = F_33 ( V_1 -> V_10 , & V_27 ) ;
if ( V_28 )
return false ;
if ( ( V_27 . V_29 == 0 ) || ( V_27 . V_30 == 0 ) )
return false ;
F_34 ( & V_27 , V_25 ) ;
return true ;
}
static int F_35 ( struct V_2 * V_3 ,
struct V_11 * V_14 )
{
T_2 V_31 = 1 << F_36 ( V_3 -> V_32 ) ;
if ( V_14 -> V_33 && ( V_31 & V_14 -> V_34 ) == 0 )
return - V_35 ;
return 0 ;
}
static void F_37 ( struct V_2 * V_3 ,
struct V_11 * V_12 )
{
F_38 ( V_3 ) ;
F_13 ( & V_3 -> V_7 -> V_13 ) ;
if ( V_3 -> V_14 -> V_15 ) {
F_23 ( F_39 ( V_3 ) ) ;
F_40 ( V_3 , V_3 -> V_14 -> V_15 ) ;
V_3 -> V_14 -> V_15 = NULL ;
}
F_15 ( & V_3 -> V_7 -> V_13 ) ;
}
static void F_41 ( struct V_2 * V_3 )
{
struct V_36 * V_7 = V_3 -> V_7 ;
struct V_37 * V_38 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_23 * V_24 = & V_3 -> V_14 -> V_25 ;
struct V_16 * V_16 = F_19 ( V_3 -> V_14 ) ;
struct V_39 V_40 = {} ;
unsigned long V_41 = 0 ;
F_42 ( V_1 -> V_7 , L_1 , V_42 ,
V_24 -> V_43 ) ;
F_42 ( V_1 -> V_7 , L_2 , V_42 ,
V_24 -> V_44 ) ;
F_43 (encoder, &dev->mode_config.encoder_list, head) {
if ( V_38 -> V_3 == V_3 )
V_41 |= F_44 ( V_38 -> V_45 ) ;
}
F_42 ( V_1 -> V_7 , L_3 ,
V_42 , V_41 ) ;
if ( V_41 & ( F_44 ( V_46 ) |
F_44 ( V_47 ) ) )
V_40 . V_48 = V_49 | V_50 ;
else if ( V_41 & F_44 ( V_51 ) )
V_40 . V_48 = V_50 ;
else
V_40 . V_48 = 0 ;
V_40 . V_52 = ! ( V_16 -> V_53 & V_54 ) ;
V_40 . V_55 = ! ! ( V_16 -> V_53 &
V_56 ) ;
V_40 . V_57 = V_16 -> V_57 ;
V_40 . V_58 = 0 ;
V_40 . V_59 = V_16 -> V_60 ;
V_40 . V_61 = V_16 -> V_62 ;
F_32 ( V_24 , & V_40 . V_24 ) ;
F_45 ( V_1 -> V_9 , V_1 -> V_10 ,
V_24 -> V_63 & V_64 ,
V_16 -> V_57 , V_24 -> V_43 ) ;
F_46 ( V_1 -> V_10 , & V_40 ) ;
}
static int F_47 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
F_48 ( V_1 -> V_20 ) ;
return 0 ;
}
static void F_49 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
F_50 ( V_1 -> V_20 ) ;
}
static void F_51 ( struct V_1 * V_1 )
{
if ( ! F_52 ( V_1 -> V_9 ) )
F_53 ( V_1 -> V_9 ) ;
if ( ! F_52 ( V_1 -> V_10 ) )
F_54 ( V_1 -> V_10 ) ;
}
static int F_55 ( struct V_1 * V_1 ,
struct V_65 * V_66 )
{
struct V_5 * V_6 = F_4 ( V_1 -> V_7 -> V_8 ) ;
int V_28 ;
V_1 -> V_9 = F_56 ( V_6 , V_66 -> V_9 ) ;
if ( F_57 ( V_1 -> V_9 ) ) {
V_28 = F_58 ( V_1 -> V_9 ) ;
goto V_67;
}
V_1 -> V_10 = F_59 ( V_6 , V_66 -> V_10 ) ;
if ( F_57 ( V_1 -> V_10 ) ) {
V_28 = F_58 ( V_1 -> V_10 ) ;
goto V_67;
}
return 0 ;
V_67:
F_51 ( V_1 ) ;
return V_28 ;
}
static int F_60 ( struct V_1 * V_1 ,
struct V_65 * V_66 , struct V_36 * V_68 )
{
struct V_5 * V_6 = F_4 ( V_1 -> V_7 -> V_8 ) ;
int V_69 = - V_35 ;
int V_28 ;
V_28 = F_55 ( V_1 , V_66 ) ;
if ( V_28 ) {
F_61 ( V_1 -> V_7 , L_4 ,
V_28 ) ;
return V_28 ;
}
if ( V_66 -> V_69 >= 0 )
V_69 = V_70 ;
V_1 -> V_71 [ 0 ] = F_62 ( V_68 , V_6 , V_66 -> V_72 [ 0 ] , V_69 , 0 ,
V_73 ) ;
if ( F_57 ( V_1 -> V_71 [ 0 ] ) ) {
V_28 = F_58 ( V_1 -> V_71 [ 0 ] ) ;
goto V_74;
}
V_28 = F_63 ( V_68 , & V_1 -> V_4 , & V_1 -> V_19 ,
& V_1 -> V_71 [ 0 ] -> V_4 , & V_75 ,
V_66 -> V_76 ) ;
if ( V_28 ) {
F_61 ( V_1 -> V_7 , L_5 , V_28 ) ;
goto V_74;
}
V_28 = F_64 ( V_1 -> V_71 [ 0 ] ) ;
if ( V_28 ) {
F_61 ( V_1 -> V_7 , L_6 ,
V_28 ) ;
goto V_77;
}
if ( V_66 -> V_69 >= 0 && V_66 -> V_72 [ 1 ] > 0 ) {
V_1 -> V_71 [ 1 ] = F_62 ( V_68 , V_6 , V_66 -> V_72 [ 1 ] ,
V_78 ,
F_65 ( & V_1 -> V_4 ) ,
V_79 ) ;
if ( F_57 ( V_1 -> V_71 [ 1 ] ) ) {
V_1 -> V_71 [ 1 ] = NULL ;
} else {
V_28 = F_64 ( V_1 -> V_71 [ 1 ] ) ;
if ( V_28 ) {
F_61 ( V_1 -> V_7 , L_7
L_8 , V_28 ) ;
goto V_80;
}
}
}
V_1 -> V_20 = F_66 ( V_1 -> V_71 [ 0 ] ) ;
V_28 = F_67 ( V_1 -> V_7 , V_1 -> V_20 , F_29 , 0 ,
L_9 , V_1 ) ;
if ( V_28 < 0 ) {
F_61 ( V_1 -> V_7 , L_10 , V_28 ) ;
goto V_81;
}
F_68 ( V_1 -> V_20 ) ;
return 0 ;
V_81:
if ( V_1 -> V_71 [ 1 ] )
F_69 ( V_1 -> V_71 [ 1 ] ) ;
V_80:
F_69 ( V_1 -> V_71 [ 0 ] ) ;
V_77:
F_28 ( V_1 -> V_19 ) ;
V_74:
F_51 ( V_1 ) ;
return V_28 ;
}
static int F_70 ( struct V_82 * V_7 , struct V_82 * V_83 , void * V_84 )
{
struct V_65 * V_66 = V_7 -> V_85 ;
struct V_36 * V_68 = V_84 ;
struct V_1 * V_1 ;
int V_28 ;
V_1 = F_71 ( V_7 , sizeof( * V_1 ) , V_18 ) ;
if ( ! V_1 )
return - V_86 ;
V_1 -> V_7 = V_7 ;
V_28 = F_60 ( V_1 , V_66 , V_68 ) ;
if ( V_28 )
return V_28 ;
F_72 ( V_7 , V_1 ) ;
return 0 ;
}
static void F_73 ( struct V_82 * V_7 , struct V_82 * V_83 ,
void * V_84 )
{
struct V_1 * V_1 = F_4 ( V_7 ) ;
F_51 ( V_1 ) ;
if ( V_1 -> V_71 [ 1 ] )
F_69 ( V_1 -> V_71 [ 1 ] ) ;
F_69 ( V_1 -> V_71 [ 0 ] ) ;
}
static int F_74 ( struct V_87 * V_88 )
{
struct V_82 * V_7 = & V_88 -> V_7 ;
int V_28 ;
if ( ! V_7 -> V_85 )
return - V_35 ;
V_28 = F_75 ( V_7 , F_76 ( 32 ) ) ;
if ( V_28 )
return V_28 ;
return F_77 ( V_7 , & V_89 ) ;
}
static int F_78 ( struct V_87 * V_88 )
{
F_79 ( & V_88 -> V_7 , & V_89 ) ;
return 0 ;
}
