static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
int V_7 ;
int V_8 ;
F_2 ( & V_4 -> V_9 ) ;
if ( V_4 -> V_10 ) {
if ( F_3 ( V_4 -> V_11 , V_2 ) ) {
V_8 = - V_12 ;
goto V_13;
}
if ( ! V_4 -> V_14 ) {
V_4 -> V_14 = V_15 -> V_16 ;
F_4 ( V_17 , & V_4 -> V_18 ) ;
} else if ( V_4 -> V_14 != V_15 -> V_16 ) {
F_5 ( V_17 , & V_4 -> V_18 ) ;
}
F_6 ( & V_4 -> V_19 ) ;
F_6 ( & V_4 -> V_20 ) ;
if ( V_6 ) {
V_7 = V_4 -> V_21 % 2 ;
F_7 ( & V_6 -> V_22 , & V_4 -> V_23 [ V_7 ] ) ;
V_6 -> V_21 = V_4 -> V_21 ;
}
F_8 ( & V_4 -> V_9 ) ;
return 0 ;
}
V_8 = 0 ;
F_2 ( & V_4 -> V_11 -> V_24 ) ;
if ( ! V_4 -> V_11 -> V_25 )
V_8 = F_9 ( V_2 , V_4 -> V_11 ) ;
F_8 ( & V_4 -> V_11 -> V_24 ) ;
if ( V_8 )
goto V_13;
if ( ! V_4 -> V_10 ) {
V_8 = F_10 ( V_2 , V_4 ) ;
if ( V_8 )
goto V_13;
}
F_4 ( V_17 , & V_4 -> V_18 ) ;
V_4 -> V_14 = V_15 -> V_16 ;
F_6 ( & V_4 -> V_19 ) ;
F_6 ( & V_4 -> V_20 ) ;
if ( V_6 ) {
V_7 = V_4 -> V_21 % 2 ;
F_7 ( & V_6 -> V_22 , & V_4 -> V_23 [ V_7 ] ) ;
V_6 -> V_21 = V_4 -> V_21 ;
}
V_13:
F_8 ( & V_4 -> V_9 ) ;
return V_8 ;
}
static int F_11 ( struct V_3 * V_4 )
{
int V_8 = - V_26 ;
F_12 () ;
if ( ! V_4 -> V_10 )
return - V_26 ;
F_2 ( & V_4 -> V_9 ) ;
if ( V_4 -> V_10 ) {
V_8 = 0 ;
F_6 ( & V_4 -> V_20 ) ;
}
F_8 ( & V_4 -> V_9 ) ;
return V_8 ;
}
int F_13 ( struct V_3 * V_4 )
{
int V_8 = - V_26 ;
F_2 ( & V_4 -> V_9 ) ;
F_6 ( & V_4 -> V_20 ) ;
F_8 ( & V_4 -> V_9 ) ;
return V_8 ;
}
void F_14 ( struct V_3 * V_4 )
{
if ( F_15 ( & V_4 -> V_20 ) ) {
F_12 () ;
if ( F_16 ( & V_4 -> V_27 ) )
F_17 ( & V_4 -> V_27 ) ;
}
}
static int F_18 ( struct V_3 * log ,
struct V_28 * V_29 ,
struct V_30 * V_31 , T_1 V_32 )
{
int V_8 = 0 ;
if ( F_19 ( log -> V_11 , V_33 ) ) {
V_8 = F_20 ( V_29 , V_32 ) ;
if ( V_8 )
return V_8 ;
}
if ( V_31 -> V_34 )
V_8 = F_21 ( log -> V_11 -> V_35 ,
V_29 -> V_36 , V_29 -> V_37 ) ;
if ( ! V_8 && F_22 ( V_29 , V_32 , 0 ) ) {
if ( V_31 -> V_34 && F_23 ( V_29 ) == 0 )
V_8 = F_24 ( log , V_29 ) ;
if ( V_31 -> V_38 )
F_25 ( V_29 ) ;
if ( V_31 -> V_39 )
F_26 ( V_29 ) ;
}
return V_8 ;
}
static T_2 int F_27 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_40 * V_41 ,
struct V_28 * V_29 , int V_42 ,
struct V_43 * V_44 )
{
int V_8 ;
T_3 V_45 ;
T_1 V_46 = 0 ;
int V_47 = 0 ;
unsigned long V_48 ;
unsigned long V_49 ;
int V_50 = 0 ;
bool V_51 = V_44 -> type == V_52 ;
if ( V_4 -> V_53 . V_54 != V_55 )
V_50 = 1 ;
V_45 = F_28 ( V_29 , V_42 ) ;
V_48 = F_29 ( V_29 , V_42 ) ;
V_8 = F_30 ( NULL , V_4 , V_44 , V_41 , 0 , 0 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( V_8 == 0 ) {
char * V_56 ;
char * V_57 ;
T_3 V_58 = F_28 ( V_41 -> V_59 [ 0 ] ,
V_41 -> V_60 [ 0 ] ) ;
if ( V_58 != V_45 )
goto V_61;
if ( V_45 == 0 ) {
F_31 ( V_41 ) ;
return 0 ;
}
V_57 = F_32 ( V_45 , V_62 ) ;
V_56 = F_32 ( V_45 , V_62 ) ;
if ( ! V_57 || ! V_56 ) {
F_31 ( V_41 ) ;
F_33 ( V_57 ) ;
F_33 ( V_56 ) ;
return - V_63 ;
}
F_34 ( V_29 , V_56 , V_48 , V_45 ) ;
V_49 = F_29 ( V_41 -> V_59 [ 0 ] , V_41 -> V_60 [ 0 ] ) ;
F_34 ( V_41 -> V_59 [ 0 ] , V_57 , V_49 ,
V_45 ) ;
V_8 = memcmp ( V_57 , V_56 , V_45 ) ;
F_33 ( V_57 ) ;
F_33 ( V_56 ) ;
if ( V_8 == 0 ) {
F_31 ( V_41 ) ;
return 0 ;
}
if ( V_51 ) {
struct V_64 * V_65 ;
T_1 V_66 ;
T_3 V_67 ;
V_65 = F_35 ( V_41 -> V_59 [ 0 ] , V_41 -> V_60 [ 0 ] ,
struct V_64 ) ;
V_66 = F_36 ( V_41 -> V_59 [ 0 ] , V_65 ) ;
V_65 = F_35 ( V_29 , V_42 ,
struct V_64 ) ;
F_37 ( V_29 , V_65 , V_66 ) ;
V_67 = F_38 ( V_29 , V_65 ) ;
if ( F_39 ( V_67 ) )
F_40 ( V_29 , V_65 , 0 ) ;
}
} else if ( V_51 ) {
struct V_64 * V_65 ;
T_3 V_67 ;
V_65 = F_35 ( V_29 , V_42 , struct V_64 ) ;
F_37 ( V_29 , V_65 , 0 ) ;
V_67 = F_38 ( V_29 , V_65 ) ;
if ( F_39 ( V_67 ) )
F_40 ( V_29 , V_65 , 0 ) ;
}
V_61:
F_31 ( V_41 ) ;
V_8 = F_41 ( V_2 , V_4 , V_41 ,
V_44 , V_45 ) ;
if ( V_8 == - V_68 ) {
T_3 V_69 ;
V_69 = F_28 ( V_41 -> V_59 [ 0 ] ,
V_41 -> V_60 [ 0 ] ) ;
if ( V_69 > V_45 )
F_42 ( V_4 , V_41 , V_45 , 1 ) ;
else if ( V_69 < V_45 )
F_43 ( V_4 , V_41 ,
V_45 - V_69 ) ;
} else if ( V_8 ) {
return V_8 ;
}
V_49 = F_29 ( V_41 -> V_59 [ 0 ] ,
V_41 -> V_60 [ 0 ] ) ;
if ( V_44 -> type == V_52 && V_8 == - V_68 ) {
struct V_64 * V_70 ;
struct V_64 * V_71 ;
V_70 = (struct V_64 * ) V_48 ;
V_71 = (struct V_64 * ) V_49 ;
if ( F_44 ( V_29 , V_70 ) == 0 )
goto V_72;
if ( V_50 &&
F_39 ( F_38 ( V_29 , V_70 ) ) &&
F_39 ( F_38 ( V_41 -> V_59 [ 0 ] , V_71 ) ) ) {
V_47 = 1 ;
V_46 = F_45 ( V_41 -> V_59 [ 0 ] ,
V_71 ) ;
}
}
F_46 ( V_41 -> V_59 [ 0 ] , V_29 , V_49 ,
V_48 , V_45 ) ;
if ( V_47 ) {
struct V_64 * V_71 ;
V_71 = (struct V_64 * ) V_49 ;
F_40 ( V_41 -> V_59 [ 0 ] , V_71 , V_46 ) ;
}
if ( V_44 -> type == V_52 ) {
struct V_64 * V_71 ;
V_71 = (struct V_64 * ) V_49 ;
if ( F_44 ( V_41 -> V_59 [ 0 ] , V_71 ) == 0 ) {
F_47 ( V_41 -> V_59 [ 0 ] , V_71 ,
V_2 -> V_73 ) ;
}
}
V_72:
F_48 ( V_41 -> V_59 [ 0 ] ) ;
F_31 ( V_41 ) ;
return 0 ;
}
T_2 int F_49 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_40 * V_41 ,
struct V_28 * V_29 , int V_42 ,
struct V_43 * V_44 )
{
int V_74 ;
T_1 V_75 ;
T_1 V_36 = V_44 -> V_76 ;
T_1 V_66 = 0 ;
struct V_77 * V_65 ;
struct V_78 * V_78 = NULL ;
unsigned long V_79 ;
int V_8 = 0 ;
V_65 = F_35 ( V_29 , V_42 , struct V_77 ) ;
V_74 = F_50 ( V_29 , V_65 ) ;
if ( V_74 == V_80 ||
V_74 == V_81 ) {
V_66 = F_51 ( V_29 , V_65 ) ;
V_75 = V_36 + V_66 ;
if ( F_52 ( V_29 , V_65 ) == 0 )
V_66 = 0 ;
} else if ( V_74 == V_82 ) {
V_79 = F_53 ( V_29 , V_42 , V_65 ) ;
V_66 = F_54 ( V_29 , V_65 ) ;
V_75 = F_55 ( V_36 + V_79 , V_4 -> V_83 ) ;
} else {
V_8 = 0 ;
goto V_13;
}
V_78 = F_56 ( V_4 , V_44 -> V_54 ) ;
if ( ! V_78 ) {
V_8 = - V_84 ;
goto V_13;
}
V_8 = F_57 ( V_2 , V_4 , V_41 , F_58 ( V_78 ) ,
V_36 , 0 ) ;
if ( V_8 == 0 &&
( V_74 == V_80 ||
V_74 == V_81 ) ) {
struct V_77 V_85 ;
struct V_77 V_86 ;
struct V_77 * V_87 ;
struct V_28 * V_88 ;
V_88 = V_41 -> V_59 [ 0 ] ;
V_87 = F_35 ( V_88 , V_41 -> V_60 [ 0 ] ,
struct V_77 ) ;
F_34 ( V_29 , & V_85 , ( unsigned long ) V_65 ,
sizeof( V_85 ) ) ;
F_34 ( V_88 , & V_86 , ( unsigned long ) V_87 ,
sizeof( V_86 ) ) ;
if ( memcmp ( & V_85 , & V_86 , sizeof( V_85 ) ) == 0 ) {
F_31 ( V_41 ) ;
goto V_13;
}
}
F_31 ( V_41 ) ;
V_8 = F_59 ( V_2 , V_4 , V_78 , V_36 , V_75 , 1 ) ;
if ( V_8 )
goto V_13;
if ( V_74 == V_80 ||
V_74 == V_81 ) {
T_1 V_76 ;
unsigned long V_89 ;
struct V_43 V_90 ;
V_8 = F_41 ( V_2 , V_4 , V_41 , V_44 ,
sizeof( * V_65 ) ) ;
if ( V_8 )
goto V_13;
V_89 = F_29 ( V_41 -> V_59 [ 0 ] ,
V_41 -> V_60 [ 0 ] ) ;
F_46 ( V_41 -> V_59 [ 0 ] , V_29 , V_89 ,
( unsigned long ) V_65 , sizeof( * V_65 ) ) ;
V_90 . V_54 = F_52 ( V_29 , V_65 ) ;
V_90 . V_76 = F_60 ( V_29 , V_65 ) ;
V_90 . type = V_91 ;
V_76 = V_44 -> V_76 - F_61 ( V_29 , V_65 ) ;
if ( V_90 . V_54 > 0 ) {
T_1 V_92 ;
T_1 V_93 ;
F_62 ( V_94 ) ;
V_8 = F_63 ( V_4 , V_90 . V_54 ,
V_90 . V_76 ) ;
if ( V_8 == 0 ) {
V_8 = F_64 ( V_2 , V_4 ,
V_90 . V_54 , V_90 . V_76 ,
0 , V_4 -> V_53 . V_54 ,
V_44 -> V_54 , V_76 , 0 ) ;
if ( V_8 )
goto V_13;
} else {
V_8 = F_65 ( V_2 ,
V_4 , V_4 -> V_53 . V_54 ,
V_44 -> V_54 , V_76 , & V_90 ) ;
if ( V_8 )
goto V_13;
}
F_31 ( V_41 ) ;
if ( F_66 ( V_29 , V_65 ) ) {
V_92 = V_90 . V_54 ;
V_93 = V_92 + V_90 . V_76 ;
} else {
V_92 = V_90 . V_54 +
F_61 ( V_29 , V_65 ) ;
V_93 = V_92 +
F_51 ( V_29 , V_65 ) ;
}
V_8 = F_67 ( V_4 -> V_10 ,
V_92 , V_93 - 1 ,
& V_94 , 0 ) ;
if ( V_8 )
goto V_13;
while ( ! F_68 ( & V_94 ) ) {
struct V_95 * V_96 ;
V_96 = F_69 ( V_94 . V_97 ,
struct V_95 ,
V_22 ) ;
if ( ! V_8 )
V_8 = F_70 ( V_2 ,
V_4 -> V_11 -> V_98 ,
V_96 ) ;
F_71 ( & V_96 -> V_22 ) ;
F_33 ( V_96 ) ;
}
if ( V_8 )
goto V_13;
} else {
F_31 ( V_41 ) ;
}
} else if ( V_74 == V_82 ) {
V_8 = F_27 ( V_2 , V_4 , V_41 , V_29 , V_42 , V_44 ) ;
if ( V_8 )
goto V_13;
}
F_72 ( V_78 , V_66 ) ;
V_8 = F_73 ( V_2 , V_4 , V_78 ) ;
V_13:
if ( V_78 )
F_74 ( V_78 ) ;
return V_8 ;
}
static T_2 int F_75 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_40 * V_41 ,
struct V_78 * V_99 ,
struct V_100 * V_101 )
{
struct V_78 * V_78 ;
char * V_102 ;
int V_103 ;
struct V_28 * V_88 ;
struct V_43 V_104 ;
int V_8 ;
V_88 = V_41 -> V_59 [ 0 ] ;
F_76 ( V_88 , V_101 , & V_104 ) ;
V_103 = F_77 ( V_88 , V_101 ) ;
V_102 = F_32 ( V_103 , V_62 ) ;
if ( ! V_102 )
return - V_63 ;
F_34 ( V_88 , V_102 , ( unsigned long ) ( V_101 + 1 ) , V_103 ) ;
F_31 ( V_41 ) ;
V_78 = F_56 ( V_4 , V_104 . V_54 ) ;
if ( ! V_78 ) {
V_8 = - V_84 ;
goto V_13;
}
V_8 = F_78 ( V_2 , V_4 , V_41 , V_104 . V_54 ) ;
if ( V_8 )
goto V_13;
V_8 = F_79 ( V_2 , V_4 , V_99 , V_78 , V_102 , V_103 ) ;
if ( V_8 )
goto V_13;
else
V_8 = F_80 ( V_2 , V_4 ) ;
V_13:
F_33 ( V_102 ) ;
F_74 ( V_78 ) ;
return V_8 ;
}
static T_2 int F_81 ( struct V_3 * V_4 ,
struct V_40 * V_41 ,
T_1 V_105 , T_1 V_54 , T_1 V_7 ,
const char * V_102 , int V_103 )
{
struct V_100 * V_101 ;
struct V_43 V_104 ;
int V_106 = 0 ;
V_101 = F_82 ( NULL , V_4 , V_41 , V_105 ,
V_7 , V_102 , V_103 , 0 ) ;
if ( V_101 && ! F_83 ( V_101 ) ) {
F_76 ( V_41 -> V_59 [ 0 ] , V_101 , & V_104 ) ;
if ( V_104 . V_54 != V_54 )
goto V_13;
} else
goto V_13;
F_31 ( V_41 ) ;
V_101 = F_84 ( NULL , V_4 , V_41 , V_105 , V_102 , V_103 , 0 ) ;
if ( V_101 && ! F_83 ( V_101 ) ) {
F_76 ( V_41 -> V_59 [ 0 ] , V_101 , & V_104 ) ;
if ( V_104 . V_54 != V_54 )
goto V_13;
} else
goto V_13;
V_106 = 1 ;
V_13:
F_31 ( V_41 ) ;
return V_106 ;
}
static T_2 int F_85 ( struct V_3 * log ,
struct V_43 * V_44 ,
T_1 V_107 ,
char * V_102 , int V_108 )
{
struct V_40 * V_41 ;
struct V_109 * V_110 ;
unsigned long V_111 ;
unsigned long V_112 ;
unsigned long V_113 ;
int V_114 ;
int V_45 ;
int V_8 ;
int V_106 = 0 ;
V_41 = F_86 () ;
if ( ! V_41 )
return - V_63 ;
V_8 = F_30 ( NULL , log , V_44 , V_41 , 0 , 0 ) ;
if ( V_8 != 0 )
goto V_13;
V_111 = F_29 ( V_41 -> V_59 [ 0 ] , V_41 -> V_60 [ 0 ] ) ;
if ( V_44 -> type == V_115 ) {
if ( F_87 ( V_41 , V_107 ,
V_102 , V_108 , NULL ) )
V_106 = 1 ;
goto V_13;
}
V_45 = F_28 ( V_41 -> V_59 [ 0 ] , V_41 -> V_60 [ 0 ] ) ;
V_112 = V_111 + V_45 ;
while ( V_111 < V_112 ) {
V_110 = (struct V_109 * ) V_111 ;
V_114 = F_88 ( V_41 -> V_59 [ 0 ] , V_110 ) ;
if ( V_114 == V_108 ) {
V_113 = ( unsigned long ) ( V_110 + 1 ) ;
V_8 = F_89 ( V_41 -> V_59 [ 0 ] , V_102 ,
V_113 , V_108 ) ;
if ( V_8 == 0 ) {
V_106 = 1 ;
goto V_13;
}
}
V_111 = ( unsigned long ) ( V_110 + 1 ) + V_114 ;
}
V_13:
F_90 ( V_41 ) ;
return V_106 ;
}
static inline int F_91 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_40 * V_41 ,
struct V_3 * V_10 ,
struct V_78 * V_99 , struct V_78 * V_78 ,
struct V_28 * V_29 ,
T_1 V_116 , T_1 V_117 ,
T_1 V_118 , char * V_102 , int V_108 ,
int * V_119 )
{
int V_8 ;
char * V_120 ;
int V_121 ;
struct V_28 * V_88 ;
struct V_100 * V_101 ;
struct V_43 V_122 ;
struct V_123 * V_124 ;
V_125:
V_122 . V_54 = V_116 ;
V_122 . type = V_126 ;
V_122 . V_76 = V_117 ;
V_8 = F_30 ( NULL , V_4 , & V_122 , V_41 , 0 , 0 ) ;
if ( V_8 == 0 ) {
struct V_109 * V_127 ;
unsigned long V_111 ;
unsigned long V_112 ;
V_88 = V_41 -> V_59 [ 0 ] ;
if ( V_122 . V_54 == V_122 . V_76 )
return 1 ;
V_111 = F_29 ( V_88 , V_41 -> V_60 [ 0 ] ) ;
V_112 = V_111 + F_28 ( V_88 , V_41 -> V_60 [ 0 ] ) ;
while ( V_111 < V_112 ) {
V_127 = (struct V_109 * ) V_111 ;
V_121 = F_88 ( V_88 ,
V_127 ) ;
V_120 = F_32 ( V_121 , V_62 ) ;
if ( ! V_120 )
return - V_63 ;
F_34 ( V_88 , V_120 ,
( unsigned long ) ( V_127 + 1 ) ,
V_121 ) ;
if ( ! F_85 ( V_10 , & V_122 ,
V_117 ,
V_120 ,
V_121 ) ) {
F_92 ( V_78 ) ;
F_31 ( V_41 ) ;
V_8 = F_79 ( V_2 , V_4 , V_99 ,
V_78 , V_120 ,
V_121 ) ;
F_33 ( V_120 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_80 ( V_2 , V_4 ) ;
if ( V_8 )
return V_8 ;
* V_119 = 1 ;
goto V_125;
}
F_33 ( V_120 ) ;
V_111 = ( unsigned long ) ( V_127 + 1 ) + V_121 ;
}
* V_119 = 1 ;
}
F_31 ( V_41 ) ;
V_124 = F_93 ( NULL , V_4 , V_41 , V_102 , V_108 ,
V_116 , V_117 , 0 ,
0 ) ;
if ( ! F_94 ( V_124 ) ) {
T_3 V_45 ;
T_3 V_128 = 0 ;
unsigned long V_129 ;
struct V_78 * V_130 ;
V_88 = V_41 -> V_59 [ 0 ] ;
V_45 = F_28 ( V_88 , V_41 -> V_60 [ 0 ] ) ;
V_129 = F_29 ( V_88 , V_41 -> V_60 [ 0 ] ) ;
while ( V_128 < V_45 ) {
V_124 = (struct V_123 * ) V_129 + V_128 ;
V_121 = F_95 ( V_88 , V_124 ) ;
if ( F_96 ( V_88 , V_124 ) != V_117 )
goto V_97;
V_120 = F_32 ( V_121 , V_62 ) ;
if ( ! V_120 )
return - V_63 ;
F_34 ( V_88 , V_120 , ( unsigned long ) & V_124 -> V_102 ,
V_121 ) ;
V_122 . V_54 = V_116 ;
V_122 . type = V_115 ;
V_122 . V_76 = F_97 ( V_117 ,
V_120 ,
V_121 ) ;
V_8 = 0 ;
if ( ! F_85 ( V_10 , & V_122 ,
V_117 , V_120 ,
V_121 ) ) {
V_8 = - V_26 ;
V_130 = F_56 ( V_4 ,
V_117 ) ;
if ( V_130 ) {
F_92 ( V_78 ) ;
F_31 ( V_41 ) ;
V_8 = F_79 ( V_2 , V_4 ,
V_130 ,
V_78 ,
V_120 ,
V_121 ) ;
if ( ! V_8 )
V_8 = F_80 (
V_2 , V_4 ) ;
}
F_74 ( V_130 ) ;
F_33 ( V_120 ) ;
if ( V_8 )
return V_8 ;
* V_119 = 1 ;
goto V_125;
}
F_33 ( V_120 ) ;
if ( V_8 )
return V_8 ;
V_97:
V_128 += V_121 + sizeof( * V_124 ) ;
}
* V_119 = 1 ;
}
F_31 ( V_41 ) ;
V_101 = F_82 ( V_2 , V_4 , V_41 , F_58 ( V_99 ) ,
V_118 , V_102 , V_108 , 0 ) ;
if ( V_101 && ! F_83 ( V_101 ) ) {
V_8 = F_75 ( V_2 , V_4 , V_41 , V_99 , V_101 ) ;
if ( V_8 )
return V_8 ;
}
F_31 ( V_41 ) ;
V_101 = F_84 ( V_2 , V_4 , V_41 , F_58 ( V_99 ) ,
V_102 , V_108 , 0 ) ;
if ( V_101 && ! F_83 ( V_101 ) ) {
V_8 = F_75 ( V_2 , V_4 , V_41 , V_99 , V_101 ) ;
if ( V_8 )
return V_8 ;
}
F_31 ( V_41 ) ;
return 0 ;
}
static int F_98 ( struct V_28 * V_29 , unsigned long V_131 ,
T_3 * V_108 , char * * V_102 , T_1 * V_7 ,
T_1 * V_117 )
{
struct V_123 * V_124 ;
V_124 = (struct V_123 * ) V_131 ;
* V_108 = F_95 ( V_29 , V_124 ) ;
* V_102 = F_32 ( * V_108 , V_62 ) ;
if ( * V_102 == NULL )
return - V_63 ;
F_34 ( V_29 , * V_102 , ( unsigned long ) & V_124 -> V_102 ,
* V_108 ) ;
* V_7 = F_99 ( V_29 , V_124 ) ;
if ( V_117 )
* V_117 = F_96 ( V_29 , V_124 ) ;
return 0 ;
}
static int F_100 ( struct V_28 * V_29 , unsigned long V_131 ,
T_3 * V_108 , char * * V_102 , T_1 * V_7 )
{
struct V_109 * V_110 ;
V_110 = (struct V_109 * ) V_131 ;
* V_108 = F_88 ( V_29 , V_110 ) ;
* V_102 = F_32 ( * V_108 , V_62 ) ;
if ( * V_102 == NULL )
return - V_63 ;
F_34 ( V_29 , * V_102 , ( unsigned long ) ( V_110 + 1 ) , * V_108 ) ;
* V_7 = F_101 ( V_29 , V_110 ) ;
return 0 ;
}
static T_2 int F_102 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_3 * log ,
struct V_40 * V_41 ,
struct V_28 * V_29 , int V_42 ,
struct V_43 * V_44 )
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
V_131 = F_29 ( V_29 , V_42 ) ;
V_132 = V_131 + F_28 ( V_29 , V_42 ) ;
if ( V_44 -> type == V_115 ) {
struct V_123 * V_135 ;
V_134 = sizeof( struct V_123 ) ;
V_133 = 1 ;
V_135 = (struct V_123 * ) V_131 ;
V_117 = F_96 ( V_29 , V_135 ) ;
} else {
V_134 = sizeof( struct V_109 ) ;
V_117 = V_44 -> V_76 ;
}
V_116 = V_44 -> V_54 ;
V_99 = F_56 ( V_4 , V_117 ) ;
if ( ! V_99 ) {
V_8 = - V_26 ;
goto V_13;
}
V_78 = F_56 ( V_4 , V_116 ) ;
if ( ! V_78 ) {
V_8 = - V_84 ;
goto V_13;
}
while ( V_131 < V_132 ) {
if ( V_133 ) {
V_8 = F_98 ( V_29 , V_131 , & V_108 , & V_102 ,
& V_118 , & V_117 ) ;
if ( ! V_99 )
V_99 = F_56 ( V_4 , V_117 ) ;
if ( ! V_99 ) {
V_8 = - V_26 ;
goto V_13;
}
} else {
V_8 = F_100 ( V_29 , V_131 , & V_108 , & V_102 ,
& V_118 ) ;
}
if ( V_8 )
goto V_13;
if ( ! F_81 ( V_4 , V_41 , F_58 ( V_99 ) , F_58 ( V_78 ) ,
V_118 , V_102 , V_108 ) ) {
if ( ! V_119 ) {
V_8 = F_91 ( V_2 , V_4 , V_41 , log ,
V_99 , V_78 , V_29 ,
V_116 ,
V_117 ,
V_118 , V_102 , V_108 ,
& V_119 ) ;
if ( V_8 ) {
if ( V_8 == 1 )
V_8 = 0 ;
goto V_13;
}
}
V_8 = F_103 ( V_2 , V_99 , V_78 , V_102 , V_108 ,
0 , V_118 ) ;
if ( V_8 )
goto V_13;
F_73 ( V_2 , V_4 , V_78 ) ;
}
V_131 = ( unsigned long ) ( V_131 + V_134 ) + V_108 ;
F_33 ( V_102 ) ;
V_102 = NULL ;
if ( V_133 ) {
F_74 ( V_99 ) ;
V_99 = NULL ;
}
}
V_8 = F_27 ( V_2 , V_4 , V_41 , V_29 , V_42 , V_44 ) ;
V_13:
F_31 ( V_41 ) ;
F_33 ( V_102 ) ;
F_74 ( V_99 ) ;
F_74 ( V_78 ) ;
return V_8 ;
}
static int F_104 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_1 V_76 )
{
int V_8 ;
V_8 = F_105 ( V_4 , NULL , V_136 ,
V_76 , V_137 , NULL ) ;
if ( V_8 > 0 )
V_8 = F_106 ( V_2 , V_4 , V_76 ) ;
return V_8 ;
}
static int F_107 ( struct V_3 * V_4 ,
struct V_78 * V_78 , struct V_40 * V_41 )
{
int V_8 = 0 ;
int V_103 ;
unsigned int V_138 = 0 ;
T_3 V_45 ;
T_3 V_128 = 0 ;
T_1 V_116 = F_58 ( V_78 ) ;
T_1 V_76 = 0 ;
unsigned long V_111 ;
struct V_123 * V_124 ;
struct V_28 * V_88 ;
while ( 1 ) {
V_8 = F_108 ( V_4 , V_116 , V_76 , V_41 ,
& V_124 , & V_76 ) ;
if ( V_8 )
break;
V_88 = V_41 -> V_59 [ 0 ] ;
V_45 = F_28 ( V_88 , V_41 -> V_60 [ 0 ] ) ;
V_111 = F_29 ( V_88 , V_41 -> V_60 [ 0 ] ) ;
while ( V_128 < V_45 ) {
V_124 = (struct V_123 * ) ( V_111 + V_128 ) ;
V_103 = F_95 ( V_88 , V_124 ) ;
V_138 ++ ;
V_128 += V_103 + sizeof( * V_124 ) ;
}
V_76 ++ ;
F_31 ( V_41 ) ;
}
F_31 ( V_41 ) ;
if ( V_8 < 0 )
return V_8 ;
return V_138 ;
}
static int F_109 ( struct V_3 * V_4 ,
struct V_78 * V_78 , struct V_40 * V_41 )
{
int V_8 ;
struct V_43 V_44 ;
unsigned int V_138 = 0 ;
unsigned long V_111 ;
unsigned long V_112 ;
int V_103 ;
T_1 V_139 = F_58 ( V_78 ) ;
V_44 . V_54 = V_139 ;
V_44 . type = V_126 ;
V_44 . V_76 = ( T_1 ) - 1 ;
while ( 1 ) {
V_8 = F_30 ( NULL , V_4 , & V_44 , V_41 , 0 , 0 ) ;
if ( V_8 < 0 )
break;
if ( V_8 > 0 ) {
if ( V_41 -> V_60 [ 0 ] == 0 )
break;
V_41 -> V_60 [ 0 ] -- ;
}
V_140:
F_110 ( V_41 -> V_59 [ 0 ] , & V_44 ,
V_41 -> V_60 [ 0 ] ) ;
if ( V_44 . V_54 != V_139 ||
V_44 . type != V_126 )
break;
V_111 = F_29 ( V_41 -> V_59 [ 0 ] , V_41 -> V_60 [ 0 ] ) ;
V_112 = V_111 + F_28 ( V_41 -> V_59 [ 0 ] ,
V_41 -> V_60 [ 0 ] ) ;
while ( V_111 < V_112 ) {
struct V_109 * V_110 ;
V_110 = (struct V_109 * ) V_111 ;
V_103 = F_88 ( V_41 -> V_59 [ 0 ] ,
V_110 ) ;
V_111 = ( unsigned long ) ( V_110 + 1 ) + V_103 ;
V_138 ++ ;
}
if ( V_44 . V_76 == 0 )
break;
if ( V_41 -> V_60 [ 0 ] > 0 ) {
V_41 -> V_60 [ 0 ] -- ;
goto V_140;
}
V_44 . V_76 -- ;
F_31 ( V_41 ) ;
}
F_31 ( V_41 ) ;
return V_138 ;
}
static T_2 int F_111 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_78 * V_78 )
{
struct V_40 * V_41 ;
int V_8 ;
T_1 V_138 = 0 ;
T_1 V_139 = F_58 ( V_78 ) ;
V_41 = F_86 () ;
if ( ! V_41 )
return - V_63 ;
V_8 = F_109 ( V_4 , V_78 , V_41 ) ;
if ( V_8 < 0 )
goto V_13;
V_138 = V_8 ;
V_8 = F_107 ( V_4 , V_78 , V_41 ) ;
if ( V_8 == - V_26 )
V_8 = 0 ;
if ( V_8 < 0 )
goto V_13;
V_138 += V_8 ;
V_8 = 0 ;
if ( V_138 != V_78 -> V_141 ) {
F_112 ( V_78 , V_138 ) ;
F_73 ( V_2 , V_4 , V_78 ) ;
}
F_113 ( V_78 ) -> V_142 = ( T_1 ) - 1 ;
if ( V_78 -> V_141 == 0 ) {
if ( F_39 ( V_78 -> V_143 ) ) {
V_8 = F_114 ( V_2 , V_4 , NULL , V_41 ,
V_139 , 1 ) ;
if ( V_8 )
goto V_13;
}
V_8 = F_104 ( V_2 , V_4 , V_139 ) ;
}
V_13:
F_90 ( V_41 ) ;
return V_8 ;
}
static T_2 int F_115 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_40 * V_41 )
{
int V_8 ;
struct V_43 V_44 ;
struct V_78 * V_78 ;
V_44 . V_54 = V_144 ;
V_44 . type = V_137 ;
V_44 . V_76 = ( T_1 ) - 1 ;
while ( 1 ) {
V_8 = F_30 ( V_2 , V_4 , & V_44 , V_41 , - 1 , 1 ) ;
if ( V_8 < 0 )
break;
if ( V_8 == 1 ) {
if ( V_41 -> V_60 [ 0 ] == 0 )
break;
V_41 -> V_60 [ 0 ] -- ;
}
F_110 ( V_41 -> V_59 [ 0 ] , & V_44 , V_41 -> V_60 [ 0 ] ) ;
if ( V_44 . V_54 != V_144 ||
V_44 . type != V_137 )
break;
V_8 = F_116 ( V_2 , V_4 , V_41 ) ;
if ( V_8 )
goto V_13;
F_31 ( V_41 ) ;
V_78 = F_56 ( V_4 , V_44 . V_76 ) ;
if ( ! V_78 )
return - V_84 ;
V_8 = F_111 ( V_2 , V_4 , V_78 ) ;
F_74 ( V_78 ) ;
if ( V_8 )
goto V_13;
V_44 . V_76 = ( T_1 ) - 1 ;
}
V_8 = 0 ;
V_13:
F_31 ( V_41 ) ;
return V_8 ;
}
static T_2 int F_78 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_40 * V_41 ,
T_1 V_54 )
{
struct V_43 V_44 ;
int V_8 = 0 ;
struct V_78 * V_78 ;
V_78 = F_56 ( V_4 , V_54 ) ;
if ( ! V_78 )
return - V_84 ;
V_44 . V_54 = V_144 ;
V_44 . type = V_137 ;
V_44 . V_76 = V_54 ;
V_8 = F_41 ( V_2 , V_4 , V_41 , & V_44 , 0 ) ;
F_31 ( V_41 ) ;
if ( V_8 == 0 ) {
if ( ! V_78 -> V_141 )
F_112 ( V_78 , 1 ) ;
else
F_92 ( V_78 ) ;
V_8 = F_73 ( V_2 , V_4 , V_78 ) ;
} else if ( V_8 == - V_68 ) {
V_8 = 0 ;
} else {
F_117 () ;
}
F_74 ( V_78 ) ;
return V_8 ;
}
static T_2 int F_118 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_40 * V_41 ,
T_1 V_105 , T_1 V_7 ,
char * V_102 , int V_103 , T_4 type ,
struct V_43 * V_104 )
{
struct V_78 * V_78 ;
struct V_78 * V_99 ;
int V_8 ;
V_78 = F_56 ( V_4 , V_104 -> V_54 ) ;
if ( ! V_78 )
return - V_26 ;
V_99 = F_56 ( V_4 , V_105 ) ;
if ( ! V_99 ) {
F_74 ( V_78 ) ;
return - V_84 ;
}
V_8 = F_103 ( V_2 , V_99 , V_78 , V_102 , V_103 , 1 , V_7 ) ;
F_74 ( V_78 ) ;
F_74 ( V_99 ) ;
return V_8 ;
}
static T_2 int F_119 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_40 * V_41 ,
struct V_28 * V_29 ,
struct V_100 * V_101 ,
struct V_43 * V_44 )
{
char * V_102 ;
int V_103 ;
struct V_100 * V_145 ;
struct V_43 V_146 ;
struct V_43 V_147 ;
struct V_78 * V_99 ;
T_4 V_148 ;
int V_149 ;
int V_8 = 0 ;
bool V_150 = ( V_44 -> type == V_151 ) ;
V_99 = F_56 ( V_4 , V_44 -> V_54 ) ;
if ( ! V_99 )
return - V_84 ;
V_103 = F_77 ( V_29 , V_101 ) ;
V_102 = F_32 ( V_103 , V_62 ) ;
if ( ! V_102 ) {
V_8 = - V_63 ;
goto V_13;
}
V_148 = F_120 ( V_29 , V_101 ) ;
F_34 ( V_29 , V_102 , ( unsigned long ) ( V_101 + 1 ) ,
V_103 ) ;
F_76 ( V_29 , V_101 , & V_147 ) ;
V_149 = F_121 ( V_2 , V_4 , V_41 , & V_147 , 0 ) ;
if ( V_149 == 0 )
V_149 = 1 ;
else
V_149 = 0 ;
F_31 ( V_41 ) ;
if ( V_44 -> type == V_152 ) {
V_145 = F_84 ( V_2 , V_4 , V_41 , V_44 -> V_54 ,
V_102 , V_103 , 1 ) ;
} else if ( V_44 -> type == V_151 ) {
V_145 = F_82 ( V_2 , V_4 , V_41 ,
V_44 -> V_54 ,
V_44 -> V_76 , V_102 ,
V_103 , 1 ) ;
} else {
V_8 = - V_153 ;
goto V_13;
}
if ( F_94 ( V_145 ) ) {
if ( V_44 -> type != V_151 )
goto V_13;
goto V_61;
}
F_76 ( V_41 -> V_59 [ 0 ] , V_145 , & V_146 ) ;
if ( V_146 . V_54 == V_147 . V_54 &&
V_146 . type == V_147 . type &&
V_146 . V_76 == V_147 . V_76 &&
F_120 ( V_41 -> V_59 [ 0 ] , V_145 ) == V_148 ) {
V_150 = false ;
goto V_13;
}
if ( ! V_149 )
goto V_13;
V_8 = F_75 ( V_2 , V_4 , V_41 , V_99 , V_145 ) ;
if ( V_8 )
goto V_13;
if ( V_44 -> type == V_151 )
goto V_61;
V_13:
F_31 ( V_41 ) ;
if ( ! V_8 && V_150 ) {
F_122 ( V_99 , V_99 -> V_154 + V_103 * 2 ) ;
V_8 = F_73 ( V_2 , V_4 , V_99 ) ;
}
F_33 ( V_102 ) ;
F_74 ( V_99 ) ;
return V_8 ;
V_61:
F_31 ( V_41 ) ;
V_8 = F_118 ( V_2 , V_4 , V_41 , V_44 -> V_54 , V_44 -> V_76 ,
V_102 , V_103 , V_148 , & V_147 ) ;
if ( V_8 && V_8 != - V_26 )
goto V_13;
V_150 = false ;
V_8 = 0 ;
goto V_13;
}
static T_2 int F_123 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_40 * V_41 ,
struct V_28 * V_29 , int V_42 ,
struct V_43 * V_44 )
{
int V_8 ;
T_3 V_45 = F_28 ( V_29 , V_42 ) ;
struct V_100 * V_101 ;
int V_103 ;
unsigned long V_111 ;
unsigned long V_112 ;
V_111 = F_29 ( V_29 , V_42 ) ;
V_112 = V_111 + V_45 ;
while ( V_111 < V_112 ) {
V_101 = (struct V_100 * ) V_111 ;
if ( F_124 ( V_4 , V_29 , V_101 ) )
return - V_84 ;
V_103 = F_77 ( V_29 , V_101 ) ;
V_8 = F_119 ( V_2 , V_4 , V_41 , V_29 , V_101 , V_44 ) ;
if ( V_8 )
return V_8 ;
V_111 = ( unsigned long ) ( V_101 + 1 ) ;
V_111 += V_103 ;
}
return 0 ;
}
static T_2 int F_125 ( struct V_3 * V_4 ,
struct V_40 * V_41 ,
T_1 V_105 , int V_155 ,
T_1 * V_156 , T_1 * V_157 )
{
struct V_43 V_44 ;
T_1 V_158 ;
struct V_159 * V_65 ;
int V_8 ;
int V_160 ;
if ( * V_156 == ( T_1 ) - 1 )
return 1 ;
V_44 . V_54 = V_105 ;
V_44 . type = V_155 ;
V_44 . V_76 = * V_156 ;
V_8 = F_30 ( NULL , V_4 , & V_44 , V_41 , 0 , 0 ) ;
if ( V_8 < 0 )
goto V_13;
if ( V_8 > 0 ) {
if ( V_41 -> V_60 [ 0 ] == 0 )
goto V_13;
V_41 -> V_60 [ 0 ] -- ;
}
if ( V_8 != 0 )
F_110 ( V_41 -> V_59 [ 0 ] , & V_44 , V_41 -> V_60 [ 0 ] ) ;
if ( V_44 . type != V_155 || V_44 . V_54 != V_105 ) {
V_8 = 1 ;
goto V_97;
}
V_65 = F_35 ( V_41 -> V_59 [ 0 ] , V_41 -> V_60 [ 0 ] ,
struct V_159 ) ;
V_158 = F_126 ( V_41 -> V_59 [ 0 ] , V_65 ) ;
if ( * V_156 >= V_44 . V_76 && * V_156 <= V_158 ) {
V_8 = 0 ;
* V_156 = V_44 . V_76 ;
* V_157 = V_158 ;
goto V_13;
}
V_8 = 1 ;
V_97:
V_160 = F_127 ( V_41 -> V_59 [ 0 ] ) ;
if ( V_41 -> V_60 [ 0 ] >= V_160 ) {
V_8 = F_128 ( V_4 , V_41 ) ;
if ( V_8 )
goto V_13;
} else {
V_41 -> V_60 [ 0 ] ++ ;
}
F_110 ( V_41 -> V_59 [ 0 ] , & V_44 , V_41 -> V_60 [ 0 ] ) ;
if ( V_44 . type != V_155 || V_44 . V_54 != V_105 ) {
V_8 = 1 ;
goto V_13;
}
V_65 = F_35 ( V_41 -> V_59 [ 0 ] , V_41 -> V_60 [ 0 ] ,
struct V_159 ) ;
V_158 = F_126 ( V_41 -> V_59 [ 0 ] , V_65 ) ;
* V_156 = V_44 . V_76 ;
* V_157 = V_158 ;
V_8 = 0 ;
V_13:
F_31 ( V_41 ) ;
return V_8 ;
}
static T_2 int F_129 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_3 * log ,
struct V_40 * V_41 ,
struct V_40 * V_161 ,
struct V_78 * V_99 ,
struct V_43 * V_162 )
{
int V_8 ;
struct V_28 * V_29 ;
int V_42 ;
T_3 V_45 ;
struct V_100 * V_101 ;
struct V_100 * V_163 ;
int V_103 ;
unsigned long V_111 ;
unsigned long V_112 ;
char * V_102 ;
struct V_78 * V_78 ;
struct V_43 V_104 ;
V_125:
V_29 = V_41 -> V_59 [ 0 ] ;
V_42 = V_41 -> V_60 [ 0 ] ;
V_45 = F_28 ( V_29 , V_42 ) ;
V_111 = F_29 ( V_29 , V_42 ) ;
V_112 = V_111 + V_45 ;
while ( V_111 < V_112 ) {
V_101 = (struct V_100 * ) V_111 ;
if ( F_124 ( V_4 , V_29 , V_101 ) ) {
V_8 = - V_84 ;
goto V_13;
}
V_103 = F_77 ( V_29 , V_101 ) ;
V_102 = F_32 ( V_103 , V_62 ) ;
if ( ! V_102 ) {
V_8 = - V_63 ;
goto V_13;
}
F_34 ( V_29 , V_102 , ( unsigned long ) ( V_101 + 1 ) ,
V_103 ) ;
V_163 = NULL ;
if ( log && V_162 -> type == V_152 ) {
V_163 = F_84 ( V_2 , log , V_161 ,
V_162 -> V_54 ,
V_102 , V_103 , 0 ) ;
} else if ( log && V_162 -> type == V_151 ) {
V_163 = F_82 ( V_2 , log ,
V_161 ,
V_162 -> V_54 ,
V_162 -> V_76 ,
V_102 , V_103 , 0 ) ;
}
if ( ! V_163 || ( F_83 ( V_163 ) && F_130 ( V_163 ) == - V_26 ) ) {
F_76 ( V_29 , V_101 , & V_104 ) ;
F_31 ( V_41 ) ;
F_31 ( V_161 ) ;
V_78 = F_56 ( V_4 , V_104 . V_54 ) ;
if ( ! V_78 ) {
F_33 ( V_102 ) ;
return - V_84 ;
}
V_8 = F_78 ( V_2 , V_4 ,
V_41 , V_104 . V_54 ) ;
if ( V_8 ) {
F_33 ( V_102 ) ;
F_74 ( V_78 ) ;
goto V_13;
}
F_92 ( V_78 ) ;
V_8 = F_79 ( V_2 , V_4 , V_99 , V_78 ,
V_102 , V_103 ) ;
if ( ! V_8 )
V_8 = F_80 ( V_2 , V_4 ) ;
F_33 ( V_102 ) ;
F_74 ( V_78 ) ;
if ( V_8 )
goto V_13;
V_8 = F_30 ( NULL , V_4 , V_162 , V_41 ,
0 , 0 ) ;
if ( V_8 == 0 )
goto V_125;
V_8 = 0 ;
goto V_13;
} else if ( F_83 ( V_163 ) ) {
F_33 ( V_102 ) ;
return F_130 ( V_163 ) ;
}
F_31 ( V_161 ) ;
F_33 ( V_102 ) ;
V_111 = ( unsigned long ) ( V_101 + 1 ) ;
V_111 += V_103 ;
}
V_8 = 0 ;
V_13:
F_31 ( V_41 ) ;
F_31 ( V_161 ) ;
return V_8 ;
}
static T_2 int F_114 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_3 * log ,
struct V_40 * V_41 ,
T_1 V_105 , int V_164 )
{
T_1 V_165 ;
T_1 V_166 ;
int V_155 = V_167 ;
int V_8 = 0 ;
struct V_43 V_162 ;
struct V_43 V_146 ;
struct V_40 * V_161 ;
struct V_78 * V_99 ;
V_162 . V_54 = V_105 ;
V_162 . type = V_152 ;
V_161 = F_86 () ;
if ( ! V_161 )
return - V_63 ;
V_99 = F_56 ( V_4 , V_105 ) ;
if ( ! V_99 ) {
F_90 ( V_161 ) ;
return 0 ;
}
V_125:
V_165 = 0 ;
V_166 = 0 ;
while ( 1 ) {
if ( V_164 )
V_166 = ( T_1 ) - 1 ;
else {
V_8 = F_125 ( log , V_41 , V_105 , V_155 ,
& V_165 , & V_166 ) ;
if ( V_8 != 0 )
break;
}
V_162 . V_76 = V_165 ;
while ( 1 ) {
int V_160 ;
V_8 = F_30 ( NULL , V_4 , & V_162 , V_41 ,
0 , 0 ) ;
if ( V_8 < 0 )
goto V_13;
V_160 = F_127 ( V_41 -> V_59 [ 0 ] ) ;
if ( V_41 -> V_60 [ 0 ] >= V_160 ) {
V_8 = F_128 ( V_4 , V_41 ) ;
if ( V_8 )
break;
}
F_110 ( V_41 -> V_59 [ 0 ] , & V_146 ,
V_41 -> V_60 [ 0 ] ) ;
if ( V_146 . V_54 != V_105 ||
V_146 . type != V_162 . type )
goto V_168;
if ( V_146 . V_76 > V_166 )
break;
V_8 = F_129 ( V_2 , V_4 , log , V_41 ,
V_161 , V_99 ,
& V_146 ) ;
if ( V_8 )
goto V_13;
if ( V_146 . V_76 == ( T_1 ) - 1 )
break;
V_162 . V_76 = V_146 . V_76 + 1 ;
}
F_31 ( V_41 ) ;
if ( V_166 == ( T_1 ) - 1 )
break;
V_165 = V_166 + 1 ;
}
V_168:
V_8 = 0 ;
if ( V_155 == V_167 ) {
V_155 = V_169 ;
V_162 . type = V_151 ;
F_31 ( V_41 ) ;
goto V_125;
}
V_13:
F_31 ( V_41 ) ;
F_90 ( V_161 ) ;
F_74 ( V_99 ) ;
return V_8 ;
}
static int F_131 ( struct V_3 * log , struct V_28 * V_29 ,
struct V_30 * V_31 , T_1 V_32 )
{
int V_160 ;
struct V_40 * V_41 ;
struct V_3 * V_4 = V_31 -> V_170 ;
struct V_43 V_44 ;
int V_171 ;
int V_172 ;
int V_8 ;
V_8 = F_20 ( V_29 , V_32 ) ;
if ( V_8 )
return V_8 ;
V_171 = F_23 ( V_29 ) ;
if ( V_171 != 0 )
return 0 ;
V_41 = F_86 () ;
if ( ! V_41 )
return - V_63 ;
V_160 = F_127 ( V_29 ) ;
for ( V_172 = 0 ; V_172 < V_160 ; V_172 ++ ) {
F_110 ( V_29 , & V_44 , V_172 ) ;
if ( V_44 . type == V_52 &&
V_31 -> V_173 == V_174 ) {
struct V_64 * V_51 ;
T_3 V_67 ;
V_51 = F_35 ( V_29 , V_172 ,
struct V_64 ) ;
V_67 = F_38 ( V_29 , V_51 ) ;
if ( F_39 ( V_67 ) ) {
V_8 = F_114 ( V_31 -> V_2 ,
V_4 , log , V_41 , V_44 . V_54 , 0 ) ;
if ( V_8 )
break;
}
V_8 = F_27 ( V_31 -> V_2 , V_4 , V_41 ,
V_29 , V_172 , & V_44 ) ;
if ( V_8 )
break;
if ( F_132 ( V_67 ) ) {
V_8 = F_104 ( V_31 -> V_2 , V_4 ,
V_44 . V_54 ) ;
if ( V_8 )
break;
}
V_8 = F_78 ( V_31 -> V_2 , V_4 ,
V_41 , V_44 . V_54 ) ;
if ( V_8 )
break;
}
if ( V_44 . type == V_151 &&
V_31 -> V_173 == V_175 ) {
V_8 = F_123 ( V_31 -> V_2 , V_4 , V_41 ,
V_29 , V_172 , & V_44 ) ;
if ( V_8 )
break;
}
if ( V_31 -> V_173 < V_176 )
continue;
if ( V_44 . type == V_177 ) {
V_8 = F_27 ( V_31 -> V_2 , V_4 , V_41 ,
V_29 , V_172 , & V_44 ) ;
if ( V_8 )
break;
} else if ( V_44 . type == V_126 ||
V_44 . type == V_115 ) {
V_8 = F_102 ( V_31 -> V_2 , V_4 , log , V_41 ,
V_29 , V_172 , & V_44 ) ;
if ( V_8 && V_8 != - V_26 )
break;
V_8 = 0 ;
} else if ( V_44 . type == V_178 ) {
V_8 = F_49 ( V_31 -> V_2 , V_4 , V_41 ,
V_29 , V_172 , & V_44 ) ;
if ( V_8 )
break;
} else if ( V_44 . type == V_152 ) {
V_8 = F_123 ( V_31 -> V_2 , V_4 , V_41 ,
V_29 , V_172 , & V_44 ) ;
if ( V_8 )
break;
}
}
F_90 ( V_41 ) ;
return V_8 ;
}
static T_2 int F_133 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_40 * V_41 , int * V_171 ,
struct V_30 * V_31 )
{
T_1 V_179 ;
T_1 V_180 ;
T_1 V_181 ;
struct V_28 * V_97 ;
struct V_28 * V_182 ;
struct V_28 * V_183 ;
T_3 V_184 ;
int V_8 = 0 ;
F_134 ( * V_171 < 0 ) ;
F_134 ( * V_171 >= V_185 ) ;
while ( * V_171 > 0 ) {
F_134 ( * V_171 < 0 ) ;
F_134 ( * V_171 >= V_185 ) ;
V_182 = V_41 -> V_59 [ * V_171 ] ;
F_134 ( F_23 ( V_182 ) != * V_171 ) ;
if ( V_41 -> V_60 [ * V_171 ] >=
F_127 ( V_182 ) )
break;
V_180 = F_135 ( V_182 , V_41 -> V_60 [ * V_171 ] ) ;
V_181 = F_136 ( V_182 , V_41 -> V_60 [ * V_171 ] ) ;
V_184 = V_4 -> V_186 ;
V_183 = V_41 -> V_59 [ * V_171 ] ;
V_179 = F_137 ( V_183 ) ;
V_97 = F_138 ( V_4 , V_180 , V_184 ) ;
if ( ! V_97 )
return - V_63 ;
if ( * V_171 == 1 ) {
V_8 = V_31 -> V_187 ( V_4 , V_97 , V_31 , V_181 ) ;
if ( V_8 ) {
F_139 ( V_97 ) ;
return V_8 ;
}
V_41 -> V_60 [ * V_171 ] ++ ;
if ( V_31 -> free ) {
V_8 = F_20 ( V_97 , V_181 ) ;
if ( V_8 ) {
F_139 ( V_97 ) ;
return V_8 ;
}
if ( V_2 ) {
F_140 ( V_97 ) ;
F_141 ( V_97 ) ;
F_142 ( V_2 , V_4 , V_97 ) ;
F_26 ( V_97 ) ;
F_143 ( V_97 ) ;
}
F_134 ( V_179 !=
V_55 ) ;
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
V_8 = F_20 ( V_97 , V_181 ) ;
if ( V_8 ) {
F_139 ( V_97 ) ;
return V_8 ;
}
F_134 ( * V_171 <= 0 ) ;
if ( V_41 -> V_59 [ * V_171 - 1 ] )
F_139 ( V_41 -> V_59 [ * V_171 - 1 ] ) ;
V_41 -> V_59 [ * V_171 - 1 ] = V_97 ;
* V_171 = F_23 ( V_97 ) ;
V_41 -> V_60 [ * V_171 ] = 0 ;
F_145 () ;
}
F_134 ( * V_171 < 0 ) ;
F_134 ( * V_171 >= V_185 ) ;
V_41 -> V_60 [ * V_171 ] = F_127 ( V_41 -> V_59 [ * V_171 ] ) ;
F_145 () ;
return 0 ;
}
static T_2 int F_146 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_40 * V_41 , int * V_171 ,
struct V_30 * V_31 )
{
T_1 V_179 ;
int V_172 ;
int V_42 ;
int V_8 ;
for ( V_172 = * V_171 ; V_172 < V_185 - 1 && V_41 -> V_59 [ V_172 ] ; V_172 ++ ) {
V_42 = V_41 -> V_60 [ V_172 ] ;
if ( V_42 + 1 < F_127 ( V_41 -> V_59 [ V_172 ] ) ) {
V_41 -> V_60 [ V_172 ] ++ ;
* V_171 = V_172 ;
F_134 ( * V_171 == 0 ) ;
return 0 ;
} else {
struct V_28 * V_183 ;
if ( V_41 -> V_59 [ * V_171 ] == V_4 -> V_188 )
V_183 = V_41 -> V_59 [ * V_171 ] ;
else
V_183 = V_41 -> V_59 [ * V_171 + 1 ] ;
V_179 = F_137 ( V_183 ) ;
V_8 = V_31 -> V_187 ( V_4 , V_41 -> V_59 [ * V_171 ] , V_31 ,
F_147 ( V_41 -> V_59 [ * V_171 ] ) ) ;
if ( V_8 )
return V_8 ;
if ( V_31 -> free ) {
struct V_28 * V_97 ;
V_97 = V_41 -> V_59 [ * V_171 ] ;
if ( V_2 ) {
F_140 ( V_97 ) ;
F_141 ( V_97 ) ;
F_142 ( V_2 , V_4 , V_97 ) ;
F_26 ( V_97 ) ;
F_143 ( V_97 ) ;
}
F_134 ( V_179 != V_55 ) ;
V_8 = F_144 ( V_4 ,
V_41 -> V_59 [ * V_171 ] -> V_36 ,
V_41 -> V_59 [ * V_171 ] -> V_37 ) ;
if ( V_8 )
return V_8 ;
}
F_139 ( V_41 -> V_59 [ * V_171 ] ) ;
V_41 -> V_59 [ * V_171 ] = NULL ;
* V_171 = V_172 + 1 ;
}
}
return 1 ;
}
static int F_148 ( struct V_1 * V_2 ,
struct V_3 * log , struct V_30 * V_31 )
{
int V_8 = 0 ;
int V_189 ;
int V_171 ;
struct V_40 * V_41 ;
int V_190 ;
V_41 = F_86 () ;
if ( ! V_41 )
return - V_63 ;
V_171 = F_23 ( log -> V_188 ) ;
V_190 = V_171 ;
V_41 -> V_59 [ V_171 ] = log -> V_188 ;
F_149 ( log -> V_188 ) ;
V_41 -> V_60 [ V_171 ] = 0 ;
while ( 1 ) {
V_189 = F_133 ( V_2 , log , V_41 , & V_171 , V_31 ) ;
if ( V_189 > 0 )
break;
if ( V_189 < 0 ) {
V_8 = V_189 ;
goto V_13;
}
V_189 = F_146 ( V_2 , log , V_41 , & V_171 , V_31 ) ;
if ( V_189 > 0 )
break;
if ( V_189 < 0 ) {
V_8 = V_189 ;
goto V_13;
}
}
if ( V_41 -> V_59 [ V_190 ] ) {
V_8 = V_31 -> V_187 ( log , V_41 -> V_59 [ V_190 ] , V_31 ,
F_147 ( V_41 -> V_59 [ V_190 ] ) ) ;
if ( V_8 )
goto V_13;
if ( V_31 -> free ) {
struct V_28 * V_97 ;
V_97 = V_41 -> V_59 [ V_190 ] ;
if ( V_2 ) {
F_140 ( V_97 ) ;
F_141 ( V_97 ) ;
F_142 ( V_2 , log , V_97 ) ;
F_26 ( V_97 ) ;
F_143 ( V_97 ) ;
}
F_134 ( log -> V_53 . V_54 !=
V_55 ) ;
V_8 = F_144 ( log , V_97 -> V_36 ,
V_97 -> V_37 ) ;
if ( V_8 )
goto V_13;
}
}
V_13:
F_90 ( V_41 ) ;
return V_8 ;
}
static int F_150 ( struct V_1 * V_2 ,
struct V_3 * log )
{
int V_8 ;
if ( log -> V_21 == 1 ) {
V_8 = F_151 ( V_2 , log -> V_11 -> V_25 ,
& log -> V_53 , & log -> V_191 ) ;
} else {
V_8 = F_152 ( V_2 , log -> V_11 -> V_25 ,
& log -> V_53 , & log -> V_191 ) ;
}
return V_8 ;
}
static void F_153 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_73 )
{
F_154 ( V_39 ) ;
int V_7 = V_73 % 2 ;
do {
F_155 ( & V_4 -> V_192 [ V_7 ] ,
& V_39 , V_193 ) ;
F_8 ( & V_4 -> V_9 ) ;
if ( V_4 -> V_194 < V_73 &&
F_156 ( & V_4 -> V_195 [ V_7 ] ) )
F_157 () ;
F_158 ( & V_4 -> V_192 [ V_7 ] , & V_39 ) ;
F_2 ( & V_4 -> V_9 ) ;
} while ( V_4 -> V_194 < V_73 &&
F_156 ( & V_4 -> V_195 [ V_7 ] ) );
}
static void F_159 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_154 ( V_39 ) ;
while ( F_156 ( & V_4 -> V_20 ) ) {
F_155 ( & V_4 -> V_27 ,
& V_39 , V_193 ) ;
F_8 ( & V_4 -> V_9 ) ;
if ( F_156 ( & V_4 -> V_20 ) )
F_157 () ;
F_2 ( & V_4 -> V_9 ) ;
F_158 ( & V_4 -> V_27 , & V_39 ) ;
}
}
static inline void F_160 ( struct V_3 * V_4 ,
struct V_5 * V_6 )
{
if ( ! V_6 )
return;
F_2 ( & V_4 -> V_9 ) ;
F_161 ( & V_6 -> V_22 ) ;
F_8 ( & V_4 -> V_9 ) ;
}
static inline void F_162 ( struct V_3 * V_4 ,
int V_7 , int error )
{
struct V_5 * V_6 ;
if ( ! error ) {
F_163 ( & V_4 -> V_23 [ V_7 ] ) ;
return;
}
F_164 (ctx, &root->log_ctxs[index], list)
V_6 -> V_196 = error ;
F_163 ( & V_4 -> V_23 [ V_7 ] ) ;
}
int F_165 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_5 * V_6 )
{
int V_197 ;
int V_198 ;
int V_199 ;
int V_8 ;
struct V_3 * log = V_4 -> V_10 ;
struct V_3 * V_25 = V_4 -> V_11 -> V_25 ;
int V_21 = 0 ;
struct V_5 V_200 ;
struct V_201 V_202 ;
F_2 ( & V_4 -> V_9 ) ;
V_21 = V_6 -> V_21 ;
if ( V_4 -> V_194 >= V_21 ) {
F_8 ( & V_4 -> V_9 ) ;
return V_6 -> V_196 ;
}
V_197 = V_21 % 2 ;
if ( F_156 ( & V_4 -> V_195 [ V_197 ] ) ) {
F_153 ( V_2 , V_4 , V_21 ) ;
F_8 ( & V_4 -> V_9 ) ;
return V_6 -> V_196 ;
}
ASSERT ( V_21 == V_4 -> V_21 ) ;
F_166 ( & V_4 -> V_195 [ V_197 ] , 1 ) ;
if ( F_156 ( & V_4 -> V_195 [ ( V_197 + 1 ) % 2 ] ) )
F_153 ( V_2 , V_4 , V_21 - 1 ) ;
while ( 1 ) {
int V_203 = F_156 ( & V_4 -> V_19 ) ;
if ( ! F_167 ( V_4 , V_204 ) &&
F_168 ( V_17 , & V_4 -> V_18 ) ) {
F_8 ( & V_4 -> V_9 ) ;
F_169 ( 1 ) ;
F_2 ( & V_4 -> V_9 ) ;
}
F_159 ( V_2 , V_4 ) ;
if ( V_203 == F_156 ( & V_4 -> V_19 ) )
break;
}
if ( F_3 ( V_4 -> V_11 , V_2 ) ) {
V_8 = - V_12 ;
F_170 ( log , V_21 ) ;
F_8 ( & V_4 -> V_9 ) ;
goto V_13;
}
if ( V_21 % 2 == 0 )
V_199 = V_205 ;
else
V_199 = V_206 ;
F_171 ( & V_202 ) ;
V_8 = F_172 ( log , & log -> V_207 , V_199 ) ;
if ( V_8 ) {
F_173 ( & V_202 ) ;
F_174 ( V_2 , V_4 , V_8 ) ;
F_170 ( log , V_21 ) ;
F_175 ( V_4 -> V_11 , V_2 ) ;
F_8 ( & V_4 -> V_9 ) ;
goto V_13;
}
F_176 ( & log -> V_191 , log -> V_188 ) ;
V_4 -> V_21 ++ ;
log -> V_21 = V_4 -> V_21 ;
V_4 -> V_14 = 0 ;
F_8 ( & V_4 -> V_9 ) ;
F_177 ( & V_200 ) ;
F_2 ( & V_25 -> V_9 ) ;
F_6 ( & V_25 -> V_19 ) ;
F_6 ( & V_25 -> V_20 ) ;
V_198 = V_25 -> V_21 % 2 ;
F_7 ( & V_200 . V_22 , & V_25 -> V_23 [ V_198 ] ) ;
V_200 . V_21 = V_25 -> V_21 ;
F_8 ( & V_25 -> V_9 ) ;
V_8 = F_150 ( V_2 , log ) ;
F_2 ( & V_25 -> V_9 ) ;
if ( F_15 ( & V_25 -> V_20 ) ) {
F_12 () ;
if ( F_16 ( & V_25 -> V_27 ) )
F_17 ( & V_25 -> V_27 ) ;
}
if ( V_8 ) {
if ( ! F_68 ( & V_200 . V_22 ) )
F_161 ( & V_200 . V_22 ) ;
F_173 ( & V_202 ) ;
F_175 ( V_4 -> V_11 , V_2 ) ;
if ( V_8 != - V_208 ) {
F_174 ( V_2 , V_4 , V_8 ) ;
F_8 ( & V_25 -> V_9 ) ;
goto V_13;
}
F_178 ( log , & log -> V_207 , V_199 ) ;
F_170 ( log , V_21 ) ;
F_8 ( & V_25 -> V_9 ) ;
V_8 = - V_12 ;
goto V_13;
}
if ( V_25 -> V_194 >= V_200 . V_21 ) {
F_173 ( & V_202 ) ;
F_8 ( & V_25 -> V_9 ) ;
V_8 = V_200 . V_196 ;
goto V_13;
}
V_198 = V_200 . V_21 % 2 ;
if ( F_156 ( & V_25 -> V_195 [ V_198 ] ) ) {
F_173 ( & V_202 ) ;
V_8 = F_178 ( log , & log -> V_207 ,
V_199 ) ;
F_179 ( V_2 , log , V_21 ) ;
F_153 ( V_2 , V_25 ,
V_200 . V_21 ) ;
F_8 ( & V_25 -> V_9 ) ;
if ( ! V_8 )
V_8 = V_200 . V_196 ;
goto V_13;
}
ASSERT ( V_200 . V_21 == V_25 -> V_21 ) ;
F_166 ( & V_25 -> V_195 [ V_198 ] , 1 ) ;
if ( F_156 ( & V_25 -> V_195 [ ( V_198 + 1 ) % 2 ] ) ) {
F_153 ( V_2 , V_25 ,
V_200 . V_21 - 1 ) ;
}
F_159 ( V_2 , V_25 ) ;
if ( F_3 ( V_4 -> V_11 , V_2 ) ) {
F_173 ( & V_202 ) ;
F_178 ( log , & log -> V_207 , V_199 ) ;
F_170 ( log , V_21 ) ;
F_8 ( & V_25 -> V_9 ) ;
V_8 = - V_12 ;
goto V_209;
}
V_8 = F_172 ( V_25 ,
& V_25 -> V_207 ,
V_205 | V_206 ) ;
F_173 ( & V_202 ) ;
if ( V_8 ) {
F_175 ( V_4 -> V_11 , V_2 ) ;
F_174 ( V_2 , V_4 , V_8 ) ;
F_170 ( log , V_21 ) ;
F_8 ( & V_25 -> V_9 ) ;
goto V_209;
}
V_8 = F_178 ( log , & log -> V_207 , V_199 ) ;
if ( ! V_8 )
V_8 = F_178 ( V_25 ,
& V_25 -> V_207 ,
V_206 | V_205 ) ;
if ( V_8 ) {
F_175 ( V_4 -> V_11 , V_2 ) ;
F_170 ( log , V_21 ) ;
F_8 ( & V_25 -> V_9 ) ;
goto V_209;
}
F_179 ( V_2 , log , V_21 ) ;
F_180 ( V_4 -> V_11 -> V_210 ,
V_25 -> V_188 -> V_36 ) ;
F_181 ( V_4 -> V_11 -> V_210 ,
F_23 ( V_25 -> V_188 ) ) ;
V_25 -> V_21 ++ ;
F_8 ( & V_25 -> V_9 ) ;
V_8 = F_182 ( V_2 , V_4 -> V_11 -> V_211 , 1 ) ;
if ( V_8 ) {
F_175 ( V_4 -> V_11 , V_2 ) ;
F_174 ( V_2 , V_4 , V_8 ) ;
goto V_209;
}
F_2 ( & V_4 -> V_9 ) ;
if ( V_4 -> V_212 < V_21 )
V_4 -> V_212 = V_21 ;
F_8 ( & V_4 -> V_9 ) ;
V_209:
F_162 ( V_25 , V_198 , V_8 ) ;
F_2 ( & V_25 -> V_9 ) ;
V_25 -> V_194 ++ ;
F_166 ( & V_25 -> V_195 [ V_198 ] , 0 ) ;
F_8 ( & V_25 -> V_9 ) ;
if ( F_16 ( & V_25 -> V_192 [ V_198 ] ) )
F_17 ( & V_25 -> V_192 [ V_198 ] ) ;
V_13:
F_162 ( V_4 , V_197 , V_8 ) ;
F_2 ( & V_4 -> V_9 ) ;
V_4 -> V_194 ++ ;
F_166 ( & V_4 -> V_195 [ V_197 ] , 0 ) ;
F_8 ( & V_4 -> V_9 ) ;
if ( F_16 ( & V_4 -> V_192 [ V_197 ] ) )
F_17 ( & V_4 -> V_192 [ V_197 ] ) ;
return V_8 ;
}
static void F_183 ( struct V_1 * V_2 ,
struct V_3 * log )
{
int V_8 ;
T_1 V_36 ;
T_1 V_213 ;
struct V_30 V_31 = {
. free = 1 ,
. V_187 = F_18
} ;
V_8 = F_148 ( V_2 , log , & V_31 ) ;
if ( V_8 )
F_174 ( V_2 , log , V_8 ) ;
while ( 1 ) {
V_8 = F_184 ( & log -> V_207 ,
0 , & V_36 , & V_213 , V_205 | V_206 ,
NULL ) ;
if ( V_8 )
break;
F_185 ( & log -> V_207 , V_36 , V_213 ,
V_205 | V_206 , V_62 ) ;
}
F_170 ( log , 0 ) ;
F_170 ( log , 1 ) ;
F_139 ( log -> V_188 ) ;
F_33 ( log ) ;
}
int F_186 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( V_4 -> V_10 ) {
F_183 ( V_2 , V_4 -> V_10 ) ;
V_4 -> V_10 = NULL ;
}
return 0 ;
}
int F_187 ( struct V_1 * V_2 ,
struct V_214 * V_11 )
{
if ( V_11 -> V_25 ) {
F_183 ( V_2 , V_11 -> V_25 ) ;
V_11 -> V_25 = NULL ;
}
return 0 ;
}
int F_188 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_102 , int V_103 ,
struct V_78 * V_99 , T_1 V_7 )
{
struct V_3 * log ;
struct V_100 * V_101 ;
struct V_40 * V_41 ;
int V_8 ;
int V_215 = 0 ;
int V_216 = 0 ;
T_1 V_217 = F_58 ( V_99 ) ;
if ( F_113 ( V_99 ) -> V_218 < V_2 -> V_73 )
return 0 ;
V_8 = F_11 ( V_4 ) ;
if ( V_8 )
return 0 ;
F_2 ( & F_113 ( V_99 ) -> V_9 ) ;
log = V_4 -> V_10 ;
V_41 = F_86 () ;
if ( ! V_41 ) {
V_215 = - V_63 ;
goto V_219;
}
V_101 = F_84 ( V_2 , log , V_41 , V_217 ,
V_102 , V_103 , - 1 ) ;
if ( F_83 ( V_101 ) ) {
V_215 = F_130 ( V_101 ) ;
goto V_220;
}
if ( V_101 ) {
V_8 = F_189 ( V_2 , log , V_41 , V_101 ) ;
V_216 += V_103 ;
if ( V_8 ) {
V_215 = V_8 ;
goto V_220;
}
}
F_31 ( V_41 ) ;
V_101 = F_82 ( V_2 , log , V_41 , V_217 ,
V_7 , V_102 , V_103 , - 1 ) ;
if ( F_83 ( V_101 ) ) {
V_215 = F_130 ( V_101 ) ;
goto V_220;
}
if ( V_101 ) {
V_8 = F_189 ( V_2 , log , V_41 , V_101 ) ;
V_216 += V_103 ;
if ( V_8 ) {
V_215 = V_8 ;
goto V_220;
}
}
if ( V_216 ) {
struct V_43 V_44 ;
V_44 . V_54 = V_217 ;
V_44 . V_76 = 0 ;
V_44 . type = V_52 ;
F_31 ( V_41 ) ;
V_8 = F_30 ( V_2 , log , & V_44 , V_41 , 0 , 1 ) ;
if ( V_8 < 0 ) {
V_215 = V_8 ;
goto V_220;
}
if ( V_8 == 0 ) {
struct V_64 * V_65 ;
T_1 V_154 ;
V_65 = F_35 ( V_41 -> V_59 [ 0 ] , V_41 -> V_60 [ 0 ] ,
struct V_64 ) ;
V_154 = F_45 ( V_41 -> V_59 [ 0 ] , V_65 ) ;
if ( V_154 > V_216 )
V_154 -= V_216 ;
else
V_154 = 0 ;
F_40 ( V_41 -> V_59 [ 0 ] , V_65 , V_154 ) ;
F_48 ( V_41 -> V_59 [ 0 ] ) ;
} else
V_8 = 0 ;
F_31 ( V_41 ) ;
}
V_220:
F_90 ( V_41 ) ;
V_219:
F_8 ( & F_113 ( V_99 ) -> V_9 ) ;
if ( V_8 == - V_208 ) {
F_175 ( V_4 -> V_11 , V_2 ) ;
V_8 = 0 ;
} else if ( V_8 < 0 )
F_174 ( V_2 , V_4 , V_8 ) ;
F_14 ( V_4 ) ;
return V_215 ;
}
int F_190 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_102 , int V_103 ,
struct V_78 * V_78 , T_1 V_105 )
{
struct V_3 * log ;
T_1 V_7 ;
int V_8 ;
if ( F_113 ( V_78 ) -> V_218 < V_2 -> V_73 )
return 0 ;
V_8 = F_11 ( V_4 ) ;
if ( V_8 )
return 0 ;
log = V_4 -> V_10 ;
F_2 ( & F_113 ( V_78 ) -> V_9 ) ;
V_8 = F_191 ( V_2 , log , V_102 , V_103 , F_58 ( V_78 ) ,
V_105 , & V_7 ) ;
F_8 ( & F_113 ( V_78 ) -> V_9 ) ;
if ( V_8 == - V_208 ) {
F_175 ( V_4 -> V_11 , V_2 ) ;
V_8 = 0 ;
} else if ( V_8 < 0 && V_8 != - V_26 )
F_174 ( V_2 , V_4 , V_8 ) ;
F_14 ( V_4 ) ;
return V_8 ;
}
static T_2 int F_192 ( struct V_1 * V_2 ,
struct V_3 * log ,
struct V_40 * V_41 ,
int V_155 , T_1 V_105 ,
T_1 V_221 , T_1 V_222 )
{
int V_8 ;
struct V_43 V_44 ;
struct V_159 * V_65 ;
V_44 . V_54 = V_105 ;
V_44 . V_76 = V_221 ;
if ( V_155 == V_152 )
V_44 . type = V_167 ;
else
V_44 . type = V_169 ;
V_8 = F_41 ( V_2 , log , V_41 , & V_44 , sizeof( * V_65 ) ) ;
if ( V_8 )
return V_8 ;
V_65 = F_35 ( V_41 -> V_59 [ 0 ] , V_41 -> V_60 [ 0 ] ,
struct V_159 ) ;
F_193 ( V_41 -> V_59 [ 0 ] , V_65 , V_222 ) ;
F_48 ( V_41 -> V_59 [ 0 ] ) ;
F_31 ( V_41 ) ;
return 0 ;
}
static T_2 int F_194 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_78 * V_78 ,
struct V_40 * V_41 ,
struct V_40 * V_223 , int V_155 ,
T_1 V_224 , T_1 * V_225 )
{
struct V_43 V_226 ;
struct V_3 * log = V_4 -> V_10 ;
struct V_28 * V_227 ;
int V_215 = 0 ;
int V_8 ;
int V_172 ;
int V_160 ;
T_1 V_221 = V_224 ;
T_1 V_222 = ( T_1 ) - 1 ;
T_1 V_139 = F_58 ( V_78 ) ;
log = V_4 -> V_10 ;
V_226 . V_54 = V_139 ;
V_226 . type = V_155 ;
V_226 . V_76 = V_224 ;
V_8 = F_195 ( V_4 , & V_226 , V_41 , V_2 -> V_73 ) ;
if ( V_8 != 0 || V_226 . V_54 != V_139 || V_226 . type != V_155 ) {
V_226 . V_54 = V_139 ;
V_226 . type = V_155 ;
V_226 . V_76 = ( T_1 ) - 1 ;
F_31 ( V_41 ) ;
V_8 = F_30 ( NULL , V_4 , & V_226 , V_41 , 0 , 0 ) ;
if ( V_8 < 0 ) {
F_31 ( V_41 ) ;
return V_8 ;
}
V_8 = F_196 ( V_4 , V_41 , V_139 , V_155 ) ;
if ( V_8 == 0 ) {
struct V_43 V_228 ;
F_110 ( V_41 -> V_59 [ 0 ] , & V_228 ,
V_41 -> V_60 [ 0 ] ) ;
if ( V_155 == V_228 . type )
V_221 = F_197 ( V_224 , V_228 . V_76 ) + 1 ;
}
goto V_229;
}
V_8 = F_196 ( V_4 , V_41 , V_139 , V_155 ) ;
if ( V_8 == 0 ) {
struct V_43 V_228 ;
F_110 ( V_41 -> V_59 [ 0 ] , & V_228 , V_41 -> V_60 [ 0 ] ) ;
if ( V_155 == V_228 . type ) {
V_221 = V_228 . V_76 ;
V_8 = F_27 ( V_2 , log , V_223 ,
V_41 -> V_59 [ 0 ] , V_41 -> V_60 [ 0 ] ,
& V_228 ) ;
if ( V_8 ) {
V_215 = V_8 ;
goto V_229;
}
}
}
F_31 ( V_41 ) ;
V_8 = F_30 ( NULL , V_4 , & V_226 , V_41 , 0 , 0 ) ;
if ( F_134 ( V_8 != 0 ) )
goto V_229;
while ( 1 ) {
struct V_43 V_228 ;
V_227 = V_41 -> V_59 [ 0 ] ;
V_160 = F_127 ( V_227 ) ;
for ( V_172 = V_41 -> V_60 [ 0 ] ; V_172 < V_160 ; V_172 ++ ) {
F_110 ( V_227 , & V_226 , V_172 ) ;
if ( V_226 . V_54 != V_139 || V_226 . type != V_155 )
goto V_229;
V_8 = F_27 ( V_2 , log , V_223 , V_227 , V_172 ,
& V_226 ) ;
if ( V_8 ) {
V_215 = V_8 ;
goto V_229;
}
}
V_41 -> V_60 [ 0 ] = V_160 ;
V_8 = F_128 ( V_4 , V_41 ) ;
if ( V_8 == 1 ) {
V_222 = ( T_1 ) - 1 ;
goto V_229;
}
F_110 ( V_41 -> V_59 [ 0 ] , & V_228 , V_41 -> V_60 [ 0 ] ) ;
if ( V_228 . V_54 != V_139 || V_228 . type != V_155 ) {
V_222 = ( T_1 ) - 1 ;
goto V_229;
}
if ( F_147 ( V_41 -> V_59 [ 0 ] ) != V_2 -> V_73 ) {
V_8 = F_27 ( V_2 , log , V_223 ,
V_41 -> V_59 [ 0 ] , V_41 -> V_60 [ 0 ] ,
& V_228 ) ;
if ( V_8 )
V_215 = V_8 ;
else
V_222 = V_228 . V_76 ;
goto V_229;
}
}
V_229:
F_31 ( V_41 ) ;
F_31 ( V_223 ) ;
if ( V_215 == 0 ) {
* V_225 = V_222 ;
V_8 = F_192 ( V_2 , log , V_41 , V_155 ,
V_139 , V_221 , V_222 ) ;
if ( V_8 )
V_215 = V_8 ;
}
return V_215 ;
}
static T_2 int F_198 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_78 * V_78 ,
struct V_40 * V_41 ,
struct V_40 * V_223 )
{
T_1 V_226 ;
T_1 V_230 ;
int V_8 ;
int V_155 = V_152 ;
V_125:
V_226 = 0 ;
V_230 = 0 ;
while ( 1 ) {
V_8 = F_194 ( V_2 , V_4 , V_78 , V_41 ,
V_223 , V_155 , V_226 ,
& V_230 ) ;
if ( V_8 )
return V_8 ;
if ( V_230 == ( T_1 ) - 1 )
break;
V_226 = V_230 + 1 ;
}
if ( V_155 == V_152 ) {
V_155 = V_151 ;
goto V_125;
}
return 0 ;
}
static int F_199 ( struct V_1 * V_2 ,
struct V_3 * log ,
struct V_40 * V_41 ,
T_1 V_54 , int V_231 )
{
int V_8 ;
struct V_43 V_44 ;
struct V_43 V_146 ;
int V_232 ;
V_44 . V_54 = V_54 ;
V_44 . type = V_231 ;
V_44 . V_76 = ( T_1 ) - 1 ;
while ( 1 ) {
V_8 = F_30 ( V_2 , log , & V_44 , V_41 , - 1 , 1 ) ;
F_200 ( V_8 == 0 ) ;
if ( V_8 < 0 )
break;
if ( V_41 -> V_60 [ 0 ] == 0 )
break;
V_41 -> V_60 [ 0 ] -- ;
F_110 ( V_41 -> V_59 [ 0 ] , & V_146 ,
V_41 -> V_60 [ 0 ] ) ;
if ( V_146 . V_54 != V_54 )
break;
V_146 . V_76 = 0 ;
V_146 . type = 0 ;
V_8 = F_201 ( V_41 -> V_59 [ 0 ] , & V_146 , 0 ,
& V_232 ) ;
V_8 = F_202 ( V_2 , log , V_41 , V_232 ,
V_41 -> V_60 [ 0 ] - V_232 + 1 ) ;
if ( V_8 || V_232 != 0 )
break;
F_31 ( V_41 ) ;
}
F_31 ( V_41 ) ;
if ( V_8 > 0 )
V_8 = 0 ;
return V_8 ;
}
static void F_203 ( struct V_1 * V_2 ,
struct V_28 * V_88 ,
struct V_64 * V_65 ,
struct V_78 * V_78 , int V_233 )
{
struct V_234 V_235 ;
F_204 ( & V_235 ) ;
if ( V_233 ) {
F_205 ( V_88 , V_65 , 0 , & V_235 ) ;
F_206 ( V_88 , V_65 , 0 , & V_235 ) ;
} else {
F_205 ( V_88 , V_65 ,
F_113 ( V_78 ) -> V_236 ,
& V_235 ) ;
F_206 ( V_88 , V_65 , V_78 -> V_154 , & V_235 ) ;
}
F_207 ( V_88 , V_65 , F_208 ( V_78 ) , & V_235 ) ;
F_209 ( V_88 , V_65 , F_210 ( V_78 ) , & V_235 ) ;
F_211 ( V_88 , V_65 , V_78 -> V_143 , & V_235 ) ;
F_212 ( V_88 , V_65 , V_78 -> V_141 , & V_235 ) ;
F_213 ( V_88 , F_214 ( V_65 ) ,
V_78 -> V_237 . V_238 , & V_235 ) ;
F_215 ( V_88 , F_214 ( V_65 ) ,
V_78 -> V_237 . V_239 , & V_235 ) ;
F_213 ( V_88 , F_216 ( V_65 ) ,
V_78 -> V_240 . V_238 , & V_235 ) ;
F_215 ( V_88 , F_216 ( V_65 ) ,
V_78 -> V_240 . V_239 , & V_235 ) ;
F_213 ( V_88 , F_217 ( V_65 ) ,
V_78 -> V_241 . V_238 , & V_235 ) ;
F_215 ( V_88 , F_217 ( V_65 ) ,
V_78 -> V_241 . V_239 , & V_235 ) ;
F_218 ( V_88 , V_65 , F_219 ( V_78 ) ,
& V_235 ) ;
F_220 ( V_88 , V_65 , V_78 -> V_242 , & V_235 ) ;
F_221 ( V_88 , V_65 , V_2 -> V_73 , & V_235 ) ;
F_222 ( V_88 , V_65 , V_78 -> V_243 , & V_235 ) ;
F_223 ( V_88 , V_65 , F_113 ( V_78 ) -> V_244 , & V_235 ) ;
F_224 ( V_88 , V_65 , 0 , & V_235 ) ;
}
static int F_225 ( struct V_1 * V_2 ,
struct V_3 * log , struct V_40 * V_41 ,
struct V_78 * V_78 )
{
struct V_64 * V_51 ;
int V_8 ;
V_8 = F_41 ( V_2 , log , V_41 ,
& F_113 ( V_78 ) -> V_104 ,
sizeof( * V_51 ) ) ;
if ( V_8 && V_8 != - V_68 )
return V_8 ;
V_51 = F_35 ( V_41 -> V_59 [ 0 ] , V_41 -> V_60 [ 0 ] ,
struct V_64 ) ;
F_203 ( V_2 , V_41 -> V_59 [ 0 ] , V_51 , V_78 , 0 ) ;
F_31 ( V_41 ) ;
return 0 ;
}
static T_2 int F_226 ( struct V_1 * V_2 ,
struct V_78 * V_78 ,
struct V_40 * V_223 ,
struct V_40 * V_245 , T_1 * V_246 ,
int V_232 , int V_247 , int V_248 )
{
unsigned long V_249 ;
unsigned long V_250 ;
struct V_3 * log = F_113 ( V_78 ) -> V_4 -> V_10 ;
struct V_77 * V_251 ;
struct V_64 * V_51 ;
struct V_28 * V_227 = V_245 -> V_59 [ 0 ] ;
struct V_43 V_252 , V_253 , V_44 ;
int V_8 ;
struct V_43 * V_254 ;
T_3 * V_255 ;
char * V_256 ;
int V_172 ;
struct V_257 V_94 ;
int V_258 = F_113 ( V_78 ) -> V_244 & V_259 ;
bool V_260 = false ;
bool V_261 = true ;
bool V_229 = false ;
F_163 ( & V_94 ) ;
V_256 = F_32 ( V_247 * sizeof( struct V_43 ) +
V_247 * sizeof( T_3 ) , V_62 ) ;
if ( ! V_256 )
return - V_63 ;
V_252 . V_54 = ( T_1 ) - 1 ;
V_255 = ( T_3 * ) V_256 ;
V_254 = (struct V_43 * ) ( V_256 + V_247 * sizeof( T_3 ) ) ;
for ( V_172 = 0 ; V_172 < V_247 ; V_172 ++ ) {
V_255 [ V_172 ] = F_28 ( V_227 , V_172 + V_232 ) ;
F_110 ( V_227 , V_254 + V_172 , V_172 + V_232 ) ;
}
V_8 = F_227 ( V_2 , log , V_223 ,
V_254 , V_255 , V_247 ) ;
if ( V_8 ) {
F_33 ( V_256 ) ;
return V_8 ;
}
for ( V_172 = 0 ; V_172 < V_247 ; V_172 ++ , V_223 -> V_60 [ 0 ] ++ ) {
V_250 = F_29 ( V_223 -> V_59 [ 0 ] ,
V_223 -> V_60 [ 0 ] ) ;
V_249 = F_29 ( V_227 , V_232 + V_172 ) ;
if ( ( V_172 == ( V_247 - 1 ) ) )
V_253 = V_254 [ V_172 ] ;
if ( V_254 [ V_172 ] . type == V_52 ) {
V_51 = F_35 ( V_223 -> V_59 [ 0 ] ,
V_223 -> V_60 [ 0 ] ,
struct V_64 ) ;
F_203 ( V_2 , V_223 -> V_59 [ 0 ] , V_51 ,
V_78 , V_248 == V_262 ) ;
} else {
F_46 ( V_223 -> V_59 [ 0 ] , V_227 , V_250 ,
V_249 , V_255 [ V_172 ] ) ;
}
if ( V_254 [ V_172 ] . type == V_178 ) {
V_260 = true ;
if ( V_252 . V_54 == ( T_1 ) - 1 )
V_252 = V_254 [ V_172 ] ;
} else {
V_261 = false ;
}
if ( V_254 [ V_172 ] . type == V_178 &&
! V_258 ) {
int V_74 ;
V_251 = F_35 ( V_227 , V_232 + V_172 ,
struct V_77 ) ;
if ( F_228 ( V_227 , V_251 ) < V_2 -> V_73 )
continue;
V_74 = F_50 ( V_227 , V_251 ) ;
if ( V_74 == V_80 ) {
T_1 V_263 , V_264 , V_265 , V_266 ;
V_263 = F_52 ( V_227 ,
V_251 ) ;
if ( V_263 == 0 )
continue;
V_264 = F_60 ( V_227 ,
V_251 ) ;
V_265 = F_61 ( V_227 , V_251 ) ;
V_266 = F_51 ( V_227 ,
V_251 ) ;
if ( F_66 ( V_227 ,
V_251 ) ) {
V_265 = 0 ;
V_266 = V_264 ;
}
V_8 = F_67 (
log -> V_11 -> V_98 ,
V_263 + V_265 , V_263 + V_265 + V_266 - 1 ,
& V_94 , 0 ) ;
if ( V_8 ) {
F_31 ( V_223 ) ;
F_33 ( V_256 ) ;
return V_8 ;
}
}
}
}
F_48 ( V_223 -> V_59 [ 0 ] ) ;
F_31 ( V_223 ) ;
F_33 ( V_256 ) ;
V_8 = 0 ;
while ( ! F_68 ( & V_94 ) ) {
struct V_95 * V_96 = F_69 ( V_94 . V_97 ,
struct V_95 ,
V_22 ) ;
if ( ! V_8 )
V_8 = F_70 ( V_2 , log , V_96 ) ;
F_71 ( & V_96 -> V_22 ) ;
F_33 ( V_96 ) ;
}
if ( ! V_260 )
return V_8 ;
if ( V_261 && * V_246 == V_252 . V_76 ) {
V_261 = false ;
}
if ( V_261 ) {
T_1 V_37 ;
V_8 = F_229 ( F_113 ( V_78 ) -> V_4 , V_245 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( V_8 )
goto V_267;
if ( V_245 -> V_60 [ 0 ] )
V_245 -> V_60 [ 0 ] -- ;
V_227 = V_245 -> V_59 [ 0 ] ;
F_110 ( V_227 , & V_44 , V_245 -> V_60 [ 0 ] ) ;
if ( V_44 . V_54 != F_58 ( V_78 ) ||
V_44 . type != V_178 )
goto V_267;
V_251 = F_35 ( V_227 , V_245 -> V_60 [ 0 ] ,
struct V_77 ) ;
if ( F_50 ( V_227 , V_251 ) ==
V_82 ) {
V_37 = F_53 ( V_227 ,
V_245 -> V_60 [ 0 ] ,
V_251 ) ;
* V_246 = F_55 ( V_44 . V_76 + V_37 ,
log -> V_83 ) ;
} else {
V_37 = F_51 ( V_227 , V_251 ) ;
* V_246 = V_44 . V_76 + V_37 ;
}
}
V_267:
if ( V_261 ) {
F_31 ( V_245 ) ;
V_8 = F_30 ( NULL , F_113 ( V_78 ) -> V_4 , & V_252 ,
V_245 , 0 , 0 ) ;
if ( V_8 < 0 )
return V_8 ;
ASSERT ( V_8 == 0 ) ;
V_227 = V_245 -> V_59 [ 0 ] ;
V_172 = V_245 -> V_60 [ 0 ] ;
} else {
V_172 = V_232 ;
}
while ( ! V_229 ) {
T_1 V_76 , V_37 ;
T_1 V_75 ;
if ( V_172 >= F_127 ( V_245 -> V_59 [ 0 ] ) ) {
V_8 = F_128 ( F_113 ( V_78 ) -> V_4 , V_245 ) ;
if ( V_8 < 0 )
return V_8 ;
ASSERT ( V_8 == 0 ) ;
V_227 = V_245 -> V_59 [ 0 ] ;
V_172 = 0 ;
}
F_110 ( V_227 , & V_44 , V_172 ) ;
if ( ! F_230 ( & V_44 , & V_253 ) )
V_229 = true ;
if ( V_44 . V_54 != F_58 ( V_78 ) ||
V_44 . type != V_178 ) {
V_172 ++ ;
continue;
}
V_251 = F_35 ( V_227 , V_172 , struct V_77 ) ;
if ( F_50 ( V_227 , V_251 ) ==
V_82 ) {
V_37 = F_53 ( V_227 , V_172 , V_251 ) ;
V_75 = F_55 ( V_44 . V_76 + V_37 , log -> V_83 ) ;
} else {
V_37 = F_51 ( V_227 , V_251 ) ;
V_75 = V_44 . V_76 + V_37 ;
}
V_172 ++ ;
if ( * V_246 == V_44 . V_76 ) {
* V_246 = V_75 ;
continue;
}
V_76 = * V_246 ;
V_37 = V_44 . V_76 - * V_246 ;
V_8 = F_231 ( V_2 , log , F_58 ( V_78 ) ,
V_76 , 0 , 0 , V_37 , 0 , V_37 , 0 ,
0 , 0 ) ;
if ( V_8 )
break;
* V_246 = V_75 ;
}
if ( ! V_8 && V_261 )
V_8 = 1 ;
return V_8 ;
}
static int F_232 ( void * V_268 , struct V_257 * V_269 , struct V_257 * V_270 )
{
struct V_271 * V_272 , * V_273 ;
V_272 = F_69 ( V_269 , struct V_271 , V_22 ) ;
V_273 = F_69 ( V_270 , struct V_271 , V_22 ) ;
if ( V_272 -> V_36 < V_273 -> V_36 )
return - 1 ;
else if ( V_272 -> V_36 > V_273 -> V_36 )
return 1 ;
return 0 ;
}
static int F_233 ( struct V_1 * V_2 ,
struct V_78 * V_78 ,
struct V_3 * V_4 ,
const struct V_271 * V_274 ,
const struct V_257 * V_275 ,
bool * V_276 )
{
struct V_277 * V_278 ;
struct V_3 * log = V_4 -> V_10 ;
T_1 V_279 = V_274 -> V_279 ;
T_1 V_280 = V_274 -> V_280 ;
const bool V_258 = F_113 ( V_78 ) -> V_244 & V_259 ;
T_1 V_281 ;
T_1 V_282 ;
F_62 ( V_94 ) ;
int V_8 = 0 ;
* V_276 = false ;
if ( F_168 ( V_283 , & V_274 -> V_244 ) ||
V_274 -> V_284 == V_285 )
return 0 ;
F_164 (ordered, logged_list, log_list) {
struct V_95 * V_286 ;
if ( ! V_280 )
break;
if ( V_278 -> V_287 + V_278 -> V_37 <= V_279 ||
V_279 + V_280 <= V_278 -> V_287 )
continue;
if ( ! F_168 ( V_288 , & V_278 -> V_244 ) &&
! F_168 ( V_289 , & V_278 -> V_244 ) &&
! F_168 ( V_290 , & V_278 -> V_244 ) ) {
const T_1 V_36 = V_278 -> V_287 ;
const T_1 V_213 = V_278 -> V_287 + V_278 -> V_37 - 1 ;
F_134 ( V_278 -> V_78 != V_78 ) ;
F_234 ( V_78 -> V_291 , V_36 , V_213 ) ;
}
F_235 ( V_278 -> V_39 ,
( F_168 ( V_288 , & V_278 -> V_244 ) ||
F_168 ( V_289 , & V_278 -> V_244 ) ) ) ;
if ( F_168 ( V_289 , & V_278 -> V_244 ) ) {
F_236 ( V_78 ) ;
* V_276 = true ;
break;
}
if ( V_278 -> V_287 > V_279 ) {
if ( V_278 -> V_287 + V_278 -> V_37 >=
V_279 + V_280 )
V_280 = V_278 -> V_287 - V_279 ;
} else {
if ( V_278 -> V_287 + V_278 -> V_37 <
V_279 + V_280 ) {
V_280 = ( V_279 + V_280 ) -
( V_278 -> V_287 + V_278 -> V_37 ) ;
V_279 = V_278 -> V_287 +
V_278 -> V_37 ;
} else {
V_280 = 0 ;
}
}
if ( V_258 )
continue;
if ( F_237 ( V_292 ,
& V_278 -> V_244 ) )
continue;
if ( V_278 -> V_293 ) {
F_238 ( V_78 , V_278 , 0 ) ;
F_235 ( V_278 -> V_39 ,
V_278 -> V_293 == 0 ) ;
}
F_164 (sum, &ordered->list, list) {
V_8 = F_70 ( V_2 , log , V_286 ) ;
if ( V_8 )
break;
}
}
if ( * V_276 || ! V_280 || V_8 || V_258 )
return V_8 ;
if ( V_274 -> V_294 ) {
V_281 = 0 ;
V_282 = F_197 ( V_274 -> V_295 , V_274 -> V_296 ) ;
} else {
V_281 = V_279 - V_274 -> V_36 ;
V_282 = V_280 ;
}
V_8 = F_67 ( log -> V_11 -> V_98 ,
V_274 -> V_284 + V_281 ,
V_274 -> V_284 + V_281 +
V_282 - 1 , & V_94 , 0 ) ;
if ( V_8 )
return V_8 ;
while ( ! F_68 ( & V_94 ) ) {
struct V_95 * V_96 = F_69 ( V_94 . V_97 ,
struct V_95 ,
V_22 ) ;
if ( ! V_8 )
V_8 = F_70 ( V_2 , log , V_96 ) ;
F_71 ( & V_96 -> V_22 ) ;
F_33 ( V_96 ) ;
}
return V_8 ;
}
static int F_239 ( struct V_1 * V_2 ,
struct V_78 * V_78 , struct V_3 * V_4 ,
const struct V_271 * V_274 ,
struct V_40 * V_41 ,
const struct V_257 * V_275 ,
struct V_5 * V_6 )
{
struct V_3 * log = V_4 -> V_10 ;
struct V_77 * V_297 ;
struct V_28 * V_88 ;
struct V_234 V_235 ;
struct V_43 V_44 ;
T_1 V_298 = V_274 -> V_36 - V_274 -> V_299 ;
T_1 V_295 ;
int V_8 ;
int V_300 = 0 ;
bool V_301 = false ;
V_8 = F_233 ( V_2 , V_78 , V_4 , V_274 , V_275 ,
& V_301 ) ;
if ( V_8 )
return V_8 ;
if ( V_301 ) {
V_6 -> V_302 = - V_84 ;
return 0 ;
}
F_204 ( & V_235 ) ;
V_8 = F_240 ( V_2 , log , V_78 , V_41 , V_274 -> V_36 ,
V_274 -> V_36 + V_274 -> V_37 , NULL , 0 , 1 ,
sizeof( * V_297 ) , & V_300 ) ;
if ( V_8 )
return V_8 ;
if ( ! V_300 ) {
V_44 . V_54 = F_58 ( V_78 ) ;
V_44 . type = V_178 ;
V_44 . V_76 = V_274 -> V_36 ;
V_8 = F_41 ( V_2 , log , V_41 , & V_44 ,
sizeof( * V_297 ) ) ;
if ( V_8 )
return V_8 ;
}
V_88 = V_41 -> V_59 [ 0 ] ;
V_297 = F_35 ( V_88 , V_41 -> V_60 [ 0 ] ,
struct V_77 ) ;
F_241 ( V_88 , V_297 , V_2 -> V_73 ,
& V_235 ) ;
if ( F_168 ( V_283 , & V_274 -> V_244 ) )
F_242 ( V_88 , V_297 ,
V_81 ,
& V_235 ) ;
else
F_242 ( V_88 , V_297 ,
V_80 ,
& V_235 ) ;
V_295 = F_197 ( V_274 -> V_295 , V_274 -> V_296 ) ;
if ( V_274 -> V_294 != V_303 ) {
F_243 ( V_88 , V_297 ,
V_274 -> V_284 ,
& V_235 ) ;
F_244 ( V_88 , V_297 , V_295 ,
& V_235 ) ;
} else if ( V_274 -> V_284 < V_304 ) {
F_243 ( V_88 , V_297 ,
V_274 -> V_284 -
V_298 , & V_235 ) ;
F_244 ( V_88 , V_297 , V_295 ,
& V_235 ) ;
} else {
F_243 ( V_88 , V_297 , 0 , & V_235 ) ;
F_244 ( V_88 , V_297 , 0 ,
& V_235 ) ;
}
F_245 ( V_88 , V_297 , V_298 , & V_235 ) ;
F_246 ( V_88 , V_297 , V_274 -> V_37 , & V_235 ) ;
F_247 ( V_88 , V_297 , V_274 -> V_305 , & V_235 ) ;
F_248 ( V_88 , V_297 , V_274 -> V_294 ,
& V_235 ) ;
F_249 ( V_88 , V_297 , 0 , & V_235 ) ;
F_250 ( V_88 , V_297 , 0 , & V_235 ) ;
F_48 ( V_88 ) ;
F_31 ( V_41 ) ;
return V_8 ;
}
static int F_251 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_78 * V_78 ,
struct V_40 * V_41 ,
struct V_257 * V_275 ,
struct V_5 * V_6 )
{
struct V_271 * V_274 , * V_306 ;
struct V_257 V_307 ;
struct V_308 * V_309 = & F_113 ( V_78 ) -> V_310 ;
T_1 V_311 ;
int V_8 = 0 ;
int V_312 = 0 ;
F_163 ( & V_307 ) ;
F_252 ( & V_309 -> V_313 ) ;
V_311 = V_4 -> V_11 -> V_314 ;
F_253 (em, n, &tree->modified_extents, list) {
F_161 ( & V_274 -> V_22 ) ;
if ( ++ V_312 > 32768 ) {
F_161 ( & V_309 -> V_315 ) ;
V_8 = - V_316 ;
goto V_317;
}
if ( V_274 -> V_236 <= V_311 )
continue;
F_6 ( & V_274 -> V_318 ) ;
F_5 ( V_319 , & V_274 -> V_244 ) ;
F_7 ( & V_274 -> V_22 , & V_307 ) ;
V_312 ++ ;
}
F_254 ( NULL , & V_307 , F_232 ) ;
V_317:
while ( ! F_68 ( & V_307 ) ) {
V_274 = F_69 ( V_307 . V_97 , struct V_271 , V_22 ) ;
F_161 ( & V_274 -> V_22 ) ;
if ( V_8 ) {
F_255 ( V_309 , V_274 ) ;
F_256 ( V_274 ) ;
continue;
}
F_257 ( & V_309 -> V_313 ) ;
V_8 = F_239 ( V_2 , V_78 , V_4 , V_274 , V_41 , V_275 ,
V_6 ) ;
F_252 ( & V_309 -> V_313 ) ;
F_255 ( V_309 , V_274 ) ;
F_256 ( V_274 ) ;
}
F_134 ( ! F_68 ( & V_307 ) ) ;
F_257 ( & V_309 -> V_313 ) ;
F_31 ( V_41 ) ;
return V_8 ;
}
static int F_258 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_78 * V_78 ,
int V_248 ,
const T_5 V_36 ,
const T_5 V_213 ,
struct V_5 * V_6 )
{
struct V_40 * V_41 ;
struct V_40 * V_223 ;
struct V_43 V_226 ;
struct V_43 V_230 ;
struct V_3 * log = V_4 -> V_10 ;
struct V_28 * V_227 = NULL ;
F_62 ( V_275 ) ;
T_1 V_246 = 0 ;
int V_215 = 0 ;
int V_8 ;
int V_160 ;
int V_320 = 0 ;
int V_321 ;
bool V_322 = false ;
T_1 V_139 = F_58 ( V_78 ) ;
struct V_308 * V_323 = & F_113 ( V_78 ) -> V_310 ;
V_41 = F_86 () ;
if ( ! V_41 )
return - V_63 ;
V_223 = F_86 () ;
if ( ! V_223 ) {
F_90 ( V_41 ) ;
return - V_63 ;
}
V_226 . V_54 = V_139 ;
V_226 . type = V_52 ;
V_226 . V_76 = 0 ;
V_230 . V_54 = V_139 ;
if ( F_39 ( V_78 -> V_143 ) ||
( ! F_168 ( V_324 ,
& F_113 ( V_78 ) -> V_325 ) &&
V_248 == V_262 ) )
V_230 . type = V_177 ;
else
V_230 . type = ( T_4 ) - 1 ;
V_230 . V_76 = ( T_1 ) - 1 ;
if ( F_39 ( V_78 -> V_143 ) ||
F_113 ( V_78 ) -> V_236 > V_4 -> V_11 -> V_314 ) {
V_8 = F_259 ( V_2 , V_78 ) ;
if ( V_8 ) {
F_90 ( V_41 ) ;
F_90 ( V_223 ) ;
return V_8 ;
}
}
F_2 ( & F_113 ( V_78 ) -> V_9 ) ;
F_260 ( V_78 , & V_275 , V_36 , V_213 ) ;
if ( F_39 ( V_78 -> V_143 ) ) {
int V_231 = V_169 ;
if ( V_248 == V_262 )
V_231 = V_177 ;
V_8 = F_199 ( V_2 , log , V_41 , V_139 , V_231 ) ;
} else {
if ( F_261 ( V_324 ,
& F_113 ( V_78 ) -> V_325 ) ) {
F_4 ( V_326 ,
& F_113 ( V_78 ) -> V_325 ) ;
V_8 = F_262 ( V_2 , log ,
V_78 , 0 , 0 ) ;
} else if ( F_261 ( V_326 ,
& F_113 ( V_78 ) -> V_325 ) ||
V_248 == V_262 ) {
if ( V_248 == V_327 )
V_322 = true ;
V_230 . type = V_177 ;
V_8 = F_199 ( V_2 , log , V_41 , V_139 ,
V_230 . type ) ;
} else {
if ( V_248 == V_327 )
V_322 = true ;
V_8 = F_225 ( V_2 , log , V_223 , V_78 ) ;
if ( V_8 ) {
V_215 = V_8 ;
goto V_219;
}
goto V_328;
}
}
if ( V_8 ) {
V_215 = V_8 ;
goto V_219;
}
while ( 1 ) {
V_321 = 0 ;
V_8 = F_195 ( V_4 , & V_226 ,
V_41 , V_2 -> V_73 ) ;
if ( V_8 != 0 )
break;
V_125:
if ( V_226 . V_54 != V_139 )
break;
if ( V_226 . type > V_230 . type )
break;
V_227 = V_41 -> V_59 [ 0 ] ;
if ( V_321 && V_320 + V_321 == V_41 -> V_60 [ 0 ] ) {
V_321 ++ ;
goto V_329;
} else if ( ! V_321 ) {
V_320 = V_41 -> V_60 [ 0 ] ;
V_321 = 1 ;
goto V_329;
}
V_8 = F_226 ( V_2 , V_78 , V_223 , V_41 , & V_246 ,
V_320 , V_321 , V_248 ) ;
if ( V_8 < 0 ) {
V_215 = V_8 ;
goto V_219;
}
if ( V_8 ) {
V_321 = 0 ;
F_31 ( V_41 ) ;
continue;
}
V_321 = 1 ;
V_320 = V_41 -> V_60 [ 0 ] ;
V_329:
V_160 = F_127 ( V_41 -> V_59 [ 0 ] ) ;
V_41 -> V_60 [ 0 ] ++ ;
if ( V_41 -> V_60 [ 0 ] < V_160 ) {
F_110 ( V_41 -> V_59 [ 0 ] , & V_226 ,
V_41 -> V_60 [ 0 ] ) ;
goto V_125;
}
if ( V_321 ) {
V_8 = F_226 ( V_2 , V_78 , V_223 , V_41 ,
& V_246 , V_320 ,
V_321 , V_248 ) ;
if ( V_8 < 0 ) {
V_215 = V_8 ;
goto V_219;
}
V_8 = 0 ;
V_321 = 0 ;
}
F_31 ( V_41 ) ;
if ( V_226 . V_76 < ( T_1 ) - 1 ) {
V_226 . V_76 ++ ;
} else if ( V_226 . type < V_230 . type ) {
V_226 . type ++ ;
V_226 . V_76 = 0 ;
} else {
break;
}
}
if ( V_321 ) {
V_8 = F_226 ( V_2 , V_78 , V_223 , V_41 , & V_246 ,
V_320 , V_321 , V_248 ) ;
if ( V_8 < 0 ) {
V_215 = V_8 ;
goto V_219;
}
V_8 = 0 ;
V_321 = 0 ;
}
V_328:
F_31 ( V_41 ) ;
F_31 ( V_223 ) ;
if ( V_322 ) {
V_215 = F_236 ( V_78 ) ;
if ( V_215 ) {
V_6 -> V_302 = V_215 ;
goto V_219;
}
V_8 = F_251 ( V_2 , V_4 , V_78 , V_223 ,
& V_275 , V_6 ) ;
if ( V_8 ) {
V_215 = V_8 ;
goto V_219;
}
} else if ( V_248 == V_327 ) {
struct V_271 * V_274 , * V_306 ;
F_252 ( & V_323 -> V_313 ) ;
F_253 (em, n, &em_tree->modified_extents,
list) {
const T_1 V_330 = V_274 -> V_279 + V_274 -> V_280 - 1 ;
if ( V_274 -> V_279 >= V_36 && V_330 <= V_213 )
F_161 ( & V_274 -> V_22 ) ;
}
F_257 ( & V_323 -> V_313 ) ;
}
if ( V_248 == V_327 && F_39 ( V_78 -> V_143 ) ) {
V_8 = F_198 ( V_2 , V_4 , V_78 , V_41 , V_223 ) ;
if ( V_8 ) {
V_215 = V_8 ;
goto V_219;
}
}
F_113 ( V_78 ) -> V_218 = V_2 -> V_73 ;
F_113 ( V_78 ) -> V_212 = F_113 ( V_78 ) -> V_331 ;
V_219:
if ( F_263 ( V_215 ) )
F_264 ( & V_275 ) ;
else
F_265 ( & V_275 , log ) ;
F_8 ( & F_113 ( V_78 ) -> V_9 ) ;
F_90 ( V_41 ) ;
F_90 ( V_223 ) ;
return V_215 ;
}
static T_2 int F_266 ( struct V_1 * V_2 ,
struct V_78 * V_78 ,
struct V_332 * V_183 ,
struct V_333 * V_334 ,
T_1 V_335 )
{
int V_8 = 0 ;
struct V_3 * V_4 ;
struct V_332 * V_336 = NULL ;
struct V_78 * V_337 = V_78 ;
if ( F_132 ( V_78 -> V_143 ) &&
F_113 ( V_78 ) -> V_236 <= V_335 &&
F_113 ( V_78 ) -> V_338 <= V_335 )
goto V_13;
if ( ! F_39 ( V_78 -> V_143 ) ) {
if ( ! V_183 || ! V_183 -> V_339 || V_334 != V_183 -> V_339 -> V_340 )
goto V_13;
V_78 = V_183 -> V_339 ;
}
while ( 1 ) {
if ( V_78 != V_337 )
F_113 ( V_78 ) -> V_218 = V_2 -> V_73 ;
F_12 () ;
if ( F_113 ( V_78 ) -> V_338 > V_335 ) {
V_4 = F_113 ( V_78 ) -> V_4 ;
F_175 ( V_4 -> V_11 , V_2 ) ;
V_8 = 1 ;
break;
}
if ( ! V_183 || ! V_183 -> V_339 || V_334 != V_183 -> V_339 -> V_340 )
break;
if ( F_267 ( V_183 ) )
break;
V_183 = F_268 ( V_183 ) ;
F_269 ( V_336 ) ;
V_336 = V_183 ;
V_78 = V_183 -> V_339 ;
}
F_269 ( V_336 ) ;
V_13:
return V_8 ;
}
static int F_270 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_78 * V_78 ,
struct V_332 * V_183 ,
const T_5 V_36 ,
const T_5 V_213 ,
int V_341 ,
struct V_5 * V_6 )
{
int V_248 = V_341 ? V_262 : V_327 ;
struct V_333 * V_334 ;
struct V_332 * V_336 = NULL ;
int V_8 = 0 ;
T_1 V_335 = V_4 -> V_11 -> V_314 ;
V_334 = V_78 -> V_340 ;
if ( F_167 ( V_4 , V_342 ) ) {
V_8 = 1 ;
goto V_343;
}
if ( V_4 -> V_11 -> V_344 >
V_4 -> V_11 -> V_314 ) {
V_8 = 1 ;
goto V_343;
}
if ( V_4 != F_113 ( V_78 ) -> V_4 ||
F_271 ( & V_4 -> V_191 ) == 0 ) {
V_8 = 1 ;
goto V_343;
}
V_8 = F_266 ( V_2 , V_78 , V_183 ,
V_334 , V_335 ) ;
if ( V_8 )
goto V_343;
if ( F_272 ( V_78 , V_2 -> V_73 ) ) {
V_8 = V_345 ;
goto V_343;
}
V_8 = F_1 ( V_2 , V_4 , V_6 ) ;
if ( V_8 )
goto V_343;
V_8 = F_258 ( V_2 , V_4 , V_78 , V_248 , V_36 , V_213 , V_6 ) ;
if ( V_8 )
goto V_346;
if ( F_132 ( V_78 -> V_143 ) &&
F_113 ( V_78 ) -> V_236 <= V_335 &&
F_113 ( V_78 ) -> V_338 <= V_335 ) {
V_8 = 0 ;
goto V_346;
}
V_248 = V_262 ;
while ( 1 ) {
if ( ! V_183 || ! V_183 -> V_339 || V_334 != V_183 -> V_339 -> V_340 )
break;
V_78 = V_183 -> V_339 ;
if ( V_4 != F_113 ( V_78 ) -> V_4 )
break;
if ( F_113 ( V_78 ) -> V_236 >
V_4 -> V_11 -> V_314 ) {
V_8 = F_258 ( V_2 , V_4 , V_78 , V_248 ,
0 , V_347 , V_6 ) ;
if ( V_8 )
goto V_346;
}
if ( F_267 ( V_183 ) )
break;
V_183 = F_268 ( V_183 ) ;
F_269 ( V_336 ) ;
V_336 = V_183 ;
}
V_8 = 0 ;
V_346:
F_269 ( V_336 ) ;
if ( V_8 < 0 ) {
F_175 ( V_4 -> V_11 , V_2 ) ;
V_8 = 1 ;
}
if ( V_8 )
F_160 ( V_4 , V_6 ) ;
F_14 ( V_4 ) ;
V_343:
return V_8 ;
}
int F_273 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_332 * V_332 ,
const T_5 V_36 ,
const T_5 V_213 ,
struct V_5 * V_6 )
{
struct V_332 * V_183 = F_268 ( V_332 ) ;
int V_8 ;
V_8 = F_270 ( V_2 , V_4 , V_332 -> V_339 , V_183 ,
V_36 , V_213 , 0 , V_6 ) ;
F_269 ( V_183 ) ;
return V_8 ;
}
int F_274 ( struct V_3 * V_25 )
{
int V_8 ;
struct V_40 * V_41 ;
struct V_1 * V_2 ;
struct V_43 V_44 ;
struct V_43 V_146 ;
struct V_43 V_348 ;
struct V_3 * log ;
struct V_214 * V_11 = V_25 -> V_11 ;
struct V_30 V_31 = {
. V_187 = F_18 ,
. V_173 = 0 ,
} ;
V_41 = F_86 () ;
if ( ! V_41 )
return - V_63 ;
V_11 -> V_349 = 1 ;
V_2 = F_275 ( V_11 -> V_211 , 0 ) ;
if ( F_83 ( V_2 ) ) {
V_8 = F_130 ( V_2 ) ;
goto error;
}
V_31 . V_2 = V_2 ;
V_31 . V_34 = 1 ;
V_8 = F_148 ( V_2 , V_25 , & V_31 ) ;
if ( V_8 ) {
F_276 ( V_11 , V_8 , L_1
L_2 ) ;
goto error;
}
V_125:
V_44 . V_54 = V_55 ;
V_44 . V_76 = ( T_1 ) - 1 ;
V_44 . type = V_350 ;
while ( 1 ) {
V_8 = F_30 ( NULL , V_25 , & V_44 , V_41 , 0 , 0 ) ;
if ( V_8 < 0 ) {
F_276 ( V_11 , V_8 ,
L_3 ) ;
goto error;
}
if ( V_8 > 0 ) {
if ( V_41 -> V_60 [ 0 ] == 0 )
break;
V_41 -> V_60 [ 0 ] -- ;
}
F_110 ( V_41 -> V_59 [ 0 ] , & V_146 ,
V_41 -> V_60 [ 0 ] ) ;
F_31 ( V_41 ) ;
if ( V_146 . V_54 != V_55 )
break;
log = F_277 ( V_25 , & V_146 ) ;
if ( F_83 ( log ) ) {
V_8 = F_130 ( log ) ;
F_276 ( V_11 , V_8 ,
L_4 ) ;
goto error;
}
V_348 . V_54 = V_146 . V_76 ;
V_348 . type = V_350 ;
V_348 . V_76 = ( T_1 ) - 1 ;
V_31 . V_170 = F_278 ( V_11 , & V_348 ) ;
if ( F_83 ( V_31 . V_170 ) ) {
V_8 = F_130 ( V_31 . V_170 ) ;
F_139 ( log -> V_188 ) ;
F_139 ( log -> V_351 ) ;
F_33 ( log ) ;
F_276 ( V_11 , V_8 , L_5
L_6 ) ;
goto error;
}
V_31 . V_170 -> V_10 = log ;
F_279 ( V_2 , V_31 . V_170 ) ;
V_8 = F_148 ( V_2 , log , & V_31 ) ;
if ( ! V_8 && V_31 . V_173 == V_176 ) {
V_8 = F_115 ( V_2 , V_31 . V_170 ,
V_41 ) ;
}
V_44 . V_76 = V_146 . V_76 - 1 ;
V_31 . V_170 -> V_10 = NULL ;
F_139 ( log -> V_188 ) ;
F_139 ( log -> V_351 ) ;
F_33 ( log ) ;
if ( V_8 )
goto error;
if ( V_146 . V_76 == 0 )
break;
}
F_31 ( V_41 ) ;
if ( V_31 . V_34 ) {
V_31 . V_34 = 0 ;
V_31 . V_187 = F_131 ;
V_31 . V_173 = V_174 ;
goto V_125;
}
if ( V_31 . V_173 < V_176 ) {
V_31 . V_173 ++ ;
goto V_125;
}
F_90 ( V_41 ) ;
V_8 = F_280 ( V_2 , V_11 -> V_211 ) ;
if ( V_8 )
return V_8 ;
F_139 ( V_25 -> V_188 ) ;
V_25 -> V_10 = NULL ;
V_11 -> V_349 = 0 ;
F_33 ( V_25 ) ;
return 0 ;
error:
if ( V_31 . V_2 )
F_281 ( V_31 . V_2 , V_11 -> V_211 ) ;
F_90 ( V_41 ) ;
return V_8 ;
}
void F_282 ( struct V_1 * V_2 ,
struct V_78 * V_99 , struct V_78 * V_78 ,
int V_352 )
{
if ( F_132 ( V_78 -> V_143 ) )
F_113 ( V_78 ) -> V_338 = V_2 -> V_73 ;
F_12 () ;
if ( F_113 ( V_99 ) -> V_218 == V_2 -> V_73 )
return;
if ( F_113 ( V_78 ) -> V_218 == V_2 -> V_73 )
return;
if ( V_352 )
goto V_353;
return;
V_353:
F_113 ( V_99 ) -> V_338 = V_2 -> V_73 ;
}
int F_283 ( struct V_1 * V_2 ,
struct V_78 * V_78 , struct V_78 * V_354 ,
struct V_332 * V_183 )
{
struct V_3 * V_4 = F_113 ( V_78 ) -> V_4 ;
if ( F_132 ( V_78 -> V_143 ) )
F_113 ( V_78 ) -> V_338 = V_2 -> V_73 ;
if ( F_113 ( V_78 ) -> V_218 <=
V_4 -> V_11 -> V_314 &&
( ! V_354 || F_113 ( V_354 ) -> V_218 <=
V_4 -> V_11 -> V_314 ) )
return 0 ;
return F_270 ( V_2 , V_4 , V_78 , V_183 , 0 ,
V_347 , 1 , NULL ) ;
}
