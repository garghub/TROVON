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
F_15 ( V_23 -> V_2 ,
log -> V_15 -> V_26 ,
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
if ( V_4 -> V_42 . V_43 != V_44 )
V_41 = 1 ;
V_36 = F_20 ( V_21 , V_33 ) ;
V_39 = F_21 ( V_21 , V_33 ) ;
V_5 = F_22 ( NULL , V_4 , V_35 , V_32 , 0 , 0 ) ;
if ( V_5 == 0 ) {
char * V_45 ;
char * V_46 ;
T_3 V_47 = F_20 ( V_32 -> V_48 [ 0 ] ,
V_32 -> V_49 [ 0 ] ) ;
if ( V_47 != V_36 )
goto V_50;
if ( V_36 == 0 ) {
F_23 ( V_32 ) ;
return 0 ;
}
V_46 = F_24 ( V_36 , V_51 ) ;
V_45 = F_24 ( V_36 , V_51 ) ;
if ( ! V_46 || ! V_45 ) {
F_23 ( V_32 ) ;
F_25 ( V_46 ) ;
F_25 ( V_45 ) ;
return - V_52 ;
}
F_26 ( V_21 , V_45 , V_39 , V_36 ) ;
V_40 = F_21 ( V_32 -> V_48 [ 0 ] , V_32 -> V_49 [ 0 ] ) ;
F_26 ( V_32 -> V_48 [ 0 ] , V_46 , V_40 ,
V_36 ) ;
V_5 = memcmp ( V_46 , V_45 , V_36 ) ;
F_25 ( V_46 ) ;
F_25 ( V_45 ) ;
if ( V_5 == 0 ) {
F_23 ( V_32 ) ;
return 0 ;
}
}
V_50:
F_23 ( V_32 ) ;
V_5 = F_27 ( V_2 , V_4 , V_32 ,
V_35 , V_36 ) ;
if ( V_5 == - V_53 ) {
T_3 V_54 ;
V_54 = F_20 ( V_32 -> V_48 [ 0 ] ,
V_32 -> V_49 [ 0 ] ) ;
if ( V_54 > V_36 )
F_28 ( V_2 , V_4 , V_32 , V_36 , 1 ) ;
else if ( V_54 < V_36 )
F_29 ( V_2 , V_4 , V_32 ,
V_36 - V_54 ) ;
} else if ( V_5 ) {
return V_5 ;
}
V_40 = F_21 ( V_32 -> V_48 [ 0 ] ,
V_32 -> V_49 [ 0 ] ) ;
if ( V_35 -> type == V_55 && V_5 == - V_53 ) {
struct V_56 * V_57 ;
struct V_56 * V_58 ;
V_57 = (struct V_56 * ) V_39 ;
V_58 = (struct V_56 * ) V_40 ;
if ( F_30 ( V_21 , V_57 ) == 0 )
goto V_59;
if ( V_41 &&
F_31 ( F_32 ( V_21 , V_57 ) ) &&
F_31 ( F_32 ( V_32 -> V_48 [ 0 ] , V_58 ) ) ) {
V_38 = 1 ;
V_37 = F_33 ( V_32 -> V_48 [ 0 ] ,
V_58 ) ;
}
}
F_34 ( V_32 -> V_48 [ 0 ] , V_21 , V_40 ,
V_39 , V_36 ) ;
if ( V_38 ) {
struct V_56 * V_58 ;
V_58 = (struct V_56 * ) V_40 ;
F_35 ( V_32 -> V_48 [ 0 ] , V_58 , V_37 ) ;
}
if ( V_35 -> type == V_55 ) {
struct V_56 * V_58 ;
V_58 = (struct V_56 * ) V_40 ;
if ( F_30 ( V_32 -> V_48 [ 0 ] , V_58 ) == 0 ) {
F_36 ( V_32 -> V_48 [ 0 ] , V_58 ,
V_2 -> V_60 ) ;
}
}
V_59:
F_37 ( V_32 -> V_48 [ 0 ] ) ;
F_23 ( V_32 ) ;
return 0 ;
}
T_2 int F_38 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_31 * V_32 ,
struct V_20 * V_21 , int V_33 ,
struct V_34 * V_35 )
{
int V_61 ;
T_1 V_62 = V_4 -> V_63 - 1 ;
T_1 V_64 ;
T_1 V_27 = V_35 -> V_65 ;
T_1 V_66 ;
struct V_67 * V_68 ;
struct V_69 * V_69 = NULL ;
unsigned long V_70 ;
int V_5 = 0 ;
V_68 = F_39 ( V_21 , V_33 , struct V_67 ) ;
V_61 = F_40 ( V_21 , V_68 ) ;
if ( V_61 == V_71 ||
V_61 == V_72 )
V_64 = V_27 + F_41 ( V_21 , V_68 ) ;
else if ( V_61 == V_73 ) {
V_70 = F_42 ( V_21 , V_68 ) ;
V_64 = ( V_27 + V_70 + V_62 ) & ~ V_62 ;
} else {
V_5 = 0 ;
goto V_74;
}
V_69 = F_43 ( V_4 , V_35 -> V_43 ) ;
if ( ! V_69 ) {
V_5 = - V_75 ;
goto V_74;
}
V_5 = F_44 ( V_2 , V_4 , V_32 , F_45 ( V_69 ) ,
V_27 , 0 ) ;
if ( V_5 == 0 &&
( V_61 == V_71 ||
V_61 == V_72 ) ) {
struct V_67 V_76 ;
struct V_67 V_77 ;
struct V_67 * V_78 ;
struct V_20 * V_79 ;
V_79 = V_32 -> V_48 [ 0 ] ;
V_78 = F_39 ( V_79 , V_32 -> V_49 [ 0 ] ,
struct V_67 ) ;
F_26 ( V_21 , & V_76 , ( unsigned long ) V_68 ,
sizeof( V_76 ) ) ;
F_26 ( V_79 , & V_77 , ( unsigned long ) V_78 ,
sizeof( V_77 ) ) ;
if ( memcmp ( & V_76 , & V_77 , sizeof( V_76 ) ) == 0 ) {
F_23 ( V_32 ) ;
goto V_74;
}
}
F_23 ( V_32 ) ;
V_66 = F_46 ( V_69 ) ;
V_5 = F_47 ( V_2 , V_4 , V_69 , V_27 , V_64 , 1 ) ;
F_48 ( V_5 ) ;
if ( V_61 == V_71 ||
V_61 == V_72 ) {
T_1 V_65 ;
unsigned long V_80 ;
struct V_34 V_81 ;
V_5 = F_27 ( V_2 , V_4 , V_32 , V_35 ,
sizeof( * V_68 ) ) ;
F_48 ( V_5 ) ;
V_80 = F_21 ( V_32 -> V_48 [ 0 ] ,
V_32 -> V_49 [ 0 ] ) ;
F_34 ( V_32 -> V_48 [ 0 ] , V_21 , V_80 ,
( unsigned long ) V_68 , sizeof( * V_68 ) ) ;
V_81 . V_43 = F_49 ( V_21 , V_68 ) ;
V_81 . V_65 = F_50 ( V_21 , V_68 ) ;
V_81 . type = V_82 ;
V_65 = V_35 -> V_65 - F_51 ( V_21 , V_68 ) ;
if ( V_81 . V_43 > 0 ) {
T_1 V_83 ;
T_1 V_84 ;
F_52 ( V_85 ) ;
V_5 = F_53 ( V_4 , V_81 . V_43 ,
V_81 . V_65 ) ;
if ( V_5 == 0 ) {
V_5 = F_54 ( V_2 , V_4 ,
V_81 . V_43 , V_81 . V_65 ,
0 , V_4 -> V_42 . V_43 ,
V_35 -> V_43 , V_65 , 0 ) ;
F_48 ( V_5 ) ;
} else {
V_5 = F_55 ( V_2 ,
V_4 , V_4 -> V_42 . V_43 ,
V_35 -> V_43 , V_65 , & V_81 ) ;
F_48 ( V_5 ) ;
}
F_23 ( V_32 ) ;
if ( F_56 ( V_21 , V_68 ) ) {
V_83 = V_81 . V_43 ;
V_84 = V_83 + V_81 . V_65 ;
} else {
V_83 = V_81 . V_43 +
F_51 ( V_21 , V_68 ) ;
V_84 = V_83 +
F_41 ( V_21 , V_68 ) ;
}
V_5 = F_57 ( V_4 -> V_8 ,
V_83 , V_84 - 1 ,
& V_85 , 0 ) ;
F_48 ( V_5 ) ;
while ( ! F_58 ( & V_85 ) ) {
struct V_86 * V_87 ;
V_87 = F_59 ( V_85 . V_88 ,
struct V_86 ,
V_89 ) ;
V_5 = F_60 ( V_2 ,
V_4 -> V_15 -> V_90 ,
V_87 ) ;
F_48 ( V_5 ) ;
F_61 ( & V_87 -> V_89 ) ;
F_25 ( V_87 ) ;
}
} else {
F_23 ( V_32 ) ;
}
} else if ( V_61 == V_73 ) {
V_5 = F_19 ( V_2 , V_4 , V_32 , V_21 , V_33 , V_35 ) ;
F_48 ( V_5 ) ;
}
F_62 ( V_69 , V_66 ) ;
V_5 = F_63 ( V_2 , V_4 , V_69 ) ;
V_74:
if ( V_69 )
F_64 ( V_69 ) ;
return V_5 ;
}
static T_2 int F_65 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_31 * V_32 ,
struct V_69 * V_91 ,
struct V_92 * V_93 )
{
struct V_69 * V_69 ;
char * V_94 ;
int V_95 ;
struct V_20 * V_79 ;
struct V_34 V_96 ;
int V_5 ;
V_79 = V_32 -> V_48 [ 0 ] ;
F_66 ( V_79 , V_93 , & V_96 ) ;
V_95 = F_67 ( V_79 , V_93 ) ;
V_94 = F_24 ( V_95 , V_51 ) ;
if ( ! V_94 )
return - V_52 ;
F_26 ( V_79 , V_94 , ( unsigned long ) ( V_93 + 1 ) , V_95 ) ;
F_23 ( V_32 ) ;
V_69 = F_43 ( V_4 , V_96 . V_43 ) ;
if ( ! V_69 ) {
F_25 ( V_94 ) ;
return - V_75 ;
}
V_5 = F_68 ( V_2 , V_4 , V_32 , V_96 . V_43 ) ;
F_48 ( V_5 ) ;
V_5 = F_69 ( V_2 , V_4 , V_91 , V_69 , V_94 , V_95 ) ;
F_48 ( V_5 ) ;
F_25 ( V_94 ) ;
F_64 ( V_69 ) ;
F_70 ( V_2 , V_4 ) ;
return V_5 ;
}
static T_2 int F_71 ( struct V_3 * V_4 ,
struct V_31 * V_32 ,
T_1 V_97 , T_1 V_43 , T_1 V_98 ,
const char * V_94 , int V_95 )
{
struct V_92 * V_93 ;
struct V_34 V_96 ;
int V_99 = 0 ;
V_93 = F_72 ( NULL , V_4 , V_32 , V_97 ,
V_98 , V_94 , V_95 , 0 ) ;
if ( V_93 && ! F_73 ( V_93 ) ) {
F_66 ( V_32 -> V_48 [ 0 ] , V_93 , & V_96 ) ;
if ( V_96 . V_43 != V_43 )
goto V_74;
} else
goto V_74;
F_23 ( V_32 ) ;
V_93 = F_74 ( NULL , V_4 , V_32 , V_97 , V_94 , V_95 , 0 ) ;
if ( V_93 && ! F_73 ( V_93 ) ) {
F_66 ( V_32 -> V_48 [ 0 ] , V_93 , & V_96 ) ;
if ( V_96 . V_43 != V_43 )
goto V_74;
} else
goto V_74;
V_99 = 1 ;
V_74:
F_23 ( V_32 ) ;
return V_99 ;
}
static T_2 int F_75 ( struct V_3 * log ,
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
V_32 = F_76 () ;
if ( ! V_32 )
return - V_52 ;
V_5 = F_22 ( NULL , log , V_35 , V_32 , 0 , 0 ) ;
if ( V_5 != 0 )
goto V_74;
V_104 = F_21 ( V_32 -> V_48 [ 0 ] , V_32 -> V_49 [ 0 ] ) ;
if ( V_35 -> type == V_108 ) {
if ( F_77 ( V_32 , V_100 ,
V_94 , V_101 , NULL ) )
V_99 = 1 ;
goto V_74;
}
V_36 = F_20 ( V_32 -> V_48 [ 0 ] , V_32 -> V_49 [ 0 ] ) ;
V_105 = V_104 + V_36 ;
while ( V_104 < V_105 ) {
V_103 = (struct V_102 * ) V_104 ;
V_107 = F_78 ( V_32 -> V_48 [ 0 ] , V_103 ) ;
if ( V_107 == V_101 ) {
V_106 = ( unsigned long ) ( V_103 + 1 ) ;
V_5 = F_79 ( V_32 -> V_48 [ 0 ] , V_94 ,
V_106 , V_101 ) ;
if ( V_5 == 0 ) {
V_99 = 1 ;
goto V_74;
}
}
V_104 = ( unsigned long ) ( V_103 + 1 ) + V_107 ;
}
V_74:
F_80 ( V_32 ) ;
return V_99 ;
}
static inline int F_81 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_31 * V_32 ,
struct V_3 * V_8 ,
struct V_69 * V_91 , struct V_69 * V_69 ,
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
V_115 . V_43 = V_109 ;
V_115 . type = V_119 ;
V_115 . V_65 = V_110 ;
V_5 = F_22 ( NULL , V_4 , & V_115 , V_32 , 0 , 0 ) ;
if ( V_5 == 0 ) {
struct V_102 * V_120 ;
unsigned long V_104 ;
unsigned long V_105 ;
V_79 = V_32 -> V_48 [ 0 ] ;
if ( V_115 . V_43 == V_115 . V_65 )
return 1 ;
V_104 = F_21 ( V_79 , V_32 -> V_49 [ 0 ] ) ;
V_105 = V_104 + F_20 ( V_79 , V_32 -> V_49 [ 0 ] ) ;
while ( V_104 < V_105 ) {
V_120 = (struct V_102 * ) V_104 ;
V_114 = F_78 ( V_79 ,
V_120 ) ;
V_113 = F_24 ( V_114 , V_51 ) ;
F_48 ( ! V_113 ) ;
F_26 ( V_79 , V_113 ,
( unsigned long ) ( V_120 + 1 ) ,
V_114 ) ;
if ( ! F_75 ( V_8 , & V_115 ,
V_110 ,
V_113 ,
V_114 ) ) {
F_82 ( V_69 ) ;
F_23 ( V_32 ) ;
V_5 = F_69 ( V_2 , V_4 , V_91 ,
V_69 , V_113 ,
V_114 ) ;
F_48 ( V_5 ) ;
F_70 ( V_2 , V_4 ) ;
F_25 ( V_113 ) ;
* V_112 = 1 ;
goto V_118;
}
F_25 ( V_113 ) ;
V_104 = ( unsigned long ) ( V_120 + 1 ) + V_114 ;
}
F_48 ( V_5 ) ;
* V_112 = 1 ;
}
F_23 ( V_32 ) ;
V_117 = F_83 ( NULL , V_4 , V_32 , V_94 , V_101 ,
V_109 , V_110 , 0 ,
0 ) ;
if ( ! F_84 ( V_117 ) ) {
T_3 V_36 ;
T_3 V_121 = 0 ;
unsigned long V_122 ;
struct V_69 * V_123 ;
V_79 = V_32 -> V_48 [ 0 ] ;
V_36 = F_20 ( V_79 , V_32 -> V_49 [ 0 ] ) ;
V_122 = F_21 ( V_79 , V_32 -> V_49 [ 0 ] ) ;
while ( V_121 < V_36 ) {
V_117 = (struct V_116 * ) V_122 + V_121 ;
V_114 = F_85 ( V_79 , V_117 ) ;
if ( F_86 ( V_79 , V_117 ) != V_110 )
goto V_88;
V_113 = F_24 ( V_114 , V_51 ) ;
F_26 ( V_79 , V_113 , ( unsigned long ) & V_117 -> V_94 ,
V_114 ) ;
V_115 . V_43 = V_109 ;
V_115 . type = V_108 ;
V_115 . V_65 = F_87 ( V_110 ,
V_113 ,
V_114 ) ;
V_5 = 0 ;
if ( ! F_75 ( V_8 , & V_115 ,
V_110 , V_113 ,
V_114 ) ) {
V_5 = - V_18 ;
V_123 = F_43 ( V_4 ,
V_110 ) ;
if ( V_123 ) {
F_82 ( V_69 ) ;
F_23 ( V_32 ) ;
V_5 = F_69 ( V_2 , V_4 ,
V_123 ,
V_69 ,
V_113 ,
V_114 ) ;
F_70 ( V_2 , V_4 ) ;
}
F_48 ( V_5 ) ;
F_64 ( V_123 ) ;
F_25 ( V_113 ) ;
* V_112 = 1 ;
goto V_118;
}
F_25 ( V_113 ) ;
F_48 ( V_5 ) ;
V_88:
V_121 += V_114 + sizeof( * V_117 ) ;
}
* V_112 = 1 ;
}
F_23 ( V_32 ) ;
V_93 = F_72 ( V_2 , V_4 , V_32 , F_45 ( V_91 ) ,
V_111 , V_94 , V_101 , 0 ) ;
if ( V_93 && ! F_73 ( V_93 ) ) {
V_5 = F_65 ( V_2 , V_4 , V_32 , V_91 , V_93 ) ;
F_48 ( V_5 ) ;
}
F_23 ( V_32 ) ;
V_93 = F_74 ( V_2 , V_4 , V_32 , F_45 ( V_91 ) ,
V_94 , V_101 , 0 ) ;
if ( V_93 && ! F_73 ( V_93 ) ) {
V_5 = F_65 ( V_2 , V_4 , V_32 , V_91 , V_93 ) ;
F_48 ( V_5 ) ;
}
F_23 ( V_32 ) ;
return 0 ;
}
static int F_88 ( struct V_20 * V_21 , unsigned long V_124 ,
T_3 * V_101 , char * * V_94 , T_1 * V_98 ,
T_1 * V_110 )
{
struct V_116 * V_117 ;
V_117 = (struct V_116 * ) V_124 ;
* V_101 = F_85 ( V_21 , V_117 ) ;
* V_94 = F_24 ( * V_101 , V_51 ) ;
if ( * V_94 == NULL )
return - V_52 ;
F_26 ( V_21 , * V_94 , ( unsigned long ) & V_117 -> V_94 ,
* V_101 ) ;
* V_98 = F_89 ( V_21 , V_117 ) ;
if ( V_110 )
* V_110 = F_86 ( V_21 , V_117 ) ;
return 0 ;
}
static int F_90 ( struct V_20 * V_21 , unsigned long V_124 ,
T_3 * V_101 , char * * V_94 , T_1 * V_98 )
{
struct V_102 * V_103 ;
V_103 = (struct V_102 * ) V_124 ;
* V_101 = F_78 ( V_21 , V_103 ) ;
* V_94 = F_24 ( * V_101 , V_51 ) ;
if ( * V_94 == NULL )
return - V_52 ;
F_26 ( V_21 , * V_94 , ( unsigned long ) ( V_103 + 1 ) , * V_101 ) ;
* V_98 = F_91 ( V_21 , V_103 ) ;
return 0 ;
}
static T_2 int F_92 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_3 * log ,
struct V_31 * V_32 ,
struct V_20 * V_21 , int V_33 ,
struct V_34 * V_35 )
{
struct V_69 * V_91 ;
struct V_69 * V_69 ;
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
V_110 = F_86 ( V_21 , V_128 ) ;
} else {
V_127 = sizeof( struct V_102 ) ;
V_110 = V_35 -> V_65 ;
}
V_109 = V_35 -> V_43 ;
V_91 = F_43 ( V_4 , V_110 ) ;
if ( ! V_91 )
return - V_18 ;
V_69 = F_43 ( V_4 , V_109 ) ;
if ( ! V_69 ) {
F_64 ( V_91 ) ;
return - V_75 ;
}
while ( V_124 < V_125 ) {
if ( V_126 ) {
V_5 = F_88 ( V_21 , V_124 , & V_101 , & V_94 ,
& V_111 , & V_110 ) ;
if ( ! V_91 )
V_91 = F_43 ( V_4 , V_110 ) ;
if ( ! V_91 )
return - V_18 ;
} else {
V_5 = F_90 ( V_21 , V_124 , & V_101 , & V_94 ,
& V_111 ) ;
}
if ( V_5 )
return V_5 ;
if ( ! F_71 ( V_4 , V_32 , F_45 ( V_91 ) , F_45 ( V_69 ) ,
V_111 , V_94 , V_101 ) ) {
if ( ! V_112 ) {
V_5 = F_81 ( V_2 , V_4 , V_32 , log ,
V_91 , V_69 , V_21 ,
V_109 ,
V_110 ,
V_111 , V_94 , V_101 ,
& V_112 ) ;
if ( V_5 == 1 )
goto V_74;
F_48 ( V_5 ) ;
}
V_5 = F_93 ( V_2 , V_91 , V_69 , V_94 , V_101 ,
0 , V_111 ) ;
F_48 ( V_5 ) ;
F_63 ( V_2 , V_4 , V_69 ) ;
}
V_124 = ( unsigned long ) ( V_124 + V_127 ) + V_101 ;
F_25 ( V_94 ) ;
if ( V_126 ) {
F_64 ( V_91 ) ;
V_91 = NULL ;
}
}
V_5 = F_19 ( V_2 , V_4 , V_32 , V_21 , V_33 , V_35 ) ;
F_48 ( V_5 ) ;
V_74:
F_23 ( V_32 ) ;
F_64 ( V_91 ) ;
F_64 ( V_69 ) ;
return 0 ;
}
static int F_94 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_1 V_65 )
{
int V_5 ;
V_5 = F_95 ( V_4 , V_65 ) ;
if ( V_5 > 0 )
V_5 = F_96 ( V_2 , V_4 , V_65 ) ;
return V_5 ;
}
static int F_97 ( struct V_3 * V_4 ,
struct V_69 * V_69 , struct V_31 * V_32 )
{
int V_5 = 0 ;
int V_95 ;
unsigned int V_129 = 0 ;
T_3 V_36 ;
T_3 V_121 = 0 ;
T_1 V_109 = F_45 ( V_69 ) ;
T_1 V_65 = 0 ;
unsigned long V_104 ;
struct V_116 * V_117 ;
struct V_20 * V_79 ;
while ( 1 ) {
V_5 = F_98 ( V_4 , V_109 , V_65 , V_32 ,
& V_117 , & V_65 ) ;
if ( V_5 )
break;
V_79 = V_32 -> V_48 [ 0 ] ;
V_36 = F_20 ( V_79 , V_32 -> V_49 [ 0 ] ) ;
V_104 = F_21 ( V_79 , V_32 -> V_49 [ 0 ] ) ;
while ( V_121 < V_36 ) {
V_117 = (struct V_116 * ) ( V_104 + V_121 ) ;
V_95 = F_85 ( V_79 , V_117 ) ;
V_129 ++ ;
V_121 += V_95 + sizeof( * V_117 ) ;
}
V_65 ++ ;
F_23 ( V_32 ) ;
}
F_23 ( V_32 ) ;
if ( V_5 < 0 )
return V_5 ;
return V_129 ;
}
static int F_99 ( struct V_3 * V_4 ,
struct V_69 * V_69 , struct V_31 * V_32 )
{
int V_5 ;
struct V_34 V_35 ;
unsigned int V_129 = 0 ;
unsigned long V_104 ;
unsigned long V_105 ;
int V_95 ;
T_1 V_130 = F_45 ( V_69 ) ;
V_35 . V_43 = V_130 ;
V_35 . type = V_119 ;
V_35 . V_65 = ( T_1 ) - 1 ;
while ( 1 ) {
V_5 = F_22 ( NULL , V_4 , & V_35 , V_32 , 0 , 0 ) ;
if ( V_5 < 0 )
break;
if ( V_5 > 0 ) {
if ( V_32 -> V_49 [ 0 ] == 0 )
break;
V_32 -> V_49 [ 0 ] -- ;
}
F_100 ( V_32 -> V_48 [ 0 ] , & V_35 ,
V_32 -> V_49 [ 0 ] ) ;
if ( V_35 . V_43 != V_130 ||
V_35 . type != V_119 )
break;
V_104 = F_21 ( V_32 -> V_48 [ 0 ] , V_32 -> V_49 [ 0 ] ) ;
V_105 = V_104 + F_20 ( V_32 -> V_48 [ 0 ] ,
V_32 -> V_49 [ 0 ] ) ;
while ( V_104 < V_105 ) {
struct V_102 * V_103 ;
V_103 = (struct V_102 * ) V_104 ;
V_95 = F_78 ( V_32 -> V_48 [ 0 ] ,
V_103 ) ;
V_104 = ( unsigned long ) ( V_103 + 1 ) + V_95 ;
V_129 ++ ;
}
if ( V_35 . V_65 == 0 )
break;
V_35 . V_65 -- ;
F_23 ( V_32 ) ;
}
F_23 ( V_32 ) ;
return V_129 ;
}
static T_2 int F_101 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_69 * V_69 )
{
struct V_31 * V_32 ;
int V_5 ;
T_1 V_129 = 0 ;
T_1 V_130 = F_45 ( V_69 ) ;
V_32 = F_76 () ;
if ( ! V_32 )
return - V_52 ;
V_5 = F_99 ( V_4 , V_69 , V_32 ) ;
if ( V_5 < 0 )
goto V_74;
V_129 = V_5 ;
V_5 = F_97 ( V_4 , V_69 , V_32 ) ;
if ( V_5 == - V_18 )
V_5 = 0 ;
if ( V_5 < 0 )
goto V_74;
V_129 += V_5 ;
V_5 = 0 ;
if ( V_129 != V_69 -> V_131 ) {
F_102 ( V_69 , V_129 ) ;
F_63 ( V_2 , V_4 , V_69 ) ;
}
F_103 ( V_69 ) -> V_132 = ( T_1 ) - 1 ;
if ( V_69 -> V_131 == 0 ) {
if ( F_31 ( V_69 -> V_133 ) ) {
V_5 = F_104 ( V_2 , V_4 , NULL , V_32 ,
V_130 , 1 ) ;
F_48 ( V_5 ) ;
}
V_5 = F_94 ( V_2 , V_4 , V_130 ) ;
F_48 ( V_5 ) ;
}
V_74:
F_80 ( V_32 ) ;
return V_5 ;
}
static T_2 int F_105 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_31 * V_32 )
{
int V_5 ;
struct V_34 V_35 ;
struct V_69 * V_69 ;
V_35 . V_43 = V_134 ;
V_35 . type = V_135 ;
V_35 . V_65 = ( T_1 ) - 1 ;
while ( 1 ) {
V_5 = F_22 ( V_2 , V_4 , & V_35 , V_32 , - 1 , 1 ) ;
if ( V_5 < 0 )
break;
if ( V_5 == 1 ) {
if ( V_32 -> V_49 [ 0 ] == 0 )
break;
V_32 -> V_49 [ 0 ] -- ;
}
F_100 ( V_32 -> V_48 [ 0 ] , & V_35 , V_32 -> V_49 [ 0 ] ) ;
if ( V_35 . V_43 != V_134 ||
V_35 . type != V_135 )
break;
V_5 = F_106 ( V_2 , V_4 , V_32 ) ;
if ( V_5 )
goto V_74;
F_23 ( V_32 ) ;
V_69 = F_43 ( V_4 , V_35 . V_65 ) ;
if ( ! V_69 )
return - V_75 ;
V_5 = F_101 ( V_2 , V_4 , V_69 ) ;
F_48 ( V_5 ) ;
F_64 ( V_69 ) ;
V_35 . V_65 = ( T_1 ) - 1 ;
}
V_5 = 0 ;
V_74:
F_23 ( V_32 ) ;
return V_5 ;
}
static T_2 int F_68 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_31 * V_32 ,
T_1 V_43 )
{
struct V_34 V_35 ;
int V_5 = 0 ;
struct V_69 * V_69 ;
V_69 = F_43 ( V_4 , V_43 ) ;
if ( ! V_69 )
return - V_75 ;
V_35 . V_43 = V_134 ;
F_107 ( & V_35 , V_135 ) ;
V_35 . V_65 = V_43 ;
V_5 = F_27 ( V_2 , V_4 , V_32 , & V_35 , 0 ) ;
F_23 ( V_32 ) ;
if ( V_5 == 0 ) {
F_82 ( V_69 ) ;
V_5 = F_63 ( V_2 , V_4 , V_69 ) ;
} else if ( V_5 == - V_53 ) {
V_5 = 0 ;
} else {
F_108 () ;
}
F_64 ( V_69 ) ;
return V_5 ;
}
static T_2 int F_109 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_31 * V_32 ,
T_1 V_97 , T_1 V_98 ,
char * V_94 , int V_95 , T_4 type ,
struct V_34 * V_96 )
{
struct V_69 * V_69 ;
struct V_69 * V_91 ;
int V_5 ;
V_69 = F_43 ( V_4 , V_96 -> V_43 ) ;
if ( ! V_69 )
return - V_18 ;
V_91 = F_43 ( V_4 , V_97 ) ;
if ( ! V_91 ) {
F_64 ( V_69 ) ;
return - V_75 ;
}
V_5 = F_93 ( V_2 , V_91 , V_69 , V_94 , V_95 , 1 , V_98 ) ;
F_64 ( V_69 ) ;
F_64 ( V_91 ) ;
return V_5 ;
}
static T_2 int F_110 ( struct V_1 * V_2 ,
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
struct V_69 * V_91 ;
T_4 V_139 ;
int V_140 ;
int V_5 ;
V_91 = F_43 ( V_4 , V_35 -> V_43 ) ;
if ( ! V_91 )
return - V_75 ;
V_95 = F_67 ( V_21 , V_93 ) ;
V_94 = F_24 ( V_95 , V_51 ) ;
if ( ! V_94 )
return - V_52 ;
V_139 = F_111 ( V_21 , V_93 ) ;
F_26 ( V_21 , V_94 , ( unsigned long ) ( V_93 + 1 ) ,
V_95 ) ;
F_66 ( V_21 , V_93 , & V_138 ) ;
V_140 = F_112 ( V_2 , V_4 , V_32 , & V_138 , 0 ) ;
if ( V_140 == 0 )
V_140 = 1 ;
else
V_140 = 0 ;
F_23 ( V_32 ) ;
if ( V_35 -> type == V_141 ) {
V_136 = F_74 ( V_2 , V_4 , V_32 , V_35 -> V_43 ,
V_94 , V_95 , 1 ) ;
} else if ( V_35 -> type == V_142 ) {
V_136 = F_72 ( V_2 , V_4 , V_32 ,
V_35 -> V_43 ,
V_35 -> V_65 , V_94 ,
V_95 , 1 ) ;
} else {
F_108 () ;
}
if ( F_84 ( V_136 ) ) {
if ( V_35 -> type != V_142 )
goto V_74;
goto V_50;
}
F_66 ( V_32 -> V_48 [ 0 ] , V_136 , & V_137 ) ;
if ( V_137 . V_43 == V_138 . V_43 &&
V_137 . type == V_138 . type &&
V_137 . V_65 == V_138 . V_65 &&
F_111 ( V_32 -> V_48 [ 0 ] , V_136 ) == V_139 ) {
goto V_74;
}
if ( ! V_140 )
goto V_74;
V_5 = F_65 ( V_2 , V_4 , V_32 , V_91 , V_136 ) ;
F_48 ( V_5 ) ;
if ( V_35 -> type == V_142 )
goto V_50;
V_74:
F_23 ( V_32 ) ;
F_25 ( V_94 ) ;
F_64 ( V_91 ) ;
return 0 ;
V_50:
F_23 ( V_32 ) ;
V_5 = F_109 ( V_2 , V_4 , V_32 , V_35 -> V_43 , V_35 -> V_65 ,
V_94 , V_95 , V_139 , & V_138 ) ;
F_48 ( V_5 && V_5 != - V_18 ) ;
goto V_74;
}
static T_2 int F_113 ( struct V_1 * V_2 ,
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
if ( F_114 ( V_4 , V_21 , V_93 ) )
return - V_75 ;
V_95 = F_67 ( V_21 , V_93 ) ;
V_5 = F_110 ( V_2 , V_4 , V_32 , V_21 , V_93 , V_35 ) ;
F_48 ( V_5 ) ;
V_104 = ( unsigned long ) ( V_93 + 1 ) ;
V_104 += V_95 ;
}
return 0 ;
}
static T_2 int F_115 ( struct V_3 * V_4 ,
struct V_31 * V_32 ,
T_1 V_97 , int V_143 ,
T_1 * V_144 , T_1 * V_145 )
{
struct V_34 V_35 ;
T_1 V_146 ;
struct V_147 * V_68 ;
int V_5 ;
int V_148 ;
if ( * V_144 == ( T_1 ) - 1 )
return 1 ;
V_35 . V_43 = V_97 ;
V_35 . type = V_143 ;
V_35 . V_65 = * V_144 ;
V_5 = F_22 ( NULL , V_4 , & V_35 , V_32 , 0 , 0 ) ;
if ( V_5 < 0 )
goto V_74;
if ( V_5 > 0 ) {
if ( V_32 -> V_49 [ 0 ] == 0 )
goto V_74;
V_32 -> V_49 [ 0 ] -- ;
}
if ( V_5 != 0 )
F_100 ( V_32 -> V_48 [ 0 ] , & V_35 , V_32 -> V_49 [ 0 ] ) ;
if ( V_35 . type != V_143 || V_35 . V_43 != V_97 ) {
V_5 = 1 ;
goto V_88;
}
V_68 = F_39 ( V_32 -> V_48 [ 0 ] , V_32 -> V_49 [ 0 ] ,
struct V_147 ) ;
V_146 = F_116 ( V_32 -> V_48 [ 0 ] , V_68 ) ;
if ( * V_144 >= V_35 . V_65 && * V_144 <= V_146 ) {
V_5 = 0 ;
* V_144 = V_35 . V_65 ;
* V_145 = V_146 ;
goto V_74;
}
V_5 = 1 ;
V_88:
V_148 = F_117 ( V_32 -> V_48 [ 0 ] ) ;
if ( V_32 -> V_49 [ 0 ] >= V_148 ) {
V_5 = F_118 ( V_4 , V_32 ) ;
if ( V_5 )
goto V_74;
} else {
V_32 -> V_49 [ 0 ] ++ ;
}
F_100 ( V_32 -> V_48 [ 0 ] , & V_35 , V_32 -> V_49 [ 0 ] ) ;
if ( V_35 . type != V_143 || V_35 . V_43 != V_97 ) {
V_5 = 1 ;
goto V_74;
}
V_68 = F_39 ( V_32 -> V_48 [ 0 ] , V_32 -> V_49 [ 0 ] ,
struct V_147 ) ;
V_146 = F_116 ( V_32 -> V_48 [ 0 ] , V_68 ) ;
* V_144 = V_35 . V_65 ;
* V_145 = V_146 ;
V_5 = 0 ;
V_74:
F_23 ( V_32 ) ;
return V_5 ;
}
static T_2 int F_119 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_3 * log ,
struct V_31 * V_32 ,
struct V_31 * V_149 ,
struct V_69 * V_91 ,
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
struct V_69 * V_69 ;
struct V_34 V_96 ;
V_118:
V_21 = V_32 -> V_48 [ 0 ] ;
V_33 = V_32 -> V_49 [ 0 ] ;
V_36 = F_20 ( V_21 , V_33 ) ;
V_104 = F_21 ( V_21 , V_33 ) ;
V_105 = V_104 + V_36 ;
while ( V_104 < V_105 ) {
V_93 = (struct V_92 * ) V_104 ;
if ( F_114 ( V_4 , V_21 , V_93 ) ) {
V_5 = - V_75 ;
goto V_74;
}
V_95 = F_67 ( V_21 , V_93 ) ;
V_94 = F_24 ( V_95 , V_51 ) ;
if ( ! V_94 ) {
V_5 = - V_52 ;
goto V_74;
}
F_26 ( V_21 , V_94 , ( unsigned long ) ( V_93 + 1 ) ,
V_95 ) ;
V_151 = NULL ;
if ( log && V_150 -> type == V_141 ) {
V_151 = F_74 ( V_2 , log , V_149 ,
V_150 -> V_43 ,
V_94 , V_95 , 0 ) ;
} else if ( log && V_150 -> type == V_142 ) {
V_151 = F_72 ( V_2 , log ,
V_149 ,
V_150 -> V_43 ,
V_150 -> V_65 ,
V_94 , V_95 , 0 ) ;
}
if ( F_84 ( V_151 ) ) {
F_66 ( V_21 , V_93 , & V_96 ) ;
F_23 ( V_32 ) ;
F_23 ( V_149 ) ;
V_69 = F_43 ( V_4 , V_96 . V_43 ) ;
if ( ! V_69 ) {
F_25 ( V_94 ) ;
return - V_75 ;
}
V_5 = F_68 ( V_2 , V_4 ,
V_32 , V_96 . V_43 ) ;
F_48 ( V_5 ) ;
F_82 ( V_69 ) ;
V_5 = F_69 ( V_2 , V_4 , V_91 , V_69 ,
V_94 , V_95 ) ;
F_48 ( V_5 ) ;
F_70 ( V_2 , V_4 ) ;
F_25 ( V_94 ) ;
F_64 ( V_69 ) ;
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
static T_2 int F_104 ( struct V_1 * V_2 ,
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
struct V_69 * V_91 ;
V_150 . V_43 = V_97 ;
V_150 . type = V_141 ;
V_149 = F_76 () ;
if ( ! V_149 )
return - V_52 ;
V_91 = F_43 ( V_4 , V_97 ) ;
if ( ! V_91 ) {
F_80 ( V_149 ) ;
return 0 ;
}
V_118:
V_153 = 0 ;
V_154 = 0 ;
while ( 1 ) {
if ( V_152 )
V_154 = ( T_1 ) - 1 ;
else {
V_5 = F_115 ( log , V_32 , V_97 , V_143 ,
& V_153 , & V_154 ) ;
if ( V_5 != 0 )
break;
}
V_150 . V_65 = V_153 ;
while ( 1 ) {
int V_148 ;
V_5 = F_22 ( NULL , V_4 , & V_150 , V_32 ,
0 , 0 ) ;
if ( V_5 < 0 )
goto V_74;
V_148 = F_117 ( V_32 -> V_48 [ 0 ] ) ;
if ( V_32 -> V_49 [ 0 ] >= V_148 ) {
V_5 = F_118 ( V_4 , V_32 ) ;
if ( V_5 )
break;
}
F_100 ( V_32 -> V_48 [ 0 ] , & V_137 ,
V_32 -> V_49 [ 0 ] ) ;
if ( V_137 . V_43 != V_97 ||
V_137 . type != V_150 . type )
goto V_156;
if ( V_137 . V_65 > V_154 )
break;
V_5 = F_119 ( V_2 , V_4 , log , V_32 ,
V_149 , V_91 ,
& V_137 ) ;
F_48 ( V_5 ) ;
if ( V_137 . V_65 == ( T_1 ) - 1 )
break;
V_150 . V_65 = V_137 . V_65 + 1 ;
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
F_80 ( V_149 ) ;
F_64 ( V_91 ) ;
return V_5 ;
}
static int F_120 ( struct V_3 * log , struct V_20 * V_21 ,
struct V_22 * V_23 , T_1 V_24 )
{
int V_148 ;
struct V_31 * V_32 ;
struct V_3 * V_4 = V_23 -> V_158 ;
struct V_34 V_35 ;
int V_159 ;
int V_160 ;
int V_5 ;
V_5 = F_121 ( V_21 , V_24 ) ;
if ( V_5 )
return V_5 ;
V_159 = F_122 ( V_21 ) ;
if ( V_159 != 0 )
return 0 ;
V_32 = F_76 () ;
if ( ! V_32 )
return - V_52 ;
V_148 = F_117 ( V_21 ) ;
for ( V_160 = 0 ; V_160 < V_148 ; V_160 ++ ) {
F_100 ( V_21 , & V_35 , V_160 ) ;
if ( V_35 . type == V_55 &&
V_23 -> V_161 == V_162 ) {
struct V_56 * V_163 ;
T_3 V_164 ;
V_163 = F_39 ( V_21 , V_160 ,
struct V_56 ) ;
V_164 = F_32 ( V_21 , V_163 ) ;
if ( F_31 ( V_164 ) ) {
V_5 = F_104 ( V_23 -> V_2 ,
V_4 , log , V_32 , V_35 . V_43 , 0 ) ;
F_48 ( V_5 ) ;
}
V_5 = F_19 ( V_23 -> V_2 , V_4 , V_32 ,
V_21 , V_160 , & V_35 ) ;
F_48 ( V_5 ) ;
if ( F_123 ( V_164 ) ) {
V_5 = F_94 ( V_23 -> V_2 , V_4 ,
V_35 . V_43 ) ;
F_48 ( V_5 ) ;
}
V_5 = F_68 ( V_23 -> V_2 , V_4 ,
V_32 , V_35 . V_43 ) ;
F_48 ( V_5 ) ;
}
if ( V_23 -> V_161 < V_165 )
continue;
if ( V_35 . type == V_166 ) {
V_5 = F_19 ( V_23 -> V_2 , V_4 , V_32 ,
V_21 , V_160 , & V_35 ) ;
F_48 ( V_5 ) ;
} else if ( V_35 . type == V_119 ) {
V_5 = F_92 ( V_23 -> V_2 , V_4 , log , V_32 ,
V_21 , V_160 , & V_35 ) ;
F_48 ( V_5 && V_5 != - V_18 ) ;
} else if ( V_35 . type == V_108 ) {
V_5 = F_92 ( V_23 -> V_2 , V_4 , log , V_32 ,
V_21 , V_160 , & V_35 ) ;
F_48 ( V_5 && V_5 != - V_18 ) ;
} else if ( V_35 . type == V_167 ) {
V_5 = F_38 ( V_23 -> V_2 , V_4 , V_32 ,
V_21 , V_160 , & V_35 ) ;
F_48 ( V_5 ) ;
} else if ( V_35 . type == V_141 ||
V_35 . type == V_142 ) {
V_5 = F_113 ( V_23 -> V_2 , V_4 , V_32 ,
V_21 , V_160 , & V_35 ) ;
F_48 ( V_5 ) ;
}
}
F_80 ( V_32 ) ;
return 0 ;
}
static T_2 int F_124 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_31 * V_32 , int * V_159 ,
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
F_125 ( * V_159 < 0 ) ;
F_125 ( * V_159 >= V_174 ) ;
while ( * V_159 > 0 ) {
F_125 ( * V_159 < 0 ) ;
F_125 ( * V_159 >= V_174 ) ;
V_171 = V_32 -> V_48 [ * V_159 ] ;
if ( F_122 ( V_171 ) != * V_159 )
F_125 ( 1 ) ;
if ( V_32 -> V_49 [ * V_159 ] >=
F_117 ( V_171 ) )
break;
V_169 = F_126 ( V_171 , V_32 -> V_49 [ * V_159 ] ) ;
V_170 = F_127 ( V_171 , V_32 -> V_49 [ * V_159 ] ) ;
V_173 = F_128 ( V_4 , * V_159 - 1 ) ;
V_172 = V_32 -> V_48 [ * V_159 ] ;
V_168 = F_129 ( V_172 ) ;
V_88 = F_130 ( V_4 , V_169 , V_173 ) ;
if ( ! V_88 )
return - V_52 ;
if ( * V_159 == 1 ) {
V_5 = V_23 -> V_175 ( V_4 , V_88 , V_23 , V_170 ) ;
if ( V_5 )
return V_5 ;
V_32 -> V_49 [ * V_159 ] ++ ;
if ( V_23 -> free ) {
V_5 = F_121 ( V_88 , V_170 ) ;
if ( V_5 ) {
F_131 ( V_88 ) ;
return V_5 ;
}
F_132 ( V_88 ) ;
F_133 ( V_88 ) ;
F_134 ( V_2 , V_4 , V_88 ) ;
F_18 ( V_88 ) ;
F_135 ( V_88 ) ;
F_125 ( V_168 !=
V_44 ) ;
V_5 = F_136 ( V_4 ,
V_169 , V_173 ) ;
F_48 ( V_5 ) ;
}
F_131 ( V_88 ) ;
continue;
}
V_5 = F_121 ( V_88 , V_170 ) ;
if ( V_5 ) {
F_131 ( V_88 ) ;
return V_5 ;
}
F_125 ( * V_159 <= 0 ) ;
if ( V_32 -> V_48 [ * V_159 - 1 ] )
F_131 ( V_32 -> V_48 [ * V_159 - 1 ] ) ;
V_32 -> V_48 [ * V_159 - 1 ] = V_88 ;
* V_159 = F_122 ( V_88 ) ;
V_32 -> V_49 [ * V_159 ] = 0 ;
F_137 () ;
}
F_125 ( * V_159 < 0 ) ;
F_125 ( * V_159 >= V_174 ) ;
V_32 -> V_49 [ * V_159 ] = F_117 ( V_32 -> V_48 [ * V_159 ] ) ;
F_137 () ;
return 0 ;
}
static T_2 int F_138 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_31 * V_32 , int * V_159 ,
struct V_22 * V_23 )
{
T_1 V_168 ;
int V_160 ;
int V_33 ;
int V_5 ;
for ( V_160 = * V_159 ; V_160 < V_174 - 1 && V_32 -> V_48 [ V_160 ] ; V_160 ++ ) {
V_33 = V_32 -> V_49 [ V_160 ] ;
if ( V_33 + 1 < F_117 ( V_32 -> V_48 [ V_160 ] ) ) {
V_32 -> V_49 [ V_160 ] ++ ;
* V_159 = V_160 ;
F_125 ( * V_159 == 0 ) ;
return 0 ;
} else {
struct V_20 * V_172 ;
if ( V_32 -> V_48 [ * V_159 ] == V_4 -> V_176 )
V_172 = V_32 -> V_48 [ * V_159 ] ;
else
V_172 = V_32 -> V_48 [ * V_159 + 1 ] ;
V_168 = F_129 ( V_172 ) ;
V_5 = V_23 -> V_175 ( V_4 , V_32 -> V_48 [ * V_159 ] , V_23 ,
F_139 ( V_32 -> V_48 [ * V_159 ] ) ) ;
if ( V_5 )
return V_5 ;
if ( V_23 -> free ) {
struct V_20 * V_88 ;
V_88 = V_32 -> V_48 [ * V_159 ] ;
F_132 ( V_88 ) ;
F_133 ( V_88 ) ;
F_134 ( V_2 , V_4 , V_88 ) ;
F_18 ( V_88 ) ;
F_135 ( V_88 ) ;
F_125 ( V_168 != V_44 ) ;
V_5 = F_136 ( V_4 ,
V_32 -> V_48 [ * V_159 ] -> V_27 ,
V_32 -> V_48 [ * V_159 ] -> V_28 ) ;
F_48 ( V_5 ) ;
}
F_131 ( V_32 -> V_48 [ * V_159 ] ) ;
V_32 -> V_48 [ * V_159 ] = NULL ;
* V_159 = V_160 + 1 ;
}
}
return 1 ;
}
static int F_140 ( struct V_1 * V_2 ,
struct V_3 * log , struct V_22 * V_23 )
{
int V_5 = 0 ;
int V_177 ;
int V_159 ;
struct V_31 * V_32 ;
int V_160 ;
int V_178 ;
V_32 = F_76 () ;
if ( ! V_32 )
return - V_52 ;
V_159 = F_122 ( log -> V_176 ) ;
V_178 = V_159 ;
V_32 -> V_48 [ V_159 ] = log -> V_176 ;
F_141 ( log -> V_176 ) ;
V_32 -> V_49 [ V_159 ] = 0 ;
while ( 1 ) {
V_177 = F_124 ( V_2 , log , V_32 , & V_159 , V_23 ) ;
if ( V_177 > 0 )
break;
if ( V_177 < 0 ) {
V_5 = V_177 ;
goto V_74;
}
V_177 = F_138 ( V_2 , log , V_32 , & V_159 , V_23 ) ;
if ( V_177 > 0 )
break;
if ( V_177 < 0 ) {
V_5 = V_177 ;
goto V_74;
}
}
if ( V_32 -> V_48 [ V_178 ] ) {
V_5 = V_23 -> V_175 ( log , V_32 -> V_48 [ V_178 ] , V_23 ,
F_139 ( V_32 -> V_48 [ V_178 ] ) ) ;
if ( V_5 )
goto V_74;
if ( V_23 -> free ) {
struct V_20 * V_88 ;
V_88 = V_32 -> V_48 [ V_178 ] ;
F_132 ( V_88 ) ;
F_133 ( V_88 ) ;
F_134 ( V_2 , log , V_88 ) ;
F_18 ( V_88 ) ;
F_135 ( V_88 ) ;
F_125 ( log -> V_42 . V_43 !=
V_44 ) ;
V_5 = F_136 ( log , V_88 -> V_27 ,
V_88 -> V_28 ) ;
F_48 ( V_5 ) ;
}
}
V_74:
for ( V_160 = 0 ; V_160 <= V_178 ; V_160 ++ ) {
if ( V_32 -> V_48 [ V_160 ] ) {
F_131 ( V_32 -> V_48 [ V_160 ] ) ;
V_32 -> V_48 [ V_160 ] = NULL ;
}
}
F_80 ( V_32 ) ;
return V_5 ;
}
static int F_142 ( struct V_1 * V_2 ,
struct V_3 * log )
{
int V_5 ;
if ( log -> V_179 == 1 ) {
V_5 = F_143 ( V_2 , log -> V_15 -> V_17 ,
& log -> V_42 , & log -> V_180 ) ;
} else {
V_5 = F_144 ( V_2 , log -> V_15 -> V_17 ,
& log -> V_42 , & log -> V_180 ) ;
}
return V_5 ;
}
static int F_145 ( struct V_1 * V_2 ,
struct V_3 * V_4 , unsigned long V_60 )
{
F_146 ( V_30 ) ;
int V_98 = V_60 % 2 ;
do {
F_147 ( & V_4 -> V_181 [ V_98 ] ,
& V_30 , V_182 ) ;
F_4 ( & V_4 -> V_7 ) ;
if ( V_4 -> V_15 -> V_183 !=
V_2 -> V_60 && V_4 -> V_179 < V_60 + 2 &&
F_148 ( & V_4 -> V_184 [ V_98 ] ) )
F_149 () ;
F_150 ( & V_4 -> V_181 [ V_98 ] , & V_30 ) ;
F_2 ( & V_4 -> V_7 ) ;
} while ( V_4 -> V_15 -> V_183 !=
V_2 -> V_60 && V_4 -> V_179 < V_60 + 2 &&
F_148 ( & V_4 -> V_184 [ V_98 ] ) );
return 0 ;
}
static void F_151 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_146 ( V_30 ) ;
while ( V_4 -> V_15 -> V_183 !=
V_2 -> V_60 && F_148 ( & V_4 -> V_14 ) ) {
F_147 ( & V_4 -> V_19 ,
& V_30 , V_182 ) ;
F_4 ( & V_4 -> V_7 ) ;
if ( V_4 -> V_15 -> V_183 !=
V_2 -> V_60 && F_148 ( & V_4 -> V_14 ) )
F_149 () ;
F_2 ( & V_4 -> V_7 ) ;
F_150 ( & V_4 -> V_19 , & V_30 ) ;
}
}
int F_152 ( struct V_1 * V_2 ,
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
V_185 = V_4 -> V_179 % 2 ;
if ( F_148 ( & V_4 -> V_184 [ V_185 ] ) ) {
F_145 ( V_2 , V_4 , V_4 -> V_179 ) ;
F_4 ( & V_4 -> V_7 ) ;
return 0 ;
}
F_153 ( & V_4 -> V_184 [ V_185 ] , 1 ) ;
if ( F_148 ( & V_4 -> V_184 [ ( V_185 + 1 ) % 2 ] ) )
F_145 ( V_2 , V_4 , V_4 -> V_179 - 1 ) ;
while ( 1 ) {
int V_188 = F_148 ( & V_4 -> V_13 ) ;
if ( ! F_154 ( V_4 , V_189 ) && V_4 -> V_12 ) {
F_4 ( & V_4 -> V_7 ) ;
F_155 ( 1 ) ;
F_2 ( & V_4 -> V_7 ) ;
}
F_151 ( V_2 , V_4 ) ;
if ( V_188 == F_148 ( & V_4 -> V_13 ) )
break;
}
if ( V_4 -> V_15 -> V_183 == V_2 -> V_60 ) {
V_5 = - V_190 ;
F_4 ( & V_4 -> V_7 ) ;
goto V_74;
}
V_179 = V_4 -> V_179 ;
if ( V_179 % 2 == 0 )
V_187 = V_191 ;
else
V_187 = V_192 ;
V_5 = F_156 ( log , & log -> V_193 , V_187 ) ;
if ( V_5 ) {
F_157 ( V_2 , V_4 , V_5 ) ;
F_4 ( & V_4 -> V_7 ) ;
goto V_74;
}
F_158 ( & log -> V_180 , log -> V_176 ) ;
V_4 -> V_179 ++ ;
log -> V_179 = V_4 -> V_179 ;
V_4 -> V_9 = 0 ;
F_8 () ;
F_4 ( & V_4 -> V_7 ) ;
F_2 ( & V_17 -> V_7 ) ;
F_3 ( & V_17 -> V_13 ) ;
F_3 ( & V_17 -> V_14 ) ;
F_4 ( & V_17 -> V_7 ) ;
V_5 = F_142 ( V_2 , log ) ;
F_2 ( & V_17 -> V_7 ) ;
if ( F_11 ( & V_17 -> V_14 ) ) {
F_8 () ;
if ( F_12 ( & V_17 -> V_19 ) )
F_13 ( & V_17 -> V_19 ) ;
}
if ( V_5 ) {
if ( V_5 != - V_194 ) {
F_157 ( V_2 , V_4 , V_5 ) ;
F_4 ( & V_17 -> V_7 ) ;
goto V_74;
}
V_4 -> V_15 -> V_183 = V_2 -> V_60 ;
F_159 ( log , & log -> V_193 , V_187 ) ;
F_4 ( & V_17 -> V_7 ) ;
V_5 = - V_190 ;
goto V_74;
}
V_186 = V_17 -> V_179 % 2 ;
if ( F_148 ( & V_17 -> V_184 [ V_186 ] ) ) {
F_159 ( log , & log -> V_193 , V_187 ) ;
F_145 ( V_2 , V_17 ,
V_17 -> V_179 ) ;
F_4 ( & V_17 -> V_7 ) ;
V_5 = 0 ;
goto V_74;
}
F_153 ( & V_17 -> V_184 [ V_186 ] , 1 ) ;
if ( F_148 ( & V_17 -> V_184 [ ( V_186 + 1 ) % 2 ] ) ) {
F_145 ( V_2 , V_17 ,
V_17 -> V_179 - 1 ) ;
}
F_151 ( V_2 , V_17 ) ;
if ( V_4 -> V_15 -> V_183 == V_2 -> V_60 ) {
F_159 ( log , & log -> V_193 , V_187 ) ;
F_4 ( & V_17 -> V_7 ) ;
V_5 = - V_190 ;
goto V_195;
}
V_5 = F_160 ( V_17 ,
& V_17 -> V_193 ,
V_191 | V_192 ) ;
if ( V_5 ) {
F_157 ( V_2 , V_4 , V_5 ) ;
F_4 ( & V_17 -> V_7 ) ;
goto V_195;
}
F_159 ( log , & log -> V_193 , V_187 ) ;
F_161 ( V_4 -> V_15 -> V_196 ,
V_17 -> V_176 -> V_27 ) ;
F_162 ( V_4 -> V_15 -> V_196 ,
F_122 ( V_17 -> V_176 ) ) ;
V_17 -> V_179 ++ ;
F_8 () ;
F_4 ( & V_17 -> V_7 ) ;
F_163 ( V_4 ) ;
V_5 = F_164 ( V_2 , V_4 -> V_15 -> V_197 , 1 ) ;
F_165 ( V_4 ) ;
if ( V_5 ) {
F_157 ( V_2 , V_4 , V_5 ) ;
goto V_195;
}
F_2 ( & V_4 -> V_7 ) ;
if ( V_4 -> V_198 < V_179 )
V_4 -> V_198 = V_179 ;
F_4 ( & V_4 -> V_7 ) ;
V_195:
F_153 ( & V_17 -> V_184 [ V_186 ] , 0 ) ;
F_8 () ;
if ( F_12 ( & V_17 -> V_181 [ V_186 ] ) )
F_13 ( & V_17 -> V_181 [ V_186 ] ) ;
V_74:
F_153 ( & V_4 -> V_184 [ V_185 ] , 0 ) ;
F_8 () ;
if ( F_12 ( & V_4 -> V_181 [ V_185 ] ) )
F_13 ( & V_4 -> V_181 [ V_185 ] ) ;
return V_5 ;
}
static void F_166 ( struct V_1 * V_2 ,
struct V_3 * log )
{
int V_5 ;
T_1 V_27 ;
T_1 V_199 ;
struct V_22 V_23 = {
. free = 1 ,
. V_175 = F_14
} ;
V_5 = F_140 ( V_2 , log , & V_23 ) ;
F_48 ( V_5 ) ;
while ( 1 ) {
V_5 = F_167 ( & log -> V_193 ,
0 , & V_27 , & V_199 , V_191 | V_192 ,
NULL ) ;
if ( V_5 )
break;
F_168 ( & log -> V_193 , V_27 , V_199 ,
V_191 | V_192 , V_51 ) ;
}
F_131 ( log -> V_176 ) ;
F_25 ( log ) ;
}
int F_169 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( V_4 -> V_8 ) {
F_166 ( V_2 , V_4 -> V_8 ) ;
V_4 -> V_8 = NULL ;
}
return 0 ;
}
int F_170 ( struct V_1 * V_2 ,
struct V_200 * V_15 )
{
if ( V_15 -> V_17 ) {
F_166 ( V_2 , V_15 -> V_17 ) ;
V_15 -> V_17 = NULL ;
}
return 0 ;
}
int F_171 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_94 , int V_95 ,
struct V_69 * V_91 , T_1 V_98 )
{
struct V_3 * log ;
struct V_92 * V_93 ;
struct V_31 * V_32 ;
int V_5 ;
int V_6 = 0 ;
int V_201 = 0 ;
T_1 V_202 = F_45 ( V_91 ) ;
if ( F_103 ( V_91 ) -> V_203 < V_2 -> V_60 )
return 0 ;
V_5 = F_7 ( V_4 ) ;
if ( V_5 )
return 0 ;
F_2 ( & F_103 ( V_91 ) -> V_7 ) ;
log = V_4 -> V_8 ;
V_32 = F_76 () ;
if ( ! V_32 ) {
V_6 = - V_52 ;
goto V_204;
}
V_93 = F_74 ( V_2 , log , V_32 , V_202 ,
V_94 , V_95 , - 1 ) ;
if ( F_73 ( V_93 ) ) {
V_6 = F_172 ( V_93 ) ;
goto V_205;
}
if ( V_93 ) {
V_5 = F_173 ( V_2 , log , V_32 , V_93 ) ;
V_201 += V_95 ;
F_48 ( V_5 ) ;
}
F_23 ( V_32 ) ;
V_93 = F_72 ( V_2 , log , V_32 , V_202 ,
V_98 , V_94 , V_95 , - 1 ) ;
if ( F_73 ( V_93 ) ) {
V_6 = F_172 ( V_93 ) ;
goto V_205;
}
if ( V_93 ) {
V_5 = F_173 ( V_2 , log , V_32 , V_93 ) ;
V_201 += V_95 ;
F_48 ( V_5 ) ;
}
if ( V_201 ) {
struct V_34 V_35 ;
V_35 . V_43 = V_202 ;
V_35 . V_65 = 0 ;
V_35 . type = V_55 ;
F_23 ( V_32 ) ;
V_5 = F_22 ( V_2 , log , & V_35 , V_32 , 0 , 1 ) ;
if ( V_5 < 0 ) {
V_6 = V_5 ;
goto V_205;
}
if ( V_5 == 0 ) {
struct V_56 * V_68 ;
T_1 V_206 ;
V_68 = F_39 ( V_32 -> V_48 [ 0 ] , V_32 -> V_49 [ 0 ] ,
struct V_56 ) ;
V_206 = F_33 ( V_32 -> V_48 [ 0 ] , V_68 ) ;
if ( V_206 > V_201 )
V_206 -= V_201 ;
else
V_206 = 0 ;
F_35 ( V_32 -> V_48 [ 0 ] , V_68 , V_206 ) ;
F_37 ( V_32 -> V_48 [ 0 ] ) ;
} else
V_5 = 0 ;
F_23 ( V_32 ) ;
}
V_205:
F_80 ( V_32 ) ;
V_204:
F_4 ( & F_103 ( V_91 ) -> V_7 ) ;
if ( V_5 == - V_194 ) {
V_4 -> V_15 -> V_183 = V_2 -> V_60 ;
V_5 = 0 ;
} else if ( V_5 < 0 )
F_157 ( V_2 , V_4 , V_5 ) ;
F_10 ( V_4 ) ;
return V_6 ;
}
int F_174 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_94 , int V_95 ,
struct V_69 * V_69 , T_1 V_97 )
{
struct V_3 * log ;
T_1 V_98 ;
int V_5 ;
if ( F_103 ( V_69 ) -> V_203 < V_2 -> V_60 )
return 0 ;
V_5 = F_7 ( V_4 ) ;
if ( V_5 )
return 0 ;
log = V_4 -> V_8 ;
F_2 ( & F_103 ( V_69 ) -> V_7 ) ;
V_5 = F_175 ( V_2 , log , V_94 , V_95 , F_45 ( V_69 ) ,
V_97 , & V_98 ) ;
F_4 ( & F_103 ( V_69 ) -> V_7 ) ;
if ( V_5 == - V_194 ) {
V_4 -> V_15 -> V_183 = V_2 -> V_60 ;
V_5 = 0 ;
} else if ( V_5 < 0 && V_5 != - V_18 )
F_157 ( V_2 , V_4 , V_5 ) ;
F_10 ( V_4 ) ;
return V_5 ;
}
static T_2 int F_176 ( struct V_1 * V_2 ,
struct V_3 * log ,
struct V_31 * V_32 ,
int V_143 , T_1 V_97 ,
T_1 V_207 , T_1 V_208 )
{
int V_5 ;
struct V_34 V_35 ;
struct V_147 * V_68 ;
V_35 . V_43 = V_97 ;
V_35 . V_65 = V_207 ;
if ( V_143 == V_141 )
V_35 . type = V_155 ;
else
V_35 . type = V_157 ;
V_5 = F_27 ( V_2 , log , V_32 , & V_35 , sizeof( * V_68 ) ) ;
if ( V_5 )
return V_5 ;
V_68 = F_39 ( V_32 -> V_48 [ 0 ] , V_32 -> V_49 [ 0 ] ,
struct V_147 ) ;
F_177 ( V_32 -> V_48 [ 0 ] , V_68 , V_208 ) ;
F_37 ( V_32 -> V_48 [ 0 ] ) ;
F_23 ( V_32 ) ;
return 0 ;
}
static T_2 int F_178 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_69 * V_69 ,
struct V_31 * V_32 ,
struct V_31 * V_209 , int V_143 ,
T_1 V_210 , T_1 * V_211 )
{
struct V_34 V_212 ;
struct V_34 V_213 ;
struct V_3 * log = V_4 -> V_8 ;
struct V_20 * V_214 ;
int V_6 = 0 ;
int V_5 ;
int V_160 ;
int V_148 ;
T_1 V_207 = V_210 ;
T_1 V_208 = ( T_1 ) - 1 ;
T_1 V_130 = F_45 ( V_69 ) ;
log = V_4 -> V_8 ;
V_213 . V_43 = V_130 ;
V_213 . V_65 = ( T_1 ) - 1 ;
V_213 . type = V_143 ;
V_212 . V_43 = V_130 ;
V_212 . type = V_143 ;
V_212 . V_65 = V_210 ;
V_32 -> V_215 = 1 ;
V_5 = F_179 ( V_4 , & V_212 , & V_213 ,
V_32 , 0 , V_2 -> V_60 ) ;
if ( V_5 != 0 || V_212 . V_43 != V_130 || V_212 . type != V_143 ) {
V_212 . V_43 = V_130 ;
V_212 . type = V_143 ;
V_212 . V_65 = ( T_1 ) - 1 ;
F_23 ( V_32 ) ;
V_5 = F_22 ( NULL , V_4 , & V_212 , V_32 , 0 , 0 ) ;
if ( V_5 < 0 ) {
F_23 ( V_32 ) ;
return V_5 ;
}
V_5 = F_180 ( V_4 , V_32 , V_130 , V_143 ) ;
if ( V_5 == 0 ) {
struct V_34 V_216 ;
F_100 ( V_32 -> V_48 [ 0 ] , & V_216 ,
V_32 -> V_49 [ 0 ] ) ;
if ( V_143 == V_216 . type )
V_207 = F_181 ( V_210 , V_216 . V_65 ) + 1 ;
}
goto V_217;
}
V_5 = F_180 ( V_4 , V_32 , V_130 , V_143 ) ;
if ( V_5 == 0 ) {
struct V_34 V_216 ;
F_100 ( V_32 -> V_48 [ 0 ] , & V_216 , V_32 -> V_49 [ 0 ] ) ;
if ( V_143 == V_216 . type ) {
V_207 = V_216 . V_65 ;
V_5 = F_19 ( V_2 , log , V_209 ,
V_32 -> V_48 [ 0 ] , V_32 -> V_49 [ 0 ] ,
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
F_125 ( 1 ) ;
goto V_217;
}
while ( 1 ) {
struct V_34 V_216 ;
V_214 = V_32 -> V_48 [ 0 ] ;
V_148 = F_117 ( V_214 ) ;
for ( V_160 = V_32 -> V_49 [ 0 ] ; V_160 < V_148 ; V_160 ++ ) {
F_100 ( V_214 , & V_212 , V_160 ) ;
if ( V_212 . V_43 != V_130 || V_212 . type != V_143 )
goto V_217;
V_5 = F_19 ( V_2 , log , V_209 , V_214 , V_160 ,
& V_212 ) ;
if ( V_5 ) {
V_6 = V_5 ;
goto V_217;
}
}
V_32 -> V_49 [ 0 ] = V_148 ;
V_5 = F_118 ( V_4 , V_32 ) ;
if ( V_5 == 1 ) {
V_208 = ( T_1 ) - 1 ;
goto V_217;
}
F_100 ( V_32 -> V_48 [ 0 ] , & V_216 , V_32 -> V_49 [ 0 ] ) ;
if ( V_216 . V_43 != V_130 || V_216 . type != V_143 ) {
V_208 = ( T_1 ) - 1 ;
goto V_217;
}
if ( F_139 ( V_32 -> V_48 [ 0 ] ) != V_2 -> V_60 ) {
V_5 = F_19 ( V_2 , log , V_209 ,
V_32 -> V_48 [ 0 ] , V_32 -> V_49 [ 0 ] ,
& V_216 ) ;
if ( V_5 )
V_6 = V_5 ;
else
V_208 = V_216 . V_65 ;
goto V_217;
}
}
V_217:
F_23 ( V_32 ) ;
F_23 ( V_209 ) ;
if ( V_6 == 0 ) {
* V_211 = V_208 ;
V_5 = F_176 ( V_2 , log , V_32 , V_143 ,
V_130 , V_207 , V_208 ) ;
if ( V_5 )
V_6 = V_5 ;
}
return V_6 ;
}
static T_2 int F_182 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_69 * V_69 ,
struct V_31 * V_32 ,
struct V_31 * V_209 )
{
T_1 V_212 ;
T_1 V_213 ;
int V_5 ;
int V_143 = V_141 ;
V_118:
V_212 = 0 ;
V_213 = 0 ;
while ( 1 ) {
V_5 = F_178 ( V_2 , V_4 , V_69 , V_32 ,
V_209 , V_143 , V_212 ,
& V_213 ) ;
if ( V_5 )
return V_5 ;
if ( V_213 == ( T_1 ) - 1 )
break;
V_212 = V_213 + 1 ;
}
if ( V_143 == V_141 ) {
V_143 = V_142 ;
goto V_118;
}
return 0 ;
}
static int F_183 ( struct V_1 * V_2 ,
struct V_3 * log ,
struct V_31 * V_32 ,
T_1 V_43 , int V_218 )
{
int V_5 ;
struct V_34 V_35 ;
struct V_34 V_137 ;
int V_219 ;
V_35 . V_43 = V_43 ;
V_35 . type = V_218 ;
V_35 . V_65 = ( T_1 ) - 1 ;
while ( 1 ) {
V_5 = F_22 ( V_2 , log , & V_35 , V_32 , - 1 , 1 ) ;
F_48 ( V_5 == 0 ) ;
if ( V_5 < 0 )
break;
if ( V_32 -> V_49 [ 0 ] == 0 )
break;
V_32 -> V_49 [ 0 ] -- ;
F_100 ( V_32 -> V_48 [ 0 ] , & V_137 ,
V_32 -> V_49 [ 0 ] ) ;
if ( V_137 . V_43 != V_43 )
break;
V_137 . V_65 = 0 ;
V_137 . type = 0 ;
V_5 = F_184 ( V_32 -> V_48 [ 0 ] , & V_137 , 0 ,
& V_219 ) ;
V_5 = F_185 ( V_2 , log , V_32 , V_219 ,
V_32 -> V_49 [ 0 ] - V_219 + 1 ) ;
if ( V_5 || V_219 != 0 )
break;
F_23 ( V_32 ) ;
}
F_23 ( V_32 ) ;
if ( V_5 > 0 )
V_5 = 0 ;
return V_5 ;
}
static void F_186 ( struct V_1 * V_2 ,
struct V_20 * V_79 ,
struct V_56 * V_68 ,
struct V_69 * V_69 , int V_220 )
{
F_187 ( V_79 , V_68 , F_188 ( V_69 ) ) ;
F_189 ( V_79 , V_68 , F_190 ( V_69 ) ) ;
F_191 ( V_79 , V_68 , V_69 -> V_133 ) ;
F_192 ( V_79 , V_68 , V_69 -> V_131 ) ;
F_193 ( V_79 , F_194 ( V_68 ) ,
V_69 -> V_221 . V_222 ) ;
F_195 ( V_79 , F_194 ( V_68 ) ,
V_69 -> V_221 . V_223 ) ;
F_193 ( V_79 , F_196 ( V_68 ) ,
V_69 -> V_224 . V_222 ) ;
F_195 ( V_79 , F_196 ( V_68 ) ,
V_69 -> V_224 . V_223 ) ;
F_193 ( V_79 , F_197 ( V_68 ) ,
V_69 -> V_225 . V_222 ) ;
F_195 ( V_79 , F_197 ( V_68 ) ,
V_69 -> V_225 . V_223 ) ;
F_198 ( V_79 , V_68 , F_46 ( V_69 ) ) ;
F_199 ( V_79 , V_68 , V_69 -> V_226 ) ;
F_200 ( V_79 , V_68 , V_2 -> V_60 ) ;
F_201 ( V_79 , V_68 , V_69 -> V_227 ) ;
F_202 ( V_79 , V_68 , F_103 ( V_69 ) -> V_228 ) ;
F_203 ( V_79 , V_68 , 0 ) ;
if ( V_220 ) {
F_36 ( V_79 , V_68 , 0 ) ;
F_35 ( V_79 , V_68 , 0 ) ;
} else {
F_36 ( V_79 , V_68 ,
F_103 ( V_69 ) -> V_229 ) ;
F_35 ( V_79 , V_68 , V_69 -> V_206 ) ;
}
}
static T_2 int F_204 ( struct V_1 * V_2 ,
struct V_69 * V_69 ,
struct V_31 * V_209 ,
struct V_20 * V_214 ,
int V_219 , int V_230 , int V_231 )
{
unsigned long V_232 ;
unsigned long V_233 ;
struct V_3 * log = F_103 ( V_69 ) -> V_4 -> V_8 ;
struct V_67 * V_234 ;
struct V_56 * V_163 ;
int V_5 ;
struct V_34 * V_235 ;
T_3 * V_236 ;
char * V_237 ;
int V_160 ;
struct V_238 V_85 ;
int V_239 = F_103 ( V_69 ) -> V_228 & V_240 ;
F_205 ( & V_85 ) ;
V_237 = F_24 ( V_230 * sizeof( struct V_34 ) +
V_230 * sizeof( T_3 ) , V_51 ) ;
if ( ! V_237 )
return - V_52 ;
V_236 = ( T_3 * ) V_237 ;
V_235 = (struct V_34 * ) ( V_237 + V_230 * sizeof( T_3 ) ) ;
for ( V_160 = 0 ; V_160 < V_230 ; V_160 ++ ) {
V_236 [ V_160 ] = F_20 ( V_214 , V_160 + V_219 ) ;
F_100 ( V_214 , V_235 + V_160 , V_160 + V_219 ) ;
}
V_5 = F_206 ( V_2 , log , V_209 ,
V_235 , V_236 , V_230 ) ;
if ( V_5 ) {
F_25 ( V_237 ) ;
return V_5 ;
}
for ( V_160 = 0 ; V_160 < V_230 ; V_160 ++ , V_209 -> V_49 [ 0 ] ++ ) {
V_233 = F_21 ( V_209 -> V_48 [ 0 ] ,
V_209 -> V_49 [ 0 ] ) ;
V_232 = F_21 ( V_214 , V_219 + V_160 ) ;
if ( V_235 [ V_160 ] . type == V_55 ) {
V_163 = F_39 ( V_209 -> V_48 [ 0 ] ,
V_209 -> V_49 [ 0 ] ,
struct V_56 ) ;
F_186 ( V_2 , V_209 -> V_48 [ 0 ] , V_163 ,
V_69 , V_231 == V_241 ) ;
} else {
F_34 ( V_209 -> V_48 [ 0 ] , V_214 , V_233 ,
V_232 , V_236 [ V_160 ] ) ;
}
if ( F_207 ( V_235 + V_160 ) == V_167 &&
! V_239 ) {
int V_61 ;
V_234 = F_39 ( V_214 , V_219 + V_160 ,
struct V_67 ) ;
if ( F_208 ( V_214 , V_234 ) < V_2 -> V_60 )
continue;
V_61 = F_40 ( V_214 , V_234 ) ;
if ( V_61 == V_71 ) {
T_1 V_242 , V_243 , V_244 , V_245 ;
V_242 = F_49 ( V_214 ,
V_234 ) ;
if ( V_242 == 0 )
continue;
V_243 = F_50 ( V_214 ,
V_234 ) ;
V_244 = F_51 ( V_214 , V_234 ) ;
V_245 = F_41 ( V_214 ,
V_234 ) ;
if ( F_56 ( V_214 ,
V_234 ) ) {
V_244 = 0 ;
V_245 = V_243 ;
}
V_5 = F_57 (
log -> V_15 -> V_90 ,
V_242 + V_244 , V_242 + V_244 + V_245 - 1 ,
& V_85 , 0 ) ;
F_48 ( V_5 ) ;
}
}
}
F_37 ( V_209 -> V_48 [ 0 ] ) ;
F_23 ( V_209 ) ;
F_25 ( V_237 ) ;
V_5 = 0 ;
while ( ! F_58 ( & V_85 ) ) {
struct V_86 * V_87 = F_59 ( V_85 . V_88 ,
struct V_86 ,
V_89 ) ;
if ( ! V_5 )
V_5 = F_60 ( V_2 , log , V_87 ) ;
F_61 ( & V_87 -> V_89 ) ;
F_25 ( V_87 ) ;
}
return V_5 ;
}
static int F_209 ( void * V_246 , struct V_238 * V_247 , struct V_238 * V_248 )
{
struct V_249 * V_250 , * V_251 ;
V_250 = F_59 ( V_247 , struct V_249 , V_89 ) ;
V_251 = F_59 ( V_248 , struct V_249 , V_89 ) ;
if ( V_250 -> V_27 < V_251 -> V_27 )
return - 1 ;
else if ( V_250 -> V_27 > V_251 -> V_27 )
return 1 ;
return 0 ;
}
static int F_210 ( struct V_1 * V_2 ,
struct V_69 * V_69 , struct V_3 * V_4 ,
struct V_249 * V_252 , struct V_31 * V_32 ,
struct V_31 * V_209 , struct V_253 * args )
{
struct V_3 * log = V_4 -> V_8 ;
struct V_67 * V_254 ;
struct V_34 V_35 ;
T_1 V_27 = V_252 -> V_255 ;
T_1 V_256 = V_27 ;
T_1 V_28 = V_252 -> V_257 ;
T_1 V_258 ;
int V_148 ;
int V_5 ;
if ( F_103 ( V_69 ) -> V_203 == V_2 -> V_60 ) {
V_5 = F_211 ( V_2 , log , V_69 , V_209 , V_27 ,
V_27 + V_28 , NULL , 0 ) ;
if ( V_5 )
return V_5 ;
}
while ( V_28 ) {
if ( args -> V_230 )
goto V_259;
V_118:
V_35 . V_43 = F_45 ( V_69 ) ;
V_35 . type = V_167 ;
V_35 . V_65 = V_256 ;
V_5 = F_22 ( NULL , V_4 , & V_35 , V_32 , 0 , 0 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( V_5 ) {
do {
if ( V_32 -> V_49 [ 0 ] == 0 ) {
F_23 ( V_32 ) ;
if ( V_256 == 0 )
return - V_18 ;
V_256 -- ;
goto V_118;
}
V_32 -> V_49 [ 0 ] -- ;
F_100 ( V_32 -> V_48 [ 0 ] , & V_35 ,
V_32 -> V_49 [ 0 ] ) ;
if ( V_35 . V_43 != F_45 ( V_69 ) ||
V_35 . type != V_167 ) {
F_23 ( V_32 ) ;
return - V_18 ;
}
} while ( V_35 . V_65 > V_27 );
V_254 = F_39 ( V_32 -> V_48 [ 0 ] , V_32 -> V_49 [ 0 ] ,
struct V_67 ) ;
V_258 = F_41 ( V_32 -> V_48 [ 0 ] ,
V_254 ) ;
if ( V_35 . V_65 + V_258 <= V_27 ) {
F_23 ( V_32 ) ;
return - V_18 ;
}
}
args -> V_214 = V_32 -> V_48 [ 0 ] ;
V_259:
F_100 ( V_32 -> V_48 [ 0 ] , & V_35 , V_32 -> V_49 [ 0 ] ) ;
V_254 = F_39 ( args -> V_214 , V_32 -> V_49 [ 0 ] ,
struct V_67 ) ;
if ( args -> V_230 &&
args -> V_219 + args -> V_230 == V_32 -> V_49 [ 0 ] ) {
args -> V_230 ++ ;
} else if ( args -> V_230 ) {
V_5 = F_204 ( V_2 , V_69 , V_209 , args -> V_214 ,
args -> V_219 , args -> V_230 ,
V_260 ) ;
if ( V_5 )
return V_5 ;
args -> V_230 = 1 ;
args -> V_219 = V_32 -> V_49 [ 0 ] ;
} else if ( ! args -> V_230 ) {
args -> V_230 = 1 ;
args -> V_219 = V_32 -> V_49 [ 0 ] ;
}
V_148 = F_117 ( V_32 -> V_48 [ 0 ] ) ;
V_32 -> V_49 [ 0 ] ++ ;
V_258 = F_41 ( args -> V_214 , V_254 ) ;
if ( V_28 < V_258 ) {
V_28 = 0 ;
} else {
V_28 -= V_258 ;
}
V_27 = V_35 . V_65 + V_258 ;
args -> V_261 = V_27 ;
V_256 = V_27 ;
if ( V_32 -> V_49 [ 0 ] < V_148 ) {
if ( V_28 )
goto V_259;
break;
}
if ( args -> V_230 ) {
V_5 = F_204 ( V_2 , V_69 , V_209 , args -> V_214 ,
args -> V_219 , args -> V_230 ,
V_260 ) ;
if ( V_5 )
return V_5 ;
args -> V_230 = 0 ;
F_23 ( V_32 ) ;
}
}
return 0 ;
}
static int F_212 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_69 * V_69 ,
struct V_31 * V_32 ,
struct V_31 * V_209 )
{
struct V_253 args ;
struct V_249 * V_252 , * V_262 ;
struct V_238 V_263 ;
struct V_264 * V_265 = & F_103 ( V_69 ) -> V_266 ;
T_1 V_267 ;
int V_5 = 0 ;
F_205 ( & V_263 ) ;
memset ( & args , 0 , sizeof( args ) ) ;
F_213 ( & V_265 -> V_268 ) ;
V_267 = V_4 -> V_15 -> V_269 ;
F_214 (em, n, &tree->modified_extents, list) {
F_215 ( & V_252 -> V_89 ) ;
if ( V_252 -> V_229 <= V_267 )
continue;
F_3 ( & V_252 -> V_270 ) ;
F_216 ( V_271 , & V_252 -> V_228 ) ;
F_217 ( & V_252 -> V_89 , & V_263 ) ;
}
F_218 ( NULL , & V_263 , F_209 ) ;
while ( ! F_58 ( & V_263 ) ) {
V_252 = F_59 ( V_263 . V_88 , struct V_249 , V_89 ) ;
F_215 ( & V_252 -> V_89 ) ;
F_219 ( V_271 , & V_252 -> V_228 ) ;
if ( V_5 ) {
F_220 ( V_252 ) ;
continue;
}
F_221 ( & V_265 -> V_268 ) ;
if ( args . V_230 && V_252 -> V_255 != args . V_261 ) {
V_5 = F_204 ( V_2 , V_69 , V_209 , args . V_214 ,
args . V_219 , args . V_230 ,
V_260 ) ;
if ( V_5 ) {
F_220 ( V_252 ) ;
F_213 ( & V_265 -> V_268 ) ;
continue;
}
F_23 ( V_32 ) ;
args . V_230 = 0 ;
}
V_5 = F_210 ( V_2 , V_69 , V_4 , V_252 , V_32 , V_209 , & args ) ;
F_220 ( V_252 ) ;
F_213 ( & V_265 -> V_268 ) ;
}
F_125 ( ! F_58 ( & V_263 ) ) ;
F_221 ( & V_265 -> V_268 ) ;
if ( ! V_5 && args . V_230 )
V_5 = F_204 ( V_2 , V_69 , V_209 , args . V_214 ,
args . V_219 , args . V_230 , V_260 ) ;
F_23 ( V_32 ) ;
return V_5 ;
}
static int F_222 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_69 * V_69 ,
int V_231 )
{
struct V_31 * V_32 ;
struct V_31 * V_209 ;
struct V_34 V_212 ;
struct V_34 V_213 ;
struct V_3 * log = V_4 -> V_8 ;
struct V_20 * V_214 = NULL ;
int V_6 = 0 ;
int V_5 ;
int V_148 ;
int V_272 = 0 ;
int V_273 ;
bool V_274 = false ;
T_1 V_130 = F_45 ( V_69 ) ;
log = V_4 -> V_8 ;
V_32 = F_76 () ;
if ( ! V_32 )
return - V_52 ;
V_209 = F_76 () ;
if ( ! V_209 ) {
F_80 ( V_32 ) ;
return - V_52 ;
}
V_212 . V_43 = V_130 ;
V_212 . type = V_55 ;
V_212 . V_65 = 0 ;
V_213 . V_43 = V_130 ;
if ( V_231 == V_241 || F_31 ( V_69 -> V_133 ) )
V_213 . type = V_166 ;
else
V_213 . type = ( T_4 ) - 1 ;
V_213 . V_65 = ( T_1 ) - 1 ;
if ( F_31 ( V_69 -> V_133 ) ||
F_103 ( V_69 ) -> V_229 > V_4 -> V_15 -> V_269 ) {
V_5 = F_223 ( V_2 , V_69 ) ;
if ( V_5 ) {
F_80 ( V_32 ) ;
F_80 ( V_209 ) ;
return V_5 ;
}
}
F_2 ( & F_103 ( V_69 ) -> V_7 ) ;
if ( F_31 ( V_69 -> V_133 ) ) {
int V_218 = V_157 ;
if ( V_231 == V_241 )
V_218 = V_166 ;
V_5 = F_183 ( V_2 , log , V_32 , V_130 , V_218 ) ;
} else {
if ( F_224 ( V_275 ,
& F_103 ( V_69 ) -> V_276 ) ) {
V_5 = F_225 ( V_2 , log ,
V_69 , 0 , 0 ) ;
} else {
V_274 = true ;
V_213 . type = V_166 ;
V_5 = F_183 ( V_2 , log , V_32 , V_130 ,
V_166 ) ;
}
}
if ( V_5 ) {
V_6 = V_5 ;
goto V_204;
}
V_32 -> V_215 = 1 ;
while ( 1 ) {
V_273 = 0 ;
V_5 = F_179 ( V_4 , & V_212 , & V_213 ,
V_32 , 0 , V_2 -> V_60 ) ;
if ( V_5 != 0 )
break;
V_118:
if ( V_212 . V_43 != V_130 )
break;
if ( V_212 . type > V_213 . type )
break;
V_214 = V_32 -> V_48 [ 0 ] ;
if ( V_273 && V_272 + V_273 == V_32 -> V_49 [ 0 ] ) {
V_273 ++ ;
goto V_259;
} else if ( ! V_273 ) {
V_272 = V_32 -> V_49 [ 0 ] ;
V_273 = 1 ;
goto V_259;
}
V_5 = F_204 ( V_2 , V_69 , V_209 , V_214 , V_272 ,
V_273 , V_231 ) ;
if ( V_5 ) {
V_6 = V_5 ;
goto V_204;
}
V_273 = 1 ;
V_272 = V_32 -> V_49 [ 0 ] ;
V_259:
V_148 = F_117 ( V_32 -> V_48 [ 0 ] ) ;
V_32 -> V_49 [ 0 ] ++ ;
if ( V_32 -> V_49 [ 0 ] < V_148 ) {
F_100 ( V_32 -> V_48 [ 0 ] , & V_212 ,
V_32 -> V_49 [ 0 ] ) ;
goto V_118;
}
if ( V_273 ) {
V_5 = F_204 ( V_2 , V_69 , V_209 , V_214 ,
V_272 ,
V_273 , V_231 ) ;
if ( V_5 ) {
V_6 = V_5 ;
goto V_204;
}
V_273 = 0 ;
}
F_23 ( V_32 ) ;
if ( V_212 . V_65 < ( T_1 ) - 1 )
V_212 . V_65 ++ ;
else if ( V_212 . type < ( T_4 ) - 1 )
V_212 . type ++ ;
else if ( V_212 . V_43 < ( T_1 ) - 1 )
V_212 . V_43 ++ ;
else
break;
}
if ( V_273 ) {
V_5 = F_204 ( V_2 , V_69 , V_209 , V_214 , V_272 ,
V_273 , V_231 ) ;
if ( V_5 ) {
V_6 = V_5 ;
goto V_204;
}
V_273 = 0 ;
}
if ( V_274 ) {
F_23 ( V_32 ) ;
F_23 ( V_209 ) ;
V_5 = F_212 ( V_2 , V_4 , V_69 , V_32 ,
V_209 ) ;
if ( V_5 ) {
V_6 = V_5 ;
goto V_204;
}
} else {
struct V_264 * V_265 = & F_103 ( V_69 ) -> V_266 ;
struct V_249 * V_252 , * V_262 ;
F_214 (em, n, &tree->modified_extents, list)
F_215 ( & V_252 -> V_89 ) ;
}
if ( V_231 == V_260 && F_31 ( V_69 -> V_133 ) ) {
F_23 ( V_32 ) ;
F_23 ( V_209 ) ;
V_5 = F_182 ( V_2 , V_4 , V_69 , V_32 , V_209 ) ;
if ( V_5 ) {
V_6 = V_5 ;
goto V_204;
}
}
F_103 ( V_69 ) -> V_203 = V_2 -> V_60 ;
F_103 ( V_69 ) -> V_198 = F_103 ( V_69 ) -> V_277 ;
V_204:
F_4 ( & F_103 ( V_69 ) -> V_7 ) ;
F_80 ( V_32 ) ;
F_80 ( V_209 ) ;
return V_6 ;
}
static T_2 int F_226 ( struct V_1 * V_2 ,
struct V_69 * V_69 ,
struct V_278 * V_172 ,
struct V_279 * V_280 ,
T_1 V_281 )
{
int V_5 = 0 ;
struct V_3 * V_4 ;
struct V_278 * V_282 = NULL ;
if ( F_123 ( V_69 -> V_133 ) &&
F_103 ( V_69 ) -> V_229 <= V_281 &&
F_103 ( V_69 ) -> V_283 <= V_281 )
goto V_74;
if ( ! F_31 ( V_69 -> V_133 ) ) {
if ( ! V_172 || ! V_172 -> V_284 || V_280 != V_172 -> V_284 -> V_285 )
goto V_74;
V_69 = V_172 -> V_284 ;
}
while ( 1 ) {
F_103 ( V_69 ) -> V_203 = V_2 -> V_60 ;
F_8 () ;
if ( F_103 ( V_69 ) -> V_283 > V_281 ) {
V_4 = F_103 ( V_69 ) -> V_4 ;
V_4 -> V_15 -> V_183 =
V_2 -> V_60 ;
V_5 = 1 ;
break;
}
if ( ! V_172 || ! V_172 -> V_284 || V_280 != V_172 -> V_284 -> V_285 )
break;
if ( F_227 ( V_172 ) )
break;
V_172 = F_228 ( V_172 ) ;
F_229 ( V_282 ) ;
V_282 = V_172 ;
V_69 = V_172 -> V_284 ;
}
F_229 ( V_282 ) ;
V_74:
return V_5 ;
}
int F_230 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_69 * V_69 ,
struct V_278 * V_172 , int V_286 )
{
int V_231 = V_286 ? V_241 : V_260 ;
struct V_279 * V_280 ;
struct V_278 * V_282 = NULL ;
int V_5 = 0 ;
T_1 V_281 = V_4 -> V_15 -> V_269 ;
V_280 = V_69 -> V_285 ;
if ( F_154 ( V_4 , V_287 ) ) {
V_5 = 1 ;
goto V_288;
}
if ( V_4 -> V_15 -> V_183 >
V_4 -> V_15 -> V_269 ) {
V_5 = 1 ;
goto V_288;
}
if ( V_4 != F_103 ( V_69 ) -> V_4 ||
F_231 ( & V_4 -> V_180 ) == 0 ) {
V_5 = 1 ;
goto V_288;
}
V_5 = F_226 ( V_2 , V_69 , V_172 ,
V_280 , V_281 ) ;
if ( V_5 )
goto V_288;
if ( F_232 ( V_69 , V_2 -> V_60 ) ) {
V_5 = V_289 ;
goto V_288;
}
V_5 = F_1 ( V_2 , V_4 ) ;
if ( V_5 )
goto V_290;
V_5 = F_222 ( V_2 , V_4 , V_69 , V_231 ) ;
if ( V_5 )
goto V_290;
if ( F_123 ( V_69 -> V_133 ) &&
F_103 ( V_69 ) -> V_229 <= V_281 &&
F_103 ( V_69 ) -> V_283 <= V_281 ) {
V_5 = 0 ;
goto V_290;
}
V_231 = V_241 ;
while ( 1 ) {
if ( ! V_172 || ! V_172 -> V_284 || V_280 != V_172 -> V_284 -> V_285 )
break;
V_69 = V_172 -> V_284 ;
if ( V_4 != F_103 ( V_69 ) -> V_4 )
break;
if ( F_103 ( V_69 ) -> V_229 >
V_4 -> V_15 -> V_269 ) {
V_5 = F_222 ( V_2 , V_4 , V_69 , V_231 ) ;
if ( V_5 )
goto V_290;
}
if ( F_227 ( V_172 ) )
break;
V_172 = F_228 ( V_172 ) ;
F_229 ( V_282 ) ;
V_282 = V_172 ;
}
V_5 = 0 ;
V_290:
F_229 ( V_282 ) ;
if ( V_5 < 0 ) {
F_125 ( V_5 != - V_194 ) ;
V_4 -> V_15 -> V_183 = V_2 -> V_60 ;
V_5 = 1 ;
}
F_10 ( V_4 ) ;
V_288:
return V_5 ;
}
int F_233 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_278 * V_278 )
{
struct V_278 * V_172 = F_228 ( V_278 ) ;
int V_5 ;
V_5 = F_230 ( V_2 , V_4 , V_278 -> V_284 , V_172 , 0 ) ;
F_229 ( V_172 ) ;
return V_5 ;
}
int F_234 ( struct V_3 * V_17 )
{
int V_5 ;
struct V_31 * V_32 ;
struct V_1 * V_2 ;
struct V_34 V_35 ;
struct V_34 V_137 ;
struct V_34 V_291 ;
struct V_3 * log ;
struct V_200 * V_15 = V_17 -> V_15 ;
struct V_22 V_23 = {
. V_175 = F_14 ,
. V_161 = 0 ,
} ;
V_32 = F_76 () ;
if ( ! V_32 )
return - V_52 ;
V_15 -> V_292 = 1 ;
V_2 = F_235 ( V_15 -> V_197 , 0 ) ;
if ( F_73 ( V_2 ) ) {
V_5 = F_172 ( V_2 ) ;
goto error;
}
V_23 . V_2 = V_2 ;
V_23 . V_25 = 1 ;
V_5 = F_140 ( V_2 , V_17 , & V_23 ) ;
if ( V_5 ) {
F_236 ( V_15 , V_5 , L_1
L_2 ) ;
goto error;
}
V_118:
V_35 . V_43 = V_44 ;
V_35 . V_65 = ( T_1 ) - 1 ;
F_107 ( & V_35 , V_293 ) ;
while ( 1 ) {
V_5 = F_22 ( NULL , V_17 , & V_35 , V_32 , 0 , 0 ) ;
if ( V_5 < 0 ) {
F_236 ( V_15 , V_5 ,
L_3 ) ;
goto error;
}
if ( V_5 > 0 ) {
if ( V_32 -> V_49 [ 0 ] == 0 )
break;
V_32 -> V_49 [ 0 ] -- ;
}
F_100 ( V_32 -> V_48 [ 0 ] , & V_137 ,
V_32 -> V_49 [ 0 ] ) ;
F_23 ( V_32 ) ;
if ( V_137 . V_43 != V_44 )
break;
log = F_237 ( V_17 ,
& V_137 ) ;
if ( F_73 ( log ) ) {
V_5 = F_172 ( log ) ;
F_236 ( V_15 , V_5 ,
L_4 ) ;
goto error;
}
V_291 . V_43 = V_137 . V_65 ;
V_291 . type = V_293 ;
V_291 . V_65 = ( T_1 ) - 1 ;
V_23 . V_158 = F_238 ( V_15 , & V_291 ) ;
if ( F_73 ( V_23 . V_158 ) ) {
V_5 = F_172 ( V_23 . V_158 ) ;
F_236 ( V_15 , V_5 , L_5
L_6 ) ;
goto error;
}
V_23 . V_158 -> V_8 = log ;
F_239 ( V_2 , V_23 . V_158 ) ;
V_5 = F_140 ( V_2 , log , & V_23 ) ;
F_48 ( V_5 ) ;
if ( V_23 . V_161 == V_165 ) {
V_5 = F_105 ( V_2 , V_23 . V_158 ,
V_32 ) ;
F_48 ( V_5 ) ;
}
V_35 . V_65 = V_137 . V_65 - 1 ;
V_23 . V_158 -> V_8 = NULL ;
F_131 ( log -> V_176 ) ;
F_131 ( log -> V_294 ) ;
F_25 ( log ) ;
if ( V_137 . V_65 == 0 )
break;
}
F_23 ( V_32 ) ;
if ( V_23 . V_25 ) {
V_23 . V_25 = 0 ;
V_23 . V_175 = F_120 ;
V_23 . V_161 = V_162 ;
goto V_118;
}
if ( V_23 . V_161 < V_165 ) {
V_23 . V_161 ++ ;
goto V_118;
}
F_80 ( V_32 ) ;
F_131 ( V_17 -> V_176 ) ;
V_17 -> V_8 = NULL ;
V_15 -> V_292 = 0 ;
F_240 ( V_2 , V_15 -> V_197 ) ;
F_25 ( V_17 ) ;
return 0 ;
error:
F_80 ( V_32 ) ;
return V_5 ;
}
void F_241 ( struct V_1 * V_2 ,
struct V_69 * V_91 , struct V_69 * V_69 ,
int V_295 )
{
if ( F_123 ( V_69 -> V_133 ) )
F_103 ( V_69 ) -> V_283 = V_2 -> V_60 ;
F_8 () ;
if ( F_103 ( V_91 ) -> V_203 == V_2 -> V_60 )
return;
if ( F_103 ( V_69 ) -> V_203 == V_2 -> V_60 )
return;
if ( V_295 )
goto V_296;
return;
V_296:
F_103 ( V_91 ) -> V_283 = V_2 -> V_60 ;
}
int F_242 ( struct V_1 * V_2 ,
struct V_69 * V_69 , struct V_69 * V_297 ,
struct V_278 * V_172 )
{
struct V_3 * V_4 = F_103 ( V_69 ) -> V_4 ;
if ( F_123 ( V_69 -> V_133 ) )
F_103 ( V_69 ) -> V_283 = V_2 -> V_60 ;
if ( F_103 ( V_69 ) -> V_203 <=
V_4 -> V_15 -> V_269 &&
( ! V_297 || F_103 ( V_297 ) -> V_203 <=
V_4 -> V_15 -> V_269 ) )
return 0 ;
return F_230 ( V_2 , V_4 , V_69 , V_172 , 1 ) ;
}
