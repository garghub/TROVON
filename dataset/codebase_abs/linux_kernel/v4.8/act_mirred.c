static void F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 ;
F_3 ( & V_8 ) ;
F_4 ( & V_5 -> V_9 ) ;
V_7 = F_5 ( V_5 -> V_10 , 1 ) ;
if ( V_7 )
F_6 ( V_7 ) ;
F_7 ( & V_8 ) ;
}
static int F_8 ( struct V_11 * V_11 , struct V_12 * V_13 ,
struct V_12 * V_14 , struct V_1 * * V_2 , int V_15 ,
int V_3 )
{
struct V_16 * V_17 = F_9 ( V_11 , V_18 ) ;
struct V_12 * V_19 [ V_20 + 1 ] ;
struct V_21 * V_22 ;
struct V_4 * V_5 ;
struct V_6 * V_7 ;
int V_23 , V_24 = 0 ;
bool V_25 = false ;
if ( V_13 == NULL )
return - V_26 ;
V_23 = F_10 ( V_19 , V_20 , V_13 , V_27 ) ;
if ( V_23 < 0 )
return V_23 ;
if ( V_19 [ V_28 ] == NULL )
return - V_26 ;
V_22 = F_11 ( V_19 [ V_28 ] ) ;
V_25 = F_12 ( V_17 , V_22 -> V_29 , V_2 , V_3 ) ;
if ( V_25 && V_3 )
return 0 ;
switch ( V_22 -> V_30 ) {
case V_31 :
case V_32 :
break;
default:
if ( V_25 )
F_13 ( * V_2 , V_3 ) ;
return - V_26 ;
}
if ( V_22 -> V_33 ) {
V_7 = F_14 ( V_11 , V_22 -> V_33 ) ;
if ( V_7 == NULL ) {
if ( V_25 )
F_13 ( * V_2 , V_3 ) ;
return - V_34 ;
}
switch ( V_7 -> type ) {
case V_35 :
case V_36 :
case V_37 :
case V_38 :
case V_39 :
case V_40 :
V_24 = 0 ;
break;
default:
V_24 = 1 ;
break;
}
} else {
V_7 = NULL ;
}
if ( ! V_25 ) {
if ( V_7 == NULL )
return - V_26 ;
V_23 = F_15 ( V_17 , V_22 -> V_29 , V_14 , V_2 ,
& V_41 , V_3 , true ) ;
if ( V_23 )
return V_23 ;
V_23 = V_42 ;
} else {
F_13 ( * V_2 , V_3 ) ;
if ( ! V_15 )
return - V_43 ;
}
V_5 = F_2 ( * V_2 ) ;
F_16 () ;
V_5 -> V_44 = V_22 -> V_45 ;
V_5 -> V_46 = V_22 -> V_30 ;
if ( V_7 != NULL ) {
V_5 -> V_47 = V_22 -> V_33 ;
if ( V_23 != V_42 )
F_6 ( F_5 ( V_5 -> V_10 , 1 ) ) ;
F_17 ( V_7 ) ;
F_18 ( V_5 -> V_10 , V_7 ) ;
V_5 -> V_48 = V_24 ;
}
if ( V_23 == V_42 ) {
F_3 ( & V_8 ) ;
F_19 ( & V_5 -> V_9 , & V_49 ) ;
F_7 ( & V_8 ) ;
F_20 ( V_17 , * V_2 ) ;
}
return V_23 ;
}
static int V_4 ( struct V_50 * V_51 , const struct V_1 * V_2 ,
struct V_52 * V_53 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 ;
struct V_50 * V_54 ;
int V_55 , V_56 ;
T_1 V_57 ;
F_21 ( & V_5 -> V_58 ) ;
F_22 ( F_23 ( V_5 -> V_59 . V_60 ) , V_51 ) ;
F_24 () ;
V_55 = F_25 ( V_5 -> V_44 ) ;
V_7 = F_26 ( V_5 -> V_10 ) ;
if ( F_27 ( ! V_7 ) ) {
F_28 ( L_1 ) ;
goto V_61;
}
if ( F_27 ( ! ( V_7 -> V_62 & V_63 ) ) ) {
F_29 ( L_2 ,
V_7 -> V_64 ) ;
goto V_61;
}
V_57 = F_30 ( V_51 -> V_65 ) ;
V_54 = F_31 ( V_51 , V_66 ) ;
if ( ! V_54 )
goto V_61;
if ( ! ( V_57 & V_67 ) ) {
if ( V_5 -> V_48 )
F_32 ( V_54 , V_51 -> V_68 ) ;
}
if ( V_5 -> V_46 != V_31 )
V_54 -> V_65 = F_33 ( V_54 -> V_65 , V_57 ) ;
V_54 -> V_69 = V_51 -> V_7 -> V_33 ;
V_54 -> V_7 = V_7 ;
V_56 = F_34 ( V_54 ) ;
if ( V_56 ) {
V_61:
F_35 ( F_23 ( V_5 -> V_59 . V_70 ) ) ;
if ( V_5 -> V_46 != V_31 )
V_55 = V_71 ;
}
F_36 () ;
return V_55 ;
}
static int F_37 ( struct V_50 * V_51 , struct V_1 * V_2 , int V_3 , int V_72 )
{
unsigned char * V_73 = F_38 ( V_51 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_21 V_74 = {
. V_29 = V_5 -> V_75 ,
. V_45 = V_5 -> V_44 ,
. V_76 = V_5 -> V_77 - V_72 ,
. V_78 = V_5 -> V_79 - V_3 ,
. V_30 = V_5 -> V_46 ,
. V_33 = V_5 -> V_47 ,
} ;
struct V_80 V_81 ;
if ( F_39 ( V_51 , V_28 , sizeof( V_74 ) , & V_74 ) )
goto V_82;
F_40 ( & V_81 , & V_5 -> V_58 ) ;
if ( F_41 ( V_51 , V_83 , sizeof( V_81 ) , & V_81 , V_84 ) )
goto V_82;
return V_51 -> V_85 ;
V_82:
F_42 ( V_51 , V_73 ) ;
return - 1 ;
}
static int F_43 ( struct V_11 * V_11 , struct V_50 * V_51 ,
struct V_86 * V_87 , int type ,
const struct V_88 * V_89 )
{
struct V_16 * V_17 = F_9 ( V_11 , V_18 ) ;
return F_44 ( V_17 , V_51 , V_87 , type , V_89 ) ;
}
static int F_45 ( struct V_11 * V_11 , struct V_1 * * V_2 , T_1 V_29 )
{
struct V_16 * V_17 = F_9 ( V_11 , V_18 ) ;
return F_46 ( V_17 , V_2 , V_29 ) ;
}
static int F_47 ( struct V_90 * V_91 ,
unsigned long V_92 , void * V_93 )
{
struct V_6 * V_7 = F_48 ( V_93 ) ;
struct V_4 * V_5 ;
F_16 () ;
if ( V_92 == V_94 ) {
F_3 ( & V_8 ) ;
F_49 (m, &mirred_list, tcfm_list) {
if ( F_50 ( V_5 -> V_10 ) == V_7 ) {
F_6 ( V_7 ) ;
F_51 ( V_5 -> V_10 , NULL ) ;
}
}
F_7 ( & V_8 ) ;
}
return V_95 ;
}
static T_2 int F_52 ( struct V_11 * V_11 )
{
struct V_16 * V_17 = F_9 ( V_11 , V_18 ) ;
return F_53 ( V_17 , & V_41 , V_96 ) ;
}
static void T_3 F_54 ( struct V_11 * V_11 )
{
struct V_16 * V_17 = F_9 ( V_11 , V_18 ) ;
F_55 ( V_17 ) ;
}
static int T_4 F_56 ( void )
{
int V_56 = F_57 ( & V_97 ) ;
if ( V_56 )
return V_56 ;
F_58 ( L_3 ) ;
return F_59 ( & V_41 , & V_98 ) ;
}
static void T_5 F_60 ( void )
{
F_61 ( & V_41 , & V_98 ) ;
F_62 ( & V_97 ) ;
}
