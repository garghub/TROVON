static T_1 int
F_1 ( struct V_1 * V_2 )
{
F_2 () ;
return V_2 -> V_3 == V_4 ||
V_2 -> V_3 == V_5 ;
}
static int F_3 ( struct V_1 * V_2 , T_2 V_6 )
{
return ( V_2 -> V_7 & V_6 ) == V_6 ;
}
static void F_4 ( struct V_1 * V_2 )
{
F_5 ( & V_2 -> V_8 ) ;
}
void F_6 ( struct V_1 * V_2 )
{
if ( F_7 ( & V_2 -> V_8 ) ) {
F_8 ( V_2 -> V_9 > 0 ) ;
F_8 ( V_2 -> V_10 > 0 ) ;
F_9 ( V_2 -> V_11 ) ;
F_9 ( V_2 ) ;
}
}
static int F_10 ( struct V_12 * V_13 ,
struct V_1 * V_14 )
{
struct V_15 * * V_16 ;
struct V_15 * V_17 = NULL ;
struct V_1 * V_2 ;
F_11 ( & V_13 -> V_18 ) ;
V_16 = & V_13 -> V_19 . V_15 ;
while ( * V_16 ) {
V_17 = * V_16 ;
V_2 = F_12 ( V_17 , struct V_1 ,
V_20 ) ;
if ( V_14 -> V_21 . V_22 < V_2 -> V_21 . V_22 ) {
V_16 = & ( * V_16 ) -> V_23 ;
} else if ( V_14 -> V_21 . V_22 > V_2 -> V_21 . V_22 ) {
V_16 = & ( * V_16 ) -> V_24 ;
} else {
F_13 ( & V_13 -> V_18 ) ;
return - V_25 ;
}
}
F_14 ( & V_14 -> V_20 , V_17 , V_16 ) ;
F_15 ( & V_14 -> V_20 ,
& V_13 -> V_19 ) ;
if ( V_13 -> V_26 > V_14 -> V_21 . V_22 )
V_13 -> V_26 = V_14 -> V_21 . V_22 ;
F_13 ( & V_13 -> V_18 ) ;
return 0 ;
}
static struct V_1 *
F_16 ( struct V_12 * V_13 , T_2 V_27 ,
int V_28 )
{
struct V_1 * V_2 , * V_29 = NULL ;
struct V_15 * V_30 ;
T_2 V_31 , V_32 ;
F_11 ( & V_13 -> V_18 ) ;
V_30 = V_13 -> V_19 . V_15 ;
while ( V_30 ) {
V_2 = F_12 ( V_30 , struct V_1 ,
V_20 ) ;
V_31 = V_2 -> V_21 . V_22 + V_2 -> V_21 . V_33 - 1 ;
V_32 = V_2 -> V_21 . V_22 ;
if ( V_27 < V_32 ) {
if ( ! V_28 && ( ! V_29 || V_32 < V_29 -> V_21 . V_22 ) )
V_29 = V_2 ;
V_30 = V_30 -> V_23 ;
} else if ( V_27 > V_32 ) {
if ( V_28 && V_27 <= V_31 ) {
V_29 = V_2 ;
break;
}
V_30 = V_30 -> V_24 ;
} else {
V_29 = V_2 ;
break;
}
}
if ( V_29 ) {
F_4 ( V_29 ) ;
if ( V_27 == 0 && V_13 -> V_26 > V_29 -> V_21 . V_22 )
V_13 -> V_26 = V_29 -> V_21 . V_22 ;
}
F_13 ( & V_13 -> V_18 ) ;
return V_29 ;
}
static int F_17 ( struct V_34 * V_35 ,
T_2 V_32 , T_2 V_36 )
{
T_2 V_31 = V_32 + V_36 - 1 ;
F_18 ( & V_35 -> V_37 -> V_38 [ 0 ] ,
V_32 , V_31 , V_39 , V_40 ) ;
F_18 ( & V_35 -> V_37 -> V_38 [ 1 ] ,
V_32 , V_31 , V_39 , V_40 ) ;
return 0 ;
}
static void F_19 ( struct V_34 * V_35 ,
struct V_1 * V_2 )
{
T_2 V_32 , V_31 ;
V_32 = V_2 -> V_21 . V_22 ;
V_31 = V_32 + V_2 -> V_21 . V_33 - 1 ;
F_20 ( & V_35 -> V_37 -> V_38 [ 0 ] ,
V_32 , V_31 , V_39 , V_40 ) ;
F_20 ( & V_35 -> V_37 -> V_38 [ 1 ] ,
V_32 , V_31 , V_39 , V_40 ) ;
}
static int F_21 ( struct V_34 * V_35 ,
struct V_1 * V_2 )
{
T_2 V_27 ;
T_2 * V_41 ;
int V_42 ;
int V_43 , V_44 , V_29 ;
if ( V_2 -> V_21 . V_22 < V_45 ) {
V_42 = V_45 - V_2 -> V_21 . V_22 ;
V_2 -> V_46 += V_42 ;
V_29 = F_17 ( V_35 , V_2 -> V_21 . V_22 ,
V_42 ) ;
if ( V_29 )
return V_29 ;
}
for ( V_43 = 0 ; V_43 < V_47 ; V_43 ++ ) {
V_27 = F_22 ( V_43 ) ;
V_29 = F_23 ( & V_35 -> V_37 -> V_48 ,
V_2 -> V_21 . V_22 , V_27 ,
0 , & V_41 , & V_44 , & V_42 ) ;
if ( V_29 )
return V_29 ;
while ( V_44 -- ) {
T_2 V_32 , V_49 ;
if ( V_41 [ V_44 ] > V_2 -> V_21 . V_22 +
V_2 -> V_21 . V_33 )
continue;
if ( V_41 [ V_44 ] + V_42 <= V_2 -> V_21 . V_22 )
continue;
V_32 = V_41 [ V_44 ] ;
if ( V_32 < V_2 -> V_21 . V_22 ) {
V_32 = V_2 -> V_21 . V_22 ;
V_49 = ( V_41 [ V_44 ] + V_42 ) - V_32 ;
} else {
V_49 = F_24 ( T_2 , V_42 ,
V_2 -> V_21 . V_22 +
V_2 -> V_21 . V_33 - V_32 ) ;
}
V_2 -> V_46 += V_49 ;
V_29 = F_17 ( V_35 , V_32 , V_49 ) ;
if ( V_29 ) {
F_9 ( V_41 ) ;
return V_29 ;
}
}
F_9 ( V_41 ) ;
}
return 0 ;
}
static struct V_50 *
F_25 ( struct V_1 * V_2 )
{
struct V_50 * V_51 ;
F_11 ( & V_2 -> V_52 ) ;
if ( ! V_2 -> V_53 ) {
F_13 ( & V_2 -> V_52 ) ;
return NULL ;
}
V_51 = V_2 -> V_53 ;
F_5 ( & V_51 -> V_8 ) ;
F_13 ( & V_2 -> V_52 ) ;
return V_51 ;
}
static void F_26 ( struct V_50 * V_51 )
{
if ( F_7 ( & V_51 -> V_8 ) )
F_9 ( V_51 ) ;
}
static T_2 F_27 ( struct V_1 * V_14 ,
struct V_12 * V_13 , T_2 V_32 , T_2 V_31 )
{
T_2 V_54 , V_55 , V_56 , V_57 = 0 ;
int V_29 ;
while ( V_32 < V_31 ) {
V_29 = F_28 ( V_13 -> V_58 , V_32 ,
& V_54 , & V_55 ,
V_59 | V_39 ,
NULL ) ;
if ( V_29 )
break;
if ( V_54 <= V_32 ) {
V_32 = V_55 + 1 ;
} else if ( V_54 > V_32 && V_54 < V_31 ) {
V_56 = V_54 - V_32 ;
V_57 += V_56 ;
V_29 = F_29 ( V_14 , V_32 ,
V_56 ) ;
F_30 ( V_29 ) ;
V_32 = V_55 + 1 ;
} else {
break;
}
}
if ( V_32 < V_31 ) {
V_56 = V_31 - V_32 ;
V_57 += V_56 ;
V_29 = F_29 ( V_14 , V_32 , V_56 ) ;
F_30 ( V_29 ) ;
}
return V_57 ;
}
static T_1 void F_31 ( struct V_60 * V_61 )
{
struct V_1 * V_14 ;
struct V_12 * V_37 ;
struct V_50 * V_53 ;
struct V_34 * V_62 ;
struct V_63 * V_64 ;
struct V_65 * V_66 ;
struct V_67 V_21 ;
T_2 V_68 = 0 ;
T_2 V_69 = 0 ;
T_3 V_70 ;
int V_29 = - V_71 ;
V_53 = F_32 ( V_61 , struct V_50 , V_61 ) ;
V_14 = V_53 -> V_14 ;
V_37 = V_14 -> V_37 ;
V_62 = V_37 -> V_62 ;
V_64 = F_33 () ;
if ( ! V_64 )
goto V_72;
V_69 = F_34 ( T_2 , V_14 -> V_21 . V_22 , V_45 ) ;
V_64 -> V_73 = 1 ;
V_64 -> V_74 = 1 ;
V_64 -> V_75 = 1 ;
V_21 . V_22 = V_69 ;
V_21 . V_33 = 0 ;
V_21 . type = V_76 ;
V_77:
F_35 ( & V_53 -> V_78 ) ;
F_36 ( & V_37 -> V_79 ) ;
V_80:
V_29 = F_37 ( NULL , V_62 , & V_21 , V_64 , 0 , 0 ) ;
if ( V_29 < 0 )
goto V_81;
V_66 = V_64 -> V_82 [ 0 ] ;
V_70 = F_38 ( V_66 ) ;
while ( 1 ) {
if ( F_39 ( V_37 ) > 1 ) {
V_69 = ( T_2 ) - 1 ;
break;
}
if ( V_64 -> V_83 [ 0 ] < V_70 ) {
F_40 ( V_66 , & V_21 , V_64 -> V_83 [ 0 ] ) ;
} else {
V_29 = F_41 ( V_64 , 0 , & V_21 ) ;
if ( V_29 )
break;
if ( F_42 () ||
F_43 ( & V_37 -> V_79 ) ) {
V_53 -> V_84 = V_69 ;
F_44 ( V_64 ) ;
F_45 ( & V_37 -> V_79 ) ;
F_46 ( & V_53 -> V_78 ) ;
F_47 () ;
goto V_77;
}
V_29 = F_48 ( V_62 , V_64 ) ;
if ( V_29 < 0 )
goto V_81;
if ( V_29 )
break;
V_66 = V_64 -> V_82 [ 0 ] ;
V_70 = F_38 ( V_66 ) ;
continue;
}
if ( V_21 . V_22 < V_69 ) {
V_21 . V_22 = V_69 ;
V_21 . V_33 = 0 ;
V_21 . type = V_76 ;
V_53 -> V_84 = V_69 ;
F_44 ( V_64 ) ;
goto V_80;
}
if ( V_21 . V_22 < V_14 -> V_21 . V_22 ) {
V_64 -> V_83 [ 0 ] ++ ;
continue;
}
if ( V_21 . V_22 >= V_14 -> V_21 . V_22 +
V_14 -> V_21 . V_33 )
break;
if ( V_21 . type == V_76 ||
V_21 . type == V_85 ) {
V_68 += F_27 ( V_14 ,
V_37 , V_69 ,
V_21 . V_22 ) ;
if ( V_21 . type == V_85 )
V_69 = V_21 . V_22 +
V_37 -> V_86 -> V_87 ;
else
V_69 = V_21 . V_22 + V_21 . V_33 ;
if ( V_68 > ( 1024 * 1024 * 2 ) ) {
V_68 = 0 ;
F_49 ( & V_53 -> V_88 ) ;
}
}
V_64 -> V_83 [ 0 ] ++ ;
}
V_29 = 0 ;
V_68 += F_27 ( V_14 , V_37 , V_69 ,
V_14 -> V_21 . V_22 +
V_14 -> V_21 . V_33 ) ;
V_53 -> V_84 = ( T_2 ) - 1 ;
F_11 ( & V_14 -> V_52 ) ;
V_14 -> V_53 = NULL ;
V_14 -> V_3 = V_4 ;
F_13 ( & V_14 -> V_52 ) ;
V_81:
F_50 ( V_64 ) ;
F_45 ( & V_37 -> V_79 ) ;
F_19 ( V_62 , V_14 ) ;
F_46 ( & V_53 -> V_78 ) ;
V_72:
if ( V_29 ) {
F_11 ( & V_14 -> V_52 ) ;
V_14 -> V_53 = NULL ;
V_14 -> V_3 = V_5 ;
F_13 ( & V_14 -> V_52 ) ;
}
F_49 ( & V_53 -> V_88 ) ;
F_26 ( V_53 ) ;
F_6 ( V_14 ) ;
}
static int F_51 ( struct V_1 * V_2 ,
int V_89 )
{
F_52 ( V_88 ) ;
struct V_12 * V_37 = V_2 -> V_37 ;
struct V_50 * V_53 ;
int V_29 = 0 ;
V_53 = F_53 ( sizeof( * V_53 ) , V_40 ) ;
if ( ! V_53 )
return - V_71 ;
F_54 ( & V_53 -> V_90 ) ;
F_55 ( & V_53 -> V_78 ) ;
F_56 ( & V_53 -> V_88 ) ;
V_53 -> V_14 = V_2 ;
V_53 -> V_84 = V_2 -> V_21 . V_22 ;
F_57 ( & V_53 -> V_8 , 1 ) ;
F_58 ( & V_53 -> V_61 , V_91 ,
F_31 , NULL , NULL ) ;
F_11 ( & V_2 -> V_52 ) ;
while ( V_2 -> V_3 == V_92 ) {
struct V_50 * V_51 ;
V_51 = V_2 -> V_53 ;
F_5 ( & V_51 -> V_8 ) ;
F_59 ( & V_51 -> V_88 , & V_88 , V_93 ) ;
F_13 ( & V_2 -> V_52 ) ;
F_60 () ;
F_61 ( & V_51 -> V_88 , & V_88 ) ;
F_26 ( V_51 ) ;
F_11 ( & V_2 -> V_52 ) ;
}
if ( V_2 -> V_3 != V_94 ) {
F_13 ( & V_2 -> V_52 ) ;
F_9 ( V_53 ) ;
return 0 ;
}
F_8 ( V_2 -> V_53 ) ;
V_2 -> V_53 = V_53 ;
V_2 -> V_3 = V_92 ;
F_13 ( & V_2 -> V_52 ) ;
if ( V_37 -> V_95 & V_96 ) {
F_35 ( & V_53 -> V_78 ) ;
V_29 = F_62 ( V_37 , V_2 ) ;
F_11 ( & V_2 -> V_52 ) ;
if ( V_29 == 1 ) {
V_2 -> V_53 = NULL ;
V_2 -> V_3 = V_4 ;
V_2 -> V_97 = ( T_2 ) - 1 ;
V_53 -> V_84 = ( T_2 ) - 1 ;
} else {
if ( V_89 ) {
V_2 -> V_53 = NULL ;
V_2 -> V_3 = V_94 ;
} else {
V_2 -> V_3 = V_98 ;
V_2 -> V_99 = 1 ;
}
}
F_13 ( & V_2 -> V_52 ) ;
F_46 ( & V_53 -> V_78 ) ;
F_49 ( & V_53 -> V_88 ) ;
if ( V_29 == 1 ) {
F_26 ( V_53 ) ;
F_19 ( V_37 -> V_62 , V_2 ) ;
return 0 ;
}
} else {
F_11 ( & V_2 -> V_52 ) ;
if ( V_89 ) {
V_2 -> V_53 = NULL ;
V_2 -> V_3 = V_94 ;
} else {
V_2 -> V_3 = V_98 ;
V_2 -> V_99 = 1 ;
}
F_13 ( & V_2 -> V_52 ) ;
F_49 ( & V_53 -> V_88 ) ;
}
if ( V_89 ) {
F_26 ( V_53 ) ;
return 0 ;
}
F_63 ( & V_37 -> V_79 ) ;
F_5 ( & V_53 -> V_8 ) ;
F_64 ( & V_53 -> V_90 , & V_37 -> V_100 ) ;
F_65 ( & V_37 -> V_79 ) ;
F_4 ( V_2 ) ;
F_66 ( V_37 -> V_101 , & V_53 -> V_61 ) ;
return V_29 ;
}
static struct V_1 *
F_67 ( struct V_12 * V_13 , T_2 V_27 )
{
struct V_1 * V_2 ;
V_2 = F_16 ( V_13 , V_27 , 0 ) ;
return V_2 ;
}
struct V_1 * F_68 (
struct V_12 * V_13 ,
T_2 V_27 )
{
struct V_1 * V_2 ;
V_2 = F_16 ( V_13 , V_27 , 1 ) ;
return V_2 ;
}
static struct V_102 * F_69 ( struct V_12 * V_13 ,
T_2 V_7 )
{
struct V_103 * V_104 = & V_13 -> V_105 ;
struct V_102 * V_106 ;
V_7 &= V_107 ;
F_70 () ;
F_71 (found, head, list) {
if ( V_106 -> V_7 & V_7 ) {
F_72 () ;
return V_106 ;
}
}
F_72 () ;
return NULL ;
}
void F_73 ( struct V_12 * V_13 )
{
struct V_103 * V_104 = & V_13 -> V_105 ;
struct V_102 * V_106 ;
F_70 () ;
F_71 (found, head, list)
V_106 -> V_108 = 0 ;
F_72 () ;
}
int F_74 ( struct V_34 * V_35 , T_2 V_32 , T_2 V_49 )
{
int V_29 ;
struct V_67 V_21 ;
struct V_63 * V_64 ;
V_64 = F_33 () ;
if ( ! V_64 )
return - V_71 ;
V_21 . V_22 = V_32 ;
V_21 . V_33 = V_49 ;
V_21 . type = V_76 ;
V_29 = F_37 ( NULL , V_35 -> V_37 -> V_62 , & V_21 , V_64 ,
0 , 0 ) ;
F_50 ( V_64 ) ;
return V_29 ;
}
int F_75 ( struct V_109 * V_110 ,
struct V_34 * V_35 , T_2 V_27 ,
T_2 V_33 , int V_111 , T_2 * V_112 , T_2 * V_7 )
{
struct V_113 * V_104 ;
struct V_114 * V_115 ;
struct V_63 * V_64 ;
struct V_116 * V_117 ;
struct V_65 * V_66 ;
struct V_67 V_21 ;
T_3 V_118 ;
T_2 V_119 ;
T_2 V_120 ;
int V_29 ;
if ( V_111 && ! F_76 ( V_35 -> V_37 , V_121 ) ) {
V_33 = V_35 -> V_87 ;
V_111 = 0 ;
}
V_64 = F_33 () ;
if ( ! V_64 )
return - V_71 ;
if ( ! V_110 ) {
V_64 -> V_73 = 1 ;
V_64 -> V_74 = 1 ;
}
V_122:
V_21 . V_22 = V_27 ;
V_21 . V_33 = V_33 ;
if ( V_111 )
V_21 . type = V_85 ;
else
V_21 . type = V_76 ;
V_29 = F_37 ( V_110 , V_35 -> V_37 -> V_62 ,
& V_21 , V_64 , 0 , 0 ) ;
if ( V_29 < 0 )
goto V_123;
if ( V_29 > 0 && V_111 && V_21 . type == V_85 ) {
if ( V_64 -> V_83 [ 0 ] ) {
V_64 -> V_83 [ 0 ] -- ;
F_40 ( V_64 -> V_82 [ 0 ] , & V_21 ,
V_64 -> V_83 [ 0 ] ) ;
if ( V_21 . V_22 == V_27 &&
V_21 . type == V_76 &&
V_21 . V_33 == V_35 -> V_87 )
V_29 = 0 ;
}
}
if ( V_29 == 0 ) {
V_66 = V_64 -> V_82 [ 0 ] ;
V_118 = F_77 ( V_66 , V_64 -> V_83 [ 0 ] ) ;
if ( V_118 >= sizeof( * V_117 ) ) {
V_117 = F_78 ( V_66 , V_64 -> V_83 [ 0 ] ,
struct V_116 ) ;
V_119 = F_79 ( V_66 , V_117 ) ;
V_120 = F_80 ( V_66 , V_117 ) ;
} else {
#ifdef F_81
struct V_124 * V_125 ;
F_30 ( V_118 != sizeof( * V_125 ) ) ;
V_125 = F_78 ( V_66 , V_64 -> V_83 [ 0 ] ,
struct V_124 ) ;
V_119 = F_82 ( V_66 , V_125 ) ;
V_120 = V_126 ;
#else
F_83 () ;
#endif
}
F_30 ( V_119 == 0 ) ;
} else {
V_119 = 0 ;
V_120 = 0 ;
V_29 = 0 ;
}
if ( ! V_110 )
goto V_72;
V_115 = & V_110 -> V_127 -> V_115 ;
F_11 ( & V_115 -> V_52 ) ;
V_104 = F_84 ( V_110 , V_27 ) ;
if ( V_104 ) {
if ( ! F_85 ( & V_104 -> V_78 ) ) {
F_5 ( & V_104 -> V_128 . V_112 ) ;
F_13 ( & V_115 -> V_52 ) ;
F_44 ( V_64 ) ;
F_35 ( & V_104 -> V_78 ) ;
F_46 ( & V_104 -> V_78 ) ;
F_86 ( & V_104 -> V_128 ) ;
goto V_122;
}
F_11 ( & V_104 -> V_52 ) ;
if ( V_104 -> V_129 && V_104 -> V_129 -> V_130 )
V_120 |= V_104 -> V_129 -> V_131 ;
else
F_30 ( V_119 == 0 ) ;
V_119 += V_104 -> V_128 . V_132 ;
F_13 ( & V_104 -> V_52 ) ;
F_46 ( & V_104 -> V_78 ) ;
}
F_13 ( & V_115 -> V_52 ) ;
V_72:
F_8 ( V_119 == 0 ) ;
if ( V_112 )
* V_112 = V_119 ;
if ( V_7 )
* V_7 = V_120 ;
V_123:
F_50 ( V_64 ) ;
return V_29 ;
}
static int F_87 ( struct V_109 * V_110 ,
struct V_34 * V_35 ,
struct V_63 * V_64 ,
T_2 V_133 , T_3 V_134 )
{
struct V_116 * V_135 ;
struct V_124 * V_125 ;
struct V_136 * V_137 ;
struct V_138 * V_139 ;
struct V_65 * V_66 ;
struct V_67 V_21 ;
struct V_67 V_140 ;
T_3 V_141 = sizeof( * V_135 ) ;
T_2 V_112 ;
int V_29 ;
V_66 = V_64 -> V_82 [ 0 ] ;
F_30 ( F_77 ( V_66 , V_64 -> V_83 [ 0 ] ) != sizeof( * V_125 ) ) ;
F_40 ( V_66 , & V_21 , V_64 -> V_83 [ 0 ] ) ;
V_125 = F_78 ( V_66 , V_64 -> V_83 [ 0 ] ,
struct V_124 ) ;
V_112 = F_82 ( V_66 , V_125 ) ;
if ( V_133 == ( T_2 ) - 1 ) {
while ( 1 ) {
if ( V_64 -> V_83 [ 0 ] >= F_38 ( V_66 ) ) {
V_29 = F_48 ( V_35 , V_64 ) ;
if ( V_29 < 0 )
return V_29 ;
F_30 ( V_29 > 0 ) ;
V_66 = V_64 -> V_82 [ 0 ] ;
}
F_40 ( V_66 , & V_140 ,
V_64 -> V_83 [ 0 ] ) ;
F_30 ( V_21 . V_22 != V_140 . V_22 ) ;
if ( V_140 . type != V_142 ) {
V_64 -> V_83 [ 0 ] ++ ;
continue;
}
V_137 = F_78 ( V_66 , V_64 -> V_83 [ 0 ] ,
struct V_136 ) ;
V_133 = F_88 ( V_66 , V_137 ) ;
break;
}
}
F_44 ( V_64 ) ;
if ( V_133 < V_143 )
V_141 += sizeof( * V_139 ) ;
V_141 -= sizeof( * V_125 ) ;
V_29 = F_37 ( V_110 , V_35 , & V_21 , V_64 ,
V_141 + V_134 , 1 ) ;
if ( V_29 < 0 )
return V_29 ;
F_30 ( V_29 ) ;
F_89 ( V_35 , V_64 , V_141 ) ;
V_66 = V_64 -> V_82 [ 0 ] ;
V_135 = F_78 ( V_66 , V_64 -> V_83 [ 0 ] , struct V_116 ) ;
F_90 ( V_66 , V_135 , V_112 ) ;
F_91 ( V_66 , V_135 , 0 ) ;
if ( V_133 < V_143 ) {
F_92 ( V_66 , V_135 ,
V_144 |
V_126 ) ;
V_139 = (struct V_138 * ) ( V_135 + 1 ) ;
F_93 ( V_66 , 0 , ( unsigned long ) V_139 , sizeof( * V_139 ) ) ;
F_94 ( V_66 , V_139 , ( int ) V_133 ) ;
} else {
F_92 ( V_66 , V_135 , V_145 ) ;
}
F_95 ( V_66 ) ;
return 0 ;
}
static T_2 F_96 ( T_2 V_146 , T_2 V_133 , T_2 V_33 )
{
T_3 V_147 = ~ ( T_3 ) 0 ;
T_3 V_148 = ~ ( T_3 ) 0 ;
T_4 V_149 ;
V_149 = F_97 ( V_146 ) ;
V_147 = F_98 ( V_147 , & V_149 , sizeof( V_149 ) ) ;
V_149 = F_97 ( V_133 ) ;
V_148 = F_98 ( V_148 , & V_149 , sizeof( V_149 ) ) ;
V_149 = F_97 ( V_33 ) ;
V_148 = F_98 ( V_148 , & V_149 , sizeof( V_149 ) ) ;
return ( ( T_2 ) V_147 << 31 ) ^ ( T_2 ) V_148 ;
}
static T_2 F_99 ( struct V_65 * V_66 ,
struct V_150 * V_151 )
{
return F_96 ( F_100 ( V_66 , V_151 ) ,
F_101 ( V_66 , V_151 ) ,
F_102 ( V_66 , V_151 ) ) ;
}
static int F_103 ( struct V_65 * V_66 ,
struct V_150 * V_151 ,
T_2 V_146 , T_2 V_133 , T_2 V_33 )
{
if ( F_100 ( V_66 , V_151 ) != V_146 ||
F_101 ( V_66 , V_151 ) != V_133 ||
F_102 ( V_66 , V_151 ) != V_33 )
return 0 ;
return 1 ;
}
static T_1 int F_104 ( struct V_109 * V_110 ,
struct V_34 * V_35 ,
struct V_63 * V_64 ,
T_2 V_27 , T_2 V_17 ,
T_2 V_146 ,
T_2 V_133 , T_2 V_33 )
{
struct V_67 V_21 ;
struct V_150 * V_151 ;
struct V_65 * V_66 ;
T_3 V_70 ;
int V_29 ;
int V_152 ;
int V_81 = - V_153 ;
V_21 . V_22 = V_27 ;
if ( V_17 ) {
V_21 . type = V_154 ;
V_21 . V_33 = V_17 ;
} else {
V_21 . type = V_155 ;
V_21 . V_33 = F_96 ( V_146 ,
V_133 , V_33 ) ;
}
V_77:
V_152 = 0 ;
V_29 = F_37 ( V_110 , V_35 , & V_21 , V_64 , - 1 , 1 ) ;
if ( V_29 < 0 ) {
V_81 = V_29 ;
goto V_156;
}
if ( V_17 ) {
if ( ! V_29 )
return 0 ;
#ifdef F_81
V_21 . type = V_142 ;
F_44 ( V_64 ) ;
V_29 = F_37 ( V_110 , V_35 , & V_21 , V_64 , - 1 , 1 ) ;
if ( V_29 < 0 ) {
V_81 = V_29 ;
goto V_156;
}
if ( ! V_29 )
return 0 ;
#endif
goto V_156;
}
V_66 = V_64 -> V_82 [ 0 ] ;
V_70 = F_38 ( V_66 ) ;
while ( 1 ) {
if ( V_64 -> V_83 [ 0 ] >= V_70 ) {
V_29 = F_48 ( V_35 , V_64 ) ;
if ( V_29 < 0 )
V_81 = V_29 ;
if ( V_29 )
goto V_156;
V_66 = V_64 -> V_82 [ 0 ] ;
V_70 = F_38 ( V_66 ) ;
V_152 = 1 ;
}
F_40 ( V_66 , & V_21 , V_64 -> V_83 [ 0 ] ) ;
if ( V_21 . V_22 != V_27 ||
V_21 . type != V_155 )
goto V_156;
V_151 = F_78 ( V_66 , V_64 -> V_83 [ 0 ] ,
struct V_150 ) ;
if ( F_103 ( V_66 , V_151 , V_146 ,
V_133 , V_33 ) ) {
if ( V_152 ) {
F_44 ( V_64 ) ;
goto V_77;
}
V_81 = 0 ;
break;
}
V_64 -> V_83 [ 0 ] ++ ;
}
V_156:
return V_81 ;
}
static T_1 int F_105 ( struct V_109 * V_110 ,
struct V_34 * V_35 ,
struct V_63 * V_64 ,
T_2 V_27 , T_2 V_17 ,
T_2 V_146 , T_2 V_133 ,
T_2 V_33 , int V_157 )
{
struct V_67 V_21 ;
struct V_65 * V_66 ;
T_3 V_56 ;
T_3 V_119 ;
int V_29 ;
V_21 . V_22 = V_27 ;
if ( V_17 ) {
V_21 . type = V_154 ;
V_21 . V_33 = V_17 ;
V_56 = sizeof( struct V_158 ) ;
} else {
V_21 . type = V_155 ;
V_21 . V_33 = F_96 ( V_146 ,
V_133 , V_33 ) ;
V_56 = sizeof( struct V_150 ) ;
}
V_29 = F_106 ( V_110 , V_35 , V_64 , & V_21 , V_56 ) ;
if ( V_29 && V_29 != - V_25 )
goto V_156;
V_66 = V_64 -> V_82 [ 0 ] ;
if ( V_17 ) {
struct V_158 * V_151 ;
V_151 = F_78 ( V_66 , V_64 -> V_83 [ 0 ] ,
struct V_158 ) ;
if ( V_29 == 0 ) {
F_107 ( V_66 , V_151 , V_157 ) ;
} else {
V_119 = F_108 ( V_66 , V_151 ) ;
V_119 += V_157 ;
F_107 ( V_66 , V_151 , V_119 ) ;
}
} else {
struct V_150 * V_151 ;
while ( V_29 == - V_25 ) {
V_151 = F_78 ( V_66 , V_64 -> V_83 [ 0 ] ,
struct V_150 ) ;
if ( F_103 ( V_66 , V_151 , V_146 ,
V_133 , V_33 ) )
break;
F_44 ( V_64 ) ;
V_21 . V_33 ++ ;
V_29 = F_106 ( V_110 , V_35 , V_64 , & V_21 ,
V_56 ) ;
if ( V_29 && V_29 != - V_25 )
goto V_156;
V_66 = V_64 -> V_82 [ 0 ] ;
}
V_151 = F_78 ( V_66 , V_64 -> V_83 [ 0 ] ,
struct V_150 ) ;
if ( V_29 == 0 ) {
F_109 ( V_66 , V_151 ,
V_146 ) ;
F_110 ( V_66 , V_151 , V_133 ) ;
F_111 ( V_66 , V_151 , V_33 ) ;
F_112 ( V_66 , V_151 , V_157 ) ;
} else {
V_119 = F_113 ( V_66 , V_151 ) ;
V_119 += V_157 ;
F_112 ( V_66 , V_151 , V_119 ) ;
}
}
F_95 ( V_66 ) ;
V_29 = 0 ;
V_156:
F_44 ( V_64 ) ;
return V_29 ;
}
static T_1 int F_114 ( struct V_109 * V_110 ,
struct V_34 * V_35 ,
struct V_63 * V_64 ,
int V_159 , int * V_160 )
{
struct V_67 V_21 ;
struct V_150 * V_161 = NULL ;
struct V_158 * V_162 = NULL ;
struct V_65 * V_66 ;
T_3 V_119 = 0 ;
int V_29 = 0 ;
V_66 = V_64 -> V_82 [ 0 ] ;
F_40 ( V_66 , & V_21 , V_64 -> V_83 [ 0 ] ) ;
if ( V_21 . type == V_155 ) {
V_161 = F_78 ( V_66 , V_64 -> V_83 [ 0 ] ,
struct V_150 ) ;
V_119 = F_113 ( V_66 , V_161 ) ;
} else if ( V_21 . type == V_154 ) {
V_162 = F_78 ( V_66 , V_64 -> V_83 [ 0 ] ,
struct V_158 ) ;
V_119 = F_108 ( V_66 , V_162 ) ;
#ifdef F_81
} else if ( V_21 . type == V_142 ) {
struct V_136 * V_137 ;
V_137 = F_78 ( V_66 , V_64 -> V_83 [ 0 ] ,
struct V_136 ) ;
V_119 = F_115 ( V_66 , V_137 ) ;
#endif
} else {
F_83 () ;
}
F_30 ( V_119 < V_159 ) ;
V_119 -= V_159 ;
if ( V_119 == 0 ) {
V_29 = F_116 ( V_110 , V_35 , V_64 ) ;
* V_160 = 1 ;
} else {
if ( V_21 . type == V_155 )
F_112 ( V_66 , V_161 , V_119 ) ;
else if ( V_21 . type == V_154 )
F_107 ( V_66 , V_162 , V_119 ) ;
#ifdef F_81
else {
struct V_136 * V_137 ;
V_137 = F_78 ( V_66 , V_64 -> V_83 [ 0 ] ,
struct V_136 ) ;
F_117 ( V_66 , V_137 , V_119 ) ;
}
#endif
F_95 ( V_66 ) ;
}
return V_29 ;
}
static T_1 T_3 F_118 ( struct V_34 * V_35 ,
struct V_63 * V_64 ,
struct V_163 * V_164 )
{
struct V_67 V_21 ;
struct V_65 * V_66 ;
struct V_150 * V_161 ;
struct V_158 * V_162 ;
T_3 V_119 = 0 ;
V_66 = V_64 -> V_82 [ 0 ] ;
F_40 ( V_66 , & V_21 , V_64 -> V_83 [ 0 ] ) ;
if ( V_164 ) {
if ( F_119 ( V_66 , V_164 ) ==
V_155 ) {
V_161 = (struct V_150 * ) ( & V_164 -> V_33 ) ;
V_119 = F_113 ( V_66 , V_161 ) ;
} else {
V_162 = (struct V_158 * ) ( V_164 + 1 ) ;
V_119 = F_108 ( V_66 , V_162 ) ;
}
} else if ( V_21 . type == V_155 ) {
V_161 = F_78 ( V_66 , V_64 -> V_83 [ 0 ] ,
struct V_150 ) ;
V_119 = F_113 ( V_66 , V_161 ) ;
} else if ( V_21 . type == V_154 ) {
V_162 = F_78 ( V_66 , V_64 -> V_83 [ 0 ] ,
struct V_158 ) ;
V_119 = F_108 ( V_66 , V_162 ) ;
#ifdef F_81
} else if ( V_21 . type == V_142 ) {
struct V_136 * V_137 ;
V_137 = F_78 ( V_66 , V_64 -> V_83 [ 0 ] ,
struct V_136 ) ;
V_119 = F_115 ( V_66 , V_137 ) ;
#endif
} else {
F_8 ( 1 ) ;
}
return V_119 ;
}
static T_1 int F_120 ( struct V_109 * V_110 ,
struct V_34 * V_35 ,
struct V_63 * V_64 ,
T_2 V_27 , T_2 V_17 ,
T_2 V_146 )
{
struct V_67 V_21 ;
int V_29 ;
V_21 . V_22 = V_27 ;
if ( V_17 ) {
V_21 . type = V_165 ;
V_21 . V_33 = V_17 ;
} else {
V_21 . type = V_166 ;
V_21 . V_33 = V_146 ;
}
V_29 = F_37 ( V_110 , V_35 , & V_21 , V_64 , - 1 , 1 ) ;
if ( V_29 > 0 )
V_29 = - V_153 ;
#ifdef F_81
if ( V_29 == - V_153 && V_17 ) {
F_44 ( V_64 ) ;
V_21 . type = V_142 ;
V_29 = F_37 ( V_110 , V_35 , & V_21 , V_64 , - 1 , 1 ) ;
if ( V_29 > 0 )
V_29 = - V_153 ;
}
#endif
return V_29 ;
}
static T_1 int F_121 ( struct V_109 * V_110 ,
struct V_34 * V_35 ,
struct V_63 * V_64 ,
T_2 V_27 , T_2 V_17 ,
T_2 V_146 )
{
struct V_67 V_21 ;
int V_29 ;
V_21 . V_22 = V_27 ;
if ( V_17 ) {
V_21 . type = V_165 ;
V_21 . V_33 = V_17 ;
} else {
V_21 . type = V_166 ;
V_21 . V_33 = V_146 ;
}
V_29 = F_106 ( V_110 , V_35 , V_64 , & V_21 , 0 ) ;
F_44 ( V_64 ) ;
return V_29 ;
}
static inline int F_122 ( T_2 V_17 , T_2 V_133 )
{
int type ;
if ( V_133 < V_143 ) {
if ( V_17 > 0 )
type = V_165 ;
else
type = V_166 ;
} else {
if ( V_17 > 0 )
type = V_154 ;
else
type = V_155 ;
}
return type ;
}
static int F_41 ( struct V_63 * V_64 , int V_167 ,
struct V_67 * V_21 )
{
for (; V_167 < V_168 ; V_167 ++ ) {
if ( ! V_64 -> V_82 [ V_167 ] )
break;
if ( V_64 -> V_83 [ V_167 ] + 1 >=
F_38 ( V_64 -> V_82 [ V_167 ] ) )
continue;
if ( V_167 == 0 )
F_40 ( V_64 -> V_82 [ V_167 ] , V_21 ,
V_64 -> V_83 [ V_167 ] + 1 ) ;
else
F_123 ( V_64 -> V_82 [ V_167 ] , V_21 ,
V_64 -> V_83 [ V_167 ] + 1 ) ;
return 0 ;
}
return 1 ;
}
static T_5
int F_124 ( struct V_109 * V_110 ,
struct V_34 * V_35 ,
struct V_63 * V_64 ,
struct V_163 * * V_169 ,
T_2 V_27 , T_2 V_36 ,
T_2 V_17 , T_2 V_146 ,
T_2 V_133 , T_2 V_33 , int V_170 )
{
struct V_67 V_21 ;
struct V_65 * V_66 ;
struct V_116 * V_117 ;
struct V_163 * V_164 ;
T_2 V_7 ;
T_2 V_118 ;
unsigned long V_171 ;
unsigned long V_31 ;
int V_134 ;
int type ;
int V_172 ;
int V_29 ;
int V_81 = 0 ;
bool V_173 = F_76 ( V_35 -> V_37 ,
V_121 ) ;
V_21 . V_22 = V_27 ;
V_21 . type = V_76 ;
V_21 . V_33 = V_36 ;
V_172 = F_122 ( V_17 , V_133 ) ;
if ( V_170 ) {
V_134 = F_125 ( V_172 ) ;
V_64 -> V_174 = 1 ;
} else
V_134 = - 1 ;
if ( V_173 && V_133 < V_143 ) {
V_21 . type = V_85 ;
V_21 . V_33 = V_133 ;
}
V_77:
V_29 = F_37 ( V_110 , V_35 , & V_21 , V_64 , V_134 , 1 ) ;
if ( V_29 < 0 ) {
V_81 = V_29 ;
goto V_72;
}
if ( V_29 > 0 && V_173 ) {
V_173 = false ;
if ( V_64 -> V_83 [ 0 ] ) {
V_64 -> V_83 [ 0 ] -- ;
F_40 ( V_64 -> V_82 [ 0 ] , & V_21 ,
V_64 -> V_83 [ 0 ] ) ;
if ( V_21 . V_22 == V_27 &&
V_21 . type == V_76 &&
V_21 . V_33 == V_36 )
V_29 = 0 ;
}
if ( V_29 ) {
V_21 . V_22 = V_27 ;
V_21 . type = V_76 ;
V_21 . V_33 = V_36 ;
F_44 ( V_64 ) ;
goto V_77;
}
}
if ( V_29 && ! V_170 ) {
V_81 = - V_153 ;
goto V_72;
} else if ( F_8 ( V_29 ) ) {
V_81 = - V_175 ;
goto V_72;
}
V_66 = V_64 -> V_82 [ 0 ] ;
V_118 = F_77 ( V_66 , V_64 -> V_83 [ 0 ] ) ;
#ifdef F_81
if ( V_118 < sizeof( * V_117 ) ) {
if ( ! V_170 ) {
V_81 = - V_153 ;
goto V_72;
}
V_29 = F_87 ( V_110 , V_35 , V_64 , V_133 ,
V_134 ) ;
if ( V_29 < 0 ) {
V_81 = V_29 ;
goto V_72;
}
V_66 = V_64 -> V_82 [ 0 ] ;
V_118 = F_77 ( V_66 , V_64 -> V_83 [ 0 ] ) ;
}
#endif
F_30 ( V_118 < sizeof( * V_117 ) ) ;
V_117 = F_78 ( V_66 , V_64 -> V_83 [ 0 ] , struct V_116 ) ;
V_7 = F_80 ( V_66 , V_117 ) ;
V_171 = ( unsigned long ) ( V_117 + 1 ) ;
V_31 = ( unsigned long ) V_117 + V_118 ;
if ( V_7 & V_144 && ! V_173 ) {
V_171 += sizeof( struct V_138 ) ;
F_30 ( V_171 > V_31 ) ;
}
V_81 = - V_153 ;
while ( 1 ) {
if ( V_171 >= V_31 ) {
F_8 ( V_171 > V_31 ) ;
break;
}
V_164 = (struct V_163 * ) V_171 ;
type = F_119 ( V_66 , V_164 ) ;
if ( V_172 < type )
break;
if ( V_172 > type ) {
V_171 += F_125 ( type ) ;
continue;
}
if ( type == V_155 ) {
struct V_150 * V_176 ;
V_176 = (struct V_150 * ) ( & V_164 -> V_33 ) ;
if ( F_103 ( V_66 , V_176 , V_146 ,
V_133 , V_33 ) ) {
V_81 = 0 ;
break;
}
if ( F_99 ( V_66 , V_176 ) <
F_96 ( V_146 , V_133 , V_33 ) )
break;
} else {
T_2 V_177 ;
V_177 = F_126 ( V_66 , V_164 ) ;
if ( V_17 > 0 ) {
if ( V_17 == V_177 ) {
V_81 = 0 ;
break;
}
if ( V_177 < V_17 )
break;
} else {
if ( V_146 == V_177 ) {
V_81 = 0 ;
break;
}
if ( V_177 < V_146 )
break;
}
}
V_171 += F_125 ( type ) ;
}
if ( V_81 == - V_153 && V_170 ) {
if ( V_118 + V_134 >=
F_127 ( V_35 ) ) {
V_81 = - V_178 ;
goto V_72;
}
if ( F_41 ( V_64 , 0 , & V_21 ) == 0 &&
V_21 . V_22 == V_27 &&
V_21 . type < V_179 ) {
V_81 = - V_178 ;
goto V_72;
}
}
* V_169 = (struct V_163 * ) V_171 ;
V_72:
if ( V_170 ) {
V_64 -> V_174 = 0 ;
F_128 ( V_64 , 1 ) ;
}
return V_81 ;
}
static T_5
void F_129 ( struct V_34 * V_35 ,
struct V_63 * V_64 ,
struct V_163 * V_164 ,
T_2 V_17 , T_2 V_146 ,
T_2 V_133 , T_2 V_33 , int V_157 ,
struct V_180 * V_129 )
{
struct V_65 * V_66 ;
struct V_116 * V_117 ;
unsigned long V_171 ;
unsigned long V_31 ;
unsigned long V_181 ;
T_2 V_112 ;
int V_56 ;
int type ;
V_66 = V_64 -> V_82 [ 0 ] ;
V_117 = F_78 ( V_66 , V_64 -> V_83 [ 0 ] , struct V_116 ) ;
V_181 = ( unsigned long ) V_164 - ( unsigned long ) V_117 ;
type = F_122 ( V_17 , V_133 ) ;
V_56 = F_125 ( type ) ;
F_89 ( V_35 , V_64 , V_56 ) ;
V_117 = F_78 ( V_66 , V_64 -> V_83 [ 0 ] , struct V_116 ) ;
V_112 = F_79 ( V_66 , V_117 ) ;
V_112 += V_157 ;
F_90 ( V_66 , V_117 , V_112 ) ;
if ( V_129 )
F_130 ( V_129 , V_66 , V_117 ) ;
V_171 = ( unsigned long ) V_117 + V_181 ;
V_31 = ( unsigned long ) V_117 + F_77 ( V_66 , V_64 -> V_83 [ 0 ] ) ;
if ( V_171 < V_31 - V_56 )
F_131 ( V_66 , V_171 + V_56 , V_171 ,
V_31 - V_56 - V_171 ) ;
V_164 = (struct V_163 * ) V_171 ;
F_132 ( V_66 , V_164 , type ) ;
if ( type == V_155 ) {
struct V_150 * V_176 ;
V_176 = (struct V_150 * ) ( & V_164 -> V_33 ) ;
F_109 ( V_66 , V_176 , V_146 ) ;
F_110 ( V_66 , V_176 , V_133 ) ;
F_111 ( V_66 , V_176 , V_33 ) ;
F_112 ( V_66 , V_176 , V_157 ) ;
} else if ( type == V_154 ) {
struct V_158 * V_182 ;
V_182 = (struct V_158 * ) ( V_164 + 1 ) ;
F_107 ( V_66 , V_182 , V_157 ) ;
F_133 ( V_66 , V_164 , V_17 ) ;
} else if ( type == V_165 ) {
F_133 ( V_66 , V_164 , V_17 ) ;
} else {
F_133 ( V_66 , V_164 , V_146 ) ;
}
F_95 ( V_66 ) ;
}
static int F_134 ( struct V_109 * V_110 ,
struct V_34 * V_35 ,
struct V_63 * V_64 ,
struct V_163 * * V_169 ,
T_2 V_27 , T_2 V_36 , T_2 V_17 ,
T_2 V_146 , T_2 V_133 , T_2 V_33 )
{
int V_29 ;
V_29 = F_124 ( V_110 , V_35 , V_64 , V_169 ,
V_27 , V_36 , V_17 ,
V_146 , V_133 , V_33 , 0 ) ;
if ( V_29 != - V_153 )
return V_29 ;
F_44 ( V_64 ) ;
* V_169 = NULL ;
if ( V_133 < V_143 ) {
V_29 = F_120 ( V_110 , V_35 , V_64 , V_27 , V_17 ,
V_146 ) ;
} else {
V_29 = F_104 ( V_110 , V_35 , V_64 , V_27 , V_17 ,
V_146 , V_133 , V_33 ) ;
}
return V_29 ;
}
static T_5
void F_135 ( struct V_34 * V_35 ,
struct V_63 * V_64 ,
struct V_163 * V_164 ,
int V_183 ,
struct V_180 * V_129 ,
int * V_160 )
{
struct V_65 * V_66 ;
struct V_116 * V_117 ;
struct V_150 * V_176 = NULL ;
struct V_158 * V_182 = NULL ;
unsigned long V_171 ;
unsigned long V_31 ;
T_3 V_118 ;
int V_56 ;
int type ;
T_2 V_112 ;
V_66 = V_64 -> V_82 [ 0 ] ;
V_117 = F_78 ( V_66 , V_64 -> V_83 [ 0 ] , struct V_116 ) ;
V_112 = F_79 ( V_66 , V_117 ) ;
F_8 ( V_183 < 0 && V_112 + V_183 <= 0 ) ;
V_112 += V_183 ;
F_90 ( V_66 , V_117 , V_112 ) ;
if ( V_129 )
F_130 ( V_129 , V_66 , V_117 ) ;
type = F_119 ( V_66 , V_164 ) ;
if ( type == V_155 ) {
V_176 = (struct V_150 * ) ( & V_164 -> V_33 ) ;
V_112 = F_113 ( V_66 , V_176 ) ;
} else if ( type == V_154 ) {
V_182 = (struct V_158 * ) ( V_164 + 1 ) ;
V_112 = F_108 ( V_66 , V_182 ) ;
} else {
V_112 = 1 ;
F_30 ( V_183 != - 1 ) ;
}
F_30 ( V_183 < 0 && V_112 < - V_183 ) ;
V_112 += V_183 ;
if ( V_112 > 0 ) {
if ( type == V_155 )
F_112 ( V_66 , V_176 , V_112 ) ;
else
F_107 ( V_66 , V_182 , V_112 ) ;
} else {
* V_160 = 1 ;
V_56 = F_125 ( type ) ;
V_118 = F_77 ( V_66 , V_64 -> V_83 [ 0 ] ) ;
V_171 = ( unsigned long ) V_164 ;
V_31 = ( unsigned long ) V_117 + V_118 ;
if ( V_171 + V_56 < V_31 )
F_131 ( V_66 , V_171 , V_171 + V_56 ,
V_31 - V_171 - V_56 ) ;
V_118 -= V_56 ;
F_136 ( V_35 , V_64 , V_118 , 1 ) ;
}
F_95 ( V_66 ) ;
}
static T_5
int F_137 ( struct V_109 * V_110 ,
struct V_34 * V_35 ,
struct V_63 * V_64 ,
T_2 V_27 , T_2 V_36 , T_2 V_17 ,
T_2 V_146 , T_2 V_133 ,
T_2 V_33 , int V_157 ,
struct V_180 * V_129 )
{
struct V_163 * V_164 ;
int V_29 ;
V_29 = F_124 ( V_110 , V_35 , V_64 , & V_164 ,
V_27 , V_36 , V_17 ,
V_146 , V_133 , V_33 , 1 ) ;
if ( V_29 == 0 ) {
F_30 ( V_133 < V_143 ) ;
F_135 ( V_35 , V_64 , V_164 ,
V_157 , V_129 , NULL ) ;
} else if ( V_29 == - V_153 ) {
F_129 ( V_35 , V_64 , V_164 , V_17 ,
V_146 , V_133 , V_33 ,
V_157 , V_129 ) ;
V_29 = 0 ;
}
return V_29 ;
}
static int F_138 ( struct V_109 * V_110 ,
struct V_34 * V_35 ,
struct V_63 * V_64 ,
T_2 V_27 , T_2 V_17 , T_2 V_146 ,
T_2 V_133 , T_2 V_33 , int V_157 )
{
int V_29 ;
if ( V_133 < V_143 ) {
F_30 ( V_157 != 1 ) ;
V_29 = F_121 ( V_110 , V_35 , V_64 , V_27 ,
V_17 , V_146 ) ;
} else {
V_29 = F_105 ( V_110 , V_35 , V_64 , V_27 ,
V_17 , V_146 ,
V_133 , V_33 , V_157 ) ;
}
return V_29 ;
}
static int F_139 ( struct V_109 * V_110 ,
struct V_34 * V_35 ,
struct V_63 * V_64 ,
struct V_163 * V_164 ,
int V_159 , int V_184 , int * V_160 )
{
int V_29 = 0 ;
F_30 ( ! V_184 && V_159 != 1 ) ;
if ( V_164 ) {
F_135 ( V_35 , V_64 , V_164 ,
- V_159 , NULL , V_160 ) ;
} else if ( V_184 ) {
V_29 = F_114 ( V_110 , V_35 , V_64 , V_159 ,
V_160 ) ;
} else {
* V_160 = 1 ;
V_29 = F_116 ( V_110 , V_35 , V_64 ) ;
}
return V_29 ;
}
static int F_140 ( struct V_185 * V_186 ,
T_2 V_32 , T_2 V_49 )
{
return F_141 ( V_186 , V_32 >> 9 , V_49 >> 9 , V_40 , 0 ) ;
}
int F_142 ( struct V_34 * V_35 , T_2 V_27 ,
T_2 V_36 , T_2 * V_187 )
{
int V_29 ;
T_2 V_188 = 0 ;
struct V_189 * V_190 = NULL ;
V_29 = F_143 ( V_35 -> V_37 , V_191 ,
V_27 , & V_36 , & V_190 , 0 ) ;
if ( ! V_29 ) {
struct V_192 * V_193 = V_190 -> V_194 ;
int V_43 ;
for ( V_43 = 0 ; V_43 < V_190 -> V_195 ; V_43 ++ , V_193 ++ ) {
if ( ! V_193 -> V_196 -> V_197 )
continue;
V_29 = F_140 ( V_193 -> V_196 -> V_186 ,
V_193 -> V_198 ,
V_193 -> V_199 ) ;
if ( ! V_29 )
V_188 += V_193 -> V_199 ;
else if ( V_29 != - V_200 )
break;
V_29 = 0 ;
}
F_9 ( V_190 ) ;
}
if ( V_187 )
* V_187 = V_188 ;
if ( V_29 == - V_200 )
V_29 = 0 ;
return V_29 ;
}
int F_144 ( struct V_109 * V_110 ,
struct V_34 * V_35 ,
T_2 V_27 , T_2 V_36 , T_2 V_17 ,
T_2 V_146 , T_2 V_133 , T_2 V_33 ,
int V_201 )
{
int V_29 ;
struct V_12 * V_37 = V_35 -> V_37 ;
F_30 ( V_133 < V_143 &&
V_146 == V_202 ) ;
if ( V_133 < V_143 ) {
V_29 = F_145 ( V_37 , V_110 , V_27 ,
V_36 ,
V_17 , V_146 , ( int ) V_133 ,
V_203 , NULL , V_201 ) ;
} else {
V_29 = F_146 ( V_37 , V_110 , V_27 ,
V_36 ,
V_17 , V_146 , V_133 , V_33 ,
V_203 , NULL , V_201 ) ;
}
return V_29 ;
}
static int F_147 ( struct V_109 * V_110 ,
struct V_34 * V_35 ,
T_2 V_27 , T_2 V_36 ,
T_2 V_17 , T_2 V_146 ,
T_2 V_133 , T_2 V_33 , int V_157 ,
int V_201 ,
struct V_180 * V_129 )
{
struct V_12 * V_37 = V_35 -> V_37 ;
struct V_63 * V_64 ;
struct V_65 * V_66 ;
struct V_116 * V_135 ;
struct V_67 V_21 ;
T_2 V_112 ;
int V_29 ;
enum V_204 type = V_205 ;
V_64 = F_33 () ;
if ( ! V_64 )
return - V_71 ;
if ( ! F_148 ( V_146 ) || ! V_35 -> V_37 -> V_206 )
V_201 = 1 ;
V_64 -> V_75 = 1 ;
V_64 -> V_207 = 1 ;
V_29 = F_137 ( V_110 , V_37 -> V_62 , V_64 ,
V_27 , V_36 , V_17 ,
V_146 , V_133 , V_33 ,
V_157 , V_129 ) ;
if ( ( V_29 < 0 && V_29 != - V_178 ) || ( ! V_29 && V_201 ) )
goto V_72;
if ( ! V_29 && ! V_201 ) {
ASSERT ( V_35 -> V_37 -> V_206 ) ;
V_66 = V_64 -> V_82 [ 0 ] ;
F_40 ( V_66 , & V_21 , V_64 -> V_83 [ 0 ] ) ;
V_135 = F_78 ( V_66 , V_64 -> V_83 [ 0 ] ,
struct V_116 ) ;
if ( F_79 ( V_66 , V_135 ) > ( T_2 ) V_157 )
type = V_208 ;
F_44 ( V_64 ) ;
V_29 = F_149 ( V_110 , V_37 , V_146 ,
V_27 , V_36 , type , 0 ) ;
goto V_72;
}
V_66 = V_64 -> V_82 [ 0 ] ;
F_40 ( V_66 , & V_21 , V_64 -> V_83 [ 0 ] ) ;
V_135 = F_78 ( V_66 , V_64 -> V_83 [ 0 ] , struct V_116 ) ;
V_112 = F_79 ( V_66 , V_135 ) ;
if ( V_112 )
type = V_208 ;
F_90 ( V_66 , V_135 , V_112 + V_157 ) ;
if ( V_129 )
F_130 ( V_129 , V_66 , V_135 ) ;
F_95 ( V_66 ) ;
F_44 ( V_64 ) ;
if ( ! V_201 ) {
V_29 = F_149 ( V_110 , V_37 , V_146 ,
V_27 , V_36 , type , 0 ) ;
if ( V_29 )
goto V_72;
}
V_64 -> V_75 = 1 ;
V_64 -> V_207 = 1 ;
V_29 = F_138 ( V_110 , V_35 -> V_37 -> V_62 ,
V_64 , V_27 , V_17 , V_146 ,
V_133 , V_33 , V_157 ) ;
if ( V_29 )
F_150 ( V_110 , V_35 , V_29 ) ;
V_72:
F_50 ( V_64 ) ;
return V_29 ;
}
static int F_151 ( struct V_109 * V_110 ,
struct V_34 * V_35 ,
struct V_209 * V_128 ,
struct V_180 * V_129 ,
int V_210 )
{
int V_29 = 0 ;
struct V_211 * V_151 ;
struct V_67 V_212 ;
T_2 V_17 = 0 ;
T_2 V_213 = 0 ;
T_2 V_7 = 0 ;
V_212 . V_22 = V_128 -> V_27 ;
V_212 . V_33 = V_128 -> V_36 ;
V_212 . type = V_76 ;
V_151 = F_152 ( V_128 ) ;
F_153 ( V_128 , V_151 , V_128 -> V_214 ) ;
if ( V_128 -> type == V_154 )
V_17 = V_151 -> V_17 ;
V_213 = V_151 -> V_35 ;
if ( V_128 -> V_214 == V_203 && V_210 ) {
if ( V_129 )
V_7 |= V_129 -> V_131 ;
V_29 = F_154 ( V_110 , V_35 ,
V_17 , V_213 , V_7 ,
V_151 -> V_22 , V_151 -> V_33 ,
& V_212 , V_128 -> V_132 ) ;
} else if ( V_128 -> V_214 == V_203 ) {
V_29 = F_147 ( V_110 , V_35 , V_128 -> V_27 ,
V_128 -> V_36 , V_17 ,
V_213 , V_151 -> V_22 ,
V_151 -> V_33 , V_128 -> V_132 ,
V_128 -> V_201 , V_129 ) ;
} else if ( V_128 -> V_214 == V_215 ) {
V_29 = F_155 ( V_110 , V_35 , V_128 -> V_27 ,
V_128 -> V_36 , V_17 ,
V_213 , V_151 -> V_22 ,
V_151 -> V_33 , V_128 -> V_132 ,
V_129 , V_128 -> V_201 ) ;
} else {
F_83 () ;
}
return V_29 ;
}
static void F_130 ( struct V_180 * V_129 ,
struct V_65 * V_66 ,
struct V_116 * V_117 )
{
T_2 V_7 = F_80 ( V_66 , V_117 ) ;
if ( V_129 -> V_130 ) {
V_7 |= V_129 -> V_131 ;
F_92 ( V_66 , V_117 , V_7 ) ;
}
if ( V_129 -> V_216 ) {
struct V_138 * V_139 ;
F_30 ( ! ( V_7 & V_144 ) ) ;
V_139 = (struct V_138 * ) ( V_117 + 1 ) ;
F_156 ( V_66 , V_139 , & V_129 -> V_21 ) ;
}
}
static int F_157 ( struct V_109 * V_110 ,
struct V_34 * V_35 ,
struct V_209 * V_128 ,
struct V_180 * V_129 )
{
struct V_67 V_21 ;
struct V_63 * V_64 ;
struct V_116 * V_117 ;
struct V_65 * V_66 ;
T_3 V_118 ;
int V_29 ;
int V_81 = 0 ;
int V_111 = ! V_129 -> V_184 ;
if ( V_110 -> V_217 )
return 0 ;
if ( V_111 && ! F_76 ( V_35 -> V_37 , V_121 ) )
V_111 = 0 ;
V_64 = F_33 () ;
if ( ! V_64 )
return - V_71 ;
V_21 . V_22 = V_128 -> V_27 ;
if ( V_111 ) {
V_21 . type = V_85 ;
V_21 . V_33 = V_129 -> V_167 ;
} else {
V_21 . type = V_76 ;
V_21 . V_33 = V_128 -> V_36 ;
}
V_77:
V_64 -> V_75 = 1 ;
V_64 -> V_207 = 1 ;
V_29 = F_37 ( V_110 , V_35 -> V_37 -> V_62 , & V_21 ,
V_64 , 0 , 1 ) ;
if ( V_29 < 0 ) {
V_81 = V_29 ;
goto V_72;
}
if ( V_29 > 0 ) {
if ( V_111 ) {
if ( V_64 -> V_83 [ 0 ] > 0 ) {
V_64 -> V_83 [ 0 ] -- ;
F_40 ( V_64 -> V_82 [ 0 ] , & V_21 ,
V_64 -> V_83 [ 0 ] ) ;
if ( V_21 . V_22 == V_128 -> V_27 &&
V_21 . type == V_76 &&
V_21 . V_33 == V_128 -> V_36 )
V_29 = 0 ;
}
if ( V_29 > 0 ) {
F_44 ( V_64 ) ;
V_111 = 0 ;
V_21 . V_22 = V_128 -> V_27 ;
V_21 . V_33 = V_128 -> V_36 ;
V_21 . type = V_76 ;
goto V_77;
}
} else {
V_81 = - V_175 ;
goto V_72;
}
}
V_66 = V_64 -> V_82 [ 0 ] ;
V_118 = F_77 ( V_66 , V_64 -> V_83 [ 0 ] ) ;
#ifdef F_81
if ( V_118 < sizeof( * V_117 ) ) {
V_29 = F_87 ( V_110 , V_35 -> V_37 -> V_62 ,
V_64 , ( T_2 ) - 1 , 0 ) ;
if ( V_29 < 0 ) {
V_81 = V_29 ;
goto V_72;
}
V_66 = V_64 -> V_82 [ 0 ] ;
V_118 = F_77 ( V_66 , V_64 -> V_83 [ 0 ] ) ;
}
#endif
F_30 ( V_118 < sizeof( * V_117 ) ) ;
V_117 = F_78 ( V_66 , V_64 -> V_83 [ 0 ] , struct V_116 ) ;
F_130 ( V_129 , V_66 , V_117 ) ;
F_95 ( V_66 ) ;
V_72:
F_50 ( V_64 ) ;
return V_81 ;
}
static int F_158 ( struct V_109 * V_110 ,
struct V_34 * V_35 ,
struct V_209 * V_128 ,
struct V_180 * V_129 ,
int V_210 )
{
int V_29 = 0 ;
struct V_218 * V_151 ;
struct V_67 V_212 ;
T_2 V_17 = 0 ;
T_2 V_213 = 0 ;
bool V_173 = F_76 ( V_35 -> V_37 ,
V_121 ) ;
V_151 = F_159 ( V_128 ) ;
F_160 ( V_128 , V_151 , V_128 -> V_214 ) ;
if ( V_128 -> type == V_165 )
V_17 = V_151 -> V_17 ;
V_213 = V_151 -> V_35 ;
V_212 . V_22 = V_128 -> V_27 ;
if ( V_173 ) {
V_212 . V_33 = V_151 -> V_167 ;
V_212 . type = V_85 ;
} else {
V_212 . V_33 = V_128 -> V_36 ;
V_212 . type = V_76 ;
}
F_30 ( V_128 -> V_132 != 1 ) ;
if ( V_128 -> V_214 == V_203 && V_210 ) {
F_30 ( ! V_129 || ! V_129 -> V_130 ) ;
V_29 = F_161 ( V_110 , V_35 ,
V_17 , V_213 ,
V_129 -> V_131 ,
& V_129 -> V_21 ,
V_151 -> V_167 , & V_212 ,
V_128 -> V_201 ) ;
} else if ( V_128 -> V_214 == V_203 ) {
V_29 = F_147 ( V_110 , V_35 , V_128 -> V_27 ,
V_128 -> V_36 , V_17 , V_213 ,
V_151 -> V_167 , 0 , 1 , V_128 -> V_201 ,
V_129 ) ;
} else if ( V_128 -> V_214 == V_215 ) {
V_29 = F_155 ( V_110 , V_35 , V_128 -> V_27 ,
V_128 -> V_36 , V_17 , V_213 ,
V_151 -> V_167 , 0 , 1 , V_129 ,
V_128 -> V_201 ) ;
} else {
F_83 () ;
}
return V_29 ;
}
static int F_162 ( struct V_109 * V_110 ,
struct V_34 * V_35 ,
struct V_209 * V_128 ,
struct V_180 * V_129 ,
int V_210 )
{
int V_29 = 0 ;
if ( V_110 -> V_217 ) {
if ( V_210 )
F_163 ( V_35 , V_128 -> V_27 ,
V_128 -> V_36 , 1 ) ;
return 0 ;
}
if ( F_164 ( V_128 ) ) {
struct V_113 * V_104 ;
F_30 ( V_129 ) ;
V_104 = F_165 ( V_128 ) ;
F_166 ( V_128 , V_104 , V_128 -> V_214 ) ;
if ( V_210 ) {
F_163 ( V_35 , V_128 -> V_27 ,
V_128 -> V_36 , 1 ) ;
if ( V_104 -> V_184 ) {
V_29 = F_167 ( V_110 , V_35 ,
V_128 -> V_27 ,
V_128 -> V_36 ) ;
}
}
return V_29 ;
}
if ( V_128 -> type == V_166 ||
V_128 -> type == V_165 )
V_29 = F_158 ( V_110 , V_35 , V_128 , V_129 ,
V_210 ) ;
else if ( V_128 -> type == V_155 ||
V_128 -> type == V_154 )
V_29 = F_151 ( V_110 , V_35 , V_128 , V_129 ,
V_210 ) ;
else
F_83 () ;
return V_29 ;
}
T_1 int F_168 ( struct V_109 * V_110 ,
struct V_34 * V_35 ,
unsigned long V_44 )
{
struct V_114 * V_115 ;
struct V_209 * V_151 ;
struct V_113 * V_219 = NULL ;
struct V_180 * V_129 ;
struct V_12 * V_37 = V_35 -> V_37 ;
T_6 V_32 = F_169 () ;
int V_29 ;
unsigned long V_8 = 0 ;
unsigned long V_220 = 0 ;
int V_221 = 0 ;
V_115 = & V_110 -> V_127 -> V_115 ;
while ( 1 ) {
if ( ! V_219 ) {
if ( V_8 >= V_44 )
break;
F_11 ( & V_115 -> V_52 ) ;
V_219 = F_170 ( V_110 ) ;
if ( ! V_219 ) {
F_13 ( & V_115 -> V_52 ) ;
break;
}
V_29 = F_171 ( V_110 , V_219 ) ;
F_13 ( & V_115 -> V_52 ) ;
if ( V_29 == - V_178 ) {
V_219 = NULL ;
V_8 ++ ;
continue;
}
}
F_11 ( & V_219 -> V_52 ) ;
F_172 ( V_110 , V_37 , V_115 ,
V_219 ) ;
V_151 = F_173 ( V_219 ) ;
if ( V_151 && V_151 -> V_222 &&
F_174 ( V_37 , V_115 , V_151 -> V_222 ) ) {
F_13 ( & V_219 -> V_52 ) ;
F_175 ( V_219 ) ;
F_11 ( & V_115 -> V_52 ) ;
V_219 -> V_223 = 0 ;
V_115 -> V_224 ++ ;
F_13 ( & V_115 -> V_52 ) ;
V_219 = NULL ;
F_47 () ;
V_8 ++ ;
continue;
}
V_221 = V_219 -> V_221 ;
V_219 -> V_221 = 0 ;
V_129 = V_219 -> V_129 ;
V_219 -> V_129 = NULL ;
if ( ! V_151 ) {
V_151 = & V_219 -> V_128 ;
if ( V_129 && V_221 ) {
F_176 ( V_129 ) ;
V_129 = NULL ;
}
if ( V_129 ) {
F_13 ( & V_219 -> V_52 ) ;
V_29 = F_157 ( V_110 , V_35 ,
V_151 , V_129 ) ;
F_176 ( V_129 ) ;
if ( V_29 ) {
if ( V_221 )
V_219 -> V_221 = 1 ;
V_219 -> V_223 = 0 ;
F_177 ( V_37 , L_1 , V_29 ) ;
F_175 ( V_219 ) ;
return V_29 ;
}
continue;
}
F_13 ( & V_219 -> V_52 ) ;
F_11 ( & V_115 -> V_52 ) ;
F_11 ( & V_219 -> V_52 ) ;
if ( F_178 ( & V_219 -> V_213 ) ||
V_219 -> V_129 ) {
F_13 ( & V_219 -> V_52 ) ;
F_13 ( & V_115 -> V_52 ) ;
continue;
}
V_151 -> V_225 = 0 ;
V_115 -> V_226 -- ;
F_179 ( & V_219 -> V_227 ,
& V_115 -> V_228 ) ;
F_13 ( & V_115 -> V_52 ) ;
} else {
V_220 ++ ;
V_151 -> V_225 = 0 ;
F_179 ( & V_151 -> V_15 , & V_219 -> V_213 ) ;
}
F_180 ( & V_115 -> V_229 ) ;
if ( ! F_164 ( V_151 ) ) {
switch ( V_151 -> V_214 ) {
case V_203 :
case V_230 :
V_219 -> V_128 . V_132 -= V_151 -> V_132 ;
break;
case V_215 :
V_219 -> V_128 . V_132 += V_151 -> V_132 ;
break;
default:
F_8 ( 1 ) ;
}
}
F_13 ( & V_219 -> V_52 ) ;
V_29 = F_162 ( V_110 , V_35 , V_151 , V_129 ,
V_221 ) ;
F_176 ( V_129 ) ;
if ( V_29 ) {
V_219 -> V_223 = 0 ;
F_175 ( V_219 ) ;
F_86 ( V_151 ) ;
F_177 ( V_37 , L_2 , V_29 ) ;
return V_29 ;
}
if ( F_164 ( V_151 ) ) {
F_175 ( V_219 ) ;
V_219 = NULL ;
}
F_86 ( V_151 ) ;
V_8 ++ ;
F_47 () ;
}
if ( V_220 > 0 ) {
T_2 V_231 = F_181 ( F_182 ( F_169 () , V_32 ) ) ;
T_2 V_232 ;
F_11 ( & V_115 -> V_52 ) ;
V_232 = V_37 -> V_233 * 3 + V_231 ;
V_232 = F_183 ( V_232 , 4 ) ;
V_37 -> V_233 = V_232 ;
F_13 ( & V_115 -> V_52 ) ;
}
return 0 ;
}
static T_2 F_184 ( struct V_234 * V_35 )
{
struct V_15 * V_30 = V_35 -> V_15 ;
struct V_209 * V_235 ;
int V_236 = 1 ;
T_2 V_237 ;
T_2 V_238 = 0 , V_69 = 0 ;
V_30 = F_178 ( V_35 ) ;
if ( V_30 ) {
V_235 = F_12 ( V_30 , struct V_209 , V_15 ) ;
V_238 = V_235 -> V_27 ;
}
V_30 = F_185 ( V_35 ) ;
if ( V_30 ) {
V_235 = F_12 ( V_30 , struct V_209 , V_15 ) ;
V_69 = V_235 -> V_27 ;
}
V_30 = V_35 -> V_15 ;
while ( V_30 ) {
V_235 = F_12 ( V_30 , struct V_209 , V_15 ) ;
F_8 ( ! V_235 -> V_225 ) ;
V_237 = V_235 -> V_27 ;
if ( V_236 )
V_30 = V_30 -> V_23 ;
else
V_30 = V_30 -> V_24 ;
V_236 = 1 - V_236 ;
}
return V_237 ;
}
static inline T_2 F_186 ( struct V_34 * V_35 , T_2 V_239 )
{
T_2 V_36 ;
V_36 = V_239 * ( sizeof( struct V_116 ) +
sizeof( struct V_163 ) ) ;
if ( ! F_76 ( V_35 -> V_37 , V_121 ) )
V_36 += V_239 * sizeof( struct V_138 ) ;
return F_183 ( V_36 , F_187 ( V_35 ) ) ;
}
int F_188 ( struct V_109 * V_110 ,
struct V_34 * V_35 )
{
struct V_240 * V_241 ;
T_2 V_226 = V_110 -> V_127 -> V_115 . V_224 ;
T_2 V_36 ;
int V_29 = 0 ;
V_36 = F_189 ( V_35 , 1 ) ;
V_226 = F_186 ( V_35 , V_226 ) ;
if ( V_226 > 1 )
V_36 += ( V_226 - 1 ) * V_35 -> V_87 ;
V_36 <<= 1 ;
V_241 = & V_35 -> V_37 -> V_242 ;
if ( V_241 -> V_105 -> V_108 )
V_36 <<= 1 ;
F_11 ( & V_241 -> V_52 ) ;
if ( V_241 -> V_10 <= V_36 )
V_29 = 1 ;
F_13 ( & V_241 -> V_52 ) ;
return V_29 ;
}
int F_190 ( struct V_109 * V_110 ,
struct V_34 * V_35 )
{
struct V_12 * V_37 = V_35 -> V_37 ;
T_2 V_229 =
F_191 ( & V_110 -> V_127 -> V_115 . V_229 ) ;
T_2 V_243 ;
T_2 V_244 ;
F_2 () ;
V_243 = V_37 -> V_233 ;
V_244 = V_229 * V_243 ;
if ( V_229 * V_243 >= V_245 )
return 1 ;
if ( V_244 >= V_245 / 2 )
return 2 ;
return F_188 ( V_110 , V_35 ) ;
}
static void F_192 ( struct V_60 * V_61 )
{
struct V_246 * V_247 ;
struct V_109 * V_110 ;
int V_29 ;
V_247 = F_32 ( V_61 , struct V_246 , V_61 ) ;
V_110 = F_193 ( V_247 -> V_35 ) ;
if ( F_194 ( V_110 ) ) {
V_247 -> error = F_195 ( V_110 ) ;
goto V_248;
}
V_110 -> V_249 = true ;
V_29 = F_196 ( V_110 , V_247 -> V_35 , V_247 -> V_8 ) ;
if ( V_29 )
V_247 -> error = V_29 ;
V_29 = F_197 ( V_110 , V_247 -> V_35 ) ;
if ( V_29 && ! V_247 -> error )
V_247 -> error = V_29 ;
V_248:
if ( V_247 -> V_249 )
F_198 ( & V_247 -> V_88 ) ;
else
F_9 ( V_247 ) ;
}
int F_199 ( struct V_34 * V_35 ,
unsigned long V_8 , int V_88 )
{
struct V_246 * V_247 ;
int V_29 ;
V_247 = F_200 ( sizeof( * V_247 ) , V_40 ) ;
if ( ! V_247 )
return - V_71 ;
V_247 -> V_35 = V_35 -> V_37 -> V_86 ;
V_247 -> V_8 = V_8 ;
V_247 -> error = 0 ;
if ( V_88 )
V_247 -> V_249 = 1 ;
else
V_247 -> V_249 = 0 ;
F_201 ( & V_247 -> V_88 ) ;
F_58 ( & V_247 -> V_61 , V_250 ,
F_192 , NULL , NULL ) ;
F_66 ( V_35 -> V_37 -> V_251 , & V_247 -> V_61 ) ;
if ( V_88 ) {
F_202 ( & V_247 -> V_88 ) ;
V_29 = V_247 -> error ;
F_9 ( V_247 ) ;
return V_29 ;
}
return 0 ;
}
int F_196 ( struct V_109 * V_110 ,
struct V_34 * V_35 , unsigned long V_8 )
{
struct V_15 * V_128 ;
struct V_114 * V_115 ;
struct V_113 * V_104 ;
int V_29 ;
int V_252 = V_8 == ( unsigned long ) - 1 ;
int V_253 = 0 ;
if ( V_110 -> V_217 )
return 0 ;
if ( V_35 == V_35 -> V_37 -> V_62 )
V_35 = V_35 -> V_37 -> V_86 ;
V_115 = & V_110 -> V_127 -> V_115 ;
if ( V_8 == 0 ) {
V_8 = F_191 ( & V_115 -> V_229 ) * 2 ;
V_253 = 1 ;
}
V_77:
#ifdef F_203
V_115 -> V_254 = F_184 ( & V_115 -> V_35 ) ;
#endif
V_29 = F_168 ( V_110 , V_35 , V_8 ) ;
if ( V_29 < 0 ) {
F_150 ( V_110 , V_35 , V_29 ) ;
return V_29 ;
}
if ( V_252 ) {
if ( ! F_204 ( & V_110 -> V_255 ) )
F_205 ( V_110 , V_35 ) ;
F_11 ( & V_115 -> V_52 ) ;
V_128 = F_178 ( & V_115 -> V_228 ) ;
if ( ! V_128 ) {
F_13 ( & V_115 -> V_52 ) ;
goto V_72;
}
V_8 = ( unsigned long ) - 1 ;
while ( V_128 ) {
V_104 = F_12 ( V_128 , struct V_113 ,
V_227 ) ;
if ( F_164 ( & V_104 -> V_128 ) ) {
struct V_209 * V_151 ;
V_151 = & V_104 -> V_128 ;
F_5 ( & V_151 -> V_112 ) ;
F_13 ( & V_115 -> V_52 ) ;
F_35 ( & V_104 -> V_78 ) ;
F_46 ( & V_104 -> V_78 ) ;
F_86 ( V_151 ) ;
F_47 () ;
goto V_77;
} else {
F_8 ( 1 ) ;
}
V_128 = F_206 ( V_128 ) ;
}
F_13 ( & V_115 -> V_52 ) ;
F_47 () ;
goto V_77;
}
V_72:
V_29 = F_207 ( V_110 , V_35 -> V_37 ) ;
if ( V_29 )
return V_29 ;
F_208 ( V_110 ) ;
return 0 ;
}
int F_209 ( struct V_109 * V_110 ,
struct V_34 * V_35 ,
T_2 V_27 , T_2 V_36 , T_2 V_7 ,
int V_167 , int V_184 )
{
struct V_180 * V_129 ;
int V_29 ;
V_129 = F_210 () ;
if ( ! V_129 )
return - V_71 ;
V_129 -> V_131 = V_7 ;
V_129 -> V_130 = 1 ;
V_129 -> V_216 = 0 ;
V_129 -> V_184 = V_184 ? 1 : 0 ;
V_129 -> V_167 = V_167 ;
V_29 = F_211 ( V_35 -> V_37 , V_110 , V_27 ,
V_36 , V_129 ) ;
if ( V_29 )
F_176 ( V_129 ) ;
return V_29 ;
}
static T_1 int F_212 ( struct V_109 * V_110 ,
struct V_34 * V_35 ,
struct V_63 * V_64 ,
T_2 V_22 , T_2 V_33 , T_2 V_27 )
{
struct V_113 * V_104 ;
struct V_209 * V_151 ;
struct V_211 * V_256 ;
struct V_114 * V_115 ;
struct V_15 * V_128 ;
int V_29 = 0 ;
V_115 = & V_110 -> V_127 -> V_115 ;
F_11 ( & V_115 -> V_52 ) ;
V_104 = F_84 ( V_110 , V_27 ) ;
if ( ! V_104 ) {
F_13 ( & V_115 -> V_52 ) ;
return 0 ;
}
if ( ! F_85 ( & V_104 -> V_78 ) ) {
F_5 ( & V_104 -> V_128 . V_112 ) ;
F_13 ( & V_115 -> V_52 ) ;
F_44 ( V_64 ) ;
F_35 ( & V_104 -> V_78 ) ;
F_46 ( & V_104 -> V_78 ) ;
F_86 ( & V_104 -> V_128 ) ;
return - V_178 ;
}
F_13 ( & V_115 -> V_52 ) ;
F_11 ( & V_104 -> V_52 ) ;
V_128 = F_178 ( & V_104 -> V_213 ) ;
while ( V_128 ) {
V_151 = F_12 ( V_128 , struct V_209 , V_15 ) ;
V_128 = F_206 ( V_128 ) ;
if ( V_151 -> type != V_155 ) {
V_29 = 1 ;
break;
}
V_256 = F_152 ( V_151 ) ;
if ( V_256 -> V_35 != V_35 -> V_257 . V_22 ||
V_256 -> V_22 != V_22 ||
V_256 -> V_33 != V_33 ) {
V_29 = 1 ;
break;
}
}
F_13 ( & V_104 -> V_52 ) ;
F_46 ( & V_104 -> V_78 ) ;
return V_29 ;
}
static T_1 int F_213 ( struct V_109 * V_110 ,
struct V_34 * V_35 ,
struct V_63 * V_64 ,
T_2 V_22 , T_2 V_33 , T_2 V_27 )
{
struct V_34 * V_62 = V_35 -> V_37 -> V_62 ;
struct V_65 * V_66 ;
struct V_150 * V_151 ;
struct V_163 * V_164 ;
struct V_116 * V_117 ;
struct V_67 V_21 ;
T_3 V_118 ;
int V_29 ;
V_21 . V_22 = V_27 ;
V_21 . V_33 = ( T_2 ) - 1 ;
V_21 . type = V_76 ;
V_29 = F_37 ( NULL , V_62 , & V_21 , V_64 , 0 , 0 ) ;
if ( V_29 < 0 )
goto V_72;
F_30 ( V_29 == 0 ) ;
V_29 = - V_153 ;
if ( V_64 -> V_83 [ 0 ] == 0 )
goto V_72;
V_64 -> V_83 [ 0 ] -- ;
V_66 = V_64 -> V_82 [ 0 ] ;
F_40 ( V_66 , & V_21 , V_64 -> V_83 [ 0 ] ) ;
if ( V_21 . V_22 != V_27 || V_21 . type != V_76 )
goto V_72;
V_29 = 1 ;
V_118 = F_77 ( V_66 , V_64 -> V_83 [ 0 ] ) ;
#ifdef F_81
if ( V_118 < sizeof( * V_117 ) ) {
F_8 ( V_118 != sizeof( struct V_124 ) ) ;
goto V_72;
}
#endif
V_117 = F_78 ( V_66 , V_64 -> V_83 [ 0 ] , struct V_116 ) ;
if ( V_118 != sizeof( * V_117 ) +
F_125 ( V_155 ) )
goto V_72;
if ( F_214 ( V_66 , V_117 ) <=
F_215 ( & V_35 -> V_258 ) )
goto V_72;
V_164 = (struct V_163 * ) ( V_117 + 1 ) ;
if ( F_119 ( V_66 , V_164 ) !=
V_155 )
goto V_72;
V_151 = (struct V_150 * ) ( & V_164 -> V_33 ) ;
if ( F_79 ( V_66 , V_117 ) !=
F_113 ( V_66 , V_151 ) ||
F_100 ( V_66 , V_151 ) !=
V_35 -> V_257 . V_22 ||
F_101 ( V_66 , V_151 ) != V_22 ||
F_102 ( V_66 , V_151 ) != V_33 )
goto V_72;
V_29 = 0 ;
V_72:
return V_29 ;
}
int F_216 ( struct V_109 * V_110 ,
struct V_34 * V_35 ,
T_2 V_22 , T_2 V_33 , T_2 V_27 )
{
struct V_63 * V_64 ;
int V_29 ;
int V_259 ;
V_64 = F_33 () ;
if ( ! V_64 )
return - V_153 ;
do {
V_29 = F_213 ( V_110 , V_35 , V_64 , V_22 ,
V_33 , V_27 ) ;
if ( V_29 && V_29 != - V_153 )
goto V_72;
V_259 = F_212 ( V_110 , V_35 , V_64 , V_22 ,
V_33 , V_27 ) ;
} while ( V_259 == - V_178 );
if ( V_259 && V_259 != - V_153 ) {
V_29 = V_259 ;
goto V_72;
}
if ( V_29 != - V_153 || V_259 != - V_153 )
V_29 = 0 ;
V_72:
F_50 ( V_64 ) ;
if ( V_35 -> V_257 . V_22 == V_260 )
F_8 ( V_29 > 0 ) ;
return V_29 ;
}
static int F_217 ( struct V_109 * V_110 ,
struct V_34 * V_35 ,
struct V_65 * V_261 ,
int V_262 , int V_263 )
{
T_2 V_27 ;
T_2 V_36 ;
T_2 V_17 ;
T_2 V_213 ;
T_3 V_70 ;
struct V_67 V_21 ;
struct V_264 * V_265 ;
int V_43 ;
int V_167 ;
int V_29 = 0 ;
int (* F_218)( struct V_109 * , struct V_34 * ,
T_2 , T_2 , T_2 , T_2 , T_2 , T_2 , int );
if ( F_219 ( V_35 ) )
return 0 ;
V_213 = F_220 ( V_261 ) ;
V_70 = F_38 ( V_261 ) ;
V_167 = F_221 ( V_261 ) ;
if ( ! F_222 ( V_266 , & V_35 -> V_267 ) && V_167 == 0 )
return 0 ;
if ( V_263 )
F_218 = F_144 ;
else
F_218 = V_268 ;
if ( V_262 )
V_17 = V_261 -> V_32 ;
else
V_17 = 0 ;
for ( V_43 = 0 ; V_43 < V_70 ; V_43 ++ ) {
if ( V_167 == 0 ) {
F_40 ( V_261 , & V_21 , V_43 ) ;
if ( V_21 . type != V_269 )
continue;
V_265 = F_78 ( V_261 , V_43 ,
struct V_264 ) ;
if ( F_223 ( V_261 , V_265 ) ==
V_270 )
continue;
V_27 = F_224 ( V_261 , V_265 ) ;
if ( V_27 == 0 )
continue;
V_36 = F_225 ( V_261 , V_265 ) ;
V_21 . V_33 -= F_226 ( V_261 , V_265 ) ;
V_29 = F_218 ( V_110 , V_35 , V_27 , V_36 ,
V_17 , V_213 , V_21 . V_22 ,
V_21 . V_33 , 1 ) ;
if ( V_29 )
goto V_156;
} else {
V_27 = F_227 ( V_261 , V_43 ) ;
V_36 = V_35 -> V_87 ;
V_29 = F_218 ( V_110 , V_35 , V_27 , V_36 ,
V_17 , V_213 , V_167 - 1 , 0 ,
1 ) ;
if ( V_29 )
goto V_156;
}
}
return 0 ;
V_156:
return V_29 ;
}
int F_228 ( struct V_109 * V_110 , struct V_34 * V_35 ,
struct V_65 * V_261 , int V_262 )
{
return F_217 ( V_110 , V_35 , V_261 , V_262 , 1 ) ;
}
int F_229 ( struct V_109 * V_110 , struct V_34 * V_35 ,
struct V_65 * V_261 , int V_262 )
{
return F_217 ( V_110 , V_35 , V_261 , V_262 , 0 ) ;
}
static int F_230 ( struct V_109 * V_110 ,
struct V_34 * V_35 ,
struct V_63 * V_64 ,
struct V_1 * V_2 )
{
int V_29 ;
struct V_34 * V_62 = V_35 -> V_37 -> V_62 ;
unsigned long V_139 ;
struct V_65 * V_66 ;
V_29 = F_37 ( V_110 , V_62 , & V_2 -> V_21 , V_64 , 0 , 1 ) ;
if ( V_29 ) {
if ( V_29 > 0 )
V_29 = - V_153 ;
goto V_156;
}
V_66 = V_64 -> V_82 [ 0 ] ;
V_139 = F_231 ( V_66 , V_64 -> V_83 [ 0 ] ) ;
F_232 ( V_66 , & V_2 -> V_135 , V_139 , sizeof( V_2 -> V_135 ) ) ;
F_95 ( V_66 ) ;
F_44 ( V_64 ) ;
V_156:
if ( V_29 )
F_150 ( V_110 , V_35 , V_29 ) ;
return V_29 ;
}
static struct V_1 *
F_233 ( struct V_34 * V_35 ,
struct V_1 * V_2 )
{
struct V_15 * V_128 ;
F_11 ( & V_35 -> V_37 -> V_18 ) ;
if ( F_234 ( & V_2 -> V_20 ) ) {
const T_2 V_271 = V_2 -> V_21 . V_22 + V_2 -> V_21 . V_33 ;
F_13 ( & V_35 -> V_37 -> V_18 ) ;
F_6 ( V_2 ) ;
V_2 = F_67 ( V_35 -> V_37 ,
V_271 ) ;
return V_2 ;
}
V_128 = F_206 ( & V_2 -> V_20 ) ;
F_6 ( V_2 ) ;
if ( V_128 ) {
V_2 = F_12 ( V_128 , struct V_1 ,
V_20 ) ;
F_4 ( V_2 ) ;
} else
V_2 = NULL ;
F_13 ( & V_35 -> V_37 -> V_18 ) ;
return V_2 ;
}
static int F_235 ( struct V_1 * V_14 ,
struct V_109 * V_110 ,
struct V_63 * V_64 )
{
struct V_34 * V_35 = V_14 -> V_37 -> V_86 ;
struct V_272 * V_272 = NULL ;
T_2 V_273 = 0 ;
int V_274 = V_275 ;
int V_276 = 0 ;
int V_277 = 0 ;
int V_29 = 0 ;
if ( V_14 -> V_21 . V_33 < ( 100 * 1024 * 1024 ) ) {
F_11 ( & V_14 -> V_52 ) ;
V_14 -> V_278 = V_279 ;
F_13 ( & V_14 -> V_52 ) ;
return 0 ;
}
V_77:
V_272 = F_236 ( V_35 , V_14 , V_64 ) ;
if ( F_194 ( V_272 ) && F_195 ( V_272 ) != - V_153 ) {
V_29 = F_195 ( V_272 ) ;
F_44 ( V_64 ) ;
goto V_72;
}
if ( F_194 ( V_272 ) ) {
F_30 ( V_277 ) ;
V_277 ++ ;
if ( V_14 -> V_280 )
goto V_123;
V_29 = F_237 ( V_35 , V_110 , V_14 , V_64 ) ;
if ( V_29 )
goto V_123;
goto V_77;
}
if ( V_14 -> V_281 == V_110 -> V_282 &&
F_238 ( V_272 ) ) {
V_274 = V_283 ;
goto V_284;
}
F_239 ( V_272 ) -> V_285 = 0 ;
V_29 = F_240 ( V_110 , V_35 , V_272 ) ;
F_8 ( V_29 ) ;
if ( F_238 ( V_272 ) > 0 ) {
V_29 = F_241 ( V_35 ,
& V_35 -> V_37 -> V_242 ) ;
if ( V_29 )
goto V_284;
V_29 = F_242 ( V_35 , V_110 , V_272 ) ;
if ( V_29 )
goto V_284;
}
F_11 ( & V_14 -> V_52 ) ;
if ( V_14 -> V_3 != V_4 ||
! F_243 ( V_35 , V_286 ) ||
V_14 -> V_287 ) {
V_274 = V_279 ;
F_13 ( & V_14 -> V_52 ) ;
goto V_284;
}
F_13 ( & V_14 -> V_52 ) ;
V_276 = ( int ) F_183 ( V_14 -> V_21 . V_33 , 256 * 1024 * 1024 ) ;
if ( ! V_276 )
V_276 = 1 ;
V_276 *= 16 ;
V_276 *= V_288 ;
V_29 = F_244 ( V_272 , V_276 ) ;
if ( V_29 )
goto V_284;
V_29 = F_245 ( V_272 , V_110 , 0 , 0 , V_276 ,
V_276 , V_276 ,
& V_273 ) ;
if ( ! V_29 )
V_274 = V_283 ;
F_246 ( V_272 , V_276 ) ;
V_284:
F_247 ( V_272 ) ;
V_123:
F_44 ( V_64 ) ;
V_72:
F_11 ( & V_14 -> V_52 ) ;
if ( ! V_29 && V_274 == V_283 )
V_14 -> V_281 = V_110 -> V_282 ;
V_14 -> V_278 = V_274 ;
F_13 ( & V_14 -> V_52 ) ;
return V_29 ;
}
int F_248 ( struct V_109 * V_110 ,
struct V_34 * V_35 )
{
struct V_1 * V_2 ;
int V_81 = 0 ;
struct V_63 * V_64 ;
T_2 V_69 = 0 ;
V_64 = F_33 () ;
if ( ! V_64 )
return - V_71 ;
V_77:
while ( 1 ) {
V_2 = F_67 ( V_35 -> V_37 , V_69 ) ;
while ( V_2 ) {
if ( V_2 -> V_278 == V_289 )
break;
V_2 = F_233 ( V_35 , V_2 ) ;
}
if ( ! V_2 ) {
if ( V_69 == 0 )
break;
V_69 = 0 ;
continue;
}
V_81 = F_235 ( V_2 , V_110 , V_64 ) ;
V_69 = V_2 -> V_21 . V_22 + V_2 -> V_21 . V_33 ;
F_6 ( V_2 ) ;
}
while ( 1 ) {
if ( V_69 == 0 ) {
V_81 = F_196 ( V_110 , V_35 ,
( unsigned long ) - 1 ) ;
if ( V_81 )
goto V_72;
}
V_2 = F_67 ( V_35 -> V_37 , V_69 ) ;
while ( V_2 ) {
if ( V_2 -> V_278 == V_289 ) {
F_6 ( V_2 ) ;
goto V_77;
}
if ( V_2 -> V_290 )
break;
V_2 = F_233 ( V_35 , V_2 ) ;
}
if ( ! V_2 ) {
if ( V_69 == 0 )
break;
V_69 = 0 ;
continue;
}
if ( V_2 -> V_278 == V_283 )
V_2 -> V_278 = V_291 ;
V_2 -> V_290 = 0 ;
V_69 = V_2 -> V_21 . V_22 + V_2 -> V_21 . V_33 ;
V_81 = F_230 ( V_110 , V_35 , V_64 , V_2 ) ;
F_6 ( V_2 ) ;
if ( V_81 )
goto V_72;
}
while ( 1 ) {
if ( V_69 == 0 ) {
V_81 = F_196 ( V_110 , V_35 ,
( unsigned long ) - 1 ) ;
if ( V_81 )
goto V_72;
}
V_2 = F_67 ( V_35 -> V_37 , V_69 ) ;
while ( V_2 ) {
if ( V_2 -> V_290 ) {
F_6 ( V_2 ) ;
goto V_77;
}
if ( V_2 -> V_278 == V_291 )
break;
V_2 = F_233 ( V_35 , V_2 ) ;
}
if ( ! V_2 ) {
if ( V_69 == 0 )
break;
V_69 = 0 ;
continue;
}
V_81 = F_249 ( V_35 , V_110 , V_2 , V_64 ) ;
if ( ! V_81 && V_2 -> V_278 == V_291 )
V_2 -> V_278 = V_279 ;
V_69 = V_2 -> V_21 . V_22 + V_2 -> V_21 . V_33 ;
F_6 ( V_2 ) ;
}
V_72:
F_50 ( V_64 ) ;
return V_81 ;
}
int F_250 ( struct V_34 * V_35 , T_2 V_27 )
{
struct V_1 * V_14 ;
int V_292 = 0 ;
V_14 = F_68 ( V_35 -> V_37 , V_27 ) ;
if ( ! V_14 || V_14 -> V_280 )
V_292 = 1 ;
if ( V_14 )
F_6 ( V_14 ) ;
return V_292 ;
}
static const char * F_251 ( T_2 V_7 )
{
switch ( V_7 ) {
case V_293 | V_294 :
return L_3 ;
case V_293 :
return L_4 ;
case V_294 :
return L_5 ;
case V_295 :
return L_6 ;
default:
F_8 ( 1 ) ;
return L_7 ;
} ;
}
static int F_252 ( struct V_12 * V_13 , T_2 V_7 ,
T_2 V_296 , T_2 V_297 ,
struct V_102 * * V_105 )
{
struct V_102 * V_106 ;
int V_43 ;
int V_298 ;
int V_29 ;
if ( V_7 & ( V_299 | V_300 |
V_301 ) )
V_298 = 2 ;
else
V_298 = 1 ;
V_106 = F_69 ( V_13 , V_7 ) ;
if ( V_106 ) {
F_11 ( & V_106 -> V_52 ) ;
V_106 -> V_296 += V_296 ;
V_106 -> V_302 += V_296 * V_298 ;
V_106 -> V_297 += V_297 ;
V_106 -> V_303 += V_297 * V_298 ;
V_106 -> V_108 = 0 ;
F_13 ( & V_106 -> V_52 ) ;
* V_105 = V_106 ;
return 0 ;
}
V_106 = F_53 ( sizeof( * V_106 ) , V_40 ) ;
if ( ! V_106 )
return - V_71 ;
V_29 = F_253 ( & V_106 -> V_304 , 0 , V_305 ) ;
if ( V_29 ) {
F_9 ( V_106 ) ;
return V_29 ;
}
for ( V_43 = 0 ; V_43 < V_306 ; V_43 ++ )
F_54 ( & V_106 -> V_307 [ V_43 ] ) ;
F_254 ( & V_106 -> V_308 ) ;
F_255 ( & V_106 -> V_52 ) ;
V_106 -> V_7 = V_7 & V_107 ;
V_106 -> V_296 = V_296 ;
V_106 -> V_302 = V_296 * V_298 ;
V_106 -> V_297 = V_297 ;
V_106 -> V_303 = V_297 * V_298 ;
V_106 -> V_309 = 0 ;
V_106 -> V_310 = 0 ;
V_106 -> V_311 = 0 ;
V_106 -> V_312 = 0 ;
V_106 -> V_108 = 0 ;
V_106 -> V_313 = V_314 ;
V_106 -> V_315 = 0 ;
V_106 -> V_316 = 0 ;
F_56 ( & V_106 -> V_88 ) ;
F_54 ( & V_106 -> V_317 ) ;
V_29 = F_256 ( & V_106 -> V_318 , & V_319 ,
V_13 -> V_320 , L_8 ,
F_251 ( V_106 -> V_7 ) ) ;
if ( V_29 ) {
F_9 ( V_106 ) ;
return V_29 ;
}
* V_105 = V_106 ;
F_257 ( & V_106 -> V_90 , & V_13 -> V_105 ) ;
if ( V_7 & V_294 )
V_13 -> V_321 = V_106 ;
return V_29 ;
}
static void F_258 ( struct V_12 * V_37 , T_2 V_7 )
{
T_2 V_322 = F_259 ( V_7 ) &
V_323 ;
F_260 ( & V_37 -> V_324 ) ;
if ( V_7 & V_294 )
V_37 -> V_325 |= V_322 ;
if ( V_7 & V_293 )
V_37 -> V_326 |= V_322 ;
if ( V_7 & V_295 )
V_37 -> V_327 |= V_322 ;
F_261 ( & V_37 -> V_324 ) ;
}
static T_2 F_262 ( struct V_12 * V_37 , T_2 V_7 )
{
struct V_328 * V_329 = V_37 -> V_330 ;
T_2 V_331 = 0 ;
if ( ! V_329 )
return 0 ;
if ( V_7 & V_294 &&
V_329 -> V_332 . V_7 & V_333 ) {
V_331 = V_294 | V_329 -> V_332 . V_331 ;
} else if ( V_7 & V_295 &&
V_329 -> V_334 . V_7 & V_333 ) {
V_331 = V_295 | V_329 -> V_334 . V_331 ;
} else if ( V_7 & V_293 &&
V_329 -> V_335 . V_7 & V_333 ) {
V_331 = V_293 | V_329 -> V_335 . V_331 ;
}
return V_331 ;
}
static T_2 F_263 ( struct V_34 * V_35 , T_2 V_7 )
{
T_2 V_336 = V_35 -> V_37 -> V_337 -> V_338 ;
T_2 V_331 ;
T_2 V_339 ;
F_11 ( & V_35 -> V_37 -> V_340 ) ;
V_331 = F_262 ( V_35 -> V_37 , V_7 ) ;
if ( V_331 ) {
if ( ( V_7 & V_331 ) & V_323 ) {
F_13 ( & V_35 -> V_37 -> V_340 ) ;
return F_264 ( V_331 ) ;
}
}
F_13 ( & V_35 -> V_37 -> V_340 ) ;
if ( V_336 == 1 )
V_7 &= ~ ( V_300 | V_341 |
V_342 ) ;
if ( V_336 < 3 )
V_7 &= ~ V_343 ;
if ( V_336 < 4 )
V_7 &= ~ V_301 ;
V_339 = V_7 & ( V_299 | V_341 |
V_300 | V_342 |
V_343 | V_301 ) ;
V_7 &= ~ V_339 ;
if ( V_339 & V_343 )
V_339 = V_343 ;
else if ( V_339 & V_342 )
V_339 = V_342 ;
else if ( V_339 & V_301 )
V_339 = V_301 ;
else if ( V_339 & V_300 )
V_339 = V_300 ;
else if ( V_339 & V_341 )
V_339 = V_341 ;
return F_264 ( V_7 | V_339 ) ;
}
static T_2 F_265 ( struct V_34 * V_35 , T_2 V_344 )
{
unsigned V_222 ;
T_2 V_7 ;
do {
V_7 = V_344 ;
V_222 = F_266 ( & V_35 -> V_37 -> V_324 ) ;
if ( V_7 & V_294 )
V_7 |= V_35 -> V_37 -> V_325 ;
else if ( V_7 & V_295 )
V_7 |= V_35 -> V_37 -> V_327 ;
else if ( V_7 & V_293 )
V_7 |= V_35 -> V_37 -> V_326 ;
} while ( F_267 ( & V_35 -> V_37 -> V_324 , V_222 ) );
return F_263 ( V_35 , V_7 ) ;
}
T_2 F_268 ( struct V_34 * V_35 , int V_332 )
{
T_2 V_7 ;
T_2 V_29 ;
if ( V_332 )
V_7 = V_294 ;
else if ( V_35 == V_35 -> V_37 -> V_345 )
V_7 = V_295 ;
else
V_7 = V_293 ;
V_29 = F_265 ( V_35 , V_7 ) ;
return V_29 ;
}
int F_244 ( struct V_272 * V_272 , T_2 V_346 )
{
struct V_102 * V_321 ;
struct V_34 * V_35 = F_239 ( V_272 ) -> V_35 ;
struct V_12 * V_37 = V_35 -> V_37 ;
T_2 V_347 ;
int V_29 = 0 , V_348 = 0 , V_349 = 1 ;
V_346 = F_269 ( V_346 , V_35 -> V_350 ) ;
if ( F_270 ( V_272 ) ) {
V_348 = 1 ;
ASSERT ( V_351 -> V_352 ) ;
}
V_321 = V_37 -> V_321 ;
if ( ! V_321 )
goto V_353;
V_77:
F_11 ( & V_321 -> V_52 ) ;
V_347 = V_321 -> V_297 + V_321 -> V_310 +
V_321 -> V_309 + V_321 -> V_311 +
V_321 -> V_312 ;
if ( V_347 + V_346 > V_321 -> V_296 ) {
struct V_109 * V_110 ;
if ( ! V_321 -> V_108 && V_349 ) {
T_2 V_354 ;
V_321 -> V_313 = V_355 ;
F_13 ( & V_321 -> V_52 ) ;
V_353:
V_354 = F_268 ( V_35 , 1 ) ;
V_110 = F_193 ( V_35 ) ;
if ( F_194 ( V_110 ) )
return F_195 ( V_110 ) ;
V_29 = F_271 ( V_110 , V_35 -> V_37 -> V_62 ,
V_354 ,
V_314 ) ;
F_197 ( V_110 , V_35 ) ;
if ( V_29 < 0 ) {
if ( V_29 != - V_356 )
return V_29 ;
else
goto V_357;
}
if ( ! V_321 )
V_321 = V_37 -> V_321 ;
goto V_77;
}
if ( F_272 ( & V_321 -> V_304 ,
V_346 ) < 0 )
V_348 = 1 ;
F_13 ( & V_321 -> V_52 ) ;
V_357:
if ( ! V_348 &&
! F_191 ( & V_35 -> V_37 -> V_358 ) ) {
V_348 = 1 ;
V_110 = F_193 ( V_35 ) ;
if ( F_194 ( V_110 ) )
return F_195 ( V_110 ) ;
V_29 = F_273 ( V_110 , V_35 ) ;
if ( V_29 )
return V_29 ;
goto V_77;
}
F_274 ( V_35 -> V_37 ,
L_9 ,
V_321 -> V_7 , V_346 , 1 ) ;
return - V_356 ;
}
V_321 -> V_312 += V_346 ;
F_274 ( V_35 -> V_37 , L_10 ,
V_321 -> V_7 , V_346 , 1 ) ;
F_13 ( & V_321 -> V_52 ) ;
return 0 ;
}
void F_246 ( struct V_272 * V_272 , T_2 V_346 )
{
struct V_34 * V_35 = F_239 ( V_272 ) -> V_35 ;
struct V_102 * V_321 ;
V_346 = F_269 ( V_346 , V_35 -> V_350 ) ;
V_321 = V_35 -> V_37 -> V_321 ;
F_11 ( & V_321 -> V_52 ) ;
F_8 ( V_321 -> V_312 < V_346 ) ;
V_321 -> V_312 -= V_346 ;
F_274 ( V_35 -> V_37 , L_10 ,
V_321 -> V_7 , V_346 , 0 ) ;
F_13 ( & V_321 -> V_52 ) ;
}
static void F_275 ( struct V_12 * V_13 )
{
struct V_103 * V_104 = & V_13 -> V_105 ;
struct V_102 * V_106 ;
F_70 () ;
F_71 (found, head, list) {
if ( V_106 -> V_7 & V_293 )
V_106 -> V_313 = V_355 ;
}
F_72 () ;
}
static inline T_2 F_276 ( struct V_240 * V_359 )
{
return ( V_359 -> V_56 << 1 ) ;
}
static int F_277 ( struct V_34 * V_35 ,
struct V_102 * V_360 , int V_361 )
{
struct V_240 * V_241 = & V_35 -> V_37 -> V_242 ;
T_2 V_36 = V_360 -> V_296 - V_360 -> V_311 ;
T_2 V_362 = V_360 -> V_297 + V_360 -> V_310 ;
T_2 V_363 ;
if ( V_361 == V_355 )
return 1 ;
if ( V_360 -> V_7 & V_293 )
V_362 += F_276 ( V_241 ) ;
if ( V_361 == V_364 ) {
V_363 = F_278 ( V_35 -> V_37 -> V_365 ) ;
V_363 = F_34 ( T_2 , 64 * 1024 * 1024 ,
F_279 ( V_363 , 1 ) ) ;
if ( V_36 - V_362 < V_363 )
return 1 ;
}
if ( V_362 + 2 * 1024 * 1024 < F_280 ( V_36 , 8 ) )
return 0 ;
return 1 ;
}
static T_2 F_281 ( struct V_34 * V_35 , T_2 type )
{
T_2 V_366 ;
if ( type & ( V_301 |
V_341 |
V_342 |
V_343 ) )
V_366 = V_35 -> V_37 -> V_337 -> V_338 ;
else if ( type & V_300 )
V_366 = 2 ;
else
V_366 = 1 ;
return F_189 ( V_35 , V_366 + 1 ) ;
}
static void F_282 ( struct V_109 * V_110 ,
struct V_34 * V_35 , T_2 type )
{
struct V_102 * V_13 ;
T_2 V_367 ;
T_2 V_363 ;
V_13 = F_69 ( V_35 -> V_37 , V_295 ) ;
F_11 ( & V_13 -> V_52 ) ;
V_367 = V_13 -> V_296 - V_13 -> V_297 - V_13 -> V_309 -
V_13 -> V_310 - V_13 -> V_311 ;
F_13 ( & V_13 -> V_52 ) ;
V_363 = F_281 ( V_35 , type ) ;
if ( V_367 < V_363 && F_243 ( V_35 , V_368 ) ) {
F_283 ( V_35 -> V_37 , L_11 ,
V_367 , V_363 , type ) ;
F_284 ( V_13 , 0 , 0 ) ;
}
if ( V_367 < V_363 ) {
T_2 V_7 ;
V_7 = F_268 ( V_35 -> V_37 -> V_345 , 0 ) ;
F_285 ( V_110 , V_35 , V_7 ) ;
}
}
static int F_271 ( struct V_109 * V_110 ,
struct V_34 * V_62 , T_2 V_7 , int V_361 )
{
struct V_102 * V_105 ;
struct V_12 * V_37 = V_62 -> V_37 ;
int V_369 = 0 ;
int V_29 = 0 ;
if ( V_110 -> V_370 )
return - V_356 ;
V_105 = F_69 ( V_62 -> V_37 , V_7 ) ;
if ( ! V_105 ) {
V_29 = F_252 ( V_62 -> V_37 , V_7 ,
0 , 0 , & V_105 ) ;
F_30 ( V_29 ) ;
}
F_30 ( ! V_105 ) ;
V_77:
F_11 ( & V_105 -> V_52 ) ;
if ( V_361 < V_105 -> V_313 )
V_361 = V_105 -> V_313 ;
if ( V_105 -> V_108 ) {
if ( F_277 ( V_62 , V_105 , V_361 ) )
V_29 = - V_356 ;
else
V_29 = 0 ;
F_13 ( & V_105 -> V_52 ) ;
return V_29 ;
}
if ( ! F_277 ( V_62 , V_105 , V_361 ) ) {
F_13 ( & V_105 -> V_52 ) ;
return 0 ;
} else if ( V_105 -> V_315 ) {
V_369 = 1 ;
} else {
V_105 -> V_315 = 1 ;
}
F_13 ( & V_105 -> V_52 ) ;
F_35 ( & V_37 -> V_371 ) ;
if ( V_369 ) {
F_46 ( & V_37 -> V_371 ) ;
V_369 = 0 ;
goto V_77;
}
V_110 -> V_370 = true ;
if ( F_286 ( V_105 ) )
V_7 |= ( V_294 | V_293 ) ;
if ( V_7 & V_294 && V_37 -> V_372 ) {
V_37 -> V_373 ++ ;
if ( ! ( V_37 -> V_373 %
V_37 -> V_372 ) )
F_275 ( V_37 ) ;
}
F_282 ( V_110 , V_62 , V_7 ) ;
V_29 = F_285 ( V_110 , V_62 , V_7 ) ;
V_110 -> V_370 = false ;
F_11 ( & V_105 -> V_52 ) ;
if ( V_29 < 0 && V_29 != - V_356 )
goto V_72;
if ( V_29 )
V_105 -> V_108 = 1 ;
else
V_29 = 1 ;
V_105 -> V_313 = V_314 ;
V_72:
V_105 -> V_315 = 0 ;
F_13 ( & V_105 -> V_52 ) ;
F_46 ( & V_37 -> V_371 ) ;
return V_29 ;
}
static int F_287 ( struct V_34 * V_35 ,
struct V_102 * V_105 , T_2 V_346 ,
enum V_374 V_316 )
{
struct V_240 * V_241 = & V_35 -> V_37 -> V_242 ;
T_2 V_375 = F_268 ( V_35 , 0 ) ;
T_2 V_376 ;
T_2 V_377 ;
T_2 V_347 ;
V_347 = V_105 -> V_297 + V_105 -> V_310 +
V_105 -> V_309 + V_105 -> V_311 ;
F_11 ( & V_241 -> V_52 ) ;
V_376 = F_276 ( V_241 ) ;
F_13 ( & V_241 -> V_52 ) ;
if ( V_347 + V_376 >= V_105 -> V_296 )
return 0 ;
V_347 += V_105 -> V_312 ;
F_11 ( & V_35 -> V_37 -> V_378 ) ;
V_377 = V_35 -> V_37 -> V_379 ;
F_13 ( & V_35 -> V_37 -> V_378 ) ;
if ( V_375 & ( V_299 |
V_300 |
V_301 ) )
V_377 >>= 1 ;
if ( V_316 == V_380 )
V_377 >>= 3 ;
else
V_377 >>= 1 ;
if ( V_347 + V_346 < V_105 -> V_296 + V_377 )
return 1 ;
return 0 ;
}
static void F_288 ( struct V_34 * V_35 ,
unsigned long V_381 , int V_382 )
{
struct V_383 * V_384 = V_35 -> V_37 -> V_384 ;
if ( F_289 ( & V_384 -> V_385 ) ) {
F_290 ( V_384 , V_381 , V_386 ) ;
F_45 ( & V_384 -> V_385 ) ;
} else {
F_291 ( V_35 -> V_37 , 0 , V_382 ) ;
if ( ! V_351 -> V_352 )
F_292 ( V_35 -> V_37 , V_382 ) ;
}
}
static inline int F_293 ( struct V_34 * V_35 , T_2 V_387 )
{
T_2 V_346 ;
int V_44 ;
V_346 = F_189 ( V_35 , 1 ) ;
V_44 = ( int ) F_183 ( V_387 , V_346 ) ;
if ( ! V_44 )
V_44 = 1 ;
return V_44 ;
}
static void F_294 ( struct V_34 * V_35 , T_2 V_387 , T_2 V_388 ,
bool V_389 )
{
struct V_240 * V_390 ;
struct V_102 * V_105 ;
struct V_109 * V_110 ;
T_2 V_287 ;
T_2 V_391 ;
long V_392 ;
unsigned long V_381 ;
int V_393 ;
int V_394 ;
enum V_374 V_316 ;
V_394 = F_293 ( V_35 , V_387 ) ;
V_387 = V_394 * V_395 ;
V_110 = (struct V_109 * ) V_351 -> V_352 ;
V_390 = & V_35 -> V_37 -> V_396 ;
V_105 = V_390 -> V_105 ;
V_287 = F_295 (
& V_35 -> V_37 -> V_287 ) ;
if ( V_287 == 0 ) {
if ( V_110 )
return;
if ( V_389 )
F_292 ( V_35 -> V_37 , V_394 ) ;
return;
}
V_393 = 0 ;
while ( V_287 && V_393 < 3 ) {
V_391 = F_296 ( V_287 , V_387 ) ;
V_381 = V_391 >> V_397 ;
F_288 ( V_35 , V_381 , V_394 ) ;
V_391 = F_191 ( & V_35 -> V_37 -> V_398 ) ;
if ( ! V_391 )
goto V_399;
if ( V_391 <= V_381 )
V_391 = 0 ;
else
V_391 -= V_381 ;
F_297 ( V_35 -> V_37 -> V_400 ,
F_191 ( & V_35 -> V_37 -> V_398 ) <=
( int ) V_391 ) ;
V_399:
if ( ! V_110 )
V_316 = V_380 ;
else
V_316 = V_401 ;
F_11 ( & V_105 -> V_52 ) ;
if ( F_287 ( V_35 , V_105 , V_388 , V_316 ) ) {
F_13 ( & V_105 -> V_52 ) ;
break;
}
F_13 ( & V_105 -> V_52 ) ;
V_393 ++ ;
if ( V_389 && ! V_110 ) {
F_292 ( V_35 -> V_37 , V_394 ) ;
} else {
V_392 = F_298 ( 1 ) ;
if ( V_392 )
break;
}
V_287 = F_295 (
& V_35 -> V_37 -> V_287 ) ;
}
}
static int F_299 ( struct V_34 * V_35 ,
struct V_102 * V_105 ,
T_2 V_346 , int V_361 )
{
struct V_240 * V_402 = & V_35 -> V_37 -> V_403 ;
struct V_109 * V_110 ;
V_110 = (struct V_109 * ) V_351 -> V_352 ;
if ( V_110 )
return - V_178 ;
if ( V_361 )
goto V_404;
if ( F_272 ( & V_105 -> V_304 ,
V_346 ) >= 0 )
goto V_404;
if ( V_105 != V_402 -> V_105 )
return - V_356 ;
F_11 ( & V_402 -> V_52 ) ;
if ( F_272 ( & V_105 -> V_304 ,
V_346 - V_402 -> V_56 ) >= 0 ) {
F_13 ( & V_402 -> V_52 ) ;
return - V_356 ;
}
F_13 ( & V_402 -> V_52 ) ;
V_404:
V_110 = F_193 ( V_35 ) ;
if ( F_194 ( V_110 ) )
return - V_356 ;
return F_273 ( V_110 , V_35 ) ;
}
static int F_300 ( struct V_34 * V_35 ,
struct V_102 * V_105 , T_2 V_36 ,
T_2 V_405 , int V_267 )
{
struct V_109 * V_110 ;
int V_44 ;
int V_29 = 0 ;
switch ( V_267 ) {
case V_406 :
case V_407 :
if ( V_267 == V_406 )
V_44 = F_293 ( V_35 , V_36 ) * 2 ;
else
V_44 = - 1 ;
V_110 = F_193 ( V_35 ) ;
if ( F_194 ( V_110 ) ) {
V_29 = F_195 ( V_110 ) ;
break;
}
V_29 = F_301 ( V_110 , V_35 , V_44 ) ;
F_197 ( V_110 , V_35 ) ;
break;
case V_408 :
case V_409 :
F_294 ( V_35 , V_36 * 2 , V_405 ,
V_267 == V_409 ) ;
break;
case V_410 :
V_110 = F_193 ( V_35 ) ;
if ( F_194 ( V_110 ) ) {
V_29 = F_195 ( V_110 ) ;
break;
}
V_29 = F_271 ( V_110 , V_35 -> V_37 -> V_62 ,
F_268 ( V_35 , 0 ) ,
V_314 ) ;
F_197 ( V_110 , V_35 ) ;
if ( V_29 == - V_356 )
V_29 = 0 ;
break;
case V_411 :
V_29 = F_299 ( V_35 , V_105 , V_405 , 0 ) ;
break;
default:
V_29 = - V_356 ;
break;
}
return V_29 ;
}
static inline T_2
F_302 ( struct V_34 * V_35 ,
struct V_102 * V_105 )
{
T_2 V_347 ;
T_2 V_412 ;
T_2 V_387 ;
V_387 = F_24 ( T_2 , F_303 () * 1024 * 1024 ,
16 * 1024 * 1024 ) ;
F_11 ( & V_105 -> V_52 ) ;
if ( F_287 ( V_35 , V_105 , V_387 ,
V_380 ) ) {
V_387 = 0 ;
goto V_72;
}
V_347 = V_105 -> V_297 + V_105 -> V_310 +
V_105 -> V_309 + V_105 -> V_311 +
V_105 -> V_312 ;
if ( F_287 ( V_35 , V_105 , 1024 * 1024 ,
V_380 ) )
V_412 = F_279 ( V_105 -> V_296 , 95 ) ;
else
V_412 = F_279 ( V_105 -> V_296 , 90 ) ;
if ( V_347 > V_412 )
V_387 = V_347 - V_412 ;
else
V_387 = 0 ;
V_387 = F_296 ( V_387 , V_105 -> V_312 +
V_105 -> V_310 ) ;
V_72:
F_13 ( & V_105 -> V_52 ) ;
return V_387 ;
}
static inline int F_304 ( struct V_102 * V_105 ,
struct V_12 * V_37 , T_2 V_347 )
{
return ( V_347 >= F_279 ( V_105 -> V_296 , 98 ) &&
! F_39 ( V_37 ) &&
! F_222 ( V_413 , & V_37 -> V_414 ) ) ;
}
static int F_305 ( struct V_102 * V_105 ,
struct V_12 * V_37 ,
int V_415 )
{
T_2 V_347 ;
F_11 ( & V_105 -> V_52 ) ;
if ( V_415 > V_411 && V_105 -> V_108 ) {
F_13 ( & V_105 -> V_52 ) ;
return 0 ;
}
V_347 = V_105 -> V_297 + V_105 -> V_310 +
V_105 -> V_309 + V_105 -> V_311 +
V_105 -> V_312 ;
if ( F_304 ( V_105 , V_37 , V_347 ) ) {
F_13 ( & V_105 -> V_52 ) ;
return 1 ;
}
F_13 ( & V_105 -> V_52 ) ;
return 0 ;
}
static void F_306 ( struct V_416 * V_61 )
{
struct V_12 * V_37 ;
struct V_102 * V_105 ;
T_2 V_387 ;
int V_415 ;
V_37 = F_32 ( V_61 , struct V_12 , V_417 ) ;
V_105 = F_69 ( V_37 , V_293 ) ;
V_387 = F_302 ( V_37 -> V_418 ,
V_105 ) ;
if ( ! V_387 )
return;
V_415 = V_406 ;
do {
F_300 ( V_37 -> V_418 , V_105 , V_387 ,
V_387 , V_415 ) ;
V_415 ++ ;
if ( ! F_305 ( V_105 , V_37 ,
V_415 ) )
return;
} while ( V_415 <= V_411 );
if ( F_305 ( V_105 , V_37 , V_415 ) )
F_307 ( V_419 , V_61 ) ;
}
void F_308 ( struct V_416 * V_61 )
{
F_309 ( V_61 , F_306 ) ;
}
static int F_310 ( struct V_34 * V_35 ,
struct V_240 * V_390 ,
T_2 V_405 ,
enum V_374 V_316 )
{
struct V_102 * V_105 = V_390 -> V_105 ;
T_2 V_347 ;
T_2 V_36 = V_405 ;
int V_415 = V_406 ;
int V_29 = 0 ;
bool V_420 = false ;
V_77:
V_29 = 0 ;
F_11 ( & V_105 -> V_52 ) ;
while ( V_316 == V_380 && ! V_420 &&
V_105 -> V_316 ) {
F_13 ( & V_105 -> V_52 ) ;
if ( V_351 -> V_352 )
return - V_178 ;
V_29 = F_311 ( V_105 -> V_88 , ! V_105 -> V_316 ) ;
if ( V_29 )
return - V_421 ;
F_11 ( & V_105 -> V_52 ) ;
}
V_29 = - V_356 ;
V_347 = V_105 -> V_297 + V_105 -> V_310 +
V_105 -> V_309 + V_105 -> V_311 +
V_105 -> V_312 ;
if ( V_347 <= V_105 -> V_296 ) {
if ( V_347 + V_405 <= V_105 -> V_296 ) {
V_105 -> V_312 += V_405 ;
F_274 ( V_35 -> V_37 ,
L_10 , V_105 -> V_7 , V_405 , 1 ) ;
V_29 = 0 ;
} else {
V_36 = V_405 ;
}
} else {
V_36 = V_347 - V_105 -> V_296 +
( V_405 * 2 ) ;
}
if ( V_29 && F_287 ( V_35 , V_105 , V_405 , V_316 ) ) {
V_105 -> V_312 += V_405 ;
F_274 ( V_35 -> V_37 , L_10 ,
V_105 -> V_7 , V_405 ,
1 ) ;
V_29 = 0 ;
}
if ( V_29 && V_316 != V_401 ) {
V_420 = true ;
V_105 -> V_316 = 1 ;
} else if ( ! V_29 && V_105 -> V_7 & V_293 ) {
V_347 += V_405 ;
if ( ! V_35 -> V_37 -> V_422 &&
F_304 ( V_105 , V_35 -> V_37 , V_347 ) &&
! F_312 ( & V_35 -> V_37 -> V_417 ) )
F_307 ( V_419 ,
& V_35 -> V_37 -> V_417 ) ;
}
F_13 ( & V_105 -> V_52 ) ;
if ( ! V_29 || V_316 == V_401 )
goto V_72;
V_29 = F_300 ( V_35 , V_105 , V_36 , V_405 ,
V_415 ) ;
V_415 ++ ;
if ( V_316 == V_423 &&
( V_415 == V_408 ||
V_415 == V_409 ) )
V_415 = V_410 ;
if ( ! V_29 )
goto V_77;
else if ( V_316 == V_423 &&
V_415 < V_411 )
goto V_77;
else if ( V_316 == V_380 &&
V_415 <= V_411 )
goto V_77;
V_72:
if ( V_29 == - V_356 &&
F_313 ( V_35 -> V_424 == V_425 ) ) {
struct V_240 * V_241 =
& V_35 -> V_37 -> V_242 ;
if ( V_390 != V_241 &&
! F_314 ( V_241 , V_405 ) )
V_29 = 0 ;
}
if ( V_29 == - V_356 )
F_274 ( V_35 -> V_37 ,
L_9 ,
V_105 -> V_7 , V_405 , 1 ) ;
if ( V_420 ) {
F_11 ( & V_105 -> V_52 ) ;
V_105 -> V_316 = 0 ;
F_315 ( & V_105 -> V_88 ) ;
F_13 ( & V_105 -> V_52 ) ;
}
return V_29 ;
}
static struct V_240 * F_316 (
const struct V_109 * V_110 ,
const struct V_34 * V_35 )
{
struct V_240 * V_390 = NULL ;
if ( F_222 ( V_266 , & V_35 -> V_267 ) )
V_390 = V_110 -> V_390 ;
if ( V_35 == V_35 -> V_37 -> V_426 && V_110 -> V_427 )
V_390 = V_110 -> V_390 ;
if ( V_35 == V_35 -> V_37 -> V_428 )
V_390 = V_110 -> V_390 ;
if ( ! V_390 )
V_390 = V_35 -> V_390 ;
if ( ! V_390 )
V_390 = & V_35 -> V_37 -> V_429 ;
return V_390 ;
}
static int F_314 ( struct V_240 * V_390 ,
T_2 V_36 )
{
int V_29 = - V_356 ;
F_11 ( & V_390 -> V_52 ) ;
if ( V_390 -> V_10 >= V_36 ) {
V_390 -> V_10 -= V_36 ;
if ( V_390 -> V_10 < V_390 -> V_56 )
V_390 -> V_108 = 0 ;
V_29 = 0 ;
}
F_13 ( & V_390 -> V_52 ) ;
return V_29 ;
}
static void F_317 ( struct V_240 * V_390 ,
T_2 V_36 , int V_430 )
{
F_11 ( & V_390 -> V_52 ) ;
V_390 -> V_10 += V_36 ;
if ( V_430 )
V_390 -> V_56 += V_36 ;
else if ( V_390 -> V_10 >= V_390 -> V_56 )
V_390 -> V_108 = 1 ;
F_13 ( & V_390 -> V_52 ) ;
}
int F_318 ( struct V_12 * V_37 ,
struct V_240 * V_431 , T_2 V_36 ,
int V_432 )
{
struct V_240 * V_241 = & V_37 -> V_242 ;
T_2 V_433 ;
if ( V_241 -> V_105 != V_431 -> V_105 )
return - V_356 ;
F_11 ( & V_241 -> V_52 ) ;
V_433 = F_280 ( V_241 -> V_56 , V_432 ) ;
if ( V_241 -> V_10 < V_433 + V_36 ) {
F_13 ( & V_241 -> V_52 ) ;
return - V_356 ;
}
V_241 -> V_10 -= V_36 ;
if ( V_241 -> V_10 < V_241 -> V_56 )
V_241 -> V_108 = 0 ;
F_13 ( & V_241 -> V_52 ) ;
F_317 ( V_431 , V_36 , 1 ) ;
return 0 ;
}
static void F_319 ( struct V_12 * V_37 ,
struct V_240 * V_390 ,
struct V_240 * V_431 , T_2 V_36 )
{
struct V_102 * V_105 = V_390 -> V_105 ;
F_11 ( & V_390 -> V_52 ) ;
if ( V_36 == ( T_2 ) - 1 )
V_36 = V_390 -> V_56 ;
V_390 -> V_56 -= V_36 ;
if ( V_390 -> V_10 >= V_390 -> V_56 ) {
V_36 = V_390 -> V_10 - V_390 -> V_56 ;
V_390 -> V_10 = V_390 -> V_56 ;
V_390 -> V_108 = 1 ;
} else {
V_36 = 0 ;
}
F_13 ( & V_390 -> V_52 ) ;
if ( V_36 > 0 ) {
if ( V_431 ) {
F_11 ( & V_431 -> V_52 ) ;
if ( ! V_431 -> V_108 ) {
T_2 V_434 ;
V_434 = V_431 -> V_56 - V_431 -> V_10 ;
V_434 = F_296 ( V_36 , V_434 ) ;
V_431 -> V_10 += V_434 ;
if ( V_431 -> V_10 >= V_431 -> V_56 )
V_431 -> V_108 = 1 ;
V_36 -= V_434 ;
}
F_13 ( & V_431 -> V_52 ) ;
}
if ( V_36 ) {
F_11 ( & V_105 -> V_52 ) ;
V_105 -> V_312 -= V_36 ;
F_274 ( V_37 , L_10 ,
V_105 -> V_7 , V_36 , 0 ) ;
F_13 ( & V_105 -> V_52 ) ;
}
}
}
static int F_320 ( struct V_240 * V_435 ,
struct V_240 * V_436 , T_2 V_36 )
{
int V_29 ;
V_29 = F_314 ( V_435 , V_36 ) ;
if ( V_29 )
return V_29 ;
F_317 ( V_436 , V_36 , 1 ) ;
return 0 ;
}
void F_321 ( struct V_240 * V_437 , unsigned short type )
{
memset ( V_437 , 0 , sizeof( * V_437 ) ) ;
F_255 ( & V_437 -> V_52 ) ;
V_437 -> type = type ;
}
struct V_240 * F_322 ( struct V_34 * V_35 ,
unsigned short type )
{
struct V_240 * V_390 ;
struct V_12 * V_37 = V_35 -> V_37 ;
V_390 = F_200 ( sizeof( * V_390 ) , V_40 ) ;
if ( ! V_390 )
return NULL ;
F_321 ( V_390 , type ) ;
V_390 -> V_105 = F_69 ( V_37 ,
V_293 ) ;
return V_390 ;
}
void F_323 ( struct V_34 * V_35 ,
struct V_240 * V_437 )
{
if ( ! V_437 )
return;
F_324 ( V_35 , V_437 , ( T_2 ) - 1 ) ;
F_9 ( V_437 ) ;
}
int F_325 ( struct V_34 * V_35 ,
struct V_240 * V_390 , T_2 V_36 ,
enum V_374 V_316 )
{
int V_29 ;
if ( V_36 == 0 )
return 0 ;
V_29 = F_310 ( V_35 , V_390 , V_36 , V_316 ) ;
if ( ! V_29 ) {
F_317 ( V_390 , V_36 , 1 ) ;
return 0 ;
}
return V_29 ;
}
int F_326 ( struct V_34 * V_35 ,
struct V_240 * V_390 , int V_432 )
{
T_2 V_36 = 0 ;
int V_29 = - V_356 ;
if ( ! V_390 )
return 0 ;
F_11 ( & V_390 -> V_52 ) ;
V_36 = F_280 ( V_390 -> V_56 , V_432 ) ;
if ( V_390 -> V_10 >= V_36 )
V_29 = 0 ;
F_13 ( & V_390 -> V_52 ) ;
return V_29 ;
}
int F_327 ( struct V_34 * V_35 ,
struct V_240 * V_390 , T_2 V_438 ,
enum V_374 V_316 )
{
T_2 V_36 = 0 ;
int V_29 = - V_356 ;
if ( ! V_390 )
return 0 ;
F_11 ( & V_390 -> V_52 ) ;
V_36 = V_438 ;
if ( V_390 -> V_10 >= V_36 )
V_29 = 0 ;
else
V_36 -= V_390 -> V_10 ;
F_13 ( & V_390 -> V_52 ) ;
if ( ! V_29 )
return 0 ;
V_29 = F_310 ( V_35 , V_390 , V_36 , V_316 ) ;
if ( ! V_29 ) {
F_317 ( V_390 , V_36 , 0 ) ;
return 0 ;
}
return V_29 ;
}
int F_328 ( struct V_240 * V_439 ,
struct V_240 * V_440 ,
T_2 V_36 )
{
return F_320 ( V_439 , V_440 , V_36 ) ;
}
void F_324 ( struct V_34 * V_35 ,
struct V_240 * V_390 ,
T_2 V_36 )
{
struct V_240 * V_241 = & V_35 -> V_37 -> V_242 ;
if ( V_241 == V_390 ||
V_390 -> V_105 != V_241 -> V_105 )
V_241 = NULL ;
F_319 ( V_35 -> V_37 , V_390 , V_241 ,
V_36 ) ;
}
static T_2 F_329 ( struct V_12 * V_37 )
{
struct V_102 * V_360 ;
T_2 V_36 ;
T_2 V_441 ;
T_2 V_442 ;
int V_443 = F_330 ( V_37 -> V_365 ) ;
V_360 = F_69 ( V_37 , V_294 ) ;
F_11 ( & V_360 -> V_52 ) ;
V_442 = V_360 -> V_297 ;
F_13 ( & V_360 -> V_52 ) ;
V_360 = F_69 ( V_37 , V_293 ) ;
F_11 ( & V_360 -> V_52 ) ;
if ( V_360 -> V_7 & V_294 )
V_442 = 0 ;
V_441 = V_360 -> V_297 ;
F_13 ( & V_360 -> V_52 ) ;
V_36 = ( V_442 >> V_37 -> V_384 -> V_444 ) *
V_443 * 2 ;
V_36 += F_183 ( V_442 + V_441 , 50 ) ;
if ( V_36 * 3 > V_441 )
V_36 = F_183 ( V_441 , 3 ) ;
return F_269 ( V_36 , V_37 -> V_62 -> V_87 << 10 ) ;
}
static void F_331 ( struct V_12 * V_37 )
{
struct V_240 * V_390 = & V_37 -> V_242 ;
struct V_102 * V_360 = V_390 -> V_105 ;
T_2 V_36 ;
V_36 = F_329 ( V_37 ) ;
F_11 ( & V_360 -> V_52 ) ;
F_11 ( & V_390 -> V_52 ) ;
V_390 -> V_56 = F_24 ( T_2 , V_36 , 512 * 1024 * 1024 ) ;
V_36 = V_360 -> V_297 + V_360 -> V_309 +
V_360 -> V_310 + V_360 -> V_311 +
V_360 -> V_312 ;
if ( V_360 -> V_296 > V_36 ) {
V_36 = V_360 -> V_296 - V_36 ;
V_390 -> V_10 += V_36 ;
V_360 -> V_312 += V_36 ;
F_274 ( V_37 , L_10 ,
V_360 -> V_7 , V_36 , 1 ) ;
}
if ( V_390 -> V_10 >= V_390 -> V_56 ) {
V_36 = V_390 -> V_10 - V_390 -> V_56 ;
V_360 -> V_312 -= V_36 ;
F_274 ( V_37 , L_10 ,
V_360 -> V_7 , V_36 , 0 ) ;
V_390 -> V_10 = V_390 -> V_56 ;
V_390 -> V_108 = 1 ;
}
F_13 ( & V_390 -> V_52 ) ;
F_13 ( & V_360 -> V_52 ) ;
}
static void F_332 ( struct V_12 * V_37 )
{
struct V_102 * V_105 ;
V_105 = F_69 ( V_37 , V_295 ) ;
V_37 -> V_445 . V_105 = V_105 ;
V_105 = F_69 ( V_37 , V_293 ) ;
V_37 -> V_242 . V_105 = V_105 ;
V_37 -> V_396 . V_105 = V_105 ;
V_37 -> V_446 . V_105 = V_105 ;
V_37 -> V_429 . V_105 = V_105 ;
V_37 -> V_403 . V_105 = V_105 ;
V_37 -> V_62 -> V_390 = & V_37 -> V_242 ;
V_37 -> V_426 -> V_390 = & V_37 -> V_242 ;
V_37 -> V_447 -> V_390 = & V_37 -> V_242 ;
V_37 -> V_86 -> V_390 = & V_37 -> V_242 ;
if ( V_37 -> V_448 )
V_37 -> V_448 -> V_390 = & V_37 -> V_242 ;
V_37 -> V_345 -> V_390 = & V_37 -> V_445 ;
F_331 ( V_37 ) ;
}
static void F_333 ( struct V_12 * V_37 )
{
F_319 ( V_37 , & V_37 -> V_242 , NULL ,
( T_2 ) - 1 ) ;
F_8 ( V_37 -> V_396 . V_56 > 0 ) ;
F_8 ( V_37 -> V_396 . V_10 > 0 ) ;
F_8 ( V_37 -> V_446 . V_56 > 0 ) ;
F_8 ( V_37 -> V_446 . V_10 > 0 ) ;
F_8 ( V_37 -> V_445 . V_56 > 0 ) ;
F_8 ( V_37 -> V_445 . V_10 > 0 ) ;
F_8 ( V_37 -> V_403 . V_56 > 0 ) ;
F_8 ( V_37 -> V_403 . V_10 > 0 ) ;
}
void F_334 ( struct V_109 * V_110 ,
struct V_34 * V_35 )
{
if ( ! V_110 -> V_390 )
return;
if ( ! V_110 -> V_310 )
return;
F_274 ( V_35 -> V_37 , L_12 ,
V_110 -> V_282 , V_110 -> V_310 , 0 ) ;
F_324 ( V_35 , V_110 -> V_390 , V_110 -> V_310 ) ;
V_110 -> V_310 = 0 ;
}
int F_335 ( struct V_109 * V_110 ,
struct V_272 * V_272 )
{
struct V_34 * V_35 = F_239 ( V_272 ) -> V_35 ;
struct V_240 * V_439 = F_316 ( V_110 , V_35 ) ;
struct V_240 * V_440 = V_35 -> V_449 ;
T_2 V_36 = F_189 ( V_35 , 1 ) ;
F_274 ( V_35 -> V_37 , L_13 ,
F_336 ( V_272 ) , V_36 , 1 ) ;
return F_320 ( V_439 , V_440 , V_36 ) ;
}
void F_337 ( struct V_272 * V_272 )
{
struct V_34 * V_35 = F_239 ( V_272 ) -> V_35 ;
T_2 V_36 = F_189 ( V_35 , 1 ) ;
F_274 ( V_35 -> V_37 , L_13 ,
F_336 ( V_272 ) , V_36 , 0 ) ;
F_324 ( V_35 , V_35 -> V_449 , V_36 ) ;
}
int F_338 ( struct V_34 * V_35 ,
struct V_240 * V_437 ,
int V_394 ,
T_2 * V_450 ,
bool V_451 )
{
T_2 V_36 ;
int V_29 ;
struct V_240 * V_241 = & V_35 -> V_37 -> V_242 ;
if ( V_35 -> V_37 -> V_206 ) {
V_36 = 3 * V_35 -> V_87 ;
V_29 = F_339 ( V_35 , V_36 ) ;
if ( V_29 )
return V_29 ;
} else {
V_36 = 0 ;
}
* V_450 = V_36 ;
V_36 = F_189 ( V_35 , V_394 ) ;
V_437 -> V_105 = F_69 ( V_35 -> V_37 ,
V_293 ) ;
V_29 = F_325 ( V_35 , V_437 , V_36 ,
V_380 ) ;
if ( V_29 == - V_356 && V_451 )
V_29 = F_328 ( V_241 , V_437 , V_36 ) ;
if ( V_29 ) {
if ( * V_450 )
F_340 ( V_35 , * V_450 ) ;
}
return V_29 ;
}
void F_341 ( struct V_34 * V_35 ,
struct V_240 * V_437 ,
T_2 V_450 )
{
F_324 ( V_35 , V_437 , ( T_2 ) - 1 ) ;
if ( V_450 )
F_340 ( V_35 , V_450 ) ;
}
static unsigned F_342 ( struct V_272 * V_272 )
{
unsigned V_452 = 0 ;
unsigned V_453 = 0 ;
F_30 ( ! F_239 ( V_272 ) -> V_454 ) ;
F_239 ( V_272 ) -> V_454 -- ;
if ( F_239 ( V_272 ) -> V_454 == 0 &&
F_343 ( V_455 ,
& F_239 ( V_272 ) -> V_456 ) )
V_452 = 1 ;
if ( F_239 ( V_272 ) -> V_454 >=
F_239 ( V_272 ) -> V_457 )
return V_452 ;
V_453 = F_239 ( V_272 ) -> V_457 -
F_239 ( V_272 ) -> V_454 ;
F_239 ( V_272 ) -> V_457 -= V_453 ;
return V_453 + V_452 ;
}
static T_2 F_344 ( struct V_272 * V_272 , T_2 V_36 ,
int V_458 )
{
struct V_34 * V_35 = F_239 ( V_272 ) -> V_35 ;
T_2 V_443 ;
int V_459 ;
int V_460 ;
int V_461 ;
if ( F_239 ( V_272 ) -> V_7 & V_462 &&
F_239 ( V_272 ) -> V_463 == 0 )
return 0 ;
V_461 = ( int ) F_183 ( F_239 ( V_272 ) -> V_463 , V_35 -> V_350 ) ;
if ( V_458 )
F_239 ( V_272 ) -> V_463 += V_36 ;
else
F_239 ( V_272 ) -> V_463 -= V_36 ;
V_443 = F_187 ( V_35 ) - sizeof( struct V_464 ) ;
V_459 = ( int ) F_183 ( V_443 ,
sizeof( struct V_465 ) +
sizeof( struct V_466 ) ) ;
V_460 = ( int ) F_183 ( F_239 ( V_272 ) -> V_463 , V_35 -> V_350 ) ;
V_460 = V_460 + V_459 - 1 ;
V_460 = V_460 / V_459 ;
V_461 = V_461 + V_459 - 1 ;
V_461 = V_461 / V_459 ;
if ( V_461 == V_460 )
return 0 ;
if ( V_458 )
return F_189 ( V_35 ,
V_460 - V_461 ) ;
return F_189 ( V_35 , V_461 - V_460 ) ;
}
int F_345 ( struct V_272 * V_272 , T_2 V_36 )
{
struct V_34 * V_35 = F_239 ( V_272 ) -> V_35 ;
struct V_240 * V_390 = & V_35 -> V_37 -> V_396 ;
T_2 V_467 = 0 ;
T_2 V_463 ;
unsigned V_468 = 0 ;
int V_469 = 0 ;
enum V_374 V_316 = V_380 ;
int V_29 = 0 ;
bool V_470 = true ;
T_2 V_471 = 0 ;
unsigned V_472 ;
if ( F_270 ( V_272 ) ) {
V_316 = V_401 ;
V_470 = false ;
}
if ( V_316 != V_401 &&
F_346 ( V_35 -> V_37 ) )
F_347 ( 1 ) ;
if ( V_470 )
F_35 ( & F_239 ( V_272 ) -> V_473 ) ;
V_36 = F_269 ( V_36 , V_35 -> V_350 ) ;
F_11 ( & F_239 ( V_272 ) -> V_52 ) ;
F_239 ( V_272 ) -> V_454 ++ ;
if ( F_239 ( V_272 ) -> V_454 >
F_239 ( V_272 ) -> V_457 )
V_468 = F_239 ( V_272 ) -> V_454 -
F_239 ( V_272 ) -> V_457 ;
if ( ! F_222 ( V_455 ,
& F_239 ( V_272 ) -> V_456 ) ) {
V_468 ++ ;
V_469 = 1 ;
}
V_467 = F_189 ( V_35 , V_468 ) ;
V_467 += F_344 ( V_272 , V_36 , 1 ) ;
V_463 = F_239 ( V_272 ) -> V_463 ;
F_13 ( & F_239 ( V_272 ) -> V_52 ) ;
if ( V_35 -> V_37 -> V_206 ) {
V_29 = F_339 ( V_35 , V_36 +
V_468 * V_35 -> V_87 ) ;
if ( V_29 )
goto V_474;
}
V_29 = F_310 ( V_35 , V_390 , V_467 , V_316 ) ;
if ( F_313 ( V_29 ) ) {
if ( V_35 -> V_37 -> V_206 )
F_340 ( V_35 , V_36 +
V_468 * V_35 -> V_87 ) ;
goto V_474;
}
F_11 ( & F_239 ( V_272 ) -> V_52 ) ;
if ( V_469 ) {
F_348 ( V_455 ,
& F_239 ( V_272 ) -> V_456 ) ;
V_468 -- ;
}
F_239 ( V_272 ) -> V_457 += V_468 ;
F_13 ( & F_239 ( V_272 ) -> V_52 ) ;
if ( V_470 )
F_46 ( & F_239 ( V_272 ) -> V_473 ) ;
if ( V_467 )
F_274 ( V_35 -> V_37 , L_14 ,
F_336 ( V_272 ) , V_467 , 1 ) ;
F_317 ( V_390 , V_467 , 1 ) ;
return 0 ;
V_474:
F_11 ( & F_239 ( V_272 ) -> V_52 ) ;
V_472 = F_342 ( V_272 ) ;
if ( F_239 ( V_272 ) -> V_463 == V_463 ) {
F_344 ( V_272 , V_36 , 0 ) ;
} else {
T_2 V_475 = F_239 ( V_272 ) -> V_463 ;
T_2 V_346 ;
V_346 = V_463 - F_239 ( V_272 ) -> V_463 ;
F_239 ( V_272 ) -> V_463 = V_463 ;
V_471 = F_344 ( V_272 , V_346 , 0 ) ;
F_239 ( V_272 ) -> V_463 = V_463 - V_36 ;
V_346 = V_463 - V_475 ;
V_346 = F_344 ( V_272 , V_346 , 0 ) ;
F_239 ( V_272 ) -> V_463 = V_475 - V_36 ;
if ( V_346 > V_471 )
V_471 = V_346 - V_471 ;
else
V_471 = 0 ;
}
F_13 ( & F_239 ( V_272 ) -> V_52 ) ;
if ( V_472 )
V_471 += F_189 ( V_35 , V_472 ) ;
if ( V_471 ) {
F_324 ( V_35 , V_390 , V_471 ) ;
F_274 ( V_35 -> V_37 , L_14 ,
F_336 ( V_272 ) , V_471 , 0 ) ;
}
if ( V_470 )
F_46 ( & F_239 ( V_272 ) -> V_473 ) ;
return V_29 ;
}
void F_349 ( struct V_272 * V_272 , T_2 V_36 )
{
struct V_34 * V_35 = F_239 ( V_272 ) -> V_35 ;
T_2 V_471 = 0 ;
unsigned V_472 ;
V_36 = F_269 ( V_36 , V_35 -> V_350 ) ;
F_11 ( & F_239 ( V_272 ) -> V_52 ) ;
V_472 = F_342 ( V_272 ) ;
if ( V_36 )
V_471 = F_344 ( V_272 , V_36 , 0 ) ;
F_13 ( & F_239 ( V_272 ) -> V_52 ) ;
if ( V_472 > 0 )
V_471 += F_189 ( V_35 , V_472 ) ;
F_274 ( V_35 -> V_37 , L_14 ,
F_336 ( V_272 ) , V_471 , 0 ) ;
if ( V_35 -> V_37 -> V_206 ) {
F_340 ( V_35 , V_36 +
V_472 * V_35 -> V_87 ) ;
}
F_324 ( V_35 , & V_35 -> V_37 -> V_396 ,
V_471 ) ;
}
int F_350 ( struct V_272 * V_272 , T_2 V_36 )
{
int V_29 ;
V_29 = F_244 ( V_272 , V_36 ) ;
if ( V_29 )
return V_29 ;
V_29 = F_345 ( V_272 , V_36 ) ;
if ( V_29 ) {
F_246 ( V_272 , V_36 ) ;
return V_29 ;
}
return 0 ;
}
void F_351 ( struct V_272 * V_272 , T_2 V_36 )
{
F_349 ( V_272 , V_36 ) ;
F_246 ( V_272 , V_36 ) ;
}
static int F_352 ( struct V_34 * V_35 ,
T_2 V_27 , T_2 V_36 , int V_353 )
{
struct V_1 * V_2 = NULL ;
struct V_12 * V_13 = V_35 -> V_37 ;
T_2 V_476 = V_36 ;
T_2 V_477 ;
T_2 V_478 ;
int V_298 ;
F_11 ( & V_13 -> V_479 ) ;
V_477 = F_353 ( V_13 -> V_365 ) ;
if ( V_353 )
V_477 += V_36 ;
else
V_477 -= V_36 ;
F_354 ( V_13 -> V_365 , V_477 ) ;
F_13 ( & V_13 -> V_479 ) ;
while ( V_476 ) {
V_2 = F_68 ( V_13 , V_27 ) ;
if ( ! V_2 )
return - V_153 ;
if ( V_2 -> V_7 & ( V_299 |
V_300 |
V_301 ) )
V_298 = 2 ;
else
V_298 = 1 ;
if ( ! V_353 && V_2 -> V_3 == V_94 )
F_51 ( V_2 , 1 ) ;
V_478 = V_27 - V_2 -> V_21 . V_22 ;
F_8 ( V_478 > V_2 -> V_21 . V_33 ) ;
F_11 ( & V_2 -> V_105 -> V_52 ) ;
F_11 ( & V_2 -> V_52 ) ;
if ( F_243 ( V_35 , V_286 ) &&
V_2 -> V_278 < V_289 )
V_2 -> V_278 = V_289 ;
V_2 -> V_290 = 1 ;
V_477 = F_355 ( & V_2 -> V_135 ) ;
V_36 = F_296 ( V_476 , V_2 -> V_21 . V_33 - V_478 ) ;
if ( V_353 ) {
V_477 += V_36 ;
F_356 ( & V_2 -> V_135 , V_477 ) ;
V_2 -> V_10 -= V_36 ;
V_2 -> V_105 -> V_310 -= V_36 ;
V_2 -> V_105 -> V_297 += V_36 ;
V_2 -> V_105 -> V_303 += V_36 * V_298 ;
F_13 ( & V_2 -> V_52 ) ;
F_13 ( & V_2 -> V_105 -> V_52 ) ;
} else {
V_477 -= V_36 ;
F_356 ( & V_2 -> V_135 , V_477 ) ;
V_2 -> V_9 += V_36 ;
V_2 -> V_105 -> V_309 += V_36 ;
V_2 -> V_105 -> V_297 -= V_36 ;
V_2 -> V_105 -> V_303 -= V_36 * V_298 ;
F_13 ( & V_2 -> V_52 ) ;
F_13 ( & V_2 -> V_105 -> V_52 ) ;
F_357 ( V_13 -> V_58 ,
V_27 , V_27 + V_36 - 1 ,
V_40 | V_480 ) ;
if ( V_477 == 0 ) {
F_11 ( & V_13 -> V_481 ) ;
if ( F_204 ( & V_2 -> V_482 ) ) {
F_4 ( V_2 ) ;
F_64 ( & V_2 -> V_482 ,
& V_13 -> V_483 ) ;
}
F_13 ( & V_13 -> V_481 ) ;
}
}
F_6 ( V_2 ) ;
V_476 -= V_36 ;
V_27 += V_36 ;
}
return 0 ;
}
static T_2 V_26 ( struct V_34 * V_35 , T_2 V_484 )
{
struct V_1 * V_2 ;
T_2 V_27 ;
F_11 ( & V_35 -> V_37 -> V_18 ) ;
V_27 = V_35 -> V_37 -> V_26 ;
F_13 ( & V_35 -> V_37 -> V_18 ) ;
if ( V_27 < ( T_2 ) - 1 )
return V_27 ;
V_2 = F_67 ( V_35 -> V_37 , V_484 ) ;
if ( ! V_2 )
return 0 ;
V_27 = V_2 -> V_21 . V_22 ;
F_6 ( V_2 ) ;
return V_27 ;
}
static int F_358 ( struct V_34 * V_35 ,
struct V_1 * V_2 ,
T_2 V_27 , T_2 V_36 , int V_10 )
{
F_11 ( & V_2 -> V_105 -> V_52 ) ;
F_11 ( & V_2 -> V_52 ) ;
V_2 -> V_9 += V_36 ;
V_2 -> V_105 -> V_309 += V_36 ;
if ( V_10 ) {
V_2 -> V_10 -= V_36 ;
V_2 -> V_105 -> V_310 -= V_36 ;
}
F_13 ( & V_2 -> V_52 ) ;
F_13 ( & V_2 -> V_105 -> V_52 ) ;
F_357 ( V_35 -> V_37 -> V_58 , V_27 ,
V_27 + V_36 - 1 , V_40 | V_480 ) ;
if ( V_10 )
F_359 ( V_35 , V_27 , V_36 ) ;
return 0 ;
}
int F_163 ( struct V_34 * V_35 ,
T_2 V_27 , T_2 V_36 , int V_10 )
{
struct V_1 * V_2 ;
V_2 = F_68 ( V_35 -> V_37 , V_27 ) ;
F_30 ( ! V_2 ) ;
F_358 ( V_35 , V_2 , V_27 , V_36 , V_10 ) ;
F_6 ( V_2 ) ;
return 0 ;
}
int F_360 ( struct V_34 * V_35 ,
T_2 V_27 , T_2 V_36 )
{
struct V_1 * V_2 ;
int V_29 ;
V_2 = F_68 ( V_35 -> V_37 , V_27 ) ;
if ( ! V_2 )
return - V_485 ;
F_51 ( V_2 , 1 ) ;
F_358 ( V_35 , V_2 , V_27 , V_36 , 0 ) ;
V_29 = F_361 ( V_2 , V_27 , V_36 ) ;
F_6 ( V_2 ) ;
return V_29 ;
}
static int F_362 ( struct V_34 * V_35 , T_2 V_32 , T_2 V_36 )
{
int V_29 ;
struct V_1 * V_14 ;
struct V_50 * V_53 ;
V_14 = F_68 ( V_35 -> V_37 , V_32 ) ;
if ( ! V_14 )
return - V_485 ;
F_51 ( V_14 , 0 ) ;
V_53 = F_25 ( V_14 ) ;
if ( ! V_53 ) {
F_30 ( ! F_1 ( V_14 ) ) ;
V_29 = F_361 ( V_14 , V_32 , V_36 ) ;
} else {
F_35 ( & V_53 -> V_78 ) ;
if ( V_32 >= V_53 -> V_84 ) {
V_29 = F_17 ( V_35 , V_32 , V_36 ) ;
} else if ( V_32 + V_36 <= V_53 -> V_84 ) {
V_29 = F_361 ( V_14 ,
V_32 , V_36 ) ;
} else {
V_36 = V_53 -> V_84 - V_32 ;
V_29 = F_361 ( V_14 ,
V_32 , V_36 ) ;
if ( V_29 )
goto V_486;
V_36 = ( V_32 + V_36 ) -
V_53 -> V_84 ;
V_32 = V_53 -> V_84 ;
V_29 = F_17 ( V_35 , V_32 , V_36 ) ;
}
V_486:
F_46 ( & V_53 -> V_78 ) ;
F_26 ( V_53 ) ;
}
F_6 ( V_14 ) ;
return V_29 ;
}
int F_363 ( struct V_34 * log ,
struct V_65 * V_487 )
{
struct V_264 * V_135 ;
struct V_67 V_21 ;
int V_488 ;
int V_43 ;
if ( ! F_76 ( log -> V_37 , V_489 ) )
return 0 ;
for ( V_43 = 0 ; V_43 < F_38 ( V_487 ) ; V_43 ++ ) {
F_40 ( V_487 , & V_21 , V_43 ) ;
if ( V_21 . type != V_269 )
continue;
V_135 = F_78 ( V_487 , V_43 , struct V_264 ) ;
V_488 = F_223 ( V_487 , V_135 ) ;
if ( V_488 == V_270 )
continue;
if ( F_224 ( V_487 , V_135 ) == 0 )
continue;
V_21 . V_22 = F_224 ( V_487 , V_135 ) ;
V_21 . V_33 = F_225 ( V_487 , V_135 ) ;
F_362 ( log , V_21 . V_22 , V_21 . V_33 ) ;
}
return 0 ;
}
static int F_364 ( struct V_1 * V_2 ,
T_2 V_36 , int V_458 , int V_490 )
{
struct V_102 * V_105 = V_2 -> V_105 ;
int V_29 = 0 ;
F_11 ( & V_105 -> V_52 ) ;
F_11 ( & V_2 -> V_52 ) ;
if ( V_458 != V_491 ) {
if ( V_2 -> V_280 ) {
V_29 = - V_178 ;
} else {
V_2 -> V_10 += V_36 ;
V_105 -> V_310 += V_36 ;
if ( V_458 == V_492 ) {
F_274 ( V_2 -> V_37 ,
L_10 , V_105 -> V_7 ,
V_36 , 0 ) ;
V_105 -> V_312 -= V_36 ;
}
if ( V_490 )
V_2 -> V_287 += V_36 ;
}
} else {
if ( V_2 -> V_280 )
V_105 -> V_311 += V_36 ;
V_2 -> V_10 -= V_36 ;
V_105 -> V_310 -= V_36 ;
if ( V_490 )
V_2 -> V_287 -= V_36 ;
}
F_13 ( & V_2 -> V_52 ) ;
F_13 ( & V_105 -> V_52 ) ;
return V_29 ;
}
void F_365 ( struct V_109 * V_110 ,
struct V_34 * V_35 )
{
struct V_12 * V_37 = V_35 -> V_37 ;
struct V_50 * V_80 ;
struct V_50 * V_53 ;
struct V_1 * V_2 ;
F_63 ( & V_37 -> V_79 ) ;
F_366 (caching_ctl, next,
&fs_info->caching_block_groups, list) {
V_2 = V_53 -> V_14 ;
if ( F_1 ( V_2 ) ) {
V_2 -> V_97 = ( T_2 ) - 1 ;
F_367 ( & V_53 -> V_90 ) ;
F_26 ( V_53 ) ;
} else {
V_2 -> V_97 = V_53 -> V_84 ;
}
}
if ( V_37 -> V_58 == & V_37 -> V_38 [ 0 ] )
V_37 -> V_58 = & V_37 -> V_38 [ 1 ] ;
else
V_37 -> V_58 = & V_37 -> V_38 [ 0 ] ;
F_65 ( & V_37 -> V_79 ) ;
F_331 ( V_37 ) ;
}
static int F_368 ( struct V_34 * V_35 , T_2 V_32 , T_2 V_31 ,
const bool V_493 )
{
struct V_12 * V_37 = V_35 -> V_37 ;
struct V_1 * V_2 = NULL ;
struct V_102 * V_105 ;
struct V_240 * V_241 = & V_37 -> V_242 ;
T_2 V_49 ;
bool V_292 ;
while ( V_32 <= V_31 ) {
V_292 = false ;
if ( ! V_2 ||
V_32 >= V_2 -> V_21 . V_22 + V_2 -> V_21 . V_33 ) {
if ( V_2 )
F_6 ( V_2 ) ;
V_2 = F_68 ( V_37 , V_32 ) ;
F_30 ( ! V_2 ) ;
}
V_49 = V_2 -> V_21 . V_22 + V_2 -> V_21 . V_33 - V_32 ;
V_49 = F_296 ( V_49 , V_31 + 1 - V_32 ) ;
if ( V_32 < V_2 -> V_97 ) {
V_49 = F_296 ( V_49 , V_2 -> V_97 - V_32 ) ;
if ( V_493 )
F_29 ( V_2 , V_32 , V_49 ) ;
}
V_32 += V_49 ;
V_105 = V_2 -> V_105 ;
F_11 ( & V_105 -> V_52 ) ;
F_11 ( & V_2 -> V_52 ) ;
V_2 -> V_9 -= V_49 ;
V_105 -> V_309 -= V_49 ;
F_369 ( & V_105 -> V_304 , - V_49 ) ;
if ( V_2 -> V_280 ) {
V_105 -> V_311 += V_49 ;
V_292 = true ;
}
F_13 ( & V_2 -> V_52 ) ;
if ( ! V_292 && V_241 -> V_105 == V_105 ) {
F_11 ( & V_241 -> V_52 ) ;
if ( ! V_241 -> V_108 ) {
V_49 = F_296 ( V_49 , V_241 -> V_56 -
V_241 -> V_10 ) ;
V_241 -> V_10 += V_49 ;
V_105 -> V_312 += V_49 ;
if ( V_241 -> V_10 >= V_241 -> V_56 )
V_241 -> V_108 = 1 ;
}
F_13 ( & V_241 -> V_52 ) ;
}
F_13 ( & V_105 -> V_52 ) ;
}
if ( V_2 )
F_6 ( V_2 ) ;
return 0 ;
}
int F_370 ( struct V_109 * V_110 ,
struct V_34 * V_35 )
{
struct V_12 * V_37 = V_35 -> V_37 ;
struct V_494 * V_495 ;
T_2 V_32 ;
T_2 V_31 ;
int V_29 ;
if ( V_110 -> V_217 )
return 0 ;
if ( V_37 -> V_58 == & V_37 -> V_38 [ 0 ] )
V_495 = & V_37 -> V_38 [ 1 ] ;
else
V_495 = & V_37 -> V_38 [ 0 ] ;
while ( 1 ) {
V_29 = F_28 ( V_495 , 0 , & V_32 , & V_31 ,
V_59 , NULL ) ;
if ( V_29 )
break;
if ( F_243 ( V_35 , V_496 ) )
V_29 = F_142 ( V_35 , V_32 ,
V_31 + 1 - V_32 , NULL ) ;
F_371 ( V_495 , V_32 , V_31 , V_40 ) ;
F_368 ( V_35 , V_32 , V_31 , true ) ;
F_47 () ;
}
return 0 ;
}
static void F_372 ( struct V_12 * V_37 , T_2 V_36 ,
T_2 V_133 , T_2 V_146 )
{
struct V_102 * V_105 ;
T_2 V_7 ;
if ( V_133 < V_143 ) {
if ( V_146 == V_497 )
V_7 = V_295 ;
else
V_7 = V_293 ;
} else {
V_7 = V_294 ;
}
V_105 = F_69 ( V_37 , V_7 ) ;
F_30 ( ! V_105 ) ;
F_369 ( & V_105 -> V_304 , V_36 ) ;
}
static int F_155 ( struct V_109 * V_110 ,
struct V_34 * V_35 ,
T_2 V_27 , T_2 V_36 , T_2 V_17 ,
T_2 V_146 , T_2 V_498 ,
T_2 V_499 , int V_159 ,
struct V_180 * V_129 ,
int V_201 )
{
struct V_67 V_21 ;
struct V_63 * V_64 ;
struct V_12 * V_13 = V_35 -> V_37 ;
struct V_34 * V_62 = V_13 -> V_62 ;
struct V_65 * V_66 ;
struct V_116 * V_117 ;
struct V_163 * V_164 ;
int V_29 ;
int V_184 ;
int V_500 = 0 ;
int V_501 = 0 ;
int V_502 = 1 ;
T_3 V_118 ;
T_2 V_112 ;
int V_160 = 0 ;
enum V_204 type = V_503 ;
bool V_173 = F_76 ( V_35 -> V_37 ,
V_121 ) ;
if ( ! V_13 -> V_206 || ! F_148 ( V_146 ) )
V_201 = 1 ;
V_64 = F_33 () ;
if ( ! V_64 )
return - V_71 ;
V_64 -> V_75 = 1 ;
V_64 -> V_207 = 1 ;
V_184 = V_498 >= V_143 ;
F_30 ( ! V_184 && V_159 != 1 ) ;
if ( V_184 )
V_173 = 0 ;
V_29 = F_134 ( V_110 , V_62 , V_64 , & V_164 ,
V_27 , V_36 , V_17 ,
V_146 , V_498 ,
V_499 ) ;
if ( V_29 == 0 ) {
V_500 = V_64 -> V_83 [ 0 ] ;
while ( V_500 >= 0 ) {
F_40 ( V_64 -> V_82 [ 0 ] , & V_21 ,
V_500 ) ;
if ( V_21 . V_22 != V_27 )
break;
if ( V_21 . type == V_76 &&
V_21 . V_33 == V_36 ) {
V_501 = 1 ;
break;
}
if ( V_21 . type == V_85 &&
V_21 . V_33 == V_498 ) {
V_501 = 1 ;
break;
}
if ( V_64 -> V_83 [ 0 ] - V_500 > 5 )
break;
V_500 -- ;
}
#ifdef F_81
V_118 = F_77 ( V_64 -> V_82 [ 0 ] , V_500 ) ;
if ( V_501 && V_118 < sizeof( * V_117 ) )
V_501 = 0 ;
#endif
if ( ! V_501 ) {
F_30 ( V_164 ) ;
V_29 = F_139 ( V_110 , V_62 , V_64 ,
NULL , V_159 ,
V_184 , & V_160 ) ;
if ( V_29 ) {
F_150 ( V_110 , V_62 , V_29 ) ;
goto V_72;
}
F_44 ( V_64 ) ;
V_64 -> V_207 = 1 ;
V_21 . V_22 = V_27 ;
V_21 . type = V_76 ;
V_21 . V_33 = V_36 ;
if ( ! V_184 && V_173 ) {
V_21 . type = V_85 ;
V_21 . V_33 = V_498 ;
}
V_29 = F_37 ( V_110 , V_62 ,
& V_21 , V_64 , - 1 , 1 ) ;
if ( V_29 > 0 && V_173 && V_64 -> V_83 [ 0 ] ) {
V_64 -> V_83 [ 0 ] -- ;
F_40 ( V_64 -> V_82 [ 0 ] , & V_21 ,
V_64 -> V_83 [ 0 ] ) ;
if ( V_21 . V_22 == V_27 &&
V_21 . type == V_76 &&
V_21 . V_33 == V_36 )
V_29 = 0 ;
}
if ( V_29 > 0 && V_173 ) {
V_173 = false ;
V_21 . V_22 = V_27 ;
V_21 . type = V_76 ;
V_21 . V_33 = V_36 ;
F_44 ( V_64 ) ;
V_29 = F_37 ( V_110 , V_62 ,
& V_21 , V_64 , - 1 , 1 ) ;
}
if ( V_29 ) {
F_373 ( V_13 , L_15 ,
V_29 , V_27 ) ;
if ( V_29 > 0 )
F_374 ( V_62 ,
V_64 -> V_82 [ 0 ] ) ;
}
if ( V_29 < 0 ) {
F_150 ( V_110 , V_62 , V_29 ) ;
goto V_72;
}
V_500 = V_64 -> V_83 [ 0 ] ;
}
} else if ( F_8 ( V_29 == - V_153 ) ) {
F_374 ( V_62 , V_64 -> V_82 [ 0 ] ) ;
F_373 ( V_13 ,
L_16 ,
V_27 , V_17 , V_146 , V_498 ,
V_499 ) ;
F_150 ( V_110 , V_62 , V_29 ) ;
goto V_72;
} else {
F_150 ( V_110 , V_62 , V_29 ) ;
goto V_72;
}
V_66 = V_64 -> V_82 [ 0 ] ;
V_118 = F_77 ( V_66 , V_500 ) ;
#ifdef F_81
if ( V_118 < sizeof( * V_117 ) ) {
F_30 ( V_501 || V_500 != V_64 -> V_83 [ 0 ] ) ;
V_29 = F_87 ( V_110 , V_62 , V_64 ,
V_498 , 0 ) ;
if ( V_29 < 0 ) {
F_150 ( V_110 , V_62 , V_29 ) ;
goto V_72;
}
F_44 ( V_64 ) ;
V_64 -> V_207 = 1 ;
V_21 . V_22 = V_27 ;
V_21 . type = V_76 ;
V_21 . V_33 = V_36 ;
V_29 = F_37 ( V_110 , V_62 , & V_21 , V_64 ,
- 1 , 1 ) ;
if ( V_29 ) {
F_373 ( V_13 , L_15 ,
V_29 , V_27 ) ;
F_374 ( V_62 , V_64 -> V_82 [ 0 ] ) ;
}
if ( V_29 < 0 ) {
F_150 ( V_110 , V_62 , V_29 ) ;
goto V_72;
}
V_500 = V_64 -> V_83 [ 0 ] ;
V_66 = V_64 -> V_82 [ 0 ] ;
V_118 = F_77 ( V_66 , V_500 ) ;
}
#endif
F_30 ( V_118 < sizeof( * V_117 ) ) ;
V_117 = F_78 ( V_66 , V_500 ,
struct V_116 ) ;
if ( V_498 < V_143 &&
V_21 . type == V_76 ) {
struct V_138 * V_139 ;
F_30 ( V_118 < sizeof( * V_117 ) + sizeof( * V_139 ) ) ;
V_139 = (struct V_138 * ) ( V_117 + 1 ) ;
F_8 ( V_498 != F_375 ( V_66 , V_139 ) ) ;
}
V_112 = F_79 ( V_66 , V_117 ) ;
if ( V_112 < V_159 ) {
F_373 ( V_13 , L_17
L_18 , V_159 , V_112 , V_27 ) ;
V_29 = - V_485 ;
F_150 ( V_110 , V_62 , V_29 ) ;
goto V_72;
}
V_112 -= V_159 ;
if ( V_112 > 0 ) {
type = V_504 ;
if ( V_129 )
F_130 ( V_129 , V_66 , V_117 ) ;
if ( V_164 ) {
F_30 ( ! V_501 ) ;
} else {
F_90 ( V_66 , V_117 , V_112 ) ;
F_95 ( V_66 ) ;
}
if ( V_501 ) {
V_29 = F_139 ( V_110 , V_62 , V_64 ,
V_164 , V_159 ,
V_184 , & V_160 ) ;
if ( V_29 ) {
F_150 ( V_110 , V_62 , V_29 ) ;
goto V_72;
}
}
F_372 ( V_35 -> V_37 , - V_36 , V_498 ,
V_146 ) ;
} else {
if ( V_501 ) {
F_30 ( V_184 && V_159 !=
F_118 ( V_35 , V_64 , V_164 ) ) ;
if ( V_164 ) {
F_30 ( V_64 -> V_83 [ 0 ] != V_500 ) ;
} else {
F_30 ( V_64 -> V_83 [ 0 ] != V_500 + 1 ) ;
V_64 -> V_83 [ 0 ] = V_500 ;
V_502 = 2 ;
}
}
V_160 = 1 ;
V_29 = F_376 ( V_110 , V_62 , V_64 , V_64 -> V_83 [ 0 ] ,
V_502 ) ;
if ( V_29 ) {
F_150 ( V_110 , V_62 , V_29 ) ;
goto V_72;
}
F_44 ( V_64 ) ;
if ( V_184 ) {
V_29 = F_167 ( V_110 , V_35 , V_27 , V_36 ) ;
if ( V_29 ) {
F_150 ( V_110 , V_62 , V_29 ) ;
goto V_72;
}
}
V_29 = F_352 ( V_35 , V_27 , V_36 , 0 ) ;
if ( V_29 ) {
F_150 ( V_110 , V_62 , V_29 ) ;
goto V_72;
}
}
F_44 ( V_64 ) ;
if ( ! V_29 && V_160 && ! V_201 ) {
int V_505 = 0 ;
if ( V_498 >= V_143 &&
type == V_504 )
V_505 = 1 ;
V_29 = F_149 ( V_110 , V_13 , V_146 ,
V_27 , V_36 , type ,
V_505 ) ;
}
V_72:
F_50 ( V_64 ) ;
return V_29 ;
}
static T_1 int F_377 ( struct V_109 * V_110 ,
struct V_34 * V_35 , T_2 V_27 )
{
struct V_113 * V_104 ;
struct V_114 * V_115 ;
int V_29 = 0 ;
V_115 = & V_110 -> V_127 -> V_115 ;
F_11 ( & V_115 -> V_52 ) ;
V_104 = F_84 ( V_110 , V_27 ) ;
if ( ! V_104 )
goto V_506;
F_11 ( & V_104 -> V_52 ) ;
if ( F_178 ( & V_104 -> V_213 ) )
goto V_72;
if ( V_104 -> V_129 ) {
if ( ! V_104 -> V_221 )
goto V_72;
F_176 ( V_104 -> V_129 ) ;
V_104 -> V_129 = NULL ;
}
if ( ! F_85 ( & V_104 -> V_78 ) )
goto V_72;
V_104 -> V_128 . V_225 = 0 ;
F_179 ( & V_104 -> V_227 , & V_115 -> V_228 ) ;
F_180 ( & V_115 -> V_229 ) ;
V_115 -> V_226 -- ;
if ( V_104 -> V_223 == 0 )
V_115 -> V_224 -- ;
V_104 -> V_223 = 0 ;
F_13 ( & V_104 -> V_52 ) ;
F_13 ( & V_115 -> V_52 ) ;
F_30 ( V_104 -> V_129 ) ;
if ( V_104 -> V_221 )
V_29 = 1 ;
F_46 ( & V_104 -> V_78 ) ;
F_86 ( & V_104 -> V_128 ) ;
return V_29 ;
V_72:
F_13 ( & V_104 -> V_52 ) ;
V_506:
F_13 ( & V_115 -> V_52 ) ;
return 0 ;
}
void F_378 ( struct V_109 * V_110 ,
struct V_34 * V_35 ,
struct V_65 * V_261 ,
T_2 V_17 , int V_160 )
{
struct V_1 * V_2 = NULL ;
int V_507 = 1 ;
int V_29 ;
if ( V_35 -> V_257 . V_22 != V_202 ) {
V_29 = F_145 ( V_35 -> V_37 , V_110 ,
V_261 -> V_32 , V_261 -> V_49 ,
V_17 , V_35 -> V_257 . V_22 ,
F_221 ( V_261 ) ,
V_215 , NULL , 0 ) ;
F_30 ( V_29 ) ;
}
if ( ! V_160 )
return;
V_2 = F_68 ( V_35 -> V_37 , V_261 -> V_32 ) ;
if ( F_379 ( V_261 ) == V_110 -> V_282 ) {
if ( V_35 -> V_257 . V_22 != V_202 ) {
V_29 = F_377 ( V_110 , V_35 , V_261 -> V_32 ) ;
if ( ! V_29 )
goto V_72;
}
if ( F_380 ( V_261 , V_508 ) ) {
F_358 ( V_35 , V_2 , V_261 -> V_32 , V_261 -> V_49 , 1 ) ;
goto V_72;
}
F_8 ( F_222 ( V_509 , & V_261 -> V_510 ) ) ;
F_29 ( V_2 , V_261 -> V_32 , V_261 -> V_49 ) ;
F_364 ( V_2 , V_261 -> V_49 , V_491 , 0 ) ;
F_359 ( V_35 , V_261 -> V_32 , V_261 -> V_49 ) ;
V_507 = 0 ;
}
V_72:
if ( V_507 )
F_372 ( V_35 -> V_37 , V_261 -> V_49 ,
F_221 ( V_261 ) ,
V_35 -> V_257 . V_22 ) ;
F_381 ( V_511 , & V_261 -> V_510 ) ;
F_6 ( V_2 ) ;
}
int V_268 ( struct V_109 * V_110 , struct V_34 * V_35 ,
T_2 V_27 , T_2 V_36 , T_2 V_17 , T_2 V_146 ,
T_2 V_133 , T_2 V_33 , int V_201 )
{
int V_29 ;
struct V_12 * V_37 = V_35 -> V_37 ;
if ( F_219 ( V_35 ) )
return 0 ;
F_372 ( V_35 -> V_37 , V_36 , V_133 , V_146 ) ;
if ( V_146 == V_202 ) {
F_8 ( V_133 >= V_143 ) ;
F_163 ( V_35 , V_27 , V_36 , 1 ) ;
V_29 = 0 ;
} else if ( V_133 < V_143 ) {
V_29 = F_145 ( V_37 , V_110 , V_27 ,
V_36 ,
V_17 , V_146 , ( int ) V_133 ,
V_215 , NULL , V_201 ) ;
} else {
V_29 = F_146 ( V_37 , V_110 , V_27 ,
V_36 ,
V_17 , V_146 , V_133 ,
V_33 , V_215 ,
NULL , V_201 ) ;
}
return V_29 ;
}
static T_1 void
F_382 ( struct V_1 * V_2 ,
T_2 V_36 )
{
struct V_50 * V_53 ;
V_53 = F_25 ( V_2 ) ;
if ( ! V_53 )
return;
F_297 ( V_53 -> V_88 , F_1 ( V_2 ) ||
( V_2 -> V_11 -> V_512 >= V_36 ) ) ;
F_26 ( V_53 ) ;
}
static T_1 int
F_383 ( struct V_1 * V_2 )
{
struct V_50 * V_53 ;
int V_29 = 0 ;
V_53 = F_25 ( V_2 ) ;
if ( ! V_53 )
return ( V_2 -> V_3 == V_5 ) ? - V_175 : 0 ;
F_297 ( V_53 -> V_88 , F_1 ( V_2 ) ) ;
if ( V_2 -> V_3 == V_5 )
V_29 = - V_175 ;
F_26 ( V_53 ) ;
return V_29 ;
}
int F_384 ( T_2 V_7 )
{
if ( V_7 & V_301 )
return V_513 ;
else if ( V_7 & V_300 )
return V_514 ;
else if ( V_7 & V_299 )
return V_515 ;
else if ( V_7 & V_341 )
return V_516 ;
else if ( V_7 & V_342 )
return V_517 ;
else if ( V_7 & V_343 )
return V_518 ;
return V_519 ;
}
int F_385 ( struct V_1 * V_2 )
{
return F_384 ( V_2 -> V_7 ) ;
}
static const char * F_386 ( enum V_520 type )
{
if ( type >= V_306 )
return NULL ;
return V_521 [ type ] ;
}
static inline void
F_387 ( struct V_1 * V_2 ,
int V_490 )
{
if ( V_490 )
F_36 ( & V_2 -> V_522 ) ;
}
static inline void
F_388 ( struct V_1 * V_2 ,
int V_490 )
{
F_4 ( V_2 ) ;
if ( V_490 )
F_36 ( & V_2 -> V_522 ) ;
}
static struct V_1 *
F_389 ( struct V_1 * V_14 ,
struct V_523 * V_524 ,
int V_490 )
{
struct V_1 * V_525 ;
bool V_526 = false ;
V_77:
F_11 ( & V_524 -> V_527 ) ;
if ( V_526 ) {
if ( V_525 == V_524 -> V_14 )
return V_525 ;
F_45 ( & V_525 -> V_522 ) ;
F_6 ( V_525 ) ;
}
V_525 = V_524 -> V_14 ;
if ( ! V_525 )
return NULL ;
if ( V_525 == V_14 )
return V_525 ;
F_4 ( V_525 ) ;
if ( ! V_490 )
return V_525 ;
if ( F_289 ( & V_525 -> V_522 ) )
return V_525 ;
F_13 ( & V_524 -> V_527 ) ;
F_36 ( & V_525 -> V_522 ) ;
V_526 = true ;
goto V_77;
}
static inline void
F_390 ( struct V_1 * V_2 ,
int V_490 )
{
if ( V_490 )
F_45 ( & V_2 -> V_522 ) ;
F_6 ( V_2 ) ;
}
static T_1 int F_391 ( struct V_34 * V_528 ,
T_2 V_36 , T_2 V_529 ,
T_2 V_530 , struct V_67 * V_212 ,
T_2 V_7 , int V_490 )
{
int V_29 = 0 ;
struct V_34 * V_35 = V_528 -> V_37 -> V_62 ;
struct V_523 * V_531 = NULL ;
struct V_1 * V_14 = NULL ;
T_2 V_484 = 0 ;
T_2 V_532 = 0 ;
int V_533 = 2 * 1024 * 1024 ;
struct V_102 * V_105 ;
int V_534 = 0 ;
int V_535 = F_384 ( V_7 ) ;
int V_536 = ( V_7 & V_294 ) ?
V_537 : V_492 ;
bool V_538 = false ;
bool V_539 = false ;
bool V_540 = true ;
bool V_541 = false ;
F_8 ( V_36 < V_35 -> V_350 ) ;
V_212 -> type = V_76 ;
V_212 -> V_22 = 0 ;
V_212 -> V_33 = 0 ;
F_392 ( V_528 , V_36 , V_529 , V_7 ) ;
V_105 = F_69 ( V_35 -> V_37 , V_7 ) ;
if ( ! V_105 ) {
F_373 ( V_35 -> V_37 , L_19 , V_7 ) ;
return - V_356 ;
}
if ( F_286 ( V_105 ) )
V_540 = false ;
if ( V_7 & V_293 && V_540 ) {
V_531 = & V_35 -> V_37 -> V_542 ;
if ( ! F_243 ( V_35 , V_543 ) )
V_533 = 64 * 1024 ;
}
if ( ( V_7 & V_294 ) && V_540 &&
F_243 ( V_35 , V_543 ) ) {
V_531 = & V_35 -> V_37 -> V_544 ;
}
if ( V_531 ) {
F_11 ( & V_531 -> V_52 ) ;
if ( V_531 -> V_14 )
V_530 = V_531 -> V_545 ;
F_13 ( & V_531 -> V_52 ) ;
}
V_484 = F_393 ( V_484 , V_26 ( V_35 , 0 ) ) ;
V_484 = F_393 ( V_484 , V_530 ) ;
if ( ! V_531 )
V_533 = 0 ;
if ( V_484 == V_530 ) {
V_14 = F_68 ( V_35 -> V_37 ,
V_484 ) ;
if ( V_14 && F_3 ( V_14 , V_7 ) &&
V_14 -> V_3 != V_94 ) {
F_36 ( & V_105 -> V_308 ) ;
if ( F_204 ( & V_14 -> V_90 ) ||
V_14 -> V_280 ) {
F_6 ( V_14 ) ;
F_45 ( & V_105 -> V_308 ) ;
} else {
V_535 = F_385 ( V_14 ) ;
F_387 ( V_14 , V_490 ) ;
goto V_546;
}
} else if ( V_14 ) {
F_6 ( V_14 ) ;
}
}
V_547:
V_541 = false ;
F_36 ( & V_105 -> V_308 ) ;
F_394 (block_group, &space_info->block_groups[index],
list) {
T_2 V_33 ;
int V_3 ;
F_388 ( V_14 , V_490 ) ;
V_484 = V_14 -> V_21 . V_22 ;
if ( ! F_3 ( V_14 , V_7 ) ) {
T_2 V_548 = V_299 |
V_300 |
V_342 |
V_343 |
V_301 ;
if ( ( V_7 & V_548 ) && ! ( V_14 -> V_7 & V_548 ) )
goto V_534;
}
V_546:
V_3 = F_1 ( V_14 ) ;
if ( F_313 ( ! V_3 ) ) {
V_29 = F_51 ( V_14 , 0 ) ;
F_30 ( V_29 < 0 ) ;
V_29 = 0 ;
}
if ( F_313 ( V_14 -> V_3 == V_5 ) )
goto V_534;
if ( F_313 ( V_14 -> V_280 ) )
goto V_534;
if ( V_531 ) {
struct V_1 * V_549 ;
unsigned long V_550 ;
V_549 = F_389 ( V_14 ,
V_531 ,
V_490 ) ;
if ( ! V_549 )
goto V_551;
if ( V_549 != V_14 &&
( V_549 -> V_280 ||
! F_3 ( V_549 , V_7 ) ) )
goto V_552;
V_33 = F_395 ( V_549 ,
V_531 ,
V_36 ,
V_549 -> V_21 . V_22 ,
& V_532 ) ;
if ( V_33 ) {
F_13 ( & V_531 -> V_527 ) ;
F_396 ( V_35 ,
V_549 ,
V_484 , V_36 ) ;
if ( V_549 != V_14 ) {
F_390 ( V_14 ,
V_490 ) ;
V_14 = V_549 ;
}
goto V_553;
}
F_8 ( V_531 -> V_14 != V_549 ) ;
V_552:
if ( V_534 >= V_554 &&
V_549 != V_14 ) {
F_13 ( & V_531 -> V_527 ) ;
F_390 ( V_549 ,
V_490 ) ;
goto V_555;
}
F_397 ( NULL , V_531 ) ;
if ( V_549 != V_14 )
F_390 ( V_549 ,
V_490 ) ;
V_551:
if ( V_534 >= V_554 ) {
F_13 ( & V_531 -> V_527 ) ;
goto V_555;
}
V_550 = F_34 (unsigned long,
empty_cluster + empty_size,
block_group->full_stripe_len) ;
V_29 = F_398 ( V_35 , V_14 ,
V_531 , V_484 ,
V_36 ,
V_550 ) ;
if ( V_29 == 0 ) {
V_33 = F_395 ( V_14 ,
V_531 ,
V_36 ,
V_484 ,
& V_532 ) ;
if ( V_33 ) {
F_13 ( & V_531 -> V_527 ) ;
F_396 ( V_35 ,
V_14 , V_484 ,
V_36 ) ;
goto V_553;
}
} else if ( ! V_3 && V_534 > V_556
&& ! V_538 ) {
F_13 ( & V_531 -> V_527 ) ;
V_538 = true ;
F_382 ( V_14 ,
V_36 + V_533 + V_529 ) ;
goto V_546;
}
F_397 ( NULL , V_531 ) ;
F_13 ( & V_531 -> V_527 ) ;
goto V_534;
}
V_555:
F_11 ( & V_14 -> V_11 -> V_557 ) ;
if ( V_3 &&
V_14 -> V_11 -> V_512 <
V_36 + V_533 + V_529 ) {
if ( V_14 -> V_11 -> V_512 >
V_532 )
V_532 =
V_14 -> V_11 -> V_512 ;
F_13 ( & V_14 -> V_11 -> V_557 ) ;
goto V_534;
}
F_13 ( & V_14 -> V_11 -> V_557 ) ;
V_33 = F_399 ( V_14 , V_484 ,
V_36 , V_529 ,
& V_532 ) ;
if ( ! V_33 && ! V_539 && ! V_3 &&
V_534 > V_556 ) {
F_382 ( V_14 ,
V_36 + V_529 ) ;
V_539 = true ;
goto V_546;
} else if ( ! V_33 ) {
if ( ! V_3 )
V_541 = true ;
goto V_534;
}
V_553:
V_484 = F_269 ( V_33 , V_35 -> V_558 ) ;
if ( V_484 + V_36 >
V_14 -> V_21 . V_22 + V_14 -> V_21 . V_33 ) {
F_29 ( V_14 , V_33 , V_36 ) ;
goto V_534;
}
if ( V_33 < V_484 )
F_29 ( V_14 , V_33 ,
V_484 - V_33 ) ;
F_30 ( V_33 > V_484 ) ;
V_29 = F_364 ( V_14 , V_36 ,
V_536 , V_490 ) ;
if ( V_29 == - V_178 ) {
F_29 ( V_14 , V_33 , V_36 ) ;
goto V_534;
}
V_212 -> V_22 = V_484 ;
V_212 -> V_33 = V_36 ;
F_400 ( V_528 , V_14 ,
V_484 , V_36 ) ;
F_390 ( V_14 , V_490 ) ;
break;
V_534:
V_538 = false ;
V_539 = false ;
F_30 ( V_535 != F_385 ( V_14 ) ) ;
F_390 ( V_14 , V_490 ) ;
}
F_45 ( & V_105 -> V_308 ) ;
if ( ! V_212 -> V_22 && V_534 >= V_559 && V_541 )
goto V_547;
if ( ! V_212 -> V_22 && ++ V_535 < V_306 )
goto V_547;
if ( ! V_212 -> V_22 && V_534 < V_554 ) {
V_535 = 0 ;
V_534 ++ ;
if ( V_534 == V_560 ) {
struct V_109 * V_110 ;
int V_561 = 0 ;
V_110 = V_351 -> V_352 ;
if ( V_110 )
V_561 = 1 ;
else
V_110 = F_193 ( V_35 ) ;
if ( F_194 ( V_110 ) ) {
V_29 = F_195 ( V_110 ) ;
goto V_72;
}
V_29 = F_271 ( V_110 , V_35 , V_7 ,
V_355 ) ;
if ( V_29 < 0 && V_29 != - V_356 )
F_150 ( V_110 ,
V_35 , V_29 ) ;
else
V_29 = 0 ;
if ( ! V_561 )
F_197 ( V_110 , V_35 ) ;
if ( V_29 )
goto V_72;
}
if ( V_534 == V_554 ) {
V_529 = 0 ;
V_533 = 0 ;
}
goto V_547;
} else if ( ! V_212 -> V_22 ) {
V_29 = - V_356 ;
} else if ( V_212 -> V_22 ) {
V_29 = 0 ;
}
V_72:
if ( V_29 == - V_356 )
V_212 -> V_33 = V_532 ;
return V_29 ;
}
static void F_284 ( struct V_102 * V_13 , T_2 V_346 ,
int V_562 )
{
struct V_1 * V_2 ;
int V_535 = 0 ;
F_11 ( & V_13 -> V_52 ) ;
F_401 ( V_563 L_20 ,
V_13 -> V_7 ,
V_13 -> V_296 - V_13 -> V_297 - V_13 -> V_309 -
V_13 -> V_310 - V_13 -> V_311 ,
( V_13 -> V_108 ) ? L_21 : L_22 ) ;
F_401 ( V_563 L_23
L_24 ,
V_13 -> V_296 , V_13 -> V_297 , V_13 -> V_309 ,
V_13 -> V_310 , V_13 -> V_312 ,
V_13 -> V_311 ) ;
F_13 ( & V_13 -> V_52 ) ;
if ( ! V_562 )
return;
F_36 ( & V_13 -> V_308 ) ;
V_77:
F_394 (cache, &info->block_groups[index], list) {
F_11 ( & V_2 -> V_52 ) ;
F_401 ( V_563 L_25
L_26
L_27 ,
V_2 -> V_21 . V_22 , V_2 -> V_21 . V_33 ,
F_355 ( & V_2 -> V_135 ) , V_2 -> V_9 ,
V_2 -> V_10 , V_2 -> V_280 ? L_28 : L_21 ) ;
F_402 ( V_2 , V_346 ) ;
F_13 ( & V_2 -> V_52 ) ;
}
if ( ++ V_535 < V_306 )
goto V_77;
F_45 ( & V_13 -> V_308 ) ;
}
int F_403 ( struct V_34 * V_35 ,
T_2 V_36 , T_2 V_564 ,
T_2 V_529 , T_2 V_530 ,
struct V_67 * V_212 , int V_184 , int V_490 )
{
bool V_565 = false ;
T_2 V_7 ;
int V_29 ;
V_7 = F_268 ( V_35 , V_184 ) ;
V_77:
F_8 ( V_36 < V_35 -> V_350 ) ;
V_29 = F_391 ( V_35 , V_36 , V_529 , V_530 , V_212 ,
V_7 , V_490 ) ;
if ( V_29 == - V_356 ) {
if ( ! V_565 && V_212 -> V_33 ) {
V_36 = F_296 ( V_36 >> 1 , V_212 -> V_33 ) ;
V_36 = F_404 ( V_36 , V_35 -> V_350 ) ;
V_36 = F_393 ( V_36 , V_564 ) ;
if ( V_36 == V_564 )
V_565 = true ;
goto V_77;
} else if ( F_243 ( V_35 , V_368 ) ) {
struct V_102 * V_360 ;
V_360 = F_69 ( V_35 -> V_37 , V_7 ) ;
F_373 ( V_35 -> V_37 , L_29 ,
V_7 , V_36 ) ;
if ( V_360 )
F_284 ( V_360 , V_36 , 1 ) ;
}
}
return V_29 ;
}
static int F_405 ( struct V_34 * V_35 ,
T_2 V_32 , T_2 V_49 ,
int V_507 , int V_490 )
{
struct V_1 * V_2 ;
int V_29 = 0 ;
V_2 = F_68 ( V_35 -> V_37 , V_32 ) ;
if ( ! V_2 ) {
F_373 ( V_35 -> V_37 , L_30 ,
V_32 ) ;
return - V_356 ;
}
if ( F_243 ( V_35 , V_496 ) )
V_29 = F_142 ( V_35 , V_32 , V_49 , NULL ) ;
if ( V_507 )
F_358 ( V_35 , V_2 , V_32 , V_49 , 1 ) ;
else {
F_29 ( V_2 , V_32 , V_49 ) ;
F_364 ( V_2 , V_49 , V_491 , V_490 ) ;
}
F_6 ( V_2 ) ;
F_359 ( V_35 , V_32 , V_49 ) ;
return V_29 ;
}
int F_406 ( struct V_34 * V_35 ,
T_2 V_32 , T_2 V_49 , int V_490 )
{
return F_405 ( V_35 , V_32 , V_49 , 0 , V_490 ) ;
}
int F_407 ( struct V_34 * V_35 ,
T_2 V_32 , T_2 V_49 )
{
return F_405 ( V_35 , V_32 , V_49 , 1 , 0 ) ;
}
static int F_154 ( struct V_109 * V_110 ,
struct V_34 * V_35 ,
T_2 V_17 , T_2 V_146 ,
T_2 V_7 , T_2 V_133 , T_2 V_33 ,
struct V_67 * V_212 , int V_132 )
{
int V_29 ;
struct V_12 * V_37 = V_35 -> V_37 ;
struct V_116 * V_566 ;
struct V_163 * V_164 ;
struct V_63 * V_64 ;
struct V_65 * V_66 ;
int type ;
T_3 V_56 ;
if ( V_17 > 0 )
type = V_154 ;
else
type = V_155 ;
V_56 = sizeof( * V_566 ) + F_125 ( type ) ;
V_64 = F_33 () ;
if ( ! V_64 )
return - V_71 ;
V_64 -> V_207 = 1 ;
V_29 = F_106 ( V_110 , V_37 -> V_62 , V_64 ,
V_212 , V_56 ) ;
if ( V_29 ) {
F_50 ( V_64 ) ;
return V_29 ;
}
V_66 = V_64 -> V_82 [ 0 ] ;
V_566 = F_78 ( V_66 , V_64 -> V_83 [ 0 ] ,
struct V_116 ) ;
F_90 ( V_66 , V_566 , V_132 ) ;
F_91 ( V_66 , V_566 , V_110 -> V_282 ) ;
F_92 ( V_66 , V_566 ,
V_7 | V_145 ) ;
V_164 = (struct V_163 * ) ( V_566 + 1 ) ;
F_132 ( V_66 , V_164 , type ) ;
if ( V_17 > 0 ) {
struct V_158 * V_151 ;
V_151 = (struct V_158 * ) ( V_164 + 1 ) ;
F_133 ( V_66 , V_164 , V_17 ) ;
F_107 ( V_66 , V_151 , V_132 ) ;
} else {
struct V_150 * V_151 ;
V_151 = (struct V_150 * ) ( & V_164 -> V_33 ) ;
F_109 ( V_66 , V_151 , V_146 ) ;
F_110 ( V_66 , V_151 , V_133 ) ;
F_111 ( V_66 , V_151 , V_33 ) ;
F_112 ( V_66 , V_151 , V_132 ) ;
}
F_95 ( V_64 -> V_82 [ 0 ] ) ;
F_50 ( V_64 ) ;
V_29 = F_149 ( V_110 , V_37 , V_146 ,
V_212 -> V_22 , V_212 -> V_33 ,
V_205 , 0 ) ;
if ( V_29 )
return V_29 ;
V_29 = F_352 ( V_35 , V_212 -> V_22 , V_212 -> V_33 , 1 ) ;
if ( V_29 ) {
F_373 ( V_37 , L_31 ,
V_212 -> V_22 , V_212 -> V_33 ) ;
F_83 () ;
}
F_408 ( V_35 , V_212 -> V_22 , V_212 -> V_33 ) ;
return V_29 ;
}
static int F_161 ( struct V_109 * V_110 ,
struct V_34 * V_35 ,
T_2 V_17 , T_2 V_146 ,
T_2 V_7 , struct V_466 * V_21 ,
int V_167 , struct V_67 * V_212 ,
int V_201 )
{
int V_29 ;
struct V_12 * V_37 = V_35 -> V_37 ;
struct V_116 * V_566 ;
struct V_138 * V_567 ;
struct V_163 * V_164 ;
struct V_63 * V_64 ;
struct V_65 * V_66 ;
T_3 V_56 = sizeof( * V_566 ) + sizeof( * V_164 ) ;
T_2 V_36 = V_212 -> V_33 ;
bool V_173 = F_76 ( V_35 -> V_37 ,
V_121 ) ;
if ( ! V_173 )
V_56 += sizeof( * V_567 ) ;
V_64 = F_33 () ;
if ( ! V_64 ) {
F_407 ( V_35 , V_212 -> V_22 ,
V_35 -> V_87 ) ;
return - V_71 ;
}
V_64 -> V_207 = 1 ;
V_29 = F_106 ( V_110 , V_37 -> V_62 , V_64 ,
V_212 , V_56 ) ;
if ( V_29 ) {
F_407 ( V_35 , V_212 -> V_22 ,
V_35 -> V_87 ) ;
F_50 ( V_64 ) ;
return V_29 ;
}
V_66 = V_64 -> V_82 [ 0 ] ;
V_566 = F_78 ( V_66 , V_64 -> V_83 [ 0 ] ,
struct V_116 ) ;
F_90 ( V_66 , V_566 , 1 ) ;
F_91 ( V_66 , V_566 , V_110 -> V_282 ) ;
F_92 ( V_66 , V_566 ,
V_7 | V_144 ) ;
if ( V_173 ) {
V_164 = (struct V_163 * ) ( V_566 + 1 ) ;
V_36 = V_35 -> V_87 ;
} else {
V_567 = (struct V_138 * ) ( V_566 + 1 ) ;
F_156 ( V_66 , V_567 , V_21 ) ;
F_94 ( V_66 , V_567 , V_167 ) ;
V_164 = (struct V_163 * ) ( V_567 + 1 ) ;
}
if ( V_17 > 0 ) {
F_30 ( ! ( V_7 & V_126 ) ) ;
F_132 ( V_66 , V_164 ,
V_165 ) ;
F_133 ( V_66 , V_164 , V_17 ) ;
} else {
F_132 ( V_66 , V_164 ,
V_166 ) ;
F_133 ( V_66 , V_164 , V_146 ) ;
}
F_95 ( V_66 ) ;
F_50 ( V_64 ) ;
if ( ! V_201 ) {
V_29 = F_149 ( V_110 , V_37 , V_146 ,
V_212 -> V_22 , V_36 ,
V_205 , 0 ) ;
if ( V_29 )
return V_29 ;
}
V_29 = F_352 ( V_35 , V_212 -> V_22 , V_35 -> V_87 , 1 ) ;
if ( V_29 ) {
F_373 ( V_37 , L_31 ,
V_212 -> V_22 , V_212 -> V_33 ) ;
F_83 () ;
}
F_408 ( V_35 , V_212 -> V_22 , V_35 -> V_87 ) ;
return V_29 ;
}
int F_409 ( struct V_109 * V_110 ,
struct V_34 * V_35 ,
T_2 V_146 , T_2 V_133 ,
T_2 V_33 , struct V_67 * V_212 )
{
int V_29 ;
F_30 ( V_146 == V_202 ) ;
V_29 = F_146 ( V_35 -> V_37 , V_110 , V_212 -> V_22 ,
V_212 -> V_33 , 0 ,
V_146 , V_133 , V_33 ,
V_230 , NULL , 0 ) ;
return V_29 ;
}
int F_410 ( struct V_109 * V_110 ,
struct V_34 * V_35 ,
T_2 V_146 , T_2 V_133 , T_2 V_33 ,
struct V_67 * V_212 )
{
int V_29 ;
struct V_1 * V_14 ;
if ( ! F_76 ( V_35 -> V_37 , V_489 ) ) {
V_29 = F_362 ( V_35 , V_212 -> V_22 , V_212 -> V_33 ) ;
if ( V_29 )
return V_29 ;
}
V_14 = F_68 ( V_35 -> V_37 , V_212 -> V_22 ) ;
if ( ! V_14 )
return - V_485 ;
V_29 = F_364 ( V_14 , V_212 -> V_33 ,
V_537 , 0 ) ;
F_30 ( V_29 ) ;
V_29 = F_154 ( V_110 , V_35 , 0 , V_146 ,
0 , V_133 , V_33 , V_212 , 1 ) ;
F_6 ( V_14 ) ;
return V_29 ;
}
static struct V_65 *
F_411 ( struct V_109 * V_110 , struct V_34 * V_35 ,
T_2 V_27 , T_3 V_568 , int V_167 )
{
struct V_65 * V_261 ;
V_261 = F_412 ( V_35 , V_27 , V_568 ) ;
if ( ! V_261 )
return F_413 ( - V_71 ) ;
F_414 ( V_261 , V_110 -> V_282 ) ;
F_415 ( V_35 -> V_257 . V_22 , V_261 , V_167 ) ;
F_416 ( V_261 ) ;
F_417 ( V_110 , V_35 , V_261 ) ;
F_381 ( V_569 , & V_261 -> V_510 ) ;
F_418 ( V_261 ) ;
F_419 ( V_261 ) ;
if ( V_35 -> V_257 . V_22 == V_202 ) {
V_261 -> V_570 = V_35 -> V_571 % 2 ;
if ( V_261 -> V_570 == 0 )
F_357 ( & V_35 -> V_572 , V_261 -> V_32 ,
V_261 -> V_32 + V_261 -> V_49 - 1 , V_40 ) ;
else
F_420 ( & V_35 -> V_572 , V_261 -> V_32 ,
V_261 -> V_32 + V_261 -> V_49 - 1 , V_40 ) ;
} else {
V_261 -> V_570 = - 1 ;
F_357 ( & V_110 -> V_127 -> V_573 , V_261 -> V_32 ,
V_261 -> V_32 + V_261 -> V_49 - 1 , V_40 ) ;
}
V_110 -> V_574 ++ ;
return V_261 ;
}
static struct V_240 *
F_421 ( struct V_109 * V_110 ,
struct V_34 * V_35 , T_3 V_568 )
{
struct V_240 * V_390 ;
struct V_240 * V_241 = & V_35 -> V_37 -> V_242 ;
int V_29 ;
bool V_575 = false ;
V_390 = F_316 ( V_110 , V_35 ) ;
if ( F_313 ( V_390 -> V_56 == 0 ) )
goto V_576;
V_77:
V_29 = F_314 ( V_390 , V_568 ) ;
if ( ! V_29 )
return V_390 ;
if ( V_390 -> V_577 )
return F_413 ( V_29 ) ;
if ( V_390 -> type == V_578 && ! V_575 ) {
V_575 = true ;
F_331 ( V_35 -> V_37 ) ;
goto V_77;
}
if ( F_243 ( V_35 , V_368 ) ) {
static F_422 ( V_579 ,
V_580 * 10 ,
1 ) ;
if ( F_423 ( & V_579 ) )
F_424 ( 1 , V_581
L_32 , V_29 ) ;
}
V_576:
V_29 = F_310 ( V_35 , V_390 , V_568 ,
V_401 ) ;
if ( ! V_29 )
return V_390 ;
if ( V_390 -> type != V_578 &&
V_390 -> V_105 == V_241 -> V_105 ) {
V_29 = F_314 ( V_241 , V_568 ) ;
if ( ! V_29 )
return V_241 ;
}
return F_413 ( V_29 ) ;
}
static void F_425 ( struct V_12 * V_37 ,
struct V_240 * V_390 , T_3 V_568 )
{
F_317 ( V_390 , V_568 , 0 ) ;
F_319 ( V_37 , V_390 , NULL , 0 ) ;
}
struct V_65 * F_426 ( struct V_109 * V_110 ,
struct V_34 * V_35 ,
T_2 V_17 , T_2 V_146 ,
struct V_466 * V_21 , int V_167 ,
T_2 V_582 , T_2 V_529 )
{
struct V_67 V_212 ;
struct V_240 * V_390 ;
struct V_65 * V_261 ;
T_2 V_7 = 0 ;
int V_29 ;
T_3 V_568 = V_35 -> V_87 ;
bool V_173 = F_76 ( V_35 -> V_37 ,
V_121 ) ;
if ( F_219 ( V_35 ) ) {
V_261 = F_411 ( V_110 , V_35 , V_35 -> V_583 ,
V_568 , V_167 ) ;
if ( ! F_194 ( V_261 ) )
V_35 -> V_583 += V_568 ;
return V_261 ;
}
V_390 = F_421 ( V_110 , V_35 , V_568 ) ;
if ( F_194 ( V_390 ) )
return F_427 ( V_390 ) ;
V_29 = F_403 ( V_35 , V_568 , V_568 ,
V_529 , V_582 , & V_212 , 0 , 0 ) ;
if ( V_29 ) {
F_425 ( V_35 -> V_37 , V_390 , V_568 ) ;
return F_413 ( V_29 ) ;
}
V_261 = F_411 ( V_110 , V_35 , V_212 . V_22 ,
V_568 , V_167 ) ;
F_30 ( F_194 ( V_261 ) ) ;
if ( V_146 == V_584 ) {
if ( V_17 == 0 )
V_17 = V_212 . V_22 ;
V_7 |= V_126 ;
} else
F_30 ( V_17 > 0 ) ;
if ( V_146 != V_202 ) {
struct V_180 * V_129 ;
V_129 = F_210 () ;
F_30 ( ! V_129 ) ;
if ( V_21 )
memcpy ( & V_129 -> V_21 , V_21 , sizeof( V_129 -> V_21 ) ) ;
else
memset ( & V_129 -> V_21 , 0 , sizeof( V_129 -> V_21 ) ) ;
V_129 -> V_131 = V_7 ;
if ( V_173 )
V_129 -> V_216 = 0 ;
else
V_129 -> V_216 = 1 ;
V_129 -> V_130 = 1 ;
V_129 -> V_184 = 0 ;
V_129 -> V_167 = V_167 ;
V_29 = F_145 ( V_35 -> V_37 , V_110 ,
V_212 . V_22 ,
V_212 . V_33 , V_17 , V_146 ,
V_167 , V_230 ,
V_129 , 0 ) ;
F_30 ( V_29 ) ;
}
return V_261 ;
}
static T_1 void F_428 ( struct V_109 * V_110 ,
struct V_34 * V_35 ,
struct V_585 * V_586 ,
struct V_63 * V_64 )
{
T_2 V_27 ;
T_2 V_285 ;
T_2 V_112 ;
T_2 V_7 ;
T_3 V_70 ;
T_3 V_568 ;
struct V_67 V_21 ;
struct V_65 * V_487 ;
int V_29 ;
int V_587 ;
int V_588 = 0 ;
if ( V_64 -> V_83 [ V_586 -> V_167 ] < V_586 -> V_589 ) {
V_586 -> V_590 = V_586 -> V_590 * 2 / 3 ;
V_586 -> V_590 = F_393 ( V_586 -> V_590 , 2 ) ;
} else {
V_586 -> V_590 = V_586 -> V_590 * 3 / 2 ;
V_586 -> V_590 = F_24 ( int , V_586 -> V_590 ,
F_429 ( V_35 ) ) ;
}
V_487 = V_64 -> V_82 [ V_586 -> V_167 ] ;
V_70 = F_38 ( V_487 ) ;
V_568 = V_35 -> V_87 ;
for ( V_587 = V_64 -> V_83 [ V_586 -> V_167 ] ; V_587 < V_70 ; V_587 ++ ) {
if ( V_588 >= V_586 -> V_590 )
break;
F_47 () ;
V_27 = F_227 ( V_487 , V_587 ) ;
V_285 = F_430 ( V_487 , V_587 ) ;
if ( V_587 == V_64 -> V_83 [ V_586 -> V_167 ] )
goto V_75;
if ( V_586 -> V_591 == V_592 &&
V_285 <= V_35 -> V_257 . V_33 )
continue;
V_29 = F_75 ( V_110 , V_35 , V_27 ,
V_586 -> V_167 - 1 , 1 , & V_112 ,
& V_7 ) ;
if ( V_29 < 0 )
continue;
F_30 ( V_112 == 0 ) ;
if ( V_586 -> V_591 == V_593 ) {
if ( V_112 == 1 )
goto V_75;
if ( V_586 -> V_167 == 1 &&
( V_7 & V_126 ) )
continue;
if ( ! V_586 -> V_594 ||
V_285 <= V_35 -> V_257 . V_33 )
continue;
F_123 ( V_487 , & V_21 , V_587 ) ;
V_29 = F_431 ( & V_21 ,
& V_586 -> V_595 ) ;
if ( V_29 < 0 )
continue;
} else {
if ( V_586 -> V_167 == 1 &&
( V_7 & V_126 ) )
continue;
}
V_75:
F_432 ( V_35 , V_27 , V_568 ) ;
V_588 ++ ;
}
V_586 -> V_589 = V_587 ;
}
static int F_433 ( struct V_109 * V_110 ,
struct V_34 * V_35 ,
struct V_65 * V_487 )
{
int V_44 = F_38 ( V_487 ) ;
int V_43 , V_596 , V_29 ;
struct V_67 V_21 ;
struct V_264 * V_265 ;
T_2 V_27 , V_36 ;
for ( V_43 = 0 ; V_43 < V_44 ; V_43 ++ ) {
F_40 ( V_487 , & V_21 , V_43 ) ;
if ( V_21 . type != V_269 )
continue;
V_265 = F_78 ( V_487 , V_43 , struct V_264 ) ;
V_596 = F_223 ( V_487 , V_265 ) ;
if ( V_596 == V_270 )
continue;
V_27 = F_224 ( V_487 , V_265 ) ;
if ( ! V_27 )
continue;
V_36 = F_225 ( V_487 , V_265 ) ;
V_29 = F_149 ( V_110 , V_35 -> V_37 ,
V_35 -> V_22 ,
V_27 , V_36 ,
V_597 , 0 ) ;
if ( V_29 )
return V_29 ;
}
return 0 ;
}
static int F_434 ( struct V_34 * V_35 ,
struct V_63 * V_64 , int V_598 )
{
int V_167 = 0 ;
int V_44 , V_587 ;
struct V_65 * V_487 ;
if ( V_598 == 0 )
return 1 ;
while ( V_167 <= V_598 ) {
V_487 = V_64 -> V_82 [ V_167 ] ;
V_44 = F_38 ( V_487 ) ;
V_64 -> V_83 [ V_167 ] ++ ;
V_587 = V_64 -> V_83 [ V_167 ] ;
if ( V_587 >= V_44 || V_167 == 0 ) {
if ( V_167 != V_598 ) {
F_435 ( V_487 , V_64 -> V_599 [ V_167 ] ) ;
V_64 -> V_599 [ V_167 ] = 0 ;
F_436 ( V_487 ) ;
V_64 -> V_82 [ V_167 ] = NULL ;
V_64 -> V_83 [ V_167 ] = 0 ;
}
} else {
break;
}
V_167 ++ ;
}
V_487 = V_64 -> V_82 [ V_598 ] ;
if ( V_64 -> V_83 [ V_598 ] >= F_38 ( V_487 ) )
return 1 ;
return 0 ;
}
static int F_437 ( struct V_109 * V_110 ,
struct V_34 * V_35 ,
struct V_65 * V_600 ,
T_2 V_601 ,
int V_598 )
{
int V_29 = 0 ;
int V_167 ;
struct V_65 * V_487 = V_600 ;
struct V_63 * V_64 = NULL ;
F_30 ( V_598 < 0 || V_598 > V_168 ) ;
F_30 ( V_600 == NULL ) ;
if ( ! V_35 -> V_37 -> V_206 )
return 0 ;
if ( ! F_438 ( V_600 ) ) {
V_29 = F_439 ( V_600 , V_601 ) ;
if ( V_29 )
goto V_72;
}
if ( V_598 == 0 ) {
V_29 = F_433 ( V_110 , V_35 , V_600 ) ;
goto V_72;
}
V_64 = F_33 () ;
if ( ! V_64 )
return - V_71 ;
F_440 ( V_600 ) ;
V_64 -> V_82 [ V_598 ] = V_600 ;
V_64 -> V_83 [ V_598 ] = 0 ;
V_64 -> V_599 [ V_598 ] = 0 ;
V_602:
V_167 = V_598 ;
while ( V_167 >= 0 ) {
if ( V_64 -> V_82 [ V_167 ] == NULL ) {
int V_603 ;
T_2 V_604 ;
T_2 V_605 ;
V_487 = V_64 -> V_82 [ V_167 + 1 ] ;
V_603 = V_64 -> V_83 [ V_167 + 1 ] ;
V_605 = F_227 ( V_487 , V_603 ) ;
V_604 = F_430 ( V_487 , V_603 ) ;
V_487 = F_441 ( V_35 , V_605 , V_604 ) ;
if ( ! V_487 || ! F_438 ( V_487 ) ) {
V_29 = - V_175 ;
goto V_72;
}
V_64 -> V_82 [ V_167 ] = V_487 ;
V_64 -> V_83 [ V_167 ] = 0 ;
F_442 ( V_487 ) ;
F_443 ( V_487 , V_606 ) ;
V_64 -> V_599 [ V_167 ] = V_607 ;
V_29 = F_149 ( V_110 , V_35 -> V_37 ,
V_35 -> V_22 ,
V_605 ,
V_35 -> V_87 ,
V_597 ,
0 ) ;
if ( V_29 )
goto V_72;
}
if ( V_167 == 0 ) {
V_29 = F_433 ( V_110 , V_35 , V_64 -> V_82 [ V_167 ] ) ;
if ( V_29 )
goto V_72;
V_29 = F_434 ( V_35 , V_64 , V_598 ) ;
if ( V_29 )
break;
goto V_602;
}
V_167 -- ;
}
V_29 = 0 ;
V_72:
F_50 ( V_64 ) ;
return V_29 ;
}
static T_1 int F_444 ( struct V_109 * V_110 ,
struct V_34 * V_35 ,
struct V_63 * V_64 ,
struct V_585 * V_586 , int V_608 )
{
int V_167 = V_586 -> V_167 ;
struct V_65 * V_487 = V_64 -> V_82 [ V_167 ] ;
T_2 V_609 = V_126 ;
int V_29 ;
if ( V_586 -> V_591 == V_592 &&
F_220 ( V_487 ) != V_35 -> V_257 . V_22 )
return 1 ;
if ( V_608 &&
( ( V_586 -> V_591 == V_593 && V_586 -> V_112 [ V_167 ] != 1 ) ||
( V_586 -> V_591 == V_592 && ! ( V_586 -> V_7 [ V_167 ] & V_609 ) ) ) ) {
F_30 ( ! V_64 -> V_599 [ V_167 ] ) ;
V_29 = F_75 ( V_110 , V_35 ,
V_487 -> V_32 , V_167 , 1 ,
& V_586 -> V_112 [ V_167 ] ,
& V_586 -> V_7 [ V_167 ] ) ;
F_30 ( V_29 == - V_71 ) ;
if ( V_29 )
return V_29 ;
F_30 ( V_586 -> V_112 [ V_167 ] == 0 ) ;
}
if ( V_586 -> V_591 == V_593 ) {
if ( V_586 -> V_112 [ V_167 ] > 1 )
return 1 ;
if ( V_64 -> V_599 [ V_167 ] && ! V_586 -> V_174 ) {
F_435 ( V_487 , V_64 -> V_599 [ V_167 ] ) ;
V_64 -> V_599 [ V_167 ] = 0 ;
}
return 0 ;
}
if ( ! ( V_586 -> V_7 [ V_167 ] & V_609 ) ) {
F_30 ( ! V_64 -> V_599 [ V_167 ] ) ;
V_29 = F_228 ( V_110 , V_35 , V_487 , 1 ) ;
F_30 ( V_29 ) ;
V_29 = F_229 ( V_110 , V_35 , V_487 , 0 ) ;
F_30 ( V_29 ) ;
V_29 = F_209 ( V_110 , V_35 , V_487 -> V_32 ,
V_487 -> V_49 , V_609 ,
F_221 ( V_487 ) , 0 ) ;
F_30 ( V_29 ) ;
V_586 -> V_7 [ V_167 ] |= V_609 ;
}
if ( V_64 -> V_599 [ V_167 ] && V_167 > 0 ) {
F_435 ( V_487 , V_64 -> V_599 [ V_167 ] ) ;
V_64 -> V_599 [ V_167 ] = 0 ;
}
return 0 ;
}
static T_1 int F_445 ( struct V_109 * V_110 ,
struct V_34 * V_35 ,
struct V_63 * V_64 ,
struct V_585 * V_586 , int * V_608 )
{
T_2 V_27 ;
T_2 V_285 ;
T_2 V_17 ;
T_3 V_568 ;
struct V_67 V_21 ;
struct V_65 * V_80 ;
int V_167 = V_586 -> V_167 ;
int V_75 = 0 ;
int V_29 = 0 ;
bool V_610 = false ;
V_285 = F_430 ( V_64 -> V_82 [ V_167 ] ,
V_64 -> V_83 [ V_167 ] ) ;
if ( V_586 -> V_591 == V_592 &&
V_285 <= V_35 -> V_257 . V_33 ) {
* V_608 = 1 ;
return 1 ;
}
V_27 = F_227 ( V_64 -> V_82 [ V_167 ] , V_64 -> V_83 [ V_167 ] ) ;
V_568 = V_35 -> V_87 ;
V_80 = F_446 ( V_35 , V_27 ) ;
if ( ! V_80 ) {
V_80 = F_412 ( V_35 , V_27 , V_568 ) ;
if ( ! V_80 )
return - V_71 ;
F_415 ( V_35 -> V_257 . V_22 , V_80 ,
V_167 - 1 ) ;
V_75 = 1 ;
}
F_416 ( V_80 ) ;
F_418 ( V_80 ) ;
V_29 = F_75 ( V_110 , V_35 , V_27 , V_167 - 1 , 1 ,
& V_586 -> V_112 [ V_167 - 1 ] ,
& V_586 -> V_7 [ V_167 - 1 ] ) ;
if ( V_29 < 0 ) {
F_447 ( V_80 ) ;
return V_29 ;
}
if ( F_313 ( V_586 -> V_112 [ V_167 - 1 ] == 0 ) ) {
F_373 ( V_35 -> V_37 , L_33 ) ;
F_83 () ;
}
* V_608 = 0 ;
if ( V_586 -> V_591 == V_593 ) {
if ( V_586 -> V_112 [ V_167 - 1 ] > 1 ) {
V_610 = true ;
if ( V_167 == 1 &&
( V_586 -> V_7 [ 0 ] & V_126 ) )
goto V_611;
if ( ! V_586 -> V_594 ||
V_285 <= V_35 -> V_257 . V_33 )
goto V_611;
F_123 ( V_64 -> V_82 [ V_167 ] , & V_21 ,
V_64 -> V_83 [ V_167 ] ) ;
V_29 = F_431 ( & V_21 , & V_586 -> V_595 ) ;
if ( V_29 < 0 )
goto V_611;
V_586 -> V_591 = V_592 ;
V_586 -> V_612 = V_167 - 1 ;
}
} else {
if ( V_167 == 1 &&
( V_586 -> V_7 [ 0 ] & V_126 ) )
goto V_611;
}
if ( ! F_448 ( V_80 , V_285 , 0 ) ) {
F_447 ( V_80 ) ;
F_436 ( V_80 ) ;
V_80 = NULL ;
* V_608 = 1 ;
}
if ( ! V_80 ) {
if ( V_75 && V_167 == 1 )
F_428 ( V_110 , V_35 , V_586 , V_64 ) ;
V_80 = F_441 ( V_35 , V_27 , V_285 ) ;
if ( ! V_80 || ! F_438 ( V_80 ) ) {
F_436 ( V_80 ) ;
return - V_175 ;
}
F_416 ( V_80 ) ;
F_418 ( V_80 ) ;
}
V_167 -- ;
F_30 ( V_167 != F_221 ( V_80 ) ) ;
V_64 -> V_82 [ V_167 ] = V_80 ;
V_64 -> V_83 [ V_167 ] = 0 ;
V_64 -> V_599 [ V_167 ] = V_613 ;
V_586 -> V_167 = V_167 ;
if ( V_586 -> V_167 == 1 )
V_586 -> V_589 = 0 ;
return 0 ;
V_611:
V_586 -> V_112 [ V_167 - 1 ] = 0 ;
V_586 -> V_7 [ V_167 - 1 ] = 0 ;
if ( V_586 -> V_591 == V_593 ) {
if ( V_586 -> V_7 [ V_167 ] & V_126 ) {
V_17 = V_64 -> V_82 [ V_167 ] -> V_32 ;
} else {
F_30 ( V_35 -> V_257 . V_22 !=
F_220 ( V_64 -> V_82 [ V_167 ] ) ) ;
V_17 = 0 ;
}
if ( V_610 ) {
V_29 = F_437 ( V_110 , V_35 , V_80 ,
V_285 , V_167 - 1 ) ;
if ( V_29 ) {
F_449 ( V_614 L_34
L_35
L_36 ,
V_35 -> V_37 -> V_384 -> V_615 , V_29 ) ;
}
}
V_29 = V_268 ( V_110 , V_35 , V_27 , V_568 , V_17 ,
V_35 -> V_257 . V_22 , V_167 - 1 , 0 , 0 ) ;
F_30 ( V_29 ) ;
}
F_447 ( V_80 ) ;
F_436 ( V_80 ) ;
* V_608 = 1 ;
return 1 ;
}
static T_1 int F_450 ( struct V_109 * V_110 ,
struct V_34 * V_35 ,
struct V_63 * V_64 ,
struct V_585 * V_586 )
{
int V_29 ;
int V_167 = V_586 -> V_167 ;
struct V_65 * V_487 = V_64 -> V_82 [ V_167 ] ;
T_2 V_17 = 0 ;
if ( V_586 -> V_591 == V_592 ) {
F_30 ( V_586 -> V_612 < V_167 ) ;
if ( V_167 < V_586 -> V_612 )
goto V_72;
V_29 = F_41 ( V_64 , V_167 + 1 , & V_586 -> V_595 ) ;
if ( V_29 > 0 )
V_586 -> V_594 = 0 ;
V_586 -> V_591 = V_593 ;
V_586 -> V_612 = - 1 ;
V_64 -> V_83 [ V_167 ] = 0 ;
if ( ! V_64 -> V_599 [ V_167 ] ) {
F_30 ( V_167 == 0 ) ;
F_416 ( V_487 ) ;
F_418 ( V_487 ) ;
V_64 -> V_599 [ V_167 ] = V_613 ;
V_29 = F_75 ( V_110 , V_35 ,
V_487 -> V_32 , V_167 , 1 ,
& V_586 -> V_112 [ V_167 ] ,
& V_586 -> V_7 [ V_167 ] ) ;
if ( V_29 < 0 ) {
F_435 ( V_487 , V_64 -> V_599 [ V_167 ] ) ;
V_64 -> V_599 [ V_167 ] = 0 ;
return V_29 ;
}
F_30 ( V_586 -> V_112 [ V_167 ] == 0 ) ;
if ( V_586 -> V_112 [ V_167 ] == 1 ) {
F_435 ( V_487 , V_64 -> V_599 [ V_167 ] ) ;
V_64 -> V_599 [ V_167 ] = 0 ;
return 1 ;
}
}
}
F_30 ( V_586 -> V_112 [ V_167 ] > 1 && ! V_64 -> V_599 [ V_167 ] ) ;
if ( V_586 -> V_112 [ V_167 ] == 1 ) {
if ( V_167 == 0 ) {
if ( V_586 -> V_7 [ V_167 ] & V_126 )
V_29 = F_229 ( V_110 , V_35 , V_487 , 1 ) ;
else
V_29 = F_229 ( V_110 , V_35 , V_487 , 0 ) ;
F_30 ( V_29 ) ;
V_29 = F_433 ( V_110 , V_35 , V_487 ) ;
if ( V_29 ) {
F_449 ( V_614 L_34
L_37
L_36 ,
V_35 -> V_37 -> V_384 -> V_615 , V_29 ) ;
}
}
if ( ! V_64 -> V_599 [ V_167 ] &&
F_379 ( V_487 ) == V_110 -> V_282 ) {
F_416 ( V_487 ) ;
F_418 ( V_487 ) ;
V_64 -> V_599 [ V_167 ] = V_613 ;
}
F_417 ( V_110 , V_35 , V_487 ) ;
}
if ( V_487 == V_35 -> V_128 ) {
if ( V_586 -> V_7 [ V_167 ] & V_126 )
V_17 = V_487 -> V_32 ;
else
F_30 ( V_35 -> V_257 . V_22 !=
F_220 ( V_487 ) ) ;
} else {
if ( V_586 -> V_7 [ V_167 + 1 ] & V_126 )
V_17 = V_64 -> V_82 [ V_167 + 1 ] -> V_32 ;
else
F_30 ( V_35 -> V_257 . V_22 !=
F_220 ( V_64 -> V_82 [ V_167 + 1 ] ) ) ;
}
F_378 ( V_110 , V_35 , V_487 , V_17 , V_586 -> V_112 [ V_167 ] == 1 ) ;
V_72:
V_586 -> V_112 [ V_167 ] = 0 ;
V_586 -> V_7 [ V_167 ] = 0 ;
return 0 ;
}
static T_1 int F_451 ( struct V_109 * V_110 ,
struct V_34 * V_35 ,
struct V_63 * V_64 ,
struct V_585 * V_586 )
{
int V_167 = V_586 -> V_167 ;
int V_608 = 1 ;
int V_29 ;
while ( V_167 >= 0 ) {
V_29 = F_444 ( V_110 , V_35 , V_64 , V_586 , V_608 ) ;
if ( V_29 > 0 )
break;
if ( V_167 == 0 )
break;
if ( V_64 -> V_83 [ V_167 ] >=
F_38 ( V_64 -> V_82 [ V_167 ] ) )
break;
V_29 = F_445 ( V_110 , V_35 , V_64 , V_586 , & V_608 ) ;
if ( V_29 > 0 ) {
V_64 -> V_83 [ V_167 ] ++ ;
continue;
} else if ( V_29 < 0 )
return V_29 ;
V_167 = V_586 -> V_167 ;
}
return 0 ;
}
static T_1 int F_452 ( struct V_109 * V_110 ,
struct V_34 * V_35 ,
struct V_63 * V_64 ,
struct V_585 * V_586 , int V_616 )
{
int V_167 = V_586 -> V_167 ;
int V_29 ;
V_64 -> V_83 [ V_167 ] = F_38 ( V_64 -> V_82 [ V_167 ] ) ;
while ( V_167 < V_616 && V_64 -> V_82 [ V_167 ] ) {
V_586 -> V_167 = V_167 ;
if ( V_64 -> V_83 [ V_167 ] + 1 <
F_38 ( V_64 -> V_82 [ V_167 ] ) ) {
V_64 -> V_83 [ V_167 ] ++ ;
return 0 ;
} else {
V_29 = F_450 ( V_110 , V_35 , V_64 , V_586 ) ;
if ( V_29 > 0 )
return 0 ;
if ( V_64 -> V_599 [ V_167 ] ) {
F_435 ( V_64 -> V_82 [ V_167 ] ,
V_64 -> V_599 [ V_167 ] ) ;
V_64 -> V_599 [ V_167 ] = 0 ;
}
F_436 ( V_64 -> V_82 [ V_167 ] ) ;
V_64 -> V_82 [ V_167 ] = NULL ;
V_167 ++ ;
}
}
return 1 ;
}
int F_453 ( struct V_34 * V_35 ,
struct V_240 * V_390 , int V_594 ,
int V_617 )
{
struct V_63 * V_64 ;
struct V_109 * V_110 ;
struct V_34 * V_86 = V_35 -> V_37 -> V_86 ;
struct V_618 * V_258 = & V_35 -> V_258 ;
struct V_585 * V_586 ;
struct V_67 V_21 ;
int V_81 = 0 ;
int V_29 ;
int V_167 ;
bool V_619 = false ;
F_177 ( V_35 -> V_37 , L_38 , V_35 -> V_22 ) ;
V_64 = F_33 () ;
if ( ! V_64 ) {
V_81 = - V_71 ;
goto V_72;
}
V_586 = F_53 ( sizeof( * V_586 ) , V_40 ) ;
if ( ! V_586 ) {
F_50 ( V_64 ) ;
V_81 = - V_71 ;
goto V_72;
}
V_110 = F_454 ( V_86 , 0 ) ;
if ( F_194 ( V_110 ) ) {
V_81 = F_195 ( V_110 ) ;
goto V_123;
}
if ( V_390 )
V_110 -> V_390 = V_390 ;
if ( F_455 ( & V_258 -> V_620 ) == 0 ) {
V_167 = F_221 ( V_35 -> V_128 ) ;
V_64 -> V_82 [ V_167 ] = F_456 ( V_35 ) ;
F_418 ( V_64 -> V_82 [ V_167 ] ) ;
V_64 -> V_83 [ V_167 ] = 0 ;
V_64 -> V_599 [ V_167 ] = V_613 ;
memset ( & V_586 -> V_595 , 0 ,
sizeof( V_586 -> V_595 ) ) ;
} else {
F_457 ( & V_21 , & V_258 -> V_620 ) ;
memcpy ( & V_586 -> V_595 , & V_21 ,
sizeof( V_586 -> V_595 ) ) ;
V_167 = V_258 -> V_621 ;
F_30 ( V_167 == 0 ) ;
V_64 -> V_622 = V_167 ;
V_29 = F_37 ( NULL , V_35 , & V_21 , V_64 , 0 , 0 ) ;
V_64 -> V_622 = 0 ;
if ( V_29 < 0 ) {
V_81 = V_29 ;
goto V_623;
}
F_8 ( V_29 > 0 ) ;
F_128 ( V_64 , 0 ) ;
V_167 = F_221 ( V_35 -> V_128 ) ;
while ( 1 ) {
F_416 ( V_64 -> V_82 [ V_167 ] ) ;
F_418 ( V_64 -> V_82 [ V_167 ] ) ;
V_64 -> V_599 [ V_167 ] = V_613 ;
V_29 = F_75 ( V_110 , V_35 ,
V_64 -> V_82 [ V_167 ] -> V_32 ,
V_167 , 1 , & V_586 -> V_112 [ V_167 ] ,
& V_586 -> V_7 [ V_167 ] ) ;
if ( V_29 < 0 ) {
V_81 = V_29 ;
goto V_623;
}
F_30 ( V_586 -> V_112 [ V_167 ] == 0 ) ;
if ( V_167 == V_258 -> V_621 )
break;
F_447 ( V_64 -> V_82 [ V_167 ] ) ;
V_64 -> V_599 [ V_167 ] = 0 ;
F_8 ( V_586 -> V_112 [ V_167 ] != 1 ) ;
V_167 -- ;
}
}
V_586 -> V_167 = V_167 ;
V_586 -> V_612 = - 1 ;
V_586 -> V_591 = V_593 ;
V_586 -> V_594 = V_594 ;
V_586 -> V_174 = 0 ;
V_586 -> V_617 = V_617 ;
V_586 -> V_590 = F_429 ( V_35 ) ;
while ( 1 ) {
V_29 = F_451 ( V_110 , V_35 , V_64 , V_586 ) ;
if ( V_29 < 0 ) {
V_81 = V_29 ;
break;
}
V_29 = F_452 ( V_110 , V_35 , V_64 , V_586 , V_168 ) ;
if ( V_29 < 0 ) {
V_81 = V_29 ;
break;
}
if ( V_29 > 0 ) {
F_30 ( V_586 -> V_591 != V_593 ) ;
break;
}
if ( V_586 -> V_591 == V_593 ) {
V_167 = V_586 -> V_167 ;
F_458 ( V_64 -> V_82 [ V_167 ] ,
& V_258 -> V_620 ,
V_64 -> V_83 [ V_167 ] ) ;
V_258 -> V_621 = V_167 ;
}
F_30 ( V_586 -> V_167 == 0 ) ;
if ( F_459 ( V_110 , V_86 ) ||
( ! V_617 && F_460 ( V_35 ) ) ) {
V_29 = F_461 ( V_110 , V_86 ,
& V_35 -> V_257 ,
V_258 ) ;
if ( V_29 ) {
F_150 ( V_110 , V_86 , V_29 ) ;
V_81 = V_29 ;
goto V_623;
}
V_29 = F_207 ( V_110 ,
V_35 -> V_37 ) ;
if ( V_29 )
F_449 ( V_614 L_39
L_40
L_41
L_42
L_43 , V_29 ) ;
F_462 ( V_110 , V_86 ) ;
if ( ! V_617 && F_460 ( V_35 ) ) {
F_463 ( L_44 ) ;
V_81 = - V_178 ;
goto V_123;
}
V_110 = F_454 ( V_86 , 0 ) ;
if ( F_194 ( V_110 ) ) {
V_81 = F_195 ( V_110 ) ;
goto V_123;
}
if ( V_390 )
V_110 -> V_390 = V_390 ;
}
}
F_44 ( V_64 ) ;
if ( V_81 )
goto V_623;
V_29 = F_464 ( V_110 , V_86 , & V_35 -> V_257 ) ;
if ( V_29 ) {
F_150 ( V_110 , V_86 , V_29 ) ;
goto V_623;
}
if ( V_35 -> V_257 . V_22 != V_584 ) {
V_29 = F_465 ( V_86 , & V_35 -> V_257 , V_64 ,
NULL , NULL ) ;
if ( V_29 < 0 ) {
F_150 ( V_110 , V_86 , V_29 ) ;
V_81 = V_29 ;
goto V_623;
} else if ( V_29 > 0 ) {
F_466 ( V_110 , V_86 ,
V_35 -> V_257 . V_22 ) ;
}
}
if ( F_222 ( V_624 , & V_35 -> V_267 ) ) {
F_467 ( V_86 -> V_37 , V_35 ) ;
} else {
F_436 ( V_35 -> V_128 ) ;
F_436 ( V_35 -> V_625 ) ;
F_468 ( V_35 ) ;
}
V_619 = true ;
V_623:
V_29 = F_207 ( V_110 , V_86 -> V_37 ) ;
if ( V_29 )
F_449 ( V_614 L_39
L_40
L_41
L_42
L_43 , V_29 ) ;
F_462 ( V_110 , V_86 ) ;
V_123:
F_9 ( V_586 ) ;
F_50 ( V_64 ) ;
V_72:
if ( ! V_617 && V_619 == false )
F_469 ( V_35 ) ;
if ( V_81 && V_81 != - V_178 )
F_470 ( V_35 -> V_37 , V_81 ) ;
return V_81 ;
}
int F_471 ( struct V_109 * V_110 ,
struct V_34 * V_35 ,
struct V_65 * V_128 ,
struct V_65 * V_17 )
{
struct V_63 * V_64 ;
struct V_585 * V_586 ;
int V_167 ;
int V_626 ;
int V_29 = 0 ;
int V_627 ;
F_30 ( V_35 -> V_257 . V_22 != V_584 ) ;
V_64 = F_33 () ;
if ( ! V_64 )
return - V_71 ;
V_586 = F_53 ( sizeof( * V_586 ) , V_40 ) ;
if ( ! V_586 ) {
F_50 ( V_64 ) ;
return - V_71 ;
}
F_472 ( V_17 ) ;
V_626 = F_221 ( V_17 ) ;
F_440 ( V_17 ) ;
V_64 -> V_82 [ V_626 ] = V_17 ;
V_64 -> V_83 [ V_626 ] = F_38 ( V_17 ) ;
F_472 ( V_128 ) ;
V_167 = F_221 ( V_128 ) ;
V_64 -> V_82 [ V_167 ] = V_128 ;
V_64 -> V_83 [ V_167 ] = 0 ;
V_64 -> V_599 [ V_167 ] = V_613 ;
V_586 -> V_112 [ V_626 ] = 1 ;
V_586 -> V_7 [ V_626 ] = V_126 ;
V_586 -> V_167 = V_167 ;
V_586 -> V_612 = - 1 ;
V_586 -> V_591 = V_593 ;
V_586 -> V_594 = 0 ;
V_586 -> V_174 = 1 ;
V_586 -> V_617 = 1 ;
V_586 -> V_590 = F_429 ( V_35 ) ;
while ( 1 ) {
V_627 = F_451 ( V_110 , V_35 , V_64 , V_586 ) ;
if ( V_627 < 0 ) {
V_29 = V_627 ;
break;
}
V_627 = F_452 ( V_110 , V_35 , V_64 , V_586 , V_626 ) ;
if ( V_627 < 0 )
V_29 = V_627 ;
if ( V_627 != 0 )
break;
}
F_9 ( V_586 ) ;
F_50 ( V_64 ) ;
return V_29 ;
}
static T_2 F_473 ( struct V_34 * V_35 , T_2 V_7 )
{
T_2 V_336 ;
T_2 V_628 ;
V_628 = F_262 ( V_35 -> V_37 , V_7 ) ;
if ( V_628 )
return F_264 ( V_628 ) ;
V_336 = V_35 -> V_37 -> V_337 -> V_338 ;
V_628 = V_341 |
V_342 | V_343 |
V_300 | V_301 ;
if ( V_336 == 1 ) {
V_628 |= V_299 ;
V_628 = V_7 & ~ V_628 ;
if ( V_7 & V_341 )
return V_628 ;
if ( V_7 & ( V_300 |
V_301 ) )
return V_628 | V_299 ;
} else {
if ( V_7 & V_628 )
return V_7 ;
V_628 |= V_299 ;
V_628 = V_7 & ~ V_628 ;
if ( V_7 & V_299 )
return V_628 | V_300 ;
}
return V_7 ;
}
static int F_474 ( struct V_1 * V_2 , int V_361 )
{
struct V_102 * V_360 = V_2 -> V_105 ;
T_2 V_36 ;
T_2 V_629 ;
int V_29 = - V_356 ;
if ( ( V_360 -> V_7 &
( V_295 | V_293 ) ) &&
! V_361 )
V_629 = 1 * 1024 * 1024 ;
else
V_629 = 0 ;
F_11 ( & V_360 -> V_52 ) ;
F_11 ( & V_2 -> V_52 ) ;
if ( V_2 -> V_280 ) {
V_29 = 0 ;
goto V_72;
}
V_36 = V_2 -> V_21 . V_33 - V_2 -> V_10 - V_2 -> V_9 -
V_2 -> V_46 - F_355 ( & V_2 -> V_135 ) ;
if ( V_360 -> V_297 + V_360 -> V_310 + V_360 -> V_309 +
V_360 -> V_312 + V_360 -> V_311 + V_36 +
V_629 <= V_360 -> V_296 ) {
V_360 -> V_311 += V_36 ;
V_2 -> V_280 = 1 ;
F_64 ( & V_2 -> V_630 , & V_360 -> V_317 ) ;
V_29 = 0 ;
}
V_72:
F_13 ( & V_2 -> V_52 ) ;
F_13 ( & V_360 -> V_52 ) ;
return V_29 ;
}
int F_475 ( struct V_34 * V_35 ,
struct V_1 * V_2 )
{
struct V_109 * V_110 ;
T_2 V_631 ;
int V_29 ;
F_30 ( V_2 -> V_280 ) ;
V_110 = F_193 ( V_35 ) ;
if ( F_194 ( V_110 ) )
return F_195 ( V_110 ) ;
V_631 = F_473 ( V_35 , V_2 -> V_7 ) ;
if ( V_631 != V_2 -> V_7 ) {
V_29 = F_271 ( V_110 , V_35 , V_631 ,
V_355 ) ;
if ( V_29 < 0 )
goto V_72;
}
V_29 = F_474 ( V_2 , 0 ) ;
if ( ! V_29 )
goto V_72;
V_631 = F_265 ( V_35 , V_2 -> V_105 -> V_7 ) ;
V_29 = F_271 ( V_110 , V_35 , V_631 ,
V_355 ) ;
if ( V_29 < 0 )
goto V_72;
V_29 = F_474 ( V_2 , 0 ) ;
V_72:
F_197 ( V_110 , V_35 ) ;
return V_29 ;
}
int F_476 ( struct V_109 * V_110 ,
struct V_34 * V_35 , T_2 type )
{
T_2 V_631 = F_265 ( V_35 , type ) ;
return F_271 ( V_110 , V_35 , V_631 ,
V_355 ) ;
}
T_2 F_477 ( struct V_102 * V_360 )
{
struct V_1 * V_14 ;
T_2 V_632 = 0 ;
int V_298 ;
if ( F_204 ( & V_360 -> V_317 ) )
return 0 ;
F_11 ( & V_360 -> V_52 ) ;
F_394 (block_group, &sinfo->ro_bgs, ro_list) {
F_11 ( & V_14 -> V_52 ) ;
if ( ! V_14 -> V_280 ) {
F_13 ( & V_14 -> V_52 ) ;
continue;
}
if ( V_14 -> V_7 & ( V_300 |
V_301 |
V_299 ) )
V_298 = 2 ;
else
V_298 = 1 ;
V_632 += ( V_14 -> V_21 . V_33 -
F_355 ( & V_14 -> V_135 ) ) *
V_298 ;
F_13 ( & V_14 -> V_52 ) ;
}
F_13 ( & V_360 -> V_52 ) ;
return V_632 ;
}
void F_478 ( struct V_34 * V_35 ,
struct V_1 * V_2 )
{
struct V_102 * V_360 = V_2 -> V_105 ;
T_2 V_36 ;
F_30 ( ! V_2 -> V_280 ) ;
F_11 ( & V_360 -> V_52 ) ;
F_11 ( & V_2 -> V_52 ) ;
V_36 = V_2 -> V_21 . V_33 - V_2 -> V_10 - V_2 -> V_9 -
V_2 -> V_46 - F_355 ( & V_2 -> V_135 ) ;
V_360 -> V_311 -= V_36 ;
V_2 -> V_280 = 0 ;
F_367 ( & V_2 -> V_630 ) ;
F_13 ( & V_2 -> V_52 ) ;
F_13 ( & V_360 -> V_52 ) ;
}
int F_479 ( struct V_34 * V_35 , T_2 V_27 )
{
struct V_1 * V_14 ;
struct V_102 * V_105 ;
struct V_633 * V_337 = V_35 -> V_37 -> V_337 ;
struct V_634 * V_635 ;
struct V_109 * V_110 ;
T_2 V_636 ;
T_2 V_637 = 1 ;
T_2 V_638 = 0 ;
T_2 V_331 ;
int V_535 ;
int V_108 = 0 ;
int V_29 = 0 ;
V_14 = F_68 ( V_35 -> V_37 , V_27 ) ;
if ( ! V_14 )
return - 1 ;
V_636 = F_355 ( & V_14 -> V_135 ) ;
if ( ! V_636 )
goto V_72;
V_105 = V_14 -> V_105 ;
F_11 ( & V_105 -> V_52 ) ;
V_108 = V_105 -> V_108 ;
if ( ( V_105 -> V_296 != V_14 -> V_21 . V_33 ) &&
( V_105 -> V_297 + V_105 -> V_310 +
V_105 -> V_309 + V_105 -> V_311 +
V_636 < V_105 -> V_296 ) ) {
F_13 ( & V_105 -> V_52 ) ;
goto V_72;
}
F_13 ( & V_105 -> V_52 ) ;
V_29 = - 1 ;
V_331 = F_262 ( V_35 -> V_37 , V_14 -> V_7 ) ;
if ( V_331 ) {
V_535 = F_384 ( F_264 ( V_331 ) ) ;
} else {
if ( V_108 )
goto V_72;
V_535 = F_385 ( V_14 ) ;
}
if ( V_535 == V_513 ) {
V_637 = 4 ;
V_636 >>= 1 ;
} else if ( V_535 == V_514 ) {
V_637 = 2 ;
} else if ( V_535 == V_515 ) {
V_636 <<= 1 ;
} else if ( V_535 == V_516 ) {
V_637 = V_337 -> V_338 ;
F_480 ( V_636 , V_637 ) ;
}
V_110 = F_193 ( V_35 ) ;
if ( F_194 ( V_110 ) ) {
V_29 = F_195 ( V_110 ) ;
goto V_72;
}
F_35 ( & V_35 -> V_37 -> V_371 ) ;
F_394 (device, &fs_devices->alloc_list, dev_alloc_list) {
T_2 V_639 ;
if ( V_635 -> V_296 > V_635 -> V_297 + V_636 &&
! V_635 -> V_640 ) {
V_29 = F_481 ( V_110 , V_635 , V_636 ,
& V_639 , NULL ) ;
if ( ! V_29 )
V_638 ++ ;
if ( V_638 >= V_637 )
break;
V_29 = - 1 ;
}
}
F_46 ( & V_35 -> V_37 -> V_371 ) ;
F_197 ( V_110 , V_35 ) ;
V_72:
F_6 ( V_14 ) ;
return V_29 ;
}
static int F_482 ( struct V_34 * V_35 ,
struct V_63 * V_64 , struct V_67 * V_21 )
{
int V_29 = 0 ;
struct V_67 V_140 ;
struct V_65 * V_66 ;
int V_587 ;
V_29 = F_37 ( NULL , V_35 , V_21 , V_64 , 0 , 0 ) ;
if ( V_29 < 0 )
goto V_72;
while ( 1 ) {
V_587 = V_64 -> V_83 [ 0 ] ;
V_66 = V_64 -> V_82 [ 0 ] ;
if ( V_587 >= F_38 ( V_66 ) ) {
V_29 = F_48 ( V_35 , V_64 ) ;
if ( V_29 == 0 )
continue;
if ( V_29 < 0 )
goto V_72;
break;
}
F_40 ( V_66 , & V_140 , V_587 ) ;
if ( V_140 . V_22 >= V_21 -> V_22 &&
V_140 . type == V_179 ) {
V_29 = 0 ;
goto V_72;
}
V_64 -> V_83 [ 0 ] ++ ;
}
V_72:
return V_29 ;
}
void F_483 ( struct V_12 * V_13 )
{
struct V_1 * V_14 ;
T_2 V_69 = 0 ;
while ( 1 ) {
struct V_272 * V_272 ;
V_14 = F_67 ( V_13 , V_69 ) ;
while ( V_14 ) {
F_11 ( & V_14 -> V_52 ) ;
if ( V_14 -> V_164 )
break;
F_13 ( & V_14 -> V_52 ) ;
V_14 = F_233 ( V_13 -> V_86 ,
V_14 ) ;
}
if ( ! V_14 ) {
if ( V_69 == 0 )
break;
V_69 = 0 ;
continue;
}
V_272 = V_14 -> V_272 ;
V_14 -> V_164 = 0 ;
V_14 -> V_272 = NULL ;
F_13 ( & V_14 -> V_52 ) ;
F_247 ( V_272 ) ;
V_69 = V_14 -> V_21 . V_22 + V_14 -> V_21 . V_33 ;
F_6 ( V_14 ) ;
}
}
int F_484 ( struct V_12 * V_13 )
{
struct V_1 * V_14 ;
struct V_102 * V_105 ;
struct V_50 * V_53 ;
struct V_15 * V_30 ;
F_63 ( & V_13 -> V_79 ) ;
while ( ! F_204 ( & V_13 -> V_100 ) ) {
V_53 = F_485 ( V_13 -> V_100 . V_80 ,
struct V_50 , V_90 ) ;
F_486 ( & V_53 -> V_90 ) ;
F_26 ( V_53 ) ;
}
F_65 ( & V_13 -> V_79 ) ;
F_11 ( & V_13 -> V_481 ) ;
while ( ! F_204 ( & V_13 -> V_483 ) ) {
V_14 = F_487 ( & V_13 -> V_483 ,
struct V_1 ,
V_482 ) ;
F_367 ( & V_14 -> V_482 ) ;
F_6 ( V_14 ) ;
}
F_13 ( & V_13 -> V_481 ) ;
F_11 ( & V_13 -> V_18 ) ;
while ( ( V_30 = F_185 ( & V_13 -> V_19 ) ) != NULL ) {
V_14 = F_12 ( V_30 , struct V_1 ,
V_20 ) ;
F_179 ( & V_14 -> V_20 ,
& V_13 -> V_19 ) ;
F_488 ( & V_14 -> V_20 ) ;
F_13 ( & V_13 -> V_18 ) ;
F_63 ( & V_14 -> V_105 -> V_308 ) ;
F_486 ( & V_14 -> V_90 ) ;
F_65 ( & V_14 -> V_105 -> V_308 ) ;
if ( V_14 -> V_3 == V_98 )
F_383 ( V_14 ) ;
if ( V_14 -> V_3 == V_94 ||
V_14 -> V_3 == V_5 )
F_19 ( V_13 -> V_62 , V_14 ) ;
F_489 ( V_14 ) ;
F_6 ( V_14 ) ;
F_11 ( & V_13 -> V_18 ) ;
}
F_13 ( & V_13 -> V_18 ) ;
F_490 () ;
F_333 ( V_13 ) ;
while ( ! F_204 ( & V_13 -> V_105 ) ) {
int V_43 ;
V_105 = F_485 ( V_13 -> V_105 . V_80 ,
struct V_102 ,
V_90 ) ;
if ( F_243 ( V_13 -> V_86 , V_368 ) ) {
if ( F_8 ( V_105 -> V_309 > 0 ||
V_105 -> V_310 > 0 ||
V_105 -> V_312 > 0 ) ) {
F_284 ( V_105 , 0 , 0 ) ;
}
}
F_486 ( & V_105 -> V_90 ) ;
for ( V_43 = 0 ; V_43 < V_306 ; V_43 ++ ) {
struct V_641 * V_318 ;
V_318 = V_105 -> V_642 [ V_43 ] ;
V_105 -> V_642 [ V_43 ] = NULL ;
if ( V_318 ) {
F_491 ( V_318 ) ;
F_492 ( V_318 ) ;
}
}
F_491 ( & V_105 -> V_318 ) ;
F_492 ( & V_105 -> V_318 ) ;
}
return 0 ;
}
static void F_493 ( struct V_102 * V_105 ,
struct V_1 * V_2 )
{
int V_535 = F_385 ( V_2 ) ;
bool V_238 = false ;
F_63 ( & V_105 -> V_308 ) ;
if ( F_204 ( & V_105 -> V_307 [ V_535 ] ) )
V_238 = true ;
F_64 ( & V_2 -> V_90 , & V_105 -> V_307 [ V_535 ] ) ;
F_65 ( & V_105 -> V_308 ) ;
if ( V_238 ) {
struct V_643 * V_644 ;
int V_29 ;
V_644 = F_53 ( sizeof( * V_644 ) , V_40 ) ;
if ( ! V_644 )
goto V_645;
V_644 -> V_646 = V_535 ;
F_494 ( & V_644 -> V_318 , & V_647 ) ;
V_29 = F_495 ( & V_644 -> V_318 , & V_105 -> V_318 ,
L_8 , F_386 ( V_535 ) ) ;
if ( V_29 ) {
F_492 ( & V_644 -> V_318 ) ;
goto V_645;
}
V_105 -> V_642 [ V_535 ] = & V_644 -> V_318 ;
}
return;
V_645:
F_496 ( L_45 ) ;
}
static struct V_1 *
F_497 ( struct V_34 * V_35 , T_2 V_32 , T_2 V_56 )
{
struct V_1 * V_2 ;
V_2 = F_53 ( sizeof( * V_2 ) , V_40 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_11 = F_53 ( sizeof( * V_2 -> V_11 ) ,
V_40 ) ;
if ( ! V_2 -> V_11 ) {
F_9 ( V_2 ) ;
return NULL ;
}
V_2 -> V_21 . V_22 = V_32 ;
V_2 -> V_21 . V_33 = V_56 ;
V_2 -> V_21 . type = V_179 ;
V_2 -> V_350 = V_35 -> V_350 ;
V_2 -> V_37 = V_35 -> V_37 ;
V_2 -> V_648 = F_498 ( V_35 ,
& V_35 -> V_37 -> V_48 ,
V_32 ) ;
F_57 ( & V_2 -> V_8 , 1 ) ;
F_255 ( & V_2 -> V_52 ) ;
F_254 ( & V_2 -> V_522 ) ;
F_54 ( & V_2 -> V_90 ) ;
F_54 ( & V_2 -> V_649 ) ;
F_54 ( & V_2 -> V_482 ) ;
F_54 ( & V_2 -> V_630 ) ;
F_499 ( V_2 ) ;
F_57 ( & V_2 -> V_650 , 0 ) ;
return V_2 ;
}
int F_500 ( struct V_34 * V_35 )
{
struct V_63 * V_64 ;
int V_29 ;
struct V_1 * V_2 ;
struct V_12 * V_13 = V_35 -> V_37 ;
struct V_102 * V_105 ;
struct V_67 V_21 ;
struct V_67 V_140 ;
struct V_65 * V_66 ;
int V_651 = 0 ;
T_2 V_652 ;
V_35 = V_13 -> V_62 ;
V_21 . V_22 = 0 ;
V_21 . V_33 = 0 ;
V_21 . type = V_179 ;
V_64 = F_33 () ;
if ( ! V_64 )
return - V_71 ;
V_64 -> V_75 = 1 ;
V_652 = F_501 ( V_35 -> V_37 -> V_365 ) ;
if ( F_243 ( V_35 , V_286 ) &&
F_502 ( V_35 -> V_37 -> V_365 ) != V_652 )
V_651 = 1 ;
if ( F_243 ( V_35 , V_653 ) )
V_651 = 1 ;
while ( 1 ) {
V_29 = F_482 ( V_35 , V_64 , & V_21 ) ;
if ( V_29 > 0 )
break;
if ( V_29 != 0 )
goto error;
V_66 = V_64 -> V_82 [ 0 ] ;
F_40 ( V_66 , & V_140 , V_64 -> V_83 [ 0 ] ) ;
V_2 = F_497 ( V_35 , V_140 . V_22 ,
V_140 . V_33 ) ;
if ( ! V_2 ) {
V_29 = - V_71 ;
goto error;
}
if ( V_651 ) {
V_2 -> V_278 = V_289 ;
if ( F_243 ( V_35 , V_286 ) )
V_2 -> V_290 = 1 ;
}
F_503 ( V_66 , & V_2 -> V_135 ,
F_231 ( V_66 , V_64 -> V_83 [ 0 ] ) ,
sizeof( V_2 -> V_135 ) ) ;
V_2 -> V_7 = F_504 ( & V_2 -> V_135 ) ;
V_21 . V_22 = V_140 . V_22 + V_140 . V_33 ;
F_44 ( V_64 ) ;
V_29 = F_21 ( V_35 , V_2 ) ;
if ( V_29 ) {
F_19 ( V_35 , V_2 ) ;
F_6 ( V_2 ) ;
goto error;
}
if ( V_140 . V_33 == F_355 ( & V_2 -> V_135 ) ) {
V_2 -> V_97 = ( T_2 ) - 1 ;
V_2 -> V_3 = V_4 ;
F_19 ( V_35 , V_2 ) ;
} else if ( F_355 ( & V_2 -> V_135 ) == 0 ) {
V_2 -> V_97 = ( T_2 ) - 1 ;
V_2 -> V_3 = V_4 ;
F_27 ( V_2 , V_35 -> V_37 ,
V_140 . V_22 ,
V_140 . V_22 +
V_140 . V_33 ) ;
F_19 ( V_35 , V_2 ) ;
}
V_29 = F_10 ( V_35 -> V_37 , V_2 ) ;
if ( V_29 ) {
F_489 ( V_2 ) ;
F_6 ( V_2 ) ;
goto error;
}
V_29 = F_252 ( V_13 , V_2 -> V_7 , V_140 . V_33 ,
F_355 ( & V_2 -> V_135 ) ,
& V_105 ) ;
if ( V_29 ) {
F_489 ( V_2 ) ;
F_11 ( & V_13 -> V_18 ) ;
F_179 ( & V_2 -> V_20 ,
& V_13 -> V_19 ) ;
F_488 ( & V_2 -> V_20 ) ;
F_13 ( & V_13 -> V_18 ) ;
F_6 ( V_2 ) ;
goto error;
}
V_2 -> V_105 = V_105 ;
F_11 ( & V_2 -> V_105 -> V_52 ) ;
V_2 -> V_105 -> V_311 += V_2 -> V_46 ;
F_13 ( & V_2 -> V_105 -> V_52 ) ;
F_493 ( V_105 , V_2 ) ;
F_258 ( V_35 -> V_37 , V_2 -> V_7 ) ;
if ( F_505 ( V_35 , V_2 -> V_21 . V_22 ) ) {
F_474 ( V_2 , 1 ) ;
} else if ( F_355 ( & V_2 -> V_135 ) == 0 ) {
F_11 ( & V_13 -> V_481 ) ;
if ( F_204 ( & V_2 -> V_482 ) ) {
F_4 ( V_2 ) ;
F_64 ( & V_2 -> V_482 ,
& V_13 -> V_483 ) ;
}
F_13 ( & V_13 -> V_481 ) ;
}
}
F_71 (space_info, &root->fs_info->space_info, list) {
if ( ! ( F_265 ( V_35 , V_105 -> V_7 ) &
( V_301 |
V_300 |
V_342 |
V_343 |
V_299 ) ) )
continue;
F_394 (cache,
&space_info->block_groups[BTRFS_RAID_RAID0],
list)
F_474 ( V_2 , 1 ) ;
F_394 (cache,
&space_info->block_groups[BTRFS_RAID_SINGLE],
list)
F_474 ( V_2 , 1 ) ;
}
F_332 ( V_13 ) ;
V_29 = 0 ;
error:
F_50 ( V_64 ) ;
return V_29 ;
}
void F_205 ( struct V_109 * V_110 ,
struct V_34 * V_35 )
{
struct V_1 * V_14 , * V_339 ;
struct V_34 * V_62 = V_35 -> V_37 -> V_62 ;
struct V_654 V_135 ;
struct V_67 V_21 ;
int V_29 = 0 ;
F_366 (block_group, tmp, &trans->new_bgs, bg_list) {
if ( V_29 )
goto V_80;
F_11 ( & V_14 -> V_52 ) ;
memcpy ( & V_135 , & V_14 -> V_135 , sizeof( V_135 ) ) ;
memcpy ( & V_21 , & V_14 -> V_21 , sizeof( V_21 ) ) ;
F_13 ( & V_14 -> V_52 ) ;
V_29 = F_506 ( V_110 , V_62 , & V_21 , & V_135 ,
sizeof( V_135 ) ) ;
if ( V_29 )
F_150 ( V_110 , V_62 , V_29 ) ;
V_29 = F_507 ( V_110 , V_62 ,
V_21 . V_22 , V_21 . V_33 ) ;
if ( V_29 )
F_150 ( V_110 , V_62 , V_29 ) ;
V_80:
F_367 ( & V_14 -> V_482 ) ;
}
}
int F_508 ( struct V_109 * V_110 ,
struct V_34 * V_35 , T_2 V_297 ,
T_2 type , T_2 V_655 , T_2 V_656 ,
T_2 V_56 )
{
int V_29 ;
struct V_34 * V_62 ;
struct V_1 * V_2 ;
V_62 = V_35 -> V_37 -> V_62 ;
F_509 ( V_35 -> V_37 , V_110 ) ;
V_2 = F_497 ( V_35 , V_656 , V_56 ) ;
if ( ! V_2 )
return - V_71 ;
F_356 ( & V_2 -> V_135 , V_297 ) ;
F_510 ( & V_2 -> V_135 , V_655 ) ;
F_511 ( & V_2 -> V_135 , type ) ;
V_2 -> V_7 = type ;
V_2 -> V_97 = ( T_2 ) - 1 ;
V_2 -> V_3 = V_4 ;
V_29 = F_21 ( V_35 , V_2 ) ;
if ( V_29 ) {
F_19 ( V_35 , V_2 ) ;
F_6 ( V_2 ) ;
return V_29 ;
}
F_27 ( V_2 , V_35 -> V_37 , V_656 ,
V_656 + V_56 ) ;
F_19 ( V_35 , V_2 ) ;
V_29 = F_10 ( V_35 -> V_37 , V_2 ) ;
if ( V_29 ) {
F_489 ( V_2 ) ;
F_6 ( V_2 ) ;
return V_29 ;
}
V_29 = F_252 ( V_35 -> V_37 , V_2 -> V_7 , V_56 , V_297 ,
& V_2 -> V_105 ) ;
if ( V_29 ) {
F_489 ( V_2 ) ;
F_11 ( & V_35 -> V_37 -> V_18 ) ;
F_179 ( & V_2 -> V_20 ,
& V_35 -> V_37 -> V_19 ) ;
F_488 ( & V_2 -> V_20 ) ;
F_13 ( & V_35 -> V_37 -> V_18 ) ;
F_6 ( V_2 ) ;
return V_29 ;
}
F_331 ( V_35 -> V_37 ) ;
F_11 ( & V_2 -> V_105 -> V_52 ) ;
V_2 -> V_105 -> V_311 += V_2 -> V_46 ;
F_13 ( & V_2 -> V_105 -> V_52 ) ;
F_493 ( V_2 -> V_105 , V_2 ) ;
F_64 ( & V_2 -> V_482 , & V_110 -> V_255 ) ;
F_258 ( V_62 -> V_37 , type ) ;
return 0 ;
}
static void F_512 ( struct V_12 * V_37 , T_2 V_7 )
{
T_2 V_322 = F_259 ( V_7 ) &
V_323 ;
F_260 ( & V_37 -> V_324 ) ;
if ( V_7 & V_294 )
V_37 -> V_325 &= ~ V_322 ;
if ( V_7 & V_293 )
V_37 -> V_326 &= ~ V_322 ;
if ( V_7 & V_295 )
V_37 -> V_327 &= ~ V_322 ;
F_261 ( & V_37 -> V_324 ) ;
}
int F_513 ( struct V_109 * V_110 ,
struct V_34 * V_35 , T_2 V_657 ,
struct V_658 * V_659 )
{
struct V_63 * V_64 ;
struct V_1 * V_14 ;
struct V_523 * V_524 ;
struct V_34 * V_86 = V_35 -> V_37 -> V_86 ;
struct V_67 V_21 ;
struct V_272 * V_272 ;
struct V_641 * V_318 = NULL ;
int V_29 ;
int V_535 ;
int V_298 ;
struct V_50 * V_53 = NULL ;
bool V_660 ;
V_35 = V_35 -> V_37 -> V_62 ;
V_14 = F_68 ( V_35 -> V_37 , V_657 ) ;
F_30 ( ! V_14 ) ;
F_30 ( ! V_14 -> V_280 ) ;
F_19 ( V_35 , V_14 ) ;
memcpy ( & V_21 , & V_14 -> V_21 , sizeof( V_21 ) ) ;
V_535 = F_385 ( V_14 ) ;
if ( V_14 -> V_7 & ( V_299 |
V_300 |
V_301 ) )
V_298 = 2 ;
else
V_298 = 1 ;
V_524 = & V_35 -> V_37 -> V_544 ;
F_11 ( & V_524 -> V_527 ) ;
F_397 ( V_14 , V_524 ) ;
F_13 ( & V_524 -> V_527 ) ;
V_524 = & V_35 -> V_37 -> V_542 ;
F_11 ( & V_524 -> V_527 ) ;
F_397 ( V_14 , V_524 ) ;
F_13 ( & V_524 -> V_527 ) ;
V_64 = F_33 () ;
if ( ! V_64 ) {
V_29 = - V_71 ;
goto V_72;
}
V_272 = F_236 ( V_86 , V_14 , V_64 ) ;
if ( ! F_194 ( V_272 ) ) {
V_29 = F_514 ( V_110 , V_272 ) ;
if ( V_29 ) {
F_515 ( V_272 ) ;
goto V_72;
}
F_516 ( V_272 ) ;
F_11 ( & V_14 -> V_52 ) ;
if ( V_14 -> V_164 ) {
V_14 -> V_164 = 0 ;
V_14 -> V_272 = NULL ;
F_13 ( & V_14 -> V_52 ) ;
F_247 ( V_272 ) ;
} else {
F_13 ( & V_14 -> V_52 ) ;
}
F_515 ( V_272 ) ;
}
V_21 . V_22 = V_661 ;
V_21 . V_33 = V_14 -> V_21 . V_22 ;
V_21 . type = 0 ;
V_29 = F_37 ( V_110 , V_86 , & V_21 , V_64 , - 1 , 1 ) ;
if ( V_29 < 0 )
goto V_72;
if ( V_29 > 0 )
F_44 ( V_64 ) ;
if ( V_29 == 0 ) {
V_29 = F_116 ( V_110 , V_86 , V_64 ) ;
if ( V_29 )
goto V_72;
F_44 ( V_64 ) ;
}
F_11 ( & V_35 -> V_37 -> V_18 ) ;
F_179 ( & V_14 -> V_20 ,
& V_35 -> V_37 -> V_19 ) ;
F_488 ( & V_14 -> V_20 ) ;
if ( V_35 -> V_37 -> V_26 == V_14 -> V_21 . V_22 )
V_35 -> V_37 -> V_26 = ( T_2 ) - 1 ;
F_13 ( & V_35 -> V_37 -> V_18 ) ;
F_63 ( & V_14 -> V_105 -> V_308 ) ;
F_367 ( & V_14 -> V_90 ) ;
if ( F_204 ( & V_14 -> V_105 -> V_307 [ V_535 ] ) ) {
V_318 = V_14 -> V_105 -> V_642 [ V_535 ] ;
V_14 -> V_105 -> V_642 [ V_535 ] = NULL ;
F_512 ( V_35 -> V_37 , V_14 -> V_7 ) ;
}
F_65 ( & V_14 -> V_105 -> V_308 ) ;
if ( V_318 ) {
F_491 ( V_318 ) ;
F_492 ( V_318 ) ;
}
if ( V_14 -> V_99 )
V_53 = F_25 ( V_14 ) ;
if ( V_14 -> V_3 == V_98 )
F_383 ( V_14 ) ;
if ( V_14 -> V_99 ) {
F_63 ( & V_35 -> V_37 -> V_79 ) ;
if ( ! V_53 ) {
struct V_50 * V_51 ;
F_394 (ctl,
&root->fs_info->caching_block_groups, list)
if ( V_51 -> V_14 == V_14 ) {
V_53 = V_51 ;
F_5 ( & V_53 -> V_8 ) ;
break;
}
}
if ( V_53 )
F_367 ( & V_53 -> V_90 ) ;
F_65 ( & V_35 -> V_37 -> V_79 ) ;
if ( V_53 ) {
F_26 ( V_53 ) ;
F_26 ( V_53 ) ;
}
}
F_489 ( V_14 ) ;
F_11 ( & V_14 -> V_105 -> V_52 ) ;
F_367 ( & V_14 -> V_630 ) ;
V_14 -> V_105 -> V_296 -= V_14 -> V_21 . V_33 ;
V_14 -> V_105 -> V_311 -= V_14 -> V_21 . V_33 ;
V_14 -> V_105 -> V_302 -= V_14 -> V_21 . V_33 * V_298 ;
F_13 ( & V_14 -> V_105 -> V_52 ) ;
memcpy ( & V_21 , & V_14 -> V_21 , sizeof( V_21 ) ) ;
F_517 ( V_35 ) ;
if ( ! F_204 ( & V_659 -> V_90 ) ) {
F_518 ( V_659 ) ;
}
F_11 ( & V_14 -> V_52 ) ;
V_14 -> V_662 = 1 ;
V_660 = ( F_191 ( & V_14 -> V_650 ) == 0 ) ;
if ( ! V_660 ) {
F_519 ( & V_659 -> V_90 , & V_35 -> V_37 -> V_663 ) ;
}
F_13 ( & V_14 -> V_52 ) ;
if ( V_660 ) {
struct V_664 * V_665 ;
V_665 = & V_35 -> V_37 -> V_48 . V_666 ;
F_520 ( & V_665 -> V_52 ) ;
F_521 ( V_665 , V_659 ) ;
F_522 ( & V_665 -> V_52 ) ;
F_518 ( V_659 ) ;
}
F_523 ( V_35 ) ;
F_6 ( V_14 ) ;
F_6 ( V_14 ) ;
V_29 = F_37 ( V_110 , V_35 , & V_21 , V_64 , - 1 , 1 ) ;
if ( V_29 > 0 )
V_29 = - V_175 ;
if ( V_29 < 0 )
goto V_72;
V_29 = F_116 ( V_110 , V_35 , V_64 ) ;
V_72:
F_50 ( V_64 ) ;
return V_29 ;
}
void F_524 ( struct V_12 * V_37 )
{
struct V_1 * V_14 ;
struct V_102 * V_105 ;
struct V_34 * V_35 = V_37 -> V_62 ;
struct V_109 * V_110 ;
int V_29 = 0 ;
if ( ! V_37 -> V_667 )
return;
F_11 ( & V_37 -> V_481 ) ;
while ( ! F_204 ( & V_37 -> V_483 ) ) {
T_2 V_32 , V_31 ;
V_14 = F_487 ( & V_37 -> V_483 ,
struct V_1 ,
V_482 ) ;
V_105 = V_14 -> V_105 ;
F_367 ( & V_14 -> V_482 ) ;
if ( V_29 || F_286 ( V_105 ) ) {
F_6 ( V_14 ) ;
continue;
}
F_13 ( & V_37 -> V_481 ) ;
F_63 ( & V_105 -> V_308 ) ;
F_11 ( & V_14 -> V_52 ) ;
if ( V_14 -> V_10 ||
F_355 ( & V_14 -> V_135 ) ||
V_14 -> V_280 ) {
F_13 ( & V_14 -> V_52 ) ;
F_65 ( & V_105 -> V_308 ) ;
goto V_80;
}
F_13 ( & V_14 -> V_52 ) ;
V_29 = F_474 ( V_14 , 0 ) ;
F_65 ( & V_105 -> V_308 ) ;
if ( V_29 < 0 ) {
V_29 = 0 ;
goto V_80;
}
V_110 = F_193 ( V_35 ) ;
if ( F_194 ( V_110 ) ) {
F_478 ( V_35 , V_14 ) ;
V_29 = F_195 ( V_110 ) ;
goto V_80;
}
V_32 = V_14 -> V_21 . V_22 ;
V_31 = V_32 + V_14 -> V_21 . V_33 - 1 ;
V_29 = F_20 ( & V_37 -> V_38 [ 0 ] , V_32 , V_31 ,
V_59 , V_40 ) ;
if ( V_29 ) {
F_478 ( V_35 , V_14 ) ;
goto V_668;
}
V_29 = F_20 ( & V_37 -> V_38 [ 1 ] , V_32 , V_31 ,
V_59 , V_40 ) ;
if ( V_29 ) {
F_478 ( V_35 , V_14 ) ;
goto V_668;
}
V_14 -> V_9 = 0 ;
V_29 = F_525 ( V_110 , V_35 ,
V_14 -> V_21 . V_22 ) ;
V_668:
F_197 ( V_110 , V_35 ) ;
V_80:
F_6 ( V_14 ) ;
F_11 ( & V_37 -> V_481 ) ;
}
F_13 ( & V_37 -> V_481 ) ;
}
int F_526 ( struct V_12 * V_37 )
{
struct V_102 * V_105 ;
struct V_669 * V_670 ;
T_2 V_671 ;
T_2 V_7 ;
int V_672 = 0 ;
int V_29 ;
V_670 = V_37 -> V_365 ;
if ( ! F_527 ( V_670 ) )
return 1 ;
V_671 = F_528 ( V_670 ) ;
if ( V_671 & V_673 )
V_672 = 1 ;
V_7 = V_295 ;
V_29 = F_252 ( V_37 , V_7 , 0 , 0 , & V_105 ) ;
if ( V_29 )
goto V_72;
if ( V_672 ) {
V_7 = V_293 | V_294 ;
V_29 = F_252 ( V_37 , V_7 , 0 , 0 , & V_105 ) ;
} else {
V_7 = V_293 ;
V_29 = F_252 ( V_37 , V_7 , 0 , 0 , & V_105 ) ;
if ( V_29 )
goto V_72;
V_7 = V_294 ;
V_29 = F_252 ( V_37 , V_7 , 0 , 0 , & V_105 ) ;
}
V_72:
return V_29 ;
}
int F_529 ( struct V_34 * V_35 , T_2 V_32 , T_2 V_31 )
{
return F_368 ( V_35 , V_32 , V_31 , false ) ;
}
int F_530 ( struct V_34 * V_35 , struct V_674 * V_675 )
{
struct V_12 * V_37 = V_35 -> V_37 ;
struct V_1 * V_2 = NULL ;
T_2 V_676 ;
T_2 V_32 ;
T_2 V_31 ;
T_2 V_677 = 0 ;
T_2 V_296 = F_278 ( V_37 -> V_365 ) ;
int V_29 = 0 ;
if ( V_675 -> V_49 == V_296 )
V_2 = F_67 ( V_37 , V_675 -> V_32 ) ;
else
V_2 = F_68 ( V_37 , V_675 -> V_32 ) ;
while ( V_2 ) {
if ( V_2 -> V_21 . V_22 >= ( V_675 -> V_32 + V_675 -> V_49 ) ) {
F_6 ( V_2 ) ;
break;
}
V_32 = F_393 ( V_675 -> V_32 , V_2 -> V_21 . V_22 ) ;
V_31 = F_296 ( V_675 -> V_32 + V_675 -> V_49 ,
V_2 -> V_21 . V_22 + V_2 -> V_21 . V_33 ) ;
if ( V_31 - V_32 >= V_675 -> V_678 ) {
if ( ! F_1 ( V_2 ) ) {
V_29 = F_51 ( V_2 , 0 ) ;
if ( V_29 ) {
F_6 ( V_2 ) ;
break;
}
V_29 = F_383 ( V_2 ) ;
if ( V_29 ) {
F_6 ( V_2 ) ;
break;
}
}
V_29 = F_531 ( V_2 ,
& V_676 ,
V_32 ,
V_31 ,
V_675 -> V_678 ) ;
V_677 += V_676 ;
if ( V_29 ) {
F_6 ( V_2 ) ;
break;
}
}
V_2 = F_233 ( V_37 -> V_86 , V_2 ) ;
}
V_675 -> V_49 = V_677 ;
return V_29 ;
}
void F_532 ( struct V_34 * V_35 )
{
F_533 ( & V_35 -> V_679 -> V_680 ) ;
F_2 () ;
if ( F_534 ( & V_35 -> V_679 -> V_88 ) )
F_49 ( & V_35 -> V_679 -> V_88 ) ;
}
int F_535 ( struct V_34 * V_35 )
{
if ( F_191 ( & V_35 -> V_681 ) )
return 0 ;
F_536 ( & V_35 -> V_679 -> V_680 ) ;
F_2 () ;
if ( F_191 ( & V_35 -> V_681 ) ) {
F_532 ( V_35 ) ;
return 0 ;
}
return 1 ;
}
