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
if ( V_29 > 0 ) {
F_40 ( V_65 -> V_83 [ 0 ] , & V_21 , V_65 -> V_84 [ 0 ] ) ;
if ( V_21 . V_22 == V_32 &&
V_21 . type == V_86 )
V_29 = 0 ;
}
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
#ifdef F_219
if ( F_220 ( F_221 ( V_265 , & V_35 -> V_266 ) ) )
return 0 ;
#endif
V_212 = F_222 ( V_260 ) ;
V_71 = F_38 ( V_260 ) ;
V_166 = F_223 ( V_260 ) ;
if ( ! F_221 ( V_267 , & V_35 -> V_266 ) && V_166 == 0 )
return 0 ;
if ( V_262 )
F_218 = F_144 ;
else
F_218 = V_268 ;
if ( V_261 )
V_17 = V_260 -> V_32 ;
else
V_17 = 0 ;
for ( V_43 = 0 ; V_43 < V_71 ; V_43 ++ ) {
if ( V_166 == 0 ) {
F_40 ( V_260 , & V_21 , V_43 ) ;
if ( F_224 ( & V_21 ) != V_269 )
continue;
V_264 = F_78 ( V_260 , V_43 ,
struct V_263 ) ;
if ( F_225 ( V_260 , V_264 ) ==
V_270 )
continue;
V_27 = F_226 ( V_260 , V_264 ) ;
if ( V_27 == 0 )
continue;
V_36 = F_227 ( V_260 , V_264 ) ;
V_21 . V_33 -= F_228 ( V_260 , V_264 ) ;
V_29 = F_218 ( V_109 , V_35 , V_27 , V_36 ,
V_17 , V_212 , V_21 . V_22 ,
V_21 . V_33 , 1 ) ;
if ( V_29 )
goto V_155;
} else {
V_27 = F_229 ( V_260 , V_43 ) ;
V_36 = F_230 ( V_35 , V_166 - 1 ) ;
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
int F_231 ( struct V_108 * V_109 , struct V_34 * V_35 ,
struct V_66 * V_260 , int V_261 )
{
return F_217 ( V_109 , V_35 , V_260 , V_261 , 1 ) ;
}
int F_232 ( struct V_108 * V_109 , struct V_34 * V_35 ,
struct V_66 * V_260 , int V_261 )
{
return F_217 ( V_109 , V_35 , V_260 , V_261 , 0 ) ;
}
static int F_233 ( struct V_108 * V_109 ,
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
V_138 = F_234 ( V_67 , V_65 -> V_84 [ 0 ] ) ;
F_235 ( V_67 , & V_2 -> V_134 , V_138 , sizeof( V_2 -> V_134 ) ) ;
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
F_236 ( struct V_34 * V_35 ,
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
static int F_237 ( struct V_1 * V_14 ,
struct V_108 * V_109 ,
struct V_64 * V_65 )
{
struct V_34 * V_35 = V_14 -> V_37 -> V_87 ;
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
V_78:
V_271 = F_238 ( V_35 , V_14 , V_65 ) ;
if ( F_194 ( V_271 ) && F_195 ( V_271 ) != - V_152 ) {
V_29 = F_195 ( V_271 ) ;
F_44 ( V_65 ) ;
goto V_73;
}
if ( F_194 ( V_271 ) ) {
F_30 ( V_276 ) ;
V_276 ++ ;
if ( V_14 -> V_279 )
goto V_122;
V_29 = F_239 ( V_35 , V_109 , V_14 , V_65 ) ;
if ( V_29 )
goto V_122;
goto V_78;
}
if ( V_14 -> V_280 == V_109 -> V_281 &&
F_240 ( V_271 ) ) {
V_273 = V_282 ;
goto V_283;
}
F_241 ( V_271 ) -> V_284 = 0 ;
V_29 = F_242 ( V_109 , V_35 , V_271 ) ;
F_8 ( V_29 ) ;
if ( F_240 ( V_271 ) > 0 ) {
V_29 = F_243 ( V_35 ,
& V_35 -> V_37 -> V_241 ) ;
if ( V_29 )
goto V_283;
V_29 = F_244 ( V_35 , V_109 , V_271 ) ;
if ( V_29 )
goto V_283;
}
F_11 ( & V_14 -> V_52 ) ;
if ( V_14 -> V_3 != V_4 ||
! F_245 ( V_35 , V_285 ) ||
V_14 -> V_286 ) {
V_273 = V_278 ;
F_13 ( & V_14 -> V_52 ) ;
goto V_283;
}
F_13 ( & V_14 -> V_52 ) ;
V_275 = ( int ) F_183 ( V_14 -> V_21 . V_33 , 256 * 1024 * 1024 ) ;
if ( ! V_275 )
V_275 = 1 ;
V_275 *= 16 ;
V_275 *= V_287 ;
V_29 = F_246 ( V_271 , V_275 ) ;
if ( V_29 )
goto V_283;
V_29 = F_247 ( V_271 , V_109 , 0 , 0 , V_275 ,
V_275 , V_275 ,
& V_272 ) ;
if ( ! V_29 )
V_273 = V_282 ;
F_248 ( V_271 , V_275 ) ;
V_283:
F_249 ( V_271 ) ;
V_122:
F_44 ( V_65 ) ;
V_73:
F_11 ( & V_14 -> V_52 ) ;
if ( ! V_29 && V_273 == V_282 )
V_14 -> V_280 = V_109 -> V_281 ;
V_14 -> V_277 = V_273 ;
F_13 ( & V_14 -> V_52 ) ;
return V_29 ;
}
int F_250 ( struct V_108 * V_109 ,
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
if ( V_2 -> V_277 == V_288 )
break;
V_2 = F_236 ( V_35 , V_2 ) ;
}
if ( ! V_2 ) {
if ( V_70 == 0 )
break;
V_70 = 0 ;
continue;
}
V_82 = F_237 ( V_2 , V_109 , V_65 ) ;
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
if ( V_2 -> V_277 == V_288 ) {
F_6 ( V_2 ) ;
goto V_78;
}
if ( V_2 -> V_289 )
break;
V_2 = F_236 ( V_35 , V_2 ) ;
}
if ( ! V_2 ) {
if ( V_70 == 0 )
break;
V_70 = 0 ;
continue;
}
if ( V_2 -> V_277 == V_282 )
V_2 -> V_277 = V_290 ;
V_2 -> V_289 = 0 ;
V_70 = V_2 -> V_21 . V_22 + V_2 -> V_21 . V_33 ;
V_82 = F_233 ( V_109 , V_35 , V_65 , V_2 ) ;
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
if ( V_2 -> V_289 ) {
F_6 ( V_2 ) ;
goto V_78;
}
if ( V_2 -> V_277 == V_290 )
break;
V_2 = F_236 ( V_35 , V_2 ) ;
}
if ( ! V_2 ) {
if ( V_70 == 0 )
break;
V_70 = 0 ;
continue;
}
V_82 = F_251 ( V_35 , V_109 , V_2 , V_65 ) ;
if ( ! V_82 && V_2 -> V_277 == V_290 )
V_2 -> V_277 = V_278 ;
V_70 = V_2 -> V_21 . V_22 + V_2 -> V_21 . V_33 ;
F_6 ( V_2 ) ;
}
V_73:
F_50 ( V_65 ) ;
return V_82 ;
}
int F_252 ( struct V_34 * V_35 , T_2 V_27 )
{
struct V_1 * V_14 ;
int V_291 = 0 ;
V_14 = F_68 ( V_35 -> V_37 , V_27 ) ;
if ( ! V_14 || V_14 -> V_279 )
V_291 = 1 ;
if ( V_14 )
F_6 ( V_14 ) ;
return V_291 ;
}
static const char * F_253 ( T_2 V_7 )
{
switch ( V_7 ) {
case V_292 | V_293 :
return L_3 ;
case V_292 :
return L_4 ;
case V_293 :
return L_5 ;
case V_294 :
return L_6 ;
default:
F_8 ( 1 ) ;
return L_7 ;
} ;
}
static int F_254 ( struct V_12 * V_13 , T_2 V_7 ,
T_2 V_295 , T_2 V_296 ,
struct V_101 * * V_104 )
{
struct V_101 * V_105 ;
int V_43 ;
int V_297 ;
int V_29 ;
if ( V_7 & ( V_298 | V_299 |
V_300 ) )
V_297 = 2 ;
else
V_297 = 1 ;
V_105 = F_69 ( V_13 , V_7 ) ;
if ( V_105 ) {
F_11 ( & V_105 -> V_52 ) ;
V_105 -> V_295 += V_295 ;
V_105 -> V_301 += V_295 * V_297 ;
V_105 -> V_296 += V_296 ;
V_105 -> V_302 += V_296 * V_297 ;
V_105 -> V_107 = 0 ;
F_13 ( & V_105 -> V_52 ) ;
* V_104 = V_105 ;
return 0 ;
}
V_105 = F_53 ( sizeof( * V_105 ) , V_40 ) ;
if ( ! V_105 )
return - V_72 ;
V_29 = F_255 ( & V_105 -> V_303 , 0 ) ;
if ( V_29 ) {
F_9 ( V_105 ) ;
return V_29 ;
}
for ( V_43 = 0 ; V_43 < V_304 ; V_43 ++ )
F_54 ( & V_105 -> V_305 [ V_43 ] ) ;
F_256 ( & V_105 -> V_306 ) ;
F_257 ( & V_105 -> V_52 ) ;
V_105 -> V_7 = V_7 & V_106 ;
V_105 -> V_295 = V_295 ;
V_105 -> V_301 = V_295 * V_297 ;
V_105 -> V_296 = V_296 ;
V_105 -> V_302 = V_296 * V_297 ;
V_105 -> V_307 = 0 ;
V_105 -> V_308 = 0 ;
V_105 -> V_309 = 0 ;
V_105 -> V_310 = 0 ;
V_105 -> V_107 = 0 ;
V_105 -> V_311 = V_312 ;
V_105 -> V_313 = 0 ;
V_105 -> V_314 = 0 ;
F_56 ( & V_105 -> V_89 ) ;
V_29 = F_258 ( & V_105 -> V_315 , & V_316 ,
V_13 -> V_317 , L_8 ,
F_253 ( V_105 -> V_7 ) ) ;
if ( V_29 ) {
F_9 ( V_105 ) ;
return V_29 ;
}
* V_104 = V_105 ;
F_259 ( & V_105 -> V_91 , & V_13 -> V_104 ) ;
if ( V_7 & V_293 )
V_13 -> V_318 = V_105 ;
return V_29 ;
}
static void F_260 ( struct V_12 * V_37 , T_2 V_7 )
{
T_2 V_319 = F_261 ( V_7 ) &
V_320 ;
F_262 ( & V_37 -> V_321 ) ;
if ( V_7 & V_293 )
V_37 -> V_322 |= V_319 ;
if ( V_7 & V_292 )
V_37 -> V_323 |= V_319 ;
if ( V_7 & V_294 )
V_37 -> V_324 |= V_319 ;
F_263 ( & V_37 -> V_321 ) ;
}
static T_2 F_264 ( struct V_12 * V_37 , T_2 V_7 )
{
struct V_325 * V_326 = V_37 -> V_327 ;
T_2 V_328 = 0 ;
if ( ! V_326 )
return 0 ;
if ( V_7 & V_293 &&
V_326 -> V_329 . V_7 & V_330 ) {
V_328 = V_293 | V_326 -> V_329 . V_328 ;
} else if ( V_7 & V_294 &&
V_326 -> V_331 . V_7 & V_330 ) {
V_328 = V_294 | V_326 -> V_331 . V_328 ;
} else if ( V_7 & V_292 &&
V_326 -> V_332 . V_7 & V_330 ) {
V_328 = V_292 | V_326 -> V_332 . V_328 ;
}
return V_328 ;
}
static T_2 F_265 ( struct V_34 * V_35 , T_2 V_7 )
{
T_2 V_333 = V_35 -> V_37 -> V_334 -> V_335 ;
T_2 V_328 ;
T_2 V_336 ;
F_11 ( & V_35 -> V_37 -> V_337 ) ;
V_328 = F_264 ( V_35 -> V_37 , V_7 ) ;
if ( V_328 ) {
if ( ( V_7 & V_328 ) & V_320 ) {
F_13 ( & V_35 -> V_37 -> V_337 ) ;
return F_266 ( V_328 ) ;
}
}
F_13 ( & V_35 -> V_37 -> V_337 ) ;
if ( V_333 == 1 )
V_7 &= ~ ( V_299 | V_338 |
V_339 ) ;
if ( V_333 < 3 )
V_7 &= ~ V_340 ;
if ( V_333 < 4 )
V_7 &= ~ V_300 ;
V_336 = V_7 & ( V_298 | V_338 |
V_299 | V_339 |
V_340 | V_300 ) ;
V_7 &= ~ V_336 ;
if ( V_336 & V_340 )
V_336 = V_340 ;
else if ( V_336 & V_339 )
V_336 = V_339 ;
else if ( V_336 & V_300 )
V_336 = V_300 ;
else if ( V_336 & V_299 )
V_336 = V_299 ;
else if ( V_336 & V_338 )
V_336 = V_338 ;
return F_266 ( V_7 | V_336 ) ;
}
static T_2 F_267 ( struct V_34 * V_35 , T_2 V_341 )
{
unsigned V_221 ;
T_2 V_7 ;
do {
V_7 = V_341 ;
V_221 = F_268 ( & V_35 -> V_37 -> V_321 ) ;
if ( V_7 & V_293 )
V_7 |= V_35 -> V_37 -> V_322 ;
else if ( V_7 & V_294 )
V_7 |= V_35 -> V_37 -> V_324 ;
else if ( V_7 & V_292 )
V_7 |= V_35 -> V_37 -> V_323 ;
} while ( F_269 ( & V_35 -> V_37 -> V_321 , V_221 ) );
return F_265 ( V_35 , V_7 ) ;
}
T_2 F_270 ( struct V_34 * V_35 , int V_329 )
{
T_2 V_7 ;
T_2 V_29 ;
if ( V_329 )
V_7 = V_293 ;
else if ( V_35 == V_35 -> V_37 -> V_342 )
V_7 = V_294 ;
else
V_7 = V_292 ;
V_29 = F_267 ( V_35 , V_7 ) ;
return V_29 ;
}
int F_246 ( struct V_271 * V_271 , T_2 V_343 )
{
struct V_101 * V_318 ;
struct V_34 * V_35 = F_241 ( V_271 ) -> V_35 ;
struct V_12 * V_37 = V_35 -> V_37 ;
T_2 V_344 ;
int V_29 = 0 , V_345 = 0 , V_346 = 1 ;
V_343 = F_271 ( V_343 , V_35 -> V_347 ) ;
if ( F_272 ( V_271 ) ) {
V_345 = 1 ;
ASSERT ( V_348 -> V_349 ) ;
}
V_318 = V_37 -> V_318 ;
if ( ! V_318 )
goto V_350;
V_78:
F_11 ( & V_318 -> V_52 ) ;
V_344 = V_318 -> V_296 + V_318 -> V_308 +
V_318 -> V_307 + V_318 -> V_309 +
V_318 -> V_310 ;
if ( V_344 + V_343 > V_318 -> V_295 ) {
struct V_108 * V_109 ;
if ( ! V_318 -> V_107 && V_346 ) {
T_2 V_351 ;
V_318 -> V_311 = V_352 ;
F_13 ( & V_318 -> V_52 ) ;
V_350:
V_351 = F_270 ( V_35 , 1 ) ;
V_109 = F_193 ( V_35 ) ;
if ( F_194 ( V_109 ) )
return F_195 ( V_109 ) ;
V_29 = F_273 ( V_109 , V_35 -> V_37 -> V_63 ,
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
if ( F_274 ( & V_318 -> V_303 ,
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
V_29 = F_275 ( V_109 , V_35 ) ;
if ( V_29 )
return V_29 ;
goto V_78;
}
F_276 ( V_35 -> V_37 ,
L_9 ,
V_318 -> V_7 , V_343 , 1 ) ;
return - V_353 ;
}
V_318 -> V_310 += V_343 ;
F_276 ( V_35 -> V_37 , L_10 ,
V_318 -> V_7 , V_343 , 1 ) ;
F_13 ( & V_318 -> V_52 ) ;
return 0 ;
}
void F_248 ( struct V_271 * V_271 , T_2 V_343 )
{
struct V_34 * V_35 = F_241 ( V_271 ) -> V_35 ;
struct V_101 * V_318 ;
V_343 = F_271 ( V_343 , V_35 -> V_347 ) ;
V_318 = V_35 -> V_37 -> V_318 ;
F_11 ( & V_318 -> V_52 ) ;
F_8 ( V_318 -> V_310 < V_343 ) ;
V_318 -> V_310 -= V_343 ;
F_276 ( V_35 -> V_37 , L_10 ,
V_318 -> V_7 , V_343 , 0 ) ;
F_13 ( & V_318 -> V_52 ) ;
}
static void F_277 ( struct V_12 * V_13 )
{
struct V_102 * V_103 = & V_13 -> V_104 ;
struct V_101 * V_105 ;
F_70 () ;
F_71 (found, head, list) {
if ( V_105 -> V_7 & V_292 )
V_105 -> V_311 = V_352 ;
}
F_72 () ;
}
static inline T_2 F_278 ( struct V_239 * V_356 )
{
return ( V_356 -> V_57 << 1 ) ;
}
static int F_279 ( struct V_34 * V_35 ,
struct V_101 * V_357 , int V_358 )
{
struct V_239 * V_240 = & V_35 -> V_37 -> V_241 ;
T_2 V_36 = V_357 -> V_295 - V_357 -> V_309 ;
T_2 V_359 = V_357 -> V_296 + V_357 -> V_308 ;
T_2 V_360 ;
if ( V_358 == V_352 )
return 1 ;
if ( V_357 -> V_7 & V_292 )
V_359 += F_278 ( V_240 ) ;
if ( V_358 == V_361 ) {
V_360 = F_280 ( V_35 -> V_37 -> V_362 ) ;
V_360 = F_34 ( T_2 , 64 * 1024 * 1024 ,
F_281 ( V_360 , 1 ) ) ;
if ( V_36 - V_359 < V_360 )
return 1 ;
}
if ( V_359 + 2 * 1024 * 1024 < F_282 ( V_36 , 8 ) )
return 0 ;
return 1 ;
}
static T_2 F_283 ( struct V_34 * V_35 , T_2 type )
{
T_2 V_363 ;
if ( type & ( V_300 |
V_338 |
V_339 |
V_340 ) )
V_363 = V_35 -> V_37 -> V_334 -> V_335 ;
else if ( type & V_299 )
V_363 = 2 ;
else
V_363 = 1 ;
return F_189 ( V_35 , V_363 + 1 ) ;
}
static void F_284 ( struct V_108 * V_109 ,
struct V_34 * V_35 , T_2 type )
{
struct V_101 * V_13 ;
T_2 V_364 ;
T_2 V_360 ;
V_13 = F_69 ( V_35 -> V_37 , V_294 ) ;
F_11 ( & V_13 -> V_52 ) ;
V_364 = V_13 -> V_295 - V_13 -> V_296 - V_13 -> V_307 -
V_13 -> V_308 - V_13 -> V_309 ;
F_13 ( & V_13 -> V_52 ) ;
V_360 = F_283 ( V_35 , type ) ;
if ( V_364 < V_360 && F_245 ( V_35 , V_365 ) ) {
F_285 ( V_35 -> V_37 , L_11 ,
V_364 , V_360 , type ) ;
F_286 ( V_13 , 0 , 0 ) ;
}
if ( V_364 < V_360 ) {
T_2 V_7 ;
V_7 = F_270 ( V_35 -> V_37 -> V_342 , 0 ) ;
F_287 ( V_109 , V_35 , V_7 ) ;
}
}
static int F_273 ( struct V_108 * V_109 ,
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
V_29 = F_254 ( V_63 -> V_37 , V_7 ,
0 , 0 , & V_104 ) ;
F_30 ( V_29 ) ;
}
F_30 ( ! V_104 ) ;
V_78:
F_11 ( & V_104 -> V_52 ) ;
if ( V_358 < V_104 -> V_311 )
V_358 = V_104 -> V_311 ;
if ( V_104 -> V_107 ) {
if ( F_279 ( V_63 , V_104 , V_358 ) )
V_29 = - V_353 ;
else
V_29 = 0 ;
F_13 ( & V_104 -> V_52 ) ;
return V_29 ;
}
if ( ! F_279 ( V_63 , V_104 , V_358 ) ) {
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
if ( F_288 ( V_104 ) )
V_7 |= ( V_293 | V_292 ) ;
if ( V_7 & V_293 && V_37 -> V_369 ) {
V_37 -> V_370 ++ ;
if ( ! ( V_37 -> V_370 %
V_37 -> V_369 ) )
F_277 ( V_37 ) ;
}
F_284 ( V_109 , V_63 , V_7 ) ;
V_29 = F_287 ( V_109 , V_63 , V_7 ) ;
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
static int F_289 ( struct V_34 * V_35 ,
struct V_101 * V_104 , T_2 V_343 ,
enum V_371 V_314 )
{
struct V_239 * V_240 = & V_35 -> V_37 -> V_241 ;
T_2 V_372 = F_270 ( V_35 , 0 ) ;
T_2 V_373 ;
T_2 V_374 ;
T_2 V_344 ;
V_344 = V_104 -> V_296 + V_104 -> V_308 +
V_104 -> V_307 + V_104 -> V_309 ;
F_11 ( & V_240 -> V_52 ) ;
V_373 = F_278 ( V_240 ) ;
F_13 ( & V_240 -> V_52 ) ;
if ( V_344 + V_373 >= V_104 -> V_295 )
return 0 ;
V_344 += V_104 -> V_310 ;
F_11 ( & V_35 -> V_37 -> V_375 ) ;
V_374 = V_35 -> V_37 -> V_376 ;
F_13 ( & V_35 -> V_37 -> V_375 ) ;
if ( V_372 & ( V_298 |
V_299 |
V_300 ) )
V_374 >>= 1 ;
if ( V_314 == V_377 )
V_374 >>= 3 ;
else
V_374 >>= 1 ;
if ( V_344 + V_343 < V_104 -> V_295 + V_374 )
return 1 ;
return 0 ;
}
static void F_290 ( struct V_34 * V_35 ,
unsigned long V_378 , int V_379 )
{
struct V_380 * V_381 = V_35 -> V_37 -> V_381 ;
if ( F_291 ( & V_381 -> V_382 ) ) {
F_292 ( V_381 , V_378 , V_383 ) ;
F_45 ( & V_381 -> V_382 ) ;
} else {
F_293 ( V_35 -> V_37 , 0 , V_379 ) ;
if ( ! V_348 -> V_349 )
F_294 ( V_35 -> V_37 , V_379 ) ;
}
}
static inline int F_295 ( struct V_34 * V_35 , T_2 V_384 )
{
T_2 V_343 ;
int V_44 ;
V_343 = F_189 ( V_35 , 1 ) ;
V_44 = ( int ) F_183 ( V_384 , V_343 ) ;
if ( ! V_44 )
V_44 = 1 ;
return V_44 ;
}
static void F_296 ( struct V_34 * V_35 , T_2 V_384 , T_2 V_385 ,
bool V_386 )
{
struct V_239 * V_387 ;
struct V_101 * V_104 ;
struct V_108 * V_109 ;
T_2 V_286 ;
T_2 V_388 ;
long V_389 ;
unsigned long V_378 ;
int V_390 ;
int V_391 ;
enum V_371 V_314 ;
V_391 = F_295 ( V_35 , V_384 ) ;
V_384 = V_391 * V_392 ;
V_109 = (struct V_108 * ) V_348 -> V_349 ;
V_387 = & V_35 -> V_37 -> V_393 ;
V_104 = V_387 -> V_104 ;
V_286 = F_297 (
& V_35 -> V_37 -> V_286 ) ;
if ( V_286 == 0 ) {
if ( V_109 )
return;
if ( V_386 )
F_294 ( V_35 -> V_37 , V_391 ) ;
return;
}
V_390 = 0 ;
while ( V_286 && V_390 < 3 ) {
V_388 = F_298 ( V_286 , V_384 ) ;
V_378 = V_388 >> V_394 ;
F_290 ( V_35 , V_378 , V_391 ) ;
V_388 = F_191 ( & V_35 -> V_37 -> V_395 ) ;
if ( ! V_388 )
goto V_396;
if ( V_388 <= V_378 )
V_388 = 0 ;
else
V_388 -= V_378 ;
F_299 ( V_35 -> V_37 -> V_397 ,
F_191 ( & V_35 -> V_37 -> V_395 ) <=
( int ) V_388 ) ;
V_396:
if ( ! V_109 )
V_314 = V_377 ;
else
V_314 = V_398 ;
F_11 ( & V_104 -> V_52 ) ;
if ( F_289 ( V_35 , V_104 , V_385 , V_314 ) ) {
F_13 ( & V_104 -> V_52 ) ;
break;
}
F_13 ( & V_104 -> V_52 ) ;
V_390 ++ ;
if ( V_386 && ! V_109 ) {
F_294 ( V_35 -> V_37 , V_391 ) ;
} else {
V_389 = F_300 ( 1 ) ;
if ( V_389 )
break;
}
V_286 = F_297 (
& V_35 -> V_37 -> V_286 ) ;
}
}
static int F_301 ( struct V_34 * V_35 ,
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
if ( F_274 ( & V_104 -> V_303 ,
V_343 ) >= 0 )
goto V_401;
if ( V_104 != V_399 -> V_104 )
return - V_353 ;
F_11 ( & V_399 -> V_52 ) ;
if ( F_274 ( & V_104 -> V_303 ,
V_343 - V_399 -> V_57 ) >= 0 ) {
F_13 ( & V_399 -> V_52 ) ;
return - V_353 ;
}
F_13 ( & V_399 -> V_52 ) ;
V_401:
V_109 = F_193 ( V_35 ) ;
if ( F_194 ( V_109 ) )
return - V_353 ;
return F_275 ( V_109 , V_35 ) ;
}
static int F_302 ( struct V_34 * V_35 ,
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
V_44 = F_295 ( V_35 , V_36 ) * 2 ;
else
V_44 = - 1 ;
V_109 = F_193 ( V_35 ) ;
if ( F_194 ( V_109 ) ) {
V_29 = F_195 ( V_109 ) ;
break;
}
V_29 = F_303 ( V_109 , V_35 , V_44 ) ;
F_197 ( V_109 , V_35 ) ;
break;
case V_405 :
case V_406 :
F_296 ( V_35 , V_36 * 2 , V_402 ,
V_266 == V_406 ) ;
break;
case V_407 :
V_109 = F_193 ( V_35 ) ;
if ( F_194 ( V_109 ) ) {
V_29 = F_195 ( V_109 ) ;
break;
}
V_29 = F_273 ( V_109 , V_35 -> V_37 -> V_63 ,
F_270 ( V_35 , 0 ) ,
V_312 ) ;
F_197 ( V_109 , V_35 ) ;
if ( V_29 == - V_353 )
V_29 = 0 ;
break;
case V_408 :
V_29 = F_301 ( V_35 , V_104 , V_402 , 0 ) ;
break;
default:
V_29 = - V_353 ;
break;
}
return V_29 ;
}
static inline T_2
F_304 ( struct V_34 * V_35 ,
struct V_101 * V_104 )
{
T_2 V_344 ;
T_2 V_409 ;
T_2 V_384 ;
V_384 = F_24 ( T_2 , F_305 () * 1024 * 1024 ,
16 * 1024 * 1024 ) ;
F_11 ( & V_104 -> V_52 ) ;
if ( F_289 ( V_35 , V_104 , V_384 ,
V_377 ) ) {
V_384 = 0 ;
goto V_73;
}
V_344 = V_104 -> V_296 + V_104 -> V_308 +
V_104 -> V_307 + V_104 -> V_309 +
V_104 -> V_310 ;
if ( F_289 ( V_35 , V_104 , 1024 * 1024 ,
V_377 ) )
V_409 = F_281 ( V_104 -> V_295 , 95 ) ;
else
V_409 = F_281 ( V_104 -> V_295 , 90 ) ;
if ( V_344 > V_409 )
V_384 = V_344 - V_409 ;
else
V_384 = 0 ;
V_384 = F_298 ( V_384 , V_104 -> V_310 +
V_104 -> V_308 ) ;
V_73:
F_13 ( & V_104 -> V_52 ) ;
return V_384 ;
}
static inline int F_306 ( struct V_101 * V_104 ,
struct V_12 * V_37 , T_2 V_344 )
{
return ( V_344 >= F_281 ( V_104 -> V_295 , 98 ) &&
! F_39 ( V_37 ) &&
! F_221 ( V_410 , & V_37 -> V_411 ) ) ;
}
static int F_307 ( struct V_101 * V_104 ,
struct V_12 * V_37 )
{
T_2 V_344 ;
F_11 ( & V_104 -> V_52 ) ;
V_344 = V_104 -> V_296 + V_104 -> V_308 +
V_104 -> V_307 + V_104 -> V_309 +
V_104 -> V_310 ;
if ( F_306 ( V_104 , V_37 , V_344 ) ) {
F_13 ( & V_104 -> V_52 ) ;
return 1 ;
}
F_13 ( & V_104 -> V_52 ) ;
return 0 ;
}
static void F_308 ( struct V_412 * V_62 )
{
struct V_12 * V_37 ;
struct V_101 * V_104 ;
T_2 V_384 ;
int V_413 ;
V_37 = F_32 ( V_62 , struct V_12 , V_414 ) ;
V_104 = F_69 ( V_37 , V_292 ) ;
V_384 = F_304 ( V_37 -> V_415 ,
V_104 ) ;
if ( ! V_384 )
return;
V_413 = V_403 ;
do {
F_302 ( V_37 -> V_415 , V_104 , V_384 ,
V_384 , V_413 ) ;
V_413 ++ ;
if ( ! F_307 ( V_104 , V_37 ) )
return;
} while ( V_413 <= V_408 );
if ( F_307 ( V_104 , V_37 ) )
F_309 ( V_416 , V_62 ) ;
}
void F_310 ( struct V_412 * V_62 )
{
F_311 ( V_62 , F_308 ) ;
}
static int F_312 ( struct V_34 * V_35 ,
struct V_239 * V_387 ,
T_2 V_402 ,
enum V_371 V_314 )
{
struct V_101 * V_104 = V_387 -> V_104 ;
T_2 V_344 ;
T_2 V_36 = V_402 ;
int V_413 = V_403 ;
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
V_29 = F_313 ( V_104 -> V_89 , ! V_104 -> V_314 ) ;
if ( V_29 )
return - V_418 ;
F_11 ( & V_104 -> V_52 ) ;
}
V_29 = - V_353 ;
V_344 = V_104 -> V_296 + V_104 -> V_308 +
V_104 -> V_307 + V_104 -> V_309 +
V_104 -> V_310 ;
if ( V_344 <= V_104 -> V_295 ) {
if ( V_344 + V_402 <= V_104 -> V_295 ) {
V_104 -> V_310 += V_402 ;
F_276 ( V_35 -> V_37 ,
L_10 , V_104 -> V_7 , V_402 , 1 ) ;
V_29 = 0 ;
} else {
V_36 = V_402 ;
}
} else {
V_36 = V_344 - V_104 -> V_295 +
( V_402 * 2 ) ;
}
if ( V_29 && F_289 ( V_35 , V_104 , V_402 , V_314 ) ) {
V_104 -> V_310 += V_402 ;
F_276 ( V_35 -> V_37 , L_10 ,
V_104 -> V_7 , V_402 ,
1 ) ;
V_29 = 0 ;
}
if ( V_29 && V_314 != V_398 ) {
V_417 = true ;
V_104 -> V_314 = 1 ;
} else if ( ! V_29 && V_104 -> V_7 & V_292 ) {
V_344 += V_402 ;
if ( F_306 ( V_104 , V_35 -> V_37 , V_344 ) &&
! F_314 ( & V_35 -> V_37 -> V_414 ) )
F_309 ( V_416 ,
& V_35 -> V_37 -> V_414 ) ;
}
F_13 ( & V_104 -> V_52 ) ;
if ( ! V_29 || V_314 == V_398 )
goto V_73;
V_29 = F_302 ( V_35 , V_104 , V_36 , V_402 ,
V_413 ) ;
V_413 ++ ;
if ( V_314 == V_419 &&
( V_413 == V_405 ||
V_413 == V_406 ) )
V_413 = V_407 ;
if ( ! V_29 )
goto V_78;
else if ( V_314 == V_419 &&
V_413 < V_408 )
goto V_78;
else if ( V_314 == V_377 &&
V_413 <= V_408 )
goto V_78;
V_73:
if ( V_29 == - V_353 &&
F_220 ( V_35 -> V_420 == V_421 ) ) {
struct V_239 * V_240 =
& V_35 -> V_37 -> V_241 ;
if ( V_387 != V_240 &&
! F_315 ( V_240 , V_402 ) )
V_29 = 0 ;
}
if ( V_29 == - V_353 )
F_276 ( V_35 -> V_37 ,
L_9 ,
V_104 -> V_7 , V_402 , 1 ) ;
if ( V_417 ) {
F_11 ( & V_104 -> V_52 ) ;
V_104 -> V_314 = 0 ;
F_316 ( & V_104 -> V_89 ) ;
F_13 ( & V_104 -> V_52 ) ;
}
return V_29 ;
}
static struct V_239 * F_317 (
const struct V_108 * V_109 ,
const struct V_34 * V_35 )
{
struct V_239 * V_387 = NULL ;
if ( F_221 ( V_267 , & V_35 -> V_266 ) )
V_387 = V_109 -> V_387 ;
if ( V_35 == V_35 -> V_37 -> V_422 && V_109 -> V_423 )
V_387 = V_109 -> V_387 ;
if ( V_35 == V_35 -> V_37 -> V_424 )
V_387 = V_109 -> V_387 ;
if ( ! V_387 )
V_387 = V_35 -> V_387 ;
if ( ! V_387 )
V_387 = & V_35 -> V_37 -> V_425 ;
return V_387 ;
}
static int F_315 ( struct V_239 * V_387 ,
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
static void F_318 ( struct V_239 * V_387 ,
T_2 V_36 , int V_426 )
{
F_11 ( & V_387 -> V_52 ) ;
V_387 -> V_10 += V_36 ;
if ( V_426 )
V_387 -> V_57 += V_36 ;
else if ( V_387 -> V_10 >= V_387 -> V_57 )
V_387 -> V_107 = 1 ;
F_13 ( & V_387 -> V_52 ) ;
}
int F_319 ( struct V_12 * V_37 ,
struct V_239 * V_427 , T_2 V_36 ,
int V_428 )
{
struct V_239 * V_240 = & V_37 -> V_241 ;
T_2 V_429 ;
if ( V_240 -> V_104 != V_427 -> V_104 )
return - V_353 ;
F_11 ( & V_240 -> V_52 ) ;
V_429 = F_282 ( V_240 -> V_57 , V_428 ) ;
if ( V_240 -> V_10 < V_429 + V_36 ) {
F_13 ( & V_240 -> V_52 ) ;
return - V_353 ;
}
V_240 -> V_10 -= V_36 ;
if ( V_240 -> V_10 < V_240 -> V_57 )
V_240 -> V_107 = 0 ;
F_13 ( & V_240 -> V_52 ) ;
F_318 ( V_427 , V_36 , 1 ) ;
return 0 ;
}
static void F_320 ( struct V_12 * V_37 ,
struct V_239 * V_387 ,
struct V_239 * V_427 , T_2 V_36 )
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
if ( V_427 ) {
F_11 ( & V_427 -> V_52 ) ;
if ( ! V_427 -> V_107 ) {
T_2 V_430 ;
V_430 = V_427 -> V_57 - V_427 -> V_10 ;
V_430 = F_298 ( V_36 , V_430 ) ;
V_427 -> V_10 += V_430 ;
if ( V_427 -> V_10 >= V_427 -> V_57 )
V_427 -> V_107 = 1 ;
V_36 -= V_430 ;
}
F_13 ( & V_427 -> V_52 ) ;
}
if ( V_36 ) {
F_11 ( & V_104 -> V_52 ) ;
V_104 -> V_310 -= V_36 ;
F_276 ( V_37 , L_10 ,
V_104 -> V_7 , V_36 , 0 ) ;
F_13 ( & V_104 -> V_52 ) ;
}
}
}
static int F_321 ( struct V_239 * V_431 ,
struct V_239 * V_432 , T_2 V_36 )
{
int V_29 ;
V_29 = F_315 ( V_431 , V_36 ) ;
if ( V_29 )
return V_29 ;
F_318 ( V_432 , V_36 , 1 ) ;
return 0 ;
}
void F_322 ( struct V_239 * V_433 , unsigned short type )
{
memset ( V_433 , 0 , sizeof( * V_433 ) ) ;
F_257 ( & V_433 -> V_52 ) ;
V_433 -> type = type ;
}
struct V_239 * F_323 ( struct V_34 * V_35 ,
unsigned short type )
{
struct V_239 * V_387 ;
struct V_12 * V_37 = V_35 -> V_37 ;
V_387 = F_200 ( sizeof( * V_387 ) , V_40 ) ;
if ( ! V_387 )
return NULL ;
F_322 ( V_387 , type ) ;
V_387 -> V_104 = F_69 ( V_37 ,
V_292 ) ;
return V_387 ;
}
void F_324 ( struct V_34 * V_35 ,
struct V_239 * V_433 )
{
if ( ! V_433 )
return;
F_325 ( V_35 , V_433 , ( T_2 ) - 1 ) ;
F_9 ( V_433 ) ;
}
int F_326 ( struct V_34 * V_35 ,
struct V_239 * V_387 , T_2 V_36 ,
enum V_371 V_314 )
{
int V_29 ;
if ( V_36 == 0 )
return 0 ;
V_29 = F_312 ( V_35 , V_387 , V_36 , V_314 ) ;
if ( ! V_29 ) {
F_318 ( V_387 , V_36 , 1 ) ;
return 0 ;
}
return V_29 ;
}
int F_327 ( struct V_34 * V_35 ,
struct V_239 * V_387 , int V_428 )
{
T_2 V_36 = 0 ;
int V_29 = - V_353 ;
if ( ! V_387 )
return 0 ;
F_11 ( & V_387 -> V_52 ) ;
V_36 = F_282 ( V_387 -> V_57 , V_428 ) ;
if ( V_387 -> V_10 >= V_36 )
V_29 = 0 ;
F_13 ( & V_387 -> V_52 ) ;
return V_29 ;
}
int F_328 ( struct V_34 * V_35 ,
struct V_239 * V_387 , T_2 V_434 ,
enum V_371 V_314 )
{
T_2 V_36 = 0 ;
int V_29 = - V_353 ;
if ( ! V_387 )
return 0 ;
F_11 ( & V_387 -> V_52 ) ;
V_36 = V_434 ;
if ( V_387 -> V_10 >= V_36 )
V_29 = 0 ;
else
V_36 -= V_387 -> V_10 ;
F_13 ( & V_387 -> V_52 ) ;
if ( ! V_29 )
return 0 ;
V_29 = F_312 ( V_35 , V_387 , V_36 , V_314 ) ;
if ( ! V_29 ) {
F_318 ( V_387 , V_36 , 0 ) ;
return 0 ;
}
return V_29 ;
}
int F_329 ( struct V_239 * V_435 ,
struct V_239 * V_436 ,
T_2 V_36 )
{
return F_321 ( V_435 , V_436 , V_36 ) ;
}
void F_325 ( struct V_34 * V_35 ,
struct V_239 * V_387 ,
T_2 V_36 )
{
struct V_239 * V_240 = & V_35 -> V_37 -> V_241 ;
if ( V_240 == V_387 ||
V_387 -> V_104 != V_240 -> V_104 )
V_240 = NULL ;
F_320 ( V_35 -> V_37 , V_387 , V_240 ,
V_36 ) ;
}
static T_2 F_330 ( struct V_12 * V_37 )
{
struct V_101 * V_357 ;
T_2 V_36 ;
T_2 V_437 ;
T_2 V_438 ;
int V_439 = F_331 ( V_37 -> V_362 ) ;
V_357 = F_69 ( V_37 , V_293 ) ;
F_11 ( & V_357 -> V_52 ) ;
V_438 = V_357 -> V_296 ;
F_13 ( & V_357 -> V_52 ) ;
V_357 = F_69 ( V_37 , V_292 ) ;
F_11 ( & V_357 -> V_52 ) ;
if ( V_357 -> V_7 & V_293 )
V_438 = 0 ;
V_437 = V_357 -> V_296 ;
F_13 ( & V_357 -> V_52 ) ;
V_36 = ( V_438 >> V_37 -> V_381 -> V_440 ) *
V_439 * 2 ;
V_36 += F_183 ( V_438 + V_437 , 50 ) ;
if ( V_36 * 3 > V_437 )
V_36 = F_183 ( V_437 , 3 ) ;
return F_271 ( V_36 , V_37 -> V_63 -> V_88 << 10 ) ;
}
static void F_332 ( struct V_12 * V_37 )
{
struct V_239 * V_387 = & V_37 -> V_241 ;
struct V_101 * V_357 = V_387 -> V_104 ;
T_2 V_36 ;
V_36 = F_330 ( V_37 ) ;
F_11 ( & V_357 -> V_52 ) ;
F_11 ( & V_387 -> V_52 ) ;
V_387 -> V_57 = F_24 ( T_2 , V_36 , 512 * 1024 * 1024 ) ;
V_36 = V_357 -> V_296 + V_357 -> V_307 +
V_357 -> V_308 + V_357 -> V_309 +
V_357 -> V_310 ;
if ( V_357 -> V_295 > V_36 ) {
V_36 = V_357 -> V_295 - V_36 ;
V_387 -> V_10 += V_36 ;
V_357 -> V_310 += V_36 ;
F_276 ( V_37 , L_10 ,
V_357 -> V_7 , V_36 , 1 ) ;
}
if ( V_387 -> V_10 >= V_387 -> V_57 ) {
V_36 = V_387 -> V_10 - V_387 -> V_57 ;
V_357 -> V_310 -= V_36 ;
F_276 ( V_37 , L_10 ,
V_357 -> V_7 , V_36 , 0 ) ;
V_387 -> V_10 = V_387 -> V_57 ;
V_387 -> V_107 = 1 ;
}
F_13 ( & V_387 -> V_52 ) ;
F_13 ( & V_357 -> V_52 ) ;
}
static void F_333 ( struct V_12 * V_37 )
{
struct V_101 * V_104 ;
V_104 = F_69 ( V_37 , V_294 ) ;
V_37 -> V_441 . V_104 = V_104 ;
V_104 = F_69 ( V_37 , V_292 ) ;
V_37 -> V_241 . V_104 = V_104 ;
V_37 -> V_393 . V_104 = V_104 ;
V_37 -> V_442 . V_104 = V_104 ;
V_37 -> V_425 . V_104 = V_104 ;
V_37 -> V_400 . V_104 = V_104 ;
V_37 -> V_63 -> V_387 = & V_37 -> V_241 ;
V_37 -> V_422 -> V_387 = & V_37 -> V_241 ;
V_37 -> V_443 -> V_387 = & V_37 -> V_241 ;
V_37 -> V_87 -> V_387 = & V_37 -> V_241 ;
if ( V_37 -> V_444 )
V_37 -> V_444 -> V_387 = & V_37 -> V_241 ;
V_37 -> V_342 -> V_387 = & V_37 -> V_441 ;
F_332 ( V_37 ) ;
}
static void F_334 ( struct V_12 * V_37 )
{
F_320 ( V_37 , & V_37 -> V_241 , NULL ,
( T_2 ) - 1 ) ;
F_8 ( V_37 -> V_393 . V_57 > 0 ) ;
F_8 ( V_37 -> V_393 . V_10 > 0 ) ;
F_8 ( V_37 -> V_442 . V_57 > 0 ) ;
F_8 ( V_37 -> V_442 . V_10 > 0 ) ;
F_8 ( V_37 -> V_441 . V_57 > 0 ) ;
F_8 ( V_37 -> V_441 . V_10 > 0 ) ;
F_8 ( V_37 -> V_400 . V_57 > 0 ) ;
F_8 ( V_37 -> V_400 . V_10 > 0 ) ;
}
void F_335 ( struct V_108 * V_109 ,
struct V_34 * V_35 )
{
if ( ! V_109 -> V_387 )
return;
if ( ! V_109 -> V_308 )
return;
F_276 ( V_35 -> V_37 , L_12 ,
V_109 -> V_281 , V_109 -> V_308 , 0 ) ;
F_325 ( V_35 , V_109 -> V_387 , V_109 -> V_308 ) ;
V_109 -> V_308 = 0 ;
}
int F_336 ( struct V_108 * V_109 ,
struct V_271 * V_271 )
{
struct V_34 * V_35 = F_241 ( V_271 ) -> V_35 ;
struct V_239 * V_435 = F_317 ( V_109 , V_35 ) ;
struct V_239 * V_436 = V_35 -> V_445 ;
T_2 V_36 = F_189 ( V_35 , 1 ) ;
F_276 ( V_35 -> V_37 , L_13 ,
F_337 ( V_271 ) , V_36 , 1 ) ;
return F_321 ( V_435 , V_436 , V_36 ) ;
}
void F_338 ( struct V_271 * V_271 )
{
struct V_34 * V_35 = F_241 ( V_271 ) -> V_35 ;
T_2 V_36 = F_189 ( V_35 , 1 ) ;
F_276 ( V_35 -> V_37 , L_13 ,
F_337 ( V_271 ) , V_36 , 0 ) ;
F_325 ( V_35 , V_35 -> V_445 , V_36 ) ;
}
int F_339 ( struct V_34 * V_35 ,
struct V_239 * V_433 ,
int V_391 ,
T_2 * V_446 ,
bool V_447 )
{
T_2 V_36 ;
int V_29 ;
struct V_239 * V_240 = & V_35 -> V_37 -> V_241 ;
if ( V_35 -> V_37 -> V_205 ) {
V_36 = 3 * V_35 -> V_88 ;
V_29 = F_340 ( V_35 , V_36 ) ;
if ( V_29 )
return V_29 ;
} else {
V_36 = 0 ;
}
* V_446 = V_36 ;
V_36 = F_189 ( V_35 , V_391 ) ;
V_433 -> V_104 = F_69 ( V_35 -> V_37 ,
V_292 ) ;
V_29 = F_326 ( V_35 , V_433 , V_36 ,
V_377 ) ;
if ( V_29 == - V_353 && V_447 )
V_29 = F_329 ( V_240 , V_433 , V_36 ) ;
if ( V_29 ) {
if ( * V_446 )
F_341 ( V_35 , * V_446 ) ;
}
return V_29 ;
}
void F_342 ( struct V_34 * V_35 ,
struct V_239 * V_433 ,
T_2 V_446 )
{
F_325 ( V_35 , V_433 , ( T_2 ) - 1 ) ;
if ( V_446 )
F_341 ( V_35 , V_446 ) ;
}
static unsigned F_343 ( struct V_271 * V_271 )
{
unsigned V_448 = 0 ;
unsigned V_449 = 0 ;
F_30 ( ! F_241 ( V_271 ) -> V_450 ) ;
F_241 ( V_271 ) -> V_450 -- ;
if ( F_241 ( V_271 ) -> V_450 == 0 &&
F_344 ( V_451 ,
& F_241 ( V_271 ) -> V_452 ) )
V_448 = 1 ;
if ( F_241 ( V_271 ) -> V_450 >=
F_241 ( V_271 ) -> V_453 )
return V_448 ;
V_449 = F_241 ( V_271 ) -> V_453 -
F_241 ( V_271 ) -> V_450 ;
F_241 ( V_271 ) -> V_453 -= V_449 ;
return V_449 + V_448 ;
}
static T_2 F_345 ( struct V_271 * V_271 , T_2 V_36 ,
int V_454 )
{
struct V_34 * V_35 = F_241 ( V_271 ) -> V_35 ;
T_2 V_439 ;
int V_455 ;
int V_456 ;
int V_457 ;
if ( F_241 ( V_271 ) -> V_7 & V_458 &&
F_241 ( V_271 ) -> V_459 == 0 )
return 0 ;
V_457 = ( int ) F_183 ( F_241 ( V_271 ) -> V_459 , V_35 -> V_347 ) ;
if ( V_454 )
F_241 ( V_271 ) -> V_459 += V_36 ;
else
F_241 ( V_271 ) -> V_459 -= V_36 ;
V_439 = F_187 ( V_35 ) - sizeof( struct V_460 ) ;
V_455 = ( int ) F_183 ( V_439 ,
sizeof( struct V_461 ) +
sizeof( struct V_462 ) ) ;
V_456 = ( int ) F_183 ( F_241 ( V_271 ) -> V_459 , V_35 -> V_347 ) ;
V_456 = V_456 + V_455 - 1 ;
V_456 = V_456 / V_455 ;
V_457 = V_457 + V_455 - 1 ;
V_457 = V_457 / V_455 ;
if ( V_457 == V_456 )
return 0 ;
if ( V_454 )
return F_189 ( V_35 ,
V_456 - V_457 ) ;
return F_189 ( V_35 , V_457 - V_456 ) ;
}
int F_346 ( struct V_271 * V_271 , T_2 V_36 )
{
struct V_34 * V_35 = F_241 ( V_271 ) -> V_35 ;
struct V_239 * V_387 = & V_35 -> V_37 -> V_393 ;
T_2 V_463 = 0 ;
T_2 V_459 ;
unsigned V_464 = 0 ;
int V_465 = 0 ;
enum V_371 V_314 = V_377 ;
int V_29 = 0 ;
bool V_466 = true ;
T_2 V_467 = 0 ;
unsigned V_468 ;
if ( F_272 ( V_271 ) ) {
V_314 = V_398 ;
V_466 = false ;
}
if ( V_314 != V_398 &&
F_347 ( V_35 -> V_37 ) )
F_348 ( 1 ) ;
if ( V_466 )
F_35 ( & F_241 ( V_271 ) -> V_469 ) ;
V_36 = F_271 ( V_36 , V_35 -> V_347 ) ;
F_11 ( & F_241 ( V_271 ) -> V_52 ) ;
F_241 ( V_271 ) -> V_450 ++ ;
if ( F_241 ( V_271 ) -> V_450 >
F_241 ( V_271 ) -> V_453 )
V_464 = F_241 ( V_271 ) -> V_450 -
F_241 ( V_271 ) -> V_453 ;
if ( ! F_221 ( V_451 ,
& F_241 ( V_271 ) -> V_452 ) ) {
V_464 ++ ;
V_465 = 1 ;
}
V_463 = F_189 ( V_35 , V_464 ) ;
V_463 += F_345 ( V_271 , V_36 , 1 ) ;
V_459 = F_241 ( V_271 ) -> V_459 ;
F_13 ( & F_241 ( V_271 ) -> V_52 ) ;
if ( V_35 -> V_37 -> V_205 ) {
V_29 = F_340 ( V_35 , V_36 +
V_464 * V_35 -> V_88 ) ;
if ( V_29 )
goto V_470;
}
V_29 = F_312 ( V_35 , V_387 , V_463 , V_314 ) ;
if ( F_220 ( V_29 ) ) {
if ( V_35 -> V_37 -> V_205 )
F_341 ( V_35 , V_36 +
V_464 * V_35 -> V_88 ) ;
goto V_470;
}
F_11 ( & F_241 ( V_271 ) -> V_52 ) ;
if ( V_465 ) {
F_349 ( V_451 ,
& F_241 ( V_271 ) -> V_452 ) ;
V_464 -- ;
}
F_241 ( V_271 ) -> V_453 += V_464 ;
F_13 ( & F_241 ( V_271 ) -> V_52 ) ;
if ( V_466 )
F_46 ( & F_241 ( V_271 ) -> V_469 ) ;
if ( V_463 )
F_276 ( V_35 -> V_37 , L_14 ,
F_337 ( V_271 ) , V_463 , 1 ) ;
F_318 ( V_387 , V_463 , 1 ) ;
return 0 ;
V_470:
F_11 ( & F_241 ( V_271 ) -> V_52 ) ;
V_468 = F_343 ( V_271 ) ;
if ( F_241 ( V_271 ) -> V_459 == V_459 ) {
F_345 ( V_271 , V_36 , 0 ) ;
} else {
T_2 V_471 = F_241 ( V_271 ) -> V_459 ;
T_2 V_343 ;
V_343 = V_459 - F_241 ( V_271 ) -> V_459 ;
F_241 ( V_271 ) -> V_459 = V_459 ;
V_467 = F_345 ( V_271 , V_343 , 0 ) ;
F_241 ( V_271 ) -> V_459 = V_459 - V_36 ;
V_343 = V_459 - V_471 ;
V_343 = F_345 ( V_271 , V_343 , 0 ) ;
F_241 ( V_271 ) -> V_459 = V_471 - V_36 ;
if ( V_343 > V_467 )
V_467 = V_343 - V_467 ;
else
V_467 = 0 ;
}
F_13 ( & F_241 ( V_271 ) -> V_52 ) ;
if ( V_468 )
V_467 += F_189 ( V_35 , V_468 ) ;
if ( V_467 ) {
F_325 ( V_35 , V_387 , V_467 ) ;
F_276 ( V_35 -> V_37 , L_14 ,
F_337 ( V_271 ) , V_467 , 0 ) ;
}
if ( V_466 )
F_46 ( & F_241 ( V_271 ) -> V_469 ) ;
return V_29 ;
}
void F_350 ( struct V_271 * V_271 , T_2 V_36 )
{
struct V_34 * V_35 = F_241 ( V_271 ) -> V_35 ;
T_2 V_467 = 0 ;
unsigned V_468 ;
V_36 = F_271 ( V_36 , V_35 -> V_347 ) ;
F_11 ( & F_241 ( V_271 ) -> V_52 ) ;
V_468 = F_343 ( V_271 ) ;
if ( V_36 )
V_467 = F_345 ( V_271 , V_36 , 0 ) ;
F_13 ( & F_241 ( V_271 ) -> V_52 ) ;
if ( V_468 > 0 )
V_467 += F_189 ( V_35 , V_468 ) ;
F_276 ( V_35 -> V_37 , L_14 ,
F_337 ( V_271 ) , V_467 , 0 ) ;
if ( V_35 -> V_37 -> V_205 ) {
F_341 ( V_35 , V_36 +
V_468 * V_35 -> V_88 ) ;
}
F_325 ( V_35 , & V_35 -> V_37 -> V_393 ,
V_467 ) ;
}
int F_351 ( struct V_271 * V_271 , T_2 V_36 )
{
int V_29 ;
V_29 = F_246 ( V_271 , V_36 ) ;
if ( V_29 )
return V_29 ;
V_29 = F_346 ( V_271 , V_36 ) ;
if ( V_29 ) {
F_248 ( V_271 , V_36 ) ;
return V_29 ;
}
return 0 ;
}
void F_352 ( struct V_271 * V_271 , T_2 V_36 )
{
F_350 ( V_271 , V_36 ) ;
F_248 ( V_271 , V_36 ) ;
}
static int F_353 ( struct V_34 * V_35 ,
T_2 V_27 , T_2 V_36 , int V_350 )
{
struct V_1 * V_2 = NULL ;
struct V_12 * V_13 = V_35 -> V_37 ;
T_2 V_472 = V_36 ;
T_2 V_473 ;
T_2 V_474 ;
int V_297 ;
F_11 ( & V_13 -> V_475 ) ;
V_473 = F_354 ( V_13 -> V_362 ) ;
if ( V_350 )
V_473 += V_36 ;
else
V_473 -= V_36 ;
F_355 ( V_13 -> V_362 , V_473 ) ;
F_13 ( & V_13 -> V_475 ) ;
while ( V_472 ) {
V_2 = F_68 ( V_13 , V_27 ) ;
if ( ! V_2 )
return - V_152 ;
if ( V_2 -> V_7 & ( V_298 |
V_299 |
V_300 ) )
V_297 = 2 ;
else
V_297 = 1 ;
if ( ! V_350 && V_2 -> V_3 == V_95 )
F_51 ( V_2 , 1 ) ;
V_474 = V_27 - V_2 -> V_21 . V_22 ;
F_8 ( V_474 > V_2 -> V_21 . V_33 ) ;
F_11 ( & V_2 -> V_104 -> V_52 ) ;
F_11 ( & V_2 -> V_52 ) ;
if ( F_245 ( V_35 , V_285 ) &&
V_2 -> V_277 < V_288 )
V_2 -> V_277 = V_288 ;
V_2 -> V_289 = 1 ;
V_473 = F_356 ( & V_2 -> V_134 ) ;
V_36 = F_298 ( V_472 , V_2 -> V_21 . V_33 - V_474 ) ;
if ( V_350 ) {
V_473 += V_36 ;
F_357 ( & V_2 -> V_134 , V_473 ) ;
V_2 -> V_10 -= V_36 ;
V_2 -> V_104 -> V_308 -= V_36 ;
V_2 -> V_104 -> V_296 += V_36 ;
V_2 -> V_104 -> V_302 += V_36 * V_297 ;
F_13 ( & V_2 -> V_52 ) ;
F_13 ( & V_2 -> V_104 -> V_52 ) ;
} else {
V_473 -= V_36 ;
F_357 ( & V_2 -> V_134 , V_473 ) ;
V_2 -> V_9 += V_36 ;
V_2 -> V_104 -> V_307 += V_36 ;
V_2 -> V_104 -> V_296 -= V_36 ;
V_2 -> V_104 -> V_302 -= V_36 * V_297 ;
F_13 ( & V_2 -> V_52 ) ;
F_13 ( & V_2 -> V_104 -> V_52 ) ;
F_358 ( V_13 -> V_59 ,
V_27 , V_27 + V_36 - 1 ,
V_40 | V_476 ) ;
}
F_6 ( V_2 ) ;
V_472 -= V_36 ;
V_27 += V_36 ;
}
return 0 ;
}
static T_2 V_26 ( struct V_34 * V_35 , T_2 V_477 )
{
struct V_1 * V_2 ;
T_2 V_27 ;
F_11 ( & V_35 -> V_37 -> V_18 ) ;
V_27 = V_35 -> V_37 -> V_26 ;
F_13 ( & V_35 -> V_37 -> V_18 ) ;
if ( V_27 < ( T_2 ) - 1 )
return V_27 ;
V_2 = F_67 ( V_35 -> V_37 , V_477 ) ;
if ( ! V_2 )
return 0 ;
V_27 = V_2 -> V_21 . V_22 ;
F_6 ( V_2 ) ;
return V_27 ;
}
static int F_359 ( struct V_34 * V_35 ,
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
F_358 ( V_35 -> V_37 -> V_59 , V_27 ,
V_27 + V_36 - 1 , V_40 | V_476 ) ;
if ( V_10 )
F_360 ( V_35 , V_27 , V_36 ) ;
return 0 ;
}
int F_163 ( struct V_34 * V_35 ,
T_2 V_27 , T_2 V_36 , int V_10 )
{
struct V_1 * V_2 ;
V_2 = F_68 ( V_35 -> V_37 , V_27 ) ;
F_30 ( ! V_2 ) ;
F_359 ( V_35 , V_2 , V_27 , V_36 , V_10 ) ;
F_6 ( V_2 ) ;
return 0 ;
}
int F_361 ( struct V_34 * V_35 ,
T_2 V_27 , T_2 V_36 )
{
struct V_1 * V_2 ;
int V_29 ;
V_2 = F_68 ( V_35 -> V_37 , V_27 ) ;
if ( ! V_2 )
return - V_478 ;
F_51 ( V_2 , 1 ) ;
F_359 ( V_35 , V_2 , V_27 , V_36 , 0 ) ;
V_29 = F_362 ( V_2 , V_27 , V_36 ) ;
F_6 ( V_2 ) ;
return V_29 ;
}
static int F_363 ( struct V_34 * V_35 , T_2 V_32 , T_2 V_36 )
{
int V_29 ;
struct V_1 * V_14 ;
struct V_50 * V_54 ;
V_14 = F_68 ( V_35 -> V_37 , V_32 ) ;
if ( ! V_14 )
return - V_478 ;
F_51 ( V_14 , 0 ) ;
V_54 = F_25 ( V_14 ) ;
if ( ! V_54 ) {
F_30 ( ! F_1 ( V_14 ) ) ;
V_29 = F_362 ( V_14 , V_32 , V_36 ) ;
} else {
F_35 ( & V_54 -> V_79 ) ;
if ( V_32 >= V_54 -> V_85 ) {
V_29 = F_17 ( V_35 , V_32 , V_36 ) ;
} else if ( V_32 + V_36 <= V_54 -> V_85 ) {
V_29 = F_362 ( V_14 ,
V_32 , V_36 ) ;
} else {
V_36 = V_54 -> V_85 - V_32 ;
V_29 = F_362 ( V_14 ,
V_32 , V_36 ) ;
if ( V_29 )
goto V_479;
V_36 = ( V_32 + V_36 ) -
V_54 -> V_85 ;
V_32 = V_54 -> V_85 ;
V_29 = F_17 ( V_35 , V_32 , V_36 ) ;
}
V_479:
F_46 ( & V_54 -> V_79 ) ;
F_26 ( V_54 ) ;
}
F_6 ( V_14 ) ;
return V_29 ;
}
int F_364 ( struct V_34 * log ,
struct V_66 * V_480 )
{
struct V_263 * V_134 ;
struct V_68 V_21 ;
int V_481 ;
int V_43 ;
if ( ! F_76 ( log -> V_37 , V_482 ) )
return 0 ;
for ( V_43 = 0 ; V_43 < F_38 ( V_480 ) ; V_43 ++ ) {
F_40 ( V_480 , & V_21 , V_43 ) ;
if ( V_21 . type != V_269 )
continue;
V_134 = F_78 ( V_480 , V_43 , struct V_263 ) ;
V_481 = F_225 ( V_480 , V_134 ) ;
if ( V_481 == V_270 )
continue;
if ( F_226 ( V_480 , V_134 ) == 0 )
continue;
V_21 . V_22 = F_226 ( V_480 , V_134 ) ;
V_21 . V_33 = F_227 ( V_480 , V_134 ) ;
F_363 ( log , V_21 . V_22 , V_21 . V_33 ) ;
}
return 0 ;
}
static int F_365 ( struct V_1 * V_2 ,
T_2 V_36 , int V_454 , int V_483 )
{
struct V_101 * V_104 = V_2 -> V_104 ;
int V_29 = 0 ;
F_11 ( & V_104 -> V_52 ) ;
F_11 ( & V_2 -> V_52 ) ;
if ( V_454 != V_484 ) {
if ( V_2 -> V_279 ) {
V_29 = - V_177 ;
} else {
V_2 -> V_10 += V_36 ;
V_104 -> V_308 += V_36 ;
if ( V_454 == V_485 ) {
F_276 ( V_2 -> V_37 ,
L_10 , V_104 -> V_7 ,
V_36 , 0 ) ;
V_104 -> V_310 -= V_36 ;
}
if ( V_483 )
V_2 -> V_286 += V_36 ;
}
} else {
if ( V_2 -> V_279 )
V_104 -> V_309 += V_36 ;
V_2 -> V_10 -= V_36 ;
V_104 -> V_308 -= V_36 ;
if ( V_483 )
V_2 -> V_286 -= V_36 ;
}
F_13 ( & V_2 -> V_52 ) ;
F_13 ( & V_104 -> V_52 ) ;
return V_29 ;
}
void F_366 ( struct V_108 * V_109 ,
struct V_34 * V_35 )
{
struct V_12 * V_37 = V_35 -> V_37 ;
struct V_50 * V_81 ;
struct V_50 * V_54 ;
struct V_1 * V_2 ;
F_63 ( & V_37 -> V_80 ) ;
F_367 (caching_ctl, next,
&fs_info->caching_block_groups, list) {
V_2 = V_54 -> V_14 ;
if ( F_1 ( V_2 ) ) {
V_2 -> V_98 = ( T_2 ) - 1 ;
F_368 ( & V_54 -> V_91 ) ;
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
F_332 ( V_37 ) ;
}
static int F_369 ( struct V_34 * V_35 , T_2 V_32 , T_2 V_31 )
{
struct V_12 * V_37 = V_35 -> V_37 ;
struct V_1 * V_2 = NULL ;
struct V_101 * V_104 ;
struct V_239 * V_240 = & V_37 -> V_241 ;
T_2 V_49 ;
bool V_291 ;
while ( V_32 <= V_31 ) {
V_291 = false ;
if ( ! V_2 ||
V_32 >= V_2 -> V_21 . V_22 + V_2 -> V_21 . V_33 ) {
if ( V_2 )
F_6 ( V_2 ) ;
V_2 = F_68 ( V_37 , V_32 ) ;
F_30 ( ! V_2 ) ;
}
V_49 = V_2 -> V_21 . V_22 + V_2 -> V_21 . V_33 - V_32 ;
V_49 = F_298 ( V_49 , V_31 + 1 - V_32 ) ;
if ( V_32 < V_2 -> V_98 ) {
V_49 = F_298 ( V_49 , V_2 -> V_98 - V_32 ) ;
F_29 ( V_2 , V_32 , V_49 ) ;
}
V_32 += V_49 ;
V_104 = V_2 -> V_104 ;
F_11 ( & V_104 -> V_52 ) ;
F_11 ( & V_2 -> V_52 ) ;
V_2 -> V_9 -= V_49 ;
V_104 -> V_307 -= V_49 ;
F_370 ( & V_104 -> V_303 , - V_49 ) ;
if ( V_2 -> V_279 ) {
V_104 -> V_309 += V_49 ;
V_291 = true ;
}
F_13 ( & V_2 -> V_52 ) ;
if ( ! V_291 && V_240 -> V_104 == V_104 ) {
F_11 ( & V_240 -> V_52 ) ;
if ( ! V_240 -> V_107 ) {
V_49 = F_298 ( V_49 , V_240 -> V_57 -
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
int F_371 ( struct V_108 * V_109 ,
struct V_34 * V_35 )
{
struct V_12 * V_37 = V_35 -> V_37 ;
struct V_486 * V_487 ;
T_2 V_32 ;
T_2 V_31 ;
int V_29 ;
if ( V_109 -> V_216 )
return 0 ;
if ( V_37 -> V_59 == & V_37 -> V_38 [ 0 ] )
V_487 = & V_37 -> V_38 [ 1 ] ;
else
V_487 = & V_37 -> V_38 [ 0 ] ;
while ( 1 ) {
V_29 = F_28 ( V_487 , 0 , & V_32 , & V_31 ,
V_60 , NULL ) ;
if ( V_29 )
break;
if ( F_245 ( V_35 , V_488 ) )
V_29 = F_142 ( V_35 , V_32 ,
V_31 + 1 - V_32 , NULL ) ;
F_372 ( V_487 , V_32 , V_31 , V_40 ) ;
F_369 ( V_35 , V_32 , V_31 ) ;
F_47 () ;
}
return 0 ;
}
static void F_373 ( struct V_12 * V_37 , T_2 V_36 ,
T_2 V_132 , T_2 V_145 )
{
struct V_101 * V_104 ;
T_2 V_7 ;
if ( V_132 < V_142 ) {
if ( V_145 == V_489 )
V_7 = V_294 ;
else
V_7 = V_292 ;
} else {
V_7 = V_293 ;
}
V_104 = F_69 ( V_37 , V_7 ) ;
F_30 ( ! V_104 ) ;
F_370 ( & V_104 -> V_303 , V_36 ) ;
}
static int F_155 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
T_2 V_27 , T_2 V_36 , T_2 V_17 ,
T_2 V_145 , T_2 V_490 ,
T_2 V_491 , int V_158 ,
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
int V_492 = 0 ;
int V_493 = 0 ;
int V_494 = 1 ;
T_3 V_117 ;
T_2 V_111 ;
int V_159 = 0 ;
enum V_203 type = V_495 ;
bool V_172 = F_76 ( V_35 -> V_37 ,
V_120 ) ;
if ( ! V_13 -> V_205 || ! F_148 ( V_145 ) )
V_200 = 1 ;
V_65 = F_33 () ;
if ( ! V_65 )
return - V_72 ;
V_65 -> V_76 = 1 ;
V_65 -> V_206 = 1 ;
V_183 = V_490 >= V_142 ;
F_30 ( ! V_183 && V_158 != 1 ) ;
if ( V_183 )
V_172 = 0 ;
V_29 = F_134 ( V_109 , V_63 , V_65 , & V_163 ,
V_27 , V_36 , V_17 ,
V_145 , V_490 ,
V_491 ) ;
if ( V_29 == 0 ) {
V_492 = V_65 -> V_84 [ 0 ] ;
while ( V_492 >= 0 ) {
F_40 ( V_65 -> V_83 [ 0 ] , & V_21 ,
V_492 ) ;
if ( V_21 . V_22 != V_27 )
break;
if ( V_21 . type == V_77 &&
V_21 . V_33 == V_36 ) {
V_493 = 1 ;
break;
}
if ( V_21 . type == V_86 &&
V_21 . V_33 == V_490 ) {
V_493 = 1 ;
break;
}
if ( V_65 -> V_84 [ 0 ] - V_492 > 5 )
break;
V_492 -- ;
}
#ifdef F_81
V_117 = F_77 ( V_65 -> V_83 [ 0 ] , V_492 ) ;
if ( V_493 && V_117 < sizeof( * V_116 ) )
V_493 = 0 ;
#endif
if ( ! V_493 ) {
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
V_21 . V_33 = V_490 ;
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
F_374 ( V_13 , L_15 ,
V_29 , V_27 ) ;
if ( V_29 > 0 )
F_375 ( V_63 ,
V_65 -> V_83 [ 0 ] ) ;
}
if ( V_29 < 0 ) {
F_150 ( V_109 , V_63 , V_29 ) ;
goto V_73;
}
V_492 = V_65 -> V_84 [ 0 ] ;
}
} else if ( F_8 ( V_29 == - V_152 ) ) {
F_375 ( V_63 , V_65 -> V_83 [ 0 ] ) ;
F_374 ( V_13 ,
L_16 ,
V_27 , V_17 , V_145 , V_490 ,
V_491 ) ;
F_150 ( V_109 , V_63 , V_29 ) ;
goto V_73;
} else {
F_150 ( V_109 , V_63 , V_29 ) ;
goto V_73;
}
V_67 = V_65 -> V_83 [ 0 ] ;
V_117 = F_77 ( V_67 , V_492 ) ;
#ifdef F_81
if ( V_117 < sizeof( * V_116 ) ) {
F_30 ( V_493 || V_492 != V_65 -> V_84 [ 0 ] ) ;
V_29 = F_87 ( V_109 , V_63 , V_65 ,
V_490 , 0 ) ;
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
F_374 ( V_13 , L_15 ,
V_29 , V_27 ) ;
F_375 ( V_63 , V_65 -> V_83 [ 0 ] ) ;
}
if ( V_29 < 0 ) {
F_150 ( V_109 , V_63 , V_29 ) ;
goto V_73;
}
V_492 = V_65 -> V_84 [ 0 ] ;
V_67 = V_65 -> V_83 [ 0 ] ;
V_117 = F_77 ( V_67 , V_492 ) ;
}
#endif
F_30 ( V_117 < sizeof( * V_116 ) ) ;
V_116 = F_78 ( V_67 , V_492 ,
struct V_115 ) ;
if ( V_490 < V_142 &&
V_21 . type == V_77 ) {
struct V_137 * V_138 ;
F_30 ( V_117 < sizeof( * V_116 ) + sizeof( * V_138 ) ) ;
V_138 = (struct V_137 * ) ( V_116 + 1 ) ;
F_8 ( V_490 != F_376 ( V_67 , V_138 ) ) ;
}
V_111 = F_79 ( V_67 , V_116 ) ;
if ( V_111 < V_158 ) {
F_374 ( V_13 , L_17
L_18 , V_158 , V_111 , V_27 ) ;
V_29 = - V_478 ;
F_150 ( V_109 , V_63 , V_29 ) ;
goto V_73;
}
V_111 -= V_158 ;
if ( V_111 > 0 ) {
type = V_496 ;
if ( V_128 )
F_130 ( V_128 , V_67 , V_116 ) ;
if ( V_163 ) {
F_30 ( ! V_493 ) ;
} else {
F_90 ( V_67 , V_116 , V_111 ) ;
F_95 ( V_67 ) ;
}
if ( V_493 ) {
V_29 = F_139 ( V_109 , V_63 , V_65 ,
V_163 , V_158 ,
V_183 , & V_159 ) ;
if ( V_29 ) {
F_150 ( V_109 , V_63 , V_29 ) ;
goto V_73;
}
}
F_373 ( V_35 -> V_37 , - V_36 , V_490 ,
V_145 ) ;
} else {
if ( V_493 ) {
F_30 ( V_183 && V_158 !=
F_118 ( V_35 , V_65 , V_163 ) ) ;
if ( V_163 ) {
F_30 ( V_65 -> V_84 [ 0 ] != V_492 ) ;
} else {
F_30 ( V_65 -> V_84 [ 0 ] != V_492 + 1 ) ;
V_65 -> V_84 [ 0 ] = V_492 ;
V_494 = 2 ;
}
}
V_159 = 1 ;
V_29 = F_377 ( V_109 , V_63 , V_65 , V_65 -> V_84 [ 0 ] ,
V_494 ) ;
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
V_29 = F_353 ( V_35 , V_27 , V_36 , 0 ) ;
if ( V_29 ) {
F_150 ( V_109 , V_63 , V_29 ) ;
goto V_73;
}
}
F_44 ( V_65 ) ;
if ( ! V_29 && V_159 && ! V_200 ) {
int V_497 = 0 ;
if ( V_490 >= V_142 &&
type == V_496 )
V_497 = 1 ;
V_29 = F_149 ( V_109 , V_13 , V_145 ,
V_27 , V_36 , type ,
V_497 ) ;
}
V_73:
F_50 ( V_65 ) ;
return V_29 ;
}
static T_1 int F_378 ( struct V_108 * V_109 ,
struct V_34 * V_35 , T_2 V_27 )
{
struct V_112 * V_103 ;
struct V_113 * V_114 ;
int V_29 = 0 ;
V_114 = & V_109 -> V_126 -> V_114 ;
F_11 ( & V_114 -> V_52 ) ;
V_103 = F_84 ( V_109 , V_27 ) ;
if ( ! V_103 )
goto V_498;
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
V_498:
F_13 ( & V_114 -> V_52 ) ;
return 0 ;
}
void F_379 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
struct V_66 * V_260 ,
T_2 V_17 , int V_159 )
{
struct V_1 * V_2 = NULL ;
int V_499 = 1 ;
int V_29 ;
if ( V_35 -> V_256 . V_22 != V_201 ) {
V_29 = F_145 ( V_35 -> V_37 , V_109 ,
V_260 -> V_32 , V_260 -> V_49 ,
V_17 , V_35 -> V_256 . V_22 ,
F_223 ( V_260 ) ,
V_214 , NULL , 0 ) ;
F_30 ( V_29 ) ;
}
if ( ! V_159 )
return;
V_2 = F_68 ( V_35 -> V_37 , V_260 -> V_32 ) ;
if ( F_380 ( V_260 ) == V_109 -> V_281 ) {
if ( V_35 -> V_256 . V_22 != V_201 ) {
V_29 = F_378 ( V_109 , V_35 , V_260 -> V_32 ) ;
if ( ! V_29 )
goto V_73;
}
if ( F_381 ( V_260 , V_500 ) ) {
F_359 ( V_35 , V_2 , V_260 -> V_32 , V_260 -> V_49 , 1 ) ;
goto V_73;
}
F_8 ( F_221 ( V_501 , & V_260 -> V_502 ) ) ;
F_29 ( V_2 , V_260 -> V_32 , V_260 -> V_49 ) ;
F_365 ( V_2 , V_260 -> V_49 , V_484 , 0 ) ;
F_360 ( V_35 , V_260 -> V_32 , V_260 -> V_49 ) ;
V_499 = 0 ;
}
V_73:
if ( V_499 )
F_373 ( V_35 -> V_37 , V_260 -> V_49 ,
F_223 ( V_260 ) ,
V_35 -> V_256 . V_22 ) ;
F_382 ( V_503 , & V_260 -> V_502 ) ;
F_6 ( V_2 ) ;
}
int V_268 ( struct V_108 * V_109 , struct V_34 * V_35 ,
T_2 V_27 , T_2 V_36 , T_2 V_17 , T_2 V_145 ,
T_2 V_132 , T_2 V_33 , int V_200 )
{
int V_29 ;
struct V_12 * V_37 = V_35 -> V_37 ;
#ifdef F_219
if ( F_220 ( F_221 ( V_265 , & V_35 -> V_266 ) ) )
return 0 ;
#endif
F_373 ( V_35 -> V_37 , V_36 , V_132 , V_145 ) ;
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
static T_2 F_383 ( struct V_34 * V_35 ,
struct V_1 * V_2 ,
T_2 V_243 , T_2 V_36 )
{
T_2 V_29 = F_271 ( V_243 , V_35 -> V_504 ) ;
return V_29 ;
}
static T_1 void
F_384 ( struct V_1 * V_2 ,
T_2 V_36 )
{
struct V_50 * V_54 ;
V_54 = F_25 ( V_2 ) ;
if ( ! V_54 )
return;
F_299 ( V_54 -> V_89 , F_1 ( V_2 ) ||
( V_2 -> V_11 -> V_505 >= V_36 ) ) ;
F_26 ( V_54 ) ;
}
static T_1 int
F_385 ( struct V_1 * V_2 )
{
struct V_50 * V_54 ;
int V_29 = 0 ;
V_54 = F_25 ( V_2 ) ;
if ( ! V_54 )
return ( V_2 -> V_3 == V_5 ) ? - V_174 : 0 ;
F_299 ( V_54 -> V_89 , F_1 ( V_2 ) ) ;
if ( V_2 -> V_3 == V_5 )
V_29 = - V_174 ;
F_26 ( V_54 ) ;
return V_29 ;
}
int F_386 ( T_2 V_7 )
{
if ( V_7 & V_300 )
return V_506 ;
else if ( V_7 & V_299 )
return V_507 ;
else if ( V_7 & V_298 )
return V_508 ;
else if ( V_7 & V_338 )
return V_509 ;
else if ( V_7 & V_339 )
return V_510 ;
else if ( V_7 & V_340 )
return V_511 ;
return V_512 ;
}
int F_387 ( struct V_1 * V_2 )
{
return F_386 ( V_2 -> V_7 ) ;
}
static const char * F_388 ( enum V_513 type )
{
if ( type >= V_304 )
return NULL ;
return V_514 [ type ] ;
}
static inline void
F_389 ( struct V_1 * V_2 ,
int V_483 )
{
if ( V_483 )
F_36 ( & V_2 -> V_515 ) ;
}
static inline void
F_390 ( struct V_1 * V_2 ,
int V_483 )
{
F_4 ( V_2 ) ;
if ( V_483 )
F_36 ( & V_2 -> V_515 ) ;
}
static struct V_1 *
F_391 ( struct V_1 * V_14 ,
struct V_516 * V_517 ,
int V_483 )
{
struct V_1 * V_518 ;
bool V_519 = false ;
V_78:
F_11 ( & V_517 -> V_520 ) ;
if ( V_519 ) {
if ( V_518 == V_517 -> V_14 )
return V_518 ;
F_45 ( & V_518 -> V_515 ) ;
F_6 ( V_518 ) ;
}
V_518 = V_517 -> V_14 ;
if ( ! V_518 )
return NULL ;
if ( V_518 == V_14 )
return V_518 ;
F_4 ( V_518 ) ;
if ( ! V_483 )
return V_518 ;
if ( F_291 ( & V_518 -> V_515 ) )
return V_518 ;
F_13 ( & V_517 -> V_520 ) ;
F_36 ( & V_518 -> V_515 ) ;
V_519 = true ;
goto V_78;
}
static inline void
F_392 ( struct V_1 * V_2 ,
int V_483 )
{
if ( V_483 )
F_45 ( & V_2 -> V_515 ) ;
F_6 ( V_2 ) ;
}
static T_1 int F_393 ( struct V_34 * V_521 ,
T_2 V_36 , T_2 V_522 ,
T_2 V_523 , struct V_68 * V_211 ,
T_2 V_7 , int V_483 )
{
int V_29 = 0 ;
struct V_34 * V_35 = V_521 -> V_37 -> V_63 ;
struct V_516 * V_524 = NULL ;
struct V_1 * V_14 = NULL ;
T_2 V_477 = 0 ;
T_2 V_525 = 0 ;
int V_526 = 2 * 1024 * 1024 ;
struct V_101 * V_104 ;
int V_527 = 0 ;
int V_528 = F_386 ( V_7 ) ;
int V_529 = ( V_7 & V_293 ) ?
V_530 : V_485 ;
bool V_531 = false ;
bool V_532 = false ;
bool V_533 = true ;
bool V_534 = false ;
F_8 ( V_36 < V_35 -> V_347 ) ;
F_394 ( V_211 , V_77 ) ;
V_211 -> V_22 = 0 ;
V_211 -> V_33 = 0 ;
F_395 ( V_521 , V_36 , V_522 , V_7 ) ;
V_104 = F_69 ( V_35 -> V_37 , V_7 ) ;
if ( ! V_104 ) {
F_374 ( V_35 -> V_37 , L_19 , V_7 ) ;
return - V_353 ;
}
if ( F_288 ( V_104 ) )
V_533 = false ;
if ( V_7 & V_292 && V_533 ) {
V_524 = & V_35 -> V_37 -> V_535 ;
if ( ! F_245 ( V_35 , V_536 ) )
V_526 = 64 * 1024 ;
}
if ( ( V_7 & V_293 ) && V_533 &&
F_245 ( V_35 , V_536 ) ) {
V_524 = & V_35 -> V_37 -> V_537 ;
}
if ( V_524 ) {
F_11 ( & V_524 -> V_52 ) ;
if ( V_524 -> V_14 )
V_523 = V_524 -> V_538 ;
F_13 ( & V_524 -> V_52 ) ;
}
V_477 = F_396 ( V_477 , V_26 ( V_35 , 0 ) ) ;
V_477 = F_396 ( V_477 , V_523 ) ;
if ( ! V_524 )
V_526 = 0 ;
if ( V_477 == V_523 ) {
V_14 = F_68 ( V_35 -> V_37 ,
V_477 ) ;
if ( V_14 && F_3 ( V_14 , V_7 ) &&
V_14 -> V_3 != V_95 ) {
F_36 ( & V_104 -> V_306 ) ;
if ( F_204 ( & V_14 -> V_91 ) ||
V_14 -> V_279 ) {
F_6 ( V_14 ) ;
F_45 ( & V_104 -> V_306 ) ;
} else {
V_528 = F_387 ( V_14 ) ;
F_389 ( V_14 , V_483 ) ;
goto V_539;
}
} else if ( V_14 ) {
F_6 ( V_14 ) ;
}
}
V_540:
V_534 = false ;
F_36 ( & V_104 -> V_306 ) ;
F_397 (block_group, &space_info->block_groups[index],
list) {
T_2 V_33 ;
int V_3 ;
F_390 ( V_14 , V_483 ) ;
V_477 = V_14 -> V_21 . V_22 ;
if ( ! F_3 ( V_14 , V_7 ) ) {
T_2 V_541 = V_298 |
V_299 |
V_339 |
V_340 |
V_300 ;
if ( ( V_7 & V_541 ) && ! ( V_14 -> V_7 & V_541 ) )
goto V_527;
}
V_539:
V_3 = F_1 ( V_14 ) ;
if ( F_220 ( ! V_3 ) ) {
V_29 = F_51 ( V_14 , 0 ) ;
F_30 ( V_29 < 0 ) ;
V_29 = 0 ;
}
if ( F_220 ( V_14 -> V_3 == V_5 ) )
goto V_527;
if ( F_220 ( V_14 -> V_279 ) )
goto V_527;
if ( V_524 ) {
struct V_1 * V_542 ;
unsigned long V_543 ;
V_542 = F_391 ( V_14 ,
V_524 ,
V_483 ) ;
if ( ! V_542 )
goto V_544;
if ( V_542 != V_14 &&
( V_542 -> V_279 ||
! F_3 ( V_542 , V_7 ) ) )
goto V_545;
V_33 = F_398 ( V_542 ,
V_524 ,
V_36 ,
V_542 -> V_21 . V_22 ,
& V_525 ) ;
if ( V_33 ) {
F_13 ( & V_524 -> V_520 ) ;
F_399 ( V_35 ,
V_542 ,
V_477 , V_36 ) ;
if ( V_542 != V_14 ) {
F_392 ( V_14 ,
V_483 ) ;
V_14 = V_542 ;
}
goto V_546;
}
F_8 ( V_524 -> V_14 != V_542 ) ;
V_545:
if ( V_527 >= V_547 &&
V_542 != V_14 ) {
F_13 ( & V_524 -> V_520 ) ;
F_392 ( V_542 ,
V_483 ) ;
goto V_548;
}
F_400 ( NULL , V_524 ) ;
if ( V_542 != V_14 )
F_392 ( V_542 ,
V_483 ) ;
V_544:
if ( V_527 >= V_547 ) {
F_13 ( & V_524 -> V_520 ) ;
goto V_548;
}
V_543 = F_34 (unsigned long,
empty_cluster + empty_size,
block_group->full_stripe_len) ;
V_29 = F_401 ( V_35 , V_14 ,
V_524 , V_477 ,
V_36 ,
V_543 ) ;
if ( V_29 == 0 ) {
V_33 = F_398 ( V_14 ,
V_524 ,
V_36 ,
V_477 ,
& V_525 ) ;
if ( V_33 ) {
F_13 ( & V_524 -> V_520 ) ;
F_399 ( V_35 ,
V_14 , V_477 ,
V_36 ) ;
goto V_546;
}
} else if ( ! V_3 && V_527 > V_549
&& ! V_531 ) {
F_13 ( & V_524 -> V_520 ) ;
V_531 = true ;
F_384 ( V_14 ,
V_36 + V_526 + V_522 ) ;
goto V_539;
}
F_400 ( NULL , V_524 ) ;
F_13 ( & V_524 -> V_520 ) ;
goto V_527;
}
V_548:
F_11 ( & V_14 -> V_11 -> V_550 ) ;
if ( V_3 &&
V_14 -> V_11 -> V_505 <
V_36 + V_526 + V_522 ) {
if ( V_14 -> V_11 -> V_505 >
V_525 )
V_525 =
V_14 -> V_11 -> V_505 ;
F_13 ( & V_14 -> V_11 -> V_550 ) ;
goto V_527;
}
F_13 ( & V_14 -> V_11 -> V_550 ) ;
V_33 = F_402 ( V_14 , V_477 ,
V_36 , V_522 ,
& V_525 ) ;
if ( ! V_33 && ! V_532 && ! V_3 &&
V_527 > V_549 ) {
F_384 ( V_14 ,
V_36 + V_522 ) ;
V_532 = true ;
goto V_539;
} else if ( ! V_33 ) {
if ( ! V_3 )
V_534 = true ;
goto V_527;
}
V_546:
V_477 = F_383 ( V_35 , V_14 ,
V_33 , V_36 ) ;
if ( V_477 + V_36 >
V_14 -> V_21 . V_22 + V_14 -> V_21 . V_33 ) {
F_29 ( V_14 , V_33 , V_36 ) ;
goto V_527;
}
if ( V_33 < V_477 )
F_29 ( V_14 , V_33 ,
V_477 - V_33 ) ;
F_30 ( V_33 > V_477 ) ;
V_29 = F_365 ( V_14 , V_36 ,
V_529 , V_483 ) ;
if ( V_29 == - V_177 ) {
F_29 ( V_14 , V_33 , V_36 ) ;
goto V_527;
}
V_211 -> V_22 = V_477 ;
V_211 -> V_33 = V_36 ;
F_403 ( V_521 , V_14 ,
V_477 , V_36 ) ;
F_392 ( V_14 , V_483 ) ;
break;
V_527:
V_531 = false ;
V_532 = false ;
F_30 ( V_528 != F_387 ( V_14 ) ) ;
F_392 ( V_14 , V_483 ) ;
}
F_45 ( & V_104 -> V_306 ) ;
if ( ! V_211 -> V_22 && V_527 >= V_551 && V_534 )
goto V_540;
if ( ! V_211 -> V_22 && ++ V_528 < V_304 )
goto V_540;
if ( ! V_211 -> V_22 && V_527 < V_547 ) {
V_528 = 0 ;
V_527 ++ ;
if ( V_527 == V_552 ) {
struct V_108 * V_109 ;
int V_553 = 0 ;
V_109 = V_348 -> V_349 ;
if ( V_109 )
V_553 = 1 ;
else
V_109 = F_193 ( V_35 ) ;
if ( F_194 ( V_109 ) ) {
V_29 = F_195 ( V_109 ) ;
goto V_73;
}
V_29 = F_273 ( V_109 , V_35 , V_7 ,
V_352 ) ;
if ( V_29 < 0 && V_29 != - V_353 )
F_150 ( V_109 ,
V_35 , V_29 ) ;
else
V_29 = 0 ;
if ( ! V_553 )
F_197 ( V_109 , V_35 ) ;
if ( V_29 )
goto V_73;
}
if ( V_527 == V_547 ) {
V_522 = 0 ;
V_526 = 0 ;
}
goto V_540;
} else if ( ! V_211 -> V_22 ) {
V_29 = - V_353 ;
} else if ( V_211 -> V_22 ) {
V_29 = 0 ;
}
V_73:
if ( V_29 == - V_353 )
V_211 -> V_33 = V_525 ;
return V_29 ;
}
static void F_286 ( struct V_101 * V_13 , T_2 V_343 ,
int V_554 )
{
struct V_1 * V_2 ;
int V_528 = 0 ;
F_11 ( & V_13 -> V_52 ) ;
F_404 ( V_555 L_20 ,
V_13 -> V_7 ,
V_13 -> V_295 - V_13 -> V_296 - V_13 -> V_307 -
V_13 -> V_308 - V_13 -> V_309 ,
( V_13 -> V_107 ) ? L_21 : L_22 ) ;
F_404 ( V_555 L_23
L_24 ,
V_13 -> V_295 , V_13 -> V_296 , V_13 -> V_307 ,
V_13 -> V_308 , V_13 -> V_310 ,
V_13 -> V_309 ) ;
F_13 ( & V_13 -> V_52 ) ;
if ( ! V_554 )
return;
F_36 ( & V_13 -> V_306 ) ;
V_78:
F_397 (cache, &info->block_groups[index], list) {
F_11 ( & V_2 -> V_52 ) ;
F_404 ( V_555 L_25
L_26
L_27 ,
V_2 -> V_21 . V_22 , V_2 -> V_21 . V_33 ,
F_356 ( & V_2 -> V_134 ) , V_2 -> V_9 ,
V_2 -> V_10 , V_2 -> V_279 ? L_28 : L_21 ) ;
F_405 ( V_2 , V_343 ) ;
F_13 ( & V_2 -> V_52 ) ;
}
if ( ++ V_528 < V_304 )
goto V_78;
F_45 ( & V_13 -> V_306 ) ;
}
int F_406 ( struct V_34 * V_35 ,
T_2 V_36 , T_2 V_556 ,
T_2 V_522 , T_2 V_523 ,
struct V_68 * V_211 , int V_183 , int V_483 )
{
bool V_557 = false ;
T_2 V_7 ;
int V_29 ;
V_7 = F_270 ( V_35 , V_183 ) ;
V_78:
F_8 ( V_36 < V_35 -> V_347 ) ;
V_29 = F_393 ( V_35 , V_36 , V_522 , V_523 , V_211 ,
V_7 , V_483 ) ;
if ( V_29 == - V_353 ) {
if ( ! V_557 && V_211 -> V_33 ) {
V_36 = F_298 ( V_36 >> 1 , V_211 -> V_33 ) ;
V_36 = F_407 ( V_36 , V_35 -> V_347 ) ;
V_36 = F_396 ( V_36 , V_556 ) ;
if ( V_36 == V_556 )
V_557 = true ;
goto V_78;
} else if ( F_245 ( V_35 , V_365 ) ) {
struct V_101 * V_357 ;
V_357 = F_69 ( V_35 -> V_37 , V_7 ) ;
F_374 ( V_35 -> V_37 , L_29 ,
V_7 , V_36 ) ;
if ( V_357 )
F_286 ( V_357 , V_36 , 1 ) ;
}
}
return V_29 ;
}
static int F_408 ( struct V_34 * V_35 ,
T_2 V_32 , T_2 V_49 ,
int V_499 , int V_483 )
{
struct V_1 * V_2 ;
int V_29 = 0 ;
V_2 = F_68 ( V_35 -> V_37 , V_32 ) ;
if ( ! V_2 ) {
F_374 ( V_35 -> V_37 , L_30 ,
V_32 ) ;
return - V_353 ;
}
if ( F_245 ( V_35 , V_488 ) )
V_29 = F_142 ( V_35 , V_32 , V_49 , NULL ) ;
if ( V_499 )
F_359 ( V_35 , V_2 , V_32 , V_49 , 1 ) ;
else {
F_29 ( V_2 , V_32 , V_49 ) ;
F_365 ( V_2 , V_49 , V_484 , V_483 ) ;
}
F_6 ( V_2 ) ;
F_360 ( V_35 , V_32 , V_49 ) ;
return V_29 ;
}
int F_409 ( struct V_34 * V_35 ,
T_2 V_32 , T_2 V_49 , int V_483 )
{
return F_408 ( V_35 , V_32 , V_49 , 0 , V_483 ) ;
}
int F_410 ( struct V_34 * V_35 ,
T_2 V_32 , T_2 V_49 )
{
return F_408 ( V_35 , V_32 , V_49 , 1 , 0 ) ;
}
static int F_154 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
T_2 V_17 , T_2 V_145 ,
T_2 V_7 , T_2 V_132 , T_2 V_33 ,
struct V_68 * V_211 , int V_131 )
{
int V_29 ;
struct V_12 * V_37 = V_35 -> V_37 ;
struct V_115 * V_558 ;
struct V_162 * V_163 ;
struct V_64 * V_65 ;
struct V_66 * V_67 ;
int type ;
T_3 V_57 ;
if ( V_17 > 0 )
type = V_153 ;
else
type = V_154 ;
V_57 = sizeof( * V_558 ) + F_125 ( type ) ;
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
V_558 = F_78 ( V_67 , V_65 -> V_84 [ 0 ] ,
struct V_115 ) ;
F_90 ( V_67 , V_558 , V_131 ) ;
F_91 ( V_67 , V_558 , V_109 -> V_281 ) ;
F_92 ( V_67 , V_558 ,
V_7 | V_144 ) ;
V_163 = (struct V_162 * ) ( V_558 + 1 ) ;
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
V_29 = F_353 ( V_35 , V_211 -> V_22 , V_211 -> V_33 , 1 ) ;
if ( V_29 ) {
F_374 ( V_37 , L_31 ,
V_211 -> V_22 , V_211 -> V_33 ) ;
F_83 () ;
}
F_411 ( V_35 , V_211 -> V_22 , V_211 -> V_33 ) ;
return V_29 ;
}
static int F_161 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
T_2 V_17 , T_2 V_145 ,
T_2 V_7 , struct V_462 * V_21 ,
int V_166 , struct V_68 * V_211 ,
int V_200 )
{
int V_29 ;
struct V_12 * V_37 = V_35 -> V_37 ;
struct V_115 * V_558 ;
struct V_137 * V_559 ;
struct V_162 * V_163 ;
struct V_64 * V_65 ;
struct V_66 * V_67 ;
T_3 V_57 = sizeof( * V_558 ) + sizeof( * V_163 ) ;
T_2 V_36 = V_211 -> V_33 ;
bool V_172 = F_76 ( V_35 -> V_37 ,
V_120 ) ;
if ( ! V_172 )
V_57 += sizeof( * V_559 ) ;
V_65 = F_33 () ;
if ( ! V_65 ) {
F_410 ( V_35 , V_211 -> V_22 ,
V_35 -> V_88 ) ;
return - V_72 ;
}
V_65 -> V_206 = 1 ;
V_29 = F_106 ( V_109 , V_37 -> V_63 , V_65 ,
V_211 , V_57 ) ;
if ( V_29 ) {
F_410 ( V_35 , V_211 -> V_22 ,
V_35 -> V_88 ) ;
F_50 ( V_65 ) ;
return V_29 ;
}
V_67 = V_65 -> V_83 [ 0 ] ;
V_558 = F_78 ( V_67 , V_65 -> V_84 [ 0 ] ,
struct V_115 ) ;
F_90 ( V_67 , V_558 , 1 ) ;
F_91 ( V_67 , V_558 , V_109 -> V_281 ) ;
F_92 ( V_67 , V_558 ,
V_7 | V_143 ) ;
if ( V_172 ) {
V_163 = (struct V_162 * ) ( V_558 + 1 ) ;
V_36 = V_35 -> V_88 ;
} else {
V_559 = (struct V_137 * ) ( V_558 + 1 ) ;
F_156 ( V_67 , V_559 , V_21 ) ;
F_94 ( V_67 , V_559 , V_166 ) ;
V_163 = (struct V_162 * ) ( V_559 + 1 ) ;
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
V_29 = F_353 ( V_35 , V_211 -> V_22 , V_35 -> V_88 , 1 ) ;
if ( V_29 ) {
F_374 ( V_37 , L_31 ,
V_211 -> V_22 , V_211 -> V_33 ) ;
F_83 () ;
}
F_411 ( V_35 , V_211 -> V_22 , V_35 -> V_88 ) ;
return V_29 ;
}
int F_412 ( struct V_108 * V_109 ,
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
int F_413 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
T_2 V_145 , T_2 V_132 , T_2 V_33 ,
struct V_68 * V_211 )
{
int V_29 ;
struct V_1 * V_14 ;
if ( ! F_76 ( V_35 -> V_37 , V_482 ) ) {
V_29 = F_363 ( V_35 , V_211 -> V_22 , V_211 -> V_33 ) ;
if ( V_29 )
return V_29 ;
}
V_14 = F_68 ( V_35 -> V_37 , V_211 -> V_22 ) ;
if ( ! V_14 )
return - V_478 ;
V_29 = F_365 ( V_14 , V_211 -> V_33 ,
V_530 , 0 ) ;
F_30 ( V_29 ) ;
V_29 = F_154 ( V_109 , V_35 , 0 , V_145 ,
0 , V_132 , V_33 , V_211 , 1 ) ;
F_6 ( V_14 ) ;
return V_29 ;
}
static struct V_66 *
F_414 ( struct V_108 * V_109 , struct V_34 * V_35 ,
T_2 V_27 , T_3 V_560 , int V_166 )
{
struct V_66 * V_260 ;
V_260 = F_415 ( V_35 , V_27 , V_560 ) ;
if ( ! V_260 )
return F_416 ( - V_72 ) ;
F_417 ( V_260 , V_109 -> V_281 ) ;
F_418 ( V_35 -> V_256 . V_22 , V_260 , V_166 ) ;
F_419 ( V_260 ) ;
F_420 ( V_109 , V_35 , V_260 ) ;
F_382 ( V_561 , & V_260 -> V_502 ) ;
F_421 ( V_260 ) ;
F_422 ( V_260 ) ;
if ( V_35 -> V_256 . V_22 == V_201 ) {
if ( V_35 -> V_562 % 2 == 0 )
F_358 ( & V_35 -> V_563 , V_260 -> V_32 ,
V_260 -> V_32 + V_260 -> V_49 - 1 , V_40 ) ;
else
F_423 ( & V_35 -> V_563 , V_260 -> V_32 ,
V_260 -> V_32 + V_260 -> V_49 - 1 , V_40 ) ;
} else {
F_358 ( & V_109 -> V_126 -> V_564 , V_260 -> V_32 ,
V_260 -> V_32 + V_260 -> V_49 - 1 , V_40 ) ;
}
V_109 -> V_565 ++ ;
return V_260 ;
}
static struct V_239 *
F_424 ( struct V_108 * V_109 ,
struct V_34 * V_35 , T_3 V_560 )
{
struct V_239 * V_387 ;
struct V_239 * V_240 = & V_35 -> V_37 -> V_241 ;
int V_29 ;
bool V_566 = false ;
V_387 = F_317 ( V_109 , V_35 ) ;
if ( F_220 ( V_387 -> V_57 == 0 ) )
goto V_567;
V_78:
V_29 = F_315 ( V_387 , V_560 ) ;
if ( ! V_29 )
return V_387 ;
if ( V_387 -> V_568 )
return F_416 ( V_29 ) ;
if ( V_387 -> type == V_569 && ! V_566 ) {
V_566 = true ;
F_332 ( V_35 -> V_37 ) ;
goto V_78;
}
if ( F_245 ( V_35 , V_365 ) ) {
static F_425 ( V_570 ,
V_571 * 10 ,
1 ) ;
if ( F_426 ( & V_570 ) )
F_427 ( 1 , V_572
L_32 , V_29 ) ;
}
V_567:
V_29 = F_312 ( V_35 , V_387 , V_560 ,
V_398 ) ;
if ( ! V_29 )
return V_387 ;
if ( V_387 -> type != V_569 &&
V_387 -> V_104 == V_240 -> V_104 ) {
V_29 = F_315 ( V_240 , V_560 ) ;
if ( ! V_29 )
return V_240 ;
}
return F_416 ( V_29 ) ;
}
static void F_428 ( struct V_12 * V_37 ,
struct V_239 * V_387 , T_3 V_560 )
{
F_318 ( V_387 , V_560 , 0 ) ;
F_320 ( V_37 , V_387 , NULL , 0 ) ;
}
struct V_66 * F_429 ( struct V_108 * V_109 ,
struct V_34 * V_35 , T_3 V_560 ,
T_2 V_17 , T_2 V_145 ,
struct V_462 * V_21 , int V_166 ,
T_2 V_573 , T_2 V_522 )
{
struct V_68 V_211 ;
struct V_239 * V_387 ;
struct V_66 * V_260 ;
T_2 V_7 = 0 ;
int V_29 ;
bool V_172 = F_76 ( V_35 -> V_37 ,
V_120 ) ;
#ifdef F_219
if ( F_220 ( F_221 ( V_265 , & V_35 -> V_266 ) ) ) {
V_260 = F_414 ( V_109 , V_35 , V_35 -> V_574 ,
V_560 , V_166 ) ;
if ( ! F_194 ( V_260 ) )
V_35 -> V_574 += V_560 ;
return V_260 ;
}
#endif
V_387 = F_424 ( V_109 , V_35 , V_560 ) ;
if ( F_194 ( V_387 ) )
return F_430 ( V_387 ) ;
V_29 = F_406 ( V_35 , V_560 , V_560 ,
V_522 , V_573 , & V_211 , 0 , 0 ) ;
if ( V_29 ) {
F_428 ( V_35 -> V_37 , V_387 , V_560 ) ;
return F_416 ( V_29 ) ;
}
V_260 = F_414 ( V_109 , V_35 , V_211 . V_22 ,
V_560 , V_166 ) ;
F_30 ( F_194 ( V_260 ) ) ;
if ( V_145 == V_575 ) {
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
static T_1 void F_431 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
struct V_576 * V_577 ,
struct V_64 * V_65 )
{
T_2 V_27 ;
T_2 V_284 ;
T_2 V_111 ;
T_2 V_7 ;
T_3 V_71 ;
T_3 V_560 ;
struct V_68 V_21 ;
struct V_66 * V_480 ;
int V_29 ;
int V_578 ;
int V_579 = 0 ;
if ( V_65 -> V_84 [ V_577 -> V_166 ] < V_577 -> V_580 ) {
V_577 -> V_581 = V_577 -> V_581 * 2 / 3 ;
V_577 -> V_581 = F_396 ( V_577 -> V_581 , 2 ) ;
} else {
V_577 -> V_581 = V_577 -> V_581 * 3 / 2 ;
V_577 -> V_581 = F_24 ( int , V_577 -> V_581 ,
F_432 ( V_35 ) ) ;
}
V_480 = V_65 -> V_83 [ V_577 -> V_166 ] ;
V_71 = F_38 ( V_480 ) ;
V_560 = F_230 ( V_35 , V_577 -> V_166 - 1 ) ;
for ( V_578 = V_65 -> V_84 [ V_577 -> V_166 ] ; V_578 < V_71 ; V_578 ++ ) {
if ( V_579 >= V_577 -> V_581 )
break;
F_47 () ;
V_27 = F_229 ( V_480 , V_578 ) ;
V_284 = F_433 ( V_480 , V_578 ) ;
if ( V_578 == V_65 -> V_84 [ V_577 -> V_166 ] )
goto V_76;
if ( V_577 -> V_582 == V_583 &&
V_284 <= V_35 -> V_256 . V_33 )
continue;
V_29 = F_75 ( V_109 , V_35 , V_27 ,
V_577 -> V_166 - 1 , 1 , & V_111 ,
& V_7 ) ;
if ( V_29 < 0 )
continue;
F_30 ( V_111 == 0 ) ;
if ( V_577 -> V_582 == V_584 ) {
if ( V_111 == 1 )
goto V_76;
if ( V_577 -> V_166 == 1 &&
( V_7 & V_125 ) )
continue;
if ( ! V_577 -> V_585 ||
V_284 <= V_35 -> V_256 . V_33 )
continue;
F_123 ( V_480 , & V_21 , V_578 ) ;
V_29 = F_434 ( & V_21 ,
& V_577 -> V_586 ) ;
if ( V_29 < 0 )
continue;
} else {
if ( V_577 -> V_166 == 1 &&
( V_7 & V_125 ) )
continue;
}
V_76:
V_29 = F_435 ( V_35 , V_27 , V_560 ,
V_284 ) ;
if ( V_29 )
break;
V_579 ++ ;
}
V_577 -> V_580 = V_578 ;
}
static int F_436 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
struct V_66 * V_480 )
{
int V_44 = F_38 ( V_480 ) ;
int V_43 , V_587 , V_29 ;
struct V_68 V_21 ;
struct V_263 * V_264 ;
T_2 V_27 , V_36 ;
for ( V_43 = 0 ; V_43 < V_44 ; V_43 ++ ) {
F_40 ( V_480 , & V_21 , V_43 ) ;
if ( V_21 . type != V_269 )
continue;
V_264 = F_78 ( V_480 , V_43 , struct V_263 ) ;
V_587 = F_225 ( V_480 , V_264 ) ;
if ( V_587 == V_270 )
continue;
V_27 = F_226 ( V_480 , V_264 ) ;
if ( ! V_27 )
continue;
V_36 = F_227 ( V_480 , V_264 ) ;
V_29 = F_149 ( V_109 , V_35 -> V_37 ,
V_35 -> V_22 ,
V_27 , V_36 ,
V_588 , 0 ) ;
if ( V_29 )
return V_29 ;
}
return 0 ;
}
static int F_437 ( struct V_34 * V_35 ,
struct V_64 * V_65 , int V_589 )
{
int V_166 = 0 ;
int V_44 , V_578 ;
struct V_66 * V_480 ;
if ( V_589 == 0 )
return 1 ;
while ( V_166 <= V_589 ) {
V_480 = V_65 -> V_83 [ V_166 ] ;
V_44 = F_38 ( V_480 ) ;
V_65 -> V_84 [ V_166 ] ++ ;
V_578 = V_65 -> V_84 [ V_166 ] ;
if ( V_578 >= V_44 || V_166 == 0 ) {
if ( V_166 != V_589 ) {
F_438 ( V_480 , V_65 -> V_590 [ V_166 ] ) ;
V_65 -> V_590 [ V_166 ] = 0 ;
F_439 ( V_480 ) ;
V_65 -> V_83 [ V_166 ] = NULL ;
V_65 -> V_84 [ V_166 ] = 0 ;
}
} else {
break;
}
V_166 ++ ;
}
V_480 = V_65 -> V_83 [ V_589 ] ;
if ( V_65 -> V_84 [ V_589 ] >= F_38 ( V_480 ) )
return 1 ;
return 0 ;
}
static int F_440 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
struct V_66 * V_591 ,
T_2 V_592 ,
int V_589 )
{
int V_29 = 0 ;
int V_166 ;
struct V_66 * V_480 = V_591 ;
struct V_64 * V_65 = NULL ;
F_30 ( V_589 < 0 || V_589 > V_167 ) ;
F_30 ( V_591 == NULL ) ;
if ( ! V_35 -> V_37 -> V_205 )
return 0 ;
if ( ! F_441 ( V_591 ) ) {
V_29 = F_442 ( V_591 , V_592 ) ;
if ( V_29 )
goto V_73;
}
if ( V_589 == 0 ) {
V_29 = F_436 ( V_109 , V_35 , V_591 ) ;
goto V_73;
}
V_65 = F_33 () ;
if ( ! V_65 )
return - V_72 ;
F_443 ( V_591 ) ;
V_65 -> V_83 [ V_589 ] = V_591 ;
V_65 -> V_84 [ V_589 ] = 0 ;
V_65 -> V_590 [ V_589 ] = 0 ;
V_593:
V_166 = V_589 ;
while ( V_166 >= 0 ) {
if ( V_65 -> V_83 [ V_166 ] == NULL ) {
int V_594 = V_35 -> V_595 ;
int V_596 ;
T_2 V_597 ;
T_2 V_598 ;
V_480 = V_65 -> V_83 [ V_166 + 1 ] ;
V_596 = V_65 -> V_84 [ V_166 + 1 ] ;
V_598 = F_229 ( V_480 , V_596 ) ;
V_597 = F_433 ( V_480 , V_596 ) ;
V_480 = F_444 ( V_35 , V_598 , V_594 ,
V_597 ) ;
if ( ! V_480 || ! F_441 ( V_480 ) ) {
V_29 = - V_174 ;
goto V_73;
}
V_65 -> V_83 [ V_166 ] = V_480 ;
V_65 -> V_84 [ V_166 ] = 0 ;
F_445 ( V_480 ) ;
F_446 ( V_480 , V_599 ) ;
V_65 -> V_590 [ V_166 ] = V_600 ;
V_29 = F_149 ( V_109 , V_35 -> V_37 ,
V_35 -> V_22 ,
V_598 ,
V_594 ,
V_588 ,
0 ) ;
if ( V_29 )
goto V_73;
}
if ( V_166 == 0 ) {
V_29 = F_436 ( V_109 , V_35 , V_65 -> V_83 [ V_166 ] ) ;
if ( V_29 )
goto V_73;
V_29 = F_437 ( V_35 , V_65 , V_589 ) ;
if ( V_29 )
break;
goto V_593;
}
V_166 -- ;
}
V_29 = 0 ;
V_73:
F_50 ( V_65 ) ;
return V_29 ;
}
static T_1 int F_447 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
struct V_64 * V_65 ,
struct V_576 * V_577 , int V_601 )
{
int V_166 = V_577 -> V_166 ;
struct V_66 * V_480 = V_65 -> V_83 [ V_166 ] ;
T_2 V_602 = V_125 ;
int V_29 ;
if ( V_577 -> V_582 == V_583 &&
F_222 ( V_480 ) != V_35 -> V_256 . V_22 )
return 1 ;
if ( V_601 &&
( ( V_577 -> V_582 == V_584 && V_577 -> V_111 [ V_166 ] != 1 ) ||
( V_577 -> V_582 == V_583 && ! ( V_577 -> V_7 [ V_166 ] & V_602 ) ) ) ) {
F_30 ( ! V_65 -> V_590 [ V_166 ] ) ;
V_29 = F_75 ( V_109 , V_35 ,
V_480 -> V_32 , V_166 , 1 ,
& V_577 -> V_111 [ V_166 ] ,
& V_577 -> V_7 [ V_166 ] ) ;
F_30 ( V_29 == - V_72 ) ;
if ( V_29 )
return V_29 ;
F_30 ( V_577 -> V_111 [ V_166 ] == 0 ) ;
}
if ( V_577 -> V_582 == V_584 ) {
if ( V_577 -> V_111 [ V_166 ] > 1 )
return 1 ;
if ( V_65 -> V_590 [ V_166 ] && ! V_577 -> V_173 ) {
F_438 ( V_480 , V_65 -> V_590 [ V_166 ] ) ;
V_65 -> V_590 [ V_166 ] = 0 ;
}
return 0 ;
}
if ( ! ( V_577 -> V_7 [ V_166 ] & V_602 ) ) {
F_30 ( ! V_65 -> V_590 [ V_166 ] ) ;
V_29 = F_231 ( V_109 , V_35 , V_480 , 1 ) ;
F_30 ( V_29 ) ;
V_29 = F_232 ( V_109 , V_35 , V_480 , 0 ) ;
F_30 ( V_29 ) ;
V_29 = F_209 ( V_109 , V_35 , V_480 -> V_32 ,
V_480 -> V_49 , V_602 ,
F_223 ( V_480 ) , 0 ) ;
F_30 ( V_29 ) ;
V_577 -> V_7 [ V_166 ] |= V_602 ;
}
if ( V_65 -> V_590 [ V_166 ] && V_166 > 0 ) {
F_438 ( V_480 , V_65 -> V_590 [ V_166 ] ) ;
V_65 -> V_590 [ V_166 ] = 0 ;
}
return 0 ;
}
static T_1 int F_448 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
struct V_64 * V_65 ,
struct V_576 * V_577 , int * V_601 )
{
T_2 V_27 ;
T_2 V_284 ;
T_2 V_17 ;
T_3 V_560 ;
struct V_68 V_21 ;
struct V_66 * V_81 ;
int V_166 = V_577 -> V_166 ;
int V_76 = 0 ;
int V_29 = 0 ;
bool V_603 = false ;
V_284 = F_433 ( V_65 -> V_83 [ V_166 ] ,
V_65 -> V_84 [ V_166 ] ) ;
if ( V_577 -> V_582 == V_583 &&
V_284 <= V_35 -> V_256 . V_33 ) {
* V_601 = 1 ;
return 1 ;
}
V_27 = F_229 ( V_65 -> V_83 [ V_166 ] , V_65 -> V_84 [ V_166 ] ) ;
V_560 = F_230 ( V_35 , V_166 - 1 ) ;
V_81 = F_449 ( V_35 , V_27 , V_560 ) ;
if ( ! V_81 ) {
V_81 = F_415 ( V_35 , V_27 , V_560 ) ;
if ( ! V_81 )
return - V_72 ;
F_418 ( V_35 -> V_256 . V_22 , V_81 ,
V_166 - 1 ) ;
V_76 = 1 ;
}
F_419 ( V_81 ) ;
F_421 ( V_81 ) ;
V_29 = F_75 ( V_109 , V_35 , V_27 , V_166 - 1 , 1 ,
& V_577 -> V_111 [ V_166 - 1 ] ,
& V_577 -> V_7 [ V_166 - 1 ] ) ;
if ( V_29 < 0 ) {
F_450 ( V_81 ) ;
return V_29 ;
}
if ( F_220 ( V_577 -> V_111 [ V_166 - 1 ] == 0 ) ) {
F_374 ( V_35 -> V_37 , L_33 ) ;
F_83 () ;
}
* V_601 = 0 ;
if ( V_577 -> V_582 == V_584 ) {
if ( V_577 -> V_111 [ V_166 - 1 ] > 1 ) {
V_603 = true ;
if ( V_166 == 1 &&
( V_577 -> V_7 [ 0 ] & V_125 ) )
goto V_604;
if ( ! V_577 -> V_585 ||
V_284 <= V_35 -> V_256 . V_33 )
goto V_604;
F_123 ( V_65 -> V_83 [ V_166 ] , & V_21 ,
V_65 -> V_84 [ V_166 ] ) ;
V_29 = F_434 ( & V_21 , & V_577 -> V_586 ) ;
if ( V_29 < 0 )
goto V_604;
V_577 -> V_582 = V_583 ;
V_577 -> V_605 = V_166 - 1 ;
}
} else {
if ( V_166 == 1 &&
( V_577 -> V_7 [ 0 ] & V_125 ) )
goto V_604;
}
if ( ! F_451 ( V_81 , V_284 , 0 ) ) {
F_450 ( V_81 ) ;
F_439 ( V_81 ) ;
V_81 = NULL ;
* V_601 = 1 ;
}
if ( ! V_81 ) {
if ( V_76 && V_166 == 1 )
F_431 ( V_109 , V_35 , V_577 , V_65 ) ;
V_81 = F_444 ( V_35 , V_27 , V_560 , V_284 ) ;
if ( ! V_81 || ! F_441 ( V_81 ) ) {
F_439 ( V_81 ) ;
return - V_174 ;
}
F_419 ( V_81 ) ;
F_421 ( V_81 ) ;
}
V_166 -- ;
F_30 ( V_166 != F_223 ( V_81 ) ) ;
V_65 -> V_83 [ V_166 ] = V_81 ;
V_65 -> V_84 [ V_166 ] = 0 ;
V_65 -> V_590 [ V_166 ] = V_606 ;
V_577 -> V_166 = V_166 ;
if ( V_577 -> V_166 == 1 )
V_577 -> V_580 = 0 ;
return 0 ;
V_604:
V_577 -> V_111 [ V_166 - 1 ] = 0 ;
V_577 -> V_7 [ V_166 - 1 ] = 0 ;
if ( V_577 -> V_582 == V_584 ) {
if ( V_577 -> V_7 [ V_166 ] & V_125 ) {
V_17 = V_65 -> V_83 [ V_166 ] -> V_32 ;
} else {
F_30 ( V_35 -> V_256 . V_22 !=
F_222 ( V_65 -> V_83 [ V_166 ] ) ) ;
V_17 = 0 ;
}
if ( V_603 ) {
V_29 = F_440 ( V_109 , V_35 , V_81 ,
V_284 , V_166 - 1 ) ;
if ( V_29 ) {
F_452 ( V_607 L_34
L_35
L_36 ,
V_35 -> V_37 -> V_381 -> V_608 , V_29 ) ;
}
}
V_29 = V_268 ( V_109 , V_35 , V_27 , V_560 , V_17 ,
V_35 -> V_256 . V_22 , V_166 - 1 , 0 , 0 ) ;
F_30 ( V_29 ) ;
}
F_450 ( V_81 ) ;
F_439 ( V_81 ) ;
* V_601 = 1 ;
return 1 ;
}
static T_1 int F_453 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
struct V_64 * V_65 ,
struct V_576 * V_577 )
{
int V_29 ;
int V_166 = V_577 -> V_166 ;
struct V_66 * V_480 = V_65 -> V_83 [ V_166 ] ;
T_2 V_17 = 0 ;
if ( V_577 -> V_582 == V_583 ) {
F_30 ( V_577 -> V_605 < V_166 ) ;
if ( V_166 < V_577 -> V_605 )
goto V_73;
V_29 = F_41 ( V_65 , V_166 + 1 , & V_577 -> V_586 ) ;
if ( V_29 > 0 )
V_577 -> V_585 = 0 ;
V_577 -> V_582 = V_584 ;
V_577 -> V_605 = - 1 ;
V_65 -> V_84 [ V_166 ] = 0 ;
if ( ! V_65 -> V_590 [ V_166 ] ) {
F_30 ( V_166 == 0 ) ;
F_419 ( V_480 ) ;
F_421 ( V_480 ) ;
V_65 -> V_590 [ V_166 ] = V_606 ;
V_29 = F_75 ( V_109 , V_35 ,
V_480 -> V_32 , V_166 , 1 ,
& V_577 -> V_111 [ V_166 ] ,
& V_577 -> V_7 [ V_166 ] ) ;
if ( V_29 < 0 ) {
F_438 ( V_480 , V_65 -> V_590 [ V_166 ] ) ;
V_65 -> V_590 [ V_166 ] = 0 ;
return V_29 ;
}
F_30 ( V_577 -> V_111 [ V_166 ] == 0 ) ;
if ( V_577 -> V_111 [ V_166 ] == 1 ) {
F_438 ( V_480 , V_65 -> V_590 [ V_166 ] ) ;
V_65 -> V_590 [ V_166 ] = 0 ;
return 1 ;
}
}
}
F_30 ( V_577 -> V_111 [ V_166 ] > 1 && ! V_65 -> V_590 [ V_166 ] ) ;
if ( V_577 -> V_111 [ V_166 ] == 1 ) {
if ( V_166 == 0 ) {
if ( V_577 -> V_7 [ V_166 ] & V_125 )
V_29 = F_232 ( V_109 , V_35 , V_480 , 1 ) ;
else
V_29 = F_232 ( V_109 , V_35 , V_480 , 0 ) ;
F_30 ( V_29 ) ;
V_29 = F_436 ( V_109 , V_35 , V_480 ) ;
if ( V_29 ) {
F_452 ( V_607 L_34
L_37
L_36 ,
V_35 -> V_37 -> V_381 -> V_608 , V_29 ) ;
}
}
if ( ! V_65 -> V_590 [ V_166 ] &&
F_380 ( V_480 ) == V_109 -> V_281 ) {
F_419 ( V_480 ) ;
F_421 ( V_480 ) ;
V_65 -> V_590 [ V_166 ] = V_606 ;
}
F_420 ( V_109 , V_35 , V_480 ) ;
}
if ( V_480 == V_35 -> V_127 ) {
if ( V_577 -> V_7 [ V_166 ] & V_125 )
V_17 = V_480 -> V_32 ;
else
F_30 ( V_35 -> V_256 . V_22 !=
F_222 ( V_480 ) ) ;
} else {
if ( V_577 -> V_7 [ V_166 + 1 ] & V_125 )
V_17 = V_65 -> V_83 [ V_166 + 1 ] -> V_32 ;
else
F_30 ( V_35 -> V_256 . V_22 !=
F_222 ( V_65 -> V_83 [ V_166 + 1 ] ) ) ;
}
F_379 ( V_109 , V_35 , V_480 , V_17 , V_577 -> V_111 [ V_166 ] == 1 ) ;
V_73:
V_577 -> V_111 [ V_166 ] = 0 ;
V_577 -> V_7 [ V_166 ] = 0 ;
return 0 ;
}
static T_1 int F_454 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
struct V_64 * V_65 ,
struct V_576 * V_577 )
{
int V_166 = V_577 -> V_166 ;
int V_601 = 1 ;
int V_29 ;
while ( V_166 >= 0 ) {
V_29 = F_447 ( V_109 , V_35 , V_65 , V_577 , V_601 ) ;
if ( V_29 > 0 )
break;
if ( V_166 == 0 )
break;
if ( V_65 -> V_84 [ V_166 ] >=
F_38 ( V_65 -> V_83 [ V_166 ] ) )
break;
V_29 = F_448 ( V_109 , V_35 , V_65 , V_577 , & V_601 ) ;
if ( V_29 > 0 ) {
V_65 -> V_84 [ V_166 ] ++ ;
continue;
} else if ( V_29 < 0 )
return V_29 ;
V_166 = V_577 -> V_166 ;
}
return 0 ;
}
static T_1 int F_455 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
struct V_64 * V_65 ,
struct V_576 * V_577 , int V_609 )
{
int V_166 = V_577 -> V_166 ;
int V_29 ;
V_65 -> V_84 [ V_166 ] = F_38 ( V_65 -> V_83 [ V_166 ] ) ;
while ( V_166 < V_609 && V_65 -> V_83 [ V_166 ] ) {
V_577 -> V_166 = V_166 ;
if ( V_65 -> V_84 [ V_166 ] + 1 <
F_38 ( V_65 -> V_83 [ V_166 ] ) ) {
V_65 -> V_84 [ V_166 ] ++ ;
return 0 ;
} else {
V_29 = F_453 ( V_109 , V_35 , V_65 , V_577 ) ;
if ( V_29 > 0 )
return 0 ;
if ( V_65 -> V_590 [ V_166 ] ) {
F_438 ( V_65 -> V_83 [ V_166 ] ,
V_65 -> V_590 [ V_166 ] ) ;
V_65 -> V_590 [ V_166 ] = 0 ;
}
F_439 ( V_65 -> V_83 [ V_166 ] ) ;
V_65 -> V_83 [ V_166 ] = NULL ;
V_166 ++ ;
}
}
return 1 ;
}
int F_456 ( struct V_34 * V_35 ,
struct V_239 * V_387 , int V_585 ,
int V_610 )
{
struct V_64 * V_65 ;
struct V_108 * V_109 ;
struct V_34 * V_87 = V_35 -> V_37 -> V_87 ;
struct V_611 * V_257 = & V_35 -> V_257 ;
struct V_576 * V_577 ;
struct V_68 V_21 ;
int V_82 = 0 ;
int V_29 ;
int V_166 ;
bool V_612 = false ;
F_177 ( V_35 -> V_37 , L_38 , V_35 -> V_22 ) ;
V_65 = F_33 () ;
if ( ! V_65 ) {
V_82 = - V_72 ;
goto V_73;
}
V_577 = F_53 ( sizeof( * V_577 ) , V_40 ) ;
if ( ! V_577 ) {
F_50 ( V_65 ) ;
V_82 = - V_72 ;
goto V_73;
}
V_109 = F_457 ( V_87 , 0 ) ;
if ( F_194 ( V_109 ) ) {
V_82 = F_195 ( V_109 ) ;
goto V_122;
}
if ( V_387 )
V_109 -> V_387 = V_387 ;
if ( F_458 ( & V_257 -> V_613 ) == 0 ) {
V_166 = F_223 ( V_35 -> V_127 ) ;
V_65 -> V_83 [ V_166 ] = F_459 ( V_35 ) ;
F_421 ( V_65 -> V_83 [ V_166 ] ) ;
V_65 -> V_84 [ V_166 ] = 0 ;
V_65 -> V_590 [ V_166 ] = V_606 ;
memset ( & V_577 -> V_586 , 0 ,
sizeof( V_577 -> V_586 ) ) ;
} else {
F_460 ( & V_21 , & V_257 -> V_613 ) ;
memcpy ( & V_577 -> V_586 , & V_21 ,
sizeof( V_577 -> V_586 ) ) ;
V_166 = V_257 -> V_614 ;
F_30 ( V_166 == 0 ) ;
V_65 -> V_615 = V_166 ;
V_29 = F_37 ( NULL , V_35 , & V_21 , V_65 , 0 , 0 ) ;
V_65 -> V_615 = 0 ;
if ( V_29 < 0 ) {
V_82 = V_29 ;
goto V_616;
}
F_8 ( V_29 > 0 ) ;
F_128 ( V_65 , 0 ) ;
V_166 = F_223 ( V_35 -> V_127 ) ;
while ( 1 ) {
F_419 ( V_65 -> V_83 [ V_166 ] ) ;
F_421 ( V_65 -> V_83 [ V_166 ] ) ;
V_65 -> V_590 [ V_166 ] = V_606 ;
V_29 = F_75 ( V_109 , V_35 ,
V_65 -> V_83 [ V_166 ] -> V_32 ,
V_166 , 1 , & V_577 -> V_111 [ V_166 ] ,
& V_577 -> V_7 [ V_166 ] ) ;
if ( V_29 < 0 ) {
V_82 = V_29 ;
goto V_616;
}
F_30 ( V_577 -> V_111 [ V_166 ] == 0 ) ;
if ( V_166 == V_257 -> V_614 )
break;
F_450 ( V_65 -> V_83 [ V_166 ] ) ;
V_65 -> V_590 [ V_166 ] = 0 ;
F_8 ( V_577 -> V_111 [ V_166 ] != 1 ) ;
V_166 -- ;
}
}
V_577 -> V_166 = V_166 ;
V_577 -> V_605 = - 1 ;
V_577 -> V_582 = V_584 ;
V_577 -> V_585 = V_585 ;
V_577 -> V_173 = 0 ;
V_577 -> V_610 = V_610 ;
V_577 -> V_581 = F_432 ( V_35 ) ;
while ( 1 ) {
V_29 = F_454 ( V_109 , V_35 , V_65 , V_577 ) ;
if ( V_29 < 0 ) {
V_82 = V_29 ;
break;
}
V_29 = F_455 ( V_109 , V_35 , V_65 , V_577 , V_167 ) ;
if ( V_29 < 0 ) {
V_82 = V_29 ;
break;
}
if ( V_29 > 0 ) {
F_30 ( V_577 -> V_582 != V_584 ) ;
break;
}
if ( V_577 -> V_582 == V_584 ) {
V_166 = V_577 -> V_166 ;
F_461 ( V_65 -> V_83 [ V_166 ] ,
& V_257 -> V_613 ,
V_65 -> V_84 [ V_166 ] ) ;
V_257 -> V_614 = V_166 ;
}
F_30 ( V_577 -> V_166 == 0 ) ;
if ( F_462 ( V_109 , V_87 ) ||
( ! V_610 && F_463 ( V_35 ) ) ) {
V_29 = F_464 ( V_109 , V_87 ,
& V_35 -> V_256 ,
V_257 ) ;
if ( V_29 ) {
F_150 ( V_109 , V_87 , V_29 ) ;
V_82 = V_29 ;
goto V_616;
}
V_29 = F_207 ( V_109 ,
V_35 -> V_37 ) ;
if ( V_29 )
F_452 ( V_607 L_39
L_40
L_41
L_42
L_43 , V_29 ) ;
F_465 ( V_109 , V_87 ) ;
if ( ! V_610 && F_463 ( V_35 ) ) {
F_466 ( L_44 ) ;
V_82 = - V_177 ;
goto V_122;
}
V_109 = F_457 ( V_87 , 0 ) ;
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
goto V_616;
V_29 = F_467 ( V_109 , V_87 , & V_35 -> V_256 ) ;
if ( V_29 ) {
F_150 ( V_109 , V_87 , V_29 ) ;
goto V_616;
}
if ( V_35 -> V_256 . V_22 != V_575 ) {
V_29 = F_468 ( V_87 , & V_35 -> V_256 , V_65 ,
NULL , NULL ) ;
if ( V_29 < 0 ) {
F_150 ( V_109 , V_87 , V_29 ) ;
V_82 = V_29 ;
goto V_616;
} else if ( V_29 > 0 ) {
F_469 ( V_109 , V_87 ,
V_35 -> V_256 . V_22 ) ;
}
}
if ( F_221 ( V_617 , & V_35 -> V_266 ) ) {
F_470 ( V_87 -> V_37 , V_35 ) ;
} else {
F_439 ( V_35 -> V_127 ) ;
F_439 ( V_35 -> V_618 ) ;
F_471 ( V_35 ) ;
}
V_612 = true ;
V_616:
V_29 = F_207 ( V_109 , V_87 -> V_37 ) ;
if ( V_29 )
F_452 ( V_607 L_39
L_40
L_41
L_42
L_43 , V_29 ) ;
F_465 ( V_109 , V_87 ) ;
V_122:
F_9 ( V_577 ) ;
F_50 ( V_65 ) ;
V_73:
if ( ! V_610 && V_612 == false )
F_472 ( V_35 ) ;
if ( V_82 && V_82 != - V_177 )
F_473 ( V_35 -> V_37 , V_82 ) ;
return V_82 ;
}
int F_474 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
struct V_66 * V_127 ,
struct V_66 * V_17 )
{
struct V_64 * V_65 ;
struct V_576 * V_577 ;
int V_166 ;
int V_619 ;
int V_29 = 0 ;
int V_620 ;
F_30 ( V_35 -> V_256 . V_22 != V_575 ) ;
V_65 = F_33 () ;
if ( ! V_65 )
return - V_72 ;
V_577 = F_53 ( sizeof( * V_577 ) , V_40 ) ;
if ( ! V_577 ) {
F_50 ( V_65 ) ;
return - V_72 ;
}
F_475 ( V_17 ) ;
V_619 = F_223 ( V_17 ) ;
F_443 ( V_17 ) ;
V_65 -> V_83 [ V_619 ] = V_17 ;
V_65 -> V_84 [ V_619 ] = F_38 ( V_17 ) ;
F_475 ( V_127 ) ;
V_166 = F_223 ( V_127 ) ;
V_65 -> V_83 [ V_166 ] = V_127 ;
V_65 -> V_84 [ V_166 ] = 0 ;
V_65 -> V_590 [ V_166 ] = V_606 ;
V_577 -> V_111 [ V_619 ] = 1 ;
V_577 -> V_7 [ V_619 ] = V_125 ;
V_577 -> V_166 = V_166 ;
V_577 -> V_605 = - 1 ;
V_577 -> V_582 = V_584 ;
V_577 -> V_585 = 0 ;
V_577 -> V_173 = 1 ;
V_577 -> V_610 = 1 ;
V_577 -> V_581 = F_432 ( V_35 ) ;
while ( 1 ) {
V_620 = F_454 ( V_109 , V_35 , V_65 , V_577 ) ;
if ( V_620 < 0 ) {
V_29 = V_620 ;
break;
}
V_620 = F_455 ( V_109 , V_35 , V_65 , V_577 , V_619 ) ;
if ( V_620 < 0 )
V_29 = V_620 ;
if ( V_620 != 0 )
break;
}
F_9 ( V_577 ) ;
F_50 ( V_65 ) ;
return V_29 ;
}
static T_2 F_476 ( struct V_34 * V_35 , T_2 V_7 )
{
T_2 V_333 ;
T_2 V_621 ;
V_621 = F_264 ( V_35 -> V_37 , V_7 ) ;
if ( V_621 )
return F_266 ( V_621 ) ;
V_333 = V_35 -> V_37 -> V_334 -> V_335 ;
V_621 = V_338 |
V_339 | V_340 |
V_299 | V_300 ;
if ( V_333 == 1 ) {
V_621 |= V_298 ;
V_621 = V_7 & ~ V_621 ;
if ( V_7 & V_338 )
return V_621 ;
if ( V_7 & ( V_299 |
V_300 ) )
return V_621 | V_298 ;
} else {
if ( V_7 & V_621 )
return V_7 ;
V_621 |= V_298 ;
V_621 = V_7 & ~ V_621 ;
if ( V_7 & V_298 )
return V_621 | V_299 ;
}
return V_7 ;
}
static int F_477 ( struct V_1 * V_2 , int V_358 )
{
struct V_101 * V_357 = V_2 -> V_104 ;
T_2 V_36 ;
T_2 V_622 ;
int V_29 = - V_353 ;
if ( ( V_357 -> V_7 &
( V_294 | V_292 ) ) &&
! V_358 )
V_622 = 1 * 1024 * 1024 ;
else
V_622 = 0 ;
F_11 ( & V_357 -> V_52 ) ;
F_11 ( & V_2 -> V_52 ) ;
if ( V_2 -> V_279 ) {
V_29 = 0 ;
goto V_73;
}
V_36 = V_2 -> V_21 . V_33 - V_2 -> V_10 - V_2 -> V_9 -
V_2 -> V_46 - F_356 ( & V_2 -> V_134 ) ;
if ( V_357 -> V_296 + V_357 -> V_308 + V_357 -> V_307 +
V_357 -> V_310 + V_357 -> V_309 + V_36 +
V_622 <= V_357 -> V_295 ) {
V_357 -> V_309 += V_36 ;
V_2 -> V_279 = 1 ;
V_29 = 0 ;
}
V_73:
F_13 ( & V_2 -> V_52 ) ;
F_13 ( & V_357 -> V_52 ) ;
return V_29 ;
}
int F_478 ( struct V_34 * V_35 ,
struct V_1 * V_2 )
{
struct V_108 * V_109 ;
T_2 V_623 ;
int V_29 ;
F_30 ( V_2 -> V_279 ) ;
V_109 = F_193 ( V_35 ) ;
if ( F_194 ( V_109 ) )
return F_195 ( V_109 ) ;
V_623 = F_476 ( V_35 , V_2 -> V_7 ) ;
if ( V_623 != V_2 -> V_7 ) {
V_29 = F_273 ( V_109 , V_35 , V_623 ,
V_352 ) ;
if ( V_29 < 0 )
goto V_73;
}
V_29 = F_477 ( V_2 , 0 ) ;
if ( ! V_29 )
goto V_73;
V_623 = F_267 ( V_35 , V_2 -> V_104 -> V_7 ) ;
V_29 = F_273 ( V_109 , V_35 , V_623 ,
V_352 ) ;
if ( V_29 < 0 )
goto V_73;
V_29 = F_477 ( V_2 , 0 ) ;
V_73:
F_197 ( V_109 , V_35 ) ;
return V_29 ;
}
int F_479 ( struct V_108 * V_109 ,
struct V_34 * V_35 , T_2 type )
{
T_2 V_623 = F_267 ( V_35 , type ) ;
return F_273 ( V_109 , V_35 , V_623 ,
V_352 ) ;
}
static T_2 F_480 ( struct V_102 * V_624 )
{
struct V_1 * V_14 ;
T_2 V_625 = 0 ;
int V_297 ;
F_397 (block_group, groups_list, list) {
F_11 ( & V_14 -> V_52 ) ;
if ( ! V_14 -> V_279 ) {
F_13 ( & V_14 -> V_52 ) ;
continue;
}
if ( V_14 -> V_7 & ( V_299 |
V_300 |
V_298 ) )
V_297 = 2 ;
else
V_297 = 1 ;
V_625 += ( V_14 -> V_21 . V_33 -
F_356 ( & V_14 -> V_134 ) ) *
V_297 ;
F_13 ( & V_14 -> V_52 ) ;
}
return V_625 ;
}
T_2 F_481 ( struct V_101 * V_357 )
{
int V_43 ;
T_2 V_625 = 0 ;
F_11 ( & V_357 -> V_52 ) ;
for ( V_43 = 0 ; V_43 < V_304 ; V_43 ++ )
if ( ! F_204 ( & V_357 -> V_305 [ V_43 ] ) )
V_625 += F_480 (
& V_357 -> V_305 [ V_43 ] ) ;
F_13 ( & V_357 -> V_52 ) ;
return V_625 ;
}
void F_482 ( struct V_34 * V_35 ,
struct V_1 * V_2 )
{
struct V_101 * V_357 = V_2 -> V_104 ;
T_2 V_36 ;
F_30 ( ! V_2 -> V_279 ) ;
F_11 ( & V_357 -> V_52 ) ;
F_11 ( & V_2 -> V_52 ) ;
V_36 = V_2 -> V_21 . V_33 - V_2 -> V_10 - V_2 -> V_9 -
V_2 -> V_46 - F_356 ( & V_2 -> V_134 ) ;
V_357 -> V_309 -= V_36 ;
V_2 -> V_279 = 0 ;
F_13 ( & V_2 -> V_52 ) ;
F_13 ( & V_357 -> V_52 ) ;
}
int F_483 ( struct V_34 * V_35 , T_2 V_27 )
{
struct V_1 * V_14 ;
struct V_101 * V_104 ;
struct V_626 * V_334 = V_35 -> V_37 -> V_334 ;
struct V_627 * V_628 ;
struct V_108 * V_109 ;
T_2 V_629 ;
T_2 V_630 = 1 ;
T_2 V_631 = 0 ;
T_2 V_328 ;
int V_528 ;
int V_107 = 0 ;
int V_29 = 0 ;
V_14 = F_68 ( V_35 -> V_37 , V_27 ) ;
if ( ! V_14 )
return - 1 ;
V_629 = F_356 ( & V_14 -> V_134 ) ;
if ( ! V_629 )
goto V_73;
V_104 = V_14 -> V_104 ;
F_11 ( & V_104 -> V_52 ) ;
V_107 = V_104 -> V_107 ;
if ( ( V_104 -> V_295 != V_14 -> V_21 . V_33 ) &&
( V_104 -> V_296 + V_104 -> V_308 +
V_104 -> V_307 + V_104 -> V_309 +
V_629 < V_104 -> V_295 ) ) {
F_13 ( & V_104 -> V_52 ) ;
goto V_73;
}
F_13 ( & V_104 -> V_52 ) ;
V_29 = - 1 ;
V_328 = F_264 ( V_35 -> V_37 , V_14 -> V_7 ) ;
if ( V_328 ) {
V_528 = F_386 ( F_266 ( V_328 ) ) ;
} else {
if ( V_107 )
goto V_73;
V_528 = F_387 ( V_14 ) ;
}
if ( V_528 == V_506 ) {
V_630 = 4 ;
V_629 >>= 1 ;
} else if ( V_528 == V_507 ) {
V_630 = 2 ;
} else if ( V_528 == V_508 ) {
V_629 <<= 1 ;
} else if ( V_528 == V_509 ) {
V_630 = V_334 -> V_335 ;
F_484 ( V_629 , V_630 ) ;
}
V_109 = F_193 ( V_35 ) ;
if ( F_194 ( V_109 ) ) {
V_29 = F_195 ( V_109 ) ;
goto V_73;
}
F_35 ( & V_35 -> V_37 -> V_368 ) ;
F_397 (device, &fs_devices->alloc_list, dev_alloc_list) {
T_2 V_632 ;
if ( V_628 -> V_295 > V_628 -> V_296 + V_629 &&
! V_628 -> V_633 ) {
V_29 = F_485 ( V_109 , V_628 , V_629 ,
& V_632 , NULL ) ;
if ( ! V_29 )
V_631 ++ ;
if ( V_631 >= V_630 )
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
static int F_486 ( struct V_34 * V_35 ,
struct V_64 * V_65 , struct V_68 * V_21 )
{
int V_29 = 0 ;
struct V_68 V_139 ;
struct V_66 * V_67 ;
int V_578 ;
V_29 = F_37 ( NULL , V_35 , V_21 , V_65 , 0 , 0 ) ;
if ( V_29 < 0 )
goto V_73;
while ( 1 ) {
V_578 = V_65 -> V_84 [ 0 ] ;
V_67 = V_65 -> V_83 [ 0 ] ;
if ( V_578 >= F_38 ( V_67 ) ) {
V_29 = F_48 ( V_35 , V_65 ) ;
if ( V_29 == 0 )
continue;
if ( V_29 < 0 )
goto V_73;
break;
}
F_40 ( V_67 , & V_139 , V_578 ) ;
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
void F_487 ( struct V_12 * V_13 )
{
struct V_1 * V_14 ;
T_2 V_70 = 0 ;
while ( 1 ) {
struct V_271 * V_271 ;
V_14 = F_67 ( V_13 , V_70 ) ;
while ( V_14 ) {
F_11 ( & V_14 -> V_52 ) ;
if ( V_14 -> V_163 )
break;
F_13 ( & V_14 -> V_52 ) ;
V_14 = F_236 ( V_13 -> V_87 ,
V_14 ) ;
}
if ( ! V_14 ) {
if ( V_70 == 0 )
break;
V_70 = 0 ;
continue;
}
V_271 = V_14 -> V_271 ;
V_14 -> V_163 = 0 ;
V_14 -> V_271 = NULL ;
F_13 ( & V_14 -> V_52 ) ;
F_249 ( V_271 ) ;
V_70 = V_14 -> V_21 . V_22 + V_14 -> V_21 . V_33 ;
F_6 ( V_14 ) ;
}
}
int F_488 ( struct V_12 * V_13 )
{
struct V_1 * V_14 ;
struct V_101 * V_104 ;
struct V_50 * V_54 ;
struct V_15 * V_30 ;
F_63 ( & V_13 -> V_80 ) ;
while ( ! F_204 ( & V_13 -> V_99 ) ) {
V_54 = F_489 ( V_13 -> V_99 . V_81 ,
struct V_50 , V_91 ) ;
F_490 ( & V_54 -> V_91 ) ;
F_26 ( V_54 ) ;
}
F_65 ( & V_13 -> V_80 ) ;
F_11 ( & V_13 -> V_18 ) ;
while ( ( V_30 = F_185 ( & V_13 -> V_19 ) ) != NULL ) {
V_14 = F_12 ( V_30 , struct V_1 ,
V_20 ) ;
F_179 ( & V_14 -> V_20 ,
& V_13 -> V_19 ) ;
F_13 ( & V_13 -> V_18 ) ;
F_63 ( & V_14 -> V_104 -> V_306 ) ;
F_490 ( & V_14 -> V_91 ) ;
F_65 ( & V_14 -> V_104 -> V_306 ) ;
if ( V_14 -> V_3 == V_53 )
F_385 ( V_14 ) ;
if ( V_14 -> V_3 == V_95 ||
V_14 -> V_3 == V_5 )
F_19 ( V_13 -> V_63 , V_14 ) ;
F_491 ( V_14 ) ;
F_6 ( V_14 ) ;
F_11 ( & V_13 -> V_18 ) ;
}
F_13 ( & V_13 -> V_18 ) ;
F_492 () ;
F_334 ( V_13 ) ;
while ( ! F_204 ( & V_13 -> V_104 ) ) {
int V_43 ;
V_104 = F_489 ( V_13 -> V_104 . V_81 ,
struct V_101 ,
V_91 ) ;
if ( F_245 ( V_13 -> V_87 , V_365 ) ) {
if ( F_8 ( V_104 -> V_307 > 0 ||
V_104 -> V_308 > 0 ||
V_104 -> V_310 > 0 ) ) {
F_286 ( V_104 , 0 , 0 ) ;
}
}
F_490 ( & V_104 -> V_91 ) ;
for ( V_43 = 0 ; V_43 < V_304 ; V_43 ++ ) {
struct V_634 * V_315 ;
V_315 = V_104 -> V_635 [ V_43 ] ;
V_104 -> V_635 [ V_43 ] = NULL ;
if ( V_315 ) {
F_493 ( V_315 ) ;
F_494 ( V_315 ) ;
}
}
F_493 ( & V_104 -> V_315 ) ;
F_494 ( & V_104 -> V_315 ) ;
}
return 0 ;
}
static void F_495 ( struct V_101 * V_104 ,
struct V_1 * V_2 )
{
int V_528 = F_387 ( V_2 ) ;
bool V_237 = false ;
F_63 ( & V_104 -> V_306 ) ;
if ( F_204 ( & V_104 -> V_305 [ V_528 ] ) )
V_237 = true ;
F_64 ( & V_2 -> V_91 , & V_104 -> V_305 [ V_528 ] ) ;
F_65 ( & V_104 -> V_306 ) ;
if ( V_237 ) {
struct V_636 * V_637 ;
int V_29 ;
V_637 = F_53 ( sizeof( * V_637 ) , V_40 ) ;
if ( ! V_637 )
goto V_638;
V_637 -> V_639 = V_528 ;
F_496 ( & V_637 -> V_315 , & V_640 ) ;
V_29 = F_497 ( & V_637 -> V_315 , & V_104 -> V_315 ,
L_8 , F_388 ( V_528 ) ) ;
if ( V_29 ) {
F_494 ( & V_637 -> V_315 ) ;
goto V_638;
}
V_104 -> V_635 [ V_528 ] = & V_637 -> V_315 ;
}
return;
V_638:
F_498 ( L_45 ) ;
}
static struct V_1 *
F_499 ( struct V_34 * V_35 , T_2 V_32 , T_2 V_57 )
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
V_2 -> V_641 = F_500 ( V_35 ,
& V_35 -> V_37 -> V_48 ,
V_32 ) ;
F_57 ( & V_2 -> V_8 , 1 ) ;
F_257 ( & V_2 -> V_52 ) ;
F_256 ( & V_2 -> V_515 ) ;
F_54 ( & V_2 -> V_91 ) ;
F_54 ( & V_2 -> V_642 ) ;
F_54 ( & V_2 -> V_643 ) ;
F_501 ( V_2 ) ;
return V_2 ;
}
int F_502 ( struct V_34 * V_35 )
{
struct V_64 * V_65 ;
int V_29 ;
struct V_1 * V_2 ;
struct V_12 * V_13 = V_35 -> V_37 ;
struct V_101 * V_104 ;
struct V_68 V_21 ;
struct V_68 V_139 ;
struct V_66 * V_67 ;
int V_644 = 0 ;
T_2 V_645 ;
V_35 = V_13 -> V_63 ;
V_21 . V_22 = 0 ;
V_21 . V_33 = 0 ;
F_394 ( & V_21 , V_178 ) ;
V_65 = F_33 () ;
if ( ! V_65 )
return - V_72 ;
V_65 -> V_76 = 1 ;
V_645 = F_503 ( V_35 -> V_37 -> V_362 ) ;
if ( F_245 ( V_35 , V_285 ) &&
F_504 ( V_35 -> V_37 -> V_362 ) != V_645 )
V_644 = 1 ;
if ( F_245 ( V_35 , V_646 ) )
V_644 = 1 ;
while ( 1 ) {
V_29 = F_486 ( V_35 , V_65 , & V_21 ) ;
if ( V_29 > 0 )
break;
if ( V_29 != 0 )
goto error;
V_67 = V_65 -> V_83 [ 0 ] ;
F_40 ( V_67 , & V_139 , V_65 -> V_84 [ 0 ] ) ;
V_2 = F_499 ( V_35 , V_139 . V_22 ,
V_139 . V_33 ) ;
if ( ! V_2 ) {
V_29 = - V_72 ;
goto error;
}
if ( V_644 ) {
V_2 -> V_277 = V_288 ;
if ( F_245 ( V_35 , V_285 ) )
V_2 -> V_289 = 1 ;
}
F_505 ( V_67 , & V_2 -> V_134 ,
F_234 ( V_67 , V_65 -> V_84 [ 0 ] ) ,
sizeof( V_2 -> V_134 ) ) ;
V_2 -> V_7 = F_506 ( & V_2 -> V_134 ) ;
V_21 . V_22 = V_139 . V_22 + V_139 . V_33 ;
F_44 ( V_65 ) ;
V_29 = F_21 ( V_35 , V_2 ) ;
if ( V_29 ) {
F_19 ( V_35 , V_2 ) ;
F_6 ( V_2 ) ;
goto error;
}
if ( V_139 . V_33 == F_356 ( & V_2 -> V_134 ) ) {
V_2 -> V_98 = ( T_2 ) - 1 ;
V_2 -> V_3 = V_4 ;
F_19 ( V_35 , V_2 ) ;
} else if ( F_356 ( & V_2 -> V_134 ) == 0 ) {
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
F_491 ( V_2 ) ;
F_6 ( V_2 ) ;
goto error;
}
V_29 = F_254 ( V_13 , V_2 -> V_7 , V_139 . V_33 ,
F_356 ( & V_2 -> V_134 ) ,
& V_104 ) ;
if ( V_29 ) {
F_491 ( V_2 ) ;
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
F_495 ( V_104 , V_2 ) ;
F_260 ( V_35 -> V_37 , V_2 -> V_7 ) ;
if ( F_507 ( V_35 , V_2 -> V_21 . V_22 ) )
F_477 ( V_2 , 1 ) ;
}
F_71 (space_info, &root->fs_info->space_info, list) {
if ( ! ( F_267 ( V_35 , V_104 -> V_7 ) &
( V_300 |
V_299 |
V_339 |
V_340 |
V_298 ) ) )
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
F_333 ( V_13 ) ;
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
struct V_647 V_134 ;
struct V_68 V_21 ;
int V_29 = 0 ;
F_367 (block_group, tmp, &trans->new_bgs,
new_bg_list) {
F_368 ( & V_14 -> V_643 ) ;
if ( V_29 )
continue;
F_11 ( & V_14 -> V_52 ) ;
memcpy ( & V_134 , & V_14 -> V_134 , sizeof( V_134 ) ) ;
memcpy ( & V_21 , & V_14 -> V_21 , sizeof( V_21 ) ) ;
F_13 ( & V_14 -> V_52 ) ;
V_29 = F_508 ( V_109 , V_63 , & V_21 , & V_134 ,
sizeof( V_134 ) ) ;
if ( V_29 )
F_150 ( V_109 , V_63 , V_29 ) ;
V_29 = F_509 ( V_109 , V_63 ,
V_21 . V_22 , V_21 . V_33 ) ;
if ( V_29 )
F_150 ( V_109 , V_63 , V_29 ) ;
}
}
int F_510 ( struct V_108 * V_109 ,
struct V_34 * V_35 , T_2 V_296 ,
T_2 type , T_2 V_648 , T_2 V_649 ,
T_2 V_57 )
{
int V_29 ;
struct V_34 * V_63 ;
struct V_1 * V_2 ;
V_63 = V_35 -> V_37 -> V_63 ;
F_511 ( V_35 -> V_37 , V_109 ) ;
V_2 = F_499 ( V_35 , V_649 , V_57 ) ;
if ( ! V_2 )
return - V_72 ;
F_357 ( & V_2 -> V_134 , V_296 ) ;
F_512 ( & V_2 -> V_134 , V_648 ) ;
F_513 ( & V_2 -> V_134 , type ) ;
V_2 -> V_7 = type ;
V_2 -> V_98 = ( T_2 ) - 1 ;
V_2 -> V_3 = V_4 ;
V_29 = F_21 ( V_35 , V_2 ) ;
if ( V_29 ) {
F_19 ( V_35 , V_2 ) ;
F_6 ( V_2 ) ;
return V_29 ;
}
F_27 ( V_2 , V_35 -> V_37 , V_649 ,
V_649 + V_57 ) ;
F_19 ( V_35 , V_2 ) ;
V_29 = F_10 ( V_35 -> V_37 , V_2 ) ;
if ( V_29 ) {
F_491 ( V_2 ) ;
F_6 ( V_2 ) ;
return V_29 ;
}
V_29 = F_254 ( V_35 -> V_37 , V_2 -> V_7 , V_57 , V_296 ,
& V_2 -> V_104 ) ;
if ( V_29 ) {
F_491 ( V_2 ) ;
F_11 ( & V_35 -> V_37 -> V_18 ) ;
F_179 ( & V_2 -> V_20 ,
& V_35 -> V_37 -> V_19 ) ;
F_13 ( & V_35 -> V_37 -> V_18 ) ;
F_6 ( V_2 ) ;
return V_29 ;
}
F_332 ( V_35 -> V_37 ) ;
F_11 ( & V_2 -> V_104 -> V_52 ) ;
V_2 -> V_104 -> V_309 += V_2 -> V_46 ;
F_13 ( & V_2 -> V_104 -> V_52 ) ;
F_495 ( V_2 -> V_104 , V_2 ) ;
F_64 ( & V_2 -> V_643 , & V_109 -> V_254 ) ;
F_260 ( V_63 -> V_37 , type ) ;
return 0 ;
}
static void F_514 ( struct V_12 * V_37 , T_2 V_7 )
{
T_2 V_319 = F_261 ( V_7 ) &
V_320 ;
F_262 ( & V_37 -> V_321 ) ;
if ( V_7 & V_293 )
V_37 -> V_322 &= ~ V_319 ;
if ( V_7 & V_292 )
V_37 -> V_323 &= ~ V_319 ;
if ( V_7 & V_294 )
V_37 -> V_324 &= ~ V_319 ;
F_263 ( & V_37 -> V_321 ) ;
}
int F_515 ( struct V_108 * V_109 ,
struct V_34 * V_35 , T_2 V_650 )
{
struct V_64 * V_65 ;
struct V_1 * V_14 ;
struct V_516 * V_517 ;
struct V_34 * V_87 = V_35 -> V_37 -> V_87 ;
struct V_68 V_21 ;
struct V_271 * V_271 ;
struct V_634 * V_315 = NULL ;
int V_29 ;
int V_528 ;
int V_297 ;
V_35 = V_35 -> V_37 -> V_63 ;
V_14 = F_68 ( V_35 -> V_37 , V_650 ) ;
F_30 ( ! V_14 ) ;
F_30 ( ! V_14 -> V_279 ) ;
F_19 ( V_35 , V_14 ) ;
memcpy ( & V_21 , & V_14 -> V_21 , sizeof( V_21 ) ) ;
V_528 = F_387 ( V_14 ) ;
if ( V_14 -> V_7 & ( V_298 |
V_299 |
V_300 ) )
V_297 = 2 ;
else
V_297 = 1 ;
V_517 = & V_35 -> V_37 -> V_537 ;
F_11 ( & V_517 -> V_520 ) ;
F_400 ( V_14 , V_517 ) ;
F_13 ( & V_517 -> V_520 ) ;
V_517 = & V_35 -> V_37 -> V_535 ;
F_11 ( & V_517 -> V_520 ) ;
F_400 ( V_14 , V_517 ) ;
F_13 ( & V_517 -> V_520 ) ;
V_65 = F_33 () ;
if ( ! V_65 ) {
V_29 = - V_72 ;
goto V_73;
}
V_271 = F_238 ( V_87 , V_14 , V_65 ) ;
if ( ! F_194 ( V_271 ) ) {
V_29 = F_516 ( V_109 , V_271 ) ;
if ( V_29 ) {
F_517 ( V_271 ) ;
goto V_73;
}
F_518 ( V_271 ) ;
F_11 ( & V_14 -> V_52 ) ;
if ( V_14 -> V_163 ) {
V_14 -> V_163 = 0 ;
V_14 -> V_271 = NULL ;
F_13 ( & V_14 -> V_52 ) ;
F_249 ( V_271 ) ;
} else {
F_13 ( & V_14 -> V_52 ) ;
}
F_517 ( V_271 ) ;
}
V_21 . V_22 = V_651 ;
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
F_368 ( & V_14 -> V_91 ) ;
if ( F_204 ( & V_14 -> V_104 -> V_305 [ V_528 ] ) ) {
V_315 = V_14 -> V_104 -> V_635 [ V_528 ] ;
V_14 -> V_104 -> V_635 [ V_528 ] = NULL ;
F_514 ( V_35 -> V_37 , V_14 -> V_7 ) ;
}
F_65 ( & V_14 -> V_104 -> V_306 ) ;
if ( V_315 ) {
F_493 ( V_315 ) ;
F_494 ( V_315 ) ;
}
if ( V_14 -> V_3 == V_53 )
F_385 ( V_14 ) ;
F_491 ( V_14 ) ;
F_11 ( & V_14 -> V_104 -> V_52 ) ;
V_14 -> V_104 -> V_295 -= V_14 -> V_21 . V_33 ;
V_14 -> V_104 -> V_309 -= V_14 -> V_21 . V_33 ;
V_14 -> V_104 -> V_301 -= V_14 -> V_21 . V_33 * V_297 ;
F_13 ( & V_14 -> V_104 -> V_52 ) ;
memcpy ( & V_21 , & V_14 -> V_21 , sizeof( V_21 ) ) ;
F_73 ( V_35 -> V_37 ) ;
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
int F_519 ( struct V_12 * V_37 )
{
struct V_101 * V_104 ;
struct V_652 * V_653 ;
T_2 V_654 ;
T_2 V_7 ;
int V_655 = 0 ;
int V_29 ;
V_653 = V_37 -> V_362 ;
if ( ! F_520 ( V_653 ) )
return 1 ;
V_654 = F_521 ( V_653 ) ;
if ( V_654 & V_656 )
V_655 = 1 ;
V_7 = V_294 ;
V_29 = F_254 ( V_37 , V_7 , 0 , 0 , & V_104 ) ;
if ( V_29 )
goto V_73;
if ( V_655 ) {
V_7 = V_292 | V_293 ;
V_29 = F_254 ( V_37 , V_7 , 0 , 0 , & V_104 ) ;
} else {
V_7 = V_292 ;
V_29 = F_254 ( V_37 , V_7 , 0 , 0 , & V_104 ) ;
if ( V_29 )
goto V_73;
V_7 = V_293 ;
V_29 = F_254 ( V_37 , V_7 , 0 , 0 , & V_104 ) ;
}
V_73:
return V_29 ;
}
int F_522 ( struct V_34 * V_35 , T_2 V_32 , T_2 V_31 )
{
return F_369 ( V_35 , V_32 , V_31 ) ;
}
int F_523 ( struct V_34 * V_35 , T_2 V_27 ,
T_2 V_36 , T_2 * V_186 )
{
return F_142 ( V_35 , V_27 , V_36 , V_186 ) ;
}
int F_524 ( struct V_34 * V_35 , struct V_657 * V_658 )
{
struct V_12 * V_37 = V_35 -> V_37 ;
struct V_1 * V_2 = NULL ;
T_2 V_659 ;
T_2 V_32 ;
T_2 V_31 ;
T_2 V_660 = 0 ;
T_2 V_295 = F_280 ( V_37 -> V_362 ) ;
int V_29 = 0 ;
if ( V_658 -> V_49 == V_295 )
V_2 = F_67 ( V_37 , V_658 -> V_32 ) ;
else
V_2 = F_68 ( V_37 , V_658 -> V_32 ) ;
while ( V_2 ) {
if ( V_2 -> V_21 . V_22 >= ( V_658 -> V_32 + V_658 -> V_49 ) ) {
F_6 ( V_2 ) ;
break;
}
V_32 = F_396 ( V_658 -> V_32 , V_2 -> V_21 . V_22 ) ;
V_31 = F_298 ( V_658 -> V_32 + V_658 -> V_49 ,
V_2 -> V_21 . V_22 + V_2 -> V_21 . V_33 ) ;
if ( V_31 - V_32 >= V_658 -> V_661 ) {
if ( ! F_1 ( V_2 ) ) {
V_29 = F_51 ( V_2 , 0 ) ;
if ( V_29 ) {
F_6 ( V_2 ) ;
break;
}
V_29 = F_385 ( V_2 ) ;
if ( V_29 ) {
F_6 ( V_2 ) ;
break;
}
}
V_29 = F_525 ( V_2 ,
& V_659 ,
V_32 ,
V_31 ,
V_658 -> V_661 ) ;
V_660 += V_659 ;
if ( V_29 ) {
F_6 ( V_2 ) ;
break;
}
}
V_2 = F_236 ( V_37 -> V_87 , V_2 ) ;
}
V_658 -> V_49 = V_660 ;
return V_29 ;
}
void F_526 ( struct V_34 * V_35 )
{
F_527 ( & V_35 -> V_662 -> V_663 ) ;
F_2 () ;
if ( F_528 ( & V_35 -> V_662 -> V_89 ) )
F_49 ( & V_35 -> V_662 -> V_89 ) ;
}
int F_529 ( struct V_34 * V_35 )
{
if ( F_220 ( F_191 ( & V_35 -> V_664 ) ) )
return 0 ;
F_530 ( & V_35 -> V_662 -> V_663 ) ;
F_2 () ;
if ( F_220 ( F_191 ( & V_35 -> V_664 ) ) ) {
F_526 ( V_35 ) ;
return 0 ;
}
return 1 ;
}
