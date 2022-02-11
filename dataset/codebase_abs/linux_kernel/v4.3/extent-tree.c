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
static T_1 T_3 F_118 ( struct V_63 * V_64 ,
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
static int F_140 ( struct V_185 * V_186 , T_2 V_32 , T_2 V_49 ,
T_2 * V_187 )
{
int V_188 , V_29 = 0 ;
T_2 V_189 , V_31 ;
T_2 V_190 = F_141 ( V_32 , 1 << 9 ) ;
if ( F_8 ( V_32 != V_190 ) ) {
V_49 -= V_190 - V_32 ;
V_49 = F_142 ( V_49 , 1 << 9 ) ;
V_32 = V_190 ;
}
* V_187 = 0 ;
if ( ! V_49 )
return 0 ;
V_31 = V_32 + V_49 ;
V_189 = V_49 ;
for ( V_188 = 0 ; V_188 < V_47 ; V_188 ++ ) {
T_2 V_191 = F_22 ( V_188 ) ;
T_2 V_192 = V_191 + V_193 ;
T_2 V_56 = V_191 - V_32 ;
if ( ! F_143 ( V_191 , V_32 , V_189 ) &&
! F_143 ( V_192 , V_32 , V_189 ) &&
! F_143 ( V_32 , V_191 , V_193 ) )
continue;
if ( V_191 <= V_32 ) {
V_32 += V_192 - V_32 ;
if ( V_32 > V_31 ) {
V_189 = 0 ;
break;
}
V_189 = V_31 - V_32 ;
continue;
}
if ( V_56 ) {
V_29 = F_144 ( V_186 , V_32 >> 9 , V_56 >> 9 ,
V_40 , 0 ) ;
if ( ! V_29 )
* V_187 += V_56 ;
else if ( V_29 != - V_194 )
return V_29 ;
}
V_32 = V_192 ;
if ( V_32 > V_31 ) {
V_189 = 0 ;
break;
}
V_189 = V_31 - V_32 ;
}
if ( V_189 ) {
V_29 = F_144 ( V_186 , V_32 >> 9 , V_189 >> 9 ,
V_40 , 0 ) ;
if ( ! V_29 )
* V_187 += V_189 ;
}
return V_29 ;
}
int F_145 ( struct V_34 * V_35 , T_2 V_27 ,
T_2 V_36 , T_2 * V_195 )
{
int V_29 ;
T_2 V_187 = 0 ;
struct V_196 * V_197 = NULL ;
V_29 = F_146 ( V_35 -> V_37 , V_198 ,
V_27 , & V_36 , & V_197 , 0 ) ;
if ( ! V_29 ) {
struct V_199 * V_200 = V_197 -> V_201 ;
int V_43 ;
for ( V_43 = 0 ; V_43 < V_197 -> V_202 ; V_43 ++ , V_200 ++ ) {
T_2 V_203 ;
if ( ! V_200 -> V_204 -> V_205 )
continue;
V_29 = F_140 ( V_200 -> V_204 -> V_186 ,
V_200 -> V_206 ,
V_200 -> V_207 ,
& V_203 ) ;
if ( ! V_29 )
V_187 += V_203 ;
else if ( V_29 != - V_194 )
break;
V_29 = 0 ;
}
F_147 ( V_197 ) ;
}
if ( V_195 )
* V_195 = V_187 ;
if ( V_29 == - V_194 )
V_29 = 0 ;
return V_29 ;
}
int F_148 ( struct V_109 * V_110 ,
struct V_34 * V_35 ,
T_2 V_27 , T_2 V_36 , T_2 V_17 ,
T_2 V_146 , T_2 V_133 , T_2 V_33 ,
int V_208 )
{
int V_29 ;
struct V_12 * V_37 = V_35 -> V_37 ;
F_30 ( V_133 < V_143 &&
V_146 == V_209 ) ;
if ( V_133 < V_143 ) {
V_29 = F_149 ( V_37 , V_110 , V_27 ,
V_36 ,
V_17 , V_146 , ( int ) V_133 ,
V_210 , NULL , V_208 ) ;
} else {
V_29 = F_150 ( V_37 , V_110 , V_27 ,
V_36 ,
V_17 , V_146 , V_133 , V_33 ,
V_210 , NULL , V_208 ) ;
}
return V_29 ;
}
static int F_151 ( struct V_109 * V_110 ,
struct V_34 * V_35 ,
struct V_211 * V_128 ,
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
int V_208 = V_128 -> V_208 ;
V_64 = F_33 () ;
if ( ! V_64 )
return - V_71 ;
if ( ! F_152 ( V_146 ) || ! V_35 -> V_37 -> V_212 )
V_208 = 1 ;
V_64 -> V_75 = 1 ;
V_64 -> V_213 = 1 ;
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
V_64 -> V_213 = 1 ;
V_29 = F_138 ( V_110 , V_35 -> V_37 -> V_62 ,
V_64 , V_27 , V_17 , V_146 ,
V_133 , V_33 , V_157 ) ;
if ( V_29 )
F_153 ( V_110 , V_35 , V_29 ) ;
V_72:
F_50 ( V_64 ) ;
return V_29 ;
}
static int F_154 ( struct V_109 * V_110 ,
struct V_34 * V_35 ,
struct V_211 * V_128 ,
struct V_180 * V_129 ,
int V_214 )
{
int V_29 = 0 ;
struct V_215 * V_151 ;
struct V_67 V_216 ;
T_2 V_17 = 0 ;
T_2 V_217 = 0 ;
T_2 V_7 = 0 ;
V_216 . V_22 = V_128 -> V_27 ;
V_216 . V_33 = V_128 -> V_36 ;
V_216 . type = V_76 ;
V_151 = F_155 ( V_128 ) ;
F_156 ( V_128 , V_151 , V_128 -> V_218 ) ;
if ( V_128 -> type == V_154 )
V_17 = V_151 -> V_17 ;
V_217 = V_151 -> V_35 ;
if ( V_128 -> V_218 == V_210 && V_214 ) {
if ( V_129 )
V_7 |= V_129 -> V_131 ;
V_29 = F_157 ( V_110 , V_35 ,
V_17 , V_217 , V_7 ,
V_151 -> V_22 , V_151 -> V_33 ,
& V_216 , V_128 -> V_132 ) ;
} else if ( V_128 -> V_218 == V_210 ) {
V_29 = F_151 ( V_110 , V_35 , V_128 , V_17 ,
V_217 , V_151 -> V_22 ,
V_151 -> V_33 , V_128 -> V_132 ,
V_129 ) ;
} else if ( V_128 -> V_218 == V_219 ) {
V_29 = F_158 ( V_110 , V_35 , V_128 , V_17 ,
V_217 , V_151 -> V_22 ,
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
if ( V_129 -> V_220 ) {
struct V_138 * V_139 ;
F_30 ( ! ( V_7 & V_144 ) ) ;
V_139 = (struct V_138 * ) ( V_117 + 1 ) ;
F_159 ( V_66 , V_139 , & V_129 -> V_21 ) ;
}
}
static int F_160 ( struct V_109 * V_110 ,
struct V_34 * V_35 ,
struct V_211 * V_128 ,
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
if ( V_110 -> V_221 )
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
V_64 -> V_213 = 1 ;
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
static int F_161 ( struct V_109 * V_110 ,
struct V_34 * V_35 ,
struct V_211 * V_128 ,
struct V_180 * V_129 ,
int V_214 )
{
int V_29 = 0 ;
struct V_222 * V_151 ;
struct V_67 V_216 ;
T_2 V_17 = 0 ;
T_2 V_217 = 0 ;
bool V_173 = F_76 ( V_35 -> V_37 ,
V_121 ) ;
V_151 = F_162 ( V_128 ) ;
F_163 ( V_128 , V_151 , V_128 -> V_218 ) ;
if ( V_128 -> type == V_165 )
V_17 = V_151 -> V_17 ;
V_217 = V_151 -> V_35 ;
V_216 . V_22 = V_128 -> V_27 ;
if ( V_173 ) {
V_216 . V_33 = V_151 -> V_167 ;
V_216 . type = V_85 ;
} else {
V_216 . V_33 = V_128 -> V_36 ;
V_216 . type = V_76 ;
}
F_30 ( V_128 -> V_132 != 1 ) ;
if ( V_128 -> V_218 == V_210 && V_214 ) {
F_30 ( ! V_129 || ! V_129 -> V_130 ) ;
V_29 = F_164 ( V_110 , V_35 ,
V_17 , V_217 ,
V_129 -> V_131 ,
& V_129 -> V_21 ,
V_151 -> V_167 , & V_216 ,
V_128 -> V_208 ) ;
} else if ( V_128 -> V_218 == V_210 ) {
V_29 = F_151 ( V_110 , V_35 , V_128 ,
V_17 , V_217 ,
V_151 -> V_167 , 0 , 1 ,
V_129 ) ;
} else if ( V_128 -> V_218 == V_219 ) {
V_29 = F_158 ( V_110 , V_35 , V_128 ,
V_17 , V_217 ,
V_151 -> V_167 , 0 , 1 , V_129 ) ;
} else {
F_83 () ;
}
return V_29 ;
}
static int F_165 ( struct V_109 * V_110 ,
struct V_34 * V_35 ,
struct V_211 * V_128 ,
struct V_180 * V_129 ,
int V_214 )
{
int V_29 = 0 ;
if ( V_110 -> V_221 ) {
if ( V_214 )
F_166 ( V_35 , V_128 -> V_27 ,
V_128 -> V_36 , 1 ) ;
return 0 ;
}
if ( F_167 ( V_128 ) ) {
struct V_113 * V_104 ;
F_30 ( V_129 ) ;
V_104 = F_168 ( V_128 ) ;
F_169 ( V_128 , V_104 , V_128 -> V_218 ) ;
if ( V_214 ) {
F_166 ( V_35 , V_128 -> V_27 ,
V_128 -> V_36 , 1 ) ;
if ( V_104 -> V_184 ) {
V_29 = F_170 ( V_110 , V_35 ,
V_128 -> V_27 ,
V_128 -> V_36 ) ;
}
}
return V_29 ;
}
if ( V_128 -> type == V_166 ||
V_128 -> type == V_165 )
V_29 = F_161 ( V_110 , V_35 , V_128 , V_129 ,
V_214 ) ;
else if ( V_128 -> type == V_155 ||
V_128 -> type == V_154 )
V_29 = F_154 ( V_110 , V_35 , V_128 , V_129 ,
V_214 ) ;
else
F_83 () ;
return V_29 ;
}
static inline struct V_211 *
F_171 ( struct V_113 * V_104 )
{
struct V_211 * V_151 ;
if ( F_172 ( & V_104 -> V_223 ) )
return NULL ;
F_173 (ref, &head->ref_list, list) {
if ( V_151 -> V_218 == V_210 )
return V_151 ;
}
return F_174 ( V_104 -> V_223 . V_80 , struct V_211 ,
V_90 ) ;
}
static T_1 int F_175 ( struct V_109 * V_110 ,
struct V_34 * V_35 ,
unsigned long V_44 )
{
struct V_114 * V_115 ;
struct V_211 * V_151 ;
struct V_113 * V_224 = NULL ;
struct V_180 * V_129 ;
struct V_12 * V_37 = V_35 -> V_37 ;
T_6 V_32 = F_176 () ;
int V_29 ;
unsigned long V_8 = 0 ;
unsigned long V_225 = 0 ;
int V_226 = 0 ;
V_115 = & V_110 -> V_127 -> V_115 ;
while ( 1 ) {
if ( ! V_224 ) {
if ( V_8 >= V_44 )
break;
F_11 ( & V_115 -> V_52 ) ;
V_224 = F_177 ( V_110 ) ;
if ( ! V_224 ) {
F_13 ( & V_115 -> V_52 ) ;
break;
}
V_29 = F_178 ( V_110 , V_224 ) ;
F_13 ( & V_115 -> V_52 ) ;
if ( V_29 == - V_178 ) {
V_224 = NULL ;
V_8 ++ ;
continue;
}
}
F_11 ( & V_224 -> V_52 ) ;
V_151 = F_171 ( V_224 ) ;
if ( V_151 && V_151 -> V_227 &&
F_179 ( V_37 , V_115 , V_151 -> V_227 ) ) {
F_13 ( & V_224 -> V_52 ) ;
F_180 ( V_224 ) ;
F_11 ( & V_115 -> V_52 ) ;
V_224 -> V_228 = 0 ;
V_115 -> V_229 ++ ;
F_13 ( & V_115 -> V_52 ) ;
V_224 = NULL ;
F_47 () ;
V_8 ++ ;
continue;
}
V_226 = V_224 -> V_226 ;
V_224 -> V_226 = 0 ;
V_129 = V_224 -> V_129 ;
V_224 -> V_129 = NULL ;
if ( ! V_151 ) {
V_151 = & V_224 -> V_128 ;
if ( V_129 && V_226 ) {
F_181 ( V_129 ) ;
V_129 = NULL ;
}
if ( V_129 ) {
F_13 ( & V_224 -> V_52 ) ;
V_29 = F_160 ( V_110 , V_35 ,
V_151 , V_129 ) ;
F_181 ( V_129 ) ;
if ( V_29 ) {
if ( V_226 )
V_224 -> V_226 = 1 ;
V_224 -> V_228 = 0 ;
F_182 ( V_37 , L_1 , V_29 ) ;
F_180 ( V_224 ) ;
return V_29 ;
}
continue;
}
F_13 ( & V_224 -> V_52 ) ;
F_11 ( & V_115 -> V_52 ) ;
F_11 ( & V_224 -> V_52 ) ;
if ( ! F_172 ( & V_224 -> V_223 ) ||
V_224 -> V_129 ) {
F_13 ( & V_224 -> V_52 ) ;
F_13 ( & V_115 -> V_52 ) ;
continue;
}
V_151 -> V_230 = 0 ;
V_115 -> V_231 -- ;
F_183 ( & V_224 -> V_232 ,
& V_115 -> V_233 ) ;
F_13 ( & V_115 -> V_52 ) ;
} else {
V_225 ++ ;
V_151 -> V_230 = 0 ;
F_184 ( & V_151 -> V_90 ) ;
}
F_185 ( & V_115 -> V_234 ) ;
if ( ! F_167 ( V_151 ) ) {
switch ( V_151 -> V_218 ) {
case V_210 :
case V_235 :
V_224 -> V_128 . V_132 -= V_151 -> V_132 ;
break;
case V_219 :
V_224 -> V_128 . V_132 += V_151 -> V_132 ;
break;
default:
F_8 ( 1 ) ;
}
}
F_13 ( & V_224 -> V_52 ) ;
V_29 = F_165 ( V_110 , V_35 , V_151 , V_129 ,
V_226 ) ;
F_181 ( V_129 ) ;
if ( V_29 ) {
V_224 -> V_228 = 0 ;
F_180 ( V_224 ) ;
F_86 ( V_151 ) ;
F_182 ( V_37 , L_2 , V_29 ) ;
return V_29 ;
}
if ( F_167 ( V_151 ) ) {
if ( V_224 -> V_184 &&
V_224 -> V_236 < 0 ) {
F_11 ( & V_115 -> V_52 ) ;
V_115 -> V_237 -= V_151 -> V_36 ;
F_13 ( & V_115 -> V_52 ) ;
}
F_180 ( V_224 ) ;
V_224 = NULL ;
}
F_86 ( V_151 ) ;
V_8 ++ ;
F_47 () ;
}
if ( V_225 > 0 ) {
T_2 V_238 = F_186 ( F_187 ( F_176 () , V_32 ) ) ;
T_2 V_239 ;
F_11 ( & V_115 -> V_52 ) ;
V_239 = V_37 -> V_240 * 3 + V_238 ;
V_37 -> V_240 = V_239 >> 2 ;
F_13 ( & V_115 -> V_52 ) ;
}
return 0 ;
}
static T_2 F_188 ( struct V_241 * V_35 )
{
struct V_15 * V_30 = V_35 -> V_15 ;
struct V_211 * V_242 ;
int V_243 = 1 ;
T_2 V_244 ;
T_2 V_245 = 0 , V_69 = 0 ;
V_30 = F_189 ( V_35 ) ;
if ( V_30 ) {
V_242 = F_12 ( V_30 , struct V_211 , V_15 ) ;
V_245 = V_242 -> V_27 ;
}
V_30 = F_190 ( V_35 ) ;
if ( V_30 ) {
V_242 = F_12 ( V_30 , struct V_211 , V_15 ) ;
V_69 = V_242 -> V_27 ;
}
V_30 = V_35 -> V_15 ;
while ( V_30 ) {
V_242 = F_12 ( V_30 , struct V_211 , V_15 ) ;
F_8 ( ! V_242 -> V_230 ) ;
V_244 = V_242 -> V_27 ;
if ( V_243 )
V_30 = V_30 -> V_23 ;
else
V_30 = V_30 -> V_24 ;
V_243 = 1 - V_243 ;
}
return V_244 ;
}
static inline T_2 F_191 ( struct V_34 * V_35 , T_2 V_246 )
{
T_2 V_36 ;
V_36 = V_246 * ( sizeof( struct V_116 ) +
sizeof( struct V_163 ) ) ;
if ( ! F_76 ( V_35 -> V_37 , V_121 ) )
V_36 += V_246 * sizeof( struct V_138 ) ;
return F_192 ( V_36 , F_193 ( V_35 ) ) ;
}
T_2 F_194 ( struct V_34 * V_35 , T_2 V_247 )
{
T_2 V_248 ;
T_2 V_249 ;
T_2 V_250 ;
V_248 = F_193 ( V_35 ) - sizeof( struct V_251 ) ;
V_249 = F_195 ( V_248 ,
( T_2 ) F_196 ( V_35 -> V_37 -> V_252 ) ) ;
V_250 = F_195 ( V_247 , V_35 -> V_253 ) ;
V_250 += V_249 - 1 ;
V_250 = F_195 ( V_250 , V_249 ) ;
return V_250 ;
}
int F_197 ( struct V_109 * V_110 ,
struct V_34 * V_35 )
{
struct V_254 * V_255 ;
T_2 V_231 = V_110 -> V_127 -> V_115 . V_229 ;
T_2 V_247 = V_110 -> V_127 -> V_115 . V_237 ;
T_2 V_256 = V_110 -> V_127 -> V_256 ;
T_2 V_36 , V_257 ;
int V_29 = 0 ;
V_36 = F_198 ( V_35 , 1 ) ;
V_231 = F_191 ( V_35 , V_231 ) ;
if ( V_231 > 1 )
V_36 += ( V_231 - 1 ) * V_35 -> V_87 ;
V_36 <<= 1 ;
V_36 += F_194 ( V_35 , V_247 ) * V_35 -> V_87 ;
V_257 = F_198 ( V_35 ,
V_256 ) ;
V_255 = & V_35 -> V_37 -> V_258 ;
if ( V_255 -> V_105 -> V_108 ) {
V_257 <<= 1 ;
V_36 <<= 1 ;
}
F_11 ( & V_255 -> V_52 ) ;
if ( V_255 -> V_10 <= V_36 + V_257 )
V_29 = 1 ;
F_13 ( & V_255 -> V_52 ) ;
return V_29 ;
}
int F_199 ( struct V_109 * V_110 ,
struct V_34 * V_35 )
{
struct V_12 * V_37 = V_35 -> V_37 ;
T_2 V_234 =
F_200 ( & V_110 -> V_127 -> V_115 . V_234 ) ;
T_2 V_259 ;
T_2 V_260 ;
F_2 () ;
V_259 = V_37 -> V_240 ;
V_260 = V_234 * V_259 ;
if ( V_234 * V_259 >= V_261 )
return 1 ;
if ( V_260 >= V_261 / 2 )
return 2 ;
return F_197 ( V_110 , V_35 ) ;
}
static void F_201 ( struct V_60 * V_61 )
{
struct V_262 * V_263 ;
struct V_109 * V_110 ;
int V_29 ;
V_263 = F_32 ( V_61 , struct V_262 , V_61 ) ;
V_110 = F_202 ( V_263 -> V_35 ) ;
if ( F_203 ( V_110 ) ) {
V_263 -> error = F_204 ( V_110 ) ;
goto V_264;
}
V_110 -> V_265 = true ;
V_29 = F_205 ( V_110 , V_263 -> V_35 , V_263 -> V_8 ) ;
if ( V_29 )
V_263 -> error = V_29 ;
V_29 = F_206 ( V_110 , V_263 -> V_35 ) ;
if ( V_29 && ! V_263 -> error )
V_263 -> error = V_29 ;
V_264:
if ( V_263 -> V_265 )
F_207 ( & V_263 -> V_88 ) ;
else
F_9 ( V_263 ) ;
}
int F_208 ( struct V_34 * V_35 ,
unsigned long V_8 , int V_88 )
{
struct V_262 * V_263 ;
int V_29 ;
V_263 = F_209 ( sizeof( * V_263 ) , V_40 ) ;
if ( ! V_263 )
return - V_71 ;
V_263 -> V_35 = V_35 -> V_37 -> V_86 ;
V_263 -> V_8 = V_8 ;
V_263 -> error = 0 ;
if ( V_88 )
V_263 -> V_265 = 1 ;
else
V_263 -> V_265 = 0 ;
F_210 ( & V_263 -> V_88 ) ;
F_58 ( & V_263 -> V_61 , V_266 ,
F_201 , NULL , NULL ) ;
F_66 ( V_35 -> V_37 -> V_267 , & V_263 -> V_61 ) ;
if ( V_88 ) {
F_211 ( & V_263 -> V_88 ) ;
V_29 = V_263 -> error ;
F_9 ( V_263 ) ;
return V_29 ;
}
return 0 ;
}
int F_205 ( struct V_109 * V_110 ,
struct V_34 * V_35 , unsigned long V_8 )
{
struct V_15 * V_128 ;
struct V_114 * V_115 ;
struct V_113 * V_104 ;
int V_29 ;
int V_268 = V_8 == ( unsigned long ) - 1 ;
bool V_269 = V_110 -> V_269 ;
if ( V_110 -> V_221 )
return 0 ;
if ( V_35 == V_35 -> V_37 -> V_62 )
V_35 = V_35 -> V_37 -> V_86 ;
V_115 = & V_110 -> V_127 -> V_115 ;
if ( V_8 == 0 )
V_8 = F_200 ( & V_115 -> V_234 ) * 2 ;
V_77:
#ifdef F_212
V_115 -> V_270 = F_188 ( & V_115 -> V_35 ) ;
#endif
V_110 -> V_269 = false ;
V_29 = F_175 ( V_110 , V_35 , V_8 ) ;
if ( V_29 < 0 ) {
F_153 ( V_110 , V_35 , V_29 ) ;
return V_29 ;
}
if ( V_268 ) {
if ( ! F_172 ( & V_110 -> V_271 ) )
F_213 ( V_110 , V_35 ) ;
F_11 ( & V_115 -> V_52 ) ;
V_128 = F_189 ( & V_115 -> V_233 ) ;
if ( ! V_128 ) {
F_13 ( & V_115 -> V_52 ) ;
goto V_72;
}
V_8 = ( unsigned long ) - 1 ;
while ( V_128 ) {
V_104 = F_12 ( V_128 , struct V_113 ,
V_232 ) ;
if ( F_167 ( & V_104 -> V_128 ) ) {
struct V_211 * V_151 ;
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
V_128 = F_214 ( V_128 ) ;
}
F_13 ( & V_115 -> V_52 ) ;
F_47 () ;
goto V_77;
}
V_72:
F_215 ( V_110 ) ;
V_110 -> V_269 = V_269 ;
return 0 ;
}
int F_216 ( struct V_109 * V_110 ,
struct V_34 * V_35 ,
T_2 V_27 , T_2 V_36 , T_2 V_7 ,
int V_167 , int V_184 )
{
struct V_180 * V_129 ;
int V_29 ;
V_129 = F_217 () ;
if ( ! V_129 )
return - V_71 ;
V_129 -> V_131 = V_7 ;
V_129 -> V_130 = 1 ;
V_129 -> V_220 = 0 ;
V_129 -> V_184 = V_184 ? 1 : 0 ;
V_129 -> V_167 = V_167 ;
V_29 = F_218 ( V_35 -> V_37 , V_110 , V_27 ,
V_36 , V_129 ) ;
if ( V_29 )
F_181 ( V_129 ) ;
return V_29 ;
}
static T_1 int F_219 ( struct V_109 * V_110 ,
struct V_34 * V_35 ,
struct V_63 * V_64 ,
T_2 V_22 , T_2 V_33 , T_2 V_27 )
{
struct V_113 * V_104 ;
struct V_211 * V_151 ;
struct V_215 * V_272 ;
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
F_173 (ref, &head->ref_list, list) {
if ( V_151 -> type != V_155 ) {
V_29 = 1 ;
break;
}
V_272 = F_155 ( V_151 ) ;
if ( V_272 -> V_35 != V_35 -> V_273 . V_22 ||
V_272 -> V_22 != V_22 ||
V_272 -> V_33 != V_33 ) {
V_29 = 1 ;
break;
}
}
F_13 ( & V_104 -> V_52 ) ;
F_46 ( & V_104 -> V_78 ) ;
return V_29 ;
}
static T_1 int F_220 ( struct V_109 * V_110 ,
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
if ( F_221 ( V_66 , V_117 ) <=
F_222 ( & V_35 -> V_274 ) )
goto V_72;
V_164 = (struct V_163 * ) ( V_117 + 1 ) ;
if ( F_119 ( V_66 , V_164 ) !=
V_155 )
goto V_72;
V_151 = (struct V_150 * ) ( & V_164 -> V_33 ) ;
if ( F_79 ( V_66 , V_117 ) !=
F_113 ( V_66 , V_151 ) ||
F_100 ( V_66 , V_151 ) !=
V_35 -> V_273 . V_22 ||
F_101 ( V_66 , V_151 ) != V_22 ||
F_102 ( V_66 , V_151 ) != V_33 )
goto V_72;
V_29 = 0 ;
V_72:
return V_29 ;
}
int F_223 ( struct V_109 * V_110 ,
struct V_34 * V_35 ,
T_2 V_22 , T_2 V_33 , T_2 V_27 )
{
struct V_63 * V_64 ;
int V_29 ;
int V_275 ;
V_64 = F_33 () ;
if ( ! V_64 )
return - V_153 ;
do {
V_29 = F_220 ( V_110 , V_35 , V_64 , V_22 ,
V_33 , V_27 ) ;
if ( V_29 && V_29 != - V_153 )
goto V_72;
V_275 = F_219 ( V_110 , V_35 , V_64 , V_22 ,
V_33 , V_27 ) ;
} while ( V_275 == - V_178 );
if ( V_275 && V_275 != - V_153 ) {
V_29 = V_275 ;
goto V_72;
}
if ( V_29 != - V_153 || V_275 != - V_153 )
V_29 = 0 ;
V_72:
F_50 ( V_64 ) ;
if ( V_35 -> V_273 . V_22 == V_276 )
F_8 ( V_29 > 0 ) ;
return V_29 ;
}
static int F_224 ( struct V_109 * V_110 ,
struct V_34 * V_35 ,
struct V_65 * V_277 ,
int V_278 , int V_279 )
{
T_2 V_27 ;
T_2 V_36 ;
T_2 V_17 ;
T_2 V_217 ;
T_3 V_70 ;
struct V_67 V_21 ;
struct V_280 * V_281 ;
int V_43 ;
int V_167 ;
int V_29 = 0 ;
int (* F_225)( struct V_109 * , struct V_34 * ,
T_2 , T_2 , T_2 , T_2 , T_2 , T_2 , int );
if ( F_226 ( V_35 ) )
return 0 ;
V_217 = F_227 ( V_277 ) ;
V_70 = F_38 ( V_277 ) ;
V_167 = F_228 ( V_277 ) ;
if ( ! F_229 ( V_282 , & V_35 -> V_283 ) && V_167 == 0 )
return 0 ;
if ( V_279 )
F_225 = F_148 ;
else
F_225 = V_284 ;
if ( V_278 )
V_17 = V_277 -> V_32 ;
else
V_17 = 0 ;
for ( V_43 = 0 ; V_43 < V_70 ; V_43 ++ ) {
if ( V_167 == 0 ) {
F_40 ( V_277 , & V_21 , V_43 ) ;
if ( V_21 . type != V_285 )
continue;
V_281 = F_78 ( V_277 , V_43 ,
struct V_280 ) ;
if ( F_230 ( V_277 , V_281 ) ==
V_286 )
continue;
V_27 = F_231 ( V_277 , V_281 ) ;
if ( V_27 == 0 )
continue;
V_36 = F_232 ( V_277 , V_281 ) ;
V_21 . V_33 -= F_233 ( V_277 , V_281 ) ;
V_29 = F_225 ( V_110 , V_35 , V_27 , V_36 ,
V_17 , V_217 , V_21 . V_22 ,
V_21 . V_33 , 1 ) ;
if ( V_29 )
goto V_156;
} else {
V_27 = F_234 ( V_277 , V_43 ) ;
V_36 = V_35 -> V_87 ;
V_29 = F_225 ( V_110 , V_35 , V_27 , V_36 ,
V_17 , V_217 , V_167 - 1 , 0 ,
1 ) ;
if ( V_29 )
goto V_156;
}
}
return 0 ;
V_156:
return V_29 ;
}
int F_235 ( struct V_109 * V_110 , struct V_34 * V_35 ,
struct V_65 * V_277 , int V_278 )
{
return F_224 ( V_110 , V_35 , V_277 , V_278 , 1 ) ;
}
int F_236 ( struct V_109 * V_110 , struct V_34 * V_35 ,
struct V_65 * V_277 , int V_278 )
{
return F_224 ( V_110 , V_35 , V_277 , V_278 , 0 ) ;
}
static int F_237 ( struct V_109 * V_110 ,
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
V_139 = F_238 ( V_66 , V_64 -> V_83 [ 0 ] ) ;
F_239 ( V_66 , & V_2 -> V_135 , V_139 , sizeof( V_2 -> V_135 ) ) ;
F_95 ( V_66 ) ;
V_156:
F_44 ( V_64 ) ;
return V_29 ;
}
static struct V_1 *
F_240 ( struct V_34 * V_35 ,
struct V_1 * V_2 )
{
struct V_15 * V_128 ;
F_11 ( & V_35 -> V_37 -> V_18 ) ;
if ( F_241 ( & V_2 -> V_20 ) ) {
const T_2 V_287 = V_2 -> V_21 . V_22 + V_2 -> V_21 . V_33 ;
F_13 ( & V_35 -> V_37 -> V_18 ) ;
F_6 ( V_2 ) ;
V_2 = F_67 ( V_35 -> V_37 ,
V_287 ) ;
return V_2 ;
}
V_128 = F_214 ( & V_2 -> V_20 ) ;
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
static int F_242 ( struct V_1 * V_14 ,
struct V_109 * V_110 ,
struct V_63 * V_64 )
{
struct V_34 * V_35 = V_14 -> V_37 -> V_86 ;
struct V_288 * V_288 = NULL ;
T_2 V_289 = 0 ;
int V_290 = V_291 ;
T_2 V_292 = 0 ;
int V_293 = 0 ;
int V_29 = 0 ;
if ( V_14 -> V_21 . V_33 < ( 100 * 1024 * 1024 ) ) {
F_11 ( & V_14 -> V_52 ) ;
V_14 -> V_294 = V_295 ;
F_13 ( & V_14 -> V_52 ) ;
return 0 ;
}
if ( V_110 -> V_221 )
return 0 ;
V_77:
V_288 = F_243 ( V_35 , V_14 , V_64 ) ;
if ( F_203 ( V_288 ) && F_204 ( V_288 ) != - V_153 ) {
V_29 = F_204 ( V_288 ) ;
F_44 ( V_64 ) ;
goto V_72;
}
if ( F_203 ( V_288 ) ) {
F_30 ( V_293 ) ;
V_293 ++ ;
if ( V_14 -> V_296 )
goto V_123;
V_29 = F_244 ( V_35 , V_110 , V_14 , V_64 ) ;
if ( V_29 )
goto V_123;
goto V_77;
}
if ( V_14 -> V_297 == V_110 -> V_298 &&
F_245 ( V_288 ) ) {
V_290 = V_299 ;
goto V_300;
}
F_246 ( V_288 ) -> V_301 = 0 ;
V_29 = F_247 ( V_110 , V_35 , V_288 ) ;
if ( V_29 ) {
F_153 ( V_110 , V_35 , V_29 ) ;
goto V_300;
}
F_8 ( V_29 ) ;
if ( F_245 ( V_288 ) > 0 ) {
V_29 = F_248 ( V_35 ,
& V_35 -> V_37 -> V_258 ) ;
if ( V_29 )
goto V_300;
V_29 = F_249 ( V_35 , V_110 , NULL , V_288 ) ;
if ( V_29 )
goto V_300;
}
F_11 ( & V_14 -> V_52 ) ;
if ( V_14 -> V_3 != V_4 ||
! F_250 ( V_35 , V_302 ) ) {
V_290 = V_295 ;
F_13 ( & V_14 -> V_52 ) ;
goto V_300;
}
F_13 ( & V_14 -> V_52 ) ;
V_292 = F_192 ( V_14 -> V_21 . V_33 , 256 * 1024 * 1024 ) ;
if ( ! V_292 )
V_292 = 1 ;
V_292 *= 16 ;
V_292 *= V_303 ;
V_29 = F_251 ( V_288 , V_292 , V_292 ) ;
if ( V_29 )
goto V_300;
V_29 = F_252 ( V_288 , V_110 , 0 , 0 , V_292 ,
V_292 , V_292 ,
& V_289 ) ;
if ( ! V_29 )
V_290 = V_299 ;
F_253 ( V_288 , V_292 ) ;
V_300:
F_254 ( V_288 ) ;
V_123:
F_44 ( V_64 ) ;
V_72:
F_11 ( & V_14 -> V_52 ) ;
if ( ! V_29 && V_290 == V_299 )
V_14 -> V_297 = V_110 -> V_298 ;
V_14 -> V_294 = V_290 ;
F_13 ( & V_14 -> V_52 ) ;
return V_29 ;
}
int F_255 ( struct V_109 * V_110 ,
struct V_34 * V_35 )
{
struct V_1 * V_2 , * V_304 ;
struct V_305 * V_306 = V_110 -> V_127 ;
struct V_63 * V_64 ;
if ( F_172 ( & V_306 -> V_307 ) ||
! F_250 ( V_35 , V_302 ) )
return 0 ;
V_64 = F_33 () ;
if ( ! V_64 )
return - V_71 ;
F_256 (cache, tmp, &cur_trans->dirty_bgs,
dirty_list) {
if ( V_2 -> V_294 == V_308 )
F_242 ( V_2 , V_110 , V_64 ) ;
}
F_50 ( V_64 ) ;
return 0 ;
}
int F_257 ( struct V_109 * V_110 ,
struct V_34 * V_35 )
{
struct V_1 * V_2 ;
struct V_305 * V_306 = V_110 -> V_127 ;
int V_29 = 0 ;
int V_309 ;
struct V_63 * V_64 = NULL ;
F_258 ( V_310 ) ;
struct V_103 * V_311 = & V_306 -> V_312 ;
int V_313 = 0 ;
int V_314 = 0 ;
F_11 ( & V_306 -> V_315 ) ;
if ( F_172 ( & V_306 -> V_307 ) ) {
F_13 ( & V_306 -> V_315 ) ;
return 0 ;
}
F_259 ( & V_306 -> V_307 , & V_310 ) ;
F_13 ( & V_306 -> V_315 ) ;
V_77:
F_213 ( V_110 , V_35 ) ;
if ( ! V_64 ) {
V_64 = F_33 () ;
if ( ! V_64 )
return - V_71 ;
}
F_35 ( & V_110 -> V_127 -> V_316 ) ;
while ( ! F_172 ( & V_310 ) ) {
V_2 = F_260 ( & V_310 ,
struct V_1 ,
V_317 ) ;
if ( ! F_172 ( & V_2 -> V_318 ) ) {
F_261 ( & V_2 -> V_318 ) ;
F_262 ( V_35 , V_110 , V_2 ,
& V_2 -> V_319 , V_64 ,
V_2 -> V_21 . V_22 ) ;
F_6 ( V_2 ) ;
}
F_11 ( & V_306 -> V_315 ) ;
F_261 ( & V_2 -> V_317 ) ;
F_13 ( & V_306 -> V_315 ) ;
V_309 = 1 ;
F_242 ( V_2 , V_110 , V_64 ) ;
if ( V_2 -> V_294 == V_299 ) {
V_2 -> V_319 . V_288 = NULL ;
V_29 = F_263 ( V_35 , V_110 , V_2 , V_64 ) ;
if ( V_29 == 0 && V_2 -> V_319 . V_288 ) {
V_313 ++ ;
V_309 = 0 ;
F_64 ( & V_2 -> V_318 , V_311 ) ;
} else {
V_29 = 0 ;
}
}
if ( ! V_29 ) {
V_29 = F_237 ( V_110 , V_35 , V_64 , V_2 ) ;
if ( V_29 == - V_153 ) {
V_29 = 0 ;
F_11 ( & V_306 -> V_315 ) ;
if ( F_172 ( & V_2 -> V_317 ) ) {
F_64 ( & V_2 -> V_317 ,
& V_306 -> V_307 ) ;
F_4 ( V_2 ) ;
}
F_13 ( & V_306 -> V_315 ) ;
} else if ( V_29 ) {
F_153 ( V_110 , V_35 , V_29 ) ;
}
}
if ( V_309 )
F_6 ( V_2 ) ;
if ( V_29 )
break;
F_46 ( & V_110 -> V_127 -> V_316 ) ;
F_35 ( & V_110 -> V_127 -> V_316 ) ;
}
F_46 ( & V_110 -> V_127 -> V_316 ) ;
V_29 = F_205 ( V_110 , V_35 , 0 ) ;
if ( ! V_29 && V_314 == 0 ) {
V_314 ++ ;
F_11 ( & V_306 -> V_315 ) ;
F_259 ( & V_306 -> V_307 , & V_310 ) ;
if ( ! F_172 ( & V_310 ) ) {
F_13 ( & V_306 -> V_315 ) ;
goto V_77;
}
F_13 ( & V_306 -> V_315 ) ;
}
F_50 ( V_64 ) ;
return V_29 ;
}
int F_264 ( struct V_109 * V_110 ,
struct V_34 * V_35 )
{
struct V_1 * V_2 ;
struct V_305 * V_306 = V_110 -> V_127 ;
int V_29 = 0 ;
int V_309 ;
struct V_63 * V_64 ;
struct V_103 * V_311 = & V_306 -> V_312 ;
int V_313 = 0 ;
V_64 = F_33 () ;
if ( ! V_64 )
return - V_71 ;
while ( ! F_172 ( & V_306 -> V_307 ) ) {
V_2 = F_260 ( & V_306 -> V_307 ,
struct V_1 ,
V_317 ) ;
if ( ! F_172 ( & V_2 -> V_318 ) ) {
F_261 ( & V_2 -> V_318 ) ;
F_262 ( V_35 , V_110 , V_2 ,
& V_2 -> V_319 , V_64 ,
V_2 -> V_21 . V_22 ) ;
F_6 ( V_2 ) ;
}
F_261 ( & V_2 -> V_317 ) ;
V_309 = 1 ;
F_242 ( V_2 , V_110 , V_64 ) ;
if ( ! V_29 )
V_29 = F_205 ( V_110 , V_35 , ( unsigned long ) - 1 ) ;
if ( ! V_29 && V_2 -> V_294 == V_299 ) {
V_2 -> V_319 . V_288 = NULL ;
V_29 = F_263 ( V_35 , V_110 , V_2 , V_64 ) ;
if ( V_29 == 0 && V_2 -> V_319 . V_288 ) {
V_313 ++ ;
V_309 = 0 ;
F_64 ( & V_2 -> V_318 , V_311 ) ;
} else {
V_29 = 0 ;
}
}
if ( ! V_29 ) {
V_29 = F_237 ( V_110 , V_35 , V_64 , V_2 ) ;
if ( V_29 )
F_153 ( V_110 , V_35 , V_29 ) ;
}
if ( V_309 )
F_6 ( V_2 ) ;
}
while ( ! F_172 ( V_311 ) ) {
V_2 = F_260 ( V_311 , struct V_1 ,
V_318 ) ;
F_261 ( & V_2 -> V_318 ) ;
F_262 ( V_35 , V_110 , V_2 ,
& V_2 -> V_319 , V_64 , V_2 -> V_21 . V_22 ) ;
F_6 ( V_2 ) ;
}
F_50 ( V_64 ) ;
return V_29 ;
}
int F_265 ( struct V_34 * V_35 , T_2 V_27 )
{
struct V_1 * V_14 ;
int V_320 = 0 ;
V_14 = F_68 ( V_35 -> V_37 , V_27 ) ;
if ( ! V_14 || V_14 -> V_296 )
V_320 = 1 ;
if ( V_14 )
F_6 ( V_14 ) ;
return V_320 ;
}
static const char * F_266 ( T_2 V_7 )
{
switch ( V_7 ) {
case V_321 | V_322 :
return L_3 ;
case V_321 :
return L_4 ;
case V_322 :
return L_5 ;
case V_323 :
return L_6 ;
default:
F_8 ( 1 ) ;
return L_7 ;
} ;
}
static int F_267 ( struct V_12 * V_13 , T_2 V_7 ,
T_2 V_324 , T_2 V_325 ,
struct V_102 * * V_105 )
{
struct V_102 * V_106 ;
int V_43 ;
int V_326 ;
int V_29 ;
if ( V_7 & ( V_327 | V_328 |
V_329 ) )
V_326 = 2 ;
else
V_326 = 1 ;
V_106 = F_69 ( V_13 , V_7 ) ;
if ( V_106 ) {
F_11 ( & V_106 -> V_52 ) ;
V_106 -> V_324 += V_324 ;
V_106 -> V_330 += V_324 * V_326 ;
V_106 -> V_325 += V_325 ;
V_106 -> V_331 += V_325 * V_326 ;
if ( V_324 > 0 )
V_106 -> V_108 = 0 ;
F_13 ( & V_106 -> V_52 ) ;
* V_105 = V_106 ;
return 0 ;
}
V_106 = F_53 ( sizeof( * V_106 ) , V_40 ) ;
if ( ! V_106 )
return - V_71 ;
V_29 = F_268 ( & V_106 -> V_332 , 0 , V_333 ) ;
if ( V_29 ) {
F_9 ( V_106 ) ;
return V_29 ;
}
for ( V_43 = 0 ; V_43 < V_334 ; V_43 ++ )
F_54 ( & V_106 -> V_335 [ V_43 ] ) ;
F_269 ( & V_106 -> V_336 ) ;
F_270 ( & V_106 -> V_52 ) ;
V_106 -> V_7 = V_7 & V_107 ;
V_106 -> V_324 = V_324 ;
V_106 -> V_330 = V_324 * V_326 ;
V_106 -> V_325 = V_325 ;
V_106 -> V_331 = V_325 * V_326 ;
V_106 -> V_337 = 0 ;
V_106 -> V_338 = 0 ;
V_106 -> V_339 = 0 ;
V_106 -> V_340 = 0 ;
V_106 -> V_108 = 0 ;
V_106 -> V_341 = V_342 ;
V_106 -> V_343 = 0 ;
V_106 -> V_344 = 0 ;
F_56 ( & V_106 -> V_88 ) ;
F_54 ( & V_106 -> V_345 ) ;
V_29 = F_271 ( & V_106 -> V_346 , & V_347 ,
V_13 -> V_348 , L_8 ,
F_266 ( V_106 -> V_7 ) ) ;
if ( V_29 ) {
F_9 ( V_106 ) ;
return V_29 ;
}
* V_105 = V_106 ;
F_272 ( & V_106 -> V_90 , & V_13 -> V_105 ) ;
if ( V_7 & V_322 )
V_13 -> V_349 = V_106 ;
return V_29 ;
}
static void F_273 ( struct V_12 * V_37 , T_2 V_7 )
{
T_2 V_350 = F_274 ( V_7 ) &
V_351 ;
F_275 ( & V_37 -> V_352 ) ;
if ( V_7 & V_322 )
V_37 -> V_353 |= V_350 ;
if ( V_7 & V_321 )
V_37 -> V_354 |= V_350 ;
if ( V_7 & V_323 )
V_37 -> V_355 |= V_350 ;
F_276 ( & V_37 -> V_352 ) ;
}
static T_2 F_277 ( struct V_12 * V_37 , T_2 V_7 )
{
struct V_356 * V_357 = V_37 -> V_358 ;
T_2 V_359 = 0 ;
if ( ! V_357 )
return 0 ;
if ( V_7 & V_322 &&
V_357 -> V_360 . V_7 & V_361 ) {
V_359 = V_322 | V_357 -> V_360 . V_359 ;
} else if ( V_7 & V_323 &&
V_357 -> V_362 . V_7 & V_361 ) {
V_359 = V_323 | V_357 -> V_362 . V_359 ;
} else if ( V_7 & V_321 &&
V_357 -> V_363 . V_7 & V_361 ) {
V_359 = V_321 | V_357 -> V_363 . V_359 ;
}
return V_359 ;
}
static T_2 F_278 ( struct V_34 * V_35 , T_2 V_7 )
{
T_2 V_364 = V_35 -> V_37 -> V_365 -> V_366 ;
T_2 V_359 ;
T_2 V_304 ;
F_11 ( & V_35 -> V_37 -> V_367 ) ;
V_359 = F_277 ( V_35 -> V_37 , V_7 ) ;
if ( V_359 ) {
if ( ( V_7 & V_359 ) & V_351 ) {
F_13 ( & V_35 -> V_37 -> V_367 ) ;
return F_279 ( V_359 ) ;
}
}
F_13 ( & V_35 -> V_37 -> V_367 ) ;
if ( V_364 == 1 )
V_7 &= ~ ( V_328 | V_368 |
V_369 ) ;
if ( V_364 < 3 )
V_7 &= ~ V_370 ;
if ( V_364 < 4 )
V_7 &= ~ V_329 ;
V_304 = V_7 & ( V_327 | V_368 |
V_328 | V_369 |
V_370 | V_329 ) ;
V_7 &= ~ V_304 ;
if ( V_304 & V_370 )
V_304 = V_370 ;
else if ( V_304 & V_369 )
V_304 = V_369 ;
else if ( V_304 & V_329 )
V_304 = V_329 ;
else if ( V_304 & V_328 )
V_304 = V_328 ;
else if ( V_304 & V_368 )
V_304 = V_368 ;
return F_279 ( V_7 | V_304 ) ;
}
static T_2 F_280 ( struct V_34 * V_35 , T_2 V_371 )
{
unsigned V_227 ;
T_2 V_7 ;
do {
V_7 = V_371 ;
V_227 = F_281 ( & V_35 -> V_37 -> V_352 ) ;
if ( V_7 & V_322 )
V_7 |= V_35 -> V_37 -> V_353 ;
else if ( V_7 & V_323 )
V_7 |= V_35 -> V_37 -> V_355 ;
else if ( V_7 & V_321 )
V_7 |= V_35 -> V_37 -> V_354 ;
} while ( F_282 ( & V_35 -> V_37 -> V_352 , V_227 ) );
return F_278 ( V_35 , V_7 ) ;
}
T_2 F_283 ( struct V_34 * V_35 , int V_360 )
{
T_2 V_7 ;
T_2 V_29 ;
if ( V_360 )
V_7 = V_322 ;
else if ( V_35 == V_35 -> V_37 -> V_372 )
V_7 = V_323 ;
else
V_7 = V_321 ;
V_29 = F_280 ( V_35 , V_7 ) ;
return V_29 ;
}
int F_251 ( struct V_288 * V_288 , T_2 V_203 , T_2 V_373 )
{
struct V_102 * V_349 ;
struct V_34 * V_35 = F_246 ( V_288 ) -> V_35 ;
struct V_12 * V_37 = V_35 -> V_37 ;
T_2 V_374 ;
int V_29 = 0 ;
int V_375 = 2 ;
int V_376 ;
V_203 = F_141 ( V_203 , V_35 -> V_253 ) ;
if ( F_284 ( V_288 ) ) {
V_375 = 0 ;
ASSERT ( V_377 -> V_378 ) ;
}
V_349 = V_37 -> V_349 ;
if ( ! V_349 )
goto V_379;
V_77:
F_11 ( & V_349 -> V_52 ) ;
V_374 = V_349 -> V_325 + V_349 -> V_338 +
V_349 -> V_337 + V_349 -> V_339 +
V_349 -> V_340 ;
if ( V_374 + V_203 > V_349 -> V_324 ) {
struct V_109 * V_110 ;
if ( ! V_349 -> V_108 ) {
T_2 V_380 ;
V_349 -> V_341 = V_381 ;
F_13 ( & V_349 -> V_52 ) ;
V_379:
V_380 = F_283 ( V_35 , 1 ) ;
V_110 = F_202 ( V_35 ) ;
if ( F_203 ( V_110 ) )
return F_204 ( V_110 ) ;
V_29 = F_285 ( V_110 , V_35 -> V_37 -> V_62 ,
V_380 ,
V_342 ) ;
F_206 ( V_110 , V_35 ) ;
if ( V_29 < 0 ) {
if ( V_29 != - V_382 )
return V_29 ;
else {
V_376 = 1 ;
goto V_383;
}
}
if ( ! V_349 )
V_349 = V_37 -> V_349 ;
goto V_77;
}
V_376 = F_286 (
& V_349 -> V_332 ,
V_374 + V_203 - V_349 -> V_324 ) ;
F_13 ( & V_349 -> V_52 ) ;
V_383:
if ( V_375 &&
! F_200 ( & V_35 -> V_37 -> V_384 ) ) {
V_375 -- ;
if ( V_375 > 0 )
F_287 ( V_37 , - 1 ) ;
V_110 = F_202 ( V_35 ) ;
if ( F_203 ( V_110 ) )
return F_204 ( V_110 ) ;
if ( V_376 >= 0 ||
V_110 -> V_127 -> V_385 ||
V_375 > 0 ) {
V_29 = F_288 ( V_110 , V_35 ) ;
if ( V_29 )
return V_29 ;
F_63 ( & V_35 -> V_37 -> V_386 ) ;
F_65 ( & V_35 -> V_37 -> V_386 ) ;
goto V_77;
} else {
F_206 ( V_110 , V_35 ) ;
}
}
F_289 ( V_35 -> V_37 ,
L_9 ,
V_349 -> V_7 , V_203 , 1 ) ;
return - V_382 ;
}
V_29 = F_290 ( V_35 , V_373 ) ;
if ( V_29 )
goto V_72;
V_349 -> V_340 += V_203 ;
F_289 ( V_35 -> V_37 , L_10 ,
V_349 -> V_7 , V_203 , 1 ) ;
V_72:
F_13 ( & V_349 -> V_52 ) ;
return V_29 ;
}
void F_253 ( struct V_288 * V_288 , T_2 V_203 )
{
struct V_34 * V_35 = F_246 ( V_288 ) -> V_35 ;
struct V_102 * V_349 ;
V_203 = F_141 ( V_203 , V_35 -> V_253 ) ;
V_349 = V_35 -> V_37 -> V_349 ;
F_11 ( & V_349 -> V_52 ) ;
F_8 ( V_349 -> V_340 < V_203 ) ;
V_349 -> V_340 -= V_203 ;
F_289 ( V_35 -> V_37 , L_10 ,
V_349 -> V_7 , V_203 , 0 ) ;
F_13 ( & V_349 -> V_52 ) ;
}
static void F_291 ( struct V_12 * V_13 )
{
struct V_103 * V_104 = & V_13 -> V_105 ;
struct V_102 * V_106 ;
F_70 () ;
F_71 (found, head, list) {
if ( V_106 -> V_7 & V_321 )
V_106 -> V_341 = V_381 ;
}
F_72 () ;
}
static inline T_2 F_292 ( struct V_254 * V_387 )
{
return ( V_387 -> V_56 << 1 ) ;
}
static int F_293 ( struct V_34 * V_35 ,
struct V_102 * V_388 , int V_389 )
{
struct V_254 * V_255 = & V_35 -> V_37 -> V_258 ;
T_2 V_36 = V_388 -> V_324 - V_388 -> V_339 ;
T_2 V_390 = V_388 -> V_325 + V_388 -> V_338 ;
T_2 V_391 ;
if ( V_389 == V_381 )
return 1 ;
if ( V_388 -> V_7 & V_321 )
V_390 += F_292 ( V_255 ) ;
if ( V_389 == V_392 ) {
V_391 = F_294 ( V_35 -> V_37 -> V_252 ) ;
V_391 = F_34 ( T_2 , 64 * 1024 * 1024 ,
F_295 ( V_391 , 1 ) ) ;
if ( V_36 - V_390 < V_391 )
return 1 ;
}
if ( V_390 + 2 * 1024 * 1024 < F_296 ( V_36 , 8 ) )
return 0 ;
return 1 ;
}
static T_2 F_297 ( struct V_34 * V_35 , T_2 type )
{
T_2 V_393 ;
if ( type & ( V_329 |
V_368 |
V_369 |
V_370 ) )
V_393 = V_35 -> V_37 -> V_365 -> V_366 ;
else if ( type & V_328 )
V_393 = 2 ;
else
V_393 = 1 ;
return V_393 ;
}
void F_298 ( struct V_109 * V_110 ,
struct V_34 * V_35 ,
T_2 type )
{
struct V_102 * V_13 ;
T_2 V_394 ;
T_2 V_391 ;
int V_29 = 0 ;
T_2 V_395 ;
ASSERT ( F_299 ( & V_35 -> V_37 -> V_396 ) ) ;
V_13 = F_69 ( V_35 -> V_37 , V_323 ) ;
F_11 ( & V_13 -> V_52 ) ;
V_394 = V_13 -> V_324 - V_13 -> V_325 - V_13 -> V_337 -
V_13 -> V_338 - V_13 -> V_339 -
V_13 -> V_340 ;
F_13 ( & V_13 -> V_52 ) ;
V_395 = F_297 ( V_35 , type ) ;
V_391 = F_300 ( V_35 , V_395 ) +
F_198 ( V_35 , 1 ) ;
if ( V_394 < V_391 && F_250 ( V_35 , V_397 ) ) {
F_301 ( V_35 -> V_37 , L_11 ,
V_394 , V_391 , type ) ;
F_302 ( V_13 , 0 , 0 ) ;
}
if ( V_394 < V_391 ) {
T_2 V_7 ;
V_7 = F_283 ( V_35 -> V_37 -> V_372 , 0 ) ;
V_29 = F_303 ( V_110 , V_35 , V_7 ) ;
}
if ( ! V_29 ) {
V_29 = F_304 ( V_35 -> V_37 -> V_372 ,
& V_35 -> V_37 -> V_398 ,
V_391 , V_399 ) ;
if ( ! V_29 )
V_110 -> V_400 += V_391 ;
}
}
static int F_285 ( struct V_109 * V_110 ,
struct V_34 * V_62 , T_2 V_7 , int V_389 )
{
struct V_102 * V_105 ;
struct V_12 * V_37 = V_62 -> V_37 ;
int V_401 = 0 ;
int V_29 = 0 ;
if ( V_110 -> V_402 )
return - V_382 ;
V_105 = F_69 ( V_62 -> V_37 , V_7 ) ;
if ( ! V_105 ) {
V_29 = F_267 ( V_62 -> V_37 , V_7 ,
0 , 0 , & V_105 ) ;
F_30 ( V_29 ) ;
}
F_30 ( ! V_105 ) ;
V_77:
F_11 ( & V_105 -> V_52 ) ;
if ( V_389 < V_105 -> V_341 )
V_389 = V_105 -> V_341 ;
if ( V_105 -> V_108 ) {
if ( F_293 ( V_62 , V_105 , V_389 ) )
V_29 = - V_382 ;
else
V_29 = 0 ;
F_13 ( & V_105 -> V_52 ) ;
return V_29 ;
}
if ( ! F_293 ( V_62 , V_105 , V_389 ) ) {
F_13 ( & V_105 -> V_52 ) ;
return 0 ;
} else if ( V_105 -> V_343 ) {
V_401 = 1 ;
} else {
V_105 -> V_343 = 1 ;
}
F_13 ( & V_105 -> V_52 ) ;
F_35 ( & V_37 -> V_396 ) ;
if ( V_401 ) {
F_46 ( & V_37 -> V_396 ) ;
V_401 = 0 ;
goto V_77;
}
V_110 -> V_402 = true ;
if ( F_305 ( V_105 ) )
V_7 |= ( V_322 | V_321 ) ;
if ( V_7 & V_322 && V_37 -> V_403 ) {
V_37 -> V_404 ++ ;
if ( ! ( V_37 -> V_404 %
V_37 -> V_403 ) )
F_291 ( V_37 ) ;
}
F_298 ( V_110 , V_62 , V_7 ) ;
V_29 = F_303 ( V_110 , V_62 , V_7 ) ;
V_110 -> V_402 = false ;
F_11 ( & V_105 -> V_52 ) ;
if ( V_29 < 0 && V_29 != - V_382 )
goto V_72;
if ( V_29 )
V_105 -> V_108 = 1 ;
else
V_29 = 1 ;
V_105 -> V_341 = V_342 ;
V_72:
V_105 -> V_343 = 0 ;
F_13 ( & V_105 -> V_52 ) ;
F_46 ( & V_37 -> V_396 ) ;
if ( V_110 -> V_269 &&
V_110 -> V_400 >= ( 2 * 1024 * 1024ull ) ) {
F_213 ( V_110 , V_110 -> V_35 ) ;
F_306 ( V_110 ) ;
}
return V_29 ;
}
static int F_307 ( struct V_34 * V_35 ,
struct V_102 * V_105 , T_2 V_203 ,
enum V_405 V_344 )
{
struct V_254 * V_255 = & V_35 -> V_37 -> V_258 ;
T_2 V_406 = F_283 ( V_35 , 0 ) ;
T_2 V_407 ;
T_2 V_408 ;
T_2 V_374 ;
V_374 = V_105 -> V_325 + V_105 -> V_338 +
V_105 -> V_337 + V_105 -> V_339 ;
F_11 ( & V_255 -> V_52 ) ;
V_407 = F_292 ( V_255 ) ;
F_13 ( & V_255 -> V_52 ) ;
if ( V_374 + V_407 >= V_105 -> V_324 )
return 0 ;
V_374 += V_105 -> V_340 ;
F_11 ( & V_35 -> V_37 -> V_409 ) ;
V_408 = V_35 -> V_37 -> V_410 ;
F_13 ( & V_35 -> V_37 -> V_409 ) ;
if ( V_406 & ( V_327 |
V_328 |
V_329 ) )
V_408 >>= 1 ;
if ( V_344 == V_411 )
V_408 >>= 3 ;
else
V_408 >>= 1 ;
if ( V_374 + V_203 < V_105 -> V_324 + V_408 )
return 1 ;
return 0 ;
}
static void F_308 ( struct V_34 * V_35 ,
unsigned long V_412 , int V_413 )
{
struct V_414 * V_415 = V_35 -> V_37 -> V_415 ;
if ( F_309 ( & V_415 -> V_416 ) ) {
F_310 ( V_415 , V_412 , V_417 ) ;
F_45 ( & V_415 -> V_416 ) ;
} else {
F_311 ( V_35 -> V_37 , 0 , V_413 ) ;
if ( ! V_377 -> V_378 )
F_287 ( V_35 -> V_37 , V_413 ) ;
}
}
static inline int F_312 ( struct V_34 * V_35 , T_2 V_418 )
{
T_2 V_203 ;
int V_44 ;
V_203 = F_198 ( V_35 , 1 ) ;
V_44 = ( int ) F_195 ( V_418 , V_203 ) ;
if ( ! V_44 )
V_44 = 1 ;
return V_44 ;
}
static void F_313 ( struct V_34 * V_35 , T_2 V_418 , T_2 V_419 ,
bool V_420 )
{
struct V_254 * V_421 ;
struct V_102 * V_105 ;
struct V_109 * V_110 ;
T_2 V_422 ;
T_2 V_423 ;
long V_424 ;
unsigned long V_412 ;
int V_314 ;
int V_425 ;
enum V_405 V_344 ;
V_425 = F_312 ( V_35 , V_418 ) ;
V_418 = V_425 * V_426 ;
V_110 = (struct V_109 * ) V_377 -> V_378 ;
V_421 = & V_35 -> V_37 -> V_427 ;
V_105 = V_421 -> V_105 ;
V_422 = F_314 (
& V_35 -> V_37 -> V_422 ) ;
if ( V_422 == 0 ) {
if ( V_110 )
return;
if ( V_420 )
F_287 ( V_35 -> V_37 , V_425 ) ;
return;
}
V_314 = 0 ;
while ( V_422 && V_314 < 3 ) {
V_423 = F_315 ( V_422 , V_418 ) ;
V_412 = V_423 >> V_428 ;
F_308 ( V_35 , V_412 , V_425 ) ;
V_423 = F_200 ( & V_35 -> V_37 -> V_429 ) ;
if ( ! V_423 )
goto V_430;
if ( V_423 <= V_412 )
V_423 = 0 ;
else
V_423 -= V_412 ;
F_316 ( V_35 -> V_37 -> V_431 ,
F_200 ( & V_35 -> V_37 -> V_429 ) <=
( int ) V_423 ) ;
V_430:
if ( ! V_110 )
V_344 = V_411 ;
else
V_344 = V_399 ;
F_11 ( & V_105 -> V_52 ) ;
if ( F_307 ( V_35 , V_105 , V_419 , V_344 ) ) {
F_13 ( & V_105 -> V_52 ) ;
break;
}
F_13 ( & V_105 -> V_52 ) ;
V_314 ++ ;
if ( V_420 && ! V_110 ) {
F_287 ( V_35 -> V_37 , V_425 ) ;
} else {
V_424 = F_317 ( 1 ) ;
if ( V_424 )
break;
}
V_422 = F_314 (
& V_35 -> V_37 -> V_422 ) ;
}
}
static int F_318 ( struct V_34 * V_35 ,
struct V_102 * V_105 ,
T_2 V_203 , int V_389 )
{
struct V_254 * V_432 = & V_35 -> V_37 -> V_433 ;
struct V_109 * V_110 ;
V_110 = (struct V_109 * ) V_377 -> V_378 ;
if ( V_110 )
return - V_178 ;
if ( V_389 )
goto V_434;
if ( F_286 ( & V_105 -> V_332 ,
V_203 ) >= 0 )
goto V_434;
if ( V_105 != V_432 -> V_105 )
return - V_382 ;
F_11 ( & V_432 -> V_52 ) ;
if ( F_286 ( & V_105 -> V_332 ,
V_203 - V_432 -> V_56 ) >= 0 ) {
F_13 ( & V_432 -> V_52 ) ;
return - V_382 ;
}
F_13 ( & V_432 -> V_52 ) ;
V_434:
V_110 = F_202 ( V_35 ) ;
if ( F_203 ( V_110 ) )
return - V_382 ;
return F_288 ( V_110 , V_35 ) ;
}
static int F_319 ( struct V_34 * V_35 ,
struct V_102 * V_105 , T_2 V_36 ,
T_2 V_435 , int V_283 )
{
struct V_109 * V_110 ;
int V_44 ;
int V_29 = 0 ;
switch ( V_283 ) {
case V_436 :
case V_437 :
if ( V_283 == V_436 )
V_44 = F_312 ( V_35 , V_36 ) * 2 ;
else
V_44 = - 1 ;
V_110 = F_202 ( V_35 ) ;
if ( F_203 ( V_110 ) ) {
V_29 = F_204 ( V_110 ) ;
break;
}
V_29 = F_320 ( V_110 , V_35 , V_44 ) ;
F_206 ( V_110 , V_35 ) ;
break;
case V_438 :
case V_439 :
F_313 ( V_35 , V_36 * 2 , V_435 ,
V_283 == V_439 ) ;
break;
case V_440 :
V_110 = F_202 ( V_35 ) ;
if ( F_203 ( V_110 ) ) {
V_29 = F_204 ( V_110 ) ;
break;
}
V_29 = F_285 ( V_110 , V_35 -> V_37 -> V_62 ,
F_283 ( V_35 , 0 ) ,
V_342 ) ;
F_206 ( V_110 , V_35 ) ;
if ( V_29 == - V_382 )
V_29 = 0 ;
break;
case V_441 :
V_29 = F_318 ( V_35 , V_105 , V_435 , 0 ) ;
break;
default:
V_29 = - V_382 ;
break;
}
return V_29 ;
}
static inline T_2
F_321 ( struct V_34 * V_35 ,
struct V_102 * V_105 )
{
T_2 V_374 ;
T_2 V_442 ;
T_2 V_418 ;
V_418 = F_24 ( T_2 , F_322 () * 1024 * 1024 ,
16 * 1024 * 1024 ) ;
F_11 ( & V_105 -> V_52 ) ;
if ( F_307 ( V_35 , V_105 , V_418 ,
V_411 ) ) {
V_418 = 0 ;
goto V_72;
}
V_374 = V_105 -> V_325 + V_105 -> V_338 +
V_105 -> V_337 + V_105 -> V_339 +
V_105 -> V_340 ;
if ( F_307 ( V_35 , V_105 , 1024 * 1024 ,
V_411 ) )
V_442 = F_295 ( V_105 -> V_324 , 95 ) ;
else
V_442 = F_295 ( V_105 -> V_324 , 90 ) ;
if ( V_374 > V_442 )
V_418 = V_374 - V_442 ;
else
V_418 = 0 ;
V_418 = F_315 ( V_418 , V_105 -> V_340 +
V_105 -> V_338 ) ;
V_72:
F_13 ( & V_105 -> V_52 ) ;
return V_418 ;
}
static inline int F_323 ( struct V_102 * V_105 ,
struct V_12 * V_37 , T_2 V_374 )
{
T_2 V_391 = F_295 ( V_105 -> V_324 , 98 ) ;
if ( V_105 -> V_325 >= V_391 )
return 0 ;
return ( V_374 >= V_391 && ! F_39 ( V_37 ) &&
! F_229 ( V_443 , & V_37 -> V_444 ) ) ;
}
static int F_324 ( struct V_102 * V_105 ,
struct V_12 * V_37 ,
int V_445 )
{
T_2 V_374 ;
F_11 ( & V_105 -> V_52 ) ;
if ( V_445 > V_441 && V_105 -> V_108 ) {
F_13 ( & V_105 -> V_52 ) ;
return 0 ;
}
V_374 = V_105 -> V_325 + V_105 -> V_338 +
V_105 -> V_337 + V_105 -> V_339 +
V_105 -> V_340 ;
if ( F_323 ( V_105 , V_37 , V_374 ) ) {
F_13 ( & V_105 -> V_52 ) ;
return 1 ;
}
F_13 ( & V_105 -> V_52 ) ;
return 0 ;
}
static void F_325 ( struct V_446 * V_61 )
{
struct V_12 * V_37 ;
struct V_102 * V_105 ;
T_2 V_418 ;
int V_445 ;
V_37 = F_32 ( V_61 , struct V_12 , V_447 ) ;
V_105 = F_69 ( V_37 , V_321 ) ;
V_418 = F_321 ( V_37 -> V_448 ,
V_105 ) ;
if ( ! V_418 )
return;
V_445 = V_436 ;
do {
F_319 ( V_37 -> V_448 , V_105 , V_418 ,
V_418 , V_445 ) ;
V_445 ++ ;
if ( ! F_324 ( V_105 , V_37 ,
V_445 ) )
return;
} while ( V_445 < V_441 );
}
void F_326 ( struct V_446 * V_61 )
{
F_327 ( V_61 , F_325 ) ;
}
static int F_328 ( struct V_34 * V_35 ,
struct V_254 * V_421 ,
T_2 V_435 ,
enum V_405 V_344 )
{
struct V_102 * V_105 = V_421 -> V_105 ;
T_2 V_374 ;
T_2 V_36 = V_435 ;
int V_445 = V_436 ;
int V_29 = 0 ;
bool V_449 = false ;
V_77:
V_29 = 0 ;
F_11 ( & V_105 -> V_52 ) ;
while ( V_344 == V_411 && ! V_449 &&
V_105 -> V_344 ) {
F_13 ( & V_105 -> V_52 ) ;
if ( V_377 -> V_378 )
return - V_178 ;
V_29 = F_329 ( V_105 -> V_88 , ! V_105 -> V_344 ) ;
if ( V_29 )
return - V_450 ;
F_11 ( & V_105 -> V_52 ) ;
}
V_29 = - V_382 ;
V_374 = V_105 -> V_325 + V_105 -> V_338 +
V_105 -> V_337 + V_105 -> V_339 +
V_105 -> V_340 ;
if ( V_374 <= V_105 -> V_324 ) {
if ( V_374 + V_435 <= V_105 -> V_324 ) {
V_105 -> V_340 += V_435 ;
F_289 ( V_35 -> V_37 ,
L_10 , V_105 -> V_7 , V_435 , 1 ) ;
V_29 = 0 ;
} else {
V_36 = V_435 ;
}
} else {
V_36 = V_374 - V_105 -> V_324 +
( V_435 * 2 ) ;
}
if ( V_29 && F_307 ( V_35 , V_105 , V_435 , V_344 ) ) {
V_105 -> V_340 += V_435 ;
F_289 ( V_35 -> V_37 , L_10 ,
V_105 -> V_7 , V_435 ,
1 ) ;
V_29 = 0 ;
}
if ( V_29 && V_344 != V_399 ) {
V_449 = true ;
V_105 -> V_344 = 1 ;
} else if ( ! V_29 && V_105 -> V_7 & V_321 ) {
V_374 += V_435 ;
if ( ! V_35 -> V_37 -> V_451 &&
F_323 ( V_105 , V_35 -> V_37 , V_374 ) &&
! F_330 ( & V_35 -> V_37 -> V_447 ) )
F_331 ( V_452 ,
& V_35 -> V_37 -> V_447 ) ;
}
F_13 ( & V_105 -> V_52 ) ;
if ( ! V_29 || V_344 == V_399 )
goto V_72;
V_29 = F_319 ( V_35 , V_105 , V_36 , V_435 ,
V_445 ) ;
V_445 ++ ;
if ( V_344 == V_453 &&
( V_445 == V_438 ||
V_445 == V_439 ) )
V_445 = V_440 ;
if ( ! V_29 )
goto V_77;
else if ( V_344 == V_453 &&
V_445 < V_441 )
goto V_77;
else if ( V_344 == V_411 &&
V_445 <= V_441 )
goto V_77;
V_72:
if ( V_29 == - V_382 &&
F_332 ( V_35 -> V_454 == V_455 ) ) {
struct V_254 * V_255 =
& V_35 -> V_37 -> V_258 ;
if ( V_421 != V_255 &&
! F_333 ( V_255 , V_435 ) )
V_29 = 0 ;
}
if ( V_29 == - V_382 )
F_289 ( V_35 -> V_37 ,
L_9 ,
V_105 -> V_7 , V_435 , 1 ) ;
if ( V_449 ) {
F_11 ( & V_105 -> V_52 ) ;
V_105 -> V_344 = 0 ;
F_334 ( & V_105 -> V_88 ) ;
F_13 ( & V_105 -> V_52 ) ;
}
return V_29 ;
}
static struct V_254 * F_335 (
const struct V_109 * V_110 ,
const struct V_34 * V_35 )
{
struct V_254 * V_421 = NULL ;
if ( F_229 ( V_282 , & V_35 -> V_283 ) )
V_421 = V_110 -> V_421 ;
if ( V_35 == V_35 -> V_37 -> V_456 && V_110 -> V_457 )
V_421 = V_110 -> V_421 ;
if ( V_35 == V_35 -> V_37 -> V_458 )
V_421 = V_110 -> V_421 ;
if ( ! V_421 )
V_421 = V_35 -> V_421 ;
if ( ! V_421 )
V_421 = & V_35 -> V_37 -> V_459 ;
return V_421 ;
}
static int F_333 ( struct V_254 * V_421 ,
T_2 V_36 )
{
int V_29 = - V_382 ;
F_11 ( & V_421 -> V_52 ) ;
if ( V_421 -> V_10 >= V_36 ) {
V_421 -> V_10 -= V_36 ;
if ( V_421 -> V_10 < V_421 -> V_56 )
V_421 -> V_108 = 0 ;
V_29 = 0 ;
}
F_13 ( & V_421 -> V_52 ) ;
return V_29 ;
}
static void F_336 ( struct V_254 * V_421 ,
T_2 V_36 , int V_460 )
{
F_11 ( & V_421 -> V_52 ) ;
V_421 -> V_10 += V_36 ;
if ( V_460 )
V_421 -> V_56 += V_36 ;
else if ( V_421 -> V_10 >= V_421 -> V_56 )
V_421 -> V_108 = 1 ;
F_13 ( & V_421 -> V_52 ) ;
}
int F_337 ( struct V_12 * V_37 ,
struct V_254 * V_461 , T_2 V_36 ,
int V_462 )
{
struct V_254 * V_255 = & V_37 -> V_258 ;
T_2 V_463 ;
if ( V_255 -> V_105 != V_461 -> V_105 )
return - V_382 ;
F_11 ( & V_255 -> V_52 ) ;
V_463 = F_296 ( V_255 -> V_56 , V_462 ) ;
if ( V_255 -> V_10 < V_463 + V_36 ) {
F_13 ( & V_255 -> V_52 ) ;
return - V_382 ;
}
V_255 -> V_10 -= V_36 ;
if ( V_255 -> V_10 < V_255 -> V_56 )
V_255 -> V_108 = 0 ;
F_13 ( & V_255 -> V_52 ) ;
F_336 ( V_461 , V_36 , 1 ) ;
return 0 ;
}
static void F_338 ( struct V_12 * V_37 ,
struct V_254 * V_421 ,
struct V_254 * V_461 , T_2 V_36 )
{
struct V_102 * V_105 = V_421 -> V_105 ;
F_11 ( & V_421 -> V_52 ) ;
if ( V_36 == ( T_2 ) - 1 )
V_36 = V_421 -> V_56 ;
V_421 -> V_56 -= V_36 ;
if ( V_421 -> V_10 >= V_421 -> V_56 ) {
V_36 = V_421 -> V_10 - V_421 -> V_56 ;
V_421 -> V_10 = V_421 -> V_56 ;
V_421 -> V_108 = 1 ;
} else {
V_36 = 0 ;
}
F_13 ( & V_421 -> V_52 ) ;
if ( V_36 > 0 ) {
if ( V_461 ) {
F_11 ( & V_461 -> V_52 ) ;
if ( ! V_461 -> V_108 ) {
T_2 V_464 ;
V_464 = V_461 -> V_56 - V_461 -> V_10 ;
V_464 = F_315 ( V_36 , V_464 ) ;
V_461 -> V_10 += V_464 ;
if ( V_461 -> V_10 >= V_461 -> V_56 )
V_461 -> V_108 = 1 ;
V_36 -= V_464 ;
}
F_13 ( & V_461 -> V_52 ) ;
}
if ( V_36 ) {
F_11 ( & V_105 -> V_52 ) ;
V_105 -> V_340 -= V_36 ;
F_289 ( V_37 , L_10 ,
V_105 -> V_7 , V_36 , 0 ) ;
F_13 ( & V_105 -> V_52 ) ;
}
}
}
static int F_339 ( struct V_254 * V_465 ,
struct V_254 * V_466 , T_2 V_36 )
{
int V_29 ;
V_29 = F_333 ( V_465 , V_36 ) ;
if ( V_29 )
return V_29 ;
F_336 ( V_466 , V_36 , 1 ) ;
return 0 ;
}
void F_340 ( struct V_254 * V_467 , unsigned short type )
{
memset ( V_467 , 0 , sizeof( * V_467 ) ) ;
F_270 ( & V_467 -> V_52 ) ;
V_467 -> type = type ;
}
struct V_254 * F_341 ( struct V_34 * V_35 ,
unsigned short type )
{
struct V_254 * V_421 ;
struct V_12 * V_37 = V_35 -> V_37 ;
V_421 = F_209 ( sizeof( * V_421 ) , V_40 ) ;
if ( ! V_421 )
return NULL ;
F_340 ( V_421 , type ) ;
V_421 -> V_105 = F_69 ( V_37 ,
V_321 ) ;
return V_421 ;
}
void F_342 ( struct V_34 * V_35 ,
struct V_254 * V_467 )
{
if ( ! V_467 )
return;
F_343 ( V_35 , V_467 , ( T_2 ) - 1 ) ;
F_9 ( V_467 ) ;
}
void F_344 ( struct V_254 * V_467 )
{
F_9 ( V_467 ) ;
}
int F_304 ( struct V_34 * V_35 ,
struct V_254 * V_421 , T_2 V_36 ,
enum V_405 V_344 )
{
int V_29 ;
if ( V_36 == 0 )
return 0 ;
V_29 = F_328 ( V_35 , V_421 , V_36 , V_344 ) ;
if ( ! V_29 ) {
F_336 ( V_421 , V_36 , 1 ) ;
return 0 ;
}
return V_29 ;
}
int F_345 ( struct V_34 * V_35 ,
struct V_254 * V_421 , int V_462 )
{
T_2 V_36 = 0 ;
int V_29 = - V_382 ;
if ( ! V_421 )
return 0 ;
F_11 ( & V_421 -> V_52 ) ;
V_36 = F_296 ( V_421 -> V_56 , V_462 ) ;
if ( V_421 -> V_10 >= V_36 )
V_29 = 0 ;
F_13 ( & V_421 -> V_52 ) ;
return V_29 ;
}
int F_346 ( struct V_34 * V_35 ,
struct V_254 * V_421 , T_2 V_468 ,
enum V_405 V_344 )
{
T_2 V_36 = 0 ;
int V_29 = - V_382 ;
if ( ! V_421 )
return 0 ;
F_11 ( & V_421 -> V_52 ) ;
V_36 = V_468 ;
if ( V_421 -> V_10 >= V_36 )
V_29 = 0 ;
else
V_36 -= V_421 -> V_10 ;
F_13 ( & V_421 -> V_52 ) ;
if ( ! V_29 )
return 0 ;
V_29 = F_328 ( V_35 , V_421 , V_36 , V_344 ) ;
if ( ! V_29 ) {
F_336 ( V_421 , V_36 , 0 ) ;
return 0 ;
}
return V_29 ;
}
int F_347 ( struct V_254 * V_469 ,
struct V_254 * V_470 ,
T_2 V_36 )
{
return F_339 ( V_469 , V_470 , V_36 ) ;
}
void F_343 ( struct V_34 * V_35 ,
struct V_254 * V_421 ,
T_2 V_36 )
{
struct V_254 * V_255 = & V_35 -> V_37 -> V_258 ;
if ( V_255 == V_421 ||
V_421 -> V_105 != V_255 -> V_105 )
V_255 = NULL ;
F_338 ( V_35 -> V_37 , V_421 , V_255 ,
V_36 ) ;
}
static T_2 F_348 ( struct V_12 * V_37 )
{
struct V_102 * V_388 ;
T_2 V_36 ;
T_2 V_471 ;
T_2 V_472 ;
int V_248 = F_196 ( V_37 -> V_252 ) ;
V_388 = F_69 ( V_37 , V_322 ) ;
F_11 ( & V_388 -> V_52 ) ;
V_472 = V_388 -> V_325 ;
F_13 ( & V_388 -> V_52 ) ;
V_388 = F_69 ( V_37 , V_321 ) ;
F_11 ( & V_388 -> V_52 ) ;
if ( V_388 -> V_7 & V_322 )
V_472 = 0 ;
V_471 = V_388 -> V_325 ;
F_13 ( & V_388 -> V_52 ) ;
V_36 = ( V_472 >> V_37 -> V_415 -> V_473 ) *
V_248 * 2 ;
V_36 += F_192 ( V_472 + V_471 , 50 ) ;
if ( V_36 * 3 > V_471 )
V_36 = F_192 ( V_471 , 3 ) ;
return F_141 ( V_36 , V_37 -> V_62 -> V_87 << 10 ) ;
}
static void F_349 ( struct V_12 * V_37 )
{
struct V_254 * V_421 = & V_37 -> V_258 ;
struct V_102 * V_388 = V_421 -> V_105 ;
T_2 V_36 ;
V_36 = F_348 ( V_37 ) ;
F_11 ( & V_388 -> V_52 ) ;
F_11 ( & V_421 -> V_52 ) ;
V_421 -> V_56 = F_24 ( T_2 , V_36 , 512 * 1024 * 1024 ) ;
V_36 = V_388 -> V_325 + V_388 -> V_337 +
V_388 -> V_338 + V_388 -> V_339 +
V_388 -> V_340 ;
if ( V_388 -> V_324 > V_36 ) {
V_36 = V_388 -> V_324 - V_36 ;
V_421 -> V_10 += V_36 ;
V_388 -> V_340 += V_36 ;
F_289 ( V_37 , L_10 ,
V_388 -> V_7 , V_36 , 1 ) ;
}
if ( V_421 -> V_10 >= V_421 -> V_56 ) {
V_36 = V_421 -> V_10 - V_421 -> V_56 ;
V_388 -> V_340 -= V_36 ;
F_289 ( V_37 , L_10 ,
V_388 -> V_7 , V_36 , 0 ) ;
V_421 -> V_10 = V_421 -> V_56 ;
V_421 -> V_108 = 1 ;
}
F_13 ( & V_421 -> V_52 ) ;
F_13 ( & V_388 -> V_52 ) ;
}
static void F_350 ( struct V_12 * V_37 )
{
struct V_102 * V_105 ;
V_105 = F_69 ( V_37 , V_323 ) ;
V_37 -> V_398 . V_105 = V_105 ;
V_105 = F_69 ( V_37 , V_321 ) ;
V_37 -> V_258 . V_105 = V_105 ;
V_37 -> V_427 . V_105 = V_105 ;
V_37 -> V_474 . V_105 = V_105 ;
V_37 -> V_459 . V_105 = V_105 ;
V_37 -> V_433 . V_105 = V_105 ;
V_37 -> V_62 -> V_421 = & V_37 -> V_258 ;
V_37 -> V_456 -> V_421 = & V_37 -> V_258 ;
V_37 -> V_475 -> V_421 = & V_37 -> V_258 ;
V_37 -> V_86 -> V_421 = & V_37 -> V_258 ;
if ( V_37 -> V_476 )
V_37 -> V_476 -> V_421 = & V_37 -> V_258 ;
V_37 -> V_372 -> V_421 = & V_37 -> V_398 ;
F_349 ( V_37 ) ;
}
static void F_351 ( struct V_12 * V_37 )
{
F_338 ( V_37 , & V_37 -> V_258 , NULL ,
( T_2 ) - 1 ) ;
F_8 ( V_37 -> V_427 . V_56 > 0 ) ;
F_8 ( V_37 -> V_427 . V_10 > 0 ) ;
F_8 ( V_37 -> V_474 . V_56 > 0 ) ;
F_8 ( V_37 -> V_474 . V_10 > 0 ) ;
F_8 ( V_37 -> V_398 . V_56 > 0 ) ;
F_8 ( V_37 -> V_398 . V_10 > 0 ) ;
F_8 ( V_37 -> V_433 . V_56 > 0 ) ;
F_8 ( V_37 -> V_433 . V_10 > 0 ) ;
}
void F_352 ( struct V_109 * V_110 ,
struct V_34 * V_35 )
{
if ( ! V_110 -> V_421 )
return;
if ( ! V_110 -> V_338 )
return;
F_289 ( V_35 -> V_37 , L_12 ,
V_110 -> V_298 , V_110 -> V_338 , 0 ) ;
F_343 ( V_35 , V_110 -> V_421 , V_110 -> V_338 ) ;
V_110 -> V_338 = 0 ;
}
void F_306 ( struct V_109 * V_110 )
{
struct V_12 * V_37 = V_110 -> V_35 -> V_37 ;
if ( ! V_110 -> V_400 )
return;
F_353 ( ! F_172 ( & V_110 -> V_271 ) ) ;
F_338 ( V_37 , & V_37 -> V_398 , NULL ,
V_110 -> V_400 ) ;
V_110 -> V_400 = 0 ;
}
int F_354 ( struct V_109 * V_110 ,
struct V_288 * V_288 )
{
struct V_34 * V_35 = F_246 ( V_288 ) -> V_35 ;
struct V_254 * V_469 = F_335 ( V_110 , V_35 ) ;
struct V_254 * V_470 = V_35 -> V_477 ;
T_2 V_36 = F_198 ( V_35 , 1 ) ;
F_289 ( V_35 -> V_37 , L_13 ,
F_355 ( V_288 ) , V_36 , 1 ) ;
return F_339 ( V_469 , V_470 , V_36 ) ;
}
void F_356 ( struct V_288 * V_288 )
{
struct V_34 * V_35 = F_246 ( V_288 ) -> V_35 ;
T_2 V_36 = F_198 ( V_35 , 1 ) ;
F_289 ( V_35 -> V_37 , L_13 ,
F_355 ( V_288 ) , V_36 , 0 ) ;
F_343 ( V_35 , V_35 -> V_477 , V_36 ) ;
}
int F_357 ( struct V_34 * V_35 ,
struct V_254 * V_467 ,
int V_425 ,
T_2 * V_478 ,
bool V_479 )
{
T_2 V_36 ;
int V_29 ;
struct V_254 * V_255 = & V_35 -> V_37 -> V_258 ;
if ( V_35 -> V_37 -> V_212 ) {
V_36 = 3 * V_35 -> V_87 ;
V_29 = F_290 ( V_35 , V_36 ) ;
if ( V_29 )
return V_29 ;
} else {
V_36 = 0 ;
}
* V_478 = V_36 ;
V_36 = F_198 ( V_35 , V_425 ) ;
V_467 -> V_105 = F_69 ( V_35 -> V_37 ,
V_321 ) ;
V_29 = F_304 ( V_35 , V_467 , V_36 ,
V_411 ) ;
if ( V_29 == - V_382 && V_479 )
V_29 = F_347 ( V_255 , V_467 , V_36 ) ;
if ( V_29 ) {
if ( * V_478 )
F_358 ( V_35 , * V_478 ) ;
}
return V_29 ;
}
void F_359 ( struct V_34 * V_35 ,
struct V_254 * V_467 ,
T_2 V_478 )
{
F_343 ( V_35 , V_467 , ( T_2 ) - 1 ) ;
}
static unsigned F_360 ( struct V_288 * V_288 , T_2 V_36 )
{
unsigned V_480 = 0 ;
unsigned V_481 = 0 ;
unsigned V_482 = 0 ;
V_482 = ( unsigned ) F_195 ( V_36 +
V_483 - 1 ,
V_483 ) ;
ASSERT ( V_482 ) ;
ASSERT ( F_246 ( V_288 ) -> V_484 >= V_482 ) ;
F_246 ( V_288 ) -> V_484 -= V_482 ;
if ( F_246 ( V_288 ) -> V_484 == 0 &&
F_361 ( V_485 ,
& F_246 ( V_288 ) -> V_486 ) )
V_480 = 1 ;
if ( F_246 ( V_288 ) -> V_484 >=
F_246 ( V_288 ) -> V_487 )
return V_480 ;
V_481 = F_246 ( V_288 ) -> V_487 -
F_246 ( V_288 ) -> V_484 ;
F_246 ( V_288 ) -> V_487 -= V_481 ;
return V_481 + V_480 ;
}
static T_2 F_362 ( struct V_288 * V_288 , T_2 V_36 ,
int V_488 )
{
struct V_34 * V_35 = F_246 ( V_288 ) -> V_35 ;
T_2 V_489 , V_250 ;
if ( F_246 ( V_288 ) -> V_7 & V_490 &&
F_246 ( V_288 ) -> V_247 == 0 )
return 0 ;
V_489 = F_194 ( V_35 , F_246 ( V_288 ) -> V_247 ) ;
if ( V_488 )
F_246 ( V_288 ) -> V_247 += V_36 ;
else
F_246 ( V_288 ) -> V_247 -= V_36 ;
V_250 = F_194 ( V_35 , F_246 ( V_288 ) -> V_247 ) ;
if ( V_489 == V_250 )
return 0 ;
if ( V_488 )
return F_198 ( V_35 ,
V_250 - V_489 ) ;
return F_198 ( V_35 , V_489 - V_250 ) ;
}
int F_363 ( struct V_288 * V_288 , T_2 V_36 )
{
struct V_34 * V_35 = F_246 ( V_288 ) -> V_35 ;
struct V_254 * V_421 = & V_35 -> V_37 -> V_427 ;
T_2 V_491 = 0 ;
T_2 V_247 ;
unsigned V_492 = 0 ;
int V_493 = 0 ;
enum V_405 V_344 = V_411 ;
int V_29 = 0 ;
bool V_494 = true ;
T_2 V_495 = 0 ;
unsigned V_496 ;
if ( F_284 ( V_288 ) ) {
V_344 = V_399 ;
V_494 = false ;
}
if ( V_344 != V_399 &&
F_364 ( V_35 -> V_37 ) )
F_365 ( 1 ) ;
if ( V_494 )
F_35 ( & F_246 ( V_288 ) -> V_497 ) ;
V_36 = F_141 ( V_36 , V_35 -> V_253 ) ;
F_11 ( & F_246 ( V_288 ) -> V_52 ) ;
V_492 = ( unsigned ) F_195 ( V_36 +
V_483 - 1 ,
V_483 ) ;
F_246 ( V_288 ) -> V_484 += V_492 ;
V_492 = 0 ;
if ( F_246 ( V_288 ) -> V_484 >
F_246 ( V_288 ) -> V_487 )
V_492 = F_246 ( V_288 ) -> V_484 -
F_246 ( V_288 ) -> V_487 ;
if ( ! F_229 ( V_485 ,
& F_246 ( V_288 ) -> V_486 ) ) {
V_492 ++ ;
V_493 = 1 ;
}
V_491 = F_198 ( V_35 , V_492 ) ;
V_491 += F_362 ( V_288 , V_36 , 1 ) ;
V_247 = F_246 ( V_288 ) -> V_247 ;
F_13 ( & F_246 ( V_288 ) -> V_52 ) ;
if ( V_35 -> V_37 -> V_212 ) {
V_29 = F_290 ( V_35 , V_492 * V_35 -> V_87 ) ;
if ( V_29 )
goto V_498;
}
V_29 = F_328 ( V_35 , V_421 , V_491 , V_344 ) ;
if ( F_332 ( V_29 ) ) {
if ( V_35 -> V_37 -> V_212 )
F_358 ( V_35 , V_492 * V_35 -> V_87 ) ;
goto V_498;
}
F_11 ( & F_246 ( V_288 ) -> V_52 ) ;
if ( V_493 ) {
F_366 ( V_485 ,
& F_246 ( V_288 ) -> V_486 ) ;
V_492 -- ;
}
F_246 ( V_288 ) -> V_487 += V_492 ;
F_13 ( & F_246 ( V_288 ) -> V_52 ) ;
if ( V_494 )
F_46 ( & F_246 ( V_288 ) -> V_497 ) ;
if ( V_491 )
F_289 ( V_35 -> V_37 , L_14 ,
F_355 ( V_288 ) , V_491 , 1 ) ;
F_336 ( V_421 , V_491 , 1 ) ;
return 0 ;
V_498:
F_11 ( & F_246 ( V_288 ) -> V_52 ) ;
V_496 = F_360 ( V_288 , V_36 ) ;
if ( F_246 ( V_288 ) -> V_247 == V_247 ) {
F_362 ( V_288 , V_36 , 0 ) ;
} else {
T_2 V_499 = F_246 ( V_288 ) -> V_247 ;
T_2 V_203 ;
V_203 = V_247 - F_246 ( V_288 ) -> V_247 ;
F_246 ( V_288 ) -> V_247 = V_247 ;
V_495 = F_362 ( V_288 , V_203 , 0 ) ;
F_246 ( V_288 ) -> V_247 = V_247 - V_36 ;
V_203 = V_247 - V_499 ;
V_203 = F_362 ( V_288 , V_203 , 0 ) ;
F_246 ( V_288 ) -> V_247 = V_499 - V_36 ;
if ( V_203 > V_495 )
V_495 = V_203 - V_495 ;
else
V_495 = 0 ;
}
F_13 ( & F_246 ( V_288 ) -> V_52 ) ;
if ( V_496 )
V_495 += F_198 ( V_35 , V_496 ) ;
if ( V_495 ) {
F_343 ( V_35 , V_421 , V_495 ) ;
F_289 ( V_35 -> V_37 , L_14 ,
F_355 ( V_288 ) , V_495 , 0 ) ;
}
if ( V_494 )
F_46 ( & F_246 ( V_288 ) -> V_497 ) ;
return V_29 ;
}
void F_367 ( struct V_288 * V_288 , T_2 V_36 )
{
struct V_34 * V_35 = F_246 ( V_288 ) -> V_35 ;
T_2 V_495 = 0 ;
unsigned V_496 ;
V_36 = F_141 ( V_36 , V_35 -> V_253 ) ;
F_11 ( & F_246 ( V_288 ) -> V_52 ) ;
V_496 = F_360 ( V_288 , V_36 ) ;
if ( V_36 )
V_495 = F_362 ( V_288 , V_36 , 0 ) ;
F_13 ( & F_246 ( V_288 ) -> V_52 ) ;
if ( V_496 > 0 )
V_495 += F_198 ( V_35 , V_496 ) ;
if ( F_226 ( V_35 ) )
return;
F_289 ( V_35 -> V_37 , L_14 ,
F_355 ( V_288 ) , V_495 , 0 ) ;
F_343 ( V_35 , & V_35 -> V_37 -> V_427 ,
V_495 ) ;
}
int F_368 ( struct V_288 * V_288 , T_2 V_36 )
{
int V_29 ;
V_29 = F_251 ( V_288 , V_36 , V_36 ) ;
if ( V_29 )
return V_29 ;
V_29 = F_363 ( V_288 , V_36 ) ;
if ( V_29 ) {
F_253 ( V_288 , V_36 ) ;
return V_29 ;
}
return 0 ;
}
void F_369 ( struct V_288 * V_288 , T_2 V_36 )
{
F_367 ( V_288 , V_36 ) ;
F_253 ( V_288 , V_36 ) ;
}
static int F_370 ( struct V_109 * V_110 ,
struct V_34 * V_35 , T_2 V_27 ,
T_2 V_36 , int V_379 )
{
struct V_1 * V_2 = NULL ;
struct V_12 * V_13 = V_35 -> V_37 ;
T_2 V_500 = V_36 ;
T_2 V_501 ;
T_2 V_502 ;
int V_326 ;
F_11 ( & V_13 -> V_503 ) ;
V_501 = F_371 ( V_13 -> V_252 ) ;
if ( V_379 )
V_501 += V_36 ;
else
V_501 -= V_36 ;
F_372 ( V_13 -> V_252 , V_501 ) ;
F_13 ( & V_13 -> V_503 ) ;
while ( V_500 ) {
V_2 = F_68 ( V_13 , V_27 ) ;
if ( ! V_2 )
return - V_153 ;
if ( V_2 -> V_7 & ( V_327 |
V_328 |
V_329 ) )
V_326 = 2 ;
else
V_326 = 1 ;
if ( ! V_379 && V_2 -> V_3 == V_94 )
F_51 ( V_2 , 1 ) ;
V_502 = V_27 - V_2 -> V_21 . V_22 ;
F_8 ( V_502 > V_2 -> V_21 . V_33 ) ;
F_11 ( & V_2 -> V_105 -> V_52 ) ;
F_11 ( & V_2 -> V_52 ) ;
if ( F_250 ( V_35 , V_302 ) &&
V_2 -> V_294 < V_308 )
V_2 -> V_294 = V_308 ;
V_501 = F_373 ( & V_2 -> V_135 ) ;
V_36 = F_315 ( V_500 , V_2 -> V_21 . V_33 - V_502 ) ;
if ( V_379 ) {
V_501 += V_36 ;
F_374 ( & V_2 -> V_135 , V_501 ) ;
V_2 -> V_10 -= V_36 ;
V_2 -> V_105 -> V_338 -= V_36 ;
V_2 -> V_105 -> V_325 += V_36 ;
V_2 -> V_105 -> V_331 += V_36 * V_326 ;
F_13 ( & V_2 -> V_52 ) ;
F_13 ( & V_2 -> V_105 -> V_52 ) ;
} else {
V_501 -= V_36 ;
F_374 ( & V_2 -> V_135 , V_501 ) ;
V_2 -> V_9 += V_36 ;
V_2 -> V_105 -> V_337 += V_36 ;
V_2 -> V_105 -> V_325 -= V_36 ;
V_2 -> V_105 -> V_331 -= V_36 * V_326 ;
F_13 ( & V_2 -> V_52 ) ;
F_13 ( & V_2 -> V_105 -> V_52 ) ;
F_375 ( V_13 -> V_58 ,
V_27 , V_27 + V_36 - 1 ,
V_40 | V_504 ) ;
if ( V_501 == 0 ) {
F_11 ( & V_13 -> V_505 ) ;
if ( F_172 ( & V_2 -> V_506 ) ) {
F_4 ( V_2 ) ;
F_64 ( & V_2 -> V_506 ,
& V_13 -> V_507 ) ;
}
F_13 ( & V_13 -> V_505 ) ;
}
}
F_11 ( & V_110 -> V_127 -> V_315 ) ;
if ( F_172 ( & V_2 -> V_317 ) ) {
F_64 ( & V_2 -> V_317 ,
& V_110 -> V_127 -> V_307 ) ;
V_110 -> V_127 -> V_256 ++ ;
F_4 ( V_2 ) ;
}
F_13 ( & V_110 -> V_127 -> V_315 ) ;
F_6 ( V_2 ) ;
V_500 -= V_36 ;
V_27 += V_36 ;
}
return 0 ;
}
static T_2 V_26 ( struct V_34 * V_35 , T_2 V_508 )
{
struct V_1 * V_2 ;
T_2 V_27 ;
F_11 ( & V_35 -> V_37 -> V_18 ) ;
V_27 = V_35 -> V_37 -> V_26 ;
F_13 ( & V_35 -> V_37 -> V_18 ) ;
if ( V_27 < ( T_2 ) - 1 )
return V_27 ;
V_2 = F_67 ( V_35 -> V_37 , V_508 ) ;
if ( ! V_2 )
return 0 ;
V_27 = V_2 -> V_21 . V_22 ;
F_6 ( V_2 ) ;
return V_27 ;
}
static int F_376 ( struct V_34 * V_35 ,
struct V_1 * V_2 ,
T_2 V_27 , T_2 V_36 , int V_10 )
{
F_11 ( & V_2 -> V_105 -> V_52 ) ;
F_11 ( & V_2 -> V_52 ) ;
V_2 -> V_9 += V_36 ;
V_2 -> V_105 -> V_337 += V_36 ;
if ( V_10 ) {
V_2 -> V_10 -= V_36 ;
V_2 -> V_105 -> V_338 -= V_36 ;
}
F_13 ( & V_2 -> V_52 ) ;
F_13 ( & V_2 -> V_105 -> V_52 ) ;
F_375 ( V_35 -> V_37 -> V_58 , V_27 ,
V_27 + V_36 - 1 , V_40 | V_504 ) ;
if ( V_10 )
F_377 ( V_35 , V_27 , V_36 ) ;
return 0 ;
}
int F_166 ( struct V_34 * V_35 ,
T_2 V_27 , T_2 V_36 , int V_10 )
{
struct V_1 * V_2 ;
V_2 = F_68 ( V_35 -> V_37 , V_27 ) ;
F_30 ( ! V_2 ) ;
F_376 ( V_35 , V_2 , V_27 , V_36 , V_10 ) ;
F_6 ( V_2 ) ;
return 0 ;
}
int F_378 ( struct V_34 * V_35 ,
T_2 V_27 , T_2 V_36 )
{
struct V_1 * V_2 ;
int V_29 ;
V_2 = F_68 ( V_35 -> V_37 , V_27 ) ;
if ( ! V_2 )
return - V_509 ;
F_51 ( V_2 , 1 ) ;
F_376 ( V_35 , V_2 , V_27 , V_36 , 0 ) ;
V_29 = F_379 ( V_2 , V_27 , V_36 ) ;
F_6 ( V_2 ) ;
return V_29 ;
}
static int F_380 ( struct V_34 * V_35 , T_2 V_32 , T_2 V_36 )
{
int V_29 ;
struct V_1 * V_14 ;
struct V_50 * V_53 ;
V_14 = F_68 ( V_35 -> V_37 , V_32 ) ;
if ( ! V_14 )
return - V_509 ;
F_51 ( V_14 , 0 ) ;
V_53 = F_25 ( V_14 ) ;
if ( ! V_53 ) {
F_30 ( ! F_1 ( V_14 ) ) ;
V_29 = F_379 ( V_14 , V_32 , V_36 ) ;
} else {
F_35 ( & V_53 -> V_78 ) ;
if ( V_32 >= V_53 -> V_84 ) {
V_29 = F_17 ( V_35 , V_32 , V_36 ) ;
} else if ( V_32 + V_36 <= V_53 -> V_84 ) {
V_29 = F_379 ( V_14 ,
V_32 , V_36 ) ;
} else {
V_36 = V_53 -> V_84 - V_32 ;
V_29 = F_379 ( V_14 ,
V_32 , V_36 ) ;
if ( V_29 )
goto V_510;
V_36 = ( V_32 + V_36 ) -
V_53 -> V_84 ;
V_32 = V_53 -> V_84 ;
V_29 = F_17 ( V_35 , V_32 , V_36 ) ;
}
V_510:
F_46 ( & V_53 -> V_78 ) ;
F_26 ( V_53 ) ;
}
F_6 ( V_14 ) ;
return V_29 ;
}
int F_381 ( struct V_34 * log ,
struct V_65 * V_511 )
{
struct V_280 * V_135 ;
struct V_67 V_21 ;
int V_512 ;
int V_43 ;
if ( ! F_76 ( log -> V_37 , V_513 ) )
return 0 ;
for ( V_43 = 0 ; V_43 < F_38 ( V_511 ) ; V_43 ++ ) {
F_40 ( V_511 , & V_21 , V_43 ) ;
if ( V_21 . type != V_285 )
continue;
V_135 = F_78 ( V_511 , V_43 , struct V_280 ) ;
V_512 = F_230 ( V_511 , V_135 ) ;
if ( V_512 == V_286 )
continue;
if ( F_231 ( V_511 , V_135 ) == 0 )
continue;
V_21 . V_22 = F_231 ( V_511 , V_135 ) ;
V_21 . V_33 = F_232 ( V_511 , V_135 ) ;
F_380 ( log , V_21 . V_22 , V_21 . V_33 ) ;
}
return 0 ;
}
static int F_382 ( struct V_1 * V_2 ,
T_2 V_36 , int V_488 , int V_514 )
{
struct V_102 * V_105 = V_2 -> V_105 ;
int V_29 = 0 ;
F_11 ( & V_105 -> V_52 ) ;
F_11 ( & V_2 -> V_52 ) ;
if ( V_488 != V_515 ) {
if ( V_2 -> V_296 ) {
V_29 = - V_178 ;
} else {
V_2 -> V_10 += V_36 ;
V_105 -> V_338 += V_36 ;
if ( V_488 == V_516 ) {
F_289 ( V_2 -> V_37 ,
L_10 , V_105 -> V_7 ,
V_36 , 0 ) ;
V_105 -> V_340 -= V_36 ;
}
if ( V_514 )
V_2 -> V_422 += V_36 ;
}
} else {
if ( V_2 -> V_296 )
V_105 -> V_339 += V_36 ;
V_2 -> V_10 -= V_36 ;
V_105 -> V_338 -= V_36 ;
if ( V_514 )
V_2 -> V_422 -= V_36 ;
}
F_13 ( & V_2 -> V_52 ) ;
F_13 ( & V_105 -> V_52 ) ;
return V_29 ;
}
void F_383 ( struct V_109 * V_110 ,
struct V_34 * V_35 )
{
struct V_12 * V_37 = V_35 -> V_37 ;
struct V_50 * V_80 ;
struct V_50 * V_53 ;
struct V_1 * V_2 ;
F_63 ( & V_37 -> V_79 ) ;
F_256 (caching_ctl, next,
&fs_info->caching_block_groups, list) {
V_2 = V_53 -> V_14 ;
if ( F_1 ( V_2 ) ) {
V_2 -> V_97 = ( T_2 ) - 1 ;
F_261 ( & V_53 -> V_90 ) ;
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
F_349 ( V_37 ) ;
}
static int F_384 ( struct V_34 * V_35 , T_2 V_32 , T_2 V_31 ,
const bool V_517 )
{
struct V_12 * V_37 = V_35 -> V_37 ;
struct V_1 * V_2 = NULL ;
struct V_102 * V_105 ;
struct V_254 * V_255 = & V_37 -> V_258 ;
T_2 V_49 ;
bool V_320 ;
while ( V_32 <= V_31 ) {
V_320 = false ;
if ( ! V_2 ||
V_32 >= V_2 -> V_21 . V_22 + V_2 -> V_21 . V_33 ) {
if ( V_2 )
F_6 ( V_2 ) ;
V_2 = F_68 ( V_37 , V_32 ) ;
F_30 ( ! V_2 ) ;
}
V_49 = V_2 -> V_21 . V_22 + V_2 -> V_21 . V_33 - V_32 ;
V_49 = F_315 ( V_49 , V_31 + 1 - V_32 ) ;
if ( V_32 < V_2 -> V_97 ) {
V_49 = F_315 ( V_49 , V_2 -> V_97 - V_32 ) ;
if ( V_517 )
F_29 ( V_2 , V_32 , V_49 ) ;
}
V_32 += V_49 ;
V_105 = V_2 -> V_105 ;
F_11 ( & V_105 -> V_52 ) ;
F_11 ( & V_2 -> V_52 ) ;
V_2 -> V_9 -= V_49 ;
V_105 -> V_337 -= V_49 ;
F_385 ( & V_105 -> V_332 , - V_49 ) ;
if ( V_2 -> V_296 ) {
V_105 -> V_339 += V_49 ;
V_320 = true ;
}
F_13 ( & V_2 -> V_52 ) ;
if ( ! V_320 && V_255 -> V_105 == V_105 ) {
F_11 ( & V_255 -> V_52 ) ;
if ( ! V_255 -> V_108 ) {
V_49 = F_315 ( V_49 , V_255 -> V_56 -
V_255 -> V_10 ) ;
V_255 -> V_10 += V_49 ;
V_105 -> V_340 += V_49 ;
if ( V_255 -> V_10 >= V_255 -> V_56 )
V_255 -> V_108 = 1 ;
}
F_13 ( & V_255 -> V_52 ) ;
}
F_13 ( & V_105 -> V_52 ) ;
}
if ( V_2 )
F_6 ( V_2 ) ;
return 0 ;
}
int F_386 ( struct V_109 * V_110 ,
struct V_34 * V_35 )
{
struct V_12 * V_37 = V_35 -> V_37 ;
struct V_1 * V_14 , * V_304 ;
struct V_103 * V_518 ;
struct V_519 * V_520 ;
T_2 V_32 ;
T_2 V_31 ;
int V_29 ;
if ( V_37 -> V_58 == & V_37 -> V_38 [ 0 ] )
V_520 = & V_37 -> V_38 [ 1 ] ;
else
V_520 = & V_37 -> V_38 [ 0 ] ;
while ( ! V_110 -> V_221 ) {
F_35 ( & V_37 -> V_521 ) ;
V_29 = F_28 ( V_520 , 0 , & V_32 , & V_31 ,
V_59 , NULL ) ;
if ( V_29 ) {
F_46 ( & V_37 -> V_521 ) ;
break;
}
if ( F_250 ( V_35 , V_522 ) )
V_29 = F_145 ( V_35 , V_32 ,
V_31 + 1 - V_32 , NULL ) ;
F_387 ( V_520 , V_32 , V_31 , V_40 ) ;
F_384 ( V_35 , V_32 , V_31 , true ) ;
F_46 ( & V_37 -> V_521 ) ;
F_47 () ;
}
V_518 = & V_110 -> V_127 -> V_518 ;
F_256 (block_group, tmp, deleted_bgs, bg_list) {
T_2 V_523 = 0 ;
V_29 = - V_524 ;
if ( ! V_110 -> V_221 )
V_29 = F_145 ( V_35 ,
V_14 -> V_21 . V_22 ,
V_14 -> V_21 . V_33 ,
& V_523 ) ;
F_261 ( & V_14 -> V_506 ) ;
F_388 ( V_14 ) ;
F_6 ( V_14 ) ;
if ( V_29 ) {
const char * V_525 = F_389 ( V_29 ) ;
F_390 ( V_37 ,
L_15 ,
V_29 , V_525 ) ;
}
}
return 0 ;
}
static void F_391 ( struct V_12 * V_37 , T_2 V_36 ,
T_2 V_133 , T_2 V_146 )
{
struct V_102 * V_105 ;
T_2 V_7 ;
if ( V_133 < V_143 ) {
if ( V_146 == V_526 )
V_7 = V_323 ;
else
V_7 = V_321 ;
} else {
V_7 = V_322 ;
}
V_105 = F_69 ( V_37 , V_7 ) ;
F_30 ( ! V_105 ) ;
F_385 ( & V_105 -> V_332 , V_36 ) ;
}
static int F_158 ( struct V_109 * V_110 ,
struct V_34 * V_35 ,
struct V_211 * V_128 , T_2 V_17 ,
T_2 V_146 , T_2 V_527 ,
T_2 V_528 , int V_159 ,
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
int V_529 = 0 ;
int V_530 = 0 ;
int V_531 = 1 ;
int V_208 = V_128 -> V_208 ;
T_3 V_118 ;
T_2 V_112 ;
T_2 V_27 = V_128 -> V_27 ;
T_2 V_36 = V_128 -> V_36 ;
int V_160 = 0 ;
bool V_173 = F_76 ( V_35 -> V_37 ,
V_121 ) ;
if ( ! V_13 -> V_212 || ! F_152 ( V_146 ) )
V_208 = 1 ;
V_64 = F_33 () ;
if ( ! V_64 )
return - V_71 ;
V_64 -> V_75 = 1 ;
V_64 -> V_213 = 1 ;
V_184 = V_527 >= V_143 ;
F_30 ( ! V_184 && V_159 != 1 ) ;
if ( V_184 )
V_173 = 0 ;
V_29 = F_134 ( V_110 , V_62 , V_64 , & V_164 ,
V_27 , V_36 , V_17 ,
V_146 , V_527 ,
V_528 ) ;
if ( V_29 == 0 ) {
V_529 = V_64 -> V_83 [ 0 ] ;
while ( V_529 >= 0 ) {
F_40 ( V_64 -> V_82 [ 0 ] , & V_21 ,
V_529 ) ;
if ( V_21 . V_22 != V_27 )
break;
if ( V_21 . type == V_76 &&
V_21 . V_33 == V_36 ) {
V_530 = 1 ;
break;
}
if ( V_21 . type == V_85 &&
V_21 . V_33 == V_527 ) {
V_530 = 1 ;
break;
}
if ( V_64 -> V_83 [ 0 ] - V_529 > 5 )
break;
V_529 -- ;
}
#ifdef F_81
V_118 = F_77 ( V_64 -> V_82 [ 0 ] , V_529 ) ;
if ( V_530 && V_118 < sizeof( * V_117 ) )
V_530 = 0 ;
#endif
if ( ! V_530 ) {
F_30 ( V_164 ) ;
V_29 = F_139 ( V_110 , V_62 , V_64 ,
NULL , V_159 ,
V_184 , & V_160 ) ;
if ( V_29 ) {
F_153 ( V_110 , V_62 , V_29 ) ;
goto V_72;
}
F_44 ( V_64 ) ;
V_64 -> V_213 = 1 ;
V_21 . V_22 = V_27 ;
V_21 . type = V_76 ;
V_21 . V_33 = V_36 ;
if ( ! V_184 && V_173 ) {
V_21 . type = V_85 ;
V_21 . V_33 = V_527 ;
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
F_392 ( V_13 , L_16 ,
V_29 , V_27 ) ;
if ( V_29 > 0 )
F_393 ( V_62 ,
V_64 -> V_82 [ 0 ] ) ;
}
if ( V_29 < 0 ) {
F_153 ( V_110 , V_62 , V_29 ) ;
goto V_72;
}
V_529 = V_64 -> V_83 [ 0 ] ;
}
} else if ( F_8 ( V_29 == - V_153 ) ) {
F_393 ( V_62 , V_64 -> V_82 [ 0 ] ) ;
F_392 ( V_13 ,
L_17 ,
V_27 , V_17 , V_146 , V_527 ,
V_528 ) ;
F_153 ( V_110 , V_62 , V_29 ) ;
goto V_72;
} else {
F_153 ( V_110 , V_62 , V_29 ) ;
goto V_72;
}
V_66 = V_64 -> V_82 [ 0 ] ;
V_118 = F_77 ( V_66 , V_529 ) ;
#ifdef F_81
if ( V_118 < sizeof( * V_117 ) ) {
F_30 ( V_530 || V_529 != V_64 -> V_83 [ 0 ] ) ;
V_29 = F_87 ( V_110 , V_62 , V_64 ,
V_527 , 0 ) ;
if ( V_29 < 0 ) {
F_153 ( V_110 , V_62 , V_29 ) ;
goto V_72;
}
F_44 ( V_64 ) ;
V_64 -> V_213 = 1 ;
V_21 . V_22 = V_27 ;
V_21 . type = V_76 ;
V_21 . V_33 = V_36 ;
V_29 = F_37 ( V_110 , V_62 , & V_21 , V_64 ,
- 1 , 1 ) ;
if ( V_29 ) {
F_392 ( V_13 , L_16 ,
V_29 , V_27 ) ;
F_393 ( V_62 , V_64 -> V_82 [ 0 ] ) ;
}
if ( V_29 < 0 ) {
F_153 ( V_110 , V_62 , V_29 ) ;
goto V_72;
}
V_529 = V_64 -> V_83 [ 0 ] ;
V_66 = V_64 -> V_82 [ 0 ] ;
V_118 = F_77 ( V_66 , V_529 ) ;
}
#endif
F_30 ( V_118 < sizeof( * V_117 ) ) ;
V_117 = F_78 ( V_66 , V_529 ,
struct V_116 ) ;
if ( V_527 < V_143 &&
V_21 . type == V_76 ) {
struct V_138 * V_139 ;
F_30 ( V_118 < sizeof( * V_117 ) + sizeof( * V_139 ) ) ;
V_139 = (struct V_138 * ) ( V_117 + 1 ) ;
F_8 ( V_527 != F_394 ( V_66 , V_139 ) ) ;
}
V_112 = F_79 ( V_66 , V_117 ) ;
if ( V_112 < V_159 ) {
F_392 ( V_13 , L_18
L_19 , V_159 , V_112 , V_27 ) ;
V_29 = - V_509 ;
F_153 ( V_110 , V_62 , V_29 ) ;
goto V_72;
}
V_112 -= V_159 ;
if ( V_112 > 0 ) {
if ( V_129 )
F_130 ( V_129 , V_66 , V_117 ) ;
if ( V_164 ) {
F_30 ( ! V_530 ) ;
} else {
F_90 ( V_66 , V_117 , V_112 ) ;
F_95 ( V_66 ) ;
}
if ( V_530 ) {
V_29 = F_139 ( V_110 , V_62 , V_64 ,
V_164 , V_159 ,
V_184 , & V_160 ) ;
if ( V_29 ) {
F_153 ( V_110 , V_62 , V_29 ) ;
goto V_72;
}
}
F_391 ( V_35 -> V_37 , - V_36 , V_527 ,
V_146 ) ;
} else {
if ( V_530 ) {
F_30 ( V_184 && V_159 !=
F_118 ( V_64 , V_164 ) ) ;
if ( V_164 ) {
F_30 ( V_64 -> V_83 [ 0 ] != V_529 ) ;
} else {
F_30 ( V_64 -> V_83 [ 0 ] != V_529 + 1 ) ;
V_64 -> V_83 [ 0 ] = V_529 ;
V_531 = 2 ;
}
}
V_160 = 1 ;
V_29 = F_395 ( V_110 , V_62 , V_64 , V_64 -> V_83 [ 0 ] ,
V_531 ) ;
if ( V_29 ) {
F_153 ( V_110 , V_62 , V_29 ) ;
goto V_72;
}
F_44 ( V_64 ) ;
if ( V_184 ) {
V_29 = F_170 ( V_110 , V_35 , V_27 , V_36 ) ;
if ( V_29 ) {
F_153 ( V_110 , V_62 , V_29 ) ;
goto V_72;
}
}
V_29 = F_370 ( V_110 , V_35 , V_27 , V_36 , 0 ) ;
if ( V_29 ) {
F_153 ( V_110 , V_62 , V_29 ) ;
goto V_72;
}
}
F_44 ( V_64 ) ;
V_72:
F_50 ( V_64 ) ;
return V_29 ;
}
static T_1 int F_396 ( struct V_109 * V_110 ,
struct V_34 * V_35 , T_2 V_27 )
{
struct V_113 * V_104 ;
struct V_114 * V_115 ;
int V_29 = 0 ;
V_115 = & V_110 -> V_127 -> V_115 ;
F_11 ( & V_115 -> V_52 ) ;
V_104 = F_84 ( V_110 , V_27 ) ;
if ( ! V_104 )
goto V_532;
F_11 ( & V_104 -> V_52 ) ;
if ( ! F_172 ( & V_104 -> V_223 ) )
goto V_72;
if ( V_104 -> V_129 ) {
if ( ! V_104 -> V_226 )
goto V_72;
F_181 ( V_104 -> V_129 ) ;
V_104 -> V_129 = NULL ;
}
if ( ! F_85 ( & V_104 -> V_78 ) )
goto V_72;
V_104 -> V_128 . V_230 = 0 ;
F_183 ( & V_104 -> V_232 , & V_115 -> V_233 ) ;
F_185 ( & V_115 -> V_234 ) ;
V_115 -> V_231 -- ;
if ( V_104 -> V_228 == 0 )
V_115 -> V_229 -- ;
V_104 -> V_228 = 0 ;
F_13 ( & V_104 -> V_52 ) ;
F_13 ( & V_115 -> V_52 ) ;
F_30 ( V_104 -> V_129 ) ;
if ( V_104 -> V_226 )
V_29 = 1 ;
F_46 ( & V_104 -> V_78 ) ;
F_86 ( & V_104 -> V_128 ) ;
return V_29 ;
V_72:
F_13 ( & V_104 -> V_52 ) ;
V_532:
F_13 ( & V_115 -> V_52 ) ;
return 0 ;
}
void F_397 ( struct V_109 * V_110 ,
struct V_34 * V_35 ,
struct V_65 * V_277 ,
T_2 V_17 , int V_160 )
{
int V_533 = 1 ;
int V_29 ;
if ( V_35 -> V_273 . V_22 != V_209 ) {
V_29 = F_149 ( V_35 -> V_37 , V_110 ,
V_277 -> V_32 , V_277 -> V_49 ,
V_17 , V_35 -> V_273 . V_22 ,
F_228 ( V_277 ) ,
V_219 , NULL , 0 ) ;
F_30 ( V_29 ) ;
}
if ( ! V_160 )
return;
if ( F_398 ( V_277 ) == V_110 -> V_298 ) {
struct V_1 * V_2 ;
if ( V_35 -> V_273 . V_22 != V_209 ) {
V_29 = F_396 ( V_110 , V_35 , V_277 -> V_32 ) ;
if ( ! V_29 )
goto V_72;
}
V_2 = F_68 ( V_35 -> V_37 , V_277 -> V_32 ) ;
if ( F_399 ( V_277 , V_534 ) ) {
F_376 ( V_35 , V_2 , V_277 -> V_32 , V_277 -> V_49 , 1 ) ;
F_6 ( V_2 ) ;
goto V_72;
}
F_8 ( F_229 ( V_535 , & V_277 -> V_536 ) ) ;
F_29 ( V_2 , V_277 -> V_32 , V_277 -> V_49 ) ;
F_382 ( V_2 , V_277 -> V_49 , V_515 , 0 ) ;
F_6 ( V_2 ) ;
F_377 ( V_35 , V_277 -> V_32 , V_277 -> V_49 ) ;
V_533 = 0 ;
}
V_72:
if ( V_533 )
F_391 ( V_35 -> V_37 , V_277 -> V_49 ,
F_228 ( V_277 ) ,
V_35 -> V_273 . V_22 ) ;
F_400 ( V_537 , & V_277 -> V_536 ) ;
}
int V_284 ( struct V_109 * V_110 , struct V_34 * V_35 ,
T_2 V_27 , T_2 V_36 , T_2 V_17 , T_2 V_146 ,
T_2 V_133 , T_2 V_33 , int V_208 )
{
int V_29 ;
struct V_12 * V_37 = V_35 -> V_37 ;
if ( F_226 ( V_35 ) )
return 0 ;
F_391 ( V_35 -> V_37 , V_36 , V_133 , V_146 ) ;
if ( V_146 == V_209 ) {
F_8 ( V_133 >= V_143 ) ;
F_166 ( V_35 , V_27 , V_36 , 1 ) ;
V_29 = 0 ;
} else if ( V_133 < V_143 ) {
V_29 = F_149 ( V_37 , V_110 , V_27 ,
V_36 ,
V_17 , V_146 , ( int ) V_133 ,
V_219 , NULL , V_208 ) ;
} else {
V_29 = F_150 ( V_37 , V_110 , V_27 ,
V_36 ,
V_17 , V_146 , V_133 ,
V_33 , V_219 ,
NULL , V_208 ) ;
}
return V_29 ;
}
static T_1 void
F_401 ( struct V_1 * V_2 ,
T_2 V_36 )
{
struct V_50 * V_53 ;
V_53 = F_25 ( V_2 ) ;
if ( ! V_53 )
return;
F_316 ( V_53 -> V_88 , F_1 ( V_2 ) ||
( V_2 -> V_11 -> V_538 >= V_36 ) ) ;
F_26 ( V_53 ) ;
}
static T_1 int
F_402 ( struct V_1 * V_2 )
{
struct V_50 * V_53 ;
int V_29 = 0 ;
V_53 = F_25 ( V_2 ) ;
if ( ! V_53 )
return ( V_2 -> V_3 == V_5 ) ? - V_175 : 0 ;
F_316 ( V_53 -> V_88 , F_1 ( V_2 ) ) ;
if ( V_2 -> V_3 == V_5 )
V_29 = - V_175 ;
F_26 ( V_53 ) ;
return V_29 ;
}
int F_403 ( T_2 V_7 )
{
if ( V_7 & V_329 )
return V_539 ;
else if ( V_7 & V_328 )
return V_540 ;
else if ( V_7 & V_327 )
return V_541 ;
else if ( V_7 & V_368 )
return V_542 ;
else if ( V_7 & V_369 )
return V_543 ;
else if ( V_7 & V_370 )
return V_544 ;
return V_545 ;
}
int F_404 ( struct V_1 * V_2 )
{
return F_403 ( V_2 -> V_7 ) ;
}
static const char * F_405 ( enum V_546 type )
{
if ( type >= V_334 )
return NULL ;
return V_547 [ type ] ;
}
static inline void
F_406 ( struct V_1 * V_2 ,
int V_514 )
{
if ( V_514 )
F_36 ( & V_2 -> V_548 ) ;
}
static inline void
F_407 ( struct V_1 * V_2 ,
int V_514 )
{
F_4 ( V_2 ) ;
if ( V_514 )
F_36 ( & V_2 -> V_548 ) ;
}
static struct V_1 *
F_408 ( struct V_1 * V_14 ,
struct V_549 * V_550 ,
int V_514 )
{
struct V_1 * V_551 ;
bool V_552 = false ;
V_77:
F_11 ( & V_550 -> V_553 ) ;
if ( V_552 ) {
if ( V_551 == V_550 -> V_14 )
return V_551 ;
F_45 ( & V_551 -> V_548 ) ;
F_6 ( V_551 ) ;
}
V_551 = V_550 -> V_14 ;
if ( ! V_551 )
return NULL ;
if ( V_551 == V_14 )
return V_551 ;
F_4 ( V_551 ) ;
if ( ! V_514 )
return V_551 ;
if ( F_309 ( & V_551 -> V_548 ) )
return V_551 ;
F_13 ( & V_550 -> V_553 ) ;
F_36 ( & V_551 -> V_548 ) ;
V_552 = true ;
goto V_77;
}
static inline void
F_409 ( struct V_1 * V_2 ,
int V_514 )
{
if ( V_514 )
F_45 ( & V_2 -> V_548 ) ;
F_6 ( V_2 ) ;
}
static T_1 int F_410 ( struct V_34 * V_554 ,
T_2 V_36 , T_2 V_555 ,
T_2 V_556 , struct V_67 * V_216 ,
T_2 V_7 , int V_514 )
{
int V_29 = 0 ;
struct V_34 * V_35 = V_554 -> V_37 -> V_62 ;
struct V_549 * V_557 = NULL ;
struct V_1 * V_14 = NULL ;
T_2 V_508 = 0 ;
T_2 V_558 = 0 ;
int V_559 = 2 * 1024 * 1024 ;
struct V_102 * V_105 ;
int V_560 = 0 ;
int V_561 = F_403 ( V_7 ) ;
int V_562 = ( V_7 & V_322 ) ?
V_563 : V_516 ;
bool V_564 = false ;
bool V_565 = false ;
bool V_566 = true ;
bool V_567 = false ;
F_8 ( V_36 < V_35 -> V_253 ) ;
V_216 -> type = V_76 ;
V_216 -> V_22 = 0 ;
V_216 -> V_33 = 0 ;
F_411 ( V_554 , V_36 , V_555 , V_7 ) ;
V_105 = F_69 ( V_35 -> V_37 , V_7 ) ;
if ( ! V_105 ) {
F_392 ( V_35 -> V_37 , L_20 , V_7 ) ;
return - V_382 ;
}
if ( F_305 ( V_105 ) )
V_566 = false ;
if ( V_7 & V_321 && V_566 ) {
V_557 = & V_35 -> V_37 -> V_568 ;
if ( ! F_250 ( V_35 , V_569 ) )
V_559 = 64 * 1024 ;
}
if ( ( V_7 & V_322 ) && V_566 &&
F_250 ( V_35 , V_569 ) ) {
V_557 = & V_35 -> V_37 -> V_570 ;
}
if ( V_557 ) {
F_11 ( & V_557 -> V_52 ) ;
if ( V_557 -> V_14 )
V_556 = V_557 -> V_571 ;
F_13 ( & V_557 -> V_52 ) ;
}
V_508 = F_412 ( V_508 , V_26 ( V_35 , 0 ) ) ;
V_508 = F_412 ( V_508 , V_556 ) ;
if ( ! V_557 )
V_559 = 0 ;
if ( V_508 == V_556 ) {
V_14 = F_68 ( V_35 -> V_37 ,
V_508 ) ;
if ( V_14 && F_3 ( V_14 , V_7 ) &&
V_14 -> V_3 != V_94 ) {
F_36 ( & V_105 -> V_336 ) ;
if ( F_172 ( & V_14 -> V_90 ) ||
V_14 -> V_296 ) {
F_6 ( V_14 ) ;
F_45 ( & V_105 -> V_336 ) ;
} else {
V_561 = F_404 ( V_14 ) ;
F_406 ( V_14 , V_514 ) ;
goto V_572;
}
} else if ( V_14 ) {
F_6 ( V_14 ) ;
}
}
V_573:
V_567 = false ;
F_36 ( & V_105 -> V_336 ) ;
F_173 (block_group, &space_info->block_groups[index],
list) {
T_2 V_33 ;
int V_3 ;
F_407 ( V_14 , V_514 ) ;
V_508 = V_14 -> V_21 . V_22 ;
if ( ! F_3 ( V_14 , V_7 ) ) {
T_2 V_574 = V_327 |
V_328 |
V_369 |
V_370 |
V_329 ;
if ( ( V_7 & V_574 ) && ! ( V_14 -> V_7 & V_574 ) )
goto V_560;
}
V_572:
V_3 = F_1 ( V_14 ) ;
if ( F_332 ( ! V_3 ) ) {
V_29 = F_51 ( V_14 , 0 ) ;
F_30 ( V_29 < 0 ) ;
V_29 = 0 ;
}
if ( F_332 ( V_14 -> V_3 == V_5 ) )
goto V_560;
if ( F_332 ( V_14 -> V_296 ) )
goto V_560;
if ( V_557 ) {
struct V_1 * V_575 ;
unsigned long V_576 ;
V_575 = F_408 ( V_14 ,
V_557 ,
V_514 ) ;
if ( ! V_575 )
goto V_577;
if ( V_575 != V_14 &&
( V_575 -> V_296 ||
! F_3 ( V_575 , V_7 ) ) )
goto V_578;
V_33 = F_413 ( V_575 ,
V_557 ,
V_36 ,
V_575 -> V_21 . V_22 ,
& V_558 ) ;
if ( V_33 ) {
F_13 ( & V_557 -> V_553 ) ;
F_414 ( V_35 ,
V_575 ,
V_508 , V_36 ) ;
if ( V_575 != V_14 ) {
F_409 ( V_14 ,
V_514 ) ;
V_14 = V_575 ;
}
goto V_579;
}
F_8 ( V_557 -> V_14 != V_575 ) ;
V_578:
if ( V_560 >= V_580 &&
V_575 != V_14 ) {
F_13 ( & V_557 -> V_553 ) ;
F_409 ( V_575 ,
V_514 ) ;
goto V_581;
}
F_415 ( NULL , V_557 ) ;
if ( V_575 != V_14 )
F_409 ( V_575 ,
V_514 ) ;
V_577:
if ( V_560 >= V_580 ) {
F_13 ( & V_557 -> V_553 ) ;
goto V_581;
}
V_576 = F_34 (unsigned long,
empty_cluster + empty_size,
block_group->full_stripe_len) ;
V_29 = F_416 ( V_35 , V_14 ,
V_557 , V_508 ,
V_36 ,
V_576 ) ;
if ( V_29 == 0 ) {
V_33 = F_413 ( V_14 ,
V_557 ,
V_36 ,
V_508 ,
& V_558 ) ;
if ( V_33 ) {
F_13 ( & V_557 -> V_553 ) ;
F_414 ( V_35 ,
V_14 , V_508 ,
V_36 ) ;
goto V_579;
}
} else if ( ! V_3 && V_560 > V_582
&& ! V_564 ) {
F_13 ( & V_557 -> V_553 ) ;
V_564 = true ;
F_401 ( V_14 ,
V_36 + V_559 + V_555 ) ;
goto V_572;
}
F_415 ( NULL , V_557 ) ;
F_13 ( & V_557 -> V_553 ) ;
goto V_560;
}
V_581:
F_11 ( & V_14 -> V_11 -> V_583 ) ;
if ( V_3 &&
V_14 -> V_11 -> V_538 <
V_36 + V_559 + V_555 ) {
if ( V_14 -> V_11 -> V_538 >
V_558 )
V_558 =
V_14 -> V_11 -> V_538 ;
F_13 ( & V_14 -> V_11 -> V_583 ) ;
goto V_560;
}
F_13 ( & V_14 -> V_11 -> V_583 ) ;
V_33 = F_417 ( V_14 , V_508 ,
V_36 , V_555 ,
& V_558 ) ;
if ( ! V_33 && ! V_565 && ! V_3 &&
V_560 > V_582 ) {
F_401 ( V_14 ,
V_36 + V_555 ) ;
V_565 = true ;
goto V_572;
} else if ( ! V_33 ) {
if ( ! V_3 )
V_567 = true ;
goto V_560;
}
V_579:
V_508 = F_141 ( V_33 , V_35 -> V_584 ) ;
if ( V_508 + V_36 >
V_14 -> V_21 . V_22 + V_14 -> V_21 . V_33 ) {
F_29 ( V_14 , V_33 , V_36 ) ;
goto V_560;
}
if ( V_33 < V_508 )
F_29 ( V_14 , V_33 ,
V_508 - V_33 ) ;
F_30 ( V_33 > V_508 ) ;
V_29 = F_382 ( V_14 , V_36 ,
V_562 , V_514 ) ;
if ( V_29 == - V_178 ) {
F_29 ( V_14 , V_33 , V_36 ) ;
goto V_560;
}
V_216 -> V_22 = V_508 ;
V_216 -> V_33 = V_36 ;
F_418 ( V_554 , V_14 ,
V_508 , V_36 ) ;
F_409 ( V_14 , V_514 ) ;
break;
V_560:
V_564 = false ;
V_565 = false ;
F_30 ( V_561 != F_404 ( V_14 ) ) ;
F_409 ( V_14 , V_514 ) ;
}
F_45 ( & V_105 -> V_336 ) ;
if ( ! V_216 -> V_22 && V_560 >= V_585 && V_567 )
goto V_573;
if ( ! V_216 -> V_22 && ++ V_561 < V_334 )
goto V_573;
if ( ! V_216 -> V_22 && V_560 < V_580 ) {
V_561 = 0 ;
V_560 ++ ;
if ( V_560 == V_586 ) {
struct V_109 * V_110 ;
int V_587 = 0 ;
V_110 = V_377 -> V_378 ;
if ( V_110 )
V_587 = 1 ;
else
V_110 = F_202 ( V_35 ) ;
if ( F_203 ( V_110 ) ) {
V_29 = F_204 ( V_110 ) ;
goto V_72;
}
V_29 = F_285 ( V_110 , V_35 , V_7 ,
V_381 ) ;
if ( V_29 < 0 && V_29 != - V_382 )
F_153 ( V_110 ,
V_35 , V_29 ) ;
else
V_29 = 0 ;
if ( ! V_587 )
F_206 ( V_110 , V_35 ) ;
if ( V_29 )
goto V_72;
}
if ( V_560 == V_580 ) {
V_555 = 0 ;
V_559 = 0 ;
}
goto V_573;
} else if ( ! V_216 -> V_22 ) {
V_29 = - V_382 ;
} else if ( V_216 -> V_22 ) {
V_29 = 0 ;
}
V_72:
if ( V_29 == - V_382 )
V_216 -> V_33 = V_558 ;
return V_29 ;
}
static void F_302 ( struct V_102 * V_13 , T_2 V_203 ,
int V_588 )
{
struct V_1 * V_2 ;
int V_561 = 0 ;
F_11 ( & V_13 -> V_52 ) ;
F_419 ( V_589 L_21 ,
V_13 -> V_7 ,
V_13 -> V_324 - V_13 -> V_325 - V_13 -> V_337 -
V_13 -> V_338 - V_13 -> V_339 ,
( V_13 -> V_108 ) ? L_22 : L_23 ) ;
F_419 ( V_589 L_24
L_25 ,
V_13 -> V_324 , V_13 -> V_325 , V_13 -> V_337 ,
V_13 -> V_338 , V_13 -> V_340 ,
V_13 -> V_339 ) ;
F_13 ( & V_13 -> V_52 ) ;
if ( ! V_588 )
return;
F_36 ( & V_13 -> V_336 ) ;
V_77:
F_173 (cache, &info->block_groups[index], list) {
F_11 ( & V_2 -> V_52 ) ;
F_419 ( V_589 L_26
L_27
L_28 ,
V_2 -> V_21 . V_22 , V_2 -> V_21 . V_33 ,
F_373 ( & V_2 -> V_135 ) , V_2 -> V_9 ,
V_2 -> V_10 , V_2 -> V_296 ? L_29 : L_22 ) ;
F_420 ( V_2 , V_203 ) ;
F_13 ( & V_2 -> V_52 ) ;
}
if ( ++ V_561 < V_334 )
goto V_77;
F_45 ( & V_13 -> V_336 ) ;
}
int F_421 ( struct V_34 * V_35 ,
T_2 V_36 , T_2 V_590 ,
T_2 V_555 , T_2 V_556 ,
struct V_67 * V_216 , int V_184 , int V_514 )
{
bool V_591 = false ;
T_2 V_7 ;
int V_29 ;
V_7 = F_283 ( V_35 , V_184 ) ;
V_77:
F_8 ( V_36 < V_35 -> V_253 ) ;
V_29 = F_410 ( V_35 , V_36 , V_555 , V_556 , V_216 ,
V_7 , V_514 ) ;
if ( V_29 == - V_382 ) {
if ( ! V_591 && V_216 -> V_33 ) {
V_36 = F_315 ( V_36 >> 1 , V_216 -> V_33 ) ;
V_36 = F_142 ( V_36 , V_35 -> V_253 ) ;
V_36 = F_412 ( V_36 , V_590 ) ;
if ( V_36 == V_590 )
V_591 = true ;
goto V_77;
} else if ( F_250 ( V_35 , V_397 ) ) {
struct V_102 * V_388 ;
V_388 = F_69 ( V_35 -> V_37 , V_7 ) ;
F_392 ( V_35 -> V_37 , L_30 ,
V_7 , V_36 ) ;
if ( V_388 )
F_302 ( V_388 , V_36 , 1 ) ;
}
}
return V_29 ;
}
static int F_422 ( struct V_34 * V_35 ,
T_2 V_32 , T_2 V_49 ,
int V_533 , int V_514 )
{
struct V_1 * V_2 ;
int V_29 = 0 ;
V_2 = F_68 ( V_35 -> V_37 , V_32 ) ;
if ( ! V_2 ) {
F_392 ( V_35 -> V_37 , L_31 ,
V_32 ) ;
return - V_382 ;
}
if ( V_533 )
F_376 ( V_35 , V_2 , V_32 , V_49 , 1 ) ;
else {
if ( F_250 ( V_35 , V_522 ) )
V_29 = F_145 ( V_35 , V_32 , V_49 , NULL ) ;
F_29 ( V_2 , V_32 , V_49 ) ;
F_382 ( V_2 , V_49 , V_515 , V_514 ) ;
}
F_6 ( V_2 ) ;
F_377 ( V_35 , V_32 , V_49 ) ;
return V_29 ;
}
int F_423 ( struct V_34 * V_35 ,
T_2 V_32 , T_2 V_49 , int V_514 )
{
return F_422 ( V_35 , V_32 , V_49 , 0 , V_514 ) ;
}
int F_424 ( struct V_34 * V_35 ,
T_2 V_32 , T_2 V_49 )
{
return F_422 ( V_35 , V_32 , V_49 , 1 , 0 ) ;
}
static int F_157 ( struct V_109 * V_110 ,
struct V_34 * V_35 ,
T_2 V_17 , T_2 V_146 ,
T_2 V_7 , T_2 V_133 , T_2 V_33 ,
struct V_67 * V_216 , int V_132 )
{
int V_29 ;
struct V_12 * V_37 = V_35 -> V_37 ;
struct V_116 * V_592 ;
struct V_163 * V_164 ;
struct V_63 * V_64 ;
struct V_65 * V_66 ;
int type ;
T_3 V_56 ;
if ( V_17 > 0 )
type = V_154 ;
else
type = V_155 ;
V_56 = sizeof( * V_592 ) + F_125 ( type ) ;
V_64 = F_33 () ;
if ( ! V_64 )
return - V_71 ;
V_64 -> V_213 = 1 ;
V_29 = F_106 ( V_110 , V_37 -> V_62 , V_64 ,
V_216 , V_56 ) ;
if ( V_29 ) {
F_50 ( V_64 ) ;
return V_29 ;
}
V_66 = V_64 -> V_82 [ 0 ] ;
V_592 = F_78 ( V_66 , V_64 -> V_83 [ 0 ] ,
struct V_116 ) ;
F_90 ( V_66 , V_592 , V_132 ) ;
F_91 ( V_66 , V_592 , V_110 -> V_298 ) ;
F_92 ( V_66 , V_592 ,
V_7 | V_145 ) ;
V_164 = (struct V_163 * ) ( V_592 + 1 ) ;
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
V_29 = F_370 ( V_110 , V_35 , V_216 -> V_22 , V_216 -> V_33 , 1 ) ;
if ( V_29 ) {
F_392 ( V_37 , L_32 ,
V_216 -> V_22 , V_216 -> V_33 ) ;
F_83 () ;
}
F_425 ( V_35 , V_216 -> V_22 , V_216 -> V_33 ) ;
return V_29 ;
}
static int F_164 ( struct V_109 * V_110 ,
struct V_34 * V_35 ,
T_2 V_17 , T_2 V_146 ,
T_2 V_7 , struct V_593 * V_21 ,
int V_167 , struct V_67 * V_216 ,
int V_208 )
{
int V_29 ;
struct V_12 * V_37 = V_35 -> V_37 ;
struct V_116 * V_592 ;
struct V_138 * V_594 ;
struct V_163 * V_164 ;
struct V_63 * V_64 ;
struct V_65 * V_66 ;
T_3 V_56 = sizeof( * V_592 ) + sizeof( * V_164 ) ;
T_2 V_36 = V_216 -> V_33 ;
bool V_173 = F_76 ( V_35 -> V_37 ,
V_121 ) ;
if ( ! V_173 )
V_56 += sizeof( * V_594 ) ;
V_64 = F_33 () ;
if ( ! V_64 ) {
F_424 ( V_35 , V_216 -> V_22 ,
V_35 -> V_87 ) ;
return - V_71 ;
}
V_64 -> V_213 = 1 ;
V_29 = F_106 ( V_110 , V_37 -> V_62 , V_64 ,
V_216 , V_56 ) ;
if ( V_29 ) {
F_50 ( V_64 ) ;
F_424 ( V_35 , V_216 -> V_22 ,
V_35 -> V_87 ) ;
return V_29 ;
}
V_66 = V_64 -> V_82 [ 0 ] ;
V_592 = F_78 ( V_66 , V_64 -> V_83 [ 0 ] ,
struct V_116 ) ;
F_90 ( V_66 , V_592 , 1 ) ;
F_91 ( V_66 , V_592 , V_110 -> V_298 ) ;
F_92 ( V_66 , V_592 ,
V_7 | V_144 ) ;
if ( V_173 ) {
V_164 = (struct V_163 * ) ( V_592 + 1 ) ;
V_36 = V_35 -> V_87 ;
} else {
V_594 = (struct V_138 * ) ( V_592 + 1 ) ;
F_159 ( V_66 , V_594 , V_21 ) ;
F_94 ( V_66 , V_594 , V_167 ) ;
V_164 = (struct V_163 * ) ( V_594 + 1 ) ;
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
V_29 = F_370 ( V_110 , V_35 , V_216 -> V_22 , V_35 -> V_87 ,
1 ) ;
if ( V_29 ) {
F_392 ( V_37 , L_32 ,
V_216 -> V_22 , V_216 -> V_33 ) ;
F_83 () ;
}
F_425 ( V_35 , V_216 -> V_22 , V_35 -> V_87 ) ;
return V_29 ;
}
int F_426 ( struct V_109 * V_110 ,
struct V_34 * V_35 ,
T_2 V_146 , T_2 V_133 ,
T_2 V_33 , struct V_67 * V_216 )
{
int V_29 ;
F_30 ( V_146 == V_209 ) ;
V_29 = F_150 ( V_35 -> V_37 , V_110 , V_216 -> V_22 ,
V_216 -> V_33 , 0 ,
V_146 , V_133 , V_33 ,
V_235 , NULL , 0 ) ;
return V_29 ;
}
int F_427 ( struct V_109 * V_110 ,
struct V_34 * V_35 ,
T_2 V_146 , T_2 V_133 , T_2 V_33 ,
struct V_67 * V_216 )
{
int V_29 ;
struct V_1 * V_14 ;
if ( ! F_76 ( V_35 -> V_37 , V_513 ) ) {
V_29 = F_380 ( V_35 , V_216 -> V_22 , V_216 -> V_33 ) ;
if ( V_29 )
return V_29 ;
}
V_14 = F_68 ( V_35 -> V_37 , V_216 -> V_22 ) ;
if ( ! V_14 )
return - V_509 ;
V_29 = F_382 ( V_14 , V_216 -> V_33 ,
V_563 , 0 ) ;
F_30 ( V_29 ) ;
V_29 = F_157 ( V_110 , V_35 , 0 , V_146 ,
0 , V_133 , V_33 , V_216 , 1 ) ;
F_6 ( V_14 ) ;
return V_29 ;
}
static struct V_65 *
F_428 ( struct V_109 * V_110 , struct V_34 * V_35 ,
T_2 V_27 , int V_167 )
{
struct V_65 * V_277 ;
V_277 = F_429 ( V_35 , V_27 ) ;
if ( ! V_277 )
return F_430 ( - V_71 ) ;
F_431 ( V_277 , V_110 -> V_298 ) ;
F_432 ( V_35 -> V_273 . V_22 , V_277 , V_167 ) ;
F_433 ( V_277 ) ;
F_434 ( V_110 , V_35 -> V_37 , V_277 ) ;
F_400 ( V_595 , & V_277 -> V_536 ) ;
F_435 ( V_277 ) ;
F_436 ( V_277 ) ;
if ( V_35 -> V_273 . V_22 == V_209 ) {
V_277 -> V_596 = V_35 -> V_597 % 2 ;
if ( V_277 -> V_596 == 0 )
F_375 ( & V_35 -> V_598 , V_277 -> V_32 ,
V_277 -> V_32 + V_277 -> V_49 - 1 , V_40 ) ;
else
F_437 ( & V_35 -> V_598 , V_277 -> V_32 ,
V_277 -> V_32 + V_277 -> V_49 - 1 , V_40 ) ;
} else {
V_277 -> V_596 = - 1 ;
F_375 ( & V_110 -> V_127 -> V_599 , V_277 -> V_32 ,
V_277 -> V_32 + V_277 -> V_49 - 1 , V_40 ) ;
}
V_110 -> V_600 ++ ;
return V_277 ;
}
static struct V_254 *
F_438 ( struct V_109 * V_110 ,
struct V_34 * V_35 , T_3 V_601 )
{
struct V_254 * V_421 ;
struct V_254 * V_255 = & V_35 -> V_37 -> V_258 ;
int V_29 ;
bool V_602 = false ;
V_421 = F_335 ( V_110 , V_35 ) ;
if ( F_332 ( V_421 -> V_56 == 0 ) )
goto V_603;
V_77:
V_29 = F_333 ( V_421 , V_601 ) ;
if ( ! V_29 )
return V_421 ;
if ( V_421 -> V_604 )
return F_430 ( V_29 ) ;
if ( V_421 -> type == V_605 && ! V_602 ) {
V_602 = true ;
F_349 ( V_35 -> V_37 ) ;
goto V_77;
}
if ( F_250 ( V_35 , V_397 ) ) {
static F_439 ( V_606 ,
V_607 * 10 ,
1 ) ;
if ( F_440 ( & V_606 ) )
F_441 ( 1 , V_608
L_33 , V_29 ) ;
}
V_603:
V_29 = F_328 ( V_35 , V_421 , V_601 ,
V_399 ) ;
if ( ! V_29 )
return V_421 ;
if ( V_421 -> type != V_605 &&
V_421 -> V_105 == V_255 -> V_105 ) {
V_29 = F_333 ( V_255 , V_601 ) ;
if ( ! V_29 )
return V_255 ;
}
return F_430 ( V_29 ) ;
}
static void F_442 ( struct V_12 * V_37 ,
struct V_254 * V_421 , T_3 V_601 )
{
F_336 ( V_421 , V_601 , 0 ) ;
F_338 ( V_37 , V_421 , NULL , 0 ) ;
}
struct V_65 * F_443 ( struct V_109 * V_110 ,
struct V_34 * V_35 ,
T_2 V_17 , T_2 V_146 ,
struct V_593 * V_21 , int V_167 ,
T_2 V_609 , T_2 V_555 )
{
struct V_67 V_216 ;
struct V_254 * V_421 ;
struct V_65 * V_277 ;
struct V_180 * V_129 ;
T_2 V_7 = 0 ;
int V_29 ;
T_3 V_601 = V_35 -> V_87 ;
bool V_173 = F_76 ( V_35 -> V_37 ,
V_121 ) ;
if ( F_226 ( V_35 ) ) {
V_277 = F_428 ( V_110 , V_35 , V_35 -> V_610 ,
V_167 ) ;
if ( ! F_203 ( V_277 ) )
V_35 -> V_610 += V_601 ;
return V_277 ;
}
V_421 = F_438 ( V_110 , V_35 , V_601 ) ;
if ( F_203 ( V_421 ) )
return F_444 ( V_421 ) ;
V_29 = F_421 ( V_35 , V_601 , V_601 ,
V_555 , V_609 , & V_216 , 0 , 0 ) ;
if ( V_29 )
goto V_611;
V_277 = F_428 ( V_110 , V_35 , V_216 . V_22 , V_167 ) ;
if ( F_203 ( V_277 ) ) {
V_29 = F_204 ( V_277 ) ;
goto V_612;
}
if ( V_146 == V_613 ) {
if ( V_17 == 0 )
V_17 = V_216 . V_22 ;
V_7 |= V_126 ;
} else
F_30 ( V_17 > 0 ) ;
if ( V_146 != V_209 ) {
V_129 = F_217 () ;
if ( ! V_129 ) {
V_29 = - V_71 ;
goto V_614;
}
if ( V_21 )
memcpy ( & V_129 -> V_21 , V_21 , sizeof( V_129 -> V_21 ) ) ;
else
memset ( & V_129 -> V_21 , 0 , sizeof( V_129 -> V_21 ) ) ;
V_129 -> V_131 = V_7 ;
if ( V_173 )
V_129 -> V_220 = 0 ;
else
V_129 -> V_220 = 1 ;
V_129 -> V_130 = 1 ;
V_129 -> V_184 = 0 ;
V_129 -> V_167 = V_167 ;
V_29 = F_149 ( V_35 -> V_37 , V_110 ,
V_216 . V_22 , V_216 . V_33 ,
V_17 , V_146 , V_167 ,
V_235 ,
V_129 , 0 ) ;
if ( V_29 )
goto V_615;
}
return V_277 ;
V_615:
F_181 ( V_129 ) ;
V_614:
F_445 ( V_277 ) ;
V_612:
F_423 ( V_35 , V_216 . V_22 , V_216 . V_33 , 0 ) ;
V_611:
F_442 ( V_35 -> V_37 , V_421 , V_601 ) ;
return F_430 ( V_29 ) ;
}
static T_1 void F_446 ( struct V_109 * V_110 ,
struct V_34 * V_35 ,
struct V_616 * V_617 ,
struct V_63 * V_64 )
{
T_2 V_27 ;
T_2 V_301 ;
T_2 V_112 ;
T_2 V_7 ;
T_3 V_70 ;
T_3 V_601 ;
struct V_67 V_21 ;
struct V_65 * V_511 ;
int V_29 ;
int V_618 ;
int V_619 = 0 ;
if ( V_64 -> V_83 [ V_617 -> V_167 ] < V_617 -> V_620 ) {
V_617 -> V_621 = V_617 -> V_621 * 2 / 3 ;
V_617 -> V_621 = F_412 ( V_617 -> V_621 , 2 ) ;
} else {
V_617 -> V_621 = V_617 -> V_621 * 3 / 2 ;
V_617 -> V_621 = F_24 ( int , V_617 -> V_621 ,
F_447 ( V_35 ) ) ;
}
V_511 = V_64 -> V_82 [ V_617 -> V_167 ] ;
V_70 = F_38 ( V_511 ) ;
V_601 = V_35 -> V_87 ;
for ( V_618 = V_64 -> V_83 [ V_617 -> V_167 ] ; V_618 < V_70 ; V_618 ++ ) {
if ( V_619 >= V_617 -> V_621 )
break;
F_47 () ;
V_27 = F_234 ( V_511 , V_618 ) ;
V_301 = F_448 ( V_511 , V_618 ) ;
if ( V_618 == V_64 -> V_83 [ V_617 -> V_167 ] )
goto V_75;
if ( V_617 -> V_622 == V_623 &&
V_301 <= V_35 -> V_273 . V_33 )
continue;
V_29 = F_75 ( V_110 , V_35 , V_27 ,
V_617 -> V_167 - 1 , 1 , & V_112 ,
& V_7 ) ;
if ( V_29 < 0 )
continue;
F_30 ( V_112 == 0 ) ;
if ( V_617 -> V_622 == V_624 ) {
if ( V_112 == 1 )
goto V_75;
if ( V_617 -> V_167 == 1 &&
( V_7 & V_126 ) )
continue;
if ( ! V_617 -> V_625 ||
V_301 <= V_35 -> V_273 . V_33 )
continue;
F_123 ( V_511 , & V_21 , V_618 ) ;
V_29 = F_449 ( & V_21 ,
& V_617 -> V_626 ) ;
if ( V_29 < 0 )
continue;
} else {
if ( V_617 -> V_167 == 1 &&
( V_7 & V_126 ) )
continue;
}
V_75:
F_450 ( V_35 , V_27 ) ;
V_619 ++ ;
}
V_617 -> V_620 = V_618 ;
}
static int F_451 ( struct V_109 * V_110 ,
struct V_34 * V_35 ,
struct V_65 * V_511 )
{
int V_44 = F_38 ( V_511 ) ;
int V_43 , V_627 ;
struct V_67 V_21 ;
struct V_280 * V_281 ;
T_2 V_27 , V_36 ;
for ( V_43 = 0 ; V_43 < V_44 ; V_43 ++ ) {
F_40 ( V_511 , & V_21 , V_43 ) ;
if ( V_21 . type != V_285 )
continue;
V_281 = F_78 ( V_511 , V_43 , struct V_280 ) ;
V_627 = F_230 ( V_511 , V_281 ) ;
if ( V_627 == V_286 )
continue;
V_27 = F_231 ( V_511 , V_281 ) ;
if ( ! V_27 )
continue;
V_36 = F_232 ( V_511 , V_281 ) ;
}
return 0 ;
}
static int F_452 ( struct V_34 * V_35 ,
struct V_63 * V_64 , int V_628 )
{
int V_167 = 0 ;
int V_44 , V_618 ;
struct V_65 * V_511 ;
if ( V_628 == 0 )
return 1 ;
while ( V_167 <= V_628 ) {
V_511 = V_64 -> V_82 [ V_167 ] ;
V_44 = F_38 ( V_511 ) ;
V_64 -> V_83 [ V_167 ] ++ ;
V_618 = V_64 -> V_83 [ V_167 ] ;
if ( V_618 >= V_44 || V_167 == 0 ) {
if ( V_167 != V_628 ) {
F_453 ( V_511 , V_64 -> V_629 [ V_167 ] ) ;
V_64 -> V_629 [ V_167 ] = 0 ;
F_445 ( V_511 ) ;
V_64 -> V_82 [ V_167 ] = NULL ;
V_64 -> V_83 [ V_167 ] = 0 ;
}
} else {
break;
}
V_167 ++ ;
}
V_511 = V_64 -> V_82 [ V_628 ] ;
if ( V_64 -> V_83 [ V_628 ] >= F_38 ( V_511 ) )
return 1 ;
return 0 ;
}
static int F_454 ( struct V_109 * V_110 ,
struct V_34 * V_35 ,
struct V_65 * V_630 ,
T_2 V_631 ,
int V_628 )
{
int V_29 = 0 ;
int V_167 ;
struct V_65 * V_511 = V_630 ;
struct V_63 * V_64 = NULL ;
F_30 ( V_628 < 0 || V_628 > V_168 ) ;
F_30 ( V_630 == NULL ) ;
if ( ! V_35 -> V_37 -> V_212 )
return 0 ;
if ( ! F_455 ( V_630 ) ) {
V_29 = F_456 ( V_630 , V_631 ) ;
if ( V_29 )
goto V_72;
}
if ( V_628 == 0 ) {
V_29 = F_451 ( V_110 , V_35 , V_630 ) ;
goto V_72;
}
V_64 = F_33 () ;
if ( ! V_64 )
return - V_71 ;
F_457 ( V_630 ) ;
V_64 -> V_82 [ V_628 ] = V_630 ;
V_64 -> V_83 [ V_628 ] = 0 ;
V_64 -> V_629 [ V_628 ] = 0 ;
V_632:
V_167 = V_628 ;
while ( V_167 >= 0 ) {
if ( V_64 -> V_82 [ V_167 ] == NULL ) {
int V_633 ;
T_2 V_634 ;
T_2 V_635 ;
V_511 = V_64 -> V_82 [ V_167 + 1 ] ;
V_633 = V_64 -> V_83 [ V_167 + 1 ] ;
V_635 = F_234 ( V_511 , V_633 ) ;
V_634 = F_448 ( V_511 , V_633 ) ;
V_511 = F_458 ( V_35 , V_635 , V_634 ) ;
if ( F_203 ( V_511 ) ) {
V_29 = F_204 ( V_511 ) ;
goto V_72;
} else if ( ! F_455 ( V_511 ) ) {
F_445 ( V_511 ) ;
V_29 = - V_175 ;
goto V_72;
}
V_64 -> V_82 [ V_167 ] = V_511 ;
V_64 -> V_83 [ V_167 ] = 0 ;
F_459 ( V_511 ) ;
F_460 ( V_511 , V_636 ) ;
V_64 -> V_629 [ V_167 ] = V_637 ;
}
if ( V_167 == 0 ) {
V_29 = F_451 ( V_110 , V_35 , V_64 -> V_82 [ V_167 ] ) ;
if ( V_29 )
goto V_72;
V_29 = F_452 ( V_35 , V_64 , V_628 ) ;
if ( V_29 )
break;
goto V_632;
}
V_167 -- ;
}
V_29 = 0 ;
V_72:
F_50 ( V_64 ) ;
return V_29 ;
}
static T_1 int F_461 ( struct V_109 * V_110 ,
struct V_34 * V_35 ,
struct V_63 * V_64 ,
struct V_616 * V_617 , int V_638 )
{
int V_167 = V_617 -> V_167 ;
struct V_65 * V_511 = V_64 -> V_82 [ V_167 ] ;
T_2 V_639 = V_126 ;
int V_29 ;
if ( V_617 -> V_622 == V_623 &&
F_227 ( V_511 ) != V_35 -> V_273 . V_22 )
return 1 ;
if ( V_638 &&
( ( V_617 -> V_622 == V_624 && V_617 -> V_112 [ V_167 ] != 1 ) ||
( V_617 -> V_622 == V_623 && ! ( V_617 -> V_7 [ V_167 ] & V_639 ) ) ) ) {
F_30 ( ! V_64 -> V_629 [ V_167 ] ) ;
V_29 = F_75 ( V_110 , V_35 ,
V_511 -> V_32 , V_167 , 1 ,
& V_617 -> V_112 [ V_167 ] ,
& V_617 -> V_7 [ V_167 ] ) ;
F_30 ( V_29 == - V_71 ) ;
if ( V_29 )
return V_29 ;
F_30 ( V_617 -> V_112 [ V_167 ] == 0 ) ;
}
if ( V_617 -> V_622 == V_624 ) {
if ( V_617 -> V_112 [ V_167 ] > 1 )
return 1 ;
if ( V_64 -> V_629 [ V_167 ] && ! V_617 -> V_174 ) {
F_453 ( V_511 , V_64 -> V_629 [ V_167 ] ) ;
V_64 -> V_629 [ V_167 ] = 0 ;
}
return 0 ;
}
if ( ! ( V_617 -> V_7 [ V_167 ] & V_639 ) ) {
F_30 ( ! V_64 -> V_629 [ V_167 ] ) ;
V_29 = F_235 ( V_110 , V_35 , V_511 , 1 ) ;
F_30 ( V_29 ) ;
V_29 = F_236 ( V_110 , V_35 , V_511 , 0 ) ;
F_30 ( V_29 ) ;
V_29 = F_216 ( V_110 , V_35 , V_511 -> V_32 ,
V_511 -> V_49 , V_639 ,
F_228 ( V_511 ) , 0 ) ;
F_30 ( V_29 ) ;
V_617 -> V_7 [ V_167 ] |= V_639 ;
}
if ( V_64 -> V_629 [ V_167 ] && V_167 > 0 ) {
F_453 ( V_511 , V_64 -> V_629 [ V_167 ] ) ;
V_64 -> V_629 [ V_167 ] = 0 ;
}
return 0 ;
}
static T_1 int F_462 ( struct V_109 * V_110 ,
struct V_34 * V_35 ,
struct V_63 * V_64 ,
struct V_616 * V_617 , int * V_638 )
{
T_2 V_27 ;
T_2 V_301 ;
T_2 V_17 ;
T_3 V_601 ;
struct V_67 V_21 ;
struct V_65 * V_80 ;
int V_167 = V_617 -> V_167 ;
int V_75 = 0 ;
int V_29 = 0 ;
bool V_640 = false ;
V_301 = F_448 ( V_64 -> V_82 [ V_167 ] ,
V_64 -> V_83 [ V_167 ] ) ;
if ( V_617 -> V_622 == V_623 &&
V_301 <= V_35 -> V_273 . V_33 ) {
* V_638 = 1 ;
return 1 ;
}
V_27 = F_234 ( V_64 -> V_82 [ V_167 ] , V_64 -> V_83 [ V_167 ] ) ;
V_601 = V_35 -> V_87 ;
V_80 = F_463 ( V_35 -> V_37 , V_27 ) ;
if ( ! V_80 ) {
V_80 = F_429 ( V_35 , V_27 ) ;
if ( ! V_80 )
return - V_71 ;
F_432 ( V_35 -> V_273 . V_22 , V_80 ,
V_167 - 1 ) ;
V_75 = 1 ;
}
F_433 ( V_80 ) ;
F_435 ( V_80 ) ;
V_29 = F_75 ( V_110 , V_35 , V_27 , V_167 - 1 , 1 ,
& V_617 -> V_112 [ V_167 - 1 ] ,
& V_617 -> V_7 [ V_167 - 1 ] ) ;
if ( V_29 < 0 ) {
F_464 ( V_80 ) ;
return V_29 ;
}
if ( F_332 ( V_617 -> V_112 [ V_167 - 1 ] == 0 ) ) {
F_392 ( V_35 -> V_37 , L_34 ) ;
F_83 () ;
}
* V_638 = 0 ;
if ( V_617 -> V_622 == V_624 ) {
if ( V_617 -> V_112 [ V_167 - 1 ] > 1 ) {
V_640 = true ;
if ( V_167 == 1 &&
( V_617 -> V_7 [ 0 ] & V_126 ) )
goto V_641;
if ( ! V_617 -> V_625 ||
V_301 <= V_35 -> V_273 . V_33 )
goto V_641;
F_123 ( V_64 -> V_82 [ V_167 ] , & V_21 ,
V_64 -> V_83 [ V_167 ] ) ;
V_29 = F_449 ( & V_21 , & V_617 -> V_626 ) ;
if ( V_29 < 0 )
goto V_641;
V_617 -> V_622 = V_623 ;
V_617 -> V_642 = V_167 - 1 ;
}
} else {
if ( V_167 == 1 &&
( V_617 -> V_7 [ 0 ] & V_126 ) )
goto V_641;
}
if ( ! F_465 ( V_80 , V_301 , 0 ) ) {
F_464 ( V_80 ) ;
F_445 ( V_80 ) ;
V_80 = NULL ;
* V_638 = 1 ;
}
if ( ! V_80 ) {
if ( V_75 && V_167 == 1 )
F_446 ( V_110 , V_35 , V_617 , V_64 ) ;
V_80 = F_458 ( V_35 , V_27 , V_301 ) ;
if ( F_203 ( V_80 ) ) {
return F_204 ( V_80 ) ;
} else if ( ! F_455 ( V_80 ) ) {
F_445 ( V_80 ) ;
return - V_175 ;
}
F_433 ( V_80 ) ;
F_435 ( V_80 ) ;
}
V_167 -- ;
F_30 ( V_167 != F_228 ( V_80 ) ) ;
V_64 -> V_82 [ V_167 ] = V_80 ;
V_64 -> V_83 [ V_167 ] = 0 ;
V_64 -> V_629 [ V_167 ] = V_643 ;
V_617 -> V_167 = V_167 ;
if ( V_617 -> V_167 == 1 )
V_617 -> V_620 = 0 ;
return 0 ;
V_641:
V_617 -> V_112 [ V_167 - 1 ] = 0 ;
V_617 -> V_7 [ V_167 - 1 ] = 0 ;
if ( V_617 -> V_622 == V_624 ) {
if ( V_617 -> V_7 [ V_167 ] & V_126 ) {
V_17 = V_64 -> V_82 [ V_167 ] -> V_32 ;
} else {
F_30 ( V_35 -> V_273 . V_22 !=
F_227 ( V_64 -> V_82 [ V_167 ] ) ) ;
V_17 = 0 ;
}
if ( V_640 ) {
V_29 = F_454 ( V_110 , V_35 , V_80 ,
V_301 , V_167 - 1 ) ;
if ( V_29 ) {
F_466 ( V_644 L_35
L_36
L_37 ,
V_35 -> V_37 -> V_415 -> V_645 , V_29 ) ;
}
}
V_29 = V_284 ( V_110 , V_35 , V_27 , V_601 , V_17 ,
V_35 -> V_273 . V_22 , V_167 - 1 , 0 , 0 ) ;
F_30 ( V_29 ) ;
}
F_464 ( V_80 ) ;
F_445 ( V_80 ) ;
* V_638 = 1 ;
return 1 ;
}
static T_1 int F_467 ( struct V_109 * V_110 ,
struct V_34 * V_35 ,
struct V_63 * V_64 ,
struct V_616 * V_617 )
{
int V_29 ;
int V_167 = V_617 -> V_167 ;
struct V_65 * V_511 = V_64 -> V_82 [ V_167 ] ;
T_2 V_17 = 0 ;
if ( V_617 -> V_622 == V_623 ) {
F_30 ( V_617 -> V_642 < V_167 ) ;
if ( V_167 < V_617 -> V_642 )
goto V_72;
V_29 = F_41 ( V_64 , V_167 + 1 , & V_617 -> V_626 ) ;
if ( V_29 > 0 )
V_617 -> V_625 = 0 ;
V_617 -> V_622 = V_624 ;
V_617 -> V_642 = - 1 ;
V_64 -> V_83 [ V_167 ] = 0 ;
if ( ! V_64 -> V_629 [ V_167 ] ) {
F_30 ( V_167 == 0 ) ;
F_433 ( V_511 ) ;
F_435 ( V_511 ) ;
V_64 -> V_629 [ V_167 ] = V_643 ;
V_29 = F_75 ( V_110 , V_35 ,
V_511 -> V_32 , V_167 , 1 ,
& V_617 -> V_112 [ V_167 ] ,
& V_617 -> V_7 [ V_167 ] ) ;
if ( V_29 < 0 ) {
F_453 ( V_511 , V_64 -> V_629 [ V_167 ] ) ;
V_64 -> V_629 [ V_167 ] = 0 ;
return V_29 ;
}
F_30 ( V_617 -> V_112 [ V_167 ] == 0 ) ;
if ( V_617 -> V_112 [ V_167 ] == 1 ) {
F_453 ( V_511 , V_64 -> V_629 [ V_167 ] ) ;
V_64 -> V_629 [ V_167 ] = 0 ;
return 1 ;
}
}
}
F_30 ( V_617 -> V_112 [ V_167 ] > 1 && ! V_64 -> V_629 [ V_167 ] ) ;
if ( V_617 -> V_112 [ V_167 ] == 1 ) {
if ( V_167 == 0 ) {
if ( V_617 -> V_7 [ V_167 ] & V_126 )
V_29 = F_236 ( V_110 , V_35 , V_511 , 1 ) ;
else
V_29 = F_236 ( V_110 , V_35 , V_511 , 0 ) ;
F_30 ( V_29 ) ;
V_29 = F_451 ( V_110 , V_35 , V_511 ) ;
if ( V_29 ) {
F_466 ( V_644 L_35
L_38
L_37 ,
V_35 -> V_37 -> V_415 -> V_645 , V_29 ) ;
}
}
if ( ! V_64 -> V_629 [ V_167 ] &&
F_398 ( V_511 ) == V_110 -> V_298 ) {
F_433 ( V_511 ) ;
F_435 ( V_511 ) ;
V_64 -> V_629 [ V_167 ] = V_643 ;
}
F_434 ( V_110 , V_35 -> V_37 , V_511 ) ;
}
if ( V_511 == V_35 -> V_128 ) {
if ( V_617 -> V_7 [ V_167 ] & V_126 )
V_17 = V_511 -> V_32 ;
else
F_30 ( V_35 -> V_273 . V_22 !=
F_227 ( V_511 ) ) ;
} else {
if ( V_617 -> V_7 [ V_167 + 1 ] & V_126 )
V_17 = V_64 -> V_82 [ V_167 + 1 ] -> V_32 ;
else
F_30 ( V_35 -> V_273 . V_22 !=
F_227 ( V_64 -> V_82 [ V_167 + 1 ] ) ) ;
}
F_397 ( V_110 , V_35 , V_511 , V_17 , V_617 -> V_112 [ V_167 ] == 1 ) ;
V_72:
V_617 -> V_112 [ V_167 ] = 0 ;
V_617 -> V_7 [ V_167 ] = 0 ;
return 0 ;
}
static T_1 int F_468 ( struct V_109 * V_110 ,
struct V_34 * V_35 ,
struct V_63 * V_64 ,
struct V_616 * V_617 )
{
int V_167 = V_617 -> V_167 ;
int V_638 = 1 ;
int V_29 ;
while ( V_167 >= 0 ) {
V_29 = F_461 ( V_110 , V_35 , V_64 , V_617 , V_638 ) ;
if ( V_29 > 0 )
break;
if ( V_167 == 0 )
break;
if ( V_64 -> V_83 [ V_167 ] >=
F_38 ( V_64 -> V_82 [ V_167 ] ) )
break;
V_29 = F_462 ( V_110 , V_35 , V_64 , V_617 , & V_638 ) ;
if ( V_29 > 0 ) {
V_64 -> V_83 [ V_167 ] ++ ;
continue;
} else if ( V_29 < 0 )
return V_29 ;
V_167 = V_617 -> V_167 ;
}
return 0 ;
}
static T_1 int F_469 ( struct V_109 * V_110 ,
struct V_34 * V_35 ,
struct V_63 * V_64 ,
struct V_616 * V_617 , int V_646 )
{
int V_167 = V_617 -> V_167 ;
int V_29 ;
V_64 -> V_83 [ V_167 ] = F_38 ( V_64 -> V_82 [ V_167 ] ) ;
while ( V_167 < V_646 && V_64 -> V_82 [ V_167 ] ) {
V_617 -> V_167 = V_167 ;
if ( V_64 -> V_83 [ V_167 ] + 1 <
F_38 ( V_64 -> V_82 [ V_167 ] ) ) {
V_64 -> V_83 [ V_167 ] ++ ;
return 0 ;
} else {
V_29 = F_467 ( V_110 , V_35 , V_64 , V_617 ) ;
if ( V_29 > 0 )
return 0 ;
if ( V_64 -> V_629 [ V_167 ] ) {
F_453 ( V_64 -> V_82 [ V_167 ] ,
V_64 -> V_629 [ V_167 ] ) ;
V_64 -> V_629 [ V_167 ] = 0 ;
}
F_445 ( V_64 -> V_82 [ V_167 ] ) ;
V_64 -> V_82 [ V_167 ] = NULL ;
V_167 ++ ;
}
}
return 1 ;
}
int F_470 ( struct V_34 * V_35 ,
struct V_254 * V_421 , int V_625 ,
int V_647 )
{
struct V_63 * V_64 ;
struct V_109 * V_110 ;
struct V_34 * V_86 = V_35 -> V_37 -> V_86 ;
struct V_648 * V_274 = & V_35 -> V_274 ;
struct V_616 * V_617 ;
struct V_67 V_21 ;
int V_81 = 0 ;
int V_29 ;
int V_167 ;
bool V_649 = false ;
F_182 ( V_35 -> V_37 , L_39 , V_35 -> V_22 ) ;
V_64 = F_33 () ;
if ( ! V_64 ) {
V_81 = - V_71 ;
goto V_72;
}
V_617 = F_53 ( sizeof( * V_617 ) , V_40 ) ;
if ( ! V_617 ) {
F_50 ( V_64 ) ;
V_81 = - V_71 ;
goto V_72;
}
V_110 = F_471 ( V_86 , 0 ) ;
if ( F_203 ( V_110 ) ) {
V_81 = F_204 ( V_110 ) ;
goto V_123;
}
if ( V_421 )
V_110 -> V_421 = V_421 ;
if ( F_472 ( & V_274 -> V_650 ) == 0 ) {
V_167 = F_228 ( V_35 -> V_128 ) ;
V_64 -> V_82 [ V_167 ] = F_473 ( V_35 ) ;
F_435 ( V_64 -> V_82 [ V_167 ] ) ;
V_64 -> V_83 [ V_167 ] = 0 ;
V_64 -> V_629 [ V_167 ] = V_643 ;
memset ( & V_617 -> V_626 , 0 ,
sizeof( V_617 -> V_626 ) ) ;
} else {
F_474 ( & V_21 , & V_274 -> V_650 ) ;
memcpy ( & V_617 -> V_626 , & V_21 ,
sizeof( V_617 -> V_626 ) ) ;
V_167 = V_274 -> V_651 ;
F_30 ( V_167 == 0 ) ;
V_64 -> V_652 = V_167 ;
V_29 = F_37 ( NULL , V_35 , & V_21 , V_64 , 0 , 0 ) ;
V_64 -> V_652 = 0 ;
if ( V_29 < 0 ) {
V_81 = V_29 ;
goto V_653;
}
F_8 ( V_29 > 0 ) ;
F_128 ( V_64 , 0 ) ;
V_167 = F_228 ( V_35 -> V_128 ) ;
while ( 1 ) {
F_433 ( V_64 -> V_82 [ V_167 ] ) ;
F_435 ( V_64 -> V_82 [ V_167 ] ) ;
V_64 -> V_629 [ V_167 ] = V_643 ;
V_29 = F_75 ( V_110 , V_35 ,
V_64 -> V_82 [ V_167 ] -> V_32 ,
V_167 , 1 , & V_617 -> V_112 [ V_167 ] ,
& V_617 -> V_7 [ V_167 ] ) ;
if ( V_29 < 0 ) {
V_81 = V_29 ;
goto V_653;
}
F_30 ( V_617 -> V_112 [ V_167 ] == 0 ) ;
if ( V_167 == V_274 -> V_651 )
break;
F_464 ( V_64 -> V_82 [ V_167 ] ) ;
V_64 -> V_629 [ V_167 ] = 0 ;
F_8 ( V_617 -> V_112 [ V_167 ] != 1 ) ;
V_167 -- ;
}
}
V_617 -> V_167 = V_167 ;
V_617 -> V_642 = - 1 ;
V_617 -> V_622 = V_624 ;
V_617 -> V_625 = V_625 ;
V_617 -> V_174 = 0 ;
V_617 -> V_647 = V_647 ;
V_617 -> V_621 = F_447 ( V_35 ) ;
while ( 1 ) {
V_29 = F_468 ( V_110 , V_35 , V_64 , V_617 ) ;
if ( V_29 < 0 ) {
V_81 = V_29 ;
break;
}
V_29 = F_469 ( V_110 , V_35 , V_64 , V_617 , V_168 ) ;
if ( V_29 < 0 ) {
V_81 = V_29 ;
break;
}
if ( V_29 > 0 ) {
F_30 ( V_617 -> V_622 != V_624 ) ;
break;
}
if ( V_617 -> V_622 == V_624 ) {
V_167 = V_617 -> V_167 ;
F_475 ( V_64 -> V_82 [ V_167 ] ,
& V_274 -> V_650 ,
V_64 -> V_83 [ V_167 ] ) ;
V_274 -> V_651 = V_167 ;
}
F_30 ( V_617 -> V_167 == 0 ) ;
if ( F_476 ( V_110 , V_86 ) ||
( ! V_647 && F_477 ( V_35 ) ) ) {
V_29 = F_478 ( V_110 , V_86 ,
& V_35 -> V_273 ,
V_274 ) ;
if ( V_29 ) {
F_153 ( V_110 , V_86 , V_29 ) ;
V_81 = V_29 ;
goto V_653;
}
F_479 ( V_110 , V_86 ) ;
if ( ! V_647 && F_477 ( V_35 ) ) {
F_480 ( L_40 ) ;
V_81 = - V_178 ;
goto V_123;
}
V_110 = F_471 ( V_86 , 0 ) ;
if ( F_203 ( V_110 ) ) {
V_81 = F_204 ( V_110 ) ;
goto V_123;
}
if ( V_421 )
V_110 -> V_421 = V_421 ;
}
}
F_44 ( V_64 ) ;
if ( V_81 )
goto V_653;
V_29 = F_481 ( V_110 , V_86 , & V_35 -> V_273 ) ;
if ( V_29 ) {
F_153 ( V_110 , V_86 , V_29 ) ;
goto V_653;
}
if ( V_35 -> V_273 . V_22 != V_613 ) {
V_29 = F_482 ( V_86 , & V_35 -> V_273 , V_64 ,
NULL , NULL ) ;
if ( V_29 < 0 ) {
F_153 ( V_110 , V_86 , V_29 ) ;
V_81 = V_29 ;
goto V_653;
} else if ( V_29 > 0 ) {
F_483 ( V_110 , V_86 ,
V_35 -> V_273 . V_22 ) ;
}
}
if ( F_229 ( V_654 , & V_35 -> V_283 ) ) {
F_484 ( V_110 , V_35 ) ;
} else {
F_445 ( V_35 -> V_128 ) ;
F_445 ( V_35 -> V_655 ) ;
F_485 ( V_35 ) ;
}
V_649 = true ;
V_653:
F_479 ( V_110 , V_86 ) ;
V_123:
F_9 ( V_617 ) ;
F_50 ( V_64 ) ;
V_72:
if ( ! V_647 && V_649 == false )
F_486 ( V_35 ) ;
if ( V_81 && V_81 != - V_178 )
F_487 ( V_35 -> V_37 , V_81 ) ;
return V_81 ;
}
int F_488 ( struct V_109 * V_110 ,
struct V_34 * V_35 ,
struct V_65 * V_128 ,
struct V_65 * V_17 )
{
struct V_63 * V_64 ;
struct V_616 * V_617 ;
int V_167 ;
int V_656 ;
int V_29 = 0 ;
int V_657 ;
F_30 ( V_35 -> V_273 . V_22 != V_613 ) ;
V_64 = F_33 () ;
if ( ! V_64 )
return - V_71 ;
V_617 = F_53 ( sizeof( * V_617 ) , V_40 ) ;
if ( ! V_617 ) {
F_50 ( V_64 ) ;
return - V_71 ;
}
F_489 ( V_17 ) ;
V_656 = F_228 ( V_17 ) ;
F_457 ( V_17 ) ;
V_64 -> V_82 [ V_656 ] = V_17 ;
V_64 -> V_83 [ V_656 ] = F_38 ( V_17 ) ;
F_489 ( V_128 ) ;
V_167 = F_228 ( V_128 ) ;
V_64 -> V_82 [ V_167 ] = V_128 ;
V_64 -> V_83 [ V_167 ] = 0 ;
V_64 -> V_629 [ V_167 ] = V_643 ;
V_617 -> V_112 [ V_656 ] = 1 ;
V_617 -> V_7 [ V_656 ] = V_126 ;
V_617 -> V_167 = V_167 ;
V_617 -> V_642 = - 1 ;
V_617 -> V_622 = V_624 ;
V_617 -> V_625 = 0 ;
V_617 -> V_174 = 1 ;
V_617 -> V_647 = 1 ;
V_617 -> V_621 = F_447 ( V_35 ) ;
while ( 1 ) {
V_657 = F_468 ( V_110 , V_35 , V_64 , V_617 ) ;
if ( V_657 < 0 ) {
V_29 = V_657 ;
break;
}
V_657 = F_469 ( V_110 , V_35 , V_64 , V_617 , V_656 ) ;
if ( V_657 < 0 )
V_29 = V_657 ;
if ( V_657 != 0 )
break;
}
F_9 ( V_617 ) ;
F_50 ( V_64 ) ;
return V_29 ;
}
static T_2 F_490 ( struct V_34 * V_35 , T_2 V_7 )
{
T_2 V_364 ;
T_2 V_658 ;
V_658 = F_277 ( V_35 -> V_37 , V_7 ) ;
if ( V_658 )
return F_279 ( V_658 ) ;
V_364 = V_35 -> V_37 -> V_365 -> V_366 ;
V_658 = V_368 |
V_369 | V_370 |
V_328 | V_329 ;
if ( V_364 == 1 ) {
V_658 |= V_327 ;
V_658 = V_7 & ~ V_658 ;
if ( V_7 & V_368 )
return V_658 ;
if ( V_7 & ( V_328 |
V_329 ) )
return V_658 | V_327 ;
} else {
if ( V_7 & V_658 )
return V_7 ;
V_658 |= V_327 ;
V_658 = V_7 & ~ V_658 ;
if ( V_7 & V_327 )
return V_658 | V_328 ;
}
return V_7 ;
}
static int F_491 ( struct V_1 * V_2 , int V_389 )
{
struct V_102 * V_388 = V_2 -> V_105 ;
T_2 V_36 ;
T_2 V_659 ;
int V_29 = - V_382 ;
if ( ( V_388 -> V_7 &
( V_323 | V_321 ) ) &&
! V_389 )
V_659 = 1 * 1024 * 1024 ;
else
V_659 = 0 ;
F_11 ( & V_388 -> V_52 ) ;
F_11 ( & V_2 -> V_52 ) ;
if ( V_2 -> V_296 ) {
V_2 -> V_296 ++ ;
V_29 = 0 ;
goto V_72;
}
V_36 = V_2 -> V_21 . V_33 - V_2 -> V_10 - V_2 -> V_9 -
V_2 -> V_46 - F_373 ( & V_2 -> V_135 ) ;
if ( V_388 -> V_325 + V_388 -> V_338 + V_388 -> V_337 +
V_388 -> V_340 + V_388 -> V_339 + V_36 +
V_659 <= V_388 -> V_324 ) {
V_388 -> V_339 += V_36 ;
V_2 -> V_296 ++ ;
F_64 ( & V_2 -> V_660 , & V_388 -> V_345 ) ;
V_29 = 0 ;
}
V_72:
F_13 ( & V_2 -> V_52 ) ;
F_13 ( & V_388 -> V_52 ) ;
return V_29 ;
}
int F_492 ( struct V_34 * V_35 ,
struct V_1 * V_2 )
{
struct V_109 * V_110 ;
T_2 V_661 ;
int V_29 ;
V_77:
V_110 = F_202 ( V_35 ) ;
if ( F_203 ( V_110 ) )
return F_204 ( V_110 ) ;
F_35 ( & V_35 -> V_37 -> V_662 ) ;
if ( V_110 -> V_127 -> V_663 ) {
T_2 V_298 = V_110 -> V_298 ;
F_46 ( & V_35 -> V_37 -> V_662 ) ;
F_206 ( V_110 , V_35 ) ;
V_29 = F_493 ( V_35 , V_298 ) ;
if ( V_29 )
return V_29 ;
goto V_77;
}
V_661 = F_490 ( V_35 , V_2 -> V_7 ) ;
if ( V_661 != V_2 -> V_7 ) {
V_29 = F_285 ( V_110 , V_35 , V_661 ,
V_381 ) ;
if ( V_29 == - V_382 )
V_29 = 0 ;
if ( V_29 < 0 )
goto V_72;
}
V_29 = F_491 ( V_2 , 0 ) ;
if ( ! V_29 )
goto V_72;
V_661 = F_280 ( V_35 , V_2 -> V_105 -> V_7 ) ;
V_29 = F_285 ( V_110 , V_35 , V_661 ,
V_381 ) ;
if ( V_29 < 0 )
goto V_72;
V_29 = F_491 ( V_2 , 0 ) ;
V_72:
if ( V_2 -> V_7 & V_323 ) {
V_661 = F_490 ( V_35 , V_2 -> V_7 ) ;
F_494 ( V_35 -> V_37 -> V_372 ) ;
F_298 ( V_110 , V_35 , V_661 ) ;
F_495 ( V_35 -> V_37 -> V_372 ) ;
}
F_46 ( & V_35 -> V_37 -> V_662 ) ;
F_206 ( V_110 , V_35 ) ;
return V_29 ;
}
int F_496 ( struct V_109 * V_110 ,
struct V_34 * V_35 , T_2 type )
{
T_2 V_661 = F_280 ( V_35 , type ) ;
return F_285 ( V_110 , V_35 , V_661 ,
V_381 ) ;
}
T_2 F_497 ( struct V_102 * V_388 )
{
struct V_1 * V_14 ;
T_2 V_664 = 0 ;
int V_326 ;
if ( F_172 ( & V_388 -> V_345 ) )
return 0 ;
F_11 ( & V_388 -> V_52 ) ;
F_173 (block_group, &sinfo->ro_bgs, ro_list) {
F_11 ( & V_14 -> V_52 ) ;
if ( ! V_14 -> V_296 ) {
F_13 ( & V_14 -> V_52 ) ;
continue;
}
if ( V_14 -> V_7 & ( V_328 |
V_329 |
V_327 ) )
V_326 = 2 ;
else
V_326 = 1 ;
V_664 += ( V_14 -> V_21 . V_33 -
F_373 ( & V_14 -> V_135 ) ) *
V_326 ;
F_13 ( & V_14 -> V_52 ) ;
}
F_13 ( & V_388 -> V_52 ) ;
return V_664 ;
}
void F_498 ( struct V_34 * V_35 ,
struct V_1 * V_2 )
{
struct V_102 * V_388 = V_2 -> V_105 ;
T_2 V_36 ;
F_30 ( ! V_2 -> V_296 ) ;
F_11 ( & V_388 -> V_52 ) ;
F_11 ( & V_2 -> V_52 ) ;
if ( ! -- V_2 -> V_296 ) {
V_36 = V_2 -> V_21 . V_33 - V_2 -> V_10 -
V_2 -> V_9 - V_2 -> V_46 -
F_373 ( & V_2 -> V_135 ) ;
V_388 -> V_339 -= V_36 ;
F_261 ( & V_2 -> V_660 ) ;
}
F_13 ( & V_2 -> V_52 ) ;
F_13 ( & V_388 -> V_52 ) ;
}
int F_499 ( struct V_34 * V_35 , T_2 V_27 )
{
struct V_1 * V_14 ;
struct V_102 * V_105 ;
struct V_665 * V_365 = V_35 -> V_37 -> V_365 ;
struct V_666 * V_667 ;
struct V_109 * V_110 ;
T_2 V_668 ;
T_2 V_669 = 1 ;
T_2 V_670 = 0 ;
T_2 V_359 ;
int V_561 ;
int V_108 = 0 ;
int V_29 = 0 ;
V_14 = F_68 ( V_35 -> V_37 , V_27 ) ;
if ( ! V_14 )
return - 1 ;
V_668 = F_373 ( & V_14 -> V_135 ) ;
if ( ! V_668 )
goto V_72;
V_105 = V_14 -> V_105 ;
F_11 ( & V_105 -> V_52 ) ;
V_108 = V_105 -> V_108 ;
if ( ( V_105 -> V_324 != V_14 -> V_21 . V_33 ) &&
( V_105 -> V_325 + V_105 -> V_338 +
V_105 -> V_337 + V_105 -> V_339 +
V_668 < V_105 -> V_324 ) ) {
F_13 ( & V_105 -> V_52 ) ;
goto V_72;
}
F_13 ( & V_105 -> V_52 ) ;
V_29 = - 1 ;
V_359 = F_277 ( V_35 -> V_37 , V_14 -> V_7 ) ;
if ( V_359 ) {
V_561 = F_403 ( F_279 ( V_359 ) ) ;
} else {
if ( V_108 )
goto V_72;
V_561 = F_404 ( V_14 ) ;
}
if ( V_561 == V_539 ) {
V_669 = 4 ;
V_668 >>= 1 ;
} else if ( V_561 == V_540 ) {
V_669 = 2 ;
} else if ( V_561 == V_541 ) {
V_668 <<= 1 ;
} else if ( V_561 == V_542 ) {
V_669 = V_365 -> V_366 ;
V_668 = F_195 ( V_668 , V_669 ) ;
}
V_110 = F_202 ( V_35 ) ;
if ( F_203 ( V_110 ) ) {
V_29 = F_204 ( V_110 ) ;
goto V_72;
}
F_35 ( & V_35 -> V_37 -> V_396 ) ;
F_173 (device, &fs_devices->alloc_list, dev_alloc_list) {
T_2 V_671 ;
if ( V_667 -> V_324 > V_667 -> V_325 + V_668 &&
! V_667 -> V_672 ) {
V_29 = F_500 ( V_110 , V_667 , V_668 ,
& V_671 , NULL ) ;
if ( ! V_29 )
V_670 ++ ;
if ( V_670 >= V_669 )
break;
V_29 = - 1 ;
}
}
F_46 ( & V_35 -> V_37 -> V_396 ) ;
F_206 ( V_110 , V_35 ) ;
V_72:
F_6 ( V_14 ) ;
return V_29 ;
}
static int F_501 ( struct V_34 * V_35 ,
struct V_63 * V_64 , struct V_67 * V_21 )
{
int V_29 = 0 ;
struct V_67 V_140 ;
struct V_65 * V_66 ;
int V_618 ;
V_29 = F_37 ( NULL , V_35 , V_21 , V_64 , 0 , 0 ) ;
if ( V_29 < 0 )
goto V_72;
while ( 1 ) {
V_618 = V_64 -> V_83 [ 0 ] ;
V_66 = V_64 -> V_82 [ 0 ] ;
if ( V_618 >= F_38 ( V_66 ) ) {
V_29 = F_48 ( V_35 , V_64 ) ;
if ( V_29 == 0 )
continue;
if ( V_29 < 0 )
goto V_72;
break;
}
F_40 ( V_66 , & V_140 , V_618 ) ;
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
void F_502 ( struct V_12 * V_13 )
{
struct V_1 * V_14 ;
T_2 V_69 = 0 ;
while ( 1 ) {
struct V_288 * V_288 ;
V_14 = F_67 ( V_13 , V_69 ) ;
while ( V_14 ) {
F_11 ( & V_14 -> V_52 ) ;
if ( V_14 -> V_164 )
break;
F_13 ( & V_14 -> V_52 ) ;
V_14 = F_240 ( V_13 -> V_86 ,
V_14 ) ;
}
if ( ! V_14 ) {
if ( V_69 == 0 )
break;
V_69 = 0 ;
continue;
}
V_288 = V_14 -> V_288 ;
V_14 -> V_164 = 0 ;
V_14 -> V_288 = NULL ;
F_13 ( & V_14 -> V_52 ) ;
F_254 ( V_288 ) ;
V_69 = V_14 -> V_21 . V_22 + V_14 -> V_21 . V_33 ;
F_6 ( V_14 ) ;
}
}
int F_503 ( struct V_12 * V_13 )
{
struct V_1 * V_14 ;
struct V_102 * V_105 ;
struct V_50 * V_53 ;
struct V_15 * V_30 ;
F_63 ( & V_13 -> V_79 ) ;
while ( ! F_172 ( & V_13 -> V_100 ) ) {
V_53 = F_174 ( V_13 -> V_100 . V_80 ,
struct V_50 , V_90 ) ;
F_184 ( & V_53 -> V_90 ) ;
F_26 ( V_53 ) ;
}
F_65 ( & V_13 -> V_79 ) ;
F_11 ( & V_13 -> V_505 ) ;
while ( ! F_172 ( & V_13 -> V_507 ) ) {
V_14 = F_260 ( & V_13 -> V_507 ,
struct V_1 ,
V_506 ) ;
F_261 ( & V_14 -> V_506 ) ;
F_6 ( V_14 ) ;
}
F_13 ( & V_13 -> V_505 ) ;
F_11 ( & V_13 -> V_18 ) ;
while ( ( V_30 = F_190 ( & V_13 -> V_19 ) ) != NULL ) {
V_14 = F_12 ( V_30 , struct V_1 ,
V_20 ) ;
F_183 ( & V_14 -> V_20 ,
& V_13 -> V_19 ) ;
F_504 ( & V_14 -> V_20 ) ;
F_13 ( & V_13 -> V_18 ) ;
F_63 ( & V_14 -> V_105 -> V_336 ) ;
F_184 ( & V_14 -> V_90 ) ;
F_65 ( & V_14 -> V_105 -> V_336 ) ;
if ( V_14 -> V_3 == V_98 )
F_402 ( V_14 ) ;
if ( V_14 -> V_3 == V_94 ||
V_14 -> V_3 == V_5 )
F_19 ( V_13 -> V_62 , V_14 ) ;
F_505 ( V_14 ) ;
F_6 ( V_14 ) ;
F_11 ( & V_13 -> V_18 ) ;
}
F_13 ( & V_13 -> V_18 ) ;
F_506 () ;
F_351 ( V_13 ) ;
while ( ! F_172 ( & V_13 -> V_105 ) ) {
int V_43 ;
V_105 = F_174 ( V_13 -> V_105 . V_80 ,
struct V_102 ,
V_90 ) ;
if ( F_250 ( V_13 -> V_86 , V_397 ) ) {
if ( F_8 ( V_105 -> V_337 > 0 ||
V_105 -> V_338 > 0 ||
V_105 -> V_340 > 0 ) ) {
F_302 ( V_105 , 0 , 0 ) ;
}
}
F_184 ( & V_105 -> V_90 ) ;
for ( V_43 = 0 ; V_43 < V_334 ; V_43 ++ ) {
struct V_673 * V_346 ;
V_346 = V_105 -> V_674 [ V_43 ] ;
V_105 -> V_674 [ V_43 ] = NULL ;
if ( V_346 ) {
F_507 ( V_346 ) ;
F_508 ( V_346 ) ;
}
}
F_507 ( & V_105 -> V_346 ) ;
F_508 ( & V_105 -> V_346 ) ;
}
return 0 ;
}
static void F_509 ( struct V_102 * V_105 ,
struct V_1 * V_2 )
{
int V_561 = F_404 ( V_2 ) ;
bool V_245 = false ;
F_63 ( & V_105 -> V_336 ) ;
if ( F_172 ( & V_105 -> V_335 [ V_561 ] ) )
V_245 = true ;
F_64 ( & V_2 -> V_90 , & V_105 -> V_335 [ V_561 ] ) ;
F_65 ( & V_105 -> V_336 ) ;
if ( V_245 ) {
struct V_675 * V_676 ;
int V_29 ;
V_676 = F_53 ( sizeof( * V_676 ) , V_40 ) ;
if ( ! V_676 )
goto V_677;
V_676 -> V_678 = V_561 ;
F_510 ( & V_676 -> V_346 , & V_679 ) ;
V_29 = F_511 ( & V_676 -> V_346 , & V_105 -> V_346 ,
L_8 , F_405 ( V_561 ) ) ;
if ( V_29 ) {
F_508 ( & V_676 -> V_346 ) ;
goto V_677;
}
V_105 -> V_674 [ V_561 ] = & V_676 -> V_346 ;
}
return;
V_677:
F_512 ( L_41 ) ;
}
static struct V_1 *
F_513 ( struct V_34 * V_35 , T_2 V_32 , T_2 V_56 )
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
V_2 -> V_253 = V_35 -> V_253 ;
V_2 -> V_37 = V_35 -> V_37 ;
V_2 -> V_680 = F_514 ( V_35 ,
& V_35 -> V_37 -> V_48 ,
V_32 ) ;
F_57 ( & V_2 -> V_8 , 1 ) ;
F_270 ( & V_2 -> V_52 ) ;
F_269 ( & V_2 -> V_548 ) ;
F_54 ( & V_2 -> V_90 ) ;
F_54 ( & V_2 -> V_681 ) ;
F_54 ( & V_2 -> V_506 ) ;
F_54 ( & V_2 -> V_660 ) ;
F_54 ( & V_2 -> V_317 ) ;
F_54 ( & V_2 -> V_318 ) ;
F_515 ( V_2 ) ;
F_57 ( & V_2 -> V_682 , 0 ) ;
return V_2 ;
}
int F_516 ( struct V_34 * V_35 )
{
struct V_63 * V_64 ;
int V_29 ;
struct V_1 * V_2 ;
struct V_12 * V_13 = V_35 -> V_37 ;
struct V_102 * V_105 ;
struct V_67 V_21 ;
struct V_67 V_140 ;
struct V_65 * V_66 ;
int V_683 = 0 ;
T_2 V_684 ;
V_35 = V_13 -> V_62 ;
V_21 . V_22 = 0 ;
V_21 . V_33 = 0 ;
V_21 . type = V_179 ;
V_64 = F_33 () ;
if ( ! V_64 )
return - V_71 ;
V_64 -> V_75 = 1 ;
V_684 = F_517 ( V_35 -> V_37 -> V_252 ) ;
if ( F_250 ( V_35 , V_302 ) &&
F_518 ( V_35 -> V_37 -> V_252 ) != V_684 )
V_683 = 1 ;
if ( F_250 ( V_35 , V_685 ) )
V_683 = 1 ;
while ( 1 ) {
V_29 = F_501 ( V_35 , V_64 , & V_21 ) ;
if ( V_29 > 0 )
break;
if ( V_29 != 0 )
goto error;
V_66 = V_64 -> V_82 [ 0 ] ;
F_40 ( V_66 , & V_140 , V_64 -> V_83 [ 0 ] ) ;
V_2 = F_513 ( V_35 , V_140 . V_22 ,
V_140 . V_33 ) ;
if ( ! V_2 ) {
V_29 = - V_71 ;
goto error;
}
if ( V_683 ) {
if ( F_250 ( V_35 , V_302 ) )
V_2 -> V_294 = V_308 ;
}
F_519 ( V_66 , & V_2 -> V_135 ,
F_238 ( V_66 , V_64 -> V_83 [ 0 ] ) ,
sizeof( V_2 -> V_135 ) ) ;
V_2 -> V_7 = F_520 ( & V_2 -> V_135 ) ;
V_21 . V_22 = V_140 . V_22 + V_140 . V_33 ;
F_44 ( V_64 ) ;
V_29 = F_21 ( V_35 , V_2 ) ;
if ( V_29 ) {
F_19 ( V_35 , V_2 ) ;
F_6 ( V_2 ) ;
goto error;
}
if ( V_140 . V_33 == F_373 ( & V_2 -> V_135 ) ) {
V_2 -> V_97 = ( T_2 ) - 1 ;
V_2 -> V_3 = V_4 ;
F_19 ( V_35 , V_2 ) ;
} else if ( F_373 ( & V_2 -> V_135 ) == 0 ) {
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
F_505 ( V_2 ) ;
F_6 ( V_2 ) ;
goto error;
}
V_29 = F_267 ( V_13 , V_2 -> V_7 , V_140 . V_33 ,
F_373 ( & V_2 -> V_135 ) ,
& V_105 ) ;
if ( V_29 ) {
F_505 ( V_2 ) ;
F_11 ( & V_13 -> V_18 ) ;
F_183 ( & V_2 -> V_20 ,
& V_13 -> V_19 ) ;
F_504 ( & V_2 -> V_20 ) ;
F_13 ( & V_13 -> V_18 ) ;
F_6 ( V_2 ) ;
goto error;
}
V_2 -> V_105 = V_105 ;
F_11 ( & V_2 -> V_105 -> V_52 ) ;
V_2 -> V_105 -> V_339 += V_2 -> V_46 ;
F_13 ( & V_2 -> V_105 -> V_52 ) ;
F_509 ( V_105 , V_2 ) ;
F_273 ( V_35 -> V_37 , V_2 -> V_7 ) ;
if ( F_521 ( V_35 , V_2 -> V_21 . V_22 ) ) {
F_491 ( V_2 , 1 ) ;
} else if ( F_373 ( & V_2 -> V_135 ) == 0 ) {
F_11 ( & V_13 -> V_505 ) ;
if ( F_172 ( & V_2 -> V_506 ) ) {
F_4 ( V_2 ) ;
F_64 ( & V_2 -> V_506 ,
& V_13 -> V_507 ) ;
}
F_13 ( & V_13 -> V_505 ) ;
}
}
F_71 (space_info, &root->fs_info->space_info, list) {
if ( ! ( F_280 ( V_35 , V_105 -> V_7 ) &
( V_329 |
V_328 |
V_369 |
V_370 |
V_327 ) ) )
continue;
F_173 (cache,
&space_info->block_groups[BTRFS_RAID_RAID0],
list)
F_491 ( V_2 , 1 ) ;
F_173 (cache,
&space_info->block_groups[BTRFS_RAID_SINGLE],
list)
F_491 ( V_2 , 1 ) ;
}
F_350 ( V_13 ) ;
V_29 = 0 ;
error:
F_50 ( V_64 ) ;
return V_29 ;
}
void F_213 ( struct V_109 * V_110 ,
struct V_34 * V_35 )
{
struct V_1 * V_14 , * V_304 ;
struct V_34 * V_62 = V_35 -> V_37 -> V_62 ;
struct V_686 V_135 ;
struct V_67 V_21 ;
int V_29 = 0 ;
bool V_269 = V_110 -> V_269 ;
V_110 -> V_269 = false ;
F_256 (block_group, tmp, &trans->new_bgs, bg_list) {
if ( V_29 )
goto V_80;
F_11 ( & V_14 -> V_52 ) ;
memcpy ( & V_135 , & V_14 -> V_135 , sizeof( V_135 ) ) ;
memcpy ( & V_21 , & V_14 -> V_21 , sizeof( V_21 ) ) ;
F_13 ( & V_14 -> V_52 ) ;
V_29 = F_522 ( V_110 , V_62 , & V_21 , & V_135 ,
sizeof( V_135 ) ) ;
if ( V_29 )
F_153 ( V_110 , V_62 , V_29 ) ;
V_29 = F_523 ( V_110 , V_62 ,
V_21 . V_22 , V_21 . V_33 ) ;
if ( V_29 )
F_153 ( V_110 , V_62 , V_29 ) ;
V_80:
F_261 ( & V_14 -> V_506 ) ;
}
V_110 -> V_269 = V_269 ;
}
int F_524 ( struct V_109 * V_110 ,
struct V_34 * V_35 , T_2 V_325 ,
T_2 type , T_2 V_687 , T_2 V_688 ,
T_2 V_56 )
{
int V_29 ;
struct V_34 * V_62 ;
struct V_1 * V_2 ;
V_62 = V_35 -> V_37 -> V_62 ;
F_525 ( V_35 -> V_37 , V_110 ) ;
V_2 = F_513 ( V_35 , V_688 , V_56 ) ;
if ( ! V_2 )
return - V_71 ;
F_374 ( & V_2 -> V_135 , V_325 ) ;
F_526 ( & V_2 -> V_135 , V_687 ) ;
F_527 ( & V_2 -> V_135 , type ) ;
V_2 -> V_7 = type ;
V_2 -> V_97 = ( T_2 ) - 1 ;
V_2 -> V_3 = V_4 ;
V_29 = F_21 ( V_35 , V_2 ) ;
if ( V_29 ) {
F_19 ( V_35 , V_2 ) ;
F_6 ( V_2 ) ;
return V_29 ;
}
F_27 ( V_2 , V_35 -> V_37 , V_688 ,
V_688 + V_56 ) ;
F_19 ( V_35 , V_2 ) ;
V_29 = F_267 ( V_35 -> V_37 , V_2 -> V_7 , 0 , 0 ,
& V_2 -> V_105 ) ;
if ( V_29 ) {
F_505 ( V_2 ) ;
F_6 ( V_2 ) ;
return V_29 ;
}
V_29 = F_10 ( V_35 -> V_37 , V_2 ) ;
if ( V_29 ) {
F_505 ( V_2 ) ;
F_6 ( V_2 ) ;
return V_29 ;
}
V_29 = F_267 ( V_35 -> V_37 , V_2 -> V_7 , V_56 , V_325 ,
& V_2 -> V_105 ) ;
if ( V_29 ) {
F_505 ( V_2 ) ;
F_11 ( & V_35 -> V_37 -> V_18 ) ;
F_183 ( & V_2 -> V_20 ,
& V_35 -> V_37 -> V_19 ) ;
F_504 ( & V_2 -> V_20 ) ;
F_13 ( & V_35 -> V_37 -> V_18 ) ;
F_6 ( V_2 ) ;
return V_29 ;
}
F_349 ( V_35 -> V_37 ) ;
F_11 ( & V_2 -> V_105 -> V_52 ) ;
V_2 -> V_105 -> V_339 += V_2 -> V_46 ;
F_13 ( & V_2 -> V_105 -> V_52 ) ;
F_509 ( V_2 -> V_105 , V_2 ) ;
F_64 ( & V_2 -> V_506 , & V_110 -> V_271 ) ;
F_273 ( V_62 -> V_37 , type ) ;
return 0 ;
}
static void F_528 ( struct V_12 * V_37 , T_2 V_7 )
{
T_2 V_350 = F_274 ( V_7 ) &
V_351 ;
F_275 ( & V_37 -> V_352 ) ;
if ( V_7 & V_322 )
V_37 -> V_353 &= ~ V_350 ;
if ( V_7 & V_321 )
V_37 -> V_354 &= ~ V_350 ;
if ( V_7 & V_323 )
V_37 -> V_355 &= ~ V_350 ;
F_276 ( & V_37 -> V_352 ) ;
}
int F_529 ( struct V_109 * V_110 ,
struct V_34 * V_35 , T_2 V_689 ,
struct V_690 * V_691 )
{
struct V_63 * V_64 ;
struct V_1 * V_14 ;
struct V_549 * V_550 ;
struct V_34 * V_86 = V_35 -> V_37 -> V_86 ;
struct V_67 V_21 ;
struct V_288 * V_288 ;
struct V_673 * V_346 = NULL ;
int V_29 ;
int V_561 ;
int V_326 ;
struct V_50 * V_53 = NULL ;
bool V_692 ;
V_35 = V_35 -> V_37 -> V_62 ;
V_14 = F_68 ( V_35 -> V_37 , V_689 ) ;
F_30 ( ! V_14 ) ;
F_30 ( ! V_14 -> V_296 ) ;
F_19 ( V_35 , V_14 ) ;
memcpy ( & V_21 , & V_14 -> V_21 , sizeof( V_21 ) ) ;
V_561 = F_404 ( V_14 ) ;
if ( V_14 -> V_7 & ( V_327 |
V_328 |
V_329 ) )
V_326 = 2 ;
else
V_326 = 1 ;
V_550 = & V_35 -> V_37 -> V_570 ;
F_11 ( & V_550 -> V_553 ) ;
F_415 ( V_14 , V_550 ) ;
F_13 ( & V_550 -> V_553 ) ;
V_550 = & V_35 -> V_37 -> V_568 ;
F_11 ( & V_550 -> V_553 ) ;
F_415 ( V_14 , V_550 ) ;
F_13 ( & V_550 -> V_553 ) ;
V_64 = F_33 () ;
if ( ! V_64 ) {
V_29 = - V_71 ;
goto V_72;
}
V_288 = F_243 ( V_86 , V_14 , V_64 ) ;
F_35 ( & V_110 -> V_127 -> V_316 ) ;
F_11 ( & V_110 -> V_127 -> V_315 ) ;
if ( ! F_172 ( & V_14 -> V_318 ) ) {
F_261 ( & V_14 -> V_318 ) ;
F_8 ( ! F_203 ( V_288 ) && V_288 != V_14 -> V_319 . V_288 ) ;
F_13 ( & V_110 -> V_127 -> V_315 ) ;
F_262 ( V_35 , V_110 , V_14 ,
& V_14 -> V_319 , V_64 ,
V_14 -> V_21 . V_22 ) ;
F_6 ( V_14 ) ;
F_11 ( & V_110 -> V_127 -> V_315 ) ;
}
if ( ! F_172 ( & V_14 -> V_317 ) ) {
F_261 ( & V_14 -> V_317 ) ;
F_6 ( V_14 ) ;
}
F_13 ( & V_110 -> V_127 -> V_315 ) ;
F_46 ( & V_110 -> V_127 -> V_316 ) ;
if ( ! F_203 ( V_288 ) ) {
V_29 = F_530 ( V_110 , V_288 ) ;
if ( V_29 ) {
F_531 ( V_288 ) ;
goto V_72;
}
F_532 ( V_288 ) ;
F_11 ( & V_14 -> V_52 ) ;
if ( V_14 -> V_164 ) {
V_14 -> V_164 = 0 ;
V_14 -> V_288 = NULL ;
F_13 ( & V_14 -> V_52 ) ;
F_254 ( V_288 ) ;
} else {
F_13 ( & V_14 -> V_52 ) ;
}
F_531 ( V_288 ) ;
}
V_21 . V_22 = V_693 ;
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
F_183 ( & V_14 -> V_20 ,
& V_35 -> V_37 -> V_19 ) ;
F_504 ( & V_14 -> V_20 ) ;
if ( V_35 -> V_37 -> V_26 == V_14 -> V_21 . V_22 )
V_35 -> V_37 -> V_26 = ( T_2 ) - 1 ;
F_13 ( & V_35 -> V_37 -> V_18 ) ;
F_63 ( & V_14 -> V_105 -> V_336 ) ;
F_261 ( & V_14 -> V_90 ) ;
if ( F_172 ( & V_14 -> V_105 -> V_335 [ V_561 ] ) ) {
V_346 = V_14 -> V_105 -> V_674 [ V_561 ] ;
V_14 -> V_105 -> V_674 [ V_561 ] = NULL ;
F_528 ( V_35 -> V_37 , V_14 -> V_7 ) ;
}
F_65 ( & V_14 -> V_105 -> V_336 ) ;
if ( V_346 ) {
F_507 ( V_346 ) ;
F_508 ( V_346 ) ;
}
if ( V_14 -> V_99 )
V_53 = F_25 ( V_14 ) ;
if ( V_14 -> V_3 == V_98 )
F_402 ( V_14 ) ;
if ( V_14 -> V_99 ) {
F_63 ( & V_35 -> V_37 -> V_79 ) ;
if ( ! V_53 ) {
struct V_50 * V_51 ;
F_173 (ctl,
&root->fs_info->caching_block_groups, list)
if ( V_51 -> V_14 == V_14 ) {
V_53 = V_51 ;
F_5 ( & V_53 -> V_8 ) ;
break;
}
}
if ( V_53 )
F_261 ( & V_53 -> V_90 ) ;
F_65 ( & V_35 -> V_37 -> V_79 ) ;
if ( V_53 ) {
F_26 ( V_53 ) ;
F_26 ( V_53 ) ;
}
}
F_11 ( & V_110 -> V_127 -> V_315 ) ;
if ( ! F_172 ( & V_14 -> V_317 ) ) {
F_8 ( 1 ) ;
}
if ( ! F_172 ( & V_14 -> V_318 ) ) {
F_8 ( 1 ) ;
}
F_13 ( & V_110 -> V_127 -> V_315 ) ;
F_505 ( V_14 ) ;
F_11 ( & V_14 -> V_105 -> V_52 ) ;
F_261 ( & V_14 -> V_660 ) ;
if ( F_250 ( V_35 , V_397 ) ) {
F_8 ( V_14 -> V_105 -> V_324
< V_14 -> V_21 . V_33 ) ;
F_8 ( V_14 -> V_105 -> V_339
< V_14 -> V_21 . V_33 ) ;
F_8 ( V_14 -> V_105 -> V_330
< V_14 -> V_21 . V_33 * V_326 ) ;
}
V_14 -> V_105 -> V_324 -= V_14 -> V_21 . V_33 ;
V_14 -> V_105 -> V_339 -= V_14 -> V_21 . V_33 ;
V_14 -> V_105 -> V_330 -= V_14 -> V_21 . V_33 * V_326 ;
F_13 ( & V_14 -> V_105 -> V_52 ) ;
memcpy ( & V_21 , & V_14 -> V_21 , sizeof( V_21 ) ) ;
F_494 ( V_35 ) ;
if ( ! F_172 ( & V_691 -> V_90 ) ) {
F_533 ( V_691 ) ;
}
F_11 ( & V_14 -> V_52 ) ;
V_14 -> V_694 = 1 ;
V_692 = ( F_200 ( & V_14 -> V_682 ) == 0 ) ;
if ( ! V_692 ) {
F_534 ( & V_691 -> V_90 , & V_35 -> V_37 -> V_695 ) ;
}
F_13 ( & V_14 -> V_52 ) ;
if ( V_692 ) {
struct V_696 * V_697 ;
V_697 = & V_35 -> V_37 -> V_48 . V_698 ;
F_535 ( & V_697 -> V_52 ) ;
F_536 ( V_697 , V_691 ) ;
F_537 ( & V_697 -> V_52 ) ;
F_533 ( V_691 ) ;
}
F_495 ( V_35 ) ;
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
void F_538 ( struct V_12 * V_37 )
{
struct V_1 * V_14 ;
struct V_102 * V_105 ;
struct V_34 * V_35 = V_37 -> V_62 ;
struct V_109 * V_110 ;
int V_29 = 0 ;
if ( ! V_37 -> V_699 )
return;
F_11 ( & V_37 -> V_505 ) ;
while ( ! F_172 ( & V_37 -> V_507 ) ) {
T_2 V_32 , V_31 ;
int V_682 ;
V_14 = F_260 ( & V_37 -> V_507 ,
struct V_1 ,
V_506 ) ;
V_105 = V_14 -> V_105 ;
F_261 ( & V_14 -> V_506 ) ;
if ( V_29 || F_305 ( V_105 ) ) {
F_6 ( V_14 ) ;
continue;
}
F_13 ( & V_37 -> V_505 ) ;
F_35 ( & V_35 -> V_37 -> V_700 ) ;
F_63 ( & V_105 -> V_336 ) ;
F_11 ( & V_14 -> V_52 ) ;
if ( V_14 -> V_10 ||
F_373 ( & V_14 -> V_135 ) ||
V_14 -> V_296 ) {
F_13 ( & V_14 -> V_52 ) ;
F_65 ( & V_105 -> V_336 ) ;
goto V_80;
}
F_13 ( & V_14 -> V_52 ) ;
V_29 = F_491 ( V_14 , 0 ) ;
F_65 ( & V_105 -> V_336 ) ;
if ( V_29 < 0 ) {
V_29 = 0 ;
goto V_80;
}
V_110 = F_471 ( V_35 , 1 ) ;
if ( F_203 ( V_110 ) ) {
F_498 ( V_35 , V_14 ) ;
V_29 = F_204 ( V_110 ) ;
goto V_80;
}
V_32 = V_14 -> V_21 . V_22 ;
V_31 = V_32 + V_14 -> V_21 . V_33 - 1 ;
F_35 ( & V_37 -> V_521 ) ;
V_29 = F_20 ( & V_37 -> V_38 [ 0 ] , V_32 , V_31 ,
V_59 , V_40 ) ;
if ( V_29 ) {
F_46 ( & V_37 -> V_521 ) ;
F_498 ( V_35 , V_14 ) ;
goto V_701;
}
V_29 = F_20 ( & V_37 -> V_38 [ 1 ] , V_32 , V_31 ,
V_59 , V_40 ) ;
if ( V_29 ) {
F_46 ( & V_37 -> V_521 ) ;
F_498 ( V_35 , V_14 ) ;
goto V_701;
}
F_46 ( & V_37 -> V_521 ) ;
F_11 ( & V_105 -> V_52 ) ;
F_11 ( & V_14 -> V_52 ) ;
V_105 -> V_337 -= V_14 -> V_9 ;
V_105 -> V_339 += V_14 -> V_9 ;
F_385 ( & V_105 -> V_332 ,
- V_14 -> V_9 ) ;
V_14 -> V_9 = 0 ;
F_13 ( & V_14 -> V_52 ) ;
F_13 ( & V_105 -> V_52 ) ;
V_682 = F_250 ( V_35 , V_522 ) ;
if ( V_682 )
F_539 ( V_14 ) ;
V_29 = F_540 ( V_110 , V_35 ,
V_14 -> V_21 . V_22 ) ;
if ( V_29 ) {
if ( V_682 )
F_388 ( V_14 ) ;
goto V_701;
}
if ( V_682 ) {
F_8 ( ! F_172 ( & V_14 -> V_506 ) ) ;
F_11 ( & V_110 -> V_127 -> V_702 ) ;
F_541 ( & V_14 -> V_506 ,
& V_110 -> V_127 -> V_518 ) ;
F_13 ( & V_110 -> V_127 -> V_702 ) ;
F_4 ( V_14 ) ;
}
V_701:
F_206 ( V_110 , V_35 ) ;
V_80:
F_46 ( & V_35 -> V_37 -> V_700 ) ;
F_6 ( V_14 ) ;
F_11 ( & V_37 -> V_505 ) ;
}
F_13 ( & V_37 -> V_505 ) ;
}
int F_542 ( struct V_12 * V_37 )
{
struct V_102 * V_105 ;
struct V_703 * V_704 ;
T_2 V_705 ;
T_2 V_7 ;
int V_706 = 0 ;
int V_29 ;
V_704 = V_37 -> V_252 ;
if ( ! F_543 ( V_704 ) )
return 1 ;
V_705 = F_544 ( V_704 ) ;
if ( V_705 & V_707 )
V_706 = 1 ;
V_7 = V_323 ;
V_29 = F_267 ( V_37 , V_7 , 0 , 0 , & V_105 ) ;
if ( V_29 )
goto V_72;
if ( V_706 ) {
V_7 = V_321 | V_322 ;
V_29 = F_267 ( V_37 , V_7 , 0 , 0 , & V_105 ) ;
} else {
V_7 = V_321 ;
V_29 = F_267 ( V_37 , V_7 , 0 , 0 , & V_105 ) ;
if ( V_29 )
goto V_72;
V_7 = V_322 ;
V_29 = F_267 ( V_37 , V_7 , 0 , 0 , & V_105 ) ;
}
V_72:
return V_29 ;
}
int F_545 ( struct V_34 * V_35 , T_2 V_32 , T_2 V_31 )
{
return F_384 ( V_35 , V_32 , V_31 , false ) ;
}
static int F_546 ( struct V_666 * V_667 ,
T_2 V_708 , T_2 * V_523 )
{
T_2 V_32 = 0 , V_49 = 0 ;
int V_29 ;
* V_523 = 0 ;
if ( ! V_667 -> V_709 )
return 0 ;
if ( V_667 -> V_324 <= V_667 -> V_325 )
return 0 ;
V_29 = 0 ;
while ( 1 ) {
struct V_12 * V_37 = V_667 -> V_475 -> V_37 ;
struct V_305 * V_110 ;
T_2 V_203 ;
V_29 = F_547 ( & V_37 -> V_396 ) ;
if ( V_29 )
return V_29 ;
F_36 ( & V_37 -> V_79 ) ;
F_11 ( & V_37 -> V_710 ) ;
V_110 = V_37 -> V_711 ;
if ( V_110 )
F_5 ( & V_110 -> V_712 ) ;
F_13 ( & V_37 -> V_710 ) ;
V_29 = F_548 ( V_110 , V_667 , V_708 , V_32 ,
& V_32 , & V_49 ) ;
if ( V_110 )
F_549 ( V_110 ) ;
if ( V_29 ) {
F_45 ( & V_37 -> V_79 ) ;
F_46 ( & V_37 -> V_396 ) ;
if ( V_29 == - V_382 )
V_29 = 0 ;
break;
}
V_29 = F_140 ( V_667 -> V_186 , V_32 , V_49 , & V_203 ) ;
F_45 ( & V_37 -> V_79 ) ;
F_46 ( & V_37 -> V_396 ) ;
if ( V_29 )
break;
V_32 += V_49 ;
* V_523 += V_203 ;
if ( F_550 ( V_377 ) ) {
V_29 = - V_713 ;
break;
}
F_47 () ;
}
return V_29 ;
}
int F_551 ( struct V_34 * V_35 , struct V_714 * V_715 )
{
struct V_12 * V_37 = V_35 -> V_37 ;
struct V_1 * V_2 = NULL ;
struct V_666 * V_667 ;
struct V_103 * V_716 ;
T_2 V_717 ;
T_2 V_32 ;
T_2 V_31 ;
T_2 V_523 = 0 ;
T_2 V_324 = F_294 ( V_37 -> V_252 ) ;
int V_29 = 0 ;
if ( V_715 -> V_49 == V_324 )
V_2 = F_67 ( V_37 , V_715 -> V_32 ) ;
else
V_2 = F_68 ( V_37 , V_715 -> V_32 ) ;
while ( V_2 ) {
if ( V_2 -> V_21 . V_22 >= ( V_715 -> V_32 + V_715 -> V_49 ) ) {
F_6 ( V_2 ) ;
break;
}
V_32 = F_412 ( V_715 -> V_32 , V_2 -> V_21 . V_22 ) ;
V_31 = F_315 ( V_715 -> V_32 + V_715 -> V_49 ,
V_2 -> V_21 . V_22 + V_2 -> V_21 . V_33 ) ;
if ( V_31 - V_32 >= V_715 -> V_708 ) {
if ( ! F_1 ( V_2 ) ) {
V_29 = F_51 ( V_2 , 0 ) ;
if ( V_29 ) {
F_6 ( V_2 ) ;
break;
}
V_29 = F_402 ( V_2 ) ;
if ( V_29 ) {
F_6 ( V_2 ) ;
break;
}
}
V_29 = F_552 ( V_2 ,
& V_717 ,
V_32 ,
V_31 ,
V_715 -> V_708 ) ;
V_523 += V_717 ;
if ( V_29 ) {
F_6 ( V_2 ) ;
break;
}
}
V_2 = F_240 ( V_37 -> V_86 , V_2 ) ;
}
F_35 ( & V_35 -> V_37 -> V_365 -> V_718 ) ;
V_716 = & V_35 -> V_37 -> V_365 -> V_719 ;
F_173 (device, devices, dev_alloc_list) {
V_29 = F_546 ( V_667 , V_715 -> V_708 ,
& V_717 ) ;
if ( V_29 )
break;
V_523 += V_717 ;
}
F_46 ( & V_35 -> V_37 -> V_365 -> V_718 ) ;
V_715 -> V_49 = V_523 ;
return V_29 ;
}
void F_553 ( struct V_34 * V_35 )
{
F_554 ( & V_35 -> V_720 -> V_721 ) ;
F_2 () ;
if ( F_555 ( & V_35 -> V_720 -> V_88 ) )
F_49 ( & V_35 -> V_720 -> V_88 ) ;
}
int F_556 ( struct V_34 * V_35 )
{
if ( F_200 ( & V_35 -> V_722 ) )
return 0 ;
F_557 ( & V_35 -> V_720 -> V_721 ) ;
F_2 () ;
if ( F_200 ( & V_35 -> V_722 ) ) {
F_553 ( V_35 ) ;
return 0 ;
}
return 1 ;
}
