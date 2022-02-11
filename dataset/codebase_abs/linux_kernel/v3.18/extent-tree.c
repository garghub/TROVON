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
if ( V_2 -> V_3 != V_53 ) {
F_13 ( & V_2 -> V_52 ) ;
return NULL ;
}
if ( ! V_2 -> V_54 ) {
F_13 ( & V_2 -> V_52 ) ;
return NULL ;
}
V_51 = V_2 -> V_54 ;
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
T_2 V_55 , V_56 , V_57 , V_58 = 0 ;
int V_29 ;
while ( V_32 < V_31 ) {
V_29 = F_28 ( V_13 -> V_59 , V_32 ,
& V_55 , & V_56 ,
V_60 | V_39 ,
NULL ) ;
if ( V_29 )
break;
if ( V_55 <= V_32 ) {
V_32 = V_56 + 1 ;
} else if ( V_55 > V_32 && V_55 < V_31 ) {
V_57 = V_55 - V_32 ;
V_58 += V_57 ;
V_29 = F_29 ( V_14 , V_32 ,
V_57 ) ;
F_30 ( V_29 ) ;
V_32 = V_56 + 1 ;
} else {
break;
}
}
if ( V_32 < V_31 ) {
V_57 = V_31 - V_32 ;
V_58 += V_57 ;
V_29 = F_29 ( V_14 , V_32 , V_57 ) ;
F_30 ( V_29 ) ;
}
return V_58 ;
}
static T_1 void F_31 ( struct V_61 * V_62 )
{
struct V_1 * V_14 ;
struct V_12 * V_37 ;
struct V_50 * V_54 ;
struct V_34 * V_63 ;
struct V_64 * V_65 ;
struct V_66 * V_67 ;
struct V_68 V_21 ;
T_2 V_69 = 0 ;
T_2 V_70 = 0 ;
T_3 V_71 ;
int V_29 = - V_72 ;
V_54 = F_32 ( V_62 , struct V_50 , V_62 ) ;
V_14 = V_54 -> V_14 ;
V_37 = V_14 -> V_37 ;
V_63 = V_37 -> V_63 ;
V_65 = F_33 () ;
if ( ! V_65 )
goto V_73;
V_70 = F_34 ( T_2 , V_14 -> V_21 . V_22 , V_45 ) ;
V_65 -> V_74 = 1 ;
V_65 -> V_75 = 1 ;
V_65 -> V_76 = 1 ;
V_21 . V_22 = V_70 ;
V_21 . V_33 = 0 ;
V_21 . type = V_77 ;
V_78:
F_35 ( & V_54 -> V_79 ) ;
F_36 ( & V_37 -> V_80 ) ;
V_81:
V_29 = F_37 ( NULL , V_63 , & V_21 , V_65 , 0 , 0 ) ;
if ( V_29 < 0 )
goto V_82;
V_67 = V_65 -> V_83 [ 0 ] ;
V_71 = F_38 ( V_67 ) ;
while ( 1 ) {
if ( F_39 ( V_37 ) > 1 ) {
V_70 = ( T_2 ) - 1 ;
break;
}
if ( V_65 -> V_84 [ 0 ] < V_71 ) {
F_40 ( V_67 , & V_21 , V_65 -> V_84 [ 0 ] ) ;
} else {
V_29 = F_41 ( V_65 , 0 , & V_21 ) ;
if ( V_29 )
break;
if ( F_42 () ||
F_43 ( & V_37 -> V_80 ) ) {
V_54 -> V_85 = V_70 ;
F_44 ( V_65 ) ;
F_45 ( & V_37 -> V_80 ) ;
F_46 ( & V_54 -> V_79 ) ;
F_47 () ;
goto V_78;
}
V_29 = F_48 ( V_63 , V_65 ) ;
if ( V_29 < 0 )
goto V_82;
if ( V_29 )
break;
V_67 = V_65 -> V_83 [ 0 ] ;
V_71 = F_38 ( V_67 ) ;
continue;
}
if ( V_21 . V_22 < V_70 ) {
V_21 . V_22 = V_70 ;
V_21 . V_33 = 0 ;
V_21 . type = V_77 ;
V_54 -> V_85 = V_70 ;
F_44 ( V_65 ) ;
goto V_81;
}
if ( V_21 . V_22 < V_14 -> V_21 . V_22 ) {
V_65 -> V_84 [ 0 ] ++ ;
continue;
}
if ( V_21 . V_22 >= V_14 -> V_21 . V_22 +
V_14 -> V_21 . V_33 )
break;
if ( V_21 . type == V_77 ||
V_21 . type == V_86 ) {
V_69 += F_27 ( V_14 ,
V_37 , V_70 ,
V_21 . V_22 ) ;
if ( V_21 . type == V_86 )
V_70 = V_21 . V_22 +
V_37 -> V_87 -> V_88 ;
else
V_70 = V_21 . V_22 + V_21 . V_33 ;
if ( V_69 > ( 1024 * 1024 * 2 ) ) {
V_69 = 0 ;
F_49 ( & V_54 -> V_89 ) ;
}
}
V_65 -> V_84 [ 0 ] ++ ;
}
V_29 = 0 ;
V_69 += F_27 ( V_14 , V_37 , V_70 ,
V_14 -> V_21 . V_22 +
V_14 -> V_21 . V_33 ) ;
V_54 -> V_85 = ( T_2 ) - 1 ;
F_11 ( & V_14 -> V_52 ) ;
V_14 -> V_54 = NULL ;
V_14 -> V_3 = V_4 ;
F_13 ( & V_14 -> V_52 ) ;
V_82:
F_50 ( V_65 ) ;
F_45 ( & V_37 -> V_80 ) ;
F_19 ( V_63 , V_14 ) ;
F_46 ( & V_54 -> V_79 ) ;
V_73:
if ( V_29 ) {
F_11 ( & V_14 -> V_52 ) ;
V_14 -> V_54 = NULL ;
V_14 -> V_3 = V_5 ;
F_13 ( & V_14 -> V_52 ) ;
}
F_49 ( & V_54 -> V_89 ) ;
F_26 ( V_54 ) ;
F_6 ( V_14 ) ;
}
static int F_51 ( struct V_1 * V_2 ,
int V_90 )
{
F_52 ( V_89 ) ;
struct V_12 * V_37 = V_2 -> V_37 ;
struct V_50 * V_54 ;
int V_29 = 0 ;
V_54 = F_53 ( sizeof( * V_54 ) , V_40 ) ;
if ( ! V_54 )
return - V_72 ;
F_54 ( & V_54 -> V_91 ) ;
F_55 ( & V_54 -> V_79 ) ;
F_56 ( & V_54 -> V_89 ) ;
V_54 -> V_14 = V_2 ;
V_54 -> V_85 = V_2 -> V_21 . V_22 ;
F_57 ( & V_54 -> V_8 , 1 ) ;
F_58 ( & V_54 -> V_62 , V_92 ,
F_31 , NULL , NULL ) ;
F_11 ( & V_2 -> V_52 ) ;
while ( V_2 -> V_3 == V_93 ) {
struct V_50 * V_51 ;
V_51 = V_2 -> V_54 ;
F_5 ( & V_51 -> V_8 ) ;
F_59 ( & V_51 -> V_89 , & V_89 , V_94 ) ;
F_13 ( & V_2 -> V_52 ) ;
F_60 () ;
F_61 ( & V_51 -> V_89 , & V_89 ) ;
F_26 ( V_51 ) ;
F_11 ( & V_2 -> V_52 ) ;
}
if ( V_2 -> V_3 != V_95 ) {
F_13 ( & V_2 -> V_52 ) ;
F_9 ( V_54 ) ;
return 0 ;
}
F_8 ( V_2 -> V_54 ) ;
V_2 -> V_54 = V_54 ;
V_2 -> V_3 = V_93 ;
F_13 ( & V_2 -> V_52 ) ;
if ( V_37 -> V_96 & V_97 ) {
V_29 = F_62 ( V_37 , V_2 ) ;
F_11 ( & V_2 -> V_52 ) ;
if ( V_29 == 1 ) {
V_2 -> V_54 = NULL ;
V_2 -> V_3 = V_4 ;
V_2 -> V_98 = ( T_2 ) - 1 ;
} else {
if ( V_90 ) {
V_2 -> V_54 = NULL ;
V_2 -> V_3 = V_95 ;
} else {
V_2 -> V_3 = V_53 ;
}
}
F_13 ( & V_2 -> V_52 ) ;
F_49 ( & V_54 -> V_89 ) ;
if ( V_29 == 1 ) {
F_26 ( V_54 ) ;
F_19 ( V_37 -> V_63 , V_2 ) ;
return 0 ;
}
} else {
F_11 ( & V_2 -> V_52 ) ;
if ( V_90 ) {
V_2 -> V_54 = NULL ;
V_2 -> V_3 = V_95 ;
} else {
V_2 -> V_3 = V_53 ;
}
F_13 ( & V_2 -> V_52 ) ;
F_49 ( & V_54 -> V_89 ) ;
}
if ( V_90 ) {
F_26 ( V_54 ) ;
return 0 ;
}
F_63 ( & V_37 -> V_80 ) ;
F_5 ( & V_54 -> V_8 ) ;
F_64 ( & V_54 -> V_91 , & V_37 -> V_99 ) ;
F_65 ( & V_37 -> V_80 ) ;
F_4 ( V_2 ) ;
F_66 ( V_37 -> V_100 , & V_54 -> V_62 ) ;
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
static struct V_101 * F_69 ( struct V_12 * V_13 ,
T_2 V_7 )
{
struct V_102 * V_103 = & V_13 -> V_104 ;
struct V_101 * V_105 ;
V_7 &= V_106 ;
F_70 () ;
F_71 (found, head, list) {
if ( V_105 -> V_7 & V_7 ) {
F_72 () ;
return V_105 ;
}
}
F_72 () ;
return NULL ;
}
void F_73 ( struct V_12 * V_13 )
{
struct V_102 * V_103 = & V_13 -> V_104 ;
struct V_101 * V_105 ;
F_70 () ;
F_71 (found, head, list)
V_105 -> V_107 = 0 ;
F_72 () ;
}
int F_74 ( struct V_34 * V_35 , T_2 V_32 , T_2 V_49 )
{
int V_29 ;
struct V_68 V_21 ;
struct V_64 * V_65 ;
V_65 = F_33 () ;
if ( ! V_65 )
return - V_72 ;
V_21 . V_22 = V_32 ;
V_21 . V_33 = V_49 ;
V_21 . type = V_77 ;
V_29 = F_37 ( NULL , V_35 -> V_37 -> V_63 , & V_21 , V_65 ,
0 , 0 ) ;
F_50 ( V_65 ) ;
return V_29 ;
}
int F_75 ( struct V_108 * V_109 ,
struct V_34 * V_35 , T_2 V_27 ,
T_2 V_33 , int V_110 , T_2 * V_111 , T_2 * V_7 )
{
struct V_112 * V_103 ;
struct V_113 * V_114 ;
struct V_64 * V_65 ;
struct V_115 * V_116 ;
struct V_66 * V_67 ;
struct V_68 V_21 ;
T_3 V_117 ;
T_2 V_118 ;
T_2 V_119 ;
int V_29 ;
if ( V_110 && ! F_76 ( V_35 -> V_37 , V_120 ) ) {
V_33 = V_35 -> V_88 ;
V_110 = 0 ;
}
V_65 = F_33 () ;
if ( ! V_65 )
return - V_72 ;
if ( ! V_109 ) {
V_65 -> V_74 = 1 ;
V_65 -> V_75 = 1 ;
}
V_121:
V_21 . V_22 = V_27 ;
V_21 . V_33 = V_33 ;
if ( V_110 )
V_21 . type = V_86 ;
else
V_21 . type = V_77 ;
V_29 = F_37 ( V_109 , V_35 -> V_37 -> V_63 ,
& V_21 , V_65 , 0 , 0 ) ;
if ( V_29 < 0 )
goto V_122;
if ( V_29 > 0 && V_110 && V_21 . type == V_86 ) {
if ( V_65 -> V_84 [ 0 ] ) {
V_65 -> V_84 [ 0 ] -- ;
F_40 ( V_65 -> V_83 [ 0 ] , & V_21 ,
V_65 -> V_84 [ 0 ] ) ;
if ( V_21 . V_22 == V_27 &&
V_21 . type == V_77 &&
V_21 . V_33 == V_35 -> V_88 )
V_29 = 0 ;
}
}
if ( V_29 == 0 ) {
V_67 = V_65 -> V_83 [ 0 ] ;
V_117 = F_77 ( V_67 , V_65 -> V_84 [ 0 ] ) ;
if ( V_117 >= sizeof( * V_116 ) ) {
V_116 = F_78 ( V_67 , V_65 -> V_84 [ 0 ] ,
struct V_115 ) ;
V_118 = F_79 ( V_67 , V_116 ) ;
V_119 = F_80 ( V_67 , V_116 ) ;
} else {
#ifdef F_81
struct V_123 * V_124 ;
F_30 ( V_117 != sizeof( * V_124 ) ) ;
V_124 = F_78 ( V_67 , V_65 -> V_84 [ 0 ] ,
struct V_123 ) ;
V_118 = F_82 ( V_67 , V_124 ) ;
V_119 = V_125 ;
#else
F_83 () ;
#endif
}
F_30 ( V_118 == 0 ) ;
} else {
V_118 = 0 ;
V_119 = 0 ;
V_29 = 0 ;
}
if ( ! V_109 )
goto V_73;
V_114 = & V_109 -> V_126 -> V_114 ;
F_11 ( & V_114 -> V_52 ) ;
V_103 = F_84 ( V_109 , V_27 ) ;
if ( V_103 ) {
if ( ! F_85 ( & V_103 -> V_79 ) ) {
F_5 ( & V_103 -> V_127 . V_111 ) ;
F_13 ( & V_114 -> V_52 ) ;
F_44 ( V_65 ) ;
F_35 ( & V_103 -> V_79 ) ;
F_46 ( & V_103 -> V_79 ) ;
F_86 ( & V_103 -> V_127 ) ;
goto V_121;
}
F_11 ( & V_103 -> V_52 ) ;
if ( V_103 -> V_128 && V_103 -> V_128 -> V_129 )
V_119 |= V_103 -> V_128 -> V_130 ;
else
F_30 ( V_118 == 0 ) ;
V_118 += V_103 -> V_127 . V_131 ;
F_13 ( & V_103 -> V_52 ) ;
F_46 ( & V_103 -> V_79 ) ;
}
F_13 ( & V_114 -> V_52 ) ;
V_73:
F_8 ( V_118 == 0 ) ;
if ( V_111 )
* V_111 = V_118 ;
if ( V_7 )
* V_7 = V_119 ;
V_122:
F_50 ( V_65 ) ;
return V_29 ;
}
static int F_87 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
struct V_64 * V_65 ,
T_2 V_132 , T_3 V_133 )
{
struct V_115 * V_134 ;
struct V_123 * V_124 ;
struct V_135 * V_136 ;
struct V_137 * V_138 ;
struct V_66 * V_67 ;
struct V_68 V_21 ;
struct V_68 V_139 ;
T_3 V_140 = sizeof( * V_134 ) ;
T_2 V_111 ;
int V_29 ;
V_67 = V_65 -> V_83 [ 0 ] ;
F_30 ( F_77 ( V_67 , V_65 -> V_84 [ 0 ] ) != sizeof( * V_124 ) ) ;
F_40 ( V_67 , & V_21 , V_65 -> V_84 [ 0 ] ) ;
V_124 = F_78 ( V_67 , V_65 -> V_84 [ 0 ] ,
struct V_123 ) ;
V_111 = F_82 ( V_67 , V_124 ) ;
if ( V_132 == ( T_2 ) - 1 ) {
while ( 1 ) {
if ( V_65 -> V_84 [ 0 ] >= F_38 ( V_67 ) ) {
V_29 = F_48 ( V_35 , V_65 ) ;
if ( V_29 < 0 )
return V_29 ;
F_30 ( V_29 > 0 ) ;
V_67 = V_65 -> V_83 [ 0 ] ;
}
F_40 ( V_67 , & V_139 ,
V_65 -> V_84 [ 0 ] ) ;
F_30 ( V_21 . V_22 != V_139 . V_22 ) ;
if ( V_139 . type != V_141 ) {
V_65 -> V_84 [ 0 ] ++ ;
continue;
}
V_136 = F_78 ( V_67 , V_65 -> V_84 [ 0 ] ,
struct V_135 ) ;
V_132 = F_88 ( V_67 , V_136 ) ;
break;
}
}
F_44 ( V_65 ) ;
if ( V_132 < V_142 )
V_140 += sizeof( * V_138 ) ;
V_140 -= sizeof( * V_124 ) ;
V_29 = F_37 ( V_109 , V_35 , & V_21 , V_65 ,
V_140 + V_133 , 1 ) ;
if ( V_29 < 0 )
return V_29 ;
F_30 ( V_29 ) ;
F_89 ( V_35 , V_65 , V_140 ) ;
V_67 = V_65 -> V_83 [ 0 ] ;
V_134 = F_78 ( V_67 , V_65 -> V_84 [ 0 ] , struct V_115 ) ;
F_90 ( V_67 , V_134 , V_111 ) ;
F_91 ( V_67 , V_134 , 0 ) ;
if ( V_132 < V_142 ) {
F_92 ( V_67 , V_134 ,
V_143 |
V_125 ) ;
V_138 = (struct V_137 * ) ( V_134 + 1 ) ;
F_93 ( V_67 , 0 , ( unsigned long ) V_138 , sizeof( * V_138 ) ) ;
F_94 ( V_67 , V_138 , ( int ) V_132 ) ;
} else {
F_92 ( V_67 , V_134 , V_144 ) ;
}
F_95 ( V_67 ) ;
return 0 ;
}
static T_2 F_96 ( T_2 V_145 , T_2 V_132 , T_2 V_33 )
{
T_3 V_146 = ~ ( T_3 ) 0 ;
T_3 V_147 = ~ ( T_3 ) 0 ;
T_4 V_148 ;
V_148 = F_97 ( V_145 ) ;
V_146 = F_98 ( V_146 , & V_148 , sizeof( V_148 ) ) ;
V_148 = F_97 ( V_132 ) ;
V_147 = F_98 ( V_147 , & V_148 , sizeof( V_148 ) ) ;
V_148 = F_97 ( V_33 ) ;
V_147 = F_98 ( V_147 , & V_148 , sizeof( V_148 ) ) ;
return ( ( T_2 ) V_146 << 31 ) ^ ( T_2 ) V_147 ;
}
static T_2 F_99 ( struct V_66 * V_67 ,
struct V_149 * V_150 )
{
return F_96 ( F_100 ( V_67 , V_150 ) ,
F_101 ( V_67 , V_150 ) ,
F_102 ( V_67 , V_150 ) ) ;
}
static int F_103 ( struct V_66 * V_67 ,
struct V_149 * V_150 ,
T_2 V_145 , T_2 V_132 , T_2 V_33 )
{
if ( F_100 ( V_67 , V_150 ) != V_145 ||
F_101 ( V_67 , V_150 ) != V_132 ||
F_102 ( V_67 , V_150 ) != V_33 )
return 0 ;
return 1 ;
}
static T_1 int F_104 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
struct V_64 * V_65 ,
T_2 V_27 , T_2 V_17 ,
T_2 V_145 ,
T_2 V_132 , T_2 V_33 )
{
struct V_68 V_21 ;
struct V_149 * V_150 ;
struct V_66 * V_67 ;
T_3 V_71 ;
int V_29 ;
int V_151 ;
int V_82 = - V_152 ;
V_21 . V_22 = V_27 ;
if ( V_17 ) {
V_21 . type = V_153 ;
V_21 . V_33 = V_17 ;
} else {
V_21 . type = V_154 ;
V_21 . V_33 = F_96 ( V_145 ,
V_132 , V_33 ) ;
}
V_78:
V_151 = 0 ;
V_29 = F_37 ( V_109 , V_35 , & V_21 , V_65 , - 1 , 1 ) ;
if ( V_29 < 0 ) {
V_82 = V_29 ;
goto V_155;
}
if ( V_17 ) {
if ( ! V_29 )
return 0 ;
#ifdef F_81
V_21 . type = V_141 ;
F_44 ( V_65 ) ;
V_29 = F_37 ( V_109 , V_35 , & V_21 , V_65 , - 1 , 1 ) ;
if ( V_29 < 0 ) {
V_82 = V_29 ;
goto V_155;
}
if ( ! V_29 )
return 0 ;
#endif
goto V_155;
}
V_67 = V_65 -> V_83 [ 0 ] ;
V_71 = F_38 ( V_67 ) ;
while ( 1 ) {
if ( V_65 -> V_84 [ 0 ] >= V_71 ) {
V_29 = F_48 ( V_35 , V_65 ) ;
if ( V_29 < 0 )
V_82 = V_29 ;
if ( V_29 )
goto V_155;
V_67 = V_65 -> V_83 [ 0 ] ;
V_71 = F_38 ( V_67 ) ;
V_151 = 1 ;
}
F_40 ( V_67 , & V_21 , V_65 -> V_84 [ 0 ] ) ;
if ( V_21 . V_22 != V_27 ||
V_21 . type != V_154 )
goto V_155;
V_150 = F_78 ( V_67 , V_65 -> V_84 [ 0 ] ,
struct V_149 ) ;
if ( F_103 ( V_67 , V_150 , V_145 ,
V_132 , V_33 ) ) {
if ( V_151 ) {
F_44 ( V_65 ) ;
goto V_78;
}
V_82 = 0 ;
break;
}
V_65 -> V_84 [ 0 ] ++ ;
}
V_155:
return V_82 ;
}
static T_1 int F_105 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
struct V_64 * V_65 ,
T_2 V_27 , T_2 V_17 ,
T_2 V_145 , T_2 V_132 ,
T_2 V_33 , int V_156 )
{
struct V_68 V_21 ;
struct V_66 * V_67 ;
T_3 V_57 ;
T_3 V_118 ;
int V_29 ;
V_21 . V_22 = V_27 ;
if ( V_17 ) {
V_21 . type = V_153 ;
V_21 . V_33 = V_17 ;
V_57 = sizeof( struct V_157 ) ;
} else {
V_21 . type = V_154 ;
V_21 . V_33 = F_96 ( V_145 ,
V_132 , V_33 ) ;
V_57 = sizeof( struct V_149 ) ;
}
V_29 = F_106 ( V_109 , V_35 , V_65 , & V_21 , V_57 ) ;
if ( V_29 && V_29 != - V_25 )
goto V_155;
V_67 = V_65 -> V_83 [ 0 ] ;
if ( V_17 ) {
struct V_157 * V_150 ;
V_150 = F_78 ( V_67 , V_65 -> V_84 [ 0 ] ,
struct V_157 ) ;
if ( V_29 == 0 ) {
F_107 ( V_67 , V_150 , V_156 ) ;
} else {
V_118 = F_108 ( V_67 , V_150 ) ;
V_118 += V_156 ;
F_107 ( V_67 , V_150 , V_118 ) ;
}
} else {
struct V_149 * V_150 ;
while ( V_29 == - V_25 ) {
V_150 = F_78 ( V_67 , V_65 -> V_84 [ 0 ] ,
struct V_149 ) ;
if ( F_103 ( V_67 , V_150 , V_145 ,
V_132 , V_33 ) )
break;
F_44 ( V_65 ) ;
V_21 . V_33 ++ ;
V_29 = F_106 ( V_109 , V_35 , V_65 , & V_21 ,
V_57 ) ;
if ( V_29 && V_29 != - V_25 )
goto V_155;
V_67 = V_65 -> V_83 [ 0 ] ;
}
V_150 = F_78 ( V_67 , V_65 -> V_84 [ 0 ] ,
struct V_149 ) ;
if ( V_29 == 0 ) {
F_109 ( V_67 , V_150 ,
V_145 ) ;
F_110 ( V_67 , V_150 , V_132 ) ;
F_111 ( V_67 , V_150 , V_33 ) ;
F_112 ( V_67 , V_150 , V_156 ) ;
} else {
V_118 = F_113 ( V_67 , V_150 ) ;
V_118 += V_156 ;
F_112 ( V_67 , V_150 , V_118 ) ;
}
}
F_95 ( V_67 ) ;
V_29 = 0 ;
V_155:
F_44 ( V_65 ) ;
return V_29 ;
}
static T_1 int F_114 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
struct V_64 * V_65 ,
int V_158 , int * V_159 )
{
struct V_68 V_21 ;
struct V_149 * V_160 = NULL ;
struct V_157 * V_161 = NULL ;
struct V_66 * V_67 ;
T_3 V_118 = 0 ;
int V_29 = 0 ;
V_67 = V_65 -> V_83 [ 0 ] ;
F_40 ( V_67 , & V_21 , V_65 -> V_84 [ 0 ] ) ;
if ( V_21 . type == V_154 ) {
V_160 = F_78 ( V_67 , V_65 -> V_84 [ 0 ] ,
struct V_149 ) ;
V_118 = F_113 ( V_67 , V_160 ) ;
} else if ( V_21 . type == V_153 ) {
V_161 = F_78 ( V_67 , V_65 -> V_84 [ 0 ] ,
struct V_157 ) ;
V_118 = F_108 ( V_67 , V_161 ) ;
#ifdef F_81
} else if ( V_21 . type == V_141 ) {
struct V_135 * V_136 ;
V_136 = F_78 ( V_67 , V_65 -> V_84 [ 0 ] ,
struct V_135 ) ;
V_118 = F_115 ( V_67 , V_136 ) ;
#endif
} else {
F_83 () ;
}
F_30 ( V_118 < V_158 ) ;
V_118 -= V_158 ;
if ( V_118 == 0 ) {
V_29 = F_116 ( V_109 , V_35 , V_65 ) ;
* V_159 = 1 ;
} else {
if ( V_21 . type == V_154 )
F_112 ( V_67 , V_160 , V_118 ) ;
else if ( V_21 . type == V_153 )
F_107 ( V_67 , V_161 , V_118 ) ;
#ifdef F_81
else {
struct V_135 * V_136 ;
V_136 = F_78 ( V_67 , V_65 -> V_84 [ 0 ] ,
struct V_135 ) ;
F_117 ( V_67 , V_136 , V_118 ) ;
}
#endif
F_95 ( V_67 ) ;
}
return V_29 ;
}
static T_1 T_3 F_118 ( struct V_34 * V_35 ,
struct V_64 * V_65 ,
struct V_162 * V_163 )
{
struct V_68 V_21 ;
struct V_66 * V_67 ;
struct V_149 * V_160 ;
struct V_157 * V_161 ;
T_3 V_118 = 0 ;
V_67 = V_65 -> V_83 [ 0 ] ;
F_40 ( V_67 , & V_21 , V_65 -> V_84 [ 0 ] ) ;
if ( V_163 ) {
if ( F_119 ( V_67 , V_163 ) ==
V_154 ) {
V_160 = (struct V_149 * ) ( & V_163 -> V_33 ) ;
V_118 = F_113 ( V_67 , V_160 ) ;
} else {
V_161 = (struct V_157 * ) ( V_163 + 1 ) ;
V_118 = F_108 ( V_67 , V_161 ) ;
}
} else if ( V_21 . type == V_154 ) {
V_160 = F_78 ( V_67 , V_65 -> V_84 [ 0 ] ,
struct V_149 ) ;
V_118 = F_113 ( V_67 , V_160 ) ;
} else if ( V_21 . type == V_153 ) {
V_161 = F_78 ( V_67 , V_65 -> V_84 [ 0 ] ,
struct V_157 ) ;
V_118 = F_108 ( V_67 , V_161 ) ;
#ifdef F_81
} else if ( V_21 . type == V_141 ) {
struct V_135 * V_136 ;
V_136 = F_78 ( V_67 , V_65 -> V_84 [ 0 ] ,
struct V_135 ) ;
V_118 = F_115 ( V_67 , V_136 ) ;
#endif
} else {
F_8 ( 1 ) ;
}
return V_118 ;
}
static T_1 int F_120 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
struct V_64 * V_65 ,
T_2 V_27 , T_2 V_17 ,
T_2 V_145 )
{
struct V_68 V_21 ;
int V_29 ;
V_21 . V_22 = V_27 ;
if ( V_17 ) {
V_21 . type = V_164 ;
V_21 . V_33 = V_17 ;
} else {
V_21 . type = V_165 ;
V_21 . V_33 = V_145 ;
}
V_29 = F_37 ( V_109 , V_35 , & V_21 , V_65 , - 1 , 1 ) ;
if ( V_29 > 0 )
V_29 = - V_152 ;
#ifdef F_81
if ( V_29 == - V_152 && V_17 ) {
F_44 ( V_65 ) ;
V_21 . type = V_141 ;
V_29 = F_37 ( V_109 , V_35 , & V_21 , V_65 , - 1 , 1 ) ;
if ( V_29 > 0 )
V_29 = - V_152 ;
}
#endif
return V_29 ;
}
static T_1 int F_121 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
struct V_64 * V_65 ,
T_2 V_27 , T_2 V_17 ,
T_2 V_145 )
{
struct V_68 V_21 ;
int V_29 ;
V_21 . V_22 = V_27 ;
if ( V_17 ) {
V_21 . type = V_164 ;
V_21 . V_33 = V_17 ;
} else {
V_21 . type = V_165 ;
V_21 . V_33 = V_145 ;
}
V_29 = F_106 ( V_109 , V_35 , V_65 , & V_21 , 0 ) ;
F_44 ( V_65 ) ;
return V_29 ;
}
static inline int F_122 ( T_2 V_17 , T_2 V_132 )
{
int type ;
if ( V_132 < V_142 ) {
if ( V_17 > 0 )
type = V_164 ;
else
type = V_165 ;
} else {
if ( V_17 > 0 )
type = V_153 ;
else
type = V_154 ;
}
return type ;
}
static int F_41 ( struct V_64 * V_65 , int V_166 ,
struct V_68 * V_21 )
{
for (; V_166 < V_167 ; V_166 ++ ) {
if ( ! V_65 -> V_83 [ V_166 ] )
break;
if ( V_65 -> V_84 [ V_166 ] + 1 >=
F_38 ( V_65 -> V_83 [ V_166 ] ) )
continue;
if ( V_166 == 0 )
F_40 ( V_65 -> V_83 [ V_166 ] , V_21 ,
V_65 -> V_84 [ V_166 ] + 1 ) ;
else
F_123 ( V_65 -> V_83 [ V_166 ] , V_21 ,
V_65 -> V_84 [ V_166 ] + 1 ) ;
return 0 ;
}
return 1 ;
}
static T_5
int F_124 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
struct V_64 * V_65 ,
struct V_162 * * V_168 ,
T_2 V_27 , T_2 V_36 ,
T_2 V_17 , T_2 V_145 ,
T_2 V_132 , T_2 V_33 , int V_169 )
{
struct V_68 V_21 ;
struct V_66 * V_67 ;
struct V_115 * V_116 ;
struct V_162 * V_163 ;
T_2 V_7 ;
T_2 V_117 ;
unsigned long V_170 ;
unsigned long V_31 ;
int V_133 ;
int type ;
int V_171 ;
int V_29 ;
int V_82 = 0 ;
bool V_172 = F_76 ( V_35 -> V_37 ,
V_120 ) ;
V_21 . V_22 = V_27 ;
V_21 . type = V_77 ;
V_21 . V_33 = V_36 ;
V_171 = F_122 ( V_17 , V_132 ) ;
if ( V_169 ) {
V_133 = F_125 ( V_171 ) ;
V_65 -> V_173 = 1 ;
} else
V_133 = - 1 ;
if ( V_172 && V_132 < V_142 ) {
V_21 . type = V_86 ;
V_21 . V_33 = V_132 ;
}
V_78:
V_29 = F_37 ( V_109 , V_35 , & V_21 , V_65 , V_133 , 1 ) ;
if ( V_29 < 0 ) {
V_82 = V_29 ;
goto V_73;
}
if ( V_29 > 0 && V_172 ) {
V_172 = false ;
if ( V_65 -> V_84 [ 0 ] ) {
V_65 -> V_84 [ 0 ] -- ;
F_40 ( V_65 -> V_83 [ 0 ] , & V_21 ,
V_65 -> V_84 [ 0 ] ) ;
if ( V_21 . V_22 == V_27 &&
V_21 . type == V_77 &&
V_21 . V_33 == V_36 )
V_29 = 0 ;
}
if ( V_29 ) {
V_21 . V_22 = V_27 ;
V_21 . type = V_77 ;
V_21 . V_33 = V_36 ;
F_44 ( V_65 ) ;
goto V_78;
}
}
if ( V_29 && ! V_169 ) {
V_82 = - V_152 ;
goto V_73;
} else if ( F_8 ( V_29 ) ) {
V_82 = - V_174 ;
goto V_73;
}
V_67 = V_65 -> V_83 [ 0 ] ;
V_117 = F_77 ( V_67 , V_65 -> V_84 [ 0 ] ) ;
#ifdef F_81
if ( V_117 < sizeof( * V_116 ) ) {
if ( ! V_169 ) {
V_82 = - V_152 ;
goto V_73;
}
V_29 = F_87 ( V_109 , V_35 , V_65 , V_132 ,
V_133 ) ;
if ( V_29 < 0 ) {
V_82 = V_29 ;
goto V_73;
}
V_67 = V_65 -> V_83 [ 0 ] ;
V_117 = F_77 ( V_67 , V_65 -> V_84 [ 0 ] ) ;
}
#endif
F_30 ( V_117 < sizeof( * V_116 ) ) ;
V_116 = F_78 ( V_67 , V_65 -> V_84 [ 0 ] , struct V_115 ) ;
V_7 = F_80 ( V_67 , V_116 ) ;
V_170 = ( unsigned long ) ( V_116 + 1 ) ;
V_31 = ( unsigned long ) V_116 + V_117 ;
if ( V_7 & V_143 && ! V_172 ) {
V_170 += sizeof( struct V_137 ) ;
F_30 ( V_170 > V_31 ) ;
}
V_82 = - V_152 ;
while ( 1 ) {
if ( V_170 >= V_31 ) {
F_8 ( V_170 > V_31 ) ;
break;
}
V_163 = (struct V_162 * ) V_170 ;
type = F_119 ( V_67 , V_163 ) ;
if ( V_171 < type )
break;
if ( V_171 > type ) {
V_170 += F_125 ( type ) ;
continue;
}
if ( type == V_154 ) {
struct V_149 * V_175 ;
V_175 = (struct V_149 * ) ( & V_163 -> V_33 ) ;
if ( F_103 ( V_67 , V_175 , V_145 ,
V_132 , V_33 ) ) {
V_82 = 0 ;
break;
}
if ( F_99 ( V_67 , V_175 ) <
F_96 ( V_145 , V_132 , V_33 ) )
break;
} else {
T_2 V_176 ;
V_176 = F_126 ( V_67 , V_163 ) ;
if ( V_17 > 0 ) {
if ( V_17 == V_176 ) {
V_82 = 0 ;
break;
}
if ( V_176 < V_17 )
break;
} else {
if ( V_145 == V_176 ) {
V_82 = 0 ;
break;
}
if ( V_176 < V_145 )
break;
}
}
V_170 += F_125 ( type ) ;
}
if ( V_82 == - V_152 && V_169 ) {
if ( V_117 + V_133 >=
F_127 ( V_35 ) ) {
V_82 = - V_177 ;
goto V_73;
}
if ( F_41 ( V_65 , 0 , & V_21 ) == 0 &&
V_21 . V_22 == V_27 &&
V_21 . type < V_178 ) {
V_82 = - V_177 ;
goto V_73;
}
}
* V_168 = (struct V_162 * ) V_170 ;
V_73:
if ( V_169 ) {
V_65 -> V_173 = 0 ;
F_128 ( V_65 , 1 ) ;
}
return V_82 ;
}
static T_5
void F_129 ( struct V_34 * V_35 ,
struct V_64 * V_65 ,
struct V_162 * V_163 ,
T_2 V_17 , T_2 V_145 ,
T_2 V_132 , T_2 V_33 , int V_156 ,
struct V_179 * V_128 )
{
struct V_66 * V_67 ;
struct V_115 * V_116 ;
unsigned long V_170 ;
unsigned long V_31 ;
unsigned long V_180 ;
T_2 V_111 ;
int V_57 ;
int type ;
V_67 = V_65 -> V_83 [ 0 ] ;
V_116 = F_78 ( V_67 , V_65 -> V_84 [ 0 ] , struct V_115 ) ;
V_180 = ( unsigned long ) V_163 - ( unsigned long ) V_116 ;
type = F_122 ( V_17 , V_132 ) ;
V_57 = F_125 ( type ) ;
F_89 ( V_35 , V_65 , V_57 ) ;
V_116 = F_78 ( V_67 , V_65 -> V_84 [ 0 ] , struct V_115 ) ;
V_111 = F_79 ( V_67 , V_116 ) ;
V_111 += V_156 ;
F_90 ( V_67 , V_116 , V_111 ) ;
if ( V_128 )
F_130 ( V_128 , V_67 , V_116 ) ;
V_170 = ( unsigned long ) V_116 + V_180 ;
V_31 = ( unsigned long ) V_116 + F_77 ( V_67 , V_65 -> V_84 [ 0 ] ) ;
if ( V_170 < V_31 - V_57 )
F_131 ( V_67 , V_170 + V_57 , V_170 ,
V_31 - V_57 - V_170 ) ;
V_163 = (struct V_162 * ) V_170 ;
F_132 ( V_67 , V_163 , type ) ;
if ( type == V_154 ) {
struct V_149 * V_175 ;
V_175 = (struct V_149 * ) ( & V_163 -> V_33 ) ;
F_109 ( V_67 , V_175 , V_145 ) ;
F_110 ( V_67 , V_175 , V_132 ) ;
F_111 ( V_67 , V_175 , V_33 ) ;
F_112 ( V_67 , V_175 , V_156 ) ;
} else if ( type == V_153 ) {
struct V_157 * V_181 ;
V_181 = (struct V_157 * ) ( V_163 + 1 ) ;
F_107 ( V_67 , V_181 , V_156 ) ;
F_133 ( V_67 , V_163 , V_17 ) ;
} else if ( type == V_164 ) {
F_133 ( V_67 , V_163 , V_17 ) ;
} else {
F_133 ( V_67 , V_163 , V_145 ) ;
}
F_95 ( V_67 ) ;
}
static int F_134 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
struct V_64 * V_65 ,
struct V_162 * * V_168 ,
T_2 V_27 , T_2 V_36 , T_2 V_17 ,
T_2 V_145 , T_2 V_132 , T_2 V_33 )
{
int V_29 ;
V_29 = F_124 ( V_109 , V_35 , V_65 , V_168 ,
V_27 , V_36 , V_17 ,
V_145 , V_132 , V_33 , 0 ) ;
if ( V_29 != - V_152 )
return V_29 ;
F_44 ( V_65 ) ;
* V_168 = NULL ;
if ( V_132 < V_142 ) {
V_29 = F_120 ( V_109 , V_35 , V_65 , V_27 , V_17 ,
V_145 ) ;
} else {
V_29 = F_104 ( V_109 , V_35 , V_65 , V_27 , V_17 ,
V_145 , V_132 , V_33 ) ;
}
return V_29 ;
}
static T_5
void F_135 ( struct V_34 * V_35 ,
struct V_64 * V_65 ,
struct V_162 * V_163 ,
int V_182 ,
struct V_179 * V_128 ,
int * V_159 )
{
struct V_66 * V_67 ;
struct V_115 * V_116 ;
struct V_149 * V_175 = NULL ;
struct V_157 * V_181 = NULL ;
unsigned long V_170 ;
unsigned long V_31 ;
T_3 V_117 ;
int V_57 ;
int type ;
T_2 V_111 ;
V_67 = V_65 -> V_83 [ 0 ] ;
V_116 = F_78 ( V_67 , V_65 -> V_84 [ 0 ] , struct V_115 ) ;
V_111 = F_79 ( V_67 , V_116 ) ;
F_8 ( V_182 < 0 && V_111 + V_182 <= 0 ) ;
V_111 += V_182 ;
F_90 ( V_67 , V_116 , V_111 ) ;
if ( V_128 )
F_130 ( V_128 , V_67 , V_116 ) ;
type = F_119 ( V_67 , V_163 ) ;
if ( type == V_154 ) {
V_175 = (struct V_149 * ) ( & V_163 -> V_33 ) ;
V_111 = F_113 ( V_67 , V_175 ) ;
} else if ( type == V_153 ) {
V_181 = (struct V_157 * ) ( V_163 + 1 ) ;
V_111 = F_108 ( V_67 , V_181 ) ;
} else {
V_111 = 1 ;
F_30 ( V_182 != - 1 ) ;
}
F_30 ( V_182 < 0 && V_111 < - V_182 ) ;
V_111 += V_182 ;
if ( V_111 > 0 ) {
if ( type == V_154 )
F_112 ( V_67 , V_175 , V_111 ) ;
else
F_107 ( V_67 , V_181 , V_111 ) ;
} else {
* V_159 = 1 ;
V_57 = F_125 ( type ) ;
V_117 = F_77 ( V_67 , V_65 -> V_84 [ 0 ] ) ;
V_170 = ( unsigned long ) V_163 ;
V_31 = ( unsigned long ) V_116 + V_117 ;
if ( V_170 + V_57 < V_31 )
F_131 ( V_67 , V_170 , V_170 + V_57 ,
V_31 - V_170 - V_57 ) ;
V_117 -= V_57 ;
F_136 ( V_35 , V_65 , V_117 , 1 ) ;
}
F_95 ( V_67 ) ;
}
static T_5
int F_137 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
struct V_64 * V_65 ,
T_2 V_27 , T_2 V_36 , T_2 V_17 ,
T_2 V_145 , T_2 V_132 ,
T_2 V_33 , int V_156 ,
struct V_179 * V_128 )
{
struct V_162 * V_163 ;
int V_29 ;
V_29 = F_124 ( V_109 , V_35 , V_65 , & V_163 ,
V_27 , V_36 , V_17 ,
V_145 , V_132 , V_33 , 1 ) ;
if ( V_29 == 0 ) {
F_30 ( V_132 < V_142 ) ;
F_135 ( V_35 , V_65 , V_163 ,
V_156 , V_128 , NULL ) ;
} else if ( V_29 == - V_152 ) {
F_129 ( V_35 , V_65 , V_163 , V_17 ,
V_145 , V_132 , V_33 ,
V_156 , V_128 ) ;
V_29 = 0 ;
}
return V_29 ;
}
static int F_138 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
struct V_64 * V_65 ,
T_2 V_27 , T_2 V_17 , T_2 V_145 ,
T_2 V_132 , T_2 V_33 , int V_156 )
{
int V_29 ;
if ( V_132 < V_142 ) {
F_30 ( V_156 != 1 ) ;
V_29 = F_121 ( V_109 , V_35 , V_65 , V_27 ,
V_17 , V_145 ) ;
} else {
V_29 = F_105 ( V_109 , V_35 , V_65 , V_27 ,
V_17 , V_145 ,
V_132 , V_33 , V_156 ) ;
}
return V_29 ;
}
static int F_139 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
struct V_64 * V_65 ,
struct V_162 * V_163 ,
int V_158 , int V_183 , int * V_159 )
{
int V_29 = 0 ;
F_30 ( ! V_183 && V_158 != 1 ) ;
if ( V_163 ) {
F_135 ( V_35 , V_65 , V_163 ,
- V_158 , NULL , V_159 ) ;
} else if ( V_183 ) {
V_29 = F_114 ( V_109 , V_35 , V_65 , V_158 ,
V_159 ) ;
} else {
* V_159 = 1 ;
V_29 = F_116 ( V_109 , V_35 , V_65 ) ;
}
return V_29 ;
}
static int F_140 ( struct V_184 * V_185 ,
T_2 V_32 , T_2 V_49 )
{
return F_141 ( V_185 , V_32 >> 9 , V_49 >> 9 , V_40 , 0 ) ;
}
static int F_142 ( struct V_34 * V_35 , T_2 V_27 ,
T_2 V_36 , T_2 * V_186 )
{
int V_29 ;
T_2 V_187 = 0 ;
struct V_188 * V_189 = NULL ;
V_29 = F_143 ( V_35 -> V_37 , V_190 ,
V_27 , & V_36 , & V_189 , 0 ) ;
if ( ! V_29 ) {
struct V_191 * V_192 = V_189 -> V_193 ;
int V_43 ;
for ( V_43 = 0 ; V_43 < V_189 -> V_194 ; V_43 ++ , V_192 ++ ) {
if ( ! V_192 -> V_195 -> V_196 )
continue;
V_29 = F_140 ( V_192 -> V_195 -> V_185 ,
V_192 -> V_197 ,
V_192 -> V_198 ) ;
if ( ! V_29 )
V_187 += V_192 -> V_198 ;
else if ( V_29 != - V_199 )
break;
V_29 = 0 ;
}
F_9 ( V_189 ) ;
}
if ( V_186 )
* V_186 = V_187 ;
if ( V_29 == - V_199 )
V_29 = 0 ;
return V_29 ;
}
int F_144 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
T_2 V_27 , T_2 V_36 , T_2 V_17 ,
T_2 V_145 , T_2 V_132 , T_2 V_33 ,
int V_200 )
{
int V_29 ;
struct V_12 * V_37 = V_35 -> V_37 ;
F_30 ( V_132 < V_142 &&
V_145 == V_201 ) ;
if ( V_132 < V_142 ) {
V_29 = F_145 ( V_37 , V_109 , V_27 ,
V_36 ,
V_17 , V_145 , ( int ) V_132 ,
V_202 , NULL , V_200 ) ;
} else {
V_29 = F_146 ( V_37 , V_109 , V_27 ,
V_36 ,
V_17 , V_145 , V_132 , V_33 ,
V_202 , NULL , V_200 ) ;
}
return V_29 ;
}
static int F_147 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
T_2 V_27 , T_2 V_36 ,
T_2 V_17 , T_2 V_145 ,
T_2 V_132 , T_2 V_33 , int V_156 ,
int V_200 ,
struct V_179 * V_128 )
{
struct V_12 * V_37 = V_35 -> V_37 ;
struct V_64 * V_65 ;
struct V_66 * V_67 ;
struct V_115 * V_134 ;
struct V_68 V_21 ;
T_2 V_111 ;
int V_29 ;
enum V_203 type = V_204 ;
V_65 = F_33 () ;
if ( ! V_65 )
return - V_72 ;
if ( ! F_148 ( V_145 ) || ! V_35 -> V_37 -> V_205 )
V_200 = 1 ;
V_65 -> V_76 = 1 ;
V_65 -> V_206 = 1 ;
V_29 = F_137 ( V_109 , V_37 -> V_63 , V_65 ,
V_27 , V_36 , V_17 ,
V_145 , V_132 , V_33 ,
V_156 , V_128 ) ;
if ( ( V_29 < 0 && V_29 != - V_177 ) || ( ! V_29 && V_200 ) )
goto V_73;
if ( ! V_29 && ! V_200 ) {
ASSERT ( V_35 -> V_37 -> V_205 ) ;
V_67 = V_65 -> V_83 [ 0 ] ;
F_40 ( V_67 , & V_21 , V_65 -> V_84 [ 0 ] ) ;
V_134 = F_78 ( V_67 , V_65 -> V_84 [ 0 ] ,
struct V_115 ) ;
if ( F_79 ( V_67 , V_134 ) > ( T_2 ) V_156 )
type = V_207 ;
F_44 ( V_65 ) ;
V_29 = F_149 ( V_109 , V_37 , V_145 ,
V_27 , V_36 , type , 0 ) ;
goto V_73;
}
V_67 = V_65 -> V_83 [ 0 ] ;
F_40 ( V_67 , & V_21 , V_65 -> V_84 [ 0 ] ) ;
V_134 = F_78 ( V_67 , V_65 -> V_84 [ 0 ] , struct V_115 ) ;
V_111 = F_79 ( V_67 , V_134 ) ;
if ( V_111 )
type = V_207 ;
F_90 ( V_67 , V_134 , V_111 + V_156 ) ;
if ( V_128 )
F_130 ( V_128 , V_67 , V_134 ) ;
F_95 ( V_67 ) ;
F_44 ( V_65 ) ;
if ( ! V_200 ) {
V_29 = F_149 ( V_109 , V_37 , V_145 ,
V_27 , V_36 , type , 0 ) ;
if ( V_29 )
goto V_73;
}
V_65 -> V_76 = 1 ;
V_65 -> V_206 = 1 ;
V_29 = F_138 ( V_109 , V_35 -> V_37 -> V_63 ,
V_65 , V_27 , V_17 , V_145 ,
V_132 , V_33 , V_156 ) ;
if ( V_29 )
F_150 ( V_109 , V_35 , V_29 ) ;
V_73:
F_50 ( V_65 ) ;
return V_29 ;
}
static int F_151 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
struct V_208 * V_127 ,
struct V_179 * V_128 ,
int V_209 )
{
int V_29 = 0 ;
struct V_210 * V_150 ;
struct V_68 V_211 ;
T_2 V_17 = 0 ;
T_2 V_212 = 0 ;
T_2 V_7 = 0 ;
V_211 . V_22 = V_127 -> V_27 ;
V_211 . V_33 = V_127 -> V_36 ;
V_211 . type = V_77 ;
V_150 = F_152 ( V_127 ) ;
F_153 ( V_127 , V_150 , V_127 -> V_213 ) ;
if ( V_127 -> type == V_153 )
V_17 = V_150 -> V_17 ;
V_212 = V_150 -> V_35 ;
if ( V_127 -> V_213 == V_202 && V_209 ) {
if ( V_128 )
V_7 |= V_128 -> V_130 ;
V_29 = F_154 ( V_109 , V_35 ,
V_17 , V_212 , V_7 ,
V_150 -> V_22 , V_150 -> V_33 ,
& V_211 , V_127 -> V_131 ) ;
} else if ( V_127 -> V_213 == V_202 ) {
V_29 = F_147 ( V_109 , V_35 , V_127 -> V_27 ,
V_127 -> V_36 , V_17 ,
V_212 , V_150 -> V_22 ,
V_150 -> V_33 , V_127 -> V_131 ,
V_127 -> V_200 , V_128 ) ;
} else if ( V_127 -> V_213 == V_214 ) {
V_29 = F_155 ( V_109 , V_35 , V_127 -> V_27 ,
V_127 -> V_36 , V_17 ,
V_212 , V_150 -> V_22 ,
V_150 -> V_33 , V_127 -> V_131 ,
V_128 , V_127 -> V_200 ) ;
} else {
F_83 () ;
}
return V_29 ;
}
static void F_130 ( struct V_179 * V_128 ,
struct V_66 * V_67 ,
struct V_115 * V_116 )
{
T_2 V_7 = F_80 ( V_67 , V_116 ) ;
if ( V_128 -> V_129 ) {
V_7 |= V_128 -> V_130 ;
F_92 ( V_67 , V_116 , V_7 ) ;
}
if ( V_128 -> V_215 ) {
struct V_137 * V_138 ;
F_30 ( ! ( V_7 & V_143 ) ) ;
V_138 = (struct V_137 * ) ( V_116 + 1 ) ;
F_156 ( V_67 , V_138 , & V_128 -> V_21 ) ;
}
}
static int F_157 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
struct V_208 * V_127 ,
struct V_179 * V_128 )
{
struct V_68 V_21 ;
struct V_64 * V_65 ;
struct V_115 * V_116 ;
struct V_66 * V_67 ;
T_3 V_117 ;
int V_29 ;
int V_82 = 0 ;
int V_110 = ! V_128 -> V_183 ;
if ( V_109 -> V_216 )
return 0 ;
if ( V_110 && ! F_76 ( V_35 -> V_37 , V_120 ) )
V_110 = 0 ;
V_65 = F_33 () ;
if ( ! V_65 )
return - V_72 ;
V_21 . V_22 = V_127 -> V_27 ;
if ( V_110 ) {
V_21 . type = V_86 ;
V_21 . V_33 = V_128 -> V_166 ;
} else {
V_21 . type = V_77 ;
V_21 . V_33 = V_127 -> V_36 ;
}
V_78:
V_65 -> V_76 = 1 ;
V_65 -> V_206 = 1 ;
V_29 = F_37 ( V_109 , V_35 -> V_37 -> V_63 , & V_21 ,
V_65 , 0 , 1 ) ;
if ( V_29 < 0 ) {
V_82 = V_29 ;
goto V_73;
}
if ( V_29 > 0 ) {
if ( V_110 ) {
if ( V_65 -> V_84 [ 0 ] > 0 ) {
V_65 -> V_84 [ 0 ] -- ;
F_40 ( V_65 -> V_83 [ 0 ] , & V_21 ,
V_65 -> V_84 [ 0 ] ) ;
if ( V_21 . V_22 == V_127 -> V_27 &&
V_21 . type == V_77 &&
V_21 . V_33 == V_127 -> V_36 )
V_29 = 0 ;
}
if ( V_29 > 0 ) {
F_44 ( V_65 ) ;
V_110 = 0 ;
V_21 . V_22 = V_127 -> V_27 ;
V_21 . V_33 = V_127 -> V_36 ;
V_21 . type = V_77 ;
goto V_78;
}
} else {
V_82 = - V_174 ;
goto V_73;
}
}
V_67 = V_65 -> V_83 [ 0 ] ;
V_117 = F_77 ( V_67 , V_65 -> V_84 [ 0 ] ) ;
#ifdef F_81
if ( V_117 < sizeof( * V_116 ) ) {
V_29 = F_87 ( V_109 , V_35 -> V_37 -> V_63 ,
V_65 , ( T_2 ) - 1 , 0 ) ;
if ( V_29 < 0 ) {
V_82 = V_29 ;
goto V_73;
}
V_67 = V_65 -> V_83 [ 0 ] ;
V_117 = F_77 ( V_67 , V_65 -> V_84 [ 0 ] ) ;
}
#endif
F_30 ( V_117 < sizeof( * V_116 ) ) ;
V_116 = F_78 ( V_67 , V_65 -> V_84 [ 0 ] , struct V_115 ) ;
F_130 ( V_128 , V_67 , V_116 ) ;
F_95 ( V_67 ) ;
V_73:
F_50 ( V_65 ) ;
return V_82 ;
}
static int F_158 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
struct V_208 * V_127 ,
struct V_179 * V_128 ,
int V_209 )
{
int V_29 = 0 ;
struct V_217 * V_150 ;
struct V_68 V_211 ;
T_2 V_17 = 0 ;
T_2 V_212 = 0 ;
bool V_172 = F_76 ( V_35 -> V_37 ,
V_120 ) ;
V_150 = F_159 ( V_127 ) ;
F_160 ( V_127 , V_150 , V_127 -> V_213 ) ;
if ( V_127 -> type == V_164 )
V_17 = V_150 -> V_17 ;
V_212 = V_150 -> V_35 ;
V_211 . V_22 = V_127 -> V_27 ;
if ( V_172 ) {
V_211 . V_33 = V_150 -> V_166 ;
V_211 . type = V_86 ;
} else {
V_211 . V_33 = V_127 -> V_36 ;
V_211 . type = V_77 ;
}
F_30 ( V_127 -> V_131 != 1 ) ;
if ( V_127 -> V_213 == V_202 && V_209 ) {
F_30 ( ! V_128 || ! V_128 -> V_129 ) ;
V_29 = F_161 ( V_109 , V_35 ,
V_17 , V_212 ,
V_128 -> V_130 ,
& V_128 -> V_21 ,
V_150 -> V_166 , & V_211 ,
V_127 -> V_200 ) ;
} else if ( V_127 -> V_213 == V_202 ) {
V_29 = F_147 ( V_109 , V_35 , V_127 -> V_27 ,
V_127 -> V_36 , V_17 , V_212 ,
V_150 -> V_166 , 0 , 1 , V_127 -> V_200 ,
V_128 ) ;
} else if ( V_127 -> V_213 == V_214 ) {
V_29 = F_155 ( V_109 , V_35 , V_127 -> V_27 ,
V_127 -> V_36 , V_17 , V_212 ,
V_150 -> V_166 , 0 , 1 , V_128 ,
V_127 -> V_200 ) ;
} else {
F_83 () ;
}
return V_29 ;
}
static int F_162 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
struct V_208 * V_127 ,
struct V_179 * V_128 ,
int V_209 )
{
int V_29 = 0 ;
if ( V_109 -> V_216 ) {
if ( V_209 )
F_163 ( V_35 , V_127 -> V_27 ,
V_127 -> V_36 , 1 ) ;
return 0 ;
}
if ( F_164 ( V_127 ) ) {
struct V_112 * V_103 ;
F_30 ( V_128 ) ;
V_103 = F_165 ( V_127 ) ;
F_166 ( V_127 , V_103 , V_127 -> V_213 ) ;
if ( V_209 ) {
F_163 ( V_35 , V_127 -> V_27 ,
V_127 -> V_36 , 1 ) ;
if ( V_103 -> V_183 ) {
V_29 = F_167 ( V_109 , V_35 ,
V_127 -> V_27 ,
V_127 -> V_36 ) ;
}
}
return V_29 ;
}
if ( V_127 -> type == V_165 ||
V_127 -> type == V_164 )
V_29 = F_158 ( V_109 , V_35 , V_127 , V_128 ,
V_209 ) ;
else if ( V_127 -> type == V_154 ||
V_127 -> type == V_153 )
V_29 = F_151 ( V_109 , V_35 , V_127 , V_128 ,
V_209 ) ;
else
F_83 () ;
return V_29 ;
}
T_1 int F_168 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
unsigned long V_44 )
{
struct V_113 * V_114 ;
struct V_208 * V_150 ;
struct V_112 * V_218 = NULL ;
struct V_179 * V_128 ;
struct V_12 * V_37 = V_35 -> V_37 ;
T_6 V_32 = F_169 () ;
int V_29 ;
unsigned long V_8 = 0 ;
unsigned long V_219 = 0 ;
int V_220 = 0 ;
V_114 = & V_109 -> V_126 -> V_114 ;
while ( 1 ) {
if ( ! V_218 ) {
if ( V_8 >= V_44 )
break;
F_11 ( & V_114 -> V_52 ) ;
V_218 = F_170 ( V_109 ) ;
if ( ! V_218 ) {
F_13 ( & V_114 -> V_52 ) ;
break;
}
V_29 = F_171 ( V_109 , V_218 ) ;
F_13 ( & V_114 -> V_52 ) ;
if ( V_29 == - V_177 ) {
V_218 = NULL ;
V_8 ++ ;
continue;
}
}
F_11 ( & V_218 -> V_52 ) ;
F_172 ( V_109 , V_37 , V_114 ,
V_218 ) ;
V_150 = F_173 ( V_218 ) ;
if ( V_150 && V_150 -> V_221 &&
F_174 ( V_37 , V_114 , V_150 -> V_221 ) ) {
F_13 ( & V_218 -> V_52 ) ;
F_175 ( V_218 ) ;
F_11 ( & V_114 -> V_52 ) ;
V_218 -> V_222 = 0 ;
V_114 -> V_223 ++ ;
F_13 ( & V_114 -> V_52 ) ;
V_218 = NULL ;
F_47 () ;
V_8 ++ ;
continue;
}
V_220 = V_218 -> V_220 ;
V_218 -> V_220 = 0 ;
V_128 = V_218 -> V_128 ;
V_218 -> V_128 = NULL ;
if ( ! V_150 ) {
V_150 = & V_218 -> V_127 ;
if ( V_128 && V_220 ) {
F_176 ( V_128 ) ;
V_128 = NULL ;
}
if ( V_128 ) {
F_13 ( & V_218 -> V_52 ) ;
V_29 = F_157 ( V_109 , V_35 ,
V_150 , V_128 ) ;
F_176 ( V_128 ) ;
if ( V_29 ) {
if ( V_220 )
V_218 -> V_220 = 1 ;
V_218 -> V_222 = 0 ;
F_177 ( V_37 , L_1 , V_29 ) ;
F_175 ( V_218 ) ;
return V_29 ;
}
continue;
}
F_13 ( & V_218 -> V_52 ) ;
F_11 ( & V_114 -> V_52 ) ;
F_11 ( & V_218 -> V_52 ) ;
if ( F_178 ( & V_218 -> V_212 ) ||
V_218 -> V_128 ) {
F_13 ( & V_218 -> V_52 ) ;
F_13 ( & V_114 -> V_52 ) ;
continue;
}
V_150 -> V_224 = 0 ;
V_114 -> V_225 -- ;
F_179 ( & V_218 -> V_226 ,
& V_114 -> V_227 ) ;
F_13 ( & V_114 -> V_52 ) ;
} else {
V_219 ++ ;
V_150 -> V_224 = 0 ;
F_179 ( & V_150 -> V_15 , & V_218 -> V_212 ) ;
}
F_180 ( & V_114 -> V_228 ) ;
if ( ! F_164 ( V_150 ) ) {
switch ( V_150 -> V_213 ) {
case V_202 :
case V_229 :
V_218 -> V_127 . V_131 -= V_150 -> V_131 ;
break;
case V_214 :
V_218 -> V_127 . V_131 += V_150 -> V_131 ;
break;
default:
F_8 ( 1 ) ;
}
}
F_13 ( & V_218 -> V_52 ) ;
V_29 = F_162 ( V_109 , V_35 , V_150 , V_128 ,
V_220 ) ;
F_176 ( V_128 ) ;
if ( V_29 ) {
V_218 -> V_222 = 0 ;
F_175 ( V_218 ) ;
F_86 ( V_150 ) ;
F_177 ( V_37 , L_2 , V_29 ) ;
return V_29 ;
}
if ( F_164 ( V_150 ) ) {
F_175 ( V_218 ) ;
V_218 = NULL ;
}
F_86 ( V_150 ) ;
V_8 ++ ;
F_47 () ;
}
if ( V_219 > 0 ) {
T_2 V_230 = F_181 ( F_182 ( F_169 () , V_32 ) ) ;
T_2 V_231 ;
F_11 ( & V_114 -> V_52 ) ;
V_231 = V_37 -> V_232 * 3 + V_230 ;
V_231 = F_183 ( V_231 , 4 ) ;
V_37 -> V_232 = V_231 ;
F_13 ( & V_114 -> V_52 ) ;
}
return 0 ;
}
static T_2 F_184 ( struct V_233 * V_35 )
{
struct V_15 * V_30 = V_35 -> V_15 ;
struct V_208 * V_234 ;
int V_235 = 1 ;
T_2 V_236 ;
T_2 V_237 = 0 , V_70 = 0 ;
V_30 = F_178 ( V_35 ) ;
if ( V_30 ) {
V_234 = F_12 ( V_30 , struct V_208 , V_15 ) ;
V_237 = V_234 -> V_27 ;
}
V_30 = F_185 ( V_35 ) ;
if ( V_30 ) {
V_234 = F_12 ( V_30 , struct V_208 , V_15 ) ;
V_70 = V_234 -> V_27 ;
}
V_30 = V_35 -> V_15 ;
while ( V_30 ) {
V_234 = F_12 ( V_30 , struct V_208 , V_15 ) ;
F_8 ( ! V_234 -> V_224 ) ;
V_236 = V_234 -> V_27 ;
if ( V_235 )
V_30 = V_30 -> V_23 ;
else
V_30 = V_30 -> V_24 ;
V_235 = 1 - V_235 ;
}
return V_236 ;
}
static inline T_2 F_186 ( struct V_34 * V_35 , T_2 V_238 )
{
T_2 V_36 ;
V_36 = V_238 * ( sizeof( struct V_115 ) +
sizeof( struct V_162 ) ) ;
if ( ! F_76 ( V_35 -> V_37 , V_120 ) )
V_36 += V_238 * sizeof( struct V_137 ) ;
return F_183 ( V_36 , F_187 ( V_35 ) ) ;
}
int F_188 ( struct V_108 * V_109 ,
struct V_34 * V_35 )
{
struct V_239 * V_240 ;
T_2 V_225 = V_109 -> V_126 -> V_114 . V_223 ;
T_2 V_36 ;
int V_29 = 0 ;
V_36 = F_189 ( V_35 , 1 ) ;
V_225 = F_186 ( V_35 , V_225 ) ;
if ( V_225 > 1 )
V_36 += ( V_225 - 1 ) * V_35 -> V_88 ;
V_36 <<= 1 ;
V_240 = & V_35 -> V_37 -> V_241 ;
if ( V_240 -> V_104 -> V_107 )
V_36 <<= 1 ;
F_11 ( & V_240 -> V_52 ) ;
if ( V_240 -> V_10 <= V_36 )
V_29 = 1 ;
F_13 ( & V_240 -> V_52 ) ;
return V_29 ;
}
int F_190 ( struct V_108 * V_109 ,
struct V_34 * V_35 )
{
struct V_12 * V_37 = V_35 -> V_37 ;
T_2 V_228 =
F_191 ( & V_109 -> V_126 -> V_114 . V_228 ) ;
T_2 V_242 ;
T_2 V_243 ;
F_2 () ;
V_242 = V_37 -> V_232 ;
V_243 = V_228 * V_242 ;
if ( V_228 * V_242 >= V_244 )
return 1 ;
if ( V_243 >= V_244 / 2 )
return 2 ;
return F_188 ( V_109 , V_35 ) ;
}
static void F_192 ( struct V_61 * V_62 )
{
struct V_245 * V_246 ;
struct V_108 * V_109 ;
int V_29 ;
V_246 = F_32 ( V_62 , struct V_245 , V_62 ) ;
V_109 = F_193 ( V_246 -> V_35 ) ;
if ( F_194 ( V_109 ) ) {
V_246 -> error = F_195 ( V_109 ) ;
goto V_247;
}
V_109 -> V_248 = true ;
V_29 = F_196 ( V_109 , V_246 -> V_35 , V_246 -> V_8 ) ;
if ( V_29 )
V_246 -> error = V_29 ;
V_29 = F_197 ( V_109 , V_246 -> V_35 ) ;
if ( V_29 && ! V_246 -> error )
V_246 -> error = V_29 ;
V_247:
if ( V_246 -> V_248 )
F_198 ( & V_246 -> V_89 ) ;
else
F_9 ( V_246 ) ;
}
int F_199 ( struct V_34 * V_35 ,
unsigned long V_8 , int V_89 )
{
struct V_245 * V_246 ;
int V_29 ;
V_246 = F_200 ( sizeof( * V_246 ) , V_40 ) ;
if ( ! V_246 )
return - V_72 ;
V_246 -> V_35 = V_35 -> V_37 -> V_87 ;
V_246 -> V_8 = V_8 ;
V_246 -> error = 0 ;
if ( V_89 )
V_246 -> V_248 = 1 ;
else
V_246 -> V_248 = 0 ;
F_201 ( & V_246 -> V_89 ) ;
F_58 ( & V_246 -> V_62 , V_249 ,
F_192 , NULL , NULL ) ;
F_66 ( V_35 -> V_37 -> V_250 , & V_246 -> V_62 ) ;
if ( V_89 ) {
F_202 ( & V_246 -> V_89 ) ;
V_29 = V_246 -> error ;
F_9 ( V_246 ) ;
return V_29 ;
}
return 0 ;
}
int F_196 ( struct V_108 * V_109 ,
struct V_34 * V_35 , unsigned long V_8 )
{
struct V_15 * V_127 ;
struct V_113 * V_114 ;
struct V_112 * V_103 ;
int V_29 ;
int V_251 = V_8 == ( unsigned long ) - 1 ;
int V_252 = 0 ;
if ( V_109 -> V_216 )
return 0 ;
if ( V_35 == V_35 -> V_37 -> V_63 )
V_35 = V_35 -> V_37 -> V_87 ;
V_114 = & V_109 -> V_126 -> V_114 ;
if ( V_8 == 0 ) {
V_8 = F_191 ( & V_114 -> V_228 ) * 2 ;
V_252 = 1 ;
}
V_78:
#ifdef F_203
V_114 -> V_253 = F_184 ( & V_114 -> V_35 ) ;
#endif
V_29 = F_168 ( V_109 , V_35 , V_8 ) ;
if ( V_29 < 0 ) {
F_150 ( V_109 , V_35 , V_29 ) ;
return V_29 ;
}
if ( V_251 ) {
if ( ! F_204 ( & V_109 -> V_254 ) )
F_205 ( V_109 , V_35 ) ;
F_11 ( & V_114 -> V_52 ) ;
V_127 = F_178 ( & V_114 -> V_227 ) ;
if ( ! V_127 ) {
F_13 ( & V_114 -> V_52 ) ;
goto V_73;
}
V_8 = ( unsigned long ) - 1 ;
while ( V_127 ) {
V_103 = F_12 ( V_127 , struct V_112 ,
V_226 ) ;
if ( F_164 ( & V_103 -> V_127 ) ) {
struct V_208 * V_150 ;
V_150 = & V_103 -> V_127 ;
F_5 ( & V_150 -> V_111 ) ;
F_13 ( & V_114 -> V_52 ) ;
F_35 ( & V_103 -> V_79 ) ;
F_46 ( & V_103 -> V_79 ) ;
F_86 ( V_150 ) ;
F_47 () ;
goto V_78;
} else {
F_8 ( 1 ) ;
}
V_127 = F_206 ( V_127 ) ;
}
F_13 ( & V_114 -> V_52 ) ;
F_47 () ;
goto V_78;
}
V_73:
V_29 = F_207 ( V_109 , V_35 -> V_37 ) ;
if ( V_29 )
return V_29 ;
F_208 ( V_109 ) ;
return 0 ;
}
int F_209 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
T_2 V_27 , T_2 V_36 , T_2 V_7 ,
int V_166 , int V_183 )
{
struct V_179 * V_128 ;
int V_29 ;
V_128 = F_210 () ;
if ( ! V_128 )
return - V_72 ;
V_128 -> V_130 = V_7 ;
V_128 -> V_129 = 1 ;
V_128 -> V_215 = 0 ;
V_128 -> V_183 = V_183 ? 1 : 0 ;
V_128 -> V_166 = V_166 ;
V_29 = F_211 ( V_35 -> V_37 , V_109 , V_27 ,
V_36 , V_128 ) ;
if ( V_29 )
F_176 ( V_128 ) ;
return V_29 ;
}
static T_1 int F_212 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
struct V_64 * V_65 ,
T_2 V_22 , T_2 V_33 , T_2 V_27 )
{
struct V_112 * V_103 ;
struct V_208 * V_150 ;
struct V_210 * V_255 ;
struct V_113 * V_114 ;
struct V_15 * V_127 ;
int V_29 = 0 ;
V_114 = & V_109 -> V_126 -> V_114 ;
F_11 ( & V_114 -> V_52 ) ;
V_103 = F_84 ( V_109 , V_27 ) ;
if ( ! V_103 ) {
F_13 ( & V_114 -> V_52 ) ;
return 0 ;
}
if ( ! F_85 ( & V_103 -> V_79 ) ) {
F_5 ( & V_103 -> V_127 . V_111 ) ;
F_13 ( & V_114 -> V_52 ) ;
F_44 ( V_65 ) ;
F_35 ( & V_103 -> V_79 ) ;
F_46 ( & V_103 -> V_79 ) ;
F_86 ( & V_103 -> V_127 ) ;
return - V_177 ;
}
F_13 ( & V_114 -> V_52 ) ;
F_11 ( & V_103 -> V_52 ) ;
V_127 = F_178 ( & V_103 -> V_212 ) ;
while ( V_127 ) {
V_150 = F_12 ( V_127 , struct V_208 , V_15 ) ;
V_127 = F_206 ( V_127 ) ;
if ( V_150 -> type != V_154 ) {
V_29 = 1 ;
break;
}
V_255 = F_152 ( V_150 ) ;
if ( V_255 -> V_35 != V_35 -> V_256 . V_22 ||
V_255 -> V_22 != V_22 ||
V_255 -> V_33 != V_33 ) {
V_29 = 1 ;
break;
}
}
F_13 ( & V_103 -> V_52 ) ;
F_46 ( & V_103 -> V_79 ) ;
return V_29 ;
}
static T_1 int F_213 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
struct V_64 * V_65 ,
T_2 V_22 , T_2 V_33 , T_2 V_27 )
{
struct V_34 * V_63 = V_35 -> V_37 -> V_63 ;
struct V_66 * V_67 ;
struct V_149 * V_150 ;
struct V_162 * V_163 ;
struct V_115 * V_116 ;
struct V_68 V_21 ;
T_3 V_117 ;
int V_29 ;
V_21 . V_22 = V_27 ;
V_21 . V_33 = ( T_2 ) - 1 ;
V_21 . type = V_77 ;
V_29 = F_37 ( NULL , V_63 , & V_21 , V_65 , 0 , 0 ) ;
if ( V_29 < 0 )
goto V_73;
F_30 ( V_29 == 0 ) ;
V_29 = - V_152 ;
if ( V_65 -> V_84 [ 0 ] == 0 )
goto V_73;
V_65 -> V_84 [ 0 ] -- ;
V_67 = V_65 -> V_83 [ 0 ] ;
F_40 ( V_67 , & V_21 , V_65 -> V_84 [ 0 ] ) ;
if ( V_21 . V_22 != V_27 || V_21 . type != V_77 )
goto V_73;
V_29 = 1 ;
V_117 = F_77 ( V_67 , V_65 -> V_84 [ 0 ] ) ;
#ifdef F_81
if ( V_117 < sizeof( * V_116 ) ) {
F_8 ( V_117 != sizeof( struct V_123 ) ) ;
goto V_73;
}
#endif
V_116 = F_78 ( V_67 , V_65 -> V_84 [ 0 ] , struct V_115 ) ;
if ( V_117 != sizeof( * V_116 ) +
F_125 ( V_154 ) )
goto V_73;
if ( F_214 ( V_67 , V_116 ) <=
F_215 ( & V_35 -> V_257 ) )
goto V_73;
V_163 = (struct V_162 * ) ( V_116 + 1 ) ;
if ( F_119 ( V_67 , V_163 ) !=
V_154 )
goto V_73;
V_150 = (struct V_149 * ) ( & V_163 -> V_33 ) ;
if ( F_79 ( V_67 , V_116 ) !=
F_113 ( V_67 , V_150 ) ||
F_100 ( V_67 , V_150 ) !=
V_35 -> V_256 . V_22 ||
F_101 ( V_67 , V_150 ) != V_22 ||
F_102 ( V_67 , V_150 ) != V_33 )
goto V_73;
V_29 = 0 ;
V_73:
return V_29 ;
}
int F_216 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
T_2 V_22 , T_2 V_33 , T_2 V_27 )
{
struct V_64 * V_65 ;
int V_29 ;
int V_258 ;
V_65 = F_33 () ;
if ( ! V_65 )
return - V_152 ;
do {
V_29 = F_213 ( V_109 , V_35 , V_65 , V_22 ,
V_33 , V_27 ) ;
if ( V_29 && V_29 != - V_152 )
goto V_73;
V_258 = F_212 ( V_109 , V_35 , V_65 , V_22 ,
V_33 , V_27 ) ;
} while ( V_258 == - V_177 );
if ( V_258 && V_258 != - V_152 ) {
V_29 = V_258 ;
goto V_73;
}
if ( V_29 != - V_152 || V_258 != - V_152 )
V_29 = 0 ;
V_73:
F_50 ( V_65 ) ;
if ( V_35 -> V_256 . V_22 == V_259 )
F_8 ( V_29 > 0 ) ;
return V_29 ;
}
static int F_217 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
struct V_66 * V_260 ,
int V_261 , int V_262 )
{
T_2 V_27 ;
T_2 V_36 ;
T_2 V_17 ;
T_2 V_212 ;
T_3 V_71 ;
struct V_68 V_21 ;
struct V_263 * V_264 ;
int V_43 ;
int V_166 ;
int V_29 = 0 ;
int (* F_218)( struct V_108 * , struct V_34 * ,
T_2 , T_2 , T_2 , T_2 , T_2 , T_2 , int );
if ( F_219 ( V_35 ) )
return 0 ;
V_212 = F_220 ( V_260 ) ;
V_71 = F_38 ( V_260 ) ;
V_166 = F_221 ( V_260 ) ;
if ( ! F_222 ( V_265 , & V_35 -> V_266 ) && V_166 == 0 )
return 0 ;
if ( V_262 )
F_218 = F_144 ;
else
F_218 = V_267 ;
if ( V_261 )
V_17 = V_260 -> V_32 ;
else
V_17 = 0 ;
for ( V_43 = 0 ; V_43 < V_71 ; V_43 ++ ) {
if ( V_166 == 0 ) {
F_40 ( V_260 , & V_21 , V_43 ) ;
if ( V_21 . type != V_268 )
continue;
V_264 = F_78 ( V_260 , V_43 ,
struct V_263 ) ;
if ( F_223 ( V_260 , V_264 ) ==
V_269 )
continue;
V_27 = F_224 ( V_260 , V_264 ) ;
if ( V_27 == 0 )
continue;
V_36 = F_225 ( V_260 , V_264 ) ;
V_21 . V_33 -= F_226 ( V_260 , V_264 ) ;
V_29 = F_218 ( V_109 , V_35 , V_27 , V_36 ,
V_17 , V_212 , V_21 . V_22 ,
V_21 . V_33 , 1 ) ;
if ( V_29 )
goto V_155;
} else {
V_27 = F_227 ( V_260 , V_43 ) ;
V_36 = V_35 -> V_88 ;
V_29 = F_218 ( V_109 , V_35 , V_27 , V_36 ,
V_17 , V_212 , V_166 - 1 , 0 ,
1 ) ;
if ( V_29 )
goto V_155;
}
}
return 0 ;
V_155:
return V_29 ;
}
int F_228 ( struct V_108 * V_109 , struct V_34 * V_35 ,
struct V_66 * V_260 , int V_261 )
{
return F_217 ( V_109 , V_35 , V_260 , V_261 , 1 ) ;
}
int F_229 ( struct V_108 * V_109 , struct V_34 * V_35 ,
struct V_66 * V_260 , int V_261 )
{
return F_217 ( V_109 , V_35 , V_260 , V_261 , 0 ) ;
}
static int F_230 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
struct V_64 * V_65 ,
struct V_1 * V_2 )
{
int V_29 ;
struct V_34 * V_63 = V_35 -> V_37 -> V_63 ;
unsigned long V_138 ;
struct V_66 * V_67 ;
V_29 = F_37 ( V_109 , V_63 , & V_2 -> V_21 , V_65 , 0 , 1 ) ;
if ( V_29 < 0 )
goto V_155;
F_30 ( V_29 ) ;
V_67 = V_65 -> V_83 [ 0 ] ;
V_138 = F_231 ( V_67 , V_65 -> V_84 [ 0 ] ) ;
F_232 ( V_67 , & V_2 -> V_134 , V_138 , sizeof( V_2 -> V_134 ) ) ;
F_95 ( V_67 ) ;
F_44 ( V_65 ) ;
V_155:
if ( V_29 ) {
F_150 ( V_109 , V_35 , V_29 ) ;
return V_29 ;
}
return 0 ;
}
static struct V_1 *
F_233 ( struct V_34 * V_35 ,
struct V_1 * V_2 )
{
struct V_15 * V_127 ;
F_11 ( & V_35 -> V_37 -> V_18 ) ;
V_127 = F_206 ( & V_2 -> V_20 ) ;
F_6 ( V_2 ) ;
if ( V_127 ) {
V_2 = F_12 ( V_127 , struct V_1 ,
V_20 ) ;
F_4 ( V_2 ) ;
} else
V_2 = NULL ;
F_13 ( & V_35 -> V_37 -> V_18 ) ;
return V_2 ;
}
static int F_234 ( struct V_1 * V_14 ,
struct V_108 * V_109 ,
struct V_64 * V_65 )
{
struct V_34 * V_35 = V_14 -> V_37 -> V_87 ;
struct V_270 * V_270 = NULL ;
T_2 V_271 = 0 ;
int V_272 = V_273 ;
int V_274 = 0 ;
int V_275 = 0 ;
int V_29 = 0 ;
if ( V_14 -> V_21 . V_33 < ( 100 * 1024 * 1024 ) ) {
F_11 ( & V_14 -> V_52 ) ;
V_14 -> V_276 = V_277 ;
F_13 ( & V_14 -> V_52 ) ;
return 0 ;
}
V_78:
V_270 = F_235 ( V_35 , V_14 , V_65 ) ;
if ( F_194 ( V_270 ) && F_195 ( V_270 ) != - V_152 ) {
V_29 = F_195 ( V_270 ) ;
F_44 ( V_65 ) ;
goto V_73;
}
if ( F_194 ( V_270 ) ) {
F_30 ( V_275 ) ;
V_275 ++ ;
if ( V_14 -> V_278 )
goto V_122;
V_29 = F_236 ( V_35 , V_109 , V_14 , V_65 ) ;
if ( V_29 )
goto V_122;
goto V_78;
}
if ( V_14 -> V_279 == V_109 -> V_280 &&
F_237 ( V_270 ) ) {
V_272 = V_281 ;
goto V_282;
}
F_238 ( V_270 ) -> V_283 = 0 ;
V_29 = F_239 ( V_109 , V_35 , V_270 ) ;
F_8 ( V_29 ) ;
if ( F_237 ( V_270 ) > 0 ) {
V_29 = F_240 ( V_35 ,
& V_35 -> V_37 -> V_241 ) ;
if ( V_29 )
goto V_282;
V_29 = F_241 ( V_35 , V_109 , V_270 ) ;
if ( V_29 )
goto V_282;
}
F_11 ( & V_14 -> V_52 ) ;
if ( V_14 -> V_3 != V_4 ||
! F_242 ( V_35 , V_284 ) ||
V_14 -> V_285 ) {
V_272 = V_277 ;
F_13 ( & V_14 -> V_52 ) ;
goto V_282;
}
F_13 ( & V_14 -> V_52 ) ;
V_274 = ( int ) F_183 ( V_14 -> V_21 . V_33 , 256 * 1024 * 1024 ) ;
if ( ! V_274 )
V_274 = 1 ;
V_274 *= 16 ;
V_274 *= V_286 ;
V_29 = F_243 ( V_270 , V_274 ) ;
if ( V_29 )
goto V_282;
V_29 = F_244 ( V_270 , V_109 , 0 , 0 , V_274 ,
V_274 , V_274 ,
& V_271 ) ;
if ( ! V_29 )
V_272 = V_281 ;
F_245 ( V_270 , V_274 ) ;
V_282:
F_246 ( V_270 ) ;
V_122:
F_44 ( V_65 ) ;
V_73:
F_11 ( & V_14 -> V_52 ) ;
if ( ! V_29 && V_272 == V_281 )
V_14 -> V_279 = V_109 -> V_280 ;
V_14 -> V_276 = V_272 ;
F_13 ( & V_14 -> V_52 ) ;
return V_29 ;
}
int F_247 ( struct V_108 * V_109 ,
struct V_34 * V_35 )
{
struct V_1 * V_2 ;
int V_82 = 0 ;
struct V_64 * V_65 ;
T_2 V_70 = 0 ;
V_65 = F_33 () ;
if ( ! V_65 )
return - V_72 ;
V_78:
while ( 1 ) {
V_2 = F_67 ( V_35 -> V_37 , V_70 ) ;
while ( V_2 ) {
if ( V_2 -> V_276 == V_287 )
break;
V_2 = F_233 ( V_35 , V_2 ) ;
}
if ( ! V_2 ) {
if ( V_70 == 0 )
break;
V_70 = 0 ;
continue;
}
V_82 = F_234 ( V_2 , V_109 , V_65 ) ;
V_70 = V_2 -> V_21 . V_22 + V_2 -> V_21 . V_33 ;
F_6 ( V_2 ) ;
}
while ( 1 ) {
if ( V_70 == 0 ) {
V_82 = F_196 ( V_109 , V_35 ,
( unsigned long ) - 1 ) ;
if ( V_82 )
goto V_73;
}
V_2 = F_67 ( V_35 -> V_37 , V_70 ) ;
while ( V_2 ) {
if ( V_2 -> V_276 == V_287 ) {
F_6 ( V_2 ) ;
goto V_78;
}
if ( V_2 -> V_288 )
break;
V_2 = F_233 ( V_35 , V_2 ) ;
}
if ( ! V_2 ) {
if ( V_70 == 0 )
break;
V_70 = 0 ;
continue;
}
if ( V_2 -> V_276 == V_281 )
V_2 -> V_276 = V_289 ;
V_2 -> V_288 = 0 ;
V_70 = V_2 -> V_21 . V_22 + V_2 -> V_21 . V_33 ;
V_82 = F_230 ( V_109 , V_35 , V_65 , V_2 ) ;
F_6 ( V_2 ) ;
if ( V_82 )
goto V_73;
}
while ( 1 ) {
if ( V_70 == 0 ) {
V_82 = F_196 ( V_109 , V_35 ,
( unsigned long ) - 1 ) ;
if ( V_82 )
goto V_73;
}
V_2 = F_67 ( V_35 -> V_37 , V_70 ) ;
while ( V_2 ) {
if ( V_2 -> V_288 ) {
F_6 ( V_2 ) ;
goto V_78;
}
if ( V_2 -> V_276 == V_289 )
break;
V_2 = F_233 ( V_35 , V_2 ) ;
}
if ( ! V_2 ) {
if ( V_70 == 0 )
break;
V_70 = 0 ;
continue;
}
V_82 = F_248 ( V_35 , V_109 , V_2 , V_65 ) ;
if ( ! V_82 && V_2 -> V_276 == V_289 )
V_2 -> V_276 = V_277 ;
V_70 = V_2 -> V_21 . V_22 + V_2 -> V_21 . V_33 ;
F_6 ( V_2 ) ;
}
V_73:
F_50 ( V_65 ) ;
return V_82 ;
}
int F_249 ( struct V_34 * V_35 , T_2 V_27 )
{
struct V_1 * V_14 ;
int V_290 = 0 ;
V_14 = F_68 ( V_35 -> V_37 , V_27 ) ;
if ( ! V_14 || V_14 -> V_278 )
V_290 = 1 ;
if ( V_14 )
F_6 ( V_14 ) ;
return V_290 ;
}
static const char * F_250 ( T_2 V_7 )
{
switch ( V_7 ) {
case V_291 | V_292 :
return L_3 ;
case V_291 :
return L_4 ;
case V_292 :
return L_5 ;
case V_293 :
return L_6 ;
default:
F_8 ( 1 ) ;
return L_7 ;
} ;
}
static int F_251 ( struct V_12 * V_13 , T_2 V_7 ,
T_2 V_294 , T_2 V_295 ,
struct V_101 * * V_104 )
{
struct V_101 * V_105 ;
int V_43 ;
int V_296 ;
int V_29 ;
if ( V_7 & ( V_297 | V_298 |
V_299 ) )
V_296 = 2 ;
else
V_296 = 1 ;
V_105 = F_69 ( V_13 , V_7 ) ;
if ( V_105 ) {
F_11 ( & V_105 -> V_52 ) ;
V_105 -> V_294 += V_294 ;
V_105 -> V_300 += V_294 * V_296 ;
V_105 -> V_295 += V_295 ;
V_105 -> V_301 += V_295 * V_296 ;
V_105 -> V_107 = 0 ;
F_13 ( & V_105 -> V_52 ) ;
* V_104 = V_105 ;
return 0 ;
}
V_105 = F_53 ( sizeof( * V_105 ) , V_40 ) ;
if ( ! V_105 )
return - V_72 ;
V_29 = F_252 ( & V_105 -> V_302 , 0 , V_303 ) ;
if ( V_29 ) {
F_9 ( V_105 ) ;
return V_29 ;
}
for ( V_43 = 0 ; V_43 < V_304 ; V_43 ++ )
F_54 ( & V_105 -> V_305 [ V_43 ] ) ;
F_253 ( & V_105 -> V_306 ) ;
F_254 ( & V_105 -> V_52 ) ;
V_105 -> V_7 = V_7 & V_106 ;
V_105 -> V_294 = V_294 ;
V_105 -> V_300 = V_294 * V_296 ;
V_105 -> V_295 = V_295 ;
V_105 -> V_301 = V_295 * V_296 ;
V_105 -> V_307 = 0 ;
V_105 -> V_308 = 0 ;
V_105 -> V_309 = 0 ;
V_105 -> V_310 = 0 ;
V_105 -> V_107 = 0 ;
V_105 -> V_311 = V_312 ;
V_105 -> V_313 = 0 ;
V_105 -> V_314 = 0 ;
F_56 ( & V_105 -> V_89 ) ;
V_29 = F_255 ( & V_105 -> V_315 , & V_316 ,
V_13 -> V_317 , L_8 ,
F_250 ( V_105 -> V_7 ) ) ;
if ( V_29 ) {
F_9 ( V_105 ) ;
return V_29 ;
}
* V_104 = V_105 ;
F_256 ( & V_105 -> V_91 , & V_13 -> V_104 ) ;
if ( V_7 & V_292 )
V_13 -> V_318 = V_105 ;
return V_29 ;
}
static void F_257 ( struct V_12 * V_37 , T_2 V_7 )
{
T_2 V_319 = F_258 ( V_7 ) &
V_320 ;
F_259 ( & V_37 -> V_321 ) ;
if ( V_7 & V_292 )
V_37 -> V_322 |= V_319 ;
if ( V_7 & V_291 )
V_37 -> V_323 |= V_319 ;
if ( V_7 & V_293 )
V_37 -> V_324 |= V_319 ;
F_260 ( & V_37 -> V_321 ) ;
}
static T_2 F_261 ( struct V_12 * V_37 , T_2 V_7 )
{
struct V_325 * V_326 = V_37 -> V_327 ;
T_2 V_328 = 0 ;
if ( ! V_326 )
return 0 ;
if ( V_7 & V_292 &&
V_326 -> V_329 . V_7 & V_330 ) {
V_328 = V_292 | V_326 -> V_329 . V_328 ;
} else if ( V_7 & V_293 &&
V_326 -> V_331 . V_7 & V_330 ) {
V_328 = V_293 | V_326 -> V_331 . V_328 ;
} else if ( V_7 & V_291 &&
V_326 -> V_332 . V_7 & V_330 ) {
V_328 = V_291 | V_326 -> V_332 . V_328 ;
}
return V_328 ;
}
static T_2 F_262 ( struct V_34 * V_35 , T_2 V_7 )
{
T_2 V_333 = V_35 -> V_37 -> V_334 -> V_335 ;
T_2 V_328 ;
T_2 V_336 ;
F_11 ( & V_35 -> V_37 -> V_337 ) ;
V_328 = F_261 ( V_35 -> V_37 , V_7 ) ;
if ( V_328 ) {
if ( ( V_7 & V_328 ) & V_320 ) {
F_13 ( & V_35 -> V_37 -> V_337 ) ;
return F_263 ( V_328 ) ;
}
}
F_13 ( & V_35 -> V_37 -> V_337 ) ;
if ( V_333 == 1 )
V_7 &= ~ ( V_298 | V_338 |
V_339 ) ;
if ( V_333 < 3 )
V_7 &= ~ V_340 ;
if ( V_333 < 4 )
V_7 &= ~ V_299 ;
V_336 = V_7 & ( V_297 | V_338 |
V_298 | V_339 |
V_340 | V_299 ) ;
V_7 &= ~ V_336 ;
if ( V_336 & V_340 )
V_336 = V_340 ;
else if ( V_336 & V_339 )
V_336 = V_339 ;
else if ( V_336 & V_299 )
V_336 = V_299 ;
else if ( V_336 & V_298 )
V_336 = V_298 ;
else if ( V_336 & V_338 )
V_336 = V_338 ;
return F_263 ( V_7 | V_336 ) ;
}
static T_2 F_264 ( struct V_34 * V_35 , T_2 V_341 )
{
unsigned V_221 ;
T_2 V_7 ;
do {
V_7 = V_341 ;
V_221 = F_265 ( & V_35 -> V_37 -> V_321 ) ;
if ( V_7 & V_292 )
V_7 |= V_35 -> V_37 -> V_322 ;
else if ( V_7 & V_293 )
V_7 |= V_35 -> V_37 -> V_324 ;
else if ( V_7 & V_291 )
V_7 |= V_35 -> V_37 -> V_323 ;
} while ( F_266 ( & V_35 -> V_37 -> V_321 , V_221 ) );
return F_262 ( V_35 , V_7 ) ;
}
T_2 F_267 ( struct V_34 * V_35 , int V_329 )
{
T_2 V_7 ;
T_2 V_29 ;
if ( V_329 )
V_7 = V_292 ;
else if ( V_35 == V_35 -> V_37 -> V_342 )
V_7 = V_293 ;
else
V_7 = V_291 ;
V_29 = F_264 ( V_35 , V_7 ) ;
return V_29 ;
}
int F_243 ( struct V_270 * V_270 , T_2 V_343 )
{
struct V_101 * V_318 ;
struct V_34 * V_35 = F_238 ( V_270 ) -> V_35 ;
struct V_12 * V_37 = V_35 -> V_37 ;
T_2 V_344 ;
int V_29 = 0 , V_345 = 0 , V_346 = 1 ;
V_343 = F_268 ( V_343 , V_35 -> V_347 ) ;
if ( F_269 ( V_270 ) ) {
V_345 = 1 ;
ASSERT ( V_348 -> V_349 ) ;
}
V_318 = V_37 -> V_318 ;
if ( ! V_318 )
goto V_350;
V_78:
F_11 ( & V_318 -> V_52 ) ;
V_344 = V_318 -> V_295 + V_318 -> V_308 +
V_318 -> V_307 + V_318 -> V_309 +
V_318 -> V_310 ;
if ( V_344 + V_343 > V_318 -> V_294 ) {
struct V_108 * V_109 ;
if ( ! V_318 -> V_107 && V_346 ) {
T_2 V_351 ;
V_318 -> V_311 = V_352 ;
F_13 ( & V_318 -> V_52 ) ;
V_350:
V_351 = F_267 ( V_35 , 1 ) ;
V_109 = F_193 ( V_35 ) ;
if ( F_194 ( V_109 ) )
return F_195 ( V_109 ) ;
V_29 = F_270 ( V_109 , V_35 -> V_37 -> V_63 ,
V_351 ,
V_312 ) ;
F_197 ( V_109 , V_35 ) ;
if ( V_29 < 0 ) {
if ( V_29 != - V_353 )
return V_29 ;
else
goto V_354;
}
if ( ! V_318 )
V_318 = V_37 -> V_318 ;
goto V_78;
}
if ( F_271 ( & V_318 -> V_302 ,
V_343 ) < 0 )
V_345 = 1 ;
F_13 ( & V_318 -> V_52 ) ;
V_354:
if ( ! V_345 &&
! F_191 ( & V_35 -> V_37 -> V_355 ) ) {
V_345 = 1 ;
V_109 = F_193 ( V_35 ) ;
if ( F_194 ( V_109 ) )
return F_195 ( V_109 ) ;
V_29 = F_272 ( V_109 , V_35 ) ;
if ( V_29 )
return V_29 ;
goto V_78;
}
F_273 ( V_35 -> V_37 ,
L_9 ,
V_318 -> V_7 , V_343 , 1 ) ;
return - V_353 ;
}
V_318 -> V_310 += V_343 ;
F_273 ( V_35 -> V_37 , L_10 ,
V_318 -> V_7 , V_343 , 1 ) ;
F_13 ( & V_318 -> V_52 ) ;
return 0 ;
}
void F_245 ( struct V_270 * V_270 , T_2 V_343 )
{
struct V_34 * V_35 = F_238 ( V_270 ) -> V_35 ;
struct V_101 * V_318 ;
V_343 = F_268 ( V_343 , V_35 -> V_347 ) ;
V_318 = V_35 -> V_37 -> V_318 ;
F_11 ( & V_318 -> V_52 ) ;
F_8 ( V_318 -> V_310 < V_343 ) ;
V_318 -> V_310 -= V_343 ;
F_273 ( V_35 -> V_37 , L_10 ,
V_318 -> V_7 , V_343 , 0 ) ;
F_13 ( & V_318 -> V_52 ) ;
}
static void F_274 ( struct V_12 * V_13 )
{
struct V_102 * V_103 = & V_13 -> V_104 ;
struct V_101 * V_105 ;
F_70 () ;
F_71 (found, head, list) {
if ( V_105 -> V_7 & V_291 )
V_105 -> V_311 = V_352 ;
}
F_72 () ;
}
static inline T_2 F_275 ( struct V_239 * V_356 )
{
return ( V_356 -> V_57 << 1 ) ;
}
static int F_276 ( struct V_34 * V_35 ,
struct V_101 * V_357 , int V_358 )
{
struct V_239 * V_240 = & V_35 -> V_37 -> V_241 ;
T_2 V_36 = V_357 -> V_294 - V_357 -> V_309 ;
T_2 V_359 = V_357 -> V_295 + V_357 -> V_308 ;
T_2 V_360 ;
if ( V_358 == V_352 )
return 1 ;
if ( V_357 -> V_7 & V_291 )
V_359 += F_275 ( V_240 ) ;
if ( V_358 == V_361 ) {
V_360 = F_277 ( V_35 -> V_37 -> V_362 ) ;
V_360 = F_34 ( T_2 , 64 * 1024 * 1024 ,
F_278 ( V_360 , 1 ) ) ;
if ( V_36 - V_359 < V_360 )
return 1 ;
}
if ( V_359 + 2 * 1024 * 1024 < F_279 ( V_36 , 8 ) )
return 0 ;
return 1 ;
}
static T_2 F_280 ( struct V_34 * V_35 , T_2 type )
{
T_2 V_363 ;
if ( type & ( V_299 |
V_338 |
V_339 |
V_340 ) )
V_363 = V_35 -> V_37 -> V_334 -> V_335 ;
else if ( type & V_298 )
V_363 = 2 ;
else
V_363 = 1 ;
return F_189 ( V_35 , V_363 + 1 ) ;
}
static void F_281 ( struct V_108 * V_109 ,
struct V_34 * V_35 , T_2 type )
{
struct V_101 * V_13 ;
T_2 V_364 ;
T_2 V_360 ;
V_13 = F_69 ( V_35 -> V_37 , V_293 ) ;
F_11 ( & V_13 -> V_52 ) ;
V_364 = V_13 -> V_294 - V_13 -> V_295 - V_13 -> V_307 -
V_13 -> V_308 - V_13 -> V_309 ;
F_13 ( & V_13 -> V_52 ) ;
V_360 = F_280 ( V_35 , type ) ;
if ( V_364 < V_360 && F_242 ( V_35 , V_365 ) ) {
F_282 ( V_35 -> V_37 , L_11 ,
V_364 , V_360 , type ) ;
F_283 ( V_13 , 0 , 0 ) ;
}
if ( V_364 < V_360 ) {
T_2 V_7 ;
V_7 = F_267 ( V_35 -> V_37 -> V_342 , 0 ) ;
F_284 ( V_109 , V_35 , V_7 ) ;
}
}
static int F_270 ( struct V_108 * V_109 ,
struct V_34 * V_63 , T_2 V_7 , int V_358 )
{
struct V_101 * V_104 ;
struct V_12 * V_37 = V_63 -> V_37 ;
int V_366 = 0 ;
int V_29 = 0 ;
if ( V_109 -> V_367 )
return - V_353 ;
V_104 = F_69 ( V_63 -> V_37 , V_7 ) ;
if ( ! V_104 ) {
V_29 = F_251 ( V_63 -> V_37 , V_7 ,
0 , 0 , & V_104 ) ;
F_30 ( V_29 ) ;
}
F_30 ( ! V_104 ) ;
V_78:
F_11 ( & V_104 -> V_52 ) ;
if ( V_358 < V_104 -> V_311 )
V_358 = V_104 -> V_311 ;
if ( V_104 -> V_107 ) {
if ( F_276 ( V_63 , V_104 , V_358 ) )
V_29 = - V_353 ;
else
V_29 = 0 ;
F_13 ( & V_104 -> V_52 ) ;
return V_29 ;
}
if ( ! F_276 ( V_63 , V_104 , V_358 ) ) {
F_13 ( & V_104 -> V_52 ) ;
return 0 ;
} else if ( V_104 -> V_313 ) {
V_366 = 1 ;
} else {
V_104 -> V_313 = 1 ;
}
F_13 ( & V_104 -> V_52 ) ;
F_35 ( & V_37 -> V_368 ) ;
if ( V_366 ) {
F_46 ( & V_37 -> V_368 ) ;
V_366 = 0 ;
goto V_78;
}
V_109 -> V_367 = true ;
if ( F_285 ( V_104 ) )
V_7 |= ( V_292 | V_291 ) ;
if ( V_7 & V_292 && V_37 -> V_369 ) {
V_37 -> V_370 ++ ;
if ( ! ( V_37 -> V_370 %
V_37 -> V_369 ) )
F_274 ( V_37 ) ;
}
F_281 ( V_109 , V_63 , V_7 ) ;
V_29 = F_284 ( V_109 , V_63 , V_7 ) ;
V_109 -> V_367 = false ;
F_11 ( & V_104 -> V_52 ) ;
if ( V_29 < 0 && V_29 != - V_353 )
goto V_73;
if ( V_29 )
V_104 -> V_107 = 1 ;
else
V_29 = 1 ;
V_104 -> V_311 = V_312 ;
V_73:
V_104 -> V_313 = 0 ;
F_13 ( & V_104 -> V_52 ) ;
F_46 ( & V_37 -> V_368 ) ;
return V_29 ;
}
static int F_286 ( struct V_34 * V_35 ,
struct V_101 * V_104 , T_2 V_343 ,
enum V_371 V_314 )
{
struct V_239 * V_240 = & V_35 -> V_37 -> V_241 ;
T_2 V_372 = F_267 ( V_35 , 0 ) ;
T_2 V_373 ;
T_2 V_374 ;
T_2 V_344 ;
V_344 = V_104 -> V_295 + V_104 -> V_308 +
V_104 -> V_307 + V_104 -> V_309 ;
F_11 ( & V_240 -> V_52 ) ;
V_373 = F_275 ( V_240 ) ;
F_13 ( & V_240 -> V_52 ) ;
if ( V_344 + V_373 >= V_104 -> V_294 )
return 0 ;
V_344 += V_104 -> V_310 ;
F_11 ( & V_35 -> V_37 -> V_375 ) ;
V_374 = V_35 -> V_37 -> V_376 ;
F_13 ( & V_35 -> V_37 -> V_375 ) ;
if ( V_372 & ( V_297 |
V_298 |
V_299 ) )
V_374 >>= 1 ;
if ( V_314 == V_377 )
V_374 >>= 3 ;
else
V_374 >>= 1 ;
if ( V_344 + V_343 < V_104 -> V_294 + V_374 )
return 1 ;
return 0 ;
}
static void F_287 ( struct V_34 * V_35 ,
unsigned long V_378 , int V_379 )
{
struct V_380 * V_381 = V_35 -> V_37 -> V_381 ;
if ( F_288 ( & V_381 -> V_382 ) ) {
F_289 ( V_381 , V_378 , V_383 ) ;
F_45 ( & V_381 -> V_382 ) ;
} else {
F_290 ( V_35 -> V_37 , 0 , V_379 ) ;
if ( ! V_348 -> V_349 )
F_291 ( V_35 -> V_37 , V_379 ) ;
}
}
static inline int F_292 ( struct V_34 * V_35 , T_2 V_384 )
{
T_2 V_343 ;
int V_44 ;
V_343 = F_189 ( V_35 , 1 ) ;
V_44 = ( int ) F_183 ( V_384 , V_343 ) ;
if ( ! V_44 )
V_44 = 1 ;
return V_44 ;
}
static void F_293 ( struct V_34 * V_35 , T_2 V_384 , T_2 V_385 ,
bool V_386 )
{
struct V_239 * V_387 ;
struct V_101 * V_104 ;
struct V_108 * V_109 ;
T_2 V_285 ;
T_2 V_388 ;
long V_389 ;
unsigned long V_378 ;
int V_390 ;
int V_391 ;
enum V_371 V_314 ;
V_391 = F_292 ( V_35 , V_384 ) ;
V_384 = V_391 * V_392 ;
V_109 = (struct V_108 * ) V_348 -> V_349 ;
V_387 = & V_35 -> V_37 -> V_393 ;
V_104 = V_387 -> V_104 ;
V_285 = F_294 (
& V_35 -> V_37 -> V_285 ) ;
if ( V_285 == 0 ) {
if ( V_109 )
return;
if ( V_386 )
F_291 ( V_35 -> V_37 , V_391 ) ;
return;
}
V_390 = 0 ;
while ( V_285 && V_390 < 3 ) {
V_388 = F_295 ( V_285 , V_384 ) ;
V_378 = V_388 >> V_394 ;
F_287 ( V_35 , V_378 , V_391 ) ;
V_388 = F_191 ( & V_35 -> V_37 -> V_395 ) ;
if ( ! V_388 )
goto V_396;
if ( V_388 <= V_378 )
V_388 = 0 ;
else
V_388 -= V_378 ;
F_296 ( V_35 -> V_37 -> V_397 ,
F_191 ( & V_35 -> V_37 -> V_395 ) <=
( int ) V_388 ) ;
V_396:
if ( ! V_109 )
V_314 = V_377 ;
else
V_314 = V_398 ;
F_11 ( & V_104 -> V_52 ) ;
if ( F_286 ( V_35 , V_104 , V_385 , V_314 ) ) {
F_13 ( & V_104 -> V_52 ) ;
break;
}
F_13 ( & V_104 -> V_52 ) ;
V_390 ++ ;
if ( V_386 && ! V_109 ) {
F_291 ( V_35 -> V_37 , V_391 ) ;
} else {
V_389 = F_297 ( 1 ) ;
if ( V_389 )
break;
}
V_285 = F_294 (
& V_35 -> V_37 -> V_285 ) ;
}
}
static int F_298 ( struct V_34 * V_35 ,
struct V_101 * V_104 ,
T_2 V_343 , int V_358 )
{
struct V_239 * V_399 = & V_35 -> V_37 -> V_400 ;
struct V_108 * V_109 ;
V_109 = (struct V_108 * ) V_348 -> V_349 ;
if ( V_109 )
return - V_177 ;
if ( V_358 )
goto V_401;
if ( F_271 ( & V_104 -> V_302 ,
V_343 ) >= 0 )
goto V_401;
if ( V_104 != V_399 -> V_104 )
return - V_353 ;
F_11 ( & V_399 -> V_52 ) ;
if ( F_271 ( & V_104 -> V_302 ,
V_343 - V_399 -> V_57 ) >= 0 ) {
F_13 ( & V_399 -> V_52 ) ;
return - V_353 ;
}
F_13 ( & V_399 -> V_52 ) ;
V_401:
V_109 = F_193 ( V_35 ) ;
if ( F_194 ( V_109 ) )
return - V_353 ;
return F_272 ( V_109 , V_35 ) ;
}
static int F_299 ( struct V_34 * V_35 ,
struct V_101 * V_104 , T_2 V_36 ,
T_2 V_402 , int V_266 )
{
struct V_108 * V_109 ;
int V_44 ;
int V_29 = 0 ;
switch ( V_266 ) {
case V_403 :
case V_404 :
if ( V_266 == V_403 )
V_44 = F_292 ( V_35 , V_36 ) * 2 ;
else
V_44 = - 1 ;
V_109 = F_193 ( V_35 ) ;
if ( F_194 ( V_109 ) ) {
V_29 = F_195 ( V_109 ) ;
break;
}
V_29 = F_300 ( V_109 , V_35 , V_44 ) ;
F_197 ( V_109 , V_35 ) ;
break;
case V_405 :
case V_406 :
F_293 ( V_35 , V_36 * 2 , V_402 ,
V_266 == V_406 ) ;
break;
case V_407 :
V_109 = F_193 ( V_35 ) ;
if ( F_194 ( V_109 ) ) {
V_29 = F_195 ( V_109 ) ;
break;
}
V_29 = F_270 ( V_109 , V_35 -> V_37 -> V_63 ,
F_267 ( V_35 , 0 ) ,
V_312 ) ;
F_197 ( V_109 , V_35 ) ;
if ( V_29 == - V_353 )
V_29 = 0 ;
break;
case V_408 :
V_29 = F_298 ( V_35 , V_104 , V_402 , 0 ) ;
break;
default:
V_29 = - V_353 ;
break;
}
return V_29 ;
}
static inline T_2
F_301 ( struct V_34 * V_35 ,
struct V_101 * V_104 )
{
T_2 V_344 ;
T_2 V_409 ;
T_2 V_384 ;
V_384 = F_24 ( T_2 , F_302 () * 1024 * 1024 ,
16 * 1024 * 1024 ) ;
F_11 ( & V_104 -> V_52 ) ;
if ( F_286 ( V_35 , V_104 , V_384 ,
V_377 ) ) {
V_384 = 0 ;
goto V_73;
}
V_344 = V_104 -> V_295 + V_104 -> V_308 +
V_104 -> V_307 + V_104 -> V_309 +
V_104 -> V_310 ;
if ( F_286 ( V_35 , V_104 , 1024 * 1024 ,
V_377 ) )
V_409 = F_278 ( V_104 -> V_294 , 95 ) ;
else
V_409 = F_278 ( V_104 -> V_294 , 90 ) ;
if ( V_344 > V_409 )
V_384 = V_344 - V_409 ;
else
V_384 = 0 ;
V_384 = F_295 ( V_384 , V_104 -> V_310 +
V_104 -> V_308 ) ;
V_73:
F_13 ( & V_104 -> V_52 ) ;
return V_384 ;
}
static inline int F_303 ( struct V_101 * V_104 ,
struct V_12 * V_37 , T_2 V_344 )
{
return ( V_344 >= F_278 ( V_104 -> V_294 , 98 ) &&
! F_39 ( V_37 ) &&
! F_222 ( V_410 , & V_37 -> V_411 ) ) ;
}
static int F_304 ( struct V_101 * V_104 ,
struct V_12 * V_37 ,
int V_412 )
{
T_2 V_344 ;
F_11 ( & V_104 -> V_52 ) ;
if ( V_412 > V_408 && V_104 -> V_107 ) {
F_13 ( & V_104 -> V_52 ) ;
return 0 ;
}
V_344 = V_104 -> V_295 + V_104 -> V_308 +
V_104 -> V_307 + V_104 -> V_309 +
V_104 -> V_310 ;
if ( F_303 ( V_104 , V_37 , V_344 ) ) {
F_13 ( & V_104 -> V_52 ) ;
return 1 ;
}
F_13 ( & V_104 -> V_52 ) ;
return 0 ;
}
static void F_305 ( struct V_413 * V_62 )
{
struct V_12 * V_37 ;
struct V_101 * V_104 ;
T_2 V_384 ;
int V_412 ;
V_37 = F_32 ( V_62 , struct V_12 , V_414 ) ;
V_104 = F_69 ( V_37 , V_291 ) ;
V_384 = F_301 ( V_37 -> V_415 ,
V_104 ) ;
if ( ! V_384 )
return;
V_412 = V_403 ;
do {
F_299 ( V_37 -> V_415 , V_104 , V_384 ,
V_384 , V_412 ) ;
V_412 ++ ;
if ( ! F_304 ( V_104 , V_37 ,
V_412 ) )
return;
} while ( V_412 <= V_408 );
if ( F_304 ( V_104 , V_37 , V_412 ) )
F_306 ( V_416 , V_62 ) ;
}
void F_307 ( struct V_413 * V_62 )
{
F_308 ( V_62 , F_305 ) ;
}
static int F_309 ( struct V_34 * V_35 ,
struct V_239 * V_387 ,
T_2 V_402 ,
enum V_371 V_314 )
{
struct V_101 * V_104 = V_387 -> V_104 ;
T_2 V_344 ;
T_2 V_36 = V_402 ;
int V_412 = V_403 ;
int V_29 = 0 ;
bool V_417 = false ;
V_78:
V_29 = 0 ;
F_11 ( & V_104 -> V_52 ) ;
while ( V_314 == V_377 && ! V_417 &&
V_104 -> V_314 ) {
F_13 ( & V_104 -> V_52 ) ;
if ( V_348 -> V_349 )
return - V_177 ;
V_29 = F_310 ( V_104 -> V_89 , ! V_104 -> V_314 ) ;
if ( V_29 )
return - V_418 ;
F_11 ( & V_104 -> V_52 ) ;
}
V_29 = - V_353 ;
V_344 = V_104 -> V_295 + V_104 -> V_308 +
V_104 -> V_307 + V_104 -> V_309 +
V_104 -> V_310 ;
if ( V_344 <= V_104 -> V_294 ) {
if ( V_344 + V_402 <= V_104 -> V_294 ) {
V_104 -> V_310 += V_402 ;
F_273 ( V_35 -> V_37 ,
L_10 , V_104 -> V_7 , V_402 , 1 ) ;
V_29 = 0 ;
} else {
V_36 = V_402 ;
}
} else {
V_36 = V_344 - V_104 -> V_294 +
( V_402 * 2 ) ;
}
if ( V_29 && F_286 ( V_35 , V_104 , V_402 , V_314 ) ) {
V_104 -> V_310 += V_402 ;
F_273 ( V_35 -> V_37 , L_10 ,
V_104 -> V_7 , V_402 ,
1 ) ;
V_29 = 0 ;
}
if ( V_29 && V_314 != V_398 ) {
V_417 = true ;
V_104 -> V_314 = 1 ;
} else if ( ! V_29 && V_104 -> V_7 & V_291 ) {
V_344 += V_402 ;
if ( ! V_35 -> V_37 -> V_419 &&
F_303 ( V_104 , V_35 -> V_37 , V_344 ) &&
! F_311 ( & V_35 -> V_37 -> V_414 ) )
F_306 ( V_416 ,
& V_35 -> V_37 -> V_414 ) ;
}
F_13 ( & V_104 -> V_52 ) ;
if ( ! V_29 || V_314 == V_398 )
goto V_73;
V_29 = F_299 ( V_35 , V_104 , V_36 , V_402 ,
V_412 ) ;
V_412 ++ ;
if ( V_314 == V_420 &&
( V_412 == V_405 ||
V_412 == V_406 ) )
V_412 = V_407 ;
if ( ! V_29 )
goto V_78;
else if ( V_314 == V_420 &&
V_412 < V_408 )
goto V_78;
else if ( V_314 == V_377 &&
V_412 <= V_408 )
goto V_78;
V_73:
if ( V_29 == - V_353 &&
F_312 ( V_35 -> V_421 == V_422 ) ) {
struct V_239 * V_240 =
& V_35 -> V_37 -> V_241 ;
if ( V_387 != V_240 &&
! F_313 ( V_240 , V_402 ) )
V_29 = 0 ;
}
if ( V_29 == - V_353 )
F_273 ( V_35 -> V_37 ,
L_9 ,
V_104 -> V_7 , V_402 , 1 ) ;
if ( V_417 ) {
F_11 ( & V_104 -> V_52 ) ;
V_104 -> V_314 = 0 ;
F_314 ( & V_104 -> V_89 ) ;
F_13 ( & V_104 -> V_52 ) ;
}
return V_29 ;
}
static struct V_239 * F_315 (
const struct V_108 * V_109 ,
const struct V_34 * V_35 )
{
struct V_239 * V_387 = NULL ;
if ( F_222 ( V_265 , & V_35 -> V_266 ) )
V_387 = V_109 -> V_387 ;
if ( V_35 == V_35 -> V_37 -> V_423 && V_109 -> V_424 )
V_387 = V_109 -> V_387 ;
if ( V_35 == V_35 -> V_37 -> V_425 )
V_387 = V_109 -> V_387 ;
if ( ! V_387 )
V_387 = V_35 -> V_387 ;
if ( ! V_387 )
V_387 = & V_35 -> V_37 -> V_426 ;
return V_387 ;
}
static int F_313 ( struct V_239 * V_387 ,
T_2 V_36 )
{
int V_29 = - V_353 ;
F_11 ( & V_387 -> V_52 ) ;
if ( V_387 -> V_10 >= V_36 ) {
V_387 -> V_10 -= V_36 ;
if ( V_387 -> V_10 < V_387 -> V_57 )
V_387 -> V_107 = 0 ;
V_29 = 0 ;
}
F_13 ( & V_387 -> V_52 ) ;
return V_29 ;
}
static void F_316 ( struct V_239 * V_387 ,
T_2 V_36 , int V_427 )
{
F_11 ( & V_387 -> V_52 ) ;
V_387 -> V_10 += V_36 ;
if ( V_427 )
V_387 -> V_57 += V_36 ;
else if ( V_387 -> V_10 >= V_387 -> V_57 )
V_387 -> V_107 = 1 ;
F_13 ( & V_387 -> V_52 ) ;
}
int F_317 ( struct V_12 * V_37 ,
struct V_239 * V_428 , T_2 V_36 ,
int V_429 )
{
struct V_239 * V_240 = & V_37 -> V_241 ;
T_2 V_430 ;
if ( V_240 -> V_104 != V_428 -> V_104 )
return - V_353 ;
F_11 ( & V_240 -> V_52 ) ;
V_430 = F_279 ( V_240 -> V_57 , V_429 ) ;
if ( V_240 -> V_10 < V_430 + V_36 ) {
F_13 ( & V_240 -> V_52 ) ;
return - V_353 ;
}
V_240 -> V_10 -= V_36 ;
if ( V_240 -> V_10 < V_240 -> V_57 )
V_240 -> V_107 = 0 ;
F_13 ( & V_240 -> V_52 ) ;
F_316 ( V_428 , V_36 , 1 ) ;
return 0 ;
}
static void F_318 ( struct V_12 * V_37 ,
struct V_239 * V_387 ,
struct V_239 * V_428 , T_2 V_36 )
{
struct V_101 * V_104 = V_387 -> V_104 ;
F_11 ( & V_387 -> V_52 ) ;
if ( V_36 == ( T_2 ) - 1 )
V_36 = V_387 -> V_57 ;
V_387 -> V_57 -= V_36 ;
if ( V_387 -> V_10 >= V_387 -> V_57 ) {
V_36 = V_387 -> V_10 - V_387 -> V_57 ;
V_387 -> V_10 = V_387 -> V_57 ;
V_387 -> V_107 = 1 ;
} else {
V_36 = 0 ;
}
F_13 ( & V_387 -> V_52 ) ;
if ( V_36 > 0 ) {
if ( V_428 ) {
F_11 ( & V_428 -> V_52 ) ;
if ( ! V_428 -> V_107 ) {
T_2 V_431 ;
V_431 = V_428 -> V_57 - V_428 -> V_10 ;
V_431 = F_295 ( V_36 , V_431 ) ;
V_428 -> V_10 += V_431 ;
if ( V_428 -> V_10 >= V_428 -> V_57 )
V_428 -> V_107 = 1 ;
V_36 -= V_431 ;
}
F_13 ( & V_428 -> V_52 ) ;
}
if ( V_36 ) {
F_11 ( & V_104 -> V_52 ) ;
V_104 -> V_310 -= V_36 ;
F_273 ( V_37 , L_10 ,
V_104 -> V_7 , V_36 , 0 ) ;
F_13 ( & V_104 -> V_52 ) ;
}
}
}
static int F_319 ( struct V_239 * V_432 ,
struct V_239 * V_433 , T_2 V_36 )
{
int V_29 ;
V_29 = F_313 ( V_432 , V_36 ) ;
if ( V_29 )
return V_29 ;
F_316 ( V_433 , V_36 , 1 ) ;
return 0 ;
}
void F_320 ( struct V_239 * V_434 , unsigned short type )
{
memset ( V_434 , 0 , sizeof( * V_434 ) ) ;
F_254 ( & V_434 -> V_52 ) ;
V_434 -> type = type ;
}
struct V_239 * F_321 ( struct V_34 * V_35 ,
unsigned short type )
{
struct V_239 * V_387 ;
struct V_12 * V_37 = V_35 -> V_37 ;
V_387 = F_200 ( sizeof( * V_387 ) , V_40 ) ;
if ( ! V_387 )
return NULL ;
F_320 ( V_387 , type ) ;
V_387 -> V_104 = F_69 ( V_37 ,
V_291 ) ;
return V_387 ;
}
void F_322 ( struct V_34 * V_35 ,
struct V_239 * V_434 )
{
if ( ! V_434 )
return;
F_323 ( V_35 , V_434 , ( T_2 ) - 1 ) ;
F_9 ( V_434 ) ;
}
int F_324 ( struct V_34 * V_35 ,
struct V_239 * V_387 , T_2 V_36 ,
enum V_371 V_314 )
{
int V_29 ;
if ( V_36 == 0 )
return 0 ;
V_29 = F_309 ( V_35 , V_387 , V_36 , V_314 ) ;
if ( ! V_29 ) {
F_316 ( V_387 , V_36 , 1 ) ;
return 0 ;
}
return V_29 ;
}
int F_325 ( struct V_34 * V_35 ,
struct V_239 * V_387 , int V_429 )
{
T_2 V_36 = 0 ;
int V_29 = - V_353 ;
if ( ! V_387 )
return 0 ;
F_11 ( & V_387 -> V_52 ) ;
V_36 = F_279 ( V_387 -> V_57 , V_429 ) ;
if ( V_387 -> V_10 >= V_36 )
V_29 = 0 ;
F_13 ( & V_387 -> V_52 ) ;
return V_29 ;
}
int F_326 ( struct V_34 * V_35 ,
struct V_239 * V_387 , T_2 V_435 ,
enum V_371 V_314 )
{
T_2 V_36 = 0 ;
int V_29 = - V_353 ;
if ( ! V_387 )
return 0 ;
F_11 ( & V_387 -> V_52 ) ;
V_36 = V_435 ;
if ( V_387 -> V_10 >= V_36 )
V_29 = 0 ;
else
V_36 -= V_387 -> V_10 ;
F_13 ( & V_387 -> V_52 ) ;
if ( ! V_29 )
return 0 ;
V_29 = F_309 ( V_35 , V_387 , V_36 , V_314 ) ;
if ( ! V_29 ) {
F_316 ( V_387 , V_36 , 0 ) ;
return 0 ;
}
return V_29 ;
}
int F_327 ( struct V_239 * V_436 ,
struct V_239 * V_437 ,
T_2 V_36 )
{
return F_319 ( V_436 , V_437 , V_36 ) ;
}
void F_323 ( struct V_34 * V_35 ,
struct V_239 * V_387 ,
T_2 V_36 )
{
struct V_239 * V_240 = & V_35 -> V_37 -> V_241 ;
if ( V_240 == V_387 ||
V_387 -> V_104 != V_240 -> V_104 )
V_240 = NULL ;
F_318 ( V_35 -> V_37 , V_387 , V_240 ,
V_36 ) ;
}
static T_2 F_328 ( struct V_12 * V_37 )
{
struct V_101 * V_357 ;
T_2 V_36 ;
T_2 V_438 ;
T_2 V_439 ;
int V_440 = F_329 ( V_37 -> V_362 ) ;
V_357 = F_69 ( V_37 , V_292 ) ;
F_11 ( & V_357 -> V_52 ) ;
V_439 = V_357 -> V_295 ;
F_13 ( & V_357 -> V_52 ) ;
V_357 = F_69 ( V_37 , V_291 ) ;
F_11 ( & V_357 -> V_52 ) ;
if ( V_357 -> V_7 & V_292 )
V_439 = 0 ;
V_438 = V_357 -> V_295 ;
F_13 ( & V_357 -> V_52 ) ;
V_36 = ( V_439 >> V_37 -> V_381 -> V_441 ) *
V_440 * 2 ;
V_36 += F_183 ( V_439 + V_438 , 50 ) ;
if ( V_36 * 3 > V_438 )
V_36 = F_183 ( V_438 , 3 ) ;
return F_268 ( V_36 , V_37 -> V_63 -> V_88 << 10 ) ;
}
static void F_330 ( struct V_12 * V_37 )
{
struct V_239 * V_387 = & V_37 -> V_241 ;
struct V_101 * V_357 = V_387 -> V_104 ;
T_2 V_36 ;
V_36 = F_328 ( V_37 ) ;
F_11 ( & V_357 -> V_52 ) ;
F_11 ( & V_387 -> V_52 ) ;
V_387 -> V_57 = F_24 ( T_2 , V_36 , 512 * 1024 * 1024 ) ;
V_36 = V_357 -> V_295 + V_357 -> V_307 +
V_357 -> V_308 + V_357 -> V_309 +
V_357 -> V_310 ;
if ( V_357 -> V_294 > V_36 ) {
V_36 = V_357 -> V_294 - V_36 ;
V_387 -> V_10 += V_36 ;
V_357 -> V_310 += V_36 ;
F_273 ( V_37 , L_10 ,
V_357 -> V_7 , V_36 , 1 ) ;
}
if ( V_387 -> V_10 >= V_387 -> V_57 ) {
V_36 = V_387 -> V_10 - V_387 -> V_57 ;
V_357 -> V_310 -= V_36 ;
F_273 ( V_37 , L_10 ,
V_357 -> V_7 , V_36 , 0 ) ;
V_387 -> V_10 = V_387 -> V_57 ;
V_387 -> V_107 = 1 ;
}
F_13 ( & V_387 -> V_52 ) ;
F_13 ( & V_357 -> V_52 ) ;
}
static void F_331 ( struct V_12 * V_37 )
{
struct V_101 * V_104 ;
V_104 = F_69 ( V_37 , V_293 ) ;
V_37 -> V_442 . V_104 = V_104 ;
V_104 = F_69 ( V_37 , V_291 ) ;
V_37 -> V_241 . V_104 = V_104 ;
V_37 -> V_393 . V_104 = V_104 ;
V_37 -> V_443 . V_104 = V_104 ;
V_37 -> V_426 . V_104 = V_104 ;
V_37 -> V_400 . V_104 = V_104 ;
V_37 -> V_63 -> V_387 = & V_37 -> V_241 ;
V_37 -> V_423 -> V_387 = & V_37 -> V_241 ;
V_37 -> V_444 -> V_387 = & V_37 -> V_241 ;
V_37 -> V_87 -> V_387 = & V_37 -> V_241 ;
if ( V_37 -> V_445 )
V_37 -> V_445 -> V_387 = & V_37 -> V_241 ;
V_37 -> V_342 -> V_387 = & V_37 -> V_442 ;
F_330 ( V_37 ) ;
}
static void F_332 ( struct V_12 * V_37 )
{
F_318 ( V_37 , & V_37 -> V_241 , NULL ,
( T_2 ) - 1 ) ;
F_8 ( V_37 -> V_393 . V_57 > 0 ) ;
F_8 ( V_37 -> V_393 . V_10 > 0 ) ;
F_8 ( V_37 -> V_443 . V_57 > 0 ) ;
F_8 ( V_37 -> V_443 . V_10 > 0 ) ;
F_8 ( V_37 -> V_442 . V_57 > 0 ) ;
F_8 ( V_37 -> V_442 . V_10 > 0 ) ;
F_8 ( V_37 -> V_400 . V_57 > 0 ) ;
F_8 ( V_37 -> V_400 . V_10 > 0 ) ;
}
void F_333 ( struct V_108 * V_109 ,
struct V_34 * V_35 )
{
if ( ! V_109 -> V_387 )
return;
if ( ! V_109 -> V_308 )
return;
F_273 ( V_35 -> V_37 , L_12 ,
V_109 -> V_280 , V_109 -> V_308 , 0 ) ;
F_323 ( V_35 , V_109 -> V_387 , V_109 -> V_308 ) ;
V_109 -> V_308 = 0 ;
}
int F_334 ( struct V_108 * V_109 ,
struct V_270 * V_270 )
{
struct V_34 * V_35 = F_238 ( V_270 ) -> V_35 ;
struct V_239 * V_436 = F_315 ( V_109 , V_35 ) ;
struct V_239 * V_437 = V_35 -> V_446 ;
T_2 V_36 = F_189 ( V_35 , 1 ) ;
F_273 ( V_35 -> V_37 , L_13 ,
F_335 ( V_270 ) , V_36 , 1 ) ;
return F_319 ( V_436 , V_437 , V_36 ) ;
}
void F_336 ( struct V_270 * V_270 )
{
struct V_34 * V_35 = F_238 ( V_270 ) -> V_35 ;
T_2 V_36 = F_189 ( V_35 , 1 ) ;
F_273 ( V_35 -> V_37 , L_13 ,
F_335 ( V_270 ) , V_36 , 0 ) ;
F_323 ( V_35 , V_35 -> V_446 , V_36 ) ;
}
int F_337 ( struct V_34 * V_35 ,
struct V_239 * V_434 ,
int V_391 ,
T_2 * V_447 ,
bool V_448 )
{
T_2 V_36 ;
int V_29 ;
struct V_239 * V_240 = & V_35 -> V_37 -> V_241 ;
if ( V_35 -> V_37 -> V_205 ) {
V_36 = 3 * V_35 -> V_88 ;
V_29 = F_338 ( V_35 , V_36 ) ;
if ( V_29 )
return V_29 ;
} else {
V_36 = 0 ;
}
* V_447 = V_36 ;
V_36 = F_189 ( V_35 , V_391 ) ;
V_434 -> V_104 = F_69 ( V_35 -> V_37 ,
V_291 ) ;
V_29 = F_324 ( V_35 , V_434 , V_36 ,
V_377 ) ;
if ( V_29 == - V_353 && V_448 )
V_29 = F_327 ( V_240 , V_434 , V_36 ) ;
if ( V_29 ) {
if ( * V_447 )
F_339 ( V_35 , * V_447 ) ;
}
return V_29 ;
}
void F_340 ( struct V_34 * V_35 ,
struct V_239 * V_434 ,
T_2 V_447 )
{
F_323 ( V_35 , V_434 , ( T_2 ) - 1 ) ;
if ( V_447 )
F_339 ( V_35 , V_447 ) ;
}
static unsigned F_341 ( struct V_270 * V_270 )
{
unsigned V_449 = 0 ;
unsigned V_450 = 0 ;
F_30 ( ! F_238 ( V_270 ) -> V_451 ) ;
F_238 ( V_270 ) -> V_451 -- ;
if ( F_238 ( V_270 ) -> V_451 == 0 &&
F_342 ( V_452 ,
& F_238 ( V_270 ) -> V_453 ) )
V_449 = 1 ;
if ( F_238 ( V_270 ) -> V_451 >=
F_238 ( V_270 ) -> V_454 )
return V_449 ;
V_450 = F_238 ( V_270 ) -> V_454 -
F_238 ( V_270 ) -> V_451 ;
F_238 ( V_270 ) -> V_454 -= V_450 ;
return V_450 + V_449 ;
}
static T_2 F_343 ( struct V_270 * V_270 , T_2 V_36 ,
int V_455 )
{
struct V_34 * V_35 = F_238 ( V_270 ) -> V_35 ;
T_2 V_440 ;
int V_456 ;
int V_457 ;
int V_458 ;
if ( F_238 ( V_270 ) -> V_7 & V_459 &&
F_238 ( V_270 ) -> V_460 == 0 )
return 0 ;
V_458 = ( int ) F_183 ( F_238 ( V_270 ) -> V_460 , V_35 -> V_347 ) ;
if ( V_455 )
F_238 ( V_270 ) -> V_460 += V_36 ;
else
F_238 ( V_270 ) -> V_460 -= V_36 ;
V_440 = F_187 ( V_35 ) - sizeof( struct V_461 ) ;
V_456 = ( int ) F_183 ( V_440 ,
sizeof( struct V_462 ) +
sizeof( struct V_463 ) ) ;
V_457 = ( int ) F_183 ( F_238 ( V_270 ) -> V_460 , V_35 -> V_347 ) ;
V_457 = V_457 + V_456 - 1 ;
V_457 = V_457 / V_456 ;
V_458 = V_458 + V_456 - 1 ;
V_458 = V_458 / V_456 ;
if ( V_458 == V_457 )
return 0 ;
if ( V_455 )
return F_189 ( V_35 ,
V_457 - V_458 ) ;
return F_189 ( V_35 , V_458 - V_457 ) ;
}
int F_344 ( struct V_270 * V_270 , T_2 V_36 )
{
struct V_34 * V_35 = F_238 ( V_270 ) -> V_35 ;
struct V_239 * V_387 = & V_35 -> V_37 -> V_393 ;
T_2 V_464 = 0 ;
T_2 V_460 ;
unsigned V_465 = 0 ;
int V_466 = 0 ;
enum V_371 V_314 = V_377 ;
int V_29 = 0 ;
bool V_467 = true ;
T_2 V_468 = 0 ;
unsigned V_469 ;
if ( F_269 ( V_270 ) ) {
V_314 = V_398 ;
V_467 = false ;
}
if ( V_314 != V_398 &&
F_345 ( V_35 -> V_37 ) )
F_346 ( 1 ) ;
if ( V_467 )
F_35 ( & F_238 ( V_270 ) -> V_470 ) ;
V_36 = F_268 ( V_36 , V_35 -> V_347 ) ;
F_11 ( & F_238 ( V_270 ) -> V_52 ) ;
F_238 ( V_270 ) -> V_451 ++ ;
if ( F_238 ( V_270 ) -> V_451 >
F_238 ( V_270 ) -> V_454 )
V_465 = F_238 ( V_270 ) -> V_451 -
F_238 ( V_270 ) -> V_454 ;
if ( ! F_222 ( V_452 ,
& F_238 ( V_270 ) -> V_453 ) ) {
V_465 ++ ;
V_466 = 1 ;
}
V_464 = F_189 ( V_35 , V_465 ) ;
V_464 += F_343 ( V_270 , V_36 , 1 ) ;
V_460 = F_238 ( V_270 ) -> V_460 ;
F_13 ( & F_238 ( V_270 ) -> V_52 ) ;
if ( V_35 -> V_37 -> V_205 ) {
V_29 = F_338 ( V_35 , V_36 +
V_465 * V_35 -> V_88 ) ;
if ( V_29 )
goto V_471;
}
V_29 = F_309 ( V_35 , V_387 , V_464 , V_314 ) ;
if ( F_312 ( V_29 ) ) {
if ( V_35 -> V_37 -> V_205 )
F_339 ( V_35 , V_36 +
V_465 * V_35 -> V_88 ) ;
goto V_471;
}
F_11 ( & F_238 ( V_270 ) -> V_52 ) ;
if ( V_466 ) {
F_347 ( V_452 ,
& F_238 ( V_270 ) -> V_453 ) ;
V_465 -- ;
}
F_238 ( V_270 ) -> V_454 += V_465 ;
F_13 ( & F_238 ( V_270 ) -> V_52 ) ;
if ( V_467 )
F_46 ( & F_238 ( V_270 ) -> V_470 ) ;
if ( V_464 )
F_273 ( V_35 -> V_37 , L_14 ,
F_335 ( V_270 ) , V_464 , 1 ) ;
F_316 ( V_387 , V_464 , 1 ) ;
return 0 ;
V_471:
F_11 ( & F_238 ( V_270 ) -> V_52 ) ;
V_469 = F_341 ( V_270 ) ;
if ( F_238 ( V_270 ) -> V_460 == V_460 ) {
F_343 ( V_270 , V_36 , 0 ) ;
} else {
T_2 V_472 = F_238 ( V_270 ) -> V_460 ;
T_2 V_343 ;
V_343 = V_460 - F_238 ( V_270 ) -> V_460 ;
F_238 ( V_270 ) -> V_460 = V_460 ;
V_468 = F_343 ( V_270 , V_343 , 0 ) ;
F_238 ( V_270 ) -> V_460 = V_460 - V_36 ;
V_343 = V_460 - V_472 ;
V_343 = F_343 ( V_270 , V_343 , 0 ) ;
F_238 ( V_270 ) -> V_460 = V_472 - V_36 ;
if ( V_343 > V_468 )
V_468 = V_343 - V_468 ;
else
V_468 = 0 ;
}
F_13 ( & F_238 ( V_270 ) -> V_52 ) ;
if ( V_469 )
V_468 += F_189 ( V_35 , V_469 ) ;
if ( V_468 ) {
F_323 ( V_35 , V_387 , V_468 ) ;
F_273 ( V_35 -> V_37 , L_14 ,
F_335 ( V_270 ) , V_468 , 0 ) ;
}
if ( V_467 )
F_46 ( & F_238 ( V_270 ) -> V_470 ) ;
return V_29 ;
}
void F_348 ( struct V_270 * V_270 , T_2 V_36 )
{
struct V_34 * V_35 = F_238 ( V_270 ) -> V_35 ;
T_2 V_468 = 0 ;
unsigned V_469 ;
V_36 = F_268 ( V_36 , V_35 -> V_347 ) ;
F_11 ( & F_238 ( V_270 ) -> V_52 ) ;
V_469 = F_341 ( V_270 ) ;
if ( V_36 )
V_468 = F_343 ( V_270 , V_36 , 0 ) ;
F_13 ( & F_238 ( V_270 ) -> V_52 ) ;
if ( V_469 > 0 )
V_468 += F_189 ( V_35 , V_469 ) ;
F_273 ( V_35 -> V_37 , L_14 ,
F_335 ( V_270 ) , V_468 , 0 ) ;
if ( V_35 -> V_37 -> V_205 ) {
F_339 ( V_35 , V_36 +
V_469 * V_35 -> V_88 ) ;
}
F_323 ( V_35 , & V_35 -> V_37 -> V_393 ,
V_468 ) ;
}
int F_349 ( struct V_270 * V_270 , T_2 V_36 )
{
int V_29 ;
V_29 = F_243 ( V_270 , V_36 ) ;
if ( V_29 )
return V_29 ;
V_29 = F_344 ( V_270 , V_36 ) ;
if ( V_29 ) {
F_245 ( V_270 , V_36 ) ;
return V_29 ;
}
return 0 ;
}
void F_350 ( struct V_270 * V_270 , T_2 V_36 )
{
F_348 ( V_270 , V_36 ) ;
F_245 ( V_270 , V_36 ) ;
}
static int F_351 ( struct V_34 * V_35 ,
T_2 V_27 , T_2 V_36 , int V_350 )
{
struct V_1 * V_2 = NULL ;
struct V_12 * V_13 = V_35 -> V_37 ;
T_2 V_473 = V_36 ;
T_2 V_474 ;
T_2 V_475 ;
int V_296 ;
F_11 ( & V_13 -> V_476 ) ;
V_474 = F_352 ( V_13 -> V_362 ) ;
if ( V_350 )
V_474 += V_36 ;
else
V_474 -= V_36 ;
F_353 ( V_13 -> V_362 , V_474 ) ;
F_13 ( & V_13 -> V_476 ) ;
while ( V_473 ) {
V_2 = F_68 ( V_13 , V_27 ) ;
if ( ! V_2 )
return - V_152 ;
if ( V_2 -> V_7 & ( V_297 |
V_298 |
V_299 ) )
V_296 = 2 ;
else
V_296 = 1 ;
if ( ! V_350 && V_2 -> V_3 == V_95 )
F_51 ( V_2 , 1 ) ;
V_475 = V_27 - V_2 -> V_21 . V_22 ;
F_8 ( V_475 > V_2 -> V_21 . V_33 ) ;
F_11 ( & V_2 -> V_104 -> V_52 ) ;
F_11 ( & V_2 -> V_52 ) ;
if ( F_242 ( V_35 , V_284 ) &&
V_2 -> V_276 < V_287 )
V_2 -> V_276 = V_287 ;
V_2 -> V_288 = 1 ;
V_474 = F_354 ( & V_2 -> V_134 ) ;
V_36 = F_295 ( V_473 , V_2 -> V_21 . V_33 - V_475 ) ;
if ( V_350 ) {
V_474 += V_36 ;
F_355 ( & V_2 -> V_134 , V_474 ) ;
V_2 -> V_10 -= V_36 ;
V_2 -> V_104 -> V_308 -= V_36 ;
V_2 -> V_104 -> V_295 += V_36 ;
V_2 -> V_104 -> V_301 += V_36 * V_296 ;
F_13 ( & V_2 -> V_52 ) ;
F_13 ( & V_2 -> V_104 -> V_52 ) ;
} else {
V_474 -= V_36 ;
if ( V_474 == 0 ) {
F_11 ( & V_13 -> V_477 ) ;
if ( F_204 ( & V_2 -> V_478 ) ) {
F_4 ( V_2 ) ;
F_64 ( & V_2 -> V_478 ,
& V_13 -> V_479 ) ;
}
F_13 ( & V_13 -> V_477 ) ;
}
F_355 ( & V_2 -> V_134 , V_474 ) ;
V_2 -> V_9 += V_36 ;
V_2 -> V_104 -> V_307 += V_36 ;
V_2 -> V_104 -> V_295 -= V_36 ;
V_2 -> V_104 -> V_301 -= V_36 * V_296 ;
F_13 ( & V_2 -> V_52 ) ;
F_13 ( & V_2 -> V_104 -> V_52 ) ;
F_356 ( V_13 -> V_59 ,
V_27 , V_27 + V_36 - 1 ,
V_40 | V_480 ) ;
}
F_6 ( V_2 ) ;
V_473 -= V_36 ;
V_27 += V_36 ;
}
return 0 ;
}
static T_2 V_26 ( struct V_34 * V_35 , T_2 V_481 )
{
struct V_1 * V_2 ;
T_2 V_27 ;
F_11 ( & V_35 -> V_37 -> V_18 ) ;
V_27 = V_35 -> V_37 -> V_26 ;
F_13 ( & V_35 -> V_37 -> V_18 ) ;
if ( V_27 < ( T_2 ) - 1 )
return V_27 ;
V_2 = F_67 ( V_35 -> V_37 , V_481 ) ;
if ( ! V_2 )
return 0 ;
V_27 = V_2 -> V_21 . V_22 ;
F_6 ( V_2 ) ;
return V_27 ;
}
static int F_357 ( struct V_34 * V_35 ,
struct V_1 * V_2 ,
T_2 V_27 , T_2 V_36 , int V_10 )
{
F_11 ( & V_2 -> V_104 -> V_52 ) ;
F_11 ( & V_2 -> V_52 ) ;
V_2 -> V_9 += V_36 ;
V_2 -> V_104 -> V_307 += V_36 ;
if ( V_10 ) {
V_2 -> V_10 -= V_36 ;
V_2 -> V_104 -> V_308 -= V_36 ;
}
F_13 ( & V_2 -> V_52 ) ;
F_13 ( & V_2 -> V_104 -> V_52 ) ;
F_356 ( V_35 -> V_37 -> V_59 , V_27 ,
V_27 + V_36 - 1 , V_40 | V_480 ) ;
if ( V_10 )
F_358 ( V_35 , V_27 , V_36 ) ;
return 0 ;
}
int F_163 ( struct V_34 * V_35 ,
T_2 V_27 , T_2 V_36 , int V_10 )
{
struct V_1 * V_2 ;
V_2 = F_68 ( V_35 -> V_37 , V_27 ) ;
F_30 ( ! V_2 ) ;
F_357 ( V_35 , V_2 , V_27 , V_36 , V_10 ) ;
F_6 ( V_2 ) ;
return 0 ;
}
int F_359 ( struct V_34 * V_35 ,
T_2 V_27 , T_2 V_36 )
{
struct V_1 * V_2 ;
int V_29 ;
V_2 = F_68 ( V_35 -> V_37 , V_27 ) ;
if ( ! V_2 )
return - V_482 ;
F_51 ( V_2 , 1 ) ;
F_357 ( V_35 , V_2 , V_27 , V_36 , 0 ) ;
V_29 = F_360 ( V_2 , V_27 , V_36 ) ;
F_6 ( V_2 ) ;
return V_29 ;
}
static int F_361 ( struct V_34 * V_35 , T_2 V_32 , T_2 V_36 )
{
int V_29 ;
struct V_1 * V_14 ;
struct V_50 * V_54 ;
V_14 = F_68 ( V_35 -> V_37 , V_32 ) ;
if ( ! V_14 )
return - V_482 ;
F_51 ( V_14 , 0 ) ;
V_54 = F_25 ( V_14 ) ;
if ( ! V_54 ) {
F_30 ( ! F_1 ( V_14 ) ) ;
V_29 = F_360 ( V_14 , V_32 , V_36 ) ;
} else {
F_35 ( & V_54 -> V_79 ) ;
if ( V_32 >= V_54 -> V_85 ) {
V_29 = F_17 ( V_35 , V_32 , V_36 ) ;
} else if ( V_32 + V_36 <= V_54 -> V_85 ) {
V_29 = F_360 ( V_14 ,
V_32 , V_36 ) ;
} else {
V_36 = V_54 -> V_85 - V_32 ;
V_29 = F_360 ( V_14 ,
V_32 , V_36 ) ;
if ( V_29 )
goto V_483;
V_36 = ( V_32 + V_36 ) -
V_54 -> V_85 ;
V_32 = V_54 -> V_85 ;
V_29 = F_17 ( V_35 , V_32 , V_36 ) ;
}
V_483:
F_46 ( & V_54 -> V_79 ) ;
F_26 ( V_54 ) ;
}
F_6 ( V_14 ) ;
return V_29 ;
}
int F_362 ( struct V_34 * log ,
struct V_66 * V_484 )
{
struct V_263 * V_134 ;
struct V_68 V_21 ;
int V_485 ;
int V_43 ;
if ( ! F_76 ( log -> V_37 , V_486 ) )
return 0 ;
for ( V_43 = 0 ; V_43 < F_38 ( V_484 ) ; V_43 ++ ) {
F_40 ( V_484 , & V_21 , V_43 ) ;
if ( V_21 . type != V_268 )
continue;
V_134 = F_78 ( V_484 , V_43 , struct V_263 ) ;
V_485 = F_223 ( V_484 , V_134 ) ;
if ( V_485 == V_269 )
continue;
if ( F_224 ( V_484 , V_134 ) == 0 )
continue;
V_21 . V_22 = F_224 ( V_484 , V_134 ) ;
V_21 . V_33 = F_225 ( V_484 , V_134 ) ;
F_361 ( log , V_21 . V_22 , V_21 . V_33 ) ;
}
return 0 ;
}
static int F_363 ( struct V_1 * V_2 ,
T_2 V_36 , int V_455 , int V_487 )
{
struct V_101 * V_104 = V_2 -> V_104 ;
int V_29 = 0 ;
F_11 ( & V_104 -> V_52 ) ;
F_11 ( & V_2 -> V_52 ) ;
if ( V_455 != V_488 ) {
if ( V_2 -> V_278 ) {
V_29 = - V_177 ;
} else {
V_2 -> V_10 += V_36 ;
V_104 -> V_308 += V_36 ;
if ( V_455 == V_489 ) {
F_273 ( V_2 -> V_37 ,
L_10 , V_104 -> V_7 ,
V_36 , 0 ) ;
V_104 -> V_310 -= V_36 ;
}
if ( V_487 )
V_2 -> V_285 += V_36 ;
}
} else {
if ( V_2 -> V_278 )
V_104 -> V_309 += V_36 ;
V_2 -> V_10 -= V_36 ;
V_104 -> V_308 -= V_36 ;
if ( V_487 )
V_2 -> V_285 -= V_36 ;
}
F_13 ( & V_2 -> V_52 ) ;
F_13 ( & V_104 -> V_52 ) ;
return V_29 ;
}
void F_364 ( struct V_108 * V_109 ,
struct V_34 * V_35 )
{
struct V_12 * V_37 = V_35 -> V_37 ;
struct V_50 * V_81 ;
struct V_50 * V_54 ;
struct V_1 * V_2 ;
F_63 ( & V_37 -> V_80 ) ;
F_365 (caching_ctl, next,
&fs_info->caching_block_groups, list) {
V_2 = V_54 -> V_14 ;
if ( F_1 ( V_2 ) ) {
V_2 -> V_98 = ( T_2 ) - 1 ;
F_366 ( & V_54 -> V_91 ) ;
F_26 ( V_54 ) ;
} else {
V_2 -> V_98 = V_54 -> V_85 ;
}
}
if ( V_37 -> V_59 == & V_37 -> V_38 [ 0 ] )
V_37 -> V_59 = & V_37 -> V_38 [ 1 ] ;
else
V_37 -> V_59 = & V_37 -> V_38 [ 0 ] ;
F_65 ( & V_37 -> V_80 ) ;
F_330 ( V_37 ) ;
}
static int F_367 ( struct V_34 * V_35 , T_2 V_32 , T_2 V_31 )
{
struct V_12 * V_37 = V_35 -> V_37 ;
struct V_1 * V_2 = NULL ;
struct V_101 * V_104 ;
struct V_239 * V_240 = & V_37 -> V_241 ;
T_2 V_49 ;
bool V_290 ;
while ( V_32 <= V_31 ) {
V_290 = false ;
if ( ! V_2 ||
V_32 >= V_2 -> V_21 . V_22 + V_2 -> V_21 . V_33 ) {
if ( V_2 )
F_6 ( V_2 ) ;
V_2 = F_68 ( V_37 , V_32 ) ;
F_30 ( ! V_2 ) ;
}
V_49 = V_2 -> V_21 . V_22 + V_2 -> V_21 . V_33 - V_32 ;
V_49 = F_295 ( V_49 , V_31 + 1 - V_32 ) ;
if ( V_32 < V_2 -> V_98 ) {
V_49 = F_295 ( V_49 , V_2 -> V_98 - V_32 ) ;
F_29 ( V_2 , V_32 , V_49 ) ;
}
V_32 += V_49 ;
V_104 = V_2 -> V_104 ;
F_11 ( & V_104 -> V_52 ) ;
F_11 ( & V_2 -> V_52 ) ;
V_2 -> V_9 -= V_49 ;
V_104 -> V_307 -= V_49 ;
F_368 ( & V_104 -> V_302 , - V_49 ) ;
if ( V_2 -> V_278 ) {
V_104 -> V_309 += V_49 ;
V_290 = true ;
}
F_13 ( & V_2 -> V_52 ) ;
if ( ! V_290 && V_240 -> V_104 == V_104 ) {
F_11 ( & V_240 -> V_52 ) ;
if ( ! V_240 -> V_107 ) {
V_49 = F_295 ( V_49 , V_240 -> V_57 -
V_240 -> V_10 ) ;
V_240 -> V_10 += V_49 ;
V_104 -> V_310 += V_49 ;
if ( V_240 -> V_10 >= V_240 -> V_57 )
V_240 -> V_107 = 1 ;
}
F_13 ( & V_240 -> V_52 ) ;
}
F_13 ( & V_104 -> V_52 ) ;
}
if ( V_2 )
F_6 ( V_2 ) ;
return 0 ;
}
int F_369 ( struct V_108 * V_109 ,
struct V_34 * V_35 )
{
struct V_12 * V_37 = V_35 -> V_37 ;
struct V_490 * V_491 ;
T_2 V_32 ;
T_2 V_31 ;
int V_29 ;
if ( V_109 -> V_216 )
return 0 ;
if ( V_37 -> V_59 == & V_37 -> V_38 [ 0 ] )
V_491 = & V_37 -> V_38 [ 1 ] ;
else
V_491 = & V_37 -> V_38 [ 0 ] ;
while ( 1 ) {
V_29 = F_28 ( V_491 , 0 , & V_32 , & V_31 ,
V_60 , NULL ) ;
if ( V_29 )
break;
if ( F_242 ( V_35 , V_492 ) )
V_29 = F_142 ( V_35 , V_32 ,
V_31 + 1 - V_32 , NULL ) ;
F_370 ( V_491 , V_32 , V_31 , V_40 ) ;
F_367 ( V_35 , V_32 , V_31 ) ;
F_47 () ;
}
return 0 ;
}
static void F_371 ( struct V_12 * V_37 , T_2 V_36 ,
T_2 V_132 , T_2 V_145 )
{
struct V_101 * V_104 ;
T_2 V_7 ;
if ( V_132 < V_142 ) {
if ( V_145 == V_493 )
V_7 = V_293 ;
else
V_7 = V_291 ;
} else {
V_7 = V_292 ;
}
V_104 = F_69 ( V_37 , V_7 ) ;
F_30 ( ! V_104 ) ;
F_368 ( & V_104 -> V_302 , V_36 ) ;
}
static int F_155 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
T_2 V_27 , T_2 V_36 , T_2 V_17 ,
T_2 V_145 , T_2 V_494 ,
T_2 V_495 , int V_158 ,
struct V_179 * V_128 ,
int V_200 )
{
struct V_68 V_21 ;
struct V_64 * V_65 ;
struct V_12 * V_13 = V_35 -> V_37 ;
struct V_34 * V_63 = V_13 -> V_63 ;
struct V_66 * V_67 ;
struct V_115 * V_116 ;
struct V_162 * V_163 ;
int V_29 ;
int V_183 ;
int V_496 = 0 ;
int V_497 = 0 ;
int V_498 = 1 ;
T_3 V_117 ;
T_2 V_111 ;
int V_159 = 0 ;
enum V_203 type = V_499 ;
bool V_172 = F_76 ( V_35 -> V_37 ,
V_120 ) ;
if ( ! V_13 -> V_205 || ! F_148 ( V_145 ) )
V_200 = 1 ;
V_65 = F_33 () ;
if ( ! V_65 )
return - V_72 ;
V_65 -> V_76 = 1 ;
V_65 -> V_206 = 1 ;
V_183 = V_494 >= V_142 ;
F_30 ( ! V_183 && V_158 != 1 ) ;
if ( V_183 )
V_172 = 0 ;
V_29 = F_134 ( V_109 , V_63 , V_65 , & V_163 ,
V_27 , V_36 , V_17 ,
V_145 , V_494 ,
V_495 ) ;
if ( V_29 == 0 ) {
V_496 = V_65 -> V_84 [ 0 ] ;
while ( V_496 >= 0 ) {
F_40 ( V_65 -> V_83 [ 0 ] , & V_21 ,
V_496 ) ;
if ( V_21 . V_22 != V_27 )
break;
if ( V_21 . type == V_77 &&
V_21 . V_33 == V_36 ) {
V_497 = 1 ;
break;
}
if ( V_21 . type == V_86 &&
V_21 . V_33 == V_494 ) {
V_497 = 1 ;
break;
}
if ( V_65 -> V_84 [ 0 ] - V_496 > 5 )
break;
V_496 -- ;
}
#ifdef F_81
V_117 = F_77 ( V_65 -> V_83 [ 0 ] , V_496 ) ;
if ( V_497 && V_117 < sizeof( * V_116 ) )
V_497 = 0 ;
#endif
if ( ! V_497 ) {
F_30 ( V_163 ) ;
V_29 = F_139 ( V_109 , V_63 , V_65 ,
NULL , V_158 ,
V_183 , & V_159 ) ;
if ( V_29 ) {
F_150 ( V_109 , V_63 , V_29 ) ;
goto V_73;
}
F_44 ( V_65 ) ;
V_65 -> V_206 = 1 ;
V_21 . V_22 = V_27 ;
V_21 . type = V_77 ;
V_21 . V_33 = V_36 ;
if ( ! V_183 && V_172 ) {
V_21 . type = V_86 ;
V_21 . V_33 = V_494 ;
}
V_29 = F_37 ( V_109 , V_63 ,
& V_21 , V_65 , - 1 , 1 ) ;
if ( V_29 > 0 && V_172 && V_65 -> V_84 [ 0 ] ) {
V_65 -> V_84 [ 0 ] -- ;
F_40 ( V_65 -> V_83 [ 0 ] , & V_21 ,
V_65 -> V_84 [ 0 ] ) ;
if ( V_21 . V_22 == V_27 &&
V_21 . type == V_77 &&
V_21 . V_33 == V_36 )
V_29 = 0 ;
}
if ( V_29 > 0 && V_172 ) {
V_172 = false ;
V_21 . V_22 = V_27 ;
V_21 . type = V_77 ;
V_21 . V_33 = V_36 ;
F_44 ( V_65 ) ;
V_29 = F_37 ( V_109 , V_63 ,
& V_21 , V_65 , - 1 , 1 ) ;
}
if ( V_29 ) {
F_372 ( V_13 , L_15 ,
V_29 , V_27 ) ;
if ( V_29 > 0 )
F_373 ( V_63 ,
V_65 -> V_83 [ 0 ] ) ;
}
if ( V_29 < 0 ) {
F_150 ( V_109 , V_63 , V_29 ) ;
goto V_73;
}
V_496 = V_65 -> V_84 [ 0 ] ;
}
} else if ( F_8 ( V_29 == - V_152 ) ) {
F_373 ( V_63 , V_65 -> V_83 [ 0 ] ) ;
F_372 ( V_13 ,
L_16 ,
V_27 , V_17 , V_145 , V_494 ,
V_495 ) ;
F_150 ( V_109 , V_63 , V_29 ) ;
goto V_73;
} else {
F_150 ( V_109 , V_63 , V_29 ) ;
goto V_73;
}
V_67 = V_65 -> V_83 [ 0 ] ;
V_117 = F_77 ( V_67 , V_496 ) ;
#ifdef F_81
if ( V_117 < sizeof( * V_116 ) ) {
F_30 ( V_497 || V_496 != V_65 -> V_84 [ 0 ] ) ;
V_29 = F_87 ( V_109 , V_63 , V_65 ,
V_494 , 0 ) ;
if ( V_29 < 0 ) {
F_150 ( V_109 , V_63 , V_29 ) ;
goto V_73;
}
F_44 ( V_65 ) ;
V_65 -> V_206 = 1 ;
V_21 . V_22 = V_27 ;
V_21 . type = V_77 ;
V_21 . V_33 = V_36 ;
V_29 = F_37 ( V_109 , V_63 , & V_21 , V_65 ,
- 1 , 1 ) ;
if ( V_29 ) {
F_372 ( V_13 , L_15 ,
V_29 , V_27 ) ;
F_373 ( V_63 , V_65 -> V_83 [ 0 ] ) ;
}
if ( V_29 < 0 ) {
F_150 ( V_109 , V_63 , V_29 ) ;
goto V_73;
}
V_496 = V_65 -> V_84 [ 0 ] ;
V_67 = V_65 -> V_83 [ 0 ] ;
V_117 = F_77 ( V_67 , V_496 ) ;
}
#endif
F_30 ( V_117 < sizeof( * V_116 ) ) ;
V_116 = F_78 ( V_67 , V_496 ,
struct V_115 ) ;
if ( V_494 < V_142 &&
V_21 . type == V_77 ) {
struct V_137 * V_138 ;
F_30 ( V_117 < sizeof( * V_116 ) + sizeof( * V_138 ) ) ;
V_138 = (struct V_137 * ) ( V_116 + 1 ) ;
F_8 ( V_494 != F_374 ( V_67 , V_138 ) ) ;
}
V_111 = F_79 ( V_67 , V_116 ) ;
if ( V_111 < V_158 ) {
F_372 ( V_13 , L_17
L_18 , V_158 , V_111 , V_27 ) ;
V_29 = - V_482 ;
F_150 ( V_109 , V_63 , V_29 ) ;
goto V_73;
}
V_111 -= V_158 ;
if ( V_111 > 0 ) {
type = V_500 ;
if ( V_128 )
F_130 ( V_128 , V_67 , V_116 ) ;
if ( V_163 ) {
F_30 ( ! V_497 ) ;
} else {
F_90 ( V_67 , V_116 , V_111 ) ;
F_95 ( V_67 ) ;
}
if ( V_497 ) {
V_29 = F_139 ( V_109 , V_63 , V_65 ,
V_163 , V_158 ,
V_183 , & V_159 ) ;
if ( V_29 ) {
F_150 ( V_109 , V_63 , V_29 ) ;
goto V_73;
}
}
F_371 ( V_35 -> V_37 , - V_36 , V_494 ,
V_145 ) ;
} else {
if ( V_497 ) {
F_30 ( V_183 && V_158 !=
F_118 ( V_35 , V_65 , V_163 ) ) ;
if ( V_163 ) {
F_30 ( V_65 -> V_84 [ 0 ] != V_496 ) ;
} else {
F_30 ( V_65 -> V_84 [ 0 ] != V_496 + 1 ) ;
V_65 -> V_84 [ 0 ] = V_496 ;
V_498 = 2 ;
}
}
V_159 = 1 ;
V_29 = F_375 ( V_109 , V_63 , V_65 , V_65 -> V_84 [ 0 ] ,
V_498 ) ;
if ( V_29 ) {
F_150 ( V_109 , V_63 , V_29 ) ;
goto V_73;
}
F_44 ( V_65 ) ;
if ( V_183 ) {
V_29 = F_167 ( V_109 , V_35 , V_27 , V_36 ) ;
if ( V_29 ) {
F_150 ( V_109 , V_63 , V_29 ) ;
goto V_73;
}
}
V_29 = F_351 ( V_35 , V_27 , V_36 , 0 ) ;
if ( V_29 ) {
F_150 ( V_109 , V_63 , V_29 ) ;
goto V_73;
}
}
F_44 ( V_65 ) ;
if ( ! V_29 && V_159 && ! V_200 ) {
int V_501 = 0 ;
if ( V_494 >= V_142 &&
type == V_500 )
V_501 = 1 ;
V_29 = F_149 ( V_109 , V_13 , V_145 ,
V_27 , V_36 , type ,
V_501 ) ;
}
V_73:
F_50 ( V_65 ) ;
return V_29 ;
}
static T_1 int F_376 ( struct V_108 * V_109 ,
struct V_34 * V_35 , T_2 V_27 )
{
struct V_112 * V_103 ;
struct V_113 * V_114 ;
int V_29 = 0 ;
V_114 = & V_109 -> V_126 -> V_114 ;
F_11 ( & V_114 -> V_52 ) ;
V_103 = F_84 ( V_109 , V_27 ) ;
if ( ! V_103 )
goto V_502;
F_11 ( & V_103 -> V_52 ) ;
if ( F_178 ( & V_103 -> V_212 ) )
goto V_73;
if ( V_103 -> V_128 ) {
if ( ! V_103 -> V_220 )
goto V_73;
F_176 ( V_103 -> V_128 ) ;
V_103 -> V_128 = NULL ;
}
if ( ! F_85 ( & V_103 -> V_79 ) )
goto V_73;
V_103 -> V_127 . V_224 = 0 ;
F_179 ( & V_103 -> V_226 , & V_114 -> V_227 ) ;
F_180 ( & V_114 -> V_228 ) ;
V_114 -> V_225 -- ;
if ( V_103 -> V_222 == 0 )
V_114 -> V_223 -- ;
V_103 -> V_222 = 0 ;
F_13 ( & V_103 -> V_52 ) ;
F_13 ( & V_114 -> V_52 ) ;
F_30 ( V_103 -> V_128 ) ;
if ( V_103 -> V_220 )
V_29 = 1 ;
F_46 ( & V_103 -> V_79 ) ;
F_86 ( & V_103 -> V_127 ) ;
return V_29 ;
V_73:
F_13 ( & V_103 -> V_52 ) ;
V_502:
F_13 ( & V_114 -> V_52 ) ;
return 0 ;
}
void F_377 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
struct V_66 * V_260 ,
T_2 V_17 , int V_159 )
{
struct V_1 * V_2 = NULL ;
int V_503 = 1 ;
int V_29 ;
if ( V_35 -> V_256 . V_22 != V_201 ) {
V_29 = F_145 ( V_35 -> V_37 , V_109 ,
V_260 -> V_32 , V_260 -> V_49 ,
V_17 , V_35 -> V_256 . V_22 ,
F_221 ( V_260 ) ,
V_214 , NULL , 0 ) ;
F_30 ( V_29 ) ;
}
if ( ! V_159 )
return;
V_2 = F_68 ( V_35 -> V_37 , V_260 -> V_32 ) ;
if ( F_378 ( V_260 ) == V_109 -> V_280 ) {
if ( V_35 -> V_256 . V_22 != V_201 ) {
V_29 = F_376 ( V_109 , V_35 , V_260 -> V_32 ) ;
if ( ! V_29 )
goto V_73;
}
if ( F_379 ( V_260 , V_504 ) ) {
F_357 ( V_35 , V_2 , V_260 -> V_32 , V_260 -> V_49 , 1 ) ;
goto V_73;
}
F_8 ( F_222 ( V_505 , & V_260 -> V_506 ) ) ;
F_29 ( V_2 , V_260 -> V_32 , V_260 -> V_49 ) ;
F_363 ( V_2 , V_260 -> V_49 , V_488 , 0 ) ;
F_358 ( V_35 , V_260 -> V_32 , V_260 -> V_49 ) ;
V_503 = 0 ;
}
V_73:
if ( V_503 )
F_371 ( V_35 -> V_37 , V_260 -> V_49 ,
F_221 ( V_260 ) ,
V_35 -> V_256 . V_22 ) ;
F_380 ( V_507 , & V_260 -> V_506 ) ;
F_6 ( V_2 ) ;
}
int V_267 ( struct V_108 * V_109 , struct V_34 * V_35 ,
T_2 V_27 , T_2 V_36 , T_2 V_17 , T_2 V_145 ,
T_2 V_132 , T_2 V_33 , int V_200 )
{
int V_29 ;
struct V_12 * V_37 = V_35 -> V_37 ;
if ( F_219 ( V_35 ) )
return 0 ;
F_371 ( V_35 -> V_37 , V_36 , V_132 , V_145 ) ;
if ( V_145 == V_201 ) {
F_8 ( V_132 >= V_142 ) ;
F_163 ( V_35 , V_27 , V_36 , 1 ) ;
V_29 = 0 ;
} else if ( V_132 < V_142 ) {
V_29 = F_145 ( V_37 , V_109 , V_27 ,
V_36 ,
V_17 , V_145 , ( int ) V_132 ,
V_214 , NULL , V_200 ) ;
} else {
V_29 = F_146 ( V_37 , V_109 , V_27 ,
V_36 ,
V_17 , V_145 , V_132 ,
V_33 , V_214 ,
NULL , V_200 ) ;
}
return V_29 ;
}
static T_1 void
F_381 ( struct V_1 * V_2 ,
T_2 V_36 )
{
struct V_50 * V_54 ;
V_54 = F_25 ( V_2 ) ;
if ( ! V_54 )
return;
F_296 ( V_54 -> V_89 , F_1 ( V_2 ) ||
( V_2 -> V_11 -> V_508 >= V_36 ) ) ;
F_26 ( V_54 ) ;
}
static T_1 int
F_382 ( struct V_1 * V_2 )
{
struct V_50 * V_54 ;
int V_29 = 0 ;
V_54 = F_25 ( V_2 ) ;
if ( ! V_54 )
return ( V_2 -> V_3 == V_5 ) ? - V_174 : 0 ;
F_296 ( V_54 -> V_89 , F_1 ( V_2 ) ) ;
if ( V_2 -> V_3 == V_5 )
V_29 = - V_174 ;
F_26 ( V_54 ) ;
return V_29 ;
}
int F_383 ( T_2 V_7 )
{
if ( V_7 & V_299 )
return V_509 ;
else if ( V_7 & V_298 )
return V_510 ;
else if ( V_7 & V_297 )
return V_511 ;
else if ( V_7 & V_338 )
return V_512 ;
else if ( V_7 & V_339 )
return V_513 ;
else if ( V_7 & V_340 )
return V_514 ;
return V_515 ;
}
int F_384 ( struct V_1 * V_2 )
{
return F_383 ( V_2 -> V_7 ) ;
}
static const char * F_385 ( enum V_516 type )
{
if ( type >= V_304 )
return NULL ;
return V_517 [ type ] ;
}
static inline void
F_386 ( struct V_1 * V_2 ,
int V_487 )
{
if ( V_487 )
F_36 ( & V_2 -> V_518 ) ;
}
static inline void
F_387 ( struct V_1 * V_2 ,
int V_487 )
{
F_4 ( V_2 ) ;
if ( V_487 )
F_36 ( & V_2 -> V_518 ) ;
}
static struct V_1 *
F_388 ( struct V_1 * V_14 ,
struct V_519 * V_520 ,
int V_487 )
{
struct V_1 * V_521 ;
bool V_522 = false ;
V_78:
F_11 ( & V_520 -> V_523 ) ;
if ( V_522 ) {
if ( V_521 == V_520 -> V_14 )
return V_521 ;
F_45 ( & V_521 -> V_518 ) ;
F_6 ( V_521 ) ;
}
V_521 = V_520 -> V_14 ;
if ( ! V_521 )
return NULL ;
if ( V_521 == V_14 )
return V_521 ;
F_4 ( V_521 ) ;
if ( ! V_487 )
return V_521 ;
if ( F_288 ( & V_521 -> V_518 ) )
return V_521 ;
F_13 ( & V_520 -> V_523 ) ;
F_36 ( & V_521 -> V_518 ) ;
V_522 = true ;
goto V_78;
}
static inline void
F_389 ( struct V_1 * V_2 ,
int V_487 )
{
if ( V_487 )
F_45 ( & V_2 -> V_518 ) ;
F_6 ( V_2 ) ;
}
static T_1 int F_390 ( struct V_34 * V_524 ,
T_2 V_36 , T_2 V_525 ,
T_2 V_526 , struct V_68 * V_211 ,
T_2 V_7 , int V_487 )
{
int V_29 = 0 ;
struct V_34 * V_35 = V_524 -> V_37 -> V_63 ;
struct V_519 * V_527 = NULL ;
struct V_1 * V_14 = NULL ;
T_2 V_481 = 0 ;
T_2 V_528 = 0 ;
int V_529 = 2 * 1024 * 1024 ;
struct V_101 * V_104 ;
int V_530 = 0 ;
int V_531 = F_383 ( V_7 ) ;
int V_532 = ( V_7 & V_292 ) ?
V_533 : V_489 ;
bool V_534 = false ;
bool V_535 = false ;
bool V_536 = true ;
bool V_537 = false ;
F_8 ( V_36 < V_35 -> V_347 ) ;
V_211 -> type = V_77 ;
V_211 -> V_22 = 0 ;
V_211 -> V_33 = 0 ;
F_391 ( V_524 , V_36 , V_525 , V_7 ) ;
V_104 = F_69 ( V_35 -> V_37 , V_7 ) ;
if ( ! V_104 ) {
F_372 ( V_35 -> V_37 , L_19 , V_7 ) ;
return - V_353 ;
}
if ( F_285 ( V_104 ) )
V_536 = false ;
if ( V_7 & V_291 && V_536 ) {
V_527 = & V_35 -> V_37 -> V_538 ;
if ( ! F_242 ( V_35 , V_539 ) )
V_529 = 64 * 1024 ;
}
if ( ( V_7 & V_292 ) && V_536 &&
F_242 ( V_35 , V_539 ) ) {
V_527 = & V_35 -> V_37 -> V_540 ;
}
if ( V_527 ) {
F_11 ( & V_527 -> V_52 ) ;
if ( V_527 -> V_14 )
V_526 = V_527 -> V_541 ;
F_13 ( & V_527 -> V_52 ) ;
}
V_481 = F_392 ( V_481 , V_26 ( V_35 , 0 ) ) ;
V_481 = F_392 ( V_481 , V_526 ) ;
if ( ! V_527 )
V_529 = 0 ;
if ( V_481 == V_526 ) {
V_14 = F_68 ( V_35 -> V_37 ,
V_481 ) ;
if ( V_14 && F_3 ( V_14 , V_7 ) &&
V_14 -> V_3 != V_95 ) {
F_36 ( & V_104 -> V_306 ) ;
if ( F_204 ( & V_14 -> V_91 ) ||
V_14 -> V_278 ) {
F_6 ( V_14 ) ;
F_45 ( & V_104 -> V_306 ) ;
} else {
V_531 = F_384 ( V_14 ) ;
F_386 ( V_14 , V_487 ) ;
goto V_542;
}
} else if ( V_14 ) {
F_6 ( V_14 ) ;
}
}
V_543:
V_537 = false ;
F_36 ( & V_104 -> V_306 ) ;
F_393 (block_group, &space_info->block_groups[index],
list) {
T_2 V_33 ;
int V_3 ;
F_387 ( V_14 , V_487 ) ;
V_481 = V_14 -> V_21 . V_22 ;
if ( ! F_3 ( V_14 , V_7 ) ) {
T_2 V_544 = V_297 |
V_298 |
V_339 |
V_340 |
V_299 ;
if ( ( V_7 & V_544 ) && ! ( V_14 -> V_7 & V_544 ) )
goto V_530;
}
V_542:
V_3 = F_1 ( V_14 ) ;
if ( F_312 ( ! V_3 ) ) {
V_29 = F_51 ( V_14 , 0 ) ;
F_30 ( V_29 < 0 ) ;
V_29 = 0 ;
}
if ( F_312 ( V_14 -> V_3 == V_5 ) )
goto V_530;
if ( F_312 ( V_14 -> V_278 ) )
goto V_530;
if ( V_527 ) {
struct V_1 * V_545 ;
unsigned long V_546 ;
V_545 = F_388 ( V_14 ,
V_527 ,
V_487 ) ;
if ( ! V_545 )
goto V_547;
if ( V_545 != V_14 &&
( V_545 -> V_278 ||
! F_3 ( V_545 , V_7 ) ) )
goto V_548;
V_33 = F_394 ( V_545 ,
V_527 ,
V_36 ,
V_545 -> V_21 . V_22 ,
& V_528 ) ;
if ( V_33 ) {
F_13 ( & V_527 -> V_523 ) ;
F_395 ( V_35 ,
V_545 ,
V_481 , V_36 ) ;
if ( V_545 != V_14 ) {
F_389 ( V_14 ,
V_487 ) ;
V_14 = V_545 ;
}
goto V_549;
}
F_8 ( V_527 -> V_14 != V_545 ) ;
V_548:
if ( V_530 >= V_550 &&
V_545 != V_14 ) {
F_13 ( & V_527 -> V_523 ) ;
F_389 ( V_545 ,
V_487 ) ;
goto V_551;
}
F_396 ( NULL , V_527 ) ;
if ( V_545 != V_14 )
F_389 ( V_545 ,
V_487 ) ;
V_547:
if ( V_530 >= V_550 ) {
F_13 ( & V_527 -> V_523 ) ;
goto V_551;
}
V_546 = F_34 (unsigned long,
empty_cluster + empty_size,
block_group->full_stripe_len) ;
V_29 = F_397 ( V_35 , V_14 ,
V_527 , V_481 ,
V_36 ,
V_546 ) ;
if ( V_29 == 0 ) {
V_33 = F_394 ( V_14 ,
V_527 ,
V_36 ,
V_481 ,
& V_528 ) ;
if ( V_33 ) {
F_13 ( & V_527 -> V_523 ) ;
F_395 ( V_35 ,
V_14 , V_481 ,
V_36 ) ;
goto V_549;
}
} else if ( ! V_3 && V_530 > V_552
&& ! V_534 ) {
F_13 ( & V_527 -> V_523 ) ;
V_534 = true ;
F_381 ( V_14 ,
V_36 + V_529 + V_525 ) ;
goto V_542;
}
F_396 ( NULL , V_527 ) ;
F_13 ( & V_527 -> V_523 ) ;
goto V_530;
}
V_551:
F_11 ( & V_14 -> V_11 -> V_553 ) ;
if ( V_3 &&
V_14 -> V_11 -> V_508 <
V_36 + V_529 + V_525 ) {
if ( V_14 -> V_11 -> V_508 >
V_528 )
V_528 =
V_14 -> V_11 -> V_508 ;
F_13 ( & V_14 -> V_11 -> V_553 ) ;
goto V_530;
}
F_13 ( & V_14 -> V_11 -> V_553 ) ;
V_33 = F_398 ( V_14 , V_481 ,
V_36 , V_525 ,
& V_528 ) ;
if ( ! V_33 && ! V_535 && ! V_3 &&
V_530 > V_552 ) {
F_381 ( V_14 ,
V_36 + V_525 ) ;
V_535 = true ;
goto V_542;
} else if ( ! V_33 ) {
if ( ! V_3 )
V_537 = true ;
goto V_530;
}
V_549:
V_481 = F_268 ( V_33 , V_35 -> V_554 ) ;
if ( V_481 + V_36 >
V_14 -> V_21 . V_22 + V_14 -> V_21 . V_33 ) {
F_29 ( V_14 , V_33 , V_36 ) ;
goto V_530;
}
if ( V_33 < V_481 )
F_29 ( V_14 , V_33 ,
V_481 - V_33 ) ;
F_30 ( V_33 > V_481 ) ;
V_29 = F_363 ( V_14 , V_36 ,
V_532 , V_487 ) ;
if ( V_29 == - V_177 ) {
F_29 ( V_14 , V_33 , V_36 ) ;
goto V_530;
}
V_211 -> V_22 = V_481 ;
V_211 -> V_33 = V_36 ;
F_399 ( V_524 , V_14 ,
V_481 , V_36 ) ;
F_389 ( V_14 , V_487 ) ;
break;
V_530:
V_534 = false ;
V_535 = false ;
F_30 ( V_531 != F_384 ( V_14 ) ) ;
F_389 ( V_14 , V_487 ) ;
}
F_45 ( & V_104 -> V_306 ) ;
if ( ! V_211 -> V_22 && V_530 >= V_555 && V_537 )
goto V_543;
if ( ! V_211 -> V_22 && ++ V_531 < V_304 )
goto V_543;
if ( ! V_211 -> V_22 && V_530 < V_550 ) {
V_531 = 0 ;
V_530 ++ ;
if ( V_530 == V_556 ) {
struct V_108 * V_109 ;
int V_557 = 0 ;
V_109 = V_348 -> V_349 ;
if ( V_109 )
V_557 = 1 ;
else
V_109 = F_193 ( V_35 ) ;
if ( F_194 ( V_109 ) ) {
V_29 = F_195 ( V_109 ) ;
goto V_73;
}
V_29 = F_270 ( V_109 , V_35 , V_7 ,
V_352 ) ;
if ( V_29 < 0 && V_29 != - V_353 )
F_150 ( V_109 ,
V_35 , V_29 ) ;
else
V_29 = 0 ;
if ( ! V_557 )
F_197 ( V_109 , V_35 ) ;
if ( V_29 )
goto V_73;
}
if ( V_530 == V_550 ) {
V_525 = 0 ;
V_529 = 0 ;
}
goto V_543;
} else if ( ! V_211 -> V_22 ) {
V_29 = - V_353 ;
} else if ( V_211 -> V_22 ) {
V_29 = 0 ;
}
V_73:
if ( V_29 == - V_353 )
V_211 -> V_33 = V_528 ;
return V_29 ;
}
static void F_283 ( struct V_101 * V_13 , T_2 V_343 ,
int V_558 )
{
struct V_1 * V_2 ;
int V_531 = 0 ;
F_11 ( & V_13 -> V_52 ) ;
F_400 ( V_559 L_20 ,
V_13 -> V_7 ,
V_13 -> V_294 - V_13 -> V_295 - V_13 -> V_307 -
V_13 -> V_308 - V_13 -> V_309 ,
( V_13 -> V_107 ) ? L_21 : L_22 ) ;
F_400 ( V_559 L_23
L_24 ,
V_13 -> V_294 , V_13 -> V_295 , V_13 -> V_307 ,
V_13 -> V_308 , V_13 -> V_310 ,
V_13 -> V_309 ) ;
F_13 ( & V_13 -> V_52 ) ;
if ( ! V_558 )
return;
F_36 ( & V_13 -> V_306 ) ;
V_78:
F_393 (cache, &info->block_groups[index], list) {
F_11 ( & V_2 -> V_52 ) ;
F_400 ( V_559 L_25
L_26
L_27 ,
V_2 -> V_21 . V_22 , V_2 -> V_21 . V_33 ,
F_354 ( & V_2 -> V_134 ) , V_2 -> V_9 ,
V_2 -> V_10 , V_2 -> V_278 ? L_28 : L_21 ) ;
F_401 ( V_2 , V_343 ) ;
F_13 ( & V_2 -> V_52 ) ;
}
if ( ++ V_531 < V_304 )
goto V_78;
F_45 ( & V_13 -> V_306 ) ;
}
int F_402 ( struct V_34 * V_35 ,
T_2 V_36 , T_2 V_560 ,
T_2 V_525 , T_2 V_526 ,
struct V_68 * V_211 , int V_183 , int V_487 )
{
bool V_561 = false ;
T_2 V_7 ;
int V_29 ;
V_7 = F_267 ( V_35 , V_183 ) ;
V_78:
F_8 ( V_36 < V_35 -> V_347 ) ;
V_29 = F_390 ( V_35 , V_36 , V_525 , V_526 , V_211 ,
V_7 , V_487 ) ;
if ( V_29 == - V_353 ) {
if ( ! V_561 && V_211 -> V_33 ) {
V_36 = F_295 ( V_36 >> 1 , V_211 -> V_33 ) ;
V_36 = F_403 ( V_36 , V_35 -> V_347 ) ;
V_36 = F_392 ( V_36 , V_560 ) ;
if ( V_36 == V_560 )
V_561 = true ;
goto V_78;
} else if ( F_242 ( V_35 , V_365 ) ) {
struct V_101 * V_357 ;
V_357 = F_69 ( V_35 -> V_37 , V_7 ) ;
F_372 ( V_35 -> V_37 , L_29 ,
V_7 , V_36 ) ;
if ( V_357 )
F_283 ( V_357 , V_36 , 1 ) ;
}
}
return V_29 ;
}
static int F_404 ( struct V_34 * V_35 ,
T_2 V_32 , T_2 V_49 ,
int V_503 , int V_487 )
{
struct V_1 * V_2 ;
int V_29 = 0 ;
V_2 = F_68 ( V_35 -> V_37 , V_32 ) ;
if ( ! V_2 ) {
F_372 ( V_35 -> V_37 , L_30 ,
V_32 ) ;
return - V_353 ;
}
if ( F_242 ( V_35 , V_492 ) )
V_29 = F_142 ( V_35 , V_32 , V_49 , NULL ) ;
if ( V_503 )
F_357 ( V_35 , V_2 , V_32 , V_49 , 1 ) ;
else {
F_29 ( V_2 , V_32 , V_49 ) ;
F_363 ( V_2 , V_49 , V_488 , V_487 ) ;
}
F_6 ( V_2 ) ;
F_358 ( V_35 , V_32 , V_49 ) ;
return V_29 ;
}
int F_405 ( struct V_34 * V_35 ,
T_2 V_32 , T_2 V_49 , int V_487 )
{
return F_404 ( V_35 , V_32 , V_49 , 0 , V_487 ) ;
}
int F_406 ( struct V_34 * V_35 ,
T_2 V_32 , T_2 V_49 )
{
return F_404 ( V_35 , V_32 , V_49 , 1 , 0 ) ;
}
static int F_154 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
T_2 V_17 , T_2 V_145 ,
T_2 V_7 , T_2 V_132 , T_2 V_33 ,
struct V_68 * V_211 , int V_131 )
{
int V_29 ;
struct V_12 * V_37 = V_35 -> V_37 ;
struct V_115 * V_562 ;
struct V_162 * V_163 ;
struct V_64 * V_65 ;
struct V_66 * V_67 ;
int type ;
T_3 V_57 ;
if ( V_17 > 0 )
type = V_153 ;
else
type = V_154 ;
V_57 = sizeof( * V_562 ) + F_125 ( type ) ;
V_65 = F_33 () ;
if ( ! V_65 )
return - V_72 ;
V_65 -> V_206 = 1 ;
V_29 = F_106 ( V_109 , V_37 -> V_63 , V_65 ,
V_211 , V_57 ) ;
if ( V_29 ) {
F_50 ( V_65 ) ;
return V_29 ;
}
V_67 = V_65 -> V_83 [ 0 ] ;
V_562 = F_78 ( V_67 , V_65 -> V_84 [ 0 ] ,
struct V_115 ) ;
F_90 ( V_67 , V_562 , V_131 ) ;
F_91 ( V_67 , V_562 , V_109 -> V_280 ) ;
F_92 ( V_67 , V_562 ,
V_7 | V_144 ) ;
V_163 = (struct V_162 * ) ( V_562 + 1 ) ;
F_132 ( V_67 , V_163 , type ) ;
if ( V_17 > 0 ) {
struct V_157 * V_150 ;
V_150 = (struct V_157 * ) ( V_163 + 1 ) ;
F_133 ( V_67 , V_163 , V_17 ) ;
F_107 ( V_67 , V_150 , V_131 ) ;
} else {
struct V_149 * V_150 ;
V_150 = (struct V_149 * ) ( & V_163 -> V_33 ) ;
F_109 ( V_67 , V_150 , V_145 ) ;
F_110 ( V_67 , V_150 , V_132 ) ;
F_111 ( V_67 , V_150 , V_33 ) ;
F_112 ( V_67 , V_150 , V_131 ) ;
}
F_95 ( V_65 -> V_83 [ 0 ] ) ;
F_50 ( V_65 ) ;
V_29 = F_149 ( V_109 , V_37 , V_145 ,
V_211 -> V_22 , V_211 -> V_33 ,
V_204 , 0 ) ;
if ( V_29 )
return V_29 ;
V_29 = F_351 ( V_35 , V_211 -> V_22 , V_211 -> V_33 , 1 ) ;
if ( V_29 ) {
F_372 ( V_37 , L_31 ,
V_211 -> V_22 , V_211 -> V_33 ) ;
F_83 () ;
}
F_407 ( V_35 , V_211 -> V_22 , V_211 -> V_33 ) ;
return V_29 ;
}
static int F_161 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
T_2 V_17 , T_2 V_145 ,
T_2 V_7 , struct V_463 * V_21 ,
int V_166 , struct V_68 * V_211 ,
int V_200 )
{
int V_29 ;
struct V_12 * V_37 = V_35 -> V_37 ;
struct V_115 * V_562 ;
struct V_137 * V_563 ;
struct V_162 * V_163 ;
struct V_64 * V_65 ;
struct V_66 * V_67 ;
T_3 V_57 = sizeof( * V_562 ) + sizeof( * V_163 ) ;
T_2 V_36 = V_211 -> V_33 ;
bool V_172 = F_76 ( V_35 -> V_37 ,
V_120 ) ;
if ( ! V_172 )
V_57 += sizeof( * V_563 ) ;
V_65 = F_33 () ;
if ( ! V_65 ) {
F_406 ( V_35 , V_211 -> V_22 ,
V_35 -> V_88 ) ;
return - V_72 ;
}
V_65 -> V_206 = 1 ;
V_29 = F_106 ( V_109 , V_37 -> V_63 , V_65 ,
V_211 , V_57 ) ;
if ( V_29 ) {
F_406 ( V_35 , V_211 -> V_22 ,
V_35 -> V_88 ) ;
F_50 ( V_65 ) ;
return V_29 ;
}
V_67 = V_65 -> V_83 [ 0 ] ;
V_562 = F_78 ( V_67 , V_65 -> V_84 [ 0 ] ,
struct V_115 ) ;
F_90 ( V_67 , V_562 , 1 ) ;
F_91 ( V_67 , V_562 , V_109 -> V_280 ) ;
F_92 ( V_67 , V_562 ,
V_7 | V_143 ) ;
if ( V_172 ) {
V_163 = (struct V_162 * ) ( V_562 + 1 ) ;
V_36 = V_35 -> V_88 ;
} else {
V_563 = (struct V_137 * ) ( V_562 + 1 ) ;
F_156 ( V_67 , V_563 , V_21 ) ;
F_94 ( V_67 , V_563 , V_166 ) ;
V_163 = (struct V_162 * ) ( V_563 + 1 ) ;
}
if ( V_17 > 0 ) {
F_30 ( ! ( V_7 & V_125 ) ) ;
F_132 ( V_67 , V_163 ,
V_164 ) ;
F_133 ( V_67 , V_163 , V_17 ) ;
} else {
F_132 ( V_67 , V_163 ,
V_165 ) ;
F_133 ( V_67 , V_163 , V_145 ) ;
}
F_95 ( V_67 ) ;
F_50 ( V_65 ) ;
if ( ! V_200 ) {
V_29 = F_149 ( V_109 , V_37 , V_145 ,
V_211 -> V_22 , V_36 ,
V_204 , 0 ) ;
if ( V_29 )
return V_29 ;
}
V_29 = F_351 ( V_35 , V_211 -> V_22 , V_35 -> V_88 , 1 ) ;
if ( V_29 ) {
F_372 ( V_37 , L_31 ,
V_211 -> V_22 , V_211 -> V_33 ) ;
F_83 () ;
}
F_407 ( V_35 , V_211 -> V_22 , V_35 -> V_88 ) ;
return V_29 ;
}
int F_408 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
T_2 V_145 , T_2 V_132 ,
T_2 V_33 , struct V_68 * V_211 )
{
int V_29 ;
F_30 ( V_145 == V_201 ) ;
V_29 = F_146 ( V_35 -> V_37 , V_109 , V_211 -> V_22 ,
V_211 -> V_33 , 0 ,
V_145 , V_132 , V_33 ,
V_229 , NULL , 0 ) ;
return V_29 ;
}
int F_409 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
T_2 V_145 , T_2 V_132 , T_2 V_33 ,
struct V_68 * V_211 )
{
int V_29 ;
struct V_1 * V_14 ;
if ( ! F_76 ( V_35 -> V_37 , V_486 ) ) {
V_29 = F_361 ( V_35 , V_211 -> V_22 , V_211 -> V_33 ) ;
if ( V_29 )
return V_29 ;
}
V_14 = F_68 ( V_35 -> V_37 , V_211 -> V_22 ) ;
if ( ! V_14 )
return - V_482 ;
V_29 = F_363 ( V_14 , V_211 -> V_33 ,
V_533 , 0 ) ;
F_30 ( V_29 ) ;
V_29 = F_154 ( V_109 , V_35 , 0 , V_145 ,
0 , V_132 , V_33 , V_211 , 1 ) ;
F_6 ( V_14 ) ;
return V_29 ;
}
static struct V_66 *
F_410 ( struct V_108 * V_109 , struct V_34 * V_35 ,
T_2 V_27 , T_3 V_564 , int V_166 )
{
struct V_66 * V_260 ;
V_260 = F_411 ( V_35 , V_27 , V_564 ) ;
if ( ! V_260 )
return F_412 ( - V_72 ) ;
F_413 ( V_260 , V_109 -> V_280 ) ;
F_414 ( V_35 -> V_256 . V_22 , V_260 , V_166 ) ;
F_415 ( V_260 ) ;
F_416 ( V_109 , V_35 , V_260 ) ;
F_380 ( V_565 , & V_260 -> V_506 ) ;
F_417 ( V_260 ) ;
F_418 ( V_260 ) ;
if ( V_35 -> V_256 . V_22 == V_201 ) {
V_260 -> V_566 = V_35 -> V_567 % 2 ;
if ( V_260 -> V_566 == 0 )
F_356 ( & V_35 -> V_568 , V_260 -> V_32 ,
V_260 -> V_32 + V_260 -> V_49 - 1 , V_40 ) ;
else
F_419 ( & V_35 -> V_568 , V_260 -> V_32 ,
V_260 -> V_32 + V_260 -> V_49 - 1 , V_40 ) ;
} else {
V_260 -> V_566 = - 1 ;
F_356 ( & V_109 -> V_126 -> V_569 , V_260 -> V_32 ,
V_260 -> V_32 + V_260 -> V_49 - 1 , V_40 ) ;
}
V_109 -> V_570 ++ ;
return V_260 ;
}
static struct V_239 *
F_420 ( struct V_108 * V_109 ,
struct V_34 * V_35 , T_3 V_564 )
{
struct V_239 * V_387 ;
struct V_239 * V_240 = & V_35 -> V_37 -> V_241 ;
int V_29 ;
bool V_571 = false ;
V_387 = F_315 ( V_109 , V_35 ) ;
if ( F_312 ( V_387 -> V_57 == 0 ) )
goto V_572;
V_78:
V_29 = F_313 ( V_387 , V_564 ) ;
if ( ! V_29 )
return V_387 ;
if ( V_387 -> V_573 )
return F_412 ( V_29 ) ;
if ( V_387 -> type == V_574 && ! V_571 ) {
V_571 = true ;
F_330 ( V_35 -> V_37 ) ;
goto V_78;
}
if ( F_242 ( V_35 , V_365 ) ) {
static F_421 ( V_575 ,
V_576 * 10 ,
1 ) ;
if ( F_422 ( & V_575 ) )
F_423 ( 1 , V_577
L_32 , V_29 ) ;
}
V_572:
V_29 = F_309 ( V_35 , V_387 , V_564 ,
V_398 ) ;
if ( ! V_29 )
return V_387 ;
if ( V_387 -> type != V_574 &&
V_387 -> V_104 == V_240 -> V_104 ) {
V_29 = F_313 ( V_240 , V_564 ) ;
if ( ! V_29 )
return V_240 ;
}
return F_412 ( V_29 ) ;
}
static void F_424 ( struct V_12 * V_37 ,
struct V_239 * V_387 , T_3 V_564 )
{
F_316 ( V_387 , V_564 , 0 ) ;
F_318 ( V_37 , V_387 , NULL , 0 ) ;
}
struct V_66 * F_425 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
T_2 V_17 , T_2 V_145 ,
struct V_463 * V_21 , int V_166 ,
T_2 V_578 , T_2 V_525 )
{
struct V_68 V_211 ;
struct V_239 * V_387 ;
struct V_66 * V_260 ;
T_2 V_7 = 0 ;
int V_29 ;
T_3 V_564 = V_35 -> V_88 ;
bool V_172 = F_76 ( V_35 -> V_37 ,
V_120 ) ;
if ( F_219 ( V_35 ) ) {
V_260 = F_410 ( V_109 , V_35 , V_35 -> V_579 ,
V_564 , V_166 ) ;
if ( ! F_194 ( V_260 ) )
V_35 -> V_579 += V_564 ;
return V_260 ;
}
V_387 = F_420 ( V_109 , V_35 , V_564 ) ;
if ( F_194 ( V_387 ) )
return F_426 ( V_387 ) ;
V_29 = F_402 ( V_35 , V_564 , V_564 ,
V_525 , V_578 , & V_211 , 0 , 0 ) ;
if ( V_29 ) {
F_424 ( V_35 -> V_37 , V_387 , V_564 ) ;
return F_412 ( V_29 ) ;
}
V_260 = F_410 ( V_109 , V_35 , V_211 . V_22 ,
V_564 , V_166 ) ;
F_30 ( F_194 ( V_260 ) ) ;
if ( V_145 == V_580 ) {
if ( V_17 == 0 )
V_17 = V_211 . V_22 ;
V_7 |= V_125 ;
} else
F_30 ( V_17 > 0 ) ;
if ( V_145 != V_201 ) {
struct V_179 * V_128 ;
V_128 = F_210 () ;
F_30 ( ! V_128 ) ;
if ( V_21 )
memcpy ( & V_128 -> V_21 , V_21 , sizeof( V_128 -> V_21 ) ) ;
else
memset ( & V_128 -> V_21 , 0 , sizeof( V_128 -> V_21 ) ) ;
V_128 -> V_130 = V_7 ;
if ( V_172 )
V_128 -> V_215 = 0 ;
else
V_128 -> V_215 = 1 ;
V_128 -> V_129 = 1 ;
V_128 -> V_183 = 0 ;
V_128 -> V_166 = V_166 ;
V_29 = F_145 ( V_35 -> V_37 , V_109 ,
V_211 . V_22 ,
V_211 . V_33 , V_17 , V_145 ,
V_166 , V_229 ,
V_128 , 0 ) ;
F_30 ( V_29 ) ;
}
return V_260 ;
}
static T_1 void F_427 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
struct V_581 * V_582 ,
struct V_64 * V_65 )
{
T_2 V_27 ;
T_2 V_283 ;
T_2 V_111 ;
T_2 V_7 ;
T_3 V_71 ;
T_3 V_564 ;
struct V_68 V_21 ;
struct V_66 * V_484 ;
int V_29 ;
int V_583 ;
int V_584 = 0 ;
if ( V_65 -> V_84 [ V_582 -> V_166 ] < V_582 -> V_585 ) {
V_582 -> V_586 = V_582 -> V_586 * 2 / 3 ;
V_582 -> V_586 = F_392 ( V_582 -> V_586 , 2 ) ;
} else {
V_582 -> V_586 = V_582 -> V_586 * 3 / 2 ;
V_582 -> V_586 = F_24 ( int , V_582 -> V_586 ,
F_428 ( V_35 ) ) ;
}
V_484 = V_65 -> V_83 [ V_582 -> V_166 ] ;
V_71 = F_38 ( V_484 ) ;
V_564 = V_35 -> V_88 ;
for ( V_583 = V_65 -> V_84 [ V_582 -> V_166 ] ; V_583 < V_71 ; V_583 ++ ) {
if ( V_584 >= V_582 -> V_586 )
break;
F_47 () ;
V_27 = F_227 ( V_484 , V_583 ) ;
V_283 = F_429 ( V_484 , V_583 ) ;
if ( V_583 == V_65 -> V_84 [ V_582 -> V_166 ] )
goto V_76;
if ( V_582 -> V_587 == V_588 &&
V_283 <= V_35 -> V_256 . V_33 )
continue;
V_29 = F_75 ( V_109 , V_35 , V_27 ,
V_582 -> V_166 - 1 , 1 , & V_111 ,
& V_7 ) ;
if ( V_29 < 0 )
continue;
F_30 ( V_111 == 0 ) ;
if ( V_582 -> V_587 == V_589 ) {
if ( V_111 == 1 )
goto V_76;
if ( V_582 -> V_166 == 1 &&
( V_7 & V_125 ) )
continue;
if ( ! V_582 -> V_590 ||
V_283 <= V_35 -> V_256 . V_33 )
continue;
F_123 ( V_484 , & V_21 , V_583 ) ;
V_29 = F_430 ( & V_21 ,
& V_582 -> V_591 ) ;
if ( V_29 < 0 )
continue;
} else {
if ( V_582 -> V_166 == 1 &&
( V_7 & V_125 ) )
continue;
}
V_76:
F_431 ( V_35 , V_27 , V_564 ) ;
V_584 ++ ;
}
V_582 -> V_585 = V_583 ;
}
static int F_432 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
struct V_66 * V_484 )
{
int V_44 = F_38 ( V_484 ) ;
int V_43 , V_592 , V_29 ;
struct V_68 V_21 ;
struct V_263 * V_264 ;
T_2 V_27 , V_36 ;
for ( V_43 = 0 ; V_43 < V_44 ; V_43 ++ ) {
F_40 ( V_484 , & V_21 , V_43 ) ;
if ( V_21 . type != V_268 )
continue;
V_264 = F_78 ( V_484 , V_43 , struct V_263 ) ;
V_592 = F_223 ( V_484 , V_264 ) ;
if ( V_592 == V_269 )
continue;
V_27 = F_224 ( V_484 , V_264 ) ;
if ( ! V_27 )
continue;
V_36 = F_225 ( V_484 , V_264 ) ;
V_29 = F_149 ( V_109 , V_35 -> V_37 ,
V_35 -> V_22 ,
V_27 , V_36 ,
V_593 , 0 ) ;
if ( V_29 )
return V_29 ;
}
return 0 ;
}
static int F_433 ( struct V_34 * V_35 ,
struct V_64 * V_65 , int V_594 )
{
int V_166 = 0 ;
int V_44 , V_583 ;
struct V_66 * V_484 ;
if ( V_594 == 0 )
return 1 ;
while ( V_166 <= V_594 ) {
V_484 = V_65 -> V_83 [ V_166 ] ;
V_44 = F_38 ( V_484 ) ;
V_65 -> V_84 [ V_166 ] ++ ;
V_583 = V_65 -> V_84 [ V_166 ] ;
if ( V_583 >= V_44 || V_166 == 0 ) {
if ( V_166 != V_594 ) {
F_434 ( V_484 , V_65 -> V_595 [ V_166 ] ) ;
V_65 -> V_595 [ V_166 ] = 0 ;
F_435 ( V_484 ) ;
V_65 -> V_83 [ V_166 ] = NULL ;
V_65 -> V_84 [ V_166 ] = 0 ;
}
} else {
break;
}
V_166 ++ ;
}
V_484 = V_65 -> V_83 [ V_594 ] ;
if ( V_65 -> V_84 [ V_594 ] >= F_38 ( V_484 ) )
return 1 ;
return 0 ;
}
static int F_436 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
struct V_66 * V_596 ,
T_2 V_597 ,
int V_594 )
{
int V_29 = 0 ;
int V_166 ;
struct V_66 * V_484 = V_596 ;
struct V_64 * V_65 = NULL ;
F_30 ( V_594 < 0 || V_594 > V_167 ) ;
F_30 ( V_596 == NULL ) ;
if ( ! V_35 -> V_37 -> V_205 )
return 0 ;
if ( ! F_437 ( V_596 ) ) {
V_29 = F_438 ( V_596 , V_597 ) ;
if ( V_29 )
goto V_73;
}
if ( V_594 == 0 ) {
V_29 = F_432 ( V_109 , V_35 , V_596 ) ;
goto V_73;
}
V_65 = F_33 () ;
if ( ! V_65 )
return - V_72 ;
F_439 ( V_596 ) ;
V_65 -> V_83 [ V_594 ] = V_596 ;
V_65 -> V_84 [ V_594 ] = 0 ;
V_65 -> V_595 [ V_594 ] = 0 ;
V_598:
V_166 = V_594 ;
while ( V_166 >= 0 ) {
if ( V_65 -> V_83 [ V_166 ] == NULL ) {
int V_599 ;
T_2 V_600 ;
T_2 V_601 ;
V_484 = V_65 -> V_83 [ V_166 + 1 ] ;
V_599 = V_65 -> V_84 [ V_166 + 1 ] ;
V_601 = F_227 ( V_484 , V_599 ) ;
V_600 = F_429 ( V_484 , V_599 ) ;
V_484 = F_440 ( V_35 , V_601 , V_600 ) ;
if ( ! V_484 || ! F_437 ( V_484 ) ) {
V_29 = - V_174 ;
goto V_73;
}
V_65 -> V_83 [ V_166 ] = V_484 ;
V_65 -> V_84 [ V_166 ] = 0 ;
F_441 ( V_484 ) ;
F_442 ( V_484 , V_602 ) ;
V_65 -> V_595 [ V_166 ] = V_603 ;
V_29 = F_149 ( V_109 , V_35 -> V_37 ,
V_35 -> V_22 ,
V_601 ,
V_35 -> V_88 ,
V_593 ,
0 ) ;
if ( V_29 )
goto V_73;
}
if ( V_166 == 0 ) {
V_29 = F_432 ( V_109 , V_35 , V_65 -> V_83 [ V_166 ] ) ;
if ( V_29 )
goto V_73;
V_29 = F_433 ( V_35 , V_65 , V_594 ) ;
if ( V_29 )
break;
goto V_598;
}
V_166 -- ;
}
V_29 = 0 ;
V_73:
F_50 ( V_65 ) ;
return V_29 ;
}
static T_1 int F_443 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
struct V_64 * V_65 ,
struct V_581 * V_582 , int V_604 )
{
int V_166 = V_582 -> V_166 ;
struct V_66 * V_484 = V_65 -> V_83 [ V_166 ] ;
T_2 V_605 = V_125 ;
int V_29 ;
if ( V_582 -> V_587 == V_588 &&
F_220 ( V_484 ) != V_35 -> V_256 . V_22 )
return 1 ;
if ( V_604 &&
( ( V_582 -> V_587 == V_589 && V_582 -> V_111 [ V_166 ] != 1 ) ||
( V_582 -> V_587 == V_588 && ! ( V_582 -> V_7 [ V_166 ] & V_605 ) ) ) ) {
F_30 ( ! V_65 -> V_595 [ V_166 ] ) ;
V_29 = F_75 ( V_109 , V_35 ,
V_484 -> V_32 , V_166 , 1 ,
& V_582 -> V_111 [ V_166 ] ,
& V_582 -> V_7 [ V_166 ] ) ;
F_30 ( V_29 == - V_72 ) ;
if ( V_29 )
return V_29 ;
F_30 ( V_582 -> V_111 [ V_166 ] == 0 ) ;
}
if ( V_582 -> V_587 == V_589 ) {
if ( V_582 -> V_111 [ V_166 ] > 1 )
return 1 ;
if ( V_65 -> V_595 [ V_166 ] && ! V_582 -> V_173 ) {
F_434 ( V_484 , V_65 -> V_595 [ V_166 ] ) ;
V_65 -> V_595 [ V_166 ] = 0 ;
}
return 0 ;
}
if ( ! ( V_582 -> V_7 [ V_166 ] & V_605 ) ) {
F_30 ( ! V_65 -> V_595 [ V_166 ] ) ;
V_29 = F_228 ( V_109 , V_35 , V_484 , 1 ) ;
F_30 ( V_29 ) ;
V_29 = F_229 ( V_109 , V_35 , V_484 , 0 ) ;
F_30 ( V_29 ) ;
V_29 = F_209 ( V_109 , V_35 , V_484 -> V_32 ,
V_484 -> V_49 , V_605 ,
F_221 ( V_484 ) , 0 ) ;
F_30 ( V_29 ) ;
V_582 -> V_7 [ V_166 ] |= V_605 ;
}
if ( V_65 -> V_595 [ V_166 ] && V_166 > 0 ) {
F_434 ( V_484 , V_65 -> V_595 [ V_166 ] ) ;
V_65 -> V_595 [ V_166 ] = 0 ;
}
return 0 ;
}
static T_1 int F_444 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
struct V_64 * V_65 ,
struct V_581 * V_582 , int * V_604 )
{
T_2 V_27 ;
T_2 V_283 ;
T_2 V_17 ;
T_3 V_564 ;
struct V_68 V_21 ;
struct V_66 * V_81 ;
int V_166 = V_582 -> V_166 ;
int V_76 = 0 ;
int V_29 = 0 ;
bool V_606 = false ;
V_283 = F_429 ( V_65 -> V_83 [ V_166 ] ,
V_65 -> V_84 [ V_166 ] ) ;
if ( V_582 -> V_587 == V_588 &&
V_283 <= V_35 -> V_256 . V_33 ) {
* V_604 = 1 ;
return 1 ;
}
V_27 = F_227 ( V_65 -> V_83 [ V_166 ] , V_65 -> V_84 [ V_166 ] ) ;
V_564 = V_35 -> V_88 ;
V_81 = F_445 ( V_35 , V_27 ) ;
if ( ! V_81 ) {
V_81 = F_411 ( V_35 , V_27 , V_564 ) ;
if ( ! V_81 )
return - V_72 ;
F_414 ( V_35 -> V_256 . V_22 , V_81 ,
V_166 - 1 ) ;
V_76 = 1 ;
}
F_415 ( V_81 ) ;
F_417 ( V_81 ) ;
V_29 = F_75 ( V_109 , V_35 , V_27 , V_166 - 1 , 1 ,
& V_582 -> V_111 [ V_166 - 1 ] ,
& V_582 -> V_7 [ V_166 - 1 ] ) ;
if ( V_29 < 0 ) {
F_446 ( V_81 ) ;
return V_29 ;
}
if ( F_312 ( V_582 -> V_111 [ V_166 - 1 ] == 0 ) ) {
F_372 ( V_35 -> V_37 , L_33 ) ;
F_83 () ;
}
* V_604 = 0 ;
if ( V_582 -> V_587 == V_589 ) {
if ( V_582 -> V_111 [ V_166 - 1 ] > 1 ) {
V_606 = true ;
if ( V_166 == 1 &&
( V_582 -> V_7 [ 0 ] & V_125 ) )
goto V_607;
if ( ! V_582 -> V_590 ||
V_283 <= V_35 -> V_256 . V_33 )
goto V_607;
F_123 ( V_65 -> V_83 [ V_166 ] , & V_21 ,
V_65 -> V_84 [ V_166 ] ) ;
V_29 = F_430 ( & V_21 , & V_582 -> V_591 ) ;
if ( V_29 < 0 )
goto V_607;
V_582 -> V_587 = V_588 ;
V_582 -> V_608 = V_166 - 1 ;
}
} else {
if ( V_166 == 1 &&
( V_582 -> V_7 [ 0 ] & V_125 ) )
goto V_607;
}
if ( ! F_447 ( V_81 , V_283 , 0 ) ) {
F_446 ( V_81 ) ;
F_435 ( V_81 ) ;
V_81 = NULL ;
* V_604 = 1 ;
}
if ( ! V_81 ) {
if ( V_76 && V_166 == 1 )
F_427 ( V_109 , V_35 , V_582 , V_65 ) ;
V_81 = F_440 ( V_35 , V_27 , V_283 ) ;
if ( ! V_81 || ! F_437 ( V_81 ) ) {
F_435 ( V_81 ) ;
return - V_174 ;
}
F_415 ( V_81 ) ;
F_417 ( V_81 ) ;
}
V_166 -- ;
F_30 ( V_166 != F_221 ( V_81 ) ) ;
V_65 -> V_83 [ V_166 ] = V_81 ;
V_65 -> V_84 [ V_166 ] = 0 ;
V_65 -> V_595 [ V_166 ] = V_609 ;
V_582 -> V_166 = V_166 ;
if ( V_582 -> V_166 == 1 )
V_582 -> V_585 = 0 ;
return 0 ;
V_607:
V_582 -> V_111 [ V_166 - 1 ] = 0 ;
V_582 -> V_7 [ V_166 - 1 ] = 0 ;
if ( V_582 -> V_587 == V_589 ) {
if ( V_582 -> V_7 [ V_166 ] & V_125 ) {
V_17 = V_65 -> V_83 [ V_166 ] -> V_32 ;
} else {
F_30 ( V_35 -> V_256 . V_22 !=
F_220 ( V_65 -> V_83 [ V_166 ] ) ) ;
V_17 = 0 ;
}
if ( V_606 ) {
V_29 = F_436 ( V_109 , V_35 , V_81 ,
V_283 , V_166 - 1 ) ;
if ( V_29 ) {
F_448 ( V_610 L_34
L_35
L_36 ,
V_35 -> V_37 -> V_381 -> V_611 , V_29 ) ;
}
}
V_29 = V_267 ( V_109 , V_35 , V_27 , V_564 , V_17 ,
V_35 -> V_256 . V_22 , V_166 - 1 , 0 , 0 ) ;
F_30 ( V_29 ) ;
}
F_446 ( V_81 ) ;
F_435 ( V_81 ) ;
* V_604 = 1 ;
return 1 ;
}
static T_1 int F_449 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
struct V_64 * V_65 ,
struct V_581 * V_582 )
{
int V_29 ;
int V_166 = V_582 -> V_166 ;
struct V_66 * V_484 = V_65 -> V_83 [ V_166 ] ;
T_2 V_17 = 0 ;
if ( V_582 -> V_587 == V_588 ) {
F_30 ( V_582 -> V_608 < V_166 ) ;
if ( V_166 < V_582 -> V_608 )
goto V_73;
V_29 = F_41 ( V_65 , V_166 + 1 , & V_582 -> V_591 ) ;
if ( V_29 > 0 )
V_582 -> V_590 = 0 ;
V_582 -> V_587 = V_589 ;
V_582 -> V_608 = - 1 ;
V_65 -> V_84 [ V_166 ] = 0 ;
if ( ! V_65 -> V_595 [ V_166 ] ) {
F_30 ( V_166 == 0 ) ;
F_415 ( V_484 ) ;
F_417 ( V_484 ) ;
V_65 -> V_595 [ V_166 ] = V_609 ;
V_29 = F_75 ( V_109 , V_35 ,
V_484 -> V_32 , V_166 , 1 ,
& V_582 -> V_111 [ V_166 ] ,
& V_582 -> V_7 [ V_166 ] ) ;
if ( V_29 < 0 ) {
F_434 ( V_484 , V_65 -> V_595 [ V_166 ] ) ;
V_65 -> V_595 [ V_166 ] = 0 ;
return V_29 ;
}
F_30 ( V_582 -> V_111 [ V_166 ] == 0 ) ;
if ( V_582 -> V_111 [ V_166 ] == 1 ) {
F_434 ( V_484 , V_65 -> V_595 [ V_166 ] ) ;
V_65 -> V_595 [ V_166 ] = 0 ;
return 1 ;
}
}
}
F_30 ( V_582 -> V_111 [ V_166 ] > 1 && ! V_65 -> V_595 [ V_166 ] ) ;
if ( V_582 -> V_111 [ V_166 ] == 1 ) {
if ( V_166 == 0 ) {
if ( V_582 -> V_7 [ V_166 ] & V_125 )
V_29 = F_229 ( V_109 , V_35 , V_484 , 1 ) ;
else
V_29 = F_229 ( V_109 , V_35 , V_484 , 0 ) ;
F_30 ( V_29 ) ;
V_29 = F_432 ( V_109 , V_35 , V_484 ) ;
if ( V_29 ) {
F_448 ( V_610 L_34
L_37
L_36 ,
V_35 -> V_37 -> V_381 -> V_611 , V_29 ) ;
}
}
if ( ! V_65 -> V_595 [ V_166 ] &&
F_378 ( V_484 ) == V_109 -> V_280 ) {
F_415 ( V_484 ) ;
F_417 ( V_484 ) ;
V_65 -> V_595 [ V_166 ] = V_609 ;
}
F_416 ( V_109 , V_35 , V_484 ) ;
}
if ( V_484 == V_35 -> V_127 ) {
if ( V_582 -> V_7 [ V_166 ] & V_125 )
V_17 = V_484 -> V_32 ;
else
F_30 ( V_35 -> V_256 . V_22 !=
F_220 ( V_484 ) ) ;
} else {
if ( V_582 -> V_7 [ V_166 + 1 ] & V_125 )
V_17 = V_65 -> V_83 [ V_166 + 1 ] -> V_32 ;
else
F_30 ( V_35 -> V_256 . V_22 !=
F_220 ( V_65 -> V_83 [ V_166 + 1 ] ) ) ;
}
F_377 ( V_109 , V_35 , V_484 , V_17 , V_582 -> V_111 [ V_166 ] == 1 ) ;
V_73:
V_582 -> V_111 [ V_166 ] = 0 ;
V_582 -> V_7 [ V_166 ] = 0 ;
return 0 ;
}
static T_1 int F_450 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
struct V_64 * V_65 ,
struct V_581 * V_582 )
{
int V_166 = V_582 -> V_166 ;
int V_604 = 1 ;
int V_29 ;
while ( V_166 >= 0 ) {
V_29 = F_443 ( V_109 , V_35 , V_65 , V_582 , V_604 ) ;
if ( V_29 > 0 )
break;
if ( V_166 == 0 )
break;
if ( V_65 -> V_84 [ V_166 ] >=
F_38 ( V_65 -> V_83 [ V_166 ] ) )
break;
V_29 = F_444 ( V_109 , V_35 , V_65 , V_582 , & V_604 ) ;
if ( V_29 > 0 ) {
V_65 -> V_84 [ V_166 ] ++ ;
continue;
} else if ( V_29 < 0 )
return V_29 ;
V_166 = V_582 -> V_166 ;
}
return 0 ;
}
static T_1 int F_451 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
struct V_64 * V_65 ,
struct V_581 * V_582 , int V_612 )
{
int V_166 = V_582 -> V_166 ;
int V_29 ;
V_65 -> V_84 [ V_166 ] = F_38 ( V_65 -> V_83 [ V_166 ] ) ;
while ( V_166 < V_612 && V_65 -> V_83 [ V_166 ] ) {
V_582 -> V_166 = V_166 ;
if ( V_65 -> V_84 [ V_166 ] + 1 <
F_38 ( V_65 -> V_83 [ V_166 ] ) ) {
V_65 -> V_84 [ V_166 ] ++ ;
return 0 ;
} else {
V_29 = F_449 ( V_109 , V_35 , V_65 , V_582 ) ;
if ( V_29 > 0 )
return 0 ;
if ( V_65 -> V_595 [ V_166 ] ) {
F_434 ( V_65 -> V_83 [ V_166 ] ,
V_65 -> V_595 [ V_166 ] ) ;
V_65 -> V_595 [ V_166 ] = 0 ;
}
F_435 ( V_65 -> V_83 [ V_166 ] ) ;
V_65 -> V_83 [ V_166 ] = NULL ;
V_166 ++ ;
}
}
return 1 ;
}
int F_452 ( struct V_34 * V_35 ,
struct V_239 * V_387 , int V_590 ,
int V_613 )
{
struct V_64 * V_65 ;
struct V_108 * V_109 ;
struct V_34 * V_87 = V_35 -> V_37 -> V_87 ;
struct V_614 * V_257 = & V_35 -> V_257 ;
struct V_581 * V_582 ;
struct V_68 V_21 ;
int V_82 = 0 ;
int V_29 ;
int V_166 ;
bool V_615 = false ;
F_177 ( V_35 -> V_37 , L_38 , V_35 -> V_22 ) ;
V_65 = F_33 () ;
if ( ! V_65 ) {
V_82 = - V_72 ;
goto V_73;
}
V_582 = F_53 ( sizeof( * V_582 ) , V_40 ) ;
if ( ! V_582 ) {
F_50 ( V_65 ) ;
V_82 = - V_72 ;
goto V_73;
}
V_109 = F_453 ( V_87 , 0 ) ;
if ( F_194 ( V_109 ) ) {
V_82 = F_195 ( V_109 ) ;
goto V_122;
}
if ( V_387 )
V_109 -> V_387 = V_387 ;
if ( F_454 ( & V_257 -> V_616 ) == 0 ) {
V_166 = F_221 ( V_35 -> V_127 ) ;
V_65 -> V_83 [ V_166 ] = F_455 ( V_35 ) ;
F_417 ( V_65 -> V_83 [ V_166 ] ) ;
V_65 -> V_84 [ V_166 ] = 0 ;
V_65 -> V_595 [ V_166 ] = V_609 ;
memset ( & V_582 -> V_591 , 0 ,
sizeof( V_582 -> V_591 ) ) ;
} else {
F_456 ( & V_21 , & V_257 -> V_616 ) ;
memcpy ( & V_582 -> V_591 , & V_21 ,
sizeof( V_582 -> V_591 ) ) ;
V_166 = V_257 -> V_617 ;
F_30 ( V_166 == 0 ) ;
V_65 -> V_618 = V_166 ;
V_29 = F_37 ( NULL , V_35 , & V_21 , V_65 , 0 , 0 ) ;
V_65 -> V_618 = 0 ;
if ( V_29 < 0 ) {
V_82 = V_29 ;
goto V_619;
}
F_8 ( V_29 > 0 ) ;
F_128 ( V_65 , 0 ) ;
V_166 = F_221 ( V_35 -> V_127 ) ;
while ( 1 ) {
F_415 ( V_65 -> V_83 [ V_166 ] ) ;
F_417 ( V_65 -> V_83 [ V_166 ] ) ;
V_65 -> V_595 [ V_166 ] = V_609 ;
V_29 = F_75 ( V_109 , V_35 ,
V_65 -> V_83 [ V_166 ] -> V_32 ,
V_166 , 1 , & V_582 -> V_111 [ V_166 ] ,
& V_582 -> V_7 [ V_166 ] ) ;
if ( V_29 < 0 ) {
V_82 = V_29 ;
goto V_619;
}
F_30 ( V_582 -> V_111 [ V_166 ] == 0 ) ;
if ( V_166 == V_257 -> V_617 )
break;
F_446 ( V_65 -> V_83 [ V_166 ] ) ;
V_65 -> V_595 [ V_166 ] = 0 ;
F_8 ( V_582 -> V_111 [ V_166 ] != 1 ) ;
V_166 -- ;
}
}
V_582 -> V_166 = V_166 ;
V_582 -> V_608 = - 1 ;
V_582 -> V_587 = V_589 ;
V_582 -> V_590 = V_590 ;
V_582 -> V_173 = 0 ;
V_582 -> V_613 = V_613 ;
V_582 -> V_586 = F_428 ( V_35 ) ;
while ( 1 ) {
V_29 = F_450 ( V_109 , V_35 , V_65 , V_582 ) ;
if ( V_29 < 0 ) {
V_82 = V_29 ;
break;
}
V_29 = F_451 ( V_109 , V_35 , V_65 , V_582 , V_167 ) ;
if ( V_29 < 0 ) {
V_82 = V_29 ;
break;
}
if ( V_29 > 0 ) {
F_30 ( V_582 -> V_587 != V_589 ) ;
break;
}
if ( V_582 -> V_587 == V_589 ) {
V_166 = V_582 -> V_166 ;
F_457 ( V_65 -> V_83 [ V_166 ] ,
& V_257 -> V_616 ,
V_65 -> V_84 [ V_166 ] ) ;
V_257 -> V_617 = V_166 ;
}
F_30 ( V_582 -> V_166 == 0 ) ;
if ( F_458 ( V_109 , V_87 ) ||
( ! V_613 && F_459 ( V_35 ) ) ) {
V_29 = F_460 ( V_109 , V_87 ,
& V_35 -> V_256 ,
V_257 ) ;
if ( V_29 ) {
F_150 ( V_109 , V_87 , V_29 ) ;
V_82 = V_29 ;
goto V_619;
}
V_29 = F_207 ( V_109 ,
V_35 -> V_37 ) ;
if ( V_29 )
F_448 ( V_610 L_39
L_40
L_41
L_42
L_43 , V_29 ) ;
F_461 ( V_109 , V_87 ) ;
if ( ! V_613 && F_459 ( V_35 ) ) {
F_462 ( L_44 ) ;
V_82 = - V_177 ;
goto V_122;
}
V_109 = F_453 ( V_87 , 0 ) ;
if ( F_194 ( V_109 ) ) {
V_82 = F_195 ( V_109 ) ;
goto V_122;
}
if ( V_387 )
V_109 -> V_387 = V_387 ;
}
}
F_44 ( V_65 ) ;
if ( V_82 )
goto V_619;
V_29 = F_463 ( V_109 , V_87 , & V_35 -> V_256 ) ;
if ( V_29 ) {
F_150 ( V_109 , V_87 , V_29 ) ;
goto V_619;
}
if ( V_35 -> V_256 . V_22 != V_580 ) {
V_29 = F_464 ( V_87 , & V_35 -> V_256 , V_65 ,
NULL , NULL ) ;
if ( V_29 < 0 ) {
F_150 ( V_109 , V_87 , V_29 ) ;
V_82 = V_29 ;
goto V_619;
} else if ( V_29 > 0 ) {
F_465 ( V_109 , V_87 ,
V_35 -> V_256 . V_22 ) ;
}
}
if ( F_222 ( V_620 , & V_35 -> V_266 ) ) {
F_466 ( V_87 -> V_37 , V_35 ) ;
} else {
F_435 ( V_35 -> V_127 ) ;
F_435 ( V_35 -> V_621 ) ;
F_467 ( V_35 ) ;
}
V_615 = true ;
V_619:
V_29 = F_207 ( V_109 , V_87 -> V_37 ) ;
if ( V_29 )
F_448 ( V_610 L_39
L_40
L_41
L_42
L_43 , V_29 ) ;
F_461 ( V_109 , V_87 ) ;
V_122:
F_9 ( V_582 ) ;
F_50 ( V_65 ) ;
V_73:
if ( ! V_613 && V_615 == false )
F_468 ( V_35 ) ;
if ( V_82 && V_82 != - V_177 )
F_469 ( V_35 -> V_37 , V_82 ) ;
return V_82 ;
}
int F_470 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
struct V_66 * V_127 ,
struct V_66 * V_17 )
{
struct V_64 * V_65 ;
struct V_581 * V_582 ;
int V_166 ;
int V_622 ;
int V_29 = 0 ;
int V_623 ;
F_30 ( V_35 -> V_256 . V_22 != V_580 ) ;
V_65 = F_33 () ;
if ( ! V_65 )
return - V_72 ;
V_582 = F_53 ( sizeof( * V_582 ) , V_40 ) ;
if ( ! V_582 ) {
F_50 ( V_65 ) ;
return - V_72 ;
}
F_471 ( V_17 ) ;
V_622 = F_221 ( V_17 ) ;
F_439 ( V_17 ) ;
V_65 -> V_83 [ V_622 ] = V_17 ;
V_65 -> V_84 [ V_622 ] = F_38 ( V_17 ) ;
F_471 ( V_127 ) ;
V_166 = F_221 ( V_127 ) ;
V_65 -> V_83 [ V_166 ] = V_127 ;
V_65 -> V_84 [ V_166 ] = 0 ;
V_65 -> V_595 [ V_166 ] = V_609 ;
V_582 -> V_111 [ V_622 ] = 1 ;
V_582 -> V_7 [ V_622 ] = V_125 ;
V_582 -> V_166 = V_166 ;
V_582 -> V_608 = - 1 ;
V_582 -> V_587 = V_589 ;
V_582 -> V_590 = 0 ;
V_582 -> V_173 = 1 ;
V_582 -> V_613 = 1 ;
V_582 -> V_586 = F_428 ( V_35 ) ;
while ( 1 ) {
V_623 = F_450 ( V_109 , V_35 , V_65 , V_582 ) ;
if ( V_623 < 0 ) {
V_29 = V_623 ;
break;
}
V_623 = F_451 ( V_109 , V_35 , V_65 , V_582 , V_622 ) ;
if ( V_623 < 0 )
V_29 = V_623 ;
if ( V_623 != 0 )
break;
}
F_9 ( V_582 ) ;
F_50 ( V_65 ) ;
return V_29 ;
}
static T_2 F_472 ( struct V_34 * V_35 , T_2 V_7 )
{
T_2 V_333 ;
T_2 V_624 ;
V_624 = F_261 ( V_35 -> V_37 , V_7 ) ;
if ( V_624 )
return F_263 ( V_624 ) ;
V_333 = V_35 -> V_37 -> V_334 -> V_335 ;
V_624 = V_338 |
V_339 | V_340 |
V_298 | V_299 ;
if ( V_333 == 1 ) {
V_624 |= V_297 ;
V_624 = V_7 & ~ V_624 ;
if ( V_7 & V_338 )
return V_624 ;
if ( V_7 & ( V_298 |
V_299 ) )
return V_624 | V_297 ;
} else {
if ( V_7 & V_624 )
return V_7 ;
V_624 |= V_297 ;
V_624 = V_7 & ~ V_624 ;
if ( V_7 & V_297 )
return V_624 | V_298 ;
}
return V_7 ;
}
static int F_473 ( struct V_1 * V_2 , int V_358 )
{
struct V_101 * V_357 = V_2 -> V_104 ;
T_2 V_36 ;
T_2 V_625 ;
int V_29 = - V_353 ;
if ( ( V_357 -> V_7 &
( V_293 | V_291 ) ) &&
! V_358 )
V_625 = 1 * 1024 * 1024 ;
else
V_625 = 0 ;
F_11 ( & V_357 -> V_52 ) ;
F_11 ( & V_2 -> V_52 ) ;
if ( V_2 -> V_278 ) {
V_29 = 0 ;
goto V_73;
}
V_36 = V_2 -> V_21 . V_33 - V_2 -> V_10 - V_2 -> V_9 -
V_2 -> V_46 - F_354 ( & V_2 -> V_134 ) ;
if ( V_357 -> V_295 + V_357 -> V_308 + V_357 -> V_307 +
V_357 -> V_310 + V_357 -> V_309 + V_36 +
V_625 <= V_357 -> V_294 ) {
V_357 -> V_309 += V_36 ;
V_2 -> V_278 = 1 ;
V_29 = 0 ;
}
V_73:
F_13 ( & V_2 -> V_52 ) ;
F_13 ( & V_357 -> V_52 ) ;
return V_29 ;
}
int F_474 ( struct V_34 * V_35 ,
struct V_1 * V_2 )
{
struct V_108 * V_109 ;
T_2 V_626 ;
int V_29 ;
F_30 ( V_2 -> V_278 ) ;
V_109 = F_193 ( V_35 ) ;
if ( F_194 ( V_109 ) )
return F_195 ( V_109 ) ;
V_626 = F_472 ( V_35 , V_2 -> V_7 ) ;
if ( V_626 != V_2 -> V_7 ) {
V_29 = F_270 ( V_109 , V_35 , V_626 ,
V_352 ) ;
if ( V_29 < 0 )
goto V_73;
}
V_29 = F_473 ( V_2 , 0 ) ;
if ( ! V_29 )
goto V_73;
V_626 = F_264 ( V_35 , V_2 -> V_104 -> V_7 ) ;
V_29 = F_270 ( V_109 , V_35 , V_626 ,
V_352 ) ;
if ( V_29 < 0 )
goto V_73;
V_29 = F_473 ( V_2 , 0 ) ;
V_73:
F_197 ( V_109 , V_35 ) ;
return V_29 ;
}
int F_475 ( struct V_108 * V_109 ,
struct V_34 * V_35 , T_2 type )
{
T_2 V_626 = F_264 ( V_35 , type ) ;
return F_270 ( V_109 , V_35 , V_626 ,
V_352 ) ;
}
static T_2 F_476 ( struct V_102 * V_627 )
{
struct V_1 * V_14 ;
T_2 V_628 = 0 ;
int V_296 ;
F_393 (block_group, groups_list, list) {
F_11 ( & V_14 -> V_52 ) ;
if ( ! V_14 -> V_278 ) {
F_13 ( & V_14 -> V_52 ) ;
continue;
}
if ( V_14 -> V_7 & ( V_298 |
V_299 |
V_297 ) )
V_296 = 2 ;
else
V_296 = 1 ;
V_628 += ( V_14 -> V_21 . V_33 -
F_354 ( & V_14 -> V_134 ) ) *
V_296 ;
F_13 ( & V_14 -> V_52 ) ;
}
return V_628 ;
}
T_2 F_477 ( struct V_101 * V_357 )
{
int V_43 ;
T_2 V_628 = 0 ;
F_11 ( & V_357 -> V_52 ) ;
for ( V_43 = 0 ; V_43 < V_304 ; V_43 ++ )
if ( ! F_204 ( & V_357 -> V_305 [ V_43 ] ) )
V_628 += F_476 (
& V_357 -> V_305 [ V_43 ] ) ;
F_13 ( & V_357 -> V_52 ) ;
return V_628 ;
}
void F_478 ( struct V_34 * V_35 ,
struct V_1 * V_2 )
{
struct V_101 * V_357 = V_2 -> V_104 ;
T_2 V_36 ;
F_30 ( ! V_2 -> V_278 ) ;
F_11 ( & V_357 -> V_52 ) ;
F_11 ( & V_2 -> V_52 ) ;
V_36 = V_2 -> V_21 . V_33 - V_2 -> V_10 - V_2 -> V_9 -
V_2 -> V_46 - F_354 ( & V_2 -> V_134 ) ;
V_357 -> V_309 -= V_36 ;
V_2 -> V_278 = 0 ;
F_13 ( & V_2 -> V_52 ) ;
F_13 ( & V_357 -> V_52 ) ;
}
int F_479 ( struct V_34 * V_35 , T_2 V_27 )
{
struct V_1 * V_14 ;
struct V_101 * V_104 ;
struct V_629 * V_334 = V_35 -> V_37 -> V_334 ;
struct V_630 * V_631 ;
struct V_108 * V_109 ;
T_2 V_632 ;
T_2 V_633 = 1 ;
T_2 V_634 = 0 ;
T_2 V_328 ;
int V_531 ;
int V_107 = 0 ;
int V_29 = 0 ;
V_14 = F_68 ( V_35 -> V_37 , V_27 ) ;
if ( ! V_14 )
return - 1 ;
V_632 = F_354 ( & V_14 -> V_134 ) ;
if ( ! V_632 )
goto V_73;
V_104 = V_14 -> V_104 ;
F_11 ( & V_104 -> V_52 ) ;
V_107 = V_104 -> V_107 ;
if ( ( V_104 -> V_294 != V_14 -> V_21 . V_33 ) &&
( V_104 -> V_295 + V_104 -> V_308 +
V_104 -> V_307 + V_104 -> V_309 +
V_632 < V_104 -> V_294 ) ) {
F_13 ( & V_104 -> V_52 ) ;
goto V_73;
}
F_13 ( & V_104 -> V_52 ) ;
V_29 = - 1 ;
V_328 = F_261 ( V_35 -> V_37 , V_14 -> V_7 ) ;
if ( V_328 ) {
V_531 = F_383 ( F_263 ( V_328 ) ) ;
} else {
if ( V_107 )
goto V_73;
V_531 = F_384 ( V_14 ) ;
}
if ( V_531 == V_509 ) {
V_633 = 4 ;
V_632 >>= 1 ;
} else if ( V_531 == V_510 ) {
V_633 = 2 ;
} else if ( V_531 == V_511 ) {
V_632 <<= 1 ;
} else if ( V_531 == V_512 ) {
V_633 = V_334 -> V_335 ;
F_480 ( V_632 , V_633 ) ;
}
V_109 = F_193 ( V_35 ) ;
if ( F_194 ( V_109 ) ) {
V_29 = F_195 ( V_109 ) ;
goto V_73;
}
F_35 ( & V_35 -> V_37 -> V_368 ) ;
F_393 (device, &fs_devices->alloc_list, dev_alloc_list) {
T_2 V_635 ;
if ( V_631 -> V_294 > V_631 -> V_295 + V_632 &&
! V_631 -> V_636 ) {
V_29 = F_481 ( V_109 , V_631 , V_632 ,
& V_635 , NULL ) ;
if ( ! V_29 )
V_634 ++ ;
if ( V_634 >= V_633 )
break;
V_29 = - 1 ;
}
}
F_46 ( & V_35 -> V_37 -> V_368 ) ;
F_197 ( V_109 , V_35 ) ;
V_73:
F_6 ( V_14 ) ;
return V_29 ;
}
static int F_482 ( struct V_34 * V_35 ,
struct V_64 * V_65 , struct V_68 * V_21 )
{
int V_29 = 0 ;
struct V_68 V_139 ;
struct V_66 * V_67 ;
int V_583 ;
V_29 = F_37 ( NULL , V_35 , V_21 , V_65 , 0 , 0 ) ;
if ( V_29 < 0 )
goto V_73;
while ( 1 ) {
V_583 = V_65 -> V_84 [ 0 ] ;
V_67 = V_65 -> V_83 [ 0 ] ;
if ( V_583 >= F_38 ( V_67 ) ) {
V_29 = F_48 ( V_35 , V_65 ) ;
if ( V_29 == 0 )
continue;
if ( V_29 < 0 )
goto V_73;
break;
}
F_40 ( V_67 , & V_139 , V_583 ) ;
if ( V_139 . V_22 >= V_21 -> V_22 &&
V_139 . type == V_178 ) {
V_29 = 0 ;
goto V_73;
}
V_65 -> V_84 [ 0 ] ++ ;
}
V_73:
return V_29 ;
}
void F_483 ( struct V_12 * V_13 )
{
struct V_1 * V_14 ;
T_2 V_70 = 0 ;
while ( 1 ) {
struct V_270 * V_270 ;
V_14 = F_67 ( V_13 , V_70 ) ;
while ( V_14 ) {
F_11 ( & V_14 -> V_52 ) ;
if ( V_14 -> V_163 )
break;
F_13 ( & V_14 -> V_52 ) ;
V_14 = F_233 ( V_13 -> V_87 ,
V_14 ) ;
}
if ( ! V_14 ) {
if ( V_70 == 0 )
break;
V_70 = 0 ;
continue;
}
V_270 = V_14 -> V_270 ;
V_14 -> V_163 = 0 ;
V_14 -> V_270 = NULL ;
F_13 ( & V_14 -> V_52 ) ;
F_246 ( V_270 ) ;
V_70 = V_14 -> V_21 . V_22 + V_14 -> V_21 . V_33 ;
F_6 ( V_14 ) ;
}
}
int F_484 ( struct V_12 * V_13 )
{
struct V_1 * V_14 ;
struct V_101 * V_104 ;
struct V_50 * V_54 ;
struct V_15 * V_30 ;
F_63 ( & V_13 -> V_80 ) ;
while ( ! F_204 ( & V_13 -> V_99 ) ) {
V_54 = F_485 ( V_13 -> V_99 . V_81 ,
struct V_50 , V_91 ) ;
F_486 ( & V_54 -> V_91 ) ;
F_26 ( V_54 ) ;
}
F_65 ( & V_13 -> V_80 ) ;
F_11 ( & V_13 -> V_477 ) ;
while ( ! F_204 ( & V_13 -> V_479 ) ) {
V_14 = F_487 ( & V_13 -> V_479 ,
struct V_1 ,
V_478 ) ;
F_366 ( & V_14 -> V_478 ) ;
F_6 ( V_14 ) ;
}
F_13 ( & V_13 -> V_477 ) ;
F_11 ( & V_13 -> V_18 ) ;
while ( ( V_30 = F_185 ( & V_13 -> V_19 ) ) != NULL ) {
V_14 = F_12 ( V_30 , struct V_1 ,
V_20 ) ;
F_179 ( & V_14 -> V_20 ,
& V_13 -> V_19 ) ;
F_13 ( & V_13 -> V_18 ) ;
F_63 ( & V_14 -> V_104 -> V_306 ) ;
F_486 ( & V_14 -> V_91 ) ;
F_65 ( & V_14 -> V_104 -> V_306 ) ;
if ( V_14 -> V_3 == V_53 )
F_382 ( V_14 ) ;
if ( V_14 -> V_3 == V_95 ||
V_14 -> V_3 == V_5 )
F_19 ( V_13 -> V_63 , V_14 ) ;
F_488 ( V_14 ) ;
F_6 ( V_14 ) ;
F_11 ( & V_13 -> V_18 ) ;
}
F_13 ( & V_13 -> V_18 ) ;
F_489 () ;
F_332 ( V_13 ) ;
while ( ! F_204 ( & V_13 -> V_104 ) ) {
int V_43 ;
V_104 = F_485 ( V_13 -> V_104 . V_81 ,
struct V_101 ,
V_91 ) ;
if ( F_242 ( V_13 -> V_87 , V_365 ) ) {
if ( F_8 ( V_104 -> V_307 > 0 ||
V_104 -> V_308 > 0 ||
V_104 -> V_310 > 0 ) ) {
F_283 ( V_104 , 0 , 0 ) ;
}
}
F_486 ( & V_104 -> V_91 ) ;
for ( V_43 = 0 ; V_43 < V_304 ; V_43 ++ ) {
struct V_637 * V_315 ;
V_315 = V_104 -> V_638 [ V_43 ] ;
V_104 -> V_638 [ V_43 ] = NULL ;
if ( V_315 ) {
F_490 ( V_315 ) ;
F_491 ( V_315 ) ;
}
}
F_490 ( & V_104 -> V_315 ) ;
F_491 ( & V_104 -> V_315 ) ;
}
return 0 ;
}
static void F_492 ( struct V_101 * V_104 ,
struct V_1 * V_2 )
{
int V_531 = F_384 ( V_2 ) ;
bool V_237 = false ;
F_63 ( & V_104 -> V_306 ) ;
if ( F_204 ( & V_104 -> V_305 [ V_531 ] ) )
V_237 = true ;
F_64 ( & V_2 -> V_91 , & V_104 -> V_305 [ V_531 ] ) ;
F_65 ( & V_104 -> V_306 ) ;
if ( V_237 ) {
struct V_639 * V_640 ;
int V_29 ;
V_640 = F_53 ( sizeof( * V_640 ) , V_40 ) ;
if ( ! V_640 )
goto V_641;
V_640 -> V_642 = V_531 ;
F_493 ( & V_640 -> V_315 , & V_643 ) ;
V_29 = F_494 ( & V_640 -> V_315 , & V_104 -> V_315 ,
L_8 , F_385 ( V_531 ) ) ;
if ( V_29 ) {
F_491 ( & V_640 -> V_315 ) ;
goto V_641;
}
V_104 -> V_638 [ V_531 ] = & V_640 -> V_315 ;
}
return;
V_641:
F_495 ( L_45 ) ;
}
static struct V_1 *
F_496 ( struct V_34 * V_35 , T_2 V_32 , T_2 V_57 )
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
V_2 -> V_21 . V_33 = V_57 ;
V_2 -> V_21 . type = V_178 ;
V_2 -> V_347 = V_35 -> V_347 ;
V_2 -> V_37 = V_35 -> V_37 ;
V_2 -> V_644 = F_497 ( V_35 ,
& V_35 -> V_37 -> V_48 ,
V_32 ) ;
F_57 ( & V_2 -> V_8 , 1 ) ;
F_254 ( & V_2 -> V_52 ) ;
F_253 ( & V_2 -> V_518 ) ;
F_54 ( & V_2 -> V_91 ) ;
F_54 ( & V_2 -> V_645 ) ;
F_54 ( & V_2 -> V_478 ) ;
F_498 ( V_2 ) ;
return V_2 ;
}
int F_499 ( struct V_34 * V_35 )
{
struct V_64 * V_65 ;
int V_29 ;
struct V_1 * V_2 ;
struct V_12 * V_13 = V_35 -> V_37 ;
struct V_101 * V_104 ;
struct V_68 V_21 ;
struct V_68 V_139 ;
struct V_66 * V_67 ;
int V_646 = 0 ;
T_2 V_647 ;
V_35 = V_13 -> V_63 ;
V_21 . V_22 = 0 ;
V_21 . V_33 = 0 ;
V_21 . type = V_178 ;
V_65 = F_33 () ;
if ( ! V_65 )
return - V_72 ;
V_65 -> V_76 = 1 ;
V_647 = F_500 ( V_35 -> V_37 -> V_362 ) ;
if ( F_242 ( V_35 , V_284 ) &&
F_501 ( V_35 -> V_37 -> V_362 ) != V_647 )
V_646 = 1 ;
if ( F_242 ( V_35 , V_648 ) )
V_646 = 1 ;
while ( 1 ) {
V_29 = F_482 ( V_35 , V_65 , & V_21 ) ;
if ( V_29 > 0 )
break;
if ( V_29 != 0 )
goto error;
V_67 = V_65 -> V_83 [ 0 ] ;
F_40 ( V_67 , & V_139 , V_65 -> V_84 [ 0 ] ) ;
V_2 = F_496 ( V_35 , V_139 . V_22 ,
V_139 . V_33 ) ;
if ( ! V_2 ) {
V_29 = - V_72 ;
goto error;
}
if ( V_646 ) {
V_2 -> V_276 = V_287 ;
if ( F_242 ( V_35 , V_284 ) )
V_2 -> V_288 = 1 ;
}
F_502 ( V_67 , & V_2 -> V_134 ,
F_231 ( V_67 , V_65 -> V_84 [ 0 ] ) ,
sizeof( V_2 -> V_134 ) ) ;
V_2 -> V_7 = F_503 ( & V_2 -> V_134 ) ;
V_21 . V_22 = V_139 . V_22 + V_139 . V_33 ;
F_44 ( V_65 ) ;
V_29 = F_21 ( V_35 , V_2 ) ;
if ( V_29 ) {
F_19 ( V_35 , V_2 ) ;
F_6 ( V_2 ) ;
goto error;
}
if ( V_139 . V_33 == F_354 ( & V_2 -> V_134 ) ) {
V_2 -> V_98 = ( T_2 ) - 1 ;
V_2 -> V_3 = V_4 ;
F_19 ( V_35 , V_2 ) ;
} else if ( F_354 ( & V_2 -> V_134 ) == 0 ) {
V_2 -> V_98 = ( T_2 ) - 1 ;
V_2 -> V_3 = V_4 ;
F_27 ( V_2 , V_35 -> V_37 ,
V_139 . V_22 ,
V_139 . V_22 +
V_139 . V_33 ) ;
F_19 ( V_35 , V_2 ) ;
}
V_29 = F_10 ( V_35 -> V_37 , V_2 ) ;
if ( V_29 ) {
F_488 ( V_2 ) ;
F_6 ( V_2 ) ;
goto error;
}
V_29 = F_251 ( V_13 , V_2 -> V_7 , V_139 . V_33 ,
F_354 ( & V_2 -> V_134 ) ,
& V_104 ) ;
if ( V_29 ) {
F_488 ( V_2 ) ;
F_11 ( & V_13 -> V_18 ) ;
F_179 ( & V_2 -> V_20 ,
& V_13 -> V_19 ) ;
F_13 ( & V_13 -> V_18 ) ;
F_6 ( V_2 ) ;
goto error;
}
V_2 -> V_104 = V_104 ;
F_11 ( & V_2 -> V_104 -> V_52 ) ;
V_2 -> V_104 -> V_309 += V_2 -> V_46 ;
F_13 ( & V_2 -> V_104 -> V_52 ) ;
F_492 ( V_104 , V_2 ) ;
F_257 ( V_35 -> V_37 , V_2 -> V_7 ) ;
if ( F_504 ( V_35 , V_2 -> V_21 . V_22 ) ) {
F_473 ( V_2 , 1 ) ;
} else if ( F_354 ( & V_2 -> V_134 ) == 0 ) {
F_11 ( & V_13 -> V_477 ) ;
if ( F_204 ( & V_2 -> V_478 ) ) {
F_4 ( V_2 ) ;
F_64 ( & V_2 -> V_478 ,
& V_13 -> V_479 ) ;
}
F_13 ( & V_13 -> V_477 ) ;
}
}
F_71 (space_info, &root->fs_info->space_info, list) {
if ( ! ( F_264 ( V_35 , V_104 -> V_7 ) &
( V_299 |
V_298 |
V_339 |
V_340 |
V_297 ) ) )
continue;
F_393 (cache,
&space_info->block_groups[BTRFS_RAID_RAID0],
list)
F_473 ( V_2 , 1 ) ;
F_393 (cache,
&space_info->block_groups[BTRFS_RAID_SINGLE],
list)
F_473 ( V_2 , 1 ) ;
}
F_331 ( V_13 ) ;
V_29 = 0 ;
error:
F_50 ( V_65 ) ;
return V_29 ;
}
void F_205 ( struct V_108 * V_109 ,
struct V_34 * V_35 )
{
struct V_1 * V_14 , * V_336 ;
struct V_34 * V_63 = V_35 -> V_37 -> V_63 ;
struct V_649 V_134 ;
struct V_68 V_21 ;
int V_29 = 0 ;
F_365 (block_group, tmp, &trans->new_bgs, bg_list) {
F_366 ( & V_14 -> V_478 ) ;
if ( V_29 )
continue;
F_11 ( & V_14 -> V_52 ) ;
memcpy ( & V_134 , & V_14 -> V_134 , sizeof( V_134 ) ) ;
memcpy ( & V_21 , & V_14 -> V_21 , sizeof( V_21 ) ) ;
F_13 ( & V_14 -> V_52 ) ;
V_29 = F_505 ( V_109 , V_63 , & V_21 , & V_134 ,
sizeof( V_134 ) ) ;
if ( V_29 )
F_150 ( V_109 , V_63 , V_29 ) ;
V_29 = F_506 ( V_109 , V_63 ,
V_21 . V_22 , V_21 . V_33 ) ;
if ( V_29 )
F_150 ( V_109 , V_63 , V_29 ) ;
}
}
int F_507 ( struct V_108 * V_109 ,
struct V_34 * V_35 , T_2 V_295 ,
T_2 type , T_2 V_650 , T_2 V_651 ,
T_2 V_57 )
{
int V_29 ;
struct V_34 * V_63 ;
struct V_1 * V_2 ;
V_63 = V_35 -> V_37 -> V_63 ;
F_508 ( V_35 -> V_37 , V_109 ) ;
V_2 = F_496 ( V_35 , V_651 , V_57 ) ;
if ( ! V_2 )
return - V_72 ;
F_355 ( & V_2 -> V_134 , V_295 ) ;
F_509 ( & V_2 -> V_134 , V_650 ) ;
F_510 ( & V_2 -> V_134 , type ) ;
V_2 -> V_7 = type ;
V_2 -> V_98 = ( T_2 ) - 1 ;
V_2 -> V_3 = V_4 ;
V_29 = F_21 ( V_35 , V_2 ) ;
if ( V_29 ) {
F_19 ( V_35 , V_2 ) ;
F_6 ( V_2 ) ;
return V_29 ;
}
F_27 ( V_2 , V_35 -> V_37 , V_651 ,
V_651 + V_57 ) ;
F_19 ( V_35 , V_2 ) ;
V_29 = F_10 ( V_35 -> V_37 , V_2 ) ;
if ( V_29 ) {
F_488 ( V_2 ) ;
F_6 ( V_2 ) ;
return V_29 ;
}
V_29 = F_251 ( V_35 -> V_37 , V_2 -> V_7 , V_57 , V_295 ,
& V_2 -> V_104 ) ;
if ( V_29 ) {
F_488 ( V_2 ) ;
F_11 ( & V_35 -> V_37 -> V_18 ) ;
F_179 ( & V_2 -> V_20 ,
& V_35 -> V_37 -> V_19 ) ;
F_13 ( & V_35 -> V_37 -> V_18 ) ;
F_6 ( V_2 ) ;
return V_29 ;
}
F_330 ( V_35 -> V_37 ) ;
F_11 ( & V_2 -> V_104 -> V_52 ) ;
V_2 -> V_104 -> V_309 += V_2 -> V_46 ;
F_13 ( & V_2 -> V_104 -> V_52 ) ;
F_492 ( V_2 -> V_104 , V_2 ) ;
F_64 ( & V_2 -> V_478 , & V_109 -> V_254 ) ;
F_257 ( V_63 -> V_37 , type ) ;
return 0 ;
}
static void F_511 ( struct V_12 * V_37 , T_2 V_7 )
{
T_2 V_319 = F_258 ( V_7 ) &
V_320 ;
F_259 ( & V_37 -> V_321 ) ;
if ( V_7 & V_292 )
V_37 -> V_322 &= ~ V_319 ;
if ( V_7 & V_291 )
V_37 -> V_323 &= ~ V_319 ;
if ( V_7 & V_293 )
V_37 -> V_324 &= ~ V_319 ;
F_260 ( & V_37 -> V_321 ) ;
}
int F_512 ( struct V_108 * V_109 ,
struct V_34 * V_35 , T_2 V_652 )
{
struct V_64 * V_65 ;
struct V_1 * V_14 ;
struct V_519 * V_520 ;
struct V_34 * V_87 = V_35 -> V_37 -> V_87 ;
struct V_68 V_21 ;
struct V_270 * V_270 ;
struct V_637 * V_315 = NULL ;
int V_29 ;
int V_531 ;
int V_296 ;
V_35 = V_35 -> V_37 -> V_63 ;
V_14 = F_68 ( V_35 -> V_37 , V_652 ) ;
F_30 ( ! V_14 ) ;
F_30 ( ! V_14 -> V_278 ) ;
F_19 ( V_35 , V_14 ) ;
memcpy ( & V_21 , & V_14 -> V_21 , sizeof( V_21 ) ) ;
V_531 = F_384 ( V_14 ) ;
if ( V_14 -> V_7 & ( V_297 |
V_298 |
V_299 ) )
V_296 = 2 ;
else
V_296 = 1 ;
V_520 = & V_35 -> V_37 -> V_540 ;
F_11 ( & V_520 -> V_523 ) ;
F_396 ( V_14 , V_520 ) ;
F_13 ( & V_520 -> V_523 ) ;
V_520 = & V_35 -> V_37 -> V_538 ;
F_11 ( & V_520 -> V_523 ) ;
F_396 ( V_14 , V_520 ) ;
F_13 ( & V_520 -> V_523 ) ;
V_65 = F_33 () ;
if ( ! V_65 ) {
V_29 = - V_72 ;
goto V_73;
}
V_270 = F_235 ( V_87 , V_14 , V_65 ) ;
if ( ! F_194 ( V_270 ) ) {
V_29 = F_513 ( V_109 , V_270 ) ;
if ( V_29 ) {
F_514 ( V_270 ) ;
goto V_73;
}
F_515 ( V_270 ) ;
F_11 ( & V_14 -> V_52 ) ;
if ( V_14 -> V_163 ) {
V_14 -> V_163 = 0 ;
V_14 -> V_270 = NULL ;
F_13 ( & V_14 -> V_52 ) ;
F_246 ( V_270 ) ;
} else {
F_13 ( & V_14 -> V_52 ) ;
}
F_514 ( V_270 ) ;
}
V_21 . V_22 = V_653 ;
V_21 . V_33 = V_14 -> V_21 . V_22 ;
V_21 . type = 0 ;
V_29 = F_37 ( V_109 , V_87 , & V_21 , V_65 , - 1 , 1 ) ;
if ( V_29 < 0 )
goto V_73;
if ( V_29 > 0 )
F_44 ( V_65 ) ;
if ( V_29 == 0 ) {
V_29 = F_116 ( V_109 , V_87 , V_65 ) ;
if ( V_29 )
goto V_73;
F_44 ( V_65 ) ;
}
F_11 ( & V_35 -> V_37 -> V_18 ) ;
F_179 ( & V_14 -> V_20 ,
& V_35 -> V_37 -> V_19 ) ;
if ( V_35 -> V_37 -> V_26 == V_14 -> V_21 . V_22 )
V_35 -> V_37 -> V_26 = ( T_2 ) - 1 ;
F_13 ( & V_35 -> V_37 -> V_18 ) ;
F_63 ( & V_14 -> V_104 -> V_306 ) ;
F_366 ( & V_14 -> V_91 ) ;
if ( F_204 ( & V_14 -> V_104 -> V_305 [ V_531 ] ) ) {
V_315 = V_14 -> V_104 -> V_638 [ V_531 ] ;
V_14 -> V_104 -> V_638 [ V_531 ] = NULL ;
F_511 ( V_35 -> V_37 , V_14 -> V_7 ) ;
}
F_65 ( & V_14 -> V_104 -> V_306 ) ;
if ( V_315 ) {
F_490 ( V_315 ) ;
F_491 ( V_315 ) ;
}
if ( V_14 -> V_3 == V_53 )
F_382 ( V_14 ) ;
F_488 ( V_14 ) ;
F_11 ( & V_14 -> V_104 -> V_52 ) ;
V_14 -> V_104 -> V_294 -= V_14 -> V_21 . V_33 ;
V_14 -> V_104 -> V_309 -= V_14 -> V_21 . V_33 ;
V_14 -> V_104 -> V_300 -= V_14 -> V_21 . V_33 * V_296 ;
F_13 ( & V_14 -> V_104 -> V_52 ) ;
memcpy ( & V_21 , & V_14 -> V_21 , sizeof( V_21 ) ) ;
F_6 ( V_14 ) ;
F_6 ( V_14 ) ;
V_29 = F_37 ( V_109 , V_35 , & V_21 , V_65 , - 1 , 1 ) ;
if ( V_29 > 0 )
V_29 = - V_174 ;
if ( V_29 < 0 )
goto V_73;
V_29 = F_116 ( V_109 , V_35 , V_65 ) ;
V_73:
F_50 ( V_65 ) ;
return V_29 ;
}
void F_516 ( struct V_12 * V_37 )
{
struct V_1 * V_14 ;
struct V_101 * V_104 ;
struct V_34 * V_35 = V_37 -> V_63 ;
struct V_108 * V_109 ;
int V_29 = 0 ;
if ( ! V_37 -> V_654 )
return;
F_11 ( & V_37 -> V_477 ) ;
while ( ! F_204 ( & V_37 -> V_479 ) ) {
T_2 V_32 , V_31 ;
V_14 = F_487 ( & V_37 -> V_479 ,
struct V_1 ,
V_478 ) ;
V_104 = V_14 -> V_104 ;
F_366 ( & V_14 -> V_478 ) ;
if ( V_29 || F_285 ( V_104 ) ) {
F_6 ( V_14 ) ;
continue;
}
F_13 ( & V_37 -> V_477 ) ;
F_63 ( & V_104 -> V_306 ) ;
F_11 ( & V_14 -> V_52 ) ;
if ( V_14 -> V_10 ||
F_354 ( & V_14 -> V_134 ) ||
V_14 -> V_278 ) {
F_13 ( & V_14 -> V_52 ) ;
F_65 ( & V_104 -> V_306 ) ;
goto V_81;
}
F_13 ( & V_14 -> V_52 ) ;
V_29 = F_473 ( V_14 , 0 ) ;
F_65 ( & V_104 -> V_306 ) ;
if ( V_29 < 0 ) {
V_29 = 0 ;
goto V_81;
}
V_109 = F_193 ( V_35 ) ;
if ( F_194 ( V_109 ) ) {
F_478 ( V_35 , V_14 ) ;
V_29 = F_195 ( V_109 ) ;
goto V_81;
}
V_32 = V_14 -> V_21 . V_22 ;
V_31 = V_32 + V_14 -> V_21 . V_33 - 1 ;
F_20 ( & V_37 -> V_38 [ 0 ] , V_32 , V_31 ,
V_60 , V_40 ) ;
F_20 ( & V_37 -> V_38 [ 1 ] , V_32 , V_31 ,
V_60 , V_40 ) ;
V_14 -> V_9 = 0 ;
V_29 = F_517 ( V_109 , V_35 ,
V_14 -> V_21 . V_22 ) ;
F_197 ( V_109 , V_35 ) ;
V_81:
F_6 ( V_14 ) ;
F_11 ( & V_37 -> V_477 ) ;
}
F_13 ( & V_37 -> V_477 ) ;
}
int F_518 ( struct V_12 * V_37 )
{
struct V_101 * V_104 ;
struct V_655 * V_656 ;
T_2 V_657 ;
T_2 V_7 ;
int V_658 = 0 ;
int V_29 ;
V_656 = V_37 -> V_362 ;
if ( ! F_519 ( V_656 ) )
return 1 ;
V_657 = F_520 ( V_656 ) ;
if ( V_657 & V_659 )
V_658 = 1 ;
V_7 = V_293 ;
V_29 = F_251 ( V_37 , V_7 , 0 , 0 , & V_104 ) ;
if ( V_29 )
goto V_73;
if ( V_658 ) {
V_7 = V_291 | V_292 ;
V_29 = F_251 ( V_37 , V_7 , 0 , 0 , & V_104 ) ;
} else {
V_7 = V_291 ;
V_29 = F_251 ( V_37 , V_7 , 0 , 0 , & V_104 ) ;
if ( V_29 )
goto V_73;
V_7 = V_292 ;
V_29 = F_251 ( V_37 , V_7 , 0 , 0 , & V_104 ) ;
}
V_73:
return V_29 ;
}
int F_521 ( struct V_34 * V_35 , T_2 V_32 , T_2 V_31 )
{
return F_367 ( V_35 , V_32 , V_31 ) ;
}
int F_522 ( struct V_34 * V_35 , T_2 V_27 ,
T_2 V_36 , T_2 * V_186 )
{
return F_142 ( V_35 , V_27 , V_36 , V_186 ) ;
}
int F_523 ( struct V_34 * V_35 , struct V_660 * V_661 )
{
struct V_12 * V_37 = V_35 -> V_37 ;
struct V_1 * V_2 = NULL ;
T_2 V_662 ;
T_2 V_32 ;
T_2 V_31 ;
T_2 V_663 = 0 ;
T_2 V_294 = F_277 ( V_37 -> V_362 ) ;
int V_29 = 0 ;
if ( V_661 -> V_49 == V_294 )
V_2 = F_67 ( V_37 , V_661 -> V_32 ) ;
else
V_2 = F_68 ( V_37 , V_661 -> V_32 ) ;
while ( V_2 ) {
if ( V_2 -> V_21 . V_22 >= ( V_661 -> V_32 + V_661 -> V_49 ) ) {
F_6 ( V_2 ) ;
break;
}
V_32 = F_392 ( V_661 -> V_32 , V_2 -> V_21 . V_22 ) ;
V_31 = F_295 ( V_661 -> V_32 + V_661 -> V_49 ,
V_2 -> V_21 . V_22 + V_2 -> V_21 . V_33 ) ;
if ( V_31 - V_32 >= V_661 -> V_664 ) {
if ( ! F_1 ( V_2 ) ) {
V_29 = F_51 ( V_2 , 0 ) ;
if ( V_29 ) {
F_6 ( V_2 ) ;
break;
}
V_29 = F_382 ( V_2 ) ;
if ( V_29 ) {
F_6 ( V_2 ) ;
break;
}
}
V_29 = F_524 ( V_2 ,
& V_662 ,
V_32 ,
V_31 ,
V_661 -> V_664 ) ;
V_663 += V_662 ;
if ( V_29 ) {
F_6 ( V_2 ) ;
break;
}
}
V_2 = F_233 ( V_37 -> V_87 , V_2 ) ;
}
V_661 -> V_49 = V_663 ;
return V_29 ;
}
void F_525 ( struct V_34 * V_35 )
{
F_526 ( & V_35 -> V_665 -> V_666 ) ;
F_2 () ;
if ( F_527 ( & V_35 -> V_665 -> V_89 ) )
F_49 ( & V_35 -> V_665 -> V_89 ) ;
}
int F_528 ( struct V_34 * V_35 )
{
if ( F_191 ( & V_35 -> V_667 ) )
return 0 ;
F_529 ( & V_35 -> V_665 -> V_666 ) ;
F_2 () ;
if ( F_191 ( & V_35 -> V_667 ) ) {
F_525 ( V_35 ) ;
return 0 ;
}
return 1 ;
}
