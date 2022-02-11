static void F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 -> V_4 -> V_5 ) ;
if ( V_1 -> V_6 )
return;
F_3 ( V_3 ) ;
F_4 ( V_1 -> V_7 [ 0 ] ) ;
F_5 ( V_1 -> V_8 ) ;
F_6 ( V_1 -> V_9 ) ;
F_7 ( & V_1 -> V_10 ) ;
V_1 -> V_6 = 1 ;
}
static void F_8 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 -> V_4 -> V_5 ) ;
if ( ! V_1 -> V_6 )
return;
F_9 ( V_1 -> V_8 ) ;
F_10 ( V_1 -> V_9 ) ;
F_11 ( V_1 -> V_7 [ 0 ] ) ;
F_12 ( V_3 ) ;
F_13 ( & V_1 -> V_10 ) ;
V_1 -> V_6 = 0 ;
}
static void F_14 ( struct V_11 * V_12 , int V_13 )
{
struct V_1 * V_1 = F_15 ( V_12 ) ;
F_16 ( V_1 -> V_4 , L_1 , V_14 , V_13 ) ;
switch ( V_13 ) {
case V_15 :
F_1 ( V_1 ) ;
break;
case V_16 :
case V_17 :
case V_18 :
F_8 ( V_1 ) ;
break;
}
}
static int F_17 ( struct V_11 * V_12 ,
struct V_19 * V_20 ,
struct V_21 * V_22 ,
T_1 V_23 )
{
struct V_1 * V_1 = F_15 ( V_12 ) ;
int V_24 ;
if ( V_1 -> V_25 )
return - V_26 ;
V_24 = F_18 ( V_1 -> V_27 ) ;
if ( V_24 ) {
F_16 ( V_1 -> V_4 , L_2 ) ;
F_19 ( & V_22 -> V_10 . V_28 ) ;
return V_24 ;
}
V_1 -> V_25 = V_20 ;
V_1 -> V_29 = V_22 ;
V_12 -> V_30 -> V_20 = V_20 ;
return 0 ;
}
static int F_20 ( struct V_11 * V_12 ,
struct V_31 * V_32 ,
struct V_31 * V_13 ,
int V_33 , int V_34 ,
struct V_19 * V_35 )
{
struct V_36 * V_4 = V_12 -> V_4 ;
struct V_37 * V_38 ;
struct V_1 * V_1 = F_15 ( V_12 ) ;
struct V_39 V_40 = {} ;
unsigned long V_41 = 0 ;
int V_24 ;
F_16 ( V_1 -> V_4 , L_3 , V_14 ,
V_13 -> V_42 ) ;
F_16 ( V_1 -> V_4 , L_4 , V_14 ,
V_13 -> V_43 ) ;
F_21 (encoder, &dev->mode_config.encoder_list, head)
if ( V_38 -> V_12 == V_12 )
V_41 |= F_22 ( V_38 -> V_44 ) ;
F_16 ( V_1 -> V_4 , L_5 ,
V_14 , V_41 ) ;
if ( V_41 & ( F_22 ( V_45 ) |
F_22 ( V_46 ) ) )
V_40 . V_47 = V_48 | V_49 ;
else if ( V_41 & F_22 ( V_50 ) )
V_40 . V_47 = V_49 ;
else
V_40 . V_47 = 0 ;
V_40 . V_51 = 1 ;
V_40 . V_52 = 0 ;
V_40 . V_53 = V_1 -> V_53 ;
V_40 . V_54 = 0 ;
V_40 . V_55 = V_1 -> V_56 ;
V_40 . V_57 = V_1 -> V_58 ;
F_23 ( V_13 , & V_40 . V_13 ) ;
V_24 = F_24 ( V_1 -> V_8 , V_1 -> V_9 ,
V_13 -> V_59 & V_60 ,
V_1 -> V_53 , V_13 -> V_42 ) ;
if ( V_24 ) {
F_25 ( V_1 -> V_4 ,
L_6 ,
V_24 ) ;
return V_24 ;
}
V_24 = F_26 ( V_1 -> V_9 , & V_40 ) ;
if ( V_24 ) {
F_25 ( V_1 -> V_4 ,
L_7 , V_24 ) ;
return V_24 ;
}
return F_27 ( V_1 -> V_7 [ 0 ] , V_12 , V_13 ,
V_12 -> V_30 -> V_20 ,
0 , 0 , V_13 -> V_42 , V_13 -> V_43 ,
V_33 , V_34 , V_13 -> V_42 , V_13 -> V_43 ,
V_13 -> V_59 & V_60 ) ;
}
static void F_28 ( struct V_1 * V_1 )
{
unsigned long V_59 ;
struct V_36 * V_61 = V_1 -> V_10 . V_4 ;
F_29 ( & V_61 -> V_62 , V_59 ) ;
if ( V_1 -> V_29 )
F_30 ( & V_1 -> V_10 ,
V_1 -> V_29 ) ;
V_1 -> V_29 = NULL ;
F_31 ( V_1 -> V_27 ) ;
F_32 ( & V_61 -> V_62 , V_59 ) ;
}
static T_2 F_33 ( int V_63 , void * V_64 )
{
struct V_1 * V_1 = V_64 ;
F_34 ( V_1 -> V_27 ) ;
if ( V_1 -> V_25 ) {
struct V_65 * V_7 = V_1 -> V_7 [ 0 ] ;
V_1 -> V_25 = NULL ;
F_35 ( V_7 , V_1 -> V_10 . V_30 -> V_20 ,
V_7 -> V_33 , V_7 -> V_34 ) ;
F_28 ( V_1 ) ;
}
return V_66 ;
}
static bool F_36 ( struct V_11 * V_12 ,
const struct V_31 * V_13 ,
struct V_31 * V_67 )
{
struct V_1 * V_1 = F_15 ( V_12 ) ;
struct V_68 V_69 ;
int V_24 ;
F_23 ( V_67 , & V_69 ) ;
V_24 = F_37 ( V_1 -> V_9 , & V_69 ) ;
if ( V_24 )
return false ;
F_38 ( & V_69 , V_67 ) ;
return true ;
}
static void F_39 ( struct V_11 * V_12 )
{
struct V_1 * V_1 = F_15 ( V_12 ) ;
F_8 ( V_1 ) ;
}
static void F_40 ( struct V_11 * V_12 )
{
struct V_1 * V_1 = F_15 ( V_12 ) ;
F_1 ( V_1 ) ;
}
static int F_41 ( struct V_11 * V_12 )
{
return 0 ;
}
static void F_42 ( struct V_11 * V_12 )
{
struct V_1 * V_1 = F_15 ( V_12 ) ;
V_1 -> V_29 = NULL ;
V_1 -> V_25 = NULL ;
}
static int F_43 ( struct V_11 * V_12 ,
T_3 V_53 , int V_55 , int V_57 )
{
struct V_1 * V_1 = F_15 ( V_12 ) ;
V_1 -> V_53 = V_53 ;
V_1 -> V_56 = V_55 ;
V_1 -> V_58 = V_57 ;
return 0 ;
}
static void F_44 ( struct V_1 * V_1 )
{
if ( ! F_45 ( V_1 -> V_8 ) )
F_46 ( V_1 -> V_8 ) ;
if ( ! F_45 ( V_1 -> V_9 ) )
F_47 ( V_1 -> V_9 ) ;
}
static int F_48 ( struct V_1 * V_1 ,
struct V_70 * V_71 )
{
struct V_2 * V_3 = F_2 ( V_1 -> V_4 -> V_5 ) ;
int V_24 ;
V_1 -> V_8 = F_49 ( V_3 , V_71 -> V_8 ) ;
if ( F_50 ( V_1 -> V_8 ) ) {
V_24 = F_51 ( V_1 -> V_8 ) ;
goto V_72;
}
V_1 -> V_9 = F_52 ( V_3 , V_71 -> V_9 ) ;
if ( F_50 ( V_1 -> V_9 ) ) {
V_24 = F_51 ( V_1 -> V_9 ) ;
goto V_72;
}
return 0 ;
V_72:
F_44 ( V_1 ) ;
return V_24 ;
}
static int F_53 ( struct V_1 * V_1 ,
struct V_70 * V_71 , struct V_36 * V_61 )
{
struct V_2 * V_3 = F_2 ( V_1 -> V_4 -> V_5 ) ;
int V_73 = - V_74 ;
int V_24 ;
V_24 = F_48 ( V_1 , V_71 ) ;
if ( V_24 ) {
F_25 ( V_1 -> V_4 , L_8 ,
V_24 ) ;
return V_24 ;
}
if ( V_71 -> V_73 >= 0 )
V_73 = V_75 ;
V_1 -> V_7 [ 0 ] = F_54 ( V_61 , V_3 , V_71 -> V_76 [ 0 ] , V_73 , 0 ,
V_77 ) ;
if ( F_50 ( V_1 -> V_7 [ 0 ] ) ) {
V_24 = F_51 ( V_1 -> V_7 [ 0 ] ) ;
goto V_78;
}
V_24 = F_55 ( V_61 , & V_1 -> V_10 , & V_1 -> V_27 ,
& V_1 -> V_7 [ 0 ] -> V_10 , & V_79 ,
V_1 -> V_4 -> V_80 ) ;
if ( V_24 ) {
F_25 ( V_1 -> V_4 , L_9 , V_24 ) ;
goto V_78;
}
V_24 = F_56 ( V_1 -> V_7 [ 0 ] ) ;
if ( V_24 ) {
F_25 ( V_1 -> V_4 , L_10 ,
V_24 ) ;
goto V_81;
}
if ( V_71 -> V_73 >= 0 && V_71 -> V_76 [ 1 ] > 0 ) {
V_1 -> V_7 [ 1 ] = F_54 ( V_61 , V_3 , V_71 -> V_76 [ 1 ] ,
V_82 ,
F_57 ( & V_1 -> V_10 ) ,
V_83 ) ;
if ( F_50 ( V_1 -> V_7 [ 1 ] ) )
V_1 -> V_7 [ 1 ] = NULL ;
}
V_1 -> V_63 = F_58 ( V_1 -> V_7 [ 0 ] ) ;
V_24 = F_59 ( V_1 -> V_4 , V_1 -> V_63 , F_33 , 0 ,
L_11 , V_1 ) ;
if ( V_24 < 0 ) {
F_25 ( V_1 -> V_4 , L_12 , V_24 ) ;
goto V_84;
}
return 0 ;
V_84:
F_60 ( V_1 -> V_7 [ 0 ] ) ;
V_81:
F_61 ( V_1 -> V_27 ) ;
V_78:
F_44 ( V_1 ) ;
return V_24 ;
}
static int F_62 ( struct V_85 * V_4 , struct V_85 * V_86 , void * V_87 )
{
struct V_70 * V_71 = V_4 -> V_88 ;
struct V_36 * V_61 = V_87 ;
struct V_1 * V_1 ;
int V_24 ;
V_1 = F_63 ( V_4 , sizeof( * V_1 ) , V_89 ) ;
if ( ! V_1 )
return - V_90 ;
V_1 -> V_4 = V_4 ;
V_24 = F_53 ( V_1 , V_71 , V_61 ) ;
if ( V_24 )
return V_24 ;
F_64 ( V_4 , V_1 ) ;
return 0 ;
}
static void F_65 ( struct V_85 * V_4 , struct V_85 * V_86 ,
void * V_87 )
{
struct V_1 * V_1 = F_2 ( V_4 ) ;
F_61 ( V_1 -> V_27 ) ;
F_60 ( V_1 -> V_7 [ 0 ] ) ;
F_44 ( V_1 ) ;
}
static int F_66 ( struct V_91 * V_92 )
{
struct V_85 * V_4 = & V_92 -> V_4 ;
int V_24 ;
if ( ! V_4 -> V_88 )
return - V_74 ;
V_24 = F_67 ( V_4 , F_68 ( 32 ) ) ;
if ( V_24 )
return V_24 ;
return F_69 ( V_4 , & V_93 ) ;
}
static int F_70 ( struct V_91 * V_92 )
{
F_71 ( & V_92 -> V_4 , & V_93 ) ;
return 0 ;
}
