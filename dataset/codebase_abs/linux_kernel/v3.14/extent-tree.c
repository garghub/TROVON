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
V_54 -> V_62 . V_92 = F_31 ;
F_11 ( & V_2 -> V_52 ) ;
while ( V_2 -> V_3 == V_93 ) {
struct V_50 * V_51 ;
V_51 = V_2 -> V_54 ;
F_5 ( & V_51 -> V_8 ) ;
F_58 ( & V_51 -> V_89 , & V_89 , V_94 ) ;
F_13 ( & V_2 -> V_52 ) ;
F_59 () ;
F_60 ( & V_51 -> V_89 , & V_89 ) ;
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
V_29 = F_61 ( V_37 , V_2 ) ;
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
F_62 ( & V_37 -> V_80 ) ;
F_5 ( & V_54 -> V_8 ) ;
F_63 ( & V_54 -> V_91 , & V_37 -> V_99 ) ;
F_64 ( & V_37 -> V_80 ) ;
F_4 ( V_2 ) ;
F_65 ( & V_37 -> V_100 , & V_54 -> V_62 ) ;
return V_29 ;
}
static struct V_1 *
F_66 ( struct V_12 * V_13 , T_2 V_27 )
{
struct V_1 * V_2 ;
V_2 = F_16 ( V_13 , V_27 , 0 ) ;
return V_2 ;
}
struct V_1 * F_67 (
struct V_12 * V_13 ,
T_2 V_27 )
{
struct V_1 * V_2 ;
V_2 = F_16 ( V_13 , V_27 , 1 ) ;
return V_2 ;
}
static struct V_101 * F_68 ( struct V_12 * V_13 ,
T_2 V_7 )
{
struct V_102 * V_103 = & V_13 -> V_104 ;
struct V_101 * V_105 ;
V_7 &= V_106 ;
F_69 () ;
F_70 (found, head, list) {
if ( V_105 -> V_7 & V_7 ) {
F_71 () ;
return V_105 ;
}
}
F_71 () ;
return NULL ;
}
void F_72 ( struct V_12 * V_13 )
{
struct V_102 * V_103 = & V_13 -> V_104 ;
struct V_101 * V_105 ;
F_69 () ;
F_70 (found, head, list)
V_105 -> V_107 = 0 ;
F_71 () ;
}
int F_73 ( struct V_34 * V_35 , T_2 V_32 , T_2 V_49 )
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
F_50 ( V_65 ) ;
return V_29 ;
}
int F_74 ( struct V_108 * V_109 ,
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
if ( V_110 && ! F_75 ( V_35 -> V_37 , V_120 ) ) {
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
F_44 ( V_65 ) ;
goto V_78;
}
}
if ( V_29 == 0 ) {
V_67 = V_65 -> V_83 [ 0 ] ;
V_117 = F_76 ( V_67 , V_65 -> V_84 [ 0 ] ) ;
if ( V_117 >= sizeof( * V_116 ) ) {
V_116 = F_77 ( V_67 , V_65 -> V_84 [ 0 ] ,
struct V_115 ) ;
V_118 = F_78 ( V_67 , V_116 ) ;
V_119 = F_79 ( V_67 , V_116 ) ;
} else {
#ifdef F_80
struct V_123 * V_124 ;
F_30 ( V_117 != sizeof( * V_124 ) ) ;
V_124 = F_77 ( V_67 , V_65 -> V_84 [ 0 ] ,
struct V_123 ) ;
V_118 = F_81 ( V_67 , V_124 ) ;
V_119 = V_125 ;
#else
F_82 () ;
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
V_103 = F_83 ( V_109 , V_27 ) ;
if ( V_103 ) {
if ( ! F_84 ( & V_103 -> V_79 ) ) {
F_5 ( & V_103 -> V_127 . V_111 ) ;
F_13 ( & V_114 -> V_52 ) ;
F_44 ( V_65 ) ;
F_35 ( & V_103 -> V_79 ) ;
F_46 ( & V_103 -> V_79 ) ;
F_85 ( & V_103 -> V_127 ) ;
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
static int F_86 ( struct V_108 * V_109 ,
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
F_30 ( F_76 ( V_67 , V_65 -> V_84 [ 0 ] ) != sizeof( * V_124 ) ) ;
F_40 ( V_67 , & V_21 , V_65 -> V_84 [ 0 ] ) ;
V_124 = F_77 ( V_67 , V_65 -> V_84 [ 0 ] ,
struct V_123 ) ;
V_111 = F_81 ( V_67 , V_124 ) ;
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
V_136 = F_77 ( V_67 , V_65 -> V_84 [ 0 ] ,
struct V_135 ) ;
V_132 = F_87 ( V_67 , V_136 ) ;
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
F_88 ( V_35 , V_65 , V_140 ) ;
V_67 = V_65 -> V_83 [ 0 ] ;
V_134 = F_77 ( V_67 , V_65 -> V_84 [ 0 ] , struct V_115 ) ;
F_89 ( V_67 , V_134 , V_111 ) ;
F_90 ( V_67 , V_134 , 0 ) ;
if ( V_132 < V_142 ) {
F_91 ( V_67 , V_134 ,
V_143 |
V_125 ) ;
V_138 = (struct V_137 * ) ( V_134 + 1 ) ;
F_92 ( V_67 , 0 , ( unsigned long ) V_138 , sizeof( * V_138 ) ) ;
F_93 ( V_67 , V_138 , ( int ) V_132 ) ;
} else {
F_91 ( V_67 , V_134 , V_144 ) ;
}
F_94 ( V_67 ) ;
return 0 ;
}
static T_2 F_95 ( T_2 V_145 , T_2 V_132 , T_2 V_33 )
{
T_3 V_146 = ~ ( T_3 ) 0 ;
T_3 V_147 = ~ ( T_3 ) 0 ;
T_4 V_148 ;
V_148 = F_96 ( V_145 ) ;
V_146 = F_97 ( V_146 , & V_148 , sizeof( V_148 ) ) ;
V_148 = F_96 ( V_132 ) ;
V_147 = F_97 ( V_147 , & V_148 , sizeof( V_148 ) ) ;
V_148 = F_96 ( V_33 ) ;
V_147 = F_97 ( V_147 , & V_148 , sizeof( V_148 ) ) ;
return ( ( T_2 ) V_146 << 31 ) ^ ( T_2 ) V_147 ;
}
static T_2 F_98 ( struct V_66 * V_67 ,
struct V_149 * V_150 )
{
return F_95 ( F_99 ( V_67 , V_150 ) ,
F_100 ( V_67 , V_150 ) ,
F_101 ( V_67 , V_150 ) ) ;
}
static int F_102 ( struct V_66 * V_67 ,
struct V_149 * V_150 ,
T_2 V_145 , T_2 V_132 , T_2 V_33 )
{
if ( F_99 ( V_67 , V_150 ) != V_145 ||
F_100 ( V_67 , V_150 ) != V_132 ||
F_101 ( V_67 , V_150 ) != V_33 )
return 0 ;
return 1 ;
}
static T_1 int F_103 ( struct V_108 * V_109 ,
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
V_21 . V_33 = F_95 ( V_145 ,
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
#ifdef F_80
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
V_150 = F_77 ( V_67 , V_65 -> V_84 [ 0 ] ,
struct V_149 ) ;
if ( F_102 ( V_67 , V_150 , V_145 ,
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
static T_1 int F_104 ( struct V_108 * V_109 ,
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
V_21 . V_33 = F_95 ( V_145 ,
V_132 , V_33 ) ;
V_57 = sizeof( struct V_149 ) ;
}
V_29 = F_105 ( V_109 , V_35 , V_65 , & V_21 , V_57 ) ;
if ( V_29 && V_29 != - V_25 )
goto V_155;
V_67 = V_65 -> V_83 [ 0 ] ;
if ( V_17 ) {
struct V_157 * V_150 ;
V_150 = F_77 ( V_67 , V_65 -> V_84 [ 0 ] ,
struct V_157 ) ;
if ( V_29 == 0 ) {
F_106 ( V_67 , V_150 , V_156 ) ;
} else {
V_118 = F_107 ( V_67 , V_150 ) ;
V_118 += V_156 ;
F_106 ( V_67 , V_150 , V_118 ) ;
}
} else {
struct V_149 * V_150 ;
while ( V_29 == - V_25 ) {
V_150 = F_77 ( V_67 , V_65 -> V_84 [ 0 ] ,
struct V_149 ) ;
if ( F_102 ( V_67 , V_150 , V_145 ,
V_132 , V_33 ) )
break;
F_44 ( V_65 ) ;
V_21 . V_33 ++ ;
V_29 = F_105 ( V_109 , V_35 , V_65 , & V_21 ,
V_57 ) ;
if ( V_29 && V_29 != - V_25 )
goto V_155;
V_67 = V_65 -> V_83 [ 0 ] ;
}
V_150 = F_77 ( V_67 , V_65 -> V_84 [ 0 ] ,
struct V_149 ) ;
if ( V_29 == 0 ) {
F_108 ( V_67 , V_150 ,
V_145 ) ;
F_109 ( V_67 , V_150 , V_132 ) ;
F_110 ( V_67 , V_150 , V_33 ) ;
F_111 ( V_67 , V_150 , V_156 ) ;
} else {
V_118 = F_112 ( V_67 , V_150 ) ;
V_118 += V_156 ;
F_111 ( V_67 , V_150 , V_118 ) ;
}
}
F_94 ( V_67 ) ;
V_29 = 0 ;
V_155:
F_44 ( V_65 ) ;
return V_29 ;
}
static T_1 int F_113 ( struct V_108 * V_109 ,
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
V_159 = F_77 ( V_67 , V_65 -> V_84 [ 0 ] ,
struct V_149 ) ;
V_118 = F_112 ( V_67 , V_159 ) ;
} else if ( V_21 . type == V_153 ) {
V_160 = F_77 ( V_67 , V_65 -> V_84 [ 0 ] ,
struct V_157 ) ;
V_118 = F_107 ( V_67 , V_160 ) ;
#ifdef F_80
} else if ( V_21 . type == V_141 ) {
struct V_135 * V_136 ;
V_136 = F_77 ( V_67 , V_65 -> V_84 [ 0 ] ,
struct V_135 ) ;
V_118 = F_114 ( V_67 , V_136 ) ;
#endif
} else {
F_82 () ;
}
F_30 ( V_118 < V_158 ) ;
V_118 -= V_158 ;
if ( V_118 == 0 ) {
V_29 = F_115 ( V_109 , V_35 , V_65 ) ;
} else {
if ( V_21 . type == V_154 )
F_111 ( V_67 , V_159 , V_118 ) ;
else if ( V_21 . type == V_153 )
F_106 ( V_67 , V_160 , V_118 ) ;
#ifdef F_80
else {
struct V_135 * V_136 ;
V_136 = F_77 ( V_67 , V_65 -> V_84 [ 0 ] ,
struct V_135 ) ;
F_116 ( V_67 , V_136 , V_118 ) ;
}
#endif
F_94 ( V_67 ) ;
}
return V_29 ;
}
static T_1 T_3 F_117 ( struct V_34 * V_35 ,
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
if ( F_118 ( V_67 , V_162 ) ==
V_154 ) {
V_159 = (struct V_149 * ) ( & V_162 -> V_33 ) ;
V_118 = F_112 ( V_67 , V_159 ) ;
} else {
V_160 = (struct V_157 * ) ( V_162 + 1 ) ;
V_118 = F_107 ( V_67 , V_160 ) ;
}
} else if ( V_21 . type == V_154 ) {
V_159 = F_77 ( V_67 , V_65 -> V_84 [ 0 ] ,
struct V_149 ) ;
V_118 = F_112 ( V_67 , V_159 ) ;
} else if ( V_21 . type == V_153 ) {
V_160 = F_77 ( V_67 , V_65 -> V_84 [ 0 ] ,
struct V_157 ) ;
V_118 = F_107 ( V_67 , V_160 ) ;
#ifdef F_80
} else if ( V_21 . type == V_141 ) {
struct V_135 * V_136 ;
V_136 = F_77 ( V_67 , V_65 -> V_84 [ 0 ] ,
struct V_135 ) ;
V_118 = F_114 ( V_67 , V_136 ) ;
#endif
} else {
F_8 ( 1 ) ;
}
return V_118 ;
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
V_29 = F_37 ( V_109 , V_35 , & V_21 , V_65 , - 1 , 1 ) ;
if ( V_29 > 0 )
V_29 = - V_152 ;
#ifdef F_80
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
V_21 . type = V_163 ;
V_21 . V_33 = V_17 ;
} else {
V_21 . type = V_164 ;
V_21 . V_33 = V_145 ;
}
V_29 = F_105 ( V_109 , V_35 , V_65 , & V_21 , 0 ) ;
F_44 ( V_65 ) ;
return V_29 ;
}
static inline int F_121 ( T_2 V_17 , T_2 V_132 )
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
F_122 ( V_65 -> V_83 [ V_165 ] , V_21 ,
V_65 -> V_84 [ V_165 ] + 1 ) ;
return 0 ;
}
return 1 ;
}
static T_5
int F_123 ( struct V_108 * V_109 ,
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
bool V_171 = F_75 ( V_35 -> V_37 ,
V_120 ) ;
V_21 . V_22 = V_27 ;
V_21 . type = V_77 ;
V_21 . V_33 = V_36 ;
V_170 = F_121 ( V_17 , V_132 ) ;
if ( V_168 ) {
V_133 = F_124 ( V_170 ) ;
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
F_44 ( V_65 ) ;
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
V_117 = F_76 ( V_67 , V_65 -> V_84 [ 0 ] ) ;
#ifdef F_80
if ( V_117 < sizeof( * V_116 ) ) {
if ( ! V_168 ) {
V_82 = - V_152 ;
goto V_73;
}
V_29 = F_86 ( V_109 , V_35 , V_65 , V_132 ,
V_133 ) ;
if ( V_29 < 0 ) {
V_82 = V_29 ;
goto V_73;
}
V_67 = V_65 -> V_83 [ 0 ] ;
V_117 = F_76 ( V_67 , V_65 -> V_84 [ 0 ] ) ;
}
#endif
F_30 ( V_117 < sizeof( * V_116 ) ) ;
V_116 = F_77 ( V_67 , V_65 -> V_84 [ 0 ] , struct V_115 ) ;
V_7 = F_79 ( V_67 , V_116 ) ;
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
type = F_118 ( V_67 , V_162 ) ;
if ( V_170 < type )
break;
if ( V_170 > type ) {
V_169 += F_124 ( type ) ;
continue;
}
if ( type == V_154 ) {
struct V_149 * V_174 ;
V_174 = (struct V_149 * ) ( & V_162 -> V_33 ) ;
if ( F_102 ( V_67 , V_174 , V_145 ,
V_132 , V_33 ) ) {
V_82 = 0 ;
break;
}
if ( F_98 ( V_67 , V_174 ) <
F_95 ( V_145 , V_132 , V_33 ) )
break;
} else {
T_2 V_175 ;
V_175 = F_125 ( V_67 , V_162 ) ;
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
V_169 += F_124 ( type ) ;
}
if ( V_82 == - V_152 && V_168 ) {
if ( V_117 + V_133 >=
F_126 ( V_35 ) ) {
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
F_127 ( V_65 , 1 ) ;
}
return V_82 ;
}
static T_5
void F_128 ( struct V_34 * V_35 ,
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
V_116 = F_77 ( V_67 , V_65 -> V_84 [ 0 ] , struct V_115 ) ;
V_179 = ( unsigned long ) V_162 - ( unsigned long ) V_116 ;
type = F_121 ( V_17 , V_132 ) ;
V_57 = F_124 ( type ) ;
F_88 ( V_35 , V_65 , V_57 ) ;
V_116 = F_77 ( V_67 , V_65 -> V_84 [ 0 ] , struct V_115 ) ;
V_111 = F_78 ( V_67 , V_116 ) ;
V_111 += V_156 ;
F_89 ( V_67 , V_116 , V_111 ) ;
if ( V_128 )
F_129 ( V_128 , V_67 , V_116 ) ;
V_169 = ( unsigned long ) V_116 + V_179 ;
V_31 = ( unsigned long ) V_116 + F_76 ( V_67 , V_65 -> V_84 [ 0 ] ) ;
if ( V_169 < V_31 - V_57 )
F_130 ( V_67 , V_169 + V_57 , V_169 ,
V_31 - V_57 - V_169 ) ;
V_162 = (struct V_161 * ) V_169 ;
F_131 ( V_67 , V_162 , type ) ;
if ( type == V_154 ) {
struct V_149 * V_174 ;
V_174 = (struct V_149 * ) ( & V_162 -> V_33 ) ;
F_108 ( V_67 , V_174 , V_145 ) ;
F_109 ( V_67 , V_174 , V_132 ) ;
F_110 ( V_67 , V_174 , V_33 ) ;
F_111 ( V_67 , V_174 , V_156 ) ;
} else if ( type == V_153 ) {
struct V_157 * V_180 ;
V_180 = (struct V_157 * ) ( V_162 + 1 ) ;
F_106 ( V_67 , V_180 , V_156 ) ;
F_132 ( V_67 , V_162 , V_17 ) ;
} else if ( type == V_163 ) {
F_132 ( V_67 , V_162 , V_17 ) ;
} else {
F_132 ( V_67 , V_162 , V_145 ) ;
}
F_94 ( V_67 ) ;
}
static int F_133 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
struct V_64 * V_65 ,
struct V_161 * * V_167 ,
T_2 V_27 , T_2 V_36 , T_2 V_17 ,
T_2 V_145 , T_2 V_132 , T_2 V_33 )
{
int V_29 ;
V_29 = F_123 ( V_109 , V_35 , V_65 , V_167 ,
V_27 , V_36 , V_17 ,
V_145 , V_132 , V_33 , 0 ) ;
if ( V_29 != - V_152 )
return V_29 ;
F_44 ( V_65 ) ;
* V_167 = NULL ;
if ( V_132 < V_142 ) {
V_29 = F_119 ( V_109 , V_35 , V_65 , V_27 , V_17 ,
V_145 ) ;
} else {
V_29 = F_103 ( V_109 , V_35 , V_65 , V_27 , V_17 ,
V_145 , V_132 , V_33 ) ;
}
return V_29 ;
}
static T_5
void F_134 ( struct V_34 * V_35 ,
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
V_116 = F_77 ( V_67 , V_65 -> V_84 [ 0 ] , struct V_115 ) ;
V_111 = F_78 ( V_67 , V_116 ) ;
F_8 ( V_181 < 0 && V_111 + V_181 <= 0 ) ;
V_111 += V_181 ;
F_89 ( V_67 , V_116 , V_111 ) ;
if ( V_128 )
F_129 ( V_128 , V_67 , V_116 ) ;
type = F_118 ( V_67 , V_162 ) ;
if ( type == V_154 ) {
V_174 = (struct V_149 * ) ( & V_162 -> V_33 ) ;
V_111 = F_112 ( V_67 , V_174 ) ;
} else if ( type == V_153 ) {
V_180 = (struct V_157 * ) ( V_162 + 1 ) ;
V_111 = F_107 ( V_67 , V_180 ) ;
} else {
V_111 = 1 ;
F_30 ( V_181 != - 1 ) ;
}
F_30 ( V_181 < 0 && V_111 < - V_181 ) ;
V_111 += V_181 ;
if ( V_111 > 0 ) {
if ( type == V_154 )
F_111 ( V_67 , V_174 , V_111 ) ;
else
F_106 ( V_67 , V_180 , V_111 ) ;
} else {
V_57 = F_124 ( type ) ;
V_117 = F_76 ( V_67 , V_65 -> V_84 [ 0 ] ) ;
V_169 = ( unsigned long ) V_162 ;
V_31 = ( unsigned long ) V_116 + V_117 ;
if ( V_169 + V_57 < V_31 )
F_130 ( V_67 , V_169 , V_169 + V_57 ,
V_31 - V_169 - V_57 ) ;
V_117 -= V_57 ;
F_135 ( V_35 , V_65 , V_117 , 1 ) ;
}
F_94 ( V_67 ) ;
}
static T_5
int F_136 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
struct V_64 * V_65 ,
T_2 V_27 , T_2 V_36 , T_2 V_17 ,
T_2 V_145 , T_2 V_132 ,
T_2 V_33 , int V_156 ,
struct V_178 * V_128 )
{
struct V_161 * V_162 ;
int V_29 ;
V_29 = F_123 ( V_109 , V_35 , V_65 , & V_162 ,
V_27 , V_36 , V_17 ,
V_145 , V_132 , V_33 , 1 ) ;
if ( V_29 == 0 ) {
F_30 ( V_132 < V_142 ) ;
F_134 ( V_35 , V_65 , V_162 ,
V_156 , V_128 ) ;
} else if ( V_29 == - V_152 ) {
F_128 ( V_35 , V_65 , V_162 , V_17 ,
V_145 , V_132 , V_33 ,
V_156 , V_128 ) ;
V_29 = 0 ;
}
return V_29 ;
}
static int F_137 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
struct V_64 * V_65 ,
T_2 V_27 , T_2 V_17 , T_2 V_145 ,
T_2 V_132 , T_2 V_33 , int V_156 )
{
int V_29 ;
if ( V_132 < V_142 ) {
F_30 ( V_156 != 1 ) ;
V_29 = F_120 ( V_109 , V_35 , V_65 , V_27 ,
V_17 , V_145 ) ;
} else {
V_29 = F_104 ( V_109 , V_35 , V_65 , V_27 ,
V_17 , V_145 ,
V_132 , V_33 , V_156 ) ;
}
return V_29 ;
}
static int F_138 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
struct V_64 * V_65 ,
struct V_161 * V_162 ,
int V_158 , int V_182 )
{
int V_29 = 0 ;
F_30 ( ! V_182 && V_158 != 1 ) ;
if ( V_162 ) {
F_134 ( V_35 , V_65 , V_162 ,
- V_158 , NULL ) ;
} else if ( V_182 ) {
V_29 = F_113 ( V_109 , V_35 , V_65 , V_158 ) ;
} else {
V_29 = F_115 ( V_109 , V_35 , V_65 ) ;
}
return V_29 ;
}
static int F_139 ( struct V_183 * V_184 ,
T_2 V_32 , T_2 V_49 )
{
return F_140 ( V_184 , V_32 >> 9 , V_49 >> 9 , V_40 , 0 ) ;
}
static int F_141 ( struct V_34 * V_35 , T_2 V_27 ,
T_2 V_36 , T_2 * V_185 )
{
int V_29 ;
T_2 V_186 = 0 ;
struct V_187 * V_188 = NULL ;
V_29 = F_142 ( V_35 -> V_37 , V_189 ,
V_27 , & V_36 , & V_188 , 0 ) ;
if ( ! V_29 ) {
struct V_190 * V_191 = V_188 -> V_192 ;
int V_43 ;
for ( V_43 = 0 ; V_43 < V_188 -> V_193 ; V_43 ++ , V_191 ++ ) {
if ( ! V_191 -> V_194 -> V_195 )
continue;
V_29 = F_139 ( V_191 -> V_194 -> V_184 ,
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
int F_143 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
T_2 V_27 , T_2 V_36 , T_2 V_17 ,
T_2 V_145 , T_2 V_132 , T_2 V_33 , int V_199 )
{
int V_29 ;
struct V_12 * V_37 = V_35 -> V_37 ;
F_30 ( V_132 < V_142 &&
V_145 == V_200 ) ;
if ( V_132 < V_142 ) {
V_29 = F_144 ( V_37 , V_109 , V_27 ,
V_36 ,
V_17 , V_145 , ( int ) V_132 ,
V_201 , NULL , V_199 ) ;
} else {
V_29 = F_145 ( V_37 , V_109 , V_27 ,
V_36 ,
V_17 , V_145 , V_132 , V_33 ,
V_201 , NULL , V_199 ) ;
}
return V_29 ;
}
static int F_146 ( struct V_108 * V_109 ,
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
V_29 = F_136 ( V_109 , V_35 -> V_37 -> V_63 ,
V_65 , V_27 , V_36 , V_17 ,
V_145 , V_132 , V_33 ,
V_156 , V_128 ) ;
if ( V_29 != - V_176 )
goto V_73;
V_67 = V_65 -> V_83 [ 0 ] ;
V_134 = F_77 ( V_67 , V_65 -> V_84 [ 0 ] , struct V_115 ) ;
V_111 = F_78 ( V_67 , V_134 ) ;
F_89 ( V_67 , V_134 , V_111 + V_156 ) ;
if ( V_128 )
F_129 ( V_128 , V_67 , V_134 ) ;
F_94 ( V_67 ) ;
F_44 ( V_65 ) ;
V_65 -> V_76 = 1 ;
V_65 -> V_202 = 1 ;
V_29 = F_137 ( V_109 , V_35 -> V_37 -> V_63 ,
V_65 , V_27 , V_17 , V_145 ,
V_132 , V_33 , V_156 ) ;
if ( V_29 )
F_147 ( V_109 , V_35 , V_29 ) ;
V_73:
F_50 ( V_65 ) ;
return V_29 ;
}
static int F_148 ( struct V_108 * V_109 ,
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
V_150 = F_149 ( V_127 ) ;
F_150 ( V_127 , V_150 , V_127 -> V_208 ) ;
if ( V_127 -> type == V_153 )
V_17 = V_150 -> V_17 ;
else
V_207 = V_150 -> V_35 ;
if ( V_127 -> V_208 == V_201 && V_204 ) {
if ( V_128 )
V_7 |= V_128 -> V_130 ;
V_29 = F_151 ( V_109 , V_35 ,
V_17 , V_207 , V_7 ,
V_150 -> V_22 , V_150 -> V_33 ,
& V_206 , V_127 -> V_131 ) ;
} else if ( V_127 -> V_208 == V_201 ) {
V_29 = F_146 ( V_109 , V_35 , V_127 -> V_27 ,
V_127 -> V_36 , V_17 ,
V_207 , V_150 -> V_22 ,
V_150 -> V_33 , V_127 -> V_131 ,
V_128 ) ;
} else if ( V_127 -> V_208 == V_209 ) {
V_29 = F_152 ( V_109 , V_35 , V_127 -> V_27 ,
V_127 -> V_36 , V_17 ,
V_207 , V_150 -> V_22 ,
V_150 -> V_33 , V_127 -> V_131 ,
V_128 ) ;
} else {
F_82 () ;
}
return V_29 ;
}
static void F_129 ( struct V_178 * V_128 ,
struct V_66 * V_67 ,
struct V_115 * V_116 )
{
T_2 V_7 = F_79 ( V_67 , V_116 ) ;
if ( V_128 -> V_129 ) {
V_7 |= V_128 -> V_130 ;
F_91 ( V_67 , V_116 , V_7 ) ;
}
if ( V_128 -> V_210 ) {
struct V_137 * V_138 ;
F_30 ( ! ( V_7 & V_143 ) ) ;
V_138 = (struct V_137 * ) ( V_116 + 1 ) ;
F_153 ( V_67 , V_138 , & V_128 -> V_21 ) ;
}
}
static int F_154 ( struct V_108 * V_109 ,
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
if ( V_110 && ! F_75 ( V_35 -> V_37 , V_120 ) )
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
F_44 ( V_65 ) ;
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
V_117 = F_76 ( V_67 , V_65 -> V_84 [ 0 ] ) ;
#ifdef F_80
if ( V_117 < sizeof( * V_116 ) ) {
V_29 = F_86 ( V_109 , V_35 -> V_37 -> V_63 ,
V_65 , ( T_2 ) - 1 , 0 ) ;
if ( V_29 < 0 ) {
V_82 = V_29 ;
goto V_73;
}
V_67 = V_65 -> V_83 [ 0 ] ;
V_117 = F_76 ( V_67 , V_65 -> V_84 [ 0 ] ) ;
}
#endif
F_30 ( V_117 < sizeof( * V_116 ) ) ;
V_116 = F_77 ( V_67 , V_65 -> V_84 [ 0 ] , struct V_115 ) ;
F_129 ( V_128 , V_67 , V_116 ) ;
F_94 ( V_67 ) ;
V_73:
F_50 ( V_65 ) ;
return V_82 ;
}
static int F_155 ( struct V_108 * V_109 ,
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
bool V_171 = F_75 ( V_35 -> V_37 ,
V_120 ) ;
V_150 = F_156 ( V_127 ) ;
F_157 ( V_127 , V_150 , V_127 -> V_208 ) ;
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
V_29 = F_158 ( V_109 , V_35 ,
V_17 , V_207 ,
V_128 -> V_130 ,
& V_128 -> V_21 ,
V_150 -> V_165 , & V_206 ) ;
} else if ( V_127 -> V_208 == V_201 ) {
V_29 = F_146 ( V_109 , V_35 , V_127 -> V_27 ,
V_127 -> V_36 , V_17 , V_207 ,
V_150 -> V_165 , 0 , 1 , V_128 ) ;
} else if ( V_127 -> V_208 == V_209 ) {
V_29 = F_152 ( V_109 , V_35 , V_127 -> V_27 ,
V_127 -> V_36 , V_17 , V_207 ,
V_150 -> V_165 , 0 , 1 , V_128 ) ;
} else {
F_82 () ;
}
return V_29 ;
}
static int F_159 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
struct V_203 * V_127 ,
struct V_178 * V_128 ,
int V_204 )
{
int V_29 = 0 ;
if ( V_109 -> V_211 ) {
if ( V_204 )
F_160 ( V_35 , V_127 -> V_27 ,
V_127 -> V_36 , 1 ) ;
return 0 ;
}
if ( F_161 ( V_127 ) ) {
struct V_112 * V_103 ;
F_30 ( V_128 ) ;
V_103 = F_162 ( V_127 ) ;
F_163 ( V_127 , V_103 , V_127 -> V_208 ) ;
if ( V_204 ) {
F_160 ( V_35 , V_127 -> V_27 ,
V_127 -> V_36 , 1 ) ;
if ( V_103 -> V_182 ) {
V_29 = F_164 ( V_109 , V_35 ,
V_127 -> V_27 ,
V_127 -> V_36 ) ;
}
}
return V_29 ;
}
if ( V_127 -> type == V_164 ||
V_127 -> type == V_163 )
V_29 = F_155 ( V_109 , V_35 , V_127 , V_128 ,
V_204 ) ;
else if ( V_127 -> type == V_154 ||
V_127 -> type == V_153 )
V_29 = F_148 ( V_109 , V_35 , V_127 , V_128 ,
V_204 ) ;
else
F_82 () ;
return V_29 ;
}
T_1 int F_165 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
unsigned long V_44 )
{
struct V_113 * V_114 ;
struct V_203 * V_150 ;
struct V_112 * V_213 = NULL ;
struct V_178 * V_128 ;
struct V_12 * V_37 = V_35 -> V_37 ;
T_6 V_32 = F_166 () ;
int V_29 ;
unsigned long V_8 = 0 ;
unsigned long V_214 = 0 ;
int V_215 = 0 ;
V_114 = & V_109 -> V_126 -> V_114 ;
while ( 1 ) {
if ( ! V_213 ) {
if ( V_8 >= V_44 )
break;
F_11 ( & V_114 -> V_52 ) ;
V_213 = F_167 ( V_109 ) ;
if ( ! V_213 ) {
F_13 ( & V_114 -> V_52 ) ;
break;
}
V_29 = F_168 ( V_109 , V_213 ) ;
F_13 ( & V_114 -> V_52 ) ;
if ( V_29 == - V_176 ) {
V_213 = NULL ;
V_8 ++ ;
continue;
}
}
F_11 ( & V_213 -> V_52 ) ;
F_169 ( V_109 , V_37 , V_114 ,
V_213 ) ;
V_150 = F_170 ( V_213 ) ;
if ( V_150 && V_150 -> V_216 &&
F_171 ( V_37 , V_114 , V_150 -> V_216 ) ) {
F_13 ( & V_213 -> V_52 ) ;
F_172 ( V_213 ) ;
F_11 ( & V_114 -> V_52 ) ;
V_213 -> V_217 = 0 ;
V_114 -> V_218 ++ ;
F_13 ( & V_114 -> V_52 ) ;
V_213 = NULL ;
F_47 () ;
V_8 ++ ;
continue;
}
V_215 = V_213 -> V_215 ;
V_213 -> V_215 = 0 ;
V_128 = V_213 -> V_128 ;
V_213 -> V_128 = NULL ;
if ( ! V_150 ) {
V_150 = & V_213 -> V_127 ;
if ( V_128 && V_215 ) {
F_173 ( V_128 ) ;
V_128 = NULL ;
}
if ( V_128 ) {
F_13 ( & V_213 -> V_52 ) ;
V_29 = F_154 ( V_109 , V_35 ,
V_150 , V_128 ) ;
F_173 ( V_128 ) ;
if ( V_29 ) {
if ( V_215 )
V_213 -> V_215 = 1 ;
V_213 -> V_217 = 0 ;
F_174 ( V_37 , L_1 , V_29 ) ;
F_172 ( V_213 ) ;
return V_29 ;
}
continue;
}
F_13 ( & V_213 -> V_52 ) ;
F_11 ( & V_114 -> V_52 ) ;
F_11 ( & V_213 -> V_52 ) ;
if ( F_175 ( & V_213 -> V_207 ) ) {
F_13 ( & V_213 -> V_52 ) ;
F_13 ( & V_114 -> V_52 ) ;
continue;
}
V_150 -> V_219 = 0 ;
V_114 -> V_220 -- ;
F_176 ( & V_213 -> V_221 ,
& V_114 -> V_222 ) ;
F_13 ( & V_114 -> V_52 ) ;
} else {
V_214 ++ ;
V_150 -> V_219 = 0 ;
F_176 ( & V_150 -> V_15 , & V_213 -> V_207 ) ;
}
F_177 ( & V_114 -> V_223 ) ;
if ( ! F_161 ( V_150 ) ) {
switch ( V_150 -> V_208 ) {
case V_201 :
case V_224 :
V_213 -> V_127 . V_131 -= V_150 -> V_131 ;
break;
case V_209 :
V_213 -> V_127 . V_131 += V_150 -> V_131 ;
break;
default:
F_8 ( 1 ) ;
}
}
F_13 ( & V_213 -> V_52 ) ;
V_29 = F_159 ( V_109 , V_35 , V_150 , V_128 ,
V_215 ) ;
F_173 ( V_128 ) ;
if ( V_29 ) {
V_213 -> V_217 = 0 ;
F_172 ( V_213 ) ;
F_85 ( V_150 ) ;
F_174 ( V_37 , L_2 , V_29 ) ;
return V_29 ;
}
if ( F_161 ( V_150 ) ) {
F_172 ( V_213 ) ;
V_213 = NULL ;
}
F_85 ( V_150 ) ;
V_8 ++ ;
F_47 () ;
}
if ( V_214 > 0 ) {
T_2 V_225 = F_178 ( F_179 ( F_166 () , V_32 ) ) ;
T_2 V_226 ;
F_11 ( & V_114 -> V_52 ) ;
V_226 = V_37 -> V_227 * 3 + V_225 ;
V_226 = F_180 ( V_226 , 4 ) ;
V_37 -> V_227 = V_226 ;
F_13 ( & V_114 -> V_52 ) ;
}
return 0 ;
}
static T_2 F_181 ( struct V_228 * V_35 )
{
struct V_15 * V_30 = V_35 -> V_15 ;
struct V_203 * V_229 ;
int V_230 = 1 ;
T_2 V_231 ;
T_2 V_232 = 0 , V_70 = 0 ;
V_30 = F_175 ( V_35 ) ;
if ( V_30 ) {
V_229 = F_12 ( V_30 , struct V_203 , V_15 ) ;
V_232 = V_229 -> V_27 ;
}
V_30 = F_182 ( V_35 ) ;
if ( V_30 ) {
V_229 = F_12 ( V_30 , struct V_203 , V_15 ) ;
V_70 = V_229 -> V_27 ;
}
V_30 = V_35 -> V_15 ;
while ( V_30 ) {
V_229 = F_12 ( V_30 , struct V_203 , V_15 ) ;
F_8 ( ! V_229 -> V_219 ) ;
V_231 = V_229 -> V_27 ;
if ( V_230 )
V_30 = V_30 -> V_23 ;
else
V_30 = V_30 -> V_24 ;
V_230 = 1 - V_230 ;
}
return V_231 ;
}
int F_183 ( struct V_108 * V_109 ,
struct V_12 * V_37 )
{
struct V_233 * V_233 ;
int V_29 = 0 ;
if ( F_184 ( & V_109 -> V_234 ) !=
! V_109 -> V_235 . V_216 ) {
F_185 ( V_37 ,
L_3 ,
F_184 ( & V_109 -> V_234 ) ? L_4 : L_5 ,
( T_3 ) ( V_109 -> V_235 . V_216 >> 32 ) ,
( T_3 ) V_109 -> V_235 . V_216 ) ;
F_82 () ;
}
if ( ! V_109 -> V_235 . V_216 )
return 0 ;
while ( ! F_184 ( & V_109 -> V_234 ) ) {
V_233 = F_186 ( & V_109 -> V_234 ,
struct V_233 , V_91 ) ;
F_187 ( & V_233 -> V_91 ) ;
if ( ! V_29 )
V_29 = F_188 (
V_109 , V_37 , V_233 -> V_127 ,
V_233 -> V_128 ) ;
F_9 ( V_233 ) ;
}
F_189 ( V_37 , & V_109 -> V_235 ) ;
return V_29 ;
}
static inline T_2 F_190 ( struct V_34 * V_35 , T_2 V_236 )
{
T_2 V_36 ;
V_36 = V_236 * ( sizeof( struct V_115 ) +
sizeof( struct V_161 ) ) ;
if ( ! F_75 ( V_35 -> V_37 , V_120 ) )
V_36 += V_236 * sizeof( struct V_137 ) ;
return F_180 ( V_36 , F_191 ( V_35 ) ) ;
}
int F_192 ( struct V_108 * V_109 ,
struct V_34 * V_35 )
{
struct V_237 * V_238 ;
T_2 V_220 = V_109 -> V_126 -> V_114 . V_218 ;
T_2 V_36 ;
int V_29 = 0 ;
V_36 = F_193 ( V_35 , 1 ) ;
V_220 = F_190 ( V_35 , V_220 ) ;
if ( V_220 > 1 )
V_36 += ( V_220 - 1 ) * V_35 -> V_88 ;
V_36 <<= 1 ;
V_238 = & V_35 -> V_37 -> V_239 ;
if ( V_238 -> V_104 -> V_107 )
V_36 <<= 1 ;
F_11 ( & V_238 -> V_52 ) ;
if ( V_238 -> V_10 <= V_36 )
V_29 = 1 ;
F_13 ( & V_238 -> V_52 ) ;
return V_29 ;
}
int F_194 ( struct V_108 * V_109 ,
struct V_34 * V_35 )
{
struct V_12 * V_37 = V_35 -> V_37 ;
T_2 V_223 =
F_195 ( & V_109 -> V_126 -> V_114 . V_223 ) ;
T_2 V_240 ;
F_2 () ;
V_240 = V_37 -> V_227 ;
if ( V_223 * V_240 >= V_241 )
return 1 ;
return F_192 ( V_109 , V_35 ) ;
}
int F_196 ( struct V_108 * V_109 ,
struct V_34 * V_35 , unsigned long V_8 )
{
struct V_15 * V_127 ;
struct V_113 * V_114 ;
struct V_112 * V_103 ;
int V_29 ;
int V_242 = V_8 == ( unsigned long ) - 1 ;
int V_243 = 0 ;
if ( V_109 -> V_211 )
return 0 ;
if ( V_35 == V_35 -> V_37 -> V_63 )
V_35 = V_35 -> V_37 -> V_87 ;
F_183 ( V_109 , V_35 -> V_37 ) ;
V_114 = & V_109 -> V_126 -> V_114 ;
if ( V_8 == 0 ) {
V_8 = F_195 ( & V_114 -> V_223 ) * 2 ;
V_243 = 1 ;
}
V_78:
#ifdef F_197
V_114 -> V_244 = F_181 ( & V_114 -> V_35 ) ;
#endif
V_29 = F_165 ( V_109 , V_35 , V_8 ) ;
if ( V_29 < 0 ) {
F_147 ( V_109 , V_35 , V_29 ) ;
return V_29 ;
}
if ( V_242 ) {
if ( ! F_184 ( & V_109 -> V_245 ) )
F_198 ( V_109 , V_35 ) ;
F_11 ( & V_114 -> V_52 ) ;
V_127 = F_175 ( & V_114 -> V_222 ) ;
if ( ! V_127 ) {
F_13 ( & V_114 -> V_52 ) ;
goto V_73;
}
V_8 = ( unsigned long ) - 1 ;
while ( V_127 ) {
V_103 = F_12 ( V_127 , struct V_112 ,
V_221 ) ;
if ( F_161 ( & V_103 -> V_127 ) ) {
struct V_203 * V_150 ;
V_150 = & V_103 -> V_127 ;
F_5 ( & V_150 -> V_111 ) ;
F_13 ( & V_114 -> V_52 ) ;
F_35 ( & V_103 -> V_79 ) ;
F_46 ( & V_103 -> V_79 ) ;
F_85 ( V_150 ) ;
F_47 () ;
goto V_78;
} else {
F_8 ( 1 ) ;
}
V_127 = F_199 ( V_127 ) ;
}
F_13 ( & V_114 -> V_52 ) ;
F_47 () ;
goto V_78;
}
V_73:
F_200 ( V_109 ) ;
return 0 ;
}
int F_201 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
T_2 V_27 , T_2 V_36 , T_2 V_7 ,
int V_165 , int V_182 )
{
struct V_178 * V_128 ;
int V_29 ;
V_128 = F_202 () ;
if ( ! V_128 )
return - V_72 ;
V_128 -> V_130 = V_7 ;
V_128 -> V_129 = 1 ;
V_128 -> V_210 = 0 ;
V_128 -> V_182 = V_182 ? 1 : 0 ;
V_128 -> V_165 = V_165 ;
V_29 = F_203 ( V_35 -> V_37 , V_109 , V_27 ,
V_36 , V_128 ) ;
if ( V_29 )
F_173 ( V_128 ) ;
return V_29 ;
}
static T_1 int F_204 ( struct V_108 * V_109 ,
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
V_114 = & V_109 -> V_126 -> V_114 ;
F_11 ( & V_114 -> V_52 ) ;
V_103 = F_83 ( V_109 , V_27 ) ;
if ( ! V_103 ) {
F_13 ( & V_114 -> V_52 ) ;
return 0 ;
}
if ( ! F_84 ( & V_103 -> V_79 ) ) {
F_5 ( & V_103 -> V_127 . V_111 ) ;
F_13 ( & V_114 -> V_52 ) ;
F_44 ( V_65 ) ;
F_35 ( & V_103 -> V_79 ) ;
F_46 ( & V_103 -> V_79 ) ;
F_85 ( & V_103 -> V_127 ) ;
return - V_176 ;
}
F_13 ( & V_114 -> V_52 ) ;
F_11 ( & V_103 -> V_52 ) ;
V_127 = F_175 ( & V_103 -> V_207 ) ;
while ( V_127 ) {
V_150 = F_12 ( V_127 , struct V_203 , V_15 ) ;
V_127 = F_199 ( V_127 ) ;
if ( V_150 -> type != V_154 ) {
V_29 = 1 ;
break;
}
V_246 = F_149 ( V_150 ) ;
if ( V_246 -> V_35 != V_35 -> V_247 . V_22 ||
V_246 -> V_22 != V_22 ||
V_246 -> V_33 != V_33 ) {
V_29 = 1 ;
break;
}
}
F_13 ( & V_103 -> V_52 ) ;
F_46 ( & V_103 -> V_79 ) ;
return V_29 ;
}
static T_1 int F_205 ( struct V_108 * V_109 ,
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
V_117 = F_76 ( V_67 , V_65 -> V_84 [ 0 ] ) ;
#ifdef F_80
if ( V_117 < sizeof( * V_116 ) ) {
F_8 ( V_117 != sizeof( struct V_123 ) ) ;
goto V_73;
}
#endif
V_116 = F_77 ( V_67 , V_65 -> V_84 [ 0 ] , struct V_115 ) ;
if ( V_117 != sizeof( * V_116 ) +
F_124 ( V_154 ) )
goto V_73;
if ( F_206 ( V_67 , V_116 ) <=
F_207 ( & V_35 -> V_248 ) )
goto V_73;
V_162 = (struct V_161 * ) ( V_116 + 1 ) ;
if ( F_118 ( V_67 , V_162 ) !=
V_154 )
goto V_73;
V_150 = (struct V_149 * ) ( & V_162 -> V_33 ) ;
if ( F_78 ( V_67 , V_116 ) !=
F_112 ( V_67 , V_150 ) ||
F_99 ( V_67 , V_150 ) !=
V_35 -> V_247 . V_22 ||
F_100 ( V_67 , V_150 ) != V_22 ||
F_101 ( V_67 , V_150 ) != V_33 )
goto V_73;
V_29 = 0 ;
V_73:
return V_29 ;
}
int F_208 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
T_2 V_22 , T_2 V_33 , T_2 V_27 )
{
struct V_64 * V_65 ;
int V_29 ;
int V_249 ;
V_65 = F_33 () ;
if ( ! V_65 )
return - V_152 ;
do {
V_29 = F_205 ( V_109 , V_35 , V_65 , V_22 ,
V_33 , V_27 ) ;
if ( V_29 && V_29 != - V_152 )
goto V_73;
V_249 = F_204 ( V_109 , V_35 , V_65 , V_22 ,
V_33 , V_27 ) ;
} while ( V_249 == - V_176 );
if ( V_249 && V_249 != - V_152 ) {
V_29 = V_249 ;
goto V_73;
}
if ( V_29 != - V_152 || V_249 != - V_152 )
V_29 = 0 ;
V_73:
F_50 ( V_65 ) ;
if ( V_35 -> V_247 . V_22 == V_250 )
F_8 ( V_29 > 0 ) ;
return V_29 ;
}
static int F_209 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
struct V_66 * V_251 ,
int V_252 , int V_253 , int V_199 )
{
T_2 V_27 ;
T_2 V_36 ;
T_2 V_17 ;
T_2 V_207 ;
T_3 V_71 ;
struct V_68 V_21 ;
struct V_254 * V_255 ;
int V_43 ;
int V_165 ;
int V_29 = 0 ;
int (* F_210)( struct V_108 * , struct V_34 * ,
T_2 , T_2 , T_2 , T_2 , T_2 , T_2 , int );
V_207 = F_211 ( V_251 ) ;
V_71 = F_38 ( V_251 ) ;
V_165 = F_212 ( V_251 ) ;
if ( ! V_35 -> V_256 && V_165 == 0 )
return 0 ;
if ( V_253 )
F_210 = F_143 ;
else
F_210 = V_257 ;
if ( V_252 )
V_17 = V_251 -> V_32 ;
else
V_17 = 0 ;
for ( V_43 = 0 ; V_43 < V_71 ; V_43 ++ ) {
if ( V_165 == 0 ) {
F_40 ( V_251 , & V_21 , V_43 ) ;
if ( F_213 ( & V_21 ) != V_258 )
continue;
V_255 = F_77 ( V_251 , V_43 ,
struct V_254 ) ;
if ( F_214 ( V_251 , V_255 ) ==
V_259 )
continue;
V_27 = F_215 ( V_251 , V_255 ) ;
if ( V_27 == 0 )
continue;
V_36 = F_216 ( V_251 , V_255 ) ;
V_21 . V_33 -= F_217 ( V_251 , V_255 ) ;
V_29 = F_210 ( V_109 , V_35 , V_27 , V_36 ,
V_17 , V_207 , V_21 . V_22 ,
V_21 . V_33 , V_199 ) ;
if ( V_29 )
goto V_155;
} else {
V_27 = F_218 ( V_251 , V_43 ) ;
V_36 = F_219 ( V_35 , V_165 - 1 ) ;
V_29 = F_210 ( V_109 , V_35 , V_27 , V_36 ,
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
int F_220 ( struct V_108 * V_109 , struct V_34 * V_35 ,
struct V_66 * V_251 , int V_252 , int V_199 )
{
return F_209 ( V_109 , V_35 , V_251 , V_252 , 1 , V_199 ) ;
}
int F_221 ( struct V_108 * V_109 , struct V_34 * V_35 ,
struct V_66 * V_251 , int V_252 , int V_199 )
{
return F_209 ( V_109 , V_35 , V_251 , V_252 , 0 , V_199 ) ;
}
static int F_222 ( struct V_108 * V_109 ,
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
V_138 = F_223 ( V_67 , V_65 -> V_84 [ 0 ] ) ;
F_224 ( V_67 , & V_2 -> V_134 , V_138 , sizeof( V_2 -> V_134 ) ) ;
F_94 ( V_67 ) ;
F_44 ( V_65 ) ;
V_155:
if ( V_29 ) {
F_147 ( V_109 , V_35 , V_29 ) ;
return V_29 ;
}
return 0 ;
}
static struct V_1 *
F_225 ( struct V_34 * V_35 ,
struct V_1 * V_2 )
{
struct V_15 * V_127 ;
F_11 ( & V_35 -> V_37 -> V_18 ) ;
V_127 = F_199 ( & V_2 -> V_20 ) ;
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
static int F_226 ( struct V_1 * V_14 ,
struct V_108 * V_109 ,
struct V_64 * V_65 )
{
struct V_34 * V_35 = V_14 -> V_37 -> V_87 ;
struct V_260 * V_260 = NULL ;
T_2 V_261 = 0 ;
int V_262 = V_263 ;
int V_264 = 0 ;
int V_265 = 0 ;
int V_29 = 0 ;
if ( V_14 -> V_21 . V_33 < ( 100 * 1024 * 1024 ) ) {
F_11 ( & V_14 -> V_52 ) ;
V_14 -> V_266 = V_267 ;
F_13 ( & V_14 -> V_52 ) ;
return 0 ;
}
V_78:
V_260 = F_227 ( V_35 , V_14 , V_65 ) ;
if ( F_228 ( V_260 ) && F_229 ( V_260 ) != - V_152 ) {
V_29 = F_229 ( V_260 ) ;
F_44 ( V_65 ) ;
goto V_73;
}
if ( F_228 ( V_260 ) ) {
F_30 ( V_265 ) ;
V_265 ++ ;
if ( V_14 -> V_268 )
goto V_122;
V_29 = F_230 ( V_35 , V_109 , V_14 , V_65 ) ;
if ( V_29 )
goto V_122;
goto V_78;
}
if ( V_14 -> V_269 == V_109 -> V_270 &&
F_231 ( V_260 ) ) {
V_262 = V_271 ;
goto V_272;
}
F_232 ( V_260 ) -> V_273 = 0 ;
V_29 = F_233 ( V_109 , V_35 , V_260 ) ;
F_8 ( V_29 ) ;
if ( F_231 ( V_260 ) > 0 ) {
V_29 = F_234 ( V_35 ,
& V_35 -> V_37 -> V_239 ) ;
if ( V_29 )
goto V_272;
V_29 = F_235 ( V_35 , V_109 , V_260 ) ;
if ( V_29 )
goto V_272;
}
F_11 ( & V_14 -> V_52 ) ;
if ( V_14 -> V_3 != V_4 ||
! F_236 ( V_35 , V_274 ) ) {
V_262 = V_267 ;
F_13 ( & V_14 -> V_52 ) ;
goto V_272;
}
F_13 ( & V_14 -> V_52 ) ;
V_264 = ( int ) F_180 ( V_14 -> V_21 . V_33 , 256 * 1024 * 1024 ) ;
if ( ! V_264 )
V_264 = 1 ;
V_264 *= 16 ;
V_264 *= V_275 ;
V_29 = F_237 ( V_260 , V_264 ) ;
if ( V_29 )
goto V_272;
V_29 = F_238 ( V_260 , V_109 , 0 , 0 , V_264 ,
V_264 , V_264 ,
& V_261 ) ;
if ( ! V_29 )
V_262 = V_271 ;
F_239 ( V_260 , V_264 ) ;
V_272:
F_240 ( V_260 ) ;
V_122:
F_44 ( V_65 ) ;
V_73:
F_11 ( & V_14 -> V_52 ) ;
if ( ! V_29 && V_262 == V_271 )
V_14 -> V_269 = V_109 -> V_270 ;
V_14 -> V_266 = V_262 ;
F_13 ( & V_14 -> V_52 ) ;
return V_29 ;
}
int F_241 ( struct V_108 * V_109 ,
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
V_2 = F_66 ( V_35 -> V_37 , V_70 ) ;
while ( V_2 ) {
if ( V_2 -> V_266 == V_276 )
break;
V_2 = F_225 ( V_35 , V_2 ) ;
}
if ( ! V_2 ) {
if ( V_70 == 0 )
break;
V_70 = 0 ;
continue;
}
V_82 = F_226 ( V_2 , V_109 , V_65 ) ;
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
V_2 = F_66 ( V_35 -> V_37 , V_70 ) ;
while ( V_2 ) {
if ( V_2 -> V_266 == V_276 ) {
F_6 ( V_2 ) ;
goto V_78;
}
if ( V_2 -> V_277 )
break;
V_2 = F_225 ( V_35 , V_2 ) ;
}
if ( ! V_2 ) {
if ( V_70 == 0 )
break;
V_70 = 0 ;
continue;
}
if ( V_2 -> V_266 == V_271 )
V_2 -> V_266 = V_278 ;
V_2 -> V_277 = 0 ;
V_70 = V_2 -> V_21 . V_22 + V_2 -> V_21 . V_33 ;
V_82 = F_222 ( V_109 , V_35 , V_65 , V_2 ) ;
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
V_2 = F_66 ( V_35 -> V_37 , V_70 ) ;
while ( V_2 ) {
if ( V_2 -> V_277 ) {
F_6 ( V_2 ) ;
goto V_78;
}
if ( V_2 -> V_266 == V_278 )
break;
V_2 = F_225 ( V_35 , V_2 ) ;
}
if ( ! V_2 ) {
if ( V_70 == 0 )
break;
V_70 = 0 ;
continue;
}
V_82 = F_242 ( V_35 , V_109 , V_2 , V_65 ) ;
if ( ! V_82 && V_2 -> V_266 == V_278 )
V_2 -> V_266 = V_267 ;
V_70 = V_2 -> V_21 . V_22 + V_2 -> V_21 . V_33 ;
F_6 ( V_2 ) ;
}
V_73:
F_50 ( V_65 ) ;
return V_82 ;
}
int F_243 ( struct V_34 * V_35 , T_2 V_27 )
{
struct V_1 * V_14 ;
int V_279 = 0 ;
V_14 = F_67 ( V_35 -> V_37 , V_27 ) ;
if ( ! V_14 || V_14 -> V_268 )
V_279 = 1 ;
if ( V_14 )
F_6 ( V_14 ) ;
return V_279 ;
}
static const char * F_244 ( T_2 V_7 )
{
switch ( V_7 ) {
case V_280 | V_281 :
return L_6 ;
case V_280 :
return L_7 ;
case V_281 :
return L_8 ;
case V_282 :
return L_9 ;
default:
F_8 ( 1 ) ;
return L_10 ;
} ;
}
static int F_245 ( struct V_12 * V_13 , T_2 V_7 ,
T_2 V_283 , T_2 V_284 ,
struct V_101 * * V_104 )
{
struct V_101 * V_105 ;
int V_43 ;
int V_285 ;
int V_29 ;
if ( V_7 & ( V_286 | V_287 |
V_288 ) )
V_285 = 2 ;
else
V_285 = 1 ;
V_105 = F_68 ( V_13 , V_7 ) ;
if ( V_105 ) {
F_11 ( & V_105 -> V_52 ) ;
V_105 -> V_283 += V_283 ;
V_105 -> V_289 += V_283 * V_285 ;
V_105 -> V_284 += V_284 ;
V_105 -> V_290 += V_284 * V_285 ;
V_105 -> V_107 = 0 ;
F_13 ( & V_105 -> V_52 ) ;
* V_104 = V_105 ;
return 0 ;
}
V_105 = F_53 ( sizeof( * V_105 ) , V_40 ) ;
if ( ! V_105 )
return - V_72 ;
V_29 = F_246 ( & V_105 -> V_291 , 0 ) ;
if ( V_29 ) {
F_9 ( V_105 ) ;
return V_29 ;
}
for ( V_43 = 0 ; V_43 < V_292 ; V_43 ++ ) {
F_54 ( & V_105 -> V_293 [ V_43 ] ) ;
F_247 ( & V_105 -> V_294 [ V_43 ] , & V_295 ) ;
}
F_248 ( & V_105 -> V_296 ) ;
F_249 ( & V_105 -> V_52 ) ;
V_105 -> V_7 = V_7 & V_106 ;
V_105 -> V_283 = V_283 ;
V_105 -> V_289 = V_283 * V_285 ;
V_105 -> V_284 = V_284 ;
V_105 -> V_290 = V_284 * V_285 ;
V_105 -> V_297 = 0 ;
V_105 -> V_298 = 0 ;
V_105 -> V_299 = 0 ;
V_105 -> V_300 = 0 ;
V_105 -> V_107 = 0 ;
V_105 -> V_301 = V_302 ;
V_105 -> V_303 = 0 ;
V_105 -> V_304 = 0 ;
F_56 ( & V_105 -> V_89 ) ;
V_29 = F_250 ( & V_105 -> V_305 , & V_306 ,
V_13 -> V_307 , L_11 ,
F_244 ( V_105 -> V_7 ) ) ;
if ( V_29 ) {
F_9 ( V_105 ) ;
return V_29 ;
}
* V_104 = V_105 ;
F_251 ( & V_105 -> V_91 , & V_13 -> V_104 ) ;
if ( V_7 & V_281 )
V_13 -> V_308 = V_105 ;
return V_29 ;
}
static void F_252 ( struct V_12 * V_37 , T_2 V_7 )
{
T_2 V_309 = F_253 ( V_7 ) &
V_310 ;
F_254 ( & V_37 -> V_311 ) ;
if ( V_7 & V_281 )
V_37 -> V_312 |= V_309 ;
if ( V_7 & V_280 )
V_37 -> V_313 |= V_309 ;
if ( V_7 & V_282 )
V_37 -> V_314 |= V_309 ;
F_255 ( & V_37 -> V_311 ) ;
}
static T_2 F_256 ( struct V_12 * V_37 , T_2 V_7 )
{
struct V_315 * V_316 = V_37 -> V_317 ;
T_2 V_318 = 0 ;
if ( ! V_316 )
return 0 ;
if ( V_7 & V_281 &&
V_316 -> V_319 . V_7 & V_320 ) {
V_318 = V_281 | V_316 -> V_319 . V_318 ;
} else if ( V_7 & V_282 &&
V_316 -> V_321 . V_7 & V_320 ) {
V_318 = V_282 | V_316 -> V_321 . V_318 ;
} else if ( V_7 & V_280 &&
V_316 -> V_322 . V_7 & V_320 ) {
V_318 = V_280 | V_316 -> V_322 . V_318 ;
}
return V_318 ;
}
static T_2 F_257 ( struct V_34 * V_35 , T_2 V_7 )
{
T_2 V_323 = V_35 -> V_37 -> V_324 -> V_325 +
V_35 -> V_37 -> V_324 -> V_326 ;
T_2 V_318 ;
T_2 V_327 ;
F_11 ( & V_35 -> V_37 -> V_328 ) ;
V_318 = F_256 ( V_35 -> V_37 , V_7 ) ;
if ( V_318 ) {
if ( ( V_7 & V_318 ) & V_310 ) {
F_13 ( & V_35 -> V_37 -> V_328 ) ;
return F_258 ( V_318 ) ;
}
}
F_13 ( & V_35 -> V_37 -> V_328 ) ;
if ( V_323 == 1 )
V_7 &= ~ ( V_287 | V_329 |
V_330 ) ;
if ( V_323 < 3 )
V_7 &= ~ V_331 ;
if ( V_323 < 4 )
V_7 &= ~ V_288 ;
V_327 = V_7 & ( V_286 | V_329 |
V_287 | V_330 |
V_331 | V_288 ) ;
V_7 &= ~ V_327 ;
if ( V_327 & V_331 )
V_327 = V_331 ;
else if ( V_327 & V_330 )
V_327 = V_330 ;
else if ( V_327 & V_288 )
V_327 = V_288 ;
else if ( V_327 & V_287 )
V_327 = V_287 ;
else if ( V_327 & V_329 )
V_327 = V_329 ;
return F_258 ( V_7 | V_327 ) ;
}
static T_2 F_259 ( struct V_34 * V_35 , T_2 V_7 )
{
unsigned V_216 ;
do {
V_216 = F_260 ( & V_35 -> V_37 -> V_311 ) ;
if ( V_7 & V_281 )
V_7 |= V_35 -> V_37 -> V_312 ;
else if ( V_7 & V_282 )
V_7 |= V_35 -> V_37 -> V_314 ;
else if ( V_7 & V_280 )
V_7 |= V_35 -> V_37 -> V_313 ;
} while ( F_261 ( & V_35 -> V_37 -> V_311 , V_216 ) );
return F_257 ( V_35 , V_7 ) ;
}
T_2 F_262 ( struct V_34 * V_35 , int V_319 )
{
T_2 V_7 ;
T_2 V_29 ;
if ( V_319 )
V_7 = V_281 ;
else if ( V_35 == V_35 -> V_37 -> V_332 )
V_7 = V_282 ;
else
V_7 = V_280 ;
V_29 = F_259 ( V_35 , V_7 ) ;
return V_29 ;
}
int F_237 ( struct V_260 * V_260 , T_2 V_333 )
{
struct V_101 * V_308 ;
struct V_34 * V_35 = F_232 ( V_260 ) -> V_35 ;
struct V_12 * V_37 = V_35 -> V_37 ;
T_2 V_334 ;
int V_29 = 0 , V_335 = 0 , V_336 = 1 ;
V_333 = F_263 ( V_333 , V_35 -> V_337 ) ;
if ( F_264 ( V_260 ) ) {
V_335 = 1 ;
ASSERT ( V_338 -> V_339 ) ;
}
V_308 = V_37 -> V_308 ;
if ( ! V_308 )
goto V_340;
V_78:
F_11 ( & V_308 -> V_52 ) ;
V_334 = V_308 -> V_284 + V_308 -> V_298 +
V_308 -> V_297 + V_308 -> V_299 +
V_308 -> V_300 ;
if ( V_334 + V_333 > V_308 -> V_283 ) {
struct V_108 * V_109 ;
if ( ! V_308 -> V_107 && V_336 ) {
T_2 V_341 ;
V_308 -> V_301 = V_342 ;
F_13 ( & V_308 -> V_52 ) ;
V_340:
V_341 = F_262 ( V_35 , 1 ) ;
V_109 = F_265 ( V_35 ) ;
if ( F_228 ( V_109 ) )
return F_229 ( V_109 ) ;
V_29 = F_266 ( V_109 , V_35 -> V_37 -> V_63 ,
V_341 ,
V_302 ) ;
F_267 ( V_109 , V_35 ) ;
if ( V_29 < 0 ) {
if ( V_29 != - V_343 )
return V_29 ;
else
goto V_344;
}
if ( ! V_308 )
V_308 = V_37 -> V_308 ;
goto V_78;
}
if ( F_268 ( & V_308 -> V_291 ,
V_333 ) < 0 )
V_335 = 1 ;
F_13 ( & V_308 -> V_52 ) ;
V_344:
if ( ! V_335 &&
! F_195 ( & V_35 -> V_37 -> V_345 ) ) {
V_335 = 1 ;
V_109 = F_265 ( V_35 ) ;
if ( F_228 ( V_109 ) )
return F_229 ( V_109 ) ;
V_29 = F_269 ( V_109 , V_35 ) ;
if ( V_29 )
return V_29 ;
goto V_78;
}
F_270 ( V_35 -> V_37 ,
L_12 ,
V_308 -> V_7 , V_333 , 1 ) ;
return - V_343 ;
}
V_308 -> V_300 += V_333 ;
F_270 ( V_35 -> V_37 , L_13 ,
V_308 -> V_7 , V_333 , 1 ) ;
F_13 ( & V_308 -> V_52 ) ;
return 0 ;
}
void F_239 ( struct V_260 * V_260 , T_2 V_333 )
{
struct V_34 * V_35 = F_232 ( V_260 ) -> V_35 ;
struct V_101 * V_308 ;
V_333 = F_263 ( V_333 , V_35 -> V_337 ) ;
V_308 = V_35 -> V_37 -> V_308 ;
F_11 ( & V_308 -> V_52 ) ;
F_8 ( V_308 -> V_300 < V_333 ) ;
V_308 -> V_300 -= V_333 ;
F_270 ( V_35 -> V_37 , L_13 ,
V_308 -> V_7 , V_333 , 0 ) ;
F_13 ( & V_308 -> V_52 ) ;
}
static void F_271 ( struct V_12 * V_13 )
{
struct V_102 * V_103 = & V_13 -> V_104 ;
struct V_101 * V_105 ;
F_69 () ;
F_70 (found, head, list) {
if ( V_105 -> V_7 & V_280 )
V_105 -> V_301 = V_342 ;
}
F_71 () ;
}
static inline T_2 F_272 ( struct V_237 * V_346 )
{
return ( V_346 -> V_57 << 1 ) ;
}
static int F_273 ( struct V_34 * V_35 ,
struct V_101 * V_347 , int V_348 )
{
struct V_237 * V_238 = & V_35 -> V_37 -> V_239 ;
T_2 V_36 = V_347 -> V_283 - V_347 -> V_299 ;
T_2 V_349 = V_347 -> V_284 + V_347 -> V_298 ;
T_2 V_350 ;
if ( V_348 == V_342 )
return 1 ;
if ( V_347 -> V_7 & V_280 )
V_349 += F_272 ( V_238 ) ;
if ( V_348 == V_351 ) {
V_350 = F_274 ( V_35 -> V_37 -> V_352 ) ;
V_350 = F_34 ( T_2 , 64 * 1024 * 1024 ,
F_275 ( V_350 , 1 ) ) ;
if ( V_36 - V_349 < V_350 )
return 1 ;
}
if ( V_349 + 2 * 1024 * 1024 < F_276 ( V_36 , 8 ) )
return 0 ;
return 1 ;
}
static T_2 F_277 ( struct V_34 * V_35 , T_2 type )
{
T_2 V_353 ;
if ( type & ( V_288 |
V_329 |
V_330 |
V_331 ) )
V_353 = V_35 -> V_37 -> V_324 -> V_325 ;
else if ( type & V_287 )
V_353 = 2 ;
else
V_353 = 1 ;
return F_193 ( V_35 , V_353 + 1 ) ;
}
static void F_278 ( struct V_108 * V_109 ,
struct V_34 * V_35 , T_2 type )
{
struct V_101 * V_13 ;
T_2 V_354 ;
T_2 V_350 ;
V_13 = F_68 ( V_35 -> V_37 , V_282 ) ;
F_11 ( & V_13 -> V_52 ) ;
V_354 = V_13 -> V_283 - V_13 -> V_284 - V_13 -> V_297 -
V_13 -> V_298 - V_13 -> V_299 ;
F_13 ( & V_13 -> V_52 ) ;
V_350 = F_277 ( V_35 , type ) ;
if ( V_354 < V_350 && F_236 ( V_35 , V_355 ) ) {
F_279 ( V_35 -> V_37 , L_14 ,
V_354 , V_350 , type ) ;
F_280 ( V_13 , 0 , 0 ) ;
}
if ( V_354 < V_350 ) {
T_2 V_7 ;
V_7 = F_262 ( V_35 -> V_37 -> V_332 , 0 ) ;
F_281 ( V_109 , V_35 , V_7 ) ;
}
}
static int F_266 ( struct V_108 * V_109 ,
struct V_34 * V_63 , T_2 V_7 , int V_348 )
{
struct V_101 * V_104 ;
struct V_12 * V_37 = V_63 -> V_37 ;
int V_356 = 0 ;
int V_29 = 0 ;
if ( V_109 -> V_357 )
return - V_343 ;
V_104 = F_68 ( V_63 -> V_37 , V_7 ) ;
if ( ! V_104 ) {
V_29 = F_245 ( V_63 -> V_37 , V_7 ,
0 , 0 , & V_104 ) ;
F_30 ( V_29 ) ;
}
F_30 ( ! V_104 ) ;
V_78:
F_11 ( & V_104 -> V_52 ) ;
if ( V_348 < V_104 -> V_301 )
V_348 = V_104 -> V_301 ;
if ( V_104 -> V_107 ) {
if ( F_273 ( V_63 , V_104 , V_348 ) )
V_29 = - V_343 ;
else
V_29 = 0 ;
F_13 ( & V_104 -> V_52 ) ;
return V_29 ;
}
if ( ! F_273 ( V_63 , V_104 , V_348 ) ) {
F_13 ( & V_104 -> V_52 ) ;
return 0 ;
} else if ( V_104 -> V_303 ) {
V_356 = 1 ;
} else {
V_104 -> V_303 = 1 ;
}
F_13 ( & V_104 -> V_52 ) ;
F_35 ( & V_37 -> V_358 ) ;
if ( V_356 ) {
F_46 ( & V_37 -> V_358 ) ;
V_356 = 0 ;
goto V_78;
}
V_109 -> V_357 = true ;
if ( F_282 ( V_104 ) )
V_7 |= ( V_281 | V_280 ) ;
if ( V_7 & V_281 && V_37 -> V_359 ) {
V_37 -> V_360 ++ ;
if ( ! ( V_37 -> V_360 %
V_37 -> V_359 ) )
F_271 ( V_37 ) ;
}
F_278 ( V_109 , V_63 , V_7 ) ;
V_29 = F_281 ( V_109 , V_63 , V_7 ) ;
V_109 -> V_357 = false ;
F_11 ( & V_104 -> V_52 ) ;
if ( V_29 < 0 && V_29 != - V_343 )
goto V_73;
if ( V_29 )
V_104 -> V_107 = 1 ;
else
V_29 = 1 ;
V_104 -> V_301 = V_302 ;
V_73:
V_104 -> V_303 = 0 ;
F_13 ( & V_104 -> V_52 ) ;
F_46 ( & V_37 -> V_358 ) ;
return V_29 ;
}
static int F_283 ( struct V_34 * V_35 ,
struct V_101 * V_104 , T_2 V_333 ,
enum V_361 V_304 )
{
struct V_237 * V_238 = & V_35 -> V_37 -> V_239 ;
T_2 V_362 = F_262 ( V_35 , 0 ) ;
T_2 V_363 ;
T_2 V_364 ;
T_2 V_334 ;
V_334 = V_104 -> V_284 + V_104 -> V_298 +
V_104 -> V_297 + V_104 -> V_299 ;
F_11 ( & V_238 -> V_52 ) ;
V_363 = F_272 ( V_238 ) ;
F_13 ( & V_238 -> V_52 ) ;
if ( V_334 + V_363 >= V_104 -> V_283 )
return 0 ;
V_334 += V_104 -> V_300 ;
F_11 ( & V_35 -> V_37 -> V_365 ) ;
V_364 = V_35 -> V_37 -> V_366 ;
F_13 ( & V_35 -> V_37 -> V_365 ) ;
if ( V_362 & ( V_286 |
V_287 |
V_288 ) )
V_364 >>= 1 ;
if ( V_304 == V_367 )
V_364 >>= 3 ;
else
V_364 >>= 1 ;
if ( V_334 + V_333 < V_104 -> V_283 + V_364 )
return 1 ;
return 0 ;
}
static void F_284 ( struct V_34 * V_35 ,
unsigned long V_368 )
{
struct V_369 * V_370 = V_35 -> V_37 -> V_370 ;
if ( F_285 ( & V_370 -> V_371 ) ) {
F_286 ( V_370 , V_368 , V_372 ) ;
F_45 ( & V_370 -> V_371 ) ;
} else {
F_287 ( V_35 -> V_37 , 0 ) ;
if ( ! V_338 -> V_339 )
F_288 ( V_35 -> V_37 , - 1 ) ;
}
}
static inline int F_289 ( struct V_34 * V_35 , T_2 V_373 )
{
T_2 V_333 ;
int V_44 ;
V_333 = F_193 ( V_35 , 1 ) ;
V_44 = ( int ) F_180 ( V_373 , V_333 ) ;
if ( ! V_44 )
V_44 = 1 ;
return V_44 ;
}
static void F_290 ( struct V_34 * V_35 , T_2 V_373 , T_2 V_374 ,
bool V_375 )
{
struct V_237 * V_376 ;
struct V_101 * V_104 ;
struct V_108 * V_109 ;
T_2 V_377 ;
T_2 V_378 ;
long V_379 ;
unsigned long V_368 ;
int V_380 ;
int V_381 ;
enum V_361 V_304 ;
V_381 = F_289 ( V_35 , V_373 ) ;
V_373 = V_381 * V_382 ;
V_109 = (struct V_108 * ) V_338 -> V_339 ;
V_376 = & V_35 -> V_37 -> V_383 ;
V_104 = V_376 -> V_104 ;
V_377 = F_291 (
& V_35 -> V_37 -> V_377 ) ;
if ( V_377 == 0 ) {
if ( V_109 )
return;
if ( V_375 )
F_288 ( V_35 -> V_37 , V_381 ) ;
return;
}
V_380 = 0 ;
while ( V_377 && V_380 < 3 ) {
V_378 = F_292 ( V_377 , V_373 ) ;
V_368 = V_378 >> V_384 ;
F_284 ( V_35 , V_368 ) ;
V_378 = F_195 ( & V_35 -> V_37 -> V_385 ) ;
if ( ! V_378 )
goto V_386;
if ( V_378 <= V_368 )
V_378 = 0 ;
else
V_378 -= V_368 ;
F_293 ( V_35 -> V_37 -> V_387 ,
F_195 ( & V_35 -> V_37 -> V_385 ) <=
( int ) V_378 ) ;
V_386:
if ( ! V_109 )
V_304 = V_367 ;
else
V_304 = V_388 ;
F_11 ( & V_104 -> V_52 ) ;
if ( F_283 ( V_35 , V_104 , V_374 , V_304 ) ) {
F_13 ( & V_104 -> V_52 ) ;
break;
}
F_13 ( & V_104 -> V_52 ) ;
V_380 ++ ;
if ( V_375 && ! V_109 ) {
F_288 ( V_35 -> V_37 , V_381 ) ;
} else {
V_379 = F_294 ( 1 ) ;
if ( V_379 )
break;
}
V_377 = F_291 (
& V_35 -> V_37 -> V_377 ) ;
}
}
static int F_295 ( struct V_34 * V_35 ,
struct V_101 * V_104 ,
T_2 V_333 , int V_348 )
{
struct V_237 * V_389 = & V_35 -> V_37 -> V_390 ;
struct V_108 * V_109 ;
V_109 = (struct V_108 * ) V_338 -> V_339 ;
if ( V_109 )
return - V_176 ;
if ( V_348 )
goto V_391;
F_11 ( & V_104 -> V_52 ) ;
if ( F_268 ( & V_104 -> V_291 ,
V_333 ) >= 0 ) {
F_13 ( & V_104 -> V_52 ) ;
goto V_391;
}
F_13 ( & V_104 -> V_52 ) ;
if ( V_104 != V_389 -> V_104 )
return - V_343 ;
F_11 ( & V_104 -> V_52 ) ;
F_11 ( & V_389 -> V_52 ) ;
if ( F_268 ( & V_104 -> V_291 ,
V_333 - V_389 -> V_57 ) >= 0 ) {
F_13 ( & V_389 -> V_52 ) ;
F_13 ( & V_104 -> V_52 ) ;
return - V_343 ;
}
F_13 ( & V_389 -> V_52 ) ;
F_13 ( & V_104 -> V_52 ) ;
V_391:
V_109 = F_265 ( V_35 ) ;
if ( F_228 ( V_109 ) )
return - V_343 ;
return F_269 ( V_109 , V_35 ) ;
}
static int F_296 ( struct V_34 * V_35 ,
struct V_101 * V_104 , T_2 V_36 ,
T_2 V_392 , int V_393 )
{
struct V_108 * V_109 ;
int V_44 ;
int V_29 = 0 ;
switch ( V_393 ) {
case V_394 :
case V_395 :
if ( V_393 == V_394 )
V_44 = F_289 ( V_35 , V_36 ) * 2 ;
else
V_44 = - 1 ;
V_109 = F_265 ( V_35 ) ;
if ( F_228 ( V_109 ) ) {
V_29 = F_229 ( V_109 ) ;
break;
}
V_29 = F_297 ( V_109 , V_35 , V_44 ) ;
F_267 ( V_109 , V_35 ) ;
break;
case V_396 :
case V_397 :
F_290 ( V_35 , V_36 , V_392 ,
V_393 == V_397 ) ;
break;
case V_398 :
V_109 = F_265 ( V_35 ) ;
if ( F_228 ( V_109 ) ) {
V_29 = F_229 ( V_109 ) ;
break;
}
V_29 = F_266 ( V_109 , V_35 -> V_37 -> V_63 ,
F_262 ( V_35 , 0 ) ,
V_302 ) ;
F_267 ( V_109 , V_35 ) ;
if ( V_29 == - V_343 )
V_29 = 0 ;
break;
case V_399 :
V_29 = F_295 ( V_35 , V_104 , V_392 , 0 ) ;
break;
default:
V_29 = - V_343 ;
break;
}
return V_29 ;
}
static int F_298 ( struct V_34 * V_35 ,
struct V_237 * V_376 ,
T_2 V_392 ,
enum V_361 V_304 )
{
struct V_101 * V_104 = V_376 -> V_104 ;
T_2 V_334 ;
T_2 V_36 = V_392 ;
int V_400 = V_394 ;
int V_29 = 0 ;
bool V_401 = false ;
V_78:
V_29 = 0 ;
F_11 ( & V_104 -> V_52 ) ;
while ( V_304 == V_367 && ! V_401 &&
V_104 -> V_304 ) {
F_13 ( & V_104 -> V_52 ) ;
if ( V_338 -> V_339 )
return - V_176 ;
V_29 = F_299 ( V_104 -> V_89 , ! V_104 -> V_304 ) ;
if ( V_29 )
return - V_402 ;
F_11 ( & V_104 -> V_52 ) ;
}
V_29 = - V_343 ;
V_334 = V_104 -> V_284 + V_104 -> V_298 +
V_104 -> V_297 + V_104 -> V_299 +
V_104 -> V_300 ;
if ( V_334 <= V_104 -> V_283 ) {
if ( V_334 + V_392 <= V_104 -> V_283 ) {
V_104 -> V_300 += V_392 ;
F_270 ( V_35 -> V_37 ,
L_13 , V_104 -> V_7 , V_392 , 1 ) ;
V_29 = 0 ;
} else {
V_36 = V_392 ;
}
} else {
V_36 = V_334 - V_104 -> V_283 +
( V_392 * 2 ) ;
}
if ( V_29 && F_283 ( V_35 , V_104 , V_392 , V_304 ) ) {
V_104 -> V_300 += V_392 ;
F_270 ( V_35 -> V_37 , L_13 ,
V_104 -> V_7 , V_392 ,
1 ) ;
V_29 = 0 ;
}
if ( V_29 && V_304 != V_388 ) {
V_401 = true ;
V_104 -> V_304 = 1 ;
}
F_13 ( & V_104 -> V_52 ) ;
if ( ! V_29 || V_304 == V_388 )
goto V_73;
V_29 = F_296 ( V_35 , V_104 , V_36 , V_392 ,
V_400 ) ;
V_400 ++ ;
if ( V_304 == V_403 &&
( V_400 == V_396 ||
V_400 == V_397 ) )
V_400 = V_398 ;
if ( ! V_29 )
goto V_78;
else if ( V_304 == V_403 &&
V_400 < V_399 )
goto V_78;
else if ( V_304 == V_367 &&
V_400 <= V_399 )
goto V_78;
V_73:
if ( V_29 == - V_343 &&
F_300 ( V_35 -> V_404 == V_405 ) ) {
struct V_237 * V_238 =
& V_35 -> V_37 -> V_239 ;
if ( V_376 != V_238 &&
! F_301 ( V_238 , V_392 ) )
V_29 = 0 ;
}
if ( V_29 == - V_343 )
F_270 ( V_35 -> V_37 ,
L_12 ,
V_104 -> V_7 , V_392 , 1 ) ;
if ( V_401 ) {
F_11 ( & V_104 -> V_52 ) ;
V_104 -> V_304 = 0 ;
F_302 ( & V_104 -> V_89 ) ;
F_13 ( & V_104 -> V_52 ) ;
}
return V_29 ;
}
static struct V_237 * F_303 (
const struct V_108 * V_109 ,
const struct V_34 * V_35 )
{
struct V_237 * V_376 = NULL ;
if ( V_35 -> V_256 )
V_376 = V_109 -> V_376 ;
if ( V_35 == V_35 -> V_37 -> V_406 && V_109 -> V_407 )
V_376 = V_109 -> V_376 ;
if ( V_35 == V_35 -> V_37 -> V_408 )
V_376 = V_109 -> V_376 ;
if ( ! V_376 )
V_376 = V_35 -> V_376 ;
if ( ! V_376 )
V_376 = & V_35 -> V_37 -> V_409 ;
return V_376 ;
}
static int F_301 ( struct V_237 * V_376 ,
T_2 V_36 )
{
int V_29 = - V_343 ;
F_11 ( & V_376 -> V_52 ) ;
if ( V_376 -> V_10 >= V_36 ) {
V_376 -> V_10 -= V_36 ;
if ( V_376 -> V_10 < V_376 -> V_57 )
V_376 -> V_107 = 0 ;
V_29 = 0 ;
}
F_13 ( & V_376 -> V_52 ) ;
return V_29 ;
}
static void F_304 ( struct V_237 * V_376 ,
T_2 V_36 , int V_410 )
{
F_11 ( & V_376 -> V_52 ) ;
V_376 -> V_10 += V_36 ;
if ( V_410 )
V_376 -> V_57 += V_36 ;
else if ( V_376 -> V_10 >= V_376 -> V_57 )
V_376 -> V_107 = 1 ;
F_13 ( & V_376 -> V_52 ) ;
}
int F_305 ( struct V_12 * V_37 ,
struct V_237 * V_411 , T_2 V_36 ,
int V_412 )
{
struct V_237 * V_238 = & V_37 -> V_239 ;
T_2 V_413 ;
if ( V_238 -> V_104 != V_411 -> V_104 )
return - V_343 ;
F_11 ( & V_238 -> V_52 ) ;
V_413 = F_276 ( V_238 -> V_57 , V_412 ) ;
if ( V_238 -> V_10 < V_413 + V_36 ) {
F_13 ( & V_238 -> V_52 ) ;
return - V_343 ;
}
V_238 -> V_10 -= V_36 ;
if ( V_238 -> V_10 < V_238 -> V_57 )
V_238 -> V_107 = 0 ;
F_13 ( & V_238 -> V_52 ) ;
F_304 ( V_411 , V_36 , 1 ) ;
return 0 ;
}
static void F_306 ( struct V_12 * V_37 ,
struct V_237 * V_376 ,
struct V_237 * V_411 , T_2 V_36 )
{
struct V_101 * V_104 = V_376 -> V_104 ;
F_11 ( & V_376 -> V_52 ) ;
if ( V_36 == ( T_2 ) - 1 )
V_36 = V_376 -> V_57 ;
V_376 -> V_57 -= V_36 ;
if ( V_376 -> V_10 >= V_376 -> V_57 ) {
V_36 = V_376 -> V_10 - V_376 -> V_57 ;
V_376 -> V_10 = V_376 -> V_57 ;
V_376 -> V_107 = 1 ;
} else {
V_36 = 0 ;
}
F_13 ( & V_376 -> V_52 ) ;
if ( V_36 > 0 ) {
if ( V_411 ) {
F_11 ( & V_411 -> V_52 ) ;
if ( ! V_411 -> V_107 ) {
T_2 V_414 ;
V_414 = V_411 -> V_57 - V_411 -> V_10 ;
V_414 = F_292 ( V_36 , V_414 ) ;
V_411 -> V_10 += V_414 ;
if ( V_411 -> V_10 >= V_411 -> V_57 )
V_411 -> V_107 = 1 ;
V_36 -= V_414 ;
}
F_13 ( & V_411 -> V_52 ) ;
}
if ( V_36 ) {
F_11 ( & V_104 -> V_52 ) ;
V_104 -> V_300 -= V_36 ;
F_270 ( V_37 , L_13 ,
V_104 -> V_7 , V_36 , 0 ) ;
F_13 ( & V_104 -> V_52 ) ;
}
}
}
static int F_307 ( struct V_237 * V_415 ,
struct V_237 * V_416 , T_2 V_36 )
{
int V_29 ;
V_29 = F_301 ( V_415 , V_36 ) ;
if ( V_29 )
return V_29 ;
F_304 ( V_416 , V_36 , 1 ) ;
return 0 ;
}
void F_308 ( struct V_237 * V_417 , unsigned short type )
{
memset ( V_417 , 0 , sizeof( * V_417 ) ) ;
F_249 ( & V_417 -> V_52 ) ;
V_417 -> type = type ;
}
struct V_237 * F_309 ( struct V_34 * V_35 ,
unsigned short type )
{
struct V_237 * V_376 ;
struct V_12 * V_37 = V_35 -> V_37 ;
V_376 = F_310 ( sizeof( * V_376 ) , V_40 ) ;
if ( ! V_376 )
return NULL ;
F_308 ( V_376 , type ) ;
V_376 -> V_104 = F_68 ( V_37 ,
V_280 ) ;
return V_376 ;
}
void F_311 ( struct V_34 * V_35 ,
struct V_237 * V_417 )
{
if ( ! V_417 )
return;
F_312 ( V_35 , V_417 , ( T_2 ) - 1 ) ;
F_9 ( V_417 ) ;
}
int F_313 ( struct V_34 * V_35 ,
struct V_237 * V_376 , T_2 V_36 ,
enum V_361 V_304 )
{
int V_29 ;
if ( V_36 == 0 )
return 0 ;
V_29 = F_298 ( V_35 , V_376 , V_36 , V_304 ) ;
if ( ! V_29 ) {
F_304 ( V_376 , V_36 , 1 ) ;
return 0 ;
}
return V_29 ;
}
int F_314 ( struct V_34 * V_35 ,
struct V_237 * V_376 , int V_412 )
{
T_2 V_36 = 0 ;
int V_29 = - V_343 ;
if ( ! V_376 )
return 0 ;
F_11 ( & V_376 -> V_52 ) ;
V_36 = F_276 ( V_376 -> V_57 , V_412 ) ;
if ( V_376 -> V_10 >= V_36 )
V_29 = 0 ;
F_13 ( & V_376 -> V_52 ) ;
return V_29 ;
}
int F_315 ( struct V_34 * V_35 ,
struct V_237 * V_376 , T_2 V_418 ,
enum V_361 V_304 )
{
T_2 V_36 = 0 ;
int V_29 = - V_343 ;
if ( ! V_376 )
return 0 ;
F_11 ( & V_376 -> V_52 ) ;
V_36 = V_418 ;
if ( V_376 -> V_10 >= V_36 )
V_29 = 0 ;
else
V_36 -= V_376 -> V_10 ;
F_13 ( & V_376 -> V_52 ) ;
if ( ! V_29 )
return 0 ;
V_29 = F_298 ( V_35 , V_376 , V_36 , V_304 ) ;
if ( ! V_29 ) {
F_304 ( V_376 , V_36 , 0 ) ;
return 0 ;
}
return V_29 ;
}
int F_316 ( struct V_237 * V_419 ,
struct V_237 * V_420 ,
T_2 V_36 )
{
return F_307 ( V_419 , V_420 , V_36 ) ;
}
void F_312 ( struct V_34 * V_35 ,
struct V_237 * V_376 ,
T_2 V_36 )
{
struct V_237 * V_238 = & V_35 -> V_37 -> V_239 ;
if ( V_238 == V_376 ||
V_376 -> V_104 != V_238 -> V_104 )
V_238 = NULL ;
F_306 ( V_35 -> V_37 , V_376 , V_238 ,
V_36 ) ;
}
static T_2 F_317 ( struct V_12 * V_37 )
{
struct V_101 * V_347 ;
T_2 V_36 ;
T_2 V_421 ;
T_2 V_422 ;
int V_423 = F_318 ( V_37 -> V_352 ) ;
V_347 = F_68 ( V_37 , V_281 ) ;
F_11 ( & V_347 -> V_52 ) ;
V_422 = V_347 -> V_284 ;
F_13 ( & V_347 -> V_52 ) ;
V_347 = F_68 ( V_37 , V_280 ) ;
F_11 ( & V_347 -> V_52 ) ;
if ( V_347 -> V_7 & V_281 )
V_422 = 0 ;
V_421 = V_347 -> V_284 ;
F_13 ( & V_347 -> V_52 ) ;
V_36 = ( V_422 >> V_37 -> V_370 -> V_424 ) *
V_423 * 2 ;
V_36 += F_180 ( V_422 + V_421 , 50 ) ;
if ( V_36 * 3 > V_421 )
V_36 = F_180 ( V_421 , 3 ) ;
return F_263 ( V_36 , V_37 -> V_63 -> V_88 << 10 ) ;
}
static void F_319 ( struct V_12 * V_37 )
{
struct V_237 * V_376 = & V_37 -> V_239 ;
struct V_101 * V_347 = V_376 -> V_104 ;
T_2 V_36 ;
V_36 = F_317 ( V_37 ) ;
F_11 ( & V_347 -> V_52 ) ;
F_11 ( & V_376 -> V_52 ) ;
V_376 -> V_57 = F_24 ( T_2 , V_36 , 512 * 1024 * 1024 ) ;
V_36 = V_347 -> V_284 + V_347 -> V_297 +
V_347 -> V_298 + V_347 -> V_299 +
V_347 -> V_300 ;
if ( V_347 -> V_283 > V_36 ) {
V_36 = V_347 -> V_283 - V_36 ;
V_376 -> V_10 += V_36 ;
V_347 -> V_300 += V_36 ;
F_270 ( V_37 , L_13 ,
V_347 -> V_7 , V_36 , 1 ) ;
}
if ( V_376 -> V_10 >= V_376 -> V_57 ) {
V_36 = V_376 -> V_10 - V_376 -> V_57 ;
V_347 -> V_300 -= V_36 ;
F_270 ( V_37 , L_13 ,
V_347 -> V_7 , V_36 , 0 ) ;
V_376 -> V_10 = V_376 -> V_57 ;
V_376 -> V_107 = 1 ;
}
F_13 ( & V_376 -> V_52 ) ;
F_13 ( & V_347 -> V_52 ) ;
}
static void F_320 ( struct V_12 * V_37 )
{
struct V_101 * V_104 ;
V_104 = F_68 ( V_37 , V_282 ) ;
V_37 -> V_425 . V_104 = V_104 ;
V_104 = F_68 ( V_37 , V_280 ) ;
V_37 -> V_239 . V_104 = V_104 ;
V_37 -> V_383 . V_104 = V_104 ;
V_37 -> V_426 . V_104 = V_104 ;
V_37 -> V_409 . V_104 = V_104 ;
V_37 -> V_390 . V_104 = V_104 ;
V_37 -> V_63 -> V_376 = & V_37 -> V_239 ;
V_37 -> V_406 -> V_376 = & V_37 -> V_239 ;
V_37 -> V_427 -> V_376 = & V_37 -> V_239 ;
V_37 -> V_87 -> V_376 = & V_37 -> V_239 ;
if ( V_37 -> V_428 )
V_37 -> V_428 -> V_376 = & V_37 -> V_239 ;
V_37 -> V_332 -> V_376 = & V_37 -> V_425 ;
F_319 ( V_37 ) ;
}
static void F_321 ( struct V_12 * V_37 )
{
F_306 ( V_37 , & V_37 -> V_239 , NULL ,
( T_2 ) - 1 ) ;
F_8 ( V_37 -> V_383 . V_57 > 0 ) ;
F_8 ( V_37 -> V_383 . V_10 > 0 ) ;
F_8 ( V_37 -> V_426 . V_57 > 0 ) ;
F_8 ( V_37 -> V_426 . V_10 > 0 ) ;
F_8 ( V_37 -> V_425 . V_57 > 0 ) ;
F_8 ( V_37 -> V_425 . V_10 > 0 ) ;
F_8 ( V_37 -> V_390 . V_57 > 0 ) ;
F_8 ( V_37 -> V_390 . V_10 > 0 ) ;
}
void F_322 ( struct V_108 * V_109 ,
struct V_34 * V_35 )
{
if ( ! V_109 -> V_376 )
return;
if ( ! V_109 -> V_298 )
return;
F_270 ( V_35 -> V_37 , L_15 ,
V_109 -> V_270 , V_109 -> V_298 , 0 ) ;
F_312 ( V_35 , V_109 -> V_376 , V_109 -> V_298 ) ;
V_109 -> V_298 = 0 ;
}
int F_323 ( struct V_108 * V_109 ,
struct V_260 * V_260 )
{
struct V_34 * V_35 = F_232 ( V_260 ) -> V_35 ;
struct V_237 * V_419 = F_303 ( V_109 , V_35 ) ;
struct V_237 * V_420 = V_35 -> V_429 ;
T_2 V_36 = F_193 ( V_35 , 1 ) ;
F_270 ( V_35 -> V_37 , L_16 ,
F_324 ( V_260 ) , V_36 , 1 ) ;
return F_307 ( V_419 , V_420 , V_36 ) ;
}
void F_325 ( struct V_260 * V_260 )
{
struct V_34 * V_35 = F_232 ( V_260 ) -> V_35 ;
T_2 V_36 = F_193 ( V_35 , 1 ) ;
F_270 ( V_35 -> V_37 , L_16 ,
F_324 ( V_260 ) , V_36 , 0 ) ;
F_312 ( V_35 , V_35 -> V_429 , V_36 ) ;
}
int F_326 ( struct V_34 * V_35 ,
struct V_237 * V_417 ,
int V_381 ,
T_2 * V_430 ,
bool V_431 )
{
T_2 V_36 ;
int V_29 ;
struct V_237 * V_238 = & V_35 -> V_37 -> V_239 ;
if ( V_35 -> V_37 -> V_432 ) {
V_36 = 3 * V_35 -> V_88 ;
V_29 = F_327 ( V_35 , V_36 ) ;
if ( V_29 )
return V_29 ;
} else {
V_36 = 0 ;
}
* V_430 = V_36 ;
V_36 = F_193 ( V_35 , V_381 ) ;
V_417 -> V_104 = F_68 ( V_35 -> V_37 ,
V_280 ) ;
V_29 = F_313 ( V_35 , V_417 , V_36 ,
V_367 ) ;
if ( V_29 == - V_343 && V_431 )
V_29 = F_316 ( V_238 , V_417 , V_36 ) ;
if ( V_29 ) {
if ( * V_430 )
F_328 ( V_35 , * V_430 ) ;
}
return V_29 ;
}
void F_329 ( struct V_34 * V_35 ,
struct V_237 * V_417 ,
T_2 V_430 )
{
F_312 ( V_35 , V_417 , ( T_2 ) - 1 ) ;
if ( V_430 )
F_328 ( V_35 , V_430 ) ;
}
static unsigned F_330 ( struct V_260 * V_260 )
{
unsigned V_433 = 0 ;
unsigned V_434 = 0 ;
F_30 ( ! F_232 ( V_260 ) -> V_435 ) ;
F_232 ( V_260 ) -> V_435 -- ;
if ( F_232 ( V_260 ) -> V_435 == 0 &&
F_331 ( V_436 ,
& F_232 ( V_260 ) -> V_437 ) )
V_433 = 1 ;
if ( F_232 ( V_260 ) -> V_435 >=
F_232 ( V_260 ) -> V_438 )
return V_433 ;
V_434 = F_232 ( V_260 ) -> V_438 -
F_232 ( V_260 ) -> V_435 ;
F_232 ( V_260 ) -> V_438 -= V_434 ;
return V_434 + V_433 ;
}
static T_2 F_332 ( struct V_260 * V_260 , T_2 V_36 ,
int V_439 )
{
struct V_34 * V_35 = F_232 ( V_260 ) -> V_35 ;
T_2 V_423 ;
int V_440 ;
int V_441 ;
int V_442 ;
if ( F_232 ( V_260 ) -> V_7 & V_443 &&
F_232 ( V_260 ) -> V_444 == 0 )
return 0 ;
V_442 = ( int ) F_180 ( F_232 ( V_260 ) -> V_444 , V_35 -> V_337 ) ;
if ( V_439 )
F_232 ( V_260 ) -> V_444 += V_36 ;
else
F_232 ( V_260 ) -> V_444 -= V_36 ;
V_423 = F_191 ( V_35 ) - sizeof( struct V_445 ) ;
V_440 = ( int ) F_180 ( V_423 ,
sizeof( struct V_446 ) +
sizeof( struct V_447 ) ) ;
V_441 = ( int ) F_180 ( F_232 ( V_260 ) -> V_444 , V_35 -> V_337 ) ;
V_441 = V_441 + V_440 - 1 ;
V_441 = V_441 / V_440 ;
V_442 = V_442 + V_440 - 1 ;
V_442 = V_442 / V_440 ;
if ( V_442 == V_441 )
return 0 ;
if ( V_439 )
return F_193 ( V_35 ,
V_441 - V_442 ) ;
return F_193 ( V_35 , V_442 - V_441 ) ;
}
int F_333 ( struct V_260 * V_260 , T_2 V_36 )
{
struct V_34 * V_35 = F_232 ( V_260 ) -> V_35 ;
struct V_237 * V_376 = & V_35 -> V_37 -> V_383 ;
T_2 V_448 = 0 ;
T_2 V_444 ;
unsigned V_449 = 0 ;
int V_450 = 0 ;
enum V_361 V_304 = V_367 ;
int V_29 = 0 ;
bool V_451 = true ;
T_2 V_452 = 0 ;
unsigned V_453 ;
if ( F_264 ( V_260 ) ) {
V_304 = V_388 ;
V_451 = false ;
}
if ( V_304 != V_388 &&
F_334 ( V_35 -> V_37 ) )
F_335 ( 1 ) ;
if ( V_451 )
F_35 ( & F_232 ( V_260 ) -> V_454 ) ;
V_36 = F_263 ( V_36 , V_35 -> V_337 ) ;
F_11 ( & F_232 ( V_260 ) -> V_52 ) ;
F_232 ( V_260 ) -> V_435 ++ ;
if ( F_232 ( V_260 ) -> V_435 >
F_232 ( V_260 ) -> V_438 )
V_449 = F_232 ( V_260 ) -> V_435 -
F_232 ( V_260 ) -> V_438 ;
if ( ! F_336 ( V_436 ,
& F_232 ( V_260 ) -> V_437 ) ) {
V_449 ++ ;
V_450 = 1 ;
}
V_448 = F_193 ( V_35 , V_449 ) ;
V_448 += F_332 ( V_260 , V_36 , 1 ) ;
V_444 = F_232 ( V_260 ) -> V_444 ;
F_13 ( & F_232 ( V_260 ) -> V_52 ) ;
if ( V_35 -> V_37 -> V_432 ) {
V_29 = F_327 ( V_35 , V_36 +
V_449 * V_35 -> V_88 ) ;
if ( V_29 )
goto V_455;
}
V_29 = F_298 ( V_35 , V_376 , V_448 , V_304 ) ;
if ( F_300 ( V_29 ) ) {
if ( V_35 -> V_37 -> V_432 )
F_328 ( V_35 , V_36 +
V_449 * V_35 -> V_88 ) ;
goto V_455;
}
F_11 ( & F_232 ( V_260 ) -> V_52 ) ;
if ( V_450 ) {
F_337 ( V_436 ,
& F_232 ( V_260 ) -> V_437 ) ;
V_449 -- ;
}
F_232 ( V_260 ) -> V_438 += V_449 ;
F_13 ( & F_232 ( V_260 ) -> V_52 ) ;
if ( V_451 )
F_46 ( & F_232 ( V_260 ) -> V_454 ) ;
if ( V_448 )
F_270 ( V_35 -> V_37 , L_17 ,
F_324 ( V_260 ) , V_448 , 1 ) ;
F_304 ( V_376 , V_448 , 1 ) ;
return 0 ;
V_455:
F_11 ( & F_232 ( V_260 ) -> V_52 ) ;
V_453 = F_330 ( V_260 ) ;
if ( F_232 ( V_260 ) -> V_444 == V_444 ) {
F_332 ( V_260 , V_36 , 0 ) ;
} else {
T_2 V_456 = F_232 ( V_260 ) -> V_444 ;
T_2 V_333 ;
V_333 = V_444 - F_232 ( V_260 ) -> V_444 ;
F_232 ( V_260 ) -> V_444 = V_444 ;
V_452 = F_332 ( V_260 , V_333 , 0 ) ;
F_232 ( V_260 ) -> V_444 = V_444 - V_36 ;
V_333 = V_444 - V_456 ;
V_333 = F_332 ( V_260 , V_333 , 0 ) ;
F_232 ( V_260 ) -> V_444 = V_456 - V_36 ;
if ( V_333 > V_452 )
V_452 = V_333 - V_452 ;
else
V_452 = 0 ;
}
F_13 ( & F_232 ( V_260 ) -> V_52 ) ;
if ( V_453 )
V_452 += F_193 ( V_35 , V_453 ) ;
if ( V_452 ) {
F_312 ( V_35 , V_376 , V_452 ) ;
F_270 ( V_35 -> V_37 , L_17 ,
F_324 ( V_260 ) , V_452 , 0 ) ;
}
if ( V_451 )
F_46 ( & F_232 ( V_260 ) -> V_454 ) ;
return V_29 ;
}
void F_338 ( struct V_260 * V_260 , T_2 V_36 )
{
struct V_34 * V_35 = F_232 ( V_260 ) -> V_35 ;
T_2 V_452 = 0 ;
unsigned V_453 ;
V_36 = F_263 ( V_36 , V_35 -> V_337 ) ;
F_11 ( & F_232 ( V_260 ) -> V_52 ) ;
V_453 = F_330 ( V_260 ) ;
if ( V_36 )
V_452 = F_332 ( V_260 , V_36 , 0 ) ;
F_13 ( & F_232 ( V_260 ) -> V_52 ) ;
if ( V_453 > 0 )
V_452 += F_193 ( V_35 , V_453 ) ;
F_270 ( V_35 -> V_37 , L_17 ,
F_324 ( V_260 ) , V_452 , 0 ) ;
if ( V_35 -> V_37 -> V_432 ) {
F_328 ( V_35 , V_36 +
V_453 * V_35 -> V_88 ) ;
}
F_312 ( V_35 , & V_35 -> V_37 -> V_383 ,
V_452 ) ;
}
int F_339 ( struct V_260 * V_260 , T_2 V_36 )
{
int V_29 ;
V_29 = F_237 ( V_260 , V_36 ) ;
if ( V_29 )
return V_29 ;
V_29 = F_333 ( V_260 , V_36 ) ;
if ( V_29 ) {
F_239 ( V_260 , V_36 ) ;
return V_29 ;
}
return 0 ;
}
void F_340 ( struct V_260 * V_260 , T_2 V_36 )
{
F_338 ( V_260 , V_36 ) ;
F_239 ( V_260 , V_36 ) ;
}
static int F_341 ( struct V_34 * V_35 ,
T_2 V_27 , T_2 V_36 , int V_340 )
{
struct V_1 * V_2 = NULL ;
struct V_12 * V_13 = V_35 -> V_37 ;
T_2 V_457 = V_36 ;
T_2 V_458 ;
T_2 V_459 ;
int V_285 ;
F_11 ( & V_13 -> V_460 ) ;
V_458 = F_342 ( V_13 -> V_352 ) ;
if ( V_340 )
V_458 += V_36 ;
else
V_458 -= V_36 ;
F_343 ( V_13 -> V_352 , V_458 ) ;
F_13 ( & V_13 -> V_460 ) ;
while ( V_457 ) {
V_2 = F_67 ( V_13 , V_27 ) ;
if ( ! V_2 )
return - V_152 ;
if ( V_2 -> V_7 & ( V_286 |
V_287 |
V_288 ) )
V_285 = 2 ;
else
V_285 = 1 ;
if ( ! V_340 && V_2 -> V_3 == V_95 )
F_51 ( V_2 , 1 ) ;
V_459 = V_27 - V_2 -> V_21 . V_22 ;
F_8 ( V_459 > V_2 -> V_21 . V_33 ) ;
F_11 ( & V_2 -> V_104 -> V_52 ) ;
F_11 ( & V_2 -> V_52 ) ;
if ( F_236 ( V_35 , V_274 ) &&
V_2 -> V_266 < V_276 )
V_2 -> V_266 = V_276 ;
V_2 -> V_277 = 1 ;
V_458 = F_344 ( & V_2 -> V_134 ) ;
V_36 = F_292 ( V_457 , V_2 -> V_21 . V_33 - V_459 ) ;
if ( V_340 ) {
V_458 += V_36 ;
F_345 ( & V_2 -> V_134 , V_458 ) ;
V_2 -> V_10 -= V_36 ;
V_2 -> V_104 -> V_298 -= V_36 ;
V_2 -> V_104 -> V_284 += V_36 ;
V_2 -> V_104 -> V_290 += V_36 * V_285 ;
F_13 ( & V_2 -> V_52 ) ;
F_13 ( & V_2 -> V_104 -> V_52 ) ;
} else {
V_458 -= V_36 ;
F_345 ( & V_2 -> V_134 , V_458 ) ;
V_2 -> V_9 += V_36 ;
V_2 -> V_104 -> V_297 += V_36 ;
V_2 -> V_104 -> V_284 -= V_36 ;
V_2 -> V_104 -> V_290 -= V_36 * V_285 ;
F_13 ( & V_2 -> V_52 ) ;
F_13 ( & V_2 -> V_104 -> V_52 ) ;
F_346 ( V_13 -> V_59 ,
V_27 , V_27 + V_36 - 1 ,
V_40 | V_461 ) ;
}
F_6 ( V_2 ) ;
V_457 -= V_36 ;
V_27 += V_36 ;
}
return 0 ;
}
static T_2 V_26 ( struct V_34 * V_35 , T_2 V_462 )
{
struct V_1 * V_2 ;
T_2 V_27 ;
F_11 ( & V_35 -> V_37 -> V_18 ) ;
V_27 = V_35 -> V_37 -> V_26 ;
F_13 ( & V_35 -> V_37 -> V_18 ) ;
if ( V_27 < ( T_2 ) - 1 )
return V_27 ;
V_2 = F_66 ( V_35 -> V_37 , V_462 ) ;
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
V_2 -> V_104 -> V_297 += V_36 ;
if ( V_10 ) {
V_2 -> V_10 -= V_36 ;
V_2 -> V_104 -> V_298 -= V_36 ;
}
F_13 ( & V_2 -> V_52 ) ;
F_13 ( & V_2 -> V_104 -> V_52 ) ;
F_346 ( V_35 -> V_37 -> V_59 , V_27 ,
V_27 + V_36 - 1 , V_40 | V_461 ) ;
if ( V_10 )
F_348 ( V_35 , V_27 , V_36 ) ;
return 0 ;
}
int F_160 ( struct V_34 * V_35 ,
T_2 V_27 , T_2 V_36 , int V_10 )
{
struct V_1 * V_2 ;
V_2 = F_67 ( V_35 -> V_37 , V_27 ) ;
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
V_2 = F_67 ( V_35 -> V_37 , V_27 ) ;
if ( ! V_2 )
return - V_463 ;
F_51 ( V_2 , 1 ) ;
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
V_14 = F_67 ( V_35 -> V_37 , V_32 ) ;
if ( ! V_14 )
return - V_463 ;
F_51 ( V_14 , 0 ) ;
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
goto V_464;
V_36 = ( V_32 + V_36 ) -
V_54 -> V_85 ;
V_32 = V_54 -> V_85 ;
V_29 = F_17 ( V_35 , V_32 , V_36 ) ;
}
V_464:
F_46 ( & V_54 -> V_79 ) ;
F_26 ( V_54 ) ;
}
F_6 ( V_14 ) ;
return V_29 ;
}
int F_352 ( struct V_34 * log ,
struct V_66 * V_465 )
{
struct V_254 * V_134 ;
struct V_68 V_21 ;
int V_466 ;
int V_43 ;
if ( ! F_75 ( log -> V_37 , V_467 ) )
return 0 ;
for ( V_43 = 0 ; V_43 < F_38 ( V_465 ) ; V_43 ++ ) {
F_40 ( V_465 , & V_21 , V_43 ) ;
if ( V_21 . type != V_258 )
continue;
V_134 = F_77 ( V_465 , V_43 , struct V_254 ) ;
V_466 = F_214 ( V_465 , V_134 ) ;
if ( V_466 == V_259 )
continue;
if ( F_215 ( V_465 , V_134 ) == 0 )
continue;
V_21 . V_22 = F_215 ( V_465 , V_134 ) ;
V_21 . V_33 = F_216 ( V_465 , V_134 ) ;
F_351 ( log , V_21 . V_22 , V_21 . V_33 ) ;
}
return 0 ;
}
static int F_353 ( struct V_1 * V_2 ,
T_2 V_36 , int V_439 )
{
struct V_101 * V_104 = V_2 -> V_104 ;
int V_29 = 0 ;
F_11 ( & V_104 -> V_52 ) ;
F_11 ( & V_2 -> V_52 ) ;
if ( V_439 != V_468 ) {
if ( V_2 -> V_268 ) {
V_29 = - V_176 ;
} else {
V_2 -> V_10 += V_36 ;
V_104 -> V_298 += V_36 ;
if ( V_439 == V_469 ) {
F_270 ( V_2 -> V_37 ,
L_13 , V_104 -> V_7 ,
V_36 , 0 ) ;
V_104 -> V_300 -= V_36 ;
}
}
} else {
if ( V_2 -> V_268 )
V_104 -> V_299 += V_36 ;
V_2 -> V_10 -= V_36 ;
V_104 -> V_298 -= V_36 ;
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
F_62 ( & V_37 -> V_80 ) ;
F_355 (caching_ctl, next,
&fs_info->caching_block_groups, list) {
V_2 = V_54 -> V_14 ;
if ( F_1 ( V_2 ) ) {
V_2 -> V_98 = ( T_2 ) - 1 ;
F_356 ( & V_54 -> V_91 ) ;
F_26 ( V_54 ) ;
} else {
V_2 -> V_98 = V_54 -> V_85 ;
}
}
if ( V_37 -> V_59 == & V_37 -> V_38 [ 0 ] )
V_37 -> V_59 = & V_37 -> V_38 [ 1 ] ;
else
V_37 -> V_59 = & V_37 -> V_38 [ 0 ] ;
F_64 ( & V_37 -> V_80 ) ;
F_70 (space_info, &fs_info->space_info, list)
F_357 ( & V_104 -> V_291 , 0 ) ;
F_319 ( V_37 ) ;
}
static int F_358 ( struct V_34 * V_35 , T_2 V_32 , T_2 V_31 )
{
struct V_12 * V_37 = V_35 -> V_37 ;
struct V_1 * V_2 = NULL ;
struct V_101 * V_104 ;
struct V_237 * V_238 = & V_37 -> V_239 ;
T_2 V_49 ;
bool V_279 ;
while ( V_32 <= V_31 ) {
V_279 = false ;
if ( ! V_2 ||
V_32 >= V_2 -> V_21 . V_22 + V_2 -> V_21 . V_33 ) {
if ( V_2 )
F_6 ( V_2 ) ;
V_2 = F_67 ( V_37 , V_32 ) ;
F_30 ( ! V_2 ) ;
}
V_49 = V_2 -> V_21 . V_22 + V_2 -> V_21 . V_33 - V_32 ;
V_49 = F_292 ( V_49 , V_31 + 1 - V_32 ) ;
if ( V_32 < V_2 -> V_98 ) {
V_49 = F_292 ( V_49 , V_2 -> V_98 - V_32 ) ;
F_29 ( V_2 , V_32 , V_49 ) ;
}
V_32 += V_49 ;
V_104 = V_2 -> V_104 ;
F_11 ( & V_104 -> V_52 ) ;
F_11 ( & V_2 -> V_52 ) ;
V_2 -> V_9 -= V_49 ;
V_104 -> V_297 -= V_49 ;
if ( V_2 -> V_268 ) {
V_104 -> V_299 += V_49 ;
V_279 = true ;
}
F_13 ( & V_2 -> V_52 ) ;
if ( ! V_279 && V_238 -> V_104 == V_104 ) {
F_11 ( & V_238 -> V_52 ) ;
if ( ! V_238 -> V_107 ) {
V_49 = F_292 ( V_49 , V_238 -> V_57 -
V_238 -> V_10 ) ;
V_238 -> V_10 += V_49 ;
V_104 -> V_300 += V_49 ;
if ( V_238 -> V_10 >= V_238 -> V_57 )
V_238 -> V_107 = 1 ;
}
F_13 ( & V_238 -> V_52 ) ;
}
F_13 ( & V_104 -> V_52 ) ;
}
if ( V_2 )
F_6 ( V_2 ) ;
return 0 ;
}
int F_359 ( struct V_108 * V_109 ,
struct V_34 * V_35 )
{
struct V_12 * V_37 = V_35 -> V_37 ;
struct V_470 * V_471 ;
T_2 V_32 ;
T_2 V_31 ;
int V_29 ;
if ( V_109 -> V_211 )
return 0 ;
if ( V_37 -> V_59 == & V_37 -> V_38 [ 0 ] )
V_471 = & V_37 -> V_38 [ 1 ] ;
else
V_471 = & V_37 -> V_38 [ 0 ] ;
while ( 1 ) {
V_29 = F_28 ( V_471 , 0 , & V_32 , & V_31 ,
V_60 , NULL ) ;
if ( V_29 )
break;
if ( F_236 ( V_35 , V_472 ) )
V_29 = F_141 ( V_35 , V_32 ,
V_31 + 1 - V_32 , NULL ) ;
F_360 ( V_471 , V_32 , V_31 , V_40 ) ;
F_358 ( V_35 , V_32 , V_31 ) ;
F_47 () ;
}
return 0 ;
}
static void F_361 ( struct V_12 * V_37 , T_2 V_36 ,
T_2 V_132 , T_2 V_145 )
{
struct V_101 * V_104 ;
T_2 V_7 ;
if ( V_132 < V_142 ) {
if ( V_145 == V_473 )
V_7 = V_282 ;
else
V_7 = V_280 ;
} else {
V_7 = V_281 ;
}
V_104 = F_68 ( V_37 , V_7 ) ;
F_30 ( ! V_104 ) ;
F_362 ( & V_104 -> V_291 , V_36 ) ;
}
static int F_152 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
T_2 V_27 , T_2 V_36 , T_2 V_17 ,
T_2 V_145 , T_2 V_474 ,
T_2 V_475 , int V_158 ,
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
int V_476 = 0 ;
int V_477 = 0 ;
int V_478 = 1 ;
T_3 V_117 ;
T_2 V_111 ;
bool V_171 = F_75 ( V_35 -> V_37 ,
V_120 ) ;
V_65 = F_33 () ;
if ( ! V_65 )
return - V_72 ;
V_65 -> V_76 = 1 ;
V_65 -> V_202 = 1 ;
V_182 = V_474 >= V_142 ;
F_30 ( ! V_182 && V_158 != 1 ) ;
if ( V_182 )
V_171 = 0 ;
V_29 = F_133 ( V_109 , V_63 , V_65 , & V_162 ,
V_27 , V_36 , V_17 ,
V_145 , V_474 ,
V_475 ) ;
if ( V_29 == 0 ) {
V_476 = V_65 -> V_84 [ 0 ] ;
while ( V_476 >= 0 ) {
F_40 ( V_65 -> V_83 [ 0 ] , & V_21 ,
V_476 ) ;
if ( V_21 . V_22 != V_27 )
break;
if ( V_21 . type == V_77 &&
V_21 . V_33 == V_36 ) {
V_477 = 1 ;
break;
}
if ( V_21 . type == V_86 &&
V_21 . V_33 == V_474 ) {
V_477 = 1 ;
break;
}
if ( V_65 -> V_84 [ 0 ] - V_476 > 5 )
break;
V_476 -- ;
}
#ifdef F_80
V_117 = F_76 ( V_65 -> V_83 [ 0 ] , V_476 ) ;
if ( V_477 && V_117 < sizeof( * V_116 ) )
V_477 = 0 ;
#endif
if ( ! V_477 ) {
F_30 ( V_162 ) ;
V_29 = F_138 ( V_109 , V_63 , V_65 ,
NULL , V_158 ,
V_182 ) ;
if ( V_29 ) {
F_147 ( V_109 , V_63 , V_29 ) ;
goto V_73;
}
F_44 ( V_65 ) ;
V_65 -> V_202 = 1 ;
V_21 . V_22 = V_27 ;
V_21 . type = V_77 ;
V_21 . V_33 = V_36 ;
if ( ! V_182 && V_171 ) {
V_21 . type = V_86 ;
V_21 . V_33 = V_474 ;
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
F_44 ( V_65 ) ;
V_29 = F_37 ( V_109 , V_63 ,
& V_21 , V_65 , - 1 , 1 ) ;
}
if ( V_29 ) {
F_185 ( V_13 , L_18 ,
V_29 , V_27 ) ;
if ( V_29 > 0 )
F_363 ( V_63 ,
V_65 -> V_83 [ 0 ] ) ;
}
if ( V_29 < 0 ) {
F_147 ( V_109 , V_63 , V_29 ) ;
goto V_73;
}
V_476 = V_65 -> V_84 [ 0 ] ;
}
} else if ( F_8 ( V_29 == - V_152 ) ) {
F_363 ( V_63 , V_65 -> V_83 [ 0 ] ) ;
F_185 ( V_13 ,
L_19 ,
V_27 , V_17 , V_145 , V_474 ,
V_475 ) ;
} else {
F_147 ( V_109 , V_63 , V_29 ) ;
goto V_73;
}
V_67 = V_65 -> V_83 [ 0 ] ;
V_117 = F_76 ( V_67 , V_476 ) ;
#ifdef F_80
if ( V_117 < sizeof( * V_116 ) ) {
F_30 ( V_477 || V_476 != V_65 -> V_84 [ 0 ] ) ;
V_29 = F_86 ( V_109 , V_63 , V_65 ,
V_474 , 0 ) ;
if ( V_29 < 0 ) {
F_147 ( V_109 , V_63 , V_29 ) ;
goto V_73;
}
F_44 ( V_65 ) ;
V_65 -> V_202 = 1 ;
V_21 . V_22 = V_27 ;
V_21 . type = V_77 ;
V_21 . V_33 = V_36 ;
V_29 = F_37 ( V_109 , V_63 , & V_21 , V_65 ,
- 1 , 1 ) ;
if ( V_29 ) {
F_185 ( V_13 , L_18 ,
V_29 , V_27 ) ;
F_363 ( V_63 , V_65 -> V_83 [ 0 ] ) ;
}
if ( V_29 < 0 ) {
F_147 ( V_109 , V_63 , V_29 ) ;
goto V_73;
}
V_476 = V_65 -> V_84 [ 0 ] ;
V_67 = V_65 -> V_83 [ 0 ] ;
V_117 = F_76 ( V_67 , V_476 ) ;
}
#endif
F_30 ( V_117 < sizeof( * V_116 ) ) ;
V_116 = F_77 ( V_67 , V_476 ,
struct V_115 ) ;
if ( V_474 < V_142 &&
V_21 . type == V_77 ) {
struct V_137 * V_138 ;
F_30 ( V_117 < sizeof( * V_116 ) + sizeof( * V_138 ) ) ;
V_138 = (struct V_137 * ) ( V_116 + 1 ) ;
F_8 ( V_474 != F_364 ( V_67 , V_138 ) ) ;
}
V_111 = F_78 ( V_67 , V_116 ) ;
if ( V_111 < V_158 ) {
F_185 ( V_13 , L_20
L_21 , V_158 , V_111 , V_27 ) ;
V_29 = - V_463 ;
F_147 ( V_109 , V_63 , V_29 ) ;
goto V_73;
}
V_111 -= V_158 ;
if ( V_111 > 0 ) {
if ( V_128 )
F_129 ( V_128 , V_67 , V_116 ) ;
if ( V_162 ) {
F_30 ( ! V_477 ) ;
} else {
F_89 ( V_67 , V_116 , V_111 ) ;
F_94 ( V_67 ) ;
}
if ( V_477 ) {
V_29 = F_138 ( V_109 , V_63 , V_65 ,
V_162 , V_158 ,
V_182 ) ;
if ( V_29 ) {
F_147 ( V_109 , V_63 , V_29 ) ;
goto V_73;
}
}
F_361 ( V_35 -> V_37 , - V_36 , V_474 ,
V_145 ) ;
} else {
if ( V_477 ) {
F_30 ( V_182 && V_158 !=
F_117 ( V_35 , V_65 , V_162 ) ) ;
if ( V_162 ) {
F_30 ( V_65 -> V_84 [ 0 ] != V_476 ) ;
} else {
F_30 ( V_65 -> V_84 [ 0 ] != V_476 + 1 ) ;
V_65 -> V_84 [ 0 ] = V_476 ;
V_478 = 2 ;
}
}
V_29 = F_365 ( V_109 , V_63 , V_65 , V_65 -> V_84 [ 0 ] ,
V_478 ) ;
if ( V_29 ) {
F_147 ( V_109 , V_63 , V_29 ) ;
goto V_73;
}
F_44 ( V_65 ) ;
if ( V_182 ) {
V_29 = F_164 ( V_109 , V_35 , V_27 , V_36 ) ;
if ( V_29 ) {
F_147 ( V_109 , V_63 , V_29 ) ;
goto V_73;
}
}
V_29 = F_341 ( V_35 , V_27 , V_36 , 0 ) ;
if ( V_29 ) {
F_147 ( V_109 , V_63 , V_29 ) ;
goto V_73;
}
}
V_73:
F_50 ( V_65 ) ;
return V_29 ;
}
static T_1 int F_366 ( struct V_108 * V_109 ,
struct V_34 * V_35 , T_2 V_27 )
{
struct V_112 * V_103 ;
struct V_113 * V_114 ;
int V_29 = 0 ;
V_114 = & V_109 -> V_126 -> V_114 ;
F_11 ( & V_114 -> V_52 ) ;
V_103 = F_83 ( V_109 , V_27 ) ;
if ( ! V_103 )
goto V_479;
F_11 ( & V_103 -> V_52 ) ;
if ( F_175 ( & V_103 -> V_207 ) )
goto V_73;
if ( V_103 -> V_128 ) {
if ( ! V_103 -> V_215 )
goto V_73;
F_173 ( V_103 -> V_128 ) ;
V_103 -> V_128 = NULL ;
}
if ( ! F_84 ( & V_103 -> V_79 ) )
goto V_73;
V_103 -> V_127 . V_219 = 0 ;
F_176 ( & V_103 -> V_221 , & V_114 -> V_222 ) ;
F_177 ( & V_114 -> V_223 ) ;
V_114 -> V_220 -- ;
if ( V_103 -> V_217 == 0 )
V_114 -> V_218 -- ;
V_103 -> V_217 = 0 ;
F_13 ( & V_103 -> V_52 ) ;
F_13 ( & V_114 -> V_52 ) ;
F_30 ( V_103 -> V_128 ) ;
if ( V_103 -> V_215 )
V_29 = 1 ;
F_46 ( & V_103 -> V_79 ) ;
F_85 ( & V_103 -> V_127 ) ;
return V_29 ;
V_73:
F_13 ( & V_103 -> V_52 ) ;
V_479:
F_13 ( & V_114 -> V_52 ) ;
return 0 ;
}
void F_367 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
struct V_66 * V_251 ,
T_2 V_17 , int V_480 )
{
struct V_1 * V_2 = NULL ;
int V_481 = 1 ;
int V_29 ;
if ( V_35 -> V_247 . V_22 != V_200 ) {
V_29 = F_144 ( V_35 -> V_37 , V_109 ,
V_251 -> V_32 , V_251 -> V_49 ,
V_17 , V_35 -> V_247 . V_22 ,
F_212 ( V_251 ) ,
V_209 , NULL , 0 ) ;
F_30 ( V_29 ) ;
}
if ( ! V_480 )
return;
V_2 = F_67 ( V_35 -> V_37 , V_251 -> V_32 ) ;
if ( F_368 ( V_251 ) == V_109 -> V_270 ) {
if ( V_35 -> V_247 . V_22 != V_200 ) {
V_29 = F_366 ( V_109 , V_35 , V_251 -> V_32 ) ;
if ( ! V_29 )
goto V_73;
}
if ( F_369 ( V_251 , V_482 ) ) {
F_347 ( V_35 , V_2 , V_251 -> V_32 , V_251 -> V_49 , 1 ) ;
goto V_73;
}
F_8 ( F_336 ( V_483 , & V_251 -> V_484 ) ) ;
F_29 ( V_2 , V_251 -> V_32 , V_251 -> V_49 ) ;
F_353 ( V_2 , V_251 -> V_49 , V_468 ) ;
F_348 ( V_35 , V_251 -> V_32 , V_251 -> V_49 ) ;
V_481 = 0 ;
}
V_73:
if ( V_481 )
F_361 ( V_35 -> V_37 , V_251 -> V_49 ,
F_212 ( V_251 ) ,
V_35 -> V_247 . V_22 ) ;
F_370 ( V_485 , & V_251 -> V_484 ) ;
F_6 ( V_2 ) ;
}
int V_257 ( struct V_108 * V_109 , struct V_34 * V_35 ,
T_2 V_27 , T_2 V_36 , T_2 V_17 , T_2 V_145 ,
T_2 V_132 , T_2 V_33 , int V_199 )
{
int V_29 ;
struct V_12 * V_37 = V_35 -> V_37 ;
F_361 ( V_35 -> V_37 , V_36 , V_132 , V_145 ) ;
if ( V_145 == V_200 ) {
F_8 ( V_132 >= V_142 ) ;
F_160 ( V_35 , V_27 , V_36 , 1 ) ;
V_29 = 0 ;
} else if ( V_132 < V_142 ) {
V_29 = F_144 ( V_37 , V_109 , V_27 ,
V_36 ,
V_17 , V_145 , ( int ) V_132 ,
V_209 , NULL , V_199 ) ;
} else {
V_29 = F_145 ( V_37 , V_109 , V_27 ,
V_36 ,
V_17 , V_145 , V_132 ,
V_33 , V_209 ,
NULL , V_199 ) ;
}
return V_29 ;
}
static T_2 F_371 ( struct V_34 * V_35 ,
struct V_1 * V_2 ,
T_2 V_486 , T_2 V_36 )
{
T_2 V_29 = F_263 ( V_486 , V_35 -> V_487 ) ;
return V_29 ;
}
static T_1 void
F_372 ( struct V_1 * V_2 ,
T_2 V_36 )
{
struct V_50 * V_54 ;
V_54 = F_25 ( V_2 ) ;
if ( ! V_54 )
return;
F_293 ( V_54 -> V_89 , F_1 ( V_2 ) ||
( V_2 -> V_11 -> V_488 >= V_36 ) ) ;
F_26 ( V_54 ) ;
}
static T_1 int
F_373 ( struct V_1 * V_2 )
{
struct V_50 * V_54 ;
int V_29 = 0 ;
V_54 = F_25 ( V_2 ) ;
if ( ! V_54 )
return ( V_2 -> V_3 == V_5 ) ? - V_173 : 0 ;
F_293 ( V_54 -> V_89 , F_1 ( V_2 ) ) ;
if ( V_2 -> V_3 == V_5 )
V_29 = - V_173 ;
F_26 ( V_54 ) ;
return V_29 ;
}
int F_374 ( T_2 V_7 )
{
if ( V_7 & V_288 )
return V_489 ;
else if ( V_7 & V_287 )
return V_490 ;
else if ( V_7 & V_286 )
return V_491 ;
else if ( V_7 & V_329 )
return V_492 ;
else if ( V_7 & V_330 )
return V_493 ;
else if ( V_7 & V_331 )
return V_494 ;
return V_495 ;
}
int F_375 ( struct V_1 * V_2 )
{
return F_374 ( V_2 -> V_7 ) ;
}
static const char * F_376 ( enum V_496 type )
{
if ( type >= V_292 )
return NULL ;
return V_497 [ type ] ;
}
static T_1 int F_377 ( struct V_34 * V_498 ,
T_2 V_36 , T_2 V_499 ,
T_2 V_500 , struct V_68 * V_206 ,
T_2 V_7 )
{
int V_29 = 0 ;
struct V_34 * V_35 = V_498 -> V_37 -> V_63 ;
struct V_501 * V_502 = NULL ;
struct V_1 * V_14 = NULL ;
T_2 V_462 = 0 ;
T_2 V_503 = 0 ;
int V_504 = 2 * 1024 * 1024 ;
struct V_101 * V_104 ;
int V_505 = 0 ;
int V_506 = F_374 ( V_7 ) ;
int V_507 = ( V_7 & V_281 ) ?
V_508 : V_469 ;
bool V_509 = false ;
bool V_510 = false ;
bool V_511 = true ;
bool V_512 = false ;
F_8 ( V_36 < V_35 -> V_337 ) ;
F_378 ( V_206 , V_77 ) ;
V_206 -> V_22 = 0 ;
V_206 -> V_33 = 0 ;
F_379 ( V_498 , V_36 , V_499 , V_7 ) ;
V_104 = F_68 ( V_35 -> V_37 , V_7 ) ;
if ( ! V_104 ) {
F_185 ( V_35 -> V_37 , L_22 , V_7 ) ;
return - V_343 ;
}
if ( F_282 ( V_104 ) )
V_511 = false ;
if ( V_7 & V_280 && V_511 ) {
V_502 = & V_35 -> V_37 -> V_513 ;
if ( ! F_236 ( V_35 , V_514 ) )
V_504 = 64 * 1024 ;
}
if ( ( V_7 & V_281 ) && V_511 &&
F_236 ( V_35 , V_514 ) ) {
V_502 = & V_35 -> V_37 -> V_515 ;
}
if ( V_502 ) {
F_11 ( & V_502 -> V_52 ) ;
if ( V_502 -> V_14 )
V_500 = V_502 -> V_516 ;
F_13 ( & V_502 -> V_52 ) ;
}
V_462 = F_380 ( V_462 , V_26 ( V_35 , 0 ) ) ;
V_462 = F_380 ( V_462 , V_500 ) ;
if ( ! V_502 )
V_504 = 0 ;
if ( V_462 == V_500 ) {
V_14 = F_67 ( V_35 -> V_37 ,
V_462 ) ;
if ( V_14 && F_3 ( V_14 , V_7 ) &&
V_14 -> V_3 != V_95 ) {
F_36 ( & V_104 -> V_296 ) ;
if ( F_184 ( & V_14 -> V_91 ) ||
V_14 -> V_268 ) {
F_6 ( V_14 ) ;
F_45 ( & V_104 -> V_296 ) ;
} else {
V_506 = F_375 ( V_14 ) ;
goto V_517;
}
} else if ( V_14 ) {
F_6 ( V_14 ) ;
}
}
V_518:
V_512 = false ;
F_36 ( & V_104 -> V_296 ) ;
F_381 (block_group, &space_info->block_groups[index],
list) {
T_2 V_33 ;
int V_3 ;
F_4 ( V_14 ) ;
V_462 = V_14 -> V_21 . V_22 ;
if ( ! F_3 ( V_14 , V_7 ) ) {
T_2 V_519 = V_286 |
V_287 |
V_330 |
V_331 |
V_288 ;
if ( ( V_7 & V_519 ) && ! ( V_14 -> V_7 & V_519 ) )
goto V_505;
}
V_517:
V_3 = F_1 ( V_14 ) ;
if ( F_300 ( ! V_3 ) ) {
V_29 = F_51 ( V_14 , 0 ) ;
F_30 ( V_29 < 0 ) ;
V_29 = 0 ;
}
if ( F_300 ( V_14 -> V_3 == V_5 ) )
goto V_505;
if ( F_300 ( V_14 -> V_268 ) )
goto V_505;
if ( V_502 ) {
struct V_1 * V_520 ;
unsigned long V_521 ;
F_11 ( & V_502 -> V_522 ) ;
V_520 = V_502 -> V_14 ;
if ( V_520 != V_14 &&
( ! V_520 ||
V_520 -> V_268 ||
! F_3 ( V_520 , V_7 ) ) )
goto V_523;
if ( V_520 != V_14 )
F_4 ( V_520 ) ;
V_33 = F_382 ( V_520 ,
V_502 ,
V_36 ,
V_520 -> V_21 . V_22 ,
& V_503 ) ;
if ( V_33 ) {
F_13 ( & V_502 -> V_522 ) ;
F_383 ( V_35 ,
V_520 ,
V_462 , V_36 ) ;
if ( V_520 != V_14 ) {
F_6 ( V_14 ) ;
V_14 = V_520 ;
}
goto V_524;
}
F_8 ( V_502 -> V_14 != V_520 ) ;
if ( V_520 != V_14 )
F_6 ( V_520 ) ;
V_523:
if ( V_505 >= V_525 &&
V_502 -> V_14 != V_14 ) {
F_13 ( & V_502 -> V_522 ) ;
goto V_526;
}
F_384 ( NULL , V_502 ) ;
if ( V_505 >= V_525 ) {
F_13 ( & V_502 -> V_522 ) ;
goto V_526;
}
V_521 = F_34 (unsigned long,
empty_cluster + empty_size,
block_group->full_stripe_len) ;
V_29 = F_385 ( V_35 , V_14 ,
V_502 , V_462 ,
V_36 ,
V_521 ) ;
if ( V_29 == 0 ) {
V_33 = F_382 ( V_14 ,
V_502 ,
V_36 ,
V_462 ,
& V_503 ) ;
if ( V_33 ) {
F_13 ( & V_502 -> V_522 ) ;
F_383 ( V_35 ,
V_14 , V_462 ,
V_36 ) ;
goto V_524;
}
} else if ( ! V_3 && V_505 > V_527
&& ! V_509 ) {
F_13 ( & V_502 -> V_522 ) ;
V_509 = true ;
F_372 ( V_14 ,
V_36 + V_504 + V_499 ) ;
goto V_517;
}
F_384 ( NULL , V_502 ) ;
F_13 ( & V_502 -> V_522 ) ;
goto V_505;
}
V_526:
F_11 ( & V_14 -> V_11 -> V_528 ) ;
if ( V_3 &&
V_14 -> V_11 -> V_488 <
V_36 + V_504 + V_499 ) {
if ( V_14 -> V_11 -> V_488 >
V_503 )
V_503 =
V_14 -> V_11 -> V_488 ;
F_13 ( & V_14 -> V_11 -> V_528 ) ;
goto V_505;
}
F_13 ( & V_14 -> V_11 -> V_528 ) ;
V_33 = F_386 ( V_14 , V_462 ,
V_36 , V_499 ,
& V_503 ) ;
if ( ! V_33 && ! V_510 && ! V_3 &&
V_505 > V_527 ) {
F_372 ( V_14 ,
V_36 + V_499 ) ;
V_510 = true ;
goto V_517;
} else if ( ! V_33 ) {
if ( ! V_3 )
V_512 = true ;
goto V_505;
}
V_524:
V_462 = F_371 ( V_35 , V_14 ,
V_33 , V_36 ) ;
if ( V_462 + V_36 >
V_14 -> V_21 . V_22 + V_14 -> V_21 . V_33 ) {
F_29 ( V_14 , V_33 , V_36 ) ;
goto V_505;
}
if ( V_33 < V_462 )
F_29 ( V_14 , V_33 ,
V_462 - V_33 ) ;
F_30 ( V_33 > V_462 ) ;
V_29 = F_353 ( V_14 , V_36 ,
V_507 ) ;
if ( V_29 == - V_176 ) {
F_29 ( V_14 , V_33 , V_36 ) ;
goto V_505;
}
V_206 -> V_22 = V_462 ;
V_206 -> V_33 = V_36 ;
F_387 ( V_498 , V_14 ,
V_462 , V_36 ) ;
F_6 ( V_14 ) ;
break;
V_505:
V_509 = false ;
V_510 = false ;
F_30 ( V_506 != F_375 ( V_14 ) ) ;
F_6 ( V_14 ) ;
}
F_45 ( & V_104 -> V_296 ) ;
if ( ! V_206 -> V_22 && V_505 >= V_529 && V_512 )
goto V_518;
if ( ! V_206 -> V_22 && ++ V_506 < V_292 )
goto V_518;
if ( ! V_206 -> V_22 && V_505 < V_525 ) {
V_506 = 0 ;
V_505 ++ ;
if ( V_505 == V_530 ) {
struct V_108 * V_109 ;
V_109 = F_265 ( V_35 ) ;
if ( F_228 ( V_109 ) ) {
V_29 = F_229 ( V_109 ) ;
goto V_73;
}
V_29 = F_266 ( V_109 , V_35 , V_7 ,
V_342 ) ;
if ( V_29 < 0 && V_29 != - V_343 )
F_147 ( V_109 ,
V_35 , V_29 ) ;
else
V_29 = 0 ;
F_267 ( V_109 , V_35 ) ;
if ( V_29 )
goto V_73;
}
if ( V_505 == V_525 ) {
V_499 = 0 ;
V_504 = 0 ;
}
goto V_518;
} else if ( ! V_206 -> V_22 ) {
V_29 = - V_343 ;
} else if ( V_206 -> V_22 ) {
V_29 = 0 ;
}
V_73:
if ( V_29 == - V_343 )
V_206 -> V_33 = V_503 ;
return V_29 ;
}
static void F_280 ( struct V_101 * V_13 , T_2 V_333 ,
int V_531 )
{
struct V_1 * V_2 ;
int V_506 = 0 ;
F_11 ( & V_13 -> V_52 ) ;
F_388 ( V_532 L_23 ,
V_13 -> V_7 ,
V_13 -> V_283 - V_13 -> V_284 - V_13 -> V_297 -
V_13 -> V_298 - V_13 -> V_299 ,
( V_13 -> V_107 ) ? L_4 : L_24 ) ;
F_388 ( V_532 L_25
L_26 ,
V_13 -> V_283 , V_13 -> V_284 , V_13 -> V_297 ,
V_13 -> V_298 , V_13 -> V_300 ,
V_13 -> V_299 ) ;
F_13 ( & V_13 -> V_52 ) ;
if ( ! V_531 )
return;
F_36 ( & V_13 -> V_296 ) ;
V_78:
F_381 (cache, &info->block_groups[index], list) {
F_11 ( & V_2 -> V_52 ) ;
F_388 ( V_532 L_27
L_28
L_29 ,
V_2 -> V_21 . V_22 , V_2 -> V_21 . V_33 ,
F_344 ( & V_2 -> V_134 ) , V_2 -> V_9 ,
V_2 -> V_10 , V_2 -> V_268 ? L_30 : L_4 ) ;
F_389 ( V_2 , V_333 ) ;
F_13 ( & V_2 -> V_52 ) ;
}
if ( ++ V_506 < V_292 )
goto V_78;
F_45 ( & V_13 -> V_296 ) ;
}
int F_390 ( struct V_34 * V_35 ,
T_2 V_36 , T_2 V_533 ,
T_2 V_499 , T_2 V_500 ,
struct V_68 * V_206 , int V_182 )
{
bool V_534 = false ;
T_2 V_7 ;
int V_29 ;
V_7 = F_262 ( V_35 , V_182 ) ;
V_78:
F_8 ( V_36 < V_35 -> V_337 ) ;
V_29 = F_377 ( V_35 , V_36 , V_499 , V_500 , V_206 ,
V_7 ) ;
if ( V_29 == - V_343 ) {
if ( ! V_534 && V_206 -> V_33 ) {
V_36 = F_292 ( V_36 >> 1 , V_206 -> V_33 ) ;
V_36 = F_391 ( V_36 , V_35 -> V_337 ) ;
V_36 = F_380 ( V_36 , V_533 ) ;
if ( V_36 == V_533 )
V_534 = true ;
goto V_78;
} else if ( F_236 ( V_35 , V_355 ) ) {
struct V_101 * V_347 ;
V_347 = F_68 ( V_35 -> V_37 , V_7 ) ;
F_185 ( V_35 -> V_37 , L_31 ,
V_7 , V_36 ) ;
if ( V_347 )
F_280 ( V_347 , V_36 , 1 ) ;
}
}
return V_29 ;
}
static int F_392 ( struct V_34 * V_35 ,
T_2 V_32 , T_2 V_49 , int V_481 )
{
struct V_1 * V_2 ;
int V_29 = 0 ;
V_2 = F_67 ( V_35 -> V_37 , V_32 ) ;
if ( ! V_2 ) {
F_185 ( V_35 -> V_37 , L_32 ,
V_32 ) ;
return - V_343 ;
}
if ( F_236 ( V_35 , V_472 ) )
V_29 = F_141 ( V_35 , V_32 , V_49 , NULL ) ;
if ( V_481 )
F_347 ( V_35 , V_2 , V_32 , V_49 , 1 ) ;
else {
F_29 ( V_2 , V_32 , V_49 ) ;
F_353 ( V_2 , V_49 , V_468 ) ;
}
F_6 ( V_2 ) ;
F_348 ( V_35 , V_32 , V_49 ) ;
return V_29 ;
}
int F_393 ( struct V_34 * V_35 ,
T_2 V_32 , T_2 V_49 )
{
return F_392 ( V_35 , V_32 , V_49 , 0 ) ;
}
int F_394 ( struct V_34 * V_35 ,
T_2 V_32 , T_2 V_49 )
{
return F_392 ( V_35 , V_32 , V_49 , 1 ) ;
}
static int F_151 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
T_2 V_17 , T_2 V_145 ,
T_2 V_7 , T_2 V_132 , T_2 V_33 ,
struct V_68 * V_206 , int V_131 )
{
int V_29 ;
struct V_12 * V_37 = V_35 -> V_37 ;
struct V_115 * V_535 ;
struct V_161 * V_162 ;
struct V_64 * V_65 ;
struct V_66 * V_67 ;
int type ;
T_3 V_57 ;
if ( V_17 > 0 )
type = V_153 ;
else
type = V_154 ;
V_57 = sizeof( * V_535 ) + F_124 ( type ) ;
V_65 = F_33 () ;
if ( ! V_65 )
return - V_72 ;
V_65 -> V_202 = 1 ;
V_29 = F_105 ( V_109 , V_37 -> V_63 , V_65 ,
V_206 , V_57 ) ;
if ( V_29 ) {
F_50 ( V_65 ) ;
return V_29 ;
}
V_67 = V_65 -> V_83 [ 0 ] ;
V_535 = F_77 ( V_67 , V_65 -> V_84 [ 0 ] ,
struct V_115 ) ;
F_89 ( V_67 , V_535 , V_131 ) ;
F_90 ( V_67 , V_535 , V_109 -> V_270 ) ;
F_91 ( V_67 , V_535 ,
V_7 | V_144 ) ;
V_162 = (struct V_161 * ) ( V_535 + 1 ) ;
F_131 ( V_67 , V_162 , type ) ;
if ( V_17 > 0 ) {
struct V_157 * V_150 ;
V_150 = (struct V_157 * ) ( V_162 + 1 ) ;
F_132 ( V_67 , V_162 , V_17 ) ;
F_106 ( V_67 , V_150 , V_131 ) ;
} else {
struct V_149 * V_150 ;
V_150 = (struct V_149 * ) ( & V_162 -> V_33 ) ;
F_108 ( V_67 , V_150 , V_145 ) ;
F_109 ( V_67 , V_150 , V_132 ) ;
F_110 ( V_67 , V_150 , V_33 ) ;
F_111 ( V_67 , V_150 , V_131 ) ;
}
F_94 ( V_65 -> V_83 [ 0 ] ) ;
F_50 ( V_65 ) ;
V_29 = F_341 ( V_35 , V_206 -> V_22 , V_206 -> V_33 , 1 ) ;
if ( V_29 ) {
F_185 ( V_37 , L_33 ,
V_206 -> V_22 , V_206 -> V_33 ) ;
F_82 () ;
}
F_395 ( V_35 , V_206 -> V_22 , V_206 -> V_33 ) ;
return V_29 ;
}
static int F_158 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
T_2 V_17 , T_2 V_145 ,
T_2 V_7 , struct V_447 * V_21 ,
int V_165 , struct V_68 * V_206 )
{
int V_29 ;
struct V_12 * V_37 = V_35 -> V_37 ;
struct V_115 * V_535 ;
struct V_137 * V_536 ;
struct V_161 * V_162 ;
struct V_64 * V_65 ;
struct V_66 * V_67 ;
T_3 V_57 = sizeof( * V_535 ) + sizeof( * V_162 ) ;
bool V_171 = F_75 ( V_35 -> V_37 ,
V_120 ) ;
if ( ! V_171 )
V_57 += sizeof( * V_536 ) ;
V_65 = F_33 () ;
if ( ! V_65 ) {
F_394 ( V_35 , V_206 -> V_22 ,
V_35 -> V_88 ) ;
return - V_72 ;
}
V_65 -> V_202 = 1 ;
V_29 = F_105 ( V_109 , V_37 -> V_63 , V_65 ,
V_206 , V_57 ) ;
if ( V_29 ) {
F_394 ( V_35 , V_206 -> V_22 ,
V_35 -> V_88 ) ;
F_50 ( V_65 ) ;
return V_29 ;
}
V_67 = V_65 -> V_83 [ 0 ] ;
V_535 = F_77 ( V_67 , V_65 -> V_84 [ 0 ] ,
struct V_115 ) ;
F_89 ( V_67 , V_535 , 1 ) ;
F_90 ( V_67 , V_535 , V_109 -> V_270 ) ;
F_91 ( V_67 , V_535 ,
V_7 | V_143 ) ;
if ( V_171 ) {
V_162 = (struct V_161 * ) ( V_535 + 1 ) ;
} else {
V_536 = (struct V_137 * ) ( V_535 + 1 ) ;
F_153 ( V_67 , V_536 , V_21 ) ;
F_93 ( V_67 , V_536 , V_165 ) ;
V_162 = (struct V_161 * ) ( V_536 + 1 ) ;
}
if ( V_17 > 0 ) {
F_30 ( ! ( V_7 & V_125 ) ) ;
F_131 ( V_67 , V_162 ,
V_163 ) ;
F_132 ( V_67 , V_162 , V_17 ) ;
} else {
F_131 ( V_67 , V_162 ,
V_164 ) ;
F_132 ( V_67 , V_162 , V_145 ) ;
}
F_94 ( V_67 ) ;
F_50 ( V_65 ) ;
V_29 = F_341 ( V_35 , V_206 -> V_22 , V_35 -> V_88 , 1 ) ;
if ( V_29 ) {
F_185 ( V_37 , L_33 ,
V_206 -> V_22 , V_206 -> V_33 ) ;
F_82 () ;
}
F_395 ( V_35 , V_206 -> V_22 , V_35 -> V_88 ) ;
return V_29 ;
}
int F_396 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
T_2 V_145 , T_2 V_132 ,
T_2 V_33 , struct V_68 * V_206 )
{
int V_29 ;
F_30 ( V_145 == V_200 ) ;
V_29 = F_145 ( V_35 -> V_37 , V_109 , V_206 -> V_22 ,
V_206 -> V_33 , 0 ,
V_145 , V_132 , V_33 ,
V_224 , NULL , 0 ) ;
return V_29 ;
}
int F_397 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
T_2 V_145 , T_2 V_132 , T_2 V_33 ,
struct V_68 * V_206 )
{
int V_29 ;
struct V_1 * V_14 ;
if ( ! F_75 ( V_35 -> V_37 , V_467 ) ) {
V_29 = F_351 ( V_35 , V_206 -> V_22 , V_206 -> V_33 ) ;
if ( V_29 )
return V_29 ;
}
V_14 = F_67 ( V_35 -> V_37 , V_206 -> V_22 ) ;
if ( ! V_14 )
return - V_463 ;
V_29 = F_353 ( V_14 , V_206 -> V_33 ,
V_508 ) ;
F_30 ( V_29 ) ;
V_29 = F_151 ( V_109 , V_35 , 0 , V_145 ,
0 , V_132 , V_33 , V_206 , 1 ) ;
F_6 ( V_14 ) ;
return V_29 ;
}
static struct V_66 *
F_398 ( struct V_108 * V_109 , struct V_34 * V_35 ,
T_2 V_27 , T_3 V_537 , int V_165 )
{
struct V_66 * V_251 ;
V_251 = F_399 ( V_35 , V_27 , V_537 ) ;
if ( ! V_251 )
return F_400 ( - V_72 ) ;
F_401 ( V_251 , V_109 -> V_270 ) ;
F_402 ( V_35 -> V_247 . V_22 , V_251 , V_165 ) ;
F_403 ( V_251 ) ;
F_404 ( V_109 , V_35 , V_251 ) ;
F_370 ( V_538 , & V_251 -> V_484 ) ;
F_405 ( V_251 ) ;
F_406 ( V_251 ) ;
if ( V_35 -> V_247 . V_22 == V_200 ) {
if ( V_35 -> V_539 % 2 == 0 )
F_346 ( & V_35 -> V_540 , V_251 -> V_32 ,
V_251 -> V_32 + V_251 -> V_49 - 1 , V_40 ) ;
else
F_407 ( & V_35 -> V_540 , V_251 -> V_32 ,
V_251 -> V_32 + V_251 -> V_49 - 1 , V_40 ) ;
} else {
F_346 ( & V_109 -> V_126 -> V_541 , V_251 -> V_32 ,
V_251 -> V_32 + V_251 -> V_49 - 1 , V_40 ) ;
}
V_109 -> V_542 ++ ;
return V_251 ;
}
static struct V_237 *
F_408 ( struct V_108 * V_109 ,
struct V_34 * V_35 , T_3 V_537 )
{
struct V_237 * V_376 ;
struct V_237 * V_238 = & V_35 -> V_37 -> V_239 ;
int V_29 ;
bool V_543 = false ;
V_376 = F_303 ( V_109 , V_35 ) ;
if ( F_300 ( V_376 -> V_57 == 0 ) )
goto V_544;
V_78:
V_29 = F_301 ( V_376 , V_537 ) ;
if ( ! V_29 )
return V_376 ;
if ( V_376 -> V_545 )
return F_400 ( V_29 ) ;
if ( V_376 -> type == V_546 && ! V_543 ) {
V_543 = true ;
F_319 ( V_35 -> V_37 ) ;
goto V_78;
}
if ( F_236 ( V_35 , V_355 ) ) {
static F_409 ( V_547 ,
V_548 * 10 ,
1 ) ;
if ( F_410 ( & V_547 ) )
F_411 ( 1 , V_549
L_34 , V_29 ) ;
}
V_544:
V_29 = F_298 ( V_35 , V_376 , V_537 ,
V_388 ) ;
if ( ! V_29 )
return V_376 ;
if ( V_376 -> type != V_546 &&
V_376 -> V_104 == V_238 -> V_104 ) {
V_29 = F_301 ( V_238 , V_537 ) ;
if ( ! V_29 )
return V_238 ;
}
return F_400 ( V_29 ) ;
}
static void F_412 ( struct V_12 * V_37 ,
struct V_237 * V_376 , T_3 V_537 )
{
F_304 ( V_376 , V_537 , 0 ) ;
F_306 ( V_37 , V_376 , NULL , 0 ) ;
}
struct V_66 * F_413 ( struct V_108 * V_109 ,
struct V_34 * V_35 , T_3 V_537 ,
T_2 V_17 , T_2 V_145 ,
struct V_447 * V_21 , int V_165 ,
T_2 V_550 , T_2 V_499 )
{
struct V_68 V_206 ;
struct V_237 * V_376 ;
struct V_66 * V_251 ;
T_2 V_7 = 0 ;
int V_29 ;
bool V_171 = F_75 ( V_35 -> V_37 ,
V_120 ) ;
V_376 = F_408 ( V_109 , V_35 , V_537 ) ;
if ( F_228 ( V_376 ) )
return F_414 ( V_376 ) ;
V_29 = F_390 ( V_35 , V_537 , V_537 ,
V_499 , V_550 , & V_206 , 0 ) ;
if ( V_29 ) {
F_412 ( V_35 -> V_37 , V_376 , V_537 ) ;
return F_400 ( V_29 ) ;
}
V_251 = F_398 ( V_109 , V_35 , V_206 . V_22 ,
V_537 , V_165 ) ;
F_30 ( F_228 ( V_251 ) ) ;
if ( V_145 == V_551 ) {
if ( V_17 == 0 )
V_17 = V_206 . V_22 ;
V_7 |= V_125 ;
} else
F_30 ( V_17 > 0 ) ;
if ( V_145 != V_200 ) {
struct V_178 * V_128 ;
V_128 = F_202 () ;
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
V_29 = F_144 ( V_35 -> V_37 , V_109 ,
V_206 . V_22 ,
V_206 . V_33 , V_17 , V_145 ,
V_165 , V_224 ,
V_128 , 0 ) ;
F_30 ( V_29 ) ;
}
return V_251 ;
}
static T_1 void F_415 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
struct V_552 * V_553 ,
struct V_64 * V_65 )
{
T_2 V_27 ;
T_2 V_273 ;
T_2 V_111 ;
T_2 V_7 ;
T_3 V_71 ;
T_3 V_537 ;
struct V_68 V_21 ;
struct V_66 * V_465 ;
int V_29 ;
int V_554 ;
int V_555 = 0 ;
if ( V_65 -> V_84 [ V_553 -> V_165 ] < V_553 -> V_556 ) {
V_553 -> V_557 = V_553 -> V_557 * 2 / 3 ;
V_553 -> V_557 = F_380 ( V_553 -> V_557 , 2 ) ;
} else {
V_553 -> V_557 = V_553 -> V_557 * 3 / 2 ;
V_553 -> V_557 = F_24 ( int , V_553 -> V_557 ,
F_416 ( V_35 ) ) ;
}
V_465 = V_65 -> V_83 [ V_553 -> V_165 ] ;
V_71 = F_38 ( V_465 ) ;
V_537 = F_219 ( V_35 , V_553 -> V_165 - 1 ) ;
for ( V_554 = V_65 -> V_84 [ V_553 -> V_165 ] ; V_554 < V_71 ; V_554 ++ ) {
if ( V_555 >= V_553 -> V_557 )
break;
F_47 () ;
V_27 = F_218 ( V_465 , V_554 ) ;
V_273 = F_417 ( V_465 , V_554 ) ;
if ( V_554 == V_65 -> V_84 [ V_553 -> V_165 ] )
goto V_76;
if ( V_553 -> V_558 == V_559 &&
V_273 <= V_35 -> V_247 . V_33 )
continue;
V_29 = F_74 ( V_109 , V_35 , V_27 ,
V_553 -> V_165 - 1 , 1 , & V_111 ,
& V_7 ) ;
if ( V_29 < 0 )
continue;
F_30 ( V_111 == 0 ) ;
if ( V_553 -> V_558 == V_560 ) {
if ( V_111 == 1 )
goto V_76;
if ( V_553 -> V_165 == 1 &&
( V_7 & V_125 ) )
continue;
if ( ! V_553 -> V_561 ||
V_273 <= V_35 -> V_247 . V_33 )
continue;
F_122 ( V_465 , & V_21 , V_554 ) ;
V_29 = F_418 ( & V_21 ,
& V_553 -> V_562 ) ;
if ( V_29 < 0 )
continue;
} else {
if ( V_553 -> V_165 == 1 &&
( V_7 & V_125 ) )
continue;
}
V_76:
V_29 = F_419 ( V_35 , V_27 , V_537 ,
V_273 ) ;
if ( V_29 )
break;
V_555 ++ ;
}
V_553 -> V_556 = V_554 ;
}
static T_1 int F_420 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
struct V_64 * V_65 ,
struct V_552 * V_553 , int V_563 )
{
int V_165 = V_553 -> V_165 ;
struct V_66 * V_465 = V_65 -> V_83 [ V_165 ] ;
T_2 V_564 = V_125 ;
int V_29 ;
if ( V_553 -> V_558 == V_559 &&
F_211 ( V_465 ) != V_35 -> V_247 . V_22 )
return 1 ;
if ( V_563 &&
( ( V_553 -> V_558 == V_560 && V_553 -> V_111 [ V_165 ] != 1 ) ||
( V_553 -> V_558 == V_559 && ! ( V_553 -> V_7 [ V_165 ] & V_564 ) ) ) ) {
F_30 ( ! V_65 -> V_565 [ V_165 ] ) ;
V_29 = F_74 ( V_109 , V_35 ,
V_465 -> V_32 , V_165 , 1 ,
& V_553 -> V_111 [ V_165 ] ,
& V_553 -> V_7 [ V_165 ] ) ;
F_30 ( V_29 == - V_72 ) ;
if ( V_29 )
return V_29 ;
F_30 ( V_553 -> V_111 [ V_165 ] == 0 ) ;
}
if ( V_553 -> V_558 == V_560 ) {
if ( V_553 -> V_111 [ V_165 ] > 1 )
return 1 ;
if ( V_65 -> V_565 [ V_165 ] && ! V_553 -> V_172 ) {
F_421 ( V_465 , V_65 -> V_565 [ V_165 ] ) ;
V_65 -> V_565 [ V_165 ] = 0 ;
}
return 0 ;
}
if ( ! ( V_553 -> V_7 [ V_165 ] & V_564 ) ) {
F_30 ( ! V_65 -> V_565 [ V_165 ] ) ;
V_29 = F_220 ( V_109 , V_35 , V_465 , 1 , V_553 -> V_566 ) ;
F_30 ( V_29 ) ;
V_29 = F_221 ( V_109 , V_35 , V_465 , 0 , V_553 -> V_566 ) ;
F_30 ( V_29 ) ;
V_29 = F_201 ( V_109 , V_35 , V_465 -> V_32 ,
V_465 -> V_49 , V_564 ,
F_212 ( V_465 ) , 0 ) ;
F_30 ( V_29 ) ;
V_553 -> V_7 [ V_165 ] |= V_564 ;
}
if ( V_65 -> V_565 [ V_165 ] && V_165 > 0 ) {
F_421 ( V_465 , V_65 -> V_565 [ V_165 ] ) ;
V_65 -> V_565 [ V_165 ] = 0 ;
}
return 0 ;
}
static T_1 int F_422 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
struct V_64 * V_65 ,
struct V_552 * V_553 , int * V_563 )
{
T_2 V_27 ;
T_2 V_273 ;
T_2 V_17 ;
T_3 V_537 ;
struct V_68 V_21 ;
struct V_66 * V_81 ;
int V_165 = V_553 -> V_165 ;
int V_76 = 0 ;
int V_29 = 0 ;
V_273 = F_417 ( V_65 -> V_83 [ V_165 ] ,
V_65 -> V_84 [ V_165 ] ) ;
if ( V_553 -> V_558 == V_559 &&
V_273 <= V_35 -> V_247 . V_33 ) {
* V_563 = 1 ;
return 1 ;
}
V_27 = F_218 ( V_65 -> V_83 [ V_165 ] , V_65 -> V_84 [ V_165 ] ) ;
V_537 = F_219 ( V_35 , V_165 - 1 ) ;
V_81 = F_423 ( V_35 , V_27 , V_537 ) ;
if ( ! V_81 ) {
V_81 = F_399 ( V_35 , V_27 , V_537 ) ;
if ( ! V_81 )
return - V_72 ;
F_402 ( V_35 -> V_247 . V_22 , V_81 ,
V_165 - 1 ) ;
V_76 = 1 ;
}
F_403 ( V_81 ) ;
F_405 ( V_81 ) ;
V_29 = F_74 ( V_109 , V_35 , V_27 , V_165 - 1 , 1 ,
& V_553 -> V_111 [ V_165 - 1 ] ,
& V_553 -> V_7 [ V_165 - 1 ] ) ;
if ( V_29 < 0 ) {
F_424 ( V_81 ) ;
return V_29 ;
}
if ( F_300 ( V_553 -> V_111 [ V_165 - 1 ] == 0 ) ) {
F_185 ( V_35 -> V_37 , L_35 ) ;
F_82 () ;
}
* V_563 = 0 ;
if ( V_553 -> V_558 == V_560 ) {
if ( V_553 -> V_111 [ V_165 - 1 ] > 1 ) {
if ( V_165 == 1 &&
( V_553 -> V_7 [ 0 ] & V_125 ) )
goto V_567;
if ( ! V_553 -> V_561 ||
V_273 <= V_35 -> V_247 . V_33 )
goto V_567;
F_122 ( V_65 -> V_83 [ V_165 ] , & V_21 ,
V_65 -> V_84 [ V_165 ] ) ;
V_29 = F_418 ( & V_21 , & V_553 -> V_562 ) ;
if ( V_29 < 0 )
goto V_567;
V_553 -> V_558 = V_559 ;
V_553 -> V_568 = V_165 - 1 ;
}
} else {
if ( V_165 == 1 &&
( V_553 -> V_7 [ 0 ] & V_125 ) )
goto V_567;
}
if ( ! F_425 ( V_81 , V_273 , 0 ) ) {
F_424 ( V_81 ) ;
F_426 ( V_81 ) ;
V_81 = NULL ;
* V_563 = 1 ;
}
if ( ! V_81 ) {
if ( V_76 && V_165 == 1 )
F_415 ( V_109 , V_35 , V_553 , V_65 ) ;
V_81 = F_427 ( V_35 , V_27 , V_537 , V_273 ) ;
if ( ! V_81 || ! F_428 ( V_81 ) ) {
F_426 ( V_81 ) ;
return - V_173 ;
}
F_403 ( V_81 ) ;
F_405 ( V_81 ) ;
}
V_165 -- ;
F_30 ( V_165 != F_212 ( V_81 ) ) ;
V_65 -> V_83 [ V_165 ] = V_81 ;
V_65 -> V_84 [ V_165 ] = 0 ;
V_65 -> V_565 [ V_165 ] = V_569 ;
V_553 -> V_165 = V_165 ;
if ( V_553 -> V_165 == 1 )
V_553 -> V_556 = 0 ;
return 0 ;
V_567:
V_553 -> V_111 [ V_165 - 1 ] = 0 ;
V_553 -> V_7 [ V_165 - 1 ] = 0 ;
if ( V_553 -> V_558 == V_560 ) {
if ( V_553 -> V_7 [ V_165 ] & V_125 ) {
V_17 = V_65 -> V_83 [ V_165 ] -> V_32 ;
} else {
F_30 ( V_35 -> V_247 . V_22 !=
F_211 ( V_65 -> V_83 [ V_165 ] ) ) ;
V_17 = 0 ;
}
V_29 = V_257 ( V_109 , V_35 , V_27 , V_537 , V_17 ,
V_35 -> V_247 . V_22 , V_165 - 1 , 0 , 0 ) ;
F_30 ( V_29 ) ;
}
F_424 ( V_81 ) ;
F_426 ( V_81 ) ;
* V_563 = 1 ;
return 1 ;
}
static T_1 int F_429 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
struct V_64 * V_65 ,
struct V_552 * V_553 )
{
int V_29 ;
int V_165 = V_553 -> V_165 ;
struct V_66 * V_465 = V_65 -> V_83 [ V_165 ] ;
T_2 V_17 = 0 ;
if ( V_553 -> V_558 == V_559 ) {
F_30 ( V_553 -> V_568 < V_165 ) ;
if ( V_165 < V_553 -> V_568 )
goto V_73;
V_29 = F_41 ( V_65 , V_165 + 1 , & V_553 -> V_562 ) ;
if ( V_29 > 0 )
V_553 -> V_561 = 0 ;
V_553 -> V_558 = V_560 ;
V_553 -> V_568 = - 1 ;
V_65 -> V_84 [ V_165 ] = 0 ;
if ( ! V_65 -> V_565 [ V_165 ] ) {
F_30 ( V_165 == 0 ) ;
F_403 ( V_465 ) ;
F_405 ( V_465 ) ;
V_65 -> V_565 [ V_165 ] = V_569 ;
V_29 = F_74 ( V_109 , V_35 ,
V_465 -> V_32 , V_165 , 1 ,
& V_553 -> V_111 [ V_165 ] ,
& V_553 -> V_7 [ V_165 ] ) ;
if ( V_29 < 0 ) {
F_421 ( V_465 , V_65 -> V_565 [ V_165 ] ) ;
V_65 -> V_565 [ V_165 ] = 0 ;
return V_29 ;
}
F_30 ( V_553 -> V_111 [ V_165 ] == 0 ) ;
if ( V_553 -> V_111 [ V_165 ] == 1 ) {
F_421 ( V_465 , V_65 -> V_565 [ V_165 ] ) ;
V_65 -> V_565 [ V_165 ] = 0 ;
return 1 ;
}
}
}
F_30 ( V_553 -> V_111 [ V_165 ] > 1 && ! V_65 -> V_565 [ V_165 ] ) ;
if ( V_553 -> V_111 [ V_165 ] == 1 ) {
if ( V_165 == 0 ) {
if ( V_553 -> V_7 [ V_165 ] & V_125 )
V_29 = F_221 ( V_109 , V_35 , V_465 , 1 ,
V_553 -> V_566 ) ;
else
V_29 = F_221 ( V_109 , V_35 , V_465 , 0 ,
V_553 -> V_566 ) ;
F_30 ( V_29 ) ;
}
if ( ! V_65 -> V_565 [ V_165 ] &&
F_368 ( V_465 ) == V_109 -> V_270 ) {
F_403 ( V_465 ) ;
F_405 ( V_465 ) ;
V_65 -> V_565 [ V_165 ] = V_569 ;
}
F_404 ( V_109 , V_35 , V_465 ) ;
}
if ( V_465 == V_35 -> V_127 ) {
if ( V_553 -> V_7 [ V_165 ] & V_125 )
V_17 = V_465 -> V_32 ;
else
F_30 ( V_35 -> V_247 . V_22 !=
F_211 ( V_465 ) ) ;
} else {
if ( V_553 -> V_7 [ V_165 + 1 ] & V_125 )
V_17 = V_65 -> V_83 [ V_165 + 1 ] -> V_32 ;
else
F_30 ( V_35 -> V_247 . V_22 !=
F_211 ( V_65 -> V_83 [ V_165 + 1 ] ) ) ;
}
F_367 ( V_109 , V_35 , V_465 , V_17 , V_553 -> V_111 [ V_165 ] == 1 ) ;
V_73:
V_553 -> V_111 [ V_165 ] = 0 ;
V_553 -> V_7 [ V_165 ] = 0 ;
return 0 ;
}
static T_1 int F_430 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
struct V_64 * V_65 ,
struct V_552 * V_553 )
{
int V_165 = V_553 -> V_165 ;
int V_563 = 1 ;
int V_29 ;
while ( V_165 >= 0 ) {
V_29 = F_420 ( V_109 , V_35 , V_65 , V_553 , V_563 ) ;
if ( V_29 > 0 )
break;
if ( V_165 == 0 )
break;
if ( V_65 -> V_84 [ V_165 ] >=
F_38 ( V_65 -> V_83 [ V_165 ] ) )
break;
V_29 = F_422 ( V_109 , V_35 , V_65 , V_553 , & V_563 ) ;
if ( V_29 > 0 ) {
V_65 -> V_84 [ V_165 ] ++ ;
continue;
} else if ( V_29 < 0 )
return V_29 ;
V_165 = V_553 -> V_165 ;
}
return 0 ;
}
static T_1 int F_431 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
struct V_64 * V_65 ,
struct V_552 * V_553 , int V_570 )
{
int V_165 = V_553 -> V_165 ;
int V_29 ;
V_65 -> V_84 [ V_165 ] = F_38 ( V_65 -> V_83 [ V_165 ] ) ;
while ( V_165 < V_570 && V_65 -> V_83 [ V_165 ] ) {
V_553 -> V_165 = V_165 ;
if ( V_65 -> V_84 [ V_165 ] + 1 <
F_38 ( V_65 -> V_83 [ V_165 ] ) ) {
V_65 -> V_84 [ V_165 ] ++ ;
return 0 ;
} else {
V_29 = F_429 ( V_109 , V_35 , V_65 , V_553 ) ;
if ( V_29 > 0 )
return 0 ;
if ( V_65 -> V_565 [ V_165 ] ) {
F_421 ( V_65 -> V_83 [ V_165 ] ,
V_65 -> V_565 [ V_165 ] ) ;
V_65 -> V_565 [ V_165 ] = 0 ;
}
F_426 ( V_65 -> V_83 [ V_165 ] ) ;
V_65 -> V_83 [ V_165 ] = NULL ;
V_165 ++ ;
}
}
return 1 ;
}
int F_432 ( struct V_34 * V_35 ,
struct V_237 * V_376 , int V_561 ,
int V_566 )
{
struct V_64 * V_65 ;
struct V_108 * V_109 ;
struct V_34 * V_87 = V_35 -> V_37 -> V_87 ;
struct V_571 * V_248 = & V_35 -> V_248 ;
struct V_552 * V_553 ;
struct V_68 V_21 ;
int V_82 = 0 ;
int V_29 ;
int V_165 ;
bool V_572 = false ;
V_65 = F_33 () ;
if ( ! V_65 ) {
V_82 = - V_72 ;
goto V_73;
}
V_553 = F_53 ( sizeof( * V_553 ) , V_40 ) ;
if ( ! V_553 ) {
F_50 ( V_65 ) ;
V_82 = - V_72 ;
goto V_73;
}
V_109 = F_433 ( V_87 , 0 ) ;
if ( F_228 ( V_109 ) ) {
V_82 = F_229 ( V_109 ) ;
goto V_122;
}
if ( V_376 )
V_109 -> V_376 = V_376 ;
if ( F_434 ( & V_248 -> V_573 ) == 0 ) {
V_165 = F_212 ( V_35 -> V_127 ) ;
V_65 -> V_83 [ V_165 ] = F_435 ( V_35 ) ;
F_405 ( V_65 -> V_83 [ V_165 ] ) ;
V_65 -> V_84 [ V_165 ] = 0 ;
V_65 -> V_565 [ V_165 ] = V_569 ;
memset ( & V_553 -> V_562 , 0 ,
sizeof( V_553 -> V_562 ) ) ;
} else {
F_436 ( & V_21 , & V_248 -> V_573 ) ;
memcpy ( & V_553 -> V_562 , & V_21 ,
sizeof( V_553 -> V_562 ) ) ;
V_165 = V_248 -> V_574 ;
F_30 ( V_165 == 0 ) ;
V_65 -> V_575 = V_165 ;
V_29 = F_37 ( NULL , V_35 , & V_21 , V_65 , 0 , 0 ) ;
V_65 -> V_575 = 0 ;
if ( V_29 < 0 ) {
V_82 = V_29 ;
goto V_576;
}
F_8 ( V_29 > 0 ) ;
F_127 ( V_65 , 0 ) ;
V_165 = F_212 ( V_35 -> V_127 ) ;
while ( 1 ) {
F_403 ( V_65 -> V_83 [ V_165 ] ) ;
F_405 ( V_65 -> V_83 [ V_165 ] ) ;
V_65 -> V_565 [ V_165 ] = V_569 ;
V_29 = F_74 ( V_109 , V_35 ,
V_65 -> V_83 [ V_165 ] -> V_32 ,
V_165 , 1 , & V_553 -> V_111 [ V_165 ] ,
& V_553 -> V_7 [ V_165 ] ) ;
if ( V_29 < 0 ) {
V_82 = V_29 ;
goto V_576;
}
F_30 ( V_553 -> V_111 [ V_165 ] == 0 ) ;
if ( V_165 == V_248 -> V_574 )
break;
F_424 ( V_65 -> V_83 [ V_165 ] ) ;
V_65 -> V_565 [ V_165 ] = 0 ;
F_8 ( V_553 -> V_111 [ V_165 ] != 1 ) ;
V_165 -- ;
}
}
V_553 -> V_165 = V_165 ;
V_553 -> V_568 = - 1 ;
V_553 -> V_558 = V_560 ;
V_553 -> V_561 = V_561 ;
V_553 -> V_172 = 0 ;
V_553 -> V_566 = V_566 ;
V_553 -> V_557 = F_416 ( V_35 ) ;
while ( 1 ) {
V_29 = F_430 ( V_109 , V_35 , V_65 , V_553 ) ;
if ( V_29 < 0 ) {
V_82 = V_29 ;
break;
}
V_29 = F_431 ( V_109 , V_35 , V_65 , V_553 , V_166 ) ;
if ( V_29 < 0 ) {
V_82 = V_29 ;
break;
}
if ( V_29 > 0 ) {
F_30 ( V_553 -> V_558 != V_560 ) ;
break;
}
if ( V_553 -> V_558 == V_560 ) {
V_165 = V_553 -> V_165 ;
F_437 ( V_65 -> V_83 [ V_165 ] ,
& V_248 -> V_573 ,
V_65 -> V_84 [ V_165 ] ) ;
V_248 -> V_574 = V_165 ;
}
F_30 ( V_553 -> V_165 == 0 ) ;
if ( F_438 ( V_109 , V_87 ) ||
( ! V_566 && F_439 ( V_35 ) ) ) {
V_29 = F_440 ( V_109 , V_87 ,
& V_35 -> V_247 ,
V_248 ) ;
if ( V_29 ) {
F_147 ( V_109 , V_87 , V_29 ) ;
V_82 = V_29 ;
goto V_576;
}
F_441 ( V_109 , V_87 ) ;
if ( ! V_566 && F_439 ( V_35 ) ) {
F_442 ( L_36 ) ;
V_82 = - V_176 ;
goto V_122;
}
V_109 = F_433 ( V_87 , 0 ) ;
if ( F_228 ( V_109 ) ) {
V_82 = F_229 ( V_109 ) ;
goto V_122;
}
if ( V_376 )
V_109 -> V_376 = V_376 ;
}
}
F_44 ( V_65 ) ;
if ( V_82 )
goto V_576;
V_29 = F_443 ( V_109 , V_87 , & V_35 -> V_247 ) ;
if ( V_29 ) {
F_147 ( V_109 , V_87 , V_29 ) ;
goto V_576;
}
if ( V_35 -> V_247 . V_22 != V_551 ) {
V_29 = F_444 ( V_87 , & V_35 -> V_247 , V_65 ,
NULL , NULL ) ;
if ( V_29 < 0 ) {
F_147 ( V_109 , V_87 , V_29 ) ;
V_82 = V_29 ;
goto V_576;
} else if ( V_29 > 0 ) {
F_445 ( V_109 , V_87 ,
V_35 -> V_247 . V_22 ) ;
}
}
if ( V_35 -> V_577 ) {
F_446 ( V_87 -> V_37 , V_35 ) ;
} else {
F_426 ( V_35 -> V_127 ) ;
F_426 ( V_35 -> V_578 ) ;
F_447 ( V_35 ) ;
}
V_572 = true ;
V_576:
F_441 ( V_109 , V_87 ) ;
V_122:
F_9 ( V_553 ) ;
F_50 ( V_65 ) ;
V_73:
if ( ! V_566 && V_572 == false )
F_448 ( V_35 ) ;
if ( V_82 && V_82 != - V_176 )
F_449 ( V_35 -> V_37 , V_82 ) ;
return V_82 ;
}
int F_450 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
struct V_66 * V_127 ,
struct V_66 * V_17 )
{
struct V_64 * V_65 ;
struct V_552 * V_553 ;
int V_165 ;
int V_579 ;
int V_29 = 0 ;
int V_580 ;
F_30 ( V_35 -> V_247 . V_22 != V_551 ) ;
V_65 = F_33 () ;
if ( ! V_65 )
return - V_72 ;
V_553 = F_53 ( sizeof( * V_553 ) , V_40 ) ;
if ( ! V_553 ) {
F_50 ( V_65 ) ;
return - V_72 ;
}
F_451 ( V_17 ) ;
V_579 = F_212 ( V_17 ) ;
F_452 ( V_17 ) ;
V_65 -> V_83 [ V_579 ] = V_17 ;
V_65 -> V_84 [ V_579 ] = F_38 ( V_17 ) ;
F_451 ( V_127 ) ;
V_165 = F_212 ( V_127 ) ;
V_65 -> V_83 [ V_165 ] = V_127 ;
V_65 -> V_84 [ V_165 ] = 0 ;
V_65 -> V_565 [ V_165 ] = V_569 ;
V_553 -> V_111 [ V_579 ] = 1 ;
V_553 -> V_7 [ V_579 ] = V_125 ;
V_553 -> V_165 = V_165 ;
V_553 -> V_568 = - 1 ;
V_553 -> V_558 = V_560 ;
V_553 -> V_561 = 0 ;
V_553 -> V_172 = 1 ;
V_553 -> V_566 = 1 ;
V_553 -> V_557 = F_416 ( V_35 ) ;
while ( 1 ) {
V_580 = F_430 ( V_109 , V_35 , V_65 , V_553 ) ;
if ( V_580 < 0 ) {
V_29 = V_580 ;
break;
}
V_580 = F_431 ( V_109 , V_35 , V_65 , V_553 , V_579 ) ;
if ( V_580 < 0 )
V_29 = V_580 ;
if ( V_580 != 0 )
break;
}
F_9 ( V_553 ) ;
F_50 ( V_65 ) ;
return V_29 ;
}
static T_2 F_453 ( struct V_34 * V_35 , T_2 V_7 )
{
T_2 V_323 ;
T_2 V_581 ;
V_581 = F_256 ( V_35 -> V_37 , V_7 ) ;
if ( V_581 )
return F_258 ( V_581 ) ;
V_323 = V_35 -> V_37 -> V_324 -> V_325 +
V_35 -> V_37 -> V_324 -> V_326 ;
V_581 = V_329 |
V_330 | V_331 |
V_287 | V_288 ;
if ( V_323 == 1 ) {
V_581 |= V_286 ;
V_581 = V_7 & ~ V_581 ;
if ( V_7 & V_329 )
return V_581 ;
if ( V_7 & ( V_287 |
V_288 ) )
return V_581 | V_286 ;
} else {
if ( V_7 & V_581 )
return V_7 ;
V_581 |= V_286 ;
V_581 = V_7 & ~ V_581 ;
if ( V_7 & V_286 )
return V_581 | V_287 ;
}
return V_7 ;
}
static int F_454 ( struct V_1 * V_2 , int V_348 )
{
struct V_101 * V_347 = V_2 -> V_104 ;
T_2 V_36 ;
T_2 V_582 ;
int V_29 = - V_343 ;
if ( ( V_347 -> V_7 &
( V_282 | V_280 ) ) &&
! V_348 )
V_582 = 1 * 1024 * 1024 ;
else
V_582 = 0 ;
F_11 ( & V_347 -> V_52 ) ;
F_11 ( & V_2 -> V_52 ) ;
if ( V_2 -> V_268 ) {
V_29 = 0 ;
goto V_73;
}
V_36 = V_2 -> V_21 . V_33 - V_2 -> V_10 - V_2 -> V_9 -
V_2 -> V_46 - F_344 ( & V_2 -> V_134 ) ;
if ( V_347 -> V_284 + V_347 -> V_298 + V_347 -> V_297 +
V_347 -> V_300 + V_347 -> V_299 + V_36 +
V_582 <= V_347 -> V_283 ) {
V_347 -> V_299 += V_36 ;
V_2 -> V_268 = 1 ;
V_29 = 0 ;
}
V_73:
F_13 ( & V_2 -> V_52 ) ;
F_13 ( & V_347 -> V_52 ) ;
return V_29 ;
}
int F_455 ( struct V_34 * V_35 ,
struct V_1 * V_2 )
{
struct V_108 * V_109 ;
T_2 V_583 ;
int V_29 ;
F_30 ( V_2 -> V_268 ) ;
V_109 = F_265 ( V_35 ) ;
if ( F_228 ( V_109 ) )
return F_229 ( V_109 ) ;
V_583 = F_453 ( V_35 , V_2 -> V_7 ) ;
if ( V_583 != V_2 -> V_7 ) {
V_29 = F_266 ( V_109 , V_35 , V_583 ,
V_342 ) ;
if ( V_29 < 0 )
goto V_73;
}
V_29 = F_454 ( V_2 , 0 ) ;
if ( ! V_29 )
goto V_73;
V_583 = F_259 ( V_35 , V_2 -> V_104 -> V_7 ) ;
V_29 = F_266 ( V_109 , V_35 , V_583 ,
V_342 ) ;
if ( V_29 < 0 )
goto V_73;
V_29 = F_454 ( V_2 , 0 ) ;
V_73:
F_267 ( V_109 , V_35 ) ;
return V_29 ;
}
int F_456 ( struct V_108 * V_109 ,
struct V_34 * V_35 , T_2 type )
{
T_2 V_583 = F_259 ( V_35 , type ) ;
return F_266 ( V_109 , V_35 , V_583 ,
V_342 ) ;
}
static T_2 F_457 ( struct V_102 * V_584 )
{
struct V_1 * V_14 ;
T_2 V_585 = 0 ;
int V_285 ;
F_381 (block_group, groups_list, list) {
F_11 ( & V_14 -> V_52 ) ;
if ( ! V_14 -> V_268 ) {
F_13 ( & V_14 -> V_52 ) ;
continue;
}
if ( V_14 -> V_7 & ( V_287 |
V_288 |
V_286 ) )
V_285 = 2 ;
else
V_285 = 1 ;
V_585 += ( V_14 -> V_21 . V_33 -
F_344 ( & V_14 -> V_134 ) ) *
V_285 ;
F_13 ( & V_14 -> V_52 ) ;
}
return V_585 ;
}
T_2 F_458 ( struct V_101 * V_347 )
{
int V_43 ;
T_2 V_585 = 0 ;
F_11 ( & V_347 -> V_52 ) ;
for ( V_43 = 0 ; V_43 < V_292 ; V_43 ++ )
if ( ! F_184 ( & V_347 -> V_293 [ V_43 ] ) )
V_585 += F_457 (
& V_347 -> V_293 [ V_43 ] ) ;
F_13 ( & V_347 -> V_52 ) ;
return V_585 ;
}
void F_459 ( struct V_34 * V_35 ,
struct V_1 * V_2 )
{
struct V_101 * V_347 = V_2 -> V_104 ;
T_2 V_36 ;
F_30 ( ! V_2 -> V_268 ) ;
F_11 ( & V_347 -> V_52 ) ;
F_11 ( & V_2 -> V_52 ) ;
V_36 = V_2 -> V_21 . V_33 - V_2 -> V_10 - V_2 -> V_9 -
V_2 -> V_46 - F_344 ( & V_2 -> V_134 ) ;
V_347 -> V_299 -= V_36 ;
V_2 -> V_268 = 0 ;
F_13 ( & V_2 -> V_52 ) ;
F_13 ( & V_347 -> V_52 ) ;
}
int F_460 ( struct V_34 * V_35 , T_2 V_27 )
{
struct V_1 * V_14 ;
struct V_101 * V_104 ;
struct V_586 * V_324 = V_35 -> V_37 -> V_324 ;
struct V_587 * V_588 ;
struct V_108 * V_109 ;
T_2 V_589 ;
T_2 V_590 = 1 ;
T_2 V_591 = 0 ;
T_2 V_318 ;
int V_506 ;
int V_107 = 0 ;
int V_29 = 0 ;
V_14 = F_67 ( V_35 -> V_37 , V_27 ) ;
if ( ! V_14 )
return - 1 ;
V_589 = F_344 ( & V_14 -> V_134 ) ;
if ( ! V_589 )
goto V_73;
V_104 = V_14 -> V_104 ;
F_11 ( & V_104 -> V_52 ) ;
V_107 = V_104 -> V_107 ;
if ( ( V_104 -> V_283 != V_14 -> V_21 . V_33 ) &&
( V_104 -> V_284 + V_104 -> V_298 +
V_104 -> V_297 + V_104 -> V_299 +
V_589 < V_104 -> V_283 ) ) {
F_13 ( & V_104 -> V_52 ) ;
goto V_73;
}
F_13 ( & V_104 -> V_52 ) ;
V_29 = - 1 ;
V_318 = F_256 ( V_35 -> V_37 , V_14 -> V_7 ) ;
if ( V_318 ) {
V_506 = F_374 ( F_258 ( V_318 ) ) ;
} else {
if ( V_107 )
goto V_73;
V_506 = F_375 ( V_14 ) ;
}
if ( V_506 == V_489 ) {
V_590 = 4 ;
V_589 >>= 1 ;
} else if ( V_506 == V_490 ) {
V_590 = 2 ;
} else if ( V_506 == V_491 ) {
V_589 <<= 1 ;
} else if ( V_506 == V_492 ) {
V_590 = V_324 -> V_325 ;
F_461 ( V_589 , V_590 ) ;
}
V_109 = F_265 ( V_35 ) ;
if ( F_228 ( V_109 ) ) {
V_29 = F_229 ( V_109 ) ;
goto V_73;
}
F_35 ( & V_35 -> V_37 -> V_358 ) ;
F_381 (device, &fs_devices->alloc_list, dev_alloc_list) {
T_2 V_592 ;
if ( V_588 -> V_283 > V_588 -> V_284 + V_589 &&
! V_588 -> V_593 ) {
V_29 = F_462 ( V_109 , V_588 , V_589 ,
& V_592 , NULL ) ;
if ( ! V_29 )
V_591 ++ ;
if ( V_591 >= V_590 )
break;
V_29 = - 1 ;
}
}
F_46 ( & V_35 -> V_37 -> V_358 ) ;
F_267 ( V_109 , V_35 ) ;
V_73:
F_6 ( V_14 ) ;
return V_29 ;
}
static int F_463 ( struct V_34 * V_35 ,
struct V_64 * V_65 , struct V_68 * V_21 )
{
int V_29 = 0 ;
struct V_68 V_139 ;
struct V_66 * V_67 ;
int V_554 ;
V_29 = F_37 ( NULL , V_35 , V_21 , V_65 , 0 , 0 ) ;
if ( V_29 < 0 )
goto V_73;
while ( 1 ) {
V_554 = V_65 -> V_84 [ 0 ] ;
V_67 = V_65 -> V_83 [ 0 ] ;
if ( V_554 >= F_38 ( V_67 ) ) {
V_29 = F_48 ( V_35 , V_65 ) ;
if ( V_29 == 0 )
continue;
if ( V_29 < 0 )
goto V_73;
break;
}
F_40 ( V_67 , & V_139 , V_554 ) ;
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
void F_464 ( struct V_12 * V_13 )
{
struct V_1 * V_14 ;
T_2 V_70 = 0 ;
while ( 1 ) {
struct V_260 * V_260 ;
V_14 = F_66 ( V_13 , V_70 ) ;
while ( V_14 ) {
F_11 ( & V_14 -> V_52 ) ;
if ( V_14 -> V_162 )
break;
F_13 ( & V_14 -> V_52 ) ;
V_14 = F_225 ( V_13 -> V_87 ,
V_14 ) ;
}
if ( ! V_14 ) {
if ( V_70 == 0 )
break;
V_70 = 0 ;
continue;
}
V_260 = V_14 -> V_260 ;
V_14 -> V_162 = 0 ;
V_14 -> V_260 = NULL ;
F_13 ( & V_14 -> V_52 ) ;
F_240 ( V_260 ) ;
V_70 = V_14 -> V_21 . V_22 + V_14 -> V_21 . V_33 ;
F_6 ( V_14 ) ;
}
}
int F_465 ( struct V_12 * V_13 )
{
struct V_1 * V_14 ;
struct V_101 * V_104 ;
struct V_50 * V_54 ;
struct V_15 * V_30 ;
F_62 ( & V_13 -> V_80 ) ;
while ( ! F_184 ( & V_13 -> V_99 ) ) {
V_54 = F_466 ( V_13 -> V_99 . V_81 ,
struct V_50 , V_91 ) ;
F_187 ( & V_54 -> V_91 ) ;
F_26 ( V_54 ) ;
}
F_64 ( & V_13 -> V_80 ) ;
F_11 ( & V_13 -> V_18 ) ;
while ( ( V_30 = F_182 ( & V_13 -> V_19 ) ) != NULL ) {
V_14 = F_12 ( V_30 , struct V_1 ,
V_20 ) ;
F_176 ( & V_14 -> V_20 ,
& V_13 -> V_19 ) ;
F_13 ( & V_13 -> V_18 ) ;
F_62 ( & V_14 -> V_104 -> V_296 ) ;
F_187 ( & V_14 -> V_91 ) ;
F_64 ( & V_14 -> V_104 -> V_296 ) ;
if ( V_14 -> V_3 == V_53 )
F_373 ( V_14 ) ;
if ( V_14 -> V_3 == V_95 ||
V_14 -> V_3 == V_5 )
F_19 ( V_13 -> V_63 , V_14 ) ;
F_467 ( V_14 ) ;
F_6 ( V_14 ) ;
F_11 ( & V_13 -> V_18 ) ;
}
F_13 ( & V_13 -> V_18 ) ;
F_468 () ;
F_321 ( V_13 ) ;
while ( ! F_184 ( & V_13 -> V_104 ) ) {
int V_43 ;
V_104 = F_466 ( V_13 -> V_104 . V_81 ,
struct V_101 ,
V_91 ) ;
if ( F_236 ( V_13 -> V_87 , V_355 ) ) {
if ( F_8 ( V_104 -> V_297 > 0 ||
V_104 -> V_298 > 0 ||
V_104 -> V_300 > 0 ) ) {
F_280 ( V_104 , 0 , 0 ) ;
}
}
F_187 ( & V_104 -> V_91 ) ;
for ( V_43 = 0 ; V_43 < V_292 ; V_43 ++ ) {
struct V_594 * V_305 ;
V_305 = & V_104 -> V_294 [ V_43 ] ;
if ( V_305 -> V_17 ) {
F_469 ( V_305 ) ;
F_470 ( V_305 ) ;
}
}
F_469 ( & V_104 -> V_305 ) ;
F_470 ( & V_104 -> V_305 ) ;
}
return 0 ;
}
static void F_471 ( struct V_101 * V_104 ,
struct V_1 * V_2 )
{
int V_506 = F_375 ( V_2 ) ;
F_62 ( & V_104 -> V_296 ) ;
if ( F_184 ( & V_104 -> V_293 [ V_506 ] ) ) {
struct V_594 * V_305 = & V_104 -> V_294 [ V_506 ] ;
int V_29 ;
F_472 ( & V_104 -> V_305 ) ;
V_29 = F_473 ( V_305 , & V_104 -> V_305 , L_11 ,
F_376 ( V_506 ) ) ;
if ( V_29 ) {
F_474 ( L_37 ) ;
F_470 ( & V_104 -> V_305 ) ;
}
}
F_63 ( & V_2 -> V_91 , & V_104 -> V_293 [ V_506 ] ) ;
F_64 ( & V_104 -> V_296 ) ;
}
static struct V_1 *
F_475 ( struct V_34 * V_35 , T_2 V_32 , T_2 V_57 )
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
V_2 -> V_21 . type = V_177 ;
V_2 -> V_337 = V_35 -> V_337 ;
V_2 -> V_37 = V_35 -> V_37 ;
V_2 -> V_595 = F_476 ( V_35 ,
& V_35 -> V_37 -> V_48 ,
V_32 ) ;
F_57 ( & V_2 -> V_8 , 1 ) ;
F_249 ( & V_2 -> V_52 ) ;
F_54 ( & V_2 -> V_91 ) ;
F_54 ( & V_2 -> V_596 ) ;
F_54 ( & V_2 -> V_597 ) ;
F_477 ( V_2 ) ;
return V_2 ;
}
int F_478 ( struct V_34 * V_35 )
{
struct V_64 * V_65 ;
int V_29 ;
struct V_1 * V_2 ;
struct V_12 * V_13 = V_35 -> V_37 ;
struct V_101 * V_104 ;
struct V_68 V_21 ;
struct V_68 V_139 ;
struct V_66 * V_67 ;
int V_598 = 0 ;
T_2 V_599 ;
V_35 = V_13 -> V_63 ;
V_21 . V_22 = 0 ;
V_21 . V_33 = 0 ;
F_378 ( & V_21 , V_177 ) ;
V_65 = F_33 () ;
if ( ! V_65 )
return - V_72 ;
V_65 -> V_76 = 1 ;
V_599 = F_479 ( V_35 -> V_37 -> V_352 ) ;
if ( F_236 ( V_35 , V_274 ) &&
F_480 ( V_35 -> V_37 -> V_352 ) != V_599 )
V_598 = 1 ;
if ( F_236 ( V_35 , V_600 ) )
V_598 = 1 ;
while ( 1 ) {
V_29 = F_463 ( V_35 , V_65 , & V_21 ) ;
if ( V_29 > 0 )
break;
if ( V_29 != 0 )
goto error;
V_67 = V_65 -> V_83 [ 0 ] ;
F_40 ( V_67 , & V_139 , V_65 -> V_84 [ 0 ] ) ;
V_2 = F_475 ( V_35 , V_139 . V_22 ,
V_139 . V_33 ) ;
if ( ! V_2 ) {
V_29 = - V_72 ;
goto error;
}
if ( V_598 ) {
V_2 -> V_266 = V_276 ;
if ( F_236 ( V_35 , V_274 ) )
V_2 -> V_277 = 1 ;
}
F_481 ( V_67 , & V_2 -> V_134 ,
F_223 ( V_67 , V_65 -> V_84 [ 0 ] ) ,
sizeof( V_2 -> V_134 ) ) ;
V_2 -> V_7 = F_482 ( & V_2 -> V_134 ) ;
V_21 . V_22 = V_139 . V_22 + V_139 . V_33 ;
F_44 ( V_65 ) ;
V_29 = F_21 ( V_35 , V_2 ) ;
if ( V_29 ) {
F_19 ( V_35 , V_2 ) ;
F_6 ( V_2 ) ;
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
F_467 ( V_2 ) ;
F_6 ( V_2 ) ;
goto error;
}
V_29 = F_245 ( V_13 , V_2 -> V_7 , V_139 . V_33 ,
F_344 ( & V_2 -> V_134 ) ,
& V_104 ) ;
if ( V_29 ) {
F_467 ( V_2 ) ;
F_11 ( & V_13 -> V_18 ) ;
F_176 ( & V_2 -> V_20 ,
& V_13 -> V_19 ) ;
F_13 ( & V_13 -> V_18 ) ;
F_6 ( V_2 ) ;
goto error;
}
V_2 -> V_104 = V_104 ;
F_11 ( & V_2 -> V_104 -> V_52 ) ;
V_2 -> V_104 -> V_299 += V_2 -> V_46 ;
F_13 ( & V_2 -> V_104 -> V_52 ) ;
F_471 ( V_104 , V_2 ) ;
F_252 ( V_35 -> V_37 , V_2 -> V_7 ) ;
if ( F_483 ( V_35 , V_2 -> V_21 . V_22 ) )
F_454 ( V_2 , 1 ) ;
}
F_70 (space_info, &root->fs_info->space_info, list) {
if ( ! ( F_259 ( V_35 , V_104 -> V_7 ) &
( V_288 |
V_287 |
V_330 |
V_331 |
V_286 ) ) )
continue;
F_381 (cache,
&space_info->block_groups[BTRFS_RAID_RAID0],
list)
F_454 ( V_2 , 1 ) ;
F_381 (cache,
&space_info->block_groups[BTRFS_RAID_SINGLE],
list)
F_454 ( V_2 , 1 ) ;
}
F_320 ( V_13 ) ;
V_29 = 0 ;
error:
F_50 ( V_65 ) ;
return V_29 ;
}
void F_198 ( struct V_108 * V_109 ,
struct V_34 * V_35 )
{
struct V_1 * V_14 , * V_327 ;
struct V_34 * V_63 = V_35 -> V_37 -> V_63 ;
struct V_601 V_134 ;
struct V_68 V_21 ;
int V_29 = 0 ;
F_355 (block_group, tmp, &trans->new_bgs,
new_bg_list) {
F_356 ( & V_14 -> V_597 ) ;
if ( V_29 )
continue;
F_11 ( & V_14 -> V_52 ) ;
memcpy ( & V_134 , & V_14 -> V_134 , sizeof( V_134 ) ) ;
memcpy ( & V_21 , & V_14 -> V_21 , sizeof( V_21 ) ) ;
F_13 ( & V_14 -> V_52 ) ;
V_29 = F_484 ( V_109 , V_63 , & V_21 , & V_134 ,
sizeof( V_134 ) ) ;
if ( V_29 )
F_147 ( V_109 , V_63 , V_29 ) ;
V_29 = F_485 ( V_109 , V_63 ,
V_21 . V_22 , V_21 . V_33 ) ;
if ( V_29 )
F_147 ( V_109 , V_63 , V_29 ) ;
}
}
int F_486 ( struct V_108 * V_109 ,
struct V_34 * V_35 , T_2 V_284 ,
T_2 type , T_2 V_602 , T_2 V_603 ,
T_2 V_57 )
{
int V_29 ;
struct V_34 * V_63 ;
struct V_1 * V_2 ;
V_63 = V_35 -> V_37 -> V_63 ;
V_35 -> V_37 -> V_604 = V_109 -> V_270 ;
V_2 = F_475 ( V_35 , V_603 , V_57 ) ;
if ( ! V_2 )
return - V_72 ;
F_345 ( & V_2 -> V_134 , V_284 ) ;
F_487 ( & V_2 -> V_134 , V_602 ) ;
F_488 ( & V_2 -> V_134 , type ) ;
V_2 -> V_7 = type ;
V_2 -> V_98 = ( T_2 ) - 1 ;
V_2 -> V_3 = V_4 ;
V_29 = F_21 ( V_35 , V_2 ) ;
if ( V_29 ) {
F_19 ( V_35 , V_2 ) ;
F_6 ( V_2 ) ;
return V_29 ;
}
F_27 ( V_2 , V_35 -> V_37 , V_603 ,
V_603 + V_57 ) ;
F_19 ( V_35 , V_2 ) ;
V_29 = F_10 ( V_35 -> V_37 , V_2 ) ;
if ( V_29 ) {
F_467 ( V_2 ) ;
F_6 ( V_2 ) ;
return V_29 ;
}
V_29 = F_245 ( V_35 -> V_37 , V_2 -> V_7 , V_57 , V_284 ,
& V_2 -> V_104 ) ;
if ( V_29 ) {
F_467 ( V_2 ) ;
F_11 ( & V_35 -> V_37 -> V_18 ) ;
F_176 ( & V_2 -> V_20 ,
& V_35 -> V_37 -> V_19 ) ;
F_13 ( & V_35 -> V_37 -> V_18 ) ;
F_6 ( V_2 ) ;
return V_29 ;
}
F_319 ( V_35 -> V_37 ) ;
F_11 ( & V_2 -> V_104 -> V_52 ) ;
V_2 -> V_104 -> V_299 += V_2 -> V_46 ;
F_13 ( & V_2 -> V_104 -> V_52 ) ;
F_471 ( V_2 -> V_104 , V_2 ) ;
F_63 ( & V_2 -> V_597 , & V_109 -> V_245 ) ;
F_252 ( V_63 -> V_37 , type ) ;
return 0 ;
}
static void F_489 ( struct V_12 * V_37 , T_2 V_7 )
{
T_2 V_309 = F_253 ( V_7 ) &
V_310 ;
F_254 ( & V_37 -> V_311 ) ;
if ( V_7 & V_281 )
V_37 -> V_312 &= ~ V_309 ;
if ( V_7 & V_280 )
V_37 -> V_313 &= ~ V_309 ;
if ( V_7 & V_282 )
V_37 -> V_314 &= ~ V_309 ;
F_255 ( & V_37 -> V_311 ) ;
}
int F_490 ( struct V_108 * V_109 ,
struct V_34 * V_35 , T_2 V_605 )
{
struct V_64 * V_65 ;
struct V_1 * V_14 ;
struct V_501 * V_606 ;
struct V_34 * V_87 = V_35 -> V_37 -> V_87 ;
struct V_68 V_21 ;
struct V_260 * V_260 ;
int V_29 ;
int V_506 ;
int V_285 ;
V_35 = V_35 -> V_37 -> V_63 ;
V_14 = F_67 ( V_35 -> V_37 , V_605 ) ;
F_30 ( ! V_14 ) ;
F_30 ( ! V_14 -> V_268 ) ;
F_19 ( V_35 , V_14 ) ;
memcpy ( & V_21 , & V_14 -> V_21 , sizeof( V_21 ) ) ;
V_506 = F_375 ( V_14 ) ;
if ( V_14 -> V_7 & ( V_286 |
V_287 |
V_288 ) )
V_285 = 2 ;
else
V_285 = 1 ;
V_606 = & V_35 -> V_37 -> V_515 ;
F_11 ( & V_606 -> V_522 ) ;
F_384 ( V_14 , V_606 ) ;
F_13 ( & V_606 -> V_522 ) ;
V_606 = & V_35 -> V_37 -> V_513 ;
F_11 ( & V_606 -> V_522 ) ;
F_384 ( V_14 , V_606 ) ;
F_13 ( & V_606 -> V_522 ) ;
V_65 = F_33 () ;
if ( ! V_65 ) {
V_29 = - V_72 ;
goto V_73;
}
V_260 = F_227 ( V_87 , V_14 , V_65 ) ;
if ( ! F_228 ( V_260 ) ) {
V_29 = F_491 ( V_109 , V_260 ) ;
if ( V_29 ) {
F_492 ( V_260 ) ;
goto V_73;
}
F_493 ( V_260 ) ;
F_11 ( & V_14 -> V_52 ) ;
if ( V_14 -> V_162 ) {
V_14 -> V_162 = 0 ;
V_14 -> V_260 = NULL ;
F_13 ( & V_14 -> V_52 ) ;
F_240 ( V_260 ) ;
} else {
F_13 ( & V_14 -> V_52 ) ;
}
F_492 ( V_260 ) ;
}
V_21 . V_22 = V_607 ;
V_21 . V_33 = V_14 -> V_21 . V_22 ;
V_21 . type = 0 ;
V_29 = F_37 ( V_109 , V_87 , & V_21 , V_65 , - 1 , 1 ) ;
if ( V_29 < 0 )
goto V_73;
if ( V_29 > 0 )
F_44 ( V_65 ) ;
if ( V_29 == 0 ) {
V_29 = F_115 ( V_109 , V_87 , V_65 ) ;
if ( V_29 )
goto V_73;
F_44 ( V_65 ) ;
}
F_11 ( & V_35 -> V_37 -> V_18 ) ;
F_176 ( & V_14 -> V_20 ,
& V_35 -> V_37 -> V_19 ) ;
if ( V_35 -> V_37 -> V_26 == V_14 -> V_21 . V_22 )
V_35 -> V_37 -> V_26 = ( T_2 ) - 1 ;
F_13 ( & V_35 -> V_37 -> V_18 ) ;
F_62 ( & V_14 -> V_104 -> V_296 ) ;
F_356 ( & V_14 -> V_91 ) ;
if ( F_184 ( & V_14 -> V_104 -> V_293 [ V_506 ] ) ) {
F_469 ( & V_14 -> V_104 -> V_294 [ V_506 ] ) ;
F_470 ( & V_14 -> V_104 -> V_294 [ V_506 ] ) ;
F_489 ( V_35 -> V_37 , V_14 -> V_7 ) ;
}
F_64 ( & V_14 -> V_104 -> V_296 ) ;
if ( V_14 -> V_3 == V_53 )
F_373 ( V_14 ) ;
F_467 ( V_14 ) ;
F_11 ( & V_14 -> V_104 -> V_52 ) ;
V_14 -> V_104 -> V_283 -= V_14 -> V_21 . V_33 ;
V_14 -> V_104 -> V_299 -= V_14 -> V_21 . V_33 ;
V_14 -> V_104 -> V_289 -= V_14 -> V_21 . V_33 * V_285 ;
F_13 ( & V_14 -> V_104 -> V_52 ) ;
memcpy ( & V_21 , & V_14 -> V_21 , sizeof( V_21 ) ) ;
F_72 ( V_35 -> V_37 ) ;
F_6 ( V_14 ) ;
F_6 ( V_14 ) ;
V_29 = F_37 ( V_109 , V_35 , & V_21 , V_65 , - 1 , 1 ) ;
if ( V_29 > 0 )
V_29 = - V_173 ;
if ( V_29 < 0 )
goto V_73;
V_29 = F_115 ( V_109 , V_35 , V_65 ) ;
V_73:
F_50 ( V_65 ) ;
return V_29 ;
}
int F_494 ( struct V_12 * V_37 )
{
struct V_101 * V_104 ;
struct V_608 * V_609 ;
T_2 V_610 ;
T_2 V_7 ;
int V_611 = 0 ;
int V_29 ;
V_609 = V_37 -> V_352 ;
if ( ! F_495 ( V_609 ) )
return 1 ;
V_610 = F_496 ( V_609 ) ;
if ( V_610 & V_612 )
V_611 = 1 ;
V_7 = V_282 ;
V_29 = F_245 ( V_37 , V_7 , 0 , 0 , & V_104 ) ;
if ( V_29 )
goto V_73;
if ( V_611 ) {
V_7 = V_280 | V_281 ;
V_29 = F_245 ( V_37 , V_7 , 0 , 0 , & V_104 ) ;
} else {
V_7 = V_280 ;
V_29 = F_245 ( V_37 , V_7 , 0 , 0 , & V_104 ) ;
if ( V_29 )
goto V_73;
V_7 = V_281 ;
V_29 = F_245 ( V_37 , V_7 , 0 , 0 , & V_104 ) ;
}
V_73:
return V_29 ;
}
int F_497 ( struct V_34 * V_35 , T_2 V_32 , T_2 V_31 )
{
return F_358 ( V_35 , V_32 , V_31 ) ;
}
int F_498 ( struct V_34 * V_35 , T_2 V_27 ,
T_2 V_36 , T_2 * V_185 )
{
return F_141 ( V_35 , V_27 , V_36 , V_185 ) ;
}
int F_499 ( struct V_34 * V_35 , struct V_613 * V_614 )
{
struct V_12 * V_37 = V_35 -> V_37 ;
struct V_1 * V_2 = NULL ;
T_2 V_615 ;
T_2 V_32 ;
T_2 V_31 ;
T_2 V_616 = 0 ;
T_2 V_283 = F_274 ( V_37 -> V_352 ) ;
int V_29 = 0 ;
if ( V_614 -> V_49 == V_283 )
V_2 = F_66 ( V_37 , V_614 -> V_32 ) ;
else
V_2 = F_67 ( V_37 , V_614 -> V_32 ) ;
while ( V_2 ) {
if ( V_2 -> V_21 . V_22 >= ( V_614 -> V_32 + V_614 -> V_49 ) ) {
F_6 ( V_2 ) ;
break;
}
V_32 = F_380 ( V_614 -> V_32 , V_2 -> V_21 . V_22 ) ;
V_31 = F_292 ( V_614 -> V_32 + V_614 -> V_49 ,
V_2 -> V_21 . V_22 + V_2 -> V_21 . V_33 ) ;
if ( V_31 - V_32 >= V_614 -> V_617 ) {
if ( ! F_1 ( V_2 ) ) {
V_29 = F_51 ( V_2 , 0 ) ;
if ( V_29 ) {
F_6 ( V_2 ) ;
break;
}
V_29 = F_373 ( V_2 ) ;
if ( V_29 ) {
F_6 ( V_2 ) ;
break;
}
}
V_29 = F_500 ( V_2 ,
& V_615 ,
V_32 ,
V_31 ,
V_614 -> V_617 ) ;
V_616 += V_615 ;
if ( V_29 ) {
F_6 ( V_2 ) ;
break;
}
}
V_2 = F_225 ( V_37 -> V_87 , V_2 ) ;
}
V_614 -> V_49 = V_616 ;
return V_29 ;
}
