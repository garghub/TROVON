static int F_1 ( struct V_1 * V_2 , const T_1 * V_3 ,
unsigned int V_4 )
{
unsigned long V_5 = F_2 ( V_2 ) ;
int V_6 ;
T_1 * V_7 , * V_8 ;
unsigned long V_9 ;
V_9 = V_4 + V_5 ;
V_7 = F_3 ( V_9 , V_10 ) ;
if ( ! V_7 )
return - V_11 ;
V_8 = ( T_1 * ) F_4 ( ( unsigned long ) V_7 , V_5 + 1 ) ;
memcpy ( V_8 , V_3 , V_4 ) ;
V_6 = V_2 -> V_12 ( V_2 , V_8 , V_4 ) ;
memset ( V_8 , 0 , V_4 ) ;
F_5 ( V_7 ) ;
return V_6 ;
}
int F_6 ( struct V_1 * V_2 ,
const T_1 * V_3 , unsigned int V_4 )
{
unsigned long V_5 = F_2 ( V_2 ) ;
V_2 = V_2 -> V_13 ;
if ( ( unsigned long ) V_3 & V_5 )
return F_1 ( V_2 , V_3 , V_4 ) ;
return V_2 -> V_12 ( V_2 , V_3 , V_4 ) ;
}
int F_7 ( struct V_1 * V_2 , unsigned int V_14 )
{
int V_15 ;
if ( V_14 > F_8 ( V_2 ) )
return - V_16 ;
if ( V_2 -> V_17 ) {
V_15 = V_2 -> V_17 ( V_2 -> V_13 , V_14 ) ;
if ( V_15 )
return V_15 ;
}
V_2 -> V_13 -> V_14 = V_14 ;
V_2 -> V_14 = V_14 ;
return 0 ;
}
unsigned int F_9 ( struct V_1 * V_2 )
{
return V_2 -> V_18 + sizeof( struct V_19 ) ;
}
static int F_10 ( struct V_20 * V_21 ,
int (* F_11)( struct V_20 * V_21 ) )
{
struct V_19 * V_22 = F_12 ( V_21 ) ;
struct V_1 * V_23 = F_13 ( V_21 ) ;
struct V_24 * V_25 , * V_26 ;
if ( V_21 -> V_27 )
return F_11 ( V_21 ) ;
V_25 = F_14 ( V_22 -> V_28 , V_21 -> V_25 , V_21 -> V_29 ) ;
V_26 = V_21 -> V_25 == V_21 -> V_26 ?
V_25 : F_14 ( V_22 -> V_30 , V_21 -> V_26 , V_21 -> V_29 ) ;
F_15 ( & V_22 -> V_31 , V_23 ) ;
F_16 ( & V_22 -> V_31 , F_17 ( V_21 ) ,
V_21 -> V_32 . V_33 , V_21 -> V_32 . V_34 ) ;
F_18 ( & V_22 -> V_31 , V_25 , V_26 , V_21 -> V_35 ,
V_21 -> V_36 ) ;
F_19 ( & V_22 -> V_31 , V_21 -> V_25 , V_21 -> V_29 ) ;
return F_11 ( & V_22 -> V_31 ) ;
}
static int F_20 ( struct V_20 * V_21 )
{
struct V_1 * V_23 = F_13 ( V_21 ) ;
struct V_37 * V_38 = F_21 ( V_23 ) ;
return F_10 ( V_21 , V_38 -> V_39 ) ;
}
static int F_22 ( struct V_20 * V_21 )
{
struct V_1 * V_23 = F_13 ( V_21 ) ;
struct V_37 * V_38 = F_21 ( V_23 ) ;
return F_10 ( V_21 , V_38 -> V_40 ) ;
}
static int F_23 ( struct V_41 * V_21 )
{
return - V_42 ;
}
static int F_24 ( struct V_43 * V_2 )
{
struct V_37 * V_38 = & V_2 -> V_44 -> V_45 ;
struct V_1 * V_46 = F_25 ( V_2 ) ;
if ( F_26 ( V_38 -> V_47 , V_38 -> V_48 ) > V_49 / 8 )
return - V_16 ;
V_46 -> V_12 = V_38 -> V_12 ;
V_46 -> V_17 = V_38 -> V_17 ;
V_46 -> V_39 = F_20 ;
V_46 -> V_40 = F_22 ;
if ( V_38 -> V_48 ) {
V_46 -> V_50 = V_38 -> V_50 ? : F_23 ;
V_46 -> V_51 = V_38 -> V_51 ? : F_23 ;
} else {
V_46 -> V_50 = V_52 ;
V_46 -> V_51 = V_53 ;
}
V_46 -> V_13 = F_25 ( V_2 ) ;
V_46 -> V_14 = V_38 -> V_47 ;
return 0 ;
}
static void F_27 ( struct V_43 * V_2 )
{
struct V_1 * V_23 = F_25 ( V_2 ) ;
struct V_54 * V_38 = F_28 ( V_23 ) ;
V_38 -> exit ( V_23 ) ;
}
static int F_29 ( struct V_43 * V_2 )
{
struct V_1 * V_23 = F_25 ( V_2 ) ;
struct V_54 * V_38 = F_28 ( V_23 ) ;
if ( F_21 ( V_23 ) -> V_39 )
return F_24 ( V_2 ) ;
V_23 -> V_12 = V_38 -> V_12 ;
V_23 -> V_17 = V_38 -> V_17 ;
V_23 -> V_39 = V_38 -> V_39 ;
V_23 -> V_40 = V_38 -> V_40 ;
V_23 -> V_13 = F_25 ( V_2 ) ;
V_23 -> V_14 = V_38 -> V_47 ;
if ( V_38 -> exit )
V_23 -> V_32 . exit = F_27 ;
if ( V_38 -> V_55 )
return V_38 -> V_55 ( V_23 ) ;
return 0 ;
}
static int F_30 ( struct V_56 * V_57 , struct V_58 * V_38 )
{
struct V_59 V_60 ;
struct V_37 * V_23 = & V_38 -> V_45 ;
strncpy ( V_60 . type , L_1 , sizeof( V_60 . type ) ) ;
strncpy ( V_60 . V_61 , V_23 -> V_61 ? : L_2 , sizeof( V_60 . V_61 ) ) ;
V_60 . V_62 = V_38 -> V_63 ;
V_60 . V_47 = V_23 -> V_47 ;
V_60 . V_48 = V_23 -> V_48 ;
if ( F_31 ( V_57 , V_64 ,
sizeof( struct V_59 ) , & V_60 ) )
goto V_65;
return 0 ;
V_65:
return - V_66 ;
}
static int F_30 ( struct V_56 * V_57 , struct V_58 * V_38 )
{
return - V_42 ;
}
static void F_32 ( struct V_67 * V_68 , struct V_58 * V_38 )
{
struct V_37 * V_23 = & V_38 -> V_45 ;
F_33 ( V_68 , L_3 ) ;
F_33 ( V_68 , L_4 , V_38 -> V_69 & V_70 ?
L_5 : L_6 ) ;
F_33 ( V_68 , L_7 , V_38 -> V_63 ) ;
F_33 ( V_68 , L_8 , V_23 -> V_48 ) ;
F_33 ( V_68 , L_9 , V_23 -> V_47 ) ;
F_33 ( V_68 , L_10 , V_23 -> V_61 ? : L_2 ) ;
}
static int F_34 ( struct V_56 * V_57 , struct V_58 * V_38 )
{
struct V_59 V_60 ;
struct V_54 * V_23 = F_35 ( V_38 , struct V_54 , V_32 ) ;
strncpy ( V_60 . type , L_1 , sizeof( V_60 . type ) ) ;
strncpy ( V_60 . V_61 , L_11 , sizeof( V_60 . V_61 ) ) ;
V_60 . V_62 = V_38 -> V_63 ;
V_60 . V_47 = V_23 -> V_47 ;
V_60 . V_48 = V_23 -> V_48 ;
if ( F_31 ( V_57 , V_64 ,
sizeof( struct V_59 ) , & V_60 ) )
goto V_65;
return 0 ;
V_65:
return - V_66 ;
}
static int F_34 ( struct V_56 * V_57 , struct V_58 * V_38 )
{
return - V_42 ;
}
static void F_36 ( struct V_67 * V_68 , struct V_58 * V_38 )
{
struct V_54 * V_23 = F_35 ( V_38 , struct V_54 , V_32 ) ;
F_33 ( V_68 , L_3 ) ;
F_33 ( V_68 , L_4 , V_38 -> V_69 & V_70 ?
L_5 : L_6 ) ;
F_33 ( V_68 , L_7 , V_38 -> V_63 ) ;
F_33 ( V_68 , L_8 , V_23 -> V_48 ) ;
F_33 ( V_68 , L_9 , V_23 -> V_47 ) ;
F_33 ( V_68 , L_12 ) ;
}
static int V_52 ( struct V_41 * V_21 )
{
return F_37 ( & V_21 -> V_71 ) ;
}
static int V_53 ( struct V_41 * V_21 )
{
return F_38 ( & V_21 -> V_71 ) ;
}
static int F_39 ( struct V_56 * V_57 , struct V_58 * V_38 )
{
struct V_59 V_60 ;
struct V_37 * V_23 = & V_38 -> V_45 ;
strncpy ( V_60 . type , L_13 , sizeof( V_60 . type ) ) ;
strncpy ( V_60 . V_61 , V_23 -> V_61 , sizeof( V_60 . V_61 ) ) ;
V_60 . V_62 = V_38 -> V_63 ;
V_60 . V_47 = V_23 -> V_47 ;
V_60 . V_48 = V_23 -> V_48 ;
if ( F_31 ( V_57 , V_64 ,
sizeof( struct V_59 ) , & V_60 ) )
goto V_65;
return 0 ;
V_65:
return - V_66 ;
}
static int F_39 ( struct V_56 * V_57 , struct V_58 * V_38 )
{
return - V_42 ;
}
static void F_40 ( struct V_67 * V_68 , struct V_58 * V_38 )
{
struct V_37 * V_23 = & V_38 -> V_45 ;
F_33 ( V_68 , L_14 ) ;
F_33 ( V_68 , L_4 , V_38 -> V_69 & V_70 ?
L_5 : L_6 ) ;
F_33 ( V_68 , L_7 , V_38 -> V_63 ) ;
F_33 ( V_68 , L_8 , V_23 -> V_48 ) ;
F_33 ( V_68 , L_9 , V_23 -> V_47 ) ;
F_33 ( V_68 , L_10 , V_23 -> V_61 ) ;
}
static int F_41 ( struct V_72 * V_73 ,
const char * V_74 , T_2 type , T_2 V_75 )
{
V_73 -> V_32 . V_76 = & V_77 ;
return F_42 ( & V_73 -> V_32 , V_74 , type , V_75 ) ;
}
static int F_43 ( struct V_1 * V_2 ,
const T_1 * V_3 , unsigned int V_4 )
{
struct V_78 * V_79 = F_44 ( V_2 ) ;
return F_6 ( V_79 -> V_13 , V_3 , V_4 ) ;
}
static int F_45 ( struct V_1 * V_2 ,
unsigned int V_14 )
{
struct V_78 * V_79 = F_44 ( V_2 ) ;
return F_7 ( V_79 -> V_13 , V_14 ) ;
}
static void F_46 ( struct V_20 * V_21 , int V_15 )
{
struct V_80 * V_81 = F_12 ( V_21 ) ;
struct V_41 * V_31 = & V_81 -> V_31 ;
struct V_1 * V_61 ;
if ( V_15 == - V_82 )
return;
if ( V_15 )
goto V_83;
V_61 = F_13 ( V_21 ) ;
F_47 ( V_31 -> V_84 , V_81 -> V_85 , 0 ,
F_48 ( V_61 ) , 1 ) ;
V_83:
F_49 ( V_31 -> V_84 ) ;
}
static void F_50 ( struct V_86 * V_32 , int V_15 )
{
struct V_20 * V_21 = V_32 -> V_34 ;
F_46 ( V_21 , V_15 ) ;
F_51 ( V_21 , V_15 ) ;
}
static int F_52 ( struct V_20 * V_21 )
{
struct V_1 * V_61 = F_13 ( V_21 ) ;
struct V_78 * V_79 = F_44 ( V_61 ) ;
struct V_80 * V_81 = F_12 ( V_21 ) ;
struct V_41 * V_31 = & V_81 -> V_31 ;
unsigned int V_48 = F_48 ( V_61 ) ;
struct V_24 * V_25 , * V_26 ;
T_3 V_87 ;
void * V_34 ;
T_1 * V_88 ;
T_4 V_89 ;
int V_15 ;
if ( V_21 -> V_35 < V_48 )
return - V_16 ;
V_87 = V_21 -> V_32 . V_33 ;
V_34 = V_21 -> V_32 . V_34 ;
V_81 -> V_85 = F_14 ( V_81 -> V_90 , V_21 -> V_26 , V_21 -> V_29 ) ;
V_88 = F_53 ( F_54 ( V_81 -> V_85 ) ) ? NULL : F_55 ( V_81 -> V_85 ) ;
if ( ! V_88 ) {
V_88 = F_3 ( V_48 , V_21 -> V_32 . V_91 &
V_92 ? V_93 :
V_10 ) ;
if ( ! V_88 )
return - V_11 ;
V_87 = F_50 ;
V_34 = V_21 ;
}
memcpy ( & V_89 , V_21 -> V_36 + V_48 - sizeof( V_89 ) , sizeof( V_89 ) ) ;
V_25 = F_14 ( V_81 -> V_25 , V_21 -> V_25 , V_21 -> V_29 + V_48 ) ;
V_26 = V_21 -> V_25 == V_21 -> V_26 ?
V_25 : F_14 ( V_81 -> V_26 , V_81 -> V_85 , V_48 ) ;
F_56 ( V_31 , V_79 -> V_13 ) ;
F_57 ( V_31 , V_21 -> V_32 . V_91 ,
V_21 -> V_32 . V_33 , V_21 -> V_32 . V_34 ) ;
F_58 ( V_31 , V_25 , V_26 ,
V_21 -> V_35 - V_48 , V_21 -> V_36 ) ;
F_59 ( V_31 , V_21 -> V_25 , V_21 -> V_29 ) ;
F_60 ( V_31 , V_88 , F_61 ( V_89 ) ) ;
V_15 = F_62 ( V_31 ) ;
if ( F_63 ( F_53 ( F_54 ( V_81 -> V_85 ) ) ) )
F_46 ( V_21 , V_15 ) ;
return V_15 ;
}
static int F_64 ( struct V_20 * V_21 )
{
struct V_1 * V_61 = F_13 ( V_21 ) ;
struct V_78 * V_79 = F_44 ( V_61 ) ;
struct V_80 * V_81 = F_12 ( V_21 ) ;
struct V_20 * V_31 = & V_81 -> V_31 . V_71 ;
unsigned int V_48 = F_48 ( V_61 ) ;
struct V_24 * V_25 , * V_26 ;
T_3 V_87 ;
void * V_34 ;
if ( V_21 -> V_35 < V_48 )
return - V_16 ;
F_15 ( V_31 , V_79 -> V_13 ) ;
V_87 = V_21 -> V_32 . V_33 ;
V_34 = V_21 -> V_32 . V_34 ;
V_25 = F_14 ( V_81 -> V_25 , V_21 -> V_25 , V_21 -> V_29 + V_48 ) ;
V_26 = V_21 -> V_25 == V_21 -> V_26 ?
V_25 : F_14 ( V_81 -> V_26 , V_21 -> V_26 ,
V_21 -> V_29 + V_48 ) ;
F_16 ( V_31 , V_21 -> V_32 . V_91 , V_87 , V_34 ) ;
F_18 ( V_31 , V_25 , V_26 ,
V_21 -> V_35 - V_48 , V_21 -> V_36 ) ;
F_19 ( V_31 , V_21 -> V_25 , V_21 -> V_29 ) ;
F_47 ( V_21 -> V_36 , V_21 -> V_25 , V_21 -> V_29 , V_48 , 0 ) ;
return F_38 ( V_31 ) ;
}
static int F_65 ( struct V_20 * V_21 )
{
struct V_1 * V_61 = F_13 ( V_21 ) ;
struct V_78 * V_79 = F_44 ( V_61 ) ;
int V_15 = 0 ;
F_66 ( & V_79 -> V_94 ) ;
if ( V_61 -> V_39 != F_65 )
goto V_95;
V_61 -> V_39 = F_52 ;
V_95:
F_67 ( & V_79 -> V_94 ) ;
if ( V_15 )
return V_15 ;
return F_52 ( V_21 ) ;
}
static int F_68 ( struct V_43 * V_2 )
{
struct V_1 * V_61 = F_25 ( V_2 ) ;
struct V_78 * V_79 = F_44 ( V_61 ) ;
int V_15 ;
F_69 ( & V_79 -> V_94 ) ;
F_70 ( V_61 , sizeof( struct V_80 ) ) ;
V_15 = F_71 ( V_2 ) ;
V_79 -> V_13 = V_61 -> V_13 ;
V_61 -> V_13 = V_61 ;
return V_15 ;
}
static void F_72 ( struct V_43 * V_2 )
{
struct V_1 * V_61 = F_25 ( V_2 ) ;
struct V_78 * V_79 = F_44 ( V_61 ) ;
F_73 ( V_79 -> V_13 ) ;
}
struct V_96 * F_74 ( struct V_97 * V_98 ,
struct V_99 * * V_100 , T_2 type , T_2 V_75 )
{
const char * V_74 ;
struct V_72 * V_73 ;
struct V_101 * V_102 ;
struct V_96 * V_103 ;
struct V_54 * V_38 ;
unsigned int V_48 ;
unsigned int V_47 ;
int V_15 ;
V_102 = F_75 ( V_100 ) ;
if ( F_76 ( V_102 ) )
return F_77 ( V_102 ) ;
if ( ( V_102 -> type ^ ( V_104 | V_105 ) ) &
V_102 -> V_75 )
return F_78 ( - V_16 ) ;
V_74 = F_79 ( V_100 [ 1 ] ) ;
if ( F_76 ( V_74 ) )
return F_77 ( V_74 ) ;
V_103 = F_80 ( sizeof( * V_103 ) + sizeof( * V_73 ) , V_93 ) ;
if ( ! V_103 )
return F_78 ( - V_11 ) ;
V_73 = F_81 ( V_103 ) ;
V_75 |= F_82 ( V_102 -> type , V_102 -> V_75 ) ;
F_83 ( V_73 , F_84 ( V_103 ) ) ;
V_15 = ( V_102 -> V_75 & V_105 ) ?
F_41 ( V_73 , V_74 , type , V_75 ) :
F_85 ( V_73 , V_74 , type , V_75 ) ;
if ( V_15 )
goto V_106;
V_38 = F_86 ( V_73 ) ;
V_48 = F_87 ( V_38 ) ;
V_47 = F_88 ( V_38 ) ;
V_15 = - V_16 ;
if ( V_48 < sizeof( V_107 ) )
goto V_108;
if ( V_102 -> V_75 & V_105 ) {
if ( ! V_38 -> V_32 . V_45 . V_39 )
goto V_108;
if ( strcmp ( V_98 -> V_74 , V_38 -> V_32 . V_45 . V_61 ) )
goto V_108;
memcpy ( V_103 -> V_38 . V_32 . V_109 , V_38 -> V_32 . V_109 ,
V_110 ) ;
memcpy ( V_103 -> V_38 . V_32 . V_111 ,
V_38 -> V_32 . V_111 , V_110 ) ;
V_103 -> V_38 . V_32 . V_69 = V_104 |
V_105 ;
V_103 -> V_38 . V_32 . V_69 |= V_38 -> V_32 . V_69 &
V_70 ;
V_103 -> V_38 . V_32 . V_112 = V_38 -> V_32 . V_112 ;
V_103 -> V_38 . V_32 . V_63 = V_38 -> V_32 . V_63 ;
V_103 -> V_38 . V_32 . V_113 = V_38 -> V_32 . V_113 ;
V_103 -> V_38 . V_32 . V_114 = & V_115 ;
V_103 -> V_38 . V_32 . V_45 . V_48 = V_48 ;
V_103 -> V_38 . V_32 . V_45 . V_47 = V_47 ;
V_103 -> V_38 . V_32 . V_45 . V_12 = V_38 -> V_32 . V_45 . V_12 ;
V_103 -> V_38 . V_32 . V_45 . V_17 =
V_38 -> V_32 . V_45 . V_17 ;
V_103 -> V_38 . V_32 . V_45 . V_39 = V_38 -> V_32 . V_45 . V_39 ;
V_103 -> V_38 . V_32 . V_45 . V_40 = V_38 -> V_32 . V_45 . V_40 ;
goto V_83;
}
V_15 = - V_116 ;
if ( snprintf ( V_103 -> V_38 . V_32 . V_109 , V_110 ,
L_15 , V_98 -> V_74 , V_38 -> V_32 . V_109 ) >=
V_110 )
goto V_108;
if ( snprintf ( V_103 -> V_38 . V_32 . V_111 , V_110 ,
L_15 , V_98 -> V_74 , V_38 -> V_32 . V_111 ) >=
V_110 )
goto V_108;
V_103 -> V_38 . V_32 . V_69 = V_38 -> V_32 . V_69 & V_70 ;
V_103 -> V_38 . V_32 . V_112 = V_38 -> V_32 . V_112 ;
V_103 -> V_38 . V_32 . V_63 = V_38 -> V_32 . V_63 ;
V_103 -> V_38 . V_32 . V_113 = V_38 -> V_32 . V_113 ;
V_103 -> V_38 . V_32 . V_117 = sizeof( struct V_78 ) ;
V_103 -> V_38 . V_12 = F_43 ;
V_103 -> V_38 . V_17 = F_45 ;
V_103 -> V_38 . V_48 = V_48 ;
V_103 -> V_38 . V_47 = V_47 ;
V_103 -> V_38 . V_39 = F_65 ;
V_103 -> V_38 . V_40 = F_64 ;
V_103 -> V_38 . V_32 . V_118 = F_68 ;
V_103 -> V_38 . V_32 . V_119 = F_72 ;
V_83:
return V_103 ;
V_108:
F_89 ( V_73 ) ;
V_106:
F_5 ( V_103 ) ;
V_103 = F_78 ( V_15 ) ;
goto V_83;
}
void F_90 ( struct V_96 * V_103 )
{
F_89 ( F_81 ( V_103 ) ) ;
F_5 ( V_103 ) ;
}
int F_71 ( struct V_43 * V_2 )
{
struct V_120 * V_103 = ( void * ) V_2 -> V_44 ;
struct V_1 * V_13 ;
struct V_1 * V_23 ;
V_23 = F_25 ( V_2 ) ;
V_13 = F_91 ( F_92 ( V_103 ) ) ;
if ( F_76 ( V_13 ) )
return F_93 ( V_13 ) ;
V_23 -> V_13 = V_13 ;
V_23 -> V_18 += F_9 ( V_13 ) ;
return 0 ;
}
void F_94 ( struct V_43 * V_2 )
{
F_73 ( F_25 ( V_2 ) -> V_13 ) ;
}
static int F_95 ( struct V_58 * V_38 , T_2 type , T_2 V_75 )
{
struct V_99 * V_100 [ 3 ] ;
struct {
struct V_99 V_121 ;
struct V_101 V_34 ;
} V_122 ;
struct {
struct V_99 V_121 ;
struct V_123 V_34 ;
} V_124 ;
struct V_97 * V_98 ;
struct V_120 * V_103 ;
struct V_58 * V_125 ;
const char * V_61 ;
int V_15 ;
V_125 = F_96 ( V_38 -> V_111 ,
V_104 | V_105 ,
V_126 | V_105 ) ;
V_15 = F_93 ( V_125 ) ;
if ( F_76 ( V_125 ) )
goto V_83;
V_15 = - V_127 ;
if ( ! F_97 ( V_125 ) )
goto V_128;
V_122 . V_121 . V_129 = sizeof( V_122 ) ;
V_122 . V_121 . V_130 = V_131 ;
V_122 . V_34 . type = type | V_105 ;
V_122 . V_34 . V_75 = V_75 | V_105 ;
V_100 [ 0 ] = & V_122 . V_121 ;
V_124 . V_121 . V_129 = sizeof( V_124 ) ;
V_124 . V_121 . V_130 = V_132 ;
memcpy ( V_124 . V_34 . V_74 , V_38 -> V_111 , V_110 ) ;
V_100 [ 1 ] = & V_124 . V_121 ;
V_100 [ 2 ] = NULL ;
V_61 = V_38 -> V_45 . V_61 ;
V_98 = F_98 ( V_61 ) ;
V_15 = - V_133 ;
if ( ! V_98 )
goto V_134;
if ( V_98 -> V_135 ) {
V_15 = V_98 -> V_135 ( V_98 , V_100 ) ;
if ( V_15 )
goto V_136;
goto V_137;
}
V_103 = V_98 -> V_138 ( V_100 ) ;
V_15 = F_93 ( V_103 ) ;
if ( F_76 ( V_103 ) )
goto V_136;
V_15 = F_99 ( V_98 , V_103 ) ;
if ( V_15 ) {
V_98 -> free ( V_103 ) ;
goto V_136;
}
V_137:
V_15 = - V_127 ;
V_136:
F_100 ( V_98 ) ;
V_134:
F_101 ( V_125 ) ;
V_128:
F_102 ( V_125 ) ;
V_83:
F_102 ( V_38 ) ;
return V_15 ;
}
struct V_58 * F_103 ( const char * V_74 , T_2 type , T_2 V_75 )
{
struct V_58 * V_38 ;
V_38 = F_104 ( V_74 , type , V_75 ) ;
if ( F_76 ( V_38 ) )
return V_38 ;
if ( V_38 -> V_114 == & V_115 )
return V_38 ;
if ( ! V_38 -> V_45 . V_48 )
return V_38 ;
F_102 ( V_38 ) ;
V_38 = F_104 ( V_74 , type | V_139 ,
V_75 & ~ V_139 ) ;
if ( F_76 ( V_38 ) )
return V_38 ;
if ( V_38 -> V_114 == & V_115 ) {
if ( ~ V_38 -> V_69 & ( type ^ ~ V_75 ) & V_139 ) {
F_102 ( V_38 ) ;
V_38 = F_78 ( - V_133 ) ;
}
return V_38 ;
}
F_105 ( ! V_38 -> V_45 . V_48 ) ;
return F_78 ( F_95 ( V_38 , type , V_75 ) ) ;
}
int F_85 ( struct V_72 * V_73 , const char * V_74 ,
T_2 type , T_2 V_75 )
{
V_73 -> V_32 . V_76 = & V_115 ;
return F_42 ( & V_73 -> V_32 , V_74 , type , V_75 ) ;
}
struct V_1 * F_106 ( const char * V_140 , T_2 type , T_2 V_75 )
{
return F_107 ( V_140 , & V_115 , type , V_75 ) ;
}
static int F_108 ( struct V_54 * V_38 )
{
struct V_58 * V_32 = & V_38 -> V_32 ;
if ( F_26 ( V_38 -> V_47 , V_38 -> V_48 ) > V_49 / 8 )
return - V_16 ;
V_32 -> V_114 = & V_141 ;
V_32 -> V_69 &= ~ V_126 ;
V_32 -> V_69 |= V_104 ;
return 0 ;
}
int F_109 ( struct V_54 * V_38 )
{
struct V_58 * V_32 = & V_38 -> V_32 ;
int V_15 ;
V_15 = F_108 ( V_38 ) ;
if ( V_15 )
return V_15 ;
return F_110 ( V_32 ) ;
}
void F_111 ( struct V_54 * V_38 )
{
F_112 ( & V_38 -> V_32 ) ;
}
int F_113 ( struct V_54 * V_142 , int V_143 )
{
int V_144 , V_6 ;
for ( V_144 = 0 ; V_144 < V_143 ; V_144 ++ ) {
V_6 = F_109 ( & V_142 [ V_144 ] ) ;
if ( V_6 )
goto V_15;
}
return 0 ;
V_15:
for ( -- V_144 ; V_144 >= 0 ; -- V_144 )
F_111 ( & V_142 [ V_144 ] ) ;
return V_6 ;
}
void F_114 ( struct V_54 * V_142 , int V_143 )
{
int V_144 ;
for ( V_144 = V_143 - 1 ; V_144 >= 0 ; -- V_144 )
F_111 ( & V_142 [ V_144 ] ) ;
}
int F_115 ( struct V_97 * V_98 ,
struct V_96 * V_103 )
{
int V_15 ;
V_15 = F_108 ( & V_103 -> V_38 ) ;
if ( V_15 )
return V_15 ;
return F_99 ( V_98 , F_84 ( V_103 ) ) ;
}
