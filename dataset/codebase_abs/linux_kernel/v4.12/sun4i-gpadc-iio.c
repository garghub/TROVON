static unsigned int F_1 ( unsigned int V_1 )
{
return F_2 ( V_1 ) ;
}
static unsigned int F_3 ( unsigned int V_1 )
{
return F_4 ( V_1 ) ;
}
static int F_5 ( struct V_2 * V_3 , int V_4 ,
unsigned int V_5 )
{
struct V_6 * V_7 = F_6 ( V_3 ) ;
int V_8 ;
T_1 V_9 ;
F_7 ( V_3 -> V_10 . V_11 ) ;
F_8 ( & V_7 -> V_12 ) ;
V_8 = F_9 ( V_7 -> V_13 , V_14 ,
F_10 ( 1 ) |
V_15 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_11 ( V_7 -> V_13 , V_16 , & V_9 ) ;
if ( V_8 )
return V_8 ;
if ( V_5 == V_7 -> V_17 ) {
V_8 = F_9 ( V_7 -> V_13 , V_16 ,
V_7 -> V_18 -> V_19 |
V_7 -> V_18 -> V_20 |
V_7 -> V_18 -> V_21 ( V_4 ) ) ;
if ( ( V_9 & V_7 -> V_18 -> V_22 ) !=
V_7 -> V_18 -> V_21 ( V_4 ) )
F_12 ( 10 ) ;
} else {
V_8 = F_9 ( V_7 -> V_13 , V_16 ,
V_7 -> V_18 -> V_19 ) ;
}
if ( V_8 )
return V_8 ;
if ( ( V_9 & V_7 -> V_18 -> V_20 ) != V_7 -> V_18 -> V_20 )
F_12 ( 100 ) ;
return 0 ;
}
static int F_13 ( struct V_2 * V_3 , int V_4 , int * V_23 ,
unsigned int V_5 )
{
struct V_6 * V_7 = F_6 ( V_3 ) ;
int V_8 ;
F_14 ( & V_7 -> V_24 ) ;
V_8 = F_5 ( V_3 , V_4 , V_5 ) ;
if ( V_8 )
goto V_25;
F_15 ( V_5 ) ;
if ( ! F_16 ( & V_7 -> V_12 ,
F_17 ( 1000 ) ) ) {
V_8 = - V_26 ;
goto V_25;
}
if ( V_5 == V_7 -> V_17 )
* V_23 = V_7 -> V_27 ;
else
* V_23 = V_7 -> V_28 ;
V_8 = 0 ;
F_18 ( V_3 -> V_10 . V_11 ) ;
V_25:
F_19 ( V_3 -> V_10 . V_11 ) ;
F_20 ( & V_7 -> V_24 ) ;
return V_8 ;
}
static int F_21 ( struct V_2 * V_3 , int V_4 ,
int * V_23 )
{
struct V_6 * V_7 = F_6 ( V_3 ) ;
return F_13 ( V_3 , V_4 , V_23 , V_7 -> V_17 ) ;
}
static int F_22 ( struct V_2 * V_3 , int * V_23 )
{
struct V_6 * V_7 = F_6 ( V_3 ) ;
if ( V_7 -> V_29 ) {
F_7 ( V_3 -> V_10 . V_11 ) ;
F_11 ( V_7 -> V_13 , V_30 , V_23 ) ;
F_18 ( V_3 -> V_10 . V_11 ) ;
F_19 ( V_3 -> V_10 . V_11 ) ;
return 0 ;
}
return F_13 ( V_3 , 0 , V_23 , V_7 -> V_31 ) ;
}
static int F_23 ( struct V_2 * V_3 , int * V_23 )
{
struct V_6 * V_7 = F_6 ( V_3 ) ;
* V_23 = V_7 -> V_18 -> V_32 ;
return 0 ;
}
static int F_24 ( struct V_2 * V_3 , int * V_23 )
{
struct V_6 * V_7 = F_6 ( V_3 ) ;
* V_23 = V_7 -> V_18 -> V_33 ;
return 0 ;
}
static int F_25 ( struct V_2 * V_3 ,
struct V_34 const * V_1 , int * V_23 ,
int * V_35 , long V_36 )
{
int V_8 ;
switch ( V_36 ) {
case V_37 :
V_8 = F_23 ( V_3 , V_23 ) ;
if ( V_8 )
return V_8 ;
return V_38 ;
case V_39 :
if ( V_1 -> type == V_40 )
V_8 = F_21 ( V_3 , V_1 -> V_4 ,
V_23 ) ;
else
V_8 = F_22 ( V_3 , V_23 ) ;
if ( V_8 )
return V_8 ;
return V_38 ;
case V_41 :
if ( V_1 -> type == V_40 ) {
* V_23 = 0 ;
* V_35 = 732421875 ;
return V_42 ;
}
V_8 = F_24 ( V_3 , V_23 ) ;
if ( V_8 )
return V_8 ;
return V_38 ;
default:
return - V_43 ;
}
return - V_43 ;
}
static T_2 F_26 ( int V_5 , void * V_44 )
{
struct V_6 * V_7 = V_44 ;
if ( F_27 ( & V_7 -> V_45 ) )
goto V_46;
if ( ! F_11 ( V_7 -> V_13 , V_30 , & V_7 -> V_28 ) )
F_28 ( & V_7 -> V_12 ) ;
V_46:
F_29 ( V_7 -> V_31 ) ;
return V_47 ;
}
static T_2 F_30 ( int V_5 , void * V_44 )
{
struct V_6 * V_7 = V_44 ;
if ( F_27 ( & V_7 -> V_48 ) )
goto V_46;
if ( ! F_11 ( V_7 -> V_13 , V_49 , & V_7 -> V_27 ) )
F_28 ( & V_7 -> V_12 ) ;
V_46:
F_29 ( V_7 -> V_17 ) ;
return V_47 ;
}
static int F_31 ( struct V_50 * V_10 )
{
struct V_6 * V_7 = F_6 ( F_32 ( V_10 ) ) ;
F_9 ( V_7 -> V_13 , V_16 , 0 ) ;
F_9 ( V_7 -> V_13 , V_51 , 0 ) ;
return 0 ;
}
static int F_33 ( struct V_50 * V_10 )
{
struct V_6 * V_7 = F_6 ( F_32 ( V_10 ) ) ;
F_9 ( V_7 -> V_13 , V_52 ,
F_34 ( 2 ) |
F_35 ( 7 ) |
F_36 ( 63 ) ) ;
F_9 ( V_7 -> V_13 , V_16 , V_7 -> V_18 -> V_19 ) ;
F_9 ( V_7 -> V_13 , V_53 ,
V_54 |
F_37 ( 1 ) ) ;
F_9 ( V_7 -> V_13 , V_51 ,
V_55 |
F_38 ( 800 ) ) ;
return 0 ;
}
static int F_39 ( void * V_18 , int * V_56 )
{
struct V_6 * V_7 = V_18 ;
int V_23 , V_57 , V_58 ;
if ( F_22 ( V_7 -> V_3 , & V_23 ) )
return - V_26 ;
F_24 ( V_7 -> V_3 , & V_57 ) ;
F_23 ( V_7 -> V_3 , & V_58 ) ;
* V_56 = ( V_23 + V_58 ) * V_57 ;
return 0 ;
}
static int F_40 ( struct V_59 * V_60 , const char * V_61 ,
T_3 V_62 , const char * V_63 ,
unsigned int * V_5 , T_4 * V_64 )
{
int V_8 ;
struct V_65 * V_66 = F_32 ( V_60 -> V_10 . V_11 ) ;
struct V_6 * V_7 = F_6 ( F_32 ( & V_60 -> V_10 ) ) ;
F_41 ( V_64 , 1 ) ;
V_8 = F_42 ( V_60 , V_61 ) ;
if ( V_8 < 0 ) {
F_43 ( & V_60 -> V_10 , L_1 , V_61 ) ;
return V_8 ;
}
V_8 = F_44 ( V_66 -> V_67 , V_8 ) ;
if ( V_8 < 0 ) {
F_43 ( & V_60 -> V_10 , L_2 , V_61 ) ;
return V_8 ;
}
* V_5 = V_8 ;
V_8 = F_45 ( & V_60 -> V_10 , * V_5 , V_62 , 0 ,
V_63 , V_7 ) ;
if ( V_8 < 0 ) {
F_43 ( & V_60 -> V_10 , L_3 ,
V_61 , V_8 ) ;
return V_8 ;
}
F_46 ( * V_5 ) ;
F_41 ( V_64 , 0 ) ;
return 0 ;
}
static int F_47 ( struct V_59 * V_60 ,
struct V_2 * V_3 )
{
struct V_6 * V_7 = F_6 ( V_3 ) ;
const struct V_68 * V_69 ;
struct V_70 * V_71 ;
void T_5 * V_72 ;
int V_8 ;
V_69 = F_48 ( V_73 , & V_60 -> V_10 ) ;
if ( ! V_69 )
return - V_74 ;
V_7 -> V_29 = true ;
V_7 -> V_18 = (struct V_75 * ) V_69 -> V_18 ;
V_3 -> V_76 = F_49 ( V_77 ) ;
V_3 -> V_78 = V_77 ;
V_71 = F_50 ( V_60 , V_79 , 0 ) ;
V_72 = F_51 ( & V_60 -> V_10 , V_71 ) ;
if ( F_52 ( V_72 ) )
return F_53 ( V_72 ) ;
V_7 -> V_13 = F_54 ( & V_60 -> V_10 , V_72 ,
& V_80 ) ;
if ( F_52 ( V_7 -> V_13 ) ) {
V_8 = F_53 ( V_7 -> V_13 ) ;
F_43 ( & V_60 -> V_10 , L_4 , V_8 ) ;
return V_8 ;
}
if ( ! F_55 ( V_81 ) )
return 0 ;
V_7 -> V_82 = & V_60 -> V_10 ;
V_7 -> V_83 = F_56 ( V_7 -> V_82 , 0 ,
V_7 , & V_84 ) ;
if ( F_52 ( V_7 -> V_83 ) )
F_43 ( & V_60 -> V_10 , L_5 ,
F_53 ( V_7 -> V_83 ) ) ;
return F_57 ( V_7 -> V_83 ) ;
}
static int F_58 ( struct V_59 * V_60 ,
struct V_2 * V_3 )
{
struct V_6 * V_7 = F_6 ( V_3 ) ;
struct V_65 * V_65 =
F_32 ( V_60 -> V_10 . V_11 ) ;
int V_8 ;
V_7 -> V_29 = false ;
V_7 -> V_13 = V_65 -> V_13 ;
V_3 -> V_76 = F_49 ( V_85 ) ;
V_3 -> V_78 = V_85 ;
V_7 -> V_18 = (struct V_75 * ) F_59 ( V_60 ) -> V_86 ;
if ( F_55 ( V_81 ) ) {
V_7 -> V_82 = V_60 -> V_10 . V_11 ;
V_7 -> V_83 = F_56 ( V_7 -> V_82 ,
0 , V_7 ,
& V_84 ) ;
if ( F_52 ( V_7 -> V_83 ) ) {
F_43 ( & V_60 -> V_10 ,
L_5 ,
F_53 ( V_7 -> V_83 ) ) ;
return F_53 ( V_7 -> V_83 ) ;
}
} else {
V_3 -> V_76 =
F_49 ( V_87 ) ;
V_3 -> V_78 = V_87 ;
}
if ( F_55 ( V_81 ) ) {
V_8 = F_40 ( V_60 , L_6 ,
F_26 ,
L_7 , & V_7 -> V_31 ,
& V_7 -> V_45 ) ;
if ( V_8 < 0 )
return V_8 ;
}
V_8 = F_40 ( V_60 , L_8 ,
F_30 , L_9 ,
& V_7 -> V_17 , & V_7 -> V_48 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( F_55 ( V_81 ) ) {
V_8 = F_60 ( V_3 , V_88 ) ;
if ( V_8 < 0 ) {
F_43 ( & V_60 -> V_10 ,
L_10 ) ;
return V_8 ;
}
}
return 0 ;
}
static int F_61 ( struct V_59 * V_60 )
{
struct V_6 * V_7 ;
struct V_2 * V_3 ;
int V_8 ;
V_3 = F_62 ( & V_60 -> V_10 , sizeof( * V_7 ) ) ;
if ( ! V_3 )
return - V_89 ;
V_7 = F_6 ( V_3 ) ;
F_63 ( V_60 , V_3 ) ;
F_64 ( & V_7 -> V_24 ) ;
V_7 -> V_3 = V_3 ;
F_65 ( & V_7 -> V_12 ) ;
V_3 -> V_61 = F_66 ( & V_60 -> V_10 ) ;
V_3 -> V_10 . V_11 = & V_60 -> V_10 ;
V_3 -> V_10 . V_90 = V_60 -> V_10 . V_90 ;
V_3 -> V_7 = & V_91 ;
V_3 -> V_92 = V_93 ;
if ( V_60 -> V_10 . V_90 )
V_8 = F_47 ( V_60 , V_3 ) ;
else
V_8 = F_58 ( V_60 , V_3 ) ;
if ( V_8 )
return V_8 ;
F_67 ( & V_60 -> V_10 ,
V_94 ) ;
F_68 ( & V_60 -> V_10 ) ;
F_69 ( & V_60 -> V_10 ) ;
F_70 ( & V_60 -> V_10 ) ;
V_8 = F_71 ( & V_60 -> V_10 , V_3 ) ;
if ( V_8 < 0 ) {
F_43 ( & V_60 -> V_10 , L_11 ) ;
goto V_95;
}
return 0 ;
V_95:
if ( ! V_7 -> V_29 && F_55 ( V_81 ) )
F_72 ( V_3 ) ;
F_73 ( & V_60 -> V_10 ) ;
F_74 ( & V_60 -> V_10 ) ;
return V_8 ;
}
static int F_75 ( struct V_59 * V_60 )
{
struct V_2 * V_3 = F_76 ( V_60 ) ;
struct V_6 * V_7 = F_6 ( V_3 ) ;
F_73 ( & V_60 -> V_10 ) ;
F_74 ( & V_60 -> V_10 ) ;
if ( ! F_55 ( V_81 ) )
return 0 ;
F_77 ( V_7 -> V_82 , V_7 -> V_83 ) ;
if ( ! V_7 -> V_29 )
F_72 ( V_3 ) ;
return 0 ;
}
