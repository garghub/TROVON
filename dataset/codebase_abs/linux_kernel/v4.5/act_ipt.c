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
static int F_11 ( struct V_33 * V_33 , struct V_34 * V_35 , struct V_34 * V_36 ,
struct V_26 * V_27 , int V_37 , int V_28 )
{
struct V_34 * V_38 [ V_39 + 1 ] ;
struct V_29 * V_30 ;
struct V_1 * V_40 , * V_2 ;
char * V_41 ;
int V_9 = 0 , V_42 ;
T_1 V_4 = 0 ;
T_1 V_43 = 0 ;
if ( V_35 == NULL )
return - V_44 ;
V_42 = F_12 ( V_38 , V_39 , V_35 , V_45 ) ;
if ( V_42 < 0 )
return V_42 ;
if ( V_38 [ V_46 ] == NULL )
return - V_44 ;
if ( V_38 [ V_47 ] == NULL )
return - V_44 ;
V_40 = (struct V_1 * ) F_13 ( V_38 [ V_47 ] ) ;
if ( F_14 ( V_38 [ V_47 ] ) < V_40 -> V_11 . V_22 )
return - V_44 ;
if ( V_38 [ V_48 ] != NULL )
V_43 = F_15 ( V_38 [ V_48 ] ) ;
if ( ! F_16 ( V_43 , V_27 , V_28 ) ) {
V_9 = F_17 ( V_43 , V_36 , V_27 , sizeof( * V_30 ) , V_28 , false ) ;
if ( V_9 )
return V_9 ;
V_9 = V_49 ;
} else {
if ( V_28 )
return 0 ;
F_18 ( V_27 , V_28 ) ;
if ( ! V_37 )
return - V_50 ;
}
V_30 = F_9 ( V_27 ) ;
V_4 = F_15 ( V_38 [ V_46 ] ) ;
V_42 = - V_51 ;
V_41 = F_19 ( V_52 , V_53 ) ;
if ( F_20 ( ! V_41 ) )
goto V_54;
if ( V_38 [ V_55 ] == NULL ||
F_21 ( V_41 , V_38 [ V_55 ] , V_52 ) >= V_52 )
strcpy ( V_41 , L_1 ) ;
V_2 = F_22 ( V_40 , V_40 -> V_11 . V_22 , V_53 ) ;
if ( F_20 ( ! V_2 ) )
goto V_56;
V_42 = F_1 ( V_2 , V_41 , V_4 ) ;
if ( V_42 < 0 )
goto V_57;
F_23 ( & V_30 -> V_58 ) ;
if ( V_9 != V_49 ) {
F_7 ( V_30 -> V_31 ) ;
F_10 ( V_30 -> V_32 ) ;
F_10 ( V_30 -> V_31 ) ;
}
V_30 -> V_32 = V_41 ;
V_30 -> V_31 = V_2 ;
V_30 -> V_59 = V_4 ;
F_24 ( & V_30 -> V_58 ) ;
if ( V_9 == V_49 )
F_25 ( V_27 ) ;
return V_9 ;
V_57:
F_10 ( V_2 ) ;
V_56:
F_10 ( V_41 ) ;
V_54:
if ( V_9 == V_49 )
F_26 ( V_27 , V_36 ) ;
return V_42 ;
}
static int V_29 ( struct V_60 * V_61 , const struct V_26 * V_27 ,
struct V_62 * V_63 )
{
int V_9 = 0 , V_64 = 0 ;
struct V_29 * V_30 = V_27 -> V_65 ;
struct V_66 V_6 ;
if ( F_27 ( V_61 , V_67 ) )
return V_68 ;
F_28 ( & V_30 -> V_58 ) ;
V_30 -> V_69 . V_70 = V_71 ;
F_29 ( & V_30 -> V_72 , V_61 ) ;
V_6 . V_33 = F_30 ( V_61 -> V_73 ) ;
V_6 . V_74 = V_61 -> V_73 ;
V_6 . V_75 = NULL ;
V_6 . V_76 = V_30 -> V_59 ;
V_6 . V_8 = V_30 -> V_31 -> V_11 . V_15 . V_8 ;
V_6 . V_17 = V_30 -> V_31 -> V_18 ;
V_6 . V_20 = V_21 ;
V_9 = V_6 . V_8 -> V_8 ( V_61 , & V_6 ) ;
switch ( V_9 ) {
case V_77 :
V_64 = V_78 ;
break;
case V_79 :
V_64 = V_80 ;
V_30 -> V_81 . V_82 ++ ;
break;
case V_83 :
V_64 = V_84 ;
break;
default:
F_31 ( L_2 ,
V_9 ) ;
V_64 = V_85 ;
break;
}
F_32 ( & V_30 -> V_58 ) ;
return V_64 ;
}
static int F_33 ( struct V_60 * V_61 , struct V_26 * V_27 , int V_28 , int V_86 )
{
unsigned char * V_87 = F_34 ( V_61 ) ;
struct V_29 * V_30 = V_27 -> V_65 ;
struct V_1 * V_2 ;
struct V_88 V_89 ;
struct V_90 V_91 ;
V_2 = F_22 ( V_30 -> V_31 , V_30 -> V_31 -> V_11 . V_12 . V_22 , V_67 ) ;
if ( F_20 ( ! V_2 ) )
goto V_92;
V_91 . V_93 = V_30 -> V_94 - V_28 ;
V_91 . V_95 = V_30 -> V_96 - V_86 ;
strcpy ( V_2 -> V_11 . V_12 . V_13 , V_30 -> V_31 -> V_11 . V_15 . V_8 -> V_13 ) ;
if ( F_35 ( V_61 , V_47 , V_30 -> V_31 -> V_11 . V_12 . V_22 , V_2 ) ||
F_36 ( V_61 , V_48 , V_30 -> V_97 ) ||
F_36 ( V_61 , V_46 , V_30 -> V_59 ) ||
F_35 ( V_61 , V_98 , sizeof( struct V_90 ) , & V_91 ) ||
F_37 ( V_61 , V_55 , V_30 -> V_32 ) )
goto V_92;
V_89 . V_99 = F_38 ( V_71 - V_30 -> V_69 . V_99 ) ;
V_89 . V_70 = F_38 ( V_71 - V_30 -> V_69 . V_70 ) ;
V_89 . V_100 = F_38 ( V_30 -> V_69 . V_100 ) ;
if ( F_35 ( V_61 , V_101 , sizeof ( V_89 ) , & V_89 ) )
goto V_92;
F_10 ( V_2 ) ;
return V_61 -> V_102 ;
V_92:
F_39 ( V_61 , V_87 ) ;
F_10 ( V_2 ) ;
return - 1 ;
}
static int T_2 F_40 ( void )
{
int V_103 , V_104 ;
V_103 = F_41 ( & V_105 , V_106 ) ;
if ( V_103 < 0 )
F_42 ( L_3 ) ;
V_104 = F_41 ( & V_107 , V_106 ) ;
if ( V_104 < 0 )
F_42 ( L_4 ) ;
if ( V_103 < 0 && V_104 < 0 ) {
return V_103 ;
} else
return 0 ;
}
static void T_3 F_43 ( void )
{
F_44 ( & V_105 ) ;
F_44 ( & V_107 ) ;
}
