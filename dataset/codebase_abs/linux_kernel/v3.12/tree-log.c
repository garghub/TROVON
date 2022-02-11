static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_5 ;
int V_6 = 0 ;
F_2 ( & V_4 -> V_7 ) ;
if ( V_4 -> V_8 ) {
if ( ! V_4 -> V_9 ) {
V_4 -> V_9 = V_10 -> V_11 ;
V_4 -> V_12 = false ;
} else if ( V_4 -> V_9 != V_10 -> V_11 ) {
V_4 -> V_12 = true ;
}
F_3 ( & V_4 -> V_13 ) ;
F_3 ( & V_4 -> V_14 ) ;
F_4 ( & V_4 -> V_7 ) ;
return 0 ;
}
V_4 -> V_12 = false ;
V_4 -> V_9 = V_10 -> V_11 ;
F_2 ( & V_4 -> V_15 -> V_16 ) ;
if ( ! V_4 -> V_15 -> V_17 ) {
V_5 = F_5 ( V_2 , V_4 -> V_15 ) ;
if ( V_5 )
V_6 = V_5 ;
}
if ( V_6 == 0 && ! V_4 -> V_8 ) {
V_5 = F_6 ( V_2 , V_4 ) ;
if ( V_5 )
V_6 = V_5 ;
}
F_4 ( & V_4 -> V_15 -> V_16 ) ;
F_3 ( & V_4 -> V_13 ) ;
F_3 ( & V_4 -> V_14 ) ;
F_4 ( & V_4 -> V_7 ) ;
return V_6 ;
}
static int F_7 ( struct V_3 * V_4 )
{
int V_5 = - V_18 ;
F_8 () ;
if ( ! V_4 -> V_8 )
return - V_18 ;
F_2 ( & V_4 -> V_7 ) ;
if ( V_4 -> V_8 ) {
V_5 = 0 ;
F_3 ( & V_4 -> V_14 ) ;
}
F_4 ( & V_4 -> V_7 ) ;
return V_5 ;
}
int F_9 ( struct V_3 * V_4 )
{
int V_5 = - V_18 ;
F_2 ( & V_4 -> V_7 ) ;
F_3 ( & V_4 -> V_14 ) ;
F_4 ( & V_4 -> V_7 ) ;
return V_5 ;
}
void F_10 ( struct V_3 * V_4 )
{
if ( F_11 ( & V_4 -> V_14 ) ) {
F_8 () ;
if ( F_12 ( & V_4 -> V_19 ) )
F_13 ( & V_4 -> V_19 ) ;
}
}
static int F_14 ( struct V_3 * log ,
struct V_20 * V_21 ,
struct V_22 * V_23 , T_1 V_24 )
{
int V_5 = 0 ;
if ( F_15 ( log -> V_15 , V_25 ) ) {
V_5 = F_16 ( V_21 , V_24 ) ;
if ( V_5 )
return V_5 ;
}
if ( V_23 -> V_26 )
V_5 = F_17 ( log -> V_15 -> V_27 ,
V_21 -> V_28 , V_21 -> V_29 ) ;
if ( ! V_5 && F_18 ( V_21 , V_24 , 0 ) ) {
if ( V_23 -> V_26 && F_19 ( V_21 ) == 0 )
V_5 = F_20 ( log , V_21 ) ;
if ( V_23 -> V_30 )
F_21 ( V_21 ) ;
if ( V_23 -> V_31 )
F_22 ( V_21 ) ;
}
return V_5 ;
}
static T_2 int F_23 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_32 * V_33 ,
struct V_20 * V_21 , int V_34 ,
struct V_35 * V_36 )
{
int V_5 ;
T_3 V_37 ;
T_1 V_38 = 0 ;
int V_39 = 0 ;
unsigned long V_40 ;
unsigned long V_41 ;
int V_42 = 0 ;
bool V_43 = V_36 -> type == V_44 ;
if ( V_4 -> V_45 . V_46 != V_47 )
V_42 = 1 ;
V_37 = F_24 ( V_21 , V_34 ) ;
V_40 = F_25 ( V_21 , V_34 ) ;
V_5 = F_26 ( NULL , V_4 , V_36 , V_33 , 0 , 0 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( V_5 == 0 ) {
char * V_48 ;
char * V_49 ;
T_3 V_50 = F_24 ( V_33 -> V_51 [ 0 ] ,
V_33 -> V_52 [ 0 ] ) ;
if ( V_50 != V_37 )
goto V_53;
if ( V_37 == 0 ) {
F_27 ( V_33 ) ;
return 0 ;
}
V_49 = F_28 ( V_37 , V_54 ) ;
V_48 = F_28 ( V_37 , V_54 ) ;
if ( ! V_49 || ! V_48 ) {
F_27 ( V_33 ) ;
F_29 ( V_49 ) ;
F_29 ( V_48 ) ;
return - V_55 ;
}
F_30 ( V_21 , V_48 , V_40 , V_37 ) ;
V_41 = F_25 ( V_33 -> V_51 [ 0 ] , V_33 -> V_52 [ 0 ] ) ;
F_30 ( V_33 -> V_51 [ 0 ] , V_49 , V_41 ,
V_37 ) ;
V_5 = memcmp ( V_49 , V_48 , V_37 ) ;
F_29 ( V_49 ) ;
F_29 ( V_48 ) ;
if ( V_5 == 0 ) {
F_27 ( V_33 ) ;
return 0 ;
}
if ( V_43 ) {
struct V_56 * V_57 ;
T_1 V_58 ;
T_3 V_59 ;
V_57 = F_31 ( V_33 -> V_51 [ 0 ] , V_33 -> V_52 [ 0 ] ,
struct V_56 ) ;
V_58 = F_32 ( V_33 -> V_51 [ 0 ] , V_57 ) ;
V_57 = F_31 ( V_21 , V_34 ,
struct V_56 ) ;
F_33 ( V_21 , V_57 , V_58 ) ;
V_59 = F_34 ( V_21 , V_57 ) ;
if ( F_35 ( V_59 ) )
F_36 ( V_21 , V_57 , 0 ) ;
}
} else if ( V_43 ) {
struct V_56 * V_57 ;
T_3 V_59 ;
V_57 = F_31 ( V_21 , V_34 , struct V_56 ) ;
F_33 ( V_21 , V_57 , 0 ) ;
V_59 = F_34 ( V_21 , V_57 ) ;
if ( F_35 ( V_59 ) )
F_36 ( V_21 , V_57 , 0 ) ;
}
V_53:
F_27 ( V_33 ) ;
V_5 = F_37 ( V_2 , V_4 , V_33 ,
V_36 , V_37 ) ;
if ( V_5 == - V_60 ) {
T_3 V_61 ;
V_61 = F_24 ( V_33 -> V_51 [ 0 ] ,
V_33 -> V_52 [ 0 ] ) ;
if ( V_61 > V_37 )
F_38 ( V_4 , V_33 , V_37 , 1 ) ;
else if ( V_61 < V_37 )
F_39 ( V_4 , V_33 ,
V_37 - V_61 ) ;
} else if ( V_5 ) {
return V_5 ;
}
V_41 = F_25 ( V_33 -> V_51 [ 0 ] ,
V_33 -> V_52 [ 0 ] ) ;
if ( V_36 -> type == V_44 && V_5 == - V_60 ) {
struct V_56 * V_62 ;
struct V_56 * V_63 ;
V_62 = (struct V_56 * ) V_40 ;
V_63 = (struct V_56 * ) V_41 ;
if ( F_40 ( V_21 , V_62 ) == 0 )
goto V_64;
if ( V_42 &&
F_35 ( F_34 ( V_21 , V_62 ) ) &&
F_35 ( F_34 ( V_33 -> V_51 [ 0 ] , V_63 ) ) ) {
V_39 = 1 ;
V_38 = F_41 ( V_33 -> V_51 [ 0 ] ,
V_63 ) ;
}
}
F_42 ( V_33 -> V_51 [ 0 ] , V_21 , V_41 ,
V_40 , V_37 ) ;
if ( V_39 ) {
struct V_56 * V_63 ;
V_63 = (struct V_56 * ) V_41 ;
F_36 ( V_33 -> V_51 [ 0 ] , V_63 , V_38 ) ;
}
if ( V_36 -> type == V_44 ) {
struct V_56 * V_63 ;
V_63 = (struct V_56 * ) V_41 ;
if ( F_40 ( V_33 -> V_51 [ 0 ] , V_63 ) == 0 ) {
F_43 ( V_33 -> V_51 [ 0 ] , V_63 ,
V_2 -> V_65 ) ;
}
}
V_64:
F_44 ( V_33 -> V_51 [ 0 ] ) ;
F_27 ( V_33 ) ;
return 0 ;
}
T_2 int F_45 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_32 * V_33 ,
struct V_20 * V_21 , int V_34 ,
struct V_35 * V_36 )
{
int V_66 ;
T_1 V_67 ;
T_1 V_28 = V_36 -> V_68 ;
T_1 V_58 = 0 ;
struct V_69 * V_57 ;
struct V_70 * V_70 = NULL ;
unsigned long V_71 ;
int V_5 = 0 ;
V_57 = F_31 ( V_21 , V_34 , struct V_69 ) ;
V_66 = F_46 ( V_21 , V_57 ) ;
if ( V_66 == V_72 ||
V_66 == V_73 ) {
V_58 = F_47 ( V_21 , V_57 ) ;
V_67 = V_28 + V_58 ;
if ( F_48 ( V_21 , V_57 ) == 0 )
V_58 = 0 ;
} else if ( V_66 == V_74 ) {
V_71 = F_49 ( V_21 , V_57 ) ;
V_58 = F_50 ( V_21 , V_57 ) ;
V_67 = F_51 ( V_28 + V_71 , V_4 -> V_75 ) ;
} else {
V_5 = 0 ;
goto V_76;
}
V_70 = F_52 ( V_4 , V_36 -> V_46 ) ;
if ( ! V_70 ) {
V_5 = - V_77 ;
goto V_76;
}
V_5 = F_53 ( V_2 , V_4 , V_33 , F_54 ( V_70 ) ,
V_28 , 0 ) ;
if ( V_5 == 0 &&
( V_66 == V_72 ||
V_66 == V_73 ) ) {
struct V_69 V_78 ;
struct V_69 V_79 ;
struct V_69 * V_80 ;
struct V_20 * V_81 ;
V_81 = V_33 -> V_51 [ 0 ] ;
V_80 = F_31 ( V_81 , V_33 -> V_52 [ 0 ] ,
struct V_69 ) ;
F_30 ( V_21 , & V_78 , ( unsigned long ) V_57 ,
sizeof( V_78 ) ) ;
F_30 ( V_81 , & V_79 , ( unsigned long ) V_80 ,
sizeof( V_79 ) ) ;
if ( memcmp ( & V_78 , & V_79 , sizeof( V_78 ) ) == 0 ) {
F_27 ( V_33 ) ;
goto V_76;
}
}
F_27 ( V_33 ) ;
V_5 = F_55 ( V_2 , V_4 , V_70 , V_28 , V_67 , 1 ) ;
if ( V_5 )
goto V_76;
if ( V_66 == V_72 ||
V_66 == V_73 ) {
T_1 V_68 ;
unsigned long V_82 ;
struct V_35 V_83 ;
V_5 = F_37 ( V_2 , V_4 , V_33 , V_36 ,
sizeof( * V_57 ) ) ;
if ( V_5 )
goto V_76;
V_82 = F_25 ( V_33 -> V_51 [ 0 ] ,
V_33 -> V_52 [ 0 ] ) ;
F_42 ( V_33 -> V_51 [ 0 ] , V_21 , V_82 ,
( unsigned long ) V_57 , sizeof( * V_57 ) ) ;
V_83 . V_46 = F_48 ( V_21 , V_57 ) ;
V_83 . V_68 = F_56 ( V_21 , V_57 ) ;
V_83 . type = V_84 ;
V_68 = V_36 -> V_68 - F_57 ( V_21 , V_57 ) ;
if ( V_83 . V_46 > 0 ) {
T_1 V_85 ;
T_1 V_86 ;
F_58 ( V_87 ) ;
V_5 = F_59 ( V_4 , V_83 . V_46 ,
V_83 . V_68 ) ;
if ( V_5 == 0 ) {
V_5 = F_60 ( V_2 , V_4 ,
V_83 . V_46 , V_83 . V_68 ,
0 , V_4 -> V_45 . V_46 ,
V_36 -> V_46 , V_68 , 0 ) ;
if ( V_5 )
goto V_76;
} else {
V_5 = F_61 ( V_2 ,
V_4 , V_4 -> V_45 . V_46 ,
V_36 -> V_46 , V_68 , & V_83 ) ;
if ( V_5 )
goto V_76;
}
F_27 ( V_33 ) ;
if ( F_62 ( V_21 , V_57 ) ) {
V_85 = V_83 . V_46 ;
V_86 = V_85 + V_83 . V_68 ;
} else {
V_85 = V_83 . V_46 +
F_57 ( V_21 , V_57 ) ;
V_86 = V_85 +
F_47 ( V_21 , V_57 ) ;
}
V_5 = F_63 ( V_4 -> V_8 ,
V_85 , V_86 - 1 ,
& V_87 , 0 ) ;
if ( V_5 )
goto V_76;
while ( ! F_64 ( & V_87 ) ) {
struct V_88 * V_89 ;
V_89 = F_65 ( V_87 . V_90 ,
struct V_88 ,
V_91 ) ;
if ( ! V_5 )
V_5 = F_66 ( V_2 ,
V_4 -> V_15 -> V_92 ,
V_89 ) ;
F_67 ( & V_89 -> V_91 ) ;
F_29 ( V_89 ) ;
}
if ( V_5 )
goto V_76;
} else {
F_27 ( V_33 ) ;
}
} else if ( V_66 == V_74 ) {
V_5 = F_23 ( V_2 , V_4 , V_33 , V_21 , V_34 , V_36 ) ;
if ( V_5 )
goto V_76;
}
F_68 ( V_70 , V_58 ) ;
V_5 = F_69 ( V_2 , V_4 , V_70 ) ;
V_76:
if ( V_70 )
F_70 ( V_70 ) ;
return V_5 ;
}
static T_2 int F_71 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_32 * V_33 ,
struct V_70 * V_93 ,
struct V_94 * V_95 )
{
struct V_70 * V_70 ;
char * V_96 ;
int V_97 ;
struct V_20 * V_81 ;
struct V_35 V_98 ;
int V_5 ;
V_81 = V_33 -> V_51 [ 0 ] ;
F_72 ( V_81 , V_95 , & V_98 ) ;
V_97 = F_73 ( V_81 , V_95 ) ;
V_96 = F_28 ( V_97 , V_54 ) ;
if ( ! V_96 )
return - V_55 ;
F_30 ( V_81 , V_96 , ( unsigned long ) ( V_95 + 1 ) , V_97 ) ;
F_27 ( V_33 ) ;
V_70 = F_52 ( V_4 , V_98 . V_46 ) ;
if ( ! V_70 ) {
V_5 = - V_77 ;
goto V_76;
}
V_5 = F_74 ( V_2 , V_4 , V_33 , V_98 . V_46 ) ;
if ( V_5 )
goto V_76;
V_5 = F_75 ( V_2 , V_4 , V_93 , V_70 , V_96 , V_97 ) ;
if ( V_5 )
goto V_76;
else
V_5 = F_76 ( V_2 , V_4 ) ;
V_76:
F_29 ( V_96 ) ;
F_70 ( V_70 ) ;
return V_5 ;
}
static T_2 int F_77 ( struct V_3 * V_4 ,
struct V_32 * V_33 ,
T_1 V_99 , T_1 V_46 , T_1 V_100 ,
const char * V_96 , int V_97 )
{
struct V_94 * V_95 ;
struct V_35 V_98 ;
int V_101 = 0 ;
V_95 = F_78 ( NULL , V_4 , V_33 , V_99 ,
V_100 , V_96 , V_97 , 0 ) ;
if ( V_95 && ! F_79 ( V_95 ) ) {
F_72 ( V_33 -> V_51 [ 0 ] , V_95 , & V_98 ) ;
if ( V_98 . V_46 != V_46 )
goto V_76;
} else
goto V_76;
F_27 ( V_33 ) ;
V_95 = F_80 ( NULL , V_4 , V_33 , V_99 , V_96 , V_97 , 0 ) ;
if ( V_95 && ! F_79 ( V_95 ) ) {
F_72 ( V_33 -> V_51 [ 0 ] , V_95 , & V_98 ) ;
if ( V_98 . V_46 != V_46 )
goto V_76;
} else
goto V_76;
V_101 = 1 ;
V_76:
F_27 ( V_33 ) ;
return V_101 ;
}
static T_2 int F_81 ( struct V_3 * log ,
struct V_35 * V_36 ,
T_1 V_102 ,
char * V_96 , int V_103 )
{
struct V_32 * V_33 ;
struct V_104 * V_105 ;
unsigned long V_106 ;
unsigned long V_107 ;
unsigned long V_108 ;
int V_109 ;
int V_37 ;
int V_5 ;
int V_101 = 0 ;
V_33 = F_82 () ;
if ( ! V_33 )
return - V_55 ;
V_5 = F_26 ( NULL , log , V_36 , V_33 , 0 , 0 ) ;
if ( V_5 != 0 )
goto V_76;
V_106 = F_25 ( V_33 -> V_51 [ 0 ] , V_33 -> V_52 [ 0 ] ) ;
if ( V_36 -> type == V_110 ) {
if ( F_83 ( V_33 , V_102 ,
V_96 , V_103 , NULL ) )
V_101 = 1 ;
goto V_76;
}
V_37 = F_24 ( V_33 -> V_51 [ 0 ] , V_33 -> V_52 [ 0 ] ) ;
V_107 = V_106 + V_37 ;
while ( V_106 < V_107 ) {
V_105 = (struct V_104 * ) V_106 ;
V_109 = F_84 ( V_33 -> V_51 [ 0 ] , V_105 ) ;
if ( V_109 == V_103 ) {
V_108 = ( unsigned long ) ( V_105 + 1 ) ;
V_5 = F_85 ( V_33 -> V_51 [ 0 ] , V_96 ,
V_108 , V_103 ) ;
if ( V_5 == 0 ) {
V_101 = 1 ;
goto V_76;
}
}
V_106 = ( unsigned long ) ( V_105 + 1 ) + V_109 ;
}
V_76:
F_86 ( V_33 ) ;
return V_101 ;
}
static inline int F_87 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_32 * V_33 ,
struct V_3 * V_8 ,
struct V_70 * V_93 , struct V_70 * V_70 ,
struct V_20 * V_21 ,
T_1 V_111 , T_1 V_112 ,
T_1 V_113 , char * V_96 , int V_103 ,
int * V_114 )
{
int V_5 ;
char * V_115 ;
int V_116 ;
struct V_20 * V_81 ;
struct V_94 * V_95 ;
struct V_35 V_117 ;
struct V_118 * V_119 ;
V_120:
V_117 . V_46 = V_111 ;
V_117 . type = V_121 ;
V_117 . V_68 = V_112 ;
V_5 = F_26 ( NULL , V_4 , & V_117 , V_33 , 0 , 0 ) ;
if ( V_5 == 0 ) {
struct V_104 * V_122 ;
unsigned long V_106 ;
unsigned long V_107 ;
V_81 = V_33 -> V_51 [ 0 ] ;
if ( V_117 . V_46 == V_117 . V_68 )
return 1 ;
V_106 = F_25 ( V_81 , V_33 -> V_52 [ 0 ] ) ;
V_107 = V_106 + F_24 ( V_81 , V_33 -> V_52 [ 0 ] ) ;
while ( V_106 < V_107 ) {
V_122 = (struct V_104 * ) V_106 ;
V_116 = F_84 ( V_81 ,
V_122 ) ;
V_115 = F_28 ( V_116 , V_54 ) ;
if ( ! V_115 )
return - V_55 ;
F_30 ( V_81 , V_115 ,
( unsigned long ) ( V_122 + 1 ) ,
V_116 ) ;
if ( ! F_81 ( V_8 , & V_117 ,
V_112 ,
V_115 ,
V_116 ) ) {
F_88 ( V_70 ) ;
F_27 ( V_33 ) ;
V_5 = F_75 ( V_2 , V_4 , V_93 ,
V_70 , V_115 ,
V_116 ) ;
F_29 ( V_115 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_76 ( V_2 , V_4 ) ;
if ( V_5 )
return V_5 ;
* V_114 = 1 ;
goto V_120;
}
F_29 ( V_115 ) ;
V_106 = ( unsigned long ) ( V_122 + 1 ) + V_116 ;
}
* V_114 = 1 ;
}
F_27 ( V_33 ) ;
V_119 = F_89 ( NULL , V_4 , V_33 , V_96 , V_103 ,
V_111 , V_112 , 0 ,
0 ) ;
if ( ! F_90 ( V_119 ) ) {
T_3 V_37 ;
T_3 V_123 = 0 ;
unsigned long V_124 ;
struct V_70 * V_125 ;
V_81 = V_33 -> V_51 [ 0 ] ;
V_37 = F_24 ( V_81 , V_33 -> V_52 [ 0 ] ) ;
V_124 = F_25 ( V_81 , V_33 -> V_52 [ 0 ] ) ;
while ( V_123 < V_37 ) {
V_119 = (struct V_118 * ) V_124 + V_123 ;
V_116 = F_91 ( V_81 , V_119 ) ;
if ( F_92 ( V_81 , V_119 ) != V_112 )
goto V_90;
V_115 = F_28 ( V_116 , V_54 ) ;
if ( ! V_115 )
return - V_55 ;
F_30 ( V_81 , V_115 , ( unsigned long ) & V_119 -> V_96 ,
V_116 ) ;
V_117 . V_46 = V_111 ;
V_117 . type = V_110 ;
V_117 . V_68 = F_93 ( V_112 ,
V_115 ,
V_116 ) ;
V_5 = 0 ;
if ( ! F_81 ( V_8 , & V_117 ,
V_112 , V_115 ,
V_116 ) ) {
V_5 = - V_18 ;
V_125 = F_52 ( V_4 ,
V_112 ) ;
if ( V_125 ) {
F_88 ( V_70 ) ;
F_27 ( V_33 ) ;
V_5 = F_75 ( V_2 , V_4 ,
V_125 ,
V_70 ,
V_115 ,
V_116 ) ;
if ( ! V_5 )
V_5 = F_76 (
V_2 , V_4 ) ;
}
F_70 ( V_125 ) ;
F_29 ( V_115 ) ;
if ( V_5 )
return V_5 ;
* V_114 = 1 ;
goto V_120;
}
F_29 ( V_115 ) ;
if ( V_5 )
return V_5 ;
V_90:
V_123 += V_116 + sizeof( * V_119 ) ;
}
* V_114 = 1 ;
}
F_27 ( V_33 ) ;
V_95 = F_78 ( V_2 , V_4 , V_33 , F_54 ( V_93 ) ,
V_113 , V_96 , V_103 , 0 ) ;
if ( V_95 && ! F_79 ( V_95 ) ) {
V_5 = F_71 ( V_2 , V_4 , V_33 , V_93 , V_95 ) ;
if ( V_5 )
return V_5 ;
}
F_27 ( V_33 ) ;
V_95 = F_80 ( V_2 , V_4 , V_33 , F_54 ( V_93 ) ,
V_96 , V_103 , 0 ) ;
if ( V_95 && ! F_79 ( V_95 ) ) {
V_5 = F_71 ( V_2 , V_4 , V_33 , V_93 , V_95 ) ;
if ( V_5 )
return V_5 ;
}
F_27 ( V_33 ) ;
return 0 ;
}
static int F_94 ( struct V_20 * V_21 , unsigned long V_126 ,
T_3 * V_103 , char * * V_96 , T_1 * V_100 ,
T_1 * V_112 )
{
struct V_118 * V_119 ;
V_119 = (struct V_118 * ) V_126 ;
* V_103 = F_91 ( V_21 , V_119 ) ;
* V_96 = F_28 ( * V_103 , V_54 ) ;
if ( * V_96 == NULL )
return - V_55 ;
F_30 ( V_21 , * V_96 , ( unsigned long ) & V_119 -> V_96 ,
* V_103 ) ;
* V_100 = F_95 ( V_21 , V_119 ) ;
if ( V_112 )
* V_112 = F_92 ( V_21 , V_119 ) ;
return 0 ;
}
static int F_96 ( struct V_20 * V_21 , unsigned long V_126 ,
T_3 * V_103 , char * * V_96 , T_1 * V_100 )
{
struct V_104 * V_105 ;
V_105 = (struct V_104 * ) V_126 ;
* V_103 = F_84 ( V_21 , V_105 ) ;
* V_96 = F_28 ( * V_103 , V_54 ) ;
if ( * V_96 == NULL )
return - V_55 ;
F_30 ( V_21 , * V_96 , ( unsigned long ) ( V_105 + 1 ) , * V_103 ) ;
* V_100 = F_97 ( V_21 , V_105 ) ;
return 0 ;
}
static T_2 int F_98 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_3 * log ,
struct V_32 * V_33 ,
struct V_20 * V_21 , int V_34 ,
struct V_35 * V_36 )
{
struct V_70 * V_93 ;
struct V_70 * V_70 ;
unsigned long V_126 ;
unsigned long V_127 ;
char * V_96 ;
int V_103 ;
int V_5 ;
int V_114 = 0 ;
int V_128 = 0 ;
T_1 V_112 ;
T_1 V_111 ;
T_1 V_113 = 0 ;
int V_129 ;
V_126 = F_25 ( V_21 , V_34 ) ;
V_127 = V_126 + F_24 ( V_21 , V_34 ) ;
if ( V_36 -> type == V_110 ) {
struct V_118 * V_130 ;
V_129 = sizeof( struct V_118 ) ;
V_128 = 1 ;
V_130 = (struct V_118 * ) V_126 ;
V_112 = F_92 ( V_21 , V_130 ) ;
} else {
V_129 = sizeof( struct V_104 ) ;
V_112 = V_36 -> V_68 ;
}
V_111 = V_36 -> V_46 ;
V_93 = F_52 ( V_4 , V_112 ) ;
if ( ! V_93 )
return - V_18 ;
V_70 = F_52 ( V_4 , V_111 ) ;
if ( ! V_70 ) {
F_70 ( V_93 ) ;
return - V_77 ;
}
while ( V_126 < V_127 ) {
if ( V_128 ) {
V_5 = F_94 ( V_21 , V_126 , & V_103 , & V_96 ,
& V_113 , & V_112 ) ;
if ( ! V_93 )
V_93 = F_52 ( V_4 , V_112 ) ;
if ( ! V_93 )
return - V_18 ;
} else {
V_5 = F_96 ( V_21 , V_126 , & V_103 , & V_96 ,
& V_113 ) ;
}
if ( V_5 )
return V_5 ;
if ( ! F_77 ( V_4 , V_33 , F_54 ( V_93 ) , F_54 ( V_70 ) ,
V_113 , V_96 , V_103 ) ) {
if ( ! V_114 ) {
V_5 = F_87 ( V_2 , V_4 , V_33 , log ,
V_93 , V_70 , V_21 ,
V_111 ,
V_112 ,
V_113 , V_96 , V_103 ,
& V_114 ) ;
if ( V_5 == 1 ) {
V_5 = 0 ;
goto V_76;
}
if ( V_5 )
goto V_76;
}
V_5 = F_99 ( V_2 , V_93 , V_70 , V_96 , V_103 ,
0 , V_113 ) ;
if ( V_5 )
goto V_76;
F_69 ( V_2 , V_4 , V_70 ) ;
}
V_126 = ( unsigned long ) ( V_126 + V_129 ) + V_103 ;
F_29 ( V_96 ) ;
if ( V_128 ) {
F_70 ( V_93 ) ;
V_93 = NULL ;
}
}
V_5 = F_23 ( V_2 , V_4 , V_33 , V_21 , V_34 , V_36 ) ;
V_76:
F_27 ( V_33 ) ;
F_70 ( V_93 ) ;
F_70 ( V_70 ) ;
return V_5 ;
}
static int F_100 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_1 V_68 )
{
int V_5 ;
V_5 = F_101 ( V_4 , V_68 ) ;
if ( V_5 > 0 )
V_5 = F_102 ( V_2 , V_4 , V_68 ) ;
return V_5 ;
}
static int F_103 ( struct V_3 * V_4 ,
struct V_70 * V_70 , struct V_32 * V_33 )
{
int V_5 = 0 ;
int V_97 ;
unsigned int V_131 = 0 ;
T_3 V_37 ;
T_3 V_123 = 0 ;
T_1 V_111 = F_54 ( V_70 ) ;
T_1 V_68 = 0 ;
unsigned long V_106 ;
struct V_118 * V_119 ;
struct V_20 * V_81 ;
while ( 1 ) {
V_5 = F_104 ( V_4 , V_111 , V_68 , V_33 ,
& V_119 , & V_68 ) ;
if ( V_5 )
break;
V_81 = V_33 -> V_51 [ 0 ] ;
V_37 = F_24 ( V_81 , V_33 -> V_52 [ 0 ] ) ;
V_106 = F_25 ( V_81 , V_33 -> V_52 [ 0 ] ) ;
while ( V_123 < V_37 ) {
V_119 = (struct V_118 * ) ( V_106 + V_123 ) ;
V_97 = F_91 ( V_81 , V_119 ) ;
V_131 ++ ;
V_123 += V_97 + sizeof( * V_119 ) ;
}
V_68 ++ ;
F_27 ( V_33 ) ;
}
F_27 ( V_33 ) ;
if ( V_5 < 0 )
return V_5 ;
return V_131 ;
}
static int F_105 ( struct V_3 * V_4 ,
struct V_70 * V_70 , struct V_32 * V_33 )
{
int V_5 ;
struct V_35 V_36 ;
unsigned int V_131 = 0 ;
unsigned long V_106 ;
unsigned long V_107 ;
int V_97 ;
T_1 V_132 = F_54 ( V_70 ) ;
V_36 . V_46 = V_132 ;
V_36 . type = V_121 ;
V_36 . V_68 = ( T_1 ) - 1 ;
while ( 1 ) {
V_5 = F_26 ( NULL , V_4 , & V_36 , V_33 , 0 , 0 ) ;
if ( V_5 < 0 )
break;
if ( V_5 > 0 ) {
if ( V_33 -> V_52 [ 0 ] == 0 )
break;
V_33 -> V_52 [ 0 ] -- ;
}
F_106 ( V_33 -> V_51 [ 0 ] , & V_36 ,
V_33 -> V_52 [ 0 ] ) ;
if ( V_36 . V_46 != V_132 ||
V_36 . type != V_121 )
break;
V_106 = F_25 ( V_33 -> V_51 [ 0 ] , V_33 -> V_52 [ 0 ] ) ;
V_107 = V_106 + F_24 ( V_33 -> V_51 [ 0 ] ,
V_33 -> V_52 [ 0 ] ) ;
while ( V_106 < V_107 ) {
struct V_104 * V_105 ;
V_105 = (struct V_104 * ) V_106 ;
V_97 = F_84 ( V_33 -> V_51 [ 0 ] ,
V_105 ) ;
V_106 = ( unsigned long ) ( V_105 + 1 ) + V_97 ;
V_131 ++ ;
}
if ( V_36 . V_68 == 0 )
break;
V_36 . V_68 -- ;
F_27 ( V_33 ) ;
}
F_27 ( V_33 ) ;
return V_131 ;
}
static T_2 int F_107 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_70 * V_70 )
{
struct V_32 * V_33 ;
int V_5 ;
T_1 V_131 = 0 ;
T_1 V_132 = F_54 ( V_70 ) ;
V_33 = F_82 () ;
if ( ! V_33 )
return - V_55 ;
V_5 = F_105 ( V_4 , V_70 , V_33 ) ;
if ( V_5 < 0 )
goto V_76;
V_131 = V_5 ;
V_5 = F_103 ( V_4 , V_70 , V_33 ) ;
if ( V_5 == - V_18 )
V_5 = 0 ;
if ( V_5 < 0 )
goto V_76;
V_131 += V_5 ;
V_5 = 0 ;
if ( V_131 != V_70 -> V_133 ) {
F_108 ( V_70 , V_131 ) ;
F_69 ( V_2 , V_4 , V_70 ) ;
}
F_109 ( V_70 ) -> V_134 = ( T_1 ) - 1 ;
if ( V_70 -> V_133 == 0 ) {
if ( F_35 ( V_70 -> V_135 ) ) {
V_5 = F_110 ( V_2 , V_4 , NULL , V_33 ,
V_132 , 1 ) ;
if ( V_5 )
goto V_76;
}
V_5 = F_100 ( V_2 , V_4 , V_132 ) ;
}
V_76:
F_86 ( V_33 ) ;
return V_5 ;
}
static T_2 int F_111 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_32 * V_33 )
{
int V_5 ;
struct V_35 V_36 ;
struct V_70 * V_70 ;
V_36 . V_46 = V_136 ;
V_36 . type = V_137 ;
V_36 . V_68 = ( T_1 ) - 1 ;
while ( 1 ) {
V_5 = F_26 ( V_2 , V_4 , & V_36 , V_33 , - 1 , 1 ) ;
if ( V_5 < 0 )
break;
if ( V_5 == 1 ) {
if ( V_33 -> V_52 [ 0 ] == 0 )
break;
V_33 -> V_52 [ 0 ] -- ;
}
F_106 ( V_33 -> V_51 [ 0 ] , & V_36 , V_33 -> V_52 [ 0 ] ) ;
if ( V_36 . V_46 != V_136 ||
V_36 . type != V_137 )
break;
V_5 = F_112 ( V_2 , V_4 , V_33 ) ;
if ( V_5 )
goto V_76;
F_27 ( V_33 ) ;
V_70 = F_52 ( V_4 , V_36 . V_68 ) ;
if ( ! V_70 )
return - V_77 ;
V_5 = F_107 ( V_2 , V_4 , V_70 ) ;
F_70 ( V_70 ) ;
if ( V_5 )
goto V_76;
V_36 . V_68 = ( T_1 ) - 1 ;
}
V_5 = 0 ;
V_76:
F_27 ( V_33 ) ;
return V_5 ;
}
static T_2 int F_74 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_32 * V_33 ,
T_1 V_46 )
{
struct V_35 V_36 ;
int V_5 = 0 ;
struct V_70 * V_70 ;
V_70 = F_52 ( V_4 , V_46 ) ;
if ( ! V_70 )
return - V_77 ;
V_36 . V_46 = V_136 ;
F_113 ( & V_36 , V_137 ) ;
V_36 . V_68 = V_46 ;
V_5 = F_37 ( V_2 , V_4 , V_33 , & V_36 , 0 ) ;
F_27 ( V_33 ) ;
if ( V_5 == 0 ) {
if ( ! V_70 -> V_133 )
F_108 ( V_70 , 1 ) ;
else
F_88 ( V_70 ) ;
V_5 = F_69 ( V_2 , V_4 , V_70 ) ;
} else if ( V_5 == - V_60 ) {
V_5 = 0 ;
} else {
F_114 () ;
}
F_70 ( V_70 ) ;
return V_5 ;
}
static T_2 int F_115 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_32 * V_33 ,
T_1 V_99 , T_1 V_100 ,
char * V_96 , int V_97 , T_4 type ,
struct V_35 * V_98 )
{
struct V_70 * V_70 ;
struct V_70 * V_93 ;
int V_5 ;
V_70 = F_52 ( V_4 , V_98 -> V_46 ) ;
if ( ! V_70 )
return - V_18 ;
V_93 = F_52 ( V_4 , V_99 ) ;
if ( ! V_93 ) {
F_70 ( V_70 ) ;
return - V_77 ;
}
V_5 = F_99 ( V_2 , V_93 , V_70 , V_96 , V_97 , 1 , V_100 ) ;
F_70 ( V_70 ) ;
F_70 ( V_93 ) ;
return V_5 ;
}
static T_2 int F_116 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_32 * V_33 ,
struct V_20 * V_21 ,
struct V_94 * V_95 ,
struct V_35 * V_36 )
{
char * V_96 ;
int V_97 ;
struct V_94 * V_138 ;
struct V_35 V_139 ;
struct V_35 V_140 ;
struct V_70 * V_93 ;
T_4 V_141 ;
int V_142 ;
int V_5 = 0 ;
bool V_143 = ( V_36 -> type == V_144 ) ;
V_93 = F_52 ( V_4 , V_36 -> V_46 ) ;
if ( ! V_93 )
return - V_77 ;
V_97 = F_73 ( V_21 , V_95 ) ;
V_96 = F_28 ( V_97 , V_54 ) ;
if ( ! V_96 ) {
V_5 = - V_55 ;
goto V_76;
}
V_141 = F_117 ( V_21 , V_95 ) ;
F_30 ( V_21 , V_96 , ( unsigned long ) ( V_95 + 1 ) ,
V_97 ) ;
F_72 ( V_21 , V_95 , & V_140 ) ;
V_142 = F_118 ( V_2 , V_4 , V_33 , & V_140 , 0 ) ;
if ( V_142 == 0 )
V_142 = 1 ;
else
V_142 = 0 ;
F_27 ( V_33 ) ;
if ( V_36 -> type == V_145 ) {
V_138 = F_80 ( V_2 , V_4 , V_33 , V_36 -> V_46 ,
V_96 , V_97 , 1 ) ;
} else if ( V_36 -> type == V_144 ) {
V_138 = F_78 ( V_2 , V_4 , V_33 ,
V_36 -> V_46 ,
V_36 -> V_68 , V_96 ,
V_97 , 1 ) ;
} else {
V_5 = - V_146 ;
goto V_76;
}
if ( F_90 ( V_138 ) ) {
if ( V_36 -> type != V_144 )
goto V_76;
goto V_53;
}
F_72 ( V_33 -> V_51 [ 0 ] , V_138 , & V_139 ) ;
if ( V_139 . V_46 == V_140 . V_46 &&
V_139 . type == V_140 . type &&
V_139 . V_68 == V_140 . V_68 &&
F_117 ( V_33 -> V_51 [ 0 ] , V_138 ) == V_141 ) {
goto V_76;
}
if ( ! V_142 )
goto V_76;
V_5 = F_71 ( V_2 , V_4 , V_33 , V_93 , V_138 ) ;
if ( V_5 )
goto V_76;
if ( V_36 -> type == V_144 )
goto V_53;
V_76:
F_27 ( V_33 ) ;
if ( ! V_5 && V_143 ) {
F_119 ( V_93 , V_93 -> V_147 + V_97 * 2 ) ;
V_5 = F_69 ( V_2 , V_4 , V_93 ) ;
}
F_29 ( V_96 ) ;
F_70 ( V_93 ) ;
return V_5 ;
V_53:
F_27 ( V_33 ) ;
V_5 = F_115 ( V_2 , V_4 , V_33 , V_36 -> V_46 , V_36 -> V_68 ,
V_96 , V_97 , V_141 , & V_140 ) ;
if ( V_5 && V_5 != - V_18 )
goto V_76;
V_143 = false ;
V_5 = 0 ;
goto V_76;
}
static T_2 int F_120 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_32 * V_33 ,
struct V_20 * V_21 , int V_34 ,
struct V_35 * V_36 )
{
int V_5 ;
T_3 V_37 = F_24 ( V_21 , V_34 ) ;
struct V_94 * V_95 ;
int V_97 ;
unsigned long V_106 ;
unsigned long V_107 ;
V_106 = F_25 ( V_21 , V_34 ) ;
V_107 = V_106 + V_37 ;
while ( V_106 < V_107 ) {
V_95 = (struct V_94 * ) V_106 ;
if ( F_121 ( V_4 , V_21 , V_95 ) )
return - V_77 ;
V_97 = F_73 ( V_21 , V_95 ) ;
V_5 = F_116 ( V_2 , V_4 , V_33 , V_21 , V_95 , V_36 ) ;
if ( V_5 )
return V_5 ;
V_106 = ( unsigned long ) ( V_95 + 1 ) ;
V_106 += V_97 ;
}
return 0 ;
}
static T_2 int F_122 ( struct V_3 * V_4 ,
struct V_32 * V_33 ,
T_1 V_99 , int V_148 ,
T_1 * V_149 , T_1 * V_150 )
{
struct V_35 V_36 ;
T_1 V_151 ;
struct V_152 * V_57 ;
int V_5 ;
int V_153 ;
if ( * V_149 == ( T_1 ) - 1 )
return 1 ;
V_36 . V_46 = V_99 ;
V_36 . type = V_148 ;
V_36 . V_68 = * V_149 ;
V_5 = F_26 ( NULL , V_4 , & V_36 , V_33 , 0 , 0 ) ;
if ( V_5 < 0 )
goto V_76;
if ( V_5 > 0 ) {
if ( V_33 -> V_52 [ 0 ] == 0 )
goto V_76;
V_33 -> V_52 [ 0 ] -- ;
}
if ( V_5 != 0 )
F_106 ( V_33 -> V_51 [ 0 ] , & V_36 , V_33 -> V_52 [ 0 ] ) ;
if ( V_36 . type != V_148 || V_36 . V_46 != V_99 ) {
V_5 = 1 ;
goto V_90;
}
V_57 = F_31 ( V_33 -> V_51 [ 0 ] , V_33 -> V_52 [ 0 ] ,
struct V_152 ) ;
V_151 = F_123 ( V_33 -> V_51 [ 0 ] , V_57 ) ;
if ( * V_149 >= V_36 . V_68 && * V_149 <= V_151 ) {
V_5 = 0 ;
* V_149 = V_36 . V_68 ;
* V_150 = V_151 ;
goto V_76;
}
V_5 = 1 ;
V_90:
V_153 = F_124 ( V_33 -> V_51 [ 0 ] ) ;
if ( V_33 -> V_52 [ 0 ] >= V_153 ) {
V_5 = F_125 ( V_4 , V_33 ) ;
if ( V_5 )
goto V_76;
} else {
V_33 -> V_52 [ 0 ] ++ ;
}
F_106 ( V_33 -> V_51 [ 0 ] , & V_36 , V_33 -> V_52 [ 0 ] ) ;
if ( V_36 . type != V_148 || V_36 . V_46 != V_99 ) {
V_5 = 1 ;
goto V_76;
}
V_57 = F_31 ( V_33 -> V_51 [ 0 ] , V_33 -> V_52 [ 0 ] ,
struct V_152 ) ;
V_151 = F_123 ( V_33 -> V_51 [ 0 ] , V_57 ) ;
* V_149 = V_36 . V_68 ;
* V_150 = V_151 ;
V_5 = 0 ;
V_76:
F_27 ( V_33 ) ;
return V_5 ;
}
static T_2 int F_126 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_3 * log ,
struct V_32 * V_33 ,
struct V_32 * V_154 ,
struct V_70 * V_93 ,
struct V_35 * V_155 )
{
int V_5 ;
struct V_20 * V_21 ;
int V_34 ;
T_3 V_37 ;
struct V_94 * V_95 ;
struct V_94 * V_156 ;
int V_97 ;
unsigned long V_106 ;
unsigned long V_107 ;
char * V_96 ;
struct V_70 * V_70 ;
struct V_35 V_98 ;
V_120:
V_21 = V_33 -> V_51 [ 0 ] ;
V_34 = V_33 -> V_52 [ 0 ] ;
V_37 = F_24 ( V_21 , V_34 ) ;
V_106 = F_25 ( V_21 , V_34 ) ;
V_107 = V_106 + V_37 ;
while ( V_106 < V_107 ) {
V_95 = (struct V_94 * ) V_106 ;
if ( F_121 ( V_4 , V_21 , V_95 ) ) {
V_5 = - V_77 ;
goto V_76;
}
V_97 = F_73 ( V_21 , V_95 ) ;
V_96 = F_28 ( V_97 , V_54 ) ;
if ( ! V_96 ) {
V_5 = - V_55 ;
goto V_76;
}
F_30 ( V_21 , V_96 , ( unsigned long ) ( V_95 + 1 ) ,
V_97 ) ;
V_156 = NULL ;
if ( log && V_155 -> type == V_145 ) {
V_156 = F_80 ( V_2 , log , V_154 ,
V_155 -> V_46 ,
V_96 , V_97 , 0 ) ;
} else if ( log && V_155 -> type == V_144 ) {
V_156 = F_78 ( V_2 , log ,
V_154 ,
V_155 -> V_46 ,
V_155 -> V_68 ,
V_96 , V_97 , 0 ) ;
}
if ( F_90 ( V_156 ) ) {
F_72 ( V_21 , V_95 , & V_98 ) ;
F_27 ( V_33 ) ;
F_27 ( V_154 ) ;
V_70 = F_52 ( V_4 , V_98 . V_46 ) ;
if ( ! V_70 ) {
F_29 ( V_96 ) ;
return - V_77 ;
}
V_5 = F_74 ( V_2 , V_4 ,
V_33 , V_98 . V_46 ) ;
if ( V_5 ) {
F_29 ( V_96 ) ;
F_70 ( V_70 ) ;
goto V_76;
}
F_88 ( V_70 ) ;
V_5 = F_75 ( V_2 , V_4 , V_93 , V_70 ,
V_96 , V_97 ) ;
if ( ! V_5 )
V_5 = F_76 ( V_2 , V_4 ) ;
F_29 ( V_96 ) ;
F_70 ( V_70 ) ;
if ( V_5 )
goto V_76;
V_5 = F_26 ( NULL , V_4 , V_155 , V_33 ,
0 , 0 ) ;
if ( V_5 == 0 )
goto V_120;
V_5 = 0 ;
goto V_76;
}
F_27 ( V_154 ) ;
F_29 ( V_96 ) ;
V_106 = ( unsigned long ) ( V_95 + 1 ) ;
V_106 += V_97 ;
}
V_5 = 0 ;
V_76:
F_27 ( V_33 ) ;
F_27 ( V_154 ) ;
return V_5 ;
}
static T_2 int F_110 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_3 * log ,
struct V_32 * V_33 ,
T_1 V_99 , int V_157 )
{
T_1 V_158 ;
T_1 V_159 ;
int V_148 = V_160 ;
int V_5 = 0 ;
struct V_35 V_155 ;
struct V_35 V_139 ;
struct V_32 * V_154 ;
struct V_70 * V_93 ;
V_155 . V_46 = V_99 ;
V_155 . type = V_145 ;
V_154 = F_82 () ;
if ( ! V_154 )
return - V_55 ;
V_93 = F_52 ( V_4 , V_99 ) ;
if ( ! V_93 ) {
F_86 ( V_154 ) ;
return 0 ;
}
V_120:
V_158 = 0 ;
V_159 = 0 ;
while ( 1 ) {
if ( V_157 )
V_159 = ( T_1 ) - 1 ;
else {
V_5 = F_122 ( log , V_33 , V_99 , V_148 ,
& V_158 , & V_159 ) ;
if ( V_5 != 0 )
break;
}
V_155 . V_68 = V_158 ;
while ( 1 ) {
int V_153 ;
V_5 = F_26 ( NULL , V_4 , & V_155 , V_33 ,
0 , 0 ) ;
if ( V_5 < 0 )
goto V_76;
V_153 = F_124 ( V_33 -> V_51 [ 0 ] ) ;
if ( V_33 -> V_52 [ 0 ] >= V_153 ) {
V_5 = F_125 ( V_4 , V_33 ) ;
if ( V_5 )
break;
}
F_106 ( V_33 -> V_51 [ 0 ] , & V_139 ,
V_33 -> V_52 [ 0 ] ) ;
if ( V_139 . V_46 != V_99 ||
V_139 . type != V_155 . type )
goto V_161;
if ( V_139 . V_68 > V_159 )
break;
V_5 = F_126 ( V_2 , V_4 , log , V_33 ,
V_154 , V_93 ,
& V_139 ) ;
if ( V_5 )
goto V_76;
if ( V_139 . V_68 == ( T_1 ) - 1 )
break;
V_155 . V_68 = V_139 . V_68 + 1 ;
}
F_27 ( V_33 ) ;
if ( V_159 == ( T_1 ) - 1 )
break;
V_158 = V_159 + 1 ;
}
V_161:
V_5 = 0 ;
if ( V_148 == V_160 ) {
V_148 = V_162 ;
V_155 . type = V_144 ;
F_27 ( V_33 ) ;
goto V_120;
}
V_76:
F_27 ( V_33 ) ;
F_86 ( V_154 ) ;
F_70 ( V_93 ) ;
return V_5 ;
}
static int F_127 ( struct V_3 * log , struct V_20 * V_21 ,
struct V_22 * V_23 , T_1 V_24 )
{
int V_153 ;
struct V_32 * V_33 ;
struct V_3 * V_4 = V_23 -> V_163 ;
struct V_35 V_36 ;
int V_164 ;
int V_165 ;
int V_5 ;
V_5 = F_16 ( V_21 , V_24 ) ;
if ( V_5 )
return V_5 ;
V_164 = F_19 ( V_21 ) ;
if ( V_164 != 0 )
return 0 ;
V_33 = F_82 () ;
if ( ! V_33 )
return - V_55 ;
V_153 = F_124 ( V_21 ) ;
for ( V_165 = 0 ; V_165 < V_153 ; V_165 ++ ) {
F_106 ( V_21 , & V_36 , V_165 ) ;
if ( V_36 . type == V_44 &&
V_23 -> V_166 == V_167 ) {
struct V_56 * V_43 ;
T_3 V_59 ;
V_43 = F_31 ( V_21 , V_165 ,
struct V_56 ) ;
V_59 = F_34 ( V_21 , V_43 ) ;
if ( F_35 ( V_59 ) ) {
V_5 = F_110 ( V_23 -> V_2 ,
V_4 , log , V_33 , V_36 . V_46 , 0 ) ;
if ( V_5 )
break;
}
V_5 = F_23 ( V_23 -> V_2 , V_4 , V_33 ,
V_21 , V_165 , & V_36 ) ;
if ( V_5 )
break;
if ( F_128 ( V_59 ) ) {
V_5 = F_100 ( V_23 -> V_2 , V_4 ,
V_36 . V_46 ) ;
if ( V_5 )
break;
}
V_5 = F_74 ( V_23 -> V_2 , V_4 ,
V_33 , V_36 . V_46 ) ;
if ( V_5 )
break;
}
if ( V_36 . type == V_144 &&
V_23 -> V_166 == V_168 ) {
V_5 = F_120 ( V_23 -> V_2 , V_4 , V_33 ,
V_21 , V_165 , & V_36 ) ;
if ( V_5 )
break;
}
if ( V_23 -> V_166 < V_169 )
continue;
if ( V_36 . type == V_170 ) {
V_5 = F_23 ( V_23 -> V_2 , V_4 , V_33 ,
V_21 , V_165 , & V_36 ) ;
if ( V_5 )
break;
} else if ( V_36 . type == V_121 ||
V_36 . type == V_110 ) {
V_5 = F_98 ( V_23 -> V_2 , V_4 , log , V_33 ,
V_21 , V_165 , & V_36 ) ;
if ( V_5 && V_5 != - V_18 )
break;
V_5 = 0 ;
} else if ( V_36 . type == V_171 ) {
V_5 = F_45 ( V_23 -> V_2 , V_4 , V_33 ,
V_21 , V_165 , & V_36 ) ;
if ( V_5 )
break;
} else if ( V_36 . type == V_145 ) {
V_5 = F_120 ( V_23 -> V_2 , V_4 , V_33 ,
V_21 , V_165 , & V_36 ) ;
if ( V_5 )
break;
}
}
F_86 ( V_33 ) ;
return V_5 ;
}
static T_2 int F_129 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_32 * V_33 , int * V_164 ,
struct V_22 * V_23 )
{
T_1 V_172 ;
T_1 V_173 ;
T_1 V_174 ;
struct V_20 * V_90 ;
struct V_20 * V_175 ;
struct V_20 * V_176 ;
T_3 V_177 ;
int V_5 = 0 ;
F_130 ( * V_164 < 0 ) ;
F_130 ( * V_164 >= V_178 ) ;
while ( * V_164 > 0 ) {
F_130 ( * V_164 < 0 ) ;
F_130 ( * V_164 >= V_178 ) ;
V_175 = V_33 -> V_51 [ * V_164 ] ;
if ( F_19 ( V_175 ) != * V_164 )
F_130 ( 1 ) ;
if ( V_33 -> V_52 [ * V_164 ] >=
F_124 ( V_175 ) )
break;
V_173 = F_131 ( V_175 , V_33 -> V_52 [ * V_164 ] ) ;
V_174 = F_132 ( V_175 , V_33 -> V_52 [ * V_164 ] ) ;
V_177 = F_133 ( V_4 , * V_164 - 1 ) ;
V_176 = V_33 -> V_51 [ * V_164 ] ;
V_172 = F_134 ( V_176 ) ;
V_90 = F_135 ( V_4 , V_173 , V_177 ) ;
if ( ! V_90 )
return - V_55 ;
if ( * V_164 == 1 ) {
V_5 = V_23 -> V_179 ( V_4 , V_90 , V_23 , V_174 ) ;
if ( V_5 ) {
F_136 ( V_90 ) ;
return V_5 ;
}
V_33 -> V_52 [ * V_164 ] ++ ;
if ( V_23 -> free ) {
V_5 = F_16 ( V_90 , V_174 ) ;
if ( V_5 ) {
F_136 ( V_90 ) ;
return V_5 ;
}
F_137 ( V_90 ) ;
F_138 ( V_90 ) ;
F_139 ( V_2 , V_4 , V_90 ) ;
F_22 ( V_90 ) ;
F_140 ( V_90 ) ;
F_130 ( V_172 !=
V_47 ) ;
V_5 = F_141 ( V_4 ,
V_173 , V_177 ) ;
if ( V_5 ) {
F_136 ( V_90 ) ;
return V_5 ;
}
}
F_136 ( V_90 ) ;
continue;
}
V_5 = F_16 ( V_90 , V_174 ) ;
if ( V_5 ) {
F_136 ( V_90 ) ;
return V_5 ;
}
F_130 ( * V_164 <= 0 ) ;
if ( V_33 -> V_51 [ * V_164 - 1 ] )
F_136 ( V_33 -> V_51 [ * V_164 - 1 ] ) ;
V_33 -> V_51 [ * V_164 - 1 ] = V_90 ;
* V_164 = F_19 ( V_90 ) ;
V_33 -> V_52 [ * V_164 ] = 0 ;
F_142 () ;
}
F_130 ( * V_164 < 0 ) ;
F_130 ( * V_164 >= V_178 ) ;
V_33 -> V_52 [ * V_164 ] = F_124 ( V_33 -> V_51 [ * V_164 ] ) ;
F_142 () ;
return 0 ;
}
static T_2 int F_143 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_32 * V_33 , int * V_164 ,
struct V_22 * V_23 )
{
T_1 V_172 ;
int V_165 ;
int V_34 ;
int V_5 ;
for ( V_165 = * V_164 ; V_165 < V_178 - 1 && V_33 -> V_51 [ V_165 ] ; V_165 ++ ) {
V_34 = V_33 -> V_52 [ V_165 ] ;
if ( V_34 + 1 < F_124 ( V_33 -> V_51 [ V_165 ] ) ) {
V_33 -> V_52 [ V_165 ] ++ ;
* V_164 = V_165 ;
F_130 ( * V_164 == 0 ) ;
return 0 ;
} else {
struct V_20 * V_176 ;
if ( V_33 -> V_51 [ * V_164 ] == V_4 -> V_180 )
V_176 = V_33 -> V_51 [ * V_164 ] ;
else
V_176 = V_33 -> V_51 [ * V_164 + 1 ] ;
V_172 = F_134 ( V_176 ) ;
V_5 = V_23 -> V_179 ( V_4 , V_33 -> V_51 [ * V_164 ] , V_23 ,
F_144 ( V_33 -> V_51 [ * V_164 ] ) ) ;
if ( V_5 )
return V_5 ;
if ( V_23 -> free ) {
struct V_20 * V_90 ;
V_90 = V_33 -> V_51 [ * V_164 ] ;
F_137 ( V_90 ) ;
F_138 ( V_90 ) ;
F_139 ( V_2 , V_4 , V_90 ) ;
F_22 ( V_90 ) ;
F_140 ( V_90 ) ;
F_130 ( V_172 != V_47 ) ;
V_5 = F_141 ( V_4 ,
V_33 -> V_51 [ * V_164 ] -> V_28 ,
V_33 -> V_51 [ * V_164 ] -> V_29 ) ;
if ( V_5 )
return V_5 ;
}
F_136 ( V_33 -> V_51 [ * V_164 ] ) ;
V_33 -> V_51 [ * V_164 ] = NULL ;
* V_164 = V_165 + 1 ;
}
}
return 1 ;
}
static int F_145 ( struct V_1 * V_2 ,
struct V_3 * log , struct V_22 * V_23 )
{
int V_5 = 0 ;
int V_181 ;
int V_164 ;
struct V_32 * V_33 ;
int V_182 ;
V_33 = F_82 () ;
if ( ! V_33 )
return - V_55 ;
V_164 = F_19 ( log -> V_180 ) ;
V_182 = V_164 ;
V_33 -> V_51 [ V_164 ] = log -> V_180 ;
F_146 ( log -> V_180 ) ;
V_33 -> V_52 [ V_164 ] = 0 ;
while ( 1 ) {
V_181 = F_129 ( V_2 , log , V_33 , & V_164 , V_23 ) ;
if ( V_181 > 0 )
break;
if ( V_181 < 0 ) {
V_5 = V_181 ;
goto V_76;
}
V_181 = F_143 ( V_2 , log , V_33 , & V_164 , V_23 ) ;
if ( V_181 > 0 )
break;
if ( V_181 < 0 ) {
V_5 = V_181 ;
goto V_76;
}
}
if ( V_33 -> V_51 [ V_182 ] ) {
V_5 = V_23 -> V_179 ( log , V_33 -> V_51 [ V_182 ] , V_23 ,
F_144 ( V_33 -> V_51 [ V_182 ] ) ) ;
if ( V_5 )
goto V_76;
if ( V_23 -> free ) {
struct V_20 * V_90 ;
V_90 = V_33 -> V_51 [ V_182 ] ;
F_137 ( V_90 ) ;
F_138 ( V_90 ) ;
F_139 ( V_2 , log , V_90 ) ;
F_22 ( V_90 ) ;
F_140 ( V_90 ) ;
F_130 ( log -> V_45 . V_46 !=
V_47 ) ;
V_5 = F_141 ( log , V_90 -> V_28 ,
V_90 -> V_29 ) ;
if ( V_5 )
goto V_76;
}
}
V_76:
F_86 ( V_33 ) ;
return V_5 ;
}
static int F_147 ( struct V_1 * V_2 ,
struct V_3 * log )
{
int V_5 ;
if ( log -> V_183 == 1 ) {
V_5 = F_148 ( V_2 , log -> V_15 -> V_17 ,
& log -> V_45 , & log -> V_184 ) ;
} else {
V_5 = F_149 ( V_2 , log -> V_15 -> V_17 ,
& log -> V_45 , & log -> V_184 ) ;
}
return V_5 ;
}
static int F_150 ( struct V_1 * V_2 ,
struct V_3 * V_4 , unsigned long V_65 )
{
F_151 ( V_31 ) ;
int V_100 = V_65 % 2 ;
do {
F_152 ( & V_4 -> V_185 [ V_100 ] ,
& V_31 , V_186 ) ;
F_4 ( & V_4 -> V_7 ) ;
if ( V_4 -> V_15 -> V_187 !=
V_2 -> V_65 && V_4 -> V_183 < V_65 + 2 &&
F_153 ( & V_4 -> V_188 [ V_100 ] ) )
F_154 () ;
F_155 ( & V_4 -> V_185 [ V_100 ] , & V_31 ) ;
F_2 ( & V_4 -> V_7 ) ;
} while ( V_4 -> V_15 -> V_187 !=
V_2 -> V_65 && V_4 -> V_183 < V_65 + 2 &&
F_153 ( & V_4 -> V_188 [ V_100 ] ) );
return 0 ;
}
static void F_156 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_151 ( V_31 ) ;
while ( V_4 -> V_15 -> V_187 !=
V_2 -> V_65 && F_153 ( & V_4 -> V_14 ) ) {
F_152 ( & V_4 -> V_19 ,
& V_31 , V_186 ) ;
F_4 ( & V_4 -> V_7 ) ;
if ( V_4 -> V_15 -> V_187 !=
V_2 -> V_65 && F_153 ( & V_4 -> V_14 ) )
F_154 () ;
F_2 ( & V_4 -> V_7 ) ;
F_155 ( & V_4 -> V_19 , & V_31 ) ;
}
}
int F_157 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_189 ;
int V_190 ;
int V_191 ;
int V_5 ;
struct V_3 * log = V_4 -> V_8 ;
struct V_3 * V_17 = V_4 -> V_15 -> V_17 ;
unsigned long V_183 = 0 ;
struct V_192 V_193 ;
F_2 ( & V_4 -> V_7 ) ;
V_183 = V_4 -> V_183 ;
V_189 = V_4 -> V_183 % 2 ;
if ( F_153 ( & V_4 -> V_188 [ V_189 ] ) ) {
F_150 ( V_2 , V_4 , V_4 -> V_183 ) ;
F_4 ( & V_4 -> V_7 ) ;
return 0 ;
}
F_158 ( & V_4 -> V_188 [ V_189 ] , 1 ) ;
if ( F_153 ( & V_4 -> V_188 [ ( V_189 + 1 ) % 2 ] ) )
F_150 ( V_2 , V_4 , V_4 -> V_183 - 1 ) ;
while ( 1 ) {
int V_194 = F_153 ( & V_4 -> V_13 ) ;
if ( ! F_159 ( V_4 , V_195 ) && V_4 -> V_12 ) {
F_4 ( & V_4 -> V_7 ) ;
F_160 ( 1 ) ;
F_2 ( & V_4 -> V_7 ) ;
}
F_156 ( V_2 , V_4 ) ;
if ( V_194 == F_153 ( & V_4 -> V_13 ) )
break;
}
if ( V_4 -> V_15 -> V_187 == V_2 -> V_65 ) {
V_5 = - V_196 ;
F_161 ( log , V_183 ) ;
F_4 ( & V_4 -> V_7 ) ;
goto V_76;
}
if ( V_183 % 2 == 0 )
V_191 = V_197 ;
else
V_191 = V_198 ;
F_162 ( & V_193 ) ;
V_5 = F_163 ( log , & log -> V_199 , V_191 ) ;
if ( V_5 ) {
F_164 ( & V_193 ) ;
F_165 ( V_2 , V_4 , V_5 ) ;
F_161 ( log , V_183 ) ;
F_4 ( & V_4 -> V_7 ) ;
goto V_76;
}
F_166 ( & log -> V_184 , log -> V_180 ) ;
V_4 -> V_183 ++ ;
log -> V_183 = V_4 -> V_183 ;
V_4 -> V_9 = 0 ;
F_8 () ;
F_4 ( & V_4 -> V_7 ) ;
F_2 ( & V_17 -> V_7 ) ;
F_3 ( & V_17 -> V_13 ) ;
F_3 ( & V_17 -> V_14 ) ;
F_4 ( & V_17 -> V_7 ) ;
V_5 = F_147 ( V_2 , log ) ;
F_2 ( & V_17 -> V_7 ) ;
if ( F_11 ( & V_17 -> V_14 ) ) {
F_8 () ;
if ( F_12 ( & V_17 -> V_19 ) )
F_13 ( & V_17 -> V_19 ) ;
}
if ( V_5 ) {
F_164 ( & V_193 ) ;
if ( V_5 != - V_200 ) {
F_165 ( V_2 , V_4 , V_5 ) ;
F_4 ( & V_17 -> V_7 ) ;
goto V_76;
}
V_4 -> V_15 -> V_187 = V_2 -> V_65 ;
F_167 ( log , & log -> V_199 , V_191 ) ;
F_161 ( log , V_183 ) ;
F_4 ( & V_17 -> V_7 ) ;
V_5 = - V_196 ;
goto V_76;
}
V_190 = V_17 -> V_183 % 2 ;
if ( F_153 ( & V_17 -> V_188 [ V_190 ] ) ) {
F_164 ( & V_193 ) ;
F_167 ( log , & log -> V_199 , V_191 ) ;
F_150 ( V_2 , V_17 ,
V_17 -> V_183 ) ;
F_161 ( log , V_183 ) ;
F_4 ( & V_17 -> V_7 ) ;
V_5 = 0 ;
goto V_76;
}
F_158 ( & V_17 -> V_188 [ V_190 ] , 1 ) ;
if ( F_153 ( & V_17 -> V_188 [ ( V_190 + 1 ) % 2 ] ) ) {
F_150 ( V_2 , V_17 ,
V_17 -> V_183 - 1 ) ;
}
F_156 ( V_2 , V_17 ) ;
if ( V_4 -> V_15 -> V_187 == V_2 -> V_65 ) {
F_164 ( & V_193 ) ;
F_167 ( log , & log -> V_199 , V_191 ) ;
F_161 ( log , V_183 ) ;
F_4 ( & V_17 -> V_7 ) ;
V_5 = - V_196 ;
goto V_201;
}
V_5 = F_163 ( V_17 ,
& V_17 -> V_199 ,
V_197 | V_198 ) ;
F_164 ( & V_193 ) ;
if ( V_5 ) {
F_165 ( V_2 , V_4 , V_5 ) ;
F_161 ( log , V_183 ) ;
F_4 ( & V_17 -> V_7 ) ;
goto V_201;
}
F_167 ( log , & log -> V_199 , V_191 ) ;
F_167 ( V_17 ,
& V_17 -> V_199 ,
V_198 | V_197 ) ;
F_168 ( log , V_183 ) ;
F_169 ( V_4 -> V_15 -> V_202 ,
V_17 -> V_180 -> V_28 ) ;
F_170 ( V_4 -> V_15 -> V_202 ,
F_19 ( V_17 -> V_180 ) ) ;
V_17 -> V_183 ++ ;
F_8 () ;
F_4 ( & V_17 -> V_7 ) ;
F_171 ( V_4 ) ;
V_5 = F_172 ( V_2 , V_4 -> V_15 -> V_203 , 1 ) ;
F_173 ( V_4 ) ;
if ( V_5 ) {
F_165 ( V_2 , V_4 , V_5 ) ;
goto V_201;
}
F_2 ( & V_4 -> V_7 ) ;
if ( V_4 -> V_204 < V_183 )
V_4 -> V_204 = V_183 ;
F_4 ( & V_4 -> V_7 ) ;
V_201:
F_158 ( & V_17 -> V_188 [ V_190 ] , 0 ) ;
F_8 () ;
if ( F_12 ( & V_17 -> V_185 [ V_190 ] ) )
F_13 ( & V_17 -> V_185 [ V_190 ] ) ;
V_76:
F_158 ( & V_4 -> V_188 [ V_189 ] , 0 ) ;
F_8 () ;
if ( F_12 ( & V_4 -> V_185 [ V_189 ] ) )
F_13 ( & V_4 -> V_185 [ V_189 ] ) ;
return V_5 ;
}
static void F_174 ( struct V_1 * V_2 ,
struct V_3 * log )
{
int V_5 ;
T_1 V_28 ;
T_1 V_205 ;
struct V_22 V_23 = {
. free = 1 ,
. V_179 = F_14
} ;
if ( V_2 ) {
V_5 = F_145 ( V_2 , log , & V_23 ) ;
if ( V_5 )
F_165 ( V_2 , log , V_5 ) ;
}
while ( 1 ) {
V_5 = F_175 ( & log -> V_199 ,
0 , & V_28 , & V_205 , V_197 | V_198 ,
NULL ) ;
if ( V_5 )
break;
F_176 ( & log -> V_199 , V_28 , V_205 ,
V_197 | V_198 , V_54 ) ;
}
F_161 ( log , 0 ) ;
F_161 ( log , 1 ) ;
F_136 ( log -> V_180 ) ;
F_29 ( log ) ;
}
int F_177 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( V_4 -> V_8 ) {
F_174 ( V_2 , V_4 -> V_8 ) ;
V_4 -> V_8 = NULL ;
}
return 0 ;
}
int F_178 ( struct V_1 * V_2 ,
struct V_206 * V_15 )
{
if ( V_15 -> V_17 ) {
F_174 ( V_2 , V_15 -> V_17 ) ;
V_15 -> V_17 = NULL ;
}
return 0 ;
}
int F_179 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_96 , int V_97 ,
struct V_70 * V_93 , T_1 V_100 )
{
struct V_3 * log ;
struct V_94 * V_95 ;
struct V_32 * V_33 ;
int V_5 ;
int V_6 = 0 ;
int V_207 = 0 ;
T_1 V_208 = F_54 ( V_93 ) ;
if ( F_109 ( V_93 ) -> V_209 < V_2 -> V_65 )
return 0 ;
V_5 = F_7 ( V_4 ) ;
if ( V_5 )
return 0 ;
F_2 ( & F_109 ( V_93 ) -> V_7 ) ;
log = V_4 -> V_8 ;
V_33 = F_82 () ;
if ( ! V_33 ) {
V_6 = - V_55 ;
goto V_210;
}
V_95 = F_80 ( V_2 , log , V_33 , V_208 ,
V_96 , V_97 , - 1 ) ;
if ( F_79 ( V_95 ) ) {
V_6 = F_180 ( V_95 ) ;
goto V_211;
}
if ( V_95 ) {
V_5 = F_181 ( V_2 , log , V_33 , V_95 ) ;
V_207 += V_97 ;
if ( V_5 ) {
V_6 = V_5 ;
goto V_211;
}
}
F_27 ( V_33 ) ;
V_95 = F_78 ( V_2 , log , V_33 , V_208 ,
V_100 , V_96 , V_97 , - 1 ) ;
if ( F_79 ( V_95 ) ) {
V_6 = F_180 ( V_95 ) ;
goto V_211;
}
if ( V_95 ) {
V_5 = F_181 ( V_2 , log , V_33 , V_95 ) ;
V_207 += V_97 ;
if ( V_5 ) {
V_6 = V_5 ;
goto V_211;
}
}
if ( V_207 ) {
struct V_35 V_36 ;
V_36 . V_46 = V_208 ;
V_36 . V_68 = 0 ;
V_36 . type = V_44 ;
F_27 ( V_33 ) ;
V_5 = F_26 ( V_2 , log , & V_36 , V_33 , 0 , 1 ) ;
if ( V_5 < 0 ) {
V_6 = V_5 ;
goto V_211;
}
if ( V_5 == 0 ) {
struct V_56 * V_57 ;
T_1 V_147 ;
V_57 = F_31 ( V_33 -> V_51 [ 0 ] , V_33 -> V_52 [ 0 ] ,
struct V_56 ) ;
V_147 = F_41 ( V_33 -> V_51 [ 0 ] , V_57 ) ;
if ( V_147 > V_207 )
V_147 -= V_207 ;
else
V_147 = 0 ;
F_36 ( V_33 -> V_51 [ 0 ] , V_57 , V_147 ) ;
F_44 ( V_33 -> V_51 [ 0 ] ) ;
} else
V_5 = 0 ;
F_27 ( V_33 ) ;
}
V_211:
F_86 ( V_33 ) ;
V_210:
F_4 ( & F_109 ( V_93 ) -> V_7 ) ;
if ( V_5 == - V_200 ) {
V_4 -> V_15 -> V_187 = V_2 -> V_65 ;
V_5 = 0 ;
} else if ( V_5 < 0 )
F_165 ( V_2 , V_4 , V_5 ) ;
F_10 ( V_4 ) ;
return V_6 ;
}
int F_182 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_96 , int V_97 ,
struct V_70 * V_70 , T_1 V_99 )
{
struct V_3 * log ;
T_1 V_100 ;
int V_5 ;
if ( F_109 ( V_70 ) -> V_209 < V_2 -> V_65 )
return 0 ;
V_5 = F_7 ( V_4 ) ;
if ( V_5 )
return 0 ;
log = V_4 -> V_8 ;
F_2 ( & F_109 ( V_70 ) -> V_7 ) ;
V_5 = F_183 ( V_2 , log , V_96 , V_97 , F_54 ( V_70 ) ,
V_99 , & V_100 ) ;
F_4 ( & F_109 ( V_70 ) -> V_7 ) ;
if ( V_5 == - V_200 ) {
V_4 -> V_15 -> V_187 = V_2 -> V_65 ;
V_5 = 0 ;
} else if ( V_5 < 0 && V_5 != - V_18 )
F_165 ( V_2 , V_4 , V_5 ) ;
F_10 ( V_4 ) ;
return V_5 ;
}
static T_2 int F_184 ( struct V_1 * V_2 ,
struct V_3 * log ,
struct V_32 * V_33 ,
int V_148 , T_1 V_99 ,
T_1 V_212 , T_1 V_213 )
{
int V_5 ;
struct V_35 V_36 ;
struct V_152 * V_57 ;
V_36 . V_46 = V_99 ;
V_36 . V_68 = V_212 ;
if ( V_148 == V_145 )
V_36 . type = V_160 ;
else
V_36 . type = V_162 ;
V_5 = F_37 ( V_2 , log , V_33 , & V_36 , sizeof( * V_57 ) ) ;
if ( V_5 )
return V_5 ;
V_57 = F_31 ( V_33 -> V_51 [ 0 ] , V_33 -> V_52 [ 0 ] ,
struct V_152 ) ;
F_185 ( V_33 -> V_51 [ 0 ] , V_57 , V_213 ) ;
F_44 ( V_33 -> V_51 [ 0 ] ) ;
F_27 ( V_33 ) ;
return 0 ;
}
static T_2 int F_186 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_70 * V_70 ,
struct V_32 * V_33 ,
struct V_32 * V_214 , int V_148 ,
T_1 V_215 , T_1 * V_216 )
{
struct V_35 V_217 ;
struct V_35 V_218 ;
struct V_3 * log = V_4 -> V_8 ;
struct V_20 * V_219 ;
int V_6 = 0 ;
int V_5 ;
int V_165 ;
int V_153 ;
T_1 V_212 = V_215 ;
T_1 V_213 = ( T_1 ) - 1 ;
T_1 V_132 = F_54 ( V_70 ) ;
log = V_4 -> V_8 ;
V_218 . V_46 = V_132 ;
V_218 . V_68 = ( T_1 ) - 1 ;
V_218 . type = V_148 ;
V_217 . V_46 = V_132 ;
V_217 . type = V_148 ;
V_217 . V_68 = V_215 ;
V_33 -> V_220 = 1 ;
V_5 = F_187 ( V_4 , & V_217 , & V_218 ,
V_33 , V_2 -> V_65 ) ;
if ( V_5 != 0 || V_217 . V_46 != V_132 || V_217 . type != V_148 ) {
V_217 . V_46 = V_132 ;
V_217 . type = V_148 ;
V_217 . V_68 = ( T_1 ) - 1 ;
F_27 ( V_33 ) ;
V_5 = F_26 ( NULL , V_4 , & V_217 , V_33 , 0 , 0 ) ;
if ( V_5 < 0 ) {
F_27 ( V_33 ) ;
return V_5 ;
}
V_5 = F_188 ( V_4 , V_33 , V_132 , V_148 ) ;
if ( V_5 == 0 ) {
struct V_35 V_221 ;
F_106 ( V_33 -> V_51 [ 0 ] , & V_221 ,
V_33 -> V_52 [ 0 ] ) ;
if ( V_148 == V_221 . type )
V_212 = F_189 ( V_215 , V_221 . V_68 ) + 1 ;
}
goto V_222;
}
V_5 = F_188 ( V_4 , V_33 , V_132 , V_148 ) ;
if ( V_5 == 0 ) {
struct V_35 V_221 ;
F_106 ( V_33 -> V_51 [ 0 ] , & V_221 , V_33 -> V_52 [ 0 ] ) ;
if ( V_148 == V_221 . type ) {
V_212 = V_221 . V_68 ;
V_5 = F_23 ( V_2 , log , V_214 ,
V_33 -> V_51 [ 0 ] , V_33 -> V_52 [ 0 ] ,
& V_221 ) ;
if ( V_5 ) {
V_6 = V_5 ;
goto V_222;
}
}
}
F_27 ( V_33 ) ;
V_5 = F_26 ( NULL , V_4 , & V_217 , V_33 , 0 , 0 ) ;
if ( V_5 != 0 ) {
F_130 ( 1 ) ;
goto V_222;
}
while ( 1 ) {
struct V_35 V_221 ;
V_219 = V_33 -> V_51 [ 0 ] ;
V_153 = F_124 ( V_219 ) ;
for ( V_165 = V_33 -> V_52 [ 0 ] ; V_165 < V_153 ; V_165 ++ ) {
F_106 ( V_219 , & V_217 , V_165 ) ;
if ( V_217 . V_46 != V_132 || V_217 . type != V_148 )
goto V_222;
V_5 = F_23 ( V_2 , log , V_214 , V_219 , V_165 ,
& V_217 ) ;
if ( V_5 ) {
V_6 = V_5 ;
goto V_222;
}
}
V_33 -> V_52 [ 0 ] = V_153 ;
V_5 = F_125 ( V_4 , V_33 ) ;
if ( V_5 == 1 ) {
V_213 = ( T_1 ) - 1 ;
goto V_222;
}
F_106 ( V_33 -> V_51 [ 0 ] , & V_221 , V_33 -> V_52 [ 0 ] ) ;
if ( V_221 . V_46 != V_132 || V_221 . type != V_148 ) {
V_213 = ( T_1 ) - 1 ;
goto V_222;
}
if ( F_144 ( V_33 -> V_51 [ 0 ] ) != V_2 -> V_65 ) {
V_5 = F_23 ( V_2 , log , V_214 ,
V_33 -> V_51 [ 0 ] , V_33 -> V_52 [ 0 ] ,
& V_221 ) ;
if ( V_5 )
V_6 = V_5 ;
else
V_213 = V_221 . V_68 ;
goto V_222;
}
}
V_222:
F_27 ( V_33 ) ;
F_27 ( V_214 ) ;
if ( V_6 == 0 ) {
* V_216 = V_213 ;
V_5 = F_184 ( V_2 , log , V_33 , V_148 ,
V_132 , V_212 , V_213 ) ;
if ( V_5 )
V_6 = V_5 ;
}
return V_6 ;
}
static T_2 int F_190 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_70 * V_70 ,
struct V_32 * V_33 ,
struct V_32 * V_214 )
{
T_1 V_217 ;
T_1 V_218 ;
int V_5 ;
int V_148 = V_145 ;
V_120:
V_217 = 0 ;
V_218 = 0 ;
while ( 1 ) {
V_5 = F_186 ( V_2 , V_4 , V_70 , V_33 ,
V_214 , V_148 , V_217 ,
& V_218 ) ;
if ( V_5 )
return V_5 ;
if ( V_218 == ( T_1 ) - 1 )
break;
V_217 = V_218 + 1 ;
}
if ( V_148 == V_145 ) {
V_148 = V_144 ;
goto V_120;
}
return 0 ;
}
static int F_191 ( struct V_1 * V_2 ,
struct V_3 * log ,
struct V_32 * V_33 ,
T_1 V_46 , int V_223 )
{
int V_5 ;
struct V_35 V_36 ;
struct V_35 V_139 ;
int V_224 ;
V_36 . V_46 = V_46 ;
V_36 . type = V_223 ;
V_36 . V_68 = ( T_1 ) - 1 ;
while ( 1 ) {
V_5 = F_26 ( V_2 , log , & V_36 , V_33 , - 1 , 1 ) ;
F_192 ( V_5 == 0 ) ;
if ( V_5 < 0 )
break;
if ( V_33 -> V_52 [ 0 ] == 0 )
break;
V_33 -> V_52 [ 0 ] -- ;
F_106 ( V_33 -> V_51 [ 0 ] , & V_139 ,
V_33 -> V_52 [ 0 ] ) ;
if ( V_139 . V_46 != V_46 )
break;
V_139 . V_68 = 0 ;
V_139 . type = 0 ;
V_5 = F_193 ( V_33 -> V_51 [ 0 ] , & V_139 , 0 ,
& V_224 ) ;
V_5 = F_194 ( V_2 , log , V_33 , V_224 ,
V_33 -> V_52 [ 0 ] - V_224 + 1 ) ;
if ( V_5 || V_224 != 0 )
break;
F_27 ( V_33 ) ;
}
F_27 ( V_33 ) ;
if ( V_5 > 0 )
V_5 = 0 ;
return V_5 ;
}
static void F_195 ( struct V_1 * V_2 ,
struct V_20 * V_81 ,
struct V_56 * V_57 ,
struct V_70 * V_70 , int V_225 )
{
struct V_226 V_227 ;
F_196 ( & V_227 ) ;
if ( V_225 ) {
F_197 ( V_81 , V_57 , 0 , & V_227 ) ;
F_198 ( V_81 , V_57 , 0 , & V_227 ) ;
} else {
F_197 ( V_81 , V_57 ,
F_109 ( V_70 ) -> V_228 ,
& V_227 ) ;
F_198 ( V_81 , V_57 , V_70 -> V_147 , & V_227 ) ;
}
F_199 ( V_81 , V_57 , F_200 ( V_70 ) , & V_227 ) ;
F_201 ( V_81 , V_57 , F_202 ( V_70 ) , & V_227 ) ;
F_203 ( V_81 , V_57 , V_70 -> V_135 , & V_227 ) ;
F_204 ( V_81 , V_57 , V_70 -> V_133 , & V_227 ) ;
F_205 ( V_81 , F_206 ( V_57 ) ,
V_70 -> V_229 . V_230 , & V_227 ) ;
F_207 ( V_81 , F_206 ( V_57 ) ,
V_70 -> V_229 . V_231 , & V_227 ) ;
F_205 ( V_81 , F_208 ( V_57 ) ,
V_70 -> V_232 . V_230 , & V_227 ) ;
F_207 ( V_81 , F_208 ( V_57 ) ,
V_70 -> V_232 . V_231 , & V_227 ) ;
F_205 ( V_81 , F_209 ( V_57 ) ,
V_70 -> V_233 . V_230 , & V_227 ) ;
F_207 ( V_81 , F_209 ( V_57 ) ,
V_70 -> V_233 . V_231 , & V_227 ) ;
F_210 ( V_81 , V_57 , F_211 ( V_70 ) ,
& V_227 ) ;
F_212 ( V_81 , V_57 , V_70 -> V_234 , & V_227 ) ;
F_213 ( V_81 , V_57 , V_2 -> V_65 , & V_227 ) ;
F_214 ( V_81 , V_57 , V_70 -> V_235 , & V_227 ) ;
F_215 ( V_81 , V_57 , F_109 ( V_70 ) -> V_236 , & V_227 ) ;
F_216 ( V_81 , V_57 , 0 , & V_227 ) ;
}
static int F_217 ( struct V_1 * V_2 ,
struct V_3 * log , struct V_32 * V_33 ,
struct V_70 * V_70 )
{
struct V_56 * V_43 ;
struct V_35 V_36 ;
int V_5 ;
memcpy ( & V_36 , & F_109 ( V_70 ) -> V_98 , sizeof( V_36 ) ) ;
V_5 = F_37 ( V_2 , log , V_33 , & V_36 ,
sizeof( * V_43 ) ) ;
if ( V_5 && V_5 != - V_60 )
return V_5 ;
V_43 = F_31 ( V_33 -> V_51 [ 0 ] , V_33 -> V_52 [ 0 ] ,
struct V_56 ) ;
F_195 ( V_2 , V_33 -> V_51 [ 0 ] , V_43 , V_70 , 0 ) ;
F_27 ( V_33 ) ;
return 0 ;
}
static T_2 int F_218 ( struct V_1 * V_2 ,
struct V_70 * V_70 ,
struct V_32 * V_214 ,
struct V_20 * V_219 ,
int V_224 , int V_237 , int V_238 )
{
unsigned long V_239 ;
unsigned long V_240 ;
struct V_3 * log = F_109 ( V_70 ) -> V_4 -> V_8 ;
struct V_69 * V_241 ;
struct V_56 * V_43 ;
int V_5 ;
struct V_35 * V_242 ;
T_3 * V_243 ;
char * V_244 ;
int V_165 ;
struct V_245 V_87 ;
int V_246 = F_109 ( V_70 ) -> V_236 & V_247 ;
F_219 ( & V_87 ) ;
V_244 = F_28 ( V_237 * sizeof( struct V_35 ) +
V_237 * sizeof( T_3 ) , V_54 ) ;
if ( ! V_244 )
return - V_55 ;
V_243 = ( T_3 * ) V_244 ;
V_242 = (struct V_35 * ) ( V_244 + V_237 * sizeof( T_3 ) ) ;
for ( V_165 = 0 ; V_165 < V_237 ; V_165 ++ ) {
V_243 [ V_165 ] = F_24 ( V_219 , V_165 + V_224 ) ;
F_106 ( V_219 , V_242 + V_165 , V_165 + V_224 ) ;
}
V_5 = F_220 ( V_2 , log , V_214 ,
V_242 , V_243 , V_237 ) ;
if ( V_5 ) {
F_29 ( V_244 ) ;
return V_5 ;
}
for ( V_165 = 0 ; V_165 < V_237 ; V_165 ++ , V_214 -> V_52 [ 0 ] ++ ) {
V_240 = F_25 ( V_214 -> V_51 [ 0 ] ,
V_214 -> V_52 [ 0 ] ) ;
V_239 = F_25 ( V_219 , V_224 + V_165 ) ;
if ( V_242 [ V_165 ] . type == V_44 ) {
V_43 = F_31 ( V_214 -> V_51 [ 0 ] ,
V_214 -> V_52 [ 0 ] ,
struct V_56 ) ;
F_195 ( V_2 , V_214 -> V_51 [ 0 ] , V_43 ,
V_70 , V_238 == V_248 ) ;
} else {
F_42 ( V_214 -> V_51 [ 0 ] , V_219 , V_240 ,
V_239 , V_243 [ V_165 ] ) ;
}
if ( F_221 ( V_242 + V_165 ) == V_171 &&
! V_246 ) {
int V_66 ;
V_241 = F_31 ( V_219 , V_224 + V_165 ,
struct V_69 ) ;
if ( F_222 ( V_219 , V_241 ) < V_2 -> V_65 )
continue;
V_66 = F_46 ( V_219 , V_241 ) ;
if ( V_66 == V_72 ) {
T_1 V_249 , V_250 , V_251 , V_252 ;
V_249 = F_48 ( V_219 ,
V_241 ) ;
if ( V_249 == 0 )
continue;
V_250 = F_56 ( V_219 ,
V_241 ) ;
V_251 = F_57 ( V_219 , V_241 ) ;
V_252 = F_47 ( V_219 ,
V_241 ) ;
if ( F_62 ( V_219 ,
V_241 ) ) {
V_251 = 0 ;
V_252 = V_250 ;
}
V_5 = F_63 (
log -> V_15 -> V_92 ,
V_249 + V_251 , V_249 + V_251 + V_252 - 1 ,
& V_87 , 0 ) ;
if ( V_5 ) {
F_27 ( V_214 ) ;
F_29 ( V_244 ) ;
return V_5 ;
}
}
}
}
F_44 ( V_214 -> V_51 [ 0 ] ) ;
F_27 ( V_214 ) ;
F_29 ( V_244 ) ;
V_5 = 0 ;
while ( ! F_64 ( & V_87 ) ) {
struct V_88 * V_89 = F_65 ( V_87 . V_90 ,
struct V_88 ,
V_91 ) ;
if ( ! V_5 )
V_5 = F_66 ( V_2 , log , V_89 ) ;
F_67 ( & V_89 -> V_91 ) ;
F_29 ( V_89 ) ;
}
return V_5 ;
}
static int F_223 ( void * V_253 , struct V_245 * V_254 , struct V_245 * V_255 )
{
struct V_256 * V_257 , * V_258 ;
V_257 = F_65 ( V_254 , struct V_256 , V_91 ) ;
V_258 = F_65 ( V_255 , struct V_256 , V_91 ) ;
if ( V_257 -> V_28 < V_258 -> V_28 )
return - 1 ;
else if ( V_257 -> V_28 > V_258 -> V_28 )
return 1 ;
return 0 ;
}
static int F_224 ( struct V_1 * V_2 ,
struct V_70 * V_70 , struct V_3 * V_4 ,
struct V_256 * V_259 , struct V_32 * V_33 )
{
struct V_3 * log = V_4 -> V_8 ;
struct V_69 * V_260 ;
struct V_20 * V_81 ;
struct V_261 * V_262 ;
struct V_245 V_87 ;
struct V_226 V_227 ;
struct V_35 V_36 ;
T_1 V_263 = V_259 -> V_263 ;
T_1 V_264 = V_259 -> V_264 ;
T_1 V_265 ;
T_1 V_266 ;
T_1 V_267 = V_259 -> V_28 - V_259 -> V_268 ;
T_1 V_269 ;
int V_5 ;
int V_100 = log -> V_183 % 2 ;
bool V_246 = F_109 ( V_70 ) -> V_236 & V_247 ;
V_5 = F_225 ( V_2 , log , V_70 , V_33 , V_259 -> V_28 ,
V_259 -> V_28 + V_259 -> V_29 , NULL , 0 ) ;
if ( V_5 )
return V_5 ;
F_219 ( & V_87 ) ;
F_196 ( & V_227 ) ;
V_36 . V_46 = F_54 ( V_70 ) ;
V_36 . type = V_171 ;
V_36 . V_68 = V_259 -> V_28 ;
V_5 = F_37 ( V_2 , log , V_33 , & V_36 , sizeof( * V_260 ) ) ;
if ( V_5 )
return V_5 ;
V_81 = V_33 -> V_51 [ 0 ] ;
V_260 = F_31 ( V_81 , V_33 -> V_52 [ 0 ] ,
struct V_69 ) ;
F_226 ( V_81 , V_260 , V_259 -> V_228 ,
& V_227 ) ;
if ( F_227 ( V_270 , & V_259 -> V_236 ) ) {
V_246 = true ;
F_228 ( V_81 , V_260 ,
V_73 ,
& V_227 ) ;
} else {
F_228 ( V_81 , V_260 ,
V_72 ,
& V_227 ) ;
if ( V_259 -> V_271 == 0 )
V_246 = true ;
}
V_269 = F_189 ( V_259 -> V_269 , V_259 -> V_272 ) ;
if ( V_259 -> V_273 != V_274 ) {
F_229 ( V_81 , V_260 ,
V_259 -> V_271 ,
& V_227 ) ;
F_230 ( V_81 , V_260 , V_269 ,
& V_227 ) ;
} else if ( V_259 -> V_271 < V_275 ) {
F_229 ( V_81 , V_260 ,
V_259 -> V_271 -
V_267 , & V_227 ) ;
F_230 ( V_81 , V_260 , V_269 ,
& V_227 ) ;
} else {
F_229 ( V_81 , V_260 , 0 , & V_227 ) ;
F_230 ( V_81 , V_260 , 0 ,
& V_227 ) ;
}
F_231 ( V_81 , V_260 ,
V_259 -> V_28 - V_259 -> V_268 ,
& V_227 ) ;
F_232 ( V_81 , V_260 , V_259 -> V_29 , & V_227 ) ;
F_233 ( V_81 , V_260 , V_259 -> V_276 , & V_227 ) ;
F_234 ( V_81 , V_260 , V_259 -> V_273 ,
& V_227 ) ;
F_235 ( V_81 , V_260 , 0 , & V_227 ) ;
F_236 ( V_81 , V_260 , 0 , & V_227 ) ;
F_44 ( V_81 ) ;
F_27 ( V_33 ) ;
if ( V_5 ) {
return V_5 ;
}
if ( V_246 )
return 0 ;
if ( V_259 -> V_273 ) {
V_265 = 0 ;
V_266 = V_269 ;
}
V_120:
F_237 ( & log -> V_277 [ V_100 ] ) ;
F_238 (ordered, &log->logged_list[index], log_list) {
struct V_88 * V_278 ;
if ( ! V_264 )
break;
if ( V_262 -> V_70 != V_70 )
continue;
if ( V_262 -> V_279 + V_262 -> V_29 <= V_263 ||
V_263 + V_264 <= V_262 -> V_279 )
continue;
if ( V_262 -> V_279 > V_263 ) {
if ( V_262 -> V_279 + V_262 -> V_29 >=
V_263 + V_264 )
V_264 = V_262 -> V_279 - V_263 ;
} else {
if ( V_262 -> V_279 + V_262 -> V_29 <
V_263 + V_264 ) {
V_264 = ( V_263 + V_264 ) -
( V_262 -> V_279 + V_262 -> V_29 ) ;
V_263 = V_262 -> V_279 +
V_262 -> V_29 ;
} else {
V_264 = 0 ;
}
}
if ( F_239 ( V_280 ,
& V_262 -> V_236 ) )
continue;
F_3 ( & V_262 -> V_281 ) ;
F_240 ( & log -> V_277 [ V_100 ] ) ;
F_241 ( V_262 -> V_31 , V_262 -> V_282 == 0 ) ;
F_238 (sum, &ordered->list, list) {
V_5 = F_66 ( V_2 , log , V_278 ) ;
if ( V_5 ) {
F_242 ( V_262 ) ;
goto V_283;
}
}
F_242 ( V_262 ) ;
goto V_120;
}
F_240 ( & log -> V_277 [ V_100 ] ) ;
V_283:
if ( ! V_264 || V_5 )
return V_5 ;
V_265 = V_263 - V_259 -> V_28 ;
V_266 = V_264 ;
V_5 = F_63 ( log -> V_15 -> V_92 ,
V_259 -> V_271 + V_265 ,
V_259 -> V_271 + V_265 +
V_266 - 1 , & V_87 , 0 ) ;
if ( V_5 )
return V_5 ;
while ( ! F_64 ( & V_87 ) ) {
struct V_88 * V_89 = F_65 ( V_87 . V_90 ,
struct V_88 ,
V_91 ) ;
if ( ! V_5 )
V_5 = F_66 ( V_2 , log , V_89 ) ;
F_67 ( & V_89 -> V_91 ) ;
F_29 ( V_89 ) ;
}
return V_5 ;
}
static int F_243 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_70 * V_70 ,
struct V_32 * V_33 )
{
struct V_256 * V_259 , * V_284 ;
struct V_245 V_285 ;
struct V_286 * V_287 = & F_109 ( V_70 ) -> V_288 ;
T_1 V_289 ;
int V_5 = 0 ;
int V_290 = 0 ;
F_219 ( & V_285 ) ;
F_244 ( & V_287 -> V_291 ) ;
V_289 = V_4 -> V_15 -> V_292 ;
F_245 (em, n, &tree->modified_extents, list) {
F_246 ( & V_259 -> V_91 ) ;
if ( ++ V_290 > 32768 ) {
F_246 ( & V_287 -> V_293 ) ;
V_5 = - V_294 ;
goto V_295;
}
if ( V_259 -> V_228 <= V_289 )
continue;
F_3 ( & V_259 -> V_281 ) ;
F_247 ( V_296 , & V_259 -> V_236 ) ;
F_248 ( & V_259 -> V_91 , & V_285 ) ;
V_290 ++ ;
}
F_249 ( NULL , & V_285 , F_223 ) ;
V_295:
while ( ! F_64 ( & V_285 ) ) {
V_259 = F_65 ( V_285 . V_90 , struct V_256 , V_91 ) ;
F_246 ( & V_259 -> V_91 ) ;
if ( V_5 ) {
F_250 ( V_287 , V_259 ) ;
F_251 ( V_259 ) ;
continue;
}
F_252 ( & V_287 -> V_291 ) ;
V_5 = F_224 ( V_2 , V_70 , V_4 , V_259 , V_33 ) ;
F_244 ( & V_287 -> V_291 ) ;
F_250 ( V_287 , V_259 ) ;
F_251 ( V_259 ) ;
}
F_130 ( ! F_64 ( & V_285 ) ) ;
F_252 ( & V_287 -> V_291 ) ;
F_27 ( V_33 ) ;
return V_5 ;
}
static int F_253 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_70 * V_70 ,
int V_238 )
{
struct V_32 * V_33 ;
struct V_32 * V_214 ;
struct V_35 V_217 ;
struct V_35 V_218 ;
struct V_3 * log = V_4 -> V_8 ;
struct V_20 * V_219 = NULL ;
int V_6 = 0 ;
int V_5 ;
int V_153 ;
int V_297 = 0 ;
int V_298 ;
bool V_299 = false ;
T_1 V_132 = F_54 ( V_70 ) ;
V_33 = F_82 () ;
if ( ! V_33 )
return - V_55 ;
V_214 = F_82 () ;
if ( ! V_214 ) {
F_86 ( V_33 ) ;
return - V_55 ;
}
V_217 . V_46 = V_132 ;
V_217 . type = V_44 ;
V_217 . V_68 = 0 ;
V_218 . V_46 = V_132 ;
if ( F_35 ( V_70 -> V_135 ) ||
( ! F_227 ( V_300 ,
& F_109 ( V_70 ) -> V_301 ) &&
V_238 == V_248 ) )
V_218 . type = V_170 ;
else
V_218 . type = ( T_4 ) - 1 ;
V_218 . V_68 = ( T_1 ) - 1 ;
if ( F_35 ( V_70 -> V_135 ) ||
F_109 ( V_70 ) -> V_228 > V_4 -> V_15 -> V_292 ) {
V_5 = F_254 ( V_2 , V_70 ) ;
if ( V_5 ) {
F_86 ( V_33 ) ;
F_86 ( V_214 ) ;
return V_5 ;
}
}
F_2 ( & F_109 ( V_70 ) -> V_7 ) ;
F_255 ( log , V_70 ) ;
if ( F_35 ( V_70 -> V_135 ) ) {
int V_223 = V_162 ;
if ( V_238 == V_248 )
V_223 = V_170 ;
V_5 = F_191 ( V_2 , log , V_33 , V_132 , V_223 ) ;
} else {
if ( F_256 ( V_300 ,
& F_109 ( V_70 ) -> V_301 ) ) {
F_257 ( V_302 ,
& F_109 ( V_70 ) -> V_301 ) ;
V_5 = F_258 ( V_2 , log ,
V_70 , 0 , 0 ) ;
} else if ( F_256 ( V_302 ,
& F_109 ( V_70 ) -> V_301 ) ) {
if ( V_238 == V_303 )
V_299 = true ;
V_218 . type = V_170 ;
V_5 = F_191 ( V_2 , log , V_33 , V_132 ,
V_218 . type ) ;
} else {
if ( V_238 == V_303 )
V_299 = true ;
V_5 = F_217 ( V_2 , log , V_214 , V_70 ) ;
if ( V_5 ) {
V_6 = V_5 ;
goto V_210;
}
goto V_304;
}
}
if ( V_5 ) {
V_6 = V_5 ;
goto V_210;
}
V_33 -> V_220 = 1 ;
while ( 1 ) {
V_298 = 0 ;
V_5 = F_187 ( V_4 , & V_217 , & V_218 ,
V_33 , V_2 -> V_65 ) ;
if ( V_5 != 0 )
break;
V_120:
if ( V_217 . V_46 != V_132 )
break;
if ( V_217 . type > V_218 . type )
break;
V_219 = V_33 -> V_51 [ 0 ] ;
if ( V_298 && V_297 + V_298 == V_33 -> V_52 [ 0 ] ) {
V_298 ++ ;
goto V_305;
} else if ( ! V_298 ) {
V_297 = V_33 -> V_52 [ 0 ] ;
V_298 = 1 ;
goto V_305;
}
V_5 = F_218 ( V_2 , V_70 , V_214 , V_219 , V_297 ,
V_298 , V_238 ) ;
if ( V_5 ) {
V_6 = V_5 ;
goto V_210;
}
V_298 = 1 ;
V_297 = V_33 -> V_52 [ 0 ] ;
V_305:
V_153 = F_124 ( V_33 -> V_51 [ 0 ] ) ;
V_33 -> V_52 [ 0 ] ++ ;
if ( V_33 -> V_52 [ 0 ] < V_153 ) {
F_106 ( V_33 -> V_51 [ 0 ] , & V_217 ,
V_33 -> V_52 [ 0 ] ) ;
goto V_120;
}
if ( V_298 ) {
V_5 = F_218 ( V_2 , V_70 , V_214 , V_219 ,
V_297 ,
V_298 , V_238 ) ;
if ( V_5 ) {
V_6 = V_5 ;
goto V_210;
}
V_298 = 0 ;
}
F_27 ( V_33 ) ;
if ( V_217 . V_68 < ( T_1 ) - 1 )
V_217 . V_68 ++ ;
else if ( V_217 . type < ( T_4 ) - 1 )
V_217 . type ++ ;
else if ( V_217 . V_46 < ( T_1 ) - 1 )
V_217 . V_46 ++ ;
else
break;
}
if ( V_298 ) {
V_5 = F_218 ( V_2 , V_70 , V_214 , V_219 , V_297 ,
V_298 , V_238 ) ;
if ( V_5 ) {
V_6 = V_5 ;
goto V_210;
}
V_298 = 0 ;
}
V_304:
F_27 ( V_33 ) ;
F_27 ( V_214 ) ;
if ( V_299 ) {
V_5 = F_243 ( V_2 , V_4 , V_70 , V_214 ) ;
if ( V_5 ) {
V_6 = V_5 ;
goto V_210;
}
} else {
struct V_286 * V_287 = & F_109 ( V_70 ) -> V_288 ;
struct V_256 * V_259 , * V_284 ;
F_244 ( & V_287 -> V_291 ) ;
F_245 (em, n, &tree->modified_extents, list)
F_246 ( & V_259 -> V_91 ) ;
F_252 ( & V_287 -> V_291 ) ;
}
if ( V_238 == V_303 && F_35 ( V_70 -> V_135 ) ) {
V_5 = F_190 ( V_2 , V_4 , V_70 , V_33 , V_214 ) ;
if ( V_5 ) {
V_6 = V_5 ;
goto V_210;
}
}
F_109 ( V_70 ) -> V_209 = V_2 -> V_65 ;
F_109 ( V_70 ) -> V_204 = F_109 ( V_70 ) -> V_306 ;
V_210:
if ( V_6 )
F_161 ( log , log -> V_183 ) ;
F_4 ( & F_109 ( V_70 ) -> V_7 ) ;
F_86 ( V_33 ) ;
F_86 ( V_214 ) ;
return V_6 ;
}
static T_2 int F_259 ( struct V_1 * V_2 ,
struct V_70 * V_70 ,
struct V_307 * V_176 ,
struct V_308 * V_309 ,
T_1 V_310 )
{
int V_5 = 0 ;
struct V_3 * V_4 ;
struct V_307 * V_311 = NULL ;
struct V_70 * V_312 = V_70 ;
if ( F_128 ( V_70 -> V_135 ) &&
F_109 ( V_70 ) -> V_228 <= V_310 &&
F_109 ( V_70 ) -> V_313 <= V_310 )
goto V_76;
if ( ! F_35 ( V_70 -> V_135 ) ) {
if ( ! V_176 || ! V_176 -> V_314 || V_309 != V_176 -> V_314 -> V_315 )
goto V_76;
V_70 = V_176 -> V_314 ;
}
while ( 1 ) {
if ( V_70 != V_312 )
F_109 ( V_70 ) -> V_209 = V_2 -> V_65 ;
F_8 () ;
if ( F_109 ( V_70 ) -> V_313 > V_310 ) {
V_4 = F_109 ( V_70 ) -> V_4 ;
V_4 -> V_15 -> V_187 =
V_2 -> V_65 ;
V_5 = 1 ;
break;
}
if ( ! V_176 || ! V_176 -> V_314 || V_309 != V_176 -> V_314 -> V_315 )
break;
if ( F_260 ( V_176 ) )
break;
V_176 = F_261 ( V_176 ) ;
F_262 ( V_311 ) ;
V_311 = V_176 ;
V_70 = V_176 -> V_314 ;
}
F_262 ( V_311 ) ;
V_76:
return V_5 ;
}
static int F_263 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_70 * V_70 ,
struct V_307 * V_176 , int V_316 )
{
int V_238 = V_316 ? V_248 : V_303 ;
struct V_308 * V_309 ;
struct V_307 * V_311 = NULL ;
int V_5 = 0 ;
T_1 V_310 = V_4 -> V_15 -> V_292 ;
V_309 = V_70 -> V_315 ;
if ( F_159 ( V_4 , V_317 ) ) {
V_5 = 1 ;
goto V_318;
}
if ( V_4 -> V_15 -> V_187 >
V_4 -> V_15 -> V_292 ) {
V_5 = 1 ;
goto V_318;
}
if ( V_4 != F_109 ( V_70 ) -> V_4 ||
F_264 ( & V_4 -> V_184 ) == 0 ) {
V_5 = 1 ;
goto V_318;
}
V_5 = F_259 ( V_2 , V_70 , V_176 ,
V_309 , V_310 ) ;
if ( V_5 )
goto V_318;
if ( F_265 ( V_70 , V_2 -> V_65 ) ) {
V_5 = V_319 ;
goto V_318;
}
V_5 = F_1 ( V_2 , V_4 ) ;
if ( V_5 )
goto V_320;
V_5 = F_253 ( V_2 , V_4 , V_70 , V_238 ) ;
if ( V_5 )
goto V_320;
if ( F_128 ( V_70 -> V_135 ) &&
F_109 ( V_70 ) -> V_228 <= V_310 &&
F_109 ( V_70 ) -> V_313 <= V_310 ) {
V_5 = 0 ;
goto V_320;
}
V_238 = V_248 ;
while ( 1 ) {
if ( ! V_176 || ! V_176 -> V_314 || V_309 != V_176 -> V_314 -> V_315 )
break;
V_70 = V_176 -> V_314 ;
if ( V_4 != F_109 ( V_70 ) -> V_4 )
break;
if ( F_109 ( V_70 ) -> V_228 >
V_4 -> V_15 -> V_292 ) {
V_5 = F_253 ( V_2 , V_4 , V_70 , V_238 ) ;
if ( V_5 )
goto V_320;
}
if ( F_260 ( V_176 ) )
break;
V_176 = F_261 ( V_176 ) ;
F_262 ( V_311 ) ;
V_311 = V_176 ;
}
V_5 = 0 ;
V_320:
F_262 ( V_311 ) ;
if ( V_5 < 0 ) {
V_4 -> V_15 -> V_187 = V_2 -> V_65 ;
V_5 = 1 ;
}
F_10 ( V_4 ) ;
V_318:
return V_5 ;
}
int F_266 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_307 * V_307 )
{
struct V_307 * V_176 = F_261 ( V_307 ) ;
int V_5 ;
V_5 = F_263 ( V_2 , V_4 , V_307 -> V_314 , V_176 , 0 ) ;
F_262 ( V_176 ) ;
return V_5 ;
}
int F_267 ( struct V_3 * V_17 )
{
int V_5 ;
struct V_32 * V_33 ;
struct V_1 * V_2 ;
struct V_35 V_36 ;
struct V_35 V_139 ;
struct V_35 V_321 ;
struct V_3 * log ;
struct V_206 * V_15 = V_17 -> V_15 ;
struct V_22 V_23 = {
. V_179 = F_14 ,
. V_166 = 0 ,
} ;
V_33 = F_82 () ;
if ( ! V_33 )
return - V_55 ;
V_15 -> V_322 = 1 ;
V_2 = F_268 ( V_15 -> V_203 , 0 ) ;
if ( F_79 ( V_2 ) ) {
V_5 = F_180 ( V_2 ) ;
goto error;
}
V_23 . V_2 = V_2 ;
V_23 . V_26 = 1 ;
V_5 = F_145 ( V_2 , V_17 , & V_23 ) ;
if ( V_5 ) {
F_269 ( V_15 , V_5 , L_1
L_2 ) ;
goto error;
}
V_120:
V_36 . V_46 = V_47 ;
V_36 . V_68 = ( T_1 ) - 1 ;
F_113 ( & V_36 , V_323 ) ;
while ( 1 ) {
V_5 = F_26 ( NULL , V_17 , & V_36 , V_33 , 0 , 0 ) ;
if ( V_5 < 0 ) {
F_269 ( V_15 , V_5 ,
L_3 ) ;
goto error;
}
if ( V_5 > 0 ) {
if ( V_33 -> V_52 [ 0 ] == 0 )
break;
V_33 -> V_52 [ 0 ] -- ;
}
F_106 ( V_33 -> V_51 [ 0 ] , & V_139 ,
V_33 -> V_52 [ 0 ] ) ;
F_27 ( V_33 ) ;
if ( V_139 . V_46 != V_47 )
break;
log = F_270 ( V_17 , & V_139 ) ;
if ( F_79 ( log ) ) {
V_5 = F_180 ( log ) ;
F_269 ( V_15 , V_5 ,
L_4 ) ;
goto error;
}
V_321 . V_46 = V_139 . V_68 ;
V_321 . type = V_323 ;
V_321 . V_68 = ( T_1 ) - 1 ;
V_23 . V_163 = F_271 ( V_15 , & V_321 ) ;
if ( F_79 ( V_23 . V_163 ) ) {
V_5 = F_180 ( V_23 . V_163 ) ;
F_136 ( log -> V_180 ) ;
F_136 ( log -> V_324 ) ;
F_29 ( log ) ;
F_269 ( V_15 , V_5 , L_5
L_6 ) ;
goto error;
}
V_23 . V_163 -> V_8 = log ;
F_272 ( V_2 , V_23 . V_163 ) ;
V_5 = F_145 ( V_2 , log , & V_23 ) ;
if ( ! V_5 && V_23 . V_166 == V_169 ) {
V_5 = F_111 ( V_2 , V_23 . V_163 ,
V_33 ) ;
}
V_36 . V_68 = V_139 . V_68 - 1 ;
V_23 . V_163 -> V_8 = NULL ;
F_136 ( log -> V_180 ) ;
F_136 ( log -> V_324 ) ;
F_29 ( log ) ;
if ( V_5 )
goto error;
if ( V_139 . V_68 == 0 )
break;
}
F_27 ( V_33 ) ;
if ( V_23 . V_26 ) {
V_23 . V_26 = 0 ;
V_23 . V_179 = F_127 ;
V_23 . V_166 = V_167 ;
goto V_120;
}
if ( V_23 . V_166 < V_169 ) {
V_23 . V_166 ++ ;
goto V_120;
}
F_86 ( V_33 ) ;
V_5 = F_273 ( V_2 , V_15 -> V_203 ) ;
if ( V_5 )
return V_5 ;
F_136 ( V_17 -> V_180 ) ;
V_17 -> V_8 = NULL ;
V_15 -> V_322 = 0 ;
F_29 ( V_17 ) ;
return 0 ;
error:
if ( V_23 . V_2 )
F_274 ( V_23 . V_2 , V_15 -> V_203 ) ;
F_86 ( V_33 ) ;
return V_5 ;
}
void F_275 ( struct V_1 * V_2 ,
struct V_70 * V_93 , struct V_70 * V_70 ,
int V_325 )
{
if ( F_128 ( V_70 -> V_135 ) )
F_109 ( V_70 ) -> V_313 = V_2 -> V_65 ;
F_8 () ;
if ( F_109 ( V_93 ) -> V_209 == V_2 -> V_65 )
return;
if ( F_109 ( V_70 ) -> V_209 == V_2 -> V_65 )
return;
if ( V_325 )
goto V_326;
return;
V_326:
F_109 ( V_93 ) -> V_313 = V_2 -> V_65 ;
}
int F_276 ( struct V_1 * V_2 ,
struct V_70 * V_70 , struct V_70 * V_327 ,
struct V_307 * V_176 )
{
struct V_3 * V_4 = F_109 ( V_70 ) -> V_4 ;
if ( F_128 ( V_70 -> V_135 ) )
F_109 ( V_70 ) -> V_313 = V_2 -> V_65 ;
if ( F_109 ( V_70 ) -> V_209 <=
V_4 -> V_15 -> V_292 &&
( ! V_327 || F_109 ( V_327 ) -> V_209 <=
V_4 -> V_15 -> V_292 ) )
return 0 ;
return F_263 ( V_2 , V_4 , V_70 , V_176 , 1 ) ;
}
