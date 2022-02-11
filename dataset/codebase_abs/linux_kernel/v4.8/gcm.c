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
struct V_27 * V_46 = & V_39 -> V_47 . V_46 ;
struct V_25 * V_44 ;
V_44 = V_3 -> V_42 == V_3 -> V_44 ? V_39 -> V_42 : V_39 -> V_44 ;
F_20 ( V_46 , V_18 -> V_22 ) ;
F_22 ( V_46 , V_39 -> V_42 , V_44 ,
V_45 + sizeof( V_39 -> V_41 ) ,
V_39 -> V_24 ) ;
}
static inline unsigned int F_38 ( unsigned int V_48 )
{
V_48 &= 0xfU ;
return V_48 ? 16 - V_48 : 0 ;
}
static int F_39 ( struct V_2 * V_3 ,
T_3 V_49 ,
struct V_25 * V_42 ,
unsigned int V_48 , T_4 V_50 )
{
struct V_1 * V_39 = F_1 ( V_3 ) ;
struct V_51 * V_52 = & V_39 -> V_47 . V_52 ;
F_40 ( V_52 , V_50 , V_49 , V_3 ) ;
F_41 ( V_52 , V_42 , NULL , V_48 ) ;
return F_42 ( V_52 ) ;
}
static int F_43 ( struct V_2 * V_3 ,
unsigned int V_53 ,
T_3 V_49 , T_4 V_50 )
{
return F_39 ( V_3 , V_49 , & V_54 -> V_26 , V_53 , V_50 ) ;
}
static int F_44 ( struct V_2 * V_3 , T_4 V_50 )
{
struct V_1 * V_39 = F_1 ( V_3 ) ;
struct V_51 * V_52 = & V_39 -> V_47 . V_52 ;
struct V_55 * V_56 = & V_39 -> V_57 ;
T_5 V_58 ;
V_58 . V_59 = F_45 ( V_3 -> V_43 * 8 ) ;
V_58 . V_60 = F_45 ( V_56 -> V_45 * 8 ) ;
memcpy ( V_39 -> V_61 , & V_58 , 16 ) ;
F_19 ( & V_39 -> V_26 , V_39 -> V_61 , 16 ) ;
F_40 ( V_52 , V_50 , V_62 , V_3 ) ;
F_41 ( V_52 , & V_39 -> V_26 ,
V_39 -> V_61 , sizeof( V_58 ) ) ;
return F_46 ( V_52 ) ;
}
static int F_47 ( struct V_2 * V_3 , T_4 V_50 )
{
struct V_1 * V_39 = F_1 ( V_3 ) ;
struct V_55 * V_56 = & V_39 -> V_57 ;
return V_56 -> F_7 ( V_3 , V_50 ) ;
}
static void V_62 ( struct V_6 * V_63 , int V_7 )
{
struct V_2 * V_3 = V_63 -> V_10 ;
if ( V_7 )
goto V_35;
V_7 = F_47 ( V_3 , 0 ) ;
if ( V_7 == - V_11 )
return;
V_35:
F_48 ( V_3 , V_7 ) ;
}
static int F_49 ( struct V_2 * V_3 , T_4 V_50 )
{
return F_44 ( V_3 , V_50 ) ? :
F_47 ( V_3 , V_50 ) ;
}
static void F_50 ( struct V_6 * V_63 ,
int V_7 )
{
struct V_2 * V_3 = V_63 -> V_10 ;
if ( V_7 )
goto V_35;
V_7 = F_49 ( V_3 , 0 ) ;
if ( V_7 == - V_11 )
return;
V_35:
F_48 ( V_3 , V_7 ) ;
}
static int F_51 ( struct V_2 * V_3 , T_4 V_50 )
{
struct V_1 * V_39 = F_1 ( V_3 ) ;
struct V_55 * V_56 = & V_39 -> V_57 ;
unsigned int V_53 ;
V_53 = F_38 ( V_56 -> V_45 ) ;
if ( V_53 )
return F_43 ( V_3 , V_53 ,
F_50 , V_50 ) ? :
F_49 ( V_3 , V_50 ) ;
return F_49 ( V_3 , V_50 ) ;
}
static void F_52 ( struct V_6 * V_63 , int V_7 )
{
struct V_2 * V_3 = V_63 -> V_10 ;
if ( V_7 )
goto V_35;
V_7 = F_51 ( V_3 , 0 ) ;
if ( V_7 == - V_11 )
return;
V_35:
F_48 ( V_3 , V_7 ) ;
}
static int F_53 ( struct V_2 * V_3 , T_4 V_50 )
{
struct V_1 * V_39 = F_1 ( V_3 ) ;
struct V_55 * V_56 = & V_39 -> V_57 ;
if ( V_56 -> V_45 )
return F_39 ( V_3 , F_52 ,
V_56 -> V_42 , V_56 -> V_45 , V_50 ) ? :
F_51 ( V_3 , V_50 ) ;
return F_49 ( V_3 , V_50 ) ;
}
static void F_54 ( struct V_6 * V_63 ,
int V_7 )
{
struct V_2 * V_3 = V_63 -> V_10 ;
if ( V_7 )
goto V_35;
V_7 = F_53 ( V_3 , 0 ) ;
if ( V_7 == - V_11 )
return;
V_35:
F_48 ( V_3 , V_7 ) ;
}
static int F_55 ( struct V_2 * V_3 , T_4 V_50 )
{
unsigned int V_53 ;
V_53 = F_38 ( V_3 -> V_43 ) ;
if ( V_53 )
return F_43 ( V_3 , V_53 ,
F_54 , V_50 ) ? :
F_53 ( V_3 , V_50 ) ;
return F_53 ( V_3 , V_50 ) ;
}
static void F_56 ( struct V_6 * V_63 , int V_7 )
{
struct V_2 * V_3 = V_63 -> V_10 ;
if ( V_7 )
goto V_35;
V_7 = F_55 ( V_3 , 0 ) ;
if ( V_7 == - V_11 )
return;
V_35:
F_48 ( V_3 , V_7 ) ;
}
static int F_57 ( struct V_2 * V_3 , T_4 V_50 )
{
if ( V_3 -> V_43 )
return F_39 ( V_3 , F_56 ,
V_3 -> V_42 , V_3 -> V_43 , V_50 ) ? :
F_55 ( V_3 , V_50 ) ;
return F_53 ( V_3 , V_50 ) ;
}
static void F_58 ( struct V_6 * V_63 , int V_7 )
{
struct V_2 * V_3 = V_63 -> V_10 ;
if ( V_7 )
goto V_35;
V_7 = F_57 ( V_3 , 0 ) ;
if ( V_7 == - V_11 )
return;
V_35:
F_48 ( V_3 , V_7 ) ;
}
static int F_59 ( struct V_2 * V_3 , T_4 V_50 )
{
struct V_1 * V_39 = F_1 ( V_3 ) ;
struct V_51 * V_52 = & V_39 -> V_47 . V_52 ;
struct V_17 * V_18 = F_9 ( F_3 ( V_3 ) ) ;
F_60 ( V_52 , V_18 -> V_20 ) ;
F_40 ( V_52 , V_50 , F_58 , V_3 ) ;
return F_61 ( V_52 ) ? :
F_57 ( V_3 , V_50 ) ;
}
static int F_62 ( struct V_2 * V_3 , T_4 V_50 )
{
struct V_1 * V_39 = F_1 ( V_3 ) ;
struct V_13 * V_14 = F_3 ( V_3 ) ;
V_5 * V_41 = V_39 -> V_41 ;
F_63 ( V_41 , V_39 -> V_61 , 16 ) ;
F_64 ( V_41 , V_3 -> V_44 ,
V_3 -> V_43 + V_3 -> V_45 ,
F_65 ( V_14 ) , 1 ) ;
return 0 ;
}
static int F_66 ( struct V_2 * V_3 , T_4 V_50 )
{
struct V_1 * V_39 = F_1 ( V_3 ) ;
struct V_55 * V_56 = & V_39 -> V_57 ;
V_56 -> V_42 = F_67 ( V_3 -> V_42 == V_3 -> V_44 ? V_39 -> V_42 : V_39 -> V_44 ) ;
V_56 -> V_45 = V_3 -> V_45 ;
V_56 -> F_7 = F_62 ;
return F_59 ( V_3 , V_50 ) ;
}
static void F_68 ( struct V_6 * V_63 , int V_7 )
{
struct V_2 * V_3 = V_63 -> V_10 ;
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
struct V_27 * V_46 = & V_39 -> V_47 . V_46 ;
T_4 V_50 = F_70 ( V_3 ) ;
F_31 ( V_3 ) ;
F_37 ( V_3 , V_3 -> V_45 ) ;
F_21 ( V_46 , V_50 , F_68 , V_3 ) ;
return F_23 ( V_46 ) ? :
F_66 ( V_3 , V_50 ) ;
}
static int F_71 ( struct V_2 * V_3 )
{
struct V_1 * V_39 = F_1 ( V_3 ) ;
struct V_13 * V_14 = F_3 ( V_3 ) ;
V_5 * V_41 = V_39 -> V_41 ;
V_5 * V_61 = V_39 -> V_61 ;
unsigned int V_37 = F_65 ( V_14 ) ;
unsigned int V_45 = V_3 -> V_45 - V_37 ;
F_63 ( V_41 , V_61 , 16 ) ;
F_64 ( V_61 , V_3 -> V_42 ,
V_3 -> V_43 + V_45 , V_37 , 0 ) ;
return F_72 ( V_61 , V_41 , V_37 ) ? - V_64 : 0 ;
}
static void F_73 ( struct V_6 * V_63 , int V_7 )
{
struct V_2 * V_3 = V_63 -> V_10 ;
if ( ! V_7 )
V_7 = F_71 ( V_3 ) ;
F_48 ( V_3 , V_7 ) ;
}
static int F_74 ( struct V_2 * V_3 , T_4 V_50 )
{
struct V_1 * V_39 = F_1 ( V_3 ) ;
struct V_27 * V_46 = & V_39 -> V_47 . V_46 ;
struct V_55 * V_56 = & V_39 -> V_57 ;
F_37 ( V_3 , V_56 -> V_45 ) ;
F_21 ( V_46 , V_50 , F_73 , V_3 ) ;
return F_75 ( V_46 ) ? : F_71 ( V_3 ) ;
}
static int F_76 ( struct V_2 * V_3 )
{
struct V_13 * V_14 = F_3 ( V_3 ) ;
struct V_1 * V_39 = F_1 ( V_3 ) ;
struct V_55 * V_56 = & V_39 -> V_57 ;
unsigned int V_37 = F_65 ( V_14 ) ;
unsigned int V_45 = V_3 -> V_45 ;
T_4 V_50 = F_70 ( V_3 ) ;
V_45 -= V_37 ;
F_31 ( V_3 ) ;
V_56 -> V_42 = F_67 ( V_39 -> V_42 ) ;
V_56 -> V_45 = V_45 ;
V_56 -> F_7 = F_74 ;
return F_59 ( V_3 , V_50 ) ;
}
static int F_77 ( struct V_13 * V_36 )
{
struct V_65 * V_66 = F_78 ( V_36 ) ;
struct V_67 * V_68 = F_79 ( V_66 ) ;
struct V_17 * V_18 = F_9 ( V_36 ) ;
struct V_21 * V_22 ;
struct V_19 * V_20 ;
unsigned long V_4 ;
int V_7 ;
V_20 = F_80 ( & V_68 -> V_20 ) ;
if ( F_81 ( V_20 ) )
return F_82 ( V_20 ) ;
V_22 = F_83 ( & V_68 -> V_22 ) ;
V_7 = F_82 ( V_22 ) ;
if ( F_81 ( V_22 ) )
goto V_69;
V_18 -> V_22 = V_22 ;
V_18 -> V_20 = V_20 ;
V_4 = F_2 ( V_36 ) ;
V_4 &= ~ ( F_84 () - 1 ) ;
F_85 ( V_36 ,
V_4 + F_86 ( struct V_1 , V_47 ) +
F_87 ( sizeof( struct V_27 ) +
F_17 ( V_22 ) ,
sizeof( struct V_51 ) +
F_88 ( V_20 ) ) ) ;
return 0 ;
V_69:
F_89 ( V_20 ) ;
return V_7 ;
}
static void F_90 ( struct V_13 * V_36 )
{
struct V_17 * V_18 = F_9 ( V_36 ) ;
F_89 ( V_18 -> V_20 ) ;
F_91 ( V_18 -> V_22 ) ;
}
static void F_92 ( struct V_65 * V_66 )
{
struct V_67 * V_18 = F_79 ( V_66 ) ;
F_93 ( & V_18 -> V_22 ) ;
F_94 ( & V_18 -> V_20 ) ;
F_95 ( V_66 ) ;
}
static int F_96 ( struct V_70 * V_71 ,
struct V_72 * * V_73 ,
const char * V_74 ,
const char * V_75 ,
const char * V_76 )
{
struct V_77 * V_78 ;
struct V_65 * V_66 ;
struct V_79 * V_22 ;
struct V_80 * V_81 ;
struct V_82 * V_20 ;
struct V_67 * V_18 ;
int V_7 ;
V_78 = F_97 ( V_73 ) ;
if ( F_81 ( V_78 ) )
return F_82 ( V_78 ) ;
if ( ( V_78 -> type ^ V_83 ) & V_78 -> V_84 )
return - V_38 ;
V_81 = F_98 ( V_76 , & V_85 ,
V_86 ,
V_87 |
F_99 ( V_78 -> type ,
V_78 -> V_84 ) ) ;
if ( F_81 ( V_81 ) )
return F_82 ( V_81 ) ;
V_20 = F_100 ( V_81 ) ;
V_7 = - V_31 ;
V_66 = F_16 ( sizeof( * V_66 ) + sizeof( * V_18 ) , V_30 ) ;
if ( ! V_66 )
goto V_88;
V_18 = F_79 ( V_66 ) ;
V_7 = F_101 ( & V_18 -> V_20 , V_20 ,
F_102 ( V_66 ) ) ;
if ( V_7 )
goto V_89;
V_7 = - V_38 ;
if ( V_20 -> V_90 != 16 )
goto V_91;
F_103 ( & V_18 -> V_22 , F_102 ( V_66 ) ) ;
V_7 = F_104 ( & V_18 -> V_22 , V_75 , 0 ,
F_99 ( V_78 -> type ,
V_78 -> V_84 ) ) ;
if ( V_7 )
goto V_91;
V_22 = F_105 ( & V_18 -> V_22 ) ;
if ( F_106 ( V_22 ) != 16 )
goto V_92;
V_7 = - V_38 ;
if ( V_22 -> V_93 . V_94 != 1 )
goto V_92;
V_7 = - V_95 ;
if ( snprintf ( V_66 -> V_96 . V_93 . V_97 , V_98 ,
L_1 , V_22 -> V_93 . V_97 ,
V_81 -> V_97 ) >=
V_98 )
goto V_92;
memcpy ( V_66 -> V_96 . V_93 . V_99 , V_74 , V_98 ) ;
V_66 -> V_96 . V_93 . V_100 = ( V_20 -> V_93 . V_100 |
V_22 -> V_93 . V_100 ) & V_101 ;
V_66 -> V_96 . V_93 . V_102 = ( V_20 -> V_93 . V_102 +
V_22 -> V_93 . V_102 ) / 2 ;
V_66 -> V_96 . V_93 . V_94 = 1 ;
V_66 -> V_96 . V_93 . V_103 = V_20 -> V_93 . V_103 |
V_22 -> V_93 . V_103 ;
V_66 -> V_96 . V_93 . V_104 = sizeof( struct V_17 ) ;
V_66 -> V_96 . V_105 = 12 ;
V_66 -> V_96 . V_106 = F_107 ( V_22 ) ;
V_66 -> V_96 . V_107 = 16 ;
V_66 -> V_96 . V_108 = F_77 ;
V_66 -> V_96 . exit = F_90 ;
V_66 -> V_96 . V_109 = F_8 ;
V_66 -> V_96 . V_110 = F_30 ;
V_66 -> V_96 . V_111 = F_69 ;
V_66 -> V_96 . V_112 = F_76 ;
V_66 -> free = F_92 ;
V_7 = F_108 ( V_71 , V_66 ) ;
if ( V_7 )
goto V_92;
V_88:
F_109 ( V_81 ) ;
return V_7 ;
V_92:
F_93 ( & V_18 -> V_22 ) ;
V_91:
F_94 ( & V_18 -> V_20 ) ;
V_89:
F_95 ( V_66 ) ;
goto V_88;
}
static int F_110 ( struct V_70 * V_71 , struct V_72 * * V_73 )
{
const char * V_113 ;
char V_75 [ V_98 ] ;
char V_74 [ V_98 ] ;
V_113 = F_111 ( V_73 [ 1 ] ) ;
if ( F_81 ( V_113 ) )
return F_82 ( V_113 ) ;
if ( snprintf ( V_75 , V_98 , L_2 , V_113 ) >=
V_98 )
return - V_95 ;
if ( snprintf ( V_74 , V_98 , L_3 , V_113 ) >=
V_98 )
return - V_95 ;
return F_96 ( V_71 , V_73 , V_74 ,
V_75 , L_4 ) ;
}
static int F_112 ( struct V_70 * V_71 ,
struct V_72 * * V_73 )
{
const char * V_75 ;
const char * V_76 ;
char V_74 [ V_98 ] ;
V_75 = F_111 ( V_73 [ 1 ] ) ;
if ( F_81 ( V_75 ) )
return F_82 ( V_75 ) ;
V_76 = F_111 ( V_73 [ 2 ] ) ;
if ( F_81 ( V_76 ) )
return F_82 ( V_76 ) ;
if ( snprintf ( V_74 , V_98 , L_1 ,
V_75 , V_76 ) >= V_98 )
return - V_95 ;
return F_96 ( V_71 , V_73 , V_74 ,
V_75 , V_76 ) ;
}
static int F_113 ( struct V_13 * V_114 , const V_5 * V_15 ,
unsigned int V_16 )
{
struct V_115 * V_18 = F_9 ( V_114 ) ;
struct V_13 * V_116 = V_18 -> V_116 ;
int V_7 ;
if ( V_16 < 4 )
return - V_38 ;
V_16 -= 4 ;
memcpy ( V_18 -> V_117 , V_15 + V_16 , 4 ) ;
F_114 ( V_116 , V_28 ) ;
F_14 ( V_116 , F_12 ( V_114 ) &
V_28 ) ;
V_7 = F_115 ( V_116 , V_15 , V_16 ) ;
F_14 ( V_114 , F_12 ( V_116 ) &
V_29 ) ;
return V_7 ;
}
static int F_116 ( struct V_13 * V_114 ,
unsigned int V_37 )
{
struct V_115 * V_18 = F_9 ( V_114 ) ;
switch ( V_37 ) {
case 8 :
case 12 :
case 16 :
break;
default:
return - V_38 ;
}
return F_117 ( V_18 -> V_116 , V_37 ) ;
}
static struct V_2 * F_118 ( struct V_2 * V_3 )
{
struct V_118 * V_119 = F_5 ( V_3 ) ;
struct V_13 * V_14 = F_3 ( V_3 ) ;
struct V_115 * V_18 = F_9 ( V_14 ) ;
struct V_2 * V_120 = & V_119 -> V_120 ;
struct V_13 * V_116 = V_18 -> V_116 ;
struct V_25 * V_26 ;
V_5 * V_24 = F_4 ( ( V_5 * ) ( V_120 + 1 ) + F_119 ( V_116 ) ,
F_2 ( V_116 ) + 1 ) ;
F_64 ( V_24 + 12 , V_3 -> V_42 , 0 , V_3 -> V_43 - 8 , 0 ) ;
memcpy ( V_24 , V_18 -> V_117 , 4 ) ;
memcpy ( V_24 + 4 , V_3 -> V_24 , 8 ) ;
F_33 ( V_119 -> V_42 , 3 ) ;
F_34 ( V_119 -> V_42 , V_24 + 12 , V_3 -> V_43 - 8 ) ;
V_26 = F_35 ( V_119 -> V_42 + 1 , V_3 -> V_42 , V_3 -> V_43 ) ;
if ( V_26 != V_119 -> V_42 + 1 )
F_36 ( V_119 -> V_42 , 2 , V_26 ) ;
if ( V_3 -> V_42 != V_3 -> V_44 ) {
F_33 ( V_119 -> V_44 , 3 ) ;
F_34 ( V_119 -> V_44 , V_24 + 12 , V_3 -> V_43 - 8 ) ;
V_26 = F_35 ( V_119 -> V_44 + 1 , V_3 -> V_44 , V_3 -> V_43 ) ;
if ( V_26 != V_119 -> V_44 + 1 )
F_36 ( V_119 -> V_44 , 2 , V_26 ) ;
}
F_120 ( V_120 , V_116 ) ;
F_121 ( V_120 , V_3 -> V_93 . V_50 , V_3 -> V_93 . F_7 ,
V_3 -> V_93 . V_10 ) ;
F_122 ( V_120 , V_119 -> V_42 ,
V_3 -> V_42 == V_3 -> V_44 ? V_119 -> V_42 : V_119 -> V_44 ,
V_3 -> V_45 , V_24 ) ;
F_123 ( V_120 , V_3 -> V_43 - 8 ) ;
return V_120 ;
}
static int F_124 ( struct V_2 * V_3 )
{
if ( V_3 -> V_43 != 16 && V_3 -> V_43 != 20 )
return - V_38 ;
V_3 = F_118 ( V_3 ) ;
return F_125 ( V_3 ) ;
}
static int F_126 ( struct V_2 * V_3 )
{
if ( V_3 -> V_43 != 16 && V_3 -> V_43 != 20 )
return - V_38 ;
V_3 = F_118 ( V_3 ) ;
return F_127 ( V_3 ) ;
}
static int F_128 ( struct V_13 * V_36 )
{
struct V_65 * V_66 = F_78 ( V_36 ) ;
struct V_121 * V_122 = F_79 ( V_66 ) ;
struct V_115 * V_18 = F_9 ( V_36 ) ;
struct V_13 * V_14 ;
unsigned long V_4 ;
V_14 = F_129 ( V_122 ) ;
if ( F_81 ( V_14 ) )
return F_82 ( V_14 ) ;
V_18 -> V_116 = V_14 ;
V_4 = F_2 ( V_14 ) ;
V_4 &= ~ ( F_84 () - 1 ) ;
F_85 (
V_36 ,
sizeof( struct V_118 ) +
F_130 ( F_119 ( V_14 ) , F_84 () ) +
V_4 + 24 ) ;
return 0 ;
}
static void F_131 ( struct V_13 * V_36 )
{
struct V_115 * V_18 = F_9 ( V_36 ) ;
F_132 ( V_18 -> V_116 ) ;
}
static void F_133 ( struct V_65 * V_66 )
{
F_134 ( F_79 ( V_66 ) ) ;
F_95 ( V_66 ) ;
}
static int F_135 ( struct V_70 * V_71 ,
struct V_72 * * V_73 )
{
struct V_77 * V_78 ;
struct V_65 * V_66 ;
struct V_121 * V_122 ;
struct V_123 * V_96 ;
const char * V_124 ;
int V_7 ;
V_78 = F_97 ( V_73 ) ;
if ( F_81 ( V_78 ) )
return F_82 ( V_78 ) ;
if ( ( V_78 -> type ^ V_83 ) & V_78 -> V_84 )
return - V_38 ;
V_124 = F_111 ( V_73 [ 1 ] ) ;
if ( F_81 ( V_124 ) )
return F_82 ( V_124 ) ;
V_66 = F_16 ( sizeof( * V_66 ) + sizeof( * V_122 ) , V_30 ) ;
if ( ! V_66 )
return - V_31 ;
V_122 = F_79 ( V_66 ) ;
F_136 ( V_122 , F_102 ( V_66 ) ) ;
V_7 = F_137 ( V_122 , V_124 , 0 ,
F_99 ( V_78 -> type , V_78 -> V_84 ) ) ;
if ( V_7 )
goto V_125;
V_96 = F_138 ( V_122 ) ;
V_7 = - V_38 ;
if ( F_139 ( V_96 ) != 12 )
goto V_126;
if ( V_96 -> V_93 . V_94 != 1 )
goto V_126;
V_7 = - V_95 ;
if ( snprintf ( V_66 -> V_96 . V_93 . V_99 , V_98 ,
L_5 , V_96 -> V_93 . V_99 ) >=
V_98 ||
snprintf ( V_66 -> V_96 . V_93 . V_97 , V_98 ,
L_5 , V_96 -> V_93 . V_97 ) >=
V_98 )
goto V_126;
V_66 -> V_96 . V_93 . V_100 = V_96 -> V_93 . V_100 & V_101 ;
V_66 -> V_96 . V_93 . V_102 = V_96 -> V_93 . V_102 ;
V_66 -> V_96 . V_93 . V_94 = 1 ;
V_66 -> V_96 . V_93 . V_103 = V_96 -> V_93 . V_103 ;
V_66 -> V_96 . V_93 . V_104 = sizeof( struct V_115 ) ;
V_66 -> V_96 . V_105 = 8 ;
V_66 -> V_96 . V_106 = F_140 ( V_96 ) ;
V_66 -> V_96 . V_107 = F_141 ( V_96 ) ;
V_66 -> V_96 . V_108 = F_128 ;
V_66 -> V_96 . exit = F_131 ;
V_66 -> V_96 . V_109 = F_113 ;
V_66 -> V_96 . V_110 = F_116 ;
V_66 -> V_96 . V_111 = F_124 ;
V_66 -> V_96 . V_112 = F_126 ;
V_66 -> free = F_133 ;
V_7 = F_108 ( V_71 , V_66 ) ;
if ( V_7 )
goto V_126;
V_35:
return V_7 ;
V_126:
F_134 ( V_122 ) ;
V_125:
F_95 ( V_66 ) ;
goto V_35;
}
static int F_142 ( struct V_13 * V_114 , const V_5 * V_15 ,
unsigned int V_16 )
{
struct V_127 * V_18 = F_9 ( V_114 ) ;
struct V_13 * V_116 = V_18 -> V_116 ;
int V_7 ;
if ( V_16 < 4 )
return - V_38 ;
V_16 -= 4 ;
memcpy ( V_18 -> V_117 , V_15 + V_16 , 4 ) ;
F_114 ( V_116 , V_28 ) ;
F_14 ( V_116 , F_12 ( V_114 ) &
V_28 ) ;
V_7 = F_115 ( V_116 , V_15 , V_16 ) ;
F_14 ( V_114 , F_12 ( V_116 ) &
V_29 ) ;
return V_7 ;
}
static int F_143 ( struct V_13 * V_114 ,
unsigned int V_37 )
{
struct V_127 * V_18 = F_9 ( V_114 ) ;
if ( V_37 != 16 )
return - V_38 ;
return F_117 ( V_18 -> V_116 , V_37 ) ;
}
static int F_144 ( struct V_2 * V_3 , bool V_128 )
{
struct V_13 * V_14 = F_3 ( V_3 ) ;
struct V_127 * V_18 = F_9 ( V_14 ) ;
struct V_129 * V_119 = F_5 ( V_3 ) ;
struct V_2 * V_120 = & V_119 -> V_120 ;
unsigned int V_37 = F_65 ( V_14 ) ;
V_5 * V_24 = F_4 ( ( V_5 * ) ( V_119 + 1 ) + F_119 ( V_18 -> V_116 ) ,
F_2 ( V_18 -> V_116 ) + 1 ) ;
int V_7 ;
if ( V_3 -> V_42 != V_3 -> V_44 ) {
V_7 = F_145 ( V_3 , V_128 ) ;
if ( V_7 )
return V_7 ;
}
memcpy ( V_24 , V_18 -> V_117 , 4 ) ;
memcpy ( V_24 + 4 , V_3 -> V_24 , 8 ) ;
F_120 ( V_120 , V_18 -> V_116 ) ;
F_121 ( V_120 , V_3 -> V_93 . V_50 ,
V_3 -> V_93 . F_7 , V_3 -> V_93 . V_10 ) ;
F_122 ( V_120 , V_3 -> V_42 , V_3 -> V_44 ,
V_128 ? 0 : V_37 , V_24 ) ;
F_123 ( V_120 , V_3 -> V_43 + V_3 -> V_45 -
V_120 -> V_45 ) ;
return V_128 ? F_125 ( V_120 ) : F_127 ( V_120 ) ;
}
static int F_145 ( struct V_2 * V_3 , bool V_128 )
{
struct V_13 * V_14 = F_3 ( V_3 ) ;
struct V_127 * V_18 = F_9 ( V_14 ) ;
unsigned int V_37 = F_65 ( V_14 ) ;
unsigned int V_130 = V_3 -> V_43 + V_3 -> V_45 -
( V_128 ? 0 : V_37 ) ;
F_146 ( V_131 , V_18 -> null ) ;
F_20 ( V_131 , V_18 -> null ) ;
F_21 ( V_131 , V_3 -> V_93 . V_50 , NULL , NULL ) ;
F_22 ( V_131 , V_3 -> V_42 , V_3 -> V_44 , V_130 , NULL ) ;
return F_23 ( V_131 ) ;
}
static int F_147 ( struct V_2 * V_3 )
{
return F_144 ( V_3 , true ) ;
}
static int F_148 ( struct V_2 * V_3 )
{
return F_144 ( V_3 , false ) ;
}
static int F_149 ( struct V_13 * V_36 )
{
struct V_65 * V_66 = F_78 ( V_36 ) ;
struct V_132 * V_68 = F_79 ( V_66 ) ;
struct V_121 * V_122 = & V_68 -> V_14 ;
struct V_127 * V_18 = F_9 ( V_36 ) ;
struct V_13 * V_14 ;
struct V_21 * null ;
unsigned long V_4 ;
int V_7 = 0 ;
V_14 = F_129 ( V_122 ) ;
if ( F_81 ( V_14 ) )
return F_82 ( V_14 ) ;
null = F_150 () ;
V_7 = F_82 ( null ) ;
if ( F_81 ( null ) )
goto V_133;
V_18 -> V_116 = V_14 ;
V_18 -> null = null ;
V_4 = F_2 ( V_14 ) ;
V_4 &= ~ ( F_84 () - 1 ) ;
F_85 (
V_36 ,
sizeof( struct V_129 ) +
F_130 ( F_119 ( V_14 ) , F_84 () ) +
V_4 + 12 ) ;
return 0 ;
V_133:
F_132 ( V_14 ) ;
return V_7 ;
}
static void F_151 ( struct V_13 * V_36 )
{
struct V_127 * V_18 = F_9 ( V_36 ) ;
F_132 ( V_18 -> V_116 ) ;
F_152 () ;
}
static void F_153 ( struct V_65 * V_66 )
{
struct V_132 * V_18 = F_79 ( V_66 ) ;
F_134 ( & V_18 -> V_14 ) ;
F_95 ( V_66 ) ;
}
static int F_154 ( struct V_70 * V_71 ,
struct V_72 * * V_73 )
{
struct V_77 * V_78 ;
struct V_65 * V_66 ;
struct V_121 * V_122 ;
struct V_123 * V_96 ;
struct V_132 * V_18 ;
const char * V_124 ;
int V_7 ;
V_78 = F_97 ( V_73 ) ;
if ( F_81 ( V_78 ) )
return F_82 ( V_78 ) ;
if ( ( V_78 -> type ^ V_83 ) & V_78 -> V_84 )
return - V_38 ;
V_124 = F_111 ( V_73 [ 1 ] ) ;
if ( F_81 ( V_124 ) )
return F_82 ( V_124 ) ;
V_66 = F_16 ( sizeof( * V_66 ) + sizeof( * V_18 ) , V_30 ) ;
if ( ! V_66 )
return - V_31 ;
V_18 = F_79 ( V_66 ) ;
V_122 = & V_18 -> V_14 ;
F_136 ( V_122 , F_102 ( V_66 ) ) ;
V_7 = F_137 ( V_122 , V_124 , 0 ,
F_99 ( V_78 -> type , V_78 -> V_84 ) ) ;
if ( V_7 )
goto V_125;
V_96 = F_138 ( V_122 ) ;
V_7 = - V_38 ;
if ( F_139 ( V_96 ) != 12 )
goto V_126;
if ( V_96 -> V_93 . V_94 != 1 )
goto V_126;
V_7 = - V_95 ;
if ( snprintf ( V_66 -> V_96 . V_93 . V_99 , V_98 ,
L_6 , V_96 -> V_93 . V_99 ) >=
V_98 ||
snprintf ( V_66 -> V_96 . V_93 . V_97 , V_98 ,
L_6 , V_96 -> V_93 . V_97 ) >=
V_98 )
goto V_126;
V_66 -> V_96 . V_93 . V_100 = V_96 -> V_93 . V_100 & V_101 ;
V_66 -> V_96 . V_93 . V_102 = V_96 -> V_93 . V_102 ;
V_66 -> V_96 . V_93 . V_94 = 1 ;
V_66 -> V_96 . V_93 . V_103 = V_96 -> V_93 . V_103 ;
V_66 -> V_96 . V_93 . V_104 = sizeof( struct V_127 ) ;
V_66 -> V_96 . V_105 = 8 ;
V_66 -> V_96 . V_106 = F_140 ( V_96 ) ;
V_66 -> V_96 . V_107 = F_141 ( V_96 ) ;
V_66 -> V_96 . V_108 = F_149 ;
V_66 -> V_96 . exit = F_151 ;
V_66 -> V_96 . V_109 = F_142 ;
V_66 -> V_96 . V_110 = F_143 ;
V_66 -> V_96 . V_111 = F_147 ;
V_66 -> V_96 . V_112 = F_148 ;
V_66 -> free = F_153 ,
V_7 = F_108 ( V_71 , V_66 ) ;
if ( V_7 )
goto V_126;
V_35:
return V_7 ;
V_126:
F_134 ( V_122 ) ;
V_125:
F_95 ( V_66 ) ;
goto V_35;
}
static int T_6 F_155 ( void )
{
int V_7 ;
V_54 = F_16 ( sizeof( * V_54 ) , V_30 ) ;
if ( ! V_54 )
return - V_31 ;
F_19 ( & V_54 -> V_26 , V_54 -> V_134 , sizeof( V_54 -> V_134 ) ) ;
V_7 = F_156 ( & V_135 ) ;
if ( V_7 )
goto V_35;
V_7 = F_156 ( & V_136 ) ;
if ( V_7 )
goto V_137;
V_7 = F_156 ( & V_138 ) ;
if ( V_7 )
goto V_139;
V_7 = F_156 ( & V_140 ) ;
if ( V_7 )
goto V_141;
return 0 ;
V_141:
F_157 ( & V_138 ) ;
V_139:
F_157 ( & V_136 ) ;
V_137:
F_157 ( & V_135 ) ;
V_35:
F_95 ( V_54 ) ;
return V_7 ;
}
static void T_7 F_158 ( void )
{
F_95 ( V_54 ) ;
F_157 ( & V_140 ) ;
F_157 ( & V_138 ) ;
F_157 ( & V_136 ) ;
F_157 ( & V_135 ) ;
}
