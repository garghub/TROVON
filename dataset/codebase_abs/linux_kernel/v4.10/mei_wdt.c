static const char * F_1 ( enum V_1 V_2 )
{
switch ( V_2 ) {
case V_3 :
return L_1 ;
case V_4 :
return L_2 ;
case V_5 :
return L_3 ;
case V_6 :
return L_4 ;
case V_7 :
return L_5 ;
case V_8 :
return L_6 ;
default:
return L_7 ;
}
}
static int F_2 ( struct V_9 * V_10 )
{
struct V_11 V_12 ;
const T_1 V_13 = sizeof( V_12 ) ;
int V_14 ;
memset ( & V_12 , 0 , V_13 ) ;
V_12 . V_15 . V_16 = V_17 ;
V_12 . V_15 . V_18 = V_13 - F_3 ( struct V_19 , V_20 ) ;
V_12 . V_15 . V_20 = V_21 ;
V_12 . V_15 . V_22 = V_23 ;
V_12 . V_24 = V_10 -> V_24 ;
V_14 = F_4 ( V_10 -> V_25 , ( V_26 * ) & V_12 , V_13 ) ;
if ( V_14 < 0 )
return V_14 ;
return 0 ;
}
static int F_5 ( struct V_9 * V_10 )
{
struct V_27 V_12 ;
const T_1 V_13 = sizeof( V_12 ) ;
int V_14 ;
memset ( & V_12 , 0 , V_13 ) ;
V_12 . V_15 . V_16 = V_17 ;
V_12 . V_15 . V_18 = V_13 - F_3 ( struct V_19 , V_20 ) ;
V_12 . V_15 . V_20 = V_28 ;
V_12 . V_15 . V_22 = V_23 ;
V_14 = F_4 ( V_10 -> V_25 , ( V_26 * ) & V_12 , V_13 ) ;
if ( V_14 < 0 )
return V_14 ;
return 0 ;
}
static int F_6 ( struct V_29 * V_30 )
{
struct V_9 * V_10 = F_7 ( V_30 ) ;
V_10 -> V_2 = V_5 ;
V_30 -> V_24 = V_10 -> V_24 ;
return 0 ;
}
static int F_8 ( struct V_29 * V_30 )
{
struct V_9 * V_10 = F_7 ( V_30 ) ;
int V_14 ;
if ( V_10 -> V_2 != V_6 )
return 0 ;
V_10 -> V_2 = V_7 ;
V_14 = F_5 ( V_10 ) ;
if ( V_14 )
return V_14 ;
V_10 -> V_2 = V_4 ;
return 0 ;
}
static int F_9 ( struct V_29 * V_30 )
{
struct V_9 * V_10 = F_7 ( V_30 ) ;
int V_14 ;
if ( V_10 -> V_2 != V_5 && V_10 -> V_2 != V_6 )
return 0 ;
if ( V_10 -> V_31 )
F_10 ( & V_10 -> V_32 ) ;
V_10 -> V_2 = V_6 ;
V_14 = F_2 ( V_10 ) ;
if ( V_14 )
return V_14 ;
if ( V_10 -> V_31 )
V_14 = F_11 ( & V_10 -> V_32 ) ;
return V_14 ;
}
static int F_12 ( struct V_29 * V_30 ,
unsigned int V_24 )
{
struct V_9 * V_10 = F_7 ( V_30 ) ;
V_10 -> V_24 = V_24 ;
V_30 -> V_24 = V_24 ;
return 0 ;
}
static inline bool F_13 ( struct V_9 * V_10 )
{
return ! ! F_7 ( & V_10 -> V_30 ) ;
}
static void F_14 ( struct V_9 * V_10 )
{
F_15 ( & V_10 -> V_33 ) ;
if ( F_13 ( V_10 ) ) {
F_16 ( & V_10 -> V_30 ) ;
F_17 ( & V_10 -> V_30 , NULL ) ;
memset ( & V_10 -> V_30 , 0 , sizeof( V_10 -> V_30 ) ) ;
}
F_18 ( & V_10 -> V_33 ) ;
}
static int F_19 ( struct V_9 * V_10 )
{
struct V_34 * V_35 ;
int V_14 ;
if ( ! V_10 || ! V_10 -> V_25 )
return - V_36 ;
V_35 = & V_10 -> V_25 -> V_35 ;
F_15 ( & V_10 -> V_33 ) ;
if ( F_13 ( V_10 ) ) {
V_14 = 0 ;
goto V_37;
}
V_10 -> V_30 . V_38 = & V_39 ;
V_10 -> V_30 . V_40 = & V_41 ;
V_10 -> V_30 . V_42 = V_35 ;
V_10 -> V_30 . V_24 = V_43 ;
V_10 -> V_30 . V_44 = V_45 ;
V_10 -> V_30 . V_46 = V_47 ;
F_17 ( & V_10 -> V_30 , V_10 ) ;
F_20 ( & V_10 -> V_30 ) ;
V_14 = F_21 ( & V_10 -> V_30 ) ;
if ( V_14 ) {
F_22 ( V_35 , L_8 , V_14 ) ;
F_17 ( & V_10 -> V_30 , NULL ) ;
}
V_10 -> V_2 = V_4 ;
V_37:
F_18 ( & V_10 -> V_33 ) ;
return V_14 ;
}
static void F_23 ( struct V_48 * V_49 )
{
struct V_9 * V_10 = F_24 ( V_49 , struct V_9 , V_50 ) ;
F_14 ( V_10 ) ;
}
static void F_25 ( struct V_51 * V_25 )
{
struct V_9 * V_10 = F_26 ( V_25 ) ;
struct V_52 V_53 ;
const T_1 V_54 = sizeof( V_53 ) ;
int V_14 ;
V_14 = F_27 ( V_10 -> V_25 , ( V_26 * ) & V_53 , V_54 ) ;
if ( V_14 < 0 ) {
F_22 ( & V_25 -> V_35 , L_9 , V_14 ) ;
return;
}
if ( V_14 == 0 )
return;
if ( V_14 < sizeof( struct V_19 ) ) {
F_22 ( & V_25 -> V_35 , L_10 , V_14 ) ;
return;
}
if ( V_53 . V_15 . V_16 != V_17 ||
V_53 . V_15 . V_22 != V_23 ) {
F_22 ( & V_25 -> V_35 , L_11 ) ;
return;
}
if ( V_53 . V_15 . V_20 != V_55 ) {
F_28 ( & V_25 -> V_35 , L_12 ,
V_53 . V_15 . V_20 ,
F_1 ( V_10 -> V_2 ) ,
V_10 -> V_2 ) ;
return;
}
if ( V_10 -> V_2 == V_6 ) {
if ( V_53 . V_56 & V_57 ) {
V_10 -> V_2 = V_8 ;
F_29 ( & V_10 -> V_50 ) ;
}
goto V_37;
}
if ( V_10 -> V_2 == V_3 ) {
if ( V_53 . V_56 & V_57 ) {
V_10 -> V_2 = V_8 ;
} else {
F_5 ( V_10 ) ;
F_19 ( V_10 ) ;
}
return;
}
F_28 ( & V_25 -> V_35 , L_13 ,
F_1 ( V_10 -> V_2 ) , V_10 -> V_2 ) ;
V_37:
if ( ! F_30 ( & V_10 -> V_32 ) )
F_31 ( & V_10 -> V_32 ) ;
}
static void F_32 ( struct V_51 * V_25 )
{
struct V_9 * V_10 = F_26 ( V_25 ) ;
if ( V_10 -> V_2 != V_8 )
return;
F_19 ( V_10 ) ;
}
static T_2 F_33 ( struct V_58 * V_58 , char T_3 * V_59 ,
T_1 V_60 , T_4 * V_61 )
{
struct V_9 * V_10 = V_58 -> V_62 ;
const T_1 V_63 = 32 ;
char V_64 [ 32 ] ;
T_2 V_65 ;
F_15 ( & V_10 -> V_33 ) ;
V_65 = F_34 ( V_64 , V_63 , L_14 ,
F_13 ( V_10 ) ? L_15 : L_16 ) ;
F_18 ( & V_10 -> V_33 ) ;
return F_35 ( V_59 , V_60 , V_61 , V_64 , V_65 ) ;
}
static T_2 F_36 ( struct V_58 * V_58 , char T_3 * V_59 ,
T_1 V_60 , T_4 * V_61 )
{
struct V_9 * V_10 = V_58 -> V_62 ;
const T_1 V_63 = 32 ;
char V_64 [ V_63 ] ;
T_2 V_65 ;
V_65 = F_34 ( V_64 , V_63 , L_17 ,
F_1 ( V_10 -> V_2 ) ) ;
return F_35 ( V_59 , V_60 , V_61 , V_64 , V_65 ) ;
}
static void F_37 ( struct V_9 * V_10 )
{
F_38 ( V_10 -> V_66 ) ;
V_10 -> V_66 = NULL ;
}
static int F_39 ( struct V_9 * V_10 )
{
struct V_67 * V_68 , * V_69 ;
V_68 = F_40 ( V_70 , NULL ) ;
if ( ! V_68 )
return - V_71 ;
V_10 -> V_66 = V_68 ;
V_69 = F_41 ( L_18 , V_72 , V_68 , V_10 , & V_73 ) ;
if ( ! V_69 )
goto V_74;
V_69 = F_41 ( L_19 , V_72 ,
V_68 , V_10 , & V_75 ) ;
if ( ! V_69 )
goto V_74;
return 0 ;
V_74:
F_37 ( V_10 ) ;
return - V_76 ;
}
static inline void F_37 ( struct V_9 * V_10 ) {}
static inline int F_39 ( struct V_9 * V_10 )
{
return 0 ;
}
static int F_42 ( struct V_51 * V_25 ,
const struct V_77 * V_78 )
{
struct V_9 * V_10 ;
int V_14 ;
V_10 = F_43 ( sizeof( struct V_9 ) , V_79 ) ;
if ( ! V_10 )
return - V_71 ;
V_10 -> V_24 = V_43 ;
V_10 -> V_2 = V_3 ;
V_10 -> V_25 = V_25 ;
V_10 -> V_31 = F_44 ( V_25 ) > 0x1 ;
F_45 ( & V_10 -> V_33 ) ;
F_10 ( & V_10 -> V_32 ) ;
F_46 ( & V_10 -> V_50 , F_23 ) ;
F_47 ( V_25 , V_10 ) ;
V_14 = F_48 ( V_25 ) ;
if ( V_14 < 0 ) {
F_22 ( & V_25 -> V_35 , L_20 ) ;
goto V_80;
}
V_14 = F_49 ( V_10 -> V_25 , F_25 ) ;
if ( V_14 ) {
F_22 ( & V_25 -> V_35 , L_21 , V_14 ) ;
goto V_81;
}
V_14 = F_50 ( V_10 -> V_25 , F_32 ) ;
if ( V_14 && V_14 != - V_82 ) {
F_22 ( & V_25 -> V_35 , L_22 , V_14 ) ;
goto V_81;
}
V_39 . V_83 = F_44 ( V_25 ) ;
if ( V_10 -> V_31 )
V_14 = F_2 ( V_10 ) ;
else
V_14 = F_19 ( V_10 ) ;
if ( V_14 )
goto V_81;
if ( F_39 ( V_10 ) )
F_28 ( & V_25 -> V_35 , L_23 ) ;
return 0 ;
V_81:
F_51 ( V_25 ) ;
V_80:
F_52 ( V_10 ) ;
return V_14 ;
}
static int F_53 ( struct V_51 * V_25 )
{
struct V_9 * V_10 = F_26 ( V_25 ) ;
if ( ! F_30 ( & V_10 -> V_32 ) )
F_31 ( & V_10 -> V_32 ) ;
F_54 ( & V_10 -> V_50 ) ;
F_14 ( V_10 ) ;
F_51 ( V_25 ) ;
F_37 ( V_10 ) ;
F_52 ( V_10 ) ;
return 0 ;
}
