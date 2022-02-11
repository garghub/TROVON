static bool F_1 ( int V_1 )
{
return V_1 == V_2 || V_1 == V_3 ;
}
static bool F_2 ( int V_1 )
{
switch ( V_1 ) {
case V_2 :
case V_4 :
return false ;
case V_3 :
case V_5 :
return true ;
default:
F_3 () ;
}
}
static void F_4 ( struct V_6 * V_7 , int V_8 )
{
struct V_9 * V_10 = F_5 ( V_7 ) ;
struct V_11 * V_12 ;
F_6 ( & V_13 ) ;
F_7 ( & V_10 -> V_14 ) ;
V_12 = F_8 ( V_10 -> V_15 , 1 ) ;
if ( V_12 )
F_9 ( V_12 ) ;
F_10 ( & V_13 ) ;
}
static int F_11 ( struct V_16 * V_16 , struct V_17 * V_18 ,
struct V_17 * V_19 , struct V_6 * * V_7 , int V_20 ,
int V_8 )
{
struct V_21 * V_22 = F_12 ( V_16 , V_23 ) ;
struct V_17 * V_24 [ V_25 + 1 ] ;
bool V_26 = false ;
struct V_27 * V_28 ;
struct V_9 * V_10 ;
struct V_11 * V_12 ;
bool V_29 = false ;
int V_30 ;
if ( V_18 == NULL )
return - V_31 ;
V_30 = F_13 ( V_24 , V_25 , V_18 , V_32 , NULL ) ;
if ( V_30 < 0 )
return V_30 ;
if ( V_24 [ V_33 ] == NULL )
return - V_31 ;
V_28 = F_14 ( V_24 [ V_33 ] ) ;
V_29 = F_15 ( V_22 , V_28 -> V_34 , V_7 , V_8 ) ;
if ( V_29 && V_8 )
return 0 ;
switch ( V_28 -> V_35 ) {
case V_4 :
case V_2 :
case V_3 :
case V_5 :
break;
default:
if ( V_29 )
F_16 ( * V_7 , V_8 ) ;
return - V_31 ;
}
if ( V_28 -> V_36 ) {
V_12 = F_17 ( V_16 , V_28 -> V_36 ) ;
if ( V_12 == NULL ) {
if ( V_29 )
F_16 ( * V_7 , V_8 ) ;
return - V_37 ;
}
V_26 = F_18 ( V_12 ) ;
} else {
V_12 = NULL ;
}
if ( ! V_29 ) {
if ( V_12 == NULL )
return - V_31 ;
V_30 = F_19 ( V_22 , V_28 -> V_34 , V_19 , V_7 ,
& V_38 , V_8 , true ) ;
if ( V_30 )
return V_30 ;
V_30 = V_39 ;
} else {
F_16 ( * V_7 , V_8 ) ;
if ( ! V_20 )
return - V_40 ;
}
V_10 = F_5 ( * V_7 ) ;
F_20 () ;
V_10 -> V_41 = V_28 -> V_1 ;
V_10 -> V_42 = V_28 -> V_35 ;
if ( V_12 != NULL ) {
V_10 -> V_43 = V_28 -> V_36 ;
if ( V_30 != V_39 )
F_9 ( F_8 ( V_10 -> V_15 , 1 ) ) ;
F_21 ( V_12 ) ;
F_22 ( V_10 -> V_15 , V_12 ) ;
V_10 -> V_44 = V_26 ;
}
if ( V_30 == V_39 ) {
F_6 ( & V_13 ) ;
F_23 ( & V_10 -> V_14 , & V_45 ) ;
F_10 ( & V_13 ) ;
F_24 ( V_22 , * V_7 ) ;
}
return V_30 ;
}
static int V_9 ( struct V_46 * V_47 , const struct V_6 * V_7 ,
struct V_48 * V_49 )
{
struct V_9 * V_10 = F_5 ( V_7 ) ;
bool V_50 ;
struct V_11 * V_12 ;
struct V_46 * V_51 ;
int V_52 , V_53 = 0 ;
int V_54 ;
int V_55 ;
F_25 ( & V_10 -> V_56 ) ;
F_26 ( F_27 ( V_10 -> V_57 . V_58 ) , V_47 ) ;
F_28 () ;
V_50 = F_29 ( V_10 -> V_44 ) ;
V_54 = F_29 ( V_10 -> V_42 ) ;
V_52 = F_29 ( V_10 -> V_41 ) ;
V_12 = F_30 ( V_10 -> V_15 ) ;
if ( F_31 ( ! V_12 ) ) {
F_32 ( L_1 ) ;
goto V_59;
}
if ( F_31 ( ! ( V_12 -> V_60 & V_61 ) ) ) {
F_33 ( L_2 ,
V_12 -> V_62 ) ;
goto V_59;
}
V_51 = F_34 ( V_47 , V_63 ) ;
if ( ! V_51 )
goto V_59;
if ( F_35 ( V_47 ) != F_2 ( V_54 ) &&
V_50 ) {
if ( ! F_35 ( V_47 ) ) {
V_55 = F_36 ( V_47 ) - F_37 ( V_47 ) ;
F_38 ( V_51 , V_55 ) ;
} else {
F_39 ( V_51 , V_47 -> V_55 ) ;
}
}
if ( F_1 ( V_54 ) ) {
V_51 -> V_64 = 1 ;
V_51 -> V_65 = V_51 -> V_66 ;
}
V_51 -> V_67 = V_47 -> V_12 -> V_36 ;
V_51 -> V_12 = V_12 ;
if ( ! F_2 ( V_54 ) )
V_53 = F_40 ( V_51 ) ;
else
V_53 = F_41 ( V_51 ) ;
if ( V_53 ) {
V_59:
F_42 ( F_27 ( V_10 -> V_57 . V_68 ) ) ;
if ( F_1 ( V_54 ) )
V_52 = V_69 ;
}
F_43 () ;
return V_52 ;
}
static void F_44 ( struct V_6 * V_7 , T_1 V_70 , T_2 V_71 ,
T_1 V_72 )
{
struct V_9 * V_10 = F_5 ( V_7 ) ;
struct V_73 * V_74 = & V_10 -> V_56 ;
F_45 ( F_27 ( V_7 -> V_58 ) , V_70 , V_71 ) ;
V_74 -> V_72 = V_72 ;
}
static int F_46 ( struct V_46 * V_47 , struct V_6 * V_7 , int V_8 ,
int V_75 )
{
unsigned char * V_76 = F_47 ( V_47 ) ;
struct V_9 * V_10 = F_5 ( V_7 ) ;
struct V_27 V_77 = {
. V_34 = V_10 -> V_78 ,
. V_1 = V_10 -> V_41 ,
. V_79 = V_10 -> V_80 - V_75 ,
. V_81 = V_10 -> V_82 - V_8 ,
. V_35 = V_10 -> V_42 ,
. V_36 = V_10 -> V_43 ,
} ;
struct V_73 V_83 ;
if ( F_48 ( V_47 , V_33 , sizeof( V_77 ) , & V_77 ) )
goto V_84;
F_49 ( & V_83 , & V_10 -> V_56 ) ;
if ( F_50 ( V_47 , V_85 , sizeof( V_83 ) , & V_83 , V_86 ) )
goto V_84;
return V_47 -> V_87 ;
V_84:
F_51 ( V_47 , V_76 ) ;
return - 1 ;
}
static int F_52 ( struct V_16 * V_16 , struct V_46 * V_47 ,
struct V_88 * V_89 , int type ,
const struct V_90 * V_91 )
{
struct V_21 * V_22 = F_12 ( V_16 , V_23 ) ;
return F_53 ( V_22 , V_47 , V_89 , type , V_91 ) ;
}
static int F_54 ( struct V_16 * V_16 , struct V_6 * * V_7 , T_2 V_34 )
{
struct V_21 * V_22 = F_12 ( V_16 , V_23 ) ;
return F_55 ( V_22 , V_7 , V_34 ) ;
}
static int F_56 ( struct V_92 * V_93 ,
unsigned long V_94 , void * V_95 )
{
struct V_11 * V_12 = F_57 ( V_95 ) ;
struct V_9 * V_10 ;
F_20 () ;
if ( V_94 == V_96 ) {
F_6 ( & V_13 ) ;
F_58 (m, &mirred_list, tcfm_list) {
if ( F_59 ( V_10 -> V_15 ) == V_12 ) {
F_9 ( V_12 ) ;
F_60 ( V_10 -> V_15 , NULL ) ;
}
}
F_10 ( & V_13 ) ;
}
return V_97 ;
}
static int F_61 ( const struct V_6 * V_7 , struct V_16 * V_16 ,
struct V_11 * * V_98 )
{
int V_36 = F_62 ( V_7 ) ;
* V_98 = F_17 ( V_16 , V_36 ) ;
if ( ! * V_98 )
return - V_31 ;
return 0 ;
}
static T_3 int F_63 ( struct V_16 * V_16 )
{
struct V_21 * V_22 = F_12 ( V_16 , V_23 ) ;
return F_64 ( V_22 , & V_38 , V_99 ) ;
}
static void T_4 F_65 ( struct V_16 * V_16 )
{
struct V_21 * V_22 = F_12 ( V_16 , V_23 ) ;
F_66 ( V_22 ) ;
}
static int T_5 F_67 ( void )
{
int V_53 = F_68 ( & V_100 ) ;
if ( V_53 )
return V_53 ;
F_69 ( L_3 ) ;
return F_70 ( & V_38 , & V_101 ) ;
}
static void T_6 F_71 ( void )
{
F_72 ( & V_38 , & V_101 ) ;
F_73 ( & V_100 ) ;
}
