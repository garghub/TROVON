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
F_144 ( V_190 ) ;
}
if ( V_187 )
* V_187 = V_188 ;
if ( V_29 == - V_200 )
V_29 = 0 ;
return V_29 ;
}
int F_145 ( struct V_109 * V_110 ,
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
V_29 = F_146 ( V_37 , V_110 , V_27 ,
V_36 ,
V_17 , V_146 , ( int ) V_133 ,
V_203 , NULL , V_201 ) ;
} else {
V_29 = F_147 ( V_37 , V_110 , V_27 ,
V_36 ,
V_17 , V_146 , V_133 , V_33 ,
V_203 , NULL , V_201 ) ;
}
return V_29 ;
}
static int F_148 ( struct V_109 * V_110 ,
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
if ( ! F_149 ( V_146 ) || ! V_35 -> V_37 -> V_206 )
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
V_29 = F_150 ( V_110 , V_37 , V_146 ,
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
V_29 = F_150 ( V_110 , V_37 , V_146 ,
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
F_151 ( V_110 , V_35 , V_29 ) ;
V_72:
F_50 ( V_64 ) ;
return V_29 ;
}
static int F_152 ( struct V_109 * V_110 ,
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
V_151 = F_153 ( V_128 ) ;
F_154 ( V_128 , V_151 , V_128 -> V_214 ) ;
if ( V_128 -> type == V_154 )
V_17 = V_151 -> V_17 ;
V_213 = V_151 -> V_35 ;
if ( V_128 -> V_214 == V_203 && V_210 ) {
if ( V_129 )
V_7 |= V_129 -> V_131 ;
V_29 = F_155 ( V_110 , V_35 ,
V_17 , V_213 , V_7 ,
V_151 -> V_22 , V_151 -> V_33 ,
& V_212 , V_128 -> V_132 ) ;
} else if ( V_128 -> V_214 == V_203 ) {
V_29 = F_148 ( V_110 , V_35 , V_128 -> V_27 ,
V_128 -> V_36 , V_17 ,
V_213 , V_151 -> V_22 ,
V_151 -> V_33 , V_128 -> V_132 ,
V_128 -> V_201 , V_129 ) ;
} else if ( V_128 -> V_214 == V_215 ) {
V_29 = F_156 ( V_110 , V_35 , V_128 -> V_27 ,
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
F_157 ( V_66 , V_139 , & V_129 -> V_21 ) ;
}
}
static int F_158 ( struct V_109 * V_110 ,
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
static int F_159 ( struct V_109 * V_110 ,
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
V_151 = F_160 ( V_128 ) ;
F_161 ( V_128 , V_151 , V_128 -> V_214 ) ;
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
V_29 = F_162 ( V_110 , V_35 ,
V_17 , V_213 ,
V_129 -> V_131 ,
& V_129 -> V_21 ,
V_151 -> V_167 , & V_212 ,
V_128 -> V_201 ) ;
} else if ( V_128 -> V_214 == V_203 ) {
V_29 = F_148 ( V_110 , V_35 , V_128 -> V_27 ,
V_128 -> V_36 , V_17 , V_213 ,
V_151 -> V_167 , 0 , 1 , V_128 -> V_201 ,
V_129 ) ;
} else if ( V_128 -> V_214 == V_215 ) {
V_29 = F_156 ( V_110 , V_35 , V_128 -> V_27 ,
V_128 -> V_36 , V_17 , V_213 ,
V_151 -> V_167 , 0 , 1 , V_129 ,
V_128 -> V_201 ) ;
} else {
F_83 () ;
}
return V_29 ;
}
static int F_163 ( struct V_109 * V_110 ,
struct V_34 * V_35 ,
struct V_209 * V_128 ,
struct V_180 * V_129 ,
int V_210 )
{
int V_29 = 0 ;
if ( V_110 -> V_217 ) {
if ( V_210 )
F_164 ( V_35 , V_128 -> V_27 ,
V_128 -> V_36 , 1 ) ;
return 0 ;
}
if ( F_165 ( V_128 ) ) {
struct V_113 * V_104 ;
F_30 ( V_129 ) ;
V_104 = F_166 ( V_128 ) ;
F_167 ( V_128 , V_104 , V_128 -> V_214 ) ;
if ( V_210 ) {
F_164 ( V_35 , V_128 -> V_27 ,
V_128 -> V_36 , 1 ) ;
if ( V_104 -> V_184 ) {
V_29 = F_168 ( V_110 , V_35 ,
V_128 -> V_27 ,
V_128 -> V_36 ) ;
}
}
return V_29 ;
}
if ( V_128 -> type == V_166 ||
V_128 -> type == V_165 )
V_29 = F_159 ( V_110 , V_35 , V_128 , V_129 ,
V_210 ) ;
else if ( V_128 -> type == V_155 ||
V_128 -> type == V_154 )
V_29 = F_152 ( V_110 , V_35 , V_128 , V_129 ,
V_210 ) ;
else
F_83 () ;
return V_29 ;
}
T_1 int F_169 ( struct V_109 * V_110 ,
struct V_34 * V_35 ,
unsigned long V_44 )
{
struct V_114 * V_115 ;
struct V_209 * V_151 ;
struct V_113 * V_219 = NULL ;
struct V_180 * V_129 ;
struct V_12 * V_37 = V_35 -> V_37 ;
T_6 V_32 = F_170 () ;
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
V_219 = F_171 ( V_110 ) ;
if ( ! V_219 ) {
F_13 ( & V_115 -> V_52 ) ;
break;
}
V_29 = F_172 ( V_110 , V_219 ) ;
F_13 ( & V_115 -> V_52 ) ;
if ( V_29 == - V_178 ) {
V_219 = NULL ;
V_8 ++ ;
continue;
}
}
F_11 ( & V_219 -> V_52 ) ;
F_173 ( V_110 , V_37 , V_115 ,
V_219 ) ;
V_151 = F_174 ( V_219 ) ;
if ( V_151 && V_151 -> V_222 &&
F_175 ( V_37 , V_115 , V_151 -> V_222 ) ) {
F_13 ( & V_219 -> V_52 ) ;
F_176 ( V_219 ) ;
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
F_177 ( V_129 ) ;
V_129 = NULL ;
}
if ( V_129 ) {
F_13 ( & V_219 -> V_52 ) ;
V_29 = F_158 ( V_110 , V_35 ,
V_151 , V_129 ) ;
F_177 ( V_129 ) ;
if ( V_29 ) {
if ( V_221 )
V_219 -> V_221 = 1 ;
V_219 -> V_223 = 0 ;
F_178 ( V_37 , L_1 , V_29 ) ;
F_176 ( V_219 ) ;
return V_29 ;
}
continue;
}
F_13 ( & V_219 -> V_52 ) ;
F_11 ( & V_115 -> V_52 ) ;
F_11 ( & V_219 -> V_52 ) ;
if ( F_179 ( & V_219 -> V_213 ) ||
V_219 -> V_129 ) {
F_13 ( & V_219 -> V_52 ) ;
F_13 ( & V_115 -> V_52 ) ;
continue;
}
V_151 -> V_225 = 0 ;
V_115 -> V_226 -- ;
F_180 ( & V_219 -> V_227 ,
& V_115 -> V_228 ) ;
F_13 ( & V_115 -> V_52 ) ;
} else {
V_220 ++ ;
V_151 -> V_225 = 0 ;
F_180 ( & V_151 -> V_15 , & V_219 -> V_213 ) ;
}
F_181 ( & V_115 -> V_229 ) ;
if ( ! F_165 ( V_151 ) ) {
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
V_29 = F_163 ( V_110 , V_35 , V_151 , V_129 ,
V_221 ) ;
F_177 ( V_129 ) ;
if ( V_29 ) {
V_219 -> V_223 = 0 ;
F_176 ( V_219 ) ;
F_86 ( V_151 ) ;
F_178 ( V_37 , L_2 , V_29 ) ;
return V_29 ;
}
if ( F_165 ( V_151 ) ) {
F_176 ( V_219 ) ;
V_219 = NULL ;
}
F_86 ( V_151 ) ;
V_8 ++ ;
F_47 () ;
}
if ( V_220 > 0 ) {
T_2 V_231 = F_182 ( F_183 ( F_170 () , V_32 ) ) ;
T_2 V_232 ;
F_11 ( & V_115 -> V_52 ) ;
V_232 = V_37 -> V_233 * 3 + V_231 ;
V_232 = F_184 ( V_232 , 4 ) ;
V_37 -> V_233 = V_232 ;
F_13 ( & V_115 -> V_52 ) ;
}
return 0 ;
}
static T_2 F_185 ( struct V_234 * V_35 )
{
struct V_15 * V_30 = V_35 -> V_15 ;
struct V_209 * V_235 ;
int V_236 = 1 ;
T_2 V_237 ;
T_2 V_238 = 0 , V_69 = 0 ;
V_30 = F_179 ( V_35 ) ;
if ( V_30 ) {
V_235 = F_12 ( V_30 , struct V_209 , V_15 ) ;
V_238 = V_235 -> V_27 ;
}
V_30 = F_186 ( V_35 ) ;
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
static inline T_2 F_187 ( struct V_34 * V_35 , T_2 V_239 )
{
T_2 V_36 ;
V_36 = V_239 * ( sizeof( struct V_116 ) +
sizeof( struct V_163 ) ) ;
if ( ! F_76 ( V_35 -> V_37 , V_121 ) )
V_36 += V_239 * sizeof( struct V_138 ) ;
return F_184 ( V_36 , F_188 ( V_35 ) ) ;
}
int F_189 ( struct V_109 * V_110 ,
struct V_34 * V_35 )
{
struct V_240 * V_241 ;
T_2 V_226 = V_110 -> V_127 -> V_115 . V_224 ;
T_2 V_36 ;
int V_29 = 0 ;
V_36 = F_190 ( V_35 , 1 ) ;
V_226 = F_187 ( V_35 , V_226 ) ;
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
int F_191 ( struct V_109 * V_110 ,
struct V_34 * V_35 )
{
struct V_12 * V_37 = V_35 -> V_37 ;
T_2 V_229 =
F_192 ( & V_110 -> V_127 -> V_115 . V_229 ) ;
T_2 V_243 ;
T_2 V_244 ;
F_2 () ;
V_243 = V_37 -> V_233 ;
V_244 = V_229 * V_243 ;
if ( V_229 * V_243 >= V_245 )
return 1 ;
if ( V_244 >= V_245 / 2 )
return 2 ;
return F_189 ( V_110 , V_35 ) ;
}
static void F_193 ( struct V_60 * V_61 )
{
struct V_246 * V_247 ;
struct V_109 * V_110 ;
int V_29 ;
V_247 = F_32 ( V_61 , struct V_246 , V_61 ) ;
V_110 = F_194 ( V_247 -> V_35 ) ;
if ( F_195 ( V_110 ) ) {
V_247 -> error = F_196 ( V_110 ) ;
goto V_248;
}
V_110 -> V_249 = true ;
V_29 = F_197 ( V_110 , V_247 -> V_35 , V_247 -> V_8 ) ;
if ( V_29 )
V_247 -> error = V_29 ;
V_29 = F_198 ( V_110 , V_247 -> V_35 ) ;
if ( V_29 && ! V_247 -> error )
V_247 -> error = V_29 ;
V_248:
if ( V_247 -> V_249 )
F_199 ( & V_247 -> V_88 ) ;
else
F_9 ( V_247 ) ;
}
int F_200 ( struct V_34 * V_35 ,
unsigned long V_8 , int V_88 )
{
struct V_246 * V_247 ;
int V_29 ;
V_247 = F_201 ( sizeof( * V_247 ) , V_40 ) ;
if ( ! V_247 )
return - V_71 ;
V_247 -> V_35 = V_35 -> V_37 -> V_86 ;
V_247 -> V_8 = V_8 ;
V_247 -> error = 0 ;
if ( V_88 )
V_247 -> V_249 = 1 ;
else
V_247 -> V_249 = 0 ;
F_202 ( & V_247 -> V_88 ) ;
F_58 ( & V_247 -> V_61 , V_250 ,
F_193 , NULL , NULL ) ;
F_66 ( V_35 -> V_37 -> V_251 , & V_247 -> V_61 ) ;
if ( V_88 ) {
F_203 ( & V_247 -> V_88 ) ;
V_29 = V_247 -> error ;
F_9 ( V_247 ) ;
return V_29 ;
}
return 0 ;
}
int F_197 ( struct V_109 * V_110 ,
struct V_34 * V_35 , unsigned long V_8 )
{
struct V_15 * V_128 ;
struct V_114 * V_115 ;
struct V_113 * V_104 ;
int V_29 ;
int V_252 = V_8 == ( unsigned long ) - 1 ;
if ( V_110 -> V_217 )
return 0 ;
if ( V_35 == V_35 -> V_37 -> V_62 )
V_35 = V_35 -> V_37 -> V_86 ;
V_115 = & V_110 -> V_127 -> V_115 ;
if ( V_8 == 0 )
V_8 = F_192 ( & V_115 -> V_229 ) * 2 ;
V_77:
#ifdef F_204
V_115 -> V_253 = F_185 ( & V_115 -> V_35 ) ;
#endif
V_29 = F_169 ( V_110 , V_35 , V_8 ) ;
if ( V_29 < 0 ) {
F_151 ( V_110 , V_35 , V_29 ) ;
return V_29 ;
}
if ( V_252 ) {
if ( ! F_205 ( & V_110 -> V_254 ) )
F_206 ( V_110 , V_35 ) ;
F_11 ( & V_115 -> V_52 ) ;
V_128 = F_179 ( & V_115 -> V_228 ) ;
if ( ! V_128 ) {
F_13 ( & V_115 -> V_52 ) ;
goto V_72;
}
V_8 = ( unsigned long ) - 1 ;
while ( V_128 ) {
V_104 = F_12 ( V_128 , struct V_113 ,
V_227 ) ;
if ( F_165 ( & V_104 -> V_128 ) ) {
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
V_128 = F_207 ( V_128 ) ;
}
F_13 ( & V_115 -> V_52 ) ;
F_47 () ;
goto V_77;
}
V_72:
V_29 = F_208 ( V_110 , V_35 -> V_37 ) ;
if ( V_29 )
return V_29 ;
F_209 ( V_110 ) ;
return 0 ;
}
int F_210 ( struct V_109 * V_110 ,
struct V_34 * V_35 ,
T_2 V_27 , T_2 V_36 , T_2 V_7 ,
int V_167 , int V_184 )
{
struct V_180 * V_129 ;
int V_29 ;
V_129 = F_211 () ;
if ( ! V_129 )
return - V_71 ;
V_129 -> V_131 = V_7 ;
V_129 -> V_130 = 1 ;
V_129 -> V_216 = 0 ;
V_129 -> V_184 = V_184 ? 1 : 0 ;
V_129 -> V_167 = V_167 ;
V_29 = F_212 ( V_35 -> V_37 , V_110 , V_27 ,
V_36 , V_129 ) ;
if ( V_29 )
F_177 ( V_129 ) ;
return V_29 ;
}
static T_1 int F_213 ( struct V_109 * V_110 ,
struct V_34 * V_35 ,
struct V_63 * V_64 ,
T_2 V_22 , T_2 V_33 , T_2 V_27 )
{
struct V_113 * V_104 ;
struct V_209 * V_151 ;
struct V_211 * V_255 ;
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
V_128 = F_179 ( & V_104 -> V_213 ) ;
while ( V_128 ) {
V_151 = F_12 ( V_128 , struct V_209 , V_15 ) ;
V_128 = F_207 ( V_128 ) ;
if ( V_151 -> type != V_155 ) {
V_29 = 1 ;
break;
}
V_255 = F_153 ( V_151 ) ;
if ( V_255 -> V_35 != V_35 -> V_256 . V_22 ||
V_255 -> V_22 != V_22 ||
V_255 -> V_33 != V_33 ) {
V_29 = 1 ;
break;
}
}
F_13 ( & V_104 -> V_52 ) ;
F_46 ( & V_104 -> V_78 ) ;
return V_29 ;
}
static T_1 int F_214 ( struct V_109 * V_110 ,
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
if ( F_215 ( V_66 , V_117 ) <=
F_216 ( & V_35 -> V_257 ) )
goto V_72;
V_164 = (struct V_163 * ) ( V_117 + 1 ) ;
if ( F_119 ( V_66 , V_164 ) !=
V_155 )
goto V_72;
V_151 = (struct V_150 * ) ( & V_164 -> V_33 ) ;
if ( F_79 ( V_66 , V_117 ) !=
F_113 ( V_66 , V_151 ) ||
F_100 ( V_66 , V_151 ) !=
V_35 -> V_256 . V_22 ||
F_101 ( V_66 , V_151 ) != V_22 ||
F_102 ( V_66 , V_151 ) != V_33 )
goto V_72;
V_29 = 0 ;
V_72:
return V_29 ;
}
int F_217 ( struct V_109 * V_110 ,
struct V_34 * V_35 ,
T_2 V_22 , T_2 V_33 , T_2 V_27 )
{
struct V_63 * V_64 ;
int V_29 ;
int V_258 ;
V_64 = F_33 () ;
if ( ! V_64 )
return - V_153 ;
do {
V_29 = F_214 ( V_110 , V_35 , V_64 , V_22 ,
V_33 , V_27 ) ;
if ( V_29 && V_29 != - V_153 )
goto V_72;
V_258 = F_213 ( V_110 , V_35 , V_64 , V_22 ,
V_33 , V_27 ) ;
} while ( V_258 == - V_178 );
if ( V_258 && V_258 != - V_153 ) {
V_29 = V_258 ;
goto V_72;
}
if ( V_29 != - V_153 || V_258 != - V_153 )
V_29 = 0 ;
V_72:
F_50 ( V_64 ) ;
if ( V_35 -> V_256 . V_22 == V_259 )
F_8 ( V_29 > 0 ) ;
return V_29 ;
}
static int F_218 ( struct V_109 * V_110 ,
struct V_34 * V_35 ,
struct V_65 * V_260 ,
int V_261 , int V_262 )
{
T_2 V_27 ;
T_2 V_36 ;
T_2 V_17 ;
T_2 V_213 ;
T_3 V_70 ;
struct V_67 V_21 ;
struct V_263 * V_264 ;
int V_43 ;
int V_167 ;
int V_29 = 0 ;
int (* F_219)( struct V_109 * , struct V_34 * ,
T_2 , T_2 , T_2 , T_2 , T_2 , T_2 , int );
if ( F_220 ( V_35 ) )
return 0 ;
V_213 = F_221 ( V_260 ) ;
V_70 = F_38 ( V_260 ) ;
V_167 = F_222 ( V_260 ) ;
if ( ! F_223 ( V_265 , & V_35 -> V_266 ) && V_167 == 0 )
return 0 ;
if ( V_262 )
F_219 = F_145 ;
else
F_219 = V_267 ;
if ( V_261 )
V_17 = V_260 -> V_32 ;
else
V_17 = 0 ;
for ( V_43 = 0 ; V_43 < V_70 ; V_43 ++ ) {
if ( V_167 == 0 ) {
F_40 ( V_260 , & V_21 , V_43 ) ;
if ( V_21 . type != V_268 )
continue;
V_264 = F_78 ( V_260 , V_43 ,
struct V_263 ) ;
if ( F_224 ( V_260 , V_264 ) ==
V_269 )
continue;
V_27 = F_225 ( V_260 , V_264 ) ;
if ( V_27 == 0 )
continue;
V_36 = F_226 ( V_260 , V_264 ) ;
V_21 . V_33 -= F_227 ( V_260 , V_264 ) ;
V_29 = F_219 ( V_110 , V_35 , V_27 , V_36 ,
V_17 , V_213 , V_21 . V_22 ,
V_21 . V_33 , 1 ) ;
if ( V_29 )
goto V_156;
} else {
V_27 = F_228 ( V_260 , V_43 ) ;
V_36 = V_35 -> V_87 ;
V_29 = F_219 ( V_110 , V_35 , V_27 , V_36 ,
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
int F_229 ( struct V_109 * V_110 , struct V_34 * V_35 ,
struct V_65 * V_260 , int V_261 )
{
return F_218 ( V_110 , V_35 , V_260 , V_261 , 1 ) ;
}
int F_230 ( struct V_109 * V_110 , struct V_34 * V_35 ,
struct V_65 * V_260 , int V_261 )
{
return F_218 ( V_110 , V_35 , V_260 , V_261 , 0 ) ;
}
static int F_231 ( struct V_109 * V_110 ,
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
V_139 = F_232 ( V_66 , V_64 -> V_83 [ 0 ] ) ;
F_233 ( V_66 , & V_2 -> V_135 , V_139 , sizeof( V_2 -> V_135 ) ) ;
F_95 ( V_66 ) ;
F_44 ( V_64 ) ;
V_156:
if ( V_29 )
F_151 ( V_110 , V_35 , V_29 ) ;
return V_29 ;
}
static struct V_1 *
F_234 ( struct V_34 * V_35 ,
struct V_1 * V_2 )
{
struct V_15 * V_128 ;
F_11 ( & V_35 -> V_37 -> V_18 ) ;
if ( F_235 ( & V_2 -> V_20 ) ) {
const T_2 V_270 = V_2 -> V_21 . V_22 + V_2 -> V_21 . V_33 ;
F_13 ( & V_35 -> V_37 -> V_18 ) ;
F_6 ( V_2 ) ;
V_2 = F_67 ( V_35 -> V_37 ,
V_270 ) ;
return V_2 ;
}
V_128 = F_207 ( & V_2 -> V_20 ) ;
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
static int F_236 ( struct V_1 * V_14 ,
struct V_109 * V_110 ,
struct V_63 * V_64 )
{
struct V_34 * V_35 = V_14 -> V_37 -> V_86 ;
struct V_271 * V_271 = NULL ;
T_2 V_272 = 0 ;
int V_273 = V_274 ;
int V_275 = 0 ;
int V_276 = 0 ;
int V_29 = 0 ;
if ( V_14 -> V_21 . V_33 < ( 100 * 1024 * 1024 ) ) {
F_11 ( & V_14 -> V_52 ) ;
V_14 -> V_277 = V_278 ;
F_13 ( & V_14 -> V_52 ) ;
return 0 ;
}
if ( V_110 -> V_217 )
return 0 ;
V_77:
V_271 = F_237 ( V_35 , V_14 , V_64 ) ;
if ( F_195 ( V_271 ) && F_196 ( V_271 ) != - V_153 ) {
V_29 = F_196 ( V_271 ) ;
F_44 ( V_64 ) ;
goto V_72;
}
if ( F_195 ( V_271 ) ) {
F_30 ( V_276 ) ;
V_276 ++ ;
if ( V_14 -> V_279 )
goto V_123;
V_29 = F_238 ( V_35 , V_110 , V_14 , V_64 ) ;
if ( V_29 )
goto V_123;
goto V_77;
}
if ( V_14 -> V_280 == V_110 -> V_281 &&
F_239 ( V_271 ) ) {
V_273 = V_282 ;
goto V_283;
}
F_240 ( V_271 ) -> V_284 = 0 ;
V_29 = F_241 ( V_110 , V_35 , V_271 ) ;
if ( V_29 ) {
F_151 ( V_110 , V_35 , V_29 ) ;
goto V_283;
}
F_8 ( V_29 ) ;
if ( F_239 ( V_271 ) > 0 ) {
V_29 = F_242 ( V_35 ,
& V_35 -> V_37 -> V_242 ) ;
if ( V_29 )
goto V_283;
V_29 = F_243 ( V_35 , V_110 , V_271 ) ;
if ( V_29 )
goto V_283;
}
F_11 ( & V_14 -> V_52 ) ;
if ( V_14 -> V_3 != V_4 ||
! F_244 ( V_35 , V_285 ) ||
V_14 -> V_286 ) {
V_273 = V_278 ;
F_13 ( & V_14 -> V_52 ) ;
goto V_283;
}
F_13 ( & V_14 -> V_52 ) ;
V_275 = ( int ) F_184 ( V_14 -> V_21 . V_33 , 256 * 1024 * 1024 ) ;
if ( ! V_275 )
V_275 = 1 ;
V_275 *= 16 ;
V_275 *= V_287 ;
V_29 = F_245 ( V_271 , V_275 ) ;
if ( V_29 )
goto V_283;
V_29 = F_246 ( V_271 , V_110 , 0 , 0 , V_275 ,
V_275 , V_275 ,
& V_272 ) ;
if ( ! V_29 )
V_273 = V_282 ;
F_247 ( V_271 , V_275 ) ;
V_283:
F_248 ( V_271 ) ;
V_123:
F_44 ( V_64 ) ;
V_72:
F_11 ( & V_14 -> V_52 ) ;
if ( ! V_29 && V_273 == V_282 )
V_14 -> V_280 = V_110 -> V_281 ;
V_14 -> V_277 = V_273 ;
F_13 ( & V_14 -> V_52 ) ;
return V_29 ;
}
int F_249 ( struct V_109 * V_110 ,
struct V_34 * V_35 )
{
struct V_1 * V_2 , * V_288 ;
struct V_289 * V_290 = V_110 -> V_127 ;
struct V_63 * V_64 ;
if ( F_205 ( & V_290 -> V_291 ) ||
! F_244 ( V_35 , V_285 ) )
return 0 ;
V_64 = F_33 () ;
if ( ! V_64 )
return - V_71 ;
F_250 (cache, tmp, &cur_trans->dirty_bgs,
dirty_list) {
if ( V_2 -> V_277 == V_292 )
F_236 ( V_2 , V_110 , V_64 ) ;
}
F_50 ( V_64 ) ;
return 0 ;
}
int F_251 ( struct V_109 * V_110 ,
struct V_34 * V_35 )
{
struct V_1 * V_2 ;
struct V_289 * V_290 = V_110 -> V_127 ;
int V_29 = 0 ;
struct V_63 * V_64 ;
if ( F_205 ( & V_290 -> V_291 ) )
return 0 ;
V_64 = F_33 () ;
if ( ! V_64 )
return - V_71 ;
while ( ! F_205 ( & V_290 -> V_291 ) ) {
V_2 = F_252 ( & V_290 -> V_291 ,
struct V_1 ,
V_293 ) ;
F_253 ( & V_2 -> V_293 ) ;
if ( V_2 -> V_277 == V_292 )
F_236 ( V_2 , V_110 , V_64 ) ;
if ( ! V_29 )
V_29 = F_197 ( V_110 , V_35 ,
( unsigned long ) - 1 ) ;
if ( ! V_29 && V_2 -> V_277 == V_282 )
F_254 ( V_35 , V_110 , V_2 , V_64 ) ;
if ( ! V_29 )
V_29 = F_231 ( V_110 , V_35 , V_64 , V_2 ) ;
F_6 ( V_2 ) ;
}
F_50 ( V_64 ) ;
return V_29 ;
}
int F_255 ( struct V_34 * V_35 , T_2 V_27 )
{
struct V_1 * V_14 ;
int V_294 = 0 ;
V_14 = F_68 ( V_35 -> V_37 , V_27 ) ;
if ( ! V_14 || V_14 -> V_279 )
V_294 = 1 ;
if ( V_14 )
F_6 ( V_14 ) ;
return V_294 ;
}
static const char * F_256 ( T_2 V_7 )
{
switch ( V_7 ) {
case V_295 | V_296 :
return L_3 ;
case V_295 :
return L_4 ;
case V_296 :
return L_5 ;
case V_297 :
return L_6 ;
default:
F_8 ( 1 ) ;
return L_7 ;
} ;
}
static int F_257 ( struct V_12 * V_13 , T_2 V_7 ,
T_2 V_298 , T_2 V_299 ,
struct V_102 * * V_105 )
{
struct V_102 * V_106 ;
int V_43 ;
int V_300 ;
int V_29 ;
if ( V_7 & ( V_301 | V_302 |
V_303 ) )
V_300 = 2 ;
else
V_300 = 1 ;
V_106 = F_69 ( V_13 , V_7 ) ;
if ( V_106 ) {
F_11 ( & V_106 -> V_52 ) ;
V_106 -> V_298 += V_298 ;
V_106 -> V_304 += V_298 * V_300 ;
V_106 -> V_299 += V_299 ;
V_106 -> V_305 += V_299 * V_300 ;
V_106 -> V_108 = 0 ;
F_13 ( & V_106 -> V_52 ) ;
* V_105 = V_106 ;
return 0 ;
}
V_106 = F_53 ( sizeof( * V_106 ) , V_40 ) ;
if ( ! V_106 )
return - V_71 ;
V_29 = F_258 ( & V_106 -> V_306 , 0 , V_307 ) ;
if ( V_29 ) {
F_9 ( V_106 ) ;
return V_29 ;
}
for ( V_43 = 0 ; V_43 < V_308 ; V_43 ++ )
F_54 ( & V_106 -> V_309 [ V_43 ] ) ;
F_259 ( & V_106 -> V_310 ) ;
F_260 ( & V_106 -> V_52 ) ;
V_106 -> V_7 = V_7 & V_107 ;
V_106 -> V_298 = V_298 ;
V_106 -> V_304 = V_298 * V_300 ;
V_106 -> V_299 = V_299 ;
V_106 -> V_305 = V_299 * V_300 ;
V_106 -> V_311 = 0 ;
V_106 -> V_312 = 0 ;
V_106 -> V_313 = 0 ;
V_106 -> V_314 = 0 ;
V_106 -> V_108 = 0 ;
V_106 -> V_315 = V_316 ;
V_106 -> V_317 = 0 ;
V_106 -> V_318 = 0 ;
F_56 ( & V_106 -> V_88 ) ;
F_54 ( & V_106 -> V_319 ) ;
V_29 = F_261 ( & V_106 -> V_320 , & V_321 ,
V_13 -> V_322 , L_8 ,
F_256 ( V_106 -> V_7 ) ) ;
if ( V_29 ) {
F_9 ( V_106 ) ;
return V_29 ;
}
* V_105 = V_106 ;
F_262 ( & V_106 -> V_90 , & V_13 -> V_105 ) ;
if ( V_7 & V_296 )
V_13 -> V_323 = V_106 ;
return V_29 ;
}
static void F_263 ( struct V_12 * V_37 , T_2 V_7 )
{
T_2 V_324 = F_264 ( V_7 ) &
V_325 ;
F_265 ( & V_37 -> V_326 ) ;
if ( V_7 & V_296 )
V_37 -> V_327 |= V_324 ;
if ( V_7 & V_295 )
V_37 -> V_328 |= V_324 ;
if ( V_7 & V_297 )
V_37 -> V_329 |= V_324 ;
F_266 ( & V_37 -> V_326 ) ;
}
static T_2 F_267 ( struct V_12 * V_37 , T_2 V_7 )
{
struct V_330 * V_331 = V_37 -> V_332 ;
T_2 V_333 = 0 ;
if ( ! V_331 )
return 0 ;
if ( V_7 & V_296 &&
V_331 -> V_334 . V_7 & V_335 ) {
V_333 = V_296 | V_331 -> V_334 . V_333 ;
} else if ( V_7 & V_297 &&
V_331 -> V_336 . V_7 & V_335 ) {
V_333 = V_297 | V_331 -> V_336 . V_333 ;
} else if ( V_7 & V_295 &&
V_331 -> V_337 . V_7 & V_335 ) {
V_333 = V_295 | V_331 -> V_337 . V_333 ;
}
return V_333 ;
}
static T_2 F_268 ( struct V_34 * V_35 , T_2 V_7 )
{
T_2 V_338 = V_35 -> V_37 -> V_339 -> V_340 ;
T_2 V_333 ;
T_2 V_288 ;
F_11 ( & V_35 -> V_37 -> V_341 ) ;
V_333 = F_267 ( V_35 -> V_37 , V_7 ) ;
if ( V_333 ) {
if ( ( V_7 & V_333 ) & V_325 ) {
F_13 ( & V_35 -> V_37 -> V_341 ) ;
return F_269 ( V_333 ) ;
}
}
F_13 ( & V_35 -> V_37 -> V_341 ) ;
if ( V_338 == 1 )
V_7 &= ~ ( V_302 | V_342 |
V_343 ) ;
if ( V_338 < 3 )
V_7 &= ~ V_344 ;
if ( V_338 < 4 )
V_7 &= ~ V_303 ;
V_288 = V_7 & ( V_301 | V_342 |
V_302 | V_343 |
V_344 | V_303 ) ;
V_7 &= ~ V_288 ;
if ( V_288 & V_344 )
V_288 = V_344 ;
else if ( V_288 & V_343 )
V_288 = V_343 ;
else if ( V_288 & V_303 )
V_288 = V_303 ;
else if ( V_288 & V_302 )
V_288 = V_302 ;
else if ( V_288 & V_342 )
V_288 = V_342 ;
return F_269 ( V_7 | V_288 ) ;
}
static T_2 F_270 ( struct V_34 * V_35 , T_2 V_345 )
{
unsigned V_222 ;
T_2 V_7 ;
do {
V_7 = V_345 ;
V_222 = F_271 ( & V_35 -> V_37 -> V_326 ) ;
if ( V_7 & V_296 )
V_7 |= V_35 -> V_37 -> V_327 ;
else if ( V_7 & V_297 )
V_7 |= V_35 -> V_37 -> V_329 ;
else if ( V_7 & V_295 )
V_7 |= V_35 -> V_37 -> V_328 ;
} while ( F_272 ( & V_35 -> V_37 -> V_326 , V_222 ) );
return F_268 ( V_35 , V_7 ) ;
}
T_2 F_273 ( struct V_34 * V_35 , int V_334 )
{
T_2 V_7 ;
T_2 V_29 ;
if ( V_334 )
V_7 = V_296 ;
else if ( V_35 == V_35 -> V_37 -> V_346 )
V_7 = V_297 ;
else
V_7 = V_295 ;
V_29 = F_270 ( V_35 , V_7 ) ;
return V_29 ;
}
int F_245 ( struct V_271 * V_271 , T_2 V_347 )
{
struct V_102 * V_323 ;
struct V_34 * V_35 = F_240 ( V_271 ) -> V_35 ;
struct V_12 * V_37 = V_35 -> V_37 ;
T_2 V_348 ;
int V_29 = 0 , V_349 = 0 , V_350 = 1 ;
V_347 = F_274 ( V_347 , V_35 -> V_351 ) ;
if ( F_275 ( V_271 ) ) {
V_349 = 1 ;
ASSERT ( V_352 -> V_353 ) ;
}
V_323 = V_37 -> V_323 ;
if ( ! V_323 )
goto V_354;
V_77:
F_11 ( & V_323 -> V_52 ) ;
V_348 = V_323 -> V_299 + V_323 -> V_312 +
V_323 -> V_311 + V_323 -> V_313 +
V_323 -> V_314 ;
if ( V_348 + V_347 > V_323 -> V_298 ) {
struct V_109 * V_110 ;
if ( ! V_323 -> V_108 && V_350 ) {
T_2 V_355 ;
V_323 -> V_315 = V_356 ;
F_13 ( & V_323 -> V_52 ) ;
V_354:
V_355 = F_273 ( V_35 , 1 ) ;
V_110 = F_194 ( V_35 ) ;
if ( F_195 ( V_110 ) )
return F_196 ( V_110 ) ;
V_29 = F_276 ( V_110 , V_35 -> V_37 -> V_62 ,
V_355 ,
V_316 ) ;
F_198 ( V_110 , V_35 ) ;
if ( V_29 < 0 ) {
if ( V_29 != - V_357 )
return V_29 ;
else
goto V_358;
}
if ( ! V_323 )
V_323 = V_37 -> V_323 ;
goto V_77;
}
if ( F_277 ( & V_323 -> V_306 ,
V_347 ) < 0 )
V_349 = 1 ;
F_13 ( & V_323 -> V_52 ) ;
V_358:
if ( ! V_349 &&
! F_192 ( & V_35 -> V_37 -> V_359 ) ) {
V_349 = 1 ;
V_110 = F_194 ( V_35 ) ;
if ( F_195 ( V_110 ) )
return F_196 ( V_110 ) ;
V_29 = F_278 ( V_110 , V_35 ) ;
if ( V_29 )
return V_29 ;
goto V_77;
}
F_279 ( V_35 -> V_37 ,
L_9 ,
V_323 -> V_7 , V_347 , 1 ) ;
return - V_357 ;
}
V_323 -> V_314 += V_347 ;
F_279 ( V_35 -> V_37 , L_10 ,
V_323 -> V_7 , V_347 , 1 ) ;
F_13 ( & V_323 -> V_52 ) ;
return 0 ;
}
void F_247 ( struct V_271 * V_271 , T_2 V_347 )
{
struct V_34 * V_35 = F_240 ( V_271 ) -> V_35 ;
struct V_102 * V_323 ;
V_347 = F_274 ( V_347 , V_35 -> V_351 ) ;
V_323 = V_35 -> V_37 -> V_323 ;
F_11 ( & V_323 -> V_52 ) ;
F_8 ( V_323 -> V_314 < V_347 ) ;
V_323 -> V_314 -= V_347 ;
F_279 ( V_35 -> V_37 , L_10 ,
V_323 -> V_7 , V_347 , 0 ) ;
F_13 ( & V_323 -> V_52 ) ;
}
static void F_280 ( struct V_12 * V_13 )
{
struct V_103 * V_104 = & V_13 -> V_105 ;
struct V_102 * V_106 ;
F_70 () ;
F_71 (found, head, list) {
if ( V_106 -> V_7 & V_295 )
V_106 -> V_315 = V_356 ;
}
F_72 () ;
}
static inline T_2 F_281 ( struct V_240 * V_360 )
{
return ( V_360 -> V_56 << 1 ) ;
}
static int F_282 ( struct V_34 * V_35 ,
struct V_102 * V_361 , int V_362 )
{
struct V_240 * V_241 = & V_35 -> V_37 -> V_242 ;
T_2 V_36 = V_361 -> V_298 - V_361 -> V_313 ;
T_2 V_363 = V_361 -> V_299 + V_361 -> V_312 ;
T_2 V_364 ;
if ( V_362 == V_356 )
return 1 ;
if ( V_361 -> V_7 & V_295 )
V_363 += F_281 ( V_241 ) ;
if ( V_362 == V_365 ) {
V_364 = F_283 ( V_35 -> V_37 -> V_366 ) ;
V_364 = F_34 ( T_2 , 64 * 1024 * 1024 ,
F_284 ( V_364 , 1 ) ) ;
if ( V_36 - V_363 < V_364 )
return 1 ;
}
if ( V_363 + 2 * 1024 * 1024 < F_285 ( V_36 , 8 ) )
return 0 ;
return 1 ;
}
static T_2 F_286 ( struct V_34 * V_35 , T_2 type )
{
T_2 V_367 ;
if ( type & ( V_303 |
V_342 |
V_343 |
V_344 ) )
V_367 = V_35 -> V_37 -> V_339 -> V_340 ;
else if ( type & V_302 )
V_367 = 2 ;
else
V_367 = 1 ;
return F_190 ( V_35 , V_367 + 1 ) ;
}
static void F_287 ( struct V_109 * V_110 ,
struct V_34 * V_35 , T_2 type )
{
struct V_102 * V_13 ;
T_2 V_368 ;
T_2 V_364 ;
V_13 = F_69 ( V_35 -> V_37 , V_297 ) ;
F_11 ( & V_13 -> V_52 ) ;
V_368 = V_13 -> V_298 - V_13 -> V_299 - V_13 -> V_311 -
V_13 -> V_312 - V_13 -> V_313 ;
F_13 ( & V_13 -> V_52 ) ;
V_364 = F_286 ( V_35 , type ) ;
if ( V_368 < V_364 && F_244 ( V_35 , V_369 ) ) {
F_288 ( V_35 -> V_37 , L_11 ,
V_368 , V_364 , type ) ;
F_289 ( V_13 , 0 , 0 ) ;
}
if ( V_368 < V_364 ) {
T_2 V_7 ;
V_7 = F_273 ( V_35 -> V_37 -> V_346 , 0 ) ;
F_290 ( V_110 , V_35 , V_7 ) ;
}
}
static int F_276 ( struct V_109 * V_110 ,
struct V_34 * V_62 , T_2 V_7 , int V_362 )
{
struct V_102 * V_105 ;
struct V_12 * V_37 = V_62 -> V_37 ;
int V_370 = 0 ;
int V_29 = 0 ;
if ( V_110 -> V_371 )
return - V_357 ;
V_105 = F_69 ( V_62 -> V_37 , V_7 ) ;
if ( ! V_105 ) {
V_29 = F_257 ( V_62 -> V_37 , V_7 ,
0 , 0 , & V_105 ) ;
F_30 ( V_29 ) ;
}
F_30 ( ! V_105 ) ;
V_77:
F_11 ( & V_105 -> V_52 ) ;
if ( V_362 < V_105 -> V_315 )
V_362 = V_105 -> V_315 ;
if ( V_105 -> V_108 ) {
if ( F_282 ( V_62 , V_105 , V_362 ) )
V_29 = - V_357 ;
else
V_29 = 0 ;
F_13 ( & V_105 -> V_52 ) ;
return V_29 ;
}
if ( ! F_282 ( V_62 , V_105 , V_362 ) ) {
F_13 ( & V_105 -> V_52 ) ;
return 0 ;
} else if ( V_105 -> V_317 ) {
V_370 = 1 ;
} else {
V_105 -> V_317 = 1 ;
}
F_13 ( & V_105 -> V_52 ) ;
F_35 ( & V_37 -> V_372 ) ;
if ( V_370 ) {
F_46 ( & V_37 -> V_372 ) ;
V_370 = 0 ;
goto V_77;
}
V_110 -> V_371 = true ;
if ( F_291 ( V_105 ) )
V_7 |= ( V_296 | V_295 ) ;
if ( V_7 & V_296 && V_37 -> V_373 ) {
V_37 -> V_374 ++ ;
if ( ! ( V_37 -> V_374 %
V_37 -> V_373 ) )
F_280 ( V_37 ) ;
}
F_287 ( V_110 , V_62 , V_7 ) ;
V_29 = F_290 ( V_110 , V_62 , V_7 ) ;
V_110 -> V_371 = false ;
F_11 ( & V_105 -> V_52 ) ;
if ( V_29 < 0 && V_29 != - V_357 )
goto V_72;
if ( V_29 )
V_105 -> V_108 = 1 ;
else
V_29 = 1 ;
V_105 -> V_315 = V_316 ;
V_72:
V_105 -> V_317 = 0 ;
F_13 ( & V_105 -> V_52 ) ;
F_46 ( & V_37 -> V_372 ) ;
return V_29 ;
}
static int F_292 ( struct V_34 * V_35 ,
struct V_102 * V_105 , T_2 V_347 ,
enum V_375 V_318 )
{
struct V_240 * V_241 = & V_35 -> V_37 -> V_242 ;
T_2 V_376 = F_273 ( V_35 , 0 ) ;
T_2 V_377 ;
T_2 V_378 ;
T_2 V_348 ;
V_348 = V_105 -> V_299 + V_105 -> V_312 +
V_105 -> V_311 + V_105 -> V_313 ;
F_11 ( & V_241 -> V_52 ) ;
V_377 = F_281 ( V_241 ) ;
F_13 ( & V_241 -> V_52 ) ;
if ( V_348 + V_377 >= V_105 -> V_298 )
return 0 ;
V_348 += V_105 -> V_314 ;
F_11 ( & V_35 -> V_37 -> V_379 ) ;
V_378 = V_35 -> V_37 -> V_380 ;
F_13 ( & V_35 -> V_37 -> V_379 ) ;
if ( V_376 & ( V_301 |
V_302 |
V_303 ) )
V_378 >>= 1 ;
if ( V_318 == V_381 )
V_378 >>= 3 ;
else
V_378 >>= 1 ;
if ( V_348 + V_347 < V_105 -> V_298 + V_378 )
return 1 ;
return 0 ;
}
static void F_293 ( struct V_34 * V_35 ,
unsigned long V_382 , int V_383 )
{
struct V_384 * V_385 = V_35 -> V_37 -> V_385 ;
if ( F_294 ( & V_385 -> V_386 ) ) {
F_295 ( V_385 , V_382 , V_387 ) ;
F_45 ( & V_385 -> V_386 ) ;
} else {
F_296 ( V_35 -> V_37 , 0 , V_383 ) ;
if ( ! V_352 -> V_353 )
F_297 ( V_35 -> V_37 , V_383 ) ;
}
}
static inline int F_298 ( struct V_34 * V_35 , T_2 V_388 )
{
T_2 V_347 ;
int V_44 ;
V_347 = F_190 ( V_35 , 1 ) ;
V_44 = ( int ) F_184 ( V_388 , V_347 ) ;
if ( ! V_44 )
V_44 = 1 ;
return V_44 ;
}
static void F_299 ( struct V_34 * V_35 , T_2 V_388 , T_2 V_389 ,
bool V_390 )
{
struct V_240 * V_391 ;
struct V_102 * V_105 ;
struct V_109 * V_110 ;
T_2 V_286 ;
T_2 V_392 ;
long V_393 ;
unsigned long V_382 ;
int V_394 ;
int V_395 ;
enum V_375 V_318 ;
V_395 = F_298 ( V_35 , V_388 ) ;
V_388 = V_395 * V_396 ;
V_110 = (struct V_109 * ) V_352 -> V_353 ;
V_391 = & V_35 -> V_37 -> V_397 ;
V_105 = V_391 -> V_105 ;
V_286 = F_300 (
& V_35 -> V_37 -> V_286 ) ;
if ( V_286 == 0 ) {
if ( V_110 )
return;
if ( V_390 )
F_297 ( V_35 -> V_37 , V_395 ) ;
return;
}
V_394 = 0 ;
while ( V_286 && V_394 < 3 ) {
V_392 = F_301 ( V_286 , V_388 ) ;
V_382 = V_392 >> V_398 ;
F_293 ( V_35 , V_382 , V_395 ) ;
V_392 = F_192 ( & V_35 -> V_37 -> V_399 ) ;
if ( ! V_392 )
goto V_400;
if ( V_392 <= V_382 )
V_392 = 0 ;
else
V_392 -= V_382 ;
F_302 ( V_35 -> V_37 -> V_401 ,
F_192 ( & V_35 -> V_37 -> V_399 ) <=
( int ) V_392 ) ;
V_400:
if ( ! V_110 )
V_318 = V_381 ;
else
V_318 = V_402 ;
F_11 ( & V_105 -> V_52 ) ;
if ( F_292 ( V_35 , V_105 , V_389 , V_318 ) ) {
F_13 ( & V_105 -> V_52 ) ;
break;
}
F_13 ( & V_105 -> V_52 ) ;
V_394 ++ ;
if ( V_390 && ! V_110 ) {
F_297 ( V_35 -> V_37 , V_395 ) ;
} else {
V_393 = F_303 ( 1 ) ;
if ( V_393 )
break;
}
V_286 = F_300 (
& V_35 -> V_37 -> V_286 ) ;
}
}
static int F_304 ( struct V_34 * V_35 ,
struct V_102 * V_105 ,
T_2 V_347 , int V_362 )
{
struct V_240 * V_403 = & V_35 -> V_37 -> V_404 ;
struct V_109 * V_110 ;
V_110 = (struct V_109 * ) V_352 -> V_353 ;
if ( V_110 )
return - V_178 ;
if ( V_362 )
goto V_405;
if ( F_277 ( & V_105 -> V_306 ,
V_347 ) >= 0 )
goto V_405;
if ( V_105 != V_403 -> V_105 )
return - V_357 ;
F_11 ( & V_403 -> V_52 ) ;
if ( F_277 ( & V_105 -> V_306 ,
V_347 - V_403 -> V_56 ) >= 0 ) {
F_13 ( & V_403 -> V_52 ) ;
return - V_357 ;
}
F_13 ( & V_403 -> V_52 ) ;
V_405:
V_110 = F_194 ( V_35 ) ;
if ( F_195 ( V_110 ) )
return - V_357 ;
return F_278 ( V_110 , V_35 ) ;
}
static int F_305 ( struct V_34 * V_35 ,
struct V_102 * V_105 , T_2 V_36 ,
T_2 V_406 , int V_266 )
{
struct V_109 * V_110 ;
int V_44 ;
int V_29 = 0 ;
switch ( V_266 ) {
case V_407 :
case V_408 :
if ( V_266 == V_407 )
V_44 = F_298 ( V_35 , V_36 ) * 2 ;
else
V_44 = - 1 ;
V_110 = F_194 ( V_35 ) ;
if ( F_195 ( V_110 ) ) {
V_29 = F_196 ( V_110 ) ;
break;
}
V_29 = F_306 ( V_110 , V_35 , V_44 ) ;
F_198 ( V_110 , V_35 ) ;
break;
case V_409 :
case V_410 :
F_299 ( V_35 , V_36 * 2 , V_406 ,
V_266 == V_410 ) ;
break;
case V_411 :
V_110 = F_194 ( V_35 ) ;
if ( F_195 ( V_110 ) ) {
V_29 = F_196 ( V_110 ) ;
break;
}
V_29 = F_276 ( V_110 , V_35 -> V_37 -> V_62 ,
F_273 ( V_35 , 0 ) ,
V_316 ) ;
F_198 ( V_110 , V_35 ) ;
if ( V_29 == - V_357 )
V_29 = 0 ;
break;
case V_412 :
V_29 = F_304 ( V_35 , V_105 , V_406 , 0 ) ;
break;
default:
V_29 = - V_357 ;
break;
}
return V_29 ;
}
static inline T_2
F_307 ( struct V_34 * V_35 ,
struct V_102 * V_105 )
{
T_2 V_348 ;
T_2 V_413 ;
T_2 V_388 ;
V_388 = F_24 ( T_2 , F_308 () * 1024 * 1024 ,
16 * 1024 * 1024 ) ;
F_11 ( & V_105 -> V_52 ) ;
if ( F_292 ( V_35 , V_105 , V_388 ,
V_381 ) ) {
V_388 = 0 ;
goto V_72;
}
V_348 = V_105 -> V_299 + V_105 -> V_312 +
V_105 -> V_311 + V_105 -> V_313 +
V_105 -> V_314 ;
if ( F_292 ( V_35 , V_105 , 1024 * 1024 ,
V_381 ) )
V_413 = F_284 ( V_105 -> V_298 , 95 ) ;
else
V_413 = F_284 ( V_105 -> V_298 , 90 ) ;
if ( V_348 > V_413 )
V_388 = V_348 - V_413 ;
else
V_388 = 0 ;
V_388 = F_301 ( V_388 , V_105 -> V_314 +
V_105 -> V_312 ) ;
V_72:
F_13 ( & V_105 -> V_52 ) ;
return V_388 ;
}
static inline int F_309 ( struct V_102 * V_105 ,
struct V_12 * V_37 , T_2 V_348 )
{
return ( V_348 >= F_284 ( V_105 -> V_298 , 98 ) &&
! F_39 ( V_37 ) &&
! F_223 ( V_414 , & V_37 -> V_415 ) ) ;
}
static int F_310 ( struct V_102 * V_105 ,
struct V_12 * V_37 ,
int V_416 )
{
T_2 V_348 ;
F_11 ( & V_105 -> V_52 ) ;
if ( V_416 > V_412 && V_105 -> V_108 ) {
F_13 ( & V_105 -> V_52 ) ;
return 0 ;
}
V_348 = V_105 -> V_299 + V_105 -> V_312 +
V_105 -> V_311 + V_105 -> V_313 +
V_105 -> V_314 ;
if ( F_309 ( V_105 , V_37 , V_348 ) ) {
F_13 ( & V_105 -> V_52 ) ;
return 1 ;
}
F_13 ( & V_105 -> V_52 ) ;
return 0 ;
}
static void F_311 ( struct V_417 * V_61 )
{
struct V_12 * V_37 ;
struct V_102 * V_105 ;
T_2 V_388 ;
int V_416 ;
V_37 = F_32 ( V_61 , struct V_12 , V_418 ) ;
V_105 = F_69 ( V_37 , V_295 ) ;
V_388 = F_307 ( V_37 -> V_419 ,
V_105 ) ;
if ( ! V_388 )
return;
V_416 = V_407 ;
do {
F_305 ( V_37 -> V_419 , V_105 , V_388 ,
V_388 , V_416 ) ;
V_416 ++ ;
if ( ! F_310 ( V_105 , V_37 ,
V_416 ) )
return;
} while ( V_416 <= V_412 );
if ( F_310 ( V_105 , V_37 , V_416 ) )
F_312 ( V_420 , V_61 ) ;
}
void F_313 ( struct V_417 * V_61 )
{
F_314 ( V_61 , F_311 ) ;
}
static int F_315 ( struct V_34 * V_35 ,
struct V_240 * V_391 ,
T_2 V_406 ,
enum V_375 V_318 )
{
struct V_102 * V_105 = V_391 -> V_105 ;
T_2 V_348 ;
T_2 V_36 = V_406 ;
int V_416 = V_407 ;
int V_29 = 0 ;
bool V_421 = false ;
V_77:
V_29 = 0 ;
F_11 ( & V_105 -> V_52 ) ;
while ( V_318 == V_381 && ! V_421 &&
V_105 -> V_318 ) {
F_13 ( & V_105 -> V_52 ) ;
if ( V_352 -> V_353 )
return - V_178 ;
V_29 = F_316 ( V_105 -> V_88 , ! V_105 -> V_318 ) ;
if ( V_29 )
return - V_422 ;
F_11 ( & V_105 -> V_52 ) ;
}
V_29 = - V_357 ;
V_348 = V_105 -> V_299 + V_105 -> V_312 +
V_105 -> V_311 + V_105 -> V_313 +
V_105 -> V_314 ;
if ( V_348 <= V_105 -> V_298 ) {
if ( V_348 + V_406 <= V_105 -> V_298 ) {
V_105 -> V_314 += V_406 ;
F_279 ( V_35 -> V_37 ,
L_10 , V_105 -> V_7 , V_406 , 1 ) ;
V_29 = 0 ;
} else {
V_36 = V_406 ;
}
} else {
V_36 = V_348 - V_105 -> V_298 +
( V_406 * 2 ) ;
}
if ( V_29 && F_292 ( V_35 , V_105 , V_406 , V_318 ) ) {
V_105 -> V_314 += V_406 ;
F_279 ( V_35 -> V_37 , L_10 ,
V_105 -> V_7 , V_406 ,
1 ) ;
V_29 = 0 ;
}
if ( V_29 && V_318 != V_402 ) {
V_421 = true ;
V_105 -> V_318 = 1 ;
} else if ( ! V_29 && V_105 -> V_7 & V_295 ) {
V_348 += V_406 ;
if ( ! V_35 -> V_37 -> V_423 &&
F_309 ( V_105 , V_35 -> V_37 , V_348 ) &&
! F_317 ( & V_35 -> V_37 -> V_418 ) )
F_312 ( V_420 ,
& V_35 -> V_37 -> V_418 ) ;
}
F_13 ( & V_105 -> V_52 ) ;
if ( ! V_29 || V_318 == V_402 )
goto V_72;
V_29 = F_305 ( V_35 , V_105 , V_36 , V_406 ,
V_416 ) ;
V_416 ++ ;
if ( V_318 == V_424 &&
( V_416 == V_409 ||
V_416 == V_410 ) )
V_416 = V_411 ;
if ( ! V_29 )
goto V_77;
else if ( V_318 == V_424 &&
V_416 < V_412 )
goto V_77;
else if ( V_318 == V_381 &&
V_416 <= V_412 )
goto V_77;
V_72:
if ( V_29 == - V_357 &&
F_318 ( V_35 -> V_425 == V_426 ) ) {
struct V_240 * V_241 =
& V_35 -> V_37 -> V_242 ;
if ( V_391 != V_241 &&
! F_319 ( V_241 , V_406 ) )
V_29 = 0 ;
}
if ( V_29 == - V_357 )
F_279 ( V_35 -> V_37 ,
L_9 ,
V_105 -> V_7 , V_406 , 1 ) ;
if ( V_421 ) {
F_11 ( & V_105 -> V_52 ) ;
V_105 -> V_318 = 0 ;
F_320 ( & V_105 -> V_88 ) ;
F_13 ( & V_105 -> V_52 ) ;
}
return V_29 ;
}
static struct V_240 * F_321 (
const struct V_109 * V_110 ,
const struct V_34 * V_35 )
{
struct V_240 * V_391 = NULL ;
if ( F_223 ( V_265 , & V_35 -> V_266 ) )
V_391 = V_110 -> V_391 ;
if ( V_35 == V_35 -> V_37 -> V_427 && V_110 -> V_428 )
V_391 = V_110 -> V_391 ;
if ( V_35 == V_35 -> V_37 -> V_429 )
V_391 = V_110 -> V_391 ;
if ( ! V_391 )
V_391 = V_35 -> V_391 ;
if ( ! V_391 )
V_391 = & V_35 -> V_37 -> V_430 ;
return V_391 ;
}
static int F_319 ( struct V_240 * V_391 ,
T_2 V_36 )
{
int V_29 = - V_357 ;
F_11 ( & V_391 -> V_52 ) ;
if ( V_391 -> V_10 >= V_36 ) {
V_391 -> V_10 -= V_36 ;
if ( V_391 -> V_10 < V_391 -> V_56 )
V_391 -> V_108 = 0 ;
V_29 = 0 ;
}
F_13 ( & V_391 -> V_52 ) ;
return V_29 ;
}
static void F_322 ( struct V_240 * V_391 ,
T_2 V_36 , int V_431 )
{
F_11 ( & V_391 -> V_52 ) ;
V_391 -> V_10 += V_36 ;
if ( V_431 )
V_391 -> V_56 += V_36 ;
else if ( V_391 -> V_10 >= V_391 -> V_56 )
V_391 -> V_108 = 1 ;
F_13 ( & V_391 -> V_52 ) ;
}
int F_323 ( struct V_12 * V_37 ,
struct V_240 * V_432 , T_2 V_36 ,
int V_433 )
{
struct V_240 * V_241 = & V_37 -> V_242 ;
T_2 V_434 ;
if ( V_241 -> V_105 != V_432 -> V_105 )
return - V_357 ;
F_11 ( & V_241 -> V_52 ) ;
V_434 = F_285 ( V_241 -> V_56 , V_433 ) ;
if ( V_241 -> V_10 < V_434 + V_36 ) {
F_13 ( & V_241 -> V_52 ) ;
return - V_357 ;
}
V_241 -> V_10 -= V_36 ;
if ( V_241 -> V_10 < V_241 -> V_56 )
V_241 -> V_108 = 0 ;
F_13 ( & V_241 -> V_52 ) ;
F_322 ( V_432 , V_36 , 1 ) ;
return 0 ;
}
static void F_324 ( struct V_12 * V_37 ,
struct V_240 * V_391 ,
struct V_240 * V_432 , T_2 V_36 )
{
struct V_102 * V_105 = V_391 -> V_105 ;
F_11 ( & V_391 -> V_52 ) ;
if ( V_36 == ( T_2 ) - 1 )
V_36 = V_391 -> V_56 ;
V_391 -> V_56 -= V_36 ;
if ( V_391 -> V_10 >= V_391 -> V_56 ) {
V_36 = V_391 -> V_10 - V_391 -> V_56 ;
V_391 -> V_10 = V_391 -> V_56 ;
V_391 -> V_108 = 1 ;
} else {
V_36 = 0 ;
}
F_13 ( & V_391 -> V_52 ) ;
if ( V_36 > 0 ) {
if ( V_432 ) {
F_11 ( & V_432 -> V_52 ) ;
if ( ! V_432 -> V_108 ) {
T_2 V_435 ;
V_435 = V_432 -> V_56 - V_432 -> V_10 ;
V_435 = F_301 ( V_36 , V_435 ) ;
V_432 -> V_10 += V_435 ;
if ( V_432 -> V_10 >= V_432 -> V_56 )
V_432 -> V_108 = 1 ;
V_36 -= V_435 ;
}
F_13 ( & V_432 -> V_52 ) ;
}
if ( V_36 ) {
F_11 ( & V_105 -> V_52 ) ;
V_105 -> V_314 -= V_36 ;
F_279 ( V_37 , L_10 ,
V_105 -> V_7 , V_36 , 0 ) ;
F_13 ( & V_105 -> V_52 ) ;
}
}
}
static int F_325 ( struct V_240 * V_436 ,
struct V_240 * V_437 , T_2 V_36 )
{
int V_29 ;
V_29 = F_319 ( V_436 , V_36 ) ;
if ( V_29 )
return V_29 ;
F_322 ( V_437 , V_36 , 1 ) ;
return 0 ;
}
void F_326 ( struct V_240 * V_438 , unsigned short type )
{
memset ( V_438 , 0 , sizeof( * V_438 ) ) ;
F_260 ( & V_438 -> V_52 ) ;
V_438 -> type = type ;
}
struct V_240 * F_327 ( struct V_34 * V_35 ,
unsigned short type )
{
struct V_240 * V_391 ;
struct V_12 * V_37 = V_35 -> V_37 ;
V_391 = F_201 ( sizeof( * V_391 ) , V_40 ) ;
if ( ! V_391 )
return NULL ;
F_326 ( V_391 , type ) ;
V_391 -> V_105 = F_69 ( V_37 ,
V_295 ) ;
return V_391 ;
}
void F_328 ( struct V_34 * V_35 ,
struct V_240 * V_438 )
{
if ( ! V_438 )
return;
F_329 ( V_35 , V_438 , ( T_2 ) - 1 ) ;
F_9 ( V_438 ) ;
}
int F_330 ( struct V_34 * V_35 ,
struct V_240 * V_391 , T_2 V_36 ,
enum V_375 V_318 )
{
int V_29 ;
if ( V_36 == 0 )
return 0 ;
V_29 = F_315 ( V_35 , V_391 , V_36 , V_318 ) ;
if ( ! V_29 ) {
F_322 ( V_391 , V_36 , 1 ) ;
return 0 ;
}
return V_29 ;
}
int F_331 ( struct V_34 * V_35 ,
struct V_240 * V_391 , int V_433 )
{
T_2 V_36 = 0 ;
int V_29 = - V_357 ;
if ( ! V_391 )
return 0 ;
F_11 ( & V_391 -> V_52 ) ;
V_36 = F_285 ( V_391 -> V_56 , V_433 ) ;
if ( V_391 -> V_10 >= V_36 )
V_29 = 0 ;
F_13 ( & V_391 -> V_52 ) ;
return V_29 ;
}
int F_332 ( struct V_34 * V_35 ,
struct V_240 * V_391 , T_2 V_439 ,
enum V_375 V_318 )
{
T_2 V_36 = 0 ;
int V_29 = - V_357 ;
if ( ! V_391 )
return 0 ;
F_11 ( & V_391 -> V_52 ) ;
V_36 = V_439 ;
if ( V_391 -> V_10 >= V_36 )
V_29 = 0 ;
else
V_36 -= V_391 -> V_10 ;
F_13 ( & V_391 -> V_52 ) ;
if ( ! V_29 )
return 0 ;
V_29 = F_315 ( V_35 , V_391 , V_36 , V_318 ) ;
if ( ! V_29 ) {
F_322 ( V_391 , V_36 , 0 ) ;
return 0 ;
}
return V_29 ;
}
int F_333 ( struct V_240 * V_440 ,
struct V_240 * V_441 ,
T_2 V_36 )
{
return F_325 ( V_440 , V_441 , V_36 ) ;
}
void F_329 ( struct V_34 * V_35 ,
struct V_240 * V_391 ,
T_2 V_36 )
{
struct V_240 * V_241 = & V_35 -> V_37 -> V_242 ;
if ( V_241 == V_391 ||
V_391 -> V_105 != V_241 -> V_105 )
V_241 = NULL ;
F_324 ( V_35 -> V_37 , V_391 , V_241 ,
V_36 ) ;
}
static T_2 F_334 ( struct V_12 * V_37 )
{
struct V_102 * V_361 ;
T_2 V_36 ;
T_2 V_442 ;
T_2 V_443 ;
int V_444 = F_335 ( V_37 -> V_366 ) ;
V_361 = F_69 ( V_37 , V_296 ) ;
F_11 ( & V_361 -> V_52 ) ;
V_443 = V_361 -> V_299 ;
F_13 ( & V_361 -> V_52 ) ;
V_361 = F_69 ( V_37 , V_295 ) ;
F_11 ( & V_361 -> V_52 ) ;
if ( V_361 -> V_7 & V_296 )
V_443 = 0 ;
V_442 = V_361 -> V_299 ;
F_13 ( & V_361 -> V_52 ) ;
V_36 = ( V_443 >> V_37 -> V_385 -> V_445 ) *
V_444 * 2 ;
V_36 += F_184 ( V_443 + V_442 , 50 ) ;
if ( V_36 * 3 > V_442 )
V_36 = F_184 ( V_442 , 3 ) ;
return F_274 ( V_36 , V_37 -> V_62 -> V_87 << 10 ) ;
}
static void F_336 ( struct V_12 * V_37 )
{
struct V_240 * V_391 = & V_37 -> V_242 ;
struct V_102 * V_361 = V_391 -> V_105 ;
T_2 V_36 ;
V_36 = F_334 ( V_37 ) ;
F_11 ( & V_361 -> V_52 ) ;
F_11 ( & V_391 -> V_52 ) ;
V_391 -> V_56 = F_24 ( T_2 , V_36 , 512 * 1024 * 1024 ) ;
V_36 = V_361 -> V_299 + V_361 -> V_311 +
V_361 -> V_312 + V_361 -> V_313 +
V_361 -> V_314 ;
if ( V_361 -> V_298 > V_36 ) {
V_36 = V_361 -> V_298 - V_36 ;
V_391 -> V_10 += V_36 ;
V_361 -> V_314 += V_36 ;
F_279 ( V_37 , L_10 ,
V_361 -> V_7 , V_36 , 1 ) ;
}
if ( V_391 -> V_10 >= V_391 -> V_56 ) {
V_36 = V_391 -> V_10 - V_391 -> V_56 ;
V_361 -> V_314 -= V_36 ;
F_279 ( V_37 , L_10 ,
V_361 -> V_7 , V_36 , 0 ) ;
V_391 -> V_10 = V_391 -> V_56 ;
V_391 -> V_108 = 1 ;
}
F_13 ( & V_391 -> V_52 ) ;
F_13 ( & V_361 -> V_52 ) ;
}
static void F_337 ( struct V_12 * V_37 )
{
struct V_102 * V_105 ;
V_105 = F_69 ( V_37 , V_297 ) ;
V_37 -> V_446 . V_105 = V_105 ;
V_105 = F_69 ( V_37 , V_295 ) ;
V_37 -> V_242 . V_105 = V_105 ;
V_37 -> V_397 . V_105 = V_105 ;
V_37 -> V_447 . V_105 = V_105 ;
V_37 -> V_430 . V_105 = V_105 ;
V_37 -> V_404 . V_105 = V_105 ;
V_37 -> V_62 -> V_391 = & V_37 -> V_242 ;
V_37 -> V_427 -> V_391 = & V_37 -> V_242 ;
V_37 -> V_448 -> V_391 = & V_37 -> V_242 ;
V_37 -> V_86 -> V_391 = & V_37 -> V_242 ;
if ( V_37 -> V_449 )
V_37 -> V_449 -> V_391 = & V_37 -> V_242 ;
V_37 -> V_346 -> V_391 = & V_37 -> V_446 ;
F_336 ( V_37 ) ;
}
static void F_338 ( struct V_12 * V_37 )
{
F_324 ( V_37 , & V_37 -> V_242 , NULL ,
( T_2 ) - 1 ) ;
F_8 ( V_37 -> V_397 . V_56 > 0 ) ;
F_8 ( V_37 -> V_397 . V_10 > 0 ) ;
F_8 ( V_37 -> V_447 . V_56 > 0 ) ;
F_8 ( V_37 -> V_447 . V_10 > 0 ) ;
F_8 ( V_37 -> V_446 . V_56 > 0 ) ;
F_8 ( V_37 -> V_446 . V_10 > 0 ) ;
F_8 ( V_37 -> V_404 . V_56 > 0 ) ;
F_8 ( V_37 -> V_404 . V_10 > 0 ) ;
}
void F_339 ( struct V_109 * V_110 ,
struct V_34 * V_35 )
{
if ( ! V_110 -> V_391 )
return;
if ( ! V_110 -> V_312 )
return;
F_279 ( V_35 -> V_37 , L_12 ,
V_110 -> V_281 , V_110 -> V_312 , 0 ) ;
F_329 ( V_35 , V_110 -> V_391 , V_110 -> V_312 ) ;
V_110 -> V_312 = 0 ;
}
int F_340 ( struct V_109 * V_110 ,
struct V_271 * V_271 )
{
struct V_34 * V_35 = F_240 ( V_271 ) -> V_35 ;
struct V_240 * V_440 = F_321 ( V_110 , V_35 ) ;
struct V_240 * V_441 = V_35 -> V_450 ;
T_2 V_36 = F_190 ( V_35 , 1 ) ;
F_279 ( V_35 -> V_37 , L_13 ,
F_341 ( V_271 ) , V_36 , 1 ) ;
return F_325 ( V_440 , V_441 , V_36 ) ;
}
void F_342 ( struct V_271 * V_271 )
{
struct V_34 * V_35 = F_240 ( V_271 ) -> V_35 ;
T_2 V_36 = F_190 ( V_35 , 1 ) ;
F_279 ( V_35 -> V_37 , L_13 ,
F_341 ( V_271 ) , V_36 , 0 ) ;
F_329 ( V_35 , V_35 -> V_450 , V_36 ) ;
}
int F_343 ( struct V_34 * V_35 ,
struct V_240 * V_438 ,
int V_395 ,
T_2 * V_451 ,
bool V_452 )
{
T_2 V_36 ;
int V_29 ;
struct V_240 * V_241 = & V_35 -> V_37 -> V_242 ;
if ( V_35 -> V_37 -> V_206 ) {
V_36 = 3 * V_35 -> V_87 ;
V_29 = F_344 ( V_35 , V_36 ) ;
if ( V_29 )
return V_29 ;
} else {
V_36 = 0 ;
}
* V_451 = V_36 ;
V_36 = F_190 ( V_35 , V_395 ) ;
V_438 -> V_105 = F_69 ( V_35 -> V_37 ,
V_295 ) ;
V_29 = F_330 ( V_35 , V_438 , V_36 ,
V_381 ) ;
if ( V_29 == - V_357 && V_452 )
V_29 = F_333 ( V_241 , V_438 , V_36 ) ;
if ( V_29 ) {
if ( * V_451 )
F_345 ( V_35 , * V_451 ) ;
}
return V_29 ;
}
void F_346 ( struct V_34 * V_35 ,
struct V_240 * V_438 ,
T_2 V_451 )
{
F_329 ( V_35 , V_438 , ( T_2 ) - 1 ) ;
if ( V_451 )
F_345 ( V_35 , V_451 ) ;
}
static unsigned F_347 ( struct V_271 * V_271 , T_2 V_36 )
{
unsigned V_453 = 0 ;
unsigned V_454 = 0 ;
unsigned V_455 = 0 ;
V_455 = ( unsigned ) F_184 ( V_36 +
V_456 - 1 ,
V_456 ) ;
ASSERT ( V_455 ) ;
ASSERT ( F_240 ( V_271 ) -> V_457 >= V_455 ) ;
F_240 ( V_271 ) -> V_457 -= V_455 ;
if ( F_240 ( V_271 ) -> V_457 == 0 &&
F_348 ( V_458 ,
& F_240 ( V_271 ) -> V_459 ) )
V_453 = 1 ;
if ( F_240 ( V_271 ) -> V_457 >=
F_240 ( V_271 ) -> V_460 )
return V_453 ;
V_454 = F_240 ( V_271 ) -> V_460 -
F_240 ( V_271 ) -> V_457 ;
F_240 ( V_271 ) -> V_460 -= V_454 ;
return V_454 + V_453 ;
}
static T_2 F_349 ( struct V_271 * V_271 , T_2 V_36 ,
int V_461 )
{
struct V_34 * V_35 = F_240 ( V_271 ) -> V_35 ;
T_2 V_444 ;
int V_462 ;
int V_463 ;
int V_464 ;
if ( F_240 ( V_271 ) -> V_7 & V_465 &&
F_240 ( V_271 ) -> V_466 == 0 )
return 0 ;
V_464 = ( int ) F_184 ( F_240 ( V_271 ) -> V_466 , V_35 -> V_351 ) ;
if ( V_461 )
F_240 ( V_271 ) -> V_466 += V_36 ;
else
F_240 ( V_271 ) -> V_466 -= V_36 ;
V_444 = F_188 ( V_35 ) - sizeof( struct V_467 ) ;
V_462 = ( int ) F_184 ( V_444 ,
sizeof( struct V_468 ) +
sizeof( struct V_469 ) ) ;
V_463 = ( int ) F_184 ( F_240 ( V_271 ) -> V_466 , V_35 -> V_351 ) ;
V_463 = V_463 + V_462 - 1 ;
V_463 = V_463 / V_462 ;
V_464 = V_464 + V_462 - 1 ;
V_464 = V_464 / V_462 ;
if ( V_464 == V_463 )
return 0 ;
if ( V_461 )
return F_190 ( V_35 ,
V_463 - V_464 ) ;
return F_190 ( V_35 , V_464 - V_463 ) ;
}
int F_350 ( struct V_271 * V_271 , T_2 V_36 )
{
struct V_34 * V_35 = F_240 ( V_271 ) -> V_35 ;
struct V_240 * V_391 = & V_35 -> V_37 -> V_397 ;
T_2 V_470 = 0 ;
T_2 V_466 ;
unsigned V_471 = 0 ;
int V_472 = 0 ;
enum V_375 V_318 = V_381 ;
int V_29 = 0 ;
bool V_473 = true ;
T_2 V_474 = 0 ;
unsigned V_475 ;
if ( F_275 ( V_271 ) ) {
V_318 = V_402 ;
V_473 = false ;
}
if ( V_318 != V_402 &&
F_351 ( V_35 -> V_37 ) )
F_352 ( 1 ) ;
if ( V_473 )
F_35 ( & F_240 ( V_271 ) -> V_476 ) ;
V_36 = F_274 ( V_36 , V_35 -> V_351 ) ;
F_11 ( & F_240 ( V_271 ) -> V_52 ) ;
V_471 = ( unsigned ) F_184 ( V_36 +
V_456 - 1 ,
V_456 ) ;
F_240 ( V_271 ) -> V_457 += V_471 ;
V_471 = 0 ;
if ( F_240 ( V_271 ) -> V_457 >
F_240 ( V_271 ) -> V_460 )
V_471 = F_240 ( V_271 ) -> V_457 -
F_240 ( V_271 ) -> V_460 ;
if ( ! F_223 ( V_458 ,
& F_240 ( V_271 ) -> V_459 ) ) {
V_471 ++ ;
V_472 = 1 ;
}
V_470 = F_190 ( V_35 , V_471 ) ;
V_470 += F_349 ( V_271 , V_36 , 1 ) ;
V_466 = F_240 ( V_271 ) -> V_466 ;
F_13 ( & F_240 ( V_271 ) -> V_52 ) ;
if ( V_35 -> V_37 -> V_206 ) {
V_29 = F_344 ( V_35 , V_36 +
V_471 * V_35 -> V_87 ) ;
if ( V_29 )
goto V_477;
}
V_29 = F_315 ( V_35 , V_391 , V_470 , V_318 ) ;
if ( F_318 ( V_29 ) ) {
if ( V_35 -> V_37 -> V_206 )
F_345 ( V_35 , V_36 +
V_471 * V_35 -> V_87 ) ;
goto V_477;
}
F_11 ( & F_240 ( V_271 ) -> V_52 ) ;
if ( V_472 ) {
F_353 ( V_458 ,
& F_240 ( V_271 ) -> V_459 ) ;
V_471 -- ;
}
F_240 ( V_271 ) -> V_460 += V_471 ;
F_13 ( & F_240 ( V_271 ) -> V_52 ) ;
if ( V_473 )
F_46 ( & F_240 ( V_271 ) -> V_476 ) ;
if ( V_470 )
F_279 ( V_35 -> V_37 , L_14 ,
F_341 ( V_271 ) , V_470 , 1 ) ;
F_322 ( V_391 , V_470 , 1 ) ;
return 0 ;
V_477:
F_11 ( & F_240 ( V_271 ) -> V_52 ) ;
V_475 = F_347 ( V_271 , V_36 ) ;
if ( F_240 ( V_271 ) -> V_466 == V_466 ) {
F_349 ( V_271 , V_36 , 0 ) ;
} else {
T_2 V_478 = F_240 ( V_271 ) -> V_466 ;
T_2 V_347 ;
V_347 = V_466 - F_240 ( V_271 ) -> V_466 ;
F_240 ( V_271 ) -> V_466 = V_466 ;
V_474 = F_349 ( V_271 , V_347 , 0 ) ;
F_240 ( V_271 ) -> V_466 = V_466 - V_36 ;
V_347 = V_466 - V_478 ;
V_347 = F_349 ( V_271 , V_347 , 0 ) ;
F_240 ( V_271 ) -> V_466 = V_478 - V_36 ;
if ( V_347 > V_474 )
V_474 = V_347 - V_474 ;
else
V_474 = 0 ;
}
F_13 ( & F_240 ( V_271 ) -> V_52 ) ;
if ( V_475 )
V_474 += F_190 ( V_35 , V_475 ) ;
if ( V_474 ) {
F_329 ( V_35 , V_391 , V_474 ) ;
F_279 ( V_35 -> V_37 , L_14 ,
F_341 ( V_271 ) , V_474 , 0 ) ;
}
if ( V_473 )
F_46 ( & F_240 ( V_271 ) -> V_476 ) ;
return V_29 ;
}
void F_354 ( struct V_271 * V_271 , T_2 V_36 )
{
struct V_34 * V_35 = F_240 ( V_271 ) -> V_35 ;
T_2 V_474 = 0 ;
unsigned V_475 ;
V_36 = F_274 ( V_36 , V_35 -> V_351 ) ;
F_11 ( & F_240 ( V_271 ) -> V_52 ) ;
V_475 = F_347 ( V_271 , V_36 ) ;
if ( V_36 )
V_474 = F_349 ( V_271 , V_36 , 0 ) ;
F_13 ( & F_240 ( V_271 ) -> V_52 ) ;
if ( V_475 > 0 )
V_474 += F_190 ( V_35 , V_475 ) ;
if ( F_220 ( V_35 ) )
return;
F_279 ( V_35 -> V_37 , L_14 ,
F_341 ( V_271 ) , V_474 , 0 ) ;
if ( V_35 -> V_37 -> V_206 ) {
F_345 ( V_35 , V_36 +
V_475 * V_35 -> V_87 ) ;
}
F_329 ( V_35 , & V_35 -> V_37 -> V_397 ,
V_474 ) ;
}
int F_355 ( struct V_271 * V_271 , T_2 V_36 )
{
int V_29 ;
V_29 = F_245 ( V_271 , V_36 ) ;
if ( V_29 )
return V_29 ;
V_29 = F_350 ( V_271 , V_36 ) ;
if ( V_29 ) {
F_247 ( V_271 , V_36 ) ;
return V_29 ;
}
return 0 ;
}
void F_356 ( struct V_271 * V_271 , T_2 V_36 )
{
F_354 ( V_271 , V_36 ) ;
F_247 ( V_271 , V_36 ) ;
}
static int F_357 ( struct V_109 * V_110 ,
struct V_34 * V_35 , T_2 V_27 ,
T_2 V_36 , int V_354 )
{
struct V_1 * V_2 = NULL ;
struct V_12 * V_13 = V_35 -> V_37 ;
T_2 V_479 = V_36 ;
T_2 V_480 ;
T_2 V_481 ;
int V_300 ;
F_11 ( & V_13 -> V_482 ) ;
V_480 = F_358 ( V_13 -> V_366 ) ;
if ( V_354 )
V_480 += V_36 ;
else
V_480 -= V_36 ;
F_359 ( V_13 -> V_366 , V_480 ) ;
F_13 ( & V_13 -> V_482 ) ;
while ( V_479 ) {
V_2 = F_68 ( V_13 , V_27 ) ;
if ( ! V_2 )
return - V_153 ;
if ( V_2 -> V_7 & ( V_301 |
V_302 |
V_303 ) )
V_300 = 2 ;
else
V_300 = 1 ;
if ( ! V_354 && V_2 -> V_3 == V_94 )
F_51 ( V_2 , 1 ) ;
F_11 ( & V_110 -> V_127 -> V_483 ) ;
if ( F_205 ( & V_2 -> V_293 ) ) {
F_64 ( & V_2 -> V_293 ,
& V_110 -> V_127 -> V_291 ) ;
F_4 ( V_2 ) ;
}
F_13 ( & V_110 -> V_127 -> V_483 ) ;
V_481 = V_27 - V_2 -> V_21 . V_22 ;
F_8 ( V_481 > V_2 -> V_21 . V_33 ) ;
F_11 ( & V_2 -> V_105 -> V_52 ) ;
F_11 ( & V_2 -> V_52 ) ;
if ( F_244 ( V_35 , V_285 ) &&
V_2 -> V_277 < V_292 )
V_2 -> V_277 = V_292 ;
V_480 = F_360 ( & V_2 -> V_135 ) ;
V_36 = F_301 ( V_479 , V_2 -> V_21 . V_33 - V_481 ) ;
if ( V_354 ) {
V_480 += V_36 ;
F_361 ( & V_2 -> V_135 , V_480 ) ;
V_2 -> V_10 -= V_36 ;
V_2 -> V_105 -> V_312 -= V_36 ;
V_2 -> V_105 -> V_299 += V_36 ;
V_2 -> V_105 -> V_305 += V_36 * V_300 ;
F_13 ( & V_2 -> V_52 ) ;
F_13 ( & V_2 -> V_105 -> V_52 ) ;
} else {
V_480 -= V_36 ;
F_361 ( & V_2 -> V_135 , V_480 ) ;
V_2 -> V_9 += V_36 ;
V_2 -> V_105 -> V_311 += V_36 ;
V_2 -> V_105 -> V_299 -= V_36 ;
V_2 -> V_105 -> V_305 -= V_36 * V_300 ;
F_13 ( & V_2 -> V_52 ) ;
F_13 ( & V_2 -> V_105 -> V_52 ) ;
F_362 ( V_13 -> V_58 ,
V_27 , V_27 + V_36 - 1 ,
V_40 | V_484 ) ;
if ( V_480 == 0 ) {
F_11 ( & V_13 -> V_485 ) ;
if ( F_205 ( & V_2 -> V_486 ) ) {
F_4 ( V_2 ) ;
F_64 ( & V_2 -> V_486 ,
& V_13 -> V_487 ) ;
}
F_13 ( & V_13 -> V_485 ) ;
}
}
F_6 ( V_2 ) ;
V_479 -= V_36 ;
V_27 += V_36 ;
}
return 0 ;
}
static T_2 V_26 ( struct V_34 * V_35 , T_2 V_488 )
{
struct V_1 * V_2 ;
T_2 V_27 ;
F_11 ( & V_35 -> V_37 -> V_18 ) ;
V_27 = V_35 -> V_37 -> V_26 ;
F_13 ( & V_35 -> V_37 -> V_18 ) ;
if ( V_27 < ( T_2 ) - 1 )
return V_27 ;
V_2 = F_67 ( V_35 -> V_37 , V_488 ) ;
if ( ! V_2 )
return 0 ;
V_27 = V_2 -> V_21 . V_22 ;
F_6 ( V_2 ) ;
return V_27 ;
}
static int F_363 ( struct V_34 * V_35 ,
struct V_1 * V_2 ,
T_2 V_27 , T_2 V_36 , int V_10 )
{
F_11 ( & V_2 -> V_105 -> V_52 ) ;
F_11 ( & V_2 -> V_52 ) ;
V_2 -> V_9 += V_36 ;
V_2 -> V_105 -> V_311 += V_36 ;
if ( V_10 ) {
V_2 -> V_10 -= V_36 ;
V_2 -> V_105 -> V_312 -= V_36 ;
}
F_13 ( & V_2 -> V_52 ) ;
F_13 ( & V_2 -> V_105 -> V_52 ) ;
F_362 ( V_35 -> V_37 -> V_58 , V_27 ,
V_27 + V_36 - 1 , V_40 | V_484 ) ;
if ( V_10 )
F_364 ( V_35 , V_27 , V_36 ) ;
return 0 ;
}
int F_164 ( struct V_34 * V_35 ,
T_2 V_27 , T_2 V_36 , int V_10 )
{
struct V_1 * V_2 ;
V_2 = F_68 ( V_35 -> V_37 , V_27 ) ;
F_30 ( ! V_2 ) ;
F_363 ( V_35 , V_2 , V_27 , V_36 , V_10 ) ;
F_6 ( V_2 ) ;
return 0 ;
}
int F_365 ( struct V_34 * V_35 ,
T_2 V_27 , T_2 V_36 )
{
struct V_1 * V_2 ;
int V_29 ;
V_2 = F_68 ( V_35 -> V_37 , V_27 ) ;
if ( ! V_2 )
return - V_489 ;
F_51 ( V_2 , 1 ) ;
F_363 ( V_35 , V_2 , V_27 , V_36 , 0 ) ;
V_29 = F_366 ( V_2 , V_27 , V_36 ) ;
F_6 ( V_2 ) ;
return V_29 ;
}
static int F_367 ( struct V_34 * V_35 , T_2 V_32 , T_2 V_36 )
{
int V_29 ;
struct V_1 * V_14 ;
struct V_50 * V_53 ;
V_14 = F_68 ( V_35 -> V_37 , V_32 ) ;
if ( ! V_14 )
return - V_489 ;
F_51 ( V_14 , 0 ) ;
V_53 = F_25 ( V_14 ) ;
if ( ! V_53 ) {
F_30 ( ! F_1 ( V_14 ) ) ;
V_29 = F_366 ( V_14 , V_32 , V_36 ) ;
} else {
F_35 ( & V_53 -> V_78 ) ;
if ( V_32 >= V_53 -> V_84 ) {
V_29 = F_17 ( V_35 , V_32 , V_36 ) ;
} else if ( V_32 + V_36 <= V_53 -> V_84 ) {
V_29 = F_366 ( V_14 ,
V_32 , V_36 ) ;
} else {
V_36 = V_53 -> V_84 - V_32 ;
V_29 = F_366 ( V_14 ,
V_32 , V_36 ) ;
if ( V_29 )
goto V_490;
V_36 = ( V_32 + V_36 ) -
V_53 -> V_84 ;
V_32 = V_53 -> V_84 ;
V_29 = F_17 ( V_35 , V_32 , V_36 ) ;
}
V_490:
F_46 ( & V_53 -> V_78 ) ;
F_26 ( V_53 ) ;
}
F_6 ( V_14 ) ;
return V_29 ;
}
int F_368 ( struct V_34 * log ,
struct V_65 * V_491 )
{
struct V_263 * V_135 ;
struct V_67 V_21 ;
int V_492 ;
int V_43 ;
if ( ! F_76 ( log -> V_37 , V_493 ) )
return 0 ;
for ( V_43 = 0 ; V_43 < F_38 ( V_491 ) ; V_43 ++ ) {
F_40 ( V_491 , & V_21 , V_43 ) ;
if ( V_21 . type != V_268 )
continue;
V_135 = F_78 ( V_491 , V_43 , struct V_263 ) ;
V_492 = F_224 ( V_491 , V_135 ) ;
if ( V_492 == V_269 )
continue;
if ( F_225 ( V_491 , V_135 ) == 0 )
continue;
V_21 . V_22 = F_225 ( V_491 , V_135 ) ;
V_21 . V_33 = F_226 ( V_491 , V_135 ) ;
F_367 ( log , V_21 . V_22 , V_21 . V_33 ) ;
}
return 0 ;
}
static int F_369 ( struct V_1 * V_2 ,
T_2 V_36 , int V_461 , int V_494 )
{
struct V_102 * V_105 = V_2 -> V_105 ;
int V_29 = 0 ;
F_11 ( & V_105 -> V_52 ) ;
F_11 ( & V_2 -> V_52 ) ;
if ( V_461 != V_495 ) {
if ( V_2 -> V_279 ) {
V_29 = - V_178 ;
} else {
V_2 -> V_10 += V_36 ;
V_105 -> V_312 += V_36 ;
if ( V_461 == V_496 ) {
F_279 ( V_2 -> V_37 ,
L_10 , V_105 -> V_7 ,
V_36 , 0 ) ;
V_105 -> V_314 -= V_36 ;
}
if ( V_494 )
V_2 -> V_286 += V_36 ;
}
} else {
if ( V_2 -> V_279 )
V_105 -> V_313 += V_36 ;
V_2 -> V_10 -= V_36 ;
V_105 -> V_312 -= V_36 ;
if ( V_494 )
V_2 -> V_286 -= V_36 ;
}
F_13 ( & V_2 -> V_52 ) ;
F_13 ( & V_105 -> V_52 ) ;
return V_29 ;
}
void F_370 ( struct V_109 * V_110 ,
struct V_34 * V_35 )
{
struct V_12 * V_37 = V_35 -> V_37 ;
struct V_50 * V_80 ;
struct V_50 * V_53 ;
struct V_1 * V_2 ;
F_63 ( & V_37 -> V_79 ) ;
F_250 (caching_ctl, next,
&fs_info->caching_block_groups, list) {
V_2 = V_53 -> V_14 ;
if ( F_1 ( V_2 ) ) {
V_2 -> V_97 = ( T_2 ) - 1 ;
F_253 ( & V_53 -> V_90 ) ;
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
F_336 ( V_37 ) ;
}
static int F_371 ( struct V_34 * V_35 , T_2 V_32 , T_2 V_31 ,
const bool V_497 )
{
struct V_12 * V_37 = V_35 -> V_37 ;
struct V_1 * V_2 = NULL ;
struct V_102 * V_105 ;
struct V_240 * V_241 = & V_37 -> V_242 ;
T_2 V_49 ;
bool V_294 ;
while ( V_32 <= V_31 ) {
V_294 = false ;
if ( ! V_2 ||
V_32 >= V_2 -> V_21 . V_22 + V_2 -> V_21 . V_33 ) {
if ( V_2 )
F_6 ( V_2 ) ;
V_2 = F_68 ( V_37 , V_32 ) ;
F_30 ( ! V_2 ) ;
}
V_49 = V_2 -> V_21 . V_22 + V_2 -> V_21 . V_33 - V_32 ;
V_49 = F_301 ( V_49 , V_31 + 1 - V_32 ) ;
if ( V_32 < V_2 -> V_97 ) {
V_49 = F_301 ( V_49 , V_2 -> V_97 - V_32 ) ;
if ( V_497 )
F_29 ( V_2 , V_32 , V_49 ) ;
}
V_32 += V_49 ;
V_105 = V_2 -> V_105 ;
F_11 ( & V_105 -> V_52 ) ;
F_11 ( & V_2 -> V_52 ) ;
V_2 -> V_9 -= V_49 ;
V_105 -> V_311 -= V_49 ;
F_372 ( & V_105 -> V_306 , - V_49 ) ;
if ( V_2 -> V_279 ) {
V_105 -> V_313 += V_49 ;
V_294 = true ;
}
F_13 ( & V_2 -> V_52 ) ;
if ( ! V_294 && V_241 -> V_105 == V_105 ) {
F_11 ( & V_241 -> V_52 ) ;
if ( ! V_241 -> V_108 ) {
V_49 = F_301 ( V_49 , V_241 -> V_56 -
V_241 -> V_10 ) ;
V_241 -> V_10 += V_49 ;
V_105 -> V_314 += V_49 ;
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
int F_373 ( struct V_109 * V_110 ,
struct V_34 * V_35 )
{
struct V_12 * V_37 = V_35 -> V_37 ;
struct V_498 * V_499 ;
T_2 V_32 ;
T_2 V_31 ;
int V_29 ;
if ( V_110 -> V_217 )
return 0 ;
if ( V_37 -> V_58 == & V_37 -> V_38 [ 0 ] )
V_499 = & V_37 -> V_38 [ 1 ] ;
else
V_499 = & V_37 -> V_38 [ 0 ] ;
while ( 1 ) {
F_35 ( & V_37 -> V_500 ) ;
V_29 = F_28 ( V_499 , 0 , & V_32 , & V_31 ,
V_59 , NULL ) ;
if ( V_29 ) {
F_46 ( & V_37 -> V_500 ) ;
break;
}
if ( F_244 ( V_35 , V_501 ) )
V_29 = F_142 ( V_35 , V_32 ,
V_31 + 1 - V_32 , NULL ) ;
F_374 ( V_499 , V_32 , V_31 , V_40 ) ;
F_371 ( V_35 , V_32 , V_31 , true ) ;
F_46 ( & V_37 -> V_500 ) ;
F_47 () ;
}
return 0 ;
}
static void F_375 ( struct V_12 * V_37 , T_2 V_36 ,
T_2 V_133 , T_2 V_146 )
{
struct V_102 * V_105 ;
T_2 V_7 ;
if ( V_133 < V_143 ) {
if ( V_146 == V_502 )
V_7 = V_297 ;
else
V_7 = V_295 ;
} else {
V_7 = V_296 ;
}
V_105 = F_69 ( V_37 , V_7 ) ;
F_30 ( ! V_105 ) ;
F_372 ( & V_105 -> V_306 , V_36 ) ;
}
static int F_156 ( struct V_109 * V_110 ,
struct V_34 * V_35 ,
T_2 V_27 , T_2 V_36 , T_2 V_17 ,
T_2 V_146 , T_2 V_503 ,
T_2 V_504 , int V_159 ,
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
int V_505 = 0 ;
int V_506 = 0 ;
int V_507 = 1 ;
T_3 V_118 ;
T_2 V_112 ;
int V_160 = 0 ;
enum V_204 type = V_508 ;
bool V_173 = F_76 ( V_35 -> V_37 ,
V_121 ) ;
if ( ! V_13 -> V_206 || ! F_149 ( V_146 ) )
V_201 = 1 ;
V_64 = F_33 () ;
if ( ! V_64 )
return - V_71 ;
V_64 -> V_75 = 1 ;
V_64 -> V_207 = 1 ;
V_184 = V_503 >= V_143 ;
F_30 ( ! V_184 && V_159 != 1 ) ;
if ( V_184 )
V_173 = 0 ;
V_29 = F_134 ( V_110 , V_62 , V_64 , & V_164 ,
V_27 , V_36 , V_17 ,
V_146 , V_503 ,
V_504 ) ;
if ( V_29 == 0 ) {
V_505 = V_64 -> V_83 [ 0 ] ;
while ( V_505 >= 0 ) {
F_40 ( V_64 -> V_82 [ 0 ] , & V_21 ,
V_505 ) ;
if ( V_21 . V_22 != V_27 )
break;
if ( V_21 . type == V_76 &&
V_21 . V_33 == V_36 ) {
V_506 = 1 ;
break;
}
if ( V_21 . type == V_85 &&
V_21 . V_33 == V_503 ) {
V_506 = 1 ;
break;
}
if ( V_64 -> V_83 [ 0 ] - V_505 > 5 )
break;
V_505 -- ;
}
#ifdef F_81
V_118 = F_77 ( V_64 -> V_82 [ 0 ] , V_505 ) ;
if ( V_506 && V_118 < sizeof( * V_117 ) )
V_506 = 0 ;
#endif
if ( ! V_506 ) {
F_30 ( V_164 ) ;
V_29 = F_139 ( V_110 , V_62 , V_64 ,
NULL , V_159 ,
V_184 , & V_160 ) ;
if ( V_29 ) {
F_151 ( V_110 , V_62 , V_29 ) ;
goto V_72;
}
F_44 ( V_64 ) ;
V_64 -> V_207 = 1 ;
V_21 . V_22 = V_27 ;
V_21 . type = V_76 ;
V_21 . V_33 = V_36 ;
if ( ! V_184 && V_173 ) {
V_21 . type = V_85 ;
V_21 . V_33 = V_503 ;
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
F_376 ( V_13 , L_15 ,
V_29 , V_27 ) ;
if ( V_29 > 0 )
F_377 ( V_62 ,
V_64 -> V_82 [ 0 ] ) ;
}
if ( V_29 < 0 ) {
F_151 ( V_110 , V_62 , V_29 ) ;
goto V_72;
}
V_505 = V_64 -> V_83 [ 0 ] ;
}
} else if ( F_8 ( V_29 == - V_153 ) ) {
F_377 ( V_62 , V_64 -> V_82 [ 0 ] ) ;
F_376 ( V_13 ,
L_16 ,
V_27 , V_17 , V_146 , V_503 ,
V_504 ) ;
F_151 ( V_110 , V_62 , V_29 ) ;
goto V_72;
} else {
F_151 ( V_110 , V_62 , V_29 ) ;
goto V_72;
}
V_66 = V_64 -> V_82 [ 0 ] ;
V_118 = F_77 ( V_66 , V_505 ) ;
#ifdef F_81
if ( V_118 < sizeof( * V_117 ) ) {
F_30 ( V_506 || V_505 != V_64 -> V_83 [ 0 ] ) ;
V_29 = F_87 ( V_110 , V_62 , V_64 ,
V_503 , 0 ) ;
if ( V_29 < 0 ) {
F_151 ( V_110 , V_62 , V_29 ) ;
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
F_376 ( V_13 , L_15 ,
V_29 , V_27 ) ;
F_377 ( V_62 , V_64 -> V_82 [ 0 ] ) ;
}
if ( V_29 < 0 ) {
F_151 ( V_110 , V_62 , V_29 ) ;
goto V_72;
}
V_505 = V_64 -> V_83 [ 0 ] ;
V_66 = V_64 -> V_82 [ 0 ] ;
V_118 = F_77 ( V_66 , V_505 ) ;
}
#endif
F_30 ( V_118 < sizeof( * V_117 ) ) ;
V_117 = F_78 ( V_66 , V_505 ,
struct V_116 ) ;
if ( V_503 < V_143 &&
V_21 . type == V_76 ) {
struct V_138 * V_139 ;
F_30 ( V_118 < sizeof( * V_117 ) + sizeof( * V_139 ) ) ;
V_139 = (struct V_138 * ) ( V_117 + 1 ) ;
F_8 ( V_503 != F_378 ( V_66 , V_139 ) ) ;
}
V_112 = F_79 ( V_66 , V_117 ) ;
if ( V_112 < V_159 ) {
F_376 ( V_13 , L_17
L_18 , V_159 , V_112 , V_27 ) ;
V_29 = - V_489 ;
F_151 ( V_110 , V_62 , V_29 ) ;
goto V_72;
}
V_112 -= V_159 ;
if ( V_112 > 0 ) {
type = V_509 ;
if ( V_129 )
F_130 ( V_129 , V_66 , V_117 ) ;
if ( V_164 ) {
F_30 ( ! V_506 ) ;
} else {
F_90 ( V_66 , V_117 , V_112 ) ;
F_95 ( V_66 ) ;
}
if ( V_506 ) {
V_29 = F_139 ( V_110 , V_62 , V_64 ,
V_164 , V_159 ,
V_184 , & V_160 ) ;
if ( V_29 ) {
F_151 ( V_110 , V_62 , V_29 ) ;
goto V_72;
}
}
F_375 ( V_35 -> V_37 , - V_36 , V_503 ,
V_146 ) ;
} else {
if ( V_506 ) {
F_30 ( V_184 && V_159 !=
F_118 ( V_35 , V_64 , V_164 ) ) ;
if ( V_164 ) {
F_30 ( V_64 -> V_83 [ 0 ] != V_505 ) ;
} else {
F_30 ( V_64 -> V_83 [ 0 ] != V_505 + 1 ) ;
V_64 -> V_83 [ 0 ] = V_505 ;
V_507 = 2 ;
}
}
V_160 = 1 ;
V_29 = F_379 ( V_110 , V_62 , V_64 , V_64 -> V_83 [ 0 ] ,
V_507 ) ;
if ( V_29 ) {
F_151 ( V_110 , V_62 , V_29 ) ;
goto V_72;
}
F_44 ( V_64 ) ;
if ( V_184 ) {
V_29 = F_168 ( V_110 , V_35 , V_27 , V_36 ) ;
if ( V_29 ) {
F_151 ( V_110 , V_62 , V_29 ) ;
goto V_72;
}
}
V_29 = F_357 ( V_110 , V_35 , V_27 , V_36 , 0 ) ;
if ( V_29 ) {
F_151 ( V_110 , V_62 , V_29 ) ;
goto V_72;
}
}
F_44 ( V_64 ) ;
if ( ! V_29 && V_160 && ! V_201 ) {
int V_510 = 0 ;
if ( V_503 >= V_143 &&
type == V_509 )
V_510 = 1 ;
V_29 = F_150 ( V_110 , V_13 , V_146 ,
V_27 , V_36 , type ,
V_510 ) ;
}
V_72:
F_50 ( V_64 ) ;
return V_29 ;
}
static T_1 int F_380 ( struct V_109 * V_110 ,
struct V_34 * V_35 , T_2 V_27 )
{
struct V_113 * V_104 ;
struct V_114 * V_115 ;
int V_29 = 0 ;
V_115 = & V_110 -> V_127 -> V_115 ;
F_11 ( & V_115 -> V_52 ) ;
V_104 = F_84 ( V_110 , V_27 ) ;
if ( ! V_104 )
goto V_511;
F_11 ( & V_104 -> V_52 ) ;
if ( F_179 ( & V_104 -> V_213 ) )
goto V_72;
if ( V_104 -> V_129 ) {
if ( ! V_104 -> V_221 )
goto V_72;
F_177 ( V_104 -> V_129 ) ;
V_104 -> V_129 = NULL ;
}
if ( ! F_85 ( & V_104 -> V_78 ) )
goto V_72;
V_104 -> V_128 . V_225 = 0 ;
F_180 ( & V_104 -> V_227 , & V_115 -> V_228 ) ;
F_181 ( & V_115 -> V_229 ) ;
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
V_511:
F_13 ( & V_115 -> V_52 ) ;
return 0 ;
}
void F_381 ( struct V_109 * V_110 ,
struct V_34 * V_35 ,
struct V_65 * V_260 ,
T_2 V_17 , int V_160 )
{
int V_512 = 1 ;
int V_29 ;
if ( V_35 -> V_256 . V_22 != V_202 ) {
V_29 = F_146 ( V_35 -> V_37 , V_110 ,
V_260 -> V_32 , V_260 -> V_49 ,
V_17 , V_35 -> V_256 . V_22 ,
F_222 ( V_260 ) ,
V_215 , NULL , 0 ) ;
F_30 ( V_29 ) ;
}
if ( ! V_160 )
return;
if ( F_382 ( V_260 ) == V_110 -> V_281 ) {
struct V_1 * V_2 ;
if ( V_35 -> V_256 . V_22 != V_202 ) {
V_29 = F_380 ( V_110 , V_35 , V_260 -> V_32 ) ;
if ( ! V_29 )
goto V_72;
}
V_2 = F_68 ( V_35 -> V_37 , V_260 -> V_32 ) ;
if ( F_383 ( V_260 , V_513 ) ) {
F_363 ( V_35 , V_2 , V_260 -> V_32 , V_260 -> V_49 , 1 ) ;
F_6 ( V_2 ) ;
goto V_72;
}
F_8 ( F_223 ( V_514 , & V_260 -> V_515 ) ) ;
F_29 ( V_2 , V_260 -> V_32 , V_260 -> V_49 ) ;
F_369 ( V_2 , V_260 -> V_49 , V_495 , 0 ) ;
F_6 ( V_2 ) ;
F_364 ( V_35 , V_260 -> V_32 , V_260 -> V_49 ) ;
V_512 = 0 ;
}
V_72:
if ( V_512 )
F_375 ( V_35 -> V_37 , V_260 -> V_49 ,
F_222 ( V_260 ) ,
V_35 -> V_256 . V_22 ) ;
F_384 ( V_516 , & V_260 -> V_515 ) ;
}
int V_267 ( struct V_109 * V_110 , struct V_34 * V_35 ,
T_2 V_27 , T_2 V_36 , T_2 V_17 , T_2 V_146 ,
T_2 V_133 , T_2 V_33 , int V_201 )
{
int V_29 ;
struct V_12 * V_37 = V_35 -> V_37 ;
if ( F_220 ( V_35 ) )
return 0 ;
F_375 ( V_35 -> V_37 , V_36 , V_133 , V_146 ) ;
if ( V_146 == V_202 ) {
F_8 ( V_133 >= V_143 ) ;
F_164 ( V_35 , V_27 , V_36 , 1 ) ;
V_29 = 0 ;
} else if ( V_133 < V_143 ) {
V_29 = F_146 ( V_37 , V_110 , V_27 ,
V_36 ,
V_17 , V_146 , ( int ) V_133 ,
V_215 , NULL , V_201 ) ;
} else {
V_29 = F_147 ( V_37 , V_110 , V_27 ,
V_36 ,
V_17 , V_146 , V_133 ,
V_33 , V_215 ,
NULL , V_201 ) ;
}
return V_29 ;
}
static T_1 void
F_385 ( struct V_1 * V_2 ,
T_2 V_36 )
{
struct V_50 * V_53 ;
V_53 = F_25 ( V_2 ) ;
if ( ! V_53 )
return;
F_302 ( V_53 -> V_88 , F_1 ( V_2 ) ||
( V_2 -> V_11 -> V_517 >= V_36 ) ) ;
F_26 ( V_53 ) ;
}
static T_1 int
F_386 ( struct V_1 * V_2 )
{
struct V_50 * V_53 ;
int V_29 = 0 ;
V_53 = F_25 ( V_2 ) ;
if ( ! V_53 )
return ( V_2 -> V_3 == V_5 ) ? - V_175 : 0 ;
F_302 ( V_53 -> V_88 , F_1 ( V_2 ) ) ;
if ( V_2 -> V_3 == V_5 )
V_29 = - V_175 ;
F_26 ( V_53 ) ;
return V_29 ;
}
int F_387 ( T_2 V_7 )
{
if ( V_7 & V_303 )
return V_518 ;
else if ( V_7 & V_302 )
return V_519 ;
else if ( V_7 & V_301 )
return V_520 ;
else if ( V_7 & V_342 )
return V_521 ;
else if ( V_7 & V_343 )
return V_522 ;
else if ( V_7 & V_344 )
return V_523 ;
return V_524 ;
}
int F_388 ( struct V_1 * V_2 )
{
return F_387 ( V_2 -> V_7 ) ;
}
static const char * F_389 ( enum V_525 type )
{
if ( type >= V_308 )
return NULL ;
return V_526 [ type ] ;
}
static inline void
F_390 ( struct V_1 * V_2 ,
int V_494 )
{
if ( V_494 )
F_36 ( & V_2 -> V_527 ) ;
}
static inline void
F_391 ( struct V_1 * V_2 ,
int V_494 )
{
F_4 ( V_2 ) ;
if ( V_494 )
F_36 ( & V_2 -> V_527 ) ;
}
static struct V_1 *
F_392 ( struct V_1 * V_14 ,
struct V_528 * V_529 ,
int V_494 )
{
struct V_1 * V_530 ;
bool V_531 = false ;
V_77:
F_11 ( & V_529 -> V_532 ) ;
if ( V_531 ) {
if ( V_530 == V_529 -> V_14 )
return V_530 ;
F_45 ( & V_530 -> V_527 ) ;
F_6 ( V_530 ) ;
}
V_530 = V_529 -> V_14 ;
if ( ! V_530 )
return NULL ;
if ( V_530 == V_14 )
return V_530 ;
F_4 ( V_530 ) ;
if ( ! V_494 )
return V_530 ;
if ( F_294 ( & V_530 -> V_527 ) )
return V_530 ;
F_13 ( & V_529 -> V_532 ) ;
F_36 ( & V_530 -> V_527 ) ;
V_531 = true ;
goto V_77;
}
static inline void
F_393 ( struct V_1 * V_2 ,
int V_494 )
{
if ( V_494 )
F_45 ( & V_2 -> V_527 ) ;
F_6 ( V_2 ) ;
}
static T_1 int F_394 ( struct V_34 * V_533 ,
T_2 V_36 , T_2 V_534 ,
T_2 V_535 , struct V_67 * V_212 ,
T_2 V_7 , int V_494 )
{
int V_29 = 0 ;
struct V_34 * V_35 = V_533 -> V_37 -> V_62 ;
struct V_528 * V_536 = NULL ;
struct V_1 * V_14 = NULL ;
T_2 V_488 = 0 ;
T_2 V_537 = 0 ;
int V_538 = 2 * 1024 * 1024 ;
struct V_102 * V_105 ;
int V_539 = 0 ;
int V_540 = F_387 ( V_7 ) ;
int V_541 = ( V_7 & V_296 ) ?
V_542 : V_496 ;
bool V_543 = false ;
bool V_544 = false ;
bool V_545 = true ;
bool V_546 = false ;
F_8 ( V_36 < V_35 -> V_351 ) ;
V_212 -> type = V_76 ;
V_212 -> V_22 = 0 ;
V_212 -> V_33 = 0 ;
F_395 ( V_533 , V_36 , V_534 , V_7 ) ;
V_105 = F_69 ( V_35 -> V_37 , V_7 ) ;
if ( ! V_105 ) {
F_376 ( V_35 -> V_37 , L_19 , V_7 ) ;
return - V_357 ;
}
if ( F_291 ( V_105 ) )
V_545 = false ;
if ( V_7 & V_295 && V_545 ) {
V_536 = & V_35 -> V_37 -> V_547 ;
if ( ! F_244 ( V_35 , V_548 ) )
V_538 = 64 * 1024 ;
}
if ( ( V_7 & V_296 ) && V_545 &&
F_244 ( V_35 , V_548 ) ) {
V_536 = & V_35 -> V_37 -> V_549 ;
}
if ( V_536 ) {
F_11 ( & V_536 -> V_52 ) ;
if ( V_536 -> V_14 )
V_535 = V_536 -> V_550 ;
F_13 ( & V_536 -> V_52 ) ;
}
V_488 = F_396 ( V_488 , V_26 ( V_35 , 0 ) ) ;
V_488 = F_396 ( V_488 , V_535 ) ;
if ( ! V_536 )
V_538 = 0 ;
if ( V_488 == V_535 ) {
V_14 = F_68 ( V_35 -> V_37 ,
V_488 ) ;
if ( V_14 && F_3 ( V_14 , V_7 ) &&
V_14 -> V_3 != V_94 ) {
F_36 ( & V_105 -> V_310 ) ;
if ( F_205 ( & V_14 -> V_90 ) ||
V_14 -> V_279 ) {
F_6 ( V_14 ) ;
F_45 ( & V_105 -> V_310 ) ;
} else {
V_540 = F_388 ( V_14 ) ;
F_390 ( V_14 , V_494 ) ;
goto V_551;
}
} else if ( V_14 ) {
F_6 ( V_14 ) ;
}
}
V_552:
V_546 = false ;
F_36 ( & V_105 -> V_310 ) ;
F_397 (block_group, &space_info->block_groups[index],
list) {
T_2 V_33 ;
int V_3 ;
F_391 ( V_14 , V_494 ) ;
V_488 = V_14 -> V_21 . V_22 ;
if ( ! F_3 ( V_14 , V_7 ) ) {
T_2 V_553 = V_301 |
V_302 |
V_343 |
V_344 |
V_303 ;
if ( ( V_7 & V_553 ) && ! ( V_14 -> V_7 & V_553 ) )
goto V_539;
}
V_551:
V_3 = F_1 ( V_14 ) ;
if ( F_318 ( ! V_3 ) ) {
V_29 = F_51 ( V_14 , 0 ) ;
F_30 ( V_29 < 0 ) ;
V_29 = 0 ;
}
if ( F_318 ( V_14 -> V_3 == V_5 ) )
goto V_539;
if ( F_318 ( V_14 -> V_279 ) )
goto V_539;
if ( V_536 ) {
struct V_1 * V_554 ;
unsigned long V_555 ;
V_554 = F_392 ( V_14 ,
V_536 ,
V_494 ) ;
if ( ! V_554 )
goto V_556;
if ( V_554 != V_14 &&
( V_554 -> V_279 ||
! F_3 ( V_554 , V_7 ) ) )
goto V_557;
V_33 = F_398 ( V_554 ,
V_536 ,
V_36 ,
V_554 -> V_21 . V_22 ,
& V_537 ) ;
if ( V_33 ) {
F_13 ( & V_536 -> V_532 ) ;
F_399 ( V_35 ,
V_554 ,
V_488 , V_36 ) ;
if ( V_554 != V_14 ) {
F_393 ( V_14 ,
V_494 ) ;
V_14 = V_554 ;
}
goto V_558;
}
F_8 ( V_536 -> V_14 != V_554 ) ;
V_557:
if ( V_539 >= V_559 &&
V_554 != V_14 ) {
F_13 ( & V_536 -> V_532 ) ;
F_393 ( V_554 ,
V_494 ) ;
goto V_560;
}
F_400 ( NULL , V_536 ) ;
if ( V_554 != V_14 )
F_393 ( V_554 ,
V_494 ) ;
V_556:
if ( V_539 >= V_559 ) {
F_13 ( & V_536 -> V_532 ) ;
goto V_560;
}
V_555 = F_34 (unsigned long,
empty_cluster + empty_size,
block_group->full_stripe_len) ;
V_29 = F_401 ( V_35 , V_14 ,
V_536 , V_488 ,
V_36 ,
V_555 ) ;
if ( V_29 == 0 ) {
V_33 = F_398 ( V_14 ,
V_536 ,
V_36 ,
V_488 ,
& V_537 ) ;
if ( V_33 ) {
F_13 ( & V_536 -> V_532 ) ;
F_399 ( V_35 ,
V_14 , V_488 ,
V_36 ) ;
goto V_558;
}
} else if ( ! V_3 && V_539 > V_561
&& ! V_543 ) {
F_13 ( & V_536 -> V_532 ) ;
V_543 = true ;
F_385 ( V_14 ,
V_36 + V_538 + V_534 ) ;
goto V_551;
}
F_400 ( NULL , V_536 ) ;
F_13 ( & V_536 -> V_532 ) ;
goto V_539;
}
V_560:
F_11 ( & V_14 -> V_11 -> V_562 ) ;
if ( V_3 &&
V_14 -> V_11 -> V_517 <
V_36 + V_538 + V_534 ) {
if ( V_14 -> V_11 -> V_517 >
V_537 )
V_537 =
V_14 -> V_11 -> V_517 ;
F_13 ( & V_14 -> V_11 -> V_562 ) ;
goto V_539;
}
F_13 ( & V_14 -> V_11 -> V_562 ) ;
V_33 = F_402 ( V_14 , V_488 ,
V_36 , V_534 ,
& V_537 ) ;
if ( ! V_33 && ! V_544 && ! V_3 &&
V_539 > V_561 ) {
F_385 ( V_14 ,
V_36 + V_534 ) ;
V_544 = true ;
goto V_551;
} else if ( ! V_33 ) {
if ( ! V_3 )
V_546 = true ;
goto V_539;
}
V_558:
V_488 = F_274 ( V_33 , V_35 -> V_563 ) ;
if ( V_488 + V_36 >
V_14 -> V_21 . V_22 + V_14 -> V_21 . V_33 ) {
F_29 ( V_14 , V_33 , V_36 ) ;
goto V_539;
}
if ( V_33 < V_488 )
F_29 ( V_14 , V_33 ,
V_488 - V_33 ) ;
F_30 ( V_33 > V_488 ) ;
V_29 = F_369 ( V_14 , V_36 ,
V_541 , V_494 ) ;
if ( V_29 == - V_178 ) {
F_29 ( V_14 , V_33 , V_36 ) ;
goto V_539;
}
V_212 -> V_22 = V_488 ;
V_212 -> V_33 = V_36 ;
F_403 ( V_533 , V_14 ,
V_488 , V_36 ) ;
F_393 ( V_14 , V_494 ) ;
break;
V_539:
V_543 = false ;
V_544 = false ;
F_30 ( V_540 != F_388 ( V_14 ) ) ;
F_393 ( V_14 , V_494 ) ;
}
F_45 ( & V_105 -> V_310 ) ;
if ( ! V_212 -> V_22 && V_539 >= V_564 && V_546 )
goto V_552;
if ( ! V_212 -> V_22 && ++ V_540 < V_308 )
goto V_552;
if ( ! V_212 -> V_22 && V_539 < V_559 ) {
V_540 = 0 ;
V_539 ++ ;
if ( V_539 == V_565 ) {
struct V_109 * V_110 ;
int V_566 = 0 ;
V_110 = V_352 -> V_353 ;
if ( V_110 )
V_566 = 1 ;
else
V_110 = F_194 ( V_35 ) ;
if ( F_195 ( V_110 ) ) {
V_29 = F_196 ( V_110 ) ;
goto V_72;
}
V_29 = F_276 ( V_110 , V_35 , V_7 ,
V_356 ) ;
if ( V_29 < 0 && V_29 != - V_357 )
F_151 ( V_110 ,
V_35 , V_29 ) ;
else
V_29 = 0 ;
if ( ! V_566 )
F_198 ( V_110 , V_35 ) ;
if ( V_29 )
goto V_72;
}
if ( V_539 == V_559 ) {
V_534 = 0 ;
V_538 = 0 ;
}
goto V_552;
} else if ( ! V_212 -> V_22 ) {
V_29 = - V_357 ;
} else if ( V_212 -> V_22 ) {
V_29 = 0 ;
}
V_72:
if ( V_29 == - V_357 )
V_212 -> V_33 = V_537 ;
return V_29 ;
}
static void F_289 ( struct V_102 * V_13 , T_2 V_347 ,
int V_567 )
{
struct V_1 * V_2 ;
int V_540 = 0 ;
F_11 ( & V_13 -> V_52 ) ;
F_404 ( V_568 L_20 ,
V_13 -> V_7 ,
V_13 -> V_298 - V_13 -> V_299 - V_13 -> V_311 -
V_13 -> V_312 - V_13 -> V_313 ,
( V_13 -> V_108 ) ? L_21 : L_22 ) ;
F_404 ( V_568 L_23
L_24 ,
V_13 -> V_298 , V_13 -> V_299 , V_13 -> V_311 ,
V_13 -> V_312 , V_13 -> V_314 ,
V_13 -> V_313 ) ;
F_13 ( & V_13 -> V_52 ) ;
if ( ! V_567 )
return;
F_36 ( & V_13 -> V_310 ) ;
V_77:
F_397 (cache, &info->block_groups[index], list) {
F_11 ( & V_2 -> V_52 ) ;
F_404 ( V_568 L_25
L_26
L_27 ,
V_2 -> V_21 . V_22 , V_2 -> V_21 . V_33 ,
F_360 ( & V_2 -> V_135 ) , V_2 -> V_9 ,
V_2 -> V_10 , V_2 -> V_279 ? L_28 : L_21 ) ;
F_405 ( V_2 , V_347 ) ;
F_13 ( & V_2 -> V_52 ) ;
}
if ( ++ V_540 < V_308 )
goto V_77;
F_45 ( & V_13 -> V_310 ) ;
}
int F_406 ( struct V_34 * V_35 ,
T_2 V_36 , T_2 V_569 ,
T_2 V_534 , T_2 V_535 ,
struct V_67 * V_212 , int V_184 , int V_494 )
{
bool V_570 = false ;
T_2 V_7 ;
int V_29 ;
V_7 = F_273 ( V_35 , V_184 ) ;
V_77:
F_8 ( V_36 < V_35 -> V_351 ) ;
V_29 = F_394 ( V_35 , V_36 , V_534 , V_535 , V_212 ,
V_7 , V_494 ) ;
if ( V_29 == - V_357 ) {
if ( ! V_570 && V_212 -> V_33 ) {
V_36 = F_301 ( V_36 >> 1 , V_212 -> V_33 ) ;
V_36 = F_407 ( V_36 , V_35 -> V_351 ) ;
V_36 = F_396 ( V_36 , V_569 ) ;
if ( V_36 == V_569 )
V_570 = true ;
goto V_77;
} else if ( F_244 ( V_35 , V_369 ) ) {
struct V_102 * V_361 ;
V_361 = F_69 ( V_35 -> V_37 , V_7 ) ;
F_376 ( V_35 -> V_37 , L_29 ,
V_7 , V_36 ) ;
if ( V_361 )
F_289 ( V_361 , V_36 , 1 ) ;
}
}
return V_29 ;
}
static int F_408 ( struct V_34 * V_35 ,
T_2 V_32 , T_2 V_49 ,
int V_512 , int V_494 )
{
struct V_1 * V_2 ;
int V_29 = 0 ;
V_2 = F_68 ( V_35 -> V_37 , V_32 ) ;
if ( ! V_2 ) {
F_376 ( V_35 -> V_37 , L_30 ,
V_32 ) ;
return - V_357 ;
}
if ( F_244 ( V_35 , V_501 ) )
V_29 = F_142 ( V_35 , V_32 , V_49 , NULL ) ;
if ( V_512 )
F_363 ( V_35 , V_2 , V_32 , V_49 , 1 ) ;
else {
F_29 ( V_2 , V_32 , V_49 ) ;
F_369 ( V_2 , V_49 , V_495 , V_494 ) ;
}
F_6 ( V_2 ) ;
F_364 ( V_35 , V_32 , V_49 ) ;
return V_29 ;
}
int F_409 ( struct V_34 * V_35 ,
T_2 V_32 , T_2 V_49 , int V_494 )
{
return F_408 ( V_35 , V_32 , V_49 , 0 , V_494 ) ;
}
int F_410 ( struct V_34 * V_35 ,
T_2 V_32 , T_2 V_49 )
{
return F_408 ( V_35 , V_32 , V_49 , 1 , 0 ) ;
}
static int F_155 ( struct V_109 * V_110 ,
struct V_34 * V_35 ,
T_2 V_17 , T_2 V_146 ,
T_2 V_7 , T_2 V_133 , T_2 V_33 ,
struct V_67 * V_212 , int V_132 )
{
int V_29 ;
struct V_12 * V_37 = V_35 -> V_37 ;
struct V_116 * V_571 ;
struct V_163 * V_164 ;
struct V_63 * V_64 ;
struct V_65 * V_66 ;
int type ;
T_3 V_56 ;
if ( V_17 > 0 )
type = V_154 ;
else
type = V_155 ;
V_56 = sizeof( * V_571 ) + F_125 ( type ) ;
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
V_571 = F_78 ( V_66 , V_64 -> V_83 [ 0 ] ,
struct V_116 ) ;
F_90 ( V_66 , V_571 , V_132 ) ;
F_91 ( V_66 , V_571 , V_110 -> V_281 ) ;
F_92 ( V_66 , V_571 ,
V_7 | V_145 ) ;
V_164 = (struct V_163 * ) ( V_571 + 1 ) ;
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
V_29 = F_150 ( V_110 , V_37 , V_146 ,
V_212 -> V_22 , V_212 -> V_33 ,
V_205 , 0 ) ;
if ( V_29 )
return V_29 ;
V_29 = F_357 ( V_110 , V_35 , V_212 -> V_22 , V_212 -> V_33 , 1 ) ;
if ( V_29 ) {
F_376 ( V_37 , L_31 ,
V_212 -> V_22 , V_212 -> V_33 ) ;
F_83 () ;
}
F_411 ( V_35 , V_212 -> V_22 , V_212 -> V_33 ) ;
return V_29 ;
}
static int F_162 ( struct V_109 * V_110 ,
struct V_34 * V_35 ,
T_2 V_17 , T_2 V_146 ,
T_2 V_7 , struct V_469 * V_21 ,
int V_167 , struct V_67 * V_212 ,
int V_201 )
{
int V_29 ;
struct V_12 * V_37 = V_35 -> V_37 ;
struct V_116 * V_571 ;
struct V_138 * V_572 ;
struct V_163 * V_164 ;
struct V_63 * V_64 ;
struct V_65 * V_66 ;
T_3 V_56 = sizeof( * V_571 ) + sizeof( * V_164 ) ;
T_2 V_36 = V_212 -> V_33 ;
bool V_173 = F_76 ( V_35 -> V_37 ,
V_121 ) ;
if ( ! V_173 )
V_56 += sizeof( * V_572 ) ;
V_64 = F_33 () ;
if ( ! V_64 ) {
F_410 ( V_35 , V_212 -> V_22 ,
V_35 -> V_87 ) ;
return - V_71 ;
}
V_64 -> V_207 = 1 ;
V_29 = F_106 ( V_110 , V_37 -> V_62 , V_64 ,
V_212 , V_56 ) ;
if ( V_29 ) {
F_410 ( V_35 , V_212 -> V_22 ,
V_35 -> V_87 ) ;
F_50 ( V_64 ) ;
return V_29 ;
}
V_66 = V_64 -> V_82 [ 0 ] ;
V_571 = F_78 ( V_66 , V_64 -> V_83 [ 0 ] ,
struct V_116 ) ;
F_90 ( V_66 , V_571 , 1 ) ;
F_91 ( V_66 , V_571 , V_110 -> V_281 ) ;
F_92 ( V_66 , V_571 ,
V_7 | V_144 ) ;
if ( V_173 ) {
V_164 = (struct V_163 * ) ( V_571 + 1 ) ;
V_36 = V_35 -> V_87 ;
} else {
V_572 = (struct V_138 * ) ( V_571 + 1 ) ;
F_157 ( V_66 , V_572 , V_21 ) ;
F_94 ( V_66 , V_572 , V_167 ) ;
V_164 = (struct V_163 * ) ( V_572 + 1 ) ;
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
V_29 = F_150 ( V_110 , V_37 , V_146 ,
V_212 -> V_22 , V_36 ,
V_205 , 0 ) ;
if ( V_29 )
return V_29 ;
}
V_29 = F_357 ( V_110 , V_35 , V_212 -> V_22 , V_35 -> V_87 ,
1 ) ;
if ( V_29 ) {
F_376 ( V_37 , L_31 ,
V_212 -> V_22 , V_212 -> V_33 ) ;
F_83 () ;
}
F_411 ( V_35 , V_212 -> V_22 , V_35 -> V_87 ) ;
return V_29 ;
}
int F_412 ( struct V_109 * V_110 ,
struct V_34 * V_35 ,
T_2 V_146 , T_2 V_133 ,
T_2 V_33 , struct V_67 * V_212 )
{
int V_29 ;
F_30 ( V_146 == V_202 ) ;
V_29 = F_147 ( V_35 -> V_37 , V_110 , V_212 -> V_22 ,
V_212 -> V_33 , 0 ,
V_146 , V_133 , V_33 ,
V_230 , NULL , 0 ) ;
return V_29 ;
}
int F_413 ( struct V_109 * V_110 ,
struct V_34 * V_35 ,
T_2 V_146 , T_2 V_133 , T_2 V_33 ,
struct V_67 * V_212 )
{
int V_29 ;
struct V_1 * V_14 ;
if ( ! F_76 ( V_35 -> V_37 , V_493 ) ) {
V_29 = F_367 ( V_35 , V_212 -> V_22 , V_212 -> V_33 ) ;
if ( V_29 )
return V_29 ;
}
V_14 = F_68 ( V_35 -> V_37 , V_212 -> V_22 ) ;
if ( ! V_14 )
return - V_489 ;
V_29 = F_369 ( V_14 , V_212 -> V_33 ,
V_542 , 0 ) ;
F_30 ( V_29 ) ;
V_29 = F_155 ( V_110 , V_35 , 0 , V_146 ,
0 , V_133 , V_33 , V_212 , 1 ) ;
F_6 ( V_14 ) ;
return V_29 ;
}
static struct V_65 *
F_414 ( struct V_109 * V_110 , struct V_34 * V_35 ,
T_2 V_27 , int V_167 )
{
struct V_65 * V_260 ;
V_260 = F_415 ( V_35 , V_27 ) ;
if ( ! V_260 )
return F_416 ( - V_71 ) ;
F_417 ( V_260 , V_110 -> V_281 ) ;
F_418 ( V_35 -> V_256 . V_22 , V_260 , V_167 ) ;
F_419 ( V_260 ) ;
F_420 ( V_110 , V_35 , V_260 ) ;
F_384 ( V_573 , & V_260 -> V_515 ) ;
F_421 ( V_260 ) ;
F_422 ( V_260 ) ;
if ( V_35 -> V_256 . V_22 == V_202 ) {
V_260 -> V_574 = V_35 -> V_575 % 2 ;
if ( V_260 -> V_574 == 0 )
F_362 ( & V_35 -> V_576 , V_260 -> V_32 ,
V_260 -> V_32 + V_260 -> V_49 - 1 , V_40 ) ;
else
F_423 ( & V_35 -> V_576 , V_260 -> V_32 ,
V_260 -> V_32 + V_260 -> V_49 - 1 , V_40 ) ;
} else {
V_260 -> V_574 = - 1 ;
F_362 ( & V_110 -> V_127 -> V_577 , V_260 -> V_32 ,
V_260 -> V_32 + V_260 -> V_49 - 1 , V_40 ) ;
}
V_110 -> V_578 ++ ;
return V_260 ;
}
static struct V_240 *
F_424 ( struct V_109 * V_110 ,
struct V_34 * V_35 , T_3 V_579 )
{
struct V_240 * V_391 ;
struct V_240 * V_241 = & V_35 -> V_37 -> V_242 ;
int V_29 ;
bool V_580 = false ;
V_391 = F_321 ( V_110 , V_35 ) ;
if ( F_318 ( V_391 -> V_56 == 0 ) )
goto V_581;
V_77:
V_29 = F_319 ( V_391 , V_579 ) ;
if ( ! V_29 )
return V_391 ;
if ( V_391 -> V_582 )
return F_416 ( V_29 ) ;
if ( V_391 -> type == V_583 && ! V_580 ) {
V_580 = true ;
F_336 ( V_35 -> V_37 ) ;
goto V_77;
}
if ( F_244 ( V_35 , V_369 ) ) {
static F_425 ( V_584 ,
V_585 * 10 ,
1 ) ;
if ( F_426 ( & V_584 ) )
F_427 ( 1 , V_586
L_32 , V_29 ) ;
}
V_581:
V_29 = F_315 ( V_35 , V_391 , V_579 ,
V_402 ) ;
if ( ! V_29 )
return V_391 ;
if ( V_391 -> type != V_583 &&
V_391 -> V_105 == V_241 -> V_105 ) {
V_29 = F_319 ( V_241 , V_579 ) ;
if ( ! V_29 )
return V_241 ;
}
return F_416 ( V_29 ) ;
}
static void F_428 ( struct V_12 * V_37 ,
struct V_240 * V_391 , T_3 V_579 )
{
F_322 ( V_391 , V_579 , 0 ) ;
F_324 ( V_37 , V_391 , NULL , 0 ) ;
}
struct V_65 * F_429 ( struct V_109 * V_110 ,
struct V_34 * V_35 ,
T_2 V_17 , T_2 V_146 ,
struct V_469 * V_21 , int V_167 ,
T_2 V_587 , T_2 V_534 )
{
struct V_67 V_212 ;
struct V_240 * V_391 ;
struct V_65 * V_260 ;
T_2 V_7 = 0 ;
int V_29 ;
T_3 V_579 = V_35 -> V_87 ;
bool V_173 = F_76 ( V_35 -> V_37 ,
V_121 ) ;
if ( F_220 ( V_35 ) ) {
V_260 = F_414 ( V_110 , V_35 , V_35 -> V_588 ,
V_167 ) ;
if ( ! F_195 ( V_260 ) )
V_35 -> V_588 += V_579 ;
return V_260 ;
}
V_391 = F_424 ( V_110 , V_35 , V_579 ) ;
if ( F_195 ( V_391 ) )
return F_430 ( V_391 ) ;
V_29 = F_406 ( V_35 , V_579 , V_579 ,
V_534 , V_587 , & V_212 , 0 , 0 ) ;
if ( V_29 ) {
F_428 ( V_35 -> V_37 , V_391 , V_579 ) ;
return F_416 ( V_29 ) ;
}
V_260 = F_414 ( V_110 , V_35 , V_212 . V_22 , V_167 ) ;
F_30 ( F_195 ( V_260 ) ) ;
if ( V_146 == V_589 ) {
if ( V_17 == 0 )
V_17 = V_212 . V_22 ;
V_7 |= V_126 ;
} else
F_30 ( V_17 > 0 ) ;
if ( V_146 != V_202 ) {
struct V_180 * V_129 ;
V_129 = F_211 () ;
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
V_29 = F_146 ( V_35 -> V_37 , V_110 ,
V_212 . V_22 ,
V_212 . V_33 , V_17 , V_146 ,
V_167 , V_230 ,
V_129 , 0 ) ;
F_30 ( V_29 ) ;
}
return V_260 ;
}
static T_1 void F_431 ( struct V_109 * V_110 ,
struct V_34 * V_35 ,
struct V_590 * V_591 ,
struct V_63 * V_64 )
{
T_2 V_27 ;
T_2 V_284 ;
T_2 V_112 ;
T_2 V_7 ;
T_3 V_70 ;
T_3 V_579 ;
struct V_67 V_21 ;
struct V_65 * V_491 ;
int V_29 ;
int V_592 ;
int V_593 = 0 ;
if ( V_64 -> V_83 [ V_591 -> V_167 ] < V_591 -> V_594 ) {
V_591 -> V_595 = V_591 -> V_595 * 2 / 3 ;
V_591 -> V_595 = F_396 ( V_591 -> V_595 , 2 ) ;
} else {
V_591 -> V_595 = V_591 -> V_595 * 3 / 2 ;
V_591 -> V_595 = F_24 ( int , V_591 -> V_595 ,
F_432 ( V_35 ) ) ;
}
V_491 = V_64 -> V_82 [ V_591 -> V_167 ] ;
V_70 = F_38 ( V_491 ) ;
V_579 = V_35 -> V_87 ;
for ( V_592 = V_64 -> V_83 [ V_591 -> V_167 ] ; V_592 < V_70 ; V_592 ++ ) {
if ( V_593 >= V_591 -> V_595 )
break;
F_47 () ;
V_27 = F_228 ( V_491 , V_592 ) ;
V_284 = F_433 ( V_491 , V_592 ) ;
if ( V_592 == V_64 -> V_83 [ V_591 -> V_167 ] )
goto V_75;
if ( V_591 -> V_596 == V_597 &&
V_284 <= V_35 -> V_256 . V_33 )
continue;
V_29 = F_75 ( V_110 , V_35 , V_27 ,
V_591 -> V_167 - 1 , 1 , & V_112 ,
& V_7 ) ;
if ( V_29 < 0 )
continue;
F_30 ( V_112 == 0 ) ;
if ( V_591 -> V_596 == V_598 ) {
if ( V_112 == 1 )
goto V_75;
if ( V_591 -> V_167 == 1 &&
( V_7 & V_126 ) )
continue;
if ( ! V_591 -> V_599 ||
V_284 <= V_35 -> V_256 . V_33 )
continue;
F_123 ( V_491 , & V_21 , V_592 ) ;
V_29 = F_434 ( & V_21 ,
& V_591 -> V_600 ) ;
if ( V_29 < 0 )
continue;
} else {
if ( V_591 -> V_167 == 1 &&
( V_7 & V_126 ) )
continue;
}
V_75:
F_435 ( V_35 , V_27 ) ;
V_593 ++ ;
}
V_591 -> V_594 = V_592 ;
}
static int F_436 ( struct V_109 * V_110 ,
struct V_34 * V_35 ,
struct V_65 * V_491 )
{
int V_44 = F_38 ( V_491 ) ;
int V_43 , V_601 , V_29 ;
struct V_67 V_21 ;
struct V_263 * V_264 ;
T_2 V_27 , V_36 ;
for ( V_43 = 0 ; V_43 < V_44 ; V_43 ++ ) {
F_40 ( V_491 , & V_21 , V_43 ) ;
if ( V_21 . type != V_268 )
continue;
V_264 = F_78 ( V_491 , V_43 , struct V_263 ) ;
V_601 = F_224 ( V_491 , V_264 ) ;
if ( V_601 == V_269 )
continue;
V_27 = F_225 ( V_491 , V_264 ) ;
if ( ! V_27 )
continue;
V_36 = F_226 ( V_491 , V_264 ) ;
V_29 = F_150 ( V_110 , V_35 -> V_37 ,
V_35 -> V_22 ,
V_27 , V_36 ,
V_602 , 0 ) ;
if ( V_29 )
return V_29 ;
}
return 0 ;
}
static int F_437 ( struct V_34 * V_35 ,
struct V_63 * V_64 , int V_603 )
{
int V_167 = 0 ;
int V_44 , V_592 ;
struct V_65 * V_491 ;
if ( V_603 == 0 )
return 1 ;
while ( V_167 <= V_603 ) {
V_491 = V_64 -> V_82 [ V_167 ] ;
V_44 = F_38 ( V_491 ) ;
V_64 -> V_83 [ V_167 ] ++ ;
V_592 = V_64 -> V_83 [ V_167 ] ;
if ( V_592 >= V_44 || V_167 == 0 ) {
if ( V_167 != V_603 ) {
F_438 ( V_491 , V_64 -> V_604 [ V_167 ] ) ;
V_64 -> V_604 [ V_167 ] = 0 ;
F_439 ( V_491 ) ;
V_64 -> V_82 [ V_167 ] = NULL ;
V_64 -> V_83 [ V_167 ] = 0 ;
}
} else {
break;
}
V_167 ++ ;
}
V_491 = V_64 -> V_82 [ V_603 ] ;
if ( V_64 -> V_83 [ V_603 ] >= F_38 ( V_491 ) )
return 1 ;
return 0 ;
}
static int F_440 ( struct V_109 * V_110 ,
struct V_34 * V_35 ,
struct V_65 * V_605 ,
T_2 V_606 ,
int V_603 )
{
int V_29 = 0 ;
int V_167 ;
struct V_65 * V_491 = V_605 ;
struct V_63 * V_64 = NULL ;
F_30 ( V_603 < 0 || V_603 > V_168 ) ;
F_30 ( V_605 == NULL ) ;
if ( ! V_35 -> V_37 -> V_206 )
return 0 ;
if ( ! F_441 ( V_605 ) ) {
V_29 = F_442 ( V_605 , V_606 ) ;
if ( V_29 )
goto V_72;
}
if ( V_603 == 0 ) {
V_29 = F_436 ( V_110 , V_35 , V_605 ) ;
goto V_72;
}
V_64 = F_33 () ;
if ( ! V_64 )
return - V_71 ;
F_443 ( V_605 ) ;
V_64 -> V_82 [ V_603 ] = V_605 ;
V_64 -> V_83 [ V_603 ] = 0 ;
V_64 -> V_604 [ V_603 ] = 0 ;
V_607:
V_167 = V_603 ;
while ( V_167 >= 0 ) {
if ( V_64 -> V_82 [ V_167 ] == NULL ) {
int V_608 ;
T_2 V_609 ;
T_2 V_610 ;
V_491 = V_64 -> V_82 [ V_167 + 1 ] ;
V_608 = V_64 -> V_83 [ V_167 + 1 ] ;
V_610 = F_228 ( V_491 , V_608 ) ;
V_609 = F_433 ( V_491 , V_608 ) ;
V_491 = F_444 ( V_35 , V_610 , V_609 ) ;
if ( ! V_491 || ! F_441 ( V_491 ) ) {
V_29 = - V_175 ;
goto V_72;
}
V_64 -> V_82 [ V_167 ] = V_491 ;
V_64 -> V_83 [ V_167 ] = 0 ;
F_445 ( V_491 ) ;
F_446 ( V_491 , V_611 ) ;
V_64 -> V_604 [ V_167 ] = V_612 ;
V_29 = F_150 ( V_110 , V_35 -> V_37 ,
V_35 -> V_22 ,
V_610 ,
V_35 -> V_87 ,
V_602 ,
0 ) ;
if ( V_29 )
goto V_72;
}
if ( V_167 == 0 ) {
V_29 = F_436 ( V_110 , V_35 , V_64 -> V_82 [ V_167 ] ) ;
if ( V_29 )
goto V_72;
V_29 = F_437 ( V_35 , V_64 , V_603 ) ;
if ( V_29 )
break;
goto V_607;
}
V_167 -- ;
}
V_29 = 0 ;
V_72:
F_50 ( V_64 ) ;
return V_29 ;
}
static T_1 int F_447 ( struct V_109 * V_110 ,
struct V_34 * V_35 ,
struct V_63 * V_64 ,
struct V_590 * V_591 , int V_613 )
{
int V_167 = V_591 -> V_167 ;
struct V_65 * V_491 = V_64 -> V_82 [ V_167 ] ;
T_2 V_614 = V_126 ;
int V_29 ;
if ( V_591 -> V_596 == V_597 &&
F_221 ( V_491 ) != V_35 -> V_256 . V_22 )
return 1 ;
if ( V_613 &&
( ( V_591 -> V_596 == V_598 && V_591 -> V_112 [ V_167 ] != 1 ) ||
( V_591 -> V_596 == V_597 && ! ( V_591 -> V_7 [ V_167 ] & V_614 ) ) ) ) {
F_30 ( ! V_64 -> V_604 [ V_167 ] ) ;
V_29 = F_75 ( V_110 , V_35 ,
V_491 -> V_32 , V_167 , 1 ,
& V_591 -> V_112 [ V_167 ] ,
& V_591 -> V_7 [ V_167 ] ) ;
F_30 ( V_29 == - V_71 ) ;
if ( V_29 )
return V_29 ;
F_30 ( V_591 -> V_112 [ V_167 ] == 0 ) ;
}
if ( V_591 -> V_596 == V_598 ) {
if ( V_591 -> V_112 [ V_167 ] > 1 )
return 1 ;
if ( V_64 -> V_604 [ V_167 ] && ! V_591 -> V_174 ) {
F_438 ( V_491 , V_64 -> V_604 [ V_167 ] ) ;
V_64 -> V_604 [ V_167 ] = 0 ;
}
return 0 ;
}
if ( ! ( V_591 -> V_7 [ V_167 ] & V_614 ) ) {
F_30 ( ! V_64 -> V_604 [ V_167 ] ) ;
V_29 = F_229 ( V_110 , V_35 , V_491 , 1 ) ;
F_30 ( V_29 ) ;
V_29 = F_230 ( V_110 , V_35 , V_491 , 0 ) ;
F_30 ( V_29 ) ;
V_29 = F_210 ( V_110 , V_35 , V_491 -> V_32 ,
V_491 -> V_49 , V_614 ,
F_222 ( V_491 ) , 0 ) ;
F_30 ( V_29 ) ;
V_591 -> V_7 [ V_167 ] |= V_614 ;
}
if ( V_64 -> V_604 [ V_167 ] && V_167 > 0 ) {
F_438 ( V_491 , V_64 -> V_604 [ V_167 ] ) ;
V_64 -> V_604 [ V_167 ] = 0 ;
}
return 0 ;
}
static T_1 int F_448 ( struct V_109 * V_110 ,
struct V_34 * V_35 ,
struct V_63 * V_64 ,
struct V_590 * V_591 , int * V_613 )
{
T_2 V_27 ;
T_2 V_284 ;
T_2 V_17 ;
T_3 V_579 ;
struct V_67 V_21 ;
struct V_65 * V_80 ;
int V_167 = V_591 -> V_167 ;
int V_75 = 0 ;
int V_29 = 0 ;
bool V_615 = false ;
V_284 = F_433 ( V_64 -> V_82 [ V_167 ] ,
V_64 -> V_83 [ V_167 ] ) ;
if ( V_591 -> V_596 == V_597 &&
V_284 <= V_35 -> V_256 . V_33 ) {
* V_613 = 1 ;
return 1 ;
}
V_27 = F_228 ( V_64 -> V_82 [ V_167 ] , V_64 -> V_83 [ V_167 ] ) ;
V_579 = V_35 -> V_87 ;
V_80 = F_449 ( V_35 , V_27 ) ;
if ( ! V_80 ) {
V_80 = F_415 ( V_35 , V_27 ) ;
if ( ! V_80 )
return - V_71 ;
F_418 ( V_35 -> V_256 . V_22 , V_80 ,
V_167 - 1 ) ;
V_75 = 1 ;
}
F_419 ( V_80 ) ;
F_421 ( V_80 ) ;
V_29 = F_75 ( V_110 , V_35 , V_27 , V_167 - 1 , 1 ,
& V_591 -> V_112 [ V_167 - 1 ] ,
& V_591 -> V_7 [ V_167 - 1 ] ) ;
if ( V_29 < 0 ) {
F_450 ( V_80 ) ;
return V_29 ;
}
if ( F_318 ( V_591 -> V_112 [ V_167 - 1 ] == 0 ) ) {
F_376 ( V_35 -> V_37 , L_33 ) ;
F_83 () ;
}
* V_613 = 0 ;
if ( V_591 -> V_596 == V_598 ) {
if ( V_591 -> V_112 [ V_167 - 1 ] > 1 ) {
V_615 = true ;
if ( V_167 == 1 &&
( V_591 -> V_7 [ 0 ] & V_126 ) )
goto V_616;
if ( ! V_591 -> V_599 ||
V_284 <= V_35 -> V_256 . V_33 )
goto V_616;
F_123 ( V_64 -> V_82 [ V_167 ] , & V_21 ,
V_64 -> V_83 [ V_167 ] ) ;
V_29 = F_434 ( & V_21 , & V_591 -> V_600 ) ;
if ( V_29 < 0 )
goto V_616;
V_591 -> V_596 = V_597 ;
V_591 -> V_617 = V_167 - 1 ;
}
} else {
if ( V_167 == 1 &&
( V_591 -> V_7 [ 0 ] & V_126 ) )
goto V_616;
}
if ( ! F_451 ( V_80 , V_284 , 0 ) ) {
F_450 ( V_80 ) ;
F_439 ( V_80 ) ;
V_80 = NULL ;
* V_613 = 1 ;
}
if ( ! V_80 ) {
if ( V_75 && V_167 == 1 )
F_431 ( V_110 , V_35 , V_591 , V_64 ) ;
V_80 = F_444 ( V_35 , V_27 , V_284 ) ;
if ( ! V_80 || ! F_441 ( V_80 ) ) {
F_439 ( V_80 ) ;
return - V_175 ;
}
F_419 ( V_80 ) ;
F_421 ( V_80 ) ;
}
V_167 -- ;
F_30 ( V_167 != F_222 ( V_80 ) ) ;
V_64 -> V_82 [ V_167 ] = V_80 ;
V_64 -> V_83 [ V_167 ] = 0 ;
V_64 -> V_604 [ V_167 ] = V_618 ;
V_591 -> V_167 = V_167 ;
if ( V_591 -> V_167 == 1 )
V_591 -> V_594 = 0 ;
return 0 ;
V_616:
V_591 -> V_112 [ V_167 - 1 ] = 0 ;
V_591 -> V_7 [ V_167 - 1 ] = 0 ;
if ( V_591 -> V_596 == V_598 ) {
if ( V_591 -> V_7 [ V_167 ] & V_126 ) {
V_17 = V_64 -> V_82 [ V_167 ] -> V_32 ;
} else {
F_30 ( V_35 -> V_256 . V_22 !=
F_221 ( V_64 -> V_82 [ V_167 ] ) ) ;
V_17 = 0 ;
}
if ( V_615 ) {
V_29 = F_440 ( V_110 , V_35 , V_80 ,
V_284 , V_167 - 1 ) ;
if ( V_29 ) {
F_452 ( V_619 L_34
L_35
L_36 ,
V_35 -> V_37 -> V_385 -> V_620 , V_29 ) ;
}
}
V_29 = V_267 ( V_110 , V_35 , V_27 , V_579 , V_17 ,
V_35 -> V_256 . V_22 , V_167 - 1 , 0 , 0 ) ;
F_30 ( V_29 ) ;
}
F_450 ( V_80 ) ;
F_439 ( V_80 ) ;
* V_613 = 1 ;
return 1 ;
}
static T_1 int F_453 ( struct V_109 * V_110 ,
struct V_34 * V_35 ,
struct V_63 * V_64 ,
struct V_590 * V_591 )
{
int V_29 ;
int V_167 = V_591 -> V_167 ;
struct V_65 * V_491 = V_64 -> V_82 [ V_167 ] ;
T_2 V_17 = 0 ;
if ( V_591 -> V_596 == V_597 ) {
F_30 ( V_591 -> V_617 < V_167 ) ;
if ( V_167 < V_591 -> V_617 )
goto V_72;
V_29 = F_41 ( V_64 , V_167 + 1 , & V_591 -> V_600 ) ;
if ( V_29 > 0 )
V_591 -> V_599 = 0 ;
V_591 -> V_596 = V_598 ;
V_591 -> V_617 = - 1 ;
V_64 -> V_83 [ V_167 ] = 0 ;
if ( ! V_64 -> V_604 [ V_167 ] ) {
F_30 ( V_167 == 0 ) ;
F_419 ( V_491 ) ;
F_421 ( V_491 ) ;
V_64 -> V_604 [ V_167 ] = V_618 ;
V_29 = F_75 ( V_110 , V_35 ,
V_491 -> V_32 , V_167 , 1 ,
& V_591 -> V_112 [ V_167 ] ,
& V_591 -> V_7 [ V_167 ] ) ;
if ( V_29 < 0 ) {
F_438 ( V_491 , V_64 -> V_604 [ V_167 ] ) ;
V_64 -> V_604 [ V_167 ] = 0 ;
return V_29 ;
}
F_30 ( V_591 -> V_112 [ V_167 ] == 0 ) ;
if ( V_591 -> V_112 [ V_167 ] == 1 ) {
F_438 ( V_491 , V_64 -> V_604 [ V_167 ] ) ;
V_64 -> V_604 [ V_167 ] = 0 ;
return 1 ;
}
}
}
F_30 ( V_591 -> V_112 [ V_167 ] > 1 && ! V_64 -> V_604 [ V_167 ] ) ;
if ( V_591 -> V_112 [ V_167 ] == 1 ) {
if ( V_167 == 0 ) {
if ( V_591 -> V_7 [ V_167 ] & V_126 )
V_29 = F_230 ( V_110 , V_35 , V_491 , 1 ) ;
else
V_29 = F_230 ( V_110 , V_35 , V_491 , 0 ) ;
F_30 ( V_29 ) ;
V_29 = F_436 ( V_110 , V_35 , V_491 ) ;
if ( V_29 ) {
F_452 ( V_619 L_34
L_37
L_36 ,
V_35 -> V_37 -> V_385 -> V_620 , V_29 ) ;
}
}
if ( ! V_64 -> V_604 [ V_167 ] &&
F_382 ( V_491 ) == V_110 -> V_281 ) {
F_419 ( V_491 ) ;
F_421 ( V_491 ) ;
V_64 -> V_604 [ V_167 ] = V_618 ;
}
F_420 ( V_110 , V_35 , V_491 ) ;
}
if ( V_491 == V_35 -> V_128 ) {
if ( V_591 -> V_7 [ V_167 ] & V_126 )
V_17 = V_491 -> V_32 ;
else
F_30 ( V_35 -> V_256 . V_22 !=
F_221 ( V_491 ) ) ;
} else {
if ( V_591 -> V_7 [ V_167 + 1 ] & V_126 )
V_17 = V_64 -> V_82 [ V_167 + 1 ] -> V_32 ;
else
F_30 ( V_35 -> V_256 . V_22 !=
F_221 ( V_64 -> V_82 [ V_167 + 1 ] ) ) ;
}
F_381 ( V_110 , V_35 , V_491 , V_17 , V_591 -> V_112 [ V_167 ] == 1 ) ;
V_72:
V_591 -> V_112 [ V_167 ] = 0 ;
V_591 -> V_7 [ V_167 ] = 0 ;
return 0 ;
}
static T_1 int F_454 ( struct V_109 * V_110 ,
struct V_34 * V_35 ,
struct V_63 * V_64 ,
struct V_590 * V_591 )
{
int V_167 = V_591 -> V_167 ;
int V_613 = 1 ;
int V_29 ;
while ( V_167 >= 0 ) {
V_29 = F_447 ( V_110 , V_35 , V_64 , V_591 , V_613 ) ;
if ( V_29 > 0 )
break;
if ( V_167 == 0 )
break;
if ( V_64 -> V_83 [ V_167 ] >=
F_38 ( V_64 -> V_82 [ V_167 ] ) )
break;
V_29 = F_448 ( V_110 , V_35 , V_64 , V_591 , & V_613 ) ;
if ( V_29 > 0 ) {
V_64 -> V_83 [ V_167 ] ++ ;
continue;
} else if ( V_29 < 0 )
return V_29 ;
V_167 = V_591 -> V_167 ;
}
return 0 ;
}
static T_1 int F_455 ( struct V_109 * V_110 ,
struct V_34 * V_35 ,
struct V_63 * V_64 ,
struct V_590 * V_591 , int V_621 )
{
int V_167 = V_591 -> V_167 ;
int V_29 ;
V_64 -> V_83 [ V_167 ] = F_38 ( V_64 -> V_82 [ V_167 ] ) ;
while ( V_167 < V_621 && V_64 -> V_82 [ V_167 ] ) {
V_591 -> V_167 = V_167 ;
if ( V_64 -> V_83 [ V_167 ] + 1 <
F_38 ( V_64 -> V_82 [ V_167 ] ) ) {
V_64 -> V_83 [ V_167 ] ++ ;
return 0 ;
} else {
V_29 = F_453 ( V_110 , V_35 , V_64 , V_591 ) ;
if ( V_29 > 0 )
return 0 ;
if ( V_64 -> V_604 [ V_167 ] ) {
F_438 ( V_64 -> V_82 [ V_167 ] ,
V_64 -> V_604 [ V_167 ] ) ;
V_64 -> V_604 [ V_167 ] = 0 ;
}
F_439 ( V_64 -> V_82 [ V_167 ] ) ;
V_64 -> V_82 [ V_167 ] = NULL ;
V_167 ++ ;
}
}
return 1 ;
}
int F_456 ( struct V_34 * V_35 ,
struct V_240 * V_391 , int V_599 ,
int V_622 )
{
struct V_63 * V_64 ;
struct V_109 * V_110 ;
struct V_34 * V_86 = V_35 -> V_37 -> V_86 ;
struct V_623 * V_257 = & V_35 -> V_257 ;
struct V_590 * V_591 ;
struct V_67 V_21 ;
int V_81 = 0 ;
int V_29 ;
int V_167 ;
bool V_624 = false ;
F_178 ( V_35 -> V_37 , L_38 , V_35 -> V_22 ) ;
V_64 = F_33 () ;
if ( ! V_64 ) {
V_81 = - V_71 ;
goto V_72;
}
V_591 = F_53 ( sizeof( * V_591 ) , V_40 ) ;
if ( ! V_591 ) {
F_50 ( V_64 ) ;
V_81 = - V_71 ;
goto V_72;
}
V_110 = F_457 ( V_86 , 0 ) ;
if ( F_195 ( V_110 ) ) {
V_81 = F_196 ( V_110 ) ;
goto V_123;
}
if ( V_391 )
V_110 -> V_391 = V_391 ;
if ( F_458 ( & V_257 -> V_625 ) == 0 ) {
V_167 = F_222 ( V_35 -> V_128 ) ;
V_64 -> V_82 [ V_167 ] = F_459 ( V_35 ) ;
F_421 ( V_64 -> V_82 [ V_167 ] ) ;
V_64 -> V_83 [ V_167 ] = 0 ;
V_64 -> V_604 [ V_167 ] = V_618 ;
memset ( & V_591 -> V_600 , 0 ,
sizeof( V_591 -> V_600 ) ) ;
} else {
F_460 ( & V_21 , & V_257 -> V_625 ) ;
memcpy ( & V_591 -> V_600 , & V_21 ,
sizeof( V_591 -> V_600 ) ) ;
V_167 = V_257 -> V_626 ;
F_30 ( V_167 == 0 ) ;
V_64 -> V_627 = V_167 ;
V_29 = F_37 ( NULL , V_35 , & V_21 , V_64 , 0 , 0 ) ;
V_64 -> V_627 = 0 ;
if ( V_29 < 0 ) {
V_81 = V_29 ;
goto V_628;
}
F_8 ( V_29 > 0 ) ;
F_128 ( V_64 , 0 ) ;
V_167 = F_222 ( V_35 -> V_128 ) ;
while ( 1 ) {
F_419 ( V_64 -> V_82 [ V_167 ] ) ;
F_421 ( V_64 -> V_82 [ V_167 ] ) ;
V_64 -> V_604 [ V_167 ] = V_618 ;
V_29 = F_75 ( V_110 , V_35 ,
V_64 -> V_82 [ V_167 ] -> V_32 ,
V_167 , 1 , & V_591 -> V_112 [ V_167 ] ,
& V_591 -> V_7 [ V_167 ] ) ;
if ( V_29 < 0 ) {
V_81 = V_29 ;
goto V_628;
}
F_30 ( V_591 -> V_112 [ V_167 ] == 0 ) ;
if ( V_167 == V_257 -> V_626 )
break;
F_450 ( V_64 -> V_82 [ V_167 ] ) ;
V_64 -> V_604 [ V_167 ] = 0 ;
F_8 ( V_591 -> V_112 [ V_167 ] != 1 ) ;
V_167 -- ;
}
}
V_591 -> V_167 = V_167 ;
V_591 -> V_617 = - 1 ;
V_591 -> V_596 = V_598 ;
V_591 -> V_599 = V_599 ;
V_591 -> V_174 = 0 ;
V_591 -> V_622 = V_622 ;
V_591 -> V_595 = F_432 ( V_35 ) ;
while ( 1 ) {
V_29 = F_454 ( V_110 , V_35 , V_64 , V_591 ) ;
if ( V_29 < 0 ) {
V_81 = V_29 ;
break;
}
V_29 = F_455 ( V_110 , V_35 , V_64 , V_591 , V_168 ) ;
if ( V_29 < 0 ) {
V_81 = V_29 ;
break;
}
if ( V_29 > 0 ) {
F_30 ( V_591 -> V_596 != V_598 ) ;
break;
}
if ( V_591 -> V_596 == V_598 ) {
V_167 = V_591 -> V_167 ;
F_461 ( V_64 -> V_82 [ V_167 ] ,
& V_257 -> V_625 ,
V_64 -> V_83 [ V_167 ] ) ;
V_257 -> V_626 = V_167 ;
}
F_30 ( V_591 -> V_167 == 0 ) ;
if ( F_462 ( V_110 , V_86 ) ||
( ! V_622 && F_463 ( V_35 ) ) ) {
V_29 = F_464 ( V_110 , V_86 ,
& V_35 -> V_256 ,
V_257 ) ;
if ( V_29 ) {
F_151 ( V_110 , V_86 , V_29 ) ;
V_81 = V_29 ;
goto V_628;
}
V_29 = F_208 ( V_110 ,
V_35 -> V_37 ) ;
if ( V_29 )
F_452 ( V_619 L_39
L_40
L_41
L_42
L_43 , V_29 ) ;
F_465 ( V_110 , V_86 ) ;
if ( ! V_622 && F_463 ( V_35 ) ) {
F_466 ( L_44 ) ;
V_81 = - V_178 ;
goto V_123;
}
V_110 = F_457 ( V_86 , 0 ) ;
if ( F_195 ( V_110 ) ) {
V_81 = F_196 ( V_110 ) ;
goto V_123;
}
if ( V_391 )
V_110 -> V_391 = V_391 ;
}
}
F_44 ( V_64 ) ;
if ( V_81 )
goto V_628;
V_29 = F_467 ( V_110 , V_86 , & V_35 -> V_256 ) ;
if ( V_29 ) {
F_151 ( V_110 , V_86 , V_29 ) ;
goto V_628;
}
if ( V_35 -> V_256 . V_22 != V_589 ) {
V_29 = F_468 ( V_86 , & V_35 -> V_256 , V_64 ,
NULL , NULL ) ;
if ( V_29 < 0 ) {
F_151 ( V_110 , V_86 , V_29 ) ;
V_81 = V_29 ;
goto V_628;
} else if ( V_29 > 0 ) {
F_469 ( V_110 , V_86 ,
V_35 -> V_256 . V_22 ) ;
}
}
if ( F_223 ( V_629 , & V_35 -> V_266 ) ) {
F_470 ( V_86 -> V_37 , V_35 ) ;
} else {
F_439 ( V_35 -> V_128 ) ;
F_439 ( V_35 -> V_630 ) ;
F_471 ( V_35 ) ;
}
V_624 = true ;
V_628:
V_29 = F_208 ( V_110 , V_86 -> V_37 ) ;
if ( V_29 )
F_452 ( V_619 L_39
L_40
L_41
L_42
L_43 , V_29 ) ;
F_465 ( V_110 , V_86 ) ;
V_123:
F_9 ( V_591 ) ;
F_50 ( V_64 ) ;
V_72:
if ( ! V_622 && V_624 == false )
F_472 ( V_35 ) ;
if ( V_81 && V_81 != - V_178 )
F_473 ( V_35 -> V_37 , V_81 ) ;
return V_81 ;
}
int F_474 ( struct V_109 * V_110 ,
struct V_34 * V_35 ,
struct V_65 * V_128 ,
struct V_65 * V_17 )
{
struct V_63 * V_64 ;
struct V_590 * V_591 ;
int V_167 ;
int V_631 ;
int V_29 = 0 ;
int V_632 ;
F_30 ( V_35 -> V_256 . V_22 != V_589 ) ;
V_64 = F_33 () ;
if ( ! V_64 )
return - V_71 ;
V_591 = F_53 ( sizeof( * V_591 ) , V_40 ) ;
if ( ! V_591 ) {
F_50 ( V_64 ) ;
return - V_71 ;
}
F_475 ( V_17 ) ;
V_631 = F_222 ( V_17 ) ;
F_443 ( V_17 ) ;
V_64 -> V_82 [ V_631 ] = V_17 ;
V_64 -> V_83 [ V_631 ] = F_38 ( V_17 ) ;
F_475 ( V_128 ) ;
V_167 = F_222 ( V_128 ) ;
V_64 -> V_82 [ V_167 ] = V_128 ;
V_64 -> V_83 [ V_167 ] = 0 ;
V_64 -> V_604 [ V_167 ] = V_618 ;
V_591 -> V_112 [ V_631 ] = 1 ;
V_591 -> V_7 [ V_631 ] = V_126 ;
V_591 -> V_167 = V_167 ;
V_591 -> V_617 = - 1 ;
V_591 -> V_596 = V_598 ;
V_591 -> V_599 = 0 ;
V_591 -> V_174 = 1 ;
V_591 -> V_622 = 1 ;
V_591 -> V_595 = F_432 ( V_35 ) ;
while ( 1 ) {
V_632 = F_454 ( V_110 , V_35 , V_64 , V_591 ) ;
if ( V_632 < 0 ) {
V_29 = V_632 ;
break;
}
V_632 = F_455 ( V_110 , V_35 , V_64 , V_591 , V_631 ) ;
if ( V_632 < 0 )
V_29 = V_632 ;
if ( V_632 != 0 )
break;
}
F_9 ( V_591 ) ;
F_50 ( V_64 ) ;
return V_29 ;
}
static T_2 F_476 ( struct V_34 * V_35 , T_2 V_7 )
{
T_2 V_338 ;
T_2 V_633 ;
V_633 = F_267 ( V_35 -> V_37 , V_7 ) ;
if ( V_633 )
return F_269 ( V_633 ) ;
V_338 = V_35 -> V_37 -> V_339 -> V_340 ;
V_633 = V_342 |
V_343 | V_344 |
V_302 | V_303 ;
if ( V_338 == 1 ) {
V_633 |= V_301 ;
V_633 = V_7 & ~ V_633 ;
if ( V_7 & V_342 )
return V_633 ;
if ( V_7 & ( V_302 |
V_303 ) )
return V_633 | V_301 ;
} else {
if ( V_7 & V_633 )
return V_7 ;
V_633 |= V_301 ;
V_633 = V_7 & ~ V_633 ;
if ( V_7 & V_301 )
return V_633 | V_302 ;
}
return V_7 ;
}
static int F_477 ( struct V_1 * V_2 , int V_362 )
{
struct V_102 * V_361 = V_2 -> V_105 ;
T_2 V_36 ;
T_2 V_634 ;
int V_29 = - V_357 ;
if ( ( V_361 -> V_7 &
( V_297 | V_295 ) ) &&
! V_362 )
V_634 = 1 * 1024 * 1024 ;
else
V_634 = 0 ;
F_11 ( & V_361 -> V_52 ) ;
F_11 ( & V_2 -> V_52 ) ;
if ( V_2 -> V_279 ) {
V_29 = 0 ;
goto V_72;
}
V_36 = V_2 -> V_21 . V_33 - V_2 -> V_10 - V_2 -> V_9 -
V_2 -> V_46 - F_360 ( & V_2 -> V_135 ) ;
if ( V_361 -> V_299 + V_361 -> V_312 + V_361 -> V_311 +
V_361 -> V_314 + V_361 -> V_313 + V_36 +
V_634 <= V_361 -> V_298 ) {
V_361 -> V_313 += V_36 ;
V_2 -> V_279 = 1 ;
F_64 ( & V_2 -> V_635 , & V_361 -> V_319 ) ;
V_29 = 0 ;
}
V_72:
F_13 ( & V_2 -> V_52 ) ;
F_13 ( & V_361 -> V_52 ) ;
return V_29 ;
}
int F_478 ( struct V_34 * V_35 ,
struct V_1 * V_2 )
{
struct V_109 * V_110 ;
T_2 V_636 ;
int V_29 ;
F_30 ( V_2 -> V_279 ) ;
V_110 = F_194 ( V_35 ) ;
if ( F_195 ( V_110 ) )
return F_196 ( V_110 ) ;
V_29 = F_477 ( V_2 , 0 ) ;
if ( ! V_29 )
goto V_72;
V_636 = F_270 ( V_35 , V_2 -> V_105 -> V_7 ) ;
V_29 = F_276 ( V_110 , V_35 , V_636 ,
V_356 ) ;
if ( V_29 < 0 )
goto V_72;
V_29 = F_477 ( V_2 , 0 ) ;
V_72:
if ( V_2 -> V_7 & V_297 ) {
V_636 = F_476 ( V_35 , V_2 -> V_7 ) ;
F_287 ( V_110 , V_35 , V_636 ) ;
}
F_198 ( V_110 , V_35 ) ;
return V_29 ;
}
int F_479 ( struct V_109 * V_110 ,
struct V_34 * V_35 , T_2 type )
{
T_2 V_636 = F_270 ( V_35 , type ) ;
return F_276 ( V_110 , V_35 , V_636 ,
V_356 ) ;
}
T_2 F_480 ( struct V_102 * V_361 )
{
struct V_1 * V_14 ;
T_2 V_637 = 0 ;
int V_300 ;
if ( F_205 ( & V_361 -> V_319 ) )
return 0 ;
F_11 ( & V_361 -> V_52 ) ;
F_397 (block_group, &sinfo->ro_bgs, ro_list) {
F_11 ( & V_14 -> V_52 ) ;
if ( ! V_14 -> V_279 ) {
F_13 ( & V_14 -> V_52 ) ;
continue;
}
if ( V_14 -> V_7 & ( V_302 |
V_303 |
V_301 ) )
V_300 = 2 ;
else
V_300 = 1 ;
V_637 += ( V_14 -> V_21 . V_33 -
F_360 ( & V_14 -> V_135 ) ) *
V_300 ;
F_13 ( & V_14 -> V_52 ) ;
}
F_13 ( & V_361 -> V_52 ) ;
return V_637 ;
}
void F_481 ( struct V_34 * V_35 ,
struct V_1 * V_2 )
{
struct V_102 * V_361 = V_2 -> V_105 ;
T_2 V_36 ;
F_30 ( ! V_2 -> V_279 ) ;
F_11 ( & V_361 -> V_52 ) ;
F_11 ( & V_2 -> V_52 ) ;
V_36 = V_2 -> V_21 . V_33 - V_2 -> V_10 - V_2 -> V_9 -
V_2 -> V_46 - F_360 ( & V_2 -> V_135 ) ;
V_361 -> V_313 -= V_36 ;
V_2 -> V_279 = 0 ;
F_253 ( & V_2 -> V_635 ) ;
F_13 ( & V_2 -> V_52 ) ;
F_13 ( & V_361 -> V_52 ) ;
}
int F_482 ( struct V_34 * V_35 , T_2 V_27 )
{
struct V_1 * V_14 ;
struct V_102 * V_105 ;
struct V_638 * V_339 = V_35 -> V_37 -> V_339 ;
struct V_639 * V_640 ;
struct V_109 * V_110 ;
T_2 V_641 ;
T_2 V_642 = 1 ;
T_2 V_643 = 0 ;
T_2 V_333 ;
int V_540 ;
int V_108 = 0 ;
int V_29 = 0 ;
V_14 = F_68 ( V_35 -> V_37 , V_27 ) ;
if ( ! V_14 )
return - 1 ;
V_641 = F_360 ( & V_14 -> V_135 ) ;
if ( ! V_641 )
goto V_72;
V_105 = V_14 -> V_105 ;
F_11 ( & V_105 -> V_52 ) ;
V_108 = V_105 -> V_108 ;
if ( ( V_105 -> V_298 != V_14 -> V_21 . V_33 ) &&
( V_105 -> V_299 + V_105 -> V_312 +
V_105 -> V_311 + V_105 -> V_313 +
V_641 < V_105 -> V_298 ) ) {
F_13 ( & V_105 -> V_52 ) ;
goto V_72;
}
F_13 ( & V_105 -> V_52 ) ;
V_29 = - 1 ;
V_333 = F_267 ( V_35 -> V_37 , V_14 -> V_7 ) ;
if ( V_333 ) {
V_540 = F_387 ( F_269 ( V_333 ) ) ;
} else {
if ( V_108 )
goto V_72;
V_540 = F_388 ( V_14 ) ;
}
if ( V_540 == V_518 ) {
V_642 = 4 ;
V_641 >>= 1 ;
} else if ( V_540 == V_519 ) {
V_642 = 2 ;
} else if ( V_540 == V_520 ) {
V_641 <<= 1 ;
} else if ( V_540 == V_521 ) {
V_642 = V_339 -> V_340 ;
F_483 ( V_641 , V_642 ) ;
}
V_110 = F_194 ( V_35 ) ;
if ( F_195 ( V_110 ) ) {
V_29 = F_196 ( V_110 ) ;
goto V_72;
}
F_35 ( & V_35 -> V_37 -> V_372 ) ;
F_397 (device, &fs_devices->alloc_list, dev_alloc_list) {
T_2 V_644 ;
if ( V_640 -> V_298 > V_640 -> V_299 + V_641 &&
! V_640 -> V_645 ) {
V_29 = F_484 ( V_110 , V_640 , V_641 ,
& V_644 , NULL ) ;
if ( ! V_29 )
V_643 ++ ;
if ( V_643 >= V_642 )
break;
V_29 = - 1 ;
}
}
F_46 ( & V_35 -> V_37 -> V_372 ) ;
F_198 ( V_110 , V_35 ) ;
V_72:
F_6 ( V_14 ) ;
return V_29 ;
}
static int F_485 ( struct V_34 * V_35 ,
struct V_63 * V_64 , struct V_67 * V_21 )
{
int V_29 = 0 ;
struct V_67 V_140 ;
struct V_65 * V_66 ;
int V_592 ;
V_29 = F_37 ( NULL , V_35 , V_21 , V_64 , 0 , 0 ) ;
if ( V_29 < 0 )
goto V_72;
while ( 1 ) {
V_592 = V_64 -> V_83 [ 0 ] ;
V_66 = V_64 -> V_82 [ 0 ] ;
if ( V_592 >= F_38 ( V_66 ) ) {
V_29 = F_48 ( V_35 , V_64 ) ;
if ( V_29 == 0 )
continue;
if ( V_29 < 0 )
goto V_72;
break;
}
F_40 ( V_66 , & V_140 , V_592 ) ;
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
void F_486 ( struct V_12 * V_13 )
{
struct V_1 * V_14 ;
T_2 V_69 = 0 ;
while ( 1 ) {
struct V_271 * V_271 ;
V_14 = F_67 ( V_13 , V_69 ) ;
while ( V_14 ) {
F_11 ( & V_14 -> V_52 ) ;
if ( V_14 -> V_164 )
break;
F_13 ( & V_14 -> V_52 ) ;
V_14 = F_234 ( V_13 -> V_86 ,
V_14 ) ;
}
if ( ! V_14 ) {
if ( V_69 == 0 )
break;
V_69 = 0 ;
continue;
}
V_271 = V_14 -> V_271 ;
V_14 -> V_164 = 0 ;
V_14 -> V_271 = NULL ;
F_13 ( & V_14 -> V_52 ) ;
F_248 ( V_271 ) ;
V_69 = V_14 -> V_21 . V_22 + V_14 -> V_21 . V_33 ;
F_6 ( V_14 ) ;
}
}
int F_487 ( struct V_12 * V_13 )
{
struct V_1 * V_14 ;
struct V_102 * V_105 ;
struct V_50 * V_53 ;
struct V_15 * V_30 ;
F_63 ( & V_13 -> V_79 ) ;
while ( ! F_205 ( & V_13 -> V_100 ) ) {
V_53 = F_488 ( V_13 -> V_100 . V_80 ,
struct V_50 , V_90 ) ;
F_489 ( & V_53 -> V_90 ) ;
F_26 ( V_53 ) ;
}
F_65 ( & V_13 -> V_79 ) ;
F_11 ( & V_13 -> V_485 ) ;
while ( ! F_205 ( & V_13 -> V_487 ) ) {
V_14 = F_252 ( & V_13 -> V_487 ,
struct V_1 ,
V_486 ) ;
F_253 ( & V_14 -> V_486 ) ;
F_6 ( V_14 ) ;
}
F_13 ( & V_13 -> V_485 ) ;
F_11 ( & V_13 -> V_18 ) ;
while ( ( V_30 = F_186 ( & V_13 -> V_19 ) ) != NULL ) {
V_14 = F_12 ( V_30 , struct V_1 ,
V_20 ) ;
F_180 ( & V_14 -> V_20 ,
& V_13 -> V_19 ) ;
F_490 ( & V_14 -> V_20 ) ;
F_13 ( & V_13 -> V_18 ) ;
F_63 ( & V_14 -> V_105 -> V_310 ) ;
F_489 ( & V_14 -> V_90 ) ;
F_65 ( & V_14 -> V_105 -> V_310 ) ;
if ( V_14 -> V_3 == V_98 )
F_386 ( V_14 ) ;
if ( V_14 -> V_3 == V_94 ||
V_14 -> V_3 == V_5 )
F_19 ( V_13 -> V_62 , V_14 ) ;
F_491 ( V_14 ) ;
F_6 ( V_14 ) ;
F_11 ( & V_13 -> V_18 ) ;
}
F_13 ( & V_13 -> V_18 ) ;
F_492 () ;
F_338 ( V_13 ) ;
while ( ! F_205 ( & V_13 -> V_105 ) ) {
int V_43 ;
V_105 = F_488 ( V_13 -> V_105 . V_80 ,
struct V_102 ,
V_90 ) ;
if ( F_244 ( V_13 -> V_86 , V_369 ) ) {
if ( F_8 ( V_105 -> V_311 > 0 ||
V_105 -> V_312 > 0 ||
V_105 -> V_314 > 0 ) ) {
F_289 ( V_105 , 0 , 0 ) ;
}
}
F_489 ( & V_105 -> V_90 ) ;
for ( V_43 = 0 ; V_43 < V_308 ; V_43 ++ ) {
struct V_646 * V_320 ;
V_320 = V_105 -> V_647 [ V_43 ] ;
V_105 -> V_647 [ V_43 ] = NULL ;
if ( V_320 ) {
F_493 ( V_320 ) ;
F_494 ( V_320 ) ;
}
}
F_493 ( & V_105 -> V_320 ) ;
F_494 ( & V_105 -> V_320 ) ;
}
return 0 ;
}
static void F_495 ( struct V_102 * V_105 ,
struct V_1 * V_2 )
{
int V_540 = F_388 ( V_2 ) ;
bool V_238 = false ;
F_63 ( & V_105 -> V_310 ) ;
if ( F_205 ( & V_105 -> V_309 [ V_540 ] ) )
V_238 = true ;
F_64 ( & V_2 -> V_90 , & V_105 -> V_309 [ V_540 ] ) ;
F_65 ( & V_105 -> V_310 ) ;
if ( V_238 ) {
struct V_648 * V_649 ;
int V_29 ;
V_649 = F_53 ( sizeof( * V_649 ) , V_40 ) ;
if ( ! V_649 )
goto V_650;
V_649 -> V_651 = V_540 ;
F_496 ( & V_649 -> V_320 , & V_652 ) ;
V_29 = F_497 ( & V_649 -> V_320 , & V_105 -> V_320 ,
L_8 , F_389 ( V_540 ) ) ;
if ( V_29 ) {
F_494 ( & V_649 -> V_320 ) ;
goto V_650;
}
V_105 -> V_647 [ V_540 ] = & V_649 -> V_320 ;
}
return;
V_650:
F_498 ( L_45 ) ;
}
static struct V_1 *
F_499 ( struct V_34 * V_35 , T_2 V_32 , T_2 V_56 )
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
V_2 -> V_351 = V_35 -> V_351 ;
V_2 -> V_37 = V_35 -> V_37 ;
V_2 -> V_653 = F_500 ( V_35 ,
& V_35 -> V_37 -> V_48 ,
V_32 ) ;
F_57 ( & V_2 -> V_8 , 1 ) ;
F_260 ( & V_2 -> V_52 ) ;
F_259 ( & V_2 -> V_527 ) ;
F_54 ( & V_2 -> V_90 ) ;
F_54 ( & V_2 -> V_654 ) ;
F_54 ( & V_2 -> V_486 ) ;
F_54 ( & V_2 -> V_635 ) ;
F_54 ( & V_2 -> V_293 ) ;
F_501 ( V_2 ) ;
F_57 ( & V_2 -> V_655 , 0 ) ;
return V_2 ;
}
int F_502 ( struct V_34 * V_35 )
{
struct V_63 * V_64 ;
int V_29 ;
struct V_1 * V_2 ;
struct V_12 * V_13 = V_35 -> V_37 ;
struct V_102 * V_105 ;
struct V_67 V_21 ;
struct V_67 V_140 ;
struct V_65 * V_66 ;
int V_656 = 0 ;
T_2 V_657 ;
V_35 = V_13 -> V_62 ;
V_21 . V_22 = 0 ;
V_21 . V_33 = 0 ;
V_21 . type = V_179 ;
V_64 = F_33 () ;
if ( ! V_64 )
return - V_71 ;
V_64 -> V_75 = 1 ;
V_657 = F_503 ( V_35 -> V_37 -> V_366 ) ;
if ( F_244 ( V_35 , V_285 ) &&
F_504 ( V_35 -> V_37 -> V_366 ) != V_657 )
V_656 = 1 ;
if ( F_244 ( V_35 , V_658 ) )
V_656 = 1 ;
while ( 1 ) {
V_29 = F_485 ( V_35 , V_64 , & V_21 ) ;
if ( V_29 > 0 )
break;
if ( V_29 != 0 )
goto error;
V_66 = V_64 -> V_82 [ 0 ] ;
F_40 ( V_66 , & V_140 , V_64 -> V_83 [ 0 ] ) ;
V_2 = F_499 ( V_35 , V_140 . V_22 ,
V_140 . V_33 ) ;
if ( ! V_2 ) {
V_29 = - V_71 ;
goto error;
}
if ( V_656 ) {
if ( F_244 ( V_35 , V_285 ) )
V_2 -> V_277 = V_292 ;
}
F_505 ( V_66 , & V_2 -> V_135 ,
F_232 ( V_66 , V_64 -> V_83 [ 0 ] ) ,
sizeof( V_2 -> V_135 ) ) ;
V_2 -> V_7 = F_506 ( & V_2 -> V_135 ) ;
V_21 . V_22 = V_140 . V_22 + V_140 . V_33 ;
F_44 ( V_64 ) ;
V_29 = F_21 ( V_35 , V_2 ) ;
if ( V_29 ) {
F_19 ( V_35 , V_2 ) ;
F_6 ( V_2 ) ;
goto error;
}
if ( V_140 . V_33 == F_360 ( & V_2 -> V_135 ) ) {
V_2 -> V_97 = ( T_2 ) - 1 ;
V_2 -> V_3 = V_4 ;
F_19 ( V_35 , V_2 ) ;
} else if ( F_360 ( & V_2 -> V_135 ) == 0 ) {
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
F_491 ( V_2 ) ;
F_6 ( V_2 ) ;
goto error;
}
V_29 = F_257 ( V_13 , V_2 -> V_7 , V_140 . V_33 ,
F_360 ( & V_2 -> V_135 ) ,
& V_105 ) ;
if ( V_29 ) {
F_491 ( V_2 ) ;
F_11 ( & V_13 -> V_18 ) ;
F_180 ( & V_2 -> V_20 ,
& V_13 -> V_19 ) ;
F_490 ( & V_2 -> V_20 ) ;
F_13 ( & V_13 -> V_18 ) ;
F_6 ( V_2 ) ;
goto error;
}
V_2 -> V_105 = V_105 ;
F_11 ( & V_2 -> V_105 -> V_52 ) ;
V_2 -> V_105 -> V_313 += V_2 -> V_46 ;
F_13 ( & V_2 -> V_105 -> V_52 ) ;
F_495 ( V_105 , V_2 ) ;
F_263 ( V_35 -> V_37 , V_2 -> V_7 ) ;
if ( F_507 ( V_35 , V_2 -> V_21 . V_22 ) ) {
F_477 ( V_2 , 1 ) ;
} else if ( F_360 ( & V_2 -> V_135 ) == 0 ) {
F_11 ( & V_13 -> V_485 ) ;
if ( F_205 ( & V_2 -> V_486 ) ) {
F_4 ( V_2 ) ;
F_64 ( & V_2 -> V_486 ,
& V_13 -> V_487 ) ;
}
F_13 ( & V_13 -> V_485 ) ;
}
}
F_71 (space_info, &root->fs_info->space_info, list) {
if ( ! ( F_270 ( V_35 , V_105 -> V_7 ) &
( V_303 |
V_302 |
V_343 |
V_344 |
V_301 ) ) )
continue;
F_397 (cache,
&space_info->block_groups[BTRFS_RAID_RAID0],
list)
F_477 ( V_2 , 1 ) ;
F_397 (cache,
&space_info->block_groups[BTRFS_RAID_SINGLE],
list)
F_477 ( V_2 , 1 ) ;
}
F_337 ( V_13 ) ;
V_29 = 0 ;
error:
F_50 ( V_64 ) ;
return V_29 ;
}
void F_206 ( struct V_109 * V_110 ,
struct V_34 * V_35 )
{
struct V_1 * V_14 , * V_288 ;
struct V_34 * V_62 = V_35 -> V_37 -> V_62 ;
struct V_659 V_135 ;
struct V_67 V_21 ;
int V_29 = 0 ;
F_250 (block_group, tmp, &trans->new_bgs, bg_list) {
if ( V_29 )
goto V_80;
F_11 ( & V_14 -> V_52 ) ;
memcpy ( & V_135 , & V_14 -> V_135 , sizeof( V_135 ) ) ;
memcpy ( & V_21 , & V_14 -> V_21 , sizeof( V_21 ) ) ;
F_13 ( & V_14 -> V_52 ) ;
V_29 = F_508 ( V_110 , V_62 , & V_21 , & V_135 ,
sizeof( V_135 ) ) ;
if ( V_29 )
F_151 ( V_110 , V_62 , V_29 ) ;
V_29 = F_509 ( V_110 , V_62 ,
V_21 . V_22 , V_21 . V_33 ) ;
if ( V_29 )
F_151 ( V_110 , V_62 , V_29 ) ;
V_80:
F_253 ( & V_14 -> V_486 ) ;
}
}
int F_510 ( struct V_109 * V_110 ,
struct V_34 * V_35 , T_2 V_299 ,
T_2 type , T_2 V_660 , T_2 V_661 ,
T_2 V_56 )
{
int V_29 ;
struct V_34 * V_62 ;
struct V_1 * V_2 ;
V_62 = V_35 -> V_37 -> V_62 ;
F_511 ( V_35 -> V_37 , V_110 ) ;
V_2 = F_499 ( V_35 , V_661 , V_56 ) ;
if ( ! V_2 )
return - V_71 ;
F_361 ( & V_2 -> V_135 , V_299 ) ;
F_512 ( & V_2 -> V_135 , V_660 ) ;
F_513 ( & V_2 -> V_135 , type ) ;
V_2 -> V_7 = type ;
V_2 -> V_97 = ( T_2 ) - 1 ;
V_2 -> V_3 = V_4 ;
V_29 = F_21 ( V_35 , V_2 ) ;
if ( V_29 ) {
F_19 ( V_35 , V_2 ) ;
F_6 ( V_2 ) ;
return V_29 ;
}
F_27 ( V_2 , V_35 -> V_37 , V_661 ,
V_661 + V_56 ) ;
F_19 ( V_35 , V_2 ) ;
V_29 = F_10 ( V_35 -> V_37 , V_2 ) ;
if ( V_29 ) {
F_491 ( V_2 ) ;
F_6 ( V_2 ) ;
return V_29 ;
}
V_29 = F_257 ( V_35 -> V_37 , V_2 -> V_7 , V_56 , V_299 ,
& V_2 -> V_105 ) ;
if ( V_29 ) {
F_491 ( V_2 ) ;
F_11 ( & V_35 -> V_37 -> V_18 ) ;
F_180 ( & V_2 -> V_20 ,
& V_35 -> V_37 -> V_19 ) ;
F_490 ( & V_2 -> V_20 ) ;
F_13 ( & V_35 -> V_37 -> V_18 ) ;
F_6 ( V_2 ) ;
return V_29 ;
}
F_336 ( V_35 -> V_37 ) ;
F_11 ( & V_2 -> V_105 -> V_52 ) ;
V_2 -> V_105 -> V_313 += V_2 -> V_46 ;
F_13 ( & V_2 -> V_105 -> V_52 ) ;
F_495 ( V_2 -> V_105 , V_2 ) ;
F_64 ( & V_2 -> V_486 , & V_110 -> V_254 ) ;
F_263 ( V_62 -> V_37 , type ) ;
return 0 ;
}
static void F_514 ( struct V_12 * V_37 , T_2 V_7 )
{
T_2 V_324 = F_264 ( V_7 ) &
V_325 ;
F_265 ( & V_37 -> V_326 ) ;
if ( V_7 & V_296 )
V_37 -> V_327 &= ~ V_324 ;
if ( V_7 & V_295 )
V_37 -> V_328 &= ~ V_324 ;
if ( V_7 & V_297 )
V_37 -> V_329 &= ~ V_324 ;
F_266 ( & V_37 -> V_326 ) ;
}
int F_515 ( struct V_109 * V_110 ,
struct V_34 * V_35 , T_2 V_662 ,
struct V_663 * V_664 )
{
struct V_63 * V_64 ;
struct V_1 * V_14 ;
struct V_528 * V_529 ;
struct V_34 * V_86 = V_35 -> V_37 -> V_86 ;
struct V_67 V_21 ;
struct V_271 * V_271 ;
struct V_646 * V_320 = NULL ;
int V_29 ;
int V_540 ;
int V_300 ;
struct V_50 * V_53 = NULL ;
bool V_665 ;
V_35 = V_35 -> V_37 -> V_62 ;
V_14 = F_68 ( V_35 -> V_37 , V_662 ) ;
F_30 ( ! V_14 ) ;
F_30 ( ! V_14 -> V_279 ) ;
F_19 ( V_35 , V_14 ) ;
memcpy ( & V_21 , & V_14 -> V_21 , sizeof( V_21 ) ) ;
V_540 = F_388 ( V_14 ) ;
if ( V_14 -> V_7 & ( V_301 |
V_302 |
V_303 ) )
V_300 = 2 ;
else
V_300 = 1 ;
V_529 = & V_35 -> V_37 -> V_549 ;
F_11 ( & V_529 -> V_532 ) ;
F_400 ( V_14 , V_529 ) ;
F_13 ( & V_529 -> V_532 ) ;
V_529 = & V_35 -> V_37 -> V_547 ;
F_11 ( & V_529 -> V_532 ) ;
F_400 ( V_14 , V_529 ) ;
F_13 ( & V_529 -> V_532 ) ;
V_64 = F_33 () ;
if ( ! V_64 ) {
V_29 = - V_71 ;
goto V_72;
}
V_271 = F_237 ( V_86 , V_14 , V_64 ) ;
if ( ! F_195 ( V_271 ) ) {
V_29 = F_516 ( V_110 , V_271 ) ;
if ( V_29 ) {
F_517 ( V_271 ) ;
goto V_72;
}
F_518 ( V_271 ) ;
F_11 ( & V_14 -> V_52 ) ;
if ( V_14 -> V_164 ) {
V_14 -> V_164 = 0 ;
V_14 -> V_271 = NULL ;
F_13 ( & V_14 -> V_52 ) ;
F_248 ( V_271 ) ;
} else {
F_13 ( & V_14 -> V_52 ) ;
}
F_517 ( V_271 ) ;
}
V_21 . V_22 = V_666 ;
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
F_180 ( & V_14 -> V_20 ,
& V_35 -> V_37 -> V_19 ) ;
F_490 ( & V_14 -> V_20 ) ;
if ( V_35 -> V_37 -> V_26 == V_14 -> V_21 . V_22 )
V_35 -> V_37 -> V_26 = ( T_2 ) - 1 ;
F_13 ( & V_35 -> V_37 -> V_18 ) ;
F_63 ( & V_14 -> V_105 -> V_310 ) ;
F_253 ( & V_14 -> V_90 ) ;
if ( F_205 ( & V_14 -> V_105 -> V_309 [ V_540 ] ) ) {
V_320 = V_14 -> V_105 -> V_647 [ V_540 ] ;
V_14 -> V_105 -> V_647 [ V_540 ] = NULL ;
F_514 ( V_35 -> V_37 , V_14 -> V_7 ) ;
}
F_65 ( & V_14 -> V_105 -> V_310 ) ;
if ( V_320 ) {
F_493 ( V_320 ) ;
F_494 ( V_320 ) ;
}
if ( V_14 -> V_99 )
V_53 = F_25 ( V_14 ) ;
if ( V_14 -> V_3 == V_98 )
F_386 ( V_14 ) ;
if ( V_14 -> V_99 ) {
F_63 ( & V_35 -> V_37 -> V_79 ) ;
if ( ! V_53 ) {
struct V_50 * V_51 ;
F_397 (ctl,
&root->fs_info->caching_block_groups, list)
if ( V_51 -> V_14 == V_14 ) {
V_53 = V_51 ;
F_5 ( & V_53 -> V_8 ) ;
break;
}
}
if ( V_53 )
F_253 ( & V_53 -> V_90 ) ;
F_65 ( & V_35 -> V_37 -> V_79 ) ;
if ( V_53 ) {
F_26 ( V_53 ) ;
F_26 ( V_53 ) ;
}
}
F_11 ( & V_110 -> V_127 -> V_483 ) ;
if ( ! F_205 ( & V_14 -> V_293 ) ) {
F_253 ( & V_14 -> V_293 ) ;
F_6 ( V_14 ) ;
}
F_13 ( & V_110 -> V_127 -> V_483 ) ;
F_491 ( V_14 ) ;
F_11 ( & V_14 -> V_105 -> V_52 ) ;
F_253 ( & V_14 -> V_635 ) ;
V_14 -> V_105 -> V_298 -= V_14 -> V_21 . V_33 ;
V_14 -> V_105 -> V_313 -= V_14 -> V_21 . V_33 ;
V_14 -> V_105 -> V_304 -= V_14 -> V_21 . V_33 * V_300 ;
F_13 ( & V_14 -> V_105 -> V_52 ) ;
memcpy ( & V_21 , & V_14 -> V_21 , sizeof( V_21 ) ) ;
F_519 ( V_35 ) ;
if ( ! F_205 ( & V_664 -> V_90 ) ) {
F_520 ( V_664 ) ;
}
F_11 ( & V_14 -> V_52 ) ;
V_14 -> V_667 = 1 ;
V_665 = ( F_192 ( & V_14 -> V_655 ) == 0 ) ;
if ( ! V_665 ) {
F_521 ( & V_664 -> V_90 , & V_35 -> V_37 -> V_668 ) ;
}
F_13 ( & V_14 -> V_52 ) ;
if ( V_665 ) {
struct V_669 * V_670 ;
V_670 = & V_35 -> V_37 -> V_48 . V_671 ;
F_522 ( & V_670 -> V_52 ) ;
F_523 ( V_670 , V_664 ) ;
F_524 ( & V_670 -> V_52 ) ;
F_520 ( V_664 ) ;
}
F_525 ( V_35 ) ;
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
void F_526 ( struct V_12 * V_37 )
{
struct V_1 * V_14 ;
struct V_102 * V_105 ;
struct V_34 * V_35 = V_37 -> V_62 ;
struct V_109 * V_110 ;
int V_29 = 0 ;
if ( ! V_37 -> V_672 )
return;
F_11 ( & V_37 -> V_485 ) ;
while ( ! F_205 ( & V_37 -> V_487 ) ) {
T_2 V_32 , V_31 ;
V_14 = F_252 ( & V_37 -> V_487 ,
struct V_1 ,
V_486 ) ;
V_105 = V_14 -> V_105 ;
F_253 ( & V_14 -> V_486 ) ;
if ( V_29 || F_291 ( V_105 ) ) {
F_6 ( V_14 ) ;
continue;
}
F_13 ( & V_37 -> V_485 ) ;
F_63 ( & V_105 -> V_310 ) ;
F_11 ( & V_14 -> V_52 ) ;
if ( V_14 -> V_10 ||
F_360 ( & V_14 -> V_135 ) ||
V_14 -> V_279 ) {
F_13 ( & V_14 -> V_52 ) ;
F_65 ( & V_105 -> V_310 ) ;
goto V_80;
}
F_13 ( & V_14 -> V_52 ) ;
V_29 = F_477 ( V_14 , 0 ) ;
F_65 ( & V_105 -> V_310 ) ;
if ( V_29 < 0 ) {
V_29 = 0 ;
goto V_80;
}
V_110 = F_457 ( V_35 , 1 ) ;
if ( F_195 ( V_110 ) ) {
F_481 ( V_35 , V_14 ) ;
V_29 = F_196 ( V_110 ) ;
goto V_80;
}
V_32 = V_14 -> V_21 . V_22 ;
V_31 = V_32 + V_14 -> V_21 . V_33 - 1 ;
F_35 ( & V_37 -> V_500 ) ;
V_29 = F_20 ( & V_37 -> V_38 [ 0 ] , V_32 , V_31 ,
V_59 , V_40 ) ;
if ( V_29 ) {
F_46 ( & V_37 -> V_500 ) ;
F_481 ( V_35 , V_14 ) ;
goto V_673;
}
V_29 = F_20 ( & V_37 -> V_38 [ 1 ] , V_32 , V_31 ,
V_59 , V_40 ) ;
if ( V_29 ) {
F_46 ( & V_37 -> V_500 ) ;
F_481 ( V_35 , V_14 ) ;
goto V_673;
}
F_46 ( & V_37 -> V_500 ) ;
V_14 -> V_9 = 0 ;
V_29 = F_527 ( V_110 , V_35 ,
V_14 -> V_21 . V_22 ) ;
V_673:
F_198 ( V_110 , V_35 ) ;
V_80:
F_6 ( V_14 ) ;
F_11 ( & V_37 -> V_485 ) ;
}
F_13 ( & V_37 -> V_485 ) ;
}
int F_528 ( struct V_12 * V_37 )
{
struct V_102 * V_105 ;
struct V_674 * V_675 ;
T_2 V_676 ;
T_2 V_7 ;
int V_677 = 0 ;
int V_29 ;
V_675 = V_37 -> V_366 ;
if ( ! F_529 ( V_675 ) )
return 1 ;
V_676 = F_530 ( V_675 ) ;
if ( V_676 & V_678 )
V_677 = 1 ;
V_7 = V_297 ;
V_29 = F_257 ( V_37 , V_7 , 0 , 0 , & V_105 ) ;
if ( V_29 )
goto V_72;
if ( V_677 ) {
V_7 = V_295 | V_296 ;
V_29 = F_257 ( V_37 , V_7 , 0 , 0 , & V_105 ) ;
} else {
V_7 = V_295 ;
V_29 = F_257 ( V_37 , V_7 , 0 , 0 , & V_105 ) ;
if ( V_29 )
goto V_72;
V_7 = V_296 ;
V_29 = F_257 ( V_37 , V_7 , 0 , 0 , & V_105 ) ;
}
V_72:
return V_29 ;
}
int F_531 ( struct V_34 * V_35 , T_2 V_32 , T_2 V_31 )
{
return F_371 ( V_35 , V_32 , V_31 , false ) ;
}
int F_532 ( struct V_34 * V_35 , struct V_679 * V_680 )
{
struct V_12 * V_37 = V_35 -> V_37 ;
struct V_1 * V_2 = NULL ;
T_2 V_681 ;
T_2 V_32 ;
T_2 V_31 ;
T_2 V_682 = 0 ;
T_2 V_298 = F_283 ( V_37 -> V_366 ) ;
int V_29 = 0 ;
if ( V_680 -> V_49 == V_298 )
V_2 = F_67 ( V_37 , V_680 -> V_32 ) ;
else
V_2 = F_68 ( V_37 , V_680 -> V_32 ) ;
while ( V_2 ) {
if ( V_2 -> V_21 . V_22 >= ( V_680 -> V_32 + V_680 -> V_49 ) ) {
F_6 ( V_2 ) ;
break;
}
V_32 = F_396 ( V_680 -> V_32 , V_2 -> V_21 . V_22 ) ;
V_31 = F_301 ( V_680 -> V_32 + V_680 -> V_49 ,
V_2 -> V_21 . V_22 + V_2 -> V_21 . V_33 ) ;
if ( V_31 - V_32 >= V_680 -> V_683 ) {
if ( ! F_1 ( V_2 ) ) {
V_29 = F_51 ( V_2 , 0 ) ;
if ( V_29 ) {
F_6 ( V_2 ) ;
break;
}
V_29 = F_386 ( V_2 ) ;
if ( V_29 ) {
F_6 ( V_2 ) ;
break;
}
}
V_29 = F_533 ( V_2 ,
& V_681 ,
V_32 ,
V_31 ,
V_680 -> V_683 ) ;
V_682 += V_681 ;
if ( V_29 ) {
F_6 ( V_2 ) ;
break;
}
}
V_2 = F_234 ( V_37 -> V_86 , V_2 ) ;
}
V_680 -> V_49 = V_682 ;
return V_29 ;
}
void F_534 ( struct V_34 * V_35 )
{
F_535 ( & V_35 -> V_684 -> V_685 ) ;
F_2 () ;
if ( F_536 ( & V_35 -> V_684 -> V_88 ) )
F_49 ( & V_35 -> V_684 -> V_88 ) ;
}
int F_537 ( struct V_34 * V_35 )
{
if ( F_192 ( & V_35 -> V_686 ) )
return 0 ;
F_538 ( & V_35 -> V_684 -> V_685 ) ;
F_2 () ;
if ( F_192 ( & V_35 -> V_686 ) ) {
F_534 ( V_35 ) ;
return 0 ;
}
return 1 ;
}
