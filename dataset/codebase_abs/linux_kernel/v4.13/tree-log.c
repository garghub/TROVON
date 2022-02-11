static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
int V_9 = 0 ;
F_2 ( & V_4 -> V_10 ) ;
if ( V_4 -> V_11 ) {
if ( F_3 ( V_8 , V_2 ) ) {
V_9 = - V_12 ;
goto V_13;
}
if ( ! V_4 -> V_14 ) {
F_4 ( V_15 , & V_4 -> V_16 ) ;
V_4 -> V_14 = V_17 -> V_18 ;
} else if ( V_4 -> V_14 != V_17 -> V_18 ) {
F_5 ( V_15 , & V_4 -> V_16 ) ;
}
} else {
F_2 ( & V_8 -> V_19 ) ;
if ( ! V_8 -> V_20 )
V_9 = F_6 ( V_2 , V_8 ) ;
F_7 ( & V_8 -> V_19 ) ;
if ( V_9 )
goto V_13;
V_9 = F_8 ( V_2 , V_4 ) ;
if ( V_9 )
goto V_13;
F_4 ( V_15 , & V_4 -> V_16 ) ;
V_4 -> V_14 = V_17 -> V_18 ;
}
F_9 ( & V_4 -> V_21 ) ;
F_9 ( & V_4 -> V_22 ) ;
if ( V_6 ) {
int V_23 = V_4 -> V_24 % 2 ;
F_10 ( & V_6 -> V_25 , & V_4 -> V_26 [ V_23 ] ) ;
V_6 -> V_24 = V_4 -> V_24 ;
}
V_13:
F_7 ( & V_4 -> V_10 ) ;
return V_9 ;
}
static int F_11 ( struct V_3 * V_4 )
{
int V_9 = - V_27 ;
F_12 () ;
if ( ! V_4 -> V_11 )
return - V_27 ;
F_2 ( & V_4 -> V_10 ) ;
if ( V_4 -> V_11 ) {
V_9 = 0 ;
F_9 ( & V_4 -> V_22 ) ;
}
F_7 ( & V_4 -> V_10 ) ;
return V_9 ;
}
int F_13 ( struct V_3 * V_4 )
{
int V_9 = - V_27 ;
F_2 ( & V_4 -> V_10 ) ;
F_9 ( & V_4 -> V_22 ) ;
F_7 ( & V_4 -> V_10 ) ;
return V_9 ;
}
void F_14 ( struct V_3 * V_4 )
{
if ( F_15 ( & V_4 -> V_22 ) ) {
if ( F_16 ( & V_4 -> V_28 ) )
F_17 ( & V_4 -> V_28 ) ;
}
}
static int F_18 ( struct V_3 * log ,
struct V_29 * V_30 ,
struct V_31 * V_32 , T_1 V_33 )
{
struct V_7 * V_8 = log -> V_8 ;
int V_9 = 0 ;
if ( F_19 ( V_8 , V_34 ) ) {
V_9 = F_20 ( V_30 , V_33 ) ;
if ( V_9 )
return V_9 ;
}
if ( V_32 -> V_35 )
V_9 = F_21 ( V_8 , V_30 -> V_36 ,
V_30 -> V_37 ) ;
if ( ! V_9 && F_22 ( V_30 , V_33 , 0 ) ) {
if ( V_32 -> V_35 && F_23 ( V_30 ) == 0 )
V_9 = F_24 ( V_8 , V_30 ) ;
if ( V_32 -> V_38 )
F_25 ( V_30 ) ;
if ( V_32 -> V_39 )
F_26 ( V_30 ) ;
}
return V_9 ;
}
static T_2 int F_27 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_40 * V_41 ,
struct V_29 * V_30 , int V_42 ,
struct V_43 * V_44 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
int V_9 ;
T_3 V_45 ;
T_1 V_46 = 0 ;
int V_47 = 0 ;
unsigned long V_48 ;
unsigned long V_49 ;
int V_50 = 0 ;
bool V_51 = V_44 -> type == V_52 ;
if ( V_4 -> V_53 . V_54 != V_55 )
V_50 = 1 ;
V_45 = F_28 ( V_30 , V_42 ) ;
V_48 = F_29 ( V_30 , V_42 ) ;
V_9 = F_30 ( NULL , V_4 , V_44 , V_41 , 0 , 0 ) ;
if ( V_9 < 0 )
return V_9 ;
if ( V_9 == 0 ) {
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
F_34 ( V_30 , V_56 , V_48 , V_45 ) ;
V_49 = F_29 ( V_41 -> V_59 [ 0 ] , V_41 -> V_60 [ 0 ] ) ;
F_34 ( V_41 -> V_59 [ 0 ] , V_57 , V_49 ,
V_45 ) ;
V_9 = memcmp ( V_57 , V_56 , V_45 ) ;
F_33 ( V_57 ) ;
F_33 ( V_56 ) ;
if ( V_9 == 0 ) {
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
V_65 = F_35 ( V_30 , V_42 ,
struct V_64 ) ;
F_37 ( V_30 , V_65 , V_66 ) ;
V_67 = F_38 ( V_30 , V_65 ) ;
if ( F_39 ( V_67 ) )
F_40 ( V_30 , V_65 , 0 ) ;
}
} else if ( V_51 ) {
struct V_64 * V_65 ;
T_3 V_67 ;
V_65 = F_35 ( V_30 , V_42 , struct V_64 ) ;
F_37 ( V_30 , V_65 , 0 ) ;
V_67 = F_38 ( V_30 , V_65 ) ;
if ( F_39 ( V_67 ) )
F_40 ( V_30 , V_65 , 0 ) ;
}
V_61:
F_31 ( V_41 ) ;
V_41 -> V_68 = 1 ;
V_9 = F_41 ( V_2 , V_4 , V_41 ,
V_44 , V_45 ) ;
V_41 -> V_68 = 0 ;
if ( V_9 == - V_69 || V_9 == - V_70 ) {
T_3 V_71 ;
V_71 = F_28 ( V_41 -> V_59 [ 0 ] ,
V_41 -> V_60 [ 0 ] ) ;
if ( V_71 > V_45 )
F_42 ( V_8 , V_41 , V_45 , 1 ) ;
else if ( V_71 < V_45 )
F_43 ( V_8 , V_41 ,
V_45 - V_71 ) ;
} else if ( V_9 ) {
return V_9 ;
}
V_49 = F_29 ( V_41 -> V_59 [ 0 ] ,
V_41 -> V_60 [ 0 ] ) ;
if ( V_44 -> type == V_52 && V_9 == - V_69 ) {
struct V_64 * V_72 ;
struct V_64 * V_73 ;
V_72 = (struct V_64 * ) V_48 ;
V_73 = (struct V_64 * ) V_49 ;
if ( F_44 ( V_30 , V_72 ) == 0 ) {
struct V_29 * V_74 = V_41 -> V_59 [ 0 ] ;
const T_1 V_75 = F_45 ( V_30 , V_72 ) ;
if ( F_46 ( F_38 ( V_30 , V_72 ) ) &&
F_46 ( F_38 ( V_74 , V_73 ) ) &&
V_75 != 0 ) {
struct V_76 V_77 ;
F_47 ( & V_77 ) ;
F_48 ( V_74 , V_73 ,
V_75 , & V_77 ) ;
}
goto V_78;
}
if ( V_50 &&
F_39 ( F_38 ( V_30 , V_72 ) ) &&
F_39 ( F_38 ( V_41 -> V_59 [ 0 ] , V_73 ) ) ) {
V_47 = 1 ;
V_46 = F_45 ( V_41 -> V_59 [ 0 ] ,
V_73 ) ;
}
}
F_49 ( V_41 -> V_59 [ 0 ] , V_30 , V_49 ,
V_48 , V_45 ) ;
if ( V_47 ) {
struct V_64 * V_73 ;
V_73 = (struct V_64 * ) V_49 ;
F_40 ( V_41 -> V_59 [ 0 ] , V_73 , V_46 ) ;
}
if ( V_44 -> type == V_52 ) {
struct V_64 * V_73 ;
V_73 = (struct V_64 * ) V_49 ;
if ( F_44 ( V_41 -> V_59 [ 0 ] , V_73 ) == 0 ) {
F_50 ( V_41 -> V_59 [ 0 ] , V_73 ,
V_2 -> V_79 ) ;
}
}
V_78:
F_51 ( V_41 -> V_59 [ 0 ] ) ;
F_31 ( V_41 ) ;
return 0 ;
}
T_2 int F_52 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_40 * V_41 ,
struct V_29 * V_30 , int V_42 ,
struct V_43 * V_44 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
int V_80 ;
T_1 V_81 ;
T_1 V_36 = V_44 -> V_82 ;
T_1 V_66 = 0 ;
struct V_83 * V_65 ;
struct V_84 * V_84 = NULL ;
unsigned long V_85 ;
int V_9 = 0 ;
V_65 = F_35 ( V_30 , V_42 , struct V_83 ) ;
V_80 = F_53 ( V_30 , V_65 ) ;
if ( V_80 == V_86 ||
V_80 == V_87 ) {
V_66 = F_54 ( V_30 , V_65 ) ;
V_81 = V_36 + V_66 ;
if ( F_55 ( V_30 , V_65 ) == 0 )
V_66 = 0 ;
} else if ( V_80 == V_88 ) {
V_85 = F_56 ( V_30 , V_42 , V_65 ) ;
V_66 = F_57 ( V_30 , V_65 ) ;
V_81 = F_58 ( V_36 + V_85 ,
V_8 -> V_89 ) ;
} else {
V_9 = 0 ;
goto V_13;
}
V_84 = F_59 ( V_4 , V_44 -> V_54 ) ;
if ( ! V_84 ) {
V_9 = - V_90 ;
goto V_13;
}
V_9 = F_60 ( V_2 , V_4 , V_41 ,
F_61 ( F_62 ( V_84 ) ) , V_36 , 0 ) ;
if ( V_9 == 0 &&
( V_80 == V_86 ||
V_80 == V_87 ) ) {
struct V_83 V_91 ;
struct V_83 V_92 ;
struct V_83 * V_93 ;
struct V_29 * V_94 ;
V_94 = V_41 -> V_59 [ 0 ] ;
V_93 = F_35 ( V_94 , V_41 -> V_60 [ 0 ] ,
struct V_83 ) ;
F_34 ( V_30 , & V_91 , ( unsigned long ) V_65 ,
sizeof( V_91 ) ) ;
F_34 ( V_94 , & V_92 , ( unsigned long ) V_93 ,
sizeof( V_92 ) ) ;
if ( memcmp ( & V_91 , & V_92 , sizeof( V_91 ) ) == 0 ) {
F_31 ( V_41 ) ;
goto V_13;
}
}
F_31 ( V_41 ) ;
V_9 = F_63 ( V_2 , V_4 , V_84 , V_36 , V_81 , 1 ) ;
if ( V_9 )
goto V_13;
if ( V_80 == V_86 ||
V_80 == V_87 ) {
T_1 V_82 ;
unsigned long V_95 ;
struct V_43 V_96 ;
if ( F_55 ( V_30 , V_65 ) == 0 &&
F_19 ( V_8 , V_97 ) )
goto V_98;
V_9 = F_41 ( V_2 , V_4 , V_41 , V_44 ,
sizeof( * V_65 ) ) ;
if ( V_9 )
goto V_13;
V_95 = F_29 ( V_41 -> V_59 [ 0 ] ,
V_41 -> V_60 [ 0 ] ) ;
F_49 ( V_41 -> V_59 [ 0 ] , V_30 , V_95 ,
( unsigned long ) V_65 , sizeof( * V_65 ) ) ;
V_96 . V_54 = F_55 ( V_30 , V_65 ) ;
V_96 . V_82 = F_64 ( V_30 , V_65 ) ;
V_96 . type = V_99 ;
V_82 = V_44 -> V_82 - F_65 ( V_30 , V_65 ) ;
V_9 = F_66 ( V_2 , V_8 ,
F_55 ( V_30 , V_65 ) ,
F_64 ( V_30 , V_65 ) ,
V_62 ) ;
if ( V_9 < 0 )
goto V_13;
if ( V_96 . V_54 > 0 ) {
T_1 V_100 ;
T_1 V_101 ;
F_67 ( V_102 ) ;
V_9 = F_68 ( V_8 , V_96 . V_54 ,
V_96 . V_82 ) ;
if ( V_9 == 0 ) {
V_9 = F_69 ( V_2 , V_8 ,
V_96 . V_54 , V_96 . V_82 ,
0 , V_4 -> V_53 . V_54 ,
V_44 -> V_54 , V_82 ) ;
if ( V_9 )
goto V_13;
} else {
V_9 = F_70 ( V_2 ,
V_8 ,
V_4 -> V_53 . V_54 ,
V_44 -> V_54 , V_82 , & V_96 ) ;
if ( V_9 )
goto V_13;
}
F_31 ( V_41 ) ;
if ( F_71 ( V_30 , V_65 ) ) {
V_100 = V_96 . V_54 ;
V_101 = V_100 + V_96 . V_82 ;
} else {
V_100 = V_96 . V_54 +
F_65 ( V_30 , V_65 ) ;
V_101 = V_100 +
F_54 ( V_30 , V_65 ) ;
}
V_9 = F_72 ( V_4 -> V_11 ,
V_100 , V_101 - 1 ,
& V_102 , 0 ) ;
if ( V_9 )
goto V_13;
while ( ! F_73 ( & V_102 ) ) {
struct V_103 * V_104 ;
V_104 = F_74 ( V_102 . V_105 ,
struct V_103 ,
V_25 ) ;
if ( ! V_9 )
V_9 = F_75 ( V_2 , V_8 ,
V_104 -> V_106 ,
V_104 -> V_37 ) ;
if ( ! V_9 )
V_9 = F_76 ( V_2 ,
V_8 -> V_107 , V_104 ) ;
F_77 ( & V_104 -> V_25 ) ;
F_33 ( V_104 ) ;
}
if ( V_9 )
goto V_13;
} else {
F_31 ( V_41 ) ;
}
} else if ( V_80 == V_88 ) {
V_9 = F_27 ( V_2 , V_4 , V_41 , V_30 , V_42 , V_44 ) ;
if ( V_9 )
goto V_13;
}
F_78 ( V_84 , V_66 ) ;
V_98:
V_9 = F_79 ( V_2 , V_4 , V_84 ) ;
V_13:
if ( V_84 )
F_80 ( V_84 ) ;
return V_9 ;
}
static T_2 int F_81 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_40 * V_41 ,
struct V_108 * V_109 ,
struct V_110 * V_111 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
struct V_84 * V_84 ;
char * V_112 ;
int V_113 ;
struct V_29 * V_94 ;
struct V_43 V_114 ;
int V_9 ;
V_94 = V_41 -> V_59 [ 0 ] ;
F_82 ( V_94 , V_111 , & V_114 ) ;
V_113 = F_83 ( V_94 , V_111 ) ;
V_112 = F_32 ( V_113 , V_62 ) ;
if ( ! V_112 )
return - V_63 ;
F_34 ( V_94 , V_112 , ( unsigned long ) ( V_111 + 1 ) , V_113 ) ;
F_31 ( V_41 ) ;
V_84 = F_59 ( V_4 , V_114 . V_54 ) ;
if ( ! V_84 ) {
V_9 = - V_90 ;
goto V_13;
}
V_9 = F_84 ( V_2 , V_4 , V_41 , V_114 . V_54 ) ;
if ( V_9 )
goto V_13;
V_9 = F_85 ( V_2 , V_4 , V_109 , F_62 ( V_84 ) , V_112 ,
V_113 ) ;
if ( V_9 )
goto V_13;
else
V_9 = F_86 ( V_2 , V_8 ) ;
V_13:
F_33 ( V_112 ) ;
F_80 ( V_84 ) ;
return V_9 ;
}
static T_2 int F_87 ( struct V_3 * V_4 ,
struct V_40 * V_41 ,
T_1 V_115 , T_1 V_54 , T_1 V_23 ,
const char * V_112 , int V_113 )
{
struct V_110 * V_111 ;
struct V_43 V_114 ;
int V_116 = 0 ;
V_111 = F_88 ( NULL , V_4 , V_41 , V_115 ,
V_23 , V_112 , V_113 , 0 ) ;
if ( V_111 && ! F_89 ( V_111 ) ) {
F_82 ( V_41 -> V_59 [ 0 ] , V_111 , & V_114 ) ;
if ( V_114 . V_54 != V_54 )
goto V_13;
} else
goto V_13;
F_31 ( V_41 ) ;
V_111 = F_90 ( NULL , V_4 , V_41 , V_115 , V_112 , V_113 , 0 ) ;
if ( V_111 && ! F_89 ( V_111 ) ) {
F_82 ( V_41 -> V_59 [ 0 ] , V_111 , & V_114 ) ;
if ( V_114 . V_54 != V_54 )
goto V_13;
} else
goto V_13;
V_116 = 1 ;
V_13:
F_31 ( V_41 ) ;
return V_116 ;
}
static T_2 int F_91 ( struct V_3 * log ,
struct V_43 * V_44 ,
T_1 V_117 ,
const char * V_112 , int V_118 )
{
struct V_40 * V_41 ;
struct V_119 * V_120 ;
unsigned long V_121 ;
unsigned long V_122 ;
unsigned long V_123 ;
int V_124 ;
int V_45 ;
int V_9 ;
int V_116 = 0 ;
V_41 = F_92 () ;
if ( ! V_41 )
return - V_63 ;
V_9 = F_30 ( NULL , log , V_44 , V_41 , 0 , 0 ) ;
if ( V_9 != 0 )
goto V_13;
V_121 = F_29 ( V_41 -> V_59 [ 0 ] , V_41 -> V_60 [ 0 ] ) ;
if ( V_44 -> type == V_125 ) {
if ( F_93 ( V_41 , V_117 ,
V_112 , V_118 , NULL ) )
V_116 = 1 ;
goto V_13;
}
V_45 = F_28 ( V_41 -> V_59 [ 0 ] , V_41 -> V_60 [ 0 ] ) ;
V_122 = V_121 + V_45 ;
while ( V_121 < V_122 ) {
V_120 = (struct V_119 * ) V_121 ;
V_124 = F_94 ( V_41 -> V_59 [ 0 ] , V_120 ) ;
if ( V_124 == V_118 ) {
V_123 = ( unsigned long ) ( V_120 + 1 ) ;
V_9 = F_95 ( V_41 -> V_59 [ 0 ] , V_112 ,
V_123 , V_118 ) ;
if ( V_9 == 0 ) {
V_116 = 1 ;
goto V_13;
}
}
V_121 = ( unsigned long ) ( V_120 + 1 ) + V_124 ;
}
V_13:
F_96 ( V_41 ) ;
return V_116 ;
}
static inline int F_97 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_40 * V_41 ,
struct V_3 * V_11 ,
struct V_108 * V_109 ,
struct V_108 * V_84 ,
T_1 V_126 , T_1 V_127 ,
T_1 V_128 , char * V_112 , int V_118 ,
int * V_129 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
int V_9 ;
char * V_130 ;
int V_131 ;
struct V_29 * V_94 ;
struct V_110 * V_111 ;
struct V_43 V_132 ;
struct V_133 * V_134 ;
V_135:
V_132 . V_54 = V_126 ;
V_132 . type = V_136 ;
V_132 . V_82 = V_127 ;
V_9 = F_30 ( NULL , V_4 , & V_132 , V_41 , 0 , 0 ) ;
if ( V_9 == 0 ) {
struct V_119 * V_137 ;
unsigned long V_121 ;
unsigned long V_122 ;
V_94 = V_41 -> V_59 [ 0 ] ;
if ( V_132 . V_54 == V_132 . V_82 )
return 1 ;
V_121 = F_29 ( V_94 , V_41 -> V_60 [ 0 ] ) ;
V_122 = V_121 + F_28 ( V_94 , V_41 -> V_60 [ 0 ] ) ;
while ( V_121 < V_122 ) {
V_137 = (struct V_119 * ) V_121 ;
V_131 = F_94 ( V_94 ,
V_137 ) ;
V_130 = F_32 ( V_131 , V_62 ) ;
if ( ! V_130 )
return - V_63 ;
F_34 ( V_94 , V_130 ,
( unsigned long ) ( V_137 + 1 ) ,
V_131 ) ;
if ( ! F_91 ( V_11 , & V_132 ,
V_127 ,
V_130 ,
V_131 ) ) {
F_98 ( & V_84 -> V_138 ) ;
F_31 ( V_41 ) ;
V_9 = F_85 ( V_2 , V_4 , V_109 , V_84 ,
V_130 , V_131 ) ;
F_33 ( V_130 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_86 ( V_2 , V_8 ) ;
if ( V_9 )
return V_9 ;
* V_129 = 1 ;
goto V_135;
}
F_33 ( V_130 ) ;
V_121 = ( unsigned long ) ( V_137 + 1 ) + V_131 ;
}
* V_129 = 1 ;
}
F_31 ( V_41 ) ;
V_134 = F_99 ( NULL , V_4 , V_41 , V_112 , V_118 ,
V_126 , V_127 , 0 ,
0 ) ;
if ( ! F_100 ( V_134 ) ) {
T_3 V_45 ;
T_3 V_139 = 0 ;
unsigned long V_140 ;
struct V_84 * V_141 ;
V_94 = V_41 -> V_59 [ 0 ] ;
V_45 = F_28 ( V_94 , V_41 -> V_60 [ 0 ] ) ;
V_140 = F_29 ( V_94 , V_41 -> V_60 [ 0 ] ) ;
while ( V_139 < V_45 ) {
V_134 = (struct V_133 * ) ( V_140 + V_139 ) ;
V_131 = F_101 ( V_94 , V_134 ) ;
if ( F_102 ( V_94 , V_134 ) != V_127 )
goto V_105;
V_130 = F_32 ( V_131 , V_62 ) ;
if ( ! V_130 )
return - V_63 ;
F_34 ( V_94 , V_130 , ( unsigned long ) & V_134 -> V_112 ,
V_131 ) ;
V_132 . V_54 = V_126 ;
V_132 . type = V_125 ;
V_132 . V_82 = F_103 ( V_127 ,
V_130 ,
V_131 ) ;
V_9 = 0 ;
if ( ! F_91 ( V_11 , & V_132 ,
V_127 , V_130 ,
V_131 ) ) {
V_9 = - V_27 ;
V_141 = F_59 ( V_4 ,
V_127 ) ;
if ( V_141 ) {
F_98 ( & V_84 -> V_138 ) ;
F_31 ( V_41 ) ;
V_9 = F_85 ( V_2 , V_4 ,
F_62 ( V_141 ) ,
V_84 ,
V_130 ,
V_131 ) ;
if ( ! V_9 )
V_9 = F_86 (
V_2 ,
V_8 ) ;
}
F_80 ( V_141 ) ;
F_33 ( V_130 ) ;
if ( V_9 )
return V_9 ;
* V_129 = 1 ;
goto V_135;
}
F_33 ( V_130 ) ;
if ( V_9 )
return V_9 ;
V_105:
V_139 += V_131 + sizeof( * V_134 ) ;
}
* V_129 = 1 ;
}
F_31 ( V_41 ) ;
V_111 = F_88 ( V_2 , V_4 , V_41 , F_61 ( V_109 ) ,
V_128 , V_112 , V_118 , 0 ) ;
if ( V_111 && ! F_89 ( V_111 ) ) {
V_9 = F_81 ( V_2 , V_4 , V_41 , V_109 , V_111 ) ;
if ( V_9 )
return V_9 ;
}
F_31 ( V_41 ) ;
V_111 = F_90 ( V_2 , V_4 , V_41 , F_61 ( V_109 ) ,
V_112 , V_118 , 0 ) ;
if ( V_111 && ! F_89 ( V_111 ) ) {
V_9 = F_81 ( V_2 , V_4 , V_41 , V_109 , V_111 ) ;
if ( V_9 )
return V_9 ;
}
F_31 ( V_41 ) ;
return 0 ;
}
static int F_104 ( struct V_29 * V_30 , int V_42 ,
unsigned long V_142 , T_3 * V_118 , char * * V_112 ,
T_1 * V_23 , T_1 * V_127 )
{
struct V_133 * V_134 ;
V_134 = (struct V_133 * ) V_142 ;
* V_118 = F_101 ( V_30 , V_134 ) ;
if ( ! F_105 ( V_30 , V_42 , ( unsigned long ) & V_134 -> V_112 ,
* V_118 ) )
return - V_90 ;
* V_112 = F_32 ( * V_118 , V_62 ) ;
if ( * V_112 == NULL )
return - V_63 ;
F_34 ( V_30 , * V_112 , ( unsigned long ) & V_134 -> V_112 ,
* V_118 ) ;
* V_23 = F_106 ( V_30 , V_134 ) ;
if ( V_127 )
* V_127 = F_102 ( V_30 , V_134 ) ;
return 0 ;
}
static int F_107 ( struct V_29 * V_30 , int V_42 ,
unsigned long V_142 , T_3 * V_118 , char * * V_112 ,
T_1 * V_23 )
{
struct V_119 * V_120 ;
V_120 = (struct V_119 * ) V_142 ;
* V_118 = F_94 ( V_30 , V_120 ) ;
if ( ! F_105 ( V_30 , V_42 , ( unsigned long ) ( V_120 + 1 ) ,
* V_118 ) )
return - V_90 ;
* V_112 = F_32 ( * V_118 , V_62 ) ;
if ( * V_112 == NULL )
return - V_63 ;
F_34 ( V_30 , * V_112 , ( unsigned long ) ( V_120 + 1 ) , * V_118 ) ;
* V_23 = F_108 ( V_30 , V_120 ) ;
return 0 ;
}
static T_2 int F_109 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_3 * log ,
struct V_40 * V_41 ,
struct V_29 * V_30 , int V_42 ,
struct V_43 * V_44 )
{
struct V_84 * V_109 = NULL ;
struct V_84 * V_84 = NULL ;
unsigned long V_142 ;
unsigned long V_143 ;
char * V_112 = NULL ;
int V_118 ;
int V_9 ;
int V_129 = 0 ;
int V_144 = 0 ;
T_1 V_127 ;
T_1 V_126 ;
T_1 V_128 = 0 ;
int V_145 ;
V_142 = F_29 ( V_30 , V_42 ) ;
V_143 = V_142 + F_28 ( V_30 , V_42 ) ;
if ( V_44 -> type == V_125 ) {
struct V_133 * V_146 ;
V_145 = sizeof( struct V_133 ) ;
V_144 = 1 ;
V_146 = (struct V_133 * ) V_142 ;
V_127 = F_102 ( V_30 , V_146 ) ;
} else {
V_145 = sizeof( struct V_119 ) ;
V_127 = V_44 -> V_82 ;
}
V_126 = V_44 -> V_54 ;
V_109 = F_59 ( V_4 , V_127 ) ;
if ( ! V_109 ) {
V_9 = - V_27 ;
goto V_13;
}
V_84 = F_59 ( V_4 , V_126 ) ;
if ( ! V_84 ) {
V_9 = - V_90 ;
goto V_13;
}
while ( V_142 < V_143 ) {
if ( V_144 ) {
V_9 = F_104 ( V_30 , V_42 , V_142 , & V_118 ,
& V_112 , & V_128 , & V_127 ) ;
if ( ! V_109 )
V_109 = F_59 ( V_4 , V_127 ) ;
if ( ! V_109 ) {
V_9 = - V_27 ;
goto V_13;
}
} else {
V_9 = F_107 ( V_30 , V_42 , V_142 , & V_118 ,
& V_112 , & V_128 ) ;
}
if ( V_9 )
goto V_13;
if ( ! F_87 ( V_4 , V_41 , F_61 ( F_62 ( V_109 ) ) ,
F_61 ( F_62 ( V_84 ) ) , V_128 ,
V_112 , V_118 ) ) {
if ( ! V_129 ) {
V_9 = F_97 ( V_2 , V_4 , V_41 , log ,
F_62 ( V_109 ) ,
F_62 ( V_84 ) ,
V_126 ,
V_127 ,
V_128 , V_112 , V_118 ,
& V_129 ) ;
if ( V_9 ) {
if ( V_9 == 1 )
V_9 = 0 ;
goto V_13;
}
}
V_9 = F_110 ( V_2 , F_62 ( V_109 ) ,
F_62 ( V_84 ) ,
V_112 , V_118 , 0 , V_128 ) ;
if ( V_9 )
goto V_13;
F_79 ( V_2 , V_4 , V_84 ) ;
}
V_142 = ( unsigned long ) ( V_142 + V_145 ) + V_118 ;
F_33 ( V_112 ) ;
V_112 = NULL ;
if ( V_144 ) {
F_80 ( V_109 ) ;
V_109 = NULL ;
}
}
V_9 = F_27 ( V_2 , V_4 , V_41 , V_30 , V_42 , V_44 ) ;
V_13:
F_31 ( V_41 ) ;
F_33 ( V_112 ) ;
F_80 ( V_109 ) ;
F_80 ( V_84 ) ;
return V_9 ;
}
static int F_111 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_1 V_147 )
{
int V_9 ;
V_9 = F_112 ( V_2 , V_4 , V_147 ) ;
if ( V_9 == - V_69 )
V_9 = 0 ;
return V_9 ;
}
static int F_113 ( struct V_3 * V_4 ,
struct V_108 * V_84 , struct V_40 * V_41 )
{
int V_9 = 0 ;
int V_113 ;
unsigned int V_148 = 0 ;
T_3 V_45 ;
T_3 V_139 = 0 ;
T_1 V_126 = F_61 ( V_84 ) ;
T_1 V_82 = 0 ;
unsigned long V_121 ;
struct V_133 * V_134 ;
struct V_29 * V_94 ;
while ( 1 ) {
V_9 = F_114 ( V_4 , V_126 , V_82 , V_41 ,
& V_134 , & V_82 ) ;
if ( V_9 )
break;
V_94 = V_41 -> V_59 [ 0 ] ;
V_45 = F_28 ( V_94 , V_41 -> V_60 [ 0 ] ) ;
V_121 = F_29 ( V_94 , V_41 -> V_60 [ 0 ] ) ;
V_139 = 0 ;
while ( V_139 < V_45 ) {
V_134 = (struct V_133 * ) ( V_121 + V_139 ) ;
V_113 = F_101 ( V_94 , V_134 ) ;
V_148 ++ ;
V_139 += V_113 + sizeof( * V_134 ) ;
}
V_82 ++ ;
F_31 ( V_41 ) ;
}
F_31 ( V_41 ) ;
if ( V_9 < 0 && V_9 != - V_27 )
return V_9 ;
return V_148 ;
}
static int F_115 ( struct V_3 * V_4 ,
struct V_108 * V_84 , struct V_40 * V_41 )
{
int V_9 ;
struct V_43 V_44 ;
unsigned int V_148 = 0 ;
unsigned long V_121 ;
unsigned long V_122 ;
int V_113 ;
T_1 V_147 = F_61 ( V_84 ) ;
V_44 . V_54 = V_147 ;
V_44 . type = V_136 ;
V_44 . V_82 = ( T_1 ) - 1 ;
while ( 1 ) {
V_9 = F_30 ( NULL , V_4 , & V_44 , V_41 , 0 , 0 ) ;
if ( V_9 < 0 )
break;
if ( V_9 > 0 ) {
if ( V_41 -> V_60 [ 0 ] == 0 )
break;
V_41 -> V_60 [ 0 ] -- ;
}
V_149:
F_116 ( V_41 -> V_59 [ 0 ] , & V_44 ,
V_41 -> V_60 [ 0 ] ) ;
if ( V_44 . V_54 != V_147 ||
V_44 . type != V_136 )
break;
V_121 = F_29 ( V_41 -> V_59 [ 0 ] , V_41 -> V_60 [ 0 ] ) ;
V_122 = V_121 + F_28 ( V_41 -> V_59 [ 0 ] ,
V_41 -> V_60 [ 0 ] ) ;
while ( V_121 < V_122 ) {
struct V_119 * V_120 ;
V_120 = (struct V_119 * ) V_121 ;
V_113 = F_94 ( V_41 -> V_59 [ 0 ] ,
V_120 ) ;
V_121 = ( unsigned long ) ( V_120 + 1 ) + V_113 ;
V_148 ++ ;
}
if ( V_44 . V_82 == 0 )
break;
if ( V_41 -> V_60 [ 0 ] > 0 ) {
V_41 -> V_60 [ 0 ] -- ;
goto V_149;
}
V_44 . V_82 -- ;
F_31 ( V_41 ) ;
}
F_31 ( V_41 ) ;
return V_148 ;
}
static T_2 int F_117 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_84 * V_84 )
{
struct V_40 * V_41 ;
int V_9 ;
T_1 V_148 = 0 ;
T_1 V_147 = F_61 ( F_62 ( V_84 ) ) ;
V_41 = F_92 () ;
if ( ! V_41 )
return - V_63 ;
V_9 = F_115 ( V_4 , F_62 ( V_84 ) , V_41 ) ;
if ( V_9 < 0 )
goto V_13;
V_148 = V_9 ;
V_9 = F_113 ( V_4 , F_62 ( V_84 ) , V_41 ) ;
if ( V_9 < 0 )
goto V_13;
V_148 += V_9 ;
V_9 = 0 ;
if ( V_148 != V_84 -> V_150 ) {
F_118 ( V_84 , V_148 ) ;
F_79 ( V_2 , V_4 , V_84 ) ;
}
F_62 ( V_84 ) -> V_151 = ( T_1 ) - 1 ;
if ( V_84 -> V_150 == 0 ) {
if ( F_39 ( V_84 -> V_152 ) ) {
V_9 = F_119 ( V_2 , V_4 , NULL , V_41 ,
V_147 , 1 ) ;
if ( V_9 )
goto V_13;
}
V_9 = F_111 ( V_2 , V_4 , V_147 ) ;
}
V_13:
F_96 ( V_41 ) ;
return V_9 ;
}
static T_2 int F_120 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_40 * V_41 )
{
int V_9 ;
struct V_43 V_44 ;
struct V_84 * V_84 ;
V_44 . V_54 = V_153 ;
V_44 . type = V_154 ;
V_44 . V_82 = ( T_1 ) - 1 ;
while ( 1 ) {
V_9 = F_30 ( V_2 , V_4 , & V_44 , V_41 , - 1 , 1 ) ;
if ( V_9 < 0 )
break;
if ( V_9 == 1 ) {
if ( V_41 -> V_60 [ 0 ] == 0 )
break;
V_41 -> V_60 [ 0 ] -- ;
}
F_116 ( V_41 -> V_59 [ 0 ] , & V_44 , V_41 -> V_60 [ 0 ] ) ;
if ( V_44 . V_54 != V_153 ||
V_44 . type != V_154 )
break;
V_9 = F_121 ( V_2 , V_4 , V_41 ) ;
if ( V_9 )
goto V_13;
F_31 ( V_41 ) ;
V_84 = F_59 ( V_4 , V_44 . V_82 ) ;
if ( ! V_84 )
return - V_90 ;
V_9 = F_117 ( V_2 , V_4 , V_84 ) ;
F_80 ( V_84 ) ;
if ( V_9 )
goto V_13;
V_44 . V_82 = ( T_1 ) - 1 ;
}
V_9 = 0 ;
V_13:
F_31 ( V_41 ) ;
return V_9 ;
}
static T_2 int F_84 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_40 * V_41 ,
T_1 V_54 )
{
struct V_43 V_44 ;
int V_9 = 0 ;
struct V_84 * V_84 ;
V_84 = F_59 ( V_4 , V_54 ) ;
if ( ! V_84 )
return - V_90 ;
V_44 . V_54 = V_153 ;
V_44 . type = V_154 ;
V_44 . V_82 = V_54 ;
V_9 = F_41 ( V_2 , V_4 , V_41 , & V_44 , 0 ) ;
F_31 ( V_41 ) ;
if ( V_9 == 0 ) {
if ( ! V_84 -> V_150 )
F_118 ( V_84 , 1 ) ;
else
F_98 ( V_84 ) ;
V_9 = F_79 ( V_2 , V_4 , V_84 ) ;
} else if ( V_9 == - V_69 ) {
V_9 = 0 ;
} else {
F_122 () ;
}
F_80 ( V_84 ) ;
return V_9 ;
}
static T_2 int F_123 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_115 , T_1 V_23 ,
char * V_112 , int V_113 ,
struct V_43 * V_114 )
{
struct V_84 * V_84 ;
struct V_84 * V_109 ;
int V_9 ;
V_84 = F_59 ( V_4 , V_114 -> V_54 ) ;
if ( ! V_84 )
return - V_27 ;
V_109 = F_59 ( V_4 , V_115 ) ;
if ( ! V_109 ) {
F_80 ( V_84 ) ;
return - V_90 ;
}
V_9 = F_110 ( V_2 , F_62 ( V_109 ) , F_62 ( V_84 ) , V_112 ,
V_113 , 1 , V_23 ) ;
F_80 ( V_84 ) ;
F_80 ( V_109 ) ;
return V_9 ;
}
static bool F_124 ( struct V_3 * V_11 ,
const char * V_112 , const int V_113 ,
const T_1 V_115 , const T_1 V_147 )
{
struct V_43 V_132 ;
V_132 . V_54 = V_147 ;
V_132 . type = V_136 ;
V_132 . V_82 = V_115 ;
if ( F_91 ( V_11 , & V_132 , V_115 , V_112 , V_113 ) )
return true ;
V_132 . type = V_125 ;
V_132 . V_82 = F_103 ( V_115 , V_112 , V_113 ) ;
if ( F_91 ( V_11 , & V_132 , V_115 , V_112 , V_113 ) )
return true ;
return false ;
}
static T_2 int F_125 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_40 * V_41 ,
struct V_29 * V_30 ,
struct V_110 * V_111 ,
struct V_43 * V_44 )
{
char * V_112 ;
int V_113 ;
struct V_110 * V_155 ;
struct V_43 V_156 ;
struct V_43 V_157 ;
struct V_84 * V_109 ;
T_4 V_158 ;
int V_159 ;
int V_9 = 0 ;
bool V_160 = ( V_44 -> type == V_161 ) ;
bool V_162 = false ;
V_109 = F_59 ( V_4 , V_44 -> V_54 ) ;
if ( ! V_109 )
return - V_90 ;
V_113 = F_83 ( V_30 , V_111 ) ;
V_112 = F_32 ( V_113 , V_62 ) ;
if ( ! V_112 ) {
V_9 = - V_63 ;
goto V_13;
}
V_158 = F_126 ( V_30 , V_111 ) ;
F_34 ( V_30 , V_112 , ( unsigned long ) ( V_111 + 1 ) ,
V_113 ) ;
F_82 ( V_30 , V_111 , & V_157 ) ;
V_159 = F_127 ( V_2 , V_4 , V_41 , & V_157 , 0 ) ;
if ( V_159 == 0 )
V_159 = 1 ;
else
V_159 = 0 ;
F_31 ( V_41 ) ;
if ( V_44 -> type == V_163 ) {
V_155 = F_90 ( V_2 , V_4 , V_41 , V_44 -> V_54 ,
V_112 , V_113 , 1 ) ;
} else if ( V_44 -> type == V_161 ) {
V_155 = F_88 ( V_2 , V_4 , V_41 ,
V_44 -> V_54 ,
V_44 -> V_82 , V_112 ,
V_113 , 1 ) ;
} else {
V_9 = - V_164 ;
goto V_13;
}
if ( F_100 ( V_155 ) ) {
if ( V_44 -> type != V_161 )
goto V_13;
goto V_61;
}
F_82 ( V_41 -> V_59 [ 0 ] , V_155 , & V_156 ) ;
if ( V_156 . V_54 == V_157 . V_54 &&
V_156 . type == V_157 . type &&
V_156 . V_82 == V_157 . V_82 &&
F_126 ( V_41 -> V_59 [ 0 ] , V_155 ) == V_158 ) {
V_160 = false ;
goto V_13;
}
if ( ! V_159 )
goto V_13;
V_9 = F_81 ( V_2 , V_4 , V_41 , F_62 ( V_109 ) , V_155 ) ;
if ( V_9 )
goto V_13;
if ( V_44 -> type == V_161 )
goto V_61;
V_13:
F_31 ( V_41 ) ;
if ( ! V_9 && V_160 ) {
F_128 ( F_62 ( V_109 ) , V_109 -> V_165 + V_113 * 2 ) ;
V_9 = F_79 ( V_2 , V_4 , V_109 ) ;
}
F_33 ( V_112 ) ;
F_80 ( V_109 ) ;
if ( ! V_9 && V_162 )
V_9 = 1 ;
return V_9 ;
V_61:
if ( F_124 ( V_4 -> V_11 , V_112 , V_113 ,
V_44 -> V_54 , V_157 . V_54 ) ) {
V_9 = 0 ;
V_160 = false ;
goto V_13;
}
F_31 ( V_41 ) ;
V_9 = F_123 ( V_2 , V_4 , V_44 -> V_54 , V_44 -> V_82 ,
V_112 , V_113 , & V_157 ) ;
if ( V_9 && V_9 != - V_27 && V_9 != - V_69 )
goto V_13;
if ( ! V_9 )
V_162 = true ;
V_160 = false ;
V_9 = 0 ;
goto V_13;
}
static T_2 int F_129 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_40 * V_41 ,
struct V_29 * V_30 , int V_42 ,
struct V_43 * V_44 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
int V_9 = 0 ;
T_3 V_45 = F_28 ( V_30 , V_42 ) ;
struct V_110 * V_111 ;
int V_113 ;
unsigned long V_121 ;
unsigned long V_122 ;
struct V_40 * V_166 = NULL ;
V_121 = F_29 ( V_30 , V_42 ) ;
V_122 = V_121 + V_45 ;
while ( V_121 < V_122 ) {
V_111 = (struct V_110 * ) V_121 ;
if ( F_130 ( V_8 , V_30 , V_42 , V_111 ) )
return - V_90 ;
V_113 = F_83 ( V_30 , V_111 ) ;
V_9 = F_125 ( V_2 , V_4 , V_41 , V_30 , V_111 , V_44 ) ;
if ( V_9 < 0 )
break;
V_121 = ( unsigned long ) ( V_111 + 1 ) ;
V_121 += V_113 ;
if ( V_9 == 1 && F_126 ( V_30 , V_111 ) != V_167 ) {
struct V_43 V_168 ;
if ( ! V_166 ) {
V_166 = F_92 () ;
if ( ! V_166 ) {
V_9 = - V_63 ;
break;
}
}
F_82 ( V_30 , V_111 , & V_168 ) ;
V_9 = F_84 ( V_2 , V_4 , V_166 ,
V_168 . V_54 ) ;
if ( V_9 )
break;
}
V_9 = 0 ;
}
F_96 ( V_166 ) ;
return V_9 ;
}
static T_2 int F_131 ( struct V_3 * V_4 ,
struct V_40 * V_41 ,
T_1 V_115 , int V_169 ,
T_1 * V_170 , T_1 * V_171 )
{
struct V_43 V_44 ;
T_1 V_172 ;
struct V_173 * V_65 ;
int V_9 ;
int V_174 ;
if ( * V_170 == ( T_1 ) - 1 )
return 1 ;
V_44 . V_54 = V_115 ;
V_44 . type = V_169 ;
V_44 . V_82 = * V_170 ;
V_9 = F_30 ( NULL , V_4 , & V_44 , V_41 , 0 , 0 ) ;
if ( V_9 < 0 )
goto V_13;
if ( V_9 > 0 ) {
if ( V_41 -> V_60 [ 0 ] == 0 )
goto V_13;
V_41 -> V_60 [ 0 ] -- ;
}
if ( V_9 != 0 )
F_116 ( V_41 -> V_59 [ 0 ] , & V_44 , V_41 -> V_60 [ 0 ] ) ;
if ( V_44 . type != V_169 || V_44 . V_54 != V_115 ) {
V_9 = 1 ;
goto V_105;
}
V_65 = F_35 ( V_41 -> V_59 [ 0 ] , V_41 -> V_60 [ 0 ] ,
struct V_173 ) ;
V_172 = F_132 ( V_41 -> V_59 [ 0 ] , V_65 ) ;
if ( * V_170 >= V_44 . V_82 && * V_170 <= V_172 ) {
V_9 = 0 ;
* V_170 = V_44 . V_82 ;
* V_171 = V_172 ;
goto V_13;
}
V_9 = 1 ;
V_105:
V_174 = F_133 ( V_41 -> V_59 [ 0 ] ) ;
V_41 -> V_60 [ 0 ] ++ ;
if ( V_41 -> V_60 [ 0 ] >= V_174 ) {
V_9 = F_134 ( V_4 , V_41 ) ;
if ( V_9 )
goto V_13;
}
F_116 ( V_41 -> V_59 [ 0 ] , & V_44 , V_41 -> V_60 [ 0 ] ) ;
if ( V_44 . type != V_169 || V_44 . V_54 != V_115 ) {
V_9 = 1 ;
goto V_13;
}
V_65 = F_35 ( V_41 -> V_59 [ 0 ] , V_41 -> V_60 [ 0 ] ,
struct V_173 ) ;
V_172 = F_132 ( V_41 -> V_59 [ 0 ] , V_65 ) ;
* V_170 = V_44 . V_82 ;
* V_171 = V_172 ;
V_9 = 0 ;
V_13:
F_31 ( V_41 ) ;
return V_9 ;
}
static T_2 int F_135 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_3 * log ,
struct V_40 * V_41 ,
struct V_40 * V_175 ,
struct V_84 * V_109 ,
struct V_43 * V_176 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
int V_9 ;
struct V_29 * V_30 ;
int V_42 ;
T_3 V_45 ;
struct V_110 * V_111 ;
struct V_110 * V_177 ;
int V_113 ;
unsigned long V_121 ;
unsigned long V_122 ;
char * V_112 ;
struct V_84 * V_84 ;
struct V_43 V_114 ;
V_135:
V_30 = V_41 -> V_59 [ 0 ] ;
V_42 = V_41 -> V_60 [ 0 ] ;
V_45 = F_28 ( V_30 , V_42 ) ;
V_121 = F_29 ( V_30 , V_42 ) ;
V_122 = V_121 + V_45 ;
while ( V_121 < V_122 ) {
V_111 = (struct V_110 * ) V_121 ;
if ( F_130 ( V_8 , V_30 , V_42 , V_111 ) ) {
V_9 = - V_90 ;
goto V_13;
}
V_113 = F_83 ( V_30 , V_111 ) ;
V_112 = F_32 ( V_113 , V_62 ) ;
if ( ! V_112 ) {
V_9 = - V_63 ;
goto V_13;
}
F_34 ( V_30 , V_112 , ( unsigned long ) ( V_111 + 1 ) ,
V_113 ) ;
V_177 = NULL ;
if ( log && V_176 -> type == V_163 ) {
V_177 = F_90 ( V_2 , log , V_175 ,
V_176 -> V_54 ,
V_112 , V_113 , 0 ) ;
} else if ( log && V_176 -> type == V_161 ) {
V_177 = F_88 ( V_2 , log ,
V_175 ,
V_176 -> V_54 ,
V_176 -> V_82 ,
V_112 , V_113 , 0 ) ;
}
if ( ! V_177 || ( F_89 ( V_177 ) && F_136 ( V_177 ) == - V_27 ) ) {
F_82 ( V_30 , V_111 , & V_114 ) ;
F_31 ( V_41 ) ;
F_31 ( V_175 ) ;
V_84 = F_59 ( V_4 , V_114 . V_54 ) ;
if ( ! V_84 ) {
F_33 ( V_112 ) ;
return - V_90 ;
}
V_9 = F_84 ( V_2 , V_4 ,
V_41 , V_114 . V_54 ) ;
if ( V_9 ) {
F_33 ( V_112 ) ;
F_80 ( V_84 ) ;
goto V_13;
}
F_98 ( V_84 ) ;
V_9 = F_85 ( V_2 , V_4 , F_62 ( V_109 ) ,
F_62 ( V_84 ) , V_112 , V_113 ) ;
if ( ! V_9 )
V_9 = F_86 ( V_2 , V_8 ) ;
F_33 ( V_112 ) ;
F_80 ( V_84 ) ;
if ( V_9 )
goto V_13;
V_9 = F_30 ( NULL , V_4 , V_176 , V_41 ,
0 , 0 ) ;
if ( V_9 == 0 )
goto V_135;
V_9 = 0 ;
goto V_13;
} else if ( F_89 ( V_177 ) ) {
F_33 ( V_112 ) ;
return F_136 ( V_177 ) ;
}
F_31 ( V_175 ) ;
F_33 ( V_112 ) ;
V_121 = ( unsigned long ) ( V_111 + 1 ) ;
V_121 += V_113 ;
}
V_9 = 0 ;
V_13:
F_31 ( V_41 ) ;
F_31 ( V_175 ) ;
return V_9 ;
}
static int F_137 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_3 * log ,
struct V_40 * V_41 ,
const T_1 V_147 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
struct V_43 V_132 ;
struct V_40 * V_175 ;
int V_178 ;
int V_174 ;
int V_9 ;
V_175 = F_92 () ;
if ( ! V_175 )
return - V_63 ;
V_132 . V_54 = V_147 ;
V_132 . type = V_179 ;
V_132 . V_82 = 0 ;
V_135:
V_9 = F_30 ( NULL , V_4 , & V_132 , V_41 , 0 , 0 ) ;
if ( V_9 < 0 )
goto V_13;
V_180:
V_174 = F_133 ( V_41 -> V_59 [ 0 ] ) ;
for ( V_178 = V_41 -> V_60 [ 0 ] ; V_178 < V_174 ; V_178 ++ ) {
struct V_43 V_44 ;
struct V_110 * V_111 ;
struct V_110 * V_177 ;
T_3 V_181 ;
T_3 V_182 ;
F_116 ( V_41 -> V_59 [ 0 ] , & V_44 , V_178 ) ;
if ( V_44 . V_54 != V_147 || V_44 . type != V_179 ) {
V_9 = 0 ;
goto V_13;
}
V_111 = F_35 ( V_41 -> V_59 [ 0 ] , V_178 , struct V_110 ) ;
V_181 = F_28 ( V_41 -> V_59 [ 0 ] , V_178 ) ;
V_182 = 0 ;
while ( V_182 < V_181 ) {
T_5 V_113 = F_83 ( V_41 -> V_59 [ 0 ] , V_111 ) ;
T_5 V_183 = F_138 ( V_41 -> V_59 [ 0 ] , V_111 ) ;
T_3 V_184 = sizeof( * V_111 ) + V_113 + V_183 ;
char * V_112 ;
V_9 = F_130 ( V_8 , V_41 -> V_59 [ 0 ] , V_178 , V_111 ) ;
if ( V_9 ) {
V_9 = - V_90 ;
goto V_13;
}
V_112 = F_32 ( V_113 , V_62 ) ;
if ( ! V_112 ) {
V_9 = - V_63 ;
goto V_13;
}
F_34 ( V_41 -> V_59 [ 0 ] , V_112 ,
( unsigned long ) ( V_111 + 1 ) , V_113 ) ;
V_177 = F_139 ( NULL , log , V_175 , V_147 ,
V_112 , V_113 , 0 ) ;
F_31 ( V_175 ) ;
if ( ! V_177 ) {
F_31 ( V_41 ) ;
V_111 = F_139 ( V_2 , V_4 , V_41 , V_147 ,
V_112 , V_113 , - 1 ) ;
F_33 ( V_112 ) ;
if ( F_89 ( V_111 ) ) {
V_9 = F_136 ( V_111 ) ;
goto V_13;
}
ASSERT ( V_111 ) ;
V_9 = F_140 ( V_2 , V_4 ,
V_41 , V_111 ) ;
if ( V_9 )
goto V_13;
F_31 ( V_41 ) ;
V_132 = V_44 ;
goto V_135;
}
F_33 ( V_112 ) ;
if ( F_89 ( V_177 ) ) {
V_9 = F_136 ( V_177 ) ;
goto V_13;
}
V_182 += V_184 ;
V_111 = (struct V_110 * ) ( ( char * ) V_111 + V_184 ) ;
}
}
V_9 = F_134 ( V_4 , V_41 ) ;
if ( V_9 > 0 )
V_9 = 0 ;
else if ( V_9 == 0 )
goto V_180;
V_13:
F_96 ( V_175 ) ;
F_31 ( V_41 ) ;
return V_9 ;
}
static T_2 int F_119 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_3 * log ,
struct V_40 * V_41 ,
T_1 V_115 , int V_185 )
{
T_1 V_186 ;
T_1 V_187 ;
int V_169 = V_188 ;
int V_9 = 0 ;
struct V_43 V_176 ;
struct V_43 V_156 ;
struct V_40 * V_175 ;
struct V_84 * V_109 ;
V_176 . V_54 = V_115 ;
V_176 . type = V_163 ;
V_175 = F_92 () ;
if ( ! V_175 )
return - V_63 ;
V_109 = F_59 ( V_4 , V_115 ) ;
if ( ! V_109 ) {
F_96 ( V_175 ) ;
return 0 ;
}
V_135:
V_186 = 0 ;
V_187 = 0 ;
while ( 1 ) {
if ( V_185 )
V_187 = ( T_1 ) - 1 ;
else {
V_9 = F_131 ( log , V_41 , V_115 , V_169 ,
& V_186 , & V_187 ) ;
if ( V_9 != 0 )
break;
}
V_176 . V_82 = V_186 ;
while ( 1 ) {
int V_174 ;
V_9 = F_30 ( NULL , V_4 , & V_176 , V_41 ,
0 , 0 ) ;
if ( V_9 < 0 )
goto V_13;
V_174 = F_133 ( V_41 -> V_59 [ 0 ] ) ;
if ( V_41 -> V_60 [ 0 ] >= V_174 ) {
V_9 = F_134 ( V_4 , V_41 ) ;
if ( V_9 )
break;
}
F_116 ( V_41 -> V_59 [ 0 ] , & V_156 ,
V_41 -> V_60 [ 0 ] ) ;
if ( V_156 . V_54 != V_115 ||
V_156 . type != V_176 . type )
goto V_189;
if ( V_156 . V_82 > V_187 )
break;
V_9 = F_135 ( V_2 , V_4 , log , V_41 ,
V_175 , V_109 ,
& V_156 ) ;
if ( V_9 )
goto V_13;
if ( V_156 . V_82 == ( T_1 ) - 1 )
break;
V_176 . V_82 = V_156 . V_82 + 1 ;
}
F_31 ( V_41 ) ;
if ( V_187 == ( T_1 ) - 1 )
break;
V_186 = V_187 + 1 ;
}
V_189:
V_9 = 0 ;
if ( V_169 == V_188 ) {
V_169 = V_190 ;
V_176 . type = V_161 ;
F_31 ( V_41 ) ;
goto V_135;
}
V_13:
F_31 ( V_41 ) ;
F_96 ( V_175 ) ;
F_80 ( V_109 ) ;
return V_9 ;
}
static int F_141 ( struct V_3 * log , struct V_29 * V_30 ,
struct V_31 * V_32 , T_1 V_33 )
{
int V_174 ;
struct V_40 * V_41 ;
struct V_3 * V_4 = V_32 -> V_191 ;
struct V_43 V_44 ;
int V_192 ;
int V_178 ;
int V_9 ;
V_9 = F_20 ( V_30 , V_33 ) ;
if ( V_9 )
return V_9 ;
V_192 = F_23 ( V_30 ) ;
if ( V_192 != 0 )
return 0 ;
V_41 = F_92 () ;
if ( ! V_41 )
return - V_63 ;
V_174 = F_133 ( V_30 ) ;
for ( V_178 = 0 ; V_178 < V_174 ; V_178 ++ ) {
F_116 ( V_30 , & V_44 , V_178 ) ;
if ( V_44 . type == V_52 &&
V_32 -> V_193 == V_194 ) {
struct V_64 * V_51 ;
T_3 V_67 ;
V_51 = F_35 ( V_30 , V_178 ,
struct V_64 ) ;
V_9 = F_137 ( V_32 -> V_2 , V_4 , log ,
V_41 , V_44 . V_54 ) ;
if ( V_9 )
break;
V_67 = F_38 ( V_30 , V_51 ) ;
if ( F_39 ( V_67 ) ) {
V_9 = F_119 ( V_32 -> V_2 ,
V_4 , log , V_41 , V_44 . V_54 , 0 ) ;
if ( V_9 )
break;
}
V_9 = F_27 ( V_32 -> V_2 , V_4 , V_41 ,
V_30 , V_178 , & V_44 ) ;
if ( V_9 )
break;
if ( F_46 ( V_67 ) ) {
V_9 = F_111 ( V_32 -> V_2 , V_4 ,
V_44 . V_54 ) ;
if ( V_9 )
break;
}
V_9 = F_84 ( V_32 -> V_2 , V_4 ,
V_41 , V_44 . V_54 ) ;
if ( V_9 )
break;
}
if ( V_44 . type == V_161 &&
V_32 -> V_193 == V_195 ) {
V_9 = F_129 ( V_32 -> V_2 , V_4 , V_41 ,
V_30 , V_178 , & V_44 ) ;
if ( V_9 )
break;
}
if ( V_32 -> V_193 < V_196 )
continue;
if ( V_44 . type == V_179 ) {
V_9 = F_27 ( V_32 -> V_2 , V_4 , V_41 ,
V_30 , V_178 , & V_44 ) ;
if ( V_9 )
break;
} else if ( V_44 . type == V_136 ||
V_44 . type == V_125 ) {
V_9 = F_109 ( V_32 -> V_2 , V_4 , log , V_41 ,
V_30 , V_178 , & V_44 ) ;
if ( V_9 && V_9 != - V_27 )
break;
V_9 = 0 ;
} else if ( V_44 . type == V_197 ) {
V_9 = F_52 ( V_32 -> V_2 , V_4 , V_41 ,
V_30 , V_178 , & V_44 ) ;
if ( V_9 )
break;
} else if ( V_44 . type == V_163 ) {
V_9 = F_129 ( V_32 -> V_2 , V_4 , V_41 ,
V_30 , V_178 , & V_44 ) ;
if ( V_9 )
break;
}
}
F_96 ( V_41 ) ;
return V_9 ;
}
static T_2 int F_142 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_40 * V_41 , int * V_192 ,
struct V_31 * V_32 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
T_1 V_198 ;
T_1 V_106 ;
T_1 V_199 ;
struct V_29 * V_105 ;
struct V_29 * V_182 ;
struct V_29 * V_200 ;
T_3 V_201 ;
int V_9 = 0 ;
F_143 ( * V_192 < 0 ) ;
F_143 ( * V_192 >= V_202 ) ;
while ( * V_192 > 0 ) {
F_143 ( * V_192 < 0 ) ;
F_143 ( * V_192 >= V_202 ) ;
V_182 = V_41 -> V_59 [ * V_192 ] ;
F_143 ( F_23 ( V_182 ) != * V_192 ) ;
if ( V_41 -> V_60 [ * V_192 ] >=
F_133 ( V_182 ) )
break;
V_106 = F_144 ( V_182 , V_41 -> V_60 [ * V_192 ] ) ;
V_199 = F_145 ( V_182 , V_41 -> V_60 [ * V_192 ] ) ;
V_201 = V_8 -> V_203 ;
V_200 = V_41 -> V_59 [ * V_192 ] ;
V_198 = F_146 ( V_200 ) ;
V_105 = F_147 ( V_8 , V_106 ) ;
if ( F_89 ( V_105 ) )
return F_136 ( V_105 ) ;
if ( * V_192 == 1 ) {
V_9 = V_32 -> V_204 ( V_4 , V_105 , V_32 , V_199 ) ;
if ( V_9 ) {
F_148 ( V_105 ) ;
return V_9 ;
}
V_41 -> V_60 [ * V_192 ] ++ ;
if ( V_32 -> free ) {
V_9 = F_20 ( V_105 , V_199 ) ;
if ( V_9 ) {
F_148 ( V_105 ) ;
return V_9 ;
}
if ( V_2 ) {
F_149 ( V_105 ) ;
F_150 ( V_105 ) ;
F_151 ( V_8 , V_105 ) ;
F_26 ( V_105 ) ;
F_152 ( V_105 ) ;
}
F_143 ( V_198 !=
V_55 ) ;
V_9 = F_153 (
V_8 , V_106 ,
V_201 ) ;
if ( V_9 ) {
F_148 ( V_105 ) ;
return V_9 ;
}
}
F_148 ( V_105 ) ;
continue;
}
V_9 = F_20 ( V_105 , V_199 ) ;
if ( V_9 ) {
F_148 ( V_105 ) ;
return V_9 ;
}
F_143 ( * V_192 <= 0 ) ;
if ( V_41 -> V_59 [ * V_192 - 1 ] )
F_148 ( V_41 -> V_59 [ * V_192 - 1 ] ) ;
V_41 -> V_59 [ * V_192 - 1 ] = V_105 ;
* V_192 = F_23 ( V_105 ) ;
V_41 -> V_60 [ * V_192 ] = 0 ;
F_154 () ;
}
F_143 ( * V_192 < 0 ) ;
F_143 ( * V_192 >= V_202 ) ;
V_41 -> V_60 [ * V_192 ] = F_133 ( V_41 -> V_59 [ * V_192 ] ) ;
F_154 () ;
return 0 ;
}
static T_2 int F_155 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_40 * V_41 , int * V_192 ,
struct V_31 * V_32 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
T_1 V_198 ;
int V_178 ;
int V_42 ;
int V_9 ;
for ( V_178 = * V_192 ; V_178 < V_202 - 1 && V_41 -> V_59 [ V_178 ] ; V_178 ++ ) {
V_42 = V_41 -> V_60 [ V_178 ] ;
if ( V_42 + 1 < F_133 ( V_41 -> V_59 [ V_178 ] ) ) {
V_41 -> V_60 [ V_178 ] ++ ;
* V_192 = V_178 ;
F_143 ( * V_192 == 0 ) ;
return 0 ;
} else {
struct V_29 * V_200 ;
if ( V_41 -> V_59 [ * V_192 ] == V_4 -> V_205 )
V_200 = V_41 -> V_59 [ * V_192 ] ;
else
V_200 = V_41 -> V_59 [ * V_192 + 1 ] ;
V_198 = F_146 ( V_200 ) ;
V_9 = V_32 -> V_204 ( V_4 , V_41 -> V_59 [ * V_192 ] , V_32 ,
F_156 ( V_41 -> V_59 [ * V_192 ] ) ) ;
if ( V_9 )
return V_9 ;
if ( V_32 -> free ) {
struct V_29 * V_105 ;
V_105 = V_41 -> V_59 [ * V_192 ] ;
if ( V_2 ) {
F_149 ( V_105 ) ;
F_150 ( V_105 ) ;
F_151 ( V_8 , V_105 ) ;
F_26 ( V_105 ) ;
F_152 ( V_105 ) ;
}
F_143 ( V_198 != V_55 ) ;
V_9 = F_153 (
V_8 ,
V_41 -> V_59 [ * V_192 ] -> V_36 ,
V_41 -> V_59 [ * V_192 ] -> V_37 ) ;
if ( V_9 )
return V_9 ;
}
F_148 ( V_41 -> V_59 [ * V_192 ] ) ;
V_41 -> V_59 [ * V_192 ] = NULL ;
* V_192 = V_178 + 1 ;
}
}
return 1 ;
}
static int F_157 ( struct V_1 * V_2 ,
struct V_3 * log , struct V_31 * V_32 )
{
struct V_7 * V_8 = log -> V_8 ;
int V_9 = 0 ;
int V_206 ;
int V_192 ;
struct V_40 * V_41 ;
int V_207 ;
V_41 = F_92 () ;
if ( ! V_41 )
return - V_63 ;
V_192 = F_23 ( log -> V_205 ) ;
V_207 = V_192 ;
V_41 -> V_59 [ V_192 ] = log -> V_205 ;
F_158 ( log -> V_205 ) ;
V_41 -> V_60 [ V_192 ] = 0 ;
while ( 1 ) {
V_206 = F_142 ( V_2 , log , V_41 , & V_192 , V_32 ) ;
if ( V_206 > 0 )
break;
if ( V_206 < 0 ) {
V_9 = V_206 ;
goto V_13;
}
V_206 = F_155 ( V_2 , log , V_41 , & V_192 , V_32 ) ;
if ( V_206 > 0 )
break;
if ( V_206 < 0 ) {
V_9 = V_206 ;
goto V_13;
}
}
if ( V_41 -> V_59 [ V_207 ] ) {
V_9 = V_32 -> V_204 ( log , V_41 -> V_59 [ V_207 ] , V_32 ,
F_156 ( V_41 -> V_59 [ V_207 ] ) ) ;
if ( V_9 )
goto V_13;
if ( V_32 -> free ) {
struct V_29 * V_105 ;
V_105 = V_41 -> V_59 [ V_207 ] ;
if ( V_2 ) {
F_149 ( V_105 ) ;
F_150 ( V_105 ) ;
F_151 ( V_8 , V_105 ) ;
F_26 ( V_105 ) ;
F_152 ( V_105 ) ;
}
F_143 ( log -> V_53 . V_54 !=
V_55 ) ;
V_9 = F_153 ( V_8 ,
V_105 -> V_36 , V_105 -> V_37 ) ;
if ( V_9 )
goto V_13;
}
}
V_13:
F_96 ( V_41 ) ;
return V_9 ;
}
static int F_159 ( struct V_1 * V_2 ,
struct V_3 * log )
{
struct V_7 * V_8 = log -> V_8 ;
int V_9 ;
if ( log -> V_24 == 1 ) {
V_9 = F_160 ( V_2 , V_8 -> V_20 ,
& log -> V_53 , & log -> V_208 ) ;
} else {
V_9 = F_161 ( V_2 , V_8 -> V_20 ,
& log -> V_53 , & log -> V_208 ) ;
}
return V_9 ;
}
static void F_162 ( struct V_3 * V_4 , int V_79 )
{
F_163 ( V_39 ) ;
int V_23 = V_79 % 2 ;
do {
F_164 ( & V_4 -> V_209 [ V_23 ] ,
& V_39 , V_210 ) ;
F_7 ( & V_4 -> V_10 ) ;
if ( V_4 -> V_211 < V_79 &&
F_165 ( & V_4 -> V_212 [ V_23 ] ) )
F_166 () ;
F_167 ( & V_4 -> V_209 [ V_23 ] , & V_39 ) ;
F_2 ( & V_4 -> V_10 ) ;
} while ( V_4 -> V_211 < V_79 &&
F_165 ( & V_4 -> V_212 [ V_23 ] ) );
}
static void F_168 ( struct V_3 * V_4 )
{
F_163 ( V_39 ) ;
while ( F_165 ( & V_4 -> V_22 ) ) {
F_164 ( & V_4 -> V_28 ,
& V_39 , V_210 ) ;
F_7 ( & V_4 -> V_10 ) ;
if ( F_165 ( & V_4 -> V_22 ) )
F_166 () ;
F_167 ( & V_4 -> V_28 , & V_39 ) ;
F_2 ( & V_4 -> V_10 ) ;
}
}
static inline void F_169 ( struct V_3 * V_4 ,
struct V_5 * V_6 )
{
if ( ! V_6 )
return;
F_2 ( & V_4 -> V_10 ) ;
F_170 ( & V_6 -> V_25 ) ;
F_7 ( & V_4 -> V_10 ) ;
}
static inline void F_171 ( struct V_3 * V_4 ,
int V_23 , int error )
{
struct V_5 * V_6 ;
struct V_5 * V_213 ;
F_172 (ctx, safe, &root->log_ctxs[index], list) {
F_170 ( & V_6 -> V_25 ) ;
V_6 -> V_214 = error ;
}
F_173 ( & V_4 -> V_26 [ V_23 ] ) ;
}
int F_174 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_5 * V_6 )
{
int V_215 ;
int V_216 ;
int V_217 ;
int V_9 ;
struct V_7 * V_8 = V_4 -> V_8 ;
struct V_3 * log = V_4 -> V_11 ;
struct V_3 * V_20 = V_8 -> V_20 ;
int V_24 = 0 ;
struct V_5 V_218 ;
struct V_219 V_220 ;
F_2 ( & V_4 -> V_10 ) ;
V_24 = V_6 -> V_24 ;
if ( V_4 -> V_211 >= V_24 ) {
F_7 ( & V_4 -> V_10 ) ;
return V_6 -> V_214 ;
}
V_215 = V_24 % 2 ;
if ( F_165 ( & V_4 -> V_212 [ V_215 ] ) ) {
F_162 ( V_4 , V_24 ) ;
F_7 ( & V_4 -> V_10 ) ;
return V_6 -> V_214 ;
}
ASSERT ( V_24 == V_4 -> V_24 ) ;
F_175 ( & V_4 -> V_212 [ V_215 ] , 1 ) ;
if ( F_165 ( & V_4 -> V_212 [ ( V_215 + 1 ) % 2 ] ) )
F_162 ( V_4 , V_24 - 1 ) ;
while ( 1 ) {
int V_221 = F_165 ( & V_4 -> V_21 ) ;
if ( ! F_176 ( V_8 , V_222 ) &&
F_177 ( V_15 , & V_4 -> V_16 ) ) {
F_7 ( & V_4 -> V_10 ) ;
F_178 ( 1 ) ;
F_2 ( & V_4 -> V_10 ) ;
}
F_168 ( V_4 ) ;
if ( V_221 == F_165 ( & V_4 -> V_21 ) )
break;
}
if ( F_3 ( V_8 , V_2 ) ) {
V_9 = - V_12 ;
F_179 ( log , V_24 ) ;
F_7 ( & V_4 -> V_10 ) ;
goto V_13;
}
if ( V_24 % 2 == 0 )
V_217 = V_223 ;
else
V_217 = V_224 ;
F_180 ( & V_220 ) ;
V_9 = F_181 ( V_8 , & log -> V_225 , V_217 ) ;
if ( V_9 ) {
F_182 ( & V_220 ) ;
F_183 ( V_2 , V_9 ) ;
F_179 ( log , V_24 ) ;
F_184 ( V_8 , V_2 ) ;
F_7 ( & V_4 -> V_10 ) ;
goto V_13;
}
F_185 ( & log -> V_208 , log -> V_205 ) ;
V_4 -> V_24 ++ ;
log -> V_24 = V_4 -> V_24 ;
V_4 -> V_14 = 0 ;
F_7 ( & V_4 -> V_10 ) ;
F_186 ( & V_218 , NULL ) ;
F_2 ( & V_20 -> V_10 ) ;
F_9 ( & V_20 -> V_21 ) ;
F_9 ( & V_20 -> V_22 ) ;
V_216 = V_20 -> V_24 % 2 ;
F_10 ( & V_218 . V_25 , & V_20 -> V_26 [ V_216 ] ) ;
V_218 . V_24 = V_20 -> V_24 ;
F_7 ( & V_20 -> V_10 ) ;
V_9 = F_159 ( V_2 , log ) ;
F_2 ( & V_20 -> V_10 ) ;
if ( F_15 ( & V_20 -> V_22 ) ) {
if ( F_16 ( & V_20 -> V_28 ) )
F_17 ( & V_20 -> V_28 ) ;
}
if ( V_9 ) {
if ( ! F_73 ( & V_218 . V_25 ) )
F_170 ( & V_218 . V_25 ) ;
F_182 ( & V_220 ) ;
F_184 ( V_8 , V_2 ) ;
if ( V_9 != - V_226 ) {
F_183 ( V_2 , V_9 ) ;
F_7 ( & V_20 -> V_10 ) ;
goto V_13;
}
F_187 ( log , V_217 ) ;
F_179 ( log , V_24 ) ;
F_7 ( & V_20 -> V_10 ) ;
V_9 = - V_12 ;
goto V_13;
}
if ( V_20 -> V_211 >= V_218 . V_24 ) {
F_182 ( & V_220 ) ;
F_170 ( & V_218 . V_25 ) ;
F_7 ( & V_20 -> V_10 ) ;
V_9 = V_218 . V_214 ;
goto V_13;
}
V_216 = V_218 . V_24 % 2 ;
if ( F_165 ( & V_20 -> V_212 [ V_216 ] ) ) {
F_182 ( & V_220 ) ;
V_9 = F_187 ( log , V_217 ) ;
F_188 ( V_2 , log , V_24 ) ;
F_162 ( V_20 ,
V_218 . V_24 ) ;
F_7 ( & V_20 -> V_10 ) ;
if ( ! V_9 )
V_9 = V_218 . V_214 ;
goto V_13;
}
ASSERT ( V_218 . V_24 == V_20 -> V_24 ) ;
F_175 ( & V_20 -> V_212 [ V_216 ] , 1 ) ;
if ( F_165 ( & V_20 -> V_212 [ ( V_216 + 1 ) % 2 ] ) ) {
F_162 ( V_20 ,
V_218 . V_24 - 1 ) ;
}
F_168 ( V_20 ) ;
if ( F_3 ( V_8 , V_2 ) ) {
F_182 ( & V_220 ) ;
F_187 ( log , V_217 ) ;
F_179 ( log , V_24 ) ;
F_7 ( & V_20 -> V_10 ) ;
V_9 = - V_12 ;
goto V_227;
}
V_9 = F_181 ( V_8 ,
& V_20 -> V_225 ,
V_223 | V_224 ) ;
F_182 ( & V_220 ) ;
if ( V_9 ) {
F_184 ( V_8 , V_2 ) ;
F_183 ( V_2 , V_9 ) ;
F_179 ( log , V_24 ) ;
F_7 ( & V_20 -> V_10 ) ;
goto V_227;
}
V_9 = F_187 ( log , V_217 ) ;
if ( ! V_9 )
V_9 = F_187 ( V_20 ,
V_224 | V_223 ) ;
if ( V_9 ) {
F_184 ( V_8 , V_2 ) ;
F_179 ( log , V_24 ) ;
F_7 ( & V_20 -> V_10 ) ;
goto V_227;
}
F_188 ( V_2 , log , V_24 ) ;
F_189 ( V_8 -> V_228 ,
V_20 -> V_205 -> V_36 ) ;
F_190 ( V_8 -> V_228 ,
F_23 ( V_20 -> V_205 ) ) ;
V_20 -> V_24 ++ ;
F_7 ( & V_20 -> V_10 ) ;
V_9 = F_191 ( V_8 , 1 ) ;
if ( V_9 ) {
F_184 ( V_8 , V_2 ) ;
F_183 ( V_2 , V_9 ) ;
goto V_227;
}
F_2 ( & V_4 -> V_10 ) ;
if ( V_4 -> V_229 < V_24 )
V_4 -> V_229 = V_24 ;
F_7 ( & V_4 -> V_10 ) ;
V_227:
F_2 ( & V_20 -> V_10 ) ;
F_171 ( V_20 , V_216 , V_9 ) ;
V_20 -> V_211 ++ ;
F_175 ( & V_20 -> V_212 [ V_216 ] , 0 ) ;
F_7 ( & V_20 -> V_10 ) ;
if ( F_16 ( & V_20 -> V_209 [ V_216 ] ) )
F_17 ( & V_20 -> V_209 [ V_216 ] ) ;
V_13:
F_2 ( & V_4 -> V_10 ) ;
F_171 ( V_4 , V_215 , V_9 ) ;
V_4 -> V_211 ++ ;
F_175 ( & V_4 -> V_212 [ V_215 ] , 0 ) ;
F_7 ( & V_4 -> V_10 ) ;
if ( F_16 ( & V_4 -> V_209 [ V_215 ] ) )
F_17 ( & V_4 -> V_209 [ V_215 ] ) ;
return V_9 ;
}
static void F_192 ( struct V_1 * V_2 ,
struct V_3 * log )
{
int V_9 ;
T_1 V_36 ;
T_1 V_230 ;
struct V_31 V_32 = {
. free = 1 ,
. V_204 = F_18
} ;
V_9 = F_157 ( V_2 , log , & V_32 ) ;
if ( V_9 )
F_183 ( V_2 , V_9 ) ;
while ( 1 ) {
V_9 = F_193 ( & log -> V_225 ,
0 , & V_36 , & V_230 , V_223 | V_224 ,
NULL ) ;
if ( V_9 )
break;
F_194 ( & log -> V_225 , V_36 , V_230 ,
V_223 | V_224 ) ;
}
F_179 ( log , 0 ) ;
F_179 ( log , 1 ) ;
F_148 ( log -> V_205 ) ;
F_33 ( log ) ;
}
int F_195 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( V_4 -> V_11 ) {
F_192 ( V_2 , V_4 -> V_11 ) ;
V_4 -> V_11 = NULL ;
}
return 0 ;
}
int F_196 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
if ( V_8 -> V_20 ) {
F_192 ( V_2 , V_8 -> V_20 ) ;
V_8 -> V_20 = NULL ;
}
return 0 ;
}
int F_197 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_112 , int V_113 ,
struct V_108 * V_109 , T_1 V_23 )
{
struct V_3 * log ;
struct V_110 * V_111 ;
struct V_40 * V_41 ;
int V_9 ;
int V_231 = 0 ;
int V_232 = 0 ;
T_1 V_233 = F_61 ( V_109 ) ;
if ( V_109 -> V_234 < V_2 -> V_79 )
return 0 ;
V_9 = F_11 ( V_4 ) ;
if ( V_9 )
return 0 ;
F_2 ( & V_109 -> V_10 ) ;
log = V_4 -> V_11 ;
V_41 = F_92 () ;
if ( ! V_41 ) {
V_231 = - V_63 ;
goto V_235;
}
V_111 = F_90 ( V_2 , log , V_41 , V_233 ,
V_112 , V_113 , - 1 ) ;
if ( F_89 ( V_111 ) ) {
V_231 = F_136 ( V_111 ) ;
goto V_236;
}
if ( V_111 ) {
V_9 = F_140 ( V_2 , log , V_41 , V_111 ) ;
V_232 += V_113 ;
if ( V_9 ) {
V_231 = V_9 ;
goto V_236;
}
}
F_31 ( V_41 ) ;
V_111 = F_88 ( V_2 , log , V_41 , V_233 ,
V_23 , V_112 , V_113 , - 1 ) ;
if ( F_89 ( V_111 ) ) {
V_231 = F_136 ( V_111 ) ;
goto V_236;
}
if ( V_111 ) {
V_9 = F_140 ( V_2 , log , V_41 , V_111 ) ;
V_232 += V_113 ;
if ( V_9 ) {
V_231 = V_9 ;
goto V_236;
}
}
if ( V_232 ) {
struct V_43 V_44 ;
V_44 . V_54 = V_233 ;
V_44 . V_82 = 0 ;
V_44 . type = V_52 ;
F_31 ( V_41 ) ;
V_9 = F_30 ( V_2 , log , & V_44 , V_41 , 0 , 1 ) ;
if ( V_9 < 0 ) {
V_231 = V_9 ;
goto V_236;
}
if ( V_9 == 0 ) {
struct V_64 * V_65 ;
T_1 V_165 ;
V_65 = F_35 ( V_41 -> V_59 [ 0 ] , V_41 -> V_60 [ 0 ] ,
struct V_64 ) ;
V_165 = F_45 ( V_41 -> V_59 [ 0 ] , V_65 ) ;
if ( V_165 > V_232 )
V_165 -= V_232 ;
else
V_165 = 0 ;
F_40 ( V_41 -> V_59 [ 0 ] , V_65 , V_165 ) ;
F_51 ( V_41 -> V_59 [ 0 ] ) ;
} else
V_9 = 0 ;
F_31 ( V_41 ) ;
}
V_236:
F_96 ( V_41 ) ;
V_235:
F_7 ( & V_109 -> V_10 ) ;
if ( V_9 == - V_226 ) {
F_184 ( V_4 -> V_8 , V_2 ) ;
V_9 = 0 ;
} else if ( V_9 < 0 )
F_183 ( V_2 , V_9 ) ;
F_14 ( V_4 ) ;
return V_231 ;
}
int F_198 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_112 , int V_113 ,
struct V_108 * V_84 , T_1 V_115 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
struct V_3 * log ;
T_1 V_23 ;
int V_9 ;
if ( V_84 -> V_234 < V_2 -> V_79 )
return 0 ;
V_9 = F_11 ( V_4 ) ;
if ( V_9 )
return 0 ;
log = V_4 -> V_11 ;
F_2 ( & V_84 -> V_10 ) ;
V_9 = F_199 ( V_2 , log , V_112 , V_113 , F_61 ( V_84 ) ,
V_115 , & V_23 ) ;
F_7 ( & V_84 -> V_10 ) ;
if ( V_9 == - V_226 ) {
F_184 ( V_8 , V_2 ) ;
V_9 = 0 ;
} else if ( V_9 < 0 && V_9 != - V_27 )
F_183 ( V_2 , V_9 ) ;
F_14 ( V_4 ) ;
return V_9 ;
}
static T_2 int F_200 ( struct V_1 * V_2 ,
struct V_3 * log ,
struct V_40 * V_41 ,
int V_169 , T_1 V_115 ,
T_1 V_237 , T_1 V_238 )
{
int V_9 ;
struct V_43 V_44 ;
struct V_173 * V_65 ;
V_44 . V_54 = V_115 ;
V_44 . V_82 = V_237 ;
if ( V_169 == V_163 )
V_44 . type = V_188 ;
else
V_44 . type = V_190 ;
V_9 = F_41 ( V_2 , log , V_41 , & V_44 , sizeof( * V_65 ) ) ;
if ( V_9 )
return V_9 ;
V_65 = F_35 ( V_41 -> V_59 [ 0 ] , V_41 -> V_60 [ 0 ] ,
struct V_173 ) ;
F_201 ( V_41 -> V_59 [ 0 ] , V_65 , V_238 ) ;
F_51 ( V_41 -> V_59 [ 0 ] ) ;
F_31 ( V_41 ) ;
return 0 ;
}
static T_2 int F_202 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_108 * V_84 ,
struct V_40 * V_41 ,
struct V_40 * V_239 , int V_169 ,
struct V_5 * V_6 ,
T_1 V_240 , T_1 * V_241 )
{
struct V_43 V_242 ;
struct V_3 * log = V_4 -> V_11 ;
struct V_29 * V_243 ;
int V_231 = 0 ;
int V_9 ;
int V_178 ;
int V_174 ;
T_1 V_237 = V_240 ;
T_1 V_238 = ( T_1 ) - 1 ;
T_1 V_147 = F_61 ( V_84 ) ;
log = V_4 -> V_11 ;
V_242 . V_54 = V_147 ;
V_242 . type = V_169 ;
V_242 . V_82 = V_240 ;
V_9 = F_203 ( V_4 , & V_242 , V_41 , V_2 -> V_79 ) ;
if ( V_9 != 0 || V_242 . V_54 != V_147 || V_242 . type != V_169 ) {
V_242 . V_54 = V_147 ;
V_242 . type = V_169 ;
V_242 . V_82 = ( T_1 ) - 1 ;
F_31 ( V_41 ) ;
V_9 = F_30 ( NULL , V_4 , & V_242 , V_41 , 0 , 0 ) ;
if ( V_9 < 0 ) {
F_31 ( V_41 ) ;
return V_9 ;
}
V_9 = F_204 ( V_4 , V_41 , V_147 , V_169 ) ;
if ( V_9 == 0 ) {
struct V_43 V_244 ;
F_116 ( V_41 -> V_59 [ 0 ] , & V_244 ,
V_41 -> V_60 [ 0 ] ) ;
if ( V_169 == V_244 . type )
V_237 = F_205 ( V_240 , V_244 . V_82 ) + 1 ;
}
goto V_245;
}
V_9 = F_204 ( V_4 , V_41 , V_147 , V_169 ) ;
if ( V_9 == 0 ) {
struct V_43 V_244 ;
F_116 ( V_41 -> V_59 [ 0 ] , & V_244 , V_41 -> V_60 [ 0 ] ) ;
if ( V_169 == V_244 . type ) {
V_237 = V_244 . V_82 ;
V_9 = F_27 ( V_2 , log , V_239 ,
V_41 -> V_59 [ 0 ] , V_41 -> V_60 [ 0 ] ,
& V_244 ) ;
if ( V_9 ) {
V_231 = V_9 ;
goto V_245;
}
}
}
F_31 ( V_41 ) ;
V_9 = F_30 ( NULL , V_4 , & V_242 , V_41 , 0 , 0 ) ;
if ( F_143 ( V_9 != 0 ) )
goto V_245;
while ( 1 ) {
struct V_43 V_244 ;
V_243 = V_41 -> V_59 [ 0 ] ;
V_174 = F_133 ( V_243 ) ;
for ( V_178 = V_41 -> V_60 [ 0 ] ; V_178 < V_174 ; V_178 ++ ) {
struct V_110 * V_111 ;
F_116 ( V_243 , & V_242 , V_178 ) ;
if ( V_242 . V_54 != V_147 || V_242 . type != V_169 )
goto V_245;
V_9 = F_27 ( V_2 , log , V_239 , V_243 , V_178 ,
& V_242 ) ;
if ( V_9 ) {
V_231 = V_9 ;
goto V_245;
}
V_111 = F_35 ( V_243 , V_178 , struct V_110 ) ;
F_82 ( V_243 , V_111 , & V_244 ) ;
if ( V_6 &&
( F_206 ( V_243 , V_111 ) == V_2 -> V_79 ||
F_126 ( V_243 , V_111 ) == V_167 ) &&
V_244 . type != V_246 )
V_6 -> V_247 = true ;
}
V_41 -> V_60 [ 0 ] = V_174 ;
V_9 = F_134 ( V_4 , V_41 ) ;
if ( V_9 == 1 ) {
V_238 = ( T_1 ) - 1 ;
goto V_245;
}
F_116 ( V_41 -> V_59 [ 0 ] , & V_244 , V_41 -> V_60 [ 0 ] ) ;
if ( V_244 . V_54 != V_147 || V_244 . type != V_169 ) {
V_238 = ( T_1 ) - 1 ;
goto V_245;
}
if ( F_156 ( V_41 -> V_59 [ 0 ] ) != V_2 -> V_79 ) {
V_9 = F_27 ( V_2 , log , V_239 ,
V_41 -> V_59 [ 0 ] , V_41 -> V_60 [ 0 ] ,
& V_244 ) ;
if ( V_9 )
V_231 = V_9 ;
else
V_238 = V_244 . V_82 ;
goto V_245;
}
}
V_245:
F_31 ( V_41 ) ;
F_31 ( V_239 ) ;
if ( V_231 == 0 ) {
* V_241 = V_238 ;
V_9 = F_200 ( V_2 , log , V_41 , V_169 ,
V_147 , V_237 , V_238 ) ;
if ( V_9 )
V_231 = V_9 ;
}
return V_231 ;
}
static T_2 int F_207 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_108 * V_84 ,
struct V_40 * V_41 ,
struct V_40 * V_239 ,
struct V_5 * V_6 )
{
T_1 V_242 ;
T_1 V_248 ;
int V_9 ;
int V_169 = V_163 ;
V_135:
V_242 = 0 ;
V_248 = 0 ;
while ( 1 ) {
V_9 = F_202 ( V_2 , V_4 , V_84 , V_41 , V_239 , V_169 ,
V_6 , V_242 , & V_248 ) ;
if ( V_9 )
return V_9 ;
if ( V_248 == ( T_1 ) - 1 )
break;
V_242 = V_248 + 1 ;
}
if ( V_169 == V_163 ) {
V_169 = V_161 ;
goto V_135;
}
return 0 ;
}
static int F_208 ( struct V_1 * V_2 ,
struct V_3 * log ,
struct V_40 * V_41 ,
T_1 V_54 , int V_249 )
{
int V_9 ;
struct V_43 V_44 ;
struct V_43 V_156 ;
int V_250 ;
V_44 . V_54 = V_54 ;
V_44 . type = V_249 ;
V_44 . V_82 = ( T_1 ) - 1 ;
while ( 1 ) {
V_9 = F_30 ( V_2 , log , & V_44 , V_41 , - 1 , 1 ) ;
F_209 ( V_9 == 0 ) ;
if ( V_9 < 0 )
break;
if ( V_41 -> V_60 [ 0 ] == 0 )
break;
V_41 -> V_60 [ 0 ] -- ;
F_116 ( V_41 -> V_59 [ 0 ] , & V_156 ,
V_41 -> V_60 [ 0 ] ) ;
if ( V_156 . V_54 != V_54 )
break;
V_156 . V_82 = 0 ;
V_156 . type = 0 ;
V_9 = F_210 ( V_41 -> V_59 [ 0 ] , & V_156 , 0 ,
& V_250 ) ;
V_9 = F_211 ( V_2 , log , V_41 , V_250 ,
V_41 -> V_60 [ 0 ] - V_250 + 1 ) ;
if ( V_9 || V_250 != 0 )
break;
F_31 ( V_41 ) ;
}
F_31 ( V_41 ) ;
if ( V_9 > 0 )
V_9 = 0 ;
return V_9 ;
}
static void F_212 ( struct V_1 * V_2 ,
struct V_29 * V_94 ,
struct V_64 * V_65 ,
struct V_84 * V_84 , int V_251 ,
T_1 V_252 )
{
struct V_76 V_77 ;
F_47 ( & V_77 ) ;
if ( V_251 ) {
F_213 ( V_94 , V_65 , 0 , & V_77 ) ;
F_48 ( V_94 , V_65 , V_252 , & V_77 ) ;
} else {
F_213 ( V_94 , V_65 ,
F_62 ( V_84 ) -> V_253 ,
& V_77 ) ;
F_48 ( V_94 , V_65 , V_84 -> V_165 , & V_77 ) ;
}
F_214 ( V_94 , V_65 , F_215 ( V_84 ) , & V_77 ) ;
F_216 ( V_94 , V_65 , F_217 ( V_84 ) , & V_77 ) ;
F_218 ( V_94 , V_65 , V_84 -> V_152 , & V_77 ) ;
F_219 ( V_94 , V_65 , V_84 -> V_150 , & V_77 ) ;
F_220 ( V_94 , & V_65 -> V_254 ,
V_84 -> V_255 . V_256 , & V_77 ) ;
F_221 ( V_94 , & V_65 -> V_254 ,
V_84 -> V_255 . V_257 , & V_77 ) ;
F_220 ( V_94 , & V_65 -> V_258 ,
V_84 -> V_259 . V_256 , & V_77 ) ;
F_221 ( V_94 , & V_65 -> V_258 ,
V_84 -> V_259 . V_257 , & V_77 ) ;
F_220 ( V_94 , & V_65 -> ctime ,
V_84 -> V_260 . V_256 , & V_77 ) ;
F_221 ( V_94 , & V_65 -> ctime ,
V_84 -> V_260 . V_257 , & V_77 ) ;
F_222 ( V_94 , V_65 , F_223 ( V_84 ) ,
& V_77 ) ;
F_224 ( V_94 , V_65 , V_84 -> V_261 , & V_77 ) ;
F_225 ( V_94 , V_65 , V_2 -> V_79 , & V_77 ) ;
F_226 ( V_94 , V_65 , V_84 -> V_262 , & V_77 ) ;
F_227 ( V_94 , V_65 , F_62 ( V_84 ) -> V_263 , & V_77 ) ;
F_228 ( V_94 , V_65 , 0 , & V_77 ) ;
}
static int F_229 ( struct V_1 * V_2 ,
struct V_3 * log , struct V_40 * V_41 ,
struct V_108 * V_84 )
{
struct V_64 * V_51 ;
int V_9 ;
V_9 = F_41 ( V_2 , log , V_41 ,
& V_84 -> V_114 , sizeof( * V_51 ) ) ;
if ( V_9 && V_9 != - V_69 )
return V_9 ;
V_51 = F_35 ( V_41 -> V_59 [ 0 ] , V_41 -> V_60 [ 0 ] ,
struct V_64 ) ;
F_212 ( V_2 , V_41 -> V_59 [ 0 ] , V_51 , & V_84 -> V_138 ,
0 , 0 ) ;
F_31 ( V_41 ) ;
return 0 ;
}
static T_2 int F_230 ( struct V_1 * V_2 ,
struct V_108 * V_84 ,
struct V_40 * V_239 ,
struct V_40 * V_264 , T_1 * V_265 ,
int V_250 , int V_266 , int V_267 ,
T_1 V_252 )
{
struct V_7 * V_8 = F_231 ( V_84 -> V_138 . V_268 ) ;
unsigned long V_269 ;
unsigned long V_270 ;
struct V_3 * log = V_84 -> V_4 -> V_11 ;
struct V_83 * V_271 ;
struct V_64 * V_51 ;
struct V_29 * V_243 = V_264 -> V_59 [ 0 ] ;
struct V_43 V_272 , V_273 , V_44 ;
int V_9 ;
struct V_43 * V_274 ;
T_3 * V_275 ;
char * V_276 ;
int V_178 ;
struct V_277 V_102 ;
int V_278 = V_84 -> V_263 & V_279 ;
bool V_280 = false ;
bool V_281 = true ;
bool V_245 = false ;
F_173 ( & V_102 ) ;
V_276 = F_32 ( V_266 * sizeof( struct V_43 ) +
V_266 * sizeof( T_3 ) , V_62 ) ;
if ( ! V_276 )
return - V_63 ;
V_272 . V_54 = ( T_1 ) - 1 ;
V_275 = ( T_3 * ) V_276 ;
V_274 = (struct V_43 * ) ( V_276 + V_266 * sizeof( T_3 ) ) ;
for ( V_178 = 0 ; V_178 < V_266 ; V_178 ++ ) {
V_275 [ V_178 ] = F_28 ( V_243 , V_178 + V_250 ) ;
F_116 ( V_243 , V_274 + V_178 , V_178 + V_250 ) ;
}
V_9 = F_232 ( V_2 , log , V_239 ,
V_274 , V_275 , V_266 ) ;
if ( V_9 ) {
F_33 ( V_276 ) ;
return V_9 ;
}
for ( V_178 = 0 ; V_178 < V_266 ; V_178 ++ , V_239 -> V_60 [ 0 ] ++ ) {
V_270 = F_29 ( V_239 -> V_59 [ 0 ] ,
V_239 -> V_60 [ 0 ] ) ;
V_269 = F_29 ( V_243 , V_250 + V_178 ) ;
if ( ( V_178 == ( V_266 - 1 ) ) )
V_273 = V_274 [ V_178 ] ;
if ( V_274 [ V_178 ] . type == V_52 ) {
V_51 = F_35 ( V_239 -> V_59 [ 0 ] ,
V_239 -> V_60 [ 0 ] ,
struct V_64 ) ;
F_212 ( V_2 , V_239 -> V_59 [ 0 ] , V_51 ,
& V_84 -> V_138 ,
V_267 == V_282 ,
V_252 ) ;
} else {
F_49 ( V_239 -> V_59 [ 0 ] , V_243 , V_270 ,
V_269 , V_275 [ V_178 ] ) ;
}
if ( V_274 [ V_178 ] . type == V_197 ) {
V_280 = true ;
if ( V_272 . V_54 == ( T_1 ) - 1 )
V_272 = V_274 [ V_178 ] ;
} else {
V_281 = false ;
}
if ( V_274 [ V_178 ] . type == V_197 &&
! V_278 ) {
int V_80 ;
V_271 = F_35 ( V_243 , V_250 + V_178 ,
struct V_83 ) ;
if ( F_233 ( V_243 , V_271 ) < V_2 -> V_79 )
continue;
V_80 = F_53 ( V_243 , V_271 ) ;
if ( V_80 == V_86 ) {
T_1 V_283 , V_284 , V_285 , V_286 ;
V_283 = F_55 ( V_243 ,
V_271 ) ;
if ( V_283 == 0 )
continue;
V_284 = F_64 ( V_243 ,
V_271 ) ;
V_285 = F_65 ( V_243 , V_271 ) ;
V_286 = F_54 ( V_243 ,
V_271 ) ;
if ( F_71 ( V_243 ,
V_271 ) ) {
V_285 = 0 ;
V_286 = V_284 ;
}
V_9 = F_72 (
V_8 -> V_107 ,
V_283 + V_285 , V_283 + V_285 + V_286 - 1 ,
& V_102 , 0 ) ;
if ( V_9 ) {
F_31 ( V_239 ) ;
F_33 ( V_276 ) ;
return V_9 ;
}
}
}
}
F_51 ( V_239 -> V_59 [ 0 ] ) ;
F_31 ( V_239 ) ;
F_33 ( V_276 ) ;
V_9 = 0 ;
while ( ! F_73 ( & V_102 ) ) {
struct V_103 * V_104 = F_74 ( V_102 . V_105 ,
struct V_103 ,
V_25 ) ;
if ( ! V_9 )
V_9 = F_76 ( V_2 , log , V_104 ) ;
F_77 ( & V_104 -> V_25 ) ;
F_33 ( V_104 ) ;
}
if ( ! V_280 )
return V_9 ;
if ( V_281 && * V_265 == V_272 . V_82 ) {
V_281 = false ;
}
if ( V_281 ) {
T_1 V_37 ;
V_9 = F_234 ( V_84 -> V_4 , V_264 ) ;
if ( V_9 < 0 )
return V_9 ;
if ( V_9 )
goto V_287;
if ( V_264 -> V_60 [ 0 ] )
V_264 -> V_60 [ 0 ] -- ;
V_243 = V_264 -> V_59 [ 0 ] ;
F_116 ( V_243 , & V_44 , V_264 -> V_60 [ 0 ] ) ;
if ( V_44 . V_54 != F_61 ( V_84 ) ||
V_44 . type != V_197 )
goto V_287;
V_271 = F_35 ( V_243 , V_264 -> V_60 [ 0 ] ,
struct V_83 ) ;
if ( F_53 ( V_243 , V_271 ) ==
V_88 ) {
V_37 = F_56 ( V_243 ,
V_264 -> V_60 [ 0 ] ,
V_271 ) ;
* V_265 = F_58 ( V_44 . V_82 + V_37 ,
V_8 -> V_89 ) ;
} else {
V_37 = F_54 ( V_243 , V_271 ) ;
* V_265 = V_44 . V_82 + V_37 ;
}
}
V_287:
if ( V_281 ) {
F_31 ( V_264 ) ;
V_9 = F_30 ( NULL , V_84 -> V_4 , & V_272 ,
V_264 , 0 , 0 ) ;
if ( V_9 < 0 )
return V_9 ;
ASSERT ( V_9 == 0 ) ;
V_243 = V_264 -> V_59 [ 0 ] ;
V_178 = V_264 -> V_60 [ 0 ] ;
} else {
V_178 = V_250 ;
}
while ( ! V_245 ) {
T_1 V_82 , V_37 ;
T_1 V_81 ;
if ( V_178 >= F_133 ( V_264 -> V_59 [ 0 ] ) ) {
V_9 = F_134 ( V_84 -> V_4 , V_264 ) ;
if ( V_9 < 0 )
return V_9 ;
ASSERT ( V_9 == 0 ) ;
V_243 = V_264 -> V_59 [ 0 ] ;
V_178 = 0 ;
}
F_116 ( V_243 , & V_44 , V_178 ) ;
if ( ! F_235 ( & V_44 , & V_273 ) )
V_245 = true ;
if ( V_44 . V_54 != F_61 ( V_84 ) ||
V_44 . type != V_197 ) {
V_178 ++ ;
continue;
}
V_271 = F_35 ( V_243 , V_178 , struct V_83 ) ;
if ( F_53 ( V_243 , V_271 ) ==
V_88 ) {
V_37 = F_56 ( V_243 , V_178 , V_271 ) ;
V_81 = F_58 ( V_44 . V_82 + V_37 ,
V_8 -> V_89 ) ;
} else {
V_37 = F_54 ( V_243 , V_271 ) ;
V_81 = V_44 . V_82 + V_37 ;
}
V_178 ++ ;
if ( * V_265 == V_44 . V_82 ) {
* V_265 = V_81 ;
continue;
}
V_82 = * V_265 ;
V_37 = V_44 . V_82 - * V_265 ;
V_9 = F_236 ( V_2 , log , F_61 ( V_84 ) ,
V_82 , 0 , 0 , V_37 , 0 , V_37 , 0 , 0 , 0 ) ;
if ( V_9 )
break;
* V_265 = V_81 ;
}
if ( ! V_9 && V_281 )
V_9 = 1 ;
return V_9 ;
}
static int F_237 ( void * V_288 , struct V_277 * V_289 , struct V_277 * V_290 )
{
struct V_291 * V_292 , * V_293 ;
V_292 = F_74 ( V_289 , struct V_291 , V_25 ) ;
V_293 = F_74 ( V_290 , struct V_291 , V_25 ) ;
if ( V_292 -> V_36 < V_293 -> V_36 )
return - 1 ;
else if ( V_292 -> V_36 > V_293 -> V_36 )
return 1 ;
return 0 ;
}
static int F_238 ( struct V_1 * V_2 ,
struct V_84 * V_84 ,
struct V_3 * V_4 ,
const struct V_291 * V_294 ,
const struct V_277 * V_295 ,
bool * V_296 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
struct V_297 * V_298 ;
struct V_3 * log = V_4 -> V_11 ;
T_1 V_299 = V_294 -> V_299 ;
T_1 V_300 = V_294 -> V_300 ;
const bool V_278 = F_62 ( V_84 ) -> V_263 & V_279 ;
T_1 V_301 ;
T_1 V_302 ;
F_67 ( V_102 ) ;
int V_9 = 0 ;
* V_296 = false ;
if ( F_177 ( V_303 , & V_294 -> V_263 ) ||
V_294 -> V_304 == V_305 )
return 0 ;
F_239 (ordered, logged_list, log_list) {
struct V_103 * V_306 ;
if ( ! V_300 )
break;
if ( V_298 -> V_307 + V_298 -> V_37 <= V_299 ||
V_299 + V_300 <= V_298 -> V_307 )
continue;
if ( ! F_177 ( V_308 , & V_298 -> V_263 ) &&
! F_177 ( V_309 , & V_298 -> V_263 ) &&
! F_177 ( V_310 , & V_298 -> V_263 ) ) {
const T_1 V_36 = V_298 -> V_307 ;
const T_1 V_230 = V_298 -> V_307 + V_298 -> V_37 - 1 ;
F_143 ( V_298 -> V_84 != V_84 ) ;
F_240 ( V_84 -> V_311 , V_36 , V_230 ) ;
}
F_241 ( V_298 -> V_39 ,
( F_177 ( V_308 , & V_298 -> V_263 ) ||
F_177 ( V_309 , & V_298 -> V_263 ) ) ) ;
if ( F_177 ( V_309 , & V_298 -> V_263 ) ) {
F_242 ( V_84 -> V_311 ) ;
* V_296 = true ;
break;
}
if ( V_298 -> V_307 > V_299 ) {
if ( V_298 -> V_307 + V_298 -> V_37 >=
V_299 + V_300 )
V_300 = V_298 -> V_307 - V_299 ;
} else {
if ( V_298 -> V_307 + V_298 -> V_37 <
V_299 + V_300 ) {
V_300 = ( V_299 + V_300 ) -
( V_298 -> V_307 + V_298 -> V_37 ) ;
V_299 = V_298 -> V_307 +
V_298 -> V_37 ;
} else {
V_300 = 0 ;
}
}
if ( V_278 )
continue;
if ( F_243 ( V_312 ,
& V_298 -> V_263 ) )
continue;
F_239 (sum, &ordered->list, list) {
V_9 = F_76 ( V_2 , log , V_306 ) ;
if ( V_9 )
break;
}
}
if ( * V_296 || ! V_300 || V_9 || V_278 )
return V_9 ;
if ( V_294 -> V_313 ) {
V_301 = 0 ;
V_302 = F_205 ( V_294 -> V_314 , V_294 -> V_315 ) ;
} else {
V_301 = V_299 - V_294 -> V_36 ;
V_302 = V_300 ;
}
V_9 = F_72 ( V_8 -> V_107 ,
V_294 -> V_304 + V_301 ,
V_294 -> V_304 + V_301 +
V_302 - 1 , & V_102 , 0 ) ;
if ( V_9 )
return V_9 ;
while ( ! F_73 ( & V_102 ) ) {
struct V_103 * V_104 = F_74 ( V_102 . V_105 ,
struct V_103 ,
V_25 ) ;
if ( ! V_9 )
V_9 = F_76 ( V_2 , log , V_104 ) ;
F_77 ( & V_104 -> V_25 ) ;
F_33 ( V_104 ) ;
}
return V_9 ;
}
static int F_244 ( struct V_1 * V_2 ,
struct V_108 * V_84 , struct V_3 * V_4 ,
const struct V_291 * V_294 ,
struct V_40 * V_41 ,
const struct V_277 * V_295 ,
struct V_5 * V_6 )
{
struct V_3 * log = V_4 -> V_11 ;
struct V_83 * V_316 ;
struct V_29 * V_94 ;
struct V_76 V_77 ;
struct V_43 V_44 ;
T_1 V_317 = V_294 -> V_36 - V_294 -> V_318 ;
T_1 V_314 ;
int V_9 ;
int V_319 = 0 ;
bool V_320 = false ;
V_9 = F_238 ( V_2 , & V_84 -> V_138 , V_4 , V_294 ,
V_295 , & V_320 ) ;
if ( V_9 )
return V_9 ;
if ( V_320 ) {
V_6 -> V_321 = - V_90 ;
return 0 ;
}
F_47 ( & V_77 ) ;
V_9 = F_245 ( V_2 , log , & V_84 -> V_138 , V_41 , V_294 -> V_36 ,
V_294 -> V_36 + V_294 -> V_37 , NULL , 0 , 1 ,
sizeof( * V_316 ) , & V_319 ) ;
if ( V_9 )
return V_9 ;
if ( ! V_319 ) {
V_44 . V_54 = F_61 ( V_84 ) ;
V_44 . type = V_197 ;
V_44 . V_82 = V_294 -> V_36 ;
V_9 = F_41 ( V_2 , log , V_41 , & V_44 ,
sizeof( * V_316 ) ) ;
if ( V_9 )
return V_9 ;
}
V_94 = V_41 -> V_59 [ 0 ] ;
V_316 = F_35 ( V_94 , V_41 -> V_60 [ 0 ] ,
struct V_83 ) ;
F_246 ( V_94 , V_316 , V_2 -> V_79 ,
& V_77 ) ;
if ( F_177 ( V_303 , & V_294 -> V_263 ) )
F_247 ( V_94 , V_316 ,
V_87 ,
& V_77 ) ;
else
F_247 ( V_94 , V_316 ,
V_86 ,
& V_77 ) ;
V_314 = F_205 ( V_294 -> V_314 , V_294 -> V_315 ) ;
if ( V_294 -> V_313 != V_322 ) {
F_248 ( V_94 , V_316 ,
V_294 -> V_304 ,
& V_77 ) ;
F_249 ( V_94 , V_316 , V_314 ,
& V_77 ) ;
} else if ( V_294 -> V_304 < V_323 ) {
F_248 ( V_94 , V_316 ,
V_294 -> V_304 -
V_317 , & V_77 ) ;
F_249 ( V_94 , V_316 , V_314 ,
& V_77 ) ;
} else {
F_248 ( V_94 , V_316 , 0 , & V_77 ) ;
F_249 ( V_94 , V_316 , 0 ,
& V_77 ) ;
}
F_250 ( V_94 , V_316 , V_317 , & V_77 ) ;
F_251 ( V_94 , V_316 , V_294 -> V_37 , & V_77 ) ;
F_252 ( V_94 , V_316 , V_294 -> V_324 , & V_77 ) ;
F_253 ( V_94 , V_316 , V_294 -> V_313 ,
& V_77 ) ;
F_254 ( V_94 , V_316 , 0 , & V_77 ) ;
F_255 ( V_94 , V_316 , 0 , & V_77 ) ;
F_51 ( V_94 ) ;
F_31 ( V_41 ) ;
return V_9 ;
}
static int F_256 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_108 * V_84 ,
struct V_40 * V_41 ,
struct V_277 * V_295 ,
struct V_5 * V_6 ,
const T_1 V_36 ,
const T_1 V_230 )
{
struct V_291 * V_294 , * V_325 ;
struct V_277 V_326 ;
struct V_327 * V_328 = & V_84 -> V_329 ;
T_1 V_330 ;
int V_9 = 0 ;
int V_331 = 0 ;
F_173 ( & V_326 ) ;
F_257 ( & V_84 -> V_332 ) ;
F_258 ( & V_328 -> V_333 ) ;
V_330 = V_4 -> V_8 -> V_334 ;
F_172 (em, n, &tree->modified_extents, list) {
F_170 ( & V_294 -> V_25 ) ;
if ( ++ V_331 > 32768 ) {
F_170 ( & V_328 -> V_335 ) ;
V_9 = - V_336 ;
goto V_337;
}
if ( V_294 -> V_253 <= V_330 )
continue;
F_259 ( & V_294 -> V_338 ) ;
F_5 ( V_339 , & V_294 -> V_263 ) ;
F_10 ( & V_294 -> V_25 , & V_326 ) ;
V_331 ++ ;
}
F_260 ( NULL , & V_326 , F_237 ) ;
F_261 ( V_84 , V_295 , V_36 , V_230 ) ;
V_9 = F_242 ( V_84 -> V_138 . V_311 ) ;
if ( V_9 )
V_6 -> V_321 = V_9 ;
V_337:
while ( ! F_73 ( & V_326 ) ) {
V_294 = F_74 ( V_326 . V_105 , struct V_291 , V_25 ) ;
F_170 ( & V_294 -> V_25 ) ;
if ( V_9 ) {
F_262 ( V_328 , V_294 ) ;
F_263 ( V_294 ) ;
continue;
}
F_264 ( & V_328 -> V_333 ) ;
V_9 = F_244 ( V_2 , V_84 , V_4 , V_294 , V_41 , V_295 ,
V_6 ) ;
F_258 ( & V_328 -> V_333 ) ;
F_262 ( V_328 , V_294 ) ;
F_263 ( V_294 ) ;
}
F_143 ( ! F_73 ( & V_326 ) ) ;
F_264 ( & V_328 -> V_333 ) ;
F_265 ( & V_84 -> V_332 ) ;
F_31 ( V_41 ) ;
return V_9 ;
}
static int F_266 ( struct V_3 * log , struct V_108 * V_84 ,
struct V_40 * V_41 , T_1 * V_340 )
{
struct V_43 V_44 ;
int V_9 ;
V_44 . V_54 = F_61 ( V_84 ) ;
V_44 . type = V_52 ;
V_44 . V_82 = 0 ;
V_9 = F_30 ( NULL , log , & V_44 , V_41 , 0 , 0 ) ;
if ( V_9 < 0 ) {
return V_9 ;
} else if ( V_9 > 0 ) {
* V_340 = 0 ;
} else {
struct V_64 * V_65 ;
V_65 = F_35 ( V_41 -> V_59 [ 0 ] , V_41 -> V_60 [ 0 ] ,
struct V_64 ) ;
* V_340 = F_45 ( V_41 -> V_59 [ 0 ] , V_65 ) ;
}
F_31 ( V_41 ) ;
return 0 ;
}
static int F_267 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_108 * V_84 ,
struct V_40 * V_41 ,
struct V_40 * V_239 )
{
int V_9 ;
struct V_43 V_44 ;
const T_1 V_147 = F_61 ( V_84 ) ;
int V_341 = 0 ;
int V_250 = 0 ;
V_44 . V_54 = V_147 ;
V_44 . type = V_179 ;
V_44 . V_82 = 0 ;
V_9 = F_30 ( NULL , V_4 , & V_44 , V_41 , 0 , 0 ) ;
if ( V_9 < 0 )
return V_9 ;
while ( true ) {
int V_42 = V_41 -> V_60 [ 0 ] ;
struct V_29 * V_94 = V_41 -> V_59 [ 0 ] ;
int V_174 = F_133 ( V_94 ) ;
if ( V_42 >= V_174 ) {
if ( V_341 > 0 ) {
T_1 V_265 = 0 ;
V_9 = F_230 ( V_2 , V_84 , V_239 , V_41 ,
& V_265 , V_250 ,
V_341 , 1 , 0 ) ;
ASSERT ( V_9 <= 0 ) ;
if ( V_9 < 0 )
return V_9 ;
V_341 = 0 ;
}
V_9 = F_134 ( V_4 , V_41 ) ;
if ( V_9 < 0 )
return V_9 ;
else if ( V_9 > 0 )
break;
continue;
}
F_116 ( V_94 , & V_44 , V_42 ) ;
if ( V_44 . V_54 != V_147 || V_44 . type != V_179 )
break;
if ( V_341 == 0 )
V_250 = V_42 ;
V_341 ++ ;
V_41 -> V_60 [ 0 ] ++ ;
F_154 () ;
}
if ( V_341 > 0 ) {
T_1 V_265 = 0 ;
V_9 = F_230 ( V_2 , V_84 , V_239 , V_41 ,
& V_265 , V_250 ,
V_341 , 1 , 0 ) ;
ASSERT ( V_9 <= 0 ) ;
if ( V_9 < 0 )
return V_9 ;
}
return 0 ;
}
static int F_268 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_108 * V_84 ,
struct V_40 * V_41 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
int V_9 ;
struct V_43 V_44 ;
T_1 V_342 ;
T_1 V_343 ;
struct V_29 * V_94 ;
struct V_3 * log = V_4 -> V_11 ;
const T_1 V_147 = F_61 ( V_84 ) ;
const T_1 V_165 = F_269 ( & V_84 -> V_138 ) ;
if ( ! F_19 ( V_8 , V_97 ) )
return 0 ;
V_44 . V_54 = V_147 ;
V_44 . type = V_197 ;
V_44 . V_82 = ( T_1 ) - 1 ;
V_9 = F_30 ( NULL , V_4 , & V_44 , V_41 , 0 , 0 ) ;
ASSERT ( V_9 != 0 ) ;
if ( V_9 < 0 )
return V_9 ;
ASSERT ( V_41 -> V_60 [ 0 ] > 0 ) ;
V_41 -> V_60 [ 0 ] -- ;
V_94 = V_41 -> V_59 [ 0 ] ;
F_116 ( V_94 , & V_44 , V_41 -> V_60 [ 0 ] ) ;
if ( V_44 . V_54 != V_147 || V_44 . type != V_197 ) {
V_342 = 0 ;
V_343 = V_165 ;
} else {
struct V_83 * V_271 ;
T_1 V_37 ;
if ( V_44 . V_82 >= V_165 )
return 0 ;
V_271 = F_35 ( V_94 , V_41 -> V_60 [ 0 ] ,
struct V_83 ) ;
if ( F_53 ( V_94 , V_271 ) ==
V_88 ) {
V_37 = F_56 ( V_94 ,
V_41 -> V_60 [ 0 ] ,
V_271 ) ;
ASSERT ( V_37 == V_165 ) ;
return 0 ;
}
V_37 = F_54 ( V_94 , V_271 ) ;
if ( V_44 . V_82 + V_37 > V_165 )
return 0 ;
V_342 = V_44 . V_82 + V_37 ;
V_343 = V_165 - V_342 ;
}
F_31 ( V_41 ) ;
if ( V_343 == 0 )
return 0 ;
V_343 = F_58 ( V_343 , V_8 -> V_89 ) ;
V_9 = F_236 ( V_2 , log , V_147 , V_342 , 0 , 0 ,
V_343 , 0 , V_343 , 0 , 0 , 0 ) ;
return V_9 ;
}
static int F_270 ( struct V_29 * V_30 ,
const int V_42 ,
const struct V_43 * V_44 ,
struct V_108 * V_84 ,
T_1 * V_344 )
{
int V_9 ;
struct V_40 * V_345 ;
char * V_112 = NULL ;
T_3 V_113 = 0 ;
T_3 V_45 = F_28 ( V_30 , V_42 ) ;
T_3 V_139 = 0 ;
unsigned long V_121 = F_29 ( V_30 , V_42 ) ;
V_345 = F_92 () ;
if ( ! V_345 )
return - V_63 ;
V_345 -> V_346 = 1 ;
V_345 -> V_347 = 1 ;
while ( V_139 < V_45 ) {
T_1 V_200 ;
T_3 V_348 ;
T_3 V_184 ;
unsigned long V_123 ;
struct V_110 * V_111 ;
if ( V_44 -> type == V_136 ) {
struct V_119 * V_349 ;
V_349 = (struct V_119 * ) ( V_121 + V_139 ) ;
V_200 = V_44 -> V_82 ;
V_348 = F_94 ( V_30 , V_349 ) ;
V_123 = ( unsigned long ) ( V_349 + 1 ) ;
V_184 = sizeof( * V_349 ) + V_348 ;
} else {
struct V_133 * V_134 ;
V_134 = (struct V_133 * ) ( V_121 +
V_139 ) ;
V_200 = F_102 ( V_30 , V_134 ) ;
V_348 = F_101 ( V_30 , V_134 ) ;
V_123 = ( unsigned long ) & V_134 -> V_112 ;
V_184 = sizeof( * V_134 ) + V_348 ;
}
V_9 = F_105 ( V_30 , V_42 , V_123 ,
V_348 ) ;
if ( ! V_9 ) {
V_9 = - V_90 ;
goto V_13;
}
if ( V_348 > V_113 ) {
char * V_350 ;
V_350 = F_271 ( V_112 , V_348 , V_62 ) ;
if ( ! V_350 ) {
V_9 = - V_63 ;
goto V_13;
}
V_113 = V_348 ;
V_112 = V_350 ;
}
F_34 ( V_30 , V_112 , V_123 , V_348 ) ;
V_111 = F_90 ( NULL , V_84 -> V_4 , V_345 ,
V_200 , V_112 , V_348 , 0 ) ;
if ( V_111 && ! F_89 ( V_111 ) ) {
struct V_43 V_168 ;
F_82 ( V_345 -> V_59 [ 0 ] ,
V_111 , & V_168 ) ;
if ( V_168 . type == V_52 ) {
V_9 = 1 ;
* V_344 = V_168 . V_54 ;
} else {
V_9 = - V_12 ;
}
goto V_13;
} else if ( F_89 ( V_111 ) ) {
V_9 = F_136 ( V_111 ) ;
goto V_13;
}
F_31 ( V_345 ) ;
V_139 += V_184 ;
}
V_9 = 0 ;
V_13:
F_96 ( V_345 ) ;
F_33 ( V_112 ) ;
return V_9 ;
}
static int F_272 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_108 * V_84 ,
int V_267 ,
const T_6 V_36 ,
const T_6 V_230 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
struct V_40 * V_41 ;
struct V_40 * V_239 ;
struct V_43 V_242 ;
struct V_43 V_248 ;
struct V_3 * log = V_4 -> V_11 ;
struct V_29 * V_243 = NULL ;
F_67 ( V_295 ) ;
T_1 V_265 = 0 ;
int V_231 = 0 ;
int V_9 ;
int V_174 ;
int V_351 = 0 ;
int V_341 ;
bool V_352 = false ;
T_1 V_147 = F_61 ( V_84 ) ;
struct V_327 * V_353 = & V_84 -> V_329 ;
T_1 V_252 = 0 ;
bool V_354 = true ;
V_41 = F_92 () ;
if ( ! V_41 )
return - V_63 ;
V_239 = F_92 () ;
if ( ! V_239 ) {
F_96 ( V_41 ) ;
return - V_63 ;
}
V_242 . V_54 = V_147 ;
V_242 . type = V_52 ;
V_242 . V_82 = 0 ;
V_248 . V_54 = V_147 ;
if ( F_39 ( V_84 -> V_138 . V_152 ) ||
( ! F_177 ( V_355 ,
& V_84 -> V_356 ) &&
V_267 >= V_282 ) )
V_248 . type = V_179 ;
else
V_248 . type = ( T_4 ) - 1 ;
V_248 . V_82 = ( T_1 ) - 1 ;
if ( F_39 ( V_84 -> V_138 . V_152 ) ||
V_84 -> V_253 > V_8 -> V_334 )
V_9 = F_273 ( V_2 , V_84 ) ;
else
V_9 = F_274 ( V_84 ) ;
if ( V_9 ) {
F_96 ( V_41 ) ;
F_96 ( V_239 ) ;
return V_9 ;
}
if ( V_267 == V_357 ) {
V_267 = V_282 ;
F_275 ( & V_84 -> V_10 , V_358 ) ;
} else {
F_2 ( & V_84 -> V_10 ) ;
}
if ( F_39 ( V_84 -> V_138 . V_152 ) ) {
int V_249 = V_190 ;
if ( V_267 == V_282 )
V_249 = V_179 ;
V_9 = F_208 ( V_2 , log , V_41 , V_147 , V_249 ) ;
} else {
if ( V_267 == V_282 ) {
V_231 = F_266 ( log , V_84 , V_41 , & V_252 ) ;
if ( V_231 )
goto V_235;
}
if ( F_177 ( V_355 ,
& V_84 -> V_356 ) ) {
if ( V_267 == V_282 ) {
V_248 . type = V_179 ;
V_9 = F_208 ( V_2 , log , V_41 , V_147 ,
V_248 . type ) ;
} else {
F_4 ( V_355 ,
& V_84 -> V_356 ) ;
F_4 ( V_359 ,
& V_84 -> V_356 ) ;
while( 1 ) {
V_9 = F_276 ( V_2 ,
log , & V_84 -> V_138 , 0 , 0 ) ;
if ( V_9 != - V_12 )
break;
}
}
} else if ( F_277 ( V_359 ,
& V_84 -> V_356 ) ||
V_267 == V_282 ) {
if ( V_267 == V_360 )
V_352 = true ;
V_248 . type = V_179 ;
V_9 = F_208 ( V_2 , log , V_41 , V_147 ,
V_248 . type ) ;
} else {
if ( V_267 == V_360 )
V_352 = true ;
goto V_361;
}
}
if ( V_9 ) {
V_231 = V_9 ;
goto V_235;
}
while ( 1 ) {
V_341 = 0 ;
V_9 = F_203 ( V_4 , & V_242 ,
V_41 , V_2 -> V_79 ) ;
if ( V_9 < 0 ) {
V_231 = V_9 ;
goto V_235;
}
if ( V_9 != 0 )
break;
V_135:
if ( V_242 . V_54 != V_147 )
break;
if ( V_242 . type > V_248 . type )
break;
if ( V_242 . type == V_52 )
V_354 = false ;
if ( ( V_242 . type == V_136 ||
V_242 . type == V_125 ) &&
V_84 -> V_253 == V_2 -> V_79 ) {
T_1 V_344 = 0 ;
V_9 = F_270 ( V_41 -> V_59 [ 0 ] ,
V_41 -> V_60 [ 0 ] , & V_242 , V_84 ,
& V_344 ) ;
if ( V_9 < 0 ) {
V_231 = V_9 ;
goto V_235;
} else if ( V_9 > 0 && V_6 &&
V_344 != F_61 ( F_62 ( V_6 -> V_84 ) ) ) {
struct V_43 V_362 ;
struct V_84 * V_363 ;
if ( V_341 > 0 ) {
V_341 ++ ;
} else {
V_341 = 1 ;
V_351 = V_41 -> V_60 [ 0 ] ;
}
V_9 = F_230 ( V_2 , V_84 , V_239 , V_41 ,
& V_265 , V_351 ,
V_341 , V_267 ,
V_252 ) ;
if ( V_9 < 0 ) {
V_231 = V_9 ;
goto V_235;
}
V_341 = 0 ;
F_31 ( V_41 ) ;
V_362 . V_54 = V_344 ;
V_362 . type = V_52 ;
V_362 . V_82 = 0 ;
V_363 = F_278 ( V_8 -> V_364 ,
& V_362 , V_4 ,
NULL ) ;
if ( F_89 ( V_363 ) &&
F_136 ( V_363 ) == - V_27 ) {
goto V_365;
} else if ( F_89 ( V_363 ) ) {
V_231 = F_136 ( V_363 ) ;
goto V_235;
}
V_231 = F_272 ( V_2 , V_4 ,
F_62 ( V_363 ) ,
V_357 , 0 , V_366 ,
V_6 ) ;
F_80 ( V_363 ) ;
if ( V_231 )
goto V_235;
else
goto V_365;
}
}
if ( V_242 . type == V_179 ) {
if ( V_341 == 0 )
goto V_367;
V_9 = F_230 ( V_2 , V_84 , V_239 , V_41 ,
& V_265 , V_351 ,
V_341 , V_267 , V_252 ) ;
if ( V_9 < 0 ) {
V_231 = V_9 ;
goto V_235;
}
V_341 = 0 ;
if ( V_9 ) {
F_31 ( V_41 ) ;
continue;
}
goto V_367;
}
V_243 = V_41 -> V_59 [ 0 ] ;
if ( V_341 && V_351 + V_341 == V_41 -> V_60 [ 0 ] ) {
V_341 ++ ;
goto V_367;
} else if ( ! V_341 ) {
V_351 = V_41 -> V_60 [ 0 ] ;
V_341 = 1 ;
goto V_367;
}
V_9 = F_230 ( V_2 , V_84 , V_239 , V_41 , & V_265 ,
V_351 , V_341 , V_267 ,
V_252 ) ;
if ( V_9 < 0 ) {
V_231 = V_9 ;
goto V_235;
}
if ( V_9 ) {
V_341 = 0 ;
F_31 ( V_41 ) ;
continue;
}
V_341 = 1 ;
V_351 = V_41 -> V_60 [ 0 ] ;
V_367:
V_174 = F_133 ( V_41 -> V_59 [ 0 ] ) ;
V_41 -> V_60 [ 0 ] ++ ;
if ( V_41 -> V_60 [ 0 ] < V_174 ) {
F_116 ( V_41 -> V_59 [ 0 ] , & V_242 ,
V_41 -> V_60 [ 0 ] ) ;
goto V_135;
}
if ( V_341 ) {
V_9 = F_230 ( V_2 , V_84 , V_239 , V_41 ,
& V_265 , V_351 ,
V_341 , V_267 , V_252 ) ;
if ( V_9 < 0 ) {
V_231 = V_9 ;
goto V_235;
}
V_9 = 0 ;
V_341 = 0 ;
}
F_31 ( V_41 ) ;
V_365:
if ( V_242 . V_82 < ( T_1 ) - 1 ) {
V_242 . V_82 ++ ;
} else if ( V_242 . type < V_248 . type ) {
V_242 . type ++ ;
V_242 . V_82 = 0 ;
} else {
break;
}
}
if ( V_341 ) {
V_9 = F_230 ( V_2 , V_84 , V_239 , V_41 , & V_265 ,
V_351 , V_341 , V_267 ,
V_252 ) ;
if ( V_9 < 0 ) {
V_231 = V_9 ;
goto V_235;
}
V_9 = 0 ;
V_341 = 0 ;
}
F_31 ( V_41 ) ;
F_31 ( V_239 ) ;
V_231 = F_267 ( V_2 , V_4 , V_84 , V_41 , V_239 ) ;
if ( V_231 )
goto V_235;
if ( V_248 . type >= V_197 && ! V_352 ) {
F_31 ( V_41 ) ;
F_31 ( V_239 ) ;
V_231 = F_268 ( V_2 , V_4 , V_84 , V_41 ) ;
if ( V_231 )
goto V_235;
}
V_361:
F_31 ( V_41 ) ;
F_31 ( V_239 ) ;
if ( V_354 ) {
V_231 = F_229 ( V_2 , log , V_239 , V_84 ) ;
if ( V_231 )
goto V_235;
}
if ( V_352 ) {
V_9 = F_256 ( V_2 , V_4 , V_84 , V_239 ,
& V_295 , V_6 , V_36 , V_230 ) ;
if ( V_9 ) {
V_231 = V_9 ;
goto V_235;
}
} else if ( V_267 == V_360 ) {
struct V_291 * V_294 , * V_325 ;
F_258 ( & V_353 -> V_333 ) ;
F_172 (em, n, &em_tree->modified_extents,
list) {
const T_1 V_368 = V_294 -> V_299 + V_294 -> V_300 - 1 ;
if ( V_294 -> V_299 >= V_36 && V_368 <= V_230 )
F_170 ( & V_294 -> V_25 ) ;
}
F_264 ( & V_353 -> V_333 ) ;
}
if ( V_267 == V_360 && F_39 ( V_84 -> V_138 . V_152 ) ) {
V_9 = F_207 ( V_2 , V_4 , V_84 , V_41 , V_239 ,
V_6 ) ;
if ( V_9 ) {
V_231 = V_9 ;
goto V_235;
}
}
F_279 ( & V_84 -> V_333 ) ;
V_84 -> V_234 = V_2 -> V_79 ;
V_84 -> V_229 = V_84 -> V_369 ;
F_280 ( & V_84 -> V_333 ) ;
V_235:
if ( F_281 ( V_231 ) )
F_282 ( & V_295 ) ;
else
F_283 ( & V_295 , log ) ;
F_7 ( & V_84 -> V_10 ) ;
F_96 ( V_41 ) ;
F_96 ( V_239 ) ;
return V_231 ;
}
static bool F_284 ( struct V_1 * V_2 ,
struct V_108 * V_84 )
{
struct V_7 * V_8 = V_84 -> V_4 -> V_8 ;
bool V_9 = false ;
F_2 ( & V_84 -> V_10 ) ;
if ( V_84 -> V_370 > V_8 -> V_334 ) {
F_184 ( V_8 , V_2 ) ;
V_9 = true ;
}
F_7 ( & V_84 -> V_10 ) ;
return V_9 ;
}
static T_2 int F_285 ( struct V_1 * V_2 ,
struct V_108 * V_84 ,
struct V_371 * V_200 ,
struct V_372 * V_364 ,
T_1 V_373 )
{
int V_9 = 0 ;
struct V_371 * V_374 = NULL ;
struct V_108 * V_375 = V_84 ;
if ( F_46 ( V_84 -> V_138 . V_152 ) &&
V_84 -> V_253 <= V_373 &&
V_84 -> V_370 <= V_373 )
goto V_13;
if ( ! F_39 ( V_84 -> V_138 . V_152 ) ) {
if ( ! V_200 || F_286 ( V_200 ) || V_364 != V_200 -> V_376 )
goto V_13;
V_84 = F_62 ( F_287 ( V_200 ) ) ;
}
while ( 1 ) {
if ( V_84 != V_375 )
V_84 -> V_234 = V_2 -> V_79 ;
F_12 () ;
if ( F_284 ( V_2 , V_84 ) ) {
V_9 = 1 ;
break;
}
if ( ! V_200 || F_286 ( V_200 ) || V_364 != V_200 -> V_376 )
break;
if ( F_288 ( V_200 ) ) {
V_84 = F_62 ( F_287 ( V_200 ) ) ;
if ( F_284 ( V_2 , V_84 ) )
V_9 = 1 ;
break;
}
V_200 = F_289 ( V_200 ) ;
F_290 ( V_374 ) ;
V_374 = V_200 ;
V_84 = F_62 ( F_287 ( V_200 ) ) ;
}
F_290 ( V_374 ) ;
V_13:
return V_9 ;
}
static int F_291 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_108 * V_377 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
struct V_3 * log = V_4 -> V_11 ;
struct V_40 * V_41 ;
F_67 ( V_378 ) ;
struct V_379 * V_380 ;
int V_9 = 0 ;
V_41 = F_92 () ;
if ( ! V_41 )
return - V_63 ;
V_380 = F_32 ( sizeof( * V_380 ) , V_62 ) ;
if ( ! V_380 ) {
F_96 ( V_41 ) ;
return - V_63 ;
}
V_380 -> V_147 = F_61 ( V_377 ) ;
F_10 ( & V_380 -> V_25 , & V_378 ) ;
while ( ! F_73 ( & V_378 ) ) {
struct V_29 * V_94 ;
struct V_43 V_242 ;
int V_174 ;
int V_178 ;
V_380 = F_292 ( & V_378 , struct V_379 ,
V_25 ) ;
if ( V_9 )
goto V_381;
V_242 . V_54 = V_380 -> V_147 ;
V_242 . type = V_163 ;
V_242 . V_82 = 0 ;
V_135:
F_31 ( V_41 ) ;
V_9 = F_203 ( log , & V_242 , V_41 , V_2 -> V_79 ) ;
if ( V_9 < 0 ) {
goto V_381;
} else if ( V_9 > 0 ) {
V_9 = 0 ;
goto V_381;
}
V_180:
V_94 = V_41 -> V_59 [ 0 ] ;
V_174 = F_133 ( V_94 ) ;
for ( V_178 = V_41 -> V_60 [ 0 ] ; V_178 < V_174 ; V_178 ++ ) {
struct V_110 * V_111 ;
struct V_43 V_168 ;
struct V_84 * V_382 ;
struct V_379 * V_383 ;
int V_384 = V_282 ;
int type ;
F_116 ( V_94 , & V_242 , V_178 ) ;
if ( V_242 . V_54 != V_380 -> V_147 ||
V_242 . type != V_163 )
goto V_381;
V_111 = F_35 ( V_94 , V_178 , struct V_110 ) ;
type = F_126 ( V_94 , V_111 ) ;
if ( F_206 ( V_94 , V_111 ) < V_2 -> V_79 &&
type != V_167 )
continue;
F_82 ( V_94 , V_111 , & V_168 ) ;
if ( V_168 . type == V_246 )
continue;
F_31 ( V_41 ) ;
V_382 = F_278 ( V_8 -> V_364 , & V_168 , V_4 , NULL ) ;
if ( F_89 ( V_382 ) ) {
V_9 = F_136 ( V_382 ) ;
goto V_381;
}
if ( F_293 ( F_62 ( V_382 ) , V_2 -> V_79 ) ) {
F_80 ( V_382 ) ;
break;
}
V_6 -> V_247 = false ;
if ( type == V_167 || type == V_385 )
V_384 = V_360 ;
V_9 = F_272 ( V_2 , V_4 , F_62 ( V_382 ) ,
V_384 , 0 , V_366 , V_6 ) ;
if ( ! V_9 &&
F_284 ( V_2 , F_62 ( V_382 ) ) )
V_9 = 1 ;
F_80 ( V_382 ) ;
if ( V_9 )
goto V_381;
if ( V_6 -> V_247 ) {
V_383 = F_32 ( sizeof( * V_383 ) ,
V_62 ) ;
if ( ! V_383 ) {
V_9 = - V_63 ;
goto V_381;
}
V_383 -> V_147 = V_168 . V_54 ;
F_10 ( & V_383 -> V_25 , & V_378 ) ;
}
break;
}
if ( V_178 == V_174 ) {
V_9 = F_134 ( log , V_41 ) ;
if ( V_9 < 0 ) {
goto V_381;
} else if ( V_9 > 0 ) {
V_9 = 0 ;
goto V_381;
}
goto V_180;
}
if ( V_242 . V_82 < ( T_1 ) - 1 ) {
V_242 . V_82 ++ ;
goto V_135;
}
V_381:
F_77 ( & V_380 -> V_25 ) ;
F_33 ( V_380 ) ;
}
F_96 ( V_41 ) ;
return V_9 ;
}
static int F_294 ( struct V_1 * V_2 ,
struct V_108 * V_84 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 = F_231 ( V_84 -> V_138 . V_268 ) ;
int V_9 ;
struct V_40 * V_41 ;
struct V_43 V_44 ;
struct V_3 * V_4 = V_84 -> V_4 ;
const T_1 V_147 = F_61 ( V_84 ) ;
V_41 = F_92 () ;
if ( ! V_41 )
return - V_63 ;
V_41 -> V_347 = 1 ;
V_41 -> V_346 = 1 ;
V_44 . V_54 = V_147 ;
V_44 . type = V_136 ;
V_44 . V_82 = 0 ;
V_9 = F_30 ( NULL , V_4 , & V_44 , V_41 , 0 , 0 ) ;
if ( V_9 < 0 )
goto V_13;
while ( true ) {
struct V_29 * V_94 = V_41 -> V_59 [ 0 ] ;
int V_42 = V_41 -> V_60 [ 0 ] ;
T_3 V_139 = 0 ;
T_3 V_45 ;
unsigned long V_121 ;
if ( V_42 >= F_133 ( V_94 ) ) {
V_9 = F_134 ( V_4 , V_41 ) ;
if ( V_9 < 0 )
goto V_13;
else if ( V_9 > 0 )
break;
continue;
}
F_116 ( V_94 , & V_44 , V_42 ) ;
if ( V_44 . V_54 != V_147 || V_44 . type > V_125 )
break;
V_45 = F_28 ( V_94 , V_42 ) ;
V_121 = F_29 ( V_94 , V_42 ) ;
while ( V_139 < V_45 ) {
struct V_43 V_362 ;
struct V_84 * V_386 ;
V_362 . type = V_52 ;
V_362 . V_82 = 0 ;
if ( V_44 . type == V_125 ) {
struct V_133 * V_134 ;
V_134 = (struct V_133 * )
( V_121 + V_139 ) ;
V_362 . V_54 = F_102 (
V_94 , V_134 ) ;
V_139 += sizeof( * V_134 ) ;
V_139 += F_101 ( V_94 ,
V_134 ) ;
} else {
V_362 . V_54 = V_44 . V_82 ;
V_139 = V_45 ;
}
V_386 = F_278 ( V_8 -> V_364 , & V_362 ,
V_4 , NULL ) ;
if ( F_89 ( V_386 ) )
continue;
if ( V_6 )
V_6 -> V_247 = false ;
V_9 = F_272 ( V_2 , V_4 , F_62 ( V_386 ) ,
V_360 , 0 , V_366 , V_6 ) ;
if ( ! V_9 &&
F_284 ( V_2 , F_62 ( V_386 ) ) )
V_9 = 1 ;
if ( ! V_9 && V_6 && V_6 -> V_247 )
V_9 = F_291 ( V_2 , V_4 ,
F_62 ( V_386 ) , V_6 ) ;
F_80 ( V_386 ) ;
if ( V_9 )
goto V_13;
}
V_41 -> V_60 [ 0 ] ++ ;
}
V_9 = 0 ;
V_13:
F_96 ( V_41 ) ;
return V_9 ;
}
static int F_295 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_108 * V_84 ,
struct V_371 * V_200 ,
const T_6 V_36 ,
const T_6 V_230 ,
int V_387 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
int V_267 = V_387 ? V_282 : V_360 ;
struct V_372 * V_364 ;
struct V_371 * V_374 = NULL ;
int V_9 = 0 ;
T_1 V_373 = V_8 -> V_334 ;
bool V_388 = false ;
struct V_108 * V_375 = V_84 ;
V_364 = V_84 -> V_138 . V_268 ;
if ( F_176 ( V_8 , V_389 ) ) {
V_9 = 1 ;
goto V_390;
}
if ( V_8 -> V_391 >
V_8 -> V_334 ) {
V_9 = 1 ;
goto V_390;
}
if ( V_4 != V_84 -> V_4 || F_296 ( & V_4 -> V_208 ) == 0 ) {
V_9 = 1 ;
goto V_390;
}
V_9 = F_285 ( V_2 , V_84 , V_200 , V_364 ,
V_373 ) ;
if ( V_9 )
goto V_390;
if ( F_293 ( V_84 , V_2 -> V_79 ) ) {
V_9 = V_392 ;
goto V_390;
}
V_9 = F_1 ( V_2 , V_4 , V_6 ) ;
if ( V_9 )
goto V_390;
V_9 = F_272 ( V_2 , V_4 , V_84 , V_267 , V_36 , V_230 , V_6 ) ;
if ( V_9 )
goto V_393;
if ( F_46 ( V_84 -> V_138 . V_152 ) &&
V_84 -> V_253 <= V_373 &&
V_84 -> V_370 <= V_373 ) {
V_9 = 0 ;
goto V_393;
}
if ( F_39 ( V_84 -> V_138 . V_152 ) && V_6 && V_6 -> V_247 )
V_388 = true ;
if ( V_84 -> V_370 > V_373 ) {
V_9 = F_294 ( V_2 , V_375 , V_6 ) ;
if ( V_9 )
goto V_393;
}
while ( 1 ) {
if ( ! V_200 || F_286 ( V_200 ) || V_364 != V_200 -> V_376 )
break;
V_84 = F_62 ( F_287 ( V_200 ) ) ;
if ( V_4 != V_84 -> V_4 )
break;
if ( V_84 -> V_253 > V_373 ) {
V_9 = F_272 ( V_2 , V_4 , V_84 ,
V_282 , 0 , V_366 , V_6 ) ;
if ( V_9 )
goto V_393;
}
if ( F_288 ( V_200 ) )
break;
V_200 = F_289 ( V_200 ) ;
F_290 ( V_374 ) ;
V_374 = V_200 ;
}
if ( V_388 )
V_9 = F_291 ( V_2 , V_4 , V_375 , V_6 ) ;
else
V_9 = 0 ;
V_393:
F_290 ( V_374 ) ;
if ( V_9 < 0 ) {
F_184 ( V_8 , V_2 ) ;
V_9 = 1 ;
}
if ( V_9 )
F_169 ( V_4 , V_6 ) ;
F_14 ( V_4 ) ;
V_390:
return V_9 ;
}
int F_297 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_371 * V_371 ,
const T_6 V_36 ,
const T_6 V_230 ,
struct V_5 * V_6 )
{
struct V_371 * V_200 = F_289 ( V_371 ) ;
int V_9 ;
V_9 = F_295 ( V_2 , V_4 , F_62 ( F_287 ( V_371 ) ) ,
V_200 , V_36 , V_230 , 0 , V_6 ) ;
F_290 ( V_200 ) ;
return V_9 ;
}
int F_298 ( struct V_3 * V_20 )
{
int V_9 ;
struct V_40 * V_41 ;
struct V_1 * V_2 ;
struct V_43 V_44 ;
struct V_43 V_156 ;
struct V_43 V_394 ;
struct V_3 * log ;
struct V_7 * V_8 = V_20 -> V_8 ;
struct V_31 V_32 = {
. V_204 = F_18 ,
. V_193 = 0 ,
} ;
V_41 = F_92 () ;
if ( ! V_41 )
return - V_63 ;
F_5 ( V_395 , & V_8 -> V_263 ) ;
V_2 = F_299 ( V_8 -> V_396 , 0 ) ;
if ( F_89 ( V_2 ) ) {
V_9 = F_136 ( V_2 ) ;
goto error;
}
V_32 . V_2 = V_2 ;
V_32 . V_35 = 1 ;
V_9 = F_157 ( V_2 , V_20 , & V_32 ) ;
if ( V_9 ) {
F_300 ( V_8 , V_9 ,
L_1 ) ;
goto error;
}
V_135:
V_44 . V_54 = V_55 ;
V_44 . V_82 = ( T_1 ) - 1 ;
V_44 . type = V_246 ;
while ( 1 ) {
V_9 = F_30 ( NULL , V_20 , & V_44 , V_41 , 0 , 0 ) ;
if ( V_9 < 0 ) {
F_300 ( V_8 , V_9 ,
L_2 ) ;
goto error;
}
if ( V_9 > 0 ) {
if ( V_41 -> V_60 [ 0 ] == 0 )
break;
V_41 -> V_60 [ 0 ] -- ;
}
F_116 ( V_41 -> V_59 [ 0 ] , & V_156 ,
V_41 -> V_60 [ 0 ] ) ;
F_31 ( V_41 ) ;
if ( V_156 . V_54 != V_55 )
break;
log = F_301 ( V_20 , & V_156 ) ;
if ( F_89 ( log ) ) {
V_9 = F_136 ( log ) ;
F_300 ( V_8 , V_9 ,
L_3 ) ;
goto error;
}
V_394 . V_54 = V_156 . V_82 ;
V_394 . type = V_246 ;
V_394 . V_82 = ( T_1 ) - 1 ;
V_32 . V_191 = F_302 ( V_8 , & V_394 ) ;
if ( F_89 ( V_32 . V_191 ) ) {
V_9 = F_136 ( V_32 . V_191 ) ;
F_148 ( log -> V_205 ) ;
F_148 ( log -> V_397 ) ;
F_33 ( log ) ;
F_300 ( V_8 , V_9 ,
L_4 ) ;
goto error;
}
V_32 . V_191 -> V_11 = log ;
F_303 ( V_2 , V_32 . V_191 ) ;
V_9 = F_157 ( V_2 , log , & V_32 ) ;
if ( ! V_9 && V_32 . V_193 == V_196 ) {
V_9 = F_120 ( V_2 , V_32 . V_191 ,
V_41 ) ;
}
V_44 . V_82 = V_156 . V_82 - 1 ;
V_32 . V_191 -> V_11 = NULL ;
F_148 ( log -> V_205 ) ;
F_148 ( log -> V_397 ) ;
F_33 ( log ) ;
if ( V_9 )
goto error;
if ( V_156 . V_82 == 0 )
break;
}
F_31 ( V_41 ) ;
if ( V_32 . V_35 ) {
V_32 . V_35 = 0 ;
V_32 . V_204 = F_141 ;
V_32 . V_193 = V_194 ;
goto V_135;
}
if ( V_32 . V_193 < V_196 ) {
V_32 . V_193 ++ ;
goto V_135;
}
F_96 ( V_41 ) ;
V_9 = F_304 ( V_2 ) ;
if ( V_9 )
return V_9 ;
F_148 ( V_20 -> V_205 ) ;
V_20 -> V_11 = NULL ;
F_4 ( V_395 , & V_8 -> V_263 ) ;
F_33 ( V_20 ) ;
return 0 ;
error:
if ( V_32 . V_2 )
F_305 ( V_32 . V_2 ) ;
F_96 ( V_41 ) ;
return V_9 ;
}
void F_306 ( struct V_1 * V_2 ,
struct V_108 * V_109 , struct V_108 * V_84 ,
int V_398 )
{
F_2 ( & V_84 -> V_10 ) ;
V_84 -> V_370 = V_2 -> V_79 ;
F_7 ( & V_84 -> V_10 ) ;
F_12 () ;
if ( V_109 -> V_234 == V_2 -> V_79 )
return;
if ( V_84 -> V_234 == V_2 -> V_79 )
return;
if ( V_398 )
goto V_399;
return;
V_399:
F_2 ( & V_109 -> V_10 ) ;
V_109 -> V_370 = V_2 -> V_79 ;
F_7 ( & V_109 -> V_10 ) ;
}
void F_307 ( struct V_1 * V_2 ,
struct V_108 * V_109 )
{
F_2 ( & V_109 -> V_10 ) ;
V_109 -> V_370 = V_2 -> V_79 ;
F_7 ( & V_109 -> V_10 ) ;
}
int F_308 ( struct V_1 * V_2 ,
struct V_108 * V_84 , struct V_108 * V_400 ,
struct V_371 * V_200 )
{
struct V_7 * V_8 = F_231 ( V_84 -> V_138 . V_268 ) ;
struct V_3 * V_4 = V_84 -> V_4 ;
if ( F_46 ( V_84 -> V_138 . V_152 ) )
V_84 -> V_370 = V_2 -> V_79 ;
if ( V_84 -> V_234 <= V_8 -> V_334 &&
( ! V_400 || V_400 -> V_234 <= V_8 -> V_334 ) )
return 0 ;
return F_295 ( V_2 , V_4 , V_84 , V_200 , 0 ,
V_366 , 1 , NULL ) ;
}
