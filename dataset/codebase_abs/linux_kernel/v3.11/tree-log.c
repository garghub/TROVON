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
V_57 = F_31 ( V_33 -> V_51 [ 0 ] , V_33 -> V_52 [ 0 ] ,
struct V_56 ) ;
V_58 = F_32 ( V_33 -> V_51 [ 0 ] , V_57 ) ;
V_57 = F_31 ( V_21 , V_34 ,
struct V_56 ) ;
F_33 ( V_21 , V_57 , V_58 ) ;
}
} else if ( V_43 ) {
struct V_56 * V_57 ;
V_57 = F_31 ( V_21 , V_34 , struct V_56 ) ;
F_33 ( V_21 , V_57 , 0 ) ;
}
V_53:
F_27 ( V_33 ) ;
V_5 = F_34 ( V_2 , V_4 , V_33 ,
V_36 , V_37 ) ;
if ( V_5 == - V_59 ) {
T_3 V_60 ;
V_60 = F_24 ( V_33 -> V_51 [ 0 ] ,
V_33 -> V_52 [ 0 ] ) ;
if ( V_60 > V_37 )
F_35 ( V_4 , V_33 , V_37 , 1 ) ;
else if ( V_60 < V_37 )
F_36 ( V_4 , V_33 ,
V_37 - V_60 ) ;
} else if ( V_5 ) {
return V_5 ;
}
V_41 = F_25 ( V_33 -> V_51 [ 0 ] ,
V_33 -> V_52 [ 0 ] ) ;
if ( V_36 -> type == V_44 && V_5 == - V_59 ) {
struct V_56 * V_61 ;
struct V_56 * V_62 ;
V_61 = (struct V_56 * ) V_40 ;
V_62 = (struct V_56 * ) V_41 ;
if ( F_37 ( V_21 , V_61 ) == 0 )
goto V_63;
if ( V_42 &&
F_38 ( F_39 ( V_21 , V_61 ) ) &&
F_38 ( F_39 ( V_33 -> V_51 [ 0 ] , V_62 ) ) ) {
V_39 = 1 ;
V_38 = F_40 ( V_33 -> V_51 [ 0 ] ,
V_62 ) ;
}
}
F_41 ( V_33 -> V_51 [ 0 ] , V_21 , V_41 ,
V_40 , V_37 ) ;
if ( V_39 ) {
struct V_56 * V_62 ;
V_62 = (struct V_56 * ) V_41 ;
F_42 ( V_33 -> V_51 [ 0 ] , V_62 , V_38 ) ;
}
if ( V_36 -> type == V_44 ) {
struct V_56 * V_62 ;
V_62 = (struct V_56 * ) V_41 ;
if ( F_37 ( V_33 -> V_51 [ 0 ] , V_62 ) == 0 ) {
F_43 ( V_33 -> V_51 [ 0 ] , V_62 ,
V_2 -> V_64 ) ;
}
}
V_63:
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
int V_65 ;
T_1 V_66 ;
T_1 V_28 = V_36 -> V_67 ;
T_1 V_58 = 0 ;
struct V_68 * V_57 ;
struct V_69 * V_69 = NULL ;
unsigned long V_70 ;
int V_5 = 0 ;
V_57 = F_31 ( V_21 , V_34 , struct V_68 ) ;
V_65 = F_46 ( V_21 , V_57 ) ;
if ( V_65 == V_71 ||
V_65 == V_72 ) {
V_58 = F_47 ( V_21 , V_57 ) ;
V_66 = V_28 + V_58 ;
if ( F_48 ( V_21 , V_57 ) == 0 )
V_58 = 0 ;
} else if ( V_65 == V_73 ) {
V_70 = F_49 ( V_21 , V_57 ) ;
V_58 = F_50 ( V_21 , V_57 ) ;
V_66 = F_51 ( V_28 + V_70 , V_4 -> V_74 ) ;
} else {
V_5 = 0 ;
goto V_75;
}
V_69 = F_52 ( V_4 , V_36 -> V_46 ) ;
if ( ! V_69 ) {
V_5 = - V_76 ;
goto V_75;
}
V_5 = F_53 ( V_2 , V_4 , V_33 , F_54 ( V_69 ) ,
V_28 , 0 ) ;
if ( V_5 == 0 &&
( V_65 == V_71 ||
V_65 == V_72 ) ) {
struct V_68 V_77 ;
struct V_68 V_78 ;
struct V_68 * V_79 ;
struct V_20 * V_80 ;
V_80 = V_33 -> V_51 [ 0 ] ;
V_79 = F_31 ( V_80 , V_33 -> V_52 [ 0 ] ,
struct V_68 ) ;
F_30 ( V_21 , & V_77 , ( unsigned long ) V_57 ,
sizeof( V_77 ) ) ;
F_30 ( V_80 , & V_78 , ( unsigned long ) V_79 ,
sizeof( V_78 ) ) ;
if ( memcmp ( & V_77 , & V_78 , sizeof( V_77 ) ) == 0 ) {
F_27 ( V_33 ) ;
goto V_75;
}
}
F_27 ( V_33 ) ;
V_5 = F_55 ( V_2 , V_4 , V_69 , V_28 , V_66 , 1 ) ;
if ( V_5 )
goto V_75;
if ( V_65 == V_71 ||
V_65 == V_72 ) {
T_1 V_67 ;
unsigned long V_81 ;
struct V_35 V_82 ;
V_5 = F_34 ( V_2 , V_4 , V_33 , V_36 ,
sizeof( * V_57 ) ) ;
if ( V_5 )
goto V_75;
V_81 = F_25 ( V_33 -> V_51 [ 0 ] ,
V_33 -> V_52 [ 0 ] ) ;
F_41 ( V_33 -> V_51 [ 0 ] , V_21 , V_81 ,
( unsigned long ) V_57 , sizeof( * V_57 ) ) ;
V_82 . V_46 = F_48 ( V_21 , V_57 ) ;
V_82 . V_67 = F_56 ( V_21 , V_57 ) ;
V_82 . type = V_83 ;
V_67 = V_36 -> V_67 - F_57 ( V_21 , V_57 ) ;
if ( V_82 . V_46 > 0 ) {
T_1 V_84 ;
T_1 V_85 ;
F_58 ( V_86 ) ;
V_5 = F_59 ( V_4 , V_82 . V_46 ,
V_82 . V_67 ) ;
if ( V_5 == 0 ) {
V_5 = F_60 ( V_2 , V_4 ,
V_82 . V_46 , V_82 . V_67 ,
0 , V_4 -> V_45 . V_46 ,
V_36 -> V_46 , V_67 , 0 ) ;
if ( V_5 )
goto V_75;
} else {
V_5 = F_61 ( V_2 ,
V_4 , V_4 -> V_45 . V_46 ,
V_36 -> V_46 , V_67 , & V_82 ) ;
if ( V_5 )
goto V_75;
}
F_27 ( V_33 ) ;
if ( F_62 ( V_21 , V_57 ) ) {
V_84 = V_82 . V_46 ;
V_85 = V_84 + V_82 . V_67 ;
} else {
V_84 = V_82 . V_46 +
F_57 ( V_21 , V_57 ) ;
V_85 = V_84 +
F_47 ( V_21 , V_57 ) ;
}
V_5 = F_63 ( V_4 -> V_8 ,
V_84 , V_85 - 1 ,
& V_86 , 0 ) ;
if ( V_5 )
goto V_75;
while ( ! F_64 ( & V_86 ) ) {
struct V_87 * V_88 ;
V_88 = F_65 ( V_86 . V_89 ,
struct V_87 ,
V_90 ) ;
if ( ! V_5 )
V_5 = F_66 ( V_2 ,
V_4 -> V_15 -> V_91 ,
V_88 ) ;
F_67 ( & V_88 -> V_90 ) ;
F_29 ( V_88 ) ;
}
if ( V_5 )
goto V_75;
} else {
F_27 ( V_33 ) ;
}
} else if ( V_65 == V_73 ) {
V_5 = F_23 ( V_2 , V_4 , V_33 , V_21 , V_34 , V_36 ) ;
if ( V_5 )
goto V_75;
}
F_68 ( V_69 , V_58 ) ;
V_5 = F_69 ( V_2 , V_4 , V_69 ) ;
V_75:
if ( V_69 )
F_70 ( V_69 ) ;
return V_5 ;
}
static T_2 int F_71 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_32 * V_33 ,
struct V_69 * V_92 ,
struct V_93 * V_94 )
{
struct V_69 * V_69 ;
char * V_95 ;
int V_96 ;
struct V_20 * V_80 ;
struct V_35 V_97 ;
int V_5 ;
V_80 = V_33 -> V_51 [ 0 ] ;
F_72 ( V_80 , V_94 , & V_97 ) ;
V_96 = F_73 ( V_80 , V_94 ) ;
V_95 = F_28 ( V_96 , V_54 ) ;
if ( ! V_95 )
return - V_55 ;
F_30 ( V_80 , V_95 , ( unsigned long ) ( V_94 + 1 ) , V_96 ) ;
F_27 ( V_33 ) ;
V_69 = F_52 ( V_4 , V_97 . V_46 ) ;
if ( ! V_69 ) {
V_5 = - V_76 ;
goto V_75;
}
V_5 = F_74 ( V_2 , V_4 , V_33 , V_97 . V_46 ) ;
if ( V_5 )
goto V_75;
V_5 = F_75 ( V_2 , V_4 , V_92 , V_69 , V_95 , V_96 ) ;
if ( V_5 )
goto V_75;
F_76 ( V_2 , V_4 ) ;
V_75:
F_29 ( V_95 ) ;
F_70 ( V_69 ) ;
return V_5 ;
}
static T_2 int F_77 ( struct V_3 * V_4 ,
struct V_32 * V_33 ,
T_1 V_98 , T_1 V_46 , T_1 V_99 ,
const char * V_95 , int V_96 )
{
struct V_93 * V_94 ;
struct V_35 V_97 ;
int V_100 = 0 ;
V_94 = F_78 ( NULL , V_4 , V_33 , V_98 ,
V_99 , V_95 , V_96 , 0 ) ;
if ( V_94 && ! F_79 ( V_94 ) ) {
F_72 ( V_33 -> V_51 [ 0 ] , V_94 , & V_97 ) ;
if ( V_97 . V_46 != V_46 )
goto V_75;
} else
goto V_75;
F_27 ( V_33 ) ;
V_94 = F_80 ( NULL , V_4 , V_33 , V_98 , V_95 , V_96 , 0 ) ;
if ( V_94 && ! F_79 ( V_94 ) ) {
F_72 ( V_33 -> V_51 [ 0 ] , V_94 , & V_97 ) ;
if ( V_97 . V_46 != V_46 )
goto V_75;
} else
goto V_75;
V_100 = 1 ;
V_75:
F_27 ( V_33 ) ;
return V_100 ;
}
static T_2 int F_81 ( struct V_3 * log ,
struct V_35 * V_36 ,
T_1 V_101 ,
char * V_95 , int V_102 )
{
struct V_32 * V_33 ;
struct V_103 * V_104 ;
unsigned long V_105 ;
unsigned long V_106 ;
unsigned long V_107 ;
int V_108 ;
int V_37 ;
int V_5 ;
int V_100 = 0 ;
V_33 = F_82 () ;
if ( ! V_33 )
return - V_55 ;
V_5 = F_26 ( NULL , log , V_36 , V_33 , 0 , 0 ) ;
if ( V_5 != 0 )
goto V_75;
V_105 = F_25 ( V_33 -> V_51 [ 0 ] , V_33 -> V_52 [ 0 ] ) ;
if ( V_36 -> type == V_109 ) {
if ( F_83 ( V_33 , V_101 ,
V_95 , V_102 , NULL ) )
V_100 = 1 ;
goto V_75;
}
V_37 = F_24 ( V_33 -> V_51 [ 0 ] , V_33 -> V_52 [ 0 ] ) ;
V_106 = V_105 + V_37 ;
while ( V_105 < V_106 ) {
V_104 = (struct V_103 * ) V_105 ;
V_108 = F_84 ( V_33 -> V_51 [ 0 ] , V_104 ) ;
if ( V_108 == V_102 ) {
V_107 = ( unsigned long ) ( V_104 + 1 ) ;
V_5 = F_85 ( V_33 -> V_51 [ 0 ] , V_95 ,
V_107 , V_102 ) ;
if ( V_5 == 0 ) {
V_100 = 1 ;
goto V_75;
}
}
V_105 = ( unsigned long ) ( V_104 + 1 ) + V_108 ;
}
V_75:
F_86 ( V_33 ) ;
return V_100 ;
}
static inline int F_87 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_32 * V_33 ,
struct V_3 * V_8 ,
struct V_69 * V_92 , struct V_69 * V_69 ,
struct V_20 * V_21 ,
T_1 V_110 , T_1 V_111 ,
T_1 V_112 , char * V_95 , int V_102 ,
int * V_113 )
{
int V_5 ;
char * V_114 ;
int V_115 ;
struct V_20 * V_80 ;
struct V_93 * V_94 ;
struct V_35 V_116 ;
struct V_117 * V_118 ;
V_119:
V_116 . V_46 = V_110 ;
V_116 . type = V_120 ;
V_116 . V_67 = V_111 ;
V_5 = F_26 ( NULL , V_4 , & V_116 , V_33 , 0 , 0 ) ;
if ( V_5 == 0 ) {
struct V_103 * V_121 ;
unsigned long V_105 ;
unsigned long V_106 ;
V_80 = V_33 -> V_51 [ 0 ] ;
if ( V_116 . V_46 == V_116 . V_67 )
return 1 ;
V_105 = F_25 ( V_80 , V_33 -> V_52 [ 0 ] ) ;
V_106 = V_105 + F_24 ( V_80 , V_33 -> V_52 [ 0 ] ) ;
while ( V_105 < V_106 ) {
V_121 = (struct V_103 * ) V_105 ;
V_115 = F_84 ( V_80 ,
V_121 ) ;
V_114 = F_28 ( V_115 , V_54 ) ;
if ( ! V_114 )
return - V_55 ;
F_30 ( V_80 , V_114 ,
( unsigned long ) ( V_121 + 1 ) ,
V_115 ) ;
if ( ! F_81 ( V_8 , & V_116 ,
V_111 ,
V_114 ,
V_115 ) ) {
F_88 ( V_69 ) ;
F_27 ( V_33 ) ;
V_5 = F_75 ( V_2 , V_4 , V_92 ,
V_69 , V_114 ,
V_115 ) ;
F_29 ( V_114 ) ;
if ( V_5 )
return V_5 ;
F_76 ( V_2 , V_4 ) ;
* V_113 = 1 ;
goto V_119;
}
F_29 ( V_114 ) ;
V_105 = ( unsigned long ) ( V_121 + 1 ) + V_115 ;
}
* V_113 = 1 ;
}
F_27 ( V_33 ) ;
V_118 = F_89 ( NULL , V_4 , V_33 , V_95 , V_102 ,
V_110 , V_111 , 0 ,
0 ) ;
if ( ! F_90 ( V_118 ) ) {
T_3 V_37 ;
T_3 V_122 = 0 ;
unsigned long V_123 ;
struct V_69 * V_124 ;
V_80 = V_33 -> V_51 [ 0 ] ;
V_37 = F_24 ( V_80 , V_33 -> V_52 [ 0 ] ) ;
V_123 = F_25 ( V_80 , V_33 -> V_52 [ 0 ] ) ;
while ( V_122 < V_37 ) {
V_118 = (struct V_117 * ) V_123 + V_122 ;
V_115 = F_91 ( V_80 , V_118 ) ;
if ( F_92 ( V_80 , V_118 ) != V_111 )
goto V_89;
V_114 = F_28 ( V_115 , V_54 ) ;
if ( ! V_114 )
return - V_55 ;
F_30 ( V_80 , V_114 , ( unsigned long ) & V_118 -> V_95 ,
V_115 ) ;
V_116 . V_46 = V_110 ;
V_116 . type = V_109 ;
V_116 . V_67 = F_93 ( V_111 ,
V_114 ,
V_115 ) ;
V_5 = 0 ;
if ( ! F_81 ( V_8 , & V_116 ,
V_111 , V_114 ,
V_115 ) ) {
V_5 = - V_18 ;
V_124 = F_52 ( V_4 ,
V_111 ) ;
if ( V_124 ) {
F_88 ( V_69 ) ;
F_27 ( V_33 ) ;
V_5 = F_75 ( V_2 , V_4 ,
V_124 ,
V_69 ,
V_114 ,
V_115 ) ;
F_76 ( V_2 , V_4 ) ;
}
F_70 ( V_124 ) ;
F_29 ( V_114 ) ;
if ( V_5 )
return V_5 ;
* V_113 = 1 ;
goto V_119;
}
F_29 ( V_114 ) ;
if ( V_5 )
return V_5 ;
V_89:
V_122 += V_115 + sizeof( * V_118 ) ;
}
* V_113 = 1 ;
}
F_27 ( V_33 ) ;
V_94 = F_78 ( V_2 , V_4 , V_33 , F_54 ( V_92 ) ,
V_112 , V_95 , V_102 , 0 ) ;
if ( V_94 && ! F_79 ( V_94 ) ) {
V_5 = F_71 ( V_2 , V_4 , V_33 , V_92 , V_94 ) ;
if ( V_5 )
return V_5 ;
}
F_27 ( V_33 ) ;
V_94 = F_80 ( V_2 , V_4 , V_33 , F_54 ( V_92 ) ,
V_95 , V_102 , 0 ) ;
if ( V_94 && ! F_79 ( V_94 ) ) {
V_5 = F_71 ( V_2 , V_4 , V_33 , V_92 , V_94 ) ;
if ( V_5 )
return V_5 ;
}
F_27 ( V_33 ) ;
return 0 ;
}
static int F_94 ( struct V_20 * V_21 , unsigned long V_125 ,
T_3 * V_102 , char * * V_95 , T_1 * V_99 ,
T_1 * V_111 )
{
struct V_117 * V_118 ;
V_118 = (struct V_117 * ) V_125 ;
* V_102 = F_91 ( V_21 , V_118 ) ;
* V_95 = F_28 ( * V_102 , V_54 ) ;
if ( * V_95 == NULL )
return - V_55 ;
F_30 ( V_21 , * V_95 , ( unsigned long ) & V_118 -> V_95 ,
* V_102 ) ;
* V_99 = F_95 ( V_21 , V_118 ) ;
if ( V_111 )
* V_111 = F_92 ( V_21 , V_118 ) ;
return 0 ;
}
static int F_96 ( struct V_20 * V_21 , unsigned long V_125 ,
T_3 * V_102 , char * * V_95 , T_1 * V_99 )
{
struct V_103 * V_104 ;
V_104 = (struct V_103 * ) V_125 ;
* V_102 = F_84 ( V_21 , V_104 ) ;
* V_95 = F_28 ( * V_102 , V_54 ) ;
if ( * V_95 == NULL )
return - V_55 ;
F_30 ( V_21 , * V_95 , ( unsigned long ) ( V_104 + 1 ) , * V_102 ) ;
* V_99 = F_97 ( V_21 , V_104 ) ;
return 0 ;
}
static T_2 int F_98 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_3 * log ,
struct V_32 * V_33 ,
struct V_20 * V_21 , int V_34 ,
struct V_35 * V_36 )
{
struct V_69 * V_92 ;
struct V_69 * V_69 ;
unsigned long V_125 ;
unsigned long V_126 ;
char * V_95 ;
int V_102 ;
int V_5 ;
int V_113 = 0 ;
int V_127 = 0 ;
T_1 V_111 ;
T_1 V_110 ;
T_1 V_112 = 0 ;
int V_128 ;
V_125 = F_25 ( V_21 , V_34 ) ;
V_126 = V_125 + F_24 ( V_21 , V_34 ) ;
if ( V_36 -> type == V_109 ) {
struct V_117 * V_129 ;
V_128 = sizeof( struct V_117 ) ;
V_127 = 1 ;
V_129 = (struct V_117 * ) V_125 ;
V_111 = F_92 ( V_21 , V_129 ) ;
} else {
V_128 = sizeof( struct V_103 ) ;
V_111 = V_36 -> V_67 ;
}
V_110 = V_36 -> V_46 ;
V_92 = F_52 ( V_4 , V_111 ) ;
if ( ! V_92 )
return - V_18 ;
V_69 = F_52 ( V_4 , V_110 ) ;
if ( ! V_69 ) {
F_70 ( V_92 ) ;
return - V_76 ;
}
while ( V_125 < V_126 ) {
if ( V_127 ) {
V_5 = F_94 ( V_21 , V_125 , & V_102 , & V_95 ,
& V_112 , & V_111 ) ;
if ( ! V_92 )
V_92 = F_52 ( V_4 , V_111 ) ;
if ( ! V_92 )
return - V_18 ;
} else {
V_5 = F_96 ( V_21 , V_125 , & V_102 , & V_95 ,
& V_112 ) ;
}
if ( V_5 )
return V_5 ;
if ( ! F_77 ( V_4 , V_33 , F_54 ( V_92 ) , F_54 ( V_69 ) ,
V_112 , V_95 , V_102 ) ) {
if ( ! V_113 ) {
V_5 = F_87 ( V_2 , V_4 , V_33 , log ,
V_92 , V_69 , V_21 ,
V_110 ,
V_111 ,
V_112 , V_95 , V_102 ,
& V_113 ) ;
if ( V_5 == 1 ) {
V_5 = 0 ;
goto V_75;
}
if ( V_5 )
goto V_75;
}
V_5 = F_99 ( V_2 , V_92 , V_69 , V_95 , V_102 ,
0 , V_112 ) ;
if ( V_5 )
goto V_75;
F_69 ( V_2 , V_4 , V_69 ) ;
}
V_125 = ( unsigned long ) ( V_125 + V_128 ) + V_102 ;
F_29 ( V_95 ) ;
if ( V_127 ) {
F_70 ( V_92 ) ;
V_92 = NULL ;
}
}
V_5 = F_23 ( V_2 , V_4 , V_33 , V_21 , V_34 , V_36 ) ;
V_75:
F_27 ( V_33 ) ;
F_70 ( V_92 ) ;
F_70 ( V_69 ) ;
return V_5 ;
}
static int F_100 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_1 V_67 )
{
int V_5 ;
V_5 = F_101 ( V_4 , V_67 ) ;
if ( V_5 > 0 )
V_5 = F_102 ( V_2 , V_4 , V_67 ) ;
return V_5 ;
}
static int F_103 ( struct V_3 * V_4 ,
struct V_69 * V_69 , struct V_32 * V_33 )
{
int V_5 = 0 ;
int V_96 ;
unsigned int V_130 = 0 ;
T_3 V_37 ;
T_3 V_122 = 0 ;
T_1 V_110 = F_54 ( V_69 ) ;
T_1 V_67 = 0 ;
unsigned long V_105 ;
struct V_117 * V_118 ;
struct V_20 * V_80 ;
while ( 1 ) {
V_5 = F_104 ( V_4 , V_110 , V_67 , V_33 ,
& V_118 , & V_67 ) ;
if ( V_5 )
break;
V_80 = V_33 -> V_51 [ 0 ] ;
V_37 = F_24 ( V_80 , V_33 -> V_52 [ 0 ] ) ;
V_105 = F_25 ( V_80 , V_33 -> V_52 [ 0 ] ) ;
while ( V_122 < V_37 ) {
V_118 = (struct V_117 * ) ( V_105 + V_122 ) ;
V_96 = F_91 ( V_80 , V_118 ) ;
V_130 ++ ;
V_122 += V_96 + sizeof( * V_118 ) ;
}
V_67 ++ ;
F_27 ( V_33 ) ;
}
F_27 ( V_33 ) ;
if ( V_5 < 0 )
return V_5 ;
return V_130 ;
}
static int F_105 ( struct V_3 * V_4 ,
struct V_69 * V_69 , struct V_32 * V_33 )
{
int V_5 ;
struct V_35 V_36 ;
unsigned int V_130 = 0 ;
unsigned long V_105 ;
unsigned long V_106 ;
int V_96 ;
T_1 V_131 = F_54 ( V_69 ) ;
V_36 . V_46 = V_131 ;
V_36 . type = V_120 ;
V_36 . V_67 = ( T_1 ) - 1 ;
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
if ( V_36 . V_46 != V_131 ||
V_36 . type != V_120 )
break;
V_105 = F_25 ( V_33 -> V_51 [ 0 ] , V_33 -> V_52 [ 0 ] ) ;
V_106 = V_105 + F_24 ( V_33 -> V_51 [ 0 ] ,
V_33 -> V_52 [ 0 ] ) ;
while ( V_105 < V_106 ) {
struct V_103 * V_104 ;
V_104 = (struct V_103 * ) V_105 ;
V_96 = F_84 ( V_33 -> V_51 [ 0 ] ,
V_104 ) ;
V_105 = ( unsigned long ) ( V_104 + 1 ) + V_96 ;
V_130 ++ ;
}
if ( V_36 . V_67 == 0 )
break;
V_36 . V_67 -- ;
F_27 ( V_33 ) ;
}
F_27 ( V_33 ) ;
return V_130 ;
}
static T_2 int F_107 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_69 * V_69 )
{
struct V_32 * V_33 ;
int V_5 ;
T_1 V_130 = 0 ;
T_1 V_131 = F_54 ( V_69 ) ;
V_33 = F_82 () ;
if ( ! V_33 )
return - V_55 ;
V_5 = F_105 ( V_4 , V_69 , V_33 ) ;
if ( V_5 < 0 )
goto V_75;
V_130 = V_5 ;
V_5 = F_103 ( V_4 , V_69 , V_33 ) ;
if ( V_5 == - V_18 )
V_5 = 0 ;
if ( V_5 < 0 )
goto V_75;
V_130 += V_5 ;
V_5 = 0 ;
if ( V_130 != V_69 -> V_132 ) {
F_108 ( V_69 , V_130 ) ;
F_69 ( V_2 , V_4 , V_69 ) ;
}
F_109 ( V_69 ) -> V_133 = ( T_1 ) - 1 ;
if ( V_69 -> V_132 == 0 ) {
if ( F_38 ( V_69 -> V_134 ) ) {
V_5 = F_110 ( V_2 , V_4 , NULL , V_33 ,
V_131 , 1 ) ;
if ( V_5 )
goto V_75;
}
V_5 = F_100 ( V_2 , V_4 , V_131 ) ;
}
V_75:
F_86 ( V_33 ) ;
return V_5 ;
}
static T_2 int F_111 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_32 * V_33 )
{
int V_5 ;
struct V_35 V_36 ;
struct V_69 * V_69 ;
V_36 . V_46 = V_135 ;
V_36 . type = V_136 ;
V_36 . V_67 = ( T_1 ) - 1 ;
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
if ( V_36 . V_46 != V_135 ||
V_36 . type != V_136 )
break;
V_5 = F_112 ( V_2 , V_4 , V_33 ) ;
if ( V_5 )
goto V_75;
F_27 ( V_33 ) ;
V_69 = F_52 ( V_4 , V_36 . V_67 ) ;
if ( ! V_69 )
return - V_76 ;
V_5 = F_107 ( V_2 , V_4 , V_69 ) ;
F_70 ( V_69 ) ;
if ( V_5 )
goto V_75;
V_36 . V_67 = ( T_1 ) - 1 ;
}
V_5 = 0 ;
V_75:
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
struct V_69 * V_69 ;
V_69 = F_52 ( V_4 , V_46 ) ;
if ( ! V_69 )
return - V_76 ;
V_36 . V_46 = V_135 ;
F_113 ( & V_36 , V_136 ) ;
V_36 . V_67 = V_46 ;
V_5 = F_34 ( V_2 , V_4 , V_33 , & V_36 , 0 ) ;
F_27 ( V_33 ) ;
if ( V_5 == 0 ) {
if ( ! V_69 -> V_132 )
F_108 ( V_69 , 1 ) ;
else
F_88 ( V_69 ) ;
V_5 = F_69 ( V_2 , V_4 , V_69 ) ;
} else if ( V_5 == - V_59 ) {
V_5 = 0 ;
} else {
F_114 () ;
}
F_70 ( V_69 ) ;
return V_5 ;
}
static T_2 int F_115 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_32 * V_33 ,
T_1 V_98 , T_1 V_99 ,
char * V_95 , int V_96 , T_4 type ,
struct V_35 * V_97 )
{
struct V_69 * V_69 ;
struct V_69 * V_92 ;
int V_5 ;
V_69 = F_52 ( V_4 , V_97 -> V_46 ) ;
if ( ! V_69 )
return - V_18 ;
V_92 = F_52 ( V_4 , V_98 ) ;
if ( ! V_92 ) {
F_70 ( V_69 ) ;
return - V_76 ;
}
V_5 = F_99 ( V_2 , V_92 , V_69 , V_95 , V_96 , 1 , V_99 ) ;
F_70 ( V_69 ) ;
F_70 ( V_92 ) ;
return V_5 ;
}
static T_2 int F_116 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_32 * V_33 ,
struct V_20 * V_21 ,
struct V_93 * V_94 ,
struct V_35 * V_36 )
{
char * V_95 ;
int V_96 ;
struct V_93 * V_137 ;
struct V_35 V_138 ;
struct V_35 V_139 ;
struct V_69 * V_92 ;
T_4 V_140 ;
int V_141 ;
int V_5 = 0 ;
V_92 = F_52 ( V_4 , V_36 -> V_46 ) ;
if ( ! V_92 )
return - V_76 ;
V_96 = F_73 ( V_21 , V_94 ) ;
V_95 = F_28 ( V_96 , V_54 ) ;
if ( ! V_95 )
return - V_55 ;
V_140 = F_117 ( V_21 , V_94 ) ;
F_30 ( V_21 , V_95 , ( unsigned long ) ( V_94 + 1 ) ,
V_96 ) ;
F_72 ( V_21 , V_94 , & V_139 ) ;
V_141 = F_118 ( V_2 , V_4 , V_33 , & V_139 , 0 ) ;
if ( V_141 == 0 )
V_141 = 1 ;
else
V_141 = 0 ;
F_27 ( V_33 ) ;
if ( V_36 -> type == V_142 ) {
V_137 = F_80 ( V_2 , V_4 , V_33 , V_36 -> V_46 ,
V_95 , V_96 , 1 ) ;
} else if ( V_36 -> type == V_143 ) {
V_137 = F_78 ( V_2 , V_4 , V_33 ,
V_36 -> V_46 ,
V_36 -> V_67 , V_95 ,
V_96 , 1 ) ;
} else {
V_5 = - V_144 ;
goto V_75;
}
if ( F_90 ( V_137 ) ) {
if ( V_36 -> type != V_143 )
goto V_75;
goto V_53;
}
F_72 ( V_33 -> V_51 [ 0 ] , V_137 , & V_138 ) ;
if ( V_138 . V_46 == V_139 . V_46 &&
V_138 . type == V_139 . type &&
V_138 . V_67 == V_139 . V_67 &&
F_117 ( V_33 -> V_51 [ 0 ] , V_137 ) == V_140 ) {
goto V_75;
}
if ( ! V_141 )
goto V_75;
V_5 = F_71 ( V_2 , V_4 , V_33 , V_92 , V_137 ) ;
if ( V_5 )
goto V_75;
if ( V_36 -> type == V_143 )
goto V_53;
V_75:
F_27 ( V_33 ) ;
F_29 ( V_95 ) ;
F_70 ( V_92 ) ;
return V_5 ;
V_53:
F_27 ( V_33 ) ;
V_5 = F_115 ( V_2 , V_4 , V_33 , V_36 -> V_46 , V_36 -> V_67 ,
V_95 , V_96 , V_140 , & V_139 ) ;
if ( V_5 && V_5 != - V_18 )
goto V_75;
V_5 = 0 ;
goto V_75;
}
static T_2 int F_119 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_32 * V_33 ,
struct V_20 * V_21 , int V_34 ,
struct V_35 * V_36 )
{
int V_5 ;
T_3 V_37 = F_24 ( V_21 , V_34 ) ;
struct V_93 * V_94 ;
int V_96 ;
unsigned long V_105 ;
unsigned long V_106 ;
V_105 = F_25 ( V_21 , V_34 ) ;
V_106 = V_105 + V_37 ;
while ( V_105 < V_106 ) {
V_94 = (struct V_93 * ) V_105 ;
if ( F_120 ( V_4 , V_21 , V_94 ) )
return - V_76 ;
V_96 = F_73 ( V_21 , V_94 ) ;
V_5 = F_116 ( V_2 , V_4 , V_33 , V_21 , V_94 , V_36 ) ;
if ( V_5 )
return V_5 ;
V_105 = ( unsigned long ) ( V_94 + 1 ) ;
V_105 += V_96 ;
}
return 0 ;
}
static T_2 int F_121 ( struct V_3 * V_4 ,
struct V_32 * V_33 ,
T_1 V_98 , int V_145 ,
T_1 * V_146 , T_1 * V_147 )
{
struct V_35 V_36 ;
T_1 V_148 ;
struct V_149 * V_57 ;
int V_5 ;
int V_150 ;
if ( * V_146 == ( T_1 ) - 1 )
return 1 ;
V_36 . V_46 = V_98 ;
V_36 . type = V_145 ;
V_36 . V_67 = * V_146 ;
V_5 = F_26 ( NULL , V_4 , & V_36 , V_33 , 0 , 0 ) ;
if ( V_5 < 0 )
goto V_75;
if ( V_5 > 0 ) {
if ( V_33 -> V_52 [ 0 ] == 0 )
goto V_75;
V_33 -> V_52 [ 0 ] -- ;
}
if ( V_5 != 0 )
F_106 ( V_33 -> V_51 [ 0 ] , & V_36 , V_33 -> V_52 [ 0 ] ) ;
if ( V_36 . type != V_145 || V_36 . V_46 != V_98 ) {
V_5 = 1 ;
goto V_89;
}
V_57 = F_31 ( V_33 -> V_51 [ 0 ] , V_33 -> V_52 [ 0 ] ,
struct V_149 ) ;
V_148 = F_122 ( V_33 -> V_51 [ 0 ] , V_57 ) ;
if ( * V_146 >= V_36 . V_67 && * V_146 <= V_148 ) {
V_5 = 0 ;
* V_146 = V_36 . V_67 ;
* V_147 = V_148 ;
goto V_75;
}
V_5 = 1 ;
V_89:
V_150 = F_123 ( V_33 -> V_51 [ 0 ] ) ;
if ( V_33 -> V_52 [ 0 ] >= V_150 ) {
V_5 = F_124 ( V_4 , V_33 ) ;
if ( V_5 )
goto V_75;
} else {
V_33 -> V_52 [ 0 ] ++ ;
}
F_106 ( V_33 -> V_51 [ 0 ] , & V_36 , V_33 -> V_52 [ 0 ] ) ;
if ( V_36 . type != V_145 || V_36 . V_46 != V_98 ) {
V_5 = 1 ;
goto V_75;
}
V_57 = F_31 ( V_33 -> V_51 [ 0 ] , V_33 -> V_52 [ 0 ] ,
struct V_149 ) ;
V_148 = F_122 ( V_33 -> V_51 [ 0 ] , V_57 ) ;
* V_146 = V_36 . V_67 ;
* V_147 = V_148 ;
V_5 = 0 ;
V_75:
F_27 ( V_33 ) ;
return V_5 ;
}
static T_2 int F_125 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_3 * log ,
struct V_32 * V_33 ,
struct V_32 * V_151 ,
struct V_69 * V_92 ,
struct V_35 * V_152 )
{
int V_5 ;
struct V_20 * V_21 ;
int V_34 ;
T_3 V_37 ;
struct V_93 * V_94 ;
struct V_93 * V_153 ;
int V_96 ;
unsigned long V_105 ;
unsigned long V_106 ;
char * V_95 ;
struct V_69 * V_69 ;
struct V_35 V_97 ;
V_119:
V_21 = V_33 -> V_51 [ 0 ] ;
V_34 = V_33 -> V_52 [ 0 ] ;
V_37 = F_24 ( V_21 , V_34 ) ;
V_105 = F_25 ( V_21 , V_34 ) ;
V_106 = V_105 + V_37 ;
while ( V_105 < V_106 ) {
V_94 = (struct V_93 * ) V_105 ;
if ( F_120 ( V_4 , V_21 , V_94 ) ) {
V_5 = - V_76 ;
goto V_75;
}
V_96 = F_73 ( V_21 , V_94 ) ;
V_95 = F_28 ( V_96 , V_54 ) ;
if ( ! V_95 ) {
V_5 = - V_55 ;
goto V_75;
}
F_30 ( V_21 , V_95 , ( unsigned long ) ( V_94 + 1 ) ,
V_96 ) ;
V_153 = NULL ;
if ( log && V_152 -> type == V_142 ) {
V_153 = F_80 ( V_2 , log , V_151 ,
V_152 -> V_46 ,
V_95 , V_96 , 0 ) ;
} else if ( log && V_152 -> type == V_143 ) {
V_153 = F_78 ( V_2 , log ,
V_151 ,
V_152 -> V_46 ,
V_152 -> V_67 ,
V_95 , V_96 , 0 ) ;
}
if ( F_90 ( V_153 ) ) {
F_72 ( V_21 , V_94 , & V_97 ) ;
F_27 ( V_33 ) ;
F_27 ( V_151 ) ;
V_69 = F_52 ( V_4 , V_97 . V_46 ) ;
if ( ! V_69 ) {
F_29 ( V_95 ) ;
return - V_76 ;
}
V_5 = F_74 ( V_2 , V_4 ,
V_33 , V_97 . V_46 ) ;
if ( V_5 ) {
F_29 ( V_95 ) ;
F_70 ( V_69 ) ;
goto V_75;
}
F_88 ( V_69 ) ;
V_5 = F_75 ( V_2 , V_4 , V_92 , V_69 ,
V_95 , V_96 ) ;
if ( ! V_5 )
F_76 ( V_2 , V_4 ) ;
F_29 ( V_95 ) ;
F_70 ( V_69 ) ;
if ( V_5 )
goto V_75;
V_5 = F_26 ( NULL , V_4 , V_152 , V_33 ,
0 , 0 ) ;
if ( V_5 == 0 )
goto V_119;
V_5 = 0 ;
goto V_75;
}
F_27 ( V_151 ) ;
F_29 ( V_95 ) ;
V_105 = ( unsigned long ) ( V_94 + 1 ) ;
V_105 += V_96 ;
}
V_5 = 0 ;
V_75:
F_27 ( V_33 ) ;
F_27 ( V_151 ) ;
return V_5 ;
}
static T_2 int F_110 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_3 * log ,
struct V_32 * V_33 ,
T_1 V_98 , int V_154 )
{
T_1 V_155 ;
T_1 V_156 ;
int V_145 = V_157 ;
int V_5 = 0 ;
struct V_35 V_152 ;
struct V_35 V_138 ;
struct V_32 * V_151 ;
struct V_69 * V_92 ;
V_152 . V_46 = V_98 ;
V_152 . type = V_142 ;
V_151 = F_82 () ;
if ( ! V_151 )
return - V_55 ;
V_92 = F_52 ( V_4 , V_98 ) ;
if ( ! V_92 ) {
F_86 ( V_151 ) ;
return 0 ;
}
V_119:
V_155 = 0 ;
V_156 = 0 ;
while ( 1 ) {
if ( V_154 )
V_156 = ( T_1 ) - 1 ;
else {
V_5 = F_121 ( log , V_33 , V_98 , V_145 ,
& V_155 , & V_156 ) ;
if ( V_5 != 0 )
break;
}
V_152 . V_67 = V_155 ;
while ( 1 ) {
int V_150 ;
V_5 = F_26 ( NULL , V_4 , & V_152 , V_33 ,
0 , 0 ) ;
if ( V_5 < 0 )
goto V_75;
V_150 = F_123 ( V_33 -> V_51 [ 0 ] ) ;
if ( V_33 -> V_52 [ 0 ] >= V_150 ) {
V_5 = F_124 ( V_4 , V_33 ) ;
if ( V_5 )
break;
}
F_106 ( V_33 -> V_51 [ 0 ] , & V_138 ,
V_33 -> V_52 [ 0 ] ) ;
if ( V_138 . V_46 != V_98 ||
V_138 . type != V_152 . type )
goto V_158;
if ( V_138 . V_67 > V_156 )
break;
V_5 = F_125 ( V_2 , V_4 , log , V_33 ,
V_151 , V_92 ,
& V_138 ) ;
if ( V_5 )
goto V_75;
if ( V_138 . V_67 == ( T_1 ) - 1 )
break;
V_152 . V_67 = V_138 . V_67 + 1 ;
}
F_27 ( V_33 ) ;
if ( V_156 == ( T_1 ) - 1 )
break;
V_155 = V_156 + 1 ;
}
V_158:
V_5 = 0 ;
if ( V_145 == V_157 ) {
V_145 = V_159 ;
V_152 . type = V_143 ;
F_27 ( V_33 ) ;
goto V_119;
}
V_75:
F_27 ( V_33 ) ;
F_86 ( V_151 ) ;
F_70 ( V_92 ) ;
return V_5 ;
}
static int F_126 ( struct V_3 * log , struct V_20 * V_21 ,
struct V_22 * V_23 , T_1 V_24 )
{
int V_150 ;
struct V_32 * V_33 ;
struct V_3 * V_4 = V_23 -> V_160 ;
struct V_35 V_36 ;
int V_161 ;
int V_162 ;
int V_5 ;
V_5 = F_16 ( V_21 , V_24 ) ;
if ( V_5 )
return V_5 ;
V_161 = F_19 ( V_21 ) ;
if ( V_161 != 0 )
return 0 ;
V_33 = F_82 () ;
if ( ! V_33 )
return - V_55 ;
V_150 = F_123 ( V_21 ) ;
for ( V_162 = 0 ; V_162 < V_150 ; V_162 ++ ) {
F_106 ( V_21 , & V_36 , V_162 ) ;
if ( V_36 . type == V_44 &&
V_23 -> V_163 == V_164 ) {
struct V_56 * V_43 ;
T_3 V_165 ;
V_43 = F_31 ( V_21 , V_162 ,
struct V_56 ) ;
V_165 = F_39 ( V_21 , V_43 ) ;
if ( F_38 ( V_165 ) ) {
V_5 = F_110 ( V_23 -> V_2 ,
V_4 , log , V_33 , V_36 . V_46 , 0 ) ;
if ( V_5 )
break;
}
V_5 = F_23 ( V_23 -> V_2 , V_4 , V_33 ,
V_21 , V_162 , & V_36 ) ;
if ( V_5 )
break;
if ( F_127 ( V_165 ) ) {
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
if ( V_23 -> V_163 < V_166 )
continue;
if ( V_36 . type == V_167 ) {
V_5 = F_23 ( V_23 -> V_2 , V_4 , V_33 ,
V_21 , V_162 , & V_36 ) ;
if ( V_5 )
break;
} else if ( V_36 . type == V_120 ||
V_36 . type == V_109 ) {
V_5 = F_98 ( V_23 -> V_2 , V_4 , log , V_33 ,
V_21 , V_162 , & V_36 ) ;
if ( V_5 && V_5 != - V_18 )
break;
V_5 = 0 ;
} else if ( V_36 . type == V_168 ) {
V_5 = F_45 ( V_23 -> V_2 , V_4 , V_33 ,
V_21 , V_162 , & V_36 ) ;
if ( V_5 )
break;
} else if ( V_36 . type == V_142 ||
V_36 . type == V_143 ) {
V_5 = F_119 ( V_23 -> V_2 , V_4 , V_33 ,
V_21 , V_162 , & V_36 ) ;
if ( V_5 )
break;
}
}
F_86 ( V_33 ) ;
return V_5 ;
}
static T_2 int F_128 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_32 * V_33 , int * V_161 ,
struct V_22 * V_23 )
{
T_1 V_169 ;
T_1 V_170 ;
T_1 V_171 ;
struct V_20 * V_89 ;
struct V_20 * V_172 ;
struct V_20 * V_173 ;
T_3 V_174 ;
int V_5 = 0 ;
F_129 ( * V_161 < 0 ) ;
F_129 ( * V_161 >= V_175 ) ;
while ( * V_161 > 0 ) {
F_129 ( * V_161 < 0 ) ;
F_129 ( * V_161 >= V_175 ) ;
V_172 = V_33 -> V_51 [ * V_161 ] ;
if ( F_19 ( V_172 ) != * V_161 )
F_129 ( 1 ) ;
if ( V_33 -> V_52 [ * V_161 ] >=
F_123 ( V_172 ) )
break;
V_170 = F_130 ( V_172 , V_33 -> V_52 [ * V_161 ] ) ;
V_171 = F_131 ( V_172 , V_33 -> V_52 [ * V_161 ] ) ;
V_174 = F_132 ( V_4 , * V_161 - 1 ) ;
V_173 = V_33 -> V_51 [ * V_161 ] ;
V_169 = F_133 ( V_173 ) ;
V_89 = F_134 ( V_4 , V_170 , V_174 ) ;
if ( ! V_89 )
return - V_55 ;
if ( * V_161 == 1 ) {
V_5 = V_23 -> V_176 ( V_4 , V_89 , V_23 , V_171 ) ;
if ( V_5 ) {
F_135 ( V_89 ) ;
return V_5 ;
}
V_33 -> V_52 [ * V_161 ] ++ ;
if ( V_23 -> free ) {
V_5 = F_16 ( V_89 , V_171 ) ;
if ( V_5 ) {
F_135 ( V_89 ) ;
return V_5 ;
}
F_136 ( V_89 ) ;
F_137 ( V_89 ) ;
F_138 ( V_2 , V_4 , V_89 ) ;
F_22 ( V_89 ) ;
F_139 ( V_89 ) ;
F_129 ( V_169 !=
V_47 ) ;
V_5 = F_140 ( V_4 ,
V_170 , V_174 ) ;
if ( V_5 ) {
F_135 ( V_89 ) ;
return V_5 ;
}
}
F_135 ( V_89 ) ;
continue;
}
V_5 = F_16 ( V_89 , V_171 ) ;
if ( V_5 ) {
F_135 ( V_89 ) ;
return V_5 ;
}
F_129 ( * V_161 <= 0 ) ;
if ( V_33 -> V_51 [ * V_161 - 1 ] )
F_135 ( V_33 -> V_51 [ * V_161 - 1 ] ) ;
V_33 -> V_51 [ * V_161 - 1 ] = V_89 ;
* V_161 = F_19 ( V_89 ) ;
V_33 -> V_52 [ * V_161 ] = 0 ;
F_141 () ;
}
F_129 ( * V_161 < 0 ) ;
F_129 ( * V_161 >= V_175 ) ;
V_33 -> V_52 [ * V_161 ] = F_123 ( V_33 -> V_51 [ * V_161 ] ) ;
F_141 () ;
return 0 ;
}
static T_2 int F_142 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_32 * V_33 , int * V_161 ,
struct V_22 * V_23 )
{
T_1 V_169 ;
int V_162 ;
int V_34 ;
int V_5 ;
for ( V_162 = * V_161 ; V_162 < V_175 - 1 && V_33 -> V_51 [ V_162 ] ; V_162 ++ ) {
V_34 = V_33 -> V_52 [ V_162 ] ;
if ( V_34 + 1 < F_123 ( V_33 -> V_51 [ V_162 ] ) ) {
V_33 -> V_52 [ V_162 ] ++ ;
* V_161 = V_162 ;
F_129 ( * V_161 == 0 ) ;
return 0 ;
} else {
struct V_20 * V_173 ;
if ( V_33 -> V_51 [ * V_161 ] == V_4 -> V_177 )
V_173 = V_33 -> V_51 [ * V_161 ] ;
else
V_173 = V_33 -> V_51 [ * V_161 + 1 ] ;
V_169 = F_133 ( V_173 ) ;
V_5 = V_23 -> V_176 ( V_4 , V_33 -> V_51 [ * V_161 ] , V_23 ,
F_143 ( V_33 -> V_51 [ * V_161 ] ) ) ;
if ( V_5 )
return V_5 ;
if ( V_23 -> free ) {
struct V_20 * V_89 ;
V_89 = V_33 -> V_51 [ * V_161 ] ;
F_136 ( V_89 ) ;
F_137 ( V_89 ) ;
F_138 ( V_2 , V_4 , V_89 ) ;
F_22 ( V_89 ) ;
F_139 ( V_89 ) ;
F_129 ( V_169 != V_47 ) ;
V_5 = F_140 ( V_4 ,
V_33 -> V_51 [ * V_161 ] -> V_28 ,
V_33 -> V_51 [ * V_161 ] -> V_29 ) ;
if ( V_5 )
return V_5 ;
}
F_135 ( V_33 -> V_51 [ * V_161 ] ) ;
V_33 -> V_51 [ * V_161 ] = NULL ;
* V_161 = V_162 + 1 ;
}
}
return 1 ;
}
static int F_144 ( struct V_1 * V_2 ,
struct V_3 * log , struct V_22 * V_23 )
{
int V_5 = 0 ;
int V_178 ;
int V_161 ;
struct V_32 * V_33 ;
int V_179 ;
V_33 = F_82 () ;
if ( ! V_33 )
return - V_55 ;
V_161 = F_19 ( log -> V_177 ) ;
V_179 = V_161 ;
V_33 -> V_51 [ V_161 ] = log -> V_177 ;
F_145 ( log -> V_177 ) ;
V_33 -> V_52 [ V_161 ] = 0 ;
while ( 1 ) {
V_178 = F_128 ( V_2 , log , V_33 , & V_161 , V_23 ) ;
if ( V_178 > 0 )
break;
if ( V_178 < 0 ) {
V_5 = V_178 ;
goto V_75;
}
V_178 = F_142 ( V_2 , log , V_33 , & V_161 , V_23 ) ;
if ( V_178 > 0 )
break;
if ( V_178 < 0 ) {
V_5 = V_178 ;
goto V_75;
}
}
if ( V_33 -> V_51 [ V_179 ] ) {
V_5 = V_23 -> V_176 ( log , V_33 -> V_51 [ V_179 ] , V_23 ,
F_143 ( V_33 -> V_51 [ V_179 ] ) ) ;
if ( V_5 )
goto V_75;
if ( V_23 -> free ) {
struct V_20 * V_89 ;
V_89 = V_33 -> V_51 [ V_179 ] ;
F_136 ( V_89 ) ;
F_137 ( V_89 ) ;
F_138 ( V_2 , log , V_89 ) ;
F_22 ( V_89 ) ;
F_139 ( V_89 ) ;
F_129 ( log -> V_45 . V_46 !=
V_47 ) ;
V_5 = F_140 ( log , V_89 -> V_28 ,
V_89 -> V_29 ) ;
if ( V_5 )
goto V_75;
}
}
V_75:
F_86 ( V_33 ) ;
return V_5 ;
}
static int F_146 ( struct V_1 * V_2 ,
struct V_3 * log )
{
int V_5 ;
if ( log -> V_180 == 1 ) {
V_5 = F_147 ( V_2 , log -> V_15 -> V_17 ,
& log -> V_45 , & log -> V_181 ) ;
} else {
V_5 = F_148 ( V_2 , log -> V_15 -> V_17 ,
& log -> V_45 , & log -> V_181 ) ;
}
return V_5 ;
}
static int F_149 ( struct V_1 * V_2 ,
struct V_3 * V_4 , unsigned long V_64 )
{
F_150 ( V_31 ) ;
int V_99 = V_64 % 2 ;
do {
F_151 ( & V_4 -> V_182 [ V_99 ] ,
& V_31 , V_183 ) ;
F_4 ( & V_4 -> V_7 ) ;
if ( V_4 -> V_15 -> V_184 !=
V_2 -> V_64 && V_4 -> V_180 < V_64 + 2 &&
F_152 ( & V_4 -> V_185 [ V_99 ] ) )
F_153 () ;
F_154 ( & V_4 -> V_182 [ V_99 ] , & V_31 ) ;
F_2 ( & V_4 -> V_7 ) ;
} while ( V_4 -> V_15 -> V_184 !=
V_2 -> V_64 && V_4 -> V_180 < V_64 + 2 &&
F_152 ( & V_4 -> V_185 [ V_99 ] ) );
return 0 ;
}
static void F_155 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_150 ( V_31 ) ;
while ( V_4 -> V_15 -> V_184 !=
V_2 -> V_64 && F_152 ( & V_4 -> V_14 ) ) {
F_151 ( & V_4 -> V_19 ,
& V_31 , V_183 ) ;
F_4 ( & V_4 -> V_7 ) ;
if ( V_4 -> V_15 -> V_184 !=
V_2 -> V_64 && F_152 ( & V_4 -> V_14 ) )
F_153 () ;
F_2 ( & V_4 -> V_7 ) ;
F_154 ( & V_4 -> V_19 , & V_31 ) ;
}
}
int F_156 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_186 ;
int V_187 ;
int V_188 ;
int V_5 ;
struct V_3 * log = V_4 -> V_8 ;
struct V_3 * V_17 = V_4 -> V_15 -> V_17 ;
unsigned long V_180 = 0 ;
struct V_189 V_190 ;
F_2 ( & V_4 -> V_7 ) ;
V_180 = V_4 -> V_180 ;
V_186 = V_4 -> V_180 % 2 ;
if ( F_152 ( & V_4 -> V_185 [ V_186 ] ) ) {
F_149 ( V_2 , V_4 , V_4 -> V_180 ) ;
F_4 ( & V_4 -> V_7 ) ;
return 0 ;
}
F_157 ( & V_4 -> V_185 [ V_186 ] , 1 ) ;
if ( F_152 ( & V_4 -> V_185 [ ( V_186 + 1 ) % 2 ] ) )
F_149 ( V_2 , V_4 , V_4 -> V_180 - 1 ) ;
while ( 1 ) {
int V_191 = F_152 ( & V_4 -> V_13 ) ;
if ( ! F_158 ( V_4 , V_192 ) && V_4 -> V_12 ) {
F_4 ( & V_4 -> V_7 ) ;
F_159 ( 1 ) ;
F_2 ( & V_4 -> V_7 ) ;
}
F_155 ( V_2 , V_4 ) ;
if ( V_191 == F_152 ( & V_4 -> V_13 ) )
break;
}
if ( V_4 -> V_15 -> V_184 == V_2 -> V_64 ) {
V_5 = - V_193 ;
F_160 ( log , V_180 ) ;
F_4 ( & V_4 -> V_7 ) ;
goto V_75;
}
if ( V_180 % 2 == 0 )
V_188 = V_194 ;
else
V_188 = V_195 ;
F_161 ( & V_190 ) ;
V_5 = F_162 ( log , & log -> V_196 , V_188 ) ;
if ( V_5 ) {
F_163 ( & V_190 ) ;
F_164 ( V_2 , V_4 , V_5 ) ;
F_160 ( log , V_180 ) ;
F_4 ( & V_4 -> V_7 ) ;
goto V_75;
}
F_165 ( & log -> V_181 , log -> V_177 ) ;
V_4 -> V_180 ++ ;
log -> V_180 = V_4 -> V_180 ;
V_4 -> V_9 = 0 ;
F_8 () ;
F_4 ( & V_4 -> V_7 ) ;
F_2 ( & V_17 -> V_7 ) ;
F_3 ( & V_17 -> V_13 ) ;
F_3 ( & V_17 -> V_14 ) ;
F_4 ( & V_17 -> V_7 ) ;
V_5 = F_146 ( V_2 , log ) ;
F_2 ( & V_17 -> V_7 ) ;
if ( F_11 ( & V_17 -> V_14 ) ) {
F_8 () ;
if ( F_12 ( & V_17 -> V_19 ) )
F_13 ( & V_17 -> V_19 ) ;
}
if ( V_5 ) {
F_163 ( & V_190 ) ;
if ( V_5 != - V_197 ) {
F_164 ( V_2 , V_4 , V_5 ) ;
F_4 ( & V_17 -> V_7 ) ;
goto V_75;
}
V_4 -> V_15 -> V_184 = V_2 -> V_64 ;
F_166 ( log , & log -> V_196 , V_188 ) ;
F_160 ( log , V_180 ) ;
F_4 ( & V_17 -> V_7 ) ;
V_5 = - V_193 ;
goto V_75;
}
V_187 = V_17 -> V_180 % 2 ;
if ( F_152 ( & V_17 -> V_185 [ V_187 ] ) ) {
F_163 ( & V_190 ) ;
F_166 ( log , & log -> V_196 , V_188 ) ;
F_149 ( V_2 , V_17 ,
V_17 -> V_180 ) ;
F_160 ( log , V_180 ) ;
F_4 ( & V_17 -> V_7 ) ;
V_5 = 0 ;
goto V_75;
}
F_157 ( & V_17 -> V_185 [ V_187 ] , 1 ) ;
if ( F_152 ( & V_17 -> V_185 [ ( V_187 + 1 ) % 2 ] ) ) {
F_149 ( V_2 , V_17 ,
V_17 -> V_180 - 1 ) ;
}
F_155 ( V_2 , V_17 ) ;
if ( V_4 -> V_15 -> V_184 == V_2 -> V_64 ) {
F_163 ( & V_190 ) ;
F_166 ( log , & log -> V_196 , V_188 ) ;
F_160 ( log , V_180 ) ;
F_4 ( & V_17 -> V_7 ) ;
V_5 = - V_193 ;
goto V_198;
}
V_5 = F_162 ( V_17 ,
& V_17 -> V_196 ,
V_194 | V_195 ) ;
F_163 ( & V_190 ) ;
if ( V_5 ) {
F_164 ( V_2 , V_4 , V_5 ) ;
F_160 ( log , V_180 ) ;
F_4 ( & V_17 -> V_7 ) ;
goto V_198;
}
F_166 ( log , & log -> V_196 , V_188 ) ;
F_166 ( V_17 ,
& V_17 -> V_196 ,
V_195 | V_194 ) ;
F_167 ( log , V_180 ) ;
F_168 ( V_4 -> V_15 -> V_199 ,
V_17 -> V_177 -> V_28 ) ;
F_169 ( V_4 -> V_15 -> V_199 ,
F_19 ( V_17 -> V_177 ) ) ;
V_17 -> V_180 ++ ;
F_8 () ;
F_4 ( & V_17 -> V_7 ) ;
F_170 ( V_4 ) ;
V_5 = F_171 ( V_2 , V_4 -> V_15 -> V_200 , 1 ) ;
F_172 ( V_4 ) ;
if ( V_5 ) {
F_164 ( V_2 , V_4 , V_5 ) ;
goto V_198;
}
F_2 ( & V_4 -> V_7 ) ;
if ( V_4 -> V_201 < V_180 )
V_4 -> V_201 = V_180 ;
F_4 ( & V_4 -> V_7 ) ;
V_198:
F_157 ( & V_17 -> V_185 [ V_187 ] , 0 ) ;
F_8 () ;
if ( F_12 ( & V_17 -> V_182 [ V_187 ] ) )
F_13 ( & V_17 -> V_182 [ V_187 ] ) ;
V_75:
F_157 ( & V_4 -> V_185 [ V_186 ] , 0 ) ;
F_8 () ;
if ( F_12 ( & V_4 -> V_182 [ V_186 ] ) )
F_13 ( & V_4 -> V_182 [ V_186 ] ) ;
return V_5 ;
}
static void F_173 ( struct V_1 * V_2 ,
struct V_3 * log )
{
int V_5 ;
T_1 V_28 ;
T_1 V_202 ;
struct V_22 V_23 = {
. free = 1 ,
. V_176 = F_14
} ;
if ( V_2 ) {
V_5 = F_144 ( V_2 , log , & V_23 ) ;
if ( V_5 )
F_164 ( V_2 , log , V_5 ) ;
}
while ( 1 ) {
V_5 = F_174 ( & log -> V_196 ,
0 , & V_28 , & V_202 , V_194 | V_195 ,
NULL ) ;
if ( V_5 )
break;
F_175 ( & log -> V_196 , V_28 , V_202 ,
V_194 | V_195 , V_54 ) ;
}
F_160 ( log , 0 ) ;
F_160 ( log , 1 ) ;
F_135 ( log -> V_177 ) ;
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
struct V_203 * V_15 )
{
if ( V_15 -> V_17 ) {
F_173 ( V_2 , V_15 -> V_17 ) ;
V_15 -> V_17 = NULL ;
}
return 0 ;
}
int F_178 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_95 , int V_96 ,
struct V_69 * V_92 , T_1 V_99 )
{
struct V_3 * log ;
struct V_93 * V_94 ;
struct V_32 * V_33 ;
int V_5 ;
int V_6 = 0 ;
int V_204 = 0 ;
T_1 V_205 = F_54 ( V_92 ) ;
if ( F_109 ( V_92 ) -> V_206 < V_2 -> V_64 )
return 0 ;
V_5 = F_7 ( V_4 ) ;
if ( V_5 )
return 0 ;
F_2 ( & F_109 ( V_92 ) -> V_7 ) ;
log = V_4 -> V_8 ;
V_33 = F_82 () ;
if ( ! V_33 ) {
V_6 = - V_55 ;
goto V_207;
}
V_94 = F_80 ( V_2 , log , V_33 , V_205 ,
V_95 , V_96 , - 1 ) ;
if ( F_79 ( V_94 ) ) {
V_6 = F_179 ( V_94 ) ;
goto V_208;
}
if ( V_94 ) {
V_5 = F_180 ( V_2 , log , V_33 , V_94 ) ;
V_204 += V_96 ;
if ( V_5 ) {
V_6 = V_5 ;
goto V_208;
}
}
F_27 ( V_33 ) ;
V_94 = F_78 ( V_2 , log , V_33 , V_205 ,
V_99 , V_95 , V_96 , - 1 ) ;
if ( F_79 ( V_94 ) ) {
V_6 = F_179 ( V_94 ) ;
goto V_208;
}
if ( V_94 ) {
V_5 = F_180 ( V_2 , log , V_33 , V_94 ) ;
V_204 += V_96 ;
if ( V_5 ) {
V_6 = V_5 ;
goto V_208;
}
}
if ( V_204 ) {
struct V_35 V_36 ;
V_36 . V_46 = V_205 ;
V_36 . V_67 = 0 ;
V_36 . type = V_44 ;
F_27 ( V_33 ) ;
V_5 = F_26 ( V_2 , log , & V_36 , V_33 , 0 , 1 ) ;
if ( V_5 < 0 ) {
V_6 = V_5 ;
goto V_208;
}
if ( V_5 == 0 ) {
struct V_56 * V_57 ;
T_1 V_209 ;
V_57 = F_31 ( V_33 -> V_51 [ 0 ] , V_33 -> V_52 [ 0 ] ,
struct V_56 ) ;
V_209 = F_40 ( V_33 -> V_51 [ 0 ] , V_57 ) ;
if ( V_209 > V_204 )
V_209 -= V_204 ;
else
V_209 = 0 ;
F_42 ( V_33 -> V_51 [ 0 ] , V_57 , V_209 ) ;
F_44 ( V_33 -> V_51 [ 0 ] ) ;
} else
V_5 = 0 ;
F_27 ( V_33 ) ;
}
V_208:
F_86 ( V_33 ) ;
V_207:
F_4 ( & F_109 ( V_92 ) -> V_7 ) ;
if ( V_5 == - V_197 ) {
V_4 -> V_15 -> V_184 = V_2 -> V_64 ;
V_5 = 0 ;
} else if ( V_5 < 0 )
F_164 ( V_2 , V_4 , V_5 ) ;
F_10 ( V_4 ) ;
return V_6 ;
}
int F_181 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_95 , int V_96 ,
struct V_69 * V_69 , T_1 V_98 )
{
struct V_3 * log ;
T_1 V_99 ;
int V_5 ;
if ( F_109 ( V_69 ) -> V_206 < V_2 -> V_64 )
return 0 ;
V_5 = F_7 ( V_4 ) ;
if ( V_5 )
return 0 ;
log = V_4 -> V_8 ;
F_2 ( & F_109 ( V_69 ) -> V_7 ) ;
V_5 = F_182 ( V_2 , log , V_95 , V_96 , F_54 ( V_69 ) ,
V_98 , & V_99 ) ;
F_4 ( & F_109 ( V_69 ) -> V_7 ) ;
if ( V_5 == - V_197 ) {
V_4 -> V_15 -> V_184 = V_2 -> V_64 ;
V_5 = 0 ;
} else if ( V_5 < 0 && V_5 != - V_18 )
F_164 ( V_2 , V_4 , V_5 ) ;
F_10 ( V_4 ) ;
return V_5 ;
}
static T_2 int F_183 ( struct V_1 * V_2 ,
struct V_3 * log ,
struct V_32 * V_33 ,
int V_145 , T_1 V_98 ,
T_1 V_210 , T_1 V_211 )
{
int V_5 ;
struct V_35 V_36 ;
struct V_149 * V_57 ;
V_36 . V_46 = V_98 ;
V_36 . V_67 = V_210 ;
if ( V_145 == V_142 )
V_36 . type = V_157 ;
else
V_36 . type = V_159 ;
V_5 = F_34 ( V_2 , log , V_33 , & V_36 , sizeof( * V_57 ) ) ;
if ( V_5 )
return V_5 ;
V_57 = F_31 ( V_33 -> V_51 [ 0 ] , V_33 -> V_52 [ 0 ] ,
struct V_149 ) ;
F_184 ( V_33 -> V_51 [ 0 ] , V_57 , V_211 ) ;
F_44 ( V_33 -> V_51 [ 0 ] ) ;
F_27 ( V_33 ) ;
return 0 ;
}
static T_2 int F_185 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_69 * V_69 ,
struct V_32 * V_33 ,
struct V_32 * V_212 , int V_145 ,
T_1 V_213 , T_1 * V_214 )
{
struct V_35 V_215 ;
struct V_35 V_216 ;
struct V_3 * log = V_4 -> V_8 ;
struct V_20 * V_217 ;
int V_6 = 0 ;
int V_5 ;
int V_162 ;
int V_150 ;
T_1 V_210 = V_213 ;
T_1 V_211 = ( T_1 ) - 1 ;
T_1 V_131 = F_54 ( V_69 ) ;
log = V_4 -> V_8 ;
V_216 . V_46 = V_131 ;
V_216 . V_67 = ( T_1 ) - 1 ;
V_216 . type = V_145 ;
V_215 . V_46 = V_131 ;
V_215 . type = V_145 ;
V_215 . V_67 = V_213 ;
V_33 -> V_218 = 1 ;
V_5 = F_186 ( V_4 , & V_215 , & V_216 ,
V_33 , V_2 -> V_64 ) ;
if ( V_5 != 0 || V_215 . V_46 != V_131 || V_215 . type != V_145 ) {
V_215 . V_46 = V_131 ;
V_215 . type = V_145 ;
V_215 . V_67 = ( T_1 ) - 1 ;
F_27 ( V_33 ) ;
V_5 = F_26 ( NULL , V_4 , & V_215 , V_33 , 0 , 0 ) ;
if ( V_5 < 0 ) {
F_27 ( V_33 ) ;
return V_5 ;
}
V_5 = F_187 ( V_4 , V_33 , V_131 , V_145 ) ;
if ( V_5 == 0 ) {
struct V_35 V_219 ;
F_106 ( V_33 -> V_51 [ 0 ] , & V_219 ,
V_33 -> V_52 [ 0 ] ) ;
if ( V_145 == V_219 . type )
V_210 = F_188 ( V_213 , V_219 . V_67 ) + 1 ;
}
goto V_220;
}
V_5 = F_187 ( V_4 , V_33 , V_131 , V_145 ) ;
if ( V_5 == 0 ) {
struct V_35 V_219 ;
F_106 ( V_33 -> V_51 [ 0 ] , & V_219 , V_33 -> V_52 [ 0 ] ) ;
if ( V_145 == V_219 . type ) {
V_210 = V_219 . V_67 ;
V_5 = F_23 ( V_2 , log , V_212 ,
V_33 -> V_51 [ 0 ] , V_33 -> V_52 [ 0 ] ,
& V_219 ) ;
if ( V_5 ) {
V_6 = V_5 ;
goto V_220;
}
}
}
F_27 ( V_33 ) ;
V_5 = F_26 ( NULL , V_4 , & V_215 , V_33 , 0 , 0 ) ;
if ( V_5 != 0 ) {
F_129 ( 1 ) ;
goto V_220;
}
while ( 1 ) {
struct V_35 V_219 ;
V_217 = V_33 -> V_51 [ 0 ] ;
V_150 = F_123 ( V_217 ) ;
for ( V_162 = V_33 -> V_52 [ 0 ] ; V_162 < V_150 ; V_162 ++ ) {
F_106 ( V_217 , & V_215 , V_162 ) ;
if ( V_215 . V_46 != V_131 || V_215 . type != V_145 )
goto V_220;
V_5 = F_23 ( V_2 , log , V_212 , V_217 , V_162 ,
& V_215 ) ;
if ( V_5 ) {
V_6 = V_5 ;
goto V_220;
}
}
V_33 -> V_52 [ 0 ] = V_150 ;
V_5 = F_124 ( V_4 , V_33 ) ;
if ( V_5 == 1 ) {
V_211 = ( T_1 ) - 1 ;
goto V_220;
}
F_106 ( V_33 -> V_51 [ 0 ] , & V_219 , V_33 -> V_52 [ 0 ] ) ;
if ( V_219 . V_46 != V_131 || V_219 . type != V_145 ) {
V_211 = ( T_1 ) - 1 ;
goto V_220;
}
if ( F_143 ( V_33 -> V_51 [ 0 ] ) != V_2 -> V_64 ) {
V_5 = F_23 ( V_2 , log , V_212 ,
V_33 -> V_51 [ 0 ] , V_33 -> V_52 [ 0 ] ,
& V_219 ) ;
if ( V_5 )
V_6 = V_5 ;
else
V_211 = V_219 . V_67 ;
goto V_220;
}
}
V_220:
F_27 ( V_33 ) ;
F_27 ( V_212 ) ;
if ( V_6 == 0 ) {
* V_214 = V_211 ;
V_5 = F_183 ( V_2 , log , V_33 , V_145 ,
V_131 , V_210 , V_211 ) ;
if ( V_5 )
V_6 = V_5 ;
}
return V_6 ;
}
static T_2 int F_189 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_69 * V_69 ,
struct V_32 * V_33 ,
struct V_32 * V_212 )
{
T_1 V_215 ;
T_1 V_216 ;
int V_5 ;
int V_145 = V_142 ;
V_119:
V_215 = 0 ;
V_216 = 0 ;
while ( 1 ) {
V_5 = F_185 ( V_2 , V_4 , V_69 , V_33 ,
V_212 , V_145 , V_215 ,
& V_216 ) ;
if ( V_5 )
return V_5 ;
if ( V_216 == ( T_1 ) - 1 )
break;
V_215 = V_216 + 1 ;
}
if ( V_145 == V_142 ) {
V_145 = V_143 ;
goto V_119;
}
return 0 ;
}
static int F_190 ( struct V_1 * V_2 ,
struct V_3 * log ,
struct V_32 * V_33 ,
T_1 V_46 , int V_221 )
{
int V_5 ;
struct V_35 V_36 ;
struct V_35 V_138 ;
int V_222 ;
V_36 . V_46 = V_46 ;
V_36 . type = V_221 ;
V_36 . V_67 = ( T_1 ) - 1 ;
while ( 1 ) {
V_5 = F_26 ( V_2 , log , & V_36 , V_33 , - 1 , 1 ) ;
F_191 ( V_5 == 0 ) ;
if ( V_5 < 0 )
break;
if ( V_33 -> V_52 [ 0 ] == 0 )
break;
V_33 -> V_52 [ 0 ] -- ;
F_106 ( V_33 -> V_51 [ 0 ] , & V_138 ,
V_33 -> V_52 [ 0 ] ) ;
if ( V_138 . V_46 != V_46 )
break;
V_138 . V_67 = 0 ;
V_138 . type = 0 ;
V_5 = F_192 ( V_33 -> V_51 [ 0 ] , & V_138 , 0 ,
& V_222 ) ;
V_5 = F_193 ( V_2 , log , V_33 , V_222 ,
V_33 -> V_52 [ 0 ] - V_222 + 1 ) ;
if ( V_5 || V_222 != 0 )
break;
F_27 ( V_33 ) ;
}
F_27 ( V_33 ) ;
if ( V_5 > 0 )
V_5 = 0 ;
return V_5 ;
}
static void F_194 ( struct V_1 * V_2 ,
struct V_20 * V_80 ,
struct V_56 * V_57 ,
struct V_69 * V_69 , int V_223 )
{
struct V_224 V_225 ;
F_195 ( & V_225 ) ;
if ( V_223 ) {
F_196 ( V_80 , V_57 , 0 , & V_225 ) ;
F_197 ( V_80 , V_57 , 0 , & V_225 ) ;
} else {
F_196 ( V_80 , V_57 ,
F_109 ( V_69 ) -> V_226 ,
& V_225 ) ;
F_197 ( V_80 , V_57 , V_69 -> V_209 , & V_225 ) ;
}
F_198 ( V_80 , V_57 , F_199 ( V_69 ) , & V_225 ) ;
F_200 ( V_80 , V_57 , F_201 ( V_69 ) , & V_225 ) ;
F_202 ( V_80 , V_57 , V_69 -> V_134 , & V_225 ) ;
F_203 ( V_80 , V_57 , V_69 -> V_132 , & V_225 ) ;
F_204 ( V_80 , F_205 ( V_57 ) ,
V_69 -> V_227 . V_228 , & V_225 ) ;
F_206 ( V_80 , F_205 ( V_57 ) ,
V_69 -> V_227 . V_229 , & V_225 ) ;
F_204 ( V_80 , F_207 ( V_57 ) ,
V_69 -> V_230 . V_228 , & V_225 ) ;
F_206 ( V_80 , F_207 ( V_57 ) ,
V_69 -> V_230 . V_229 , & V_225 ) ;
F_204 ( V_80 , F_208 ( V_57 ) ,
V_69 -> V_231 . V_228 , & V_225 ) ;
F_206 ( V_80 , F_208 ( V_57 ) ,
V_69 -> V_231 . V_229 , & V_225 ) ;
F_209 ( V_80 , V_57 , F_210 ( V_69 ) ,
& V_225 ) ;
F_211 ( V_80 , V_57 , V_69 -> V_232 , & V_225 ) ;
F_212 ( V_80 , V_57 , V_2 -> V_64 , & V_225 ) ;
F_213 ( V_80 , V_57 , V_69 -> V_233 , & V_225 ) ;
F_214 ( V_80 , V_57 , F_109 ( V_69 ) -> V_234 , & V_225 ) ;
F_215 ( V_80 , V_57 , 0 , & V_225 ) ;
}
static int F_216 ( struct V_1 * V_2 ,
struct V_3 * log , struct V_32 * V_33 ,
struct V_69 * V_69 )
{
struct V_56 * V_43 ;
struct V_35 V_36 ;
int V_5 ;
memcpy ( & V_36 , & F_109 ( V_69 ) -> V_97 , sizeof( V_36 ) ) ;
V_5 = F_34 ( V_2 , log , V_33 , & V_36 ,
sizeof( * V_43 ) ) ;
if ( V_5 && V_5 != - V_59 )
return V_5 ;
V_43 = F_31 ( V_33 -> V_51 [ 0 ] , V_33 -> V_52 [ 0 ] ,
struct V_56 ) ;
F_194 ( V_2 , V_33 -> V_51 [ 0 ] , V_43 , V_69 , 0 ) ;
F_27 ( V_33 ) ;
return 0 ;
}
static T_2 int F_217 ( struct V_1 * V_2 ,
struct V_69 * V_69 ,
struct V_32 * V_212 ,
struct V_20 * V_217 ,
int V_222 , int V_235 , int V_236 )
{
unsigned long V_237 ;
unsigned long V_238 ;
struct V_3 * log = F_109 ( V_69 ) -> V_4 -> V_8 ;
struct V_68 * V_239 ;
struct V_56 * V_43 ;
int V_5 ;
struct V_35 * V_240 ;
T_3 * V_241 ;
char * V_242 ;
int V_162 ;
struct V_243 V_86 ;
int V_244 = F_109 ( V_69 ) -> V_234 & V_245 ;
F_218 ( & V_86 ) ;
V_242 = F_28 ( V_235 * sizeof( struct V_35 ) +
V_235 * sizeof( T_3 ) , V_54 ) ;
if ( ! V_242 )
return - V_55 ;
V_241 = ( T_3 * ) V_242 ;
V_240 = (struct V_35 * ) ( V_242 + V_235 * sizeof( T_3 ) ) ;
for ( V_162 = 0 ; V_162 < V_235 ; V_162 ++ ) {
V_241 [ V_162 ] = F_24 ( V_217 , V_162 + V_222 ) ;
F_106 ( V_217 , V_240 + V_162 , V_162 + V_222 ) ;
}
V_5 = F_219 ( V_2 , log , V_212 ,
V_240 , V_241 , V_235 ) ;
if ( V_5 ) {
F_29 ( V_242 ) ;
return V_5 ;
}
for ( V_162 = 0 ; V_162 < V_235 ; V_162 ++ , V_212 -> V_52 [ 0 ] ++ ) {
V_238 = F_25 ( V_212 -> V_51 [ 0 ] ,
V_212 -> V_52 [ 0 ] ) ;
V_237 = F_25 ( V_217 , V_222 + V_162 ) ;
if ( V_240 [ V_162 ] . type == V_44 ) {
V_43 = F_31 ( V_212 -> V_51 [ 0 ] ,
V_212 -> V_52 [ 0 ] ,
struct V_56 ) ;
F_194 ( V_2 , V_212 -> V_51 [ 0 ] , V_43 ,
V_69 , V_236 == V_246 ) ;
} else {
F_41 ( V_212 -> V_51 [ 0 ] , V_217 , V_238 ,
V_237 , V_241 [ V_162 ] ) ;
}
if ( F_220 ( V_240 + V_162 ) == V_168 &&
! V_244 ) {
int V_65 ;
V_239 = F_31 ( V_217 , V_222 + V_162 ,
struct V_68 ) ;
if ( F_221 ( V_217 , V_239 ) < V_2 -> V_64 )
continue;
V_65 = F_46 ( V_217 , V_239 ) ;
if ( V_65 == V_71 ) {
T_1 V_247 , V_248 , V_249 , V_250 ;
V_247 = F_48 ( V_217 ,
V_239 ) ;
if ( V_247 == 0 )
continue;
V_248 = F_56 ( V_217 ,
V_239 ) ;
V_249 = F_57 ( V_217 , V_239 ) ;
V_250 = F_47 ( V_217 ,
V_239 ) ;
if ( F_62 ( V_217 ,
V_239 ) ) {
V_249 = 0 ;
V_250 = V_248 ;
}
V_5 = F_63 (
log -> V_15 -> V_91 ,
V_247 + V_249 , V_247 + V_249 + V_250 - 1 ,
& V_86 , 0 ) ;
if ( V_5 ) {
F_27 ( V_212 ) ;
F_29 ( V_242 ) ;
return V_5 ;
}
}
}
}
F_44 ( V_212 -> V_51 [ 0 ] ) ;
F_27 ( V_212 ) ;
F_29 ( V_242 ) ;
V_5 = 0 ;
while ( ! F_64 ( & V_86 ) ) {
struct V_87 * V_88 = F_65 ( V_86 . V_89 ,
struct V_87 ,
V_90 ) ;
if ( ! V_5 )
V_5 = F_66 ( V_2 , log , V_88 ) ;
F_67 ( & V_88 -> V_90 ) ;
F_29 ( V_88 ) ;
}
return V_5 ;
}
static int F_222 ( void * V_251 , struct V_243 * V_252 , struct V_243 * V_253 )
{
struct V_254 * V_255 , * V_256 ;
V_255 = F_65 ( V_252 , struct V_254 , V_90 ) ;
V_256 = F_65 ( V_253 , struct V_254 , V_90 ) ;
if ( V_255 -> V_28 < V_256 -> V_28 )
return - 1 ;
else if ( V_255 -> V_28 > V_256 -> V_28 )
return 1 ;
return 0 ;
}
static int F_223 ( struct V_1 * V_2 ,
struct V_69 * V_69 , struct V_3 * V_4 ,
struct V_254 * V_257 , struct V_32 * V_33 )
{
struct V_3 * log = V_4 -> V_8 ;
struct V_68 * V_258 ;
struct V_20 * V_80 ;
struct V_259 * V_260 ;
struct V_243 V_86 ;
struct V_224 V_225 ;
struct V_35 V_36 ;
T_1 V_261 = V_257 -> V_261 ;
T_1 V_262 = V_257 -> V_262 ;
T_1 V_263 ;
T_1 V_264 ;
T_1 V_265 = V_257 -> V_28 - V_257 -> V_266 ;
T_1 V_267 ;
int V_5 ;
int V_99 = log -> V_180 % 2 ;
bool V_244 = F_109 ( V_69 ) -> V_234 & V_245 ;
V_5 = F_224 ( V_2 , log , V_69 , V_33 , V_257 -> V_28 ,
V_257 -> V_28 + V_257 -> V_29 , NULL , 0 ) ;
if ( V_5 )
return V_5 ;
F_218 ( & V_86 ) ;
F_195 ( & V_225 ) ;
V_36 . V_46 = F_54 ( V_69 ) ;
V_36 . type = V_168 ;
V_36 . V_67 = V_257 -> V_28 ;
V_5 = F_34 ( V_2 , log , V_33 , & V_36 , sizeof( * V_258 ) ) ;
if ( V_5 )
return V_5 ;
V_80 = V_33 -> V_51 [ 0 ] ;
V_258 = F_31 ( V_80 , V_33 -> V_52 [ 0 ] ,
struct V_68 ) ;
F_225 ( V_80 , V_258 , V_257 -> V_226 ,
& V_225 ) ;
if ( F_226 ( V_268 , & V_257 -> V_234 ) ) {
V_244 = true ;
F_227 ( V_80 , V_258 ,
V_72 ,
& V_225 ) ;
} else {
F_227 ( V_80 , V_258 ,
V_71 ,
& V_225 ) ;
if ( V_257 -> V_269 == 0 )
V_244 = true ;
}
V_267 = F_188 ( V_257 -> V_267 , V_257 -> V_270 ) ;
if ( V_257 -> V_271 != V_272 ) {
F_228 ( V_80 , V_258 ,
V_257 -> V_269 ,
& V_225 ) ;
F_229 ( V_80 , V_258 , V_267 ,
& V_225 ) ;
} else if ( V_257 -> V_269 < V_273 ) {
F_228 ( V_80 , V_258 ,
V_257 -> V_269 -
V_265 , & V_225 ) ;
F_229 ( V_80 , V_258 , V_267 ,
& V_225 ) ;
} else {
F_228 ( V_80 , V_258 , 0 , & V_225 ) ;
F_229 ( V_80 , V_258 , 0 ,
& V_225 ) ;
}
F_230 ( V_80 , V_258 ,
V_257 -> V_28 - V_257 -> V_266 ,
& V_225 ) ;
F_231 ( V_80 , V_258 , V_257 -> V_29 , & V_225 ) ;
F_232 ( V_80 , V_258 , V_257 -> V_274 , & V_225 ) ;
F_233 ( V_80 , V_258 , V_257 -> V_271 ,
& V_225 ) ;
F_234 ( V_80 , V_258 , 0 , & V_225 ) ;
F_235 ( V_80 , V_258 , 0 , & V_225 ) ;
F_44 ( V_80 ) ;
F_27 ( V_33 ) ;
if ( V_5 ) {
return V_5 ;
}
if ( V_244 )
return 0 ;
if ( V_257 -> V_271 ) {
V_263 = 0 ;
V_264 = V_267 ;
}
V_119:
F_236 ( & log -> V_275 [ V_99 ] ) ;
F_237 (ordered, &log->logged_list[index], log_list) {
struct V_87 * V_276 ;
if ( ! V_262 )
break;
if ( V_260 -> V_69 != V_69 )
continue;
if ( V_260 -> V_277 + V_260 -> V_29 <= V_261 ||
V_261 + V_262 <= V_260 -> V_277 )
continue;
if ( V_260 -> V_277 > V_261 ) {
if ( V_260 -> V_277 + V_260 -> V_29 >=
V_261 + V_262 )
V_262 = V_260 -> V_277 - V_261 ;
} else {
if ( V_260 -> V_277 + V_260 -> V_29 <
V_261 + V_262 ) {
V_262 = ( V_261 + V_262 ) -
( V_260 -> V_277 + V_260 -> V_29 ) ;
V_261 = V_260 -> V_277 +
V_260 -> V_29 ;
} else {
V_262 = 0 ;
}
}
if ( F_238 ( V_278 ,
& V_260 -> V_234 ) )
continue;
F_3 ( & V_260 -> V_279 ) ;
F_239 ( & log -> V_275 [ V_99 ] ) ;
F_240 ( V_260 -> V_31 , V_260 -> V_280 == 0 ) ;
F_237 (sum, &ordered->list, list) {
V_5 = F_66 ( V_2 , log , V_276 ) ;
if ( V_5 ) {
F_241 ( V_260 ) ;
goto V_281;
}
}
F_241 ( V_260 ) ;
goto V_119;
}
F_239 ( & log -> V_275 [ V_99 ] ) ;
V_281:
if ( ! V_262 || V_5 )
return V_5 ;
V_263 = V_261 - V_257 -> V_28 ;
V_264 = V_262 ;
V_5 = F_63 ( log -> V_15 -> V_91 ,
V_257 -> V_269 + V_263 ,
V_257 -> V_269 + V_263 +
V_264 - 1 , & V_86 , 0 ) ;
if ( V_5 )
return V_5 ;
while ( ! F_64 ( & V_86 ) ) {
struct V_87 * V_88 = F_65 ( V_86 . V_89 ,
struct V_87 ,
V_90 ) ;
if ( ! V_5 )
V_5 = F_66 ( V_2 , log , V_88 ) ;
F_67 ( & V_88 -> V_90 ) ;
F_29 ( V_88 ) ;
}
return V_5 ;
}
static int F_242 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_69 * V_69 ,
struct V_32 * V_33 )
{
struct V_254 * V_257 , * V_282 ;
struct V_243 V_283 ;
struct V_284 * V_285 = & F_109 ( V_69 ) -> V_286 ;
T_1 V_287 ;
int V_5 = 0 ;
int V_288 = 0 ;
F_218 ( & V_283 ) ;
F_243 ( & V_285 -> V_289 ) ;
V_287 = V_4 -> V_15 -> V_290 ;
F_244 (em, n, &tree->modified_extents, list) {
F_245 ( & V_257 -> V_90 ) ;
if ( ++ V_288 > 32768 ) {
F_245 ( & V_285 -> V_291 ) ;
V_5 = - V_292 ;
goto V_293;
}
if ( V_257 -> V_226 <= V_287 )
continue;
F_3 ( & V_257 -> V_279 ) ;
F_246 ( V_294 , & V_257 -> V_234 ) ;
F_247 ( & V_257 -> V_90 , & V_283 ) ;
V_288 ++ ;
}
F_248 ( NULL , & V_283 , F_222 ) ;
V_293:
while ( ! F_64 ( & V_283 ) ) {
V_257 = F_65 ( V_283 . V_89 , struct V_254 , V_90 ) ;
F_245 ( & V_257 -> V_90 ) ;
if ( V_5 ) {
F_249 ( V_285 , V_257 ) ;
F_250 ( V_257 ) ;
continue;
}
F_251 ( & V_285 -> V_289 ) ;
V_5 = F_223 ( V_2 , V_69 , V_4 , V_257 , V_33 ) ;
F_243 ( & V_285 -> V_289 ) ;
F_249 ( V_285 , V_257 ) ;
F_250 ( V_257 ) ;
}
F_129 ( ! F_64 ( & V_283 ) ) ;
F_251 ( & V_285 -> V_289 ) ;
F_27 ( V_33 ) ;
return V_5 ;
}
static int F_252 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_69 * V_69 ,
int V_236 )
{
struct V_32 * V_33 ;
struct V_32 * V_212 ;
struct V_35 V_215 ;
struct V_35 V_216 ;
struct V_3 * log = V_4 -> V_8 ;
struct V_20 * V_217 = NULL ;
int V_6 = 0 ;
int V_5 ;
int V_150 ;
int V_295 = 0 ;
int V_296 ;
bool V_297 = false ;
T_1 V_131 = F_54 ( V_69 ) ;
V_33 = F_82 () ;
if ( ! V_33 )
return - V_55 ;
V_212 = F_82 () ;
if ( ! V_212 ) {
F_86 ( V_33 ) ;
return - V_55 ;
}
V_215 . V_46 = V_131 ;
V_215 . type = V_44 ;
V_215 . V_67 = 0 ;
V_216 . V_46 = V_131 ;
if ( F_38 ( V_69 -> V_134 ) ||
( ! F_226 ( V_298 ,
& F_109 ( V_69 ) -> V_299 ) &&
V_236 == V_246 ) )
V_216 . type = V_167 ;
else
V_216 . type = ( T_4 ) - 1 ;
V_216 . V_67 = ( T_1 ) - 1 ;
if ( F_38 ( V_69 -> V_134 ) ||
F_109 ( V_69 ) -> V_226 > V_4 -> V_15 -> V_290 ) {
V_5 = F_253 ( V_2 , V_69 ) ;
if ( V_5 ) {
F_86 ( V_33 ) ;
F_86 ( V_212 ) ;
return V_5 ;
}
}
F_2 ( & F_109 ( V_69 ) -> V_7 ) ;
F_254 ( log , V_69 ) ;
if ( F_38 ( V_69 -> V_134 ) ) {
int V_221 = V_159 ;
if ( V_236 == V_246 )
V_221 = V_167 ;
V_5 = F_190 ( V_2 , log , V_33 , V_131 , V_221 ) ;
} else {
if ( F_255 ( V_298 ,
& F_109 ( V_69 ) -> V_299 ) ) {
F_256 ( V_300 ,
& F_109 ( V_69 ) -> V_299 ) ;
V_5 = F_257 ( V_2 , log ,
V_69 , 0 , 0 ) ;
} else if ( F_255 ( V_300 ,
& F_109 ( V_69 ) -> V_299 ) ) {
if ( V_236 == V_301 )
V_297 = true ;
V_216 . type = V_167 ;
V_5 = F_190 ( V_2 , log , V_33 , V_131 ,
V_216 . type ) ;
} else {
if ( V_236 == V_301 )
V_297 = true ;
V_5 = F_216 ( V_2 , log , V_212 , V_69 ) ;
if ( V_5 ) {
V_6 = V_5 ;
goto V_207;
}
goto V_302;
}
}
if ( V_5 ) {
V_6 = V_5 ;
goto V_207;
}
V_33 -> V_218 = 1 ;
while ( 1 ) {
V_296 = 0 ;
V_5 = F_186 ( V_4 , & V_215 , & V_216 ,
V_33 , V_2 -> V_64 ) ;
if ( V_5 != 0 )
break;
V_119:
if ( V_215 . V_46 != V_131 )
break;
if ( V_215 . type > V_216 . type )
break;
V_217 = V_33 -> V_51 [ 0 ] ;
if ( V_296 && V_295 + V_296 == V_33 -> V_52 [ 0 ] ) {
V_296 ++ ;
goto V_303;
} else if ( ! V_296 ) {
V_295 = V_33 -> V_52 [ 0 ] ;
V_296 = 1 ;
goto V_303;
}
V_5 = F_217 ( V_2 , V_69 , V_212 , V_217 , V_295 ,
V_296 , V_236 ) ;
if ( V_5 ) {
V_6 = V_5 ;
goto V_207;
}
V_296 = 1 ;
V_295 = V_33 -> V_52 [ 0 ] ;
V_303:
V_150 = F_123 ( V_33 -> V_51 [ 0 ] ) ;
V_33 -> V_52 [ 0 ] ++ ;
if ( V_33 -> V_52 [ 0 ] < V_150 ) {
F_106 ( V_33 -> V_51 [ 0 ] , & V_215 ,
V_33 -> V_52 [ 0 ] ) ;
goto V_119;
}
if ( V_296 ) {
V_5 = F_217 ( V_2 , V_69 , V_212 , V_217 ,
V_295 ,
V_296 , V_236 ) ;
if ( V_5 ) {
V_6 = V_5 ;
goto V_207;
}
V_296 = 0 ;
}
F_27 ( V_33 ) ;
if ( V_215 . V_67 < ( T_1 ) - 1 )
V_215 . V_67 ++ ;
else if ( V_215 . type < ( T_4 ) - 1 )
V_215 . type ++ ;
else if ( V_215 . V_46 < ( T_1 ) - 1 )
V_215 . V_46 ++ ;
else
break;
}
if ( V_296 ) {
V_5 = F_217 ( V_2 , V_69 , V_212 , V_217 , V_295 ,
V_296 , V_236 ) ;
if ( V_5 ) {
V_6 = V_5 ;
goto V_207;
}
V_296 = 0 ;
}
V_302:
F_27 ( V_33 ) ;
F_27 ( V_212 ) ;
if ( V_297 ) {
V_5 = F_242 ( V_2 , V_4 , V_69 , V_212 ) ;
if ( V_5 ) {
V_6 = V_5 ;
goto V_207;
}
} else {
struct V_284 * V_285 = & F_109 ( V_69 ) -> V_286 ;
struct V_254 * V_257 , * V_282 ;
F_243 ( & V_285 -> V_289 ) ;
F_244 (em, n, &tree->modified_extents, list)
F_245 ( & V_257 -> V_90 ) ;
F_251 ( & V_285 -> V_289 ) ;
}
if ( V_236 == V_301 && F_38 ( V_69 -> V_134 ) ) {
V_5 = F_189 ( V_2 , V_4 , V_69 , V_33 , V_212 ) ;
if ( V_5 ) {
V_6 = V_5 ;
goto V_207;
}
}
F_109 ( V_69 ) -> V_206 = V_2 -> V_64 ;
F_109 ( V_69 ) -> V_201 = F_109 ( V_69 ) -> V_304 ;
V_207:
if ( V_6 )
F_160 ( log , log -> V_180 ) ;
F_4 ( & F_109 ( V_69 ) -> V_7 ) ;
F_86 ( V_33 ) ;
F_86 ( V_212 ) ;
return V_6 ;
}
static T_2 int F_258 ( struct V_1 * V_2 ,
struct V_69 * V_69 ,
struct V_305 * V_173 ,
struct V_306 * V_307 ,
T_1 V_308 )
{
int V_5 = 0 ;
struct V_3 * V_4 ;
struct V_305 * V_309 = NULL ;
if ( F_127 ( V_69 -> V_134 ) &&
F_109 ( V_69 ) -> V_226 <= V_308 &&
F_109 ( V_69 ) -> V_310 <= V_308 )
goto V_75;
if ( ! F_38 ( V_69 -> V_134 ) ) {
if ( ! V_173 || ! V_173 -> V_311 || V_307 != V_173 -> V_311 -> V_312 )
goto V_75;
V_69 = V_173 -> V_311 ;
}
while ( 1 ) {
F_109 ( V_69 ) -> V_206 = V_2 -> V_64 ;
F_8 () ;
if ( F_109 ( V_69 ) -> V_310 > V_308 ) {
V_4 = F_109 ( V_69 ) -> V_4 ;
V_4 -> V_15 -> V_184 =
V_2 -> V_64 ;
V_5 = 1 ;
break;
}
if ( ! V_173 || ! V_173 -> V_311 || V_307 != V_173 -> V_311 -> V_312 )
break;
if ( F_259 ( V_173 ) )
break;
V_173 = F_260 ( V_173 ) ;
F_261 ( V_309 ) ;
V_309 = V_173 ;
V_69 = V_173 -> V_311 ;
}
F_261 ( V_309 ) ;
V_75:
return V_5 ;
}
static int F_262 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_69 * V_69 ,
struct V_305 * V_173 , int V_313 )
{
int V_236 = V_313 ? V_246 : V_301 ;
struct V_306 * V_307 ;
struct V_305 * V_309 = NULL ;
int V_5 = 0 ;
T_1 V_308 = V_4 -> V_15 -> V_290 ;
V_307 = V_69 -> V_312 ;
if ( F_158 ( V_4 , V_314 ) ) {
V_5 = 1 ;
goto V_315;
}
if ( V_4 -> V_15 -> V_184 >
V_4 -> V_15 -> V_290 ) {
V_5 = 1 ;
goto V_315;
}
if ( V_4 != F_109 ( V_69 ) -> V_4 ||
F_263 ( & V_4 -> V_181 ) == 0 ) {
V_5 = 1 ;
goto V_315;
}
V_5 = F_258 ( V_2 , V_69 , V_173 ,
V_307 , V_308 ) ;
if ( V_5 )
goto V_315;
if ( F_264 ( V_69 , V_2 -> V_64 ) ) {
V_5 = V_316 ;
goto V_315;
}
V_5 = F_1 ( V_2 , V_4 ) ;
if ( V_5 )
goto V_317;
V_5 = F_252 ( V_2 , V_4 , V_69 , V_236 ) ;
if ( V_5 )
goto V_317;
if ( F_127 ( V_69 -> V_134 ) &&
F_109 ( V_69 ) -> V_226 <= V_308 &&
F_109 ( V_69 ) -> V_310 <= V_308 ) {
V_5 = 0 ;
goto V_317;
}
V_236 = V_246 ;
while ( 1 ) {
if ( ! V_173 || ! V_173 -> V_311 || V_307 != V_173 -> V_311 -> V_312 )
break;
V_69 = V_173 -> V_311 ;
if ( V_4 != F_109 ( V_69 ) -> V_4 )
break;
if ( F_109 ( V_69 ) -> V_226 >
V_4 -> V_15 -> V_290 ) {
V_5 = F_252 ( V_2 , V_4 , V_69 , V_236 ) ;
if ( V_5 )
goto V_317;
}
if ( F_259 ( V_173 ) )
break;
V_173 = F_260 ( V_173 ) ;
F_261 ( V_309 ) ;
V_309 = V_173 ;
}
V_5 = 0 ;
V_317:
F_261 ( V_309 ) ;
if ( V_5 < 0 ) {
V_4 -> V_15 -> V_184 = V_2 -> V_64 ;
V_5 = 1 ;
}
F_10 ( V_4 ) ;
V_315:
return V_5 ;
}
int F_265 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_305 * V_305 )
{
struct V_305 * V_173 = F_260 ( V_305 ) ;
int V_5 ;
V_5 = F_262 ( V_2 , V_4 , V_305 -> V_311 , V_173 , 0 ) ;
F_261 ( V_173 ) ;
return V_5 ;
}
int F_266 ( struct V_3 * V_17 )
{
int V_5 ;
struct V_32 * V_33 ;
struct V_1 * V_2 ;
struct V_35 V_36 ;
struct V_35 V_138 ;
struct V_35 V_318 ;
struct V_3 * log ;
struct V_203 * V_15 = V_17 -> V_15 ;
struct V_22 V_23 = {
. V_176 = F_14 ,
. V_163 = 0 ,
} ;
V_33 = F_82 () ;
if ( ! V_33 )
return - V_55 ;
V_15 -> V_319 = 1 ;
V_2 = F_267 ( V_15 -> V_200 , 0 ) ;
if ( F_79 ( V_2 ) ) {
V_5 = F_179 ( V_2 ) ;
goto error;
}
V_23 . V_2 = V_2 ;
V_23 . V_26 = 1 ;
V_5 = F_144 ( V_2 , V_17 , & V_23 ) ;
if ( V_5 ) {
F_268 ( V_15 , V_5 , L_1
L_2 ) ;
goto error;
}
V_119:
V_36 . V_46 = V_47 ;
V_36 . V_67 = ( T_1 ) - 1 ;
F_113 ( & V_36 , V_320 ) ;
while ( 1 ) {
V_5 = F_26 ( NULL , V_17 , & V_36 , V_33 , 0 , 0 ) ;
if ( V_5 < 0 ) {
F_268 ( V_15 , V_5 ,
L_3 ) ;
goto error;
}
if ( V_5 > 0 ) {
if ( V_33 -> V_52 [ 0 ] == 0 )
break;
V_33 -> V_52 [ 0 ] -- ;
}
F_106 ( V_33 -> V_51 [ 0 ] , & V_138 ,
V_33 -> V_52 [ 0 ] ) ;
F_27 ( V_33 ) ;
if ( V_138 . V_46 != V_47 )
break;
log = F_269 ( V_17 , & V_138 ) ;
if ( F_79 ( log ) ) {
V_5 = F_179 ( log ) ;
F_268 ( V_15 , V_5 ,
L_4 ) ;
goto error;
}
V_318 . V_46 = V_138 . V_67 ;
V_318 . type = V_320 ;
V_318 . V_67 = ( T_1 ) - 1 ;
V_23 . V_160 = F_270 ( V_15 , & V_318 ) ;
if ( F_79 ( V_23 . V_160 ) ) {
V_5 = F_179 ( V_23 . V_160 ) ;
F_135 ( log -> V_177 ) ;
F_135 ( log -> V_321 ) ;
F_29 ( log ) ;
F_268 ( V_15 , V_5 , L_5
L_6 ) ;
goto error;
}
V_23 . V_160 -> V_8 = log ;
F_271 ( V_2 , V_23 . V_160 ) ;
V_5 = F_144 ( V_2 , log , & V_23 ) ;
if ( ! V_5 && V_23 . V_163 == V_166 ) {
V_5 = F_111 ( V_2 , V_23 . V_160 ,
V_33 ) ;
}
V_36 . V_67 = V_138 . V_67 - 1 ;
V_23 . V_160 -> V_8 = NULL ;
F_135 ( log -> V_177 ) ;
F_135 ( log -> V_321 ) ;
F_29 ( log ) ;
if ( V_5 )
goto error;
if ( V_138 . V_67 == 0 )
break;
}
F_27 ( V_33 ) ;
if ( V_23 . V_26 ) {
V_23 . V_26 = 0 ;
V_23 . V_176 = F_126 ;
V_23 . V_163 = V_164 ;
goto V_119;
}
if ( V_23 . V_163 < V_166 ) {
V_23 . V_163 ++ ;
goto V_119;
}
F_86 ( V_33 ) ;
V_5 = F_272 ( V_2 , V_15 -> V_200 ) ;
if ( V_5 )
return V_5 ;
F_135 ( V_17 -> V_177 ) ;
V_17 -> V_8 = NULL ;
V_15 -> V_319 = 0 ;
F_29 ( V_17 ) ;
return 0 ;
error:
if ( V_23 . V_2 )
F_273 ( V_23 . V_2 , V_15 -> V_200 ) ;
F_86 ( V_33 ) ;
return V_5 ;
}
void F_274 ( struct V_1 * V_2 ,
struct V_69 * V_92 , struct V_69 * V_69 ,
int V_322 )
{
if ( F_127 ( V_69 -> V_134 ) )
F_109 ( V_69 ) -> V_310 = V_2 -> V_64 ;
F_8 () ;
if ( F_109 ( V_92 ) -> V_206 == V_2 -> V_64 )
return;
if ( F_109 ( V_69 ) -> V_206 == V_2 -> V_64 )
return;
if ( V_322 )
goto V_323;
return;
V_323:
F_109 ( V_92 ) -> V_310 = V_2 -> V_64 ;
}
int F_275 ( struct V_1 * V_2 ,
struct V_69 * V_69 , struct V_69 * V_324 ,
struct V_305 * V_173 )
{
struct V_3 * V_4 = F_109 ( V_69 ) -> V_4 ;
if ( F_127 ( V_69 -> V_134 ) )
F_109 ( V_69 ) -> V_310 = V_2 -> V_64 ;
if ( F_109 ( V_69 ) -> V_206 <=
V_4 -> V_15 -> V_290 &&
( ! V_324 || F_109 ( V_324 ) -> V_206 <=
V_4 -> V_15 -> V_290 ) )
return 0 ;
return F_262 ( V_2 , V_4 , V_69 , V_173 , 1 ) ;
}
