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
struct V_204 * V_128 ,
T_2 V_17 , T_2 V_146 ,
T_2 V_133 , T_2 V_33 , int V_157 ,
struct V_180 * V_129 )
{
struct V_12 * V_37 = V_35 -> V_37 ;
struct V_63 * V_64 ;
struct V_65 * V_66 ;
struct V_116 * V_135 ;
struct V_67 V_21 ;
T_2 V_27 = V_128 -> V_27 ;
T_2 V_36 = V_128 -> V_36 ;
T_2 V_112 ;
int V_29 ;
int V_201 = V_128 -> V_201 ;
V_64 = F_33 () ;
if ( ! V_64 )
return - V_71 ;
if ( ! F_149 ( V_146 ) || ! V_35 -> V_37 -> V_205 )
V_201 = 1 ;
V_64 -> V_75 = 1 ;
V_64 -> V_206 = 1 ;
V_29 = F_137 ( V_110 , V_37 -> V_62 , V_64 ,
V_27 , V_36 , V_17 ,
V_146 , V_133 , V_33 ,
V_157 , V_129 ) ;
if ( ( V_29 < 0 && V_29 != - V_178 ) || ! V_29 )
goto V_72;
V_66 = V_64 -> V_82 [ 0 ] ;
F_40 ( V_66 , & V_21 , V_64 -> V_83 [ 0 ] ) ;
V_135 = F_78 ( V_66 , V_64 -> V_83 [ 0 ] , struct V_116 ) ;
V_112 = F_79 ( V_66 , V_135 ) ;
F_90 ( V_66 , V_135 , V_112 + V_157 ) ;
if ( V_129 )
F_130 ( V_129 , V_66 , V_135 ) ;
F_95 ( V_66 ) ;
F_44 ( V_64 ) ;
V_64 -> V_75 = 1 ;
V_64 -> V_206 = 1 ;
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
struct V_204 * V_128 ,
struct V_180 * V_129 ,
int V_207 )
{
int V_29 = 0 ;
struct V_208 * V_151 ;
struct V_67 V_209 ;
T_2 V_17 = 0 ;
T_2 V_210 = 0 ;
T_2 V_7 = 0 ;
V_209 . V_22 = V_128 -> V_27 ;
V_209 . V_33 = V_128 -> V_36 ;
V_209 . type = V_76 ;
V_151 = F_152 ( V_128 ) ;
F_153 ( V_128 , V_151 , V_128 -> V_211 ) ;
if ( V_128 -> type == V_154 )
V_17 = V_151 -> V_17 ;
V_210 = V_151 -> V_35 ;
if ( V_128 -> V_211 == V_203 && V_207 ) {
if ( V_129 )
V_7 |= V_129 -> V_131 ;
V_29 = F_154 ( V_110 , V_35 ,
V_17 , V_210 , V_7 ,
V_151 -> V_22 , V_151 -> V_33 ,
& V_209 , V_128 -> V_132 ) ;
} else if ( V_128 -> V_211 == V_203 ) {
V_29 = F_148 ( V_110 , V_35 , V_128 , V_17 ,
V_210 , V_151 -> V_22 ,
V_151 -> V_33 , V_128 -> V_132 ,
V_129 ) ;
} else if ( V_128 -> V_211 == V_212 ) {
V_29 = F_155 ( V_110 , V_35 , V_128 , V_17 ,
V_210 , V_151 -> V_22 ,
V_151 -> V_33 , V_128 -> V_132 ,
V_129 ) ;
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
if ( V_129 -> V_213 ) {
struct V_138 * V_139 ;
F_30 ( ! ( V_7 & V_144 ) ) ;
V_139 = (struct V_138 * ) ( V_117 + 1 ) ;
F_156 ( V_66 , V_139 , & V_129 -> V_21 ) ;
}
}
static int F_157 ( struct V_109 * V_110 ,
struct V_34 * V_35 ,
struct V_204 * V_128 ,
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
if ( V_110 -> V_214 )
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
V_64 -> V_206 = 1 ;
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
struct V_204 * V_128 ,
struct V_180 * V_129 ,
int V_207 )
{
int V_29 = 0 ;
struct V_215 * V_151 ;
struct V_67 V_209 ;
T_2 V_17 = 0 ;
T_2 V_210 = 0 ;
bool V_173 = F_76 ( V_35 -> V_37 ,
V_121 ) ;
V_151 = F_159 ( V_128 ) ;
F_160 ( V_128 , V_151 , V_128 -> V_211 ) ;
if ( V_128 -> type == V_165 )
V_17 = V_151 -> V_17 ;
V_210 = V_151 -> V_35 ;
V_209 . V_22 = V_128 -> V_27 ;
if ( V_173 ) {
V_209 . V_33 = V_151 -> V_167 ;
V_209 . type = V_85 ;
} else {
V_209 . V_33 = V_128 -> V_36 ;
V_209 . type = V_76 ;
}
F_30 ( V_128 -> V_132 != 1 ) ;
if ( V_128 -> V_211 == V_203 && V_207 ) {
F_30 ( ! V_129 || ! V_129 -> V_130 ) ;
V_29 = F_161 ( V_110 , V_35 ,
V_17 , V_210 ,
V_129 -> V_131 ,
& V_129 -> V_21 ,
V_151 -> V_167 , & V_209 ,
V_128 -> V_201 ) ;
} else if ( V_128 -> V_211 == V_203 ) {
V_29 = F_148 ( V_110 , V_35 , V_128 ,
V_17 , V_210 ,
V_151 -> V_167 , 0 , 1 ,
V_129 ) ;
} else if ( V_128 -> V_211 == V_212 ) {
V_29 = F_155 ( V_110 , V_35 , V_128 ,
V_17 , V_210 ,
V_151 -> V_167 , 0 , 1 , V_129 ) ;
} else {
F_83 () ;
}
return V_29 ;
}
static int F_162 ( struct V_109 * V_110 ,
struct V_34 * V_35 ,
struct V_204 * V_128 ,
struct V_180 * V_129 ,
int V_207 )
{
int V_29 = 0 ;
if ( V_110 -> V_214 ) {
if ( V_207 )
F_163 ( V_35 , V_128 -> V_27 ,
V_128 -> V_36 , 1 ) ;
return 0 ;
}
if ( F_164 ( V_128 ) ) {
struct V_113 * V_104 ;
F_30 ( V_129 ) ;
V_104 = F_165 ( V_128 ) ;
F_166 ( V_128 , V_104 , V_128 -> V_211 ) ;
if ( V_207 ) {
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
V_207 ) ;
else if ( V_128 -> type == V_155 ||
V_128 -> type == V_154 )
V_29 = F_151 ( V_110 , V_35 , V_128 , V_129 ,
V_207 ) ;
else
F_83 () ;
return V_29 ;
}
static inline struct V_204 *
F_168 ( struct V_113 * V_104 )
{
struct V_204 * V_151 ;
if ( F_169 ( & V_104 -> V_216 ) )
return NULL ;
F_170 (ref, &head->ref_list, list) {
if ( V_151 -> V_211 == V_203 )
return V_151 ;
}
return F_171 ( V_104 -> V_216 . V_80 , struct V_204 ,
V_90 ) ;
}
static T_1 int F_172 ( struct V_109 * V_110 ,
struct V_34 * V_35 ,
unsigned long V_44 )
{
struct V_114 * V_115 ;
struct V_204 * V_151 ;
struct V_113 * V_217 = NULL ;
struct V_180 * V_129 ;
struct V_12 * V_37 = V_35 -> V_37 ;
T_6 V_32 = F_173 () ;
int V_29 ;
unsigned long V_8 = 0 ;
unsigned long V_218 = 0 ;
int V_219 = 0 ;
V_115 = & V_110 -> V_127 -> V_115 ;
while ( 1 ) {
if ( ! V_217 ) {
if ( V_8 >= V_44 )
break;
F_11 ( & V_115 -> V_52 ) ;
V_217 = F_174 ( V_110 ) ;
if ( ! V_217 ) {
F_13 ( & V_115 -> V_52 ) ;
break;
}
V_29 = F_175 ( V_110 , V_217 ) ;
F_13 ( & V_115 -> V_52 ) ;
if ( V_29 == - V_178 ) {
V_217 = NULL ;
V_8 ++ ;
continue;
}
}
F_11 ( & V_217 -> V_52 ) ;
V_151 = F_168 ( V_217 ) ;
if ( V_151 && V_151 -> V_220 &&
F_176 ( V_37 , V_115 , V_151 -> V_220 ) ) {
F_13 ( & V_217 -> V_52 ) ;
F_177 ( V_217 ) ;
F_11 ( & V_115 -> V_52 ) ;
V_217 -> V_221 = 0 ;
V_115 -> V_222 ++ ;
F_13 ( & V_115 -> V_52 ) ;
V_217 = NULL ;
F_47 () ;
V_8 ++ ;
continue;
}
V_219 = V_217 -> V_219 ;
V_217 -> V_219 = 0 ;
V_129 = V_217 -> V_129 ;
V_217 -> V_129 = NULL ;
if ( ! V_151 ) {
V_151 = & V_217 -> V_128 ;
if ( V_129 && V_219 ) {
F_178 ( V_129 ) ;
V_129 = NULL ;
}
if ( V_129 ) {
F_13 ( & V_217 -> V_52 ) ;
V_29 = F_157 ( V_110 , V_35 ,
V_151 , V_129 ) ;
F_178 ( V_129 ) ;
if ( V_29 ) {
if ( V_219 )
V_217 -> V_219 = 1 ;
V_217 -> V_221 = 0 ;
F_179 ( V_37 , L_1 , V_29 ) ;
F_177 ( V_217 ) ;
return V_29 ;
}
continue;
}
F_13 ( & V_217 -> V_52 ) ;
F_11 ( & V_115 -> V_52 ) ;
F_11 ( & V_217 -> V_52 ) ;
if ( ! F_169 ( & V_217 -> V_216 ) ||
V_217 -> V_129 ) {
F_13 ( & V_217 -> V_52 ) ;
F_13 ( & V_115 -> V_52 ) ;
continue;
}
V_151 -> V_223 = 0 ;
V_115 -> V_224 -- ;
F_180 ( & V_217 -> V_225 ,
& V_115 -> V_226 ) ;
F_13 ( & V_115 -> V_52 ) ;
} else {
V_218 ++ ;
V_151 -> V_223 = 0 ;
F_181 ( & V_151 -> V_90 ) ;
}
F_182 ( & V_115 -> V_227 ) ;
if ( ! F_164 ( V_151 ) ) {
switch ( V_151 -> V_211 ) {
case V_203 :
case V_228 :
V_217 -> V_128 . V_132 -= V_151 -> V_132 ;
break;
case V_212 :
V_217 -> V_128 . V_132 += V_151 -> V_132 ;
break;
default:
F_8 ( 1 ) ;
}
}
F_13 ( & V_217 -> V_52 ) ;
V_29 = F_162 ( V_110 , V_35 , V_151 , V_129 ,
V_219 ) ;
F_178 ( V_129 ) ;
if ( V_29 ) {
V_217 -> V_221 = 0 ;
F_177 ( V_217 ) ;
F_86 ( V_151 ) ;
F_179 ( V_37 , L_2 , V_29 ) ;
return V_29 ;
}
if ( F_164 ( V_151 ) ) {
if ( V_217 -> V_184 &&
V_217 -> V_229 < 0 ) {
F_11 ( & V_115 -> V_52 ) ;
V_115 -> V_230 -= V_151 -> V_36 ;
F_13 ( & V_115 -> V_52 ) ;
}
F_177 ( V_217 ) ;
V_217 = NULL ;
}
F_86 ( V_151 ) ;
V_8 ++ ;
F_47 () ;
}
if ( V_218 > 0 ) {
T_2 V_231 = F_183 ( F_184 ( F_173 () , V_32 ) ) ;
T_2 V_232 ;
F_11 ( & V_115 -> V_52 ) ;
V_232 = V_37 -> V_233 * 3 + V_231 ;
V_37 -> V_233 = V_232 >> 2 ;
F_13 ( & V_115 -> V_52 ) ;
}
return 0 ;
}
static T_2 F_185 ( struct V_234 * V_35 )
{
struct V_15 * V_30 = V_35 -> V_15 ;
struct V_204 * V_235 ;
int V_236 = 1 ;
T_2 V_237 ;
T_2 V_238 = 0 , V_69 = 0 ;
V_30 = F_186 ( V_35 ) ;
if ( V_30 ) {
V_235 = F_12 ( V_30 , struct V_204 , V_15 ) ;
V_238 = V_235 -> V_27 ;
}
V_30 = F_187 ( V_35 ) ;
if ( V_30 ) {
V_235 = F_12 ( V_30 , struct V_204 , V_15 ) ;
V_69 = V_235 -> V_27 ;
}
V_30 = V_35 -> V_15 ;
while ( V_30 ) {
V_235 = F_12 ( V_30 , struct V_204 , V_15 ) ;
F_8 ( ! V_235 -> V_223 ) ;
V_237 = V_235 -> V_27 ;
if ( V_236 )
V_30 = V_30 -> V_23 ;
else
V_30 = V_30 -> V_24 ;
V_236 = 1 - V_236 ;
}
return V_237 ;
}
static inline T_2 F_188 ( struct V_34 * V_35 , T_2 V_239 )
{
T_2 V_36 ;
V_36 = V_239 * ( sizeof( struct V_116 ) +
sizeof( struct V_163 ) ) ;
if ( ! F_76 ( V_35 -> V_37 , V_121 ) )
V_36 += V_239 * sizeof( struct V_138 ) ;
return F_189 ( V_36 , F_190 ( V_35 ) ) ;
}
T_2 F_191 ( struct V_34 * V_35 , T_2 V_240 )
{
T_2 V_241 ;
T_2 V_242 ;
T_2 V_243 ;
V_241 = F_190 ( V_35 ) - sizeof( struct V_244 ) ;
V_242 = F_192 ( V_241 ,
( T_2 ) F_193 ( V_35 -> V_37 -> V_245 ) ) ;
V_243 = F_192 ( V_240 , V_35 -> V_246 ) ;
V_243 += V_242 - 1 ;
V_243 = F_192 ( V_243 , V_242 ) ;
return V_243 ;
}
int F_194 ( struct V_109 * V_110 ,
struct V_34 * V_35 )
{
struct V_247 * V_248 ;
T_2 V_224 = V_110 -> V_127 -> V_115 . V_222 ;
T_2 V_240 = V_110 -> V_127 -> V_115 . V_230 ;
T_2 V_249 = V_110 -> V_127 -> V_249 ;
T_2 V_36 , V_250 ;
int V_29 = 0 ;
V_36 = F_195 ( V_35 , 1 ) ;
V_224 = F_188 ( V_35 , V_224 ) ;
if ( V_224 > 1 )
V_36 += ( V_224 - 1 ) * V_35 -> V_87 ;
V_36 <<= 1 ;
V_36 += F_191 ( V_35 , V_240 ) * V_35 -> V_87 ;
V_250 = F_195 ( V_35 ,
V_249 ) ;
V_248 = & V_35 -> V_37 -> V_251 ;
if ( V_248 -> V_105 -> V_108 ) {
V_250 <<= 1 ;
V_36 <<= 1 ;
}
F_11 ( & V_248 -> V_52 ) ;
if ( V_248 -> V_10 <= V_36 + V_250 )
V_29 = 1 ;
F_13 ( & V_248 -> V_52 ) ;
return V_29 ;
}
int F_196 ( struct V_109 * V_110 ,
struct V_34 * V_35 )
{
struct V_12 * V_37 = V_35 -> V_37 ;
T_2 V_227 =
F_197 ( & V_110 -> V_127 -> V_115 . V_227 ) ;
T_2 V_252 ;
T_2 V_253 ;
F_2 () ;
V_252 = V_37 -> V_233 ;
V_253 = V_227 * V_252 ;
if ( V_227 * V_252 >= V_254 )
return 1 ;
if ( V_253 >= V_254 / 2 )
return 2 ;
return F_194 ( V_110 , V_35 ) ;
}
static void F_198 ( struct V_60 * V_61 )
{
struct V_255 * V_256 ;
struct V_109 * V_110 ;
int V_29 ;
V_256 = F_32 ( V_61 , struct V_255 , V_61 ) ;
V_110 = F_199 ( V_256 -> V_35 ) ;
if ( F_200 ( V_110 ) ) {
V_256 -> error = F_201 ( V_110 ) ;
goto V_257;
}
V_110 -> V_258 = true ;
V_29 = F_202 ( V_110 , V_256 -> V_35 , V_256 -> V_8 ) ;
if ( V_29 )
V_256 -> error = V_29 ;
V_29 = F_203 ( V_110 , V_256 -> V_35 ) ;
if ( V_29 && ! V_256 -> error )
V_256 -> error = V_29 ;
V_257:
if ( V_256 -> V_258 )
F_204 ( & V_256 -> V_88 ) ;
else
F_9 ( V_256 ) ;
}
int F_205 ( struct V_34 * V_35 ,
unsigned long V_8 , int V_88 )
{
struct V_255 * V_256 ;
int V_29 ;
V_256 = F_206 ( sizeof( * V_256 ) , V_40 ) ;
if ( ! V_256 )
return - V_71 ;
V_256 -> V_35 = V_35 -> V_37 -> V_86 ;
V_256 -> V_8 = V_8 ;
V_256 -> error = 0 ;
if ( V_88 )
V_256 -> V_258 = 1 ;
else
V_256 -> V_258 = 0 ;
F_207 ( & V_256 -> V_88 ) ;
F_58 ( & V_256 -> V_61 , V_259 ,
F_198 , NULL , NULL ) ;
F_66 ( V_35 -> V_37 -> V_260 , & V_256 -> V_61 ) ;
if ( V_88 ) {
F_208 ( & V_256 -> V_88 ) ;
V_29 = V_256 -> error ;
F_9 ( V_256 ) ;
return V_29 ;
}
return 0 ;
}
int F_202 ( struct V_109 * V_110 ,
struct V_34 * V_35 , unsigned long V_8 )
{
struct V_15 * V_128 ;
struct V_114 * V_115 ;
struct V_113 * V_104 ;
int V_29 ;
int V_261 = V_8 == ( unsigned long ) - 1 ;
if ( V_110 -> V_214 )
return 0 ;
if ( V_35 == V_35 -> V_37 -> V_62 )
V_35 = V_35 -> V_37 -> V_86 ;
V_115 = & V_110 -> V_127 -> V_115 ;
if ( V_8 == 0 )
V_8 = F_197 ( & V_115 -> V_227 ) * 2 ;
V_77:
#ifdef F_209
V_115 -> V_262 = F_185 ( & V_115 -> V_35 ) ;
#endif
V_29 = F_172 ( V_110 , V_35 , V_8 ) ;
if ( V_29 < 0 ) {
F_150 ( V_110 , V_35 , V_29 ) ;
return V_29 ;
}
if ( V_261 ) {
if ( ! F_169 ( & V_110 -> V_263 ) )
F_210 ( V_110 , V_35 ) ;
F_11 ( & V_115 -> V_52 ) ;
V_128 = F_186 ( & V_115 -> V_226 ) ;
if ( ! V_128 ) {
F_13 ( & V_115 -> V_52 ) ;
goto V_72;
}
V_8 = ( unsigned long ) - 1 ;
while ( V_128 ) {
V_104 = F_12 ( V_128 , struct V_113 ,
V_225 ) ;
if ( F_164 ( & V_104 -> V_128 ) ) {
struct V_204 * V_151 ;
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
V_128 = F_211 ( V_128 ) ;
}
F_13 ( & V_115 -> V_52 ) ;
F_47 () ;
goto V_77;
}
V_72:
F_212 ( V_110 ) ;
return 0 ;
}
int F_213 ( struct V_109 * V_110 ,
struct V_34 * V_35 ,
T_2 V_27 , T_2 V_36 , T_2 V_7 ,
int V_167 , int V_184 )
{
struct V_180 * V_129 ;
int V_29 ;
V_129 = F_214 () ;
if ( ! V_129 )
return - V_71 ;
V_129 -> V_131 = V_7 ;
V_129 -> V_130 = 1 ;
V_129 -> V_213 = 0 ;
V_129 -> V_184 = V_184 ? 1 : 0 ;
V_129 -> V_167 = V_167 ;
V_29 = F_215 ( V_35 -> V_37 , V_110 , V_27 ,
V_36 , V_129 ) ;
if ( V_29 )
F_178 ( V_129 ) ;
return V_29 ;
}
static T_1 int F_216 ( struct V_109 * V_110 ,
struct V_34 * V_35 ,
struct V_63 * V_64 ,
T_2 V_22 , T_2 V_33 , T_2 V_27 )
{
struct V_113 * V_104 ;
struct V_204 * V_151 ;
struct V_208 * V_264 ;
struct V_114 * V_115 ;
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
F_170 (ref, &head->ref_list, list) {
if ( V_151 -> type != V_155 ) {
V_29 = 1 ;
break;
}
V_264 = F_152 ( V_151 ) ;
if ( V_264 -> V_35 != V_35 -> V_265 . V_22 ||
V_264 -> V_22 != V_22 ||
V_264 -> V_33 != V_33 ) {
V_29 = 1 ;
break;
}
}
F_13 ( & V_104 -> V_52 ) ;
F_46 ( & V_104 -> V_78 ) ;
return V_29 ;
}
static T_1 int F_217 ( struct V_109 * V_110 ,
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
if ( F_218 ( V_66 , V_117 ) <=
F_219 ( & V_35 -> V_266 ) )
goto V_72;
V_164 = (struct V_163 * ) ( V_117 + 1 ) ;
if ( F_119 ( V_66 , V_164 ) !=
V_155 )
goto V_72;
V_151 = (struct V_150 * ) ( & V_164 -> V_33 ) ;
if ( F_79 ( V_66 , V_117 ) !=
F_113 ( V_66 , V_151 ) ||
F_100 ( V_66 , V_151 ) !=
V_35 -> V_265 . V_22 ||
F_101 ( V_66 , V_151 ) != V_22 ||
F_102 ( V_66 , V_151 ) != V_33 )
goto V_72;
V_29 = 0 ;
V_72:
return V_29 ;
}
int F_220 ( struct V_109 * V_110 ,
struct V_34 * V_35 ,
T_2 V_22 , T_2 V_33 , T_2 V_27 )
{
struct V_63 * V_64 ;
int V_29 ;
int V_267 ;
V_64 = F_33 () ;
if ( ! V_64 )
return - V_153 ;
do {
V_29 = F_217 ( V_110 , V_35 , V_64 , V_22 ,
V_33 , V_27 ) ;
if ( V_29 && V_29 != - V_153 )
goto V_72;
V_267 = F_216 ( V_110 , V_35 , V_64 , V_22 ,
V_33 , V_27 ) ;
} while ( V_267 == - V_178 );
if ( V_267 && V_267 != - V_153 ) {
V_29 = V_267 ;
goto V_72;
}
if ( V_29 != - V_153 || V_267 != - V_153 )
V_29 = 0 ;
V_72:
F_50 ( V_64 ) ;
if ( V_35 -> V_265 . V_22 == V_268 )
F_8 ( V_29 > 0 ) ;
return V_29 ;
}
static int F_221 ( struct V_109 * V_110 ,
struct V_34 * V_35 ,
struct V_65 * V_269 ,
int V_270 , int V_271 )
{
T_2 V_27 ;
T_2 V_36 ;
T_2 V_17 ;
T_2 V_210 ;
T_3 V_70 ;
struct V_67 V_21 ;
struct V_272 * V_273 ;
int V_43 ;
int V_167 ;
int V_29 = 0 ;
int (* F_222)( struct V_109 * , struct V_34 * ,
T_2 , T_2 , T_2 , T_2 , T_2 , T_2 , int );
if ( F_223 ( V_35 ) )
return 0 ;
V_210 = F_224 ( V_269 ) ;
V_70 = F_38 ( V_269 ) ;
V_167 = F_225 ( V_269 ) ;
if ( ! F_226 ( V_274 , & V_35 -> V_275 ) && V_167 == 0 )
return 0 ;
if ( V_271 )
F_222 = F_145 ;
else
F_222 = V_276 ;
if ( V_270 )
V_17 = V_269 -> V_32 ;
else
V_17 = 0 ;
for ( V_43 = 0 ; V_43 < V_70 ; V_43 ++ ) {
if ( V_167 == 0 ) {
F_40 ( V_269 , & V_21 , V_43 ) ;
if ( V_21 . type != V_277 )
continue;
V_273 = F_78 ( V_269 , V_43 ,
struct V_272 ) ;
if ( F_227 ( V_269 , V_273 ) ==
V_278 )
continue;
V_27 = F_228 ( V_269 , V_273 ) ;
if ( V_27 == 0 )
continue;
V_36 = F_229 ( V_269 , V_273 ) ;
V_21 . V_33 -= F_230 ( V_269 , V_273 ) ;
V_29 = F_222 ( V_110 , V_35 , V_27 , V_36 ,
V_17 , V_210 , V_21 . V_22 ,
V_21 . V_33 , 1 ) ;
if ( V_29 )
goto V_156;
} else {
V_27 = F_231 ( V_269 , V_43 ) ;
V_36 = V_35 -> V_87 ;
V_29 = F_222 ( V_110 , V_35 , V_27 , V_36 ,
V_17 , V_210 , V_167 - 1 , 0 ,
1 ) ;
if ( V_29 )
goto V_156;
}
}
return 0 ;
V_156:
return V_29 ;
}
int F_232 ( struct V_109 * V_110 , struct V_34 * V_35 ,
struct V_65 * V_269 , int V_270 )
{
return F_221 ( V_110 , V_35 , V_269 , V_270 , 1 ) ;
}
int F_233 ( struct V_109 * V_110 , struct V_34 * V_35 ,
struct V_65 * V_269 , int V_270 )
{
return F_221 ( V_110 , V_35 , V_269 , V_270 , 0 ) ;
}
static int F_234 ( struct V_109 * V_110 ,
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
V_139 = F_235 ( V_66 , V_64 -> V_83 [ 0 ] ) ;
F_236 ( V_66 , & V_2 -> V_135 , V_139 , sizeof( V_2 -> V_135 ) ) ;
F_95 ( V_66 ) ;
V_156:
F_44 ( V_64 ) ;
return V_29 ;
}
static struct V_1 *
F_237 ( struct V_34 * V_35 ,
struct V_1 * V_2 )
{
struct V_15 * V_128 ;
F_11 ( & V_35 -> V_37 -> V_18 ) ;
if ( F_238 ( & V_2 -> V_20 ) ) {
const T_2 V_279 = V_2 -> V_21 . V_22 + V_2 -> V_21 . V_33 ;
F_13 ( & V_35 -> V_37 -> V_18 ) ;
F_6 ( V_2 ) ;
V_2 = F_67 ( V_35 -> V_37 ,
V_279 ) ;
return V_2 ;
}
V_128 = F_211 ( & V_2 -> V_20 ) ;
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
static int F_239 ( struct V_1 * V_14 ,
struct V_109 * V_110 ,
struct V_63 * V_64 )
{
struct V_34 * V_35 = V_14 -> V_37 -> V_86 ;
struct V_280 * V_280 = NULL ;
T_2 V_281 = 0 ;
int V_282 = V_283 ;
T_2 V_284 = 0 ;
int V_285 = 0 ;
int V_29 = 0 ;
if ( V_14 -> V_21 . V_33 < ( 100 * 1024 * 1024 ) ) {
F_11 ( & V_14 -> V_52 ) ;
V_14 -> V_286 = V_287 ;
F_13 ( & V_14 -> V_52 ) ;
return 0 ;
}
if ( V_110 -> V_214 )
return 0 ;
V_77:
V_280 = F_240 ( V_35 , V_14 , V_64 ) ;
if ( F_200 ( V_280 ) && F_201 ( V_280 ) != - V_153 ) {
V_29 = F_201 ( V_280 ) ;
F_44 ( V_64 ) ;
goto V_72;
}
if ( F_200 ( V_280 ) ) {
F_30 ( V_285 ) ;
V_285 ++ ;
if ( V_14 -> V_288 )
goto V_123;
V_29 = F_241 ( V_35 , V_110 , V_14 , V_64 ) ;
if ( V_29 )
goto V_123;
goto V_77;
}
if ( V_14 -> V_289 == V_110 -> V_290 &&
F_242 ( V_280 ) ) {
V_282 = V_291 ;
goto V_292;
}
F_243 ( V_280 ) -> V_293 = 0 ;
V_29 = F_244 ( V_110 , V_35 , V_280 ) ;
if ( V_29 ) {
F_150 ( V_110 , V_35 , V_29 ) ;
goto V_292;
}
F_8 ( V_29 ) ;
if ( F_242 ( V_280 ) > 0 ) {
V_29 = F_245 ( V_35 ,
& V_35 -> V_37 -> V_251 ) ;
if ( V_29 )
goto V_292;
V_29 = F_246 ( V_35 , V_110 , NULL , V_280 ) ;
if ( V_29 )
goto V_292;
}
F_11 ( & V_14 -> V_52 ) ;
if ( V_14 -> V_3 != V_4 ||
! F_247 ( V_35 , V_294 ) ) {
V_282 = V_287 ;
F_13 ( & V_14 -> V_52 ) ;
goto V_292;
}
F_13 ( & V_14 -> V_52 ) ;
V_284 = F_189 ( V_14 -> V_21 . V_33 , 256 * 1024 * 1024 ) ;
if ( ! V_284 )
V_284 = 1 ;
V_284 *= 16 ;
V_284 *= V_295 ;
V_29 = F_248 ( V_280 , V_284 , V_284 ) ;
if ( V_29 )
goto V_292;
V_29 = F_249 ( V_280 , V_110 , 0 , 0 , V_284 ,
V_284 , V_284 ,
& V_281 ) ;
if ( ! V_29 )
V_282 = V_291 ;
F_250 ( V_280 , V_284 ) ;
V_292:
F_251 ( V_280 ) ;
V_123:
F_44 ( V_64 ) ;
V_72:
F_11 ( & V_14 -> V_52 ) ;
if ( ! V_29 && V_282 == V_291 )
V_14 -> V_289 = V_110 -> V_290 ;
V_14 -> V_286 = V_282 ;
F_13 ( & V_14 -> V_52 ) ;
return V_29 ;
}
int F_252 ( struct V_109 * V_110 ,
struct V_34 * V_35 )
{
struct V_1 * V_2 , * V_296 ;
struct V_297 * V_298 = V_110 -> V_127 ;
struct V_63 * V_64 ;
if ( F_169 ( & V_298 -> V_299 ) ||
! F_247 ( V_35 , V_294 ) )
return 0 ;
V_64 = F_33 () ;
if ( ! V_64 )
return - V_71 ;
F_253 (cache, tmp, &cur_trans->dirty_bgs,
dirty_list) {
if ( V_2 -> V_286 == V_300 )
F_239 ( V_2 , V_110 , V_64 ) ;
}
F_50 ( V_64 ) ;
return 0 ;
}
int F_254 ( struct V_109 * V_110 ,
struct V_34 * V_35 )
{
struct V_1 * V_2 ;
struct V_297 * V_298 = V_110 -> V_127 ;
int V_29 = 0 ;
int V_301 ;
struct V_63 * V_64 = NULL ;
F_255 ( V_302 ) ;
struct V_103 * V_303 = & V_298 -> V_304 ;
int V_305 = 0 ;
int V_306 = 0 ;
F_11 ( & V_298 -> V_307 ) ;
if ( F_169 ( & V_298 -> V_299 ) ) {
F_13 ( & V_298 -> V_307 ) ;
return 0 ;
}
F_256 ( & V_298 -> V_299 , & V_302 ) ;
F_13 ( & V_298 -> V_307 ) ;
V_77:
F_210 ( V_110 , V_35 ) ;
if ( ! V_64 ) {
V_64 = F_33 () ;
if ( ! V_64 )
return - V_71 ;
}
F_35 ( & V_110 -> V_127 -> V_308 ) ;
while ( ! F_169 ( & V_302 ) ) {
V_2 = F_257 ( & V_302 ,
struct V_1 ,
V_309 ) ;
if ( ! F_169 ( & V_2 -> V_310 ) ) {
F_258 ( & V_2 -> V_310 ) ;
F_259 ( V_35 , V_110 , V_2 ,
& V_2 -> V_311 , V_64 ,
V_2 -> V_21 . V_22 ) ;
F_6 ( V_2 ) ;
}
F_11 ( & V_298 -> V_307 ) ;
F_258 ( & V_2 -> V_309 ) ;
F_13 ( & V_298 -> V_307 ) ;
V_301 = 1 ;
F_239 ( V_2 , V_110 , V_64 ) ;
if ( V_2 -> V_286 == V_291 ) {
V_2 -> V_311 . V_280 = NULL ;
V_29 = F_260 ( V_35 , V_110 , V_2 , V_64 ) ;
if ( V_29 == 0 && V_2 -> V_311 . V_280 ) {
V_305 ++ ;
V_301 = 0 ;
F_64 ( & V_2 -> V_310 , V_303 ) ;
} else {
V_29 = 0 ;
}
}
if ( ! V_29 ) {
V_29 = F_234 ( V_110 , V_35 , V_64 , V_2 ) ;
if ( V_29 == - V_153 ) {
V_29 = 0 ;
F_11 ( & V_298 -> V_307 ) ;
if ( F_169 ( & V_2 -> V_309 ) ) {
F_64 ( & V_2 -> V_309 ,
& V_298 -> V_299 ) ;
F_4 ( V_2 ) ;
}
F_13 ( & V_298 -> V_307 ) ;
} else if ( V_29 ) {
F_150 ( V_110 , V_35 , V_29 ) ;
}
}
if ( V_301 )
F_6 ( V_2 ) ;
if ( V_29 )
break;
F_46 ( & V_110 -> V_127 -> V_308 ) ;
F_35 ( & V_110 -> V_127 -> V_308 ) ;
}
F_46 ( & V_110 -> V_127 -> V_308 ) ;
V_29 = F_202 ( V_110 , V_35 , 0 ) ;
if ( ! V_29 && V_306 == 0 ) {
V_306 ++ ;
F_11 ( & V_298 -> V_307 ) ;
F_256 ( & V_298 -> V_299 , & V_302 ) ;
if ( ! F_169 ( & V_302 ) ) {
F_13 ( & V_298 -> V_307 ) ;
goto V_77;
}
F_13 ( & V_298 -> V_307 ) ;
}
F_50 ( V_64 ) ;
return V_29 ;
}
int F_261 ( struct V_109 * V_110 ,
struct V_34 * V_35 )
{
struct V_1 * V_2 ;
struct V_297 * V_298 = V_110 -> V_127 ;
int V_29 = 0 ;
int V_301 ;
struct V_63 * V_64 ;
struct V_103 * V_303 = & V_298 -> V_304 ;
int V_305 = 0 ;
V_64 = F_33 () ;
if ( ! V_64 )
return - V_71 ;
while ( ! F_169 ( & V_298 -> V_299 ) ) {
V_2 = F_257 ( & V_298 -> V_299 ,
struct V_1 ,
V_309 ) ;
if ( ! F_169 ( & V_2 -> V_310 ) ) {
F_258 ( & V_2 -> V_310 ) ;
F_259 ( V_35 , V_110 , V_2 ,
& V_2 -> V_311 , V_64 ,
V_2 -> V_21 . V_22 ) ;
F_6 ( V_2 ) ;
}
F_258 ( & V_2 -> V_309 ) ;
V_301 = 1 ;
F_239 ( V_2 , V_110 , V_64 ) ;
if ( ! V_29 )
V_29 = F_202 ( V_110 , V_35 , ( unsigned long ) - 1 ) ;
if ( ! V_29 && V_2 -> V_286 == V_291 ) {
V_2 -> V_311 . V_280 = NULL ;
V_29 = F_260 ( V_35 , V_110 , V_2 , V_64 ) ;
if ( V_29 == 0 && V_2 -> V_311 . V_280 ) {
V_305 ++ ;
V_301 = 0 ;
F_64 ( & V_2 -> V_310 , V_303 ) ;
} else {
V_29 = 0 ;
}
}
if ( ! V_29 ) {
V_29 = F_234 ( V_110 , V_35 , V_64 , V_2 ) ;
if ( V_29 )
F_150 ( V_110 , V_35 , V_29 ) ;
}
if ( V_301 )
F_6 ( V_2 ) ;
}
while ( ! F_169 ( V_303 ) ) {
V_2 = F_257 ( V_303 , struct V_1 ,
V_310 ) ;
F_258 ( & V_2 -> V_310 ) ;
F_259 ( V_35 , V_110 , V_2 ,
& V_2 -> V_311 , V_64 , V_2 -> V_21 . V_22 ) ;
F_6 ( V_2 ) ;
}
F_50 ( V_64 ) ;
return V_29 ;
}
int F_262 ( struct V_34 * V_35 , T_2 V_27 )
{
struct V_1 * V_14 ;
int V_312 = 0 ;
V_14 = F_68 ( V_35 -> V_37 , V_27 ) ;
if ( ! V_14 || V_14 -> V_288 )
V_312 = 1 ;
if ( V_14 )
F_6 ( V_14 ) ;
return V_312 ;
}
static const char * F_263 ( T_2 V_7 )
{
switch ( V_7 ) {
case V_313 | V_314 :
return L_3 ;
case V_313 :
return L_4 ;
case V_314 :
return L_5 ;
case V_315 :
return L_6 ;
default:
F_8 ( 1 ) ;
return L_7 ;
} ;
}
static int F_264 ( struct V_12 * V_13 , T_2 V_7 ,
T_2 V_316 , T_2 V_317 ,
struct V_102 * * V_105 )
{
struct V_102 * V_106 ;
int V_43 ;
int V_318 ;
int V_29 ;
if ( V_7 & ( V_319 | V_320 |
V_321 ) )
V_318 = 2 ;
else
V_318 = 1 ;
V_106 = F_69 ( V_13 , V_7 ) ;
if ( V_106 ) {
F_11 ( & V_106 -> V_52 ) ;
V_106 -> V_316 += V_316 ;
V_106 -> V_322 += V_316 * V_318 ;
V_106 -> V_317 += V_317 ;
V_106 -> V_323 += V_317 * V_318 ;
if ( V_316 > 0 )
V_106 -> V_108 = 0 ;
F_13 ( & V_106 -> V_52 ) ;
* V_105 = V_106 ;
return 0 ;
}
V_106 = F_53 ( sizeof( * V_106 ) , V_40 ) ;
if ( ! V_106 )
return - V_71 ;
V_29 = F_265 ( & V_106 -> V_324 , 0 , V_325 ) ;
if ( V_29 ) {
F_9 ( V_106 ) ;
return V_29 ;
}
for ( V_43 = 0 ; V_43 < V_326 ; V_43 ++ )
F_54 ( & V_106 -> V_327 [ V_43 ] ) ;
F_266 ( & V_106 -> V_328 ) ;
F_267 ( & V_106 -> V_52 ) ;
V_106 -> V_7 = V_7 & V_107 ;
V_106 -> V_316 = V_316 ;
V_106 -> V_322 = V_316 * V_318 ;
V_106 -> V_317 = V_317 ;
V_106 -> V_323 = V_317 * V_318 ;
V_106 -> V_329 = 0 ;
V_106 -> V_330 = 0 ;
V_106 -> V_331 = 0 ;
V_106 -> V_332 = 0 ;
if ( V_316 > 0 )
V_106 -> V_108 = 0 ;
else
V_106 -> V_108 = 1 ;
V_106 -> V_333 = V_334 ;
V_106 -> V_335 = 0 ;
V_106 -> V_336 = 0 ;
F_56 ( & V_106 -> V_88 ) ;
F_54 ( & V_106 -> V_337 ) ;
V_29 = F_268 ( & V_106 -> V_338 , & V_339 ,
V_13 -> V_340 , L_8 ,
F_263 ( V_106 -> V_7 ) ) ;
if ( V_29 ) {
F_9 ( V_106 ) ;
return V_29 ;
}
* V_105 = V_106 ;
F_269 ( & V_106 -> V_90 , & V_13 -> V_105 ) ;
if ( V_7 & V_314 )
V_13 -> V_341 = V_106 ;
return V_29 ;
}
static void F_270 ( struct V_12 * V_37 , T_2 V_7 )
{
T_2 V_342 = F_271 ( V_7 ) &
V_343 ;
F_272 ( & V_37 -> V_344 ) ;
if ( V_7 & V_314 )
V_37 -> V_345 |= V_342 ;
if ( V_7 & V_313 )
V_37 -> V_346 |= V_342 ;
if ( V_7 & V_315 )
V_37 -> V_347 |= V_342 ;
F_273 ( & V_37 -> V_344 ) ;
}
static T_2 F_274 ( struct V_12 * V_37 , T_2 V_7 )
{
struct V_348 * V_349 = V_37 -> V_350 ;
T_2 V_351 = 0 ;
if ( ! V_349 )
return 0 ;
if ( V_7 & V_314 &&
V_349 -> V_352 . V_7 & V_353 ) {
V_351 = V_314 | V_349 -> V_352 . V_351 ;
} else if ( V_7 & V_315 &&
V_349 -> V_354 . V_7 & V_353 ) {
V_351 = V_315 | V_349 -> V_354 . V_351 ;
} else if ( V_7 & V_313 &&
V_349 -> V_355 . V_7 & V_353 ) {
V_351 = V_313 | V_349 -> V_355 . V_351 ;
}
return V_351 ;
}
static T_2 F_275 ( struct V_34 * V_35 , T_2 V_7 )
{
T_2 V_356 = V_35 -> V_37 -> V_357 -> V_358 ;
T_2 V_351 ;
T_2 V_296 ;
F_11 ( & V_35 -> V_37 -> V_359 ) ;
V_351 = F_274 ( V_35 -> V_37 , V_7 ) ;
if ( V_351 ) {
if ( ( V_7 & V_351 ) & V_343 ) {
F_13 ( & V_35 -> V_37 -> V_359 ) ;
return F_276 ( V_351 ) ;
}
}
F_13 ( & V_35 -> V_37 -> V_359 ) ;
if ( V_356 == 1 )
V_7 &= ~ ( V_320 | V_360 |
V_361 ) ;
if ( V_356 < 3 )
V_7 &= ~ V_362 ;
if ( V_356 < 4 )
V_7 &= ~ V_321 ;
V_296 = V_7 & ( V_319 | V_360 |
V_320 | V_361 |
V_362 | V_321 ) ;
V_7 &= ~ V_296 ;
if ( V_296 & V_362 )
V_296 = V_362 ;
else if ( V_296 & V_361 )
V_296 = V_361 ;
else if ( V_296 & V_321 )
V_296 = V_321 ;
else if ( V_296 & V_320 )
V_296 = V_320 ;
else if ( V_296 & V_360 )
V_296 = V_360 ;
return F_276 ( V_7 | V_296 ) ;
}
static T_2 F_277 ( struct V_34 * V_35 , T_2 V_363 )
{
unsigned V_220 ;
T_2 V_7 ;
do {
V_7 = V_363 ;
V_220 = F_278 ( & V_35 -> V_37 -> V_344 ) ;
if ( V_7 & V_314 )
V_7 |= V_35 -> V_37 -> V_345 ;
else if ( V_7 & V_315 )
V_7 |= V_35 -> V_37 -> V_347 ;
else if ( V_7 & V_313 )
V_7 |= V_35 -> V_37 -> V_346 ;
} while ( F_279 ( & V_35 -> V_37 -> V_344 , V_220 ) );
return F_275 ( V_35 , V_7 ) ;
}
T_2 F_280 ( struct V_34 * V_35 , int V_352 )
{
T_2 V_7 ;
T_2 V_29 ;
if ( V_352 )
V_7 = V_314 ;
else if ( V_35 == V_35 -> V_37 -> V_364 )
V_7 = V_315 ;
else
V_7 = V_313 ;
V_29 = F_277 ( V_35 , V_7 ) ;
return V_29 ;
}
int F_248 ( struct V_280 * V_280 , T_2 V_365 , T_2 V_366 )
{
struct V_102 * V_341 ;
struct V_34 * V_35 = F_243 ( V_280 ) -> V_35 ;
struct V_12 * V_37 = V_35 -> V_37 ;
T_2 V_367 ;
int V_29 = 0 ;
int V_368 = 2 ;
int V_369 ;
V_365 = F_281 ( V_365 , V_35 -> V_246 ) ;
if ( F_282 ( V_280 ) ) {
V_368 = 0 ;
ASSERT ( V_370 -> V_371 ) ;
}
V_341 = V_37 -> V_341 ;
if ( ! V_341 )
goto V_372;
V_77:
F_11 ( & V_341 -> V_52 ) ;
V_367 = V_341 -> V_317 + V_341 -> V_330 +
V_341 -> V_329 + V_341 -> V_331 +
V_341 -> V_332 ;
if ( V_367 + V_365 > V_341 -> V_316 ) {
struct V_109 * V_110 ;
if ( ! V_341 -> V_108 ) {
T_2 V_373 ;
V_341 -> V_333 = V_374 ;
F_13 ( & V_341 -> V_52 ) ;
V_372:
V_373 = F_280 ( V_35 , 1 ) ;
V_110 = F_199 ( V_35 ) ;
if ( F_200 ( V_110 ) )
return F_201 ( V_110 ) ;
V_29 = F_283 ( V_110 , V_35 -> V_37 -> V_62 ,
V_373 ,
V_334 ) ;
F_203 ( V_110 , V_35 ) ;
if ( V_29 < 0 ) {
if ( V_29 != - V_375 )
return V_29 ;
else {
V_369 = 1 ;
goto V_376;
}
}
if ( ! V_341 )
V_341 = V_37 -> V_341 ;
goto V_77;
}
V_369 = F_284 (
& V_341 -> V_324 ,
V_367 + V_365 - V_341 -> V_316 ) ;
F_13 ( & V_341 -> V_52 ) ;
V_376:
if ( V_368 &&
! F_197 ( & V_35 -> V_37 -> V_377 ) ) {
V_368 -- ;
if ( V_368 > 0 )
F_285 ( V_37 , - 1 ) ;
V_110 = F_199 ( V_35 ) ;
if ( F_200 ( V_110 ) )
return F_201 ( V_110 ) ;
if ( V_369 >= 0 ||
V_110 -> V_127 -> V_378 ||
V_368 > 0 ) {
V_29 = F_286 ( V_110 , V_35 ) ;
if ( V_29 )
return V_29 ;
F_63 ( & V_35 -> V_37 -> V_379 ) ;
F_65 ( & V_35 -> V_37 -> V_379 ) ;
goto V_77;
} else {
F_203 ( V_110 , V_35 ) ;
}
}
F_287 ( V_35 -> V_37 ,
L_9 ,
V_341 -> V_7 , V_365 , 1 ) ;
return - V_375 ;
}
V_29 = F_288 ( V_35 , V_366 ) ;
if ( V_29 )
goto V_72;
V_341 -> V_332 += V_365 ;
F_287 ( V_35 -> V_37 , L_10 ,
V_341 -> V_7 , V_365 , 1 ) ;
V_72:
F_13 ( & V_341 -> V_52 ) ;
return V_29 ;
}
void F_250 ( struct V_280 * V_280 , T_2 V_365 )
{
struct V_34 * V_35 = F_243 ( V_280 ) -> V_35 ;
struct V_102 * V_341 ;
V_365 = F_281 ( V_365 , V_35 -> V_246 ) ;
V_341 = V_35 -> V_37 -> V_341 ;
F_11 ( & V_341 -> V_52 ) ;
F_8 ( V_341 -> V_332 < V_365 ) ;
V_341 -> V_332 -= V_365 ;
F_287 ( V_35 -> V_37 , L_10 ,
V_341 -> V_7 , V_365 , 0 ) ;
F_13 ( & V_341 -> V_52 ) ;
}
static void F_289 ( struct V_12 * V_13 )
{
struct V_103 * V_104 = & V_13 -> V_105 ;
struct V_102 * V_106 ;
F_70 () ;
F_71 (found, head, list) {
if ( V_106 -> V_7 & V_313 )
V_106 -> V_333 = V_374 ;
}
F_72 () ;
}
static inline T_2 F_290 ( struct V_247 * V_380 )
{
return ( V_380 -> V_56 << 1 ) ;
}
static int F_291 ( struct V_34 * V_35 ,
struct V_102 * V_381 , int V_382 )
{
struct V_247 * V_248 = & V_35 -> V_37 -> V_251 ;
T_2 V_36 = V_381 -> V_316 - V_381 -> V_331 ;
T_2 V_383 = V_381 -> V_317 + V_381 -> V_330 ;
T_2 V_384 ;
if ( V_382 == V_374 )
return 1 ;
if ( V_381 -> V_7 & V_313 )
V_383 += F_290 ( V_248 ) ;
if ( V_382 == V_385 ) {
V_384 = F_292 ( V_35 -> V_37 -> V_245 ) ;
V_384 = F_34 ( T_2 , 64 * 1024 * 1024 ,
F_293 ( V_384 , 1 ) ) ;
if ( V_36 - V_383 < V_384 )
return 1 ;
}
if ( V_383 + 2 * 1024 * 1024 < F_294 ( V_36 , 8 ) )
return 0 ;
return 1 ;
}
static T_2 F_295 ( struct V_34 * V_35 , T_2 type )
{
T_2 V_386 ;
if ( type & ( V_321 |
V_360 |
V_361 |
V_362 ) )
V_386 = V_35 -> V_37 -> V_357 -> V_358 ;
else if ( type & V_320 )
V_386 = 2 ;
else
V_386 = 1 ;
return V_386 ;
}
void F_296 ( struct V_109 * V_110 ,
struct V_34 * V_35 ,
T_2 type )
{
struct V_102 * V_13 ;
T_2 V_387 ;
T_2 V_384 ;
int V_29 = 0 ;
T_2 V_388 ;
ASSERT ( F_297 ( & V_35 -> V_37 -> V_389 ) ) ;
V_13 = F_69 ( V_35 -> V_37 , V_315 ) ;
F_11 ( & V_13 -> V_52 ) ;
V_387 = V_13 -> V_316 - V_13 -> V_317 - V_13 -> V_329 -
V_13 -> V_330 - V_13 -> V_331 -
V_13 -> V_332 ;
F_13 ( & V_13 -> V_52 ) ;
V_388 = F_295 ( V_35 , type ) ;
V_384 = F_298 ( V_35 , V_388 ) +
F_195 ( V_35 , 1 ) ;
if ( V_387 < V_384 && F_247 ( V_35 , V_390 ) ) {
F_299 ( V_35 -> V_37 , L_11 ,
V_387 , V_384 , type ) ;
F_300 ( V_13 , 0 , 0 ) ;
}
if ( V_387 < V_384 ) {
T_2 V_7 ;
V_7 = F_280 ( V_35 -> V_37 -> V_364 , 0 ) ;
V_29 = F_301 ( V_110 , V_35 , V_7 ) ;
}
if ( ! V_29 ) {
V_29 = F_302 ( V_35 -> V_37 -> V_364 ,
& V_35 -> V_37 -> V_391 ,
V_384 , V_392 ) ;
if ( ! V_29 )
V_110 -> V_393 += V_384 ;
}
}
static int F_283 ( struct V_109 * V_110 ,
struct V_34 * V_62 , T_2 V_7 , int V_382 )
{
struct V_102 * V_105 ;
struct V_12 * V_37 = V_62 -> V_37 ;
int V_394 = 0 ;
int V_29 = 0 ;
if ( V_110 -> V_395 )
return - V_375 ;
V_105 = F_69 ( V_62 -> V_37 , V_7 ) ;
if ( ! V_105 ) {
V_29 = F_264 ( V_62 -> V_37 , V_7 ,
0 , 0 , & V_105 ) ;
F_30 ( V_29 ) ;
}
F_30 ( ! V_105 ) ;
V_77:
F_11 ( & V_105 -> V_52 ) ;
if ( V_382 < V_105 -> V_333 )
V_382 = V_105 -> V_333 ;
if ( V_105 -> V_108 ) {
if ( F_291 ( V_62 , V_105 , V_382 ) )
V_29 = - V_375 ;
else
V_29 = 0 ;
F_13 ( & V_105 -> V_52 ) ;
return V_29 ;
}
if ( ! F_291 ( V_62 , V_105 , V_382 ) ) {
F_13 ( & V_105 -> V_52 ) ;
return 0 ;
} else if ( V_105 -> V_335 ) {
V_394 = 1 ;
} else {
V_105 -> V_335 = 1 ;
}
F_13 ( & V_105 -> V_52 ) ;
F_35 ( & V_37 -> V_389 ) ;
if ( V_394 ) {
F_46 ( & V_37 -> V_389 ) ;
V_394 = 0 ;
goto V_77;
}
V_110 -> V_395 = true ;
if ( F_303 ( V_105 ) )
V_7 |= ( V_314 | V_313 ) ;
if ( V_7 & V_314 && V_37 -> V_396 ) {
V_37 -> V_397 ++ ;
if ( ! ( V_37 -> V_397 %
V_37 -> V_396 ) )
F_289 ( V_37 ) ;
}
F_296 ( V_110 , V_62 , V_7 ) ;
V_29 = F_301 ( V_110 , V_62 , V_7 ) ;
V_110 -> V_395 = false ;
F_11 ( & V_105 -> V_52 ) ;
if ( V_29 < 0 && V_29 != - V_375 )
goto V_72;
if ( V_29 )
V_105 -> V_108 = 1 ;
else
V_29 = 1 ;
V_105 -> V_333 = V_334 ;
V_72:
V_105 -> V_335 = 0 ;
F_13 ( & V_105 -> V_52 ) ;
F_46 ( & V_37 -> V_389 ) ;
if ( V_110 -> V_393 >= ( 2 * 1024 * 1024ull ) ) {
F_210 ( V_110 , V_110 -> V_35 ) ;
F_304 ( V_110 ) ;
}
return V_29 ;
}
static int F_305 ( struct V_34 * V_35 ,
struct V_102 * V_105 , T_2 V_365 ,
enum V_398 V_336 )
{
struct V_247 * V_248 = & V_35 -> V_37 -> V_251 ;
T_2 V_399 = F_280 ( V_35 , 0 ) ;
T_2 V_400 ;
T_2 V_401 ;
T_2 V_367 ;
V_367 = V_105 -> V_317 + V_105 -> V_330 +
V_105 -> V_329 + V_105 -> V_331 ;
F_11 ( & V_248 -> V_52 ) ;
V_400 = F_290 ( V_248 ) ;
F_13 ( & V_248 -> V_52 ) ;
if ( V_367 + V_400 >= V_105 -> V_316 )
return 0 ;
V_367 += V_105 -> V_332 ;
F_11 ( & V_35 -> V_37 -> V_402 ) ;
V_401 = V_35 -> V_37 -> V_403 ;
F_13 ( & V_35 -> V_37 -> V_402 ) ;
if ( V_399 & ( V_319 |
V_320 |
V_321 ) )
V_401 >>= 1 ;
if ( V_336 == V_404 )
V_401 >>= 3 ;
else
V_401 >>= 1 ;
if ( V_367 + V_365 < V_105 -> V_316 + V_401 )
return 1 ;
return 0 ;
}
static void F_306 ( struct V_34 * V_35 ,
unsigned long V_405 , int V_406 )
{
struct V_407 * V_408 = V_35 -> V_37 -> V_408 ;
if ( F_307 ( & V_408 -> V_409 ) ) {
F_308 ( V_408 , V_405 , V_410 ) ;
F_45 ( & V_408 -> V_409 ) ;
} else {
F_309 ( V_35 -> V_37 , 0 , V_406 ) ;
if ( ! V_370 -> V_371 )
F_285 ( V_35 -> V_37 , V_406 ) ;
}
}
static inline int F_310 ( struct V_34 * V_35 , T_2 V_411 )
{
T_2 V_365 ;
int V_44 ;
V_365 = F_195 ( V_35 , 1 ) ;
V_44 = ( int ) F_192 ( V_411 , V_365 ) ;
if ( ! V_44 )
V_44 = 1 ;
return V_44 ;
}
static void F_311 ( struct V_34 * V_35 , T_2 V_411 , T_2 V_412 ,
bool V_413 )
{
struct V_247 * V_414 ;
struct V_102 * V_105 ;
struct V_109 * V_110 ;
T_2 V_415 ;
T_2 V_416 ;
long V_417 ;
unsigned long V_405 ;
int V_306 ;
int V_418 ;
enum V_398 V_336 ;
V_418 = F_310 ( V_35 , V_411 ) ;
V_411 = V_418 * V_419 ;
V_110 = (struct V_109 * ) V_370 -> V_371 ;
V_414 = & V_35 -> V_37 -> V_420 ;
V_105 = V_414 -> V_105 ;
V_415 = F_312 (
& V_35 -> V_37 -> V_415 ) ;
if ( V_415 == 0 ) {
if ( V_110 )
return;
if ( V_413 )
F_285 ( V_35 -> V_37 , V_418 ) ;
return;
}
V_306 = 0 ;
while ( V_415 && V_306 < 3 ) {
V_416 = F_313 ( V_415 , V_411 ) ;
V_405 = V_416 >> V_421 ;
F_306 ( V_35 , V_405 , V_418 ) ;
V_416 = F_197 ( & V_35 -> V_37 -> V_422 ) ;
if ( ! V_416 )
goto V_423;
if ( V_416 <= V_405 )
V_416 = 0 ;
else
V_416 -= V_405 ;
F_314 ( V_35 -> V_37 -> V_424 ,
F_197 ( & V_35 -> V_37 -> V_422 ) <=
( int ) V_416 ) ;
V_423:
if ( ! V_110 )
V_336 = V_404 ;
else
V_336 = V_392 ;
F_11 ( & V_105 -> V_52 ) ;
if ( F_305 ( V_35 , V_105 , V_412 , V_336 ) ) {
F_13 ( & V_105 -> V_52 ) ;
break;
}
F_13 ( & V_105 -> V_52 ) ;
V_306 ++ ;
if ( V_413 && ! V_110 ) {
F_285 ( V_35 -> V_37 , V_418 ) ;
} else {
V_417 = F_315 ( 1 ) ;
if ( V_417 )
break;
}
V_415 = F_312 (
& V_35 -> V_37 -> V_415 ) ;
}
}
static int F_316 ( struct V_34 * V_35 ,
struct V_102 * V_105 ,
T_2 V_365 , int V_382 )
{
struct V_247 * V_425 = & V_35 -> V_37 -> V_426 ;
struct V_109 * V_110 ;
V_110 = (struct V_109 * ) V_370 -> V_371 ;
if ( V_110 )
return - V_178 ;
if ( V_382 )
goto V_427;
if ( F_284 ( & V_105 -> V_324 ,
V_365 ) >= 0 )
goto V_427;
if ( V_105 != V_425 -> V_105 )
return - V_375 ;
F_11 ( & V_425 -> V_52 ) ;
if ( F_284 ( & V_105 -> V_324 ,
V_365 - V_425 -> V_56 ) >= 0 ) {
F_13 ( & V_425 -> V_52 ) ;
return - V_375 ;
}
F_13 ( & V_425 -> V_52 ) ;
V_427:
V_110 = F_199 ( V_35 ) ;
if ( F_200 ( V_110 ) )
return - V_375 ;
return F_286 ( V_110 , V_35 ) ;
}
static int F_317 ( struct V_34 * V_35 ,
struct V_102 * V_105 , T_2 V_36 ,
T_2 V_428 , int V_275 )
{
struct V_109 * V_110 ;
int V_44 ;
int V_29 = 0 ;
switch ( V_275 ) {
case V_429 :
case V_430 :
if ( V_275 == V_429 )
V_44 = F_310 ( V_35 , V_36 ) * 2 ;
else
V_44 = - 1 ;
V_110 = F_199 ( V_35 ) ;
if ( F_200 ( V_110 ) ) {
V_29 = F_201 ( V_110 ) ;
break;
}
V_29 = F_318 ( V_110 , V_35 , V_44 ) ;
F_203 ( V_110 , V_35 ) ;
break;
case V_431 :
case V_432 :
F_311 ( V_35 , V_36 * 2 , V_428 ,
V_275 == V_432 ) ;
break;
case V_433 :
V_110 = F_199 ( V_35 ) ;
if ( F_200 ( V_110 ) ) {
V_29 = F_201 ( V_110 ) ;
break;
}
V_29 = F_283 ( V_110 , V_35 -> V_37 -> V_62 ,
F_280 ( V_35 , 0 ) ,
V_334 ) ;
F_203 ( V_110 , V_35 ) ;
if ( V_29 == - V_375 )
V_29 = 0 ;
break;
case V_434 :
V_29 = F_316 ( V_35 , V_105 , V_428 , 0 ) ;
break;
default:
V_29 = - V_375 ;
break;
}
return V_29 ;
}
static inline T_2
F_319 ( struct V_34 * V_35 ,
struct V_102 * V_105 )
{
T_2 V_367 ;
T_2 V_435 ;
T_2 V_411 ;
V_411 = F_24 ( T_2 , F_320 () * 1024 * 1024 ,
16 * 1024 * 1024 ) ;
F_11 ( & V_105 -> V_52 ) ;
if ( F_305 ( V_35 , V_105 , V_411 ,
V_404 ) ) {
V_411 = 0 ;
goto V_72;
}
V_367 = V_105 -> V_317 + V_105 -> V_330 +
V_105 -> V_329 + V_105 -> V_331 +
V_105 -> V_332 ;
if ( F_305 ( V_35 , V_105 , 1024 * 1024 ,
V_404 ) )
V_435 = F_293 ( V_105 -> V_316 , 95 ) ;
else
V_435 = F_293 ( V_105 -> V_316 , 90 ) ;
if ( V_367 > V_435 )
V_411 = V_367 - V_435 ;
else
V_411 = 0 ;
V_411 = F_313 ( V_411 , V_105 -> V_332 +
V_105 -> V_330 ) ;
V_72:
F_13 ( & V_105 -> V_52 ) ;
return V_411 ;
}
static inline int F_321 ( struct V_102 * V_105 ,
struct V_12 * V_37 , T_2 V_367 )
{
T_2 V_384 = F_293 ( V_105 -> V_316 , 98 ) ;
if ( V_105 -> V_317 >= V_384 )
return 0 ;
return ( V_367 >= V_384 && ! F_39 ( V_37 ) &&
! F_226 ( V_436 , & V_37 -> V_437 ) ) ;
}
static int F_322 ( struct V_102 * V_105 ,
struct V_12 * V_37 ,
int V_438 )
{
T_2 V_367 ;
F_11 ( & V_105 -> V_52 ) ;
if ( V_438 > V_434 && V_105 -> V_108 ) {
F_13 ( & V_105 -> V_52 ) ;
return 0 ;
}
V_367 = V_105 -> V_317 + V_105 -> V_330 +
V_105 -> V_329 + V_105 -> V_331 +
V_105 -> V_332 ;
if ( F_321 ( V_105 , V_37 , V_367 ) ) {
F_13 ( & V_105 -> V_52 ) ;
return 1 ;
}
F_13 ( & V_105 -> V_52 ) ;
return 0 ;
}
static void F_323 ( struct V_439 * V_61 )
{
struct V_12 * V_37 ;
struct V_102 * V_105 ;
T_2 V_411 ;
int V_438 ;
V_37 = F_32 ( V_61 , struct V_12 , V_440 ) ;
V_105 = F_69 ( V_37 , V_313 ) ;
V_411 = F_319 ( V_37 -> V_441 ,
V_105 ) ;
if ( ! V_411 )
return;
V_438 = V_429 ;
do {
F_317 ( V_37 -> V_441 , V_105 , V_411 ,
V_411 , V_438 ) ;
V_438 ++ ;
if ( ! F_322 ( V_105 , V_37 ,
V_438 ) )
return;
} while ( V_438 < V_434 );
}
void F_324 ( struct V_439 * V_61 )
{
F_325 ( V_61 , F_323 ) ;
}
static int F_326 ( struct V_34 * V_35 ,
struct V_247 * V_414 ,
T_2 V_428 ,
enum V_398 V_336 )
{
struct V_102 * V_105 = V_414 -> V_105 ;
T_2 V_367 ;
T_2 V_36 = V_428 ;
int V_438 = V_429 ;
int V_29 = 0 ;
bool V_442 = false ;
V_77:
V_29 = 0 ;
F_11 ( & V_105 -> V_52 ) ;
while ( V_336 == V_404 && ! V_442 &&
V_105 -> V_336 ) {
F_13 ( & V_105 -> V_52 ) ;
if ( V_370 -> V_371 )
return - V_178 ;
V_29 = F_327 ( V_105 -> V_88 , ! V_105 -> V_336 ) ;
if ( V_29 )
return - V_443 ;
F_11 ( & V_105 -> V_52 ) ;
}
V_29 = - V_375 ;
V_367 = V_105 -> V_317 + V_105 -> V_330 +
V_105 -> V_329 + V_105 -> V_331 +
V_105 -> V_332 ;
if ( V_367 <= V_105 -> V_316 ) {
if ( V_367 + V_428 <= V_105 -> V_316 ) {
V_105 -> V_332 += V_428 ;
F_287 ( V_35 -> V_37 ,
L_10 , V_105 -> V_7 , V_428 , 1 ) ;
V_29 = 0 ;
} else {
V_36 = V_428 ;
}
} else {
V_36 = V_367 - V_105 -> V_316 +
( V_428 * 2 ) ;
}
if ( V_29 && F_305 ( V_35 , V_105 , V_428 , V_336 ) ) {
V_105 -> V_332 += V_428 ;
F_287 ( V_35 -> V_37 , L_10 ,
V_105 -> V_7 , V_428 ,
1 ) ;
V_29 = 0 ;
}
if ( V_29 && V_336 != V_392 ) {
V_442 = true ;
V_105 -> V_336 = 1 ;
} else if ( ! V_29 && V_105 -> V_7 & V_313 ) {
V_367 += V_428 ;
if ( ! V_35 -> V_37 -> V_444 &&
F_321 ( V_105 , V_35 -> V_37 , V_367 ) &&
! F_328 ( & V_35 -> V_37 -> V_440 ) )
F_329 ( V_445 ,
& V_35 -> V_37 -> V_440 ) ;
}
F_13 ( & V_105 -> V_52 ) ;
if ( ! V_29 || V_336 == V_392 )
goto V_72;
V_29 = F_317 ( V_35 , V_105 , V_36 , V_428 ,
V_438 ) ;
V_438 ++ ;
if ( V_336 == V_446 &&
( V_438 == V_431 ||
V_438 == V_432 ) )
V_438 = V_433 ;
if ( ! V_29 )
goto V_77;
else if ( V_336 == V_446 &&
V_438 < V_434 )
goto V_77;
else if ( V_336 == V_404 &&
V_438 <= V_434 )
goto V_77;
V_72:
if ( V_29 == - V_375 &&
F_330 ( V_35 -> V_447 == V_448 ) ) {
struct V_247 * V_248 =
& V_35 -> V_37 -> V_251 ;
if ( V_414 != V_248 &&
! F_331 ( V_248 , V_428 ) )
V_29 = 0 ;
}
if ( V_29 == - V_375 )
F_287 ( V_35 -> V_37 ,
L_9 ,
V_105 -> V_7 , V_428 , 1 ) ;
if ( V_442 ) {
F_11 ( & V_105 -> V_52 ) ;
V_105 -> V_336 = 0 ;
F_332 ( & V_105 -> V_88 ) ;
F_13 ( & V_105 -> V_52 ) ;
}
return V_29 ;
}
static struct V_247 * F_333 (
const struct V_109 * V_110 ,
const struct V_34 * V_35 )
{
struct V_247 * V_414 = NULL ;
if ( F_226 ( V_274 , & V_35 -> V_275 ) )
V_414 = V_110 -> V_414 ;
if ( V_35 == V_35 -> V_37 -> V_449 && V_110 -> V_450 )
V_414 = V_110 -> V_414 ;
if ( V_35 == V_35 -> V_37 -> V_451 )
V_414 = V_110 -> V_414 ;
if ( ! V_414 )
V_414 = V_35 -> V_414 ;
if ( ! V_414 )
V_414 = & V_35 -> V_37 -> V_452 ;
return V_414 ;
}
static int F_331 ( struct V_247 * V_414 ,
T_2 V_36 )
{
int V_29 = - V_375 ;
F_11 ( & V_414 -> V_52 ) ;
if ( V_414 -> V_10 >= V_36 ) {
V_414 -> V_10 -= V_36 ;
if ( V_414 -> V_10 < V_414 -> V_56 )
V_414 -> V_108 = 0 ;
V_29 = 0 ;
}
F_13 ( & V_414 -> V_52 ) ;
return V_29 ;
}
static void F_334 ( struct V_247 * V_414 ,
T_2 V_36 , int V_453 )
{
F_11 ( & V_414 -> V_52 ) ;
V_414 -> V_10 += V_36 ;
if ( V_453 )
V_414 -> V_56 += V_36 ;
else if ( V_414 -> V_10 >= V_414 -> V_56 )
V_414 -> V_108 = 1 ;
F_13 ( & V_414 -> V_52 ) ;
}
int F_335 ( struct V_12 * V_37 ,
struct V_247 * V_454 , T_2 V_36 ,
int V_455 )
{
struct V_247 * V_248 = & V_37 -> V_251 ;
T_2 V_456 ;
if ( V_248 -> V_105 != V_454 -> V_105 )
return - V_375 ;
F_11 ( & V_248 -> V_52 ) ;
V_456 = F_294 ( V_248 -> V_56 , V_455 ) ;
if ( V_248 -> V_10 < V_456 + V_36 ) {
F_13 ( & V_248 -> V_52 ) ;
return - V_375 ;
}
V_248 -> V_10 -= V_36 ;
if ( V_248 -> V_10 < V_248 -> V_56 )
V_248 -> V_108 = 0 ;
F_13 ( & V_248 -> V_52 ) ;
F_334 ( V_454 , V_36 , 1 ) ;
return 0 ;
}
static void F_336 ( struct V_12 * V_37 ,
struct V_247 * V_414 ,
struct V_247 * V_454 , T_2 V_36 )
{
struct V_102 * V_105 = V_414 -> V_105 ;
F_11 ( & V_414 -> V_52 ) ;
if ( V_36 == ( T_2 ) - 1 )
V_36 = V_414 -> V_56 ;
V_414 -> V_56 -= V_36 ;
if ( V_414 -> V_10 >= V_414 -> V_56 ) {
V_36 = V_414 -> V_10 - V_414 -> V_56 ;
V_414 -> V_10 = V_414 -> V_56 ;
V_414 -> V_108 = 1 ;
} else {
V_36 = 0 ;
}
F_13 ( & V_414 -> V_52 ) ;
if ( V_36 > 0 ) {
if ( V_454 ) {
F_11 ( & V_454 -> V_52 ) ;
if ( ! V_454 -> V_108 ) {
T_2 V_457 ;
V_457 = V_454 -> V_56 - V_454 -> V_10 ;
V_457 = F_313 ( V_36 , V_457 ) ;
V_454 -> V_10 += V_457 ;
if ( V_454 -> V_10 >= V_454 -> V_56 )
V_454 -> V_108 = 1 ;
V_36 -= V_457 ;
}
F_13 ( & V_454 -> V_52 ) ;
}
if ( V_36 ) {
F_11 ( & V_105 -> V_52 ) ;
V_105 -> V_332 -= V_36 ;
F_287 ( V_37 , L_10 ,
V_105 -> V_7 , V_36 , 0 ) ;
F_13 ( & V_105 -> V_52 ) ;
}
}
}
static int F_337 ( struct V_247 * V_458 ,
struct V_247 * V_459 , T_2 V_36 )
{
int V_29 ;
V_29 = F_331 ( V_458 , V_36 ) ;
if ( V_29 )
return V_29 ;
F_334 ( V_459 , V_36 , 1 ) ;
return 0 ;
}
void F_338 ( struct V_247 * V_460 , unsigned short type )
{
memset ( V_460 , 0 , sizeof( * V_460 ) ) ;
F_267 ( & V_460 -> V_52 ) ;
V_460 -> type = type ;
}
struct V_247 * F_339 ( struct V_34 * V_35 ,
unsigned short type )
{
struct V_247 * V_414 ;
struct V_12 * V_37 = V_35 -> V_37 ;
V_414 = F_206 ( sizeof( * V_414 ) , V_40 ) ;
if ( ! V_414 )
return NULL ;
F_338 ( V_414 , type ) ;
V_414 -> V_105 = F_69 ( V_37 ,
V_313 ) ;
return V_414 ;
}
void F_340 ( struct V_34 * V_35 ,
struct V_247 * V_460 )
{
if ( ! V_460 )
return;
F_341 ( V_35 , V_460 , ( T_2 ) - 1 ) ;
F_9 ( V_460 ) ;
}
void F_342 ( struct V_247 * V_460 )
{
F_9 ( V_460 ) ;
}
int F_302 ( struct V_34 * V_35 ,
struct V_247 * V_414 , T_2 V_36 ,
enum V_398 V_336 )
{
int V_29 ;
if ( V_36 == 0 )
return 0 ;
V_29 = F_326 ( V_35 , V_414 , V_36 , V_336 ) ;
if ( ! V_29 ) {
F_334 ( V_414 , V_36 , 1 ) ;
return 0 ;
}
return V_29 ;
}
int F_343 ( struct V_34 * V_35 ,
struct V_247 * V_414 , int V_455 )
{
T_2 V_36 = 0 ;
int V_29 = - V_375 ;
if ( ! V_414 )
return 0 ;
F_11 ( & V_414 -> V_52 ) ;
V_36 = F_294 ( V_414 -> V_56 , V_455 ) ;
if ( V_414 -> V_10 >= V_36 )
V_29 = 0 ;
F_13 ( & V_414 -> V_52 ) ;
return V_29 ;
}
int F_344 ( struct V_34 * V_35 ,
struct V_247 * V_414 , T_2 V_461 ,
enum V_398 V_336 )
{
T_2 V_36 = 0 ;
int V_29 = - V_375 ;
if ( ! V_414 )
return 0 ;
F_11 ( & V_414 -> V_52 ) ;
V_36 = V_461 ;
if ( V_414 -> V_10 >= V_36 )
V_29 = 0 ;
else
V_36 -= V_414 -> V_10 ;
F_13 ( & V_414 -> V_52 ) ;
if ( ! V_29 )
return 0 ;
V_29 = F_326 ( V_35 , V_414 , V_36 , V_336 ) ;
if ( ! V_29 ) {
F_334 ( V_414 , V_36 , 0 ) ;
return 0 ;
}
return V_29 ;
}
int F_345 ( struct V_247 * V_462 ,
struct V_247 * V_463 ,
T_2 V_36 )
{
return F_337 ( V_462 , V_463 , V_36 ) ;
}
void F_341 ( struct V_34 * V_35 ,
struct V_247 * V_414 ,
T_2 V_36 )
{
struct V_247 * V_248 = & V_35 -> V_37 -> V_251 ;
if ( V_248 == V_414 ||
V_414 -> V_105 != V_248 -> V_105 )
V_248 = NULL ;
F_336 ( V_35 -> V_37 , V_414 , V_248 ,
V_36 ) ;
}
static T_2 F_346 ( struct V_12 * V_37 )
{
struct V_102 * V_381 ;
T_2 V_36 ;
T_2 V_464 ;
T_2 V_465 ;
int V_241 = F_193 ( V_37 -> V_245 ) ;
V_381 = F_69 ( V_37 , V_314 ) ;
F_11 ( & V_381 -> V_52 ) ;
V_465 = V_381 -> V_317 ;
F_13 ( & V_381 -> V_52 ) ;
V_381 = F_69 ( V_37 , V_313 ) ;
F_11 ( & V_381 -> V_52 ) ;
if ( V_381 -> V_7 & V_314 )
V_465 = 0 ;
V_464 = V_381 -> V_317 ;
F_13 ( & V_381 -> V_52 ) ;
V_36 = ( V_465 >> V_37 -> V_408 -> V_466 ) *
V_241 * 2 ;
V_36 += F_189 ( V_465 + V_464 , 50 ) ;
if ( V_36 * 3 > V_464 )
V_36 = F_189 ( V_464 , 3 ) ;
return F_281 ( V_36 , V_37 -> V_62 -> V_87 << 10 ) ;
}
static void F_347 ( struct V_12 * V_37 )
{
struct V_247 * V_414 = & V_37 -> V_251 ;
struct V_102 * V_381 = V_414 -> V_105 ;
T_2 V_36 ;
V_36 = F_346 ( V_37 ) ;
F_11 ( & V_381 -> V_52 ) ;
F_11 ( & V_414 -> V_52 ) ;
V_414 -> V_56 = F_24 ( T_2 , V_36 , 512 * 1024 * 1024 ) ;
V_36 = V_381 -> V_317 + V_381 -> V_329 +
V_381 -> V_330 + V_381 -> V_331 +
V_381 -> V_332 ;
if ( V_381 -> V_316 > V_36 ) {
V_36 = V_381 -> V_316 - V_36 ;
V_414 -> V_10 += V_36 ;
V_381 -> V_332 += V_36 ;
F_287 ( V_37 , L_10 ,
V_381 -> V_7 , V_36 , 1 ) ;
}
if ( V_414 -> V_10 >= V_414 -> V_56 ) {
V_36 = V_414 -> V_10 - V_414 -> V_56 ;
V_381 -> V_332 -= V_36 ;
F_287 ( V_37 , L_10 ,
V_381 -> V_7 , V_36 , 0 ) ;
V_414 -> V_10 = V_414 -> V_56 ;
V_414 -> V_108 = 1 ;
}
F_13 ( & V_414 -> V_52 ) ;
F_13 ( & V_381 -> V_52 ) ;
}
static void F_348 ( struct V_12 * V_37 )
{
struct V_102 * V_105 ;
V_105 = F_69 ( V_37 , V_315 ) ;
V_37 -> V_391 . V_105 = V_105 ;
V_105 = F_69 ( V_37 , V_313 ) ;
V_37 -> V_251 . V_105 = V_105 ;
V_37 -> V_420 . V_105 = V_105 ;
V_37 -> V_467 . V_105 = V_105 ;
V_37 -> V_452 . V_105 = V_105 ;
V_37 -> V_426 . V_105 = V_105 ;
V_37 -> V_62 -> V_414 = & V_37 -> V_251 ;
V_37 -> V_449 -> V_414 = & V_37 -> V_251 ;
V_37 -> V_468 -> V_414 = & V_37 -> V_251 ;
V_37 -> V_86 -> V_414 = & V_37 -> V_251 ;
if ( V_37 -> V_469 )
V_37 -> V_469 -> V_414 = & V_37 -> V_251 ;
V_37 -> V_364 -> V_414 = & V_37 -> V_391 ;
F_347 ( V_37 ) ;
}
static void F_349 ( struct V_12 * V_37 )
{
F_336 ( V_37 , & V_37 -> V_251 , NULL ,
( T_2 ) - 1 ) ;
F_8 ( V_37 -> V_420 . V_56 > 0 ) ;
F_8 ( V_37 -> V_420 . V_10 > 0 ) ;
F_8 ( V_37 -> V_467 . V_56 > 0 ) ;
F_8 ( V_37 -> V_467 . V_10 > 0 ) ;
F_8 ( V_37 -> V_391 . V_56 > 0 ) ;
F_8 ( V_37 -> V_391 . V_10 > 0 ) ;
F_8 ( V_37 -> V_426 . V_56 > 0 ) ;
F_8 ( V_37 -> V_426 . V_10 > 0 ) ;
}
void F_350 ( struct V_109 * V_110 ,
struct V_34 * V_35 )
{
if ( ! V_110 -> V_414 )
return;
if ( ! V_110 -> V_330 )
return;
F_287 ( V_35 -> V_37 , L_12 ,
V_110 -> V_290 , V_110 -> V_330 , 0 ) ;
F_341 ( V_35 , V_110 -> V_414 , V_110 -> V_330 ) ;
V_110 -> V_330 = 0 ;
}
void F_304 ( struct V_109 * V_110 )
{
struct V_12 * V_37 = V_110 -> V_35 -> V_37 ;
if ( ! V_110 -> V_393 )
return;
F_351 ( ! F_169 ( & V_110 -> V_263 ) ) ;
F_336 ( V_37 , & V_37 -> V_391 , NULL ,
V_110 -> V_393 ) ;
V_110 -> V_393 = 0 ;
}
int F_352 ( struct V_109 * V_110 ,
struct V_280 * V_280 )
{
struct V_34 * V_35 = F_243 ( V_280 ) -> V_35 ;
struct V_247 * V_462 = F_333 ( V_110 , V_35 ) ;
struct V_247 * V_463 = V_35 -> V_470 ;
T_2 V_36 = F_195 ( V_35 , 1 ) ;
F_287 ( V_35 -> V_37 , L_13 ,
F_353 ( V_280 ) , V_36 , 1 ) ;
return F_337 ( V_462 , V_463 , V_36 ) ;
}
void F_354 ( struct V_280 * V_280 )
{
struct V_34 * V_35 = F_243 ( V_280 ) -> V_35 ;
T_2 V_36 = F_195 ( V_35 , 1 ) ;
F_287 ( V_35 -> V_37 , L_13 ,
F_353 ( V_280 ) , V_36 , 0 ) ;
F_341 ( V_35 , V_35 -> V_470 , V_36 ) ;
}
int F_355 ( struct V_34 * V_35 ,
struct V_247 * V_460 ,
int V_418 ,
T_2 * V_471 ,
bool V_472 )
{
T_2 V_36 ;
int V_29 ;
struct V_247 * V_248 = & V_35 -> V_37 -> V_251 ;
if ( V_35 -> V_37 -> V_205 ) {
V_36 = 3 * V_35 -> V_87 ;
V_29 = F_288 ( V_35 , V_36 ) ;
if ( V_29 )
return V_29 ;
} else {
V_36 = 0 ;
}
* V_471 = V_36 ;
V_36 = F_195 ( V_35 , V_418 ) ;
V_460 -> V_105 = F_69 ( V_35 -> V_37 ,
V_313 ) ;
V_29 = F_302 ( V_35 , V_460 , V_36 ,
V_404 ) ;
if ( V_29 == - V_375 && V_472 )
V_29 = F_345 ( V_248 , V_460 , V_36 ) ;
if ( V_29 ) {
if ( * V_471 )
F_356 ( V_35 , * V_471 ) ;
}
return V_29 ;
}
void F_357 ( struct V_34 * V_35 ,
struct V_247 * V_460 ,
T_2 V_471 )
{
F_341 ( V_35 , V_460 , ( T_2 ) - 1 ) ;
}
static unsigned F_358 ( struct V_280 * V_280 , T_2 V_36 )
{
unsigned V_473 = 0 ;
unsigned V_474 = 0 ;
unsigned V_475 = 0 ;
V_475 = ( unsigned ) F_192 ( V_36 +
V_476 - 1 ,
V_476 ) ;
ASSERT ( V_475 ) ;
ASSERT ( F_243 ( V_280 ) -> V_477 >= V_475 ) ;
F_243 ( V_280 ) -> V_477 -= V_475 ;
if ( F_243 ( V_280 ) -> V_477 == 0 &&
F_359 ( V_478 ,
& F_243 ( V_280 ) -> V_479 ) )
V_473 = 1 ;
if ( F_243 ( V_280 ) -> V_477 >=
F_243 ( V_280 ) -> V_480 )
return V_473 ;
V_474 = F_243 ( V_280 ) -> V_480 -
F_243 ( V_280 ) -> V_477 ;
F_243 ( V_280 ) -> V_480 -= V_474 ;
return V_474 + V_473 ;
}
static T_2 F_360 ( struct V_280 * V_280 , T_2 V_36 ,
int V_481 )
{
struct V_34 * V_35 = F_243 ( V_280 ) -> V_35 ;
T_2 V_482 , V_243 ;
if ( F_243 ( V_280 ) -> V_7 & V_483 &&
F_243 ( V_280 ) -> V_240 == 0 )
return 0 ;
V_482 = F_191 ( V_35 , F_243 ( V_280 ) -> V_240 ) ;
if ( V_481 )
F_243 ( V_280 ) -> V_240 += V_36 ;
else
F_243 ( V_280 ) -> V_240 -= V_36 ;
V_243 = F_191 ( V_35 , F_243 ( V_280 ) -> V_240 ) ;
if ( V_482 == V_243 )
return 0 ;
if ( V_481 )
return F_195 ( V_35 ,
V_243 - V_482 ) ;
return F_195 ( V_35 , V_482 - V_243 ) ;
}
int F_361 ( struct V_280 * V_280 , T_2 V_36 )
{
struct V_34 * V_35 = F_243 ( V_280 ) -> V_35 ;
struct V_247 * V_414 = & V_35 -> V_37 -> V_420 ;
T_2 V_484 = 0 ;
T_2 V_240 ;
unsigned V_485 = 0 ;
int V_486 = 0 ;
enum V_398 V_336 = V_404 ;
int V_29 = 0 ;
bool V_487 = true ;
T_2 V_488 = 0 ;
unsigned V_489 ;
if ( F_282 ( V_280 ) ) {
V_336 = V_392 ;
V_487 = false ;
}
if ( V_336 != V_392 &&
F_362 ( V_35 -> V_37 ) )
F_363 ( 1 ) ;
if ( V_487 )
F_35 ( & F_243 ( V_280 ) -> V_490 ) ;
V_36 = F_281 ( V_36 , V_35 -> V_246 ) ;
F_11 ( & F_243 ( V_280 ) -> V_52 ) ;
V_485 = ( unsigned ) F_192 ( V_36 +
V_476 - 1 ,
V_476 ) ;
F_243 ( V_280 ) -> V_477 += V_485 ;
V_485 = 0 ;
if ( F_243 ( V_280 ) -> V_477 >
F_243 ( V_280 ) -> V_480 )
V_485 = F_243 ( V_280 ) -> V_477 -
F_243 ( V_280 ) -> V_480 ;
if ( ! F_226 ( V_478 ,
& F_243 ( V_280 ) -> V_479 ) ) {
V_485 ++ ;
V_486 = 1 ;
}
V_484 = F_195 ( V_35 , V_485 ) ;
V_484 += F_360 ( V_280 , V_36 , 1 ) ;
V_240 = F_243 ( V_280 ) -> V_240 ;
F_13 ( & F_243 ( V_280 ) -> V_52 ) ;
if ( V_35 -> V_37 -> V_205 ) {
V_29 = F_288 ( V_35 , V_485 * V_35 -> V_87 ) ;
if ( V_29 )
goto V_491;
}
V_29 = F_326 ( V_35 , V_414 , V_484 , V_336 ) ;
if ( F_330 ( V_29 ) ) {
if ( V_35 -> V_37 -> V_205 )
F_356 ( V_35 , V_485 * V_35 -> V_87 ) ;
goto V_491;
}
F_11 ( & F_243 ( V_280 ) -> V_52 ) ;
if ( V_486 ) {
F_364 ( V_478 ,
& F_243 ( V_280 ) -> V_479 ) ;
V_485 -- ;
}
F_243 ( V_280 ) -> V_480 += V_485 ;
F_13 ( & F_243 ( V_280 ) -> V_52 ) ;
if ( V_487 )
F_46 ( & F_243 ( V_280 ) -> V_490 ) ;
if ( V_484 )
F_287 ( V_35 -> V_37 , L_14 ,
F_353 ( V_280 ) , V_484 , 1 ) ;
F_334 ( V_414 , V_484 , 1 ) ;
return 0 ;
V_491:
F_11 ( & F_243 ( V_280 ) -> V_52 ) ;
V_489 = F_358 ( V_280 , V_36 ) ;
if ( F_243 ( V_280 ) -> V_240 == V_240 ) {
F_360 ( V_280 , V_36 , 0 ) ;
} else {
T_2 V_492 = F_243 ( V_280 ) -> V_240 ;
T_2 V_365 ;
V_365 = V_240 - F_243 ( V_280 ) -> V_240 ;
F_243 ( V_280 ) -> V_240 = V_240 ;
V_488 = F_360 ( V_280 , V_365 , 0 ) ;
F_243 ( V_280 ) -> V_240 = V_240 - V_36 ;
V_365 = V_240 - V_492 ;
V_365 = F_360 ( V_280 , V_365 , 0 ) ;
F_243 ( V_280 ) -> V_240 = V_492 - V_36 ;
if ( V_365 > V_488 )
V_488 = V_365 - V_488 ;
else
V_488 = 0 ;
}
F_13 ( & F_243 ( V_280 ) -> V_52 ) ;
if ( V_489 )
V_488 += F_195 ( V_35 , V_489 ) ;
if ( V_488 ) {
F_341 ( V_35 , V_414 , V_488 ) ;
F_287 ( V_35 -> V_37 , L_14 ,
F_353 ( V_280 ) , V_488 , 0 ) ;
}
if ( V_487 )
F_46 ( & F_243 ( V_280 ) -> V_490 ) ;
return V_29 ;
}
void F_365 ( struct V_280 * V_280 , T_2 V_36 )
{
struct V_34 * V_35 = F_243 ( V_280 ) -> V_35 ;
T_2 V_488 = 0 ;
unsigned V_489 ;
V_36 = F_281 ( V_36 , V_35 -> V_246 ) ;
F_11 ( & F_243 ( V_280 ) -> V_52 ) ;
V_489 = F_358 ( V_280 , V_36 ) ;
if ( V_36 )
V_488 = F_360 ( V_280 , V_36 , 0 ) ;
F_13 ( & F_243 ( V_280 ) -> V_52 ) ;
if ( V_489 > 0 )
V_488 += F_195 ( V_35 , V_489 ) ;
if ( F_223 ( V_35 ) )
return;
F_287 ( V_35 -> V_37 , L_14 ,
F_353 ( V_280 ) , V_488 , 0 ) ;
F_341 ( V_35 , & V_35 -> V_37 -> V_420 ,
V_488 ) ;
}
int F_366 ( struct V_280 * V_280 , T_2 V_36 )
{
int V_29 ;
V_29 = F_248 ( V_280 , V_36 , V_36 ) ;
if ( V_29 )
return V_29 ;
V_29 = F_361 ( V_280 , V_36 ) ;
if ( V_29 ) {
F_250 ( V_280 , V_36 ) ;
return V_29 ;
}
return 0 ;
}
void F_367 ( struct V_280 * V_280 , T_2 V_36 )
{
F_365 ( V_280 , V_36 ) ;
F_250 ( V_280 , V_36 ) ;
}
static int F_368 ( struct V_109 * V_110 ,
struct V_34 * V_35 , T_2 V_27 ,
T_2 V_36 , int V_372 )
{
struct V_1 * V_2 = NULL ;
struct V_12 * V_13 = V_35 -> V_37 ;
T_2 V_493 = V_36 ;
T_2 V_494 ;
T_2 V_495 ;
int V_318 ;
F_11 ( & V_13 -> V_496 ) ;
V_494 = F_369 ( V_13 -> V_245 ) ;
if ( V_372 )
V_494 += V_36 ;
else
V_494 -= V_36 ;
F_370 ( V_13 -> V_245 , V_494 ) ;
F_13 ( & V_13 -> V_496 ) ;
while ( V_493 ) {
V_2 = F_68 ( V_13 , V_27 ) ;
if ( ! V_2 )
return - V_153 ;
if ( V_2 -> V_7 & ( V_319 |
V_320 |
V_321 ) )
V_318 = 2 ;
else
V_318 = 1 ;
if ( ! V_372 && V_2 -> V_3 == V_94 )
F_51 ( V_2 , 1 ) ;
V_495 = V_27 - V_2 -> V_21 . V_22 ;
F_8 ( V_495 > V_2 -> V_21 . V_33 ) ;
F_11 ( & V_2 -> V_105 -> V_52 ) ;
F_11 ( & V_2 -> V_52 ) ;
if ( F_247 ( V_35 , V_294 ) &&
V_2 -> V_286 < V_300 )
V_2 -> V_286 = V_300 ;
V_494 = F_371 ( & V_2 -> V_135 ) ;
V_36 = F_313 ( V_493 , V_2 -> V_21 . V_33 - V_495 ) ;
if ( V_372 ) {
V_494 += V_36 ;
F_372 ( & V_2 -> V_135 , V_494 ) ;
V_2 -> V_10 -= V_36 ;
V_2 -> V_105 -> V_330 -= V_36 ;
V_2 -> V_105 -> V_317 += V_36 ;
V_2 -> V_105 -> V_323 += V_36 * V_318 ;
F_13 ( & V_2 -> V_52 ) ;
F_13 ( & V_2 -> V_105 -> V_52 ) ;
} else {
V_494 -= V_36 ;
F_372 ( & V_2 -> V_135 , V_494 ) ;
V_2 -> V_9 += V_36 ;
V_2 -> V_105 -> V_329 += V_36 ;
V_2 -> V_105 -> V_317 -= V_36 ;
V_2 -> V_105 -> V_323 -= V_36 * V_318 ;
F_13 ( & V_2 -> V_52 ) ;
F_13 ( & V_2 -> V_105 -> V_52 ) ;
F_373 ( V_13 -> V_58 ,
V_27 , V_27 + V_36 - 1 ,
V_40 | V_497 ) ;
if ( V_494 == 0 ) {
F_11 ( & V_13 -> V_498 ) ;
if ( F_169 ( & V_2 -> V_499 ) ) {
F_4 ( V_2 ) ;
F_64 ( & V_2 -> V_499 ,
& V_13 -> V_500 ) ;
}
F_13 ( & V_13 -> V_498 ) ;
}
}
F_11 ( & V_110 -> V_127 -> V_307 ) ;
if ( F_169 ( & V_2 -> V_309 ) ) {
F_64 ( & V_2 -> V_309 ,
& V_110 -> V_127 -> V_299 ) ;
V_110 -> V_127 -> V_249 ++ ;
F_4 ( V_2 ) ;
}
F_13 ( & V_110 -> V_127 -> V_307 ) ;
F_6 ( V_2 ) ;
V_493 -= V_36 ;
V_27 += V_36 ;
}
return 0 ;
}
static T_2 V_26 ( struct V_34 * V_35 , T_2 V_501 )
{
struct V_1 * V_2 ;
T_2 V_27 ;
F_11 ( & V_35 -> V_37 -> V_18 ) ;
V_27 = V_35 -> V_37 -> V_26 ;
F_13 ( & V_35 -> V_37 -> V_18 ) ;
if ( V_27 < ( T_2 ) - 1 )
return V_27 ;
V_2 = F_67 ( V_35 -> V_37 , V_501 ) ;
if ( ! V_2 )
return 0 ;
V_27 = V_2 -> V_21 . V_22 ;
F_6 ( V_2 ) ;
return V_27 ;
}
static int F_374 ( struct V_34 * V_35 ,
struct V_1 * V_2 ,
T_2 V_27 , T_2 V_36 , int V_10 )
{
F_11 ( & V_2 -> V_105 -> V_52 ) ;
F_11 ( & V_2 -> V_52 ) ;
V_2 -> V_9 += V_36 ;
V_2 -> V_105 -> V_329 += V_36 ;
if ( V_10 ) {
V_2 -> V_10 -= V_36 ;
V_2 -> V_105 -> V_330 -= V_36 ;
}
F_13 ( & V_2 -> V_52 ) ;
F_13 ( & V_2 -> V_105 -> V_52 ) ;
F_373 ( V_35 -> V_37 -> V_58 , V_27 ,
V_27 + V_36 - 1 , V_40 | V_497 ) ;
if ( V_10 )
F_375 ( V_35 , V_27 , V_36 ) ;
return 0 ;
}
int F_163 ( struct V_34 * V_35 ,
T_2 V_27 , T_2 V_36 , int V_10 )
{
struct V_1 * V_2 ;
V_2 = F_68 ( V_35 -> V_37 , V_27 ) ;
F_30 ( ! V_2 ) ;
F_374 ( V_35 , V_2 , V_27 , V_36 , V_10 ) ;
F_6 ( V_2 ) ;
return 0 ;
}
int F_376 ( struct V_34 * V_35 ,
T_2 V_27 , T_2 V_36 )
{
struct V_1 * V_2 ;
int V_29 ;
V_2 = F_68 ( V_35 -> V_37 , V_27 ) ;
if ( ! V_2 )
return - V_502 ;
F_51 ( V_2 , 1 ) ;
F_374 ( V_35 , V_2 , V_27 , V_36 , 0 ) ;
V_29 = F_377 ( V_2 , V_27 , V_36 ) ;
F_6 ( V_2 ) ;
return V_29 ;
}
static int F_378 ( struct V_34 * V_35 , T_2 V_32 , T_2 V_36 )
{
int V_29 ;
struct V_1 * V_14 ;
struct V_50 * V_53 ;
V_14 = F_68 ( V_35 -> V_37 , V_32 ) ;
if ( ! V_14 )
return - V_502 ;
F_51 ( V_14 , 0 ) ;
V_53 = F_25 ( V_14 ) ;
if ( ! V_53 ) {
F_30 ( ! F_1 ( V_14 ) ) ;
V_29 = F_377 ( V_14 , V_32 , V_36 ) ;
} else {
F_35 ( & V_53 -> V_78 ) ;
if ( V_32 >= V_53 -> V_84 ) {
V_29 = F_17 ( V_35 , V_32 , V_36 ) ;
} else if ( V_32 + V_36 <= V_53 -> V_84 ) {
V_29 = F_377 ( V_14 ,
V_32 , V_36 ) ;
} else {
V_36 = V_53 -> V_84 - V_32 ;
V_29 = F_377 ( V_14 ,
V_32 , V_36 ) ;
if ( V_29 )
goto V_503;
V_36 = ( V_32 + V_36 ) -
V_53 -> V_84 ;
V_32 = V_53 -> V_84 ;
V_29 = F_17 ( V_35 , V_32 , V_36 ) ;
}
V_503:
F_46 ( & V_53 -> V_78 ) ;
F_26 ( V_53 ) ;
}
F_6 ( V_14 ) ;
return V_29 ;
}
int F_379 ( struct V_34 * log ,
struct V_65 * V_504 )
{
struct V_272 * V_135 ;
struct V_67 V_21 ;
int V_505 ;
int V_43 ;
if ( ! F_76 ( log -> V_37 , V_506 ) )
return 0 ;
for ( V_43 = 0 ; V_43 < F_38 ( V_504 ) ; V_43 ++ ) {
F_40 ( V_504 , & V_21 , V_43 ) ;
if ( V_21 . type != V_277 )
continue;
V_135 = F_78 ( V_504 , V_43 , struct V_272 ) ;
V_505 = F_227 ( V_504 , V_135 ) ;
if ( V_505 == V_278 )
continue;
if ( F_228 ( V_504 , V_135 ) == 0 )
continue;
V_21 . V_22 = F_228 ( V_504 , V_135 ) ;
V_21 . V_33 = F_229 ( V_504 , V_135 ) ;
F_378 ( log , V_21 . V_22 , V_21 . V_33 ) ;
}
return 0 ;
}
static int F_380 ( struct V_1 * V_2 ,
T_2 V_36 , int V_481 , int V_507 )
{
struct V_102 * V_105 = V_2 -> V_105 ;
int V_29 = 0 ;
F_11 ( & V_105 -> V_52 ) ;
F_11 ( & V_2 -> V_52 ) ;
if ( V_481 != V_508 ) {
if ( V_2 -> V_288 ) {
V_29 = - V_178 ;
} else {
V_2 -> V_10 += V_36 ;
V_105 -> V_330 += V_36 ;
if ( V_481 == V_509 ) {
F_287 ( V_2 -> V_37 ,
L_10 , V_105 -> V_7 ,
V_36 , 0 ) ;
V_105 -> V_332 -= V_36 ;
}
if ( V_507 )
V_2 -> V_415 += V_36 ;
}
} else {
if ( V_2 -> V_288 )
V_105 -> V_331 += V_36 ;
V_2 -> V_10 -= V_36 ;
V_105 -> V_330 -= V_36 ;
if ( V_507 )
V_2 -> V_415 -= V_36 ;
}
F_13 ( & V_2 -> V_52 ) ;
F_13 ( & V_105 -> V_52 ) ;
return V_29 ;
}
void F_381 ( struct V_109 * V_110 ,
struct V_34 * V_35 )
{
struct V_12 * V_37 = V_35 -> V_37 ;
struct V_50 * V_80 ;
struct V_50 * V_53 ;
struct V_1 * V_2 ;
F_63 ( & V_37 -> V_79 ) ;
F_253 (caching_ctl, next,
&fs_info->caching_block_groups, list) {
V_2 = V_53 -> V_14 ;
if ( F_1 ( V_2 ) ) {
V_2 -> V_97 = ( T_2 ) - 1 ;
F_258 ( & V_53 -> V_90 ) ;
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
F_347 ( V_37 ) ;
}
static int F_382 ( struct V_34 * V_35 , T_2 V_32 , T_2 V_31 ,
const bool V_510 )
{
struct V_12 * V_37 = V_35 -> V_37 ;
struct V_1 * V_2 = NULL ;
struct V_102 * V_105 ;
struct V_247 * V_248 = & V_37 -> V_251 ;
T_2 V_49 ;
bool V_312 ;
while ( V_32 <= V_31 ) {
V_312 = false ;
if ( ! V_2 ||
V_32 >= V_2 -> V_21 . V_22 + V_2 -> V_21 . V_33 ) {
if ( V_2 )
F_6 ( V_2 ) ;
V_2 = F_68 ( V_37 , V_32 ) ;
F_30 ( ! V_2 ) ;
}
V_49 = V_2 -> V_21 . V_22 + V_2 -> V_21 . V_33 - V_32 ;
V_49 = F_313 ( V_49 , V_31 + 1 - V_32 ) ;
if ( V_32 < V_2 -> V_97 ) {
V_49 = F_313 ( V_49 , V_2 -> V_97 - V_32 ) ;
if ( V_510 )
F_29 ( V_2 , V_32 , V_49 ) ;
}
V_32 += V_49 ;
V_105 = V_2 -> V_105 ;
F_11 ( & V_105 -> V_52 ) ;
F_11 ( & V_2 -> V_52 ) ;
V_2 -> V_9 -= V_49 ;
V_105 -> V_329 -= V_49 ;
F_383 ( & V_105 -> V_324 , - V_49 ) ;
if ( V_2 -> V_288 ) {
V_105 -> V_331 += V_49 ;
V_312 = true ;
}
F_13 ( & V_2 -> V_52 ) ;
if ( ! V_312 && V_248 -> V_105 == V_105 ) {
F_11 ( & V_248 -> V_52 ) ;
if ( ! V_248 -> V_108 ) {
V_49 = F_313 ( V_49 , V_248 -> V_56 -
V_248 -> V_10 ) ;
V_248 -> V_10 += V_49 ;
V_105 -> V_332 += V_49 ;
if ( V_248 -> V_10 >= V_248 -> V_56 )
V_248 -> V_108 = 1 ;
}
F_13 ( & V_248 -> V_52 ) ;
}
F_13 ( & V_105 -> V_52 ) ;
}
if ( V_2 )
F_6 ( V_2 ) ;
return 0 ;
}
int F_384 ( struct V_109 * V_110 ,
struct V_34 * V_35 )
{
struct V_12 * V_37 = V_35 -> V_37 ;
struct V_511 * V_512 ;
T_2 V_32 ;
T_2 V_31 ;
int V_29 ;
if ( V_110 -> V_214 )
return 0 ;
if ( V_37 -> V_58 == & V_37 -> V_38 [ 0 ] )
V_512 = & V_37 -> V_38 [ 1 ] ;
else
V_512 = & V_37 -> V_38 [ 0 ] ;
while ( 1 ) {
F_35 ( & V_37 -> V_513 ) ;
V_29 = F_28 ( V_512 , 0 , & V_32 , & V_31 ,
V_59 , NULL ) ;
if ( V_29 ) {
F_46 ( & V_37 -> V_513 ) ;
break;
}
if ( F_247 ( V_35 , V_514 ) )
V_29 = F_142 ( V_35 , V_32 ,
V_31 + 1 - V_32 , NULL ) ;
F_385 ( V_512 , V_32 , V_31 , V_40 ) ;
F_382 ( V_35 , V_32 , V_31 , true ) ;
F_46 ( & V_37 -> V_513 ) ;
F_47 () ;
}
return 0 ;
}
static void F_386 ( struct V_12 * V_37 , T_2 V_36 ,
T_2 V_133 , T_2 V_146 )
{
struct V_102 * V_105 ;
T_2 V_7 ;
if ( V_133 < V_143 ) {
if ( V_146 == V_515 )
V_7 = V_315 ;
else
V_7 = V_313 ;
} else {
V_7 = V_314 ;
}
V_105 = F_69 ( V_37 , V_7 ) ;
F_30 ( ! V_105 ) ;
F_383 ( & V_105 -> V_324 , V_36 ) ;
}
static int F_155 ( struct V_109 * V_110 ,
struct V_34 * V_35 ,
struct V_204 * V_128 , T_2 V_17 ,
T_2 V_146 , T_2 V_516 ,
T_2 V_517 , int V_159 ,
struct V_180 * V_129 )
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
int V_518 = 0 ;
int V_519 = 0 ;
int V_520 = 1 ;
int V_201 = V_128 -> V_201 ;
T_3 V_118 ;
T_2 V_112 ;
T_2 V_27 = V_128 -> V_27 ;
T_2 V_36 = V_128 -> V_36 ;
int V_160 = 0 ;
bool V_173 = F_76 ( V_35 -> V_37 ,
V_121 ) ;
if ( ! V_13 -> V_205 || ! F_149 ( V_146 ) )
V_201 = 1 ;
V_64 = F_33 () ;
if ( ! V_64 )
return - V_71 ;
V_64 -> V_75 = 1 ;
V_64 -> V_206 = 1 ;
V_184 = V_516 >= V_143 ;
F_30 ( ! V_184 && V_159 != 1 ) ;
if ( V_184 )
V_173 = 0 ;
V_29 = F_134 ( V_110 , V_62 , V_64 , & V_164 ,
V_27 , V_36 , V_17 ,
V_146 , V_516 ,
V_517 ) ;
if ( V_29 == 0 ) {
V_518 = V_64 -> V_83 [ 0 ] ;
while ( V_518 >= 0 ) {
F_40 ( V_64 -> V_82 [ 0 ] , & V_21 ,
V_518 ) ;
if ( V_21 . V_22 != V_27 )
break;
if ( V_21 . type == V_76 &&
V_21 . V_33 == V_36 ) {
V_519 = 1 ;
break;
}
if ( V_21 . type == V_85 &&
V_21 . V_33 == V_516 ) {
V_519 = 1 ;
break;
}
if ( V_64 -> V_83 [ 0 ] - V_518 > 5 )
break;
V_518 -- ;
}
#ifdef F_81
V_118 = F_77 ( V_64 -> V_82 [ 0 ] , V_518 ) ;
if ( V_519 && V_118 < sizeof( * V_117 ) )
V_519 = 0 ;
#endif
if ( ! V_519 ) {
F_30 ( V_164 ) ;
V_29 = F_139 ( V_110 , V_62 , V_64 ,
NULL , V_159 ,
V_184 , & V_160 ) ;
if ( V_29 ) {
F_150 ( V_110 , V_62 , V_29 ) ;
goto V_72;
}
F_44 ( V_64 ) ;
V_64 -> V_206 = 1 ;
V_21 . V_22 = V_27 ;
V_21 . type = V_76 ;
V_21 . V_33 = V_36 ;
if ( ! V_184 && V_173 ) {
V_21 . type = V_85 ;
V_21 . V_33 = V_516 ;
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
F_387 ( V_13 , L_15 ,
V_29 , V_27 ) ;
if ( V_29 > 0 )
F_388 ( V_62 ,
V_64 -> V_82 [ 0 ] ) ;
}
if ( V_29 < 0 ) {
F_150 ( V_110 , V_62 , V_29 ) ;
goto V_72;
}
V_518 = V_64 -> V_83 [ 0 ] ;
}
} else if ( F_8 ( V_29 == - V_153 ) ) {
F_388 ( V_62 , V_64 -> V_82 [ 0 ] ) ;
F_387 ( V_13 ,
L_16 ,
V_27 , V_17 , V_146 , V_516 ,
V_517 ) ;
F_150 ( V_110 , V_62 , V_29 ) ;
goto V_72;
} else {
F_150 ( V_110 , V_62 , V_29 ) ;
goto V_72;
}
V_66 = V_64 -> V_82 [ 0 ] ;
V_118 = F_77 ( V_66 , V_518 ) ;
#ifdef F_81
if ( V_118 < sizeof( * V_117 ) ) {
F_30 ( V_519 || V_518 != V_64 -> V_83 [ 0 ] ) ;
V_29 = F_87 ( V_110 , V_62 , V_64 ,
V_516 , 0 ) ;
if ( V_29 < 0 ) {
F_150 ( V_110 , V_62 , V_29 ) ;
goto V_72;
}
F_44 ( V_64 ) ;
V_64 -> V_206 = 1 ;
V_21 . V_22 = V_27 ;
V_21 . type = V_76 ;
V_21 . V_33 = V_36 ;
V_29 = F_37 ( V_110 , V_62 , & V_21 , V_64 ,
- 1 , 1 ) ;
if ( V_29 ) {
F_387 ( V_13 , L_15 ,
V_29 , V_27 ) ;
F_388 ( V_62 , V_64 -> V_82 [ 0 ] ) ;
}
if ( V_29 < 0 ) {
F_150 ( V_110 , V_62 , V_29 ) ;
goto V_72;
}
V_518 = V_64 -> V_83 [ 0 ] ;
V_66 = V_64 -> V_82 [ 0 ] ;
V_118 = F_77 ( V_66 , V_518 ) ;
}
#endif
F_30 ( V_118 < sizeof( * V_117 ) ) ;
V_117 = F_78 ( V_66 , V_518 ,
struct V_116 ) ;
if ( V_516 < V_143 &&
V_21 . type == V_76 ) {
struct V_138 * V_139 ;
F_30 ( V_118 < sizeof( * V_117 ) + sizeof( * V_139 ) ) ;
V_139 = (struct V_138 * ) ( V_117 + 1 ) ;
F_8 ( V_516 != F_389 ( V_66 , V_139 ) ) ;
}
V_112 = F_79 ( V_66 , V_117 ) ;
if ( V_112 < V_159 ) {
F_387 ( V_13 , L_17
L_18 , V_159 , V_112 , V_27 ) ;
V_29 = - V_502 ;
F_150 ( V_110 , V_62 , V_29 ) ;
goto V_72;
}
V_112 -= V_159 ;
if ( V_112 > 0 ) {
if ( V_129 )
F_130 ( V_129 , V_66 , V_117 ) ;
if ( V_164 ) {
F_30 ( ! V_519 ) ;
} else {
F_90 ( V_66 , V_117 , V_112 ) ;
F_95 ( V_66 ) ;
}
if ( V_519 ) {
V_29 = F_139 ( V_110 , V_62 , V_64 ,
V_164 , V_159 ,
V_184 , & V_160 ) ;
if ( V_29 ) {
F_150 ( V_110 , V_62 , V_29 ) ;
goto V_72;
}
}
F_386 ( V_35 -> V_37 , - V_36 , V_516 ,
V_146 ) ;
} else {
if ( V_519 ) {
F_30 ( V_184 && V_159 !=
F_118 ( V_35 , V_64 , V_164 ) ) ;
if ( V_164 ) {
F_30 ( V_64 -> V_83 [ 0 ] != V_518 ) ;
} else {
F_30 ( V_64 -> V_83 [ 0 ] != V_518 + 1 ) ;
V_64 -> V_83 [ 0 ] = V_518 ;
V_520 = 2 ;
}
}
V_160 = 1 ;
V_29 = F_390 ( V_110 , V_62 , V_64 , V_64 -> V_83 [ 0 ] ,
V_520 ) ;
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
V_29 = F_368 ( V_110 , V_35 , V_27 , V_36 , 0 ) ;
if ( V_29 ) {
F_150 ( V_110 , V_62 , V_29 ) ;
goto V_72;
}
}
F_44 ( V_64 ) ;
V_72:
F_50 ( V_64 ) ;
return V_29 ;
}
static T_1 int F_391 ( struct V_109 * V_110 ,
struct V_34 * V_35 , T_2 V_27 )
{
struct V_113 * V_104 ;
struct V_114 * V_115 ;
int V_29 = 0 ;
V_115 = & V_110 -> V_127 -> V_115 ;
F_11 ( & V_115 -> V_52 ) ;
V_104 = F_84 ( V_110 , V_27 ) ;
if ( ! V_104 )
goto V_521;
F_11 ( & V_104 -> V_52 ) ;
if ( ! F_169 ( & V_104 -> V_216 ) )
goto V_72;
if ( V_104 -> V_129 ) {
if ( ! V_104 -> V_219 )
goto V_72;
F_178 ( V_104 -> V_129 ) ;
V_104 -> V_129 = NULL ;
}
if ( ! F_85 ( & V_104 -> V_78 ) )
goto V_72;
V_104 -> V_128 . V_223 = 0 ;
F_180 ( & V_104 -> V_225 , & V_115 -> V_226 ) ;
F_182 ( & V_115 -> V_227 ) ;
V_115 -> V_224 -- ;
if ( V_104 -> V_221 == 0 )
V_115 -> V_222 -- ;
V_104 -> V_221 = 0 ;
F_13 ( & V_104 -> V_52 ) ;
F_13 ( & V_115 -> V_52 ) ;
F_30 ( V_104 -> V_129 ) ;
if ( V_104 -> V_219 )
V_29 = 1 ;
F_46 ( & V_104 -> V_78 ) ;
F_86 ( & V_104 -> V_128 ) ;
return V_29 ;
V_72:
F_13 ( & V_104 -> V_52 ) ;
V_521:
F_13 ( & V_115 -> V_52 ) ;
return 0 ;
}
void F_392 ( struct V_109 * V_110 ,
struct V_34 * V_35 ,
struct V_65 * V_269 ,
T_2 V_17 , int V_160 )
{
int V_522 = 1 ;
int V_29 ;
if ( V_35 -> V_265 . V_22 != V_202 ) {
V_29 = F_146 ( V_35 -> V_37 , V_110 ,
V_269 -> V_32 , V_269 -> V_49 ,
V_17 , V_35 -> V_265 . V_22 ,
F_225 ( V_269 ) ,
V_212 , NULL , 0 ) ;
F_30 ( V_29 ) ;
}
if ( ! V_160 )
return;
if ( F_393 ( V_269 ) == V_110 -> V_290 ) {
struct V_1 * V_2 ;
if ( V_35 -> V_265 . V_22 != V_202 ) {
V_29 = F_391 ( V_110 , V_35 , V_269 -> V_32 ) ;
if ( ! V_29 )
goto V_72;
}
V_2 = F_68 ( V_35 -> V_37 , V_269 -> V_32 ) ;
if ( F_394 ( V_269 , V_523 ) ) {
F_374 ( V_35 , V_2 , V_269 -> V_32 , V_269 -> V_49 , 1 ) ;
F_6 ( V_2 ) ;
goto V_72;
}
F_8 ( F_226 ( V_524 , & V_269 -> V_525 ) ) ;
F_29 ( V_2 , V_269 -> V_32 , V_269 -> V_49 ) ;
F_380 ( V_2 , V_269 -> V_49 , V_508 , 0 ) ;
F_6 ( V_2 ) ;
F_375 ( V_35 , V_269 -> V_32 , V_269 -> V_49 ) ;
V_522 = 0 ;
}
V_72:
if ( V_522 )
F_386 ( V_35 -> V_37 , V_269 -> V_49 ,
F_225 ( V_269 ) ,
V_35 -> V_265 . V_22 ) ;
F_395 ( V_526 , & V_269 -> V_525 ) ;
}
int V_276 ( struct V_109 * V_110 , struct V_34 * V_35 ,
T_2 V_27 , T_2 V_36 , T_2 V_17 , T_2 V_146 ,
T_2 V_133 , T_2 V_33 , int V_201 )
{
int V_29 ;
struct V_12 * V_37 = V_35 -> V_37 ;
if ( F_223 ( V_35 ) )
return 0 ;
F_386 ( V_35 -> V_37 , V_36 , V_133 , V_146 ) ;
if ( V_146 == V_202 ) {
F_8 ( V_133 >= V_143 ) ;
F_163 ( V_35 , V_27 , V_36 , 1 ) ;
V_29 = 0 ;
} else if ( V_133 < V_143 ) {
V_29 = F_146 ( V_37 , V_110 , V_27 ,
V_36 ,
V_17 , V_146 , ( int ) V_133 ,
V_212 , NULL , V_201 ) ;
} else {
V_29 = F_147 ( V_37 , V_110 , V_27 ,
V_36 ,
V_17 , V_146 , V_133 ,
V_33 , V_212 ,
NULL , V_201 ) ;
}
return V_29 ;
}
static T_1 void
F_396 ( struct V_1 * V_2 ,
T_2 V_36 )
{
struct V_50 * V_53 ;
V_53 = F_25 ( V_2 ) ;
if ( ! V_53 )
return;
F_314 ( V_53 -> V_88 , F_1 ( V_2 ) ||
( V_2 -> V_11 -> V_527 >= V_36 ) ) ;
F_26 ( V_53 ) ;
}
static T_1 int
F_397 ( struct V_1 * V_2 )
{
struct V_50 * V_53 ;
int V_29 = 0 ;
V_53 = F_25 ( V_2 ) ;
if ( ! V_53 )
return ( V_2 -> V_3 == V_5 ) ? - V_175 : 0 ;
F_314 ( V_53 -> V_88 , F_1 ( V_2 ) ) ;
if ( V_2 -> V_3 == V_5 )
V_29 = - V_175 ;
F_26 ( V_53 ) ;
return V_29 ;
}
int F_398 ( T_2 V_7 )
{
if ( V_7 & V_321 )
return V_528 ;
else if ( V_7 & V_320 )
return V_529 ;
else if ( V_7 & V_319 )
return V_530 ;
else if ( V_7 & V_360 )
return V_531 ;
else if ( V_7 & V_361 )
return V_532 ;
else if ( V_7 & V_362 )
return V_533 ;
return V_534 ;
}
int F_399 ( struct V_1 * V_2 )
{
return F_398 ( V_2 -> V_7 ) ;
}
static const char * F_400 ( enum V_535 type )
{
if ( type >= V_326 )
return NULL ;
return V_536 [ type ] ;
}
static inline void
F_401 ( struct V_1 * V_2 ,
int V_507 )
{
if ( V_507 )
F_36 ( & V_2 -> V_537 ) ;
}
static inline void
F_402 ( struct V_1 * V_2 ,
int V_507 )
{
F_4 ( V_2 ) ;
if ( V_507 )
F_36 ( & V_2 -> V_537 ) ;
}
static struct V_1 *
F_403 ( struct V_1 * V_14 ,
struct V_538 * V_539 ,
int V_507 )
{
struct V_1 * V_540 ;
bool V_541 = false ;
V_77:
F_11 ( & V_539 -> V_542 ) ;
if ( V_541 ) {
if ( V_540 == V_539 -> V_14 )
return V_540 ;
F_45 ( & V_540 -> V_537 ) ;
F_6 ( V_540 ) ;
}
V_540 = V_539 -> V_14 ;
if ( ! V_540 )
return NULL ;
if ( V_540 == V_14 )
return V_540 ;
F_4 ( V_540 ) ;
if ( ! V_507 )
return V_540 ;
if ( F_307 ( & V_540 -> V_537 ) )
return V_540 ;
F_13 ( & V_539 -> V_542 ) ;
F_36 ( & V_540 -> V_537 ) ;
V_541 = true ;
goto V_77;
}
static inline void
F_404 ( struct V_1 * V_2 ,
int V_507 )
{
if ( V_507 )
F_45 ( & V_2 -> V_537 ) ;
F_6 ( V_2 ) ;
}
static T_1 int F_405 ( struct V_34 * V_543 ,
T_2 V_36 , T_2 V_544 ,
T_2 V_545 , struct V_67 * V_209 ,
T_2 V_7 , int V_507 )
{
int V_29 = 0 ;
struct V_34 * V_35 = V_543 -> V_37 -> V_62 ;
struct V_538 * V_546 = NULL ;
struct V_1 * V_14 = NULL ;
T_2 V_501 = 0 ;
T_2 V_547 = 0 ;
int V_548 = 2 * 1024 * 1024 ;
struct V_102 * V_105 ;
int V_549 = 0 ;
int V_550 = F_398 ( V_7 ) ;
int V_551 = ( V_7 & V_314 ) ?
V_552 : V_509 ;
bool V_553 = false ;
bool V_554 = false ;
bool V_555 = true ;
bool V_556 = false ;
F_8 ( V_36 < V_35 -> V_246 ) ;
V_209 -> type = V_76 ;
V_209 -> V_22 = 0 ;
V_209 -> V_33 = 0 ;
F_406 ( V_543 , V_36 , V_544 , V_7 ) ;
V_105 = F_69 ( V_35 -> V_37 , V_7 ) ;
if ( ! V_105 ) {
F_387 ( V_35 -> V_37 , L_19 , V_7 ) ;
return - V_375 ;
}
if ( F_303 ( V_105 ) )
V_555 = false ;
if ( V_7 & V_313 && V_555 ) {
V_546 = & V_35 -> V_37 -> V_557 ;
if ( ! F_247 ( V_35 , V_558 ) )
V_548 = 64 * 1024 ;
}
if ( ( V_7 & V_314 ) && V_555 &&
F_247 ( V_35 , V_558 ) ) {
V_546 = & V_35 -> V_37 -> V_559 ;
}
if ( V_546 ) {
F_11 ( & V_546 -> V_52 ) ;
if ( V_546 -> V_14 )
V_545 = V_546 -> V_560 ;
F_13 ( & V_546 -> V_52 ) ;
}
V_501 = F_407 ( V_501 , V_26 ( V_35 , 0 ) ) ;
V_501 = F_407 ( V_501 , V_545 ) ;
if ( ! V_546 )
V_548 = 0 ;
if ( V_501 == V_545 ) {
V_14 = F_68 ( V_35 -> V_37 ,
V_501 ) ;
if ( V_14 && F_3 ( V_14 , V_7 ) &&
V_14 -> V_3 != V_94 ) {
F_36 ( & V_105 -> V_328 ) ;
if ( F_169 ( & V_14 -> V_90 ) ||
V_14 -> V_288 ) {
F_6 ( V_14 ) ;
F_45 ( & V_105 -> V_328 ) ;
} else {
V_550 = F_399 ( V_14 ) ;
F_401 ( V_14 , V_507 ) ;
goto V_561;
}
} else if ( V_14 ) {
F_6 ( V_14 ) ;
}
}
V_562:
V_556 = false ;
F_36 ( & V_105 -> V_328 ) ;
F_170 (block_group, &space_info->block_groups[index],
list) {
T_2 V_33 ;
int V_3 ;
F_402 ( V_14 , V_507 ) ;
V_501 = V_14 -> V_21 . V_22 ;
if ( ! F_3 ( V_14 , V_7 ) ) {
T_2 V_563 = V_319 |
V_320 |
V_361 |
V_362 |
V_321 ;
if ( ( V_7 & V_563 ) && ! ( V_14 -> V_7 & V_563 ) )
goto V_549;
}
V_561:
V_3 = F_1 ( V_14 ) ;
if ( F_330 ( ! V_3 ) ) {
V_29 = F_51 ( V_14 , 0 ) ;
F_30 ( V_29 < 0 ) ;
V_29 = 0 ;
}
if ( F_330 ( V_14 -> V_3 == V_5 ) )
goto V_549;
if ( F_330 ( V_14 -> V_288 ) )
goto V_549;
if ( V_546 ) {
struct V_1 * V_564 ;
unsigned long V_565 ;
V_564 = F_403 ( V_14 ,
V_546 ,
V_507 ) ;
if ( ! V_564 )
goto V_566;
if ( V_564 != V_14 &&
( V_564 -> V_288 ||
! F_3 ( V_564 , V_7 ) ) )
goto V_567;
V_33 = F_408 ( V_564 ,
V_546 ,
V_36 ,
V_564 -> V_21 . V_22 ,
& V_547 ) ;
if ( V_33 ) {
F_13 ( & V_546 -> V_542 ) ;
F_409 ( V_35 ,
V_564 ,
V_501 , V_36 ) ;
if ( V_564 != V_14 ) {
F_404 ( V_14 ,
V_507 ) ;
V_14 = V_564 ;
}
goto V_568;
}
F_8 ( V_546 -> V_14 != V_564 ) ;
V_567:
if ( V_549 >= V_569 &&
V_564 != V_14 ) {
F_13 ( & V_546 -> V_542 ) ;
F_404 ( V_564 ,
V_507 ) ;
goto V_570;
}
F_410 ( NULL , V_546 ) ;
if ( V_564 != V_14 )
F_404 ( V_564 ,
V_507 ) ;
V_566:
if ( V_549 >= V_569 ) {
F_13 ( & V_546 -> V_542 ) ;
goto V_570;
}
V_565 = F_34 (unsigned long,
empty_cluster + empty_size,
block_group->full_stripe_len) ;
V_29 = F_411 ( V_35 , V_14 ,
V_546 , V_501 ,
V_36 ,
V_565 ) ;
if ( V_29 == 0 ) {
V_33 = F_408 ( V_14 ,
V_546 ,
V_36 ,
V_501 ,
& V_547 ) ;
if ( V_33 ) {
F_13 ( & V_546 -> V_542 ) ;
F_409 ( V_35 ,
V_14 , V_501 ,
V_36 ) ;
goto V_568;
}
} else if ( ! V_3 && V_549 > V_571
&& ! V_553 ) {
F_13 ( & V_546 -> V_542 ) ;
V_553 = true ;
F_396 ( V_14 ,
V_36 + V_548 + V_544 ) ;
goto V_561;
}
F_410 ( NULL , V_546 ) ;
F_13 ( & V_546 -> V_542 ) ;
goto V_549;
}
V_570:
F_11 ( & V_14 -> V_11 -> V_572 ) ;
if ( V_3 &&
V_14 -> V_11 -> V_527 <
V_36 + V_548 + V_544 ) {
if ( V_14 -> V_11 -> V_527 >
V_547 )
V_547 =
V_14 -> V_11 -> V_527 ;
F_13 ( & V_14 -> V_11 -> V_572 ) ;
goto V_549;
}
F_13 ( & V_14 -> V_11 -> V_572 ) ;
V_33 = F_412 ( V_14 , V_501 ,
V_36 , V_544 ,
& V_547 ) ;
if ( ! V_33 && ! V_554 && ! V_3 &&
V_549 > V_571 ) {
F_396 ( V_14 ,
V_36 + V_544 ) ;
V_554 = true ;
goto V_561;
} else if ( ! V_33 ) {
if ( ! V_3 )
V_556 = true ;
goto V_549;
}
V_568:
V_501 = F_281 ( V_33 , V_35 -> V_573 ) ;
if ( V_501 + V_36 >
V_14 -> V_21 . V_22 + V_14 -> V_21 . V_33 ) {
F_29 ( V_14 , V_33 , V_36 ) ;
goto V_549;
}
if ( V_33 < V_501 )
F_29 ( V_14 , V_33 ,
V_501 - V_33 ) ;
F_30 ( V_33 > V_501 ) ;
V_29 = F_380 ( V_14 , V_36 ,
V_551 , V_507 ) ;
if ( V_29 == - V_178 ) {
F_29 ( V_14 , V_33 , V_36 ) ;
goto V_549;
}
V_209 -> V_22 = V_501 ;
V_209 -> V_33 = V_36 ;
F_413 ( V_543 , V_14 ,
V_501 , V_36 ) ;
F_404 ( V_14 , V_507 ) ;
break;
V_549:
V_553 = false ;
V_554 = false ;
F_30 ( V_550 != F_399 ( V_14 ) ) ;
F_404 ( V_14 , V_507 ) ;
}
F_45 ( & V_105 -> V_328 ) ;
if ( ! V_209 -> V_22 && V_549 >= V_574 && V_556 )
goto V_562;
if ( ! V_209 -> V_22 && ++ V_550 < V_326 )
goto V_562;
if ( ! V_209 -> V_22 && V_549 < V_569 ) {
V_550 = 0 ;
V_549 ++ ;
if ( V_549 == V_575 ) {
struct V_109 * V_110 ;
int V_576 = 0 ;
V_110 = V_370 -> V_371 ;
if ( V_110 )
V_576 = 1 ;
else
V_110 = F_199 ( V_35 ) ;
if ( F_200 ( V_110 ) ) {
V_29 = F_201 ( V_110 ) ;
goto V_72;
}
V_29 = F_283 ( V_110 , V_35 , V_7 ,
V_374 ) ;
if ( V_29 < 0 && V_29 != - V_375 )
F_150 ( V_110 ,
V_35 , V_29 ) ;
else
V_29 = 0 ;
if ( ! V_576 )
F_203 ( V_110 , V_35 ) ;
if ( V_29 )
goto V_72;
}
if ( V_549 == V_569 ) {
V_544 = 0 ;
V_548 = 0 ;
}
goto V_562;
} else if ( ! V_209 -> V_22 ) {
V_29 = - V_375 ;
} else if ( V_209 -> V_22 ) {
V_29 = 0 ;
}
V_72:
if ( V_29 == - V_375 )
V_209 -> V_33 = V_547 ;
return V_29 ;
}
static void F_300 ( struct V_102 * V_13 , T_2 V_365 ,
int V_577 )
{
struct V_1 * V_2 ;
int V_550 = 0 ;
F_11 ( & V_13 -> V_52 ) ;
F_414 ( V_578 L_20 ,
V_13 -> V_7 ,
V_13 -> V_316 - V_13 -> V_317 - V_13 -> V_329 -
V_13 -> V_330 - V_13 -> V_331 ,
( V_13 -> V_108 ) ? L_21 : L_22 ) ;
F_414 ( V_578 L_23
L_24 ,
V_13 -> V_316 , V_13 -> V_317 , V_13 -> V_329 ,
V_13 -> V_330 , V_13 -> V_332 ,
V_13 -> V_331 ) ;
F_13 ( & V_13 -> V_52 ) ;
if ( ! V_577 )
return;
F_36 ( & V_13 -> V_328 ) ;
V_77:
F_170 (cache, &info->block_groups[index], list) {
F_11 ( & V_2 -> V_52 ) ;
F_414 ( V_578 L_25
L_26
L_27 ,
V_2 -> V_21 . V_22 , V_2 -> V_21 . V_33 ,
F_371 ( & V_2 -> V_135 ) , V_2 -> V_9 ,
V_2 -> V_10 , V_2 -> V_288 ? L_28 : L_21 ) ;
F_415 ( V_2 , V_365 ) ;
F_13 ( & V_2 -> V_52 ) ;
}
if ( ++ V_550 < V_326 )
goto V_77;
F_45 ( & V_13 -> V_328 ) ;
}
int F_416 ( struct V_34 * V_35 ,
T_2 V_36 , T_2 V_579 ,
T_2 V_544 , T_2 V_545 ,
struct V_67 * V_209 , int V_184 , int V_507 )
{
bool V_580 = false ;
T_2 V_7 ;
int V_29 ;
V_7 = F_280 ( V_35 , V_184 ) ;
V_77:
F_8 ( V_36 < V_35 -> V_246 ) ;
V_29 = F_405 ( V_35 , V_36 , V_544 , V_545 , V_209 ,
V_7 , V_507 ) ;
if ( V_29 == - V_375 ) {
if ( ! V_580 && V_209 -> V_33 ) {
V_36 = F_313 ( V_36 >> 1 , V_209 -> V_33 ) ;
V_36 = F_417 ( V_36 , V_35 -> V_246 ) ;
V_36 = F_407 ( V_36 , V_579 ) ;
if ( V_36 == V_579 )
V_580 = true ;
goto V_77;
} else if ( F_247 ( V_35 , V_390 ) ) {
struct V_102 * V_381 ;
V_381 = F_69 ( V_35 -> V_37 , V_7 ) ;
F_387 ( V_35 -> V_37 , L_29 ,
V_7 , V_36 ) ;
if ( V_381 )
F_300 ( V_381 , V_36 , 1 ) ;
}
}
return V_29 ;
}
static int F_418 ( struct V_34 * V_35 ,
T_2 V_32 , T_2 V_49 ,
int V_522 , int V_507 )
{
struct V_1 * V_2 ;
int V_29 = 0 ;
V_2 = F_68 ( V_35 -> V_37 , V_32 ) ;
if ( ! V_2 ) {
F_387 ( V_35 -> V_37 , L_30 ,
V_32 ) ;
return - V_375 ;
}
if ( V_522 )
F_374 ( V_35 , V_2 , V_32 , V_49 , 1 ) ;
else {
if ( F_247 ( V_35 , V_514 ) )
V_29 = F_142 ( V_35 , V_32 , V_49 , NULL ) ;
F_29 ( V_2 , V_32 , V_49 ) ;
F_380 ( V_2 , V_49 , V_508 , V_507 ) ;
}
F_6 ( V_2 ) ;
F_375 ( V_35 , V_32 , V_49 ) ;
return V_29 ;
}
int F_419 ( struct V_34 * V_35 ,
T_2 V_32 , T_2 V_49 , int V_507 )
{
return F_418 ( V_35 , V_32 , V_49 , 0 , V_507 ) ;
}
int F_420 ( struct V_34 * V_35 ,
T_2 V_32 , T_2 V_49 )
{
return F_418 ( V_35 , V_32 , V_49 , 1 , 0 ) ;
}
static int F_154 ( struct V_109 * V_110 ,
struct V_34 * V_35 ,
T_2 V_17 , T_2 V_146 ,
T_2 V_7 , T_2 V_133 , T_2 V_33 ,
struct V_67 * V_209 , int V_132 )
{
int V_29 ;
struct V_12 * V_37 = V_35 -> V_37 ;
struct V_116 * V_581 ;
struct V_163 * V_164 ;
struct V_63 * V_64 ;
struct V_65 * V_66 ;
int type ;
T_3 V_56 ;
if ( V_17 > 0 )
type = V_154 ;
else
type = V_155 ;
V_56 = sizeof( * V_581 ) + F_125 ( type ) ;
V_64 = F_33 () ;
if ( ! V_64 )
return - V_71 ;
V_64 -> V_206 = 1 ;
V_29 = F_106 ( V_110 , V_37 -> V_62 , V_64 ,
V_209 , V_56 ) ;
if ( V_29 ) {
F_50 ( V_64 ) ;
return V_29 ;
}
V_66 = V_64 -> V_82 [ 0 ] ;
V_581 = F_78 ( V_66 , V_64 -> V_83 [ 0 ] ,
struct V_116 ) ;
F_90 ( V_66 , V_581 , V_132 ) ;
F_91 ( V_66 , V_581 , V_110 -> V_290 ) ;
F_92 ( V_66 , V_581 ,
V_7 | V_145 ) ;
V_164 = (struct V_163 * ) ( V_581 + 1 ) ;
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
V_29 = F_368 ( V_110 , V_35 , V_209 -> V_22 , V_209 -> V_33 , 1 ) ;
if ( V_29 ) {
F_387 ( V_37 , L_31 ,
V_209 -> V_22 , V_209 -> V_33 ) ;
F_83 () ;
}
F_421 ( V_35 , V_209 -> V_22 , V_209 -> V_33 ) ;
return V_29 ;
}
static int F_161 ( struct V_109 * V_110 ,
struct V_34 * V_35 ,
T_2 V_17 , T_2 V_146 ,
T_2 V_7 , struct V_582 * V_21 ,
int V_167 , struct V_67 * V_209 ,
int V_201 )
{
int V_29 ;
struct V_12 * V_37 = V_35 -> V_37 ;
struct V_116 * V_581 ;
struct V_138 * V_583 ;
struct V_163 * V_164 ;
struct V_63 * V_64 ;
struct V_65 * V_66 ;
T_3 V_56 = sizeof( * V_581 ) + sizeof( * V_164 ) ;
T_2 V_36 = V_209 -> V_33 ;
bool V_173 = F_76 ( V_35 -> V_37 ,
V_121 ) ;
if ( ! V_173 )
V_56 += sizeof( * V_583 ) ;
V_64 = F_33 () ;
if ( ! V_64 ) {
F_420 ( V_35 , V_209 -> V_22 ,
V_35 -> V_87 ) ;
return - V_71 ;
}
V_64 -> V_206 = 1 ;
V_29 = F_106 ( V_110 , V_37 -> V_62 , V_64 ,
V_209 , V_56 ) ;
if ( V_29 ) {
F_50 ( V_64 ) ;
F_420 ( V_35 , V_209 -> V_22 ,
V_35 -> V_87 ) ;
return V_29 ;
}
V_66 = V_64 -> V_82 [ 0 ] ;
V_581 = F_78 ( V_66 , V_64 -> V_83 [ 0 ] ,
struct V_116 ) ;
F_90 ( V_66 , V_581 , 1 ) ;
F_91 ( V_66 , V_581 , V_110 -> V_290 ) ;
F_92 ( V_66 , V_581 ,
V_7 | V_144 ) ;
if ( V_173 ) {
V_164 = (struct V_163 * ) ( V_581 + 1 ) ;
V_36 = V_35 -> V_87 ;
} else {
V_583 = (struct V_138 * ) ( V_581 + 1 ) ;
F_156 ( V_66 , V_583 , V_21 ) ;
F_94 ( V_66 , V_583 , V_167 ) ;
V_164 = (struct V_163 * ) ( V_583 + 1 ) ;
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
V_29 = F_368 ( V_110 , V_35 , V_209 -> V_22 , V_35 -> V_87 ,
1 ) ;
if ( V_29 ) {
F_387 ( V_37 , L_31 ,
V_209 -> V_22 , V_209 -> V_33 ) ;
F_83 () ;
}
F_421 ( V_35 , V_209 -> V_22 , V_35 -> V_87 ) ;
return V_29 ;
}
int F_422 ( struct V_109 * V_110 ,
struct V_34 * V_35 ,
T_2 V_146 , T_2 V_133 ,
T_2 V_33 , struct V_67 * V_209 )
{
int V_29 ;
F_30 ( V_146 == V_202 ) ;
V_29 = F_147 ( V_35 -> V_37 , V_110 , V_209 -> V_22 ,
V_209 -> V_33 , 0 ,
V_146 , V_133 , V_33 ,
V_228 , NULL , 0 ) ;
return V_29 ;
}
int F_423 ( struct V_109 * V_110 ,
struct V_34 * V_35 ,
T_2 V_146 , T_2 V_133 , T_2 V_33 ,
struct V_67 * V_209 )
{
int V_29 ;
struct V_1 * V_14 ;
if ( ! F_76 ( V_35 -> V_37 , V_506 ) ) {
V_29 = F_378 ( V_35 , V_209 -> V_22 , V_209 -> V_33 ) ;
if ( V_29 )
return V_29 ;
}
V_14 = F_68 ( V_35 -> V_37 , V_209 -> V_22 ) ;
if ( ! V_14 )
return - V_502 ;
V_29 = F_380 ( V_14 , V_209 -> V_33 ,
V_552 , 0 ) ;
F_30 ( V_29 ) ;
V_29 = F_154 ( V_110 , V_35 , 0 , V_146 ,
0 , V_133 , V_33 , V_209 , 1 ) ;
F_6 ( V_14 ) ;
return V_29 ;
}
static struct V_65 *
F_424 ( struct V_109 * V_110 , struct V_34 * V_35 ,
T_2 V_27 , int V_167 )
{
struct V_65 * V_269 ;
V_269 = F_425 ( V_35 , V_27 ) ;
if ( ! V_269 )
return F_426 ( - V_71 ) ;
F_427 ( V_269 , V_110 -> V_290 ) ;
F_428 ( V_35 -> V_265 . V_22 , V_269 , V_167 ) ;
F_429 ( V_269 ) ;
F_430 ( V_110 , V_35 -> V_37 , V_269 ) ;
F_395 ( V_584 , & V_269 -> V_525 ) ;
F_431 ( V_269 ) ;
F_432 ( V_269 ) ;
if ( V_35 -> V_265 . V_22 == V_202 ) {
V_269 -> V_585 = V_35 -> V_586 % 2 ;
if ( V_269 -> V_585 == 0 )
F_373 ( & V_35 -> V_587 , V_269 -> V_32 ,
V_269 -> V_32 + V_269 -> V_49 - 1 , V_40 ) ;
else
F_433 ( & V_35 -> V_587 , V_269 -> V_32 ,
V_269 -> V_32 + V_269 -> V_49 - 1 , V_40 ) ;
} else {
V_269 -> V_585 = - 1 ;
F_373 ( & V_110 -> V_127 -> V_588 , V_269 -> V_32 ,
V_269 -> V_32 + V_269 -> V_49 - 1 , V_40 ) ;
}
V_110 -> V_589 ++ ;
return V_269 ;
}
static struct V_247 *
F_434 ( struct V_109 * V_110 ,
struct V_34 * V_35 , T_3 V_590 )
{
struct V_247 * V_414 ;
struct V_247 * V_248 = & V_35 -> V_37 -> V_251 ;
int V_29 ;
bool V_591 = false ;
V_414 = F_333 ( V_110 , V_35 ) ;
if ( F_330 ( V_414 -> V_56 == 0 ) )
goto V_592;
V_77:
V_29 = F_331 ( V_414 , V_590 ) ;
if ( ! V_29 )
return V_414 ;
if ( V_414 -> V_593 )
return F_426 ( V_29 ) ;
if ( V_414 -> type == V_594 && ! V_591 ) {
V_591 = true ;
F_347 ( V_35 -> V_37 ) ;
goto V_77;
}
if ( F_247 ( V_35 , V_390 ) ) {
static F_435 ( V_595 ,
V_596 * 10 ,
1 ) ;
if ( F_436 ( & V_595 ) )
F_437 ( 1 , V_597
L_32 , V_29 ) ;
}
V_592:
V_29 = F_326 ( V_35 , V_414 , V_590 ,
V_392 ) ;
if ( ! V_29 )
return V_414 ;
if ( V_414 -> type != V_594 &&
V_414 -> V_105 == V_248 -> V_105 ) {
V_29 = F_331 ( V_248 , V_590 ) ;
if ( ! V_29 )
return V_248 ;
}
return F_426 ( V_29 ) ;
}
static void F_438 ( struct V_12 * V_37 ,
struct V_247 * V_414 , T_3 V_590 )
{
F_334 ( V_414 , V_590 , 0 ) ;
F_336 ( V_37 , V_414 , NULL , 0 ) ;
}
struct V_65 * F_439 ( struct V_109 * V_110 ,
struct V_34 * V_35 ,
T_2 V_17 , T_2 V_146 ,
struct V_582 * V_21 , int V_167 ,
T_2 V_598 , T_2 V_544 )
{
struct V_67 V_209 ;
struct V_247 * V_414 ;
struct V_65 * V_269 ;
struct V_180 * V_129 ;
T_2 V_7 = 0 ;
int V_29 ;
T_3 V_590 = V_35 -> V_87 ;
bool V_173 = F_76 ( V_35 -> V_37 ,
V_121 ) ;
if ( F_223 ( V_35 ) ) {
V_269 = F_424 ( V_110 , V_35 , V_35 -> V_599 ,
V_167 ) ;
if ( ! F_200 ( V_269 ) )
V_35 -> V_599 += V_590 ;
return V_269 ;
}
V_414 = F_434 ( V_110 , V_35 , V_590 ) ;
if ( F_200 ( V_414 ) )
return F_440 ( V_414 ) ;
V_29 = F_416 ( V_35 , V_590 , V_590 ,
V_544 , V_598 , & V_209 , 0 , 0 ) ;
if ( V_29 )
goto V_600;
V_269 = F_424 ( V_110 , V_35 , V_209 . V_22 , V_167 ) ;
if ( F_200 ( V_269 ) ) {
V_29 = F_201 ( V_269 ) ;
goto V_601;
}
if ( V_146 == V_602 ) {
if ( V_17 == 0 )
V_17 = V_209 . V_22 ;
V_7 |= V_126 ;
} else
F_30 ( V_17 > 0 ) ;
if ( V_146 != V_202 ) {
V_129 = F_214 () ;
if ( ! V_129 ) {
V_29 = - V_71 ;
goto V_603;
}
if ( V_21 )
memcpy ( & V_129 -> V_21 , V_21 , sizeof( V_129 -> V_21 ) ) ;
else
memset ( & V_129 -> V_21 , 0 , sizeof( V_129 -> V_21 ) ) ;
V_129 -> V_131 = V_7 ;
if ( V_173 )
V_129 -> V_213 = 0 ;
else
V_129 -> V_213 = 1 ;
V_129 -> V_130 = 1 ;
V_129 -> V_184 = 0 ;
V_129 -> V_167 = V_167 ;
V_29 = F_146 ( V_35 -> V_37 , V_110 ,
V_209 . V_22 , V_209 . V_33 ,
V_17 , V_146 , V_167 ,
V_228 ,
V_129 , 0 ) ;
if ( V_29 )
goto V_604;
}
return V_269 ;
V_604:
F_178 ( V_129 ) ;
V_603:
F_441 ( V_269 ) ;
V_601:
F_419 ( V_35 , V_209 . V_22 , V_209 . V_33 , 0 ) ;
V_600:
F_438 ( V_35 -> V_37 , V_414 , V_590 ) ;
return F_426 ( V_29 ) ;
}
static T_1 void F_442 ( struct V_109 * V_110 ,
struct V_34 * V_35 ,
struct V_605 * V_606 ,
struct V_63 * V_64 )
{
T_2 V_27 ;
T_2 V_293 ;
T_2 V_112 ;
T_2 V_7 ;
T_3 V_70 ;
T_3 V_590 ;
struct V_67 V_21 ;
struct V_65 * V_504 ;
int V_29 ;
int V_607 ;
int V_608 = 0 ;
if ( V_64 -> V_83 [ V_606 -> V_167 ] < V_606 -> V_609 ) {
V_606 -> V_610 = V_606 -> V_610 * 2 / 3 ;
V_606 -> V_610 = F_407 ( V_606 -> V_610 , 2 ) ;
} else {
V_606 -> V_610 = V_606 -> V_610 * 3 / 2 ;
V_606 -> V_610 = F_24 ( int , V_606 -> V_610 ,
F_443 ( V_35 ) ) ;
}
V_504 = V_64 -> V_82 [ V_606 -> V_167 ] ;
V_70 = F_38 ( V_504 ) ;
V_590 = V_35 -> V_87 ;
for ( V_607 = V_64 -> V_83 [ V_606 -> V_167 ] ; V_607 < V_70 ; V_607 ++ ) {
if ( V_608 >= V_606 -> V_610 )
break;
F_47 () ;
V_27 = F_231 ( V_504 , V_607 ) ;
V_293 = F_444 ( V_504 , V_607 ) ;
if ( V_607 == V_64 -> V_83 [ V_606 -> V_167 ] )
goto V_75;
if ( V_606 -> V_611 == V_612 &&
V_293 <= V_35 -> V_265 . V_33 )
continue;
V_29 = F_75 ( V_110 , V_35 , V_27 ,
V_606 -> V_167 - 1 , 1 , & V_112 ,
& V_7 ) ;
if ( V_29 < 0 )
continue;
F_30 ( V_112 == 0 ) ;
if ( V_606 -> V_611 == V_613 ) {
if ( V_112 == 1 )
goto V_75;
if ( V_606 -> V_167 == 1 &&
( V_7 & V_126 ) )
continue;
if ( ! V_606 -> V_614 ||
V_293 <= V_35 -> V_265 . V_33 )
continue;
F_123 ( V_504 , & V_21 , V_607 ) ;
V_29 = F_445 ( & V_21 ,
& V_606 -> V_615 ) ;
if ( V_29 < 0 )
continue;
} else {
if ( V_606 -> V_167 == 1 &&
( V_7 & V_126 ) )
continue;
}
V_75:
F_446 ( V_35 , V_27 ) ;
V_608 ++ ;
}
V_606 -> V_609 = V_607 ;
}
static int F_447 ( struct V_109 * V_110 ,
struct V_34 * V_35 ,
struct V_65 * V_504 )
{
int V_44 = F_38 ( V_504 ) ;
int V_43 , V_616 ;
struct V_67 V_21 ;
struct V_272 * V_273 ;
T_2 V_27 , V_36 ;
for ( V_43 = 0 ; V_43 < V_44 ; V_43 ++ ) {
F_40 ( V_504 , & V_21 , V_43 ) ;
if ( V_21 . type != V_277 )
continue;
V_273 = F_78 ( V_504 , V_43 , struct V_272 ) ;
V_616 = F_227 ( V_504 , V_273 ) ;
if ( V_616 == V_278 )
continue;
V_27 = F_228 ( V_504 , V_273 ) ;
if ( ! V_27 )
continue;
V_36 = F_229 ( V_504 , V_273 ) ;
}
return 0 ;
}
static int F_448 ( struct V_34 * V_35 ,
struct V_63 * V_64 , int V_617 )
{
int V_167 = 0 ;
int V_44 , V_607 ;
struct V_65 * V_504 ;
if ( V_617 == 0 )
return 1 ;
while ( V_167 <= V_617 ) {
V_504 = V_64 -> V_82 [ V_167 ] ;
V_44 = F_38 ( V_504 ) ;
V_64 -> V_83 [ V_167 ] ++ ;
V_607 = V_64 -> V_83 [ V_167 ] ;
if ( V_607 >= V_44 || V_167 == 0 ) {
if ( V_167 != V_617 ) {
F_449 ( V_504 , V_64 -> V_618 [ V_167 ] ) ;
V_64 -> V_618 [ V_167 ] = 0 ;
F_441 ( V_504 ) ;
V_64 -> V_82 [ V_167 ] = NULL ;
V_64 -> V_83 [ V_167 ] = 0 ;
}
} else {
break;
}
V_167 ++ ;
}
V_504 = V_64 -> V_82 [ V_617 ] ;
if ( V_64 -> V_83 [ V_617 ] >= F_38 ( V_504 ) )
return 1 ;
return 0 ;
}
static int F_450 ( struct V_109 * V_110 ,
struct V_34 * V_35 ,
struct V_65 * V_619 ,
T_2 V_620 ,
int V_617 )
{
int V_29 = 0 ;
int V_167 ;
struct V_65 * V_504 = V_619 ;
struct V_63 * V_64 = NULL ;
F_30 ( V_617 < 0 || V_617 > V_168 ) ;
F_30 ( V_619 == NULL ) ;
if ( ! V_35 -> V_37 -> V_205 )
return 0 ;
if ( ! F_451 ( V_619 ) ) {
V_29 = F_452 ( V_619 , V_620 ) ;
if ( V_29 )
goto V_72;
}
if ( V_617 == 0 ) {
V_29 = F_447 ( V_110 , V_35 , V_619 ) ;
goto V_72;
}
V_64 = F_33 () ;
if ( ! V_64 )
return - V_71 ;
F_453 ( V_619 ) ;
V_64 -> V_82 [ V_617 ] = V_619 ;
V_64 -> V_83 [ V_617 ] = 0 ;
V_64 -> V_618 [ V_617 ] = 0 ;
V_621:
V_167 = V_617 ;
while ( V_167 >= 0 ) {
if ( V_64 -> V_82 [ V_167 ] == NULL ) {
int V_622 ;
T_2 V_623 ;
T_2 V_624 ;
V_504 = V_64 -> V_82 [ V_167 + 1 ] ;
V_622 = V_64 -> V_83 [ V_167 + 1 ] ;
V_624 = F_231 ( V_504 , V_622 ) ;
V_623 = F_444 ( V_504 , V_622 ) ;
V_504 = F_454 ( V_35 , V_624 , V_623 ) ;
if ( F_200 ( V_504 ) ) {
V_29 = F_201 ( V_504 ) ;
goto V_72;
} else if ( ! F_451 ( V_504 ) ) {
F_441 ( V_504 ) ;
V_29 = - V_175 ;
goto V_72;
}
V_64 -> V_82 [ V_167 ] = V_504 ;
V_64 -> V_83 [ V_167 ] = 0 ;
F_455 ( V_504 ) ;
F_456 ( V_504 , V_625 ) ;
V_64 -> V_618 [ V_167 ] = V_626 ;
}
if ( V_167 == 0 ) {
V_29 = F_447 ( V_110 , V_35 , V_64 -> V_82 [ V_167 ] ) ;
if ( V_29 )
goto V_72;
V_29 = F_448 ( V_35 , V_64 , V_617 ) ;
if ( V_29 )
break;
goto V_621;
}
V_167 -- ;
}
V_29 = 0 ;
V_72:
F_50 ( V_64 ) ;
return V_29 ;
}
static T_1 int F_457 ( struct V_109 * V_110 ,
struct V_34 * V_35 ,
struct V_63 * V_64 ,
struct V_605 * V_606 , int V_627 )
{
int V_167 = V_606 -> V_167 ;
struct V_65 * V_504 = V_64 -> V_82 [ V_167 ] ;
T_2 V_628 = V_126 ;
int V_29 ;
if ( V_606 -> V_611 == V_612 &&
F_224 ( V_504 ) != V_35 -> V_265 . V_22 )
return 1 ;
if ( V_627 &&
( ( V_606 -> V_611 == V_613 && V_606 -> V_112 [ V_167 ] != 1 ) ||
( V_606 -> V_611 == V_612 && ! ( V_606 -> V_7 [ V_167 ] & V_628 ) ) ) ) {
F_30 ( ! V_64 -> V_618 [ V_167 ] ) ;
V_29 = F_75 ( V_110 , V_35 ,
V_504 -> V_32 , V_167 , 1 ,
& V_606 -> V_112 [ V_167 ] ,
& V_606 -> V_7 [ V_167 ] ) ;
F_30 ( V_29 == - V_71 ) ;
if ( V_29 )
return V_29 ;
F_30 ( V_606 -> V_112 [ V_167 ] == 0 ) ;
}
if ( V_606 -> V_611 == V_613 ) {
if ( V_606 -> V_112 [ V_167 ] > 1 )
return 1 ;
if ( V_64 -> V_618 [ V_167 ] && ! V_606 -> V_174 ) {
F_449 ( V_504 , V_64 -> V_618 [ V_167 ] ) ;
V_64 -> V_618 [ V_167 ] = 0 ;
}
return 0 ;
}
if ( ! ( V_606 -> V_7 [ V_167 ] & V_628 ) ) {
F_30 ( ! V_64 -> V_618 [ V_167 ] ) ;
V_29 = F_232 ( V_110 , V_35 , V_504 , 1 ) ;
F_30 ( V_29 ) ;
V_29 = F_233 ( V_110 , V_35 , V_504 , 0 ) ;
F_30 ( V_29 ) ;
V_29 = F_213 ( V_110 , V_35 , V_504 -> V_32 ,
V_504 -> V_49 , V_628 ,
F_225 ( V_504 ) , 0 ) ;
F_30 ( V_29 ) ;
V_606 -> V_7 [ V_167 ] |= V_628 ;
}
if ( V_64 -> V_618 [ V_167 ] && V_167 > 0 ) {
F_449 ( V_504 , V_64 -> V_618 [ V_167 ] ) ;
V_64 -> V_618 [ V_167 ] = 0 ;
}
return 0 ;
}
static T_1 int F_458 ( struct V_109 * V_110 ,
struct V_34 * V_35 ,
struct V_63 * V_64 ,
struct V_605 * V_606 , int * V_627 )
{
T_2 V_27 ;
T_2 V_293 ;
T_2 V_17 ;
T_3 V_590 ;
struct V_67 V_21 ;
struct V_65 * V_80 ;
int V_167 = V_606 -> V_167 ;
int V_75 = 0 ;
int V_29 = 0 ;
bool V_629 = false ;
V_293 = F_444 ( V_64 -> V_82 [ V_167 ] ,
V_64 -> V_83 [ V_167 ] ) ;
if ( V_606 -> V_611 == V_612 &&
V_293 <= V_35 -> V_265 . V_33 ) {
* V_627 = 1 ;
return 1 ;
}
V_27 = F_231 ( V_64 -> V_82 [ V_167 ] , V_64 -> V_83 [ V_167 ] ) ;
V_590 = V_35 -> V_87 ;
V_80 = F_459 ( V_35 -> V_37 , V_27 ) ;
if ( ! V_80 ) {
V_80 = F_425 ( V_35 , V_27 ) ;
if ( ! V_80 )
return - V_71 ;
F_428 ( V_35 -> V_265 . V_22 , V_80 ,
V_167 - 1 ) ;
V_75 = 1 ;
}
F_429 ( V_80 ) ;
F_431 ( V_80 ) ;
V_29 = F_75 ( V_110 , V_35 , V_27 , V_167 - 1 , 1 ,
& V_606 -> V_112 [ V_167 - 1 ] ,
& V_606 -> V_7 [ V_167 - 1 ] ) ;
if ( V_29 < 0 ) {
F_460 ( V_80 ) ;
return V_29 ;
}
if ( F_330 ( V_606 -> V_112 [ V_167 - 1 ] == 0 ) ) {
F_387 ( V_35 -> V_37 , L_33 ) ;
F_83 () ;
}
* V_627 = 0 ;
if ( V_606 -> V_611 == V_613 ) {
if ( V_606 -> V_112 [ V_167 - 1 ] > 1 ) {
V_629 = true ;
if ( V_167 == 1 &&
( V_606 -> V_7 [ 0 ] & V_126 ) )
goto V_630;
if ( ! V_606 -> V_614 ||
V_293 <= V_35 -> V_265 . V_33 )
goto V_630;
F_123 ( V_64 -> V_82 [ V_167 ] , & V_21 ,
V_64 -> V_83 [ V_167 ] ) ;
V_29 = F_445 ( & V_21 , & V_606 -> V_615 ) ;
if ( V_29 < 0 )
goto V_630;
V_606 -> V_611 = V_612 ;
V_606 -> V_631 = V_167 - 1 ;
}
} else {
if ( V_167 == 1 &&
( V_606 -> V_7 [ 0 ] & V_126 ) )
goto V_630;
}
if ( ! F_461 ( V_80 , V_293 , 0 ) ) {
F_460 ( V_80 ) ;
F_441 ( V_80 ) ;
V_80 = NULL ;
* V_627 = 1 ;
}
if ( ! V_80 ) {
if ( V_75 && V_167 == 1 )
F_442 ( V_110 , V_35 , V_606 , V_64 ) ;
V_80 = F_454 ( V_35 , V_27 , V_293 ) ;
if ( F_200 ( V_80 ) ) {
return F_201 ( V_80 ) ;
} else if ( ! F_451 ( V_80 ) ) {
F_441 ( V_80 ) ;
return - V_175 ;
}
F_429 ( V_80 ) ;
F_431 ( V_80 ) ;
}
V_167 -- ;
F_30 ( V_167 != F_225 ( V_80 ) ) ;
V_64 -> V_82 [ V_167 ] = V_80 ;
V_64 -> V_83 [ V_167 ] = 0 ;
V_64 -> V_618 [ V_167 ] = V_632 ;
V_606 -> V_167 = V_167 ;
if ( V_606 -> V_167 == 1 )
V_606 -> V_609 = 0 ;
return 0 ;
V_630:
V_606 -> V_112 [ V_167 - 1 ] = 0 ;
V_606 -> V_7 [ V_167 - 1 ] = 0 ;
if ( V_606 -> V_611 == V_613 ) {
if ( V_606 -> V_7 [ V_167 ] & V_126 ) {
V_17 = V_64 -> V_82 [ V_167 ] -> V_32 ;
} else {
F_30 ( V_35 -> V_265 . V_22 !=
F_224 ( V_64 -> V_82 [ V_167 ] ) ) ;
V_17 = 0 ;
}
if ( V_629 ) {
V_29 = F_450 ( V_110 , V_35 , V_80 ,
V_293 , V_167 - 1 ) ;
if ( V_29 ) {
F_462 ( V_633 L_34
L_35
L_36 ,
V_35 -> V_37 -> V_408 -> V_634 , V_29 ) ;
}
}
V_29 = V_276 ( V_110 , V_35 , V_27 , V_590 , V_17 ,
V_35 -> V_265 . V_22 , V_167 - 1 , 0 , 0 ) ;
F_30 ( V_29 ) ;
}
F_460 ( V_80 ) ;
F_441 ( V_80 ) ;
* V_627 = 1 ;
return 1 ;
}
static T_1 int F_463 ( struct V_109 * V_110 ,
struct V_34 * V_35 ,
struct V_63 * V_64 ,
struct V_605 * V_606 )
{
int V_29 ;
int V_167 = V_606 -> V_167 ;
struct V_65 * V_504 = V_64 -> V_82 [ V_167 ] ;
T_2 V_17 = 0 ;
if ( V_606 -> V_611 == V_612 ) {
F_30 ( V_606 -> V_631 < V_167 ) ;
if ( V_167 < V_606 -> V_631 )
goto V_72;
V_29 = F_41 ( V_64 , V_167 + 1 , & V_606 -> V_615 ) ;
if ( V_29 > 0 )
V_606 -> V_614 = 0 ;
V_606 -> V_611 = V_613 ;
V_606 -> V_631 = - 1 ;
V_64 -> V_83 [ V_167 ] = 0 ;
if ( ! V_64 -> V_618 [ V_167 ] ) {
F_30 ( V_167 == 0 ) ;
F_429 ( V_504 ) ;
F_431 ( V_504 ) ;
V_64 -> V_618 [ V_167 ] = V_632 ;
V_29 = F_75 ( V_110 , V_35 ,
V_504 -> V_32 , V_167 , 1 ,
& V_606 -> V_112 [ V_167 ] ,
& V_606 -> V_7 [ V_167 ] ) ;
if ( V_29 < 0 ) {
F_449 ( V_504 , V_64 -> V_618 [ V_167 ] ) ;
V_64 -> V_618 [ V_167 ] = 0 ;
return V_29 ;
}
F_30 ( V_606 -> V_112 [ V_167 ] == 0 ) ;
if ( V_606 -> V_112 [ V_167 ] == 1 ) {
F_449 ( V_504 , V_64 -> V_618 [ V_167 ] ) ;
V_64 -> V_618 [ V_167 ] = 0 ;
return 1 ;
}
}
}
F_30 ( V_606 -> V_112 [ V_167 ] > 1 && ! V_64 -> V_618 [ V_167 ] ) ;
if ( V_606 -> V_112 [ V_167 ] == 1 ) {
if ( V_167 == 0 ) {
if ( V_606 -> V_7 [ V_167 ] & V_126 )
V_29 = F_233 ( V_110 , V_35 , V_504 , 1 ) ;
else
V_29 = F_233 ( V_110 , V_35 , V_504 , 0 ) ;
F_30 ( V_29 ) ;
V_29 = F_447 ( V_110 , V_35 , V_504 ) ;
if ( V_29 ) {
F_462 ( V_633 L_34
L_37
L_36 ,
V_35 -> V_37 -> V_408 -> V_634 , V_29 ) ;
}
}
if ( ! V_64 -> V_618 [ V_167 ] &&
F_393 ( V_504 ) == V_110 -> V_290 ) {
F_429 ( V_504 ) ;
F_431 ( V_504 ) ;
V_64 -> V_618 [ V_167 ] = V_632 ;
}
F_430 ( V_110 , V_35 -> V_37 , V_504 ) ;
}
if ( V_504 == V_35 -> V_128 ) {
if ( V_606 -> V_7 [ V_167 ] & V_126 )
V_17 = V_504 -> V_32 ;
else
F_30 ( V_35 -> V_265 . V_22 !=
F_224 ( V_504 ) ) ;
} else {
if ( V_606 -> V_7 [ V_167 + 1 ] & V_126 )
V_17 = V_64 -> V_82 [ V_167 + 1 ] -> V_32 ;
else
F_30 ( V_35 -> V_265 . V_22 !=
F_224 ( V_64 -> V_82 [ V_167 + 1 ] ) ) ;
}
F_392 ( V_110 , V_35 , V_504 , V_17 , V_606 -> V_112 [ V_167 ] == 1 ) ;
V_72:
V_606 -> V_112 [ V_167 ] = 0 ;
V_606 -> V_7 [ V_167 ] = 0 ;
return 0 ;
}
static T_1 int F_464 ( struct V_109 * V_110 ,
struct V_34 * V_35 ,
struct V_63 * V_64 ,
struct V_605 * V_606 )
{
int V_167 = V_606 -> V_167 ;
int V_627 = 1 ;
int V_29 ;
while ( V_167 >= 0 ) {
V_29 = F_457 ( V_110 , V_35 , V_64 , V_606 , V_627 ) ;
if ( V_29 > 0 )
break;
if ( V_167 == 0 )
break;
if ( V_64 -> V_83 [ V_167 ] >=
F_38 ( V_64 -> V_82 [ V_167 ] ) )
break;
V_29 = F_458 ( V_110 , V_35 , V_64 , V_606 , & V_627 ) ;
if ( V_29 > 0 ) {
V_64 -> V_83 [ V_167 ] ++ ;
continue;
} else if ( V_29 < 0 )
return V_29 ;
V_167 = V_606 -> V_167 ;
}
return 0 ;
}
static T_1 int F_465 ( struct V_109 * V_110 ,
struct V_34 * V_35 ,
struct V_63 * V_64 ,
struct V_605 * V_606 , int V_635 )
{
int V_167 = V_606 -> V_167 ;
int V_29 ;
V_64 -> V_83 [ V_167 ] = F_38 ( V_64 -> V_82 [ V_167 ] ) ;
while ( V_167 < V_635 && V_64 -> V_82 [ V_167 ] ) {
V_606 -> V_167 = V_167 ;
if ( V_64 -> V_83 [ V_167 ] + 1 <
F_38 ( V_64 -> V_82 [ V_167 ] ) ) {
V_64 -> V_83 [ V_167 ] ++ ;
return 0 ;
} else {
V_29 = F_463 ( V_110 , V_35 , V_64 , V_606 ) ;
if ( V_29 > 0 )
return 0 ;
if ( V_64 -> V_618 [ V_167 ] ) {
F_449 ( V_64 -> V_82 [ V_167 ] ,
V_64 -> V_618 [ V_167 ] ) ;
V_64 -> V_618 [ V_167 ] = 0 ;
}
F_441 ( V_64 -> V_82 [ V_167 ] ) ;
V_64 -> V_82 [ V_167 ] = NULL ;
V_167 ++ ;
}
}
return 1 ;
}
int F_466 ( struct V_34 * V_35 ,
struct V_247 * V_414 , int V_614 ,
int V_636 )
{
struct V_63 * V_64 ;
struct V_109 * V_110 ;
struct V_34 * V_86 = V_35 -> V_37 -> V_86 ;
struct V_637 * V_266 = & V_35 -> V_266 ;
struct V_605 * V_606 ;
struct V_67 V_21 ;
int V_81 = 0 ;
int V_29 ;
int V_167 ;
bool V_638 = false ;
F_179 ( V_35 -> V_37 , L_38 , V_35 -> V_22 ) ;
V_64 = F_33 () ;
if ( ! V_64 ) {
V_81 = - V_71 ;
goto V_72;
}
V_606 = F_53 ( sizeof( * V_606 ) , V_40 ) ;
if ( ! V_606 ) {
F_50 ( V_64 ) ;
V_81 = - V_71 ;
goto V_72;
}
V_110 = F_467 ( V_86 , 0 ) ;
if ( F_200 ( V_110 ) ) {
V_81 = F_201 ( V_110 ) ;
goto V_123;
}
if ( V_414 )
V_110 -> V_414 = V_414 ;
if ( F_468 ( & V_266 -> V_639 ) == 0 ) {
V_167 = F_225 ( V_35 -> V_128 ) ;
V_64 -> V_82 [ V_167 ] = F_469 ( V_35 ) ;
F_431 ( V_64 -> V_82 [ V_167 ] ) ;
V_64 -> V_83 [ V_167 ] = 0 ;
V_64 -> V_618 [ V_167 ] = V_632 ;
memset ( & V_606 -> V_615 , 0 ,
sizeof( V_606 -> V_615 ) ) ;
} else {
F_470 ( & V_21 , & V_266 -> V_639 ) ;
memcpy ( & V_606 -> V_615 , & V_21 ,
sizeof( V_606 -> V_615 ) ) ;
V_167 = V_266 -> V_640 ;
F_30 ( V_167 == 0 ) ;
V_64 -> V_641 = V_167 ;
V_29 = F_37 ( NULL , V_35 , & V_21 , V_64 , 0 , 0 ) ;
V_64 -> V_641 = 0 ;
if ( V_29 < 0 ) {
V_81 = V_29 ;
goto V_642;
}
F_8 ( V_29 > 0 ) ;
F_128 ( V_64 , 0 ) ;
V_167 = F_225 ( V_35 -> V_128 ) ;
while ( 1 ) {
F_429 ( V_64 -> V_82 [ V_167 ] ) ;
F_431 ( V_64 -> V_82 [ V_167 ] ) ;
V_64 -> V_618 [ V_167 ] = V_632 ;
V_29 = F_75 ( V_110 , V_35 ,
V_64 -> V_82 [ V_167 ] -> V_32 ,
V_167 , 1 , & V_606 -> V_112 [ V_167 ] ,
& V_606 -> V_7 [ V_167 ] ) ;
if ( V_29 < 0 ) {
V_81 = V_29 ;
goto V_642;
}
F_30 ( V_606 -> V_112 [ V_167 ] == 0 ) ;
if ( V_167 == V_266 -> V_640 )
break;
F_460 ( V_64 -> V_82 [ V_167 ] ) ;
V_64 -> V_618 [ V_167 ] = 0 ;
F_8 ( V_606 -> V_112 [ V_167 ] != 1 ) ;
V_167 -- ;
}
}
V_606 -> V_167 = V_167 ;
V_606 -> V_631 = - 1 ;
V_606 -> V_611 = V_613 ;
V_606 -> V_614 = V_614 ;
V_606 -> V_174 = 0 ;
V_606 -> V_636 = V_636 ;
V_606 -> V_610 = F_443 ( V_35 ) ;
while ( 1 ) {
V_29 = F_464 ( V_110 , V_35 , V_64 , V_606 ) ;
if ( V_29 < 0 ) {
V_81 = V_29 ;
break;
}
V_29 = F_465 ( V_110 , V_35 , V_64 , V_606 , V_168 ) ;
if ( V_29 < 0 ) {
V_81 = V_29 ;
break;
}
if ( V_29 > 0 ) {
F_30 ( V_606 -> V_611 != V_613 ) ;
break;
}
if ( V_606 -> V_611 == V_613 ) {
V_167 = V_606 -> V_167 ;
F_471 ( V_64 -> V_82 [ V_167 ] ,
& V_266 -> V_639 ,
V_64 -> V_83 [ V_167 ] ) ;
V_266 -> V_640 = V_167 ;
}
F_30 ( V_606 -> V_167 == 0 ) ;
if ( F_472 ( V_110 , V_86 ) ||
( ! V_636 && F_473 ( V_35 ) ) ) {
V_29 = F_474 ( V_110 , V_86 ,
& V_35 -> V_265 ,
V_266 ) ;
if ( V_29 ) {
F_150 ( V_110 , V_86 , V_29 ) ;
V_81 = V_29 ;
goto V_642;
}
F_475 ( V_110 , V_86 ) ;
if ( ! V_636 && F_473 ( V_35 ) ) {
F_476 ( L_39 ) ;
V_81 = - V_178 ;
goto V_123;
}
V_110 = F_467 ( V_86 , 0 ) ;
if ( F_200 ( V_110 ) ) {
V_81 = F_201 ( V_110 ) ;
goto V_123;
}
if ( V_414 )
V_110 -> V_414 = V_414 ;
}
}
F_44 ( V_64 ) ;
if ( V_81 )
goto V_642;
V_29 = F_477 ( V_110 , V_86 , & V_35 -> V_265 ) ;
if ( V_29 ) {
F_150 ( V_110 , V_86 , V_29 ) ;
goto V_642;
}
if ( V_35 -> V_265 . V_22 != V_602 ) {
V_29 = F_478 ( V_86 , & V_35 -> V_265 , V_64 ,
NULL , NULL ) ;
if ( V_29 < 0 ) {
F_150 ( V_110 , V_86 , V_29 ) ;
V_81 = V_29 ;
goto V_642;
} else if ( V_29 > 0 ) {
F_479 ( V_110 , V_86 ,
V_35 -> V_265 . V_22 ) ;
}
}
if ( F_226 ( V_643 , & V_35 -> V_275 ) ) {
F_480 ( V_86 -> V_37 , V_35 ) ;
} else {
F_441 ( V_35 -> V_128 ) ;
F_441 ( V_35 -> V_644 ) ;
F_481 ( V_35 ) ;
}
V_638 = true ;
V_642:
F_475 ( V_110 , V_86 ) ;
V_123:
F_9 ( V_606 ) ;
F_50 ( V_64 ) ;
V_72:
if ( ! V_636 && V_638 == false )
F_482 ( V_35 ) ;
if ( V_81 && V_81 != - V_178 )
F_483 ( V_35 -> V_37 , V_81 ) ;
return V_81 ;
}
int F_484 ( struct V_109 * V_110 ,
struct V_34 * V_35 ,
struct V_65 * V_128 ,
struct V_65 * V_17 )
{
struct V_63 * V_64 ;
struct V_605 * V_606 ;
int V_167 ;
int V_645 ;
int V_29 = 0 ;
int V_646 ;
F_30 ( V_35 -> V_265 . V_22 != V_602 ) ;
V_64 = F_33 () ;
if ( ! V_64 )
return - V_71 ;
V_606 = F_53 ( sizeof( * V_606 ) , V_40 ) ;
if ( ! V_606 ) {
F_50 ( V_64 ) ;
return - V_71 ;
}
F_485 ( V_17 ) ;
V_645 = F_225 ( V_17 ) ;
F_453 ( V_17 ) ;
V_64 -> V_82 [ V_645 ] = V_17 ;
V_64 -> V_83 [ V_645 ] = F_38 ( V_17 ) ;
F_485 ( V_128 ) ;
V_167 = F_225 ( V_128 ) ;
V_64 -> V_82 [ V_167 ] = V_128 ;
V_64 -> V_83 [ V_167 ] = 0 ;
V_64 -> V_618 [ V_167 ] = V_632 ;
V_606 -> V_112 [ V_645 ] = 1 ;
V_606 -> V_7 [ V_645 ] = V_126 ;
V_606 -> V_167 = V_167 ;
V_606 -> V_631 = - 1 ;
V_606 -> V_611 = V_613 ;
V_606 -> V_614 = 0 ;
V_606 -> V_174 = 1 ;
V_606 -> V_636 = 1 ;
V_606 -> V_610 = F_443 ( V_35 ) ;
while ( 1 ) {
V_646 = F_464 ( V_110 , V_35 , V_64 , V_606 ) ;
if ( V_646 < 0 ) {
V_29 = V_646 ;
break;
}
V_646 = F_465 ( V_110 , V_35 , V_64 , V_606 , V_645 ) ;
if ( V_646 < 0 )
V_29 = V_646 ;
if ( V_646 != 0 )
break;
}
F_9 ( V_606 ) ;
F_50 ( V_64 ) ;
return V_29 ;
}
static T_2 F_486 ( struct V_34 * V_35 , T_2 V_7 )
{
T_2 V_356 ;
T_2 V_647 ;
V_647 = F_274 ( V_35 -> V_37 , V_7 ) ;
if ( V_647 )
return F_276 ( V_647 ) ;
V_356 = V_35 -> V_37 -> V_357 -> V_358 ;
V_647 = V_360 |
V_361 | V_362 |
V_320 | V_321 ;
if ( V_356 == 1 ) {
V_647 |= V_319 ;
V_647 = V_7 & ~ V_647 ;
if ( V_7 & V_360 )
return V_647 ;
if ( V_7 & ( V_320 |
V_321 ) )
return V_647 | V_319 ;
} else {
if ( V_7 & V_647 )
return V_7 ;
V_647 |= V_319 ;
V_647 = V_7 & ~ V_647 ;
if ( V_7 & V_319 )
return V_647 | V_320 ;
}
return V_7 ;
}
static int F_487 ( struct V_1 * V_2 , int V_382 )
{
struct V_102 * V_381 = V_2 -> V_105 ;
T_2 V_36 ;
T_2 V_648 ;
int V_29 = - V_375 ;
if ( ( V_381 -> V_7 &
( V_315 | V_313 ) ) &&
! V_382 )
V_648 = 1 * 1024 * 1024 ;
else
V_648 = 0 ;
F_11 ( & V_381 -> V_52 ) ;
F_11 ( & V_2 -> V_52 ) ;
if ( V_2 -> V_288 ) {
V_29 = 0 ;
goto V_72;
}
V_36 = V_2 -> V_21 . V_33 - V_2 -> V_10 - V_2 -> V_9 -
V_2 -> V_46 - F_371 ( & V_2 -> V_135 ) ;
if ( V_381 -> V_317 + V_381 -> V_330 + V_381 -> V_329 +
V_381 -> V_332 + V_381 -> V_331 + V_36 +
V_648 <= V_381 -> V_316 ) {
V_381 -> V_331 += V_36 ;
V_2 -> V_288 = 1 ;
F_64 ( & V_2 -> V_649 , & V_381 -> V_337 ) ;
V_29 = 0 ;
}
V_72:
F_13 ( & V_2 -> V_52 ) ;
F_13 ( & V_381 -> V_52 ) ;
return V_29 ;
}
int F_488 ( struct V_34 * V_35 ,
struct V_1 * V_2 )
{
struct V_109 * V_110 ;
T_2 V_650 ;
int V_29 ;
F_30 ( V_2 -> V_288 ) ;
V_77:
V_110 = F_199 ( V_35 ) ;
if ( F_200 ( V_110 ) )
return F_201 ( V_110 ) ;
F_35 ( & V_35 -> V_37 -> V_651 ) ;
if ( V_110 -> V_127 -> V_652 ) {
T_2 V_290 = V_110 -> V_290 ;
F_46 ( & V_35 -> V_37 -> V_651 ) ;
F_203 ( V_110 , V_35 ) ;
V_29 = F_489 ( V_35 , V_290 ) ;
if ( V_29 )
return V_29 ;
goto V_77;
}
V_650 = F_486 ( V_35 , V_2 -> V_7 ) ;
if ( V_650 != V_2 -> V_7 ) {
V_29 = F_283 ( V_110 , V_35 , V_650 ,
V_374 ) ;
if ( V_29 == - V_375 )
V_29 = 0 ;
if ( V_29 < 0 )
goto V_72;
}
V_29 = F_487 ( V_2 , 0 ) ;
if ( ! V_29 )
goto V_72;
V_650 = F_277 ( V_35 , V_2 -> V_105 -> V_7 ) ;
V_29 = F_283 ( V_110 , V_35 , V_650 ,
V_374 ) ;
if ( V_29 < 0 )
goto V_72;
V_29 = F_487 ( V_2 , 0 ) ;
V_72:
if ( V_2 -> V_7 & V_315 ) {
V_650 = F_486 ( V_35 , V_2 -> V_7 ) ;
F_490 ( V_35 -> V_37 -> V_364 ) ;
F_296 ( V_110 , V_35 , V_650 ) ;
F_491 ( V_35 -> V_37 -> V_364 ) ;
}
F_46 ( & V_35 -> V_37 -> V_651 ) ;
F_203 ( V_110 , V_35 ) ;
return V_29 ;
}
int F_492 ( struct V_109 * V_110 ,
struct V_34 * V_35 , T_2 type )
{
T_2 V_650 = F_277 ( V_35 , type ) ;
return F_283 ( V_110 , V_35 , V_650 ,
V_374 ) ;
}
T_2 F_493 ( struct V_102 * V_381 )
{
struct V_1 * V_14 ;
T_2 V_653 = 0 ;
int V_318 ;
if ( F_169 ( & V_381 -> V_337 ) )
return 0 ;
F_11 ( & V_381 -> V_52 ) ;
F_170 (block_group, &sinfo->ro_bgs, ro_list) {
F_11 ( & V_14 -> V_52 ) ;
if ( ! V_14 -> V_288 ) {
F_13 ( & V_14 -> V_52 ) ;
continue;
}
if ( V_14 -> V_7 & ( V_320 |
V_321 |
V_319 ) )
V_318 = 2 ;
else
V_318 = 1 ;
V_653 += ( V_14 -> V_21 . V_33 -
F_371 ( & V_14 -> V_135 ) ) *
V_318 ;
F_13 ( & V_14 -> V_52 ) ;
}
F_13 ( & V_381 -> V_52 ) ;
return V_653 ;
}
void F_494 ( struct V_34 * V_35 ,
struct V_1 * V_2 )
{
struct V_102 * V_381 = V_2 -> V_105 ;
T_2 V_36 ;
F_30 ( ! V_2 -> V_288 ) ;
F_11 ( & V_381 -> V_52 ) ;
F_11 ( & V_2 -> V_52 ) ;
V_36 = V_2 -> V_21 . V_33 - V_2 -> V_10 - V_2 -> V_9 -
V_2 -> V_46 - F_371 ( & V_2 -> V_135 ) ;
V_381 -> V_331 -= V_36 ;
V_2 -> V_288 = 0 ;
F_258 ( & V_2 -> V_649 ) ;
F_13 ( & V_2 -> V_52 ) ;
F_13 ( & V_381 -> V_52 ) ;
}
int F_495 ( struct V_34 * V_35 , T_2 V_27 )
{
struct V_1 * V_14 ;
struct V_102 * V_105 ;
struct V_654 * V_357 = V_35 -> V_37 -> V_357 ;
struct V_655 * V_656 ;
struct V_109 * V_110 ;
T_2 V_657 ;
T_2 V_658 = 1 ;
T_2 V_659 = 0 ;
T_2 V_351 ;
int V_550 ;
int V_108 = 0 ;
int V_29 = 0 ;
V_14 = F_68 ( V_35 -> V_37 , V_27 ) ;
if ( ! V_14 )
return - 1 ;
V_657 = F_371 ( & V_14 -> V_135 ) ;
if ( ! V_657 )
goto V_72;
V_105 = V_14 -> V_105 ;
F_11 ( & V_105 -> V_52 ) ;
V_108 = V_105 -> V_108 ;
if ( ( V_105 -> V_316 != V_14 -> V_21 . V_33 ) &&
( V_105 -> V_317 + V_105 -> V_330 +
V_105 -> V_329 + V_105 -> V_331 +
V_657 < V_105 -> V_316 ) ) {
F_13 ( & V_105 -> V_52 ) ;
goto V_72;
}
F_13 ( & V_105 -> V_52 ) ;
V_29 = - 1 ;
V_351 = F_274 ( V_35 -> V_37 , V_14 -> V_7 ) ;
if ( V_351 ) {
V_550 = F_398 ( F_276 ( V_351 ) ) ;
} else {
if ( V_108 )
goto V_72;
V_550 = F_399 ( V_14 ) ;
}
if ( V_550 == V_528 ) {
V_658 = 4 ;
V_657 >>= 1 ;
} else if ( V_550 == V_529 ) {
V_658 = 2 ;
} else if ( V_550 == V_530 ) {
V_657 <<= 1 ;
} else if ( V_550 == V_531 ) {
V_658 = V_357 -> V_358 ;
V_657 = F_192 ( V_657 , V_658 ) ;
}
V_110 = F_199 ( V_35 ) ;
if ( F_200 ( V_110 ) ) {
V_29 = F_201 ( V_110 ) ;
goto V_72;
}
F_35 ( & V_35 -> V_37 -> V_389 ) ;
F_170 (device, &fs_devices->alloc_list, dev_alloc_list) {
T_2 V_660 ;
if ( V_656 -> V_316 > V_656 -> V_317 + V_657 &&
! V_656 -> V_661 ) {
V_29 = F_496 ( V_110 , V_656 , V_657 ,
& V_660 , NULL ) ;
if ( ! V_29 )
V_659 ++ ;
if ( V_659 >= V_658 )
break;
V_29 = - 1 ;
}
}
F_46 ( & V_35 -> V_37 -> V_389 ) ;
F_203 ( V_110 , V_35 ) ;
V_72:
F_6 ( V_14 ) ;
return V_29 ;
}
static int F_497 ( struct V_34 * V_35 ,
struct V_63 * V_64 , struct V_67 * V_21 )
{
int V_29 = 0 ;
struct V_67 V_140 ;
struct V_65 * V_66 ;
int V_607 ;
V_29 = F_37 ( NULL , V_35 , V_21 , V_64 , 0 , 0 ) ;
if ( V_29 < 0 )
goto V_72;
while ( 1 ) {
V_607 = V_64 -> V_83 [ 0 ] ;
V_66 = V_64 -> V_82 [ 0 ] ;
if ( V_607 >= F_38 ( V_66 ) ) {
V_29 = F_48 ( V_35 , V_64 ) ;
if ( V_29 == 0 )
continue;
if ( V_29 < 0 )
goto V_72;
break;
}
F_40 ( V_66 , & V_140 , V_607 ) ;
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
void F_498 ( struct V_12 * V_13 )
{
struct V_1 * V_14 ;
T_2 V_69 = 0 ;
while ( 1 ) {
struct V_280 * V_280 ;
V_14 = F_67 ( V_13 , V_69 ) ;
while ( V_14 ) {
F_11 ( & V_14 -> V_52 ) ;
if ( V_14 -> V_164 )
break;
F_13 ( & V_14 -> V_52 ) ;
V_14 = F_237 ( V_13 -> V_86 ,
V_14 ) ;
}
if ( ! V_14 ) {
if ( V_69 == 0 )
break;
V_69 = 0 ;
continue;
}
V_280 = V_14 -> V_280 ;
V_14 -> V_164 = 0 ;
V_14 -> V_280 = NULL ;
F_13 ( & V_14 -> V_52 ) ;
F_251 ( V_280 ) ;
V_69 = V_14 -> V_21 . V_22 + V_14 -> V_21 . V_33 ;
F_6 ( V_14 ) ;
}
}
int F_499 ( struct V_12 * V_13 )
{
struct V_1 * V_14 ;
struct V_102 * V_105 ;
struct V_50 * V_53 ;
struct V_15 * V_30 ;
F_63 ( & V_13 -> V_79 ) ;
while ( ! F_169 ( & V_13 -> V_100 ) ) {
V_53 = F_171 ( V_13 -> V_100 . V_80 ,
struct V_50 , V_90 ) ;
F_181 ( & V_53 -> V_90 ) ;
F_26 ( V_53 ) ;
}
F_65 ( & V_13 -> V_79 ) ;
F_11 ( & V_13 -> V_498 ) ;
while ( ! F_169 ( & V_13 -> V_500 ) ) {
V_14 = F_257 ( & V_13 -> V_500 ,
struct V_1 ,
V_499 ) ;
F_258 ( & V_14 -> V_499 ) ;
F_6 ( V_14 ) ;
}
F_13 ( & V_13 -> V_498 ) ;
F_11 ( & V_13 -> V_18 ) ;
while ( ( V_30 = F_187 ( & V_13 -> V_19 ) ) != NULL ) {
V_14 = F_12 ( V_30 , struct V_1 ,
V_20 ) ;
F_180 ( & V_14 -> V_20 ,
& V_13 -> V_19 ) ;
F_500 ( & V_14 -> V_20 ) ;
F_13 ( & V_13 -> V_18 ) ;
F_63 ( & V_14 -> V_105 -> V_328 ) ;
F_181 ( & V_14 -> V_90 ) ;
F_65 ( & V_14 -> V_105 -> V_328 ) ;
if ( V_14 -> V_3 == V_98 )
F_397 ( V_14 ) ;
if ( V_14 -> V_3 == V_94 ||
V_14 -> V_3 == V_5 )
F_19 ( V_13 -> V_62 , V_14 ) ;
F_501 ( V_14 ) ;
F_6 ( V_14 ) ;
F_11 ( & V_13 -> V_18 ) ;
}
F_13 ( & V_13 -> V_18 ) ;
F_502 () ;
F_349 ( V_13 ) ;
while ( ! F_169 ( & V_13 -> V_105 ) ) {
int V_43 ;
V_105 = F_171 ( V_13 -> V_105 . V_80 ,
struct V_102 ,
V_90 ) ;
if ( F_247 ( V_13 -> V_86 , V_390 ) ) {
if ( F_8 ( V_105 -> V_329 > 0 ||
V_105 -> V_330 > 0 ||
V_105 -> V_332 > 0 ) ) {
F_300 ( V_105 , 0 , 0 ) ;
}
}
F_181 ( & V_105 -> V_90 ) ;
for ( V_43 = 0 ; V_43 < V_326 ; V_43 ++ ) {
struct V_662 * V_338 ;
V_338 = V_105 -> V_663 [ V_43 ] ;
V_105 -> V_663 [ V_43 ] = NULL ;
if ( V_338 ) {
F_503 ( V_338 ) ;
F_504 ( V_338 ) ;
}
}
F_503 ( & V_105 -> V_338 ) ;
F_504 ( & V_105 -> V_338 ) ;
}
return 0 ;
}
static void F_505 ( struct V_102 * V_105 ,
struct V_1 * V_2 )
{
int V_550 = F_399 ( V_2 ) ;
bool V_238 = false ;
F_63 ( & V_105 -> V_328 ) ;
if ( F_169 ( & V_105 -> V_327 [ V_550 ] ) )
V_238 = true ;
F_64 ( & V_2 -> V_90 , & V_105 -> V_327 [ V_550 ] ) ;
F_65 ( & V_105 -> V_328 ) ;
if ( V_238 ) {
struct V_664 * V_665 ;
int V_29 ;
V_665 = F_53 ( sizeof( * V_665 ) , V_40 ) ;
if ( ! V_665 )
goto V_666;
V_665 -> V_667 = V_550 ;
F_506 ( & V_665 -> V_338 , & V_668 ) ;
V_29 = F_507 ( & V_665 -> V_338 , & V_105 -> V_338 ,
L_8 , F_400 ( V_550 ) ) ;
if ( V_29 ) {
F_504 ( & V_665 -> V_338 ) ;
goto V_666;
}
V_105 -> V_663 [ V_550 ] = & V_665 -> V_338 ;
}
return;
V_666:
F_508 ( L_40 ) ;
}
static struct V_1 *
F_509 ( struct V_34 * V_35 , T_2 V_32 , T_2 V_56 )
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
V_2 -> V_246 = V_35 -> V_246 ;
V_2 -> V_37 = V_35 -> V_37 ;
V_2 -> V_669 = F_510 ( V_35 ,
& V_35 -> V_37 -> V_48 ,
V_32 ) ;
F_57 ( & V_2 -> V_8 , 1 ) ;
F_267 ( & V_2 -> V_52 ) ;
F_266 ( & V_2 -> V_537 ) ;
F_54 ( & V_2 -> V_90 ) ;
F_54 ( & V_2 -> V_670 ) ;
F_54 ( & V_2 -> V_499 ) ;
F_54 ( & V_2 -> V_649 ) ;
F_54 ( & V_2 -> V_309 ) ;
F_54 ( & V_2 -> V_310 ) ;
F_511 ( V_2 ) ;
F_57 ( & V_2 -> V_671 , 0 ) ;
return V_2 ;
}
int F_512 ( struct V_34 * V_35 )
{
struct V_63 * V_64 ;
int V_29 ;
struct V_1 * V_2 ;
struct V_12 * V_13 = V_35 -> V_37 ;
struct V_102 * V_105 ;
struct V_67 V_21 ;
struct V_67 V_140 ;
struct V_65 * V_66 ;
int V_672 = 0 ;
T_2 V_673 ;
V_35 = V_13 -> V_62 ;
V_21 . V_22 = 0 ;
V_21 . V_33 = 0 ;
V_21 . type = V_179 ;
V_64 = F_33 () ;
if ( ! V_64 )
return - V_71 ;
V_64 -> V_75 = 1 ;
V_673 = F_513 ( V_35 -> V_37 -> V_245 ) ;
if ( F_247 ( V_35 , V_294 ) &&
F_514 ( V_35 -> V_37 -> V_245 ) != V_673 )
V_672 = 1 ;
if ( F_247 ( V_35 , V_674 ) )
V_672 = 1 ;
while ( 1 ) {
V_29 = F_497 ( V_35 , V_64 , & V_21 ) ;
if ( V_29 > 0 )
break;
if ( V_29 != 0 )
goto error;
V_66 = V_64 -> V_82 [ 0 ] ;
F_40 ( V_66 , & V_140 , V_64 -> V_83 [ 0 ] ) ;
V_2 = F_509 ( V_35 , V_140 . V_22 ,
V_140 . V_33 ) ;
if ( ! V_2 ) {
V_29 = - V_71 ;
goto error;
}
if ( V_672 ) {
if ( F_247 ( V_35 , V_294 ) )
V_2 -> V_286 = V_300 ;
}
F_515 ( V_66 , & V_2 -> V_135 ,
F_235 ( V_66 , V_64 -> V_83 [ 0 ] ) ,
sizeof( V_2 -> V_135 ) ) ;
V_2 -> V_7 = F_516 ( & V_2 -> V_135 ) ;
V_21 . V_22 = V_140 . V_22 + V_140 . V_33 ;
F_44 ( V_64 ) ;
V_29 = F_21 ( V_35 , V_2 ) ;
if ( V_29 ) {
F_19 ( V_35 , V_2 ) ;
F_6 ( V_2 ) ;
goto error;
}
if ( V_140 . V_33 == F_371 ( & V_2 -> V_135 ) ) {
V_2 -> V_97 = ( T_2 ) - 1 ;
V_2 -> V_3 = V_4 ;
F_19 ( V_35 , V_2 ) ;
} else if ( F_371 ( & V_2 -> V_135 ) == 0 ) {
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
F_501 ( V_2 ) ;
F_6 ( V_2 ) ;
goto error;
}
V_29 = F_264 ( V_13 , V_2 -> V_7 , V_140 . V_33 ,
F_371 ( & V_2 -> V_135 ) ,
& V_105 ) ;
if ( V_29 ) {
F_501 ( V_2 ) ;
F_11 ( & V_13 -> V_18 ) ;
F_180 ( & V_2 -> V_20 ,
& V_13 -> V_19 ) ;
F_500 ( & V_2 -> V_20 ) ;
F_13 ( & V_13 -> V_18 ) ;
F_6 ( V_2 ) ;
goto error;
}
V_2 -> V_105 = V_105 ;
F_11 ( & V_2 -> V_105 -> V_52 ) ;
V_2 -> V_105 -> V_331 += V_2 -> V_46 ;
F_13 ( & V_2 -> V_105 -> V_52 ) ;
F_505 ( V_105 , V_2 ) ;
F_270 ( V_35 -> V_37 , V_2 -> V_7 ) ;
if ( F_517 ( V_35 , V_2 -> V_21 . V_22 ) ) {
F_487 ( V_2 , 1 ) ;
} else if ( F_371 ( & V_2 -> V_135 ) == 0 ) {
F_11 ( & V_13 -> V_498 ) ;
if ( F_169 ( & V_2 -> V_499 ) ) {
F_4 ( V_2 ) ;
F_64 ( & V_2 -> V_499 ,
& V_13 -> V_500 ) ;
}
F_13 ( & V_13 -> V_498 ) ;
}
}
F_71 (space_info, &root->fs_info->space_info, list) {
if ( ! ( F_277 ( V_35 , V_105 -> V_7 ) &
( V_321 |
V_320 |
V_361 |
V_362 |
V_319 ) ) )
continue;
F_170 (cache,
&space_info->block_groups[BTRFS_RAID_RAID0],
list)
F_487 ( V_2 , 1 ) ;
F_170 (cache,
&space_info->block_groups[BTRFS_RAID_SINGLE],
list)
F_487 ( V_2 , 1 ) ;
}
F_348 ( V_13 ) ;
V_29 = 0 ;
error:
F_50 ( V_64 ) ;
return V_29 ;
}
void F_210 ( struct V_109 * V_110 ,
struct V_34 * V_35 )
{
struct V_1 * V_14 , * V_296 ;
struct V_34 * V_62 = V_35 -> V_37 -> V_62 ;
struct V_675 V_135 ;
struct V_67 V_21 ;
int V_29 = 0 ;
F_253 (block_group, tmp, &trans->new_bgs, bg_list) {
if ( V_29 )
goto V_80;
F_11 ( & V_14 -> V_52 ) ;
memcpy ( & V_135 , & V_14 -> V_135 , sizeof( V_135 ) ) ;
memcpy ( & V_21 , & V_14 -> V_21 , sizeof( V_21 ) ) ;
F_13 ( & V_14 -> V_52 ) ;
V_29 = F_518 ( V_110 , V_62 , & V_21 , & V_135 ,
sizeof( V_135 ) ) ;
if ( V_29 )
F_150 ( V_110 , V_62 , V_29 ) ;
V_29 = F_519 ( V_110 , V_62 ,
V_21 . V_22 , V_21 . V_33 ) ;
if ( V_29 )
F_150 ( V_110 , V_62 , V_29 ) ;
V_80:
F_258 ( & V_14 -> V_499 ) ;
}
}
int F_520 ( struct V_109 * V_110 ,
struct V_34 * V_35 , T_2 V_317 ,
T_2 type , T_2 V_676 , T_2 V_677 ,
T_2 V_56 )
{
int V_29 ;
struct V_34 * V_62 ;
struct V_1 * V_2 ;
V_62 = V_35 -> V_37 -> V_62 ;
F_521 ( V_35 -> V_37 , V_110 ) ;
V_2 = F_509 ( V_35 , V_677 , V_56 ) ;
if ( ! V_2 )
return - V_71 ;
F_372 ( & V_2 -> V_135 , V_317 ) ;
F_522 ( & V_2 -> V_135 , V_676 ) ;
F_523 ( & V_2 -> V_135 , type ) ;
V_2 -> V_7 = type ;
V_2 -> V_97 = ( T_2 ) - 1 ;
V_2 -> V_3 = V_4 ;
V_29 = F_21 ( V_35 , V_2 ) ;
if ( V_29 ) {
F_19 ( V_35 , V_2 ) ;
F_6 ( V_2 ) ;
return V_29 ;
}
F_27 ( V_2 , V_35 -> V_37 , V_677 ,
V_677 + V_56 ) ;
F_19 ( V_35 , V_2 ) ;
V_29 = F_264 ( V_35 -> V_37 , V_2 -> V_7 , 0 , 0 ,
& V_2 -> V_105 ) ;
if ( V_29 ) {
F_501 ( V_2 ) ;
F_6 ( V_2 ) ;
return V_29 ;
}
V_29 = F_10 ( V_35 -> V_37 , V_2 ) ;
if ( V_29 ) {
F_501 ( V_2 ) ;
F_6 ( V_2 ) ;
return V_29 ;
}
V_29 = F_264 ( V_35 -> V_37 , V_2 -> V_7 , V_56 , V_317 ,
& V_2 -> V_105 ) ;
if ( V_29 ) {
F_501 ( V_2 ) ;
F_11 ( & V_35 -> V_37 -> V_18 ) ;
F_180 ( & V_2 -> V_20 ,
& V_35 -> V_37 -> V_19 ) ;
F_500 ( & V_2 -> V_20 ) ;
F_13 ( & V_35 -> V_37 -> V_18 ) ;
F_6 ( V_2 ) ;
return V_29 ;
}
F_347 ( V_35 -> V_37 ) ;
F_11 ( & V_2 -> V_105 -> V_52 ) ;
V_2 -> V_105 -> V_331 += V_2 -> V_46 ;
F_13 ( & V_2 -> V_105 -> V_52 ) ;
F_505 ( V_2 -> V_105 , V_2 ) ;
F_64 ( & V_2 -> V_499 , & V_110 -> V_263 ) ;
F_270 ( V_62 -> V_37 , type ) ;
return 0 ;
}
static void F_524 ( struct V_12 * V_37 , T_2 V_7 )
{
T_2 V_342 = F_271 ( V_7 ) &
V_343 ;
F_272 ( & V_37 -> V_344 ) ;
if ( V_7 & V_314 )
V_37 -> V_345 &= ~ V_342 ;
if ( V_7 & V_313 )
V_37 -> V_346 &= ~ V_342 ;
if ( V_7 & V_315 )
V_37 -> V_347 &= ~ V_342 ;
F_273 ( & V_37 -> V_344 ) ;
}
int F_525 ( struct V_109 * V_110 ,
struct V_34 * V_35 , T_2 V_678 ,
struct V_679 * V_680 )
{
struct V_63 * V_64 ;
struct V_1 * V_14 ;
struct V_538 * V_539 ;
struct V_34 * V_86 = V_35 -> V_37 -> V_86 ;
struct V_67 V_21 ;
struct V_280 * V_280 ;
struct V_662 * V_338 = NULL ;
int V_29 ;
int V_550 ;
int V_318 ;
struct V_50 * V_53 = NULL ;
bool V_681 ;
V_35 = V_35 -> V_37 -> V_62 ;
V_14 = F_68 ( V_35 -> V_37 , V_678 ) ;
F_30 ( ! V_14 ) ;
F_30 ( ! V_14 -> V_288 ) ;
F_19 ( V_35 , V_14 ) ;
memcpy ( & V_21 , & V_14 -> V_21 , sizeof( V_21 ) ) ;
V_550 = F_399 ( V_14 ) ;
if ( V_14 -> V_7 & ( V_319 |
V_320 |
V_321 ) )
V_318 = 2 ;
else
V_318 = 1 ;
V_539 = & V_35 -> V_37 -> V_559 ;
F_11 ( & V_539 -> V_542 ) ;
F_410 ( V_14 , V_539 ) ;
F_13 ( & V_539 -> V_542 ) ;
V_539 = & V_35 -> V_37 -> V_557 ;
F_11 ( & V_539 -> V_542 ) ;
F_410 ( V_14 , V_539 ) ;
F_13 ( & V_539 -> V_542 ) ;
V_64 = F_33 () ;
if ( ! V_64 ) {
V_29 = - V_71 ;
goto V_72;
}
V_280 = F_240 ( V_86 , V_14 , V_64 ) ;
F_35 ( & V_110 -> V_127 -> V_308 ) ;
F_11 ( & V_110 -> V_127 -> V_307 ) ;
if ( ! F_169 ( & V_14 -> V_310 ) ) {
F_258 ( & V_14 -> V_310 ) ;
F_8 ( ! F_200 ( V_280 ) && V_280 != V_14 -> V_311 . V_280 ) ;
F_13 ( & V_110 -> V_127 -> V_307 ) ;
F_259 ( V_35 , V_110 , V_14 ,
& V_14 -> V_311 , V_64 ,
V_14 -> V_21 . V_22 ) ;
F_6 ( V_14 ) ;
F_11 ( & V_110 -> V_127 -> V_307 ) ;
}
if ( ! F_169 ( & V_14 -> V_309 ) ) {
F_258 ( & V_14 -> V_309 ) ;
F_6 ( V_14 ) ;
}
F_13 ( & V_110 -> V_127 -> V_307 ) ;
F_46 ( & V_110 -> V_127 -> V_308 ) ;
if ( ! F_200 ( V_280 ) ) {
V_29 = F_526 ( V_110 , V_280 ) ;
if ( V_29 ) {
F_527 ( V_280 ) ;
goto V_72;
}
F_528 ( V_280 ) ;
F_11 ( & V_14 -> V_52 ) ;
if ( V_14 -> V_164 ) {
V_14 -> V_164 = 0 ;
V_14 -> V_280 = NULL ;
F_13 ( & V_14 -> V_52 ) ;
F_251 ( V_280 ) ;
} else {
F_13 ( & V_14 -> V_52 ) ;
}
F_527 ( V_280 ) ;
}
V_21 . V_22 = V_682 ;
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
F_500 ( & V_14 -> V_20 ) ;
if ( V_35 -> V_37 -> V_26 == V_14 -> V_21 . V_22 )
V_35 -> V_37 -> V_26 = ( T_2 ) - 1 ;
F_13 ( & V_35 -> V_37 -> V_18 ) ;
F_63 ( & V_14 -> V_105 -> V_328 ) ;
F_258 ( & V_14 -> V_90 ) ;
if ( F_169 ( & V_14 -> V_105 -> V_327 [ V_550 ] ) ) {
V_338 = V_14 -> V_105 -> V_663 [ V_550 ] ;
V_14 -> V_105 -> V_663 [ V_550 ] = NULL ;
F_524 ( V_35 -> V_37 , V_14 -> V_7 ) ;
}
F_65 ( & V_14 -> V_105 -> V_328 ) ;
if ( V_338 ) {
F_503 ( V_338 ) ;
F_504 ( V_338 ) ;
}
if ( V_14 -> V_99 )
V_53 = F_25 ( V_14 ) ;
if ( V_14 -> V_3 == V_98 )
F_397 ( V_14 ) ;
if ( V_14 -> V_99 ) {
F_63 ( & V_35 -> V_37 -> V_79 ) ;
if ( ! V_53 ) {
struct V_50 * V_51 ;
F_170 (ctl,
&root->fs_info->caching_block_groups, list)
if ( V_51 -> V_14 == V_14 ) {
V_53 = V_51 ;
F_5 ( & V_53 -> V_8 ) ;
break;
}
}
if ( V_53 )
F_258 ( & V_53 -> V_90 ) ;
F_65 ( & V_35 -> V_37 -> V_79 ) ;
if ( V_53 ) {
F_26 ( V_53 ) ;
F_26 ( V_53 ) ;
}
}
F_11 ( & V_110 -> V_127 -> V_307 ) ;
if ( ! F_169 ( & V_14 -> V_309 ) ) {
F_8 ( 1 ) ;
}
if ( ! F_169 ( & V_14 -> V_310 ) ) {
F_8 ( 1 ) ;
}
F_13 ( & V_110 -> V_127 -> V_307 ) ;
F_501 ( V_14 ) ;
F_11 ( & V_14 -> V_105 -> V_52 ) ;
F_258 ( & V_14 -> V_649 ) ;
if ( F_247 ( V_35 , V_390 ) ) {
F_8 ( V_14 -> V_105 -> V_316
< V_14 -> V_21 . V_33 ) ;
F_8 ( V_14 -> V_105 -> V_331
< V_14 -> V_21 . V_33 ) ;
F_8 ( V_14 -> V_105 -> V_322
< V_14 -> V_21 . V_33 * V_318 ) ;
}
V_14 -> V_105 -> V_316 -= V_14 -> V_21 . V_33 ;
V_14 -> V_105 -> V_331 -= V_14 -> V_21 . V_33 ;
V_14 -> V_105 -> V_322 -= V_14 -> V_21 . V_33 * V_318 ;
F_13 ( & V_14 -> V_105 -> V_52 ) ;
memcpy ( & V_21 , & V_14 -> V_21 , sizeof( V_21 ) ) ;
F_490 ( V_35 ) ;
if ( ! F_169 ( & V_680 -> V_90 ) ) {
F_529 ( V_680 ) ;
}
F_11 ( & V_14 -> V_52 ) ;
V_14 -> V_683 = 1 ;
V_681 = ( F_197 ( & V_14 -> V_671 ) == 0 ) ;
if ( ! V_681 ) {
F_530 ( & V_680 -> V_90 , & V_35 -> V_37 -> V_684 ) ;
}
F_13 ( & V_14 -> V_52 ) ;
if ( V_681 ) {
struct V_685 * V_686 ;
V_686 = & V_35 -> V_37 -> V_48 . V_687 ;
F_531 ( & V_686 -> V_52 ) ;
F_532 ( V_686 , V_680 ) ;
F_533 ( & V_686 -> V_52 ) ;
F_529 ( V_680 ) ;
}
F_491 ( V_35 ) ;
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
void F_534 ( struct V_12 * V_37 )
{
struct V_1 * V_14 ;
struct V_102 * V_105 ;
struct V_34 * V_35 = V_37 -> V_62 ;
struct V_109 * V_110 ;
int V_29 = 0 ;
if ( ! V_37 -> V_688 )
return;
F_11 ( & V_37 -> V_498 ) ;
while ( ! F_169 ( & V_37 -> V_500 ) ) {
T_2 V_32 , V_31 ;
V_14 = F_257 ( & V_37 -> V_500 ,
struct V_1 ,
V_499 ) ;
V_105 = V_14 -> V_105 ;
F_258 ( & V_14 -> V_499 ) ;
if ( V_29 || F_303 ( V_105 ) ) {
F_6 ( V_14 ) ;
continue;
}
F_13 ( & V_37 -> V_498 ) ;
F_35 ( & V_35 -> V_37 -> V_689 ) ;
F_63 ( & V_105 -> V_328 ) ;
F_11 ( & V_14 -> V_52 ) ;
if ( V_14 -> V_10 ||
F_371 ( & V_14 -> V_135 ) ||
V_14 -> V_288 ) {
F_13 ( & V_14 -> V_52 ) ;
F_65 ( & V_105 -> V_328 ) ;
goto V_80;
}
F_13 ( & V_14 -> V_52 ) ;
V_29 = F_487 ( V_14 , 0 ) ;
F_65 ( & V_105 -> V_328 ) ;
if ( V_29 < 0 ) {
V_29 = 0 ;
goto V_80;
}
V_110 = F_467 ( V_35 , 1 ) ;
if ( F_200 ( V_110 ) ) {
F_494 ( V_35 , V_14 ) ;
V_29 = F_201 ( V_110 ) ;
goto V_80;
}
V_32 = V_14 -> V_21 . V_22 ;
V_31 = V_32 + V_14 -> V_21 . V_33 - 1 ;
F_35 ( & V_37 -> V_513 ) ;
V_29 = F_20 ( & V_37 -> V_38 [ 0 ] , V_32 , V_31 ,
V_59 , V_40 ) ;
if ( V_29 ) {
F_46 ( & V_37 -> V_513 ) ;
F_494 ( V_35 , V_14 ) ;
goto V_690;
}
V_29 = F_20 ( & V_37 -> V_38 [ 1 ] , V_32 , V_31 ,
V_59 , V_40 ) ;
if ( V_29 ) {
F_46 ( & V_37 -> V_513 ) ;
F_494 ( V_35 , V_14 ) ;
goto V_690;
}
F_46 ( & V_37 -> V_513 ) ;
F_11 ( & V_105 -> V_52 ) ;
F_11 ( & V_14 -> V_52 ) ;
V_105 -> V_329 -= V_14 -> V_9 ;
V_105 -> V_331 += V_14 -> V_9 ;
F_383 ( & V_105 -> V_324 ,
- V_14 -> V_9 ) ;
V_14 -> V_9 = 0 ;
F_13 ( & V_14 -> V_52 ) ;
F_13 ( & V_105 -> V_52 ) ;
V_29 = F_535 ( V_110 , V_35 ,
V_14 -> V_21 . V_22 ) ;
V_690:
F_203 ( V_110 , V_35 ) ;
V_80:
F_46 ( & V_35 -> V_37 -> V_689 ) ;
F_6 ( V_14 ) ;
F_11 ( & V_37 -> V_498 ) ;
}
F_13 ( & V_37 -> V_498 ) ;
}
int F_536 ( struct V_12 * V_37 )
{
struct V_102 * V_105 ;
struct V_691 * V_692 ;
T_2 V_693 ;
T_2 V_7 ;
int V_694 = 0 ;
int V_29 ;
V_692 = V_37 -> V_245 ;
if ( ! F_537 ( V_692 ) )
return 1 ;
V_693 = F_538 ( V_692 ) ;
if ( V_693 & V_695 )
V_694 = 1 ;
V_7 = V_315 ;
V_29 = F_264 ( V_37 , V_7 , 0 , 0 , & V_105 ) ;
if ( V_29 )
goto V_72;
if ( V_694 ) {
V_7 = V_313 | V_314 ;
V_29 = F_264 ( V_37 , V_7 , 0 , 0 , & V_105 ) ;
} else {
V_7 = V_313 ;
V_29 = F_264 ( V_37 , V_7 , 0 , 0 , & V_105 ) ;
if ( V_29 )
goto V_72;
V_7 = V_314 ;
V_29 = F_264 ( V_37 , V_7 , 0 , 0 , & V_105 ) ;
}
V_72:
return V_29 ;
}
int F_539 ( struct V_34 * V_35 , T_2 V_32 , T_2 V_31 )
{
return F_382 ( V_35 , V_32 , V_31 , false ) ;
}
int F_540 ( struct V_34 * V_35 , struct V_696 * V_697 )
{
struct V_12 * V_37 = V_35 -> V_37 ;
struct V_1 * V_2 = NULL ;
T_2 V_698 ;
T_2 V_32 ;
T_2 V_31 ;
T_2 V_699 = 0 ;
T_2 V_316 = F_292 ( V_37 -> V_245 ) ;
int V_29 = 0 ;
if ( V_697 -> V_49 == V_316 )
V_2 = F_67 ( V_37 , V_697 -> V_32 ) ;
else
V_2 = F_68 ( V_37 , V_697 -> V_32 ) ;
while ( V_2 ) {
if ( V_2 -> V_21 . V_22 >= ( V_697 -> V_32 + V_697 -> V_49 ) ) {
F_6 ( V_2 ) ;
break;
}
V_32 = F_407 ( V_697 -> V_32 , V_2 -> V_21 . V_22 ) ;
V_31 = F_313 ( V_697 -> V_32 + V_697 -> V_49 ,
V_2 -> V_21 . V_22 + V_2 -> V_21 . V_33 ) ;
if ( V_31 - V_32 >= V_697 -> V_700 ) {
if ( ! F_1 ( V_2 ) ) {
V_29 = F_51 ( V_2 , 0 ) ;
if ( V_29 ) {
F_6 ( V_2 ) ;
break;
}
V_29 = F_397 ( V_2 ) ;
if ( V_29 ) {
F_6 ( V_2 ) ;
break;
}
}
V_29 = F_541 ( V_2 ,
& V_698 ,
V_32 ,
V_31 ,
V_697 -> V_700 ) ;
V_699 += V_698 ;
if ( V_29 ) {
F_6 ( V_2 ) ;
break;
}
}
V_2 = F_237 ( V_37 -> V_86 , V_2 ) ;
}
V_697 -> V_49 = V_699 ;
return V_29 ;
}
void F_542 ( struct V_34 * V_35 )
{
F_543 ( & V_35 -> V_701 -> V_702 ) ;
F_2 () ;
if ( F_544 ( & V_35 -> V_701 -> V_88 ) )
F_49 ( & V_35 -> V_701 -> V_88 ) ;
}
int F_545 ( struct V_34 * V_35 )
{
if ( F_197 ( & V_35 -> V_703 ) )
return 0 ;
F_546 ( & V_35 -> V_701 -> V_702 ) ;
F_2 () ;
if ( F_197 ( & V_35 -> V_703 ) ) {
F_542 ( V_35 ) ;
return 0 ;
}
return 1 ;
}
