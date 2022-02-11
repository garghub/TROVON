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
if ( V_23 -> V_25 )
F_15 ( log -> V_15 -> V_26 ,
V_21 -> V_27 , V_21 -> V_28 ) ;
if ( F_16 ( V_21 , V_24 , 0 ) ) {
if ( V_23 -> V_29 )
F_17 ( V_21 ) ;
if ( V_23 -> V_30 )
F_18 ( V_21 ) ;
}
return 0 ;
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
F_31 ( V_2 , V_4 , V_32 , V_36 , 1 ) ;
else if ( V_59 < V_36 )
F_32 ( V_2 , V_4 , V_32 ,
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
F_52 ( V_5 ) ;
if ( V_64 == V_70 ||
V_64 == V_71 ) {
T_1 V_66 ;
unsigned long V_80 ;
struct V_34 V_81 ;
V_5 = F_30 ( V_2 , V_4 , V_32 , V_35 ,
sizeof( * V_56 ) ) ;
F_52 ( V_5 ) ;
V_80 = F_21 ( V_32 -> V_50 [ 0 ] ,
V_32 -> V_51 [ 0 ] ) ;
F_37 ( V_32 -> V_50 [ 0 ] , V_21 , V_80 ,
( unsigned long ) V_56 , sizeof( * V_56 ) ) ;
V_81 . V_45 = F_44 ( V_21 , V_56 ) ;
V_81 . V_66 = F_53 ( V_21 , V_56 ) ;
V_81 . type = V_82 ;
V_66 = V_35 -> V_66 - F_54 ( V_21 , V_56 ) ;
if ( V_81 . V_45 > 0 ) {
T_1 V_83 ;
T_1 V_84 ;
F_55 ( V_85 ) ;
V_5 = F_56 ( V_4 , V_81 . V_45 ,
V_81 . V_66 ) ;
if ( V_5 == 0 ) {
V_5 = F_57 ( V_2 , V_4 ,
V_81 . V_45 , V_81 . V_66 ,
0 , V_4 -> V_44 . V_45 ,
V_35 -> V_45 , V_66 , 0 ) ;
F_52 ( V_5 ) ;
} else {
V_5 = F_58 ( V_2 ,
V_4 , V_4 -> V_44 . V_45 ,
V_35 -> V_45 , V_66 , & V_81 ) ;
F_52 ( V_5 ) ;
}
F_23 ( V_32 ) ;
if ( F_59 ( V_21 , V_56 ) ) {
V_83 = V_81 . V_45 ;
V_84 = V_83 + V_81 . V_66 ;
} else {
V_83 = V_81 . V_45 +
F_54 ( V_21 , V_56 ) ;
V_84 = V_83 +
F_43 ( V_21 , V_56 ) ;
}
V_5 = F_60 ( V_4 -> V_8 ,
V_83 , V_84 - 1 ,
& V_85 , 0 ) ;
F_52 ( V_5 ) ;
while ( ! F_61 ( & V_85 ) ) {
struct V_86 * V_87 ;
V_87 = F_62 ( V_85 . V_88 ,
struct V_86 ,
V_89 ) ;
V_5 = F_63 ( V_2 ,
V_4 -> V_15 -> V_90 ,
V_87 ) ;
F_52 ( V_5 ) ;
F_64 ( & V_87 -> V_89 ) ;
F_25 ( V_87 ) ;
}
} else {
F_23 ( V_32 ) ;
}
} else if ( V_64 == V_72 ) {
V_5 = F_19 ( V_2 , V_4 , V_32 , V_21 , V_33 , V_35 ) ;
F_52 ( V_5 ) ;
}
F_65 ( V_68 , V_57 ) ;
V_5 = F_66 ( V_2 , V_4 , V_68 ) ;
V_74:
if ( V_68 )
F_67 ( V_68 ) ;
return V_5 ;
}
static T_2 int F_68 ( struct V_1 * V_2 ,
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
F_69 ( V_79 , V_93 , & V_96 ) ;
V_95 = F_70 ( V_79 , V_93 ) ;
V_94 = F_24 ( V_95 , V_53 ) ;
if ( ! V_94 )
return - V_54 ;
F_26 ( V_79 , V_94 , ( unsigned long ) ( V_93 + 1 ) , V_95 ) ;
F_23 ( V_32 ) ;
V_68 = F_48 ( V_4 , V_96 . V_45 ) ;
if ( ! V_68 ) {
F_25 ( V_94 ) ;
return - V_75 ;
}
V_5 = F_71 ( V_2 , V_4 , V_32 , V_96 . V_45 ) ;
F_52 ( V_5 ) ;
V_5 = F_72 ( V_2 , V_4 , V_91 , V_68 , V_94 , V_95 ) ;
F_52 ( V_5 ) ;
F_25 ( V_94 ) ;
F_67 ( V_68 ) ;
F_73 ( V_2 , V_4 ) ;
return V_5 ;
}
static T_2 int F_74 ( struct V_3 * V_4 ,
struct V_31 * V_32 ,
T_1 V_97 , T_1 V_45 , T_1 V_98 ,
const char * V_94 , int V_95 )
{
struct V_92 * V_93 ;
struct V_34 V_96 ;
int V_99 = 0 ;
V_93 = F_75 ( NULL , V_4 , V_32 , V_97 ,
V_98 , V_94 , V_95 , 0 ) ;
if ( V_93 && ! F_76 ( V_93 ) ) {
F_69 ( V_32 -> V_50 [ 0 ] , V_93 , & V_96 ) ;
if ( V_96 . V_45 != V_45 )
goto V_74;
} else
goto V_74;
F_23 ( V_32 ) ;
V_93 = F_77 ( NULL , V_4 , V_32 , V_97 , V_94 , V_95 , 0 ) ;
if ( V_93 && ! F_76 ( V_93 ) ) {
F_69 ( V_32 -> V_50 [ 0 ] , V_93 , & V_96 ) ;
if ( V_96 . V_45 != V_45 )
goto V_74;
} else
goto V_74;
V_99 = 1 ;
V_74:
F_23 ( V_32 ) ;
return V_99 ;
}
static T_2 int F_78 ( struct V_3 * log ,
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
V_32 = F_79 () ;
if ( ! V_32 )
return - V_54 ;
V_5 = F_22 ( NULL , log , V_35 , V_32 , 0 , 0 ) ;
if ( V_5 != 0 )
goto V_74;
V_104 = F_21 ( V_32 -> V_50 [ 0 ] , V_32 -> V_51 [ 0 ] ) ;
if ( V_35 -> type == V_108 ) {
if ( F_80 ( V_32 , V_100 ,
V_94 , V_101 , NULL ) )
V_99 = 1 ;
goto V_74;
}
V_36 = F_20 ( V_32 -> V_50 [ 0 ] , V_32 -> V_51 [ 0 ] ) ;
V_105 = V_104 + V_36 ;
while ( V_104 < V_105 ) {
V_103 = (struct V_102 * ) V_104 ;
V_107 = F_81 ( V_32 -> V_50 [ 0 ] , V_103 ) ;
if ( V_107 == V_101 ) {
V_106 = ( unsigned long ) ( V_103 + 1 ) ;
V_5 = F_82 ( V_32 -> V_50 [ 0 ] , V_94 ,
V_106 , V_101 ) ;
if ( V_5 == 0 ) {
V_99 = 1 ;
goto V_74;
}
}
V_104 = ( unsigned long ) ( V_103 + 1 ) + V_107 ;
}
V_74:
F_83 ( V_32 ) ;
return V_99 ;
}
static inline int F_84 ( struct V_1 * V_2 ,
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
V_114 = F_81 ( V_79 ,
V_120 ) ;
V_113 = F_24 ( V_114 , V_53 ) ;
F_52 ( ! V_113 ) ;
F_26 ( V_79 , V_113 ,
( unsigned long ) ( V_120 + 1 ) ,
V_114 ) ;
if ( ! F_78 ( V_8 , & V_115 ,
V_110 ,
V_113 ,
V_114 ) ) {
F_85 ( V_68 ) ;
F_23 ( V_32 ) ;
V_5 = F_72 ( V_2 , V_4 , V_91 ,
V_68 , V_113 ,
V_114 ) ;
F_52 ( V_5 ) ;
F_73 ( V_2 , V_4 ) ;
F_25 ( V_113 ) ;
* V_112 = 1 ;
goto V_118;
}
F_25 ( V_113 ) ;
V_104 = ( unsigned long ) ( V_120 + 1 ) + V_114 ;
}
F_52 ( V_5 ) ;
* V_112 = 1 ;
}
F_23 ( V_32 ) ;
V_117 = F_86 ( NULL , V_4 , V_32 , V_94 , V_101 ,
V_109 , V_110 , 0 ,
0 ) ;
if ( ! F_87 ( V_117 ) ) {
T_3 V_36 ;
T_3 V_121 = 0 ;
unsigned long V_122 ;
struct V_68 * V_123 ;
V_79 = V_32 -> V_50 [ 0 ] ;
V_36 = F_20 ( V_79 , V_32 -> V_51 [ 0 ] ) ;
V_122 = F_21 ( V_79 , V_32 -> V_51 [ 0 ] ) ;
while ( V_121 < V_36 ) {
V_117 = (struct V_116 * ) V_122 + V_121 ;
V_114 = F_88 ( V_79 , V_117 ) ;
if ( F_89 ( V_79 , V_117 ) != V_110 )
goto V_88;
V_113 = F_24 ( V_114 , V_53 ) ;
F_26 ( V_79 , V_113 , ( unsigned long ) & V_117 -> V_94 ,
V_114 ) ;
V_115 . V_45 = V_109 ;
V_115 . type = V_108 ;
V_115 . V_66 = F_90 ( V_110 ,
V_113 ,
V_114 ) ;
V_5 = 0 ;
if ( ! F_78 ( V_8 , & V_115 ,
V_110 , V_113 ,
V_114 ) ) {
V_5 = - V_18 ;
V_123 = F_48 ( V_4 ,
V_110 ) ;
if ( V_123 ) {
F_85 ( V_68 ) ;
F_23 ( V_32 ) ;
V_5 = F_72 ( V_2 , V_4 ,
V_123 ,
V_68 ,
V_113 ,
V_114 ) ;
F_73 ( V_2 , V_4 ) ;
}
F_52 ( V_5 ) ;
F_67 ( V_123 ) ;
F_25 ( V_113 ) ;
* V_112 = 1 ;
goto V_118;
}
F_25 ( V_113 ) ;
F_52 ( V_5 ) ;
V_88:
V_121 += V_114 + sizeof( * V_117 ) ;
}
* V_112 = 1 ;
}
F_23 ( V_32 ) ;
V_93 = F_75 ( V_2 , V_4 , V_32 , F_50 ( V_91 ) ,
V_111 , V_94 , V_101 , 0 ) ;
if ( V_93 && ! F_76 ( V_93 ) ) {
V_5 = F_68 ( V_2 , V_4 , V_32 , V_91 , V_93 ) ;
F_52 ( V_5 ) ;
}
F_23 ( V_32 ) ;
V_93 = F_77 ( V_2 , V_4 , V_32 , F_50 ( V_91 ) ,
V_94 , V_101 , 0 ) ;
if ( V_93 && ! F_76 ( V_93 ) ) {
V_5 = F_68 ( V_2 , V_4 , V_32 , V_91 , V_93 ) ;
F_52 ( V_5 ) ;
}
F_23 ( V_32 ) ;
return 0 ;
}
static int F_91 ( struct V_20 * V_21 , unsigned long V_124 ,
T_3 * V_101 , char * * V_94 , T_1 * V_98 ,
T_1 * V_110 )
{
struct V_116 * V_117 ;
V_117 = (struct V_116 * ) V_124 ;
* V_101 = F_88 ( V_21 , V_117 ) ;
* V_94 = F_24 ( * V_101 , V_53 ) ;
if ( * V_94 == NULL )
return - V_54 ;
F_26 ( V_21 , * V_94 , ( unsigned long ) & V_117 -> V_94 ,
* V_101 ) ;
* V_98 = F_92 ( V_21 , V_117 ) ;
if ( V_110 )
* V_110 = F_89 ( V_21 , V_117 ) ;
return 0 ;
}
static int F_93 ( struct V_20 * V_21 , unsigned long V_124 ,
T_3 * V_101 , char * * V_94 , T_1 * V_98 )
{
struct V_102 * V_103 ;
V_103 = (struct V_102 * ) V_124 ;
* V_101 = F_81 ( V_21 , V_103 ) ;
* V_94 = F_24 ( * V_101 , V_53 ) ;
if ( * V_94 == NULL )
return - V_54 ;
F_26 ( V_21 , * V_94 , ( unsigned long ) ( V_103 + 1 ) , * V_101 ) ;
* V_98 = F_94 ( V_21 , V_103 ) ;
return 0 ;
}
static T_2 int F_95 ( struct V_1 * V_2 ,
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
V_110 = F_89 ( V_21 , V_128 ) ;
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
F_67 ( V_91 ) ;
return - V_75 ;
}
while ( V_124 < V_125 ) {
if ( V_126 ) {
V_5 = F_91 ( V_21 , V_124 , & V_101 , & V_94 ,
& V_111 , & V_110 ) ;
if ( ! V_91 )
V_91 = F_48 ( V_4 , V_110 ) ;
if ( ! V_91 )
return - V_18 ;
} else {
V_5 = F_93 ( V_21 , V_124 , & V_101 , & V_94 ,
& V_111 ) ;
}
if ( V_5 )
return V_5 ;
if ( ! F_74 ( V_4 , V_32 , F_50 ( V_91 ) , F_50 ( V_68 ) ,
V_111 , V_94 , V_101 ) ) {
if ( ! V_112 ) {
V_5 = F_84 ( V_2 , V_4 , V_32 , log ,
V_91 , V_68 , V_21 ,
V_109 ,
V_110 ,
V_111 , V_94 , V_101 ,
& V_112 ) ;
if ( V_5 == 1 )
goto V_74;
F_52 ( V_5 ) ;
}
V_5 = F_96 ( V_2 , V_91 , V_68 , V_94 , V_101 ,
0 , V_111 ) ;
F_52 ( V_5 ) ;
F_66 ( V_2 , V_4 , V_68 ) ;
}
V_124 = ( unsigned long ) ( V_124 + V_127 ) + V_101 ;
F_25 ( V_94 ) ;
if ( V_126 ) {
F_67 ( V_91 ) ;
V_91 = NULL ;
}
}
V_5 = F_19 ( V_2 , V_4 , V_32 , V_21 , V_33 , V_35 ) ;
F_52 ( V_5 ) ;
V_74:
F_23 ( V_32 ) ;
F_67 ( V_91 ) ;
F_67 ( V_68 ) ;
return 0 ;
}
static int F_97 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_1 V_66 )
{
int V_5 ;
V_5 = F_98 ( V_4 , V_66 ) ;
if ( V_5 > 0 )
V_5 = F_99 ( V_2 , V_4 , V_66 ) ;
return V_5 ;
}
static int F_100 ( struct V_3 * V_4 ,
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
V_5 = F_101 ( V_4 , V_109 , V_66 , V_32 ,
& V_117 , & V_66 ) ;
if ( V_5 )
break;
V_79 = V_32 -> V_50 [ 0 ] ;
V_36 = F_20 ( V_79 , V_32 -> V_51 [ 0 ] ) ;
V_104 = F_21 ( V_79 , V_32 -> V_51 [ 0 ] ) ;
while ( V_121 < V_36 ) {
V_117 = (struct V_116 * ) ( V_104 + V_121 ) ;
V_95 = F_88 ( V_79 , V_117 ) ;
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
static int F_102 ( struct V_3 * V_4 ,
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
F_103 ( V_32 -> V_50 [ 0 ] , & V_35 ,
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
V_95 = F_81 ( V_32 -> V_50 [ 0 ] ,
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
static T_2 int F_104 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_68 * V_68 )
{
struct V_31 * V_32 ;
int V_5 ;
T_1 V_129 = 0 ;
T_1 V_130 = F_50 ( V_68 ) ;
V_32 = F_79 () ;
if ( ! V_32 )
return - V_54 ;
V_5 = F_102 ( V_4 , V_68 , V_32 ) ;
if ( V_5 < 0 )
goto V_74;
V_129 = V_5 ;
V_5 = F_100 ( V_4 , V_68 , V_32 ) ;
if ( V_5 == - V_18 )
V_5 = 0 ;
if ( V_5 < 0 )
goto V_74;
V_129 += V_5 ;
V_5 = 0 ;
if ( V_129 != V_68 -> V_131 ) {
F_105 ( V_68 , V_129 ) ;
F_66 ( V_2 , V_4 , V_68 ) ;
}
F_106 ( V_68 ) -> V_132 = ( T_1 ) - 1 ;
if ( V_68 -> V_131 == 0 ) {
if ( F_34 ( V_68 -> V_133 ) ) {
V_5 = F_107 ( V_2 , V_4 , NULL , V_32 ,
V_130 , 1 ) ;
F_52 ( V_5 ) ;
}
V_5 = F_97 ( V_2 , V_4 , V_130 ) ;
F_52 ( V_5 ) ;
}
V_74:
F_83 ( V_32 ) ;
return V_5 ;
}
static T_2 int F_108 ( struct V_1 * V_2 ,
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
F_103 ( V_32 -> V_50 [ 0 ] , & V_35 , V_32 -> V_51 [ 0 ] ) ;
if ( V_35 . V_45 != V_134 ||
V_35 . type != V_135 )
break;
V_5 = F_109 ( V_2 , V_4 , V_32 ) ;
if ( V_5 )
goto V_74;
F_23 ( V_32 ) ;
V_68 = F_48 ( V_4 , V_35 . V_66 ) ;
if ( ! V_68 )
return - V_75 ;
V_5 = F_104 ( V_2 , V_4 , V_68 ) ;
F_52 ( V_5 ) ;
F_67 ( V_68 ) ;
V_35 . V_66 = ( T_1 ) - 1 ;
}
V_5 = 0 ;
V_74:
F_23 ( V_32 ) ;
return V_5 ;
}
static T_2 int F_71 ( struct V_1 * V_2 ,
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
F_110 ( & V_35 , V_135 ) ;
V_35 . V_66 = V_45 ;
V_5 = F_30 ( V_2 , V_4 , V_32 , & V_35 , 0 ) ;
F_23 ( V_32 ) ;
if ( V_5 == 0 ) {
if ( ! V_68 -> V_131 )
F_105 ( V_68 , 1 ) ;
else
F_85 ( V_68 ) ;
V_5 = F_66 ( V_2 , V_4 , V_68 ) ;
} else if ( V_5 == - V_58 ) {
V_5 = 0 ;
} else {
F_111 () ;
}
F_67 ( V_68 ) ;
return V_5 ;
}
static T_2 int F_112 ( struct V_1 * V_2 ,
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
F_67 ( V_68 ) ;
return - V_75 ;
}
V_5 = F_96 ( V_2 , V_91 , V_68 , V_94 , V_95 , 1 , V_98 ) ;
F_67 ( V_68 ) ;
F_67 ( V_91 ) ;
return V_5 ;
}
static T_2 int F_113 ( struct V_1 * V_2 ,
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
int V_5 ;
V_91 = F_48 ( V_4 , V_35 -> V_45 ) ;
if ( ! V_91 )
return - V_75 ;
V_95 = F_70 ( V_21 , V_93 ) ;
V_94 = F_24 ( V_95 , V_53 ) ;
if ( ! V_94 )
return - V_54 ;
V_139 = F_114 ( V_21 , V_93 ) ;
F_26 ( V_21 , V_94 , ( unsigned long ) ( V_93 + 1 ) ,
V_95 ) ;
F_69 ( V_21 , V_93 , & V_138 ) ;
V_140 = F_115 ( V_2 , V_4 , V_32 , & V_138 , 0 ) ;
if ( V_140 == 0 )
V_140 = 1 ;
else
V_140 = 0 ;
F_23 ( V_32 ) ;
if ( V_35 -> type == V_141 ) {
V_136 = F_77 ( V_2 , V_4 , V_32 , V_35 -> V_45 ,
V_94 , V_95 , 1 ) ;
} else if ( V_35 -> type == V_142 ) {
V_136 = F_75 ( V_2 , V_4 , V_32 ,
V_35 -> V_45 ,
V_35 -> V_66 , V_94 ,
V_95 , 1 ) ;
} else {
F_111 () ;
}
if ( F_87 ( V_136 ) ) {
if ( V_35 -> type != V_142 )
goto V_74;
goto V_52;
}
F_69 ( V_32 -> V_50 [ 0 ] , V_136 , & V_137 ) ;
if ( V_137 . V_45 == V_138 . V_45 &&
V_137 . type == V_138 . type &&
V_137 . V_66 == V_138 . V_66 &&
F_114 ( V_32 -> V_50 [ 0 ] , V_136 ) == V_139 ) {
goto V_74;
}
if ( ! V_140 )
goto V_74;
V_5 = F_68 ( V_2 , V_4 , V_32 , V_91 , V_136 ) ;
F_52 ( V_5 ) ;
if ( V_35 -> type == V_142 )
goto V_52;
V_74:
F_23 ( V_32 ) ;
F_25 ( V_94 ) ;
F_67 ( V_91 ) ;
return 0 ;
V_52:
F_23 ( V_32 ) ;
V_5 = F_112 ( V_2 , V_4 , V_32 , V_35 -> V_45 , V_35 -> V_66 ,
V_94 , V_95 , V_139 , & V_138 ) ;
F_52 ( V_5 && V_5 != - V_18 ) ;
goto V_74;
}
static T_2 int F_116 ( struct V_1 * V_2 ,
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
if ( F_117 ( V_4 , V_21 , V_93 ) )
return - V_75 ;
V_95 = F_70 ( V_21 , V_93 ) ;
V_5 = F_113 ( V_2 , V_4 , V_32 , V_21 , V_93 , V_35 ) ;
F_52 ( V_5 ) ;
V_104 = ( unsigned long ) ( V_93 + 1 ) ;
V_104 += V_95 ;
}
return 0 ;
}
static T_2 int F_118 ( struct V_3 * V_4 ,
struct V_31 * V_32 ,
T_1 V_97 , int V_143 ,
T_1 * V_144 , T_1 * V_145 )
{
struct V_34 V_35 ;
T_1 V_146 ;
struct V_147 * V_56 ;
int V_5 ;
int V_148 ;
if ( * V_144 == ( T_1 ) - 1 )
return 1 ;
V_35 . V_45 = V_97 ;
V_35 . type = V_143 ;
V_35 . V_66 = * V_144 ;
V_5 = F_22 ( NULL , V_4 , & V_35 , V_32 , 0 , 0 ) ;
if ( V_5 < 0 )
goto V_74;
if ( V_5 > 0 ) {
if ( V_32 -> V_51 [ 0 ] == 0 )
goto V_74;
V_32 -> V_51 [ 0 ] -- ;
}
if ( V_5 != 0 )
F_103 ( V_32 -> V_50 [ 0 ] , & V_35 , V_32 -> V_51 [ 0 ] ) ;
if ( V_35 . type != V_143 || V_35 . V_45 != V_97 ) {
V_5 = 1 ;
goto V_88;
}
V_56 = F_27 ( V_32 -> V_50 [ 0 ] , V_32 -> V_51 [ 0 ] ,
struct V_147 ) ;
V_146 = F_119 ( V_32 -> V_50 [ 0 ] , V_56 ) ;
if ( * V_144 >= V_35 . V_66 && * V_144 <= V_146 ) {
V_5 = 0 ;
* V_144 = V_35 . V_66 ;
* V_145 = V_146 ;
goto V_74;
}
V_5 = 1 ;
V_88:
V_148 = F_120 ( V_32 -> V_50 [ 0 ] ) ;
if ( V_32 -> V_51 [ 0 ] >= V_148 ) {
V_5 = F_121 ( V_4 , V_32 ) ;
if ( V_5 )
goto V_74;
} else {
V_32 -> V_51 [ 0 ] ++ ;
}
F_103 ( V_32 -> V_50 [ 0 ] , & V_35 , V_32 -> V_51 [ 0 ] ) ;
if ( V_35 . type != V_143 || V_35 . V_45 != V_97 ) {
V_5 = 1 ;
goto V_74;
}
V_56 = F_27 ( V_32 -> V_50 [ 0 ] , V_32 -> V_51 [ 0 ] ,
struct V_147 ) ;
V_146 = F_119 ( V_32 -> V_50 [ 0 ] , V_56 ) ;
* V_144 = V_35 . V_66 ;
* V_145 = V_146 ;
V_5 = 0 ;
V_74:
F_23 ( V_32 ) ;
return V_5 ;
}
static T_2 int F_122 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_3 * log ,
struct V_31 * V_32 ,
struct V_31 * V_149 ,
struct V_68 * V_91 ,
struct V_34 * V_150 )
{
int V_5 ;
struct V_20 * V_21 ;
int V_33 ;
T_3 V_36 ;
struct V_92 * V_93 ;
struct V_92 * V_151 ;
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
if ( F_117 ( V_4 , V_21 , V_93 ) ) {
V_5 = - V_75 ;
goto V_74;
}
V_95 = F_70 ( V_21 , V_93 ) ;
V_94 = F_24 ( V_95 , V_53 ) ;
if ( ! V_94 ) {
V_5 = - V_54 ;
goto V_74;
}
F_26 ( V_21 , V_94 , ( unsigned long ) ( V_93 + 1 ) ,
V_95 ) ;
V_151 = NULL ;
if ( log && V_150 -> type == V_141 ) {
V_151 = F_77 ( V_2 , log , V_149 ,
V_150 -> V_45 ,
V_94 , V_95 , 0 ) ;
} else if ( log && V_150 -> type == V_142 ) {
V_151 = F_75 ( V_2 , log ,
V_149 ,
V_150 -> V_45 ,
V_150 -> V_66 ,
V_94 , V_95 , 0 ) ;
}
if ( F_87 ( V_151 ) ) {
F_69 ( V_21 , V_93 , & V_96 ) ;
F_23 ( V_32 ) ;
F_23 ( V_149 ) ;
V_68 = F_48 ( V_4 , V_96 . V_45 ) ;
if ( ! V_68 ) {
F_25 ( V_94 ) ;
return - V_75 ;
}
V_5 = F_71 ( V_2 , V_4 ,
V_32 , V_96 . V_45 ) ;
F_52 ( V_5 ) ;
F_85 ( V_68 ) ;
V_5 = F_72 ( V_2 , V_4 , V_91 , V_68 ,
V_94 , V_95 ) ;
F_52 ( V_5 ) ;
F_73 ( V_2 , V_4 ) ;
F_25 ( V_94 ) ;
F_67 ( V_68 ) ;
V_5 = F_22 ( NULL , V_4 , V_150 , V_32 ,
0 , 0 ) ;
if ( V_5 == 0 )
goto V_118;
V_5 = 0 ;
goto V_74;
}
F_23 ( V_149 ) ;
F_25 ( V_94 ) ;
V_104 = ( unsigned long ) ( V_93 + 1 ) ;
V_104 += V_95 ;
}
V_5 = 0 ;
V_74:
F_23 ( V_32 ) ;
F_23 ( V_149 ) ;
return V_5 ;
}
static T_2 int F_107 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_3 * log ,
struct V_31 * V_32 ,
T_1 V_97 , int V_152 )
{
T_1 V_153 ;
T_1 V_154 ;
int V_143 = V_155 ;
int V_5 = 0 ;
struct V_34 V_150 ;
struct V_34 V_137 ;
struct V_31 * V_149 ;
struct V_68 * V_91 ;
V_150 . V_45 = V_97 ;
V_150 . type = V_141 ;
V_149 = F_79 () ;
if ( ! V_149 )
return - V_54 ;
V_91 = F_48 ( V_4 , V_97 ) ;
if ( ! V_91 ) {
F_83 ( V_149 ) ;
return 0 ;
}
V_118:
V_153 = 0 ;
V_154 = 0 ;
while ( 1 ) {
if ( V_152 )
V_154 = ( T_1 ) - 1 ;
else {
V_5 = F_118 ( log , V_32 , V_97 , V_143 ,
& V_153 , & V_154 ) ;
if ( V_5 != 0 )
break;
}
V_150 . V_66 = V_153 ;
while ( 1 ) {
int V_148 ;
V_5 = F_22 ( NULL , V_4 , & V_150 , V_32 ,
0 , 0 ) ;
if ( V_5 < 0 )
goto V_74;
V_148 = F_120 ( V_32 -> V_50 [ 0 ] ) ;
if ( V_32 -> V_51 [ 0 ] >= V_148 ) {
V_5 = F_121 ( V_4 , V_32 ) ;
if ( V_5 )
break;
}
F_103 ( V_32 -> V_50 [ 0 ] , & V_137 ,
V_32 -> V_51 [ 0 ] ) ;
if ( V_137 . V_45 != V_97 ||
V_137 . type != V_150 . type )
goto V_156;
if ( V_137 . V_66 > V_154 )
break;
V_5 = F_122 ( V_2 , V_4 , log , V_32 ,
V_149 , V_91 ,
& V_137 ) ;
F_52 ( V_5 ) ;
if ( V_137 . V_66 == ( T_1 ) - 1 )
break;
V_150 . V_66 = V_137 . V_66 + 1 ;
}
F_23 ( V_32 ) ;
if ( V_154 == ( T_1 ) - 1 )
break;
V_153 = V_154 + 1 ;
}
V_156:
V_5 = 0 ;
if ( V_143 == V_155 ) {
V_143 = V_157 ;
V_150 . type = V_142 ;
F_23 ( V_32 ) ;
goto V_118;
}
V_74:
F_23 ( V_32 ) ;
F_83 ( V_149 ) ;
F_67 ( V_91 ) ;
return V_5 ;
}
static int F_123 ( struct V_3 * log , struct V_20 * V_21 ,
struct V_22 * V_23 , T_1 V_24 )
{
int V_148 ;
struct V_31 * V_32 ;
struct V_3 * V_4 = V_23 -> V_158 ;
struct V_34 V_35 ;
int V_159 ;
int V_160 ;
int V_5 ;
V_5 = F_124 ( V_21 , V_24 ) ;
if ( V_5 )
return V_5 ;
V_159 = F_125 ( V_21 ) ;
if ( V_159 != 0 )
return 0 ;
V_32 = F_79 () ;
if ( ! V_32 )
return - V_54 ;
V_148 = F_120 ( V_21 ) ;
for ( V_160 = 0 ; V_160 < V_148 ; V_160 ++ ) {
F_103 ( V_21 , & V_35 , V_160 ) ;
if ( V_35 . type == V_43 &&
V_23 -> V_161 == V_162 ) {
struct V_55 * V_42 ;
T_3 V_163 ;
V_42 = F_27 ( V_21 , V_160 ,
struct V_55 ) ;
V_163 = F_35 ( V_21 , V_42 ) ;
if ( F_34 ( V_163 ) ) {
V_5 = F_107 ( V_23 -> V_2 ,
V_4 , log , V_32 , V_35 . V_45 , 0 ) ;
F_52 ( V_5 ) ;
}
V_5 = F_19 ( V_23 -> V_2 , V_4 , V_32 ,
V_21 , V_160 , & V_35 ) ;
F_52 ( V_5 ) ;
if ( F_126 ( V_163 ) ) {
V_5 = F_97 ( V_23 -> V_2 , V_4 ,
V_35 . V_45 ) ;
F_52 ( V_5 ) ;
}
V_5 = F_71 ( V_23 -> V_2 , V_4 ,
V_32 , V_35 . V_45 ) ;
F_52 ( V_5 ) ;
}
if ( V_23 -> V_161 < V_164 )
continue;
if ( V_35 . type == V_165 ) {
V_5 = F_19 ( V_23 -> V_2 , V_4 , V_32 ,
V_21 , V_160 , & V_35 ) ;
F_52 ( V_5 ) ;
} else if ( V_35 . type == V_119 ) {
V_5 = F_95 ( V_23 -> V_2 , V_4 , log , V_32 ,
V_21 , V_160 , & V_35 ) ;
F_52 ( V_5 && V_5 != - V_18 ) ;
} else if ( V_35 . type == V_108 ) {
V_5 = F_95 ( V_23 -> V_2 , V_4 , log , V_32 ,
V_21 , V_160 , & V_35 ) ;
F_52 ( V_5 && V_5 != - V_18 ) ;
} else if ( V_35 . type == V_166 ) {
V_5 = F_41 ( V_23 -> V_2 , V_4 , V_32 ,
V_21 , V_160 , & V_35 ) ;
F_52 ( V_5 ) ;
} else if ( V_35 . type == V_141 ||
V_35 . type == V_142 ) {
V_5 = F_116 ( V_23 -> V_2 , V_4 , V_32 ,
V_21 , V_160 , & V_35 ) ;
F_52 ( V_5 ) ;
}
}
F_83 ( V_32 ) ;
return 0 ;
}
static T_2 int F_127 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_31 * V_32 , int * V_159 ,
struct V_22 * V_23 )
{
T_1 V_167 ;
T_1 V_168 ;
T_1 V_169 ;
struct V_20 * V_88 ;
struct V_20 * V_170 ;
struct V_20 * V_171 ;
T_3 V_172 ;
int V_5 = 0 ;
F_128 ( * V_159 < 0 ) ;
F_128 ( * V_159 >= V_173 ) ;
while ( * V_159 > 0 ) {
F_128 ( * V_159 < 0 ) ;
F_128 ( * V_159 >= V_173 ) ;
V_170 = V_32 -> V_50 [ * V_159 ] ;
if ( F_125 ( V_170 ) != * V_159 )
F_128 ( 1 ) ;
if ( V_32 -> V_51 [ * V_159 ] >=
F_120 ( V_170 ) )
break;
V_168 = F_129 ( V_170 , V_32 -> V_51 [ * V_159 ] ) ;
V_169 = F_130 ( V_170 , V_32 -> V_51 [ * V_159 ] ) ;
V_172 = F_131 ( V_4 , * V_159 - 1 ) ;
V_171 = V_32 -> V_50 [ * V_159 ] ;
V_167 = F_132 ( V_171 ) ;
V_88 = F_133 ( V_4 , V_168 , V_172 ) ;
if ( ! V_88 )
return - V_54 ;
if ( * V_159 == 1 ) {
V_5 = V_23 -> V_174 ( V_4 , V_88 , V_23 , V_169 ) ;
if ( V_5 )
return V_5 ;
V_32 -> V_51 [ * V_159 ] ++ ;
if ( V_23 -> free ) {
V_5 = F_124 ( V_88 , V_169 ) ;
if ( V_5 ) {
F_134 ( V_88 ) ;
return V_5 ;
}
F_135 ( V_88 ) ;
F_136 ( V_88 ) ;
F_137 ( V_2 , V_4 , V_88 ) ;
F_18 ( V_88 ) ;
F_138 ( V_88 ) ;
F_128 ( V_167 !=
V_46 ) ;
V_5 = F_139 ( V_4 ,
V_168 , V_172 ) ;
F_52 ( V_5 ) ;
}
F_134 ( V_88 ) ;
continue;
}
V_5 = F_124 ( V_88 , V_169 ) ;
if ( V_5 ) {
F_134 ( V_88 ) ;
return V_5 ;
}
F_128 ( * V_159 <= 0 ) ;
if ( V_32 -> V_50 [ * V_159 - 1 ] )
F_134 ( V_32 -> V_50 [ * V_159 - 1 ] ) ;
V_32 -> V_50 [ * V_159 - 1 ] = V_88 ;
* V_159 = F_125 ( V_88 ) ;
V_32 -> V_51 [ * V_159 ] = 0 ;
F_140 () ;
}
F_128 ( * V_159 < 0 ) ;
F_128 ( * V_159 >= V_173 ) ;
V_32 -> V_51 [ * V_159 ] = F_120 ( V_32 -> V_50 [ * V_159 ] ) ;
F_140 () ;
return 0 ;
}
static T_2 int F_141 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_31 * V_32 , int * V_159 ,
struct V_22 * V_23 )
{
T_1 V_167 ;
int V_160 ;
int V_33 ;
int V_5 ;
for ( V_160 = * V_159 ; V_160 < V_173 - 1 && V_32 -> V_50 [ V_160 ] ; V_160 ++ ) {
V_33 = V_32 -> V_51 [ V_160 ] ;
if ( V_33 + 1 < F_120 ( V_32 -> V_50 [ V_160 ] ) ) {
V_32 -> V_51 [ V_160 ] ++ ;
* V_159 = V_160 ;
F_128 ( * V_159 == 0 ) ;
return 0 ;
} else {
struct V_20 * V_171 ;
if ( V_32 -> V_50 [ * V_159 ] == V_4 -> V_175 )
V_171 = V_32 -> V_50 [ * V_159 ] ;
else
V_171 = V_32 -> V_50 [ * V_159 + 1 ] ;
V_167 = F_132 ( V_171 ) ;
V_5 = V_23 -> V_174 ( V_4 , V_32 -> V_50 [ * V_159 ] , V_23 ,
F_142 ( V_32 -> V_50 [ * V_159 ] ) ) ;
if ( V_5 )
return V_5 ;
if ( V_23 -> free ) {
struct V_20 * V_88 ;
V_88 = V_32 -> V_50 [ * V_159 ] ;
F_135 ( V_88 ) ;
F_136 ( V_88 ) ;
F_137 ( V_2 , V_4 , V_88 ) ;
F_18 ( V_88 ) ;
F_138 ( V_88 ) ;
F_128 ( V_167 != V_46 ) ;
V_5 = F_139 ( V_4 ,
V_32 -> V_50 [ * V_159 ] -> V_27 ,
V_32 -> V_50 [ * V_159 ] -> V_28 ) ;
F_52 ( V_5 ) ;
}
F_134 ( V_32 -> V_50 [ * V_159 ] ) ;
V_32 -> V_50 [ * V_159 ] = NULL ;
* V_159 = V_160 + 1 ;
}
}
return 1 ;
}
static int F_143 ( struct V_1 * V_2 ,
struct V_3 * log , struct V_22 * V_23 )
{
int V_5 = 0 ;
int V_176 ;
int V_159 ;
struct V_31 * V_32 ;
int V_160 ;
int V_177 ;
V_32 = F_79 () ;
if ( ! V_32 )
return - V_54 ;
V_159 = F_125 ( log -> V_175 ) ;
V_177 = V_159 ;
V_32 -> V_50 [ V_159 ] = log -> V_175 ;
F_144 ( log -> V_175 ) ;
V_32 -> V_51 [ V_159 ] = 0 ;
while ( 1 ) {
V_176 = F_127 ( V_2 , log , V_32 , & V_159 , V_23 ) ;
if ( V_176 > 0 )
break;
if ( V_176 < 0 ) {
V_5 = V_176 ;
goto V_74;
}
V_176 = F_141 ( V_2 , log , V_32 , & V_159 , V_23 ) ;
if ( V_176 > 0 )
break;
if ( V_176 < 0 ) {
V_5 = V_176 ;
goto V_74;
}
}
if ( V_32 -> V_50 [ V_177 ] ) {
V_5 = V_23 -> V_174 ( log , V_32 -> V_50 [ V_177 ] , V_23 ,
F_142 ( V_32 -> V_50 [ V_177 ] ) ) ;
if ( V_5 )
goto V_74;
if ( V_23 -> free ) {
struct V_20 * V_88 ;
V_88 = V_32 -> V_50 [ V_177 ] ;
F_135 ( V_88 ) ;
F_136 ( V_88 ) ;
F_137 ( V_2 , log , V_88 ) ;
F_18 ( V_88 ) ;
F_138 ( V_88 ) ;
F_128 ( log -> V_44 . V_45 !=
V_46 ) ;
V_5 = F_139 ( log , V_88 -> V_27 ,
V_88 -> V_28 ) ;
F_52 ( V_5 ) ;
}
}
V_74:
for ( V_160 = 0 ; V_160 <= V_177 ; V_160 ++ ) {
if ( V_32 -> V_50 [ V_160 ] ) {
F_134 ( V_32 -> V_50 [ V_160 ] ) ;
V_32 -> V_50 [ V_160 ] = NULL ;
}
}
F_83 ( V_32 ) ;
return V_5 ;
}
static int F_145 ( struct V_1 * V_2 ,
struct V_3 * log )
{
int V_5 ;
if ( log -> V_178 == 1 ) {
V_5 = F_146 ( V_2 , log -> V_15 -> V_17 ,
& log -> V_44 , & log -> V_179 ) ;
} else {
V_5 = F_147 ( V_2 , log -> V_15 -> V_17 ,
& log -> V_44 , & log -> V_179 ) ;
}
return V_5 ;
}
static int F_148 ( struct V_1 * V_2 ,
struct V_3 * V_4 , unsigned long V_63 )
{
F_149 ( V_30 ) ;
int V_98 = V_63 % 2 ;
do {
F_150 ( & V_4 -> V_180 [ V_98 ] ,
& V_30 , V_181 ) ;
F_4 ( & V_4 -> V_7 ) ;
if ( V_4 -> V_15 -> V_182 !=
V_2 -> V_63 && V_4 -> V_178 < V_63 + 2 &&
F_151 ( & V_4 -> V_183 [ V_98 ] ) )
F_152 () ;
F_153 ( & V_4 -> V_180 [ V_98 ] , & V_30 ) ;
F_2 ( & V_4 -> V_7 ) ;
} while ( V_4 -> V_15 -> V_182 !=
V_2 -> V_63 && V_4 -> V_178 < V_63 + 2 &&
F_151 ( & V_4 -> V_183 [ V_98 ] ) );
return 0 ;
}
static void F_154 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_149 ( V_30 ) ;
while ( V_4 -> V_15 -> V_182 !=
V_2 -> V_63 && F_151 ( & V_4 -> V_14 ) ) {
F_150 ( & V_4 -> V_19 ,
& V_30 , V_181 ) ;
F_4 ( & V_4 -> V_7 ) ;
if ( V_4 -> V_15 -> V_182 !=
V_2 -> V_63 && F_151 ( & V_4 -> V_14 ) )
F_152 () ;
F_2 ( & V_4 -> V_7 ) ;
F_153 ( & V_4 -> V_19 , & V_30 ) ;
}
}
int F_155 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_184 ;
int V_185 ;
int V_186 ;
int V_5 ;
struct V_3 * log = V_4 -> V_8 ;
struct V_3 * V_17 = V_4 -> V_15 -> V_17 ;
unsigned long V_178 = 0 ;
F_2 ( & V_4 -> V_7 ) ;
V_178 = V_4 -> V_178 ;
V_184 = V_4 -> V_178 % 2 ;
if ( F_151 ( & V_4 -> V_183 [ V_184 ] ) ) {
F_148 ( V_2 , V_4 , V_4 -> V_178 ) ;
F_4 ( & V_4 -> V_7 ) ;
return 0 ;
}
F_156 ( & V_4 -> V_183 [ V_184 ] , 1 ) ;
if ( F_151 ( & V_4 -> V_183 [ ( V_184 + 1 ) % 2 ] ) )
F_148 ( V_2 , V_4 , V_4 -> V_178 - 1 ) ;
while ( 1 ) {
int V_187 = F_151 ( & V_4 -> V_13 ) ;
if ( ! F_157 ( V_4 , V_188 ) && V_4 -> V_12 ) {
F_4 ( & V_4 -> V_7 ) ;
F_158 ( 1 ) ;
F_2 ( & V_4 -> V_7 ) ;
}
F_154 ( V_2 , V_4 ) ;
if ( V_187 == F_151 ( & V_4 -> V_13 ) )
break;
}
if ( V_4 -> V_15 -> V_182 == V_2 -> V_63 ) {
V_5 = - V_189 ;
F_159 ( log , V_178 ) ;
F_4 ( & V_4 -> V_7 ) ;
goto V_74;
}
if ( V_178 % 2 == 0 )
V_186 = V_190 ;
else
V_186 = V_191 ;
V_5 = F_160 ( log , & log -> V_192 , V_186 ) ;
if ( V_5 ) {
F_161 ( V_2 , V_4 , V_5 ) ;
F_159 ( log , V_178 ) ;
F_4 ( & V_4 -> V_7 ) ;
goto V_74;
}
F_162 ( & log -> V_179 , log -> V_175 ) ;
V_4 -> V_178 ++ ;
log -> V_178 = V_4 -> V_178 ;
V_4 -> V_9 = 0 ;
F_8 () ;
F_4 ( & V_4 -> V_7 ) ;
F_2 ( & V_17 -> V_7 ) ;
F_3 ( & V_17 -> V_13 ) ;
F_3 ( & V_17 -> V_14 ) ;
F_4 ( & V_17 -> V_7 ) ;
V_5 = F_145 ( V_2 , log ) ;
F_2 ( & V_17 -> V_7 ) ;
if ( F_11 ( & V_17 -> V_14 ) ) {
F_8 () ;
if ( F_12 ( & V_17 -> V_19 ) )
F_13 ( & V_17 -> V_19 ) ;
}
if ( V_5 ) {
if ( V_5 != - V_193 ) {
F_161 ( V_2 , V_4 , V_5 ) ;
F_4 ( & V_17 -> V_7 ) ;
goto V_74;
}
V_4 -> V_15 -> V_182 = V_2 -> V_63 ;
F_163 ( log , & log -> V_192 , V_186 ) ;
F_159 ( log , V_178 ) ;
F_4 ( & V_17 -> V_7 ) ;
V_5 = - V_189 ;
goto V_74;
}
V_185 = V_17 -> V_178 % 2 ;
if ( F_151 ( & V_17 -> V_183 [ V_185 ] ) ) {
F_163 ( log , & log -> V_192 , V_186 ) ;
F_148 ( V_2 , V_17 ,
V_17 -> V_178 ) ;
F_159 ( log , V_178 ) ;
F_4 ( & V_17 -> V_7 ) ;
V_5 = 0 ;
goto V_74;
}
F_156 ( & V_17 -> V_183 [ V_185 ] , 1 ) ;
if ( F_151 ( & V_17 -> V_183 [ ( V_185 + 1 ) % 2 ] ) ) {
F_148 ( V_2 , V_17 ,
V_17 -> V_178 - 1 ) ;
}
F_154 ( V_2 , V_17 ) ;
if ( V_4 -> V_15 -> V_182 == V_2 -> V_63 ) {
F_163 ( log , & log -> V_192 , V_186 ) ;
F_159 ( log , V_178 ) ;
F_4 ( & V_17 -> V_7 ) ;
V_5 = - V_189 ;
goto V_194;
}
V_5 = F_164 ( V_17 ,
& V_17 -> V_192 ,
V_190 | V_191 ) ;
if ( V_5 ) {
F_161 ( V_2 , V_4 , V_5 ) ;
F_159 ( log , V_178 ) ;
F_4 ( & V_17 -> V_7 ) ;
goto V_194;
}
F_163 ( log , & log -> V_192 , V_186 ) ;
F_165 ( log , V_178 ) ;
F_166 ( V_4 -> V_15 -> V_195 ,
V_17 -> V_175 -> V_27 ) ;
F_167 ( V_4 -> V_15 -> V_195 ,
F_125 ( V_17 -> V_175 ) ) ;
V_17 -> V_178 ++ ;
F_8 () ;
F_4 ( & V_17 -> V_7 ) ;
F_168 ( V_4 ) ;
V_5 = F_169 ( V_2 , V_4 -> V_15 -> V_196 , 1 ) ;
F_170 ( V_4 ) ;
if ( V_5 ) {
F_161 ( V_2 , V_4 , V_5 ) ;
goto V_194;
}
F_2 ( & V_4 -> V_7 ) ;
if ( V_4 -> V_197 < V_178 )
V_4 -> V_197 = V_178 ;
F_4 ( & V_4 -> V_7 ) ;
V_194:
F_156 ( & V_17 -> V_183 [ V_185 ] , 0 ) ;
F_8 () ;
if ( F_12 ( & V_17 -> V_180 [ V_185 ] ) )
F_13 ( & V_17 -> V_180 [ V_185 ] ) ;
V_74:
F_156 ( & V_4 -> V_183 [ V_184 ] , 0 ) ;
F_8 () ;
if ( F_12 ( & V_4 -> V_180 [ V_184 ] ) )
F_13 ( & V_4 -> V_180 [ V_184 ] ) ;
return V_5 ;
}
static void F_171 ( struct V_1 * V_2 ,
struct V_3 * log )
{
int V_5 ;
T_1 V_27 ;
T_1 V_198 ;
struct V_22 V_23 = {
. free = 1 ,
. V_174 = F_14
} ;
if ( V_2 ) {
V_5 = F_143 ( V_2 , log , & V_23 ) ;
F_52 ( V_5 ) ;
}
while ( 1 ) {
V_5 = F_172 ( & log -> V_192 ,
0 , & V_27 , & V_198 , V_190 | V_191 ,
NULL ) ;
if ( V_5 )
break;
F_173 ( & log -> V_192 , V_27 , V_198 ,
V_190 | V_191 , V_53 ) ;
}
F_159 ( log , 0 ) ;
F_159 ( log , 1 ) ;
F_134 ( log -> V_175 ) ;
F_25 ( log ) ;
}
int F_174 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( V_4 -> V_8 ) {
F_171 ( V_2 , V_4 -> V_8 ) ;
V_4 -> V_8 = NULL ;
}
return 0 ;
}
int F_175 ( struct V_1 * V_2 ,
struct V_199 * V_15 )
{
if ( V_15 -> V_17 ) {
F_171 ( V_2 , V_15 -> V_17 ) ;
V_15 -> V_17 = NULL ;
}
return 0 ;
}
int F_176 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_94 , int V_95 ,
struct V_68 * V_91 , T_1 V_98 )
{
struct V_3 * log ;
struct V_92 * V_93 ;
struct V_31 * V_32 ;
int V_5 ;
int V_6 = 0 ;
int V_200 = 0 ;
T_1 V_201 = F_50 ( V_91 ) ;
if ( F_106 ( V_91 ) -> V_202 < V_2 -> V_63 )
return 0 ;
V_5 = F_7 ( V_4 ) ;
if ( V_5 )
return 0 ;
F_2 ( & F_106 ( V_91 ) -> V_7 ) ;
log = V_4 -> V_8 ;
V_32 = F_79 () ;
if ( ! V_32 ) {
V_6 = - V_54 ;
goto V_203;
}
V_93 = F_77 ( V_2 , log , V_32 , V_201 ,
V_94 , V_95 , - 1 ) ;
if ( F_76 ( V_93 ) ) {
V_6 = F_177 ( V_93 ) ;
goto V_204;
}
if ( V_93 ) {
V_5 = F_178 ( V_2 , log , V_32 , V_93 ) ;
V_200 += V_95 ;
F_52 ( V_5 ) ;
}
F_23 ( V_32 ) ;
V_93 = F_75 ( V_2 , log , V_32 , V_201 ,
V_98 , V_94 , V_95 , - 1 ) ;
if ( F_76 ( V_93 ) ) {
V_6 = F_177 ( V_93 ) ;
goto V_204;
}
if ( V_93 ) {
V_5 = F_178 ( V_2 , log , V_32 , V_93 ) ;
V_200 += V_95 ;
F_52 ( V_5 ) ;
}
if ( V_200 ) {
struct V_34 V_35 ;
V_35 . V_45 = V_201 ;
V_35 . V_66 = 0 ;
V_35 . type = V_43 ;
F_23 ( V_32 ) ;
V_5 = F_22 ( V_2 , log , & V_35 , V_32 , 0 , 1 ) ;
if ( V_5 < 0 ) {
V_6 = V_5 ;
goto V_204;
}
if ( V_5 == 0 ) {
struct V_55 * V_56 ;
T_1 V_205 ;
V_56 = F_27 ( V_32 -> V_50 [ 0 ] , V_32 -> V_51 [ 0 ] ,
struct V_55 ) ;
V_205 = F_36 ( V_32 -> V_50 [ 0 ] , V_56 ) ;
if ( V_205 > V_200 )
V_205 -= V_200 ;
else
V_205 = 0 ;
F_38 ( V_32 -> V_50 [ 0 ] , V_56 , V_205 ) ;
F_40 ( V_32 -> V_50 [ 0 ] ) ;
} else
V_5 = 0 ;
F_23 ( V_32 ) ;
}
V_204:
F_83 ( V_32 ) ;
V_203:
F_4 ( & F_106 ( V_91 ) -> V_7 ) ;
if ( V_5 == - V_193 ) {
V_4 -> V_15 -> V_182 = V_2 -> V_63 ;
V_5 = 0 ;
} else if ( V_5 < 0 )
F_161 ( V_2 , V_4 , V_5 ) ;
F_10 ( V_4 ) ;
return V_6 ;
}
int F_179 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_94 , int V_95 ,
struct V_68 * V_68 , T_1 V_97 )
{
struct V_3 * log ;
T_1 V_98 ;
int V_5 ;
if ( F_106 ( V_68 ) -> V_202 < V_2 -> V_63 )
return 0 ;
V_5 = F_7 ( V_4 ) ;
if ( V_5 )
return 0 ;
log = V_4 -> V_8 ;
F_2 ( & F_106 ( V_68 ) -> V_7 ) ;
V_5 = F_180 ( V_2 , log , V_94 , V_95 , F_50 ( V_68 ) ,
V_97 , & V_98 ) ;
F_4 ( & F_106 ( V_68 ) -> V_7 ) ;
if ( V_5 == - V_193 ) {
V_4 -> V_15 -> V_182 = V_2 -> V_63 ;
V_5 = 0 ;
} else if ( V_5 < 0 && V_5 != - V_18 )
F_161 ( V_2 , V_4 , V_5 ) ;
F_10 ( V_4 ) ;
return V_5 ;
}
static T_2 int F_181 ( struct V_1 * V_2 ,
struct V_3 * log ,
struct V_31 * V_32 ,
int V_143 , T_1 V_97 ,
T_1 V_206 , T_1 V_207 )
{
int V_5 ;
struct V_34 V_35 ;
struct V_147 * V_56 ;
V_35 . V_45 = V_97 ;
V_35 . V_66 = V_206 ;
if ( V_143 == V_141 )
V_35 . type = V_155 ;
else
V_35 . type = V_157 ;
V_5 = F_30 ( V_2 , log , V_32 , & V_35 , sizeof( * V_56 ) ) ;
if ( V_5 )
return V_5 ;
V_56 = F_27 ( V_32 -> V_50 [ 0 ] , V_32 -> V_51 [ 0 ] ,
struct V_147 ) ;
F_182 ( V_32 -> V_50 [ 0 ] , V_56 , V_207 ) ;
F_40 ( V_32 -> V_50 [ 0 ] ) ;
F_23 ( V_32 ) ;
return 0 ;
}
static T_2 int F_183 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_68 * V_68 ,
struct V_31 * V_32 ,
struct V_31 * V_208 , int V_143 ,
T_1 V_209 , T_1 * V_210 )
{
struct V_34 V_211 ;
struct V_34 V_212 ;
struct V_3 * log = V_4 -> V_8 ;
struct V_20 * V_213 ;
int V_6 = 0 ;
int V_5 ;
int V_160 ;
int V_148 ;
T_1 V_206 = V_209 ;
T_1 V_207 = ( T_1 ) - 1 ;
T_1 V_130 = F_50 ( V_68 ) ;
log = V_4 -> V_8 ;
V_212 . V_45 = V_130 ;
V_212 . V_66 = ( T_1 ) - 1 ;
V_212 . type = V_143 ;
V_211 . V_45 = V_130 ;
V_211 . type = V_143 ;
V_211 . V_66 = V_209 ;
V_32 -> V_214 = 1 ;
V_5 = F_184 ( V_4 , & V_211 , & V_212 ,
V_32 , V_2 -> V_63 ) ;
if ( V_5 != 0 || V_211 . V_45 != V_130 || V_211 . type != V_143 ) {
V_211 . V_45 = V_130 ;
V_211 . type = V_143 ;
V_211 . V_66 = ( T_1 ) - 1 ;
F_23 ( V_32 ) ;
V_5 = F_22 ( NULL , V_4 , & V_211 , V_32 , 0 , 0 ) ;
if ( V_5 < 0 ) {
F_23 ( V_32 ) ;
return V_5 ;
}
V_5 = F_185 ( V_4 , V_32 , V_130 , V_143 ) ;
if ( V_5 == 0 ) {
struct V_34 V_215 ;
F_103 ( V_32 -> V_50 [ 0 ] , & V_215 ,
V_32 -> V_51 [ 0 ] ) ;
if ( V_143 == V_215 . type )
V_206 = F_186 ( V_209 , V_215 . V_66 ) + 1 ;
}
goto V_216;
}
V_5 = F_185 ( V_4 , V_32 , V_130 , V_143 ) ;
if ( V_5 == 0 ) {
struct V_34 V_215 ;
F_103 ( V_32 -> V_50 [ 0 ] , & V_215 , V_32 -> V_51 [ 0 ] ) ;
if ( V_143 == V_215 . type ) {
V_206 = V_215 . V_66 ;
V_5 = F_19 ( V_2 , log , V_208 ,
V_32 -> V_50 [ 0 ] , V_32 -> V_51 [ 0 ] ,
& V_215 ) ;
if ( V_5 ) {
V_6 = V_5 ;
goto V_216;
}
}
}
F_23 ( V_32 ) ;
V_5 = F_22 ( NULL , V_4 , & V_211 , V_32 , 0 , 0 ) ;
if ( V_5 != 0 ) {
F_128 ( 1 ) ;
goto V_216;
}
while ( 1 ) {
struct V_34 V_215 ;
V_213 = V_32 -> V_50 [ 0 ] ;
V_148 = F_120 ( V_213 ) ;
for ( V_160 = V_32 -> V_51 [ 0 ] ; V_160 < V_148 ; V_160 ++ ) {
F_103 ( V_213 , & V_211 , V_160 ) ;
if ( V_211 . V_45 != V_130 || V_211 . type != V_143 )
goto V_216;
V_5 = F_19 ( V_2 , log , V_208 , V_213 , V_160 ,
& V_211 ) ;
if ( V_5 ) {
V_6 = V_5 ;
goto V_216;
}
}
V_32 -> V_51 [ 0 ] = V_148 ;
V_5 = F_121 ( V_4 , V_32 ) ;
if ( V_5 == 1 ) {
V_207 = ( T_1 ) - 1 ;
goto V_216;
}
F_103 ( V_32 -> V_50 [ 0 ] , & V_215 , V_32 -> V_51 [ 0 ] ) ;
if ( V_215 . V_45 != V_130 || V_215 . type != V_143 ) {
V_207 = ( T_1 ) - 1 ;
goto V_216;
}
if ( F_142 ( V_32 -> V_50 [ 0 ] ) != V_2 -> V_63 ) {
V_5 = F_19 ( V_2 , log , V_208 ,
V_32 -> V_50 [ 0 ] , V_32 -> V_51 [ 0 ] ,
& V_215 ) ;
if ( V_5 )
V_6 = V_5 ;
else
V_207 = V_215 . V_66 ;
goto V_216;
}
}
V_216:
F_23 ( V_32 ) ;
F_23 ( V_208 ) ;
if ( V_6 == 0 ) {
* V_210 = V_207 ;
V_5 = F_181 ( V_2 , log , V_32 , V_143 ,
V_130 , V_206 , V_207 ) ;
if ( V_5 )
V_6 = V_5 ;
}
return V_6 ;
}
static T_2 int F_187 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_68 * V_68 ,
struct V_31 * V_32 ,
struct V_31 * V_208 )
{
T_1 V_211 ;
T_1 V_212 ;
int V_5 ;
int V_143 = V_141 ;
V_118:
V_211 = 0 ;
V_212 = 0 ;
while ( 1 ) {
V_5 = F_183 ( V_2 , V_4 , V_68 , V_32 ,
V_208 , V_143 , V_211 ,
& V_212 ) ;
if ( V_5 )
return V_5 ;
if ( V_212 == ( T_1 ) - 1 )
break;
V_211 = V_212 + 1 ;
}
if ( V_143 == V_141 ) {
V_143 = V_142 ;
goto V_118;
}
return 0 ;
}
static int F_188 ( struct V_1 * V_2 ,
struct V_3 * log ,
struct V_31 * V_32 ,
T_1 V_45 , int V_217 )
{
int V_5 ;
struct V_34 V_35 ;
struct V_34 V_137 ;
int V_218 ;
V_35 . V_45 = V_45 ;
V_35 . type = V_217 ;
V_35 . V_66 = ( T_1 ) - 1 ;
while ( 1 ) {
V_5 = F_22 ( V_2 , log , & V_35 , V_32 , - 1 , 1 ) ;
F_52 ( V_5 == 0 ) ;
if ( V_5 < 0 )
break;
if ( V_32 -> V_51 [ 0 ] == 0 )
break;
V_32 -> V_51 [ 0 ] -- ;
F_103 ( V_32 -> V_50 [ 0 ] , & V_137 ,
V_32 -> V_51 [ 0 ] ) ;
if ( V_137 . V_45 != V_45 )
break;
V_137 . V_66 = 0 ;
V_137 . type = 0 ;
V_5 = F_189 ( V_32 -> V_50 [ 0 ] , & V_137 , 0 ,
& V_218 ) ;
V_5 = F_190 ( V_2 , log , V_32 , V_218 ,
V_32 -> V_51 [ 0 ] - V_218 + 1 ) ;
if ( V_5 || V_218 != 0 )
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
struct V_68 * V_68 , int V_219 )
{
struct V_220 V_221 ;
F_192 ( & V_221 ) ;
if ( V_219 ) {
F_193 ( V_79 , V_56 , 0 , & V_221 ) ;
F_194 ( V_79 , V_56 , 0 , & V_221 ) ;
} else {
F_193 ( V_79 , V_56 ,
F_106 ( V_68 ) -> V_222 ,
& V_221 ) ;
F_194 ( V_79 , V_56 , V_68 -> V_205 , & V_221 ) ;
}
F_195 ( V_79 , V_56 , F_196 ( V_68 ) , & V_221 ) ;
F_197 ( V_79 , V_56 , F_198 ( V_68 ) , & V_221 ) ;
F_199 ( V_79 , V_56 , V_68 -> V_133 , & V_221 ) ;
F_200 ( V_79 , V_56 , V_68 -> V_131 , & V_221 ) ;
F_201 ( V_79 , F_202 ( V_56 ) ,
V_68 -> V_223 . V_224 , & V_221 ) ;
F_203 ( V_79 , F_202 ( V_56 ) ,
V_68 -> V_223 . V_225 , & V_221 ) ;
F_201 ( V_79 , F_204 ( V_56 ) ,
V_68 -> V_226 . V_224 , & V_221 ) ;
F_203 ( V_79 , F_204 ( V_56 ) ,
V_68 -> V_226 . V_225 , & V_221 ) ;
F_201 ( V_79 , F_205 ( V_56 ) ,
V_68 -> V_227 . V_224 , & V_221 ) ;
F_203 ( V_79 , F_205 ( V_56 ) ,
V_68 -> V_227 . V_225 , & V_221 ) ;
F_206 ( V_79 , V_56 , F_207 ( V_68 ) ,
& V_221 ) ;
F_208 ( V_79 , V_56 , V_68 -> V_228 , & V_221 ) ;
F_209 ( V_79 , V_56 , V_2 -> V_63 , & V_221 ) ;
F_210 ( V_79 , V_56 , V_68 -> V_229 , & V_221 ) ;
F_211 ( V_79 , V_56 , F_106 ( V_68 ) -> V_230 , & V_221 ) ;
F_212 ( V_79 , V_56 , 0 , & V_221 ) ;
}
static int F_213 ( struct V_1 * V_2 ,
struct V_3 * log , struct V_31 * V_32 ,
struct V_68 * V_68 )
{
struct V_55 * V_42 ;
struct V_34 V_35 ;
int V_5 ;
memcpy ( & V_35 , & F_106 ( V_68 ) -> V_96 , sizeof( V_35 ) ) ;
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
struct V_31 * V_208 ,
struct V_20 * V_213 ,
int V_218 , int V_231 , int V_232 )
{
unsigned long V_233 ;
unsigned long V_234 ;
struct V_3 * log = F_106 ( V_68 ) -> V_4 -> V_8 ;
struct V_67 * V_235 ;
struct V_55 * V_42 ;
int V_5 ;
struct V_34 * V_236 ;
T_3 * V_237 ;
char * V_238 ;
int V_160 ;
struct V_239 V_85 ;
int V_240 = F_106 ( V_68 ) -> V_230 & V_241 ;
F_215 ( & V_85 ) ;
V_238 = F_24 ( V_231 * sizeof( struct V_34 ) +
V_231 * sizeof( T_3 ) , V_53 ) ;
if ( ! V_238 )
return - V_54 ;
V_237 = ( T_3 * ) V_238 ;
V_236 = (struct V_34 * ) ( V_238 + V_231 * sizeof( T_3 ) ) ;
for ( V_160 = 0 ; V_160 < V_231 ; V_160 ++ ) {
V_237 [ V_160 ] = F_20 ( V_213 , V_160 + V_218 ) ;
F_103 ( V_213 , V_236 + V_160 , V_160 + V_218 ) ;
}
V_5 = F_216 ( V_2 , log , V_208 ,
V_236 , V_237 , V_231 ) ;
if ( V_5 ) {
F_25 ( V_238 ) ;
return V_5 ;
}
for ( V_160 = 0 ; V_160 < V_231 ; V_160 ++ , V_208 -> V_51 [ 0 ] ++ ) {
V_234 = F_21 ( V_208 -> V_50 [ 0 ] ,
V_208 -> V_51 [ 0 ] ) ;
V_233 = F_21 ( V_213 , V_218 + V_160 ) ;
if ( V_236 [ V_160 ] . type == V_43 ) {
V_42 = F_27 ( V_208 -> V_50 [ 0 ] ,
V_208 -> V_51 [ 0 ] ,
struct V_55 ) ;
F_191 ( V_2 , V_208 -> V_50 [ 0 ] , V_42 ,
V_68 , V_232 == V_242 ) ;
} else {
F_37 ( V_208 -> V_50 [ 0 ] , V_213 , V_234 ,
V_233 , V_237 [ V_160 ] ) ;
}
if ( F_217 ( V_236 + V_160 ) == V_166 &&
! V_240 ) {
int V_64 ;
V_235 = F_27 ( V_213 , V_218 + V_160 ,
struct V_67 ) ;
if ( F_218 ( V_213 , V_235 ) < V_2 -> V_63 )
continue;
V_64 = F_42 ( V_213 , V_235 ) ;
if ( V_64 == V_70 ) {
T_1 V_243 , V_244 , V_245 , V_246 ;
V_243 = F_44 ( V_213 ,
V_235 ) ;
if ( V_243 == 0 )
continue;
V_244 = F_53 ( V_213 ,
V_235 ) ;
V_245 = F_54 ( V_213 , V_235 ) ;
V_246 = F_43 ( V_213 ,
V_235 ) ;
if ( F_59 ( V_213 ,
V_235 ) ) {
V_245 = 0 ;
V_246 = V_244 ;
}
V_5 = F_60 (
log -> V_15 -> V_90 ,
V_243 + V_245 , V_243 + V_245 + V_246 - 1 ,
& V_85 , 0 ) ;
F_52 ( V_5 ) ;
}
}
}
F_40 ( V_208 -> V_50 [ 0 ] ) ;
F_23 ( V_208 ) ;
F_25 ( V_238 ) ;
V_5 = 0 ;
while ( ! F_61 ( & V_85 ) ) {
struct V_86 * V_87 = F_62 ( V_85 . V_88 ,
struct V_86 ,
V_89 ) ;
if ( ! V_5 )
V_5 = F_63 ( V_2 , log , V_87 ) ;
F_64 ( & V_87 -> V_89 ) ;
F_25 ( V_87 ) ;
}
return V_5 ;
}
static int F_219 ( void * V_247 , struct V_239 * V_248 , struct V_239 * V_249 )
{
struct V_250 * V_251 , * V_252 ;
V_251 = F_62 ( V_248 , struct V_250 , V_89 ) ;
V_252 = F_62 ( V_249 , struct V_250 , V_89 ) ;
if ( V_251 -> V_27 < V_252 -> V_27 )
return - 1 ;
else if ( V_251 -> V_27 > V_252 -> V_27 )
return 1 ;
return 0 ;
}
static int F_220 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_68 * V_68 ,
struct V_250 * V_253 ,
struct V_31 * V_32 )
{
struct V_67 * V_254 ;
struct V_20 * V_79 ;
struct V_34 V_35 , V_255 ;
struct V_220 V_221 ;
T_1 V_65 ;
T_1 V_256 = 0 ;
int V_257 ;
int V_258 = 0 ;
int V_259 = 0 ;
int V_5 = 0 ;
while ( 1 ) {
F_192 ( & V_221 ) ;
V_79 = V_32 -> V_50 [ 0 ] ;
V_32 -> V_51 [ 0 ] ++ ;
if ( V_32 -> V_51 [ 0 ] >= F_120 ( V_79 ) ) {
if ( V_259 ) {
V_5 = F_190 ( V_2 , V_4 , V_32 ,
V_258 , V_259 ) ;
if ( V_5 )
return V_5 ;
V_259 = 0 ;
}
V_5 = F_221 ( V_2 , V_4 , V_32 , 1 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( V_5 > 0 )
return 0 ;
V_79 = V_32 -> V_50 [ 0 ] ;
}
F_103 ( V_79 , & V_35 , V_32 -> V_51 [ 0 ] ) ;
if ( V_35 . V_45 != F_50 ( V_68 ) ||
V_35 . type != V_166 ||
V_35 . V_66 >= V_253 -> V_27 + V_253 -> V_28 )
break;
V_254 = F_27 ( V_79 , V_32 -> V_51 [ 0 ] ,
struct V_67 ) ;
V_257 = F_222 ( V_79 , V_254 , & V_221 ) ;
if ( V_257 == V_70 ||
V_257 == V_71 ) {
V_256 = F_223 ( V_79 ,
V_254 , & V_221 ) ;
V_65 = V_35 . V_66 +
F_224 ( V_79 , V_254 ,
& V_221 ) ;
} else if ( V_257 == V_72 ) {
V_65 = V_35 . V_66 +
F_45 ( V_79 , V_254 ) ;
} else {
F_111 () ;
}
if ( V_65 <= V_253 -> V_28 + V_253 -> V_27 ) {
if ( ! V_259 ) {
V_258 = V_32 -> V_51 [ 0 ] ;
}
V_259 ++ ;
continue;
}
if ( V_32 -> V_51 [ 0 ] < F_120 ( V_79 ) - 1 ) {
struct V_34 V_260 ;
F_103 ( V_79 , & V_260 ,
V_32 -> V_51 [ 0 ] + 1 ) ;
if ( V_260 . V_45 == F_50 ( V_68 ) &&
V_260 . type == V_166 &&
V_260 . V_66 <= V_253 -> V_27 + V_253 -> V_28 ) {
if ( ! V_259 )
V_258 = V_32 -> V_51 [ 0 ] ;
V_259 ++ ;
continue;
}
}
F_52 ( V_257 == V_72 ) ;
memcpy ( & V_255 , & V_35 , sizeof( V_255 ) ) ;
V_255 . V_66 = V_253 -> V_27 + V_253 -> V_28 ;
F_225 ( V_2 , V_4 , V_32 , & V_255 ) ;
V_256 += V_253 -> V_27 + V_253 -> V_28 - V_35 . V_66 ;
F_226 ( V_79 , V_254 , V_256 ,
& V_221 ) ;
F_227 ( V_79 , V_254 , V_65 -
( V_253 -> V_27 + V_253 -> V_28 ) ,
& V_221 ) ;
F_40 ( V_79 ) ;
}
if ( V_259 )
V_5 = F_190 ( V_2 , V_4 , V_32 , V_258 , V_259 ) ;
return V_5 ;
}
static int F_228 ( struct V_1 * V_2 ,
struct V_68 * V_68 , struct V_3 * V_4 ,
struct V_250 * V_253 , struct V_31 * V_32 )
{
struct V_3 * log = V_4 -> V_8 ;
struct V_67 * V_254 ;
struct V_20 * V_79 ;
struct V_261 * V_262 ;
struct V_239 V_85 ;
struct V_220 V_221 ;
struct V_34 V_35 ;
T_1 V_263 = V_253 -> V_263 ;
T_1 V_264 = V_253 -> V_264 ;
T_1 V_265 ;
T_1 V_266 ;
T_1 V_256 = V_253 -> V_27 - V_253 -> V_267 ;
T_1 V_268 ;
int V_5 ;
int V_98 = log -> V_178 % 2 ;
bool V_240 = F_106 ( V_68 ) -> V_230 & V_241 ;
V_52:
F_215 ( & V_85 ) ;
F_192 ( & V_221 ) ;
V_35 . V_45 = F_50 ( V_68 ) ;
V_35 . type = V_166 ;
V_35 . V_66 = V_253 -> V_27 ;
V_32 -> V_269 = 1 ;
V_5 = F_30 ( V_2 , log , V_32 , & V_35 , sizeof( * V_254 ) ) ;
if ( V_5 && V_5 != - V_58 ) {
V_32 -> V_269 = 0 ;
return V_5 ;
}
V_79 = V_32 -> V_50 [ 0 ] ;
V_254 = F_27 ( V_79 , V_32 -> V_51 [ 0 ] ,
struct V_67 ) ;
if ( V_5 && F_222 ( V_79 , V_254 , & V_221 ) ==
V_72 ) {
V_5 = F_109 ( V_2 , log , V_32 ) ;
F_23 ( V_32 ) ;
if ( V_5 ) {
V_32 -> V_269 = 0 ;
return V_5 ;
}
goto V_52;
}
F_229 ( V_79 , V_254 , V_253 -> V_222 ,
& V_221 ) ;
if ( F_230 ( V_270 , & V_253 -> V_230 ) ) {
V_240 = true ;
F_231 ( V_79 , V_254 ,
V_71 ,
& V_221 ) ;
} else {
F_231 ( V_79 , V_254 ,
V_70 ,
& V_221 ) ;
if ( V_253 -> V_271 == 0 )
V_240 = true ;
}
V_268 = F_186 ( V_253 -> V_268 , V_253 -> V_272 ) ;
if ( V_253 -> V_273 != V_274 ) {
F_232 ( V_79 , V_254 ,
V_253 -> V_271 ,
& V_221 ) ;
F_233 ( V_79 , V_254 , V_268 ,
& V_221 ) ;
} else if ( V_253 -> V_271 < V_275 ) {
F_232 ( V_79 , V_254 ,
V_253 -> V_271 -
V_256 , & V_221 ) ;
F_233 ( V_79 , V_254 , V_268 ,
& V_221 ) ;
} else {
F_232 ( V_79 , V_254 , 0 , & V_221 ) ;
F_233 ( V_79 , V_254 , 0 ,
& V_221 ) ;
}
F_226 ( V_79 , V_254 ,
V_253 -> V_27 - V_253 -> V_267 ,
& V_221 ) ;
F_227 ( V_79 , V_254 , V_253 -> V_28 , & V_221 ) ;
F_234 ( V_79 , V_254 , V_253 -> V_28 , & V_221 ) ;
F_235 ( V_79 , V_254 , V_253 -> V_273 ,
& V_221 ) ;
F_236 ( V_79 , V_254 , 0 , & V_221 ) ;
F_237 ( V_79 , V_254 , 0 , & V_221 ) ;
F_40 ( V_79 ) ;
V_5 = F_220 ( V_2 , log , V_68 , V_253 , V_32 ) ;
F_23 ( V_32 ) ;
V_32 -> V_269 = 0 ;
if ( V_5 ) {
return V_5 ;
}
if ( V_240 )
return 0 ;
if ( V_253 -> V_273 ) {
V_265 = 0 ;
V_266 = V_268 ;
}
V_118:
F_238 ( & log -> V_276 [ V_98 ] ) ;
F_239 (ordered, &log->logged_list[index], log_list) {
struct V_86 * V_277 ;
if ( ! V_264 )
break;
if ( V_262 -> V_68 != V_68 )
continue;
if ( V_262 -> V_278 + V_262 -> V_28 <= V_263 ||
V_263 + V_264 <= V_262 -> V_278 )
continue;
if ( V_262 -> V_278 > V_263 ) {
if ( V_262 -> V_278 + V_262 -> V_28 >=
V_263 + V_264 )
V_264 = V_262 -> V_278 - V_263 ;
} else {
if ( V_262 -> V_278 + V_262 -> V_28 <
V_263 + V_264 ) {
V_264 = ( V_263 + V_264 ) -
( V_262 -> V_278 + V_262 -> V_28 ) ;
V_263 = V_262 -> V_278 +
V_262 -> V_28 ;
} else {
V_264 = 0 ;
}
}
if ( F_240 ( V_279 ,
& V_262 -> V_230 ) )
continue;
F_3 ( & V_262 -> V_280 ) ;
F_241 ( & log -> V_276 [ V_98 ] ) ;
F_242 ( V_262 -> V_30 , V_262 -> V_281 == 0 ) ;
F_239 (sum, &ordered->list, list) {
V_5 = F_63 ( V_2 , log , V_277 ) ;
if ( V_5 ) {
F_243 ( V_262 ) ;
goto V_282;
}
}
F_243 ( V_262 ) ;
goto V_118;
}
F_241 ( & log -> V_276 [ V_98 ] ) ;
V_282:
if ( ! V_264 || V_5 )
return V_5 ;
V_265 = V_263 - V_253 -> V_27 ;
V_266 = V_264 ;
V_5 = F_60 ( log -> V_15 -> V_90 ,
V_253 -> V_271 + V_265 ,
V_253 -> V_271 + V_265 +
V_266 - 1 , & V_85 , 0 ) ;
if ( V_5 )
return V_5 ;
while ( ! F_61 ( & V_85 ) ) {
struct V_86 * V_87 = F_62 ( V_85 . V_88 ,
struct V_86 ,
V_89 ) ;
if ( ! V_5 )
V_5 = F_63 ( V_2 , log , V_87 ) ;
F_64 ( & V_87 -> V_89 ) ;
F_25 ( V_87 ) ;
}
return V_5 ;
}
static int F_244 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_68 * V_68 ,
struct V_31 * V_32 )
{
struct V_250 * V_253 , * V_283 ;
struct V_239 V_284 ;
struct V_285 * V_286 = & F_106 ( V_68 ) -> V_287 ;
T_1 V_288 ;
int V_5 = 0 ;
int V_289 = 0 ;
F_215 ( & V_284 ) ;
F_245 ( & V_286 -> V_290 ) ;
V_288 = V_4 -> V_15 -> V_291 ;
F_246 (em, n, &tree->modified_extents, list) {
F_247 ( & V_253 -> V_89 ) ;
if ( ++ V_289 > 32768 ) {
F_247 ( & V_286 -> V_292 ) ;
V_5 = - V_293 ;
goto V_294;
}
if ( V_253 -> V_222 <= V_288 )
continue;
F_3 ( & V_253 -> V_280 ) ;
F_248 ( V_295 , & V_253 -> V_230 ) ;
F_249 ( & V_253 -> V_89 , & V_284 ) ;
V_289 ++ ;
}
F_250 ( NULL , & V_284 , F_219 ) ;
V_294:
while ( ! F_61 ( & V_284 ) ) {
V_253 = F_62 ( V_284 . V_88 , struct V_250 , V_89 ) ;
F_247 ( & V_253 -> V_89 ) ;
if ( V_5 ) {
F_251 ( V_286 , V_253 ) ;
F_252 ( V_253 ) ;
continue;
}
F_253 ( & V_286 -> V_290 ) ;
V_5 = F_228 ( V_2 , V_68 , V_4 , V_253 , V_32 ) ;
F_245 ( & V_286 -> V_290 ) ;
F_251 ( V_286 , V_253 ) ;
F_252 ( V_253 ) ;
}
F_128 ( ! F_61 ( & V_284 ) ) ;
F_253 ( & V_286 -> V_290 ) ;
F_23 ( V_32 ) ;
return V_5 ;
}
static int F_254 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_68 * V_68 ,
int V_232 )
{
struct V_31 * V_32 ;
struct V_31 * V_208 ;
struct V_34 V_211 ;
struct V_34 V_212 ;
struct V_3 * log = V_4 -> V_8 ;
struct V_20 * V_213 = NULL ;
int V_6 = 0 ;
int V_5 ;
int V_148 ;
int V_296 = 0 ;
int V_297 ;
bool V_298 = false ;
T_1 V_130 = F_50 ( V_68 ) ;
log = V_4 -> V_8 ;
V_32 = F_79 () ;
if ( ! V_32 )
return - V_54 ;
V_208 = F_79 () ;
if ( ! V_208 ) {
F_83 ( V_32 ) ;
return - V_54 ;
}
V_211 . V_45 = V_130 ;
V_211 . type = V_43 ;
V_211 . V_66 = 0 ;
V_212 . V_45 = V_130 ;
if ( F_34 ( V_68 -> V_133 ) ||
( ! F_230 ( V_299 ,
& F_106 ( V_68 ) -> V_300 ) &&
V_232 == V_242 ) )
V_212 . type = V_165 ;
else
V_212 . type = ( T_4 ) - 1 ;
V_212 . V_66 = ( T_1 ) - 1 ;
if ( F_34 ( V_68 -> V_133 ) ||
F_106 ( V_68 ) -> V_222 > V_4 -> V_15 -> V_291 ) {
V_5 = F_255 ( V_2 , V_68 ) ;
if ( V_5 ) {
F_83 ( V_32 ) ;
F_83 ( V_208 ) ;
return V_5 ;
}
}
F_2 ( & F_106 ( V_68 ) -> V_7 ) ;
F_256 ( log , V_68 ) ;
if ( F_34 ( V_68 -> V_133 ) ) {
int V_217 = V_157 ;
if ( V_232 == V_242 )
V_217 = V_165 ;
V_5 = F_188 ( V_2 , log , V_32 , V_130 , V_217 ) ;
} else {
if ( F_257 ( V_299 ,
& F_106 ( V_68 ) -> V_300 ) ) {
F_258 ( V_301 ,
& F_106 ( V_68 ) -> V_300 ) ;
V_5 = F_259 ( V_2 , log ,
V_68 , 0 , 0 ) ;
} else if ( F_257 ( V_301 ,
& F_106 ( V_68 ) -> V_300 ) ) {
if ( V_232 == V_302 )
V_298 = true ;
V_212 . type = V_165 ;
V_5 = F_188 ( V_2 , log , V_32 , V_130 ,
V_212 . type ) ;
} else {
if ( V_232 == V_302 )
V_298 = true ;
V_5 = F_213 ( V_2 , log , V_208 , V_68 ) ;
if ( V_5 ) {
V_6 = V_5 ;
goto V_203;
}
goto V_303;
}
}
if ( V_5 ) {
V_6 = V_5 ;
goto V_203;
}
V_32 -> V_214 = 1 ;
while ( 1 ) {
V_297 = 0 ;
V_5 = F_184 ( V_4 , & V_211 , & V_212 ,
V_32 , V_2 -> V_63 ) ;
if ( V_5 != 0 )
break;
V_118:
if ( V_211 . V_45 != V_130 )
break;
if ( V_211 . type > V_212 . type )
break;
V_213 = V_32 -> V_50 [ 0 ] ;
if ( V_297 && V_296 + V_297 == V_32 -> V_51 [ 0 ] ) {
V_297 ++ ;
goto V_304;
} else if ( ! V_297 ) {
V_296 = V_32 -> V_51 [ 0 ] ;
V_297 = 1 ;
goto V_304;
}
V_5 = F_214 ( V_2 , V_68 , V_208 , V_213 , V_296 ,
V_297 , V_232 ) ;
if ( V_5 ) {
V_6 = V_5 ;
goto V_203;
}
V_297 = 1 ;
V_296 = V_32 -> V_51 [ 0 ] ;
V_304:
V_148 = F_120 ( V_32 -> V_50 [ 0 ] ) ;
V_32 -> V_51 [ 0 ] ++ ;
if ( V_32 -> V_51 [ 0 ] < V_148 ) {
F_103 ( V_32 -> V_50 [ 0 ] , & V_211 ,
V_32 -> V_51 [ 0 ] ) ;
goto V_118;
}
if ( V_297 ) {
V_5 = F_214 ( V_2 , V_68 , V_208 , V_213 ,
V_296 ,
V_297 , V_232 ) ;
if ( V_5 ) {
V_6 = V_5 ;
goto V_203;
}
V_297 = 0 ;
}
F_23 ( V_32 ) ;
if ( V_211 . V_66 < ( T_1 ) - 1 )
V_211 . V_66 ++ ;
else if ( V_211 . type < ( T_4 ) - 1 )
V_211 . type ++ ;
else if ( V_211 . V_45 < ( T_1 ) - 1 )
V_211 . V_45 ++ ;
else
break;
}
if ( V_297 ) {
V_5 = F_214 ( V_2 , V_68 , V_208 , V_213 , V_296 ,
V_297 , V_232 ) ;
if ( V_5 ) {
V_6 = V_5 ;
goto V_203;
}
V_297 = 0 ;
}
V_303:
if ( V_298 ) {
F_23 ( V_208 ) ;
V_5 = F_244 ( V_2 , V_4 , V_68 , V_208 ) ;
if ( V_5 ) {
V_6 = V_5 ;
goto V_203;
}
} else {
struct V_285 * V_286 = & F_106 ( V_68 ) -> V_287 ;
struct V_250 * V_253 , * V_283 ;
F_245 ( & V_286 -> V_290 ) ;
F_246 (em, n, &tree->modified_extents, list)
F_247 ( & V_253 -> V_89 ) ;
F_253 ( & V_286 -> V_290 ) ;
}
if ( V_232 == V_302 && F_34 ( V_68 -> V_133 ) ) {
F_23 ( V_32 ) ;
F_23 ( V_208 ) ;
V_5 = F_187 ( V_2 , V_4 , V_68 , V_32 , V_208 ) ;
if ( V_5 ) {
V_6 = V_5 ;
goto V_203;
}
}
F_106 ( V_68 ) -> V_202 = V_2 -> V_63 ;
F_106 ( V_68 ) -> V_197 = F_106 ( V_68 ) -> V_305 ;
V_203:
if ( V_6 )
F_159 ( log , log -> V_178 ) ;
F_4 ( & F_106 ( V_68 ) -> V_7 ) ;
F_83 ( V_32 ) ;
F_83 ( V_208 ) ;
return V_6 ;
}
static T_2 int F_260 ( struct V_1 * V_2 ,
struct V_68 * V_68 ,
struct V_306 * V_171 ,
struct V_307 * V_308 ,
T_1 V_309 )
{
int V_5 = 0 ;
struct V_3 * V_4 ;
struct V_306 * V_310 = NULL ;
if ( F_126 ( V_68 -> V_133 ) &&
F_106 ( V_68 ) -> V_222 <= V_309 &&
F_106 ( V_68 ) -> V_311 <= V_309 )
goto V_74;
if ( ! F_34 ( V_68 -> V_133 ) ) {
if ( ! V_171 || ! V_171 -> V_312 || V_308 != V_171 -> V_312 -> V_313 )
goto V_74;
V_68 = V_171 -> V_312 ;
}
while ( 1 ) {
F_106 ( V_68 ) -> V_202 = V_2 -> V_63 ;
F_8 () ;
if ( F_106 ( V_68 ) -> V_311 > V_309 ) {
V_4 = F_106 ( V_68 ) -> V_4 ;
V_4 -> V_15 -> V_182 =
V_2 -> V_63 ;
V_5 = 1 ;
break;
}
if ( ! V_171 || ! V_171 -> V_312 || V_308 != V_171 -> V_312 -> V_313 )
break;
if ( F_261 ( V_171 ) )
break;
V_171 = F_262 ( V_171 ) ;
F_263 ( V_310 ) ;
V_310 = V_171 ;
V_68 = V_171 -> V_312 ;
}
F_263 ( V_310 ) ;
V_74:
return V_5 ;
}
int F_264 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_68 * V_68 ,
struct V_306 * V_171 , int V_314 )
{
int V_232 = V_314 ? V_242 : V_302 ;
struct V_307 * V_308 ;
struct V_306 * V_310 = NULL ;
int V_5 = 0 ;
T_1 V_309 = V_4 -> V_15 -> V_291 ;
V_308 = V_68 -> V_313 ;
if ( F_157 ( V_4 , V_315 ) ) {
V_5 = 1 ;
goto V_316;
}
if ( V_4 -> V_15 -> V_182 >
V_4 -> V_15 -> V_291 ) {
V_5 = 1 ;
goto V_316;
}
if ( V_4 != F_106 ( V_68 ) -> V_4 ||
F_265 ( & V_4 -> V_179 ) == 0 ) {
V_5 = 1 ;
goto V_316;
}
V_5 = F_260 ( V_2 , V_68 , V_171 ,
V_308 , V_309 ) ;
if ( V_5 )
goto V_316;
if ( F_266 ( V_68 , V_2 -> V_63 ) ) {
V_5 = V_317 ;
goto V_316;
}
V_5 = F_1 ( V_2 , V_4 ) ;
if ( V_5 )
goto V_318;
V_5 = F_254 ( V_2 , V_4 , V_68 , V_232 ) ;
if ( V_5 )
goto V_318;
if ( F_126 ( V_68 -> V_133 ) &&
F_106 ( V_68 ) -> V_222 <= V_309 &&
F_106 ( V_68 ) -> V_311 <= V_309 ) {
V_5 = 0 ;
goto V_318;
}
V_232 = V_242 ;
while ( 1 ) {
if ( ! V_171 || ! V_171 -> V_312 || V_308 != V_171 -> V_312 -> V_313 )
break;
V_68 = V_171 -> V_312 ;
if ( V_4 != F_106 ( V_68 ) -> V_4 )
break;
if ( F_106 ( V_68 ) -> V_222 >
V_4 -> V_15 -> V_291 ) {
V_5 = F_254 ( V_2 , V_4 , V_68 , V_232 ) ;
if ( V_5 )
goto V_318;
}
if ( F_261 ( V_171 ) )
break;
V_171 = F_262 ( V_171 ) ;
F_263 ( V_310 ) ;
V_310 = V_171 ;
}
V_5 = 0 ;
V_318:
F_263 ( V_310 ) ;
if ( V_5 < 0 ) {
V_4 -> V_15 -> V_182 = V_2 -> V_63 ;
V_5 = 1 ;
}
F_10 ( V_4 ) ;
V_316:
return V_5 ;
}
int F_267 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_306 * V_306 )
{
struct V_306 * V_171 = F_262 ( V_306 ) ;
int V_5 ;
V_5 = F_264 ( V_2 , V_4 , V_306 -> V_312 , V_171 , 0 ) ;
F_263 ( V_171 ) ;
return V_5 ;
}
int F_268 ( struct V_3 * V_17 )
{
int V_5 ;
struct V_31 * V_32 ;
struct V_1 * V_2 ;
struct V_34 V_35 ;
struct V_34 V_137 ;
struct V_34 V_260 ;
struct V_3 * log ;
struct V_199 * V_15 = V_17 -> V_15 ;
struct V_22 V_23 = {
. V_174 = F_14 ,
. V_161 = 0 ,
} ;
V_32 = F_79 () ;
if ( ! V_32 )
return - V_54 ;
V_15 -> V_319 = 1 ;
V_2 = F_269 ( V_15 -> V_196 , 0 ) ;
if ( F_76 ( V_2 ) ) {
V_5 = F_177 ( V_2 ) ;
goto error;
}
V_23 . V_2 = V_2 ;
V_23 . V_25 = 1 ;
V_5 = F_143 ( V_2 , V_17 , & V_23 ) ;
if ( V_5 ) {
F_270 ( V_15 , V_5 , L_1
L_2 ) ;
goto error;
}
V_118:
V_35 . V_45 = V_46 ;
V_35 . V_66 = ( T_1 ) - 1 ;
F_110 ( & V_35 , V_320 ) ;
while ( 1 ) {
V_5 = F_22 ( NULL , V_17 , & V_35 , V_32 , 0 , 0 ) ;
if ( V_5 < 0 ) {
F_270 ( V_15 , V_5 ,
L_3 ) ;
goto error;
}
if ( V_5 > 0 ) {
if ( V_32 -> V_51 [ 0 ] == 0 )
break;
V_32 -> V_51 [ 0 ] -- ;
}
F_103 ( V_32 -> V_50 [ 0 ] , & V_137 ,
V_32 -> V_51 [ 0 ] ) ;
F_23 ( V_32 ) ;
if ( V_137 . V_45 != V_46 )
break;
log = F_271 ( V_17 ,
& V_137 ) ;
if ( F_76 ( log ) ) {
V_5 = F_177 ( log ) ;
F_270 ( V_15 , V_5 ,
L_4 ) ;
goto error;
}
V_260 . V_45 = V_137 . V_66 ;
V_260 . type = V_320 ;
V_260 . V_66 = ( T_1 ) - 1 ;
V_23 . V_158 = F_272 ( V_15 , & V_260 ) ;
if ( F_76 ( V_23 . V_158 ) ) {
V_5 = F_177 ( V_23 . V_158 ) ;
F_270 ( V_15 , V_5 , L_5
L_6 ) ;
goto error;
}
V_23 . V_158 -> V_8 = log ;
F_273 ( V_2 , V_23 . V_158 ) ;
V_5 = F_143 ( V_2 , log , & V_23 ) ;
F_52 ( V_5 ) ;
if ( V_23 . V_161 == V_164 ) {
V_5 = F_108 ( V_2 , V_23 . V_158 ,
V_32 ) ;
F_52 ( V_5 ) ;
}
V_35 . V_66 = V_137 . V_66 - 1 ;
V_23 . V_158 -> V_8 = NULL ;
F_134 ( log -> V_175 ) ;
F_134 ( log -> V_321 ) ;
F_25 ( log ) ;
if ( V_137 . V_66 == 0 )
break;
}
F_23 ( V_32 ) ;
if ( V_23 . V_25 ) {
V_23 . V_25 = 0 ;
V_23 . V_174 = F_123 ;
V_23 . V_161 = V_162 ;
goto V_118;
}
if ( V_23 . V_161 < V_164 ) {
V_23 . V_161 ++ ;
goto V_118;
}
F_83 ( V_32 ) ;
F_134 ( V_17 -> V_175 ) ;
V_17 -> V_8 = NULL ;
V_15 -> V_319 = 0 ;
F_274 ( V_2 , V_15 -> V_196 ) ;
F_25 ( V_17 ) ;
return 0 ;
error:
F_83 ( V_32 ) ;
return V_5 ;
}
void F_275 ( struct V_1 * V_2 ,
struct V_68 * V_91 , struct V_68 * V_68 ,
int V_322 )
{
if ( F_126 ( V_68 -> V_133 ) )
F_106 ( V_68 ) -> V_311 = V_2 -> V_63 ;
F_8 () ;
if ( F_106 ( V_91 ) -> V_202 == V_2 -> V_63 )
return;
if ( F_106 ( V_68 ) -> V_202 == V_2 -> V_63 )
return;
if ( V_322 )
goto V_323;
return;
V_323:
F_106 ( V_91 ) -> V_311 = V_2 -> V_63 ;
}
int F_276 ( struct V_1 * V_2 ,
struct V_68 * V_68 , struct V_68 * V_324 ,
struct V_306 * V_171 )
{
struct V_3 * V_4 = F_106 ( V_68 ) -> V_4 ;
if ( F_126 ( V_68 -> V_133 ) )
F_106 ( V_68 ) -> V_311 = V_2 -> V_63 ;
if ( F_106 ( V_68 ) -> V_202 <=
V_4 -> V_15 -> V_291 &&
( ! V_324 || F_106 ( V_324 ) -> V_202 <=
V_4 -> V_15 -> V_291 ) )
return 0 ;
return F_264 ( V_2 , V_4 , V_68 , V_171 , 1 ) ;
}
