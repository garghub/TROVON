static void F_1 ( void * V_1 )
{
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
struct V_4 V_5 ;
struct V_6 V_7 [ 2 ] ;
T_1 V_8 , V_9 , V_10 , V_11 , V_12 , V_13 , V_14 ;
T_2 error ;
struct V_15 * V_16 = V_3 -> V_17 ;
struct V_18 * V_19 = & V_3 -> V_19 ;
unsigned long V_20 ;
int V_21 ;
V_12 = F_2 ( V_3 -> V_22 ) ;
V_8 = V_16 -> V_23 ;
V_9 = V_16 -> V_24 ;
error = V_16 -> V_25 ;
F_3 () ;
if ( error )
return;
V_10 = F_4 ( V_9 , V_8 , V_12 ) ;
if ( V_10 >= V_12 )
return;
F_5 ( & V_3 -> V_26 -> V_27 -> V_28 . V_29 , V_20 ) ;
if ( F_6 ( & V_3 -> V_26 -> V_27 -> V_28 ) ) {
F_7 ( & V_3 -> V_30 , 0 ) ;
F_8 ( & V_3 -> V_26 -> V_27 -> V_28 . V_29 ,
V_20 ) ;
return;
}
F_8 ( & V_3 -> V_26 -> V_27 -> V_28 . V_29 , V_20 ) ;
V_11 = V_12 - V_10 ;
V_13 = F_9 ( V_9 , V_12 ) ;
V_14 = F_9 ( V_8 , V_12 ) ;
memset ( & V_5 , 0 , sizeof( V_5 ) ) ;
V_5 . V_31 . type = V_32 | V_33 ;
V_5 . V_31 . V_34 = V_11 ;
if ( V_13 < V_14 ) {
V_7 [ 0 ] . V_35 = V_19 -> V_36 + V_13 ;
V_7 [ 0 ] . V_37 = V_11 ;
V_5 . V_31 . V_6 = V_7 ;
V_5 . V_31 . V_38 = 1 ;
} else {
V_7 [ 0 ] . V_35 = V_19 -> V_36 + V_13 ;
V_7 [ 0 ] . V_37 = V_12 - V_13 ;
V_7 [ 1 ] . V_35 = V_19 -> V_36 ;
V_7 [ 1 ] . V_37 = V_11 - V_7 [ 0 ] . V_37 ;
V_5 . V_31 . V_6 = V_7 ;
V_5 . V_31 . V_38 = 2 ;
}
F_7 ( & V_3 -> V_30 , 0 ) ;
V_21 = F_10 ( V_3 -> V_26 , & V_5 , V_11 , V_39 ) ;
F_11 ( V_21 > V_11 ) ;
if ( V_21 == - V_40 )
return;
if ( ! V_21 )
V_21 = - V_41 ;
F_5 ( & V_3 -> V_26 -> V_27 -> V_28 . V_29 , V_20 ) ;
if ( V_21 > 0 && ! F_6 ( & V_3 -> V_26 -> V_27 -> V_28 ) )
F_12 ( & V_3 -> V_30 ) ;
F_8 ( & V_3 -> V_26 -> V_27 -> V_28 . V_29 , V_20 ) ;
F_13 () ;
if ( V_21 < 0 )
V_16 -> V_25 = V_21 ;
else
V_16 -> V_24 = V_9 + V_21 ;
F_13 () ;
F_14 ( V_3 -> V_42 ) ;
return;
}
static void F_15 ( struct V_2 * V_3 )
{
struct V_15 * V_16 = V_3 -> V_17 ;
struct V_18 * V_19 = & V_3 -> V_19 ;
struct V_4 V_5 ;
struct V_6 V_7 [ 2 ] ;
T_1 V_8 , V_9 , V_10 , V_12 ;
int V_21 ;
V_8 = V_16 -> V_43 ;
V_9 = V_16 -> V_44 ;
F_3 () ;
V_12 = F_2 ( V_3 -> V_22 ) ;
V_10 = F_4 ( V_9 , V_8 , V_12 ) ;
if ( V_10 == 0 )
return;
memset ( & V_5 , 0 , sizeof( V_5 ) ) ;
V_5 . V_45 |= V_39 ;
V_5 . V_31 . type = V_32 | V_46 ;
V_5 . V_31 . V_34 = V_10 ;
if ( F_9 ( V_9 , V_12 ) > F_9 ( V_8 , V_12 ) ) {
V_7 [ 0 ] . V_35 = V_19 -> V_47 + F_9 ( V_8 , V_12 ) ;
V_7 [ 0 ] . V_37 = V_10 ;
V_5 . V_31 . V_6 = V_7 ;
V_5 . V_31 . V_38 = 1 ;
} else {
V_7 [ 0 ] . V_35 = V_19 -> V_47 + F_9 ( V_8 , V_12 ) ;
V_7 [ 0 ] . V_37 = V_12 - F_9 ( V_8 , V_12 ) ;
V_7 [ 1 ] . V_35 = V_19 -> V_47 ;
V_7 [ 1 ] . V_37 = V_10 - V_7 [ 0 ] . V_37 ;
V_5 . V_31 . V_6 = V_7 ;
V_5 . V_31 . V_38 = 2 ;
}
F_7 ( & V_3 -> V_48 , 0 ) ;
V_21 = F_16 ( V_3 -> V_26 , & V_5 , V_10 ) ;
if ( V_21 == - V_40 || ( V_21 >= 0 && V_21 < V_10 ) ) {
F_12 ( & V_3 -> V_48 ) ;
F_12 ( & V_3 -> V_49 ) ;
}
if ( V_21 == - V_40 )
return;
F_13 () ;
if ( V_21 < 0 ) {
V_16 -> V_50 = V_21 ;
} else {
V_16 -> V_50 = 0 ;
V_16 -> V_43 = V_8 + V_21 ;
V_9 = V_16 -> V_44 ;
}
F_13 () ;
if ( V_9 != V_8 + V_21 )
F_12 ( & V_3 -> V_48 ) ;
F_14 ( V_3 -> V_42 ) ;
}
static void F_17 ( struct V_51 * V_52 )
{
struct V_53 * V_54 = F_18 ( V_52 ,
struct V_53 , V_55 ) ;
struct V_2 * V_3 = F_18 ( V_54 , struct V_2 ,
V_54 ) ;
while ( F_19 ( & V_3 -> V_49 ) > 0 ) {
if ( F_19 ( & V_3 -> V_56 ) > 0 ) {
F_7 ( & V_3 -> V_56 , 0 ) ;
return;
}
if ( F_19 ( & V_3 -> V_30 ) > 0 )
F_1 ( V_3 ) ;
if ( F_19 ( & V_3 -> V_48 ) > 0 )
F_15 ( V_3 ) ;
F_20 ( & V_3 -> V_49 ) ;
}
}
static int F_21 ( struct V_57 * V_58 ,
struct V_59 * V_60 )
{
struct V_61 * V_62 ;
int V_21 ;
struct V_63 * V_64 ;
V_62 = F_22 ( & V_58 -> V_58 ) ;
if ( V_60 -> V_65 . V_66 . V_67 != V_68 ||
V_60 -> V_65 . V_66 . type != V_69 ||
( V_60 -> V_65 . V_66 . V_70 != V_71 &&
V_60 -> V_65 . V_66 . V_70 != V_68 ) )
V_21 = - V_72 ;
else
V_21 = 0 ;
V_64 = F_23 ( & V_62 -> V_17 , V_62 -> V_17 . V_73 ++ ) ;
V_64 -> V_74 = V_60 -> V_74 ;
V_64 -> V_75 = V_60 -> V_75 ;
V_64 -> V_65 . V_66 . V_76 = V_60 -> V_65 . V_66 . V_76 ;
V_64 -> V_21 = V_21 ;
return 0 ;
}
static void F_24 ( struct V_26 * V_26 )
{
struct V_2 * V_3 = V_26 -> V_77 ;
struct V_15 * V_16 ;
if ( V_3 == NULL )
return;
V_16 = V_3 -> V_17 ;
V_16 -> V_25 = - V_41 ;
F_14 ( V_3 -> V_42 ) ;
}
static void F_25 ( struct V_26 * V_26 )
{
struct V_2 * V_3 = V_26 -> V_77 ;
struct V_53 * V_78 ;
if ( V_3 == NULL )
return;
V_78 = & V_3 -> V_54 ;
F_12 ( & V_3 -> V_30 ) ;
F_12 ( & V_3 -> V_49 ) ;
F_26 ( V_78 -> V_79 , & V_78 -> V_55 ) ;
}
static struct V_2 * F_27 (
struct V_61 * V_62 ,
T_3 V_76 ,
T_4 V_80 ,
T_5 V_81 ,
struct V_66 * V_26 )
{
int V_21 ;
struct V_2 * V_3 ;
void * V_82 ;
V_3 = F_28 ( sizeof( * V_3 ) , V_83 ) ;
if ( V_3 == NULL )
return NULL ;
V_3 -> V_62 = V_62 ;
V_3 -> V_26 = V_26 ;
V_3 -> V_76 = V_76 ;
V_3 -> V_80 = V_80 ;
V_21 = F_29 ( V_62 -> V_58 , & V_80 , 1 , & V_82 ) ;
if ( V_21 < 0 )
goto V_47;
V_3 -> V_17 = V_82 ;
V_3 -> V_22 = V_3 -> V_17 -> V_22 ;
F_30 () ;
if ( V_3 -> V_22 > V_84 ) {
F_31 ( L_1 ,
V_85 , V_3 -> V_22 , V_84 ) ;
goto V_47;
}
V_21 = F_29 ( V_62 -> V_58 , V_3 -> V_17 -> V_80 ,
( 1 << V_3 -> V_22 ) , & V_82 ) ;
if ( V_21 < 0 )
goto V_47;
V_3 -> V_86 = V_82 ;
V_21 = F_32 ( V_62 -> V_58 -> V_87 ,
V_81 ,
V_88 ,
0 ,
L_2 ,
V_3 ) ;
if ( V_21 < 0 )
goto V_47;
V_3 -> V_42 = V_21 ;
V_3 -> V_19 . V_36 = V_3 -> V_86 ;
V_3 -> V_19 . V_47 = V_3 -> V_86 + F_2 ( V_3 -> V_22 ) ;
V_3 -> V_54 . V_79 = F_33 ( L_3 , V_89 , 1 ) ;
if ( ! V_3 -> V_54 . V_79 )
goto V_47;
F_7 ( & V_3 -> V_49 , 1 ) ;
F_34 ( & V_3 -> V_54 . V_55 , F_17 ) ;
F_35 ( & V_62 -> V_90 ) ;
F_36 ( & V_3 -> V_91 , & V_62 -> V_92 ) ;
F_37 ( & V_62 -> V_90 ) ;
F_38 ( & V_3 -> V_26 -> V_27 -> V_93 ) ;
V_3 -> V_94 = V_3 -> V_26 -> V_27 -> V_95 ;
V_3 -> V_26 -> V_27 -> V_77 = V_3 ;
V_3 -> V_26 -> V_27 -> V_95 = F_25 ;
V_3 -> V_26 -> V_27 -> V_96 = F_24 ;
F_39 ( & V_3 -> V_26 -> V_27 -> V_93 ) ;
return V_3 ;
V_47:
F_35 ( & V_62 -> V_90 ) ;
F_40 ( & V_3 -> V_91 ) ;
F_41 ( V_62 -> V_58 , V_62 , V_3 ) ;
F_37 ( & V_62 -> V_90 ) ;
return NULL ;
}
static int F_42 ( struct V_57 * V_58 ,
struct V_59 * V_60 )
{
struct V_61 * V_62 ;
int V_21 = - V_97 ;
struct V_66 * V_26 ;
struct V_2 * V_3 ;
struct V_63 * V_64 ;
struct V_98 * V_99 = (struct V_98 * ) & V_60 -> V_65 . V_100 . V_101 ;
V_62 = F_22 ( & V_58 -> V_58 ) ;
if ( V_60 -> V_65 . V_100 . V_102 < sizeof( V_99 -> V_103 ) ||
V_60 -> V_65 . V_100 . V_102 > sizeof( V_60 -> V_65 . V_100 . V_101 ) ||
V_99 -> V_103 != V_68 )
goto V_47;
V_21 = F_43 ( V_68 , V_69 , 0 , & V_26 ) ;
if ( V_21 < 0 )
goto V_47;
V_21 = F_44 ( V_26 , V_99 , V_60 -> V_65 . V_100 . V_102 , 0 ) ;
if ( V_21 < 0 ) {
F_45 ( V_26 ) ;
goto V_47;
}
V_3 = F_27 ( V_62 ,
V_60 -> V_65 . V_100 . V_76 ,
V_60 -> V_65 . V_100 . V_80 ,
V_60 -> V_65 . V_100 . V_81 ,
V_26 ) ;
if ( ! V_3 ) {
V_21 = - V_104 ;
F_45 ( V_3 -> V_26 ) ;
}
V_47:
V_64 = F_23 ( & V_62 -> V_17 , V_62 -> V_17 . V_73 ++ ) ;
V_64 -> V_74 = V_60 -> V_74 ;
V_64 -> V_75 = V_60 -> V_75 ;
V_64 -> V_65 . V_100 . V_76 = V_60 -> V_65 . V_100 . V_76 ;
V_64 -> V_21 = V_21 ;
return 0 ;
}
static int F_41 ( struct V_57 * V_58 ,
struct V_61 * V_62 ,
struct V_2 * V_3 )
{
F_46 ( V_3 -> V_42 ) ;
if ( V_3 -> V_26 -> V_27 != NULL ) {
F_38 ( & V_3 -> V_26 -> V_27 -> V_93 ) ;
V_3 -> V_26 -> V_27 -> V_77 = NULL ;
V_3 -> V_26 -> V_27 -> V_95 = V_3 -> V_94 ;
F_39 ( & V_3 -> V_26 -> V_27 -> V_93 ) ;
}
F_7 ( & V_3 -> V_56 , 1 ) ;
F_47 ( & V_3 -> V_54 . V_55 ) ;
F_48 ( V_58 , V_3 -> V_86 ) ;
F_48 ( V_58 , ( void * ) V_3 -> V_17 ) ;
F_49 ( V_3 -> V_42 , V_3 ) ;
F_45 ( V_3 -> V_26 ) ;
F_50 ( V_3 ) ;
return 0 ;
}
static int F_51 ( struct V_57 * V_58 ,
struct V_61 * V_62 ,
struct V_105 * V_106 )
{
if ( V_106 -> V_26 -> V_27 != NULL ) {
F_38 ( & V_106 -> V_26 -> V_27 -> V_93 ) ;
V_106 -> V_26 -> V_27 -> V_77 = NULL ;
V_106 -> V_26 -> V_27 -> V_95 = V_106 -> V_94 ;
F_39 ( & V_106 -> V_26 -> V_27 -> V_93 ) ;
}
F_45 ( V_106 -> V_26 ) ;
F_52 ( V_106 -> V_79 ) ;
F_53 ( V_106 -> V_79 ) ;
F_50 ( V_106 ) ;
return 0 ;
}
static int F_54 ( struct V_57 * V_58 ,
struct V_59 * V_60 )
{
struct V_61 * V_62 ;
struct V_2 * V_3 , * V_107 ;
struct V_105 * V_106 ;
int V_21 = 0 ;
struct V_63 * V_64 ;
V_62 = F_22 ( & V_58 -> V_58 ) ;
F_35 ( & V_62 -> V_90 ) ;
F_55 (map, n, &fedata->socket_mappings, list) {
if ( V_3 -> V_76 == V_60 -> V_65 . V_56 . V_76 ) {
F_40 ( & V_3 -> V_91 ) ;
F_37 ( & V_62 -> V_90 ) ;
V_21 = F_41 ( V_58 , V_62 , V_3 ) ;
goto V_47;
}
}
V_106 = F_56 ( & V_62 -> V_108 ,
V_60 -> V_65 . V_56 . V_76 ) ;
if ( V_106 != NULL ) {
F_57 ( & V_62 -> V_108 , V_106 -> V_76 ) ;
F_37 ( & V_62 -> V_90 ) ;
V_21 = F_51 ( V_58 , V_62 , V_106 ) ;
} else
F_37 ( & V_62 -> V_90 ) ;
V_47:
V_64 = F_23 ( & V_62 -> V_17 , V_62 -> V_17 . V_73 ++ ) ;
V_64 -> V_74 = V_60 -> V_74 ;
V_64 -> V_65 . V_56 . V_76 = V_60 -> V_65 . V_56 . V_76 ;
V_64 -> V_75 = V_60 -> V_75 ;
V_64 -> V_21 = V_21 ;
return 0 ;
}
static void F_58 ( struct V_51 * V_52 )
{
struct V_105 * V_106 = F_18 (
V_52 , struct V_105 , V_55 ) ;
struct V_2 * V_3 ;
struct V_53 * V_78 ;
struct V_61 * V_62 ;
struct V_66 * V_26 ;
struct V_63 * V_64 ;
struct V_59 * V_60 ;
int V_109 ;
int V_21 = - V_97 ;
unsigned long V_20 ;
V_62 = V_106 -> V_62 ;
F_5 ( & V_106 -> V_110 , V_20 ) ;
V_60 = & V_106 -> V_111 ;
if ( V_60 -> V_75 != V_112 ) {
F_8 ( & V_106 -> V_110 , V_20 ) ;
return;
}
F_8 ( & V_106 -> V_110 , V_20 ) ;
V_26 = F_59 () ;
if ( V_26 == NULL )
goto V_50;
V_26 -> type = V_106 -> V_26 -> type ;
V_26 -> V_113 = V_106 -> V_26 -> V_113 ;
V_21 = F_60 ( V_106 -> V_26 , V_26 , V_114 , true ) ;
if ( V_21 == - V_40 ) {
F_45 ( V_26 ) ;
goto V_50;
}
V_3 = F_27 ( V_62 ,
V_60 -> V_65 . V_115 . V_116 ,
V_60 -> V_65 . V_115 . V_80 ,
V_60 -> V_65 . V_115 . V_81 ,
V_26 ) ;
if ( ! V_3 ) {
V_21 = - V_104 ;
F_45 ( V_26 ) ;
goto V_50;
}
V_3 -> V_117 = V_106 ;
V_78 = & V_3 -> V_54 ;
F_12 ( & V_3 -> V_30 ) ;
F_12 ( & V_3 -> V_49 ) ;
F_26 ( V_78 -> V_79 , & V_78 -> V_55 ) ;
V_50:
V_64 = F_23 ( & V_62 -> V_17 , V_62 -> V_17 . V_73 ++ ) ;
V_64 -> V_74 = V_60 -> V_74 ;
V_64 -> V_75 = V_60 -> V_75 ;
V_64 -> V_65 . V_115 . V_76 = V_60 -> V_65 . V_115 . V_76 ;
V_64 -> V_21 = V_21 ;
F_61 ( & V_62 -> V_17 , V_109 ) ;
if ( V_109 )
F_14 ( V_62 -> V_42 ) ;
V_106 -> V_111 . V_75 = 0 ;
}
static void F_62 ( struct V_26 * V_26 )
{
struct V_105 * V_106 = V_26 -> V_77 ;
struct V_61 * V_62 ;
struct V_63 * V_64 ;
unsigned long V_20 ;
int V_109 ;
if ( V_106 == NULL )
return;
V_62 = V_106 -> V_62 ;
F_5 ( & V_106 -> V_110 , V_20 ) ;
if ( V_106 -> V_111 . V_75 == V_118 ) {
V_64 = F_23 ( & V_62 -> V_17 ,
V_62 -> V_17 . V_73 ++ ) ;
V_64 -> V_74 = V_106 -> V_111 . V_74 ;
V_64 -> V_65 . V_119 . V_76 = V_106 -> V_111 . V_65 . V_119 . V_76 ;
V_64 -> V_75 = V_106 -> V_111 . V_75 ;
V_64 -> V_21 = 0 ;
V_106 -> V_111 . V_75 = 0 ;
F_8 ( & V_106 -> V_110 , V_20 ) ;
F_61 ( & V_62 -> V_17 , V_109 ) ;
if ( V_109 )
F_14 ( V_106 -> V_62 -> V_42 ) ;
} else {
F_8 ( & V_106 -> V_110 , V_20 ) ;
F_26 ( V_106 -> V_79 , & V_106 -> V_55 ) ;
}
}
static int F_63 ( struct V_57 * V_58 ,
struct V_59 * V_60 )
{
struct V_61 * V_62 ;
int V_21 ;
struct V_105 * V_3 ;
struct V_63 * V_64 ;
V_62 = F_22 ( & V_58 -> V_58 ) ;
V_3 = F_28 ( sizeof( * V_3 ) , V_83 ) ;
if ( V_3 == NULL ) {
V_21 = - V_120 ;
goto V_47;
}
F_34 ( & V_3 -> V_55 , F_58 ) ;
F_64 ( & V_3 -> V_110 ) ;
V_3 -> V_79 = F_33 ( L_4 , V_89 , 1 ) ;
if ( ! V_3 -> V_79 ) {
V_21 = - V_120 ;
goto V_47;
}
V_21 = F_43 ( V_68 , V_69 , 0 , & V_3 -> V_26 ) ;
if ( V_21 < 0 )
goto V_47;
V_21 = F_65 ( V_3 -> V_26 , (struct V_98 * ) & V_60 -> V_65 . V_121 . V_101 ,
V_60 -> V_65 . V_121 . V_102 ) ;
if ( V_21 < 0 )
goto V_47;
V_3 -> V_62 = V_62 ;
V_3 -> V_76 = V_60 -> V_65 . V_121 . V_76 ;
F_35 ( & V_62 -> V_90 ) ;
V_21 = F_66 ( & V_62 -> V_108 , V_3 -> V_76 ,
V_3 ) ;
F_37 ( & V_62 -> V_90 ) ;
if ( V_21 )
goto V_47;
F_38 ( & V_3 -> V_26 -> V_27 -> V_93 ) ;
V_3 -> V_94 = V_3 -> V_26 -> V_27 -> V_95 ;
V_3 -> V_26 -> V_27 -> V_77 = V_3 ;
V_3 -> V_26 -> V_27 -> V_95 = F_62 ;
F_39 ( & V_3 -> V_26 -> V_27 -> V_93 ) ;
V_47:
if ( V_21 ) {
if ( V_3 && V_3 -> V_26 )
F_45 ( V_3 -> V_26 ) ;
if ( V_3 && V_3 -> V_79 )
F_53 ( V_3 -> V_79 ) ;
F_50 ( V_3 ) ;
}
V_64 = F_23 ( & V_62 -> V_17 , V_62 -> V_17 . V_73 ++ ) ;
V_64 -> V_74 = V_60 -> V_74 ;
V_64 -> V_75 = V_60 -> V_75 ;
V_64 -> V_65 . V_121 . V_76 = V_60 -> V_65 . V_121 . V_76 ;
V_64 -> V_21 = V_21 ;
return 0 ;
}
static int F_67 ( struct V_57 * V_58 ,
struct V_59 * V_60 )
{
struct V_61 * V_62 ;
int V_21 = - V_97 ;
struct V_105 * V_3 ;
struct V_63 * V_64 ;
V_62 = F_22 ( & V_58 -> V_58 ) ;
F_35 ( & V_62 -> V_90 ) ;
V_3 = F_56 ( & V_62 -> V_108 , V_60 -> V_65 . V_122 . V_76 ) ;
F_37 ( & V_62 -> V_90 ) ;
if ( V_3 == NULL )
goto V_47;
V_21 = F_68 ( V_3 -> V_26 , V_60 -> V_65 . V_122 . V_123 ) ;
V_47:
V_64 = F_23 ( & V_62 -> V_17 , V_62 -> V_17 . V_73 ++ ) ;
V_64 -> V_74 = V_60 -> V_74 ;
V_64 -> V_75 = V_60 -> V_75 ;
V_64 -> V_65 . V_122 . V_76 = V_60 -> V_65 . V_122 . V_76 ;
V_64 -> V_21 = V_21 ;
return 0 ;
}
static int F_69 ( struct V_57 * V_58 ,
struct V_59 * V_60 )
{
struct V_61 * V_62 ;
struct V_105 * V_106 ;
int V_21 = - V_97 ;
struct V_63 * V_64 ;
unsigned long V_20 ;
V_62 = F_22 ( & V_58 -> V_58 ) ;
F_35 ( & V_62 -> V_90 ) ;
V_106 = F_56 ( & V_62 -> V_108 ,
V_60 -> V_65 . V_115 . V_76 ) ;
F_37 ( & V_62 -> V_90 ) ;
if ( V_106 == NULL )
goto V_50;
F_5 ( & V_106 -> V_110 , V_20 ) ;
if ( V_106 -> V_111 . V_75 != 0 ) {
F_8 ( & V_106 -> V_110 , V_20 ) ;
V_21 = - V_124 ;
goto V_50;
}
V_106 -> V_111 = * V_60 ;
F_8 ( & V_106 -> V_110 , V_20 ) ;
F_26 ( V_106 -> V_79 , & V_106 -> V_55 ) ;
return - 1 ;
V_50:
V_64 = F_23 ( & V_62 -> V_17 , V_62 -> V_17 . V_73 ++ ) ;
V_64 -> V_74 = V_60 -> V_74 ;
V_64 -> V_75 = V_60 -> V_75 ;
V_64 -> V_65 . V_115 . V_76 = V_60 -> V_65 . V_115 . V_76 ;
V_64 -> V_21 = V_21 ;
return 0 ;
}
static int F_70 ( struct V_57 * V_58 ,
struct V_59 * V_60 )
{
struct V_61 * V_62 ;
struct V_105 * V_106 ;
struct V_63 * V_64 ;
struct V_125 * V_126 ;
struct V_127 * V_128 ;
unsigned long V_20 ;
int V_21 ;
bool V_19 ;
V_62 = F_22 ( & V_58 -> V_58 ) ;
F_35 ( & V_62 -> V_90 ) ;
V_106 = F_56 ( & V_62 -> V_108 ,
V_60 -> V_65 . V_119 . V_76 ) ;
F_37 ( & V_62 -> V_90 ) ;
if ( V_106 == NULL )
return - V_97 ;
F_5 ( & V_106 -> V_110 , V_20 ) ;
if ( V_106 -> V_111 . V_75 != 0 ) {
V_21 = - V_124 ;
goto V_47;
}
V_106 -> V_111 = * V_60 ;
V_126 = F_71 ( V_106 -> V_26 -> V_27 ) ;
V_128 = & V_126 -> V_129 ;
V_19 = V_128 -> V_130 != NULL ;
if ( V_19 ) {
V_106 -> V_111 . V_75 = 0 ;
V_21 = 0 ;
goto V_47;
}
F_8 ( & V_106 -> V_110 , V_20 ) ;
return - 1 ;
V_47:
F_8 ( & V_106 -> V_110 , V_20 ) ;
V_64 = F_23 ( & V_62 -> V_17 , V_62 -> V_17 . V_73 ++ ) ;
V_64 -> V_74 = V_60 -> V_74 ;
V_64 -> V_75 = V_60 -> V_75 ;
V_64 -> V_65 . V_119 . V_76 = V_60 -> V_65 . V_119 . V_76 ;
V_64 -> V_21 = V_21 ;
return 0 ;
}
static int F_72 ( struct V_57 * V_58 ,
struct V_59 * V_60 )
{
int V_21 = 0 ;
switch ( V_60 -> V_75 ) {
case V_131 :
V_21 = F_21 ( V_58 , V_60 ) ;
break;
case V_132 :
V_21 = F_42 ( V_58 , V_60 ) ;
break;
case V_133 :
V_21 = F_54 ( V_58 , V_60 ) ;
break;
case V_134 :
V_21 = F_63 ( V_58 , V_60 ) ;
break;
case V_135 :
V_21 = F_67 ( V_58 , V_60 ) ;
break;
case V_112 :
V_21 = F_69 ( V_58 , V_60 ) ;
break;
case V_118 :
V_21 = F_70 ( V_58 , V_60 ) ;
break;
default:
{
struct V_61 * V_62 ;
struct V_63 * V_64 ;
V_62 = F_22 ( & V_58 -> V_58 ) ;
V_64 = F_23 (
& V_62 -> V_17 , V_62 -> V_17 . V_73 ++ ) ;
V_64 -> V_74 = V_60 -> V_74 ;
V_64 -> V_75 = V_60 -> V_75 ;
V_64 -> V_21 = - V_136 ;
break;
}
}
return V_21 ;
}
static void F_73 ( struct V_61 * V_62 )
{
int V_109 , V_137 = 0 , V_138 = 1 ;
struct V_59 V_60 ;
struct V_57 * V_58 = V_62 -> V_58 ;
while ( V_138 ) {
while ( F_74 ( & V_62 -> V_17 ) ) {
F_75 ( & V_62 -> V_17 ,
V_62 -> V_17 . V_139 ++ ,
& V_60 ) ;
if ( ! F_72 ( V_58 , & V_60 ) ) {
F_61 (
& V_62 -> V_17 , V_109 ) ;
V_137 += V_109 ;
}
}
if ( V_137 ) {
F_14 ( V_62 -> V_42 ) ;
V_137 = 0 ;
}
F_76 ( & V_62 -> V_17 , V_138 ) ;
}
}
static T_6 F_77 ( int V_42 , void * V_140 )
{
struct V_57 * V_58 = V_140 ;
struct V_61 * V_62 = NULL ;
if ( V_58 == NULL )
return V_141 ;
V_62 = F_22 ( & V_58 -> V_58 ) ;
if ( V_62 == NULL )
return V_141 ;
F_73 ( V_62 ) ;
return V_141 ;
}
static T_6 V_88 ( int V_42 , void * V_142 )
{
struct V_2 * V_3 = V_142 ;
struct V_53 * V_78 ;
if ( V_3 == NULL || V_3 -> V_26 == NULL || V_3 -> V_26 -> V_27 == NULL ||
V_3 -> V_26 -> V_27 -> V_77 != V_3 )
return V_141 ;
V_78 = & V_3 -> V_54 ;
F_12 ( & V_3 -> V_48 ) ;
F_12 ( & V_3 -> V_49 ) ;
F_26 ( V_78 -> V_79 , & V_78 -> V_55 ) ;
return V_141 ;
}
static int F_78 ( struct V_57 * V_58 )
{
int V_143 , V_81 ;
T_4 V_144 ;
struct V_61 * V_62 = NULL ;
V_62 = F_28 ( sizeof( struct V_61 ) , V_83 ) ;
if ( ! V_62 )
return - V_120 ;
V_62 -> V_42 = - 1 ;
V_143 = F_79 ( V_145 , V_58 -> V_146 , L_5 , L_6 ,
& V_81 ) ;
if ( V_143 != 1 ) {
V_143 = - V_97 ;
F_80 ( V_58 , V_143 , L_7 ,
V_58 -> V_146 ) ;
goto error;
}
V_143 = F_79 ( V_145 , V_58 -> V_146 , L_8 , L_6 , & V_144 ) ;
if ( V_143 != 1 ) {
V_143 = - V_97 ;
F_80 ( V_58 , V_143 , L_9 ,
V_58 -> V_146 ) ;
goto error;
}
V_143 = F_81 ( V_58 -> V_87 , V_81 ) ;
if ( V_143 < 0 )
goto error;
V_62 -> V_42 = V_143 ;
V_143 = F_82 ( V_62 -> V_42 , NULL , F_77 ,
V_147 , L_10 , V_58 ) ;
if ( V_143 < 0 )
goto error;
V_143 = F_29 ( V_58 , & V_144 , 1 ,
( void * * ) & V_62 -> V_148 ) ;
if ( V_143 < 0 )
goto error;
F_83 ( & V_62 -> V_17 , V_62 -> V_148 , V_149 * 1 ) ;
V_62 -> V_58 = V_58 ;
F_84 ( & V_62 -> V_92 ) ;
F_85 ( & V_62 -> V_108 , V_83 ) ;
F_86 ( & V_62 -> V_90 , 1 ) ;
F_87 ( & V_58 -> V_58 , V_62 ) ;
F_35 ( & V_150 . V_151 ) ;
F_36 ( & V_62 -> V_91 , & V_150 . V_152 ) ;
F_37 ( & V_150 . V_151 ) ;
return 0 ;
error:
if ( V_62 -> V_42 >= 0 )
F_49 ( V_62 -> V_42 , V_58 ) ;
if ( V_62 -> V_148 != NULL )
F_48 ( V_58 , V_62 -> V_148 ) ;
F_50 ( V_62 ) ;
return V_143 ;
}
static int F_88 ( struct V_57 * V_58 )
{
struct V_61 * V_62 ;
struct V_2 * V_3 , * V_107 ;
struct V_105 * V_106 ;
struct V_153 V_154 ;
void * * V_155 ;
V_62 = F_22 ( & V_58 -> V_58 ) ;
F_35 ( & V_62 -> V_90 ) ;
F_55 (map, n, &fedata->socket_mappings, list) {
F_40 ( & V_3 -> V_91 ) ;
F_41 ( V_58 , V_62 , V_3 ) ;
}
F_89 (slot, &fedata->socketpass_mappings, &iter, 0 ) {
V_106 = F_90 ( V_155 ) ;
if ( ! V_106 )
continue;
if ( F_91 ( V_106 ) ) {
if ( F_92 ( V_106 ) )
V_155 = F_93 ( & V_154 ) ;
} else {
F_57 ( & V_62 -> V_108 ,
V_106 -> V_76 ) ;
F_51 ( V_58 , V_62 , V_106 ) ;
}
}
F_37 ( & V_62 -> V_90 ) ;
F_49 ( V_62 -> V_42 , V_58 ) ;
F_48 ( V_58 , V_62 -> V_148 ) ;
F_40 ( & V_62 -> V_91 ) ;
F_50 ( V_62 ) ;
F_87 ( & V_58 -> V_58 , NULL ) ;
return 0 ;
}
static int F_94 ( struct V_57 * V_58 ,
const struct V_156 * V_76 )
{
int V_143 , abort ;
struct V_157 V_158 ;
V_159:
abort = 1 ;
V_143 = F_95 ( & V_158 ) ;
if ( V_143 ) {
F_31 ( L_11 , V_85 ) ;
return V_143 ;
}
V_143 = F_96 ( V_158 , V_58 -> V_160 , L_12 , L_13 ,
V_161 ) ;
if ( V_143 ) {
F_31 ( L_14 , V_85 ) ;
goto abort;
}
V_143 = F_96 ( V_158 , V_58 -> V_160 , L_15 , L_6 ,
V_84 ) ;
if ( V_143 ) {
F_31 ( L_16 , V_85 ) ;
goto abort;
}
V_143 = F_96 ( V_158 , V_58 -> V_160 , L_17 ,
V_162 ) ;
if ( V_143 ) {
F_31 ( L_18 , V_85 ) ;
goto abort;
}
abort = 0 ;
abort:
V_143 = F_97 ( V_158 , abort ) ;
if ( V_143 ) {
if ( V_143 == - V_40 && ! abort )
goto V_159;
F_31 ( L_19 , V_85 ) ;
return V_143 ;
}
if ( abort )
return - V_104 ;
F_98 ( V_58 , V_163 ) ;
return 0 ;
}
static void F_99 ( struct V_57 * V_58 ,
enum V_164 V_165 )
{
while ( V_58 -> V_165 != V_165 ) {
switch ( V_58 -> V_165 ) {
case V_166 :
switch ( V_165 ) {
case V_163 :
case V_167 :
F_98 ( V_58 , V_163 ) ;
break;
case V_168 :
F_98 ( V_58 , V_168 ) ;
break;
default:
F_11 ( 1 ) ;
}
break;
case V_163 :
case V_169 :
switch ( V_165 ) {
case V_167 :
F_78 ( V_58 ) ;
F_98 ( V_58 , V_167 ) ;
break;
case V_168 :
case V_166 :
F_98 ( V_58 , V_168 ) ;
break;
default:
F_11 ( 1 ) ;
}
break;
case V_167 :
switch ( V_165 ) {
case V_163 :
case V_168 :
case V_166 :
F_35 ( & V_150 . V_151 ) ;
F_88 ( V_58 ) ;
F_37 ( & V_150 . V_151 ) ;
F_98 ( V_58 , V_168 ) ;
break;
default:
F_11 ( 1 ) ;
}
break;
case V_168 :
switch ( V_165 ) {
case V_163 :
case V_167 :
case V_166 :
F_98 ( V_58 , V_166 ) ;
break;
default:
F_11 ( 1 ) ;
}
break;
default:
F_11 ( 1 ) ;
}
}
}
static void F_100 ( struct V_57 * V_58 ,
enum V_164 V_170 )
{
switch ( V_170 ) {
case V_171 :
F_99 ( V_58 , V_163 ) ;
break;
case V_169 :
case V_167 :
F_99 ( V_58 , V_167 ) ;
break;
case V_168 :
F_99 ( V_58 , V_168 ) ;
break;
case V_166 :
F_99 ( V_58 , V_166 ) ;
if ( F_101 ( V_58 ) )
break;
F_102 ( & V_58 -> V_58 ) ;
break;
case V_172 :
F_99 ( V_58 , V_166 ) ;
F_102 ( & V_58 -> V_58 ) ;
break;
default:
F_80 ( V_58 , - V_97 , L_20 ,
V_170 ) ;
break;
}
}
static int F_103 ( struct V_57 * V_58 )
{
return 0 ;
}
static int F_104 ( struct V_57 * V_173 ,
struct V_174 * V_175 )
{
return 0 ;
}
static int T_7 F_105 ( void )
{
int V_21 ;
if ( ! F_106 () )
return - V_176 ;
V_21 = F_107 ( & V_177 ) ;
if ( V_21 < 0 )
return V_21 ;
F_86 ( & V_150 . V_151 , 1 ) ;
F_84 ( & V_150 . V_152 ) ;
return 0 ;
}
static void T_8 F_108 ( void )
{
struct V_61 * V_62 , * V_178 ;
F_35 ( & V_150 . V_151 ) ;
F_55 (fedata, nfedata,
&pvcalls_back_global.frontends, list) {
F_88 ( V_62 -> V_58 ) ;
}
F_37 ( & V_150 . V_151 ) ;
F_109 ( & V_177 ) ;
}
