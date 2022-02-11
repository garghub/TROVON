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
if ( V_110 ) {
V_21 . V_22 = V_27 ;
V_21 . type = V_86 ;
V_21 . V_33 = V_33 ;
} else {
V_21 . V_22 = V_27 ;
V_21 . type = V_77 ;
V_21 . V_33 = V_33 ;
}
if ( ! V_109 ) {
V_65 -> V_74 = 1 ;
V_65 -> V_75 = 1 ;
}
V_78:
V_29 = F_37 ( V_109 , V_35 -> V_37 -> V_63 ,
& V_21 , V_65 , 0 , 0 ) ;
if ( V_29 < 0 )
goto V_121;
if ( V_29 > 0 && V_110 && V_21 . type == V_86 ) {
V_110 = 0 ;
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
struct V_122 * V_123 ;
F_30 ( V_117 != sizeof( * V_123 ) ) ;
V_123 = F_76 ( V_67 , V_65 -> V_84 [ 0 ] ,
struct V_122 ) ;
V_118 = F_80 ( V_67 , V_123 ) ;
V_119 = V_124 ;
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
V_114 = & V_109 -> V_125 -> V_114 ;
F_11 ( & V_114 -> V_52 ) ;
V_103 = F_82 ( V_109 , V_27 ) ;
if ( V_103 ) {
if ( ! F_83 ( & V_103 -> V_79 ) ) {
F_5 ( & V_103 -> V_126 . V_111 ) ;
F_13 ( & V_114 -> V_52 ) ;
F_43 ( V_65 ) ;
F_35 ( & V_103 -> V_79 ) ;
F_45 ( & V_103 -> V_79 ) ;
F_84 ( & V_103 -> V_126 ) ;
goto V_78;
}
if ( V_103 -> V_127 && V_103 -> V_127 -> V_128 )
V_119 |= V_103 -> V_127 -> V_129 ;
else
F_30 ( V_118 == 0 ) ;
V_118 += V_103 -> V_126 . V_130 ;
F_45 ( & V_103 -> V_79 ) ;
}
F_13 ( & V_114 -> V_52 ) ;
V_73:
F_8 ( V_118 == 0 ) ;
if ( V_111 )
* V_111 = V_118 ;
if ( V_7 )
* V_7 = V_119 ;
V_121:
F_49 ( V_65 ) ;
return V_29 ;
}
static int F_85 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
struct V_64 * V_65 ,
T_2 V_131 , T_3 V_132 )
{
struct V_115 * V_133 ;
struct V_122 * V_123 ;
struct V_134 * V_135 ;
struct V_136 * V_137 ;
struct V_66 * V_67 ;
struct V_68 V_21 ;
struct V_68 V_138 ;
T_3 V_139 = sizeof( * V_133 ) ;
T_2 V_111 ;
int V_29 ;
V_67 = V_65 -> V_83 [ 0 ] ;
F_30 ( F_75 ( V_67 , V_65 -> V_84 [ 0 ] ) != sizeof( * V_123 ) ) ;
F_40 ( V_67 , & V_21 , V_65 -> V_84 [ 0 ] ) ;
V_123 = F_76 ( V_67 , V_65 -> V_84 [ 0 ] ,
struct V_122 ) ;
V_111 = F_80 ( V_67 , V_123 ) ;
if ( V_131 == ( T_2 ) - 1 ) {
while ( 1 ) {
if ( V_65 -> V_84 [ 0 ] >= F_38 ( V_67 ) ) {
V_29 = F_47 ( V_35 , V_65 ) ;
if ( V_29 < 0 )
return V_29 ;
F_30 ( V_29 > 0 ) ;
V_67 = V_65 -> V_83 [ 0 ] ;
}
F_40 ( V_67 , & V_138 ,
V_65 -> V_84 [ 0 ] ) ;
F_30 ( V_21 . V_22 != V_138 . V_22 ) ;
if ( V_138 . type != V_140 ) {
V_65 -> V_84 [ 0 ] ++ ;
continue;
}
V_135 = F_76 ( V_67 , V_65 -> V_84 [ 0 ] ,
struct V_134 ) ;
V_131 = F_86 ( V_67 , V_135 ) ;
break;
}
}
F_43 ( V_65 ) ;
if ( V_131 < V_141 )
V_139 += sizeof( * V_137 ) ;
V_139 -= sizeof( * V_123 ) ;
V_29 = F_37 ( V_109 , V_35 , & V_21 , V_65 ,
V_139 + V_132 , 1 ) ;
if ( V_29 < 0 )
return V_29 ;
F_30 ( V_29 ) ;
F_87 ( V_35 , V_65 , V_139 ) ;
V_67 = V_65 -> V_83 [ 0 ] ;
V_133 = F_76 ( V_67 , V_65 -> V_84 [ 0 ] , struct V_115 ) ;
F_88 ( V_67 , V_133 , V_111 ) ;
F_89 ( V_67 , V_133 , 0 ) ;
if ( V_131 < V_141 ) {
F_90 ( V_67 , V_133 ,
V_142 |
V_124 ) ;
V_137 = (struct V_136 * ) ( V_133 + 1 ) ;
F_91 ( V_67 , 0 , ( unsigned long ) V_137 , sizeof( * V_137 ) ) ;
F_92 ( V_67 , V_137 , ( int ) V_131 ) ;
} else {
F_90 ( V_67 , V_133 , V_143 ) ;
}
F_93 ( V_67 ) ;
return 0 ;
}
static T_2 F_94 ( T_2 V_144 , T_2 V_131 , T_2 V_33 )
{
T_3 V_145 = ~ ( T_3 ) 0 ;
T_3 V_146 = ~ ( T_3 ) 0 ;
T_4 V_147 ;
V_147 = F_95 ( V_144 ) ;
V_145 = F_96 ( V_145 , & V_147 , sizeof( V_147 ) ) ;
V_147 = F_95 ( V_131 ) ;
V_146 = F_96 ( V_146 , & V_147 , sizeof( V_147 ) ) ;
V_147 = F_95 ( V_33 ) ;
V_146 = F_96 ( V_146 , & V_147 , sizeof( V_147 ) ) ;
return ( ( T_2 ) V_145 << 31 ) ^ ( T_2 ) V_146 ;
}
static T_2 F_97 ( struct V_66 * V_67 ,
struct V_148 * V_149 )
{
return F_94 ( F_98 ( V_67 , V_149 ) ,
F_99 ( V_67 , V_149 ) ,
F_100 ( V_67 , V_149 ) ) ;
}
static int F_101 ( struct V_66 * V_67 ,
struct V_148 * V_149 ,
T_2 V_144 , T_2 V_131 , T_2 V_33 )
{
if ( F_98 ( V_67 , V_149 ) != V_144 ||
F_99 ( V_67 , V_149 ) != V_131 ||
F_100 ( V_67 , V_149 ) != V_33 )
return 0 ;
return 1 ;
}
static T_1 int F_102 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
struct V_64 * V_65 ,
T_2 V_27 , T_2 V_17 ,
T_2 V_144 ,
T_2 V_131 , T_2 V_33 )
{
struct V_68 V_21 ;
struct V_148 * V_149 ;
struct V_66 * V_67 ;
T_3 V_71 ;
int V_29 ;
int V_150 ;
int V_82 = - V_151 ;
V_21 . V_22 = V_27 ;
if ( V_17 ) {
V_21 . type = V_152 ;
V_21 . V_33 = V_17 ;
} else {
V_21 . type = V_153 ;
V_21 . V_33 = F_94 ( V_144 ,
V_131 , V_33 ) ;
}
V_78:
V_150 = 0 ;
V_29 = F_37 ( V_109 , V_35 , & V_21 , V_65 , - 1 , 1 ) ;
if ( V_29 < 0 ) {
V_82 = V_29 ;
goto V_154;
}
if ( V_17 ) {
if ( ! V_29 )
return 0 ;
#ifdef F_79
V_21 . type = V_140 ;
F_43 ( V_65 ) ;
V_29 = F_37 ( V_109 , V_35 , & V_21 , V_65 , - 1 , 1 ) ;
if ( V_29 < 0 ) {
V_82 = V_29 ;
goto V_154;
}
if ( ! V_29 )
return 0 ;
#endif
goto V_154;
}
V_67 = V_65 -> V_83 [ 0 ] ;
V_71 = F_38 ( V_67 ) ;
while ( 1 ) {
if ( V_65 -> V_84 [ 0 ] >= V_71 ) {
V_29 = F_47 ( V_35 , V_65 ) ;
if ( V_29 < 0 )
V_82 = V_29 ;
if ( V_29 )
goto V_154;
V_67 = V_65 -> V_83 [ 0 ] ;
V_71 = F_38 ( V_67 ) ;
V_150 = 1 ;
}
F_40 ( V_67 , & V_21 , V_65 -> V_84 [ 0 ] ) ;
if ( V_21 . V_22 != V_27 ||
V_21 . type != V_153 )
goto V_154;
V_149 = F_76 ( V_67 , V_65 -> V_84 [ 0 ] ,
struct V_148 ) ;
if ( F_101 ( V_67 , V_149 , V_144 ,
V_131 , V_33 ) ) {
if ( V_150 ) {
F_43 ( V_65 ) ;
goto V_78;
}
V_82 = 0 ;
break;
}
V_65 -> V_84 [ 0 ] ++ ;
}
V_154:
return V_82 ;
}
static T_1 int F_103 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
struct V_64 * V_65 ,
T_2 V_27 , T_2 V_17 ,
T_2 V_144 , T_2 V_131 ,
T_2 V_33 , int V_155 )
{
struct V_68 V_21 ;
struct V_66 * V_67 ;
T_3 V_57 ;
T_3 V_118 ;
int V_29 ;
V_21 . V_22 = V_27 ;
if ( V_17 ) {
V_21 . type = V_152 ;
V_21 . V_33 = V_17 ;
V_57 = sizeof( struct V_156 ) ;
} else {
V_21 . type = V_153 ;
V_21 . V_33 = F_94 ( V_144 ,
V_131 , V_33 ) ;
V_57 = sizeof( struct V_148 ) ;
}
V_29 = F_104 ( V_109 , V_35 , V_65 , & V_21 , V_57 ) ;
if ( V_29 && V_29 != - V_25 )
goto V_154;
V_67 = V_65 -> V_83 [ 0 ] ;
if ( V_17 ) {
struct V_156 * V_149 ;
V_149 = F_76 ( V_67 , V_65 -> V_84 [ 0 ] ,
struct V_156 ) ;
if ( V_29 == 0 ) {
F_105 ( V_67 , V_149 , V_155 ) ;
} else {
V_118 = F_106 ( V_67 , V_149 ) ;
V_118 += V_155 ;
F_105 ( V_67 , V_149 , V_118 ) ;
}
} else {
struct V_148 * V_149 ;
while ( V_29 == - V_25 ) {
V_149 = F_76 ( V_67 , V_65 -> V_84 [ 0 ] ,
struct V_148 ) ;
if ( F_101 ( V_67 , V_149 , V_144 ,
V_131 , V_33 ) )
break;
F_43 ( V_65 ) ;
V_21 . V_33 ++ ;
V_29 = F_104 ( V_109 , V_35 , V_65 , & V_21 ,
V_57 ) ;
if ( V_29 && V_29 != - V_25 )
goto V_154;
V_67 = V_65 -> V_83 [ 0 ] ;
}
V_149 = F_76 ( V_67 , V_65 -> V_84 [ 0 ] ,
struct V_148 ) ;
if ( V_29 == 0 ) {
F_107 ( V_67 , V_149 ,
V_144 ) ;
F_108 ( V_67 , V_149 , V_131 ) ;
F_109 ( V_67 , V_149 , V_33 ) ;
F_110 ( V_67 , V_149 , V_155 ) ;
} else {
V_118 = F_111 ( V_67 , V_149 ) ;
V_118 += V_155 ;
F_110 ( V_67 , V_149 , V_118 ) ;
}
}
F_93 ( V_67 ) ;
V_29 = 0 ;
V_154:
F_43 ( V_65 ) ;
return V_29 ;
}
static T_1 int F_112 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
struct V_64 * V_65 ,
int V_157 )
{
struct V_68 V_21 ;
struct V_148 * V_158 = NULL ;
struct V_156 * V_159 = NULL ;
struct V_66 * V_67 ;
T_3 V_118 = 0 ;
int V_29 = 0 ;
V_67 = V_65 -> V_83 [ 0 ] ;
F_40 ( V_67 , & V_21 , V_65 -> V_84 [ 0 ] ) ;
if ( V_21 . type == V_153 ) {
V_158 = F_76 ( V_67 , V_65 -> V_84 [ 0 ] ,
struct V_148 ) ;
V_118 = F_111 ( V_67 , V_158 ) ;
} else if ( V_21 . type == V_152 ) {
V_159 = F_76 ( V_67 , V_65 -> V_84 [ 0 ] ,
struct V_156 ) ;
V_118 = F_106 ( V_67 , V_159 ) ;
#ifdef F_79
} else if ( V_21 . type == V_140 ) {
struct V_134 * V_135 ;
V_135 = F_76 ( V_67 , V_65 -> V_84 [ 0 ] ,
struct V_134 ) ;
V_118 = F_113 ( V_67 , V_135 ) ;
#endif
} else {
F_81 () ;
}
F_30 ( V_118 < V_157 ) ;
V_118 -= V_157 ;
if ( V_118 == 0 ) {
V_29 = F_114 ( V_109 , V_35 , V_65 ) ;
} else {
if ( V_21 . type == V_153 )
F_110 ( V_67 , V_158 , V_118 ) ;
else if ( V_21 . type == V_152 )
F_105 ( V_67 , V_159 , V_118 ) ;
#ifdef F_79
else {
struct V_134 * V_135 ;
V_135 = F_76 ( V_67 , V_65 -> V_84 [ 0 ] ,
struct V_134 ) ;
F_115 ( V_67 , V_135 , V_118 ) ;
}
#endif
F_93 ( V_67 ) ;
}
return V_29 ;
}
static T_1 T_3 F_116 ( struct V_34 * V_35 ,
struct V_64 * V_65 ,
struct V_160 * V_161 )
{
struct V_68 V_21 ;
struct V_66 * V_67 ;
struct V_148 * V_158 ;
struct V_156 * V_159 ;
T_3 V_118 = 0 ;
V_67 = V_65 -> V_83 [ 0 ] ;
F_40 ( V_67 , & V_21 , V_65 -> V_84 [ 0 ] ) ;
if ( V_161 ) {
if ( F_117 ( V_67 , V_161 ) ==
V_153 ) {
V_158 = (struct V_148 * ) ( & V_161 -> V_33 ) ;
V_118 = F_111 ( V_67 , V_158 ) ;
} else {
V_159 = (struct V_156 * ) ( V_161 + 1 ) ;
V_118 = F_106 ( V_67 , V_159 ) ;
}
} else if ( V_21 . type == V_153 ) {
V_158 = F_76 ( V_67 , V_65 -> V_84 [ 0 ] ,
struct V_148 ) ;
V_118 = F_111 ( V_67 , V_158 ) ;
} else if ( V_21 . type == V_152 ) {
V_159 = F_76 ( V_67 , V_65 -> V_84 [ 0 ] ,
struct V_156 ) ;
V_118 = F_106 ( V_67 , V_159 ) ;
#ifdef F_79
} else if ( V_21 . type == V_140 ) {
struct V_134 * V_135 ;
V_135 = F_76 ( V_67 , V_65 -> V_84 [ 0 ] ,
struct V_134 ) ;
V_118 = F_113 ( V_67 , V_135 ) ;
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
T_2 V_144 )
{
struct V_68 V_21 ;
int V_29 ;
V_21 . V_22 = V_27 ;
if ( V_17 ) {
V_21 . type = V_162 ;
V_21 . V_33 = V_17 ;
} else {
V_21 . type = V_163 ;
V_21 . V_33 = V_144 ;
}
V_29 = F_37 ( V_109 , V_35 , & V_21 , V_65 , - 1 , 1 ) ;
if ( V_29 > 0 )
V_29 = - V_151 ;
#ifdef F_79
if ( V_29 == - V_151 && V_17 ) {
F_43 ( V_65 ) ;
V_21 . type = V_140 ;
V_29 = F_37 ( V_109 , V_35 , & V_21 , V_65 , - 1 , 1 ) ;
if ( V_29 > 0 )
V_29 = - V_151 ;
}
#endif
return V_29 ;
}
static T_1 int F_119 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
struct V_64 * V_65 ,
T_2 V_27 , T_2 V_17 ,
T_2 V_144 )
{
struct V_68 V_21 ;
int V_29 ;
V_21 . V_22 = V_27 ;
if ( V_17 ) {
V_21 . type = V_162 ;
V_21 . V_33 = V_17 ;
} else {
V_21 . type = V_163 ;
V_21 . V_33 = V_144 ;
}
V_29 = F_104 ( V_109 , V_35 , V_65 , & V_21 , 0 ) ;
F_43 ( V_65 ) ;
return V_29 ;
}
static inline int F_120 ( T_2 V_17 , T_2 V_131 )
{
int type ;
if ( V_131 < V_141 ) {
if ( V_17 > 0 )
type = V_162 ;
else
type = V_163 ;
} else {
if ( V_17 > 0 )
type = V_152 ;
else
type = V_153 ;
}
return type ;
}
static int F_41 ( struct V_64 * V_65 , int V_164 ,
struct V_68 * V_21 )
{
for (; V_164 < V_165 ; V_164 ++ ) {
if ( ! V_65 -> V_83 [ V_164 ] )
break;
if ( V_65 -> V_84 [ V_164 ] + 1 >=
F_38 ( V_65 -> V_83 [ V_164 ] ) )
continue;
if ( V_164 == 0 )
F_40 ( V_65 -> V_83 [ V_164 ] , V_21 ,
V_65 -> V_84 [ V_164 ] + 1 ) ;
else
F_121 ( V_65 -> V_83 [ V_164 ] , V_21 ,
V_65 -> V_84 [ V_164 ] + 1 ) ;
return 0 ;
}
return 1 ;
}
static T_5
int F_122 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
struct V_64 * V_65 ,
struct V_160 * * V_166 ,
T_2 V_27 , T_2 V_36 ,
T_2 V_17 , T_2 V_144 ,
T_2 V_131 , T_2 V_33 , int V_167 )
{
struct V_68 V_21 ;
struct V_66 * V_67 ;
struct V_115 * V_116 ;
struct V_160 * V_161 ;
T_2 V_7 ;
T_2 V_117 ;
unsigned long V_168 ;
unsigned long V_31 ;
int V_132 ;
int type ;
int V_169 ;
int V_29 ;
int V_82 = 0 ;
bool V_170 = F_74 ( V_35 -> V_37 ,
V_120 ) ;
V_21 . V_22 = V_27 ;
V_21 . type = V_77 ;
V_21 . V_33 = V_36 ;
V_169 = F_120 ( V_17 , V_131 ) ;
if ( V_167 ) {
V_132 = F_123 ( V_169 ) ;
V_65 -> V_171 = 1 ;
} else
V_132 = - 1 ;
if ( V_170 && V_131 < V_141 ) {
V_21 . type = V_86 ;
V_21 . V_33 = V_131 ;
}
V_78:
V_29 = F_37 ( V_109 , V_35 , & V_21 , V_65 , V_132 , 1 ) ;
if ( V_29 < 0 ) {
V_82 = V_29 ;
goto V_73;
}
if ( V_29 > 0 && V_170 ) {
V_170 = false ;
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
if ( V_29 && ! V_167 ) {
V_82 = - V_151 ;
goto V_73;
} else if ( V_29 ) {
V_82 = - V_172 ;
F_8 ( 1 ) ;
goto V_73;
}
V_67 = V_65 -> V_83 [ 0 ] ;
V_117 = F_75 ( V_67 , V_65 -> V_84 [ 0 ] ) ;
#ifdef F_79
if ( V_117 < sizeof( * V_116 ) ) {
if ( ! V_167 ) {
V_82 = - V_151 ;
goto V_73;
}
V_29 = F_85 ( V_109 , V_35 , V_65 , V_131 ,
V_132 ) ;
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
V_168 = ( unsigned long ) ( V_116 + 1 ) ;
V_31 = ( unsigned long ) V_116 + V_117 ;
if ( V_7 & V_142 && ! V_170 ) {
V_168 += sizeof( struct V_136 ) ;
F_30 ( V_168 > V_31 ) ;
}
V_82 = - V_151 ;
while ( 1 ) {
if ( V_168 >= V_31 ) {
F_8 ( V_168 > V_31 ) ;
break;
}
V_161 = (struct V_160 * ) V_168 ;
type = F_117 ( V_67 , V_161 ) ;
if ( V_169 < type )
break;
if ( V_169 > type ) {
V_168 += F_123 ( type ) ;
continue;
}
if ( type == V_153 ) {
struct V_148 * V_173 ;
V_173 = (struct V_148 * ) ( & V_161 -> V_33 ) ;
if ( F_101 ( V_67 , V_173 , V_144 ,
V_131 , V_33 ) ) {
V_82 = 0 ;
break;
}
if ( F_97 ( V_67 , V_173 ) <
F_94 ( V_144 , V_131 , V_33 ) )
break;
} else {
T_2 V_174 ;
V_174 = F_124 ( V_67 , V_161 ) ;
if ( V_17 > 0 ) {
if ( V_17 == V_174 ) {
V_82 = 0 ;
break;
}
if ( V_174 < V_17 )
break;
} else {
if ( V_144 == V_174 ) {
V_82 = 0 ;
break;
}
if ( V_174 < V_144 )
break;
}
}
V_168 += F_123 ( type ) ;
}
if ( V_82 == - V_151 && V_167 ) {
if ( V_117 + V_132 >=
F_125 ( V_35 ) ) {
V_82 = - V_175 ;
goto V_73;
}
if ( F_41 ( V_65 , 0 , & V_21 ) == 0 &&
V_21 . V_22 == V_27 &&
V_21 . type < V_176 ) {
V_82 = - V_175 ;
goto V_73;
}
}
* V_166 = (struct V_160 * ) V_168 ;
V_73:
if ( V_167 ) {
V_65 -> V_171 = 0 ;
F_126 ( V_65 , 1 ) ;
}
return V_82 ;
}
static T_5
void F_127 ( struct V_34 * V_35 ,
struct V_64 * V_65 ,
struct V_160 * V_161 ,
T_2 V_17 , T_2 V_144 ,
T_2 V_131 , T_2 V_33 , int V_155 ,
struct V_177 * V_127 )
{
struct V_66 * V_67 ;
struct V_115 * V_116 ;
unsigned long V_168 ;
unsigned long V_31 ;
unsigned long V_178 ;
T_2 V_111 ;
int V_57 ;
int type ;
V_67 = V_65 -> V_83 [ 0 ] ;
V_116 = F_76 ( V_67 , V_65 -> V_84 [ 0 ] , struct V_115 ) ;
V_178 = ( unsigned long ) V_161 - ( unsigned long ) V_116 ;
type = F_120 ( V_17 , V_131 ) ;
V_57 = F_123 ( type ) ;
F_87 ( V_35 , V_65 , V_57 ) ;
V_116 = F_76 ( V_67 , V_65 -> V_84 [ 0 ] , struct V_115 ) ;
V_111 = F_77 ( V_67 , V_116 ) ;
V_111 += V_155 ;
F_88 ( V_67 , V_116 , V_111 ) ;
if ( V_127 )
F_128 ( V_127 , V_67 , V_116 ) ;
V_168 = ( unsigned long ) V_116 + V_178 ;
V_31 = ( unsigned long ) V_116 + F_75 ( V_67 , V_65 -> V_84 [ 0 ] ) ;
if ( V_168 < V_31 - V_57 )
F_129 ( V_67 , V_168 + V_57 , V_168 ,
V_31 - V_57 - V_168 ) ;
V_161 = (struct V_160 * ) V_168 ;
F_130 ( V_67 , V_161 , type ) ;
if ( type == V_153 ) {
struct V_148 * V_173 ;
V_173 = (struct V_148 * ) ( & V_161 -> V_33 ) ;
F_107 ( V_67 , V_173 , V_144 ) ;
F_108 ( V_67 , V_173 , V_131 ) ;
F_109 ( V_67 , V_173 , V_33 ) ;
F_110 ( V_67 , V_173 , V_155 ) ;
} else if ( type == V_152 ) {
struct V_156 * V_179 ;
V_179 = (struct V_156 * ) ( V_161 + 1 ) ;
F_105 ( V_67 , V_179 , V_155 ) ;
F_131 ( V_67 , V_161 , V_17 ) ;
} else if ( type == V_162 ) {
F_131 ( V_67 , V_161 , V_17 ) ;
} else {
F_131 ( V_67 , V_161 , V_144 ) ;
}
F_93 ( V_67 ) ;
}
static int F_132 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
struct V_64 * V_65 ,
struct V_160 * * V_166 ,
T_2 V_27 , T_2 V_36 , T_2 V_17 ,
T_2 V_144 , T_2 V_131 , T_2 V_33 )
{
int V_29 ;
V_29 = F_122 ( V_109 , V_35 , V_65 , V_166 ,
V_27 , V_36 , V_17 ,
V_144 , V_131 , V_33 , 0 ) ;
if ( V_29 != - V_151 )
return V_29 ;
F_43 ( V_65 ) ;
* V_166 = NULL ;
if ( V_131 < V_141 ) {
V_29 = F_118 ( V_109 , V_35 , V_65 , V_27 , V_17 ,
V_144 ) ;
} else {
V_29 = F_102 ( V_109 , V_35 , V_65 , V_27 , V_17 ,
V_144 , V_131 , V_33 ) ;
}
return V_29 ;
}
static T_5
void F_133 ( struct V_34 * V_35 ,
struct V_64 * V_65 ,
struct V_160 * V_161 ,
int V_180 ,
struct V_177 * V_127 )
{
struct V_66 * V_67 ;
struct V_115 * V_116 ;
struct V_148 * V_173 = NULL ;
struct V_156 * V_179 = NULL ;
unsigned long V_168 ;
unsigned long V_31 ;
T_3 V_117 ;
int V_57 ;
int type ;
T_2 V_111 ;
V_67 = V_65 -> V_83 [ 0 ] ;
V_116 = F_76 ( V_67 , V_65 -> V_84 [ 0 ] , struct V_115 ) ;
V_111 = F_77 ( V_67 , V_116 ) ;
F_8 ( V_180 < 0 && V_111 + V_180 <= 0 ) ;
V_111 += V_180 ;
F_88 ( V_67 , V_116 , V_111 ) ;
if ( V_127 )
F_128 ( V_127 , V_67 , V_116 ) ;
type = F_117 ( V_67 , V_161 ) ;
if ( type == V_153 ) {
V_173 = (struct V_148 * ) ( & V_161 -> V_33 ) ;
V_111 = F_111 ( V_67 , V_173 ) ;
} else if ( type == V_152 ) {
V_179 = (struct V_156 * ) ( V_161 + 1 ) ;
V_111 = F_106 ( V_67 , V_179 ) ;
} else {
V_111 = 1 ;
F_30 ( V_180 != - 1 ) ;
}
F_30 ( V_180 < 0 && V_111 < - V_180 ) ;
V_111 += V_180 ;
if ( V_111 > 0 ) {
if ( type == V_153 )
F_110 ( V_67 , V_173 , V_111 ) ;
else
F_105 ( V_67 , V_179 , V_111 ) ;
} else {
V_57 = F_123 ( type ) ;
V_117 = F_75 ( V_67 , V_65 -> V_84 [ 0 ] ) ;
V_168 = ( unsigned long ) V_161 ;
V_31 = ( unsigned long ) V_116 + V_117 ;
if ( V_168 + V_57 < V_31 )
F_129 ( V_67 , V_168 , V_168 + V_57 ,
V_31 - V_168 - V_57 ) ;
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
T_2 V_144 , T_2 V_131 ,
T_2 V_33 , int V_155 ,
struct V_177 * V_127 )
{
struct V_160 * V_161 ;
int V_29 ;
V_29 = F_122 ( V_109 , V_35 , V_65 , & V_161 ,
V_27 , V_36 , V_17 ,
V_144 , V_131 , V_33 , 1 ) ;
if ( V_29 == 0 ) {
F_30 ( V_131 < V_141 ) ;
F_133 ( V_35 , V_65 , V_161 ,
V_155 , V_127 ) ;
} else if ( V_29 == - V_151 ) {
F_127 ( V_35 , V_65 , V_161 , V_17 ,
V_144 , V_131 , V_33 ,
V_155 , V_127 ) ;
V_29 = 0 ;
}
return V_29 ;
}
static int F_136 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
struct V_64 * V_65 ,
T_2 V_27 , T_2 V_17 , T_2 V_144 ,
T_2 V_131 , T_2 V_33 , int V_155 )
{
int V_29 ;
if ( V_131 < V_141 ) {
F_30 ( V_155 != 1 ) ;
V_29 = F_119 ( V_109 , V_35 , V_65 , V_27 ,
V_17 , V_144 ) ;
} else {
V_29 = F_103 ( V_109 , V_35 , V_65 , V_27 ,
V_17 , V_144 ,
V_131 , V_33 , V_155 ) ;
}
return V_29 ;
}
static int F_137 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
struct V_64 * V_65 ,
struct V_160 * V_161 ,
int V_157 , int V_181 )
{
int V_29 = 0 ;
F_30 ( ! V_181 && V_157 != 1 ) ;
if ( V_161 ) {
F_133 ( V_35 , V_65 , V_161 ,
- V_157 , NULL ) ;
} else if ( V_181 ) {
V_29 = F_112 ( V_109 , V_35 , V_65 , V_157 ) ;
} else {
V_29 = F_114 ( V_109 , V_35 , V_65 ) ;
}
return V_29 ;
}
static int F_138 ( struct V_182 * V_183 ,
T_2 V_32 , T_2 V_49 )
{
return F_139 ( V_183 , V_32 >> 9 , V_49 >> 9 , V_40 , 0 ) ;
}
static int F_140 ( struct V_34 * V_35 , T_2 V_27 ,
T_2 V_36 , T_2 * V_184 )
{
int V_29 ;
T_2 V_185 = 0 ;
struct V_186 * V_187 = NULL ;
V_29 = F_141 ( V_35 -> V_37 , V_188 ,
V_27 , & V_36 , & V_187 , 0 ) ;
if ( ! V_29 ) {
struct V_189 * V_190 = V_187 -> V_191 ;
int V_43 ;
for ( V_43 = 0 ; V_43 < V_187 -> V_192 ; V_43 ++ , V_190 ++ ) {
if ( ! V_190 -> V_193 -> V_194 )
continue;
V_29 = F_138 ( V_190 -> V_193 -> V_183 ,
V_190 -> V_195 ,
V_190 -> V_196 ) ;
if ( ! V_29 )
V_185 += V_190 -> V_196 ;
else if ( V_29 != - V_197 )
break;
V_29 = 0 ;
}
F_9 ( V_187 ) ;
}
if ( V_184 )
* V_184 = V_185 ;
if ( V_29 == - V_197 )
V_29 = 0 ;
return V_29 ;
}
int F_142 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
T_2 V_27 , T_2 V_36 , T_2 V_17 ,
T_2 V_144 , T_2 V_131 , T_2 V_33 , int V_198 )
{
int V_29 ;
struct V_12 * V_37 = V_35 -> V_37 ;
F_30 ( V_131 < V_141 &&
V_144 == V_199 ) ;
if ( V_131 < V_141 ) {
V_29 = F_143 ( V_37 , V_109 , V_27 ,
V_36 ,
V_17 , V_144 , ( int ) V_131 ,
V_200 , NULL , V_198 ) ;
} else {
V_29 = F_144 ( V_37 , V_109 , V_27 ,
V_36 ,
V_17 , V_144 , V_131 , V_33 ,
V_200 , NULL , V_198 ) ;
}
return V_29 ;
}
static int F_145 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
T_2 V_27 , T_2 V_36 ,
T_2 V_17 , T_2 V_144 ,
T_2 V_131 , T_2 V_33 , int V_155 ,
struct V_177 * V_127 )
{
struct V_64 * V_65 ;
struct V_66 * V_67 ;
struct V_115 * V_133 ;
T_2 V_111 ;
int V_29 ;
int V_82 = 0 ;
V_65 = F_33 () ;
if ( ! V_65 )
return - V_72 ;
V_65 -> V_76 = 1 ;
V_65 -> V_201 = 1 ;
V_29 = F_135 ( V_109 , V_35 -> V_37 -> V_63 ,
V_65 , V_27 , V_36 , V_17 ,
V_144 , V_131 , V_33 ,
V_155 , V_127 ) ;
if ( V_29 == 0 )
goto V_73;
if ( V_29 != - V_175 ) {
V_82 = V_29 ;
goto V_73;
}
V_67 = V_65 -> V_83 [ 0 ] ;
V_133 = F_76 ( V_67 , V_65 -> V_84 [ 0 ] , struct V_115 ) ;
V_111 = F_77 ( V_67 , V_133 ) ;
F_88 ( V_67 , V_133 , V_111 + V_155 ) ;
if ( V_127 )
F_128 ( V_127 , V_67 , V_133 ) ;
F_93 ( V_67 ) ;
F_43 ( V_65 ) ;
V_65 -> V_76 = 1 ;
V_65 -> V_201 = 1 ;
V_29 = F_136 ( V_109 , V_35 -> V_37 -> V_63 ,
V_65 , V_27 , V_17 , V_144 ,
V_131 , V_33 , V_155 ) ;
if ( V_29 )
F_146 ( V_109 , V_35 , V_29 ) ;
V_73:
F_49 ( V_65 ) ;
return V_82 ;
}
static int F_147 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
struct V_202 * V_126 ,
struct V_177 * V_127 ,
int V_203 )
{
int V_29 = 0 ;
struct V_204 * V_149 ;
struct V_68 V_205 ;
T_2 V_17 = 0 ;
T_2 V_206 = 0 ;
T_2 V_7 = 0 ;
V_205 . V_22 = V_126 -> V_27 ;
V_205 . V_33 = V_126 -> V_36 ;
V_205 . type = V_77 ;
V_149 = F_148 ( V_126 ) ;
F_149 ( V_126 , V_149 , V_126 -> V_207 ) ;
if ( V_126 -> type == V_152 )
V_17 = V_149 -> V_17 ;
else
V_206 = V_149 -> V_35 ;
if ( V_126 -> V_207 == V_200 && V_203 ) {
if ( V_127 )
V_7 |= V_127 -> V_129 ;
V_29 = F_150 ( V_109 , V_35 ,
V_17 , V_206 , V_7 ,
V_149 -> V_22 , V_149 -> V_33 ,
& V_205 , V_126 -> V_130 ) ;
} else if ( V_126 -> V_207 == V_200 ) {
V_29 = F_145 ( V_109 , V_35 , V_126 -> V_27 ,
V_126 -> V_36 , V_17 ,
V_206 , V_149 -> V_22 ,
V_149 -> V_33 , V_126 -> V_130 ,
V_127 ) ;
} else if ( V_126 -> V_207 == V_208 ) {
V_29 = F_151 ( V_109 , V_35 , V_126 -> V_27 ,
V_126 -> V_36 , V_17 ,
V_206 , V_149 -> V_22 ,
V_149 -> V_33 , V_126 -> V_130 ,
V_127 ) ;
} else {
F_81 () ;
}
return V_29 ;
}
static void F_128 ( struct V_177 * V_127 ,
struct V_66 * V_67 ,
struct V_115 * V_116 )
{
T_2 V_7 = F_78 ( V_67 , V_116 ) ;
if ( V_127 -> V_128 ) {
V_7 |= V_127 -> V_129 ;
F_90 ( V_67 , V_116 , V_7 ) ;
}
if ( V_127 -> V_209 ) {
struct V_136 * V_137 ;
F_30 ( ! ( V_7 & V_142 ) ) ;
V_137 = (struct V_136 * ) ( V_116 + 1 ) ;
F_152 ( V_67 , V_137 , & V_127 -> V_21 ) ;
}
}
static int F_153 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
struct V_202 * V_126 ,
struct V_177 * V_127 )
{
struct V_68 V_21 ;
struct V_64 * V_65 ;
struct V_115 * V_116 ;
struct V_66 * V_67 ;
T_3 V_117 ;
int V_29 ;
int V_82 = 0 ;
int V_110 = ! V_127 -> V_181 ;
if ( V_109 -> V_210 )
return 0 ;
if ( V_110 && ! F_74 ( V_35 -> V_37 , V_120 ) )
V_110 = 0 ;
V_65 = F_33 () ;
if ( ! V_65 )
return - V_72 ;
V_21 . V_22 = V_126 -> V_27 ;
if ( V_110 ) {
V_21 . type = V_86 ;
V_21 . V_33 = V_127 -> V_164 ;
} else {
V_21 . type = V_77 ;
V_21 . V_33 = V_126 -> V_36 ;
}
V_78:
V_65 -> V_76 = 1 ;
V_65 -> V_201 = 1 ;
V_29 = F_37 ( V_109 , V_35 -> V_37 -> V_63 , & V_21 ,
V_65 , 0 , 1 ) ;
if ( V_29 < 0 ) {
V_82 = V_29 ;
goto V_73;
}
if ( V_29 > 0 ) {
if ( V_110 ) {
F_43 ( V_65 ) ;
V_110 = 0 ;
V_21 . V_33 = V_126 -> V_36 ;
V_21 . type = V_77 ;
goto V_78;
}
V_82 = - V_172 ;
goto V_73;
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
F_128 ( V_127 , V_67 , V_116 ) ;
F_93 ( V_67 ) ;
V_73:
F_49 ( V_65 ) ;
return V_82 ;
}
static int F_154 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
struct V_202 * V_126 ,
struct V_177 * V_127 ,
int V_203 )
{
int V_29 = 0 ;
struct V_211 * V_149 ;
struct V_68 V_205 ;
T_2 V_17 = 0 ;
T_2 V_206 = 0 ;
bool V_170 = F_74 ( V_35 -> V_37 ,
V_120 ) ;
V_149 = F_155 ( V_126 ) ;
F_156 ( V_126 , V_149 , V_126 -> V_207 ) ;
if ( V_126 -> type == V_162 )
V_17 = V_149 -> V_17 ;
else
V_206 = V_149 -> V_35 ;
V_205 . V_22 = V_126 -> V_27 ;
if ( V_170 ) {
V_205 . V_33 = V_149 -> V_164 ;
V_205 . type = V_86 ;
} else {
V_205 . V_33 = V_126 -> V_36 ;
V_205 . type = V_77 ;
}
F_30 ( V_126 -> V_130 != 1 ) ;
if ( V_126 -> V_207 == V_200 && V_203 ) {
F_30 ( ! V_127 || ! V_127 -> V_128 ) ;
V_29 = F_157 ( V_109 , V_35 ,
V_17 , V_206 ,
V_127 -> V_129 ,
& V_127 -> V_21 ,
V_149 -> V_164 , & V_205 ) ;
} else if ( V_126 -> V_207 == V_200 ) {
V_29 = F_145 ( V_109 , V_35 , V_126 -> V_27 ,
V_126 -> V_36 , V_17 , V_206 ,
V_149 -> V_164 , 0 , 1 , V_127 ) ;
} else if ( V_126 -> V_207 == V_208 ) {
V_29 = F_151 ( V_109 , V_35 , V_126 -> V_27 ,
V_126 -> V_36 , V_17 , V_206 ,
V_149 -> V_164 , 0 , 1 , V_127 ) ;
} else {
F_81 () ;
}
return V_29 ;
}
static int F_158 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
struct V_202 * V_126 ,
struct V_177 * V_127 ,
int V_203 )
{
int V_29 = 0 ;
if ( V_109 -> V_210 )
return 0 ;
if ( F_159 ( V_126 ) ) {
struct V_112 * V_103 ;
F_30 ( V_127 ) ;
V_103 = F_160 ( V_126 ) ;
F_161 ( V_126 , V_103 , V_126 -> V_207 ) ;
if ( V_203 ) {
F_162 ( V_35 , V_126 -> V_27 ,
V_126 -> V_36 , 1 ) ;
if ( V_103 -> V_181 ) {
V_29 = F_163 ( V_109 , V_35 ,
V_126 -> V_27 ,
V_126 -> V_36 ) ;
}
}
return V_29 ;
}
if ( V_126 -> type == V_163 ||
V_126 -> type == V_162 )
V_29 = F_154 ( V_109 , V_35 , V_126 , V_127 ,
V_203 ) ;
else if ( V_126 -> type == V_153 ||
V_126 -> type == V_152 )
V_29 = F_147 ( V_109 , V_35 , V_126 , V_127 ,
V_203 ) ;
else
F_81 () ;
return V_29 ;
}
T_1 int F_164 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
struct V_102 * V_212 )
{
struct V_113 * V_114 ;
struct V_202 * V_149 ;
struct V_112 * V_213 = NULL ;
struct V_177 * V_127 ;
struct V_12 * V_37 = V_35 -> V_37 ;
int V_29 ;
int V_8 = 0 ;
int V_214 = 0 ;
V_114 = & V_109 -> V_125 -> V_114 ;
while ( 1 ) {
if ( ! V_213 ) {
if ( F_165 ( V_212 ) )
break;
V_213 = F_166 ( V_212 -> V_81 ,
struct V_112 , V_212 ) ;
V_29 = F_167 ( V_109 , V_213 ) ;
if ( V_29 == - V_175 ) {
V_213 = NULL ;
V_8 ++ ;
continue;
}
}
F_168 ( V_109 , V_37 , V_114 ,
V_213 ) ;
V_149 = F_169 ( V_213 ) ;
if ( V_149 && V_149 -> V_215 &&
F_170 ( V_37 , V_114 , V_149 -> V_215 ) ) {
F_171 ( & V_213 -> V_212 ) ;
F_172 ( V_213 ) ;
V_213 = NULL ;
V_114 -> V_216 ++ ;
F_13 ( & V_114 -> V_52 ) ;
F_46 () ;
F_11 ( & V_114 -> V_52 ) ;
continue;
}
V_214 = V_213 -> V_214 ;
V_213 -> V_214 = 0 ;
V_127 = V_213 -> V_127 ;
V_213 -> V_127 = NULL ;
if ( ! V_149 ) {
V_149 = & V_213 -> V_126 ;
if ( V_127 && V_214 ) {
F_173 ( V_127 ) ;
V_127 = NULL ;
}
if ( V_127 ) {
F_13 ( & V_114 -> V_52 ) ;
V_29 = F_153 ( V_109 , V_35 ,
V_149 , V_127 ) ;
F_173 ( V_127 ) ;
if ( V_29 ) {
F_174 ( V_37 , L_1 , V_29 ) ;
F_11 ( & V_114 -> V_52 ) ;
F_172 ( V_213 ) ;
return V_29 ;
}
goto V_81;
}
}
V_149 -> V_217 = 0 ;
F_175 ( & V_149 -> V_15 , & V_114 -> V_35 ) ;
V_114 -> V_218 -- ;
if ( ! F_159 ( V_149 ) ) {
switch ( V_149 -> V_207 ) {
case V_200 :
case V_219 :
V_213 -> V_126 . V_130 -= V_149 -> V_130 ;
break;
case V_208 :
V_213 -> V_126 . V_130 += V_149 -> V_130 ;
break;
default:
F_8 ( 1 ) ;
}
} else {
F_171 ( & V_213 -> V_212 ) ;
}
F_13 ( & V_114 -> V_52 ) ;
V_29 = F_158 ( V_109 , V_35 , V_149 , V_127 ,
V_214 ) ;
F_173 ( V_127 ) ;
if ( V_29 ) {
F_172 ( V_213 ) ;
F_84 ( V_149 ) ;
F_174 ( V_37 , L_2 , V_29 ) ;
F_11 ( & V_114 -> V_52 ) ;
return V_29 ;
}
if ( F_159 ( V_149 ) ) {
F_172 ( V_213 ) ;
V_213 = NULL ;
}
F_84 ( V_149 ) ;
V_8 ++ ;
V_81:
F_46 () ;
F_11 ( & V_114 -> V_52 ) ;
}
return V_8 ;
}
static T_2 F_176 ( struct V_220 * V_35 )
{
struct V_15 * V_30 = V_35 -> V_15 ;
struct V_202 * V_221 ;
int V_222 = 1 ;
T_2 V_223 ;
T_2 V_224 = 0 , V_70 = 0 ;
V_30 = F_177 ( V_35 ) ;
if ( V_30 ) {
V_221 = F_12 ( V_30 , struct V_202 , V_15 ) ;
V_224 = V_221 -> V_27 ;
}
V_30 = F_178 ( V_35 ) ;
if ( V_30 ) {
V_221 = F_12 ( V_30 , struct V_202 , V_15 ) ;
V_70 = V_221 -> V_27 ;
}
V_30 = V_35 -> V_15 ;
while ( V_30 ) {
V_221 = F_12 ( V_30 , struct V_202 , V_15 ) ;
F_8 ( ! V_221 -> V_217 ) ;
V_223 = V_221 -> V_27 ;
if ( V_222 )
V_30 = V_30 -> V_23 ;
else
V_30 = V_30 -> V_24 ;
V_222 = 1 - V_222 ;
}
return V_223 ;
}
int F_179 ( struct V_108 * V_109 ,
struct V_12 * V_37 )
{
struct V_225 * V_225 ;
int V_29 = 0 ;
if ( F_165 ( & V_109 -> V_226 ) !=
! V_109 -> V_227 . V_215 ) {
F_180 ( V_37 ,
L_3 ,
F_165 ( & V_109 -> V_226 ) ? L_4 : L_5 ,
( T_3 ) ( V_109 -> V_227 . V_215 >> 32 ) ,
( T_3 ) V_109 -> V_227 . V_215 ) ;
F_81 () ;
}
if ( ! V_109 -> V_227 . V_215 )
return 0 ;
while ( ! F_165 ( & V_109 -> V_226 ) ) {
V_225 = F_181 ( & V_109 -> V_226 ,
struct V_225 , V_91 ) ;
F_182 ( & V_225 -> V_91 ) ;
if ( ! V_29 )
V_29 = F_183 (
V_109 , V_37 , V_225 -> V_126 ,
V_225 -> V_127 ) ;
F_9 ( V_225 ) ;
}
F_184 ( V_37 , & V_109 -> V_227 ) ;
return V_29 ;
}
static int F_185 ( struct V_113 * V_114 , int V_215 ,
int V_8 )
{
int V_228 = F_186 ( & V_114 -> V_229 ) ;
if ( V_228 < V_215 || V_228 >= V_215 + V_8 )
return 1 ;
return 0 ;
}
static inline T_2 F_187 ( struct V_34 * V_35 , T_2 V_230 )
{
T_2 V_36 ;
V_36 = V_230 * ( sizeof( struct V_115 ) +
sizeof( struct V_160 ) ) ;
if ( ! F_74 ( V_35 -> V_37 , V_120 ) )
V_36 += V_230 * sizeof( struct V_136 ) ;
return F_188 ( V_36 , F_189 ( V_35 ) ) ;
}
int F_190 ( struct V_108 * V_109 ,
struct V_34 * V_35 )
{
struct V_231 * V_232 ;
T_2 V_233 = V_109 -> V_125 -> V_114 . V_216 ;
T_2 V_36 ;
int V_29 = 0 ;
V_36 = F_191 ( V_35 , 1 ) ;
V_233 = F_187 ( V_35 , V_233 ) ;
if ( V_233 > 1 )
V_36 += ( V_233 - 1 ) * V_35 -> V_88 ;
V_36 <<= 1 ;
V_232 = & V_35 -> V_37 -> V_234 ;
if ( V_232 -> V_104 -> V_107 )
V_36 <<= 1 ;
F_11 ( & V_232 -> V_52 ) ;
if ( V_232 -> V_10 <= V_36 )
V_29 = 1 ;
F_13 ( & V_232 -> V_52 ) ;
return V_29 ;
}
int F_192 ( struct V_108 * V_109 ,
struct V_34 * V_35 , unsigned long V_8 )
{
struct V_15 * V_126 ;
struct V_113 * V_114 ;
struct V_202 * V_149 ;
struct V_102 V_212 ;
int V_29 ;
T_2 V_235 ;
int V_236 = V_8 == ( unsigned long ) - 1 ;
int V_237 = 0 ;
int V_238 ;
if ( V_109 -> V_210 )
return 0 ;
if ( V_35 == V_35 -> V_37 -> V_63 )
V_35 = V_35 -> V_37 -> V_87 ;
F_179 ( V_109 , V_35 -> V_37 ) ;
V_114 = & V_109 -> V_125 -> V_114 ;
F_53 ( & V_212 ) ;
if ( V_8 == 0 ) {
V_8 = V_114 -> V_218 * 2 ;
V_237 = 1 ;
}
if ( ! V_236 && ! V_237 ) {
int V_239 ;
int V_215 = F_186 ( & V_114 -> V_229 ) ;
V_85:
V_239 = F_193 ( & V_114 -> V_240 , 0 , 1 ) ;
if ( V_239 ) {
F_51 ( V_241 ) ;
if ( V_114 -> V_242 ||
! F_190 ( V_109 , V_35 ) )
return 0 ;
F_57 ( & V_114 -> V_89 , & V_241 ,
V_94 ) ;
V_239 = F_193 ( & V_114 -> V_240 , 0 , 1 ) ;
if ( V_239 ) {
F_58 () ;
F_59 ( & V_114 -> V_89 , & V_241 ) ;
if ( ! F_185 ( V_114 , V_215 , 256 ) )
goto V_85;
else
return 0 ;
} else {
F_59 ( & V_114 -> V_89 , & V_241 ) ;
goto V_78;
}
}
} else {
F_5 ( & V_114 -> V_240 ) ;
}
V_78:
V_238 = 0 ;
F_11 ( & V_114 -> V_52 ) ;
#ifdef F_194
V_114 -> V_243 = F_176 ( & V_114 -> V_35 ) ;
#endif
while ( 1 ) {
if ( ! ( V_236 || V_237 ) &&
! F_190 ( V_109 , V_35 ) )
break;
V_235 = V_114 -> V_243 ;
V_29 = F_195 ( V_109 , & V_212 ,
V_114 -> V_243 ) ;
if ( V_29 )
break;
V_29 = F_164 ( V_109 , V_35 , & V_212 ) ;
if ( V_29 < 0 ) {
F_196 ( & V_212 ) ;
F_13 ( & V_114 -> V_52 ) ;
F_146 ( V_109 , V_35 , V_29 ) ;
F_197 ( & V_114 -> V_240 ) ;
F_48 ( & V_114 -> V_89 ) ;
return V_29 ;
}
F_198 ( V_29 , & V_114 -> V_229 ) ;
V_8 -= F_24 (unsigned long, ret, count) ;
if ( V_8 == 0 )
break;
if ( V_235 >= V_114 -> V_243 ) {
if ( V_238 == 0 ) {
V_238 = 1 ;
} else {
F_30 ( V_236 ) ;
break;
}
}
if ( V_29 ) {
V_238 = 0 ;
}
}
if ( V_236 ) {
if ( ! F_165 ( & V_109 -> V_244 ) ) {
F_13 ( & V_114 -> V_52 ) ;
F_199 ( V_109 , V_35 ) ;
F_11 ( & V_114 -> V_52 ) ;
}
V_126 = F_177 ( & V_114 -> V_35 ) ;
if ( ! V_126 )
goto V_73;
V_8 = ( unsigned long ) - 1 ;
while ( V_126 ) {
V_149 = F_12 ( V_126 , struct V_202 ,
V_15 ) ;
if ( F_159 ( V_149 ) ) {
struct V_112 * V_103 ;
V_103 = F_160 ( V_149 ) ;
F_5 ( & V_149 -> V_111 ) ;
F_13 ( & V_114 -> V_52 ) ;
F_35 ( & V_103 -> V_79 ) ;
F_45 ( & V_103 -> V_79 ) ;
F_84 ( V_149 ) ;
F_46 () ;
goto V_78;
}
V_126 = F_200 ( V_126 ) ;
}
F_13 ( & V_114 -> V_52 ) ;
F_201 ( 1 ) ;
goto V_78;
}
V_73:
F_197 ( & V_114 -> V_240 ) ;
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
int V_164 , int V_181 )
{
struct V_177 * V_127 ;
int V_29 ;
V_127 = F_205 () ;
if ( ! V_127 )
return - V_72 ;
V_127 -> V_129 = V_7 ;
V_127 -> V_128 = 1 ;
V_127 -> V_209 = 0 ;
V_127 -> V_181 = V_181 ? 1 : 0 ;
V_127 -> V_164 = V_164 ;
V_29 = F_206 ( V_35 -> V_37 , V_109 , V_27 ,
V_36 , V_127 ) ;
if ( V_29 )
F_173 ( V_127 ) ;
return V_29 ;
}
static T_1 int F_207 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
struct V_64 * V_65 ,
T_2 V_22 , T_2 V_33 , T_2 V_27 )
{
struct V_112 * V_103 ;
struct V_202 * V_149 ;
struct V_204 * V_245 ;
struct V_113 * V_114 ;
struct V_15 * V_126 ;
int V_29 = 0 ;
V_29 = - V_151 ;
V_114 = & V_109 -> V_125 -> V_114 ;
F_11 ( & V_114 -> V_52 ) ;
V_103 = F_82 ( V_109 , V_27 ) ;
if ( ! V_103 )
goto V_73;
if ( ! F_83 ( & V_103 -> V_79 ) ) {
F_5 ( & V_103 -> V_126 . V_111 ) ;
F_13 ( & V_114 -> V_52 ) ;
F_43 ( V_65 ) ;
F_35 ( & V_103 -> V_79 ) ;
F_45 ( & V_103 -> V_79 ) ;
F_84 ( & V_103 -> V_126 ) ;
return - V_175 ;
}
V_126 = F_208 ( & V_103 -> V_126 . V_15 ) ;
if ( ! V_126 )
goto V_246;
V_149 = F_12 ( V_126 , struct V_202 , V_15 ) ;
if ( V_149 -> V_27 != V_27 )
goto V_246;
V_29 = 1 ;
if ( V_149 -> type != V_153 )
goto V_246;
V_245 = F_148 ( V_149 ) ;
V_126 = F_208 ( V_126 ) ;
if ( V_126 ) {
int V_215 = V_149 -> V_215 ;
V_149 = F_12 ( V_126 , struct V_202 , V_15 ) ;
if ( V_149 -> V_27 == V_27 && V_149 -> V_215 == V_215 )
goto V_246;
}
if ( V_245 -> V_35 != V_35 -> V_247 . V_22 ||
V_245 -> V_22 != V_22 || V_245 -> V_33 != V_33 )
goto V_246;
V_29 = 0 ;
V_246:
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
struct V_148 * V_149 ;
struct V_160 * V_161 ;
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
V_29 = - V_151 ;
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
F_8 ( V_117 != sizeof( struct V_122 ) ) ;
goto V_73;
}
#endif
V_116 = F_76 ( V_67 , V_65 -> V_84 [ 0 ] , struct V_115 ) ;
if ( V_117 != sizeof( * V_116 ) +
F_123 ( V_153 ) )
goto V_73;
if ( F_210 ( V_67 , V_116 ) <=
F_211 ( & V_35 -> V_248 ) )
goto V_73;
V_161 = (struct V_160 * ) ( V_116 + 1 ) ;
if ( F_117 ( V_67 , V_161 ) !=
V_153 )
goto V_73;
V_149 = (struct V_148 * ) ( & V_161 -> V_33 ) ;
if ( F_77 ( V_67 , V_116 ) !=
F_111 ( V_67 , V_149 ) ||
F_98 ( V_67 , V_149 ) !=
V_35 -> V_247 . V_22 ||
F_99 ( V_67 , V_149 ) != V_22 ||
F_100 ( V_67 , V_149 ) != V_33 )
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
int V_249 ;
V_65 = F_33 () ;
if ( ! V_65 )
return - V_151 ;
do {
V_29 = F_209 ( V_109 , V_35 , V_65 , V_22 ,
V_33 , V_27 ) ;
if ( V_29 && V_29 != - V_151 )
goto V_73;
V_249 = F_207 ( V_109 , V_35 , V_65 , V_22 ,
V_33 , V_27 ) ;
} while ( V_249 == - V_175 );
if ( V_249 && V_249 != - V_151 ) {
V_29 = V_249 ;
goto V_73;
}
if ( V_29 != - V_151 || V_249 != - V_151 )
V_29 = 0 ;
V_73:
F_49 ( V_65 ) ;
if ( V_35 -> V_247 . V_22 == V_250 )
F_8 ( V_29 > 0 ) ;
return V_29 ;
}
static int F_213 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
struct V_66 * V_251 ,
int V_252 , int V_253 , int V_198 )
{
T_2 V_27 ;
T_2 V_36 ;
T_2 V_17 ;
T_2 V_206 ;
T_3 V_71 ;
struct V_68 V_21 ;
struct V_254 * V_255 ;
int V_43 ;
int V_164 ;
int V_29 = 0 ;
int (* F_214)( struct V_108 * , struct V_34 * ,
T_2 , T_2 , T_2 , T_2 , T_2 , T_2 , int );
V_206 = F_215 ( V_251 ) ;
V_71 = F_38 ( V_251 ) ;
V_164 = F_216 ( V_251 ) ;
if ( ! V_35 -> V_256 && V_164 == 0 )
return 0 ;
if ( V_253 )
F_214 = F_142 ;
else
F_214 = V_257 ;
if ( V_252 )
V_17 = V_251 -> V_32 ;
else
V_17 = 0 ;
for ( V_43 = 0 ; V_43 < V_71 ; V_43 ++ ) {
if ( V_164 == 0 ) {
F_40 ( V_251 , & V_21 , V_43 ) ;
if ( F_217 ( & V_21 ) != V_258 )
continue;
V_255 = F_76 ( V_251 , V_43 ,
struct V_254 ) ;
if ( F_218 ( V_251 , V_255 ) ==
V_259 )
continue;
V_27 = F_219 ( V_251 , V_255 ) ;
if ( V_27 == 0 )
continue;
V_36 = F_220 ( V_251 , V_255 ) ;
V_21 . V_33 -= F_221 ( V_251 , V_255 ) ;
V_29 = F_214 ( V_109 , V_35 , V_27 , V_36 ,
V_17 , V_206 , V_21 . V_22 ,
V_21 . V_33 , V_198 ) ;
if ( V_29 )
goto V_154;
} else {
V_27 = F_222 ( V_251 , V_43 ) ;
V_36 = F_223 ( V_35 , V_164 - 1 ) ;
V_29 = F_214 ( V_109 , V_35 , V_27 , V_36 ,
V_17 , V_206 , V_164 - 1 , 0 ,
V_198 ) ;
if ( V_29 )
goto V_154;
}
}
return 0 ;
V_154:
return V_29 ;
}
int F_224 ( struct V_108 * V_109 , struct V_34 * V_35 ,
struct V_66 * V_251 , int V_252 , int V_198 )
{
return F_213 ( V_109 , V_35 , V_251 , V_252 , 1 , V_198 ) ;
}
int F_225 ( struct V_108 * V_109 , struct V_34 * V_35 ,
struct V_66 * V_251 , int V_252 , int V_198 )
{
return F_213 ( V_109 , V_35 , V_251 , V_252 , 0 , V_198 ) ;
}
static int F_226 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
struct V_64 * V_65 ,
struct V_1 * V_2 )
{
int V_29 ;
struct V_34 * V_63 = V_35 -> V_37 -> V_63 ;
unsigned long V_137 ;
struct V_66 * V_67 ;
V_29 = F_37 ( V_109 , V_63 , & V_2 -> V_21 , V_65 , 0 , 1 ) ;
if ( V_29 < 0 )
goto V_154;
F_30 ( V_29 ) ;
V_67 = V_65 -> V_83 [ 0 ] ;
V_137 = F_227 ( V_67 , V_65 -> V_84 [ 0 ] ) ;
F_228 ( V_67 , & V_2 -> V_133 , V_137 , sizeof( V_2 -> V_133 ) ) ;
F_93 ( V_67 ) ;
F_43 ( V_65 ) ;
V_154:
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
struct V_15 * V_126 ;
F_11 ( & V_35 -> V_37 -> V_18 ) ;
V_126 = F_200 ( & V_2 -> V_20 ) ;
F_6 ( V_2 ) ;
if ( V_126 ) {
V_2 = F_12 ( V_126 , struct V_1 ,
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
V_260 = F_231 ( V_35 , V_14 , V_65 ) ;
if ( F_232 ( V_260 ) && F_233 ( V_260 ) != - V_151 ) {
V_29 = F_233 ( V_260 ) ;
F_43 ( V_65 ) ;
goto V_73;
}
if ( F_232 ( V_260 ) ) {
F_30 ( V_265 ) ;
V_265 ++ ;
if ( V_14 -> V_268 )
goto V_121;
V_29 = F_234 ( V_35 , V_109 , V_14 , V_65 ) ;
if ( V_29 )
goto V_121;
goto V_78;
}
if ( V_14 -> V_269 == V_109 -> V_270 &&
F_235 ( V_260 ) ) {
V_262 = V_271 ;
goto V_272;
}
F_236 ( V_260 ) -> V_273 = 0 ;
V_29 = F_237 ( V_109 , V_35 , V_260 ) ;
F_8 ( V_29 ) ;
if ( F_235 ( V_260 ) > 0 ) {
V_29 = F_238 ( V_35 ,
& V_35 -> V_37 -> V_234 ) ;
if ( V_29 )
goto V_272;
V_29 = F_239 ( V_35 , V_109 , V_65 ,
V_260 ) ;
if ( V_29 )
goto V_272;
}
F_11 ( & V_14 -> V_52 ) ;
if ( V_14 -> V_3 != V_4 ||
! F_240 ( V_35 , V_274 ) ) {
V_262 = V_267 ;
F_13 ( & V_14 -> V_52 ) ;
goto V_272;
}
F_13 ( & V_14 -> V_52 ) ;
V_264 = ( int ) F_188 ( V_14 -> V_21 . V_33 , 256 * 1024 * 1024 ) ;
if ( ! V_264 )
V_264 = 1 ;
V_264 *= 16 ;
V_264 *= V_275 ;
V_29 = F_241 ( V_260 , V_264 ) ;
if ( V_29 )
goto V_272;
V_29 = F_242 ( V_260 , V_109 , 0 , 0 , V_264 ,
V_264 , V_264 ,
& V_261 ) ;
if ( ! V_29 )
V_262 = V_271 ;
F_243 ( V_260 , V_264 ) ;
V_272:
F_244 ( V_260 ) ;
V_121:
F_43 ( V_65 ) ;
V_73:
F_11 ( & V_14 -> V_52 ) ;
if ( ! V_29 && V_262 == V_271 )
V_14 -> V_269 = V_109 -> V_270 ;
V_14 -> V_266 = V_262 ;
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
if ( V_2 -> V_266 == V_276 )
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
if ( V_2 -> V_266 == V_276 ) {
F_6 ( V_2 ) ;
goto V_78;
}
if ( V_2 -> V_277 )
break;
V_2 = F_229 ( V_35 , V_2 ) ;
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
V_82 = F_226 ( V_109 , V_35 , V_65 , V_2 ) ;
if ( V_82 )
goto V_73;
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
if ( V_2 -> V_277 ) {
F_6 ( V_2 ) ;
goto V_78;
}
if ( V_2 -> V_266 == V_278 )
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
if ( ! V_82 && V_2 -> V_266 == V_278 )
V_2 -> V_266 = V_267 ;
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
int V_279 = 0 ;
V_14 = F_66 ( V_35 -> V_37 , V_27 ) ;
if ( ! V_14 || V_14 -> V_268 )
V_279 = 1 ;
if ( V_14 )
F_6 ( V_14 ) ;
return V_279 ;
}
static int F_248 ( struct V_12 * V_13 , T_2 V_7 ,
T_2 V_280 , T_2 V_281 ,
struct V_101 * * V_104 )
{
struct V_101 * V_105 ;
int V_43 ;
int V_282 ;
int V_29 ;
if ( V_7 & ( V_283 | V_284 |
V_285 ) )
V_282 = 2 ;
else
V_282 = 1 ;
V_105 = F_67 ( V_13 , V_7 ) ;
if ( V_105 ) {
F_11 ( & V_105 -> V_52 ) ;
V_105 -> V_280 += V_280 ;
V_105 -> V_286 += V_280 * V_282 ;
V_105 -> V_281 += V_281 ;
V_105 -> V_287 += V_281 * V_282 ;
V_105 -> V_107 = 0 ;
F_13 ( & V_105 -> V_52 ) ;
* V_104 = V_105 ;
return 0 ;
}
V_105 = F_52 ( sizeof( * V_105 ) , V_40 ) ;
if ( ! V_105 )
return - V_72 ;
V_29 = F_249 ( & V_105 -> V_288 , 0 ) ;
if ( V_29 ) {
F_9 ( V_105 ) ;
return V_29 ;
}
for ( V_43 = 0 ; V_43 < V_289 ; V_43 ++ )
F_53 ( & V_105 -> V_290 [ V_43 ] ) ;
F_250 ( & V_105 -> V_291 ) ;
F_251 ( & V_105 -> V_52 ) ;
V_105 -> V_7 = V_7 & V_106 ;
V_105 -> V_280 = V_280 ;
V_105 -> V_286 = V_280 * V_282 ;
V_105 -> V_281 = V_281 ;
V_105 -> V_287 = V_281 * V_282 ;
V_105 -> V_292 = 0 ;
V_105 -> V_293 = 0 ;
V_105 -> V_294 = 0 ;
V_105 -> V_295 = 0 ;
V_105 -> V_107 = 0 ;
V_105 -> V_296 = V_297 ;
V_105 -> V_298 = 0 ;
V_105 -> V_299 = 0 ;
F_55 ( & V_105 -> V_89 ) ;
* V_104 = V_105 ;
F_252 ( & V_105 -> V_91 , & V_13 -> V_104 ) ;
if ( V_7 & V_300 )
V_13 -> V_301 = V_105 ;
return 0 ;
}
static void F_253 ( struct V_12 * V_37 , T_2 V_7 )
{
T_2 V_302 = F_254 ( V_7 ) &
V_303 ;
F_255 ( & V_37 -> V_304 ) ;
if ( V_7 & V_300 )
V_37 -> V_305 |= V_302 ;
if ( V_7 & V_306 )
V_37 -> V_307 |= V_302 ;
if ( V_7 & V_308 )
V_37 -> V_309 |= V_302 ;
F_256 ( & V_37 -> V_304 ) ;
}
static T_2 F_257 ( struct V_12 * V_37 , T_2 V_7 )
{
struct V_310 * V_311 = V_37 -> V_312 ;
T_2 V_313 = 0 ;
if ( ! V_311 )
return 0 ;
if ( V_7 & V_300 &&
V_311 -> V_314 . V_7 & V_315 ) {
V_313 = V_300 | V_311 -> V_314 . V_313 ;
} else if ( V_7 & V_308 &&
V_311 -> V_316 . V_7 & V_315 ) {
V_313 = V_308 | V_311 -> V_316 . V_313 ;
} else if ( V_7 & V_306 &&
V_311 -> V_317 . V_7 & V_315 ) {
V_313 = V_306 | V_311 -> V_317 . V_313 ;
}
return V_313 ;
}
static T_2 F_258 ( struct V_34 * V_35 , T_2 V_7 )
{
T_2 V_318 = V_35 -> V_37 -> V_319 -> V_320 +
V_35 -> V_37 -> V_319 -> V_321 ;
T_2 V_313 ;
T_2 V_322 ;
F_11 ( & V_35 -> V_37 -> V_323 ) ;
V_313 = F_257 ( V_35 -> V_37 , V_7 ) ;
if ( V_313 ) {
if ( ( V_7 & V_313 ) & V_303 ) {
F_13 ( & V_35 -> V_37 -> V_323 ) ;
return F_259 ( V_313 ) ;
}
}
F_13 ( & V_35 -> V_37 -> V_323 ) ;
if ( V_318 == 1 )
V_7 &= ~ ( V_284 | V_324 |
V_325 ) ;
if ( V_318 < 3 )
V_7 &= ~ V_326 ;
if ( V_318 < 4 )
V_7 &= ~ V_285 ;
V_322 = V_7 & ( V_283 | V_324 |
V_284 | V_325 |
V_326 | V_285 ) ;
V_7 &= ~ V_322 ;
if ( V_322 & V_326 )
V_322 = V_326 ;
else if ( V_322 & V_325 )
V_322 = V_325 ;
else if ( V_322 & V_285 )
V_322 = V_285 ;
else if ( V_322 & V_284 )
V_322 = V_284 ;
else if ( V_322 & V_324 )
V_322 = V_324 ;
return F_259 ( V_7 | V_322 ) ;
}
static T_2 F_260 ( struct V_34 * V_35 , T_2 V_7 )
{
unsigned V_215 ;
do {
V_215 = F_261 ( & V_35 -> V_37 -> V_304 ) ;
if ( V_7 & V_300 )
V_7 |= V_35 -> V_37 -> V_305 ;
else if ( V_7 & V_308 )
V_7 |= V_35 -> V_37 -> V_309 ;
else if ( V_7 & V_306 )
V_7 |= V_35 -> V_37 -> V_307 ;
} while ( F_262 ( & V_35 -> V_37 -> V_304 , V_215 ) );
return F_258 ( V_35 , V_7 ) ;
}
T_2 F_263 ( struct V_34 * V_35 , int V_314 )
{
T_2 V_7 ;
T_2 V_29 ;
if ( V_314 )
V_7 = V_300 ;
else if ( V_35 == V_35 -> V_37 -> V_327 )
V_7 = V_308 ;
else
V_7 = V_306 ;
V_29 = F_260 ( V_35 , V_7 ) ;
return V_29 ;
}
int F_241 ( struct V_260 * V_260 , T_2 V_328 )
{
struct V_101 * V_301 ;
struct V_34 * V_35 = F_236 ( V_260 ) -> V_35 ;
struct V_12 * V_37 = V_35 -> V_37 ;
T_2 V_329 ;
int V_29 = 0 , V_330 = 0 , V_331 = 1 ;
V_328 = F_264 ( V_328 , V_35 -> V_332 ) ;
if ( V_35 == V_35 -> V_37 -> V_87 ||
F_236 ( V_260 ) -> V_333 . V_22 == V_334 ) {
V_331 = 0 ;
V_330 = 1 ;
}
V_301 = V_37 -> V_301 ;
if ( ! V_301 )
goto V_335;
V_78:
F_11 ( & V_301 -> V_52 ) ;
V_329 = V_301 -> V_281 + V_301 -> V_293 +
V_301 -> V_292 + V_301 -> V_294 +
V_301 -> V_295 ;
if ( V_329 + V_328 > V_301 -> V_280 ) {
struct V_108 * V_109 ;
if ( ! V_301 -> V_107 && V_331 ) {
T_2 V_336 ;
V_301 -> V_296 = V_337 ;
F_13 ( & V_301 -> V_52 ) ;
V_335:
V_336 = F_263 ( V_35 , 1 ) ;
V_109 = F_265 ( V_35 ) ;
if ( F_232 ( V_109 ) )
return F_233 ( V_109 ) ;
V_29 = F_266 ( V_109 , V_35 -> V_37 -> V_63 ,
V_336 ,
V_297 ) ;
F_267 ( V_109 , V_35 ) ;
if ( V_29 < 0 ) {
if ( V_29 != - V_338 )
return V_29 ;
else
goto V_339;
}
if ( ! V_301 )
V_301 = V_37 -> V_301 ;
goto V_78;
}
if ( F_268 ( & V_301 -> V_288 ,
V_328 ) < 0 )
V_330 = 1 ;
F_13 ( & V_301 -> V_52 ) ;
V_339:
if ( ! V_330 &&
! F_186 ( & V_35 -> V_37 -> V_340 ) ) {
V_330 = 1 ;
V_109 = F_265 ( V_35 ) ;
if ( F_232 ( V_109 ) )
return F_233 ( V_109 ) ;
V_29 = F_269 ( V_109 , V_35 ) ;
if ( V_29 )
return V_29 ;
goto V_78;
}
return - V_338 ;
}
V_301 -> V_295 += V_328 ;
F_270 ( V_35 -> V_37 , L_6 ,
V_301 -> V_7 , V_328 , 1 ) ;
F_13 ( & V_301 -> V_52 ) ;
return 0 ;
}
void F_243 ( struct V_260 * V_260 , T_2 V_328 )
{
struct V_34 * V_35 = F_236 ( V_260 ) -> V_35 ;
struct V_101 * V_301 ;
V_328 = F_264 ( V_328 , V_35 -> V_332 ) ;
V_301 = V_35 -> V_37 -> V_301 ;
F_11 ( & V_301 -> V_52 ) ;
F_8 ( V_301 -> V_295 < V_328 ) ;
V_301 -> V_295 -= V_328 ;
F_270 ( V_35 -> V_37 , L_6 ,
V_301 -> V_7 , V_328 , 0 ) ;
F_13 ( & V_301 -> V_52 ) ;
}
static void F_271 ( struct V_12 * V_13 )
{
struct V_102 * V_103 = & V_13 -> V_104 ;
struct V_101 * V_105 ;
F_68 () ;
F_69 (found, head, list) {
if ( V_105 -> V_7 & V_306 )
V_105 -> V_296 = V_337 ;
}
F_70 () ;
}
static inline T_2 F_272 ( struct V_231 * V_341 )
{
return ( V_341 -> V_57 << 1 ) ;
}
static int F_273 ( struct V_34 * V_35 ,
struct V_101 * V_342 , int V_343 )
{
struct V_231 * V_232 = & V_35 -> V_37 -> V_234 ;
T_2 V_36 = V_342 -> V_280 - V_342 -> V_294 ;
T_2 V_344 = V_342 -> V_281 + V_342 -> V_293 ;
T_2 V_345 ;
if ( V_343 == V_337 )
return 1 ;
if ( V_342 -> V_7 & V_306 )
V_344 += F_272 ( V_232 ) ;
if ( V_343 == V_346 ) {
V_345 = F_274 ( V_35 -> V_37 -> V_347 ) ;
V_345 = F_34 ( T_2 , 64 * 1024 * 1024 ,
F_275 ( V_345 , 1 ) ) ;
if ( V_36 - V_344 < V_345 )
return 1 ;
}
if ( V_344 + 2 * 1024 * 1024 < F_276 ( V_36 , 8 ) )
return 0 ;
return 1 ;
}
static T_2 F_277 ( struct V_34 * V_35 , T_2 type )
{
T_2 V_348 ;
if ( type & ( V_285 |
V_324 |
V_325 |
V_326 ) )
V_348 = V_35 -> V_37 -> V_319 -> V_320 ;
else if ( type & V_284 )
V_348 = 2 ;
else
V_348 = 1 ;
return F_191 ( V_35 , V_348 + 1 ) ;
}
static void F_278 ( struct V_108 * V_109 ,
struct V_34 * V_35 , T_2 type )
{
struct V_101 * V_13 ;
T_2 V_349 ;
T_2 V_345 ;
V_13 = F_67 ( V_35 -> V_37 , V_308 ) ;
F_11 ( & V_13 -> V_52 ) ;
V_349 = V_13 -> V_280 - V_13 -> V_281 - V_13 -> V_292 -
V_13 -> V_293 - V_13 -> V_294 ;
F_13 ( & V_13 -> V_52 ) ;
V_345 = F_277 ( V_35 , type ) ;
if ( V_349 < V_345 && F_240 ( V_35 , V_350 ) ) {
F_279 ( V_35 -> V_37 , L_7 ,
V_349 , V_345 , type ) ;
F_280 ( V_13 , 0 , 0 ) ;
}
if ( V_349 < V_345 ) {
T_2 V_7 ;
V_7 = F_263 ( V_35 -> V_37 -> V_327 , 0 ) ;
F_281 ( V_109 , V_35 , V_7 ) ;
}
}
static int F_266 ( struct V_108 * V_109 ,
struct V_34 * V_63 , T_2 V_7 , int V_343 )
{
struct V_101 * V_104 ;
struct V_12 * V_37 = V_63 -> V_37 ;
int V_351 = 0 ;
int V_29 = 0 ;
if ( V_109 -> V_352 )
return - V_338 ;
V_104 = F_67 ( V_63 -> V_37 , V_7 ) ;
if ( ! V_104 ) {
V_29 = F_248 ( V_63 -> V_37 , V_7 ,
0 , 0 , & V_104 ) ;
F_30 ( V_29 ) ;
}
F_30 ( ! V_104 ) ;
V_78:
F_11 ( & V_104 -> V_52 ) ;
if ( V_343 < V_104 -> V_296 )
V_343 = V_104 -> V_296 ;
if ( V_104 -> V_107 ) {
if ( F_273 ( V_63 , V_104 , V_343 ) )
V_29 = - V_338 ;
else
V_29 = 0 ;
F_13 ( & V_104 -> V_52 ) ;
return V_29 ;
}
if ( ! F_273 ( V_63 , V_104 , V_343 ) ) {
F_13 ( & V_104 -> V_52 ) ;
return 0 ;
} else if ( V_104 -> V_298 ) {
V_351 = 1 ;
} else {
V_104 -> V_298 = 1 ;
}
F_13 ( & V_104 -> V_52 ) ;
F_35 ( & V_37 -> V_353 ) ;
if ( V_351 ) {
F_45 ( & V_37 -> V_353 ) ;
V_351 = 0 ;
goto V_78;
}
V_109 -> V_352 = true ;
if ( F_282 ( V_104 ) )
V_7 |= ( V_300 | V_306 ) ;
if ( V_7 & V_300 && V_37 -> V_354 ) {
V_37 -> V_355 ++ ;
if ( ! ( V_37 -> V_355 %
V_37 -> V_354 ) )
F_271 ( V_37 ) ;
}
F_278 ( V_109 , V_63 , V_7 ) ;
V_29 = F_281 ( V_109 , V_63 , V_7 ) ;
V_109 -> V_352 = false ;
F_11 ( & V_104 -> V_52 ) ;
if ( V_29 < 0 && V_29 != - V_338 )
goto V_73;
if ( V_29 )
V_104 -> V_107 = 1 ;
else
V_29 = 1 ;
V_104 -> V_296 = V_297 ;
V_73:
V_104 -> V_298 = 0 ;
F_13 ( & V_104 -> V_52 ) ;
F_45 ( & V_37 -> V_353 ) ;
return V_29 ;
}
static int F_283 ( struct V_34 * V_35 ,
struct V_101 * V_104 , T_2 V_328 ,
enum V_356 V_299 )
{
struct V_231 * V_232 = & V_35 -> V_37 -> V_234 ;
T_2 V_357 = F_263 ( V_35 , 0 ) ;
T_2 V_358 ;
T_2 V_359 ;
T_2 V_329 ;
V_329 = V_104 -> V_281 + V_104 -> V_293 +
V_104 -> V_292 + V_104 -> V_294 ;
F_11 ( & V_232 -> V_52 ) ;
V_358 = F_272 ( V_232 ) ;
F_13 ( & V_232 -> V_52 ) ;
if ( V_329 + V_358 >= V_104 -> V_280 )
return 0 ;
V_329 += V_104 -> V_295 ;
F_11 ( & V_35 -> V_37 -> V_360 ) ;
V_359 = V_35 -> V_37 -> V_361 ;
F_13 ( & V_35 -> V_37 -> V_360 ) ;
if ( V_357 & ( V_283 |
V_284 |
V_285 ) )
V_359 >>= 1 ;
if ( V_299 == V_362 )
V_359 >>= 3 ;
else
V_359 >>= 1 ;
if ( V_329 + V_328 < V_104 -> V_280 + V_359 )
return 1 ;
return 0 ;
}
static void F_284 ( struct V_34 * V_35 ,
unsigned long V_363 )
{
struct V_364 * V_365 = V_35 -> V_37 -> V_365 ;
if ( F_285 ( & V_365 -> V_366 ) ) {
F_286 ( V_365 , V_363 , V_367 ) ;
F_44 ( & V_365 -> V_366 ) ;
} else {
F_287 ( V_35 -> V_37 , 0 ) ;
if ( ! V_368 -> V_369 )
F_288 ( V_35 -> V_37 ) ;
}
}
static void F_289 ( struct V_34 * V_35 , T_2 V_370 , T_2 V_371 ,
bool V_372 )
{
struct V_231 * V_373 ;
struct V_101 * V_104 ;
struct V_108 * V_109 ;
T_2 V_374 ;
T_2 V_375 ;
long V_376 ;
unsigned long V_363 = ( 2 * 1024 * 1024 ) >> V_377 ;
int V_238 = 0 ;
enum V_356 V_299 ;
V_109 = (struct V_108 * ) V_368 -> V_369 ;
V_373 = & V_35 -> V_37 -> V_378 ;
V_104 = V_373 -> V_104 ;
F_2 () ;
V_374 = F_290 (
& V_35 -> V_37 -> V_374 ) ;
if ( V_374 == 0 ) {
if ( V_109 )
return;
F_288 ( V_35 -> V_37 ) ;
return;
}
while ( V_374 && V_238 < 3 ) {
V_375 = F_291 ( V_374 , V_370 ) ;
V_363 = V_375 >> V_377 ;
F_284 ( V_35 , V_363 ) ;
F_292 ( V_35 -> V_37 -> V_379 ,
! F_186 ( & V_35 -> V_37 -> V_380 ) ) ;
if ( ! V_109 )
V_299 = V_362 ;
else
V_299 = V_381 ;
F_11 ( & V_104 -> V_52 ) ;
if ( F_283 ( V_35 , V_104 , V_371 , V_299 ) ) {
F_13 ( & V_104 -> V_52 ) ;
break;
}
F_13 ( & V_104 -> V_52 ) ;
V_238 ++ ;
if ( V_372 && ! V_109 ) {
F_288 ( V_35 -> V_37 ) ;
} else {
V_376 = F_293 ( 1 ) ;
if ( V_376 )
break;
}
F_2 () ;
V_374 = F_290 (
& V_35 -> V_37 -> V_374 ) ;
}
}
static int F_294 ( struct V_34 * V_35 ,
struct V_101 * V_104 ,
T_2 V_328 , int V_343 )
{
struct V_231 * V_382 = & V_35 -> V_37 -> V_383 ;
struct V_108 * V_109 ;
V_109 = (struct V_108 * ) V_368 -> V_369 ;
if ( V_109 )
return - V_175 ;
if ( V_343 )
goto V_384;
F_11 ( & V_104 -> V_52 ) ;
if ( F_268 ( & V_104 -> V_288 ,
V_328 ) >= 0 ) {
F_13 ( & V_104 -> V_52 ) ;
goto V_384;
}
F_13 ( & V_104 -> V_52 ) ;
if ( V_104 != V_382 -> V_104 )
return - V_338 ;
F_11 ( & V_104 -> V_52 ) ;
F_11 ( & V_382 -> V_52 ) ;
if ( F_268 ( & V_104 -> V_288 ,
V_328 - V_382 -> V_57 ) >= 0 ) {
F_13 ( & V_382 -> V_52 ) ;
F_13 ( & V_104 -> V_52 ) ;
return - V_338 ;
}
F_13 ( & V_382 -> V_52 ) ;
F_13 ( & V_104 -> V_52 ) ;
V_384:
V_109 = F_265 ( V_35 ) ;
if ( F_232 ( V_109 ) )
return - V_338 ;
return F_269 ( V_109 , V_35 ) ;
}
static int F_295 ( struct V_34 * V_35 ,
struct V_101 * V_104 , T_2 V_36 ,
T_2 V_385 , int V_386 )
{
struct V_108 * V_109 ;
int V_44 ;
int V_29 = 0 ;
switch ( V_386 ) {
case V_387 :
case V_388 :
if ( V_386 == V_387 ) {
T_2 V_328 = F_191 ( V_35 , 1 ) ;
V_44 = ( int ) F_188 ( V_36 , V_328 ) ;
if ( ! V_44 )
V_44 = 1 ;
V_44 *= 2 ;
} else {
V_44 = - 1 ;
}
V_109 = F_265 ( V_35 ) ;
if ( F_232 ( V_109 ) ) {
V_29 = F_233 ( V_109 ) ;
break;
}
V_29 = F_296 ( V_109 , V_35 , V_44 ) ;
F_267 ( V_109 , V_35 ) ;
break;
case V_389 :
case V_390 :
F_289 ( V_35 , V_36 , V_385 ,
V_386 == V_390 ) ;
break;
case V_391 :
V_109 = F_265 ( V_35 ) ;
if ( F_232 ( V_109 ) ) {
V_29 = F_233 ( V_109 ) ;
break;
}
V_29 = F_266 ( V_109 , V_35 -> V_37 -> V_63 ,
F_263 ( V_35 , 0 ) ,
V_297 ) ;
F_267 ( V_109 , V_35 ) ;
if ( V_29 == - V_338 )
V_29 = 0 ;
break;
case V_392 :
V_29 = F_294 ( V_35 , V_104 , V_385 , 0 ) ;
break;
default:
V_29 = - V_338 ;
break;
}
return V_29 ;
}
static int F_297 ( struct V_34 * V_35 ,
struct V_231 * V_373 ,
T_2 V_385 ,
enum V_356 V_299 )
{
struct V_101 * V_104 = V_373 -> V_104 ;
T_2 V_329 ;
T_2 V_36 = V_385 ;
int V_393 = V_387 ;
int V_29 = 0 ;
bool V_242 = false ;
V_78:
V_29 = 0 ;
F_11 ( & V_104 -> V_52 ) ;
while ( V_299 == V_362 && ! V_242 &&
V_104 -> V_299 ) {
F_13 ( & V_104 -> V_52 ) ;
if ( V_368 -> V_369 )
return - V_175 ;
V_29 = F_298 ( V_104 -> V_89 , ! V_104 -> V_299 ) ;
if ( V_29 )
return - V_394 ;
F_11 ( & V_104 -> V_52 ) ;
}
V_29 = - V_338 ;
V_329 = V_104 -> V_281 + V_104 -> V_293 +
V_104 -> V_292 + V_104 -> V_294 +
V_104 -> V_295 ;
if ( V_329 <= V_104 -> V_280 ) {
if ( V_329 + V_385 <= V_104 -> V_280 ) {
V_104 -> V_295 += V_385 ;
F_270 ( V_35 -> V_37 ,
L_6 , V_104 -> V_7 , V_385 , 1 ) ;
V_29 = 0 ;
} else {
V_36 = V_385 ;
}
} else {
V_36 = V_329 - V_104 -> V_280 +
( V_385 * 2 ) ;
}
if ( V_29 && F_283 ( V_35 , V_104 , V_385 , V_299 ) ) {
V_104 -> V_295 += V_385 ;
F_270 ( V_35 -> V_37 , L_6 ,
V_104 -> V_7 , V_385 ,
1 ) ;
V_29 = 0 ;
}
if ( V_29 && V_299 != V_381 ) {
V_242 = true ;
V_104 -> V_299 = 1 ;
}
F_13 ( & V_104 -> V_52 ) ;
if ( ! V_29 || V_299 == V_381 )
goto V_73;
V_29 = F_295 ( V_35 , V_104 , V_36 , V_385 ,
V_393 ) ;
V_393 ++ ;
if ( V_299 == V_395 &&
( V_393 == V_389 ||
V_393 == V_390 ) )
V_393 = V_391 ;
if ( ! V_29 )
goto V_78;
else if ( V_299 == V_395 &&
V_393 < V_392 )
goto V_78;
else if ( V_299 == V_362 &&
V_393 <= V_392 )
goto V_78;
V_73:
if ( V_29 == - V_338 &&
F_299 ( V_35 -> V_396 == V_397 ) ) {
struct V_231 * V_232 =
& V_35 -> V_37 -> V_234 ;
if ( V_373 != V_232 &&
! F_300 ( V_232 , V_385 ) )
V_29 = 0 ;
}
if ( V_242 ) {
F_11 ( & V_104 -> V_52 ) ;
V_104 -> V_299 = 0 ;
F_301 ( & V_104 -> V_89 ) ;
F_13 ( & V_104 -> V_52 ) ;
}
return V_29 ;
}
static struct V_231 * F_302 (
const struct V_108 * V_109 ,
const struct V_34 * V_35 )
{
struct V_231 * V_373 = NULL ;
if ( V_35 -> V_256 )
V_373 = V_109 -> V_373 ;
if ( V_35 == V_35 -> V_37 -> V_398 && V_109 -> V_399 )
V_373 = V_109 -> V_373 ;
if ( V_35 == V_35 -> V_37 -> V_400 )
V_373 = V_109 -> V_373 ;
if ( ! V_373 )
V_373 = V_35 -> V_373 ;
if ( ! V_373 )
V_373 = & V_35 -> V_37 -> V_401 ;
return V_373 ;
}
static int F_300 ( struct V_231 * V_373 ,
T_2 V_36 )
{
int V_29 = - V_338 ;
F_11 ( & V_373 -> V_52 ) ;
if ( V_373 -> V_10 >= V_36 ) {
V_373 -> V_10 -= V_36 ;
if ( V_373 -> V_10 < V_373 -> V_57 )
V_373 -> V_107 = 0 ;
V_29 = 0 ;
}
F_13 ( & V_373 -> V_52 ) ;
return V_29 ;
}
static void F_303 ( struct V_231 * V_373 ,
T_2 V_36 , int V_402 )
{
F_11 ( & V_373 -> V_52 ) ;
V_373 -> V_10 += V_36 ;
if ( V_402 )
V_373 -> V_57 += V_36 ;
else if ( V_373 -> V_10 >= V_373 -> V_57 )
V_373 -> V_107 = 1 ;
F_13 ( & V_373 -> V_52 ) ;
}
int F_304 ( struct V_12 * V_37 ,
struct V_231 * V_403 , T_2 V_36 ,
int V_404 )
{
struct V_231 * V_232 = & V_37 -> V_234 ;
T_2 V_405 ;
if ( V_232 -> V_104 != V_403 -> V_104 )
return - V_338 ;
F_11 ( & V_232 -> V_52 ) ;
V_405 = F_276 ( V_232 -> V_57 , V_404 ) ;
if ( V_232 -> V_10 < V_405 + V_36 ) {
F_13 ( & V_232 -> V_52 ) ;
return - V_338 ;
}
V_232 -> V_10 -= V_36 ;
if ( V_232 -> V_10 < V_232 -> V_57 )
V_232 -> V_107 = 0 ;
F_13 ( & V_232 -> V_52 ) ;
F_303 ( V_403 , V_36 , 1 ) ;
return 0 ;
}
static void F_305 ( struct V_12 * V_37 ,
struct V_231 * V_373 ,
struct V_231 * V_403 , T_2 V_36 )
{
struct V_101 * V_104 = V_373 -> V_104 ;
F_11 ( & V_373 -> V_52 ) ;
if ( V_36 == ( T_2 ) - 1 )
V_36 = V_373 -> V_57 ;
V_373 -> V_57 -= V_36 ;
if ( V_373 -> V_10 >= V_373 -> V_57 ) {
V_36 = V_373 -> V_10 - V_373 -> V_57 ;
V_373 -> V_10 = V_373 -> V_57 ;
V_373 -> V_107 = 1 ;
} else {
V_36 = 0 ;
}
F_13 ( & V_373 -> V_52 ) ;
if ( V_36 > 0 ) {
if ( V_403 ) {
F_11 ( & V_403 -> V_52 ) ;
if ( ! V_403 -> V_107 ) {
T_2 V_406 ;
V_406 = V_403 -> V_57 - V_403 -> V_10 ;
V_406 = F_291 ( V_36 , V_406 ) ;
V_403 -> V_10 += V_406 ;
if ( V_403 -> V_10 >= V_403 -> V_57 )
V_403 -> V_107 = 1 ;
V_36 -= V_406 ;
}
F_13 ( & V_403 -> V_52 ) ;
}
if ( V_36 ) {
F_11 ( & V_104 -> V_52 ) ;
V_104 -> V_295 -= V_36 ;
F_270 ( V_37 , L_6 ,
V_104 -> V_7 , V_36 , 0 ) ;
F_13 ( & V_104 -> V_52 ) ;
}
}
}
static int F_306 ( struct V_231 * V_407 ,
struct V_231 * V_408 , T_2 V_36 )
{
int V_29 ;
V_29 = F_300 ( V_407 , V_36 ) ;
if ( V_29 )
return V_29 ;
F_303 ( V_408 , V_36 , 1 ) ;
return 0 ;
}
void F_307 ( struct V_231 * V_409 , unsigned short type )
{
memset ( V_409 , 0 , sizeof( * V_409 ) ) ;
F_251 ( & V_409 -> V_52 ) ;
V_409 -> type = type ;
}
struct V_231 * F_308 ( struct V_34 * V_35 ,
unsigned short type )
{
struct V_231 * V_373 ;
struct V_12 * V_37 = V_35 -> V_37 ;
V_373 = F_309 ( sizeof( * V_373 ) , V_40 ) ;
if ( ! V_373 )
return NULL ;
F_307 ( V_373 , type ) ;
V_373 -> V_104 = F_67 ( V_37 ,
V_306 ) ;
return V_373 ;
}
void F_310 ( struct V_34 * V_35 ,
struct V_231 * V_409 )
{
if ( ! V_409 )
return;
F_311 ( V_35 , V_409 , ( T_2 ) - 1 ) ;
F_9 ( V_409 ) ;
}
int F_312 ( struct V_34 * V_35 ,
struct V_231 * V_373 , T_2 V_36 ,
enum V_356 V_299 )
{
int V_29 ;
if ( V_36 == 0 )
return 0 ;
V_29 = F_297 ( V_35 , V_373 , V_36 , V_299 ) ;
if ( ! V_29 ) {
F_303 ( V_373 , V_36 , 1 ) ;
return 0 ;
}
return V_29 ;
}
int F_313 ( struct V_34 * V_35 ,
struct V_231 * V_373 , int V_404 )
{
T_2 V_36 = 0 ;
int V_29 = - V_338 ;
if ( ! V_373 )
return 0 ;
F_11 ( & V_373 -> V_52 ) ;
V_36 = F_276 ( V_373 -> V_57 , V_404 ) ;
if ( V_373 -> V_10 >= V_36 )
V_29 = 0 ;
F_13 ( & V_373 -> V_52 ) ;
return V_29 ;
}
int F_314 ( struct V_34 * V_35 ,
struct V_231 * V_373 , T_2 V_410 ,
enum V_356 V_299 )
{
T_2 V_36 = 0 ;
int V_29 = - V_338 ;
if ( ! V_373 )
return 0 ;
F_11 ( & V_373 -> V_52 ) ;
V_36 = V_410 ;
if ( V_373 -> V_10 >= V_36 )
V_29 = 0 ;
else
V_36 -= V_373 -> V_10 ;
F_13 ( & V_373 -> V_52 ) ;
if ( ! V_29 )
return 0 ;
V_29 = F_297 ( V_35 , V_373 , V_36 , V_299 ) ;
if ( ! V_29 ) {
F_303 ( V_373 , V_36 , 0 ) ;
return 0 ;
}
return V_29 ;
}
int F_315 ( struct V_231 * V_411 ,
struct V_231 * V_412 ,
T_2 V_36 )
{
return F_306 ( V_411 , V_412 , V_36 ) ;
}
void F_311 ( struct V_34 * V_35 ,
struct V_231 * V_373 ,
T_2 V_36 )
{
struct V_231 * V_232 = & V_35 -> V_37 -> V_234 ;
if ( V_232 -> V_107 || V_232 == V_373 ||
V_373 -> V_104 != V_232 -> V_104 )
V_232 = NULL ;
F_305 ( V_35 -> V_37 , V_373 , V_232 ,
V_36 ) ;
}
static T_2 F_316 ( struct V_12 * V_37 )
{
struct V_101 * V_342 ;
T_2 V_36 ;
T_2 V_413 ;
T_2 V_414 ;
int V_415 = F_317 ( V_37 -> V_347 ) ;
V_342 = F_67 ( V_37 , V_300 ) ;
F_11 ( & V_342 -> V_52 ) ;
V_414 = V_342 -> V_281 ;
F_13 ( & V_342 -> V_52 ) ;
V_342 = F_67 ( V_37 , V_306 ) ;
F_11 ( & V_342 -> V_52 ) ;
if ( V_342 -> V_7 & V_300 )
V_414 = 0 ;
V_413 = V_342 -> V_281 ;
F_13 ( & V_342 -> V_52 ) ;
V_36 = ( V_414 >> V_37 -> V_365 -> V_416 ) *
V_415 * 2 ;
V_36 += F_188 ( V_414 + V_413 , 50 ) ;
if ( V_36 * 3 > V_413 )
V_36 = F_188 ( V_413 , 3 ) ;
return F_264 ( V_36 , V_37 -> V_63 -> V_88 << 10 ) ;
}
static void F_318 ( struct V_12 * V_37 )
{
struct V_231 * V_373 = & V_37 -> V_234 ;
struct V_101 * V_342 = V_373 -> V_104 ;
T_2 V_36 ;
V_36 = F_316 ( V_37 ) ;
F_11 ( & V_342 -> V_52 ) ;
F_11 ( & V_373 -> V_52 ) ;
V_373 -> V_57 = F_24 ( T_2 , V_36 , 512 * 1024 * 1024 ) ;
V_36 = V_342 -> V_281 + V_342 -> V_292 +
V_342 -> V_293 + V_342 -> V_294 +
V_342 -> V_295 ;
if ( V_342 -> V_280 > V_36 ) {
V_36 = V_342 -> V_280 - V_36 ;
V_373 -> V_10 += V_36 ;
V_342 -> V_295 += V_36 ;
F_270 ( V_37 , L_6 ,
V_342 -> V_7 , V_36 , 1 ) ;
}
if ( V_373 -> V_10 >= V_373 -> V_57 ) {
V_36 = V_373 -> V_10 - V_373 -> V_57 ;
V_342 -> V_295 -= V_36 ;
F_270 ( V_37 , L_6 ,
V_342 -> V_7 , V_36 , 0 ) ;
V_373 -> V_10 = V_373 -> V_57 ;
V_373 -> V_107 = 1 ;
}
F_13 ( & V_373 -> V_52 ) ;
F_13 ( & V_342 -> V_52 ) ;
}
static void F_319 ( struct V_12 * V_37 )
{
struct V_101 * V_104 ;
V_104 = F_67 ( V_37 , V_308 ) ;
V_37 -> V_417 . V_104 = V_104 ;
V_104 = F_67 ( V_37 , V_306 ) ;
V_37 -> V_234 . V_104 = V_104 ;
V_37 -> V_378 . V_104 = V_104 ;
V_37 -> V_418 . V_104 = V_104 ;
V_37 -> V_401 . V_104 = V_104 ;
V_37 -> V_383 . V_104 = V_104 ;
V_37 -> V_63 -> V_373 = & V_37 -> V_234 ;
V_37 -> V_398 -> V_373 = & V_37 -> V_234 ;
V_37 -> V_419 -> V_373 = & V_37 -> V_234 ;
V_37 -> V_87 -> V_373 = & V_37 -> V_234 ;
if ( V_37 -> V_420 )
V_37 -> V_420 -> V_373 = & V_37 -> V_234 ;
V_37 -> V_327 -> V_373 = & V_37 -> V_417 ;
F_318 ( V_37 ) ;
}
static void F_320 ( struct V_12 * V_37 )
{
F_305 ( V_37 , & V_37 -> V_234 , NULL ,
( T_2 ) - 1 ) ;
F_8 ( V_37 -> V_378 . V_57 > 0 ) ;
F_8 ( V_37 -> V_378 . V_10 > 0 ) ;
F_8 ( V_37 -> V_418 . V_57 > 0 ) ;
F_8 ( V_37 -> V_418 . V_10 > 0 ) ;
F_8 ( V_37 -> V_417 . V_57 > 0 ) ;
F_8 ( V_37 -> V_417 . V_10 > 0 ) ;
F_8 ( V_37 -> V_383 . V_57 > 0 ) ;
F_8 ( V_37 -> V_383 . V_10 > 0 ) ;
}
void F_321 ( struct V_108 * V_109 ,
struct V_34 * V_35 )
{
if ( ! V_109 -> V_373 )
return;
if ( ! V_109 -> V_293 )
return;
F_270 ( V_35 -> V_37 , L_8 ,
V_109 -> V_270 , V_109 -> V_293 , 0 ) ;
F_311 ( V_35 , V_109 -> V_373 , V_109 -> V_293 ) ;
V_109 -> V_293 = 0 ;
}
int F_322 ( struct V_108 * V_109 ,
struct V_260 * V_260 )
{
struct V_34 * V_35 = F_236 ( V_260 ) -> V_35 ;
struct V_231 * V_411 = F_302 ( V_109 , V_35 ) ;
struct V_231 * V_412 = V_35 -> V_421 ;
T_2 V_36 = F_191 ( V_35 , 1 ) ;
F_270 ( V_35 -> V_37 , L_9 ,
F_323 ( V_260 ) , V_36 , 1 ) ;
return F_306 ( V_411 , V_412 , V_36 ) ;
}
void F_324 ( struct V_260 * V_260 )
{
struct V_34 * V_35 = F_236 ( V_260 ) -> V_35 ;
T_2 V_36 = F_191 ( V_35 , 1 ) ;
F_270 ( V_35 -> V_37 , L_9 ,
F_323 ( V_260 ) , V_36 , 0 ) ;
F_311 ( V_35 , V_35 -> V_421 , V_36 ) ;
}
int F_325 ( struct V_34 * V_35 ,
struct V_231 * V_409 ,
int V_422 ,
T_2 * V_423 ,
bool V_424 )
{
T_2 V_36 ;
int V_29 ;
struct V_231 * V_232 = & V_35 -> V_37 -> V_234 ;
if ( V_35 -> V_37 -> V_425 ) {
V_36 = 3 * V_35 -> V_88 ;
V_29 = F_326 ( V_35 , V_36 ) ;
if ( V_29 )
return V_29 ;
} else {
V_36 = 0 ;
}
* V_423 = V_36 ;
V_36 = F_191 ( V_35 , V_422 ) ;
V_409 -> V_104 = F_67 ( V_35 -> V_37 ,
V_306 ) ;
V_29 = F_312 ( V_35 , V_409 , V_36 ,
V_362 ) ;
if ( V_29 == - V_338 && V_424 )
V_29 = F_315 ( V_232 , V_409 , V_36 ) ;
if ( V_29 ) {
if ( * V_423 )
F_327 ( V_35 , * V_423 ) ;
}
return V_29 ;
}
void F_328 ( struct V_34 * V_35 ,
struct V_231 * V_409 ,
T_2 V_423 )
{
F_311 ( V_35 , V_409 , ( T_2 ) - 1 ) ;
if ( V_423 )
F_327 ( V_35 , V_423 ) ;
}
static unsigned F_329 ( struct V_260 * V_260 )
{
unsigned V_426 = 0 ;
unsigned V_427 = 0 ;
F_30 ( ! F_236 ( V_260 ) -> V_428 ) ;
F_236 ( V_260 ) -> V_428 -- ;
if ( F_236 ( V_260 ) -> V_428 == 0 &&
F_330 ( V_429 ,
& F_236 ( V_260 ) -> V_430 ) )
V_426 = 1 ;
if ( F_236 ( V_260 ) -> V_428 >=
F_236 ( V_260 ) -> V_431 )
return V_426 ;
V_427 = F_236 ( V_260 ) -> V_431 -
F_236 ( V_260 ) -> V_428 ;
F_236 ( V_260 ) -> V_431 -= V_427 ;
return V_427 + V_426 ;
}
static T_2 F_331 ( struct V_260 * V_260 , T_2 V_36 ,
int V_432 )
{
struct V_34 * V_35 = F_236 ( V_260 ) -> V_35 ;
T_2 V_415 ;
int V_433 ;
int V_434 ;
int V_435 ;
if ( F_236 ( V_260 ) -> V_7 & V_436 &&
F_236 ( V_260 ) -> V_437 == 0 )
return 0 ;
V_435 = ( int ) F_188 ( F_236 ( V_260 ) -> V_437 , V_35 -> V_332 ) ;
if ( V_432 )
F_236 ( V_260 ) -> V_437 += V_36 ;
else
F_236 ( V_260 ) -> V_437 -= V_36 ;
V_415 = F_189 ( V_35 ) - sizeof( struct V_438 ) ;
V_433 = ( int ) F_188 ( V_415 ,
sizeof( struct V_439 ) +
sizeof( struct V_440 ) ) ;
V_434 = ( int ) F_188 ( F_236 ( V_260 ) -> V_437 , V_35 -> V_332 ) ;
V_434 = V_434 + V_433 - 1 ;
V_434 = V_434 / V_433 ;
V_435 = V_435 + V_433 - 1 ;
V_435 = V_435 / V_433 ;
if ( V_435 == V_434 )
return 0 ;
if ( V_432 )
return F_191 ( V_35 ,
V_434 - V_435 ) ;
return F_191 ( V_35 , V_435 - V_434 ) ;
}
int F_332 ( struct V_260 * V_260 , T_2 V_36 )
{
struct V_34 * V_35 = F_236 ( V_260 ) -> V_35 ;
struct V_231 * V_373 = & V_35 -> V_37 -> V_378 ;
T_2 V_441 = 0 ;
T_2 V_437 ;
unsigned V_442 = 0 ;
int V_443 = 0 ;
enum V_356 V_299 = V_362 ;
int V_29 = 0 ;
bool V_444 = true ;
T_2 V_445 = 0 ;
unsigned V_446 ;
if ( F_333 ( V_260 ) ) {
V_299 = V_381 ;
V_444 = false ;
}
if ( V_299 != V_381 &&
F_334 ( V_35 -> V_37 ) )
F_201 ( 1 ) ;
if ( V_444 )
F_35 ( & F_236 ( V_260 ) -> V_447 ) ;
V_36 = F_264 ( V_36 , V_35 -> V_332 ) ;
F_11 ( & F_236 ( V_260 ) -> V_52 ) ;
F_236 ( V_260 ) -> V_428 ++ ;
if ( F_236 ( V_260 ) -> V_428 >
F_236 ( V_260 ) -> V_431 )
V_442 = F_236 ( V_260 ) -> V_428 -
F_236 ( V_260 ) -> V_431 ;
if ( ! F_335 ( V_429 ,
& F_236 ( V_260 ) -> V_430 ) ) {
V_442 ++ ;
V_443 = 1 ;
}
V_441 = F_191 ( V_35 , V_442 ) ;
V_441 += F_331 ( V_260 , V_36 , 1 ) ;
V_437 = F_236 ( V_260 ) -> V_437 ;
F_13 ( & F_236 ( V_260 ) -> V_52 ) ;
if ( V_35 -> V_37 -> V_425 ) {
V_29 = F_326 ( V_35 , V_36 +
V_442 * V_35 -> V_88 ) ;
if ( V_29 )
goto V_448;
}
V_29 = F_297 ( V_35 , V_373 , V_441 , V_299 ) ;
if ( F_299 ( V_29 ) ) {
if ( V_35 -> V_37 -> V_425 )
F_327 ( V_35 , V_36 +
V_442 * V_35 -> V_88 ) ;
goto V_448;
}
F_11 ( & F_236 ( V_260 ) -> V_52 ) ;
if ( V_443 ) {
F_336 ( V_429 ,
& F_236 ( V_260 ) -> V_430 ) ;
V_442 -- ;
}
F_236 ( V_260 ) -> V_431 += V_442 ;
F_13 ( & F_236 ( V_260 ) -> V_52 ) ;
if ( V_444 )
F_45 ( & F_236 ( V_260 ) -> V_447 ) ;
if ( V_441 )
F_270 ( V_35 -> V_37 , L_10 ,
F_323 ( V_260 ) , V_441 , 1 ) ;
F_303 ( V_373 , V_441 , 1 ) ;
return 0 ;
V_448:
F_11 ( & F_236 ( V_260 ) -> V_52 ) ;
V_446 = F_329 ( V_260 ) ;
if ( F_236 ( V_260 ) -> V_437 == V_437 ) {
F_331 ( V_260 , V_36 , 0 ) ;
} else {
T_2 V_449 = F_236 ( V_260 ) -> V_437 ;
T_2 V_328 ;
V_328 = V_437 - F_236 ( V_260 ) -> V_437 ;
F_236 ( V_260 ) -> V_437 = V_437 ;
V_445 = F_331 ( V_260 , V_328 , 0 ) ;
F_236 ( V_260 ) -> V_437 = V_437 - V_36 ;
V_328 = V_437 - V_449 ;
V_328 = F_331 ( V_260 , V_328 , 0 ) ;
F_236 ( V_260 ) -> V_437 = V_449 - V_36 ;
if ( V_328 > V_445 )
V_445 = V_328 - V_445 ;
else
V_445 = 0 ;
}
F_13 ( & F_236 ( V_260 ) -> V_52 ) ;
if ( V_446 )
V_445 += F_191 ( V_35 , V_446 ) ;
if ( V_445 ) {
F_311 ( V_35 , V_373 , V_445 ) ;
F_270 ( V_35 -> V_37 , L_10 ,
F_323 ( V_260 ) , V_445 , 0 ) ;
}
if ( V_444 )
F_45 ( & F_236 ( V_260 ) -> V_447 ) ;
return V_29 ;
}
void F_337 ( struct V_260 * V_260 , T_2 V_36 )
{
struct V_34 * V_35 = F_236 ( V_260 ) -> V_35 ;
T_2 V_445 = 0 ;
unsigned V_446 ;
V_36 = F_264 ( V_36 , V_35 -> V_332 ) ;
F_11 ( & F_236 ( V_260 ) -> V_52 ) ;
V_446 = F_329 ( V_260 ) ;
if ( V_36 )
V_445 = F_331 ( V_260 , V_36 , 0 ) ;
F_13 ( & F_236 ( V_260 ) -> V_52 ) ;
if ( V_446 > 0 )
V_445 += F_191 ( V_35 , V_446 ) ;
F_270 ( V_35 -> V_37 , L_10 ,
F_323 ( V_260 ) , V_445 , 0 ) ;
if ( V_35 -> V_37 -> V_425 ) {
F_327 ( V_35 , V_36 +
V_446 * V_35 -> V_88 ) ;
}
F_311 ( V_35 , & V_35 -> V_37 -> V_378 ,
V_445 ) ;
}
int F_338 ( struct V_260 * V_260 , T_2 V_36 )
{
int V_29 ;
V_29 = F_241 ( V_260 , V_36 ) ;
if ( V_29 )
return V_29 ;
V_29 = F_332 ( V_260 , V_36 ) ;
if ( V_29 ) {
F_243 ( V_260 , V_36 ) ;
return V_29 ;
}
return 0 ;
}
void F_339 ( struct V_260 * V_260 , T_2 V_36 )
{
F_337 ( V_260 , V_36 ) ;
F_243 ( V_260 , V_36 ) ;
}
static int F_340 ( struct V_34 * V_35 ,
T_2 V_27 , T_2 V_36 , int V_335 )
{
struct V_1 * V_2 = NULL ;
struct V_12 * V_13 = V_35 -> V_37 ;
T_2 V_450 = V_36 ;
T_2 V_451 ;
T_2 V_452 ;
int V_282 ;
F_11 ( & V_13 -> V_453 ) ;
V_451 = F_341 ( V_13 -> V_347 ) ;
if ( V_335 )
V_451 += V_36 ;
else
V_451 -= V_36 ;
F_342 ( V_13 -> V_347 , V_451 ) ;
F_13 ( & V_13 -> V_453 ) ;
while ( V_450 ) {
V_2 = F_66 ( V_13 , V_27 ) ;
if ( ! V_2 )
return - V_151 ;
if ( V_2 -> V_7 & ( V_283 |
V_284 |
V_285 ) )
V_282 = 2 ;
else
V_282 = 1 ;
if ( ! V_335 && V_2 -> V_3 == V_95 )
F_50 ( V_2 , 1 ) ;
V_452 = V_27 - V_2 -> V_21 . V_22 ;
F_8 ( V_452 > V_2 -> V_21 . V_33 ) ;
F_11 ( & V_2 -> V_104 -> V_52 ) ;
F_11 ( & V_2 -> V_52 ) ;
if ( F_240 ( V_35 , V_274 ) &&
V_2 -> V_266 < V_276 )
V_2 -> V_266 = V_276 ;
V_2 -> V_277 = 1 ;
V_451 = F_343 ( & V_2 -> V_133 ) ;
V_36 = F_291 ( V_450 , V_2 -> V_21 . V_33 - V_452 ) ;
if ( V_335 ) {
V_451 += V_36 ;
F_344 ( & V_2 -> V_133 , V_451 ) ;
V_2 -> V_10 -= V_36 ;
V_2 -> V_104 -> V_293 -= V_36 ;
V_2 -> V_104 -> V_281 += V_36 ;
V_2 -> V_104 -> V_287 += V_36 * V_282 ;
F_13 ( & V_2 -> V_52 ) ;
F_13 ( & V_2 -> V_104 -> V_52 ) ;
} else {
V_451 -= V_36 ;
F_344 ( & V_2 -> V_133 , V_451 ) ;
V_2 -> V_9 += V_36 ;
V_2 -> V_104 -> V_292 += V_36 ;
V_2 -> V_104 -> V_281 -= V_36 ;
V_2 -> V_104 -> V_287 -= V_36 * V_282 ;
F_13 ( & V_2 -> V_52 ) ;
F_13 ( & V_2 -> V_104 -> V_52 ) ;
F_345 ( V_13 -> V_59 ,
V_27 , V_27 + V_36 - 1 ,
V_40 | V_454 ) ;
}
F_6 ( V_2 ) ;
V_450 -= V_36 ;
V_27 += V_36 ;
}
return 0 ;
}
static T_2 V_26 ( struct V_34 * V_35 , T_2 V_455 )
{
struct V_1 * V_2 ;
T_2 V_27 ;
F_11 ( & V_35 -> V_37 -> V_18 ) ;
V_27 = V_35 -> V_37 -> V_26 ;
F_13 ( & V_35 -> V_37 -> V_18 ) ;
if ( V_27 < ( T_2 ) - 1 )
return V_27 ;
V_2 = F_65 ( V_35 -> V_37 , V_455 ) ;
if ( ! V_2 )
return 0 ;
V_27 = V_2 -> V_21 . V_22 ;
F_6 ( V_2 ) ;
return V_27 ;
}
static int F_346 ( struct V_34 * V_35 ,
struct V_1 * V_2 ,
T_2 V_27 , T_2 V_36 , int V_10 )
{
F_11 ( & V_2 -> V_104 -> V_52 ) ;
F_11 ( & V_2 -> V_52 ) ;
V_2 -> V_9 += V_36 ;
V_2 -> V_104 -> V_292 += V_36 ;
if ( V_10 ) {
V_2 -> V_10 -= V_36 ;
V_2 -> V_104 -> V_293 -= V_36 ;
}
F_13 ( & V_2 -> V_52 ) ;
F_13 ( & V_2 -> V_104 -> V_52 ) ;
F_345 ( V_35 -> V_37 -> V_59 , V_27 ,
V_27 + V_36 - 1 , V_40 | V_454 ) ;
return 0 ;
}
int F_162 ( struct V_34 * V_35 ,
T_2 V_27 , T_2 V_36 , int V_10 )
{
struct V_1 * V_2 ;
V_2 = F_66 ( V_35 -> V_37 , V_27 ) ;
F_30 ( ! V_2 ) ;
F_346 ( V_35 , V_2 , V_27 , V_36 , V_10 ) ;
F_6 ( V_2 ) ;
return 0 ;
}
int F_347 ( struct V_34 * V_35 ,
T_2 V_27 , T_2 V_36 )
{
struct V_1 * V_2 ;
int V_29 ;
V_2 = F_66 ( V_35 -> V_37 , V_27 ) ;
if ( ! V_2 )
return - V_456 ;
F_50 ( V_2 , 1 ) ;
F_346 ( V_35 , V_2 , V_27 , V_36 , 0 ) ;
V_29 = F_348 ( V_2 , V_27 , V_36 ) ;
F_6 ( V_2 ) ;
return V_29 ;
}
static int F_349 ( struct V_34 * V_35 , T_2 V_32 , T_2 V_36 )
{
int V_29 ;
struct V_1 * V_14 ;
struct V_50 * V_54 ;
V_14 = F_66 ( V_35 -> V_37 , V_32 ) ;
if ( ! V_14 )
return - V_456 ;
F_50 ( V_14 , 0 ) ;
V_54 = F_25 ( V_14 ) ;
if ( ! V_54 ) {
F_30 ( ! F_1 ( V_14 ) ) ;
V_29 = F_348 ( V_14 , V_32 , V_36 ) ;
} else {
F_35 ( & V_54 -> V_79 ) ;
if ( V_32 >= V_54 -> V_85 ) {
V_29 = F_17 ( V_35 , V_32 , V_36 ) ;
} else if ( V_32 + V_36 <= V_54 -> V_85 ) {
V_29 = F_348 ( V_14 ,
V_32 , V_36 ) ;
} else {
V_36 = V_54 -> V_85 - V_32 ;
V_29 = F_348 ( V_14 ,
V_32 , V_36 ) ;
if ( V_29 )
goto V_457;
V_36 = ( V_32 + V_36 ) -
V_54 -> V_85 ;
V_32 = V_54 -> V_85 ;
V_29 = F_17 ( V_35 , V_32 , V_36 ) ;
}
V_457:
F_45 ( & V_54 -> V_79 ) ;
F_26 ( V_54 ) ;
}
F_6 ( V_14 ) ;
return V_29 ;
}
int F_350 ( struct V_34 * log ,
struct V_66 * V_458 )
{
struct V_254 * V_133 ;
struct V_68 V_21 ;
int V_459 ;
int V_43 ;
if ( ! F_74 ( log -> V_37 , V_460 ) )
return 0 ;
for ( V_43 = 0 ; V_43 < F_38 ( V_458 ) ; V_43 ++ ) {
F_40 ( V_458 , & V_21 , V_43 ) ;
if ( V_21 . type != V_258 )
continue;
V_133 = F_76 ( V_458 , V_43 , struct V_254 ) ;
V_459 = F_218 ( V_458 , V_133 ) ;
if ( V_459 == V_259 )
continue;
if ( F_219 ( V_458 , V_133 ) == 0 )
continue;
V_21 . V_22 = F_219 ( V_458 , V_133 ) ;
V_21 . V_33 = F_220 ( V_458 , V_133 ) ;
F_349 ( log , V_21 . V_22 , V_21 . V_33 ) ;
}
return 0 ;
}
static int F_351 ( struct V_1 * V_2 ,
T_2 V_36 , int V_432 )
{
struct V_101 * V_104 = V_2 -> V_104 ;
int V_29 = 0 ;
F_11 ( & V_104 -> V_52 ) ;
F_11 ( & V_2 -> V_52 ) ;
if ( V_432 != V_461 ) {
if ( V_2 -> V_268 ) {
V_29 = - V_175 ;
} else {
V_2 -> V_10 += V_36 ;
V_104 -> V_293 += V_36 ;
if ( V_432 == V_462 ) {
F_270 ( V_2 -> V_37 ,
L_6 , V_104 -> V_7 ,
V_36 , 0 ) ;
V_104 -> V_295 -= V_36 ;
}
}
} else {
if ( V_2 -> V_268 )
V_104 -> V_294 += V_36 ;
V_2 -> V_10 -= V_36 ;
V_104 -> V_293 -= V_36 ;
}
F_13 ( & V_2 -> V_52 ) ;
F_13 ( & V_104 -> V_52 ) ;
return V_29 ;
}
void F_352 ( struct V_108 * V_109 ,
struct V_34 * V_35 )
{
struct V_12 * V_37 = V_35 -> V_37 ;
struct V_50 * V_81 ;
struct V_50 * V_54 ;
struct V_1 * V_2 ;
struct V_101 * V_104 ;
F_61 ( & V_37 -> V_80 ) ;
F_353 (caching_ctl, next,
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
F_354 ( & V_104 -> V_288 , 0 ) ;
F_318 ( V_37 ) ;
}
static int F_355 ( struct V_34 * V_35 , T_2 V_32 , T_2 V_31 )
{
struct V_12 * V_37 = V_35 -> V_37 ;
struct V_1 * V_2 = NULL ;
struct V_101 * V_104 ;
struct V_231 * V_232 = & V_37 -> V_234 ;
T_2 V_49 ;
bool V_279 ;
while ( V_32 <= V_31 ) {
V_279 = false ;
if ( ! V_2 ||
V_32 >= V_2 -> V_21 . V_22 + V_2 -> V_21 . V_33 ) {
if ( V_2 )
F_6 ( V_2 ) ;
V_2 = F_66 ( V_37 , V_32 ) ;
F_30 ( ! V_2 ) ;
}
V_49 = V_2 -> V_21 . V_22 + V_2 -> V_21 . V_33 - V_32 ;
V_49 = F_291 ( V_49 , V_31 + 1 - V_32 ) ;
if ( V_32 < V_2 -> V_98 ) {
V_49 = F_291 ( V_49 , V_2 -> V_98 - V_32 ) ;
F_29 ( V_2 , V_32 , V_49 ) ;
}
V_32 += V_49 ;
V_104 = V_2 -> V_104 ;
F_11 ( & V_104 -> V_52 ) ;
F_11 ( & V_2 -> V_52 ) ;
V_2 -> V_9 -= V_49 ;
V_104 -> V_292 -= V_49 ;
if ( V_2 -> V_268 ) {
V_104 -> V_294 += V_49 ;
V_279 = true ;
}
F_13 ( & V_2 -> V_52 ) ;
if ( ! V_279 && V_232 -> V_104 == V_104 ) {
F_11 ( & V_232 -> V_52 ) ;
if ( ! V_232 -> V_107 ) {
V_49 = F_291 ( V_49 , V_232 -> V_57 -
V_232 -> V_10 ) ;
V_232 -> V_10 += V_49 ;
V_104 -> V_295 += V_49 ;
if ( V_232 -> V_10 >= V_232 -> V_57 )
V_232 -> V_107 = 1 ;
}
F_13 ( & V_232 -> V_52 ) ;
}
F_13 ( & V_104 -> V_52 ) ;
}
if ( V_2 )
F_6 ( V_2 ) ;
return 0 ;
}
int F_356 ( struct V_108 * V_109 ,
struct V_34 * V_35 )
{
struct V_12 * V_37 = V_35 -> V_37 ;
struct V_463 * V_464 ;
T_2 V_32 ;
T_2 V_31 ;
int V_29 ;
if ( V_109 -> V_210 )
return 0 ;
if ( V_37 -> V_59 == & V_37 -> V_38 [ 0 ] )
V_464 = & V_37 -> V_38 [ 1 ] ;
else
V_464 = & V_37 -> V_38 [ 0 ] ;
while ( 1 ) {
V_29 = F_28 ( V_464 , 0 , & V_32 , & V_31 ,
V_60 , NULL ) ;
if ( V_29 )
break;
if ( F_240 ( V_35 , V_465 ) )
V_29 = F_140 ( V_35 , V_32 ,
V_31 + 1 - V_32 , NULL ) ;
F_357 ( V_464 , V_32 , V_31 , V_40 ) ;
F_355 ( V_35 , V_32 , V_31 ) ;
F_46 () ;
}
return 0 ;
}
static void F_358 ( struct V_12 * V_37 , T_2 V_36 ,
T_2 V_131 , T_2 V_144 )
{
struct V_101 * V_104 ;
T_2 V_7 ;
if ( V_131 < V_141 ) {
if ( V_144 == V_466 )
V_7 = V_308 ;
else
V_7 = V_306 ;
} else {
V_7 = V_300 ;
}
V_104 = F_67 ( V_37 , V_7 ) ;
F_30 ( ! V_104 ) ;
F_359 ( & V_104 -> V_288 , V_36 ) ;
}
static int F_151 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
T_2 V_27 , T_2 V_36 , T_2 V_17 ,
T_2 V_144 , T_2 V_467 ,
T_2 V_468 , int V_157 ,
struct V_177 * V_127 )
{
struct V_68 V_21 ;
struct V_64 * V_65 ;
struct V_12 * V_13 = V_35 -> V_37 ;
struct V_34 * V_63 = V_13 -> V_63 ;
struct V_66 * V_67 ;
struct V_115 * V_116 ;
struct V_160 * V_161 ;
int V_29 ;
int V_181 ;
int V_469 = 0 ;
int V_470 = 0 ;
int V_471 = 1 ;
T_3 V_117 ;
T_2 V_111 ;
bool V_170 = F_74 ( V_35 -> V_37 ,
V_120 ) ;
V_65 = F_33 () ;
if ( ! V_65 )
return - V_72 ;
V_65 -> V_76 = 1 ;
V_65 -> V_201 = 1 ;
V_181 = V_467 >= V_141 ;
F_30 ( ! V_181 && V_157 != 1 ) ;
if ( V_181 )
V_170 = 0 ;
V_29 = F_132 ( V_109 , V_63 , V_65 , & V_161 ,
V_27 , V_36 , V_17 ,
V_144 , V_467 ,
V_468 ) ;
if ( V_29 == 0 ) {
V_469 = V_65 -> V_84 [ 0 ] ;
while ( V_469 >= 0 ) {
F_40 ( V_65 -> V_83 [ 0 ] , & V_21 ,
V_469 ) ;
if ( V_21 . V_22 != V_27 )
break;
if ( V_21 . type == V_77 &&
V_21 . V_33 == V_36 ) {
V_470 = 1 ;
break;
}
if ( V_21 . type == V_86 &&
V_21 . V_33 == V_467 ) {
V_470 = 1 ;
break;
}
if ( V_65 -> V_84 [ 0 ] - V_469 > 5 )
break;
V_469 -- ;
}
#ifdef F_79
V_117 = F_75 ( V_65 -> V_83 [ 0 ] , V_469 ) ;
if ( V_470 && V_117 < sizeof( * V_116 ) )
V_470 = 0 ;
#endif
if ( ! V_470 ) {
F_30 ( V_161 ) ;
V_29 = F_137 ( V_109 , V_63 , V_65 ,
NULL , V_157 ,
V_181 ) ;
if ( V_29 ) {
F_146 ( V_109 , V_63 , V_29 ) ;
goto V_73;
}
F_43 ( V_65 ) ;
V_65 -> V_201 = 1 ;
V_21 . V_22 = V_27 ;
V_21 . type = V_77 ;
V_21 . V_33 = V_36 ;
if ( ! V_181 && V_170 ) {
V_21 . type = V_86 ;
V_21 . V_33 = V_467 ;
}
V_29 = F_37 ( V_109 , V_63 ,
& V_21 , V_65 , - 1 , 1 ) ;
if ( V_29 > 0 && V_170 && V_65 -> V_84 [ 0 ] ) {
V_65 -> V_84 [ 0 ] -- ;
F_40 ( V_65 -> V_83 [ 0 ] , & V_21 ,
V_65 -> V_84 [ 0 ] ) ;
if ( V_21 . V_22 == V_27 &&
V_21 . type == V_77 &&
V_21 . V_33 == V_36 )
V_29 = 0 ;
}
if ( V_29 > 0 && V_170 ) {
V_170 = false ;
V_21 . type = V_77 ;
V_21 . V_33 = V_36 ;
F_43 ( V_65 ) ;
V_29 = F_37 ( V_109 , V_63 ,
& V_21 , V_65 , - 1 , 1 ) ;
}
if ( V_29 ) {
F_180 ( V_13 , L_11 ,
V_29 , V_27 ) ;
if ( V_29 > 0 )
F_360 ( V_63 ,
V_65 -> V_83 [ 0 ] ) ;
}
if ( V_29 < 0 ) {
F_146 ( V_109 , V_63 , V_29 ) ;
goto V_73;
}
V_469 = V_65 -> V_84 [ 0 ] ;
}
} else if ( V_29 == - V_151 ) {
F_360 ( V_63 , V_65 -> V_83 [ 0 ] ) ;
F_8 ( 1 ) ;
F_180 ( V_13 ,
L_12 ,
V_27 , V_17 , V_144 , V_467 ,
V_468 ) ;
} else {
F_146 ( V_109 , V_63 , V_29 ) ;
goto V_73;
}
V_67 = V_65 -> V_83 [ 0 ] ;
V_117 = F_75 ( V_67 , V_469 ) ;
#ifdef F_79
if ( V_117 < sizeof( * V_116 ) ) {
F_30 ( V_470 || V_469 != V_65 -> V_84 [ 0 ] ) ;
V_29 = F_85 ( V_109 , V_63 , V_65 ,
V_467 , 0 ) ;
if ( V_29 < 0 ) {
F_146 ( V_109 , V_63 , V_29 ) ;
goto V_73;
}
F_43 ( V_65 ) ;
V_65 -> V_201 = 1 ;
V_21 . V_22 = V_27 ;
V_21 . type = V_77 ;
V_21 . V_33 = V_36 ;
V_29 = F_37 ( V_109 , V_63 , & V_21 , V_65 ,
- 1 , 1 ) ;
if ( V_29 ) {
F_180 ( V_13 , L_11 ,
V_29 , V_27 ) ;
F_360 ( V_63 , V_65 -> V_83 [ 0 ] ) ;
}
if ( V_29 < 0 ) {
F_146 ( V_109 , V_63 , V_29 ) ;
goto V_73;
}
V_469 = V_65 -> V_84 [ 0 ] ;
V_67 = V_65 -> V_83 [ 0 ] ;
V_117 = F_75 ( V_67 , V_469 ) ;
}
#endif
F_30 ( V_117 < sizeof( * V_116 ) ) ;
V_116 = F_76 ( V_67 , V_469 ,
struct V_115 ) ;
if ( V_467 < V_141 &&
V_21 . type == V_77 ) {
struct V_136 * V_137 ;
F_30 ( V_117 < sizeof( * V_116 ) + sizeof( * V_137 ) ) ;
V_137 = (struct V_136 * ) ( V_116 + 1 ) ;
F_8 ( V_467 != F_361 ( V_67 , V_137 ) ) ;
}
V_111 = F_77 ( V_67 , V_116 ) ;
if ( V_111 < V_157 ) {
F_180 ( V_13 , L_13
L_14 , V_157 , V_111 , V_27 ) ;
V_29 = - V_456 ;
F_146 ( V_109 , V_63 , V_29 ) ;
goto V_73;
}
V_111 -= V_157 ;
if ( V_111 > 0 ) {
if ( V_127 )
F_128 ( V_127 , V_67 , V_116 ) ;
if ( V_161 ) {
F_30 ( ! V_470 ) ;
} else {
F_88 ( V_67 , V_116 , V_111 ) ;
F_93 ( V_67 ) ;
}
if ( V_470 ) {
V_29 = F_137 ( V_109 , V_63 , V_65 ,
V_161 , V_157 ,
V_181 ) ;
if ( V_29 ) {
F_146 ( V_109 , V_63 , V_29 ) ;
goto V_73;
}
}
F_358 ( V_35 -> V_37 , - V_36 , V_467 ,
V_144 ) ;
} else {
if ( V_470 ) {
F_30 ( V_181 && V_157 !=
F_116 ( V_35 , V_65 , V_161 ) ) ;
if ( V_161 ) {
F_30 ( V_65 -> V_84 [ 0 ] != V_469 ) ;
} else {
F_30 ( V_65 -> V_84 [ 0 ] != V_469 + 1 ) ;
V_65 -> V_84 [ 0 ] = V_469 ;
V_471 = 2 ;
}
}
V_29 = F_362 ( V_109 , V_63 , V_65 , V_65 -> V_84 [ 0 ] ,
V_471 ) ;
if ( V_29 ) {
F_146 ( V_109 , V_63 , V_29 ) ;
goto V_73;
}
F_43 ( V_65 ) ;
if ( V_181 ) {
V_29 = F_163 ( V_109 , V_35 , V_27 , V_36 ) ;
if ( V_29 ) {
F_146 ( V_109 , V_63 , V_29 ) ;
goto V_73;
}
}
V_29 = F_340 ( V_35 , V_27 , V_36 , 0 ) ;
if ( V_29 ) {
F_146 ( V_109 , V_63 , V_29 ) ;
goto V_73;
}
}
V_73:
F_49 ( V_65 ) ;
return V_29 ;
}
static T_1 int F_363 ( struct V_108 * V_109 ,
struct V_34 * V_35 , T_2 V_27 )
{
struct V_112 * V_103 ;
struct V_113 * V_114 ;
struct V_202 * V_149 ;
struct V_15 * V_126 ;
int V_29 = 0 ;
V_114 = & V_109 -> V_125 -> V_114 ;
F_11 ( & V_114 -> V_52 ) ;
V_103 = F_82 ( V_109 , V_27 ) ;
if ( ! V_103 )
goto V_73;
V_126 = F_208 ( & V_103 -> V_126 . V_15 ) ;
if ( ! V_126 )
goto V_73;
V_149 = F_12 ( V_126 , struct V_202 , V_15 ) ;
if ( V_149 -> V_27 == V_27 )
goto V_73;
if ( V_103 -> V_127 ) {
if ( ! V_103 -> V_214 )
goto V_73;
F_173 ( V_103 -> V_127 ) ;
V_103 -> V_127 = NULL ;
}
if ( ! F_83 ( & V_103 -> V_79 ) )
goto V_73;
V_103 -> V_126 . V_217 = 0 ;
F_175 ( & V_103 -> V_126 . V_15 , & V_114 -> V_35 ) ;
V_114 -> V_218 -- ;
V_114 -> V_233 -- ;
if ( F_165 ( & V_103 -> V_212 ) )
V_114 -> V_216 -- ;
F_171 ( & V_103 -> V_212 ) ;
F_13 ( & V_114 -> V_52 ) ;
F_30 ( V_103 -> V_127 ) ;
if ( V_103 -> V_214 )
V_29 = 1 ;
F_45 ( & V_103 -> V_79 ) ;
F_84 ( & V_103 -> V_126 ) ;
return V_29 ;
V_73:
F_13 ( & V_114 -> V_52 ) ;
return 0 ;
}
void F_364 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
struct V_66 * V_251 ,
T_2 V_17 , int V_472 )
{
struct V_1 * V_2 = NULL ;
int V_473 = 1 ;
int V_29 ;
if ( V_35 -> V_247 . V_22 != V_199 ) {
V_29 = F_143 ( V_35 -> V_37 , V_109 ,
V_251 -> V_32 , V_251 -> V_49 ,
V_17 , V_35 -> V_247 . V_22 ,
F_216 ( V_251 ) ,
V_208 , NULL , 0 ) ;
F_30 ( V_29 ) ;
}
if ( ! V_472 )
return;
V_2 = F_66 ( V_35 -> V_37 , V_251 -> V_32 ) ;
if ( F_365 ( V_251 ) == V_109 -> V_270 ) {
if ( V_35 -> V_247 . V_22 != V_199 ) {
V_29 = F_363 ( V_109 , V_35 , V_251 -> V_32 ) ;
if ( ! V_29 )
goto V_73;
}
if ( F_366 ( V_251 , V_474 ) ) {
F_346 ( V_35 , V_2 , V_251 -> V_32 , V_251 -> V_49 , 1 ) ;
goto V_73;
}
F_8 ( F_335 ( V_475 , & V_251 -> V_476 ) ) ;
F_29 ( V_2 , V_251 -> V_32 , V_251 -> V_49 ) ;
F_351 ( V_2 , V_251 -> V_49 , V_461 ) ;
V_473 = 0 ;
}
V_73:
if ( V_473 )
F_358 ( V_35 -> V_37 , V_251 -> V_49 ,
F_216 ( V_251 ) ,
V_35 -> V_247 . V_22 ) ;
F_367 ( V_477 , & V_251 -> V_476 ) ;
F_6 ( V_2 ) ;
}
int V_257 ( struct V_108 * V_109 , struct V_34 * V_35 ,
T_2 V_27 , T_2 V_36 , T_2 V_17 , T_2 V_144 ,
T_2 V_131 , T_2 V_33 , int V_198 )
{
int V_29 ;
struct V_12 * V_37 = V_35 -> V_37 ;
F_358 ( V_35 -> V_37 , V_36 , V_131 , V_144 ) ;
if ( V_144 == V_199 ) {
F_8 ( V_131 >= V_141 ) ;
F_162 ( V_35 , V_27 , V_36 , 1 ) ;
V_29 = 0 ;
} else if ( V_131 < V_141 ) {
V_29 = F_143 ( V_37 , V_109 , V_27 ,
V_36 ,
V_17 , V_144 , ( int ) V_131 ,
V_208 , NULL , V_198 ) ;
} else {
V_29 = F_144 ( V_37 , V_109 , V_27 ,
V_36 ,
V_17 , V_144 , V_131 ,
V_33 , V_208 ,
NULL , V_198 ) ;
}
return V_29 ;
}
static T_2 F_368 ( struct V_34 * V_35 ,
struct V_1 * V_2 ,
T_2 V_228 , T_2 V_36 )
{
T_2 V_29 = F_264 ( V_228 , V_35 -> V_478 ) ;
return V_29 ;
}
static T_1 void
F_369 ( struct V_1 * V_2 ,
T_2 V_36 )
{
struct V_50 * V_54 ;
V_54 = F_25 ( V_2 ) ;
if ( ! V_54 )
return;
F_292 ( V_54 -> V_89 , F_1 ( V_2 ) ||
( V_2 -> V_11 -> V_479 >= V_36 ) ) ;
F_26 ( V_54 ) ;
}
static T_1 int
F_370 ( struct V_1 * V_2 )
{
struct V_50 * V_54 ;
int V_29 = 0 ;
V_54 = F_25 ( V_2 ) ;
if ( ! V_54 )
return ( V_2 -> V_3 == V_5 ) ? - V_172 : 0 ;
F_292 ( V_54 -> V_89 , F_1 ( V_2 ) ) ;
if ( V_2 -> V_3 == V_5 )
V_29 = - V_172 ;
F_26 ( V_54 ) ;
return V_29 ;
}
int F_371 ( T_2 V_7 )
{
if ( V_7 & V_285 )
return V_480 ;
else if ( V_7 & V_284 )
return V_481 ;
else if ( V_7 & V_283 )
return V_482 ;
else if ( V_7 & V_324 )
return V_483 ;
else if ( V_7 & V_325 )
return V_484 ;
else if ( V_7 & V_326 )
return V_485 ;
return V_486 ;
}
static int F_372 ( struct V_1 * V_2 )
{
return F_371 ( V_2 -> V_7 ) ;
}
static T_1 int F_373 ( struct V_34 * V_487 ,
T_2 V_36 , T_2 V_488 ,
T_2 V_489 , struct V_68 * V_205 ,
T_2 V_7 )
{
int V_29 = 0 ;
struct V_34 * V_35 = V_487 -> V_37 -> V_63 ;
struct V_490 * V_491 = NULL ;
struct V_1 * V_14 = NULL ;
struct V_1 * V_492 ;
T_2 V_455 = 0 ;
T_2 V_493 = 0 ;
int V_494 = 2 * 1024 * 1024 ;
struct V_101 * V_104 ;
int V_495 = 0 ;
int V_496 = F_371 ( V_7 ) ;
int V_497 = ( V_7 & V_300 ) ?
V_498 : V_462 ;
bool V_499 = false ;
bool V_500 = false ;
bool V_501 = false ;
bool V_502 = true ;
bool V_503 = false ;
F_8 ( V_36 < V_35 -> V_332 ) ;
F_374 ( V_205 , V_77 ) ;
V_205 -> V_22 = 0 ;
V_205 -> V_33 = 0 ;
F_375 ( V_487 , V_36 , V_488 , V_7 ) ;
V_104 = F_67 ( V_35 -> V_37 , V_7 ) ;
if ( ! V_104 ) {
F_180 ( V_35 -> V_37 , L_15 , V_7 ) ;
return - V_338 ;
}
if ( F_282 ( V_104 ) )
V_502 = false ;
if ( V_7 & V_306 && V_502 ) {
V_491 = & V_35 -> V_37 -> V_504 ;
if ( ! F_240 ( V_35 , V_505 ) )
V_494 = 64 * 1024 ;
}
if ( ( V_7 & V_300 ) && V_502 &&
F_240 ( V_35 , V_505 ) ) {
V_491 = & V_35 -> V_37 -> V_506 ;
}
if ( V_491 ) {
F_11 ( & V_491 -> V_52 ) ;
if ( V_491 -> V_14 )
V_489 = V_491 -> V_507 ;
F_13 ( & V_491 -> V_52 ) ;
}
V_455 = F_376 ( V_455 , V_26 ( V_35 , 0 ) ) ;
V_455 = F_376 ( V_455 , V_489 ) ;
if ( ! V_491 )
V_494 = 0 ;
if ( V_455 == V_489 ) {
V_14 = F_66 ( V_35 -> V_37 ,
V_455 ) ;
V_492 = V_14 ;
if ( V_14 && F_3 ( V_14 , V_7 ) &&
V_14 -> V_3 != V_95 ) {
F_36 ( & V_104 -> V_291 ) ;
if ( F_165 ( & V_14 -> V_91 ) ||
V_14 -> V_268 ) {
F_6 ( V_14 ) ;
F_44 ( & V_104 -> V_291 ) ;
} else {
V_496 = F_372 ( V_14 ) ;
goto V_508;
}
} else if ( V_14 ) {
F_6 ( V_14 ) ;
}
}
V_509:
V_503 = false ;
F_36 ( & V_104 -> V_291 ) ;
F_377 (block_group, &space_info->block_groups[index],
list) {
T_2 V_33 ;
int V_3 ;
V_492 = V_14 ;
F_4 ( V_14 ) ;
V_455 = V_14 -> V_21 . V_22 ;
if ( ! F_3 ( V_14 , V_7 ) ) {
T_2 V_510 = V_283 |
V_284 |
V_325 |
V_326 |
V_285 ;
if ( ( V_7 & V_510 ) && ! ( V_14 -> V_7 & V_510 ) )
goto V_495;
}
V_508:
V_3 = F_1 ( V_14 ) ;
if ( F_299 ( ! V_3 ) ) {
V_499 = true ;
V_29 = F_50 ( V_14 , 0 ) ;
F_30 ( V_29 < 0 ) ;
V_29 = 0 ;
}
if ( F_299 ( V_14 -> V_3 == V_5 ) )
goto V_495;
if ( F_299 ( V_14 -> V_268 ) )
goto V_495;
if ( V_491 ) {
unsigned long V_511 ;
F_11 ( & V_491 -> V_512 ) ;
V_492 = V_491 -> V_14 ;
if ( V_492 != V_14 &&
( ! V_492 ||
V_492 -> V_268 ||
! F_3 ( V_492 , V_7 ) ) ) {
V_492 = V_14 ;
goto V_513;
}
if ( V_492 != V_14 )
F_4 ( V_492 ) ;
V_33 = F_378 ( V_492 ,
V_491 ,
V_36 ,
V_492 -> V_21 . V_22 ,
& V_493 ) ;
if ( V_33 ) {
F_13 ( & V_491 -> V_512 ) ;
F_379 ( V_35 ,
V_14 , V_455 , V_36 ) ;
goto V_514;
}
F_8 ( V_491 -> V_14 != V_492 ) ;
if ( V_492 != V_14 ) {
F_6 ( V_492 ) ;
V_492 = V_14 ;
}
V_513:
F_30 ( V_492 != V_14 ) ;
if ( V_495 >= V_515 &&
V_491 -> V_14 != V_14 ) {
F_13 ( & V_491 -> V_512 ) ;
goto V_516;
}
F_380 ( NULL , V_491 ) ;
if ( V_495 >= V_515 ) {
F_13 ( & V_491 -> V_512 ) ;
goto V_516;
}
V_511 = F_34 (unsigned long,
empty_cluster + empty_size,
block_group->full_stripe_len) ;
V_29 = F_381 ( V_35 , V_14 ,
V_491 , V_455 ,
V_36 ,
V_511 ) ;
if ( V_29 == 0 ) {
V_33 = F_378 ( V_14 ,
V_491 ,
V_36 ,
V_455 ,
& V_493 ) ;
if ( V_33 ) {
F_13 ( & V_491 -> V_512 ) ;
F_379 ( V_35 ,
V_14 , V_455 ,
V_36 ) ;
goto V_514;
}
} else if ( ! V_3 && V_495 > V_517
&& ! V_500 ) {
F_13 ( & V_491 -> V_512 ) ;
V_500 = true ;
F_369 ( V_14 ,
V_36 + V_494 + V_488 ) ;
goto V_508;
}
F_380 ( NULL , V_491 ) ;
F_13 ( & V_491 -> V_512 ) ;
goto V_495;
}
V_516:
F_11 ( & V_14 -> V_11 -> V_518 ) ;
if ( V_3 &&
V_14 -> V_11 -> V_479 <
V_36 + V_494 + V_488 ) {
if ( V_14 -> V_11 -> V_479 >
V_493 )
V_493 =
V_14 -> V_11 -> V_479 ;
F_13 ( & V_14 -> V_11 -> V_518 ) ;
goto V_495;
}
F_13 ( & V_14 -> V_11 -> V_518 ) ;
V_33 = F_382 ( V_14 , V_455 ,
V_36 , V_488 ,
& V_493 ) ;
if ( ! V_33 && ! V_501 && ! V_3 &&
V_495 > V_517 ) {
F_369 ( V_14 ,
V_36 + V_488 ) ;
V_501 = true ;
goto V_508;
} else if ( ! V_33 ) {
if ( ! V_3 )
V_503 = true ;
goto V_495;
}
V_514:
V_455 = F_368 ( V_35 , V_492 ,
V_33 , V_36 ) ;
if ( V_455 + V_36 >
V_492 -> V_21 . V_22 + V_492 -> V_21 . V_33 ) {
F_29 ( V_492 , V_33 , V_36 ) ;
goto V_495;
}
if ( V_33 < V_455 )
F_29 ( V_492 , V_33 ,
V_455 - V_33 ) ;
F_30 ( V_33 > V_455 ) ;
V_29 = F_351 ( V_492 , V_36 ,
V_497 ) ;
if ( V_29 == - V_175 ) {
F_29 ( V_492 , V_33 , V_36 ) ;
goto V_495;
}
V_205 -> V_22 = V_455 ;
V_205 -> V_33 = V_36 ;
F_383 ( V_487 , V_14 ,
V_455 , V_36 ) ;
if ( V_492 != V_14 )
F_6 ( V_492 ) ;
F_6 ( V_14 ) ;
break;
V_495:
V_500 = false ;
V_501 = false ;
F_30 ( V_496 != F_372 ( V_14 ) ) ;
if ( V_492 != V_14 )
F_6 ( V_492 ) ;
F_6 ( V_14 ) ;
}
F_44 ( & V_104 -> V_291 ) ;
if ( ! V_205 -> V_22 && V_495 >= V_519 && V_503 )
goto V_509;
if ( ! V_205 -> V_22 && ++ V_496 < V_289 )
goto V_509;
if ( ! V_205 -> V_22 && V_495 < V_515 ) {
V_496 = 0 ;
V_495 ++ ;
if ( V_495 == V_520 ) {
struct V_108 * V_109 ;
V_109 = F_265 ( V_35 ) ;
if ( F_232 ( V_109 ) ) {
V_29 = F_233 ( V_109 ) ;
goto V_73;
}
V_29 = F_266 ( V_109 , V_35 , V_7 ,
V_337 ) ;
if ( V_29 < 0 && V_29 != - V_338 )
F_146 ( V_109 ,
V_35 , V_29 ) ;
else
V_29 = 0 ;
F_267 ( V_109 , V_35 ) ;
if ( V_29 )
goto V_73;
}
if ( V_495 == V_515 ) {
V_488 = 0 ;
V_494 = 0 ;
}
goto V_509;
} else if ( ! V_205 -> V_22 ) {
V_29 = - V_338 ;
} else if ( V_205 -> V_22 ) {
V_29 = 0 ;
}
V_73:
if ( V_29 == - V_338 )
V_205 -> V_33 = V_493 ;
return V_29 ;
}
static void F_280 ( struct V_101 * V_13 , T_2 V_328 ,
int V_521 )
{
struct V_1 * V_2 ;
int V_496 = 0 ;
F_11 ( & V_13 -> V_52 ) ;
F_384 ( V_522 L_16 ,
V_13 -> V_7 ,
V_13 -> V_280 - V_13 -> V_281 - V_13 -> V_292 -
V_13 -> V_293 - V_13 -> V_294 ,
( V_13 -> V_107 ) ? L_4 : L_17 ) ;
F_384 ( V_522 L_18
L_19 ,
V_13 -> V_280 , V_13 -> V_281 , V_13 -> V_292 ,
V_13 -> V_293 , V_13 -> V_295 ,
V_13 -> V_294 ) ;
F_13 ( & V_13 -> V_52 ) ;
if ( ! V_521 )
return;
F_36 ( & V_13 -> V_291 ) ;
V_78:
F_377 (cache, &info->block_groups[index], list) {
F_11 ( & V_2 -> V_52 ) ;
F_384 ( V_522 L_20 ,
V_2 -> V_21 . V_22 , V_2 -> V_21 . V_33 ,
F_343 ( & V_2 -> V_133 ) , V_2 -> V_9 ,
V_2 -> V_10 , V_2 -> V_268 ? L_21 : L_4 ) ;
F_385 ( V_2 , V_328 ) ;
F_13 ( & V_2 -> V_52 ) ;
}
if ( ++ V_496 < V_289 )
goto V_78;
F_44 ( & V_13 -> V_291 ) ;
}
int F_386 ( struct V_34 * V_35 ,
T_2 V_36 , T_2 V_523 ,
T_2 V_488 , T_2 V_489 ,
struct V_68 * V_205 , int V_181 )
{
bool V_524 = false ;
T_2 V_7 ;
int V_29 ;
V_7 = F_263 ( V_35 , V_181 ) ;
V_78:
F_8 ( V_36 < V_35 -> V_332 ) ;
V_29 = F_373 ( V_35 , V_36 , V_488 , V_489 , V_205 ,
V_7 ) ;
if ( V_29 == - V_338 ) {
if ( ! V_524 && V_205 -> V_33 ) {
V_36 = F_291 ( V_36 >> 1 , V_205 -> V_33 ) ;
V_36 = F_387 ( V_36 , V_35 -> V_332 ) ;
V_36 = F_376 ( V_36 , V_523 ) ;
if ( V_36 == V_523 )
V_524 = true ;
goto V_78;
} else if ( F_240 ( V_35 , V_350 ) ) {
struct V_101 * V_342 ;
V_342 = F_67 ( V_35 -> V_37 , V_7 ) ;
F_180 ( V_35 -> V_37 , L_22 ,
V_7 , V_36 ) ;
if ( V_342 )
F_280 ( V_342 , V_36 , 1 ) ;
}
}
F_388 ( V_35 , V_205 -> V_22 , V_205 -> V_33 ) ;
return V_29 ;
}
static int F_389 ( struct V_34 * V_35 ,
T_2 V_32 , T_2 V_49 , int V_473 )
{
struct V_1 * V_2 ;
int V_29 = 0 ;
V_2 = F_66 ( V_35 -> V_37 , V_32 ) ;
if ( ! V_2 ) {
F_180 ( V_35 -> V_37 , L_23 ,
V_32 ) ;
return - V_338 ;
}
if ( F_240 ( V_35 , V_465 ) )
V_29 = F_140 ( V_35 , V_32 , V_49 , NULL ) ;
if ( V_473 )
F_346 ( V_35 , V_2 , V_32 , V_49 , 1 ) ;
else {
F_29 ( V_2 , V_32 , V_49 ) ;
F_351 ( V_2 , V_49 , V_461 ) ;
}
F_6 ( V_2 ) ;
F_390 ( V_35 , V_32 , V_49 ) ;
return V_29 ;
}
int F_391 ( struct V_34 * V_35 ,
T_2 V_32 , T_2 V_49 )
{
return F_389 ( V_35 , V_32 , V_49 , 0 ) ;
}
int F_392 ( struct V_34 * V_35 ,
T_2 V_32 , T_2 V_49 )
{
return F_389 ( V_35 , V_32 , V_49 , 1 ) ;
}
static int F_150 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
T_2 V_17 , T_2 V_144 ,
T_2 V_7 , T_2 V_131 , T_2 V_33 ,
struct V_68 * V_205 , int V_130 )
{
int V_29 ;
struct V_12 * V_37 = V_35 -> V_37 ;
struct V_115 * V_525 ;
struct V_160 * V_161 ;
struct V_64 * V_65 ;
struct V_66 * V_67 ;
int type ;
T_3 V_57 ;
if ( V_17 > 0 )
type = V_152 ;
else
type = V_153 ;
V_57 = sizeof( * V_525 ) + F_123 ( type ) ;
V_65 = F_33 () ;
if ( ! V_65 )
return - V_72 ;
V_65 -> V_201 = 1 ;
V_29 = F_104 ( V_109 , V_37 -> V_63 , V_65 ,
V_205 , V_57 ) ;
if ( V_29 ) {
F_49 ( V_65 ) ;
return V_29 ;
}
V_67 = V_65 -> V_83 [ 0 ] ;
V_525 = F_76 ( V_67 , V_65 -> V_84 [ 0 ] ,
struct V_115 ) ;
F_88 ( V_67 , V_525 , V_130 ) ;
F_89 ( V_67 , V_525 , V_109 -> V_270 ) ;
F_90 ( V_67 , V_525 ,
V_7 | V_143 ) ;
V_161 = (struct V_160 * ) ( V_525 + 1 ) ;
F_130 ( V_67 , V_161 , type ) ;
if ( V_17 > 0 ) {
struct V_156 * V_149 ;
V_149 = (struct V_156 * ) ( V_161 + 1 ) ;
F_131 ( V_67 , V_161 , V_17 ) ;
F_105 ( V_67 , V_149 , V_130 ) ;
} else {
struct V_148 * V_149 ;
V_149 = (struct V_148 * ) ( & V_161 -> V_33 ) ;
F_107 ( V_67 , V_149 , V_144 ) ;
F_108 ( V_67 , V_149 , V_131 ) ;
F_109 ( V_67 , V_149 , V_33 ) ;
F_110 ( V_67 , V_149 , V_130 ) ;
}
F_93 ( V_65 -> V_83 [ 0 ] ) ;
F_49 ( V_65 ) ;
V_29 = F_340 ( V_35 , V_205 -> V_22 , V_205 -> V_33 , 1 ) ;
if ( V_29 ) {
F_180 ( V_37 , L_24 ,
V_205 -> V_22 , V_205 -> V_33 ) ;
F_81 () ;
}
return V_29 ;
}
static int F_157 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
T_2 V_17 , T_2 V_144 ,
T_2 V_7 , struct V_440 * V_21 ,
int V_164 , struct V_68 * V_205 )
{
int V_29 ;
struct V_12 * V_37 = V_35 -> V_37 ;
struct V_115 * V_525 ;
struct V_136 * V_526 ;
struct V_160 * V_161 ;
struct V_64 * V_65 ;
struct V_66 * V_67 ;
T_3 V_57 = sizeof( * V_525 ) + sizeof( * V_161 ) ;
bool V_170 = F_74 ( V_35 -> V_37 ,
V_120 ) ;
if ( ! V_170 )
V_57 += sizeof( * V_526 ) ;
V_65 = F_33 () ;
if ( ! V_65 )
return - V_72 ;
V_65 -> V_201 = 1 ;
V_29 = F_104 ( V_109 , V_37 -> V_63 , V_65 ,
V_205 , V_57 ) ;
if ( V_29 ) {
F_49 ( V_65 ) ;
return V_29 ;
}
V_67 = V_65 -> V_83 [ 0 ] ;
V_525 = F_76 ( V_67 , V_65 -> V_84 [ 0 ] ,
struct V_115 ) ;
F_88 ( V_67 , V_525 , 1 ) ;
F_89 ( V_67 , V_525 , V_109 -> V_270 ) ;
F_90 ( V_67 , V_525 ,
V_7 | V_142 ) ;
if ( V_170 ) {
V_161 = (struct V_160 * ) ( V_525 + 1 ) ;
} else {
V_526 = (struct V_136 * ) ( V_525 + 1 ) ;
F_152 ( V_67 , V_526 , V_21 ) ;
F_92 ( V_67 , V_526 , V_164 ) ;
V_161 = (struct V_160 * ) ( V_526 + 1 ) ;
}
if ( V_17 > 0 ) {
F_30 ( ! ( V_7 & V_124 ) ) ;
F_130 ( V_67 , V_161 ,
V_162 ) ;
F_131 ( V_67 , V_161 , V_17 ) ;
} else {
F_130 ( V_67 , V_161 ,
V_163 ) ;
F_131 ( V_67 , V_161 , V_144 ) ;
}
F_93 ( V_67 ) ;
F_49 ( V_65 ) ;
V_29 = F_340 ( V_35 , V_205 -> V_22 , V_35 -> V_88 , 1 ) ;
if ( V_29 ) {
F_180 ( V_37 , L_24 ,
V_205 -> V_22 , V_205 -> V_33 ) ;
F_81 () ;
}
return V_29 ;
}
int F_393 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
T_2 V_144 , T_2 V_131 ,
T_2 V_33 , struct V_68 * V_205 )
{
int V_29 ;
F_30 ( V_144 == V_199 ) ;
V_29 = F_144 ( V_35 -> V_37 , V_109 , V_205 -> V_22 ,
V_205 -> V_33 , 0 ,
V_144 , V_131 , V_33 ,
V_219 , NULL , 0 ) ;
return V_29 ;
}
int F_394 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
T_2 V_144 , T_2 V_131 , T_2 V_33 ,
struct V_68 * V_205 )
{
int V_29 ;
struct V_1 * V_14 ;
if ( ! F_74 ( V_35 -> V_37 , V_460 ) ) {
V_29 = F_349 ( V_35 , V_205 -> V_22 , V_205 -> V_33 ) ;
if ( V_29 )
return V_29 ;
}
V_14 = F_66 ( V_35 -> V_37 , V_205 -> V_22 ) ;
if ( ! V_14 )
return - V_456 ;
V_29 = F_351 ( V_14 , V_205 -> V_33 ,
V_498 ) ;
F_30 ( V_29 ) ;
V_29 = F_150 ( V_109 , V_35 , 0 , V_144 ,
0 , V_131 , V_33 , V_205 , 1 ) ;
F_6 ( V_14 ) ;
return V_29 ;
}
static struct V_66 *
F_395 ( struct V_108 * V_109 , struct V_34 * V_35 ,
T_2 V_27 , T_3 V_527 , int V_164 )
{
struct V_66 * V_251 ;
V_251 = F_396 ( V_35 , V_27 , V_527 ) ;
if ( ! V_251 )
return F_397 ( - V_72 ) ;
F_398 ( V_251 , V_109 -> V_270 ) ;
F_399 ( V_35 -> V_247 . V_22 , V_251 , V_164 ) ;
F_400 ( V_251 ) ;
F_401 ( V_109 , V_35 , V_251 ) ;
F_367 ( V_528 , & V_251 -> V_476 ) ;
F_402 ( V_251 ) ;
F_403 ( V_251 ) ;
if ( V_35 -> V_247 . V_22 == V_199 ) {
if ( V_35 -> V_529 % 2 == 0 )
F_345 ( & V_35 -> V_530 , V_251 -> V_32 ,
V_251 -> V_32 + V_251 -> V_49 - 1 , V_40 ) ;
else
F_404 ( & V_35 -> V_530 , V_251 -> V_32 ,
V_251 -> V_32 + V_251 -> V_49 - 1 , V_40 ) ;
} else {
F_345 ( & V_109 -> V_125 -> V_531 , V_251 -> V_32 ,
V_251 -> V_32 + V_251 -> V_49 - 1 , V_40 ) ;
}
V_109 -> V_532 ++ ;
return V_251 ;
}
static struct V_231 *
F_405 ( struct V_108 * V_109 ,
struct V_34 * V_35 , T_3 V_527 )
{
struct V_231 * V_373 ;
struct V_231 * V_232 = & V_35 -> V_37 -> V_234 ;
int V_29 ;
bool V_533 = false ;
V_373 = F_302 ( V_109 , V_35 ) ;
if ( F_299 ( V_373 -> V_57 == 0 ) )
goto V_534;
V_78:
V_29 = F_300 ( V_373 , V_527 ) ;
if ( ! V_29 )
return V_373 ;
if ( V_373 -> V_535 )
return F_397 ( V_29 ) ;
if ( V_373 -> type == V_536 && ! V_533 ) {
V_533 = true ;
F_318 ( V_35 -> V_37 ) ;
goto V_78;
}
if ( F_240 ( V_35 , V_350 ) ) {
static F_406 ( V_537 ,
V_538 * 10 ,
1 ) ;
if ( F_407 ( & V_537 ) )
F_408 ( 1 , V_539
L_25 , V_29 ) ;
}
V_534:
V_29 = F_297 ( V_35 , V_373 , V_527 ,
V_381 ) ;
if ( ! V_29 )
return V_373 ;
if ( V_373 -> type != V_536 &&
V_373 -> V_104 == V_232 -> V_104 ) {
V_29 = F_300 ( V_232 , V_527 ) ;
if ( ! V_29 )
return V_232 ;
}
return F_397 ( V_29 ) ;
}
static void F_409 ( struct V_12 * V_37 ,
struct V_231 * V_373 , T_3 V_527 )
{
F_303 ( V_373 , V_527 , 0 ) ;
F_305 ( V_37 , V_373 , NULL , 0 ) ;
}
struct V_66 * F_410 ( struct V_108 * V_109 ,
struct V_34 * V_35 , T_3 V_527 ,
T_2 V_17 , T_2 V_144 ,
struct V_440 * V_21 , int V_164 ,
T_2 V_540 , T_2 V_488 )
{
struct V_68 V_205 ;
struct V_231 * V_373 ;
struct V_66 * V_251 ;
T_2 V_7 = 0 ;
int V_29 ;
bool V_170 = F_74 ( V_35 -> V_37 ,
V_120 ) ;
V_373 = F_405 ( V_109 , V_35 , V_527 ) ;
if ( F_232 ( V_373 ) )
return F_411 ( V_373 ) ;
V_29 = F_386 ( V_35 , V_527 , V_527 ,
V_488 , V_540 , & V_205 , 0 ) ;
if ( V_29 ) {
F_409 ( V_35 -> V_37 , V_373 , V_527 ) ;
return F_397 ( V_29 ) ;
}
V_251 = F_395 ( V_109 , V_35 , V_205 . V_22 ,
V_527 , V_164 ) ;
F_30 ( F_232 ( V_251 ) ) ;
if ( V_144 == V_541 ) {
if ( V_17 == 0 )
V_17 = V_205 . V_22 ;
V_7 |= V_124 ;
} else
F_30 ( V_17 > 0 ) ;
if ( V_144 != V_199 ) {
struct V_177 * V_127 ;
V_127 = F_205 () ;
F_30 ( ! V_127 ) ;
if ( V_21 )
memcpy ( & V_127 -> V_21 , V_21 , sizeof( V_127 -> V_21 ) ) ;
else
memset ( & V_127 -> V_21 , 0 , sizeof( V_127 -> V_21 ) ) ;
V_127 -> V_129 = V_7 ;
if ( V_170 )
V_127 -> V_209 = 0 ;
else
V_127 -> V_209 = 1 ;
V_127 -> V_128 = 1 ;
V_127 -> V_181 = 0 ;
V_127 -> V_164 = V_164 ;
V_29 = F_143 ( V_35 -> V_37 , V_109 ,
V_205 . V_22 ,
V_205 . V_33 , V_17 , V_144 ,
V_164 , V_219 ,
V_127 , 0 ) ;
F_30 ( V_29 ) ;
}
return V_251 ;
}
static T_1 void F_412 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
struct V_542 * V_543 ,
struct V_64 * V_65 )
{
T_2 V_27 ;
T_2 V_273 ;
T_2 V_111 ;
T_2 V_7 ;
T_3 V_71 ;
T_3 V_527 ;
struct V_68 V_21 ;
struct V_66 * V_458 ;
int V_29 ;
int V_544 ;
int V_545 = 0 ;
if ( V_65 -> V_84 [ V_543 -> V_164 ] < V_543 -> V_546 ) {
V_543 -> V_547 = V_543 -> V_547 * 2 / 3 ;
V_543 -> V_547 = F_376 ( V_543 -> V_547 , 2 ) ;
} else {
V_543 -> V_547 = V_543 -> V_547 * 3 / 2 ;
V_543 -> V_547 = F_24 ( int , V_543 -> V_547 ,
F_413 ( V_35 ) ) ;
}
V_458 = V_65 -> V_83 [ V_543 -> V_164 ] ;
V_71 = F_38 ( V_458 ) ;
V_527 = F_223 ( V_35 , V_543 -> V_164 - 1 ) ;
for ( V_544 = V_65 -> V_84 [ V_543 -> V_164 ] ; V_544 < V_71 ; V_544 ++ ) {
if ( V_545 >= V_543 -> V_547 )
break;
F_46 () ;
V_27 = F_222 ( V_458 , V_544 ) ;
V_273 = F_414 ( V_458 , V_544 ) ;
if ( V_544 == V_65 -> V_84 [ V_543 -> V_164 ] )
goto V_76;
if ( V_543 -> V_548 == V_549 &&
V_273 <= V_35 -> V_247 . V_33 )
continue;
V_29 = F_73 ( V_109 , V_35 , V_27 ,
V_543 -> V_164 - 1 , 1 , & V_111 ,
& V_7 ) ;
if ( V_29 < 0 )
continue;
F_30 ( V_111 == 0 ) ;
if ( V_543 -> V_548 == V_550 ) {
if ( V_111 == 1 )
goto V_76;
if ( V_543 -> V_164 == 1 &&
( V_7 & V_124 ) )
continue;
if ( ! V_543 -> V_551 ||
V_273 <= V_35 -> V_247 . V_33 )
continue;
F_121 ( V_458 , & V_21 , V_544 ) ;
V_29 = F_415 ( & V_21 ,
& V_543 -> V_552 ) ;
if ( V_29 < 0 )
continue;
} else {
if ( V_543 -> V_164 == 1 &&
( V_7 & V_124 ) )
continue;
}
V_76:
V_29 = F_416 ( V_35 , V_27 , V_527 ,
V_273 ) ;
if ( V_29 )
break;
V_545 ++ ;
}
V_543 -> V_546 = V_544 ;
}
static T_1 int F_417 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
struct V_64 * V_65 ,
struct V_542 * V_543 , int V_553 )
{
int V_164 = V_543 -> V_164 ;
struct V_66 * V_458 = V_65 -> V_83 [ V_164 ] ;
T_2 V_554 = V_124 ;
int V_29 ;
if ( V_543 -> V_548 == V_549 &&
F_215 ( V_458 ) != V_35 -> V_247 . V_22 )
return 1 ;
if ( V_553 &&
( ( V_543 -> V_548 == V_550 && V_543 -> V_111 [ V_164 ] != 1 ) ||
( V_543 -> V_548 == V_549 && ! ( V_543 -> V_7 [ V_164 ] & V_554 ) ) ) ) {
F_30 ( ! V_65 -> V_555 [ V_164 ] ) ;
V_29 = F_73 ( V_109 , V_35 ,
V_458 -> V_32 , V_164 , 1 ,
& V_543 -> V_111 [ V_164 ] ,
& V_543 -> V_7 [ V_164 ] ) ;
F_30 ( V_29 == - V_72 ) ;
if ( V_29 )
return V_29 ;
F_30 ( V_543 -> V_111 [ V_164 ] == 0 ) ;
}
if ( V_543 -> V_548 == V_550 ) {
if ( V_543 -> V_111 [ V_164 ] > 1 )
return 1 ;
if ( V_65 -> V_555 [ V_164 ] && ! V_543 -> V_171 ) {
F_418 ( V_458 , V_65 -> V_555 [ V_164 ] ) ;
V_65 -> V_555 [ V_164 ] = 0 ;
}
return 0 ;
}
if ( ! ( V_543 -> V_7 [ V_164 ] & V_554 ) ) {
F_30 ( ! V_65 -> V_555 [ V_164 ] ) ;
V_29 = F_224 ( V_109 , V_35 , V_458 , 1 , V_543 -> V_556 ) ;
F_30 ( V_29 ) ;
V_29 = F_225 ( V_109 , V_35 , V_458 , 0 , V_543 -> V_556 ) ;
F_30 ( V_29 ) ;
V_29 = F_204 ( V_109 , V_35 , V_458 -> V_32 ,
V_458 -> V_49 , V_554 ,
F_216 ( V_458 ) , 0 ) ;
F_30 ( V_29 ) ;
V_543 -> V_7 [ V_164 ] |= V_554 ;
}
if ( V_65 -> V_555 [ V_164 ] && V_164 > 0 ) {
F_418 ( V_458 , V_65 -> V_555 [ V_164 ] ) ;
V_65 -> V_555 [ V_164 ] = 0 ;
}
return 0 ;
}
static T_1 int F_419 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
struct V_64 * V_65 ,
struct V_542 * V_543 , int * V_553 )
{
T_2 V_27 ;
T_2 V_273 ;
T_2 V_17 ;
T_3 V_527 ;
struct V_68 V_21 ;
struct V_66 * V_81 ;
int V_164 = V_543 -> V_164 ;
int V_76 = 0 ;
int V_29 = 0 ;
V_273 = F_414 ( V_65 -> V_83 [ V_164 ] ,
V_65 -> V_84 [ V_164 ] ) ;
if ( V_543 -> V_548 == V_549 &&
V_273 <= V_35 -> V_247 . V_33 ) {
* V_553 = 1 ;
return 1 ;
}
V_27 = F_222 ( V_65 -> V_83 [ V_164 ] , V_65 -> V_84 [ V_164 ] ) ;
V_527 = F_223 ( V_35 , V_164 - 1 ) ;
V_81 = F_420 ( V_35 , V_27 , V_527 ) ;
if ( ! V_81 ) {
V_81 = F_396 ( V_35 , V_27 , V_527 ) ;
if ( ! V_81 )
return - V_72 ;
F_399 ( V_35 -> V_247 . V_22 , V_81 ,
V_164 - 1 ) ;
V_76 = 1 ;
}
F_400 ( V_81 ) ;
F_402 ( V_81 ) ;
V_29 = F_73 ( V_109 , V_35 , V_27 , V_164 - 1 , 1 ,
& V_543 -> V_111 [ V_164 - 1 ] ,
& V_543 -> V_7 [ V_164 - 1 ] ) ;
if ( V_29 < 0 ) {
F_421 ( V_81 ) ;
return V_29 ;
}
if ( F_299 ( V_543 -> V_111 [ V_164 - 1 ] == 0 ) ) {
F_180 ( V_35 -> V_37 , L_26 ) ;
F_81 () ;
}
* V_553 = 0 ;
if ( V_543 -> V_548 == V_550 ) {
if ( V_543 -> V_111 [ V_164 - 1 ] > 1 ) {
if ( V_164 == 1 &&
( V_543 -> V_7 [ 0 ] & V_124 ) )
goto V_557;
if ( ! V_543 -> V_551 ||
V_273 <= V_35 -> V_247 . V_33 )
goto V_557;
F_121 ( V_65 -> V_83 [ V_164 ] , & V_21 ,
V_65 -> V_84 [ V_164 ] ) ;
V_29 = F_415 ( & V_21 , & V_543 -> V_552 ) ;
if ( V_29 < 0 )
goto V_557;
V_543 -> V_548 = V_549 ;
V_543 -> V_558 = V_164 - 1 ;
}
} else {
if ( V_164 == 1 &&
( V_543 -> V_7 [ 0 ] & V_124 ) )
goto V_557;
}
if ( ! F_422 ( V_81 , V_273 , 0 ) ) {
F_421 ( V_81 ) ;
F_423 ( V_81 ) ;
V_81 = NULL ;
* V_553 = 1 ;
}
if ( ! V_81 ) {
if ( V_76 && V_164 == 1 )
F_412 ( V_109 , V_35 , V_543 , V_65 ) ;
V_81 = F_424 ( V_35 , V_27 , V_527 , V_273 ) ;
if ( ! V_81 || ! F_425 ( V_81 ) ) {
F_423 ( V_81 ) ;
return - V_172 ;
}
F_400 ( V_81 ) ;
F_402 ( V_81 ) ;
}
V_164 -- ;
F_30 ( V_164 != F_216 ( V_81 ) ) ;
V_65 -> V_83 [ V_164 ] = V_81 ;
V_65 -> V_84 [ V_164 ] = 0 ;
V_65 -> V_555 [ V_164 ] = V_559 ;
V_543 -> V_164 = V_164 ;
if ( V_543 -> V_164 == 1 )
V_543 -> V_546 = 0 ;
return 0 ;
V_557:
V_543 -> V_111 [ V_164 - 1 ] = 0 ;
V_543 -> V_7 [ V_164 - 1 ] = 0 ;
if ( V_543 -> V_548 == V_550 ) {
if ( V_543 -> V_7 [ V_164 ] & V_124 ) {
V_17 = V_65 -> V_83 [ V_164 ] -> V_32 ;
} else {
F_30 ( V_35 -> V_247 . V_22 !=
F_215 ( V_65 -> V_83 [ V_164 ] ) ) ;
V_17 = 0 ;
}
V_29 = V_257 ( V_109 , V_35 , V_27 , V_527 , V_17 ,
V_35 -> V_247 . V_22 , V_164 - 1 , 0 , 0 ) ;
F_30 ( V_29 ) ;
}
F_421 ( V_81 ) ;
F_423 ( V_81 ) ;
* V_553 = 1 ;
return 1 ;
}
static T_1 int F_426 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
struct V_64 * V_65 ,
struct V_542 * V_543 )
{
int V_29 ;
int V_164 = V_543 -> V_164 ;
struct V_66 * V_458 = V_65 -> V_83 [ V_164 ] ;
T_2 V_17 = 0 ;
if ( V_543 -> V_548 == V_549 ) {
F_30 ( V_543 -> V_558 < V_164 ) ;
if ( V_164 < V_543 -> V_558 )
goto V_73;
V_29 = F_41 ( V_65 , V_164 + 1 , & V_543 -> V_552 ) ;
if ( V_29 > 0 )
V_543 -> V_551 = 0 ;
V_543 -> V_548 = V_550 ;
V_543 -> V_558 = - 1 ;
V_65 -> V_84 [ V_164 ] = 0 ;
if ( ! V_65 -> V_555 [ V_164 ] ) {
F_30 ( V_164 == 0 ) ;
F_400 ( V_458 ) ;
F_402 ( V_458 ) ;
V_65 -> V_555 [ V_164 ] = V_559 ;
V_29 = F_73 ( V_109 , V_35 ,
V_458 -> V_32 , V_164 , 1 ,
& V_543 -> V_111 [ V_164 ] ,
& V_543 -> V_7 [ V_164 ] ) ;
if ( V_29 < 0 ) {
F_418 ( V_458 , V_65 -> V_555 [ V_164 ] ) ;
V_65 -> V_555 [ V_164 ] = 0 ;
return V_29 ;
}
F_30 ( V_543 -> V_111 [ V_164 ] == 0 ) ;
if ( V_543 -> V_111 [ V_164 ] == 1 ) {
F_418 ( V_458 , V_65 -> V_555 [ V_164 ] ) ;
V_65 -> V_555 [ V_164 ] = 0 ;
return 1 ;
}
}
}
F_30 ( V_543 -> V_111 [ V_164 ] > 1 && ! V_65 -> V_555 [ V_164 ] ) ;
if ( V_543 -> V_111 [ V_164 ] == 1 ) {
if ( V_164 == 0 ) {
if ( V_543 -> V_7 [ V_164 ] & V_124 )
V_29 = F_225 ( V_109 , V_35 , V_458 , 1 ,
V_543 -> V_556 ) ;
else
V_29 = F_225 ( V_109 , V_35 , V_458 , 0 ,
V_543 -> V_556 ) ;
F_30 ( V_29 ) ;
}
if ( ! V_65 -> V_555 [ V_164 ] &&
F_365 ( V_458 ) == V_109 -> V_270 ) {
F_400 ( V_458 ) ;
F_402 ( V_458 ) ;
V_65 -> V_555 [ V_164 ] = V_559 ;
}
F_401 ( V_109 , V_35 , V_458 ) ;
}
if ( V_458 == V_35 -> V_126 ) {
if ( V_543 -> V_7 [ V_164 ] & V_124 )
V_17 = V_458 -> V_32 ;
else
F_30 ( V_35 -> V_247 . V_22 !=
F_215 ( V_458 ) ) ;
} else {
if ( V_543 -> V_7 [ V_164 + 1 ] & V_124 )
V_17 = V_65 -> V_83 [ V_164 + 1 ] -> V_32 ;
else
F_30 ( V_35 -> V_247 . V_22 !=
F_215 ( V_65 -> V_83 [ V_164 + 1 ] ) ) ;
}
F_364 ( V_109 , V_35 , V_458 , V_17 , V_543 -> V_111 [ V_164 ] == 1 ) ;
V_73:
V_543 -> V_111 [ V_164 ] = 0 ;
V_543 -> V_7 [ V_164 ] = 0 ;
return 0 ;
}
static T_1 int F_427 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
struct V_64 * V_65 ,
struct V_542 * V_543 )
{
int V_164 = V_543 -> V_164 ;
int V_553 = 1 ;
int V_29 ;
while ( V_164 >= 0 ) {
V_29 = F_417 ( V_109 , V_35 , V_65 , V_543 , V_553 ) ;
if ( V_29 > 0 )
break;
if ( V_164 == 0 )
break;
if ( V_65 -> V_84 [ V_164 ] >=
F_38 ( V_65 -> V_83 [ V_164 ] ) )
break;
V_29 = F_419 ( V_109 , V_35 , V_65 , V_543 , & V_553 ) ;
if ( V_29 > 0 ) {
V_65 -> V_84 [ V_164 ] ++ ;
continue;
} else if ( V_29 < 0 )
return V_29 ;
V_164 = V_543 -> V_164 ;
}
return 0 ;
}
static T_1 int F_428 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
struct V_64 * V_65 ,
struct V_542 * V_543 , int V_560 )
{
int V_164 = V_543 -> V_164 ;
int V_29 ;
V_65 -> V_84 [ V_164 ] = F_38 ( V_65 -> V_83 [ V_164 ] ) ;
while ( V_164 < V_560 && V_65 -> V_83 [ V_164 ] ) {
V_543 -> V_164 = V_164 ;
if ( V_65 -> V_84 [ V_164 ] + 1 <
F_38 ( V_65 -> V_83 [ V_164 ] ) ) {
V_65 -> V_84 [ V_164 ] ++ ;
return 0 ;
} else {
V_29 = F_426 ( V_109 , V_35 , V_65 , V_543 ) ;
if ( V_29 > 0 )
return 0 ;
if ( V_65 -> V_555 [ V_164 ] ) {
F_418 ( V_65 -> V_83 [ V_164 ] ,
V_65 -> V_555 [ V_164 ] ) ;
V_65 -> V_555 [ V_164 ] = 0 ;
}
F_423 ( V_65 -> V_83 [ V_164 ] ) ;
V_65 -> V_83 [ V_164 ] = NULL ;
V_164 ++ ;
}
}
return 1 ;
}
int F_429 ( struct V_34 * V_35 ,
struct V_231 * V_373 , int V_551 ,
int V_556 )
{
struct V_64 * V_65 ;
struct V_108 * V_109 ;
struct V_34 * V_87 = V_35 -> V_37 -> V_87 ;
struct V_561 * V_248 = & V_35 -> V_248 ;
struct V_542 * V_543 ;
struct V_68 V_21 ;
int V_82 = 0 ;
int V_29 ;
int V_164 ;
bool V_562 = false ;
V_65 = F_33 () ;
if ( ! V_65 ) {
V_82 = - V_72 ;
goto V_73;
}
V_543 = F_52 ( sizeof( * V_543 ) , V_40 ) ;
if ( ! V_543 ) {
F_49 ( V_65 ) ;
V_82 = - V_72 ;
goto V_73;
}
V_109 = F_430 ( V_87 , 0 ) ;
if ( F_232 ( V_109 ) ) {
V_82 = F_233 ( V_109 ) ;
goto V_121;
}
if ( V_373 )
V_109 -> V_373 = V_373 ;
if ( F_431 ( & V_248 -> V_563 ) == 0 ) {
V_164 = F_216 ( V_35 -> V_126 ) ;
V_65 -> V_83 [ V_164 ] = F_432 ( V_35 ) ;
F_402 ( V_65 -> V_83 [ V_164 ] ) ;
V_65 -> V_84 [ V_164 ] = 0 ;
V_65 -> V_555 [ V_164 ] = V_559 ;
memset ( & V_543 -> V_552 , 0 ,
sizeof( V_543 -> V_552 ) ) ;
} else {
F_433 ( & V_21 , & V_248 -> V_563 ) ;
memcpy ( & V_543 -> V_552 , & V_21 ,
sizeof( V_543 -> V_552 ) ) ;
V_164 = V_248 -> V_564 ;
F_30 ( V_164 == 0 ) ;
V_65 -> V_565 = V_164 ;
V_29 = F_37 ( NULL , V_35 , & V_21 , V_65 , 0 , 0 ) ;
V_65 -> V_565 = 0 ;
if ( V_29 < 0 ) {
V_82 = V_29 ;
goto V_566;
}
F_8 ( V_29 > 0 ) ;
F_126 ( V_65 , 0 ) ;
V_164 = F_216 ( V_35 -> V_126 ) ;
while ( 1 ) {
F_400 ( V_65 -> V_83 [ V_164 ] ) ;
F_402 ( V_65 -> V_83 [ V_164 ] ) ;
V_65 -> V_555 [ V_164 ] = V_559 ;
V_29 = F_73 ( V_109 , V_35 ,
V_65 -> V_83 [ V_164 ] -> V_32 ,
V_164 , 1 , & V_543 -> V_111 [ V_164 ] ,
& V_543 -> V_7 [ V_164 ] ) ;
if ( V_29 < 0 ) {
V_82 = V_29 ;
goto V_566;
}
F_30 ( V_543 -> V_111 [ V_164 ] == 0 ) ;
if ( V_164 == V_248 -> V_564 )
break;
F_421 ( V_65 -> V_83 [ V_164 ] ) ;
V_65 -> V_555 [ V_164 ] = 0 ;
F_8 ( V_543 -> V_111 [ V_164 ] != 1 ) ;
V_164 -- ;
}
}
V_543 -> V_164 = V_164 ;
V_543 -> V_558 = - 1 ;
V_543 -> V_548 = V_550 ;
V_543 -> V_551 = V_551 ;
V_543 -> V_171 = 0 ;
V_543 -> V_556 = V_556 ;
V_543 -> V_547 = F_413 ( V_35 ) ;
while ( 1 ) {
V_29 = F_427 ( V_109 , V_35 , V_65 , V_543 ) ;
if ( V_29 < 0 ) {
V_82 = V_29 ;
break;
}
V_29 = F_428 ( V_109 , V_35 , V_65 , V_543 , V_165 ) ;
if ( V_29 < 0 ) {
V_82 = V_29 ;
break;
}
if ( V_29 > 0 ) {
F_30 ( V_543 -> V_548 != V_550 ) ;
break;
}
if ( V_543 -> V_548 == V_550 ) {
V_164 = V_543 -> V_164 ;
F_434 ( V_65 -> V_83 [ V_164 ] ,
& V_248 -> V_563 ,
V_65 -> V_84 [ V_164 ] ) ;
V_248 -> V_564 = V_164 ;
}
F_30 ( V_543 -> V_164 == 0 ) ;
if ( F_435 ( V_109 , V_87 ) ||
( ! V_556 && F_436 ( V_35 ) ) ) {
V_29 = F_437 ( V_109 , V_87 ,
& V_35 -> V_247 ,
V_248 ) ;
if ( V_29 ) {
F_146 ( V_109 , V_87 , V_29 ) ;
V_82 = V_29 ;
goto V_566;
}
F_438 ( V_109 , V_87 ) ;
if ( ! V_556 && F_436 ( V_35 ) ) {
F_439 ( L_27 ) ;
V_82 = - V_175 ;
goto V_121;
}
V_109 = F_430 ( V_87 , 0 ) ;
if ( F_232 ( V_109 ) ) {
V_82 = F_233 ( V_109 ) ;
goto V_121;
}
if ( V_373 )
V_109 -> V_373 = V_373 ;
}
}
F_43 ( V_65 ) ;
if ( V_82 )
goto V_566;
V_29 = F_440 ( V_109 , V_87 , & V_35 -> V_247 ) ;
if ( V_29 ) {
F_146 ( V_109 , V_87 , V_29 ) ;
goto V_566;
}
if ( V_35 -> V_247 . V_22 != V_541 ) {
V_29 = F_441 ( V_87 , & V_35 -> V_247 , V_65 ,
NULL , NULL ) ;
if ( V_29 < 0 ) {
F_146 ( V_109 , V_87 , V_29 ) ;
V_82 = V_29 ;
goto V_566;
} else if ( V_29 > 0 ) {
F_442 ( V_109 , V_87 ,
V_35 -> V_247 . V_22 ) ;
}
}
if ( V_35 -> V_567 ) {
F_443 ( V_87 -> V_37 , V_35 ) ;
} else {
F_423 ( V_35 -> V_126 ) ;
F_423 ( V_35 -> V_568 ) ;
F_444 ( V_35 ) ;
}
V_562 = true ;
V_566:
F_438 ( V_109 , V_87 ) ;
V_121:
F_9 ( V_543 ) ;
F_49 ( V_65 ) ;
V_73:
if ( ! V_556 && V_562 == false )
F_445 ( V_35 ) ;
if ( V_82 )
F_446 ( V_35 -> V_37 , V_82 ) ;
return V_82 ;
}
int F_447 ( struct V_108 * V_109 ,
struct V_34 * V_35 ,
struct V_66 * V_126 ,
struct V_66 * V_17 )
{
struct V_64 * V_65 ;
struct V_542 * V_543 ;
int V_164 ;
int V_569 ;
int V_29 = 0 ;
int V_570 ;
F_30 ( V_35 -> V_247 . V_22 != V_541 ) ;
V_65 = F_33 () ;
if ( ! V_65 )
return - V_72 ;
V_543 = F_52 ( sizeof( * V_543 ) , V_40 ) ;
if ( ! V_543 ) {
F_49 ( V_65 ) ;
return - V_72 ;
}
F_448 ( V_17 ) ;
V_569 = F_216 ( V_17 ) ;
F_449 ( V_17 ) ;
V_65 -> V_83 [ V_569 ] = V_17 ;
V_65 -> V_84 [ V_569 ] = F_38 ( V_17 ) ;
F_448 ( V_126 ) ;
V_164 = F_216 ( V_126 ) ;
V_65 -> V_83 [ V_164 ] = V_126 ;
V_65 -> V_84 [ V_164 ] = 0 ;
V_65 -> V_555 [ V_164 ] = V_559 ;
V_543 -> V_111 [ V_569 ] = 1 ;
V_543 -> V_7 [ V_569 ] = V_124 ;
V_543 -> V_164 = V_164 ;
V_543 -> V_558 = - 1 ;
V_543 -> V_548 = V_550 ;
V_543 -> V_551 = 0 ;
V_543 -> V_171 = 1 ;
V_543 -> V_556 = 1 ;
V_543 -> V_547 = F_413 ( V_35 ) ;
while ( 1 ) {
V_570 = F_427 ( V_109 , V_35 , V_65 , V_543 ) ;
if ( V_570 < 0 ) {
V_29 = V_570 ;
break;
}
V_570 = F_428 ( V_109 , V_35 , V_65 , V_543 , V_569 ) ;
if ( V_570 < 0 )
V_29 = V_570 ;
if ( V_570 != 0 )
break;
}
F_9 ( V_543 ) ;
F_49 ( V_65 ) ;
return V_29 ;
}
static T_2 F_450 ( struct V_34 * V_35 , T_2 V_7 )
{
T_2 V_318 ;
T_2 V_571 ;
V_571 = F_257 ( V_35 -> V_37 , V_7 ) ;
if ( V_571 )
return F_259 ( V_571 ) ;
V_318 = V_35 -> V_37 -> V_319 -> V_320 +
V_35 -> V_37 -> V_319 -> V_321 ;
V_571 = V_324 |
V_325 | V_326 |
V_284 | V_285 ;
if ( V_318 == 1 ) {
V_571 |= V_283 ;
V_571 = V_7 & ~ V_571 ;
if ( V_7 & V_324 )
return V_571 ;
if ( V_7 & ( V_284 |
V_285 ) )
return V_571 | V_283 ;
} else {
if ( V_7 & V_571 )
return V_7 ;
V_571 |= V_283 ;
V_571 = V_7 & ~ V_571 ;
if ( V_7 & V_283 )
return V_571 | V_284 ;
}
return V_7 ;
}
static int F_451 ( struct V_1 * V_2 , int V_343 )
{
struct V_101 * V_342 = V_2 -> V_104 ;
T_2 V_36 ;
T_2 V_572 ;
int V_29 = - V_338 ;
if ( ( V_342 -> V_7 &
( V_308 | V_306 ) ) &&
! V_343 )
V_572 = 1 * 1024 * 1024 ;
else
V_572 = 0 ;
F_11 ( & V_342 -> V_52 ) ;
F_11 ( & V_2 -> V_52 ) ;
if ( V_2 -> V_268 ) {
V_29 = 0 ;
goto V_73;
}
V_36 = V_2 -> V_21 . V_33 - V_2 -> V_10 - V_2 -> V_9 -
V_2 -> V_46 - F_343 ( & V_2 -> V_133 ) ;
if ( V_342 -> V_281 + V_342 -> V_293 + V_342 -> V_292 +
V_342 -> V_295 + V_342 -> V_294 + V_36 +
V_572 <= V_342 -> V_280 ) {
V_342 -> V_294 += V_36 ;
V_2 -> V_268 = 1 ;
V_29 = 0 ;
}
V_73:
F_13 ( & V_2 -> V_52 ) ;
F_13 ( & V_342 -> V_52 ) ;
return V_29 ;
}
int F_452 ( struct V_34 * V_35 ,
struct V_1 * V_2 )
{
struct V_108 * V_109 ;
T_2 V_573 ;
int V_29 ;
F_30 ( V_2 -> V_268 ) ;
V_109 = F_265 ( V_35 ) ;
if ( F_232 ( V_109 ) )
return F_233 ( V_109 ) ;
V_573 = F_450 ( V_35 , V_2 -> V_7 ) ;
if ( V_573 != V_2 -> V_7 ) {
V_29 = F_266 ( V_109 , V_35 , V_573 ,
V_337 ) ;
if ( V_29 < 0 )
goto V_73;
}
V_29 = F_451 ( V_2 , 0 ) ;
if ( ! V_29 )
goto V_73;
V_573 = F_260 ( V_35 , V_2 -> V_104 -> V_7 ) ;
V_29 = F_266 ( V_109 , V_35 , V_573 ,
V_337 ) ;
if ( V_29 < 0 )
goto V_73;
V_29 = F_451 ( V_2 , 0 ) ;
V_73:
F_267 ( V_109 , V_35 ) ;
return V_29 ;
}
int F_453 ( struct V_108 * V_109 ,
struct V_34 * V_35 , T_2 type )
{
T_2 V_573 = F_260 ( V_35 , type ) ;
return F_266 ( V_109 , V_35 , V_573 ,
V_337 ) ;
}
static T_2 F_454 ( struct V_102 * V_574 )
{
struct V_1 * V_14 ;
T_2 V_575 = 0 ;
int V_282 ;
F_377 (block_group, groups_list, list) {
F_11 ( & V_14 -> V_52 ) ;
if ( ! V_14 -> V_268 ) {
F_13 ( & V_14 -> V_52 ) ;
continue;
}
if ( V_14 -> V_7 & ( V_284 |
V_285 |
V_283 ) )
V_282 = 2 ;
else
V_282 = 1 ;
V_575 += ( V_14 -> V_21 . V_33 -
F_343 ( & V_14 -> V_133 ) ) *
V_282 ;
F_13 ( & V_14 -> V_52 ) ;
}
return V_575 ;
}
T_2 F_455 ( struct V_101 * V_342 )
{
int V_43 ;
T_2 V_575 = 0 ;
F_11 ( & V_342 -> V_52 ) ;
for( V_43 = 0 ; V_43 < V_289 ; V_43 ++ )
if ( ! F_165 ( & V_342 -> V_290 [ V_43 ] ) )
V_575 += F_454 (
& V_342 -> V_290 [ V_43 ] ) ;
F_13 ( & V_342 -> V_52 ) ;
return V_575 ;
}
void F_456 ( struct V_34 * V_35 ,
struct V_1 * V_2 )
{
struct V_101 * V_342 = V_2 -> V_104 ;
T_2 V_36 ;
F_30 ( ! V_2 -> V_268 ) ;
F_11 ( & V_342 -> V_52 ) ;
F_11 ( & V_2 -> V_52 ) ;
V_36 = V_2 -> V_21 . V_33 - V_2 -> V_10 - V_2 -> V_9 -
V_2 -> V_46 - F_343 ( & V_2 -> V_133 ) ;
V_342 -> V_294 -= V_36 ;
V_2 -> V_268 = 0 ;
F_13 ( & V_2 -> V_52 ) ;
F_13 ( & V_342 -> V_52 ) ;
}
int F_457 ( struct V_34 * V_35 , T_2 V_27 )
{
struct V_1 * V_14 ;
struct V_101 * V_104 ;
struct V_576 * V_319 = V_35 -> V_37 -> V_319 ;
struct V_577 * V_578 ;
struct V_108 * V_109 ;
T_2 V_579 ;
T_2 V_580 = 1 ;
T_2 V_581 = 0 ;
T_2 V_313 ;
int V_496 ;
int V_107 = 0 ;
int V_29 = 0 ;
V_14 = F_66 ( V_35 -> V_37 , V_27 ) ;
if ( ! V_14 )
return - 1 ;
V_579 = F_343 ( & V_14 -> V_133 ) ;
if ( ! V_579 )
goto V_73;
V_104 = V_14 -> V_104 ;
F_11 ( & V_104 -> V_52 ) ;
V_107 = V_104 -> V_107 ;
if ( ( V_104 -> V_280 != V_14 -> V_21 . V_33 ) &&
( V_104 -> V_281 + V_104 -> V_293 +
V_104 -> V_292 + V_104 -> V_294 +
V_579 < V_104 -> V_280 ) ) {
F_13 ( & V_104 -> V_52 ) ;
goto V_73;
}
F_13 ( & V_104 -> V_52 ) ;
V_29 = - 1 ;
V_313 = F_257 ( V_35 -> V_37 , V_14 -> V_7 ) ;
if ( V_313 ) {
V_496 = F_371 ( F_259 ( V_313 ) ) ;
} else {
if ( V_107 )
goto V_73;
V_496 = F_372 ( V_14 ) ;
}
if ( V_496 == V_480 ) {
V_580 = 4 ;
V_579 >>= 1 ;
} else if ( V_496 == V_481 ) {
V_580 = 2 ;
} else if ( V_496 == V_482 ) {
V_579 <<= 1 ;
} else if ( V_496 == V_483 ) {
V_580 = V_319 -> V_320 ;
F_458 ( V_579 , V_580 ) ;
}
V_109 = F_265 ( V_35 ) ;
if ( F_232 ( V_109 ) ) {
V_29 = F_233 ( V_109 ) ;
goto V_73;
}
F_35 ( & V_35 -> V_37 -> V_353 ) ;
F_377 (device, &fs_devices->alloc_list, dev_alloc_list) {
T_2 V_582 ;
if ( V_578 -> V_280 > V_578 -> V_281 + V_579 &&
! V_578 -> V_583 ) {
V_29 = F_459 ( V_109 , V_578 , V_579 ,
& V_582 , NULL ) ;
if ( ! V_29 )
V_581 ++ ;
if ( V_581 >= V_580 )
break;
V_29 = - 1 ;
}
}
F_45 ( & V_35 -> V_37 -> V_353 ) ;
F_267 ( V_109 , V_35 ) ;
V_73:
F_6 ( V_14 ) ;
return V_29 ;
}
static int F_460 ( struct V_34 * V_35 ,
struct V_64 * V_65 , struct V_68 * V_21 )
{
int V_29 = 0 ;
struct V_68 V_138 ;
struct V_66 * V_67 ;
int V_544 ;
V_29 = F_37 ( NULL , V_35 , V_21 , V_65 , 0 , 0 ) ;
if ( V_29 < 0 )
goto V_73;
while ( 1 ) {
V_544 = V_65 -> V_84 [ 0 ] ;
V_67 = V_65 -> V_83 [ 0 ] ;
if ( V_544 >= F_38 ( V_67 ) ) {
V_29 = F_47 ( V_35 , V_65 ) ;
if ( V_29 == 0 )
continue;
if ( V_29 < 0 )
goto V_73;
break;
}
F_40 ( V_67 , & V_138 , V_544 ) ;
if ( V_138 . V_22 >= V_21 -> V_22 &&
V_138 . type == V_176 ) {
V_29 = 0 ;
goto V_73;
}
V_65 -> V_84 [ 0 ] ++ ;
}
V_73:
return V_29 ;
}
void F_461 ( struct V_12 * V_13 )
{
struct V_1 * V_14 ;
T_2 V_70 = 0 ;
while ( 1 ) {
struct V_260 * V_260 ;
V_14 = F_65 ( V_13 , V_70 ) ;
while ( V_14 ) {
F_11 ( & V_14 -> V_52 ) ;
if ( V_14 -> V_161 )
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
V_260 = V_14 -> V_260 ;
V_14 -> V_161 = 0 ;
V_14 -> V_260 = NULL ;
F_13 ( & V_14 -> V_52 ) ;
F_244 ( V_260 ) ;
V_70 = V_14 -> V_21 . V_22 + V_14 -> V_21 . V_33 ;
F_6 ( V_14 ) ;
}
}
int F_462 ( struct V_12 * V_13 )
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
F_61 ( & V_14 -> V_104 -> V_291 ) ;
F_182 ( & V_14 -> V_91 ) ;
F_63 ( & V_14 -> V_104 -> V_291 ) ;
if ( V_14 -> V_3 == V_53 )
F_370 ( V_14 ) ;
if ( V_14 -> V_3 == V_95 ||
V_14 -> V_3 == V_5 )
F_19 ( V_13 -> V_63 , V_14 ) ;
F_463 ( V_14 ) ;
F_6 ( V_14 ) ;
F_11 ( & V_13 -> V_18 ) ;
}
F_13 ( & V_13 -> V_18 ) ;
F_464 () ;
F_320 ( V_13 ) ;
while( ! F_165 ( & V_13 -> V_104 ) ) {
V_104 = F_166 ( V_13 -> V_104 . V_81 ,
struct V_101 ,
V_91 ) ;
if ( F_240 ( V_13 -> V_87 , V_350 ) ) {
if ( V_104 -> V_292 > 0 ||
V_104 -> V_293 > 0 ||
V_104 -> V_295 > 0 ) {
F_8 ( 1 ) ;
F_280 ( V_104 , 0 , 0 ) ;
}
}
F_465 ( & V_104 -> V_288 ) ;
F_182 ( & V_104 -> V_91 ) ;
F_9 ( V_104 ) ;
}
return 0 ;
}
static void F_466 ( struct V_101 * V_104 ,
struct V_1 * V_2 )
{
int V_496 = F_372 ( V_2 ) ;
F_61 ( & V_104 -> V_291 ) ;
F_62 ( & V_2 -> V_91 , & V_104 -> V_290 [ V_496 ] ) ;
F_63 ( & V_104 -> V_291 ) ;
}
int F_467 ( struct V_34 * V_35 )
{
struct V_64 * V_65 ;
int V_29 ;
struct V_1 * V_2 ;
struct V_12 * V_13 = V_35 -> V_37 ;
struct V_101 * V_104 ;
struct V_68 V_21 ;
struct V_68 V_138 ;
struct V_66 * V_67 ;
int V_584 = 0 ;
T_2 V_585 ;
V_35 = V_13 -> V_63 ;
V_21 . V_22 = 0 ;
V_21 . V_33 = 0 ;
F_374 ( & V_21 , V_176 ) ;
V_65 = F_33 () ;
if ( ! V_65 )
return - V_72 ;
V_65 -> V_76 = 1 ;
V_585 = F_468 ( V_35 -> V_37 -> V_347 ) ;
if ( F_240 ( V_35 , V_274 ) &&
F_469 ( V_35 -> V_37 -> V_347 ) != V_585 )
V_584 = 1 ;
if ( F_240 ( V_35 , V_586 ) )
V_584 = 1 ;
while ( 1 ) {
V_29 = F_460 ( V_35 , V_65 , & V_21 ) ;
if ( V_29 > 0 )
break;
if ( V_29 != 0 )
goto error;
V_67 = V_65 -> V_83 [ 0 ] ;
F_40 ( V_67 , & V_138 , V_65 -> V_84 [ 0 ] ) ;
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
F_53 ( & V_2 -> V_587 ) ;
if ( V_584 ) {
V_2 -> V_266 = V_276 ;
if ( F_240 ( V_35 , V_274 ) )
V_2 -> V_277 = 1 ;
}
F_470 ( V_67 , & V_2 -> V_133 ,
F_227 ( V_67 , V_65 -> V_84 [ 0 ] ) ,
sizeof( V_2 -> V_133 ) ) ;
memcpy ( & V_2 -> V_21 , & V_138 , sizeof( V_138 ) ) ;
V_21 . V_22 = V_138 . V_22 + V_138 . V_33 ;
F_43 ( V_65 ) ;
V_2 -> V_7 = F_471 ( & V_2 -> V_133 ) ;
V_2 -> V_332 = V_35 -> V_332 ;
V_2 -> V_588 = F_472 ( V_35 ,
& V_35 -> V_37 -> V_48 ,
V_138 . V_22 ) ;
F_473 ( V_2 ) ;
V_29 = F_21 ( V_35 , V_2 ) ;
if ( V_29 ) {
F_19 ( V_35 , V_2 ) ;
F_9 ( V_2 -> V_11 ) ;
F_9 ( V_2 ) ;
goto error;
}
if ( V_138 . V_33 == F_343 ( & V_2 -> V_133 ) ) {
V_2 -> V_98 = ( T_2 ) - 1 ;
V_2 -> V_3 = V_4 ;
F_19 ( V_35 , V_2 ) ;
} else if ( F_343 ( & V_2 -> V_133 ) == 0 ) {
V_2 -> V_98 = ( T_2 ) - 1 ;
V_2 -> V_3 = V_4 ;
F_27 ( V_2 , V_35 -> V_37 ,
V_138 . V_22 ,
V_138 . V_22 +
V_138 . V_33 ) ;
F_19 ( V_35 , V_2 ) ;
}
V_29 = F_10 ( V_35 -> V_37 , V_2 ) ;
if ( V_29 ) {
F_463 ( V_2 ) ;
F_6 ( V_2 ) ;
goto error;
}
V_29 = F_248 ( V_13 , V_2 -> V_7 , V_138 . V_33 ,
F_343 ( & V_2 -> V_133 ) ,
& V_104 ) ;
if ( V_29 ) {
F_463 ( V_2 ) ;
F_11 ( & V_13 -> V_18 ) ;
F_175 ( & V_2 -> V_20 ,
& V_13 -> V_19 ) ;
F_13 ( & V_13 -> V_18 ) ;
F_6 ( V_2 ) ;
goto error;
}
V_2 -> V_104 = V_104 ;
F_11 ( & V_2 -> V_104 -> V_52 ) ;
V_2 -> V_104 -> V_294 += V_2 -> V_46 ;
F_13 ( & V_2 -> V_104 -> V_52 ) ;
F_466 ( V_104 , V_2 ) ;
F_253 ( V_35 -> V_37 , V_2 -> V_7 ) ;
if ( F_474 ( V_35 , V_2 -> V_21 . V_22 ) )
F_451 ( V_2 , 1 ) ;
}
F_69 (space_info, &root->fs_info->space_info, list) {
if ( ! ( F_260 ( V_35 , V_104 -> V_7 ) &
( V_285 |
V_284 |
V_325 |
V_326 |
V_283 ) ) )
continue;
F_377 (cache,
&space_info->block_groups[BTRFS_RAID_RAID0],
list)
F_451 ( V_2 , 1 ) ;
F_377 (cache,
&space_info->block_groups[BTRFS_RAID_SINGLE],
list)
F_451 ( V_2 , 1 ) ;
}
F_319 ( V_13 ) ;
V_29 = 0 ;
error:
F_49 ( V_65 ) ;
return V_29 ;
}
void F_199 ( struct V_108 * V_109 ,
struct V_34 * V_35 )
{
struct V_1 * V_14 , * V_322 ;
struct V_34 * V_63 = V_35 -> V_37 -> V_63 ;
struct V_589 V_133 ;
struct V_68 V_21 ;
int V_29 = 0 ;
F_353 (block_group, tmp, &trans->new_bgs,
new_bg_list) {
F_171 ( & V_14 -> V_590 ) ;
if ( V_29 )
continue;
F_11 ( & V_14 -> V_52 ) ;
memcpy ( & V_133 , & V_14 -> V_133 , sizeof( V_133 ) ) ;
memcpy ( & V_21 , & V_14 -> V_21 , sizeof( V_21 ) ) ;
F_13 ( & V_14 -> V_52 ) ;
V_29 = F_475 ( V_109 , V_63 , & V_21 , & V_133 ,
sizeof( V_133 ) ) ;
if ( V_29 )
F_146 ( V_109 , V_63 , V_29 ) ;
V_29 = F_476 ( V_109 , V_63 ,
V_21 . V_22 , V_21 . V_33 ) ;
if ( V_29 )
F_146 ( V_109 , V_63 , V_29 ) ;
}
}
int F_477 ( struct V_108 * V_109 ,
struct V_34 * V_35 , T_2 V_281 ,
T_2 type , T_2 V_591 , T_2 V_592 ,
T_2 V_57 )
{
int V_29 ;
struct V_34 * V_63 ;
struct V_1 * V_2 ;
V_63 = V_35 -> V_37 -> V_63 ;
V_35 -> V_37 -> V_593 = V_109 -> V_270 ;
V_2 = F_52 ( sizeof( * V_2 ) , V_40 ) ;
if ( ! V_2 )
return - V_72 ;
V_2 -> V_11 = F_52 ( sizeof( * V_2 -> V_11 ) ,
V_40 ) ;
if ( ! V_2 -> V_11 ) {
F_9 ( V_2 ) ;
return - V_72 ;
}
V_2 -> V_21 . V_22 = V_592 ;
V_2 -> V_21 . V_33 = V_57 ;
V_2 -> V_21 . type = V_176 ;
V_2 -> V_332 = V_35 -> V_332 ;
V_2 -> V_37 = V_35 -> V_37 ;
V_2 -> V_588 = F_472 ( V_35 ,
& V_35 -> V_37 -> V_48 ,
V_592 ) ;
F_56 ( & V_2 -> V_8 , 1 ) ;
F_251 ( & V_2 -> V_52 ) ;
F_53 ( & V_2 -> V_91 ) ;
F_53 ( & V_2 -> V_587 ) ;
F_53 ( & V_2 -> V_590 ) ;
F_473 ( V_2 ) ;
F_344 ( & V_2 -> V_133 , V_281 ) ;
F_478 ( & V_2 -> V_133 , V_591 ) ;
V_2 -> V_7 = type ;
F_479 ( & V_2 -> V_133 , type ) ;
V_2 -> V_98 = ( T_2 ) - 1 ;
V_2 -> V_3 = V_4 ;
V_29 = F_21 ( V_35 , V_2 ) ;
if ( V_29 ) {
F_19 ( V_35 , V_2 ) ;
F_9 ( V_2 -> V_11 ) ;
F_9 ( V_2 ) ;
return V_29 ;
}
F_27 ( V_2 , V_35 -> V_37 , V_592 ,
V_592 + V_57 ) ;
F_19 ( V_35 , V_2 ) ;
V_29 = F_10 ( V_35 -> V_37 , V_2 ) ;
if ( V_29 ) {
F_463 ( V_2 ) ;
F_6 ( V_2 ) ;
return V_29 ;
}
V_29 = F_248 ( V_35 -> V_37 , V_2 -> V_7 , V_57 , V_281 ,
& V_2 -> V_104 ) ;
if ( V_29 ) {
F_463 ( V_2 ) ;
F_11 ( & V_35 -> V_37 -> V_18 ) ;
F_175 ( & V_2 -> V_20 ,
& V_35 -> V_37 -> V_19 ) ;
F_13 ( & V_35 -> V_37 -> V_18 ) ;
F_6 ( V_2 ) ;
return V_29 ;
}
F_318 ( V_35 -> V_37 ) ;
F_11 ( & V_2 -> V_104 -> V_52 ) ;
V_2 -> V_104 -> V_294 += V_2 -> V_46 ;
F_13 ( & V_2 -> V_104 -> V_52 ) ;
F_466 ( V_2 -> V_104 , V_2 ) ;
F_62 ( & V_2 -> V_590 , & V_109 -> V_244 ) ;
F_253 ( V_63 -> V_37 , type ) ;
return 0 ;
}
static void F_480 ( struct V_12 * V_37 , T_2 V_7 )
{
T_2 V_302 = F_254 ( V_7 ) &
V_303 ;
F_255 ( & V_37 -> V_304 ) ;
if ( V_7 & V_300 )
V_37 -> V_305 &= ~ V_302 ;
if ( V_7 & V_306 )
V_37 -> V_307 &= ~ V_302 ;
if ( V_7 & V_308 )
V_37 -> V_309 &= ~ V_302 ;
F_256 ( & V_37 -> V_304 ) ;
}
int F_481 ( struct V_108 * V_109 ,
struct V_34 * V_35 , T_2 V_594 )
{
struct V_64 * V_65 ;
struct V_1 * V_14 ;
struct V_490 * V_212 ;
struct V_34 * V_87 = V_35 -> V_37 -> V_87 ;
struct V_68 V_21 ;
struct V_260 * V_260 ;
int V_29 ;
int V_496 ;
int V_282 ;
V_35 = V_35 -> V_37 -> V_63 ;
V_14 = F_66 ( V_35 -> V_37 , V_594 ) ;
F_30 ( ! V_14 ) ;
F_30 ( ! V_14 -> V_268 ) ;
F_19 ( V_35 , V_14 ) ;
memcpy ( & V_21 , & V_14 -> V_21 , sizeof( V_21 ) ) ;
V_496 = F_372 ( V_14 ) ;
if ( V_14 -> V_7 & ( V_283 |
V_284 |
V_285 ) )
V_282 = 2 ;
else
V_282 = 1 ;
V_212 = & V_35 -> V_37 -> V_506 ;
F_11 ( & V_212 -> V_512 ) ;
F_380 ( V_14 , V_212 ) ;
F_13 ( & V_212 -> V_512 ) ;
V_212 = & V_35 -> V_37 -> V_504 ;
F_11 ( & V_212 -> V_512 ) ;
F_380 ( V_14 , V_212 ) ;
F_13 ( & V_212 -> V_512 ) ;
V_65 = F_33 () ;
if ( ! V_65 ) {
V_29 = - V_72 ;
goto V_73;
}
V_260 = F_231 ( V_87 , V_14 , V_65 ) ;
if ( ! F_232 ( V_260 ) ) {
V_29 = F_482 ( V_109 , V_260 ) ;
if ( V_29 ) {
F_483 ( V_260 ) ;
goto V_73;
}
F_484 ( V_260 ) ;
F_11 ( & V_14 -> V_52 ) ;
if ( V_14 -> V_161 ) {
V_14 -> V_161 = 0 ;
V_14 -> V_260 = NULL ;
F_13 ( & V_14 -> V_52 ) ;
F_244 ( V_260 ) ;
} else {
F_13 ( & V_14 -> V_52 ) ;
}
F_483 ( V_260 ) ;
}
V_21 . V_22 = V_595 ;
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
F_61 ( & V_14 -> V_104 -> V_291 ) ;
F_171 ( & V_14 -> V_91 ) ;
if ( F_165 ( & V_14 -> V_104 -> V_290 [ V_496 ] ) )
F_480 ( V_35 -> V_37 , V_14 -> V_7 ) ;
F_63 ( & V_14 -> V_104 -> V_291 ) ;
if ( V_14 -> V_3 == V_53 )
F_370 ( V_14 ) ;
F_463 ( V_14 ) ;
F_11 ( & V_14 -> V_104 -> V_52 ) ;
V_14 -> V_104 -> V_280 -= V_14 -> V_21 . V_33 ;
V_14 -> V_104 -> V_294 -= V_14 -> V_21 . V_33 ;
V_14 -> V_104 -> V_286 -= V_14 -> V_21 . V_33 * V_282 ;
F_13 ( & V_14 -> V_104 -> V_52 ) ;
memcpy ( & V_21 , & V_14 -> V_21 , sizeof( V_21 ) ) ;
F_71 ( V_35 -> V_37 ) ;
F_6 ( V_14 ) ;
F_6 ( V_14 ) ;
V_29 = F_37 ( V_109 , V_35 , & V_21 , V_65 , - 1 , 1 ) ;
if ( V_29 > 0 )
V_29 = - V_172 ;
if ( V_29 < 0 )
goto V_73;
V_29 = F_114 ( V_109 , V_35 , V_65 ) ;
V_73:
F_49 ( V_65 ) ;
return V_29 ;
}
int F_485 ( struct V_12 * V_37 )
{
struct V_101 * V_104 ;
struct V_596 * V_597 ;
T_2 V_598 ;
T_2 V_7 ;
int V_599 = 0 ;
int V_29 ;
V_597 = V_37 -> V_347 ;
if ( ! F_486 ( V_597 ) )
return 1 ;
V_598 = F_487 ( V_597 ) ;
if ( V_598 & V_600 )
V_599 = 1 ;
V_7 = V_308 ;
V_29 = F_248 ( V_37 , V_7 , 0 , 0 , & V_104 ) ;
if ( V_29 )
goto V_73;
if ( V_599 ) {
V_7 = V_306 | V_300 ;
V_29 = F_248 ( V_37 , V_7 , 0 , 0 , & V_104 ) ;
} else {
V_7 = V_306 ;
V_29 = F_248 ( V_37 , V_7 , 0 , 0 , & V_104 ) ;
if ( V_29 )
goto V_73;
V_7 = V_300 ;
V_29 = F_248 ( V_37 , V_7 , 0 , 0 , & V_104 ) ;
}
V_73:
return V_29 ;
}
int F_488 ( struct V_34 * V_35 , T_2 V_32 , T_2 V_31 )
{
return F_355 ( V_35 , V_32 , V_31 ) ;
}
int F_489 ( struct V_34 * V_35 , T_2 V_27 ,
T_2 V_36 , T_2 * V_184 )
{
return F_140 ( V_35 , V_27 , V_36 , V_184 ) ;
}
int F_490 ( struct V_34 * V_35 , struct V_601 * V_602 )
{
struct V_12 * V_37 = V_35 -> V_37 ;
struct V_1 * V_2 = NULL ;
T_2 V_603 ;
T_2 V_32 ;
T_2 V_31 ;
T_2 V_604 = 0 ;
T_2 V_280 = F_274 ( V_37 -> V_347 ) ;
int V_29 = 0 ;
if ( V_602 -> V_49 == V_280 )
V_2 = F_65 ( V_37 , V_602 -> V_32 ) ;
else
V_2 = F_66 ( V_37 , V_602 -> V_32 ) ;
while ( V_2 ) {
if ( V_2 -> V_21 . V_22 >= ( V_602 -> V_32 + V_602 -> V_49 ) ) {
F_6 ( V_2 ) ;
break;
}
V_32 = F_376 ( V_602 -> V_32 , V_2 -> V_21 . V_22 ) ;
V_31 = F_291 ( V_602 -> V_32 + V_602 -> V_49 ,
V_2 -> V_21 . V_22 + V_2 -> V_21 . V_33 ) ;
if ( V_31 - V_32 >= V_602 -> V_605 ) {
if ( ! F_1 ( V_2 ) ) {
V_29 = F_50 ( V_2 , 0 ) ;
if ( V_29 ) {
F_6 ( V_2 ) ;
break;
}
V_29 = F_370 ( V_2 ) ;
if ( V_29 ) {
F_6 ( V_2 ) ;
break;
}
}
V_29 = F_491 ( V_2 ,
& V_603 ,
V_32 ,
V_31 ,
V_602 -> V_605 ) ;
V_604 += V_603 ;
if ( V_29 ) {
F_6 ( V_2 ) ;
break;
}
}
V_2 = F_229 ( V_37 -> V_87 , V_2 ) ;
}
V_602 -> V_49 = V_604 ;
return V_29 ;
}
