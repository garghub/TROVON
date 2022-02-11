static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
int V_7 ;
int V_8 ;
F_2 ( & V_4 -> V_9 ) ;
if ( V_4 -> V_10 ) {
if ( F_3 ( V_4 -> V_11 -> V_12 ) ==
V_2 -> V_13 ) {
V_8 = - V_14 ;
goto V_15;
}
if ( ! V_4 -> V_16 ) {
V_4 -> V_16 = V_17 -> V_18 ;
V_4 -> V_19 = false ;
} else if ( V_4 -> V_16 != V_17 -> V_18 ) {
V_4 -> V_19 = true ;
}
F_4 ( & V_4 -> V_20 ) ;
F_4 ( & V_4 -> V_21 ) ;
if ( V_6 ) {
V_7 = V_4 -> V_22 % 2 ;
F_5 ( & V_6 -> V_23 , & V_4 -> V_24 [ V_7 ] ) ;
V_6 -> V_22 = V_4 -> V_22 ;
}
F_6 ( & V_4 -> V_9 ) ;
return 0 ;
}
V_8 = 0 ;
F_2 ( & V_4 -> V_11 -> V_25 ) ;
if ( ! V_4 -> V_11 -> V_26 )
V_8 = F_7 ( V_2 , V_4 -> V_11 ) ;
F_6 ( & V_4 -> V_11 -> V_25 ) ;
if ( V_8 )
goto V_15;
if ( ! V_4 -> V_10 ) {
V_8 = F_8 ( V_2 , V_4 ) ;
if ( V_8 )
goto V_15;
}
V_4 -> V_19 = false ;
V_4 -> V_16 = V_17 -> V_18 ;
F_4 ( & V_4 -> V_20 ) ;
F_4 ( & V_4 -> V_21 ) ;
if ( V_6 ) {
V_7 = V_4 -> V_22 % 2 ;
F_5 ( & V_6 -> V_23 , & V_4 -> V_24 [ V_7 ] ) ;
V_6 -> V_22 = V_4 -> V_22 ;
}
V_15:
F_6 ( & V_4 -> V_9 ) ;
return V_8 ;
}
static int F_9 ( struct V_3 * V_4 )
{
int V_8 = - V_27 ;
F_10 () ;
if ( ! V_4 -> V_10 )
return - V_27 ;
F_2 ( & V_4 -> V_9 ) ;
if ( V_4 -> V_10 ) {
V_8 = 0 ;
F_4 ( & V_4 -> V_21 ) ;
}
F_6 ( & V_4 -> V_9 ) ;
return V_8 ;
}
int F_11 ( struct V_3 * V_4 )
{
int V_8 = - V_27 ;
F_2 ( & V_4 -> V_9 ) ;
F_4 ( & V_4 -> V_21 ) ;
F_6 ( & V_4 -> V_9 ) ;
return V_8 ;
}
void F_12 ( struct V_3 * V_4 )
{
if ( F_13 ( & V_4 -> V_21 ) ) {
F_10 () ;
if ( F_14 ( & V_4 -> V_28 ) )
F_15 ( & V_4 -> V_28 ) ;
}
}
static int F_16 ( struct V_3 * log ,
struct V_29 * V_30 ,
struct V_31 * V_32 , T_1 V_33 )
{
int V_8 = 0 ;
if ( F_17 ( log -> V_11 , V_34 ) ) {
V_8 = F_18 ( V_30 , V_33 ) ;
if ( V_8 )
return V_8 ;
}
if ( V_32 -> V_35 )
V_8 = F_19 ( log -> V_11 -> V_36 ,
V_30 -> V_37 , V_30 -> V_38 ) ;
if ( ! V_8 && F_20 ( V_30 , V_33 , 0 ) ) {
if ( V_32 -> V_35 && F_21 ( V_30 ) == 0 )
V_8 = F_22 ( log , V_30 ) ;
if ( V_32 -> V_39 )
F_23 ( V_30 ) ;
if ( V_32 -> V_40 )
F_24 ( V_30 ) ;
}
return V_8 ;
}
static T_2 int F_25 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_41 * V_42 ,
struct V_29 * V_30 , int V_43 ,
struct V_44 * V_45 )
{
int V_8 ;
T_3 V_46 ;
T_1 V_47 = 0 ;
int V_48 = 0 ;
unsigned long V_49 ;
unsigned long V_50 ;
int V_51 = 0 ;
bool V_52 = V_45 -> type == V_53 ;
if ( V_4 -> V_54 . V_55 != V_56 )
V_51 = 1 ;
V_46 = F_26 ( V_30 , V_43 ) ;
V_49 = F_27 ( V_30 , V_43 ) ;
V_8 = F_28 ( NULL , V_4 , V_45 , V_42 , 0 , 0 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( V_8 == 0 ) {
char * V_57 ;
char * V_58 ;
T_3 V_59 = F_26 ( V_42 -> V_60 [ 0 ] ,
V_42 -> V_61 [ 0 ] ) ;
if ( V_59 != V_46 )
goto V_62;
if ( V_46 == 0 ) {
F_29 ( V_42 ) ;
return 0 ;
}
V_58 = F_30 ( V_46 , V_63 ) ;
V_57 = F_30 ( V_46 , V_63 ) ;
if ( ! V_58 || ! V_57 ) {
F_29 ( V_42 ) ;
F_31 ( V_58 ) ;
F_31 ( V_57 ) ;
return - V_64 ;
}
F_32 ( V_30 , V_57 , V_49 , V_46 ) ;
V_50 = F_27 ( V_42 -> V_60 [ 0 ] , V_42 -> V_61 [ 0 ] ) ;
F_32 ( V_42 -> V_60 [ 0 ] , V_58 , V_50 ,
V_46 ) ;
V_8 = memcmp ( V_58 , V_57 , V_46 ) ;
F_31 ( V_58 ) ;
F_31 ( V_57 ) ;
if ( V_8 == 0 ) {
F_29 ( V_42 ) ;
return 0 ;
}
if ( V_52 ) {
struct V_65 * V_66 ;
T_1 V_67 ;
T_3 V_68 ;
V_66 = F_33 ( V_42 -> V_60 [ 0 ] , V_42 -> V_61 [ 0 ] ,
struct V_65 ) ;
V_67 = F_34 ( V_42 -> V_60 [ 0 ] , V_66 ) ;
V_66 = F_33 ( V_30 , V_43 ,
struct V_65 ) ;
F_35 ( V_30 , V_66 , V_67 ) ;
V_68 = F_36 ( V_30 , V_66 ) ;
if ( F_37 ( V_68 ) )
F_38 ( V_30 , V_66 , 0 ) ;
}
} else if ( V_52 ) {
struct V_65 * V_66 ;
T_3 V_68 ;
V_66 = F_33 ( V_30 , V_43 , struct V_65 ) ;
F_35 ( V_30 , V_66 , 0 ) ;
V_68 = F_36 ( V_30 , V_66 ) ;
if ( F_37 ( V_68 ) )
F_38 ( V_30 , V_66 , 0 ) ;
}
V_62:
F_29 ( V_42 ) ;
V_8 = F_39 ( V_2 , V_4 , V_42 ,
V_45 , V_46 ) ;
if ( V_8 == - V_69 ) {
T_3 V_70 ;
V_70 = F_26 ( V_42 -> V_60 [ 0 ] ,
V_42 -> V_61 [ 0 ] ) ;
if ( V_70 > V_46 )
F_40 ( V_4 , V_42 , V_46 , 1 ) ;
else if ( V_70 < V_46 )
F_41 ( V_4 , V_42 ,
V_46 - V_70 ) ;
} else if ( V_8 ) {
return V_8 ;
}
V_50 = F_27 ( V_42 -> V_60 [ 0 ] ,
V_42 -> V_61 [ 0 ] ) ;
if ( V_45 -> type == V_53 && V_8 == - V_69 ) {
struct V_65 * V_71 ;
struct V_65 * V_72 ;
V_71 = (struct V_65 * ) V_49 ;
V_72 = (struct V_65 * ) V_50 ;
if ( F_42 ( V_30 , V_71 ) == 0 )
goto V_73;
if ( V_51 &&
F_37 ( F_36 ( V_30 , V_71 ) ) &&
F_37 ( F_36 ( V_42 -> V_60 [ 0 ] , V_72 ) ) ) {
V_48 = 1 ;
V_47 = F_43 ( V_42 -> V_60 [ 0 ] ,
V_72 ) ;
}
}
F_44 ( V_42 -> V_60 [ 0 ] , V_30 , V_50 ,
V_49 , V_46 ) ;
if ( V_48 ) {
struct V_65 * V_72 ;
V_72 = (struct V_65 * ) V_50 ;
F_38 ( V_42 -> V_60 [ 0 ] , V_72 , V_47 ) ;
}
if ( V_45 -> type == V_53 ) {
struct V_65 * V_72 ;
V_72 = (struct V_65 * ) V_50 ;
if ( F_42 ( V_42 -> V_60 [ 0 ] , V_72 ) == 0 ) {
F_45 ( V_42 -> V_60 [ 0 ] , V_72 ,
V_2 -> V_13 ) ;
}
}
V_73:
F_46 ( V_42 -> V_60 [ 0 ] ) ;
F_29 ( V_42 ) ;
return 0 ;
}
T_2 int F_47 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_41 * V_42 ,
struct V_29 * V_30 , int V_43 ,
struct V_44 * V_45 )
{
int V_74 ;
T_1 V_75 ;
T_1 V_37 = V_45 -> V_76 ;
T_1 V_67 = 0 ;
struct V_77 * V_66 ;
struct V_78 * V_78 = NULL ;
unsigned long V_79 ;
int V_8 = 0 ;
V_66 = F_33 ( V_30 , V_43 , struct V_77 ) ;
V_74 = F_48 ( V_30 , V_66 ) ;
if ( V_74 == V_80 ||
V_74 == V_81 ) {
V_67 = F_49 ( V_30 , V_66 ) ;
V_75 = V_37 + V_67 ;
if ( F_50 ( V_30 , V_66 ) == 0 )
V_67 = 0 ;
} else if ( V_74 == V_82 ) {
V_79 = F_51 ( V_30 , V_43 , V_66 ) ;
V_67 = F_52 ( V_30 , V_66 ) ;
V_75 = F_53 ( V_37 + V_79 , V_4 -> V_83 ) ;
} else {
V_8 = 0 ;
goto V_15;
}
V_78 = F_54 ( V_4 , V_45 -> V_55 ) ;
if ( ! V_78 ) {
V_8 = - V_84 ;
goto V_15;
}
V_8 = F_55 ( V_2 , V_4 , V_42 , F_56 ( V_78 ) ,
V_37 , 0 ) ;
if ( V_8 == 0 &&
( V_74 == V_80 ||
V_74 == V_81 ) ) {
struct V_77 V_85 ;
struct V_77 V_86 ;
struct V_77 * V_87 ;
struct V_29 * V_88 ;
V_88 = V_42 -> V_60 [ 0 ] ;
V_87 = F_33 ( V_88 , V_42 -> V_61 [ 0 ] ,
struct V_77 ) ;
F_32 ( V_30 , & V_85 , ( unsigned long ) V_66 ,
sizeof( V_85 ) ) ;
F_32 ( V_88 , & V_86 , ( unsigned long ) V_87 ,
sizeof( V_86 ) ) ;
if ( memcmp ( & V_85 , & V_86 , sizeof( V_85 ) ) == 0 ) {
F_29 ( V_42 ) ;
goto V_15;
}
}
F_29 ( V_42 ) ;
V_8 = F_57 ( V_2 , V_4 , V_78 , V_37 , V_75 , 1 ) ;
if ( V_8 )
goto V_15;
if ( V_74 == V_80 ||
V_74 == V_81 ) {
T_1 V_76 ;
unsigned long V_89 ;
struct V_44 V_90 ;
V_8 = F_39 ( V_2 , V_4 , V_42 , V_45 ,
sizeof( * V_66 ) ) ;
if ( V_8 )
goto V_15;
V_89 = F_27 ( V_42 -> V_60 [ 0 ] ,
V_42 -> V_61 [ 0 ] ) ;
F_44 ( V_42 -> V_60 [ 0 ] , V_30 , V_89 ,
( unsigned long ) V_66 , sizeof( * V_66 ) ) ;
V_90 . V_55 = F_50 ( V_30 , V_66 ) ;
V_90 . V_76 = F_58 ( V_30 , V_66 ) ;
V_90 . type = V_91 ;
V_76 = V_45 -> V_76 - F_59 ( V_30 , V_66 ) ;
if ( V_90 . V_55 > 0 ) {
T_1 V_92 ;
T_1 V_93 ;
F_60 ( V_94 ) ;
V_8 = F_61 ( V_4 , V_90 . V_55 ,
V_90 . V_76 ) ;
if ( V_8 == 0 ) {
V_8 = F_62 ( V_2 , V_4 ,
V_90 . V_55 , V_90 . V_76 ,
0 , V_4 -> V_54 . V_55 ,
V_45 -> V_55 , V_76 , 0 ) ;
if ( V_8 )
goto V_15;
} else {
V_8 = F_63 ( V_2 ,
V_4 , V_4 -> V_54 . V_55 ,
V_45 -> V_55 , V_76 , & V_90 ) ;
if ( V_8 )
goto V_15;
}
F_29 ( V_42 ) ;
if ( F_64 ( V_30 , V_66 ) ) {
V_92 = V_90 . V_55 ;
V_93 = V_92 + V_90 . V_76 ;
} else {
V_92 = V_90 . V_55 +
F_59 ( V_30 , V_66 ) ;
V_93 = V_92 +
F_49 ( V_30 , V_66 ) ;
}
V_8 = F_65 ( V_4 -> V_10 ,
V_92 , V_93 - 1 ,
& V_94 , 0 ) ;
if ( V_8 )
goto V_15;
while ( ! F_66 ( & V_94 ) ) {
struct V_95 * V_96 ;
V_96 = F_67 ( V_94 . V_97 ,
struct V_95 ,
V_23 ) ;
if ( ! V_8 )
V_8 = F_68 ( V_2 ,
V_4 -> V_11 -> V_98 ,
V_96 ) ;
F_69 ( & V_96 -> V_23 ) ;
F_31 ( V_96 ) ;
}
if ( V_8 )
goto V_15;
} else {
F_29 ( V_42 ) ;
}
} else if ( V_74 == V_82 ) {
V_8 = F_25 ( V_2 , V_4 , V_42 , V_30 , V_43 , V_45 ) ;
if ( V_8 )
goto V_15;
}
F_70 ( V_78 , V_67 ) ;
V_8 = F_71 ( V_2 , V_4 , V_78 ) ;
V_15:
if ( V_78 )
F_72 ( V_78 ) ;
return V_8 ;
}
static T_2 int F_73 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_41 * V_42 ,
struct V_78 * V_99 ,
struct V_100 * V_101 )
{
struct V_78 * V_78 ;
char * V_102 ;
int V_103 ;
struct V_29 * V_88 ;
struct V_44 V_104 ;
int V_8 ;
V_88 = V_42 -> V_60 [ 0 ] ;
F_74 ( V_88 , V_101 , & V_104 ) ;
V_103 = F_75 ( V_88 , V_101 ) ;
V_102 = F_30 ( V_103 , V_63 ) ;
if ( ! V_102 )
return - V_64 ;
F_32 ( V_88 , V_102 , ( unsigned long ) ( V_101 + 1 ) , V_103 ) ;
F_29 ( V_42 ) ;
V_78 = F_54 ( V_4 , V_104 . V_55 ) ;
if ( ! V_78 ) {
V_8 = - V_84 ;
goto V_15;
}
V_8 = F_76 ( V_2 , V_4 , V_42 , V_104 . V_55 ) ;
if ( V_8 )
goto V_15;
V_8 = F_77 ( V_2 , V_4 , V_99 , V_78 , V_102 , V_103 ) ;
if ( V_8 )
goto V_15;
else
V_8 = F_78 ( V_2 , V_4 ) ;
V_15:
F_31 ( V_102 ) ;
F_72 ( V_78 ) ;
return V_8 ;
}
static T_2 int F_79 ( struct V_3 * V_4 ,
struct V_41 * V_42 ,
T_1 V_105 , T_1 V_55 , T_1 V_7 ,
const char * V_102 , int V_103 )
{
struct V_100 * V_101 ;
struct V_44 V_104 ;
int V_106 = 0 ;
V_101 = F_80 ( NULL , V_4 , V_42 , V_105 ,
V_7 , V_102 , V_103 , 0 ) ;
if ( V_101 && ! F_81 ( V_101 ) ) {
F_74 ( V_42 -> V_60 [ 0 ] , V_101 , & V_104 ) ;
if ( V_104 . V_55 != V_55 )
goto V_15;
} else
goto V_15;
F_29 ( V_42 ) ;
V_101 = F_82 ( NULL , V_4 , V_42 , V_105 , V_102 , V_103 , 0 ) ;
if ( V_101 && ! F_81 ( V_101 ) ) {
F_74 ( V_42 -> V_60 [ 0 ] , V_101 , & V_104 ) ;
if ( V_104 . V_55 != V_55 )
goto V_15;
} else
goto V_15;
V_106 = 1 ;
V_15:
F_29 ( V_42 ) ;
return V_106 ;
}
static T_2 int F_83 ( struct V_3 * log ,
struct V_44 * V_45 ,
T_1 V_107 ,
char * V_102 , int V_108 )
{
struct V_41 * V_42 ;
struct V_109 * V_110 ;
unsigned long V_111 ;
unsigned long V_112 ;
unsigned long V_113 ;
int V_114 ;
int V_46 ;
int V_8 ;
int V_106 = 0 ;
V_42 = F_84 () ;
if ( ! V_42 )
return - V_64 ;
V_8 = F_28 ( NULL , log , V_45 , V_42 , 0 , 0 ) ;
if ( V_8 != 0 )
goto V_15;
V_111 = F_27 ( V_42 -> V_60 [ 0 ] , V_42 -> V_61 [ 0 ] ) ;
if ( V_45 -> type == V_115 ) {
if ( F_85 ( V_42 , V_107 ,
V_102 , V_108 , NULL ) )
V_106 = 1 ;
goto V_15;
}
V_46 = F_26 ( V_42 -> V_60 [ 0 ] , V_42 -> V_61 [ 0 ] ) ;
V_112 = V_111 + V_46 ;
while ( V_111 < V_112 ) {
V_110 = (struct V_109 * ) V_111 ;
V_114 = F_86 ( V_42 -> V_60 [ 0 ] , V_110 ) ;
if ( V_114 == V_108 ) {
V_113 = ( unsigned long ) ( V_110 + 1 ) ;
V_8 = F_87 ( V_42 -> V_60 [ 0 ] , V_102 ,
V_113 , V_108 ) ;
if ( V_8 == 0 ) {
V_106 = 1 ;
goto V_15;
}
}
V_111 = ( unsigned long ) ( V_110 + 1 ) + V_114 ;
}
V_15:
F_88 ( V_42 ) ;
return V_106 ;
}
static inline int F_89 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_41 * V_42 ,
struct V_3 * V_10 ,
struct V_78 * V_99 , struct V_78 * V_78 ,
struct V_29 * V_30 ,
T_1 V_116 , T_1 V_117 ,
T_1 V_118 , char * V_102 , int V_108 ,
int * V_119 )
{
int V_8 ;
char * V_120 ;
int V_121 ;
struct V_29 * V_88 ;
struct V_100 * V_101 ;
struct V_44 V_122 ;
struct V_123 * V_124 ;
V_125:
V_122 . V_55 = V_116 ;
V_122 . type = V_126 ;
V_122 . V_76 = V_117 ;
V_8 = F_28 ( NULL , V_4 , & V_122 , V_42 , 0 , 0 ) ;
if ( V_8 == 0 ) {
struct V_109 * V_127 ;
unsigned long V_111 ;
unsigned long V_112 ;
V_88 = V_42 -> V_60 [ 0 ] ;
if ( V_122 . V_55 == V_122 . V_76 )
return 1 ;
V_111 = F_27 ( V_88 , V_42 -> V_61 [ 0 ] ) ;
V_112 = V_111 + F_26 ( V_88 , V_42 -> V_61 [ 0 ] ) ;
while ( V_111 < V_112 ) {
V_127 = (struct V_109 * ) V_111 ;
V_121 = F_86 ( V_88 ,
V_127 ) ;
V_120 = F_30 ( V_121 , V_63 ) ;
if ( ! V_120 )
return - V_64 ;
F_32 ( V_88 , V_120 ,
( unsigned long ) ( V_127 + 1 ) ,
V_121 ) ;
if ( ! F_83 ( V_10 , & V_122 ,
V_117 ,
V_120 ,
V_121 ) ) {
F_90 ( V_78 ) ;
F_29 ( V_42 ) ;
V_8 = F_77 ( V_2 , V_4 , V_99 ,
V_78 , V_120 ,
V_121 ) ;
F_31 ( V_120 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_78 ( V_2 , V_4 ) ;
if ( V_8 )
return V_8 ;
* V_119 = 1 ;
goto V_125;
}
F_31 ( V_120 ) ;
V_111 = ( unsigned long ) ( V_127 + 1 ) + V_121 ;
}
* V_119 = 1 ;
}
F_29 ( V_42 ) ;
V_124 = F_91 ( NULL , V_4 , V_42 , V_102 , V_108 ,
V_116 , V_117 , 0 ,
0 ) ;
if ( ! F_92 ( V_124 ) ) {
T_3 V_46 ;
T_3 V_128 = 0 ;
unsigned long V_129 ;
struct V_78 * V_130 ;
V_88 = V_42 -> V_60 [ 0 ] ;
V_46 = F_26 ( V_88 , V_42 -> V_61 [ 0 ] ) ;
V_129 = F_27 ( V_88 , V_42 -> V_61 [ 0 ] ) ;
while ( V_128 < V_46 ) {
V_124 = (struct V_123 * ) V_129 + V_128 ;
V_121 = F_93 ( V_88 , V_124 ) ;
if ( F_94 ( V_88 , V_124 ) != V_117 )
goto V_97;
V_120 = F_30 ( V_121 , V_63 ) ;
if ( ! V_120 )
return - V_64 ;
F_32 ( V_88 , V_120 , ( unsigned long ) & V_124 -> V_102 ,
V_121 ) ;
V_122 . V_55 = V_116 ;
V_122 . type = V_115 ;
V_122 . V_76 = F_95 ( V_117 ,
V_120 ,
V_121 ) ;
V_8 = 0 ;
if ( ! F_83 ( V_10 , & V_122 ,
V_117 , V_120 ,
V_121 ) ) {
V_8 = - V_27 ;
V_130 = F_54 ( V_4 ,
V_117 ) ;
if ( V_130 ) {
F_90 ( V_78 ) ;
F_29 ( V_42 ) ;
V_8 = F_77 ( V_2 , V_4 ,
V_130 ,
V_78 ,
V_120 ,
V_121 ) ;
if ( ! V_8 )
V_8 = F_78 (
V_2 , V_4 ) ;
}
F_72 ( V_130 ) ;
F_31 ( V_120 ) ;
if ( V_8 )
return V_8 ;
* V_119 = 1 ;
goto V_125;
}
F_31 ( V_120 ) ;
if ( V_8 )
return V_8 ;
V_97:
V_128 += V_121 + sizeof( * V_124 ) ;
}
* V_119 = 1 ;
}
F_29 ( V_42 ) ;
V_101 = F_80 ( V_2 , V_4 , V_42 , F_56 ( V_99 ) ,
V_118 , V_102 , V_108 , 0 ) ;
if ( V_101 && ! F_81 ( V_101 ) ) {
V_8 = F_73 ( V_2 , V_4 , V_42 , V_99 , V_101 ) ;
if ( V_8 )
return V_8 ;
}
F_29 ( V_42 ) ;
V_101 = F_82 ( V_2 , V_4 , V_42 , F_56 ( V_99 ) ,
V_102 , V_108 , 0 ) ;
if ( V_101 && ! F_81 ( V_101 ) ) {
V_8 = F_73 ( V_2 , V_4 , V_42 , V_99 , V_101 ) ;
if ( V_8 )
return V_8 ;
}
F_29 ( V_42 ) ;
return 0 ;
}
static int F_96 ( struct V_29 * V_30 , unsigned long V_131 ,
T_3 * V_108 , char * * V_102 , T_1 * V_7 ,
T_1 * V_117 )
{
struct V_123 * V_124 ;
V_124 = (struct V_123 * ) V_131 ;
* V_108 = F_93 ( V_30 , V_124 ) ;
* V_102 = F_30 ( * V_108 , V_63 ) ;
if ( * V_102 == NULL )
return - V_64 ;
F_32 ( V_30 , * V_102 , ( unsigned long ) & V_124 -> V_102 ,
* V_108 ) ;
* V_7 = F_97 ( V_30 , V_124 ) ;
if ( V_117 )
* V_117 = F_94 ( V_30 , V_124 ) ;
return 0 ;
}
static int F_98 ( struct V_29 * V_30 , unsigned long V_131 ,
T_3 * V_108 , char * * V_102 , T_1 * V_7 )
{
struct V_109 * V_110 ;
V_110 = (struct V_109 * ) V_131 ;
* V_108 = F_86 ( V_30 , V_110 ) ;
* V_102 = F_30 ( * V_108 , V_63 ) ;
if ( * V_102 == NULL )
return - V_64 ;
F_32 ( V_30 , * V_102 , ( unsigned long ) ( V_110 + 1 ) , * V_108 ) ;
* V_7 = F_99 ( V_30 , V_110 ) ;
return 0 ;
}
static T_2 int F_100 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_3 * log ,
struct V_41 * V_42 ,
struct V_29 * V_30 , int V_43 ,
struct V_44 * V_45 )
{
struct V_78 * V_99 = NULL ;
struct V_78 * V_78 = NULL ;
unsigned long V_131 ;
unsigned long V_132 ;
char * V_102 = NULL ;
int V_108 ;
int V_8 ;
int V_119 = 0 ;
int V_133 = 0 ;
T_1 V_117 ;
T_1 V_116 ;
T_1 V_118 = 0 ;
int V_134 ;
V_131 = F_27 ( V_30 , V_43 ) ;
V_132 = V_131 + F_26 ( V_30 , V_43 ) ;
if ( V_45 -> type == V_115 ) {
struct V_123 * V_135 ;
V_134 = sizeof( struct V_123 ) ;
V_133 = 1 ;
V_135 = (struct V_123 * ) V_131 ;
V_117 = F_94 ( V_30 , V_135 ) ;
} else {
V_134 = sizeof( struct V_109 ) ;
V_117 = V_45 -> V_76 ;
}
V_116 = V_45 -> V_55 ;
V_99 = F_54 ( V_4 , V_117 ) ;
if ( ! V_99 ) {
V_8 = - V_27 ;
goto V_15;
}
V_78 = F_54 ( V_4 , V_116 ) ;
if ( ! V_78 ) {
V_8 = - V_84 ;
goto V_15;
}
while ( V_131 < V_132 ) {
if ( V_133 ) {
V_8 = F_96 ( V_30 , V_131 , & V_108 , & V_102 ,
& V_118 , & V_117 ) ;
if ( ! V_99 )
V_99 = F_54 ( V_4 , V_117 ) ;
if ( ! V_99 ) {
V_8 = - V_27 ;
goto V_15;
}
} else {
V_8 = F_98 ( V_30 , V_131 , & V_108 , & V_102 ,
& V_118 ) ;
}
if ( V_8 )
goto V_15;
if ( ! F_79 ( V_4 , V_42 , F_56 ( V_99 ) , F_56 ( V_78 ) ,
V_118 , V_102 , V_108 ) ) {
if ( ! V_119 ) {
V_8 = F_89 ( V_2 , V_4 , V_42 , log ,
V_99 , V_78 , V_30 ,
V_116 ,
V_117 ,
V_118 , V_102 , V_108 ,
& V_119 ) ;
if ( V_8 ) {
if ( V_8 == 1 )
V_8 = 0 ;
goto V_15;
}
}
V_8 = F_101 ( V_2 , V_99 , V_78 , V_102 , V_108 ,
0 , V_118 ) ;
if ( V_8 )
goto V_15;
F_71 ( V_2 , V_4 , V_78 ) ;
}
V_131 = ( unsigned long ) ( V_131 + V_134 ) + V_108 ;
F_31 ( V_102 ) ;
V_102 = NULL ;
if ( V_133 ) {
F_72 ( V_99 ) ;
V_99 = NULL ;
}
}
V_8 = F_25 ( V_2 , V_4 , V_42 , V_30 , V_43 , V_45 ) ;
V_15:
F_29 ( V_42 ) ;
F_31 ( V_102 ) ;
F_72 ( V_99 ) ;
F_72 ( V_78 ) ;
return V_8 ;
}
static int F_102 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_1 V_76 )
{
int V_8 ;
V_8 = F_103 ( V_4 , NULL , V_136 ,
V_76 , V_137 , NULL ) ;
if ( V_8 > 0 )
V_8 = F_104 ( V_2 , V_4 , V_76 ) ;
return V_8 ;
}
static int F_105 ( struct V_3 * V_4 ,
struct V_78 * V_78 , struct V_41 * V_42 )
{
int V_8 = 0 ;
int V_103 ;
unsigned int V_138 = 0 ;
T_3 V_46 ;
T_3 V_128 = 0 ;
T_1 V_116 = F_56 ( V_78 ) ;
T_1 V_76 = 0 ;
unsigned long V_111 ;
struct V_123 * V_124 ;
struct V_29 * V_88 ;
while ( 1 ) {
V_8 = F_106 ( V_4 , V_116 , V_76 , V_42 ,
& V_124 , & V_76 ) ;
if ( V_8 )
break;
V_88 = V_42 -> V_60 [ 0 ] ;
V_46 = F_26 ( V_88 , V_42 -> V_61 [ 0 ] ) ;
V_111 = F_27 ( V_88 , V_42 -> V_61 [ 0 ] ) ;
while ( V_128 < V_46 ) {
V_124 = (struct V_123 * ) ( V_111 + V_128 ) ;
V_103 = F_93 ( V_88 , V_124 ) ;
V_138 ++ ;
V_128 += V_103 + sizeof( * V_124 ) ;
}
V_76 ++ ;
F_29 ( V_42 ) ;
}
F_29 ( V_42 ) ;
if ( V_8 < 0 )
return V_8 ;
return V_138 ;
}
static int F_107 ( struct V_3 * V_4 ,
struct V_78 * V_78 , struct V_41 * V_42 )
{
int V_8 ;
struct V_44 V_45 ;
unsigned int V_138 = 0 ;
unsigned long V_111 ;
unsigned long V_112 ;
int V_103 ;
T_1 V_139 = F_56 ( V_78 ) ;
V_45 . V_55 = V_139 ;
V_45 . type = V_126 ;
V_45 . V_76 = ( T_1 ) - 1 ;
while ( 1 ) {
V_8 = F_28 ( NULL , V_4 , & V_45 , V_42 , 0 , 0 ) ;
if ( V_8 < 0 )
break;
if ( V_8 > 0 ) {
if ( V_42 -> V_61 [ 0 ] == 0 )
break;
V_42 -> V_61 [ 0 ] -- ;
}
V_140:
F_108 ( V_42 -> V_60 [ 0 ] , & V_45 ,
V_42 -> V_61 [ 0 ] ) ;
if ( V_45 . V_55 != V_139 ||
V_45 . type != V_126 )
break;
V_111 = F_27 ( V_42 -> V_60 [ 0 ] , V_42 -> V_61 [ 0 ] ) ;
V_112 = V_111 + F_26 ( V_42 -> V_60 [ 0 ] ,
V_42 -> V_61 [ 0 ] ) ;
while ( V_111 < V_112 ) {
struct V_109 * V_110 ;
V_110 = (struct V_109 * ) V_111 ;
V_103 = F_86 ( V_42 -> V_60 [ 0 ] ,
V_110 ) ;
V_111 = ( unsigned long ) ( V_110 + 1 ) + V_103 ;
V_138 ++ ;
}
if ( V_45 . V_76 == 0 )
break;
if ( V_42 -> V_61 [ 0 ] > 0 ) {
V_42 -> V_61 [ 0 ] -- ;
goto V_140;
}
V_45 . V_76 -- ;
F_29 ( V_42 ) ;
}
F_29 ( V_42 ) ;
return V_138 ;
}
static T_2 int F_109 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_78 * V_78 )
{
struct V_41 * V_42 ;
int V_8 ;
T_1 V_138 = 0 ;
T_1 V_139 = F_56 ( V_78 ) ;
V_42 = F_84 () ;
if ( ! V_42 )
return - V_64 ;
V_8 = F_107 ( V_4 , V_78 , V_42 ) ;
if ( V_8 < 0 )
goto V_15;
V_138 = V_8 ;
V_8 = F_105 ( V_4 , V_78 , V_42 ) ;
if ( V_8 == - V_27 )
V_8 = 0 ;
if ( V_8 < 0 )
goto V_15;
V_138 += V_8 ;
V_8 = 0 ;
if ( V_138 != V_78 -> V_141 ) {
F_110 ( V_78 , V_138 ) ;
F_71 ( V_2 , V_4 , V_78 ) ;
}
F_111 ( V_78 ) -> V_142 = ( T_1 ) - 1 ;
if ( V_78 -> V_141 == 0 ) {
if ( F_37 ( V_78 -> V_143 ) ) {
V_8 = F_112 ( V_2 , V_4 , NULL , V_42 ,
V_139 , 1 ) ;
if ( V_8 )
goto V_15;
}
V_8 = F_102 ( V_2 , V_4 , V_139 ) ;
}
V_15:
F_88 ( V_42 ) ;
return V_8 ;
}
static T_2 int F_113 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_41 * V_42 )
{
int V_8 ;
struct V_44 V_45 ;
struct V_78 * V_78 ;
V_45 . V_55 = V_144 ;
V_45 . type = V_137 ;
V_45 . V_76 = ( T_1 ) - 1 ;
while ( 1 ) {
V_8 = F_28 ( V_2 , V_4 , & V_45 , V_42 , - 1 , 1 ) ;
if ( V_8 < 0 )
break;
if ( V_8 == 1 ) {
if ( V_42 -> V_61 [ 0 ] == 0 )
break;
V_42 -> V_61 [ 0 ] -- ;
}
F_108 ( V_42 -> V_60 [ 0 ] , & V_45 , V_42 -> V_61 [ 0 ] ) ;
if ( V_45 . V_55 != V_144 ||
V_45 . type != V_137 )
break;
V_8 = F_114 ( V_2 , V_4 , V_42 ) ;
if ( V_8 )
goto V_15;
F_29 ( V_42 ) ;
V_78 = F_54 ( V_4 , V_45 . V_76 ) ;
if ( ! V_78 )
return - V_84 ;
V_8 = F_109 ( V_2 , V_4 , V_78 ) ;
F_72 ( V_78 ) ;
if ( V_8 )
goto V_15;
V_45 . V_76 = ( T_1 ) - 1 ;
}
V_8 = 0 ;
V_15:
F_29 ( V_42 ) ;
return V_8 ;
}
static T_2 int F_76 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_41 * V_42 ,
T_1 V_55 )
{
struct V_44 V_45 ;
int V_8 = 0 ;
struct V_78 * V_78 ;
V_78 = F_54 ( V_4 , V_55 ) ;
if ( ! V_78 )
return - V_84 ;
V_45 . V_55 = V_144 ;
F_115 ( & V_45 , V_137 ) ;
V_45 . V_76 = V_55 ;
V_8 = F_39 ( V_2 , V_4 , V_42 , & V_45 , 0 ) ;
F_29 ( V_42 ) ;
if ( V_8 == 0 ) {
if ( ! V_78 -> V_141 )
F_110 ( V_78 , 1 ) ;
else
F_90 ( V_78 ) ;
V_8 = F_71 ( V_2 , V_4 , V_78 ) ;
} else if ( V_8 == - V_69 ) {
V_8 = 0 ;
} else {
F_116 () ;
}
F_72 ( V_78 ) ;
return V_8 ;
}
static T_2 int F_117 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_41 * V_42 ,
T_1 V_105 , T_1 V_7 ,
char * V_102 , int V_103 , T_4 type ,
struct V_44 * V_104 )
{
struct V_78 * V_78 ;
struct V_78 * V_99 ;
int V_8 ;
V_78 = F_54 ( V_4 , V_104 -> V_55 ) ;
if ( ! V_78 )
return - V_27 ;
V_99 = F_54 ( V_4 , V_105 ) ;
if ( ! V_99 ) {
F_72 ( V_78 ) ;
return - V_84 ;
}
V_8 = F_101 ( V_2 , V_99 , V_78 , V_102 , V_103 , 1 , V_7 ) ;
F_72 ( V_78 ) ;
F_72 ( V_99 ) ;
return V_8 ;
}
static T_2 int F_118 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_41 * V_42 ,
struct V_29 * V_30 ,
struct V_100 * V_101 ,
struct V_44 * V_45 )
{
char * V_102 ;
int V_103 ;
struct V_100 * V_145 ;
struct V_44 V_146 ;
struct V_44 V_147 ;
struct V_78 * V_99 ;
T_4 V_148 ;
int V_149 ;
int V_8 = 0 ;
bool V_150 = ( V_45 -> type == V_151 ) ;
V_99 = F_54 ( V_4 , V_45 -> V_55 ) ;
if ( ! V_99 )
return - V_84 ;
V_103 = F_75 ( V_30 , V_101 ) ;
V_102 = F_30 ( V_103 , V_63 ) ;
if ( ! V_102 ) {
V_8 = - V_64 ;
goto V_15;
}
V_148 = F_119 ( V_30 , V_101 ) ;
F_32 ( V_30 , V_102 , ( unsigned long ) ( V_101 + 1 ) ,
V_103 ) ;
F_74 ( V_30 , V_101 , & V_147 ) ;
V_149 = F_120 ( V_2 , V_4 , V_42 , & V_147 , 0 ) ;
if ( V_149 == 0 )
V_149 = 1 ;
else
V_149 = 0 ;
F_29 ( V_42 ) ;
if ( V_45 -> type == V_152 ) {
V_145 = F_82 ( V_2 , V_4 , V_42 , V_45 -> V_55 ,
V_102 , V_103 , 1 ) ;
} else if ( V_45 -> type == V_151 ) {
V_145 = F_80 ( V_2 , V_4 , V_42 ,
V_45 -> V_55 ,
V_45 -> V_76 , V_102 ,
V_103 , 1 ) ;
} else {
V_8 = - V_153 ;
goto V_15;
}
if ( F_92 ( V_145 ) ) {
if ( V_45 -> type != V_151 )
goto V_15;
goto V_62;
}
F_74 ( V_42 -> V_60 [ 0 ] , V_145 , & V_146 ) ;
if ( V_146 . V_55 == V_147 . V_55 &&
V_146 . type == V_147 . type &&
V_146 . V_76 == V_147 . V_76 &&
F_119 ( V_42 -> V_60 [ 0 ] , V_145 ) == V_148 ) {
goto V_15;
}
if ( ! V_149 )
goto V_15;
V_8 = F_73 ( V_2 , V_4 , V_42 , V_99 , V_145 ) ;
if ( V_8 )
goto V_15;
if ( V_45 -> type == V_151 )
goto V_62;
V_15:
F_29 ( V_42 ) ;
if ( ! V_8 && V_150 ) {
F_121 ( V_99 , V_99 -> V_154 + V_103 * 2 ) ;
V_8 = F_71 ( V_2 , V_4 , V_99 ) ;
}
F_31 ( V_102 ) ;
F_72 ( V_99 ) ;
return V_8 ;
V_62:
F_29 ( V_42 ) ;
V_8 = F_117 ( V_2 , V_4 , V_42 , V_45 -> V_55 , V_45 -> V_76 ,
V_102 , V_103 , V_148 , & V_147 ) ;
if ( V_8 && V_8 != - V_27 )
goto V_15;
V_150 = false ;
V_8 = 0 ;
goto V_15;
}
static T_2 int F_122 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_41 * V_42 ,
struct V_29 * V_30 , int V_43 ,
struct V_44 * V_45 )
{
int V_8 ;
T_3 V_46 = F_26 ( V_30 , V_43 ) ;
struct V_100 * V_101 ;
int V_103 ;
unsigned long V_111 ;
unsigned long V_112 ;
V_111 = F_27 ( V_30 , V_43 ) ;
V_112 = V_111 + V_46 ;
while ( V_111 < V_112 ) {
V_101 = (struct V_100 * ) V_111 ;
if ( F_123 ( V_4 , V_30 , V_101 ) )
return - V_84 ;
V_103 = F_75 ( V_30 , V_101 ) ;
V_8 = F_118 ( V_2 , V_4 , V_42 , V_30 , V_101 , V_45 ) ;
if ( V_8 )
return V_8 ;
V_111 = ( unsigned long ) ( V_101 + 1 ) ;
V_111 += V_103 ;
}
return 0 ;
}
static T_2 int F_124 ( struct V_3 * V_4 ,
struct V_41 * V_42 ,
T_1 V_105 , int V_155 ,
T_1 * V_156 , T_1 * V_157 )
{
struct V_44 V_45 ;
T_1 V_158 ;
struct V_159 * V_66 ;
int V_8 ;
int V_160 ;
if ( * V_156 == ( T_1 ) - 1 )
return 1 ;
V_45 . V_55 = V_105 ;
V_45 . type = V_155 ;
V_45 . V_76 = * V_156 ;
V_8 = F_28 ( NULL , V_4 , & V_45 , V_42 , 0 , 0 ) ;
if ( V_8 < 0 )
goto V_15;
if ( V_8 > 0 ) {
if ( V_42 -> V_61 [ 0 ] == 0 )
goto V_15;
V_42 -> V_61 [ 0 ] -- ;
}
if ( V_8 != 0 )
F_108 ( V_42 -> V_60 [ 0 ] , & V_45 , V_42 -> V_61 [ 0 ] ) ;
if ( V_45 . type != V_155 || V_45 . V_55 != V_105 ) {
V_8 = 1 ;
goto V_97;
}
V_66 = F_33 ( V_42 -> V_60 [ 0 ] , V_42 -> V_61 [ 0 ] ,
struct V_159 ) ;
V_158 = F_125 ( V_42 -> V_60 [ 0 ] , V_66 ) ;
if ( * V_156 >= V_45 . V_76 && * V_156 <= V_158 ) {
V_8 = 0 ;
* V_156 = V_45 . V_76 ;
* V_157 = V_158 ;
goto V_15;
}
V_8 = 1 ;
V_97:
V_160 = F_126 ( V_42 -> V_60 [ 0 ] ) ;
if ( V_42 -> V_61 [ 0 ] >= V_160 ) {
V_8 = F_127 ( V_4 , V_42 ) ;
if ( V_8 )
goto V_15;
} else {
V_42 -> V_61 [ 0 ] ++ ;
}
F_108 ( V_42 -> V_60 [ 0 ] , & V_45 , V_42 -> V_61 [ 0 ] ) ;
if ( V_45 . type != V_155 || V_45 . V_55 != V_105 ) {
V_8 = 1 ;
goto V_15;
}
V_66 = F_33 ( V_42 -> V_60 [ 0 ] , V_42 -> V_61 [ 0 ] ,
struct V_159 ) ;
V_158 = F_125 ( V_42 -> V_60 [ 0 ] , V_66 ) ;
* V_156 = V_45 . V_76 ;
* V_157 = V_158 ;
V_8 = 0 ;
V_15:
F_29 ( V_42 ) ;
return V_8 ;
}
static T_2 int F_128 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_3 * log ,
struct V_41 * V_42 ,
struct V_41 * V_161 ,
struct V_78 * V_99 ,
struct V_44 * V_162 )
{
int V_8 ;
struct V_29 * V_30 ;
int V_43 ;
T_3 V_46 ;
struct V_100 * V_101 ;
struct V_100 * V_163 ;
int V_103 ;
unsigned long V_111 ;
unsigned long V_112 ;
char * V_102 ;
struct V_78 * V_78 ;
struct V_44 V_104 ;
V_125:
V_30 = V_42 -> V_60 [ 0 ] ;
V_43 = V_42 -> V_61 [ 0 ] ;
V_46 = F_26 ( V_30 , V_43 ) ;
V_111 = F_27 ( V_30 , V_43 ) ;
V_112 = V_111 + V_46 ;
while ( V_111 < V_112 ) {
V_101 = (struct V_100 * ) V_111 ;
if ( F_123 ( V_4 , V_30 , V_101 ) ) {
V_8 = - V_84 ;
goto V_15;
}
V_103 = F_75 ( V_30 , V_101 ) ;
V_102 = F_30 ( V_103 , V_63 ) ;
if ( ! V_102 ) {
V_8 = - V_64 ;
goto V_15;
}
F_32 ( V_30 , V_102 , ( unsigned long ) ( V_101 + 1 ) ,
V_103 ) ;
V_163 = NULL ;
if ( log && V_162 -> type == V_152 ) {
V_163 = F_82 ( V_2 , log , V_161 ,
V_162 -> V_55 ,
V_102 , V_103 , 0 ) ;
} else if ( log && V_162 -> type == V_151 ) {
V_163 = F_80 ( V_2 , log ,
V_161 ,
V_162 -> V_55 ,
V_162 -> V_76 ,
V_102 , V_103 , 0 ) ;
}
if ( ! V_163 || ( F_81 ( V_163 ) && F_129 ( V_163 ) == - V_27 ) ) {
F_74 ( V_30 , V_101 , & V_104 ) ;
F_29 ( V_42 ) ;
F_29 ( V_161 ) ;
V_78 = F_54 ( V_4 , V_104 . V_55 ) ;
if ( ! V_78 ) {
F_31 ( V_102 ) ;
return - V_84 ;
}
V_8 = F_76 ( V_2 , V_4 ,
V_42 , V_104 . V_55 ) ;
if ( V_8 ) {
F_31 ( V_102 ) ;
F_72 ( V_78 ) ;
goto V_15;
}
F_90 ( V_78 ) ;
V_8 = F_77 ( V_2 , V_4 , V_99 , V_78 ,
V_102 , V_103 ) ;
if ( ! V_8 )
V_8 = F_78 ( V_2 , V_4 ) ;
F_31 ( V_102 ) ;
F_72 ( V_78 ) ;
if ( V_8 )
goto V_15;
V_8 = F_28 ( NULL , V_4 , V_162 , V_42 ,
0 , 0 ) ;
if ( V_8 == 0 )
goto V_125;
V_8 = 0 ;
goto V_15;
} else if ( F_81 ( V_163 ) ) {
F_31 ( V_102 ) ;
return F_129 ( V_163 ) ;
}
F_29 ( V_161 ) ;
F_31 ( V_102 ) ;
V_111 = ( unsigned long ) ( V_101 + 1 ) ;
V_111 += V_103 ;
}
V_8 = 0 ;
V_15:
F_29 ( V_42 ) ;
F_29 ( V_161 ) ;
return V_8 ;
}
static T_2 int F_112 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_3 * log ,
struct V_41 * V_42 ,
T_1 V_105 , int V_164 )
{
T_1 V_165 ;
T_1 V_166 ;
int V_155 = V_167 ;
int V_8 = 0 ;
struct V_44 V_162 ;
struct V_44 V_146 ;
struct V_41 * V_161 ;
struct V_78 * V_99 ;
V_162 . V_55 = V_105 ;
V_162 . type = V_152 ;
V_161 = F_84 () ;
if ( ! V_161 )
return - V_64 ;
V_99 = F_54 ( V_4 , V_105 ) ;
if ( ! V_99 ) {
F_88 ( V_161 ) ;
return 0 ;
}
V_125:
V_165 = 0 ;
V_166 = 0 ;
while ( 1 ) {
if ( V_164 )
V_166 = ( T_1 ) - 1 ;
else {
V_8 = F_124 ( log , V_42 , V_105 , V_155 ,
& V_165 , & V_166 ) ;
if ( V_8 != 0 )
break;
}
V_162 . V_76 = V_165 ;
while ( 1 ) {
int V_160 ;
V_8 = F_28 ( NULL , V_4 , & V_162 , V_42 ,
0 , 0 ) ;
if ( V_8 < 0 )
goto V_15;
V_160 = F_126 ( V_42 -> V_60 [ 0 ] ) ;
if ( V_42 -> V_61 [ 0 ] >= V_160 ) {
V_8 = F_127 ( V_4 , V_42 ) ;
if ( V_8 )
break;
}
F_108 ( V_42 -> V_60 [ 0 ] , & V_146 ,
V_42 -> V_61 [ 0 ] ) ;
if ( V_146 . V_55 != V_105 ||
V_146 . type != V_162 . type )
goto V_168;
if ( V_146 . V_76 > V_166 )
break;
V_8 = F_128 ( V_2 , V_4 , log , V_42 ,
V_161 , V_99 ,
& V_146 ) ;
if ( V_8 )
goto V_15;
if ( V_146 . V_76 == ( T_1 ) - 1 )
break;
V_162 . V_76 = V_146 . V_76 + 1 ;
}
F_29 ( V_42 ) ;
if ( V_166 == ( T_1 ) - 1 )
break;
V_165 = V_166 + 1 ;
}
V_168:
V_8 = 0 ;
if ( V_155 == V_167 ) {
V_155 = V_169 ;
V_162 . type = V_151 ;
F_29 ( V_42 ) ;
goto V_125;
}
V_15:
F_29 ( V_42 ) ;
F_88 ( V_161 ) ;
F_72 ( V_99 ) ;
return V_8 ;
}
static int F_130 ( struct V_3 * log , struct V_29 * V_30 ,
struct V_31 * V_32 , T_1 V_33 )
{
int V_160 ;
struct V_41 * V_42 ;
struct V_3 * V_4 = V_32 -> V_170 ;
struct V_44 V_45 ;
int V_171 ;
int V_172 ;
int V_8 ;
V_8 = F_18 ( V_30 , V_33 ) ;
if ( V_8 )
return V_8 ;
V_171 = F_21 ( V_30 ) ;
if ( V_171 != 0 )
return 0 ;
V_42 = F_84 () ;
if ( ! V_42 )
return - V_64 ;
V_160 = F_126 ( V_30 ) ;
for ( V_172 = 0 ; V_172 < V_160 ; V_172 ++ ) {
F_108 ( V_30 , & V_45 , V_172 ) ;
if ( V_45 . type == V_53 &&
V_32 -> V_173 == V_174 ) {
struct V_65 * V_52 ;
T_3 V_68 ;
V_52 = F_33 ( V_30 , V_172 ,
struct V_65 ) ;
V_68 = F_36 ( V_30 , V_52 ) ;
if ( F_37 ( V_68 ) ) {
V_8 = F_112 ( V_32 -> V_2 ,
V_4 , log , V_42 , V_45 . V_55 , 0 ) ;
if ( V_8 )
break;
}
V_8 = F_25 ( V_32 -> V_2 , V_4 , V_42 ,
V_30 , V_172 , & V_45 ) ;
if ( V_8 )
break;
if ( F_131 ( V_68 ) ) {
V_8 = F_102 ( V_32 -> V_2 , V_4 ,
V_45 . V_55 ) ;
if ( V_8 )
break;
}
V_8 = F_76 ( V_32 -> V_2 , V_4 ,
V_42 , V_45 . V_55 ) ;
if ( V_8 )
break;
}
if ( V_45 . type == V_151 &&
V_32 -> V_173 == V_175 ) {
V_8 = F_122 ( V_32 -> V_2 , V_4 , V_42 ,
V_30 , V_172 , & V_45 ) ;
if ( V_8 )
break;
}
if ( V_32 -> V_173 < V_176 )
continue;
if ( V_45 . type == V_177 ) {
V_8 = F_25 ( V_32 -> V_2 , V_4 , V_42 ,
V_30 , V_172 , & V_45 ) ;
if ( V_8 )
break;
} else if ( V_45 . type == V_126 ||
V_45 . type == V_115 ) {
V_8 = F_100 ( V_32 -> V_2 , V_4 , log , V_42 ,
V_30 , V_172 , & V_45 ) ;
if ( V_8 && V_8 != - V_27 )
break;
V_8 = 0 ;
} else if ( V_45 . type == V_178 ) {
V_8 = F_47 ( V_32 -> V_2 , V_4 , V_42 ,
V_30 , V_172 , & V_45 ) ;
if ( V_8 )
break;
} else if ( V_45 . type == V_152 ) {
V_8 = F_122 ( V_32 -> V_2 , V_4 , V_42 ,
V_30 , V_172 , & V_45 ) ;
if ( V_8 )
break;
}
}
F_88 ( V_42 ) ;
return V_8 ;
}
static T_2 int F_132 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_41 * V_42 , int * V_171 ,
struct V_31 * V_32 )
{
T_1 V_179 ;
T_1 V_180 ;
T_1 V_181 ;
struct V_29 * V_97 ;
struct V_29 * V_182 ;
struct V_29 * V_183 ;
T_3 V_184 ;
int V_8 = 0 ;
F_133 ( * V_171 < 0 ) ;
F_133 ( * V_171 >= V_185 ) ;
while ( * V_171 > 0 ) {
F_133 ( * V_171 < 0 ) ;
F_133 ( * V_171 >= V_185 ) ;
V_182 = V_42 -> V_60 [ * V_171 ] ;
F_133 ( F_21 ( V_182 ) != * V_171 ) ;
if ( V_42 -> V_61 [ * V_171 ] >=
F_126 ( V_182 ) )
break;
V_180 = F_134 ( V_182 , V_42 -> V_61 [ * V_171 ] ) ;
V_181 = F_135 ( V_182 , V_42 -> V_61 [ * V_171 ] ) ;
V_184 = F_136 ( V_4 , * V_171 - 1 ) ;
V_183 = V_42 -> V_60 [ * V_171 ] ;
V_179 = F_137 ( V_183 ) ;
V_97 = F_138 ( V_4 , V_180 , V_184 ) ;
if ( ! V_97 )
return - V_64 ;
if ( * V_171 == 1 ) {
V_8 = V_32 -> V_186 ( V_4 , V_97 , V_32 , V_181 ) ;
if ( V_8 ) {
F_139 ( V_97 ) ;
return V_8 ;
}
V_42 -> V_61 [ * V_171 ] ++ ;
if ( V_32 -> free ) {
V_8 = F_18 ( V_97 , V_181 ) ;
if ( V_8 ) {
F_139 ( V_97 ) ;
return V_8 ;
}
if ( V_2 ) {
F_140 ( V_97 ) ;
F_141 ( V_97 ) ;
F_142 ( V_2 , V_4 , V_97 ) ;
F_24 ( V_97 ) ;
F_143 ( V_97 ) ;
}
F_133 ( V_179 !=
V_56 ) ;
V_8 = F_144 ( V_4 ,
V_180 , V_184 ) ;
if ( V_8 ) {
F_139 ( V_97 ) ;
return V_8 ;
}
}
F_139 ( V_97 ) ;
continue;
}
V_8 = F_18 ( V_97 , V_181 ) ;
if ( V_8 ) {
F_139 ( V_97 ) ;
return V_8 ;
}
F_133 ( * V_171 <= 0 ) ;
if ( V_42 -> V_60 [ * V_171 - 1 ] )
F_139 ( V_42 -> V_60 [ * V_171 - 1 ] ) ;
V_42 -> V_60 [ * V_171 - 1 ] = V_97 ;
* V_171 = F_21 ( V_97 ) ;
V_42 -> V_61 [ * V_171 ] = 0 ;
F_145 () ;
}
F_133 ( * V_171 < 0 ) ;
F_133 ( * V_171 >= V_185 ) ;
V_42 -> V_61 [ * V_171 ] = F_126 ( V_42 -> V_60 [ * V_171 ] ) ;
F_145 () ;
return 0 ;
}
static T_2 int F_146 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_41 * V_42 , int * V_171 ,
struct V_31 * V_32 )
{
T_1 V_179 ;
int V_172 ;
int V_43 ;
int V_8 ;
for ( V_172 = * V_171 ; V_172 < V_185 - 1 && V_42 -> V_60 [ V_172 ] ; V_172 ++ ) {
V_43 = V_42 -> V_61 [ V_172 ] ;
if ( V_43 + 1 < F_126 ( V_42 -> V_60 [ V_172 ] ) ) {
V_42 -> V_61 [ V_172 ] ++ ;
* V_171 = V_172 ;
F_133 ( * V_171 == 0 ) ;
return 0 ;
} else {
struct V_29 * V_183 ;
if ( V_42 -> V_60 [ * V_171 ] == V_4 -> V_187 )
V_183 = V_42 -> V_60 [ * V_171 ] ;
else
V_183 = V_42 -> V_60 [ * V_171 + 1 ] ;
V_179 = F_137 ( V_183 ) ;
V_8 = V_32 -> V_186 ( V_4 , V_42 -> V_60 [ * V_171 ] , V_32 ,
F_147 ( V_42 -> V_60 [ * V_171 ] ) ) ;
if ( V_8 )
return V_8 ;
if ( V_32 -> free ) {
struct V_29 * V_97 ;
V_97 = V_42 -> V_60 [ * V_171 ] ;
if ( V_2 ) {
F_140 ( V_97 ) ;
F_141 ( V_97 ) ;
F_142 ( V_2 , V_4 , V_97 ) ;
F_24 ( V_97 ) ;
F_143 ( V_97 ) ;
}
F_133 ( V_179 != V_56 ) ;
V_8 = F_144 ( V_4 ,
V_42 -> V_60 [ * V_171 ] -> V_37 ,
V_42 -> V_60 [ * V_171 ] -> V_38 ) ;
if ( V_8 )
return V_8 ;
}
F_139 ( V_42 -> V_60 [ * V_171 ] ) ;
V_42 -> V_60 [ * V_171 ] = NULL ;
* V_171 = V_172 + 1 ;
}
}
return 1 ;
}
static int F_148 ( struct V_1 * V_2 ,
struct V_3 * log , struct V_31 * V_32 )
{
int V_8 = 0 ;
int V_188 ;
int V_171 ;
struct V_41 * V_42 ;
int V_189 ;
V_42 = F_84 () ;
if ( ! V_42 )
return - V_64 ;
V_171 = F_21 ( log -> V_187 ) ;
V_189 = V_171 ;
V_42 -> V_60 [ V_171 ] = log -> V_187 ;
F_149 ( log -> V_187 ) ;
V_42 -> V_61 [ V_171 ] = 0 ;
while ( 1 ) {
V_188 = F_132 ( V_2 , log , V_42 , & V_171 , V_32 ) ;
if ( V_188 > 0 )
break;
if ( V_188 < 0 ) {
V_8 = V_188 ;
goto V_15;
}
V_188 = F_146 ( V_2 , log , V_42 , & V_171 , V_32 ) ;
if ( V_188 > 0 )
break;
if ( V_188 < 0 ) {
V_8 = V_188 ;
goto V_15;
}
}
if ( V_42 -> V_60 [ V_189 ] ) {
V_8 = V_32 -> V_186 ( log , V_42 -> V_60 [ V_189 ] , V_32 ,
F_147 ( V_42 -> V_60 [ V_189 ] ) ) ;
if ( V_8 )
goto V_15;
if ( V_32 -> free ) {
struct V_29 * V_97 ;
V_97 = V_42 -> V_60 [ V_189 ] ;
if ( V_2 ) {
F_140 ( V_97 ) ;
F_141 ( V_97 ) ;
F_142 ( V_2 , log , V_97 ) ;
F_24 ( V_97 ) ;
F_143 ( V_97 ) ;
}
F_133 ( log -> V_54 . V_55 !=
V_56 ) ;
V_8 = F_144 ( log , V_97 -> V_37 ,
V_97 -> V_38 ) ;
if ( V_8 )
goto V_15;
}
}
V_15:
F_88 ( V_42 ) ;
return V_8 ;
}
static int F_150 ( struct V_1 * V_2 ,
struct V_3 * log )
{
int V_8 ;
if ( log -> V_22 == 1 ) {
V_8 = F_151 ( V_2 , log -> V_11 -> V_26 ,
& log -> V_54 , & log -> V_190 ) ;
} else {
V_8 = F_152 ( V_2 , log -> V_11 -> V_26 ,
& log -> V_54 , & log -> V_190 ) ;
}
return V_8 ;
}
static void F_153 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_13 )
{
F_154 ( V_40 ) ;
int V_7 = V_13 % 2 ;
do {
F_155 ( & V_4 -> V_191 [ V_7 ] ,
& V_40 , V_192 ) ;
F_6 ( & V_4 -> V_9 ) ;
if ( V_4 -> V_193 < V_13 &&
F_156 ( & V_4 -> V_194 [ V_7 ] ) )
F_157 () ;
F_158 ( & V_4 -> V_191 [ V_7 ] , & V_40 ) ;
F_2 ( & V_4 -> V_9 ) ;
} while ( V_4 -> V_193 < V_13 &&
F_156 ( & V_4 -> V_194 [ V_7 ] ) );
}
static void F_159 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_154 ( V_40 ) ;
while ( F_156 ( & V_4 -> V_21 ) ) {
F_155 ( & V_4 -> V_28 ,
& V_40 , V_192 ) ;
F_6 ( & V_4 -> V_9 ) ;
if ( F_156 ( & V_4 -> V_21 ) )
F_157 () ;
F_2 ( & V_4 -> V_9 ) ;
F_158 ( & V_4 -> V_28 , & V_40 ) ;
}
}
static inline void F_160 ( struct V_3 * V_4 ,
struct V_5 * V_6 )
{
if ( ! V_6 )
return;
F_2 ( & V_4 -> V_9 ) ;
F_161 ( & V_6 -> V_23 ) ;
F_6 ( & V_4 -> V_9 ) ;
}
static inline void F_162 ( struct V_3 * V_4 ,
int V_7 , int error )
{
struct V_5 * V_6 ;
if ( ! error ) {
F_163 ( & V_4 -> V_24 [ V_7 ] ) ;
return;
}
F_164 (ctx, &root->log_ctxs[index], list)
V_6 -> V_195 = error ;
F_163 ( & V_4 -> V_24 [ V_7 ] ) ;
}
int F_165 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_5 * V_6 )
{
int V_196 ;
int V_197 ;
int V_198 ;
int V_8 ;
struct V_3 * log = V_4 -> V_10 ;
struct V_3 * V_26 = V_4 -> V_11 -> V_26 ;
int V_22 = 0 ;
struct V_5 V_199 ;
struct V_200 V_201 ;
F_2 ( & V_4 -> V_9 ) ;
V_22 = V_6 -> V_22 ;
if ( V_4 -> V_193 >= V_22 ) {
F_6 ( & V_4 -> V_9 ) ;
return V_6 -> V_195 ;
}
V_196 = V_22 % 2 ;
if ( F_156 ( & V_4 -> V_194 [ V_196 ] ) ) {
F_153 ( V_2 , V_4 , V_22 ) ;
F_6 ( & V_4 -> V_9 ) ;
return V_6 -> V_195 ;
}
ASSERT ( V_22 == V_4 -> V_22 ) ;
F_166 ( & V_4 -> V_194 [ V_196 ] , 1 ) ;
if ( F_156 ( & V_4 -> V_194 [ ( V_196 + 1 ) % 2 ] ) )
F_153 ( V_2 , V_4 , V_22 - 1 ) ;
while ( 1 ) {
int V_202 = F_156 ( & V_4 -> V_20 ) ;
if ( ! F_167 ( V_4 , V_203 ) && V_4 -> V_19 ) {
F_6 ( & V_4 -> V_9 ) ;
F_168 ( 1 ) ;
F_2 ( & V_4 -> V_9 ) ;
}
F_159 ( V_2 , V_4 ) ;
if ( V_202 == F_156 ( & V_4 -> V_20 ) )
break;
}
if ( F_3 ( V_4 -> V_11 -> V_12 ) ==
V_2 -> V_13 ) {
V_8 = - V_14 ;
F_169 ( log , V_22 ) ;
F_6 ( & V_4 -> V_9 ) ;
goto V_15;
}
if ( V_22 % 2 == 0 )
V_198 = V_204 ;
else
V_198 = V_205 ;
F_170 ( & V_201 ) ;
V_8 = F_171 ( log , & log -> V_206 , V_198 ) ;
if ( V_8 ) {
F_172 ( & V_201 ) ;
F_173 ( V_2 , V_4 , V_8 ) ;
F_169 ( log , V_22 ) ;
F_3 ( V_4 -> V_11 -> V_12 ) =
V_2 -> V_13 ;
F_6 ( & V_4 -> V_9 ) ;
goto V_15;
}
F_174 ( & log -> V_190 , log -> V_187 ) ;
V_4 -> V_22 ++ ;
log -> V_22 = V_4 -> V_22 ;
V_4 -> V_16 = 0 ;
F_6 ( & V_4 -> V_9 ) ;
F_175 ( & V_199 ) ;
F_2 ( & V_26 -> V_9 ) ;
F_4 ( & V_26 -> V_20 ) ;
F_4 ( & V_26 -> V_21 ) ;
V_197 = V_26 -> V_22 % 2 ;
F_5 ( & V_199 . V_23 , & V_26 -> V_24 [ V_197 ] ) ;
V_199 . V_22 = V_26 -> V_22 ;
F_6 ( & V_26 -> V_9 ) ;
V_8 = F_150 ( V_2 , log ) ;
F_2 ( & V_26 -> V_9 ) ;
if ( F_13 ( & V_26 -> V_21 ) ) {
F_10 () ;
if ( F_14 ( & V_26 -> V_28 ) )
F_15 ( & V_26 -> V_28 ) ;
}
if ( V_8 ) {
if ( ! F_66 ( & V_199 . V_23 ) )
F_161 ( & V_199 . V_23 ) ;
F_172 ( & V_201 ) ;
F_3 ( V_4 -> V_11 -> V_12 ) =
V_2 -> V_13 ;
if ( V_8 != - V_207 ) {
F_173 ( V_2 , V_4 , V_8 ) ;
F_6 ( & V_26 -> V_9 ) ;
goto V_15;
}
F_176 ( log , & log -> V_206 , V_198 ) ;
F_169 ( log , V_22 ) ;
F_6 ( & V_26 -> V_9 ) ;
V_8 = - V_14 ;
goto V_15;
}
if ( V_26 -> V_193 >= V_199 . V_22 ) {
F_6 ( & V_26 -> V_9 ) ;
V_8 = V_199 . V_195 ;
goto V_15;
}
V_197 = V_199 . V_22 % 2 ;
if ( F_156 ( & V_26 -> V_194 [ V_197 ] ) ) {
F_172 ( & V_201 ) ;
F_176 ( log , & log -> V_206 , V_198 ) ;
F_153 ( V_2 , V_26 ,
V_199 . V_22 ) ;
F_169 ( log , V_22 ) ;
F_6 ( & V_26 -> V_9 ) ;
V_8 = V_199 . V_195 ;
goto V_15;
}
ASSERT ( V_199 . V_22 == V_26 -> V_22 ) ;
F_166 ( & V_26 -> V_194 [ V_197 ] , 1 ) ;
if ( F_156 ( & V_26 -> V_194 [ ( V_197 + 1 ) % 2 ] ) ) {
F_153 ( V_2 , V_26 ,
V_199 . V_22 - 1 ) ;
}
F_159 ( V_2 , V_26 ) ;
if ( F_3 ( V_4 -> V_11 -> V_12 ) ==
V_2 -> V_13 ) {
F_172 ( & V_201 ) ;
F_176 ( log , & log -> V_206 , V_198 ) ;
F_169 ( log , V_22 ) ;
F_6 ( & V_26 -> V_9 ) ;
V_8 = - V_14 ;
goto V_208;
}
V_8 = F_171 ( V_26 ,
& V_26 -> V_206 ,
V_204 | V_205 ) ;
F_172 ( & V_201 ) ;
if ( V_8 ) {
F_3 ( V_4 -> V_11 -> V_12 ) =
V_2 -> V_13 ;
F_173 ( V_2 , V_4 , V_8 ) ;
F_169 ( log , V_22 ) ;
F_6 ( & V_26 -> V_9 ) ;
goto V_208;
}
F_176 ( log , & log -> V_206 , V_198 ) ;
F_176 ( V_26 ,
& V_26 -> V_206 ,
V_205 | V_204 ) ;
F_177 ( log , V_22 ) ;
F_178 ( V_4 -> V_11 -> V_209 ,
V_26 -> V_187 -> V_37 ) ;
F_179 ( V_4 -> V_11 -> V_209 ,
F_21 ( V_26 -> V_187 ) ) ;
V_26 -> V_22 ++ ;
F_6 ( & V_26 -> V_9 ) ;
V_8 = F_180 ( V_2 , V_4 -> V_11 -> V_210 , 1 ) ;
if ( V_8 ) {
F_3 ( V_4 -> V_11 -> V_12 ) =
V_2 -> V_13 ;
F_173 ( V_2 , V_4 , V_8 ) ;
goto V_208;
}
F_2 ( & V_4 -> V_9 ) ;
if ( V_4 -> V_211 < V_22 )
V_4 -> V_211 = V_22 ;
F_6 ( & V_4 -> V_9 ) ;
V_208:
F_162 ( V_26 , V_197 , V_8 ) ;
F_2 ( & V_26 -> V_9 ) ;
V_26 -> V_193 ++ ;
F_166 ( & V_26 -> V_194 [ V_197 ] , 0 ) ;
F_6 ( & V_26 -> V_9 ) ;
if ( F_14 ( & V_26 -> V_191 [ V_197 ] ) )
F_15 ( & V_26 -> V_191 [ V_197 ] ) ;
V_15:
F_162 ( V_4 , V_196 , V_8 ) ;
F_2 ( & V_4 -> V_9 ) ;
V_4 -> V_193 ++ ;
F_166 ( & V_4 -> V_194 [ V_196 ] , 0 ) ;
F_6 ( & V_4 -> V_9 ) ;
if ( F_14 ( & V_4 -> V_191 [ V_196 ] ) )
F_15 ( & V_4 -> V_191 [ V_196 ] ) ;
return V_8 ;
}
static void F_181 ( struct V_1 * V_2 ,
struct V_3 * log )
{
int V_8 ;
T_1 V_37 ;
T_1 V_212 ;
struct V_31 V_32 = {
. free = 1 ,
. V_186 = F_16
} ;
V_8 = F_148 ( V_2 , log , & V_32 ) ;
if ( V_8 )
F_173 ( V_2 , log , V_8 ) ;
while ( 1 ) {
V_8 = F_182 ( & log -> V_206 ,
0 , & V_37 , & V_212 , V_204 | V_205 ,
NULL ) ;
if ( V_8 )
break;
F_183 ( & log -> V_206 , V_37 , V_212 ,
V_204 | V_205 , V_63 ) ;
}
F_169 ( log , 0 ) ;
F_169 ( log , 1 ) ;
F_139 ( log -> V_187 ) ;
F_31 ( log ) ;
}
int F_184 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( V_4 -> V_10 ) {
F_181 ( V_2 , V_4 -> V_10 ) ;
V_4 -> V_10 = NULL ;
}
return 0 ;
}
int F_185 ( struct V_1 * V_2 ,
struct V_213 * V_11 )
{
if ( V_11 -> V_26 ) {
F_181 ( V_2 , V_11 -> V_26 ) ;
V_11 -> V_26 = NULL ;
}
return 0 ;
}
int F_186 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_102 , int V_103 ,
struct V_78 * V_99 , T_1 V_7 )
{
struct V_3 * log ;
struct V_100 * V_101 ;
struct V_41 * V_42 ;
int V_8 ;
int V_214 = 0 ;
int V_215 = 0 ;
T_1 V_216 = F_56 ( V_99 ) ;
if ( F_111 ( V_99 ) -> V_217 < V_2 -> V_13 )
return 0 ;
V_8 = F_9 ( V_4 ) ;
if ( V_8 )
return 0 ;
F_2 ( & F_111 ( V_99 ) -> V_9 ) ;
log = V_4 -> V_10 ;
V_42 = F_84 () ;
if ( ! V_42 ) {
V_214 = - V_64 ;
goto V_218;
}
V_101 = F_82 ( V_2 , log , V_42 , V_216 ,
V_102 , V_103 , - 1 ) ;
if ( F_81 ( V_101 ) ) {
V_214 = F_129 ( V_101 ) ;
goto V_219;
}
if ( V_101 ) {
V_8 = F_187 ( V_2 , log , V_42 , V_101 ) ;
V_215 += V_103 ;
if ( V_8 ) {
V_214 = V_8 ;
goto V_219;
}
}
F_29 ( V_42 ) ;
V_101 = F_80 ( V_2 , log , V_42 , V_216 ,
V_7 , V_102 , V_103 , - 1 ) ;
if ( F_81 ( V_101 ) ) {
V_214 = F_129 ( V_101 ) ;
goto V_219;
}
if ( V_101 ) {
V_8 = F_187 ( V_2 , log , V_42 , V_101 ) ;
V_215 += V_103 ;
if ( V_8 ) {
V_214 = V_8 ;
goto V_219;
}
}
if ( V_215 ) {
struct V_44 V_45 ;
V_45 . V_55 = V_216 ;
V_45 . V_76 = 0 ;
V_45 . type = V_53 ;
F_29 ( V_42 ) ;
V_8 = F_28 ( V_2 , log , & V_45 , V_42 , 0 , 1 ) ;
if ( V_8 < 0 ) {
V_214 = V_8 ;
goto V_219;
}
if ( V_8 == 0 ) {
struct V_65 * V_66 ;
T_1 V_154 ;
V_66 = F_33 ( V_42 -> V_60 [ 0 ] , V_42 -> V_61 [ 0 ] ,
struct V_65 ) ;
V_154 = F_43 ( V_42 -> V_60 [ 0 ] , V_66 ) ;
if ( V_154 > V_215 )
V_154 -= V_215 ;
else
V_154 = 0 ;
F_38 ( V_42 -> V_60 [ 0 ] , V_66 , V_154 ) ;
F_46 ( V_42 -> V_60 [ 0 ] ) ;
} else
V_8 = 0 ;
F_29 ( V_42 ) ;
}
V_219:
F_88 ( V_42 ) ;
V_218:
F_6 ( & F_111 ( V_99 ) -> V_9 ) ;
if ( V_8 == - V_207 ) {
V_4 -> V_11 -> V_12 = V_2 -> V_13 ;
V_8 = 0 ;
} else if ( V_8 < 0 )
F_173 ( V_2 , V_4 , V_8 ) ;
F_12 ( V_4 ) ;
return V_214 ;
}
int F_188 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_102 , int V_103 ,
struct V_78 * V_78 , T_1 V_105 )
{
struct V_3 * log ;
T_1 V_7 ;
int V_8 ;
if ( F_111 ( V_78 ) -> V_217 < V_2 -> V_13 )
return 0 ;
V_8 = F_9 ( V_4 ) ;
if ( V_8 )
return 0 ;
log = V_4 -> V_10 ;
F_2 ( & F_111 ( V_78 ) -> V_9 ) ;
V_8 = F_189 ( V_2 , log , V_102 , V_103 , F_56 ( V_78 ) ,
V_105 , & V_7 ) ;
F_6 ( & F_111 ( V_78 ) -> V_9 ) ;
if ( V_8 == - V_207 ) {
V_4 -> V_11 -> V_12 = V_2 -> V_13 ;
V_8 = 0 ;
} else if ( V_8 < 0 && V_8 != - V_27 )
F_173 ( V_2 , V_4 , V_8 ) ;
F_12 ( V_4 ) ;
return V_8 ;
}
static T_2 int F_190 ( struct V_1 * V_2 ,
struct V_3 * log ,
struct V_41 * V_42 ,
int V_155 , T_1 V_105 ,
T_1 V_220 , T_1 V_221 )
{
int V_8 ;
struct V_44 V_45 ;
struct V_159 * V_66 ;
V_45 . V_55 = V_105 ;
V_45 . V_76 = V_220 ;
if ( V_155 == V_152 )
V_45 . type = V_167 ;
else
V_45 . type = V_169 ;
V_8 = F_39 ( V_2 , log , V_42 , & V_45 , sizeof( * V_66 ) ) ;
if ( V_8 )
return V_8 ;
V_66 = F_33 ( V_42 -> V_60 [ 0 ] , V_42 -> V_61 [ 0 ] ,
struct V_159 ) ;
F_191 ( V_42 -> V_60 [ 0 ] , V_66 , V_221 ) ;
F_46 ( V_42 -> V_60 [ 0 ] ) ;
F_29 ( V_42 ) ;
return 0 ;
}
static T_2 int F_192 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_78 * V_78 ,
struct V_41 * V_42 ,
struct V_41 * V_222 , int V_155 ,
T_1 V_223 , T_1 * V_224 )
{
struct V_44 V_225 ;
struct V_3 * log = V_4 -> V_10 ;
struct V_29 * V_226 ;
int V_214 = 0 ;
int V_8 ;
int V_172 ;
int V_160 ;
T_1 V_220 = V_223 ;
T_1 V_221 = ( T_1 ) - 1 ;
T_1 V_139 = F_56 ( V_78 ) ;
log = V_4 -> V_10 ;
V_225 . V_55 = V_139 ;
V_225 . type = V_155 ;
V_225 . V_76 = V_223 ;
V_42 -> V_227 = 1 ;
V_8 = F_193 ( V_4 , & V_225 , V_42 , V_2 -> V_13 ) ;
if ( V_8 != 0 || V_225 . V_55 != V_139 || V_225 . type != V_155 ) {
V_225 . V_55 = V_139 ;
V_225 . type = V_155 ;
V_225 . V_76 = ( T_1 ) - 1 ;
F_29 ( V_42 ) ;
V_8 = F_28 ( NULL , V_4 , & V_225 , V_42 , 0 , 0 ) ;
if ( V_8 < 0 ) {
F_29 ( V_42 ) ;
return V_8 ;
}
V_8 = F_194 ( V_4 , V_42 , V_139 , V_155 ) ;
if ( V_8 == 0 ) {
struct V_44 V_228 ;
F_108 ( V_42 -> V_60 [ 0 ] , & V_228 ,
V_42 -> V_61 [ 0 ] ) ;
if ( V_155 == V_228 . type )
V_220 = F_195 ( V_223 , V_228 . V_76 ) + 1 ;
}
goto V_229;
}
V_8 = F_194 ( V_4 , V_42 , V_139 , V_155 ) ;
if ( V_8 == 0 ) {
struct V_44 V_228 ;
F_108 ( V_42 -> V_60 [ 0 ] , & V_228 , V_42 -> V_61 [ 0 ] ) ;
if ( V_155 == V_228 . type ) {
V_220 = V_228 . V_76 ;
V_8 = F_25 ( V_2 , log , V_222 ,
V_42 -> V_60 [ 0 ] , V_42 -> V_61 [ 0 ] ,
& V_228 ) ;
if ( V_8 ) {
V_214 = V_8 ;
goto V_229;
}
}
}
F_29 ( V_42 ) ;
V_8 = F_28 ( NULL , V_4 , & V_225 , V_42 , 0 , 0 ) ;
if ( F_133 ( V_8 != 0 ) )
goto V_229;
while ( 1 ) {
struct V_44 V_228 ;
V_226 = V_42 -> V_60 [ 0 ] ;
V_160 = F_126 ( V_226 ) ;
for ( V_172 = V_42 -> V_61 [ 0 ] ; V_172 < V_160 ; V_172 ++ ) {
F_108 ( V_226 , & V_225 , V_172 ) ;
if ( V_225 . V_55 != V_139 || V_225 . type != V_155 )
goto V_229;
V_8 = F_25 ( V_2 , log , V_222 , V_226 , V_172 ,
& V_225 ) ;
if ( V_8 ) {
V_214 = V_8 ;
goto V_229;
}
}
V_42 -> V_61 [ 0 ] = V_160 ;
V_8 = F_127 ( V_4 , V_42 ) ;
if ( V_8 == 1 ) {
V_221 = ( T_1 ) - 1 ;
goto V_229;
}
F_108 ( V_42 -> V_60 [ 0 ] , & V_228 , V_42 -> V_61 [ 0 ] ) ;
if ( V_228 . V_55 != V_139 || V_228 . type != V_155 ) {
V_221 = ( T_1 ) - 1 ;
goto V_229;
}
if ( F_147 ( V_42 -> V_60 [ 0 ] ) != V_2 -> V_13 ) {
V_8 = F_25 ( V_2 , log , V_222 ,
V_42 -> V_60 [ 0 ] , V_42 -> V_61 [ 0 ] ,
& V_228 ) ;
if ( V_8 )
V_214 = V_8 ;
else
V_221 = V_228 . V_76 ;
goto V_229;
}
}
V_229:
F_29 ( V_42 ) ;
F_29 ( V_222 ) ;
if ( V_214 == 0 ) {
* V_224 = V_221 ;
V_8 = F_190 ( V_2 , log , V_42 , V_155 ,
V_139 , V_220 , V_221 ) ;
if ( V_8 )
V_214 = V_8 ;
}
return V_214 ;
}
static T_2 int F_196 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_78 * V_78 ,
struct V_41 * V_42 ,
struct V_41 * V_222 )
{
T_1 V_225 ;
T_1 V_230 ;
int V_8 ;
int V_155 = V_152 ;
V_125:
V_225 = 0 ;
V_230 = 0 ;
while ( 1 ) {
V_8 = F_192 ( V_2 , V_4 , V_78 , V_42 ,
V_222 , V_155 , V_225 ,
& V_230 ) ;
if ( V_8 )
return V_8 ;
if ( V_230 == ( T_1 ) - 1 )
break;
V_225 = V_230 + 1 ;
}
if ( V_155 == V_152 ) {
V_155 = V_151 ;
goto V_125;
}
return 0 ;
}
static int F_197 ( struct V_1 * V_2 ,
struct V_3 * log ,
struct V_41 * V_42 ,
T_1 V_55 , int V_231 )
{
int V_8 ;
struct V_44 V_45 ;
struct V_44 V_146 ;
int V_232 ;
V_45 . V_55 = V_55 ;
V_45 . type = V_231 ;
V_45 . V_76 = ( T_1 ) - 1 ;
while ( 1 ) {
V_8 = F_28 ( V_2 , log , & V_45 , V_42 , - 1 , 1 ) ;
F_198 ( V_8 == 0 ) ;
if ( V_8 < 0 )
break;
if ( V_42 -> V_61 [ 0 ] == 0 )
break;
V_42 -> V_61 [ 0 ] -- ;
F_108 ( V_42 -> V_60 [ 0 ] , & V_146 ,
V_42 -> V_61 [ 0 ] ) ;
if ( V_146 . V_55 != V_55 )
break;
V_146 . V_76 = 0 ;
V_146 . type = 0 ;
V_8 = F_199 ( V_42 -> V_60 [ 0 ] , & V_146 , 0 ,
& V_232 ) ;
V_8 = F_200 ( V_2 , log , V_42 , V_232 ,
V_42 -> V_61 [ 0 ] - V_232 + 1 ) ;
if ( V_8 || V_232 != 0 )
break;
F_29 ( V_42 ) ;
}
F_29 ( V_42 ) ;
if ( V_8 > 0 )
V_8 = 0 ;
return V_8 ;
}
static void F_201 ( struct V_1 * V_2 ,
struct V_29 * V_88 ,
struct V_65 * V_66 ,
struct V_78 * V_78 , int V_233 )
{
struct V_234 V_235 ;
F_202 ( & V_235 ) ;
if ( V_233 ) {
F_203 ( V_88 , V_66 , 0 , & V_235 ) ;
F_204 ( V_88 , V_66 , 0 , & V_235 ) ;
} else {
F_203 ( V_88 , V_66 ,
F_111 ( V_78 ) -> V_236 ,
& V_235 ) ;
F_204 ( V_88 , V_66 , V_78 -> V_154 , & V_235 ) ;
}
F_205 ( V_88 , V_66 , F_206 ( V_78 ) , & V_235 ) ;
F_207 ( V_88 , V_66 , F_208 ( V_78 ) , & V_235 ) ;
F_209 ( V_88 , V_66 , V_78 -> V_143 , & V_235 ) ;
F_210 ( V_88 , V_66 , V_78 -> V_141 , & V_235 ) ;
F_211 ( V_88 , F_212 ( V_66 ) ,
V_78 -> V_237 . V_238 , & V_235 ) ;
F_213 ( V_88 , F_212 ( V_66 ) ,
V_78 -> V_237 . V_239 , & V_235 ) ;
F_211 ( V_88 , F_214 ( V_66 ) ,
V_78 -> V_240 . V_238 , & V_235 ) ;
F_213 ( V_88 , F_214 ( V_66 ) ,
V_78 -> V_240 . V_239 , & V_235 ) ;
F_211 ( V_88 , F_215 ( V_66 ) ,
V_78 -> V_241 . V_238 , & V_235 ) ;
F_213 ( V_88 , F_215 ( V_66 ) ,
V_78 -> V_241 . V_239 , & V_235 ) ;
F_216 ( V_88 , V_66 , F_217 ( V_78 ) ,
& V_235 ) ;
F_218 ( V_88 , V_66 , V_78 -> V_242 , & V_235 ) ;
F_219 ( V_88 , V_66 , V_2 -> V_13 , & V_235 ) ;
F_220 ( V_88 , V_66 , V_78 -> V_243 , & V_235 ) ;
F_221 ( V_88 , V_66 , F_111 ( V_78 ) -> V_244 , & V_235 ) ;
F_222 ( V_88 , V_66 , 0 , & V_235 ) ;
}
static int F_223 ( struct V_1 * V_2 ,
struct V_3 * log , struct V_41 * V_42 ,
struct V_78 * V_78 )
{
struct V_65 * V_52 ;
int V_8 ;
V_8 = F_39 ( V_2 , log , V_42 ,
& F_111 ( V_78 ) -> V_104 ,
sizeof( * V_52 ) ) ;
if ( V_8 && V_8 != - V_69 )
return V_8 ;
V_52 = F_33 ( V_42 -> V_60 [ 0 ] , V_42 -> V_61 [ 0 ] ,
struct V_65 ) ;
F_201 ( V_2 , V_42 -> V_60 [ 0 ] , V_52 , V_78 , 0 ) ;
F_29 ( V_42 ) ;
return 0 ;
}
static T_2 int F_224 ( struct V_1 * V_2 ,
struct V_78 * V_78 ,
struct V_41 * V_222 ,
struct V_41 * V_245 , T_1 * V_246 ,
int V_232 , int V_247 , int V_248 )
{
unsigned long V_249 ;
unsigned long V_250 ;
struct V_3 * log = F_111 ( V_78 ) -> V_4 -> V_10 ;
struct V_77 * V_251 ;
struct V_65 * V_52 ;
struct V_29 * V_226 = V_245 -> V_60 [ 0 ] ;
struct V_44 V_252 , V_253 , V_45 ;
int V_8 ;
struct V_44 * V_254 ;
T_3 * V_255 ;
char * V_256 ;
int V_172 ;
struct V_257 V_94 ;
int V_258 = F_111 ( V_78 ) -> V_244 & V_259 ;
bool V_260 = false ;
bool V_261 = ( * V_246 == 0 ) ;
bool V_229 = false ;
F_163 ( & V_94 ) ;
V_256 = F_30 ( V_247 * sizeof( struct V_44 ) +
V_247 * sizeof( T_3 ) , V_63 ) ;
if ( ! V_256 )
return - V_64 ;
V_252 . V_55 = ( T_1 ) - 1 ;
V_255 = ( T_3 * ) V_256 ;
V_254 = (struct V_44 * ) ( V_256 + V_247 * sizeof( T_3 ) ) ;
for ( V_172 = 0 ; V_172 < V_247 ; V_172 ++ ) {
V_255 [ V_172 ] = F_26 ( V_226 , V_172 + V_232 ) ;
F_108 ( V_226 , V_254 + V_172 , V_172 + V_232 ) ;
}
V_8 = F_225 ( V_2 , log , V_222 ,
V_254 , V_255 , V_247 ) ;
if ( V_8 ) {
F_31 ( V_256 ) ;
return V_8 ;
}
for ( V_172 = 0 ; V_172 < V_247 ; V_172 ++ , V_222 -> V_61 [ 0 ] ++ ) {
V_250 = F_27 ( V_222 -> V_60 [ 0 ] ,
V_222 -> V_61 [ 0 ] ) ;
V_249 = F_27 ( V_226 , V_232 + V_172 ) ;
if ( ( V_172 == ( V_247 - 1 ) ) )
V_253 = V_254 [ V_172 ] ;
if ( V_254 [ V_172 ] . type == V_53 ) {
V_52 = F_33 ( V_222 -> V_60 [ 0 ] ,
V_222 -> V_61 [ 0 ] ,
struct V_65 ) ;
F_201 ( V_2 , V_222 -> V_60 [ 0 ] , V_52 ,
V_78 , V_248 == V_262 ) ;
} else {
F_44 ( V_222 -> V_60 [ 0 ] , V_226 , V_250 ,
V_249 , V_255 [ V_172 ] ) ;
}
if ( V_254 [ V_172 ] . type == V_178 ) {
V_260 = true ;
if ( V_261 &&
V_252 . V_55 == ( T_1 ) - 1 )
V_252 = V_254 [ V_172 ] ;
} else {
V_261 = false ;
}
if ( F_226 ( V_254 + V_172 ) == V_178 &&
! V_258 ) {
int V_74 ;
V_251 = F_33 ( V_226 , V_232 + V_172 ,
struct V_77 ) ;
if ( F_227 ( V_226 , V_251 ) < V_2 -> V_13 )
continue;
V_74 = F_48 ( V_226 , V_251 ) ;
if ( V_74 == V_80 ) {
T_1 V_263 , V_264 , V_265 , V_266 ;
V_263 = F_50 ( V_226 ,
V_251 ) ;
if ( V_263 == 0 )
continue;
V_264 = F_58 ( V_226 ,
V_251 ) ;
V_265 = F_59 ( V_226 , V_251 ) ;
V_266 = F_49 ( V_226 ,
V_251 ) ;
if ( F_64 ( V_226 ,
V_251 ) ) {
V_265 = 0 ;
V_266 = V_264 ;
}
V_8 = F_65 (
log -> V_11 -> V_98 ,
V_263 + V_265 , V_263 + V_265 + V_266 - 1 ,
& V_94 , 0 ) ;
if ( V_8 ) {
F_29 ( V_222 ) ;
F_31 ( V_256 ) ;
return V_8 ;
}
}
}
}
F_46 ( V_222 -> V_60 [ 0 ] ) ;
F_29 ( V_222 ) ;
F_31 ( V_256 ) ;
V_8 = 0 ;
while ( ! F_66 ( & V_94 ) ) {
struct V_95 * V_96 = F_67 ( V_94 . V_97 ,
struct V_95 ,
V_23 ) ;
if ( ! V_8 )
V_8 = F_68 ( V_2 , log , V_96 ) ;
F_69 ( & V_96 -> V_23 ) ;
F_31 ( V_96 ) ;
}
if ( ! V_260 )
return V_8 ;
if ( V_261 ) {
T_1 V_38 ;
V_8 = F_228 ( F_111 ( V_78 ) -> V_4 , V_245 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( V_8 )
goto V_267;
if ( V_245 -> V_61 [ 0 ] )
V_245 -> V_61 [ 0 ] -- ;
V_226 = V_245 -> V_60 [ 0 ] ;
F_108 ( V_226 , & V_45 , V_245 -> V_61 [ 0 ] ) ;
if ( V_45 . V_55 != F_56 ( V_78 ) ||
V_45 . type != V_178 )
goto V_267;
V_251 = F_33 ( V_226 , V_245 -> V_61 [ 0 ] ,
struct V_77 ) ;
if ( F_48 ( V_226 , V_251 ) ==
V_82 ) {
V_38 = F_51 ( V_226 ,
V_245 -> V_61 [ 0 ] ,
V_251 ) ;
* V_246 = F_53 ( V_45 . V_76 + V_38 ,
log -> V_83 ) ;
} else {
V_38 = F_49 ( V_226 , V_251 ) ;
* V_246 = V_45 . V_76 + V_38 ;
}
}
V_267:
if ( V_261 ) {
F_29 ( V_245 ) ;
V_8 = F_28 ( NULL , F_111 ( V_78 ) -> V_4 , & V_252 ,
V_245 , 0 , 0 ) ;
if ( V_8 < 0 )
return V_8 ;
ASSERT ( V_8 == 0 ) ;
V_226 = V_245 -> V_60 [ 0 ] ;
V_172 = V_245 -> V_61 [ 0 ] ;
} else {
V_172 = V_232 ;
}
while ( ! V_229 ) {
T_1 V_76 , V_38 ;
T_1 V_75 ;
if ( V_172 >= F_126 ( V_245 -> V_60 [ 0 ] ) ) {
V_8 = F_127 ( F_111 ( V_78 ) -> V_4 , V_245 ) ;
if ( V_8 < 0 )
return V_8 ;
ASSERT ( V_8 == 0 ) ;
V_226 = V_245 -> V_60 [ 0 ] ;
V_172 = 0 ;
}
F_108 ( V_226 , & V_45 , V_172 ) ;
if ( ! F_229 ( & V_45 , & V_253 ) )
V_229 = true ;
if ( V_45 . V_55 != F_56 ( V_78 ) ||
V_45 . type != V_178 ) {
V_172 ++ ;
continue;
}
V_251 = F_33 ( V_226 , V_172 , struct V_77 ) ;
if ( F_48 ( V_226 , V_251 ) ==
V_82 ) {
V_38 = F_51 ( V_226 , V_172 , V_251 ) ;
V_75 = F_53 ( V_45 . V_76 + V_38 , log -> V_83 ) ;
} else {
V_38 = F_49 ( V_226 , V_251 ) ;
V_75 = V_45 . V_76 + V_38 ;
}
V_172 ++ ;
if ( * V_246 == V_45 . V_76 ) {
* V_246 = V_75 ;
continue;
}
V_76 = * V_246 ;
V_38 = V_45 . V_76 - * V_246 ;
V_8 = F_230 ( V_2 , log , F_56 ( V_78 ) ,
V_76 , 0 , 0 , V_38 , 0 , V_38 , 0 ,
0 , 0 ) ;
if ( V_8 )
break;
* V_246 = V_76 + V_38 ;
}
if ( ! V_8 && V_261 )
V_8 = 1 ;
return V_8 ;
}
static int F_231 ( void * V_268 , struct V_257 * V_269 , struct V_257 * V_270 )
{
struct V_271 * V_272 , * V_273 ;
V_272 = F_67 ( V_269 , struct V_271 , V_23 ) ;
V_273 = F_67 ( V_270 , struct V_271 , V_23 ) ;
if ( V_272 -> V_37 < V_273 -> V_37 )
return - 1 ;
else if ( V_272 -> V_37 > V_273 -> V_37 )
return 1 ;
return 0 ;
}
static int F_232 ( struct V_1 * V_2 ,
struct V_78 * V_78 , struct V_3 * V_4 ,
struct V_271 * V_274 , struct V_41 * V_42 ,
struct V_257 * V_275 )
{
struct V_3 * log = V_4 -> V_10 ;
struct V_77 * V_276 ;
struct V_29 * V_88 ;
struct V_277 * V_278 ;
struct V_257 V_94 ;
struct V_234 V_235 ;
struct V_44 V_45 ;
T_1 V_279 = V_274 -> V_279 ;
T_1 V_280 = V_274 -> V_280 ;
T_1 V_281 ;
T_1 V_282 ;
T_1 V_283 = V_274 -> V_37 - V_274 -> V_284 ;
T_1 V_285 ;
int V_8 ;
bool V_258 = F_111 ( V_78 ) -> V_244 & V_259 ;
int V_286 = 0 ;
F_163 ( & V_94 ) ;
F_202 ( & V_235 ) ;
V_8 = F_233 ( V_2 , log , V_78 , V_42 , V_274 -> V_37 ,
V_274 -> V_37 + V_274 -> V_38 , NULL , 0 , 1 ,
sizeof( * V_276 ) , & V_286 ) ;
if ( V_8 )
return V_8 ;
if ( ! V_286 ) {
V_45 . V_55 = F_56 ( V_78 ) ;
V_45 . type = V_178 ;
V_45 . V_76 = V_274 -> V_37 ;
V_8 = F_39 ( V_2 , log , V_42 , & V_45 ,
sizeof( * V_276 ) ) ;
if ( V_8 )
return V_8 ;
}
V_88 = V_42 -> V_60 [ 0 ] ;
V_276 = F_33 ( V_88 , V_42 -> V_61 [ 0 ] ,
struct V_77 ) ;
F_234 ( V_88 , V_276 , V_274 -> V_236 ,
& V_235 ) ;
if ( F_235 ( V_287 , & V_274 -> V_244 ) ) {
V_258 = true ;
F_236 ( V_88 , V_276 ,
V_81 ,
& V_235 ) ;
} else {
F_236 ( V_88 , V_276 ,
V_80 ,
& V_235 ) ;
if ( V_274 -> V_288 == V_289 )
V_258 = true ;
}
V_285 = F_195 ( V_274 -> V_285 , V_274 -> V_290 ) ;
if ( V_274 -> V_291 != V_292 ) {
F_237 ( V_88 , V_276 ,
V_274 -> V_288 ,
& V_235 ) ;
F_238 ( V_88 , V_276 , V_285 ,
& V_235 ) ;
} else if ( V_274 -> V_288 < V_293 ) {
F_237 ( V_88 , V_276 ,
V_274 -> V_288 -
V_283 , & V_235 ) ;
F_238 ( V_88 , V_276 , V_285 ,
& V_235 ) ;
} else {
F_237 ( V_88 , V_276 , 0 , & V_235 ) ;
F_238 ( V_88 , V_276 , 0 ,
& V_235 ) ;
}
F_239 ( V_88 , V_276 ,
V_274 -> V_37 - V_274 -> V_284 ,
& V_235 ) ;
F_240 ( V_88 , V_276 , V_274 -> V_38 , & V_235 ) ;
F_241 ( V_88 , V_276 , V_274 -> V_294 , & V_235 ) ;
F_242 ( V_88 , V_276 , V_274 -> V_291 ,
& V_235 ) ;
F_243 ( V_88 , V_276 , 0 , & V_235 ) ;
F_244 ( V_88 , V_276 , 0 , & V_235 ) ;
F_46 ( V_88 ) ;
F_29 ( V_42 ) ;
if ( V_8 ) {
return V_8 ;
}
if ( V_258 )
return 0 ;
F_164 (ordered, logged_list, log_list) {
struct V_95 * V_295 ;
if ( ! V_280 )
break;
if ( V_278 -> V_296 + V_278 -> V_38 <= V_279 ||
V_279 + V_280 <= V_278 -> V_296 )
continue;
if ( V_278 -> V_296 > V_279 ) {
if ( V_278 -> V_296 + V_278 -> V_38 >=
V_279 + V_280 )
V_280 = V_278 -> V_296 - V_279 ;
} else {
if ( V_278 -> V_296 + V_278 -> V_38 <
V_279 + V_280 ) {
V_280 = ( V_279 + V_280 ) -
( V_278 -> V_296 + V_278 -> V_38 ) ;
V_279 = V_278 -> V_296 +
V_278 -> V_38 ;
} else {
V_280 = 0 ;
}
}
if ( F_245 ( V_297 ,
& V_278 -> V_244 ) )
continue;
if ( V_278 -> V_298 ) {
F_246 ( V_78 , V_278 , 0 ) ;
F_247 ( V_278 -> V_40 ,
V_278 -> V_298 == 0 ) ;
}
F_164 (sum, &ordered->list, list) {
V_8 = F_68 ( V_2 , log , V_295 ) ;
if ( V_8 )
goto V_299;
}
}
V_299:
if ( ! V_280 || V_8 )
return V_8 ;
if ( V_274 -> V_291 ) {
V_281 = 0 ;
V_282 = V_285 ;
} else {
V_281 = V_279 - V_274 -> V_37 ;
V_282 = V_280 ;
}
V_8 = F_65 ( log -> V_11 -> V_98 ,
V_274 -> V_288 + V_281 ,
V_274 -> V_288 + V_281 +
V_282 - 1 , & V_94 , 0 ) ;
if ( V_8 )
return V_8 ;
while ( ! F_66 ( & V_94 ) ) {
struct V_95 * V_96 = F_67 ( V_94 . V_97 ,
struct V_95 ,
V_23 ) ;
if ( ! V_8 )
V_8 = F_68 ( V_2 , log , V_96 ) ;
F_69 ( & V_96 -> V_23 ) ;
F_31 ( V_96 ) ;
}
return V_8 ;
}
static int F_248 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_78 * V_78 ,
struct V_41 * V_42 ,
struct V_257 * V_275 )
{
struct V_271 * V_274 , * V_300 ;
struct V_257 V_301 ;
struct V_302 * V_303 = & F_111 ( V_78 ) -> V_304 ;
T_1 V_305 ;
int V_8 = 0 ;
int V_306 = 0 ;
F_163 ( & V_301 ) ;
F_249 ( & V_303 -> V_307 ) ;
V_305 = V_4 -> V_11 -> V_308 ;
F_250 (em, n, &tree->modified_extents, list) {
F_161 ( & V_274 -> V_23 ) ;
if ( ++ V_306 > 32768 ) {
F_161 ( & V_303 -> V_309 ) ;
V_8 = - V_310 ;
goto V_311;
}
if ( V_274 -> V_236 <= V_305 )
continue;
F_4 ( & V_274 -> V_312 ) ;
F_251 ( V_313 , & V_274 -> V_244 ) ;
F_5 ( & V_274 -> V_23 , & V_301 ) ;
V_306 ++ ;
}
F_252 ( NULL , & V_301 , F_231 ) ;
V_311:
while ( ! F_66 ( & V_301 ) ) {
V_274 = F_67 ( V_301 . V_97 , struct V_271 , V_23 ) ;
F_161 ( & V_274 -> V_23 ) ;
if ( V_8 ) {
F_253 ( V_303 , V_274 ) ;
F_254 ( V_274 ) ;
continue;
}
F_255 ( & V_303 -> V_307 ) ;
V_8 = F_232 ( V_2 , V_78 , V_4 , V_274 , V_42 , V_275 ) ;
F_249 ( & V_303 -> V_307 ) ;
F_253 ( V_303 , V_274 ) ;
F_254 ( V_274 ) ;
}
F_133 ( ! F_66 ( & V_301 ) ) ;
F_255 ( & V_303 -> V_307 ) ;
F_29 ( V_42 ) ;
return V_8 ;
}
static int F_256 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_78 * V_78 ,
int V_248 )
{
struct V_41 * V_42 ;
struct V_41 * V_222 ;
struct V_44 V_225 ;
struct V_44 V_230 ;
struct V_3 * log = V_4 -> V_10 ;
struct V_29 * V_226 = NULL ;
F_60 ( V_275 ) ;
T_1 V_246 = 0 ;
int V_214 = 0 ;
int V_8 ;
int V_160 ;
int V_314 = 0 ;
int V_315 ;
bool V_316 = false ;
T_1 V_139 = F_56 ( V_78 ) ;
V_42 = F_84 () ;
if ( ! V_42 )
return - V_64 ;
V_222 = F_84 () ;
if ( ! V_222 ) {
F_88 ( V_42 ) ;
return - V_64 ;
}
V_225 . V_55 = V_139 ;
V_225 . type = V_53 ;
V_225 . V_76 = 0 ;
V_230 . V_55 = V_139 ;
if ( F_37 ( V_78 -> V_143 ) ||
( ! F_235 ( V_317 ,
& F_111 ( V_78 ) -> V_318 ) &&
V_248 == V_262 ) )
V_230 . type = V_177 ;
else
V_230 . type = ( T_4 ) - 1 ;
V_230 . V_76 = ( T_1 ) - 1 ;
if ( F_37 ( V_78 -> V_143 ) ||
F_111 ( V_78 ) -> V_236 > V_4 -> V_11 -> V_308 ) {
V_8 = F_257 ( V_2 , V_78 ) ;
if ( V_8 ) {
F_88 ( V_42 ) ;
F_88 ( V_222 ) ;
return V_8 ;
}
}
F_2 ( & F_111 ( V_78 ) -> V_9 ) ;
F_258 ( V_78 , & V_275 ) ;
if ( F_37 ( V_78 -> V_143 ) ) {
int V_231 = V_169 ;
if ( V_248 == V_262 )
V_231 = V_177 ;
V_8 = F_197 ( V_2 , log , V_42 , V_139 , V_231 ) ;
} else {
if ( F_259 ( V_317 ,
& F_111 ( V_78 ) -> V_318 ) ) {
F_260 ( V_319 ,
& F_111 ( V_78 ) -> V_318 ) ;
V_8 = F_261 ( V_2 , log ,
V_78 , 0 , 0 ) ;
} else if ( F_259 ( V_319 ,
& F_111 ( V_78 ) -> V_318 ) ||
V_248 == V_262 ) {
if ( V_248 == V_320 )
V_316 = true ;
V_230 . type = V_177 ;
V_8 = F_197 ( V_2 , log , V_42 , V_139 ,
V_230 . type ) ;
} else {
if ( V_248 == V_320 )
V_316 = true ;
V_8 = F_223 ( V_2 , log , V_222 , V_78 ) ;
if ( V_8 ) {
V_214 = V_8 ;
goto V_218;
}
goto V_321;
}
}
if ( V_8 ) {
V_214 = V_8 ;
goto V_218;
}
V_42 -> V_227 = 1 ;
while ( 1 ) {
V_315 = 0 ;
V_8 = F_193 ( V_4 , & V_225 ,
V_42 , V_2 -> V_13 ) ;
if ( V_8 != 0 )
break;
V_125:
if ( V_225 . V_55 != V_139 )
break;
if ( V_225 . type > V_230 . type )
break;
V_226 = V_42 -> V_60 [ 0 ] ;
if ( V_315 && V_314 + V_315 == V_42 -> V_61 [ 0 ] ) {
V_315 ++ ;
goto V_322;
} else if ( ! V_315 ) {
V_314 = V_42 -> V_61 [ 0 ] ;
V_315 = 1 ;
goto V_322;
}
V_8 = F_224 ( V_2 , V_78 , V_222 , V_42 , & V_246 ,
V_314 , V_315 , V_248 ) ;
if ( V_8 < 0 ) {
V_214 = V_8 ;
goto V_218;
} if ( V_8 ) {
V_315 = 0 ;
F_29 ( V_42 ) ;
continue;
}
V_315 = 1 ;
V_314 = V_42 -> V_61 [ 0 ] ;
V_322:
V_160 = F_126 ( V_42 -> V_60 [ 0 ] ) ;
V_42 -> V_61 [ 0 ] ++ ;
if ( V_42 -> V_61 [ 0 ] < V_160 ) {
F_108 ( V_42 -> V_60 [ 0 ] , & V_225 ,
V_42 -> V_61 [ 0 ] ) ;
goto V_125;
}
if ( V_315 ) {
V_8 = F_224 ( V_2 , V_78 , V_222 , V_42 ,
& V_246 , V_314 ,
V_315 , V_248 ) ;
if ( V_8 < 0 ) {
V_214 = V_8 ;
goto V_218;
}
V_8 = 0 ;
V_315 = 0 ;
}
F_29 ( V_42 ) ;
if ( V_225 . V_76 < ( T_1 ) - 1 ) {
V_225 . V_76 ++ ;
} else if ( V_225 . type < V_230 . type ) {
V_225 . type ++ ;
V_225 . V_76 = 0 ;
} else {
break;
}
}
if ( V_315 ) {
V_8 = F_224 ( V_2 , V_78 , V_222 , V_42 , & V_246 ,
V_314 , V_315 , V_248 ) ;
if ( V_8 < 0 ) {
V_214 = V_8 ;
goto V_218;
}
V_8 = 0 ;
V_315 = 0 ;
}
V_321:
F_29 ( V_42 ) ;
F_29 ( V_222 ) ;
if ( V_316 ) {
V_8 = F_248 ( V_2 , V_4 , V_78 , V_222 ,
& V_275 ) ;
if ( V_8 ) {
V_214 = V_8 ;
goto V_218;
}
} else if ( V_248 == V_320 ) {
struct V_302 * V_303 = & F_111 ( V_78 ) -> V_304 ;
struct V_271 * V_274 , * V_300 ;
F_249 ( & V_303 -> V_307 ) ;
F_250 (em, n, &tree->modified_extents, list)
F_161 ( & V_274 -> V_23 ) ;
F_255 ( & V_303 -> V_307 ) ;
}
if ( V_248 == V_320 && F_37 ( V_78 -> V_143 ) ) {
V_8 = F_196 ( V_2 , V_4 , V_78 , V_42 , V_222 ) ;
if ( V_8 ) {
V_214 = V_8 ;
goto V_218;
}
}
F_111 ( V_78 ) -> V_217 = V_2 -> V_13 ;
F_111 ( V_78 ) -> V_211 = F_111 ( V_78 ) -> V_323 ;
V_218:
if ( F_262 ( V_214 ) )
F_263 ( & V_275 ) ;
else
F_264 ( & V_275 , log ) ;
F_6 ( & F_111 ( V_78 ) -> V_9 ) ;
F_88 ( V_42 ) ;
F_88 ( V_222 ) ;
return V_214 ;
}
static T_2 int F_265 ( struct V_1 * V_2 ,
struct V_78 * V_78 ,
struct V_324 * V_183 ,
struct V_325 * V_326 ,
T_1 V_327 )
{
int V_8 = 0 ;
struct V_3 * V_4 ;
struct V_324 * V_328 = NULL ;
struct V_78 * V_329 = V_78 ;
if ( F_131 ( V_78 -> V_143 ) &&
F_111 ( V_78 ) -> V_236 <= V_327 &&
F_111 ( V_78 ) -> V_330 <= V_327 )
goto V_15;
if ( ! F_37 ( V_78 -> V_143 ) ) {
if ( ! V_183 || ! V_183 -> V_331 || V_326 != V_183 -> V_331 -> V_332 )
goto V_15;
V_78 = V_183 -> V_331 ;
}
while ( 1 ) {
if ( V_78 != V_329 )
F_111 ( V_78 ) -> V_217 = V_2 -> V_13 ;
F_10 () ;
if ( F_111 ( V_78 ) -> V_330 > V_327 ) {
V_4 = F_111 ( V_78 ) -> V_4 ;
V_4 -> V_11 -> V_12 =
V_2 -> V_13 ;
V_8 = 1 ;
break;
}
if ( ! V_183 || ! V_183 -> V_331 || V_326 != V_183 -> V_331 -> V_332 )
break;
if ( F_266 ( V_183 ) )
break;
V_183 = F_267 ( V_183 ) ;
F_268 ( V_328 ) ;
V_328 = V_183 ;
V_78 = V_183 -> V_331 ;
}
F_268 ( V_328 ) ;
V_15:
return V_8 ;
}
static int F_269 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_78 * V_78 ,
struct V_324 * V_183 , int V_333 ,
struct V_5 * V_6 )
{
int V_248 = V_333 ? V_262 : V_320 ;
struct V_325 * V_326 ;
struct V_324 * V_328 = NULL ;
int V_8 = 0 ;
T_1 V_327 = V_4 -> V_11 -> V_308 ;
V_326 = V_78 -> V_332 ;
if ( F_167 ( V_4 , V_334 ) ) {
V_8 = 1 ;
goto V_335;
}
if ( V_4 -> V_11 -> V_12 >
V_4 -> V_11 -> V_308 ) {
V_8 = 1 ;
goto V_335;
}
if ( V_4 != F_111 ( V_78 ) -> V_4 ||
F_270 ( & V_4 -> V_190 ) == 0 ) {
V_8 = 1 ;
goto V_335;
}
V_8 = F_265 ( V_2 , V_78 , V_183 ,
V_326 , V_327 ) ;
if ( V_8 )
goto V_335;
if ( F_271 ( V_78 , V_2 -> V_13 ) ) {
V_8 = V_336 ;
goto V_335;
}
V_8 = F_1 ( V_2 , V_4 , V_6 ) ;
if ( V_8 )
goto V_335;
V_8 = F_256 ( V_2 , V_4 , V_78 , V_248 ) ;
if ( V_8 )
goto V_337;
if ( F_131 ( V_78 -> V_143 ) &&
F_111 ( V_78 ) -> V_236 <= V_327 &&
F_111 ( V_78 ) -> V_330 <= V_327 ) {
V_8 = 0 ;
goto V_337;
}
V_248 = V_262 ;
while ( 1 ) {
if ( ! V_183 || ! V_183 -> V_331 || V_326 != V_183 -> V_331 -> V_332 )
break;
V_78 = V_183 -> V_331 ;
if ( V_4 != F_111 ( V_78 ) -> V_4 )
break;
if ( F_111 ( V_78 ) -> V_236 >
V_4 -> V_11 -> V_308 ) {
V_8 = F_256 ( V_2 , V_4 , V_78 , V_248 ) ;
if ( V_8 )
goto V_337;
}
if ( F_266 ( V_183 ) )
break;
V_183 = F_267 ( V_183 ) ;
F_268 ( V_328 ) ;
V_328 = V_183 ;
}
V_8 = 0 ;
V_337:
F_268 ( V_328 ) ;
if ( V_8 < 0 ) {
V_4 -> V_11 -> V_12 = V_2 -> V_13 ;
V_8 = 1 ;
}
if ( V_8 )
F_160 ( V_4 , V_6 ) ;
F_12 ( V_4 ) ;
V_335:
return V_8 ;
}
int F_272 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_324 * V_324 ,
struct V_5 * V_6 )
{
struct V_324 * V_183 = F_267 ( V_324 ) ;
int V_8 ;
V_8 = F_269 ( V_2 , V_4 , V_324 -> V_331 , V_183 ,
0 , V_6 ) ;
F_268 ( V_183 ) ;
return V_8 ;
}
int F_273 ( struct V_3 * V_26 )
{
int V_8 ;
struct V_41 * V_42 ;
struct V_1 * V_2 ;
struct V_44 V_45 ;
struct V_44 V_146 ;
struct V_44 V_338 ;
struct V_3 * log ;
struct V_213 * V_11 = V_26 -> V_11 ;
struct V_31 V_32 = {
. V_186 = F_16 ,
. V_173 = 0 ,
} ;
V_42 = F_84 () ;
if ( ! V_42 )
return - V_64 ;
V_11 -> V_339 = 1 ;
V_2 = F_274 ( V_11 -> V_210 , 0 ) ;
if ( F_81 ( V_2 ) ) {
V_8 = F_129 ( V_2 ) ;
goto error;
}
V_32 . V_2 = V_2 ;
V_32 . V_35 = 1 ;
V_8 = F_148 ( V_2 , V_26 , & V_32 ) ;
if ( V_8 ) {
F_275 ( V_11 , V_8 , L_1
L_2 ) ;
goto error;
}
V_125:
V_45 . V_55 = V_56 ;
V_45 . V_76 = ( T_1 ) - 1 ;
F_115 ( & V_45 , V_340 ) ;
while ( 1 ) {
V_8 = F_28 ( NULL , V_26 , & V_45 , V_42 , 0 , 0 ) ;
if ( V_8 < 0 ) {
F_275 ( V_11 , V_8 ,
L_3 ) ;
goto error;
}
if ( V_8 > 0 ) {
if ( V_42 -> V_61 [ 0 ] == 0 )
break;
V_42 -> V_61 [ 0 ] -- ;
}
F_108 ( V_42 -> V_60 [ 0 ] , & V_146 ,
V_42 -> V_61 [ 0 ] ) ;
F_29 ( V_42 ) ;
if ( V_146 . V_55 != V_56 )
break;
log = F_276 ( V_26 , & V_146 ) ;
if ( F_81 ( log ) ) {
V_8 = F_129 ( log ) ;
F_275 ( V_11 , V_8 ,
L_4 ) ;
goto error;
}
V_338 . V_55 = V_146 . V_76 ;
V_338 . type = V_340 ;
V_338 . V_76 = ( T_1 ) - 1 ;
V_32 . V_170 = F_277 ( V_11 , & V_338 ) ;
if ( F_81 ( V_32 . V_170 ) ) {
V_8 = F_129 ( V_32 . V_170 ) ;
F_139 ( log -> V_187 ) ;
F_139 ( log -> V_341 ) ;
F_31 ( log ) ;
F_275 ( V_11 , V_8 , L_5
L_6 ) ;
goto error;
}
V_32 . V_170 -> V_10 = log ;
F_278 ( V_2 , V_32 . V_170 ) ;
V_8 = F_148 ( V_2 , log , & V_32 ) ;
if ( ! V_8 && V_32 . V_173 == V_176 ) {
V_8 = F_113 ( V_2 , V_32 . V_170 ,
V_42 ) ;
}
V_45 . V_76 = V_146 . V_76 - 1 ;
V_32 . V_170 -> V_10 = NULL ;
F_139 ( log -> V_187 ) ;
F_139 ( log -> V_341 ) ;
F_31 ( log ) ;
if ( V_8 )
goto error;
if ( V_146 . V_76 == 0 )
break;
}
F_29 ( V_42 ) ;
if ( V_32 . V_35 ) {
V_32 . V_35 = 0 ;
V_32 . V_186 = F_130 ;
V_32 . V_173 = V_174 ;
goto V_125;
}
if ( V_32 . V_173 < V_176 ) {
V_32 . V_173 ++ ;
goto V_125;
}
F_88 ( V_42 ) ;
V_8 = F_279 ( V_2 , V_11 -> V_210 ) ;
if ( V_8 )
return V_8 ;
F_139 ( V_26 -> V_187 ) ;
V_26 -> V_10 = NULL ;
V_11 -> V_339 = 0 ;
F_31 ( V_26 ) ;
return 0 ;
error:
if ( V_32 . V_2 )
F_280 ( V_32 . V_2 , V_11 -> V_210 ) ;
F_88 ( V_42 ) ;
return V_8 ;
}
void F_281 ( struct V_1 * V_2 ,
struct V_78 * V_99 , struct V_78 * V_78 ,
int V_342 )
{
if ( F_131 ( V_78 -> V_143 ) )
F_111 ( V_78 ) -> V_330 = V_2 -> V_13 ;
F_10 () ;
if ( F_111 ( V_99 ) -> V_217 == V_2 -> V_13 )
return;
if ( F_111 ( V_78 ) -> V_217 == V_2 -> V_13 )
return;
if ( V_342 )
goto V_343;
return;
V_343:
F_111 ( V_99 ) -> V_330 = V_2 -> V_13 ;
}
int F_282 ( struct V_1 * V_2 ,
struct V_78 * V_78 , struct V_78 * V_344 ,
struct V_324 * V_183 )
{
struct V_3 * V_4 = F_111 ( V_78 ) -> V_4 ;
if ( F_131 ( V_78 -> V_143 ) )
F_111 ( V_78 ) -> V_330 = V_2 -> V_13 ;
if ( F_111 ( V_78 ) -> V_217 <=
V_4 -> V_11 -> V_308 &&
( ! V_344 || F_111 ( V_344 ) -> V_217 <=
V_4 -> V_11 -> V_308 ) )
return 0 ;
return F_269 ( V_2 , V_4 , V_78 , V_183 , 1 , NULL ) ;
}
