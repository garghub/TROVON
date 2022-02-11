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
} ;
if ( V_6 . V_8 -> V_25 != NULL )
V_6 . V_8 -> V_25 ( & V_6 ) ;
F_6 ( V_6 . V_8 -> V_23 ) ;
}
static int F_8 ( struct V_26 * V_27 , int V_28 )
{
int V_9 = 0 ;
if ( V_27 ) {
if ( V_28 )
V_27 -> V_29 -- ;
V_27 -> V_30 -- ;
if ( V_27 -> V_29 <= 0 && V_27 -> V_30 <= 0 ) {
F_7 ( V_27 -> V_31 ) ;
F_9 ( V_27 -> V_32 ) ;
F_9 ( V_27 -> V_31 ) ;
F_10 ( & V_27 -> V_33 , & V_34 ) ;
V_9 = V_35 ;
}
}
return V_9 ;
}
static int F_11 ( struct V_36 * V_36 , struct V_37 * V_38 , struct V_37 * V_39 ,
struct V_40 * V_41 , int V_42 , int V_28 )
{
struct V_37 * V_43 [ V_44 + 1 ] ;
struct V_26 * V_27 ;
struct V_45 * V_46 ;
struct V_1 * V_47 , * V_2 ;
char * V_48 ;
int V_9 = 0 , V_49 ;
T_1 V_4 = 0 ;
T_1 V_50 = 0 ;
if ( V_38 == NULL )
return - V_51 ;
V_49 = F_12 ( V_43 , V_44 , V_38 , V_52 ) ;
if ( V_49 < 0 )
return V_49 ;
if ( V_43 [ V_53 ] == NULL )
return - V_51 ;
if ( V_43 [ V_54 ] == NULL )
return - V_51 ;
V_47 = (struct V_1 * ) F_13 ( V_43 [ V_54 ] ) ;
if ( F_14 ( V_43 [ V_54 ] ) < V_47 -> V_11 . V_22 )
return - V_51 ;
if ( V_43 [ V_55 ] != NULL )
V_50 = F_15 ( V_43 [ V_55 ] ) ;
V_46 = F_16 ( V_50 , V_41 , V_28 ) ;
if ( ! V_46 ) {
V_46 = F_17 ( V_50 , V_39 , V_41 , sizeof( * V_27 ) , V_28 ) ;
if ( F_3 ( V_46 ) )
return F_4 ( V_46 ) ;
V_9 = V_56 ;
} else {
if ( V_28 )
return 0 ;
F_8 ( F_18 ( V_46 ) , V_28 ) ;
if ( ! V_42 )
return - V_57 ;
}
V_27 = F_18 ( V_46 ) ;
V_4 = F_15 ( V_43 [ V_53 ] ) ;
V_49 = - V_58 ;
V_48 = F_19 ( V_59 , V_60 ) ;
if ( F_20 ( ! V_48 ) )
goto V_61;
if ( V_43 [ V_62 ] == NULL ||
F_21 ( V_48 , V_43 [ V_62 ] , V_59 ) >= V_59 )
strcpy ( V_48 , L_1 ) ;
V_2 = F_22 ( V_47 , V_47 -> V_11 . V_22 , V_60 ) ;
if ( F_20 ( ! V_2 ) )
goto V_63;
V_49 = F_1 ( V_2 , V_48 , V_4 ) ;
if ( V_49 < 0 )
goto V_64;
F_23 ( & V_27 -> V_65 ) ;
if ( V_9 != V_56 ) {
F_7 ( V_27 -> V_31 ) ;
F_9 ( V_27 -> V_32 ) ;
F_9 ( V_27 -> V_31 ) ;
}
V_27 -> V_32 = V_48 ;
V_27 -> V_31 = V_2 ;
V_27 -> V_66 = V_4 ;
F_24 ( & V_27 -> V_65 ) ;
if ( V_9 == V_56 )
F_25 ( V_46 , V_41 -> V_67 -> V_68 ) ;
return V_9 ;
V_64:
F_9 ( V_2 ) ;
V_63:
F_9 ( V_48 ) ;
V_61:
if ( V_9 == V_56 ) {
if ( V_39 )
F_26 ( & V_46 -> V_69 ,
& V_46 -> V_70 ) ;
F_27 ( V_46 , V_71 ) ;
}
return V_49 ;
}
static int F_28 ( struct V_40 * V_41 , int V_28 )
{
struct V_26 * V_27 = V_41 -> V_72 ;
return F_8 ( V_27 , V_28 ) ;
}
static int V_26 ( struct V_73 * V_74 , const struct V_40 * V_41 ,
struct V_75 * V_76 )
{
int V_9 = 0 , V_77 = 0 ;
struct V_26 * V_27 = V_41 -> V_72 ;
struct V_78 V_6 ;
if ( F_29 ( V_74 , V_79 ) )
return V_80 ;
F_30 ( & V_27 -> V_65 ) ;
V_27 -> V_81 . V_82 = V_83 ;
F_31 ( & V_27 -> V_84 , V_74 ) ;
V_6 . V_85 = V_74 -> V_86 ;
V_6 . V_87 = NULL ;
V_6 . V_88 = V_27 -> V_66 ;
V_6 . V_8 = V_27 -> V_31 -> V_11 . V_15 . V_8 ;
V_6 . V_17 = V_27 -> V_31 -> V_18 ;
V_9 = V_6 . V_8 -> V_8 ( V_74 , & V_6 ) ;
switch ( V_9 ) {
case V_89 :
V_77 = V_90 ;
break;
case V_91 :
V_77 = V_92 ;
V_27 -> V_93 . V_94 ++ ;
break;
case V_95 :
V_77 = V_96 ;
break;
default:
F_32 ( L_2 ,
V_9 ) ;
V_77 = V_97 ;
break;
}
F_33 ( & V_27 -> V_65 ) ;
return V_77 ;
}
static int F_34 ( struct V_73 * V_74 , struct V_40 * V_41 , int V_28 , int V_98 )
{
unsigned char * V_99 = F_35 ( V_74 ) ;
struct V_26 * V_27 = V_41 -> V_72 ;
struct V_1 * V_2 ;
struct V_100 V_101 ;
struct V_102 V_103 ;
V_2 = F_22 ( V_27 -> V_31 , V_27 -> V_31 -> V_11 . V_12 . V_22 , V_79 ) ;
if ( F_20 ( ! V_2 ) )
goto V_104;
V_103 . V_105 = V_27 -> V_29 - V_28 ;
V_103 . V_106 = V_27 -> V_30 - V_98 ;
strcpy ( V_2 -> V_11 . V_12 . V_13 , V_27 -> V_31 -> V_11 . V_15 . V_8 -> V_13 ) ;
if ( F_36 ( V_74 , V_54 , V_27 -> V_31 -> V_11 . V_12 . V_22 , V_2 ) ||
F_37 ( V_74 , V_55 , V_27 -> V_107 ) ||
F_37 ( V_74 , V_53 , V_27 -> V_66 ) ||
F_36 ( V_74 , V_108 , sizeof( struct V_102 ) , & V_103 ) ||
F_38 ( V_74 , V_62 , V_27 -> V_32 ) )
goto V_104;
V_101 . V_109 = F_39 ( V_83 - V_27 -> V_81 . V_109 ) ;
V_101 . V_82 = F_39 ( V_83 - V_27 -> V_81 . V_82 ) ;
V_101 . V_110 = F_39 ( V_27 -> V_81 . V_110 ) ;
if ( F_36 ( V_74 , V_111 , sizeof ( V_101 ) , & V_101 ) )
goto V_104;
F_9 ( V_2 ) ;
return V_74 -> V_112 ;
V_104:
F_40 ( V_74 , V_99 ) ;
F_9 ( V_2 ) ;
return - 1 ;
}
static int T_2 F_41 ( void )
{
int V_113 , V_114 , V_49 ;
V_49 = F_42 ( & V_34 , V_115 ) ;
if ( V_49 )
return V_49 ;
V_113 = F_43 ( & V_116 ) ;
if ( V_113 < 0 )
F_44 ( L_3 ) ;
V_114 = F_43 ( & V_117 ) ;
if ( V_114 < 0 )
F_44 ( L_4 ) ;
if ( V_113 < 0 && V_114 < 0 ) {
F_45 ( & V_34 ) ;
return V_113 ;
} else
return 0 ;
}
static void T_3 F_46 ( void )
{
F_47 ( & V_116 ) ;
F_47 ( & V_117 ) ;
F_45 ( & V_34 ) ;
}
