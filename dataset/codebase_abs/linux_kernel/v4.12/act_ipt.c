static int F_1 ( struct V_1 * V_2 , char * V_3 ,
unsigned int V_4 )
{
struct V_5 V_6 ;
struct V_7 * V_8 ;
int V_9 = 0 ;
V_8 = F_2 ( V_10 , V_2 -> V_11 . V_12 . V_13 ,
V_2 -> V_11 . V_12 . V_14 ) ;
if ( F_3 ( V_8 ) )
return F_4 ( V_8 ) ;
V_2 -> V_11 . V_15 . V_8 = V_8 ;
V_6 . V_3 = V_3 ;
V_6 . V_16 = NULL ;
V_6 . V_8 = V_8 ;
V_6 . V_17 = V_2 -> V_18 ;
V_6 . V_19 = V_4 ;
V_6 . V_20 = V_21 ;
V_9 = F_5 ( & V_6 , V_2 -> V_11 . V_22 - sizeof( * V_2 ) , 0 , false ) ;
if ( V_9 < 0 ) {
F_6 ( V_2 -> V_11 . V_15 . V_8 -> V_23 ) ;
return V_9 ;
}
return 0 ;
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_24 V_6 = {
. V_8 = V_2 -> V_11 . V_15 . V_8 ,
. V_17 = V_2 -> V_18 ,
. V_20 = V_21 ,
} ;
if ( V_6 . V_8 -> V_25 != NULL )
V_6 . V_8 -> V_25 ( & V_6 ) ;
F_6 ( V_6 . V_8 -> V_23 ) ;
}
static void F_8 ( struct V_26 * V_27 , int V_28 )
{
struct V_29 * V_30 = F_9 ( V_27 ) ;
F_7 ( V_30 -> V_31 ) ;
F_10 ( V_30 -> V_32 ) ;
F_10 ( V_30 -> V_31 ) ;
}
static int F_11 ( struct V_33 * V_34 , struct V_35 * V_36 ,
struct V_35 * V_37 , struct V_26 * * V_27 ,
const struct V_38 * V_39 , int V_40 , int V_28 )
{
struct V_35 * V_41 [ V_42 + 1 ] ;
struct V_29 * V_30 ;
struct V_1 * V_43 , * V_2 ;
char * V_44 ;
bool V_45 = false ;
int V_9 = 0 , V_46 ;
T_1 V_4 = 0 ;
T_1 V_47 = 0 ;
if ( V_36 == NULL )
return - V_48 ;
V_46 = F_12 ( V_41 , V_42 , V_36 , V_49 , NULL ) ;
if ( V_46 < 0 )
return V_46 ;
if ( V_41 [ V_50 ] != NULL )
V_47 = F_13 ( V_41 [ V_50 ] ) ;
V_45 = F_14 ( V_34 , V_47 , V_27 , V_28 ) ;
if ( V_45 && V_28 )
return 0 ;
if ( V_41 [ V_51 ] == NULL || V_41 [ V_52 ] == NULL ) {
if ( V_45 )
F_15 ( * V_27 , V_28 ) ;
return - V_48 ;
}
V_43 = (struct V_1 * ) F_16 ( V_41 [ V_52 ] ) ;
if ( F_17 ( V_41 [ V_52 ] ) < V_43 -> V_11 . V_22 ) {
if ( V_45 )
F_15 ( * V_27 , V_28 ) ;
return - V_48 ;
}
if ( ! V_45 ) {
V_9 = F_18 ( V_34 , V_47 , V_37 , V_27 , V_39 , V_28 ,
false ) ;
if ( V_9 )
return V_9 ;
V_9 = V_53 ;
} else {
if ( V_28 )
return 0 ;
F_15 ( * V_27 , V_28 ) ;
if ( ! V_40 )
return - V_54 ;
}
V_4 = F_13 ( V_41 [ V_51 ] ) ;
V_46 = - V_55 ;
V_44 = F_19 ( V_56 , V_57 ) ;
if ( F_20 ( ! V_44 ) )
goto V_58;
if ( V_41 [ V_59 ] == NULL ||
F_21 ( V_44 , V_41 [ V_59 ] , V_56 ) >= V_56 )
strcpy ( V_44 , L_1 ) ;
V_2 = F_22 ( V_43 , V_43 -> V_11 . V_22 , V_57 ) ;
if ( F_20 ( ! V_2 ) )
goto V_60;
V_46 = F_1 ( V_2 , V_44 , V_4 ) ;
if ( V_46 < 0 )
goto V_61;
V_30 = F_9 ( * V_27 ) ;
F_23 ( & V_30 -> V_62 ) ;
if ( V_9 != V_53 ) {
F_7 ( V_30 -> V_31 ) ;
F_10 ( V_30 -> V_32 ) ;
F_10 ( V_30 -> V_31 ) ;
}
V_30 -> V_32 = V_44 ;
V_30 -> V_31 = V_2 ;
V_30 -> V_63 = V_4 ;
F_24 ( & V_30 -> V_62 ) ;
if ( V_9 == V_53 )
F_25 ( V_34 , * V_27 ) ;
return V_9 ;
V_61:
F_10 ( V_2 ) ;
V_60:
F_10 ( V_44 ) ;
V_58:
if ( V_9 == V_53 )
F_26 ( * V_27 , V_37 ) ;
return V_46 ;
}
static int F_27 ( struct V_64 * V_64 , struct V_35 * V_36 ,
struct V_35 * V_37 , struct V_26 * * V_27 , int V_40 ,
int V_28 )
{
struct V_33 * V_34 = F_28 ( V_64 , V_65 ) ;
return F_11 ( V_34 , V_36 , V_37 , V_27 , & V_66 , V_40 , V_28 ) ;
}
static int F_29 ( struct V_64 * V_64 , struct V_35 * V_36 ,
struct V_35 * V_37 , struct V_26 * * V_27 , int V_40 ,
int V_28 )
{
struct V_33 * V_34 = F_28 ( V_64 , V_67 ) ;
return F_11 ( V_34 , V_36 , V_37 , V_27 , & V_68 , V_40 , V_28 ) ;
}
static int V_29 ( struct V_69 * V_70 , const struct V_26 * V_27 ,
struct V_71 * V_72 )
{
int V_9 = 0 , V_73 = 0 ;
struct V_29 * V_30 = F_9 ( V_27 ) ;
struct V_74 V_6 ;
struct V_75 V_76 = {
. V_64 = F_30 ( V_70 -> V_77 ) ,
. V_78 = V_70 -> V_77 ,
. V_4 = V_30 -> V_63 ,
. V_79 = V_21 ,
} ;
if ( F_31 ( V_70 , V_80 ) )
return V_81 ;
F_32 ( & V_30 -> V_62 ) ;
F_33 ( & V_30 -> V_82 ) ;
F_34 ( & V_30 -> V_83 , V_70 ) ;
V_6 . V_76 = & V_76 ;
V_6 . V_8 = V_30 -> V_31 -> V_11 . V_15 . V_8 ;
V_6 . V_17 = V_30 -> V_31 -> V_18 ;
V_9 = V_6 . V_8 -> V_8 ( V_70 , & V_6 ) ;
switch ( V_9 ) {
case V_84 :
V_73 = V_85 ;
break;
case V_86 :
V_73 = V_87 ;
V_30 -> V_88 . V_89 ++ ;
break;
case V_90 :
V_73 = V_91 ;
break;
default:
F_35 ( L_2 ,
V_9 ) ;
V_73 = V_85 ;
break;
}
F_36 ( & V_30 -> V_62 ) ;
return V_73 ;
}
static int F_37 ( struct V_69 * V_70 , struct V_26 * V_27 , int V_28 ,
int V_92 )
{
unsigned char * V_93 = F_38 ( V_70 ) ;
struct V_29 * V_30 = F_9 ( V_27 ) ;
struct V_1 * V_2 ;
struct V_94 V_95 ;
struct V_96 V_97 ;
V_2 = F_22 ( V_30 -> V_31 , V_30 -> V_31 -> V_11 . V_12 . V_22 , V_80 ) ;
if ( F_20 ( ! V_2 ) )
goto V_98;
V_97 . V_99 = V_30 -> V_100 - V_28 ;
V_97 . V_101 = V_30 -> V_102 - V_92 ;
strcpy ( V_2 -> V_11 . V_12 . V_13 , V_30 -> V_31 -> V_11 . V_15 . V_8 -> V_13 ) ;
if ( F_39 ( V_70 , V_52 , V_30 -> V_31 -> V_11 . V_12 . V_22 , V_2 ) ||
F_40 ( V_70 , V_50 , V_30 -> V_103 ) ||
F_40 ( V_70 , V_51 , V_30 -> V_63 ) ||
F_39 ( V_70 , V_104 , sizeof( struct V_96 ) , & V_97 ) ||
F_41 ( V_70 , V_59 , V_30 -> V_32 ) )
goto V_98;
F_42 ( & V_95 , & V_30 -> V_82 ) ;
if ( F_43 ( V_70 , V_105 , sizeof( V_95 ) , & V_95 , V_106 ) )
goto V_98;
F_10 ( V_2 ) ;
return V_70 -> V_107 ;
V_98:
F_44 ( V_70 , V_93 ) ;
F_10 ( V_2 ) ;
return - 1 ;
}
static int F_45 ( struct V_64 * V_64 , struct V_69 * V_70 ,
struct V_108 * V_109 , int type ,
const struct V_38 * V_39 )
{
struct V_33 * V_34 = F_28 ( V_64 , V_65 ) ;
return F_46 ( V_34 , V_70 , V_109 , type , V_39 ) ;
}
static int F_47 ( struct V_64 * V_64 , struct V_26 * * V_27 , T_1 V_47 )
{
struct V_33 * V_34 = F_28 ( V_64 , V_65 ) ;
return F_48 ( V_34 , V_27 , V_47 ) ;
}
static T_2 int F_49 ( struct V_64 * V_64 )
{
struct V_33 * V_34 = F_28 ( V_64 , V_65 ) ;
return F_50 ( V_34 , & V_66 , V_110 ) ;
}
static void T_3 F_51 ( struct V_64 * V_64 )
{
struct V_33 * V_34 = F_28 ( V_64 , V_65 ) ;
F_52 ( V_34 ) ;
}
static int F_53 ( struct V_64 * V_64 , struct V_69 * V_70 ,
struct V_108 * V_109 , int type ,
const struct V_38 * V_39 )
{
struct V_33 * V_34 = F_28 ( V_64 , V_67 ) ;
return F_46 ( V_34 , V_70 , V_109 , type , V_39 ) ;
}
static int F_54 ( struct V_64 * V_64 , struct V_26 * * V_27 , T_1 V_47 )
{
struct V_33 * V_34 = F_28 ( V_64 , V_67 ) ;
return F_48 ( V_34 , V_27 , V_47 ) ;
}
static T_2 int F_55 ( struct V_64 * V_64 )
{
struct V_33 * V_34 = F_28 ( V_64 , V_67 ) ;
return F_50 ( V_34 , & V_68 , V_110 ) ;
}
static void T_3 F_56 ( struct V_64 * V_64 )
{
struct V_33 * V_34 = F_28 ( V_64 , V_67 ) ;
F_52 ( V_34 ) ;
}
static int T_4 F_57 ( void )
{
int V_111 , V_112 ;
V_111 = F_58 ( & V_68 , & V_113 ) ;
if ( V_111 < 0 )
F_59 ( L_3 ) ;
V_112 = F_58 ( & V_66 , & V_114 ) ;
if ( V_112 < 0 )
F_59 ( L_4 ) ;
if ( V_111 < 0 && V_112 < 0 ) {
return V_111 ;
} else
return 0 ;
}
static void T_5 F_60 ( void )
{
F_61 ( & V_66 , & V_114 ) ;
F_61 ( & V_68 , & V_113 ) ;
}
