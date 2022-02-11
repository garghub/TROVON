static inline struct V_1 * F_1 (
struct V_2 * V_3 )
{
unsigned long V_4 = F_2 ( F_3 ( V_3 ) ) ;
return ( void * ) F_4 ( ( V_5 * ) F_5 ( V_3 ) , V_4 + 1 ) ;
}
static void F_6 ( struct V_6 * V_3 , int V_7 )
{
struct V_8 * V_9 = V_3 -> V_10 ;
if ( V_7 == - V_11 )
return;
V_9 -> V_7 = V_7 ;
F_7 ( & V_9 -> V_12 ) ;
}
static int F_8 ( struct V_13 * V_14 , const V_5 * V_15 ,
unsigned int V_16 )
{
struct V_17 * V_18 = F_9 ( V_14 ) ;
struct V_19 * V_20 = V_18 -> V_20 ;
struct V_21 * V_22 = V_18 -> V_22 ;
struct {
T_1 V_23 ;
V_5 V_24 [ 8 ] ;
struct V_8 V_9 ;
struct V_25 V_26 [ 1 ] ;
struct V_27 V_3 ;
} * V_10 ;
int V_7 ;
F_10 ( V_22 , V_28 ) ;
F_11 ( V_22 , F_12 ( V_14 ) &
V_28 ) ;
V_7 = F_13 ( V_22 , V_15 , V_16 ) ;
F_14 ( V_14 , F_15 ( V_22 ) &
V_29 ) ;
if ( V_7 )
return V_7 ;
V_10 = F_16 ( sizeof( * V_10 ) + F_17 ( V_22 ) ,
V_30 ) ;
if ( ! V_10 )
return - V_31 ;
F_18 ( & V_10 -> V_9 . V_12 ) ;
F_19 ( V_10 -> V_26 , & V_10 -> V_23 , sizeof( V_10 -> V_23 ) ) ;
F_20 ( & V_10 -> V_3 , V_22 ) ;
F_21 ( & V_10 -> V_3 , V_32 |
V_33 ,
F_6 ,
& V_10 -> V_9 ) ;
F_22 ( & V_10 -> V_3 , V_10 -> V_26 , V_10 -> V_26 ,
sizeof( V_10 -> V_23 ) , V_10 -> V_24 ) ;
V_7 = F_23 ( & V_10 -> V_3 ) ;
if ( V_7 == - V_11 || V_7 == - V_34 ) {
V_7 = F_24 (
& V_10 -> V_9 . V_12 ) ;
if ( ! V_7 )
V_7 = V_10 -> V_9 . V_7 ;
}
if ( V_7 )
goto V_35;
F_25 ( V_20 , V_28 ) ;
F_26 ( V_20 , F_12 ( V_14 ) &
V_28 ) ;
V_7 = F_27 ( V_20 , ( V_5 * ) & V_10 -> V_23 , sizeof( T_1 ) ) ;
F_14 ( V_14 , F_28 ( V_20 ) &
V_29 ) ;
V_35:
F_29 ( V_10 ) ;
return V_7 ;
}
static int F_30 ( struct V_13 * V_36 ,
unsigned int V_37 )
{
switch ( V_37 ) {
case 4 :
case 8 :
case 12 :
case 13 :
case 14 :
case 15 :
case 16 :
break;
default:
return - V_38 ;
}
return 0 ;
}
static void F_31 ( struct V_2 * V_3 )
{
struct V_1 * V_39 = F_1 ( V_3 ) ;
T_2 V_40 = F_32 ( 1 ) ;
struct V_25 * V_26 ;
memset ( V_39 -> V_41 , 0 , sizeof( V_39 -> V_41 ) ) ;
memcpy ( V_39 -> V_24 , V_3 -> V_24 , 12 ) ;
memcpy ( V_39 -> V_24 + 12 , & V_40 , 4 ) ;
F_33 ( V_39 -> V_42 , 3 ) ;
F_34 ( V_39 -> V_42 , V_39 -> V_41 , sizeof( V_39 -> V_41 ) ) ;
V_26 = F_35 ( V_39 -> V_42 + 1 , V_3 -> V_42 , V_3 -> V_43 ) ;
if ( V_26 != V_39 -> V_42 + 1 )
F_36 ( V_39 -> V_42 , 2 , V_26 ) ;
if ( V_3 -> V_42 != V_3 -> V_44 ) {
F_33 ( V_39 -> V_44 , 3 ) ;
F_34 ( V_39 -> V_44 , V_39 -> V_41 , sizeof( V_39 -> V_41 ) ) ;
V_26 = F_35 ( V_39 -> V_44 + 1 , V_3 -> V_44 , V_3 -> V_43 ) ;
if ( V_26 != V_39 -> V_44 + 1 )
F_36 ( V_39 -> V_44 , 2 , V_26 ) ;
}
}
static void F_37 ( struct V_2 * V_3 ,
unsigned int V_45 )
{
struct V_13 * V_14 = F_3 ( V_3 ) ;
struct V_17 * V_18 = F_9 ( V_14 ) ;
struct V_1 * V_39 = F_1 ( V_3 ) ;
struct V_27 * V_46 = & V_39 -> V_47 . V_48 ;
struct V_25 * V_44 ;
V_44 = V_3 -> V_42 == V_3 -> V_44 ? V_39 -> V_42 : V_39 -> V_44 ;
F_20 ( V_46 , V_18 -> V_22 ) ;
F_22 ( V_46 , V_39 -> V_42 , V_44 ,
V_45 + sizeof( V_39 -> V_41 ) ,
V_39 -> V_24 ) ;
}
static inline unsigned int F_38 ( unsigned int V_49 )
{
V_49 &= 0xfU ;
return V_49 ? 16 - V_49 : 0 ;
}
static int F_39 ( struct V_2 * V_3 ,
T_3 V_50 ,
struct V_25 * V_42 ,
unsigned int V_49 , T_4 V_51 )
{
struct V_1 * V_39 = F_1 ( V_3 ) ;
struct V_52 * V_53 = & V_39 -> V_47 . V_53 ;
F_40 ( V_53 , V_51 , V_50 , V_3 ) ;
F_41 ( V_53 , V_42 , NULL , V_49 ) ;
return F_42 ( V_53 ) ;
}
static int F_43 ( struct V_2 * V_3 ,
unsigned int V_54 ,
T_3 V_50 , T_4 V_51 )
{
return F_39 ( V_3 , V_50 , & V_55 -> V_26 , V_54 , V_51 ) ;
}
static int F_44 ( struct V_2 * V_3 , T_4 V_51 )
{
struct V_1 * V_39 = F_1 ( V_3 ) ;
struct V_52 * V_53 = & V_39 -> V_47 . V_53 ;
struct V_56 * V_57 = & V_39 -> V_58 ;
T_5 V_59 ;
V_59 . V_60 = F_45 ( V_3 -> V_43 * 8 ) ;
V_59 . V_61 = F_45 ( V_57 -> V_45 * 8 ) ;
memcpy ( V_39 -> V_62 , & V_59 , 16 ) ;
F_19 ( & V_39 -> V_26 , V_39 -> V_62 , 16 ) ;
F_40 ( V_53 , V_51 , V_63 , V_3 ) ;
F_41 ( V_53 , & V_39 -> V_26 ,
V_39 -> V_62 , sizeof( V_59 ) ) ;
return F_46 ( V_53 ) ;
}
static int F_47 ( struct V_2 * V_3 , T_4 V_51 )
{
struct V_1 * V_39 = F_1 ( V_3 ) ;
struct V_56 * V_57 = & V_39 -> V_58 ;
return V_57 -> F_7 ( V_3 , V_51 ) ;
}
static void V_63 ( struct V_6 * V_64 , int V_7 )
{
struct V_2 * V_3 = V_64 -> V_10 ;
if ( V_7 )
goto V_35;
V_7 = F_47 ( V_3 , 0 ) ;
if ( V_7 == - V_11 )
return;
V_35:
F_48 ( V_3 , V_7 ) ;
}
static int F_49 ( struct V_2 * V_3 , T_4 V_51 )
{
return F_44 ( V_3 , V_51 ) ? :
F_47 ( V_3 , V_51 ) ;
}
static void F_50 ( struct V_6 * V_64 ,
int V_7 )
{
struct V_2 * V_3 = V_64 -> V_10 ;
if ( V_7 )
goto V_35;
V_7 = F_49 ( V_3 , 0 ) ;
if ( V_7 == - V_11 )
return;
V_35:
F_48 ( V_3 , V_7 ) ;
}
static int F_51 ( struct V_2 * V_3 , T_4 V_51 )
{
struct V_1 * V_39 = F_1 ( V_3 ) ;
struct V_56 * V_57 = & V_39 -> V_58 ;
unsigned int V_54 ;
V_54 = F_38 ( V_57 -> V_45 ) ;
if ( V_54 )
return F_43 ( V_3 , V_54 ,
F_50 , V_51 ) ? :
F_49 ( V_3 , V_51 ) ;
return F_49 ( V_3 , V_51 ) ;
}
static void F_52 ( struct V_6 * V_64 , int V_7 )
{
struct V_2 * V_3 = V_64 -> V_10 ;
if ( V_7 )
goto V_35;
V_7 = F_51 ( V_3 , 0 ) ;
if ( V_7 == - V_11 )
return;
V_35:
F_48 ( V_3 , V_7 ) ;
}
static int F_53 ( struct V_2 * V_3 , T_4 V_51 )
{
struct V_1 * V_39 = F_1 ( V_3 ) ;
struct V_56 * V_57 = & V_39 -> V_58 ;
if ( V_57 -> V_45 )
return F_39 ( V_3 , F_52 ,
V_57 -> V_42 , V_57 -> V_45 , V_51 ) ? :
F_51 ( V_3 , V_51 ) ;
return F_49 ( V_3 , V_51 ) ;
}
static void F_54 ( struct V_6 * V_64 ,
int V_7 )
{
struct V_2 * V_3 = V_64 -> V_10 ;
if ( V_7 )
goto V_35;
V_7 = F_53 ( V_3 , 0 ) ;
if ( V_7 == - V_11 )
return;
V_35:
F_48 ( V_3 , V_7 ) ;
}
static int F_55 ( struct V_2 * V_3 , T_4 V_51 )
{
unsigned int V_54 ;
V_54 = F_38 ( V_3 -> V_43 ) ;
if ( V_54 )
return F_43 ( V_3 , V_54 ,
F_54 , V_51 ) ? :
F_53 ( V_3 , V_51 ) ;
return F_53 ( V_3 , V_51 ) ;
}
static void F_56 ( struct V_6 * V_64 , int V_7 )
{
struct V_2 * V_3 = V_64 -> V_10 ;
if ( V_7 )
goto V_35;
V_7 = F_55 ( V_3 , 0 ) ;
if ( V_7 == - V_11 )
return;
V_35:
F_48 ( V_3 , V_7 ) ;
}
static int F_57 ( struct V_2 * V_3 , T_4 V_51 )
{
if ( V_3 -> V_43 )
return F_39 ( V_3 , F_56 ,
V_3 -> V_42 , V_3 -> V_43 , V_51 ) ? :
F_55 ( V_3 , V_51 ) ;
return F_53 ( V_3 , V_51 ) ;
}
static void F_58 ( struct V_6 * V_64 , int V_7 )
{
struct V_2 * V_3 = V_64 -> V_10 ;
if ( V_7 )
goto V_35;
V_7 = F_57 ( V_3 , 0 ) ;
if ( V_7 == - V_11 )
return;
V_35:
F_48 ( V_3 , V_7 ) ;
}
static int F_59 ( struct V_2 * V_3 , T_4 V_51 )
{
struct V_1 * V_39 = F_1 ( V_3 ) ;
struct V_52 * V_53 = & V_39 -> V_47 . V_53 ;
struct V_17 * V_18 = F_9 ( F_3 ( V_3 ) ) ;
F_60 ( V_53 , V_18 -> V_20 ) ;
F_40 ( V_53 , V_51 , F_58 , V_3 ) ;
return F_61 ( V_53 ) ? :
F_57 ( V_3 , V_51 ) ;
}
static int F_62 ( struct V_2 * V_3 , T_4 V_51 )
{
struct V_1 * V_39 = F_1 ( V_3 ) ;
struct V_13 * V_14 = F_3 ( V_3 ) ;
V_5 * V_41 = V_39 -> V_41 ;
F_63 ( V_41 , V_39 -> V_62 , 16 ) ;
F_64 ( V_41 , V_3 -> V_44 ,
V_3 -> V_43 + V_3 -> V_45 ,
F_65 ( V_14 ) , 1 ) ;
return 0 ;
}
static int F_66 ( struct V_2 * V_3 , T_4 V_51 )
{
struct V_1 * V_39 = F_1 ( V_3 ) ;
struct V_56 * V_57 = & V_39 -> V_58 ;
V_57 -> V_42 = F_67 ( V_3 -> V_42 == V_3 -> V_44 ? V_39 -> V_42 : V_39 -> V_44 ) ;
V_57 -> V_45 = V_3 -> V_45 ;
V_57 -> F_7 = F_62 ;
return F_59 ( V_3 , V_51 ) ;
}
static void F_68 ( struct V_6 * V_64 , int V_7 )
{
struct V_2 * V_3 = V_64 -> V_10 ;
if ( V_7 )
goto V_35;
V_7 = F_66 ( V_3 , 0 ) ;
if ( V_7 == - V_11 )
return;
V_35:
F_48 ( V_3 , V_7 ) ;
}
static int F_69 ( struct V_2 * V_3 )
{
struct V_1 * V_39 = F_1 ( V_3 ) ;
struct V_27 * V_48 = & V_39 -> V_47 . V_48 ;
T_4 V_51 = F_70 ( V_3 ) ;
F_31 ( V_3 ) ;
F_37 ( V_3 , V_3 -> V_45 ) ;
F_21 ( V_48 , V_51 , F_68 , V_3 ) ;
return F_23 ( V_48 ) ? :
F_66 ( V_3 , V_51 ) ;
}
static int F_71 ( struct V_2 * V_3 )
{
struct V_1 * V_39 = F_1 ( V_3 ) ;
struct V_13 * V_14 = F_3 ( V_3 ) ;
V_5 * V_41 = V_39 -> V_41 ;
V_5 * V_62 = V_39 -> V_62 ;
unsigned int V_37 = F_65 ( V_14 ) ;
unsigned int V_45 = V_3 -> V_45 - V_37 ;
F_63 ( V_41 , V_62 , 16 ) ;
F_64 ( V_62 , V_3 -> V_42 ,
V_3 -> V_43 + V_45 , V_37 , 0 ) ;
return F_72 ( V_62 , V_41 , V_37 ) ? - V_65 : 0 ;
}
static void F_73 ( struct V_6 * V_64 , int V_7 )
{
struct V_2 * V_3 = V_64 -> V_10 ;
if ( ! V_7 )
V_7 = F_71 ( V_3 ) ;
F_48 ( V_3 , V_7 ) ;
}
static int F_74 ( struct V_2 * V_3 , T_4 V_51 )
{
struct V_1 * V_39 = F_1 ( V_3 ) ;
struct V_27 * V_48 = & V_39 -> V_47 . V_48 ;
struct V_56 * V_57 = & V_39 -> V_58 ;
F_37 ( V_3 , V_57 -> V_45 ) ;
F_21 ( V_48 , V_51 , F_73 , V_3 ) ;
return F_75 ( V_48 ) ? : F_71 ( V_3 ) ;
}
static int F_76 ( struct V_2 * V_3 )
{
struct V_13 * V_14 = F_3 ( V_3 ) ;
struct V_1 * V_39 = F_1 ( V_3 ) ;
struct V_56 * V_57 = & V_39 -> V_58 ;
unsigned int V_37 = F_65 ( V_14 ) ;
unsigned int V_45 = V_3 -> V_45 ;
T_4 V_51 = F_70 ( V_3 ) ;
V_45 -= V_37 ;
F_31 ( V_3 ) ;
V_57 -> V_42 = F_67 ( V_39 -> V_42 ) ;
V_57 -> V_45 = V_45 ;
V_57 -> F_7 = F_74 ;
return F_59 ( V_3 , V_51 ) ;
}
static int F_77 ( struct V_13 * V_36 )
{
struct V_66 * V_67 = F_78 ( V_36 ) ;
struct V_68 * V_69 = F_79 ( V_67 ) ;
struct V_17 * V_18 = F_9 ( V_36 ) ;
struct V_21 * V_22 ;
struct V_19 * V_20 ;
unsigned long V_4 ;
int V_7 ;
V_20 = F_80 ( & V_69 -> V_20 ) ;
if ( F_81 ( V_20 ) )
return F_82 ( V_20 ) ;
V_22 = F_83 ( & V_69 -> V_22 ) ;
V_7 = F_82 ( V_22 ) ;
if ( F_81 ( V_22 ) )
goto V_70;
V_18 -> V_22 = V_22 ;
V_18 -> V_20 = V_20 ;
V_4 = F_2 ( V_36 ) ;
V_4 &= ~ ( F_84 () - 1 ) ;
F_85 ( V_36 ,
V_4 + F_86 ( struct V_1 , V_47 ) +
F_87 ( sizeof( struct V_27 ) +
F_17 ( V_22 ) ,
sizeof( struct V_52 ) +
F_88 ( V_20 ) ) ) ;
return 0 ;
V_70:
F_89 ( V_20 ) ;
return V_7 ;
}
static void F_90 ( struct V_13 * V_36 )
{
struct V_17 * V_18 = F_9 ( V_36 ) ;
F_89 ( V_18 -> V_20 ) ;
F_91 ( V_18 -> V_22 ) ;
}
static int F_92 ( struct V_71 * V_72 ,
struct V_73 * * V_74 ,
const char * V_75 ,
const char * V_76 ,
const char * V_77 )
{
struct V_78 * V_79 ;
struct V_66 * V_67 ;
struct V_80 * V_22 ;
struct V_80 * V_81 ;
struct V_82 * V_20 ;
struct V_68 * V_18 ;
int V_7 ;
V_79 = F_93 ( V_74 ) ;
if ( F_81 ( V_79 ) )
return F_82 ( V_79 ) ;
if ( ( V_79 -> type ^ V_83 ) & V_79 -> V_84 )
return - V_38 ;
V_81 = F_94 ( V_77 , & V_85 ,
V_86 ,
V_87 ) ;
if ( F_81 ( V_81 ) )
return F_82 ( V_81 ) ;
V_20 = F_95 ( V_81 ) ;
V_7 = - V_31 ;
V_67 = F_16 ( sizeof( * V_67 ) + sizeof( * V_18 ) , V_30 ) ;
if ( ! V_67 )
goto V_88;
V_18 = F_79 ( V_67 ) ;
V_7 = F_96 ( & V_18 -> V_20 , V_20 ,
F_97 ( V_67 ) ) ;
if ( V_7 )
goto V_89;
V_7 = - V_38 ;
if ( V_20 -> V_90 != 16 )
goto V_91;
F_98 ( & V_18 -> V_22 , F_97 ( V_67 ) ) ;
V_7 = F_99 ( & V_18 -> V_22 , V_76 , 0 ,
F_100 ( V_79 -> type ,
V_79 -> V_84 ) ) ;
if ( V_7 )
goto V_91;
V_22 = F_101 ( & V_18 -> V_22 ) ;
if ( V_22 -> V_92 . V_93 != 16 )
goto V_94;
V_7 = - V_38 ;
if ( V_22 -> V_95 != 1 )
goto V_94;
V_7 = - V_96 ;
if ( snprintf ( V_67 -> V_97 . V_98 . V_99 , V_100 ,
L_1 , V_22 -> V_99 ,
V_81 -> V_99 ) >=
V_100 )
goto V_94;
memcpy ( V_67 -> V_97 . V_98 . V_101 , V_75 , V_100 ) ;
V_67 -> V_97 . V_98 . V_102 = ( V_20 -> V_98 . V_102 | V_22 -> V_102 ) &
V_103 ;
V_67 -> V_97 . V_98 . V_104 = ( V_20 -> V_98 . V_104 +
V_22 -> V_104 ) / 2 ;
V_67 -> V_97 . V_98 . V_95 = 1 ;
V_67 -> V_97 . V_98 . V_105 = V_20 -> V_98 . V_105 |
V_22 -> V_105 ;
V_67 -> V_97 . V_98 . V_106 = sizeof( struct V_17 ) ;
V_67 -> V_97 . V_93 = 12 ;
V_67 -> V_97 . V_107 = 16 ;
V_67 -> V_97 . V_108 = F_77 ;
V_67 -> V_97 . exit = F_90 ;
V_67 -> V_97 . V_109 = F_8 ;
V_67 -> V_97 . V_110 = F_30 ;
V_67 -> V_97 . V_111 = F_69 ;
V_67 -> V_97 . V_112 = F_76 ;
V_7 = F_102 ( V_72 , V_67 ) ;
if ( V_7 )
goto V_94;
V_88:
F_103 ( V_81 ) ;
return V_7 ;
V_94:
F_104 ( & V_18 -> V_22 ) ;
V_91:
F_105 ( & V_18 -> V_20 ) ;
V_89:
F_106 ( V_67 ) ;
goto V_88;
}
static int F_107 ( struct V_71 * V_72 , struct V_73 * * V_74 )
{
const char * V_113 ;
char V_76 [ V_100 ] ;
char V_75 [ V_100 ] ;
V_113 = F_108 ( V_74 [ 1 ] ) ;
if ( F_81 ( V_113 ) )
return F_82 ( V_113 ) ;
if ( snprintf ( V_76 , V_100 , L_2 , V_113 ) >=
V_100 )
return - V_96 ;
if ( snprintf ( V_75 , V_100 , L_3 , V_113 ) >=
V_100 )
return - V_96 ;
return F_92 ( V_72 , V_74 , V_75 ,
V_76 , L_4 ) ;
}
static void F_109 ( struct V_114 * V_67 )
{
struct V_68 * V_18 = F_110 ( V_67 ) ;
F_104 ( & V_18 -> V_22 ) ;
F_105 ( & V_18 -> V_20 ) ;
F_106 ( V_66 ( V_67 ) ) ;
}
static int F_111 ( struct V_71 * V_72 ,
struct V_73 * * V_74 )
{
const char * V_76 ;
const char * V_77 ;
char V_75 [ V_100 ] ;
V_76 = F_108 ( V_74 [ 1 ] ) ;
if ( F_81 ( V_76 ) )
return F_82 ( V_76 ) ;
V_77 = F_108 ( V_74 [ 2 ] ) ;
if ( F_81 ( V_77 ) )
return F_82 ( V_77 ) ;
if ( snprintf ( V_75 , V_100 , L_1 ,
V_76 , V_77 ) >= V_100 )
return - V_96 ;
return F_92 ( V_72 , V_74 , V_75 ,
V_76 , V_77 ) ;
}
static int F_112 ( struct V_13 * V_115 , const V_5 * V_15 ,
unsigned int V_16 )
{
struct V_116 * V_18 = F_9 ( V_115 ) ;
struct V_13 * V_117 = V_18 -> V_117 ;
int V_7 ;
if ( V_16 < 4 )
return - V_38 ;
V_16 -= 4 ;
memcpy ( V_18 -> V_118 , V_15 + V_16 , 4 ) ;
F_113 ( V_117 , V_28 ) ;
F_14 ( V_117 , F_12 ( V_115 ) &
V_28 ) ;
V_7 = F_114 ( V_117 , V_15 , V_16 ) ;
F_14 ( V_115 , F_12 ( V_117 ) &
V_29 ) ;
return V_7 ;
}
static int F_115 ( struct V_13 * V_115 ,
unsigned int V_37 )
{
struct V_116 * V_18 = F_9 ( V_115 ) ;
switch ( V_37 ) {
case 8 :
case 12 :
case 16 :
break;
default:
return - V_38 ;
}
return F_116 ( V_18 -> V_117 , V_37 ) ;
}
static struct V_2 * F_117 ( struct V_2 * V_3 )
{
struct V_2 * V_119 = F_5 ( V_3 ) ;
struct V_13 * V_14 = F_3 ( V_3 ) ;
struct V_116 * V_18 = F_9 ( V_14 ) ;
struct V_13 * V_117 = V_18 -> V_117 ;
V_5 * V_24 = F_4 ( ( V_5 * ) ( V_119 + 1 ) + F_118 ( V_117 ) ,
F_2 ( V_117 ) + 1 ) ;
memcpy ( V_24 , V_18 -> V_118 , 4 ) ;
memcpy ( V_24 + 4 , V_3 -> V_24 , 8 ) ;
F_119 ( V_119 , V_117 ) ;
F_120 ( V_119 , V_3 -> V_98 . V_51 , V_3 -> V_98 . F_7 ,
V_3 -> V_98 . V_10 ) ;
F_121 ( V_119 , V_3 -> V_42 , V_3 -> V_44 , V_3 -> V_45 , V_24 ) ;
F_122 ( V_119 , V_3 -> V_43 ) ;
return V_119 ;
}
static int F_123 ( struct V_2 * V_3 )
{
V_3 = F_117 ( V_3 ) ;
return F_124 ( V_3 ) ;
}
static int F_125 ( struct V_2 * V_3 )
{
V_3 = F_117 ( V_3 ) ;
return F_126 ( V_3 ) ;
}
static int F_127 ( struct V_13 * V_36 )
{
struct V_66 * V_67 = F_78 ( V_36 ) ;
struct V_120 * V_121 = F_79 ( V_67 ) ;
struct V_116 * V_18 = F_9 ( V_36 ) ;
struct V_13 * V_14 ;
unsigned long V_4 ;
V_14 = F_128 ( V_121 ) ;
if ( F_81 ( V_14 ) )
return F_82 ( V_14 ) ;
V_18 -> V_117 = V_14 ;
V_4 = F_2 ( V_14 ) ;
V_4 &= ~ ( F_84 () - 1 ) ;
F_85 (
V_36 ,
sizeof( struct V_2 ) +
F_129 ( F_118 ( V_14 ) , F_84 () ) +
V_4 + 12 ) ;
return 0 ;
}
static void F_130 ( struct V_13 * V_36 )
{
struct V_116 * V_18 = F_9 ( V_36 ) ;
F_131 ( V_18 -> V_117 ) ;
}
static int F_132 ( struct V_71 * V_72 ,
struct V_73 * * V_74 )
{
struct V_78 * V_79 ;
struct V_66 * V_67 ;
struct V_120 * V_121 ;
struct V_122 * V_97 ;
const char * V_123 ;
int V_7 ;
V_79 = F_93 ( V_74 ) ;
if ( F_81 ( V_79 ) )
return F_82 ( V_79 ) ;
if ( ( V_79 -> type ^ V_83 ) & V_79 -> V_84 )
return - V_38 ;
V_123 = F_108 ( V_74 [ 1 ] ) ;
if ( F_81 ( V_123 ) )
return F_82 ( V_123 ) ;
V_67 = F_16 ( sizeof( * V_67 ) + sizeof( * V_121 ) , V_30 ) ;
if ( ! V_67 )
return - V_31 ;
V_121 = F_79 ( V_67 ) ;
F_133 ( V_121 , F_97 ( V_67 ) ) ;
V_7 = F_134 ( V_121 , V_123 , 0 ,
F_100 ( V_79 -> type , V_79 -> V_84 ) ) ;
if ( V_7 )
goto V_124;
V_97 = F_135 ( V_121 ) ;
V_7 = - V_38 ;
if ( F_136 ( V_97 ) != 12 )
goto V_125;
if ( V_97 -> V_98 . V_95 != 1 )
goto V_125;
V_7 = - V_96 ;
if ( snprintf ( V_67 -> V_97 . V_98 . V_101 , V_100 ,
L_5 , V_97 -> V_98 . V_101 ) >=
V_100 ||
snprintf ( V_67 -> V_97 . V_98 . V_99 , V_100 ,
L_5 , V_97 -> V_98 . V_99 ) >=
V_100 )
goto V_125;
V_67 -> V_97 . V_98 . V_102 |= V_97 -> V_98 . V_102 & V_103 ;
V_67 -> V_97 . V_98 . V_104 = V_97 -> V_98 . V_104 ;
V_67 -> V_97 . V_98 . V_95 = 1 ;
V_67 -> V_97 . V_98 . V_105 = V_97 -> V_98 . V_105 ;
V_67 -> V_97 . V_98 . V_106 = sizeof( struct V_116 ) ;
V_67 -> V_97 . V_93 = 8 ;
V_67 -> V_97 . V_107 = F_137 ( V_97 ) ;
V_67 -> V_97 . V_108 = F_127 ;
V_67 -> V_97 . exit = F_130 ;
V_67 -> V_97 . V_109 = F_112 ;
V_67 -> V_97 . V_110 = F_115 ;
V_67 -> V_97 . V_111 = F_123 ;
V_67 -> V_97 . V_112 = F_125 ;
V_7 = F_102 ( V_72 , V_67 ) ;
if ( V_7 )
goto V_125;
V_35:
return V_7 ;
V_125:
F_138 ( V_121 ) ;
V_124:
F_106 ( V_67 ) ;
goto V_35;
}
static void F_139 ( struct V_114 * V_67 )
{
F_138 ( F_110 ( V_67 ) ) ;
F_106 ( V_66 ( V_67 ) ) ;
}
static int F_140 ( struct V_13 * V_115 , const V_5 * V_15 ,
unsigned int V_16 )
{
struct V_126 * V_18 = F_9 ( V_115 ) ;
struct V_13 * V_117 = V_18 -> V_117 ;
int V_7 ;
if ( V_16 < 4 )
return - V_38 ;
V_16 -= 4 ;
memcpy ( V_18 -> V_118 , V_15 + V_16 , 4 ) ;
F_113 ( V_117 , V_28 ) ;
F_14 ( V_117 , F_12 ( V_115 ) &
V_28 ) ;
V_7 = F_114 ( V_117 , V_15 , V_16 ) ;
F_14 ( V_115 , F_12 ( V_117 ) &
V_29 ) ;
return V_7 ;
}
static int F_141 ( struct V_13 * V_115 ,
unsigned int V_37 )
{
struct V_126 * V_18 = F_9 ( V_115 ) ;
if ( V_37 != 16 )
return - V_38 ;
return F_116 ( V_18 -> V_117 , V_37 ) ;
}
static int F_142 ( struct V_2 * V_3 , bool V_127 )
{
struct V_13 * V_14 = F_3 ( V_3 ) ;
struct V_126 * V_18 = F_9 ( V_14 ) ;
struct V_128 * V_129 = F_5 ( V_3 ) ;
struct V_2 * V_119 = & V_129 -> V_119 ;
unsigned int V_37 = F_65 ( V_14 ) ;
V_5 * V_24 = F_4 ( ( V_5 * ) ( V_129 + 1 ) + F_118 ( V_18 -> V_117 ) ,
F_2 ( V_18 -> V_117 ) + 1 ) ;
int V_7 ;
if ( V_3 -> V_42 != V_3 -> V_44 ) {
V_7 = F_143 ( V_3 , V_127 ) ;
if ( V_7 )
return V_7 ;
}
memcpy ( V_24 , V_18 -> V_118 , 4 ) ;
memcpy ( V_24 + 4 , V_3 -> V_24 , 8 ) ;
F_119 ( V_119 , V_18 -> V_117 ) ;
F_120 ( V_119 , V_3 -> V_98 . V_51 ,
V_3 -> V_98 . F_7 , V_3 -> V_98 . V_10 ) ;
F_121 ( V_119 , V_3 -> V_42 , V_3 -> V_44 ,
V_127 ? 0 : V_37 , V_24 ) ;
F_122 ( V_119 , V_3 -> V_43 + V_3 -> V_45 -
V_119 -> V_45 ) ;
return V_127 ? F_124 ( V_119 ) : F_126 ( V_119 ) ;
}
static int F_143 ( struct V_2 * V_3 , bool V_127 )
{
struct V_13 * V_14 = F_3 ( V_3 ) ;
struct V_126 * V_18 = F_9 ( V_14 ) ;
unsigned int V_37 = F_65 ( V_14 ) ;
unsigned int V_130 = V_3 -> V_43 + V_3 -> V_45 -
( V_127 ? 0 : V_37 ) ;
struct V_131 V_132 = {
. V_36 = V_18 -> null ,
} ;
return F_144 ( & V_132 , V_3 -> V_44 , V_3 -> V_42 , V_130 ) ;
}
static int F_145 ( struct V_2 * V_3 )
{
return F_142 ( V_3 , true ) ;
}
static int F_146 ( struct V_2 * V_3 )
{
return F_142 ( V_3 , false ) ;
}
static int F_147 ( struct V_13 * V_36 )
{
struct V_66 * V_67 = F_78 ( V_36 ) ;
struct V_133 * V_69 = F_79 ( V_67 ) ;
struct V_120 * V_121 = & V_69 -> V_14 ;
struct V_126 * V_18 = F_9 ( V_36 ) ;
struct V_13 * V_14 ;
struct V_134 * null ;
unsigned long V_4 ;
int V_7 = 0 ;
V_14 = F_128 ( V_121 ) ;
if ( F_81 ( V_14 ) )
return F_82 ( V_14 ) ;
null = F_148 () ;
V_7 = F_82 ( null ) ;
if ( F_81 ( null ) )
goto V_135;
V_18 -> V_117 = V_14 ;
V_18 -> null = null ;
V_4 = F_2 ( V_14 ) ;
V_4 &= ~ ( F_84 () - 1 ) ;
F_85 (
V_36 ,
sizeof( struct V_128 ) +
F_129 ( F_118 ( V_14 ) , F_84 () ) +
V_4 + 12 ) ;
return 0 ;
V_135:
F_131 ( V_14 ) ;
return V_7 ;
}
static void F_149 ( struct V_13 * V_36 )
{
struct V_126 * V_18 = F_9 ( V_36 ) ;
F_131 ( V_18 -> V_117 ) ;
F_150 () ;
}
static int F_151 ( struct V_71 * V_72 ,
struct V_73 * * V_74 )
{
struct V_78 * V_79 ;
struct V_66 * V_67 ;
struct V_120 * V_121 ;
struct V_122 * V_97 ;
struct V_133 * V_18 ;
const char * V_123 ;
int V_7 ;
V_79 = F_93 ( V_74 ) ;
if ( F_81 ( V_79 ) )
return F_82 ( V_79 ) ;
if ( ( V_79 -> type ^ V_83 ) & V_79 -> V_84 )
return - V_38 ;
V_123 = F_108 ( V_74 [ 1 ] ) ;
if ( F_81 ( V_123 ) )
return F_82 ( V_123 ) ;
V_67 = F_16 ( sizeof( * V_67 ) + sizeof( * V_18 ) , V_30 ) ;
if ( ! V_67 )
return - V_31 ;
V_18 = F_79 ( V_67 ) ;
V_121 = & V_18 -> V_14 ;
F_133 ( V_121 , F_97 ( V_67 ) ) ;
V_7 = F_134 ( V_121 , V_123 , 0 ,
F_100 ( V_79 -> type , V_79 -> V_84 ) ) ;
if ( V_7 )
goto V_124;
V_97 = F_135 ( V_121 ) ;
V_7 = - V_38 ;
if ( F_136 ( V_97 ) != 12 )
goto V_125;
if ( V_97 -> V_98 . V_95 != 1 )
goto V_125;
V_7 = - V_96 ;
if ( snprintf ( V_67 -> V_97 . V_98 . V_101 , V_100 ,
L_6 , V_97 -> V_98 . V_101 ) >=
V_100 ||
snprintf ( V_67 -> V_97 . V_98 . V_99 , V_100 ,
L_6 , V_97 -> V_98 . V_99 ) >=
V_100 )
goto V_125;
V_67 -> V_97 . V_98 . V_102 = V_97 -> V_98 . V_102 & V_103 ;
V_67 -> V_97 . V_98 . V_104 = V_97 -> V_98 . V_104 ;
V_67 -> V_97 . V_98 . V_95 = 1 ;
V_67 -> V_97 . V_98 . V_105 = V_97 -> V_98 . V_105 ;
V_67 -> V_97 . V_98 . V_106 = sizeof( struct V_126 ) ;
V_67 -> V_97 . V_93 = 8 ;
V_67 -> V_97 . V_107 = F_137 ( V_97 ) ;
V_67 -> V_97 . V_108 = F_147 ;
V_67 -> V_97 . exit = F_149 ;
V_67 -> V_97 . V_109 = F_140 ;
V_67 -> V_97 . V_110 = F_141 ;
V_67 -> V_97 . V_111 = F_145 ;
V_67 -> V_97 . V_112 = F_146 ;
V_7 = F_102 ( V_72 , V_67 ) ;
if ( V_7 )
goto V_125;
V_35:
return V_7 ;
V_125:
F_138 ( V_121 ) ;
V_124:
F_106 ( V_67 ) ;
goto V_35;
}
static void F_152 ( struct V_114 * V_67 )
{
struct V_133 * V_18 = F_110 ( V_67 ) ;
F_138 ( & V_18 -> V_14 ) ;
F_106 ( V_66 ( V_67 ) ) ;
}
static int T_6 F_153 ( void )
{
int V_7 ;
V_55 = F_16 ( sizeof( * V_55 ) , V_30 ) ;
if ( ! V_55 )
return - V_31 ;
F_19 ( & V_55 -> V_26 , V_55 -> V_136 , sizeof( V_55 -> V_136 ) ) ;
V_7 = F_154 ( & V_137 ) ;
if ( V_7 )
goto V_35;
V_7 = F_154 ( & V_138 ) ;
if ( V_7 )
goto V_139;
V_7 = F_154 ( & V_140 ) ;
if ( V_7 )
goto V_141;
V_7 = F_154 ( & V_142 ) ;
if ( V_7 )
goto V_143;
return 0 ;
V_143:
F_155 ( & V_140 ) ;
V_141:
F_155 ( & V_138 ) ;
V_139:
F_155 ( & V_137 ) ;
V_35:
F_106 ( V_55 ) ;
return V_7 ;
}
static void T_7 F_156 ( void )
{
F_106 ( V_55 ) ;
F_155 ( & V_142 ) ;
F_155 ( & V_140 ) ;
F_155 ( & V_138 ) ;
F_155 ( & V_137 ) ;
}
