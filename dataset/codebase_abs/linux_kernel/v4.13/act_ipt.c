static int F_1 ( struct V_1 * V_1 , struct V_2 * V_3 ,
char * V_4 , unsigned int V_5 )
{
struct V_6 V_7 ;
struct V_8 * V_9 ;
struct V_10 V_11 = {} ;
int V_12 = 0 ;
V_9 = F_2 ( V_13 , V_3 -> V_14 . V_15 . V_16 ,
V_3 -> V_14 . V_15 . V_17 ) ;
if ( F_3 ( V_9 ) )
return F_4 ( V_9 ) ;
V_3 -> V_14 . V_18 . V_9 = V_9 ;
memset ( & V_7 , 0 , sizeof( V_7 ) ) ;
V_7 . V_1 = V_1 ;
V_7 . V_4 = V_4 ;
V_7 . V_19 = & V_11 ;
V_7 . V_9 = V_9 ;
V_7 . V_20 = V_3 -> V_21 ;
V_7 . V_22 = V_5 ;
V_7 . V_23 = V_24 ;
V_12 = F_5 ( & V_7 , V_3 -> V_14 . V_25 - sizeof( * V_3 ) , 0 , false ) ;
if ( V_12 < 0 ) {
F_6 ( V_3 -> V_14 . V_18 . V_9 -> V_26 ) ;
return V_12 ;
}
return 0 ;
}
static void F_7 ( struct V_2 * V_3 )
{
struct V_27 V_7 = {
. V_9 = V_3 -> V_14 . V_18 . V_9 ,
. V_20 = V_3 -> V_21 ,
. V_23 = V_24 ,
} ;
if ( V_7 . V_9 -> V_28 != NULL )
V_7 . V_9 -> V_28 ( & V_7 ) ;
F_6 ( V_7 . V_9 -> V_26 ) ;
}
static void F_8 ( struct V_29 * V_30 , int V_31 )
{
struct V_32 * V_33 = F_9 ( V_30 ) ;
F_7 ( V_33 -> V_34 ) ;
F_10 ( V_33 -> V_35 ) ;
F_10 ( V_33 -> V_34 ) ;
}
static int F_11 ( struct V_1 * V_1 , unsigned int V_36 , struct V_37 * V_38 ,
struct V_37 * V_39 , struct V_29 * * V_30 ,
const struct V_40 * V_41 , int V_42 , int V_31 )
{
struct V_43 * V_44 = F_12 ( V_1 , V_36 ) ;
struct V_37 * V_45 [ V_46 + 1 ] ;
struct V_32 * V_33 ;
struct V_2 * V_47 , * V_3 ;
char * V_48 ;
bool V_49 = false ;
int V_12 = 0 , V_50 ;
T_1 V_5 = 0 ;
T_1 V_51 = 0 ;
if ( V_38 == NULL )
return - V_52 ;
V_50 = F_13 ( V_45 , V_46 , V_38 , V_53 , NULL ) ;
if ( V_50 < 0 )
return V_50 ;
if ( V_45 [ V_54 ] != NULL )
V_51 = F_14 ( V_45 [ V_54 ] ) ;
V_49 = F_15 ( V_44 , V_51 , V_30 , V_31 ) ;
if ( V_49 && V_31 )
return 0 ;
if ( V_45 [ V_55 ] == NULL || V_45 [ V_56 ] == NULL ) {
if ( V_49 )
F_16 ( * V_30 , V_31 ) ;
return - V_52 ;
}
V_47 = (struct V_2 * ) F_17 ( V_45 [ V_56 ] ) ;
if ( F_18 ( V_45 [ V_56 ] ) < V_47 -> V_14 . V_25 ) {
if ( V_49 )
F_16 ( * V_30 , V_31 ) ;
return - V_52 ;
}
if ( ! V_49 ) {
V_12 = F_19 ( V_44 , V_51 , V_39 , V_30 , V_41 , V_31 ,
false ) ;
if ( V_12 )
return V_12 ;
V_12 = V_57 ;
} else {
if ( V_31 )
return 0 ;
F_16 ( * V_30 , V_31 ) ;
if ( ! V_42 )
return - V_58 ;
}
V_5 = F_14 ( V_45 [ V_55 ] ) ;
V_50 = - V_59 ;
V_48 = F_20 ( V_60 , V_61 ) ;
if ( F_21 ( ! V_48 ) )
goto V_62;
if ( V_45 [ V_63 ] == NULL ||
F_22 ( V_48 , V_45 [ V_63 ] , V_60 ) >= V_60 )
strcpy ( V_48 , L_1 ) ;
V_3 = F_23 ( V_47 , V_47 -> V_14 . V_25 , V_61 ) ;
if ( F_21 ( ! V_3 ) )
goto V_64;
V_50 = F_1 ( V_1 , V_3 , V_48 , V_5 ) ;
if ( V_50 < 0 )
goto V_65;
V_33 = F_9 ( * V_30 ) ;
F_24 ( & V_33 -> V_66 ) ;
if ( V_12 != V_57 ) {
F_7 ( V_33 -> V_34 ) ;
F_10 ( V_33 -> V_35 ) ;
F_10 ( V_33 -> V_34 ) ;
}
V_33 -> V_35 = V_48 ;
V_33 -> V_34 = V_3 ;
V_33 -> V_67 = V_5 ;
F_25 ( & V_33 -> V_66 ) ;
if ( V_12 == V_57 )
F_26 ( V_44 , * V_30 ) ;
return V_12 ;
V_65:
F_10 ( V_3 ) ;
V_64:
F_10 ( V_48 ) ;
V_62:
if ( V_12 == V_57 )
F_27 ( * V_30 , V_39 ) ;
return V_50 ;
}
static int F_28 ( struct V_1 * V_1 , struct V_37 * V_38 ,
struct V_37 * V_39 , struct V_29 * * V_30 , int V_42 ,
int V_31 )
{
return F_11 ( V_1 , V_68 , V_38 , V_39 , V_30 , & V_69 , V_42 ,
V_31 ) ;
}
static int F_29 ( struct V_1 * V_1 , struct V_37 * V_38 ,
struct V_37 * V_39 , struct V_29 * * V_30 , int V_42 ,
int V_31 )
{
return F_11 ( V_1 , V_70 , V_38 , V_39 , V_30 , & V_71 , V_42 ,
V_31 ) ;
}
static int V_32 ( struct V_72 * V_73 , const struct V_29 * V_30 ,
struct V_74 * V_75 )
{
int V_12 = 0 , V_76 = 0 ;
struct V_32 * V_33 = F_9 ( V_30 ) ;
struct V_77 V_7 ;
struct V_78 V_79 = {
. V_1 = F_30 ( V_73 -> V_80 ) ,
. V_81 = V_73 -> V_80 ,
. V_5 = V_33 -> V_67 ,
. V_82 = V_24 ,
} ;
if ( F_31 ( V_73 , V_83 ) )
return V_84 ;
F_32 ( & V_33 -> V_66 ) ;
F_33 ( & V_33 -> V_85 ) ;
F_34 ( & V_33 -> V_86 , V_73 ) ;
V_7 . V_79 = & V_79 ;
V_7 . V_9 = V_33 -> V_34 -> V_14 . V_18 . V_9 ;
V_7 . V_20 = V_33 -> V_34 -> V_21 ;
V_12 = V_7 . V_9 -> V_9 ( V_73 , & V_7 ) ;
switch ( V_12 ) {
case V_87 :
V_76 = V_88 ;
break;
case V_89 :
V_76 = V_90 ;
V_33 -> V_91 . V_92 ++ ;
break;
case V_93 :
V_76 = V_94 ;
break;
default:
F_35 ( L_2 ,
V_12 ) ;
V_76 = V_88 ;
break;
}
F_36 ( & V_33 -> V_66 ) ;
return V_76 ;
}
static int F_37 ( struct V_72 * V_73 , struct V_29 * V_30 , int V_31 ,
int V_95 )
{
unsigned char * V_96 = F_38 ( V_73 ) ;
struct V_32 * V_33 = F_9 ( V_30 ) ;
struct V_2 * V_3 ;
struct V_97 V_98 ;
struct V_99 V_100 ;
V_3 = F_23 ( V_33 -> V_34 , V_33 -> V_34 -> V_14 . V_15 . V_25 , V_83 ) ;
if ( F_21 ( ! V_3 ) )
goto V_101;
V_100 . V_102 = V_33 -> V_103 - V_31 ;
V_100 . V_104 = V_33 -> V_105 - V_95 ;
strcpy ( V_3 -> V_14 . V_15 . V_16 , V_33 -> V_34 -> V_14 . V_18 . V_9 -> V_16 ) ;
if ( F_39 ( V_73 , V_56 , V_33 -> V_34 -> V_14 . V_15 . V_25 , V_3 ) ||
F_40 ( V_73 , V_54 , V_33 -> V_106 ) ||
F_40 ( V_73 , V_55 , V_33 -> V_67 ) ||
F_39 ( V_73 , V_107 , sizeof( struct V_99 ) , & V_100 ) ||
F_41 ( V_73 , V_63 , V_33 -> V_35 ) )
goto V_101;
F_42 ( & V_98 , & V_33 -> V_85 ) ;
if ( F_43 ( V_73 , V_108 , sizeof( V_98 ) , & V_98 , V_109 ) )
goto V_101;
F_10 ( V_3 ) ;
return V_73 -> V_110 ;
V_101:
F_44 ( V_73 , V_96 ) ;
F_10 ( V_3 ) ;
return - 1 ;
}
static int F_45 ( struct V_1 * V_1 , struct V_72 * V_73 ,
struct V_111 * V_112 , int type ,
const struct V_40 * V_41 )
{
struct V_43 * V_44 = F_12 ( V_1 , V_68 ) ;
return F_46 ( V_44 , V_73 , V_112 , type , V_41 ) ;
}
static int F_47 ( struct V_1 * V_1 , struct V_29 * * V_30 , T_1 V_51 )
{
struct V_43 * V_44 = F_12 ( V_1 , V_68 ) ;
return F_48 ( V_44 , V_30 , V_51 ) ;
}
static T_2 int F_49 ( struct V_1 * V_1 )
{
struct V_43 * V_44 = F_12 ( V_1 , V_68 ) ;
return F_50 ( V_44 , & V_69 , V_113 ) ;
}
static void T_3 F_51 ( struct V_1 * V_1 )
{
struct V_43 * V_44 = F_12 ( V_1 , V_68 ) ;
F_52 ( V_44 ) ;
}
static int F_53 ( struct V_1 * V_1 , struct V_72 * V_73 ,
struct V_111 * V_112 , int type ,
const struct V_40 * V_41 )
{
struct V_43 * V_44 = F_12 ( V_1 , V_70 ) ;
return F_46 ( V_44 , V_73 , V_112 , type , V_41 ) ;
}
static int F_54 ( struct V_1 * V_1 , struct V_29 * * V_30 , T_1 V_51 )
{
struct V_43 * V_44 = F_12 ( V_1 , V_70 ) ;
return F_48 ( V_44 , V_30 , V_51 ) ;
}
static T_2 int F_55 ( struct V_1 * V_1 )
{
struct V_43 * V_44 = F_12 ( V_1 , V_70 ) ;
return F_50 ( V_44 , & V_71 , V_113 ) ;
}
static void T_3 F_56 ( struct V_1 * V_1 )
{
struct V_43 * V_44 = F_12 ( V_1 , V_70 ) ;
F_52 ( V_44 ) ;
}
static int T_4 F_57 ( void )
{
int V_114 , V_115 ;
V_114 = F_58 ( & V_71 , & V_116 ) ;
if ( V_114 < 0 )
F_59 ( L_3 ) ;
V_115 = F_58 ( & V_69 , & V_117 ) ;
if ( V_115 < 0 )
F_59 ( L_4 ) ;
if ( V_114 < 0 && V_115 < 0 ) {
return V_114 ;
} else
return 0 ;
}
static void T_5 F_60 ( void )
{
F_61 ( & V_69 , & V_117 ) ;
F_61 ( & V_71 , & V_116 ) ;
}
