static bool F_1 ( int V_1 )
{
return V_1 == V_2 || V_1 == V_3 ;
}
static T_1 F_2 ( int V_1 )
{
switch ( V_1 ) {
case V_2 :
case V_4 :
return V_5 ;
case V_3 :
case V_6 :
return V_7 ;
default:
F_3 () ;
}
}
static void F_4 ( struct V_8 * V_9 , int V_10 )
{
struct V_11 * V_12 = F_5 ( V_9 ) ;
struct V_13 * V_14 ;
F_6 ( & V_15 ) ;
F_7 ( & V_12 -> V_16 ) ;
V_14 = F_8 ( V_12 -> V_17 , 1 ) ;
if ( V_14 )
F_9 ( V_14 ) ;
F_10 ( & V_15 ) ;
}
static int F_11 ( struct V_18 * V_18 , struct V_19 * V_20 ,
struct V_19 * V_21 , struct V_8 * * V_9 , int V_22 ,
int V_10 )
{
struct V_23 * V_24 = F_12 ( V_18 , V_25 ) ;
struct V_19 * V_26 [ V_27 + 1 ] ;
bool V_28 = false ;
struct V_29 * V_30 ;
struct V_11 * V_12 ;
struct V_13 * V_14 ;
bool V_31 = false ;
int V_32 ;
if ( V_20 == NULL )
return - V_33 ;
V_32 = F_13 ( V_26 , V_27 , V_20 , V_34 ) ;
if ( V_32 < 0 )
return V_32 ;
if ( V_26 [ V_35 ] == NULL )
return - V_33 ;
V_30 = F_14 ( V_26 [ V_35 ] ) ;
V_31 = F_15 ( V_24 , V_30 -> V_36 , V_9 , V_10 ) ;
if ( V_31 && V_10 )
return 0 ;
switch ( V_30 -> V_37 ) {
case V_4 :
case V_2 :
case V_3 :
case V_6 :
break;
default:
if ( V_31 )
F_16 ( * V_9 , V_10 ) ;
return - V_33 ;
}
if ( V_30 -> V_38 ) {
V_14 = F_17 ( V_18 , V_30 -> V_38 ) ;
if ( V_14 == NULL ) {
if ( V_31 )
F_16 ( * V_9 , V_10 ) ;
return - V_39 ;
}
V_28 = F_18 ( V_14 ) ;
} else {
V_14 = NULL ;
}
if ( ! V_31 ) {
if ( V_14 == NULL )
return - V_33 ;
V_32 = F_19 ( V_24 , V_30 -> V_36 , V_21 , V_9 ,
& V_40 , V_10 , true ) ;
if ( V_32 )
return V_32 ;
V_32 = V_41 ;
} else {
F_16 ( * V_9 , V_10 ) ;
if ( ! V_22 )
return - V_42 ;
}
V_12 = F_5 ( * V_9 ) ;
F_20 () ;
V_12 -> V_43 = V_30 -> V_1 ;
V_12 -> V_44 = V_30 -> V_37 ;
if ( V_14 != NULL ) {
V_12 -> V_45 = V_30 -> V_38 ;
if ( V_32 != V_41 )
F_9 ( F_8 ( V_12 -> V_17 , 1 ) ) ;
F_21 ( V_14 ) ;
F_22 ( V_12 -> V_17 , V_14 ) ;
V_12 -> V_46 = V_28 ;
}
if ( V_32 == V_41 ) {
F_6 ( & V_15 ) ;
F_23 ( & V_12 -> V_16 , & V_47 ) ;
F_10 ( & V_15 ) ;
F_24 ( V_24 , * V_9 ) ;
}
return V_32 ;
}
static int V_11 ( struct V_48 * V_49 , const struct V_8 * V_9 ,
struct V_50 * V_51 )
{
struct V_11 * V_12 = F_5 ( V_9 ) ;
bool V_52 ;
struct V_13 * V_14 ;
struct V_48 * V_53 ;
int V_54 , V_55 = 0 ;
int V_56 ;
int V_57 ;
T_1 V_58 ;
F_25 ( & V_12 -> V_59 ) ;
F_26 ( F_27 ( V_12 -> V_60 . V_61 ) , V_49 ) ;
F_28 () ;
V_52 = F_29 ( V_12 -> V_46 ) ;
V_56 = F_29 ( V_12 -> V_44 ) ;
V_54 = F_29 ( V_12 -> V_43 ) ;
V_14 = F_30 ( V_12 -> V_17 ) ;
if ( F_31 ( ! V_14 ) ) {
F_32 ( L_1 ) ;
goto V_62;
}
if ( F_31 ( ! ( V_14 -> V_63 & V_64 ) ) ) {
F_33 ( L_2 ,
V_14 -> V_65 ) ;
goto V_62;
}
V_58 = F_34 ( V_49 -> V_66 ) ;
V_53 = F_35 ( V_49 , V_67 ) ;
if ( ! V_53 )
goto V_62;
if ( V_58 != F_2 ( V_56 ) && V_52 ) {
if ( V_58 & V_5 ) {
V_57 = F_36 ( V_49 ) - F_37 ( V_49 ) ;
F_38 ( V_53 , V_57 ) ;
} else {
F_39 ( V_53 , V_49 -> V_57 ) ;
}
}
if ( F_1 ( V_56 ) )
V_53 -> V_66 = F_40 ( V_53 -> V_66 , V_58 ) ;
V_53 -> V_68 = V_49 -> V_14 -> V_38 ;
V_53 -> V_14 = V_14 ;
if ( F_2 ( V_56 ) & V_5 )
V_55 = F_41 ( V_53 ) ;
else
V_55 = F_42 ( V_53 ) ;
if ( V_55 ) {
V_62:
F_43 ( F_27 ( V_12 -> V_60 . V_69 ) ) ;
if ( F_1 ( V_56 ) )
V_54 = V_70 ;
}
F_44 () ;
return V_54 ;
}
static void F_45 ( struct V_8 * V_9 , T_2 V_71 , T_1 V_72 ,
T_2 V_73 )
{
struct V_11 * V_12 = F_5 ( V_9 ) ;
struct V_74 * V_75 = & V_12 -> V_59 ;
F_46 ( F_27 ( V_9 -> V_61 ) , V_71 , V_72 ) ;
V_75 -> V_73 = V_73 ;
}
static int F_47 ( struct V_48 * V_49 , struct V_8 * V_9 , int V_10 ,
int V_76 )
{
unsigned char * V_77 = F_48 ( V_49 ) ;
struct V_11 * V_12 = F_5 ( V_9 ) ;
struct V_29 V_78 = {
. V_36 = V_12 -> V_79 ,
. V_1 = V_12 -> V_43 ,
. V_80 = V_12 -> V_81 - V_76 ,
. V_82 = V_12 -> V_83 - V_10 ,
. V_37 = V_12 -> V_44 ,
. V_38 = V_12 -> V_45 ,
} ;
struct V_74 V_84 ;
if ( F_49 ( V_49 , V_35 , sizeof( V_78 ) , & V_78 ) )
goto V_85;
F_50 ( & V_84 , & V_12 -> V_59 ) ;
if ( F_51 ( V_49 , V_86 , sizeof( V_84 ) , & V_84 , V_87 ) )
goto V_85;
return V_49 -> V_88 ;
V_85:
F_52 ( V_49 , V_77 ) ;
return - 1 ;
}
static int F_53 ( struct V_18 * V_18 , struct V_48 * V_49 ,
struct V_89 * V_90 , int type ,
const struct V_91 * V_92 )
{
struct V_23 * V_24 = F_12 ( V_18 , V_25 ) ;
return F_54 ( V_24 , V_49 , V_90 , type , V_92 ) ;
}
static int F_55 ( struct V_18 * V_18 , struct V_8 * * V_9 , T_1 V_36 )
{
struct V_23 * V_24 = F_12 ( V_18 , V_25 ) ;
return F_56 ( V_24 , V_9 , V_36 ) ;
}
static int F_57 ( struct V_93 * V_94 ,
unsigned long V_95 , void * V_96 )
{
struct V_13 * V_14 = F_58 ( V_96 ) ;
struct V_11 * V_12 ;
F_20 () ;
if ( V_95 == V_97 ) {
F_6 ( & V_15 ) ;
F_59 (m, &mirred_list, tcfm_list) {
if ( F_60 ( V_12 -> V_17 ) == V_14 ) {
F_9 ( V_14 ) ;
F_61 ( V_12 -> V_17 , NULL ) ;
}
}
F_10 ( & V_15 ) ;
}
return V_98 ;
}
static int F_62 ( const struct V_8 * V_9 , struct V_18 * V_18 ,
struct V_13 * * V_99 )
{
int V_38 = F_63 ( V_9 ) ;
* V_99 = F_17 ( V_18 , V_38 ) ;
if ( ! * V_99 )
return - V_33 ;
return 0 ;
}
static T_3 int F_64 ( struct V_18 * V_18 )
{
struct V_23 * V_24 = F_12 ( V_18 , V_25 ) ;
return F_65 ( V_24 , & V_40 , V_100 ) ;
}
static void T_4 F_66 ( struct V_18 * V_18 )
{
struct V_23 * V_24 = F_12 ( V_18 , V_25 ) ;
F_67 ( V_24 ) ;
}
static int T_5 F_68 ( void )
{
int V_55 = F_69 ( & V_101 ) ;
if ( V_55 )
return V_55 ;
F_70 ( L_3 ) ;
return F_71 ( & V_40 , & V_102 ) ;
}
static void T_6 F_72 ( void )
{
F_73 ( & V_40 , & V_102 ) ;
F_74 ( & V_101 ) ;
}
