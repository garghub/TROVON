void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 =
F_2 ( V_2 , struct V_3 , V_5 ) ;
struct V_6 * V_6 = V_4 -> V_6 ;
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_9 * V_10 = V_4 -> V_10 ;
struct V_11 * V_12 = F_3 ( V_10 ) ;
int V_13 = F_4 ( V_8 ) ;
struct V_14 * V_14 ;
unsigned int V_15 ;
unsigned int V_16 ;
int V_17 ;
V_15 = F_5 ( ( unsigned long int * ) & V_10 -> V_18 ,
V_13 ) ;
V_14 = F_6 ( V_19 , V_15 ) ;
if ( ! V_14 ) {
F_7 ( L_1 ) ;
return;
}
V_14 -> V_20 . V_21 = 0 ;
F_8 ( V_14 , V_22 , 0 ) ;
V_10 -> V_14 = V_14 ;
V_10 -> V_23 = V_15 ;
V_16 = F_9 ( & V_6 -> V_24 , V_14 , & V_4 -> V_25 ,
V_15 ) ;
if ( V_16 != V_15 ) {
F_7 ( L_2 ) ;
goto V_26;
}
if ( F_10 ( V_6 , V_10 , V_12 ) ) {
F_7 ( L_3 ) ;
goto V_26;
}
#ifdef F_11
F_12 ( V_15 , & V_6 -> V_27 ) ;
#endif
V_17 = F_13 ( V_6 , V_10 ) ;
if ( V_17 ) {
F_7 ( L_4 , V_17 ) ;
goto V_26;
}
F_14 ( V_4 , V_6 -> V_28 ) ;
return;
V_26:
F_15 ( V_14 ) ;
F_16 ( V_6 , V_10 , V_29 ) ;
}
int F_17 ( struct V_6 * V_6 , struct V_11 * V_12 ,
struct V_3 * V_4 , T_1 * V_30 ,
unsigned int V_31 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
int V_13 = F_4 ( V_8 ) ;
struct V_9 * V_32 ;
struct V_11 * V_33 ;
int V_34 = V_12 -> V_35 + V_12 -> V_36 ;
V_32 = F_18 ( V_6 , V_29 ) ;
if ( F_19 ( V_32 ) ) {
F_7 ( L_5 ) ;
return - V_37 ;
}
V_33 = F_3 ( V_32 ) ;
F_20 ( ( unsigned long int * ) & V_32 -> V_18 ,
( unsigned long int * ) V_30 ,
V_31 , V_13 ) ;
V_33 -> V_38 = F_21 ( & V_6 -> V_24 , V_12 -> V_38 + V_31 ) ;
if ( V_31 >= V_12 -> V_35 ) {
V_33 -> V_35 = 0 ;
V_33 -> V_36 = V_34 - V_31 ;
V_12 -> V_36 = V_31 - V_12 -> V_35 ;
} else {
V_33 -> V_35 = V_12 -> V_35 - V_31 ;
V_33 -> V_36 = V_12 -> V_36 ;
V_12 -> V_35 = V_31 ;
V_12 -> V_36 = 0 ;
}
V_4 -> V_10 = V_32 ;
V_4 -> V_6 = V_6 ;
return 0 ;
}
T_2 * F_22 ( struct V_6 * V_6 , struct V_39 * V_40 )
{
T_3 V_41 ;
V_41 = F_23 ( V_6 , V_40 ) ;
if ( F_24 ( V_40 -> V_41 ) != V_41 )
return NULL ;
if ( F_24 ( V_40 -> V_42 . V_43 ) != V_44 )
return NULL ;
return F_25 ( V_6 , V_40 ) ;
}
static int F_26 ( struct V_6 * V_6 , struct V_45 * line )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_46 * V_47 = & V_8 -> V_47 ;
struct V_48 * V_49 = & V_6 -> V_49 ;
struct V_50 * V_51 = line -> V_51 ;
struct V_39 * V_40 = V_51 -> V_52 ;
T_2 * V_53 ;
int V_54 ;
int V_55 , V_56 , V_57 = 0 ;
int V_58 ;
V_53 = F_22 ( V_6 , V_40 ) ;
if ( ! V_53 )
return 1 ;
V_54 = F_27 ( V_6 , line ) + V_49 -> V_59 ;
V_55 = V_49 -> V_60 - V_49 -> V_61 [ 0 ] ;
V_56 = F_28 ( V_40 -> V_56 ) ;
for ( V_58 = V_54 ; V_58 < V_55 && V_57 < V_56 ; V_58 ++ ) {
struct V_62 V_63 ;
int V_64 ;
V_63 = F_29 ( V_6 , V_58 , line -> V_65 ) ;
V_64 = F_30 ( V_47 , V_63 ) ;
if ( F_31 ( V_64 , line -> V_66 ) )
continue;
if ( F_28 ( V_53 [ V_58 ] ) == V_67 ) {
F_32 ( & line -> V_68 ) ;
if ( F_33 ( V_58 , line -> V_69 ) )
F_34 ( 1 , L_6 ) ;
else
F_35 ( line -> V_70 , - 1 ) ;
F_36 ( & line -> V_68 ) ;
continue;
}
F_37 ( V_6 , F_28 ( V_53 [ V_58 ] ) , V_63 ) ;
V_57 ++ ;
}
if ( V_56 != V_57 )
F_7 ( L_7 ,
line -> V_65 , V_40 -> V_56 , V_57 ) ;
line -> V_71 = 0 ;
return 0 ;
}
static int F_38 ( struct V_6 * V_6 , struct V_45 * line )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_46 * V_47 = & V_8 -> V_47 ;
struct V_48 * V_49 = & V_6 -> V_49 ;
int V_72 = F_5 ( line -> V_66 , V_49 -> V_73 ) ;
return V_49 -> V_60 - V_49 -> V_59 - V_49 -> V_61 [ 0 ] -
V_72 * V_47 -> V_74 ;
}
static int F_39 ( struct V_6 * V_6 , struct V_45 * line ,
struct V_75 V_76 , T_1 V_77 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_46 * V_47 = & V_8 -> V_47 ;
struct V_62 * V_78 ;
struct V_79 * V_80 ;
struct V_9 * V_10 ;
struct V_14 * V_14 ;
void * V_81 ;
T_4 V_82 , V_83 ;
T_1 V_84 ;
int V_85 ;
int V_86 , V_87 ;
int V_58 , V_88 ;
int V_17 = 0 ;
F_40 ( V_89 ) ;
V_78 = V_76 . V_78 ;
V_80 = V_76 . V_80 ;
V_10 = V_76 . V_10 ;
V_81 = V_76 . V_81 ;
V_82 = V_76 . V_82 ;
V_83 = V_76 . V_83 ;
V_85 = line -> V_90 - V_77 ;
if ( ! V_85 )
return 0 ;
V_84 = V_77 ;
V_91:
memset ( V_10 , 0 , V_92 ) ;
V_86 = F_41 ( V_6 , V_85 , 0 ) ;
if ( ! V_86 )
V_86 = V_6 -> V_93 ;
V_87 = V_86 * V_47 -> V_94 ;
V_14 = F_42 ( V_8 -> V_95 , V_81 , V_87 , V_19 ) ;
if ( F_19 ( V_14 ) )
return F_43 ( V_14 ) ;
V_14 -> V_20 . V_21 = 0 ;
F_8 ( V_14 , V_96 , 0 ) ;
V_10 -> V_14 = V_14 ;
V_10 -> V_97 = V_98 ;
V_10 -> V_80 = V_80 ;
V_10 -> V_23 = V_86 ;
V_10 -> V_78 = V_78 ;
V_10 -> V_82 = V_82 ;
V_10 -> V_83 = V_83 ;
V_10 -> V_99 = V_100 ;
V_10 -> V_101 = & V_89 ;
if ( F_44 ( V_6 , V_86 ) )
V_10 -> V_102 = F_45 ( V_6 , V_103 ) ;
else
V_10 -> V_102 = F_45 ( V_6 , V_104 ) ;
for ( V_58 = 0 ; V_58 < V_10 -> V_23 ; ) {
struct V_62 V_63 ;
int V_64 ;
V_63 = F_46 ( V_6 , V_84 , line -> V_65 ) ;
V_64 = F_47 ( V_47 , V_63 ) ;
while ( F_31 ( V_64 , line -> V_66 ) ) {
V_84 += V_6 -> V_93 ;
V_63 = F_46 ( V_6 , V_84 , line -> V_65 ) ;
V_64 = F_47 ( V_47 , V_63 ) ;
}
for ( V_88 = 0 ; V_88 < V_6 -> V_93 ; V_88 ++ , V_58 ++ , V_84 ++ )
V_10 -> V_78 [ V_58 ] =
F_46 ( V_6 , V_84 , line -> V_65 ) ;
}
V_17 = F_13 ( V_6 , V_10 ) ;
if ( V_17 ) {
F_7 ( L_4 , V_17 ) ;
return V_17 ;
}
if ( ! F_48 ( & V_89 ,
F_49 ( V_105 ) ) ) {
F_7 ( L_8 ) ;
return - V_106 ;
}
F_50 ( & V_6 -> V_107 ) ;
F_51 ( & V_89 ) ;
if ( V_10 -> error ) {
F_7 ( L_9 , V_10 -> error ) ;
return - V_106 ;
}
for ( V_58 = 0 ; V_58 < V_10 -> V_23 ; V_58 ++ ) {
T_1 V_108 = F_28 ( V_80 [ V_58 ] . V_108 ) ;
if ( V_108 == V_67 || V_108 > V_6 -> V_109 . V_110 )
continue;
F_37 ( V_6 , V_108 , V_10 -> V_78 [ V_58 ] ) ;
}
V_85 -= V_86 ;
if ( V_85 > 0 )
goto V_91;
return 0 ;
}
static void F_52 ( struct V_111 * V_112 )
{
struct V_113 * V_114 = F_2 ( V_112 , struct V_113 , V_112 ) ;
F_53 ( & V_114 -> V_89 ) ;
}
static void F_54 ( struct V_9 * V_10 )
{
struct V_113 * V_114 = V_10 -> V_101 ;
struct V_6 * V_6 = V_114 -> V_6 ;
struct V_7 * V_8 = V_6 -> V_8 ;
F_55 ( V_6 , V_10 -> V_78 , V_10 -> V_23 ) ;
F_15 ( V_10 -> V_14 ) ;
F_56 ( V_8 -> V_115 , V_10 -> V_80 , V_10 -> V_83 ) ;
F_16 ( V_6 , V_10 , V_29 ) ;
F_50 ( & V_6 -> V_107 ) ;
F_57 ( & V_114 -> V_112 , F_52 ) ;
}
static int F_58 ( struct V_6 * V_6 , struct V_45 * line ,
int V_85 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_46 * V_47 = & V_8 -> V_47 ;
struct V_62 * V_78 ;
struct V_79 * V_80 ;
struct V_113 * V_114 ;
struct V_9 * V_10 ;
struct V_14 * V_14 ;
void * V_81 ;
T_4 V_82 , V_83 ;
T_2 * V_53 = F_25 ( V_6 , line -> V_51 -> V_52 ) ;
T_1 V_116 = line -> V_90 ;
int V_117 , V_86 , V_87 ;
int V_58 , V_88 ;
int V_17 = 0 ;
F_32 ( & line -> V_68 ) ;
V_117 = line -> V_71 ;
F_36 ( & line -> V_68 ) ;
V_114 = F_59 ( sizeof( struct V_113 ) , V_19 ) ;
if ( ! V_114 )
return - V_37 ;
V_81 = F_60 ( V_6 -> V_118 * V_47 -> V_94 ) ;
if ( ! V_81 ) {
V_17 = - V_37 ;
goto V_119;
}
V_114 -> V_6 = V_6 ;
F_61 ( & V_114 -> V_89 ) ;
F_62 ( & V_114 -> V_112 ) ;
V_120:
V_86 = F_41 ( V_6 , V_85 , 0 ) ;
if ( V_86 < V_6 -> V_93 ) {
F_7 ( L_10 , line -> V_65 ) ;
goto V_121;
}
V_87 = V_86 * V_47 -> V_94 ;
V_80 = F_63 ( V_8 -> V_115 , V_19 , & V_83 ) ;
if ( ! V_80 ) {
V_17 = - V_37 ;
goto V_121;
}
V_78 = ( void * ) ( V_80 ) + V_122 ;
V_82 = V_83 + V_122 ;
V_10 = F_18 ( V_6 , V_29 ) ;
if ( F_19 ( V_10 ) ) {
V_17 = F_43 ( V_10 ) ;
goto V_123;
}
V_14 = F_64 ( V_6 , V_81 , V_86 , V_87 ,
V_124 , V_19 ) ;
if ( F_19 ( V_14 ) ) {
V_17 = F_43 ( V_14 ) ;
goto V_125;
}
V_14 -> V_20 . V_21 = 0 ;
F_8 ( V_14 , V_22 , 0 ) ;
V_10 -> V_14 = V_14 ;
V_10 -> V_97 = V_126 ;
V_10 -> V_102 = F_65 ( V_6 , V_29 ) ;
V_10 -> V_80 = V_80 ;
V_10 -> V_23 = V_86 ;
V_10 -> V_78 = V_78 ;
V_10 -> V_82 = V_82 ;
V_10 -> V_83 = V_83 ;
V_10 -> V_99 = F_54 ;
V_10 -> V_101 = V_114 ;
for ( V_58 = 0 ; V_58 < V_10 -> V_23 ; ) {
struct V_62 V_63 ;
int V_64 ;
V_116 = F_66 ( V_6 , line , V_6 -> V_93 ) ;
V_63 = F_29 ( V_6 , V_116 , line -> V_65 ) ;
V_64 = F_30 ( V_47 , V_63 ) ;
while ( F_31 ( V_64 , line -> V_66 ) ) {
V_116 += V_6 -> V_93 ;
V_63 = F_29 ( V_6 , V_116 , line -> V_65 ) ;
V_64 = F_30 ( V_47 , V_63 ) ;
}
for ( V_88 = 0 ; V_88 < V_6 -> V_93 ; V_88 ++ , V_58 ++ , V_116 ++ ) {
struct V_62 V_127 ;
T_2 V_128 = F_67 ( V_67 ) ;
V_127 = F_46 ( V_6 , V_116 , line -> V_65 ) ;
F_68 ( V_6 , V_127 ) ;
V_53 [ V_116 ] = V_80 [ V_58 ] . V_108 = V_128 ;
V_10 -> V_78 [ V_58 ] = V_127 ;
}
}
F_69 ( & V_114 -> V_112 ) ;
F_70 ( V_6 , V_10 -> V_78 , V_10 -> V_23 ) ;
V_17 = F_13 ( V_6 , V_10 ) ;
if ( V_17 ) {
F_7 ( L_4 , V_17 ) ;
F_55 ( V_6 , V_10 -> V_78 , V_10 -> V_23 ) ;
goto V_129;
}
V_117 -= V_86 ;
V_85 -= V_86 ;
if ( V_85 && V_117 )
goto V_120;
F_57 ( & V_114 -> V_112 , F_52 ) ;
if ( ! F_48 ( & V_114 -> V_89 ,
F_49 ( V_105 ) ) ) {
F_7 ( L_11 ) ;
V_17 = - V_130 ;
}
if ( ! F_71 ( line ) )
F_7 ( L_12 , line -> V_65 ) ;
F_72 ( V_81 ) ;
V_119:
F_73 ( V_114 ) ;
return V_17 ;
V_129:
F_15 ( V_14 ) ;
V_125:
F_16 ( V_6 , V_10 , V_29 ) ;
V_123:
F_56 ( V_8 -> V_115 , V_80 , V_83 ) ;
V_121:
F_73 ( V_114 ) ;
F_72 ( V_81 ) ;
return V_17 ;
}
static int F_74 ( struct V_6 * V_6 , struct V_45 * line ,
struct V_75 V_76 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_46 * V_47 = & V_8 -> V_47 ;
struct V_62 * V_78 ;
struct V_79 * V_80 ;
struct V_9 * V_10 ;
struct V_14 * V_14 ;
void * V_81 ;
T_4 V_82 , V_83 ;
T_1 V_116 = 0 , V_77 ;
int V_86 , V_87 ;
int V_58 , V_88 ;
int V_17 = 0 ;
int V_131 ;
int V_85 = F_38 ( V_6 , line ) - line -> V_90 ;
F_40 ( V_89 ) ;
V_78 = V_76 . V_78 ;
V_80 = V_76 . V_80 ;
V_10 = V_76 . V_10 ;
V_81 = V_76 . V_81 ;
V_82 = V_76 . V_82 ;
V_83 = V_76 . V_83 ;
V_77 = line -> V_90 ;
V_131 = 0 ;
V_132:
memset ( V_10 , 0 , V_92 ) ;
V_86 = F_41 ( V_6 , V_85 , 0 ) ;
if ( ! V_86 )
V_86 = V_6 -> V_93 ;
V_87 = V_86 * V_47 -> V_94 ;
V_14 = F_42 ( V_8 -> V_95 , V_81 , V_87 , V_19 ) ;
if ( F_19 ( V_14 ) )
return F_43 ( V_14 ) ;
V_14 -> V_20 . V_21 = 0 ;
F_8 ( V_14 , V_96 , 0 ) ;
V_10 -> V_14 = V_14 ;
V_10 -> V_97 = V_98 ;
V_10 -> V_80 = V_80 ;
V_10 -> V_23 = V_86 ;
V_10 -> V_78 = V_78 ;
V_10 -> V_82 = V_82 ;
V_10 -> V_83 = V_83 ;
V_10 -> V_99 = V_100 ;
V_10 -> V_101 = & V_89 ;
if ( F_44 ( V_6 , V_86 ) )
V_10 -> V_102 = F_45 ( V_6 , V_103 ) ;
else
V_10 -> V_102 = F_45 ( V_6 , V_104 ) ;
for ( V_58 = 0 ; V_58 < V_10 -> V_23 ; ) {
struct V_62 V_63 ;
int V_64 ;
V_116 = F_66 ( V_6 , line , V_6 -> V_93 ) ;
V_63 = F_46 ( V_6 , V_116 , line -> V_65 ) ;
V_64 = F_47 ( V_47 , V_63 ) ;
while ( F_31 ( V_64 , line -> V_66 ) ) {
V_116 += V_6 -> V_93 ;
V_63 = F_46 ( V_6 , V_116 , line -> V_65 ) ;
V_64 = F_47 ( V_47 , V_63 ) ;
}
for ( V_88 = 0 ; V_88 < V_6 -> V_93 ; V_88 ++ , V_58 ++ , V_116 ++ )
V_10 -> V_78 [ V_58 ] =
F_46 ( V_6 , V_116 , line -> V_65 ) ;
}
V_17 = F_13 ( V_6 , V_10 ) ;
if ( V_17 ) {
F_7 ( L_4 , V_17 ) ;
return V_17 ;
}
if ( ! F_48 ( & V_89 ,
F_49 ( V_105 ) ) ) {
F_7 ( L_8 ) ;
}
F_50 ( & V_6 -> V_107 ) ;
F_51 ( & V_89 ) ;
if ( ! V_131 ++ && ! V_10 -> error ) {
V_131 = 0 ;
for ( V_58 = 0 ; V_58 < V_10 -> V_23 ; V_58 ++ , V_77 ++ ) {
T_1 V_108 = F_28 ( V_80 [ V_58 ] . V_108 ) ;
if ( V_108 == V_67 || V_108 > V_6 -> V_109 . V_110 )
continue;
F_37 ( V_6 , V_108 , V_10 -> V_78 [ V_58 ] ) ;
}
}
if ( V_10 -> error == V_133 ) {
int V_134 , V_135 , V_136 ;
int V_17 ;
V_136 = F_75 ( ( void * ) & V_10 -> V_18 , V_10 -> V_23 ) ;
V_135 = V_10 -> V_23 - V_136 ;
line -> V_90 -= V_135 ;
line -> V_71 += V_135 ;
F_76 ( line -> V_137 , line -> V_90 , V_135 ) ;
V_134 = F_77 ( V_6 ) ;
if ( V_134 > line -> V_71 )
V_134 = line -> V_71 ;
V_17 = F_58 ( V_6 , line , V_134 ) ;
if ( V_17 )
F_7 ( L_13 , V_17 ) ;
V_17 = F_39 ( V_6 , line , V_76 , V_77 ) ;
if ( V_17 )
F_7 ( L_14 , V_17 ) ;
V_85 = 0 ;
}
V_85 -= V_86 ;
if ( V_85 > 0 )
goto V_132;
return V_17 ;
}
static int F_78 ( struct V_6 * V_6 , struct V_45 * line ,
struct V_75 V_76 , int * V_138 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_46 * V_47 = & V_8 -> V_47 ;
struct V_62 * V_78 ;
struct V_79 * V_80 ;
struct V_9 * V_10 ;
struct V_14 * V_14 ;
void * V_81 ;
T_4 V_82 , V_83 ;
T_1 V_139 ;
int V_86 , V_87 ;
int V_58 , V_88 ;
int V_17 = 0 ;
int V_85 = F_38 ( V_6 , line ) ;
F_40 ( V_89 ) ;
V_78 = V_76 . V_78 ;
V_80 = V_76 . V_80 ;
V_10 = V_76 . V_10 ;
V_81 = V_76 . V_81 ;
V_82 = V_76 . V_82 ;
V_83 = V_76 . V_83 ;
* V_138 = 1 ;
V_132:
memset ( V_10 , 0 , V_92 ) ;
V_86 = F_41 ( V_6 , V_85 , 0 ) ;
if ( ! V_86 )
V_86 = V_6 -> V_93 ;
V_87 = V_86 * V_47 -> V_94 ;
V_14 = F_42 ( V_8 -> V_95 , V_81 , V_87 , V_19 ) ;
if ( F_19 ( V_14 ) )
return F_43 ( V_14 ) ;
V_14 -> V_20 . V_21 = 0 ;
F_8 ( V_14 , V_96 , 0 ) ;
V_10 -> V_14 = V_14 ;
V_10 -> V_97 = V_98 ;
V_10 -> V_80 = V_80 ;
V_10 -> V_23 = V_86 ;
V_10 -> V_78 = V_78 ;
V_10 -> V_82 = V_82 ;
V_10 -> V_83 = V_83 ;
V_10 -> V_99 = V_100 ;
V_10 -> V_101 = & V_89 ;
if ( F_44 ( V_6 , V_86 ) )
V_10 -> V_102 = F_45 ( V_6 , V_103 ) ;
else
V_10 -> V_102 = F_45 ( V_6 , V_104 ) ;
for ( V_58 = 0 ; V_58 < V_10 -> V_23 ; ) {
struct V_62 V_63 ;
int V_64 ;
V_139 = F_66 ( V_6 , line , V_6 -> V_93 ) ;
V_63 = F_46 ( V_6 , V_139 , line -> V_65 ) ;
V_64 = F_47 ( V_47 , V_63 ) ;
while ( F_31 ( V_64 , line -> V_66 ) ) {
V_139 += V_6 -> V_93 ;
V_63 = F_46 ( V_6 , V_139 , line -> V_65 ) ;
V_64 = F_47 ( V_47 , V_63 ) ;
}
for ( V_88 = 0 ; V_88 < V_6 -> V_93 ; V_88 ++ , V_58 ++ , V_139 ++ )
V_10 -> V_78 [ V_58 ] =
F_46 ( V_6 , V_139 , line -> V_65 ) ;
}
V_17 = F_13 ( V_6 , V_10 ) ;
if ( V_17 ) {
F_7 ( L_4 , V_17 ) ;
F_15 ( V_14 ) ;
return V_17 ;
}
if ( ! F_48 ( & V_89 ,
F_49 ( V_105 ) ) ) {
F_7 ( L_8 ) ;
}
F_50 ( & V_6 -> V_107 ) ;
F_51 ( & V_89 ) ;
if ( V_10 -> error ) {
int V_135 , V_136 ;
V_136 = F_75 ( ( void * ) & V_10 -> V_18 , V_10 -> V_23 ) ;
V_135 = V_10 -> V_23 - V_136 ;
line -> V_90 -= V_135 ;
line -> V_71 += V_135 ;
F_76 ( line -> V_137 , line -> V_90 , V_135 ) ;
V_85 = 0 ;
V_10 -> V_23 = V_136 ;
if ( V_10 -> error != V_133 )
* V_138 = 0 ;
}
for ( V_58 = 0 ; V_58 < V_10 -> V_23 ; V_58 ++ ) {
T_1 V_108 = F_28 ( V_80 [ V_58 ] . V_108 ) ;
if ( V_108 == V_67 || V_108 > V_6 -> V_109 . V_110 )
continue;
F_37 ( V_6 , V_108 , V_10 -> V_78 [ V_58 ] ) ;
}
V_85 -= V_86 ;
if ( V_85 > 0 )
goto V_132;
return V_17 ;
}
static int F_79 ( struct V_6 * V_6 , struct V_45 * line )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_46 * V_47 = & V_8 -> V_47 ;
struct V_9 * V_10 ;
struct V_62 * V_78 ;
struct V_79 * V_80 ;
struct V_75 V_76 ;
void * V_81 ;
T_4 V_82 , V_83 ;
int V_138 , V_17 = 0 ;
V_10 = F_18 ( V_6 , V_140 ) ;
if ( F_19 ( V_10 ) )
return F_43 ( V_10 ) ;
V_80 = F_63 ( V_8 -> V_115 , V_19 , & V_83 ) ;
if ( ! V_80 ) {
V_17 = - V_37 ;
goto V_141;
}
V_78 = ( void * ) ( V_80 ) + V_122 ;
V_82 = V_83 + V_122 ;
V_81 = F_80 ( V_6 -> V_118 , V_47 -> V_94 , V_19 ) ;
if ( ! V_81 ) {
V_17 = - V_37 ;
goto V_142;
}
V_76 . V_78 = V_78 ;
V_76 . V_80 = V_80 ;
V_76 . V_10 = V_10 ;
V_76 . V_81 = V_81 ;
V_76 . V_82 = V_82 ;
V_76 . V_83 = V_83 ;
V_17 = F_78 ( V_6 , line , V_76 , & V_138 ) ;
if ( V_17 ) {
F_7 ( L_15 ) ;
goto V_143;
}
if ( ! V_138 ) {
V_17 = F_74 ( V_6 , line , V_76 ) ;
if ( V_17 ) {
F_7 ( L_15 ) ;
goto V_143;
}
}
if ( F_71 ( line ) )
F_81 ( V_6 , line ) ;
V_143:
F_73 ( V_81 ) ;
V_142:
F_56 ( V_8 -> V_115 , V_80 , V_83 ) ;
V_141:
F_16 ( V_6 , V_10 , V_140 ) ;
return V_17 ;
}
static void F_82 ( struct V_144 * V_145 ,
struct V_45 * line )
{
struct V_45 * V_146 = NULL ;
F_83 (t, head, list)
if ( V_146 -> V_147 > line -> V_147 )
break;
F_84 ( & line -> V_148 , V_146 -> V_148 . V_149 , & V_146 -> V_148 ) ;
}
struct V_45 * F_85 ( struct V_6 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_46 * V_47 = & V_8 -> V_47 ;
struct V_48 * V_49 = & V_6 -> V_49 ;
struct V_150 * V_151 = & V_6 -> V_151 ;
struct V_45 * line , * V_152 , * V_153 = NULL ;
struct V_154 * V_155 ;
struct V_50 * V_51 ;
struct V_156 * V_157 ;
int V_158 = 0 , V_159 = 0 , V_160 = 0 ;
int V_161 = 0 ;
int V_162 ;
int V_58 , V_163 = 0 ;
F_86 ( V_164 ) ;
F_32 ( & V_151 -> V_165 ) ;
V_162 = F_87 ( & V_151 -> V_166 , V_167 ) ;
F_88 ( V_162 , & V_151 -> V_166 ) ;
V_155 = V_151 -> V_168 [ V_162 ] ;
V_51 = V_151 -> V_169 [ V_162 ] ;
V_157 = (struct V_156 * ) V_155 ;
F_36 ( & V_151 -> V_165 ) ;
for ( V_58 = 0 ; V_58 < V_151 -> V_170 ; V_58 ++ ) {
T_3 V_41 ;
line = & V_6 -> V_171 [ V_58 ] ;
memset ( V_155 , 0 , V_49 -> V_172 ) ;
line -> V_155 = V_155 ;
line -> V_173 = ( ( void * ) ( V_157 ) ) +
sizeof( struct V_156 ) ;
if ( F_89 ( V_6 , line ) )
continue;
V_41 = F_90 ( V_6 , V_157 ) ;
if ( F_24 ( V_157 -> V_41 ) != V_41 )
continue;
if ( F_24 ( V_157 -> V_42 . V_43 ) != V_44 )
continue;
if ( F_91 ( V_157 -> V_42 . V_174 ) != 1 ) {
F_7 ( L_16 ,
V_157 -> V_42 . V_174 ) ;
return F_92 ( - V_175 ) ;
}
if ( ! V_163 ) {
memcpy ( V_6 -> V_176 , V_157 -> V_42 . V_177 , 16 ) ;
V_163 = 1 ;
}
if ( memcmp ( V_6 -> V_176 , V_157 -> V_42 . V_177 , 16 ) ) {
F_93 ( L_17 ,
V_58 ) ;
continue;
}
F_32 ( & line -> V_68 ) ;
line -> V_65 = F_24 ( V_157 -> V_42 . V_65 ) ;
line -> type = F_91 ( V_157 -> V_42 . type ) ;
line -> V_147 = F_28 ( V_157 -> V_147 ) ;
F_36 ( & line -> V_68 ) ;
F_32 ( & V_151 -> V_165 ) ;
if ( line -> V_147 >= V_151 -> V_178 )
V_151 -> V_178 = line -> V_147 + 1 ;
V_151 -> V_179 -- ;
F_36 ( & V_151 -> V_165 ) ;
if ( F_94 ( V_6 , line ) )
goto V_143;
F_82 ( & V_164 , line ) ;
V_158 ++ ;
F_93 ( L_18 ,
line -> V_65 , V_157 -> V_147 ) ;
}
if ( ! V_158 ) {
F_95 ( V_6 ) ;
F_32 ( & V_151 -> V_165 ) ;
F_96 ( ! F_97 ( V_162 ,
& V_151 -> V_166 ) ) ;
F_36 ( & V_151 -> V_165 ) ;
goto V_143;
}
F_98 (line, tline, &recov_list, list) {
int V_180 , V_72 ;
V_159 ++ ;
V_180 = V_49 -> V_60 - V_49 -> V_61 [ 0 ] ;
V_72 = F_5 ( line -> V_66 , V_49 -> V_73 ) ;
V_180 -= V_72 * V_47 -> V_181 ;
line -> V_182 = V_180 ;
line -> V_51 = V_51 ;
memset ( line -> V_51 -> V_52 , 0 , V_49 -> V_183 [ 0 ] ) ;
if ( F_99 ( V_6 , line , line -> V_51 -> V_52 ) ) {
F_79 ( V_6 , line ) ;
goto V_184;
}
if ( F_26 ( V_6 , line ) )
F_79 ( V_6 , line ) ;
V_184:
if ( F_71 ( line ) ) {
struct V_144 * V_185 ;
F_32 ( & line -> V_68 ) ;
line -> V_186 = V_187 ;
V_185 = F_100 ( V_6 , line ) ;
F_36 ( & line -> V_68 ) ;
F_32 ( & V_151 -> V_188 ) ;
F_101 ( & line -> V_148 , V_185 ) ;
F_36 ( & V_151 -> V_188 ) ;
F_14 ( line -> V_137 , V_6 -> V_189 ) ;
line -> V_137 = NULL ;
line -> V_155 = NULL ;
line -> V_51 = NULL ;
} else {
if ( V_160 > 1 )
F_7 ( L_19 ) ;
V_160 ++ ;
line -> V_162 = V_162 ;
V_153 = line ;
}
}
F_32 ( & V_151 -> V_165 ) ;
if ( ! V_160 ) {
F_96 ( ! F_97 ( V_162 ,
& V_151 -> V_166 ) ) ;
F_102 ( V_6 ) ;
} else {
V_151 -> V_190 = F_103 ( V_6 ) ;
if ( V_151 -> V_190 ) {
V_151 -> V_190 -> V_147 = V_151 -> V_178 ++ ;
V_151 -> V_190 -> type = V_191 ;
V_161 = 1 ;
}
}
F_36 ( & V_151 -> V_165 ) ;
if ( V_161 ) {
F_104 ( V_6 , V_151 -> V_190 ) ;
F_105 ( & V_6 -> V_109 , V_151 -> V_190 ) ;
}
V_143:
if ( V_158 != V_159 )
F_7 ( L_20 ,
V_158 , V_159 ) ;
return V_153 ;
}
int F_106 ( struct V_6 * V_6 )
{
struct V_45 * line ;
struct V_150 * V_151 = & V_6 -> V_151 ;
int V_71 ;
int V_17 = 0 ;
F_32 ( & V_151 -> V_165 ) ;
line = V_151 -> V_153 ;
V_71 = line -> V_71 ;
F_36 ( & V_151 -> V_165 ) ;
V_17 = F_58 ( V_6 , line , V_71 ) ;
if ( V_17 ) {
F_7 ( L_21 , V_17 ) ;
return V_17 ;
}
F_107 ( V_6 , line ) ;
return V_17 ;
}
