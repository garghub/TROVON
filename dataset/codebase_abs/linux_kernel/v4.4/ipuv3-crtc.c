static void F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 -> V_4 -> V_5 ) ;
if ( V_1 -> V_6 )
return;
F_3 ( V_3 ) ;
F_4 ( V_1 -> V_7 [ 0 ] ) ;
F_5 ( V_1 -> V_8 ) ;
F_6 ( V_1 -> V_9 ) ;
V_1 -> V_6 = 1 ;
}
static void F_7 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 -> V_4 -> V_5 ) ;
if ( ! V_1 -> V_6 )
return;
F_8 ( V_1 -> V_8 ) ;
F_9 ( V_1 -> V_9 ) ;
F_10 ( V_1 -> V_7 [ 0 ] ) ;
F_11 ( V_3 ) ;
V_1 -> V_6 = 0 ;
}
static void F_12 ( struct V_10 * V_11 , int V_12 )
{
struct V_1 * V_1 = F_13 ( V_11 ) ;
F_14 ( V_1 -> V_4 , L_1 , V_13 , V_12 ) ;
switch ( V_12 ) {
case V_14 :
F_1 ( V_1 ) ;
break;
case V_15 :
case V_16 :
case V_17 :
F_7 ( V_1 ) ;
break;
}
}
static int F_15 ( struct V_10 * V_11 ,
struct V_18 * V_19 ,
struct V_20 * V_21 ,
T_1 V_22 )
{
struct V_1 * V_1 = F_13 ( V_11 ) ;
int V_23 ;
if ( V_1 -> V_24 )
return - V_25 ;
V_23 = F_16 ( V_1 -> V_26 ) ;
if ( V_23 ) {
F_14 ( V_1 -> V_4 , L_2 ) ;
F_17 ( & V_21 -> V_27 . V_28 ) ;
return V_23 ;
}
V_1 -> V_24 = V_19 ;
V_1 -> V_29 = V_21 ;
V_11 -> V_30 -> V_19 = V_19 ;
return 0 ;
}
static int F_18 ( struct V_10 * V_11 ,
struct V_31 * V_32 ,
struct V_31 * V_12 ,
int V_33 , int V_34 ,
struct V_18 * V_35 )
{
struct V_36 * V_4 = V_11 -> V_4 ;
struct V_37 * V_38 ;
struct V_1 * V_1 = F_13 ( V_11 ) ;
struct V_39 V_40 = {} ;
unsigned long V_41 = 0 ;
int V_23 ;
F_14 ( V_1 -> V_4 , L_3 , V_13 ,
V_12 -> V_42 ) ;
F_14 ( V_1 -> V_4 , L_4 , V_13 ,
V_12 -> V_43 ) ;
F_19 (encoder, &dev->mode_config.encoder_list, head)
if ( V_38 -> V_11 == V_11 )
V_41 |= F_20 ( V_38 -> V_44 ) ;
F_14 ( V_1 -> V_4 , L_5 ,
V_13 , V_41 ) ;
if ( V_41 & ( F_20 ( V_45 ) |
F_20 ( V_46 ) ) )
V_40 . V_47 = V_48 | V_49 ;
else if ( V_41 & F_20 ( V_50 ) )
V_40 . V_47 = V_49 ;
else
V_40 . V_47 = 0 ;
V_40 . V_51 = 1 ;
V_40 . V_52 = 0 ;
V_40 . V_53 = V_1 -> V_53 ;
V_40 . V_54 = 0 ;
V_40 . V_55 = V_1 -> V_56 ;
V_40 . V_57 = V_1 -> V_58 ;
F_21 ( V_12 , & V_40 . V_12 ) ;
V_23 = F_22 ( V_1 -> V_8 , V_1 -> V_9 ,
V_12 -> V_59 & V_60 ,
V_1 -> V_53 , V_12 -> V_42 ) ;
if ( V_23 ) {
F_23 ( V_1 -> V_4 ,
L_6 ,
V_23 ) ;
return V_23 ;
}
V_23 = F_24 ( V_1 -> V_9 , & V_40 ) ;
if ( V_23 ) {
F_23 ( V_1 -> V_4 ,
L_7 , V_23 ) ;
return V_23 ;
}
return F_25 ( V_1 -> V_7 [ 0 ] , V_11 , V_12 ,
V_11 -> V_30 -> V_19 ,
0 , 0 , V_12 -> V_42 , V_12 -> V_43 ,
V_33 , V_34 , V_12 -> V_42 , V_12 -> V_43 ,
V_12 -> V_59 & V_60 ) ;
}
static void F_26 ( struct V_1 * V_1 )
{
unsigned long V_59 ;
struct V_36 * V_61 = V_1 -> V_27 . V_4 ;
F_27 ( & V_61 -> V_62 , V_59 ) ;
if ( V_1 -> V_29 )
F_28 ( & V_1 -> V_27 ,
V_1 -> V_29 ) ;
V_1 -> V_29 = NULL ;
F_29 ( V_1 -> V_26 ) ;
F_30 ( & V_61 -> V_62 , V_59 ) ;
}
static T_2 F_31 ( int V_63 , void * V_64 )
{
struct V_1 * V_1 = V_64 ;
F_32 ( V_1 -> V_26 ) ;
if ( V_1 -> V_24 ) {
struct V_65 * V_7 = V_1 -> V_7 [ 0 ] ;
V_1 -> V_24 = NULL ;
F_33 ( V_7 , V_1 -> V_27 . V_30 -> V_19 ,
V_7 -> V_33 , V_7 -> V_34 ) ;
F_26 ( V_1 ) ;
}
return V_66 ;
}
static bool F_34 ( struct V_10 * V_11 ,
const struct V_31 * V_12 ,
struct V_31 * V_67 )
{
struct V_1 * V_1 = F_13 ( V_11 ) ;
struct V_68 V_69 ;
int V_23 ;
F_21 ( V_67 , & V_69 ) ;
V_23 = F_35 ( V_1 -> V_9 , & V_69 ) ;
if ( V_23 )
return false ;
F_36 ( & V_69 , V_67 ) ;
return true ;
}
static void F_37 ( struct V_10 * V_11 )
{
struct V_1 * V_1 = F_13 ( V_11 ) ;
F_7 ( V_1 ) ;
}
static void F_38 ( struct V_10 * V_11 )
{
struct V_1 * V_1 = F_13 ( V_11 ) ;
F_1 ( V_1 ) ;
}
static int F_39 ( struct V_10 * V_11 )
{
return 0 ;
}
static void F_40 ( struct V_10 * V_11 )
{
struct V_1 * V_1 = F_13 ( V_11 ) ;
V_1 -> V_29 = NULL ;
V_1 -> V_24 = NULL ;
}
static int F_41 ( struct V_10 * V_11 ,
T_3 V_53 , int V_55 , int V_57 )
{
struct V_1 * V_1 = F_13 ( V_11 ) ;
V_1 -> V_53 = V_53 ;
V_1 -> V_56 = V_55 ;
V_1 -> V_58 = V_57 ;
return 0 ;
}
static void F_42 ( struct V_1 * V_1 )
{
if ( ! F_43 ( V_1 -> V_8 ) )
F_44 ( V_1 -> V_8 ) ;
if ( ! F_43 ( V_1 -> V_9 ) )
F_45 ( V_1 -> V_9 ) ;
}
static int F_46 ( struct V_1 * V_1 ,
struct V_70 * V_71 )
{
struct V_2 * V_3 = F_2 ( V_1 -> V_4 -> V_5 ) ;
int V_23 ;
V_1 -> V_8 = F_47 ( V_3 , V_71 -> V_8 ) ;
if ( F_48 ( V_1 -> V_8 ) ) {
V_23 = F_49 ( V_1 -> V_8 ) ;
goto V_72;
}
V_1 -> V_9 = F_50 ( V_3 , V_71 -> V_9 ) ;
if ( F_48 ( V_1 -> V_9 ) ) {
V_23 = F_49 ( V_1 -> V_9 ) ;
goto V_72;
}
return 0 ;
V_72:
F_42 ( V_1 ) ;
return V_23 ;
}
static int F_51 ( struct V_1 * V_1 ,
struct V_70 * V_71 , struct V_36 * V_61 )
{
struct V_2 * V_3 = F_2 ( V_1 -> V_4 -> V_5 ) ;
int V_73 = - V_74 ;
int V_23 ;
V_23 = F_46 ( V_1 , V_71 ) ;
if ( V_23 ) {
F_23 ( V_1 -> V_4 , L_8 ,
V_23 ) ;
return V_23 ;
}
if ( V_71 -> V_73 >= 0 )
V_73 = V_75 ;
V_1 -> V_7 [ 0 ] = F_52 ( V_61 , V_3 , V_71 -> V_76 [ 0 ] , V_73 , 0 ,
V_77 ) ;
if ( F_48 ( V_1 -> V_7 [ 0 ] ) ) {
V_23 = F_49 ( V_1 -> V_7 [ 0 ] ) ;
goto V_78;
}
V_23 = F_53 ( V_61 , & V_1 -> V_27 , & V_1 -> V_26 ,
& V_1 -> V_7 [ 0 ] -> V_27 , & V_79 ,
V_1 -> V_4 -> V_80 ) ;
if ( V_23 ) {
F_23 ( V_1 -> V_4 , L_9 , V_23 ) ;
goto V_78;
}
V_23 = F_54 ( V_1 -> V_7 [ 0 ] ) ;
if ( V_23 ) {
F_23 ( V_1 -> V_4 , L_10 ,
V_23 ) ;
goto V_81;
}
if ( V_71 -> V_73 >= 0 && V_71 -> V_76 [ 1 ] > 0 ) {
V_1 -> V_7 [ 1 ] = F_52 ( V_61 , V_3 , V_71 -> V_76 [ 1 ] ,
V_82 ,
F_55 ( & V_1 -> V_27 ) ,
V_83 ) ;
if ( F_48 ( V_1 -> V_7 [ 1 ] ) )
V_1 -> V_7 [ 1 ] = NULL ;
}
V_1 -> V_63 = F_56 ( V_1 -> V_7 [ 0 ] ) ;
V_23 = F_57 ( V_1 -> V_4 , V_1 -> V_63 , F_31 , 0 ,
L_11 , V_1 ) ;
if ( V_23 < 0 ) {
F_23 ( V_1 -> V_4 , L_12 , V_23 ) ;
goto V_84;
}
return 0 ;
V_84:
F_58 ( V_1 -> V_7 [ 0 ] ) ;
V_81:
F_59 ( V_1 -> V_26 ) ;
V_78:
F_42 ( V_1 ) ;
return V_23 ;
}
static int F_60 ( struct V_85 * V_4 , struct V_85 * V_86 , void * V_87 )
{
struct V_70 * V_71 = V_4 -> V_88 ;
struct V_36 * V_61 = V_87 ;
struct V_1 * V_1 ;
int V_23 ;
V_1 = F_61 ( V_4 , sizeof( * V_1 ) , V_89 ) ;
if ( ! V_1 )
return - V_90 ;
V_1 -> V_4 = V_4 ;
V_23 = F_51 ( V_1 , V_71 , V_61 ) ;
if ( V_23 )
return V_23 ;
F_62 ( V_4 , V_1 ) ;
return 0 ;
}
static void F_63 ( struct V_85 * V_4 , struct V_85 * V_86 ,
void * V_87 )
{
struct V_1 * V_1 = F_2 ( V_4 ) ;
F_59 ( V_1 -> V_26 ) ;
F_58 ( V_1 -> V_7 [ 0 ] ) ;
F_42 ( V_1 ) ;
}
static int F_64 ( struct V_91 * V_92 )
{
struct V_85 * V_4 = & V_92 -> V_4 ;
int V_23 ;
if ( ! V_4 -> V_88 )
return - V_74 ;
V_23 = F_65 ( V_4 , F_66 ( 32 ) ) ;
if ( V_23 )
return V_23 ;
return F_67 ( V_4 , & V_93 ) ;
}
static int F_68 ( struct V_91 * V_92 )
{
F_69 ( & V_92 -> V_4 , & V_93 ) ;
return 0 ;
}
