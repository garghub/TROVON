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
static int F_11 ( struct V_36 * V_37 , struct V_36 * V_38 ,
struct V_39 * V_40 , int V_41 , int V_28 )
{
struct V_36 * V_42 [ V_43 + 1 ] ;
struct V_26 * V_27 ;
struct V_44 * V_45 ;
struct V_1 * V_46 , * V_2 ;
char * V_47 ;
int V_9 = 0 , V_48 ;
T_1 V_4 = 0 ;
T_1 V_49 = 0 ;
if ( V_37 == NULL )
return - V_50 ;
V_48 = F_12 ( V_42 , V_43 , V_37 , V_51 ) ;
if ( V_48 < 0 )
return V_48 ;
if ( V_42 [ V_52 ] == NULL )
return - V_50 ;
if ( V_42 [ V_53 ] == NULL )
return - V_50 ;
V_46 = (struct V_1 * ) F_13 ( V_42 [ V_53 ] ) ;
if ( F_14 ( V_42 [ V_53 ] ) < V_46 -> V_11 . V_22 )
return - V_50 ;
if ( V_42 [ V_54 ] != NULL )
V_49 = F_15 ( V_42 [ V_54 ] ) ;
V_45 = F_16 ( V_49 , V_40 , V_28 , & V_34 ) ;
if ( ! V_45 ) {
V_45 = F_17 ( V_49 , V_38 , V_40 , sizeof( * V_27 ) , V_28 ,
& V_55 , & V_34 ) ;
if ( F_3 ( V_45 ) )
return F_4 ( V_45 ) ;
V_9 = V_56 ;
} else {
if ( ! V_41 ) {
F_8 ( F_18 ( V_45 ) , V_28 ) ;
return - V_57 ;
}
}
V_27 = F_18 ( V_45 ) ;
V_4 = F_15 ( V_42 [ V_52 ] ) ;
V_48 = - V_58 ;
V_47 = F_19 ( V_59 , V_60 ) ;
if ( F_20 ( ! V_47 ) )
goto V_61;
if ( V_42 [ V_62 ] == NULL ||
F_21 ( V_47 , V_42 [ V_62 ] , V_59 ) >= V_59 )
strcpy ( V_47 , L_1 ) ;
V_2 = F_22 ( V_46 , V_46 -> V_11 . V_22 , V_60 ) ;
if ( F_20 ( ! V_2 ) )
goto V_63;
V_48 = F_1 ( V_2 , V_47 , V_4 ) ;
if ( V_48 < 0 )
goto V_64;
F_23 ( & V_27 -> V_65 ) ;
if ( V_9 != V_56 ) {
F_7 ( V_27 -> V_31 ) ;
F_9 ( V_27 -> V_32 ) ;
F_9 ( V_27 -> V_31 ) ;
}
V_27 -> V_32 = V_47 ;
V_27 -> V_31 = V_2 ;
V_27 -> V_66 = V_4 ;
F_24 ( & V_27 -> V_65 ) ;
if ( V_9 == V_56 )
F_25 ( V_45 , & V_34 ) ;
return V_9 ;
V_64:
F_9 ( V_2 ) ;
V_63:
F_9 ( V_47 ) ;
V_61:
F_9 ( V_45 ) ;
return V_48 ;
}
static int F_26 ( struct V_39 * V_40 , int V_28 )
{
struct V_26 * V_27 = V_40 -> V_67 ;
return F_8 ( V_27 , V_28 ) ;
}
static int V_26 ( struct V_68 * V_69 , struct V_39 * V_40 ,
struct V_70 * V_71 )
{
int V_9 = 0 , V_72 = 0 ;
struct V_26 * V_27 = V_40 -> V_67 ;
struct V_73 V_6 ;
if ( F_27 ( V_69 ) ) {
if ( F_28 ( V_69 , 0 , 0 , V_74 ) )
return V_75 ;
}
F_29 ( & V_27 -> V_65 ) ;
V_27 -> V_76 . V_77 = V_78 ;
F_30 ( & V_27 -> V_79 , V_69 ) ;
V_6 . V_80 = V_69 -> V_81 ;
V_6 . V_82 = NULL ;
V_6 . V_83 = V_27 -> V_66 ;
V_6 . V_8 = V_27 -> V_31 -> V_11 . V_15 . V_8 ;
V_6 . V_17 = V_27 -> V_31 -> V_18 ;
V_9 = V_6 . V_8 -> V_8 ( V_69 , & V_6 ) ;
switch ( V_9 ) {
case V_84 :
V_72 = V_85 ;
break;
case V_86 :
V_72 = V_87 ;
V_27 -> V_88 . V_89 ++ ;
break;
case V_90 :
V_72 = V_91 ;
break;
default:
if ( F_31 () )
F_32 ( L_2
L_3 , V_9 ) ;
V_72 = V_92 ;
break;
}
F_33 ( & V_27 -> V_65 ) ;
return V_72 ;
}
static int F_34 ( struct V_68 * V_69 , struct V_39 * V_40 , int V_28 , int V_93 )
{
unsigned char * V_94 = F_35 ( V_69 ) ;
struct V_26 * V_27 = V_40 -> V_67 ;
struct V_1 * V_2 ;
struct V_95 V_96 ;
struct V_97 V_98 ;
V_2 = F_22 ( V_27 -> V_31 , V_27 -> V_31 -> V_11 . V_12 . V_22 , V_74 ) ;
if ( F_20 ( ! V_2 ) )
goto V_99;
V_98 . V_100 = V_27 -> V_29 - V_28 ;
V_98 . V_101 = V_27 -> V_30 - V_93 ;
strcpy ( V_2 -> V_11 . V_12 . V_13 , V_27 -> V_31 -> V_11 . V_15 . V_8 -> V_13 ) ;
F_36 ( V_69 , V_53 , V_27 -> V_31 -> V_11 . V_12 . V_22 , V_2 ) ;
F_37 ( V_69 , V_54 , V_27 -> V_102 ) ;
F_37 ( V_69 , V_52 , V_27 -> V_66 ) ;
F_36 ( V_69 , V_103 , sizeof( struct V_97 ) , & V_98 ) ;
F_38 ( V_69 , V_62 , V_27 -> V_32 ) ;
V_96 . V_104 = F_39 ( V_78 - V_27 -> V_76 . V_104 ) ;
V_96 . V_77 = F_39 ( V_78 - V_27 -> V_76 . V_77 ) ;
V_96 . V_105 = F_39 ( V_27 -> V_76 . V_105 ) ;
F_36 ( V_69 , V_106 , sizeof ( V_96 ) , & V_96 ) ;
F_9 ( V_2 ) ;
return V_69 -> V_107 ;
V_99:
F_40 ( V_69 , V_94 ) ;
F_9 ( V_2 ) ;
return - 1 ;
}
static int T_2 F_41 ( void )
{
return F_42 ( & V_108 ) ;
}
static void T_3 F_43 ( void )
{
F_44 ( & V_108 ) ;
}
