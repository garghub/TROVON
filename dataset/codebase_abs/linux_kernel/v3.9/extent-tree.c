static T_1 int
F_1 ( struct V_1 * V_2 )
{
F_2 () ;
return V_2 -> V_3 == V_4 ;
}
static int F_3 ( struct V_1 * V_2 , T_2 V_5 )
{
return ( V_2 -> V_6 & V_5 ) == V_5 ;
}
static void F_4 ( struct V_1 * V_2 )
{
F_5 ( & V_2 -> V_7 ) ;
}
void F_6 ( struct V_1 * V_2 )
{
if ( F_7 ( & V_2 -> V_7 ) ) {
F_8 ( V_2 -> V_8 > 0 ) ;
F_8 ( V_2 -> V_9 > 0 ) ;
F_9 ( V_2 -> V_10 ) ;
F_9 ( V_2 ) ;
}
}
static int F_10 ( struct V_11 * V_12 ,
struct V_1 * V_13 )
{
struct V_14 * * V_15 ;
struct V_14 * V_16 = NULL ;
struct V_1 * V_2 ;
F_11 ( & V_12 -> V_17 ) ;
V_15 = & V_12 -> V_18 . V_14 ;
while ( * V_15 ) {
V_16 = * V_15 ;
V_2 = F_12 ( V_16 , struct V_1 ,
V_19 ) ;
if ( V_13 -> V_20 . V_21 < V_2 -> V_20 . V_21 ) {
V_15 = & ( * V_15 ) -> V_22 ;
} else if ( V_13 -> V_20 . V_21 > V_2 -> V_20 . V_21 ) {
V_15 = & ( * V_15 ) -> V_23 ;
} else {
F_13 ( & V_12 -> V_17 ) ;
return - V_24 ;
}
}
F_14 ( & V_13 -> V_19 , V_16 , V_15 ) ;
F_15 ( & V_13 -> V_19 ,
& V_12 -> V_18 ) ;
if ( V_12 -> V_25 > V_13 -> V_20 . V_21 )
V_12 -> V_25 = V_13 -> V_20 . V_21 ;
F_13 ( & V_12 -> V_17 ) ;
return 0 ;
}
static struct V_1 *
F_16 ( struct V_11 * V_12 , T_2 V_26 ,
int V_27 )
{
struct V_1 * V_2 , * V_28 = NULL ;
struct V_14 * V_29 ;
T_2 V_30 , V_31 ;
F_11 ( & V_12 -> V_17 ) ;
V_29 = V_12 -> V_18 . V_14 ;
while ( V_29 ) {
V_2 = F_12 ( V_29 , struct V_1 ,
V_19 ) ;
V_30 = V_2 -> V_20 . V_21 + V_2 -> V_20 . V_32 - 1 ;
V_31 = V_2 -> V_20 . V_21 ;
if ( V_26 < V_31 ) {
if ( ! V_27 && ( ! V_28 || V_31 < V_28 -> V_20 . V_21 ) )
V_28 = V_2 ;
V_29 = V_29 -> V_22 ;
} else if ( V_26 > V_31 ) {
if ( V_27 && V_26 <= V_30 ) {
V_28 = V_2 ;
break;
}
V_29 = V_29 -> V_23 ;
} else {
V_28 = V_2 ;
break;
}
}
if ( V_28 ) {
F_4 ( V_28 ) ;
if ( V_26 == 0 && V_12 -> V_25 > V_28 -> V_20 . V_21 )
V_12 -> V_25 = V_28 -> V_20 . V_21 ;
}
F_13 ( & V_12 -> V_17 ) ;
return V_28 ;
}
static int F_17 ( struct V_33 * V_34 ,
T_2 V_31 , T_2 V_35 )
{
T_2 V_30 = V_31 + V_35 - 1 ;
F_18 ( & V_34 -> V_36 -> V_37 [ 0 ] ,
V_31 , V_30 , V_38 , V_39 ) ;
F_18 ( & V_34 -> V_36 -> V_37 [ 1 ] ,
V_31 , V_30 , V_38 , V_39 ) ;
return 0 ;
}
static void F_19 ( struct V_33 * V_34 ,
struct V_1 * V_2 )
{
T_2 V_31 , V_30 ;
V_31 = V_2 -> V_20 . V_21 ;
V_30 = V_31 + V_2 -> V_20 . V_32 - 1 ;
F_20 ( & V_34 -> V_36 -> V_37 [ 0 ] ,
V_31 , V_30 , V_38 , V_39 ) ;
F_20 ( & V_34 -> V_36 -> V_37 [ 1 ] ,
V_31 , V_30 , V_38 , V_39 ) ;
}
static int F_21 ( struct V_33 * V_34 ,
struct V_1 * V_2 )
{
T_2 V_26 ;
T_2 * V_40 ;
int V_41 ;
int V_42 , V_43 , V_28 ;
if ( V_2 -> V_20 . V_21 < V_44 ) {
V_41 = V_44 - V_2 -> V_20 . V_21 ;
V_2 -> V_45 += V_41 ;
V_28 = F_17 ( V_34 , V_2 -> V_20 . V_21 ,
V_41 ) ;
if ( V_28 )
return V_28 ;
}
for ( V_42 = 0 ; V_42 < V_46 ; V_42 ++ ) {
V_26 = F_22 ( V_42 ) ;
V_28 = F_23 ( & V_34 -> V_36 -> V_47 ,
V_2 -> V_20 . V_21 , V_26 ,
0 , & V_40 , & V_43 , & V_41 ) ;
if ( V_28 )
return V_28 ;
while ( V_43 -- ) {
V_2 -> V_45 += V_41 ;
V_28 = F_17 ( V_34 , V_40 [ V_43 ] ,
V_41 ) ;
if ( V_28 ) {
F_9 ( V_40 ) ;
return V_28 ;
}
}
F_9 ( V_40 ) ;
}
return 0 ;
}
static struct V_48 *
F_24 ( struct V_1 * V_2 )
{
struct V_48 * V_49 ;
F_11 ( & V_2 -> V_50 ) ;
if ( V_2 -> V_3 != V_51 ) {
F_13 ( & V_2 -> V_50 ) ;
return NULL ;
}
if ( ! V_2 -> V_52 ) {
F_13 ( & V_2 -> V_50 ) ;
return NULL ;
}
V_49 = V_2 -> V_52 ;
F_5 ( & V_49 -> V_7 ) ;
F_13 ( & V_2 -> V_50 ) ;
return V_49 ;
}
static void F_25 ( struct V_48 * V_49 )
{
if ( F_7 ( & V_49 -> V_7 ) )
F_9 ( V_49 ) ;
}
static T_2 F_26 ( struct V_1 * V_13 ,
struct V_11 * V_12 , T_2 V_31 , T_2 V_30 )
{
T_2 V_53 , V_54 , V_55 , V_56 = 0 ;
int V_28 ;
while ( V_31 < V_30 ) {
V_28 = F_27 ( V_12 -> V_57 , V_31 ,
& V_53 , & V_54 ,
V_58 | V_38 ,
NULL ) ;
if ( V_28 )
break;
if ( V_53 <= V_31 ) {
V_31 = V_54 + 1 ;
} else if ( V_53 > V_31 && V_53 < V_30 ) {
V_55 = V_53 - V_31 ;
V_56 += V_55 ;
V_28 = F_28 ( V_13 , V_31 ,
V_55 ) ;
F_29 ( V_28 ) ;
V_31 = V_54 + 1 ;
} else {
break;
}
}
if ( V_31 < V_30 ) {
V_55 = V_30 - V_31 ;
V_56 += V_55 ;
V_28 = F_28 ( V_13 , V_31 , V_55 ) ;
F_29 ( V_28 ) ;
}
return V_56 ;
}
static T_1 void F_30 ( struct V_59 * V_60 )
{
struct V_1 * V_13 ;
struct V_11 * V_36 ;
struct V_48 * V_52 ;
struct V_33 * V_61 ;
struct V_62 * V_63 ;
struct V_64 * V_65 ;
struct V_66 V_20 ;
T_2 V_67 = 0 ;
T_2 V_68 = 0 ;
T_3 V_69 ;
int V_28 = 0 ;
V_52 = F_31 ( V_60 , struct V_48 , V_60 ) ;
V_13 = V_52 -> V_13 ;
V_36 = V_13 -> V_36 ;
V_61 = V_36 -> V_61 ;
V_63 = F_32 () ;
if ( ! V_63 )
goto V_70;
V_68 = F_33 ( T_2 , V_13 -> V_20 . V_21 , V_44 ) ;
V_63 -> V_71 = 1 ;
V_63 -> V_72 = 1 ;
V_63 -> V_73 = 1 ;
V_20 . V_21 = V_68 ;
V_20 . V_32 = 0 ;
V_20 . type = V_74 ;
V_75:
F_34 ( & V_52 -> V_76 ) ;
F_35 ( & V_36 -> V_77 ) ;
V_28 = F_36 ( NULL , V_61 , & V_20 , V_63 , 0 , 0 ) ;
if ( V_28 < 0 )
goto V_78;
V_65 = V_63 -> V_79 [ 0 ] ;
V_69 = F_37 ( V_65 ) ;
while ( 1 ) {
if ( F_38 ( V_36 ) > 1 ) {
V_68 = ( T_2 ) - 1 ;
break;
}
if ( V_63 -> V_80 [ 0 ] < V_69 ) {
F_39 ( V_65 , & V_20 , V_63 -> V_80 [ 0 ] ) ;
} else {
V_28 = F_40 ( V_63 , 0 , & V_20 ) ;
if ( V_28 )
break;
if ( F_41 () ||
F_42 ( V_61 , V_63 ) ) {
V_52 -> V_81 = V_68 ;
F_43 ( V_63 ) ;
F_44 ( & V_36 -> V_77 ) ;
F_45 ( & V_52 -> V_76 ) ;
F_46 () ;
goto V_75;
}
V_65 = V_63 -> V_79 [ 0 ] ;
V_69 = F_37 ( V_65 ) ;
continue;
}
if ( V_20 . V_21 < V_13 -> V_20 . V_21 ) {
V_63 -> V_80 [ 0 ] ++ ;
continue;
}
if ( V_20 . V_21 >= V_13 -> V_20 . V_21 +
V_13 -> V_20 . V_32 )
break;
if ( V_20 . type == V_74 ) {
V_67 += F_26 ( V_13 ,
V_36 , V_68 ,
V_20 . V_21 ) ;
V_68 = V_20 . V_21 + V_20 . V_32 ;
if ( V_67 > ( 1024 * 1024 * 2 ) ) {
V_67 = 0 ;
F_47 ( & V_52 -> V_82 ) ;
}
}
V_63 -> V_80 [ 0 ] ++ ;
}
V_28 = 0 ;
V_67 += F_26 ( V_13 , V_36 , V_68 ,
V_13 -> V_20 . V_21 +
V_13 -> V_20 . V_32 ) ;
V_52 -> V_81 = ( T_2 ) - 1 ;
F_11 ( & V_13 -> V_50 ) ;
V_13 -> V_52 = NULL ;
V_13 -> V_3 = V_4 ;
F_13 ( & V_13 -> V_50 ) ;
V_78:
F_48 ( V_63 ) ;
F_44 ( & V_36 -> V_77 ) ;
F_19 ( V_61 , V_13 ) ;
F_45 ( & V_52 -> V_76 ) ;
V_70:
F_47 ( & V_52 -> V_82 ) ;
F_25 ( V_52 ) ;
F_6 ( V_13 ) ;
}
static int F_49 ( struct V_1 * V_2 ,
int V_83 )
{
F_50 ( V_82 ) ;
struct V_11 * V_36 = V_2 -> V_36 ;
struct V_48 * V_52 ;
int V_28 = 0 ;
V_52 = F_51 ( sizeof( * V_52 ) , V_39 ) ;
if ( ! V_52 )
return - V_84 ;
F_52 ( & V_52 -> V_85 ) ;
F_53 ( & V_52 -> V_76 ) ;
F_54 ( & V_52 -> V_82 ) ;
V_52 -> V_13 = V_2 ;
V_52 -> V_81 = V_2 -> V_20 . V_21 ;
F_55 ( & V_52 -> V_7 , 1 ) ;
V_52 -> V_60 . V_86 = F_30 ;
F_11 ( & V_2 -> V_50 ) ;
while ( V_2 -> V_3 == V_87 ) {
struct V_48 * V_49 ;
V_49 = V_2 -> V_52 ;
F_5 ( & V_49 -> V_7 ) ;
F_56 ( & V_49 -> V_82 , & V_82 , V_88 ) ;
F_13 ( & V_2 -> V_50 ) ;
F_57 () ;
F_58 ( & V_49 -> V_82 , & V_82 ) ;
F_25 ( V_49 ) ;
F_11 ( & V_2 -> V_50 ) ;
}
if ( V_2 -> V_3 != V_89 ) {
F_13 ( & V_2 -> V_50 ) ;
F_9 ( V_52 ) ;
return 0 ;
}
F_8 ( V_2 -> V_52 ) ;
V_2 -> V_52 = V_52 ;
V_2 -> V_3 = V_87 ;
F_13 ( & V_2 -> V_50 ) ;
if ( V_36 -> V_90 & V_91 ) {
V_28 = F_59 ( V_36 , V_2 ) ;
F_11 ( & V_2 -> V_50 ) ;
if ( V_28 == 1 ) {
V_2 -> V_52 = NULL ;
V_2 -> V_3 = V_4 ;
V_2 -> V_92 = ( T_2 ) - 1 ;
} else {
if ( V_83 ) {
V_2 -> V_52 = NULL ;
V_2 -> V_3 = V_89 ;
} else {
V_2 -> V_3 = V_51 ;
}
}
F_13 ( & V_2 -> V_50 ) ;
F_47 ( & V_52 -> V_82 ) ;
if ( V_28 == 1 ) {
F_25 ( V_52 ) ;
F_19 ( V_36 -> V_61 , V_2 ) ;
return 0 ;
}
} else {
F_11 ( & V_2 -> V_50 ) ;
if ( V_83 ) {
V_2 -> V_52 = NULL ;
V_2 -> V_3 = V_89 ;
} else {
V_2 -> V_3 = V_51 ;
}
F_13 ( & V_2 -> V_50 ) ;
F_47 ( & V_52 -> V_82 ) ;
}
if ( V_83 ) {
F_25 ( V_52 ) ;
return 0 ;
}
F_60 ( & V_36 -> V_77 ) ;
F_5 ( & V_52 -> V_7 ) ;
F_61 ( & V_52 -> V_85 , & V_36 -> V_93 ) ;
F_62 ( & V_36 -> V_77 ) ;
F_4 ( V_2 ) ;
F_63 ( & V_36 -> V_94 , & V_52 -> V_60 ) ;
return V_28 ;
}
static struct V_1 *
F_64 ( struct V_11 * V_12 , T_2 V_26 )
{
struct V_1 * V_2 ;
V_2 = F_16 ( V_12 , V_26 , 0 ) ;
return V_2 ;
}
struct V_1 * F_65 (
struct V_11 * V_12 ,
T_2 V_26 )
{
struct V_1 * V_2 ;
V_2 = F_16 ( V_12 , V_26 , 1 ) ;
return V_2 ;
}
static struct V_95 * F_66 ( struct V_11 * V_12 ,
T_2 V_6 )
{
struct V_96 * V_97 = & V_12 -> V_98 ;
struct V_95 * V_99 ;
V_6 &= V_100 ;
F_67 () ;
F_68 (found, head, list) {
if ( V_99 -> V_6 & V_6 ) {
F_69 () ;
return V_99 ;
}
}
F_69 () ;
return NULL ;
}
void F_70 ( struct V_11 * V_12 )
{
struct V_96 * V_97 = & V_12 -> V_98 ;
struct V_95 * V_99 ;
F_67 () ;
F_68 (found, head, list)
V_99 -> V_101 = 0 ;
F_69 () ;
}
T_2 F_71 ( struct V_33 * V_34 ,
T_2 V_102 , T_2 V_103 , int V_104 )
{
struct V_1 * V_2 ;
T_2 V_105 ;
T_2 V_68 = F_72 ( V_103 , V_102 ) ;
T_2 V_106 = 0 ;
int V_107 = 0 ;
int V_108 = 9 ;
int V_109 = 0 ;
V_75:
while ( 1 ) {
V_2 = F_64 ( V_34 -> V_36 , V_68 ) ;
if ( ! V_2 )
break;
F_11 ( & V_2 -> V_50 ) ;
V_68 = V_2 -> V_20 . V_21 + V_2 -> V_20 . V_32 ;
V_105 = F_73 ( & V_2 -> V_110 ) ;
if ( ( V_107 || ! V_2 -> V_111 ) &&
F_3 ( V_2 , V_112 ) ) {
if ( V_105 + V_2 -> V_8 + V_2 -> V_9 <
F_74 ( V_2 -> V_20 . V_32 , V_108 ) ) {
V_106 = V_2 -> V_20 . V_21 ;
F_13 ( & V_2 -> V_50 ) ;
F_6 ( V_2 ) ;
goto V_99;
}
}
F_13 ( & V_2 -> V_50 ) ;
F_6 ( V_2 ) ;
F_46 () ;
}
if ( ! V_109 ) {
V_68 = V_102 ;
V_109 = 1 ;
goto V_75;
}
if ( ! V_107 && V_108 < 10 ) {
V_68 = V_102 ;
V_107 = 1 ;
V_108 = 10 ;
goto V_75;
}
V_99:
return V_106 ;
}
int F_75 ( struct V_33 * V_34 , T_2 V_31 , T_2 V_113 )
{
int V_28 ;
struct V_66 V_20 ;
struct V_62 * V_63 ;
V_63 = F_32 () ;
if ( ! V_63 )
return - V_84 ;
V_20 . V_21 = V_31 ;
V_20 . V_32 = V_113 ;
F_76 ( & V_20 , V_74 ) ;
V_28 = F_36 ( NULL , V_34 -> V_36 -> V_61 , & V_20 , V_63 ,
0 , 0 ) ;
F_48 ( V_63 ) ;
return V_28 ;
}
int F_77 ( struct V_114 * V_115 ,
struct V_33 * V_34 , T_2 V_26 ,
T_2 V_35 , T_2 * V_116 , T_2 * V_6 )
{
struct V_117 * V_97 ;
struct V_118 * V_119 ;
struct V_62 * V_63 ;
struct V_120 * V_121 ;
struct V_64 * V_65 ;
struct V_66 V_20 ;
T_3 V_122 ;
T_2 V_123 ;
T_2 V_124 ;
int V_28 ;
V_63 = F_32 () ;
if ( ! V_63 )
return - V_84 ;
V_20 . V_21 = V_26 ;
V_20 . type = V_74 ;
V_20 . V_32 = V_35 ;
if ( ! V_115 ) {
V_63 -> V_71 = 1 ;
V_63 -> V_72 = 1 ;
}
V_75:
V_28 = F_36 ( V_115 , V_34 -> V_36 -> V_61 ,
& V_20 , V_63 , 0 , 0 ) ;
if ( V_28 < 0 )
goto V_125;
if ( V_28 == 0 ) {
V_65 = V_63 -> V_79 [ 0 ] ;
V_122 = F_78 ( V_65 , V_63 -> V_80 [ 0 ] ) ;
if ( V_122 >= sizeof( * V_121 ) ) {
V_121 = F_79 ( V_65 , V_63 -> V_80 [ 0 ] ,
struct V_120 ) ;
V_123 = F_80 ( V_65 , V_121 ) ;
V_124 = F_81 ( V_65 , V_121 ) ;
} else {
#ifdef F_82
struct V_126 * V_127 ;
F_29 ( V_122 != sizeof( * V_127 ) ) ;
V_127 = F_79 ( V_65 , V_63 -> V_80 [ 0 ] ,
struct V_126 ) ;
V_123 = F_83 ( V_65 , V_127 ) ;
V_124 = V_128 ;
#else
F_84 () ;
#endif
}
F_29 ( V_123 == 0 ) ;
} else {
V_123 = 0 ;
V_124 = 0 ;
V_28 = 0 ;
}
if ( ! V_115 )
goto V_70;
V_119 = & V_115 -> V_129 -> V_119 ;
F_11 ( & V_119 -> V_50 ) ;
V_97 = F_85 ( V_115 , V_26 ) ;
if ( V_97 ) {
if ( ! F_86 ( & V_97 -> V_76 ) ) {
F_5 ( & V_97 -> V_130 . V_116 ) ;
F_13 ( & V_119 -> V_50 ) ;
F_43 ( V_63 ) ;
F_34 ( & V_97 -> V_76 ) ;
F_45 ( & V_97 -> V_76 ) ;
F_87 ( & V_97 -> V_130 ) ;
goto V_75;
}
if ( V_97 -> V_131 && V_97 -> V_131 -> V_132 )
V_124 |= V_97 -> V_131 -> V_133 ;
else
F_29 ( V_123 == 0 ) ;
V_123 += V_97 -> V_130 . V_134 ;
F_45 ( & V_97 -> V_76 ) ;
}
F_13 ( & V_119 -> V_50 ) ;
V_70:
F_8 ( V_123 == 0 ) ;
if ( V_116 )
* V_116 = V_123 ;
if ( V_6 )
* V_6 = V_124 ;
V_125:
F_48 ( V_63 ) ;
return V_28 ;
}
static int F_88 ( struct V_114 * V_115 ,
struct V_33 * V_34 ,
struct V_62 * V_63 ,
T_2 V_104 , T_3 V_135 )
{
struct V_120 * V_110 ;
struct V_126 * V_127 ;
struct V_136 * V_137 ;
struct V_138 * V_139 ;
struct V_64 * V_65 ;
struct V_66 V_20 ;
struct V_66 V_140 ;
T_3 V_141 = sizeof( * V_110 ) ;
T_2 V_116 ;
int V_28 ;
V_65 = V_63 -> V_79 [ 0 ] ;
F_29 ( F_78 ( V_65 , V_63 -> V_80 [ 0 ] ) != sizeof( * V_127 ) ) ;
F_39 ( V_65 , & V_20 , V_63 -> V_80 [ 0 ] ) ;
V_127 = F_79 ( V_65 , V_63 -> V_80 [ 0 ] ,
struct V_126 ) ;
V_116 = F_83 ( V_65 , V_127 ) ;
if ( V_104 == ( T_2 ) - 1 ) {
while ( 1 ) {
if ( V_63 -> V_80 [ 0 ] >= F_37 ( V_65 ) ) {
V_28 = F_42 ( V_34 , V_63 ) ;
if ( V_28 < 0 )
return V_28 ;
F_29 ( V_28 > 0 ) ;
V_65 = V_63 -> V_79 [ 0 ] ;
}
F_39 ( V_65 , & V_140 ,
V_63 -> V_80 [ 0 ] ) ;
F_29 ( V_20 . V_21 != V_140 . V_21 ) ;
if ( V_140 . type != V_142 ) {
V_63 -> V_80 [ 0 ] ++ ;
continue;
}
V_137 = F_79 ( V_65 , V_63 -> V_80 [ 0 ] ,
struct V_136 ) ;
V_104 = F_89 ( V_65 , V_137 ) ;
break;
}
}
F_43 ( V_63 ) ;
if ( V_104 < V_143 )
V_141 += sizeof( * V_139 ) ;
V_141 -= sizeof( * V_127 ) ;
V_28 = F_36 ( V_115 , V_34 , & V_20 , V_63 ,
V_141 + V_135 , 1 ) ;
if ( V_28 < 0 )
return V_28 ;
F_29 ( V_28 ) ;
F_90 ( V_115 , V_34 , V_63 , V_141 ) ;
V_65 = V_63 -> V_79 [ 0 ] ;
V_110 = F_79 ( V_65 , V_63 -> V_80 [ 0 ] , struct V_120 ) ;
F_91 ( V_65 , V_110 , V_116 ) ;
F_92 ( V_65 , V_110 , 0 ) ;
if ( V_104 < V_143 ) {
F_93 ( V_65 , V_110 ,
V_144 |
V_128 ) ;
V_139 = (struct V_138 * ) ( V_110 + 1 ) ;
F_94 ( V_65 , 0 , ( unsigned long ) V_139 , sizeof( * V_139 ) ) ;
F_95 ( V_65 , V_139 , ( int ) V_104 ) ;
} else {
F_93 ( V_65 , V_110 , V_145 ) ;
}
F_96 ( V_65 ) ;
return 0 ;
}
static T_2 F_97 ( T_2 V_146 , T_2 V_104 , T_2 V_32 )
{
T_3 V_147 = ~ ( T_3 ) 0 ;
T_3 V_148 = ~ ( T_3 ) 0 ;
T_4 V_149 ;
V_149 = F_98 ( V_146 ) ;
V_147 = F_99 ( V_147 , & V_149 , sizeof( V_149 ) ) ;
V_149 = F_98 ( V_104 ) ;
V_148 = F_99 ( V_148 , & V_149 , sizeof( V_149 ) ) ;
V_149 = F_98 ( V_32 ) ;
V_148 = F_99 ( V_148 , & V_149 , sizeof( V_149 ) ) ;
return ( ( T_2 ) V_147 << 31 ) ^ ( T_2 ) V_148 ;
}
static T_2 F_100 ( struct V_64 * V_65 ,
struct V_150 * V_151 )
{
return F_97 ( F_101 ( V_65 , V_151 ) ,
F_102 ( V_65 , V_151 ) ,
F_103 ( V_65 , V_151 ) ) ;
}
static int F_104 ( struct V_64 * V_65 ,
struct V_150 * V_151 ,
T_2 V_146 , T_2 V_104 , T_2 V_32 )
{
if ( F_101 ( V_65 , V_151 ) != V_146 ||
F_102 ( V_65 , V_151 ) != V_104 ||
F_103 ( V_65 , V_151 ) != V_32 )
return 0 ;
return 1 ;
}
static T_1 int F_105 ( struct V_114 * V_115 ,
struct V_33 * V_34 ,
struct V_62 * V_63 ,
T_2 V_26 , T_2 V_16 ,
T_2 V_146 ,
T_2 V_104 , T_2 V_32 )
{
struct V_66 V_20 ;
struct V_150 * V_151 ;
struct V_64 * V_65 ;
T_3 V_69 ;
int V_28 ;
int V_152 ;
int V_78 = - V_153 ;
V_20 . V_21 = V_26 ;
if ( V_16 ) {
V_20 . type = V_154 ;
V_20 . V_32 = V_16 ;
} else {
V_20 . type = V_155 ;
V_20 . V_32 = F_97 ( V_146 ,
V_104 , V_32 ) ;
}
V_75:
V_152 = 0 ;
V_28 = F_36 ( V_115 , V_34 , & V_20 , V_63 , - 1 , 1 ) ;
if ( V_28 < 0 ) {
V_78 = V_28 ;
goto V_156;
}
if ( V_16 ) {
if ( ! V_28 )
return 0 ;
#ifdef F_82
V_20 . type = V_142 ;
F_43 ( V_63 ) ;
V_28 = F_36 ( V_115 , V_34 , & V_20 , V_63 , - 1 , 1 ) ;
if ( V_28 < 0 ) {
V_78 = V_28 ;
goto V_156;
}
if ( ! V_28 )
return 0 ;
#endif
goto V_156;
}
V_65 = V_63 -> V_79 [ 0 ] ;
V_69 = F_37 ( V_65 ) ;
while ( 1 ) {
if ( V_63 -> V_80 [ 0 ] >= V_69 ) {
V_28 = F_42 ( V_34 , V_63 ) ;
if ( V_28 < 0 )
V_78 = V_28 ;
if ( V_28 )
goto V_156;
V_65 = V_63 -> V_79 [ 0 ] ;
V_69 = F_37 ( V_65 ) ;
V_152 = 1 ;
}
F_39 ( V_65 , & V_20 , V_63 -> V_80 [ 0 ] ) ;
if ( V_20 . V_21 != V_26 ||
V_20 . type != V_155 )
goto V_156;
V_151 = F_79 ( V_65 , V_63 -> V_80 [ 0 ] ,
struct V_150 ) ;
if ( F_104 ( V_65 , V_151 , V_146 ,
V_104 , V_32 ) ) {
if ( V_152 ) {
F_43 ( V_63 ) ;
goto V_75;
}
V_78 = 0 ;
break;
}
V_63 -> V_80 [ 0 ] ++ ;
}
V_156:
return V_78 ;
}
static T_1 int F_106 ( struct V_114 * V_115 ,
struct V_33 * V_34 ,
struct V_62 * V_63 ,
T_2 V_26 , T_2 V_16 ,
T_2 V_146 , T_2 V_104 ,
T_2 V_32 , int V_157 )
{
struct V_66 V_20 ;
struct V_64 * V_65 ;
T_3 V_55 ;
T_3 V_123 ;
int V_28 ;
V_20 . V_21 = V_26 ;
if ( V_16 ) {
V_20 . type = V_154 ;
V_20 . V_32 = V_16 ;
V_55 = sizeof( struct V_158 ) ;
} else {
V_20 . type = V_155 ;
V_20 . V_32 = F_97 ( V_146 ,
V_104 , V_32 ) ;
V_55 = sizeof( struct V_150 ) ;
}
V_28 = F_107 ( V_115 , V_34 , V_63 , & V_20 , V_55 ) ;
if ( V_28 && V_28 != - V_24 )
goto V_156;
V_65 = V_63 -> V_79 [ 0 ] ;
if ( V_16 ) {
struct V_158 * V_151 ;
V_151 = F_79 ( V_65 , V_63 -> V_80 [ 0 ] ,
struct V_158 ) ;
if ( V_28 == 0 ) {
F_108 ( V_65 , V_151 , V_157 ) ;
} else {
V_123 = F_109 ( V_65 , V_151 ) ;
V_123 += V_157 ;
F_108 ( V_65 , V_151 , V_123 ) ;
}
} else {
struct V_150 * V_151 ;
while ( V_28 == - V_24 ) {
V_151 = F_79 ( V_65 , V_63 -> V_80 [ 0 ] ,
struct V_150 ) ;
if ( F_104 ( V_65 , V_151 , V_146 ,
V_104 , V_32 ) )
break;
F_43 ( V_63 ) ;
V_20 . V_32 ++ ;
V_28 = F_107 ( V_115 , V_34 , V_63 , & V_20 ,
V_55 ) ;
if ( V_28 && V_28 != - V_24 )
goto V_156;
V_65 = V_63 -> V_79 [ 0 ] ;
}
V_151 = F_79 ( V_65 , V_63 -> V_80 [ 0 ] ,
struct V_150 ) ;
if ( V_28 == 0 ) {
F_110 ( V_65 , V_151 ,
V_146 ) ;
F_111 ( V_65 , V_151 , V_104 ) ;
F_112 ( V_65 , V_151 , V_32 ) ;
F_113 ( V_65 , V_151 , V_157 ) ;
} else {
V_123 = F_114 ( V_65 , V_151 ) ;
V_123 += V_157 ;
F_113 ( V_65 , V_151 , V_123 ) ;
}
}
F_96 ( V_65 ) ;
V_28 = 0 ;
V_156:
F_43 ( V_63 ) ;
return V_28 ;
}
static T_1 int F_115 ( struct V_114 * V_115 ,
struct V_33 * V_34 ,
struct V_62 * V_63 ,
int V_159 )
{
struct V_66 V_20 ;
struct V_150 * V_160 = NULL ;
struct V_158 * V_161 = NULL ;
struct V_64 * V_65 ;
T_3 V_123 = 0 ;
int V_28 = 0 ;
V_65 = V_63 -> V_79 [ 0 ] ;
F_39 ( V_65 , & V_20 , V_63 -> V_80 [ 0 ] ) ;
if ( V_20 . type == V_155 ) {
V_160 = F_79 ( V_65 , V_63 -> V_80 [ 0 ] ,
struct V_150 ) ;
V_123 = F_114 ( V_65 , V_160 ) ;
} else if ( V_20 . type == V_154 ) {
V_161 = F_79 ( V_65 , V_63 -> V_80 [ 0 ] ,
struct V_158 ) ;
V_123 = F_109 ( V_65 , V_161 ) ;
#ifdef F_82
} else if ( V_20 . type == V_142 ) {
struct V_136 * V_137 ;
V_137 = F_79 ( V_65 , V_63 -> V_80 [ 0 ] ,
struct V_136 ) ;
V_123 = F_116 ( V_65 , V_137 ) ;
#endif
} else {
F_84 () ;
}
F_29 ( V_123 < V_159 ) ;
V_123 -= V_159 ;
if ( V_123 == 0 ) {
V_28 = F_117 ( V_115 , V_34 , V_63 ) ;
} else {
if ( V_20 . type == V_155 )
F_113 ( V_65 , V_160 , V_123 ) ;
else if ( V_20 . type == V_154 )
F_108 ( V_65 , V_161 , V_123 ) ;
#ifdef F_82
else {
struct V_136 * V_137 ;
V_137 = F_79 ( V_65 , V_63 -> V_80 [ 0 ] ,
struct V_136 ) ;
F_118 ( V_65 , V_137 , V_123 ) ;
}
#endif
F_96 ( V_65 ) ;
}
return V_28 ;
}
static T_1 T_3 F_119 ( struct V_33 * V_34 ,
struct V_62 * V_63 ,
struct V_162 * V_163 )
{
struct V_66 V_20 ;
struct V_64 * V_65 ;
struct V_150 * V_160 ;
struct V_158 * V_161 ;
T_3 V_123 = 0 ;
V_65 = V_63 -> V_79 [ 0 ] ;
F_39 ( V_65 , & V_20 , V_63 -> V_80 [ 0 ] ) ;
if ( V_163 ) {
if ( F_120 ( V_65 , V_163 ) ==
V_155 ) {
V_160 = (struct V_150 * ) ( & V_163 -> V_32 ) ;
V_123 = F_114 ( V_65 , V_160 ) ;
} else {
V_161 = (struct V_158 * ) ( V_163 + 1 ) ;
V_123 = F_109 ( V_65 , V_161 ) ;
}
} else if ( V_20 . type == V_155 ) {
V_160 = F_79 ( V_65 , V_63 -> V_80 [ 0 ] ,
struct V_150 ) ;
V_123 = F_114 ( V_65 , V_160 ) ;
} else if ( V_20 . type == V_154 ) {
V_161 = F_79 ( V_65 , V_63 -> V_80 [ 0 ] ,
struct V_158 ) ;
V_123 = F_109 ( V_65 , V_161 ) ;
#ifdef F_82
} else if ( V_20 . type == V_142 ) {
struct V_136 * V_137 ;
V_137 = F_79 ( V_65 , V_63 -> V_80 [ 0 ] ,
struct V_136 ) ;
V_123 = F_116 ( V_65 , V_137 ) ;
#endif
} else {
F_8 ( 1 ) ;
}
return V_123 ;
}
static T_1 int F_121 ( struct V_114 * V_115 ,
struct V_33 * V_34 ,
struct V_62 * V_63 ,
T_2 V_26 , T_2 V_16 ,
T_2 V_146 )
{
struct V_66 V_20 ;
int V_28 ;
V_20 . V_21 = V_26 ;
if ( V_16 ) {
V_20 . type = V_164 ;
V_20 . V_32 = V_16 ;
} else {
V_20 . type = V_165 ;
V_20 . V_32 = V_146 ;
}
V_28 = F_36 ( V_115 , V_34 , & V_20 , V_63 , - 1 , 1 ) ;
if ( V_28 > 0 )
V_28 = - V_153 ;
#ifdef F_82
if ( V_28 == - V_153 && V_16 ) {
F_43 ( V_63 ) ;
V_20 . type = V_142 ;
V_28 = F_36 ( V_115 , V_34 , & V_20 , V_63 , - 1 , 1 ) ;
if ( V_28 > 0 )
V_28 = - V_153 ;
}
#endif
return V_28 ;
}
static T_1 int F_122 ( struct V_114 * V_115 ,
struct V_33 * V_34 ,
struct V_62 * V_63 ,
T_2 V_26 , T_2 V_16 ,
T_2 V_146 )
{
struct V_66 V_20 ;
int V_28 ;
V_20 . V_21 = V_26 ;
if ( V_16 ) {
V_20 . type = V_164 ;
V_20 . V_32 = V_16 ;
} else {
V_20 . type = V_165 ;
V_20 . V_32 = V_146 ;
}
V_28 = F_107 ( V_115 , V_34 , V_63 , & V_20 , 0 ) ;
F_43 ( V_63 ) ;
return V_28 ;
}
static inline int F_123 ( T_2 V_16 , T_2 V_104 )
{
int type ;
if ( V_104 < V_143 ) {
if ( V_16 > 0 )
type = V_164 ;
else
type = V_165 ;
} else {
if ( V_16 > 0 )
type = V_154 ;
else
type = V_155 ;
}
return type ;
}
static int F_40 ( struct V_62 * V_63 , int V_166 ,
struct V_66 * V_20 )
{
for (; V_166 < V_167 ; V_166 ++ ) {
if ( ! V_63 -> V_79 [ V_166 ] )
break;
if ( V_63 -> V_80 [ V_166 ] + 1 >=
F_37 ( V_63 -> V_79 [ V_166 ] ) )
continue;
if ( V_166 == 0 )
F_39 ( V_63 -> V_79 [ V_166 ] , V_20 ,
V_63 -> V_80 [ V_166 ] + 1 ) ;
else
F_124 ( V_63 -> V_79 [ V_166 ] , V_20 ,
V_63 -> V_80 [ V_166 ] + 1 ) ;
return 0 ;
}
return 1 ;
}
static T_5
int F_125 ( struct V_114 * V_115 ,
struct V_33 * V_34 ,
struct V_62 * V_63 ,
struct V_162 * * V_168 ,
T_2 V_26 , T_2 V_35 ,
T_2 V_16 , T_2 V_146 ,
T_2 V_104 , T_2 V_32 , int V_169 )
{
struct V_66 V_20 ;
struct V_64 * V_65 ;
struct V_120 * V_121 ;
struct V_162 * V_163 ;
T_2 V_6 ;
T_2 V_122 ;
unsigned long V_170 ;
unsigned long V_30 ;
int V_135 ;
int type ;
int V_171 ;
int V_28 ;
int V_78 = 0 ;
V_20 . V_21 = V_26 ;
V_20 . type = V_74 ;
V_20 . V_32 = V_35 ;
V_171 = F_123 ( V_16 , V_104 ) ;
if ( V_169 ) {
V_135 = F_126 ( V_171 ) ;
V_63 -> V_172 = 1 ;
} else
V_135 = - 1 ;
V_28 = F_36 ( V_115 , V_34 , & V_20 , V_63 , V_135 , 1 ) ;
if ( V_28 < 0 ) {
V_78 = V_28 ;
goto V_70;
}
if ( V_28 && ! V_169 ) {
V_78 = - V_153 ;
goto V_70;
} else if ( V_28 ) {
V_78 = - V_173 ;
F_8 ( 1 ) ;
goto V_70;
}
V_65 = V_63 -> V_79 [ 0 ] ;
V_122 = F_78 ( V_65 , V_63 -> V_80 [ 0 ] ) ;
#ifdef F_82
if ( V_122 < sizeof( * V_121 ) ) {
if ( ! V_169 ) {
V_78 = - V_153 ;
goto V_70;
}
V_28 = F_88 ( V_115 , V_34 , V_63 , V_104 ,
V_135 ) ;
if ( V_28 < 0 ) {
V_78 = V_28 ;
goto V_70;
}
V_65 = V_63 -> V_79 [ 0 ] ;
V_122 = F_78 ( V_65 , V_63 -> V_80 [ 0 ] ) ;
}
#endif
F_29 ( V_122 < sizeof( * V_121 ) ) ;
V_121 = F_79 ( V_65 , V_63 -> V_80 [ 0 ] , struct V_120 ) ;
V_6 = F_81 ( V_65 , V_121 ) ;
V_170 = ( unsigned long ) ( V_121 + 1 ) ;
V_30 = ( unsigned long ) V_121 + V_122 ;
if ( V_6 & V_144 ) {
V_170 += sizeof( struct V_138 ) ;
F_29 ( V_170 > V_30 ) ;
} else {
F_29 ( ! ( V_6 & V_145 ) ) ;
}
V_78 = - V_153 ;
while ( 1 ) {
if ( V_170 >= V_30 ) {
F_8 ( V_170 > V_30 ) ;
break;
}
V_163 = (struct V_162 * ) V_170 ;
type = F_120 ( V_65 , V_163 ) ;
if ( V_171 < type )
break;
if ( V_171 > type ) {
V_170 += F_126 ( type ) ;
continue;
}
if ( type == V_155 ) {
struct V_150 * V_174 ;
V_174 = (struct V_150 * ) ( & V_163 -> V_32 ) ;
if ( F_104 ( V_65 , V_174 , V_146 ,
V_104 , V_32 ) ) {
V_78 = 0 ;
break;
}
if ( F_100 ( V_65 , V_174 ) <
F_97 ( V_146 , V_104 , V_32 ) )
break;
} else {
T_2 V_175 ;
V_175 = F_127 ( V_65 , V_163 ) ;
if ( V_16 > 0 ) {
if ( V_16 == V_175 ) {
V_78 = 0 ;
break;
}
if ( V_175 < V_16 )
break;
} else {
if ( V_146 == V_175 ) {
V_78 = 0 ;
break;
}
if ( V_175 < V_146 )
break;
}
}
V_170 += F_126 ( type ) ;
}
if ( V_78 == - V_153 && V_169 ) {
if ( V_122 + V_135 >=
F_128 ( V_34 ) ) {
V_78 = - V_176 ;
goto V_70;
}
if ( F_40 ( V_63 , 0 , & V_20 ) == 0 &&
V_20 . V_21 == V_26 &&
V_20 . type < V_177 ) {
V_78 = - V_176 ;
goto V_70;
}
}
* V_168 = (struct V_162 * ) V_170 ;
V_70:
if ( V_169 ) {
V_63 -> V_172 = 0 ;
F_129 ( V_63 , 1 ) ;
}
return V_78 ;
}
static T_5
void F_130 ( struct V_114 * V_115 ,
struct V_33 * V_34 ,
struct V_62 * V_63 ,
struct V_162 * V_163 ,
T_2 V_16 , T_2 V_146 ,
T_2 V_104 , T_2 V_32 , int V_157 ,
struct V_178 * V_131 )
{
struct V_64 * V_65 ;
struct V_120 * V_121 ;
unsigned long V_170 ;
unsigned long V_30 ;
unsigned long V_179 ;
T_2 V_116 ;
int V_55 ;
int type ;
V_65 = V_63 -> V_79 [ 0 ] ;
V_121 = F_79 ( V_65 , V_63 -> V_80 [ 0 ] , struct V_120 ) ;
V_179 = ( unsigned long ) V_163 - ( unsigned long ) V_121 ;
type = F_123 ( V_16 , V_104 ) ;
V_55 = F_126 ( type ) ;
F_90 ( V_115 , V_34 , V_63 , V_55 ) ;
V_121 = F_79 ( V_65 , V_63 -> V_80 [ 0 ] , struct V_120 ) ;
V_116 = F_80 ( V_65 , V_121 ) ;
V_116 += V_157 ;
F_91 ( V_65 , V_121 , V_116 ) ;
if ( V_131 )
F_131 ( V_131 , V_65 , V_121 ) ;
V_170 = ( unsigned long ) V_121 + V_179 ;
V_30 = ( unsigned long ) V_121 + F_78 ( V_65 , V_63 -> V_80 [ 0 ] ) ;
if ( V_170 < V_30 - V_55 )
F_132 ( V_65 , V_170 + V_55 , V_170 ,
V_30 - V_55 - V_170 ) ;
V_163 = (struct V_162 * ) V_170 ;
F_133 ( V_65 , V_163 , type ) ;
if ( type == V_155 ) {
struct V_150 * V_174 ;
V_174 = (struct V_150 * ) ( & V_163 -> V_32 ) ;
F_110 ( V_65 , V_174 , V_146 ) ;
F_111 ( V_65 , V_174 , V_104 ) ;
F_112 ( V_65 , V_174 , V_32 ) ;
F_113 ( V_65 , V_174 , V_157 ) ;
} else if ( type == V_154 ) {
struct V_158 * V_180 ;
V_180 = (struct V_158 * ) ( V_163 + 1 ) ;
F_108 ( V_65 , V_180 , V_157 ) ;
F_134 ( V_65 , V_163 , V_16 ) ;
} else if ( type == V_164 ) {
F_134 ( V_65 , V_163 , V_16 ) ;
} else {
F_134 ( V_65 , V_163 , V_146 ) ;
}
F_96 ( V_65 ) ;
}
static int F_135 ( struct V_114 * V_115 ,
struct V_33 * V_34 ,
struct V_62 * V_63 ,
struct V_162 * * V_168 ,
T_2 V_26 , T_2 V_35 , T_2 V_16 ,
T_2 V_146 , T_2 V_104 , T_2 V_32 )
{
int V_28 ;
V_28 = F_125 ( V_115 , V_34 , V_63 , V_168 ,
V_26 , V_35 , V_16 ,
V_146 , V_104 , V_32 , 0 ) ;
if ( V_28 != - V_153 )
return V_28 ;
F_43 ( V_63 ) ;
* V_168 = NULL ;
if ( V_104 < V_143 ) {
V_28 = F_121 ( V_115 , V_34 , V_63 , V_26 , V_16 ,
V_146 ) ;
} else {
V_28 = F_105 ( V_115 , V_34 , V_63 , V_26 , V_16 ,
V_146 , V_104 , V_32 ) ;
}
return V_28 ;
}
static T_5
void F_136 ( struct V_114 * V_115 ,
struct V_33 * V_34 ,
struct V_62 * V_63 ,
struct V_162 * V_163 ,
int V_181 ,
struct V_178 * V_131 )
{
struct V_64 * V_65 ;
struct V_120 * V_121 ;
struct V_150 * V_174 = NULL ;
struct V_158 * V_180 = NULL ;
unsigned long V_170 ;
unsigned long V_30 ;
T_3 V_122 ;
int V_55 ;
int type ;
T_2 V_116 ;
V_65 = V_63 -> V_79 [ 0 ] ;
V_121 = F_79 ( V_65 , V_63 -> V_80 [ 0 ] , struct V_120 ) ;
V_116 = F_80 ( V_65 , V_121 ) ;
F_8 ( V_181 < 0 && V_116 + V_181 <= 0 ) ;
V_116 += V_181 ;
F_91 ( V_65 , V_121 , V_116 ) ;
if ( V_131 )
F_131 ( V_131 , V_65 , V_121 ) ;
type = F_120 ( V_65 , V_163 ) ;
if ( type == V_155 ) {
V_174 = (struct V_150 * ) ( & V_163 -> V_32 ) ;
V_116 = F_114 ( V_65 , V_174 ) ;
} else if ( type == V_154 ) {
V_180 = (struct V_158 * ) ( V_163 + 1 ) ;
V_116 = F_109 ( V_65 , V_180 ) ;
} else {
V_116 = 1 ;
F_29 ( V_181 != - 1 ) ;
}
F_29 ( V_181 < 0 && V_116 < - V_181 ) ;
V_116 += V_181 ;
if ( V_116 > 0 ) {
if ( type == V_155 )
F_113 ( V_65 , V_174 , V_116 ) ;
else
F_108 ( V_65 , V_180 , V_116 ) ;
} else {
V_55 = F_126 ( type ) ;
V_122 = F_78 ( V_65 , V_63 -> V_80 [ 0 ] ) ;
V_170 = ( unsigned long ) V_163 ;
V_30 = ( unsigned long ) V_121 + V_122 ;
if ( V_170 + V_55 < V_30 )
F_132 ( V_65 , V_170 , V_170 + V_55 ,
V_30 - V_170 - V_55 ) ;
V_122 -= V_55 ;
F_137 ( V_115 , V_34 , V_63 , V_122 , 1 ) ;
}
F_96 ( V_65 ) ;
}
static T_5
int F_138 ( struct V_114 * V_115 ,
struct V_33 * V_34 ,
struct V_62 * V_63 ,
T_2 V_26 , T_2 V_35 , T_2 V_16 ,
T_2 V_146 , T_2 V_104 ,
T_2 V_32 , int V_157 ,
struct V_178 * V_131 )
{
struct V_162 * V_163 ;
int V_28 ;
V_28 = F_125 ( V_115 , V_34 , V_63 , & V_163 ,
V_26 , V_35 , V_16 ,
V_146 , V_104 , V_32 , 1 ) ;
if ( V_28 == 0 ) {
F_29 ( V_104 < V_143 ) ;
F_136 ( V_115 , V_34 , V_63 , V_163 ,
V_157 , V_131 ) ;
} else if ( V_28 == - V_153 ) {
F_130 ( V_115 , V_34 , V_63 , V_163 , V_16 ,
V_146 , V_104 , V_32 ,
V_157 , V_131 ) ;
V_28 = 0 ;
}
return V_28 ;
}
static int F_139 ( struct V_114 * V_115 ,
struct V_33 * V_34 ,
struct V_62 * V_63 ,
T_2 V_26 , T_2 V_16 , T_2 V_146 ,
T_2 V_104 , T_2 V_32 , int V_157 )
{
int V_28 ;
if ( V_104 < V_143 ) {
F_29 ( V_157 != 1 ) ;
V_28 = F_122 ( V_115 , V_34 , V_63 , V_26 ,
V_16 , V_146 ) ;
} else {
V_28 = F_106 ( V_115 , V_34 , V_63 , V_26 ,
V_16 , V_146 ,
V_104 , V_32 , V_157 ) ;
}
return V_28 ;
}
static int F_140 ( struct V_114 * V_115 ,
struct V_33 * V_34 ,
struct V_62 * V_63 ,
struct V_162 * V_163 ,
int V_159 , int V_182 )
{
int V_28 = 0 ;
F_29 ( ! V_182 && V_159 != 1 ) ;
if ( V_163 ) {
F_136 ( V_115 , V_34 , V_63 , V_163 ,
- V_159 , NULL ) ;
} else if ( V_182 ) {
V_28 = F_115 ( V_115 , V_34 , V_63 , V_159 ) ;
} else {
V_28 = F_117 ( V_115 , V_34 , V_63 ) ;
}
return V_28 ;
}
static int F_141 ( struct V_183 * V_184 ,
T_2 V_31 , T_2 V_113 )
{
return F_142 ( V_184 , V_31 >> 9 , V_113 >> 9 , V_39 , 0 ) ;
}
static int F_143 ( struct V_33 * V_34 , T_2 V_26 ,
T_2 V_35 , T_2 * V_185 )
{
int V_28 ;
T_2 V_186 = 0 ;
struct V_187 * V_188 = NULL ;
V_28 = F_144 ( V_34 -> V_36 , V_189 ,
V_26 , & V_35 , & V_188 , 0 ) ;
if ( ! V_28 ) {
struct V_190 * V_191 = V_188 -> V_192 ;
int V_42 ;
for ( V_42 = 0 ; V_42 < V_188 -> V_193 ; V_42 ++ , V_191 ++ ) {
if ( ! V_191 -> V_194 -> V_195 )
continue;
V_28 = F_141 ( V_191 -> V_194 -> V_184 ,
V_191 -> V_196 ,
V_191 -> V_197 ) ;
if ( ! V_28 )
V_186 += V_191 -> V_197 ;
else if ( V_28 != - V_198 )
break;
V_28 = 0 ;
}
F_9 ( V_188 ) ;
}
if ( V_185 )
* V_185 = V_186 ;
if ( V_28 == - V_198 )
V_28 = 0 ;
return V_28 ;
}
int F_145 ( struct V_114 * V_115 ,
struct V_33 * V_34 ,
T_2 V_26 , T_2 V_35 , T_2 V_16 ,
T_2 V_146 , T_2 V_104 , T_2 V_32 , int V_199 )
{
int V_28 ;
struct V_11 * V_36 = V_34 -> V_36 ;
F_29 ( V_104 < V_143 &&
V_146 == V_200 ) ;
if ( V_104 < V_143 ) {
V_28 = F_146 ( V_36 , V_115 , V_26 ,
V_35 ,
V_16 , V_146 , ( int ) V_104 ,
V_201 , NULL , V_199 ) ;
} else {
V_28 = F_147 ( V_36 , V_115 , V_26 ,
V_35 ,
V_16 , V_146 , V_104 , V_32 ,
V_201 , NULL , V_199 ) ;
}
return V_28 ;
}
static int F_148 ( struct V_114 * V_115 ,
struct V_33 * V_34 ,
T_2 V_26 , T_2 V_35 ,
T_2 V_16 , T_2 V_146 ,
T_2 V_104 , T_2 V_32 , int V_157 ,
struct V_178 * V_131 )
{
struct V_62 * V_63 ;
struct V_64 * V_65 ;
struct V_120 * V_110 ;
T_2 V_116 ;
int V_28 ;
int V_78 = 0 ;
V_63 = F_32 () ;
if ( ! V_63 )
return - V_84 ;
V_63 -> V_73 = 1 ;
V_63 -> V_202 = 1 ;
V_28 = F_138 ( V_115 , V_34 -> V_36 -> V_61 ,
V_63 , V_26 , V_35 , V_16 ,
V_146 , V_104 , V_32 ,
V_157 , V_131 ) ;
if ( V_28 == 0 )
goto V_70;
if ( V_28 != - V_176 ) {
V_78 = V_28 ;
goto V_70;
}
V_65 = V_63 -> V_79 [ 0 ] ;
V_110 = F_79 ( V_65 , V_63 -> V_80 [ 0 ] , struct V_120 ) ;
V_116 = F_80 ( V_65 , V_110 ) ;
F_91 ( V_65 , V_110 , V_116 + V_157 ) ;
if ( V_131 )
F_131 ( V_131 , V_65 , V_110 ) ;
F_96 ( V_65 ) ;
F_43 ( V_63 ) ;
V_63 -> V_73 = 1 ;
V_63 -> V_202 = 1 ;
V_28 = F_139 ( V_115 , V_34 -> V_36 -> V_61 ,
V_63 , V_26 , V_16 , V_146 ,
V_104 , V_32 , V_157 ) ;
if ( V_28 )
F_149 ( V_115 , V_34 , V_28 ) ;
V_70:
F_48 ( V_63 ) ;
return V_78 ;
}
static int F_150 ( struct V_114 * V_115 ,
struct V_33 * V_34 ,
struct V_203 * V_130 ,
struct V_178 * V_131 ,
int V_204 )
{
int V_28 = 0 ;
struct V_205 * V_151 ;
struct V_66 V_206 ;
T_2 V_16 = 0 ;
T_2 V_207 = 0 ;
T_2 V_6 = 0 ;
V_206 . V_21 = V_130 -> V_26 ;
V_206 . V_32 = V_130 -> V_35 ;
V_206 . type = V_74 ;
V_151 = F_151 ( V_130 ) ;
if ( V_130 -> type == V_154 )
V_16 = V_151 -> V_16 ;
else
V_207 = V_151 -> V_34 ;
if ( V_130 -> V_208 == V_201 && V_204 ) {
if ( V_131 ) {
F_29 ( V_131 -> V_209 ) ;
V_6 |= V_131 -> V_133 ;
}
V_28 = F_152 ( V_115 , V_34 ,
V_16 , V_207 , V_6 ,
V_151 -> V_21 , V_151 -> V_32 ,
& V_206 , V_130 -> V_134 ) ;
} else if ( V_130 -> V_208 == V_201 ) {
V_28 = F_148 ( V_115 , V_34 , V_130 -> V_26 ,
V_130 -> V_35 , V_16 ,
V_207 , V_151 -> V_21 ,
V_151 -> V_32 , V_130 -> V_134 ,
V_131 ) ;
} else if ( V_130 -> V_208 == V_210 ) {
V_28 = F_153 ( V_115 , V_34 , V_130 -> V_26 ,
V_130 -> V_35 , V_16 ,
V_207 , V_151 -> V_21 ,
V_151 -> V_32 , V_130 -> V_134 ,
V_131 ) ;
} else {
F_84 () ;
}
return V_28 ;
}
static void F_131 ( struct V_178 * V_131 ,
struct V_64 * V_65 ,
struct V_120 * V_121 )
{
T_2 V_6 = F_81 ( V_65 , V_121 ) ;
if ( V_131 -> V_132 ) {
V_6 |= V_131 -> V_133 ;
F_93 ( V_65 , V_121 , V_6 ) ;
}
if ( V_131 -> V_209 ) {
struct V_138 * V_139 ;
F_29 ( ! ( V_6 & V_144 ) ) ;
V_139 = (struct V_138 * ) ( V_121 + 1 ) ;
F_154 ( V_65 , V_139 , & V_131 -> V_20 ) ;
}
}
static int F_155 ( struct V_114 * V_115 ,
struct V_33 * V_34 ,
struct V_203 * V_130 ,
struct V_178 * V_131 )
{
struct V_66 V_20 ;
struct V_62 * V_63 ;
struct V_120 * V_121 ;
struct V_64 * V_65 ;
T_3 V_122 ;
int V_28 ;
int V_78 = 0 ;
if ( V_115 -> V_211 )
return 0 ;
V_63 = F_32 () ;
if ( ! V_63 )
return - V_84 ;
V_20 . V_21 = V_130 -> V_26 ;
V_20 . type = V_74 ;
V_20 . V_32 = V_130 -> V_35 ;
V_63 -> V_73 = 1 ;
V_63 -> V_202 = 1 ;
V_28 = F_36 ( V_115 , V_34 -> V_36 -> V_61 , & V_20 ,
V_63 , 0 , 1 ) ;
if ( V_28 < 0 ) {
V_78 = V_28 ;
goto V_70;
}
if ( V_28 > 0 ) {
V_78 = - V_173 ;
goto V_70;
}
V_65 = V_63 -> V_79 [ 0 ] ;
V_122 = F_78 ( V_65 , V_63 -> V_80 [ 0 ] ) ;
#ifdef F_82
if ( V_122 < sizeof( * V_121 ) ) {
V_28 = F_88 ( V_115 , V_34 -> V_36 -> V_61 ,
V_63 , ( T_2 ) - 1 , 0 ) ;
if ( V_28 < 0 ) {
V_78 = V_28 ;
goto V_70;
}
V_65 = V_63 -> V_79 [ 0 ] ;
V_122 = F_78 ( V_65 , V_63 -> V_80 [ 0 ] ) ;
}
#endif
F_29 ( V_122 < sizeof( * V_121 ) ) ;
V_121 = F_79 ( V_65 , V_63 -> V_80 [ 0 ] , struct V_120 ) ;
F_131 ( V_131 , V_65 , V_121 ) ;
F_96 ( V_65 ) ;
V_70:
F_48 ( V_63 ) ;
return V_78 ;
}
static int F_156 ( struct V_114 * V_115 ,
struct V_33 * V_34 ,
struct V_203 * V_130 ,
struct V_178 * V_131 ,
int V_204 )
{
int V_28 = 0 ;
struct V_212 * V_151 ;
struct V_66 V_206 ;
T_2 V_16 = 0 ;
T_2 V_207 = 0 ;
V_206 . V_21 = V_130 -> V_26 ;
V_206 . V_32 = V_130 -> V_35 ;
V_206 . type = V_74 ;
V_151 = F_157 ( V_130 ) ;
if ( V_130 -> type == V_164 )
V_16 = V_151 -> V_16 ;
else
V_207 = V_151 -> V_34 ;
F_29 ( V_130 -> V_134 != 1 ) ;
if ( V_130 -> V_208 == V_201 && V_204 ) {
F_29 ( ! V_131 || ! V_131 -> V_132 ||
! V_131 -> V_209 ) ;
V_28 = F_158 ( V_115 , V_34 ,
V_16 , V_207 ,
V_131 -> V_133 ,
& V_131 -> V_20 ,
V_151 -> V_166 , & V_206 ) ;
} else if ( V_130 -> V_208 == V_201 ) {
V_28 = F_148 ( V_115 , V_34 , V_130 -> V_26 ,
V_130 -> V_35 , V_16 , V_207 ,
V_151 -> V_166 , 0 , 1 , V_131 ) ;
} else if ( V_130 -> V_208 == V_210 ) {
V_28 = F_153 ( V_115 , V_34 , V_130 -> V_26 ,
V_130 -> V_35 , V_16 , V_207 ,
V_151 -> V_166 , 0 , 1 , V_131 ) ;
} else {
F_84 () ;
}
return V_28 ;
}
static int F_159 ( struct V_114 * V_115 ,
struct V_33 * V_34 ,
struct V_203 * V_130 ,
struct V_178 * V_131 ,
int V_204 )
{
int V_28 = 0 ;
if ( V_115 -> V_211 )
return 0 ;
if ( F_160 ( V_130 ) ) {
struct V_117 * V_97 ;
F_29 ( V_131 ) ;
V_97 = F_161 ( V_130 ) ;
if ( V_204 ) {
F_162 ( V_34 , V_130 -> V_26 ,
V_130 -> V_35 , 1 ) ;
if ( V_97 -> V_182 ) {
V_28 = F_163 ( V_115 , V_34 ,
V_130 -> V_26 ,
V_130 -> V_35 ) ;
}
}
return V_28 ;
}
if ( V_130 -> type == V_165 ||
V_130 -> type == V_164 )
V_28 = F_156 ( V_115 , V_34 , V_130 , V_131 ,
V_204 ) ;
else if ( V_130 -> type == V_155 ||
V_130 -> type == V_154 )
V_28 = F_150 ( V_115 , V_34 , V_130 , V_131 ,
V_204 ) ;
else
F_84 () ;
return V_28 ;
}
T_1 int F_164 ( struct V_114 * V_115 ,
struct V_33 * V_34 ,
struct V_96 * V_213 )
{
struct V_118 * V_119 ;
struct V_203 * V_151 ;
struct V_117 * V_214 = NULL ;
struct V_178 * V_131 ;
struct V_11 * V_36 = V_34 -> V_36 ;
int V_28 ;
int V_7 = 0 ;
int V_215 = 0 ;
V_119 = & V_115 -> V_129 -> V_119 ;
while ( 1 ) {
if ( ! V_214 ) {
if ( F_165 ( V_213 ) )
break;
V_214 = F_166 ( V_213 -> V_216 ,
struct V_117 , V_213 ) ;
V_28 = F_167 ( V_115 , V_214 ) ;
if ( V_28 == - V_176 ) {
V_214 = NULL ;
V_7 ++ ;
continue;
}
}
F_168 ( V_115 , V_36 , V_119 ,
V_214 ) ;
V_151 = F_169 ( V_214 ) ;
if ( V_151 && V_151 -> V_217 &&
F_170 ( V_36 , V_119 , V_151 -> V_217 ) ) {
F_171 ( & V_214 -> V_213 ) ;
F_172 ( V_214 ) ;
V_214 = NULL ;
V_119 -> V_218 ++ ;
F_13 ( & V_119 -> V_50 ) ;
F_46 () ;
F_11 ( & V_119 -> V_50 ) ;
continue;
}
V_215 = V_214 -> V_215 ;
V_214 -> V_215 = 0 ;
V_131 = V_214 -> V_131 ;
V_214 -> V_131 = NULL ;
if ( ! V_151 ) {
V_151 = & V_214 -> V_130 ;
if ( V_131 && V_215 ) {
F_173 ( V_131 ) ;
V_131 = NULL ;
}
if ( V_131 ) {
F_13 ( & V_119 -> V_50 ) ;
V_28 = F_155 ( V_115 , V_34 ,
V_151 , V_131 ) ;
F_173 ( V_131 ) ;
if ( V_28 ) {
F_174 ( V_219
L_1
L_2 , V_28 ) ;
F_11 ( & V_119 -> V_50 ) ;
F_172 ( V_214 ) ;
return V_28 ;
}
goto V_216;
}
}
V_151 -> V_220 = 0 ;
F_175 ( & V_151 -> V_14 , & V_119 -> V_34 ) ;
V_119 -> V_221 -- ;
if ( ! F_160 ( V_151 ) ) {
switch ( V_151 -> V_208 ) {
case V_201 :
case V_222 :
V_214 -> V_130 . V_134 -= V_151 -> V_134 ;
break;
case V_210 :
V_214 -> V_130 . V_134 += V_151 -> V_134 ;
break;
default:
F_8 ( 1 ) ;
}
}
F_13 ( & V_119 -> V_50 ) ;
V_28 = F_159 ( V_115 , V_34 , V_151 , V_131 ,
V_215 ) ;
F_173 ( V_131 ) ;
if ( V_28 ) {
F_172 ( V_214 ) ;
F_87 ( V_151 ) ;
F_174 ( V_219
L_3 , V_28 ) ;
F_11 ( & V_119 -> V_50 ) ;
return V_28 ;
}
if ( F_160 ( V_151 ) ) {
F_171 ( & V_214 -> V_213 ) ;
F_172 ( V_214 ) ;
V_214 = NULL ;
}
F_87 ( V_151 ) ;
V_7 ++ ;
V_216:
F_46 () ;
F_11 ( & V_119 -> V_50 ) ;
}
return V_7 ;
}
static T_2 F_176 ( struct V_223 * V_34 )
{
struct V_14 * V_29 = V_34 -> V_14 ;
struct V_203 * V_224 ;
int V_225 = 1 ;
T_2 V_226 ;
T_2 V_227 = 0 , V_68 = 0 ;
V_29 = F_177 ( V_34 ) ;
if ( V_29 ) {
V_224 = F_12 ( V_29 , struct V_203 , V_14 ) ;
V_227 = V_224 -> V_26 ;
}
V_29 = F_178 ( V_34 ) ;
if ( V_29 ) {
V_224 = F_12 ( V_29 , struct V_203 , V_14 ) ;
V_68 = V_224 -> V_26 ;
}
V_29 = V_34 -> V_14 ;
while ( V_29 ) {
V_224 = F_12 ( V_29 , struct V_203 , V_14 ) ;
F_8 ( ! V_224 -> V_220 ) ;
V_226 = V_224 -> V_26 ;
if ( V_225 )
V_29 = V_29 -> V_22 ;
else
V_29 = V_29 -> V_23 ;
V_225 = 1 - V_225 ;
}
return V_226 ;
}
int F_179 ( struct V_114 * V_115 ,
struct V_11 * V_36 )
{
struct V_228 * V_228 ;
int V_28 = 0 ;
if ( F_165 ( & V_115 -> V_229 ) !=
! V_115 -> V_230 . V_217 ) {
F_174 ( V_231 L_4 ,
F_165 ( & V_115 -> V_229 ) ? L_5 : L_6 ,
V_115 -> V_230 . V_217 ) ;
F_84 () ;
}
if ( ! V_115 -> V_230 . V_217 )
return 0 ;
while ( ! F_165 ( & V_115 -> V_229 ) ) {
V_228 = F_180 ( & V_115 -> V_229 ,
struct V_228 , V_85 ) ;
F_181 ( & V_228 -> V_85 ) ;
if ( ! V_28 )
V_28 = F_182 (
V_115 , V_36 , V_228 -> V_130 ,
V_228 -> V_131 ) ;
F_9 ( V_228 ) ;
}
F_183 ( V_36 , & V_115 -> V_230 ) ;
return V_28 ;
}
static int F_184 ( struct V_118 * V_119 , int V_217 ,
int V_7 )
{
int V_232 = F_185 ( & V_119 -> V_233 ) ;
if ( V_232 < V_217 || V_232 >= V_217 + V_7 )
return 1 ;
return 0 ;
}
int F_186 ( struct V_114 * V_115 ,
struct V_33 * V_34 , unsigned long V_7 )
{
struct V_14 * V_130 ;
struct V_118 * V_119 ;
struct V_203 * V_151 ;
struct V_96 V_213 ;
int V_28 ;
T_2 V_234 ;
int V_235 = V_7 == ( unsigned long ) - 1 ;
int V_236 = 0 ;
int V_237 ;
if ( V_115 -> V_211 )
return 0 ;
if ( V_34 == V_34 -> V_36 -> V_61 )
V_34 = V_34 -> V_36 -> V_238 ;
F_179 ( V_115 , V_34 -> V_36 ) ;
V_119 = & V_115 -> V_129 -> V_119 ;
F_52 ( & V_213 ) ;
if ( V_7 == 0 ) {
V_7 = V_119 -> V_221 * 2 ;
V_236 = 1 ;
}
if ( ! V_235 && ! V_236 ) {
int V_239 ;
int V_217 = F_185 ( & V_119 -> V_233 ) ;
V_81:
V_239 = F_187 ( & V_119 -> V_240 , 0 , 1 ) ;
if ( V_239 ) {
F_50 ( V_241 ) ;
if ( V_119 -> V_221 < 16348 )
return 0 ;
F_56 ( & V_119 -> V_82 , & V_241 ,
V_88 ) ;
V_239 = F_187 ( & V_119 -> V_240 , 0 , 1 ) ;
if ( V_239 ) {
F_57 () ;
F_58 ( & V_119 -> V_82 , & V_241 ) ;
if ( ! F_184 ( V_119 , V_217 , 256 ) )
goto V_81;
else
return 0 ;
} else {
F_58 ( & V_119 -> V_82 , & V_241 ) ;
goto V_75;
}
}
} else {
F_5 ( & V_119 -> V_240 ) ;
}
V_75:
V_237 = 0 ;
F_11 ( & V_119 -> V_50 ) ;
#ifdef F_188
V_119 -> V_242 = F_176 ( & V_119 -> V_34 ) ;
#endif
while ( 1 ) {
if ( ! ( V_235 || V_236 ) &&
V_119 -> V_218 < 64 )
break;
V_234 = V_119 -> V_242 ;
V_28 = F_189 ( V_115 , & V_213 ,
V_119 -> V_242 ) ;
if ( V_28 )
break;
V_28 = F_164 ( V_115 , V_34 , & V_213 ) ;
if ( V_28 < 0 ) {
F_190 ( & V_213 ) ;
F_13 ( & V_119 -> V_50 ) ;
F_149 ( V_115 , V_34 , V_28 ) ;
F_191 ( & V_119 -> V_240 ) ;
return V_28 ;
}
F_192 ( V_28 , & V_119 -> V_233 ) ;
V_7 -= F_193 (unsigned long, ret, count) ;
if ( V_7 == 0 )
break;
if ( V_234 >= V_119 -> V_242 ) {
if ( V_237 == 0 ) {
V_237 = 1 ;
} else {
F_29 ( V_235 ) ;
break;
}
}
if ( V_28 ) {
V_237 = 0 ;
}
}
if ( V_235 ) {
if ( ! F_165 ( & V_115 -> V_243 ) ) {
F_13 ( & V_119 -> V_50 ) ;
F_194 ( V_115 , V_34 ) ;
F_11 ( & V_119 -> V_50 ) ;
}
V_130 = F_177 ( & V_119 -> V_34 ) ;
if ( ! V_130 )
goto V_70;
V_7 = ( unsigned long ) - 1 ;
while ( V_130 ) {
V_151 = F_12 ( V_130 , struct V_203 ,
V_14 ) ;
if ( F_160 ( V_151 ) ) {
struct V_117 * V_97 ;
V_97 = F_161 ( V_151 ) ;
F_5 ( & V_151 -> V_116 ) ;
F_13 ( & V_119 -> V_50 ) ;
F_34 ( & V_97 -> V_76 ) ;
F_45 ( & V_97 -> V_76 ) ;
F_87 ( V_151 ) ;
F_46 () ;
goto V_75;
}
V_130 = F_195 ( V_130 ) ;
}
F_13 ( & V_119 -> V_50 ) ;
F_196 ( 1 ) ;
goto V_75;
}
V_70:
F_191 ( & V_119 -> V_240 ) ;
F_2 () ;
if ( F_197 ( & V_119 -> V_82 ) )
F_47 ( & V_119 -> V_82 ) ;
F_13 ( & V_119 -> V_50 ) ;
F_198 ( V_115 ) ;
return 0 ;
}
int F_199 ( struct V_114 * V_115 ,
struct V_33 * V_34 ,
T_2 V_26 , T_2 V_35 , T_2 V_6 ,
int V_182 )
{
struct V_178 * V_131 ;
int V_28 ;
V_131 = F_200 () ;
if ( ! V_131 )
return - V_84 ;
V_131 -> V_133 = V_6 ;
V_131 -> V_132 = 1 ;
V_131 -> V_209 = 0 ;
V_131 -> V_182 = V_182 ? 1 : 0 ;
V_28 = F_201 ( V_34 -> V_36 , V_115 , V_26 ,
V_35 , V_131 ) ;
if ( V_28 )
F_173 ( V_131 ) ;
return V_28 ;
}
static T_1 int F_202 ( struct V_114 * V_115 ,
struct V_33 * V_34 ,
struct V_62 * V_63 ,
T_2 V_21 , T_2 V_32 , T_2 V_26 )
{
struct V_117 * V_97 ;
struct V_203 * V_151 ;
struct V_205 * V_244 ;
struct V_118 * V_119 ;
struct V_14 * V_130 ;
int V_28 = 0 ;
V_28 = - V_153 ;
V_119 = & V_115 -> V_129 -> V_119 ;
F_11 ( & V_119 -> V_50 ) ;
V_97 = F_85 ( V_115 , V_26 ) ;
if ( ! V_97 )
goto V_70;
if ( ! F_86 ( & V_97 -> V_76 ) ) {
F_5 ( & V_97 -> V_130 . V_116 ) ;
F_13 ( & V_119 -> V_50 ) ;
F_43 ( V_63 ) ;
F_34 ( & V_97 -> V_76 ) ;
F_45 ( & V_97 -> V_76 ) ;
F_87 ( & V_97 -> V_130 ) ;
return - V_176 ;
}
V_130 = F_203 ( & V_97 -> V_130 . V_14 ) ;
if ( ! V_130 )
goto V_245;
V_151 = F_12 ( V_130 , struct V_203 , V_14 ) ;
if ( V_151 -> V_26 != V_26 )
goto V_245;
V_28 = 1 ;
if ( V_151 -> type != V_155 )
goto V_245;
V_244 = F_151 ( V_151 ) ;
V_130 = F_203 ( V_130 ) ;
if ( V_130 ) {
int V_217 = V_151 -> V_217 ;
V_151 = F_12 ( V_130 , struct V_203 , V_14 ) ;
if ( V_151 -> V_26 == V_26 && V_151 -> V_217 == V_217 )
goto V_245;
}
if ( V_244 -> V_34 != V_34 -> V_246 . V_21 ||
V_244 -> V_21 != V_21 || V_244 -> V_32 != V_32 )
goto V_245;
V_28 = 0 ;
V_245:
F_45 ( & V_97 -> V_76 ) ;
V_70:
F_13 ( & V_119 -> V_50 ) ;
return V_28 ;
}
static T_1 int F_204 ( struct V_114 * V_115 ,
struct V_33 * V_34 ,
struct V_62 * V_63 ,
T_2 V_21 , T_2 V_32 , T_2 V_26 )
{
struct V_33 * V_61 = V_34 -> V_36 -> V_61 ;
struct V_64 * V_65 ;
struct V_150 * V_151 ;
struct V_162 * V_163 ;
struct V_120 * V_121 ;
struct V_66 V_20 ;
T_3 V_122 ;
int V_28 ;
V_20 . V_21 = V_26 ;
V_20 . V_32 = ( T_2 ) - 1 ;
V_20 . type = V_74 ;
V_28 = F_36 ( NULL , V_61 , & V_20 , V_63 , 0 , 0 ) ;
if ( V_28 < 0 )
goto V_70;
F_29 ( V_28 == 0 ) ;
V_28 = - V_153 ;
if ( V_63 -> V_80 [ 0 ] == 0 )
goto V_70;
V_63 -> V_80 [ 0 ] -- ;
V_65 = V_63 -> V_79 [ 0 ] ;
F_39 ( V_65 , & V_20 , V_63 -> V_80 [ 0 ] ) ;
if ( V_20 . V_21 != V_26 || V_20 . type != V_74 )
goto V_70;
V_28 = 1 ;
V_122 = F_78 ( V_65 , V_63 -> V_80 [ 0 ] ) ;
#ifdef F_82
if ( V_122 < sizeof( * V_121 ) ) {
F_8 ( V_122 != sizeof( struct V_126 ) ) ;
goto V_70;
}
#endif
V_121 = F_79 ( V_65 , V_63 -> V_80 [ 0 ] , struct V_120 ) ;
if ( V_122 != sizeof( * V_121 ) +
F_126 ( V_155 ) )
goto V_70;
if ( F_205 ( V_65 , V_121 ) <=
F_206 ( & V_34 -> V_247 ) )
goto V_70;
V_163 = (struct V_162 * ) ( V_121 + 1 ) ;
if ( F_120 ( V_65 , V_163 ) !=
V_155 )
goto V_70;
V_151 = (struct V_150 * ) ( & V_163 -> V_32 ) ;
if ( F_80 ( V_65 , V_121 ) !=
F_114 ( V_65 , V_151 ) ||
F_101 ( V_65 , V_151 ) !=
V_34 -> V_246 . V_21 ||
F_102 ( V_65 , V_151 ) != V_21 ||
F_103 ( V_65 , V_151 ) != V_32 )
goto V_70;
V_28 = 0 ;
V_70:
return V_28 ;
}
int F_207 ( struct V_114 * V_115 ,
struct V_33 * V_34 ,
T_2 V_21 , T_2 V_32 , T_2 V_26 )
{
struct V_62 * V_63 ;
int V_28 ;
int V_248 ;
V_63 = F_32 () ;
if ( ! V_63 )
return - V_153 ;
do {
V_28 = F_204 ( V_115 , V_34 , V_63 , V_21 ,
V_32 , V_26 ) ;
if ( V_28 && V_28 != - V_153 )
goto V_70;
V_248 = F_202 ( V_115 , V_34 , V_63 , V_21 ,
V_32 , V_26 ) ;
} while ( V_248 == - V_176 );
if ( V_248 && V_248 != - V_153 ) {
V_28 = V_248 ;
goto V_70;
}
if ( V_28 != - V_153 || V_248 != - V_153 )
V_28 = 0 ;
V_70:
F_48 ( V_63 ) ;
if ( V_34 -> V_246 . V_21 == V_249 )
F_8 ( V_28 > 0 ) ;
return V_28 ;
}
static int F_208 ( struct V_114 * V_115 ,
struct V_33 * V_34 ,
struct V_64 * V_250 ,
int V_251 , int V_252 , int V_199 )
{
T_2 V_26 ;
T_2 V_35 ;
T_2 V_16 ;
T_2 V_207 ;
T_3 V_69 ;
struct V_66 V_20 ;
struct V_253 * V_254 ;
int V_42 ;
int V_166 ;
int V_28 = 0 ;
int (* F_209)( struct V_114 * , struct V_33 * ,
T_2 , T_2 , T_2 , T_2 , T_2 , T_2 , int );
V_207 = F_210 ( V_250 ) ;
V_69 = F_37 ( V_250 ) ;
V_166 = F_211 ( V_250 ) ;
if ( ! V_34 -> V_255 && V_166 == 0 )
return 0 ;
if ( V_252 )
F_209 = F_145 ;
else
F_209 = V_256 ;
if ( V_251 )
V_16 = V_250 -> V_31 ;
else
V_16 = 0 ;
for ( V_42 = 0 ; V_42 < V_69 ; V_42 ++ ) {
if ( V_166 == 0 ) {
F_39 ( V_250 , & V_20 , V_42 ) ;
if ( F_212 ( & V_20 ) != V_257 )
continue;
V_254 = F_79 ( V_250 , V_42 ,
struct V_253 ) ;
if ( F_213 ( V_250 , V_254 ) ==
V_258 )
continue;
V_26 = F_214 ( V_250 , V_254 ) ;
if ( V_26 == 0 )
continue;
V_35 = F_215 ( V_250 , V_254 ) ;
V_20 . V_32 -= F_216 ( V_250 , V_254 ) ;
V_28 = F_209 ( V_115 , V_34 , V_26 , V_35 ,
V_16 , V_207 , V_20 . V_21 ,
V_20 . V_32 , V_199 ) ;
if ( V_28 )
goto V_156;
} else {
V_26 = F_217 ( V_250 , V_42 ) ;
V_35 = F_218 ( V_34 , V_166 - 1 ) ;
V_28 = F_209 ( V_115 , V_34 , V_26 , V_35 ,
V_16 , V_207 , V_166 - 1 , 0 ,
V_199 ) ;
if ( V_28 )
goto V_156;
}
}
return 0 ;
V_156:
return V_28 ;
}
int F_219 ( struct V_114 * V_115 , struct V_33 * V_34 ,
struct V_64 * V_250 , int V_251 , int V_199 )
{
return F_208 ( V_115 , V_34 , V_250 , V_251 , 1 , V_199 ) ;
}
int F_220 ( struct V_114 * V_115 , struct V_33 * V_34 ,
struct V_64 * V_250 , int V_251 , int V_199 )
{
return F_208 ( V_115 , V_34 , V_250 , V_251 , 0 , V_199 ) ;
}
static int F_221 ( struct V_114 * V_115 ,
struct V_33 * V_34 ,
struct V_62 * V_63 ,
struct V_1 * V_2 )
{
int V_28 ;
struct V_33 * V_61 = V_34 -> V_36 -> V_61 ;
unsigned long V_139 ;
struct V_64 * V_65 ;
V_28 = F_36 ( V_115 , V_61 , & V_2 -> V_20 , V_63 , 0 , 1 ) ;
if ( V_28 < 0 )
goto V_156;
F_29 ( V_28 ) ;
V_65 = V_63 -> V_79 [ 0 ] ;
V_139 = F_222 ( V_65 , V_63 -> V_80 [ 0 ] ) ;
F_223 ( V_65 , & V_2 -> V_110 , V_139 , sizeof( V_2 -> V_110 ) ) ;
F_96 ( V_65 ) ;
F_43 ( V_63 ) ;
V_156:
if ( V_28 ) {
F_149 ( V_115 , V_34 , V_28 ) ;
return V_28 ;
}
return 0 ;
}
static struct V_1 *
F_224 ( struct V_33 * V_34 ,
struct V_1 * V_2 )
{
struct V_14 * V_130 ;
F_11 ( & V_34 -> V_36 -> V_17 ) ;
V_130 = F_195 ( & V_2 -> V_19 ) ;
F_6 ( V_2 ) ;
if ( V_130 ) {
V_2 = F_12 ( V_130 , struct V_1 ,
V_19 ) ;
F_4 ( V_2 ) ;
} else
V_2 = NULL ;
F_13 ( & V_34 -> V_36 -> V_17 ) ;
return V_2 ;
}
static int F_225 ( struct V_1 * V_13 ,
struct V_114 * V_115 ,
struct V_62 * V_63 )
{
struct V_33 * V_34 = V_13 -> V_36 -> V_238 ;
struct V_259 * V_259 = NULL ;
T_2 V_260 = 0 ;
int V_261 = V_262 ;
int V_263 = 0 ;
int V_264 = 0 ;
int V_28 = 0 ;
if ( V_13 -> V_20 . V_32 < ( 100 * 1024 * 1024 ) ) {
F_11 ( & V_13 -> V_50 ) ;
V_13 -> V_265 = V_266 ;
F_13 ( & V_13 -> V_50 ) ;
return 0 ;
}
V_75:
V_259 = F_226 ( V_34 , V_13 , V_63 ) ;
if ( F_227 ( V_259 ) && F_228 ( V_259 ) != - V_153 ) {
V_28 = F_228 ( V_259 ) ;
F_43 ( V_63 ) ;
goto V_70;
}
if ( F_227 ( V_259 ) ) {
F_29 ( V_264 ) ;
V_264 ++ ;
if ( V_13 -> V_111 )
goto V_125;
V_28 = F_229 ( V_34 , V_115 , V_13 , V_63 ) ;
if ( V_28 )
goto V_125;
goto V_75;
}
if ( V_13 -> V_267 == V_115 -> V_268 &&
F_230 ( V_259 ) ) {
V_261 = V_269 ;
goto V_270;
}
F_231 ( V_259 ) -> V_271 = 0 ;
V_28 = F_232 ( V_115 , V_34 , V_259 ) ;
F_8 ( V_28 ) ;
if ( F_230 ( V_259 ) > 0 ) {
V_28 = F_233 ( V_34 , V_115 , V_63 ,
V_259 ) ;
if ( V_28 )
goto V_270;
}
F_11 ( & V_13 -> V_50 ) ;
if ( V_13 -> V_3 != V_4 ||
! F_234 ( V_34 , V_272 ) ) {
V_261 = V_266 ;
F_13 ( & V_13 -> V_50 ) ;
goto V_270;
}
F_13 ( & V_13 -> V_50 ) ;
V_263 = ( int ) F_235 ( V_13 -> V_20 . V_32 , 256 * 1024 * 1024 ) ;
if ( ! V_263 )
V_263 = 1 ;
V_263 *= 16 ;
V_263 *= V_273 ;
V_28 = F_236 ( V_259 , V_263 ) ;
if ( V_28 )
goto V_270;
V_28 = F_237 ( V_259 , V_115 , 0 , 0 , V_263 ,
V_263 , V_263 ,
& V_260 ) ;
if ( ! V_28 )
V_261 = V_269 ;
F_238 ( V_259 , V_263 ) ;
V_270:
F_239 ( V_259 ) ;
V_125:
F_43 ( V_63 ) ;
V_70:
F_11 ( & V_13 -> V_50 ) ;
if ( ! V_28 && V_261 == V_269 )
V_13 -> V_267 = V_115 -> V_268 ;
V_13 -> V_265 = V_261 ;
F_13 ( & V_13 -> V_50 ) ;
return V_28 ;
}
int F_240 ( struct V_114 * V_115 ,
struct V_33 * V_34 )
{
struct V_1 * V_2 ;
int V_78 = 0 ;
struct V_62 * V_63 ;
T_2 V_68 = 0 ;
V_63 = F_32 () ;
if ( ! V_63 )
return - V_84 ;
V_75:
while ( 1 ) {
V_2 = F_64 ( V_34 -> V_36 , V_68 ) ;
while ( V_2 ) {
if ( V_2 -> V_265 == V_274 )
break;
V_2 = F_224 ( V_34 , V_2 ) ;
}
if ( ! V_2 ) {
if ( V_68 == 0 )
break;
V_68 = 0 ;
continue;
}
V_78 = F_225 ( V_2 , V_115 , V_63 ) ;
V_68 = V_2 -> V_20 . V_21 + V_2 -> V_20 . V_32 ;
F_6 ( V_2 ) ;
}
while ( 1 ) {
if ( V_68 == 0 ) {
V_78 = F_186 ( V_115 , V_34 ,
( unsigned long ) - 1 ) ;
if ( V_78 )
goto V_70;
}
V_2 = F_64 ( V_34 -> V_36 , V_68 ) ;
while ( V_2 ) {
if ( V_2 -> V_265 == V_274 ) {
F_6 ( V_2 ) ;
goto V_75;
}
if ( V_2 -> V_275 )
break;
V_2 = F_224 ( V_34 , V_2 ) ;
}
if ( ! V_2 ) {
if ( V_68 == 0 )
break;
V_68 = 0 ;
continue;
}
if ( V_2 -> V_265 == V_269 )
V_2 -> V_265 = V_276 ;
V_2 -> V_275 = 0 ;
V_68 = V_2 -> V_20 . V_21 + V_2 -> V_20 . V_32 ;
V_78 = F_221 ( V_115 , V_34 , V_63 , V_2 ) ;
if ( V_78 )
goto V_70;
F_6 ( V_2 ) ;
}
while ( 1 ) {
if ( V_68 == 0 ) {
V_78 = F_186 ( V_115 , V_34 ,
( unsigned long ) - 1 ) ;
if ( V_78 )
goto V_70;
}
V_2 = F_64 ( V_34 -> V_36 , V_68 ) ;
while ( V_2 ) {
if ( V_2 -> V_275 ) {
F_6 ( V_2 ) ;
goto V_75;
}
if ( V_2 -> V_265 == V_276 )
break;
V_2 = F_224 ( V_34 , V_2 ) ;
}
if ( ! V_2 ) {
if ( V_68 == 0 )
break;
V_68 = 0 ;
continue;
}
V_78 = F_241 ( V_34 , V_115 , V_2 , V_63 ) ;
if ( ! V_78 && V_2 -> V_265 == V_276 )
V_2 -> V_265 = V_266 ;
V_68 = V_2 -> V_20 . V_21 + V_2 -> V_20 . V_32 ;
F_6 ( V_2 ) ;
}
V_70:
F_48 ( V_63 ) ;
return V_78 ;
}
int F_242 ( struct V_33 * V_34 , T_2 V_26 )
{
struct V_1 * V_13 ;
int V_277 = 0 ;
V_13 = F_65 ( V_34 -> V_36 , V_26 ) ;
if ( ! V_13 || V_13 -> V_111 )
V_277 = 1 ;
if ( V_13 )
F_6 ( V_13 ) ;
return V_277 ;
}
static int F_243 ( struct V_11 * V_12 , T_2 V_6 ,
T_2 V_278 , T_2 V_279 ,
struct V_95 * * V_98 )
{
struct V_95 * V_99 ;
int V_42 ;
int V_108 ;
if ( V_6 & ( V_280 | V_281 |
V_282 ) )
V_108 = 2 ;
else
V_108 = 1 ;
V_99 = F_66 ( V_12 , V_6 ) ;
if ( V_99 ) {
F_11 ( & V_99 -> V_50 ) ;
V_99 -> V_278 += V_278 ;
V_99 -> V_283 += V_278 * V_108 ;
V_99 -> V_279 += V_279 ;
V_99 -> V_284 += V_279 * V_108 ;
V_99 -> V_101 = 0 ;
F_13 ( & V_99 -> V_50 ) ;
* V_98 = V_99 ;
return 0 ;
}
V_99 = F_51 ( sizeof( * V_99 ) , V_39 ) ;
if ( ! V_99 )
return - V_84 ;
for ( V_42 = 0 ; V_42 < V_285 ; V_42 ++ )
F_52 ( & V_99 -> V_286 [ V_42 ] ) ;
F_244 ( & V_99 -> V_287 ) ;
F_245 ( & V_99 -> V_50 ) ;
V_99 -> V_6 = V_6 & V_100 ;
V_99 -> V_278 = V_278 ;
V_99 -> V_283 = V_278 * V_108 ;
V_99 -> V_279 = V_279 ;
V_99 -> V_284 = V_279 * V_108 ;
V_99 -> V_288 = 0 ;
V_99 -> V_289 = 0 ;
V_99 -> V_290 = 0 ;
V_99 -> V_291 = 0 ;
V_99 -> V_101 = 0 ;
V_99 -> V_292 = V_293 ;
V_99 -> V_294 = 0 ;
V_99 -> V_295 = 0 ;
F_54 ( & V_99 -> V_82 ) ;
* V_98 = V_99 ;
F_246 ( & V_99 -> V_85 , & V_12 -> V_98 ) ;
if ( V_6 & V_296 )
V_12 -> V_297 = V_99 ;
return 0 ;
}
static void F_247 ( struct V_11 * V_36 , T_2 V_6 )
{
T_2 V_298 = F_248 ( V_6 ) &
V_299 ;
F_249 ( & V_36 -> V_300 ) ;
if ( V_6 & V_296 )
V_36 -> V_301 |= V_298 ;
if ( V_6 & V_112 )
V_36 -> V_302 |= V_298 ;
if ( V_6 & V_303 )
V_36 -> V_304 |= V_298 ;
F_250 ( & V_36 -> V_300 ) ;
}
static T_2 F_251 ( struct V_11 * V_36 , T_2 V_6 )
{
struct V_305 * V_306 = V_36 -> V_307 ;
T_2 V_308 = 0 ;
if ( ! V_306 )
return 0 ;
if ( V_6 & V_296 &&
V_306 -> V_309 . V_6 & V_310 ) {
V_308 = V_296 | V_306 -> V_309 . V_308 ;
} else if ( V_6 & V_303 &&
V_306 -> V_311 . V_6 & V_310 ) {
V_308 = V_303 | V_306 -> V_311 . V_308 ;
} else if ( V_6 & V_112 &&
V_306 -> V_312 . V_6 & V_310 ) {
V_308 = V_112 | V_306 -> V_312 . V_308 ;
}
return V_308 ;
}
T_2 F_252 ( struct V_33 * V_34 , T_2 V_6 )
{
T_2 V_313 = V_34 -> V_36 -> V_314 -> V_315 +
V_34 -> V_36 -> V_314 -> V_316 ;
T_2 V_308 ;
T_2 V_317 ;
F_11 ( & V_34 -> V_36 -> V_318 ) ;
V_308 = F_251 ( V_34 -> V_36 , V_6 ) ;
if ( V_308 ) {
if ( ( V_6 & V_308 ) & V_299 ) {
F_13 ( & V_34 -> V_36 -> V_318 ) ;
return F_253 ( V_308 ) ;
}
}
F_13 ( & V_34 -> V_36 -> V_318 ) ;
if ( V_313 == 1 )
V_6 &= ~ ( V_281 | V_319 |
V_320 ) ;
if ( V_313 < 3 )
V_6 &= ~ V_321 ;
if ( V_313 < 4 )
V_6 &= ~ V_282 ;
V_317 = V_6 & ( V_280 | V_319 |
V_281 | V_320 |
V_321 | V_282 ) ;
V_6 &= ~ V_317 ;
if ( V_317 & V_321 )
V_317 = V_321 ;
else if ( V_317 & V_320 )
V_317 = V_320 ;
else if ( V_317 & V_282 )
V_317 = V_282 ;
else if ( V_317 & V_281 )
V_317 = V_281 ;
else if ( V_317 & V_319 )
V_317 = V_319 ;
return F_253 ( V_6 | V_317 ) ;
}
static T_2 F_254 ( struct V_33 * V_34 , T_2 V_6 )
{
unsigned V_217 ;
do {
V_217 = F_255 ( & V_34 -> V_36 -> V_300 ) ;
if ( V_6 & V_296 )
V_6 |= V_34 -> V_36 -> V_301 ;
else if ( V_6 & V_303 )
V_6 |= V_34 -> V_36 -> V_304 ;
else if ( V_6 & V_112 )
V_6 |= V_34 -> V_36 -> V_302 ;
} while ( F_256 ( & V_34 -> V_36 -> V_300 , V_217 ) );
return F_252 ( V_34 , V_6 ) ;
}
T_2 F_257 ( struct V_33 * V_34 , int V_309 )
{
T_2 V_6 ;
T_2 V_28 ;
if ( V_309 )
V_6 = V_296 ;
else if ( V_34 == V_34 -> V_36 -> V_322 )
V_6 = V_303 ;
else
V_6 = V_112 ;
V_28 = F_254 ( V_34 , V_6 ) ;
return V_28 ;
}
int F_236 ( struct V_259 * V_259 , T_2 V_323 )
{
struct V_95 * V_297 ;
struct V_33 * V_34 = F_231 ( V_259 ) -> V_34 ;
struct V_11 * V_36 = V_34 -> V_36 ;
T_2 V_105 ;
int V_28 = 0 , V_324 = 0 , V_325 = 1 ;
V_323 = F_258 ( V_323 , V_34 -> V_326 ) ;
if ( V_34 == V_34 -> V_36 -> V_238 ||
F_231 ( V_259 ) -> V_327 . V_21 == V_328 ) {
V_325 = 0 ;
V_324 = 1 ;
}
V_297 = V_36 -> V_297 ;
if ( ! V_297 )
goto V_329;
V_75:
F_11 ( & V_297 -> V_50 ) ;
V_105 = V_297 -> V_279 + V_297 -> V_289 +
V_297 -> V_288 + V_297 -> V_290 +
V_297 -> V_291 ;
if ( V_105 + V_323 > V_297 -> V_278 ) {
struct V_114 * V_115 ;
if ( ! V_297 -> V_101 && V_325 ) {
T_2 V_330 ;
V_297 -> V_292 = V_331 ;
F_13 ( & V_297 -> V_50 ) ;
V_329:
V_330 = F_257 ( V_34 , 1 ) ;
V_115 = F_259 ( V_34 ) ;
if ( F_227 ( V_115 ) )
return F_228 ( V_115 ) ;
V_28 = F_260 ( V_115 , V_34 -> V_36 -> V_61 ,
V_330 ,
V_293 ) ;
F_261 ( V_115 , V_34 ) ;
if ( V_28 < 0 ) {
if ( V_28 != - V_332 )
return V_28 ;
else
goto V_333;
}
if ( ! V_297 )
V_297 = V_36 -> V_297 ;
goto V_75;
}
if ( V_297 -> V_288 < V_323 )
V_324 = 1 ;
F_13 ( & V_297 -> V_50 ) ;
V_333:
if ( ! V_324 &&
! F_185 ( & V_34 -> V_36 -> V_334 ) ) {
V_324 = 1 ;
V_115 = F_259 ( V_34 ) ;
if ( F_227 ( V_115 ) )
return F_228 ( V_115 ) ;
V_28 = F_262 ( V_115 , V_34 ) ;
if ( V_28 )
return V_28 ;
goto V_75;
}
return - V_332 ;
}
V_297 -> V_291 += V_323 ;
F_263 ( V_34 -> V_36 , L_7 ,
V_297 -> V_6 , V_323 , 1 ) ;
F_13 ( & V_297 -> V_50 ) ;
return 0 ;
}
void F_238 ( struct V_259 * V_259 , T_2 V_323 )
{
struct V_33 * V_34 = F_231 ( V_259 ) -> V_34 ;
struct V_95 * V_297 ;
V_323 = F_258 ( V_323 , V_34 -> V_326 ) ;
V_297 = V_34 -> V_36 -> V_297 ;
F_11 ( & V_297 -> V_50 ) ;
V_297 -> V_291 -= V_323 ;
F_263 ( V_34 -> V_36 , L_7 ,
V_297 -> V_6 , V_323 , 0 ) ;
F_13 ( & V_297 -> V_50 ) ;
}
static void F_264 ( struct V_11 * V_12 )
{
struct V_96 * V_97 = & V_12 -> V_98 ;
struct V_95 * V_99 ;
F_67 () ;
F_68 (found, head, list) {
if ( V_99 -> V_6 & V_112 )
V_99 -> V_292 = V_331 ;
}
F_69 () ;
}
static int F_265 ( struct V_33 * V_34 ,
struct V_95 * V_335 , int V_336 )
{
struct V_337 * V_338 = & V_34 -> V_36 -> V_339 ;
T_2 V_35 = V_335 -> V_278 - V_335 -> V_290 ;
T_2 V_340 = V_335 -> V_279 + V_335 -> V_289 ;
T_2 V_341 ;
if ( V_336 == V_331 )
return 1 ;
if ( V_335 -> V_6 & V_112 )
V_340 += V_338 -> V_55 ;
if ( V_336 == V_342 ) {
V_341 = F_266 ( V_34 -> V_36 -> V_343 ) ;
V_341 = F_33 ( T_2 , 64 * 1024 * 1024 ,
F_267 ( V_341 , 1 ) ) ;
if ( V_35 - V_340 < V_341 )
return 1 ;
}
if ( V_340 + 2 * 1024 * 1024 < F_74 ( V_35 , 8 ) )
return 0 ;
return 1 ;
}
static T_2 F_268 ( struct V_33 * V_34 , T_2 type )
{
T_2 V_344 ;
if ( type & ( V_282 |
V_319 |
V_320 |
V_321 ) )
V_344 = V_34 -> V_36 -> V_314 -> V_315 ;
else if ( type & V_281 )
V_344 = 2 ;
else
V_344 = 1 ;
return F_269 ( V_34 , V_344 + 1 ) ;
}
static void F_270 ( struct V_114 * V_115 ,
struct V_33 * V_34 , T_2 type )
{
struct V_95 * V_12 ;
T_2 V_345 ;
T_2 V_341 ;
V_12 = F_66 ( V_34 -> V_36 , V_303 ) ;
F_11 ( & V_12 -> V_50 ) ;
V_345 = V_12 -> V_278 - V_12 -> V_279 - V_12 -> V_288 -
V_12 -> V_289 - V_12 -> V_290 ;
F_13 ( & V_12 -> V_50 ) ;
V_341 = F_268 ( V_34 , type ) ;
if ( V_345 < V_341 && F_234 ( V_34 , V_346 ) ) {
F_174 ( V_347 L_8 ,
V_345 , V_341 , type ) ;
F_271 ( V_12 , 0 , 0 ) ;
}
if ( V_345 < V_341 ) {
T_2 V_6 ;
V_6 = F_257 ( V_34 -> V_36 -> V_322 , 0 ) ;
F_272 ( V_115 , V_34 , V_6 ) ;
}
}
static int F_260 ( struct V_114 * V_115 ,
struct V_33 * V_61 , T_2 V_6 , int V_336 )
{
struct V_95 * V_98 ;
struct V_11 * V_36 = V_61 -> V_36 ;
int V_348 = 0 ;
int V_28 = 0 ;
if ( V_115 -> V_349 )
return - V_332 ;
V_98 = F_66 ( V_61 -> V_36 , V_6 ) ;
if ( ! V_98 ) {
V_28 = F_243 ( V_61 -> V_36 , V_6 ,
0 , 0 , & V_98 ) ;
F_29 ( V_28 ) ;
}
F_29 ( ! V_98 ) ;
V_75:
F_11 ( & V_98 -> V_50 ) ;
if ( V_336 < V_98 -> V_292 )
V_336 = V_98 -> V_292 ;
if ( V_98 -> V_101 ) {
F_13 ( & V_98 -> V_50 ) ;
return 0 ;
}
if ( ! F_265 ( V_61 , V_98 , V_336 ) ) {
F_13 ( & V_98 -> V_50 ) ;
return 0 ;
} else if ( V_98 -> V_294 ) {
V_348 = 1 ;
} else {
V_98 -> V_294 = 1 ;
}
F_13 ( & V_98 -> V_50 ) ;
F_34 ( & V_36 -> V_350 ) ;
if ( V_348 ) {
F_45 ( & V_36 -> V_350 ) ;
V_348 = 0 ;
goto V_75;
}
V_115 -> V_349 = true ;
if ( F_273 ( V_98 ) )
V_6 |= ( V_296 | V_112 ) ;
if ( V_6 & V_296 && V_36 -> V_351 ) {
V_36 -> V_352 ++ ;
if ( ! ( V_36 -> V_352 %
V_36 -> V_351 ) )
F_264 ( V_36 ) ;
}
F_270 ( V_115 , V_61 , V_6 ) ;
V_28 = F_272 ( V_115 , V_61 , V_6 ) ;
V_115 -> V_349 = false ;
F_11 ( & V_98 -> V_50 ) ;
if ( V_28 < 0 && V_28 != - V_332 )
goto V_70;
if ( V_28 )
V_98 -> V_101 = 1 ;
else
V_28 = 1 ;
V_98 -> V_292 = V_293 ;
V_70:
V_98 -> V_294 = 0 ;
F_13 ( & V_98 -> V_50 ) ;
F_45 ( & V_36 -> V_350 ) ;
return V_28 ;
}
static int F_274 ( struct V_33 * V_34 ,
struct V_95 * V_98 , T_2 V_323 ,
enum V_353 V_295 )
{
struct V_337 * V_338 = & V_34 -> V_36 -> V_339 ;
T_2 V_354 = F_257 ( V_34 , 0 ) ;
T_2 V_355 = 0 ;
T_2 V_356 ;
T_2 V_105 ;
T_2 V_357 ;
V_105 = V_98 -> V_279 + V_98 -> V_289 +
V_98 -> V_288 + V_98 -> V_290 ;
F_11 ( & V_338 -> V_50 ) ;
V_355 = V_338 -> V_55 ;
F_13 ( & V_338 -> V_50 ) ;
V_355 <<= 1 ;
if ( V_105 + V_355 >= V_98 -> V_278 )
return 0 ;
V_105 += V_98 -> V_291 ;
F_11 ( & V_34 -> V_36 -> V_358 ) ;
V_356 = V_34 -> V_36 -> V_359 ;
F_13 ( & V_34 -> V_36 -> V_358 ) ;
if ( V_354 & ( V_280 |
V_281 |
V_282 ) )
V_356 >>= 1 ;
V_357 = V_98 -> V_278 ;
if ( V_295 == V_360 )
V_357 >>= 3 ;
else
V_357 >>= 1 ;
V_357 = F_275 ( V_356 , V_357 ) ;
if ( V_105 + V_323 < V_98 -> V_278 + V_357 )
return 1 ;
return 0 ;
}
void F_276 ( struct V_33 * V_34 ,
unsigned long V_361 )
{
struct V_362 * V_363 = V_34 -> V_36 -> V_363 ;
int V_364 ;
V_364 = F_277 ( V_363 , V_361 ,
V_365 ) ;
if ( ! V_364 ) {
F_278 ( V_34 , 0 ) ;
F_279 ( V_34 , 0 ) ;
}
}
static void F_280 ( struct V_33 * V_34 , T_2 V_366 , T_2 V_367 ,
bool V_368 )
{
struct V_337 * V_369 ;
struct V_95 * V_98 ;
struct V_114 * V_115 ;
T_2 V_370 ;
T_2 V_371 ;
long V_372 ;
unsigned long V_361 = ( 2 * 1024 * 1024 ) >> V_373 ;
int V_237 = 0 ;
enum V_353 V_295 ;
V_115 = (struct V_114 * ) V_374 -> V_375 ;
V_369 = & V_34 -> V_36 -> V_376 ;
V_98 = V_369 -> V_98 ;
F_2 () ;
V_370 = F_281 (
& V_34 -> V_36 -> V_370 ) ;
if ( V_370 == 0 ) {
if ( V_115 )
return;
F_279 ( V_34 , 0 ) ;
return;
}
while ( V_370 && V_237 < 3 ) {
V_371 = F_275 ( V_370 , V_366 ) ;
V_361 = V_371 >> V_373 ;
F_276 ( V_34 , V_361 ) ;
F_282 ( V_34 -> V_36 -> V_377 ,
! F_185 ( & V_34 -> V_36 -> V_378 ) ) ;
if ( ! V_115 )
V_295 = V_360 ;
else
V_295 = V_379 ;
F_11 ( & V_98 -> V_50 ) ;
if ( F_274 ( V_34 , V_98 , V_367 , V_295 ) ) {
F_13 ( & V_98 -> V_50 ) ;
break;
}
F_13 ( & V_98 -> V_50 ) ;
V_237 ++ ;
if ( V_368 && ! V_115 ) {
F_279 ( V_34 , 0 ) ;
} else {
V_372 = F_283 ( 1 ) ;
if ( V_372 )
break;
}
F_2 () ;
V_370 = F_281 (
& V_34 -> V_36 -> V_370 ) ;
}
}
static int F_284 ( struct V_33 * V_34 ,
struct V_95 * V_98 ,
T_2 V_323 , int V_336 )
{
struct V_337 * V_380 = & V_34 -> V_36 -> V_381 ;
struct V_114 * V_115 ;
V_115 = (struct V_114 * ) V_374 -> V_375 ;
if ( V_115 )
return - V_176 ;
if ( V_336 )
goto V_382;
F_11 ( & V_98 -> V_50 ) ;
if ( V_98 -> V_288 >= V_323 ) {
F_13 ( & V_98 -> V_50 ) ;
goto V_382;
}
F_13 ( & V_98 -> V_50 ) ;
if ( V_98 != V_380 -> V_98 )
return - V_332 ;
F_11 ( & V_98 -> V_50 ) ;
F_11 ( & V_380 -> V_50 ) ;
if ( V_98 -> V_288 + V_380 -> V_55 < V_323 ) {
F_13 ( & V_380 -> V_50 ) ;
F_13 ( & V_98 -> V_50 ) ;
return - V_332 ;
}
F_13 ( & V_380 -> V_50 ) ;
F_13 ( & V_98 -> V_50 ) ;
V_382:
V_115 = F_259 ( V_34 ) ;
if ( F_227 ( V_115 ) )
return - V_332 ;
return F_262 ( V_115 , V_34 ) ;
}
static int F_285 ( struct V_33 * V_34 ,
struct V_95 * V_98 , T_2 V_35 ,
T_2 V_383 , int V_384 )
{
struct V_114 * V_115 ;
int V_43 ;
int V_28 = 0 ;
switch ( V_384 ) {
case V_385 :
case V_386 :
if ( V_384 == V_385 ) {
T_2 V_323 = F_269 ( V_34 , 1 ) ;
V_43 = ( int ) F_235 ( V_35 , V_323 ) ;
if ( ! V_43 )
V_43 = 1 ;
V_43 *= 2 ;
} else {
V_43 = - 1 ;
}
V_115 = F_259 ( V_34 ) ;
if ( F_227 ( V_115 ) ) {
V_28 = F_228 ( V_115 ) ;
break;
}
V_28 = F_286 ( V_115 , V_34 , V_43 ) ;
F_261 ( V_115 , V_34 ) ;
break;
case V_387 :
case V_388 :
F_280 ( V_34 , V_35 , V_383 ,
V_384 == V_388 ) ;
break;
case V_389 :
V_115 = F_259 ( V_34 ) ;
if ( F_227 ( V_115 ) ) {
V_28 = F_228 ( V_115 ) ;
break;
}
V_28 = F_260 ( V_115 , V_34 -> V_36 -> V_61 ,
F_257 ( V_34 , 0 ) ,
V_293 ) ;
F_261 ( V_115 , V_34 ) ;
if ( V_28 == - V_332 )
V_28 = 0 ;
break;
case V_390 :
V_28 = F_284 ( V_34 , V_98 , V_383 , 0 ) ;
break;
default:
V_28 = - V_332 ;
break;
}
return V_28 ;
}
static int F_287 ( struct V_33 * V_34 ,
struct V_337 * V_369 ,
T_2 V_383 ,
enum V_353 V_295 )
{
struct V_95 * V_98 = V_369 -> V_98 ;
T_2 V_105 ;
T_2 V_35 = V_383 ;
int V_391 = V_385 ;
int V_28 = 0 ;
bool V_392 = false ;
V_75:
V_28 = 0 ;
F_11 ( & V_98 -> V_50 ) ;
while ( V_295 == V_360 && ! V_392 &&
V_98 -> V_295 ) {
F_13 ( & V_98 -> V_50 ) ;
if ( V_374 -> V_375 )
return - V_176 ;
V_28 = F_288 ( V_98 -> V_82 , ! V_98 -> V_295 ) ;
if ( V_28 )
return - V_393 ;
F_11 ( & V_98 -> V_50 ) ;
}
V_28 = - V_332 ;
V_105 = V_98 -> V_279 + V_98 -> V_289 +
V_98 -> V_288 + V_98 -> V_290 +
V_98 -> V_291 ;
if ( V_105 <= V_98 -> V_278 ) {
if ( V_105 + V_383 <= V_98 -> V_278 ) {
V_98 -> V_291 += V_383 ;
F_263 ( V_34 -> V_36 ,
L_7 , V_98 -> V_6 , V_383 , 1 ) ;
V_28 = 0 ;
} else {
V_35 = V_383 ;
}
} else {
V_35 = V_105 - V_98 -> V_278 +
( V_383 * 2 ) ;
}
if ( V_28 && F_274 ( V_34 , V_98 , V_383 , V_295 ) ) {
V_98 -> V_291 += V_383 ;
F_263 ( V_34 -> V_36 , L_7 ,
V_98 -> V_6 , V_383 ,
1 ) ;
V_28 = 0 ;
}
if ( V_28 && V_295 != V_379 ) {
V_392 = true ;
V_98 -> V_295 = 1 ;
}
F_13 ( & V_98 -> V_50 ) ;
if ( ! V_28 || V_295 == V_379 )
goto V_70;
V_28 = F_285 ( V_34 , V_98 , V_35 , V_383 ,
V_391 ) ;
V_391 ++ ;
if ( V_295 == V_394 &&
( V_391 == V_387 ||
V_391 == V_388 ) )
V_391 = V_389 ;
if ( ! V_28 )
goto V_75;
else if ( V_295 == V_394 &&
V_391 < V_390 )
goto V_75;
else if ( V_295 == V_360 &&
V_391 <= V_390 )
goto V_75;
V_70:
if ( V_28 == - V_332 &&
F_289 ( V_34 -> V_395 == V_396 ) ) {
struct V_337 * V_338 =
& V_34 -> V_36 -> V_339 ;
if ( V_369 != V_338 &&
! F_290 ( V_338 , V_383 ) )
V_28 = 0 ;
}
if ( V_392 ) {
F_11 ( & V_98 -> V_50 ) ;
V_98 -> V_295 = 0 ;
F_291 ( & V_98 -> V_82 ) ;
F_13 ( & V_98 -> V_50 ) ;
}
return V_28 ;
}
static struct V_337 * F_292 (
const struct V_114 * V_115 ,
const struct V_33 * V_34 )
{
struct V_337 * V_369 = NULL ;
if ( V_34 -> V_255 )
V_369 = V_115 -> V_369 ;
if ( V_34 == V_34 -> V_36 -> V_397 && V_115 -> V_398 )
V_369 = V_115 -> V_369 ;
if ( ! V_369 )
V_369 = V_34 -> V_369 ;
if ( ! V_369 )
V_369 = & V_34 -> V_36 -> V_399 ;
return V_369 ;
}
static int F_290 ( struct V_337 * V_369 ,
T_2 V_35 )
{
int V_28 = - V_332 ;
F_11 ( & V_369 -> V_50 ) ;
if ( V_369 -> V_9 >= V_35 ) {
V_369 -> V_9 -= V_35 ;
if ( V_369 -> V_9 < V_369 -> V_55 )
V_369 -> V_101 = 0 ;
V_28 = 0 ;
}
F_13 ( & V_369 -> V_50 ) ;
return V_28 ;
}
static void F_293 ( struct V_337 * V_369 ,
T_2 V_35 , int V_400 )
{
F_11 ( & V_369 -> V_50 ) ;
V_369 -> V_9 += V_35 ;
if ( V_400 )
V_369 -> V_55 += V_35 ;
else if ( V_369 -> V_9 >= V_369 -> V_55 )
V_369 -> V_101 = 1 ;
F_13 ( & V_369 -> V_50 ) ;
}
static void F_294 ( struct V_11 * V_36 ,
struct V_337 * V_369 ,
struct V_337 * V_401 , T_2 V_35 )
{
struct V_95 * V_98 = V_369 -> V_98 ;
F_11 ( & V_369 -> V_50 ) ;
if ( V_35 == ( T_2 ) - 1 )
V_35 = V_369 -> V_55 ;
V_369 -> V_55 -= V_35 ;
if ( V_369 -> V_9 >= V_369 -> V_55 ) {
V_35 = V_369 -> V_9 - V_369 -> V_55 ;
V_369 -> V_9 = V_369 -> V_55 ;
V_369 -> V_101 = 1 ;
} else {
V_35 = 0 ;
}
F_13 ( & V_369 -> V_50 ) ;
if ( V_35 > 0 ) {
if ( V_401 ) {
F_11 ( & V_401 -> V_50 ) ;
if ( ! V_401 -> V_101 ) {
T_2 V_402 ;
V_402 = V_401 -> V_55 - V_401 -> V_9 ;
V_402 = F_275 ( V_35 , V_402 ) ;
V_401 -> V_9 += V_402 ;
if ( V_401 -> V_9 >= V_401 -> V_55 )
V_401 -> V_101 = 1 ;
V_35 -= V_402 ;
}
F_13 ( & V_401 -> V_50 ) ;
}
if ( V_35 ) {
F_11 ( & V_98 -> V_50 ) ;
V_98 -> V_291 -= V_35 ;
F_263 ( V_36 , L_7 ,
V_98 -> V_6 , V_35 , 0 ) ;
V_98 -> V_403 ++ ;
F_13 ( & V_98 -> V_50 ) ;
}
}
}
static int F_295 ( struct V_337 * V_404 ,
struct V_337 * V_405 , T_2 V_35 )
{
int V_28 ;
V_28 = F_290 ( V_404 , V_35 ) ;
if ( V_28 )
return V_28 ;
F_293 ( V_405 , V_35 , 1 ) ;
return 0 ;
}
void F_296 ( struct V_337 * V_406 , unsigned short type )
{
memset ( V_406 , 0 , sizeof( * V_406 ) ) ;
F_245 ( & V_406 -> V_50 ) ;
V_406 -> type = type ;
}
struct V_337 * F_297 ( struct V_33 * V_34 ,
unsigned short type )
{
struct V_337 * V_369 ;
struct V_11 * V_36 = V_34 -> V_36 ;
V_369 = F_298 ( sizeof( * V_369 ) , V_39 ) ;
if ( ! V_369 )
return NULL ;
F_296 ( V_369 , type ) ;
V_369 -> V_98 = F_66 ( V_36 ,
V_112 ) ;
return V_369 ;
}
void F_299 ( struct V_33 * V_34 ,
struct V_337 * V_406 )
{
if ( ! V_406 )
return;
F_300 ( V_34 , V_406 , ( T_2 ) - 1 ) ;
F_9 ( V_406 ) ;
}
int F_301 ( struct V_33 * V_34 ,
struct V_337 * V_369 , T_2 V_35 ,
enum V_353 V_295 )
{
int V_28 ;
if ( V_35 == 0 )
return 0 ;
V_28 = F_287 ( V_34 , V_369 , V_35 , V_295 ) ;
if ( ! V_28 ) {
F_293 ( V_369 , V_35 , 1 ) ;
return 0 ;
}
return V_28 ;
}
int F_302 ( struct V_33 * V_34 ,
struct V_337 * V_369 , int V_407 )
{
T_2 V_35 = 0 ;
int V_28 = - V_332 ;
if ( ! V_369 )
return 0 ;
F_11 ( & V_369 -> V_50 ) ;
V_35 = F_74 ( V_369 -> V_55 , V_407 ) ;
if ( V_369 -> V_9 >= V_35 )
V_28 = 0 ;
F_13 ( & V_369 -> V_50 ) ;
return V_28 ;
}
int F_303 ( struct V_33 * V_34 ,
struct V_337 * V_369 , T_2 V_408 ,
enum V_353 V_295 )
{
T_2 V_35 = 0 ;
int V_28 = - V_332 ;
if ( ! V_369 )
return 0 ;
F_11 ( & V_369 -> V_50 ) ;
V_35 = V_408 ;
if ( V_369 -> V_9 >= V_35 )
V_28 = 0 ;
else
V_35 -= V_369 -> V_9 ;
F_13 ( & V_369 -> V_50 ) ;
if ( ! V_28 )
return 0 ;
V_28 = F_287 ( V_34 , V_369 , V_35 , V_295 ) ;
if ( ! V_28 ) {
F_293 ( V_369 , V_35 , 0 ) ;
return 0 ;
}
return V_28 ;
}
int F_304 ( struct V_337 * V_409 ,
struct V_337 * V_410 ,
T_2 V_35 )
{
return F_295 ( V_409 , V_410 , V_35 ) ;
}
void F_300 ( struct V_33 * V_34 ,
struct V_337 * V_369 ,
T_2 V_35 )
{
struct V_337 * V_338 = & V_34 -> V_36 -> V_339 ;
if ( V_338 -> V_101 || V_338 == V_369 ||
V_369 -> V_98 != V_338 -> V_98 )
V_338 = NULL ;
F_294 ( V_34 -> V_36 , V_369 , V_338 ,
V_35 ) ;
}
static T_2 F_305 ( struct V_11 * V_36 )
{
struct V_95 * V_335 ;
T_2 V_35 ;
T_2 V_411 ;
T_2 V_412 ;
int V_413 = F_306 ( V_36 -> V_343 ) ;
V_335 = F_66 ( V_36 , V_296 ) ;
F_11 ( & V_335 -> V_50 ) ;
V_412 = V_335 -> V_279 ;
F_13 ( & V_335 -> V_50 ) ;
V_335 = F_66 ( V_36 , V_112 ) ;
F_11 ( & V_335 -> V_50 ) ;
if ( V_335 -> V_6 & V_296 )
V_412 = 0 ;
V_411 = V_335 -> V_279 ;
F_13 ( & V_335 -> V_50 ) ;
V_35 = ( V_412 >> V_36 -> V_363 -> V_414 ) *
V_413 * 2 ;
V_35 += F_235 ( V_412 + V_411 , 50 ) ;
if ( V_35 * 3 > V_411 )
V_35 = F_235 ( V_411 , 3 ) ;
return F_258 ( V_35 , V_36 -> V_61 -> V_415 << 10 ) ;
}
static void F_307 ( struct V_11 * V_36 )
{
struct V_337 * V_369 = & V_36 -> V_339 ;
struct V_95 * V_335 = V_369 -> V_98 ;
T_2 V_35 ;
V_35 = F_305 ( V_36 ) ;
F_11 ( & V_335 -> V_50 ) ;
F_11 ( & V_369 -> V_50 ) ;
V_369 -> V_55 = F_193 ( T_2 , V_35 , 512 * 1024 * 1024 ) ;
V_35 = V_335 -> V_279 + V_335 -> V_288 +
V_335 -> V_289 + V_335 -> V_290 +
V_335 -> V_291 ;
if ( V_335 -> V_278 > V_35 ) {
V_35 = V_335 -> V_278 - V_35 ;
V_369 -> V_9 += V_35 ;
V_335 -> V_291 += V_35 ;
F_263 ( V_36 , L_7 ,
V_335 -> V_6 , V_35 , 1 ) ;
}
if ( V_369 -> V_9 >= V_369 -> V_55 ) {
V_35 = V_369 -> V_9 - V_369 -> V_55 ;
V_335 -> V_291 -= V_35 ;
F_263 ( V_36 , L_7 ,
V_335 -> V_6 , V_35 , 0 ) ;
V_335 -> V_403 ++ ;
V_369 -> V_9 = V_369 -> V_55 ;
V_369 -> V_101 = 1 ;
}
F_13 ( & V_369 -> V_50 ) ;
F_13 ( & V_335 -> V_50 ) ;
}
static void F_308 ( struct V_11 * V_36 )
{
struct V_95 * V_98 ;
V_98 = F_66 ( V_36 , V_303 ) ;
V_36 -> V_416 . V_98 = V_98 ;
V_98 = F_66 ( V_36 , V_112 ) ;
V_36 -> V_339 . V_98 = V_98 ;
V_36 -> V_376 . V_98 = V_98 ;
V_36 -> V_417 . V_98 = V_98 ;
V_36 -> V_399 . V_98 = V_98 ;
V_36 -> V_381 . V_98 = V_98 ;
V_36 -> V_61 -> V_369 = & V_36 -> V_339 ;
V_36 -> V_397 -> V_369 = & V_36 -> V_339 ;
V_36 -> V_418 -> V_369 = & V_36 -> V_339 ;
V_36 -> V_238 -> V_369 = & V_36 -> V_339 ;
V_36 -> V_322 -> V_369 = & V_36 -> V_416 ;
F_307 ( V_36 ) ;
}
static void F_309 ( struct V_11 * V_36 )
{
F_294 ( V_36 , & V_36 -> V_339 , NULL ,
( T_2 ) - 1 ) ;
F_8 ( V_36 -> V_376 . V_55 > 0 ) ;
F_8 ( V_36 -> V_376 . V_9 > 0 ) ;
F_8 ( V_36 -> V_417 . V_55 > 0 ) ;
F_8 ( V_36 -> V_417 . V_9 > 0 ) ;
F_8 ( V_36 -> V_416 . V_55 > 0 ) ;
F_8 ( V_36 -> V_416 . V_9 > 0 ) ;
F_8 ( V_36 -> V_381 . V_55 > 0 ) ;
F_8 ( V_36 -> V_381 . V_9 > 0 ) ;
}
void F_310 ( struct V_114 * V_115 ,
struct V_33 * V_34 )
{
if ( ! V_115 -> V_369 )
return;
if ( ! V_115 -> V_289 )
return;
F_263 ( V_34 -> V_36 , L_9 ,
V_115 -> V_268 , V_115 -> V_289 , 0 ) ;
F_300 ( V_34 , V_115 -> V_369 , V_115 -> V_289 ) ;
V_115 -> V_289 = 0 ;
}
int F_311 ( struct V_114 * V_115 ,
struct V_259 * V_259 )
{
struct V_33 * V_34 = F_231 ( V_259 ) -> V_34 ;
struct V_337 * V_409 = F_292 ( V_115 , V_34 ) ;
struct V_337 * V_410 = V_34 -> V_419 ;
T_2 V_35 = F_269 ( V_34 , 1 ) ;
F_263 ( V_34 -> V_36 , L_10 ,
F_312 ( V_259 ) , V_35 , 1 ) ;
return F_295 ( V_409 , V_410 , V_35 ) ;
}
void F_313 ( struct V_259 * V_259 )
{
struct V_33 * V_34 = F_231 ( V_259 ) -> V_34 ;
T_2 V_35 = F_269 ( V_34 , 1 ) ;
F_263 ( V_34 -> V_36 , L_10 ,
F_312 ( V_259 ) , V_35 , 0 ) ;
F_300 ( V_34 , V_34 -> V_419 , V_35 ) ;
}
int F_314 ( struct V_33 * V_34 ,
struct V_337 * V_406 ,
int V_420 ,
T_2 * V_421 )
{
T_2 V_35 ;
int V_28 ;
if ( V_34 -> V_36 -> V_422 ) {
V_35 = 3 * V_34 -> V_415 ;
V_28 = F_315 ( V_34 , V_35 ) ;
if ( V_28 )
return V_28 ;
} else {
V_35 = 0 ;
}
* V_421 = V_35 ;
V_35 = F_269 ( V_34 , V_420 ) ;
V_406 -> V_98 = F_66 ( V_34 -> V_36 ,
V_112 ) ;
V_28 = F_301 ( V_34 , V_406 , V_35 ,
V_360 ) ;
if ( V_28 ) {
if ( * V_421 )
F_316 ( V_34 , * V_421 ) ;
}
return V_28 ;
}
void F_317 ( struct V_33 * V_34 ,
struct V_337 * V_406 ,
T_2 V_421 )
{
F_300 ( V_34 , V_406 , ( T_2 ) - 1 ) ;
if ( V_421 )
F_316 ( V_34 , V_421 ) ;
}
static unsigned F_318 ( struct V_259 * V_259 )
{
unsigned V_423 = 0 ;
unsigned V_424 = 0 ;
F_29 ( ! F_231 ( V_259 ) -> V_425 ) ;
F_231 ( V_259 ) -> V_425 -- ;
if ( F_231 ( V_259 ) -> V_425 == 0 &&
F_319 ( V_426 ,
& F_231 ( V_259 ) -> V_427 ) )
V_423 = 1 ;
if ( F_231 ( V_259 ) -> V_425 >=
F_231 ( V_259 ) -> V_428 )
return V_423 ;
V_424 = F_231 ( V_259 ) -> V_428 -
F_231 ( V_259 ) -> V_425 ;
F_231 ( V_259 ) -> V_428 -= V_424 ;
return V_424 + V_423 ;
}
static T_2 F_320 ( struct V_259 * V_259 , T_2 V_35 ,
int V_429 )
{
struct V_33 * V_34 = F_231 ( V_259 ) -> V_34 ;
T_2 V_413 ;
int V_430 ;
int V_431 ;
int V_432 ;
if ( F_231 ( V_259 ) -> V_6 & V_433 &&
F_231 ( V_259 ) -> V_434 == 0 )
return 0 ;
V_432 = ( int ) F_235 ( F_231 ( V_259 ) -> V_434 , V_34 -> V_326 ) ;
if ( V_429 )
F_231 ( V_259 ) -> V_434 += V_35 ;
else
F_231 ( V_259 ) -> V_434 -= V_35 ;
V_413 = F_321 ( V_34 ) - sizeof( struct V_435 ) ;
V_430 = ( int ) F_235 ( V_413 ,
sizeof( struct V_436 ) +
sizeof( struct V_437 ) ) ;
V_431 = ( int ) F_235 ( F_231 ( V_259 ) -> V_434 , V_34 -> V_326 ) ;
V_431 = V_431 + V_430 - 1 ;
V_431 = V_431 / V_430 ;
V_432 = V_432 + V_430 - 1 ;
V_432 = V_432 / V_430 ;
if ( V_432 == V_431 )
return 0 ;
if ( V_429 )
return F_269 ( V_34 ,
V_431 - V_432 ) ;
return F_269 ( V_34 , V_432 - V_431 ) ;
}
int F_322 ( struct V_259 * V_259 , T_2 V_35 )
{
struct V_33 * V_34 = F_231 ( V_259 ) -> V_34 ;
struct V_337 * V_369 = & V_34 -> V_36 -> V_376 ;
T_2 V_438 = 0 ;
T_2 V_434 ;
unsigned V_439 = 0 ;
int V_440 = 0 ;
enum V_353 V_295 = V_360 ;
int V_28 = 0 ;
bool V_441 = true ;
T_2 V_442 = 0 ;
unsigned V_443 ;
if ( F_323 ( V_259 ) ) {
V_295 = V_379 ;
V_441 = false ;
}
if ( V_295 != V_379 &&
F_324 ( V_34 -> V_36 ) )
F_196 ( 1 ) ;
if ( V_441 )
F_34 ( & F_231 ( V_259 ) -> V_444 ) ;
V_35 = F_258 ( V_35 , V_34 -> V_326 ) ;
F_11 ( & F_231 ( V_259 ) -> V_50 ) ;
F_231 ( V_259 ) -> V_425 ++ ;
if ( F_231 ( V_259 ) -> V_425 >
F_231 ( V_259 ) -> V_428 )
V_439 = F_231 ( V_259 ) -> V_425 -
F_231 ( V_259 ) -> V_428 ;
if ( ! F_325 ( V_426 ,
& F_231 ( V_259 ) -> V_427 ) ) {
V_439 ++ ;
V_440 = 1 ;
}
V_438 = F_269 ( V_34 , V_439 ) ;
V_438 += F_320 ( V_259 , V_35 , 1 ) ;
V_434 = F_231 ( V_259 ) -> V_434 ;
F_13 ( & F_231 ( V_259 ) -> V_50 ) ;
if ( V_34 -> V_36 -> V_422 ) {
V_28 = F_315 ( V_34 , V_35 +
V_439 * V_34 -> V_415 ) ;
if ( V_28 )
goto V_445;
}
V_28 = F_287 ( V_34 , V_369 , V_438 , V_295 ) ;
if ( F_289 ( V_28 ) ) {
if ( V_34 -> V_36 -> V_422 )
F_316 ( V_34 , V_35 +
V_439 * V_34 -> V_415 ) ;
goto V_445;
}
F_11 ( & F_231 ( V_259 ) -> V_50 ) ;
if ( V_440 ) {
F_326 ( V_426 ,
& F_231 ( V_259 ) -> V_427 ) ;
V_439 -- ;
}
F_231 ( V_259 ) -> V_428 += V_439 ;
F_13 ( & F_231 ( V_259 ) -> V_50 ) ;
if ( V_441 )
F_45 ( & F_231 ( V_259 ) -> V_444 ) ;
if ( V_438 )
F_263 ( V_34 -> V_36 , L_11 ,
F_312 ( V_259 ) , V_438 , 1 ) ;
F_293 ( V_369 , V_438 , 1 ) ;
return 0 ;
V_445:
F_11 ( & F_231 ( V_259 ) -> V_50 ) ;
V_443 = F_318 ( V_259 ) ;
if ( F_231 ( V_259 ) -> V_434 == V_434 ) {
F_320 ( V_259 , V_35 , 0 ) ;
} else {
T_2 V_446 = F_231 ( V_259 ) -> V_434 ;
T_2 V_323 ;
V_323 = V_434 - F_231 ( V_259 ) -> V_434 ;
F_231 ( V_259 ) -> V_434 = V_434 ;
V_442 = F_320 ( V_259 , V_323 , 0 ) ;
F_231 ( V_259 ) -> V_434 = V_434 - V_35 ;
V_323 = V_434 - V_446 ;
V_323 = F_320 ( V_259 , V_323 , 0 ) ;
F_231 ( V_259 ) -> V_434 = V_446 - V_35 ;
if ( V_323 > V_442 )
V_442 = V_323 - V_442 ;
else
V_442 = 0 ;
}
F_13 ( & F_231 ( V_259 ) -> V_50 ) ;
if ( V_443 )
V_442 += F_269 ( V_34 , V_443 ) ;
if ( V_442 ) {
F_300 ( V_34 , V_369 , V_442 ) ;
F_263 ( V_34 -> V_36 , L_11 ,
F_312 ( V_259 ) , V_442 , 0 ) ;
}
if ( V_441 )
F_45 ( & F_231 ( V_259 ) -> V_444 ) ;
return V_28 ;
}
void F_327 ( struct V_259 * V_259 , T_2 V_35 )
{
struct V_33 * V_34 = F_231 ( V_259 ) -> V_34 ;
T_2 V_442 = 0 ;
unsigned V_443 ;
V_35 = F_258 ( V_35 , V_34 -> V_326 ) ;
F_11 ( & F_231 ( V_259 ) -> V_50 ) ;
V_443 = F_318 ( V_259 ) ;
if ( V_35 )
V_442 = F_320 ( V_259 , V_35 , 0 ) ;
F_13 ( & F_231 ( V_259 ) -> V_50 ) ;
if ( V_443 > 0 )
V_442 += F_269 ( V_34 , V_443 ) ;
F_263 ( V_34 -> V_36 , L_11 ,
F_312 ( V_259 ) , V_442 , 0 ) ;
if ( V_34 -> V_36 -> V_422 ) {
F_316 ( V_34 , V_35 +
V_443 * V_34 -> V_415 ) ;
}
F_300 ( V_34 , & V_34 -> V_36 -> V_376 ,
V_442 ) ;
}
int F_328 ( struct V_259 * V_259 , T_2 V_35 )
{
int V_28 ;
V_28 = F_236 ( V_259 , V_35 ) ;
if ( V_28 )
return V_28 ;
V_28 = F_322 ( V_259 , V_35 ) ;
if ( V_28 ) {
F_238 ( V_259 , V_35 ) ;
return V_28 ;
}
return 0 ;
}
void F_329 ( struct V_259 * V_259 , T_2 V_35 )
{
F_327 ( V_259 , V_35 ) ;
F_238 ( V_259 , V_35 ) ;
}
static int F_330 ( struct V_33 * V_34 ,
T_2 V_26 , T_2 V_35 , int V_329 )
{
struct V_1 * V_2 = NULL ;
struct V_11 * V_12 = V_34 -> V_36 ;
T_2 V_447 = V_35 ;
T_2 V_448 ;
T_2 V_449 ;
int V_108 ;
F_11 ( & V_12 -> V_441 ) ;
V_448 = F_331 ( V_12 -> V_343 ) ;
if ( V_329 )
V_448 += V_35 ;
else
V_448 -= V_35 ;
F_332 ( V_12 -> V_343 , V_448 ) ;
F_13 ( & V_12 -> V_441 ) ;
while ( V_447 ) {
V_2 = F_65 ( V_12 , V_26 ) ;
if ( ! V_2 )
return - V_153 ;
if ( V_2 -> V_6 & ( V_280 |
V_281 |
V_282 ) )
V_108 = 2 ;
else
V_108 = 1 ;
if ( ! V_329 && V_2 -> V_3 == V_89 )
F_49 ( V_2 , 1 ) ;
V_449 = V_26 - V_2 -> V_20 . V_21 ;
F_8 ( V_449 > V_2 -> V_20 . V_32 ) ;
F_11 ( & V_2 -> V_98 -> V_50 ) ;
F_11 ( & V_2 -> V_50 ) ;
if ( F_234 ( V_34 , V_272 ) &&
V_2 -> V_265 < V_274 )
V_2 -> V_265 = V_274 ;
V_2 -> V_275 = 1 ;
V_448 = F_73 ( & V_2 -> V_110 ) ;
V_35 = F_275 ( V_447 , V_2 -> V_20 . V_32 - V_449 ) ;
if ( V_329 ) {
V_448 += V_35 ;
F_333 ( & V_2 -> V_110 , V_448 ) ;
V_2 -> V_9 -= V_35 ;
V_2 -> V_98 -> V_289 -= V_35 ;
V_2 -> V_98 -> V_279 += V_35 ;
V_2 -> V_98 -> V_284 += V_35 * V_108 ;
F_13 ( & V_2 -> V_50 ) ;
F_13 ( & V_2 -> V_98 -> V_50 ) ;
} else {
V_448 -= V_35 ;
F_333 ( & V_2 -> V_110 , V_448 ) ;
V_2 -> V_8 += V_35 ;
V_2 -> V_98 -> V_288 += V_35 ;
V_2 -> V_98 -> V_279 -= V_35 ;
V_2 -> V_98 -> V_284 -= V_35 * V_108 ;
F_13 ( & V_2 -> V_50 ) ;
F_13 ( & V_2 -> V_98 -> V_50 ) ;
F_334 ( V_12 -> V_57 ,
V_26 , V_26 + V_35 - 1 ,
V_39 | V_450 ) ;
}
F_6 ( V_2 ) ;
V_447 -= V_35 ;
V_26 += V_35 ;
}
return 0 ;
}
static T_2 V_25 ( struct V_33 * V_34 , T_2 V_102 )
{
struct V_1 * V_2 ;
T_2 V_26 ;
F_11 ( & V_34 -> V_36 -> V_17 ) ;
V_26 = V_34 -> V_36 -> V_25 ;
F_13 ( & V_34 -> V_36 -> V_17 ) ;
if ( V_26 < ( T_2 ) - 1 )
return V_26 ;
V_2 = F_64 ( V_34 -> V_36 , V_102 ) ;
if ( ! V_2 )
return 0 ;
V_26 = V_2 -> V_20 . V_21 ;
F_6 ( V_2 ) ;
return V_26 ;
}
static int F_335 ( struct V_33 * V_34 ,
struct V_1 * V_2 ,
T_2 V_26 , T_2 V_35 , int V_9 )
{
F_11 ( & V_2 -> V_98 -> V_50 ) ;
F_11 ( & V_2 -> V_50 ) ;
V_2 -> V_8 += V_35 ;
V_2 -> V_98 -> V_288 += V_35 ;
if ( V_9 ) {
V_2 -> V_9 -= V_35 ;
V_2 -> V_98 -> V_289 -= V_35 ;
}
F_13 ( & V_2 -> V_50 ) ;
F_13 ( & V_2 -> V_98 -> V_50 ) ;
F_334 ( V_34 -> V_36 -> V_57 , V_26 ,
V_26 + V_35 - 1 , V_39 | V_450 ) ;
return 0 ;
}
int F_162 ( struct V_33 * V_34 ,
T_2 V_26 , T_2 V_35 , int V_9 )
{
struct V_1 * V_2 ;
V_2 = F_65 ( V_34 -> V_36 , V_26 ) ;
F_29 ( ! V_2 ) ;
F_335 ( V_34 , V_2 , V_26 , V_35 , V_9 ) ;
F_6 ( V_2 ) ;
return 0 ;
}
int F_336 ( struct V_33 * V_34 ,
T_2 V_26 , T_2 V_35 )
{
struct V_1 * V_2 ;
V_2 = F_65 ( V_34 -> V_36 , V_26 ) ;
F_29 ( ! V_2 ) ;
F_49 ( V_2 , 1 ) ;
F_335 ( V_34 , V_2 , V_26 , V_35 , 0 ) ;
F_337 ( V_2 , V_26 , V_35 ) ;
F_6 ( V_2 ) ;
return 0 ;
}
static int F_338 ( struct V_1 * V_2 ,
T_2 V_35 , int V_429 )
{
struct V_95 * V_98 = V_2 -> V_98 ;
int V_28 = 0 ;
F_11 ( & V_98 -> V_50 ) ;
F_11 ( & V_2 -> V_50 ) ;
if ( V_429 != V_451 ) {
if ( V_2 -> V_111 ) {
V_28 = - V_176 ;
} else {
V_2 -> V_9 += V_35 ;
V_98 -> V_289 += V_35 ;
if ( V_429 == V_452 ) {
F_263 ( V_2 -> V_36 ,
L_7 , V_98 -> V_6 ,
V_35 , 0 ) ;
V_98 -> V_291 -= V_35 ;
}
}
} else {
if ( V_2 -> V_111 )
V_98 -> V_290 += V_35 ;
V_2 -> V_9 -= V_35 ;
V_98 -> V_289 -= V_35 ;
V_98 -> V_403 ++ ;
}
F_13 ( & V_2 -> V_50 ) ;
F_13 ( & V_98 -> V_50 ) ;
return V_28 ;
}
void F_339 ( struct V_114 * V_115 ,
struct V_33 * V_34 )
{
struct V_11 * V_36 = V_34 -> V_36 ;
struct V_48 * V_216 ;
struct V_48 * V_52 ;
struct V_1 * V_2 ;
F_60 ( & V_36 -> V_77 ) ;
F_340 (caching_ctl, next,
&fs_info->caching_block_groups, list) {
V_2 = V_52 -> V_13 ;
if ( F_1 ( V_2 ) ) {
V_2 -> V_92 = ( T_2 ) - 1 ;
F_171 ( & V_52 -> V_85 ) ;
F_25 ( V_52 ) ;
} else {
V_2 -> V_92 = V_52 -> V_81 ;
}
}
if ( V_36 -> V_57 == & V_36 -> V_37 [ 0 ] )
V_36 -> V_57 = & V_36 -> V_37 [ 1 ] ;
else
V_36 -> V_57 = & V_36 -> V_37 [ 0 ] ;
F_62 ( & V_36 -> V_77 ) ;
F_307 ( V_36 ) ;
}
static int F_341 ( struct V_33 * V_34 , T_2 V_31 , T_2 V_30 )
{
struct V_11 * V_36 = V_34 -> V_36 ;
struct V_1 * V_2 = NULL ;
struct V_95 * V_98 ;
struct V_337 * V_338 = & V_36 -> V_339 ;
T_2 V_113 ;
bool V_277 ;
while ( V_31 <= V_30 ) {
V_277 = false ;
if ( ! V_2 ||
V_31 >= V_2 -> V_20 . V_21 + V_2 -> V_20 . V_32 ) {
if ( V_2 )
F_6 ( V_2 ) ;
V_2 = F_65 ( V_36 , V_31 ) ;
F_29 ( ! V_2 ) ;
}
V_113 = V_2 -> V_20 . V_21 + V_2 -> V_20 . V_32 - V_31 ;
V_113 = F_275 ( V_113 , V_30 + 1 - V_31 ) ;
if ( V_31 < V_2 -> V_92 ) {
V_113 = F_275 ( V_113 , V_2 -> V_92 - V_31 ) ;
F_28 ( V_2 , V_31 , V_113 ) ;
}
V_31 += V_113 ;
V_98 = V_2 -> V_98 ;
F_11 ( & V_98 -> V_50 ) ;
F_11 ( & V_2 -> V_50 ) ;
V_2 -> V_8 -= V_113 ;
V_98 -> V_288 -= V_113 ;
if ( V_2 -> V_111 ) {
V_98 -> V_290 += V_113 ;
V_277 = true ;
}
F_13 ( & V_2 -> V_50 ) ;
if ( ! V_277 && V_338 -> V_98 == V_98 ) {
F_11 ( & V_338 -> V_50 ) ;
if ( ! V_338 -> V_101 ) {
V_113 = F_275 ( V_113 , V_338 -> V_55 -
V_338 -> V_9 ) ;
V_338 -> V_9 += V_113 ;
V_98 -> V_291 += V_113 ;
if ( V_338 -> V_9 >= V_338 -> V_55 )
V_338 -> V_101 = 1 ;
}
F_13 ( & V_338 -> V_50 ) ;
}
F_13 ( & V_98 -> V_50 ) ;
}
if ( V_2 )
F_6 ( V_2 ) ;
return 0 ;
}
int F_342 ( struct V_114 * V_115 ,
struct V_33 * V_34 )
{
struct V_11 * V_36 = V_34 -> V_36 ;
struct V_453 * V_454 ;
T_2 V_31 ;
T_2 V_30 ;
int V_28 ;
if ( V_115 -> V_211 )
return 0 ;
if ( V_36 -> V_57 == & V_36 -> V_37 [ 0 ] )
V_454 = & V_36 -> V_37 [ 1 ] ;
else
V_454 = & V_36 -> V_37 [ 0 ] ;
while ( 1 ) {
V_28 = F_27 ( V_454 , 0 , & V_31 , & V_30 ,
V_58 , NULL ) ;
if ( V_28 )
break;
if ( F_234 ( V_34 , V_455 ) )
V_28 = F_143 ( V_34 , V_31 ,
V_30 + 1 - V_31 , NULL ) ;
F_343 ( V_454 , V_31 , V_30 , V_39 ) ;
F_341 ( V_34 , V_31 , V_30 ) ;
F_46 () ;
}
return 0 ;
}
static int F_153 ( struct V_114 * V_115 ,
struct V_33 * V_34 ,
T_2 V_26 , T_2 V_35 , T_2 V_16 ,
T_2 V_146 , T_2 V_456 ,
T_2 V_457 , int V_159 ,
struct V_178 * V_131 )
{
struct V_66 V_20 ;
struct V_62 * V_63 ;
struct V_11 * V_12 = V_34 -> V_36 ;
struct V_33 * V_61 = V_12 -> V_61 ;
struct V_64 * V_65 ;
struct V_120 * V_121 ;
struct V_162 * V_163 ;
int V_28 ;
int V_182 ;
int V_458 = 0 ;
int V_459 = 0 ;
int V_460 = 1 ;
T_3 V_122 ;
T_2 V_116 ;
V_63 = F_32 () ;
if ( ! V_63 )
return - V_84 ;
V_63 -> V_73 = 1 ;
V_63 -> V_202 = 1 ;
V_182 = V_456 >= V_143 ;
F_29 ( ! V_182 && V_159 != 1 ) ;
V_28 = F_135 ( V_115 , V_61 , V_63 , & V_163 ,
V_26 , V_35 , V_16 ,
V_146 , V_456 ,
V_457 ) ;
if ( V_28 == 0 ) {
V_458 = V_63 -> V_80 [ 0 ] ;
while ( V_458 >= 0 ) {
F_39 ( V_63 -> V_79 [ 0 ] , & V_20 ,
V_458 ) ;
if ( V_20 . V_21 != V_26 )
break;
if ( V_20 . type == V_74 &&
V_20 . V_32 == V_35 ) {
V_459 = 1 ;
break;
}
if ( V_63 -> V_80 [ 0 ] - V_458 > 5 )
break;
V_458 -- ;
}
#ifdef F_82
V_122 = F_78 ( V_63 -> V_79 [ 0 ] , V_458 ) ;
if ( V_459 && V_122 < sizeof( * V_121 ) )
V_459 = 0 ;
#endif
if ( ! V_459 ) {
F_29 ( V_163 ) ;
V_28 = F_140 ( V_115 , V_61 , V_63 ,
NULL , V_159 ,
V_182 ) ;
if ( V_28 ) {
F_149 ( V_115 , V_61 , V_28 ) ;
goto V_70;
}
F_43 ( V_63 ) ;
V_63 -> V_202 = 1 ;
V_20 . V_21 = V_26 ;
V_20 . type = V_74 ;
V_20 . V_32 = V_35 ;
V_28 = F_36 ( V_115 , V_61 ,
& V_20 , V_63 , - 1 , 1 ) ;
if ( V_28 ) {
F_174 ( V_231 L_12
L_13 , V_28 ,
( unsigned long long ) V_26 ) ;
if ( V_28 > 0 )
F_344 ( V_61 ,
V_63 -> V_79 [ 0 ] ) ;
}
if ( V_28 < 0 ) {
F_149 ( V_115 , V_61 , V_28 ) ;
goto V_70;
}
V_458 = V_63 -> V_80 [ 0 ] ;
}
} else if ( V_28 == - V_153 ) {
F_344 ( V_61 , V_63 -> V_79 [ 0 ] ) ;
F_8 ( 1 ) ;
F_174 ( V_231 L_14
L_15 ,
( unsigned long long ) V_26 ,
( unsigned long long ) V_16 ,
( unsigned long long ) V_146 ,
( unsigned long long ) V_456 ,
( unsigned long long ) V_457 ) ;
} else {
F_149 ( V_115 , V_61 , V_28 ) ;
goto V_70;
}
V_65 = V_63 -> V_79 [ 0 ] ;
V_122 = F_78 ( V_65 , V_458 ) ;
#ifdef F_82
if ( V_122 < sizeof( * V_121 ) ) {
F_29 ( V_459 || V_458 != V_63 -> V_80 [ 0 ] ) ;
V_28 = F_88 ( V_115 , V_61 , V_63 ,
V_456 , 0 ) ;
if ( V_28 < 0 ) {
F_149 ( V_115 , V_61 , V_28 ) ;
goto V_70;
}
F_43 ( V_63 ) ;
V_63 -> V_202 = 1 ;
V_20 . V_21 = V_26 ;
V_20 . type = V_74 ;
V_20 . V_32 = V_35 ;
V_28 = F_36 ( V_115 , V_61 , & V_20 , V_63 ,
- 1 , 1 ) ;
if ( V_28 ) {
F_174 ( V_231 L_12
L_13 , V_28 ,
( unsigned long long ) V_26 ) ;
F_344 ( V_61 , V_63 -> V_79 [ 0 ] ) ;
}
if ( V_28 < 0 ) {
F_149 ( V_115 , V_61 , V_28 ) ;
goto V_70;
}
V_458 = V_63 -> V_80 [ 0 ] ;
V_65 = V_63 -> V_79 [ 0 ] ;
V_122 = F_78 ( V_65 , V_458 ) ;
}
#endif
F_29 ( V_122 < sizeof( * V_121 ) ) ;
V_121 = F_79 ( V_65 , V_458 ,
struct V_120 ) ;
if ( V_456 < V_143 ) {
struct V_138 * V_139 ;
F_29 ( V_122 < sizeof( * V_121 ) + sizeof( * V_139 ) ) ;
V_139 = (struct V_138 * ) ( V_121 + 1 ) ;
F_8 ( V_456 != F_345 ( V_65 , V_139 ) ) ;
}
V_116 = F_80 ( V_65 , V_121 ) ;
F_29 ( V_116 < V_159 ) ;
V_116 -= V_159 ;
if ( V_116 > 0 ) {
if ( V_131 )
F_131 ( V_131 , V_65 , V_121 ) ;
if ( V_163 ) {
F_29 ( ! V_459 ) ;
} else {
F_91 ( V_65 , V_121 , V_116 ) ;
F_96 ( V_65 ) ;
}
if ( V_459 ) {
V_28 = F_140 ( V_115 , V_61 , V_63 ,
V_163 , V_159 ,
V_182 ) ;
if ( V_28 ) {
F_149 ( V_115 , V_61 , V_28 ) ;
goto V_70;
}
}
} else {
if ( V_459 ) {
F_29 ( V_182 && V_159 !=
F_119 ( V_34 , V_63 , V_163 ) ) ;
if ( V_163 ) {
F_29 ( V_63 -> V_80 [ 0 ] != V_458 ) ;
} else {
F_29 ( V_63 -> V_80 [ 0 ] != V_458 + 1 ) ;
V_63 -> V_80 [ 0 ] = V_458 ;
V_460 = 2 ;
}
}
V_28 = F_346 ( V_115 , V_61 , V_63 , V_63 -> V_80 [ 0 ] ,
V_460 ) ;
if ( V_28 ) {
F_149 ( V_115 , V_61 , V_28 ) ;
goto V_70;
}
F_43 ( V_63 ) ;
if ( V_182 ) {
V_28 = F_163 ( V_115 , V_34 , V_26 , V_35 ) ;
if ( V_28 ) {
F_149 ( V_115 , V_61 , V_28 ) ;
goto V_70;
}
}
V_28 = F_330 ( V_34 , V_26 , V_35 , 0 ) ;
if ( V_28 ) {
F_149 ( V_115 , V_61 , V_28 ) ;
goto V_70;
}
}
V_70:
F_48 ( V_63 ) ;
return V_28 ;
}
static T_1 int F_347 ( struct V_114 * V_115 ,
struct V_33 * V_34 , T_2 V_26 )
{
struct V_117 * V_97 ;
struct V_118 * V_119 ;
struct V_203 * V_151 ;
struct V_14 * V_130 ;
int V_28 = 0 ;
V_119 = & V_115 -> V_129 -> V_119 ;
F_11 ( & V_119 -> V_50 ) ;
V_97 = F_85 ( V_115 , V_26 ) ;
if ( ! V_97 )
goto V_70;
V_130 = F_203 ( & V_97 -> V_130 . V_14 ) ;
if ( ! V_130 )
goto V_70;
V_151 = F_12 ( V_130 , struct V_203 , V_14 ) ;
if ( V_151 -> V_26 == V_26 )
goto V_70;
if ( V_97 -> V_131 ) {
if ( ! V_97 -> V_215 )
goto V_70;
F_173 ( V_97 -> V_131 ) ;
V_97 -> V_131 = NULL ;
}
if ( ! F_86 ( & V_97 -> V_76 ) )
goto V_70;
V_97 -> V_130 . V_220 = 0 ;
F_175 ( & V_97 -> V_130 . V_14 , & V_119 -> V_34 ) ;
V_119 -> V_221 -- ;
V_119 -> V_461 -- ;
if ( F_165 ( & V_97 -> V_213 ) )
V_119 -> V_218 -- ;
F_171 ( & V_97 -> V_213 ) ;
F_13 ( & V_119 -> V_50 ) ;
F_29 ( V_97 -> V_131 ) ;
if ( V_97 -> V_215 )
V_28 = 1 ;
F_45 ( & V_97 -> V_76 ) ;
F_87 ( & V_97 -> V_130 ) ;
return V_28 ;
V_70:
F_13 ( & V_119 -> V_50 ) ;
return 0 ;
}
void F_348 ( struct V_114 * V_115 ,
struct V_33 * V_34 ,
struct V_64 * V_250 ,
T_2 V_16 , int V_462 )
{
struct V_1 * V_2 = NULL ;
int V_28 ;
if ( V_34 -> V_246 . V_21 != V_200 ) {
V_28 = F_146 ( V_34 -> V_36 , V_115 ,
V_250 -> V_31 , V_250 -> V_113 ,
V_16 , V_34 -> V_246 . V_21 ,
F_211 ( V_250 ) ,
V_210 , NULL , 0 ) ;
F_29 ( V_28 ) ;
}
if ( ! V_462 )
return;
V_2 = F_65 ( V_34 -> V_36 , V_250 -> V_31 ) ;
if ( F_349 ( V_250 ) == V_115 -> V_268 ) {
if ( V_34 -> V_246 . V_21 != V_200 ) {
V_28 = F_347 ( V_115 , V_34 , V_250 -> V_31 ) ;
if ( ! V_28 )
goto V_70;
}
if ( F_350 ( V_250 , V_463 ) ) {
F_335 ( V_34 , V_2 , V_250 -> V_31 , V_250 -> V_113 , 1 ) ;
goto V_70;
}
F_8 ( F_325 ( V_464 , & V_250 -> V_465 ) ) ;
F_28 ( V_2 , V_250 -> V_31 , V_250 -> V_113 ) ;
F_338 ( V_2 , V_250 -> V_113 , V_451 ) ;
}
V_70:
F_351 ( V_466 , & V_250 -> V_465 ) ;
F_6 ( V_2 ) ;
}
int V_256 ( struct V_114 * V_115 , struct V_33 * V_34 ,
T_2 V_26 , T_2 V_35 , T_2 V_16 , T_2 V_146 ,
T_2 V_104 , T_2 V_32 , int V_199 )
{
int V_28 ;
struct V_11 * V_36 = V_34 -> V_36 ;
if ( V_146 == V_200 ) {
F_8 ( V_104 >= V_143 ) ;
F_162 ( V_34 , V_26 , V_35 , 1 ) ;
V_28 = 0 ;
} else if ( V_104 < V_143 ) {
V_28 = F_146 ( V_36 , V_115 , V_26 ,
V_35 ,
V_16 , V_146 , ( int ) V_104 ,
V_210 , NULL , V_199 ) ;
} else {
V_28 = F_147 ( V_36 , V_115 , V_26 ,
V_35 ,
V_16 , V_146 , V_104 ,
V_32 , V_210 ,
NULL , V_199 ) ;
}
return V_28 ;
}
static T_2 F_352 ( struct V_33 * V_34 ,
struct V_1 * V_2 ,
T_2 V_232 , T_2 V_35 )
{
T_2 V_28 = F_258 ( V_232 , V_34 -> V_467 ) ;
return V_28 ;
}
static T_1 int
F_353 ( struct V_1 * V_2 ,
T_2 V_35 )
{
struct V_48 * V_52 ;
V_52 = F_24 ( V_2 ) ;
if ( ! V_52 )
return 0 ;
F_282 ( V_52 -> V_82 , F_1 ( V_2 ) ||
( V_2 -> V_10 -> V_468 >= V_35 ) ) ;
F_25 ( V_52 ) ;
return 0 ;
}
static T_1 int
F_354 ( struct V_1 * V_2 )
{
struct V_48 * V_52 ;
V_52 = F_24 ( V_2 ) ;
if ( ! V_52 )
return 0 ;
F_282 ( V_52 -> V_82 , F_1 ( V_2 ) ) ;
F_25 ( V_52 ) ;
return 0 ;
}
int F_355 ( T_2 V_6 )
{
if ( V_6 & V_282 )
return V_469 ;
else if ( V_6 & V_281 )
return V_470 ;
else if ( V_6 & V_280 )
return V_471 ;
else if ( V_6 & V_319 )
return V_472 ;
else if ( V_6 & V_320 )
return V_473 ;
else if ( V_6 & V_321 )
return V_474 ;
return V_475 ;
}
static int F_356 ( struct V_1 * V_2 )
{
return F_355 ( V_2 -> V_6 ) ;
}
static T_1 int F_357 ( struct V_114 * V_115 ,
struct V_33 * V_476 ,
T_2 V_35 , T_2 V_477 ,
T_2 V_478 , struct V_66 * V_206 ,
T_2 V_309 )
{
int V_28 = 0 ;
struct V_33 * V_34 = V_476 -> V_36 -> V_61 ;
struct V_479 * V_480 = NULL ;
struct V_1 * V_13 = NULL ;
struct V_1 * V_481 ;
T_2 V_102 = 0 ;
int V_482 = 2 * 1024 * 1024 ;
struct V_95 * V_98 ;
int V_483 = 0 ;
int V_484 = F_355 ( V_309 ) ;
int V_485 = ( V_309 & V_296 ) ?
V_486 : V_452 ;
bool V_487 = false ;
bool V_488 = false ;
bool V_489 = false ;
bool V_490 = true ;
bool V_491 = false ;
F_8 ( V_35 < V_34 -> V_326 ) ;
F_76 ( V_206 , V_74 ) ;
V_206 -> V_21 = 0 ;
V_206 -> V_32 = 0 ;
F_358 ( V_476 , V_35 , V_477 , V_309 ) ;
V_98 = F_66 ( V_34 -> V_36 , V_309 ) ;
if ( ! V_98 ) {
F_174 ( V_231 L_16 , V_309 ) ;
return - V_332 ;
}
if ( F_273 ( V_98 ) )
V_490 = false ;
if ( V_309 & V_112 && V_490 ) {
V_480 = & V_34 -> V_36 -> V_492 ;
if ( ! F_234 ( V_34 , V_493 ) )
V_482 = 64 * 1024 ;
}
if ( ( V_309 & V_296 ) && V_490 &&
F_234 ( V_34 , V_493 ) ) {
V_480 = & V_34 -> V_36 -> V_494 ;
}
if ( V_480 ) {
F_11 ( & V_480 -> V_50 ) ;
if ( V_480 -> V_13 )
V_478 = V_480 -> V_495 ;
F_13 ( & V_480 -> V_50 ) ;
}
V_102 = F_72 ( V_102 , V_25 ( V_34 , 0 ) ) ;
V_102 = F_72 ( V_102 , V_478 ) ;
if ( ! V_480 )
V_482 = 0 ;
if ( V_102 == V_478 ) {
V_13 = F_65 ( V_34 -> V_36 ,
V_102 ) ;
V_481 = V_13 ;
if ( V_13 && F_3 ( V_13 , V_309 ) &&
V_13 -> V_3 != V_89 ) {
F_35 ( & V_98 -> V_287 ) ;
if ( F_165 ( & V_13 -> V_85 ) ||
V_13 -> V_111 ) {
F_6 ( V_13 ) ;
F_44 ( & V_98 -> V_287 ) ;
} else {
V_484 = F_356 ( V_13 ) ;
goto V_496;
}
} else if ( V_13 ) {
F_6 ( V_13 ) ;
}
}
V_497:
V_491 = false ;
F_35 ( & V_98 -> V_287 ) ;
F_359 (block_group, &space_info->block_groups[index],
list) {
T_2 V_32 ;
int V_3 ;
V_481 = V_13 ;
F_4 ( V_13 ) ;
V_102 = V_13 -> V_20 . V_21 ;
if ( ! F_3 ( V_13 , V_309 ) ) {
T_2 V_498 = V_280 |
V_281 |
V_320 |
V_321 |
V_282 ;
if ( ( V_309 & V_498 ) && ! ( V_13 -> V_6 & V_498 ) )
goto V_483;
}
V_496:
V_3 = F_1 ( V_13 ) ;
if ( F_289 ( ! V_3 ) ) {
V_487 = true ;
V_28 = F_49 ( V_13 , 0 ) ;
F_29 ( V_28 < 0 ) ;
V_28 = 0 ;
}
if ( F_289 ( V_13 -> V_111 ) )
goto V_483;
if ( V_480 ) {
unsigned long V_499 ;
F_11 ( & V_480 -> V_500 ) ;
V_481 = V_480 -> V_13 ;
if ( V_481 != V_13 &&
( ! V_481 ||
V_481 -> V_111 ||
! F_3 ( V_481 , V_309 ) ) ) {
V_481 = V_13 ;
goto V_501;
}
if ( V_481 != V_13 )
F_4 ( V_481 ) ;
V_32 = F_360 ( V_481 ,
V_480 , V_35 , V_481 -> V_20 . V_21 ) ;
if ( V_32 ) {
F_13 ( & V_480 -> V_500 ) ;
F_361 ( V_34 ,
V_13 , V_102 , V_35 ) ;
goto V_502;
}
F_8 ( V_480 -> V_13 != V_481 ) ;
if ( V_481 != V_13 ) {
F_6 ( V_481 ) ;
V_481 = V_13 ;
}
V_501:
F_29 ( V_481 != V_13 ) ;
if ( V_483 >= V_503 &&
V_480 -> V_13 != V_13 ) {
F_13 ( & V_480 -> V_500 ) ;
goto V_504;
}
F_362 ( NULL , V_480 ) ;
if ( V_483 >= V_503 ) {
F_13 ( & V_480 -> V_500 ) ;
goto V_504;
}
V_499 = F_33 (unsigned long,
empty_cluster + empty_size,
block_group->full_stripe_len) ;
V_28 = F_363 ( V_115 , V_34 ,
V_13 , V_480 ,
V_102 , V_35 ,
V_499 ) ;
if ( V_28 == 0 ) {
V_32 = F_360 ( V_13 ,
V_480 , V_35 ,
V_102 ) ;
if ( V_32 ) {
F_13 ( & V_480 -> V_500 ) ;
F_361 ( V_34 ,
V_13 , V_102 ,
V_35 ) ;
goto V_502;
}
} else if ( ! V_3 && V_483 > V_505
&& ! V_488 ) {
F_13 ( & V_480 -> V_500 ) ;
V_488 = true ;
F_353 ( V_13 ,
V_35 + V_482 + V_477 ) ;
goto V_496;
}
F_362 ( NULL , V_480 ) ;
F_13 ( & V_480 -> V_500 ) ;
goto V_483;
}
V_504:
F_11 ( & V_13 -> V_10 -> V_506 ) ;
if ( V_3 &&
V_13 -> V_10 -> V_468 <
V_35 + V_482 + V_477 ) {
F_13 ( & V_13 -> V_10 -> V_506 ) ;
goto V_483;
}
F_13 ( & V_13 -> V_10 -> V_506 ) ;
V_32 = F_364 ( V_13 , V_102 ,
V_35 , V_477 ) ;
if ( ! V_32 && ! V_489 && ! V_3 &&
V_483 > V_505 ) {
F_353 ( V_13 ,
V_35 + V_477 ) ;
V_489 = true ;
goto V_496;
} else if ( ! V_32 ) {
if ( ! V_3 )
V_491 = true ;
goto V_483;
}
V_502:
V_102 = F_352 ( V_34 , V_481 ,
V_32 , V_35 ) ;
if ( V_102 + V_35 >
V_481 -> V_20 . V_21 + V_481 -> V_20 . V_32 ) {
F_28 ( V_481 , V_32 , V_35 ) ;
goto V_483;
}
if ( V_32 < V_102 )
F_28 ( V_481 , V_32 ,
V_102 - V_32 ) ;
F_29 ( V_32 > V_102 ) ;
V_28 = F_338 ( V_481 , V_35 ,
V_485 ) ;
if ( V_28 == - V_176 ) {
F_28 ( V_481 , V_32 , V_35 ) ;
goto V_483;
}
V_206 -> V_21 = V_102 ;
V_206 -> V_32 = V_35 ;
F_365 ( V_476 , V_13 ,
V_102 , V_35 ) ;
if ( V_481 != V_13 )
F_6 ( V_481 ) ;
F_6 ( V_13 ) ;
break;
V_483:
V_488 = false ;
V_489 = false ;
F_29 ( V_484 != F_356 ( V_13 ) ) ;
if ( V_481 != V_13 )
F_6 ( V_481 ) ;
F_6 ( V_13 ) ;
}
F_44 ( & V_98 -> V_287 ) ;
if ( ! V_206 -> V_21 && V_483 >= V_507 && V_491 )
goto V_497;
if ( ! V_206 -> V_21 && ++ V_484 < V_285 )
goto V_497;
if ( ! V_206 -> V_21 && V_483 < V_503 ) {
V_484 = 0 ;
V_483 ++ ;
if ( V_483 == V_508 ) {
V_28 = F_260 ( V_115 , V_34 , V_309 ,
V_331 ) ;
if ( V_28 < 0 && V_28 != - V_332 ) {
F_149 ( V_115 ,
V_34 , V_28 ) ;
goto V_70;
}
}
if ( V_483 == V_503 ) {
V_477 = 0 ;
V_482 = 0 ;
}
goto V_497;
} else if ( ! V_206 -> V_21 ) {
V_28 = - V_332 ;
} else if ( V_206 -> V_21 ) {
V_28 = 0 ;
}
V_70:
return V_28 ;
}
static void F_271 ( struct V_95 * V_12 , T_2 V_323 ,
int V_509 )
{
struct V_1 * V_2 ;
int V_484 = 0 ;
F_11 ( & V_12 -> V_50 ) ;
F_174 ( V_347 L_17 ,
( unsigned long long ) V_12 -> V_6 ,
( unsigned long long ) ( V_12 -> V_278 - V_12 -> V_279 -
V_12 -> V_288 - V_12 -> V_289 -
V_12 -> V_290 ) ,
( V_12 -> V_101 ) ? L_5 : L_18 ) ;
F_174 ( V_347 L_19
L_20 ,
( unsigned long long ) V_12 -> V_278 ,
( unsigned long long ) V_12 -> V_279 ,
( unsigned long long ) V_12 -> V_288 ,
( unsigned long long ) V_12 -> V_289 ,
( unsigned long long ) V_12 -> V_291 ,
( unsigned long long ) V_12 -> V_290 ) ;
F_13 ( & V_12 -> V_50 ) ;
if ( ! V_509 )
return;
F_35 ( & V_12 -> V_287 ) ;
V_75:
F_359 (cache, &info->block_groups[index], list) {
F_11 ( & V_2 -> V_50 ) ;
F_174 ( V_347 L_21 ,
( unsigned long long ) V_2 -> V_20 . V_21 ,
( unsigned long long ) V_2 -> V_20 . V_32 ,
( unsigned long long ) F_73 ( & V_2 -> V_110 ) ,
( unsigned long long ) V_2 -> V_8 ,
( unsigned long long ) V_2 -> V_9 ,
V_2 -> V_111 ? L_22 : L_5 ) ;
F_366 ( V_2 , V_323 ) ;
F_13 ( & V_2 -> V_50 ) ;
}
if ( ++ V_484 < V_285 )
goto V_75;
F_44 ( & V_12 -> V_287 ) ;
}
int F_367 ( struct V_114 * V_115 ,
struct V_33 * V_34 ,
T_2 V_35 , T_2 V_510 ,
T_2 V_477 , T_2 V_478 ,
struct V_66 * V_206 , T_2 V_309 )
{
bool V_511 = false ;
int V_28 ;
V_309 = F_257 ( V_34 , V_309 ) ;
V_75:
F_8 ( V_35 < V_34 -> V_326 ) ;
V_28 = F_357 ( V_115 , V_34 , V_35 , V_477 ,
V_478 , V_206 , V_309 ) ;
if ( V_28 == - V_332 ) {
if ( ! V_511 ) {
V_35 = V_35 >> 1 ;
V_35 = F_368 ( V_35 , V_34 -> V_326 ) ;
V_35 = F_72 ( V_35 , V_510 ) ;
if ( V_35 == V_510 )
V_511 = true ;
goto V_75;
} else if ( F_234 ( V_34 , V_346 ) ) {
struct V_95 * V_335 ;
V_335 = F_66 ( V_34 -> V_36 , V_309 ) ;
F_174 ( V_231 L_23
L_24 , ( unsigned long long ) V_309 ,
( unsigned long long ) V_35 ) ;
if ( V_335 )
F_271 ( V_335 , V_35 , 1 ) ;
}
}
F_369 ( V_34 , V_206 -> V_21 , V_206 -> V_32 ) ;
return V_28 ;
}
static int F_370 ( struct V_33 * V_34 ,
T_2 V_31 , T_2 V_113 , int V_512 )
{
struct V_1 * V_2 ;
int V_28 = 0 ;
V_2 = F_65 ( V_34 -> V_36 , V_31 ) ;
if ( ! V_2 ) {
F_174 ( V_231 L_25 ,
( unsigned long long ) V_31 ) ;
return - V_332 ;
}
if ( F_234 ( V_34 , V_455 ) )
V_28 = F_143 ( V_34 , V_31 , V_113 , NULL ) ;
if ( V_512 )
F_335 ( V_34 , V_2 , V_31 , V_113 , 1 ) ;
else {
F_28 ( V_2 , V_31 , V_113 ) ;
F_338 ( V_2 , V_113 , V_451 ) ;
}
F_6 ( V_2 ) ;
F_371 ( V_34 , V_31 , V_113 ) ;
return V_28 ;
}
int F_372 ( struct V_33 * V_34 ,
T_2 V_31 , T_2 V_113 )
{
return F_370 ( V_34 , V_31 , V_113 , 0 ) ;
}
int F_373 ( struct V_33 * V_34 ,
T_2 V_31 , T_2 V_113 )
{
return F_370 ( V_34 , V_31 , V_113 , 1 ) ;
}
static int F_152 ( struct V_114 * V_115 ,
struct V_33 * V_34 ,
T_2 V_16 , T_2 V_146 ,
T_2 V_6 , T_2 V_104 , T_2 V_32 ,
struct V_66 * V_206 , int V_134 )
{
int V_28 ;
struct V_11 * V_36 = V_34 -> V_36 ;
struct V_120 * V_513 ;
struct V_162 * V_163 ;
struct V_62 * V_63 ;
struct V_64 * V_65 ;
int type ;
T_3 V_55 ;
if ( V_16 > 0 )
type = V_154 ;
else
type = V_155 ;
V_55 = sizeof( * V_513 ) + F_126 ( type ) ;
V_63 = F_32 () ;
if ( ! V_63 )
return - V_84 ;
V_63 -> V_202 = 1 ;
V_28 = F_107 ( V_115 , V_36 -> V_61 , V_63 ,
V_206 , V_55 ) ;
if ( V_28 ) {
F_48 ( V_63 ) ;
return V_28 ;
}
V_65 = V_63 -> V_79 [ 0 ] ;
V_513 = F_79 ( V_65 , V_63 -> V_80 [ 0 ] ,
struct V_120 ) ;
F_91 ( V_65 , V_513 , V_134 ) ;
F_92 ( V_65 , V_513 , V_115 -> V_268 ) ;
F_93 ( V_65 , V_513 ,
V_6 | V_145 ) ;
V_163 = (struct V_162 * ) ( V_513 + 1 ) ;
F_133 ( V_65 , V_163 , type ) ;
if ( V_16 > 0 ) {
struct V_158 * V_151 ;
V_151 = (struct V_158 * ) ( V_163 + 1 ) ;
F_134 ( V_65 , V_163 , V_16 ) ;
F_108 ( V_65 , V_151 , V_134 ) ;
} else {
struct V_150 * V_151 ;
V_151 = (struct V_150 * ) ( & V_163 -> V_32 ) ;
F_110 ( V_65 , V_151 , V_146 ) ;
F_111 ( V_65 , V_151 , V_104 ) ;
F_112 ( V_65 , V_151 , V_32 ) ;
F_113 ( V_65 , V_151 , V_134 ) ;
}
F_96 ( V_63 -> V_79 [ 0 ] ) ;
F_48 ( V_63 ) ;
V_28 = F_330 ( V_34 , V_206 -> V_21 , V_206 -> V_32 , 1 ) ;
if ( V_28 ) {
F_174 ( V_231 L_26
L_27 , ( unsigned long long ) V_206 -> V_21 ,
( unsigned long long ) V_206 -> V_32 ) ;
F_84 () ;
}
return V_28 ;
}
static int F_158 ( struct V_114 * V_115 ,
struct V_33 * V_34 ,
T_2 V_16 , T_2 V_146 ,
T_2 V_6 , struct V_437 * V_20 ,
int V_166 , struct V_66 * V_206 )
{
int V_28 ;
struct V_11 * V_36 = V_34 -> V_36 ;
struct V_120 * V_513 ;
struct V_138 * V_514 ;
struct V_162 * V_163 ;
struct V_62 * V_63 ;
struct V_64 * V_65 ;
T_3 V_55 = sizeof( * V_513 ) + sizeof( * V_514 ) + sizeof( * V_163 ) ;
V_63 = F_32 () ;
if ( ! V_63 )
return - V_84 ;
V_63 -> V_202 = 1 ;
V_28 = F_107 ( V_115 , V_36 -> V_61 , V_63 ,
V_206 , V_55 ) ;
if ( V_28 ) {
F_48 ( V_63 ) ;
return V_28 ;
}
V_65 = V_63 -> V_79 [ 0 ] ;
V_513 = F_79 ( V_65 , V_63 -> V_80 [ 0 ] ,
struct V_120 ) ;
F_91 ( V_65 , V_513 , 1 ) ;
F_92 ( V_65 , V_513 , V_115 -> V_268 ) ;
F_93 ( V_65 , V_513 ,
V_6 | V_144 ) ;
V_514 = (struct V_138 * ) ( V_513 + 1 ) ;
F_154 ( V_65 , V_514 , V_20 ) ;
F_95 ( V_65 , V_514 , V_166 ) ;
V_163 = (struct V_162 * ) ( V_514 + 1 ) ;
if ( V_16 > 0 ) {
F_29 ( ! ( V_6 & V_128 ) ) ;
F_133 ( V_65 , V_163 ,
V_164 ) ;
F_134 ( V_65 , V_163 , V_16 ) ;
} else {
F_133 ( V_65 , V_163 ,
V_165 ) ;
F_134 ( V_65 , V_163 , V_146 ) ;
}
F_96 ( V_65 ) ;
F_48 ( V_63 ) ;
V_28 = F_330 ( V_34 , V_206 -> V_21 , V_206 -> V_32 , 1 ) ;
if ( V_28 ) {
F_174 ( V_231 L_26
L_27 , ( unsigned long long ) V_206 -> V_21 ,
( unsigned long long ) V_206 -> V_32 ) ;
F_84 () ;
}
return V_28 ;
}
int F_374 ( struct V_114 * V_115 ,
struct V_33 * V_34 ,
T_2 V_146 , T_2 V_104 ,
T_2 V_32 , struct V_66 * V_206 )
{
int V_28 ;
F_29 ( V_146 == V_200 ) ;
V_28 = F_147 ( V_34 -> V_36 , V_115 , V_206 -> V_21 ,
V_206 -> V_32 , 0 ,
V_146 , V_104 , V_32 ,
V_222 , NULL , 0 ) ;
return V_28 ;
}
int F_375 ( struct V_114 * V_115 ,
struct V_33 * V_34 ,
T_2 V_146 , T_2 V_104 , T_2 V_32 ,
struct V_66 * V_206 )
{
int V_28 ;
struct V_1 * V_13 ;
struct V_48 * V_52 ;
T_2 V_31 = V_206 -> V_21 ;
T_2 V_35 = V_206 -> V_32 ;
V_13 = F_65 ( V_34 -> V_36 , V_206 -> V_21 ) ;
F_49 ( V_13 , 0 ) ;
V_52 = F_24 ( V_13 ) ;
if ( ! V_52 ) {
F_29 ( ! F_1 ( V_13 ) ) ;
V_28 = F_337 ( V_13 , V_31 , V_35 ) ;
F_29 ( V_28 ) ;
} else {
F_34 ( & V_52 -> V_76 ) ;
if ( V_31 >= V_52 -> V_81 ) {
V_28 = F_17 ( V_34 , V_31 , V_35 ) ;
F_29 ( V_28 ) ;
} else if ( V_31 + V_35 <= V_52 -> V_81 ) {
V_28 = F_337 ( V_13 ,
V_31 , V_35 ) ;
F_29 ( V_28 ) ;
} else {
V_35 = V_52 -> V_81 - V_31 ;
V_28 = F_337 ( V_13 ,
V_31 , V_35 ) ;
F_29 ( V_28 ) ;
V_31 = V_52 -> V_81 ;
V_35 = V_206 -> V_21 + V_206 -> V_32 -
V_52 -> V_81 ;
V_28 = F_17 ( V_34 , V_31 , V_35 ) ;
F_29 ( V_28 ) ;
}
F_45 ( & V_52 -> V_76 ) ;
F_25 ( V_52 ) ;
}
V_28 = F_338 ( V_13 , V_206 -> V_32 ,
V_486 ) ;
F_29 ( V_28 ) ;
F_6 ( V_13 ) ;
V_28 = F_152 ( V_115 , V_34 , 0 , V_146 ,
0 , V_104 , V_32 , V_206 , 1 ) ;
return V_28 ;
}
struct V_64 * F_376 ( struct V_114 * V_115 ,
struct V_33 * V_34 ,
T_2 V_26 , T_3 V_515 ,
int V_166 )
{
struct V_64 * V_250 ;
V_250 = F_377 ( V_34 , V_26 , V_515 ) ;
if ( ! V_250 )
return F_378 ( - V_84 ) ;
F_379 ( V_250 , V_115 -> V_268 ) ;
F_380 ( V_34 -> V_246 . V_21 , V_250 , V_166 ) ;
F_381 ( V_250 ) ;
F_382 ( V_115 , V_34 , V_250 ) ;
F_351 ( V_516 , & V_250 -> V_465 ) ;
F_383 ( V_250 ) ;
F_384 ( V_250 ) ;
if ( V_34 -> V_246 . V_21 == V_200 ) {
if ( V_34 -> V_517 % 2 == 0 )
F_334 ( & V_34 -> V_518 , V_250 -> V_31 ,
V_250 -> V_31 + V_250 -> V_113 - 1 , V_39 ) ;
else
F_385 ( & V_34 -> V_518 , V_250 -> V_31 ,
V_250 -> V_31 + V_250 -> V_113 - 1 , V_39 ) ;
} else {
F_334 ( & V_115 -> V_129 -> V_519 , V_250 -> V_31 ,
V_250 -> V_31 + V_250 -> V_113 - 1 , V_39 ) ;
}
V_115 -> V_520 ++ ;
return V_250 ;
}
static struct V_337 *
F_386 ( struct V_114 * V_115 ,
struct V_33 * V_34 , T_3 V_515 )
{
struct V_337 * V_369 ;
struct V_337 * V_338 = & V_34 -> V_36 -> V_339 ;
int V_28 ;
V_369 = F_292 ( V_115 , V_34 ) ;
if ( V_369 -> V_55 == 0 ) {
V_28 = F_287 ( V_34 , V_369 , V_515 ,
V_379 ) ;
if ( V_28 && V_369 != V_338 ) {
V_28 = F_290 ( V_338 , V_515 ) ;
if ( ! V_28 )
return V_338 ;
return F_378 ( V_28 ) ;
} else if ( V_28 ) {
return F_378 ( V_28 ) ;
}
return V_369 ;
}
V_28 = F_290 ( V_369 , V_515 ) ;
if ( ! V_28 )
return V_369 ;
if ( V_28 && ! V_369 -> V_521 ) {
if ( F_234 ( V_34 , V_346 ) ) {
static F_387 ( V_522 ,
V_523 * 10 ,
1 ) ;
if ( F_388 ( & V_522 ) )
F_389 ( 1 , V_219
L_28 , V_28 ) ;
}
V_28 = F_287 ( V_34 , V_369 , V_515 ,
V_379 ) ;
if ( ! V_28 ) {
return V_369 ;
} else if ( V_28 && V_369 != V_338 ) {
V_28 = F_290 ( V_338 , V_515 ) ;
if ( ! V_28 )
return V_338 ;
}
}
return F_378 ( - V_332 ) ;
}
static void F_390 ( struct V_11 * V_36 ,
struct V_337 * V_369 , T_3 V_515 )
{
F_293 ( V_369 , V_515 , 0 ) ;
F_294 ( V_36 , V_369 , NULL , 0 ) ;
}
struct V_64 * F_391 ( struct V_114 * V_115 ,
struct V_33 * V_34 , T_3 V_515 ,
T_2 V_16 , T_2 V_146 ,
struct V_437 * V_20 , int V_166 ,
T_2 V_524 , T_2 V_477 )
{
struct V_66 V_206 ;
struct V_337 * V_369 ;
struct V_64 * V_250 ;
T_2 V_6 = 0 ;
int V_28 ;
V_369 = F_386 ( V_115 , V_34 , V_515 ) ;
if ( F_227 ( V_369 ) )
return F_392 ( V_369 ) ;
V_28 = F_367 ( V_115 , V_34 , V_515 , V_515 ,
V_477 , V_524 , & V_206 , 0 ) ;
if ( V_28 ) {
F_390 ( V_34 -> V_36 , V_369 , V_515 ) ;
return F_378 ( V_28 ) ;
}
V_250 = F_376 ( V_115 , V_34 , V_206 . V_21 ,
V_515 , V_166 ) ;
F_29 ( F_227 ( V_250 ) ) ;
if ( V_146 == V_525 ) {
if ( V_16 == 0 )
V_16 = V_206 . V_21 ;
V_6 |= V_128 ;
} else
F_29 ( V_16 > 0 ) ;
if ( V_146 != V_200 ) {
struct V_178 * V_131 ;
V_131 = F_200 () ;
F_29 ( ! V_131 ) ;
if ( V_20 )
memcpy ( & V_131 -> V_20 , V_20 , sizeof( V_131 -> V_20 ) ) ;
else
memset ( & V_131 -> V_20 , 0 , sizeof( V_131 -> V_20 ) ) ;
V_131 -> V_133 = V_6 ;
V_131 -> V_209 = 1 ;
V_131 -> V_132 = 1 ;
V_131 -> V_182 = 0 ;
V_28 = F_146 ( V_34 -> V_36 , V_115 ,
V_206 . V_21 ,
V_206 . V_32 , V_16 , V_146 ,
V_166 , V_222 ,
V_131 , 0 ) ;
F_29 ( V_28 ) ;
}
return V_250 ;
}
static T_1 void F_393 ( struct V_114 * V_115 ,
struct V_33 * V_34 ,
struct V_526 * V_527 ,
struct V_62 * V_63 )
{
T_2 V_26 ;
T_2 V_271 ;
T_2 V_116 ;
T_2 V_6 ;
T_3 V_69 ;
T_3 V_515 ;
struct V_66 V_20 ;
struct V_64 * V_528 ;
int V_28 ;
int V_529 ;
int V_530 = 0 ;
if ( V_63 -> V_80 [ V_527 -> V_166 ] < V_527 -> V_531 ) {
V_527 -> V_532 = V_527 -> V_532 * 2 / 3 ;
V_527 -> V_532 = F_72 ( V_527 -> V_532 , 2 ) ;
} else {
V_527 -> V_532 = V_527 -> V_532 * 3 / 2 ;
V_527 -> V_532 = F_193 ( int , V_527 -> V_532 ,
F_394 ( V_34 ) ) ;
}
V_528 = V_63 -> V_79 [ V_527 -> V_166 ] ;
V_69 = F_37 ( V_528 ) ;
V_515 = F_218 ( V_34 , V_527 -> V_166 - 1 ) ;
for ( V_529 = V_63 -> V_80 [ V_527 -> V_166 ] ; V_529 < V_69 ; V_529 ++ ) {
if ( V_530 >= V_527 -> V_532 )
break;
F_46 () ;
V_26 = F_217 ( V_528 , V_529 ) ;
V_271 = F_395 ( V_528 , V_529 ) ;
if ( V_529 == V_63 -> V_80 [ V_527 -> V_166 ] )
goto V_73;
if ( V_527 -> V_533 == V_534 &&
V_271 <= V_34 -> V_246 . V_32 )
continue;
V_28 = F_77 ( V_115 , V_34 , V_26 , V_515 ,
& V_116 , & V_6 ) ;
if ( V_28 < 0 )
continue;
F_29 ( V_116 == 0 ) ;
if ( V_527 -> V_533 == V_535 ) {
if ( V_116 == 1 )
goto V_73;
if ( V_527 -> V_166 == 1 &&
( V_6 & V_128 ) )
continue;
if ( ! V_527 -> V_536 ||
V_271 <= V_34 -> V_246 . V_32 )
continue;
F_124 ( V_528 , & V_20 , V_529 ) ;
V_28 = F_396 ( & V_20 ,
& V_527 -> V_537 ) ;
if ( V_28 < 0 )
continue;
} else {
if ( V_527 -> V_166 == 1 &&
( V_6 & V_128 ) )
continue;
}
V_73:
V_28 = F_397 ( V_34 , V_26 , V_515 ,
V_271 ) ;
if ( V_28 )
break;
V_530 ++ ;
}
V_527 -> V_531 = V_529 ;
}
static T_1 int F_398 ( struct V_114 * V_115 ,
struct V_33 * V_34 ,
struct V_62 * V_63 ,
struct V_526 * V_527 , int V_538 )
{
int V_166 = V_527 -> V_166 ;
struct V_64 * V_528 = V_63 -> V_79 [ V_166 ] ;
T_2 V_539 = V_128 ;
int V_28 ;
if ( V_527 -> V_533 == V_534 &&
F_210 ( V_528 ) != V_34 -> V_246 . V_21 )
return 1 ;
if ( V_538 &&
( ( V_527 -> V_533 == V_535 && V_527 -> V_116 [ V_166 ] != 1 ) ||
( V_527 -> V_533 == V_534 && ! ( V_527 -> V_6 [ V_166 ] & V_539 ) ) ) ) {
F_29 ( ! V_63 -> V_540 [ V_166 ] ) ;
V_28 = F_77 ( V_115 , V_34 ,
V_528 -> V_31 , V_528 -> V_113 ,
& V_527 -> V_116 [ V_166 ] ,
& V_527 -> V_6 [ V_166 ] ) ;
F_29 ( V_28 == - V_84 ) ;
if ( V_28 )
return V_28 ;
F_29 ( V_527 -> V_116 [ V_166 ] == 0 ) ;
}
if ( V_527 -> V_533 == V_535 ) {
if ( V_527 -> V_116 [ V_166 ] > 1 )
return 1 ;
if ( V_63 -> V_540 [ V_166 ] && ! V_527 -> V_172 ) {
F_399 ( V_528 , V_63 -> V_540 [ V_166 ] ) ;
V_63 -> V_540 [ V_166 ] = 0 ;
}
return 0 ;
}
if ( ! ( V_527 -> V_6 [ V_166 ] & V_539 ) ) {
F_29 ( ! V_63 -> V_540 [ V_166 ] ) ;
V_28 = F_219 ( V_115 , V_34 , V_528 , 1 , V_527 -> V_541 ) ;
F_29 ( V_28 ) ;
V_28 = F_220 ( V_115 , V_34 , V_528 , 0 , V_527 -> V_541 ) ;
F_29 ( V_28 ) ;
V_28 = F_199 ( V_115 , V_34 , V_528 -> V_31 ,
V_528 -> V_113 , V_539 , 0 ) ;
F_29 ( V_28 ) ;
V_527 -> V_6 [ V_166 ] |= V_539 ;
}
if ( V_63 -> V_540 [ V_166 ] && V_166 > 0 ) {
F_399 ( V_528 , V_63 -> V_540 [ V_166 ] ) ;
V_63 -> V_540 [ V_166 ] = 0 ;
}
return 0 ;
}
static T_1 int F_400 ( struct V_114 * V_115 ,
struct V_33 * V_34 ,
struct V_62 * V_63 ,
struct V_526 * V_527 , int * V_538 )
{
T_2 V_26 ;
T_2 V_271 ;
T_2 V_16 ;
T_3 V_515 ;
struct V_66 V_20 ;
struct V_64 * V_216 ;
int V_166 = V_527 -> V_166 ;
int V_73 = 0 ;
int V_28 = 0 ;
V_271 = F_395 ( V_63 -> V_79 [ V_166 ] ,
V_63 -> V_80 [ V_166 ] ) ;
if ( V_527 -> V_533 == V_534 &&
V_271 <= V_34 -> V_246 . V_32 ) {
* V_538 = 1 ;
return 1 ;
}
V_26 = F_217 ( V_63 -> V_79 [ V_166 ] , V_63 -> V_80 [ V_166 ] ) ;
V_515 = F_218 ( V_34 , V_166 - 1 ) ;
V_216 = F_401 ( V_34 , V_26 , V_515 ) ;
if ( ! V_216 ) {
V_216 = F_377 ( V_34 , V_26 , V_515 ) ;
if ( ! V_216 )
return - V_84 ;
V_73 = 1 ;
}
F_381 ( V_216 ) ;
F_383 ( V_216 ) ;
V_28 = F_77 ( V_115 , V_34 , V_26 , V_515 ,
& V_527 -> V_116 [ V_166 - 1 ] ,
& V_527 -> V_6 [ V_166 - 1 ] ) ;
if ( V_28 < 0 ) {
F_402 ( V_216 ) ;
return V_28 ;
}
F_29 ( V_527 -> V_116 [ V_166 - 1 ] == 0 ) ;
* V_538 = 0 ;
if ( V_527 -> V_533 == V_535 ) {
if ( V_527 -> V_116 [ V_166 - 1 ] > 1 ) {
if ( V_166 == 1 &&
( V_527 -> V_6 [ 0 ] & V_128 ) )
goto V_542;
if ( ! V_527 -> V_536 ||
V_271 <= V_34 -> V_246 . V_32 )
goto V_542;
F_124 ( V_63 -> V_79 [ V_166 ] , & V_20 ,
V_63 -> V_80 [ V_166 ] ) ;
V_28 = F_396 ( & V_20 , & V_527 -> V_537 ) ;
if ( V_28 < 0 )
goto V_542;
V_527 -> V_533 = V_534 ;
V_527 -> V_543 = V_166 - 1 ;
}
} else {
if ( V_166 == 1 &&
( V_527 -> V_6 [ 0 ] & V_128 ) )
goto V_542;
}
if ( ! F_403 ( V_216 , V_271 , 0 ) ) {
F_402 ( V_216 ) ;
F_404 ( V_216 ) ;
V_216 = NULL ;
* V_538 = 1 ;
}
if ( ! V_216 ) {
if ( V_73 && V_166 == 1 )
F_393 ( V_115 , V_34 , V_527 , V_63 ) ;
V_216 = F_405 ( V_34 , V_26 , V_515 , V_271 ) ;
if ( ! V_216 )
return - V_173 ;
F_381 ( V_216 ) ;
F_383 ( V_216 ) ;
}
V_166 -- ;
F_29 ( V_166 != F_211 ( V_216 ) ) ;
V_63 -> V_79 [ V_166 ] = V_216 ;
V_63 -> V_80 [ V_166 ] = 0 ;
V_63 -> V_540 [ V_166 ] = V_544 ;
V_527 -> V_166 = V_166 ;
if ( V_527 -> V_166 == 1 )
V_527 -> V_531 = 0 ;
return 0 ;
V_542:
V_527 -> V_116 [ V_166 - 1 ] = 0 ;
V_527 -> V_6 [ V_166 - 1 ] = 0 ;
if ( V_527 -> V_533 == V_535 ) {
if ( V_527 -> V_6 [ V_166 ] & V_128 ) {
V_16 = V_63 -> V_79 [ V_166 ] -> V_31 ;
} else {
F_29 ( V_34 -> V_246 . V_21 !=
F_210 ( V_63 -> V_79 [ V_166 ] ) ) ;
V_16 = 0 ;
}
V_28 = V_256 ( V_115 , V_34 , V_26 , V_515 , V_16 ,
V_34 -> V_246 . V_21 , V_166 - 1 , 0 , 0 ) ;
F_29 ( V_28 ) ;
}
F_402 ( V_216 ) ;
F_404 ( V_216 ) ;
* V_538 = 1 ;
return 1 ;
}
static T_1 int F_406 ( struct V_114 * V_115 ,
struct V_33 * V_34 ,
struct V_62 * V_63 ,
struct V_526 * V_527 )
{
int V_28 ;
int V_166 = V_527 -> V_166 ;
struct V_64 * V_528 = V_63 -> V_79 [ V_166 ] ;
T_2 V_16 = 0 ;
if ( V_527 -> V_533 == V_534 ) {
F_29 ( V_527 -> V_543 < V_166 ) ;
if ( V_166 < V_527 -> V_543 )
goto V_70;
V_28 = F_40 ( V_63 , V_166 + 1 , & V_527 -> V_537 ) ;
if ( V_28 > 0 )
V_527 -> V_536 = 0 ;
V_527 -> V_533 = V_535 ;
V_527 -> V_543 = - 1 ;
V_63 -> V_80 [ V_166 ] = 0 ;
if ( ! V_63 -> V_540 [ V_166 ] ) {
F_29 ( V_166 == 0 ) ;
F_381 ( V_528 ) ;
F_383 ( V_528 ) ;
V_63 -> V_540 [ V_166 ] = V_544 ;
V_28 = F_77 ( V_115 , V_34 ,
V_528 -> V_31 , V_528 -> V_113 ,
& V_527 -> V_116 [ V_166 ] ,
& V_527 -> V_6 [ V_166 ] ) ;
if ( V_28 < 0 ) {
F_399 ( V_528 , V_63 -> V_540 [ V_166 ] ) ;
V_63 -> V_540 [ V_166 ] = 0 ;
return V_28 ;
}
F_29 ( V_527 -> V_116 [ V_166 ] == 0 ) ;
if ( V_527 -> V_116 [ V_166 ] == 1 ) {
F_399 ( V_528 , V_63 -> V_540 [ V_166 ] ) ;
V_63 -> V_540 [ V_166 ] = 0 ;
return 1 ;
}
}
}
F_29 ( V_527 -> V_116 [ V_166 ] > 1 && ! V_63 -> V_540 [ V_166 ] ) ;
if ( V_527 -> V_116 [ V_166 ] == 1 ) {
if ( V_166 == 0 ) {
if ( V_527 -> V_6 [ V_166 ] & V_128 )
V_28 = F_220 ( V_115 , V_34 , V_528 , 1 ,
V_527 -> V_541 ) ;
else
V_28 = F_220 ( V_115 , V_34 , V_528 , 0 ,
V_527 -> V_541 ) ;
F_29 ( V_28 ) ;
}
if ( ! V_63 -> V_540 [ V_166 ] &&
F_349 ( V_528 ) == V_115 -> V_268 ) {
F_381 ( V_528 ) ;
F_383 ( V_528 ) ;
V_63 -> V_540 [ V_166 ] = V_544 ;
}
F_382 ( V_115 , V_34 , V_528 ) ;
}
if ( V_528 == V_34 -> V_130 ) {
if ( V_527 -> V_6 [ V_166 ] & V_128 )
V_16 = V_528 -> V_31 ;
else
F_29 ( V_34 -> V_246 . V_21 !=
F_210 ( V_528 ) ) ;
} else {
if ( V_527 -> V_6 [ V_166 + 1 ] & V_128 )
V_16 = V_63 -> V_79 [ V_166 + 1 ] -> V_31 ;
else
F_29 ( V_34 -> V_246 . V_21 !=
F_210 ( V_63 -> V_79 [ V_166 + 1 ] ) ) ;
}
F_348 ( V_115 , V_34 , V_528 , V_16 , V_527 -> V_116 [ V_166 ] == 1 ) ;
V_70:
V_527 -> V_116 [ V_166 ] = 0 ;
V_527 -> V_6 [ V_166 ] = 0 ;
return 0 ;
}
static T_1 int F_407 ( struct V_114 * V_115 ,
struct V_33 * V_34 ,
struct V_62 * V_63 ,
struct V_526 * V_527 )
{
int V_166 = V_527 -> V_166 ;
int V_538 = 1 ;
int V_28 ;
while ( V_166 >= 0 ) {
V_28 = F_398 ( V_115 , V_34 , V_63 , V_527 , V_538 ) ;
if ( V_28 > 0 )
break;
if ( V_166 == 0 )
break;
if ( V_63 -> V_80 [ V_166 ] >=
F_37 ( V_63 -> V_79 [ V_166 ] ) )
break;
V_28 = F_400 ( V_115 , V_34 , V_63 , V_527 , & V_538 ) ;
if ( V_28 > 0 ) {
V_63 -> V_80 [ V_166 ] ++ ;
continue;
} else if ( V_28 < 0 )
return V_28 ;
V_166 = V_527 -> V_166 ;
}
return 0 ;
}
static T_1 int F_408 ( struct V_114 * V_115 ,
struct V_33 * V_34 ,
struct V_62 * V_63 ,
struct V_526 * V_527 , int V_545 )
{
int V_166 = V_527 -> V_166 ;
int V_28 ;
V_63 -> V_80 [ V_166 ] = F_37 ( V_63 -> V_79 [ V_166 ] ) ;
while ( V_166 < V_545 && V_63 -> V_79 [ V_166 ] ) {
V_527 -> V_166 = V_166 ;
if ( V_63 -> V_80 [ V_166 ] + 1 <
F_37 ( V_63 -> V_79 [ V_166 ] ) ) {
V_63 -> V_80 [ V_166 ] ++ ;
return 0 ;
} else {
V_28 = F_406 ( V_115 , V_34 , V_63 , V_527 ) ;
if ( V_28 > 0 )
return 0 ;
if ( V_63 -> V_540 [ V_166 ] ) {
F_399 ( V_63 -> V_79 [ V_166 ] ,
V_63 -> V_540 [ V_166 ] ) ;
V_63 -> V_540 [ V_166 ] = 0 ;
}
F_404 ( V_63 -> V_79 [ V_166 ] ) ;
V_63 -> V_79 [ V_166 ] = NULL ;
V_166 ++ ;
}
}
return 1 ;
}
int F_409 ( struct V_33 * V_34 ,
struct V_337 * V_369 , int V_536 ,
int V_541 )
{
struct V_62 * V_63 ;
struct V_114 * V_115 ;
struct V_33 * V_238 = V_34 -> V_36 -> V_238 ;
struct V_546 * V_247 = & V_34 -> V_247 ;
struct V_526 * V_527 ;
struct V_66 V_20 ;
int V_78 = 0 ;
int V_28 ;
int V_166 ;
V_63 = F_32 () ;
if ( ! V_63 ) {
V_78 = - V_84 ;
goto V_70;
}
V_527 = F_51 ( sizeof( * V_527 ) , V_39 ) ;
if ( ! V_527 ) {
F_48 ( V_63 ) ;
V_78 = - V_84 ;
goto V_70;
}
V_115 = F_410 ( V_238 , 0 ) ;
if ( F_227 ( V_115 ) ) {
V_78 = F_228 ( V_115 ) ;
goto V_125;
}
if ( V_369 )
V_115 -> V_369 = V_369 ;
if ( F_411 ( & V_247 -> V_547 ) == 0 ) {
V_166 = F_211 ( V_34 -> V_130 ) ;
V_63 -> V_79 [ V_166 ] = F_412 ( V_34 ) ;
F_383 ( V_63 -> V_79 [ V_166 ] ) ;
V_63 -> V_80 [ V_166 ] = 0 ;
V_63 -> V_540 [ V_166 ] = V_544 ;
memset ( & V_527 -> V_537 , 0 ,
sizeof( V_527 -> V_537 ) ) ;
} else {
F_413 ( & V_20 , & V_247 -> V_547 ) ;
memcpy ( & V_527 -> V_537 , & V_20 ,
sizeof( V_527 -> V_537 ) ) ;
V_166 = V_247 -> V_548 ;
F_29 ( V_166 == 0 ) ;
V_63 -> V_549 = V_166 ;
V_28 = F_36 ( NULL , V_34 , & V_20 , V_63 , 0 , 0 ) ;
V_63 -> V_549 = 0 ;
if ( V_28 < 0 ) {
V_78 = V_28 ;
goto V_550;
}
F_8 ( V_28 > 0 ) ;
F_129 ( V_63 , 0 ) ;
V_166 = F_211 ( V_34 -> V_130 ) ;
while ( 1 ) {
F_381 ( V_63 -> V_79 [ V_166 ] ) ;
F_383 ( V_63 -> V_79 [ V_166 ] ) ;
V_28 = F_77 ( V_115 , V_34 ,
V_63 -> V_79 [ V_166 ] -> V_31 ,
V_63 -> V_79 [ V_166 ] -> V_113 ,
& V_527 -> V_116 [ V_166 ] ,
& V_527 -> V_6 [ V_166 ] ) ;
if ( V_28 < 0 ) {
V_78 = V_28 ;
goto V_550;
}
F_29 ( V_527 -> V_116 [ V_166 ] == 0 ) ;
if ( V_166 == V_247 -> V_548 )
break;
F_402 ( V_63 -> V_79 [ V_166 ] ) ;
F_8 ( V_527 -> V_116 [ V_166 ] != 1 ) ;
V_166 -- ;
}
}
V_527 -> V_166 = V_166 ;
V_527 -> V_543 = - 1 ;
V_527 -> V_533 = V_535 ;
V_527 -> V_536 = V_536 ;
V_527 -> V_172 = 0 ;
V_527 -> V_541 = V_541 ;
V_527 -> V_532 = F_394 ( V_34 ) ;
while ( 1 ) {
V_28 = F_407 ( V_115 , V_34 , V_63 , V_527 ) ;
if ( V_28 < 0 ) {
V_78 = V_28 ;
break;
}
V_28 = F_408 ( V_115 , V_34 , V_63 , V_527 , V_167 ) ;
if ( V_28 < 0 ) {
V_78 = V_28 ;
break;
}
if ( V_28 > 0 ) {
F_29 ( V_527 -> V_533 != V_535 ) ;
break;
}
if ( V_527 -> V_533 == V_535 ) {
V_166 = V_527 -> V_166 ;
F_414 ( V_63 -> V_79 [ V_166 ] ,
& V_247 -> V_547 ,
V_63 -> V_80 [ V_166 ] ) ;
V_247 -> V_548 = V_166 ;
}
F_29 ( V_527 -> V_166 == 0 ) ;
if ( F_415 ( V_115 , V_238 ) ) {
V_28 = F_416 ( V_115 , V_238 ,
& V_34 -> V_246 ,
V_247 ) ;
if ( V_28 ) {
F_149 ( V_115 , V_238 , V_28 ) ;
V_78 = V_28 ;
goto V_550;
}
F_417 ( V_115 , V_238 ) ;
V_115 = F_410 ( V_238 , 0 ) ;
if ( F_227 ( V_115 ) ) {
V_78 = F_228 ( V_115 ) ;
goto V_125;
}
if ( V_369 )
V_115 -> V_369 = V_369 ;
}
}
F_43 ( V_63 ) ;
if ( V_78 )
goto V_550;
V_28 = F_418 ( V_115 , V_238 , & V_34 -> V_246 ) ;
if ( V_28 ) {
F_149 ( V_115 , V_238 , V_28 ) ;
goto V_550;
}
if ( V_34 -> V_246 . V_21 != V_525 ) {
V_28 = F_419 ( V_238 , V_34 -> V_246 . V_21 ,
NULL , NULL ) ;
if ( V_28 < 0 ) {
F_149 ( V_115 , V_238 , V_28 ) ;
V_78 = V_28 ;
goto V_550;
} else if ( V_28 > 0 ) {
F_420 ( V_115 , V_238 ,
V_34 -> V_246 . V_21 ) ;
}
}
if ( V_34 -> V_551 ) {
F_421 ( V_238 -> V_36 , V_34 ) ;
} else {
F_404 ( V_34 -> V_130 ) ;
F_404 ( V_34 -> V_552 ) ;
F_9 ( V_34 ) ;
}
V_550:
F_417 ( V_115 , V_238 ) ;
V_125:
F_9 ( V_527 ) ;
F_48 ( V_63 ) ;
V_70:
if ( V_78 )
F_422 ( V_34 -> V_36 , V_78 ) ;
return V_78 ;
}
int F_423 ( struct V_114 * V_115 ,
struct V_33 * V_34 ,
struct V_64 * V_130 ,
struct V_64 * V_16 )
{
struct V_62 * V_63 ;
struct V_526 * V_527 ;
int V_166 ;
int V_553 ;
int V_28 = 0 ;
int V_554 ;
F_29 ( V_34 -> V_246 . V_21 != V_525 ) ;
V_63 = F_32 () ;
if ( ! V_63 )
return - V_84 ;
V_527 = F_51 ( sizeof( * V_527 ) , V_39 ) ;
if ( ! V_527 ) {
F_48 ( V_63 ) ;
return - V_84 ;
}
F_424 ( V_16 ) ;
V_553 = F_211 ( V_16 ) ;
F_425 ( V_16 ) ;
V_63 -> V_79 [ V_553 ] = V_16 ;
V_63 -> V_80 [ V_553 ] = F_37 ( V_16 ) ;
F_424 ( V_130 ) ;
V_166 = F_211 ( V_130 ) ;
V_63 -> V_79 [ V_166 ] = V_130 ;
V_63 -> V_80 [ V_166 ] = 0 ;
V_63 -> V_540 [ V_166 ] = V_544 ;
V_527 -> V_116 [ V_553 ] = 1 ;
V_527 -> V_6 [ V_553 ] = V_128 ;
V_527 -> V_166 = V_166 ;
V_527 -> V_543 = - 1 ;
V_527 -> V_533 = V_535 ;
V_527 -> V_536 = 0 ;
V_527 -> V_172 = 1 ;
V_527 -> V_541 = 1 ;
V_527 -> V_532 = F_394 ( V_34 ) ;
while ( 1 ) {
V_554 = F_407 ( V_115 , V_34 , V_63 , V_527 ) ;
if ( V_554 < 0 ) {
V_28 = V_554 ;
break;
}
V_554 = F_408 ( V_115 , V_34 , V_63 , V_527 , V_553 ) ;
if ( V_554 < 0 )
V_28 = V_554 ;
if ( V_554 != 0 )
break;
}
F_9 ( V_527 ) ;
F_48 ( V_63 ) ;
return V_28 ;
}
static T_2 F_426 ( struct V_33 * V_34 , T_2 V_6 )
{
T_2 V_313 ;
T_2 V_555 ;
V_555 = F_251 ( V_34 -> V_36 , V_6 ) ;
if ( V_555 )
return F_253 ( V_555 ) ;
V_313 = V_34 -> V_36 -> V_314 -> V_315 +
V_34 -> V_36 -> V_314 -> V_316 ;
V_555 = V_319 |
V_320 | V_321 |
V_281 | V_282 ;
if ( V_313 == 1 ) {
V_555 |= V_280 ;
V_555 = V_6 & ~ V_555 ;
if ( V_6 & V_319 )
return V_555 ;
if ( V_6 & ( V_281 |
V_282 ) )
return V_555 | V_280 ;
} else {
if ( V_6 & V_555 )
return V_6 ;
V_555 |= V_280 ;
V_555 = V_6 & ~ V_555 ;
if ( V_6 & V_280 )
return V_555 | V_281 ;
}
return V_6 ;
}
static int F_427 ( struct V_1 * V_2 , int V_336 )
{
struct V_95 * V_335 = V_2 -> V_98 ;
T_2 V_35 ;
T_2 V_556 ;
int V_28 = - V_332 ;
if ( ( V_335 -> V_6 &
( V_303 | V_112 ) ) &&
! V_336 )
V_556 = 1 * 1024 * 1024 ;
else
V_556 = 0 ;
F_11 ( & V_335 -> V_50 ) ;
F_11 ( & V_2 -> V_50 ) ;
if ( V_2 -> V_111 ) {
V_28 = 0 ;
goto V_70;
}
V_35 = V_2 -> V_20 . V_32 - V_2 -> V_9 - V_2 -> V_8 -
V_2 -> V_45 - F_73 ( & V_2 -> V_110 ) ;
if ( V_335 -> V_279 + V_335 -> V_289 + V_335 -> V_288 +
V_335 -> V_291 + V_335 -> V_290 + V_35 +
V_556 <= V_335 -> V_278 ) {
V_335 -> V_290 += V_35 ;
V_2 -> V_111 = 1 ;
V_28 = 0 ;
}
V_70:
F_13 ( & V_2 -> V_50 ) ;
F_13 ( & V_335 -> V_50 ) ;
return V_28 ;
}
int F_428 ( struct V_33 * V_34 ,
struct V_1 * V_2 )
{
struct V_114 * V_115 ;
T_2 V_557 ;
int V_28 ;
F_29 ( V_2 -> V_111 ) ;
V_115 = F_259 ( V_34 ) ;
if ( F_227 ( V_115 ) )
return F_228 ( V_115 ) ;
V_557 = F_426 ( V_34 , V_2 -> V_6 ) ;
if ( V_557 != V_2 -> V_6 ) {
V_28 = F_260 ( V_115 , V_34 , V_557 ,
V_331 ) ;
if ( V_28 < 0 )
goto V_70;
}
V_28 = F_427 ( V_2 , 0 ) ;
if ( ! V_28 )
goto V_70;
V_557 = F_254 ( V_34 , V_2 -> V_98 -> V_6 ) ;
V_28 = F_260 ( V_115 , V_34 , V_557 ,
V_331 ) ;
if ( V_28 < 0 )
goto V_70;
V_28 = F_427 ( V_2 , 0 ) ;
V_70:
F_261 ( V_115 , V_34 ) ;
return V_28 ;
}
int F_429 ( struct V_114 * V_115 ,
struct V_33 * V_34 , T_2 type )
{
T_2 V_557 = F_254 ( V_34 , type ) ;
return F_260 ( V_115 , V_34 , V_557 ,
V_331 ) ;
}
static T_2 F_430 ( struct V_96 * V_558 )
{
struct V_1 * V_13 ;
T_2 V_559 = 0 ;
int V_108 ;
F_359 (block_group, groups_list, list) {
F_11 ( & V_13 -> V_50 ) ;
if ( ! V_13 -> V_111 ) {
F_13 ( & V_13 -> V_50 ) ;
continue;
}
if ( V_13 -> V_6 & ( V_281 |
V_282 |
V_280 ) )
V_108 = 2 ;
else
V_108 = 1 ;
V_559 += ( V_13 -> V_20 . V_32 -
F_73 ( & V_13 -> V_110 ) ) *
V_108 ;
F_13 ( & V_13 -> V_50 ) ;
}
return V_559 ;
}
T_2 F_431 ( struct V_95 * V_335 )
{
int V_42 ;
T_2 V_559 = 0 ;
F_11 ( & V_335 -> V_50 ) ;
for( V_42 = 0 ; V_42 < V_285 ; V_42 ++ )
if ( ! F_165 ( & V_335 -> V_286 [ V_42 ] ) )
V_559 += F_430 (
& V_335 -> V_286 [ V_42 ] ) ;
F_13 ( & V_335 -> V_50 ) ;
return V_559 ;
}
void F_432 ( struct V_33 * V_34 ,
struct V_1 * V_2 )
{
struct V_95 * V_335 = V_2 -> V_98 ;
T_2 V_35 ;
F_29 ( ! V_2 -> V_111 ) ;
F_11 ( & V_335 -> V_50 ) ;
F_11 ( & V_2 -> V_50 ) ;
V_35 = V_2 -> V_20 . V_32 - V_2 -> V_9 - V_2 -> V_8 -
V_2 -> V_45 - F_73 ( & V_2 -> V_110 ) ;
V_335 -> V_290 -= V_35 ;
V_2 -> V_111 = 0 ;
F_13 ( & V_2 -> V_50 ) ;
F_13 ( & V_335 -> V_50 ) ;
}
int F_433 ( struct V_33 * V_34 , T_2 V_26 )
{
struct V_1 * V_13 ;
struct V_95 * V_98 ;
struct V_560 * V_314 = V_34 -> V_36 -> V_314 ;
struct V_561 * V_562 ;
T_2 V_563 ;
T_2 V_564 = 1 ;
T_2 V_565 = 0 ;
T_2 V_308 ;
int V_484 ;
int V_101 = 0 ;
int V_28 = 0 ;
V_13 = F_65 ( V_34 -> V_36 , V_26 ) ;
if ( ! V_13 )
return - 1 ;
V_563 = F_73 ( & V_13 -> V_110 ) ;
if ( ! V_563 )
goto V_70;
V_98 = V_13 -> V_98 ;
F_11 ( & V_98 -> V_50 ) ;
V_101 = V_98 -> V_101 ;
if ( ( V_98 -> V_278 != V_13 -> V_20 . V_32 ) &&
( V_98 -> V_279 + V_98 -> V_289 +
V_98 -> V_288 + V_98 -> V_290 +
V_563 < V_98 -> V_278 ) ) {
F_13 ( & V_98 -> V_50 ) ;
goto V_70;
}
F_13 ( & V_98 -> V_50 ) ;
V_28 = - 1 ;
V_308 = F_251 ( V_34 -> V_36 , V_13 -> V_6 ) ;
if ( V_308 ) {
V_484 = F_355 ( F_253 ( V_308 ) ) ;
} else {
if ( V_101 )
goto V_70;
V_484 = F_356 ( V_13 ) ;
}
if ( V_484 == V_469 ) {
V_564 = 4 ;
V_563 >>= 1 ;
} else if ( V_484 == V_470 ) {
V_564 = 2 ;
} else if ( V_484 == V_471 ) {
V_563 <<= 1 ;
} else if ( V_484 == V_472 ) {
V_564 = V_314 -> V_315 ;
F_434 ( V_563 , V_564 ) ;
}
F_34 ( & V_34 -> V_36 -> V_350 ) ;
F_359 (device, &fs_devices->alloc_list, dev_alloc_list) {
T_2 V_566 ;
if ( V_562 -> V_278 > V_562 -> V_279 + V_563 &&
! V_562 -> V_567 ) {
V_28 = F_435 ( V_562 , V_563 ,
& V_566 , NULL ) ;
if ( ! V_28 )
V_565 ++ ;
if ( V_565 >= V_564 )
break;
V_28 = - 1 ;
}
}
F_45 ( & V_34 -> V_36 -> V_350 ) ;
V_70:
F_6 ( V_13 ) ;
return V_28 ;
}
static int F_436 ( struct V_33 * V_34 ,
struct V_62 * V_63 , struct V_66 * V_20 )
{
int V_28 = 0 ;
struct V_66 V_140 ;
struct V_64 * V_65 ;
int V_529 ;
V_28 = F_36 ( NULL , V_34 , V_20 , V_63 , 0 , 0 ) ;
if ( V_28 < 0 )
goto V_70;
while ( 1 ) {
V_529 = V_63 -> V_80 [ 0 ] ;
V_65 = V_63 -> V_79 [ 0 ] ;
if ( V_529 >= F_37 ( V_65 ) ) {
V_28 = F_42 ( V_34 , V_63 ) ;
if ( V_28 == 0 )
continue;
if ( V_28 < 0 )
goto V_70;
break;
}
F_39 ( V_65 , & V_140 , V_529 ) ;
if ( V_140 . V_21 >= V_20 -> V_21 &&
V_140 . type == V_177 ) {
V_28 = 0 ;
goto V_70;
}
V_63 -> V_80 [ 0 ] ++ ;
}
V_70:
return V_28 ;
}
void F_437 ( struct V_11 * V_12 )
{
struct V_1 * V_13 ;
T_2 V_68 = 0 ;
while ( 1 ) {
struct V_259 * V_259 ;
V_13 = F_64 ( V_12 , V_68 ) ;
while ( V_13 ) {
F_11 ( & V_13 -> V_50 ) ;
if ( V_13 -> V_163 )
break;
F_13 ( & V_13 -> V_50 ) ;
V_13 = F_224 ( V_12 -> V_238 ,
V_13 ) ;
}
if ( ! V_13 ) {
if ( V_68 == 0 )
break;
V_68 = 0 ;
continue;
}
V_259 = V_13 -> V_259 ;
V_13 -> V_163 = 0 ;
V_13 -> V_259 = NULL ;
F_13 ( & V_13 -> V_50 ) ;
F_239 ( V_259 ) ;
V_68 = V_13 -> V_20 . V_21 + V_13 -> V_20 . V_32 ;
F_6 ( V_13 ) ;
}
}
int F_438 ( struct V_11 * V_12 )
{
struct V_1 * V_13 ;
struct V_95 * V_98 ;
struct V_48 * V_52 ;
struct V_14 * V_29 ;
F_60 ( & V_12 -> V_77 ) ;
while ( ! F_165 ( & V_12 -> V_93 ) ) {
V_52 = F_166 ( V_12 -> V_93 . V_216 ,
struct V_48 , V_85 ) ;
F_181 ( & V_52 -> V_85 ) ;
F_25 ( V_52 ) ;
}
F_62 ( & V_12 -> V_77 ) ;
F_11 ( & V_12 -> V_17 ) ;
while ( ( V_29 = F_178 ( & V_12 -> V_18 ) ) != NULL ) {
V_13 = F_12 ( V_29 , struct V_1 ,
V_19 ) ;
F_175 ( & V_13 -> V_19 ,
& V_12 -> V_18 ) ;
F_13 ( & V_12 -> V_17 ) ;
F_60 ( & V_13 -> V_98 -> V_287 ) ;
F_181 ( & V_13 -> V_85 ) ;
F_62 ( & V_13 -> V_98 -> V_287 ) ;
if ( V_13 -> V_3 == V_51 )
F_354 ( V_13 ) ;
if ( V_13 -> V_3 == V_89 )
F_19 ( V_12 -> V_61 , V_13 ) ;
F_439 ( V_13 ) ;
F_6 ( V_13 ) ;
F_11 ( & V_12 -> V_17 ) ;
}
F_13 ( & V_12 -> V_17 ) ;
F_440 () ;
F_309 ( V_12 ) ;
while( ! F_165 ( & V_12 -> V_98 ) ) {
V_98 = F_166 ( V_12 -> V_98 . V_216 ,
struct V_95 ,
V_85 ) ;
if ( F_234 ( V_12 -> V_238 , V_346 ) ) {
if ( V_98 -> V_288 > 0 ||
V_98 -> V_289 > 0 ||
V_98 -> V_291 > 0 ) {
F_8 ( 1 ) ;
F_271 ( V_98 , 0 , 0 ) ;
}
}
F_181 ( & V_98 -> V_85 ) ;
F_9 ( V_98 ) ;
}
return 0 ;
}
static void F_441 ( struct V_95 * V_98 ,
struct V_1 * V_2 )
{
int V_484 = F_356 ( V_2 ) ;
F_60 ( & V_98 -> V_287 ) ;
F_61 ( & V_2 -> V_85 , & V_98 -> V_286 [ V_484 ] ) ;
F_62 ( & V_98 -> V_287 ) ;
}
int F_442 ( struct V_33 * V_34 )
{
struct V_62 * V_63 ;
int V_28 ;
struct V_1 * V_2 ;
struct V_11 * V_12 = V_34 -> V_36 ;
struct V_95 * V_98 ;
struct V_66 V_20 ;
struct V_66 V_140 ;
struct V_64 * V_65 ;
int V_568 = 0 ;
T_2 V_569 ;
V_34 = V_12 -> V_61 ;
V_20 . V_21 = 0 ;
V_20 . V_32 = 0 ;
F_76 ( & V_20 , V_177 ) ;
V_63 = F_32 () ;
if ( ! V_63 )
return - V_84 ;
V_63 -> V_73 = 1 ;
V_569 = F_443 ( V_34 -> V_36 -> V_343 ) ;
if ( F_234 ( V_34 , V_272 ) &&
F_444 ( V_34 -> V_36 -> V_343 ) != V_569 )
V_568 = 1 ;
if ( F_234 ( V_34 , V_570 ) )
V_568 = 1 ;
while ( 1 ) {
V_28 = F_436 ( V_34 , V_63 , & V_20 ) ;
if ( V_28 > 0 )
break;
if ( V_28 != 0 )
goto error;
V_65 = V_63 -> V_79 [ 0 ] ;
F_39 ( V_65 , & V_140 , V_63 -> V_80 [ 0 ] ) ;
V_2 = F_51 ( sizeof( * V_2 ) , V_39 ) ;
if ( ! V_2 ) {
V_28 = - V_84 ;
goto error;
}
V_2 -> V_10 = F_51 ( sizeof( * V_2 -> V_10 ) ,
V_39 ) ;
if ( ! V_2 -> V_10 ) {
F_9 ( V_2 ) ;
V_28 = - V_84 ;
goto error;
}
F_55 ( & V_2 -> V_7 , 1 ) ;
F_245 ( & V_2 -> V_50 ) ;
V_2 -> V_36 = V_12 ;
F_52 ( & V_2 -> V_85 ) ;
F_52 ( & V_2 -> V_571 ) ;
if ( V_568 ) {
V_2 -> V_265 = V_274 ;
if ( F_234 ( V_34 , V_272 ) )
V_2 -> V_275 = 1 ;
}
F_445 ( V_65 , & V_2 -> V_110 ,
F_222 ( V_65 , V_63 -> V_80 [ 0 ] ) ,
sizeof( V_2 -> V_110 ) ) ;
memcpy ( & V_2 -> V_20 , & V_140 , sizeof( V_140 ) ) ;
V_20 . V_21 = V_140 . V_21 + V_140 . V_32 ;
F_43 ( V_63 ) ;
V_2 -> V_6 = F_446 ( & V_2 -> V_110 ) ;
V_2 -> V_326 = V_34 -> V_326 ;
V_2 -> V_572 = F_447 ( V_34 ,
& V_34 -> V_36 -> V_47 ,
V_140 . V_21 ) ;
F_448 ( V_2 ) ;
V_28 = F_21 ( V_34 , V_2 ) ;
if ( V_28 ) {
F_19 ( V_34 , V_2 ) ;
F_9 ( V_2 -> V_10 ) ;
F_9 ( V_2 ) ;
goto error;
}
if ( V_140 . V_32 == F_73 ( & V_2 -> V_110 ) ) {
V_2 -> V_92 = ( T_2 ) - 1 ;
V_2 -> V_3 = V_4 ;
F_19 ( V_34 , V_2 ) ;
} else if ( F_73 ( & V_2 -> V_110 ) == 0 ) {
V_2 -> V_92 = ( T_2 ) - 1 ;
V_2 -> V_3 = V_4 ;
F_26 ( V_2 , V_34 -> V_36 ,
V_140 . V_21 ,
V_140 . V_21 +
V_140 . V_32 ) ;
F_19 ( V_34 , V_2 ) ;
}
V_28 = F_243 ( V_12 , V_2 -> V_6 , V_140 . V_32 ,
F_73 ( & V_2 -> V_110 ) ,
& V_98 ) ;
F_29 ( V_28 ) ;
V_2 -> V_98 = V_98 ;
F_11 ( & V_2 -> V_98 -> V_50 ) ;
V_2 -> V_98 -> V_290 += V_2 -> V_45 ;
F_13 ( & V_2 -> V_98 -> V_50 ) ;
F_441 ( V_98 , V_2 ) ;
V_28 = F_10 ( V_34 -> V_36 , V_2 ) ;
F_29 ( V_28 ) ;
F_247 ( V_34 -> V_36 , V_2 -> V_6 ) ;
if ( F_449 ( V_34 , V_2 -> V_20 . V_21 ) )
F_427 ( V_2 , 1 ) ;
}
F_68 (space_info, &root->fs_info->space_info, list) {
if ( ! ( F_254 ( V_34 , V_98 -> V_6 ) &
( V_282 |
V_281 |
V_320 |
V_321 |
V_280 ) ) )
continue;
F_359 (cache, &space_info->block_groups[3], list)
F_427 ( V_2 , 1 ) ;
F_359 (cache, &space_info->block_groups[4], list)
F_427 ( V_2 , 1 ) ;
}
F_308 ( V_12 ) ;
V_28 = 0 ;
error:
F_48 ( V_63 ) ;
return V_28 ;
}
void F_194 ( struct V_114 * V_115 ,
struct V_33 * V_34 )
{
struct V_1 * V_13 , * V_317 ;
struct V_33 * V_61 = V_34 -> V_36 -> V_61 ;
struct V_573 V_110 ;
struct V_66 V_20 ;
int V_28 = 0 ;
F_340 (block_group, tmp, &trans->new_bgs,
new_bg_list) {
F_171 ( & V_13 -> V_574 ) ;
if ( V_28 )
continue;
F_11 ( & V_13 -> V_50 ) ;
memcpy ( & V_110 , & V_13 -> V_110 , sizeof( V_110 ) ) ;
memcpy ( & V_20 , & V_13 -> V_20 , sizeof( V_20 ) ) ;
F_13 ( & V_13 -> V_50 ) ;
V_28 = F_450 ( V_115 , V_61 , & V_20 , & V_110 ,
sizeof( V_110 ) ) ;
if ( V_28 )
F_149 ( V_115 , V_61 , V_28 ) ;
}
}
int F_451 ( struct V_114 * V_115 ,
struct V_33 * V_34 , T_2 V_279 ,
T_2 type , T_2 V_575 , T_2 V_576 ,
T_2 V_55 )
{
int V_28 ;
struct V_33 * V_61 ;
struct V_1 * V_2 ;
V_61 = V_34 -> V_36 -> V_61 ;
V_34 -> V_36 -> V_577 = V_115 -> V_268 ;
V_2 = F_51 ( sizeof( * V_2 ) , V_39 ) ;
if ( ! V_2 )
return - V_84 ;
V_2 -> V_10 = F_51 ( sizeof( * V_2 -> V_10 ) ,
V_39 ) ;
if ( ! V_2 -> V_10 ) {
F_9 ( V_2 ) ;
return - V_84 ;
}
V_2 -> V_20 . V_21 = V_576 ;
V_2 -> V_20 . V_32 = V_55 ;
V_2 -> V_20 . type = V_177 ;
V_2 -> V_326 = V_34 -> V_326 ;
V_2 -> V_36 = V_34 -> V_36 ;
V_2 -> V_572 = F_447 ( V_34 ,
& V_34 -> V_36 -> V_47 ,
V_576 ) ;
F_55 ( & V_2 -> V_7 , 1 ) ;
F_245 ( & V_2 -> V_50 ) ;
F_52 ( & V_2 -> V_85 ) ;
F_52 ( & V_2 -> V_571 ) ;
F_52 ( & V_2 -> V_574 ) ;
F_448 ( V_2 ) ;
F_333 ( & V_2 -> V_110 , V_279 ) ;
F_452 ( & V_2 -> V_110 , V_575 ) ;
V_2 -> V_6 = type ;
F_453 ( & V_2 -> V_110 , type ) ;
V_2 -> V_92 = ( T_2 ) - 1 ;
V_2 -> V_3 = V_4 ;
V_28 = F_21 ( V_34 , V_2 ) ;
if ( V_28 ) {
F_19 ( V_34 , V_2 ) ;
F_9 ( V_2 -> V_10 ) ;
F_9 ( V_2 ) ;
return V_28 ;
}
F_26 ( V_2 , V_34 -> V_36 , V_576 ,
V_576 + V_55 ) ;
F_19 ( V_34 , V_2 ) ;
V_28 = F_243 ( V_34 -> V_36 , V_2 -> V_6 , V_55 , V_279 ,
& V_2 -> V_98 ) ;
F_29 ( V_28 ) ;
F_307 ( V_34 -> V_36 ) ;
F_11 ( & V_2 -> V_98 -> V_50 ) ;
V_2 -> V_98 -> V_290 += V_2 -> V_45 ;
F_13 ( & V_2 -> V_98 -> V_50 ) ;
F_441 ( V_2 -> V_98 , V_2 ) ;
V_28 = F_10 ( V_34 -> V_36 , V_2 ) ;
F_29 ( V_28 ) ;
F_61 ( & V_2 -> V_574 , & V_115 -> V_243 ) ;
F_247 ( V_61 -> V_36 , type ) ;
return 0 ;
}
static void F_454 ( struct V_11 * V_36 , T_2 V_6 )
{
T_2 V_298 = F_248 ( V_6 ) &
V_299 ;
F_249 ( & V_36 -> V_300 ) ;
if ( V_6 & V_296 )
V_36 -> V_301 &= ~ V_298 ;
if ( V_6 & V_112 )
V_36 -> V_302 &= ~ V_298 ;
if ( V_6 & V_303 )
V_36 -> V_304 &= ~ V_298 ;
F_250 ( & V_36 -> V_300 ) ;
}
int F_455 ( struct V_114 * V_115 ,
struct V_33 * V_34 , T_2 V_106 )
{
struct V_62 * V_63 ;
struct V_1 * V_13 ;
struct V_479 * V_213 ;
struct V_33 * V_238 = V_34 -> V_36 -> V_238 ;
struct V_66 V_20 ;
struct V_259 * V_259 ;
int V_28 ;
int V_484 ;
int V_108 ;
V_34 = V_34 -> V_36 -> V_61 ;
V_13 = F_65 ( V_34 -> V_36 , V_106 ) ;
F_29 ( ! V_13 ) ;
F_29 ( ! V_13 -> V_111 ) ;
F_19 ( V_34 , V_13 ) ;
memcpy ( & V_20 , & V_13 -> V_20 , sizeof( V_20 ) ) ;
V_484 = F_356 ( V_13 ) ;
if ( V_13 -> V_6 & ( V_280 |
V_281 |
V_282 ) )
V_108 = 2 ;
else
V_108 = 1 ;
V_213 = & V_34 -> V_36 -> V_494 ;
F_11 ( & V_213 -> V_500 ) ;
F_362 ( V_13 , V_213 ) ;
F_13 ( & V_213 -> V_500 ) ;
V_213 = & V_34 -> V_36 -> V_492 ;
F_11 ( & V_213 -> V_500 ) ;
F_362 ( V_13 , V_213 ) ;
F_13 ( & V_213 -> V_500 ) ;
V_63 = F_32 () ;
if ( ! V_63 ) {
V_28 = - V_84 ;
goto V_70;
}
V_259 = F_226 ( V_238 , V_13 , V_63 ) ;
if ( ! F_227 ( V_259 ) ) {
V_28 = F_456 ( V_115 , V_259 ) ;
if ( V_28 ) {
F_457 ( V_259 ) ;
goto V_70;
}
F_458 ( V_259 ) ;
F_11 ( & V_13 -> V_50 ) ;
if ( V_13 -> V_163 ) {
V_13 -> V_163 = 0 ;
V_13 -> V_259 = NULL ;
F_13 ( & V_13 -> V_50 ) ;
F_239 ( V_259 ) ;
} else {
F_13 ( & V_13 -> V_50 ) ;
}
F_457 ( V_259 ) ;
}
V_20 . V_21 = V_578 ;
V_20 . V_32 = V_13 -> V_20 . V_21 ;
V_20 . type = 0 ;
V_28 = F_36 ( V_115 , V_238 , & V_20 , V_63 , - 1 , 1 ) ;
if ( V_28 < 0 )
goto V_70;
if ( V_28 > 0 )
F_43 ( V_63 ) ;
if ( V_28 == 0 ) {
V_28 = F_117 ( V_115 , V_238 , V_63 ) ;
if ( V_28 )
goto V_70;
F_43 ( V_63 ) ;
}
F_11 ( & V_34 -> V_36 -> V_17 ) ;
F_175 ( & V_13 -> V_19 ,
& V_34 -> V_36 -> V_18 ) ;
if ( V_34 -> V_36 -> V_25 == V_13 -> V_20 . V_21 )
V_34 -> V_36 -> V_25 = ( T_2 ) - 1 ;
F_13 ( & V_34 -> V_36 -> V_17 ) ;
F_60 ( & V_13 -> V_98 -> V_287 ) ;
F_171 ( & V_13 -> V_85 ) ;
if ( F_165 ( & V_13 -> V_98 -> V_286 [ V_484 ] ) )
F_454 ( V_34 -> V_36 , V_13 -> V_6 ) ;
F_62 ( & V_13 -> V_98 -> V_287 ) ;
if ( V_13 -> V_3 == V_51 )
F_354 ( V_13 ) ;
F_439 ( V_13 ) ;
F_11 ( & V_13 -> V_98 -> V_50 ) ;
V_13 -> V_98 -> V_278 -= V_13 -> V_20 . V_32 ;
V_13 -> V_98 -> V_290 -= V_13 -> V_20 . V_32 ;
V_13 -> V_98 -> V_283 -= V_13 -> V_20 . V_32 * V_108 ;
F_13 ( & V_13 -> V_98 -> V_50 ) ;
memcpy ( & V_20 , & V_13 -> V_20 , sizeof( V_20 ) ) ;
F_70 ( V_34 -> V_36 ) ;
F_6 ( V_13 ) ;
F_6 ( V_13 ) ;
V_28 = F_36 ( V_115 , V_34 , & V_20 , V_63 , - 1 , 1 ) ;
if ( V_28 > 0 )
V_28 = - V_173 ;
if ( V_28 < 0 )
goto V_70;
V_28 = F_117 ( V_115 , V_34 , V_63 ) ;
V_70:
F_48 ( V_63 ) ;
return V_28 ;
}
int F_459 ( struct V_11 * V_36 )
{
struct V_95 * V_98 ;
struct V_579 * V_580 ;
T_2 V_581 ;
T_2 V_6 ;
int V_582 = 0 ;
int V_28 ;
V_580 = V_36 -> V_343 ;
if ( ! F_460 ( V_580 ) )
return 1 ;
V_581 = F_461 ( V_580 ) ;
if ( V_581 & V_583 )
V_582 = 1 ;
V_6 = V_303 ;
V_28 = F_243 ( V_36 , V_6 , 0 , 0 , & V_98 ) ;
if ( V_28 )
goto V_70;
if ( V_582 ) {
V_6 = V_112 | V_296 ;
V_28 = F_243 ( V_36 , V_6 , 0 , 0 , & V_98 ) ;
} else {
V_6 = V_112 ;
V_28 = F_243 ( V_36 , V_6 , 0 , 0 , & V_98 ) ;
if ( V_28 )
goto V_70;
V_6 = V_296 ;
V_28 = F_243 ( V_36 , V_6 , 0 , 0 , & V_98 ) ;
}
V_70:
return V_28 ;
}
int F_462 ( struct V_33 * V_34 , T_2 V_31 , T_2 V_30 )
{
return F_341 ( V_34 , V_31 , V_30 ) ;
}
int F_463 ( struct V_33 * V_34 , T_2 V_26 ,
T_2 V_35 , T_2 * V_185 )
{
return F_143 ( V_34 , V_26 , V_35 , V_185 ) ;
}
int F_464 ( struct V_33 * V_34 , struct V_584 * V_585 )
{
struct V_11 * V_36 = V_34 -> V_36 ;
struct V_1 * V_2 = NULL ;
T_2 V_586 ;
T_2 V_31 ;
T_2 V_30 ;
T_2 V_587 = 0 ;
T_2 V_278 = F_266 ( V_36 -> V_343 ) ;
int V_28 = 0 ;
if ( V_585 -> V_113 == V_278 )
V_2 = F_64 ( V_36 , V_585 -> V_31 ) ;
else
V_2 = F_65 ( V_36 , V_585 -> V_31 ) ;
while ( V_2 ) {
if ( V_2 -> V_20 . V_21 >= ( V_585 -> V_31 + V_585 -> V_113 ) ) {
F_6 ( V_2 ) ;
break;
}
V_31 = F_72 ( V_585 -> V_31 , V_2 -> V_20 . V_21 ) ;
V_30 = F_275 ( V_585 -> V_31 + V_585 -> V_113 ,
V_2 -> V_20 . V_21 + V_2 -> V_20 . V_32 ) ;
if ( V_30 - V_31 >= V_585 -> V_588 ) {
if ( ! F_1 ( V_2 ) ) {
V_28 = F_49 ( V_2 , 0 ) ;
if ( ! V_28 )
F_354 ( V_2 ) ;
}
V_28 = F_465 ( V_2 ,
& V_586 ,
V_31 ,
V_30 ,
V_585 -> V_588 ) ;
V_587 += V_586 ;
if ( V_28 ) {
F_6 ( V_2 ) ;
break;
}
}
V_2 = F_224 ( V_36 -> V_238 , V_2 ) ;
}
V_585 -> V_113 = V_587 ;
return V_28 ;
}
