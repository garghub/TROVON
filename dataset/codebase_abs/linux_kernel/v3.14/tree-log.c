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
V_71 = F_49 ( V_21 , V_34 , V_57 ) ;
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
struct V_70 * V_93 = NULL ;
struct V_70 * V_70 = NULL ;
unsigned long V_126 ;
unsigned long V_127 ;
char * V_96 = NULL ;
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
if ( ! V_93 ) {
V_5 = - V_18 ;
goto V_76;
}
V_70 = F_52 ( V_4 , V_111 ) ;
if ( ! V_70 ) {
V_5 = - V_77 ;
goto V_76;
}
while ( V_126 < V_127 ) {
if ( V_128 ) {
V_5 = F_94 ( V_21 , V_126 , & V_103 , & V_96 ,
& V_113 , & V_112 ) ;
if ( ! V_93 )
V_93 = F_52 ( V_4 , V_112 ) ;
if ( ! V_93 ) {
V_5 = - V_18 ;
goto V_76;
}
} else {
V_5 = F_96 ( V_21 , V_126 , & V_103 , & V_96 ,
& V_113 ) ;
}
if ( V_5 )
goto V_76;
if ( ! F_77 ( V_4 , V_33 , F_54 ( V_93 ) , F_54 ( V_70 ) ,
V_113 , V_96 , V_103 ) ) {
if ( ! V_114 ) {
V_5 = F_87 ( V_2 , V_4 , V_33 , log ,
V_93 , V_70 , V_21 ,
V_111 ,
V_112 ,
V_113 , V_96 , V_103 ,
& V_114 ) ;
if ( V_5 ) {
if ( V_5 == 1 )
V_5 = 0 ;
goto V_76;
}
}
V_5 = F_99 ( V_2 , V_93 , V_70 , V_96 , V_103 ,
0 , V_113 ) ;
if ( V_5 )
goto V_76;
F_69 ( V_2 , V_4 , V_70 ) ;
}
V_126 = ( unsigned long ) ( V_126 + V_129 ) + V_103 ;
F_29 ( V_96 ) ;
V_96 = NULL ;
if ( V_128 ) {
F_70 ( V_93 ) ;
V_93 = NULL ;
}
}
V_5 = F_23 ( V_2 , V_4 , V_33 , V_21 , V_34 , V_36 ) ;
V_76:
F_27 ( V_33 ) ;
F_29 ( V_96 ) ;
F_70 ( V_93 ) ;
F_70 ( V_70 ) ;
return V_5 ;
}
static int F_100 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_1 V_68 )
{
int V_5 ;
V_5 = F_101 ( V_4 , NULL , V_131 ,
V_68 , V_132 , NULL ) ;
if ( V_5 > 0 )
V_5 = F_102 ( V_2 , V_4 , V_68 ) ;
return V_5 ;
}
static int F_103 ( struct V_3 * V_4 ,
struct V_70 * V_70 , struct V_32 * V_33 )
{
int V_5 = 0 ;
int V_97 ;
unsigned int V_133 = 0 ;
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
V_133 ++ ;
V_123 += V_97 + sizeof( * V_119 ) ;
}
V_68 ++ ;
F_27 ( V_33 ) ;
}
F_27 ( V_33 ) ;
if ( V_5 < 0 )
return V_5 ;
return V_133 ;
}
static int F_105 ( struct V_3 * V_4 ,
struct V_70 * V_70 , struct V_32 * V_33 )
{
int V_5 ;
struct V_35 V_36 ;
unsigned int V_133 = 0 ;
unsigned long V_106 ;
unsigned long V_107 ;
int V_97 ;
T_1 V_134 = F_54 ( V_70 ) ;
V_36 . V_46 = V_134 ;
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
V_135:
F_106 ( V_33 -> V_51 [ 0 ] , & V_36 ,
V_33 -> V_52 [ 0 ] ) ;
if ( V_36 . V_46 != V_134 ||
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
V_133 ++ ;
}
if ( V_36 . V_68 == 0 )
break;
if ( V_33 -> V_52 [ 0 ] > 0 ) {
V_33 -> V_52 [ 0 ] -- ;
goto V_135;
}
V_36 . V_68 -- ;
F_27 ( V_33 ) ;
}
F_27 ( V_33 ) ;
return V_133 ;
}
static T_2 int F_107 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_70 * V_70 )
{
struct V_32 * V_33 ;
int V_5 ;
T_1 V_133 = 0 ;
T_1 V_134 = F_54 ( V_70 ) ;
V_33 = F_82 () ;
if ( ! V_33 )
return - V_55 ;
V_5 = F_105 ( V_4 , V_70 , V_33 ) ;
if ( V_5 < 0 )
goto V_76;
V_133 = V_5 ;
V_5 = F_103 ( V_4 , V_70 , V_33 ) ;
if ( V_5 == - V_18 )
V_5 = 0 ;
if ( V_5 < 0 )
goto V_76;
V_133 += V_5 ;
V_5 = 0 ;
if ( V_133 != V_70 -> V_136 ) {
F_108 ( V_70 , V_133 ) ;
F_69 ( V_2 , V_4 , V_70 ) ;
}
F_109 ( V_70 ) -> V_137 = ( T_1 ) - 1 ;
if ( V_70 -> V_136 == 0 ) {
if ( F_35 ( V_70 -> V_138 ) ) {
V_5 = F_110 ( V_2 , V_4 , NULL , V_33 ,
V_134 , 1 ) ;
if ( V_5 )
goto V_76;
}
V_5 = F_100 ( V_2 , V_4 , V_134 ) ;
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
V_36 . V_46 = V_139 ;
V_36 . type = V_132 ;
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
if ( V_36 . V_46 != V_139 ||
V_36 . type != V_132 )
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
V_36 . V_46 = V_139 ;
F_113 ( & V_36 , V_132 ) ;
V_36 . V_68 = V_46 ;
V_5 = F_37 ( V_2 , V_4 , V_33 , & V_36 , 0 ) ;
F_27 ( V_33 ) ;
if ( V_5 == 0 ) {
if ( ! V_70 -> V_136 )
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
struct V_94 * V_140 ;
struct V_35 V_141 ;
struct V_35 V_142 ;
struct V_70 * V_93 ;
T_4 V_143 ;
int V_144 ;
int V_5 = 0 ;
bool V_145 = ( V_36 -> type == V_146 ) ;
V_93 = F_52 ( V_4 , V_36 -> V_46 ) ;
if ( ! V_93 )
return - V_77 ;
V_97 = F_73 ( V_21 , V_95 ) ;
V_96 = F_28 ( V_97 , V_54 ) ;
if ( ! V_96 ) {
V_5 = - V_55 ;
goto V_76;
}
V_143 = F_117 ( V_21 , V_95 ) ;
F_30 ( V_21 , V_96 , ( unsigned long ) ( V_95 + 1 ) ,
V_97 ) ;
F_72 ( V_21 , V_95 , & V_142 ) ;
V_144 = F_118 ( V_2 , V_4 , V_33 , & V_142 , 0 ) ;
if ( V_144 == 0 )
V_144 = 1 ;
else
V_144 = 0 ;
F_27 ( V_33 ) ;
if ( V_36 -> type == V_147 ) {
V_140 = F_80 ( V_2 , V_4 , V_33 , V_36 -> V_46 ,
V_96 , V_97 , 1 ) ;
} else if ( V_36 -> type == V_146 ) {
V_140 = F_78 ( V_2 , V_4 , V_33 ,
V_36 -> V_46 ,
V_36 -> V_68 , V_96 ,
V_97 , 1 ) ;
} else {
V_5 = - V_148 ;
goto V_76;
}
if ( F_90 ( V_140 ) ) {
if ( V_36 -> type != V_146 )
goto V_76;
goto V_53;
}
F_72 ( V_33 -> V_51 [ 0 ] , V_140 , & V_141 ) ;
if ( V_141 . V_46 == V_142 . V_46 &&
V_141 . type == V_142 . type &&
V_141 . V_68 == V_142 . V_68 &&
F_117 ( V_33 -> V_51 [ 0 ] , V_140 ) == V_143 ) {
goto V_76;
}
if ( ! V_144 )
goto V_76;
V_5 = F_71 ( V_2 , V_4 , V_33 , V_93 , V_140 ) ;
if ( V_5 )
goto V_76;
if ( V_36 -> type == V_146 )
goto V_53;
V_76:
F_27 ( V_33 ) ;
if ( ! V_5 && V_145 ) {
F_119 ( V_93 , V_93 -> V_149 + V_97 * 2 ) ;
V_5 = F_69 ( V_2 , V_4 , V_93 ) ;
}
F_29 ( V_96 ) ;
F_70 ( V_93 ) ;
return V_5 ;
V_53:
F_27 ( V_33 ) ;
V_5 = F_115 ( V_2 , V_4 , V_33 , V_36 -> V_46 , V_36 -> V_68 ,
V_96 , V_97 , V_143 , & V_142 ) ;
if ( V_5 && V_5 != - V_18 )
goto V_76;
V_145 = false ;
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
T_1 V_99 , int V_150 ,
T_1 * V_151 , T_1 * V_152 )
{
struct V_35 V_36 ;
T_1 V_153 ;
struct V_154 * V_57 ;
int V_5 ;
int V_155 ;
if ( * V_151 == ( T_1 ) - 1 )
return 1 ;
V_36 . V_46 = V_99 ;
V_36 . type = V_150 ;
V_36 . V_68 = * V_151 ;
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
if ( V_36 . type != V_150 || V_36 . V_46 != V_99 ) {
V_5 = 1 ;
goto V_90;
}
V_57 = F_31 ( V_33 -> V_51 [ 0 ] , V_33 -> V_52 [ 0 ] ,
struct V_154 ) ;
V_153 = F_123 ( V_33 -> V_51 [ 0 ] , V_57 ) ;
if ( * V_151 >= V_36 . V_68 && * V_151 <= V_153 ) {
V_5 = 0 ;
* V_151 = V_36 . V_68 ;
* V_152 = V_153 ;
goto V_76;
}
V_5 = 1 ;
V_90:
V_155 = F_124 ( V_33 -> V_51 [ 0 ] ) ;
if ( V_33 -> V_52 [ 0 ] >= V_155 ) {
V_5 = F_125 ( V_4 , V_33 ) ;
if ( V_5 )
goto V_76;
} else {
V_33 -> V_52 [ 0 ] ++ ;
}
F_106 ( V_33 -> V_51 [ 0 ] , & V_36 , V_33 -> V_52 [ 0 ] ) ;
if ( V_36 . type != V_150 || V_36 . V_46 != V_99 ) {
V_5 = 1 ;
goto V_76;
}
V_57 = F_31 ( V_33 -> V_51 [ 0 ] , V_33 -> V_52 [ 0 ] ,
struct V_154 ) ;
V_153 = F_123 ( V_33 -> V_51 [ 0 ] , V_57 ) ;
* V_151 = V_36 . V_68 ;
* V_152 = V_153 ;
V_5 = 0 ;
V_76:
F_27 ( V_33 ) ;
return V_5 ;
}
static T_2 int F_126 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_3 * log ,
struct V_32 * V_33 ,
struct V_32 * V_156 ,
struct V_70 * V_93 ,
struct V_35 * V_157 )
{
int V_5 ;
struct V_20 * V_21 ;
int V_34 ;
T_3 V_37 ;
struct V_94 * V_95 ;
struct V_94 * V_158 ;
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
V_158 = NULL ;
if ( log && V_157 -> type == V_147 ) {
V_158 = F_80 ( V_2 , log , V_156 ,
V_157 -> V_46 ,
V_96 , V_97 , 0 ) ;
} else if ( log && V_157 -> type == V_146 ) {
V_158 = F_78 ( V_2 , log ,
V_156 ,
V_157 -> V_46 ,
V_157 -> V_68 ,
V_96 , V_97 , 0 ) ;
}
if ( ! V_158 || ( F_79 ( V_158 ) && F_127 ( V_158 ) == - V_18 ) ) {
F_72 ( V_21 , V_95 , & V_98 ) ;
F_27 ( V_33 ) ;
F_27 ( V_156 ) ;
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
V_5 = F_26 ( NULL , V_4 , V_157 , V_33 ,
0 , 0 ) ;
if ( V_5 == 0 )
goto V_120;
V_5 = 0 ;
goto V_76;
} else if ( F_79 ( V_158 ) ) {
F_29 ( V_96 ) ;
return F_127 ( V_158 ) ;
}
F_27 ( V_156 ) ;
F_29 ( V_96 ) ;
V_106 = ( unsigned long ) ( V_95 + 1 ) ;
V_106 += V_97 ;
}
V_5 = 0 ;
V_76:
F_27 ( V_33 ) ;
F_27 ( V_156 ) ;
return V_5 ;
}
static T_2 int F_110 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_3 * log ,
struct V_32 * V_33 ,
T_1 V_99 , int V_159 )
{
T_1 V_160 ;
T_1 V_161 ;
int V_150 = V_162 ;
int V_5 = 0 ;
struct V_35 V_157 ;
struct V_35 V_141 ;
struct V_32 * V_156 ;
struct V_70 * V_93 ;
V_157 . V_46 = V_99 ;
V_157 . type = V_147 ;
V_156 = F_82 () ;
if ( ! V_156 )
return - V_55 ;
V_93 = F_52 ( V_4 , V_99 ) ;
if ( ! V_93 ) {
F_86 ( V_156 ) ;
return 0 ;
}
V_120:
V_160 = 0 ;
V_161 = 0 ;
while ( 1 ) {
if ( V_159 )
V_161 = ( T_1 ) - 1 ;
else {
V_5 = F_122 ( log , V_33 , V_99 , V_150 ,
& V_160 , & V_161 ) ;
if ( V_5 != 0 )
break;
}
V_157 . V_68 = V_160 ;
while ( 1 ) {
int V_155 ;
V_5 = F_26 ( NULL , V_4 , & V_157 , V_33 ,
0 , 0 ) ;
if ( V_5 < 0 )
goto V_76;
V_155 = F_124 ( V_33 -> V_51 [ 0 ] ) ;
if ( V_33 -> V_52 [ 0 ] >= V_155 ) {
V_5 = F_125 ( V_4 , V_33 ) ;
if ( V_5 )
break;
}
F_106 ( V_33 -> V_51 [ 0 ] , & V_141 ,
V_33 -> V_52 [ 0 ] ) ;
if ( V_141 . V_46 != V_99 ||
V_141 . type != V_157 . type )
goto V_163;
if ( V_141 . V_68 > V_161 )
break;
V_5 = F_126 ( V_2 , V_4 , log , V_33 ,
V_156 , V_93 ,
& V_141 ) ;
if ( V_5 )
goto V_76;
if ( V_141 . V_68 == ( T_1 ) - 1 )
break;
V_157 . V_68 = V_141 . V_68 + 1 ;
}
F_27 ( V_33 ) ;
if ( V_161 == ( T_1 ) - 1 )
break;
V_160 = V_161 + 1 ;
}
V_163:
V_5 = 0 ;
if ( V_150 == V_162 ) {
V_150 = V_164 ;
V_157 . type = V_146 ;
F_27 ( V_33 ) ;
goto V_120;
}
V_76:
F_27 ( V_33 ) ;
F_86 ( V_156 ) ;
F_70 ( V_93 ) ;
return V_5 ;
}
static int F_128 ( struct V_3 * log , struct V_20 * V_21 ,
struct V_22 * V_23 , T_1 V_24 )
{
int V_155 ;
struct V_32 * V_33 ;
struct V_3 * V_4 = V_23 -> V_165 ;
struct V_35 V_36 ;
int V_166 ;
int V_167 ;
int V_5 ;
V_5 = F_16 ( V_21 , V_24 ) ;
if ( V_5 )
return V_5 ;
V_166 = F_19 ( V_21 ) ;
if ( V_166 != 0 )
return 0 ;
V_33 = F_82 () ;
if ( ! V_33 )
return - V_55 ;
V_155 = F_124 ( V_21 ) ;
for ( V_167 = 0 ; V_167 < V_155 ; V_167 ++ ) {
F_106 ( V_21 , & V_36 , V_167 ) ;
if ( V_36 . type == V_44 &&
V_23 -> V_168 == V_169 ) {
struct V_56 * V_43 ;
T_3 V_59 ;
V_43 = F_31 ( V_21 , V_167 ,
struct V_56 ) ;
V_59 = F_34 ( V_21 , V_43 ) ;
if ( F_35 ( V_59 ) ) {
V_5 = F_110 ( V_23 -> V_2 ,
V_4 , log , V_33 , V_36 . V_46 , 0 ) ;
if ( V_5 )
break;
}
V_5 = F_23 ( V_23 -> V_2 , V_4 , V_33 ,
V_21 , V_167 , & V_36 ) ;
if ( V_5 )
break;
if ( F_129 ( V_59 ) ) {
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
if ( V_36 . type == V_146 &&
V_23 -> V_168 == V_170 ) {
V_5 = F_120 ( V_23 -> V_2 , V_4 , V_33 ,
V_21 , V_167 , & V_36 ) ;
if ( V_5 )
break;
}
if ( V_23 -> V_168 < V_171 )
continue;
if ( V_36 . type == V_172 ) {
V_5 = F_23 ( V_23 -> V_2 , V_4 , V_33 ,
V_21 , V_167 , & V_36 ) ;
if ( V_5 )
break;
} else if ( V_36 . type == V_121 ||
V_36 . type == V_110 ) {
V_5 = F_98 ( V_23 -> V_2 , V_4 , log , V_33 ,
V_21 , V_167 , & V_36 ) ;
if ( V_5 && V_5 != - V_18 )
break;
V_5 = 0 ;
} else if ( V_36 . type == V_173 ) {
V_5 = F_45 ( V_23 -> V_2 , V_4 , V_33 ,
V_21 , V_167 , & V_36 ) ;
if ( V_5 )
break;
} else if ( V_36 . type == V_147 ) {
V_5 = F_120 ( V_23 -> V_2 , V_4 , V_33 ,
V_21 , V_167 , & V_36 ) ;
if ( V_5 )
break;
}
}
F_86 ( V_33 ) ;
return V_5 ;
}
static T_2 int F_130 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_32 * V_33 , int * V_166 ,
struct V_22 * V_23 )
{
T_1 V_174 ;
T_1 V_175 ;
T_1 V_176 ;
struct V_20 * V_90 ;
struct V_20 * V_177 ;
struct V_20 * V_178 ;
T_3 V_179 ;
int V_5 = 0 ;
F_131 ( * V_166 < 0 ) ;
F_131 ( * V_166 >= V_180 ) ;
while ( * V_166 > 0 ) {
F_131 ( * V_166 < 0 ) ;
F_131 ( * V_166 >= V_180 ) ;
V_177 = V_33 -> V_51 [ * V_166 ] ;
F_131 ( F_19 ( V_177 ) != * V_166 ) ;
if ( V_33 -> V_52 [ * V_166 ] >=
F_124 ( V_177 ) )
break;
V_175 = F_132 ( V_177 , V_33 -> V_52 [ * V_166 ] ) ;
V_176 = F_133 ( V_177 , V_33 -> V_52 [ * V_166 ] ) ;
V_179 = F_134 ( V_4 , * V_166 - 1 ) ;
V_178 = V_33 -> V_51 [ * V_166 ] ;
V_174 = F_135 ( V_178 ) ;
V_90 = F_136 ( V_4 , V_175 , V_179 ) ;
if ( ! V_90 )
return - V_55 ;
if ( * V_166 == 1 ) {
V_5 = V_23 -> V_181 ( V_4 , V_90 , V_23 , V_176 ) ;
if ( V_5 ) {
F_137 ( V_90 ) ;
return V_5 ;
}
V_33 -> V_52 [ * V_166 ] ++ ;
if ( V_23 -> free ) {
V_5 = F_16 ( V_90 , V_176 ) ;
if ( V_5 ) {
F_137 ( V_90 ) ;
return V_5 ;
}
if ( V_2 ) {
F_138 ( V_90 ) ;
F_139 ( V_90 ) ;
F_140 ( V_2 , V_4 , V_90 ) ;
F_22 ( V_90 ) ;
F_141 ( V_90 ) ;
}
F_131 ( V_174 !=
V_47 ) ;
V_5 = F_142 ( V_4 ,
V_175 , V_179 ) ;
if ( V_5 ) {
F_137 ( V_90 ) ;
return V_5 ;
}
}
F_137 ( V_90 ) ;
continue;
}
V_5 = F_16 ( V_90 , V_176 ) ;
if ( V_5 ) {
F_137 ( V_90 ) ;
return V_5 ;
}
F_131 ( * V_166 <= 0 ) ;
if ( V_33 -> V_51 [ * V_166 - 1 ] )
F_137 ( V_33 -> V_51 [ * V_166 - 1 ] ) ;
V_33 -> V_51 [ * V_166 - 1 ] = V_90 ;
* V_166 = F_19 ( V_90 ) ;
V_33 -> V_52 [ * V_166 ] = 0 ;
F_143 () ;
}
F_131 ( * V_166 < 0 ) ;
F_131 ( * V_166 >= V_180 ) ;
V_33 -> V_52 [ * V_166 ] = F_124 ( V_33 -> V_51 [ * V_166 ] ) ;
F_143 () ;
return 0 ;
}
static T_2 int F_144 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_32 * V_33 , int * V_166 ,
struct V_22 * V_23 )
{
T_1 V_174 ;
int V_167 ;
int V_34 ;
int V_5 ;
for ( V_167 = * V_166 ; V_167 < V_180 - 1 && V_33 -> V_51 [ V_167 ] ; V_167 ++ ) {
V_34 = V_33 -> V_52 [ V_167 ] ;
if ( V_34 + 1 < F_124 ( V_33 -> V_51 [ V_167 ] ) ) {
V_33 -> V_52 [ V_167 ] ++ ;
* V_166 = V_167 ;
F_131 ( * V_166 == 0 ) ;
return 0 ;
} else {
struct V_20 * V_178 ;
if ( V_33 -> V_51 [ * V_166 ] == V_4 -> V_182 )
V_178 = V_33 -> V_51 [ * V_166 ] ;
else
V_178 = V_33 -> V_51 [ * V_166 + 1 ] ;
V_174 = F_135 ( V_178 ) ;
V_5 = V_23 -> V_181 ( V_4 , V_33 -> V_51 [ * V_166 ] , V_23 ,
F_145 ( V_33 -> V_51 [ * V_166 ] ) ) ;
if ( V_5 )
return V_5 ;
if ( V_23 -> free ) {
struct V_20 * V_90 ;
V_90 = V_33 -> V_51 [ * V_166 ] ;
if ( V_2 ) {
F_138 ( V_90 ) ;
F_139 ( V_90 ) ;
F_140 ( V_2 , V_4 , V_90 ) ;
F_22 ( V_90 ) ;
F_141 ( V_90 ) ;
}
F_131 ( V_174 != V_47 ) ;
V_5 = F_142 ( V_4 ,
V_33 -> V_51 [ * V_166 ] -> V_28 ,
V_33 -> V_51 [ * V_166 ] -> V_29 ) ;
if ( V_5 )
return V_5 ;
}
F_137 ( V_33 -> V_51 [ * V_166 ] ) ;
V_33 -> V_51 [ * V_166 ] = NULL ;
* V_166 = V_167 + 1 ;
}
}
return 1 ;
}
static int F_146 ( struct V_1 * V_2 ,
struct V_3 * log , struct V_22 * V_23 )
{
int V_5 = 0 ;
int V_183 ;
int V_166 ;
struct V_32 * V_33 ;
int V_184 ;
V_33 = F_82 () ;
if ( ! V_33 )
return - V_55 ;
V_166 = F_19 ( log -> V_182 ) ;
V_184 = V_166 ;
V_33 -> V_51 [ V_166 ] = log -> V_182 ;
F_147 ( log -> V_182 ) ;
V_33 -> V_52 [ V_166 ] = 0 ;
while ( 1 ) {
V_183 = F_130 ( V_2 , log , V_33 , & V_166 , V_23 ) ;
if ( V_183 > 0 )
break;
if ( V_183 < 0 ) {
V_5 = V_183 ;
goto V_76;
}
V_183 = F_144 ( V_2 , log , V_33 , & V_166 , V_23 ) ;
if ( V_183 > 0 )
break;
if ( V_183 < 0 ) {
V_5 = V_183 ;
goto V_76;
}
}
if ( V_33 -> V_51 [ V_184 ] ) {
V_5 = V_23 -> V_181 ( log , V_33 -> V_51 [ V_184 ] , V_23 ,
F_145 ( V_33 -> V_51 [ V_184 ] ) ) ;
if ( V_5 )
goto V_76;
if ( V_23 -> free ) {
struct V_20 * V_90 ;
V_90 = V_33 -> V_51 [ V_184 ] ;
if ( V_2 ) {
F_138 ( V_90 ) ;
F_139 ( V_90 ) ;
F_140 ( V_2 , log , V_90 ) ;
F_22 ( V_90 ) ;
F_141 ( V_90 ) ;
}
F_131 ( log -> V_45 . V_46 !=
V_47 ) ;
V_5 = F_142 ( log , V_90 -> V_28 ,
V_90 -> V_29 ) ;
if ( V_5 )
goto V_76;
}
}
V_76:
F_86 ( V_33 ) ;
return V_5 ;
}
static int F_148 ( struct V_1 * V_2 ,
struct V_3 * log )
{
int V_5 ;
if ( log -> V_185 == 1 ) {
V_5 = F_149 ( V_2 , log -> V_15 -> V_17 ,
& log -> V_45 , & log -> V_186 ) ;
} else {
V_5 = F_150 ( V_2 , log -> V_15 -> V_17 ,
& log -> V_45 , & log -> V_186 ) ;
}
return V_5 ;
}
static int F_151 ( struct V_1 * V_2 ,
struct V_3 * V_4 , unsigned long V_65 )
{
F_152 ( V_31 ) ;
int V_100 = V_65 % 2 ;
do {
F_153 ( & V_4 -> V_187 [ V_100 ] ,
& V_31 , V_188 ) ;
F_4 ( & V_4 -> V_7 ) ;
if ( V_4 -> V_15 -> V_189 !=
V_2 -> V_65 && V_4 -> V_185 < V_65 + 2 &&
F_154 ( & V_4 -> V_190 [ V_100 ] ) )
F_155 () ;
F_156 ( & V_4 -> V_187 [ V_100 ] , & V_31 ) ;
F_2 ( & V_4 -> V_7 ) ;
} while ( V_4 -> V_15 -> V_189 !=
V_2 -> V_65 && V_4 -> V_185 < V_65 + 2 &&
F_154 ( & V_4 -> V_190 [ V_100 ] ) );
return 0 ;
}
static void F_157 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_152 ( V_31 ) ;
while ( V_4 -> V_15 -> V_189 !=
V_2 -> V_65 && F_154 ( & V_4 -> V_14 ) ) {
F_153 ( & V_4 -> V_19 ,
& V_31 , V_188 ) ;
F_4 ( & V_4 -> V_7 ) ;
if ( V_4 -> V_15 -> V_189 !=
V_2 -> V_65 && F_154 ( & V_4 -> V_14 ) )
F_155 () ;
F_2 ( & V_4 -> V_7 ) ;
F_156 ( & V_4 -> V_19 , & V_31 ) ;
}
}
int F_158 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_191 ;
int V_192 ;
int V_193 ;
int V_5 ;
struct V_3 * log = V_4 -> V_8 ;
struct V_3 * V_17 = V_4 -> V_15 -> V_17 ;
unsigned long V_185 = 0 ;
struct V_194 V_195 ;
F_2 ( & V_4 -> V_7 ) ;
V_185 = V_4 -> V_185 ;
V_191 = V_4 -> V_185 % 2 ;
if ( F_154 ( & V_4 -> V_190 [ V_191 ] ) ) {
F_151 ( V_2 , V_4 , V_4 -> V_185 ) ;
F_4 ( & V_4 -> V_7 ) ;
return 0 ;
}
F_159 ( & V_4 -> V_190 [ V_191 ] , 1 ) ;
if ( F_154 ( & V_4 -> V_190 [ ( V_191 + 1 ) % 2 ] ) )
F_151 ( V_2 , V_4 , V_4 -> V_185 - 1 ) ;
while ( 1 ) {
int V_196 = F_154 ( & V_4 -> V_13 ) ;
if ( ! F_160 ( V_4 , V_197 ) && V_4 -> V_12 ) {
F_4 ( & V_4 -> V_7 ) ;
F_161 ( 1 ) ;
F_2 ( & V_4 -> V_7 ) ;
}
F_157 ( V_2 , V_4 ) ;
if ( V_196 == F_154 ( & V_4 -> V_13 ) )
break;
}
if ( V_4 -> V_15 -> V_189 == V_2 -> V_65 ) {
V_5 = - V_198 ;
F_162 ( log , V_185 ) ;
F_4 ( & V_4 -> V_7 ) ;
goto V_76;
}
if ( V_185 % 2 == 0 )
V_193 = V_199 ;
else
V_193 = V_200 ;
F_163 ( & V_195 ) ;
V_5 = F_164 ( log , & log -> V_201 , V_193 ) ;
if ( V_5 ) {
F_165 ( & V_195 ) ;
F_166 ( V_2 , V_4 , V_5 ) ;
F_162 ( log , V_185 ) ;
F_4 ( & V_4 -> V_7 ) ;
goto V_76;
}
F_167 ( & log -> V_186 , log -> V_182 ) ;
V_4 -> V_185 ++ ;
log -> V_185 = V_4 -> V_185 ;
V_4 -> V_9 = 0 ;
F_8 () ;
F_4 ( & V_4 -> V_7 ) ;
F_2 ( & V_17 -> V_7 ) ;
F_3 ( & V_17 -> V_13 ) ;
F_3 ( & V_17 -> V_14 ) ;
F_4 ( & V_17 -> V_7 ) ;
V_5 = F_148 ( V_2 , log ) ;
F_2 ( & V_17 -> V_7 ) ;
if ( F_11 ( & V_17 -> V_14 ) ) {
F_8 () ;
if ( F_12 ( & V_17 -> V_19 ) )
F_13 ( & V_17 -> V_19 ) ;
}
if ( V_5 ) {
F_165 ( & V_195 ) ;
if ( V_5 != - V_202 ) {
F_166 ( V_2 , V_4 , V_5 ) ;
F_4 ( & V_17 -> V_7 ) ;
goto V_76;
}
V_4 -> V_15 -> V_189 = V_2 -> V_65 ;
F_168 ( log , & log -> V_201 , V_193 ) ;
F_162 ( log , V_185 ) ;
F_4 ( & V_17 -> V_7 ) ;
V_5 = - V_198 ;
goto V_76;
}
V_192 = V_17 -> V_185 % 2 ;
if ( F_154 ( & V_17 -> V_190 [ V_192 ] ) ) {
F_165 ( & V_195 ) ;
F_168 ( log , & log -> V_201 , V_193 ) ;
F_151 ( V_2 , V_17 ,
V_17 -> V_185 ) ;
F_162 ( log , V_185 ) ;
F_4 ( & V_17 -> V_7 ) ;
V_5 = 0 ;
goto V_76;
}
F_159 ( & V_17 -> V_190 [ V_192 ] , 1 ) ;
if ( F_154 ( & V_17 -> V_190 [ ( V_192 + 1 ) % 2 ] ) ) {
F_151 ( V_2 , V_17 ,
V_17 -> V_185 - 1 ) ;
}
F_157 ( V_2 , V_17 ) ;
if ( V_4 -> V_15 -> V_189 == V_2 -> V_65 ) {
F_165 ( & V_195 ) ;
F_168 ( log , & log -> V_201 , V_193 ) ;
F_162 ( log , V_185 ) ;
F_4 ( & V_17 -> V_7 ) ;
V_5 = - V_198 ;
goto V_203;
}
V_5 = F_164 ( V_17 ,
& V_17 -> V_201 ,
V_199 | V_200 ) ;
F_165 ( & V_195 ) ;
if ( V_5 ) {
F_166 ( V_2 , V_4 , V_5 ) ;
F_162 ( log , V_185 ) ;
F_4 ( & V_17 -> V_7 ) ;
goto V_203;
}
F_168 ( log , & log -> V_201 , V_193 ) ;
F_168 ( V_17 ,
& V_17 -> V_201 ,
V_200 | V_199 ) ;
F_169 ( log , V_185 ) ;
F_170 ( V_4 -> V_15 -> V_204 ,
V_17 -> V_182 -> V_28 ) ;
F_171 ( V_4 -> V_15 -> V_204 ,
F_19 ( V_17 -> V_182 ) ) ;
V_17 -> V_185 ++ ;
F_8 () ;
F_4 ( & V_17 -> V_7 ) ;
V_5 = F_172 ( V_2 , V_4 -> V_15 -> V_205 , 1 ) ;
if ( V_5 ) {
F_166 ( V_2 , V_4 , V_5 ) ;
goto V_203;
}
F_2 ( & V_4 -> V_7 ) ;
if ( V_4 -> V_206 < V_185 )
V_4 -> V_206 = V_185 ;
F_4 ( & V_4 -> V_7 ) ;
V_203:
F_159 ( & V_17 -> V_190 [ V_192 ] , 0 ) ;
F_8 () ;
if ( F_12 ( & V_17 -> V_187 [ V_192 ] ) )
F_13 ( & V_17 -> V_187 [ V_192 ] ) ;
V_76:
F_159 ( & V_4 -> V_190 [ V_191 ] , 0 ) ;
F_8 () ;
if ( F_12 ( & V_4 -> V_187 [ V_191 ] ) )
F_13 ( & V_4 -> V_187 [ V_191 ] ) ;
return V_5 ;
}
static void F_173 ( struct V_1 * V_2 ,
struct V_3 * log )
{
int V_5 ;
T_1 V_28 ;
T_1 V_207 ;
struct V_22 V_23 = {
. free = 1 ,
. V_181 = F_14
} ;
V_5 = F_146 ( V_2 , log , & V_23 ) ;
if ( V_5 )
F_166 ( V_2 , log , V_5 ) ;
while ( 1 ) {
V_5 = F_174 ( & log -> V_201 ,
0 , & V_28 , & V_207 , V_199 | V_200 ,
NULL ) ;
if ( V_5 )
break;
F_175 ( & log -> V_201 , V_28 , V_207 ,
V_199 | V_200 , V_54 ) ;
}
F_162 ( log , 0 ) ;
F_162 ( log , 1 ) ;
F_137 ( log -> V_182 ) ;
F_29 ( log ) ;
}
int F_176 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( V_4 -> V_8 ) {
F_173 ( V_2 , V_4 -> V_8 ) ;
V_4 -> V_8 = NULL ;
}
return 0 ;
}
int F_177 ( struct V_1 * V_2 ,
struct V_208 * V_15 )
{
if ( V_15 -> V_17 ) {
F_173 ( V_2 , V_15 -> V_17 ) ;
V_15 -> V_17 = NULL ;
}
return 0 ;
}
int F_178 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_96 , int V_97 ,
struct V_70 * V_93 , T_1 V_100 )
{
struct V_3 * log ;
struct V_94 * V_95 ;
struct V_32 * V_33 ;
int V_5 ;
int V_6 = 0 ;
int V_209 = 0 ;
T_1 V_210 = F_54 ( V_93 ) ;
if ( F_109 ( V_93 ) -> V_211 < V_2 -> V_65 )
return 0 ;
V_5 = F_7 ( V_4 ) ;
if ( V_5 )
return 0 ;
F_2 ( & F_109 ( V_93 ) -> V_7 ) ;
log = V_4 -> V_8 ;
V_33 = F_82 () ;
if ( ! V_33 ) {
V_6 = - V_55 ;
goto V_212;
}
V_95 = F_80 ( V_2 , log , V_33 , V_210 ,
V_96 , V_97 , - 1 ) ;
if ( F_79 ( V_95 ) ) {
V_6 = F_127 ( V_95 ) ;
goto V_213;
}
if ( V_95 ) {
V_5 = F_179 ( V_2 , log , V_33 , V_95 ) ;
V_209 += V_97 ;
if ( V_5 ) {
V_6 = V_5 ;
goto V_213;
}
}
F_27 ( V_33 ) ;
V_95 = F_78 ( V_2 , log , V_33 , V_210 ,
V_100 , V_96 , V_97 , - 1 ) ;
if ( F_79 ( V_95 ) ) {
V_6 = F_127 ( V_95 ) ;
goto V_213;
}
if ( V_95 ) {
V_5 = F_179 ( V_2 , log , V_33 , V_95 ) ;
V_209 += V_97 ;
if ( V_5 ) {
V_6 = V_5 ;
goto V_213;
}
}
if ( V_209 ) {
struct V_35 V_36 ;
V_36 . V_46 = V_210 ;
V_36 . V_68 = 0 ;
V_36 . type = V_44 ;
F_27 ( V_33 ) ;
V_5 = F_26 ( V_2 , log , & V_36 , V_33 , 0 , 1 ) ;
if ( V_5 < 0 ) {
V_6 = V_5 ;
goto V_213;
}
if ( V_5 == 0 ) {
struct V_56 * V_57 ;
T_1 V_149 ;
V_57 = F_31 ( V_33 -> V_51 [ 0 ] , V_33 -> V_52 [ 0 ] ,
struct V_56 ) ;
V_149 = F_41 ( V_33 -> V_51 [ 0 ] , V_57 ) ;
if ( V_149 > V_209 )
V_149 -= V_209 ;
else
V_149 = 0 ;
F_36 ( V_33 -> V_51 [ 0 ] , V_57 , V_149 ) ;
F_44 ( V_33 -> V_51 [ 0 ] ) ;
} else
V_5 = 0 ;
F_27 ( V_33 ) ;
}
V_213:
F_86 ( V_33 ) ;
V_212:
F_4 ( & F_109 ( V_93 ) -> V_7 ) ;
if ( V_5 == - V_202 ) {
V_4 -> V_15 -> V_189 = V_2 -> V_65 ;
V_5 = 0 ;
} else if ( V_5 < 0 )
F_166 ( V_2 , V_4 , V_5 ) ;
F_10 ( V_4 ) ;
return V_6 ;
}
int F_180 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_96 , int V_97 ,
struct V_70 * V_70 , T_1 V_99 )
{
struct V_3 * log ;
T_1 V_100 ;
int V_5 ;
if ( F_109 ( V_70 ) -> V_211 < V_2 -> V_65 )
return 0 ;
V_5 = F_7 ( V_4 ) ;
if ( V_5 )
return 0 ;
log = V_4 -> V_8 ;
F_2 ( & F_109 ( V_70 ) -> V_7 ) ;
V_5 = F_181 ( V_2 , log , V_96 , V_97 , F_54 ( V_70 ) ,
V_99 , & V_100 ) ;
F_4 ( & F_109 ( V_70 ) -> V_7 ) ;
if ( V_5 == - V_202 ) {
V_4 -> V_15 -> V_189 = V_2 -> V_65 ;
V_5 = 0 ;
} else if ( V_5 < 0 && V_5 != - V_18 )
F_166 ( V_2 , V_4 , V_5 ) ;
F_10 ( V_4 ) ;
return V_5 ;
}
static T_2 int F_182 ( struct V_1 * V_2 ,
struct V_3 * log ,
struct V_32 * V_33 ,
int V_150 , T_1 V_99 ,
T_1 V_214 , T_1 V_215 )
{
int V_5 ;
struct V_35 V_36 ;
struct V_154 * V_57 ;
V_36 . V_46 = V_99 ;
V_36 . V_68 = V_214 ;
if ( V_150 == V_147 )
V_36 . type = V_162 ;
else
V_36 . type = V_164 ;
V_5 = F_37 ( V_2 , log , V_33 , & V_36 , sizeof( * V_57 ) ) ;
if ( V_5 )
return V_5 ;
V_57 = F_31 ( V_33 -> V_51 [ 0 ] , V_33 -> V_52 [ 0 ] ,
struct V_154 ) ;
F_183 ( V_33 -> V_51 [ 0 ] , V_57 , V_215 ) ;
F_44 ( V_33 -> V_51 [ 0 ] ) ;
F_27 ( V_33 ) ;
return 0 ;
}
static T_2 int F_184 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_70 * V_70 ,
struct V_32 * V_33 ,
struct V_32 * V_216 , int V_150 ,
T_1 V_217 , T_1 * V_218 )
{
struct V_35 V_219 ;
struct V_3 * log = V_4 -> V_8 ;
struct V_20 * V_220 ;
int V_6 = 0 ;
int V_5 ;
int V_167 ;
int V_155 ;
T_1 V_214 = V_217 ;
T_1 V_215 = ( T_1 ) - 1 ;
T_1 V_134 = F_54 ( V_70 ) ;
log = V_4 -> V_8 ;
V_219 . V_46 = V_134 ;
V_219 . type = V_150 ;
V_219 . V_68 = V_217 ;
V_33 -> V_221 = 1 ;
V_5 = F_185 ( V_4 , & V_219 , V_33 , V_2 -> V_65 ) ;
if ( V_5 != 0 || V_219 . V_46 != V_134 || V_219 . type != V_150 ) {
V_219 . V_46 = V_134 ;
V_219 . type = V_150 ;
V_219 . V_68 = ( T_1 ) - 1 ;
F_27 ( V_33 ) ;
V_5 = F_26 ( NULL , V_4 , & V_219 , V_33 , 0 , 0 ) ;
if ( V_5 < 0 ) {
F_27 ( V_33 ) ;
return V_5 ;
}
V_5 = F_186 ( V_4 , V_33 , V_134 , V_150 ) ;
if ( V_5 == 0 ) {
struct V_35 V_222 ;
F_106 ( V_33 -> V_51 [ 0 ] , & V_222 ,
V_33 -> V_52 [ 0 ] ) ;
if ( V_150 == V_222 . type )
V_214 = F_187 ( V_217 , V_222 . V_68 ) + 1 ;
}
goto V_223;
}
V_5 = F_186 ( V_4 , V_33 , V_134 , V_150 ) ;
if ( V_5 == 0 ) {
struct V_35 V_222 ;
F_106 ( V_33 -> V_51 [ 0 ] , & V_222 , V_33 -> V_52 [ 0 ] ) ;
if ( V_150 == V_222 . type ) {
V_214 = V_222 . V_68 ;
V_5 = F_23 ( V_2 , log , V_216 ,
V_33 -> V_51 [ 0 ] , V_33 -> V_52 [ 0 ] ,
& V_222 ) ;
if ( V_5 ) {
V_6 = V_5 ;
goto V_223;
}
}
}
F_27 ( V_33 ) ;
V_5 = F_26 ( NULL , V_4 , & V_219 , V_33 , 0 , 0 ) ;
if ( F_131 ( V_5 != 0 ) )
goto V_223;
while ( 1 ) {
struct V_35 V_222 ;
V_220 = V_33 -> V_51 [ 0 ] ;
V_155 = F_124 ( V_220 ) ;
for ( V_167 = V_33 -> V_52 [ 0 ] ; V_167 < V_155 ; V_167 ++ ) {
F_106 ( V_220 , & V_219 , V_167 ) ;
if ( V_219 . V_46 != V_134 || V_219 . type != V_150 )
goto V_223;
V_5 = F_23 ( V_2 , log , V_216 , V_220 , V_167 ,
& V_219 ) ;
if ( V_5 ) {
V_6 = V_5 ;
goto V_223;
}
}
V_33 -> V_52 [ 0 ] = V_155 ;
V_5 = F_125 ( V_4 , V_33 ) ;
if ( V_5 == 1 ) {
V_215 = ( T_1 ) - 1 ;
goto V_223;
}
F_106 ( V_33 -> V_51 [ 0 ] , & V_222 , V_33 -> V_52 [ 0 ] ) ;
if ( V_222 . V_46 != V_134 || V_222 . type != V_150 ) {
V_215 = ( T_1 ) - 1 ;
goto V_223;
}
if ( F_145 ( V_33 -> V_51 [ 0 ] ) != V_2 -> V_65 ) {
V_5 = F_23 ( V_2 , log , V_216 ,
V_33 -> V_51 [ 0 ] , V_33 -> V_52 [ 0 ] ,
& V_222 ) ;
if ( V_5 )
V_6 = V_5 ;
else
V_215 = V_222 . V_68 ;
goto V_223;
}
}
V_223:
F_27 ( V_33 ) ;
F_27 ( V_216 ) ;
if ( V_6 == 0 ) {
* V_218 = V_215 ;
V_5 = F_182 ( V_2 , log , V_33 , V_150 ,
V_134 , V_214 , V_215 ) ;
if ( V_5 )
V_6 = V_5 ;
}
return V_6 ;
}
static T_2 int F_188 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_70 * V_70 ,
struct V_32 * V_33 ,
struct V_32 * V_216 )
{
T_1 V_219 ;
T_1 V_224 ;
int V_5 ;
int V_150 = V_147 ;
V_120:
V_219 = 0 ;
V_224 = 0 ;
while ( 1 ) {
V_5 = F_184 ( V_2 , V_4 , V_70 , V_33 ,
V_216 , V_150 , V_219 ,
& V_224 ) ;
if ( V_5 )
return V_5 ;
if ( V_224 == ( T_1 ) - 1 )
break;
V_219 = V_224 + 1 ;
}
if ( V_150 == V_147 ) {
V_150 = V_146 ;
goto V_120;
}
return 0 ;
}
static int F_189 ( struct V_1 * V_2 ,
struct V_3 * log ,
struct V_32 * V_33 ,
T_1 V_46 , int V_225 )
{
int V_5 ;
struct V_35 V_36 ;
struct V_35 V_141 ;
int V_226 ;
V_36 . V_46 = V_46 ;
V_36 . type = V_225 ;
V_36 . V_68 = ( T_1 ) - 1 ;
while ( 1 ) {
V_5 = F_26 ( V_2 , log , & V_36 , V_33 , - 1 , 1 ) ;
F_190 ( V_5 == 0 ) ;
if ( V_5 < 0 )
break;
if ( V_33 -> V_52 [ 0 ] == 0 )
break;
V_33 -> V_52 [ 0 ] -- ;
F_106 ( V_33 -> V_51 [ 0 ] , & V_141 ,
V_33 -> V_52 [ 0 ] ) ;
if ( V_141 . V_46 != V_46 )
break;
V_141 . V_68 = 0 ;
V_141 . type = 0 ;
V_5 = F_191 ( V_33 -> V_51 [ 0 ] , & V_141 , 0 ,
& V_226 ) ;
V_5 = F_192 ( V_2 , log , V_33 , V_226 ,
V_33 -> V_52 [ 0 ] - V_226 + 1 ) ;
if ( V_5 || V_226 != 0 )
break;
F_27 ( V_33 ) ;
}
F_27 ( V_33 ) ;
if ( V_5 > 0 )
V_5 = 0 ;
return V_5 ;
}
static void F_193 ( struct V_1 * V_2 ,
struct V_20 * V_81 ,
struct V_56 * V_57 ,
struct V_70 * V_70 , int V_227 )
{
struct V_228 V_229 ;
F_194 ( & V_229 ) ;
if ( V_227 ) {
F_195 ( V_81 , V_57 , 0 , & V_229 ) ;
F_196 ( V_81 , V_57 , 0 , & V_229 ) ;
} else {
F_195 ( V_81 , V_57 ,
F_109 ( V_70 ) -> V_230 ,
& V_229 ) ;
F_196 ( V_81 , V_57 , V_70 -> V_149 , & V_229 ) ;
}
F_197 ( V_81 , V_57 , F_198 ( V_70 ) , & V_229 ) ;
F_199 ( V_81 , V_57 , F_200 ( V_70 ) , & V_229 ) ;
F_201 ( V_81 , V_57 , V_70 -> V_138 , & V_229 ) ;
F_202 ( V_81 , V_57 , V_70 -> V_136 , & V_229 ) ;
F_203 ( V_81 , F_204 ( V_57 ) ,
V_70 -> V_231 . V_232 , & V_229 ) ;
F_205 ( V_81 , F_204 ( V_57 ) ,
V_70 -> V_231 . V_233 , & V_229 ) ;
F_203 ( V_81 , F_206 ( V_57 ) ,
V_70 -> V_234 . V_232 , & V_229 ) ;
F_205 ( V_81 , F_206 ( V_57 ) ,
V_70 -> V_234 . V_233 , & V_229 ) ;
F_203 ( V_81 , F_207 ( V_57 ) ,
V_70 -> V_235 . V_232 , & V_229 ) ;
F_205 ( V_81 , F_207 ( V_57 ) ,
V_70 -> V_235 . V_233 , & V_229 ) ;
F_208 ( V_81 , V_57 , F_209 ( V_70 ) ,
& V_229 ) ;
F_210 ( V_81 , V_57 , V_70 -> V_236 , & V_229 ) ;
F_211 ( V_81 , V_57 , V_2 -> V_65 , & V_229 ) ;
F_212 ( V_81 , V_57 , V_70 -> V_237 , & V_229 ) ;
F_213 ( V_81 , V_57 , F_109 ( V_70 ) -> V_238 , & V_229 ) ;
F_214 ( V_81 , V_57 , 0 , & V_229 ) ;
}
static int F_215 ( struct V_1 * V_2 ,
struct V_3 * log , struct V_32 * V_33 ,
struct V_70 * V_70 )
{
struct V_56 * V_43 ;
int V_5 ;
V_5 = F_37 ( V_2 , log , V_33 ,
& F_109 ( V_70 ) -> V_98 ,
sizeof( * V_43 ) ) ;
if ( V_5 && V_5 != - V_60 )
return V_5 ;
V_43 = F_31 ( V_33 -> V_51 [ 0 ] , V_33 -> V_52 [ 0 ] ,
struct V_56 ) ;
F_193 ( V_2 , V_33 -> V_51 [ 0 ] , V_43 , V_70 , 0 ) ;
F_27 ( V_33 ) ;
return 0 ;
}
static T_2 int F_216 ( struct V_1 * V_2 ,
struct V_70 * V_70 ,
struct V_32 * V_216 ,
struct V_32 * V_239 , T_1 * V_240 ,
int V_226 , int V_241 , int V_242 )
{
unsigned long V_243 ;
unsigned long V_244 ;
struct V_3 * log = F_109 ( V_70 ) -> V_4 -> V_8 ;
struct V_69 * V_245 ;
struct V_56 * V_43 ;
struct V_20 * V_220 = V_239 -> V_51 [ 0 ] ;
struct V_35 V_246 , V_247 , V_36 ;
int V_5 ;
struct V_35 * V_248 ;
T_3 * V_249 ;
char * V_250 ;
int V_167 ;
struct V_251 V_87 ;
int V_252 = F_109 ( V_70 ) -> V_238 & V_253 ;
bool V_254 = false ;
bool V_255 = ( * V_240 == 0 ) ;
bool V_223 = false ;
F_217 ( & V_87 ) ;
V_250 = F_28 ( V_241 * sizeof( struct V_35 ) +
V_241 * sizeof( T_3 ) , V_54 ) ;
if ( ! V_250 )
return - V_55 ;
V_246 . V_46 = ( T_1 ) - 1 ;
V_249 = ( T_3 * ) V_250 ;
V_248 = (struct V_35 * ) ( V_250 + V_241 * sizeof( T_3 ) ) ;
for ( V_167 = 0 ; V_167 < V_241 ; V_167 ++ ) {
V_249 [ V_167 ] = F_24 ( V_220 , V_167 + V_226 ) ;
F_106 ( V_220 , V_248 + V_167 , V_167 + V_226 ) ;
}
V_5 = F_218 ( V_2 , log , V_216 ,
V_248 , V_249 , V_241 ) ;
if ( V_5 ) {
F_29 ( V_250 ) ;
return V_5 ;
}
for ( V_167 = 0 ; V_167 < V_241 ; V_167 ++ , V_216 -> V_52 [ 0 ] ++ ) {
V_244 = F_25 ( V_216 -> V_51 [ 0 ] ,
V_216 -> V_52 [ 0 ] ) ;
V_243 = F_25 ( V_220 , V_226 + V_167 ) ;
if ( ( V_167 == ( V_241 - 1 ) ) )
V_247 = V_248 [ V_167 ] ;
if ( V_248 [ V_167 ] . type == V_44 ) {
V_43 = F_31 ( V_216 -> V_51 [ 0 ] ,
V_216 -> V_52 [ 0 ] ,
struct V_56 ) ;
F_193 ( V_2 , V_216 -> V_51 [ 0 ] , V_43 ,
V_70 , V_242 == V_256 ) ;
} else {
F_42 ( V_216 -> V_51 [ 0 ] , V_220 , V_244 ,
V_243 , V_249 [ V_167 ] ) ;
}
if ( V_248 [ V_167 ] . type == V_173 ) {
V_254 = true ;
if ( V_255 &&
V_246 . V_46 == ( T_1 ) - 1 )
V_246 = V_248 [ V_167 ] ;
} else {
V_255 = false ;
}
if ( F_219 ( V_248 + V_167 ) == V_173 &&
! V_252 ) {
int V_66 ;
V_245 = F_31 ( V_220 , V_226 + V_167 ,
struct V_69 ) ;
if ( F_220 ( V_220 , V_245 ) < V_2 -> V_65 )
continue;
V_66 = F_46 ( V_220 , V_245 ) ;
if ( V_66 == V_72 ) {
T_1 V_257 , V_258 , V_259 , V_260 ;
V_257 = F_48 ( V_220 ,
V_245 ) ;
if ( V_257 == 0 )
continue;
V_258 = F_56 ( V_220 ,
V_245 ) ;
V_259 = F_57 ( V_220 , V_245 ) ;
V_260 = F_47 ( V_220 ,
V_245 ) ;
if ( F_62 ( V_220 ,
V_245 ) ) {
V_259 = 0 ;
V_260 = V_258 ;
}
V_5 = F_63 (
log -> V_15 -> V_92 ,
V_257 + V_259 , V_257 + V_259 + V_260 - 1 ,
& V_87 , 0 ) ;
if ( V_5 ) {
F_27 ( V_216 ) ;
F_29 ( V_250 ) ;
return V_5 ;
}
}
}
}
F_44 ( V_216 -> V_51 [ 0 ] ) ;
F_27 ( V_216 ) ;
F_29 ( V_250 ) ;
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
if ( ! V_254 )
return V_5 ;
if ( V_255 ) {
T_1 V_29 ;
V_5 = F_221 ( F_109 ( V_70 ) -> V_4 , V_239 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( V_5 )
goto V_261;
if ( V_239 -> V_52 [ 0 ] )
V_239 -> V_52 [ 0 ] -- ;
V_220 = V_239 -> V_51 [ 0 ] ;
F_106 ( V_220 , & V_36 , V_239 -> V_52 [ 0 ] ) ;
if ( V_36 . V_46 != F_54 ( V_70 ) ||
V_36 . type != V_173 )
goto V_261;
V_245 = F_31 ( V_220 , V_239 -> V_52 [ 0 ] ,
struct V_69 ) ;
if ( F_46 ( V_220 , V_245 ) ==
V_74 ) {
V_29 = F_49 ( V_220 ,
V_239 -> V_52 [ 0 ] ,
V_245 ) ;
* V_240 = F_51 ( V_36 . V_68 + V_29 ,
log -> V_75 ) ;
} else {
V_29 = F_47 ( V_220 , V_245 ) ;
* V_240 = V_36 . V_68 + V_29 ;
}
}
V_261:
if ( V_255 ) {
F_27 ( V_239 ) ;
V_5 = F_26 ( NULL , F_109 ( V_70 ) -> V_4 , & V_246 ,
V_239 , 0 , 0 ) ;
if ( V_5 < 0 )
return V_5 ;
ASSERT ( V_5 == 0 ) ;
V_220 = V_239 -> V_51 [ 0 ] ;
V_167 = V_239 -> V_52 [ 0 ] ;
} else {
V_167 = V_226 ;
}
while ( ! V_223 ) {
T_1 V_68 , V_29 ;
T_1 V_67 ;
if ( V_167 >= F_124 ( V_239 -> V_51 [ 0 ] ) ) {
V_5 = F_125 ( F_109 ( V_70 ) -> V_4 , V_239 ) ;
if ( V_5 < 0 )
return V_5 ;
ASSERT ( V_5 == 0 ) ;
V_220 = V_239 -> V_51 [ 0 ] ;
V_167 = 0 ;
}
F_106 ( V_220 , & V_36 , V_167 ) ;
if ( ! F_222 ( & V_36 , & V_247 ) )
V_223 = true ;
if ( V_36 . V_46 != F_54 ( V_70 ) ||
V_36 . type != V_173 ) {
V_167 ++ ;
continue;
}
V_245 = F_31 ( V_220 , V_167 , struct V_69 ) ;
if ( F_46 ( V_220 , V_245 ) ==
V_74 ) {
V_29 = F_49 ( V_220 , V_167 , V_245 ) ;
V_67 = F_51 ( V_36 . V_68 + V_29 , log -> V_75 ) ;
} else {
V_29 = F_47 ( V_220 , V_245 ) ;
V_67 = V_36 . V_68 + V_29 ;
}
V_167 ++ ;
if ( * V_240 == V_36 . V_68 ) {
* V_240 = V_67 ;
continue;
}
V_68 = * V_240 ;
V_29 = V_36 . V_68 - * V_240 ;
V_5 = F_223 ( V_2 , log , F_54 ( V_70 ) ,
V_68 , 0 , 0 , V_29 , 0 , V_29 , 0 ,
0 , 0 ) ;
if ( V_5 )
break;
* V_240 = V_68 + V_29 ;
}
if ( ! V_5 && V_255 )
V_5 = 1 ;
return V_5 ;
}
static int F_224 ( void * V_262 , struct V_251 * V_263 , struct V_251 * V_264 )
{
struct V_265 * V_266 , * V_267 ;
V_266 = F_65 ( V_263 , struct V_265 , V_91 ) ;
V_267 = F_65 ( V_264 , struct V_265 , V_91 ) ;
if ( V_266 -> V_28 < V_267 -> V_28 )
return - 1 ;
else if ( V_266 -> V_28 > V_267 -> V_28 )
return 1 ;
return 0 ;
}
static int F_225 ( struct V_1 * V_2 ,
struct V_70 * V_70 , struct V_3 * V_4 ,
struct V_265 * V_268 , struct V_32 * V_33 )
{
struct V_3 * log = V_4 -> V_8 ;
struct V_69 * V_269 ;
struct V_20 * V_81 ;
struct V_270 * V_271 ;
struct V_251 V_87 ;
struct V_228 V_229 ;
struct V_35 V_36 ;
T_1 V_272 = V_268 -> V_272 ;
T_1 V_273 = V_268 -> V_273 ;
T_1 V_274 ;
T_1 V_275 ;
T_1 V_276 = V_268 -> V_28 - V_268 -> V_277 ;
T_1 V_278 ;
int V_5 ;
int V_100 = log -> V_185 % 2 ;
bool V_252 = F_109 ( V_70 ) -> V_238 & V_253 ;
int V_279 = 0 ;
F_217 ( & V_87 ) ;
F_194 ( & V_229 ) ;
V_5 = F_226 ( V_2 , log , V_70 , V_33 , V_268 -> V_28 ,
V_268 -> V_28 + V_268 -> V_29 , NULL , 0 , 1 ,
sizeof( * V_269 ) , & V_279 ) ;
if ( V_5 )
return V_5 ;
if ( ! V_279 ) {
V_36 . V_46 = F_54 ( V_70 ) ;
V_36 . type = V_173 ;
V_36 . V_68 = V_268 -> V_28 ;
V_5 = F_37 ( V_2 , log , V_33 , & V_36 ,
sizeof( * V_269 ) ) ;
if ( V_5 )
return V_5 ;
}
V_81 = V_33 -> V_51 [ 0 ] ;
V_269 = F_31 ( V_81 , V_33 -> V_52 [ 0 ] ,
struct V_69 ) ;
F_227 ( V_81 , V_269 , V_268 -> V_230 ,
& V_229 ) ;
if ( F_228 ( V_280 , & V_268 -> V_238 ) ) {
V_252 = true ;
F_229 ( V_81 , V_269 ,
V_73 ,
& V_229 ) ;
} else {
F_229 ( V_81 , V_269 ,
V_72 ,
& V_229 ) ;
if ( V_268 -> V_281 == V_282 )
V_252 = true ;
}
V_278 = F_187 ( V_268 -> V_278 , V_268 -> V_283 ) ;
if ( V_268 -> V_284 != V_285 ) {
F_230 ( V_81 , V_269 ,
V_268 -> V_281 ,
& V_229 ) ;
F_231 ( V_81 , V_269 , V_278 ,
& V_229 ) ;
} else if ( V_268 -> V_281 < V_286 ) {
F_230 ( V_81 , V_269 ,
V_268 -> V_281 -
V_276 , & V_229 ) ;
F_231 ( V_81 , V_269 , V_278 ,
& V_229 ) ;
} else {
F_230 ( V_81 , V_269 , 0 , & V_229 ) ;
F_231 ( V_81 , V_269 , 0 ,
& V_229 ) ;
}
F_232 ( V_81 , V_269 ,
V_268 -> V_28 - V_268 -> V_277 ,
& V_229 ) ;
F_233 ( V_81 , V_269 , V_268 -> V_29 , & V_229 ) ;
F_234 ( V_81 , V_269 , V_268 -> V_287 , & V_229 ) ;
F_235 ( V_81 , V_269 , V_268 -> V_284 ,
& V_229 ) ;
F_236 ( V_81 , V_269 , 0 , & V_229 ) ;
F_237 ( V_81 , V_269 , 0 , & V_229 ) ;
F_44 ( V_81 ) ;
F_27 ( V_33 ) ;
if ( V_5 ) {
return V_5 ;
}
if ( V_252 )
return 0 ;
V_120:
F_238 ( & log -> V_288 [ V_100 ] ) ;
F_239 (ordered, &log->logged_list[index], log_list) {
struct V_88 * V_289 ;
if ( ! V_273 )
break;
if ( V_271 -> V_70 != V_70 )
continue;
if ( V_271 -> V_290 + V_271 -> V_29 <= V_272 ||
V_272 + V_273 <= V_271 -> V_290 )
continue;
if ( V_271 -> V_290 > V_272 ) {
if ( V_271 -> V_290 + V_271 -> V_29 >=
V_272 + V_273 )
V_273 = V_271 -> V_290 - V_272 ;
} else {
if ( V_271 -> V_290 + V_271 -> V_29 <
V_272 + V_273 ) {
V_273 = ( V_272 + V_273 ) -
( V_271 -> V_290 + V_271 -> V_29 ) ;
V_272 = V_271 -> V_290 +
V_271 -> V_29 ;
} else {
V_273 = 0 ;
}
}
if ( F_240 ( V_291 ,
& V_271 -> V_238 ) )
continue;
F_3 ( & V_271 -> V_292 ) ;
F_241 ( & log -> V_288 [ V_100 ] ) ;
if ( V_271 -> V_293 ) {
F_242 ( V_70 , V_271 , 0 ) ;
F_243 ( V_271 -> V_31 ,
V_271 -> V_293 == 0 ) ;
}
F_239 (sum, &ordered->list, list) {
V_5 = F_66 ( V_2 , log , V_289 ) ;
if ( V_5 ) {
F_244 ( V_271 ) ;
goto V_294;
}
}
F_244 ( V_271 ) ;
goto V_120;
}
F_241 ( & log -> V_288 [ V_100 ] ) ;
V_294:
if ( ! V_273 || V_5 )
return V_5 ;
if ( V_268 -> V_284 ) {
V_274 = 0 ;
V_275 = V_278 ;
} else {
V_274 = V_272 - V_268 -> V_28 ;
V_275 = V_273 ;
}
V_5 = F_63 ( log -> V_15 -> V_92 ,
V_268 -> V_281 + V_274 ,
V_268 -> V_281 + V_274 +
V_275 - 1 , & V_87 , 0 ) ;
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
static int F_245 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_70 * V_70 ,
struct V_32 * V_33 )
{
struct V_265 * V_268 , * V_295 ;
struct V_251 V_296 ;
struct V_297 * V_298 = & F_109 ( V_70 ) -> V_299 ;
T_1 V_300 ;
int V_5 = 0 ;
int V_301 = 0 ;
F_217 ( & V_296 ) ;
F_246 ( & V_298 -> V_302 ) ;
V_300 = V_4 -> V_15 -> V_303 ;
F_247 (em, n, &tree->modified_extents, list) {
F_248 ( & V_268 -> V_91 ) ;
if ( ++ V_301 > 32768 ) {
F_248 ( & V_298 -> V_304 ) ;
V_5 = - V_305 ;
goto V_306;
}
if ( V_268 -> V_230 <= V_300 )
continue;
F_3 ( & V_268 -> V_292 ) ;
F_249 ( V_307 , & V_268 -> V_238 ) ;
F_250 ( & V_268 -> V_91 , & V_296 ) ;
V_301 ++ ;
}
F_251 ( NULL , & V_296 , F_224 ) ;
V_306:
while ( ! F_64 ( & V_296 ) ) {
V_268 = F_65 ( V_296 . V_90 , struct V_265 , V_91 ) ;
F_248 ( & V_268 -> V_91 ) ;
if ( V_5 ) {
F_252 ( V_298 , V_268 ) ;
F_253 ( V_268 ) ;
continue;
}
F_254 ( & V_298 -> V_302 ) ;
V_5 = F_225 ( V_2 , V_70 , V_4 , V_268 , V_33 ) ;
F_246 ( & V_298 -> V_302 ) ;
F_252 ( V_298 , V_268 ) ;
F_253 ( V_268 ) ;
}
F_131 ( ! F_64 ( & V_296 ) ) ;
F_254 ( & V_298 -> V_302 ) ;
F_27 ( V_33 ) ;
return V_5 ;
}
static int F_255 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_70 * V_70 ,
int V_242 )
{
struct V_32 * V_33 ;
struct V_32 * V_216 ;
struct V_35 V_219 ;
struct V_35 V_224 ;
struct V_3 * log = V_4 -> V_8 ;
struct V_20 * V_220 = NULL ;
T_1 V_240 = 0 ;
int V_6 = 0 ;
int V_5 ;
int V_155 ;
int V_308 = 0 ;
int V_309 ;
bool V_310 = false ;
T_1 V_134 = F_54 ( V_70 ) ;
V_33 = F_82 () ;
if ( ! V_33 )
return - V_55 ;
V_216 = F_82 () ;
if ( ! V_216 ) {
F_86 ( V_33 ) ;
return - V_55 ;
}
V_219 . V_46 = V_134 ;
V_219 . type = V_44 ;
V_219 . V_68 = 0 ;
V_224 . V_46 = V_134 ;
if ( F_35 ( V_70 -> V_138 ) ||
( ! F_228 ( V_311 ,
& F_109 ( V_70 ) -> V_312 ) &&
V_242 == V_256 ) )
V_224 . type = V_172 ;
else
V_224 . type = ( T_4 ) - 1 ;
V_224 . V_68 = ( T_1 ) - 1 ;
if ( F_35 ( V_70 -> V_138 ) ||
F_109 ( V_70 ) -> V_230 > V_4 -> V_15 -> V_303 ) {
V_5 = F_256 ( V_2 , V_70 ) ;
if ( V_5 ) {
F_86 ( V_33 ) ;
F_86 ( V_216 ) ;
return V_5 ;
}
}
F_2 ( & F_109 ( V_70 ) -> V_7 ) ;
F_257 ( log , V_70 ) ;
if ( F_35 ( V_70 -> V_138 ) ) {
int V_225 = V_164 ;
if ( V_242 == V_256 )
V_225 = V_172 ;
V_5 = F_189 ( V_2 , log , V_33 , V_134 , V_225 ) ;
} else {
if ( F_258 ( V_311 ,
& F_109 ( V_70 ) -> V_312 ) ) {
F_259 ( V_313 ,
& F_109 ( V_70 ) -> V_312 ) ;
V_5 = F_260 ( V_2 , log ,
V_70 , 0 , 0 ) ;
} else if ( F_258 ( V_313 ,
& F_109 ( V_70 ) -> V_312 ) ||
V_242 == V_256 ) {
if ( V_242 == V_314 )
V_310 = true ;
V_224 . type = V_172 ;
V_5 = F_189 ( V_2 , log , V_33 , V_134 ,
V_224 . type ) ;
} else {
if ( V_242 == V_314 )
V_310 = true ;
V_5 = F_215 ( V_2 , log , V_216 , V_70 ) ;
if ( V_5 ) {
V_6 = V_5 ;
goto V_212;
}
goto V_315;
}
}
if ( V_5 ) {
V_6 = V_5 ;
goto V_212;
}
V_33 -> V_221 = 1 ;
while ( 1 ) {
V_309 = 0 ;
V_5 = F_185 ( V_4 , & V_219 ,
V_33 , V_2 -> V_65 ) ;
if ( V_5 != 0 )
break;
V_120:
if ( V_219 . V_46 != V_134 )
break;
if ( V_219 . type > V_224 . type )
break;
V_220 = V_33 -> V_51 [ 0 ] ;
if ( V_309 && V_308 + V_309 == V_33 -> V_52 [ 0 ] ) {
V_309 ++ ;
goto V_316;
} else if ( ! V_309 ) {
V_308 = V_33 -> V_52 [ 0 ] ;
V_309 = 1 ;
goto V_316;
}
V_5 = F_216 ( V_2 , V_70 , V_216 , V_33 , & V_240 ,
V_308 , V_309 , V_242 ) ;
if ( V_5 < 0 ) {
V_6 = V_5 ;
goto V_212;
} if ( V_5 ) {
V_309 = 0 ;
F_27 ( V_33 ) ;
continue;
}
V_309 = 1 ;
V_308 = V_33 -> V_52 [ 0 ] ;
V_316:
V_155 = F_124 ( V_33 -> V_51 [ 0 ] ) ;
V_33 -> V_52 [ 0 ] ++ ;
if ( V_33 -> V_52 [ 0 ] < V_155 ) {
F_106 ( V_33 -> V_51 [ 0 ] , & V_219 ,
V_33 -> V_52 [ 0 ] ) ;
goto V_120;
}
if ( V_309 ) {
V_5 = F_216 ( V_2 , V_70 , V_216 , V_33 ,
& V_240 , V_308 ,
V_309 , V_242 ) ;
if ( V_5 < 0 ) {
V_6 = V_5 ;
goto V_212;
}
V_5 = 0 ;
V_309 = 0 ;
}
F_27 ( V_33 ) ;
if ( V_219 . V_68 < ( T_1 ) - 1 ) {
V_219 . V_68 ++ ;
} else if ( V_219 . type < V_224 . type ) {
V_219 . type ++ ;
V_219 . V_68 = 0 ;
} else {
break;
}
}
if ( V_309 ) {
V_5 = F_216 ( V_2 , V_70 , V_216 , V_33 , & V_240 ,
V_308 , V_309 , V_242 ) ;
if ( V_5 < 0 ) {
V_6 = V_5 ;
goto V_212;
}
V_5 = 0 ;
V_309 = 0 ;
}
V_315:
F_27 ( V_33 ) ;
F_27 ( V_216 ) ;
if ( V_310 ) {
V_5 = F_245 ( V_2 , V_4 , V_70 , V_216 ) ;
if ( V_5 ) {
V_6 = V_5 ;
goto V_212;
}
} else if ( V_242 == V_314 ) {
struct V_297 * V_298 = & F_109 ( V_70 ) -> V_299 ;
struct V_265 * V_268 , * V_295 ;
F_246 ( & V_298 -> V_302 ) ;
F_247 (em, n, &tree->modified_extents, list)
F_248 ( & V_268 -> V_91 ) ;
F_254 ( & V_298 -> V_302 ) ;
}
if ( V_242 == V_314 && F_35 ( V_70 -> V_138 ) ) {
V_5 = F_188 ( V_2 , V_4 , V_70 , V_33 , V_216 ) ;
if ( V_5 ) {
V_6 = V_5 ;
goto V_212;
}
}
F_109 ( V_70 ) -> V_211 = V_2 -> V_65 ;
F_109 ( V_70 ) -> V_206 = F_109 ( V_70 ) -> V_317 ;
V_212:
if ( V_6 )
F_162 ( log , log -> V_185 ) ;
F_4 ( & F_109 ( V_70 ) -> V_7 ) ;
F_86 ( V_33 ) ;
F_86 ( V_216 ) ;
return V_6 ;
}
static T_2 int F_261 ( struct V_1 * V_2 ,
struct V_70 * V_70 ,
struct V_318 * V_178 ,
struct V_319 * V_320 ,
T_1 V_321 )
{
int V_5 = 0 ;
struct V_3 * V_4 ;
struct V_318 * V_322 = NULL ;
struct V_70 * V_323 = V_70 ;
if ( F_129 ( V_70 -> V_138 ) &&
F_109 ( V_70 ) -> V_230 <= V_321 &&
F_109 ( V_70 ) -> V_324 <= V_321 )
goto V_76;
if ( ! F_35 ( V_70 -> V_138 ) ) {
if ( ! V_178 || ! V_178 -> V_325 || V_320 != V_178 -> V_325 -> V_326 )
goto V_76;
V_70 = V_178 -> V_325 ;
}
while ( 1 ) {
if ( V_70 != V_323 )
F_109 ( V_70 ) -> V_211 = V_2 -> V_65 ;
F_8 () ;
if ( F_109 ( V_70 ) -> V_324 > V_321 ) {
V_4 = F_109 ( V_70 ) -> V_4 ;
V_4 -> V_15 -> V_189 =
V_2 -> V_65 ;
V_5 = 1 ;
break;
}
if ( ! V_178 || ! V_178 -> V_325 || V_320 != V_178 -> V_325 -> V_326 )
break;
if ( F_262 ( V_178 ) )
break;
V_178 = F_263 ( V_178 ) ;
F_264 ( V_322 ) ;
V_322 = V_178 ;
V_70 = V_178 -> V_325 ;
}
F_264 ( V_322 ) ;
V_76:
return V_5 ;
}
static int F_265 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_70 * V_70 ,
struct V_318 * V_178 , int V_327 )
{
int V_242 = V_327 ? V_256 : V_314 ;
struct V_319 * V_320 ;
struct V_318 * V_322 = NULL ;
int V_5 = 0 ;
T_1 V_321 = V_4 -> V_15 -> V_303 ;
V_320 = V_70 -> V_326 ;
if ( F_160 ( V_4 , V_328 ) ) {
V_5 = 1 ;
goto V_329;
}
if ( V_4 -> V_15 -> V_189 >
V_4 -> V_15 -> V_303 ) {
V_5 = 1 ;
goto V_329;
}
if ( V_4 != F_109 ( V_70 ) -> V_4 ||
F_266 ( & V_4 -> V_186 ) == 0 ) {
V_5 = 1 ;
goto V_329;
}
V_5 = F_261 ( V_2 , V_70 , V_178 ,
V_320 , V_321 ) ;
if ( V_5 )
goto V_329;
if ( F_267 ( V_70 , V_2 -> V_65 ) ) {
V_5 = V_330 ;
goto V_329;
}
V_5 = F_1 ( V_2 , V_4 ) ;
if ( V_5 )
goto V_331;
V_5 = F_255 ( V_2 , V_4 , V_70 , V_242 ) ;
if ( V_5 )
goto V_331;
if ( F_129 ( V_70 -> V_138 ) &&
F_109 ( V_70 ) -> V_230 <= V_321 &&
F_109 ( V_70 ) -> V_324 <= V_321 ) {
V_5 = 0 ;
goto V_331;
}
V_242 = V_256 ;
while ( 1 ) {
if ( ! V_178 || ! V_178 -> V_325 || V_320 != V_178 -> V_325 -> V_326 )
break;
V_70 = V_178 -> V_325 ;
if ( V_4 != F_109 ( V_70 ) -> V_4 )
break;
if ( F_109 ( V_70 ) -> V_230 >
V_4 -> V_15 -> V_303 ) {
V_5 = F_255 ( V_2 , V_4 , V_70 , V_242 ) ;
if ( V_5 )
goto V_331;
}
if ( F_262 ( V_178 ) )
break;
V_178 = F_263 ( V_178 ) ;
F_264 ( V_322 ) ;
V_322 = V_178 ;
}
V_5 = 0 ;
V_331:
F_264 ( V_322 ) ;
if ( V_5 < 0 ) {
V_4 -> V_15 -> V_189 = V_2 -> V_65 ;
V_5 = 1 ;
}
F_10 ( V_4 ) ;
V_329:
return V_5 ;
}
int F_268 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_318 * V_318 )
{
struct V_318 * V_178 = F_263 ( V_318 ) ;
int V_5 ;
V_5 = F_265 ( V_2 , V_4 , V_318 -> V_325 , V_178 , 0 ) ;
F_264 ( V_178 ) ;
return V_5 ;
}
int F_269 ( struct V_3 * V_17 )
{
int V_5 ;
struct V_32 * V_33 ;
struct V_1 * V_2 ;
struct V_35 V_36 ;
struct V_35 V_141 ;
struct V_35 V_332 ;
struct V_3 * log ;
struct V_208 * V_15 = V_17 -> V_15 ;
struct V_22 V_23 = {
. V_181 = F_14 ,
. V_168 = 0 ,
} ;
V_33 = F_82 () ;
if ( ! V_33 )
return - V_55 ;
V_15 -> V_333 = 1 ;
V_2 = F_270 ( V_15 -> V_205 , 0 ) ;
if ( F_79 ( V_2 ) ) {
V_5 = F_127 ( V_2 ) ;
goto error;
}
V_23 . V_2 = V_2 ;
V_23 . V_26 = 1 ;
V_5 = F_146 ( V_2 , V_17 , & V_23 ) ;
if ( V_5 ) {
F_271 ( V_15 , V_5 , L_1
L_2 ) ;
goto error;
}
V_120:
V_36 . V_46 = V_47 ;
V_36 . V_68 = ( T_1 ) - 1 ;
F_113 ( & V_36 , V_334 ) ;
while ( 1 ) {
V_5 = F_26 ( NULL , V_17 , & V_36 , V_33 , 0 , 0 ) ;
if ( V_5 < 0 ) {
F_271 ( V_15 , V_5 ,
L_3 ) ;
goto error;
}
if ( V_5 > 0 ) {
if ( V_33 -> V_52 [ 0 ] == 0 )
break;
V_33 -> V_52 [ 0 ] -- ;
}
F_106 ( V_33 -> V_51 [ 0 ] , & V_141 ,
V_33 -> V_52 [ 0 ] ) ;
F_27 ( V_33 ) ;
if ( V_141 . V_46 != V_47 )
break;
log = F_272 ( V_17 , & V_141 ) ;
if ( F_79 ( log ) ) {
V_5 = F_127 ( log ) ;
F_271 ( V_15 , V_5 ,
L_4 ) ;
goto error;
}
V_332 . V_46 = V_141 . V_68 ;
V_332 . type = V_334 ;
V_332 . V_68 = ( T_1 ) - 1 ;
V_23 . V_165 = F_273 ( V_15 , & V_332 ) ;
if ( F_79 ( V_23 . V_165 ) ) {
V_5 = F_127 ( V_23 . V_165 ) ;
F_137 ( log -> V_182 ) ;
F_137 ( log -> V_335 ) ;
F_29 ( log ) ;
F_271 ( V_15 , V_5 , L_5
L_6 ) ;
goto error;
}
V_23 . V_165 -> V_8 = log ;
F_274 ( V_2 , V_23 . V_165 ) ;
V_5 = F_146 ( V_2 , log , & V_23 ) ;
if ( ! V_5 && V_23 . V_168 == V_171 ) {
V_5 = F_111 ( V_2 , V_23 . V_165 ,
V_33 ) ;
}
V_36 . V_68 = V_141 . V_68 - 1 ;
V_23 . V_165 -> V_8 = NULL ;
F_137 ( log -> V_182 ) ;
F_137 ( log -> V_335 ) ;
F_29 ( log ) ;
if ( V_5 )
goto error;
if ( V_141 . V_68 == 0 )
break;
}
F_27 ( V_33 ) ;
if ( V_23 . V_26 ) {
V_23 . V_26 = 0 ;
V_23 . V_181 = F_128 ;
V_23 . V_168 = V_169 ;
goto V_120;
}
if ( V_23 . V_168 < V_171 ) {
V_23 . V_168 ++ ;
goto V_120;
}
F_86 ( V_33 ) ;
V_5 = F_275 ( V_2 , V_15 -> V_205 ) ;
if ( V_5 )
return V_5 ;
F_137 ( V_17 -> V_182 ) ;
V_17 -> V_8 = NULL ;
V_15 -> V_333 = 0 ;
F_29 ( V_17 ) ;
return 0 ;
error:
if ( V_23 . V_2 )
F_276 ( V_23 . V_2 , V_15 -> V_205 ) ;
F_86 ( V_33 ) ;
return V_5 ;
}
void F_277 ( struct V_1 * V_2 ,
struct V_70 * V_93 , struct V_70 * V_70 ,
int V_336 )
{
if ( F_129 ( V_70 -> V_138 ) )
F_109 ( V_70 ) -> V_324 = V_2 -> V_65 ;
F_8 () ;
if ( F_109 ( V_93 ) -> V_211 == V_2 -> V_65 )
return;
if ( F_109 ( V_70 ) -> V_211 == V_2 -> V_65 )
return;
if ( V_336 )
goto V_337;
return;
V_337:
F_109 ( V_93 ) -> V_324 = V_2 -> V_65 ;
}
int F_278 ( struct V_1 * V_2 ,
struct V_70 * V_70 , struct V_70 * V_338 ,
struct V_318 * V_178 )
{
struct V_3 * V_4 = F_109 ( V_70 ) -> V_4 ;
if ( F_129 ( V_70 -> V_138 ) )
F_109 ( V_70 ) -> V_324 = V_2 -> V_65 ;
if ( F_109 ( V_70 ) -> V_211 <=
V_4 -> V_15 -> V_303 &&
( ! V_338 || F_109 ( V_338 ) -> V_211 <=
V_4 -> V_15 -> V_303 ) )
return 0 ;
return F_265 ( V_2 , V_4 , V_70 , V_178 , 1 ) ;
}
