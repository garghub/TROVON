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
if ( V_23 -> V_25 )
V_5 = F_15 ( log -> V_15 -> V_26 ,
V_21 -> V_27 , V_21 -> V_28 ) ;
if ( ! V_5 && F_16 ( V_21 , V_24 , 0 ) ) {
if ( V_23 -> V_29 )
F_17 ( V_21 ) ;
if ( V_23 -> V_30 )
F_18 ( V_21 ) ;
}
return V_5 ;
}
static T_2 int F_19 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_31 * V_32 ,
struct V_20 * V_21 , int V_33 ,
struct V_34 * V_35 )
{
int V_5 ;
T_3 V_36 ;
T_1 V_37 = 0 ;
int V_38 = 0 ;
unsigned long V_39 ;
unsigned long V_40 ;
int V_41 = 0 ;
bool V_42 = V_35 -> type == V_43 ;
if ( V_4 -> V_44 . V_45 != V_46 )
V_41 = 1 ;
V_36 = F_20 ( V_21 , V_33 ) ;
V_39 = F_21 ( V_21 , V_33 ) ;
V_5 = F_22 ( NULL , V_4 , V_35 , V_32 , 0 , 0 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( V_5 == 0 ) {
char * V_47 ;
char * V_48 ;
T_3 V_49 = F_20 ( V_32 -> V_50 [ 0 ] ,
V_32 -> V_51 [ 0 ] ) ;
if ( V_49 != V_36 )
goto V_52;
if ( V_36 == 0 ) {
F_23 ( V_32 ) ;
return 0 ;
}
V_48 = F_24 ( V_36 , V_53 ) ;
V_47 = F_24 ( V_36 , V_53 ) ;
if ( ! V_48 || ! V_47 ) {
F_23 ( V_32 ) ;
F_25 ( V_48 ) ;
F_25 ( V_47 ) ;
return - V_54 ;
}
F_26 ( V_21 , V_47 , V_39 , V_36 ) ;
V_40 = F_21 ( V_32 -> V_50 [ 0 ] , V_32 -> V_51 [ 0 ] ) ;
F_26 ( V_32 -> V_50 [ 0 ] , V_48 , V_40 ,
V_36 ) ;
V_5 = memcmp ( V_48 , V_47 , V_36 ) ;
F_25 ( V_48 ) ;
F_25 ( V_47 ) ;
if ( V_5 == 0 ) {
F_23 ( V_32 ) ;
return 0 ;
}
if ( V_42 ) {
struct V_55 * V_56 ;
T_1 V_57 ;
V_56 = F_27 ( V_32 -> V_50 [ 0 ] , V_32 -> V_51 [ 0 ] ,
struct V_55 ) ;
V_57 = F_28 ( V_32 -> V_50 [ 0 ] , V_56 ) ;
V_56 = F_27 ( V_21 , V_33 ,
struct V_55 ) ;
F_29 ( V_21 , V_56 , V_57 ) ;
}
} else if ( V_42 ) {
struct V_55 * V_56 ;
V_56 = F_27 ( V_21 , V_33 , struct V_55 ) ;
F_29 ( V_21 , V_56 , 0 ) ;
}
V_52:
F_23 ( V_32 ) ;
V_5 = F_30 ( V_2 , V_4 , V_32 ,
V_35 , V_36 ) ;
if ( V_5 == - V_58 ) {
T_3 V_59 ;
V_59 = F_20 ( V_32 -> V_50 [ 0 ] ,
V_32 -> V_51 [ 0 ] ) ;
if ( V_59 > V_36 )
F_31 ( V_4 , V_32 , V_36 , 1 ) ;
else if ( V_59 < V_36 )
F_32 ( V_4 , V_32 ,
V_36 - V_59 ) ;
} else if ( V_5 ) {
return V_5 ;
}
V_40 = F_21 ( V_32 -> V_50 [ 0 ] ,
V_32 -> V_51 [ 0 ] ) ;
if ( V_35 -> type == V_43 && V_5 == - V_58 ) {
struct V_55 * V_60 ;
struct V_55 * V_61 ;
V_60 = (struct V_55 * ) V_39 ;
V_61 = (struct V_55 * ) V_40 ;
if ( F_33 ( V_21 , V_60 ) == 0 )
goto V_62;
if ( V_41 &&
F_34 ( F_35 ( V_21 , V_60 ) ) &&
F_34 ( F_35 ( V_32 -> V_50 [ 0 ] , V_61 ) ) ) {
V_38 = 1 ;
V_37 = F_36 ( V_32 -> V_50 [ 0 ] ,
V_61 ) ;
}
}
F_37 ( V_32 -> V_50 [ 0 ] , V_21 , V_40 ,
V_39 , V_36 ) ;
if ( V_38 ) {
struct V_55 * V_61 ;
V_61 = (struct V_55 * ) V_40 ;
F_38 ( V_32 -> V_50 [ 0 ] , V_61 , V_37 ) ;
}
if ( V_35 -> type == V_43 ) {
struct V_55 * V_61 ;
V_61 = (struct V_55 * ) V_40 ;
if ( F_33 ( V_32 -> V_50 [ 0 ] , V_61 ) == 0 ) {
F_39 ( V_32 -> V_50 [ 0 ] , V_61 ,
V_2 -> V_63 ) ;
}
}
V_62:
F_40 ( V_32 -> V_50 [ 0 ] ) ;
F_23 ( V_32 ) ;
return 0 ;
}
T_2 int F_41 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_31 * V_32 ,
struct V_20 * V_21 , int V_33 ,
struct V_34 * V_35 )
{
int V_64 ;
T_1 V_65 ;
T_1 V_27 = V_35 -> V_66 ;
T_1 V_57 = 0 ;
struct V_67 * V_56 ;
struct V_68 * V_68 = NULL ;
unsigned long V_69 ;
int V_5 = 0 ;
V_56 = F_27 ( V_21 , V_33 , struct V_67 ) ;
V_64 = F_42 ( V_21 , V_56 ) ;
if ( V_64 == V_70 ||
V_64 == V_71 ) {
V_57 = F_43 ( V_21 , V_56 ) ;
V_65 = V_27 + V_57 ;
if ( F_44 ( V_21 , V_56 ) == 0 )
V_57 = 0 ;
} else if ( V_64 == V_72 ) {
V_69 = F_45 ( V_21 , V_56 ) ;
V_57 = F_46 ( V_21 , V_56 ) ;
V_65 = F_47 ( V_27 + V_69 , V_4 -> V_73 ) ;
} else {
V_5 = 0 ;
goto V_74;
}
V_68 = F_48 ( V_4 , V_35 -> V_45 ) ;
if ( ! V_68 ) {
V_5 = - V_75 ;
goto V_74;
}
V_5 = F_49 ( V_2 , V_4 , V_32 , F_50 ( V_68 ) ,
V_27 , 0 ) ;
if ( V_5 == 0 &&
( V_64 == V_70 ||
V_64 == V_71 ) ) {
struct V_67 V_76 ;
struct V_67 V_77 ;
struct V_67 * V_78 ;
struct V_20 * V_79 ;
V_79 = V_32 -> V_50 [ 0 ] ;
V_78 = F_27 ( V_79 , V_32 -> V_51 [ 0 ] ,
struct V_67 ) ;
F_26 ( V_21 , & V_76 , ( unsigned long ) V_56 ,
sizeof( V_76 ) ) ;
F_26 ( V_79 , & V_77 , ( unsigned long ) V_78 ,
sizeof( V_77 ) ) ;
if ( memcmp ( & V_76 , & V_77 , sizeof( V_76 ) ) == 0 ) {
F_23 ( V_32 ) ;
goto V_74;
}
}
F_23 ( V_32 ) ;
V_5 = F_51 ( V_2 , V_4 , V_68 , V_27 , V_65 , 1 ) ;
if ( V_5 )
goto V_74;
if ( V_64 == V_70 ||
V_64 == V_71 ) {
T_1 V_66 ;
unsigned long V_80 ;
struct V_34 V_81 ;
V_5 = F_30 ( V_2 , V_4 , V_32 , V_35 ,
sizeof( * V_56 ) ) ;
if ( V_5 )
goto V_74;
V_80 = F_21 ( V_32 -> V_50 [ 0 ] ,
V_32 -> V_51 [ 0 ] ) ;
F_37 ( V_32 -> V_50 [ 0 ] , V_21 , V_80 ,
( unsigned long ) V_56 , sizeof( * V_56 ) ) ;
V_81 . V_45 = F_44 ( V_21 , V_56 ) ;
V_81 . V_66 = F_52 ( V_21 , V_56 ) ;
V_81 . type = V_82 ;
V_66 = V_35 -> V_66 - F_53 ( V_21 , V_56 ) ;
if ( V_81 . V_45 > 0 ) {
T_1 V_83 ;
T_1 V_84 ;
F_54 ( V_85 ) ;
V_5 = F_55 ( V_4 , V_81 . V_45 ,
V_81 . V_66 ) ;
if ( V_5 == 0 ) {
V_5 = F_56 ( V_2 , V_4 ,
V_81 . V_45 , V_81 . V_66 ,
0 , V_4 -> V_44 . V_45 ,
V_35 -> V_45 , V_66 , 0 ) ;
if ( V_5 )
goto V_74;
} else {
V_5 = F_57 ( V_2 ,
V_4 , V_4 -> V_44 . V_45 ,
V_35 -> V_45 , V_66 , & V_81 ) ;
if ( V_5 )
goto V_74;
}
F_23 ( V_32 ) ;
if ( F_58 ( V_21 , V_56 ) ) {
V_83 = V_81 . V_45 ;
V_84 = V_83 + V_81 . V_66 ;
} else {
V_83 = V_81 . V_45 +
F_53 ( V_21 , V_56 ) ;
V_84 = V_83 +
F_43 ( V_21 , V_56 ) ;
}
V_5 = F_59 ( V_4 -> V_8 ,
V_83 , V_84 - 1 ,
& V_85 , 0 ) ;
if ( V_5 )
goto V_74;
while ( ! F_60 ( & V_85 ) ) {
struct V_86 * V_87 ;
V_87 = F_61 ( V_85 . V_88 ,
struct V_86 ,
V_89 ) ;
if ( ! V_5 )
V_5 = F_62 ( V_2 ,
V_4 -> V_15 -> V_90 ,
V_87 ) ;
F_63 ( & V_87 -> V_89 ) ;
F_25 ( V_87 ) ;
}
if ( V_5 )
goto V_74;
} else {
F_23 ( V_32 ) ;
}
} else if ( V_64 == V_72 ) {
V_5 = F_19 ( V_2 , V_4 , V_32 , V_21 , V_33 , V_35 ) ;
if ( V_5 )
goto V_74;
}
F_64 ( V_68 , V_57 ) ;
V_5 = F_65 ( V_2 , V_4 , V_68 ) ;
V_74:
if ( V_68 )
F_66 ( V_68 ) ;
return V_5 ;
}
static T_2 int F_67 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_31 * V_32 ,
struct V_68 * V_91 ,
struct V_92 * V_93 )
{
struct V_68 * V_68 ;
char * V_94 ;
int V_95 ;
struct V_20 * V_79 ;
struct V_34 V_96 ;
int V_5 ;
V_79 = V_32 -> V_50 [ 0 ] ;
F_68 ( V_79 , V_93 , & V_96 ) ;
V_95 = F_69 ( V_79 , V_93 ) ;
V_94 = F_24 ( V_95 , V_53 ) ;
if ( ! V_94 )
return - V_54 ;
F_26 ( V_79 , V_94 , ( unsigned long ) ( V_93 + 1 ) , V_95 ) ;
F_23 ( V_32 ) ;
V_68 = F_48 ( V_4 , V_96 . V_45 ) ;
if ( ! V_68 ) {
V_5 = - V_75 ;
goto V_74;
}
V_5 = F_70 ( V_2 , V_4 , V_32 , V_96 . V_45 ) ;
if ( V_5 )
goto V_74;
V_5 = F_71 ( V_2 , V_4 , V_91 , V_68 , V_94 , V_95 ) ;
if ( V_5 )
goto V_74;
F_72 ( V_2 , V_4 ) ;
V_74:
F_25 ( V_94 ) ;
F_66 ( V_68 ) ;
return V_5 ;
}
static T_2 int F_73 ( struct V_3 * V_4 ,
struct V_31 * V_32 ,
T_1 V_97 , T_1 V_45 , T_1 V_98 ,
const char * V_94 , int V_95 )
{
struct V_92 * V_93 ;
struct V_34 V_96 ;
int V_99 = 0 ;
V_93 = F_74 ( NULL , V_4 , V_32 , V_97 ,
V_98 , V_94 , V_95 , 0 ) ;
if ( V_93 && ! F_75 ( V_93 ) ) {
F_68 ( V_32 -> V_50 [ 0 ] , V_93 , & V_96 ) ;
if ( V_96 . V_45 != V_45 )
goto V_74;
} else
goto V_74;
F_23 ( V_32 ) ;
V_93 = F_76 ( NULL , V_4 , V_32 , V_97 , V_94 , V_95 , 0 ) ;
if ( V_93 && ! F_75 ( V_93 ) ) {
F_68 ( V_32 -> V_50 [ 0 ] , V_93 , & V_96 ) ;
if ( V_96 . V_45 != V_45 )
goto V_74;
} else
goto V_74;
V_99 = 1 ;
V_74:
F_23 ( V_32 ) ;
return V_99 ;
}
static T_2 int F_77 ( struct V_3 * log ,
struct V_34 * V_35 ,
T_1 V_100 ,
char * V_94 , int V_101 )
{
struct V_31 * V_32 ;
struct V_102 * V_103 ;
unsigned long V_104 ;
unsigned long V_105 ;
unsigned long V_106 ;
int V_107 ;
int V_36 ;
int V_5 ;
int V_99 = 0 ;
V_32 = F_78 () ;
if ( ! V_32 )
return - V_54 ;
V_5 = F_22 ( NULL , log , V_35 , V_32 , 0 , 0 ) ;
if ( V_5 != 0 )
goto V_74;
V_104 = F_21 ( V_32 -> V_50 [ 0 ] , V_32 -> V_51 [ 0 ] ) ;
if ( V_35 -> type == V_108 ) {
if ( F_79 ( V_32 , V_100 ,
V_94 , V_101 , NULL ) )
V_99 = 1 ;
goto V_74;
}
V_36 = F_20 ( V_32 -> V_50 [ 0 ] , V_32 -> V_51 [ 0 ] ) ;
V_105 = V_104 + V_36 ;
while ( V_104 < V_105 ) {
V_103 = (struct V_102 * ) V_104 ;
V_107 = F_80 ( V_32 -> V_50 [ 0 ] , V_103 ) ;
if ( V_107 == V_101 ) {
V_106 = ( unsigned long ) ( V_103 + 1 ) ;
V_5 = F_81 ( V_32 -> V_50 [ 0 ] , V_94 ,
V_106 , V_101 ) ;
if ( V_5 == 0 ) {
V_99 = 1 ;
goto V_74;
}
}
V_104 = ( unsigned long ) ( V_103 + 1 ) + V_107 ;
}
V_74:
F_82 ( V_32 ) ;
return V_99 ;
}
static inline int F_83 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_31 * V_32 ,
struct V_3 * V_8 ,
struct V_68 * V_91 , struct V_68 * V_68 ,
struct V_20 * V_21 ,
T_1 V_109 , T_1 V_110 ,
T_1 V_111 , char * V_94 , int V_101 ,
int * V_112 )
{
int V_5 ;
char * V_113 ;
int V_114 ;
struct V_20 * V_79 ;
struct V_92 * V_93 ;
struct V_34 V_115 ;
struct V_116 * V_117 ;
V_118:
V_115 . V_45 = V_109 ;
V_115 . type = V_119 ;
V_115 . V_66 = V_110 ;
V_5 = F_22 ( NULL , V_4 , & V_115 , V_32 , 0 , 0 ) ;
if ( V_5 == 0 ) {
struct V_102 * V_120 ;
unsigned long V_104 ;
unsigned long V_105 ;
V_79 = V_32 -> V_50 [ 0 ] ;
if ( V_115 . V_45 == V_115 . V_66 )
return 1 ;
V_104 = F_21 ( V_79 , V_32 -> V_51 [ 0 ] ) ;
V_105 = V_104 + F_20 ( V_79 , V_32 -> V_51 [ 0 ] ) ;
while ( V_104 < V_105 ) {
V_120 = (struct V_102 * ) V_104 ;
V_114 = F_80 ( V_79 ,
V_120 ) ;
V_113 = F_24 ( V_114 , V_53 ) ;
if ( ! V_113 )
return - V_54 ;
F_26 ( V_79 , V_113 ,
( unsigned long ) ( V_120 + 1 ) ,
V_114 ) ;
if ( ! F_77 ( V_8 , & V_115 ,
V_110 ,
V_113 ,
V_114 ) ) {
F_84 ( V_68 ) ;
F_23 ( V_32 ) ;
V_5 = F_71 ( V_2 , V_4 , V_91 ,
V_68 , V_113 ,
V_114 ) ;
F_25 ( V_113 ) ;
if ( V_5 )
return V_5 ;
F_72 ( V_2 , V_4 ) ;
* V_112 = 1 ;
goto V_118;
}
F_25 ( V_113 ) ;
V_104 = ( unsigned long ) ( V_120 + 1 ) + V_114 ;
}
* V_112 = 1 ;
}
F_23 ( V_32 ) ;
V_117 = F_85 ( NULL , V_4 , V_32 , V_94 , V_101 ,
V_109 , V_110 , 0 ,
0 ) ;
if ( ! F_86 ( V_117 ) ) {
T_3 V_36 ;
T_3 V_121 = 0 ;
unsigned long V_122 ;
struct V_68 * V_123 ;
V_79 = V_32 -> V_50 [ 0 ] ;
V_36 = F_20 ( V_79 , V_32 -> V_51 [ 0 ] ) ;
V_122 = F_21 ( V_79 , V_32 -> V_51 [ 0 ] ) ;
while ( V_121 < V_36 ) {
V_117 = (struct V_116 * ) V_122 + V_121 ;
V_114 = F_87 ( V_79 , V_117 ) ;
if ( F_88 ( V_79 , V_117 ) != V_110 )
goto V_88;
V_113 = F_24 ( V_114 , V_53 ) ;
if ( ! V_113 )
return - V_54 ;
F_26 ( V_79 , V_113 , ( unsigned long ) & V_117 -> V_94 ,
V_114 ) ;
V_115 . V_45 = V_109 ;
V_115 . type = V_108 ;
V_115 . V_66 = F_89 ( V_110 ,
V_113 ,
V_114 ) ;
V_5 = 0 ;
if ( ! F_77 ( V_8 , & V_115 ,
V_110 , V_113 ,
V_114 ) ) {
V_5 = - V_18 ;
V_123 = F_48 ( V_4 ,
V_110 ) ;
if ( V_123 ) {
F_84 ( V_68 ) ;
F_23 ( V_32 ) ;
V_5 = F_71 ( V_2 , V_4 ,
V_123 ,
V_68 ,
V_113 ,
V_114 ) ;
F_72 ( V_2 , V_4 ) ;
}
F_66 ( V_123 ) ;
F_25 ( V_113 ) ;
if ( V_5 )
return V_5 ;
* V_112 = 1 ;
goto V_118;
}
F_25 ( V_113 ) ;
if ( V_5 )
return V_5 ;
V_88:
V_121 += V_114 + sizeof( * V_117 ) ;
}
* V_112 = 1 ;
}
F_23 ( V_32 ) ;
V_93 = F_74 ( V_2 , V_4 , V_32 , F_50 ( V_91 ) ,
V_111 , V_94 , V_101 , 0 ) ;
if ( V_93 && ! F_75 ( V_93 ) ) {
V_5 = F_67 ( V_2 , V_4 , V_32 , V_91 , V_93 ) ;
if ( V_5 )
return V_5 ;
}
F_23 ( V_32 ) ;
V_93 = F_76 ( V_2 , V_4 , V_32 , F_50 ( V_91 ) ,
V_94 , V_101 , 0 ) ;
if ( V_93 && ! F_75 ( V_93 ) ) {
V_5 = F_67 ( V_2 , V_4 , V_32 , V_91 , V_93 ) ;
if ( V_5 )
return V_5 ;
}
F_23 ( V_32 ) ;
return 0 ;
}
static int F_90 ( struct V_20 * V_21 , unsigned long V_124 ,
T_3 * V_101 , char * * V_94 , T_1 * V_98 ,
T_1 * V_110 )
{
struct V_116 * V_117 ;
V_117 = (struct V_116 * ) V_124 ;
* V_101 = F_87 ( V_21 , V_117 ) ;
* V_94 = F_24 ( * V_101 , V_53 ) ;
if ( * V_94 == NULL )
return - V_54 ;
F_26 ( V_21 , * V_94 , ( unsigned long ) & V_117 -> V_94 ,
* V_101 ) ;
* V_98 = F_91 ( V_21 , V_117 ) ;
if ( V_110 )
* V_110 = F_88 ( V_21 , V_117 ) ;
return 0 ;
}
static int F_92 ( struct V_20 * V_21 , unsigned long V_124 ,
T_3 * V_101 , char * * V_94 , T_1 * V_98 )
{
struct V_102 * V_103 ;
V_103 = (struct V_102 * ) V_124 ;
* V_101 = F_80 ( V_21 , V_103 ) ;
* V_94 = F_24 ( * V_101 , V_53 ) ;
if ( * V_94 == NULL )
return - V_54 ;
F_26 ( V_21 , * V_94 , ( unsigned long ) ( V_103 + 1 ) , * V_101 ) ;
* V_98 = F_93 ( V_21 , V_103 ) ;
return 0 ;
}
static T_2 int F_94 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_3 * log ,
struct V_31 * V_32 ,
struct V_20 * V_21 , int V_33 ,
struct V_34 * V_35 )
{
struct V_68 * V_91 ;
struct V_68 * V_68 ;
unsigned long V_124 ;
unsigned long V_125 ;
char * V_94 ;
int V_101 ;
int V_5 ;
int V_112 = 0 ;
int V_126 = 0 ;
T_1 V_110 ;
T_1 V_109 ;
T_1 V_111 = 0 ;
int V_127 ;
V_124 = F_21 ( V_21 , V_33 ) ;
V_125 = V_124 + F_20 ( V_21 , V_33 ) ;
if ( V_35 -> type == V_108 ) {
struct V_116 * V_128 ;
V_127 = sizeof( struct V_116 ) ;
V_126 = 1 ;
V_128 = (struct V_116 * ) V_124 ;
V_110 = F_88 ( V_21 , V_128 ) ;
} else {
V_127 = sizeof( struct V_102 ) ;
V_110 = V_35 -> V_66 ;
}
V_109 = V_35 -> V_45 ;
V_91 = F_48 ( V_4 , V_110 ) ;
if ( ! V_91 )
return - V_18 ;
V_68 = F_48 ( V_4 , V_109 ) ;
if ( ! V_68 ) {
F_66 ( V_91 ) ;
return - V_75 ;
}
while ( V_124 < V_125 ) {
if ( V_126 ) {
V_5 = F_90 ( V_21 , V_124 , & V_101 , & V_94 ,
& V_111 , & V_110 ) ;
if ( ! V_91 )
V_91 = F_48 ( V_4 , V_110 ) ;
if ( ! V_91 )
return - V_18 ;
} else {
V_5 = F_92 ( V_21 , V_124 , & V_101 , & V_94 ,
& V_111 ) ;
}
if ( V_5 )
return V_5 ;
if ( ! F_73 ( V_4 , V_32 , F_50 ( V_91 ) , F_50 ( V_68 ) ,
V_111 , V_94 , V_101 ) ) {
if ( ! V_112 ) {
V_5 = F_83 ( V_2 , V_4 , V_32 , log ,
V_91 , V_68 , V_21 ,
V_109 ,
V_110 ,
V_111 , V_94 , V_101 ,
& V_112 ) ;
if ( V_5 == 1 ) {
V_5 = 0 ;
goto V_74;
}
if ( V_5 )
goto V_74;
}
V_5 = F_95 ( V_2 , V_91 , V_68 , V_94 , V_101 ,
0 , V_111 ) ;
if ( V_5 )
goto V_74;
F_65 ( V_2 , V_4 , V_68 ) ;
}
V_124 = ( unsigned long ) ( V_124 + V_127 ) + V_101 ;
F_25 ( V_94 ) ;
if ( V_126 ) {
F_66 ( V_91 ) ;
V_91 = NULL ;
}
}
V_5 = F_19 ( V_2 , V_4 , V_32 , V_21 , V_33 , V_35 ) ;
V_74:
F_23 ( V_32 ) ;
F_66 ( V_91 ) ;
F_66 ( V_68 ) ;
return V_5 ;
}
static int F_96 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_1 V_66 )
{
int V_5 ;
V_5 = F_97 ( V_4 , V_66 ) ;
if ( V_5 > 0 )
V_5 = F_98 ( V_2 , V_4 , V_66 ) ;
return V_5 ;
}
static int F_99 ( struct V_3 * V_4 ,
struct V_68 * V_68 , struct V_31 * V_32 )
{
int V_5 = 0 ;
int V_95 ;
unsigned int V_129 = 0 ;
T_3 V_36 ;
T_3 V_121 = 0 ;
T_1 V_109 = F_50 ( V_68 ) ;
T_1 V_66 = 0 ;
unsigned long V_104 ;
struct V_116 * V_117 ;
struct V_20 * V_79 ;
while ( 1 ) {
V_5 = F_100 ( V_4 , V_109 , V_66 , V_32 ,
& V_117 , & V_66 ) ;
if ( V_5 )
break;
V_79 = V_32 -> V_50 [ 0 ] ;
V_36 = F_20 ( V_79 , V_32 -> V_51 [ 0 ] ) ;
V_104 = F_21 ( V_79 , V_32 -> V_51 [ 0 ] ) ;
while ( V_121 < V_36 ) {
V_117 = (struct V_116 * ) ( V_104 + V_121 ) ;
V_95 = F_87 ( V_79 , V_117 ) ;
V_129 ++ ;
V_121 += V_95 + sizeof( * V_117 ) ;
}
V_66 ++ ;
F_23 ( V_32 ) ;
}
F_23 ( V_32 ) ;
if ( V_5 < 0 )
return V_5 ;
return V_129 ;
}
static int F_101 ( struct V_3 * V_4 ,
struct V_68 * V_68 , struct V_31 * V_32 )
{
int V_5 ;
struct V_34 V_35 ;
unsigned int V_129 = 0 ;
unsigned long V_104 ;
unsigned long V_105 ;
int V_95 ;
T_1 V_130 = F_50 ( V_68 ) ;
V_35 . V_45 = V_130 ;
V_35 . type = V_119 ;
V_35 . V_66 = ( T_1 ) - 1 ;
while ( 1 ) {
V_5 = F_22 ( NULL , V_4 , & V_35 , V_32 , 0 , 0 ) ;
if ( V_5 < 0 )
break;
if ( V_5 > 0 ) {
if ( V_32 -> V_51 [ 0 ] == 0 )
break;
V_32 -> V_51 [ 0 ] -- ;
}
F_102 ( V_32 -> V_50 [ 0 ] , & V_35 ,
V_32 -> V_51 [ 0 ] ) ;
if ( V_35 . V_45 != V_130 ||
V_35 . type != V_119 )
break;
V_104 = F_21 ( V_32 -> V_50 [ 0 ] , V_32 -> V_51 [ 0 ] ) ;
V_105 = V_104 + F_20 ( V_32 -> V_50 [ 0 ] ,
V_32 -> V_51 [ 0 ] ) ;
while ( V_104 < V_105 ) {
struct V_102 * V_103 ;
V_103 = (struct V_102 * ) V_104 ;
V_95 = F_80 ( V_32 -> V_50 [ 0 ] ,
V_103 ) ;
V_104 = ( unsigned long ) ( V_103 + 1 ) + V_95 ;
V_129 ++ ;
}
if ( V_35 . V_66 == 0 )
break;
V_35 . V_66 -- ;
F_23 ( V_32 ) ;
}
F_23 ( V_32 ) ;
return V_129 ;
}
static T_2 int F_103 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_68 * V_68 )
{
struct V_31 * V_32 ;
int V_5 ;
T_1 V_129 = 0 ;
T_1 V_130 = F_50 ( V_68 ) ;
V_32 = F_78 () ;
if ( ! V_32 )
return - V_54 ;
V_5 = F_101 ( V_4 , V_68 , V_32 ) ;
if ( V_5 < 0 )
goto V_74;
V_129 = V_5 ;
V_5 = F_99 ( V_4 , V_68 , V_32 ) ;
if ( V_5 == - V_18 )
V_5 = 0 ;
if ( V_5 < 0 )
goto V_74;
V_129 += V_5 ;
V_5 = 0 ;
if ( V_129 != V_68 -> V_131 ) {
F_104 ( V_68 , V_129 ) ;
F_65 ( V_2 , V_4 , V_68 ) ;
}
F_105 ( V_68 ) -> V_132 = ( T_1 ) - 1 ;
if ( V_68 -> V_131 == 0 ) {
if ( F_34 ( V_68 -> V_133 ) ) {
V_5 = F_106 ( V_2 , V_4 , NULL , V_32 ,
V_130 , 1 ) ;
if ( V_5 )
goto V_74;
}
V_5 = F_96 ( V_2 , V_4 , V_130 ) ;
}
V_74:
F_82 ( V_32 ) ;
return V_5 ;
}
static T_2 int F_107 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_31 * V_32 )
{
int V_5 ;
struct V_34 V_35 ;
struct V_68 * V_68 ;
V_35 . V_45 = V_134 ;
V_35 . type = V_135 ;
V_35 . V_66 = ( T_1 ) - 1 ;
while ( 1 ) {
V_5 = F_22 ( V_2 , V_4 , & V_35 , V_32 , - 1 , 1 ) ;
if ( V_5 < 0 )
break;
if ( V_5 == 1 ) {
if ( V_32 -> V_51 [ 0 ] == 0 )
break;
V_32 -> V_51 [ 0 ] -- ;
}
F_102 ( V_32 -> V_50 [ 0 ] , & V_35 , V_32 -> V_51 [ 0 ] ) ;
if ( V_35 . V_45 != V_134 ||
V_35 . type != V_135 )
break;
V_5 = F_108 ( V_2 , V_4 , V_32 ) ;
if ( V_5 )
goto V_74;
F_23 ( V_32 ) ;
V_68 = F_48 ( V_4 , V_35 . V_66 ) ;
if ( ! V_68 )
return - V_75 ;
V_5 = F_103 ( V_2 , V_4 , V_68 ) ;
F_66 ( V_68 ) ;
if ( V_5 )
goto V_74;
V_35 . V_66 = ( T_1 ) - 1 ;
}
V_5 = 0 ;
V_74:
F_23 ( V_32 ) ;
return V_5 ;
}
static T_2 int F_70 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_31 * V_32 ,
T_1 V_45 )
{
struct V_34 V_35 ;
int V_5 = 0 ;
struct V_68 * V_68 ;
V_68 = F_48 ( V_4 , V_45 ) ;
if ( ! V_68 )
return - V_75 ;
V_35 . V_45 = V_134 ;
F_109 ( & V_35 , V_135 ) ;
V_35 . V_66 = V_45 ;
V_5 = F_30 ( V_2 , V_4 , V_32 , & V_35 , 0 ) ;
F_23 ( V_32 ) ;
if ( V_5 == 0 ) {
if ( ! V_68 -> V_131 )
F_104 ( V_68 , 1 ) ;
else
F_84 ( V_68 ) ;
V_5 = F_65 ( V_2 , V_4 , V_68 ) ;
} else if ( V_5 == - V_58 ) {
V_5 = 0 ;
} else {
F_110 () ;
}
F_66 ( V_68 ) ;
return V_5 ;
}
static T_2 int F_111 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_31 * V_32 ,
T_1 V_97 , T_1 V_98 ,
char * V_94 , int V_95 , T_4 type ,
struct V_34 * V_96 )
{
struct V_68 * V_68 ;
struct V_68 * V_91 ;
int V_5 ;
V_68 = F_48 ( V_4 , V_96 -> V_45 ) ;
if ( ! V_68 )
return - V_18 ;
V_91 = F_48 ( V_4 , V_97 ) ;
if ( ! V_91 ) {
F_66 ( V_68 ) ;
return - V_75 ;
}
V_5 = F_95 ( V_2 , V_91 , V_68 , V_94 , V_95 , 1 , V_98 ) ;
F_66 ( V_68 ) ;
F_66 ( V_91 ) ;
return V_5 ;
}
static T_2 int F_112 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_31 * V_32 ,
struct V_20 * V_21 ,
struct V_92 * V_93 ,
struct V_34 * V_35 )
{
char * V_94 ;
int V_95 ;
struct V_92 * V_136 ;
struct V_34 V_137 ;
struct V_34 V_138 ;
struct V_68 * V_91 ;
T_4 V_139 ;
int V_140 ;
int V_5 = 0 ;
V_91 = F_48 ( V_4 , V_35 -> V_45 ) ;
if ( ! V_91 )
return - V_75 ;
V_95 = F_69 ( V_21 , V_93 ) ;
V_94 = F_24 ( V_95 , V_53 ) ;
if ( ! V_94 )
return - V_54 ;
V_139 = F_113 ( V_21 , V_93 ) ;
F_26 ( V_21 , V_94 , ( unsigned long ) ( V_93 + 1 ) ,
V_95 ) ;
F_68 ( V_21 , V_93 , & V_138 ) ;
V_140 = F_114 ( V_2 , V_4 , V_32 , & V_138 , 0 ) ;
if ( V_140 == 0 )
V_140 = 1 ;
else
V_140 = 0 ;
F_23 ( V_32 ) ;
if ( V_35 -> type == V_141 ) {
V_136 = F_76 ( V_2 , V_4 , V_32 , V_35 -> V_45 ,
V_94 , V_95 , 1 ) ;
} else if ( V_35 -> type == V_142 ) {
V_136 = F_74 ( V_2 , V_4 , V_32 ,
V_35 -> V_45 ,
V_35 -> V_66 , V_94 ,
V_95 , 1 ) ;
} else {
V_5 = - V_143 ;
goto V_74;
}
if ( F_86 ( V_136 ) ) {
if ( V_35 -> type != V_142 )
goto V_74;
goto V_52;
}
F_68 ( V_32 -> V_50 [ 0 ] , V_136 , & V_137 ) ;
if ( V_137 . V_45 == V_138 . V_45 &&
V_137 . type == V_138 . type &&
V_137 . V_66 == V_138 . V_66 &&
F_113 ( V_32 -> V_50 [ 0 ] , V_136 ) == V_139 ) {
goto V_74;
}
if ( ! V_140 )
goto V_74;
V_5 = F_67 ( V_2 , V_4 , V_32 , V_91 , V_136 ) ;
if ( V_5 )
goto V_74;
if ( V_35 -> type == V_142 )
goto V_52;
V_74:
F_23 ( V_32 ) ;
F_25 ( V_94 ) ;
F_66 ( V_91 ) ;
return V_5 ;
V_52:
F_23 ( V_32 ) ;
V_5 = F_111 ( V_2 , V_4 , V_32 , V_35 -> V_45 , V_35 -> V_66 ,
V_94 , V_95 , V_139 , & V_138 ) ;
if ( V_5 && V_5 != - V_18 )
goto V_74;
V_5 = 0 ;
goto V_74;
}
static T_2 int F_115 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_31 * V_32 ,
struct V_20 * V_21 , int V_33 ,
struct V_34 * V_35 )
{
int V_5 ;
T_3 V_36 = F_20 ( V_21 , V_33 ) ;
struct V_92 * V_93 ;
int V_95 ;
unsigned long V_104 ;
unsigned long V_105 ;
V_104 = F_21 ( V_21 , V_33 ) ;
V_105 = V_104 + V_36 ;
while ( V_104 < V_105 ) {
V_93 = (struct V_92 * ) V_104 ;
if ( F_116 ( V_4 , V_21 , V_93 ) )
return - V_75 ;
V_95 = F_69 ( V_21 , V_93 ) ;
V_5 = F_112 ( V_2 , V_4 , V_32 , V_21 , V_93 , V_35 ) ;
if ( V_5 )
return V_5 ;
V_104 = ( unsigned long ) ( V_93 + 1 ) ;
V_104 += V_95 ;
}
return 0 ;
}
static T_2 int F_117 ( struct V_3 * V_4 ,
struct V_31 * V_32 ,
T_1 V_97 , int V_144 ,
T_1 * V_145 , T_1 * V_146 )
{
struct V_34 V_35 ;
T_1 V_147 ;
struct V_148 * V_56 ;
int V_5 ;
int V_149 ;
if ( * V_145 == ( T_1 ) - 1 )
return 1 ;
V_35 . V_45 = V_97 ;
V_35 . type = V_144 ;
V_35 . V_66 = * V_145 ;
V_5 = F_22 ( NULL , V_4 , & V_35 , V_32 , 0 , 0 ) ;
if ( V_5 < 0 )
goto V_74;
if ( V_5 > 0 ) {
if ( V_32 -> V_51 [ 0 ] == 0 )
goto V_74;
V_32 -> V_51 [ 0 ] -- ;
}
if ( V_5 != 0 )
F_102 ( V_32 -> V_50 [ 0 ] , & V_35 , V_32 -> V_51 [ 0 ] ) ;
if ( V_35 . type != V_144 || V_35 . V_45 != V_97 ) {
V_5 = 1 ;
goto V_88;
}
V_56 = F_27 ( V_32 -> V_50 [ 0 ] , V_32 -> V_51 [ 0 ] ,
struct V_148 ) ;
V_147 = F_118 ( V_32 -> V_50 [ 0 ] , V_56 ) ;
if ( * V_145 >= V_35 . V_66 && * V_145 <= V_147 ) {
V_5 = 0 ;
* V_145 = V_35 . V_66 ;
* V_146 = V_147 ;
goto V_74;
}
V_5 = 1 ;
V_88:
V_149 = F_119 ( V_32 -> V_50 [ 0 ] ) ;
if ( V_32 -> V_51 [ 0 ] >= V_149 ) {
V_5 = F_120 ( V_4 , V_32 ) ;
if ( V_5 )
goto V_74;
} else {
V_32 -> V_51 [ 0 ] ++ ;
}
F_102 ( V_32 -> V_50 [ 0 ] , & V_35 , V_32 -> V_51 [ 0 ] ) ;
if ( V_35 . type != V_144 || V_35 . V_45 != V_97 ) {
V_5 = 1 ;
goto V_74;
}
V_56 = F_27 ( V_32 -> V_50 [ 0 ] , V_32 -> V_51 [ 0 ] ,
struct V_148 ) ;
V_147 = F_118 ( V_32 -> V_50 [ 0 ] , V_56 ) ;
* V_145 = V_35 . V_66 ;
* V_146 = V_147 ;
V_5 = 0 ;
V_74:
F_23 ( V_32 ) ;
return V_5 ;
}
static T_2 int F_121 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_3 * log ,
struct V_31 * V_32 ,
struct V_31 * V_150 ,
struct V_68 * V_91 ,
struct V_34 * V_151 )
{
int V_5 ;
struct V_20 * V_21 ;
int V_33 ;
T_3 V_36 ;
struct V_92 * V_93 ;
struct V_92 * V_152 ;
int V_95 ;
unsigned long V_104 ;
unsigned long V_105 ;
char * V_94 ;
struct V_68 * V_68 ;
struct V_34 V_96 ;
V_118:
V_21 = V_32 -> V_50 [ 0 ] ;
V_33 = V_32 -> V_51 [ 0 ] ;
V_36 = F_20 ( V_21 , V_33 ) ;
V_104 = F_21 ( V_21 , V_33 ) ;
V_105 = V_104 + V_36 ;
while ( V_104 < V_105 ) {
V_93 = (struct V_92 * ) V_104 ;
if ( F_116 ( V_4 , V_21 , V_93 ) ) {
V_5 = - V_75 ;
goto V_74;
}
V_95 = F_69 ( V_21 , V_93 ) ;
V_94 = F_24 ( V_95 , V_53 ) ;
if ( ! V_94 ) {
V_5 = - V_54 ;
goto V_74;
}
F_26 ( V_21 , V_94 , ( unsigned long ) ( V_93 + 1 ) ,
V_95 ) ;
V_152 = NULL ;
if ( log && V_151 -> type == V_141 ) {
V_152 = F_76 ( V_2 , log , V_150 ,
V_151 -> V_45 ,
V_94 , V_95 , 0 ) ;
} else if ( log && V_151 -> type == V_142 ) {
V_152 = F_74 ( V_2 , log ,
V_150 ,
V_151 -> V_45 ,
V_151 -> V_66 ,
V_94 , V_95 , 0 ) ;
}
if ( F_86 ( V_152 ) ) {
F_68 ( V_21 , V_93 , & V_96 ) ;
F_23 ( V_32 ) ;
F_23 ( V_150 ) ;
V_68 = F_48 ( V_4 , V_96 . V_45 ) ;
if ( ! V_68 ) {
F_25 ( V_94 ) ;
return - V_75 ;
}
V_5 = F_70 ( V_2 , V_4 ,
V_32 , V_96 . V_45 ) ;
if ( V_5 ) {
F_25 ( V_94 ) ;
F_66 ( V_68 ) ;
goto V_74;
}
F_84 ( V_68 ) ;
V_5 = F_71 ( V_2 , V_4 , V_91 , V_68 ,
V_94 , V_95 ) ;
if ( ! V_5 )
F_72 ( V_2 , V_4 ) ;
F_25 ( V_94 ) ;
F_66 ( V_68 ) ;
if ( V_5 )
goto V_74;
V_5 = F_22 ( NULL , V_4 , V_151 , V_32 ,
0 , 0 ) ;
if ( V_5 == 0 )
goto V_118;
V_5 = 0 ;
goto V_74;
}
F_23 ( V_150 ) ;
F_25 ( V_94 ) ;
V_104 = ( unsigned long ) ( V_93 + 1 ) ;
V_104 += V_95 ;
}
V_5 = 0 ;
V_74:
F_23 ( V_32 ) ;
F_23 ( V_150 ) ;
return V_5 ;
}
static T_2 int F_106 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_3 * log ,
struct V_31 * V_32 ,
T_1 V_97 , int V_153 )
{
T_1 V_154 ;
T_1 V_155 ;
int V_144 = V_156 ;
int V_5 = 0 ;
struct V_34 V_151 ;
struct V_34 V_137 ;
struct V_31 * V_150 ;
struct V_68 * V_91 ;
V_151 . V_45 = V_97 ;
V_151 . type = V_141 ;
V_150 = F_78 () ;
if ( ! V_150 )
return - V_54 ;
V_91 = F_48 ( V_4 , V_97 ) ;
if ( ! V_91 ) {
F_82 ( V_150 ) ;
return 0 ;
}
V_118:
V_154 = 0 ;
V_155 = 0 ;
while ( 1 ) {
if ( V_153 )
V_155 = ( T_1 ) - 1 ;
else {
V_5 = F_117 ( log , V_32 , V_97 , V_144 ,
& V_154 , & V_155 ) ;
if ( V_5 != 0 )
break;
}
V_151 . V_66 = V_154 ;
while ( 1 ) {
int V_149 ;
V_5 = F_22 ( NULL , V_4 , & V_151 , V_32 ,
0 , 0 ) ;
if ( V_5 < 0 )
goto V_74;
V_149 = F_119 ( V_32 -> V_50 [ 0 ] ) ;
if ( V_32 -> V_51 [ 0 ] >= V_149 ) {
V_5 = F_120 ( V_4 , V_32 ) ;
if ( V_5 )
break;
}
F_102 ( V_32 -> V_50 [ 0 ] , & V_137 ,
V_32 -> V_51 [ 0 ] ) ;
if ( V_137 . V_45 != V_97 ||
V_137 . type != V_151 . type )
goto V_157;
if ( V_137 . V_66 > V_155 )
break;
V_5 = F_121 ( V_2 , V_4 , log , V_32 ,
V_150 , V_91 ,
& V_137 ) ;
if ( V_5 )
goto V_74;
if ( V_137 . V_66 == ( T_1 ) - 1 )
break;
V_151 . V_66 = V_137 . V_66 + 1 ;
}
F_23 ( V_32 ) ;
if ( V_155 == ( T_1 ) - 1 )
break;
V_154 = V_155 + 1 ;
}
V_157:
V_5 = 0 ;
if ( V_144 == V_156 ) {
V_144 = V_158 ;
V_151 . type = V_142 ;
F_23 ( V_32 ) ;
goto V_118;
}
V_74:
F_23 ( V_32 ) ;
F_82 ( V_150 ) ;
F_66 ( V_91 ) ;
return V_5 ;
}
static int F_122 ( struct V_3 * log , struct V_20 * V_21 ,
struct V_22 * V_23 , T_1 V_24 )
{
int V_149 ;
struct V_31 * V_32 ;
struct V_3 * V_4 = V_23 -> V_159 ;
struct V_34 V_35 ;
int V_160 ;
int V_161 ;
int V_5 ;
V_5 = F_123 ( V_21 , V_24 ) ;
if ( V_5 )
return V_5 ;
V_160 = F_124 ( V_21 ) ;
if ( V_160 != 0 )
return 0 ;
V_32 = F_78 () ;
if ( ! V_32 )
return - V_54 ;
V_149 = F_119 ( V_21 ) ;
for ( V_161 = 0 ; V_161 < V_149 ; V_161 ++ ) {
F_102 ( V_21 , & V_35 , V_161 ) ;
if ( V_35 . type == V_43 &&
V_23 -> V_162 == V_163 ) {
struct V_55 * V_42 ;
T_3 V_164 ;
V_42 = F_27 ( V_21 , V_161 ,
struct V_55 ) ;
V_164 = F_35 ( V_21 , V_42 ) ;
if ( F_34 ( V_164 ) ) {
V_5 = F_106 ( V_23 -> V_2 ,
V_4 , log , V_32 , V_35 . V_45 , 0 ) ;
if ( V_5 )
break;
}
V_5 = F_19 ( V_23 -> V_2 , V_4 , V_32 ,
V_21 , V_161 , & V_35 ) ;
if ( V_5 )
break;
if ( F_125 ( V_164 ) ) {
V_5 = F_96 ( V_23 -> V_2 , V_4 ,
V_35 . V_45 ) ;
if ( V_5 )
break;
}
V_5 = F_70 ( V_23 -> V_2 , V_4 ,
V_32 , V_35 . V_45 ) ;
if ( V_5 )
break;
}
if ( V_23 -> V_162 < V_165 )
continue;
if ( V_35 . type == V_166 ) {
V_5 = F_19 ( V_23 -> V_2 , V_4 , V_32 ,
V_21 , V_161 , & V_35 ) ;
if ( V_5 )
break;
} else if ( V_35 . type == V_119 ) {
V_5 = F_94 ( V_23 -> V_2 , V_4 , log , V_32 ,
V_21 , V_161 , & V_35 ) ;
if ( V_5 && V_5 != - V_18 )
break;
V_5 = 0 ;
} else if ( V_35 . type == V_108 ) {
V_5 = F_94 ( V_23 -> V_2 , V_4 , log , V_32 ,
V_21 , V_161 , & V_35 ) ;
if ( V_5 && V_5 != - V_18 )
break;
V_5 = 0 ;
} else if ( V_35 . type == V_167 ) {
V_5 = F_41 ( V_23 -> V_2 , V_4 , V_32 ,
V_21 , V_161 , & V_35 ) ;
if ( V_5 )
break;
} else if ( V_35 . type == V_141 ||
V_35 . type == V_142 ) {
V_5 = F_115 ( V_23 -> V_2 , V_4 , V_32 ,
V_21 , V_161 , & V_35 ) ;
if ( V_5 )
break;
}
}
F_82 ( V_32 ) ;
return V_5 ;
}
static T_2 int F_126 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_31 * V_32 , int * V_160 ,
struct V_22 * V_23 )
{
T_1 V_168 ;
T_1 V_169 ;
T_1 V_170 ;
struct V_20 * V_88 ;
struct V_20 * V_171 ;
struct V_20 * V_172 ;
T_3 V_173 ;
int V_5 = 0 ;
F_127 ( * V_160 < 0 ) ;
F_127 ( * V_160 >= V_174 ) ;
while ( * V_160 > 0 ) {
F_127 ( * V_160 < 0 ) ;
F_127 ( * V_160 >= V_174 ) ;
V_171 = V_32 -> V_50 [ * V_160 ] ;
if ( F_124 ( V_171 ) != * V_160 )
F_127 ( 1 ) ;
if ( V_32 -> V_51 [ * V_160 ] >=
F_119 ( V_171 ) )
break;
V_169 = F_128 ( V_171 , V_32 -> V_51 [ * V_160 ] ) ;
V_170 = F_129 ( V_171 , V_32 -> V_51 [ * V_160 ] ) ;
V_173 = F_130 ( V_4 , * V_160 - 1 ) ;
V_172 = V_32 -> V_50 [ * V_160 ] ;
V_168 = F_131 ( V_172 ) ;
V_88 = F_132 ( V_4 , V_169 , V_173 ) ;
if ( ! V_88 )
return - V_54 ;
if ( * V_160 == 1 ) {
V_5 = V_23 -> V_175 ( V_4 , V_88 , V_23 , V_170 ) ;
if ( V_5 ) {
F_133 ( V_88 ) ;
return V_5 ;
}
V_32 -> V_51 [ * V_160 ] ++ ;
if ( V_23 -> free ) {
V_5 = F_123 ( V_88 , V_170 ) ;
if ( V_5 ) {
F_133 ( V_88 ) ;
return V_5 ;
}
F_134 ( V_88 ) ;
F_135 ( V_88 ) ;
F_136 ( V_2 , V_4 , V_88 ) ;
F_18 ( V_88 ) ;
F_137 ( V_88 ) ;
F_127 ( V_168 !=
V_46 ) ;
V_5 = F_138 ( V_4 ,
V_169 , V_173 ) ;
if ( V_5 ) {
F_133 ( V_88 ) ;
return V_5 ;
}
}
F_133 ( V_88 ) ;
continue;
}
V_5 = F_123 ( V_88 , V_170 ) ;
if ( V_5 ) {
F_133 ( V_88 ) ;
return V_5 ;
}
F_127 ( * V_160 <= 0 ) ;
if ( V_32 -> V_50 [ * V_160 - 1 ] )
F_133 ( V_32 -> V_50 [ * V_160 - 1 ] ) ;
V_32 -> V_50 [ * V_160 - 1 ] = V_88 ;
* V_160 = F_124 ( V_88 ) ;
V_32 -> V_51 [ * V_160 ] = 0 ;
F_139 () ;
}
F_127 ( * V_160 < 0 ) ;
F_127 ( * V_160 >= V_174 ) ;
V_32 -> V_51 [ * V_160 ] = F_119 ( V_32 -> V_50 [ * V_160 ] ) ;
F_139 () ;
return 0 ;
}
static T_2 int F_140 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_31 * V_32 , int * V_160 ,
struct V_22 * V_23 )
{
T_1 V_168 ;
int V_161 ;
int V_33 ;
int V_5 ;
for ( V_161 = * V_160 ; V_161 < V_174 - 1 && V_32 -> V_50 [ V_161 ] ; V_161 ++ ) {
V_33 = V_32 -> V_51 [ V_161 ] ;
if ( V_33 + 1 < F_119 ( V_32 -> V_50 [ V_161 ] ) ) {
V_32 -> V_51 [ V_161 ] ++ ;
* V_160 = V_161 ;
F_127 ( * V_160 == 0 ) ;
return 0 ;
} else {
struct V_20 * V_172 ;
if ( V_32 -> V_50 [ * V_160 ] == V_4 -> V_176 )
V_172 = V_32 -> V_50 [ * V_160 ] ;
else
V_172 = V_32 -> V_50 [ * V_160 + 1 ] ;
V_168 = F_131 ( V_172 ) ;
V_5 = V_23 -> V_175 ( V_4 , V_32 -> V_50 [ * V_160 ] , V_23 ,
F_141 ( V_32 -> V_50 [ * V_160 ] ) ) ;
if ( V_5 )
return V_5 ;
if ( V_23 -> free ) {
struct V_20 * V_88 ;
V_88 = V_32 -> V_50 [ * V_160 ] ;
F_134 ( V_88 ) ;
F_135 ( V_88 ) ;
F_136 ( V_2 , V_4 , V_88 ) ;
F_18 ( V_88 ) ;
F_137 ( V_88 ) ;
F_127 ( V_168 != V_46 ) ;
V_5 = F_138 ( V_4 ,
V_32 -> V_50 [ * V_160 ] -> V_27 ,
V_32 -> V_50 [ * V_160 ] -> V_28 ) ;
if ( V_5 )
return V_5 ;
}
F_133 ( V_32 -> V_50 [ * V_160 ] ) ;
V_32 -> V_50 [ * V_160 ] = NULL ;
* V_160 = V_161 + 1 ;
}
}
return 1 ;
}
static int F_142 ( struct V_1 * V_2 ,
struct V_3 * log , struct V_22 * V_23 )
{
int V_5 = 0 ;
int V_177 ;
int V_160 ;
struct V_31 * V_32 ;
int V_178 ;
V_32 = F_78 () ;
if ( ! V_32 )
return - V_54 ;
V_160 = F_124 ( log -> V_176 ) ;
V_178 = V_160 ;
V_32 -> V_50 [ V_160 ] = log -> V_176 ;
F_143 ( log -> V_176 ) ;
V_32 -> V_51 [ V_160 ] = 0 ;
while ( 1 ) {
V_177 = F_126 ( V_2 , log , V_32 , & V_160 , V_23 ) ;
if ( V_177 > 0 )
break;
if ( V_177 < 0 ) {
V_5 = V_177 ;
goto V_74;
}
V_177 = F_140 ( V_2 , log , V_32 , & V_160 , V_23 ) ;
if ( V_177 > 0 )
break;
if ( V_177 < 0 ) {
V_5 = V_177 ;
goto V_74;
}
}
if ( V_32 -> V_50 [ V_178 ] ) {
V_5 = V_23 -> V_175 ( log , V_32 -> V_50 [ V_178 ] , V_23 ,
F_141 ( V_32 -> V_50 [ V_178 ] ) ) ;
if ( V_5 )
goto V_74;
if ( V_23 -> free ) {
struct V_20 * V_88 ;
V_88 = V_32 -> V_50 [ V_178 ] ;
F_134 ( V_88 ) ;
F_135 ( V_88 ) ;
F_136 ( V_2 , log , V_88 ) ;
F_18 ( V_88 ) ;
F_137 ( V_88 ) ;
F_127 ( log -> V_44 . V_45 !=
V_46 ) ;
V_5 = F_138 ( log , V_88 -> V_27 ,
V_88 -> V_28 ) ;
if ( V_5 )
goto V_74;
}
}
V_74:
F_82 ( V_32 ) ;
return V_5 ;
}
static int F_144 ( struct V_1 * V_2 ,
struct V_3 * log )
{
int V_5 ;
if ( log -> V_179 == 1 ) {
V_5 = F_145 ( V_2 , log -> V_15 -> V_17 ,
& log -> V_44 , & log -> V_180 ) ;
} else {
V_5 = F_146 ( V_2 , log -> V_15 -> V_17 ,
& log -> V_44 , & log -> V_180 ) ;
}
return V_5 ;
}
static int F_147 ( struct V_1 * V_2 ,
struct V_3 * V_4 , unsigned long V_63 )
{
F_148 ( V_30 ) ;
int V_98 = V_63 % 2 ;
do {
F_149 ( & V_4 -> V_181 [ V_98 ] ,
& V_30 , V_182 ) ;
F_4 ( & V_4 -> V_7 ) ;
if ( V_4 -> V_15 -> V_183 !=
V_2 -> V_63 && V_4 -> V_179 < V_63 + 2 &&
F_150 ( & V_4 -> V_184 [ V_98 ] ) )
F_151 () ;
F_152 ( & V_4 -> V_181 [ V_98 ] , & V_30 ) ;
F_2 ( & V_4 -> V_7 ) ;
} while ( V_4 -> V_15 -> V_183 !=
V_2 -> V_63 && V_4 -> V_179 < V_63 + 2 &&
F_150 ( & V_4 -> V_184 [ V_98 ] ) );
return 0 ;
}
static void F_153 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_148 ( V_30 ) ;
while ( V_4 -> V_15 -> V_183 !=
V_2 -> V_63 && F_150 ( & V_4 -> V_14 ) ) {
F_149 ( & V_4 -> V_19 ,
& V_30 , V_182 ) ;
F_4 ( & V_4 -> V_7 ) ;
if ( V_4 -> V_15 -> V_183 !=
V_2 -> V_63 && F_150 ( & V_4 -> V_14 ) )
F_151 () ;
F_2 ( & V_4 -> V_7 ) ;
F_152 ( & V_4 -> V_19 , & V_30 ) ;
}
}
int F_154 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_185 ;
int V_186 ;
int V_187 ;
int V_5 ;
struct V_3 * log = V_4 -> V_8 ;
struct V_3 * V_17 = V_4 -> V_15 -> V_17 ;
unsigned long V_179 = 0 ;
F_2 ( & V_4 -> V_7 ) ;
V_179 = V_4 -> V_179 ;
V_185 = V_4 -> V_179 % 2 ;
if ( F_150 ( & V_4 -> V_184 [ V_185 ] ) ) {
F_147 ( V_2 , V_4 , V_4 -> V_179 ) ;
F_4 ( & V_4 -> V_7 ) ;
return 0 ;
}
F_155 ( & V_4 -> V_184 [ V_185 ] , 1 ) ;
if ( F_150 ( & V_4 -> V_184 [ ( V_185 + 1 ) % 2 ] ) )
F_147 ( V_2 , V_4 , V_4 -> V_179 - 1 ) ;
while ( 1 ) {
int V_188 = F_150 ( & V_4 -> V_13 ) ;
if ( ! F_156 ( V_4 , V_189 ) && V_4 -> V_12 ) {
F_4 ( & V_4 -> V_7 ) ;
F_157 ( 1 ) ;
F_2 ( & V_4 -> V_7 ) ;
}
F_153 ( V_2 , V_4 ) ;
if ( V_188 == F_150 ( & V_4 -> V_13 ) )
break;
}
if ( V_4 -> V_15 -> V_183 == V_2 -> V_63 ) {
V_5 = - V_190 ;
F_158 ( log , V_179 ) ;
F_4 ( & V_4 -> V_7 ) ;
goto V_74;
}
if ( V_179 % 2 == 0 )
V_187 = V_191 ;
else
V_187 = V_192 ;
V_5 = F_159 ( log , & log -> V_193 , V_187 ) ;
if ( V_5 ) {
F_160 ( V_2 , V_4 , V_5 ) ;
F_158 ( log , V_179 ) ;
F_4 ( & V_4 -> V_7 ) ;
goto V_74;
}
F_161 ( & log -> V_180 , log -> V_176 ) ;
V_4 -> V_179 ++ ;
log -> V_179 = V_4 -> V_179 ;
V_4 -> V_9 = 0 ;
F_8 () ;
F_4 ( & V_4 -> V_7 ) ;
F_2 ( & V_17 -> V_7 ) ;
F_3 ( & V_17 -> V_13 ) ;
F_3 ( & V_17 -> V_14 ) ;
F_4 ( & V_17 -> V_7 ) ;
V_5 = F_144 ( V_2 , log ) ;
F_2 ( & V_17 -> V_7 ) ;
if ( F_11 ( & V_17 -> V_14 ) ) {
F_8 () ;
if ( F_12 ( & V_17 -> V_19 ) )
F_13 ( & V_17 -> V_19 ) ;
}
if ( V_5 ) {
if ( V_5 != - V_194 ) {
F_160 ( V_2 , V_4 , V_5 ) ;
F_4 ( & V_17 -> V_7 ) ;
goto V_74;
}
V_4 -> V_15 -> V_183 = V_2 -> V_63 ;
F_162 ( log , & log -> V_193 , V_187 ) ;
F_158 ( log , V_179 ) ;
F_4 ( & V_17 -> V_7 ) ;
V_5 = - V_190 ;
goto V_74;
}
V_186 = V_17 -> V_179 % 2 ;
if ( F_150 ( & V_17 -> V_184 [ V_186 ] ) ) {
F_162 ( log , & log -> V_193 , V_187 ) ;
F_147 ( V_2 , V_17 ,
V_17 -> V_179 ) ;
F_158 ( log , V_179 ) ;
F_4 ( & V_17 -> V_7 ) ;
V_5 = 0 ;
goto V_74;
}
F_155 ( & V_17 -> V_184 [ V_186 ] , 1 ) ;
if ( F_150 ( & V_17 -> V_184 [ ( V_186 + 1 ) % 2 ] ) ) {
F_147 ( V_2 , V_17 ,
V_17 -> V_179 - 1 ) ;
}
F_153 ( V_2 , V_17 ) ;
if ( V_4 -> V_15 -> V_183 == V_2 -> V_63 ) {
F_162 ( log , & log -> V_193 , V_187 ) ;
F_158 ( log , V_179 ) ;
F_4 ( & V_17 -> V_7 ) ;
V_5 = - V_190 ;
goto V_195;
}
V_5 = F_163 ( V_17 ,
& V_17 -> V_193 ,
V_191 | V_192 ) ;
if ( V_5 ) {
F_160 ( V_2 , V_4 , V_5 ) ;
F_158 ( log , V_179 ) ;
F_4 ( & V_17 -> V_7 ) ;
goto V_195;
}
F_162 ( log , & log -> V_193 , V_187 ) ;
F_164 ( log , V_179 ) ;
F_165 ( V_4 -> V_15 -> V_196 ,
V_17 -> V_176 -> V_27 ) ;
F_166 ( V_4 -> V_15 -> V_196 ,
F_124 ( V_17 -> V_176 ) ) ;
V_17 -> V_179 ++ ;
F_8 () ;
F_4 ( & V_17 -> V_7 ) ;
F_167 ( V_4 ) ;
V_5 = F_168 ( V_2 , V_4 -> V_15 -> V_197 , 1 ) ;
F_169 ( V_4 ) ;
if ( V_5 ) {
F_160 ( V_2 , V_4 , V_5 ) ;
goto V_195;
}
F_2 ( & V_4 -> V_7 ) ;
if ( V_4 -> V_198 < V_179 )
V_4 -> V_198 = V_179 ;
F_4 ( & V_4 -> V_7 ) ;
V_195:
F_155 ( & V_17 -> V_184 [ V_186 ] , 0 ) ;
F_8 () ;
if ( F_12 ( & V_17 -> V_181 [ V_186 ] ) )
F_13 ( & V_17 -> V_181 [ V_186 ] ) ;
V_74:
F_155 ( & V_4 -> V_184 [ V_185 ] , 0 ) ;
F_8 () ;
if ( F_12 ( & V_4 -> V_181 [ V_185 ] ) )
F_13 ( & V_4 -> V_181 [ V_185 ] ) ;
return V_5 ;
}
static void F_170 ( struct V_1 * V_2 ,
struct V_3 * log )
{
int V_5 ;
T_1 V_27 ;
T_1 V_199 ;
struct V_22 V_23 = {
. free = 1 ,
. V_175 = F_14
} ;
if ( V_2 ) {
V_5 = F_142 ( V_2 , log , & V_23 ) ;
if ( V_5 )
F_160 ( V_2 , log , V_5 ) ;
}
while ( 1 ) {
V_5 = F_171 ( & log -> V_193 ,
0 , & V_27 , & V_199 , V_191 | V_192 ,
NULL ) ;
if ( V_5 )
break;
F_172 ( & log -> V_193 , V_27 , V_199 ,
V_191 | V_192 , V_53 ) ;
}
F_158 ( log , 0 ) ;
F_158 ( log , 1 ) ;
F_133 ( log -> V_176 ) ;
F_25 ( log ) ;
}
int F_173 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( V_4 -> V_8 ) {
F_170 ( V_2 , V_4 -> V_8 ) ;
V_4 -> V_8 = NULL ;
}
return 0 ;
}
int F_174 ( struct V_1 * V_2 ,
struct V_200 * V_15 )
{
if ( V_15 -> V_17 ) {
F_170 ( V_2 , V_15 -> V_17 ) ;
V_15 -> V_17 = NULL ;
}
return 0 ;
}
int F_175 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_94 , int V_95 ,
struct V_68 * V_91 , T_1 V_98 )
{
struct V_3 * log ;
struct V_92 * V_93 ;
struct V_31 * V_32 ;
int V_5 ;
int V_6 = 0 ;
int V_201 = 0 ;
T_1 V_202 = F_50 ( V_91 ) ;
if ( F_105 ( V_91 ) -> V_203 < V_2 -> V_63 )
return 0 ;
V_5 = F_7 ( V_4 ) ;
if ( V_5 )
return 0 ;
F_2 ( & F_105 ( V_91 ) -> V_7 ) ;
log = V_4 -> V_8 ;
V_32 = F_78 () ;
if ( ! V_32 ) {
V_6 = - V_54 ;
goto V_204;
}
V_93 = F_76 ( V_2 , log , V_32 , V_202 ,
V_94 , V_95 , - 1 ) ;
if ( F_75 ( V_93 ) ) {
V_6 = F_176 ( V_93 ) ;
goto V_205;
}
if ( V_93 ) {
V_5 = F_177 ( V_2 , log , V_32 , V_93 ) ;
V_201 += V_95 ;
if ( V_5 ) {
V_6 = V_5 ;
goto V_205;
}
}
F_23 ( V_32 ) ;
V_93 = F_74 ( V_2 , log , V_32 , V_202 ,
V_98 , V_94 , V_95 , - 1 ) ;
if ( F_75 ( V_93 ) ) {
V_6 = F_176 ( V_93 ) ;
goto V_205;
}
if ( V_93 ) {
V_5 = F_177 ( V_2 , log , V_32 , V_93 ) ;
V_201 += V_95 ;
if ( V_5 ) {
V_6 = V_5 ;
goto V_205;
}
}
if ( V_201 ) {
struct V_34 V_35 ;
V_35 . V_45 = V_202 ;
V_35 . V_66 = 0 ;
V_35 . type = V_43 ;
F_23 ( V_32 ) ;
V_5 = F_22 ( V_2 , log , & V_35 , V_32 , 0 , 1 ) ;
if ( V_5 < 0 ) {
V_6 = V_5 ;
goto V_205;
}
if ( V_5 == 0 ) {
struct V_55 * V_56 ;
T_1 V_206 ;
V_56 = F_27 ( V_32 -> V_50 [ 0 ] , V_32 -> V_51 [ 0 ] ,
struct V_55 ) ;
V_206 = F_36 ( V_32 -> V_50 [ 0 ] , V_56 ) ;
if ( V_206 > V_201 )
V_206 -= V_201 ;
else
V_206 = 0 ;
F_38 ( V_32 -> V_50 [ 0 ] , V_56 , V_206 ) ;
F_40 ( V_32 -> V_50 [ 0 ] ) ;
} else
V_5 = 0 ;
F_23 ( V_32 ) ;
}
V_205:
F_82 ( V_32 ) ;
V_204:
F_4 ( & F_105 ( V_91 ) -> V_7 ) ;
if ( V_5 == - V_194 ) {
V_4 -> V_15 -> V_183 = V_2 -> V_63 ;
V_5 = 0 ;
} else if ( V_5 < 0 )
F_160 ( V_2 , V_4 , V_5 ) ;
F_10 ( V_4 ) ;
return V_6 ;
}
int F_178 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_94 , int V_95 ,
struct V_68 * V_68 , T_1 V_97 )
{
struct V_3 * log ;
T_1 V_98 ;
int V_5 ;
if ( F_105 ( V_68 ) -> V_203 < V_2 -> V_63 )
return 0 ;
V_5 = F_7 ( V_4 ) ;
if ( V_5 )
return 0 ;
log = V_4 -> V_8 ;
F_2 ( & F_105 ( V_68 ) -> V_7 ) ;
V_5 = F_179 ( V_2 , log , V_94 , V_95 , F_50 ( V_68 ) ,
V_97 , & V_98 ) ;
F_4 ( & F_105 ( V_68 ) -> V_7 ) ;
if ( V_5 == - V_194 ) {
V_4 -> V_15 -> V_183 = V_2 -> V_63 ;
V_5 = 0 ;
} else if ( V_5 < 0 && V_5 != - V_18 )
F_160 ( V_2 , V_4 , V_5 ) ;
F_10 ( V_4 ) ;
return V_5 ;
}
static T_2 int F_180 ( struct V_1 * V_2 ,
struct V_3 * log ,
struct V_31 * V_32 ,
int V_144 , T_1 V_97 ,
T_1 V_207 , T_1 V_208 )
{
int V_5 ;
struct V_34 V_35 ;
struct V_148 * V_56 ;
V_35 . V_45 = V_97 ;
V_35 . V_66 = V_207 ;
if ( V_144 == V_141 )
V_35 . type = V_156 ;
else
V_35 . type = V_158 ;
V_5 = F_30 ( V_2 , log , V_32 , & V_35 , sizeof( * V_56 ) ) ;
if ( V_5 )
return V_5 ;
V_56 = F_27 ( V_32 -> V_50 [ 0 ] , V_32 -> V_51 [ 0 ] ,
struct V_148 ) ;
F_181 ( V_32 -> V_50 [ 0 ] , V_56 , V_208 ) ;
F_40 ( V_32 -> V_50 [ 0 ] ) ;
F_23 ( V_32 ) ;
return 0 ;
}
static T_2 int F_182 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_68 * V_68 ,
struct V_31 * V_32 ,
struct V_31 * V_209 , int V_144 ,
T_1 V_210 , T_1 * V_211 )
{
struct V_34 V_212 ;
struct V_34 V_213 ;
struct V_3 * log = V_4 -> V_8 ;
struct V_20 * V_214 ;
int V_6 = 0 ;
int V_5 ;
int V_161 ;
int V_149 ;
T_1 V_207 = V_210 ;
T_1 V_208 = ( T_1 ) - 1 ;
T_1 V_130 = F_50 ( V_68 ) ;
log = V_4 -> V_8 ;
V_213 . V_45 = V_130 ;
V_213 . V_66 = ( T_1 ) - 1 ;
V_213 . type = V_144 ;
V_212 . V_45 = V_130 ;
V_212 . type = V_144 ;
V_212 . V_66 = V_210 ;
V_32 -> V_215 = 1 ;
V_5 = F_183 ( V_4 , & V_212 , & V_213 ,
V_32 , V_2 -> V_63 ) ;
if ( V_5 != 0 || V_212 . V_45 != V_130 || V_212 . type != V_144 ) {
V_212 . V_45 = V_130 ;
V_212 . type = V_144 ;
V_212 . V_66 = ( T_1 ) - 1 ;
F_23 ( V_32 ) ;
V_5 = F_22 ( NULL , V_4 , & V_212 , V_32 , 0 , 0 ) ;
if ( V_5 < 0 ) {
F_23 ( V_32 ) ;
return V_5 ;
}
V_5 = F_184 ( V_4 , V_32 , V_130 , V_144 ) ;
if ( V_5 == 0 ) {
struct V_34 V_216 ;
F_102 ( V_32 -> V_50 [ 0 ] , & V_216 ,
V_32 -> V_51 [ 0 ] ) ;
if ( V_144 == V_216 . type )
V_207 = F_185 ( V_210 , V_216 . V_66 ) + 1 ;
}
goto V_217;
}
V_5 = F_184 ( V_4 , V_32 , V_130 , V_144 ) ;
if ( V_5 == 0 ) {
struct V_34 V_216 ;
F_102 ( V_32 -> V_50 [ 0 ] , & V_216 , V_32 -> V_51 [ 0 ] ) ;
if ( V_144 == V_216 . type ) {
V_207 = V_216 . V_66 ;
V_5 = F_19 ( V_2 , log , V_209 ,
V_32 -> V_50 [ 0 ] , V_32 -> V_51 [ 0 ] ,
& V_216 ) ;
if ( V_5 ) {
V_6 = V_5 ;
goto V_217;
}
}
}
F_23 ( V_32 ) ;
V_5 = F_22 ( NULL , V_4 , & V_212 , V_32 , 0 , 0 ) ;
if ( V_5 != 0 ) {
F_127 ( 1 ) ;
goto V_217;
}
while ( 1 ) {
struct V_34 V_216 ;
V_214 = V_32 -> V_50 [ 0 ] ;
V_149 = F_119 ( V_214 ) ;
for ( V_161 = V_32 -> V_51 [ 0 ] ; V_161 < V_149 ; V_161 ++ ) {
F_102 ( V_214 , & V_212 , V_161 ) ;
if ( V_212 . V_45 != V_130 || V_212 . type != V_144 )
goto V_217;
V_5 = F_19 ( V_2 , log , V_209 , V_214 , V_161 ,
& V_212 ) ;
if ( V_5 ) {
V_6 = V_5 ;
goto V_217;
}
}
V_32 -> V_51 [ 0 ] = V_149 ;
V_5 = F_120 ( V_4 , V_32 ) ;
if ( V_5 == 1 ) {
V_208 = ( T_1 ) - 1 ;
goto V_217;
}
F_102 ( V_32 -> V_50 [ 0 ] , & V_216 , V_32 -> V_51 [ 0 ] ) ;
if ( V_216 . V_45 != V_130 || V_216 . type != V_144 ) {
V_208 = ( T_1 ) - 1 ;
goto V_217;
}
if ( F_141 ( V_32 -> V_50 [ 0 ] ) != V_2 -> V_63 ) {
V_5 = F_19 ( V_2 , log , V_209 ,
V_32 -> V_50 [ 0 ] , V_32 -> V_51 [ 0 ] ,
& V_216 ) ;
if ( V_5 )
V_6 = V_5 ;
else
V_208 = V_216 . V_66 ;
goto V_217;
}
}
V_217:
F_23 ( V_32 ) ;
F_23 ( V_209 ) ;
if ( V_6 == 0 ) {
* V_211 = V_208 ;
V_5 = F_180 ( V_2 , log , V_32 , V_144 ,
V_130 , V_207 , V_208 ) ;
if ( V_5 )
V_6 = V_5 ;
}
return V_6 ;
}
static T_2 int F_186 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_68 * V_68 ,
struct V_31 * V_32 ,
struct V_31 * V_209 )
{
T_1 V_212 ;
T_1 V_213 ;
int V_5 ;
int V_144 = V_141 ;
V_118:
V_212 = 0 ;
V_213 = 0 ;
while ( 1 ) {
V_5 = F_182 ( V_2 , V_4 , V_68 , V_32 ,
V_209 , V_144 , V_212 ,
& V_213 ) ;
if ( V_5 )
return V_5 ;
if ( V_213 == ( T_1 ) - 1 )
break;
V_212 = V_213 + 1 ;
}
if ( V_144 == V_141 ) {
V_144 = V_142 ;
goto V_118;
}
return 0 ;
}
static int F_187 ( struct V_1 * V_2 ,
struct V_3 * log ,
struct V_31 * V_32 ,
T_1 V_45 , int V_218 )
{
int V_5 ;
struct V_34 V_35 ;
struct V_34 V_137 ;
int V_219 ;
V_35 . V_45 = V_45 ;
V_35 . type = V_218 ;
V_35 . V_66 = ( T_1 ) - 1 ;
while ( 1 ) {
V_5 = F_22 ( V_2 , log , & V_35 , V_32 , - 1 , 1 ) ;
F_188 ( V_5 == 0 ) ;
if ( V_5 < 0 )
break;
if ( V_32 -> V_51 [ 0 ] == 0 )
break;
V_32 -> V_51 [ 0 ] -- ;
F_102 ( V_32 -> V_50 [ 0 ] , & V_137 ,
V_32 -> V_51 [ 0 ] ) ;
if ( V_137 . V_45 != V_45 )
break;
V_137 . V_66 = 0 ;
V_137 . type = 0 ;
V_5 = F_189 ( V_32 -> V_50 [ 0 ] , & V_137 , 0 ,
& V_219 ) ;
V_5 = F_190 ( V_2 , log , V_32 , V_219 ,
V_32 -> V_51 [ 0 ] - V_219 + 1 ) ;
if ( V_5 || V_219 != 0 )
break;
F_23 ( V_32 ) ;
}
F_23 ( V_32 ) ;
if ( V_5 > 0 )
V_5 = 0 ;
return V_5 ;
}
static void F_191 ( struct V_1 * V_2 ,
struct V_20 * V_79 ,
struct V_55 * V_56 ,
struct V_68 * V_68 , int V_220 )
{
struct V_221 V_222 ;
F_192 ( & V_222 ) ;
if ( V_220 ) {
F_193 ( V_79 , V_56 , 0 , & V_222 ) ;
F_194 ( V_79 , V_56 , 0 , & V_222 ) ;
} else {
F_193 ( V_79 , V_56 ,
F_105 ( V_68 ) -> V_223 ,
& V_222 ) ;
F_194 ( V_79 , V_56 , V_68 -> V_206 , & V_222 ) ;
}
F_195 ( V_79 , V_56 , F_196 ( V_68 ) , & V_222 ) ;
F_197 ( V_79 , V_56 , F_198 ( V_68 ) , & V_222 ) ;
F_199 ( V_79 , V_56 , V_68 -> V_133 , & V_222 ) ;
F_200 ( V_79 , V_56 , V_68 -> V_131 , & V_222 ) ;
F_201 ( V_79 , F_202 ( V_56 ) ,
V_68 -> V_224 . V_225 , & V_222 ) ;
F_203 ( V_79 , F_202 ( V_56 ) ,
V_68 -> V_224 . V_226 , & V_222 ) ;
F_201 ( V_79 , F_204 ( V_56 ) ,
V_68 -> V_227 . V_225 , & V_222 ) ;
F_203 ( V_79 , F_204 ( V_56 ) ,
V_68 -> V_227 . V_226 , & V_222 ) ;
F_201 ( V_79 , F_205 ( V_56 ) ,
V_68 -> V_228 . V_225 , & V_222 ) ;
F_203 ( V_79 , F_205 ( V_56 ) ,
V_68 -> V_228 . V_226 , & V_222 ) ;
F_206 ( V_79 , V_56 , F_207 ( V_68 ) ,
& V_222 ) ;
F_208 ( V_79 , V_56 , V_68 -> V_229 , & V_222 ) ;
F_209 ( V_79 , V_56 , V_2 -> V_63 , & V_222 ) ;
F_210 ( V_79 , V_56 , V_68 -> V_230 , & V_222 ) ;
F_211 ( V_79 , V_56 , F_105 ( V_68 ) -> V_231 , & V_222 ) ;
F_212 ( V_79 , V_56 , 0 , & V_222 ) ;
}
static int F_213 ( struct V_1 * V_2 ,
struct V_3 * log , struct V_31 * V_32 ,
struct V_68 * V_68 )
{
struct V_55 * V_42 ;
struct V_34 V_35 ;
int V_5 ;
memcpy ( & V_35 , & F_105 ( V_68 ) -> V_96 , sizeof( V_35 ) ) ;
V_5 = F_30 ( V_2 , log , V_32 , & V_35 ,
sizeof( * V_42 ) ) ;
if ( V_5 && V_5 != - V_58 )
return V_5 ;
V_42 = F_27 ( V_32 -> V_50 [ 0 ] , V_32 -> V_51 [ 0 ] ,
struct V_55 ) ;
F_191 ( V_2 , V_32 -> V_50 [ 0 ] , V_42 , V_68 , 0 ) ;
F_23 ( V_32 ) ;
return 0 ;
}
static T_2 int F_214 ( struct V_1 * V_2 ,
struct V_68 * V_68 ,
struct V_31 * V_209 ,
struct V_20 * V_214 ,
int V_219 , int V_232 , int V_233 )
{
unsigned long V_234 ;
unsigned long V_235 ;
struct V_3 * log = F_105 ( V_68 ) -> V_4 -> V_8 ;
struct V_67 * V_236 ;
struct V_55 * V_42 ;
int V_5 ;
struct V_34 * V_237 ;
T_3 * V_238 ;
char * V_239 ;
int V_161 ;
struct V_240 V_85 ;
int V_241 = F_105 ( V_68 ) -> V_231 & V_242 ;
F_215 ( & V_85 ) ;
V_239 = F_24 ( V_232 * sizeof( struct V_34 ) +
V_232 * sizeof( T_3 ) , V_53 ) ;
if ( ! V_239 )
return - V_54 ;
V_238 = ( T_3 * ) V_239 ;
V_237 = (struct V_34 * ) ( V_239 + V_232 * sizeof( T_3 ) ) ;
for ( V_161 = 0 ; V_161 < V_232 ; V_161 ++ ) {
V_238 [ V_161 ] = F_20 ( V_214 , V_161 + V_219 ) ;
F_102 ( V_214 , V_237 + V_161 , V_161 + V_219 ) ;
}
V_5 = F_216 ( V_2 , log , V_209 ,
V_237 , V_238 , V_232 ) ;
if ( V_5 ) {
F_25 ( V_239 ) ;
return V_5 ;
}
for ( V_161 = 0 ; V_161 < V_232 ; V_161 ++ , V_209 -> V_51 [ 0 ] ++ ) {
V_235 = F_21 ( V_209 -> V_50 [ 0 ] ,
V_209 -> V_51 [ 0 ] ) ;
V_234 = F_21 ( V_214 , V_219 + V_161 ) ;
if ( V_237 [ V_161 ] . type == V_43 ) {
V_42 = F_27 ( V_209 -> V_50 [ 0 ] ,
V_209 -> V_51 [ 0 ] ,
struct V_55 ) ;
F_191 ( V_2 , V_209 -> V_50 [ 0 ] , V_42 ,
V_68 , V_233 == V_243 ) ;
} else {
F_37 ( V_209 -> V_50 [ 0 ] , V_214 , V_235 ,
V_234 , V_238 [ V_161 ] ) ;
}
if ( F_217 ( V_237 + V_161 ) == V_167 &&
! V_241 ) {
int V_64 ;
V_236 = F_27 ( V_214 , V_219 + V_161 ,
struct V_67 ) ;
if ( F_218 ( V_214 , V_236 ) < V_2 -> V_63 )
continue;
V_64 = F_42 ( V_214 , V_236 ) ;
if ( V_64 == V_70 ) {
T_1 V_244 , V_245 , V_246 , V_247 ;
V_244 = F_44 ( V_214 ,
V_236 ) ;
if ( V_244 == 0 )
continue;
V_245 = F_52 ( V_214 ,
V_236 ) ;
V_246 = F_53 ( V_214 , V_236 ) ;
V_247 = F_43 ( V_214 ,
V_236 ) ;
if ( F_58 ( V_214 ,
V_236 ) ) {
V_246 = 0 ;
V_247 = V_245 ;
}
V_5 = F_59 (
log -> V_15 -> V_90 ,
V_244 + V_246 , V_244 + V_246 + V_247 - 1 ,
& V_85 , 0 ) ;
if ( V_5 ) {
F_23 ( V_209 ) ;
F_25 ( V_239 ) ;
return V_5 ;
}
}
}
}
F_40 ( V_209 -> V_50 [ 0 ] ) ;
F_23 ( V_209 ) ;
F_25 ( V_239 ) ;
V_5 = 0 ;
while ( ! F_60 ( & V_85 ) ) {
struct V_86 * V_87 = F_61 ( V_85 . V_88 ,
struct V_86 ,
V_89 ) ;
if ( ! V_5 )
V_5 = F_62 ( V_2 , log , V_87 ) ;
F_63 ( & V_87 -> V_89 ) ;
F_25 ( V_87 ) ;
}
return V_5 ;
}
static int F_219 ( void * V_248 , struct V_240 * V_249 , struct V_240 * V_250 )
{
struct V_251 * V_252 , * V_253 ;
V_252 = F_61 ( V_249 , struct V_251 , V_89 ) ;
V_253 = F_61 ( V_250 , struct V_251 , V_89 ) ;
if ( V_252 -> V_27 < V_253 -> V_27 )
return - 1 ;
else if ( V_252 -> V_27 > V_253 -> V_27 )
return 1 ;
return 0 ;
}
static int F_220 ( struct V_1 * V_2 ,
struct V_68 * V_68 , struct V_3 * V_4 ,
struct V_251 * V_254 , struct V_31 * V_32 )
{
struct V_3 * log = V_4 -> V_8 ;
struct V_67 * V_255 ;
struct V_20 * V_79 ;
struct V_256 * V_257 ;
struct V_240 V_85 ;
struct V_221 V_222 ;
struct V_34 V_35 ;
T_1 V_258 = V_254 -> V_258 ;
T_1 V_259 = V_254 -> V_259 ;
T_1 V_260 ;
T_1 V_261 ;
T_1 V_262 = V_254 -> V_27 - V_254 -> V_263 ;
T_1 V_264 ;
int V_5 ;
int V_98 = log -> V_179 % 2 ;
bool V_241 = F_105 ( V_68 ) -> V_231 & V_242 ;
V_5 = F_221 ( V_2 , log , V_68 , V_32 , V_254 -> V_27 ,
V_254 -> V_27 + V_254 -> V_28 , NULL , 0 ) ;
if ( V_5 )
return V_5 ;
F_215 ( & V_85 ) ;
F_192 ( & V_222 ) ;
V_35 . V_45 = F_50 ( V_68 ) ;
V_35 . type = V_167 ;
V_35 . V_66 = V_254 -> V_27 ;
V_5 = F_30 ( V_2 , log , V_32 , & V_35 , sizeof( * V_255 ) ) ;
if ( V_5 )
return V_5 ;
V_79 = V_32 -> V_50 [ 0 ] ;
V_255 = F_27 ( V_79 , V_32 -> V_51 [ 0 ] ,
struct V_67 ) ;
F_222 ( V_79 , V_255 , V_254 -> V_223 ,
& V_222 ) ;
if ( F_223 ( V_265 , & V_254 -> V_231 ) ) {
V_241 = true ;
F_224 ( V_79 , V_255 ,
V_71 ,
& V_222 ) ;
} else {
F_224 ( V_79 , V_255 ,
V_70 ,
& V_222 ) ;
if ( V_254 -> V_266 == 0 )
V_241 = true ;
}
V_264 = F_185 ( V_254 -> V_264 , V_254 -> V_267 ) ;
if ( V_254 -> V_268 != V_269 ) {
F_225 ( V_79 , V_255 ,
V_254 -> V_266 ,
& V_222 ) ;
F_226 ( V_79 , V_255 , V_264 ,
& V_222 ) ;
} else if ( V_254 -> V_266 < V_270 ) {
F_225 ( V_79 , V_255 ,
V_254 -> V_266 -
V_262 , & V_222 ) ;
F_226 ( V_79 , V_255 , V_264 ,
& V_222 ) ;
} else {
F_225 ( V_79 , V_255 , 0 , & V_222 ) ;
F_226 ( V_79 , V_255 , 0 ,
& V_222 ) ;
}
F_227 ( V_79 , V_255 ,
V_254 -> V_27 - V_254 -> V_263 ,
& V_222 ) ;
F_228 ( V_79 , V_255 , V_254 -> V_28 , & V_222 ) ;
F_229 ( V_79 , V_255 , V_254 -> V_271 , & V_222 ) ;
F_230 ( V_79 , V_255 , V_254 -> V_268 ,
& V_222 ) ;
F_231 ( V_79 , V_255 , 0 , & V_222 ) ;
F_232 ( V_79 , V_255 , 0 , & V_222 ) ;
F_40 ( V_79 ) ;
F_23 ( V_32 ) ;
if ( V_5 ) {
return V_5 ;
}
if ( V_241 )
return 0 ;
if ( V_254 -> V_268 ) {
V_260 = 0 ;
V_261 = V_264 ;
}
V_118:
F_233 ( & log -> V_272 [ V_98 ] ) ;
F_234 (ordered, &log->logged_list[index], log_list) {
struct V_86 * V_273 ;
if ( ! V_259 )
break;
if ( V_257 -> V_68 != V_68 )
continue;
if ( V_257 -> V_274 + V_257 -> V_28 <= V_258 ||
V_258 + V_259 <= V_257 -> V_274 )
continue;
if ( V_257 -> V_274 > V_258 ) {
if ( V_257 -> V_274 + V_257 -> V_28 >=
V_258 + V_259 )
V_259 = V_257 -> V_274 - V_258 ;
} else {
if ( V_257 -> V_274 + V_257 -> V_28 <
V_258 + V_259 ) {
V_259 = ( V_258 + V_259 ) -
( V_257 -> V_274 + V_257 -> V_28 ) ;
V_258 = V_257 -> V_274 +
V_257 -> V_28 ;
} else {
V_259 = 0 ;
}
}
if ( F_235 ( V_275 ,
& V_257 -> V_231 ) )
continue;
F_3 ( & V_257 -> V_276 ) ;
F_236 ( & log -> V_272 [ V_98 ] ) ;
F_237 ( V_257 -> V_30 , V_257 -> V_277 == 0 ) ;
F_234 (sum, &ordered->list, list) {
V_5 = F_62 ( V_2 , log , V_273 ) ;
if ( V_5 ) {
F_238 ( V_257 ) ;
goto V_278;
}
}
F_238 ( V_257 ) ;
goto V_118;
}
F_236 ( & log -> V_272 [ V_98 ] ) ;
V_278:
if ( ! V_259 || V_5 )
return V_5 ;
V_260 = V_258 - V_254 -> V_27 ;
V_261 = V_259 ;
V_5 = F_59 ( log -> V_15 -> V_90 ,
V_254 -> V_266 + V_260 ,
V_254 -> V_266 + V_260 +
V_261 - 1 , & V_85 , 0 ) ;
if ( V_5 )
return V_5 ;
while ( ! F_60 ( & V_85 ) ) {
struct V_86 * V_87 = F_61 ( V_85 . V_88 ,
struct V_86 ,
V_89 ) ;
if ( ! V_5 )
V_5 = F_62 ( V_2 , log , V_87 ) ;
F_63 ( & V_87 -> V_89 ) ;
F_25 ( V_87 ) ;
}
return V_5 ;
}
static int F_239 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_68 * V_68 ,
struct V_31 * V_32 )
{
struct V_251 * V_254 , * V_279 ;
struct V_240 V_280 ;
struct V_281 * V_282 = & F_105 ( V_68 ) -> V_283 ;
T_1 V_284 ;
int V_5 = 0 ;
int V_285 = 0 ;
F_215 ( & V_280 ) ;
F_240 ( & V_282 -> V_286 ) ;
V_284 = V_4 -> V_15 -> V_287 ;
F_241 (em, n, &tree->modified_extents, list) {
F_242 ( & V_254 -> V_89 ) ;
if ( ++ V_285 > 32768 ) {
F_242 ( & V_282 -> V_288 ) ;
V_5 = - V_289 ;
goto V_290;
}
if ( V_254 -> V_223 <= V_284 )
continue;
F_3 ( & V_254 -> V_276 ) ;
F_243 ( V_291 , & V_254 -> V_231 ) ;
F_244 ( & V_254 -> V_89 , & V_280 ) ;
V_285 ++ ;
}
F_245 ( NULL , & V_280 , F_219 ) ;
V_290:
while ( ! F_60 ( & V_280 ) ) {
V_254 = F_61 ( V_280 . V_88 , struct V_251 , V_89 ) ;
F_242 ( & V_254 -> V_89 ) ;
if ( V_5 ) {
F_246 ( V_282 , V_254 ) ;
F_247 ( V_254 ) ;
continue;
}
F_248 ( & V_282 -> V_286 ) ;
V_5 = F_220 ( V_2 , V_68 , V_4 , V_254 , V_32 ) ;
F_240 ( & V_282 -> V_286 ) ;
F_246 ( V_282 , V_254 ) ;
F_247 ( V_254 ) ;
}
F_127 ( ! F_60 ( & V_280 ) ) ;
F_248 ( & V_282 -> V_286 ) ;
F_23 ( V_32 ) ;
return V_5 ;
}
static int F_249 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_68 * V_68 ,
int V_233 )
{
struct V_31 * V_32 ;
struct V_31 * V_209 ;
struct V_34 V_212 ;
struct V_34 V_213 ;
struct V_3 * log = V_4 -> V_8 ;
struct V_20 * V_214 = NULL ;
int V_6 = 0 ;
int V_5 ;
int V_149 ;
int V_292 = 0 ;
int V_293 ;
bool V_294 = false ;
T_1 V_130 = F_50 ( V_68 ) ;
V_32 = F_78 () ;
if ( ! V_32 )
return - V_54 ;
V_209 = F_78 () ;
if ( ! V_209 ) {
F_82 ( V_32 ) ;
return - V_54 ;
}
V_212 . V_45 = V_130 ;
V_212 . type = V_43 ;
V_212 . V_66 = 0 ;
V_213 . V_45 = V_130 ;
if ( F_34 ( V_68 -> V_133 ) ||
( ! F_223 ( V_295 ,
& F_105 ( V_68 ) -> V_296 ) &&
V_233 == V_243 ) )
V_213 . type = V_166 ;
else
V_213 . type = ( T_4 ) - 1 ;
V_213 . V_66 = ( T_1 ) - 1 ;
if ( F_34 ( V_68 -> V_133 ) ||
F_105 ( V_68 ) -> V_223 > V_4 -> V_15 -> V_287 ) {
V_5 = F_250 ( V_2 , V_68 ) ;
if ( V_5 ) {
F_82 ( V_32 ) ;
F_82 ( V_209 ) ;
return V_5 ;
}
}
F_2 ( & F_105 ( V_68 ) -> V_7 ) ;
F_251 ( log , V_68 ) ;
if ( F_34 ( V_68 -> V_133 ) ) {
int V_218 = V_158 ;
if ( V_233 == V_243 )
V_218 = V_166 ;
V_5 = F_187 ( V_2 , log , V_32 , V_130 , V_218 ) ;
} else {
if ( F_252 ( V_295 ,
& F_105 ( V_68 ) -> V_296 ) ) {
F_253 ( V_297 ,
& F_105 ( V_68 ) -> V_296 ) ;
V_5 = F_254 ( V_2 , log ,
V_68 , 0 , 0 ) ;
} else if ( F_252 ( V_297 ,
& F_105 ( V_68 ) -> V_296 ) ) {
if ( V_233 == V_298 )
V_294 = true ;
V_213 . type = V_166 ;
V_5 = F_187 ( V_2 , log , V_32 , V_130 ,
V_213 . type ) ;
} else {
if ( V_233 == V_298 )
V_294 = true ;
V_5 = F_213 ( V_2 , log , V_209 , V_68 ) ;
if ( V_5 ) {
V_6 = V_5 ;
goto V_204;
}
goto V_299;
}
}
if ( V_5 ) {
V_6 = V_5 ;
goto V_204;
}
V_32 -> V_215 = 1 ;
while ( 1 ) {
V_293 = 0 ;
V_5 = F_183 ( V_4 , & V_212 , & V_213 ,
V_32 , V_2 -> V_63 ) ;
if ( V_5 != 0 )
break;
V_118:
if ( V_212 . V_45 != V_130 )
break;
if ( V_212 . type > V_213 . type )
break;
V_214 = V_32 -> V_50 [ 0 ] ;
if ( V_293 && V_292 + V_293 == V_32 -> V_51 [ 0 ] ) {
V_293 ++ ;
goto V_300;
} else if ( ! V_293 ) {
V_292 = V_32 -> V_51 [ 0 ] ;
V_293 = 1 ;
goto V_300;
}
V_5 = F_214 ( V_2 , V_68 , V_209 , V_214 , V_292 ,
V_293 , V_233 ) ;
if ( V_5 ) {
V_6 = V_5 ;
goto V_204;
}
V_293 = 1 ;
V_292 = V_32 -> V_51 [ 0 ] ;
V_300:
V_149 = F_119 ( V_32 -> V_50 [ 0 ] ) ;
V_32 -> V_51 [ 0 ] ++ ;
if ( V_32 -> V_51 [ 0 ] < V_149 ) {
F_102 ( V_32 -> V_50 [ 0 ] , & V_212 ,
V_32 -> V_51 [ 0 ] ) ;
goto V_118;
}
if ( V_293 ) {
V_5 = F_214 ( V_2 , V_68 , V_209 , V_214 ,
V_292 ,
V_293 , V_233 ) ;
if ( V_5 ) {
V_6 = V_5 ;
goto V_204;
}
V_293 = 0 ;
}
F_23 ( V_32 ) ;
if ( V_212 . V_66 < ( T_1 ) - 1 )
V_212 . V_66 ++ ;
else if ( V_212 . type < ( T_4 ) - 1 )
V_212 . type ++ ;
else if ( V_212 . V_45 < ( T_1 ) - 1 )
V_212 . V_45 ++ ;
else
break;
}
if ( V_293 ) {
V_5 = F_214 ( V_2 , V_68 , V_209 , V_214 , V_292 ,
V_293 , V_233 ) ;
if ( V_5 ) {
V_6 = V_5 ;
goto V_204;
}
V_293 = 0 ;
}
V_299:
if ( V_294 ) {
F_23 ( V_209 ) ;
V_5 = F_239 ( V_2 , V_4 , V_68 , V_209 ) ;
if ( V_5 ) {
V_6 = V_5 ;
goto V_204;
}
} else {
struct V_281 * V_282 = & F_105 ( V_68 ) -> V_283 ;
struct V_251 * V_254 , * V_279 ;
F_240 ( & V_282 -> V_286 ) ;
F_241 (em, n, &tree->modified_extents, list)
F_242 ( & V_254 -> V_89 ) ;
F_248 ( & V_282 -> V_286 ) ;
}
if ( V_233 == V_298 && F_34 ( V_68 -> V_133 ) ) {
F_23 ( V_32 ) ;
F_23 ( V_209 ) ;
V_5 = F_186 ( V_2 , V_4 , V_68 , V_32 , V_209 ) ;
if ( V_5 ) {
V_6 = V_5 ;
goto V_204;
}
}
F_105 ( V_68 ) -> V_203 = V_2 -> V_63 ;
F_105 ( V_68 ) -> V_198 = F_105 ( V_68 ) -> V_301 ;
V_204:
if ( V_6 )
F_158 ( log , log -> V_179 ) ;
F_4 ( & F_105 ( V_68 ) -> V_7 ) ;
F_82 ( V_32 ) ;
F_82 ( V_209 ) ;
return V_6 ;
}
static T_2 int F_255 ( struct V_1 * V_2 ,
struct V_68 * V_68 ,
struct V_302 * V_172 ,
struct V_303 * V_304 ,
T_1 V_305 )
{
int V_5 = 0 ;
struct V_3 * V_4 ;
struct V_302 * V_306 = NULL ;
if ( F_125 ( V_68 -> V_133 ) &&
F_105 ( V_68 ) -> V_223 <= V_305 &&
F_105 ( V_68 ) -> V_307 <= V_305 )
goto V_74;
if ( ! F_34 ( V_68 -> V_133 ) ) {
if ( ! V_172 || ! V_172 -> V_308 || V_304 != V_172 -> V_308 -> V_309 )
goto V_74;
V_68 = V_172 -> V_308 ;
}
while ( 1 ) {
F_105 ( V_68 ) -> V_203 = V_2 -> V_63 ;
F_8 () ;
if ( F_105 ( V_68 ) -> V_307 > V_305 ) {
V_4 = F_105 ( V_68 ) -> V_4 ;
V_4 -> V_15 -> V_183 =
V_2 -> V_63 ;
V_5 = 1 ;
break;
}
if ( ! V_172 || ! V_172 -> V_308 || V_304 != V_172 -> V_308 -> V_309 )
break;
if ( F_256 ( V_172 ) )
break;
V_172 = F_257 ( V_172 ) ;
F_258 ( V_306 ) ;
V_306 = V_172 ;
V_68 = V_172 -> V_308 ;
}
F_258 ( V_306 ) ;
V_74:
return V_5 ;
}
static int F_259 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_68 * V_68 ,
struct V_302 * V_172 , int V_310 )
{
int V_233 = V_310 ? V_243 : V_298 ;
struct V_303 * V_304 ;
struct V_302 * V_306 = NULL ;
int V_5 = 0 ;
T_1 V_305 = V_4 -> V_15 -> V_287 ;
V_304 = V_68 -> V_309 ;
if ( F_156 ( V_4 , V_311 ) ) {
V_5 = 1 ;
goto V_312;
}
if ( V_4 -> V_15 -> V_183 >
V_4 -> V_15 -> V_287 ) {
V_5 = 1 ;
goto V_312;
}
if ( V_4 != F_105 ( V_68 ) -> V_4 ||
F_260 ( & V_4 -> V_180 ) == 0 ) {
V_5 = 1 ;
goto V_312;
}
V_5 = F_255 ( V_2 , V_68 , V_172 ,
V_304 , V_305 ) ;
if ( V_5 )
goto V_312;
if ( F_261 ( V_68 , V_2 -> V_63 ) ) {
V_5 = V_313 ;
goto V_312;
}
V_5 = F_1 ( V_2 , V_4 ) ;
if ( V_5 )
goto V_314;
V_5 = F_249 ( V_2 , V_4 , V_68 , V_233 ) ;
if ( V_5 )
goto V_314;
if ( F_125 ( V_68 -> V_133 ) &&
F_105 ( V_68 ) -> V_223 <= V_305 &&
F_105 ( V_68 ) -> V_307 <= V_305 ) {
V_5 = 0 ;
goto V_314;
}
V_233 = V_243 ;
while ( 1 ) {
if ( ! V_172 || ! V_172 -> V_308 || V_304 != V_172 -> V_308 -> V_309 )
break;
V_68 = V_172 -> V_308 ;
if ( V_4 != F_105 ( V_68 ) -> V_4 )
break;
if ( F_105 ( V_68 ) -> V_223 >
V_4 -> V_15 -> V_287 ) {
V_5 = F_249 ( V_2 , V_4 , V_68 , V_233 ) ;
if ( V_5 )
goto V_314;
}
if ( F_256 ( V_172 ) )
break;
V_172 = F_257 ( V_172 ) ;
F_258 ( V_306 ) ;
V_306 = V_172 ;
}
V_5 = 0 ;
V_314:
F_258 ( V_306 ) ;
if ( V_5 < 0 ) {
V_4 -> V_15 -> V_183 = V_2 -> V_63 ;
V_5 = 1 ;
}
F_10 ( V_4 ) ;
V_312:
return V_5 ;
}
int F_262 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_302 * V_302 )
{
struct V_302 * V_172 = F_257 ( V_302 ) ;
int V_5 ;
V_5 = F_259 ( V_2 , V_4 , V_302 -> V_308 , V_172 , 0 ) ;
F_258 ( V_172 ) ;
return V_5 ;
}
int F_263 ( struct V_3 * V_17 )
{
int V_5 ;
struct V_31 * V_32 ;
struct V_1 * V_2 ;
struct V_34 V_35 ;
struct V_34 V_137 ;
struct V_34 V_315 ;
struct V_3 * log ;
struct V_200 * V_15 = V_17 -> V_15 ;
struct V_22 V_23 = {
. V_175 = F_14 ,
. V_162 = 0 ,
} ;
V_32 = F_78 () ;
if ( ! V_32 )
return - V_54 ;
V_15 -> V_316 = 1 ;
V_2 = F_264 ( V_15 -> V_197 , 0 ) ;
if ( F_75 ( V_2 ) ) {
V_5 = F_176 ( V_2 ) ;
goto error;
}
V_23 . V_2 = V_2 ;
V_23 . V_25 = 1 ;
V_5 = F_142 ( V_2 , V_17 , & V_23 ) ;
if ( V_5 ) {
F_265 ( V_15 , V_5 , L_1
L_2 ) ;
goto error;
}
V_118:
V_35 . V_45 = V_46 ;
V_35 . V_66 = ( T_1 ) - 1 ;
F_109 ( & V_35 , V_317 ) ;
while ( 1 ) {
V_5 = F_22 ( NULL , V_17 , & V_35 , V_32 , 0 , 0 ) ;
if ( V_5 < 0 ) {
F_265 ( V_15 , V_5 ,
L_3 ) ;
goto error;
}
if ( V_5 > 0 ) {
if ( V_32 -> V_51 [ 0 ] == 0 )
break;
V_32 -> V_51 [ 0 ] -- ;
}
F_102 ( V_32 -> V_50 [ 0 ] , & V_137 ,
V_32 -> V_51 [ 0 ] ) ;
F_23 ( V_32 ) ;
if ( V_137 . V_45 != V_46 )
break;
log = F_266 ( V_17 ,
& V_137 ) ;
if ( F_75 ( log ) ) {
V_5 = F_176 ( log ) ;
F_265 ( V_15 , V_5 ,
L_4 ) ;
goto error;
}
V_315 . V_45 = V_137 . V_66 ;
V_315 . type = V_317 ;
V_315 . V_66 = ( T_1 ) - 1 ;
V_23 . V_159 = F_267 ( V_15 , & V_315 ) ;
if ( F_75 ( V_23 . V_159 ) ) {
V_5 = F_176 ( V_23 . V_159 ) ;
F_133 ( log -> V_176 ) ;
F_133 ( log -> V_318 ) ;
F_25 ( log ) ;
F_265 ( V_15 , V_5 , L_5
L_6 ) ;
goto error;
}
V_23 . V_159 -> V_8 = log ;
F_268 ( V_2 , V_23 . V_159 ) ;
V_5 = F_142 ( V_2 , log , & V_23 ) ;
if ( ! V_5 && V_23 . V_162 == V_165 ) {
V_5 = F_107 ( V_2 , V_23 . V_159 ,
V_32 ) ;
}
V_35 . V_66 = V_137 . V_66 - 1 ;
V_23 . V_159 -> V_8 = NULL ;
F_133 ( log -> V_176 ) ;
F_133 ( log -> V_318 ) ;
F_25 ( log ) ;
if ( V_5 )
goto error;
if ( V_137 . V_66 == 0 )
break;
}
F_23 ( V_32 ) ;
if ( V_23 . V_25 ) {
V_23 . V_25 = 0 ;
V_23 . V_175 = F_122 ;
V_23 . V_162 = V_163 ;
goto V_118;
}
if ( V_23 . V_162 < V_165 ) {
V_23 . V_162 ++ ;
goto V_118;
}
F_82 ( V_32 ) ;
V_5 = F_269 ( V_2 , V_15 -> V_197 ) ;
if ( V_5 )
return V_5 ;
F_133 ( V_17 -> V_176 ) ;
V_17 -> V_8 = NULL ;
V_15 -> V_316 = 0 ;
F_25 ( V_17 ) ;
return 0 ;
error:
if ( V_23 . V_2 )
F_270 ( V_23 . V_2 , V_15 -> V_197 ) ;
F_82 ( V_32 ) ;
return V_5 ;
}
void F_271 ( struct V_1 * V_2 ,
struct V_68 * V_91 , struct V_68 * V_68 ,
int V_319 )
{
if ( F_125 ( V_68 -> V_133 ) )
F_105 ( V_68 ) -> V_307 = V_2 -> V_63 ;
F_8 () ;
if ( F_105 ( V_91 ) -> V_203 == V_2 -> V_63 )
return;
if ( F_105 ( V_68 ) -> V_203 == V_2 -> V_63 )
return;
if ( V_319 )
goto V_320;
return;
V_320:
F_105 ( V_91 ) -> V_307 = V_2 -> V_63 ;
}
int F_272 ( struct V_1 * V_2 ,
struct V_68 * V_68 , struct V_68 * V_321 ,
struct V_302 * V_172 )
{
struct V_3 * V_4 = F_105 ( V_68 ) -> V_4 ;
if ( F_125 ( V_68 -> V_133 ) )
F_105 ( V_68 ) -> V_307 = V_2 -> V_63 ;
if ( F_105 ( V_68 ) -> V_203 <=
V_4 -> V_15 -> V_287 &&
( ! V_321 || F_105 ( V_321 ) -> V_203 <=
V_4 -> V_15 -> V_287 ) )
return 0 ;
return F_259 ( V_2 , V_4 , V_68 , V_172 , 1 ) ;
}
