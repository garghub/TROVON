static void F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = F_3 ( V_5 -> V_8 , 1 ) ;
F_4 ( & V_9 ) ;
F_5 ( & V_5 -> V_10 ) ;
F_6 ( & V_9 ) ;
if ( V_7 )
F_7 ( V_7 ) ;
}
static int F_8 ( struct V_11 * V_11 , struct V_12 * V_13 ,
struct V_12 * V_14 , struct V_1 * V_2 , int V_15 ,
int V_3 )
{
struct V_16 * V_17 = F_9 ( V_11 , V_18 ) ;
struct V_12 * V_19 [ V_20 + 1 ] ;
struct V_21 * V_22 ;
struct V_4 * V_5 ;
struct V_6 * V_7 ;
int V_23 , V_24 = 0 , V_25 = 0 ;
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
F_13 ( V_2 , V_3 ) ;
return - V_26 ;
}
if ( V_22 -> V_33 ) {
V_7 = F_14 ( V_11 , V_22 -> V_33 ) ;
if ( V_7 == NULL ) {
if ( V_25 )
F_13 ( V_2 , V_3 ) ;
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
sizeof( * V_5 ) , V_3 , true ) ;
if ( V_23 )
return V_23 ;
V_23 = V_41 ;
} else {
F_13 ( V_2 , V_3 ) ;
if ( ! V_15 )
return - V_42 ;
}
V_5 = F_2 ( V_2 ) ;
F_16 () ;
V_5 -> V_43 = V_22 -> V_44 ;
V_5 -> V_45 = V_22 -> V_30 ;
if ( V_7 != NULL ) {
V_5 -> V_46 = V_22 -> V_33 ;
if ( V_23 != V_41 )
F_7 ( F_3 ( V_5 -> V_8 , 1 ) ) ;
F_17 ( V_7 ) ;
F_18 ( V_5 -> V_8 , V_7 ) ;
V_5 -> V_47 = V_24 ;
}
if ( V_23 == V_41 ) {
F_4 ( & V_9 ) ;
F_19 ( & V_5 -> V_10 , & V_48 ) ;
F_6 ( & V_9 ) ;
F_20 ( V_17 , V_2 ) ;
}
return V_23 ;
}
static int V_4 ( struct V_49 * V_50 , const struct V_1 * V_2 ,
struct V_51 * V_52 )
{
struct V_4 * V_5 = V_2 -> V_53 ;
struct V_6 * V_7 ;
struct V_49 * V_54 ;
int V_55 , V_56 ;
T_1 V_57 ;
F_21 ( & V_5 -> V_58 ) ;
F_22 ( F_23 ( V_5 -> V_59 . V_60 ) , V_50 ) ;
F_24 () ;
V_55 = F_25 ( V_5 -> V_43 ) ;
V_7 = F_26 ( V_5 -> V_8 ) ;
if ( F_27 ( ! V_7 ) ) {
F_28 ( L_1 ) ;
goto V_61;
}
if ( F_27 ( ! ( V_7 -> V_62 & V_63 ) ) ) {
F_29 ( L_2 ,
V_7 -> V_64 ) ;
goto V_61;
}
V_57 = F_30 ( V_50 -> V_65 ) ;
V_54 = F_31 ( V_50 , V_66 ) ;
if ( ! V_54 )
goto V_61;
if ( ! ( V_57 & V_67 ) ) {
if ( V_5 -> V_47 )
F_32 ( V_54 , V_50 -> V_68 ) ;
}
if ( V_5 -> V_45 != V_31 )
V_54 -> V_65 = F_33 ( V_54 -> V_65 , V_57 ) ;
V_54 -> V_69 = V_50 -> V_7 -> V_33 ;
V_54 -> V_7 = V_7 ;
V_56 = F_34 ( V_54 ) ;
if ( V_56 ) {
V_61:
F_35 ( F_23 ( V_5 -> V_59 . V_70 ) ) ;
if ( V_5 -> V_45 != V_31 )
V_55 = V_71 ;
}
F_36 () ;
return V_55 ;
}
static int F_37 ( struct V_49 * V_50 , struct V_1 * V_2 , int V_3 , int V_72 )
{
unsigned char * V_73 = F_38 ( V_50 ) ;
struct V_4 * V_5 = V_2 -> V_53 ;
struct V_21 V_74 = {
. V_29 = V_5 -> V_75 ,
. V_44 = V_5 -> V_43 ,
. V_76 = V_5 -> V_77 - V_72 ,
. V_78 = V_5 -> V_79 - V_3 ,
. V_30 = V_5 -> V_45 ,
. V_33 = V_5 -> V_46 ,
} ;
struct V_80 V_81 ;
if ( F_39 ( V_50 , V_28 , sizeof( V_74 ) , & V_74 ) )
goto V_82;
V_81 . V_83 = F_40 ( V_84 - V_5 -> V_58 . V_83 ) ;
V_81 . V_85 = F_40 ( V_84 - V_5 -> V_58 . V_85 ) ;
V_81 . V_86 = F_40 ( V_5 -> V_58 . V_86 ) ;
if ( F_39 ( V_50 , V_87 , sizeof( V_81 ) , & V_81 ) )
goto V_82;
return V_50 -> V_88 ;
V_82:
F_41 ( V_50 , V_73 ) ;
return - 1 ;
}
static int F_42 ( struct V_11 * V_11 , struct V_49 * V_50 ,
struct V_89 * V_90 , int type ,
struct V_1 * V_2 )
{
struct V_16 * V_17 = F_9 ( V_11 , V_18 ) ;
return F_43 ( V_17 , V_50 , V_90 , type , V_2 ) ;
}
static int F_44 ( struct V_11 * V_11 , struct V_1 * V_2 , T_1 V_29 )
{
struct V_16 * V_17 = F_9 ( V_11 , V_18 ) ;
return F_45 ( V_17 , V_2 , V_29 ) ;
}
static int F_46 ( struct V_91 * V_92 ,
unsigned long V_93 , void * V_94 )
{
struct V_6 * V_7 = F_47 ( V_94 ) ;
struct V_4 * V_5 ;
F_16 () ;
if ( V_93 == V_95 ) {
F_4 ( & V_9 ) ;
F_48 (m, &mirred_list, tcfm_list) {
if ( F_49 ( V_5 -> V_8 ) == V_7 ) {
F_7 ( V_7 ) ;
F_50 ( V_5 -> V_8 , NULL ) ;
}
}
F_6 ( & V_9 ) ;
}
return V_96 ;
}
static T_2 int F_51 ( struct V_11 * V_11 )
{
struct V_16 * V_17 = F_9 ( V_11 , V_18 ) ;
return F_52 ( V_17 , & V_97 , V_98 ) ;
}
static void T_3 F_53 ( struct V_11 * V_11 )
{
struct V_16 * V_17 = F_9 ( V_11 , V_18 ) ;
F_54 ( V_17 ) ;
}
static int T_4 F_55 ( void )
{
int V_56 = F_56 ( & V_99 ) ;
if ( V_56 )
return V_56 ;
F_57 ( L_3 ) ;
return F_58 ( & V_97 , & V_100 ) ;
}
static void T_5 F_59 ( void )
{
F_60 ( & V_97 , & V_100 ) ;
F_61 ( & V_99 ) ;
}
