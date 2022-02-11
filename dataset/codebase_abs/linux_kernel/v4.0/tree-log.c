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
if ( F_45 ( F_38 ( V_29 , V_72 ) ) &&
F_45 ( F_38 ( V_74 , V_73 ) ) ) {
struct V_75 V_76 ;
T_1 V_77 = F_46 ( V_29 , V_72 ) ;
F_47 ( & V_76 ) ;
F_48 ( V_74 , V_73 ,
V_77 , & V_76 ) ;
}
goto V_78;
}
if ( V_50 &&
F_39 ( F_38 ( V_29 , V_72 ) ) &&
F_39 ( F_38 ( V_41 -> V_59 [ 0 ] , V_73 ) ) ) {
V_47 = 1 ;
V_46 = F_46 ( V_41 -> V_59 [ 0 ] ,
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
static T_2 int F_116 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_3 * log ,
struct V_40 * V_41 ,
T_1 V_111 , int V_169 )
{
T_1 V_170 ;
T_1 V_171 ;
int V_160 = V_172 ;
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
V_170 = 0 ;
V_171 = 0 ;
while ( 1 ) {
if ( V_169 )
V_171 = ( T_1 ) - 1 ;
else {
V_8 = F_128 ( log , V_41 , V_111 , V_160 ,
& V_170 , & V_171 ) ;
if ( V_8 != 0 )
break;
}
V_167 . V_82 = V_170 ;
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
goto V_173;
if ( V_151 . V_82 > V_171 )
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
if ( V_171 == ( T_1 ) - 1 )
break;
V_170 = V_171 + 1 ;
}
V_173:
V_8 = 0 ;
if ( V_160 == V_172 ) {
V_160 = V_174 ;
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
static int F_134 ( struct V_3 * log , struct V_28 * V_29 ,
struct V_30 * V_31 , T_1 V_32 )
{
int V_165 ;
struct V_40 * V_41 ;
struct V_3 * V_4 = V_31 -> V_175 ;
struct V_43 V_44 ;
int V_176 ;
int V_177 ;
int V_8 ;
V_8 = F_20 ( V_29 , V_32 ) ;
if ( V_8 )
return V_8 ;
V_176 = F_23 ( V_29 ) ;
if ( V_176 != 0 )
return 0 ;
V_41 = F_89 () ;
if ( ! V_41 )
return - V_63 ;
V_165 = F_130 ( V_29 ) ;
for ( V_177 = 0 ; V_177 < V_165 ; V_177 ++ ) {
F_112 ( V_29 , & V_44 , V_177 ) ;
if ( V_44 . type == V_52 &&
V_31 -> V_178 == V_179 ) {
struct V_64 * V_51 ;
T_3 V_67 ;
V_51 = F_35 ( V_29 , V_177 ,
struct V_64 ) ;
V_67 = F_38 ( V_29 , V_51 ) ;
if ( F_39 ( V_67 ) ) {
V_8 = F_116 ( V_31 -> V_2 ,
V_4 , log , V_41 , V_44 . V_54 , 0 ) ;
if ( V_8 )
break;
}
V_8 = F_27 ( V_31 -> V_2 , V_4 , V_41 ,
V_29 , V_177 , & V_44 ) ;
if ( V_8 )
break;
if ( F_45 ( V_67 ) ) {
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
V_31 -> V_178 == V_180 ) {
V_8 = F_126 ( V_31 -> V_2 , V_4 , V_41 ,
V_29 , V_177 , & V_44 ) ;
if ( V_8 )
break;
}
if ( V_31 -> V_178 < V_181 )
continue;
if ( V_44 . type == V_182 ) {
V_8 = F_27 ( V_31 -> V_2 , V_4 , V_41 ,
V_29 , V_177 , & V_44 ) ;
if ( V_8 )
break;
} else if ( V_44 . type == V_132 ||
V_44 . type == V_121 ) {
V_8 = F_105 ( V_31 -> V_2 , V_4 , log , V_41 ,
V_29 , V_177 , & V_44 ) ;
if ( V_8 && V_8 != - V_26 )
break;
V_8 = 0 ;
} else if ( V_44 . type == V_183 ) {
V_8 = F_52 ( V_31 -> V_2 , V_4 , V_41 ,
V_29 , V_177 , & V_44 ) ;
if ( V_8 )
break;
} else if ( V_44 . type == V_157 ) {
V_8 = F_126 ( V_31 -> V_2 , V_4 , V_41 ,
V_29 , V_177 , & V_44 ) ;
if ( V_8 )
break;
}
}
F_93 ( V_41 ) ;
return V_8 ;
}
static T_2 int F_135 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_40 * V_41 , int * V_176 ,
struct V_30 * V_31 )
{
T_1 V_184 ;
T_1 V_185 ;
T_1 V_186 ;
struct V_28 * V_103 ;
struct V_28 * V_187 ;
struct V_28 * V_188 ;
T_3 V_189 ;
int V_8 = 0 ;
F_136 ( * V_176 < 0 ) ;
F_136 ( * V_176 >= V_190 ) ;
while ( * V_176 > 0 ) {
F_136 ( * V_176 < 0 ) ;
F_136 ( * V_176 >= V_190 ) ;
V_187 = V_41 -> V_59 [ * V_176 ] ;
F_136 ( F_23 ( V_187 ) != * V_176 ) ;
if ( V_41 -> V_60 [ * V_176 ] >=
F_130 ( V_187 ) )
break;
V_185 = F_137 ( V_187 , V_41 -> V_60 [ * V_176 ] ) ;
V_186 = F_138 ( V_187 , V_41 -> V_60 [ * V_176 ] ) ;
V_189 = V_4 -> V_191 ;
V_188 = V_41 -> V_59 [ * V_176 ] ;
V_184 = F_139 ( V_188 ) ;
V_103 = F_140 ( V_4 , V_185 ) ;
if ( ! V_103 )
return - V_63 ;
if ( * V_176 == 1 ) {
V_8 = V_31 -> V_192 ( V_4 , V_103 , V_31 , V_186 ) ;
if ( V_8 ) {
F_141 ( V_103 ) ;
return V_8 ;
}
V_41 -> V_60 [ * V_176 ] ++ ;
if ( V_31 -> free ) {
V_8 = F_20 ( V_103 , V_186 ) ;
if ( V_8 ) {
F_141 ( V_103 ) ;
return V_8 ;
}
if ( V_2 ) {
F_142 ( V_103 ) ;
F_143 ( V_103 ) ;
F_144 ( V_2 , V_4 , V_103 ) ;
F_26 ( V_103 ) ;
F_145 ( V_103 ) ;
}
F_136 ( V_184 !=
V_55 ) ;
V_8 = F_146 ( V_4 ,
V_185 , V_189 ) ;
if ( V_8 ) {
F_141 ( V_103 ) ;
return V_8 ;
}
}
F_141 ( V_103 ) ;
continue;
}
V_8 = F_20 ( V_103 , V_186 ) ;
if ( V_8 ) {
F_141 ( V_103 ) ;
return V_8 ;
}
F_136 ( * V_176 <= 0 ) ;
if ( V_41 -> V_59 [ * V_176 - 1 ] )
F_141 ( V_41 -> V_59 [ * V_176 - 1 ] ) ;
V_41 -> V_59 [ * V_176 - 1 ] = V_103 ;
* V_176 = F_23 ( V_103 ) ;
V_41 -> V_60 [ * V_176 ] = 0 ;
F_147 () ;
}
F_136 ( * V_176 < 0 ) ;
F_136 ( * V_176 >= V_190 ) ;
V_41 -> V_60 [ * V_176 ] = F_130 ( V_41 -> V_59 [ * V_176 ] ) ;
F_147 () ;
return 0 ;
}
static T_2 int F_148 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_40 * V_41 , int * V_176 ,
struct V_30 * V_31 )
{
T_1 V_184 ;
int V_177 ;
int V_42 ;
int V_8 ;
for ( V_177 = * V_176 ; V_177 < V_190 - 1 && V_41 -> V_59 [ V_177 ] ; V_177 ++ ) {
V_42 = V_41 -> V_60 [ V_177 ] ;
if ( V_42 + 1 < F_130 ( V_41 -> V_59 [ V_177 ] ) ) {
V_41 -> V_60 [ V_177 ] ++ ;
* V_176 = V_177 ;
F_136 ( * V_176 == 0 ) ;
return 0 ;
} else {
struct V_28 * V_188 ;
if ( V_41 -> V_59 [ * V_176 ] == V_4 -> V_193 )
V_188 = V_41 -> V_59 [ * V_176 ] ;
else
V_188 = V_41 -> V_59 [ * V_176 + 1 ] ;
V_184 = F_139 ( V_188 ) ;
V_8 = V_31 -> V_192 ( V_4 , V_41 -> V_59 [ * V_176 ] , V_31 ,
F_149 ( V_41 -> V_59 [ * V_176 ] ) ) ;
if ( V_8 )
return V_8 ;
if ( V_31 -> free ) {
struct V_28 * V_103 ;
V_103 = V_41 -> V_59 [ * V_176 ] ;
if ( V_2 ) {
F_142 ( V_103 ) ;
F_143 ( V_103 ) ;
F_144 ( V_2 , V_4 , V_103 ) ;
F_26 ( V_103 ) ;
F_145 ( V_103 ) ;
}
F_136 ( V_184 != V_55 ) ;
V_8 = F_146 ( V_4 ,
V_41 -> V_59 [ * V_176 ] -> V_36 ,
V_41 -> V_59 [ * V_176 ] -> V_37 ) ;
if ( V_8 )
return V_8 ;
}
F_141 ( V_41 -> V_59 [ * V_176 ] ) ;
V_41 -> V_59 [ * V_176 ] = NULL ;
* V_176 = V_177 + 1 ;
}
}
return 1 ;
}
static int F_150 ( struct V_1 * V_2 ,
struct V_3 * log , struct V_30 * V_31 )
{
int V_8 = 0 ;
int V_194 ;
int V_176 ;
struct V_40 * V_41 ;
int V_195 ;
V_41 = F_89 () ;
if ( ! V_41 )
return - V_63 ;
V_176 = F_23 ( log -> V_193 ) ;
V_195 = V_176 ;
V_41 -> V_59 [ V_176 ] = log -> V_193 ;
F_151 ( log -> V_193 ) ;
V_41 -> V_60 [ V_176 ] = 0 ;
while ( 1 ) {
V_194 = F_135 ( V_2 , log , V_41 , & V_176 , V_31 ) ;
if ( V_194 > 0 )
break;
if ( V_194 < 0 ) {
V_8 = V_194 ;
goto V_13;
}
V_194 = F_148 ( V_2 , log , V_41 , & V_176 , V_31 ) ;
if ( V_194 > 0 )
break;
if ( V_194 < 0 ) {
V_8 = V_194 ;
goto V_13;
}
}
if ( V_41 -> V_59 [ V_195 ] ) {
V_8 = V_31 -> V_192 ( log , V_41 -> V_59 [ V_195 ] , V_31 ,
F_149 ( V_41 -> V_59 [ V_195 ] ) ) ;
if ( V_8 )
goto V_13;
if ( V_31 -> free ) {
struct V_28 * V_103 ;
V_103 = V_41 -> V_59 [ V_195 ] ;
if ( V_2 ) {
F_142 ( V_103 ) ;
F_143 ( V_103 ) ;
F_144 ( V_2 , log , V_103 ) ;
F_26 ( V_103 ) ;
F_145 ( V_103 ) ;
}
F_136 ( log -> V_53 . V_54 !=
V_55 ) ;
V_8 = F_146 ( log , V_103 -> V_36 ,
V_103 -> V_37 ) ;
if ( V_8 )
goto V_13;
}
}
V_13:
F_93 ( V_41 ) ;
return V_8 ;
}
static int F_152 ( struct V_1 * V_2 ,
struct V_3 * log )
{
int V_8 ;
if ( log -> V_21 == 1 ) {
V_8 = F_153 ( V_2 , log -> V_11 -> V_25 ,
& log -> V_53 , & log -> V_196 ) ;
} else {
V_8 = F_154 ( V_2 , log -> V_11 -> V_25 ,
& log -> V_53 , & log -> V_196 ) ;
}
return V_8 ;
}
static void F_155 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_79 )
{
F_156 ( V_39 ) ;
int V_7 = V_79 % 2 ;
do {
F_157 ( & V_4 -> V_197 [ V_7 ] ,
& V_39 , V_198 ) ;
F_8 ( & V_4 -> V_9 ) ;
if ( V_4 -> V_199 < V_79 &&
F_158 ( & V_4 -> V_200 [ V_7 ] ) )
F_159 () ;
F_160 ( & V_4 -> V_197 [ V_7 ] , & V_39 ) ;
F_2 ( & V_4 -> V_9 ) ;
} while ( V_4 -> V_199 < V_79 &&
F_158 ( & V_4 -> V_200 [ V_7 ] ) );
}
static void F_161 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_156 ( V_39 ) ;
while ( F_158 ( & V_4 -> V_20 ) ) {
F_157 ( & V_4 -> V_27 ,
& V_39 , V_198 ) ;
F_8 ( & V_4 -> V_9 ) ;
if ( F_158 ( & V_4 -> V_20 ) )
F_159 () ;
F_160 ( & V_4 -> V_27 , & V_39 ) ;
F_2 ( & V_4 -> V_9 ) ;
}
}
static inline void F_162 ( struct V_3 * V_4 ,
struct V_5 * V_6 )
{
if ( ! V_6 )
return;
F_2 ( & V_4 -> V_9 ) ;
F_163 ( & V_6 -> V_22 ) ;
F_8 ( & V_4 -> V_9 ) ;
}
static inline void F_164 ( struct V_3 * V_4 ,
int V_7 , int error )
{
struct V_5 * V_6 ;
if ( ! error ) {
F_165 ( & V_4 -> V_23 [ V_7 ] ) ;
return;
}
F_166 (ctx, &root->log_ctxs[index], list)
V_6 -> V_201 = error ;
F_165 ( & V_4 -> V_23 [ V_7 ] ) ;
}
int F_167 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_5 * V_6 )
{
int V_202 ;
int V_203 ;
int V_204 ;
int V_8 ;
struct V_3 * log = V_4 -> V_10 ;
struct V_3 * V_25 = V_4 -> V_11 -> V_25 ;
int V_21 = 0 ;
struct V_5 V_205 ;
struct V_206 V_207 ;
F_2 ( & V_4 -> V_9 ) ;
V_21 = V_6 -> V_21 ;
if ( V_4 -> V_199 >= V_21 ) {
F_8 ( & V_4 -> V_9 ) ;
return V_6 -> V_201 ;
}
V_202 = V_21 % 2 ;
if ( F_158 ( & V_4 -> V_200 [ V_202 ] ) ) {
F_155 ( V_2 , V_4 , V_21 ) ;
F_8 ( & V_4 -> V_9 ) ;
return V_6 -> V_201 ;
}
ASSERT ( V_21 == V_4 -> V_21 ) ;
F_168 ( & V_4 -> V_200 [ V_202 ] , 1 ) ;
if ( F_158 ( & V_4 -> V_200 [ ( V_202 + 1 ) % 2 ] ) )
F_155 ( V_2 , V_4 , V_21 - 1 ) ;
while ( 1 ) {
int V_208 = F_158 ( & V_4 -> V_19 ) ;
if ( ! F_169 ( V_4 , V_209 ) &&
F_170 ( V_17 , & V_4 -> V_18 ) ) {
F_8 ( & V_4 -> V_9 ) ;
F_171 ( 1 ) ;
F_2 ( & V_4 -> V_9 ) ;
}
F_161 ( V_2 , V_4 ) ;
if ( V_208 == F_158 ( & V_4 -> V_19 ) )
break;
}
if ( F_3 ( V_4 -> V_11 , V_2 ) ) {
V_8 = - V_12 ;
F_172 ( log , V_21 ) ;
F_8 ( & V_4 -> V_9 ) ;
goto V_13;
}
if ( V_21 % 2 == 0 )
V_204 = V_210 ;
else
V_204 = V_211 ;
F_173 ( & V_207 ) ;
V_8 = F_174 ( log , & log -> V_212 , V_204 ) ;
if ( V_8 ) {
F_175 ( & V_207 ) ;
F_176 ( V_2 , V_4 , V_8 ) ;
F_172 ( log , V_21 ) ;
F_177 ( V_4 -> V_11 , V_2 ) ;
F_8 ( & V_4 -> V_9 ) ;
goto V_13;
}
F_178 ( & log -> V_196 , log -> V_193 ) ;
V_4 -> V_21 ++ ;
log -> V_21 = V_4 -> V_21 ;
V_4 -> V_14 = 0 ;
F_8 ( & V_4 -> V_9 ) ;
F_179 ( & V_205 ) ;
F_2 ( & V_25 -> V_9 ) ;
F_6 ( & V_25 -> V_19 ) ;
F_6 ( & V_25 -> V_20 ) ;
V_203 = V_25 -> V_21 % 2 ;
F_7 ( & V_205 . V_22 , & V_25 -> V_23 [ V_203 ] ) ;
V_205 . V_21 = V_25 -> V_21 ;
F_8 ( & V_25 -> V_9 ) ;
V_8 = F_152 ( V_2 , log ) ;
F_2 ( & V_25 -> V_9 ) ;
if ( F_15 ( & V_25 -> V_20 ) ) {
F_12 () ;
if ( F_16 ( & V_25 -> V_27 ) )
F_17 ( & V_25 -> V_27 ) ;
}
if ( V_8 ) {
if ( ! F_71 ( & V_205 . V_22 ) )
F_163 ( & V_205 . V_22 ) ;
F_175 ( & V_207 ) ;
F_177 ( V_4 -> V_11 , V_2 ) ;
if ( V_8 != - V_213 ) {
F_176 ( V_2 , V_4 , V_8 ) ;
F_8 ( & V_25 -> V_9 ) ;
goto V_13;
}
F_180 ( log , & log -> V_212 , V_204 ) ;
F_172 ( log , V_21 ) ;
F_8 ( & V_25 -> V_9 ) ;
V_8 = - V_12 ;
goto V_13;
}
if ( V_25 -> V_199 >= V_205 . V_21 ) {
F_175 ( & V_207 ) ;
F_8 ( & V_25 -> V_9 ) ;
V_8 = V_205 . V_201 ;
goto V_13;
}
V_203 = V_205 . V_21 % 2 ;
if ( F_158 ( & V_25 -> V_200 [ V_203 ] ) ) {
F_175 ( & V_207 ) ;
V_8 = F_180 ( log , & log -> V_212 ,
V_204 ) ;
F_181 ( V_2 , log , V_21 ) ;
F_155 ( V_2 , V_25 ,
V_205 . V_21 ) ;
F_8 ( & V_25 -> V_9 ) ;
if ( ! V_8 )
V_8 = V_205 . V_201 ;
goto V_13;
}
ASSERT ( V_205 . V_21 == V_25 -> V_21 ) ;
F_168 ( & V_25 -> V_200 [ V_203 ] , 1 ) ;
if ( F_158 ( & V_25 -> V_200 [ ( V_203 + 1 ) % 2 ] ) ) {
F_155 ( V_2 , V_25 ,
V_205 . V_21 - 1 ) ;
}
F_161 ( V_2 , V_25 ) ;
if ( F_3 ( V_4 -> V_11 , V_2 ) ) {
F_175 ( & V_207 ) ;
F_180 ( log , & log -> V_212 , V_204 ) ;
F_172 ( log , V_21 ) ;
F_8 ( & V_25 -> V_9 ) ;
V_8 = - V_12 ;
goto V_214;
}
V_8 = F_174 ( V_25 ,
& V_25 -> V_212 ,
V_210 | V_211 ) ;
F_175 ( & V_207 ) ;
if ( V_8 ) {
F_177 ( V_4 -> V_11 , V_2 ) ;
F_176 ( V_2 , V_4 , V_8 ) ;
F_172 ( log , V_21 ) ;
F_8 ( & V_25 -> V_9 ) ;
goto V_214;
}
V_8 = F_180 ( log , & log -> V_212 , V_204 ) ;
if ( ! V_8 )
V_8 = F_180 ( V_25 ,
& V_25 -> V_212 ,
V_211 | V_210 ) ;
if ( V_8 ) {
F_177 ( V_4 -> V_11 , V_2 ) ;
F_172 ( log , V_21 ) ;
F_8 ( & V_25 -> V_9 ) ;
goto V_214;
}
F_181 ( V_2 , log , V_21 ) ;
F_182 ( V_4 -> V_11 -> V_215 ,
V_25 -> V_193 -> V_36 ) ;
F_183 ( V_4 -> V_11 -> V_215 ,
F_23 ( V_25 -> V_193 ) ) ;
V_25 -> V_21 ++ ;
F_8 ( & V_25 -> V_9 ) ;
V_8 = F_184 ( V_2 , V_4 -> V_11 -> V_216 , 1 ) ;
if ( V_8 ) {
F_177 ( V_4 -> V_11 , V_2 ) ;
F_176 ( V_2 , V_4 , V_8 ) ;
goto V_214;
}
F_2 ( & V_4 -> V_9 ) ;
if ( V_4 -> V_217 < V_21 )
V_4 -> V_217 = V_21 ;
F_8 ( & V_4 -> V_9 ) ;
V_214:
F_164 ( V_25 , V_203 , V_8 ) ;
F_2 ( & V_25 -> V_9 ) ;
V_25 -> V_199 ++ ;
F_168 ( & V_25 -> V_200 [ V_203 ] , 0 ) ;
F_8 ( & V_25 -> V_9 ) ;
if ( F_16 ( & V_25 -> V_197 [ V_203 ] ) )
F_17 ( & V_25 -> V_197 [ V_203 ] ) ;
V_13:
F_164 ( V_4 , V_202 , V_8 ) ;
F_2 ( & V_4 -> V_9 ) ;
V_4 -> V_199 ++ ;
F_168 ( & V_4 -> V_200 [ V_202 ] , 0 ) ;
F_8 ( & V_4 -> V_9 ) ;
if ( F_16 ( & V_4 -> V_197 [ V_202 ] ) )
F_17 ( & V_4 -> V_197 [ V_202 ] ) ;
return V_8 ;
}
static void F_185 ( struct V_1 * V_2 ,
struct V_3 * log )
{
int V_8 ;
T_1 V_36 ;
T_1 V_218 ;
struct V_30 V_31 = {
. free = 1 ,
. V_192 = F_18
} ;
V_8 = F_150 ( V_2 , log , & V_31 ) ;
if ( V_8 )
F_176 ( V_2 , log , V_8 ) ;
while ( 1 ) {
V_8 = F_186 ( & log -> V_212 ,
0 , & V_36 , & V_218 , V_210 | V_211 ,
NULL ) ;
if ( V_8 )
break;
F_187 ( & log -> V_212 , V_36 , V_218 ,
V_210 | V_211 , V_62 ) ;
}
F_172 ( log , 0 ) ;
F_172 ( log , 1 ) ;
F_141 ( log -> V_193 ) ;
F_33 ( log ) ;
}
int F_188 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( V_4 -> V_10 ) {
F_185 ( V_2 , V_4 -> V_10 ) ;
V_4 -> V_10 = NULL ;
}
return 0 ;
}
int F_189 ( struct V_1 * V_2 ,
struct V_219 * V_11 )
{
if ( V_11 -> V_25 ) {
F_185 ( V_2 , V_11 -> V_25 ) ;
V_11 -> V_25 = NULL ;
}
return 0 ;
}
int F_190 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_108 , int V_109 ,
struct V_84 * V_105 , T_1 V_7 )
{
struct V_3 * log ;
struct V_106 * V_107 ;
struct V_40 * V_41 ;
int V_8 ;
int V_220 = 0 ;
int V_221 = 0 ;
T_1 V_222 = F_61 ( V_105 ) ;
if ( F_115 ( V_105 ) -> V_223 < V_2 -> V_79 )
return 0 ;
V_8 = F_11 ( V_4 ) ;
if ( V_8 )
return 0 ;
F_2 ( & F_115 ( V_105 ) -> V_9 ) ;
log = V_4 -> V_10 ;
V_41 = F_89 () ;
if ( ! V_41 ) {
V_220 = - V_63 ;
goto V_224;
}
V_107 = F_87 ( V_2 , log , V_41 , V_222 ,
V_108 , V_109 , - 1 ) ;
if ( F_86 ( V_107 ) ) {
V_220 = F_133 ( V_107 ) ;
goto V_225;
}
if ( V_107 ) {
V_8 = F_191 ( V_2 , log , V_41 , V_107 ) ;
V_221 += V_109 ;
if ( V_8 ) {
V_220 = V_8 ;
goto V_225;
}
}
F_31 ( V_41 ) ;
V_107 = F_85 ( V_2 , log , V_41 , V_222 ,
V_7 , V_108 , V_109 , - 1 ) ;
if ( F_86 ( V_107 ) ) {
V_220 = F_133 ( V_107 ) ;
goto V_225;
}
if ( V_107 ) {
V_8 = F_191 ( V_2 , log , V_41 , V_107 ) ;
V_221 += V_109 ;
if ( V_8 ) {
V_220 = V_8 ;
goto V_225;
}
}
if ( V_221 ) {
struct V_43 V_44 ;
V_44 . V_54 = V_222 ;
V_44 . V_82 = 0 ;
V_44 . type = V_52 ;
F_31 ( V_41 ) ;
V_8 = F_30 ( V_2 , log , & V_44 , V_41 , 0 , 1 ) ;
if ( V_8 < 0 ) {
V_220 = V_8 ;
goto V_225;
}
if ( V_8 == 0 ) {
struct V_64 * V_65 ;
T_1 V_159 ;
V_65 = F_35 ( V_41 -> V_59 [ 0 ] , V_41 -> V_60 [ 0 ] ,
struct V_64 ) ;
V_159 = F_46 ( V_41 -> V_59 [ 0 ] , V_65 ) ;
if ( V_159 > V_221 )
V_159 -= V_221 ;
else
V_159 = 0 ;
F_40 ( V_41 -> V_59 [ 0 ] , V_65 , V_159 ) ;
F_51 ( V_41 -> V_59 [ 0 ] ) ;
} else
V_8 = 0 ;
F_31 ( V_41 ) ;
}
V_225:
F_93 ( V_41 ) ;
V_224:
F_8 ( & F_115 ( V_105 ) -> V_9 ) ;
if ( V_8 == - V_213 ) {
F_177 ( V_4 -> V_11 , V_2 ) ;
V_8 = 0 ;
} else if ( V_8 < 0 )
F_176 ( V_2 , V_4 , V_8 ) ;
F_14 ( V_4 ) ;
return V_220 ;
}
int F_192 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_108 , int V_109 ,
struct V_84 * V_84 , T_1 V_111 )
{
struct V_3 * log ;
T_1 V_7 ;
int V_8 ;
if ( F_115 ( V_84 ) -> V_223 < V_2 -> V_79 )
return 0 ;
V_8 = F_11 ( V_4 ) ;
if ( V_8 )
return 0 ;
log = V_4 -> V_10 ;
F_2 ( & F_115 ( V_84 ) -> V_9 ) ;
V_8 = F_193 ( V_2 , log , V_108 , V_109 , F_61 ( V_84 ) ,
V_111 , & V_7 ) ;
F_8 ( & F_115 ( V_84 ) -> V_9 ) ;
if ( V_8 == - V_213 ) {
F_177 ( V_4 -> V_11 , V_2 ) ;
V_8 = 0 ;
} else if ( V_8 < 0 && V_8 != - V_26 )
F_176 ( V_2 , V_4 , V_8 ) ;
F_14 ( V_4 ) ;
return V_8 ;
}
static T_2 int F_194 ( struct V_1 * V_2 ,
struct V_3 * log ,
struct V_40 * V_41 ,
int V_160 , T_1 V_111 ,
T_1 V_226 , T_1 V_227 )
{
int V_8 ;
struct V_43 V_44 ;
struct V_164 * V_65 ;
V_44 . V_54 = V_111 ;
V_44 . V_82 = V_226 ;
if ( V_160 == V_157 )
V_44 . type = V_172 ;
else
V_44 . type = V_174 ;
V_8 = F_41 ( V_2 , log , V_41 , & V_44 , sizeof( * V_65 ) ) ;
if ( V_8 )
return V_8 ;
V_65 = F_35 ( V_41 -> V_59 [ 0 ] , V_41 -> V_60 [ 0 ] ,
struct V_164 ) ;
F_195 ( V_41 -> V_59 [ 0 ] , V_65 , V_227 ) ;
F_51 ( V_41 -> V_59 [ 0 ] ) ;
F_31 ( V_41 ) ;
return 0 ;
}
static T_2 int F_196 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_84 * V_84 ,
struct V_40 * V_41 ,
struct V_40 * V_228 , int V_160 ,
T_1 V_229 , T_1 * V_230 )
{
struct V_43 V_231 ;
struct V_3 * log = V_4 -> V_10 ;
struct V_28 * V_232 ;
int V_220 = 0 ;
int V_8 ;
int V_177 ;
int V_165 ;
T_1 V_226 = V_229 ;
T_1 V_227 = ( T_1 ) - 1 ;
T_1 V_142 = F_61 ( V_84 ) ;
log = V_4 -> V_10 ;
V_231 . V_54 = V_142 ;
V_231 . type = V_160 ;
V_231 . V_82 = V_229 ;
V_8 = F_197 ( V_4 , & V_231 , V_41 , V_2 -> V_79 ) ;
if ( V_8 != 0 || V_231 . V_54 != V_142 || V_231 . type != V_160 ) {
V_231 . V_54 = V_142 ;
V_231 . type = V_160 ;
V_231 . V_82 = ( T_1 ) - 1 ;
F_31 ( V_41 ) ;
V_8 = F_30 ( NULL , V_4 , & V_231 , V_41 , 0 , 0 ) ;
if ( V_8 < 0 ) {
F_31 ( V_41 ) ;
return V_8 ;
}
V_8 = F_198 ( V_4 , V_41 , V_142 , V_160 ) ;
if ( V_8 == 0 ) {
struct V_43 V_233 ;
F_112 ( V_41 -> V_59 [ 0 ] , & V_233 ,
V_41 -> V_60 [ 0 ] ) ;
if ( V_160 == V_233 . type )
V_226 = F_199 ( V_229 , V_233 . V_82 ) + 1 ;
}
goto V_234;
}
V_8 = F_198 ( V_4 , V_41 , V_142 , V_160 ) ;
if ( V_8 == 0 ) {
struct V_43 V_233 ;
F_112 ( V_41 -> V_59 [ 0 ] , & V_233 , V_41 -> V_60 [ 0 ] ) ;
if ( V_160 == V_233 . type ) {
V_226 = V_233 . V_82 ;
V_8 = F_27 ( V_2 , log , V_228 ,
V_41 -> V_59 [ 0 ] , V_41 -> V_60 [ 0 ] ,
& V_233 ) ;
if ( V_8 ) {
V_220 = V_8 ;
goto V_234;
}
}
}
F_31 ( V_41 ) ;
V_8 = F_30 ( NULL , V_4 , & V_231 , V_41 , 0 , 0 ) ;
if ( F_136 ( V_8 != 0 ) )
goto V_234;
while ( 1 ) {
struct V_43 V_233 ;
V_232 = V_41 -> V_59 [ 0 ] ;
V_165 = F_130 ( V_232 ) ;
for ( V_177 = V_41 -> V_60 [ 0 ] ; V_177 < V_165 ; V_177 ++ ) {
F_112 ( V_232 , & V_231 , V_177 ) ;
if ( V_231 . V_54 != V_142 || V_231 . type != V_160 )
goto V_234;
V_8 = F_27 ( V_2 , log , V_228 , V_232 , V_177 ,
& V_231 ) ;
if ( V_8 ) {
V_220 = V_8 ;
goto V_234;
}
}
V_41 -> V_60 [ 0 ] = V_165 ;
V_8 = F_131 ( V_4 , V_41 ) ;
if ( V_8 == 1 ) {
V_227 = ( T_1 ) - 1 ;
goto V_234;
}
F_112 ( V_41 -> V_59 [ 0 ] , & V_233 , V_41 -> V_60 [ 0 ] ) ;
if ( V_233 . V_54 != V_142 || V_233 . type != V_160 ) {
V_227 = ( T_1 ) - 1 ;
goto V_234;
}
if ( F_149 ( V_41 -> V_59 [ 0 ] ) != V_2 -> V_79 ) {
V_8 = F_27 ( V_2 , log , V_228 ,
V_41 -> V_59 [ 0 ] , V_41 -> V_60 [ 0 ] ,
& V_233 ) ;
if ( V_8 )
V_220 = V_8 ;
else
V_227 = V_233 . V_82 ;
goto V_234;
}
}
V_234:
F_31 ( V_41 ) ;
F_31 ( V_228 ) ;
if ( V_220 == 0 ) {
* V_230 = V_227 ;
V_8 = F_194 ( V_2 , log , V_41 , V_160 ,
V_142 , V_226 , V_227 ) ;
if ( V_8 )
V_220 = V_8 ;
}
return V_220 ;
}
static T_2 int F_200 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_84 * V_84 ,
struct V_40 * V_41 ,
struct V_40 * V_228 )
{
T_1 V_231 ;
T_1 V_235 ;
int V_8 ;
int V_160 = V_157 ;
V_131:
V_231 = 0 ;
V_235 = 0 ;
while ( 1 ) {
V_8 = F_196 ( V_2 , V_4 , V_84 , V_41 ,
V_228 , V_160 , V_231 ,
& V_235 ) ;
if ( V_8 )
return V_8 ;
if ( V_235 == ( T_1 ) - 1 )
break;
V_231 = V_235 + 1 ;
}
if ( V_160 == V_157 ) {
V_160 = V_156 ;
goto V_131;
}
return 0 ;
}
static int F_201 ( struct V_1 * V_2 ,
struct V_3 * log ,
struct V_40 * V_41 ,
T_1 V_54 , int V_236 )
{
int V_8 ;
struct V_43 V_44 ;
struct V_43 V_151 ;
int V_237 ;
V_44 . V_54 = V_54 ;
V_44 . type = V_236 ;
V_44 . V_82 = ( T_1 ) - 1 ;
while ( 1 ) {
V_8 = F_30 ( V_2 , log , & V_44 , V_41 , - 1 , 1 ) ;
F_202 ( V_8 == 0 ) ;
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
V_8 = F_203 ( V_41 -> V_59 [ 0 ] , & V_151 , 0 ,
& V_237 ) ;
V_8 = F_204 ( V_2 , log , V_41 , V_237 ,
V_41 -> V_60 [ 0 ] - V_237 + 1 ) ;
if ( V_8 || V_237 != 0 )
break;
F_31 ( V_41 ) ;
}
F_31 ( V_41 ) ;
if ( V_8 > 0 )
V_8 = 0 ;
return V_8 ;
}
static void F_205 ( struct V_1 * V_2 ,
struct V_28 * V_94 ,
struct V_64 * V_65 ,
struct V_84 * V_84 , int V_238 ,
T_1 V_239 )
{
struct V_75 V_76 ;
F_47 ( & V_76 ) ;
if ( V_238 ) {
F_206 ( V_94 , V_65 , 0 , & V_76 ) ;
F_48 ( V_94 , V_65 , V_239 , & V_76 ) ;
} else {
F_206 ( V_94 , V_65 ,
F_115 ( V_84 ) -> V_240 ,
& V_76 ) ;
F_48 ( V_94 , V_65 , V_84 -> V_159 , & V_76 ) ;
}
F_207 ( V_94 , V_65 , F_208 ( V_84 ) , & V_76 ) ;
F_209 ( V_94 , V_65 , F_210 ( V_84 ) , & V_76 ) ;
F_211 ( V_94 , V_65 , V_84 -> V_147 , & V_76 ) ;
F_212 ( V_94 , V_65 , V_84 -> V_145 , & V_76 ) ;
F_213 ( V_94 , & V_65 -> V_241 ,
V_84 -> V_242 . V_243 , & V_76 ) ;
F_214 ( V_94 , & V_65 -> V_241 ,
V_84 -> V_242 . V_244 , & V_76 ) ;
F_213 ( V_94 , & V_65 -> V_245 ,
V_84 -> V_246 . V_243 , & V_76 ) ;
F_214 ( V_94 , & V_65 -> V_245 ,
V_84 -> V_246 . V_244 , & V_76 ) ;
F_213 ( V_94 , & V_65 -> ctime ,
V_84 -> V_247 . V_243 , & V_76 ) ;
F_214 ( V_94 , & V_65 -> ctime ,
V_84 -> V_247 . V_244 , & V_76 ) ;
F_215 ( V_94 , V_65 , F_216 ( V_84 ) ,
& V_76 ) ;
F_217 ( V_94 , V_65 , V_84 -> V_248 , & V_76 ) ;
F_218 ( V_94 , V_65 , V_2 -> V_79 , & V_76 ) ;
F_219 ( V_94 , V_65 , V_84 -> V_249 , & V_76 ) ;
F_220 ( V_94 , V_65 , F_115 ( V_84 ) -> V_250 , & V_76 ) ;
F_221 ( V_94 , V_65 , 0 , & V_76 ) ;
}
static int F_222 ( struct V_1 * V_2 ,
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
F_205 ( V_2 , V_41 -> V_59 [ 0 ] , V_51 , V_84 , 0 , 0 ) ;
F_31 ( V_41 ) ;
return 0 ;
}
static T_2 int F_223 ( struct V_1 * V_2 ,
struct V_84 * V_84 ,
struct V_40 * V_228 ,
struct V_40 * V_251 , T_1 * V_252 ,
int V_237 , int V_253 , int V_254 ,
T_1 V_239 )
{
unsigned long V_255 ;
unsigned long V_256 ;
struct V_3 * log = F_115 ( V_84 ) -> V_4 -> V_10 ;
struct V_83 * V_257 ;
struct V_64 * V_51 ;
struct V_28 * V_232 = V_251 -> V_59 [ 0 ] ;
struct V_43 V_258 , V_259 , V_44 ;
int V_8 ;
struct V_43 * V_260 ;
T_3 * V_261 ;
char * V_262 ;
int V_177 ;
struct V_263 V_100 ;
int V_264 = F_115 ( V_84 ) -> V_250 & V_265 ;
bool V_266 = false ;
bool V_267 = true ;
bool V_234 = false ;
F_165 ( & V_100 ) ;
V_262 = F_32 ( V_253 * sizeof( struct V_43 ) +
V_253 * sizeof( T_3 ) , V_62 ) ;
if ( ! V_262 )
return - V_63 ;
V_258 . V_54 = ( T_1 ) - 1 ;
V_261 = ( T_3 * ) V_262 ;
V_260 = (struct V_43 * ) ( V_262 + V_253 * sizeof( T_3 ) ) ;
for ( V_177 = 0 ; V_177 < V_253 ; V_177 ++ ) {
V_261 [ V_177 ] = F_28 ( V_232 , V_177 + V_237 ) ;
F_112 ( V_232 , V_260 + V_177 , V_177 + V_237 ) ;
}
V_8 = F_224 ( V_2 , log , V_228 ,
V_260 , V_261 , V_253 ) ;
if ( V_8 ) {
F_33 ( V_262 ) ;
return V_8 ;
}
for ( V_177 = 0 ; V_177 < V_253 ; V_177 ++ , V_228 -> V_60 [ 0 ] ++ ) {
V_256 = F_29 ( V_228 -> V_59 [ 0 ] ,
V_228 -> V_60 [ 0 ] ) ;
V_255 = F_29 ( V_232 , V_237 + V_177 ) ;
if ( ( V_177 == ( V_253 - 1 ) ) )
V_259 = V_260 [ V_177 ] ;
if ( V_260 [ V_177 ] . type == V_52 ) {
V_51 = F_35 ( V_228 -> V_59 [ 0 ] ,
V_228 -> V_60 [ 0 ] ,
struct V_64 ) ;
F_205 ( V_2 , V_228 -> V_59 [ 0 ] , V_51 ,
V_84 , V_254 == V_268 ,
V_239 ) ;
} else {
F_49 ( V_228 -> V_59 [ 0 ] , V_232 , V_256 ,
V_255 , V_261 [ V_177 ] ) ;
}
if ( V_260 [ V_177 ] . type == V_183 ) {
V_266 = true ;
if ( V_258 . V_54 == ( T_1 ) - 1 )
V_258 = V_260 [ V_177 ] ;
} else {
V_267 = false ;
}
if ( V_260 [ V_177 ] . type == V_183 &&
! V_264 ) {
int V_80 ;
V_257 = F_35 ( V_232 , V_237 + V_177 ,
struct V_83 ) ;
if ( F_225 ( V_232 , V_257 ) < V_2 -> V_79 )
continue;
V_80 = F_53 ( V_232 , V_257 ) ;
if ( V_80 == V_86 ) {
T_1 V_269 , V_270 , V_271 , V_272 ;
V_269 = F_55 ( V_232 ,
V_257 ) ;
if ( V_269 == 0 )
continue;
V_270 = F_63 ( V_232 ,
V_257 ) ;
V_271 = F_64 ( V_232 , V_257 ) ;
V_272 = F_54 ( V_232 ,
V_257 ) ;
if ( F_69 ( V_232 ,
V_257 ) ) {
V_271 = 0 ;
V_272 = V_270 ;
}
V_8 = F_70 (
log -> V_11 -> V_104 ,
V_269 + V_271 , V_269 + V_271 + V_272 - 1 ,
& V_100 , 0 ) ;
if ( V_8 ) {
F_31 ( V_228 ) ;
F_33 ( V_262 ) ;
return V_8 ;
}
}
}
}
F_51 ( V_228 -> V_59 [ 0 ] ) ;
F_31 ( V_228 ) ;
F_33 ( V_262 ) ;
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
if ( ! V_266 )
return V_8 ;
if ( V_267 && * V_252 == V_258 . V_82 ) {
V_267 = false ;
}
if ( V_267 ) {
T_1 V_37 ;
V_8 = F_226 ( F_115 ( V_84 ) -> V_4 , V_251 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( V_8 )
goto V_273;
if ( V_251 -> V_60 [ 0 ] )
V_251 -> V_60 [ 0 ] -- ;
V_232 = V_251 -> V_59 [ 0 ] ;
F_112 ( V_232 , & V_44 , V_251 -> V_60 [ 0 ] ) ;
if ( V_44 . V_54 != F_61 ( V_84 ) ||
V_44 . type != V_183 )
goto V_273;
V_257 = F_35 ( V_232 , V_251 -> V_60 [ 0 ] ,
struct V_83 ) ;
if ( F_53 ( V_232 , V_257 ) ==
V_88 ) {
V_37 = F_56 ( V_232 ,
V_251 -> V_60 [ 0 ] ,
V_257 ) ;
* V_252 = F_58 ( V_44 . V_82 + V_37 ,
log -> V_89 ) ;
} else {
V_37 = F_54 ( V_232 , V_257 ) ;
* V_252 = V_44 . V_82 + V_37 ;
}
}
V_273:
if ( V_267 ) {
F_31 ( V_251 ) ;
V_8 = F_30 ( NULL , F_115 ( V_84 ) -> V_4 , & V_258 ,
V_251 , 0 , 0 ) ;
if ( V_8 < 0 )
return V_8 ;
ASSERT ( V_8 == 0 ) ;
V_232 = V_251 -> V_59 [ 0 ] ;
V_177 = V_251 -> V_60 [ 0 ] ;
} else {
V_177 = V_237 ;
}
while ( ! V_234 ) {
T_1 V_82 , V_37 ;
T_1 V_81 ;
if ( V_177 >= F_130 ( V_251 -> V_59 [ 0 ] ) ) {
V_8 = F_131 ( F_115 ( V_84 ) -> V_4 , V_251 ) ;
if ( V_8 < 0 )
return V_8 ;
ASSERT ( V_8 == 0 ) ;
V_232 = V_251 -> V_59 [ 0 ] ;
V_177 = 0 ;
}
F_112 ( V_232 , & V_44 , V_177 ) ;
if ( ! F_227 ( & V_44 , & V_259 ) )
V_234 = true ;
if ( V_44 . V_54 != F_61 ( V_84 ) ||
V_44 . type != V_183 ) {
V_177 ++ ;
continue;
}
V_257 = F_35 ( V_232 , V_177 , struct V_83 ) ;
if ( F_53 ( V_232 , V_257 ) ==
V_88 ) {
V_37 = F_56 ( V_232 , V_177 , V_257 ) ;
V_81 = F_58 ( V_44 . V_82 + V_37 , log -> V_89 ) ;
} else {
V_37 = F_54 ( V_232 , V_257 ) ;
V_81 = V_44 . V_82 + V_37 ;
}
V_177 ++ ;
if ( * V_252 == V_44 . V_82 ) {
* V_252 = V_81 ;
continue;
}
V_82 = * V_252 ;
V_37 = V_44 . V_82 - * V_252 ;
V_8 = F_228 ( V_2 , log , F_61 ( V_84 ) ,
V_82 , 0 , 0 , V_37 , 0 , V_37 , 0 ,
0 , 0 ) ;
if ( V_8 )
break;
* V_252 = V_81 ;
}
if ( ! V_8 && V_267 )
V_8 = 1 ;
return V_8 ;
}
static int F_229 ( void * V_274 , struct V_263 * V_275 , struct V_263 * V_276 )
{
struct V_277 * V_278 , * V_279 ;
V_278 = F_72 ( V_275 , struct V_277 , V_22 ) ;
V_279 = F_72 ( V_276 , struct V_277 , V_22 ) ;
if ( V_278 -> V_36 < V_279 -> V_36 )
return - 1 ;
else if ( V_278 -> V_36 > V_279 -> V_36 )
return 1 ;
return 0 ;
}
static int F_230 ( struct V_1 * V_2 ,
struct V_84 * V_84 ,
struct V_3 * V_4 ,
const struct V_277 * V_280 ,
const struct V_263 * V_281 ,
bool * V_282 )
{
struct V_283 * V_284 ;
struct V_3 * log = V_4 -> V_10 ;
T_1 V_285 = V_280 -> V_285 ;
T_1 V_286 = V_280 -> V_286 ;
const bool V_264 = F_115 ( V_84 ) -> V_250 & V_265 ;
T_1 V_287 ;
T_1 V_288 ;
F_65 ( V_100 ) ;
int V_8 = 0 ;
* V_282 = false ;
if ( F_170 ( V_289 , & V_280 -> V_250 ) ||
V_280 -> V_290 == V_291 )
return 0 ;
F_166 (ordered, logged_list, log_list) {
struct V_101 * V_292 ;
if ( ! V_286 )
break;
if ( V_284 -> V_293 + V_284 -> V_37 <= V_285 ||
V_285 + V_286 <= V_284 -> V_293 )
continue;
if ( ! F_170 ( V_294 , & V_284 -> V_250 ) &&
! F_170 ( V_295 , & V_284 -> V_250 ) &&
! F_170 ( V_296 , & V_284 -> V_250 ) ) {
const T_1 V_36 = V_284 -> V_293 ;
const T_1 V_218 = V_284 -> V_293 + V_284 -> V_37 - 1 ;
F_136 ( V_284 -> V_84 != V_84 ) ;
F_231 ( V_84 -> V_297 , V_36 , V_218 ) ;
}
F_232 ( V_284 -> V_39 ,
( F_170 ( V_294 , & V_284 -> V_250 ) ||
F_170 ( V_295 , & V_284 -> V_250 ) ) ) ;
if ( F_170 ( V_295 , & V_284 -> V_250 ) ) {
F_233 ( V_84 ) ;
* V_282 = true ;
break;
}
if ( V_284 -> V_293 > V_285 ) {
if ( V_284 -> V_293 + V_284 -> V_37 >=
V_285 + V_286 )
V_286 = V_284 -> V_293 - V_285 ;
} else {
if ( V_284 -> V_293 + V_284 -> V_37 <
V_285 + V_286 ) {
V_286 = ( V_285 + V_286 ) -
( V_284 -> V_293 + V_284 -> V_37 ) ;
V_285 = V_284 -> V_293 +
V_284 -> V_37 ;
} else {
V_286 = 0 ;
}
}
if ( V_264 )
continue;
if ( F_234 ( V_298 ,
& V_284 -> V_250 ) )
continue;
if ( V_284 -> V_299 ) {
F_235 ( V_84 , V_284 , 0 ) ;
F_232 ( V_284 -> V_39 ,
V_284 -> V_299 == 0 ) ;
}
F_166 (sum, &ordered->list, list) {
V_8 = F_73 ( V_2 , log , V_292 ) ;
if ( V_8 )
break;
}
}
if ( * V_282 || ! V_286 || V_8 || V_264 )
return V_8 ;
if ( V_280 -> V_300 ) {
V_287 = 0 ;
V_288 = F_199 ( V_280 -> V_301 , V_280 -> V_302 ) ;
} else {
V_287 = V_285 - V_280 -> V_36 ;
V_288 = V_286 ;
}
V_8 = F_70 ( log -> V_11 -> V_104 ,
V_280 -> V_290 + V_287 ,
V_280 -> V_290 + V_287 +
V_288 - 1 , & V_100 , 0 ) ;
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
static int F_236 ( struct V_1 * V_2 ,
struct V_84 * V_84 , struct V_3 * V_4 ,
const struct V_277 * V_280 ,
struct V_40 * V_41 ,
const struct V_263 * V_281 ,
struct V_5 * V_6 )
{
struct V_3 * log = V_4 -> V_10 ;
struct V_83 * V_303 ;
struct V_28 * V_94 ;
struct V_75 V_76 ;
struct V_43 V_44 ;
T_1 V_304 = V_280 -> V_36 - V_280 -> V_305 ;
T_1 V_301 ;
int V_8 ;
int V_306 = 0 ;
bool V_307 = false ;
V_8 = F_230 ( V_2 , V_84 , V_4 , V_280 , V_281 ,
& V_307 ) ;
if ( V_8 )
return V_8 ;
if ( V_307 ) {
V_6 -> V_308 = - V_90 ;
return 0 ;
}
F_47 ( & V_76 ) ;
V_8 = F_237 ( V_2 , log , V_84 , V_41 , V_280 -> V_36 ,
V_280 -> V_36 + V_280 -> V_37 , NULL , 0 , 1 ,
sizeof( * V_303 ) , & V_306 ) ;
if ( V_8 )
return V_8 ;
if ( ! V_306 ) {
V_44 . V_54 = F_61 ( V_84 ) ;
V_44 . type = V_183 ;
V_44 . V_82 = V_280 -> V_36 ;
V_8 = F_41 ( V_2 , log , V_41 , & V_44 ,
sizeof( * V_303 ) ) ;
if ( V_8 )
return V_8 ;
}
V_94 = V_41 -> V_59 [ 0 ] ;
V_303 = F_35 ( V_94 , V_41 -> V_60 [ 0 ] ,
struct V_83 ) ;
F_238 ( V_94 , V_303 , V_2 -> V_79 ,
& V_76 ) ;
if ( F_170 ( V_289 , & V_280 -> V_250 ) )
F_239 ( V_94 , V_303 ,
V_87 ,
& V_76 ) ;
else
F_239 ( V_94 , V_303 ,
V_86 ,
& V_76 ) ;
V_301 = F_199 ( V_280 -> V_301 , V_280 -> V_302 ) ;
if ( V_280 -> V_300 != V_309 ) {
F_240 ( V_94 , V_303 ,
V_280 -> V_290 ,
& V_76 ) ;
F_241 ( V_94 , V_303 , V_301 ,
& V_76 ) ;
} else if ( V_280 -> V_290 < V_310 ) {
F_240 ( V_94 , V_303 ,
V_280 -> V_290 -
V_304 , & V_76 ) ;
F_241 ( V_94 , V_303 , V_301 ,
& V_76 ) ;
} else {
F_240 ( V_94 , V_303 , 0 , & V_76 ) ;
F_241 ( V_94 , V_303 , 0 ,
& V_76 ) ;
}
F_242 ( V_94 , V_303 , V_304 , & V_76 ) ;
F_243 ( V_94 , V_303 , V_280 -> V_37 , & V_76 ) ;
F_244 ( V_94 , V_303 , V_280 -> V_311 , & V_76 ) ;
F_245 ( V_94 , V_303 , V_280 -> V_300 ,
& V_76 ) ;
F_246 ( V_94 , V_303 , 0 , & V_76 ) ;
F_247 ( V_94 , V_303 , 0 , & V_76 ) ;
F_51 ( V_94 ) ;
F_31 ( V_41 ) ;
return V_8 ;
}
static int F_248 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_84 * V_84 ,
struct V_40 * V_41 ,
struct V_263 * V_281 ,
struct V_5 * V_6 )
{
struct V_277 * V_280 , * V_312 ;
struct V_263 V_313 ;
struct V_314 * V_315 = & F_115 ( V_84 ) -> V_316 ;
T_1 V_317 ;
int V_8 = 0 ;
int V_318 = 0 ;
F_165 ( & V_313 ) ;
F_249 ( & V_315 -> V_319 ) ;
V_317 = V_4 -> V_11 -> V_320 ;
F_250 (em, n, &tree->modified_extents, list) {
F_163 ( & V_280 -> V_22 ) ;
if ( ++ V_318 > 32768 ) {
F_163 ( & V_315 -> V_321 ) ;
V_8 = - V_322 ;
goto V_323;
}
if ( V_280 -> V_240 <= V_317 )
continue;
F_6 ( & V_280 -> V_324 ) ;
F_5 ( V_325 , & V_280 -> V_250 ) ;
F_7 ( & V_280 -> V_22 , & V_313 ) ;
V_318 ++ ;
}
F_251 ( NULL , & V_313 , F_229 ) ;
V_323:
while ( ! F_71 ( & V_313 ) ) {
V_280 = F_72 ( V_313 . V_103 , struct V_277 , V_22 ) ;
F_163 ( & V_280 -> V_22 ) ;
if ( V_8 ) {
F_252 ( V_315 , V_280 ) ;
F_253 ( V_280 ) ;
continue;
}
F_254 ( & V_315 -> V_319 ) ;
V_8 = F_236 ( V_2 , V_84 , V_4 , V_280 , V_41 , V_281 ,
V_6 ) ;
F_249 ( & V_315 -> V_319 ) ;
F_252 ( V_315 , V_280 ) ;
F_253 ( V_280 ) ;
}
F_136 ( ! F_71 ( & V_313 ) ) ;
F_254 ( & V_315 -> V_319 ) ;
F_31 ( V_41 ) ;
return V_8 ;
}
static int F_255 ( struct V_3 * log , struct V_84 * V_84 ,
struct V_40 * V_41 , T_1 * V_326 )
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
* V_326 = F_256 ( V_84 ) ;
} else {
struct V_64 * V_65 ;
V_65 = F_35 ( V_41 -> V_59 [ 0 ] , V_41 -> V_60 [ 0 ] ,
struct V_64 ) ;
* V_326 = F_46 ( V_41 -> V_59 [ 0 ] , V_65 ) ;
}
F_31 ( V_41 ) ;
return 0 ;
}
static int F_257 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_84 * V_84 ,
int V_254 ,
const T_5 V_36 ,
const T_5 V_218 ,
struct V_5 * V_6 )
{
struct V_40 * V_41 ;
struct V_40 * V_228 ;
struct V_43 V_231 ;
struct V_43 V_235 ;
struct V_3 * log = V_4 -> V_10 ;
struct V_28 * V_232 = NULL ;
F_65 ( V_281 ) ;
T_1 V_252 = 0 ;
int V_220 = 0 ;
int V_8 ;
int V_165 ;
int V_327 = 0 ;
int V_328 ;
bool V_329 = false ;
T_1 V_142 = F_61 ( V_84 ) ;
struct V_314 * V_330 = & F_115 ( V_84 ) -> V_316 ;
T_1 V_239 = 0 ;
V_41 = F_89 () ;
if ( ! V_41 )
return - V_63 ;
V_228 = F_89 () ;
if ( ! V_228 ) {
F_93 ( V_41 ) ;
return - V_63 ;
}
V_231 . V_54 = V_142 ;
V_231 . type = V_52 ;
V_231 . V_82 = 0 ;
V_235 . V_54 = V_142 ;
if ( F_39 ( V_84 -> V_147 ) ||
( ! F_170 ( V_331 ,
& F_115 ( V_84 ) -> V_332 ) &&
V_254 == V_268 ) )
V_235 . type = V_182 ;
else
V_235 . type = ( T_4 ) - 1 ;
V_235 . V_82 = ( T_1 ) - 1 ;
if ( F_39 ( V_84 -> V_147 ) ||
F_115 ( V_84 ) -> V_240 > V_4 -> V_11 -> V_320 )
V_8 = F_258 ( V_2 , V_84 ) ;
else
V_8 = F_259 ( V_84 ) ;
if ( V_8 ) {
F_93 ( V_41 ) ;
F_93 ( V_228 ) ;
return V_8 ;
}
F_2 ( & F_115 ( V_84 ) -> V_9 ) ;
F_260 ( V_84 , & V_281 , V_36 , V_218 ) ;
if ( F_39 ( V_84 -> V_147 ) ) {
int V_236 = V_174 ;
if ( V_254 == V_268 ) {
V_236 = V_121 ;
V_235 . type = V_236 ;
}
V_8 = F_201 ( V_2 , log , V_41 , V_142 , V_236 ) ;
} else {
if ( V_254 == V_268 ) {
V_220 = F_255 ( log , V_84 , V_41 ,
& V_239 ) ;
if ( V_220 )
goto V_224;
}
if ( F_170 ( V_331 ,
& F_115 ( V_84 ) -> V_332 ) ) {
if ( V_254 == V_268 ) {
V_235 . type = V_121 ;
V_8 = F_201 ( V_2 , log , V_41 , V_142 ,
V_235 . type ) ;
} else {
F_4 ( V_331 ,
& F_115 ( V_84 ) -> V_332 ) ;
F_4 ( V_333 ,
& F_115 ( V_84 ) -> V_332 ) ;
V_8 = F_261 ( V_2 , log ,
V_84 , 0 , 0 ) ;
}
} else if ( F_170 ( V_333 ,
& F_115 ( V_84 ) -> V_332 ) ||
V_254 == V_268 ) {
if ( V_254 == V_334 ) {
F_4 ( V_333 ,
& F_115 ( V_84 ) -> V_332 ) ;
V_329 = true ;
V_235 . type = V_182 ;
} else {
V_235 . type = V_121 ;
}
V_8 = F_201 ( V_2 , log , V_41 , V_142 ,
V_235 . type ) ;
} else {
if ( V_254 == V_334 )
V_329 = true ;
V_8 = F_222 ( V_2 , log , V_228 , V_84 ) ;
if ( V_8 ) {
V_220 = V_8 ;
goto V_224;
}
goto V_335;
}
}
if ( V_8 ) {
V_220 = V_8 ;
goto V_224;
}
while ( 1 ) {
V_328 = 0 ;
V_8 = F_197 ( V_4 , & V_231 ,
V_41 , V_2 -> V_79 ) ;
if ( V_8 != 0 )
break;
V_131:
if ( V_231 . V_54 != V_142 )
break;
if ( V_231 . type > V_235 . type )
break;
V_232 = V_41 -> V_59 [ 0 ] ;
if ( V_328 && V_327 + V_328 == V_41 -> V_60 [ 0 ] ) {
V_328 ++ ;
goto V_336;
} else if ( ! V_328 ) {
V_327 = V_41 -> V_60 [ 0 ] ;
V_328 = 1 ;
goto V_336;
}
V_8 = F_223 ( V_2 , V_84 , V_228 , V_41 , & V_252 ,
V_327 , V_328 , V_254 ,
V_239 ) ;
if ( V_8 < 0 ) {
V_220 = V_8 ;
goto V_224;
}
if ( V_8 ) {
V_328 = 0 ;
F_31 ( V_41 ) ;
continue;
}
V_328 = 1 ;
V_327 = V_41 -> V_60 [ 0 ] ;
V_336:
V_165 = F_130 ( V_41 -> V_59 [ 0 ] ) ;
V_41 -> V_60 [ 0 ] ++ ;
if ( V_41 -> V_60 [ 0 ] < V_165 ) {
F_112 ( V_41 -> V_59 [ 0 ] , & V_231 ,
V_41 -> V_60 [ 0 ] ) ;
goto V_131;
}
if ( V_328 ) {
V_8 = F_223 ( V_2 , V_84 , V_228 , V_41 ,
& V_252 , V_327 ,
V_328 , V_254 , V_239 ) ;
if ( V_8 < 0 ) {
V_220 = V_8 ;
goto V_224;
}
V_8 = 0 ;
V_328 = 0 ;
}
F_31 ( V_41 ) ;
if ( V_231 . V_82 < ( T_1 ) - 1 ) {
V_231 . V_82 ++ ;
} else if ( V_231 . type < V_235 . type ) {
V_231 . type ++ ;
V_231 . V_82 = 0 ;
} else {
break;
}
}
if ( V_328 ) {
V_8 = F_223 ( V_2 , V_84 , V_228 , V_41 , & V_252 ,
V_327 , V_328 , V_254 ,
V_239 ) ;
if ( V_8 < 0 ) {
V_220 = V_8 ;
goto V_224;
}
V_8 = 0 ;
V_328 = 0 ;
}
V_335:
F_31 ( V_41 ) ;
F_31 ( V_228 ) ;
if ( V_329 ) {
V_220 = F_233 ( V_84 ) ;
if ( V_220 ) {
V_6 -> V_308 = V_220 ;
goto V_224;
}
V_8 = F_248 ( V_2 , V_4 , V_84 , V_228 ,
& V_281 , V_6 ) ;
if ( V_8 ) {
V_220 = V_8 ;
goto V_224;
}
} else if ( V_254 == V_334 ) {
struct V_277 * V_280 , * V_312 ;
F_249 ( & V_330 -> V_319 ) ;
F_250 (em, n, &em_tree->modified_extents,
list) {
const T_1 V_337 = V_280 -> V_285 + V_280 -> V_286 - 1 ;
if ( V_280 -> V_285 >= V_36 && V_337 <= V_218 )
F_163 ( & V_280 -> V_22 ) ;
}
F_254 ( & V_330 -> V_319 ) ;
}
if ( V_254 == V_334 && F_39 ( V_84 -> V_147 ) ) {
V_8 = F_200 ( V_2 , V_4 , V_84 , V_41 , V_228 ) ;
if ( V_8 ) {
V_220 = V_8 ;
goto V_224;
}
}
F_115 ( V_84 ) -> V_223 = V_2 -> V_79 ;
F_115 ( V_84 ) -> V_217 = F_115 ( V_84 ) -> V_338 ;
V_224:
if ( F_262 ( V_220 ) )
F_263 ( & V_281 ) ;
else
F_264 ( & V_281 , log ) ;
F_8 ( & F_115 ( V_84 ) -> V_9 ) ;
F_93 ( V_41 ) ;
F_93 ( V_228 ) ;
return V_220 ;
}
static T_2 int F_265 ( struct V_1 * V_2 ,
struct V_84 * V_84 ,
struct V_339 * V_188 ,
struct V_340 * V_341 ,
T_1 V_342 )
{
int V_8 = 0 ;
struct V_3 * V_4 ;
struct V_339 * V_343 = NULL ;
struct V_84 * V_344 = V_84 ;
if ( F_45 ( V_84 -> V_147 ) &&
F_115 ( V_84 ) -> V_240 <= V_342 &&
F_115 ( V_84 ) -> V_345 <= V_342 )
goto V_13;
if ( ! F_39 ( V_84 -> V_147 ) ) {
if ( ! V_188 || ! V_188 -> V_346 || V_341 != V_188 -> V_346 -> V_347 )
goto V_13;
V_84 = V_188 -> V_346 ;
}
while ( 1 ) {
if ( V_84 != V_344 )
F_115 ( V_84 ) -> V_223 = V_2 -> V_79 ;
F_12 () ;
if ( F_115 ( V_84 ) -> V_345 > V_342 ) {
V_4 = F_115 ( V_84 ) -> V_4 ;
F_177 ( V_4 -> V_11 , V_2 ) ;
V_8 = 1 ;
break;
}
if ( ! V_188 || ! V_188 -> V_346 || V_341 != V_188 -> V_346 -> V_347 )
break;
if ( F_266 ( V_188 ) )
break;
V_188 = F_267 ( V_188 ) ;
F_268 ( V_343 ) ;
V_343 = V_188 ;
V_84 = V_188 -> V_346 ;
}
F_268 ( V_343 ) ;
V_13:
return V_8 ;
}
static int F_269 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_84 * V_84 ,
struct V_339 * V_188 ,
const T_5 V_36 ,
const T_5 V_218 ,
int V_348 ,
struct V_5 * V_6 )
{
int V_254 = V_348 ? V_268 : V_334 ;
struct V_340 * V_341 ;
struct V_339 * V_343 = NULL ;
int V_8 = 0 ;
T_1 V_342 = V_4 -> V_11 -> V_320 ;
const struct V_339 * const V_349 = V_188 ;
const bool V_350 = ( F_115 ( V_84 ) -> V_345 >
V_342 ) ;
V_341 = V_84 -> V_347 ;
if ( F_169 ( V_4 , V_351 ) ) {
V_8 = 1 ;
goto V_352;
}
if ( V_4 -> V_11 -> V_353 >
V_4 -> V_11 -> V_320 ) {
V_8 = 1 ;
goto V_352;
}
if ( V_4 != F_115 ( V_84 ) -> V_4 ||
F_270 ( & V_4 -> V_196 ) == 0 ) {
V_8 = 1 ;
goto V_352;
}
V_8 = F_265 ( V_2 , V_84 , V_188 ,
V_341 , V_342 ) ;
if ( V_8 )
goto V_352;
if ( F_271 ( V_84 , V_2 -> V_79 ) ) {
V_8 = V_354 ;
goto V_352;
}
V_8 = F_1 ( V_2 , V_4 , V_6 ) ;
if ( V_8 )
goto V_352;
V_8 = F_257 ( V_2 , V_4 , V_84 , V_254 , V_36 , V_218 , V_6 ) ;
if ( V_8 )
goto V_355;
if ( F_45 ( V_84 -> V_147 ) &&
F_115 ( V_84 ) -> V_240 <= V_342 &&
F_115 ( V_84 ) -> V_345 <= V_342 ) {
V_8 = 0 ;
goto V_355;
}
while ( 1 ) {
if ( ! V_188 || ! V_188 -> V_346 || V_341 != V_188 -> V_346 -> V_347 )
break;
V_84 = V_188 -> V_346 ;
if ( V_4 != F_115 ( V_84 ) -> V_4 )
break;
if ( V_350 && V_188 == V_349 )
V_254 = V_334 ;
else
V_254 = V_268 ;
if ( F_115 ( V_84 ) -> V_240 >
V_4 -> V_11 -> V_320 ||
V_254 == V_334 ) {
V_8 = F_257 ( V_2 , V_4 , V_84 , V_254 ,
0 , V_356 , V_6 ) ;
if ( V_8 )
goto V_355;
}
if ( F_266 ( V_188 ) )
break;
V_188 = F_267 ( V_188 ) ;
F_268 ( V_343 ) ;
V_343 = V_188 ;
}
V_8 = 0 ;
V_355:
F_268 ( V_343 ) ;
if ( V_8 < 0 ) {
F_177 ( V_4 -> V_11 , V_2 ) ;
V_8 = 1 ;
}
if ( V_8 )
F_162 ( V_4 , V_6 ) ;
F_14 ( V_4 ) ;
V_352:
return V_8 ;
}
int F_272 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_339 * V_339 ,
const T_5 V_36 ,
const T_5 V_218 ,
struct V_5 * V_6 )
{
struct V_339 * V_188 = F_267 ( V_339 ) ;
int V_8 ;
V_8 = F_269 ( V_2 , V_4 , V_339 -> V_346 , V_188 ,
V_36 , V_218 , 0 , V_6 ) ;
F_268 ( V_188 ) ;
return V_8 ;
}
int F_273 ( struct V_3 * V_25 )
{
int V_8 ;
struct V_40 * V_41 ;
struct V_1 * V_2 ;
struct V_43 V_44 ;
struct V_43 V_151 ;
struct V_43 V_357 ;
struct V_3 * log ;
struct V_219 * V_11 = V_25 -> V_11 ;
struct V_30 V_31 = {
. V_192 = F_18 ,
. V_178 = 0 ,
} ;
V_41 = F_89 () ;
if ( ! V_41 )
return - V_63 ;
V_11 -> V_358 = 1 ;
V_2 = F_274 ( V_11 -> V_216 , 0 ) ;
if ( F_86 ( V_2 ) ) {
V_8 = F_133 ( V_2 ) ;
goto error;
}
V_31 . V_2 = V_2 ;
V_31 . V_34 = 1 ;
V_8 = F_150 ( V_2 , V_25 , & V_31 ) ;
if ( V_8 ) {
F_275 ( V_11 , V_8 , L_1
L_2 ) ;
goto error;
}
V_131:
V_44 . V_54 = V_55 ;
V_44 . V_82 = ( T_1 ) - 1 ;
V_44 . type = V_359 ;
while ( 1 ) {
V_8 = F_30 ( NULL , V_25 , & V_44 , V_41 , 0 , 0 ) ;
if ( V_8 < 0 ) {
F_275 ( V_11 , V_8 ,
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
log = F_276 ( V_25 , & V_151 ) ;
if ( F_86 ( log ) ) {
V_8 = F_133 ( log ) ;
F_275 ( V_11 , V_8 ,
L_4 ) ;
goto error;
}
V_357 . V_54 = V_151 . V_82 ;
V_357 . type = V_359 ;
V_357 . V_82 = ( T_1 ) - 1 ;
V_31 . V_175 = F_277 ( V_11 , & V_357 ) ;
if ( F_86 ( V_31 . V_175 ) ) {
V_8 = F_133 ( V_31 . V_175 ) ;
F_141 ( log -> V_193 ) ;
F_141 ( log -> V_360 ) ;
F_33 ( log ) ;
F_275 ( V_11 , V_8 , L_5
L_6 ) ;
goto error;
}
V_31 . V_175 -> V_10 = log ;
F_278 ( V_2 , V_31 . V_175 ) ;
V_8 = F_150 ( V_2 , log , & V_31 ) ;
if ( ! V_8 && V_31 . V_178 == V_181 ) {
V_8 = F_117 ( V_2 , V_31 . V_175 ,
V_41 ) ;
}
V_44 . V_82 = V_151 . V_82 - 1 ;
V_31 . V_175 -> V_10 = NULL ;
F_141 ( log -> V_193 ) ;
F_141 ( log -> V_360 ) ;
F_33 ( log ) ;
if ( V_8 )
goto error;
if ( V_151 . V_82 == 0 )
break;
}
F_31 ( V_41 ) ;
if ( V_31 . V_34 ) {
V_31 . V_34 = 0 ;
V_31 . V_192 = F_134 ;
V_31 . V_178 = V_179 ;
goto V_131;
}
if ( V_31 . V_178 < V_181 ) {
V_31 . V_178 ++ ;
goto V_131;
}
F_93 ( V_41 ) ;
V_8 = F_279 ( V_2 , V_11 -> V_216 ) ;
if ( V_8 )
return V_8 ;
F_141 ( V_25 -> V_193 ) ;
V_25 -> V_10 = NULL ;
V_11 -> V_358 = 0 ;
F_33 ( V_25 ) ;
return 0 ;
error:
if ( V_31 . V_2 )
F_280 ( V_31 . V_2 , V_11 -> V_216 ) ;
F_93 ( V_41 ) ;
return V_8 ;
}
void F_281 ( struct V_1 * V_2 ,
struct V_84 * V_105 , struct V_84 * V_84 ,
int V_361 )
{
if ( F_45 ( V_84 -> V_147 ) )
F_115 ( V_84 ) -> V_345 = V_2 -> V_79 ;
F_12 () ;
if ( F_115 ( V_105 ) -> V_223 == V_2 -> V_79 )
return;
if ( F_115 ( V_84 ) -> V_223 == V_2 -> V_79 )
return;
if ( V_361 )
goto V_362;
return;
V_362:
F_115 ( V_105 ) -> V_345 = V_2 -> V_79 ;
}
int F_282 ( struct V_1 * V_2 ,
struct V_84 * V_84 , struct V_84 * V_363 ,
struct V_339 * V_188 )
{
struct V_3 * V_4 = F_115 ( V_84 ) -> V_4 ;
if ( F_45 ( V_84 -> V_147 ) )
F_115 ( V_84 ) -> V_345 = V_2 -> V_79 ;
if ( F_115 ( V_84 ) -> V_223 <=
V_4 -> V_11 -> V_320 &&
( ! V_363 || F_115 ( V_363 ) -> V_223 <=
V_4 -> V_11 -> V_320 ) )
return 0 ;
return F_269 ( V_2 , V_4 , V_84 , V_188 , 0 ,
V_356 , 1 , NULL ) ;
}
