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
if ( F_42 () ) {
V_54 -> V_85 = V_70 ;
F_43 ( V_65 ) ;
F_44 ( & V_37 -> V_80 ) ;
F_45 ( & V_54 -> V_79 ) ;
F_46 () ;
goto V_78;
}
V_29 = F_47 ( V_63 , V_65 ) ;
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
F_43 ( V_65 ) ;
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
F_48 ( & V_54 -> V_89 ) ;
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
F_49 ( V_65 ) ;
F_44 ( & V_37 -> V_80 ) ;
F_19 ( V_63 , V_14 ) ;
F_45 ( & V_54 -> V_79 ) ;
V_73:
if ( V_29 ) {
F_11 ( & V_14 -> V_52 ) ;
V_14 -> V_54 = NULL ;
V_14 -> V_3 = V_5 ;
F_13 ( & V_14 -> V_52 ) ;
}
F_48 ( & V_54 -> V_89 ) ;
F_26 ( V_54 ) ;
F_6 ( V_14 ) ;
}
static int F_50 ( struct V_1 * V_2 ,
int V_90 )
{
F_51 ( V_89 ) ;
struct V_12 * V_37 = V_2 -> V_37 ;
struct V_50 * V_54 ;
int V_29 = 0 ;
V_54 = F_52 ( sizeof( * V_54 ) , V_40 ) ;
if ( ! V_54 )
return - V_72 ;
F_53 ( & V_54 -> V_91 ) ;
F_54 ( & V_54 -> V_79 ) ;
F_55 ( & V_54 -> V_89 ) ;
V_54 -> V_14 = V_2 ;
V_54 -> V_85 = V_2 -> V_21 . V_22 ;
F_56 ( & V_54 -> V_8 , 1 ) ;
V_54 -> V_62 . V_92 = F_31 ;
F_11 ( & V_2 -> V_52 ) ;
while ( V_2 -> V_3 == V_93 ) {
struct V_50 * V_51 ;
V_51 = V_2 -> V_54 ;
F_5 ( & V_51 -> V_8 ) ;
F_57 ( & V_51 -> V_89 , & V_89 , V_94 ) ;
F_13 ( & V_2 -> V_52 ) ;
F_58 () ;
F_59 ( & V_51 -> V_89 , & V_89 ) ;
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
V_29 = F_60 ( V_37 , V_2 ) ;
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
F_48 ( & V_54 -> V_89 ) ;
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
F_48 ( & V_54 -> V_89 ) ;
}
if ( V_90 ) {
F_26 ( V_54 ) ;
return 0 ;
}
F_61 ( & V_37 -> V_80 ) ;
F_5 ( & V_54 -> V_8 ) ;
F_62 ( & V_54 -> V_91 , & V_37 -> V_99 ) ;
F_63 ( & V_37 -> V_80 ) ;
F_4 ( V_2 ) ;
F_64 ( & V_37 -> V_100 , & V_54 -> V_62 ) ;
return V_29 ;
}
static struct V_1 *
F_65 ( struct V_12 * V_13 , T_2 V_27 )
{
struct V_1 * V_2 ;
V_2 = F_16 ( V_13 , V_27 , 0 ) ;
return V_2 ;
}
struct V_1 * F_66 (
struct V_12 * V_13 ,
T_2 V_27 )
{
struct V_1 * V_2 ;
V_2 = F_16 ( V_13 , V_27 , 1 ) ;
return V_2 ;
}
static struct V_101 * F_67 ( struct V_12 * V_13 ,
T_2 V_7 )
{
struct V_102 * V_103 = & V_13 -> V_104 ;
struct V_101 * V_105 ;
V_7 &= V_106 ;
F_68 () ;
F_69 (found, head, list) {
if ( V_105 -> V_7 & V_7 ) {
F_70 () ;
return V_105 ;
}
}
F_70 () ;
return NULL ;
}
void F_71 ( struct V_12 * V_13 )
{
struct V_102 * V_103 = & V_13 -> V_104 ;
struct V_101 * V_105 ;
F_68 () ;
F_69 (found, head, list)
V_105 -> V_107 = 0 ;
F_70 () ;
}
int F_72 ( struct V_34 * V_35 , T_2 V_32 , T_2 V_49 )
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
if ( V_29 > 0 ) {
F_40 ( V_65 -> V_83 [ 0 ] , & V_21 , V_65 -> V_84 [ 0 ] ) ;
if ( V_21 . V_22 == V_32 &&
V_21 . type == V_86 )
V_29 = 0 ;
}
F_49 ( V_65 ) ;
return V_29 ;
}
int F_73 ( struct V_108 * V_109 ,
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
if ( V_110 && ! F_74 ( V_35 -> V_37 , V_120 ) ) {
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
V_78:
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
if ( V_29 ) {
V_21 . V_22 = V_27 ;
V_21 . type = V_77 ;
V_21 . V_33 = V_35 -> V_88 ;
F_43 ( V_65 ) ;
goto V_78;
}
}
if ( V_29 == 0 ) {
V_67 = V_65 -> V_83 [ 0 ] ;
V_117 = F_75 ( V_67 , V_65 -> V_84 [ 0 ] ) ;
if ( V_117 >= sizeof( * V_116 ) ) {
V_116 = F_76 ( V_67 , V_65 -> V_84 [ 0 ] ,
struct V_115 ) ;
V_118 = F_77 ( V_67 , V_116 ) ;
V_119 = F_78 ( V_67 , V_116 ) ;
} else {
#ifdef F_79
struct V_123 * V_124 ;
F_30 ( V_117 != sizeof( * V_124 ) ) ;
V_124 = F_76 ( V_67 , V_65 -> V_84 [ 0 ] ,
struct V_123 ) ;
V_118 = F_80 ( V_67 , V_124 ) ;
V_119 = V_125 ;
#else
F_81 () ;
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
V_103 = F_82 ( V_109 , V_27 ) ;
if ( V_103 ) {
if ( ! F_83 ( & V_103 -> V_79 ) ) {
F_5 ( & V_103 -> V_127 . V_111 ) ;
F_13 ( & V_114 -> V_52 ) ;
F_43 ( V_65 ) ;
F_35 ( & V_103 -> V_79 ) ;
F_45 ( & V_103 -> V_79 ) ;
F_84 ( & V_103 -> V_127 ) ;
goto V_121;
}
if ( V_103 -> V_128 && V_103 -> V_128 -> V_129 )
V_119 |= V_103 -> V_128 -> V_130 ;
else
F_30 ( V_118 == 0 ) ;
V_118 += V_103 -> V_127 . V_131 ;
F_45 ( & V_103 -> V_79 ) ;
}
F_13 ( & V_114 -> V_52 ) ;
V_73:
F_8 ( V_118 == 0 ) ;
if ( V_111 )
* V_111 = V_118 ;
if ( V_7 )
* V_7 = V_119 ;
V_122:
F_49 ( V_65 ) ;
return V_29 ;
}
static int F_85 ( struct V_108 * V_109 ,
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
F_30 ( F_75 ( V_67 , V_65 -> V_84 [ 0 ] ) != sizeof( * V_124 ) ) ;
F_40 ( V_67 , & V_21 , V_65 -> V_84 [ 0 ] ) ;
V_124 = F_76 ( V_67 , V_65 -> V_84 [ 0 ] ,
struct V_123 ) ;
V_111 = F_80 ( V_67 , V_124 ) ;
if ( V_132 == ( T_2 ) - 1 ) {
while ( 1 ) {
if ( V_65 -> V_84 [ 0 ] >= F_38 ( V_67 ) ) {
V_29 = F_47 ( V_35 , V_65 ) ;
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
V_136 = F_76 ( V_67 , V_65 -> V_84 [ 0 ] ,
struct V_135 ) ;
V_132 = F_86 ( V_67 , V_136 ) ;
break;
}
}
F_43 ( V_65 ) ;
if ( V_132 < V_142 )
V_140 += sizeof( * V_138 ) ;
V_140 -= sizeof( * V_124 ) ;
V_29 = F_37 ( V_109 , V_35 , & V_21 , V_65 ,
V_140 + V_133 , 1 ) ;
if ( V_29 < 0 )
return V_29 ;
F_30 ( V_29 ) ;
F_87 ( V_35 , V_65 , V_140 ) ;
V_67 = V_65 -> V_83 [ 0 ] ;
V_134 = F_76 ( V_67 , V_65 -> V_84 [ 0 ] , struct V_115 ) ;
F_88 ( V_67 , V_134 , V_111 ) ;
F_89 ( V_67 , V_134 , 0 ) ;
if ( V_132 < V_142 ) {
F_90 ( V_67 , V_134 ,
V_143 |
V_125 ) ;
V_138 = (struct V_137 * ) ( V_134 + 1 ) ;
F_91 ( V_67 , 0 , ( unsigned long ) V_138 , sizeof( * V_138 ) ) ;
F_92 ( V_67 , V_138 , ( int ) V_132 ) ;
} else {
F_90 ( V_67 , V_134 , V_144 ) ;
}
F_93 ( V_67 ) ;
return 0 ;
}
static T_2 F_94 ( T_2 V_145 , T_2 V_132 , T_2 V_33 )
{
T_3 V_146 = ~ ( T_3 ) 0 ;
T_3 V_147 = ~ ( T_3 ) 0 ;
T_4 V_148 ;
V_148 = F_95 ( V_145 ) ;
V_146 = F_96 ( V_146 , & V_148 , sizeof( V_148 ) ) ;
V_148 = F_95 ( V_132 ) ;
V_147 = F_96 ( V_147 , & V_148 , sizeof( V_148 ) ) ;
V_148 = F_95 ( V_33 ) ;
V_147 = F_96 ( V_147 , & V_148 , sizeof( V_148 ) ) ;
return ( ( T_2 ) V_146 << 31 ) ^ ( T_2 ) V_147 ;
}
static T_2 F_97 ( struct V_66 * V_67 ,
struct V_149 * V_150 )
{
return F_94 ( F_98 ( V_67 , V_150 ) ,
F_99 ( V_67 , V_150 ) ,
F_100 ( V_67 , V_150 ) ) ;
}
static int F_101 ( struct V_66 * V_67 ,
struct V_149 * V_150 ,
T_2 V_145 , T_2 V_132 , T_2 V_33 )
{
if ( F_98 ( V_67 , V_150 ) != V_145 ||
F_99 ( V_67 , V_150 ) != V_132 ||
F_100 ( V_67 , V_150 ) != V_33 )
return 0 ;
return 1 ;
}
static T_1 int F_102 ( struct V_108 * V_109 ,
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
V_21 . V_33 = F_94 ( V_145 ,
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
#ifdef F_79
V_21 . type = V_141 ;
F_43 ( V_65 ) ;
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
V_29 = F_47 ( V_35 , V_65 ) ;
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
V_150 = F_76 ( V_67 , V_65 -> V_84 [ 0 ] ,
struct V_149 ) ;
if ( F_101 ( V_67 , V_150 , V_145 ,
V_132 , V_33 ) ) {
if ( V_151 ) {
F_43 ( V_65 ) ;
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
static T_1 int F_103 ( struct V_108 * V_109 ,
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
V_21 . V_33 = F_94 ( V_145 ,
V_132 , V_33 ) ;
V_57 = sizeof( struct V_149 ) ;
}
V_29 = F_104 ( V_109 , V_35 , V_65 , & V_21 , V_57 ) ;
if ( V_29 && V_29 != - V_25 )
goto V_155;
V_67 = V_65 -> V_83 [ 0 ] ;
if ( V_17 ) {
struct V_157 * V_150 ;
V_150 = F_76 ( V_67 , V_65 -> V_84 [ 0 ] ,
struct V_157 ) ;
if ( V_29 == 0 ) {
F_105 ( V_67 , V_150 , V_156 ) ;
} else {
V_118 = F_106 ( V_67 , V_150 ) ;
V_118 += V_156 ;
F_105 ( V_67 , V_150 , V_118 ) ;
}
} else {
struct V_149 * V_150 ;
while ( V_29 == - V_25 ) {
V_150 = F_76 ( V_67 , V_65 -> V_84 [ 0 ] ,
struct V_149 ) ;
if ( F_101 ( V_67 , V_150 , V_145 ,
V_132 , V_33 ) )
break;
F_43 ( V_65 ) ;
V_21 . V_33 ++ ;
V_29 = F_104 ( V_109 , V_35 , V_65 , & V_21 ,
V_57 ) ;
if ( V_29 && V_29 != - V_25 )
goto V_155;
V_67 = V_65 -> V_83 [ 0 ] ;
}
V_150 = F_76 ( V_67 , V_65 -> V_84 [ 0 ] ,
struct V_149 ) ;
if ( V_29 == 0 ) {
F_107 ( V_67 , V_150 ,
V_145 ) ;
F_108 ( V_67 , V_150 , V_132 ) ;
F_109 ( V_67 , V_150 , V_33 ) ;
F_110 ( V_67 , V_150 , V_156 ) ;
} else {
V_118 = F_111 ( V_67 , V_150 ) ;
V_118 += V_156 ;
F_110 ( V_67 , V_150 , V_118 ) ;
}
}
F_93 ( V_67 ) ;
V_29 = 0 ;
V_155:
F_43 ( V_65 ) ;
return V_29 ;
}
static T_1 int F_112 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
struct V_64 * V_65 ,
int V_158 )
{
struct V_68 V_21 ;
struct V_149 * V_159 = NULL ;
struct V_157 * V_160 = NULL ;
struct V_66 * V_67 ;
T_3 V_118 = 0 ;
int V_29 = 0 ;
V_67 = V_65 -> V_83 [ 0 ] ;
F_40 ( V_67 , & V_21 , V_65 -> V_84 [ 0 ] ) ;
if ( V_21 . type == V_154 ) {
V_159 = F_76 ( V_67 , V_65 -> V_84 [ 0 ] ,
struct V_149 ) ;
V_118 = F_111 ( V_67 , V_159 ) ;
} else if ( V_21 . type == V_153 ) {
V_160 = F_76 ( V_67 , V_65 -> V_84 [ 0 ] ,
struct V_157 ) ;
V_118 = F_106 ( V_67 , V_160 ) ;
#ifdef F_79
} else if ( V_21 . type == V_141 ) {
struct V_135 * V_136 ;
V_136 = F_76 ( V_67 , V_65 -> V_84 [ 0 ] ,
struct V_135 ) ;
V_118 = F_113 ( V_67 , V_136 ) ;
#endif
} else {
F_81 () ;
}
F_30 ( V_118 < V_158 ) ;
V_118 -= V_158 ;
if ( V_118 == 0 ) {
V_29 = F_114 ( V_109 , V_35 , V_65 ) ;
} else {
if ( V_21 . type == V_154 )
F_110 ( V_67 , V_159 , V_118 ) ;
else if ( V_21 . type == V_153 )
F_105 ( V_67 , V_160 , V_118 ) ;
#ifdef F_79
else {
struct V_135 * V_136 ;
V_136 = F_76 ( V_67 , V_65 -> V_84 [ 0 ] ,
struct V_135 ) ;
F_115 ( V_67 , V_136 , V_118 ) ;
}
#endif
F_93 ( V_67 ) ;
}
return V_29 ;
}
static T_1 T_3 F_116 ( struct V_34 * V_35 ,
struct V_64 * V_65 ,
struct V_161 * V_162 )
{
struct V_68 V_21 ;
struct V_66 * V_67 ;
struct V_149 * V_159 ;
struct V_157 * V_160 ;
T_3 V_118 = 0 ;
V_67 = V_65 -> V_83 [ 0 ] ;
F_40 ( V_67 , & V_21 , V_65 -> V_84 [ 0 ] ) ;
if ( V_162 ) {
if ( F_117 ( V_67 , V_162 ) ==
V_154 ) {
V_159 = (struct V_149 * ) ( & V_162 -> V_33 ) ;
V_118 = F_111 ( V_67 , V_159 ) ;
} else {
V_160 = (struct V_157 * ) ( V_162 + 1 ) ;
V_118 = F_106 ( V_67 , V_160 ) ;
}
} else if ( V_21 . type == V_154 ) {
V_159 = F_76 ( V_67 , V_65 -> V_84 [ 0 ] ,
struct V_149 ) ;
V_118 = F_111 ( V_67 , V_159 ) ;
} else if ( V_21 . type == V_153 ) {
V_160 = F_76 ( V_67 , V_65 -> V_84 [ 0 ] ,
struct V_157 ) ;
V_118 = F_106 ( V_67 , V_160 ) ;
#ifdef F_79
} else if ( V_21 . type == V_141 ) {
struct V_135 * V_136 ;
V_136 = F_76 ( V_67 , V_65 -> V_84 [ 0 ] ,
struct V_135 ) ;
V_118 = F_113 ( V_67 , V_136 ) ;
#endif
} else {
F_8 ( 1 ) ;
}
return V_118 ;
}
static T_1 int F_118 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
struct V_64 * V_65 ,
T_2 V_27 , T_2 V_17 ,
T_2 V_145 )
{
struct V_68 V_21 ;
int V_29 ;
V_21 . V_22 = V_27 ;
if ( V_17 ) {
V_21 . type = V_163 ;
V_21 . V_33 = V_17 ;
} else {
V_21 . type = V_164 ;
V_21 . V_33 = V_145 ;
}
V_29 = F_37 ( V_109 , V_35 , & V_21 , V_65 , - 1 , 1 ) ;
if ( V_29 > 0 )
V_29 = - V_152 ;
#ifdef F_79
if ( V_29 == - V_152 && V_17 ) {
F_43 ( V_65 ) ;
V_21 . type = V_141 ;
V_29 = F_37 ( V_109 , V_35 , & V_21 , V_65 , - 1 , 1 ) ;
if ( V_29 > 0 )
V_29 = - V_152 ;
}
#endif
return V_29 ;
}
static T_1 int F_119 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
struct V_64 * V_65 ,
T_2 V_27 , T_2 V_17 ,
T_2 V_145 )
{
struct V_68 V_21 ;
int V_29 ;
V_21 . V_22 = V_27 ;
if ( V_17 ) {
V_21 . type = V_163 ;
V_21 . V_33 = V_17 ;
} else {
V_21 . type = V_164 ;
V_21 . V_33 = V_145 ;
}
V_29 = F_104 ( V_109 , V_35 , V_65 , & V_21 , 0 ) ;
F_43 ( V_65 ) ;
return V_29 ;
}
static inline int F_120 ( T_2 V_17 , T_2 V_132 )
{
int type ;
if ( V_132 < V_142 ) {
if ( V_17 > 0 )
type = V_163 ;
else
type = V_164 ;
} else {
if ( V_17 > 0 )
type = V_153 ;
else
type = V_154 ;
}
return type ;
}
static int F_41 ( struct V_64 * V_65 , int V_165 ,
struct V_68 * V_21 )
{
for (; V_165 < V_166 ; V_165 ++ ) {
if ( ! V_65 -> V_83 [ V_165 ] )
break;
if ( V_65 -> V_84 [ V_165 ] + 1 >=
F_38 ( V_65 -> V_83 [ V_165 ] ) )
continue;
if ( V_165 == 0 )
F_40 ( V_65 -> V_83 [ V_165 ] , V_21 ,
V_65 -> V_84 [ V_165 ] + 1 ) ;
else
F_121 ( V_65 -> V_83 [ V_165 ] , V_21 ,
V_65 -> V_84 [ V_165 ] + 1 ) ;
return 0 ;
}
return 1 ;
}
static T_5
int F_122 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
struct V_64 * V_65 ,
struct V_161 * * V_167 ,
T_2 V_27 , T_2 V_36 ,
T_2 V_17 , T_2 V_145 ,
T_2 V_132 , T_2 V_33 , int V_168 )
{
struct V_68 V_21 ;
struct V_66 * V_67 ;
struct V_115 * V_116 ;
struct V_161 * V_162 ;
T_2 V_7 ;
T_2 V_117 ;
unsigned long V_169 ;
unsigned long V_31 ;
int V_133 ;
int type ;
int V_170 ;
int V_29 ;
int V_82 = 0 ;
bool V_171 = F_74 ( V_35 -> V_37 ,
V_120 ) ;
V_21 . V_22 = V_27 ;
V_21 . type = V_77 ;
V_21 . V_33 = V_36 ;
V_170 = F_120 ( V_17 , V_132 ) ;
if ( V_168 ) {
V_133 = F_123 ( V_170 ) ;
V_65 -> V_172 = 1 ;
} else
V_133 = - 1 ;
if ( V_171 && V_132 < V_142 ) {
V_21 . type = V_86 ;
V_21 . V_33 = V_132 ;
}
V_78:
V_29 = F_37 ( V_109 , V_35 , & V_21 , V_65 , V_133 , 1 ) ;
if ( V_29 < 0 ) {
V_82 = V_29 ;
goto V_73;
}
if ( V_29 > 0 && V_171 ) {
V_171 = false ;
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
V_21 . type = V_77 ;
V_21 . V_33 = V_36 ;
F_43 ( V_65 ) ;
goto V_78;
}
}
if ( V_29 && ! V_168 ) {
V_82 = - V_152 ;
goto V_73;
} else if ( F_8 ( V_29 ) ) {
V_82 = - V_173 ;
goto V_73;
}
V_67 = V_65 -> V_83 [ 0 ] ;
V_117 = F_75 ( V_67 , V_65 -> V_84 [ 0 ] ) ;
#ifdef F_79
if ( V_117 < sizeof( * V_116 ) ) {
if ( ! V_168 ) {
V_82 = - V_152 ;
goto V_73;
}
V_29 = F_85 ( V_109 , V_35 , V_65 , V_132 ,
V_133 ) ;
if ( V_29 < 0 ) {
V_82 = V_29 ;
goto V_73;
}
V_67 = V_65 -> V_83 [ 0 ] ;
V_117 = F_75 ( V_67 , V_65 -> V_84 [ 0 ] ) ;
}
#endif
F_30 ( V_117 < sizeof( * V_116 ) ) ;
V_116 = F_76 ( V_67 , V_65 -> V_84 [ 0 ] , struct V_115 ) ;
V_7 = F_78 ( V_67 , V_116 ) ;
V_169 = ( unsigned long ) ( V_116 + 1 ) ;
V_31 = ( unsigned long ) V_116 + V_117 ;
if ( V_7 & V_143 && ! V_171 ) {
V_169 += sizeof( struct V_137 ) ;
F_30 ( V_169 > V_31 ) ;
}
V_82 = - V_152 ;
while ( 1 ) {
if ( V_169 >= V_31 ) {
F_8 ( V_169 > V_31 ) ;
break;
}
V_162 = (struct V_161 * ) V_169 ;
type = F_117 ( V_67 , V_162 ) ;
if ( V_170 < type )
break;
if ( V_170 > type ) {
V_169 += F_123 ( type ) ;
continue;
}
if ( type == V_154 ) {
struct V_149 * V_174 ;
V_174 = (struct V_149 * ) ( & V_162 -> V_33 ) ;
if ( F_101 ( V_67 , V_174 , V_145 ,
V_132 , V_33 ) ) {
V_82 = 0 ;
break;
}
if ( F_97 ( V_67 , V_174 ) <
F_94 ( V_145 , V_132 , V_33 ) )
break;
} else {
T_2 V_175 ;
V_175 = F_124 ( V_67 , V_162 ) ;
if ( V_17 > 0 ) {
if ( V_17 == V_175 ) {
V_82 = 0 ;
break;
}
if ( V_175 < V_17 )
break;
} else {
if ( V_145 == V_175 ) {
V_82 = 0 ;
break;
}
if ( V_175 < V_145 )
break;
}
}
V_169 += F_123 ( type ) ;
}
if ( V_82 == - V_152 && V_168 ) {
if ( V_117 + V_133 >=
F_125 ( V_35 ) ) {
V_82 = - V_176 ;
goto V_73;
}
if ( F_41 ( V_65 , 0 , & V_21 ) == 0 &&
V_21 . V_22 == V_27 &&
V_21 . type < V_177 ) {
V_82 = - V_176 ;
goto V_73;
}
}
* V_167 = (struct V_161 * ) V_169 ;
V_73:
if ( V_168 ) {
V_65 -> V_172 = 0 ;
F_126 ( V_65 , 1 ) ;
}
return V_82 ;
}
static T_5
void F_127 ( struct V_34 * V_35 ,
struct V_64 * V_65 ,
struct V_161 * V_162 ,
T_2 V_17 , T_2 V_145 ,
T_2 V_132 , T_2 V_33 , int V_156 ,
struct V_178 * V_128 )
{
struct V_66 * V_67 ;
struct V_115 * V_116 ;
unsigned long V_169 ;
unsigned long V_31 ;
unsigned long V_179 ;
T_2 V_111 ;
int V_57 ;
int type ;
V_67 = V_65 -> V_83 [ 0 ] ;
V_116 = F_76 ( V_67 , V_65 -> V_84 [ 0 ] , struct V_115 ) ;
V_179 = ( unsigned long ) V_162 - ( unsigned long ) V_116 ;
type = F_120 ( V_17 , V_132 ) ;
V_57 = F_123 ( type ) ;
F_87 ( V_35 , V_65 , V_57 ) ;
V_116 = F_76 ( V_67 , V_65 -> V_84 [ 0 ] , struct V_115 ) ;
V_111 = F_77 ( V_67 , V_116 ) ;
V_111 += V_156 ;
F_88 ( V_67 , V_116 , V_111 ) ;
if ( V_128 )
F_128 ( V_128 , V_67 , V_116 ) ;
V_169 = ( unsigned long ) V_116 + V_179 ;
V_31 = ( unsigned long ) V_116 + F_75 ( V_67 , V_65 -> V_84 [ 0 ] ) ;
if ( V_169 < V_31 - V_57 )
F_129 ( V_67 , V_169 + V_57 , V_169 ,
V_31 - V_57 - V_169 ) ;
V_162 = (struct V_161 * ) V_169 ;
F_130 ( V_67 , V_162 , type ) ;
if ( type == V_154 ) {
struct V_149 * V_174 ;
V_174 = (struct V_149 * ) ( & V_162 -> V_33 ) ;
F_107 ( V_67 , V_174 , V_145 ) ;
F_108 ( V_67 , V_174 , V_132 ) ;
F_109 ( V_67 , V_174 , V_33 ) ;
F_110 ( V_67 , V_174 , V_156 ) ;
} else if ( type == V_153 ) {
struct V_157 * V_180 ;
V_180 = (struct V_157 * ) ( V_162 + 1 ) ;
F_105 ( V_67 , V_180 , V_156 ) ;
F_131 ( V_67 , V_162 , V_17 ) ;
} else if ( type == V_163 ) {
F_131 ( V_67 , V_162 , V_17 ) ;
} else {
F_131 ( V_67 , V_162 , V_145 ) ;
}
F_93 ( V_67 ) ;
}
static int F_132 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
struct V_64 * V_65 ,
struct V_161 * * V_167 ,
T_2 V_27 , T_2 V_36 , T_2 V_17 ,
T_2 V_145 , T_2 V_132 , T_2 V_33 )
{
int V_29 ;
V_29 = F_122 ( V_109 , V_35 , V_65 , V_167 ,
V_27 , V_36 , V_17 ,
V_145 , V_132 , V_33 , 0 ) ;
if ( V_29 != - V_152 )
return V_29 ;
F_43 ( V_65 ) ;
* V_167 = NULL ;
if ( V_132 < V_142 ) {
V_29 = F_118 ( V_109 , V_35 , V_65 , V_27 , V_17 ,
V_145 ) ;
} else {
V_29 = F_102 ( V_109 , V_35 , V_65 , V_27 , V_17 ,
V_145 , V_132 , V_33 ) ;
}
return V_29 ;
}
static T_5
void F_133 ( struct V_34 * V_35 ,
struct V_64 * V_65 ,
struct V_161 * V_162 ,
int V_181 ,
struct V_178 * V_128 )
{
struct V_66 * V_67 ;
struct V_115 * V_116 ;
struct V_149 * V_174 = NULL ;
struct V_157 * V_180 = NULL ;
unsigned long V_169 ;
unsigned long V_31 ;
T_3 V_117 ;
int V_57 ;
int type ;
T_2 V_111 ;
V_67 = V_65 -> V_83 [ 0 ] ;
V_116 = F_76 ( V_67 , V_65 -> V_84 [ 0 ] , struct V_115 ) ;
V_111 = F_77 ( V_67 , V_116 ) ;
F_8 ( V_181 < 0 && V_111 + V_181 <= 0 ) ;
V_111 += V_181 ;
F_88 ( V_67 , V_116 , V_111 ) ;
if ( V_128 )
F_128 ( V_128 , V_67 , V_116 ) ;
type = F_117 ( V_67 , V_162 ) ;
if ( type == V_154 ) {
V_174 = (struct V_149 * ) ( & V_162 -> V_33 ) ;
V_111 = F_111 ( V_67 , V_174 ) ;
} else if ( type == V_153 ) {
V_180 = (struct V_157 * ) ( V_162 + 1 ) ;
V_111 = F_106 ( V_67 , V_180 ) ;
} else {
V_111 = 1 ;
F_30 ( V_181 != - 1 ) ;
}
F_30 ( V_181 < 0 && V_111 < - V_181 ) ;
V_111 += V_181 ;
if ( V_111 > 0 ) {
if ( type == V_154 )
F_110 ( V_67 , V_174 , V_111 ) ;
else
F_105 ( V_67 , V_180 , V_111 ) ;
} else {
V_57 = F_123 ( type ) ;
V_117 = F_75 ( V_67 , V_65 -> V_84 [ 0 ] ) ;
V_169 = ( unsigned long ) V_162 ;
V_31 = ( unsigned long ) V_116 + V_117 ;
if ( V_169 + V_57 < V_31 )
F_129 ( V_67 , V_169 , V_169 + V_57 ,
V_31 - V_169 - V_57 ) ;
V_117 -= V_57 ;
F_134 ( V_35 , V_65 , V_117 , 1 ) ;
}
F_93 ( V_67 ) ;
}
static T_5
int F_135 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
struct V_64 * V_65 ,
T_2 V_27 , T_2 V_36 , T_2 V_17 ,
T_2 V_145 , T_2 V_132 ,
T_2 V_33 , int V_156 ,
struct V_178 * V_128 )
{
struct V_161 * V_162 ;
int V_29 ;
V_29 = F_122 ( V_109 , V_35 , V_65 , & V_162 ,
V_27 , V_36 , V_17 ,
V_145 , V_132 , V_33 , 1 ) ;
if ( V_29 == 0 ) {
F_30 ( V_132 < V_142 ) ;
F_133 ( V_35 , V_65 , V_162 ,
V_156 , V_128 ) ;
} else if ( V_29 == - V_152 ) {
F_127 ( V_35 , V_65 , V_162 , V_17 ,
V_145 , V_132 , V_33 ,
V_156 , V_128 ) ;
V_29 = 0 ;
}
return V_29 ;
}
static int F_136 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
struct V_64 * V_65 ,
T_2 V_27 , T_2 V_17 , T_2 V_145 ,
T_2 V_132 , T_2 V_33 , int V_156 )
{
int V_29 ;
if ( V_132 < V_142 ) {
F_30 ( V_156 != 1 ) ;
V_29 = F_119 ( V_109 , V_35 , V_65 , V_27 ,
V_17 , V_145 ) ;
} else {
V_29 = F_103 ( V_109 , V_35 , V_65 , V_27 ,
V_17 , V_145 ,
V_132 , V_33 , V_156 ) ;
}
return V_29 ;
}
static int F_137 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
struct V_64 * V_65 ,
struct V_161 * V_162 ,
int V_158 , int V_182 )
{
int V_29 = 0 ;
F_30 ( ! V_182 && V_158 != 1 ) ;
if ( V_162 ) {
F_133 ( V_35 , V_65 , V_162 ,
- V_158 , NULL ) ;
} else if ( V_182 ) {
V_29 = F_112 ( V_109 , V_35 , V_65 , V_158 ) ;
} else {
V_29 = F_114 ( V_109 , V_35 , V_65 ) ;
}
return V_29 ;
}
static int F_138 ( struct V_183 * V_184 ,
T_2 V_32 , T_2 V_49 )
{
return F_139 ( V_184 , V_32 >> 9 , V_49 >> 9 , V_40 , 0 ) ;
}
static int F_140 ( struct V_34 * V_35 , T_2 V_27 ,
T_2 V_36 , T_2 * V_185 )
{
int V_29 ;
T_2 V_186 = 0 ;
struct V_187 * V_188 = NULL ;
V_29 = F_141 ( V_35 -> V_37 , V_189 ,
V_27 , & V_36 , & V_188 , 0 ) ;
if ( ! V_29 ) {
struct V_190 * V_191 = V_188 -> V_192 ;
int V_43 ;
for ( V_43 = 0 ; V_43 < V_188 -> V_193 ; V_43 ++ , V_191 ++ ) {
if ( ! V_191 -> V_194 -> V_195 )
continue;
V_29 = F_138 ( V_191 -> V_194 -> V_184 ,
V_191 -> V_196 ,
V_191 -> V_197 ) ;
if ( ! V_29 )
V_186 += V_191 -> V_197 ;
else if ( V_29 != - V_198 )
break;
V_29 = 0 ;
}
F_9 ( V_188 ) ;
}
if ( V_185 )
* V_185 = V_186 ;
if ( V_29 == - V_198 )
V_29 = 0 ;
return V_29 ;
}
int F_142 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
T_2 V_27 , T_2 V_36 , T_2 V_17 ,
T_2 V_145 , T_2 V_132 , T_2 V_33 , int V_199 )
{
int V_29 ;
struct V_12 * V_37 = V_35 -> V_37 ;
F_30 ( V_132 < V_142 &&
V_145 == V_200 ) ;
if ( V_132 < V_142 ) {
V_29 = F_143 ( V_37 , V_109 , V_27 ,
V_36 ,
V_17 , V_145 , ( int ) V_132 ,
V_201 , NULL , V_199 ) ;
} else {
V_29 = F_144 ( V_37 , V_109 , V_27 ,
V_36 ,
V_17 , V_145 , V_132 , V_33 ,
V_201 , NULL , V_199 ) ;
}
return V_29 ;
}
static int F_145 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
T_2 V_27 , T_2 V_36 ,
T_2 V_17 , T_2 V_145 ,
T_2 V_132 , T_2 V_33 , int V_156 ,
struct V_178 * V_128 )
{
struct V_64 * V_65 ;
struct V_66 * V_67 ;
struct V_115 * V_134 ;
T_2 V_111 ;
int V_29 ;
V_65 = F_33 () ;
if ( ! V_65 )
return - V_72 ;
V_65 -> V_76 = 1 ;
V_65 -> V_202 = 1 ;
V_29 = F_135 ( V_109 , V_35 -> V_37 -> V_63 ,
V_65 , V_27 , V_36 , V_17 ,
V_145 , V_132 , V_33 ,
V_156 , V_128 ) ;
if ( V_29 != - V_176 )
goto V_73;
V_67 = V_65 -> V_83 [ 0 ] ;
V_134 = F_76 ( V_67 , V_65 -> V_84 [ 0 ] , struct V_115 ) ;
V_111 = F_77 ( V_67 , V_134 ) ;
F_88 ( V_67 , V_134 , V_111 + V_156 ) ;
if ( V_128 )
F_128 ( V_128 , V_67 , V_134 ) ;
F_93 ( V_67 ) ;
F_43 ( V_65 ) ;
V_65 -> V_76 = 1 ;
V_65 -> V_202 = 1 ;
V_29 = F_136 ( V_109 , V_35 -> V_37 -> V_63 ,
V_65 , V_27 , V_17 , V_145 ,
V_132 , V_33 , V_156 ) ;
if ( V_29 )
F_146 ( V_109 , V_35 , V_29 ) ;
V_73:
F_49 ( V_65 ) ;
return V_29 ;
}
static int F_147 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
struct V_203 * V_127 ,
struct V_178 * V_128 ,
int V_204 )
{
int V_29 = 0 ;
struct V_205 * V_150 ;
struct V_68 V_206 ;
T_2 V_17 = 0 ;
T_2 V_207 = 0 ;
T_2 V_7 = 0 ;
V_206 . V_22 = V_127 -> V_27 ;
V_206 . V_33 = V_127 -> V_36 ;
V_206 . type = V_77 ;
V_150 = F_148 ( V_127 ) ;
F_149 ( V_127 , V_150 , V_127 -> V_208 ) ;
if ( V_127 -> type == V_153 )
V_17 = V_150 -> V_17 ;
else
V_207 = V_150 -> V_35 ;
if ( V_127 -> V_208 == V_201 && V_204 ) {
if ( V_128 )
V_7 |= V_128 -> V_130 ;
V_29 = F_150 ( V_109 , V_35 ,
V_17 , V_207 , V_7 ,
V_150 -> V_22 , V_150 -> V_33 ,
& V_206 , V_127 -> V_131 ) ;
} else if ( V_127 -> V_208 == V_201 ) {
V_29 = F_145 ( V_109 , V_35 , V_127 -> V_27 ,
V_127 -> V_36 , V_17 ,
V_207 , V_150 -> V_22 ,
V_150 -> V_33 , V_127 -> V_131 ,
V_128 ) ;
} else if ( V_127 -> V_208 == V_209 ) {
V_29 = F_151 ( V_109 , V_35 , V_127 -> V_27 ,
V_127 -> V_36 , V_17 ,
V_207 , V_150 -> V_22 ,
V_150 -> V_33 , V_127 -> V_131 ,
V_128 ) ;
} else {
F_81 () ;
}
return V_29 ;
}
static void F_128 ( struct V_178 * V_128 ,
struct V_66 * V_67 ,
struct V_115 * V_116 )
{
T_2 V_7 = F_78 ( V_67 , V_116 ) ;
if ( V_128 -> V_129 ) {
V_7 |= V_128 -> V_130 ;
F_90 ( V_67 , V_116 , V_7 ) ;
}
if ( V_128 -> V_210 ) {
struct V_137 * V_138 ;
F_30 ( ! ( V_7 & V_143 ) ) ;
V_138 = (struct V_137 * ) ( V_116 + 1 ) ;
F_152 ( V_67 , V_138 , & V_128 -> V_21 ) ;
}
}
static int F_153 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
struct V_203 * V_127 ,
struct V_178 * V_128 )
{
struct V_68 V_21 ;
struct V_64 * V_65 ;
struct V_115 * V_116 ;
struct V_66 * V_67 ;
T_3 V_117 ;
int V_29 ;
int V_82 = 0 ;
int V_110 = ! V_128 -> V_182 ;
if ( V_109 -> V_211 )
return 0 ;
if ( V_110 && ! F_74 ( V_35 -> V_37 , V_120 ) )
V_110 = 0 ;
V_65 = F_33 () ;
if ( ! V_65 )
return - V_72 ;
V_21 . V_22 = V_127 -> V_27 ;
if ( V_110 ) {
V_21 . type = V_86 ;
V_21 . V_33 = V_128 -> V_165 ;
} else {
V_21 . type = V_77 ;
V_21 . V_33 = V_127 -> V_36 ;
}
V_78:
V_65 -> V_76 = 1 ;
V_65 -> V_202 = 1 ;
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
F_43 ( V_65 ) ;
V_110 = 0 ;
V_21 . V_22 = V_127 -> V_27 ;
V_21 . V_33 = V_127 -> V_36 ;
V_21 . type = V_77 ;
goto V_78;
}
} else {
V_82 = - V_173 ;
goto V_73;
}
}
V_67 = V_65 -> V_83 [ 0 ] ;
V_117 = F_75 ( V_67 , V_65 -> V_84 [ 0 ] ) ;
#ifdef F_79
if ( V_117 < sizeof( * V_116 ) ) {
V_29 = F_85 ( V_109 , V_35 -> V_37 -> V_63 ,
V_65 , ( T_2 ) - 1 , 0 ) ;
if ( V_29 < 0 ) {
V_82 = V_29 ;
goto V_73;
}
V_67 = V_65 -> V_83 [ 0 ] ;
V_117 = F_75 ( V_67 , V_65 -> V_84 [ 0 ] ) ;
}
#endif
F_30 ( V_117 < sizeof( * V_116 ) ) ;
V_116 = F_76 ( V_67 , V_65 -> V_84 [ 0 ] , struct V_115 ) ;
F_128 ( V_128 , V_67 , V_116 ) ;
F_93 ( V_67 ) ;
V_73:
F_49 ( V_65 ) ;
return V_82 ;
}
static int F_154 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
struct V_203 * V_127 ,
struct V_178 * V_128 ,
int V_204 )
{
int V_29 = 0 ;
struct V_212 * V_150 ;
struct V_68 V_206 ;
T_2 V_17 = 0 ;
T_2 V_207 = 0 ;
bool V_171 = F_74 ( V_35 -> V_37 ,
V_120 ) ;
V_150 = F_155 ( V_127 ) ;
F_156 ( V_127 , V_150 , V_127 -> V_208 ) ;
if ( V_127 -> type == V_163 )
V_17 = V_150 -> V_17 ;
else
V_207 = V_150 -> V_35 ;
V_206 . V_22 = V_127 -> V_27 ;
if ( V_171 ) {
V_206 . V_33 = V_150 -> V_165 ;
V_206 . type = V_86 ;
} else {
V_206 . V_33 = V_127 -> V_36 ;
V_206 . type = V_77 ;
}
F_30 ( V_127 -> V_131 != 1 ) ;
if ( V_127 -> V_208 == V_201 && V_204 ) {
F_30 ( ! V_128 || ! V_128 -> V_129 ) ;
V_29 = F_157 ( V_109 , V_35 ,
V_17 , V_207 ,
V_128 -> V_130 ,
& V_128 -> V_21 ,
V_150 -> V_165 , & V_206 ) ;
} else if ( V_127 -> V_208 == V_201 ) {
V_29 = F_145 ( V_109 , V_35 , V_127 -> V_27 ,
V_127 -> V_36 , V_17 , V_207 ,
V_150 -> V_165 , 0 , 1 , V_128 ) ;
} else if ( V_127 -> V_208 == V_209 ) {
V_29 = F_151 ( V_109 , V_35 , V_127 -> V_27 ,
V_127 -> V_36 , V_17 , V_207 ,
V_150 -> V_165 , 0 , 1 , V_128 ) ;
} else {
F_81 () ;
}
return V_29 ;
}
static int F_158 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
struct V_203 * V_127 ,
struct V_178 * V_128 ,
int V_204 )
{
int V_29 = 0 ;
if ( V_109 -> V_211 ) {
if ( V_204 )
F_159 ( V_35 , V_127 -> V_27 ,
V_127 -> V_36 , 1 ) ;
return 0 ;
}
if ( F_160 ( V_127 ) ) {
struct V_112 * V_103 ;
F_30 ( V_128 ) ;
V_103 = F_161 ( V_127 ) ;
F_162 ( V_127 , V_103 , V_127 -> V_208 ) ;
if ( V_204 ) {
F_159 ( V_35 , V_127 -> V_27 ,
V_127 -> V_36 , 1 ) ;
if ( V_103 -> V_182 ) {
V_29 = F_163 ( V_109 , V_35 ,
V_127 -> V_27 ,
V_127 -> V_36 ) ;
}
}
return V_29 ;
}
if ( V_127 -> type == V_164 ||
V_127 -> type == V_163 )
V_29 = F_154 ( V_109 , V_35 , V_127 , V_128 ,
V_204 ) ;
else if ( V_127 -> type == V_154 ||
V_127 -> type == V_153 )
V_29 = F_147 ( V_109 , V_35 , V_127 , V_128 ,
V_204 ) ;
else
F_81 () ;
return V_29 ;
}
T_1 int F_164 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
struct V_102 * V_213 )
{
struct V_113 * V_114 ;
struct V_203 * V_150 ;
struct V_112 * V_214 = NULL ;
struct V_178 * V_128 ;
struct V_12 * V_37 = V_35 -> V_37 ;
int V_29 ;
int V_8 = 0 ;
int V_215 = 0 ;
V_114 = & V_109 -> V_126 -> V_114 ;
while ( 1 ) {
if ( ! V_214 ) {
if ( F_165 ( V_213 ) )
break;
V_214 = F_166 ( V_213 -> V_81 ,
struct V_112 , V_213 ) ;
V_29 = F_167 ( V_109 , V_214 ) ;
if ( V_29 == - V_176 ) {
V_214 = NULL ;
V_8 ++ ;
continue;
}
}
F_168 ( V_109 , V_37 , V_114 ,
V_214 ) ;
V_150 = F_169 ( V_214 ) ;
if ( V_150 && V_150 -> V_216 &&
F_170 ( V_37 , V_114 , V_150 -> V_216 ) ) {
F_171 ( & V_214 -> V_213 ) ;
F_172 ( V_214 ) ;
V_214 = NULL ;
V_114 -> V_217 ++ ;
F_13 ( & V_114 -> V_52 ) ;
F_46 () ;
F_11 ( & V_114 -> V_52 ) ;
continue;
}
V_215 = V_214 -> V_215 ;
V_214 -> V_215 = 0 ;
V_128 = V_214 -> V_128 ;
V_214 -> V_128 = NULL ;
if ( ! V_150 ) {
V_150 = & V_214 -> V_127 ;
if ( V_128 && V_215 ) {
F_173 ( V_128 ) ;
V_128 = NULL ;
}
if ( V_128 ) {
F_13 ( & V_114 -> V_52 ) ;
V_29 = F_153 ( V_109 , V_35 ,
V_150 , V_128 ) ;
F_173 ( V_128 ) ;
if ( V_29 ) {
if ( V_215 )
V_214 -> V_215 = 1 ;
F_174 ( V_37 , L_1 , V_29 ) ;
F_11 ( & V_114 -> V_52 ) ;
F_172 ( V_214 ) ;
return V_29 ;
}
goto V_81;
}
}
V_150 -> V_218 = 0 ;
F_175 ( & V_150 -> V_15 , & V_114 -> V_35 ) ;
V_114 -> V_219 -- ;
if ( ! F_160 ( V_150 ) ) {
switch ( V_150 -> V_208 ) {
case V_201 :
case V_220 :
V_214 -> V_127 . V_131 -= V_150 -> V_131 ;
break;
case V_209 :
V_214 -> V_127 . V_131 += V_150 -> V_131 ;
break;
default:
F_8 ( 1 ) ;
}
} else {
F_171 ( & V_214 -> V_213 ) ;
}
F_13 ( & V_114 -> V_52 ) ;
V_29 = F_158 ( V_109 , V_35 , V_150 , V_128 ,
V_215 ) ;
F_173 ( V_128 ) ;
if ( V_29 ) {
F_172 ( V_214 ) ;
F_84 ( V_150 ) ;
F_174 ( V_37 , L_2 , V_29 ) ;
F_11 ( & V_114 -> V_52 ) ;
return V_29 ;
}
if ( F_160 ( V_150 ) ) {
F_172 ( V_214 ) ;
V_214 = NULL ;
}
F_84 ( V_150 ) ;
V_8 ++ ;
V_81:
F_46 () ;
F_11 ( & V_114 -> V_52 ) ;
}
return V_8 ;
}
static T_2 F_176 ( struct V_221 * V_35 )
{
struct V_15 * V_30 = V_35 -> V_15 ;
struct V_203 * V_222 ;
int V_223 = 1 ;
T_2 V_224 ;
T_2 V_225 = 0 , V_70 = 0 ;
V_30 = F_177 ( V_35 ) ;
if ( V_30 ) {
V_222 = F_12 ( V_30 , struct V_203 , V_15 ) ;
V_225 = V_222 -> V_27 ;
}
V_30 = F_178 ( V_35 ) ;
if ( V_30 ) {
V_222 = F_12 ( V_30 , struct V_203 , V_15 ) ;
V_70 = V_222 -> V_27 ;
}
V_30 = V_35 -> V_15 ;
while ( V_30 ) {
V_222 = F_12 ( V_30 , struct V_203 , V_15 ) ;
F_8 ( ! V_222 -> V_218 ) ;
V_224 = V_222 -> V_27 ;
if ( V_223 )
V_30 = V_30 -> V_23 ;
else
V_30 = V_30 -> V_24 ;
V_223 = 1 - V_223 ;
}
return V_224 ;
}
int F_179 ( struct V_108 * V_109 ,
struct V_12 * V_37 )
{
struct V_226 * V_226 ;
int V_29 = 0 ;
if ( F_165 ( & V_109 -> V_227 ) !=
! V_109 -> V_228 . V_216 ) {
F_180 ( V_37 ,
L_3 ,
F_165 ( & V_109 -> V_227 ) ? L_4 : L_5 ,
( T_3 ) ( V_109 -> V_228 . V_216 >> 32 ) ,
( T_3 ) V_109 -> V_228 . V_216 ) ;
F_81 () ;
}
if ( ! V_109 -> V_228 . V_216 )
return 0 ;
while ( ! F_165 ( & V_109 -> V_227 ) ) {
V_226 = F_181 ( & V_109 -> V_227 ,
struct V_226 , V_91 ) ;
F_182 ( & V_226 -> V_91 ) ;
if ( ! V_29 )
V_29 = F_183 (
V_109 , V_37 , V_226 -> V_127 ,
V_226 -> V_128 ) ;
F_9 ( V_226 ) ;
}
F_184 ( V_37 , & V_109 -> V_228 ) ;
return V_29 ;
}
static int F_185 ( struct V_113 * V_114 , int V_216 ,
int V_8 )
{
int V_229 = F_186 ( & V_114 -> V_230 ) ;
if ( V_229 < V_216 || V_229 >= V_216 + V_8 )
return 1 ;
return 0 ;
}
static inline T_2 F_187 ( struct V_34 * V_35 , T_2 V_231 )
{
T_2 V_36 ;
V_36 = V_231 * ( sizeof( struct V_115 ) +
sizeof( struct V_161 ) ) ;
if ( ! F_74 ( V_35 -> V_37 , V_120 ) )
V_36 += V_231 * sizeof( struct V_137 ) ;
return F_188 ( V_36 , F_189 ( V_35 ) ) ;
}
int F_190 ( struct V_108 * V_109 ,
struct V_34 * V_35 )
{
struct V_232 * V_233 ;
T_2 V_234 = V_109 -> V_126 -> V_114 . V_217 ;
T_2 V_36 ;
int V_29 = 0 ;
V_36 = F_191 ( V_35 , 1 ) ;
V_234 = F_187 ( V_35 , V_234 ) ;
if ( V_234 > 1 )
V_36 += ( V_234 - 1 ) * V_35 -> V_88 ;
V_36 <<= 1 ;
V_233 = & V_35 -> V_37 -> V_235 ;
if ( V_233 -> V_104 -> V_107 )
V_36 <<= 1 ;
F_11 ( & V_233 -> V_52 ) ;
if ( V_233 -> V_10 <= V_36 )
V_29 = 1 ;
F_13 ( & V_233 -> V_52 ) ;
return V_29 ;
}
int F_192 ( struct V_108 * V_109 ,
struct V_34 * V_35 , unsigned long V_8 )
{
struct V_15 * V_127 ;
struct V_113 * V_114 ;
struct V_203 * V_150 ;
struct V_102 V_213 ;
int V_29 ;
T_2 V_236 ;
int V_237 = V_8 == ( unsigned long ) - 1 ;
int V_238 = 0 ;
int V_239 ;
if ( V_109 -> V_211 )
return 0 ;
if ( V_35 == V_35 -> V_37 -> V_63 )
V_35 = V_35 -> V_37 -> V_87 ;
F_179 ( V_109 , V_35 -> V_37 ) ;
V_114 = & V_109 -> V_126 -> V_114 ;
F_53 ( & V_213 ) ;
if ( V_8 == 0 ) {
V_8 = V_114 -> V_219 * 2 ;
V_238 = 1 ;
}
if ( ! V_237 && ! V_238 ) {
int V_240 ;
int V_216 = F_186 ( & V_114 -> V_230 ) ;
V_85:
V_240 = F_193 ( & V_114 -> V_241 , 0 , 1 ) ;
if ( V_240 ) {
F_51 ( V_242 ) ;
if ( V_114 -> V_243 ||
! F_190 ( V_109 , V_35 ) )
return 0 ;
F_57 ( & V_114 -> V_89 , & V_242 ,
V_94 ) ;
V_240 = F_193 ( & V_114 -> V_241 , 0 , 1 ) ;
if ( V_240 ) {
F_58 () ;
F_59 ( & V_114 -> V_89 , & V_242 ) ;
if ( ! F_185 ( V_114 , V_216 , 256 ) )
goto V_85;
else
return 0 ;
} else {
F_59 ( & V_114 -> V_89 , & V_242 ) ;
goto V_78;
}
}
} else {
F_5 ( & V_114 -> V_241 ) ;
}
V_78:
V_239 = 0 ;
F_11 ( & V_114 -> V_52 ) ;
#ifdef F_194
V_114 -> V_244 = F_176 ( & V_114 -> V_35 ) ;
#endif
while ( 1 ) {
if ( ! ( V_237 || V_238 ) &&
! F_190 ( V_109 , V_35 ) )
break;
V_236 = V_114 -> V_244 ;
V_29 = F_195 ( V_109 , & V_213 ,
V_114 -> V_244 ) ;
if ( V_29 )
break;
V_29 = F_164 ( V_109 , V_35 , & V_213 ) ;
if ( V_29 < 0 ) {
F_196 ( & V_213 ) ;
F_13 ( & V_114 -> V_52 ) ;
F_146 ( V_109 , V_35 , V_29 ) ;
F_197 ( & V_114 -> V_241 ) ;
F_48 ( & V_114 -> V_89 ) ;
return V_29 ;
}
F_198 ( V_29 , & V_114 -> V_230 ) ;
V_8 -= F_24 (unsigned long, ret, count) ;
if ( V_8 == 0 )
break;
if ( V_236 >= V_114 -> V_244 ) {
if ( V_239 == 0 ) {
V_239 = 1 ;
} else {
F_30 ( V_237 ) ;
break;
}
}
if ( V_29 ) {
V_239 = 0 ;
}
}
if ( V_237 ) {
if ( ! F_165 ( & V_109 -> V_245 ) ) {
F_13 ( & V_114 -> V_52 ) ;
F_199 ( V_109 , V_35 ) ;
F_11 ( & V_114 -> V_52 ) ;
}
V_127 = F_177 ( & V_114 -> V_35 ) ;
if ( ! V_127 )
goto V_73;
V_8 = ( unsigned long ) - 1 ;
while ( V_127 ) {
V_150 = F_12 ( V_127 , struct V_203 ,
V_15 ) ;
if ( F_160 ( V_150 ) ) {
struct V_112 * V_103 ;
V_103 = F_161 ( V_150 ) ;
F_5 ( & V_150 -> V_111 ) ;
F_13 ( & V_114 -> V_52 ) ;
F_35 ( & V_103 -> V_79 ) ;
F_45 ( & V_103 -> V_79 ) ;
F_84 ( V_150 ) ;
F_46 () ;
goto V_78;
}
V_127 = F_200 ( V_127 ) ;
}
F_13 ( & V_114 -> V_52 ) ;
F_201 ( 1 ) ;
goto V_78;
}
V_73:
F_197 ( & V_114 -> V_241 ) ;
F_2 () ;
if ( F_202 ( & V_114 -> V_89 ) )
F_48 ( & V_114 -> V_89 ) ;
F_13 ( & V_114 -> V_52 ) ;
F_203 ( V_109 ) ;
return 0 ;
}
int F_204 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
T_2 V_27 , T_2 V_36 , T_2 V_7 ,
int V_165 , int V_182 )
{
struct V_178 * V_128 ;
int V_29 ;
V_128 = F_205 () ;
if ( ! V_128 )
return - V_72 ;
V_128 -> V_130 = V_7 ;
V_128 -> V_129 = 1 ;
V_128 -> V_210 = 0 ;
V_128 -> V_182 = V_182 ? 1 : 0 ;
V_128 -> V_165 = V_165 ;
V_29 = F_206 ( V_35 -> V_37 , V_109 , V_27 ,
V_36 , V_128 ) ;
if ( V_29 )
F_173 ( V_128 ) ;
return V_29 ;
}
static T_1 int F_207 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
struct V_64 * V_65 ,
T_2 V_22 , T_2 V_33 , T_2 V_27 )
{
struct V_112 * V_103 ;
struct V_203 * V_150 ;
struct V_205 * V_246 ;
struct V_113 * V_114 ;
struct V_15 * V_127 ;
int V_29 = 0 ;
V_29 = - V_152 ;
V_114 = & V_109 -> V_126 -> V_114 ;
F_11 ( & V_114 -> V_52 ) ;
V_103 = F_82 ( V_109 , V_27 ) ;
if ( ! V_103 )
goto V_73;
if ( ! F_83 ( & V_103 -> V_79 ) ) {
F_5 ( & V_103 -> V_127 . V_111 ) ;
F_13 ( & V_114 -> V_52 ) ;
F_43 ( V_65 ) ;
F_35 ( & V_103 -> V_79 ) ;
F_45 ( & V_103 -> V_79 ) ;
F_84 ( & V_103 -> V_127 ) ;
return - V_176 ;
}
V_127 = F_208 ( & V_103 -> V_127 . V_15 ) ;
if ( ! V_127 )
goto V_247;
V_150 = F_12 ( V_127 , struct V_203 , V_15 ) ;
if ( V_150 -> V_27 != V_27 )
goto V_247;
V_29 = 1 ;
if ( V_150 -> type != V_154 )
goto V_247;
V_246 = F_148 ( V_150 ) ;
V_127 = F_208 ( V_127 ) ;
if ( V_127 ) {
int V_216 = V_150 -> V_216 ;
V_150 = F_12 ( V_127 , struct V_203 , V_15 ) ;
if ( V_150 -> V_27 == V_27 && V_150 -> V_216 == V_216 )
goto V_247;
}
if ( V_246 -> V_35 != V_35 -> V_248 . V_22 ||
V_246 -> V_22 != V_22 || V_246 -> V_33 != V_33 )
goto V_247;
V_29 = 0 ;
V_247:
F_45 ( & V_103 -> V_79 ) ;
V_73:
F_13 ( & V_114 -> V_52 ) ;
return V_29 ;
}
static T_1 int F_209 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
struct V_64 * V_65 ,
T_2 V_22 , T_2 V_33 , T_2 V_27 )
{
struct V_34 * V_63 = V_35 -> V_37 -> V_63 ;
struct V_66 * V_67 ;
struct V_149 * V_150 ;
struct V_161 * V_162 ;
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
V_117 = F_75 ( V_67 , V_65 -> V_84 [ 0 ] ) ;
#ifdef F_79
if ( V_117 < sizeof( * V_116 ) ) {
F_8 ( V_117 != sizeof( struct V_123 ) ) ;
goto V_73;
}
#endif
V_116 = F_76 ( V_67 , V_65 -> V_84 [ 0 ] , struct V_115 ) ;
if ( V_117 != sizeof( * V_116 ) +
F_123 ( V_154 ) )
goto V_73;
if ( F_210 ( V_67 , V_116 ) <=
F_211 ( & V_35 -> V_249 ) )
goto V_73;
V_162 = (struct V_161 * ) ( V_116 + 1 ) ;
if ( F_117 ( V_67 , V_162 ) !=
V_154 )
goto V_73;
V_150 = (struct V_149 * ) ( & V_162 -> V_33 ) ;
if ( F_77 ( V_67 , V_116 ) !=
F_111 ( V_67 , V_150 ) ||
F_98 ( V_67 , V_150 ) !=
V_35 -> V_248 . V_22 ||
F_99 ( V_67 , V_150 ) != V_22 ||
F_100 ( V_67 , V_150 ) != V_33 )
goto V_73;
V_29 = 0 ;
V_73:
return V_29 ;
}
int F_212 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
T_2 V_22 , T_2 V_33 , T_2 V_27 )
{
struct V_64 * V_65 ;
int V_29 ;
int V_250 ;
V_65 = F_33 () ;
if ( ! V_65 )
return - V_152 ;
do {
V_29 = F_209 ( V_109 , V_35 , V_65 , V_22 ,
V_33 , V_27 ) ;
if ( V_29 && V_29 != - V_152 )
goto V_73;
V_250 = F_207 ( V_109 , V_35 , V_65 , V_22 ,
V_33 , V_27 ) ;
} while ( V_250 == - V_176 );
if ( V_250 && V_250 != - V_152 ) {
V_29 = V_250 ;
goto V_73;
}
if ( V_29 != - V_152 || V_250 != - V_152 )
V_29 = 0 ;
V_73:
F_49 ( V_65 ) ;
if ( V_35 -> V_248 . V_22 == V_251 )
F_8 ( V_29 > 0 ) ;
return V_29 ;
}
static int F_213 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
struct V_66 * V_252 ,
int V_253 , int V_254 , int V_199 )
{
T_2 V_27 ;
T_2 V_36 ;
T_2 V_17 ;
T_2 V_207 ;
T_3 V_71 ;
struct V_68 V_21 ;
struct V_255 * V_256 ;
int V_43 ;
int V_165 ;
int V_29 = 0 ;
int (* F_214)( struct V_108 * , struct V_34 * ,
T_2 , T_2 , T_2 , T_2 , T_2 , T_2 , int );
V_207 = F_215 ( V_252 ) ;
V_71 = F_38 ( V_252 ) ;
V_165 = F_216 ( V_252 ) ;
if ( ! V_35 -> V_257 && V_165 == 0 )
return 0 ;
if ( V_254 )
F_214 = F_142 ;
else
F_214 = V_258 ;
if ( V_253 )
V_17 = V_252 -> V_32 ;
else
V_17 = 0 ;
for ( V_43 = 0 ; V_43 < V_71 ; V_43 ++ ) {
if ( V_165 == 0 ) {
F_40 ( V_252 , & V_21 , V_43 ) ;
if ( F_217 ( & V_21 ) != V_259 )
continue;
V_256 = F_76 ( V_252 , V_43 ,
struct V_255 ) ;
if ( F_218 ( V_252 , V_256 ) ==
V_260 )
continue;
V_27 = F_219 ( V_252 , V_256 ) ;
if ( V_27 == 0 )
continue;
V_36 = F_220 ( V_252 , V_256 ) ;
V_21 . V_33 -= F_221 ( V_252 , V_256 ) ;
V_29 = F_214 ( V_109 , V_35 , V_27 , V_36 ,
V_17 , V_207 , V_21 . V_22 ,
V_21 . V_33 , V_199 ) ;
if ( V_29 )
goto V_155;
} else {
V_27 = F_222 ( V_252 , V_43 ) ;
V_36 = F_223 ( V_35 , V_165 - 1 ) ;
V_29 = F_214 ( V_109 , V_35 , V_27 , V_36 ,
V_17 , V_207 , V_165 - 1 , 0 ,
V_199 ) ;
if ( V_29 )
goto V_155;
}
}
return 0 ;
V_155:
return V_29 ;
}
int F_224 ( struct V_108 * V_109 , struct V_34 * V_35 ,
struct V_66 * V_252 , int V_253 , int V_199 )
{
return F_213 ( V_109 , V_35 , V_252 , V_253 , 1 , V_199 ) ;
}
int F_225 ( struct V_108 * V_109 , struct V_34 * V_35 ,
struct V_66 * V_252 , int V_253 , int V_199 )
{
return F_213 ( V_109 , V_35 , V_252 , V_253 , 0 , V_199 ) ;
}
static int F_226 ( struct V_108 * V_109 ,
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
V_138 = F_227 ( V_67 , V_65 -> V_84 [ 0 ] ) ;
F_228 ( V_67 , & V_2 -> V_134 , V_138 , sizeof( V_2 -> V_134 ) ) ;
F_93 ( V_67 ) ;
F_43 ( V_65 ) ;
V_155:
if ( V_29 ) {
F_146 ( V_109 , V_35 , V_29 ) ;
return V_29 ;
}
return 0 ;
}
static struct V_1 *
F_229 ( struct V_34 * V_35 ,
struct V_1 * V_2 )
{
struct V_15 * V_127 ;
F_11 ( & V_35 -> V_37 -> V_18 ) ;
V_127 = F_200 ( & V_2 -> V_20 ) ;
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
static int F_230 ( struct V_1 * V_14 ,
struct V_108 * V_109 ,
struct V_64 * V_65 )
{
struct V_34 * V_35 = V_14 -> V_37 -> V_87 ;
struct V_261 * V_261 = NULL ;
T_2 V_262 = 0 ;
int V_263 = V_264 ;
int V_265 = 0 ;
int V_266 = 0 ;
int V_29 = 0 ;
if ( V_14 -> V_21 . V_33 < ( 100 * 1024 * 1024 ) ) {
F_11 ( & V_14 -> V_52 ) ;
V_14 -> V_267 = V_268 ;
F_13 ( & V_14 -> V_52 ) ;
return 0 ;
}
V_78:
V_261 = F_231 ( V_35 , V_14 , V_65 ) ;
if ( F_232 ( V_261 ) && F_233 ( V_261 ) != - V_152 ) {
V_29 = F_233 ( V_261 ) ;
F_43 ( V_65 ) ;
goto V_73;
}
if ( F_232 ( V_261 ) ) {
F_30 ( V_266 ) ;
V_266 ++ ;
if ( V_14 -> V_269 )
goto V_122;
V_29 = F_234 ( V_35 , V_109 , V_14 , V_65 ) ;
if ( V_29 )
goto V_122;
goto V_78;
}
if ( V_14 -> V_270 == V_109 -> V_271 &&
F_235 ( V_261 ) ) {
V_263 = V_272 ;
goto V_273;
}
F_236 ( V_261 ) -> V_274 = 0 ;
V_29 = F_237 ( V_109 , V_35 , V_261 ) ;
F_8 ( V_29 ) ;
if ( F_235 ( V_261 ) > 0 ) {
V_29 = F_238 ( V_35 ,
& V_35 -> V_37 -> V_235 ) ;
if ( V_29 )
goto V_273;
V_29 = F_239 ( V_35 , V_109 , V_261 ) ;
if ( V_29 )
goto V_273;
}
F_11 ( & V_14 -> V_52 ) ;
if ( V_14 -> V_3 != V_4 ||
! F_240 ( V_35 , V_275 ) ) {
V_263 = V_268 ;
F_13 ( & V_14 -> V_52 ) ;
goto V_273;
}
F_13 ( & V_14 -> V_52 ) ;
V_265 = ( int ) F_188 ( V_14 -> V_21 . V_33 , 256 * 1024 * 1024 ) ;
if ( ! V_265 )
V_265 = 1 ;
V_265 *= 16 ;
V_265 *= V_276 ;
V_29 = F_241 ( V_261 , V_265 ) ;
if ( V_29 )
goto V_273;
V_29 = F_242 ( V_261 , V_109 , 0 , 0 , V_265 ,
V_265 , V_265 ,
& V_262 ) ;
if ( ! V_29 )
V_263 = V_272 ;
F_243 ( V_261 , V_265 ) ;
V_273:
F_244 ( V_261 ) ;
V_122:
F_43 ( V_65 ) ;
V_73:
F_11 ( & V_14 -> V_52 ) ;
if ( ! V_29 && V_263 == V_272 )
V_14 -> V_270 = V_109 -> V_271 ;
V_14 -> V_267 = V_263 ;
F_13 ( & V_14 -> V_52 ) ;
return V_29 ;
}
int F_245 ( struct V_108 * V_109 ,
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
V_2 = F_65 ( V_35 -> V_37 , V_70 ) ;
while ( V_2 ) {
if ( V_2 -> V_267 == V_277 )
break;
V_2 = F_229 ( V_35 , V_2 ) ;
}
if ( ! V_2 ) {
if ( V_70 == 0 )
break;
V_70 = 0 ;
continue;
}
V_82 = F_230 ( V_2 , V_109 , V_65 ) ;
V_70 = V_2 -> V_21 . V_22 + V_2 -> V_21 . V_33 ;
F_6 ( V_2 ) ;
}
while ( 1 ) {
if ( V_70 == 0 ) {
V_82 = F_192 ( V_109 , V_35 ,
( unsigned long ) - 1 ) ;
if ( V_82 )
goto V_73;
}
V_2 = F_65 ( V_35 -> V_37 , V_70 ) ;
while ( V_2 ) {
if ( V_2 -> V_267 == V_277 ) {
F_6 ( V_2 ) ;
goto V_78;
}
if ( V_2 -> V_278 )
break;
V_2 = F_229 ( V_35 , V_2 ) ;
}
if ( ! V_2 ) {
if ( V_70 == 0 )
break;
V_70 = 0 ;
continue;
}
if ( V_2 -> V_267 == V_272 )
V_2 -> V_267 = V_279 ;
V_2 -> V_278 = 0 ;
V_70 = V_2 -> V_21 . V_22 + V_2 -> V_21 . V_33 ;
V_82 = F_226 ( V_109 , V_35 , V_65 , V_2 ) ;
F_6 ( V_2 ) ;
if ( V_82 )
goto V_73;
}
while ( 1 ) {
if ( V_70 == 0 ) {
V_82 = F_192 ( V_109 , V_35 ,
( unsigned long ) - 1 ) ;
if ( V_82 )
goto V_73;
}
V_2 = F_65 ( V_35 -> V_37 , V_70 ) ;
while ( V_2 ) {
if ( V_2 -> V_278 ) {
F_6 ( V_2 ) ;
goto V_78;
}
if ( V_2 -> V_267 == V_279 )
break;
V_2 = F_229 ( V_35 , V_2 ) ;
}
if ( ! V_2 ) {
if ( V_70 == 0 )
break;
V_70 = 0 ;
continue;
}
V_82 = F_246 ( V_35 , V_109 , V_2 , V_65 ) ;
if ( ! V_82 && V_2 -> V_267 == V_279 )
V_2 -> V_267 = V_268 ;
V_70 = V_2 -> V_21 . V_22 + V_2 -> V_21 . V_33 ;
F_6 ( V_2 ) ;
}
V_73:
F_49 ( V_65 ) ;
return V_82 ;
}
int F_247 ( struct V_34 * V_35 , T_2 V_27 )
{
struct V_1 * V_14 ;
int V_280 = 0 ;
V_14 = F_66 ( V_35 -> V_37 , V_27 ) ;
if ( ! V_14 || V_14 -> V_269 )
V_280 = 1 ;
if ( V_14 )
F_6 ( V_14 ) ;
return V_280 ;
}
static int F_248 ( struct V_12 * V_13 , T_2 V_7 ,
T_2 V_281 , T_2 V_282 ,
struct V_101 * * V_104 )
{
struct V_101 * V_105 ;
int V_43 ;
int V_283 ;
int V_29 ;
if ( V_7 & ( V_284 | V_285 |
V_286 ) )
V_283 = 2 ;
else
V_283 = 1 ;
V_105 = F_67 ( V_13 , V_7 ) ;
if ( V_105 ) {
F_11 ( & V_105 -> V_52 ) ;
V_105 -> V_281 += V_281 ;
V_105 -> V_287 += V_281 * V_283 ;
V_105 -> V_282 += V_282 ;
V_105 -> V_288 += V_282 * V_283 ;
V_105 -> V_107 = 0 ;
F_13 ( & V_105 -> V_52 ) ;
* V_104 = V_105 ;
return 0 ;
}
V_105 = F_52 ( sizeof( * V_105 ) , V_40 ) ;
if ( ! V_105 )
return - V_72 ;
V_29 = F_249 ( & V_105 -> V_289 , 0 ) ;
if ( V_29 ) {
F_9 ( V_105 ) ;
return V_29 ;
}
for ( V_43 = 0 ; V_43 < V_290 ; V_43 ++ )
F_53 ( & V_105 -> V_291 [ V_43 ] ) ;
F_250 ( & V_105 -> V_292 ) ;
F_251 ( & V_105 -> V_52 ) ;
V_105 -> V_7 = V_7 & V_106 ;
V_105 -> V_281 = V_281 ;
V_105 -> V_287 = V_281 * V_283 ;
V_105 -> V_282 = V_282 ;
V_105 -> V_288 = V_282 * V_283 ;
V_105 -> V_293 = 0 ;
V_105 -> V_294 = 0 ;
V_105 -> V_295 = 0 ;
V_105 -> V_296 = 0 ;
V_105 -> V_107 = 0 ;
V_105 -> V_297 = V_298 ;
V_105 -> V_299 = 0 ;
V_105 -> V_300 = 0 ;
F_55 ( & V_105 -> V_89 ) ;
* V_104 = V_105 ;
F_252 ( & V_105 -> V_91 , & V_13 -> V_104 ) ;
if ( V_7 & V_301 )
V_13 -> V_302 = V_105 ;
return 0 ;
}
static void F_253 ( struct V_12 * V_37 , T_2 V_7 )
{
T_2 V_303 = F_254 ( V_7 ) &
V_304 ;
F_255 ( & V_37 -> V_305 ) ;
if ( V_7 & V_301 )
V_37 -> V_306 |= V_303 ;
if ( V_7 & V_307 )
V_37 -> V_308 |= V_303 ;
if ( V_7 & V_309 )
V_37 -> V_310 |= V_303 ;
F_256 ( & V_37 -> V_305 ) ;
}
static T_2 F_257 ( struct V_12 * V_37 , T_2 V_7 )
{
struct V_311 * V_312 = V_37 -> V_313 ;
T_2 V_314 = 0 ;
if ( ! V_312 )
return 0 ;
if ( V_7 & V_301 &&
V_312 -> V_315 . V_7 & V_316 ) {
V_314 = V_301 | V_312 -> V_315 . V_314 ;
} else if ( V_7 & V_309 &&
V_312 -> V_317 . V_7 & V_316 ) {
V_314 = V_309 | V_312 -> V_317 . V_314 ;
} else if ( V_7 & V_307 &&
V_312 -> V_318 . V_7 & V_316 ) {
V_314 = V_307 | V_312 -> V_318 . V_314 ;
}
return V_314 ;
}
static T_2 F_258 ( struct V_34 * V_35 , T_2 V_7 )
{
T_2 V_319 = V_35 -> V_37 -> V_320 -> V_321 +
V_35 -> V_37 -> V_320 -> V_322 ;
T_2 V_314 ;
T_2 V_323 ;
F_11 ( & V_35 -> V_37 -> V_324 ) ;
V_314 = F_257 ( V_35 -> V_37 , V_7 ) ;
if ( V_314 ) {
if ( ( V_7 & V_314 ) & V_304 ) {
F_13 ( & V_35 -> V_37 -> V_324 ) ;
return F_259 ( V_314 ) ;
}
}
F_13 ( & V_35 -> V_37 -> V_324 ) ;
if ( V_319 == 1 )
V_7 &= ~ ( V_285 | V_325 |
V_326 ) ;
if ( V_319 < 3 )
V_7 &= ~ V_327 ;
if ( V_319 < 4 )
V_7 &= ~ V_286 ;
V_323 = V_7 & ( V_284 | V_325 |
V_285 | V_326 |
V_327 | V_286 ) ;
V_7 &= ~ V_323 ;
if ( V_323 & V_327 )
V_323 = V_327 ;
else if ( V_323 & V_326 )
V_323 = V_326 ;
else if ( V_323 & V_286 )
V_323 = V_286 ;
else if ( V_323 & V_285 )
V_323 = V_285 ;
else if ( V_323 & V_325 )
V_323 = V_325 ;
return F_259 ( V_7 | V_323 ) ;
}
static T_2 F_260 ( struct V_34 * V_35 , T_2 V_7 )
{
unsigned V_216 ;
do {
V_216 = F_261 ( & V_35 -> V_37 -> V_305 ) ;
if ( V_7 & V_301 )
V_7 |= V_35 -> V_37 -> V_306 ;
else if ( V_7 & V_309 )
V_7 |= V_35 -> V_37 -> V_310 ;
else if ( V_7 & V_307 )
V_7 |= V_35 -> V_37 -> V_308 ;
} while ( F_262 ( & V_35 -> V_37 -> V_305 , V_216 ) );
return F_258 ( V_35 , V_7 ) ;
}
T_2 F_263 ( struct V_34 * V_35 , int V_315 )
{
T_2 V_7 ;
T_2 V_29 ;
if ( V_315 )
V_7 = V_301 ;
else if ( V_35 == V_35 -> V_37 -> V_328 )
V_7 = V_309 ;
else
V_7 = V_307 ;
V_29 = F_260 ( V_35 , V_7 ) ;
return V_29 ;
}
int F_241 ( struct V_261 * V_261 , T_2 V_329 )
{
struct V_101 * V_302 ;
struct V_34 * V_35 = F_236 ( V_261 ) -> V_35 ;
struct V_12 * V_37 = V_35 -> V_37 ;
T_2 V_330 ;
int V_29 = 0 , V_331 = 0 , V_332 = 1 ;
V_329 = F_264 ( V_329 , V_35 -> V_333 ) ;
if ( F_265 ( V_261 ) ) {
V_331 = 1 ;
ASSERT ( V_334 -> V_335 ) ;
}
V_302 = V_37 -> V_302 ;
if ( ! V_302 )
goto V_336;
V_78:
F_11 ( & V_302 -> V_52 ) ;
V_330 = V_302 -> V_282 + V_302 -> V_294 +
V_302 -> V_293 + V_302 -> V_295 +
V_302 -> V_296 ;
if ( V_330 + V_329 > V_302 -> V_281 ) {
struct V_108 * V_109 ;
if ( ! V_302 -> V_107 && V_332 ) {
T_2 V_337 ;
V_302 -> V_297 = V_338 ;
F_13 ( & V_302 -> V_52 ) ;
V_336:
V_337 = F_263 ( V_35 , 1 ) ;
V_109 = F_266 ( V_35 ) ;
if ( F_232 ( V_109 ) )
return F_233 ( V_109 ) ;
V_29 = F_267 ( V_109 , V_35 -> V_37 -> V_63 ,
V_337 ,
V_298 ) ;
F_268 ( V_109 , V_35 ) ;
if ( V_29 < 0 ) {
if ( V_29 != - V_339 )
return V_29 ;
else
goto V_340;
}
if ( ! V_302 )
V_302 = V_37 -> V_302 ;
goto V_78;
}
if ( F_269 ( & V_302 -> V_289 ,
V_329 ) < 0 )
V_331 = 1 ;
F_13 ( & V_302 -> V_52 ) ;
V_340:
if ( ! V_331 &&
! F_186 ( & V_35 -> V_37 -> V_341 ) ) {
V_331 = 1 ;
V_109 = F_266 ( V_35 ) ;
if ( F_232 ( V_109 ) )
return F_233 ( V_109 ) ;
V_29 = F_270 ( V_109 , V_35 ) ;
if ( V_29 )
return V_29 ;
goto V_78;
}
F_271 ( V_35 -> V_37 ,
L_6 ,
V_302 -> V_7 , V_329 , 1 ) ;
return - V_339 ;
}
V_302 -> V_296 += V_329 ;
F_271 ( V_35 -> V_37 , L_7 ,
V_302 -> V_7 , V_329 , 1 ) ;
F_13 ( & V_302 -> V_52 ) ;
return 0 ;
}
void F_243 ( struct V_261 * V_261 , T_2 V_329 )
{
struct V_34 * V_35 = F_236 ( V_261 ) -> V_35 ;
struct V_101 * V_302 ;
V_329 = F_264 ( V_329 , V_35 -> V_333 ) ;
V_302 = V_35 -> V_37 -> V_302 ;
F_11 ( & V_302 -> V_52 ) ;
F_8 ( V_302 -> V_296 < V_329 ) ;
V_302 -> V_296 -= V_329 ;
F_271 ( V_35 -> V_37 , L_7 ,
V_302 -> V_7 , V_329 , 0 ) ;
F_13 ( & V_302 -> V_52 ) ;
}
static void F_272 ( struct V_12 * V_13 )
{
struct V_102 * V_103 = & V_13 -> V_104 ;
struct V_101 * V_105 ;
F_68 () ;
F_69 (found, head, list) {
if ( V_105 -> V_7 & V_307 )
V_105 -> V_297 = V_338 ;
}
F_70 () ;
}
static inline T_2 F_273 ( struct V_232 * V_342 )
{
return ( V_342 -> V_57 << 1 ) ;
}
static int F_274 ( struct V_34 * V_35 ,
struct V_101 * V_343 , int V_344 )
{
struct V_232 * V_233 = & V_35 -> V_37 -> V_235 ;
T_2 V_36 = V_343 -> V_281 - V_343 -> V_295 ;
T_2 V_345 = V_343 -> V_282 + V_343 -> V_294 ;
T_2 V_346 ;
if ( V_344 == V_338 )
return 1 ;
if ( V_343 -> V_7 & V_307 )
V_345 += F_273 ( V_233 ) ;
if ( V_344 == V_347 ) {
V_346 = F_275 ( V_35 -> V_37 -> V_348 ) ;
V_346 = F_34 ( T_2 , 64 * 1024 * 1024 ,
F_276 ( V_346 , 1 ) ) ;
if ( V_36 - V_345 < V_346 )
return 1 ;
}
if ( V_345 + 2 * 1024 * 1024 < F_277 ( V_36 , 8 ) )
return 0 ;
return 1 ;
}
static T_2 F_278 ( struct V_34 * V_35 , T_2 type )
{
T_2 V_349 ;
if ( type & ( V_286 |
V_325 |
V_326 |
V_327 ) )
V_349 = V_35 -> V_37 -> V_320 -> V_321 ;
else if ( type & V_285 )
V_349 = 2 ;
else
V_349 = 1 ;
return F_191 ( V_35 , V_349 + 1 ) ;
}
static void F_279 ( struct V_108 * V_109 ,
struct V_34 * V_35 , T_2 type )
{
struct V_101 * V_13 ;
T_2 V_350 ;
T_2 V_346 ;
V_13 = F_67 ( V_35 -> V_37 , V_309 ) ;
F_11 ( & V_13 -> V_52 ) ;
V_350 = V_13 -> V_281 - V_13 -> V_282 - V_13 -> V_293 -
V_13 -> V_294 - V_13 -> V_295 ;
F_13 ( & V_13 -> V_52 ) ;
V_346 = F_278 ( V_35 , type ) ;
if ( V_350 < V_346 && F_240 ( V_35 , V_351 ) ) {
F_280 ( V_35 -> V_37 , L_8 ,
V_350 , V_346 , type ) ;
F_281 ( V_13 , 0 , 0 ) ;
}
if ( V_350 < V_346 ) {
T_2 V_7 ;
V_7 = F_263 ( V_35 -> V_37 -> V_328 , 0 ) ;
F_282 ( V_109 , V_35 , V_7 ) ;
}
}
static int F_267 ( struct V_108 * V_109 ,
struct V_34 * V_63 , T_2 V_7 , int V_344 )
{
struct V_101 * V_104 ;
struct V_12 * V_37 = V_63 -> V_37 ;
int V_352 = 0 ;
int V_29 = 0 ;
if ( V_109 -> V_353 )
return - V_339 ;
V_104 = F_67 ( V_63 -> V_37 , V_7 ) ;
if ( ! V_104 ) {
V_29 = F_248 ( V_63 -> V_37 , V_7 ,
0 , 0 , & V_104 ) ;
F_30 ( V_29 ) ;
}
F_30 ( ! V_104 ) ;
V_78:
F_11 ( & V_104 -> V_52 ) ;
if ( V_344 < V_104 -> V_297 )
V_344 = V_104 -> V_297 ;
if ( V_104 -> V_107 ) {
if ( F_274 ( V_63 , V_104 , V_344 ) )
V_29 = - V_339 ;
else
V_29 = 0 ;
F_13 ( & V_104 -> V_52 ) ;
return V_29 ;
}
if ( ! F_274 ( V_63 , V_104 , V_344 ) ) {
F_13 ( & V_104 -> V_52 ) ;
return 0 ;
} else if ( V_104 -> V_299 ) {
V_352 = 1 ;
} else {
V_104 -> V_299 = 1 ;
}
F_13 ( & V_104 -> V_52 ) ;
F_35 ( & V_37 -> V_354 ) ;
if ( V_352 ) {
F_45 ( & V_37 -> V_354 ) ;
V_352 = 0 ;
goto V_78;
}
V_109 -> V_353 = true ;
if ( F_283 ( V_104 ) )
V_7 |= ( V_301 | V_307 ) ;
if ( V_7 & V_301 && V_37 -> V_355 ) {
V_37 -> V_356 ++ ;
if ( ! ( V_37 -> V_356 %
V_37 -> V_355 ) )
F_272 ( V_37 ) ;
}
F_279 ( V_109 , V_63 , V_7 ) ;
V_29 = F_282 ( V_109 , V_63 , V_7 ) ;
V_109 -> V_353 = false ;
F_11 ( & V_104 -> V_52 ) ;
if ( V_29 < 0 && V_29 != - V_339 )
goto V_73;
if ( V_29 )
V_104 -> V_107 = 1 ;
else
V_29 = 1 ;
V_104 -> V_297 = V_298 ;
V_73:
V_104 -> V_299 = 0 ;
F_13 ( & V_104 -> V_52 ) ;
F_45 ( & V_37 -> V_354 ) ;
return V_29 ;
}
static int F_284 ( struct V_34 * V_35 ,
struct V_101 * V_104 , T_2 V_329 ,
enum V_357 V_300 )
{
struct V_232 * V_233 = & V_35 -> V_37 -> V_235 ;
T_2 V_358 = F_263 ( V_35 , 0 ) ;
T_2 V_359 ;
T_2 V_360 ;
T_2 V_330 ;
V_330 = V_104 -> V_282 + V_104 -> V_294 +
V_104 -> V_293 + V_104 -> V_295 ;
F_11 ( & V_233 -> V_52 ) ;
V_359 = F_273 ( V_233 ) ;
F_13 ( & V_233 -> V_52 ) ;
if ( V_330 + V_359 >= V_104 -> V_281 )
return 0 ;
V_330 += V_104 -> V_296 ;
F_11 ( & V_35 -> V_37 -> V_361 ) ;
V_360 = V_35 -> V_37 -> V_362 ;
F_13 ( & V_35 -> V_37 -> V_361 ) ;
if ( V_358 & ( V_284 |
V_285 |
V_286 ) )
V_360 >>= 1 ;
if ( V_300 == V_363 )
V_360 >>= 3 ;
else
V_360 >>= 1 ;
if ( V_330 + V_329 < V_104 -> V_281 + V_360 )
return 1 ;
return 0 ;
}
static void F_285 ( struct V_34 * V_35 ,
unsigned long V_364 )
{
struct V_365 * V_366 = V_35 -> V_37 -> V_366 ;
if ( F_286 ( & V_366 -> V_367 ) ) {
F_287 ( V_366 , V_364 , V_368 ) ;
F_44 ( & V_366 -> V_367 ) ;
} else {
F_288 ( V_35 -> V_37 , 0 ) ;
if ( ! V_334 -> V_335 )
F_289 ( V_35 -> V_37 , - 1 ) ;
}
}
static inline int F_290 ( struct V_34 * V_35 , T_2 V_369 )
{
T_2 V_329 ;
int V_44 ;
V_329 = F_191 ( V_35 , 1 ) ;
V_44 = ( int ) F_188 ( V_369 , V_329 ) ;
if ( ! V_44 )
V_44 = 1 ;
return V_44 ;
}
static void F_291 ( struct V_34 * V_35 , T_2 V_369 , T_2 V_370 ,
bool V_371 )
{
struct V_232 * V_372 ;
struct V_101 * V_104 ;
struct V_108 * V_109 ;
T_2 V_373 ;
T_2 V_374 ;
long V_375 ;
unsigned long V_364 ;
int V_239 ;
int V_376 ;
enum V_357 V_300 ;
V_376 = F_290 ( V_35 , V_369 ) ;
V_369 = V_376 * V_377 ;
V_109 = (struct V_108 * ) V_334 -> V_335 ;
V_372 = & V_35 -> V_37 -> V_378 ;
V_104 = V_372 -> V_104 ;
V_373 = F_292 (
& V_35 -> V_37 -> V_373 ) ;
if ( V_373 == 0 ) {
if ( V_109 )
return;
if ( V_371 )
F_289 ( V_35 -> V_37 , V_376 ) ;
return;
}
V_239 = 0 ;
while ( V_373 && V_239 < 3 ) {
V_374 = F_293 ( V_373 , V_369 ) ;
V_364 = V_374 >> V_379 ;
F_285 ( V_35 , V_364 ) ;
V_374 = F_186 ( & V_35 -> V_37 -> V_380 ) ;
if ( ! V_374 )
goto V_381;
if ( V_374 <= V_364 )
V_374 = 0 ;
else
V_374 -= V_364 ;
F_294 ( V_35 -> V_37 -> V_382 ,
F_186 ( & V_35 -> V_37 -> V_380 ) <=
( int ) V_374 ) ;
V_381:
if ( ! V_109 )
V_300 = V_363 ;
else
V_300 = V_383 ;
F_11 ( & V_104 -> V_52 ) ;
if ( F_284 ( V_35 , V_104 , V_370 , V_300 ) ) {
F_13 ( & V_104 -> V_52 ) ;
break;
}
F_13 ( & V_104 -> V_52 ) ;
V_239 ++ ;
if ( V_371 && ! V_109 ) {
F_289 ( V_35 -> V_37 , V_376 ) ;
} else {
V_375 = F_295 ( 1 ) ;
if ( V_375 )
break;
}
V_373 = F_292 (
& V_35 -> V_37 -> V_373 ) ;
}
}
static int F_296 ( struct V_34 * V_35 ,
struct V_101 * V_104 ,
T_2 V_329 , int V_344 )
{
struct V_232 * V_384 = & V_35 -> V_37 -> V_385 ;
struct V_108 * V_109 ;
V_109 = (struct V_108 * ) V_334 -> V_335 ;
if ( V_109 )
return - V_176 ;
if ( V_344 )
goto V_386;
F_11 ( & V_104 -> V_52 ) ;
if ( F_269 ( & V_104 -> V_289 ,
V_329 ) >= 0 ) {
F_13 ( & V_104 -> V_52 ) ;
goto V_386;
}
F_13 ( & V_104 -> V_52 ) ;
if ( V_104 != V_384 -> V_104 )
return - V_339 ;
F_11 ( & V_104 -> V_52 ) ;
F_11 ( & V_384 -> V_52 ) ;
if ( F_269 ( & V_104 -> V_289 ,
V_329 - V_384 -> V_57 ) >= 0 ) {
F_13 ( & V_384 -> V_52 ) ;
F_13 ( & V_104 -> V_52 ) ;
return - V_339 ;
}
F_13 ( & V_384 -> V_52 ) ;
F_13 ( & V_104 -> V_52 ) ;
V_386:
V_109 = F_266 ( V_35 ) ;
if ( F_232 ( V_109 ) )
return - V_339 ;
return F_270 ( V_109 , V_35 ) ;
}
static int F_297 ( struct V_34 * V_35 ,
struct V_101 * V_104 , T_2 V_36 ,
T_2 V_387 , int V_388 )
{
struct V_108 * V_109 ;
int V_44 ;
int V_29 = 0 ;
switch ( V_388 ) {
case V_389 :
case V_390 :
if ( V_388 == V_389 )
V_44 = F_290 ( V_35 , V_36 ) * 2 ;
else
V_44 = - 1 ;
V_109 = F_266 ( V_35 ) ;
if ( F_232 ( V_109 ) ) {
V_29 = F_233 ( V_109 ) ;
break;
}
V_29 = F_298 ( V_109 , V_35 , V_44 ) ;
F_268 ( V_109 , V_35 ) ;
break;
case V_391 :
case V_392 :
F_291 ( V_35 , V_36 , V_387 ,
V_388 == V_392 ) ;
break;
case V_393 :
V_109 = F_266 ( V_35 ) ;
if ( F_232 ( V_109 ) ) {
V_29 = F_233 ( V_109 ) ;
break;
}
V_29 = F_267 ( V_109 , V_35 -> V_37 -> V_63 ,
F_263 ( V_35 , 0 ) ,
V_298 ) ;
F_268 ( V_109 , V_35 ) ;
if ( V_29 == - V_339 )
V_29 = 0 ;
break;
case V_394 :
V_29 = F_296 ( V_35 , V_104 , V_387 , 0 ) ;
break;
default:
V_29 = - V_339 ;
break;
}
return V_29 ;
}
static int F_299 ( struct V_34 * V_35 ,
struct V_232 * V_372 ,
T_2 V_387 ,
enum V_357 V_300 )
{
struct V_101 * V_104 = V_372 -> V_104 ;
T_2 V_330 ;
T_2 V_36 = V_387 ;
int V_395 = V_389 ;
int V_29 = 0 ;
bool V_243 = false ;
V_78:
V_29 = 0 ;
F_11 ( & V_104 -> V_52 ) ;
while ( V_300 == V_363 && ! V_243 &&
V_104 -> V_300 ) {
F_13 ( & V_104 -> V_52 ) ;
if ( V_334 -> V_335 )
return - V_176 ;
V_29 = F_300 ( V_104 -> V_89 , ! V_104 -> V_300 ) ;
if ( V_29 )
return - V_396 ;
F_11 ( & V_104 -> V_52 ) ;
}
V_29 = - V_339 ;
V_330 = V_104 -> V_282 + V_104 -> V_294 +
V_104 -> V_293 + V_104 -> V_295 +
V_104 -> V_296 ;
if ( V_330 <= V_104 -> V_281 ) {
if ( V_330 + V_387 <= V_104 -> V_281 ) {
V_104 -> V_296 += V_387 ;
F_271 ( V_35 -> V_37 ,
L_7 , V_104 -> V_7 , V_387 , 1 ) ;
V_29 = 0 ;
} else {
V_36 = V_387 ;
}
} else {
V_36 = V_330 - V_104 -> V_281 +
( V_387 * 2 ) ;
}
if ( V_29 && F_284 ( V_35 , V_104 , V_387 , V_300 ) ) {
V_104 -> V_296 += V_387 ;
F_271 ( V_35 -> V_37 , L_7 ,
V_104 -> V_7 , V_387 ,
1 ) ;
V_29 = 0 ;
}
if ( V_29 && V_300 != V_383 ) {
V_243 = true ;
V_104 -> V_300 = 1 ;
}
F_13 ( & V_104 -> V_52 ) ;
if ( ! V_29 || V_300 == V_383 )
goto V_73;
V_29 = F_297 ( V_35 , V_104 , V_36 , V_387 ,
V_395 ) ;
V_395 ++ ;
if ( V_300 == V_397 &&
( V_395 == V_391 ||
V_395 == V_392 ) )
V_395 = V_393 ;
if ( ! V_29 )
goto V_78;
else if ( V_300 == V_397 &&
V_395 < V_394 )
goto V_78;
else if ( V_300 == V_363 &&
V_395 <= V_394 )
goto V_78;
V_73:
if ( V_29 == - V_339 &&
F_301 ( V_35 -> V_398 == V_399 ) ) {
struct V_232 * V_233 =
& V_35 -> V_37 -> V_235 ;
if ( V_372 != V_233 &&
! F_302 ( V_233 , V_387 ) )
V_29 = 0 ;
}
if ( V_29 == - V_339 )
F_271 ( V_35 -> V_37 ,
L_6 ,
V_104 -> V_7 , V_387 , 1 ) ;
if ( V_243 ) {
F_11 ( & V_104 -> V_52 ) ;
V_104 -> V_300 = 0 ;
F_303 ( & V_104 -> V_89 ) ;
F_13 ( & V_104 -> V_52 ) ;
}
return V_29 ;
}
static struct V_232 * F_304 (
const struct V_108 * V_109 ,
const struct V_34 * V_35 )
{
struct V_232 * V_372 = NULL ;
if ( V_35 -> V_257 )
V_372 = V_109 -> V_372 ;
if ( V_35 == V_35 -> V_37 -> V_400 && V_109 -> V_401 )
V_372 = V_109 -> V_372 ;
if ( V_35 == V_35 -> V_37 -> V_402 )
V_372 = V_109 -> V_372 ;
if ( ! V_372 )
V_372 = V_35 -> V_372 ;
if ( ! V_372 )
V_372 = & V_35 -> V_37 -> V_403 ;
return V_372 ;
}
static int F_302 ( struct V_232 * V_372 ,
T_2 V_36 )
{
int V_29 = - V_339 ;
F_11 ( & V_372 -> V_52 ) ;
if ( V_372 -> V_10 >= V_36 ) {
V_372 -> V_10 -= V_36 ;
if ( V_372 -> V_10 < V_372 -> V_57 )
V_372 -> V_107 = 0 ;
V_29 = 0 ;
}
F_13 ( & V_372 -> V_52 ) ;
return V_29 ;
}
static void F_305 ( struct V_232 * V_372 ,
T_2 V_36 , int V_404 )
{
F_11 ( & V_372 -> V_52 ) ;
V_372 -> V_10 += V_36 ;
if ( V_404 )
V_372 -> V_57 += V_36 ;
else if ( V_372 -> V_10 >= V_372 -> V_57 )
V_372 -> V_107 = 1 ;
F_13 ( & V_372 -> V_52 ) ;
}
int F_306 ( struct V_12 * V_37 ,
struct V_232 * V_405 , T_2 V_36 ,
int V_406 )
{
struct V_232 * V_233 = & V_37 -> V_235 ;
T_2 V_407 ;
if ( V_233 -> V_104 != V_405 -> V_104 )
return - V_339 ;
F_11 ( & V_233 -> V_52 ) ;
V_407 = F_277 ( V_233 -> V_57 , V_406 ) ;
if ( V_233 -> V_10 < V_407 + V_36 ) {
F_13 ( & V_233 -> V_52 ) ;
return - V_339 ;
}
V_233 -> V_10 -= V_36 ;
if ( V_233 -> V_10 < V_233 -> V_57 )
V_233 -> V_107 = 0 ;
F_13 ( & V_233 -> V_52 ) ;
F_305 ( V_405 , V_36 , 1 ) ;
return 0 ;
}
static void F_307 ( struct V_12 * V_37 ,
struct V_232 * V_372 ,
struct V_232 * V_405 , T_2 V_36 )
{
struct V_101 * V_104 = V_372 -> V_104 ;
F_11 ( & V_372 -> V_52 ) ;
if ( V_36 == ( T_2 ) - 1 )
V_36 = V_372 -> V_57 ;
V_372 -> V_57 -= V_36 ;
if ( V_372 -> V_10 >= V_372 -> V_57 ) {
V_36 = V_372 -> V_10 - V_372 -> V_57 ;
V_372 -> V_10 = V_372 -> V_57 ;
V_372 -> V_107 = 1 ;
} else {
V_36 = 0 ;
}
F_13 ( & V_372 -> V_52 ) ;
if ( V_36 > 0 ) {
if ( V_405 ) {
F_11 ( & V_405 -> V_52 ) ;
if ( ! V_405 -> V_107 ) {
T_2 V_408 ;
V_408 = V_405 -> V_57 - V_405 -> V_10 ;
V_408 = F_293 ( V_36 , V_408 ) ;
V_405 -> V_10 += V_408 ;
if ( V_405 -> V_10 >= V_405 -> V_57 )
V_405 -> V_107 = 1 ;
V_36 -= V_408 ;
}
F_13 ( & V_405 -> V_52 ) ;
}
if ( V_36 ) {
F_11 ( & V_104 -> V_52 ) ;
V_104 -> V_296 -= V_36 ;
F_271 ( V_37 , L_7 ,
V_104 -> V_7 , V_36 , 0 ) ;
F_13 ( & V_104 -> V_52 ) ;
}
}
}
static int F_308 ( struct V_232 * V_409 ,
struct V_232 * V_410 , T_2 V_36 )
{
int V_29 ;
V_29 = F_302 ( V_409 , V_36 ) ;
if ( V_29 )
return V_29 ;
F_305 ( V_410 , V_36 , 1 ) ;
return 0 ;
}
void F_309 ( struct V_232 * V_411 , unsigned short type )
{
memset ( V_411 , 0 , sizeof( * V_411 ) ) ;
F_251 ( & V_411 -> V_52 ) ;
V_411 -> type = type ;
}
struct V_232 * F_310 ( struct V_34 * V_35 ,
unsigned short type )
{
struct V_232 * V_372 ;
struct V_12 * V_37 = V_35 -> V_37 ;
V_372 = F_311 ( sizeof( * V_372 ) , V_40 ) ;
if ( ! V_372 )
return NULL ;
F_309 ( V_372 , type ) ;
V_372 -> V_104 = F_67 ( V_37 ,
V_307 ) ;
return V_372 ;
}
void F_312 ( struct V_34 * V_35 ,
struct V_232 * V_411 )
{
if ( ! V_411 )
return;
F_313 ( V_35 , V_411 , ( T_2 ) - 1 ) ;
F_9 ( V_411 ) ;
}
int F_314 ( struct V_34 * V_35 ,
struct V_232 * V_372 , T_2 V_36 ,
enum V_357 V_300 )
{
int V_29 ;
if ( V_36 == 0 )
return 0 ;
V_29 = F_299 ( V_35 , V_372 , V_36 , V_300 ) ;
if ( ! V_29 ) {
F_305 ( V_372 , V_36 , 1 ) ;
return 0 ;
}
return V_29 ;
}
int F_315 ( struct V_34 * V_35 ,
struct V_232 * V_372 , int V_406 )
{
T_2 V_36 = 0 ;
int V_29 = - V_339 ;
if ( ! V_372 )
return 0 ;
F_11 ( & V_372 -> V_52 ) ;
V_36 = F_277 ( V_372 -> V_57 , V_406 ) ;
if ( V_372 -> V_10 >= V_36 )
V_29 = 0 ;
F_13 ( & V_372 -> V_52 ) ;
return V_29 ;
}
int F_316 ( struct V_34 * V_35 ,
struct V_232 * V_372 , T_2 V_412 ,
enum V_357 V_300 )
{
T_2 V_36 = 0 ;
int V_29 = - V_339 ;
if ( ! V_372 )
return 0 ;
F_11 ( & V_372 -> V_52 ) ;
V_36 = V_412 ;
if ( V_372 -> V_10 >= V_36 )
V_29 = 0 ;
else
V_36 -= V_372 -> V_10 ;
F_13 ( & V_372 -> V_52 ) ;
if ( ! V_29 )
return 0 ;
V_29 = F_299 ( V_35 , V_372 , V_36 , V_300 ) ;
if ( ! V_29 ) {
F_305 ( V_372 , V_36 , 0 ) ;
return 0 ;
}
return V_29 ;
}
int F_317 ( struct V_232 * V_413 ,
struct V_232 * V_414 ,
T_2 V_36 )
{
return F_308 ( V_413 , V_414 , V_36 ) ;
}
void F_313 ( struct V_34 * V_35 ,
struct V_232 * V_372 ,
T_2 V_36 )
{
struct V_232 * V_233 = & V_35 -> V_37 -> V_235 ;
if ( V_233 -> V_107 || V_233 == V_372 ||
V_372 -> V_104 != V_233 -> V_104 )
V_233 = NULL ;
F_307 ( V_35 -> V_37 , V_372 , V_233 ,
V_36 ) ;
}
static T_2 F_318 ( struct V_12 * V_37 )
{
struct V_101 * V_343 ;
T_2 V_36 ;
T_2 V_415 ;
T_2 V_416 ;
int V_417 = F_319 ( V_37 -> V_348 ) ;
V_343 = F_67 ( V_37 , V_301 ) ;
F_11 ( & V_343 -> V_52 ) ;
V_416 = V_343 -> V_282 ;
F_13 ( & V_343 -> V_52 ) ;
V_343 = F_67 ( V_37 , V_307 ) ;
F_11 ( & V_343 -> V_52 ) ;
if ( V_343 -> V_7 & V_301 )
V_416 = 0 ;
V_415 = V_343 -> V_282 ;
F_13 ( & V_343 -> V_52 ) ;
V_36 = ( V_416 >> V_37 -> V_366 -> V_418 ) *
V_417 * 2 ;
V_36 += F_188 ( V_416 + V_415 , 50 ) ;
if ( V_36 * 3 > V_415 )
V_36 = F_188 ( V_415 , 3 ) ;
return F_264 ( V_36 , V_37 -> V_63 -> V_88 << 10 ) ;
}
static void F_320 ( struct V_12 * V_37 )
{
struct V_232 * V_372 = & V_37 -> V_235 ;
struct V_101 * V_343 = V_372 -> V_104 ;
T_2 V_36 ;
V_36 = F_318 ( V_37 ) ;
F_11 ( & V_343 -> V_52 ) ;
F_11 ( & V_372 -> V_52 ) ;
V_372 -> V_57 = F_24 ( T_2 , V_36 , 512 * 1024 * 1024 ) ;
V_36 = V_343 -> V_282 + V_343 -> V_293 +
V_343 -> V_294 + V_343 -> V_295 +
V_343 -> V_296 ;
if ( V_343 -> V_281 > V_36 ) {
V_36 = V_343 -> V_281 - V_36 ;
V_372 -> V_10 += V_36 ;
V_343 -> V_296 += V_36 ;
F_271 ( V_37 , L_7 ,
V_343 -> V_7 , V_36 , 1 ) ;
}
if ( V_372 -> V_10 >= V_372 -> V_57 ) {
V_36 = V_372 -> V_10 - V_372 -> V_57 ;
V_343 -> V_296 -= V_36 ;
F_271 ( V_37 , L_7 ,
V_343 -> V_7 , V_36 , 0 ) ;
V_372 -> V_10 = V_372 -> V_57 ;
V_372 -> V_107 = 1 ;
}
F_13 ( & V_372 -> V_52 ) ;
F_13 ( & V_343 -> V_52 ) ;
}
static void F_321 ( struct V_12 * V_37 )
{
struct V_101 * V_104 ;
V_104 = F_67 ( V_37 , V_309 ) ;
V_37 -> V_419 . V_104 = V_104 ;
V_104 = F_67 ( V_37 , V_307 ) ;
V_37 -> V_235 . V_104 = V_104 ;
V_37 -> V_378 . V_104 = V_104 ;
V_37 -> V_420 . V_104 = V_104 ;
V_37 -> V_403 . V_104 = V_104 ;
V_37 -> V_385 . V_104 = V_104 ;
V_37 -> V_63 -> V_372 = & V_37 -> V_235 ;
V_37 -> V_400 -> V_372 = & V_37 -> V_235 ;
V_37 -> V_421 -> V_372 = & V_37 -> V_235 ;
V_37 -> V_87 -> V_372 = & V_37 -> V_235 ;
if ( V_37 -> V_422 )
V_37 -> V_422 -> V_372 = & V_37 -> V_235 ;
V_37 -> V_328 -> V_372 = & V_37 -> V_419 ;
F_320 ( V_37 ) ;
}
static void F_322 ( struct V_12 * V_37 )
{
F_307 ( V_37 , & V_37 -> V_235 , NULL ,
( T_2 ) - 1 ) ;
F_8 ( V_37 -> V_378 . V_57 > 0 ) ;
F_8 ( V_37 -> V_378 . V_10 > 0 ) ;
F_8 ( V_37 -> V_420 . V_57 > 0 ) ;
F_8 ( V_37 -> V_420 . V_10 > 0 ) ;
F_8 ( V_37 -> V_419 . V_57 > 0 ) ;
F_8 ( V_37 -> V_419 . V_10 > 0 ) ;
F_8 ( V_37 -> V_385 . V_57 > 0 ) ;
F_8 ( V_37 -> V_385 . V_10 > 0 ) ;
}
void F_323 ( struct V_108 * V_109 ,
struct V_34 * V_35 )
{
if ( ! V_109 -> V_372 )
return;
if ( ! V_109 -> V_294 )
return;
F_271 ( V_35 -> V_37 , L_9 ,
V_109 -> V_271 , V_109 -> V_294 , 0 ) ;
F_313 ( V_35 , V_109 -> V_372 , V_109 -> V_294 ) ;
V_109 -> V_294 = 0 ;
}
int F_324 ( struct V_108 * V_109 ,
struct V_261 * V_261 )
{
struct V_34 * V_35 = F_236 ( V_261 ) -> V_35 ;
struct V_232 * V_413 = F_304 ( V_109 , V_35 ) ;
struct V_232 * V_414 = V_35 -> V_423 ;
T_2 V_36 = F_191 ( V_35 , 1 ) ;
F_271 ( V_35 -> V_37 , L_10 ,
F_325 ( V_261 ) , V_36 , 1 ) ;
return F_308 ( V_413 , V_414 , V_36 ) ;
}
void F_326 ( struct V_261 * V_261 )
{
struct V_34 * V_35 = F_236 ( V_261 ) -> V_35 ;
T_2 V_36 = F_191 ( V_35 , 1 ) ;
F_271 ( V_35 -> V_37 , L_10 ,
F_325 ( V_261 ) , V_36 , 0 ) ;
F_313 ( V_35 , V_35 -> V_423 , V_36 ) ;
}
int F_327 ( struct V_34 * V_35 ,
struct V_232 * V_411 ,
int V_376 ,
T_2 * V_424 ,
bool V_425 )
{
T_2 V_36 ;
int V_29 ;
struct V_232 * V_233 = & V_35 -> V_37 -> V_235 ;
if ( V_35 -> V_37 -> V_426 ) {
V_36 = 3 * V_35 -> V_88 ;
V_29 = F_328 ( V_35 , V_36 ) ;
if ( V_29 )
return V_29 ;
} else {
V_36 = 0 ;
}
* V_424 = V_36 ;
V_36 = F_191 ( V_35 , V_376 ) ;
V_411 -> V_104 = F_67 ( V_35 -> V_37 ,
V_307 ) ;
V_29 = F_314 ( V_35 , V_411 , V_36 ,
V_363 ) ;
if ( V_29 == - V_339 && V_425 )
V_29 = F_317 ( V_233 , V_411 , V_36 ) ;
if ( V_29 ) {
if ( * V_424 )
F_329 ( V_35 , * V_424 ) ;
}
return V_29 ;
}
void F_330 ( struct V_34 * V_35 ,
struct V_232 * V_411 ,
T_2 V_424 )
{
F_313 ( V_35 , V_411 , ( T_2 ) - 1 ) ;
if ( V_424 )
F_329 ( V_35 , V_424 ) ;
}
static unsigned F_331 ( struct V_261 * V_261 )
{
unsigned V_427 = 0 ;
unsigned V_428 = 0 ;
F_30 ( ! F_236 ( V_261 ) -> V_429 ) ;
F_236 ( V_261 ) -> V_429 -- ;
if ( F_236 ( V_261 ) -> V_429 == 0 &&
F_332 ( V_430 ,
& F_236 ( V_261 ) -> V_431 ) )
V_427 = 1 ;
if ( F_236 ( V_261 ) -> V_429 >=
F_236 ( V_261 ) -> V_432 )
return V_427 ;
V_428 = F_236 ( V_261 ) -> V_432 -
F_236 ( V_261 ) -> V_429 ;
F_236 ( V_261 ) -> V_432 -= V_428 ;
return V_428 + V_427 ;
}
static T_2 F_333 ( struct V_261 * V_261 , T_2 V_36 ,
int V_433 )
{
struct V_34 * V_35 = F_236 ( V_261 ) -> V_35 ;
T_2 V_417 ;
int V_434 ;
int V_435 ;
int V_436 ;
if ( F_236 ( V_261 ) -> V_7 & V_437 &&
F_236 ( V_261 ) -> V_438 == 0 )
return 0 ;
V_436 = ( int ) F_188 ( F_236 ( V_261 ) -> V_438 , V_35 -> V_333 ) ;
if ( V_433 )
F_236 ( V_261 ) -> V_438 += V_36 ;
else
F_236 ( V_261 ) -> V_438 -= V_36 ;
V_417 = F_189 ( V_35 ) - sizeof( struct V_439 ) ;
V_434 = ( int ) F_188 ( V_417 ,
sizeof( struct V_440 ) +
sizeof( struct V_441 ) ) ;
V_435 = ( int ) F_188 ( F_236 ( V_261 ) -> V_438 , V_35 -> V_333 ) ;
V_435 = V_435 + V_434 - 1 ;
V_435 = V_435 / V_434 ;
V_436 = V_436 + V_434 - 1 ;
V_436 = V_436 / V_434 ;
if ( V_436 == V_435 )
return 0 ;
if ( V_433 )
return F_191 ( V_35 ,
V_435 - V_436 ) ;
return F_191 ( V_35 , V_436 - V_435 ) ;
}
int F_334 ( struct V_261 * V_261 , T_2 V_36 )
{
struct V_34 * V_35 = F_236 ( V_261 ) -> V_35 ;
struct V_232 * V_372 = & V_35 -> V_37 -> V_378 ;
T_2 V_442 = 0 ;
T_2 V_438 ;
unsigned V_443 = 0 ;
int V_444 = 0 ;
enum V_357 V_300 = V_363 ;
int V_29 = 0 ;
bool V_445 = true ;
T_2 V_446 = 0 ;
unsigned V_447 ;
if ( F_265 ( V_261 ) ) {
V_300 = V_383 ;
V_445 = false ;
}
if ( V_300 != V_383 &&
F_335 ( V_35 -> V_37 ) )
F_201 ( 1 ) ;
if ( V_445 )
F_35 ( & F_236 ( V_261 ) -> V_448 ) ;
V_36 = F_264 ( V_36 , V_35 -> V_333 ) ;
F_11 ( & F_236 ( V_261 ) -> V_52 ) ;
F_236 ( V_261 ) -> V_429 ++ ;
if ( F_236 ( V_261 ) -> V_429 >
F_236 ( V_261 ) -> V_432 )
V_443 = F_236 ( V_261 ) -> V_429 -
F_236 ( V_261 ) -> V_432 ;
if ( ! F_336 ( V_430 ,
& F_236 ( V_261 ) -> V_431 ) ) {
V_443 ++ ;
V_444 = 1 ;
}
V_442 = F_191 ( V_35 , V_443 ) ;
V_442 += F_333 ( V_261 , V_36 , 1 ) ;
V_438 = F_236 ( V_261 ) -> V_438 ;
F_13 ( & F_236 ( V_261 ) -> V_52 ) ;
if ( V_35 -> V_37 -> V_426 ) {
V_29 = F_328 ( V_35 , V_36 +
V_443 * V_35 -> V_88 ) ;
if ( V_29 )
goto V_449;
}
V_29 = F_299 ( V_35 , V_372 , V_442 , V_300 ) ;
if ( F_301 ( V_29 ) ) {
if ( V_35 -> V_37 -> V_426 )
F_329 ( V_35 , V_36 +
V_443 * V_35 -> V_88 ) ;
goto V_449;
}
F_11 ( & F_236 ( V_261 ) -> V_52 ) ;
if ( V_444 ) {
F_337 ( V_430 ,
& F_236 ( V_261 ) -> V_431 ) ;
V_443 -- ;
}
F_236 ( V_261 ) -> V_432 += V_443 ;
F_13 ( & F_236 ( V_261 ) -> V_52 ) ;
if ( V_445 )
F_45 ( & F_236 ( V_261 ) -> V_448 ) ;
if ( V_442 )
F_271 ( V_35 -> V_37 , L_11 ,
F_325 ( V_261 ) , V_442 , 1 ) ;
F_305 ( V_372 , V_442 , 1 ) ;
return 0 ;
V_449:
F_11 ( & F_236 ( V_261 ) -> V_52 ) ;
V_447 = F_331 ( V_261 ) ;
if ( F_236 ( V_261 ) -> V_438 == V_438 ) {
F_333 ( V_261 , V_36 , 0 ) ;
} else {
T_2 V_450 = F_236 ( V_261 ) -> V_438 ;
T_2 V_329 ;
V_329 = V_438 - F_236 ( V_261 ) -> V_438 ;
F_236 ( V_261 ) -> V_438 = V_438 ;
V_446 = F_333 ( V_261 , V_329 , 0 ) ;
F_236 ( V_261 ) -> V_438 = V_438 - V_36 ;
V_329 = V_438 - V_450 ;
V_329 = F_333 ( V_261 , V_329 , 0 ) ;
F_236 ( V_261 ) -> V_438 = V_450 - V_36 ;
if ( V_329 > V_446 )
V_446 = V_329 - V_446 ;
else
V_446 = 0 ;
}
F_13 ( & F_236 ( V_261 ) -> V_52 ) ;
if ( V_447 )
V_446 += F_191 ( V_35 , V_447 ) ;
if ( V_446 ) {
F_313 ( V_35 , V_372 , V_446 ) ;
F_271 ( V_35 -> V_37 , L_11 ,
F_325 ( V_261 ) , V_446 , 0 ) ;
}
if ( V_445 )
F_45 ( & F_236 ( V_261 ) -> V_448 ) ;
return V_29 ;
}
void F_338 ( struct V_261 * V_261 , T_2 V_36 )
{
struct V_34 * V_35 = F_236 ( V_261 ) -> V_35 ;
T_2 V_446 = 0 ;
unsigned V_447 ;
V_36 = F_264 ( V_36 , V_35 -> V_333 ) ;
F_11 ( & F_236 ( V_261 ) -> V_52 ) ;
V_447 = F_331 ( V_261 ) ;
if ( V_36 )
V_446 = F_333 ( V_261 , V_36 , 0 ) ;
F_13 ( & F_236 ( V_261 ) -> V_52 ) ;
if ( V_447 > 0 )
V_446 += F_191 ( V_35 , V_447 ) ;
F_271 ( V_35 -> V_37 , L_11 ,
F_325 ( V_261 ) , V_446 , 0 ) ;
if ( V_35 -> V_37 -> V_426 ) {
F_329 ( V_35 , V_36 +
V_447 * V_35 -> V_88 ) ;
}
F_313 ( V_35 , & V_35 -> V_37 -> V_378 ,
V_446 ) ;
}
int F_339 ( struct V_261 * V_261 , T_2 V_36 )
{
int V_29 ;
V_29 = F_241 ( V_261 , V_36 ) ;
if ( V_29 )
return V_29 ;
V_29 = F_334 ( V_261 , V_36 ) ;
if ( V_29 ) {
F_243 ( V_261 , V_36 ) ;
return V_29 ;
}
return 0 ;
}
void F_340 ( struct V_261 * V_261 , T_2 V_36 )
{
F_338 ( V_261 , V_36 ) ;
F_243 ( V_261 , V_36 ) ;
}
static int F_341 ( struct V_34 * V_35 ,
T_2 V_27 , T_2 V_36 , int V_336 )
{
struct V_1 * V_2 = NULL ;
struct V_12 * V_13 = V_35 -> V_37 ;
T_2 V_451 = V_36 ;
T_2 V_452 ;
T_2 V_453 ;
int V_283 ;
F_11 ( & V_13 -> V_454 ) ;
V_452 = F_342 ( V_13 -> V_348 ) ;
if ( V_336 )
V_452 += V_36 ;
else
V_452 -= V_36 ;
F_343 ( V_13 -> V_348 , V_452 ) ;
F_13 ( & V_13 -> V_454 ) ;
while ( V_451 ) {
V_2 = F_66 ( V_13 , V_27 ) ;
if ( ! V_2 )
return - V_152 ;
if ( V_2 -> V_7 & ( V_284 |
V_285 |
V_286 ) )
V_283 = 2 ;
else
V_283 = 1 ;
if ( ! V_336 && V_2 -> V_3 == V_95 )
F_50 ( V_2 , 1 ) ;
V_453 = V_27 - V_2 -> V_21 . V_22 ;
F_8 ( V_453 > V_2 -> V_21 . V_33 ) ;
F_11 ( & V_2 -> V_104 -> V_52 ) ;
F_11 ( & V_2 -> V_52 ) ;
if ( F_240 ( V_35 , V_275 ) &&
V_2 -> V_267 < V_277 )
V_2 -> V_267 = V_277 ;
V_2 -> V_278 = 1 ;
V_452 = F_344 ( & V_2 -> V_134 ) ;
V_36 = F_293 ( V_451 , V_2 -> V_21 . V_33 - V_453 ) ;
if ( V_336 ) {
V_452 += V_36 ;
F_345 ( & V_2 -> V_134 , V_452 ) ;
V_2 -> V_10 -= V_36 ;
V_2 -> V_104 -> V_294 -= V_36 ;
V_2 -> V_104 -> V_282 += V_36 ;
V_2 -> V_104 -> V_288 += V_36 * V_283 ;
F_13 ( & V_2 -> V_52 ) ;
F_13 ( & V_2 -> V_104 -> V_52 ) ;
} else {
V_452 -= V_36 ;
F_345 ( & V_2 -> V_134 , V_452 ) ;
V_2 -> V_9 += V_36 ;
V_2 -> V_104 -> V_293 += V_36 ;
V_2 -> V_104 -> V_282 -= V_36 ;
V_2 -> V_104 -> V_288 -= V_36 * V_283 ;
F_13 ( & V_2 -> V_52 ) ;
F_13 ( & V_2 -> V_104 -> V_52 ) ;
F_346 ( V_13 -> V_59 ,
V_27 , V_27 + V_36 - 1 ,
V_40 | V_455 ) ;
}
F_6 ( V_2 ) ;
V_451 -= V_36 ;
V_27 += V_36 ;
}
return 0 ;
}
static T_2 V_26 ( struct V_34 * V_35 , T_2 V_456 )
{
struct V_1 * V_2 ;
T_2 V_27 ;
F_11 ( & V_35 -> V_37 -> V_18 ) ;
V_27 = V_35 -> V_37 -> V_26 ;
F_13 ( & V_35 -> V_37 -> V_18 ) ;
if ( V_27 < ( T_2 ) - 1 )
return V_27 ;
V_2 = F_65 ( V_35 -> V_37 , V_456 ) ;
if ( ! V_2 )
return 0 ;
V_27 = V_2 -> V_21 . V_22 ;
F_6 ( V_2 ) ;
return V_27 ;
}
static int F_347 ( struct V_34 * V_35 ,
struct V_1 * V_2 ,
T_2 V_27 , T_2 V_36 , int V_10 )
{
F_11 ( & V_2 -> V_104 -> V_52 ) ;
F_11 ( & V_2 -> V_52 ) ;
V_2 -> V_9 += V_36 ;
V_2 -> V_104 -> V_293 += V_36 ;
if ( V_10 ) {
V_2 -> V_10 -= V_36 ;
V_2 -> V_104 -> V_294 -= V_36 ;
}
F_13 ( & V_2 -> V_52 ) ;
F_13 ( & V_2 -> V_104 -> V_52 ) ;
F_346 ( V_35 -> V_37 -> V_59 , V_27 ,
V_27 + V_36 - 1 , V_40 | V_455 ) ;
if ( V_10 )
F_348 ( V_35 , V_27 , V_36 ) ;
return 0 ;
}
int F_159 ( struct V_34 * V_35 ,
T_2 V_27 , T_2 V_36 , int V_10 )
{
struct V_1 * V_2 ;
V_2 = F_66 ( V_35 -> V_37 , V_27 ) ;
F_30 ( ! V_2 ) ;
F_347 ( V_35 , V_2 , V_27 , V_36 , V_10 ) ;
F_6 ( V_2 ) ;
return 0 ;
}
int F_349 ( struct V_34 * V_35 ,
T_2 V_27 , T_2 V_36 )
{
struct V_1 * V_2 ;
int V_29 ;
V_2 = F_66 ( V_35 -> V_37 , V_27 ) ;
if ( ! V_2 )
return - V_457 ;
F_50 ( V_2 , 1 ) ;
F_347 ( V_35 , V_2 , V_27 , V_36 , 0 ) ;
V_29 = F_350 ( V_2 , V_27 , V_36 ) ;
F_6 ( V_2 ) ;
return V_29 ;
}
static int F_351 ( struct V_34 * V_35 , T_2 V_32 , T_2 V_36 )
{
int V_29 ;
struct V_1 * V_14 ;
struct V_50 * V_54 ;
V_14 = F_66 ( V_35 -> V_37 , V_32 ) ;
if ( ! V_14 )
return - V_457 ;
F_50 ( V_14 , 0 ) ;
V_54 = F_25 ( V_14 ) ;
if ( ! V_54 ) {
F_30 ( ! F_1 ( V_14 ) ) ;
V_29 = F_350 ( V_14 , V_32 , V_36 ) ;
} else {
F_35 ( & V_54 -> V_79 ) ;
if ( V_32 >= V_54 -> V_85 ) {
V_29 = F_17 ( V_35 , V_32 , V_36 ) ;
} else if ( V_32 + V_36 <= V_54 -> V_85 ) {
V_29 = F_350 ( V_14 ,
V_32 , V_36 ) ;
} else {
V_36 = V_54 -> V_85 - V_32 ;
V_29 = F_350 ( V_14 ,
V_32 , V_36 ) ;
if ( V_29 )
goto V_458;
V_36 = ( V_32 + V_36 ) -
V_54 -> V_85 ;
V_32 = V_54 -> V_85 ;
V_29 = F_17 ( V_35 , V_32 , V_36 ) ;
}
V_458:
F_45 ( & V_54 -> V_79 ) ;
F_26 ( V_54 ) ;
}
F_6 ( V_14 ) ;
return V_29 ;
}
int F_352 ( struct V_34 * log ,
struct V_66 * V_459 )
{
struct V_255 * V_134 ;
struct V_68 V_21 ;
int V_460 ;
int V_43 ;
if ( ! F_74 ( log -> V_37 , V_461 ) )
return 0 ;
for ( V_43 = 0 ; V_43 < F_38 ( V_459 ) ; V_43 ++ ) {
F_40 ( V_459 , & V_21 , V_43 ) ;
if ( V_21 . type != V_259 )
continue;
V_134 = F_76 ( V_459 , V_43 , struct V_255 ) ;
V_460 = F_218 ( V_459 , V_134 ) ;
if ( V_460 == V_260 )
continue;
if ( F_219 ( V_459 , V_134 ) == 0 )
continue;
V_21 . V_22 = F_219 ( V_459 , V_134 ) ;
V_21 . V_33 = F_220 ( V_459 , V_134 ) ;
F_351 ( log , V_21 . V_22 , V_21 . V_33 ) ;
}
return 0 ;
}
static int F_353 ( struct V_1 * V_2 ,
T_2 V_36 , int V_433 )
{
struct V_101 * V_104 = V_2 -> V_104 ;
int V_29 = 0 ;
F_11 ( & V_104 -> V_52 ) ;
F_11 ( & V_2 -> V_52 ) ;
if ( V_433 != V_462 ) {
if ( V_2 -> V_269 ) {
V_29 = - V_176 ;
} else {
V_2 -> V_10 += V_36 ;
V_104 -> V_294 += V_36 ;
if ( V_433 == V_463 ) {
F_271 ( V_2 -> V_37 ,
L_7 , V_104 -> V_7 ,
V_36 , 0 ) ;
V_104 -> V_296 -= V_36 ;
}
}
} else {
if ( V_2 -> V_269 )
V_104 -> V_295 += V_36 ;
V_2 -> V_10 -= V_36 ;
V_104 -> V_294 -= V_36 ;
}
F_13 ( & V_2 -> V_52 ) ;
F_13 ( & V_104 -> V_52 ) ;
return V_29 ;
}
void F_354 ( struct V_108 * V_109 ,
struct V_34 * V_35 )
{
struct V_12 * V_37 = V_35 -> V_37 ;
struct V_50 * V_81 ;
struct V_50 * V_54 ;
struct V_1 * V_2 ;
struct V_101 * V_104 ;
F_61 ( & V_37 -> V_80 ) ;
F_355 (caching_ctl, next,
&fs_info->caching_block_groups, list) {
V_2 = V_54 -> V_14 ;
if ( F_1 ( V_2 ) ) {
V_2 -> V_98 = ( T_2 ) - 1 ;
F_171 ( & V_54 -> V_91 ) ;
F_26 ( V_54 ) ;
} else {
V_2 -> V_98 = V_54 -> V_85 ;
}
}
if ( V_37 -> V_59 == & V_37 -> V_38 [ 0 ] )
V_37 -> V_59 = & V_37 -> V_38 [ 1 ] ;
else
V_37 -> V_59 = & V_37 -> V_38 [ 0 ] ;
F_63 ( & V_37 -> V_80 ) ;
F_69 (space_info, &fs_info->space_info, list)
F_356 ( & V_104 -> V_289 , 0 ) ;
F_320 ( V_37 ) ;
}
static int F_357 ( struct V_34 * V_35 , T_2 V_32 , T_2 V_31 )
{
struct V_12 * V_37 = V_35 -> V_37 ;
struct V_1 * V_2 = NULL ;
struct V_101 * V_104 ;
struct V_232 * V_233 = & V_37 -> V_235 ;
T_2 V_49 ;
bool V_280 ;
while ( V_32 <= V_31 ) {
V_280 = false ;
if ( ! V_2 ||
V_32 >= V_2 -> V_21 . V_22 + V_2 -> V_21 . V_33 ) {
if ( V_2 )
F_6 ( V_2 ) ;
V_2 = F_66 ( V_37 , V_32 ) ;
F_30 ( ! V_2 ) ;
}
V_49 = V_2 -> V_21 . V_22 + V_2 -> V_21 . V_33 - V_32 ;
V_49 = F_293 ( V_49 , V_31 + 1 - V_32 ) ;
if ( V_32 < V_2 -> V_98 ) {
V_49 = F_293 ( V_49 , V_2 -> V_98 - V_32 ) ;
F_29 ( V_2 , V_32 , V_49 ) ;
}
V_32 += V_49 ;
V_104 = V_2 -> V_104 ;
F_11 ( & V_104 -> V_52 ) ;
F_11 ( & V_2 -> V_52 ) ;
V_2 -> V_9 -= V_49 ;
V_104 -> V_293 -= V_49 ;
if ( V_2 -> V_269 ) {
V_104 -> V_295 += V_49 ;
V_280 = true ;
}
F_13 ( & V_2 -> V_52 ) ;
if ( ! V_280 && V_233 -> V_104 == V_104 ) {
F_11 ( & V_233 -> V_52 ) ;
if ( ! V_233 -> V_107 ) {
V_49 = F_293 ( V_49 , V_233 -> V_57 -
V_233 -> V_10 ) ;
V_233 -> V_10 += V_49 ;
V_104 -> V_296 += V_49 ;
if ( V_233 -> V_10 >= V_233 -> V_57 )
V_233 -> V_107 = 1 ;
}
F_13 ( & V_233 -> V_52 ) ;
}
F_13 ( & V_104 -> V_52 ) ;
}
if ( V_2 )
F_6 ( V_2 ) ;
return 0 ;
}
int F_358 ( struct V_108 * V_109 ,
struct V_34 * V_35 )
{
struct V_12 * V_37 = V_35 -> V_37 ;
struct V_464 * V_465 ;
T_2 V_32 ;
T_2 V_31 ;
int V_29 ;
if ( V_109 -> V_211 )
return 0 ;
if ( V_37 -> V_59 == & V_37 -> V_38 [ 0 ] )
V_465 = & V_37 -> V_38 [ 1 ] ;
else
V_465 = & V_37 -> V_38 [ 0 ] ;
while ( 1 ) {
V_29 = F_28 ( V_465 , 0 , & V_32 , & V_31 ,
V_60 , NULL ) ;
if ( V_29 )
break;
if ( F_240 ( V_35 , V_466 ) )
V_29 = F_140 ( V_35 , V_32 ,
V_31 + 1 - V_32 , NULL ) ;
F_359 ( V_465 , V_32 , V_31 , V_40 ) ;
F_357 ( V_35 , V_32 , V_31 ) ;
F_46 () ;
}
return 0 ;
}
static void F_360 ( struct V_12 * V_37 , T_2 V_36 ,
T_2 V_132 , T_2 V_145 )
{
struct V_101 * V_104 ;
T_2 V_7 ;
if ( V_132 < V_142 ) {
if ( V_145 == V_467 )
V_7 = V_309 ;
else
V_7 = V_307 ;
} else {
V_7 = V_301 ;
}
V_104 = F_67 ( V_37 , V_7 ) ;
F_30 ( ! V_104 ) ;
F_361 ( & V_104 -> V_289 , V_36 ) ;
}
static int F_151 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
T_2 V_27 , T_2 V_36 , T_2 V_17 ,
T_2 V_145 , T_2 V_468 ,
T_2 V_469 , int V_158 ,
struct V_178 * V_128 )
{
struct V_68 V_21 ;
struct V_64 * V_65 ;
struct V_12 * V_13 = V_35 -> V_37 ;
struct V_34 * V_63 = V_13 -> V_63 ;
struct V_66 * V_67 ;
struct V_115 * V_116 ;
struct V_161 * V_162 ;
int V_29 ;
int V_182 ;
int V_470 = 0 ;
int V_471 = 0 ;
int V_472 = 1 ;
T_3 V_117 ;
T_2 V_111 ;
bool V_171 = F_74 ( V_35 -> V_37 ,
V_120 ) ;
V_65 = F_33 () ;
if ( ! V_65 )
return - V_72 ;
V_65 -> V_76 = 1 ;
V_65 -> V_202 = 1 ;
V_182 = V_468 >= V_142 ;
F_30 ( ! V_182 && V_158 != 1 ) ;
if ( V_182 )
V_171 = 0 ;
V_29 = F_132 ( V_109 , V_63 , V_65 , & V_162 ,
V_27 , V_36 , V_17 ,
V_145 , V_468 ,
V_469 ) ;
if ( V_29 == 0 ) {
V_470 = V_65 -> V_84 [ 0 ] ;
while ( V_470 >= 0 ) {
F_40 ( V_65 -> V_83 [ 0 ] , & V_21 ,
V_470 ) ;
if ( V_21 . V_22 != V_27 )
break;
if ( V_21 . type == V_77 &&
V_21 . V_33 == V_36 ) {
V_471 = 1 ;
break;
}
if ( V_21 . type == V_86 &&
V_21 . V_33 == V_468 ) {
V_471 = 1 ;
break;
}
if ( V_65 -> V_84 [ 0 ] - V_470 > 5 )
break;
V_470 -- ;
}
#ifdef F_79
V_117 = F_75 ( V_65 -> V_83 [ 0 ] , V_470 ) ;
if ( V_471 && V_117 < sizeof( * V_116 ) )
V_471 = 0 ;
#endif
if ( ! V_471 ) {
F_30 ( V_162 ) ;
V_29 = F_137 ( V_109 , V_63 , V_65 ,
NULL , V_158 ,
V_182 ) ;
if ( V_29 ) {
F_146 ( V_109 , V_63 , V_29 ) ;
goto V_73;
}
F_43 ( V_65 ) ;
V_65 -> V_202 = 1 ;
V_21 . V_22 = V_27 ;
V_21 . type = V_77 ;
V_21 . V_33 = V_36 ;
if ( ! V_182 && V_171 ) {
V_21 . type = V_86 ;
V_21 . V_33 = V_468 ;
}
V_29 = F_37 ( V_109 , V_63 ,
& V_21 , V_65 , - 1 , 1 ) ;
if ( V_29 > 0 && V_171 && V_65 -> V_84 [ 0 ] ) {
V_65 -> V_84 [ 0 ] -- ;
F_40 ( V_65 -> V_83 [ 0 ] , & V_21 ,
V_65 -> V_84 [ 0 ] ) ;
if ( V_21 . V_22 == V_27 &&
V_21 . type == V_77 &&
V_21 . V_33 == V_36 )
V_29 = 0 ;
}
if ( V_29 > 0 && V_171 ) {
V_171 = false ;
V_21 . type = V_77 ;
V_21 . V_33 = V_36 ;
F_43 ( V_65 ) ;
V_29 = F_37 ( V_109 , V_63 ,
& V_21 , V_65 , - 1 , 1 ) ;
}
if ( V_29 ) {
F_180 ( V_13 , L_12 ,
V_29 , V_27 ) ;
if ( V_29 > 0 )
F_362 ( V_63 ,
V_65 -> V_83 [ 0 ] ) ;
}
if ( V_29 < 0 ) {
F_146 ( V_109 , V_63 , V_29 ) ;
goto V_73;
}
V_470 = V_65 -> V_84 [ 0 ] ;
}
} else if ( F_8 ( V_29 == - V_152 ) ) {
F_362 ( V_63 , V_65 -> V_83 [ 0 ] ) ;
F_180 ( V_13 ,
L_13 ,
V_27 , V_17 , V_145 , V_468 ,
V_469 ) ;
} else {
F_146 ( V_109 , V_63 , V_29 ) ;
goto V_73;
}
V_67 = V_65 -> V_83 [ 0 ] ;
V_117 = F_75 ( V_67 , V_470 ) ;
#ifdef F_79
if ( V_117 < sizeof( * V_116 ) ) {
F_30 ( V_471 || V_470 != V_65 -> V_84 [ 0 ] ) ;
V_29 = F_85 ( V_109 , V_63 , V_65 ,
V_468 , 0 ) ;
if ( V_29 < 0 ) {
F_146 ( V_109 , V_63 , V_29 ) ;
goto V_73;
}
F_43 ( V_65 ) ;
V_65 -> V_202 = 1 ;
V_21 . V_22 = V_27 ;
V_21 . type = V_77 ;
V_21 . V_33 = V_36 ;
V_29 = F_37 ( V_109 , V_63 , & V_21 , V_65 ,
- 1 , 1 ) ;
if ( V_29 ) {
F_180 ( V_13 , L_12 ,
V_29 , V_27 ) ;
F_362 ( V_63 , V_65 -> V_83 [ 0 ] ) ;
}
if ( V_29 < 0 ) {
F_146 ( V_109 , V_63 , V_29 ) ;
goto V_73;
}
V_470 = V_65 -> V_84 [ 0 ] ;
V_67 = V_65 -> V_83 [ 0 ] ;
V_117 = F_75 ( V_67 , V_470 ) ;
}
#endif
F_30 ( V_117 < sizeof( * V_116 ) ) ;
V_116 = F_76 ( V_67 , V_470 ,
struct V_115 ) ;
if ( V_468 < V_142 &&
V_21 . type == V_77 ) {
struct V_137 * V_138 ;
F_30 ( V_117 < sizeof( * V_116 ) + sizeof( * V_138 ) ) ;
V_138 = (struct V_137 * ) ( V_116 + 1 ) ;
F_8 ( V_468 != F_363 ( V_67 , V_138 ) ) ;
}
V_111 = F_77 ( V_67 , V_116 ) ;
if ( V_111 < V_158 ) {
F_180 ( V_13 , L_14
L_15 , V_158 , V_111 , V_27 ) ;
V_29 = - V_457 ;
F_146 ( V_109 , V_63 , V_29 ) ;
goto V_73;
}
V_111 -= V_158 ;
if ( V_111 > 0 ) {
if ( V_128 )
F_128 ( V_128 , V_67 , V_116 ) ;
if ( V_162 ) {
F_30 ( ! V_471 ) ;
} else {
F_88 ( V_67 , V_116 , V_111 ) ;
F_93 ( V_67 ) ;
}
if ( V_471 ) {
V_29 = F_137 ( V_109 , V_63 , V_65 ,
V_162 , V_158 ,
V_182 ) ;
if ( V_29 ) {
F_146 ( V_109 , V_63 , V_29 ) ;
goto V_73;
}
}
F_360 ( V_35 -> V_37 , - V_36 , V_468 ,
V_145 ) ;
} else {
if ( V_471 ) {
F_30 ( V_182 && V_158 !=
F_116 ( V_35 , V_65 , V_162 ) ) ;
if ( V_162 ) {
F_30 ( V_65 -> V_84 [ 0 ] != V_470 ) ;
} else {
F_30 ( V_65 -> V_84 [ 0 ] != V_470 + 1 ) ;
V_65 -> V_84 [ 0 ] = V_470 ;
V_472 = 2 ;
}
}
V_29 = F_364 ( V_109 , V_63 , V_65 , V_65 -> V_84 [ 0 ] ,
V_472 ) ;
if ( V_29 ) {
F_146 ( V_109 , V_63 , V_29 ) ;
goto V_73;
}
F_43 ( V_65 ) ;
if ( V_182 ) {
V_29 = F_163 ( V_109 , V_35 , V_27 , V_36 ) ;
if ( V_29 ) {
F_146 ( V_109 , V_63 , V_29 ) ;
goto V_73;
}
}
V_29 = F_341 ( V_35 , V_27 , V_36 , 0 ) ;
if ( V_29 ) {
F_146 ( V_109 , V_63 , V_29 ) ;
goto V_73;
}
}
V_73:
F_49 ( V_65 ) ;
return V_29 ;
}
static T_1 int F_365 ( struct V_108 * V_109 ,
struct V_34 * V_35 , T_2 V_27 )
{
struct V_112 * V_103 ;
struct V_113 * V_114 ;
struct V_203 * V_150 ;
struct V_15 * V_127 ;
int V_29 = 0 ;
V_114 = & V_109 -> V_126 -> V_114 ;
F_11 ( & V_114 -> V_52 ) ;
V_103 = F_82 ( V_109 , V_27 ) ;
if ( ! V_103 )
goto V_73;
V_127 = F_208 ( & V_103 -> V_127 . V_15 ) ;
if ( ! V_127 )
goto V_73;
V_150 = F_12 ( V_127 , struct V_203 , V_15 ) ;
if ( V_150 -> V_27 == V_27 )
goto V_73;
if ( V_103 -> V_128 ) {
if ( ! V_103 -> V_215 )
goto V_73;
F_173 ( V_103 -> V_128 ) ;
V_103 -> V_128 = NULL ;
}
if ( ! F_83 ( & V_103 -> V_79 ) )
goto V_73;
V_103 -> V_127 . V_218 = 0 ;
F_175 ( & V_103 -> V_127 . V_15 , & V_114 -> V_35 ) ;
V_114 -> V_219 -- ;
V_114 -> V_234 -- ;
if ( F_165 ( & V_103 -> V_213 ) )
V_114 -> V_217 -- ;
F_171 ( & V_103 -> V_213 ) ;
F_13 ( & V_114 -> V_52 ) ;
F_30 ( V_103 -> V_128 ) ;
if ( V_103 -> V_215 )
V_29 = 1 ;
F_45 ( & V_103 -> V_79 ) ;
F_84 ( & V_103 -> V_127 ) ;
return V_29 ;
V_73:
F_13 ( & V_114 -> V_52 ) ;
return 0 ;
}
void F_366 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
struct V_66 * V_252 ,
T_2 V_17 , int V_473 )
{
struct V_1 * V_2 = NULL ;
int V_474 = 1 ;
int V_29 ;
if ( V_35 -> V_248 . V_22 != V_200 ) {
V_29 = F_143 ( V_35 -> V_37 , V_109 ,
V_252 -> V_32 , V_252 -> V_49 ,
V_17 , V_35 -> V_248 . V_22 ,
F_216 ( V_252 ) ,
V_209 , NULL , 0 ) ;
F_30 ( V_29 ) ;
}
if ( ! V_473 )
return;
V_2 = F_66 ( V_35 -> V_37 , V_252 -> V_32 ) ;
if ( F_367 ( V_252 ) == V_109 -> V_271 ) {
if ( V_35 -> V_248 . V_22 != V_200 ) {
V_29 = F_365 ( V_109 , V_35 , V_252 -> V_32 ) ;
if ( ! V_29 )
goto V_73;
}
if ( F_368 ( V_252 , V_475 ) ) {
F_347 ( V_35 , V_2 , V_252 -> V_32 , V_252 -> V_49 , 1 ) ;
goto V_73;
}
F_8 ( F_336 ( V_476 , & V_252 -> V_477 ) ) ;
F_29 ( V_2 , V_252 -> V_32 , V_252 -> V_49 ) ;
F_353 ( V_2 , V_252 -> V_49 , V_462 ) ;
F_348 ( V_35 , V_252 -> V_32 , V_252 -> V_49 ) ;
V_474 = 0 ;
}
V_73:
if ( V_474 )
F_360 ( V_35 -> V_37 , V_252 -> V_49 ,
F_216 ( V_252 ) ,
V_35 -> V_248 . V_22 ) ;
F_369 ( V_478 , & V_252 -> V_477 ) ;
F_6 ( V_2 ) ;
}
int V_258 ( struct V_108 * V_109 , struct V_34 * V_35 ,
T_2 V_27 , T_2 V_36 , T_2 V_17 , T_2 V_145 ,
T_2 V_132 , T_2 V_33 , int V_199 )
{
int V_29 ;
struct V_12 * V_37 = V_35 -> V_37 ;
F_360 ( V_35 -> V_37 , V_36 , V_132 , V_145 ) ;
if ( V_145 == V_200 ) {
F_8 ( V_132 >= V_142 ) ;
F_159 ( V_35 , V_27 , V_36 , 1 ) ;
V_29 = 0 ;
} else if ( V_132 < V_142 ) {
V_29 = F_143 ( V_37 , V_109 , V_27 ,
V_36 ,
V_17 , V_145 , ( int ) V_132 ,
V_209 , NULL , V_199 ) ;
} else {
V_29 = F_144 ( V_37 , V_109 , V_27 ,
V_36 ,
V_17 , V_145 , V_132 ,
V_33 , V_209 ,
NULL , V_199 ) ;
}
return V_29 ;
}
static T_2 F_370 ( struct V_34 * V_35 ,
struct V_1 * V_2 ,
T_2 V_229 , T_2 V_36 )
{
T_2 V_29 = F_264 ( V_229 , V_35 -> V_479 ) ;
return V_29 ;
}
static T_1 void
F_371 ( struct V_1 * V_2 ,
T_2 V_36 )
{
struct V_50 * V_54 ;
V_54 = F_25 ( V_2 ) ;
if ( ! V_54 )
return;
F_294 ( V_54 -> V_89 , F_1 ( V_2 ) ||
( V_2 -> V_11 -> V_480 >= V_36 ) ) ;
F_26 ( V_54 ) ;
}
static T_1 int
F_372 ( struct V_1 * V_2 )
{
struct V_50 * V_54 ;
int V_29 = 0 ;
V_54 = F_25 ( V_2 ) ;
if ( ! V_54 )
return ( V_2 -> V_3 == V_5 ) ? - V_173 : 0 ;
F_294 ( V_54 -> V_89 , F_1 ( V_2 ) ) ;
if ( V_2 -> V_3 == V_5 )
V_29 = - V_173 ;
F_26 ( V_54 ) ;
return V_29 ;
}
int F_373 ( T_2 V_7 )
{
if ( V_7 & V_286 )
return V_481 ;
else if ( V_7 & V_285 )
return V_482 ;
else if ( V_7 & V_284 )
return V_483 ;
else if ( V_7 & V_325 )
return V_484 ;
else if ( V_7 & V_326 )
return V_485 ;
else if ( V_7 & V_327 )
return V_486 ;
return V_487 ;
}
static int F_374 ( struct V_1 * V_2 )
{
return F_373 ( V_2 -> V_7 ) ;
}
static T_1 int F_375 ( struct V_34 * V_488 ,
T_2 V_36 , T_2 V_489 ,
T_2 V_490 , struct V_68 * V_206 ,
T_2 V_7 )
{
int V_29 = 0 ;
struct V_34 * V_35 = V_488 -> V_37 -> V_63 ;
struct V_491 * V_492 = NULL ;
struct V_1 * V_14 = NULL ;
struct V_1 * V_493 ;
T_2 V_456 = 0 ;
T_2 V_494 = 0 ;
int V_495 = 2 * 1024 * 1024 ;
struct V_101 * V_104 ;
int V_496 = 0 ;
int V_497 = F_373 ( V_7 ) ;
int V_498 = ( V_7 & V_301 ) ?
V_499 : V_463 ;
bool V_500 = false ;
bool V_501 = false ;
bool V_502 = false ;
bool V_503 = true ;
bool V_504 = false ;
F_8 ( V_36 < V_35 -> V_333 ) ;
F_376 ( V_206 , V_77 ) ;
V_206 -> V_22 = 0 ;
V_206 -> V_33 = 0 ;
F_377 ( V_488 , V_36 , V_489 , V_7 ) ;
V_104 = F_67 ( V_35 -> V_37 , V_7 ) ;
if ( ! V_104 ) {
F_180 ( V_35 -> V_37 , L_16 , V_7 ) ;
return - V_339 ;
}
if ( F_283 ( V_104 ) )
V_503 = false ;
if ( V_7 & V_307 && V_503 ) {
V_492 = & V_35 -> V_37 -> V_505 ;
if ( ! F_240 ( V_35 , V_506 ) )
V_495 = 64 * 1024 ;
}
if ( ( V_7 & V_301 ) && V_503 &&
F_240 ( V_35 , V_506 ) ) {
V_492 = & V_35 -> V_37 -> V_507 ;
}
if ( V_492 ) {
F_11 ( & V_492 -> V_52 ) ;
if ( V_492 -> V_14 )
V_490 = V_492 -> V_508 ;
F_13 ( & V_492 -> V_52 ) ;
}
V_456 = F_378 ( V_456 , V_26 ( V_35 , 0 ) ) ;
V_456 = F_378 ( V_456 , V_490 ) ;
if ( ! V_492 )
V_495 = 0 ;
if ( V_456 == V_490 ) {
V_14 = F_66 ( V_35 -> V_37 ,
V_456 ) ;
V_493 = V_14 ;
if ( V_14 && F_3 ( V_14 , V_7 ) &&
V_14 -> V_3 != V_95 ) {
F_36 ( & V_104 -> V_292 ) ;
if ( F_165 ( & V_14 -> V_91 ) ||
V_14 -> V_269 ) {
F_6 ( V_14 ) ;
F_44 ( & V_104 -> V_292 ) ;
} else {
V_497 = F_374 ( V_14 ) ;
goto V_509;
}
} else if ( V_14 ) {
F_6 ( V_14 ) ;
}
}
V_510:
V_504 = false ;
F_36 ( & V_104 -> V_292 ) ;
F_379 (block_group, &space_info->block_groups[index],
list) {
T_2 V_33 ;
int V_3 ;
V_493 = V_14 ;
F_4 ( V_14 ) ;
V_456 = V_14 -> V_21 . V_22 ;
if ( ! F_3 ( V_14 , V_7 ) ) {
T_2 V_511 = V_284 |
V_285 |
V_326 |
V_327 |
V_286 ;
if ( ( V_7 & V_511 ) && ! ( V_14 -> V_7 & V_511 ) )
goto V_496;
}
V_509:
V_3 = F_1 ( V_14 ) ;
if ( F_301 ( ! V_3 ) ) {
V_500 = true ;
V_29 = F_50 ( V_14 , 0 ) ;
F_30 ( V_29 < 0 ) ;
V_29 = 0 ;
}
if ( F_301 ( V_14 -> V_3 == V_5 ) )
goto V_496;
if ( F_301 ( V_14 -> V_269 ) )
goto V_496;
if ( V_492 ) {
unsigned long V_512 ;
F_11 ( & V_492 -> V_513 ) ;
V_493 = V_492 -> V_14 ;
if ( V_493 != V_14 &&
( ! V_493 ||
V_493 -> V_269 ||
! F_3 ( V_493 , V_7 ) ) ) {
V_493 = V_14 ;
goto V_514;
}
if ( V_493 != V_14 )
F_4 ( V_493 ) ;
V_33 = F_380 ( V_493 ,
V_492 ,
V_36 ,
V_493 -> V_21 . V_22 ,
& V_494 ) ;
if ( V_33 ) {
F_13 ( & V_492 -> V_513 ) ;
F_381 ( V_35 ,
V_14 , V_456 , V_36 ) ;
goto V_515;
}
F_8 ( V_492 -> V_14 != V_493 ) ;
if ( V_493 != V_14 ) {
F_6 ( V_493 ) ;
V_493 = V_14 ;
}
V_514:
F_30 ( V_493 != V_14 ) ;
if ( V_496 >= V_516 &&
V_492 -> V_14 != V_14 ) {
F_13 ( & V_492 -> V_513 ) ;
goto V_517;
}
F_382 ( NULL , V_492 ) ;
if ( V_496 >= V_516 ) {
F_13 ( & V_492 -> V_513 ) ;
goto V_517;
}
V_512 = F_34 (unsigned long,
empty_cluster + empty_size,
block_group->full_stripe_len) ;
V_29 = F_383 ( V_35 , V_14 ,
V_492 , V_456 ,
V_36 ,
V_512 ) ;
if ( V_29 == 0 ) {
V_33 = F_380 ( V_14 ,
V_492 ,
V_36 ,
V_456 ,
& V_494 ) ;
if ( V_33 ) {
F_13 ( & V_492 -> V_513 ) ;
F_381 ( V_35 ,
V_14 , V_456 ,
V_36 ) ;
goto V_515;
}
} else if ( ! V_3 && V_496 > V_518
&& ! V_501 ) {
F_13 ( & V_492 -> V_513 ) ;
V_501 = true ;
F_371 ( V_14 ,
V_36 + V_495 + V_489 ) ;
goto V_509;
}
F_382 ( NULL , V_492 ) ;
F_13 ( & V_492 -> V_513 ) ;
goto V_496;
}
V_517:
F_11 ( & V_14 -> V_11 -> V_519 ) ;
if ( V_3 &&
V_14 -> V_11 -> V_480 <
V_36 + V_495 + V_489 ) {
if ( V_14 -> V_11 -> V_480 >
V_494 )
V_494 =
V_14 -> V_11 -> V_480 ;
F_13 ( & V_14 -> V_11 -> V_519 ) ;
goto V_496;
}
F_13 ( & V_14 -> V_11 -> V_519 ) ;
V_33 = F_384 ( V_14 , V_456 ,
V_36 , V_489 ,
& V_494 ) ;
if ( ! V_33 && ! V_502 && ! V_3 &&
V_496 > V_518 ) {
F_371 ( V_14 ,
V_36 + V_489 ) ;
V_502 = true ;
goto V_509;
} else if ( ! V_33 ) {
if ( ! V_3 )
V_504 = true ;
goto V_496;
}
V_515:
V_456 = F_370 ( V_35 , V_493 ,
V_33 , V_36 ) ;
if ( V_456 + V_36 >
V_493 -> V_21 . V_22 + V_493 -> V_21 . V_33 ) {
F_29 ( V_493 , V_33 , V_36 ) ;
goto V_496;
}
if ( V_33 < V_456 )
F_29 ( V_493 , V_33 ,
V_456 - V_33 ) ;
F_30 ( V_33 > V_456 ) ;
V_29 = F_353 ( V_493 , V_36 ,
V_498 ) ;
if ( V_29 == - V_176 ) {
F_29 ( V_493 , V_33 , V_36 ) ;
goto V_496;
}
V_206 -> V_22 = V_456 ;
V_206 -> V_33 = V_36 ;
F_385 ( V_488 , V_14 ,
V_456 , V_36 ) ;
if ( V_493 != V_14 )
F_6 ( V_493 ) ;
F_6 ( V_14 ) ;
break;
V_496:
V_501 = false ;
V_502 = false ;
F_30 ( V_497 != F_374 ( V_14 ) ) ;
if ( V_493 != V_14 )
F_6 ( V_493 ) ;
F_6 ( V_14 ) ;
}
F_44 ( & V_104 -> V_292 ) ;
if ( ! V_206 -> V_22 && V_496 >= V_520 && V_504 )
goto V_510;
if ( ! V_206 -> V_22 && ++ V_497 < V_290 )
goto V_510;
if ( ! V_206 -> V_22 && V_496 < V_516 ) {
V_497 = 0 ;
V_496 ++ ;
if ( V_496 == V_521 ) {
struct V_108 * V_109 ;
V_109 = F_266 ( V_35 ) ;
if ( F_232 ( V_109 ) ) {
V_29 = F_233 ( V_109 ) ;
goto V_73;
}
V_29 = F_267 ( V_109 , V_35 , V_7 ,
V_338 ) ;
if ( V_29 < 0 && V_29 != - V_339 )
F_146 ( V_109 ,
V_35 , V_29 ) ;
else
V_29 = 0 ;
F_268 ( V_109 , V_35 ) ;
if ( V_29 )
goto V_73;
}
if ( V_496 == V_516 ) {
V_489 = 0 ;
V_495 = 0 ;
}
goto V_510;
} else if ( ! V_206 -> V_22 ) {
V_29 = - V_339 ;
} else if ( V_206 -> V_22 ) {
V_29 = 0 ;
}
V_73:
if ( V_29 == - V_339 )
V_206 -> V_33 = V_494 ;
return V_29 ;
}
static void F_281 ( struct V_101 * V_13 , T_2 V_329 ,
int V_522 )
{
struct V_1 * V_2 ;
int V_497 = 0 ;
F_11 ( & V_13 -> V_52 ) ;
F_386 ( V_523 L_17 ,
V_13 -> V_7 ,
V_13 -> V_281 - V_13 -> V_282 - V_13 -> V_293 -
V_13 -> V_294 - V_13 -> V_295 ,
( V_13 -> V_107 ) ? L_4 : L_18 ) ;
F_386 ( V_523 L_19
L_20 ,
V_13 -> V_281 , V_13 -> V_282 , V_13 -> V_293 ,
V_13 -> V_294 , V_13 -> V_296 ,
V_13 -> V_295 ) ;
F_13 ( & V_13 -> V_52 ) ;
if ( ! V_522 )
return;
F_36 ( & V_13 -> V_292 ) ;
V_78:
F_379 (cache, &info->block_groups[index], list) {
F_11 ( & V_2 -> V_52 ) ;
F_386 ( V_523 L_21 ,
V_2 -> V_21 . V_22 , V_2 -> V_21 . V_33 ,
F_344 ( & V_2 -> V_134 ) , V_2 -> V_9 ,
V_2 -> V_10 , V_2 -> V_269 ? L_22 : L_4 ) ;
F_387 ( V_2 , V_329 ) ;
F_13 ( & V_2 -> V_52 ) ;
}
if ( ++ V_497 < V_290 )
goto V_78;
F_44 ( & V_13 -> V_292 ) ;
}
int F_388 ( struct V_34 * V_35 ,
T_2 V_36 , T_2 V_524 ,
T_2 V_489 , T_2 V_490 ,
struct V_68 * V_206 , int V_182 )
{
bool V_525 = false ;
T_2 V_7 ;
int V_29 ;
V_7 = F_263 ( V_35 , V_182 ) ;
V_78:
F_8 ( V_36 < V_35 -> V_333 ) ;
V_29 = F_375 ( V_35 , V_36 , V_489 , V_490 , V_206 ,
V_7 ) ;
if ( V_29 == - V_339 ) {
if ( ! V_525 && V_206 -> V_33 ) {
V_36 = F_293 ( V_36 >> 1 , V_206 -> V_33 ) ;
V_36 = F_389 ( V_36 , V_35 -> V_333 ) ;
V_36 = F_378 ( V_36 , V_524 ) ;
if ( V_36 == V_524 )
V_525 = true ;
goto V_78;
} else if ( F_240 ( V_35 , V_351 ) ) {
struct V_101 * V_343 ;
V_343 = F_67 ( V_35 -> V_37 , V_7 ) ;
F_180 ( V_35 -> V_37 , L_23 ,
V_7 , V_36 ) ;
if ( V_343 )
F_281 ( V_343 , V_36 , 1 ) ;
}
}
return V_29 ;
}
static int F_390 ( struct V_34 * V_35 ,
T_2 V_32 , T_2 V_49 , int V_474 )
{
struct V_1 * V_2 ;
int V_29 = 0 ;
V_2 = F_66 ( V_35 -> V_37 , V_32 ) ;
if ( ! V_2 ) {
F_180 ( V_35 -> V_37 , L_24 ,
V_32 ) ;
return - V_339 ;
}
if ( F_240 ( V_35 , V_466 ) )
V_29 = F_140 ( V_35 , V_32 , V_49 , NULL ) ;
if ( V_474 )
F_347 ( V_35 , V_2 , V_32 , V_49 , 1 ) ;
else {
F_29 ( V_2 , V_32 , V_49 ) ;
F_353 ( V_2 , V_49 , V_462 ) ;
}
F_6 ( V_2 ) ;
F_348 ( V_35 , V_32 , V_49 ) ;
return V_29 ;
}
int F_391 ( struct V_34 * V_35 ,
T_2 V_32 , T_2 V_49 )
{
return F_390 ( V_35 , V_32 , V_49 , 0 ) ;
}
int F_392 ( struct V_34 * V_35 ,
T_2 V_32 , T_2 V_49 )
{
return F_390 ( V_35 , V_32 , V_49 , 1 ) ;
}
static int F_150 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
T_2 V_17 , T_2 V_145 ,
T_2 V_7 , T_2 V_132 , T_2 V_33 ,
struct V_68 * V_206 , int V_131 )
{
int V_29 ;
struct V_12 * V_37 = V_35 -> V_37 ;
struct V_115 * V_526 ;
struct V_161 * V_162 ;
struct V_64 * V_65 ;
struct V_66 * V_67 ;
int type ;
T_3 V_57 ;
if ( V_17 > 0 )
type = V_153 ;
else
type = V_154 ;
V_57 = sizeof( * V_526 ) + F_123 ( type ) ;
V_65 = F_33 () ;
if ( ! V_65 )
return - V_72 ;
V_65 -> V_202 = 1 ;
V_29 = F_104 ( V_109 , V_37 -> V_63 , V_65 ,
V_206 , V_57 ) ;
if ( V_29 ) {
F_49 ( V_65 ) ;
return V_29 ;
}
V_67 = V_65 -> V_83 [ 0 ] ;
V_526 = F_76 ( V_67 , V_65 -> V_84 [ 0 ] ,
struct V_115 ) ;
F_88 ( V_67 , V_526 , V_131 ) ;
F_89 ( V_67 , V_526 , V_109 -> V_271 ) ;
F_90 ( V_67 , V_526 ,
V_7 | V_144 ) ;
V_162 = (struct V_161 * ) ( V_526 + 1 ) ;
F_130 ( V_67 , V_162 , type ) ;
if ( V_17 > 0 ) {
struct V_157 * V_150 ;
V_150 = (struct V_157 * ) ( V_162 + 1 ) ;
F_131 ( V_67 , V_162 , V_17 ) ;
F_105 ( V_67 , V_150 , V_131 ) ;
} else {
struct V_149 * V_150 ;
V_150 = (struct V_149 * ) ( & V_162 -> V_33 ) ;
F_107 ( V_67 , V_150 , V_145 ) ;
F_108 ( V_67 , V_150 , V_132 ) ;
F_109 ( V_67 , V_150 , V_33 ) ;
F_110 ( V_67 , V_150 , V_131 ) ;
}
F_93 ( V_65 -> V_83 [ 0 ] ) ;
F_49 ( V_65 ) ;
V_29 = F_341 ( V_35 , V_206 -> V_22 , V_206 -> V_33 , 1 ) ;
if ( V_29 ) {
F_180 ( V_37 , L_25 ,
V_206 -> V_22 , V_206 -> V_33 ) ;
F_81 () ;
}
F_393 ( V_35 , V_206 -> V_22 , V_206 -> V_33 ) ;
return V_29 ;
}
static int F_157 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
T_2 V_17 , T_2 V_145 ,
T_2 V_7 , struct V_441 * V_21 ,
int V_165 , struct V_68 * V_206 )
{
int V_29 ;
struct V_12 * V_37 = V_35 -> V_37 ;
struct V_115 * V_526 ;
struct V_137 * V_527 ;
struct V_161 * V_162 ;
struct V_64 * V_65 ;
struct V_66 * V_67 ;
T_3 V_57 = sizeof( * V_526 ) + sizeof( * V_162 ) ;
bool V_171 = F_74 ( V_35 -> V_37 ,
V_120 ) ;
if ( ! V_171 )
V_57 += sizeof( * V_527 ) ;
V_65 = F_33 () ;
if ( ! V_65 ) {
F_392 ( V_35 , V_206 -> V_22 ,
V_35 -> V_88 ) ;
return - V_72 ;
}
V_65 -> V_202 = 1 ;
V_29 = F_104 ( V_109 , V_37 -> V_63 , V_65 ,
V_206 , V_57 ) ;
if ( V_29 ) {
F_392 ( V_35 , V_206 -> V_22 ,
V_35 -> V_88 ) ;
F_49 ( V_65 ) ;
return V_29 ;
}
V_67 = V_65 -> V_83 [ 0 ] ;
V_526 = F_76 ( V_67 , V_65 -> V_84 [ 0 ] ,
struct V_115 ) ;
F_88 ( V_67 , V_526 , 1 ) ;
F_89 ( V_67 , V_526 , V_109 -> V_271 ) ;
F_90 ( V_67 , V_526 ,
V_7 | V_143 ) ;
if ( V_171 ) {
V_162 = (struct V_161 * ) ( V_526 + 1 ) ;
} else {
V_527 = (struct V_137 * ) ( V_526 + 1 ) ;
F_152 ( V_67 , V_527 , V_21 ) ;
F_92 ( V_67 , V_527 , V_165 ) ;
V_162 = (struct V_161 * ) ( V_527 + 1 ) ;
}
if ( V_17 > 0 ) {
F_30 ( ! ( V_7 & V_125 ) ) ;
F_130 ( V_67 , V_162 ,
V_163 ) ;
F_131 ( V_67 , V_162 , V_17 ) ;
} else {
F_130 ( V_67 , V_162 ,
V_164 ) ;
F_131 ( V_67 , V_162 , V_145 ) ;
}
F_93 ( V_67 ) ;
F_49 ( V_65 ) ;
V_29 = F_341 ( V_35 , V_206 -> V_22 , V_35 -> V_88 , 1 ) ;
if ( V_29 ) {
F_180 ( V_37 , L_25 ,
V_206 -> V_22 , V_206 -> V_33 ) ;
F_81 () ;
}
F_393 ( V_35 , V_206 -> V_22 , V_35 -> V_88 ) ;
return V_29 ;
}
int F_394 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
T_2 V_145 , T_2 V_132 ,
T_2 V_33 , struct V_68 * V_206 )
{
int V_29 ;
F_30 ( V_145 == V_200 ) ;
V_29 = F_144 ( V_35 -> V_37 , V_109 , V_206 -> V_22 ,
V_206 -> V_33 , 0 ,
V_145 , V_132 , V_33 ,
V_220 , NULL , 0 ) ;
return V_29 ;
}
int F_395 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
T_2 V_145 , T_2 V_132 , T_2 V_33 ,
struct V_68 * V_206 )
{
int V_29 ;
struct V_1 * V_14 ;
if ( ! F_74 ( V_35 -> V_37 , V_461 ) ) {
V_29 = F_351 ( V_35 , V_206 -> V_22 , V_206 -> V_33 ) ;
if ( V_29 )
return V_29 ;
}
V_14 = F_66 ( V_35 -> V_37 , V_206 -> V_22 ) ;
if ( ! V_14 )
return - V_457 ;
V_29 = F_353 ( V_14 , V_206 -> V_33 ,
V_499 ) ;
F_30 ( V_29 ) ;
V_29 = F_150 ( V_109 , V_35 , 0 , V_145 ,
0 , V_132 , V_33 , V_206 , 1 ) ;
F_6 ( V_14 ) ;
return V_29 ;
}
static struct V_66 *
F_396 ( struct V_108 * V_109 , struct V_34 * V_35 ,
T_2 V_27 , T_3 V_528 , int V_165 )
{
struct V_66 * V_252 ;
V_252 = F_397 ( V_35 , V_27 , V_528 ) ;
if ( ! V_252 )
return F_398 ( - V_72 ) ;
F_399 ( V_252 , V_109 -> V_271 ) ;
F_400 ( V_35 -> V_248 . V_22 , V_252 , V_165 ) ;
F_401 ( V_252 ) ;
F_402 ( V_109 , V_35 , V_252 ) ;
F_369 ( V_529 , & V_252 -> V_477 ) ;
F_403 ( V_252 ) ;
F_404 ( V_252 ) ;
if ( V_35 -> V_248 . V_22 == V_200 ) {
if ( V_35 -> V_530 % 2 == 0 )
F_346 ( & V_35 -> V_531 , V_252 -> V_32 ,
V_252 -> V_32 + V_252 -> V_49 - 1 , V_40 ) ;
else
F_405 ( & V_35 -> V_531 , V_252 -> V_32 ,
V_252 -> V_32 + V_252 -> V_49 - 1 , V_40 ) ;
} else {
F_346 ( & V_109 -> V_126 -> V_532 , V_252 -> V_32 ,
V_252 -> V_32 + V_252 -> V_49 - 1 , V_40 ) ;
}
V_109 -> V_533 ++ ;
return V_252 ;
}
static struct V_232 *
F_406 ( struct V_108 * V_109 ,
struct V_34 * V_35 , T_3 V_528 )
{
struct V_232 * V_372 ;
struct V_232 * V_233 = & V_35 -> V_37 -> V_235 ;
int V_29 ;
bool V_534 = false ;
V_372 = F_304 ( V_109 , V_35 ) ;
if ( F_301 ( V_372 -> V_57 == 0 ) )
goto V_535;
V_78:
V_29 = F_302 ( V_372 , V_528 ) ;
if ( ! V_29 )
return V_372 ;
if ( V_372 -> V_536 )
return F_398 ( V_29 ) ;
if ( V_372 -> type == V_537 && ! V_534 ) {
V_534 = true ;
F_320 ( V_35 -> V_37 ) ;
goto V_78;
}
if ( F_240 ( V_35 , V_351 ) ) {
static F_407 ( V_538 ,
V_539 * 10 ,
1 ) ;
if ( F_408 ( & V_538 ) )
F_409 ( 1 , V_540
L_26 , V_29 ) ;
}
V_535:
V_29 = F_299 ( V_35 , V_372 , V_528 ,
V_383 ) ;
if ( ! V_29 )
return V_372 ;
if ( V_372 -> type != V_537 &&
V_372 -> V_104 == V_233 -> V_104 ) {
V_29 = F_302 ( V_233 , V_528 ) ;
if ( ! V_29 )
return V_233 ;
}
return F_398 ( V_29 ) ;
}
static void F_410 ( struct V_12 * V_37 ,
struct V_232 * V_372 , T_3 V_528 )
{
F_305 ( V_372 , V_528 , 0 ) ;
F_307 ( V_37 , V_372 , NULL , 0 ) ;
}
struct V_66 * F_411 ( struct V_108 * V_109 ,
struct V_34 * V_35 , T_3 V_528 ,
T_2 V_17 , T_2 V_145 ,
struct V_441 * V_21 , int V_165 ,
T_2 V_541 , T_2 V_489 )
{
struct V_68 V_206 ;
struct V_232 * V_372 ;
struct V_66 * V_252 ;
T_2 V_7 = 0 ;
int V_29 ;
bool V_171 = F_74 ( V_35 -> V_37 ,
V_120 ) ;
V_372 = F_406 ( V_109 , V_35 , V_528 ) ;
if ( F_232 ( V_372 ) )
return F_412 ( V_372 ) ;
V_29 = F_388 ( V_35 , V_528 , V_528 ,
V_489 , V_541 , & V_206 , 0 ) ;
if ( V_29 ) {
F_410 ( V_35 -> V_37 , V_372 , V_528 ) ;
return F_398 ( V_29 ) ;
}
V_252 = F_396 ( V_109 , V_35 , V_206 . V_22 ,
V_528 , V_165 ) ;
F_30 ( F_232 ( V_252 ) ) ;
if ( V_145 == V_542 ) {
if ( V_17 == 0 )
V_17 = V_206 . V_22 ;
V_7 |= V_125 ;
} else
F_30 ( V_17 > 0 ) ;
if ( V_145 != V_200 ) {
struct V_178 * V_128 ;
V_128 = F_205 () ;
F_30 ( ! V_128 ) ;
if ( V_21 )
memcpy ( & V_128 -> V_21 , V_21 , sizeof( V_128 -> V_21 ) ) ;
else
memset ( & V_128 -> V_21 , 0 , sizeof( V_128 -> V_21 ) ) ;
V_128 -> V_130 = V_7 ;
if ( V_171 )
V_128 -> V_210 = 0 ;
else
V_128 -> V_210 = 1 ;
V_128 -> V_129 = 1 ;
V_128 -> V_182 = 0 ;
V_128 -> V_165 = V_165 ;
V_29 = F_143 ( V_35 -> V_37 , V_109 ,
V_206 . V_22 ,
V_206 . V_33 , V_17 , V_145 ,
V_165 , V_220 ,
V_128 , 0 ) ;
F_30 ( V_29 ) ;
}
return V_252 ;
}
static T_1 void F_413 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
struct V_543 * V_544 ,
struct V_64 * V_65 )
{
T_2 V_27 ;
T_2 V_274 ;
T_2 V_111 ;
T_2 V_7 ;
T_3 V_71 ;
T_3 V_528 ;
struct V_68 V_21 ;
struct V_66 * V_459 ;
int V_29 ;
int V_545 ;
int V_546 = 0 ;
if ( V_65 -> V_84 [ V_544 -> V_165 ] < V_544 -> V_547 ) {
V_544 -> V_548 = V_544 -> V_548 * 2 / 3 ;
V_544 -> V_548 = F_378 ( V_544 -> V_548 , 2 ) ;
} else {
V_544 -> V_548 = V_544 -> V_548 * 3 / 2 ;
V_544 -> V_548 = F_24 ( int , V_544 -> V_548 ,
F_414 ( V_35 ) ) ;
}
V_459 = V_65 -> V_83 [ V_544 -> V_165 ] ;
V_71 = F_38 ( V_459 ) ;
V_528 = F_223 ( V_35 , V_544 -> V_165 - 1 ) ;
for ( V_545 = V_65 -> V_84 [ V_544 -> V_165 ] ; V_545 < V_71 ; V_545 ++ ) {
if ( V_546 >= V_544 -> V_548 )
break;
F_46 () ;
V_27 = F_222 ( V_459 , V_545 ) ;
V_274 = F_415 ( V_459 , V_545 ) ;
if ( V_545 == V_65 -> V_84 [ V_544 -> V_165 ] )
goto V_76;
if ( V_544 -> V_549 == V_550 &&
V_274 <= V_35 -> V_248 . V_33 )
continue;
V_29 = F_73 ( V_109 , V_35 , V_27 ,
V_544 -> V_165 - 1 , 1 , & V_111 ,
& V_7 ) ;
if ( V_29 < 0 )
continue;
F_30 ( V_111 == 0 ) ;
if ( V_544 -> V_549 == V_551 ) {
if ( V_111 == 1 )
goto V_76;
if ( V_544 -> V_165 == 1 &&
( V_7 & V_125 ) )
continue;
if ( ! V_544 -> V_552 ||
V_274 <= V_35 -> V_248 . V_33 )
continue;
F_121 ( V_459 , & V_21 , V_545 ) ;
V_29 = F_416 ( & V_21 ,
& V_544 -> V_553 ) ;
if ( V_29 < 0 )
continue;
} else {
if ( V_544 -> V_165 == 1 &&
( V_7 & V_125 ) )
continue;
}
V_76:
V_29 = F_417 ( V_35 , V_27 , V_528 ,
V_274 ) ;
if ( V_29 )
break;
V_546 ++ ;
}
V_544 -> V_547 = V_545 ;
}
static T_1 int F_418 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
struct V_64 * V_65 ,
struct V_543 * V_544 , int V_554 )
{
int V_165 = V_544 -> V_165 ;
struct V_66 * V_459 = V_65 -> V_83 [ V_165 ] ;
T_2 V_555 = V_125 ;
int V_29 ;
if ( V_544 -> V_549 == V_550 &&
F_215 ( V_459 ) != V_35 -> V_248 . V_22 )
return 1 ;
if ( V_554 &&
( ( V_544 -> V_549 == V_551 && V_544 -> V_111 [ V_165 ] != 1 ) ||
( V_544 -> V_549 == V_550 && ! ( V_544 -> V_7 [ V_165 ] & V_555 ) ) ) ) {
F_30 ( ! V_65 -> V_556 [ V_165 ] ) ;
V_29 = F_73 ( V_109 , V_35 ,
V_459 -> V_32 , V_165 , 1 ,
& V_544 -> V_111 [ V_165 ] ,
& V_544 -> V_7 [ V_165 ] ) ;
F_30 ( V_29 == - V_72 ) ;
if ( V_29 )
return V_29 ;
F_30 ( V_544 -> V_111 [ V_165 ] == 0 ) ;
}
if ( V_544 -> V_549 == V_551 ) {
if ( V_544 -> V_111 [ V_165 ] > 1 )
return 1 ;
if ( V_65 -> V_556 [ V_165 ] && ! V_544 -> V_172 ) {
F_419 ( V_459 , V_65 -> V_556 [ V_165 ] ) ;
V_65 -> V_556 [ V_165 ] = 0 ;
}
return 0 ;
}
if ( ! ( V_544 -> V_7 [ V_165 ] & V_555 ) ) {
F_30 ( ! V_65 -> V_556 [ V_165 ] ) ;
V_29 = F_224 ( V_109 , V_35 , V_459 , 1 , V_544 -> V_557 ) ;
F_30 ( V_29 ) ;
V_29 = F_225 ( V_109 , V_35 , V_459 , 0 , V_544 -> V_557 ) ;
F_30 ( V_29 ) ;
V_29 = F_204 ( V_109 , V_35 , V_459 -> V_32 ,
V_459 -> V_49 , V_555 ,
F_216 ( V_459 ) , 0 ) ;
F_30 ( V_29 ) ;
V_544 -> V_7 [ V_165 ] |= V_555 ;
}
if ( V_65 -> V_556 [ V_165 ] && V_165 > 0 ) {
F_419 ( V_459 , V_65 -> V_556 [ V_165 ] ) ;
V_65 -> V_556 [ V_165 ] = 0 ;
}
return 0 ;
}
static T_1 int F_420 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
struct V_64 * V_65 ,
struct V_543 * V_544 , int * V_554 )
{
T_2 V_27 ;
T_2 V_274 ;
T_2 V_17 ;
T_3 V_528 ;
struct V_68 V_21 ;
struct V_66 * V_81 ;
int V_165 = V_544 -> V_165 ;
int V_76 = 0 ;
int V_29 = 0 ;
V_274 = F_415 ( V_65 -> V_83 [ V_165 ] ,
V_65 -> V_84 [ V_165 ] ) ;
if ( V_544 -> V_549 == V_550 &&
V_274 <= V_35 -> V_248 . V_33 ) {
* V_554 = 1 ;
return 1 ;
}
V_27 = F_222 ( V_65 -> V_83 [ V_165 ] , V_65 -> V_84 [ V_165 ] ) ;
V_528 = F_223 ( V_35 , V_165 - 1 ) ;
V_81 = F_421 ( V_35 , V_27 , V_528 ) ;
if ( ! V_81 ) {
V_81 = F_397 ( V_35 , V_27 , V_528 ) ;
if ( ! V_81 )
return - V_72 ;
F_400 ( V_35 -> V_248 . V_22 , V_81 ,
V_165 - 1 ) ;
V_76 = 1 ;
}
F_401 ( V_81 ) ;
F_403 ( V_81 ) ;
V_29 = F_73 ( V_109 , V_35 , V_27 , V_165 - 1 , 1 ,
& V_544 -> V_111 [ V_165 - 1 ] ,
& V_544 -> V_7 [ V_165 - 1 ] ) ;
if ( V_29 < 0 ) {
F_422 ( V_81 ) ;
return V_29 ;
}
if ( F_301 ( V_544 -> V_111 [ V_165 - 1 ] == 0 ) ) {
F_180 ( V_35 -> V_37 , L_27 ) ;
F_81 () ;
}
* V_554 = 0 ;
if ( V_544 -> V_549 == V_551 ) {
if ( V_544 -> V_111 [ V_165 - 1 ] > 1 ) {
if ( V_165 == 1 &&
( V_544 -> V_7 [ 0 ] & V_125 ) )
goto V_558;
if ( ! V_544 -> V_552 ||
V_274 <= V_35 -> V_248 . V_33 )
goto V_558;
F_121 ( V_65 -> V_83 [ V_165 ] , & V_21 ,
V_65 -> V_84 [ V_165 ] ) ;
V_29 = F_416 ( & V_21 , & V_544 -> V_553 ) ;
if ( V_29 < 0 )
goto V_558;
V_544 -> V_549 = V_550 ;
V_544 -> V_559 = V_165 - 1 ;
}
} else {
if ( V_165 == 1 &&
( V_544 -> V_7 [ 0 ] & V_125 ) )
goto V_558;
}
if ( ! F_423 ( V_81 , V_274 , 0 ) ) {
F_422 ( V_81 ) ;
F_424 ( V_81 ) ;
V_81 = NULL ;
* V_554 = 1 ;
}
if ( ! V_81 ) {
if ( V_76 && V_165 == 1 )
F_413 ( V_109 , V_35 , V_544 , V_65 ) ;
V_81 = F_425 ( V_35 , V_27 , V_528 , V_274 ) ;
if ( ! V_81 || ! F_426 ( V_81 ) ) {
F_424 ( V_81 ) ;
return - V_173 ;
}
F_401 ( V_81 ) ;
F_403 ( V_81 ) ;
}
V_165 -- ;
F_30 ( V_165 != F_216 ( V_81 ) ) ;
V_65 -> V_83 [ V_165 ] = V_81 ;
V_65 -> V_84 [ V_165 ] = 0 ;
V_65 -> V_556 [ V_165 ] = V_560 ;
V_544 -> V_165 = V_165 ;
if ( V_544 -> V_165 == 1 )
V_544 -> V_547 = 0 ;
return 0 ;
V_558:
V_544 -> V_111 [ V_165 - 1 ] = 0 ;
V_544 -> V_7 [ V_165 - 1 ] = 0 ;
if ( V_544 -> V_549 == V_551 ) {
if ( V_544 -> V_7 [ V_165 ] & V_125 ) {
V_17 = V_65 -> V_83 [ V_165 ] -> V_32 ;
} else {
F_30 ( V_35 -> V_248 . V_22 !=
F_215 ( V_65 -> V_83 [ V_165 ] ) ) ;
V_17 = 0 ;
}
V_29 = V_258 ( V_109 , V_35 , V_27 , V_528 , V_17 ,
V_35 -> V_248 . V_22 , V_165 - 1 , 0 , 0 ) ;
F_30 ( V_29 ) ;
}
F_422 ( V_81 ) ;
F_424 ( V_81 ) ;
* V_554 = 1 ;
return 1 ;
}
static T_1 int F_427 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
struct V_64 * V_65 ,
struct V_543 * V_544 )
{
int V_29 ;
int V_165 = V_544 -> V_165 ;
struct V_66 * V_459 = V_65 -> V_83 [ V_165 ] ;
T_2 V_17 = 0 ;
if ( V_544 -> V_549 == V_550 ) {
F_30 ( V_544 -> V_559 < V_165 ) ;
if ( V_165 < V_544 -> V_559 )
goto V_73;
V_29 = F_41 ( V_65 , V_165 + 1 , & V_544 -> V_553 ) ;
if ( V_29 > 0 )
V_544 -> V_552 = 0 ;
V_544 -> V_549 = V_551 ;
V_544 -> V_559 = - 1 ;
V_65 -> V_84 [ V_165 ] = 0 ;
if ( ! V_65 -> V_556 [ V_165 ] ) {
F_30 ( V_165 == 0 ) ;
F_401 ( V_459 ) ;
F_403 ( V_459 ) ;
V_65 -> V_556 [ V_165 ] = V_560 ;
V_29 = F_73 ( V_109 , V_35 ,
V_459 -> V_32 , V_165 , 1 ,
& V_544 -> V_111 [ V_165 ] ,
& V_544 -> V_7 [ V_165 ] ) ;
if ( V_29 < 0 ) {
F_419 ( V_459 , V_65 -> V_556 [ V_165 ] ) ;
V_65 -> V_556 [ V_165 ] = 0 ;
return V_29 ;
}
F_30 ( V_544 -> V_111 [ V_165 ] == 0 ) ;
if ( V_544 -> V_111 [ V_165 ] == 1 ) {
F_419 ( V_459 , V_65 -> V_556 [ V_165 ] ) ;
V_65 -> V_556 [ V_165 ] = 0 ;
return 1 ;
}
}
}
F_30 ( V_544 -> V_111 [ V_165 ] > 1 && ! V_65 -> V_556 [ V_165 ] ) ;
if ( V_544 -> V_111 [ V_165 ] == 1 ) {
if ( V_165 == 0 ) {
if ( V_544 -> V_7 [ V_165 ] & V_125 )
V_29 = F_225 ( V_109 , V_35 , V_459 , 1 ,
V_544 -> V_557 ) ;
else
V_29 = F_225 ( V_109 , V_35 , V_459 , 0 ,
V_544 -> V_557 ) ;
F_30 ( V_29 ) ;
}
if ( ! V_65 -> V_556 [ V_165 ] &&
F_367 ( V_459 ) == V_109 -> V_271 ) {
F_401 ( V_459 ) ;
F_403 ( V_459 ) ;
V_65 -> V_556 [ V_165 ] = V_560 ;
}
F_402 ( V_109 , V_35 , V_459 ) ;
}
if ( V_459 == V_35 -> V_127 ) {
if ( V_544 -> V_7 [ V_165 ] & V_125 )
V_17 = V_459 -> V_32 ;
else
F_30 ( V_35 -> V_248 . V_22 !=
F_215 ( V_459 ) ) ;
} else {
if ( V_544 -> V_7 [ V_165 + 1 ] & V_125 )
V_17 = V_65 -> V_83 [ V_165 + 1 ] -> V_32 ;
else
F_30 ( V_35 -> V_248 . V_22 !=
F_215 ( V_65 -> V_83 [ V_165 + 1 ] ) ) ;
}
F_366 ( V_109 , V_35 , V_459 , V_17 , V_544 -> V_111 [ V_165 ] == 1 ) ;
V_73:
V_544 -> V_111 [ V_165 ] = 0 ;
V_544 -> V_7 [ V_165 ] = 0 ;
return 0 ;
}
static T_1 int F_428 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
struct V_64 * V_65 ,
struct V_543 * V_544 )
{
int V_165 = V_544 -> V_165 ;
int V_554 = 1 ;
int V_29 ;
while ( V_165 >= 0 ) {
V_29 = F_418 ( V_109 , V_35 , V_65 , V_544 , V_554 ) ;
if ( V_29 > 0 )
break;
if ( V_165 == 0 )
break;
if ( V_65 -> V_84 [ V_165 ] >=
F_38 ( V_65 -> V_83 [ V_165 ] ) )
break;
V_29 = F_420 ( V_109 , V_35 , V_65 , V_544 , & V_554 ) ;
if ( V_29 > 0 ) {
V_65 -> V_84 [ V_165 ] ++ ;
continue;
} else if ( V_29 < 0 )
return V_29 ;
V_165 = V_544 -> V_165 ;
}
return 0 ;
}
static T_1 int F_429 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
struct V_64 * V_65 ,
struct V_543 * V_544 , int V_561 )
{
int V_165 = V_544 -> V_165 ;
int V_29 ;
V_65 -> V_84 [ V_165 ] = F_38 ( V_65 -> V_83 [ V_165 ] ) ;
while ( V_165 < V_561 && V_65 -> V_83 [ V_165 ] ) {
V_544 -> V_165 = V_165 ;
if ( V_65 -> V_84 [ V_165 ] + 1 <
F_38 ( V_65 -> V_83 [ V_165 ] ) ) {
V_65 -> V_84 [ V_165 ] ++ ;
return 0 ;
} else {
V_29 = F_427 ( V_109 , V_35 , V_65 , V_544 ) ;
if ( V_29 > 0 )
return 0 ;
if ( V_65 -> V_556 [ V_165 ] ) {
F_419 ( V_65 -> V_83 [ V_165 ] ,
V_65 -> V_556 [ V_165 ] ) ;
V_65 -> V_556 [ V_165 ] = 0 ;
}
F_424 ( V_65 -> V_83 [ V_165 ] ) ;
V_65 -> V_83 [ V_165 ] = NULL ;
V_165 ++ ;
}
}
return 1 ;
}
int F_430 ( struct V_34 * V_35 ,
struct V_232 * V_372 , int V_552 ,
int V_557 )
{
struct V_64 * V_65 ;
struct V_108 * V_109 ;
struct V_34 * V_87 = V_35 -> V_37 -> V_87 ;
struct V_562 * V_249 = & V_35 -> V_249 ;
struct V_543 * V_544 ;
struct V_68 V_21 ;
int V_82 = 0 ;
int V_29 ;
int V_165 ;
bool V_563 = false ;
V_65 = F_33 () ;
if ( ! V_65 ) {
V_82 = - V_72 ;
goto V_73;
}
V_544 = F_52 ( sizeof( * V_544 ) , V_40 ) ;
if ( ! V_544 ) {
F_49 ( V_65 ) ;
V_82 = - V_72 ;
goto V_73;
}
V_109 = F_431 ( V_87 , 0 ) ;
if ( F_232 ( V_109 ) ) {
V_82 = F_233 ( V_109 ) ;
goto V_122;
}
if ( V_372 )
V_109 -> V_372 = V_372 ;
if ( F_432 ( & V_249 -> V_564 ) == 0 ) {
V_165 = F_216 ( V_35 -> V_127 ) ;
V_65 -> V_83 [ V_165 ] = F_433 ( V_35 ) ;
F_403 ( V_65 -> V_83 [ V_165 ] ) ;
V_65 -> V_84 [ V_165 ] = 0 ;
V_65 -> V_556 [ V_165 ] = V_560 ;
memset ( & V_544 -> V_553 , 0 ,
sizeof( V_544 -> V_553 ) ) ;
} else {
F_434 ( & V_21 , & V_249 -> V_564 ) ;
memcpy ( & V_544 -> V_553 , & V_21 ,
sizeof( V_544 -> V_553 ) ) ;
V_165 = V_249 -> V_565 ;
F_30 ( V_165 == 0 ) ;
V_65 -> V_566 = V_165 ;
V_29 = F_37 ( NULL , V_35 , & V_21 , V_65 , 0 , 0 ) ;
V_65 -> V_566 = 0 ;
if ( V_29 < 0 ) {
V_82 = V_29 ;
goto V_567;
}
F_8 ( V_29 > 0 ) ;
F_126 ( V_65 , 0 ) ;
V_165 = F_216 ( V_35 -> V_127 ) ;
while ( 1 ) {
F_401 ( V_65 -> V_83 [ V_165 ] ) ;
F_403 ( V_65 -> V_83 [ V_165 ] ) ;
V_65 -> V_556 [ V_165 ] = V_560 ;
V_29 = F_73 ( V_109 , V_35 ,
V_65 -> V_83 [ V_165 ] -> V_32 ,
V_165 , 1 , & V_544 -> V_111 [ V_165 ] ,
& V_544 -> V_7 [ V_165 ] ) ;
if ( V_29 < 0 ) {
V_82 = V_29 ;
goto V_567;
}
F_30 ( V_544 -> V_111 [ V_165 ] == 0 ) ;
if ( V_165 == V_249 -> V_565 )
break;
F_422 ( V_65 -> V_83 [ V_165 ] ) ;
V_65 -> V_556 [ V_165 ] = 0 ;
F_8 ( V_544 -> V_111 [ V_165 ] != 1 ) ;
V_165 -- ;
}
}
V_544 -> V_165 = V_165 ;
V_544 -> V_559 = - 1 ;
V_544 -> V_549 = V_551 ;
V_544 -> V_552 = V_552 ;
V_544 -> V_172 = 0 ;
V_544 -> V_557 = V_557 ;
V_544 -> V_548 = F_414 ( V_35 ) ;
while ( 1 ) {
V_29 = F_428 ( V_109 , V_35 , V_65 , V_544 ) ;
if ( V_29 < 0 ) {
V_82 = V_29 ;
break;
}
V_29 = F_429 ( V_109 , V_35 , V_65 , V_544 , V_166 ) ;
if ( V_29 < 0 ) {
V_82 = V_29 ;
break;
}
if ( V_29 > 0 ) {
F_30 ( V_544 -> V_549 != V_551 ) ;
break;
}
if ( V_544 -> V_549 == V_551 ) {
V_165 = V_544 -> V_165 ;
F_435 ( V_65 -> V_83 [ V_165 ] ,
& V_249 -> V_564 ,
V_65 -> V_84 [ V_165 ] ) ;
V_249 -> V_565 = V_165 ;
}
F_30 ( V_544 -> V_165 == 0 ) ;
if ( F_436 ( V_109 , V_87 ) ||
( ! V_557 && F_437 ( V_35 ) ) ) {
V_29 = F_438 ( V_109 , V_87 ,
& V_35 -> V_248 ,
V_249 ) ;
if ( V_29 ) {
F_146 ( V_109 , V_87 , V_29 ) ;
V_82 = V_29 ;
goto V_567;
}
F_439 ( V_109 , V_87 ) ;
if ( ! V_557 && F_437 ( V_35 ) ) {
F_440 ( L_28 ) ;
V_82 = - V_176 ;
goto V_122;
}
V_109 = F_431 ( V_87 , 0 ) ;
if ( F_232 ( V_109 ) ) {
V_82 = F_233 ( V_109 ) ;
goto V_122;
}
if ( V_372 )
V_109 -> V_372 = V_372 ;
}
}
F_43 ( V_65 ) ;
if ( V_82 )
goto V_567;
V_29 = F_441 ( V_109 , V_87 , & V_35 -> V_248 ) ;
if ( V_29 ) {
F_146 ( V_109 , V_87 , V_29 ) ;
goto V_567;
}
if ( V_35 -> V_248 . V_22 != V_542 ) {
V_29 = F_442 ( V_87 , & V_35 -> V_248 , V_65 ,
NULL , NULL ) ;
if ( V_29 < 0 ) {
F_146 ( V_109 , V_87 , V_29 ) ;
V_82 = V_29 ;
goto V_567;
} else if ( V_29 > 0 ) {
F_443 ( V_109 , V_87 ,
V_35 -> V_248 . V_22 ) ;
}
}
if ( V_35 -> V_568 ) {
F_444 ( V_87 -> V_37 , V_35 ) ;
} else {
F_424 ( V_35 -> V_127 ) ;
F_424 ( V_35 -> V_569 ) ;
F_445 ( V_35 ) ;
}
V_563 = true ;
V_567:
F_439 ( V_109 , V_87 ) ;
V_122:
F_9 ( V_544 ) ;
F_49 ( V_65 ) ;
V_73:
if ( ! V_557 && V_563 == false )
F_446 ( V_35 ) ;
if ( V_82 )
F_447 ( V_35 -> V_37 , V_82 ) ;
return V_82 ;
}
int F_448 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
struct V_66 * V_127 ,
struct V_66 * V_17 )
{
struct V_64 * V_65 ;
struct V_543 * V_544 ;
int V_165 ;
int V_570 ;
int V_29 = 0 ;
int V_571 ;
F_30 ( V_35 -> V_248 . V_22 != V_542 ) ;
V_65 = F_33 () ;
if ( ! V_65 )
return - V_72 ;
V_544 = F_52 ( sizeof( * V_544 ) , V_40 ) ;
if ( ! V_544 ) {
F_49 ( V_65 ) ;
return - V_72 ;
}
F_449 ( V_17 ) ;
V_570 = F_216 ( V_17 ) ;
F_450 ( V_17 ) ;
V_65 -> V_83 [ V_570 ] = V_17 ;
V_65 -> V_84 [ V_570 ] = F_38 ( V_17 ) ;
F_449 ( V_127 ) ;
V_165 = F_216 ( V_127 ) ;
V_65 -> V_83 [ V_165 ] = V_127 ;
V_65 -> V_84 [ V_165 ] = 0 ;
V_65 -> V_556 [ V_165 ] = V_560 ;
V_544 -> V_111 [ V_570 ] = 1 ;
V_544 -> V_7 [ V_570 ] = V_125 ;
V_544 -> V_165 = V_165 ;
V_544 -> V_559 = - 1 ;
V_544 -> V_549 = V_551 ;
V_544 -> V_552 = 0 ;
V_544 -> V_172 = 1 ;
V_544 -> V_557 = 1 ;
V_544 -> V_548 = F_414 ( V_35 ) ;
while ( 1 ) {
V_571 = F_428 ( V_109 , V_35 , V_65 , V_544 ) ;
if ( V_571 < 0 ) {
V_29 = V_571 ;
break;
}
V_571 = F_429 ( V_109 , V_35 , V_65 , V_544 , V_570 ) ;
if ( V_571 < 0 )
V_29 = V_571 ;
if ( V_571 != 0 )
break;
}
F_9 ( V_544 ) ;
F_49 ( V_65 ) ;
return V_29 ;
}
static T_2 F_451 ( struct V_34 * V_35 , T_2 V_7 )
{
T_2 V_319 ;
T_2 V_572 ;
V_572 = F_257 ( V_35 -> V_37 , V_7 ) ;
if ( V_572 )
return F_259 ( V_572 ) ;
V_319 = V_35 -> V_37 -> V_320 -> V_321 +
V_35 -> V_37 -> V_320 -> V_322 ;
V_572 = V_325 |
V_326 | V_327 |
V_285 | V_286 ;
if ( V_319 == 1 ) {
V_572 |= V_284 ;
V_572 = V_7 & ~ V_572 ;
if ( V_7 & V_325 )
return V_572 ;
if ( V_7 & ( V_285 |
V_286 ) )
return V_572 | V_284 ;
} else {
if ( V_7 & V_572 )
return V_7 ;
V_572 |= V_284 ;
V_572 = V_7 & ~ V_572 ;
if ( V_7 & V_284 )
return V_572 | V_285 ;
}
return V_7 ;
}
static int F_452 ( struct V_1 * V_2 , int V_344 )
{
struct V_101 * V_343 = V_2 -> V_104 ;
T_2 V_36 ;
T_2 V_573 ;
int V_29 = - V_339 ;
if ( ( V_343 -> V_7 &
( V_309 | V_307 ) ) &&
! V_344 )
V_573 = 1 * 1024 * 1024 ;
else
V_573 = 0 ;
F_11 ( & V_343 -> V_52 ) ;
F_11 ( & V_2 -> V_52 ) ;
if ( V_2 -> V_269 ) {
V_29 = 0 ;
goto V_73;
}
V_36 = V_2 -> V_21 . V_33 - V_2 -> V_10 - V_2 -> V_9 -
V_2 -> V_46 - F_344 ( & V_2 -> V_134 ) ;
if ( V_343 -> V_282 + V_343 -> V_294 + V_343 -> V_293 +
V_343 -> V_296 + V_343 -> V_295 + V_36 +
V_573 <= V_343 -> V_281 ) {
V_343 -> V_295 += V_36 ;
V_2 -> V_269 = 1 ;
V_29 = 0 ;
}
V_73:
F_13 ( & V_2 -> V_52 ) ;
F_13 ( & V_343 -> V_52 ) ;
return V_29 ;
}
int F_453 ( struct V_34 * V_35 ,
struct V_1 * V_2 )
{
struct V_108 * V_109 ;
T_2 V_574 ;
int V_29 ;
F_30 ( V_2 -> V_269 ) ;
V_109 = F_266 ( V_35 ) ;
if ( F_232 ( V_109 ) )
return F_233 ( V_109 ) ;
V_574 = F_451 ( V_35 , V_2 -> V_7 ) ;
if ( V_574 != V_2 -> V_7 ) {
V_29 = F_267 ( V_109 , V_35 , V_574 ,
V_338 ) ;
if ( V_29 < 0 )
goto V_73;
}
V_29 = F_452 ( V_2 , 0 ) ;
if ( ! V_29 )
goto V_73;
V_574 = F_260 ( V_35 , V_2 -> V_104 -> V_7 ) ;
V_29 = F_267 ( V_109 , V_35 , V_574 ,
V_338 ) ;
if ( V_29 < 0 )
goto V_73;
V_29 = F_452 ( V_2 , 0 ) ;
V_73:
F_268 ( V_109 , V_35 ) ;
return V_29 ;
}
int F_454 ( struct V_108 * V_109 ,
struct V_34 * V_35 , T_2 type )
{
T_2 V_574 = F_260 ( V_35 , type ) ;
return F_267 ( V_109 , V_35 , V_574 ,
V_338 ) ;
}
static T_2 F_455 ( struct V_102 * V_575 )
{
struct V_1 * V_14 ;
T_2 V_576 = 0 ;
int V_283 ;
F_379 (block_group, groups_list, list) {
F_11 ( & V_14 -> V_52 ) ;
if ( ! V_14 -> V_269 ) {
F_13 ( & V_14 -> V_52 ) ;
continue;
}
if ( V_14 -> V_7 & ( V_285 |
V_286 |
V_284 ) )
V_283 = 2 ;
else
V_283 = 1 ;
V_576 += ( V_14 -> V_21 . V_33 -
F_344 ( & V_14 -> V_134 ) ) *
V_283 ;
F_13 ( & V_14 -> V_52 ) ;
}
return V_576 ;
}
T_2 F_456 ( struct V_101 * V_343 )
{
int V_43 ;
T_2 V_576 = 0 ;
F_11 ( & V_343 -> V_52 ) ;
for ( V_43 = 0 ; V_43 < V_290 ; V_43 ++ )
if ( ! F_165 ( & V_343 -> V_291 [ V_43 ] ) )
V_576 += F_455 (
& V_343 -> V_291 [ V_43 ] ) ;
F_13 ( & V_343 -> V_52 ) ;
return V_576 ;
}
void F_457 ( struct V_34 * V_35 ,
struct V_1 * V_2 )
{
struct V_101 * V_343 = V_2 -> V_104 ;
T_2 V_36 ;
F_30 ( ! V_2 -> V_269 ) ;
F_11 ( & V_343 -> V_52 ) ;
F_11 ( & V_2 -> V_52 ) ;
V_36 = V_2 -> V_21 . V_33 - V_2 -> V_10 - V_2 -> V_9 -
V_2 -> V_46 - F_344 ( & V_2 -> V_134 ) ;
V_343 -> V_295 -= V_36 ;
V_2 -> V_269 = 0 ;
F_13 ( & V_2 -> V_52 ) ;
F_13 ( & V_343 -> V_52 ) ;
}
int F_458 ( struct V_34 * V_35 , T_2 V_27 )
{
struct V_1 * V_14 ;
struct V_101 * V_104 ;
struct V_577 * V_320 = V_35 -> V_37 -> V_320 ;
struct V_578 * V_579 ;
struct V_108 * V_109 ;
T_2 V_580 ;
T_2 V_581 = 1 ;
T_2 V_582 = 0 ;
T_2 V_314 ;
int V_497 ;
int V_107 = 0 ;
int V_29 = 0 ;
V_14 = F_66 ( V_35 -> V_37 , V_27 ) ;
if ( ! V_14 )
return - 1 ;
V_580 = F_344 ( & V_14 -> V_134 ) ;
if ( ! V_580 )
goto V_73;
V_104 = V_14 -> V_104 ;
F_11 ( & V_104 -> V_52 ) ;
V_107 = V_104 -> V_107 ;
if ( ( V_104 -> V_281 != V_14 -> V_21 . V_33 ) &&
( V_104 -> V_282 + V_104 -> V_294 +
V_104 -> V_293 + V_104 -> V_295 +
V_580 < V_104 -> V_281 ) ) {
F_13 ( & V_104 -> V_52 ) ;
goto V_73;
}
F_13 ( & V_104 -> V_52 ) ;
V_29 = - 1 ;
V_314 = F_257 ( V_35 -> V_37 , V_14 -> V_7 ) ;
if ( V_314 ) {
V_497 = F_373 ( F_259 ( V_314 ) ) ;
} else {
if ( V_107 )
goto V_73;
V_497 = F_374 ( V_14 ) ;
}
if ( V_497 == V_481 ) {
V_581 = 4 ;
V_580 >>= 1 ;
} else if ( V_497 == V_482 ) {
V_581 = 2 ;
} else if ( V_497 == V_483 ) {
V_580 <<= 1 ;
} else if ( V_497 == V_484 ) {
V_581 = V_320 -> V_321 ;
F_459 ( V_580 , V_581 ) ;
}
V_109 = F_266 ( V_35 ) ;
if ( F_232 ( V_109 ) ) {
V_29 = F_233 ( V_109 ) ;
goto V_73;
}
F_35 ( & V_35 -> V_37 -> V_354 ) ;
F_379 (device, &fs_devices->alloc_list, dev_alloc_list) {
T_2 V_583 ;
if ( V_579 -> V_281 > V_579 -> V_282 + V_580 &&
! V_579 -> V_584 ) {
V_29 = F_460 ( V_109 , V_579 , V_580 ,
& V_583 , NULL ) ;
if ( ! V_29 )
V_582 ++ ;
if ( V_582 >= V_581 )
break;
V_29 = - 1 ;
}
}
F_45 ( & V_35 -> V_37 -> V_354 ) ;
F_268 ( V_109 , V_35 ) ;
V_73:
F_6 ( V_14 ) ;
return V_29 ;
}
static int F_461 ( struct V_34 * V_35 ,
struct V_64 * V_65 , struct V_68 * V_21 )
{
int V_29 = 0 ;
struct V_68 V_139 ;
struct V_66 * V_67 ;
int V_545 ;
V_29 = F_37 ( NULL , V_35 , V_21 , V_65 , 0 , 0 ) ;
if ( V_29 < 0 )
goto V_73;
while ( 1 ) {
V_545 = V_65 -> V_84 [ 0 ] ;
V_67 = V_65 -> V_83 [ 0 ] ;
if ( V_545 >= F_38 ( V_67 ) ) {
V_29 = F_47 ( V_35 , V_65 ) ;
if ( V_29 == 0 )
continue;
if ( V_29 < 0 )
goto V_73;
break;
}
F_40 ( V_67 , & V_139 , V_545 ) ;
if ( V_139 . V_22 >= V_21 -> V_22 &&
V_139 . type == V_177 ) {
V_29 = 0 ;
goto V_73;
}
V_65 -> V_84 [ 0 ] ++ ;
}
V_73:
return V_29 ;
}
void F_462 ( struct V_12 * V_13 )
{
struct V_1 * V_14 ;
T_2 V_70 = 0 ;
while ( 1 ) {
struct V_261 * V_261 ;
V_14 = F_65 ( V_13 , V_70 ) ;
while ( V_14 ) {
F_11 ( & V_14 -> V_52 ) ;
if ( V_14 -> V_162 )
break;
F_13 ( & V_14 -> V_52 ) ;
V_14 = F_229 ( V_13 -> V_87 ,
V_14 ) ;
}
if ( ! V_14 ) {
if ( V_70 == 0 )
break;
V_70 = 0 ;
continue;
}
V_261 = V_14 -> V_261 ;
V_14 -> V_162 = 0 ;
V_14 -> V_261 = NULL ;
F_13 ( & V_14 -> V_52 ) ;
F_244 ( V_261 ) ;
V_70 = V_14 -> V_21 . V_22 + V_14 -> V_21 . V_33 ;
F_6 ( V_14 ) ;
}
}
int F_463 ( struct V_12 * V_13 )
{
struct V_1 * V_14 ;
struct V_101 * V_104 ;
struct V_50 * V_54 ;
struct V_15 * V_30 ;
F_61 ( & V_13 -> V_80 ) ;
while ( ! F_165 ( & V_13 -> V_99 ) ) {
V_54 = F_166 ( V_13 -> V_99 . V_81 ,
struct V_50 , V_91 ) ;
F_182 ( & V_54 -> V_91 ) ;
F_26 ( V_54 ) ;
}
F_63 ( & V_13 -> V_80 ) ;
F_11 ( & V_13 -> V_18 ) ;
while ( ( V_30 = F_178 ( & V_13 -> V_19 ) ) != NULL ) {
V_14 = F_12 ( V_30 , struct V_1 ,
V_20 ) ;
F_175 ( & V_14 -> V_20 ,
& V_13 -> V_19 ) ;
F_13 ( & V_13 -> V_18 ) ;
F_61 ( & V_14 -> V_104 -> V_292 ) ;
F_182 ( & V_14 -> V_91 ) ;
F_63 ( & V_14 -> V_104 -> V_292 ) ;
if ( V_14 -> V_3 == V_53 )
F_372 ( V_14 ) ;
if ( V_14 -> V_3 == V_95 ||
V_14 -> V_3 == V_5 )
F_19 ( V_13 -> V_63 , V_14 ) ;
F_464 ( V_14 ) ;
F_6 ( V_14 ) ;
F_11 ( & V_13 -> V_18 ) ;
}
F_13 ( & V_13 -> V_18 ) ;
F_465 () ;
F_322 ( V_13 ) ;
while ( ! F_165 ( & V_13 -> V_104 ) ) {
V_104 = F_166 ( V_13 -> V_104 . V_81 ,
struct V_101 ,
V_91 ) ;
if ( F_240 ( V_13 -> V_87 , V_351 ) ) {
if ( F_8 ( V_104 -> V_293 > 0 ||
V_104 -> V_294 > 0 ||
V_104 -> V_296 > 0 ) ) {
F_281 ( V_104 , 0 , 0 ) ;
}
}
F_466 ( & V_104 -> V_289 ) ;
F_182 ( & V_104 -> V_91 ) ;
F_9 ( V_104 ) ;
}
return 0 ;
}
static void F_467 ( struct V_101 * V_104 ,
struct V_1 * V_2 )
{
int V_497 = F_374 ( V_2 ) ;
F_61 ( & V_104 -> V_292 ) ;
F_62 ( & V_2 -> V_91 , & V_104 -> V_291 [ V_497 ] ) ;
F_63 ( & V_104 -> V_292 ) ;
}
int F_468 ( struct V_34 * V_35 )
{
struct V_64 * V_65 ;
int V_29 ;
struct V_1 * V_2 ;
struct V_12 * V_13 = V_35 -> V_37 ;
struct V_101 * V_104 ;
struct V_68 V_21 ;
struct V_68 V_139 ;
struct V_66 * V_67 ;
int V_585 = 0 ;
T_2 V_586 ;
V_35 = V_13 -> V_63 ;
V_21 . V_22 = 0 ;
V_21 . V_33 = 0 ;
F_376 ( & V_21 , V_177 ) ;
V_65 = F_33 () ;
if ( ! V_65 )
return - V_72 ;
V_65 -> V_76 = 1 ;
V_586 = F_469 ( V_35 -> V_37 -> V_348 ) ;
if ( F_240 ( V_35 , V_275 ) &&
F_470 ( V_35 -> V_37 -> V_348 ) != V_586 )
V_585 = 1 ;
if ( F_240 ( V_35 , V_587 ) )
V_585 = 1 ;
while ( 1 ) {
V_29 = F_461 ( V_35 , V_65 , & V_21 ) ;
if ( V_29 > 0 )
break;
if ( V_29 != 0 )
goto error;
V_67 = V_65 -> V_83 [ 0 ] ;
F_40 ( V_67 , & V_139 , V_65 -> V_84 [ 0 ] ) ;
V_2 = F_52 ( sizeof( * V_2 ) , V_40 ) ;
if ( ! V_2 ) {
V_29 = - V_72 ;
goto error;
}
V_2 -> V_11 = F_52 ( sizeof( * V_2 -> V_11 ) ,
V_40 ) ;
if ( ! V_2 -> V_11 ) {
F_9 ( V_2 ) ;
V_29 = - V_72 ;
goto error;
}
F_56 ( & V_2 -> V_8 , 1 ) ;
F_251 ( & V_2 -> V_52 ) ;
V_2 -> V_37 = V_13 ;
F_53 ( & V_2 -> V_91 ) ;
F_53 ( & V_2 -> V_588 ) ;
if ( V_585 ) {
V_2 -> V_267 = V_277 ;
if ( F_240 ( V_35 , V_275 ) )
V_2 -> V_278 = 1 ;
}
F_471 ( V_67 , & V_2 -> V_134 ,
F_227 ( V_67 , V_65 -> V_84 [ 0 ] ) ,
sizeof( V_2 -> V_134 ) ) ;
memcpy ( & V_2 -> V_21 , & V_139 , sizeof( V_139 ) ) ;
V_21 . V_22 = V_139 . V_22 + V_139 . V_33 ;
F_43 ( V_65 ) ;
V_2 -> V_7 = F_472 ( & V_2 -> V_134 ) ;
V_2 -> V_333 = V_35 -> V_333 ;
V_2 -> V_589 = F_473 ( V_35 ,
& V_35 -> V_37 -> V_48 ,
V_139 . V_22 ) ;
F_474 ( V_2 ) ;
V_29 = F_21 ( V_35 , V_2 ) ;
if ( V_29 ) {
F_19 ( V_35 , V_2 ) ;
F_9 ( V_2 -> V_11 ) ;
F_9 ( V_2 ) ;
goto error;
}
if ( V_139 . V_33 == F_344 ( & V_2 -> V_134 ) ) {
V_2 -> V_98 = ( T_2 ) - 1 ;
V_2 -> V_3 = V_4 ;
F_19 ( V_35 , V_2 ) ;
} else if ( F_344 ( & V_2 -> V_134 ) == 0 ) {
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
F_464 ( V_2 ) ;
F_6 ( V_2 ) ;
goto error;
}
V_29 = F_248 ( V_13 , V_2 -> V_7 , V_139 . V_33 ,
F_344 ( & V_2 -> V_134 ) ,
& V_104 ) ;
if ( V_29 ) {
F_464 ( V_2 ) ;
F_11 ( & V_13 -> V_18 ) ;
F_175 ( & V_2 -> V_20 ,
& V_13 -> V_19 ) ;
F_13 ( & V_13 -> V_18 ) ;
F_6 ( V_2 ) ;
goto error;
}
V_2 -> V_104 = V_104 ;
F_11 ( & V_2 -> V_104 -> V_52 ) ;
V_2 -> V_104 -> V_295 += V_2 -> V_46 ;
F_13 ( & V_2 -> V_104 -> V_52 ) ;
F_467 ( V_104 , V_2 ) ;
F_253 ( V_35 -> V_37 , V_2 -> V_7 ) ;
if ( F_475 ( V_35 , V_2 -> V_21 . V_22 ) )
F_452 ( V_2 , 1 ) ;
}
F_69 (space_info, &root->fs_info->space_info, list) {
if ( ! ( F_260 ( V_35 , V_104 -> V_7 ) &
( V_286 |
V_285 |
V_326 |
V_327 |
V_284 ) ) )
continue;
F_379 (cache,
&space_info->block_groups[BTRFS_RAID_RAID0],
list)
F_452 ( V_2 , 1 ) ;
F_379 (cache,
&space_info->block_groups[BTRFS_RAID_SINGLE],
list)
F_452 ( V_2 , 1 ) ;
}
F_321 ( V_13 ) ;
V_29 = 0 ;
error:
F_49 ( V_65 ) ;
return V_29 ;
}
void F_199 ( struct V_108 * V_109 ,
struct V_34 * V_35 )
{
struct V_1 * V_14 , * V_323 ;
struct V_34 * V_63 = V_35 -> V_37 -> V_63 ;
struct V_590 V_134 ;
struct V_68 V_21 ;
int V_29 = 0 ;
F_355 (block_group, tmp, &trans->new_bgs,
new_bg_list) {
F_171 ( & V_14 -> V_591 ) ;
if ( V_29 )
continue;
F_11 ( & V_14 -> V_52 ) ;
memcpy ( & V_134 , & V_14 -> V_134 , sizeof( V_134 ) ) ;
memcpy ( & V_21 , & V_14 -> V_21 , sizeof( V_21 ) ) ;
F_13 ( & V_14 -> V_52 ) ;
V_29 = F_476 ( V_109 , V_63 , & V_21 , & V_134 ,
sizeof( V_134 ) ) ;
if ( V_29 )
F_146 ( V_109 , V_63 , V_29 ) ;
V_29 = F_477 ( V_109 , V_63 ,
V_21 . V_22 , V_21 . V_33 ) ;
if ( V_29 )
F_146 ( V_109 , V_63 , V_29 ) ;
}
}
int F_478 ( struct V_108 * V_109 ,
struct V_34 * V_35 , T_2 V_282 ,
T_2 type , T_2 V_592 , T_2 V_593 ,
T_2 V_57 )
{
int V_29 ;
struct V_34 * V_63 ;
struct V_1 * V_2 ;
V_63 = V_35 -> V_37 -> V_63 ;
V_35 -> V_37 -> V_594 = V_109 -> V_271 ;
V_2 = F_52 ( sizeof( * V_2 ) , V_40 ) ;
if ( ! V_2 )
return - V_72 ;
V_2 -> V_11 = F_52 ( sizeof( * V_2 -> V_11 ) ,
V_40 ) ;
if ( ! V_2 -> V_11 ) {
F_9 ( V_2 ) ;
return - V_72 ;
}
V_2 -> V_21 . V_22 = V_593 ;
V_2 -> V_21 . V_33 = V_57 ;
V_2 -> V_21 . type = V_177 ;
V_2 -> V_333 = V_35 -> V_333 ;
V_2 -> V_37 = V_35 -> V_37 ;
V_2 -> V_589 = F_473 ( V_35 ,
& V_35 -> V_37 -> V_48 ,
V_593 ) ;
F_56 ( & V_2 -> V_8 , 1 ) ;
F_251 ( & V_2 -> V_52 ) ;
F_53 ( & V_2 -> V_91 ) ;
F_53 ( & V_2 -> V_588 ) ;
F_53 ( & V_2 -> V_591 ) ;
F_474 ( V_2 ) ;
F_345 ( & V_2 -> V_134 , V_282 ) ;
F_479 ( & V_2 -> V_134 , V_592 ) ;
V_2 -> V_7 = type ;
F_480 ( & V_2 -> V_134 , type ) ;
V_2 -> V_98 = ( T_2 ) - 1 ;
V_2 -> V_3 = V_4 ;
V_29 = F_21 ( V_35 , V_2 ) ;
if ( V_29 ) {
F_19 ( V_35 , V_2 ) ;
F_9 ( V_2 -> V_11 ) ;
F_9 ( V_2 ) ;
return V_29 ;
}
F_27 ( V_2 , V_35 -> V_37 , V_593 ,
V_593 + V_57 ) ;
F_19 ( V_35 , V_2 ) ;
V_29 = F_10 ( V_35 -> V_37 , V_2 ) ;
if ( V_29 ) {
F_464 ( V_2 ) ;
F_6 ( V_2 ) ;
return V_29 ;
}
V_29 = F_248 ( V_35 -> V_37 , V_2 -> V_7 , V_57 , V_282 ,
& V_2 -> V_104 ) ;
if ( V_29 ) {
F_464 ( V_2 ) ;
F_11 ( & V_35 -> V_37 -> V_18 ) ;
F_175 ( & V_2 -> V_20 ,
& V_35 -> V_37 -> V_19 ) ;
F_13 ( & V_35 -> V_37 -> V_18 ) ;
F_6 ( V_2 ) ;
return V_29 ;
}
F_320 ( V_35 -> V_37 ) ;
F_11 ( & V_2 -> V_104 -> V_52 ) ;
V_2 -> V_104 -> V_295 += V_2 -> V_46 ;
F_13 ( & V_2 -> V_104 -> V_52 ) ;
F_467 ( V_2 -> V_104 , V_2 ) ;
F_62 ( & V_2 -> V_591 , & V_109 -> V_245 ) ;
F_253 ( V_63 -> V_37 , type ) ;
return 0 ;
}
static void F_481 ( struct V_12 * V_37 , T_2 V_7 )
{
T_2 V_303 = F_254 ( V_7 ) &
V_304 ;
F_255 ( & V_37 -> V_305 ) ;
if ( V_7 & V_301 )
V_37 -> V_306 &= ~ V_303 ;
if ( V_7 & V_307 )
V_37 -> V_308 &= ~ V_303 ;
if ( V_7 & V_309 )
V_37 -> V_310 &= ~ V_303 ;
F_256 ( & V_37 -> V_305 ) ;
}
int F_482 ( struct V_108 * V_109 ,
struct V_34 * V_35 , T_2 V_595 )
{
struct V_64 * V_65 ;
struct V_1 * V_14 ;
struct V_491 * V_213 ;
struct V_34 * V_87 = V_35 -> V_37 -> V_87 ;
struct V_68 V_21 ;
struct V_261 * V_261 ;
int V_29 ;
int V_497 ;
int V_283 ;
V_35 = V_35 -> V_37 -> V_63 ;
V_14 = F_66 ( V_35 -> V_37 , V_595 ) ;
F_30 ( ! V_14 ) ;
F_30 ( ! V_14 -> V_269 ) ;
F_19 ( V_35 , V_14 ) ;
memcpy ( & V_21 , & V_14 -> V_21 , sizeof( V_21 ) ) ;
V_497 = F_374 ( V_14 ) ;
if ( V_14 -> V_7 & ( V_284 |
V_285 |
V_286 ) )
V_283 = 2 ;
else
V_283 = 1 ;
V_213 = & V_35 -> V_37 -> V_507 ;
F_11 ( & V_213 -> V_513 ) ;
F_382 ( V_14 , V_213 ) ;
F_13 ( & V_213 -> V_513 ) ;
V_213 = & V_35 -> V_37 -> V_505 ;
F_11 ( & V_213 -> V_513 ) ;
F_382 ( V_14 , V_213 ) ;
F_13 ( & V_213 -> V_513 ) ;
V_65 = F_33 () ;
if ( ! V_65 ) {
V_29 = - V_72 ;
goto V_73;
}
V_261 = F_231 ( V_87 , V_14 , V_65 ) ;
if ( ! F_232 ( V_261 ) ) {
V_29 = F_483 ( V_109 , V_261 ) ;
if ( V_29 ) {
F_484 ( V_261 ) ;
goto V_73;
}
F_485 ( V_261 ) ;
F_11 ( & V_14 -> V_52 ) ;
if ( V_14 -> V_162 ) {
V_14 -> V_162 = 0 ;
V_14 -> V_261 = NULL ;
F_13 ( & V_14 -> V_52 ) ;
F_244 ( V_261 ) ;
} else {
F_13 ( & V_14 -> V_52 ) ;
}
F_484 ( V_261 ) ;
}
V_21 . V_22 = V_596 ;
V_21 . V_33 = V_14 -> V_21 . V_22 ;
V_21 . type = 0 ;
V_29 = F_37 ( V_109 , V_87 , & V_21 , V_65 , - 1 , 1 ) ;
if ( V_29 < 0 )
goto V_73;
if ( V_29 > 0 )
F_43 ( V_65 ) ;
if ( V_29 == 0 ) {
V_29 = F_114 ( V_109 , V_87 , V_65 ) ;
if ( V_29 )
goto V_73;
F_43 ( V_65 ) ;
}
F_11 ( & V_35 -> V_37 -> V_18 ) ;
F_175 ( & V_14 -> V_20 ,
& V_35 -> V_37 -> V_19 ) ;
if ( V_35 -> V_37 -> V_26 == V_14 -> V_21 . V_22 )
V_35 -> V_37 -> V_26 = ( T_2 ) - 1 ;
F_13 ( & V_35 -> V_37 -> V_18 ) ;
F_61 ( & V_14 -> V_104 -> V_292 ) ;
F_171 ( & V_14 -> V_91 ) ;
if ( F_165 ( & V_14 -> V_104 -> V_291 [ V_497 ] ) )
F_481 ( V_35 -> V_37 , V_14 -> V_7 ) ;
F_63 ( & V_14 -> V_104 -> V_292 ) ;
if ( V_14 -> V_3 == V_53 )
F_372 ( V_14 ) ;
F_464 ( V_14 ) ;
F_11 ( & V_14 -> V_104 -> V_52 ) ;
V_14 -> V_104 -> V_281 -= V_14 -> V_21 . V_33 ;
V_14 -> V_104 -> V_295 -= V_14 -> V_21 . V_33 ;
V_14 -> V_104 -> V_287 -= V_14 -> V_21 . V_33 * V_283 ;
F_13 ( & V_14 -> V_104 -> V_52 ) ;
memcpy ( & V_21 , & V_14 -> V_21 , sizeof( V_21 ) ) ;
F_71 ( V_35 -> V_37 ) ;
F_6 ( V_14 ) ;
F_6 ( V_14 ) ;
V_29 = F_37 ( V_109 , V_35 , & V_21 , V_65 , - 1 , 1 ) ;
if ( V_29 > 0 )
V_29 = - V_173 ;
if ( V_29 < 0 )
goto V_73;
V_29 = F_114 ( V_109 , V_35 , V_65 ) ;
V_73:
F_49 ( V_65 ) ;
return V_29 ;
}
int F_486 ( struct V_12 * V_37 )
{
struct V_101 * V_104 ;
struct V_597 * V_598 ;
T_2 V_599 ;
T_2 V_7 ;
int V_600 = 0 ;
int V_29 ;
V_598 = V_37 -> V_348 ;
if ( ! F_487 ( V_598 ) )
return 1 ;
V_599 = F_488 ( V_598 ) ;
if ( V_599 & V_601 )
V_600 = 1 ;
V_7 = V_309 ;
V_29 = F_248 ( V_37 , V_7 , 0 , 0 , & V_104 ) ;
if ( V_29 )
goto V_73;
if ( V_600 ) {
V_7 = V_307 | V_301 ;
V_29 = F_248 ( V_37 , V_7 , 0 , 0 , & V_104 ) ;
} else {
V_7 = V_307 ;
V_29 = F_248 ( V_37 , V_7 , 0 , 0 , & V_104 ) ;
if ( V_29 )
goto V_73;
V_7 = V_301 ;
V_29 = F_248 ( V_37 , V_7 , 0 , 0 , & V_104 ) ;
}
V_73:
return V_29 ;
}
int F_489 ( struct V_34 * V_35 , T_2 V_32 , T_2 V_31 )
{
return F_357 ( V_35 , V_32 , V_31 ) ;
}
int F_490 ( struct V_34 * V_35 , T_2 V_27 ,
T_2 V_36 , T_2 * V_185 )
{
return F_140 ( V_35 , V_27 , V_36 , V_185 ) ;
}
int F_491 ( struct V_34 * V_35 , struct V_602 * V_603 )
{
struct V_12 * V_37 = V_35 -> V_37 ;
struct V_1 * V_2 = NULL ;
T_2 V_604 ;
T_2 V_32 ;
T_2 V_31 ;
T_2 V_605 = 0 ;
T_2 V_281 = F_275 ( V_37 -> V_348 ) ;
int V_29 = 0 ;
if ( V_603 -> V_49 == V_281 )
V_2 = F_65 ( V_37 , V_603 -> V_32 ) ;
else
V_2 = F_66 ( V_37 , V_603 -> V_32 ) ;
while ( V_2 ) {
if ( V_2 -> V_21 . V_22 >= ( V_603 -> V_32 + V_603 -> V_49 ) ) {
F_6 ( V_2 ) ;
break;
}
V_32 = F_378 ( V_603 -> V_32 , V_2 -> V_21 . V_22 ) ;
V_31 = F_293 ( V_603 -> V_32 + V_603 -> V_49 ,
V_2 -> V_21 . V_22 + V_2 -> V_21 . V_33 ) ;
if ( V_31 - V_32 >= V_603 -> V_606 ) {
if ( ! F_1 ( V_2 ) ) {
V_29 = F_50 ( V_2 , 0 ) ;
if ( V_29 ) {
F_6 ( V_2 ) ;
break;
}
V_29 = F_372 ( V_2 ) ;
if ( V_29 ) {
F_6 ( V_2 ) ;
break;
}
}
V_29 = F_492 ( V_2 ,
& V_604 ,
V_32 ,
V_31 ,
V_603 -> V_606 ) ;
V_605 += V_604 ;
if ( V_29 ) {
F_6 ( V_2 ) ;
break;
}
}
V_2 = F_229 ( V_37 -> V_87 , V_2 ) ;
}
V_603 -> V_49 = V_605 ;
return V_29 ;
}
