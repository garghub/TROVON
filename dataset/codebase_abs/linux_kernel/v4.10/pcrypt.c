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
static void F_19 ( struct V_30 * V_31 , int V_32 )
{
struct V_25 * V_26 = V_31 -> V_28 ;
struct V_23 * V_24 = F_20 ( V_26 ) ;
struct V_1 * V_2 = F_21 ( V_24 ) ;
V_2 -> V_29 = V_32 ;
V_26 -> V_27 . V_33 &= ~ V_34 ;
F_22 ( V_2 ) ;
}
static void F_23 ( struct V_1 * V_2 )
{
struct V_23 * V_24 = F_16 ( V_2 ) ;
struct V_25 * V_26 = F_17 ( V_24 ) ;
V_2 -> V_29 = F_24 ( V_26 ) ;
if ( V_2 -> V_29 == - V_35 )
return;
F_22 ( V_2 ) ;
}
static int F_25 ( struct V_25 * V_26 )
{
int V_32 ;
struct V_23 * V_24 = F_20 ( V_26 ) ;
struct V_25 * V_36 = F_17 ( V_24 ) ;
struct V_1 * V_2 = F_21 ( V_24 ) ;
struct V_15 * V_37 = F_26 ( V_26 ) ;
struct V_19 * V_20 = F_11 ( V_37 ) ;
T_2 V_33 = F_27 ( V_26 ) ;
memset ( V_2 , 0 , sizeof( struct V_1 ) ) ;
V_2 -> V_38 = F_23 ;
V_2 -> V_39 = F_15 ;
F_28 ( V_36 , V_20 -> V_21 ) ;
F_29 ( V_36 , V_33 & ~ V_34 ,
F_19 , V_26 ) ;
F_30 ( V_36 , V_26 -> V_40 , V_26 -> V_41 ,
V_26 -> V_42 , V_26 -> V_43 ) ;
F_31 ( V_36 , V_26 -> V_44 ) ;
V_32 = F_1 ( V_2 , & V_20 -> V_3 , & V_45 ) ;
if ( ! V_32 )
return - V_35 ;
return V_32 ;
}
static void F_32 ( struct V_1 * V_2 )
{
struct V_23 * V_24 = F_16 ( V_2 ) ;
struct V_25 * V_26 = F_17 ( V_24 ) ;
V_2 -> V_29 = F_33 ( V_26 ) ;
if ( V_2 -> V_29 == - V_35 )
return;
F_22 ( V_2 ) ;
}
static int F_34 ( struct V_25 * V_26 )
{
int V_32 ;
struct V_23 * V_24 = F_20 ( V_26 ) ;
struct V_25 * V_36 = F_17 ( V_24 ) ;
struct V_1 * V_2 = F_21 ( V_24 ) ;
struct V_15 * V_37 = F_26 ( V_26 ) ;
struct V_19 * V_20 = F_11 ( V_37 ) ;
T_2 V_33 = F_27 ( V_26 ) ;
memset ( V_2 , 0 , sizeof( struct V_1 ) ) ;
V_2 -> V_38 = F_32 ;
V_2 -> V_39 = F_15 ;
F_28 ( V_36 , V_20 -> V_21 ) ;
F_29 ( V_36 , V_33 & ~ V_34 ,
F_19 , V_26 ) ;
F_30 ( V_36 , V_26 -> V_40 , V_26 -> V_41 ,
V_26 -> V_42 , V_26 -> V_43 ) ;
F_31 ( V_36 , V_26 -> V_44 ) ;
V_32 = F_1 ( V_2 , & V_20 -> V_3 , & V_46 ) ;
if ( ! V_32 )
return - V_35 ;
return V_32 ;
}
static int F_35 ( struct V_15 * V_47 )
{
int V_7 , V_6 ;
struct V_48 * V_49 = F_36 ( V_47 ) ;
struct V_50 * V_51 = F_37 ( V_49 ) ;
struct V_19 * V_20 = F_11 ( V_47 ) ;
struct V_15 * V_52 ;
V_6 = ( unsigned int ) F_38 ( & V_51 -> V_53 ) %
F_5 ( V_54 ) ;
V_20 -> V_3 = F_6 ( V_54 ) ;
for ( V_7 = 0 ; V_7 < V_6 ; V_7 ++ )
V_20 -> V_3 = F_7 ( V_20 -> V_3 , V_54 ) ;
V_52 = F_39 ( & V_51 -> V_55 ) ;
if ( F_40 ( V_52 ) )
return F_41 ( V_52 ) ;
V_20 -> V_21 = V_52 ;
F_42 ( V_47 , sizeof( struct V_23 ) +
sizeof( struct V_25 ) +
F_43 ( V_52 ) ) ;
return 0 ;
}
static void F_44 ( struct V_15 * V_47 )
{
struct V_19 * V_20 = F_11 ( V_47 ) ;
F_45 ( V_20 -> V_21 ) ;
}
static int F_46 ( struct V_56 * V_49 ,
struct V_57 * V_58 )
{
if ( snprintf ( V_49 -> V_58 . V_59 , V_60 ,
L_1 , V_58 -> V_59 ) >= V_60 )
return - V_61 ;
memcpy ( V_49 -> V_58 . V_62 , V_58 -> V_62 , V_60 ) ;
V_49 -> V_58 . V_63 = V_58 -> V_63 + 100 ;
V_49 -> V_58 . V_64 = V_58 -> V_64 ;
V_49 -> V_58 . V_65 = V_58 -> V_65 ;
return 0 ;
}
static int F_47 ( struct V_66 * V_67 , struct V_68 * * V_69 ,
T_2 type , T_2 V_12 )
{
struct V_50 * V_20 ;
struct V_70 * V_71 ;
struct V_48 * V_49 ;
struct V_72 * V_58 ;
const char * V_73 ;
int V_32 ;
V_71 = F_48 ( V_69 ) ;
if ( F_40 ( V_71 ) )
return F_41 ( V_71 ) ;
V_73 = F_49 ( V_69 [ 1 ] ) ;
if ( F_40 ( V_73 ) )
return F_41 ( V_73 ) ;
V_49 = F_50 ( sizeof( * V_49 ) + sizeof( * V_20 ) , V_74 ) ;
if ( ! V_49 )
return - V_75 ;
V_20 = F_37 ( V_49 ) ;
F_51 ( & V_20 -> V_55 , F_52 ( V_49 ) ) ;
V_32 = F_53 ( & V_20 -> V_55 , V_73 , 0 , 0 ) ;
if ( V_32 )
goto V_76;
V_58 = F_54 ( & V_20 -> V_55 ) ;
V_32 = F_46 ( F_52 ( V_49 ) , & V_58 -> V_27 ) ;
if ( V_32 )
goto V_77;
V_49 -> V_58 . V_27 . V_78 = V_79 ;
V_49 -> V_58 . V_80 = F_55 ( V_58 ) ;
V_49 -> V_58 . V_81 = F_56 ( V_58 ) ;
V_49 -> V_58 . V_27 . V_82 = sizeof( struct V_19 ) ;
V_49 -> V_58 . V_83 = F_35 ;
V_49 -> V_58 . exit = F_44 ;
V_49 -> V_58 . V_84 = F_10 ;
V_49 -> V_58 . V_85 = F_13 ;
V_49 -> V_58 . V_86 = F_25 ;
V_49 -> V_58 . V_87 = F_34 ;
V_32 = F_57 ( V_67 , V_49 ) ;
if ( V_32 )
goto V_77;
V_13:
return V_32 ;
V_77:
F_58 ( & V_20 -> V_55 ) ;
V_76:
F_59 ( V_49 ) ;
goto V_13;
}
static int F_60 ( struct V_66 * V_67 , struct V_68 * * V_69 )
{
struct V_70 * V_71 ;
V_71 = F_48 ( V_69 ) ;
if ( F_40 ( V_71 ) )
return F_41 ( V_71 ) ;
switch ( V_71 -> type & V_71 -> V_12 & V_88 ) {
case V_89 :
return F_47 ( V_67 , V_69 , V_71 -> type , V_71 -> V_12 ) ;
}
return - V_90 ;
}
static void F_61 ( struct V_56 * V_49 )
{
struct V_50 * V_20 = F_62 ( V_49 ) ;
F_58 ( & V_20 -> V_55 ) ;
F_59 ( V_49 ) ;
}
static int F_63 ( struct V_91 * V_92 ,
unsigned long V_93 , void * V_28 )
{
struct V_4 * V_5 ;
struct V_9 * V_94 , * V_95 ;
struct V_96 * V_10 = (struct V_96 * ) V_28 ;
if ( ! ( V_93 & V_97 ) )
return 0 ;
V_5 = F_64 ( V_92 , struct V_4 , V_98 ) ;
V_94 = F_65 ( sizeof( * V_94 ) , V_74 ) ;
if ( ! V_94 )
return - V_75 ;
if ( ! F_66 ( & V_94 -> V_12 , V_74 ) ) {
F_59 ( V_94 ) ;
return - V_75 ;
}
V_95 = V_5 -> V_11 ;
F_67 ( V_94 -> V_12 , V_10 -> V_99 ) ;
F_68 ( V_5 -> V_11 , V_94 ) ;
F_69 () ;
F_70 ( V_95 -> V_12 ) ;
F_59 ( V_95 ) ;
return 0 ;
}
static int F_71 ( struct V_100 * V_14 , const char * V_73 )
{
int V_101 ;
V_14 -> V_102 . V_103 = V_104 ;
V_101 = F_72 ( & V_14 -> V_102 , NULL , V_73 ) ;
if ( ! V_101 )
F_73 ( & V_14 -> V_102 , V_105 ) ;
return V_101 ;
}
static int F_74 ( struct V_4 * V_5 ,
const char * V_73 )
{
int V_101 = - V_75 ;
struct V_9 * V_12 ;
F_75 () ;
V_5 -> V_106 = F_76 ( L_2 , V_107 | V_108 ,
1 , V_73 ) ;
if ( ! V_5 -> V_106 )
goto V_32;
V_5 -> V_14 = F_77 ( V_5 -> V_106 ) ;
if ( ! V_5 -> V_14 )
goto V_109;
V_12 = F_65 ( sizeof( * V_12 ) , V_74 ) ;
if ( ! V_12 )
goto V_110;
if ( ! F_66 ( & V_12 -> V_12 , V_74 ) ) {
F_59 ( V_12 ) ;
goto V_110;
}
F_78 ( V_12 -> V_12 , V_111 , V_54 ) ;
F_68 ( V_5 -> V_11 , V_12 ) ;
V_5 -> V_98 . V_112 = F_63 ;
V_101 = F_79 ( V_5 -> V_14 , & V_5 -> V_98 ) ;
if ( V_101 )
goto V_113;
V_101 = F_71 ( V_5 -> V_14 , V_73 ) ;
if ( V_101 )
goto V_114;
F_80 () ;
return V_101 ;
V_114:
F_81 ( V_5 -> V_14 , & V_5 -> V_98 ) ;
V_113:
F_70 ( V_12 -> V_12 ) ;
F_59 ( V_12 ) ;
V_110:
F_82 ( V_5 -> V_14 ) ;
V_109:
F_83 ( V_5 -> V_106 ) ;
V_32:
F_80 () ;
return V_101 ;
}
static void F_84 ( struct V_4 * V_5 )
{
F_70 ( V_5 -> V_11 -> V_12 ) ;
F_59 ( V_5 -> V_11 ) ;
F_85 ( V_5 -> V_14 ) ;
F_81 ( V_5 -> V_14 , & V_5 -> V_98 ) ;
F_83 ( V_5 -> V_106 ) ;
F_82 ( V_5 -> V_14 ) ;
}
static int T_3 F_86 ( void )
{
int V_32 = - V_75 ;
V_104 = F_87 ( L_3 , NULL , V_115 ) ;
if ( ! V_104 )
goto V_32;
V_32 = F_74 ( & V_45 , L_4 ) ;
if ( V_32 )
goto V_116;
V_32 = F_74 ( & V_46 , L_5 ) ;
if ( V_32 )
goto V_117;
F_88 ( V_45 . V_14 ) ;
F_88 ( V_46 . V_14 ) ;
return F_89 ( & V_118 ) ;
V_117:
F_84 ( & V_45 ) ;
V_116:
F_90 ( V_104 ) ;
V_32:
return V_32 ;
}
static void T_4 F_91 ( void )
{
F_84 ( & V_45 ) ;
F_84 ( & V_46 ) ;
F_90 ( V_104 ) ;
F_92 ( & V_118 ) ;
}
