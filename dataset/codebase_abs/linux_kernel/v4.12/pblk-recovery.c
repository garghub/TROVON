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
return F_25 ( V_40 ) ;
}
static int F_26 ( struct V_6 * V_6 , struct V_45 * line )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_46 * V_47 = & V_8 -> V_47 ;
struct V_48 * V_49 = & V_6 -> V_49 ;
struct V_39 * V_40 = line -> V_40 ;
T_2 * V_50 ;
int V_51 ;
int V_52 , V_53 , V_54 = 0 ;
int V_55 ;
V_50 = F_22 ( V_6 , V_40 ) ;
if ( ! V_50 )
return 1 ;
V_51 = F_27 ( V_6 , line ) + V_49 -> V_56 ;
V_52 = V_49 -> V_57 - V_49 -> V_58 ;
V_53 = F_28 ( V_40 -> V_53 ) ;
for ( V_55 = V_51 ; V_55 < V_52 && V_54 < V_53 ; V_55 ++ ) {
struct V_59 V_60 ;
int V_61 ;
V_60 = F_29 ( V_6 , V_55 , line -> V_62 ) ;
V_61 = F_30 ( V_47 , V_60 ) ;
if ( F_31 ( V_61 , line -> V_63 ) )
continue;
if ( F_28 ( V_50 [ V_55 ] ) == V_64 ) {
F_32 ( & line -> V_65 ) ;
if ( F_33 ( V_55 , line -> V_66 ) )
F_34 ( 1 , L_6 ) ;
else
line -> V_67 -- ;
F_35 ( & line -> V_65 ) ;
continue;
}
F_36 ( V_6 , F_28 ( V_50 [ V_55 ] ) , V_60 ) ;
V_54 ++ ;
}
if ( V_53 != V_54 )
F_7 ( L_7 ,
line -> V_62 , line -> V_40 -> V_53 , V_54 ) ;
line -> V_68 = 0 ;
return 0 ;
}
static int F_37 ( struct V_6 * V_6 , struct V_45 * line )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_46 * V_47 = & V_8 -> V_47 ;
struct V_48 * V_49 = & V_6 -> V_49 ;
int V_69 = F_5 ( line -> V_63 , V_49 -> V_70 ) ;
return V_49 -> V_57 - V_49 -> V_56 - V_49 -> V_58 -
V_69 * V_47 -> V_71 ;
}
static int F_38 ( struct V_6 * V_6 , struct V_45 * line ,
struct V_72 V_73 , T_1 V_74 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_46 * V_47 = & V_8 -> V_47 ;
struct V_59 * V_75 ;
struct V_76 * V_77 ;
struct V_9 * V_10 ;
struct V_14 * V_14 ;
void * V_78 ;
T_4 V_79 , V_80 ;
T_1 V_81 ;
int V_82 ;
int V_83 , V_84 ;
int V_55 , V_85 ;
int V_17 = 0 ;
F_39 ( V_86 ) ;
V_75 = V_73 . V_75 ;
V_77 = V_73 . V_77 ;
V_10 = V_73 . V_10 ;
V_78 = V_73 . V_78 ;
V_79 = V_73 . V_79 ;
V_80 = V_73 . V_80 ;
V_82 = line -> V_87 - V_74 ;
if ( ! V_82 )
return 0 ;
V_81 = V_74 ;
V_88:
memset ( V_10 , 0 , V_89 ) ;
V_83 = F_40 ( V_6 , V_82 , 0 ) ;
if ( ! V_83 )
V_83 = V_6 -> V_90 ;
V_84 = V_83 * V_47 -> V_91 ;
V_14 = F_41 ( V_8 -> V_92 , V_78 , V_84 , V_19 ) ;
if ( F_19 ( V_14 ) )
return F_42 ( V_14 ) ;
V_14 -> V_20 . V_21 = 0 ;
F_8 ( V_14 , V_93 , 0 ) ;
V_10 -> V_14 = V_14 ;
V_10 -> V_94 = V_95 ;
V_10 -> V_96 = F_43 ( V_6 ) ;
V_10 -> V_77 = V_77 ;
V_10 -> V_23 = V_83 ;
V_10 -> V_75 = V_75 ;
V_10 -> V_79 = V_79 ;
V_10 -> V_80 = V_80 ;
V_10 -> V_97 = V_98 ;
V_10 -> V_99 = & V_86 ;
for ( V_55 = 0 ; V_55 < V_10 -> V_23 ; ) {
struct V_59 V_60 ;
int V_61 ;
V_60 = F_44 ( V_6 , V_81 , line -> V_62 ) ;
V_61 = F_45 ( V_47 , V_60 ) ;
while ( F_31 ( V_61 , line -> V_63 ) ) {
V_81 += V_6 -> V_90 ;
V_60 = F_44 ( V_6 , V_81 , line -> V_62 ) ;
V_61 = F_45 ( V_47 , V_60 ) ;
}
for ( V_85 = 0 ; V_85 < V_6 -> V_90 ; V_85 ++ , V_55 ++ , V_81 ++ )
V_10 -> V_75 [ V_55 ] =
F_44 ( V_6 , V_81 , line -> V_62 ) ;
}
V_17 = F_13 ( V_6 , V_10 ) ;
if ( V_17 ) {
F_7 ( L_4 , V_17 ) ;
return V_17 ;
}
if ( ! F_46 ( & V_86 ,
F_47 ( V_100 ) ) ) {
F_7 ( L_8 ) ;
return - V_101 ;
}
F_48 ( & V_86 ) ;
if ( V_10 -> error ) {
F_7 ( L_9 , V_10 -> error ) ;
return - V_101 ;
}
for ( V_55 = 0 ; V_55 < V_10 -> V_23 ; V_55 ++ ) {
T_1 V_102 = F_28 ( V_77 [ V_55 ] . V_102 ) ;
if ( V_102 == V_64 || V_102 > V_6 -> V_103 . V_104 )
continue;
F_36 ( V_6 , V_102 , V_10 -> V_75 [ V_55 ] ) ;
}
V_82 -= V_83 ;
if ( V_82 > 0 )
goto V_88;
return 0 ;
}
static int F_49 ( struct V_6 * V_6 , struct V_45 * line ,
struct V_72 V_73 , int V_82 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_46 * V_47 = & V_8 -> V_47 ;
struct V_59 * V_75 ;
struct V_76 * V_77 ;
struct V_9 * V_10 ;
struct V_14 * V_14 ;
void * V_78 ;
T_4 V_79 , V_80 ;
T_2 * V_50 = F_25 ( line -> V_40 ) ;
T_1 V_105 = line -> V_87 ;
int V_106 = line -> V_68 ;
int V_83 , V_84 ;
int V_55 , V_85 ;
int V_17 = 0 ;
F_39 ( V_86 ) ;
V_75 = V_73 . V_75 ;
V_77 = V_73 . V_77 ;
V_10 = V_73 . V_10 ;
V_78 = V_73 . V_78 ;
V_79 = V_73 . V_79 ;
V_80 = V_73 . V_80 ;
V_107:
V_83 = F_40 ( V_6 , V_82 , 0 ) ;
if ( ! V_83 )
V_83 = V_6 -> V_90 ;
V_84 = V_83 * V_47 -> V_91 ;
V_14 = F_41 ( V_8 -> V_92 , V_78 , V_84 , V_19 ) ;
if ( F_19 ( V_14 ) )
return F_42 ( V_14 ) ;
V_14 -> V_20 . V_21 = 0 ;
F_8 ( V_14 , V_22 , 0 ) ;
memset ( V_10 , 0 , V_89 ) ;
V_10 -> V_14 = V_14 ;
V_10 -> V_94 = V_108 ;
V_10 -> V_96 = F_50 ( V_6 , V_29 ) ;
V_10 -> V_77 = V_77 ;
V_10 -> V_23 = V_83 ;
V_10 -> V_75 = V_75 ;
V_10 -> V_79 = V_79 ;
V_10 -> V_80 = V_80 ;
V_10 -> V_97 = V_98 ;
V_10 -> V_99 = & V_86 ;
for ( V_55 = 0 ; V_55 < V_10 -> V_23 ; ) {
struct V_59 V_60 ;
int V_61 ;
V_105 = F_51 ( V_6 , line , V_6 -> V_90 ) ;
V_60 = F_29 ( V_6 , V_105 , line -> V_62 ) ;
V_61 = F_30 ( V_47 , V_60 ) ;
while ( F_31 ( V_61 , line -> V_63 ) ) {
V_105 += V_6 -> V_90 ;
V_60 = F_29 ( V_6 , V_105 , line -> V_62 ) ;
V_61 = F_30 ( V_47 , V_60 ) ;
}
for ( V_85 = 0 ; V_85 < V_6 -> V_90 ; V_85 ++ , V_55 ++ , V_105 ++ ) {
struct V_59 V_109 ;
V_109 = F_44 ( V_6 , V_105 , line -> V_62 ) ;
F_52 ( V_6 , V_109 ) ;
V_77 [ V_55 ] . V_102 = F_53 ( V_64 ) ;
V_50 [ V_105 ] = F_53 ( V_64 ) ;
V_10 -> V_75 [ V_55 ] = V_109 ;
}
}
V_17 = F_13 ( V_6 , V_10 ) ;
if ( V_17 ) {
F_7 ( L_4 , V_17 ) ;
return V_17 ;
}
if ( ! F_46 ( & V_86 ,
F_47 ( V_100 ) ) ) {
F_7 ( L_10 ) ;
}
F_48 ( & V_86 ) ;
V_106 -= V_83 ;
V_82 -= V_83 ;
if ( V_82 > 0 && V_106 )
goto V_107;
return 0 ;
}
static int F_54 ( struct V_6 * V_6 , struct V_45 * line ,
struct V_72 V_73 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_46 * V_47 = & V_8 -> V_47 ;
struct V_59 * V_75 ;
struct V_76 * V_77 ;
struct V_9 * V_10 ;
struct V_14 * V_14 ;
void * V_78 ;
T_4 V_79 , V_80 ;
T_1 V_105 = 0 , V_74 ;
int V_83 , V_84 ;
int V_55 , V_85 ;
int V_17 = 0 ;
int V_110 ;
int V_82 = F_37 ( V_6 , line ) - line -> V_87 ;
F_39 ( V_86 ) ;
V_75 = V_73 . V_75 ;
V_77 = V_73 . V_77 ;
V_10 = V_73 . V_10 ;
V_78 = V_73 . V_78 ;
V_79 = V_73 . V_79 ;
V_80 = V_73 . V_80 ;
V_74 = line -> V_87 ;
V_110 = 0 ;
V_111:
memset ( V_10 , 0 , V_89 ) ;
V_83 = F_40 ( V_6 , V_82 , 0 ) ;
if ( ! V_83 )
V_83 = V_6 -> V_90 ;
V_84 = V_83 * V_47 -> V_91 ;
V_14 = F_41 ( V_8 -> V_92 , V_78 , V_84 , V_19 ) ;
if ( F_19 ( V_14 ) )
return F_42 ( V_14 ) ;
V_14 -> V_20 . V_21 = 0 ;
F_8 ( V_14 , V_93 , 0 ) ;
V_10 -> V_14 = V_14 ;
V_10 -> V_94 = V_95 ;
V_10 -> V_96 = F_43 ( V_6 ) ;
V_10 -> V_77 = V_77 ;
V_10 -> V_23 = V_83 ;
V_10 -> V_75 = V_75 ;
V_10 -> V_79 = V_79 ;
V_10 -> V_80 = V_80 ;
V_10 -> V_97 = V_98 ;
V_10 -> V_99 = & V_86 ;
for ( V_55 = 0 ; V_55 < V_10 -> V_23 ; ) {
struct V_59 V_60 ;
int V_61 ;
V_105 = F_51 ( V_6 , line , V_6 -> V_90 ) ;
V_60 = F_44 ( V_6 , V_105 , line -> V_62 ) ;
V_61 = F_45 ( V_47 , V_60 ) ;
while ( F_31 ( V_61 , line -> V_63 ) ) {
V_105 += V_6 -> V_90 ;
V_60 = F_44 ( V_6 , V_105 , line -> V_62 ) ;
V_61 = F_45 ( V_47 , V_60 ) ;
}
for ( V_85 = 0 ; V_85 < V_6 -> V_90 ; V_85 ++ , V_55 ++ , V_105 ++ )
V_10 -> V_75 [ V_55 ] =
F_44 ( V_6 , V_105 , line -> V_62 ) ;
}
V_17 = F_13 ( V_6 , V_10 ) ;
if ( V_17 ) {
F_7 ( L_4 , V_17 ) ;
return V_17 ;
}
if ( ! F_46 ( & V_86 ,
F_47 ( V_100 ) ) ) {
F_7 ( L_8 ) ;
}
F_48 ( & V_86 ) ;
if ( ! V_110 ++ && ! V_10 -> error ) {
V_110 = 0 ;
for ( V_55 = 0 ; V_55 < V_10 -> V_23 ; V_55 ++ , V_74 ++ ) {
T_1 V_102 = F_28 ( V_77 [ V_55 ] . V_102 ) ;
if ( V_102 == V_64 || V_102 > V_6 -> V_103 . V_104 )
continue;
F_36 ( V_6 , V_102 , V_10 -> V_75 [ V_55 ] ) ;
}
}
if ( V_10 -> error == V_112 ) {
int V_113 , V_114 , V_115 ;
int V_17 ;
V_115 = F_55 ( ( void * ) & V_10 -> V_18 , V_10 -> V_23 ) ;
V_114 = V_10 -> V_23 - V_115 ;
line -> V_87 -= V_114 ;
line -> V_68 += V_114 ;
F_56 ( line -> V_116 , line -> V_87 , V_114 ) ;
V_113 = F_57 ( V_6 ) ;
if ( V_113 > line -> V_68 )
V_113 = line -> V_68 ;
V_17 = F_49 ( V_6 , line , V_73 , V_113 ) ;
if ( V_17 )
F_7 ( L_11 , V_17 ) ;
V_17 = F_38 ( V_6 , line , V_73 , V_74 ) ;
if ( V_17 )
F_7 ( L_12 , V_17 ) ;
line -> V_117 = line -> V_68 ;
V_82 = 0 ;
}
V_82 -= V_83 ;
if ( V_82 > 0 )
goto V_111;
return V_17 ;
}
static int F_58 ( struct V_6 * V_6 , struct V_45 * line ,
struct V_72 V_73 , int * V_118 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_46 * V_47 = & V_8 -> V_47 ;
struct V_59 * V_75 ;
struct V_76 * V_77 ;
struct V_9 * V_10 ;
struct V_14 * V_14 ;
void * V_78 ;
T_4 V_79 , V_80 ;
T_1 V_119 ;
int V_83 , V_84 ;
int V_55 , V_85 ;
int V_17 = 0 ;
int V_82 = F_37 ( V_6 , line ) ;
F_39 ( V_86 ) ;
V_75 = V_73 . V_75 ;
V_77 = V_73 . V_77 ;
V_10 = V_73 . V_10 ;
V_78 = V_73 . V_78 ;
V_79 = V_73 . V_79 ;
V_80 = V_73 . V_80 ;
* V_118 = 1 ;
V_111:
memset ( V_10 , 0 , V_89 ) ;
V_83 = F_40 ( V_6 , V_82 , 0 ) ;
if ( ! V_83 )
V_83 = V_6 -> V_90 ;
V_84 = V_83 * V_47 -> V_91 ;
V_14 = F_41 ( V_8 -> V_92 , V_78 , V_84 , V_19 ) ;
if ( F_19 ( V_14 ) )
return F_42 ( V_14 ) ;
V_14 -> V_20 . V_21 = 0 ;
F_8 ( V_14 , V_93 , 0 ) ;
V_10 -> V_14 = V_14 ;
V_10 -> V_94 = V_95 ;
V_10 -> V_96 = F_43 ( V_6 ) ;
V_10 -> V_77 = V_77 ;
V_10 -> V_23 = V_83 ;
V_10 -> V_75 = V_75 ;
V_10 -> V_79 = V_79 ;
V_10 -> V_80 = V_80 ;
V_10 -> V_97 = V_98 ;
V_10 -> V_99 = & V_86 ;
for ( V_55 = 0 ; V_55 < V_10 -> V_23 ; ) {
struct V_59 V_60 ;
int V_61 ;
V_119 = F_51 ( V_6 , line , V_6 -> V_90 ) ;
V_60 = F_44 ( V_6 , V_119 , line -> V_62 ) ;
V_61 = F_45 ( V_47 , V_60 ) ;
while ( F_31 ( V_61 , line -> V_63 ) ) {
V_119 += V_6 -> V_90 ;
V_60 = F_44 ( V_6 , V_119 , line -> V_62 ) ;
V_61 = F_45 ( V_47 , V_60 ) ;
}
for ( V_85 = 0 ; V_85 < V_6 -> V_90 ; V_85 ++ , V_55 ++ , V_119 ++ )
V_10 -> V_75 [ V_55 ] =
F_44 ( V_6 , V_119 , line -> V_62 ) ;
}
V_17 = F_13 ( V_6 , V_10 ) ;
if ( V_17 ) {
F_7 ( L_4 , V_17 ) ;
F_15 ( V_14 ) ;
return V_17 ;
}
if ( ! F_46 ( & V_86 ,
F_47 ( V_100 ) ) ) {
F_7 ( L_8 ) ;
}
F_48 ( & V_86 ) ;
if ( V_10 -> error ) {
int V_114 , V_115 ;
V_115 = F_55 ( ( void * ) & V_10 -> V_18 , V_10 -> V_23 ) ;
V_114 = V_10 -> V_23 - V_115 ;
line -> V_87 -= V_114 ;
line -> V_68 += V_114 ;
line -> V_117 = line -> V_68 ;
F_56 ( line -> V_116 , line -> V_87 , V_114 ) ;
V_82 = 0 ;
V_10 -> V_23 = V_115 ;
if ( V_10 -> error != V_112 )
* V_118 = 0 ;
}
for ( V_55 = 0 ; V_55 < V_10 -> V_23 ; V_55 ++ ) {
T_1 V_102 = F_28 ( V_77 [ V_55 ] . V_102 ) ;
if ( V_102 == V_64 || V_102 > V_6 -> V_103 . V_104 )
continue;
F_36 ( V_6 , V_102 , V_10 -> V_75 [ V_55 ] ) ;
}
V_82 -= V_83 ;
if ( V_82 > 0 )
goto V_111;
return V_17 ;
}
static int F_59 ( struct V_6 * V_6 , struct V_45 * line )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_46 * V_47 = & V_8 -> V_47 ;
struct V_9 * V_10 ;
struct V_59 * V_75 ;
struct V_76 * V_77 ;
struct V_72 V_73 ;
void * V_78 ;
T_4 V_79 , V_80 ;
int V_118 , V_17 = 0 ;
V_10 = F_18 ( V_6 , V_120 ) ;
if ( F_19 ( V_10 ) )
return F_42 ( V_10 ) ;
V_77 = F_60 ( V_8 -> V_121 , V_19 , & V_80 ) ;
if ( ! V_77 ) {
V_17 = - V_37 ;
goto V_122;
}
V_75 = ( void * ) ( V_77 ) + V_123 ;
V_79 = V_80 + V_123 ;
V_78 = F_61 ( V_6 -> V_124 , V_47 -> V_91 , V_19 ) ;
if ( ! V_78 ) {
V_17 = - V_37 ;
goto V_125;
}
V_73 . V_75 = V_75 ;
V_73 . V_77 = V_77 ;
V_73 . V_10 = V_10 ;
V_73 . V_78 = V_78 ;
V_73 . V_79 = V_79 ;
V_73 . V_80 = V_80 ;
V_17 = F_58 ( V_6 , line , V_73 , & V_118 ) ;
if ( V_17 ) {
F_7 ( L_13 ) ;
goto V_126;
}
if ( ! V_118 ) {
V_17 = F_54 ( V_6 , line , V_73 ) ;
if ( V_17 ) {
F_7 ( L_13 ) ;
goto V_126;
}
}
if ( F_62 ( line ) )
F_63 ( V_6 , line ) ;
V_126:
F_64 ( V_78 ) ;
V_125:
F_65 ( V_8 -> V_121 , V_77 , V_80 ) ;
V_122:
F_16 ( V_6 , V_10 , V_120 ) ;
return V_17 ;
}
static void F_66 ( struct V_127 * V_128 ,
struct V_45 * line )
{
struct V_45 * V_129 = NULL ;
F_67 (t, head, list)
if ( V_129 -> V_130 > line -> V_130 )
break;
F_68 ( & line -> V_131 , V_129 -> V_131 . V_132 , & V_129 -> V_131 ) ;
}
struct V_45 * F_69 ( struct V_6 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_46 * V_47 = & V_8 -> V_47 ;
struct V_48 * V_49 = & V_6 -> V_49 ;
struct V_133 * V_134 = & V_6 -> V_134 ;
struct V_45 * line , * V_135 , * V_136 = NULL ;
struct V_137 * V_138 ;
struct V_39 * V_40 ;
int V_139 = 0 , V_140 = 0 , V_141 = 0 ;
int V_142 = 0 ;
int V_143 ;
int V_55 , V_144 = 0 ;
F_70 ( V_145 ) ;
F_32 ( & V_134 -> V_146 ) ;
V_143 = F_71 ( & V_134 -> V_147 , V_148 ) ;
F_72 ( V_143 , & V_134 -> V_147 ) ;
V_138 = V_134 -> V_149 [ V_143 ] . V_150 ;
V_40 = V_134 -> V_151 [ V_143 ] . V_150 ;
F_35 ( & V_134 -> V_146 ) ;
for ( V_55 = 0 ; V_55 < V_134 -> V_152 ; V_55 ++ ) {
T_3 V_41 ;
line = & V_6 -> V_153 [ V_55 ] ;
memset ( V_138 , 0 , V_49 -> V_154 ) ;
line -> V_138 = V_138 ;
line -> V_155 = ( ( void * ) ( V_138 ) ) +
sizeof( struct V_137 ) ;
if ( F_73 ( V_6 , line ) )
continue;
V_41 = F_74 ( V_6 , V_138 ) ;
if ( F_24 ( V_138 -> V_41 ) != V_41 )
continue;
if ( F_24 ( V_138 -> V_42 . V_43 ) != V_44 )
continue;
if ( F_75 ( V_138 -> V_42 . V_156 ) != 1 ) {
F_7 ( L_14 ,
V_138 -> V_42 . V_156 ) ;
return F_76 ( - V_157 ) ;
}
if ( ! V_144 ) {
memcpy ( V_6 -> V_158 , V_138 -> V_42 . V_159 , 16 ) ;
V_144 = 1 ;
}
if ( memcmp ( V_6 -> V_158 , V_138 -> V_42 . V_159 , 16 ) ) {
F_77 ( L_15 ,
V_55 ) ;
continue;
}
F_32 ( & line -> V_65 ) ;
line -> V_62 = F_24 ( line -> V_138 -> V_42 . V_62 ) ;
line -> type = F_75 ( line -> V_138 -> V_42 . type ) ;
line -> V_130 = F_28 ( line -> V_138 -> V_130 ) ;
F_35 ( & line -> V_65 ) ;
F_32 ( & V_134 -> V_146 ) ;
if ( line -> V_130 >= V_134 -> V_160 )
V_134 -> V_160 = line -> V_130 + 1 ;
V_134 -> V_161 -- ;
F_35 ( & V_134 -> V_146 ) ;
if ( F_78 ( V_6 , line ) )
goto V_126;
F_66 ( & V_145 , line ) ;
V_139 ++ ;
F_77 ( L_16 ,
line -> V_62 , V_138 -> V_130 ) ;
}
if ( ! V_139 ) {
F_79 ( V_6 ) ;
F_32 ( & V_134 -> V_146 ) ;
F_80 ( ! F_81 ( V_143 ,
& V_134 -> V_147 ) ) ;
F_35 ( & V_134 -> V_146 ) ;
goto V_126;
}
F_82 (line, tline, &recov_list, list) {
int V_162 , V_69 ;
V_140 ++ ;
V_162 = V_49 -> V_57 - V_49 -> V_58 ;
V_69 = F_5 ( line -> V_63 , V_49 -> V_70 ) ;
V_162 -= V_69 * V_47 -> V_163 ;
memset ( V_40 , 0 , V_49 -> V_164 ) ;
line -> V_40 = V_40 ;
line -> V_165 = V_162 ;
if ( F_83 ( V_6 , line ) ) {
F_59 ( V_6 , line ) ;
goto V_166;
}
if ( F_26 ( V_6 , line ) )
F_59 ( V_6 , line ) ;
V_166:
if ( F_62 ( line ) ) {
struct V_127 * V_167 ;
F_32 ( & line -> V_65 ) ;
line -> V_168 = V_169 ;
V_167 = F_84 ( V_6 , line ) ;
F_35 ( & line -> V_65 ) ;
F_32 ( & V_134 -> V_170 ) ;
F_85 ( & line -> V_131 , V_167 ) ;
F_35 ( & V_134 -> V_170 ) ;
F_14 ( line -> V_116 , V_6 -> V_171 ) ;
line -> V_116 = NULL ;
line -> V_138 = NULL ;
line -> V_40 = NULL ;
} else {
if ( V_141 > 1 )
F_7 ( L_17 ) ;
V_141 ++ ;
line -> V_143 = V_143 ;
V_136 = line ;
}
}
F_32 ( & V_134 -> V_146 ) ;
if ( ! V_141 ) {
F_80 ( ! F_81 ( V_143 ,
& V_134 -> V_147 ) ) ;
F_86 ( V_6 ) ;
} else {
V_134 -> V_172 = F_87 ( V_6 ) ;
if ( V_134 -> V_172 ) {
V_134 -> V_172 -> V_130 = V_134 -> V_160 ++ ;
V_134 -> V_172 -> type = V_173 ;
V_142 = 1 ;
}
}
F_35 ( & V_134 -> V_146 ) ;
if ( V_142 ) {
F_88 ( V_6 , V_134 -> V_172 ) ;
F_89 ( & V_6 -> V_103 , V_134 -> V_172 ) ;
}
V_126:
if ( V_139 != V_140 )
F_7 ( L_18 ,
V_139 , V_140 ) ;
return V_136 ;
}
void F_90 ( struct V_6 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_46 * V_47 = & V_8 -> V_47 ;
struct V_45 * line ;
struct V_133 * V_134 = & V_6 -> V_134 ;
struct V_9 * V_10 ;
struct V_72 V_73 ;
struct V_59 * V_75 ;
struct V_76 * V_77 ;
void * V_78 ;
T_4 V_79 , V_80 ;
F_32 ( & V_134 -> V_146 ) ;
line = V_134 -> V_136 ;
F_35 ( & V_134 -> V_146 ) ;
V_10 = F_18 ( V_6 , V_120 ) ;
if ( F_19 ( V_10 ) )
return;
V_77 = F_60 ( V_8 -> V_121 , V_19 , & V_80 ) ;
if ( ! V_77 )
goto V_122;
V_75 = ( void * ) ( V_77 ) + V_123 ;
V_79 = V_80 + V_123 ;
V_78 = F_61 ( V_6 -> V_124 , V_47 -> V_91 , V_19 ) ;
if ( ! V_78 )
goto V_125;
V_73 . V_75 = V_75 ;
V_73 . V_77 = V_77 ;
V_73 . V_10 = V_10 ;
V_73 . V_78 = V_78 ;
V_73 . V_79 = V_79 ;
V_73 . V_80 = V_80 ;
if ( F_49 ( V_6 , line , V_73 , line -> V_68 ) ) {
F_7 ( L_19 ) ;
goto V_174;
}
F_91 ( V_6 , line ) ;
V_174:
F_64 ( V_78 ) ;
V_125:
F_65 ( V_8 -> V_121 , V_77 , V_80 ) ;
V_122:
F_16 ( V_6 , V_10 , V_120 ) ;
}
