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
V_41 -> V_68 = 1 ;
V_8 = F_41 ( V_2 , V_4 , V_41 ,
V_44 , V_45 ) ;
V_41 -> V_68 = 0 ;
if ( V_8 == - V_69 || V_8 == - V_70 ) {
T_3 V_71 ;
V_71 = F_28 ( V_41 -> V_59 [ 0 ] ,
V_41 -> V_60 [ 0 ] ) ;
if ( V_71 > V_45 )
F_42 ( V_4 , V_41 , V_45 , 1 ) ;
else if ( V_71 < V_45 )
F_43 ( V_4 , V_41 ,
V_45 - V_71 ) ;
} else if ( V_8 ) {
return V_8 ;
}
V_49 = F_29 ( V_41 -> V_59 [ 0 ] ,
V_41 -> V_60 [ 0 ] ) ;
if ( V_44 -> type == V_52 && V_8 == - V_69 ) {
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
int V_8 = 0 ;
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
V_8 = 0 ;
goto V_13;
}
V_84 = F_59 ( V_4 , V_44 -> V_54 ) ;
if ( ! V_84 ) {
V_8 = - V_90 ;
goto V_13;
}
V_8 = F_60 ( V_2 , V_4 , V_41 , F_61 ( V_84 ) ,
V_36 , 0 ) ;
if ( V_8 == 0 &&
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
goto V_13;
}
}
F_31 ( V_41 ) ;
V_8 = F_62 ( V_2 , V_4 , V_84 , V_36 , V_81 , 1 ) ;
if ( V_8 )
goto V_13;
if ( V_80 == V_86 ||
V_80 == V_87 ) {
T_1 V_82 ;
unsigned long V_95 ;
struct V_43 V_96 ;
V_8 = F_41 ( V_2 , V_4 , V_41 , V_44 ,
sizeof( * V_65 ) ) ;
if ( V_8 )
goto V_13;
V_95 = F_29 ( V_41 -> V_59 [ 0 ] ,
V_41 -> V_60 [ 0 ] ) ;
F_49 ( V_41 -> V_59 [ 0 ] , V_29 , V_95 ,
( unsigned long ) V_65 , sizeof( * V_65 ) ) ;
V_96 . V_54 = F_55 ( V_29 , V_65 ) ;
V_96 . V_82 = F_63 ( V_29 , V_65 ) ;
V_96 . type = V_97 ;
V_82 = V_44 -> V_82 - F_64 ( V_29 , V_65 ) ;
if ( V_96 . V_54 > 0 ) {
T_1 V_98 ;
T_1 V_99 ;
F_65 ( V_100 ) ;
V_8 = F_66 ( V_4 , V_96 . V_54 ,
V_96 . V_82 ) ;
if ( V_8 == 0 ) {
V_8 = F_67 ( V_2 , V_4 ,
V_96 . V_54 , V_96 . V_82 ,
0 , V_4 -> V_53 . V_54 ,
V_44 -> V_54 , V_82 , 0 ) ;
if ( V_8 )
goto V_13;
} else {
V_8 = F_68 ( V_2 ,
V_4 , V_4 -> V_53 . V_54 ,
V_44 -> V_54 , V_82 , & V_96 ) ;
if ( V_8 )
goto V_13;
}
F_31 ( V_41 ) ;
if ( F_69 ( V_29 , V_65 ) ) {
V_98 = V_96 . V_54 ;
V_99 = V_98 + V_96 . V_82 ;
} else {
V_98 = V_96 . V_54 +
F_64 ( V_29 , V_65 ) ;
V_99 = V_98 +
F_54 ( V_29 , V_65 ) ;
}
V_8 = F_70 ( V_4 -> V_10 ,
V_98 , V_99 - 1 ,
& V_100 , 0 ) ;
if ( V_8 )
goto V_13;
while ( ! F_71 ( & V_100 ) ) {
struct V_101 * V_102 ;
V_102 = F_72 ( V_100 . V_103 ,
struct V_101 ,
V_22 ) ;
if ( ! V_8 )
V_8 = F_73 ( V_2 ,
V_4 -> V_11 -> V_104 ,
V_102 ) ;
F_74 ( & V_102 -> V_22 ) ;
F_33 ( V_102 ) ;
}
if ( V_8 )
goto V_13;
} else {
F_31 ( V_41 ) ;
}
} else if ( V_80 == V_88 ) {
V_8 = F_27 ( V_2 , V_4 , V_41 , V_29 , V_42 , V_44 ) ;
if ( V_8 )
goto V_13;
}
F_75 ( V_84 , V_66 ) ;
V_8 = F_76 ( V_2 , V_4 , V_84 ) ;
V_13:
if ( V_84 )
F_77 ( V_84 ) ;
return V_8 ;
}
static T_2 int F_78 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_40 * V_41 ,
struct V_84 * V_105 ,
struct V_106 * V_107 )
{
struct V_84 * V_84 ;
char * V_108 ;
int V_109 ;
struct V_28 * V_94 ;
struct V_43 V_110 ;
int V_8 ;
V_94 = V_41 -> V_59 [ 0 ] ;
F_79 ( V_94 , V_107 , & V_110 ) ;
V_109 = F_80 ( V_94 , V_107 ) ;
V_108 = F_32 ( V_109 , V_62 ) ;
if ( ! V_108 )
return - V_63 ;
F_34 ( V_94 , V_108 , ( unsigned long ) ( V_107 + 1 ) , V_109 ) ;
F_31 ( V_41 ) ;
V_84 = F_59 ( V_4 , V_110 . V_54 ) ;
if ( ! V_84 ) {
V_8 = - V_90 ;
goto V_13;
}
V_8 = F_81 ( V_2 , V_4 , V_41 , V_110 . V_54 ) ;
if ( V_8 )
goto V_13;
V_8 = F_82 ( V_2 , V_4 , V_105 , V_84 , V_108 , V_109 ) ;
if ( V_8 )
goto V_13;
else
V_8 = F_83 ( V_2 , V_4 ) ;
V_13:
F_33 ( V_108 ) ;
F_77 ( V_84 ) ;
return V_8 ;
}
static T_2 int F_84 ( struct V_3 * V_4 ,
struct V_40 * V_41 ,
T_1 V_111 , T_1 V_54 , T_1 V_7 ,
const char * V_108 , int V_109 )
{
struct V_106 * V_107 ;
struct V_43 V_110 ;
int V_112 = 0 ;
V_107 = F_85 ( NULL , V_4 , V_41 , V_111 ,
V_7 , V_108 , V_109 , 0 ) ;
if ( V_107 && ! F_86 ( V_107 ) ) {
F_79 ( V_41 -> V_59 [ 0 ] , V_107 , & V_110 ) ;
if ( V_110 . V_54 != V_54 )
goto V_13;
} else
goto V_13;
F_31 ( V_41 ) ;
V_107 = F_87 ( NULL , V_4 , V_41 , V_111 , V_108 , V_109 , 0 ) ;
if ( V_107 && ! F_86 ( V_107 ) ) {
F_79 ( V_41 -> V_59 [ 0 ] , V_107 , & V_110 ) ;
if ( V_110 . V_54 != V_54 )
goto V_13;
} else
goto V_13;
V_112 = 1 ;
V_13:
F_31 ( V_41 ) ;
return V_112 ;
}
static T_2 int F_88 ( struct V_3 * log ,
struct V_43 * V_44 ,
T_1 V_113 ,
const char * V_108 , int V_114 )
{
struct V_40 * V_41 ;
struct V_115 * V_116 ;
unsigned long V_117 ;
unsigned long V_118 ;
unsigned long V_119 ;
int V_120 ;
int V_45 ;
int V_8 ;
int V_112 = 0 ;
V_41 = F_89 () ;
if ( ! V_41 )
return - V_63 ;
V_8 = F_30 ( NULL , log , V_44 , V_41 , 0 , 0 ) ;
if ( V_8 != 0 )
goto V_13;
V_117 = F_29 ( V_41 -> V_59 [ 0 ] , V_41 -> V_60 [ 0 ] ) ;
if ( V_44 -> type == V_121 ) {
if ( F_90 ( V_41 , V_113 ,
V_108 , V_114 , NULL ) )
V_112 = 1 ;
goto V_13;
}
V_45 = F_28 ( V_41 -> V_59 [ 0 ] , V_41 -> V_60 [ 0 ] ) ;
V_118 = V_117 + V_45 ;
while ( V_117 < V_118 ) {
V_116 = (struct V_115 * ) V_117 ;
V_120 = F_91 ( V_41 -> V_59 [ 0 ] , V_116 ) ;
if ( V_120 == V_114 ) {
V_119 = ( unsigned long ) ( V_116 + 1 ) ;
V_8 = F_92 ( V_41 -> V_59 [ 0 ] , V_108 ,
V_119 , V_114 ) ;
if ( V_8 == 0 ) {
V_112 = 1 ;
goto V_13;
}
}
V_117 = ( unsigned long ) ( V_116 + 1 ) + V_120 ;
}
V_13:
F_93 ( V_41 ) ;
return V_112 ;
}
static inline int F_94 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_40 * V_41 ,
struct V_3 * V_10 ,
struct V_84 * V_105 , struct V_84 * V_84 ,
struct V_28 * V_29 ,
T_1 V_122 , T_1 V_123 ,
T_1 V_124 , char * V_108 , int V_114 ,
int * V_125 )
{
int V_8 ;
char * V_126 ;
int V_127 ;
struct V_28 * V_94 ;
struct V_106 * V_107 ;
struct V_43 V_128 ;
struct V_129 * V_130 ;
V_131:
V_128 . V_54 = V_122 ;
V_128 . type = V_132 ;
V_128 . V_82 = V_123 ;
V_8 = F_30 ( NULL , V_4 , & V_128 , V_41 , 0 , 0 ) ;
if ( V_8 == 0 ) {
struct V_115 * V_133 ;
unsigned long V_117 ;
unsigned long V_118 ;
V_94 = V_41 -> V_59 [ 0 ] ;
if ( V_128 . V_54 == V_128 . V_82 )
return 1 ;
V_117 = F_29 ( V_94 , V_41 -> V_60 [ 0 ] ) ;
V_118 = V_117 + F_28 ( V_94 , V_41 -> V_60 [ 0 ] ) ;
while ( V_117 < V_118 ) {
V_133 = (struct V_115 * ) V_117 ;
V_127 = F_91 ( V_94 ,
V_133 ) ;
V_126 = F_32 ( V_127 , V_62 ) ;
if ( ! V_126 )
return - V_63 ;
F_34 ( V_94 , V_126 ,
( unsigned long ) ( V_133 + 1 ) ,
V_127 ) ;
if ( ! F_88 ( V_10 , & V_128 ,
V_123 ,
V_126 ,
V_127 ) ) {
F_95 ( V_84 ) ;
F_31 ( V_41 ) ;
V_8 = F_82 ( V_2 , V_4 , V_105 ,
V_84 , V_126 ,
V_127 ) ;
F_33 ( V_126 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_83 ( V_2 , V_4 ) ;
if ( V_8 )
return V_8 ;
* V_125 = 1 ;
goto V_131;
}
F_33 ( V_126 ) ;
V_117 = ( unsigned long ) ( V_133 + 1 ) + V_127 ;
}
* V_125 = 1 ;
}
F_31 ( V_41 ) ;
V_130 = F_96 ( NULL , V_4 , V_41 , V_108 , V_114 ,
V_122 , V_123 , 0 ,
0 ) ;
if ( ! F_97 ( V_130 ) ) {
T_3 V_45 ;
T_3 V_134 = 0 ;
unsigned long V_135 ;
struct V_84 * V_136 ;
V_94 = V_41 -> V_59 [ 0 ] ;
V_45 = F_28 ( V_94 , V_41 -> V_60 [ 0 ] ) ;
V_135 = F_29 ( V_94 , V_41 -> V_60 [ 0 ] ) ;
while ( V_134 < V_45 ) {
V_130 = (struct V_129 * ) ( V_135 + V_134 ) ;
V_127 = F_98 ( V_94 , V_130 ) ;
if ( F_99 ( V_94 , V_130 ) != V_123 )
goto V_103;
V_126 = F_32 ( V_127 , V_62 ) ;
if ( ! V_126 )
return - V_63 ;
F_34 ( V_94 , V_126 , ( unsigned long ) & V_130 -> V_108 ,
V_127 ) ;
V_128 . V_54 = V_122 ;
V_128 . type = V_121 ;
V_128 . V_82 = F_100 ( V_123 ,
V_126 ,
V_127 ) ;
V_8 = 0 ;
if ( ! F_88 ( V_10 , & V_128 ,
V_123 , V_126 ,
V_127 ) ) {
V_8 = - V_26 ;
V_136 = F_59 ( V_4 ,
V_123 ) ;
if ( V_136 ) {
F_95 ( V_84 ) ;
F_31 ( V_41 ) ;
V_8 = F_82 ( V_2 , V_4 ,
V_136 ,
V_84 ,
V_126 ,
V_127 ) ;
if ( ! V_8 )
V_8 = F_83 (
V_2 , V_4 ) ;
}
F_77 ( V_136 ) ;
F_33 ( V_126 ) ;
if ( V_8 )
return V_8 ;
* V_125 = 1 ;
goto V_131;
}
F_33 ( V_126 ) ;
if ( V_8 )
return V_8 ;
V_103:
V_134 += V_127 + sizeof( * V_130 ) ;
}
* V_125 = 1 ;
}
F_31 ( V_41 ) ;
V_107 = F_85 ( V_2 , V_4 , V_41 , F_61 ( V_105 ) ,
V_124 , V_108 , V_114 , 0 ) ;
if ( V_107 && ! F_86 ( V_107 ) ) {
V_8 = F_78 ( V_2 , V_4 , V_41 , V_105 , V_107 ) ;
if ( V_8 )
return V_8 ;
}
F_31 ( V_41 ) ;
V_107 = F_87 ( V_2 , V_4 , V_41 , F_61 ( V_105 ) ,
V_108 , V_114 , 0 ) ;
if ( V_107 && ! F_86 ( V_107 ) ) {
V_8 = F_78 ( V_2 , V_4 , V_41 , V_105 , V_107 ) ;
if ( V_8 )
return V_8 ;
}
F_31 ( V_41 ) ;
return 0 ;
}
static int F_101 ( struct V_28 * V_29 , unsigned long V_137 ,
T_3 * V_114 , char * * V_108 , T_1 * V_7 ,
T_1 * V_123 )
{
struct V_129 * V_130 ;
V_130 = (struct V_129 * ) V_137 ;
* V_114 = F_98 ( V_29 , V_130 ) ;
* V_108 = F_32 ( * V_114 , V_62 ) ;
if ( * V_108 == NULL )
return - V_63 ;
F_34 ( V_29 , * V_108 , ( unsigned long ) & V_130 -> V_108 ,
* V_114 ) ;
* V_7 = F_102 ( V_29 , V_130 ) ;
if ( V_123 )
* V_123 = F_99 ( V_29 , V_130 ) ;
return 0 ;
}
static int F_103 ( struct V_28 * V_29 , unsigned long V_137 ,
T_3 * V_114 , char * * V_108 , T_1 * V_7 )
{
struct V_115 * V_116 ;
V_116 = (struct V_115 * ) V_137 ;
* V_114 = F_91 ( V_29 , V_116 ) ;
* V_108 = F_32 ( * V_114 , V_62 ) ;
if ( * V_108 == NULL )
return - V_63 ;
F_34 ( V_29 , * V_108 , ( unsigned long ) ( V_116 + 1 ) , * V_114 ) ;
* V_7 = F_104 ( V_29 , V_116 ) ;
return 0 ;
}
static T_2 int F_105 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_3 * log ,
struct V_40 * V_41 ,
struct V_28 * V_29 , int V_42 ,
struct V_43 * V_44 )
{
struct V_84 * V_105 = NULL ;
struct V_84 * V_84 = NULL ;
unsigned long V_137 ;
unsigned long V_138 ;
char * V_108 = NULL ;
int V_114 ;
int V_8 ;
int V_125 = 0 ;
int V_139 = 0 ;
T_1 V_123 ;
T_1 V_122 ;
T_1 V_124 = 0 ;
int V_140 ;
V_137 = F_29 ( V_29 , V_42 ) ;
V_138 = V_137 + F_28 ( V_29 , V_42 ) ;
if ( V_44 -> type == V_121 ) {
struct V_129 * V_141 ;
V_140 = sizeof( struct V_129 ) ;
V_139 = 1 ;
V_141 = (struct V_129 * ) V_137 ;
V_123 = F_99 ( V_29 , V_141 ) ;
} else {
V_140 = sizeof( struct V_115 ) ;
V_123 = V_44 -> V_82 ;
}
V_122 = V_44 -> V_54 ;
V_105 = F_59 ( V_4 , V_123 ) ;
if ( ! V_105 ) {
V_8 = - V_26 ;
goto V_13;
}
V_84 = F_59 ( V_4 , V_122 ) ;
if ( ! V_84 ) {
V_8 = - V_90 ;
goto V_13;
}
while ( V_137 < V_138 ) {
if ( V_139 ) {
V_8 = F_101 ( V_29 , V_137 , & V_114 , & V_108 ,
& V_124 , & V_123 ) ;
if ( ! V_105 )
V_105 = F_59 ( V_4 , V_123 ) ;
if ( ! V_105 ) {
V_8 = - V_26 ;
goto V_13;
}
} else {
V_8 = F_103 ( V_29 , V_137 , & V_114 , & V_108 ,
& V_124 ) ;
}
if ( V_8 )
goto V_13;
if ( ! F_84 ( V_4 , V_41 , F_61 ( V_105 ) , F_61 ( V_84 ) ,
V_124 , V_108 , V_114 ) ) {
if ( ! V_125 ) {
V_8 = F_94 ( V_2 , V_4 , V_41 , log ,
V_105 , V_84 , V_29 ,
V_122 ,
V_123 ,
V_124 , V_108 , V_114 ,
& V_125 ) ;
if ( V_8 ) {
if ( V_8 == 1 )
V_8 = 0 ;
goto V_13;
}
}
V_8 = F_106 ( V_2 , V_105 , V_84 , V_108 , V_114 ,
0 , V_124 ) ;
if ( V_8 )
goto V_13;
F_76 ( V_2 , V_4 , V_84 ) ;
}
V_137 = ( unsigned long ) ( V_137 + V_140 ) + V_114 ;
F_33 ( V_108 ) ;
V_108 = NULL ;
if ( V_139 ) {
F_77 ( V_105 ) ;
V_105 = NULL ;
}
}
V_8 = F_27 ( V_2 , V_4 , V_41 , V_29 , V_42 , V_44 ) ;
V_13:
F_31 ( V_41 ) ;
F_33 ( V_108 ) ;
F_77 ( V_105 ) ;
F_77 ( V_84 ) ;
return V_8 ;
}
static int F_107 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_1 V_142 )
{
int V_8 ;
V_8 = F_108 ( V_2 , V_4 , V_142 ) ;
if ( V_8 == - V_69 )
V_8 = 0 ;
return V_8 ;
}
static int F_109 ( struct V_3 * V_4 ,
struct V_84 * V_84 , struct V_40 * V_41 )
{
int V_8 = 0 ;
int V_109 ;
unsigned int V_143 = 0 ;
T_3 V_45 ;
T_3 V_134 = 0 ;
T_1 V_122 = F_61 ( V_84 ) ;
T_1 V_82 = 0 ;
unsigned long V_117 ;
struct V_129 * V_130 ;
struct V_28 * V_94 ;
while ( 1 ) {
V_8 = F_110 ( V_4 , V_122 , V_82 , V_41 ,
& V_130 , & V_82 ) ;
if ( V_8 )
break;
V_94 = V_41 -> V_59 [ 0 ] ;
V_45 = F_28 ( V_94 , V_41 -> V_60 [ 0 ] ) ;
V_117 = F_29 ( V_94 , V_41 -> V_60 [ 0 ] ) ;
V_134 = 0 ;
while ( V_134 < V_45 ) {
V_130 = (struct V_129 * ) ( V_117 + V_134 ) ;
V_109 = F_98 ( V_94 , V_130 ) ;
V_143 ++ ;
V_134 += V_109 + sizeof( * V_130 ) ;
}
V_82 ++ ;
F_31 ( V_41 ) ;
}
F_31 ( V_41 ) ;
if ( V_8 < 0 && V_8 != - V_26 )
return V_8 ;
return V_143 ;
}
static int F_111 ( struct V_3 * V_4 ,
struct V_84 * V_84 , struct V_40 * V_41 )
{
int V_8 ;
struct V_43 V_44 ;
unsigned int V_143 = 0 ;
unsigned long V_117 ;
unsigned long V_118 ;
int V_109 ;
T_1 V_142 = F_61 ( V_84 ) ;
V_44 . V_54 = V_142 ;
V_44 . type = V_132 ;
V_44 . V_82 = ( T_1 ) - 1 ;
while ( 1 ) {
V_8 = F_30 ( NULL , V_4 , & V_44 , V_41 , 0 , 0 ) ;
if ( V_8 < 0 )
break;
if ( V_8 > 0 ) {
if ( V_41 -> V_60 [ 0 ] == 0 )
break;
V_41 -> V_60 [ 0 ] -- ;
}
V_144:
F_112 ( V_41 -> V_59 [ 0 ] , & V_44 ,
V_41 -> V_60 [ 0 ] ) ;
if ( V_44 . V_54 != V_142 ||
V_44 . type != V_132 )
break;
V_117 = F_29 ( V_41 -> V_59 [ 0 ] , V_41 -> V_60 [ 0 ] ) ;
V_118 = V_117 + F_28 ( V_41 -> V_59 [ 0 ] ,
V_41 -> V_60 [ 0 ] ) ;
while ( V_117 < V_118 ) {
struct V_115 * V_116 ;
V_116 = (struct V_115 * ) V_117 ;
V_109 = F_91 ( V_41 -> V_59 [ 0 ] ,
V_116 ) ;
V_117 = ( unsigned long ) ( V_116 + 1 ) + V_109 ;
V_143 ++ ;
}
if ( V_44 . V_82 == 0 )
break;
if ( V_41 -> V_60 [ 0 ] > 0 ) {
V_41 -> V_60 [ 0 ] -- ;
goto V_144;
}
V_44 . V_82 -- ;
F_31 ( V_41 ) ;
}
F_31 ( V_41 ) ;
return V_143 ;
}
static T_2 int F_113 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_84 * V_84 )
{
struct V_40 * V_41 ;
int V_8 ;
T_1 V_143 = 0 ;
T_1 V_142 = F_61 ( V_84 ) ;
V_41 = F_89 () ;
if ( ! V_41 )
return - V_63 ;
V_8 = F_111 ( V_4 , V_84 , V_41 ) ;
if ( V_8 < 0 )
goto V_13;
V_143 = V_8 ;
V_8 = F_109 ( V_4 , V_84 , V_41 ) ;
if ( V_8 < 0 )
goto V_13;
V_143 += V_8 ;
V_8 = 0 ;
if ( V_143 != V_84 -> V_145 ) {
F_114 ( V_84 , V_143 ) ;
F_76 ( V_2 , V_4 , V_84 ) ;
}
F_115 ( V_84 ) -> V_146 = ( T_1 ) - 1 ;
if ( V_84 -> V_145 == 0 ) {
if ( F_39 ( V_84 -> V_147 ) ) {
V_8 = F_116 ( V_2 , V_4 , NULL , V_41 ,
V_142 , 1 ) ;
if ( V_8 )
goto V_13;
}
V_8 = F_107 ( V_2 , V_4 , V_142 ) ;
}
V_13:
F_93 ( V_41 ) ;
return V_8 ;
}
static T_2 int F_117 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_40 * V_41 )
{
int V_8 ;
struct V_43 V_44 ;
struct V_84 * V_84 ;
V_44 . V_54 = V_148 ;
V_44 . type = V_149 ;
V_44 . V_82 = ( T_1 ) - 1 ;
while ( 1 ) {
V_8 = F_30 ( V_2 , V_4 , & V_44 , V_41 , - 1 , 1 ) ;
if ( V_8 < 0 )
break;
if ( V_8 == 1 ) {
if ( V_41 -> V_60 [ 0 ] == 0 )
break;
V_41 -> V_60 [ 0 ] -- ;
}
F_112 ( V_41 -> V_59 [ 0 ] , & V_44 , V_41 -> V_60 [ 0 ] ) ;
if ( V_44 . V_54 != V_148 ||
V_44 . type != V_149 )
break;
V_8 = F_118 ( V_2 , V_4 , V_41 ) ;
if ( V_8 )
goto V_13;
F_31 ( V_41 ) ;
V_84 = F_59 ( V_4 , V_44 . V_82 ) ;
if ( ! V_84 )
return - V_90 ;
V_8 = F_113 ( V_2 , V_4 , V_84 ) ;
F_77 ( V_84 ) ;
if ( V_8 )
goto V_13;
V_44 . V_82 = ( T_1 ) - 1 ;
}
V_8 = 0 ;
V_13:
F_31 ( V_41 ) ;
return V_8 ;
}
static T_2 int F_81 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_40 * V_41 ,
T_1 V_54 )
{
struct V_43 V_44 ;
int V_8 = 0 ;
struct V_84 * V_84 ;
V_84 = F_59 ( V_4 , V_54 ) ;
if ( ! V_84 )
return - V_90 ;
V_44 . V_54 = V_148 ;
V_44 . type = V_149 ;
V_44 . V_82 = V_54 ;
V_8 = F_41 ( V_2 , V_4 , V_41 , & V_44 , 0 ) ;
F_31 ( V_41 ) ;
if ( V_8 == 0 ) {
if ( ! V_84 -> V_145 )
F_114 ( V_84 , 1 ) ;
else
F_95 ( V_84 ) ;
V_8 = F_76 ( V_2 , V_4 , V_84 ) ;
} else if ( V_8 == - V_69 ) {
V_8 = 0 ;
} else {
F_119 () ;
}
F_77 ( V_84 ) ;
return V_8 ;
}
static T_2 int F_120 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_40 * V_41 ,
T_1 V_111 , T_1 V_7 ,
char * V_108 , int V_109 , T_4 type ,
struct V_43 * V_110 )
{
struct V_84 * V_84 ;
struct V_84 * V_105 ;
int V_8 ;
V_84 = F_59 ( V_4 , V_110 -> V_54 ) ;
if ( ! V_84 )
return - V_26 ;
V_105 = F_59 ( V_4 , V_111 ) ;
if ( ! V_105 ) {
F_77 ( V_84 ) ;
return - V_90 ;
}
V_8 = F_106 ( V_2 , V_105 , V_84 , V_108 , V_109 , 1 , V_7 ) ;
F_77 ( V_84 ) ;
F_77 ( V_105 ) ;
return V_8 ;
}
static bool F_121 ( struct V_3 * V_10 ,
const char * V_108 , const int V_109 ,
const T_1 V_111 , const T_1 V_142 )
{
struct V_43 V_128 ;
V_128 . V_54 = V_142 ;
V_128 . type = V_132 ;
V_128 . V_82 = V_111 ;
if ( F_88 ( V_10 , & V_128 , V_111 , V_108 , V_109 ) )
return true ;
V_128 . type = V_121 ;
V_128 . V_82 = F_100 ( V_111 , V_108 , V_109 ) ;
if ( F_88 ( V_10 , & V_128 , V_111 , V_108 , V_109 ) )
return true ;
return false ;
}
static T_2 int F_122 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_40 * V_41 ,
struct V_28 * V_29 ,
struct V_106 * V_107 ,
struct V_43 * V_44 )
{
char * V_108 ;
int V_109 ;
struct V_106 * V_150 ;
struct V_43 V_151 ;
struct V_43 V_152 ;
struct V_84 * V_105 ;
T_4 V_153 ;
int V_154 ;
int V_8 = 0 ;
bool V_155 = ( V_44 -> type == V_156 ) ;
V_105 = F_59 ( V_4 , V_44 -> V_54 ) ;
if ( ! V_105 )
return - V_90 ;
V_109 = F_80 ( V_29 , V_107 ) ;
V_108 = F_32 ( V_109 , V_62 ) ;
if ( ! V_108 ) {
V_8 = - V_63 ;
goto V_13;
}
V_153 = F_123 ( V_29 , V_107 ) ;
F_34 ( V_29 , V_108 , ( unsigned long ) ( V_107 + 1 ) ,
V_109 ) ;
F_79 ( V_29 , V_107 , & V_152 ) ;
V_154 = F_124 ( V_2 , V_4 , V_41 , & V_152 , 0 ) ;
if ( V_154 == 0 )
V_154 = 1 ;
else
V_154 = 0 ;
F_31 ( V_41 ) ;
if ( V_44 -> type == V_157 ) {
V_150 = F_87 ( V_2 , V_4 , V_41 , V_44 -> V_54 ,
V_108 , V_109 , 1 ) ;
} else if ( V_44 -> type == V_156 ) {
V_150 = F_85 ( V_2 , V_4 , V_41 ,
V_44 -> V_54 ,
V_44 -> V_82 , V_108 ,
V_109 , 1 ) ;
} else {
V_8 = - V_158 ;
goto V_13;
}
if ( F_97 ( V_150 ) ) {
if ( V_44 -> type != V_156 )
goto V_13;
goto V_61;
}
F_79 ( V_41 -> V_59 [ 0 ] , V_150 , & V_151 ) ;
if ( V_151 . V_54 == V_152 . V_54 &&
V_151 . type == V_152 . type &&
V_151 . V_82 == V_152 . V_82 &&
F_123 ( V_41 -> V_59 [ 0 ] , V_150 ) == V_153 ) {
V_155 = false ;
goto V_13;
}
if ( ! V_154 )
goto V_13;
V_8 = F_78 ( V_2 , V_4 , V_41 , V_105 , V_150 ) ;
if ( V_8 )
goto V_13;
if ( V_44 -> type == V_156 )
goto V_61;
V_13:
F_31 ( V_41 ) ;
if ( ! V_8 && V_155 ) {
F_125 ( V_105 , V_105 -> V_159 + V_109 * 2 ) ;
V_8 = F_76 ( V_2 , V_4 , V_105 ) ;
}
F_33 ( V_108 ) ;
F_77 ( V_105 ) ;
return V_8 ;
V_61:
if ( F_121 ( V_4 -> V_10 , V_108 , V_109 ,
V_44 -> V_54 , V_152 . V_54 ) ) {
V_8 = 0 ;
V_155 = false ;
goto V_13;
}
F_31 ( V_41 ) ;
V_8 = F_120 ( V_2 , V_4 , V_41 , V_44 -> V_54 , V_44 -> V_82 ,
V_108 , V_109 , V_153 , & V_152 ) ;
if ( V_8 && V_8 != - V_26 && V_8 != - V_69 )
goto V_13;
V_155 = false ;
V_8 = 0 ;
goto V_13;
}
static T_2 int F_126 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_40 * V_41 ,
struct V_28 * V_29 , int V_42 ,
struct V_43 * V_44 )
{
int V_8 ;
T_3 V_45 = F_28 ( V_29 , V_42 ) ;
struct V_106 * V_107 ;
int V_109 ;
unsigned long V_117 ;
unsigned long V_118 ;
V_117 = F_29 ( V_29 , V_42 ) ;
V_118 = V_117 + V_45 ;
while ( V_117 < V_118 ) {
V_107 = (struct V_106 * ) V_117 ;
if ( F_127 ( V_4 , V_29 , V_107 ) )
return - V_90 ;
V_109 = F_80 ( V_29 , V_107 ) ;
V_8 = F_122 ( V_2 , V_4 , V_41 , V_29 , V_107 , V_44 ) ;
if ( V_8 )
return V_8 ;
V_117 = ( unsigned long ) ( V_107 + 1 ) ;
V_117 += V_109 ;
}
return 0 ;
}
static T_2 int F_128 ( struct V_3 * V_4 ,
struct V_40 * V_41 ,
T_1 V_111 , int V_160 ,
T_1 * V_161 , T_1 * V_162 )
{
struct V_43 V_44 ;
T_1 V_163 ;
struct V_164 * V_65 ;
int V_8 ;
int V_165 ;
if ( * V_161 == ( T_1 ) - 1 )
return 1 ;
V_44 . V_54 = V_111 ;
V_44 . type = V_160 ;
V_44 . V_82 = * V_161 ;
V_8 = F_30 ( NULL , V_4 , & V_44 , V_41 , 0 , 0 ) ;
if ( V_8 < 0 )
goto V_13;
if ( V_8 > 0 ) {
if ( V_41 -> V_60 [ 0 ] == 0 )
goto V_13;
V_41 -> V_60 [ 0 ] -- ;
}
if ( V_8 != 0 )
F_112 ( V_41 -> V_59 [ 0 ] , & V_44 , V_41 -> V_60 [ 0 ] ) ;
if ( V_44 . type != V_160 || V_44 . V_54 != V_111 ) {
V_8 = 1 ;
goto V_103;
}
V_65 = F_35 ( V_41 -> V_59 [ 0 ] , V_41 -> V_60 [ 0 ] ,
struct V_164 ) ;
V_163 = F_129 ( V_41 -> V_59 [ 0 ] , V_65 ) ;
if ( * V_161 >= V_44 . V_82 && * V_161 <= V_163 ) {
V_8 = 0 ;
* V_161 = V_44 . V_82 ;
* V_162 = V_163 ;
goto V_13;
}
V_8 = 1 ;
V_103:
V_165 = F_130 ( V_41 -> V_59 [ 0 ] ) ;
if ( V_41 -> V_60 [ 0 ] >= V_165 ) {
V_8 = F_131 ( V_4 , V_41 ) ;
if ( V_8 )
goto V_13;
} else {
V_41 -> V_60 [ 0 ] ++ ;
}
F_112 ( V_41 -> V_59 [ 0 ] , & V_44 , V_41 -> V_60 [ 0 ] ) ;
if ( V_44 . type != V_160 || V_44 . V_54 != V_111 ) {
V_8 = 1 ;
goto V_13;
}
V_65 = F_35 ( V_41 -> V_59 [ 0 ] , V_41 -> V_60 [ 0 ] ,
struct V_164 ) ;
V_163 = F_129 ( V_41 -> V_59 [ 0 ] , V_65 ) ;
* V_161 = V_44 . V_82 ;
* V_162 = V_163 ;
V_8 = 0 ;
V_13:
F_31 ( V_41 ) ;
return V_8 ;
}
static T_2 int F_132 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_3 * log ,
struct V_40 * V_41 ,
struct V_40 * V_166 ,
struct V_84 * V_105 ,
struct V_43 * V_167 )
{
int V_8 ;
struct V_28 * V_29 ;
int V_42 ;
T_3 V_45 ;
struct V_106 * V_107 ;
struct V_106 * V_168 ;
int V_109 ;
unsigned long V_117 ;
unsigned long V_118 ;
char * V_108 ;
struct V_84 * V_84 ;
struct V_43 V_110 ;
V_131:
V_29 = V_41 -> V_59 [ 0 ] ;
V_42 = V_41 -> V_60 [ 0 ] ;
V_45 = F_28 ( V_29 , V_42 ) ;
V_117 = F_29 ( V_29 , V_42 ) ;
V_118 = V_117 + V_45 ;
while ( V_117 < V_118 ) {
V_107 = (struct V_106 * ) V_117 ;
if ( F_127 ( V_4 , V_29 , V_107 ) ) {
V_8 = - V_90 ;
goto V_13;
}
V_109 = F_80 ( V_29 , V_107 ) ;
V_108 = F_32 ( V_109 , V_62 ) ;
if ( ! V_108 ) {
V_8 = - V_63 ;
goto V_13;
}
F_34 ( V_29 , V_108 , ( unsigned long ) ( V_107 + 1 ) ,
V_109 ) ;
V_168 = NULL ;
if ( log && V_167 -> type == V_157 ) {
V_168 = F_87 ( V_2 , log , V_166 ,
V_167 -> V_54 ,
V_108 , V_109 , 0 ) ;
} else if ( log && V_167 -> type == V_156 ) {
V_168 = F_85 ( V_2 , log ,
V_166 ,
V_167 -> V_54 ,
V_167 -> V_82 ,
V_108 , V_109 , 0 ) ;
}
if ( ! V_168 || ( F_86 ( V_168 ) && F_133 ( V_168 ) == - V_26 ) ) {
F_79 ( V_29 , V_107 , & V_110 ) ;
F_31 ( V_41 ) ;
F_31 ( V_166 ) ;
V_84 = F_59 ( V_4 , V_110 . V_54 ) ;
if ( ! V_84 ) {
F_33 ( V_108 ) ;
return - V_90 ;
}
V_8 = F_81 ( V_2 , V_4 ,
V_41 , V_110 . V_54 ) ;
if ( V_8 ) {
F_33 ( V_108 ) ;
F_77 ( V_84 ) ;
goto V_13;
}
F_95 ( V_84 ) ;
V_8 = F_82 ( V_2 , V_4 , V_105 , V_84 ,
V_108 , V_109 ) ;
if ( ! V_8 )
V_8 = F_83 ( V_2 , V_4 ) ;
F_33 ( V_108 ) ;
F_77 ( V_84 ) ;
if ( V_8 )
goto V_13;
V_8 = F_30 ( NULL , V_4 , V_167 , V_41 ,
0 , 0 ) ;
if ( V_8 == 0 )
goto V_131;
V_8 = 0 ;
goto V_13;
} else if ( F_86 ( V_168 ) ) {
F_33 ( V_108 ) ;
return F_133 ( V_168 ) ;
}
F_31 ( V_166 ) ;
F_33 ( V_108 ) ;
V_117 = ( unsigned long ) ( V_107 + 1 ) ;
V_117 += V_109 ;
}
V_8 = 0 ;
V_13:
F_31 ( V_41 ) ;
F_31 ( V_166 ) ;
return V_8 ;
}
static int F_134 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_3 * log ,
struct V_40 * V_41 ,
const T_1 V_142 )
{
struct V_43 V_128 ;
struct V_40 * V_166 ;
int V_169 ;
int V_165 ;
int V_8 ;
V_166 = F_89 () ;
if ( ! V_166 )
return - V_63 ;
V_128 . V_54 = V_142 ;
V_128 . type = V_170 ;
V_128 . V_82 = 0 ;
V_131:
V_8 = F_30 ( NULL , V_4 , & V_128 , V_41 , 0 , 0 ) ;
if ( V_8 < 0 )
goto V_13;
V_171:
V_165 = F_130 ( V_41 -> V_59 [ 0 ] ) ;
for ( V_169 = V_41 -> V_60 [ 0 ] ; V_169 < V_165 ; V_169 ++ ) {
struct V_43 V_44 ;
struct V_106 * V_107 ;
struct V_106 * V_168 ;
T_3 V_172 ;
T_3 V_173 ;
F_112 ( V_41 -> V_59 [ 0 ] , & V_44 , V_169 ) ;
if ( V_44 . V_54 != V_142 || V_44 . type != V_170 ) {
V_8 = 0 ;
goto V_13;
}
V_107 = F_35 ( V_41 -> V_59 [ 0 ] , V_169 , struct V_106 ) ;
V_172 = F_28 ( V_41 -> V_59 [ 0 ] , V_169 ) ;
V_173 = 0 ;
while ( V_173 < V_172 ) {
T_5 V_109 = F_80 ( V_41 -> V_59 [ 0 ] , V_107 ) ;
T_5 V_174 = F_135 ( V_41 -> V_59 [ 0 ] , V_107 ) ;
T_3 V_175 = sizeof( * V_107 ) + V_109 + V_174 ;
char * V_108 ;
V_108 = F_32 ( V_109 , V_62 ) ;
if ( ! V_108 ) {
V_8 = - V_63 ;
goto V_13;
}
F_34 ( V_41 -> V_59 [ 0 ] , V_108 ,
( unsigned long ) ( V_107 + 1 ) , V_109 ) ;
V_168 = F_136 ( NULL , log , V_166 , V_142 ,
V_108 , V_109 , 0 ) ;
F_31 ( V_166 ) ;
if ( ! V_168 ) {
F_31 ( V_41 ) ;
V_107 = F_136 ( V_2 , V_4 , V_41 , V_142 ,
V_108 , V_109 , - 1 ) ;
F_33 ( V_108 ) ;
if ( F_86 ( V_107 ) ) {
V_8 = F_133 ( V_107 ) ;
goto V_13;
}
ASSERT ( V_107 ) ;
V_8 = F_137 ( V_2 , V_4 ,
V_41 , V_107 ) ;
if ( V_8 )
goto V_13;
F_31 ( V_41 ) ;
V_128 = V_44 ;
goto V_131;
}
F_33 ( V_108 ) ;
if ( F_86 ( V_168 ) ) {
V_8 = F_133 ( V_168 ) ;
goto V_13;
}
V_173 += V_175 ;
V_107 = (struct V_106 * ) ( ( char * ) V_107 + V_175 ) ;
}
}
V_8 = F_131 ( V_4 , V_41 ) ;
if ( V_8 > 0 )
V_8 = 0 ;
else if ( V_8 == 0 )
goto V_171;
V_13:
F_93 ( V_166 ) ;
F_31 ( V_41 ) ;
return V_8 ;
}
static T_2 int F_116 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_3 * log ,
struct V_40 * V_41 ,
T_1 V_111 , int V_176 )
{
T_1 V_177 ;
T_1 V_178 ;
int V_160 = V_179 ;
int V_8 = 0 ;
struct V_43 V_167 ;
struct V_43 V_151 ;
struct V_40 * V_166 ;
struct V_84 * V_105 ;
V_167 . V_54 = V_111 ;
V_167 . type = V_157 ;
V_166 = F_89 () ;
if ( ! V_166 )
return - V_63 ;
V_105 = F_59 ( V_4 , V_111 ) ;
if ( ! V_105 ) {
F_93 ( V_166 ) ;
return 0 ;
}
V_131:
V_177 = 0 ;
V_178 = 0 ;
while ( 1 ) {
if ( V_176 )
V_178 = ( T_1 ) - 1 ;
else {
V_8 = F_128 ( log , V_41 , V_111 , V_160 ,
& V_177 , & V_178 ) ;
if ( V_8 != 0 )
break;
}
V_167 . V_82 = V_177 ;
while ( 1 ) {
int V_165 ;
V_8 = F_30 ( NULL , V_4 , & V_167 , V_41 ,
0 , 0 ) ;
if ( V_8 < 0 )
goto V_13;
V_165 = F_130 ( V_41 -> V_59 [ 0 ] ) ;
if ( V_41 -> V_60 [ 0 ] >= V_165 ) {
V_8 = F_131 ( V_4 , V_41 ) ;
if ( V_8 )
break;
}
F_112 ( V_41 -> V_59 [ 0 ] , & V_151 ,
V_41 -> V_60 [ 0 ] ) ;
if ( V_151 . V_54 != V_111 ||
V_151 . type != V_167 . type )
goto V_180;
if ( V_151 . V_82 > V_178 )
break;
V_8 = F_132 ( V_2 , V_4 , log , V_41 ,
V_166 , V_105 ,
& V_151 ) ;
if ( V_8 )
goto V_13;
if ( V_151 . V_82 == ( T_1 ) - 1 )
break;
V_167 . V_82 = V_151 . V_82 + 1 ;
}
F_31 ( V_41 ) ;
if ( V_178 == ( T_1 ) - 1 )
break;
V_177 = V_178 + 1 ;
}
V_180:
V_8 = 0 ;
if ( V_160 == V_179 ) {
V_160 = V_181 ;
V_167 . type = V_156 ;
F_31 ( V_41 ) ;
goto V_131;
}
V_13:
F_31 ( V_41 ) ;
F_93 ( V_166 ) ;
F_77 ( V_105 ) ;
return V_8 ;
}
static int F_138 ( struct V_3 * log , struct V_28 * V_29 ,
struct V_30 * V_31 , T_1 V_32 )
{
int V_165 ;
struct V_40 * V_41 ;
struct V_3 * V_4 = V_31 -> V_182 ;
struct V_43 V_44 ;
int V_183 ;
int V_169 ;
int V_8 ;
V_8 = F_20 ( V_29 , V_32 ) ;
if ( V_8 )
return V_8 ;
V_183 = F_23 ( V_29 ) ;
if ( V_183 != 0 )
return 0 ;
V_41 = F_89 () ;
if ( ! V_41 )
return - V_63 ;
V_165 = F_130 ( V_29 ) ;
for ( V_169 = 0 ; V_169 < V_165 ; V_169 ++ ) {
F_112 ( V_29 , & V_44 , V_169 ) ;
if ( V_44 . type == V_52 &&
V_31 -> V_184 == V_185 ) {
struct V_64 * V_51 ;
T_3 V_67 ;
V_51 = F_35 ( V_29 , V_169 ,
struct V_64 ) ;
V_8 = F_134 ( V_31 -> V_2 , V_4 , log ,
V_41 , V_44 . V_54 ) ;
if ( V_8 )
break;
V_67 = F_38 ( V_29 , V_51 ) ;
if ( F_39 ( V_67 ) ) {
V_8 = F_116 ( V_31 -> V_2 ,
V_4 , log , V_41 , V_44 . V_54 , 0 ) ;
if ( V_8 )
break;
}
V_8 = F_27 ( V_31 -> V_2 , V_4 , V_41 ,
V_29 , V_169 , & V_44 ) ;
if ( V_8 )
break;
if ( F_46 ( V_67 ) ) {
V_8 = F_107 ( V_31 -> V_2 , V_4 ,
V_44 . V_54 ) ;
if ( V_8 )
break;
}
V_8 = F_81 ( V_31 -> V_2 , V_4 ,
V_41 , V_44 . V_54 ) ;
if ( V_8 )
break;
}
if ( V_44 . type == V_156 &&
V_31 -> V_184 == V_186 ) {
V_8 = F_126 ( V_31 -> V_2 , V_4 , V_41 ,
V_29 , V_169 , & V_44 ) ;
if ( V_8 )
break;
}
if ( V_31 -> V_184 < V_187 )
continue;
if ( V_44 . type == V_170 ) {
V_8 = F_27 ( V_31 -> V_2 , V_4 , V_41 ,
V_29 , V_169 , & V_44 ) ;
if ( V_8 )
break;
} else if ( V_44 . type == V_132 ||
V_44 . type == V_121 ) {
V_8 = F_105 ( V_31 -> V_2 , V_4 , log , V_41 ,
V_29 , V_169 , & V_44 ) ;
if ( V_8 && V_8 != - V_26 )
break;
V_8 = 0 ;
} else if ( V_44 . type == V_188 ) {
V_8 = F_52 ( V_31 -> V_2 , V_4 , V_41 ,
V_29 , V_169 , & V_44 ) ;
if ( V_8 )
break;
} else if ( V_44 . type == V_157 ) {
V_8 = F_126 ( V_31 -> V_2 , V_4 , V_41 ,
V_29 , V_169 , & V_44 ) ;
if ( V_8 )
break;
}
}
F_93 ( V_41 ) ;
return V_8 ;
}
static T_2 int F_139 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_40 * V_41 , int * V_183 ,
struct V_30 * V_31 )
{
T_1 V_189 ;
T_1 V_190 ;
T_1 V_191 ;
struct V_28 * V_103 ;
struct V_28 * V_173 ;
struct V_28 * V_192 ;
T_3 V_193 ;
int V_8 = 0 ;
F_140 ( * V_183 < 0 ) ;
F_140 ( * V_183 >= V_194 ) ;
while ( * V_183 > 0 ) {
F_140 ( * V_183 < 0 ) ;
F_140 ( * V_183 >= V_194 ) ;
V_173 = V_41 -> V_59 [ * V_183 ] ;
F_140 ( F_23 ( V_173 ) != * V_183 ) ;
if ( V_41 -> V_60 [ * V_183 ] >=
F_130 ( V_173 ) )
break;
V_190 = F_141 ( V_173 , V_41 -> V_60 [ * V_183 ] ) ;
V_191 = F_142 ( V_173 , V_41 -> V_60 [ * V_183 ] ) ;
V_193 = V_4 -> V_195 ;
V_192 = V_41 -> V_59 [ * V_183 ] ;
V_189 = F_143 ( V_192 ) ;
V_103 = F_144 ( V_4 , V_190 ) ;
if ( ! V_103 )
return - V_63 ;
if ( * V_183 == 1 ) {
V_8 = V_31 -> V_196 ( V_4 , V_103 , V_31 , V_191 ) ;
if ( V_8 ) {
F_145 ( V_103 ) ;
return V_8 ;
}
V_41 -> V_60 [ * V_183 ] ++ ;
if ( V_31 -> free ) {
V_8 = F_20 ( V_103 , V_191 ) ;
if ( V_8 ) {
F_145 ( V_103 ) ;
return V_8 ;
}
if ( V_2 ) {
F_146 ( V_103 ) ;
F_147 ( V_103 ) ;
F_148 ( V_2 , V_4 -> V_11 ,
V_103 ) ;
F_26 ( V_103 ) ;
F_149 ( V_103 ) ;
}
F_140 ( V_189 !=
V_55 ) ;
V_8 = F_150 ( V_4 ,
V_190 , V_193 ) ;
if ( V_8 ) {
F_145 ( V_103 ) ;
return V_8 ;
}
}
F_145 ( V_103 ) ;
continue;
}
V_8 = F_20 ( V_103 , V_191 ) ;
if ( V_8 ) {
F_145 ( V_103 ) ;
return V_8 ;
}
F_140 ( * V_183 <= 0 ) ;
if ( V_41 -> V_59 [ * V_183 - 1 ] )
F_145 ( V_41 -> V_59 [ * V_183 - 1 ] ) ;
V_41 -> V_59 [ * V_183 - 1 ] = V_103 ;
* V_183 = F_23 ( V_103 ) ;
V_41 -> V_60 [ * V_183 ] = 0 ;
F_151 () ;
}
F_140 ( * V_183 < 0 ) ;
F_140 ( * V_183 >= V_194 ) ;
V_41 -> V_60 [ * V_183 ] = F_130 ( V_41 -> V_59 [ * V_183 ] ) ;
F_151 () ;
return 0 ;
}
static T_2 int F_152 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_40 * V_41 , int * V_183 ,
struct V_30 * V_31 )
{
T_1 V_189 ;
int V_169 ;
int V_42 ;
int V_8 ;
for ( V_169 = * V_183 ; V_169 < V_194 - 1 && V_41 -> V_59 [ V_169 ] ; V_169 ++ ) {
V_42 = V_41 -> V_60 [ V_169 ] ;
if ( V_42 + 1 < F_130 ( V_41 -> V_59 [ V_169 ] ) ) {
V_41 -> V_60 [ V_169 ] ++ ;
* V_183 = V_169 ;
F_140 ( * V_183 == 0 ) ;
return 0 ;
} else {
struct V_28 * V_192 ;
if ( V_41 -> V_59 [ * V_183 ] == V_4 -> V_197 )
V_192 = V_41 -> V_59 [ * V_183 ] ;
else
V_192 = V_41 -> V_59 [ * V_183 + 1 ] ;
V_189 = F_143 ( V_192 ) ;
V_8 = V_31 -> V_196 ( V_4 , V_41 -> V_59 [ * V_183 ] , V_31 ,
F_153 ( V_41 -> V_59 [ * V_183 ] ) ) ;
if ( V_8 )
return V_8 ;
if ( V_31 -> free ) {
struct V_28 * V_103 ;
V_103 = V_41 -> V_59 [ * V_183 ] ;
if ( V_2 ) {
F_146 ( V_103 ) ;
F_147 ( V_103 ) ;
F_148 ( V_2 , V_4 -> V_11 ,
V_103 ) ;
F_26 ( V_103 ) ;
F_149 ( V_103 ) ;
}
F_140 ( V_189 != V_55 ) ;
V_8 = F_150 ( V_4 ,
V_41 -> V_59 [ * V_183 ] -> V_36 ,
V_41 -> V_59 [ * V_183 ] -> V_37 ) ;
if ( V_8 )
return V_8 ;
}
F_145 ( V_41 -> V_59 [ * V_183 ] ) ;
V_41 -> V_59 [ * V_183 ] = NULL ;
* V_183 = V_169 + 1 ;
}
}
return 1 ;
}
static int F_154 ( struct V_1 * V_2 ,
struct V_3 * log , struct V_30 * V_31 )
{
int V_8 = 0 ;
int V_198 ;
int V_183 ;
struct V_40 * V_41 ;
int V_199 ;
V_41 = F_89 () ;
if ( ! V_41 )
return - V_63 ;
V_183 = F_23 ( log -> V_197 ) ;
V_199 = V_183 ;
V_41 -> V_59 [ V_183 ] = log -> V_197 ;
F_155 ( log -> V_197 ) ;
V_41 -> V_60 [ V_183 ] = 0 ;
while ( 1 ) {
V_198 = F_139 ( V_2 , log , V_41 , & V_183 , V_31 ) ;
if ( V_198 > 0 )
break;
if ( V_198 < 0 ) {
V_8 = V_198 ;
goto V_13;
}
V_198 = F_152 ( V_2 , log , V_41 , & V_183 , V_31 ) ;
if ( V_198 > 0 )
break;
if ( V_198 < 0 ) {
V_8 = V_198 ;
goto V_13;
}
}
if ( V_41 -> V_59 [ V_199 ] ) {
V_8 = V_31 -> V_196 ( log , V_41 -> V_59 [ V_199 ] , V_31 ,
F_153 ( V_41 -> V_59 [ V_199 ] ) ) ;
if ( V_8 )
goto V_13;
if ( V_31 -> free ) {
struct V_28 * V_103 ;
V_103 = V_41 -> V_59 [ V_199 ] ;
if ( V_2 ) {
F_146 ( V_103 ) ;
F_147 ( V_103 ) ;
F_148 ( V_2 , log -> V_11 , V_103 ) ;
F_26 ( V_103 ) ;
F_149 ( V_103 ) ;
}
F_140 ( log -> V_53 . V_54 !=
V_55 ) ;
V_8 = F_150 ( log , V_103 -> V_36 ,
V_103 -> V_37 ) ;
if ( V_8 )
goto V_13;
}
}
V_13:
F_93 ( V_41 ) ;
return V_8 ;
}
static int F_156 ( struct V_1 * V_2 ,
struct V_3 * log )
{
int V_8 ;
if ( log -> V_21 == 1 ) {
V_8 = F_157 ( V_2 , log -> V_11 -> V_25 ,
& log -> V_53 , & log -> V_200 ) ;
} else {
V_8 = F_158 ( V_2 , log -> V_11 -> V_25 ,
& log -> V_53 , & log -> V_200 ) ;
}
return V_8 ;
}
static void F_159 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_79 )
{
F_160 ( V_39 ) ;
int V_7 = V_79 % 2 ;
do {
F_161 ( & V_4 -> V_201 [ V_7 ] ,
& V_39 , V_202 ) ;
F_8 ( & V_4 -> V_9 ) ;
if ( V_4 -> V_203 < V_79 &&
F_162 ( & V_4 -> V_204 [ V_7 ] ) )
F_163 () ;
F_164 ( & V_4 -> V_201 [ V_7 ] , & V_39 ) ;
F_2 ( & V_4 -> V_9 ) ;
} while ( V_4 -> V_203 < V_79 &&
F_162 ( & V_4 -> V_204 [ V_7 ] ) );
}
static void F_165 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_160 ( V_39 ) ;
while ( F_162 ( & V_4 -> V_20 ) ) {
F_161 ( & V_4 -> V_27 ,
& V_39 , V_202 ) ;
F_8 ( & V_4 -> V_9 ) ;
if ( F_162 ( & V_4 -> V_20 ) )
F_163 () ;
F_164 ( & V_4 -> V_27 , & V_39 ) ;
F_2 ( & V_4 -> V_9 ) ;
}
}
static inline void F_166 ( struct V_3 * V_4 ,
struct V_5 * V_6 )
{
if ( ! V_6 )
return;
F_2 ( & V_4 -> V_9 ) ;
F_167 ( & V_6 -> V_22 ) ;
F_8 ( & V_4 -> V_9 ) ;
}
static inline void F_168 ( struct V_3 * V_4 ,
int V_7 , int error )
{
struct V_5 * V_6 ;
if ( ! error ) {
F_169 ( & V_4 -> V_23 [ V_7 ] ) ;
return;
}
F_170 (ctx, &root->log_ctxs[index], list)
V_6 -> V_205 = error ;
F_169 ( & V_4 -> V_23 [ V_7 ] ) ;
}
int F_171 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_5 * V_6 )
{
int V_206 ;
int V_207 ;
int V_208 ;
int V_8 ;
struct V_3 * log = V_4 -> V_10 ;
struct V_3 * V_25 = V_4 -> V_11 -> V_25 ;
int V_21 = 0 ;
struct V_5 V_209 ;
struct V_210 V_211 ;
F_2 ( & V_4 -> V_9 ) ;
V_21 = V_6 -> V_21 ;
if ( V_4 -> V_203 >= V_21 ) {
F_8 ( & V_4 -> V_9 ) ;
return V_6 -> V_205 ;
}
V_206 = V_21 % 2 ;
if ( F_162 ( & V_4 -> V_204 [ V_206 ] ) ) {
F_159 ( V_2 , V_4 , V_21 ) ;
F_8 ( & V_4 -> V_9 ) ;
return V_6 -> V_205 ;
}
ASSERT ( V_21 == V_4 -> V_21 ) ;
F_172 ( & V_4 -> V_204 [ V_206 ] , 1 ) ;
if ( F_162 ( & V_4 -> V_204 [ ( V_206 + 1 ) % 2 ] ) )
F_159 ( V_2 , V_4 , V_21 - 1 ) ;
while ( 1 ) {
int V_212 = F_162 ( & V_4 -> V_19 ) ;
if ( ! F_173 ( V_4 , V_213 ) &&
F_174 ( V_17 , & V_4 -> V_18 ) ) {
F_8 ( & V_4 -> V_9 ) ;
F_175 ( 1 ) ;
F_2 ( & V_4 -> V_9 ) ;
}
F_165 ( V_2 , V_4 ) ;
if ( V_212 == F_162 ( & V_4 -> V_19 ) )
break;
}
if ( F_3 ( V_4 -> V_11 , V_2 ) ) {
V_8 = - V_12 ;
F_176 ( log , V_21 ) ;
F_8 ( & V_4 -> V_9 ) ;
goto V_13;
}
if ( V_21 % 2 == 0 )
V_208 = V_214 ;
else
V_208 = V_215 ;
F_177 ( & V_211 ) ;
V_8 = F_178 ( log , & log -> V_216 , V_208 ) ;
if ( V_8 ) {
F_179 ( & V_211 ) ;
F_180 ( V_2 , V_4 , V_8 ) ;
F_176 ( log , V_21 ) ;
F_181 ( V_4 -> V_11 , V_2 ) ;
F_8 ( & V_4 -> V_9 ) ;
goto V_13;
}
F_182 ( & log -> V_200 , log -> V_197 ) ;
V_4 -> V_21 ++ ;
log -> V_21 = V_4 -> V_21 ;
V_4 -> V_14 = 0 ;
F_8 ( & V_4 -> V_9 ) ;
F_183 ( & V_209 ) ;
F_2 ( & V_25 -> V_9 ) ;
F_6 ( & V_25 -> V_19 ) ;
F_6 ( & V_25 -> V_20 ) ;
V_207 = V_25 -> V_21 % 2 ;
F_7 ( & V_209 . V_22 , & V_25 -> V_23 [ V_207 ] ) ;
V_209 . V_21 = V_25 -> V_21 ;
F_8 ( & V_25 -> V_9 ) ;
V_8 = F_156 ( V_2 , log ) ;
F_2 ( & V_25 -> V_9 ) ;
if ( F_15 ( & V_25 -> V_20 ) ) {
F_12 () ;
if ( F_16 ( & V_25 -> V_27 ) )
F_17 ( & V_25 -> V_27 ) ;
}
if ( V_8 ) {
if ( ! F_71 ( & V_209 . V_22 ) )
F_167 ( & V_209 . V_22 ) ;
F_179 ( & V_211 ) ;
F_181 ( V_4 -> V_11 , V_2 ) ;
if ( V_8 != - V_217 ) {
F_180 ( V_2 , V_4 , V_8 ) ;
F_8 ( & V_25 -> V_9 ) ;
goto V_13;
}
F_184 ( log , & log -> V_216 , V_208 ) ;
F_176 ( log , V_21 ) ;
F_8 ( & V_25 -> V_9 ) ;
V_8 = - V_12 ;
goto V_13;
}
if ( V_25 -> V_203 >= V_209 . V_21 ) {
F_179 ( & V_211 ) ;
F_8 ( & V_25 -> V_9 ) ;
V_8 = V_209 . V_205 ;
goto V_13;
}
V_207 = V_209 . V_21 % 2 ;
if ( F_162 ( & V_25 -> V_204 [ V_207 ] ) ) {
F_179 ( & V_211 ) ;
V_8 = F_184 ( log , & log -> V_216 ,
V_208 ) ;
F_185 ( V_2 , log , V_21 ) ;
F_159 ( V_2 , V_25 ,
V_209 . V_21 ) ;
F_8 ( & V_25 -> V_9 ) ;
if ( ! V_8 )
V_8 = V_209 . V_205 ;
goto V_13;
}
ASSERT ( V_209 . V_21 == V_25 -> V_21 ) ;
F_172 ( & V_25 -> V_204 [ V_207 ] , 1 ) ;
if ( F_162 ( & V_25 -> V_204 [ ( V_207 + 1 ) % 2 ] ) ) {
F_159 ( V_2 , V_25 ,
V_209 . V_21 - 1 ) ;
}
F_165 ( V_2 , V_25 ) ;
if ( F_3 ( V_4 -> V_11 , V_2 ) ) {
F_179 ( & V_211 ) ;
F_184 ( log , & log -> V_216 , V_208 ) ;
F_176 ( log , V_21 ) ;
F_8 ( & V_25 -> V_9 ) ;
V_8 = - V_12 ;
goto V_218;
}
V_8 = F_178 ( V_25 ,
& V_25 -> V_216 ,
V_214 | V_215 ) ;
F_179 ( & V_211 ) ;
if ( V_8 ) {
F_181 ( V_4 -> V_11 , V_2 ) ;
F_180 ( V_2 , V_4 , V_8 ) ;
F_176 ( log , V_21 ) ;
F_8 ( & V_25 -> V_9 ) ;
goto V_218;
}
V_8 = F_184 ( log , & log -> V_216 , V_208 ) ;
if ( ! V_8 )
V_8 = F_184 ( V_25 ,
& V_25 -> V_216 ,
V_215 | V_214 ) ;
if ( V_8 ) {
F_181 ( V_4 -> V_11 , V_2 ) ;
F_176 ( log , V_21 ) ;
F_8 ( & V_25 -> V_9 ) ;
goto V_218;
}
F_185 ( V_2 , log , V_21 ) ;
F_186 ( V_4 -> V_11 -> V_219 ,
V_25 -> V_197 -> V_36 ) ;
F_187 ( V_4 -> V_11 -> V_219 ,
F_23 ( V_25 -> V_197 ) ) ;
V_25 -> V_21 ++ ;
F_8 ( & V_25 -> V_9 ) ;
V_8 = F_188 ( V_2 , V_4 -> V_11 -> V_220 , 1 ) ;
if ( V_8 ) {
F_181 ( V_4 -> V_11 , V_2 ) ;
F_180 ( V_2 , V_4 , V_8 ) ;
goto V_218;
}
F_2 ( & V_4 -> V_9 ) ;
if ( V_4 -> V_221 < V_21 )
V_4 -> V_221 = V_21 ;
F_8 ( & V_4 -> V_9 ) ;
V_218:
F_168 ( V_25 , V_207 , V_8 ) ;
F_2 ( & V_25 -> V_9 ) ;
V_25 -> V_203 ++ ;
F_172 ( & V_25 -> V_204 [ V_207 ] , 0 ) ;
F_8 ( & V_25 -> V_9 ) ;
if ( F_16 ( & V_25 -> V_201 [ V_207 ] ) )
F_17 ( & V_25 -> V_201 [ V_207 ] ) ;
V_13:
F_168 ( V_4 , V_206 , V_8 ) ;
F_2 ( & V_4 -> V_9 ) ;
V_4 -> V_203 ++ ;
F_172 ( & V_4 -> V_204 [ V_206 ] , 0 ) ;
F_8 ( & V_4 -> V_9 ) ;
if ( F_16 ( & V_4 -> V_201 [ V_206 ] ) )
F_17 ( & V_4 -> V_201 [ V_206 ] ) ;
return V_8 ;
}
static void F_189 ( struct V_1 * V_2 ,
struct V_3 * log )
{
int V_8 ;
T_1 V_36 ;
T_1 V_222 ;
struct V_30 V_31 = {
. free = 1 ,
. V_196 = F_18
} ;
V_8 = F_154 ( V_2 , log , & V_31 ) ;
if ( V_8 )
F_180 ( V_2 , log , V_8 ) ;
while ( 1 ) {
V_8 = F_190 ( & log -> V_216 ,
0 , & V_36 , & V_222 , V_214 | V_215 ,
NULL ) ;
if ( V_8 )
break;
F_191 ( & log -> V_216 , V_36 , V_222 ,
V_214 | V_215 , V_62 ) ;
}
F_176 ( log , 0 ) ;
F_176 ( log , 1 ) ;
F_145 ( log -> V_197 ) ;
F_33 ( log ) ;
}
int F_192 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( V_4 -> V_10 ) {
F_189 ( V_2 , V_4 -> V_10 ) ;
V_4 -> V_10 = NULL ;
}
return 0 ;
}
int F_193 ( struct V_1 * V_2 ,
struct V_223 * V_11 )
{
if ( V_11 -> V_25 ) {
F_189 ( V_2 , V_11 -> V_25 ) ;
V_11 -> V_25 = NULL ;
}
return 0 ;
}
int F_194 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_108 , int V_109 ,
struct V_84 * V_105 , T_1 V_7 )
{
struct V_3 * log ;
struct V_106 * V_107 ;
struct V_40 * V_41 ;
int V_8 ;
int V_224 = 0 ;
int V_225 = 0 ;
T_1 V_226 = F_61 ( V_105 ) ;
if ( F_115 ( V_105 ) -> V_227 < V_2 -> V_79 )
return 0 ;
V_8 = F_11 ( V_4 ) ;
if ( V_8 )
return 0 ;
F_2 ( & F_115 ( V_105 ) -> V_9 ) ;
log = V_4 -> V_10 ;
V_41 = F_89 () ;
if ( ! V_41 ) {
V_224 = - V_63 ;
goto V_228;
}
V_107 = F_87 ( V_2 , log , V_41 , V_226 ,
V_108 , V_109 , - 1 ) ;
if ( F_86 ( V_107 ) ) {
V_224 = F_133 ( V_107 ) ;
goto V_229;
}
if ( V_107 ) {
V_8 = F_137 ( V_2 , log , V_41 , V_107 ) ;
V_225 += V_109 ;
if ( V_8 ) {
V_224 = V_8 ;
goto V_229;
}
}
F_31 ( V_41 ) ;
V_107 = F_85 ( V_2 , log , V_41 , V_226 ,
V_7 , V_108 , V_109 , - 1 ) ;
if ( F_86 ( V_107 ) ) {
V_224 = F_133 ( V_107 ) ;
goto V_229;
}
if ( V_107 ) {
V_8 = F_137 ( V_2 , log , V_41 , V_107 ) ;
V_225 += V_109 ;
if ( V_8 ) {
V_224 = V_8 ;
goto V_229;
}
}
if ( V_225 ) {
struct V_43 V_44 ;
V_44 . V_54 = V_226 ;
V_44 . V_82 = 0 ;
V_44 . type = V_52 ;
F_31 ( V_41 ) ;
V_8 = F_30 ( V_2 , log , & V_44 , V_41 , 0 , 1 ) ;
if ( V_8 < 0 ) {
V_224 = V_8 ;
goto V_229;
}
if ( V_8 == 0 ) {
struct V_64 * V_65 ;
T_1 V_159 ;
V_65 = F_35 ( V_41 -> V_59 [ 0 ] , V_41 -> V_60 [ 0 ] ,
struct V_64 ) ;
V_159 = F_45 ( V_41 -> V_59 [ 0 ] , V_65 ) ;
if ( V_159 > V_225 )
V_159 -= V_225 ;
else
V_159 = 0 ;
F_40 ( V_41 -> V_59 [ 0 ] , V_65 , V_159 ) ;
F_51 ( V_41 -> V_59 [ 0 ] ) ;
} else
V_8 = 0 ;
F_31 ( V_41 ) ;
}
V_229:
F_93 ( V_41 ) ;
V_228:
F_8 ( & F_115 ( V_105 ) -> V_9 ) ;
if ( V_8 == - V_217 ) {
F_181 ( V_4 -> V_11 , V_2 ) ;
V_8 = 0 ;
} else if ( V_8 < 0 )
F_180 ( V_2 , V_4 , V_8 ) ;
F_14 ( V_4 ) ;
return V_224 ;
}
int F_195 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_108 , int V_109 ,
struct V_84 * V_84 , T_1 V_111 )
{
struct V_3 * log ;
T_1 V_7 ;
int V_8 ;
if ( F_115 ( V_84 ) -> V_227 < V_2 -> V_79 )
return 0 ;
V_8 = F_11 ( V_4 ) ;
if ( V_8 )
return 0 ;
log = V_4 -> V_10 ;
F_2 ( & F_115 ( V_84 ) -> V_9 ) ;
V_8 = F_196 ( V_2 , log , V_108 , V_109 , F_61 ( V_84 ) ,
V_111 , & V_7 ) ;
F_8 ( & F_115 ( V_84 ) -> V_9 ) ;
if ( V_8 == - V_217 ) {
F_181 ( V_4 -> V_11 , V_2 ) ;
V_8 = 0 ;
} else if ( V_8 < 0 && V_8 != - V_26 )
F_180 ( V_2 , V_4 , V_8 ) ;
F_14 ( V_4 ) ;
return V_8 ;
}
static T_2 int F_197 ( struct V_1 * V_2 ,
struct V_3 * log ,
struct V_40 * V_41 ,
int V_160 , T_1 V_111 ,
T_1 V_230 , T_1 V_231 )
{
int V_8 ;
struct V_43 V_44 ;
struct V_164 * V_65 ;
V_44 . V_54 = V_111 ;
V_44 . V_82 = V_230 ;
if ( V_160 == V_157 )
V_44 . type = V_179 ;
else
V_44 . type = V_181 ;
V_8 = F_41 ( V_2 , log , V_41 , & V_44 , sizeof( * V_65 ) ) ;
if ( V_8 )
return V_8 ;
V_65 = F_35 ( V_41 -> V_59 [ 0 ] , V_41 -> V_60 [ 0 ] ,
struct V_164 ) ;
F_198 ( V_41 -> V_59 [ 0 ] , V_65 , V_231 ) ;
F_51 ( V_41 -> V_59 [ 0 ] ) ;
F_31 ( V_41 ) ;
return 0 ;
}
static T_2 int F_199 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_84 * V_84 ,
struct V_40 * V_41 ,
struct V_40 * V_232 , int V_160 ,
struct V_5 * V_6 ,
T_1 V_233 , T_1 * V_234 )
{
struct V_43 V_235 ;
struct V_3 * log = V_4 -> V_10 ;
struct V_28 * V_236 ;
int V_224 = 0 ;
int V_8 ;
int V_169 ;
int V_165 ;
T_1 V_230 = V_233 ;
T_1 V_231 = ( T_1 ) - 1 ;
T_1 V_142 = F_61 ( V_84 ) ;
log = V_4 -> V_10 ;
V_235 . V_54 = V_142 ;
V_235 . type = V_160 ;
V_235 . V_82 = V_233 ;
V_8 = F_200 ( V_4 , & V_235 , V_41 , V_2 -> V_79 ) ;
if ( V_8 != 0 || V_235 . V_54 != V_142 || V_235 . type != V_160 ) {
V_235 . V_54 = V_142 ;
V_235 . type = V_160 ;
V_235 . V_82 = ( T_1 ) - 1 ;
F_31 ( V_41 ) ;
V_8 = F_30 ( NULL , V_4 , & V_235 , V_41 , 0 , 0 ) ;
if ( V_8 < 0 ) {
F_31 ( V_41 ) ;
return V_8 ;
}
V_8 = F_201 ( V_4 , V_41 , V_142 , V_160 ) ;
if ( V_8 == 0 ) {
struct V_43 V_237 ;
F_112 ( V_41 -> V_59 [ 0 ] , & V_237 ,
V_41 -> V_60 [ 0 ] ) ;
if ( V_160 == V_237 . type )
V_230 = F_202 ( V_233 , V_237 . V_82 ) + 1 ;
}
goto V_238;
}
V_8 = F_201 ( V_4 , V_41 , V_142 , V_160 ) ;
if ( V_8 == 0 ) {
struct V_43 V_237 ;
F_112 ( V_41 -> V_59 [ 0 ] , & V_237 , V_41 -> V_60 [ 0 ] ) ;
if ( V_160 == V_237 . type ) {
V_230 = V_237 . V_82 ;
V_8 = F_27 ( V_2 , log , V_232 ,
V_41 -> V_59 [ 0 ] , V_41 -> V_60 [ 0 ] ,
& V_237 ) ;
if ( V_8 ) {
V_224 = V_8 ;
goto V_238;
}
}
}
F_31 ( V_41 ) ;
V_8 = F_30 ( NULL , V_4 , & V_235 , V_41 , 0 , 0 ) ;
if ( F_140 ( V_8 != 0 ) )
goto V_238;
while ( 1 ) {
struct V_43 V_237 ;
V_236 = V_41 -> V_59 [ 0 ] ;
V_165 = F_130 ( V_236 ) ;
for ( V_169 = V_41 -> V_60 [ 0 ] ; V_169 < V_165 ; V_169 ++ ) {
struct V_106 * V_107 ;
F_112 ( V_236 , & V_235 , V_169 ) ;
if ( V_235 . V_54 != V_142 || V_235 . type != V_160 )
goto V_238;
V_8 = F_27 ( V_2 , log , V_232 , V_236 , V_169 ,
& V_235 ) ;
if ( V_8 ) {
V_224 = V_8 ;
goto V_238;
}
V_107 = F_35 ( V_236 , V_169 , struct V_106 ) ;
F_79 ( V_236 , V_107 , & V_237 ) ;
if ( V_6 &&
( F_203 ( V_236 , V_107 ) == V_2 -> V_79 ||
F_123 ( V_236 , V_107 ) == V_239 ) &&
V_237 . type != V_240 )
V_6 -> V_241 = true ;
}
V_41 -> V_60 [ 0 ] = V_165 ;
V_8 = F_131 ( V_4 , V_41 ) ;
if ( V_8 == 1 ) {
V_231 = ( T_1 ) - 1 ;
goto V_238;
}
F_112 ( V_41 -> V_59 [ 0 ] , & V_237 , V_41 -> V_60 [ 0 ] ) ;
if ( V_237 . V_54 != V_142 || V_237 . type != V_160 ) {
V_231 = ( T_1 ) - 1 ;
goto V_238;
}
if ( F_153 ( V_41 -> V_59 [ 0 ] ) != V_2 -> V_79 ) {
V_8 = F_27 ( V_2 , log , V_232 ,
V_41 -> V_59 [ 0 ] , V_41 -> V_60 [ 0 ] ,
& V_237 ) ;
if ( V_8 )
V_224 = V_8 ;
else
V_231 = V_237 . V_82 ;
goto V_238;
}
}
V_238:
F_31 ( V_41 ) ;
F_31 ( V_232 ) ;
if ( V_224 == 0 ) {
* V_234 = V_231 ;
V_8 = F_197 ( V_2 , log , V_41 , V_160 ,
V_142 , V_230 , V_231 ) ;
if ( V_8 )
V_224 = V_8 ;
}
return V_224 ;
}
static T_2 int F_204 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_84 * V_84 ,
struct V_40 * V_41 ,
struct V_40 * V_232 ,
struct V_5 * V_6 )
{
T_1 V_235 ;
T_1 V_242 ;
int V_8 ;
int V_160 = V_157 ;
V_131:
V_235 = 0 ;
V_242 = 0 ;
while ( 1 ) {
V_8 = F_199 ( V_2 , V_4 , V_84 , V_41 ,
V_232 , V_160 , V_6 , V_235 ,
& V_242 ) ;
if ( V_8 )
return V_8 ;
if ( V_242 == ( T_1 ) - 1 )
break;
V_235 = V_242 + 1 ;
}
if ( V_160 == V_157 ) {
V_160 = V_156 ;
goto V_131;
}
return 0 ;
}
static int F_205 ( struct V_1 * V_2 ,
struct V_3 * log ,
struct V_40 * V_41 ,
T_1 V_54 , int V_243 )
{
int V_8 ;
struct V_43 V_44 ;
struct V_43 V_151 ;
int V_244 ;
V_44 . V_54 = V_54 ;
V_44 . type = V_243 ;
V_44 . V_82 = ( T_1 ) - 1 ;
while ( 1 ) {
V_8 = F_30 ( V_2 , log , & V_44 , V_41 , - 1 , 1 ) ;
F_206 ( V_8 == 0 ) ;
if ( V_8 < 0 )
break;
if ( V_41 -> V_60 [ 0 ] == 0 )
break;
V_41 -> V_60 [ 0 ] -- ;
F_112 ( V_41 -> V_59 [ 0 ] , & V_151 ,
V_41 -> V_60 [ 0 ] ) ;
if ( V_151 . V_54 != V_54 )
break;
V_151 . V_82 = 0 ;
V_151 . type = 0 ;
V_8 = F_207 ( V_41 -> V_59 [ 0 ] , & V_151 , 0 ,
& V_244 ) ;
V_8 = F_208 ( V_2 , log , V_41 , V_244 ,
V_41 -> V_60 [ 0 ] - V_244 + 1 ) ;
if ( V_8 || V_244 != 0 )
break;
F_31 ( V_41 ) ;
}
F_31 ( V_41 ) ;
if ( V_8 > 0 )
V_8 = 0 ;
return V_8 ;
}
static void F_209 ( struct V_1 * V_2 ,
struct V_28 * V_94 ,
struct V_64 * V_65 ,
struct V_84 * V_84 , int V_245 ,
T_1 V_246 )
{
struct V_76 V_77 ;
F_47 ( & V_77 ) ;
if ( V_245 ) {
F_210 ( V_94 , V_65 , 0 , & V_77 ) ;
F_48 ( V_94 , V_65 , V_246 , & V_77 ) ;
} else {
F_210 ( V_94 , V_65 ,
F_115 ( V_84 ) -> V_247 ,
& V_77 ) ;
F_48 ( V_94 , V_65 , V_84 -> V_159 , & V_77 ) ;
}
F_211 ( V_94 , V_65 , F_212 ( V_84 ) , & V_77 ) ;
F_213 ( V_94 , V_65 , F_214 ( V_84 ) , & V_77 ) ;
F_215 ( V_94 , V_65 , V_84 -> V_147 , & V_77 ) ;
F_216 ( V_94 , V_65 , V_84 -> V_145 , & V_77 ) ;
F_217 ( V_94 , & V_65 -> V_248 ,
V_84 -> V_249 . V_250 , & V_77 ) ;
F_218 ( V_94 , & V_65 -> V_248 ,
V_84 -> V_249 . V_251 , & V_77 ) ;
F_217 ( V_94 , & V_65 -> V_252 ,
V_84 -> V_253 . V_250 , & V_77 ) ;
F_218 ( V_94 , & V_65 -> V_252 ,
V_84 -> V_253 . V_251 , & V_77 ) ;
F_217 ( V_94 , & V_65 -> ctime ,
V_84 -> V_254 . V_250 , & V_77 ) ;
F_218 ( V_94 , & V_65 -> ctime ,
V_84 -> V_254 . V_251 , & V_77 ) ;
F_219 ( V_94 , V_65 , F_220 ( V_84 ) ,
& V_77 ) ;
F_221 ( V_94 , V_65 , V_84 -> V_255 , & V_77 ) ;
F_222 ( V_94 , V_65 , V_2 -> V_79 , & V_77 ) ;
F_223 ( V_94 , V_65 , V_84 -> V_256 , & V_77 ) ;
F_224 ( V_94 , V_65 , F_115 ( V_84 ) -> V_257 , & V_77 ) ;
F_225 ( V_94 , V_65 , 0 , & V_77 ) ;
}
static int F_226 ( struct V_1 * V_2 ,
struct V_3 * log , struct V_40 * V_41 ,
struct V_84 * V_84 )
{
struct V_64 * V_51 ;
int V_8 ;
V_8 = F_41 ( V_2 , log , V_41 ,
& F_115 ( V_84 ) -> V_110 ,
sizeof( * V_51 ) ) ;
if ( V_8 && V_8 != - V_69 )
return V_8 ;
V_51 = F_35 ( V_41 -> V_59 [ 0 ] , V_41 -> V_60 [ 0 ] ,
struct V_64 ) ;
F_209 ( V_2 , V_41 -> V_59 [ 0 ] , V_51 , V_84 , 0 , 0 ) ;
F_31 ( V_41 ) ;
return 0 ;
}
static T_2 int F_227 ( struct V_1 * V_2 ,
struct V_84 * V_84 ,
struct V_40 * V_232 ,
struct V_40 * V_258 , T_1 * V_259 ,
int V_244 , int V_260 , int V_261 ,
T_1 V_246 )
{
unsigned long V_262 ;
unsigned long V_263 ;
struct V_3 * log = F_115 ( V_84 ) -> V_4 -> V_10 ;
struct V_83 * V_264 ;
struct V_64 * V_51 ;
struct V_28 * V_236 = V_258 -> V_59 [ 0 ] ;
struct V_43 V_265 , V_266 , V_44 ;
int V_8 ;
struct V_43 * V_267 ;
T_3 * V_268 ;
char * V_269 ;
int V_169 ;
struct V_270 V_100 ;
int V_271 = F_115 ( V_84 ) -> V_257 & V_272 ;
bool V_273 = false ;
bool V_274 = true ;
bool V_238 = false ;
F_169 ( & V_100 ) ;
V_269 = F_32 ( V_260 * sizeof( struct V_43 ) +
V_260 * sizeof( T_3 ) , V_62 ) ;
if ( ! V_269 )
return - V_63 ;
V_265 . V_54 = ( T_1 ) - 1 ;
V_268 = ( T_3 * ) V_269 ;
V_267 = (struct V_43 * ) ( V_269 + V_260 * sizeof( T_3 ) ) ;
for ( V_169 = 0 ; V_169 < V_260 ; V_169 ++ ) {
V_268 [ V_169 ] = F_28 ( V_236 , V_169 + V_244 ) ;
F_112 ( V_236 , V_267 + V_169 , V_169 + V_244 ) ;
}
V_8 = F_228 ( V_2 , log , V_232 ,
V_267 , V_268 , V_260 ) ;
if ( V_8 ) {
F_33 ( V_269 ) ;
return V_8 ;
}
for ( V_169 = 0 ; V_169 < V_260 ; V_169 ++ , V_232 -> V_60 [ 0 ] ++ ) {
V_263 = F_29 ( V_232 -> V_59 [ 0 ] ,
V_232 -> V_60 [ 0 ] ) ;
V_262 = F_29 ( V_236 , V_244 + V_169 ) ;
if ( ( V_169 == ( V_260 - 1 ) ) )
V_266 = V_267 [ V_169 ] ;
if ( V_267 [ V_169 ] . type == V_52 ) {
V_51 = F_35 ( V_232 -> V_59 [ 0 ] ,
V_232 -> V_60 [ 0 ] ,
struct V_64 ) ;
F_209 ( V_2 , V_232 -> V_59 [ 0 ] , V_51 ,
V_84 , V_261 == V_275 ,
V_246 ) ;
} else {
F_49 ( V_232 -> V_59 [ 0 ] , V_236 , V_263 ,
V_262 , V_268 [ V_169 ] ) ;
}
if ( V_267 [ V_169 ] . type == V_188 ) {
V_273 = true ;
if ( V_265 . V_54 == ( T_1 ) - 1 )
V_265 = V_267 [ V_169 ] ;
} else {
V_274 = false ;
}
if ( V_267 [ V_169 ] . type == V_188 &&
! V_271 ) {
int V_80 ;
V_264 = F_35 ( V_236 , V_244 + V_169 ,
struct V_83 ) ;
if ( F_229 ( V_236 , V_264 ) < V_2 -> V_79 )
continue;
V_80 = F_53 ( V_236 , V_264 ) ;
if ( V_80 == V_86 ) {
T_1 V_276 , V_277 , V_278 , V_279 ;
V_276 = F_55 ( V_236 ,
V_264 ) ;
if ( V_276 == 0 )
continue;
V_277 = F_63 ( V_236 ,
V_264 ) ;
V_278 = F_64 ( V_236 , V_264 ) ;
V_279 = F_54 ( V_236 ,
V_264 ) ;
if ( F_69 ( V_236 ,
V_264 ) ) {
V_278 = 0 ;
V_279 = V_277 ;
}
V_8 = F_70 (
log -> V_11 -> V_104 ,
V_276 + V_278 , V_276 + V_278 + V_279 - 1 ,
& V_100 , 0 ) ;
if ( V_8 ) {
F_31 ( V_232 ) ;
F_33 ( V_269 ) ;
return V_8 ;
}
}
}
}
F_51 ( V_232 -> V_59 [ 0 ] ) ;
F_31 ( V_232 ) ;
F_33 ( V_269 ) ;
V_8 = 0 ;
while ( ! F_71 ( & V_100 ) ) {
struct V_101 * V_102 = F_72 ( V_100 . V_103 ,
struct V_101 ,
V_22 ) ;
if ( ! V_8 )
V_8 = F_73 ( V_2 , log , V_102 ) ;
F_74 ( & V_102 -> V_22 ) ;
F_33 ( V_102 ) ;
}
if ( ! V_273 )
return V_8 ;
if ( V_274 && * V_259 == V_265 . V_82 ) {
V_274 = false ;
}
if ( V_274 ) {
T_1 V_37 ;
V_8 = F_230 ( F_115 ( V_84 ) -> V_4 , V_258 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( V_8 )
goto V_280;
if ( V_258 -> V_60 [ 0 ] )
V_258 -> V_60 [ 0 ] -- ;
V_236 = V_258 -> V_59 [ 0 ] ;
F_112 ( V_236 , & V_44 , V_258 -> V_60 [ 0 ] ) ;
if ( V_44 . V_54 != F_61 ( V_84 ) ||
V_44 . type != V_188 )
goto V_280;
V_264 = F_35 ( V_236 , V_258 -> V_60 [ 0 ] ,
struct V_83 ) ;
if ( F_53 ( V_236 , V_264 ) ==
V_88 ) {
V_37 = F_56 ( V_236 ,
V_258 -> V_60 [ 0 ] ,
V_264 ) ;
* V_259 = F_58 ( V_44 . V_82 + V_37 ,
log -> V_89 ) ;
} else {
V_37 = F_54 ( V_236 , V_264 ) ;
* V_259 = V_44 . V_82 + V_37 ;
}
}
V_280:
if ( V_274 ) {
F_31 ( V_258 ) ;
V_8 = F_30 ( NULL , F_115 ( V_84 ) -> V_4 , & V_265 ,
V_258 , 0 , 0 ) ;
if ( V_8 < 0 )
return V_8 ;
ASSERT ( V_8 == 0 ) ;
V_236 = V_258 -> V_59 [ 0 ] ;
V_169 = V_258 -> V_60 [ 0 ] ;
} else {
V_169 = V_244 ;
}
while ( ! V_238 ) {
T_1 V_82 , V_37 ;
T_1 V_81 ;
if ( V_169 >= F_130 ( V_258 -> V_59 [ 0 ] ) ) {
V_8 = F_131 ( F_115 ( V_84 ) -> V_4 , V_258 ) ;
if ( V_8 < 0 )
return V_8 ;
ASSERT ( V_8 == 0 ) ;
V_236 = V_258 -> V_59 [ 0 ] ;
V_169 = 0 ;
}
F_112 ( V_236 , & V_44 , V_169 ) ;
if ( ! F_231 ( & V_44 , & V_266 ) )
V_238 = true ;
if ( V_44 . V_54 != F_61 ( V_84 ) ||
V_44 . type != V_188 ) {
V_169 ++ ;
continue;
}
V_264 = F_35 ( V_236 , V_169 , struct V_83 ) ;
if ( F_53 ( V_236 , V_264 ) ==
V_88 ) {
V_37 = F_56 ( V_236 , V_169 , V_264 ) ;
V_81 = F_58 ( V_44 . V_82 + V_37 , log -> V_89 ) ;
} else {
V_37 = F_54 ( V_236 , V_264 ) ;
V_81 = V_44 . V_82 + V_37 ;
}
V_169 ++ ;
if ( * V_259 == V_44 . V_82 ) {
* V_259 = V_81 ;
continue;
}
V_82 = * V_259 ;
V_37 = V_44 . V_82 - * V_259 ;
V_8 = F_232 ( V_2 , log , F_61 ( V_84 ) ,
V_82 , 0 , 0 , V_37 , 0 , V_37 , 0 ,
0 , 0 ) ;
if ( V_8 )
break;
* V_259 = V_81 ;
}
if ( ! V_8 && V_274 )
V_8 = 1 ;
return V_8 ;
}
static int F_233 ( void * V_281 , struct V_270 * V_282 , struct V_270 * V_283 )
{
struct V_284 * V_285 , * V_286 ;
V_285 = F_72 ( V_282 , struct V_284 , V_22 ) ;
V_286 = F_72 ( V_283 , struct V_284 , V_22 ) ;
if ( V_285 -> V_36 < V_286 -> V_36 )
return - 1 ;
else if ( V_285 -> V_36 > V_286 -> V_36 )
return 1 ;
return 0 ;
}
static int F_234 ( struct V_1 * V_2 ,
struct V_84 * V_84 ,
struct V_3 * V_4 ,
const struct V_284 * V_287 ,
const struct V_270 * V_288 ,
bool * V_289 )
{
struct V_290 * V_291 ;
struct V_3 * log = V_4 -> V_10 ;
T_1 V_292 = V_287 -> V_292 ;
T_1 V_293 = V_287 -> V_293 ;
const bool V_271 = F_115 ( V_84 ) -> V_257 & V_272 ;
T_1 V_294 ;
T_1 V_295 ;
F_65 ( V_100 ) ;
int V_8 = 0 ;
* V_289 = false ;
if ( F_174 ( V_296 , & V_287 -> V_257 ) ||
V_287 -> V_297 == V_298 )
return 0 ;
F_170 (ordered, logged_list, log_list) {
struct V_101 * V_299 ;
if ( ! V_293 )
break;
if ( V_291 -> V_300 + V_291 -> V_37 <= V_292 ||
V_292 + V_293 <= V_291 -> V_300 )
continue;
if ( ! F_174 ( V_301 , & V_291 -> V_257 ) &&
! F_174 ( V_302 , & V_291 -> V_257 ) &&
! F_174 ( V_303 , & V_291 -> V_257 ) ) {
const T_1 V_36 = V_291 -> V_300 ;
const T_1 V_222 = V_291 -> V_300 + V_291 -> V_37 - 1 ;
F_140 ( V_291 -> V_84 != V_84 ) ;
F_235 ( V_84 -> V_304 , V_36 , V_222 ) ;
}
F_236 ( V_291 -> V_39 ,
( F_174 ( V_301 , & V_291 -> V_257 ) ||
F_174 ( V_302 , & V_291 -> V_257 ) ) ) ;
if ( F_174 ( V_302 , & V_291 -> V_257 ) ) {
F_237 ( V_84 ) ;
* V_289 = true ;
break;
}
if ( V_291 -> V_300 > V_292 ) {
if ( V_291 -> V_300 + V_291 -> V_37 >=
V_292 + V_293 )
V_293 = V_291 -> V_300 - V_292 ;
} else {
if ( V_291 -> V_300 + V_291 -> V_37 <
V_292 + V_293 ) {
V_293 = ( V_292 + V_293 ) -
( V_291 -> V_300 + V_291 -> V_37 ) ;
V_292 = V_291 -> V_300 +
V_291 -> V_37 ;
} else {
V_293 = 0 ;
}
}
if ( V_271 )
continue;
if ( F_238 ( V_305 ,
& V_291 -> V_257 ) )
continue;
F_170 (sum, &ordered->list, list) {
V_8 = F_73 ( V_2 , log , V_299 ) ;
if ( V_8 )
break;
}
}
if ( * V_289 || ! V_293 || V_8 || V_271 )
return V_8 ;
if ( V_287 -> V_306 ) {
V_294 = 0 ;
V_295 = F_202 ( V_287 -> V_307 , V_287 -> V_308 ) ;
} else {
V_294 = V_292 - V_287 -> V_36 ;
V_295 = V_293 ;
}
V_8 = F_70 ( log -> V_11 -> V_104 ,
V_287 -> V_297 + V_294 ,
V_287 -> V_297 + V_294 +
V_295 - 1 , & V_100 , 0 ) ;
if ( V_8 )
return V_8 ;
while ( ! F_71 ( & V_100 ) ) {
struct V_101 * V_102 = F_72 ( V_100 . V_103 ,
struct V_101 ,
V_22 ) ;
if ( ! V_8 )
V_8 = F_73 ( V_2 , log , V_102 ) ;
F_74 ( & V_102 -> V_22 ) ;
F_33 ( V_102 ) ;
}
return V_8 ;
}
static int F_239 ( struct V_1 * V_2 ,
struct V_84 * V_84 , struct V_3 * V_4 ,
const struct V_284 * V_287 ,
struct V_40 * V_41 ,
const struct V_270 * V_288 ,
struct V_5 * V_6 )
{
struct V_3 * log = V_4 -> V_10 ;
struct V_83 * V_309 ;
struct V_28 * V_94 ;
struct V_76 V_77 ;
struct V_43 V_44 ;
T_1 V_310 = V_287 -> V_36 - V_287 -> V_311 ;
T_1 V_307 ;
int V_8 ;
int V_312 = 0 ;
bool V_313 = false ;
V_8 = F_234 ( V_2 , V_84 , V_4 , V_287 , V_288 ,
& V_313 ) ;
if ( V_8 )
return V_8 ;
if ( V_313 ) {
V_6 -> V_314 = - V_90 ;
return 0 ;
}
F_47 ( & V_77 ) ;
V_8 = F_240 ( V_2 , log , V_84 , V_41 , V_287 -> V_36 ,
V_287 -> V_36 + V_287 -> V_37 , NULL , 0 , 1 ,
sizeof( * V_309 ) , & V_312 ) ;
if ( V_8 )
return V_8 ;
if ( ! V_312 ) {
V_44 . V_54 = F_61 ( V_84 ) ;
V_44 . type = V_188 ;
V_44 . V_82 = V_287 -> V_36 ;
V_8 = F_41 ( V_2 , log , V_41 , & V_44 ,
sizeof( * V_309 ) ) ;
if ( V_8 )
return V_8 ;
}
V_94 = V_41 -> V_59 [ 0 ] ;
V_309 = F_35 ( V_94 , V_41 -> V_60 [ 0 ] ,
struct V_83 ) ;
F_241 ( V_94 , V_309 , V_2 -> V_79 ,
& V_77 ) ;
if ( F_174 ( V_296 , & V_287 -> V_257 ) )
F_242 ( V_94 , V_309 ,
V_87 ,
& V_77 ) ;
else
F_242 ( V_94 , V_309 ,
V_86 ,
& V_77 ) ;
V_307 = F_202 ( V_287 -> V_307 , V_287 -> V_308 ) ;
if ( V_287 -> V_306 != V_315 ) {
F_243 ( V_94 , V_309 ,
V_287 -> V_297 ,
& V_77 ) ;
F_244 ( V_94 , V_309 , V_307 ,
& V_77 ) ;
} else if ( V_287 -> V_297 < V_316 ) {
F_243 ( V_94 , V_309 ,
V_287 -> V_297 -
V_310 , & V_77 ) ;
F_244 ( V_94 , V_309 , V_307 ,
& V_77 ) ;
} else {
F_243 ( V_94 , V_309 , 0 , & V_77 ) ;
F_244 ( V_94 , V_309 , 0 ,
& V_77 ) ;
}
F_245 ( V_94 , V_309 , V_310 , & V_77 ) ;
F_246 ( V_94 , V_309 , V_287 -> V_37 , & V_77 ) ;
F_247 ( V_94 , V_309 , V_287 -> V_317 , & V_77 ) ;
F_248 ( V_94 , V_309 , V_287 -> V_306 ,
& V_77 ) ;
F_249 ( V_94 , V_309 , 0 , & V_77 ) ;
F_250 ( V_94 , V_309 , 0 , & V_77 ) ;
F_51 ( V_94 ) ;
F_31 ( V_41 ) ;
return V_8 ;
}
static int F_251 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_84 * V_84 ,
struct V_40 * V_41 ,
struct V_270 * V_288 ,
struct V_5 * V_6 )
{
struct V_284 * V_287 , * V_318 ;
struct V_270 V_319 ;
struct V_320 * V_321 = & F_115 ( V_84 ) -> V_322 ;
T_1 V_323 ;
int V_8 = 0 ;
int V_324 = 0 ;
F_169 ( & V_319 ) ;
F_252 ( & V_321 -> V_325 ) ;
V_323 = V_4 -> V_11 -> V_326 ;
F_253 (em, n, &tree->modified_extents, list) {
F_167 ( & V_287 -> V_22 ) ;
if ( ++ V_324 > 32768 ) {
F_167 ( & V_321 -> V_327 ) ;
V_8 = - V_328 ;
goto V_329;
}
if ( V_287 -> V_247 <= V_323 )
continue;
F_6 ( & V_287 -> V_330 ) ;
F_5 ( V_331 , & V_287 -> V_257 ) ;
F_7 ( & V_287 -> V_22 , & V_319 ) ;
V_324 ++ ;
}
F_254 ( NULL , & V_319 , F_233 ) ;
V_329:
while ( ! F_71 ( & V_319 ) ) {
V_287 = F_72 ( V_319 . V_103 , struct V_284 , V_22 ) ;
F_167 ( & V_287 -> V_22 ) ;
if ( V_8 ) {
F_255 ( V_321 , V_287 ) ;
F_256 ( V_287 ) ;
continue;
}
F_257 ( & V_321 -> V_325 ) ;
V_8 = F_239 ( V_2 , V_84 , V_4 , V_287 , V_41 , V_288 ,
V_6 ) ;
F_252 ( & V_321 -> V_325 ) ;
F_255 ( V_321 , V_287 ) ;
F_256 ( V_287 ) ;
}
F_140 ( ! F_71 ( & V_319 ) ) ;
F_257 ( & V_321 -> V_325 ) ;
F_31 ( V_41 ) ;
return V_8 ;
}
static int F_258 ( struct V_3 * log , struct V_84 * V_84 ,
struct V_40 * V_41 , T_1 * V_332 )
{
struct V_43 V_44 ;
int V_8 ;
V_44 . V_54 = F_61 ( V_84 ) ;
V_44 . type = V_52 ;
V_44 . V_82 = 0 ;
V_8 = F_30 ( NULL , log , & V_44 , V_41 , 0 , 0 ) ;
if ( V_8 < 0 ) {
return V_8 ;
} else if ( V_8 > 0 ) {
* V_332 = 0 ;
} else {
struct V_64 * V_65 ;
V_65 = F_35 ( V_41 -> V_59 [ 0 ] , V_41 -> V_60 [ 0 ] ,
struct V_64 ) ;
* V_332 = F_45 ( V_41 -> V_59 [ 0 ] , V_65 ) ;
}
F_31 ( V_41 ) ;
return 0 ;
}
static int F_259 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_84 * V_84 ,
struct V_40 * V_41 ,
struct V_40 * V_232 )
{
int V_8 ;
struct V_43 V_44 ;
const T_1 V_142 = F_61 ( V_84 ) ;
int V_333 = 0 ;
int V_244 = 0 ;
V_44 . V_54 = V_142 ;
V_44 . type = V_170 ;
V_44 . V_82 = 0 ;
V_8 = F_30 ( NULL , V_4 , & V_44 , V_41 , 0 , 0 ) ;
if ( V_8 < 0 )
return V_8 ;
while ( true ) {
int V_42 = V_41 -> V_60 [ 0 ] ;
struct V_28 * V_94 = V_41 -> V_59 [ 0 ] ;
int V_165 = F_130 ( V_94 ) ;
if ( V_42 >= V_165 ) {
if ( V_333 > 0 ) {
T_1 V_259 = 0 ;
V_8 = F_227 ( V_2 , V_84 , V_232 , V_41 ,
& V_259 , V_244 ,
V_333 , 1 , 0 ) ;
ASSERT ( V_8 <= 0 ) ;
if ( V_8 < 0 )
return V_8 ;
V_333 = 0 ;
}
V_8 = F_131 ( V_4 , V_41 ) ;
if ( V_8 < 0 )
return V_8 ;
else if ( V_8 > 0 )
break;
continue;
}
F_112 ( V_94 , & V_44 , V_42 ) ;
if ( V_44 . V_54 != V_142 || V_44 . type != V_170 )
break;
if ( V_333 == 0 )
V_244 = V_42 ;
V_333 ++ ;
V_41 -> V_60 [ 0 ] ++ ;
F_151 () ;
}
if ( V_333 > 0 ) {
T_1 V_259 = 0 ;
V_8 = F_227 ( V_2 , V_84 , V_232 , V_41 ,
& V_259 , V_244 ,
V_333 , 1 , 0 ) ;
ASSERT ( V_8 <= 0 ) ;
if ( V_8 < 0 )
return V_8 ;
}
return 0 ;
}
static int F_260 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_84 * V_84 ,
struct V_40 * V_41 )
{
int V_8 ;
struct V_43 V_44 ;
T_1 V_334 ;
T_1 V_335 ;
struct V_28 * V_94 ;
struct V_3 * log = V_4 -> V_10 ;
const T_1 V_142 = F_61 ( V_84 ) ;
const T_1 V_159 = F_261 ( V_84 ) ;
if ( ! F_19 ( V_4 -> V_11 , V_336 ) )
return 0 ;
V_44 . V_54 = V_142 ;
V_44 . type = V_188 ;
V_44 . V_82 = ( T_1 ) - 1 ;
V_8 = F_30 ( NULL , V_4 , & V_44 , V_41 , 0 , 0 ) ;
ASSERT ( V_8 != 0 ) ;
if ( V_8 < 0 )
return V_8 ;
ASSERT ( V_41 -> V_60 [ 0 ] > 0 ) ;
V_41 -> V_60 [ 0 ] -- ;
V_94 = V_41 -> V_59 [ 0 ] ;
F_112 ( V_94 , & V_44 , V_41 -> V_60 [ 0 ] ) ;
if ( V_44 . V_54 != V_142 || V_44 . type != V_188 ) {
V_334 = 0 ;
V_335 = V_159 ;
} else {
struct V_83 * V_264 ;
T_1 V_37 ;
if ( V_44 . V_82 >= V_159 )
return 0 ;
V_264 = F_35 ( V_94 , V_41 -> V_60 [ 0 ] ,
struct V_83 ) ;
if ( F_53 ( V_94 , V_264 ) ==
V_88 ) {
V_37 = F_56 ( V_94 ,
V_41 -> V_60 [ 0 ] ,
V_264 ) ;
ASSERT ( V_37 == V_159 ) ;
return 0 ;
}
V_37 = F_54 ( V_94 , V_264 ) ;
if ( V_44 . V_82 + V_37 > V_159 )
return 0 ;
V_334 = V_44 . V_82 + V_37 ;
V_335 = V_159 - V_334 ;
}
F_31 ( V_41 ) ;
if ( V_335 == 0 )
return 0 ;
V_335 = F_58 ( V_335 , V_4 -> V_89 ) ;
V_8 = F_232 ( V_2 , log , V_142 , V_334 , 0 , 0 ,
V_335 , 0 , V_335 , 0 , 0 , 0 ) ;
return V_8 ;
}
static int F_262 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_84 * V_84 ,
int V_261 ,
const T_6 V_36 ,
const T_6 V_222 ,
struct V_5 * V_6 )
{
struct V_40 * V_41 ;
struct V_40 * V_232 ;
struct V_43 V_235 ;
struct V_43 V_242 ;
struct V_3 * log = V_4 -> V_10 ;
struct V_28 * V_236 = NULL ;
F_65 ( V_288 ) ;
T_1 V_259 = 0 ;
int V_224 = 0 ;
int V_8 ;
int V_165 ;
int V_337 = 0 ;
int V_333 ;
bool V_338 = false ;
T_1 V_142 = F_61 ( V_84 ) ;
struct V_320 * V_339 = & F_115 ( V_84 ) -> V_322 ;
T_1 V_246 = 0 ;
bool V_340 = true ;
V_41 = F_89 () ;
if ( ! V_41 )
return - V_63 ;
V_232 = F_89 () ;
if ( ! V_232 ) {
F_93 ( V_41 ) ;
return - V_63 ;
}
V_235 . V_54 = V_142 ;
V_235 . type = V_52 ;
V_235 . V_82 = 0 ;
V_242 . V_54 = V_142 ;
if ( F_39 ( V_84 -> V_147 ) ||
( ! F_174 ( V_341 ,
& F_115 ( V_84 ) -> V_342 ) &&
V_261 == V_275 ) )
V_242 . type = V_170 ;
else
V_242 . type = ( T_4 ) - 1 ;
V_242 . V_82 = ( T_1 ) - 1 ;
if ( F_39 ( V_84 -> V_147 ) ||
F_115 ( V_84 ) -> V_247 > V_4 -> V_11 -> V_326 )
V_8 = F_263 ( V_2 , V_84 ) ;
else
V_8 = F_264 ( V_84 ) ;
if ( V_8 ) {
F_93 ( V_41 ) ;
F_93 ( V_232 ) ;
return V_8 ;
}
F_2 ( & F_115 ( V_84 ) -> V_9 ) ;
F_265 ( V_84 , & V_288 , V_36 , V_222 ) ;
if ( F_39 ( V_84 -> V_147 ) ) {
int V_243 = V_181 ;
if ( V_261 == V_275 )
V_243 = V_170 ;
V_8 = F_205 ( V_2 , log , V_41 , V_142 , V_243 ) ;
} else {
if ( V_261 == V_275 ) {
V_224 = F_258 ( log , V_84 , V_41 ,
& V_246 ) ;
if ( V_224 )
goto V_228;
}
if ( F_174 ( V_341 ,
& F_115 ( V_84 ) -> V_342 ) ) {
if ( V_261 == V_275 ) {
V_242 . type = V_170 ;
V_8 = F_205 ( V_2 , log , V_41 , V_142 ,
V_242 . type ) ;
} else {
F_4 ( V_341 ,
& F_115 ( V_84 ) -> V_342 ) ;
F_4 ( V_343 ,
& F_115 ( V_84 ) -> V_342 ) ;
while( 1 ) {
V_8 = F_266 ( V_2 ,
log , V_84 , 0 , 0 ) ;
if ( V_8 != - V_12 )
break;
}
}
} else if ( F_267 ( V_343 ,
& F_115 ( V_84 ) -> V_342 ) ||
V_261 == V_275 ) {
if ( V_261 == V_344 )
V_338 = true ;
V_242 . type = V_170 ;
V_8 = F_205 ( V_2 , log , V_41 , V_142 ,
V_242 . type ) ;
} else {
if ( V_261 == V_344 )
V_338 = true ;
goto V_345;
}
}
if ( V_8 ) {
V_224 = V_8 ;
goto V_228;
}
while ( 1 ) {
V_333 = 0 ;
V_8 = F_200 ( V_4 , & V_235 ,
V_41 , V_2 -> V_79 ) ;
if ( V_8 != 0 )
break;
V_131:
if ( V_235 . V_54 != V_142 )
break;
if ( V_235 . type > V_242 . type )
break;
if ( V_235 . type == V_52 )
V_340 = false ;
if ( V_235 . type == V_170 ) {
if ( V_333 == 0 )
goto V_346;
V_8 = F_227 ( V_2 , V_84 , V_232 , V_41 ,
& V_259 , V_337 ,
V_333 , V_261 , V_246 ) ;
if ( V_8 < 0 ) {
V_224 = V_8 ;
goto V_228;
}
V_333 = 0 ;
if ( V_8 ) {
F_31 ( V_41 ) ;
continue;
}
goto V_346;
}
V_236 = V_41 -> V_59 [ 0 ] ;
if ( V_333 && V_337 + V_333 == V_41 -> V_60 [ 0 ] ) {
V_333 ++ ;
goto V_346;
} else if ( ! V_333 ) {
V_337 = V_41 -> V_60 [ 0 ] ;
V_333 = 1 ;
goto V_346;
}
V_8 = F_227 ( V_2 , V_84 , V_232 , V_41 , & V_259 ,
V_337 , V_333 , V_261 ,
V_246 ) ;
if ( V_8 < 0 ) {
V_224 = V_8 ;
goto V_228;
}
if ( V_8 ) {
V_333 = 0 ;
F_31 ( V_41 ) ;
continue;
}
V_333 = 1 ;
V_337 = V_41 -> V_60 [ 0 ] ;
V_346:
V_165 = F_130 ( V_41 -> V_59 [ 0 ] ) ;
V_41 -> V_60 [ 0 ] ++ ;
if ( V_41 -> V_60 [ 0 ] < V_165 ) {
F_112 ( V_41 -> V_59 [ 0 ] , & V_235 ,
V_41 -> V_60 [ 0 ] ) ;
goto V_131;
}
if ( V_333 ) {
V_8 = F_227 ( V_2 , V_84 , V_232 , V_41 ,
& V_259 , V_337 ,
V_333 , V_261 , V_246 ) ;
if ( V_8 < 0 ) {
V_224 = V_8 ;
goto V_228;
}
V_8 = 0 ;
V_333 = 0 ;
}
F_31 ( V_41 ) ;
if ( V_235 . V_82 < ( T_1 ) - 1 ) {
V_235 . V_82 ++ ;
} else if ( V_235 . type < V_242 . type ) {
V_235 . type ++ ;
V_235 . V_82 = 0 ;
} else {
break;
}
}
if ( V_333 ) {
V_8 = F_227 ( V_2 , V_84 , V_232 , V_41 , & V_259 ,
V_337 , V_333 , V_261 ,
V_246 ) ;
if ( V_8 < 0 ) {
V_224 = V_8 ;
goto V_228;
}
V_8 = 0 ;
V_333 = 0 ;
}
F_31 ( V_41 ) ;
F_31 ( V_232 ) ;
V_224 = F_259 ( V_2 , V_4 , V_84 , V_41 , V_232 ) ;
if ( V_224 )
goto V_228;
if ( V_242 . type >= V_188 && ! V_338 ) {
F_31 ( V_41 ) ;
F_31 ( V_232 ) ;
V_224 = F_260 ( V_2 , V_4 , V_84 , V_41 ) ;
if ( V_224 )
goto V_228;
}
V_345:
F_31 ( V_41 ) ;
F_31 ( V_232 ) ;
if ( V_340 ) {
V_224 = F_226 ( V_2 , log , V_232 , V_84 ) ;
if ( V_224 )
goto V_228;
}
if ( V_338 ) {
V_224 = F_237 ( V_84 ) ;
if ( V_224 ) {
V_6 -> V_314 = V_224 ;
goto V_228;
}
V_8 = F_251 ( V_2 , V_4 , V_84 , V_232 ,
& V_288 , V_6 ) ;
if ( V_8 ) {
V_224 = V_8 ;
goto V_228;
}
} else if ( V_261 == V_344 ) {
struct V_284 * V_287 , * V_318 ;
F_252 ( & V_339 -> V_325 ) ;
F_253 (em, n, &em_tree->modified_extents,
list) {
const T_1 V_347 = V_287 -> V_292 + V_287 -> V_293 - 1 ;
if ( V_287 -> V_292 >= V_36 && V_347 <= V_222 )
F_167 ( & V_287 -> V_22 ) ;
}
F_257 ( & V_339 -> V_325 ) ;
}
if ( V_261 == V_344 && F_39 ( V_84 -> V_147 ) ) {
V_8 = F_204 ( V_2 , V_4 , V_84 , V_41 , V_232 ,
V_6 ) ;
if ( V_8 ) {
V_224 = V_8 ;
goto V_228;
}
}
F_268 ( & F_115 ( V_84 ) -> V_325 ) ;
F_115 ( V_84 ) -> V_227 = V_2 -> V_79 ;
F_115 ( V_84 ) -> V_221 = F_115 ( V_84 ) -> V_348 ;
F_269 ( & F_115 ( V_84 ) -> V_325 ) ;
V_228:
if ( F_270 ( V_224 ) )
F_271 ( & V_288 ) ;
else
F_272 ( & V_288 , log ) ;
F_8 ( & F_115 ( V_84 ) -> V_9 ) ;
F_93 ( V_41 ) ;
F_93 ( V_232 ) ;
return V_224 ;
}
static T_2 int F_273 ( struct V_1 * V_2 ,
struct V_84 * V_84 ,
struct V_349 * V_192 ,
struct V_350 * V_351 ,
T_1 V_352 )
{
int V_8 = 0 ;
struct V_3 * V_4 ;
struct V_349 * V_353 = NULL ;
struct V_84 * V_354 = V_84 ;
if ( F_46 ( V_84 -> V_147 ) &&
F_115 ( V_84 ) -> V_247 <= V_352 &&
F_115 ( V_84 ) -> V_355 <= V_352 )
goto V_13;
if ( ! F_39 ( V_84 -> V_147 ) ) {
if ( ! V_192 || F_274 ( V_192 ) || V_351 != F_275 ( V_192 ) -> V_356 )
goto V_13;
V_84 = F_275 ( V_192 ) ;
}
while ( 1 ) {
if ( V_84 != V_354 )
F_115 ( V_84 ) -> V_227 = V_2 -> V_79 ;
F_12 () ;
if ( F_115 ( V_84 ) -> V_355 > V_352 ) {
V_4 = F_115 ( V_84 ) -> V_4 ;
F_181 ( V_4 -> V_11 , V_2 ) ;
V_8 = 1 ;
break;
}
if ( ! V_192 || F_274 ( V_192 ) || V_351 != F_275 ( V_192 ) -> V_356 )
break;
if ( F_276 ( V_192 ) )
break;
V_192 = F_277 ( V_192 ) ;
F_278 ( V_353 ) ;
V_353 = V_192 ;
V_84 = F_275 ( V_192 ) ;
}
F_278 ( V_353 ) ;
V_13:
return V_8 ;
}
static int F_279 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_84 * V_357 ,
struct V_5 * V_6 )
{
struct V_3 * log = V_4 -> V_10 ;
struct V_40 * V_41 ;
F_65 ( V_358 ) ;
struct V_359 * V_360 ;
int V_8 = 0 ;
V_41 = F_89 () ;
if ( ! V_41 )
return - V_63 ;
V_360 = F_32 ( sizeof( * V_360 ) , V_62 ) ;
if ( ! V_360 ) {
F_93 ( V_41 ) ;
return - V_63 ;
}
V_360 -> V_142 = F_61 ( V_357 ) ;
F_7 ( & V_360 -> V_22 , & V_358 ) ;
while ( ! F_71 ( & V_358 ) ) {
struct V_28 * V_94 ;
struct V_43 V_235 ;
int V_165 ;
int V_169 ;
V_360 = F_280 ( & V_358 , struct V_359 ,
V_22 ) ;
if ( V_8 )
goto V_361;
V_235 . V_54 = V_360 -> V_142 ;
V_235 . type = V_157 ;
V_235 . V_82 = 0 ;
V_131:
F_31 ( V_41 ) ;
V_8 = F_200 ( log , & V_235 , V_41 , V_2 -> V_79 ) ;
if ( V_8 < 0 ) {
goto V_361;
} else if ( V_8 > 0 ) {
V_8 = 0 ;
goto V_361;
}
V_171:
V_94 = V_41 -> V_59 [ 0 ] ;
V_165 = F_130 ( V_94 ) ;
for ( V_169 = V_41 -> V_60 [ 0 ] ; V_169 < V_165 ; V_169 ++ ) {
struct V_106 * V_107 ;
struct V_43 V_362 ;
struct V_84 * V_363 ;
struct V_359 * V_364 ;
int V_365 = V_275 ;
int type ;
F_112 ( V_94 , & V_235 , V_169 ) ;
if ( V_235 . V_54 != V_360 -> V_142 ||
V_235 . type != V_157 )
goto V_361;
V_107 = F_35 ( V_94 , V_169 , struct V_106 ) ;
type = F_123 ( V_94 , V_107 ) ;
if ( F_203 ( V_94 , V_107 ) < V_2 -> V_79 &&
type != V_239 )
continue;
F_79 ( V_94 , V_107 , & V_362 ) ;
if ( V_362 . type == V_240 )
continue;
V_363 = F_281 ( V_4 -> V_11 -> V_351 , & V_362 ,
V_4 , NULL ) ;
if ( F_86 ( V_363 ) ) {
V_8 = F_133 ( V_363 ) ;
goto V_361;
}
if ( F_282 ( V_363 , V_2 -> V_79 ) ) {
F_77 ( V_363 ) ;
continue;
}
V_6 -> V_241 = false ;
if ( type == V_239 )
V_365 = V_344 ;
F_31 ( V_41 ) ;
V_8 = F_262 ( V_2 , V_4 , V_363 ,
V_365 , 0 , V_366 , V_6 ) ;
F_77 ( V_363 ) ;
if ( V_8 )
goto V_361;
if ( V_6 -> V_241 ) {
V_364 = F_32 ( sizeof( * V_364 ) ,
V_62 ) ;
if ( ! V_364 ) {
V_8 = - V_63 ;
goto V_361;
}
V_364 -> V_142 = V_362 . V_54 ;
F_7 ( & V_364 -> V_22 , & V_358 ) ;
}
break;
}
if ( V_169 == V_165 ) {
V_8 = F_131 ( log , V_41 ) ;
if ( V_8 < 0 ) {
goto V_361;
} else if ( V_8 > 0 ) {
V_8 = 0 ;
goto V_361;
}
goto V_171;
}
if ( V_235 . V_82 < ( T_1 ) - 1 ) {
V_235 . V_82 ++ ;
goto V_131;
}
V_361:
F_74 ( & V_360 -> V_22 ) ;
F_33 ( V_360 ) ;
}
F_93 ( V_41 ) ;
return V_8 ;
}
static int F_283 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_84 * V_84 ,
struct V_349 * V_192 ,
const T_6 V_36 ,
const T_6 V_222 ,
int V_367 ,
struct V_5 * V_6 )
{
int V_261 = V_367 ? V_275 : V_344 ;
struct V_350 * V_351 ;
struct V_349 * V_353 = NULL ;
int V_8 = 0 ;
T_1 V_352 = V_4 -> V_11 -> V_326 ;
const struct V_349 * const V_368 = V_192 ;
const bool V_369 = ( F_115 ( V_84 ) -> V_355 >
V_352 ) ;
bool V_370 = false ;
struct V_84 * V_354 = V_84 ;
V_351 = V_84 -> V_356 ;
if ( F_173 ( V_4 , V_371 ) ) {
V_8 = 1 ;
goto V_372;
}
if ( V_4 -> V_11 -> V_373 >
V_4 -> V_11 -> V_326 ) {
V_8 = 1 ;
goto V_372;
}
if ( V_4 != F_115 ( V_84 ) -> V_4 ||
F_284 ( & V_4 -> V_200 ) == 0 ) {
V_8 = 1 ;
goto V_372;
}
V_8 = F_273 ( V_2 , V_84 , V_192 ,
V_351 , V_352 ) ;
if ( V_8 )
goto V_372;
if ( F_282 ( V_84 , V_2 -> V_79 ) ) {
V_8 = V_374 ;
goto V_372;
}
V_8 = F_1 ( V_2 , V_4 , V_6 ) ;
if ( V_8 )
goto V_372;
V_8 = F_262 ( V_2 , V_4 , V_84 , V_261 , V_36 , V_222 , V_6 ) ;
if ( V_8 )
goto V_375;
if ( F_46 ( V_84 -> V_147 ) &&
F_115 ( V_84 ) -> V_247 <= V_352 &&
F_115 ( V_84 ) -> V_355 <= V_352 ) {
V_8 = 0 ;
goto V_375;
}
if ( F_39 ( V_84 -> V_147 ) && V_6 && V_6 -> V_241 )
V_370 = true ;
while ( 1 ) {
if ( ! V_192 || F_274 ( V_192 ) || V_351 != F_275 ( V_192 ) -> V_356 )
break;
V_84 = F_275 ( V_192 ) ;
if ( V_4 != F_115 ( V_84 ) -> V_4 )
break;
if ( V_369 && V_192 == V_368 )
V_261 = V_344 ;
else
V_261 = V_275 ;
if ( F_115 ( V_84 ) -> V_247 >
V_4 -> V_11 -> V_326 ||
V_261 == V_344 ) {
V_8 = F_262 ( V_2 , V_4 , V_84 , V_261 ,
0 , V_366 , V_6 ) ;
if ( V_8 )
goto V_375;
}
if ( F_276 ( V_192 ) )
break;
V_192 = F_277 ( V_192 ) ;
F_278 ( V_353 ) ;
V_353 = V_192 ;
}
if ( V_370 )
V_8 = F_279 ( V_2 , V_4 , V_354 , V_6 ) ;
else
V_8 = 0 ;
V_375:
F_278 ( V_353 ) ;
if ( V_8 < 0 ) {
F_181 ( V_4 -> V_11 , V_2 ) ;
V_8 = 1 ;
}
if ( V_8 )
F_166 ( V_4 , V_6 ) ;
F_14 ( V_4 ) ;
V_372:
return V_8 ;
}
int F_285 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_349 * V_349 ,
const T_6 V_36 ,
const T_6 V_222 ,
struct V_5 * V_6 )
{
struct V_349 * V_192 = F_277 ( V_349 ) ;
int V_8 ;
V_8 = F_283 ( V_2 , V_4 , F_275 ( V_349 ) , V_192 ,
V_36 , V_222 , 0 , V_6 ) ;
F_278 ( V_192 ) ;
return V_8 ;
}
int F_286 ( struct V_3 * V_25 )
{
int V_8 ;
struct V_40 * V_41 ;
struct V_1 * V_2 ;
struct V_43 V_44 ;
struct V_43 V_151 ;
struct V_43 V_376 ;
struct V_3 * log ;
struct V_223 * V_11 = V_25 -> V_11 ;
struct V_30 V_31 = {
. V_196 = F_18 ,
. V_184 = 0 ,
} ;
V_41 = F_89 () ;
if ( ! V_41 )
return - V_63 ;
V_11 -> V_377 = 1 ;
V_2 = F_287 ( V_11 -> V_220 , 0 ) ;
if ( F_86 ( V_2 ) ) {
V_8 = F_133 ( V_2 ) ;
goto error;
}
V_31 . V_2 = V_2 ;
V_31 . V_34 = 1 ;
V_8 = F_154 ( V_2 , V_25 , & V_31 ) ;
if ( V_8 ) {
F_288 ( V_11 , V_8 , L_1
L_2 ) ;
goto error;
}
V_131:
V_44 . V_54 = V_55 ;
V_44 . V_82 = ( T_1 ) - 1 ;
V_44 . type = V_240 ;
while ( 1 ) {
V_8 = F_30 ( NULL , V_25 , & V_44 , V_41 , 0 , 0 ) ;
if ( V_8 < 0 ) {
F_288 ( V_11 , V_8 ,
L_3 ) ;
goto error;
}
if ( V_8 > 0 ) {
if ( V_41 -> V_60 [ 0 ] == 0 )
break;
V_41 -> V_60 [ 0 ] -- ;
}
F_112 ( V_41 -> V_59 [ 0 ] , & V_151 ,
V_41 -> V_60 [ 0 ] ) ;
F_31 ( V_41 ) ;
if ( V_151 . V_54 != V_55 )
break;
log = F_289 ( V_25 , & V_151 ) ;
if ( F_86 ( log ) ) {
V_8 = F_133 ( log ) ;
F_288 ( V_11 , V_8 ,
L_4 ) ;
goto error;
}
V_376 . V_54 = V_151 . V_82 ;
V_376 . type = V_240 ;
V_376 . V_82 = ( T_1 ) - 1 ;
V_31 . V_182 = F_290 ( V_11 , & V_376 ) ;
if ( F_86 ( V_31 . V_182 ) ) {
V_8 = F_133 ( V_31 . V_182 ) ;
F_145 ( log -> V_197 ) ;
F_145 ( log -> V_378 ) ;
F_33 ( log ) ;
F_288 ( V_11 , V_8 , L_5
L_6 ) ;
goto error;
}
V_31 . V_182 -> V_10 = log ;
F_291 ( V_2 , V_31 . V_182 ) ;
V_8 = F_154 ( V_2 , log , & V_31 ) ;
if ( ! V_8 && V_31 . V_184 == V_187 ) {
V_8 = F_117 ( V_2 , V_31 . V_182 ,
V_41 ) ;
}
V_44 . V_82 = V_151 . V_82 - 1 ;
V_31 . V_182 -> V_10 = NULL ;
F_145 ( log -> V_197 ) ;
F_145 ( log -> V_378 ) ;
F_33 ( log ) ;
if ( V_8 )
goto error;
if ( V_151 . V_82 == 0 )
break;
}
F_31 ( V_41 ) ;
if ( V_31 . V_34 ) {
V_31 . V_34 = 0 ;
V_31 . V_196 = F_138 ;
V_31 . V_184 = V_185 ;
goto V_131;
}
if ( V_31 . V_184 < V_187 ) {
V_31 . V_184 ++ ;
goto V_131;
}
F_93 ( V_41 ) ;
V_8 = F_292 ( V_2 , V_11 -> V_220 ) ;
if ( V_8 )
return V_8 ;
F_145 ( V_25 -> V_197 ) ;
V_25 -> V_10 = NULL ;
V_11 -> V_377 = 0 ;
F_33 ( V_25 ) ;
return 0 ;
error:
if ( V_31 . V_2 )
F_293 ( V_31 . V_2 , V_11 -> V_220 ) ;
F_93 ( V_41 ) ;
return V_8 ;
}
void F_294 ( struct V_1 * V_2 ,
struct V_84 * V_105 , struct V_84 * V_84 ,
int V_379 )
{
if ( F_46 ( V_84 -> V_147 ) )
F_115 ( V_84 ) -> V_355 = V_2 -> V_79 ;
F_12 () ;
if ( F_115 ( V_105 ) -> V_227 == V_2 -> V_79 )
return;
if ( F_115 ( V_84 ) -> V_227 == V_2 -> V_79 )
return;
if ( V_379 )
goto V_380;
return;
V_380:
F_115 ( V_105 ) -> V_355 = V_2 -> V_79 ;
}
int F_295 ( struct V_1 * V_2 ,
struct V_84 * V_84 , struct V_84 * V_381 ,
struct V_349 * V_192 )
{
struct V_3 * V_4 = F_115 ( V_84 ) -> V_4 ;
if ( F_46 ( V_84 -> V_147 ) )
F_115 ( V_84 ) -> V_355 = V_2 -> V_79 ;
if ( F_115 ( V_84 ) -> V_227 <=
V_4 -> V_11 -> V_326 &&
( ! V_381 || F_115 ( V_381 ) -> V_227 <=
V_4 -> V_11 -> V_326 ) )
return 0 ;
return F_283 ( V_2 , V_4 , V_84 , V_192 , 0 ,
V_366 , 1 , NULL ) ;
}
