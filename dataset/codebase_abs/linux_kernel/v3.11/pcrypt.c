static int F_1 ( struct V_1 * V_2 , unsigned int * V_3 ,
struct V_4 * V_5 )
{
unsigned int V_6 , V_7 , V_8 ;
struct V_9 * V_10 ;
V_7 = * V_3 ;
F_2 () ;
V_10 = F_3 ( V_5 -> V_11 ) ;
if ( F_4 ( V_7 , V_10 -> V_12 ) )
goto V_13;
if ( ! F_5 ( V_10 -> V_12 ) )
goto V_13;
V_6 = V_7 % F_5 ( V_10 -> V_12 ) ;
V_7 = F_6 ( V_10 -> V_12 ) ;
for ( V_8 = 0 ; V_8 < V_6 ; V_8 ++ )
V_7 = F_7 ( V_7 , V_10 -> V_12 ) ;
* V_3 = V_7 ;
V_13:
F_8 () ;
return F_9 ( V_5 -> V_14 , V_2 , V_7 ) ;
}
static int F_10 ( struct V_15 * V_16 ,
const T_1 * V_17 , unsigned int V_18 )
{
struct V_19 * V_20 = F_11 ( V_16 ) ;
return F_12 ( V_20 -> V_21 , V_17 , V_18 ) ;
}
static int F_13 ( struct V_15 * V_16 ,
unsigned int V_22 )
{
struct V_19 * V_20 = F_11 ( V_16 ) ;
return F_14 ( V_20 -> V_21 , V_22 ) ;
}
static void F_15 ( struct V_1 * V_2 )
{
struct V_23 * V_24 = F_16 ( V_2 ) ;
struct V_25 * V_26 = F_17 ( V_24 ) ;
F_18 ( V_26 -> V_27 . V_28 , V_2 -> V_29 ) ;
}
static void F_19 ( struct V_1 * V_2 )
{
struct V_23 * V_24 = F_16 ( V_2 ) ;
struct V_30 * V_26 = F_17 ( V_24 ) ;
F_18 ( V_26 -> V_31 . V_27 . V_28 , V_2 -> V_29 ) ;
}
static void F_20 ( struct V_32 * V_31 , int V_33 )
{
struct V_25 * V_26 = V_31 -> V_28 ;
struct V_23 * V_24 = F_21 ( V_26 ) ;
struct V_1 * V_2 = F_22 ( V_24 ) ;
V_2 -> V_29 = V_33 ;
V_26 -> V_27 . V_34 &= ~ V_35 ;
F_23 ( V_2 ) ;
}
static void F_24 ( struct V_1 * V_2 )
{
struct V_23 * V_24 = F_16 ( V_2 ) ;
struct V_25 * V_26 = F_17 ( V_24 ) ;
V_2 -> V_29 = F_25 ( V_26 ) ;
if ( V_2 -> V_29 == - V_36 )
return;
F_23 ( V_2 ) ;
}
static int F_26 ( struct V_25 * V_26 )
{
int V_33 ;
struct V_23 * V_24 = F_21 ( V_26 ) ;
struct V_25 * V_37 = F_17 ( V_24 ) ;
struct V_1 * V_2 = F_22 ( V_24 ) ;
struct V_15 * V_38 = F_27 ( V_26 ) ;
struct V_19 * V_20 = F_11 ( V_38 ) ;
T_2 V_34 = F_28 ( V_26 ) ;
memset ( V_2 , 0 , sizeof( struct V_1 ) ) ;
V_2 -> V_39 = F_24 ;
V_2 -> V_40 = F_15 ;
F_29 ( V_37 , V_20 -> V_21 ) ;
F_30 ( V_37 , V_34 & ~ V_35 ,
F_20 , V_26 ) ;
F_31 ( V_37 , V_26 -> V_41 , V_26 -> V_42 ,
V_26 -> V_43 , V_26 -> V_44 ) ;
F_32 ( V_37 , V_26 -> V_45 , V_26 -> V_46 ) ;
V_33 = F_1 ( V_2 , & V_20 -> V_3 , & V_47 ) ;
if ( ! V_33 )
return - V_36 ;
return V_33 ;
}
static void F_33 ( struct V_1 * V_2 )
{
struct V_23 * V_24 = F_16 ( V_2 ) ;
struct V_25 * V_26 = F_17 ( V_24 ) ;
V_2 -> V_29 = F_34 ( V_26 ) ;
if ( V_2 -> V_29 == - V_36 )
return;
F_23 ( V_2 ) ;
}
static int F_35 ( struct V_25 * V_26 )
{
int V_33 ;
struct V_23 * V_24 = F_21 ( V_26 ) ;
struct V_25 * V_37 = F_17 ( V_24 ) ;
struct V_1 * V_2 = F_22 ( V_24 ) ;
struct V_15 * V_38 = F_27 ( V_26 ) ;
struct V_19 * V_20 = F_11 ( V_38 ) ;
T_2 V_34 = F_28 ( V_26 ) ;
memset ( V_2 , 0 , sizeof( struct V_1 ) ) ;
V_2 -> V_39 = F_33 ;
V_2 -> V_40 = F_15 ;
F_29 ( V_37 , V_20 -> V_21 ) ;
F_30 ( V_37 , V_34 & ~ V_35 ,
F_20 , V_26 ) ;
F_31 ( V_37 , V_26 -> V_41 , V_26 -> V_42 ,
V_26 -> V_43 , V_26 -> V_44 ) ;
F_32 ( V_37 , V_26 -> V_45 , V_26 -> V_46 ) ;
V_33 = F_1 ( V_2 , & V_20 -> V_3 , & V_48 ) ;
if ( ! V_33 )
return - V_36 ;
return V_33 ;
}
static void F_36 ( struct V_1 * V_2 )
{
struct V_23 * V_24 = F_16 ( V_2 ) ;
struct V_30 * V_26 = F_17 ( V_24 ) ;
V_2 -> V_29 = F_37 ( V_26 ) ;
if ( V_2 -> V_29 == - V_36 )
return;
F_23 ( V_2 ) ;
}
static int F_38 ( struct V_30 * V_26 )
{
int V_33 ;
struct V_25 * V_31 = & V_26 -> V_31 ;
struct V_23 * V_24 = F_21 ( V_31 ) ;
struct V_30 * V_37 = F_17 ( V_24 ) ;
struct V_1 * V_2 = F_22 ( V_24 ) ;
struct V_15 * V_38 = F_39 ( V_26 ) ;
struct V_19 * V_20 = F_11 ( V_38 ) ;
T_2 V_34 = F_28 ( V_31 ) ;
memset ( V_2 , 0 , sizeof( struct V_1 ) ) ;
V_2 -> V_39 = F_36 ;
V_2 -> V_40 = F_19 ;
F_40 ( V_37 , V_20 -> V_21 ) ;
F_41 ( V_37 , V_34 & ~ V_35 ,
F_20 , V_31 ) ;
F_42 ( V_37 , V_31 -> V_41 , V_31 -> V_42 ,
V_31 -> V_43 , V_31 -> V_44 ) ;
F_43 ( V_37 , V_31 -> V_45 , V_31 -> V_46 ) ;
F_44 ( V_37 , V_26 -> V_49 , V_26 -> V_50 ) ;
V_33 = F_1 ( V_2 , & V_20 -> V_3 , & V_47 ) ;
if ( ! V_33 )
return - V_36 ;
return V_33 ;
}
static int F_45 ( struct V_51 * V_52 )
{
int V_7 , V_6 ;
struct V_53 * V_54 = F_46 ( V_52 ) ;
struct V_55 * V_56 = F_47 ( V_54 ) ;
struct V_19 * V_20 = F_48 ( V_52 ) ;
struct V_15 * V_57 ;
V_56 -> V_58 ++ ;
V_6 = V_56 -> V_58 % F_5 ( V_59 ) ;
V_20 -> V_3 = F_6 ( V_59 ) ;
for ( V_7 = 0 ; V_7 < V_6 ; V_7 ++ )
V_20 -> V_3 = F_7 ( V_20 -> V_3 , V_59 ) ;
V_57 = F_49 ( F_47 ( V_54 ) ) ;
if ( F_50 ( V_57 ) )
return F_51 ( V_57 ) ;
V_20 -> V_21 = V_57 ;
V_52 -> V_60 . V_61 = sizeof( struct V_23 )
+ sizeof( struct V_30 )
+ F_52 ( V_57 ) ;
return 0 ;
}
static void F_53 ( struct V_51 * V_52 )
{
struct V_19 * V_20 = F_48 ( V_52 ) ;
F_54 ( V_20 -> V_21 ) ;
}
static struct V_53 * F_55 ( struct V_62 * V_63 )
{
struct V_53 * V_54 ;
struct V_55 * V_20 ;
int V_33 ;
V_54 = F_56 ( sizeof( * V_54 ) + sizeof( * V_20 ) , V_64 ) ;
if ( ! V_54 ) {
V_54 = F_57 ( - V_65 ) ;
goto V_13;
}
V_33 = - V_66 ;
if ( snprintf ( V_54 -> V_63 . V_67 , V_68 ,
L_1 , V_63 -> V_67 ) >= V_68 )
goto V_69;
memcpy ( V_54 -> V_63 . V_70 , V_63 -> V_70 , V_68 ) ;
V_20 = F_47 ( V_54 ) ;
V_33 = F_58 ( & V_20 -> V_71 , V_63 , V_54 ,
V_72 ) ;
if ( V_33 )
goto V_69;
V_54 -> V_63 . V_73 = V_63 -> V_73 + 100 ;
V_54 -> V_63 . V_74 = V_63 -> V_74 ;
V_54 -> V_63 . V_75 = V_63 -> V_75 ;
V_13:
return V_54 ;
V_69:
F_59 ( V_54 ) ;
V_54 = F_57 ( V_33 ) ;
goto V_13;
}
static struct V_53 * F_60 ( struct V_76 * * V_77 ,
T_2 type , T_2 V_12 )
{
struct V_53 * V_54 ;
struct V_62 * V_63 ;
V_63 = F_61 ( V_77 , type , ( V_12 & V_72 ) ) ;
if ( F_50 ( V_63 ) )
return F_62 ( V_63 ) ;
V_54 = F_55 ( V_63 ) ;
if ( F_50 ( V_54 ) )
goto V_78;
V_54 -> V_63 . V_79 = V_80 | V_81 ;
V_54 -> V_63 . V_82 = & V_83 ;
V_54 -> V_63 . V_84 . V_85 = V_63 -> V_84 . V_85 ;
V_54 -> V_63 . V_84 . V_86 = V_63 -> V_84 . V_86 ;
V_54 -> V_63 . V_84 . V_87 = V_63 -> V_84 . V_87 ;
V_54 -> V_63 . V_88 = sizeof( struct V_19 ) ;
V_54 -> V_63 . V_89 = F_45 ;
V_54 -> V_63 . V_90 = F_53 ;
V_54 -> V_63 . V_84 . V_91 = F_10 ;
V_54 -> V_63 . V_84 . V_92 = F_13 ;
V_54 -> V_63 . V_84 . V_93 = F_26 ;
V_54 -> V_63 . V_84 . V_94 = F_35 ;
V_54 -> V_63 . V_84 . V_95 = F_38 ;
V_78:
F_63 ( V_63 ) ;
return V_54 ;
}
static struct V_53 * F_64 ( struct V_76 * * V_77 )
{
struct V_96 * V_97 ;
V_97 = F_65 ( V_77 ) ;
if ( F_50 ( V_97 ) )
return F_62 ( V_97 ) ;
switch ( V_97 -> type & V_97 -> V_12 & V_72 ) {
case V_80 :
return F_60 ( V_77 , V_97 -> type , V_97 -> V_12 ) ;
}
return F_57 ( - V_98 ) ;
}
static void F_66 ( struct V_53 * V_54 )
{
struct V_55 * V_20 = F_47 ( V_54 ) ;
F_67 ( & V_20 -> V_71 ) ;
F_59 ( V_54 ) ;
}
static int F_68 ( struct V_99 * V_100 ,
unsigned long V_101 , void * V_28 )
{
struct V_4 * V_5 ;
struct V_9 * V_102 , * V_103 ;
struct V_104 * V_10 = (struct V_104 * ) V_28 ;
if ( ! ( V_101 & V_105 ) )
return 0 ;
V_5 = F_69 ( V_100 , struct V_4 , V_106 ) ;
V_102 = F_70 ( sizeof( * V_102 ) , V_64 ) ;
if ( ! V_102 )
return - V_65 ;
if ( ! F_71 ( & V_102 -> V_12 , V_64 ) ) {
F_59 ( V_102 ) ;
return - V_65 ;
}
V_103 = V_5 -> V_11 ;
F_72 ( V_102 -> V_12 , V_10 -> V_107 ) ;
F_73 ( V_5 -> V_11 , V_102 ) ;
F_74 () ;
F_75 ( V_103 -> V_12 ) ;
F_59 ( V_103 ) ;
return 0 ;
}
static int F_76 ( struct V_108 * V_14 , const char * V_109 )
{
int V_110 ;
V_14 -> V_111 . V_112 = V_113 ;
V_110 = F_77 ( & V_14 -> V_111 , NULL , V_109 ) ;
if ( ! V_110 )
F_78 ( & V_14 -> V_111 , V_114 ) ;
return V_110 ;
}
static int F_79 ( struct V_4 * V_5 ,
const char * V_109 )
{
int V_110 = - V_65 ;
struct V_9 * V_12 ;
F_80 () ;
V_5 -> V_115 = F_81 ( L_2 , V_116 | V_117 ,
1 , V_109 ) ;
if ( ! V_5 -> V_115 )
goto V_33;
V_5 -> V_14 = F_82 ( V_5 -> V_115 ) ;
if ( ! V_5 -> V_14 )
goto V_118;
V_12 = F_70 ( sizeof( * V_12 ) , V_64 ) ;
if ( ! V_12 )
goto V_119;
if ( ! F_71 ( & V_12 -> V_12 , V_64 ) ) {
F_59 ( V_12 ) ;
goto V_119;
}
F_83 ( V_12 -> V_12 , V_120 , V_59 ) ;
F_73 ( V_5 -> V_11 , V_12 ) ;
V_5 -> V_106 . V_121 = F_68 ;
V_110 = F_84 ( V_5 -> V_14 , & V_5 -> V_106 ) ;
if ( V_110 )
goto V_122;
V_110 = F_76 ( V_5 -> V_14 , V_109 ) ;
if ( V_110 )
goto V_123;
F_85 () ;
return V_110 ;
V_123:
F_86 ( V_5 -> V_14 , & V_5 -> V_106 ) ;
V_122:
F_75 ( V_12 -> V_12 ) ;
F_59 ( V_12 ) ;
V_119:
F_87 ( V_5 -> V_14 ) ;
V_118:
F_88 ( V_5 -> V_115 ) ;
V_33:
F_85 () ;
return V_110 ;
}
static void F_89 ( struct V_4 * V_5 )
{
F_75 ( V_5 -> V_11 -> V_12 ) ;
F_59 ( V_5 -> V_11 ) ;
F_90 ( V_5 -> V_14 ) ;
F_86 ( V_5 -> V_14 , & V_5 -> V_106 ) ;
F_88 ( V_5 -> V_115 ) ;
F_87 ( V_5 -> V_14 ) ;
}
static int T_3 F_91 ( void )
{
int V_33 = - V_65 ;
V_113 = F_92 ( L_3 , NULL , V_124 ) ;
if ( ! V_113 )
goto V_33;
V_33 = F_79 ( & V_47 , L_4 ) ;
if ( V_33 )
goto V_125;
V_33 = F_79 ( & V_48 , L_5 ) ;
if ( V_33 )
goto V_126;
F_93 ( V_47 . V_14 ) ;
F_93 ( V_48 . V_14 ) ;
return F_94 ( & V_127 ) ;
V_126:
F_89 ( & V_47 ) ;
V_125:
F_95 ( V_113 ) ;
V_33:
return V_33 ;
}
static void T_4 F_96 ( void )
{
F_89 ( & V_47 ) ;
F_89 ( & V_48 ) ;
F_95 ( V_113 ) ;
F_97 ( & V_127 ) ;
}
