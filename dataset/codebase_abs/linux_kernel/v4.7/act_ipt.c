static int F_1 ( struct V_1 * V_2 , char * V_3 , unsigned int V_4 )
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
struct V_35 * V_37 , struct V_26 * V_27 , int V_38 ,
int V_28 )
{
struct V_35 * V_39 [ V_40 + 1 ] ;
struct V_29 * V_30 ;
struct V_1 * V_41 , * V_2 ;
char * V_42 ;
int V_9 = 0 , V_43 , V_44 = 0 ;
T_1 V_4 = 0 ;
T_1 V_45 = 0 ;
if ( V_36 == NULL )
return - V_46 ;
V_43 = F_12 ( V_39 , V_40 , V_36 , V_47 ) ;
if ( V_43 < 0 )
return V_43 ;
if ( V_39 [ V_48 ] != NULL )
V_45 = F_13 ( V_39 [ V_48 ] ) ;
V_44 = F_14 ( V_34 , V_45 , V_27 , V_28 ) ;
if ( V_44 && V_28 )
return 0 ;
if ( V_39 [ V_49 ] == NULL || V_39 [ V_50 ] == NULL ) {
if ( V_44 )
F_15 ( V_27 , V_28 ) ;
return - V_46 ;
}
V_41 = (struct V_1 * ) F_16 ( V_39 [ V_50 ] ) ;
if ( F_17 ( V_39 [ V_50 ] ) < V_41 -> V_11 . V_22 ) {
if ( V_44 )
F_15 ( V_27 , V_28 ) ;
return - V_46 ;
}
if ( ! V_44 ) {
V_9 = F_18 ( V_34 , V_45 , V_37 , V_27 , sizeof( * V_30 ) , V_28 ,
false ) ;
if ( V_9 )
return V_9 ;
V_9 = V_51 ;
} else {
if ( V_28 )
return 0 ;
F_15 ( V_27 , V_28 ) ;
if ( ! V_38 )
return - V_52 ;
}
V_30 = F_9 ( V_27 ) ;
V_4 = F_13 ( V_39 [ V_49 ] ) ;
V_43 = - V_53 ;
V_42 = F_19 ( V_54 , V_55 ) ;
if ( F_20 ( ! V_42 ) )
goto V_56;
if ( V_39 [ V_57 ] == NULL ||
F_21 ( V_42 , V_39 [ V_57 ] , V_54 ) >= V_54 )
strcpy ( V_42 , L_1 ) ;
V_2 = F_22 ( V_41 , V_41 -> V_11 . V_22 , V_55 ) ;
if ( F_20 ( ! V_2 ) )
goto V_58;
V_43 = F_1 ( V_2 , V_42 , V_4 ) ;
if ( V_43 < 0 )
goto V_59;
F_23 ( & V_30 -> V_60 ) ;
if ( V_9 != V_51 ) {
F_7 ( V_30 -> V_31 ) ;
F_10 ( V_30 -> V_32 ) ;
F_10 ( V_30 -> V_31 ) ;
}
V_30 -> V_32 = V_42 ;
V_30 -> V_31 = V_2 ;
V_30 -> V_61 = V_4 ;
F_24 ( & V_30 -> V_60 ) ;
if ( V_9 == V_51 )
F_25 ( V_34 , V_27 ) ;
return V_9 ;
V_59:
F_10 ( V_2 ) ;
V_58:
F_10 ( V_42 ) ;
V_56:
if ( V_9 == V_51 )
F_26 ( V_27 , V_37 ) ;
return V_43 ;
}
static int F_27 ( struct V_62 * V_62 , struct V_35 * V_36 ,
struct V_35 * V_37 , struct V_26 * V_27 , int V_38 ,
int V_28 )
{
struct V_33 * V_34 = F_28 ( V_62 , V_63 ) ;
return F_11 ( V_34 , V_36 , V_37 , V_27 , V_38 , V_28 ) ;
}
static int F_29 ( struct V_62 * V_62 , struct V_35 * V_36 ,
struct V_35 * V_37 , struct V_26 * V_27 , int V_38 ,
int V_28 )
{
struct V_33 * V_34 = F_28 ( V_62 , V_64 ) ;
return F_11 ( V_34 , V_36 , V_37 , V_27 , V_38 , V_28 ) ;
}
static int V_29 ( struct V_65 * V_66 , const struct V_26 * V_27 ,
struct V_67 * V_68 )
{
int V_9 = 0 , V_69 = 0 ;
struct V_29 * V_30 = V_27 -> V_70 ;
struct V_71 V_6 ;
if ( F_30 ( V_66 , V_72 ) )
return V_73 ;
F_31 ( & V_30 -> V_60 ) ;
V_30 -> V_74 . V_75 = V_76 ;
F_32 ( & V_30 -> V_77 , V_66 ) ;
V_6 . V_62 = F_33 ( V_66 -> V_78 ) ;
V_6 . V_79 = V_66 -> V_78 ;
V_6 . V_80 = NULL ;
V_6 . V_81 = V_30 -> V_61 ;
V_6 . V_8 = V_30 -> V_31 -> V_11 . V_15 . V_8 ;
V_6 . V_17 = V_30 -> V_31 -> V_18 ;
V_6 . V_20 = V_21 ;
V_9 = V_6 . V_8 -> V_8 ( V_66 , & V_6 ) ;
switch ( V_9 ) {
case V_82 :
V_69 = V_83 ;
break;
case V_84 :
V_69 = V_85 ;
V_30 -> V_86 . V_87 ++ ;
break;
case V_88 :
V_69 = V_89 ;
break;
default:
F_34 ( L_2 ,
V_9 ) ;
V_69 = V_90 ;
break;
}
F_35 ( & V_30 -> V_60 ) ;
return V_69 ;
}
static int F_36 ( struct V_65 * V_66 , struct V_26 * V_27 , int V_28 , int V_91 )
{
unsigned char * V_92 = F_37 ( V_66 ) ;
struct V_29 * V_30 = V_27 -> V_70 ;
struct V_1 * V_2 ;
struct V_93 V_94 ;
struct V_95 V_96 ;
V_2 = F_22 ( V_30 -> V_31 , V_30 -> V_31 -> V_11 . V_12 . V_22 , V_72 ) ;
if ( F_20 ( ! V_2 ) )
goto V_97;
V_96 . V_98 = V_30 -> V_99 - V_28 ;
V_96 . V_100 = V_30 -> V_101 - V_91 ;
strcpy ( V_2 -> V_11 . V_12 . V_13 , V_30 -> V_31 -> V_11 . V_15 . V_8 -> V_13 ) ;
if ( F_38 ( V_66 , V_50 , V_30 -> V_31 -> V_11 . V_12 . V_22 , V_2 ) ||
F_39 ( V_66 , V_48 , V_30 -> V_102 ) ||
F_39 ( V_66 , V_49 , V_30 -> V_61 ) ||
F_38 ( V_66 , V_103 , sizeof( struct V_95 ) , & V_96 ) ||
F_40 ( V_66 , V_57 , V_30 -> V_32 ) )
goto V_97;
V_94 . V_104 = F_41 ( V_76 - V_30 -> V_74 . V_104 ) ;
V_94 . V_75 = F_41 ( V_76 - V_30 -> V_74 . V_75 ) ;
V_94 . V_105 = F_41 ( V_30 -> V_74 . V_105 ) ;
if ( F_42 ( V_66 , V_106 , sizeof( V_94 ) , & V_94 , V_107 ) )
goto V_97;
F_10 ( V_2 ) ;
return V_66 -> V_108 ;
V_97:
F_43 ( V_66 , V_92 ) ;
F_10 ( V_2 ) ;
return - 1 ;
}
static int F_44 ( struct V_62 * V_62 , struct V_65 * V_66 ,
struct V_109 * V_110 , int type ,
struct V_26 * V_27 )
{
struct V_33 * V_34 = F_28 ( V_62 , V_63 ) ;
return F_45 ( V_34 , V_66 , V_110 , type , V_27 ) ;
}
static int F_46 ( struct V_62 * V_62 , struct V_26 * V_27 , T_1 V_45 )
{
struct V_33 * V_34 = F_28 ( V_62 , V_63 ) ;
return F_47 ( V_34 , V_27 , V_45 ) ;
}
static T_2 int F_48 ( struct V_62 * V_62 )
{
struct V_33 * V_34 = F_28 ( V_62 , V_63 ) ;
return F_49 ( V_34 , & V_111 , V_112 ) ;
}
static void T_3 F_50 ( struct V_62 * V_62 )
{
struct V_33 * V_34 = F_28 ( V_62 , V_63 ) ;
F_51 ( V_34 ) ;
}
static int F_52 ( struct V_62 * V_62 , struct V_65 * V_66 ,
struct V_109 * V_110 , int type ,
struct V_26 * V_27 )
{
struct V_33 * V_34 = F_28 ( V_62 , V_64 ) ;
return F_45 ( V_34 , V_66 , V_110 , type , V_27 ) ;
}
static int F_53 ( struct V_62 * V_62 , struct V_26 * V_27 , T_1 V_45 )
{
struct V_33 * V_34 = F_28 ( V_62 , V_64 ) ;
return F_47 ( V_34 , V_27 , V_45 ) ;
}
static T_2 int F_54 ( struct V_62 * V_62 )
{
struct V_33 * V_34 = F_28 ( V_62 , V_64 ) ;
return F_49 ( V_34 , & V_113 , V_112 ) ;
}
static void T_3 F_55 ( struct V_62 * V_62 )
{
struct V_33 * V_34 = F_28 ( V_62 , V_64 ) ;
F_51 ( V_34 ) ;
}
static int T_4 F_56 ( void )
{
int V_114 , V_115 ;
V_114 = F_57 ( & V_113 , & V_116 ) ;
if ( V_114 < 0 )
F_58 ( L_3 ) ;
V_115 = F_57 ( & V_111 , & V_117 ) ;
if ( V_115 < 0 )
F_58 ( L_4 ) ;
if ( V_114 < 0 && V_115 < 0 ) {
return V_114 ;
} else
return 0 ;
}
static void T_5 F_59 ( void )
{
F_60 ( & V_111 , & V_117 ) ;
F_60 ( & V_113 , & V_116 ) ;
}
