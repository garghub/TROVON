static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
int V_7 = 0 ;
F_2 ( & V_4 -> V_8 ) ;
if ( V_4 -> V_9 ) {
if ( F_3 ( V_4 -> V_10 , V_2 ) ) {
V_7 = - V_11 ;
goto V_12;
}
if ( ! V_4 -> V_13 ) {
F_4 ( V_14 , & V_4 -> V_15 ) ;
V_4 -> V_13 = V_16 -> V_17 ;
} else if ( V_4 -> V_13 != V_16 -> V_17 ) {
F_5 ( V_14 , & V_4 -> V_15 ) ;
}
} else {
F_2 ( & V_4 -> V_10 -> V_18 ) ;
if ( ! V_4 -> V_10 -> V_19 )
V_7 = F_6 ( V_2 , V_4 -> V_10 ) ;
F_7 ( & V_4 -> V_10 -> V_18 ) ;
if ( V_7 )
goto V_12;
V_7 = F_8 ( V_2 , V_4 ) ;
if ( V_7 )
goto V_12;
F_4 ( V_14 , & V_4 -> V_15 ) ;
V_4 -> V_13 = V_16 -> V_17 ;
}
F_9 ( & V_4 -> V_20 ) ;
F_9 ( & V_4 -> V_21 ) ;
if ( V_6 ) {
int V_22 = V_4 -> V_23 % 2 ;
F_10 ( & V_6 -> V_24 , & V_4 -> V_25 [ V_22 ] ) ;
V_6 -> V_23 = V_4 -> V_23 ;
}
V_12:
F_7 ( & V_4 -> V_8 ) ;
return V_7 ;
}
static int F_11 ( struct V_3 * V_4 )
{
int V_7 = - V_26 ;
F_12 () ;
if ( ! V_4 -> V_9 )
return - V_26 ;
F_2 ( & V_4 -> V_8 ) ;
if ( V_4 -> V_9 ) {
V_7 = 0 ;
F_9 ( & V_4 -> V_21 ) ;
}
F_7 ( & V_4 -> V_8 ) ;
return V_7 ;
}
int F_13 ( struct V_3 * V_4 )
{
int V_7 = - V_26 ;
F_2 ( & V_4 -> V_8 ) ;
F_9 ( & V_4 -> V_21 ) ;
F_7 ( & V_4 -> V_8 ) ;
return V_7 ;
}
void F_14 ( struct V_3 * V_4 )
{
if ( F_15 ( & V_4 -> V_21 ) ) {
if ( F_16 ( & V_4 -> V_27 ) )
F_17 ( & V_4 -> V_27 ) ;
}
}
static int F_18 ( struct V_3 * log ,
struct V_28 * V_29 ,
struct V_30 * V_31 , T_1 V_32 )
{
int V_7 = 0 ;
if ( F_19 ( log -> V_10 , V_33 ) ) {
V_7 = F_20 ( V_29 , V_32 ) ;
if ( V_7 )
return V_7 ;
}
if ( V_31 -> V_34 )
V_7 = F_21 ( log -> V_10 -> V_35 ,
V_29 -> V_36 , V_29 -> V_37 ) ;
if ( ! V_7 && F_22 ( V_29 , V_32 , 0 ) ) {
if ( V_31 -> V_34 && F_23 ( V_29 ) == 0 )
V_7 = F_24 ( log , V_29 ) ;
if ( V_31 -> V_38 )
F_25 ( V_29 ) ;
if ( V_31 -> V_39 )
F_26 ( V_29 ) ;
}
return V_7 ;
}
static T_2 int F_27 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_40 * V_41 ,
struct V_28 * V_29 , int V_42 ,
struct V_43 * V_44 )
{
int V_7 ;
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
V_7 = F_30 ( NULL , V_4 , V_44 , V_41 , 0 , 0 ) ;
if ( V_7 < 0 )
return V_7 ;
if ( V_7 == 0 ) {
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
V_7 = memcmp ( V_57 , V_56 , V_45 ) ;
F_33 ( V_57 ) ;
F_33 ( V_56 ) ;
if ( V_7 == 0 ) {
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
V_41 -> V_68 = 1 ;
V_7 = F_41 ( V_2 , V_4 , V_41 ,
V_44 , V_45 ) ;
V_41 -> V_68 = 0 ;
if ( V_7 == - V_69 || V_7 == - V_70 ) {
T_3 V_71 ;
V_71 = F_28 ( V_41 -> V_59 [ 0 ] ,
V_41 -> V_60 [ 0 ] ) ;
if ( V_71 > V_45 )
F_42 ( V_4 , V_41 , V_45 , 1 ) ;
else if ( V_71 < V_45 )
F_43 ( V_4 , V_41 ,
V_45 - V_71 ) ;
} else if ( V_7 ) {
return V_7 ;
}
V_49 = F_29 ( V_41 -> V_59 [ 0 ] ,
V_41 -> V_60 [ 0 ] ) ;
if ( V_44 -> type == V_52 && V_7 == - V_69 ) {
struct V_64 * V_72 ;
struct V_64 * V_73 ;
V_72 = (struct V_64 * ) V_48 ;
V_73 = (struct V_64 * ) V_49 ;
if ( F_44 ( V_29 , V_72 ) == 0 ) {
struct V_28 * V_74 = V_41 -> V_59 [ 0 ] ;
const T_1 V_75 = F_45 ( V_29 , V_72 ) ;
if ( F_46 ( F_38 ( V_29 , V_72 ) ) &&
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
F_39 ( F_38 ( V_29 , V_72 ) ) &&
F_39 ( F_38 ( V_41 -> V_59 [ 0 ] , V_73 ) ) ) {
V_47 = 1 ;
V_46 = F_45 ( V_41 -> V_59 [ 0 ] ,
V_73 ) ;
}
}
F_49 ( V_41 -> V_59 [ 0 ] , V_29 , V_49 ,
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
struct V_28 * V_29 , int V_42 ,
struct V_43 * V_44 )
{
int V_80 ;
T_1 V_81 ;
T_1 V_36 = V_44 -> V_82 ;
T_1 V_66 = 0 ;
struct V_83 * V_65 ;
struct V_84 * V_84 = NULL ;
unsigned long V_85 ;
int V_7 = 0 ;
V_65 = F_35 ( V_29 , V_42 , struct V_83 ) ;
V_80 = F_53 ( V_29 , V_65 ) ;
if ( V_80 == V_86 ||
V_80 == V_87 ) {
V_66 = F_54 ( V_29 , V_65 ) ;
V_81 = V_36 + V_66 ;
if ( F_55 ( V_29 , V_65 ) == 0 )
V_66 = 0 ;
} else if ( V_80 == V_88 ) {
V_85 = F_56 ( V_29 , V_42 , V_65 ) ;
V_66 = F_57 ( V_29 , V_65 ) ;
V_81 = F_58 ( V_36 + V_85 , V_4 -> V_89 ) ;
} else {
V_7 = 0 ;
goto V_12;
}
V_84 = F_59 ( V_4 , V_44 -> V_54 ) ;
if ( ! V_84 ) {
V_7 = - V_90 ;
goto V_12;
}
V_7 = F_60 ( V_2 , V_4 , V_41 , F_61 ( V_84 ) ,
V_36 , 0 ) ;
if ( V_7 == 0 &&
( V_80 == V_86 ||
V_80 == V_87 ) ) {
struct V_83 V_91 ;
struct V_83 V_92 ;
struct V_83 * V_93 ;
struct V_28 * V_94 ;
V_94 = V_41 -> V_59 [ 0 ] ;
V_93 = F_35 ( V_94 , V_41 -> V_60 [ 0 ] ,
struct V_83 ) ;
F_34 ( V_29 , & V_91 , ( unsigned long ) V_65 ,
sizeof( V_91 ) ) ;
F_34 ( V_94 , & V_92 , ( unsigned long ) V_93 ,
sizeof( V_92 ) ) ;
if ( memcmp ( & V_91 , & V_92 , sizeof( V_91 ) ) == 0 ) {
F_31 ( V_41 ) ;
goto V_12;
}
}
F_31 ( V_41 ) ;
V_7 = F_62 ( V_2 , V_4 , V_84 , V_36 , V_81 , 1 ) ;
if ( V_7 )
goto V_12;
if ( V_80 == V_86 ||
V_80 == V_87 ) {
T_1 V_82 ;
unsigned long V_95 ;
struct V_43 V_96 ;
V_7 = F_41 ( V_2 , V_4 , V_41 , V_44 ,
sizeof( * V_65 ) ) ;
if ( V_7 )
goto V_12;
V_95 = F_29 ( V_41 -> V_59 [ 0 ] ,
V_41 -> V_60 [ 0 ] ) ;
F_49 ( V_41 -> V_59 [ 0 ] , V_29 , V_95 ,
( unsigned long ) V_65 , sizeof( * V_65 ) ) ;
V_96 . V_54 = F_55 ( V_29 , V_65 ) ;
V_96 . V_82 = F_63 ( V_29 , V_65 ) ;
V_96 . type = V_97 ;
V_82 = V_44 -> V_82 - F_64 ( V_29 , V_65 ) ;
V_7 = F_65 ( V_2 , V_4 -> V_10 ,
F_55 ( V_29 , V_65 ) ,
F_63 ( V_29 , V_65 ) ,
V_62 ) ;
if ( V_7 < 0 )
goto V_12;
if ( V_96 . V_54 > 0 ) {
T_1 V_98 ;
T_1 V_99 ;
F_66 ( V_100 ) ;
V_7 = F_67 ( V_4 , V_96 . V_54 ,
V_96 . V_82 ) ;
if ( V_7 == 0 ) {
V_7 = F_68 ( V_2 , V_4 ,
V_96 . V_54 , V_96 . V_82 ,
0 , V_4 -> V_53 . V_54 ,
V_44 -> V_54 , V_82 ) ;
if ( V_7 )
goto V_12;
} else {
V_7 = F_69 ( V_2 ,
V_4 , V_4 -> V_53 . V_54 ,
V_44 -> V_54 , V_82 , & V_96 ) ;
if ( V_7 )
goto V_12;
}
F_31 ( V_41 ) ;
if ( F_70 ( V_29 , V_65 ) ) {
V_98 = V_96 . V_54 ;
V_99 = V_98 + V_96 . V_82 ;
} else {
V_98 = V_96 . V_54 +
F_64 ( V_29 , V_65 ) ;
V_99 = V_98 +
F_54 ( V_29 , V_65 ) ;
}
V_7 = F_71 ( V_4 -> V_9 ,
V_98 , V_99 - 1 ,
& V_100 , 0 ) ;
if ( V_7 )
goto V_12;
while ( ! F_72 ( & V_100 ) ) {
struct V_101 * V_102 ;
V_102 = F_73 ( V_100 . V_103 ,
struct V_101 ,
V_24 ) ;
if ( ! V_7 )
V_7 = F_74 ( V_2 ,
V_4 -> V_10 -> V_104 ,
V_102 -> V_105 ,
V_102 -> V_37 ) ;
if ( ! V_7 )
V_7 = F_75 ( V_2 ,
V_4 -> V_10 -> V_104 ,
V_102 ) ;
F_76 ( & V_102 -> V_24 ) ;
F_33 ( V_102 ) ;
}
if ( V_7 )
goto V_12;
} else {
F_31 ( V_41 ) ;
}
} else if ( V_80 == V_88 ) {
V_7 = F_27 ( V_2 , V_4 , V_41 , V_29 , V_42 , V_44 ) ;
if ( V_7 )
goto V_12;
}
F_77 ( V_84 , V_66 ) ;
V_7 = F_78 ( V_2 , V_4 , V_84 ) ;
V_12:
if ( V_84 )
F_79 ( V_84 ) ;
return V_7 ;
}
static T_2 int F_80 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_40 * V_41 ,
struct V_84 * V_106 ,
struct V_107 * V_108 )
{
struct V_84 * V_84 ;
char * V_109 ;
int V_110 ;
struct V_28 * V_94 ;
struct V_43 V_111 ;
int V_7 ;
V_94 = V_41 -> V_59 [ 0 ] ;
F_81 ( V_94 , V_108 , & V_111 ) ;
V_110 = F_82 ( V_94 , V_108 ) ;
V_109 = F_32 ( V_110 , V_62 ) ;
if ( ! V_109 )
return - V_63 ;
F_34 ( V_94 , V_109 , ( unsigned long ) ( V_108 + 1 ) , V_110 ) ;
F_31 ( V_41 ) ;
V_84 = F_59 ( V_4 , V_111 . V_54 ) ;
if ( ! V_84 ) {
V_7 = - V_90 ;
goto V_12;
}
V_7 = F_83 ( V_2 , V_4 , V_41 , V_111 . V_54 ) ;
if ( V_7 )
goto V_12;
V_7 = F_84 ( V_2 , V_4 , V_106 , V_84 , V_109 , V_110 ) ;
if ( V_7 )
goto V_12;
else
V_7 = F_85 ( V_2 , V_4 ) ;
V_12:
F_33 ( V_109 ) ;
F_79 ( V_84 ) ;
return V_7 ;
}
static T_2 int F_86 ( struct V_3 * V_4 ,
struct V_40 * V_41 ,
T_1 V_112 , T_1 V_54 , T_1 V_22 ,
const char * V_109 , int V_110 )
{
struct V_107 * V_108 ;
struct V_43 V_111 ;
int V_113 = 0 ;
V_108 = F_87 ( NULL , V_4 , V_41 , V_112 ,
V_22 , V_109 , V_110 , 0 ) ;
if ( V_108 && ! F_88 ( V_108 ) ) {
F_81 ( V_41 -> V_59 [ 0 ] , V_108 , & V_111 ) ;
if ( V_111 . V_54 != V_54 )
goto V_12;
} else
goto V_12;
F_31 ( V_41 ) ;
V_108 = F_89 ( NULL , V_4 , V_41 , V_112 , V_109 , V_110 , 0 ) ;
if ( V_108 && ! F_88 ( V_108 ) ) {
F_81 ( V_41 -> V_59 [ 0 ] , V_108 , & V_111 ) ;
if ( V_111 . V_54 != V_54 )
goto V_12;
} else
goto V_12;
V_113 = 1 ;
V_12:
F_31 ( V_41 ) ;
return V_113 ;
}
static T_2 int F_90 ( struct V_3 * log ,
struct V_43 * V_44 ,
T_1 V_114 ,
const char * V_109 , int V_115 )
{
struct V_40 * V_41 ;
struct V_116 * V_117 ;
unsigned long V_118 ;
unsigned long V_119 ;
unsigned long V_120 ;
int V_121 ;
int V_45 ;
int V_7 ;
int V_113 = 0 ;
V_41 = F_91 () ;
if ( ! V_41 )
return - V_63 ;
V_7 = F_30 ( NULL , log , V_44 , V_41 , 0 , 0 ) ;
if ( V_7 != 0 )
goto V_12;
V_118 = F_29 ( V_41 -> V_59 [ 0 ] , V_41 -> V_60 [ 0 ] ) ;
if ( V_44 -> type == V_122 ) {
if ( F_92 ( V_41 , V_114 ,
V_109 , V_115 , NULL ) )
V_113 = 1 ;
goto V_12;
}
V_45 = F_28 ( V_41 -> V_59 [ 0 ] , V_41 -> V_60 [ 0 ] ) ;
V_119 = V_118 + V_45 ;
while ( V_118 < V_119 ) {
V_117 = (struct V_116 * ) V_118 ;
V_121 = F_93 ( V_41 -> V_59 [ 0 ] , V_117 ) ;
if ( V_121 == V_115 ) {
V_120 = ( unsigned long ) ( V_117 + 1 ) ;
V_7 = F_94 ( V_41 -> V_59 [ 0 ] , V_109 ,
V_120 , V_115 ) ;
if ( V_7 == 0 ) {
V_113 = 1 ;
goto V_12;
}
}
V_118 = ( unsigned long ) ( V_117 + 1 ) + V_121 ;
}
V_12:
F_95 ( V_41 ) ;
return V_113 ;
}
static inline int F_96 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_40 * V_41 ,
struct V_3 * V_9 ,
struct V_84 * V_106 , struct V_84 * V_84 ,
struct V_28 * V_29 ,
T_1 V_123 , T_1 V_124 ,
T_1 V_125 , char * V_109 , int V_115 ,
int * V_126 )
{
int V_7 ;
char * V_127 ;
int V_128 ;
struct V_28 * V_94 ;
struct V_107 * V_108 ;
struct V_43 V_129 ;
struct V_130 * V_131 ;
V_132:
V_129 . V_54 = V_123 ;
V_129 . type = V_133 ;
V_129 . V_82 = V_124 ;
V_7 = F_30 ( NULL , V_4 , & V_129 , V_41 , 0 , 0 ) ;
if ( V_7 == 0 ) {
struct V_116 * V_134 ;
unsigned long V_118 ;
unsigned long V_119 ;
V_94 = V_41 -> V_59 [ 0 ] ;
if ( V_129 . V_54 == V_129 . V_82 )
return 1 ;
V_118 = F_29 ( V_94 , V_41 -> V_60 [ 0 ] ) ;
V_119 = V_118 + F_28 ( V_94 , V_41 -> V_60 [ 0 ] ) ;
while ( V_118 < V_119 ) {
V_134 = (struct V_116 * ) V_118 ;
V_128 = F_93 ( V_94 ,
V_134 ) ;
V_127 = F_32 ( V_128 , V_62 ) ;
if ( ! V_127 )
return - V_63 ;
F_34 ( V_94 , V_127 ,
( unsigned long ) ( V_134 + 1 ) ,
V_128 ) ;
if ( ! F_90 ( V_9 , & V_129 ,
V_124 ,
V_127 ,
V_128 ) ) {
F_97 ( V_84 ) ;
F_31 ( V_41 ) ;
V_7 = F_84 ( V_2 , V_4 , V_106 ,
V_84 , V_127 ,
V_128 ) ;
F_33 ( V_127 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_85 ( V_2 , V_4 ) ;
if ( V_7 )
return V_7 ;
* V_126 = 1 ;
goto V_132;
}
F_33 ( V_127 ) ;
V_118 = ( unsigned long ) ( V_134 + 1 ) + V_128 ;
}
* V_126 = 1 ;
}
F_31 ( V_41 ) ;
V_131 = F_98 ( NULL , V_4 , V_41 , V_109 , V_115 ,
V_123 , V_124 , 0 ,
0 ) ;
if ( ! F_99 ( V_131 ) ) {
T_3 V_45 ;
T_3 V_135 = 0 ;
unsigned long V_136 ;
struct V_84 * V_137 ;
V_94 = V_41 -> V_59 [ 0 ] ;
V_45 = F_28 ( V_94 , V_41 -> V_60 [ 0 ] ) ;
V_136 = F_29 ( V_94 , V_41 -> V_60 [ 0 ] ) ;
while ( V_135 < V_45 ) {
V_131 = (struct V_130 * ) ( V_136 + V_135 ) ;
V_128 = F_100 ( V_94 , V_131 ) ;
if ( F_101 ( V_94 , V_131 ) != V_124 )
goto V_103;
V_127 = F_32 ( V_128 , V_62 ) ;
if ( ! V_127 )
return - V_63 ;
F_34 ( V_94 , V_127 , ( unsigned long ) & V_131 -> V_109 ,
V_128 ) ;
V_129 . V_54 = V_123 ;
V_129 . type = V_122 ;
V_129 . V_82 = F_102 ( V_124 ,
V_127 ,
V_128 ) ;
V_7 = 0 ;
if ( ! F_90 ( V_9 , & V_129 ,
V_124 , V_127 ,
V_128 ) ) {
V_7 = - V_26 ;
V_137 = F_59 ( V_4 ,
V_124 ) ;
if ( V_137 ) {
F_97 ( V_84 ) ;
F_31 ( V_41 ) ;
V_7 = F_84 ( V_2 , V_4 ,
V_137 ,
V_84 ,
V_127 ,
V_128 ) ;
if ( ! V_7 )
V_7 = F_85 (
V_2 , V_4 ) ;
}
F_79 ( V_137 ) ;
F_33 ( V_127 ) ;
if ( V_7 )
return V_7 ;
* V_126 = 1 ;
goto V_132;
}
F_33 ( V_127 ) ;
if ( V_7 )
return V_7 ;
V_103:
V_135 += V_128 + sizeof( * V_131 ) ;
}
* V_126 = 1 ;
}
F_31 ( V_41 ) ;
V_108 = F_87 ( V_2 , V_4 , V_41 , F_61 ( V_106 ) ,
V_125 , V_109 , V_115 , 0 ) ;
if ( V_108 && ! F_88 ( V_108 ) ) {
V_7 = F_80 ( V_2 , V_4 , V_41 , V_106 , V_108 ) ;
if ( V_7 )
return V_7 ;
}
F_31 ( V_41 ) ;
V_108 = F_89 ( V_2 , V_4 , V_41 , F_61 ( V_106 ) ,
V_109 , V_115 , 0 ) ;
if ( V_108 && ! F_88 ( V_108 ) ) {
V_7 = F_80 ( V_2 , V_4 , V_41 , V_106 , V_108 ) ;
if ( V_7 )
return V_7 ;
}
F_31 ( V_41 ) ;
return 0 ;
}
static int F_103 ( struct V_28 * V_29 , unsigned long V_138 ,
T_3 * V_115 , char * * V_109 , T_1 * V_22 ,
T_1 * V_124 )
{
struct V_130 * V_131 ;
V_131 = (struct V_130 * ) V_138 ;
* V_115 = F_100 ( V_29 , V_131 ) ;
* V_109 = F_32 ( * V_115 , V_62 ) ;
if ( * V_109 == NULL )
return - V_63 ;
F_34 ( V_29 , * V_109 , ( unsigned long ) & V_131 -> V_109 ,
* V_115 ) ;
* V_22 = F_104 ( V_29 , V_131 ) ;
if ( V_124 )
* V_124 = F_101 ( V_29 , V_131 ) ;
return 0 ;
}
static int F_105 ( struct V_28 * V_29 , unsigned long V_138 ,
T_3 * V_115 , char * * V_109 , T_1 * V_22 )
{
struct V_116 * V_117 ;
V_117 = (struct V_116 * ) V_138 ;
* V_115 = F_93 ( V_29 , V_117 ) ;
* V_109 = F_32 ( * V_115 , V_62 ) ;
if ( * V_109 == NULL )
return - V_63 ;
F_34 ( V_29 , * V_109 , ( unsigned long ) ( V_117 + 1 ) , * V_115 ) ;
* V_22 = F_106 ( V_29 , V_117 ) ;
return 0 ;
}
static T_2 int F_107 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_3 * log ,
struct V_40 * V_41 ,
struct V_28 * V_29 , int V_42 ,
struct V_43 * V_44 )
{
struct V_84 * V_106 = NULL ;
struct V_84 * V_84 = NULL ;
unsigned long V_138 ;
unsigned long V_139 ;
char * V_109 = NULL ;
int V_115 ;
int V_7 ;
int V_126 = 0 ;
int V_140 = 0 ;
T_1 V_124 ;
T_1 V_123 ;
T_1 V_125 = 0 ;
int V_141 ;
V_138 = F_29 ( V_29 , V_42 ) ;
V_139 = V_138 + F_28 ( V_29 , V_42 ) ;
if ( V_44 -> type == V_122 ) {
struct V_130 * V_142 ;
V_141 = sizeof( struct V_130 ) ;
V_140 = 1 ;
V_142 = (struct V_130 * ) V_138 ;
V_124 = F_101 ( V_29 , V_142 ) ;
} else {
V_141 = sizeof( struct V_116 ) ;
V_124 = V_44 -> V_82 ;
}
V_123 = V_44 -> V_54 ;
V_106 = F_59 ( V_4 , V_124 ) ;
if ( ! V_106 ) {
V_7 = - V_26 ;
goto V_12;
}
V_84 = F_59 ( V_4 , V_123 ) ;
if ( ! V_84 ) {
V_7 = - V_90 ;
goto V_12;
}
while ( V_138 < V_139 ) {
if ( V_140 ) {
V_7 = F_103 ( V_29 , V_138 , & V_115 , & V_109 ,
& V_125 , & V_124 ) ;
if ( ! V_106 )
V_106 = F_59 ( V_4 , V_124 ) ;
if ( ! V_106 ) {
V_7 = - V_26 ;
goto V_12;
}
} else {
V_7 = F_105 ( V_29 , V_138 , & V_115 , & V_109 ,
& V_125 ) ;
}
if ( V_7 )
goto V_12;
if ( ! F_86 ( V_4 , V_41 , F_61 ( V_106 ) , F_61 ( V_84 ) ,
V_125 , V_109 , V_115 ) ) {
if ( ! V_126 ) {
V_7 = F_96 ( V_2 , V_4 , V_41 , log ,
V_106 , V_84 , V_29 ,
V_123 ,
V_124 ,
V_125 , V_109 , V_115 ,
& V_126 ) ;
if ( V_7 ) {
if ( V_7 == 1 )
V_7 = 0 ;
goto V_12;
}
}
V_7 = F_108 ( V_2 , V_106 , V_84 , V_109 , V_115 ,
0 , V_125 ) ;
if ( V_7 )
goto V_12;
F_78 ( V_2 , V_4 , V_84 ) ;
}
V_138 = ( unsigned long ) ( V_138 + V_141 ) + V_115 ;
F_33 ( V_109 ) ;
V_109 = NULL ;
if ( V_140 ) {
F_79 ( V_106 ) ;
V_106 = NULL ;
}
}
V_7 = F_27 ( V_2 , V_4 , V_41 , V_29 , V_42 , V_44 ) ;
V_12:
F_31 ( V_41 ) ;
F_33 ( V_109 ) ;
F_79 ( V_106 ) ;
F_79 ( V_84 ) ;
return V_7 ;
}
static int F_109 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_1 V_143 )
{
int V_7 ;
V_7 = F_110 ( V_2 , V_4 , V_143 ) ;
if ( V_7 == - V_69 )
V_7 = 0 ;
return V_7 ;
}
static int F_111 ( struct V_3 * V_4 ,
struct V_84 * V_84 , struct V_40 * V_41 )
{
int V_7 = 0 ;
int V_110 ;
unsigned int V_144 = 0 ;
T_3 V_45 ;
T_3 V_135 = 0 ;
T_1 V_123 = F_61 ( V_84 ) ;
T_1 V_82 = 0 ;
unsigned long V_118 ;
struct V_130 * V_131 ;
struct V_28 * V_94 ;
while ( 1 ) {
V_7 = F_112 ( V_4 , V_123 , V_82 , V_41 ,
& V_131 , & V_82 ) ;
if ( V_7 )
break;
V_94 = V_41 -> V_59 [ 0 ] ;
V_45 = F_28 ( V_94 , V_41 -> V_60 [ 0 ] ) ;
V_118 = F_29 ( V_94 , V_41 -> V_60 [ 0 ] ) ;
V_135 = 0 ;
while ( V_135 < V_45 ) {
V_131 = (struct V_130 * ) ( V_118 + V_135 ) ;
V_110 = F_100 ( V_94 , V_131 ) ;
V_144 ++ ;
V_135 += V_110 + sizeof( * V_131 ) ;
}
V_82 ++ ;
F_31 ( V_41 ) ;
}
F_31 ( V_41 ) ;
if ( V_7 < 0 && V_7 != - V_26 )
return V_7 ;
return V_144 ;
}
static int F_113 ( struct V_3 * V_4 ,
struct V_84 * V_84 , struct V_40 * V_41 )
{
int V_7 ;
struct V_43 V_44 ;
unsigned int V_144 = 0 ;
unsigned long V_118 ;
unsigned long V_119 ;
int V_110 ;
T_1 V_143 = F_61 ( V_84 ) ;
V_44 . V_54 = V_143 ;
V_44 . type = V_133 ;
V_44 . V_82 = ( T_1 ) - 1 ;
while ( 1 ) {
V_7 = F_30 ( NULL , V_4 , & V_44 , V_41 , 0 , 0 ) ;
if ( V_7 < 0 )
break;
if ( V_7 > 0 ) {
if ( V_41 -> V_60 [ 0 ] == 0 )
break;
V_41 -> V_60 [ 0 ] -- ;
}
V_145:
F_114 ( V_41 -> V_59 [ 0 ] , & V_44 ,
V_41 -> V_60 [ 0 ] ) ;
if ( V_44 . V_54 != V_143 ||
V_44 . type != V_133 )
break;
V_118 = F_29 ( V_41 -> V_59 [ 0 ] , V_41 -> V_60 [ 0 ] ) ;
V_119 = V_118 + F_28 ( V_41 -> V_59 [ 0 ] ,
V_41 -> V_60 [ 0 ] ) ;
while ( V_118 < V_119 ) {
struct V_116 * V_117 ;
V_117 = (struct V_116 * ) V_118 ;
V_110 = F_93 ( V_41 -> V_59 [ 0 ] ,
V_117 ) ;
V_118 = ( unsigned long ) ( V_117 + 1 ) + V_110 ;
V_144 ++ ;
}
if ( V_44 . V_82 == 0 )
break;
if ( V_41 -> V_60 [ 0 ] > 0 ) {
V_41 -> V_60 [ 0 ] -- ;
goto V_145;
}
V_44 . V_82 -- ;
F_31 ( V_41 ) ;
}
F_31 ( V_41 ) ;
return V_144 ;
}
static T_2 int F_115 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_84 * V_84 )
{
struct V_40 * V_41 ;
int V_7 ;
T_1 V_144 = 0 ;
T_1 V_143 = F_61 ( V_84 ) ;
V_41 = F_91 () ;
if ( ! V_41 )
return - V_63 ;
V_7 = F_113 ( V_4 , V_84 , V_41 ) ;
if ( V_7 < 0 )
goto V_12;
V_144 = V_7 ;
V_7 = F_111 ( V_4 , V_84 , V_41 ) ;
if ( V_7 < 0 )
goto V_12;
V_144 += V_7 ;
V_7 = 0 ;
if ( V_144 != V_84 -> V_146 ) {
F_116 ( V_84 , V_144 ) ;
F_78 ( V_2 , V_4 , V_84 ) ;
}
F_117 ( V_84 ) -> V_147 = ( T_1 ) - 1 ;
if ( V_84 -> V_146 == 0 ) {
if ( F_39 ( V_84 -> V_148 ) ) {
V_7 = F_118 ( V_2 , V_4 , NULL , V_41 ,
V_143 , 1 ) ;
if ( V_7 )
goto V_12;
}
V_7 = F_109 ( V_2 , V_4 , V_143 ) ;
}
V_12:
F_95 ( V_41 ) ;
return V_7 ;
}
static T_2 int F_119 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_40 * V_41 )
{
int V_7 ;
struct V_43 V_44 ;
struct V_84 * V_84 ;
V_44 . V_54 = V_149 ;
V_44 . type = V_150 ;
V_44 . V_82 = ( T_1 ) - 1 ;
while ( 1 ) {
V_7 = F_30 ( V_2 , V_4 , & V_44 , V_41 , - 1 , 1 ) ;
if ( V_7 < 0 )
break;
if ( V_7 == 1 ) {
if ( V_41 -> V_60 [ 0 ] == 0 )
break;
V_41 -> V_60 [ 0 ] -- ;
}
F_114 ( V_41 -> V_59 [ 0 ] , & V_44 , V_41 -> V_60 [ 0 ] ) ;
if ( V_44 . V_54 != V_149 ||
V_44 . type != V_150 )
break;
V_7 = F_120 ( V_2 , V_4 , V_41 ) ;
if ( V_7 )
goto V_12;
F_31 ( V_41 ) ;
V_84 = F_59 ( V_4 , V_44 . V_82 ) ;
if ( ! V_84 )
return - V_90 ;
V_7 = F_115 ( V_2 , V_4 , V_84 ) ;
F_79 ( V_84 ) ;
if ( V_7 )
goto V_12;
V_44 . V_82 = ( T_1 ) - 1 ;
}
V_7 = 0 ;
V_12:
F_31 ( V_41 ) ;
return V_7 ;
}
static T_2 int F_83 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_40 * V_41 ,
T_1 V_54 )
{
struct V_43 V_44 ;
int V_7 = 0 ;
struct V_84 * V_84 ;
V_84 = F_59 ( V_4 , V_54 ) ;
if ( ! V_84 )
return - V_90 ;
V_44 . V_54 = V_149 ;
V_44 . type = V_150 ;
V_44 . V_82 = V_54 ;
V_7 = F_41 ( V_2 , V_4 , V_41 , & V_44 , 0 ) ;
F_31 ( V_41 ) ;
if ( V_7 == 0 ) {
if ( ! V_84 -> V_146 )
F_116 ( V_84 , 1 ) ;
else
F_97 ( V_84 ) ;
V_7 = F_78 ( V_2 , V_4 , V_84 ) ;
} else if ( V_7 == - V_69 ) {
V_7 = 0 ;
} else {
F_121 () ;
}
F_79 ( V_84 ) ;
return V_7 ;
}
static T_2 int F_122 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_112 , T_1 V_22 ,
char * V_109 , int V_110 ,
struct V_43 * V_111 )
{
struct V_84 * V_84 ;
struct V_84 * V_106 ;
int V_7 ;
V_84 = F_59 ( V_4 , V_111 -> V_54 ) ;
if ( ! V_84 )
return - V_26 ;
V_106 = F_59 ( V_4 , V_112 ) ;
if ( ! V_106 ) {
F_79 ( V_84 ) ;
return - V_90 ;
}
V_7 = F_108 ( V_2 , V_106 , V_84 , V_109 , V_110 , 1 , V_22 ) ;
F_79 ( V_84 ) ;
F_79 ( V_106 ) ;
return V_7 ;
}
static bool F_123 ( struct V_3 * V_9 ,
const char * V_109 , const int V_110 ,
const T_1 V_112 , const T_1 V_143 )
{
struct V_43 V_129 ;
V_129 . V_54 = V_143 ;
V_129 . type = V_133 ;
V_129 . V_82 = V_112 ;
if ( F_90 ( V_9 , & V_129 , V_112 , V_109 , V_110 ) )
return true ;
V_129 . type = V_122 ;
V_129 . V_82 = F_102 ( V_112 , V_109 , V_110 ) ;
if ( F_90 ( V_9 , & V_129 , V_112 , V_109 , V_110 ) )
return true ;
return false ;
}
static T_2 int F_124 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_40 * V_41 ,
struct V_28 * V_29 ,
struct V_107 * V_108 ,
struct V_43 * V_44 )
{
char * V_109 ;
int V_110 ;
struct V_107 * V_151 ;
struct V_43 V_152 ;
struct V_43 V_153 ;
struct V_84 * V_106 ;
T_4 V_154 ;
int V_155 ;
int V_7 = 0 ;
bool V_156 = ( V_44 -> type == V_157 ) ;
bool V_158 = false ;
V_106 = F_59 ( V_4 , V_44 -> V_54 ) ;
if ( ! V_106 )
return - V_90 ;
V_110 = F_82 ( V_29 , V_108 ) ;
V_109 = F_32 ( V_110 , V_62 ) ;
if ( ! V_109 ) {
V_7 = - V_63 ;
goto V_12;
}
V_154 = F_125 ( V_29 , V_108 ) ;
F_34 ( V_29 , V_109 , ( unsigned long ) ( V_108 + 1 ) ,
V_110 ) ;
F_81 ( V_29 , V_108 , & V_153 ) ;
V_155 = F_126 ( V_2 , V_4 , V_41 , & V_153 , 0 ) ;
if ( V_155 == 0 )
V_155 = 1 ;
else
V_155 = 0 ;
F_31 ( V_41 ) ;
if ( V_44 -> type == V_159 ) {
V_151 = F_89 ( V_2 , V_4 , V_41 , V_44 -> V_54 ,
V_109 , V_110 , 1 ) ;
} else if ( V_44 -> type == V_157 ) {
V_151 = F_87 ( V_2 , V_4 , V_41 ,
V_44 -> V_54 ,
V_44 -> V_82 , V_109 ,
V_110 , 1 ) ;
} else {
V_7 = - V_160 ;
goto V_12;
}
if ( F_99 ( V_151 ) ) {
if ( V_44 -> type != V_157 )
goto V_12;
goto V_61;
}
F_81 ( V_41 -> V_59 [ 0 ] , V_151 , & V_152 ) ;
if ( V_152 . V_54 == V_153 . V_54 &&
V_152 . type == V_153 . type &&
V_152 . V_82 == V_153 . V_82 &&
F_125 ( V_41 -> V_59 [ 0 ] , V_151 ) == V_154 ) {
V_156 = false ;
goto V_12;
}
if ( ! V_155 )
goto V_12;
V_7 = F_80 ( V_2 , V_4 , V_41 , V_106 , V_151 ) ;
if ( V_7 )
goto V_12;
if ( V_44 -> type == V_157 )
goto V_61;
V_12:
F_31 ( V_41 ) ;
if ( ! V_7 && V_156 ) {
F_127 ( V_106 , V_106 -> V_161 + V_110 * 2 ) ;
V_7 = F_78 ( V_2 , V_4 , V_106 ) ;
}
F_33 ( V_109 ) ;
F_79 ( V_106 ) ;
if ( ! V_7 && V_158 )
V_7 = 1 ;
return V_7 ;
V_61:
if ( F_123 ( V_4 -> V_9 , V_109 , V_110 ,
V_44 -> V_54 , V_153 . V_54 ) ) {
V_7 = 0 ;
V_156 = false ;
goto V_12;
}
F_31 ( V_41 ) ;
V_7 = F_122 ( V_2 , V_4 , V_44 -> V_54 , V_44 -> V_82 ,
V_109 , V_110 , & V_153 ) ;
if ( V_7 && V_7 != - V_26 && V_7 != - V_69 )
goto V_12;
if ( ! V_7 )
V_158 = true ;
V_156 = false ;
V_7 = 0 ;
goto V_12;
}
static T_2 int F_128 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_40 * V_41 ,
struct V_28 * V_29 , int V_42 ,
struct V_43 * V_44 )
{
int V_7 = 0 ;
T_3 V_45 = F_28 ( V_29 , V_42 ) ;
struct V_107 * V_108 ;
int V_110 ;
unsigned long V_118 ;
unsigned long V_119 ;
struct V_40 * V_162 = NULL ;
V_118 = F_29 ( V_29 , V_42 ) ;
V_119 = V_118 + V_45 ;
while ( V_118 < V_119 ) {
V_108 = (struct V_107 * ) V_118 ;
if ( F_129 ( V_4 , V_29 , V_108 ) )
return - V_90 ;
V_110 = F_82 ( V_29 , V_108 ) ;
V_7 = F_124 ( V_2 , V_4 , V_41 , V_29 , V_108 , V_44 ) ;
if ( V_7 < 0 )
break;
V_118 = ( unsigned long ) ( V_108 + 1 ) ;
V_118 += V_110 ;
if ( V_7 == 1 && F_125 ( V_29 , V_108 ) != V_163 ) {
struct V_43 V_164 ;
if ( ! V_162 ) {
V_162 = F_91 () ;
if ( ! V_162 ) {
V_7 = - V_63 ;
break;
}
}
F_81 ( V_29 , V_108 , & V_164 ) ;
V_7 = F_83 ( V_2 , V_4 , V_162 ,
V_164 . V_54 ) ;
if ( V_7 )
break;
}
V_7 = 0 ;
}
F_95 ( V_162 ) ;
return V_7 ;
}
static T_2 int F_130 ( struct V_3 * V_4 ,
struct V_40 * V_41 ,
T_1 V_112 , int V_165 ,
T_1 * V_166 , T_1 * V_167 )
{
struct V_43 V_44 ;
T_1 V_168 ;
struct V_169 * V_65 ;
int V_7 ;
int V_170 ;
if ( * V_166 == ( T_1 ) - 1 )
return 1 ;
V_44 . V_54 = V_112 ;
V_44 . type = V_165 ;
V_44 . V_82 = * V_166 ;
V_7 = F_30 ( NULL , V_4 , & V_44 , V_41 , 0 , 0 ) ;
if ( V_7 < 0 )
goto V_12;
if ( V_7 > 0 ) {
if ( V_41 -> V_60 [ 0 ] == 0 )
goto V_12;
V_41 -> V_60 [ 0 ] -- ;
}
if ( V_7 != 0 )
F_114 ( V_41 -> V_59 [ 0 ] , & V_44 , V_41 -> V_60 [ 0 ] ) ;
if ( V_44 . type != V_165 || V_44 . V_54 != V_112 ) {
V_7 = 1 ;
goto V_103;
}
V_65 = F_35 ( V_41 -> V_59 [ 0 ] , V_41 -> V_60 [ 0 ] ,
struct V_169 ) ;
V_168 = F_131 ( V_41 -> V_59 [ 0 ] , V_65 ) ;
if ( * V_166 >= V_44 . V_82 && * V_166 <= V_168 ) {
V_7 = 0 ;
* V_166 = V_44 . V_82 ;
* V_167 = V_168 ;
goto V_12;
}
V_7 = 1 ;
V_103:
V_170 = F_132 ( V_41 -> V_59 [ 0 ] ) ;
if ( V_41 -> V_60 [ 0 ] >= V_170 ) {
V_7 = F_133 ( V_4 , V_41 ) ;
if ( V_7 )
goto V_12;
} else {
V_41 -> V_60 [ 0 ] ++ ;
}
F_114 ( V_41 -> V_59 [ 0 ] , & V_44 , V_41 -> V_60 [ 0 ] ) ;
if ( V_44 . type != V_165 || V_44 . V_54 != V_112 ) {
V_7 = 1 ;
goto V_12;
}
V_65 = F_35 ( V_41 -> V_59 [ 0 ] , V_41 -> V_60 [ 0 ] ,
struct V_169 ) ;
V_168 = F_131 ( V_41 -> V_59 [ 0 ] , V_65 ) ;
* V_166 = V_44 . V_82 ;
* V_167 = V_168 ;
V_7 = 0 ;
V_12:
F_31 ( V_41 ) ;
return V_7 ;
}
static T_2 int F_134 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_3 * log ,
struct V_40 * V_41 ,
struct V_40 * V_171 ,
struct V_84 * V_106 ,
struct V_43 * V_172 )
{
int V_7 ;
struct V_28 * V_29 ;
int V_42 ;
T_3 V_45 ;
struct V_107 * V_108 ;
struct V_107 * V_173 ;
int V_110 ;
unsigned long V_118 ;
unsigned long V_119 ;
char * V_109 ;
struct V_84 * V_84 ;
struct V_43 V_111 ;
V_132:
V_29 = V_41 -> V_59 [ 0 ] ;
V_42 = V_41 -> V_60 [ 0 ] ;
V_45 = F_28 ( V_29 , V_42 ) ;
V_118 = F_29 ( V_29 , V_42 ) ;
V_119 = V_118 + V_45 ;
while ( V_118 < V_119 ) {
V_108 = (struct V_107 * ) V_118 ;
if ( F_129 ( V_4 , V_29 , V_108 ) ) {
V_7 = - V_90 ;
goto V_12;
}
V_110 = F_82 ( V_29 , V_108 ) ;
V_109 = F_32 ( V_110 , V_62 ) ;
if ( ! V_109 ) {
V_7 = - V_63 ;
goto V_12;
}
F_34 ( V_29 , V_109 , ( unsigned long ) ( V_108 + 1 ) ,
V_110 ) ;
V_173 = NULL ;
if ( log && V_172 -> type == V_159 ) {
V_173 = F_89 ( V_2 , log , V_171 ,
V_172 -> V_54 ,
V_109 , V_110 , 0 ) ;
} else if ( log && V_172 -> type == V_157 ) {
V_173 = F_87 ( V_2 , log ,
V_171 ,
V_172 -> V_54 ,
V_172 -> V_82 ,
V_109 , V_110 , 0 ) ;
}
if ( ! V_173 || ( F_88 ( V_173 ) && F_135 ( V_173 ) == - V_26 ) ) {
F_81 ( V_29 , V_108 , & V_111 ) ;
F_31 ( V_41 ) ;
F_31 ( V_171 ) ;
V_84 = F_59 ( V_4 , V_111 . V_54 ) ;
if ( ! V_84 ) {
F_33 ( V_109 ) ;
return - V_90 ;
}
V_7 = F_83 ( V_2 , V_4 ,
V_41 , V_111 . V_54 ) ;
if ( V_7 ) {
F_33 ( V_109 ) ;
F_79 ( V_84 ) ;
goto V_12;
}
F_97 ( V_84 ) ;
V_7 = F_84 ( V_2 , V_4 , V_106 , V_84 ,
V_109 , V_110 ) ;
if ( ! V_7 )
V_7 = F_85 ( V_2 , V_4 ) ;
F_33 ( V_109 ) ;
F_79 ( V_84 ) ;
if ( V_7 )
goto V_12;
V_7 = F_30 ( NULL , V_4 , V_172 , V_41 ,
0 , 0 ) ;
if ( V_7 == 0 )
goto V_132;
V_7 = 0 ;
goto V_12;
} else if ( F_88 ( V_173 ) ) {
F_33 ( V_109 ) ;
return F_135 ( V_173 ) ;
}
F_31 ( V_171 ) ;
F_33 ( V_109 ) ;
V_118 = ( unsigned long ) ( V_108 + 1 ) ;
V_118 += V_110 ;
}
V_7 = 0 ;
V_12:
F_31 ( V_41 ) ;
F_31 ( V_171 ) ;
return V_7 ;
}
static int F_136 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_3 * log ,
struct V_40 * V_41 ,
const T_1 V_143 )
{
struct V_43 V_129 ;
struct V_40 * V_171 ;
int V_174 ;
int V_170 ;
int V_7 ;
V_171 = F_91 () ;
if ( ! V_171 )
return - V_63 ;
V_129 . V_54 = V_143 ;
V_129 . type = V_175 ;
V_129 . V_82 = 0 ;
V_132:
V_7 = F_30 ( NULL , V_4 , & V_129 , V_41 , 0 , 0 ) ;
if ( V_7 < 0 )
goto V_12;
V_176:
V_170 = F_132 ( V_41 -> V_59 [ 0 ] ) ;
for ( V_174 = V_41 -> V_60 [ 0 ] ; V_174 < V_170 ; V_174 ++ ) {
struct V_43 V_44 ;
struct V_107 * V_108 ;
struct V_107 * V_173 ;
T_3 V_177 ;
T_3 V_178 ;
F_114 ( V_41 -> V_59 [ 0 ] , & V_44 , V_174 ) ;
if ( V_44 . V_54 != V_143 || V_44 . type != V_175 ) {
V_7 = 0 ;
goto V_12;
}
V_108 = F_35 ( V_41 -> V_59 [ 0 ] , V_174 , struct V_107 ) ;
V_177 = F_28 ( V_41 -> V_59 [ 0 ] , V_174 ) ;
V_178 = 0 ;
while ( V_178 < V_177 ) {
T_5 V_110 = F_82 ( V_41 -> V_59 [ 0 ] , V_108 ) ;
T_5 V_179 = F_137 ( V_41 -> V_59 [ 0 ] , V_108 ) ;
T_3 V_180 = sizeof( * V_108 ) + V_110 + V_179 ;
char * V_109 ;
V_109 = F_32 ( V_110 , V_62 ) ;
if ( ! V_109 ) {
V_7 = - V_63 ;
goto V_12;
}
F_34 ( V_41 -> V_59 [ 0 ] , V_109 ,
( unsigned long ) ( V_108 + 1 ) , V_110 ) ;
V_173 = F_138 ( NULL , log , V_171 , V_143 ,
V_109 , V_110 , 0 ) ;
F_31 ( V_171 ) ;
if ( ! V_173 ) {
F_31 ( V_41 ) ;
V_108 = F_138 ( V_2 , V_4 , V_41 , V_143 ,
V_109 , V_110 , - 1 ) ;
F_33 ( V_109 ) ;
if ( F_88 ( V_108 ) ) {
V_7 = F_135 ( V_108 ) ;
goto V_12;
}
ASSERT ( V_108 ) ;
V_7 = F_139 ( V_2 , V_4 ,
V_41 , V_108 ) ;
if ( V_7 )
goto V_12;
F_31 ( V_41 ) ;
V_129 = V_44 ;
goto V_132;
}
F_33 ( V_109 ) ;
if ( F_88 ( V_173 ) ) {
V_7 = F_135 ( V_173 ) ;
goto V_12;
}
V_178 += V_180 ;
V_108 = (struct V_107 * ) ( ( char * ) V_108 + V_180 ) ;
}
}
V_7 = F_133 ( V_4 , V_41 ) ;
if ( V_7 > 0 )
V_7 = 0 ;
else if ( V_7 == 0 )
goto V_176;
V_12:
F_95 ( V_171 ) ;
F_31 ( V_41 ) ;
return V_7 ;
}
static T_2 int F_118 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_3 * log ,
struct V_40 * V_41 ,
T_1 V_112 , int V_181 )
{
T_1 V_182 ;
T_1 V_183 ;
int V_165 = V_184 ;
int V_7 = 0 ;
struct V_43 V_172 ;
struct V_43 V_152 ;
struct V_40 * V_171 ;
struct V_84 * V_106 ;
V_172 . V_54 = V_112 ;
V_172 . type = V_159 ;
V_171 = F_91 () ;
if ( ! V_171 )
return - V_63 ;
V_106 = F_59 ( V_4 , V_112 ) ;
if ( ! V_106 ) {
F_95 ( V_171 ) ;
return 0 ;
}
V_132:
V_182 = 0 ;
V_183 = 0 ;
while ( 1 ) {
if ( V_181 )
V_183 = ( T_1 ) - 1 ;
else {
V_7 = F_130 ( log , V_41 , V_112 , V_165 ,
& V_182 , & V_183 ) ;
if ( V_7 != 0 )
break;
}
V_172 . V_82 = V_182 ;
while ( 1 ) {
int V_170 ;
V_7 = F_30 ( NULL , V_4 , & V_172 , V_41 ,
0 , 0 ) ;
if ( V_7 < 0 )
goto V_12;
V_170 = F_132 ( V_41 -> V_59 [ 0 ] ) ;
if ( V_41 -> V_60 [ 0 ] >= V_170 ) {
V_7 = F_133 ( V_4 , V_41 ) ;
if ( V_7 )
break;
}
F_114 ( V_41 -> V_59 [ 0 ] , & V_152 ,
V_41 -> V_60 [ 0 ] ) ;
if ( V_152 . V_54 != V_112 ||
V_152 . type != V_172 . type )
goto V_185;
if ( V_152 . V_82 > V_183 )
break;
V_7 = F_134 ( V_2 , V_4 , log , V_41 ,
V_171 , V_106 ,
& V_152 ) ;
if ( V_7 )
goto V_12;
if ( V_152 . V_82 == ( T_1 ) - 1 )
break;
V_172 . V_82 = V_152 . V_82 + 1 ;
}
F_31 ( V_41 ) ;
if ( V_183 == ( T_1 ) - 1 )
break;
V_182 = V_183 + 1 ;
}
V_185:
V_7 = 0 ;
if ( V_165 == V_184 ) {
V_165 = V_186 ;
V_172 . type = V_157 ;
F_31 ( V_41 ) ;
goto V_132;
}
V_12:
F_31 ( V_41 ) ;
F_95 ( V_171 ) ;
F_79 ( V_106 ) ;
return V_7 ;
}
static int F_140 ( struct V_3 * log , struct V_28 * V_29 ,
struct V_30 * V_31 , T_1 V_32 )
{
int V_170 ;
struct V_40 * V_41 ;
struct V_3 * V_4 = V_31 -> V_187 ;
struct V_43 V_44 ;
int V_188 ;
int V_174 ;
int V_7 ;
V_7 = F_20 ( V_29 , V_32 ) ;
if ( V_7 )
return V_7 ;
V_188 = F_23 ( V_29 ) ;
if ( V_188 != 0 )
return 0 ;
V_41 = F_91 () ;
if ( ! V_41 )
return - V_63 ;
V_170 = F_132 ( V_29 ) ;
for ( V_174 = 0 ; V_174 < V_170 ; V_174 ++ ) {
F_114 ( V_29 , & V_44 , V_174 ) ;
if ( V_44 . type == V_52 &&
V_31 -> V_189 == V_190 ) {
struct V_64 * V_51 ;
T_3 V_67 ;
V_51 = F_35 ( V_29 , V_174 ,
struct V_64 ) ;
V_7 = F_136 ( V_31 -> V_2 , V_4 , log ,
V_41 , V_44 . V_54 ) ;
if ( V_7 )
break;
V_67 = F_38 ( V_29 , V_51 ) ;
if ( F_39 ( V_67 ) ) {
V_7 = F_118 ( V_31 -> V_2 ,
V_4 , log , V_41 , V_44 . V_54 , 0 ) ;
if ( V_7 )
break;
}
V_7 = F_27 ( V_31 -> V_2 , V_4 , V_41 ,
V_29 , V_174 , & V_44 ) ;
if ( V_7 )
break;
if ( F_46 ( V_67 ) ) {
V_7 = F_109 ( V_31 -> V_2 , V_4 ,
V_44 . V_54 ) ;
if ( V_7 )
break;
}
V_7 = F_83 ( V_31 -> V_2 , V_4 ,
V_41 , V_44 . V_54 ) ;
if ( V_7 )
break;
}
if ( V_44 . type == V_157 &&
V_31 -> V_189 == V_191 ) {
V_7 = F_128 ( V_31 -> V_2 , V_4 , V_41 ,
V_29 , V_174 , & V_44 ) ;
if ( V_7 )
break;
}
if ( V_31 -> V_189 < V_192 )
continue;
if ( V_44 . type == V_175 ) {
V_7 = F_27 ( V_31 -> V_2 , V_4 , V_41 ,
V_29 , V_174 , & V_44 ) ;
if ( V_7 )
break;
} else if ( V_44 . type == V_133 ||
V_44 . type == V_122 ) {
V_7 = F_107 ( V_31 -> V_2 , V_4 , log , V_41 ,
V_29 , V_174 , & V_44 ) ;
if ( V_7 && V_7 != - V_26 )
break;
V_7 = 0 ;
} else if ( V_44 . type == V_193 ) {
V_7 = F_52 ( V_31 -> V_2 , V_4 , V_41 ,
V_29 , V_174 , & V_44 ) ;
if ( V_7 )
break;
} else if ( V_44 . type == V_159 ) {
V_7 = F_128 ( V_31 -> V_2 , V_4 , V_41 ,
V_29 , V_174 , & V_44 ) ;
if ( V_7 )
break;
}
}
F_95 ( V_41 ) ;
return V_7 ;
}
static T_2 int F_141 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_40 * V_41 , int * V_188 ,
struct V_30 * V_31 )
{
T_1 V_194 ;
T_1 V_105 ;
T_1 V_195 ;
struct V_28 * V_103 ;
struct V_28 * V_178 ;
struct V_28 * V_196 ;
T_3 V_197 ;
int V_7 = 0 ;
F_142 ( * V_188 < 0 ) ;
F_142 ( * V_188 >= V_198 ) ;
while ( * V_188 > 0 ) {
F_142 ( * V_188 < 0 ) ;
F_142 ( * V_188 >= V_198 ) ;
V_178 = V_41 -> V_59 [ * V_188 ] ;
F_142 ( F_23 ( V_178 ) != * V_188 ) ;
if ( V_41 -> V_60 [ * V_188 ] >=
F_132 ( V_178 ) )
break;
V_105 = F_143 ( V_178 , V_41 -> V_60 [ * V_188 ] ) ;
V_195 = F_144 ( V_178 , V_41 -> V_60 [ * V_188 ] ) ;
V_197 = V_4 -> V_199 ;
V_196 = V_41 -> V_59 [ * V_188 ] ;
V_194 = F_145 ( V_196 ) ;
V_103 = F_146 ( V_4 , V_105 ) ;
if ( F_88 ( V_103 ) )
return F_135 ( V_103 ) ;
if ( * V_188 == 1 ) {
V_7 = V_31 -> V_200 ( V_4 , V_103 , V_31 , V_195 ) ;
if ( V_7 ) {
F_147 ( V_103 ) ;
return V_7 ;
}
V_41 -> V_60 [ * V_188 ] ++ ;
if ( V_31 -> free ) {
V_7 = F_20 ( V_103 , V_195 ) ;
if ( V_7 ) {
F_147 ( V_103 ) ;
return V_7 ;
}
if ( V_2 ) {
F_148 ( V_103 ) ;
F_149 ( V_103 ) ;
F_150 ( V_2 , V_4 -> V_10 ,
V_103 ) ;
F_26 ( V_103 ) ;
F_151 ( V_103 ) ;
}
F_142 ( V_194 !=
V_55 ) ;
V_7 = F_152 ( V_4 ,
V_105 , V_197 ) ;
if ( V_7 ) {
F_147 ( V_103 ) ;
return V_7 ;
}
}
F_147 ( V_103 ) ;
continue;
}
V_7 = F_20 ( V_103 , V_195 ) ;
if ( V_7 ) {
F_147 ( V_103 ) ;
return V_7 ;
}
F_142 ( * V_188 <= 0 ) ;
if ( V_41 -> V_59 [ * V_188 - 1 ] )
F_147 ( V_41 -> V_59 [ * V_188 - 1 ] ) ;
V_41 -> V_59 [ * V_188 - 1 ] = V_103 ;
* V_188 = F_23 ( V_103 ) ;
V_41 -> V_60 [ * V_188 ] = 0 ;
F_153 () ;
}
F_142 ( * V_188 < 0 ) ;
F_142 ( * V_188 >= V_198 ) ;
V_41 -> V_60 [ * V_188 ] = F_132 ( V_41 -> V_59 [ * V_188 ] ) ;
F_153 () ;
return 0 ;
}
static T_2 int F_154 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_40 * V_41 , int * V_188 ,
struct V_30 * V_31 )
{
T_1 V_194 ;
int V_174 ;
int V_42 ;
int V_7 ;
for ( V_174 = * V_188 ; V_174 < V_198 - 1 && V_41 -> V_59 [ V_174 ] ; V_174 ++ ) {
V_42 = V_41 -> V_60 [ V_174 ] ;
if ( V_42 + 1 < F_132 ( V_41 -> V_59 [ V_174 ] ) ) {
V_41 -> V_60 [ V_174 ] ++ ;
* V_188 = V_174 ;
F_142 ( * V_188 == 0 ) ;
return 0 ;
} else {
struct V_28 * V_196 ;
if ( V_41 -> V_59 [ * V_188 ] == V_4 -> V_201 )
V_196 = V_41 -> V_59 [ * V_188 ] ;
else
V_196 = V_41 -> V_59 [ * V_188 + 1 ] ;
V_194 = F_145 ( V_196 ) ;
V_7 = V_31 -> V_200 ( V_4 , V_41 -> V_59 [ * V_188 ] , V_31 ,
F_155 ( V_41 -> V_59 [ * V_188 ] ) ) ;
if ( V_7 )
return V_7 ;
if ( V_31 -> free ) {
struct V_28 * V_103 ;
V_103 = V_41 -> V_59 [ * V_188 ] ;
if ( V_2 ) {
F_148 ( V_103 ) ;
F_149 ( V_103 ) ;
F_150 ( V_2 , V_4 -> V_10 ,
V_103 ) ;
F_26 ( V_103 ) ;
F_151 ( V_103 ) ;
}
F_142 ( V_194 != V_55 ) ;
V_7 = F_152 ( V_4 ,
V_41 -> V_59 [ * V_188 ] -> V_36 ,
V_41 -> V_59 [ * V_188 ] -> V_37 ) ;
if ( V_7 )
return V_7 ;
}
F_147 ( V_41 -> V_59 [ * V_188 ] ) ;
V_41 -> V_59 [ * V_188 ] = NULL ;
* V_188 = V_174 + 1 ;
}
}
return 1 ;
}
static int F_156 ( struct V_1 * V_2 ,
struct V_3 * log , struct V_30 * V_31 )
{
int V_7 = 0 ;
int V_202 ;
int V_188 ;
struct V_40 * V_41 ;
int V_203 ;
V_41 = F_91 () ;
if ( ! V_41 )
return - V_63 ;
V_188 = F_23 ( log -> V_201 ) ;
V_203 = V_188 ;
V_41 -> V_59 [ V_188 ] = log -> V_201 ;
F_157 ( log -> V_201 ) ;
V_41 -> V_60 [ V_188 ] = 0 ;
while ( 1 ) {
V_202 = F_141 ( V_2 , log , V_41 , & V_188 , V_31 ) ;
if ( V_202 > 0 )
break;
if ( V_202 < 0 ) {
V_7 = V_202 ;
goto V_12;
}
V_202 = F_154 ( V_2 , log , V_41 , & V_188 , V_31 ) ;
if ( V_202 > 0 )
break;
if ( V_202 < 0 ) {
V_7 = V_202 ;
goto V_12;
}
}
if ( V_41 -> V_59 [ V_203 ] ) {
V_7 = V_31 -> V_200 ( log , V_41 -> V_59 [ V_203 ] , V_31 ,
F_155 ( V_41 -> V_59 [ V_203 ] ) ) ;
if ( V_7 )
goto V_12;
if ( V_31 -> free ) {
struct V_28 * V_103 ;
V_103 = V_41 -> V_59 [ V_203 ] ;
if ( V_2 ) {
F_148 ( V_103 ) ;
F_149 ( V_103 ) ;
F_150 ( V_2 , log -> V_10 , V_103 ) ;
F_26 ( V_103 ) ;
F_151 ( V_103 ) ;
}
F_142 ( log -> V_53 . V_54 !=
V_55 ) ;
V_7 = F_152 ( log , V_103 -> V_36 ,
V_103 -> V_37 ) ;
if ( V_7 )
goto V_12;
}
}
V_12:
F_95 ( V_41 ) ;
return V_7 ;
}
static int F_158 ( struct V_1 * V_2 ,
struct V_3 * log )
{
int V_7 ;
if ( log -> V_23 == 1 ) {
V_7 = F_159 ( V_2 , log -> V_10 -> V_19 ,
& log -> V_53 , & log -> V_204 ) ;
} else {
V_7 = F_160 ( V_2 , log -> V_10 -> V_19 ,
& log -> V_53 , & log -> V_204 ) ;
}
return V_7 ;
}
static void F_161 ( struct V_3 * V_4 , int V_79 )
{
F_162 ( V_39 ) ;
int V_22 = V_79 % 2 ;
do {
F_163 ( & V_4 -> V_205 [ V_22 ] ,
& V_39 , V_206 ) ;
F_7 ( & V_4 -> V_8 ) ;
if ( V_4 -> V_207 < V_79 &&
F_164 ( & V_4 -> V_208 [ V_22 ] ) )
F_165 () ;
F_166 ( & V_4 -> V_205 [ V_22 ] , & V_39 ) ;
F_2 ( & V_4 -> V_8 ) ;
} while ( V_4 -> V_207 < V_79 &&
F_164 ( & V_4 -> V_208 [ V_22 ] ) );
}
static void F_167 ( struct V_3 * V_4 )
{
F_162 ( V_39 ) ;
while ( F_164 ( & V_4 -> V_21 ) ) {
F_163 ( & V_4 -> V_27 ,
& V_39 , V_206 ) ;
F_7 ( & V_4 -> V_8 ) ;
if ( F_164 ( & V_4 -> V_21 ) )
F_165 () ;
F_166 ( & V_4 -> V_27 , & V_39 ) ;
F_2 ( & V_4 -> V_8 ) ;
}
}
static inline void F_168 ( struct V_3 * V_4 ,
struct V_5 * V_6 )
{
if ( ! V_6 )
return;
F_2 ( & V_4 -> V_8 ) ;
F_169 ( & V_6 -> V_24 ) ;
F_7 ( & V_4 -> V_8 ) ;
}
static inline void F_170 ( struct V_3 * V_4 ,
int V_22 , int error )
{
struct V_5 * V_6 ;
struct V_5 * V_209 ;
F_171 (ctx, safe, &root->log_ctxs[index], list) {
F_169 ( & V_6 -> V_24 ) ;
V_6 -> V_210 = error ;
}
F_172 ( & V_4 -> V_25 [ V_22 ] ) ;
}
int F_173 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_5 * V_6 )
{
int V_211 ;
int V_212 ;
int V_213 ;
int V_7 ;
struct V_3 * log = V_4 -> V_9 ;
struct V_3 * V_19 = V_4 -> V_10 -> V_19 ;
int V_23 = 0 ;
struct V_5 V_214 ;
struct V_215 V_216 ;
F_2 ( & V_4 -> V_8 ) ;
V_23 = V_6 -> V_23 ;
if ( V_4 -> V_207 >= V_23 ) {
F_7 ( & V_4 -> V_8 ) ;
return V_6 -> V_210 ;
}
V_211 = V_23 % 2 ;
if ( F_164 ( & V_4 -> V_208 [ V_211 ] ) ) {
F_161 ( V_4 , V_23 ) ;
F_7 ( & V_4 -> V_8 ) ;
return V_6 -> V_210 ;
}
ASSERT ( V_23 == V_4 -> V_23 ) ;
F_174 ( & V_4 -> V_208 [ V_211 ] , 1 ) ;
if ( F_164 ( & V_4 -> V_208 [ ( V_211 + 1 ) % 2 ] ) )
F_161 ( V_4 , V_23 - 1 ) ;
while ( 1 ) {
int V_217 = F_164 ( & V_4 -> V_20 ) ;
if ( ! F_175 ( V_4 -> V_10 , V_218 ) &&
F_176 ( V_14 , & V_4 -> V_15 ) ) {
F_7 ( & V_4 -> V_8 ) ;
F_177 ( 1 ) ;
F_2 ( & V_4 -> V_8 ) ;
}
F_167 ( V_4 ) ;
if ( V_217 == F_164 ( & V_4 -> V_20 ) )
break;
}
if ( F_3 ( V_4 -> V_10 , V_2 ) ) {
V_7 = - V_11 ;
F_178 ( log , V_23 ) ;
F_7 ( & V_4 -> V_8 ) ;
goto V_12;
}
if ( V_23 % 2 == 0 )
V_213 = V_219 ;
else
V_213 = V_220 ;
F_179 ( & V_216 ) ;
V_7 = F_180 ( log , & log -> V_221 , V_213 ) ;
if ( V_7 ) {
F_181 ( & V_216 ) ;
F_182 ( V_2 , V_7 ) ;
F_178 ( log , V_23 ) ;
F_183 ( V_4 -> V_10 , V_2 ) ;
F_7 ( & V_4 -> V_8 ) ;
goto V_12;
}
F_184 ( & log -> V_204 , log -> V_201 ) ;
V_4 -> V_23 ++ ;
log -> V_23 = V_4 -> V_23 ;
V_4 -> V_13 = 0 ;
F_7 ( & V_4 -> V_8 ) ;
F_185 ( & V_214 , NULL ) ;
F_2 ( & V_19 -> V_8 ) ;
F_9 ( & V_19 -> V_20 ) ;
F_9 ( & V_19 -> V_21 ) ;
V_212 = V_19 -> V_23 % 2 ;
F_10 ( & V_214 . V_24 , & V_19 -> V_25 [ V_212 ] ) ;
V_214 . V_23 = V_19 -> V_23 ;
F_7 ( & V_19 -> V_8 ) ;
V_7 = F_158 ( V_2 , log ) ;
F_2 ( & V_19 -> V_8 ) ;
if ( F_15 ( & V_19 -> V_21 ) ) {
if ( F_16 ( & V_19 -> V_27 ) )
F_17 ( & V_19 -> V_27 ) ;
}
if ( V_7 ) {
if ( ! F_72 ( & V_214 . V_24 ) )
F_169 ( & V_214 . V_24 ) ;
F_181 ( & V_216 ) ;
F_183 ( V_4 -> V_10 , V_2 ) ;
if ( V_7 != - V_222 ) {
F_182 ( V_2 , V_7 ) ;
F_7 ( & V_19 -> V_8 ) ;
goto V_12;
}
F_186 ( log , & log -> V_221 , V_213 ) ;
F_178 ( log , V_23 ) ;
F_7 ( & V_19 -> V_8 ) ;
V_7 = - V_11 ;
goto V_12;
}
if ( V_19 -> V_207 >= V_214 . V_23 ) {
F_181 ( & V_216 ) ;
F_169 ( & V_214 . V_24 ) ;
F_7 ( & V_19 -> V_8 ) ;
V_7 = V_214 . V_210 ;
goto V_12;
}
V_212 = V_214 . V_23 % 2 ;
if ( F_164 ( & V_19 -> V_208 [ V_212 ] ) ) {
F_181 ( & V_216 ) ;
V_7 = F_186 ( log , & log -> V_221 ,
V_213 ) ;
F_187 ( V_2 , log , V_23 ) ;
F_161 ( V_19 ,
V_214 . V_23 ) ;
F_7 ( & V_19 -> V_8 ) ;
if ( ! V_7 )
V_7 = V_214 . V_210 ;
goto V_12;
}
ASSERT ( V_214 . V_23 == V_19 -> V_23 ) ;
F_174 ( & V_19 -> V_208 [ V_212 ] , 1 ) ;
if ( F_164 ( & V_19 -> V_208 [ ( V_212 + 1 ) % 2 ] ) ) {
F_161 ( V_19 ,
V_214 . V_23 - 1 ) ;
}
F_167 ( V_19 ) ;
if ( F_3 ( V_4 -> V_10 , V_2 ) ) {
F_181 ( & V_216 ) ;
F_186 ( log , & log -> V_221 , V_213 ) ;
F_178 ( log , V_23 ) ;
F_7 ( & V_19 -> V_8 ) ;
V_7 = - V_11 ;
goto V_223;
}
V_7 = F_180 ( V_19 ,
& V_19 -> V_221 ,
V_219 | V_220 ) ;
F_181 ( & V_216 ) ;
if ( V_7 ) {
F_183 ( V_4 -> V_10 , V_2 ) ;
F_182 ( V_2 , V_7 ) ;
F_178 ( log , V_23 ) ;
F_7 ( & V_19 -> V_8 ) ;
goto V_223;
}
V_7 = F_186 ( log , & log -> V_221 , V_213 ) ;
if ( ! V_7 )
V_7 = F_186 ( V_19 ,
& V_19 -> V_221 ,
V_220 | V_219 ) ;
if ( V_7 ) {
F_183 ( V_4 -> V_10 , V_2 ) ;
F_178 ( log , V_23 ) ;
F_7 ( & V_19 -> V_8 ) ;
goto V_223;
}
F_187 ( V_2 , log , V_23 ) ;
F_188 ( V_4 -> V_10 -> V_224 ,
V_19 -> V_201 -> V_36 ) ;
F_189 ( V_4 -> V_10 -> V_224 ,
F_23 ( V_19 -> V_201 ) ) ;
V_19 -> V_23 ++ ;
F_7 ( & V_19 -> V_8 ) ;
V_7 = F_190 ( V_2 , V_4 -> V_10 -> V_225 , 1 ) ;
if ( V_7 ) {
F_183 ( V_4 -> V_10 , V_2 ) ;
F_182 ( V_2 , V_7 ) ;
goto V_223;
}
F_2 ( & V_4 -> V_8 ) ;
if ( V_4 -> V_226 < V_23 )
V_4 -> V_226 = V_23 ;
F_7 ( & V_4 -> V_8 ) ;
V_223:
F_2 ( & V_19 -> V_8 ) ;
F_170 ( V_19 , V_212 , V_7 ) ;
V_19 -> V_207 ++ ;
F_174 ( & V_19 -> V_208 [ V_212 ] , 0 ) ;
F_7 ( & V_19 -> V_8 ) ;
if ( F_16 ( & V_19 -> V_205 [ V_212 ] ) )
F_17 ( & V_19 -> V_205 [ V_212 ] ) ;
V_12:
F_2 ( & V_4 -> V_8 ) ;
F_170 ( V_4 , V_211 , V_7 ) ;
V_4 -> V_207 ++ ;
F_174 ( & V_4 -> V_208 [ V_211 ] , 0 ) ;
F_7 ( & V_4 -> V_8 ) ;
if ( F_16 ( & V_4 -> V_205 [ V_211 ] ) )
F_17 ( & V_4 -> V_205 [ V_211 ] ) ;
return V_7 ;
}
static void F_191 ( struct V_1 * V_2 ,
struct V_3 * log )
{
int V_7 ;
T_1 V_36 ;
T_1 V_227 ;
struct V_30 V_31 = {
. free = 1 ,
. V_200 = F_18
} ;
V_7 = F_156 ( V_2 , log , & V_31 ) ;
if ( V_7 )
F_182 ( V_2 , V_7 ) ;
while ( 1 ) {
V_7 = F_192 ( & log -> V_221 ,
0 , & V_36 , & V_227 , V_219 | V_220 ,
NULL ) ;
if ( V_7 )
break;
F_193 ( & log -> V_221 , V_36 , V_227 ,
V_219 | V_220 ) ;
}
F_178 ( log , 0 ) ;
F_178 ( log , 1 ) ;
F_147 ( log -> V_201 ) ;
F_33 ( log ) ;
}
int F_194 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( V_4 -> V_9 ) {
F_191 ( V_2 , V_4 -> V_9 ) ;
V_4 -> V_9 = NULL ;
}
return 0 ;
}
int F_195 ( struct V_1 * V_2 ,
struct V_228 * V_10 )
{
if ( V_10 -> V_19 ) {
F_191 ( V_2 , V_10 -> V_19 ) ;
V_10 -> V_19 = NULL ;
}
return 0 ;
}
int F_196 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_109 , int V_110 ,
struct V_84 * V_106 , T_1 V_22 )
{
struct V_3 * log ;
struct V_107 * V_108 ;
struct V_40 * V_41 ;
int V_7 ;
int V_229 = 0 ;
int V_230 = 0 ;
T_1 V_231 = F_61 ( V_106 ) ;
if ( F_117 ( V_106 ) -> V_232 < V_2 -> V_79 )
return 0 ;
V_7 = F_11 ( V_4 ) ;
if ( V_7 )
return 0 ;
F_2 ( & F_117 ( V_106 ) -> V_8 ) ;
log = V_4 -> V_9 ;
V_41 = F_91 () ;
if ( ! V_41 ) {
V_229 = - V_63 ;
goto V_233;
}
V_108 = F_89 ( V_2 , log , V_41 , V_231 ,
V_109 , V_110 , - 1 ) ;
if ( F_88 ( V_108 ) ) {
V_229 = F_135 ( V_108 ) ;
goto V_234;
}
if ( V_108 ) {
V_7 = F_139 ( V_2 , log , V_41 , V_108 ) ;
V_230 += V_110 ;
if ( V_7 ) {
V_229 = V_7 ;
goto V_234;
}
}
F_31 ( V_41 ) ;
V_108 = F_87 ( V_2 , log , V_41 , V_231 ,
V_22 , V_109 , V_110 , - 1 ) ;
if ( F_88 ( V_108 ) ) {
V_229 = F_135 ( V_108 ) ;
goto V_234;
}
if ( V_108 ) {
V_7 = F_139 ( V_2 , log , V_41 , V_108 ) ;
V_230 += V_110 ;
if ( V_7 ) {
V_229 = V_7 ;
goto V_234;
}
}
if ( V_230 ) {
struct V_43 V_44 ;
V_44 . V_54 = V_231 ;
V_44 . V_82 = 0 ;
V_44 . type = V_52 ;
F_31 ( V_41 ) ;
V_7 = F_30 ( V_2 , log , & V_44 , V_41 , 0 , 1 ) ;
if ( V_7 < 0 ) {
V_229 = V_7 ;
goto V_234;
}
if ( V_7 == 0 ) {
struct V_64 * V_65 ;
T_1 V_161 ;
V_65 = F_35 ( V_41 -> V_59 [ 0 ] , V_41 -> V_60 [ 0 ] ,
struct V_64 ) ;
V_161 = F_45 ( V_41 -> V_59 [ 0 ] , V_65 ) ;
if ( V_161 > V_230 )
V_161 -= V_230 ;
else
V_161 = 0 ;
F_40 ( V_41 -> V_59 [ 0 ] , V_65 , V_161 ) ;
F_51 ( V_41 -> V_59 [ 0 ] ) ;
} else
V_7 = 0 ;
F_31 ( V_41 ) ;
}
V_234:
F_95 ( V_41 ) ;
V_233:
F_7 ( & F_117 ( V_106 ) -> V_8 ) ;
if ( V_7 == - V_222 ) {
F_183 ( V_4 -> V_10 , V_2 ) ;
V_7 = 0 ;
} else if ( V_7 < 0 )
F_182 ( V_2 , V_7 ) ;
F_14 ( V_4 ) ;
return V_229 ;
}
int F_197 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_109 , int V_110 ,
struct V_84 * V_84 , T_1 V_112 )
{
struct V_3 * log ;
T_1 V_22 ;
int V_7 ;
if ( F_117 ( V_84 ) -> V_232 < V_2 -> V_79 )
return 0 ;
V_7 = F_11 ( V_4 ) ;
if ( V_7 )
return 0 ;
log = V_4 -> V_9 ;
F_2 ( & F_117 ( V_84 ) -> V_8 ) ;
V_7 = F_198 ( V_2 , log , V_109 , V_110 , F_61 ( V_84 ) ,
V_112 , & V_22 ) ;
F_7 ( & F_117 ( V_84 ) -> V_8 ) ;
if ( V_7 == - V_222 ) {
F_183 ( V_4 -> V_10 , V_2 ) ;
V_7 = 0 ;
} else if ( V_7 < 0 && V_7 != - V_26 )
F_182 ( V_2 , V_7 ) ;
F_14 ( V_4 ) ;
return V_7 ;
}
static T_2 int F_199 ( struct V_1 * V_2 ,
struct V_3 * log ,
struct V_40 * V_41 ,
int V_165 , T_1 V_112 ,
T_1 V_235 , T_1 V_236 )
{
int V_7 ;
struct V_43 V_44 ;
struct V_169 * V_65 ;
V_44 . V_54 = V_112 ;
V_44 . V_82 = V_235 ;
if ( V_165 == V_159 )
V_44 . type = V_184 ;
else
V_44 . type = V_186 ;
V_7 = F_41 ( V_2 , log , V_41 , & V_44 , sizeof( * V_65 ) ) ;
if ( V_7 )
return V_7 ;
V_65 = F_35 ( V_41 -> V_59 [ 0 ] , V_41 -> V_60 [ 0 ] ,
struct V_169 ) ;
F_200 ( V_41 -> V_59 [ 0 ] , V_65 , V_236 ) ;
F_51 ( V_41 -> V_59 [ 0 ] ) ;
F_31 ( V_41 ) ;
return 0 ;
}
static T_2 int F_201 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_84 * V_84 ,
struct V_40 * V_41 ,
struct V_40 * V_237 , int V_165 ,
struct V_5 * V_6 ,
T_1 V_238 , T_1 * V_239 )
{
struct V_43 V_240 ;
struct V_3 * log = V_4 -> V_9 ;
struct V_28 * V_241 ;
int V_229 = 0 ;
int V_7 ;
int V_174 ;
int V_170 ;
T_1 V_235 = V_238 ;
T_1 V_236 = ( T_1 ) - 1 ;
T_1 V_143 = F_61 ( V_84 ) ;
log = V_4 -> V_9 ;
V_240 . V_54 = V_143 ;
V_240 . type = V_165 ;
V_240 . V_82 = V_238 ;
V_7 = F_202 ( V_4 , & V_240 , V_41 , V_2 -> V_79 ) ;
if ( V_7 != 0 || V_240 . V_54 != V_143 || V_240 . type != V_165 ) {
V_240 . V_54 = V_143 ;
V_240 . type = V_165 ;
V_240 . V_82 = ( T_1 ) - 1 ;
F_31 ( V_41 ) ;
V_7 = F_30 ( NULL , V_4 , & V_240 , V_41 , 0 , 0 ) ;
if ( V_7 < 0 ) {
F_31 ( V_41 ) ;
return V_7 ;
}
V_7 = F_203 ( V_4 , V_41 , V_143 , V_165 ) ;
if ( V_7 == 0 ) {
struct V_43 V_242 ;
F_114 ( V_41 -> V_59 [ 0 ] , & V_242 ,
V_41 -> V_60 [ 0 ] ) ;
if ( V_165 == V_242 . type )
V_235 = F_204 ( V_238 , V_242 . V_82 ) + 1 ;
}
goto V_243;
}
V_7 = F_203 ( V_4 , V_41 , V_143 , V_165 ) ;
if ( V_7 == 0 ) {
struct V_43 V_242 ;
F_114 ( V_41 -> V_59 [ 0 ] , & V_242 , V_41 -> V_60 [ 0 ] ) ;
if ( V_165 == V_242 . type ) {
V_235 = V_242 . V_82 ;
V_7 = F_27 ( V_2 , log , V_237 ,
V_41 -> V_59 [ 0 ] , V_41 -> V_60 [ 0 ] ,
& V_242 ) ;
if ( V_7 ) {
V_229 = V_7 ;
goto V_243;
}
}
}
F_31 ( V_41 ) ;
V_7 = F_30 ( NULL , V_4 , & V_240 , V_41 , 0 , 0 ) ;
if ( F_142 ( V_7 != 0 ) )
goto V_243;
while ( 1 ) {
struct V_43 V_242 ;
V_241 = V_41 -> V_59 [ 0 ] ;
V_170 = F_132 ( V_241 ) ;
for ( V_174 = V_41 -> V_60 [ 0 ] ; V_174 < V_170 ; V_174 ++ ) {
struct V_107 * V_108 ;
F_114 ( V_241 , & V_240 , V_174 ) ;
if ( V_240 . V_54 != V_143 || V_240 . type != V_165 )
goto V_243;
V_7 = F_27 ( V_2 , log , V_237 , V_241 , V_174 ,
& V_240 ) ;
if ( V_7 ) {
V_229 = V_7 ;
goto V_243;
}
V_108 = F_35 ( V_241 , V_174 , struct V_107 ) ;
F_81 ( V_241 , V_108 , & V_242 ) ;
if ( V_6 &&
( F_205 ( V_241 , V_108 ) == V_2 -> V_79 ||
F_125 ( V_241 , V_108 ) == V_163 ) &&
V_242 . type != V_244 )
V_6 -> V_245 = true ;
}
V_41 -> V_60 [ 0 ] = V_170 ;
V_7 = F_133 ( V_4 , V_41 ) ;
if ( V_7 == 1 ) {
V_236 = ( T_1 ) - 1 ;
goto V_243;
}
F_114 ( V_41 -> V_59 [ 0 ] , & V_242 , V_41 -> V_60 [ 0 ] ) ;
if ( V_242 . V_54 != V_143 || V_242 . type != V_165 ) {
V_236 = ( T_1 ) - 1 ;
goto V_243;
}
if ( F_155 ( V_41 -> V_59 [ 0 ] ) != V_2 -> V_79 ) {
V_7 = F_27 ( V_2 , log , V_237 ,
V_41 -> V_59 [ 0 ] , V_41 -> V_60 [ 0 ] ,
& V_242 ) ;
if ( V_7 )
V_229 = V_7 ;
else
V_236 = V_242 . V_82 ;
goto V_243;
}
}
V_243:
F_31 ( V_41 ) ;
F_31 ( V_237 ) ;
if ( V_229 == 0 ) {
* V_239 = V_236 ;
V_7 = F_199 ( V_2 , log , V_41 , V_165 ,
V_143 , V_235 , V_236 ) ;
if ( V_7 )
V_229 = V_7 ;
}
return V_229 ;
}
static T_2 int F_206 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_84 * V_84 ,
struct V_40 * V_41 ,
struct V_40 * V_237 ,
struct V_5 * V_6 )
{
T_1 V_240 ;
T_1 V_246 ;
int V_7 ;
int V_165 = V_159 ;
V_132:
V_240 = 0 ;
V_246 = 0 ;
while ( 1 ) {
V_7 = F_201 ( V_2 , V_4 , V_84 , V_41 ,
V_237 , V_165 , V_6 , V_240 ,
& V_246 ) ;
if ( V_7 )
return V_7 ;
if ( V_246 == ( T_1 ) - 1 )
break;
V_240 = V_246 + 1 ;
}
if ( V_165 == V_159 ) {
V_165 = V_157 ;
goto V_132;
}
return 0 ;
}
static int F_207 ( struct V_1 * V_2 ,
struct V_3 * log ,
struct V_40 * V_41 ,
T_1 V_54 , int V_247 )
{
int V_7 ;
struct V_43 V_44 ;
struct V_43 V_152 ;
int V_248 ;
V_44 . V_54 = V_54 ;
V_44 . type = V_247 ;
V_44 . V_82 = ( T_1 ) - 1 ;
while ( 1 ) {
V_7 = F_30 ( V_2 , log , & V_44 , V_41 , - 1 , 1 ) ;
F_208 ( V_7 == 0 ) ;
if ( V_7 < 0 )
break;
if ( V_41 -> V_60 [ 0 ] == 0 )
break;
V_41 -> V_60 [ 0 ] -- ;
F_114 ( V_41 -> V_59 [ 0 ] , & V_152 ,
V_41 -> V_60 [ 0 ] ) ;
if ( V_152 . V_54 != V_54 )
break;
V_152 . V_82 = 0 ;
V_152 . type = 0 ;
V_7 = F_209 ( V_41 -> V_59 [ 0 ] , & V_152 , 0 ,
& V_248 ) ;
V_7 = F_210 ( V_2 , log , V_41 , V_248 ,
V_41 -> V_60 [ 0 ] - V_248 + 1 ) ;
if ( V_7 || V_248 != 0 )
break;
F_31 ( V_41 ) ;
}
F_31 ( V_41 ) ;
if ( V_7 > 0 )
V_7 = 0 ;
return V_7 ;
}
static void F_211 ( struct V_1 * V_2 ,
struct V_28 * V_94 ,
struct V_64 * V_65 ,
struct V_84 * V_84 , int V_249 ,
T_1 V_250 )
{
struct V_76 V_77 ;
F_47 ( & V_77 ) ;
if ( V_249 ) {
F_212 ( V_94 , V_65 , 0 , & V_77 ) ;
F_48 ( V_94 , V_65 , V_250 , & V_77 ) ;
} else {
F_212 ( V_94 , V_65 ,
F_117 ( V_84 ) -> V_251 ,
& V_77 ) ;
F_48 ( V_94 , V_65 , V_84 -> V_161 , & V_77 ) ;
}
F_213 ( V_94 , V_65 , F_214 ( V_84 ) , & V_77 ) ;
F_215 ( V_94 , V_65 , F_216 ( V_84 ) , & V_77 ) ;
F_217 ( V_94 , V_65 , V_84 -> V_148 , & V_77 ) ;
F_218 ( V_94 , V_65 , V_84 -> V_146 , & V_77 ) ;
F_219 ( V_94 , & V_65 -> V_252 ,
V_84 -> V_253 . V_254 , & V_77 ) ;
F_220 ( V_94 , & V_65 -> V_252 ,
V_84 -> V_253 . V_255 , & V_77 ) ;
F_219 ( V_94 , & V_65 -> V_256 ,
V_84 -> V_257 . V_254 , & V_77 ) ;
F_220 ( V_94 , & V_65 -> V_256 ,
V_84 -> V_257 . V_255 , & V_77 ) ;
F_219 ( V_94 , & V_65 -> ctime ,
V_84 -> V_258 . V_254 , & V_77 ) ;
F_220 ( V_94 , & V_65 -> ctime ,
V_84 -> V_258 . V_255 , & V_77 ) ;
F_221 ( V_94 , V_65 , F_222 ( V_84 ) ,
& V_77 ) ;
F_223 ( V_94 , V_65 , V_84 -> V_259 , & V_77 ) ;
F_224 ( V_94 , V_65 , V_2 -> V_79 , & V_77 ) ;
F_225 ( V_94 , V_65 , V_84 -> V_260 , & V_77 ) ;
F_226 ( V_94 , V_65 , F_117 ( V_84 ) -> V_261 , & V_77 ) ;
F_227 ( V_94 , V_65 , 0 , & V_77 ) ;
}
static int F_228 ( struct V_1 * V_2 ,
struct V_3 * log , struct V_40 * V_41 ,
struct V_84 * V_84 )
{
struct V_64 * V_51 ;
int V_7 ;
V_7 = F_41 ( V_2 , log , V_41 ,
& F_117 ( V_84 ) -> V_111 ,
sizeof( * V_51 ) ) ;
if ( V_7 && V_7 != - V_69 )
return V_7 ;
V_51 = F_35 ( V_41 -> V_59 [ 0 ] , V_41 -> V_60 [ 0 ] ,
struct V_64 ) ;
F_211 ( V_2 , V_41 -> V_59 [ 0 ] , V_51 , V_84 , 0 , 0 ) ;
F_31 ( V_41 ) ;
return 0 ;
}
static T_2 int F_229 ( struct V_1 * V_2 ,
struct V_84 * V_84 ,
struct V_40 * V_237 ,
struct V_40 * V_262 , T_1 * V_263 ,
int V_248 , int V_264 , int V_265 ,
T_1 V_250 )
{
unsigned long V_266 ;
unsigned long V_267 ;
struct V_3 * log = F_117 ( V_84 ) -> V_4 -> V_9 ;
struct V_83 * V_268 ;
struct V_64 * V_51 ;
struct V_28 * V_241 = V_262 -> V_59 [ 0 ] ;
struct V_43 V_269 , V_270 , V_44 ;
int V_7 ;
struct V_43 * V_271 ;
T_3 * V_272 ;
char * V_273 ;
int V_174 ;
struct V_274 V_100 ;
int V_275 = F_117 ( V_84 ) -> V_261 & V_276 ;
bool V_277 = false ;
bool V_278 = true ;
bool V_243 = false ;
F_172 ( & V_100 ) ;
V_273 = F_32 ( V_264 * sizeof( struct V_43 ) +
V_264 * sizeof( T_3 ) , V_62 ) ;
if ( ! V_273 )
return - V_63 ;
V_269 . V_54 = ( T_1 ) - 1 ;
V_272 = ( T_3 * ) V_273 ;
V_271 = (struct V_43 * ) ( V_273 + V_264 * sizeof( T_3 ) ) ;
for ( V_174 = 0 ; V_174 < V_264 ; V_174 ++ ) {
V_272 [ V_174 ] = F_28 ( V_241 , V_174 + V_248 ) ;
F_114 ( V_241 , V_271 + V_174 , V_174 + V_248 ) ;
}
V_7 = F_230 ( V_2 , log , V_237 ,
V_271 , V_272 , V_264 ) ;
if ( V_7 ) {
F_33 ( V_273 ) ;
return V_7 ;
}
for ( V_174 = 0 ; V_174 < V_264 ; V_174 ++ , V_237 -> V_60 [ 0 ] ++ ) {
V_267 = F_29 ( V_237 -> V_59 [ 0 ] ,
V_237 -> V_60 [ 0 ] ) ;
V_266 = F_29 ( V_241 , V_248 + V_174 ) ;
if ( ( V_174 == ( V_264 - 1 ) ) )
V_270 = V_271 [ V_174 ] ;
if ( V_271 [ V_174 ] . type == V_52 ) {
V_51 = F_35 ( V_237 -> V_59 [ 0 ] ,
V_237 -> V_60 [ 0 ] ,
struct V_64 ) ;
F_211 ( V_2 , V_237 -> V_59 [ 0 ] , V_51 ,
V_84 , V_265 == V_279 ,
V_250 ) ;
} else {
F_49 ( V_237 -> V_59 [ 0 ] , V_241 , V_267 ,
V_266 , V_272 [ V_174 ] ) ;
}
if ( V_271 [ V_174 ] . type == V_193 ) {
V_277 = true ;
if ( V_269 . V_54 == ( T_1 ) - 1 )
V_269 = V_271 [ V_174 ] ;
} else {
V_278 = false ;
}
if ( V_271 [ V_174 ] . type == V_193 &&
! V_275 ) {
int V_80 ;
V_268 = F_35 ( V_241 , V_248 + V_174 ,
struct V_83 ) ;
if ( F_231 ( V_241 , V_268 ) < V_2 -> V_79 )
continue;
V_80 = F_53 ( V_241 , V_268 ) ;
if ( V_80 == V_86 ) {
T_1 V_280 , V_281 , V_282 , V_283 ;
V_280 = F_55 ( V_241 ,
V_268 ) ;
if ( V_280 == 0 )
continue;
V_281 = F_63 ( V_241 ,
V_268 ) ;
V_282 = F_64 ( V_241 , V_268 ) ;
V_283 = F_54 ( V_241 ,
V_268 ) ;
if ( F_70 ( V_241 ,
V_268 ) ) {
V_282 = 0 ;
V_283 = V_281 ;
}
V_7 = F_71 (
log -> V_10 -> V_104 ,
V_280 + V_282 , V_280 + V_282 + V_283 - 1 ,
& V_100 , 0 ) ;
if ( V_7 ) {
F_31 ( V_237 ) ;
F_33 ( V_273 ) ;
return V_7 ;
}
}
}
}
F_51 ( V_237 -> V_59 [ 0 ] ) ;
F_31 ( V_237 ) ;
F_33 ( V_273 ) ;
V_7 = 0 ;
while ( ! F_72 ( & V_100 ) ) {
struct V_101 * V_102 = F_73 ( V_100 . V_103 ,
struct V_101 ,
V_24 ) ;
if ( ! V_7 )
V_7 = F_75 ( V_2 , log , V_102 ) ;
F_76 ( & V_102 -> V_24 ) ;
F_33 ( V_102 ) ;
}
if ( ! V_277 )
return V_7 ;
if ( V_278 && * V_263 == V_269 . V_82 ) {
V_278 = false ;
}
if ( V_278 ) {
T_1 V_37 ;
V_7 = F_232 ( F_117 ( V_84 ) -> V_4 , V_262 ) ;
if ( V_7 < 0 )
return V_7 ;
if ( V_7 )
goto V_284;
if ( V_262 -> V_60 [ 0 ] )
V_262 -> V_60 [ 0 ] -- ;
V_241 = V_262 -> V_59 [ 0 ] ;
F_114 ( V_241 , & V_44 , V_262 -> V_60 [ 0 ] ) ;
if ( V_44 . V_54 != F_61 ( V_84 ) ||
V_44 . type != V_193 )
goto V_284;
V_268 = F_35 ( V_241 , V_262 -> V_60 [ 0 ] ,
struct V_83 ) ;
if ( F_53 ( V_241 , V_268 ) ==
V_88 ) {
V_37 = F_56 ( V_241 ,
V_262 -> V_60 [ 0 ] ,
V_268 ) ;
* V_263 = F_58 ( V_44 . V_82 + V_37 ,
log -> V_89 ) ;
} else {
V_37 = F_54 ( V_241 , V_268 ) ;
* V_263 = V_44 . V_82 + V_37 ;
}
}
V_284:
if ( V_278 ) {
F_31 ( V_262 ) ;
V_7 = F_30 ( NULL , F_117 ( V_84 ) -> V_4 , & V_269 ,
V_262 , 0 , 0 ) ;
if ( V_7 < 0 )
return V_7 ;
ASSERT ( V_7 == 0 ) ;
V_241 = V_262 -> V_59 [ 0 ] ;
V_174 = V_262 -> V_60 [ 0 ] ;
} else {
V_174 = V_248 ;
}
while ( ! V_243 ) {
T_1 V_82 , V_37 ;
T_1 V_81 ;
if ( V_174 >= F_132 ( V_262 -> V_59 [ 0 ] ) ) {
V_7 = F_133 ( F_117 ( V_84 ) -> V_4 , V_262 ) ;
if ( V_7 < 0 )
return V_7 ;
ASSERT ( V_7 == 0 ) ;
V_241 = V_262 -> V_59 [ 0 ] ;
V_174 = 0 ;
}
F_114 ( V_241 , & V_44 , V_174 ) ;
if ( ! F_233 ( & V_44 , & V_270 ) )
V_243 = true ;
if ( V_44 . V_54 != F_61 ( V_84 ) ||
V_44 . type != V_193 ) {
V_174 ++ ;
continue;
}
V_268 = F_35 ( V_241 , V_174 , struct V_83 ) ;
if ( F_53 ( V_241 , V_268 ) ==
V_88 ) {
V_37 = F_56 ( V_241 , V_174 , V_268 ) ;
V_81 = F_58 ( V_44 . V_82 + V_37 , log -> V_89 ) ;
} else {
V_37 = F_54 ( V_241 , V_268 ) ;
V_81 = V_44 . V_82 + V_37 ;
}
V_174 ++ ;
if ( * V_263 == V_44 . V_82 ) {
* V_263 = V_81 ;
continue;
}
V_82 = * V_263 ;
V_37 = V_44 . V_82 - * V_263 ;
V_7 = F_234 ( V_2 , log , F_61 ( V_84 ) ,
V_82 , 0 , 0 , V_37 , 0 , V_37 , 0 ,
0 , 0 ) ;
if ( V_7 )
break;
* V_263 = V_81 ;
}
if ( ! V_7 && V_278 )
V_7 = 1 ;
return V_7 ;
}
static int F_235 ( void * V_285 , struct V_274 * V_286 , struct V_274 * V_287 )
{
struct V_288 * V_289 , * V_290 ;
V_289 = F_73 ( V_286 , struct V_288 , V_24 ) ;
V_290 = F_73 ( V_287 , struct V_288 , V_24 ) ;
if ( V_289 -> V_36 < V_290 -> V_36 )
return - 1 ;
else if ( V_289 -> V_36 > V_290 -> V_36 )
return 1 ;
return 0 ;
}
static int F_236 ( struct V_1 * V_2 ,
struct V_84 * V_84 ,
struct V_3 * V_4 ,
const struct V_288 * V_291 ,
const struct V_274 * V_292 ,
bool * V_293 )
{
struct V_294 * V_295 ;
struct V_3 * log = V_4 -> V_9 ;
T_1 V_296 = V_291 -> V_296 ;
T_1 V_297 = V_291 -> V_297 ;
const bool V_275 = F_117 ( V_84 ) -> V_261 & V_276 ;
T_1 V_298 ;
T_1 V_299 ;
F_66 ( V_100 ) ;
int V_7 = 0 ;
* V_293 = false ;
if ( F_176 ( V_300 , & V_291 -> V_261 ) ||
V_291 -> V_301 == V_302 )
return 0 ;
F_237 (ordered, logged_list, log_list) {
struct V_101 * V_303 ;
if ( ! V_297 )
break;
if ( V_295 -> V_304 + V_295 -> V_37 <= V_296 ||
V_296 + V_297 <= V_295 -> V_304 )
continue;
if ( ! F_176 ( V_305 , & V_295 -> V_261 ) &&
! F_176 ( V_306 , & V_295 -> V_261 ) &&
! F_176 ( V_307 , & V_295 -> V_261 ) ) {
const T_1 V_36 = V_295 -> V_304 ;
const T_1 V_227 = V_295 -> V_304 + V_295 -> V_37 - 1 ;
F_142 ( V_295 -> V_84 != V_84 ) ;
F_238 ( V_84 -> V_308 , V_36 , V_227 ) ;
}
F_239 ( V_295 -> V_39 ,
( F_176 ( V_305 , & V_295 -> V_261 ) ||
F_176 ( V_306 , & V_295 -> V_261 ) ) ) ;
if ( F_176 ( V_306 , & V_295 -> V_261 ) ) {
F_240 ( V_84 -> V_308 ) ;
* V_293 = true ;
break;
}
if ( V_295 -> V_304 > V_296 ) {
if ( V_295 -> V_304 + V_295 -> V_37 >=
V_296 + V_297 )
V_297 = V_295 -> V_304 - V_296 ;
} else {
if ( V_295 -> V_304 + V_295 -> V_37 <
V_296 + V_297 ) {
V_297 = ( V_296 + V_297 ) -
( V_295 -> V_304 + V_295 -> V_37 ) ;
V_296 = V_295 -> V_304 +
V_295 -> V_37 ;
} else {
V_297 = 0 ;
}
}
if ( V_275 )
continue;
if ( F_241 ( V_309 ,
& V_295 -> V_261 ) )
continue;
F_237 (sum, &ordered->list, list) {
V_7 = F_75 ( V_2 , log , V_303 ) ;
if ( V_7 )
break;
}
}
if ( * V_293 || ! V_297 || V_7 || V_275 )
return V_7 ;
if ( V_291 -> V_310 ) {
V_298 = 0 ;
V_299 = F_204 ( V_291 -> V_311 , V_291 -> V_312 ) ;
} else {
V_298 = V_296 - V_291 -> V_36 ;
V_299 = V_297 ;
}
V_7 = F_71 ( log -> V_10 -> V_104 ,
V_291 -> V_301 + V_298 ,
V_291 -> V_301 + V_298 +
V_299 - 1 , & V_100 , 0 ) ;
if ( V_7 )
return V_7 ;
while ( ! F_72 ( & V_100 ) ) {
struct V_101 * V_102 = F_73 ( V_100 . V_103 ,
struct V_101 ,
V_24 ) ;
if ( ! V_7 )
V_7 = F_75 ( V_2 , log , V_102 ) ;
F_76 ( & V_102 -> V_24 ) ;
F_33 ( V_102 ) ;
}
return V_7 ;
}
static int F_242 ( struct V_1 * V_2 ,
struct V_84 * V_84 , struct V_3 * V_4 ,
const struct V_288 * V_291 ,
struct V_40 * V_41 ,
const struct V_274 * V_292 ,
struct V_5 * V_6 )
{
struct V_3 * log = V_4 -> V_9 ;
struct V_83 * V_313 ;
struct V_28 * V_94 ;
struct V_76 V_77 ;
struct V_43 V_44 ;
T_1 V_314 = V_291 -> V_36 - V_291 -> V_315 ;
T_1 V_311 ;
int V_7 ;
int V_316 = 0 ;
bool V_317 = false ;
V_7 = F_236 ( V_2 , V_84 , V_4 , V_291 , V_292 ,
& V_317 ) ;
if ( V_7 )
return V_7 ;
if ( V_317 ) {
V_6 -> V_318 = - V_90 ;
return 0 ;
}
F_47 ( & V_77 ) ;
V_7 = F_243 ( V_2 , log , V_84 , V_41 , V_291 -> V_36 ,
V_291 -> V_36 + V_291 -> V_37 , NULL , 0 , 1 ,
sizeof( * V_313 ) , & V_316 ) ;
if ( V_7 )
return V_7 ;
if ( ! V_316 ) {
V_44 . V_54 = F_61 ( V_84 ) ;
V_44 . type = V_193 ;
V_44 . V_82 = V_291 -> V_36 ;
V_7 = F_41 ( V_2 , log , V_41 , & V_44 ,
sizeof( * V_313 ) ) ;
if ( V_7 )
return V_7 ;
}
V_94 = V_41 -> V_59 [ 0 ] ;
V_313 = F_35 ( V_94 , V_41 -> V_60 [ 0 ] ,
struct V_83 ) ;
F_244 ( V_94 , V_313 , V_2 -> V_79 ,
& V_77 ) ;
if ( F_176 ( V_300 , & V_291 -> V_261 ) )
F_245 ( V_94 , V_313 ,
V_87 ,
& V_77 ) ;
else
F_245 ( V_94 , V_313 ,
V_86 ,
& V_77 ) ;
V_311 = F_204 ( V_291 -> V_311 , V_291 -> V_312 ) ;
if ( V_291 -> V_310 != V_319 ) {
F_246 ( V_94 , V_313 ,
V_291 -> V_301 ,
& V_77 ) ;
F_247 ( V_94 , V_313 , V_311 ,
& V_77 ) ;
} else if ( V_291 -> V_301 < V_320 ) {
F_246 ( V_94 , V_313 ,
V_291 -> V_301 -
V_314 , & V_77 ) ;
F_247 ( V_94 , V_313 , V_311 ,
& V_77 ) ;
} else {
F_246 ( V_94 , V_313 , 0 , & V_77 ) ;
F_247 ( V_94 , V_313 , 0 ,
& V_77 ) ;
}
F_248 ( V_94 , V_313 , V_314 , & V_77 ) ;
F_249 ( V_94 , V_313 , V_291 -> V_37 , & V_77 ) ;
F_250 ( V_94 , V_313 , V_291 -> V_321 , & V_77 ) ;
F_251 ( V_94 , V_313 , V_291 -> V_310 ,
& V_77 ) ;
F_252 ( V_94 , V_313 , 0 , & V_77 ) ;
F_253 ( V_94 , V_313 , 0 , & V_77 ) ;
F_51 ( V_94 ) ;
F_31 ( V_41 ) ;
return V_7 ;
}
static int F_254 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_84 * V_84 ,
struct V_40 * V_41 ,
struct V_274 * V_292 ,
struct V_5 * V_6 ,
const T_1 V_36 ,
const T_1 V_227 )
{
struct V_288 * V_291 , * V_322 ;
struct V_274 V_323 ;
struct V_324 * V_325 = & F_117 ( V_84 ) -> V_326 ;
T_1 V_327 ;
int V_7 = 0 ;
int V_328 = 0 ;
F_172 ( & V_323 ) ;
F_255 ( & F_117 ( V_84 ) -> V_329 ) ;
F_256 ( & V_325 -> V_330 ) ;
V_327 = V_4 -> V_10 -> V_331 ;
F_171 (em, n, &tree->modified_extents, list) {
F_169 ( & V_291 -> V_24 ) ;
if ( ++ V_328 > 32768 ) {
F_169 ( & V_325 -> V_332 ) ;
V_7 = - V_333 ;
goto V_334;
}
if ( V_291 -> V_251 <= V_327 )
continue;
F_9 ( & V_291 -> V_335 ) ;
F_5 ( V_336 , & V_291 -> V_261 ) ;
F_10 ( & V_291 -> V_24 , & V_323 ) ;
V_328 ++ ;
}
F_257 ( NULL , & V_323 , F_235 ) ;
F_258 ( V_84 , V_292 , V_36 , V_227 ) ;
V_7 = F_240 ( V_84 -> V_308 ) ;
if ( V_7 )
V_6 -> V_318 = V_7 ;
V_334:
while ( ! F_72 ( & V_323 ) ) {
V_291 = F_73 ( V_323 . V_103 , struct V_288 , V_24 ) ;
F_169 ( & V_291 -> V_24 ) ;
if ( V_7 ) {
F_259 ( V_325 , V_291 ) ;
F_260 ( V_291 ) ;
continue;
}
F_261 ( & V_325 -> V_330 ) ;
V_7 = F_242 ( V_2 , V_84 , V_4 , V_291 , V_41 , V_292 ,
V_6 ) ;
F_256 ( & V_325 -> V_330 ) ;
F_259 ( V_325 , V_291 ) ;
F_260 ( V_291 ) ;
}
F_142 ( ! F_72 ( & V_323 ) ) ;
F_261 ( & V_325 -> V_330 ) ;
F_262 ( & F_117 ( V_84 ) -> V_329 ) ;
F_31 ( V_41 ) ;
return V_7 ;
}
static int F_263 ( struct V_3 * log , struct V_84 * V_84 ,
struct V_40 * V_41 , T_1 * V_337 )
{
struct V_43 V_44 ;
int V_7 ;
V_44 . V_54 = F_61 ( V_84 ) ;
V_44 . type = V_52 ;
V_44 . V_82 = 0 ;
V_7 = F_30 ( NULL , log , & V_44 , V_41 , 0 , 0 ) ;
if ( V_7 < 0 ) {
return V_7 ;
} else if ( V_7 > 0 ) {
* V_337 = 0 ;
} else {
struct V_64 * V_65 ;
V_65 = F_35 ( V_41 -> V_59 [ 0 ] , V_41 -> V_60 [ 0 ] ,
struct V_64 ) ;
* V_337 = F_45 ( V_41 -> V_59 [ 0 ] , V_65 ) ;
}
F_31 ( V_41 ) ;
return 0 ;
}
static int F_264 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_84 * V_84 ,
struct V_40 * V_41 ,
struct V_40 * V_237 )
{
int V_7 ;
struct V_43 V_44 ;
const T_1 V_143 = F_61 ( V_84 ) ;
int V_338 = 0 ;
int V_248 = 0 ;
V_44 . V_54 = V_143 ;
V_44 . type = V_175 ;
V_44 . V_82 = 0 ;
V_7 = F_30 ( NULL , V_4 , & V_44 , V_41 , 0 , 0 ) ;
if ( V_7 < 0 )
return V_7 ;
while ( true ) {
int V_42 = V_41 -> V_60 [ 0 ] ;
struct V_28 * V_94 = V_41 -> V_59 [ 0 ] ;
int V_170 = F_132 ( V_94 ) ;
if ( V_42 >= V_170 ) {
if ( V_338 > 0 ) {
T_1 V_263 = 0 ;
V_7 = F_229 ( V_2 , V_84 , V_237 , V_41 ,
& V_263 , V_248 ,
V_338 , 1 , 0 ) ;
ASSERT ( V_7 <= 0 ) ;
if ( V_7 < 0 )
return V_7 ;
V_338 = 0 ;
}
V_7 = F_133 ( V_4 , V_41 ) ;
if ( V_7 < 0 )
return V_7 ;
else if ( V_7 > 0 )
break;
continue;
}
F_114 ( V_94 , & V_44 , V_42 ) ;
if ( V_44 . V_54 != V_143 || V_44 . type != V_175 )
break;
if ( V_338 == 0 )
V_248 = V_42 ;
V_338 ++ ;
V_41 -> V_60 [ 0 ] ++ ;
F_153 () ;
}
if ( V_338 > 0 ) {
T_1 V_263 = 0 ;
V_7 = F_229 ( V_2 , V_84 , V_237 , V_41 ,
& V_263 , V_248 ,
V_338 , 1 , 0 ) ;
ASSERT ( V_7 <= 0 ) ;
if ( V_7 < 0 )
return V_7 ;
}
return 0 ;
}
static int F_265 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_84 * V_84 ,
struct V_40 * V_41 )
{
int V_7 ;
struct V_43 V_44 ;
T_1 V_339 ;
T_1 V_340 ;
struct V_28 * V_94 ;
struct V_3 * log = V_4 -> V_9 ;
const T_1 V_143 = F_61 ( V_84 ) ;
const T_1 V_161 = F_266 ( V_84 ) ;
if ( ! F_19 ( V_4 -> V_10 , V_341 ) )
return 0 ;
V_44 . V_54 = V_143 ;
V_44 . type = V_193 ;
V_44 . V_82 = ( T_1 ) - 1 ;
V_7 = F_30 ( NULL , V_4 , & V_44 , V_41 , 0 , 0 ) ;
ASSERT ( V_7 != 0 ) ;
if ( V_7 < 0 )
return V_7 ;
ASSERT ( V_41 -> V_60 [ 0 ] > 0 ) ;
V_41 -> V_60 [ 0 ] -- ;
V_94 = V_41 -> V_59 [ 0 ] ;
F_114 ( V_94 , & V_44 , V_41 -> V_60 [ 0 ] ) ;
if ( V_44 . V_54 != V_143 || V_44 . type != V_193 ) {
V_339 = 0 ;
V_340 = V_161 ;
} else {
struct V_83 * V_268 ;
T_1 V_37 ;
if ( V_44 . V_82 >= V_161 )
return 0 ;
V_268 = F_35 ( V_94 , V_41 -> V_60 [ 0 ] ,
struct V_83 ) ;
if ( F_53 ( V_94 , V_268 ) ==
V_88 ) {
V_37 = F_56 ( V_94 ,
V_41 -> V_60 [ 0 ] ,
V_268 ) ;
ASSERT ( V_37 == V_161 ) ;
return 0 ;
}
V_37 = F_54 ( V_94 , V_268 ) ;
if ( V_44 . V_82 + V_37 > V_161 )
return 0 ;
V_339 = V_44 . V_82 + V_37 ;
V_340 = V_161 - V_339 ;
}
F_31 ( V_41 ) ;
if ( V_340 == 0 )
return 0 ;
V_340 = F_58 ( V_340 , V_4 -> V_89 ) ;
V_7 = F_234 ( V_2 , log , V_143 , V_339 , 0 , 0 ,
V_340 , 0 , V_340 , 0 , 0 , 0 ) ;
return V_7 ;
}
static int F_267 ( struct V_28 * V_29 ,
const int V_42 ,
const struct V_43 * V_44 ,
struct V_84 * V_84 ,
T_1 * V_342 )
{
int V_7 ;
struct V_40 * V_343 ;
char * V_109 = NULL ;
T_3 V_110 = 0 ;
T_3 V_45 = F_28 ( V_29 , V_42 ) ;
T_3 V_135 = 0 ;
unsigned long V_118 = F_29 ( V_29 , V_42 ) ;
V_343 = F_91 () ;
if ( ! V_343 )
return - V_63 ;
V_343 -> V_344 = 1 ;
V_343 -> V_345 = 1 ;
while ( V_135 < V_45 ) {
T_1 V_196 ;
T_3 V_346 ;
T_3 V_180 ;
unsigned long V_120 ;
struct V_107 * V_108 ;
if ( V_44 -> type == V_133 ) {
struct V_116 * V_347 ;
V_347 = (struct V_116 * ) ( V_118 + V_135 ) ;
V_196 = V_44 -> V_82 ;
V_346 = F_93 ( V_29 , V_347 ) ;
V_120 = ( unsigned long ) ( V_347 + 1 ) ;
V_180 = sizeof( * V_347 ) + V_346 ;
} else {
struct V_130 * V_131 ;
V_131 = (struct V_130 * ) ( V_118 +
V_135 ) ;
V_196 = F_101 ( V_29 , V_131 ) ;
V_346 = F_100 ( V_29 , V_131 ) ;
V_120 = ( unsigned long ) & V_131 -> V_109 ;
V_180 = sizeof( * V_131 ) + V_346 ;
}
if ( V_346 > V_110 ) {
char * V_348 ;
V_348 = F_268 ( V_109 , V_346 , V_62 ) ;
if ( ! V_348 ) {
V_7 = - V_63 ;
goto V_12;
}
V_110 = V_346 ;
V_109 = V_348 ;
}
F_34 ( V_29 , V_109 , V_120 , V_346 ) ;
V_108 = F_89 ( NULL , F_117 ( V_84 ) -> V_4 ,
V_343 , V_196 ,
V_109 , V_346 , 0 ) ;
if ( V_108 && ! F_88 ( V_108 ) ) {
struct V_43 V_164 ;
F_81 ( V_343 -> V_59 [ 0 ] ,
V_108 , & V_164 ) ;
if ( V_164 . type == V_52 ) {
V_7 = 1 ;
* V_342 = V_164 . V_54 ;
} else {
V_7 = - V_11 ;
}
goto V_12;
} else if ( F_88 ( V_108 ) ) {
V_7 = F_135 ( V_108 ) ;
goto V_12;
}
F_31 ( V_343 ) ;
V_135 += V_180 ;
}
V_7 = 0 ;
V_12:
F_95 ( V_343 ) ;
F_33 ( V_109 ) ;
return V_7 ;
}
static int F_269 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_84 * V_84 ,
int V_265 ,
const T_6 V_36 ,
const T_6 V_227 ,
struct V_5 * V_6 )
{
struct V_40 * V_41 ;
struct V_40 * V_237 ;
struct V_43 V_240 ;
struct V_43 V_246 ;
struct V_3 * log = V_4 -> V_9 ;
struct V_28 * V_241 = NULL ;
F_66 ( V_292 ) ;
T_1 V_263 = 0 ;
int V_229 = 0 ;
int V_7 ;
int V_170 ;
int V_349 = 0 ;
int V_338 ;
bool V_350 = false ;
T_1 V_143 = F_61 ( V_84 ) ;
struct V_324 * V_351 = & F_117 ( V_84 ) -> V_326 ;
T_1 V_250 = 0 ;
bool V_352 = true ;
V_41 = F_91 () ;
if ( ! V_41 )
return - V_63 ;
V_237 = F_91 () ;
if ( ! V_237 ) {
F_95 ( V_41 ) ;
return - V_63 ;
}
V_240 . V_54 = V_143 ;
V_240 . type = V_52 ;
V_240 . V_82 = 0 ;
V_246 . V_54 = V_143 ;
if ( F_39 ( V_84 -> V_148 ) ||
( ! F_176 ( V_353 ,
& F_117 ( V_84 ) -> V_354 ) &&
V_265 == V_279 ) )
V_246 . type = V_175 ;
else
V_246 . type = ( T_4 ) - 1 ;
V_246 . V_82 = ( T_1 ) - 1 ;
if ( F_39 ( V_84 -> V_148 ) ||
F_117 ( V_84 ) -> V_251 > V_4 -> V_10 -> V_331 )
V_7 = F_270 ( V_2 , V_84 ) ;
else
V_7 = F_271 ( V_84 ) ;
if ( V_7 ) {
F_95 ( V_41 ) ;
F_95 ( V_237 ) ;
return V_7 ;
}
F_2 ( & F_117 ( V_84 ) -> V_8 ) ;
if ( F_39 ( V_84 -> V_148 ) ) {
int V_247 = V_186 ;
if ( V_265 == V_279 )
V_247 = V_175 ;
V_7 = F_207 ( V_2 , log , V_41 , V_143 , V_247 ) ;
} else {
if ( V_265 == V_279 ) {
V_229 = F_263 ( log , V_84 , V_41 ,
& V_250 ) ;
if ( V_229 )
goto V_233;
}
if ( F_176 ( V_353 ,
& F_117 ( V_84 ) -> V_354 ) ) {
if ( V_265 == V_279 ) {
V_246 . type = V_175 ;
V_7 = F_207 ( V_2 , log , V_41 , V_143 ,
V_246 . type ) ;
} else {
F_4 ( V_353 ,
& F_117 ( V_84 ) -> V_354 ) ;
F_4 ( V_355 ,
& F_117 ( V_84 ) -> V_354 ) ;
while( 1 ) {
V_7 = F_272 ( V_2 ,
log , V_84 , 0 , 0 ) ;
if ( V_7 != - V_11 )
break;
}
}
} else if ( F_273 ( V_355 ,
& F_117 ( V_84 ) -> V_354 ) ||
V_265 == V_279 ) {
if ( V_265 == V_356 )
V_350 = true ;
V_246 . type = V_175 ;
V_7 = F_207 ( V_2 , log , V_41 , V_143 ,
V_246 . type ) ;
} else {
if ( V_265 == V_356 )
V_350 = true ;
goto V_357;
}
}
if ( V_7 ) {
V_229 = V_7 ;
goto V_233;
}
while ( 1 ) {
V_338 = 0 ;
V_7 = F_202 ( V_4 , & V_240 ,
V_41 , V_2 -> V_79 ) ;
if ( V_7 < 0 ) {
V_229 = V_7 ;
goto V_233;
}
if ( V_7 != 0 )
break;
V_132:
if ( V_240 . V_54 != V_143 )
break;
if ( V_240 . type > V_246 . type )
break;
if ( V_240 . type == V_52 )
V_352 = false ;
if ( ( V_240 . type == V_133 ||
V_240 . type == V_122 ) &&
F_117 ( V_84 ) -> V_251 == V_2 -> V_79 ) {
T_1 V_342 = 0 ;
V_7 = F_267 ( V_41 -> V_59 [ 0 ] ,
V_41 -> V_60 [ 0 ] ,
& V_240 , V_84 ,
& V_342 ) ;
if ( V_7 < 0 ) {
V_229 = V_7 ;
goto V_233;
} else if ( V_7 > 0 && V_6 &&
V_342 != F_61 ( V_6 -> V_84 ) ) {
struct V_43 V_358 ;
struct V_84 * V_359 ;
if ( V_338 > 0 ) {
V_338 ++ ;
} else {
V_338 = 1 ;
V_349 = V_41 -> V_60 [ 0 ] ;
}
V_7 = F_229 ( V_2 , V_84 , V_237 , V_41 ,
& V_263 , V_349 ,
V_338 , V_265 ,
V_250 ) ;
if ( V_7 < 0 ) {
V_229 = V_7 ;
goto V_233;
}
V_338 = 0 ;
F_31 ( V_41 ) ;
V_358 . V_54 = V_342 ;
V_358 . type = V_52 ;
V_358 . V_82 = 0 ;
V_359 = F_274 ( V_4 -> V_10 -> V_360 ,
& V_358 , V_4 ,
NULL ) ;
if ( F_88 ( V_359 ) &&
F_135 ( V_359 ) == - V_26 ) {
goto V_361;
} else if ( F_88 ( V_359 ) ) {
V_229 = F_135 ( V_359 ) ;
goto V_233;
}
V_229 = F_269 ( V_2 , V_4 , V_359 ,
V_279 ,
0 , V_362 , V_6 ) ;
F_79 ( V_359 ) ;
if ( V_229 )
goto V_233;
else
goto V_361;
}
}
if ( V_240 . type == V_175 ) {
if ( V_338 == 0 )
goto V_363;
V_7 = F_229 ( V_2 , V_84 , V_237 , V_41 ,
& V_263 , V_349 ,
V_338 , V_265 , V_250 ) ;
if ( V_7 < 0 ) {
V_229 = V_7 ;
goto V_233;
}
V_338 = 0 ;
if ( V_7 ) {
F_31 ( V_41 ) ;
continue;
}
goto V_363;
}
V_241 = V_41 -> V_59 [ 0 ] ;
if ( V_338 && V_349 + V_338 == V_41 -> V_60 [ 0 ] ) {
V_338 ++ ;
goto V_363;
} else if ( ! V_338 ) {
V_349 = V_41 -> V_60 [ 0 ] ;
V_338 = 1 ;
goto V_363;
}
V_7 = F_229 ( V_2 , V_84 , V_237 , V_41 , & V_263 ,
V_349 , V_338 , V_265 ,
V_250 ) ;
if ( V_7 < 0 ) {
V_229 = V_7 ;
goto V_233;
}
if ( V_7 ) {
V_338 = 0 ;
F_31 ( V_41 ) ;
continue;
}
V_338 = 1 ;
V_349 = V_41 -> V_60 [ 0 ] ;
V_363:
V_170 = F_132 ( V_41 -> V_59 [ 0 ] ) ;
V_41 -> V_60 [ 0 ] ++ ;
if ( V_41 -> V_60 [ 0 ] < V_170 ) {
F_114 ( V_41 -> V_59 [ 0 ] , & V_240 ,
V_41 -> V_60 [ 0 ] ) ;
goto V_132;
}
if ( V_338 ) {
V_7 = F_229 ( V_2 , V_84 , V_237 , V_41 ,
& V_263 , V_349 ,
V_338 , V_265 , V_250 ) ;
if ( V_7 < 0 ) {
V_229 = V_7 ;
goto V_233;
}
V_7 = 0 ;
V_338 = 0 ;
}
F_31 ( V_41 ) ;
V_361:
if ( V_240 . V_82 < ( T_1 ) - 1 ) {
V_240 . V_82 ++ ;
} else if ( V_240 . type < V_246 . type ) {
V_240 . type ++ ;
V_240 . V_82 = 0 ;
} else {
break;
}
}
if ( V_338 ) {
V_7 = F_229 ( V_2 , V_84 , V_237 , V_41 , & V_263 ,
V_349 , V_338 , V_265 ,
V_250 ) ;
if ( V_7 < 0 ) {
V_229 = V_7 ;
goto V_233;
}
V_7 = 0 ;
V_338 = 0 ;
}
F_31 ( V_41 ) ;
F_31 ( V_237 ) ;
V_229 = F_264 ( V_2 , V_4 , V_84 , V_41 , V_237 ) ;
if ( V_229 )
goto V_233;
if ( V_246 . type >= V_193 && ! V_350 ) {
F_31 ( V_41 ) ;
F_31 ( V_237 ) ;
V_229 = F_265 ( V_2 , V_4 , V_84 , V_41 ) ;
if ( V_229 )
goto V_233;
}
V_357:
F_31 ( V_41 ) ;
F_31 ( V_237 ) ;
if ( V_352 ) {
V_229 = F_228 ( V_2 , log , V_237 , V_84 ) ;
if ( V_229 )
goto V_233;
}
if ( V_350 ) {
V_7 = F_254 ( V_2 , V_4 , V_84 , V_237 ,
& V_292 , V_6 , V_36 , V_227 ) ;
if ( V_7 ) {
V_229 = V_7 ;
goto V_233;
}
} else if ( V_265 == V_356 ) {
struct V_288 * V_291 , * V_322 ;
F_256 ( & V_351 -> V_330 ) ;
F_171 (em, n, &em_tree->modified_extents,
list) {
const T_1 V_364 = V_291 -> V_296 + V_291 -> V_297 - 1 ;
if ( V_291 -> V_296 >= V_36 && V_364 <= V_227 )
F_169 ( & V_291 -> V_24 ) ;
}
F_261 ( & V_351 -> V_330 ) ;
}
if ( V_265 == V_356 && F_39 ( V_84 -> V_148 ) ) {
V_7 = F_206 ( V_2 , V_4 , V_84 , V_41 , V_237 ,
V_6 ) ;
if ( V_7 ) {
V_229 = V_7 ;
goto V_233;
}
}
F_275 ( & F_117 ( V_84 ) -> V_330 ) ;
F_117 ( V_84 ) -> V_232 = V_2 -> V_79 ;
F_117 ( V_84 ) -> V_226 = F_117 ( V_84 ) -> V_365 ;
F_276 ( & F_117 ( V_84 ) -> V_330 ) ;
V_233:
if ( F_277 ( V_229 ) )
F_278 ( & V_292 ) ;
else
F_279 ( & V_292 , log ) ;
F_7 ( & F_117 ( V_84 ) -> V_8 ) ;
F_95 ( V_41 ) ;
F_95 ( V_237 ) ;
return V_229 ;
}
static bool F_280 ( struct V_1 * V_2 ,
struct V_84 * V_84 )
{
struct V_228 * V_10 = F_117 ( V_84 ) -> V_4 -> V_10 ;
bool V_7 = false ;
F_2 ( & F_117 ( V_84 ) -> V_8 ) ;
if ( F_117 ( V_84 ) -> V_366 > V_10 -> V_331 ) {
F_183 ( V_10 , V_2 ) ;
V_7 = true ;
}
F_7 ( & F_117 ( V_84 ) -> V_8 ) ;
return V_7 ;
}
static T_2 int F_281 ( struct V_1 * V_2 ,
struct V_84 * V_84 ,
struct V_367 * V_196 ,
struct V_368 * V_360 ,
T_1 V_369 )
{
int V_7 = 0 ;
struct V_367 * V_370 = NULL ;
struct V_84 * V_371 = V_84 ;
if ( F_46 ( V_84 -> V_148 ) &&
F_117 ( V_84 ) -> V_251 <= V_369 &&
F_117 ( V_84 ) -> V_366 <= V_369 )
goto V_12;
if ( ! F_39 ( V_84 -> V_148 ) ) {
if ( ! V_196 || F_282 ( V_196 ) || V_360 != V_196 -> V_372 )
goto V_12;
V_84 = F_283 ( V_196 ) ;
}
while ( 1 ) {
if ( V_84 != V_371 )
F_117 ( V_84 ) -> V_232 = V_2 -> V_79 ;
F_12 () ;
if ( F_280 ( V_2 , V_84 ) ) {
V_7 = 1 ;
break;
}
if ( ! V_196 || F_282 ( V_196 ) || V_360 != V_196 -> V_372 )
break;
if ( F_284 ( V_196 ) ) {
V_84 = F_283 ( V_196 ) ;
if ( F_280 ( V_2 , V_84 ) )
V_7 = 1 ;
break;
}
V_196 = F_285 ( V_196 ) ;
F_286 ( V_370 ) ;
V_370 = V_196 ;
V_84 = F_283 ( V_196 ) ;
}
F_286 ( V_370 ) ;
V_12:
return V_7 ;
}
static int F_287 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_84 * V_373 ,
struct V_5 * V_6 )
{
struct V_3 * log = V_4 -> V_9 ;
struct V_40 * V_41 ;
F_66 ( V_374 ) ;
struct V_375 * V_376 ;
int V_7 = 0 ;
V_41 = F_91 () ;
if ( ! V_41 )
return - V_63 ;
V_376 = F_32 ( sizeof( * V_376 ) , V_62 ) ;
if ( ! V_376 ) {
F_95 ( V_41 ) ;
return - V_63 ;
}
V_376 -> V_143 = F_61 ( V_373 ) ;
F_10 ( & V_376 -> V_24 , & V_374 ) ;
while ( ! F_72 ( & V_374 ) ) {
struct V_28 * V_94 ;
struct V_43 V_240 ;
int V_170 ;
int V_174 ;
V_376 = F_288 ( & V_374 , struct V_375 ,
V_24 ) ;
if ( V_7 )
goto V_377;
V_240 . V_54 = V_376 -> V_143 ;
V_240 . type = V_159 ;
V_240 . V_82 = 0 ;
V_132:
F_31 ( V_41 ) ;
V_7 = F_202 ( log , & V_240 , V_41 , V_2 -> V_79 ) ;
if ( V_7 < 0 ) {
goto V_377;
} else if ( V_7 > 0 ) {
V_7 = 0 ;
goto V_377;
}
V_176:
V_94 = V_41 -> V_59 [ 0 ] ;
V_170 = F_132 ( V_94 ) ;
for ( V_174 = V_41 -> V_60 [ 0 ] ; V_174 < V_170 ; V_174 ++ ) {
struct V_107 * V_108 ;
struct V_43 V_164 ;
struct V_84 * V_378 ;
struct V_375 * V_379 ;
int V_380 = V_279 ;
int type ;
F_114 ( V_94 , & V_240 , V_174 ) ;
if ( V_240 . V_54 != V_376 -> V_143 ||
V_240 . type != V_159 )
goto V_377;
V_108 = F_35 ( V_94 , V_174 , struct V_107 ) ;
type = F_125 ( V_94 , V_108 ) ;
if ( F_205 ( V_94 , V_108 ) < V_2 -> V_79 &&
type != V_163 )
continue;
F_81 ( V_94 , V_108 , & V_164 ) ;
if ( V_164 . type == V_244 )
continue;
V_378 = F_274 ( V_4 -> V_10 -> V_360 , & V_164 ,
V_4 , NULL ) ;
if ( F_88 ( V_378 ) ) {
V_7 = F_135 ( V_378 ) ;
goto V_377;
}
if ( F_289 ( V_378 , V_2 -> V_79 ) ) {
F_79 ( V_378 ) ;
continue;
}
V_6 -> V_245 = false ;
if ( type == V_163 || type == V_381 )
V_380 = V_356 ;
F_31 ( V_41 ) ;
V_7 = F_269 ( V_2 , V_4 , V_378 ,
V_380 , 0 , V_362 , V_6 ) ;
if ( ! V_7 &&
F_280 ( V_2 , V_378 ) )
V_7 = 1 ;
F_79 ( V_378 ) ;
if ( V_7 )
goto V_377;
if ( V_6 -> V_245 ) {
V_379 = F_32 ( sizeof( * V_379 ) ,
V_62 ) ;
if ( ! V_379 ) {
V_7 = - V_63 ;
goto V_377;
}
V_379 -> V_143 = V_164 . V_54 ;
F_10 ( & V_379 -> V_24 , & V_374 ) ;
}
break;
}
if ( V_174 == V_170 ) {
V_7 = F_133 ( log , V_41 ) ;
if ( V_7 < 0 ) {
goto V_377;
} else if ( V_7 > 0 ) {
V_7 = 0 ;
goto V_377;
}
goto V_176;
}
if ( V_240 . V_82 < ( T_1 ) - 1 ) {
V_240 . V_82 ++ ;
goto V_132;
}
V_377:
F_76 ( & V_376 -> V_24 ) ;
F_33 ( V_376 ) ;
}
F_95 ( V_41 ) ;
return V_7 ;
}
static int F_290 ( struct V_1 * V_2 ,
struct V_84 * V_84 ,
struct V_5 * V_6 )
{
int V_7 ;
struct V_40 * V_41 ;
struct V_43 V_44 ;
struct V_3 * V_4 = F_117 ( V_84 ) -> V_4 ;
const T_1 V_143 = F_61 ( V_84 ) ;
V_41 = F_91 () ;
if ( ! V_41 )
return - V_63 ;
V_41 -> V_345 = 1 ;
V_41 -> V_344 = 1 ;
V_44 . V_54 = V_143 ;
V_44 . type = V_133 ;
V_44 . V_82 = 0 ;
V_7 = F_30 ( NULL , V_4 , & V_44 , V_41 , 0 , 0 ) ;
if ( V_7 < 0 )
goto V_12;
while ( true ) {
struct V_28 * V_94 = V_41 -> V_59 [ 0 ] ;
int V_42 = V_41 -> V_60 [ 0 ] ;
T_3 V_135 = 0 ;
T_3 V_45 ;
unsigned long V_118 ;
if ( V_42 >= F_132 ( V_94 ) ) {
V_7 = F_133 ( V_4 , V_41 ) ;
if ( V_7 < 0 )
goto V_12;
else if ( V_7 > 0 )
break;
continue;
}
F_114 ( V_94 , & V_44 , V_42 ) ;
if ( V_44 . V_54 != V_143 || V_44 . type > V_122 )
break;
V_45 = F_28 ( V_94 , V_42 ) ;
V_118 = F_29 ( V_94 , V_42 ) ;
while ( V_135 < V_45 ) {
struct V_43 V_358 ;
struct V_84 * V_382 ;
V_358 . type = V_52 ;
V_358 . V_82 = 0 ;
if ( V_44 . type == V_122 ) {
struct V_130 * V_131 ;
V_131 = (struct V_130 * )
( V_118 + V_135 ) ;
V_358 . V_54 = F_101 (
V_94 , V_131 ) ;
V_135 += sizeof( * V_131 ) ;
V_135 += F_100 ( V_94 ,
V_131 ) ;
} else {
V_358 . V_54 = V_44 . V_82 ;
V_135 = V_45 ;
}
V_382 = F_274 ( V_4 -> V_10 -> V_360 , & V_358 ,
V_4 , NULL ) ;
if ( F_88 ( V_382 ) )
continue;
if ( V_6 )
V_6 -> V_245 = false ;
V_7 = F_269 ( V_2 , V_4 , V_382 ,
V_356 , 0 , V_362 , V_6 ) ;
if ( ! V_7 &&
F_280 ( V_2 , V_382 ) )
V_7 = 1 ;
if ( ! V_7 && V_6 && V_6 -> V_245 )
V_7 = F_287 ( V_2 , V_4 ,
V_382 , V_6 ) ;
F_79 ( V_382 ) ;
if ( V_7 )
goto V_12;
}
V_41 -> V_60 [ 0 ] ++ ;
}
V_7 = 0 ;
V_12:
F_95 ( V_41 ) ;
return V_7 ;
}
static int F_291 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_84 * V_84 ,
struct V_367 * V_196 ,
const T_6 V_36 ,
const T_6 V_227 ,
int V_383 ,
struct V_5 * V_6 )
{
int V_265 = V_383 ? V_279 : V_356 ;
struct V_368 * V_360 ;
struct V_367 * V_370 = NULL ;
int V_7 = 0 ;
T_1 V_369 = V_4 -> V_10 -> V_331 ;
bool V_384 = false ;
struct V_84 * V_371 = V_84 ;
V_360 = V_84 -> V_385 ;
if ( F_175 ( V_4 -> V_10 , V_386 ) ) {
V_7 = 1 ;
goto V_387;
}
if ( V_4 -> V_10 -> V_388 >
V_4 -> V_10 -> V_331 ) {
V_7 = 1 ;
goto V_387;
}
if ( V_4 != F_117 ( V_84 ) -> V_4 ||
F_292 ( & V_4 -> V_204 ) == 0 ) {
V_7 = 1 ;
goto V_387;
}
V_7 = F_281 ( V_2 , V_84 , V_196 ,
V_360 , V_369 ) ;
if ( V_7 )
goto V_387;
if ( F_289 ( V_84 , V_2 -> V_79 ) ) {
V_7 = V_389 ;
goto V_387;
}
V_7 = F_1 ( V_2 , V_4 , V_6 ) ;
if ( V_7 )
goto V_387;
V_7 = F_269 ( V_2 , V_4 , V_84 , V_265 , V_36 , V_227 , V_6 ) ;
if ( V_7 )
goto V_390;
if ( F_46 ( V_84 -> V_148 ) &&
F_117 ( V_84 ) -> V_251 <= V_369 &&
F_117 ( V_84 ) -> V_366 <= V_369 ) {
V_7 = 0 ;
goto V_390;
}
if ( F_39 ( V_84 -> V_148 ) && V_6 && V_6 -> V_245 )
V_384 = true ;
if ( F_117 ( V_84 ) -> V_366 > V_369 ) {
V_7 = F_290 ( V_2 , V_371 , V_6 ) ;
if ( V_7 )
goto V_390;
}
while ( 1 ) {
if ( ! V_196 || F_282 ( V_196 ) || V_360 != V_196 -> V_372 )
break;
V_84 = F_283 ( V_196 ) ;
if ( V_4 != F_117 ( V_84 ) -> V_4 )
break;
if ( F_117 ( V_84 ) -> V_251 > V_369 ) {
V_7 = F_269 ( V_2 , V_4 , V_84 ,
V_279 ,
0 , V_362 , V_6 ) ;
if ( V_7 )
goto V_390;
}
if ( F_284 ( V_196 ) )
break;
V_196 = F_285 ( V_196 ) ;
F_286 ( V_370 ) ;
V_370 = V_196 ;
}
if ( V_384 )
V_7 = F_287 ( V_2 , V_4 , V_371 , V_6 ) ;
else
V_7 = 0 ;
V_390:
F_286 ( V_370 ) ;
if ( V_7 < 0 ) {
F_183 ( V_4 -> V_10 , V_2 ) ;
V_7 = 1 ;
}
if ( V_7 )
F_168 ( V_4 , V_6 ) ;
F_14 ( V_4 ) ;
V_387:
return V_7 ;
}
int F_293 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_367 * V_367 ,
const T_6 V_36 ,
const T_6 V_227 ,
struct V_5 * V_6 )
{
struct V_367 * V_196 = F_285 ( V_367 ) ;
int V_7 ;
V_7 = F_291 ( V_2 , V_4 , F_283 ( V_367 ) , V_196 ,
V_36 , V_227 , 0 , V_6 ) ;
F_286 ( V_196 ) ;
return V_7 ;
}
int F_294 ( struct V_3 * V_19 )
{
int V_7 ;
struct V_40 * V_41 ;
struct V_1 * V_2 ;
struct V_43 V_44 ;
struct V_43 V_152 ;
struct V_43 V_391 ;
struct V_3 * log ;
struct V_228 * V_10 = V_19 -> V_10 ;
struct V_30 V_31 = {
. V_200 = F_18 ,
. V_189 = 0 ,
} ;
V_41 = F_91 () ;
if ( ! V_41 )
return - V_63 ;
F_5 ( V_392 , & V_10 -> V_261 ) ;
V_2 = F_295 ( V_10 -> V_225 , 0 ) ;
if ( F_88 ( V_2 ) ) {
V_7 = F_135 ( V_2 ) ;
goto error;
}
V_31 . V_2 = V_2 ;
V_31 . V_34 = 1 ;
V_7 = F_156 ( V_2 , V_19 , & V_31 ) ;
if ( V_7 ) {
F_296 ( V_10 , V_7 ,
L_1 ) ;
goto error;
}
V_132:
V_44 . V_54 = V_55 ;
V_44 . V_82 = ( T_1 ) - 1 ;
V_44 . type = V_244 ;
while ( 1 ) {
V_7 = F_30 ( NULL , V_19 , & V_44 , V_41 , 0 , 0 ) ;
if ( V_7 < 0 ) {
F_296 ( V_10 , V_7 ,
L_2 ) ;
goto error;
}
if ( V_7 > 0 ) {
if ( V_41 -> V_60 [ 0 ] == 0 )
break;
V_41 -> V_60 [ 0 ] -- ;
}
F_114 ( V_41 -> V_59 [ 0 ] , & V_152 ,
V_41 -> V_60 [ 0 ] ) ;
F_31 ( V_41 ) ;
if ( V_152 . V_54 != V_55 )
break;
log = F_297 ( V_19 , & V_152 ) ;
if ( F_88 ( log ) ) {
V_7 = F_135 ( log ) ;
F_296 ( V_10 , V_7 ,
L_3 ) ;
goto error;
}
V_391 . V_54 = V_152 . V_82 ;
V_391 . type = V_244 ;
V_391 . V_82 = ( T_1 ) - 1 ;
V_31 . V_187 = F_298 ( V_10 , & V_391 ) ;
if ( F_88 ( V_31 . V_187 ) ) {
V_7 = F_135 ( V_31 . V_187 ) ;
F_147 ( log -> V_201 ) ;
F_147 ( log -> V_393 ) ;
F_33 ( log ) ;
F_296 ( V_10 , V_7 ,
L_4 ) ;
goto error;
}
V_31 . V_187 -> V_9 = log ;
F_299 ( V_2 , V_31 . V_187 ) ;
V_7 = F_156 ( V_2 , log , & V_31 ) ;
if ( ! V_7 && V_31 . V_189 == V_192 ) {
V_7 = F_119 ( V_2 , V_31 . V_187 ,
V_41 ) ;
}
V_44 . V_82 = V_152 . V_82 - 1 ;
V_31 . V_187 -> V_9 = NULL ;
F_147 ( log -> V_201 ) ;
F_147 ( log -> V_393 ) ;
F_33 ( log ) ;
if ( V_7 )
goto error;
if ( V_152 . V_82 == 0 )
break;
}
F_31 ( V_41 ) ;
if ( V_31 . V_34 ) {
V_31 . V_34 = 0 ;
V_31 . V_200 = F_140 ;
V_31 . V_189 = V_190 ;
goto V_132;
}
if ( V_31 . V_189 < V_192 ) {
V_31 . V_189 ++ ;
goto V_132;
}
F_95 ( V_41 ) ;
V_7 = F_300 ( V_2 , V_10 -> V_225 ) ;
if ( V_7 )
return V_7 ;
F_147 ( V_19 -> V_201 ) ;
V_19 -> V_9 = NULL ;
F_4 ( V_392 , & V_10 -> V_261 ) ;
F_33 ( V_19 ) ;
return 0 ;
error:
if ( V_31 . V_2 )
F_301 ( V_31 . V_2 , V_10 -> V_225 ) ;
F_95 ( V_41 ) ;
return V_7 ;
}
void F_302 ( struct V_1 * V_2 ,
struct V_84 * V_106 , struct V_84 * V_84 ,
int V_394 )
{
F_2 ( & F_117 ( V_84 ) -> V_8 ) ;
F_117 ( V_84 ) -> V_366 = V_2 -> V_79 ;
F_7 ( & F_117 ( V_84 ) -> V_8 ) ;
F_12 () ;
if ( F_117 ( V_106 ) -> V_232 == V_2 -> V_79 )
return;
if ( F_117 ( V_84 ) -> V_232 == V_2 -> V_79 )
return;
if ( V_394 )
goto V_395;
return;
V_395:
F_2 ( & F_117 ( V_106 ) -> V_8 ) ;
F_117 ( V_106 ) -> V_366 = V_2 -> V_79 ;
F_7 ( & F_117 ( V_106 ) -> V_8 ) ;
}
void F_303 ( struct V_1 * V_2 ,
struct V_84 * V_106 )
{
F_2 ( & F_117 ( V_106 ) -> V_8 ) ;
F_117 ( V_106 ) -> V_366 = V_2 -> V_79 ;
F_7 ( & F_117 ( V_106 ) -> V_8 ) ;
}
int F_304 ( struct V_1 * V_2 ,
struct V_84 * V_84 , struct V_84 * V_396 ,
struct V_367 * V_196 )
{
struct V_3 * V_4 = F_117 ( V_84 ) -> V_4 ;
if ( F_46 ( V_84 -> V_148 ) )
F_117 ( V_84 ) -> V_366 = V_2 -> V_79 ;
if ( F_117 ( V_84 ) -> V_232 <=
V_4 -> V_10 -> V_331 &&
( ! V_396 || F_117 ( V_396 ) -> V_232 <=
V_4 -> V_10 -> V_331 ) )
return 0 ;
return F_291 ( V_2 , V_4 , V_84 , V_196 , 0 ,
V_362 , 1 , NULL ) ;
}
