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
F_58 ( & V_54 -> V_62 , F_31 , NULL , NULL ) ;
F_11 ( & V_2 -> V_52 ) ;
while ( V_2 -> V_3 == V_92 ) {
struct V_50 * V_51 ;
V_51 = V_2 -> V_54 ;
F_5 ( & V_51 -> V_8 ) ;
F_59 ( & V_51 -> V_89 , & V_89 , V_93 ) ;
F_13 ( & V_2 -> V_52 ) ;
F_60 () ;
F_61 ( & V_51 -> V_89 , & V_89 ) ;
F_26 ( V_51 ) ;
F_11 ( & V_2 -> V_52 ) ;
}
if ( V_2 -> V_3 != V_94 ) {
F_13 ( & V_2 -> V_52 ) ;
F_9 ( V_54 ) ;
return 0 ;
}
F_8 ( V_2 -> V_54 ) ;
V_2 -> V_54 = V_54 ;
V_2 -> V_3 = V_92 ;
F_13 ( & V_2 -> V_52 ) ;
if ( V_37 -> V_95 & V_96 ) {
V_29 = F_62 ( V_37 , V_2 ) ;
F_11 ( & V_2 -> V_52 ) ;
if ( V_29 == 1 ) {
V_2 -> V_54 = NULL ;
V_2 -> V_3 = V_4 ;
V_2 -> V_97 = ( T_2 ) - 1 ;
} else {
if ( V_90 ) {
V_2 -> V_54 = NULL ;
V_2 -> V_3 = V_94 ;
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
V_2 -> V_3 = V_94 ;
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
F_64 ( & V_54 -> V_91 , & V_37 -> V_98 ) ;
F_65 ( & V_37 -> V_80 ) ;
F_4 ( V_2 ) ;
F_66 ( V_37 -> V_99 , & V_54 -> V_62 ) ;
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
static struct V_100 * F_69 ( struct V_12 * V_13 ,
T_2 V_7 )
{
struct V_101 * V_102 = & V_13 -> V_103 ;
struct V_100 * V_104 ;
V_7 &= V_105 ;
F_70 () ;
F_71 (found, head, list) {
if ( V_104 -> V_7 & V_7 ) {
F_72 () ;
return V_104 ;
}
}
F_72 () ;
return NULL ;
}
void F_73 ( struct V_12 * V_13 )
{
struct V_101 * V_102 = & V_13 -> V_103 ;
struct V_100 * V_104 ;
F_70 () ;
F_71 (found, head, list)
V_104 -> V_106 = 0 ;
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
int F_75 ( struct V_107 * V_108 ,
struct V_34 * V_35 , T_2 V_27 ,
T_2 V_33 , int V_109 , T_2 * V_110 , T_2 * V_7 )
{
struct V_111 * V_102 ;
struct V_112 * V_113 ;
struct V_64 * V_65 ;
struct V_114 * V_115 ;
struct V_66 * V_67 ;
struct V_68 V_21 ;
T_3 V_116 ;
T_2 V_117 ;
T_2 V_118 ;
int V_29 ;
if ( V_109 && ! F_76 ( V_35 -> V_37 , V_119 ) ) {
V_33 = V_35 -> V_88 ;
V_109 = 0 ;
}
V_65 = F_33 () ;
if ( ! V_65 )
return - V_72 ;
if ( ! V_108 ) {
V_65 -> V_74 = 1 ;
V_65 -> V_75 = 1 ;
}
V_120:
V_21 . V_22 = V_27 ;
V_21 . V_33 = V_33 ;
if ( V_109 )
V_21 . type = V_86 ;
else
V_21 . type = V_77 ;
V_78:
V_29 = F_37 ( V_108 , V_35 -> V_37 -> V_63 ,
& V_21 , V_65 , 0 , 0 ) ;
if ( V_29 < 0 )
goto V_121;
if ( V_29 > 0 && V_109 && V_21 . type == V_86 ) {
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
V_116 = F_77 ( V_67 , V_65 -> V_84 [ 0 ] ) ;
if ( V_116 >= sizeof( * V_115 ) ) {
V_115 = F_78 ( V_67 , V_65 -> V_84 [ 0 ] ,
struct V_114 ) ;
V_117 = F_79 ( V_67 , V_115 ) ;
V_118 = F_80 ( V_67 , V_115 ) ;
} else {
#ifdef F_81
struct V_122 * V_123 ;
F_30 ( V_116 != sizeof( * V_123 ) ) ;
V_123 = F_78 ( V_67 , V_65 -> V_84 [ 0 ] ,
struct V_122 ) ;
V_117 = F_82 ( V_67 , V_123 ) ;
V_118 = V_124 ;
#else
F_83 () ;
#endif
}
F_30 ( V_117 == 0 ) ;
} else {
V_117 = 0 ;
V_118 = 0 ;
V_29 = 0 ;
}
if ( ! V_108 )
goto V_73;
V_113 = & V_108 -> V_125 -> V_113 ;
F_11 ( & V_113 -> V_52 ) ;
V_102 = F_84 ( V_108 , V_27 ) ;
if ( V_102 ) {
if ( ! F_85 ( & V_102 -> V_79 ) ) {
F_5 ( & V_102 -> V_126 . V_110 ) ;
F_13 ( & V_113 -> V_52 ) ;
F_44 ( V_65 ) ;
F_35 ( & V_102 -> V_79 ) ;
F_46 ( & V_102 -> V_79 ) ;
F_86 ( & V_102 -> V_126 ) ;
goto V_120;
}
F_11 ( & V_102 -> V_52 ) ;
if ( V_102 -> V_127 && V_102 -> V_127 -> V_128 )
V_118 |= V_102 -> V_127 -> V_129 ;
else
F_30 ( V_117 == 0 ) ;
V_117 += V_102 -> V_126 . V_130 ;
F_13 ( & V_102 -> V_52 ) ;
F_46 ( & V_102 -> V_79 ) ;
}
F_13 ( & V_113 -> V_52 ) ;
V_73:
F_8 ( V_117 == 0 ) ;
if ( V_110 )
* V_110 = V_117 ;
if ( V_7 )
* V_7 = V_118 ;
V_121:
F_50 ( V_65 ) ;
return V_29 ;
}
static int F_87 ( struct V_107 * V_108 ,
struct V_34 * V_35 ,
struct V_64 * V_65 ,
T_2 V_131 , T_3 V_132 )
{
struct V_114 * V_133 ;
struct V_122 * V_123 ;
struct V_134 * V_135 ;
struct V_136 * V_137 ;
struct V_66 * V_67 ;
struct V_68 V_21 ;
struct V_68 V_138 ;
T_3 V_139 = sizeof( * V_133 ) ;
T_2 V_110 ;
int V_29 ;
V_67 = V_65 -> V_83 [ 0 ] ;
F_30 ( F_77 ( V_67 , V_65 -> V_84 [ 0 ] ) != sizeof( * V_123 ) ) ;
F_40 ( V_67 , & V_21 , V_65 -> V_84 [ 0 ] ) ;
V_123 = F_78 ( V_67 , V_65 -> V_84 [ 0 ] ,
struct V_122 ) ;
V_110 = F_82 ( V_67 , V_123 ) ;
if ( V_131 == ( T_2 ) - 1 ) {
while ( 1 ) {
if ( V_65 -> V_84 [ 0 ] >= F_38 ( V_67 ) ) {
V_29 = F_48 ( V_35 , V_65 ) ;
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
V_135 = F_78 ( V_67 , V_65 -> V_84 [ 0 ] ,
struct V_134 ) ;
V_131 = F_88 ( V_67 , V_135 ) ;
break;
}
}
F_44 ( V_65 ) ;
if ( V_131 < V_141 )
V_139 += sizeof( * V_137 ) ;
V_139 -= sizeof( * V_123 ) ;
V_29 = F_37 ( V_108 , V_35 , & V_21 , V_65 ,
V_139 + V_132 , 1 ) ;
if ( V_29 < 0 )
return V_29 ;
F_30 ( V_29 ) ;
F_89 ( V_35 , V_65 , V_139 ) ;
V_67 = V_65 -> V_83 [ 0 ] ;
V_133 = F_78 ( V_67 , V_65 -> V_84 [ 0 ] , struct V_114 ) ;
F_90 ( V_67 , V_133 , V_110 ) ;
F_91 ( V_67 , V_133 , 0 ) ;
if ( V_131 < V_141 ) {
F_92 ( V_67 , V_133 ,
V_142 |
V_124 ) ;
V_137 = (struct V_136 * ) ( V_133 + 1 ) ;
F_93 ( V_67 , 0 , ( unsigned long ) V_137 , sizeof( * V_137 ) ) ;
F_94 ( V_67 , V_137 , ( int ) V_131 ) ;
} else {
F_92 ( V_67 , V_133 , V_143 ) ;
}
F_95 ( V_67 ) ;
return 0 ;
}
static T_2 F_96 ( T_2 V_144 , T_2 V_131 , T_2 V_33 )
{
T_3 V_145 = ~ ( T_3 ) 0 ;
T_3 V_146 = ~ ( T_3 ) 0 ;
T_4 V_147 ;
V_147 = F_97 ( V_144 ) ;
V_145 = F_98 ( V_145 , & V_147 , sizeof( V_147 ) ) ;
V_147 = F_97 ( V_131 ) ;
V_146 = F_98 ( V_146 , & V_147 , sizeof( V_147 ) ) ;
V_147 = F_97 ( V_33 ) ;
V_146 = F_98 ( V_146 , & V_147 , sizeof( V_147 ) ) ;
return ( ( T_2 ) V_145 << 31 ) ^ ( T_2 ) V_146 ;
}
static T_2 F_99 ( struct V_66 * V_67 ,
struct V_148 * V_149 )
{
return F_96 ( F_100 ( V_67 , V_149 ) ,
F_101 ( V_67 , V_149 ) ,
F_102 ( V_67 , V_149 ) ) ;
}
static int F_103 ( struct V_66 * V_67 ,
struct V_148 * V_149 ,
T_2 V_144 , T_2 V_131 , T_2 V_33 )
{
if ( F_100 ( V_67 , V_149 ) != V_144 ||
F_101 ( V_67 , V_149 ) != V_131 ||
F_102 ( V_67 , V_149 ) != V_33 )
return 0 ;
return 1 ;
}
static T_1 int F_104 ( struct V_107 * V_108 ,
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
V_21 . V_33 = F_96 ( V_144 ,
V_131 , V_33 ) ;
}
V_78:
V_150 = 0 ;
V_29 = F_37 ( V_108 , V_35 , & V_21 , V_65 , - 1 , 1 ) ;
if ( V_29 < 0 ) {
V_82 = V_29 ;
goto V_154;
}
if ( V_17 ) {
if ( ! V_29 )
return 0 ;
#ifdef F_81
V_21 . type = V_140 ;
F_44 ( V_65 ) ;
V_29 = F_37 ( V_108 , V_35 , & V_21 , V_65 , - 1 , 1 ) ;
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
V_29 = F_48 ( V_35 , V_65 ) ;
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
V_149 = F_78 ( V_67 , V_65 -> V_84 [ 0 ] ,
struct V_148 ) ;
if ( F_103 ( V_67 , V_149 , V_144 ,
V_131 , V_33 ) ) {
if ( V_150 ) {
F_44 ( V_65 ) ;
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
static T_1 int F_105 ( struct V_107 * V_108 ,
struct V_34 * V_35 ,
struct V_64 * V_65 ,
T_2 V_27 , T_2 V_17 ,
T_2 V_144 , T_2 V_131 ,
T_2 V_33 , int V_155 )
{
struct V_68 V_21 ;
struct V_66 * V_67 ;
T_3 V_57 ;
T_3 V_117 ;
int V_29 ;
V_21 . V_22 = V_27 ;
if ( V_17 ) {
V_21 . type = V_152 ;
V_21 . V_33 = V_17 ;
V_57 = sizeof( struct V_156 ) ;
} else {
V_21 . type = V_153 ;
V_21 . V_33 = F_96 ( V_144 ,
V_131 , V_33 ) ;
V_57 = sizeof( struct V_148 ) ;
}
V_29 = F_106 ( V_108 , V_35 , V_65 , & V_21 , V_57 ) ;
if ( V_29 && V_29 != - V_25 )
goto V_154;
V_67 = V_65 -> V_83 [ 0 ] ;
if ( V_17 ) {
struct V_156 * V_149 ;
V_149 = F_78 ( V_67 , V_65 -> V_84 [ 0 ] ,
struct V_156 ) ;
if ( V_29 == 0 ) {
F_107 ( V_67 , V_149 , V_155 ) ;
} else {
V_117 = F_108 ( V_67 , V_149 ) ;
V_117 += V_155 ;
F_107 ( V_67 , V_149 , V_117 ) ;
}
} else {
struct V_148 * V_149 ;
while ( V_29 == - V_25 ) {
V_149 = F_78 ( V_67 , V_65 -> V_84 [ 0 ] ,
struct V_148 ) ;
if ( F_103 ( V_67 , V_149 , V_144 ,
V_131 , V_33 ) )
break;
F_44 ( V_65 ) ;
V_21 . V_33 ++ ;
V_29 = F_106 ( V_108 , V_35 , V_65 , & V_21 ,
V_57 ) ;
if ( V_29 && V_29 != - V_25 )
goto V_154;
V_67 = V_65 -> V_83 [ 0 ] ;
}
V_149 = F_78 ( V_67 , V_65 -> V_84 [ 0 ] ,
struct V_148 ) ;
if ( V_29 == 0 ) {
F_109 ( V_67 , V_149 ,
V_144 ) ;
F_110 ( V_67 , V_149 , V_131 ) ;
F_111 ( V_67 , V_149 , V_33 ) ;
F_112 ( V_67 , V_149 , V_155 ) ;
} else {
V_117 = F_113 ( V_67 , V_149 ) ;
V_117 += V_155 ;
F_112 ( V_67 , V_149 , V_117 ) ;
}
}
F_95 ( V_67 ) ;
V_29 = 0 ;
V_154:
F_44 ( V_65 ) ;
return V_29 ;
}
static T_1 int F_114 ( struct V_107 * V_108 ,
struct V_34 * V_35 ,
struct V_64 * V_65 ,
int V_157 )
{
struct V_68 V_21 ;
struct V_148 * V_158 = NULL ;
struct V_156 * V_159 = NULL ;
struct V_66 * V_67 ;
T_3 V_117 = 0 ;
int V_29 = 0 ;
V_67 = V_65 -> V_83 [ 0 ] ;
F_40 ( V_67 , & V_21 , V_65 -> V_84 [ 0 ] ) ;
if ( V_21 . type == V_153 ) {
V_158 = F_78 ( V_67 , V_65 -> V_84 [ 0 ] ,
struct V_148 ) ;
V_117 = F_113 ( V_67 , V_158 ) ;
} else if ( V_21 . type == V_152 ) {
V_159 = F_78 ( V_67 , V_65 -> V_84 [ 0 ] ,
struct V_156 ) ;
V_117 = F_108 ( V_67 , V_159 ) ;
#ifdef F_81
} else if ( V_21 . type == V_140 ) {
struct V_134 * V_135 ;
V_135 = F_78 ( V_67 , V_65 -> V_84 [ 0 ] ,
struct V_134 ) ;
V_117 = F_115 ( V_67 , V_135 ) ;
#endif
} else {
F_83 () ;
}
F_30 ( V_117 < V_157 ) ;
V_117 -= V_157 ;
if ( V_117 == 0 ) {
V_29 = F_116 ( V_108 , V_35 , V_65 ) ;
} else {
if ( V_21 . type == V_153 )
F_112 ( V_67 , V_158 , V_117 ) ;
else if ( V_21 . type == V_152 )
F_107 ( V_67 , V_159 , V_117 ) ;
#ifdef F_81
else {
struct V_134 * V_135 ;
V_135 = F_78 ( V_67 , V_65 -> V_84 [ 0 ] ,
struct V_134 ) ;
F_117 ( V_67 , V_135 , V_117 ) ;
}
#endif
F_95 ( V_67 ) ;
}
return V_29 ;
}
static T_1 T_3 F_118 ( struct V_34 * V_35 ,
struct V_64 * V_65 ,
struct V_160 * V_161 )
{
struct V_68 V_21 ;
struct V_66 * V_67 ;
struct V_148 * V_158 ;
struct V_156 * V_159 ;
T_3 V_117 = 0 ;
V_67 = V_65 -> V_83 [ 0 ] ;
F_40 ( V_67 , & V_21 , V_65 -> V_84 [ 0 ] ) ;
if ( V_161 ) {
if ( F_119 ( V_67 , V_161 ) ==
V_153 ) {
V_158 = (struct V_148 * ) ( & V_161 -> V_33 ) ;
V_117 = F_113 ( V_67 , V_158 ) ;
} else {
V_159 = (struct V_156 * ) ( V_161 + 1 ) ;
V_117 = F_108 ( V_67 , V_159 ) ;
}
} else if ( V_21 . type == V_153 ) {
V_158 = F_78 ( V_67 , V_65 -> V_84 [ 0 ] ,
struct V_148 ) ;
V_117 = F_113 ( V_67 , V_158 ) ;
} else if ( V_21 . type == V_152 ) {
V_159 = F_78 ( V_67 , V_65 -> V_84 [ 0 ] ,
struct V_156 ) ;
V_117 = F_108 ( V_67 , V_159 ) ;
#ifdef F_81
} else if ( V_21 . type == V_140 ) {
struct V_134 * V_135 ;
V_135 = F_78 ( V_67 , V_65 -> V_84 [ 0 ] ,
struct V_134 ) ;
V_117 = F_115 ( V_67 , V_135 ) ;
#endif
} else {
F_8 ( 1 ) ;
}
return V_117 ;
}
static T_1 int F_120 ( struct V_107 * V_108 ,
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
V_29 = F_37 ( V_108 , V_35 , & V_21 , V_65 , - 1 , 1 ) ;
if ( V_29 > 0 )
V_29 = - V_151 ;
#ifdef F_81
if ( V_29 == - V_151 && V_17 ) {
F_44 ( V_65 ) ;
V_21 . type = V_140 ;
V_29 = F_37 ( V_108 , V_35 , & V_21 , V_65 , - 1 , 1 ) ;
if ( V_29 > 0 )
V_29 = - V_151 ;
}
#endif
return V_29 ;
}
static T_1 int F_121 ( struct V_107 * V_108 ,
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
V_29 = F_106 ( V_108 , V_35 , V_65 , & V_21 , 0 ) ;
F_44 ( V_65 ) ;
return V_29 ;
}
static inline int F_122 ( T_2 V_17 , T_2 V_131 )
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
F_123 ( V_65 -> V_83 [ V_164 ] , V_21 ,
V_65 -> V_84 [ V_164 ] + 1 ) ;
return 0 ;
}
return 1 ;
}
static T_5
int F_124 ( struct V_107 * V_108 ,
struct V_34 * V_35 ,
struct V_64 * V_65 ,
struct V_160 * * V_166 ,
T_2 V_27 , T_2 V_36 ,
T_2 V_17 , T_2 V_144 ,
T_2 V_131 , T_2 V_33 , int V_167 )
{
struct V_68 V_21 ;
struct V_66 * V_67 ;
struct V_114 * V_115 ;
struct V_160 * V_161 ;
T_2 V_7 ;
T_2 V_116 ;
unsigned long V_168 ;
unsigned long V_31 ;
int V_132 ;
int type ;
int V_169 ;
int V_29 ;
int V_82 = 0 ;
bool V_170 = F_76 ( V_35 -> V_37 ,
V_119 ) ;
V_21 . V_22 = V_27 ;
V_21 . type = V_77 ;
V_21 . V_33 = V_36 ;
V_169 = F_122 ( V_17 , V_131 ) ;
if ( V_167 ) {
V_132 = F_125 ( V_169 ) ;
V_65 -> V_171 = 1 ;
} else
V_132 = - 1 ;
if ( V_170 && V_131 < V_141 ) {
V_21 . type = V_86 ;
V_21 . V_33 = V_131 ;
}
V_78:
V_29 = F_37 ( V_108 , V_35 , & V_21 , V_65 , V_132 , 1 ) ;
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
V_21 . V_22 = V_27 ;
V_21 . type = V_77 ;
V_21 . V_33 = V_36 ;
F_44 ( V_65 ) ;
goto V_78;
}
}
if ( V_29 && ! V_167 ) {
V_82 = - V_151 ;
goto V_73;
} else if ( F_8 ( V_29 ) ) {
V_82 = - V_172 ;
goto V_73;
}
V_67 = V_65 -> V_83 [ 0 ] ;
V_116 = F_77 ( V_67 , V_65 -> V_84 [ 0 ] ) ;
#ifdef F_81
if ( V_116 < sizeof( * V_115 ) ) {
if ( ! V_167 ) {
V_82 = - V_151 ;
goto V_73;
}
V_29 = F_87 ( V_108 , V_35 , V_65 , V_131 ,
V_132 ) ;
if ( V_29 < 0 ) {
V_82 = V_29 ;
goto V_73;
}
V_67 = V_65 -> V_83 [ 0 ] ;
V_116 = F_77 ( V_67 , V_65 -> V_84 [ 0 ] ) ;
}
#endif
F_30 ( V_116 < sizeof( * V_115 ) ) ;
V_115 = F_78 ( V_67 , V_65 -> V_84 [ 0 ] , struct V_114 ) ;
V_7 = F_80 ( V_67 , V_115 ) ;
V_168 = ( unsigned long ) ( V_115 + 1 ) ;
V_31 = ( unsigned long ) V_115 + V_116 ;
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
type = F_119 ( V_67 , V_161 ) ;
if ( V_169 < type )
break;
if ( V_169 > type ) {
V_168 += F_125 ( type ) ;
continue;
}
if ( type == V_153 ) {
struct V_148 * V_173 ;
V_173 = (struct V_148 * ) ( & V_161 -> V_33 ) ;
if ( F_103 ( V_67 , V_173 , V_144 ,
V_131 , V_33 ) ) {
V_82 = 0 ;
break;
}
if ( F_99 ( V_67 , V_173 ) <
F_96 ( V_144 , V_131 , V_33 ) )
break;
} else {
T_2 V_174 ;
V_174 = F_126 ( V_67 , V_161 ) ;
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
V_168 += F_125 ( type ) ;
}
if ( V_82 == - V_151 && V_167 ) {
if ( V_116 + V_132 >=
F_127 ( V_35 ) ) {
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
F_128 ( V_65 , 1 ) ;
}
return V_82 ;
}
static T_5
void F_129 ( struct V_34 * V_35 ,
struct V_64 * V_65 ,
struct V_160 * V_161 ,
T_2 V_17 , T_2 V_144 ,
T_2 V_131 , T_2 V_33 , int V_155 ,
struct V_177 * V_127 )
{
struct V_66 * V_67 ;
struct V_114 * V_115 ;
unsigned long V_168 ;
unsigned long V_31 ;
unsigned long V_178 ;
T_2 V_110 ;
int V_57 ;
int type ;
V_67 = V_65 -> V_83 [ 0 ] ;
V_115 = F_78 ( V_67 , V_65 -> V_84 [ 0 ] , struct V_114 ) ;
V_178 = ( unsigned long ) V_161 - ( unsigned long ) V_115 ;
type = F_122 ( V_17 , V_131 ) ;
V_57 = F_125 ( type ) ;
F_89 ( V_35 , V_65 , V_57 ) ;
V_115 = F_78 ( V_67 , V_65 -> V_84 [ 0 ] , struct V_114 ) ;
V_110 = F_79 ( V_67 , V_115 ) ;
V_110 += V_155 ;
F_90 ( V_67 , V_115 , V_110 ) ;
if ( V_127 )
F_130 ( V_127 , V_67 , V_115 ) ;
V_168 = ( unsigned long ) V_115 + V_178 ;
V_31 = ( unsigned long ) V_115 + F_77 ( V_67 , V_65 -> V_84 [ 0 ] ) ;
if ( V_168 < V_31 - V_57 )
F_131 ( V_67 , V_168 + V_57 , V_168 ,
V_31 - V_57 - V_168 ) ;
V_161 = (struct V_160 * ) V_168 ;
F_132 ( V_67 , V_161 , type ) ;
if ( type == V_153 ) {
struct V_148 * V_173 ;
V_173 = (struct V_148 * ) ( & V_161 -> V_33 ) ;
F_109 ( V_67 , V_173 , V_144 ) ;
F_110 ( V_67 , V_173 , V_131 ) ;
F_111 ( V_67 , V_173 , V_33 ) ;
F_112 ( V_67 , V_173 , V_155 ) ;
} else if ( type == V_152 ) {
struct V_156 * V_179 ;
V_179 = (struct V_156 * ) ( V_161 + 1 ) ;
F_107 ( V_67 , V_179 , V_155 ) ;
F_133 ( V_67 , V_161 , V_17 ) ;
} else if ( type == V_162 ) {
F_133 ( V_67 , V_161 , V_17 ) ;
} else {
F_133 ( V_67 , V_161 , V_144 ) ;
}
F_95 ( V_67 ) ;
}
static int F_134 ( struct V_107 * V_108 ,
struct V_34 * V_35 ,
struct V_64 * V_65 ,
struct V_160 * * V_166 ,
T_2 V_27 , T_2 V_36 , T_2 V_17 ,
T_2 V_144 , T_2 V_131 , T_2 V_33 )
{
int V_29 ;
V_29 = F_124 ( V_108 , V_35 , V_65 , V_166 ,
V_27 , V_36 , V_17 ,
V_144 , V_131 , V_33 , 0 ) ;
if ( V_29 != - V_151 )
return V_29 ;
F_44 ( V_65 ) ;
* V_166 = NULL ;
if ( V_131 < V_141 ) {
V_29 = F_120 ( V_108 , V_35 , V_65 , V_27 , V_17 ,
V_144 ) ;
} else {
V_29 = F_104 ( V_108 , V_35 , V_65 , V_27 , V_17 ,
V_144 , V_131 , V_33 ) ;
}
return V_29 ;
}
static T_5
void F_135 ( struct V_34 * V_35 ,
struct V_64 * V_65 ,
struct V_160 * V_161 ,
int V_180 ,
struct V_177 * V_127 )
{
struct V_66 * V_67 ;
struct V_114 * V_115 ;
struct V_148 * V_173 = NULL ;
struct V_156 * V_179 = NULL ;
unsigned long V_168 ;
unsigned long V_31 ;
T_3 V_116 ;
int V_57 ;
int type ;
T_2 V_110 ;
V_67 = V_65 -> V_83 [ 0 ] ;
V_115 = F_78 ( V_67 , V_65 -> V_84 [ 0 ] , struct V_114 ) ;
V_110 = F_79 ( V_67 , V_115 ) ;
F_8 ( V_180 < 0 && V_110 + V_180 <= 0 ) ;
V_110 += V_180 ;
F_90 ( V_67 , V_115 , V_110 ) ;
if ( V_127 )
F_130 ( V_127 , V_67 , V_115 ) ;
type = F_119 ( V_67 , V_161 ) ;
if ( type == V_153 ) {
V_173 = (struct V_148 * ) ( & V_161 -> V_33 ) ;
V_110 = F_113 ( V_67 , V_173 ) ;
} else if ( type == V_152 ) {
V_179 = (struct V_156 * ) ( V_161 + 1 ) ;
V_110 = F_108 ( V_67 , V_179 ) ;
} else {
V_110 = 1 ;
F_30 ( V_180 != - 1 ) ;
}
F_30 ( V_180 < 0 && V_110 < - V_180 ) ;
V_110 += V_180 ;
if ( V_110 > 0 ) {
if ( type == V_153 )
F_112 ( V_67 , V_173 , V_110 ) ;
else
F_107 ( V_67 , V_179 , V_110 ) ;
} else {
V_57 = F_125 ( type ) ;
V_116 = F_77 ( V_67 , V_65 -> V_84 [ 0 ] ) ;
V_168 = ( unsigned long ) V_161 ;
V_31 = ( unsigned long ) V_115 + V_116 ;
if ( V_168 + V_57 < V_31 )
F_131 ( V_67 , V_168 , V_168 + V_57 ,
V_31 - V_168 - V_57 ) ;
V_116 -= V_57 ;
F_136 ( V_35 , V_65 , V_116 , 1 ) ;
}
F_95 ( V_67 ) ;
}
static T_5
int F_137 ( struct V_107 * V_108 ,
struct V_34 * V_35 ,
struct V_64 * V_65 ,
T_2 V_27 , T_2 V_36 , T_2 V_17 ,
T_2 V_144 , T_2 V_131 ,
T_2 V_33 , int V_155 ,
struct V_177 * V_127 )
{
struct V_160 * V_161 ;
int V_29 ;
V_29 = F_124 ( V_108 , V_35 , V_65 , & V_161 ,
V_27 , V_36 , V_17 ,
V_144 , V_131 , V_33 , 1 ) ;
if ( V_29 == 0 ) {
F_30 ( V_131 < V_141 ) ;
F_135 ( V_35 , V_65 , V_161 ,
V_155 , V_127 ) ;
} else if ( V_29 == - V_151 ) {
F_129 ( V_35 , V_65 , V_161 , V_17 ,
V_144 , V_131 , V_33 ,
V_155 , V_127 ) ;
V_29 = 0 ;
}
return V_29 ;
}
static int F_138 ( struct V_107 * V_108 ,
struct V_34 * V_35 ,
struct V_64 * V_65 ,
T_2 V_27 , T_2 V_17 , T_2 V_144 ,
T_2 V_131 , T_2 V_33 , int V_155 )
{
int V_29 ;
if ( V_131 < V_141 ) {
F_30 ( V_155 != 1 ) ;
V_29 = F_121 ( V_108 , V_35 , V_65 , V_27 ,
V_17 , V_144 ) ;
} else {
V_29 = F_105 ( V_108 , V_35 , V_65 , V_27 ,
V_17 , V_144 ,
V_131 , V_33 , V_155 ) ;
}
return V_29 ;
}
static int F_139 ( struct V_107 * V_108 ,
struct V_34 * V_35 ,
struct V_64 * V_65 ,
struct V_160 * V_161 ,
int V_157 , int V_181 )
{
int V_29 = 0 ;
F_30 ( ! V_181 && V_157 != 1 ) ;
if ( V_161 ) {
F_135 ( V_35 , V_65 , V_161 ,
- V_157 , NULL ) ;
} else if ( V_181 ) {
V_29 = F_114 ( V_108 , V_35 , V_65 , V_157 ) ;
} else {
V_29 = F_116 ( V_108 , V_35 , V_65 ) ;
}
return V_29 ;
}
static int F_140 ( struct V_182 * V_183 ,
T_2 V_32 , T_2 V_49 )
{
return F_141 ( V_183 , V_32 >> 9 , V_49 >> 9 , V_40 , 0 ) ;
}
static int F_142 ( struct V_34 * V_35 , T_2 V_27 ,
T_2 V_36 , T_2 * V_184 )
{
int V_29 ;
T_2 V_185 = 0 ;
struct V_186 * V_187 = NULL ;
V_29 = F_143 ( V_35 -> V_37 , V_188 ,
V_27 , & V_36 , & V_187 , 0 ) ;
if ( ! V_29 ) {
struct V_189 * V_190 = V_187 -> V_191 ;
int V_43 ;
for ( V_43 = 0 ; V_43 < V_187 -> V_192 ; V_43 ++ , V_190 ++ ) {
if ( ! V_190 -> V_193 -> V_194 )
continue;
V_29 = F_140 ( V_190 -> V_193 -> V_183 ,
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
int F_144 ( struct V_107 * V_108 ,
struct V_34 * V_35 ,
T_2 V_27 , T_2 V_36 , T_2 V_17 ,
T_2 V_144 , T_2 V_131 , T_2 V_33 , int V_198 )
{
int V_29 ;
struct V_12 * V_37 = V_35 -> V_37 ;
F_30 ( V_131 < V_141 &&
V_144 == V_199 ) ;
if ( V_131 < V_141 ) {
V_29 = F_145 ( V_37 , V_108 , V_27 ,
V_36 ,
V_17 , V_144 , ( int ) V_131 ,
V_200 , NULL , V_198 ) ;
} else {
V_29 = F_146 ( V_37 , V_108 , V_27 ,
V_36 ,
V_17 , V_144 , V_131 , V_33 ,
V_200 , NULL , V_198 ) ;
}
return V_29 ;
}
static int F_147 ( struct V_107 * V_108 ,
struct V_34 * V_35 ,
T_2 V_27 , T_2 V_36 ,
T_2 V_17 , T_2 V_144 ,
T_2 V_131 , T_2 V_33 , int V_155 ,
struct V_177 * V_127 )
{
struct V_64 * V_65 ;
struct V_66 * V_67 ;
struct V_114 * V_133 ;
T_2 V_110 ;
int V_29 ;
V_65 = F_33 () ;
if ( ! V_65 )
return - V_72 ;
V_65 -> V_76 = 1 ;
V_65 -> V_201 = 1 ;
V_29 = F_137 ( V_108 , V_35 -> V_37 -> V_63 ,
V_65 , V_27 , V_36 , V_17 ,
V_144 , V_131 , V_33 ,
V_155 , V_127 ) ;
if ( V_29 != - V_175 )
goto V_73;
V_67 = V_65 -> V_83 [ 0 ] ;
V_133 = F_78 ( V_67 , V_65 -> V_84 [ 0 ] , struct V_114 ) ;
V_110 = F_79 ( V_67 , V_133 ) ;
F_90 ( V_67 , V_133 , V_110 + V_155 ) ;
if ( V_127 )
F_130 ( V_127 , V_67 , V_133 ) ;
F_95 ( V_67 ) ;
F_44 ( V_65 ) ;
V_65 -> V_76 = 1 ;
V_65 -> V_201 = 1 ;
V_29 = F_138 ( V_108 , V_35 -> V_37 -> V_63 ,
V_65 , V_27 , V_17 , V_144 ,
V_131 , V_33 , V_155 ) ;
if ( V_29 )
F_148 ( V_108 , V_35 , V_29 ) ;
V_73:
F_50 ( V_65 ) ;
return V_29 ;
}
static int F_149 ( struct V_107 * V_108 ,
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
V_149 = F_150 ( V_126 ) ;
F_151 ( V_126 , V_149 , V_126 -> V_207 ) ;
if ( V_126 -> type == V_152 )
V_17 = V_149 -> V_17 ;
else
V_206 = V_149 -> V_35 ;
if ( V_126 -> V_207 == V_200 && V_203 ) {
if ( V_127 )
V_7 |= V_127 -> V_129 ;
V_29 = F_152 ( V_108 , V_35 ,
V_17 , V_206 , V_7 ,
V_149 -> V_22 , V_149 -> V_33 ,
& V_205 , V_126 -> V_130 ) ;
} else if ( V_126 -> V_207 == V_200 ) {
V_29 = F_147 ( V_108 , V_35 , V_126 -> V_27 ,
V_126 -> V_36 , V_17 ,
V_206 , V_149 -> V_22 ,
V_149 -> V_33 , V_126 -> V_130 ,
V_127 ) ;
} else if ( V_126 -> V_207 == V_208 ) {
V_29 = F_153 ( V_108 , V_35 , V_126 -> V_27 ,
V_126 -> V_36 , V_17 ,
V_206 , V_149 -> V_22 ,
V_149 -> V_33 , V_126 -> V_130 ,
V_127 ) ;
} else {
F_83 () ;
}
return V_29 ;
}
static void F_130 ( struct V_177 * V_127 ,
struct V_66 * V_67 ,
struct V_114 * V_115 )
{
T_2 V_7 = F_80 ( V_67 , V_115 ) ;
if ( V_127 -> V_128 ) {
V_7 |= V_127 -> V_129 ;
F_92 ( V_67 , V_115 , V_7 ) ;
}
if ( V_127 -> V_209 ) {
struct V_136 * V_137 ;
F_30 ( ! ( V_7 & V_142 ) ) ;
V_137 = (struct V_136 * ) ( V_115 + 1 ) ;
F_154 ( V_67 , V_137 , & V_127 -> V_21 ) ;
}
}
static int F_155 ( struct V_107 * V_108 ,
struct V_34 * V_35 ,
struct V_202 * V_126 ,
struct V_177 * V_127 )
{
struct V_68 V_21 ;
struct V_64 * V_65 ;
struct V_114 * V_115 ;
struct V_66 * V_67 ;
T_3 V_116 ;
int V_29 ;
int V_82 = 0 ;
int V_109 = ! V_127 -> V_181 ;
if ( V_108 -> V_210 )
return 0 ;
if ( V_109 && ! F_76 ( V_35 -> V_37 , V_119 ) )
V_109 = 0 ;
V_65 = F_33 () ;
if ( ! V_65 )
return - V_72 ;
V_21 . V_22 = V_126 -> V_27 ;
if ( V_109 ) {
V_21 . type = V_86 ;
V_21 . V_33 = V_127 -> V_164 ;
} else {
V_21 . type = V_77 ;
V_21 . V_33 = V_126 -> V_36 ;
}
V_78:
V_65 -> V_76 = 1 ;
V_65 -> V_201 = 1 ;
V_29 = F_37 ( V_108 , V_35 -> V_37 -> V_63 , & V_21 ,
V_65 , 0 , 1 ) ;
if ( V_29 < 0 ) {
V_82 = V_29 ;
goto V_73;
}
if ( V_29 > 0 ) {
if ( V_109 ) {
if ( V_65 -> V_84 [ 0 ] > 0 ) {
V_65 -> V_84 [ 0 ] -- ;
F_40 ( V_65 -> V_83 [ 0 ] , & V_21 ,
V_65 -> V_84 [ 0 ] ) ;
if ( V_21 . V_22 == V_126 -> V_27 &&
V_21 . type == V_77 &&
V_21 . V_33 == V_126 -> V_36 )
V_29 = 0 ;
}
if ( V_29 > 0 ) {
F_44 ( V_65 ) ;
V_109 = 0 ;
V_21 . V_22 = V_126 -> V_27 ;
V_21 . V_33 = V_126 -> V_36 ;
V_21 . type = V_77 ;
goto V_78;
}
} else {
V_82 = - V_172 ;
goto V_73;
}
}
V_67 = V_65 -> V_83 [ 0 ] ;
V_116 = F_77 ( V_67 , V_65 -> V_84 [ 0 ] ) ;
#ifdef F_81
if ( V_116 < sizeof( * V_115 ) ) {
V_29 = F_87 ( V_108 , V_35 -> V_37 -> V_63 ,
V_65 , ( T_2 ) - 1 , 0 ) ;
if ( V_29 < 0 ) {
V_82 = V_29 ;
goto V_73;
}
V_67 = V_65 -> V_83 [ 0 ] ;
V_116 = F_77 ( V_67 , V_65 -> V_84 [ 0 ] ) ;
}
#endif
F_30 ( V_116 < sizeof( * V_115 ) ) ;
V_115 = F_78 ( V_67 , V_65 -> V_84 [ 0 ] , struct V_114 ) ;
F_130 ( V_127 , V_67 , V_115 ) ;
F_95 ( V_67 ) ;
V_73:
F_50 ( V_65 ) ;
return V_82 ;
}
static int F_156 ( struct V_107 * V_108 ,
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
bool V_170 = F_76 ( V_35 -> V_37 ,
V_119 ) ;
V_149 = F_157 ( V_126 ) ;
F_158 ( V_126 , V_149 , V_126 -> V_207 ) ;
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
V_29 = F_159 ( V_108 , V_35 ,
V_17 , V_206 ,
V_127 -> V_129 ,
& V_127 -> V_21 ,
V_149 -> V_164 , & V_205 ) ;
} else if ( V_126 -> V_207 == V_200 ) {
V_29 = F_147 ( V_108 , V_35 , V_126 -> V_27 ,
V_126 -> V_36 , V_17 , V_206 ,
V_149 -> V_164 , 0 , 1 , V_127 ) ;
} else if ( V_126 -> V_207 == V_208 ) {
V_29 = F_153 ( V_108 , V_35 , V_126 -> V_27 ,
V_126 -> V_36 , V_17 , V_206 ,
V_149 -> V_164 , 0 , 1 , V_127 ) ;
} else {
F_83 () ;
}
return V_29 ;
}
static int F_160 ( struct V_107 * V_108 ,
struct V_34 * V_35 ,
struct V_202 * V_126 ,
struct V_177 * V_127 ,
int V_203 )
{
int V_29 = 0 ;
if ( V_108 -> V_210 ) {
if ( V_203 )
F_161 ( V_35 , V_126 -> V_27 ,
V_126 -> V_36 , 1 ) ;
return 0 ;
}
if ( F_162 ( V_126 ) ) {
struct V_111 * V_102 ;
F_30 ( V_127 ) ;
V_102 = F_163 ( V_126 ) ;
F_164 ( V_126 , V_102 , V_126 -> V_207 ) ;
if ( V_203 ) {
F_161 ( V_35 , V_126 -> V_27 ,
V_126 -> V_36 , 1 ) ;
if ( V_102 -> V_181 ) {
V_29 = F_165 ( V_108 , V_35 ,
V_126 -> V_27 ,
V_126 -> V_36 ) ;
}
}
return V_29 ;
}
if ( V_126 -> type == V_163 ||
V_126 -> type == V_162 )
V_29 = F_156 ( V_108 , V_35 , V_126 , V_127 ,
V_203 ) ;
else if ( V_126 -> type == V_153 ||
V_126 -> type == V_152 )
V_29 = F_149 ( V_108 , V_35 , V_126 , V_127 ,
V_203 ) ;
else
F_83 () ;
return V_29 ;
}
T_1 int F_166 ( struct V_107 * V_108 ,
struct V_34 * V_35 ,
unsigned long V_44 )
{
struct V_112 * V_113 ;
struct V_202 * V_149 ;
struct V_111 * V_212 = NULL ;
struct V_177 * V_127 ;
struct V_12 * V_37 = V_35 -> V_37 ;
T_6 V_32 = F_167 () ;
int V_29 ;
unsigned long V_8 = 0 ;
unsigned long V_213 = 0 ;
int V_214 = 0 ;
V_113 = & V_108 -> V_125 -> V_113 ;
while ( 1 ) {
if ( ! V_212 ) {
if ( V_8 >= V_44 )
break;
F_11 ( & V_113 -> V_52 ) ;
V_212 = F_168 ( V_108 ) ;
if ( ! V_212 ) {
F_13 ( & V_113 -> V_52 ) ;
break;
}
V_29 = F_169 ( V_108 , V_212 ) ;
F_13 ( & V_113 -> V_52 ) ;
if ( V_29 == - V_175 ) {
V_212 = NULL ;
V_8 ++ ;
continue;
}
}
F_11 ( & V_212 -> V_52 ) ;
F_170 ( V_108 , V_37 , V_113 ,
V_212 ) ;
V_149 = F_171 ( V_212 ) ;
if ( V_149 && V_149 -> V_215 &&
F_172 ( V_37 , V_113 , V_149 -> V_215 ) ) {
F_13 ( & V_212 -> V_52 ) ;
F_173 ( V_212 ) ;
F_11 ( & V_113 -> V_52 ) ;
V_212 -> V_216 = 0 ;
V_113 -> V_217 ++ ;
F_13 ( & V_113 -> V_52 ) ;
V_212 = NULL ;
F_47 () ;
V_8 ++ ;
continue;
}
V_214 = V_212 -> V_214 ;
V_212 -> V_214 = 0 ;
V_127 = V_212 -> V_127 ;
V_212 -> V_127 = NULL ;
if ( ! V_149 ) {
V_149 = & V_212 -> V_126 ;
if ( V_127 && V_214 ) {
F_174 ( V_127 ) ;
V_127 = NULL ;
}
if ( V_127 ) {
F_13 ( & V_212 -> V_52 ) ;
V_29 = F_155 ( V_108 , V_35 ,
V_149 , V_127 ) ;
F_174 ( V_127 ) ;
if ( V_29 ) {
if ( V_214 )
V_212 -> V_214 = 1 ;
V_212 -> V_216 = 0 ;
F_175 ( V_37 , L_1 , V_29 ) ;
F_173 ( V_212 ) ;
return V_29 ;
}
continue;
}
F_13 ( & V_212 -> V_52 ) ;
F_11 ( & V_113 -> V_52 ) ;
F_11 ( & V_212 -> V_52 ) ;
if ( F_176 ( & V_212 -> V_206 ) ||
V_212 -> V_127 ) {
F_13 ( & V_212 -> V_52 ) ;
F_13 ( & V_113 -> V_52 ) ;
continue;
}
V_149 -> V_218 = 0 ;
V_113 -> V_219 -- ;
F_177 ( & V_212 -> V_220 ,
& V_113 -> V_221 ) ;
F_13 ( & V_113 -> V_52 ) ;
} else {
V_213 ++ ;
V_149 -> V_218 = 0 ;
F_177 ( & V_149 -> V_15 , & V_212 -> V_206 ) ;
}
F_178 ( & V_113 -> V_222 ) ;
if ( ! F_162 ( V_149 ) ) {
switch ( V_149 -> V_207 ) {
case V_200 :
case V_223 :
V_212 -> V_126 . V_130 -= V_149 -> V_130 ;
break;
case V_208 :
V_212 -> V_126 . V_130 += V_149 -> V_130 ;
break;
default:
F_8 ( 1 ) ;
}
}
F_13 ( & V_212 -> V_52 ) ;
V_29 = F_160 ( V_108 , V_35 , V_149 , V_127 ,
V_214 ) ;
F_174 ( V_127 ) ;
if ( V_29 ) {
V_212 -> V_216 = 0 ;
F_173 ( V_212 ) ;
F_86 ( V_149 ) ;
F_175 ( V_37 , L_2 , V_29 ) ;
return V_29 ;
}
if ( F_162 ( V_149 ) ) {
F_173 ( V_212 ) ;
V_212 = NULL ;
}
F_86 ( V_149 ) ;
V_8 ++ ;
F_47 () ;
}
if ( V_213 > 0 ) {
T_2 V_224 = F_179 ( F_180 ( F_167 () , V_32 ) ) ;
T_2 V_225 ;
F_11 ( & V_113 -> V_52 ) ;
V_225 = V_37 -> V_226 * 3 + V_224 ;
V_225 = F_181 ( V_225 , 4 ) ;
V_37 -> V_226 = V_225 ;
F_13 ( & V_113 -> V_52 ) ;
}
return 0 ;
}
static T_2 F_182 ( struct V_227 * V_35 )
{
struct V_15 * V_30 = V_35 -> V_15 ;
struct V_202 * V_228 ;
int V_229 = 1 ;
T_2 V_230 ;
T_2 V_231 = 0 , V_70 = 0 ;
V_30 = F_176 ( V_35 ) ;
if ( V_30 ) {
V_228 = F_12 ( V_30 , struct V_202 , V_15 ) ;
V_231 = V_228 -> V_27 ;
}
V_30 = F_183 ( V_35 ) ;
if ( V_30 ) {
V_228 = F_12 ( V_30 , struct V_202 , V_15 ) ;
V_70 = V_228 -> V_27 ;
}
V_30 = V_35 -> V_15 ;
while ( V_30 ) {
V_228 = F_12 ( V_30 , struct V_202 , V_15 ) ;
F_8 ( ! V_228 -> V_218 ) ;
V_230 = V_228 -> V_27 ;
if ( V_229 )
V_30 = V_30 -> V_23 ;
else
V_30 = V_30 -> V_24 ;
V_229 = 1 - V_229 ;
}
return V_230 ;
}
int F_184 ( struct V_107 * V_108 ,
struct V_12 * V_37 )
{
struct V_232 * V_232 ;
int V_29 = 0 ;
if ( F_185 ( & V_108 -> V_233 ) !=
! V_108 -> V_234 . V_215 ) {
F_186 ( V_37 ,
L_3 ,
F_185 ( & V_108 -> V_233 ) ? L_4 : L_5 ,
( T_3 ) ( V_108 -> V_234 . V_215 >> 32 ) ,
( T_3 ) V_108 -> V_234 . V_215 ) ;
F_83 () ;
}
if ( ! V_108 -> V_234 . V_215 )
return 0 ;
while ( ! F_185 ( & V_108 -> V_233 ) ) {
V_232 = F_187 ( & V_108 -> V_233 ,
struct V_232 , V_91 ) ;
F_188 ( & V_232 -> V_91 ) ;
if ( ! V_29 )
V_29 = F_189 (
V_108 , V_37 , V_232 -> V_126 ,
V_232 -> V_127 ) ;
F_9 ( V_232 ) ;
}
F_190 ( V_37 , & V_108 -> V_234 ) ;
return V_29 ;
}
static inline T_2 F_191 ( struct V_34 * V_35 , T_2 V_235 )
{
T_2 V_36 ;
V_36 = V_235 * ( sizeof( struct V_114 ) +
sizeof( struct V_160 ) ) ;
if ( ! F_76 ( V_35 -> V_37 , V_119 ) )
V_36 += V_235 * sizeof( struct V_136 ) ;
return F_181 ( V_36 , F_192 ( V_35 ) ) ;
}
int F_193 ( struct V_107 * V_108 ,
struct V_34 * V_35 )
{
struct V_236 * V_237 ;
T_2 V_219 = V_108 -> V_125 -> V_113 . V_217 ;
T_2 V_36 ;
int V_29 = 0 ;
V_36 = F_194 ( V_35 , 1 ) ;
V_219 = F_191 ( V_35 , V_219 ) ;
if ( V_219 > 1 )
V_36 += ( V_219 - 1 ) * V_35 -> V_88 ;
V_36 <<= 1 ;
V_237 = & V_35 -> V_37 -> V_238 ;
if ( V_237 -> V_103 -> V_106 )
V_36 <<= 1 ;
F_11 ( & V_237 -> V_52 ) ;
if ( V_237 -> V_10 <= V_36 )
V_29 = 1 ;
F_13 ( & V_237 -> V_52 ) ;
return V_29 ;
}
int F_195 ( struct V_107 * V_108 ,
struct V_34 * V_35 )
{
struct V_12 * V_37 = V_35 -> V_37 ;
T_2 V_222 =
F_196 ( & V_108 -> V_125 -> V_113 . V_222 ) ;
T_2 V_239 ;
F_2 () ;
V_239 = V_37 -> V_226 ;
if ( V_222 * V_239 >= V_240 )
return 1 ;
return F_193 ( V_108 , V_35 ) ;
}
int F_197 ( struct V_107 * V_108 ,
struct V_34 * V_35 , unsigned long V_8 )
{
struct V_15 * V_126 ;
struct V_112 * V_113 ;
struct V_111 * V_102 ;
int V_29 ;
int V_241 = V_8 == ( unsigned long ) - 1 ;
int V_242 = 0 ;
if ( V_108 -> V_210 )
return 0 ;
if ( V_35 == V_35 -> V_37 -> V_63 )
V_35 = V_35 -> V_37 -> V_87 ;
F_184 ( V_108 , V_35 -> V_37 ) ;
V_113 = & V_108 -> V_125 -> V_113 ;
if ( V_8 == 0 ) {
V_8 = F_196 ( & V_113 -> V_222 ) * 2 ;
V_242 = 1 ;
}
V_78:
#ifdef F_198
V_113 -> V_243 = F_182 ( & V_113 -> V_35 ) ;
#endif
V_29 = F_166 ( V_108 , V_35 , V_8 ) ;
if ( V_29 < 0 ) {
F_148 ( V_108 , V_35 , V_29 ) ;
return V_29 ;
}
if ( V_241 ) {
if ( ! F_185 ( & V_108 -> V_244 ) )
F_199 ( V_108 , V_35 ) ;
F_11 ( & V_113 -> V_52 ) ;
V_126 = F_176 ( & V_113 -> V_221 ) ;
if ( ! V_126 ) {
F_13 ( & V_113 -> V_52 ) ;
goto V_73;
}
V_8 = ( unsigned long ) - 1 ;
while ( V_126 ) {
V_102 = F_12 ( V_126 , struct V_111 ,
V_220 ) ;
if ( F_162 ( & V_102 -> V_126 ) ) {
struct V_202 * V_149 ;
V_149 = & V_102 -> V_126 ;
F_5 ( & V_149 -> V_110 ) ;
F_13 ( & V_113 -> V_52 ) ;
F_35 ( & V_102 -> V_79 ) ;
F_46 ( & V_102 -> V_79 ) ;
F_86 ( V_149 ) ;
F_47 () ;
goto V_78;
} else {
F_8 ( 1 ) ;
}
V_126 = F_200 ( V_126 ) ;
}
F_13 ( & V_113 -> V_52 ) ;
F_47 () ;
goto V_78;
}
V_73:
F_201 ( V_108 ) ;
return 0 ;
}
int F_202 ( struct V_107 * V_108 ,
struct V_34 * V_35 ,
T_2 V_27 , T_2 V_36 , T_2 V_7 ,
int V_164 , int V_181 )
{
struct V_177 * V_127 ;
int V_29 ;
V_127 = F_203 () ;
if ( ! V_127 )
return - V_72 ;
V_127 -> V_129 = V_7 ;
V_127 -> V_128 = 1 ;
V_127 -> V_209 = 0 ;
V_127 -> V_181 = V_181 ? 1 : 0 ;
V_127 -> V_164 = V_164 ;
V_29 = F_204 ( V_35 -> V_37 , V_108 , V_27 ,
V_36 , V_127 ) ;
if ( V_29 )
F_174 ( V_127 ) ;
return V_29 ;
}
static T_1 int F_205 ( struct V_107 * V_108 ,
struct V_34 * V_35 ,
struct V_64 * V_65 ,
T_2 V_22 , T_2 V_33 , T_2 V_27 )
{
struct V_111 * V_102 ;
struct V_202 * V_149 ;
struct V_204 * V_245 ;
struct V_112 * V_113 ;
struct V_15 * V_126 ;
int V_29 = 0 ;
V_113 = & V_108 -> V_125 -> V_113 ;
F_11 ( & V_113 -> V_52 ) ;
V_102 = F_84 ( V_108 , V_27 ) ;
if ( ! V_102 ) {
F_13 ( & V_113 -> V_52 ) ;
return 0 ;
}
if ( ! F_85 ( & V_102 -> V_79 ) ) {
F_5 ( & V_102 -> V_126 . V_110 ) ;
F_13 ( & V_113 -> V_52 ) ;
F_44 ( V_65 ) ;
F_35 ( & V_102 -> V_79 ) ;
F_46 ( & V_102 -> V_79 ) ;
F_86 ( & V_102 -> V_126 ) ;
return - V_175 ;
}
F_13 ( & V_113 -> V_52 ) ;
F_11 ( & V_102 -> V_52 ) ;
V_126 = F_176 ( & V_102 -> V_206 ) ;
while ( V_126 ) {
V_149 = F_12 ( V_126 , struct V_202 , V_15 ) ;
V_126 = F_200 ( V_126 ) ;
if ( V_149 -> type != V_153 ) {
V_29 = 1 ;
break;
}
V_245 = F_150 ( V_149 ) ;
if ( V_245 -> V_35 != V_35 -> V_246 . V_22 ||
V_245 -> V_22 != V_22 ||
V_245 -> V_33 != V_33 ) {
V_29 = 1 ;
break;
}
}
F_13 ( & V_102 -> V_52 ) ;
F_46 ( & V_102 -> V_79 ) ;
return V_29 ;
}
static T_1 int F_206 ( struct V_107 * V_108 ,
struct V_34 * V_35 ,
struct V_64 * V_65 ,
T_2 V_22 , T_2 V_33 , T_2 V_27 )
{
struct V_34 * V_63 = V_35 -> V_37 -> V_63 ;
struct V_66 * V_67 ;
struct V_148 * V_149 ;
struct V_160 * V_161 ;
struct V_114 * V_115 ;
struct V_68 V_21 ;
T_3 V_116 ;
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
V_116 = F_77 ( V_67 , V_65 -> V_84 [ 0 ] ) ;
#ifdef F_81
if ( V_116 < sizeof( * V_115 ) ) {
F_8 ( V_116 != sizeof( struct V_122 ) ) ;
goto V_73;
}
#endif
V_115 = F_78 ( V_67 , V_65 -> V_84 [ 0 ] , struct V_114 ) ;
if ( V_116 != sizeof( * V_115 ) +
F_125 ( V_153 ) )
goto V_73;
if ( F_207 ( V_67 , V_115 ) <=
F_208 ( & V_35 -> V_247 ) )
goto V_73;
V_161 = (struct V_160 * ) ( V_115 + 1 ) ;
if ( F_119 ( V_67 , V_161 ) !=
V_153 )
goto V_73;
V_149 = (struct V_148 * ) ( & V_161 -> V_33 ) ;
if ( F_79 ( V_67 , V_115 ) !=
F_113 ( V_67 , V_149 ) ||
F_100 ( V_67 , V_149 ) !=
V_35 -> V_246 . V_22 ||
F_101 ( V_67 , V_149 ) != V_22 ||
F_102 ( V_67 , V_149 ) != V_33 )
goto V_73;
V_29 = 0 ;
V_73:
return V_29 ;
}
int F_209 ( struct V_107 * V_108 ,
struct V_34 * V_35 ,
T_2 V_22 , T_2 V_33 , T_2 V_27 )
{
struct V_64 * V_65 ;
int V_29 ;
int V_248 ;
V_65 = F_33 () ;
if ( ! V_65 )
return - V_151 ;
do {
V_29 = F_206 ( V_108 , V_35 , V_65 , V_22 ,
V_33 , V_27 ) ;
if ( V_29 && V_29 != - V_151 )
goto V_73;
V_248 = F_205 ( V_108 , V_35 , V_65 , V_22 ,
V_33 , V_27 ) ;
} while ( V_248 == - V_175 );
if ( V_248 && V_248 != - V_151 ) {
V_29 = V_248 ;
goto V_73;
}
if ( V_29 != - V_151 || V_248 != - V_151 )
V_29 = 0 ;
V_73:
F_50 ( V_65 ) ;
if ( V_35 -> V_246 . V_22 == V_249 )
F_8 ( V_29 > 0 ) ;
return V_29 ;
}
static int F_210 ( struct V_107 * V_108 ,
struct V_34 * V_35 ,
struct V_66 * V_250 ,
int V_251 , int V_252 , int V_198 )
{
T_2 V_27 ;
T_2 V_36 ;
T_2 V_17 ;
T_2 V_206 ;
T_3 V_71 ;
struct V_68 V_21 ;
struct V_253 * V_254 ;
int V_43 ;
int V_164 ;
int V_29 = 0 ;
int (* F_211)( struct V_107 * , struct V_34 * ,
T_2 , T_2 , T_2 , T_2 , T_2 , T_2 , int );
V_206 = F_212 ( V_250 ) ;
V_71 = F_38 ( V_250 ) ;
V_164 = F_213 ( V_250 ) ;
if ( ! V_35 -> V_255 && V_164 == 0 )
return 0 ;
if ( V_252 )
F_211 = F_144 ;
else
F_211 = V_256 ;
if ( V_251 )
V_17 = V_250 -> V_32 ;
else
V_17 = 0 ;
for ( V_43 = 0 ; V_43 < V_71 ; V_43 ++ ) {
if ( V_164 == 0 ) {
F_40 ( V_250 , & V_21 , V_43 ) ;
if ( F_214 ( & V_21 ) != V_257 )
continue;
V_254 = F_78 ( V_250 , V_43 ,
struct V_253 ) ;
if ( F_215 ( V_250 , V_254 ) ==
V_258 )
continue;
V_27 = F_216 ( V_250 , V_254 ) ;
if ( V_27 == 0 )
continue;
V_36 = F_217 ( V_250 , V_254 ) ;
V_21 . V_33 -= F_218 ( V_250 , V_254 ) ;
V_29 = F_211 ( V_108 , V_35 , V_27 , V_36 ,
V_17 , V_206 , V_21 . V_22 ,
V_21 . V_33 , V_198 ) ;
if ( V_29 )
goto V_154;
} else {
V_27 = F_219 ( V_250 , V_43 ) ;
V_36 = F_220 ( V_35 , V_164 - 1 ) ;
V_29 = F_211 ( V_108 , V_35 , V_27 , V_36 ,
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
int F_221 ( struct V_107 * V_108 , struct V_34 * V_35 ,
struct V_66 * V_250 , int V_251 , int V_198 )
{
return F_210 ( V_108 , V_35 , V_250 , V_251 , 1 , V_198 ) ;
}
int F_222 ( struct V_107 * V_108 , struct V_34 * V_35 ,
struct V_66 * V_250 , int V_251 , int V_198 )
{
return F_210 ( V_108 , V_35 , V_250 , V_251 , 0 , V_198 ) ;
}
static int F_223 ( struct V_107 * V_108 ,
struct V_34 * V_35 ,
struct V_64 * V_65 ,
struct V_1 * V_2 )
{
int V_29 ;
struct V_34 * V_63 = V_35 -> V_37 -> V_63 ;
unsigned long V_137 ;
struct V_66 * V_67 ;
V_29 = F_37 ( V_108 , V_63 , & V_2 -> V_21 , V_65 , 0 , 1 ) ;
if ( V_29 < 0 )
goto V_154;
F_30 ( V_29 ) ;
V_67 = V_65 -> V_83 [ 0 ] ;
V_137 = F_224 ( V_67 , V_65 -> V_84 [ 0 ] ) ;
F_225 ( V_67 , & V_2 -> V_133 , V_137 , sizeof( V_2 -> V_133 ) ) ;
F_95 ( V_67 ) ;
F_44 ( V_65 ) ;
V_154:
if ( V_29 ) {
F_148 ( V_108 , V_35 , V_29 ) ;
return V_29 ;
}
return 0 ;
}
static struct V_1 *
F_226 ( struct V_34 * V_35 ,
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
static int F_227 ( struct V_1 * V_14 ,
struct V_107 * V_108 ,
struct V_64 * V_65 )
{
struct V_34 * V_35 = V_14 -> V_37 -> V_87 ;
struct V_259 * V_259 = NULL ;
T_2 V_260 = 0 ;
int V_261 = V_262 ;
int V_263 = 0 ;
int V_264 = 0 ;
int V_29 = 0 ;
if ( V_14 -> V_21 . V_33 < ( 100 * 1024 * 1024 ) ) {
F_11 ( & V_14 -> V_52 ) ;
V_14 -> V_265 = V_266 ;
F_13 ( & V_14 -> V_52 ) ;
return 0 ;
}
V_78:
V_259 = F_228 ( V_35 , V_14 , V_65 ) ;
if ( F_229 ( V_259 ) && F_230 ( V_259 ) != - V_151 ) {
V_29 = F_230 ( V_259 ) ;
F_44 ( V_65 ) ;
goto V_73;
}
if ( F_229 ( V_259 ) ) {
F_30 ( V_264 ) ;
V_264 ++ ;
if ( V_14 -> V_267 )
goto V_121;
V_29 = F_231 ( V_35 , V_108 , V_14 , V_65 ) ;
if ( V_29 )
goto V_121;
goto V_78;
}
if ( V_14 -> V_268 == V_108 -> V_269 &&
F_232 ( V_259 ) ) {
V_261 = V_270 ;
goto V_271;
}
F_233 ( V_259 ) -> V_272 = 0 ;
V_29 = F_234 ( V_108 , V_35 , V_259 ) ;
F_8 ( V_29 ) ;
if ( F_232 ( V_259 ) > 0 ) {
V_29 = F_235 ( V_35 ,
& V_35 -> V_37 -> V_238 ) ;
if ( V_29 )
goto V_271;
V_29 = F_236 ( V_35 , V_108 , V_259 ) ;
if ( V_29 )
goto V_271;
}
F_11 ( & V_14 -> V_52 ) ;
if ( V_14 -> V_3 != V_4 ||
! F_237 ( V_35 , V_273 ) ) {
V_261 = V_266 ;
F_13 ( & V_14 -> V_52 ) ;
goto V_271;
}
F_13 ( & V_14 -> V_52 ) ;
V_263 = ( int ) F_181 ( V_14 -> V_21 . V_33 , 256 * 1024 * 1024 ) ;
if ( ! V_263 )
V_263 = 1 ;
V_263 *= 16 ;
V_263 *= V_274 ;
V_29 = F_238 ( V_259 , V_263 ) ;
if ( V_29 )
goto V_271;
V_29 = F_239 ( V_259 , V_108 , 0 , 0 , V_263 ,
V_263 , V_263 ,
& V_260 ) ;
if ( ! V_29 )
V_261 = V_270 ;
F_240 ( V_259 , V_263 ) ;
V_271:
F_241 ( V_259 ) ;
V_121:
F_44 ( V_65 ) ;
V_73:
F_11 ( & V_14 -> V_52 ) ;
if ( ! V_29 && V_261 == V_270 )
V_14 -> V_268 = V_108 -> V_269 ;
V_14 -> V_265 = V_261 ;
F_13 ( & V_14 -> V_52 ) ;
return V_29 ;
}
int F_242 ( struct V_107 * V_108 ,
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
if ( V_2 -> V_265 == V_275 )
break;
V_2 = F_226 ( V_35 , V_2 ) ;
}
if ( ! V_2 ) {
if ( V_70 == 0 )
break;
V_70 = 0 ;
continue;
}
V_82 = F_227 ( V_2 , V_108 , V_65 ) ;
V_70 = V_2 -> V_21 . V_22 + V_2 -> V_21 . V_33 ;
F_6 ( V_2 ) ;
}
while ( 1 ) {
if ( V_70 == 0 ) {
V_82 = F_197 ( V_108 , V_35 ,
( unsigned long ) - 1 ) ;
if ( V_82 )
goto V_73;
}
V_2 = F_67 ( V_35 -> V_37 , V_70 ) ;
while ( V_2 ) {
if ( V_2 -> V_265 == V_275 ) {
F_6 ( V_2 ) ;
goto V_78;
}
if ( V_2 -> V_276 )
break;
V_2 = F_226 ( V_35 , V_2 ) ;
}
if ( ! V_2 ) {
if ( V_70 == 0 )
break;
V_70 = 0 ;
continue;
}
if ( V_2 -> V_265 == V_270 )
V_2 -> V_265 = V_277 ;
V_2 -> V_276 = 0 ;
V_70 = V_2 -> V_21 . V_22 + V_2 -> V_21 . V_33 ;
V_82 = F_223 ( V_108 , V_35 , V_65 , V_2 ) ;
F_6 ( V_2 ) ;
if ( V_82 )
goto V_73;
}
while ( 1 ) {
if ( V_70 == 0 ) {
V_82 = F_197 ( V_108 , V_35 ,
( unsigned long ) - 1 ) ;
if ( V_82 )
goto V_73;
}
V_2 = F_67 ( V_35 -> V_37 , V_70 ) ;
while ( V_2 ) {
if ( V_2 -> V_276 ) {
F_6 ( V_2 ) ;
goto V_78;
}
if ( V_2 -> V_265 == V_277 )
break;
V_2 = F_226 ( V_35 , V_2 ) ;
}
if ( ! V_2 ) {
if ( V_70 == 0 )
break;
V_70 = 0 ;
continue;
}
V_82 = F_243 ( V_35 , V_108 , V_2 , V_65 ) ;
if ( ! V_82 && V_2 -> V_265 == V_277 )
V_2 -> V_265 = V_266 ;
V_70 = V_2 -> V_21 . V_22 + V_2 -> V_21 . V_33 ;
F_6 ( V_2 ) ;
}
V_73:
F_50 ( V_65 ) ;
return V_82 ;
}
int F_244 ( struct V_34 * V_35 , T_2 V_27 )
{
struct V_1 * V_14 ;
int V_278 = 0 ;
V_14 = F_68 ( V_35 -> V_37 , V_27 ) ;
if ( ! V_14 || V_14 -> V_267 )
V_278 = 1 ;
if ( V_14 )
F_6 ( V_14 ) ;
return V_278 ;
}
static const char * F_245 ( T_2 V_7 )
{
switch ( V_7 ) {
case V_279 | V_280 :
return L_6 ;
case V_279 :
return L_7 ;
case V_280 :
return L_8 ;
case V_281 :
return L_9 ;
default:
F_8 ( 1 ) ;
return L_10 ;
} ;
}
static int F_246 ( struct V_12 * V_13 , T_2 V_7 ,
T_2 V_282 , T_2 V_283 ,
struct V_100 * * V_103 )
{
struct V_100 * V_104 ;
int V_43 ;
int V_284 ;
int V_29 ;
if ( V_7 & ( V_285 | V_286 |
V_287 ) )
V_284 = 2 ;
else
V_284 = 1 ;
V_104 = F_69 ( V_13 , V_7 ) ;
if ( V_104 ) {
F_11 ( & V_104 -> V_52 ) ;
V_104 -> V_282 += V_282 ;
V_104 -> V_288 += V_282 * V_284 ;
V_104 -> V_283 += V_283 ;
V_104 -> V_289 += V_283 * V_284 ;
V_104 -> V_106 = 0 ;
F_13 ( & V_104 -> V_52 ) ;
* V_103 = V_104 ;
return 0 ;
}
V_104 = F_53 ( sizeof( * V_104 ) , V_40 ) ;
if ( ! V_104 )
return - V_72 ;
V_29 = F_247 ( & V_104 -> V_290 , 0 ) ;
if ( V_29 ) {
F_9 ( V_104 ) ;
return V_29 ;
}
for ( V_43 = 0 ; V_43 < V_291 ; V_43 ++ ) {
F_54 ( & V_104 -> V_292 [ V_43 ] ) ;
F_248 ( & V_104 -> V_293 [ V_43 ] , & V_294 ) ;
}
F_249 ( & V_104 -> V_295 ) ;
F_250 ( & V_104 -> V_52 ) ;
V_104 -> V_7 = V_7 & V_105 ;
V_104 -> V_282 = V_282 ;
V_104 -> V_288 = V_282 * V_284 ;
V_104 -> V_283 = V_283 ;
V_104 -> V_289 = V_283 * V_284 ;
V_104 -> V_296 = 0 ;
V_104 -> V_297 = 0 ;
V_104 -> V_298 = 0 ;
V_104 -> V_299 = 0 ;
V_104 -> V_106 = 0 ;
V_104 -> V_300 = V_301 ;
V_104 -> V_302 = 0 ;
V_104 -> V_303 = 0 ;
F_56 ( & V_104 -> V_89 ) ;
V_29 = F_251 ( & V_104 -> V_304 , & V_305 ,
V_13 -> V_306 , L_11 ,
F_245 ( V_104 -> V_7 ) ) ;
if ( V_29 ) {
F_9 ( V_104 ) ;
return V_29 ;
}
* V_103 = V_104 ;
F_252 ( & V_104 -> V_91 , & V_13 -> V_103 ) ;
if ( V_7 & V_280 )
V_13 -> V_307 = V_104 ;
return V_29 ;
}
static void F_253 ( struct V_12 * V_37 , T_2 V_7 )
{
T_2 V_308 = F_254 ( V_7 ) &
V_309 ;
F_255 ( & V_37 -> V_310 ) ;
if ( V_7 & V_280 )
V_37 -> V_311 |= V_308 ;
if ( V_7 & V_279 )
V_37 -> V_312 |= V_308 ;
if ( V_7 & V_281 )
V_37 -> V_313 |= V_308 ;
F_256 ( & V_37 -> V_310 ) ;
}
static T_2 F_257 ( struct V_12 * V_37 , T_2 V_7 )
{
struct V_314 * V_315 = V_37 -> V_316 ;
T_2 V_317 = 0 ;
if ( ! V_315 )
return 0 ;
if ( V_7 & V_280 &&
V_315 -> V_318 . V_7 & V_319 ) {
V_317 = V_280 | V_315 -> V_318 . V_317 ;
} else if ( V_7 & V_281 &&
V_315 -> V_320 . V_7 & V_319 ) {
V_317 = V_281 | V_315 -> V_320 . V_317 ;
} else if ( V_7 & V_279 &&
V_315 -> V_321 . V_7 & V_319 ) {
V_317 = V_279 | V_315 -> V_321 . V_317 ;
}
return V_317 ;
}
static T_2 F_258 ( struct V_34 * V_35 , T_2 V_7 )
{
T_2 V_322 = V_35 -> V_37 -> V_323 -> V_324 +
V_35 -> V_37 -> V_323 -> V_325 ;
T_2 V_317 ;
T_2 V_326 ;
F_11 ( & V_35 -> V_37 -> V_327 ) ;
V_317 = F_257 ( V_35 -> V_37 , V_7 ) ;
if ( V_317 ) {
if ( ( V_7 & V_317 ) & V_309 ) {
F_13 ( & V_35 -> V_37 -> V_327 ) ;
return F_259 ( V_317 ) ;
}
}
F_13 ( & V_35 -> V_37 -> V_327 ) ;
if ( V_322 == 1 )
V_7 &= ~ ( V_286 | V_328 |
V_329 ) ;
if ( V_322 < 3 )
V_7 &= ~ V_330 ;
if ( V_322 < 4 )
V_7 &= ~ V_287 ;
V_326 = V_7 & ( V_285 | V_328 |
V_286 | V_329 |
V_330 | V_287 ) ;
V_7 &= ~ V_326 ;
if ( V_326 & V_330 )
V_326 = V_330 ;
else if ( V_326 & V_329 )
V_326 = V_329 ;
else if ( V_326 & V_287 )
V_326 = V_287 ;
else if ( V_326 & V_286 )
V_326 = V_286 ;
else if ( V_326 & V_328 )
V_326 = V_328 ;
return F_259 ( V_7 | V_326 ) ;
}
static T_2 F_260 ( struct V_34 * V_35 , T_2 V_331 )
{
unsigned V_215 ;
T_2 V_7 ;
do {
V_7 = V_331 ;
V_215 = F_261 ( & V_35 -> V_37 -> V_310 ) ;
if ( V_7 & V_280 )
V_7 |= V_35 -> V_37 -> V_311 ;
else if ( V_7 & V_281 )
V_7 |= V_35 -> V_37 -> V_313 ;
else if ( V_7 & V_279 )
V_7 |= V_35 -> V_37 -> V_312 ;
} while ( F_262 ( & V_35 -> V_37 -> V_310 , V_215 ) );
return F_258 ( V_35 , V_7 ) ;
}
T_2 F_263 ( struct V_34 * V_35 , int V_318 )
{
T_2 V_7 ;
T_2 V_29 ;
if ( V_318 )
V_7 = V_280 ;
else if ( V_35 == V_35 -> V_37 -> V_332 )
V_7 = V_281 ;
else
V_7 = V_279 ;
V_29 = F_260 ( V_35 , V_7 ) ;
return V_29 ;
}
int F_238 ( struct V_259 * V_259 , T_2 V_333 )
{
struct V_100 * V_307 ;
struct V_34 * V_35 = F_233 ( V_259 ) -> V_35 ;
struct V_12 * V_37 = V_35 -> V_37 ;
T_2 V_334 ;
int V_29 = 0 , V_335 = 0 , V_336 = 1 ;
V_333 = F_264 ( V_333 , V_35 -> V_337 ) ;
if ( F_265 ( V_259 ) ) {
V_335 = 1 ;
ASSERT ( V_338 -> V_339 ) ;
}
V_307 = V_37 -> V_307 ;
if ( ! V_307 )
goto V_340;
V_78:
F_11 ( & V_307 -> V_52 ) ;
V_334 = V_307 -> V_283 + V_307 -> V_297 +
V_307 -> V_296 + V_307 -> V_298 +
V_307 -> V_299 ;
if ( V_334 + V_333 > V_307 -> V_282 ) {
struct V_107 * V_108 ;
if ( ! V_307 -> V_106 && V_336 ) {
T_2 V_341 ;
V_307 -> V_300 = V_342 ;
F_13 ( & V_307 -> V_52 ) ;
V_340:
V_341 = F_263 ( V_35 , 1 ) ;
V_108 = F_266 ( V_35 ) ;
if ( F_229 ( V_108 ) )
return F_230 ( V_108 ) ;
V_29 = F_267 ( V_108 , V_35 -> V_37 -> V_63 ,
V_341 ,
V_301 ) ;
F_268 ( V_108 , V_35 ) ;
if ( V_29 < 0 ) {
if ( V_29 != - V_343 )
return V_29 ;
else
goto V_344;
}
if ( ! V_307 )
V_307 = V_37 -> V_307 ;
goto V_78;
}
if ( F_269 ( & V_307 -> V_290 ,
V_333 ) < 0 )
V_335 = 1 ;
F_13 ( & V_307 -> V_52 ) ;
V_344:
if ( ! V_335 &&
! F_196 ( & V_35 -> V_37 -> V_345 ) ) {
V_335 = 1 ;
V_108 = F_266 ( V_35 ) ;
if ( F_229 ( V_108 ) )
return F_230 ( V_108 ) ;
V_29 = F_270 ( V_108 , V_35 ) ;
if ( V_29 )
return V_29 ;
goto V_78;
}
F_271 ( V_35 -> V_37 ,
L_12 ,
V_307 -> V_7 , V_333 , 1 ) ;
return - V_343 ;
}
V_307 -> V_299 += V_333 ;
F_271 ( V_35 -> V_37 , L_13 ,
V_307 -> V_7 , V_333 , 1 ) ;
F_13 ( & V_307 -> V_52 ) ;
return 0 ;
}
void F_240 ( struct V_259 * V_259 , T_2 V_333 )
{
struct V_34 * V_35 = F_233 ( V_259 ) -> V_35 ;
struct V_100 * V_307 ;
V_333 = F_264 ( V_333 , V_35 -> V_337 ) ;
V_307 = V_35 -> V_37 -> V_307 ;
F_11 ( & V_307 -> V_52 ) ;
F_8 ( V_307 -> V_299 < V_333 ) ;
V_307 -> V_299 -= V_333 ;
F_271 ( V_35 -> V_37 , L_13 ,
V_307 -> V_7 , V_333 , 0 ) ;
F_13 ( & V_307 -> V_52 ) ;
}
static void F_272 ( struct V_12 * V_13 )
{
struct V_101 * V_102 = & V_13 -> V_103 ;
struct V_100 * V_104 ;
F_70 () ;
F_71 (found, head, list) {
if ( V_104 -> V_7 & V_279 )
V_104 -> V_300 = V_342 ;
}
F_72 () ;
}
static inline T_2 F_273 ( struct V_236 * V_346 )
{
return ( V_346 -> V_57 << 1 ) ;
}
static int F_274 ( struct V_34 * V_35 ,
struct V_100 * V_347 , int V_348 )
{
struct V_236 * V_237 = & V_35 -> V_37 -> V_238 ;
T_2 V_36 = V_347 -> V_282 - V_347 -> V_298 ;
T_2 V_349 = V_347 -> V_283 + V_347 -> V_297 ;
T_2 V_350 ;
if ( V_348 == V_342 )
return 1 ;
if ( V_347 -> V_7 & V_279 )
V_349 += F_273 ( V_237 ) ;
if ( V_348 == V_351 ) {
V_350 = F_275 ( V_35 -> V_37 -> V_352 ) ;
V_350 = F_34 ( T_2 , 64 * 1024 * 1024 ,
F_276 ( V_350 , 1 ) ) ;
if ( V_36 - V_349 < V_350 )
return 1 ;
}
if ( V_349 + 2 * 1024 * 1024 < F_277 ( V_36 , 8 ) )
return 0 ;
return 1 ;
}
static T_2 F_278 ( struct V_34 * V_35 , T_2 type )
{
T_2 V_353 ;
if ( type & ( V_287 |
V_328 |
V_329 |
V_330 ) )
V_353 = V_35 -> V_37 -> V_323 -> V_324 ;
else if ( type & V_286 )
V_353 = 2 ;
else
V_353 = 1 ;
return F_194 ( V_35 , V_353 + 1 ) ;
}
static void F_279 ( struct V_107 * V_108 ,
struct V_34 * V_35 , T_2 type )
{
struct V_100 * V_13 ;
T_2 V_354 ;
T_2 V_350 ;
V_13 = F_69 ( V_35 -> V_37 , V_281 ) ;
F_11 ( & V_13 -> V_52 ) ;
V_354 = V_13 -> V_282 - V_13 -> V_283 - V_13 -> V_296 -
V_13 -> V_297 - V_13 -> V_298 ;
F_13 ( & V_13 -> V_52 ) ;
V_350 = F_278 ( V_35 , type ) ;
if ( V_354 < V_350 && F_237 ( V_35 , V_355 ) ) {
F_280 ( V_35 -> V_37 , L_14 ,
V_354 , V_350 , type ) ;
F_281 ( V_13 , 0 , 0 ) ;
}
if ( V_354 < V_350 ) {
T_2 V_7 ;
V_7 = F_263 ( V_35 -> V_37 -> V_332 , 0 ) ;
F_282 ( V_108 , V_35 , V_7 ) ;
}
}
static int F_267 ( struct V_107 * V_108 ,
struct V_34 * V_63 , T_2 V_7 , int V_348 )
{
struct V_100 * V_103 ;
struct V_12 * V_37 = V_63 -> V_37 ;
int V_356 = 0 ;
int V_29 = 0 ;
if ( V_108 -> V_357 )
return - V_343 ;
V_103 = F_69 ( V_63 -> V_37 , V_7 ) ;
if ( ! V_103 ) {
V_29 = F_246 ( V_63 -> V_37 , V_7 ,
0 , 0 , & V_103 ) ;
F_30 ( V_29 ) ;
}
F_30 ( ! V_103 ) ;
V_78:
F_11 ( & V_103 -> V_52 ) ;
if ( V_348 < V_103 -> V_300 )
V_348 = V_103 -> V_300 ;
if ( V_103 -> V_106 ) {
if ( F_274 ( V_63 , V_103 , V_348 ) )
V_29 = - V_343 ;
else
V_29 = 0 ;
F_13 ( & V_103 -> V_52 ) ;
return V_29 ;
}
if ( ! F_274 ( V_63 , V_103 , V_348 ) ) {
F_13 ( & V_103 -> V_52 ) ;
return 0 ;
} else if ( V_103 -> V_302 ) {
V_356 = 1 ;
} else {
V_103 -> V_302 = 1 ;
}
F_13 ( & V_103 -> V_52 ) ;
F_35 ( & V_37 -> V_358 ) ;
if ( V_356 ) {
F_46 ( & V_37 -> V_358 ) ;
V_356 = 0 ;
goto V_78;
}
V_108 -> V_357 = true ;
if ( F_283 ( V_103 ) )
V_7 |= ( V_280 | V_279 ) ;
if ( V_7 & V_280 && V_37 -> V_359 ) {
V_37 -> V_360 ++ ;
if ( ! ( V_37 -> V_360 %
V_37 -> V_359 ) )
F_272 ( V_37 ) ;
}
F_279 ( V_108 , V_63 , V_7 ) ;
V_29 = F_282 ( V_108 , V_63 , V_7 ) ;
V_108 -> V_357 = false ;
F_11 ( & V_103 -> V_52 ) ;
if ( V_29 < 0 && V_29 != - V_343 )
goto V_73;
if ( V_29 )
V_103 -> V_106 = 1 ;
else
V_29 = 1 ;
V_103 -> V_300 = V_301 ;
V_73:
V_103 -> V_302 = 0 ;
F_13 ( & V_103 -> V_52 ) ;
F_46 ( & V_37 -> V_358 ) ;
return V_29 ;
}
static int F_284 ( struct V_34 * V_35 ,
struct V_100 * V_103 , T_2 V_333 ,
enum V_361 V_303 )
{
struct V_236 * V_237 = & V_35 -> V_37 -> V_238 ;
T_2 V_362 = F_263 ( V_35 , 0 ) ;
T_2 V_363 ;
T_2 V_364 ;
T_2 V_334 ;
V_334 = V_103 -> V_283 + V_103 -> V_297 +
V_103 -> V_296 + V_103 -> V_298 ;
F_11 ( & V_237 -> V_52 ) ;
V_363 = F_273 ( V_237 ) ;
F_13 ( & V_237 -> V_52 ) ;
if ( V_334 + V_363 >= V_103 -> V_282 )
return 0 ;
V_334 += V_103 -> V_299 ;
F_11 ( & V_35 -> V_37 -> V_365 ) ;
V_364 = V_35 -> V_37 -> V_366 ;
F_13 ( & V_35 -> V_37 -> V_365 ) ;
if ( V_362 & ( V_285 |
V_286 |
V_287 ) )
V_364 >>= 1 ;
if ( V_303 == V_367 )
V_364 >>= 3 ;
else
V_364 >>= 1 ;
if ( V_334 + V_333 < V_103 -> V_282 + V_364 )
return 1 ;
return 0 ;
}
static void F_285 ( struct V_34 * V_35 ,
unsigned long V_368 , int V_369 )
{
struct V_370 * V_371 = V_35 -> V_37 -> V_371 ;
if ( F_286 ( & V_371 -> V_372 ) ) {
F_287 ( V_371 , V_368 , V_373 ) ;
F_45 ( & V_371 -> V_372 ) ;
} else {
F_288 ( V_35 -> V_37 , 0 , V_369 ) ;
if ( ! V_338 -> V_339 )
F_289 ( V_35 -> V_37 , V_369 ) ;
}
}
static inline int F_290 ( struct V_34 * V_35 , T_2 V_374 )
{
T_2 V_333 ;
int V_44 ;
V_333 = F_194 ( V_35 , 1 ) ;
V_44 = ( int ) F_181 ( V_374 , V_333 ) ;
if ( ! V_44 )
V_44 = 1 ;
return V_44 ;
}
static void F_291 ( struct V_34 * V_35 , T_2 V_374 , T_2 V_375 ,
bool V_376 )
{
struct V_236 * V_377 ;
struct V_100 * V_103 ;
struct V_107 * V_108 ;
T_2 V_378 ;
T_2 V_379 ;
long V_380 ;
unsigned long V_368 ;
int V_381 ;
int V_382 ;
enum V_361 V_303 ;
V_382 = F_290 ( V_35 , V_374 ) ;
V_374 = V_382 * V_383 ;
V_108 = (struct V_107 * ) V_338 -> V_339 ;
V_377 = & V_35 -> V_37 -> V_384 ;
V_103 = V_377 -> V_103 ;
V_378 = F_292 (
& V_35 -> V_37 -> V_378 ) ;
if ( V_378 == 0 ) {
if ( V_108 )
return;
if ( V_376 )
F_289 ( V_35 -> V_37 , V_382 ) ;
return;
}
V_381 = 0 ;
while ( V_378 && V_381 < 3 ) {
V_379 = F_293 ( V_378 , V_374 ) ;
V_368 = V_379 >> V_385 ;
F_285 ( V_35 , V_368 , V_382 ) ;
V_379 = F_196 ( & V_35 -> V_37 -> V_386 ) ;
if ( ! V_379 )
goto V_387;
if ( V_379 <= V_368 )
V_379 = 0 ;
else
V_379 -= V_368 ;
F_294 ( V_35 -> V_37 -> V_388 ,
F_196 ( & V_35 -> V_37 -> V_386 ) <=
( int ) V_379 ) ;
V_387:
if ( ! V_108 )
V_303 = V_367 ;
else
V_303 = V_389 ;
F_11 ( & V_103 -> V_52 ) ;
if ( F_284 ( V_35 , V_103 , V_375 , V_303 ) ) {
F_13 ( & V_103 -> V_52 ) ;
break;
}
F_13 ( & V_103 -> V_52 ) ;
V_381 ++ ;
if ( V_376 && ! V_108 ) {
F_289 ( V_35 -> V_37 , V_382 ) ;
} else {
V_380 = F_295 ( 1 ) ;
if ( V_380 )
break;
}
V_378 = F_292 (
& V_35 -> V_37 -> V_378 ) ;
}
}
static int F_296 ( struct V_34 * V_35 ,
struct V_100 * V_103 ,
T_2 V_333 , int V_348 )
{
struct V_236 * V_390 = & V_35 -> V_37 -> V_391 ;
struct V_107 * V_108 ;
V_108 = (struct V_107 * ) V_338 -> V_339 ;
if ( V_108 )
return - V_175 ;
if ( V_348 )
goto V_392;
if ( F_269 ( & V_103 -> V_290 ,
V_333 ) >= 0 )
goto V_392;
if ( V_103 != V_390 -> V_103 )
return - V_343 ;
F_11 ( & V_390 -> V_52 ) ;
if ( F_269 ( & V_103 -> V_290 ,
V_333 - V_390 -> V_57 ) >= 0 ) {
F_13 ( & V_390 -> V_52 ) ;
return - V_343 ;
}
F_13 ( & V_390 -> V_52 ) ;
V_392:
V_108 = F_266 ( V_35 ) ;
if ( F_229 ( V_108 ) )
return - V_343 ;
return F_270 ( V_108 , V_35 ) ;
}
static int F_297 ( struct V_34 * V_35 ,
struct V_100 * V_103 , T_2 V_36 ,
T_2 V_393 , int V_394 )
{
struct V_107 * V_108 ;
int V_44 ;
int V_29 = 0 ;
switch ( V_394 ) {
case V_395 :
case V_396 :
if ( V_394 == V_395 )
V_44 = F_290 ( V_35 , V_36 ) * 2 ;
else
V_44 = - 1 ;
V_108 = F_266 ( V_35 ) ;
if ( F_229 ( V_108 ) ) {
V_29 = F_230 ( V_108 ) ;
break;
}
V_29 = F_298 ( V_108 , V_35 , V_44 ) ;
F_268 ( V_108 , V_35 ) ;
break;
case V_397 :
case V_398 :
F_291 ( V_35 , V_36 * 2 , V_393 ,
V_394 == V_398 ) ;
break;
case V_399 :
V_108 = F_266 ( V_35 ) ;
if ( F_229 ( V_108 ) ) {
V_29 = F_230 ( V_108 ) ;
break;
}
V_29 = F_267 ( V_108 , V_35 -> V_37 -> V_63 ,
F_263 ( V_35 , 0 ) ,
V_301 ) ;
F_268 ( V_108 , V_35 ) ;
if ( V_29 == - V_343 )
V_29 = 0 ;
break;
case V_400 :
V_29 = F_296 ( V_35 , V_103 , V_393 , 0 ) ;
break;
default:
V_29 = - V_343 ;
break;
}
return V_29 ;
}
static int F_299 ( struct V_34 * V_35 ,
struct V_236 * V_377 ,
T_2 V_393 ,
enum V_361 V_303 )
{
struct V_100 * V_103 = V_377 -> V_103 ;
T_2 V_334 ;
T_2 V_36 = V_393 ;
int V_401 = V_395 ;
int V_29 = 0 ;
bool V_402 = false ;
V_78:
V_29 = 0 ;
F_11 ( & V_103 -> V_52 ) ;
while ( V_303 == V_367 && ! V_402 &&
V_103 -> V_303 ) {
F_13 ( & V_103 -> V_52 ) ;
if ( V_338 -> V_339 )
return - V_175 ;
V_29 = F_300 ( V_103 -> V_89 , ! V_103 -> V_303 ) ;
if ( V_29 )
return - V_403 ;
F_11 ( & V_103 -> V_52 ) ;
}
V_29 = - V_343 ;
V_334 = V_103 -> V_283 + V_103 -> V_297 +
V_103 -> V_296 + V_103 -> V_298 +
V_103 -> V_299 ;
if ( V_334 <= V_103 -> V_282 ) {
if ( V_334 + V_393 <= V_103 -> V_282 ) {
V_103 -> V_299 += V_393 ;
F_271 ( V_35 -> V_37 ,
L_13 , V_103 -> V_7 , V_393 , 1 ) ;
V_29 = 0 ;
} else {
V_36 = V_393 ;
}
} else {
V_36 = V_334 - V_103 -> V_282 +
( V_393 * 2 ) ;
}
if ( V_29 && F_284 ( V_35 , V_103 , V_393 , V_303 ) ) {
V_103 -> V_299 += V_393 ;
F_271 ( V_35 -> V_37 , L_13 ,
V_103 -> V_7 , V_393 ,
1 ) ;
V_29 = 0 ;
}
if ( V_29 && V_303 != V_389 ) {
V_402 = true ;
V_103 -> V_303 = 1 ;
}
F_13 ( & V_103 -> V_52 ) ;
if ( ! V_29 || V_303 == V_389 )
goto V_73;
V_29 = F_297 ( V_35 , V_103 , V_36 , V_393 ,
V_401 ) ;
V_401 ++ ;
if ( V_303 == V_404 &&
( V_401 == V_397 ||
V_401 == V_398 ) )
V_401 = V_399 ;
if ( ! V_29 )
goto V_78;
else if ( V_303 == V_404 &&
V_401 < V_400 )
goto V_78;
else if ( V_303 == V_367 &&
V_401 <= V_400 )
goto V_78;
V_73:
if ( V_29 == - V_343 &&
F_301 ( V_35 -> V_405 == V_406 ) ) {
struct V_236 * V_237 =
& V_35 -> V_37 -> V_238 ;
if ( V_377 != V_237 &&
! F_302 ( V_237 , V_393 ) )
V_29 = 0 ;
}
if ( V_29 == - V_343 )
F_271 ( V_35 -> V_37 ,
L_12 ,
V_103 -> V_7 , V_393 , 1 ) ;
if ( V_402 ) {
F_11 ( & V_103 -> V_52 ) ;
V_103 -> V_303 = 0 ;
F_303 ( & V_103 -> V_89 ) ;
F_13 ( & V_103 -> V_52 ) ;
}
return V_29 ;
}
static struct V_236 * F_304 (
const struct V_107 * V_108 ,
const struct V_34 * V_35 )
{
struct V_236 * V_377 = NULL ;
if ( V_35 -> V_255 )
V_377 = V_108 -> V_377 ;
if ( V_35 == V_35 -> V_37 -> V_407 && V_108 -> V_408 )
V_377 = V_108 -> V_377 ;
if ( V_35 == V_35 -> V_37 -> V_409 )
V_377 = V_108 -> V_377 ;
if ( ! V_377 )
V_377 = V_35 -> V_377 ;
if ( ! V_377 )
V_377 = & V_35 -> V_37 -> V_410 ;
return V_377 ;
}
static int F_302 ( struct V_236 * V_377 ,
T_2 V_36 )
{
int V_29 = - V_343 ;
F_11 ( & V_377 -> V_52 ) ;
if ( V_377 -> V_10 >= V_36 ) {
V_377 -> V_10 -= V_36 ;
if ( V_377 -> V_10 < V_377 -> V_57 )
V_377 -> V_106 = 0 ;
V_29 = 0 ;
}
F_13 ( & V_377 -> V_52 ) ;
return V_29 ;
}
static void F_305 ( struct V_236 * V_377 ,
T_2 V_36 , int V_411 )
{
F_11 ( & V_377 -> V_52 ) ;
V_377 -> V_10 += V_36 ;
if ( V_411 )
V_377 -> V_57 += V_36 ;
else if ( V_377 -> V_10 >= V_377 -> V_57 )
V_377 -> V_106 = 1 ;
F_13 ( & V_377 -> V_52 ) ;
}
int F_306 ( struct V_12 * V_37 ,
struct V_236 * V_412 , T_2 V_36 ,
int V_413 )
{
struct V_236 * V_237 = & V_37 -> V_238 ;
T_2 V_414 ;
if ( V_237 -> V_103 != V_412 -> V_103 )
return - V_343 ;
F_11 ( & V_237 -> V_52 ) ;
V_414 = F_277 ( V_237 -> V_57 , V_413 ) ;
if ( V_237 -> V_10 < V_414 + V_36 ) {
F_13 ( & V_237 -> V_52 ) ;
return - V_343 ;
}
V_237 -> V_10 -= V_36 ;
if ( V_237 -> V_10 < V_237 -> V_57 )
V_237 -> V_106 = 0 ;
F_13 ( & V_237 -> V_52 ) ;
F_305 ( V_412 , V_36 , 1 ) ;
return 0 ;
}
static void F_307 ( struct V_12 * V_37 ,
struct V_236 * V_377 ,
struct V_236 * V_412 , T_2 V_36 )
{
struct V_100 * V_103 = V_377 -> V_103 ;
F_11 ( & V_377 -> V_52 ) ;
if ( V_36 == ( T_2 ) - 1 )
V_36 = V_377 -> V_57 ;
V_377 -> V_57 -= V_36 ;
if ( V_377 -> V_10 >= V_377 -> V_57 ) {
V_36 = V_377 -> V_10 - V_377 -> V_57 ;
V_377 -> V_10 = V_377 -> V_57 ;
V_377 -> V_106 = 1 ;
} else {
V_36 = 0 ;
}
F_13 ( & V_377 -> V_52 ) ;
if ( V_36 > 0 ) {
if ( V_412 ) {
F_11 ( & V_412 -> V_52 ) ;
if ( ! V_412 -> V_106 ) {
T_2 V_415 ;
V_415 = V_412 -> V_57 - V_412 -> V_10 ;
V_415 = F_293 ( V_36 , V_415 ) ;
V_412 -> V_10 += V_415 ;
if ( V_412 -> V_10 >= V_412 -> V_57 )
V_412 -> V_106 = 1 ;
V_36 -= V_415 ;
}
F_13 ( & V_412 -> V_52 ) ;
}
if ( V_36 ) {
F_11 ( & V_103 -> V_52 ) ;
V_103 -> V_299 -= V_36 ;
F_271 ( V_37 , L_13 ,
V_103 -> V_7 , V_36 , 0 ) ;
F_13 ( & V_103 -> V_52 ) ;
}
}
}
static int F_308 ( struct V_236 * V_416 ,
struct V_236 * V_417 , T_2 V_36 )
{
int V_29 ;
V_29 = F_302 ( V_416 , V_36 ) ;
if ( V_29 )
return V_29 ;
F_305 ( V_417 , V_36 , 1 ) ;
return 0 ;
}
void F_309 ( struct V_236 * V_418 , unsigned short type )
{
memset ( V_418 , 0 , sizeof( * V_418 ) ) ;
F_250 ( & V_418 -> V_52 ) ;
V_418 -> type = type ;
}
struct V_236 * F_310 ( struct V_34 * V_35 ,
unsigned short type )
{
struct V_236 * V_377 ;
struct V_12 * V_37 = V_35 -> V_37 ;
V_377 = F_311 ( sizeof( * V_377 ) , V_40 ) ;
if ( ! V_377 )
return NULL ;
F_309 ( V_377 , type ) ;
V_377 -> V_103 = F_69 ( V_37 ,
V_279 ) ;
return V_377 ;
}
void F_312 ( struct V_34 * V_35 ,
struct V_236 * V_418 )
{
if ( ! V_418 )
return;
F_313 ( V_35 , V_418 , ( T_2 ) - 1 ) ;
F_9 ( V_418 ) ;
}
int F_314 ( struct V_34 * V_35 ,
struct V_236 * V_377 , T_2 V_36 ,
enum V_361 V_303 )
{
int V_29 ;
if ( V_36 == 0 )
return 0 ;
V_29 = F_299 ( V_35 , V_377 , V_36 , V_303 ) ;
if ( ! V_29 ) {
F_305 ( V_377 , V_36 , 1 ) ;
return 0 ;
}
return V_29 ;
}
int F_315 ( struct V_34 * V_35 ,
struct V_236 * V_377 , int V_413 )
{
T_2 V_36 = 0 ;
int V_29 = - V_343 ;
if ( ! V_377 )
return 0 ;
F_11 ( & V_377 -> V_52 ) ;
V_36 = F_277 ( V_377 -> V_57 , V_413 ) ;
if ( V_377 -> V_10 >= V_36 )
V_29 = 0 ;
F_13 ( & V_377 -> V_52 ) ;
return V_29 ;
}
int F_316 ( struct V_34 * V_35 ,
struct V_236 * V_377 , T_2 V_419 ,
enum V_361 V_303 )
{
T_2 V_36 = 0 ;
int V_29 = - V_343 ;
if ( ! V_377 )
return 0 ;
F_11 ( & V_377 -> V_52 ) ;
V_36 = V_419 ;
if ( V_377 -> V_10 >= V_36 )
V_29 = 0 ;
else
V_36 -= V_377 -> V_10 ;
F_13 ( & V_377 -> V_52 ) ;
if ( ! V_29 )
return 0 ;
V_29 = F_299 ( V_35 , V_377 , V_36 , V_303 ) ;
if ( ! V_29 ) {
F_305 ( V_377 , V_36 , 0 ) ;
return 0 ;
}
return V_29 ;
}
int F_317 ( struct V_236 * V_420 ,
struct V_236 * V_421 ,
T_2 V_36 )
{
return F_308 ( V_420 , V_421 , V_36 ) ;
}
void F_313 ( struct V_34 * V_35 ,
struct V_236 * V_377 ,
T_2 V_36 )
{
struct V_236 * V_237 = & V_35 -> V_37 -> V_238 ;
if ( V_237 == V_377 ||
V_377 -> V_103 != V_237 -> V_103 )
V_237 = NULL ;
F_307 ( V_35 -> V_37 , V_377 , V_237 ,
V_36 ) ;
}
static T_2 F_318 ( struct V_12 * V_37 )
{
struct V_100 * V_347 ;
T_2 V_36 ;
T_2 V_422 ;
T_2 V_423 ;
int V_424 = F_319 ( V_37 -> V_352 ) ;
V_347 = F_69 ( V_37 , V_280 ) ;
F_11 ( & V_347 -> V_52 ) ;
V_423 = V_347 -> V_283 ;
F_13 ( & V_347 -> V_52 ) ;
V_347 = F_69 ( V_37 , V_279 ) ;
F_11 ( & V_347 -> V_52 ) ;
if ( V_347 -> V_7 & V_280 )
V_423 = 0 ;
V_422 = V_347 -> V_283 ;
F_13 ( & V_347 -> V_52 ) ;
V_36 = ( V_423 >> V_37 -> V_371 -> V_425 ) *
V_424 * 2 ;
V_36 += F_181 ( V_423 + V_422 , 50 ) ;
if ( V_36 * 3 > V_422 )
V_36 = F_181 ( V_422 , 3 ) ;
return F_264 ( V_36 , V_37 -> V_63 -> V_88 << 10 ) ;
}
static void F_320 ( struct V_12 * V_37 )
{
struct V_236 * V_377 = & V_37 -> V_238 ;
struct V_100 * V_347 = V_377 -> V_103 ;
T_2 V_36 ;
V_36 = F_318 ( V_37 ) ;
F_11 ( & V_347 -> V_52 ) ;
F_11 ( & V_377 -> V_52 ) ;
V_377 -> V_57 = F_24 ( T_2 , V_36 , 512 * 1024 * 1024 ) ;
V_36 = V_347 -> V_283 + V_347 -> V_296 +
V_347 -> V_297 + V_347 -> V_298 +
V_347 -> V_299 ;
if ( V_347 -> V_282 > V_36 ) {
V_36 = V_347 -> V_282 - V_36 ;
V_377 -> V_10 += V_36 ;
V_347 -> V_299 += V_36 ;
F_271 ( V_37 , L_13 ,
V_347 -> V_7 , V_36 , 1 ) ;
}
if ( V_377 -> V_10 >= V_377 -> V_57 ) {
V_36 = V_377 -> V_10 - V_377 -> V_57 ;
V_347 -> V_299 -= V_36 ;
F_271 ( V_37 , L_13 ,
V_347 -> V_7 , V_36 , 0 ) ;
V_377 -> V_10 = V_377 -> V_57 ;
V_377 -> V_106 = 1 ;
}
F_13 ( & V_377 -> V_52 ) ;
F_13 ( & V_347 -> V_52 ) ;
}
static void F_321 ( struct V_12 * V_37 )
{
struct V_100 * V_103 ;
V_103 = F_69 ( V_37 , V_281 ) ;
V_37 -> V_426 . V_103 = V_103 ;
V_103 = F_69 ( V_37 , V_279 ) ;
V_37 -> V_238 . V_103 = V_103 ;
V_37 -> V_384 . V_103 = V_103 ;
V_37 -> V_427 . V_103 = V_103 ;
V_37 -> V_410 . V_103 = V_103 ;
V_37 -> V_391 . V_103 = V_103 ;
V_37 -> V_63 -> V_377 = & V_37 -> V_238 ;
V_37 -> V_407 -> V_377 = & V_37 -> V_238 ;
V_37 -> V_428 -> V_377 = & V_37 -> V_238 ;
V_37 -> V_87 -> V_377 = & V_37 -> V_238 ;
if ( V_37 -> V_429 )
V_37 -> V_429 -> V_377 = & V_37 -> V_238 ;
V_37 -> V_332 -> V_377 = & V_37 -> V_426 ;
F_320 ( V_37 ) ;
}
static void F_322 ( struct V_12 * V_37 )
{
F_307 ( V_37 , & V_37 -> V_238 , NULL ,
( T_2 ) - 1 ) ;
F_8 ( V_37 -> V_384 . V_57 > 0 ) ;
F_8 ( V_37 -> V_384 . V_10 > 0 ) ;
F_8 ( V_37 -> V_427 . V_57 > 0 ) ;
F_8 ( V_37 -> V_427 . V_10 > 0 ) ;
F_8 ( V_37 -> V_426 . V_57 > 0 ) ;
F_8 ( V_37 -> V_426 . V_10 > 0 ) ;
F_8 ( V_37 -> V_391 . V_57 > 0 ) ;
F_8 ( V_37 -> V_391 . V_10 > 0 ) ;
}
void F_323 ( struct V_107 * V_108 ,
struct V_34 * V_35 )
{
if ( ! V_108 -> V_377 )
return;
if ( ! V_108 -> V_297 )
return;
F_271 ( V_35 -> V_37 , L_15 ,
V_108 -> V_269 , V_108 -> V_297 , 0 ) ;
F_313 ( V_35 , V_108 -> V_377 , V_108 -> V_297 ) ;
V_108 -> V_297 = 0 ;
}
int F_324 ( struct V_107 * V_108 ,
struct V_259 * V_259 )
{
struct V_34 * V_35 = F_233 ( V_259 ) -> V_35 ;
struct V_236 * V_420 = F_304 ( V_108 , V_35 ) ;
struct V_236 * V_421 = V_35 -> V_430 ;
T_2 V_36 = F_194 ( V_35 , 1 ) ;
F_271 ( V_35 -> V_37 , L_16 ,
F_325 ( V_259 ) , V_36 , 1 ) ;
return F_308 ( V_420 , V_421 , V_36 ) ;
}
void F_326 ( struct V_259 * V_259 )
{
struct V_34 * V_35 = F_233 ( V_259 ) -> V_35 ;
T_2 V_36 = F_194 ( V_35 , 1 ) ;
F_271 ( V_35 -> V_37 , L_16 ,
F_325 ( V_259 ) , V_36 , 0 ) ;
F_313 ( V_35 , V_35 -> V_430 , V_36 ) ;
}
int F_327 ( struct V_34 * V_35 ,
struct V_236 * V_418 ,
int V_382 ,
T_2 * V_431 ,
bool V_432 )
{
T_2 V_36 ;
int V_29 ;
struct V_236 * V_237 = & V_35 -> V_37 -> V_238 ;
if ( V_35 -> V_37 -> V_433 ) {
V_36 = 3 * V_35 -> V_88 ;
V_29 = F_328 ( V_35 , V_36 ) ;
if ( V_29 )
return V_29 ;
} else {
V_36 = 0 ;
}
* V_431 = V_36 ;
V_36 = F_194 ( V_35 , V_382 ) ;
V_418 -> V_103 = F_69 ( V_35 -> V_37 ,
V_279 ) ;
V_29 = F_314 ( V_35 , V_418 , V_36 ,
V_367 ) ;
if ( V_29 == - V_343 && V_432 )
V_29 = F_317 ( V_237 , V_418 , V_36 ) ;
if ( V_29 ) {
if ( * V_431 )
F_329 ( V_35 , * V_431 ) ;
}
return V_29 ;
}
void F_330 ( struct V_34 * V_35 ,
struct V_236 * V_418 ,
T_2 V_431 )
{
F_313 ( V_35 , V_418 , ( T_2 ) - 1 ) ;
if ( V_431 )
F_329 ( V_35 , V_431 ) ;
}
static unsigned F_331 ( struct V_259 * V_259 )
{
unsigned V_434 = 0 ;
unsigned V_435 = 0 ;
F_30 ( ! F_233 ( V_259 ) -> V_436 ) ;
F_233 ( V_259 ) -> V_436 -- ;
if ( F_233 ( V_259 ) -> V_436 == 0 &&
F_332 ( V_437 ,
& F_233 ( V_259 ) -> V_438 ) )
V_434 = 1 ;
if ( F_233 ( V_259 ) -> V_436 >=
F_233 ( V_259 ) -> V_439 )
return V_434 ;
V_435 = F_233 ( V_259 ) -> V_439 -
F_233 ( V_259 ) -> V_436 ;
F_233 ( V_259 ) -> V_439 -= V_435 ;
return V_435 + V_434 ;
}
static T_2 F_333 ( struct V_259 * V_259 , T_2 V_36 ,
int V_440 )
{
struct V_34 * V_35 = F_233 ( V_259 ) -> V_35 ;
T_2 V_424 ;
int V_441 ;
int V_442 ;
int V_443 ;
if ( F_233 ( V_259 ) -> V_7 & V_444 &&
F_233 ( V_259 ) -> V_445 == 0 )
return 0 ;
V_443 = ( int ) F_181 ( F_233 ( V_259 ) -> V_445 , V_35 -> V_337 ) ;
if ( V_440 )
F_233 ( V_259 ) -> V_445 += V_36 ;
else
F_233 ( V_259 ) -> V_445 -= V_36 ;
V_424 = F_192 ( V_35 ) - sizeof( struct V_446 ) ;
V_441 = ( int ) F_181 ( V_424 ,
sizeof( struct V_447 ) +
sizeof( struct V_448 ) ) ;
V_442 = ( int ) F_181 ( F_233 ( V_259 ) -> V_445 , V_35 -> V_337 ) ;
V_442 = V_442 + V_441 - 1 ;
V_442 = V_442 / V_441 ;
V_443 = V_443 + V_441 - 1 ;
V_443 = V_443 / V_441 ;
if ( V_443 == V_442 )
return 0 ;
if ( V_440 )
return F_194 ( V_35 ,
V_442 - V_443 ) ;
return F_194 ( V_35 , V_443 - V_442 ) ;
}
int F_334 ( struct V_259 * V_259 , T_2 V_36 )
{
struct V_34 * V_35 = F_233 ( V_259 ) -> V_35 ;
struct V_236 * V_377 = & V_35 -> V_37 -> V_384 ;
T_2 V_449 = 0 ;
T_2 V_445 ;
unsigned V_450 = 0 ;
int V_451 = 0 ;
enum V_361 V_303 = V_367 ;
int V_29 = 0 ;
bool V_452 = true ;
T_2 V_453 = 0 ;
unsigned V_454 ;
if ( F_265 ( V_259 ) ) {
V_303 = V_389 ;
V_452 = false ;
}
if ( V_303 != V_389 &&
F_335 ( V_35 -> V_37 ) )
F_336 ( 1 ) ;
if ( V_452 )
F_35 ( & F_233 ( V_259 ) -> V_455 ) ;
V_36 = F_264 ( V_36 , V_35 -> V_337 ) ;
F_11 ( & F_233 ( V_259 ) -> V_52 ) ;
F_233 ( V_259 ) -> V_436 ++ ;
if ( F_233 ( V_259 ) -> V_436 >
F_233 ( V_259 ) -> V_439 )
V_450 = F_233 ( V_259 ) -> V_436 -
F_233 ( V_259 ) -> V_439 ;
if ( ! F_337 ( V_437 ,
& F_233 ( V_259 ) -> V_438 ) ) {
V_450 ++ ;
V_451 = 1 ;
}
V_449 = F_194 ( V_35 , V_450 ) ;
V_449 += F_333 ( V_259 , V_36 , 1 ) ;
V_445 = F_233 ( V_259 ) -> V_445 ;
F_13 ( & F_233 ( V_259 ) -> V_52 ) ;
if ( V_35 -> V_37 -> V_433 ) {
V_29 = F_328 ( V_35 , V_36 +
V_450 * V_35 -> V_88 ) ;
if ( V_29 )
goto V_456;
}
V_29 = F_299 ( V_35 , V_377 , V_449 , V_303 ) ;
if ( F_301 ( V_29 ) ) {
if ( V_35 -> V_37 -> V_433 )
F_329 ( V_35 , V_36 +
V_450 * V_35 -> V_88 ) ;
goto V_456;
}
F_11 ( & F_233 ( V_259 ) -> V_52 ) ;
if ( V_451 ) {
F_338 ( V_437 ,
& F_233 ( V_259 ) -> V_438 ) ;
V_450 -- ;
}
F_233 ( V_259 ) -> V_439 += V_450 ;
F_13 ( & F_233 ( V_259 ) -> V_52 ) ;
if ( V_452 )
F_46 ( & F_233 ( V_259 ) -> V_455 ) ;
if ( V_449 )
F_271 ( V_35 -> V_37 , L_17 ,
F_325 ( V_259 ) , V_449 , 1 ) ;
F_305 ( V_377 , V_449 , 1 ) ;
return 0 ;
V_456:
F_11 ( & F_233 ( V_259 ) -> V_52 ) ;
V_454 = F_331 ( V_259 ) ;
if ( F_233 ( V_259 ) -> V_445 == V_445 ) {
F_333 ( V_259 , V_36 , 0 ) ;
} else {
T_2 V_457 = F_233 ( V_259 ) -> V_445 ;
T_2 V_333 ;
V_333 = V_445 - F_233 ( V_259 ) -> V_445 ;
F_233 ( V_259 ) -> V_445 = V_445 ;
V_453 = F_333 ( V_259 , V_333 , 0 ) ;
F_233 ( V_259 ) -> V_445 = V_445 - V_36 ;
V_333 = V_445 - V_457 ;
V_333 = F_333 ( V_259 , V_333 , 0 ) ;
F_233 ( V_259 ) -> V_445 = V_457 - V_36 ;
if ( V_333 > V_453 )
V_453 = V_333 - V_453 ;
else
V_453 = 0 ;
}
F_13 ( & F_233 ( V_259 ) -> V_52 ) ;
if ( V_454 )
V_453 += F_194 ( V_35 , V_454 ) ;
if ( V_453 ) {
F_313 ( V_35 , V_377 , V_453 ) ;
F_271 ( V_35 -> V_37 , L_17 ,
F_325 ( V_259 ) , V_453 , 0 ) ;
}
if ( V_452 )
F_46 ( & F_233 ( V_259 ) -> V_455 ) ;
return V_29 ;
}
void F_339 ( struct V_259 * V_259 , T_2 V_36 )
{
struct V_34 * V_35 = F_233 ( V_259 ) -> V_35 ;
T_2 V_453 = 0 ;
unsigned V_454 ;
V_36 = F_264 ( V_36 , V_35 -> V_337 ) ;
F_11 ( & F_233 ( V_259 ) -> V_52 ) ;
V_454 = F_331 ( V_259 ) ;
if ( V_36 )
V_453 = F_333 ( V_259 , V_36 , 0 ) ;
F_13 ( & F_233 ( V_259 ) -> V_52 ) ;
if ( V_454 > 0 )
V_453 += F_194 ( V_35 , V_454 ) ;
F_271 ( V_35 -> V_37 , L_17 ,
F_325 ( V_259 ) , V_453 , 0 ) ;
if ( V_35 -> V_37 -> V_433 ) {
F_329 ( V_35 , V_36 +
V_454 * V_35 -> V_88 ) ;
}
F_313 ( V_35 , & V_35 -> V_37 -> V_384 ,
V_453 ) ;
}
int F_340 ( struct V_259 * V_259 , T_2 V_36 )
{
int V_29 ;
V_29 = F_238 ( V_259 , V_36 ) ;
if ( V_29 )
return V_29 ;
V_29 = F_334 ( V_259 , V_36 ) ;
if ( V_29 ) {
F_240 ( V_259 , V_36 ) ;
return V_29 ;
}
return 0 ;
}
void F_341 ( struct V_259 * V_259 , T_2 V_36 )
{
F_339 ( V_259 , V_36 ) ;
F_240 ( V_259 , V_36 ) ;
}
static int F_342 ( struct V_34 * V_35 ,
T_2 V_27 , T_2 V_36 , int V_340 )
{
struct V_1 * V_2 = NULL ;
struct V_12 * V_13 = V_35 -> V_37 ;
T_2 V_458 = V_36 ;
T_2 V_459 ;
T_2 V_460 ;
int V_284 ;
F_11 ( & V_13 -> V_461 ) ;
V_459 = F_343 ( V_13 -> V_352 ) ;
if ( V_340 )
V_459 += V_36 ;
else
V_459 -= V_36 ;
F_344 ( V_13 -> V_352 , V_459 ) ;
F_13 ( & V_13 -> V_461 ) ;
while ( V_458 ) {
V_2 = F_68 ( V_13 , V_27 ) ;
if ( ! V_2 )
return - V_151 ;
if ( V_2 -> V_7 & ( V_285 |
V_286 |
V_287 ) )
V_284 = 2 ;
else
V_284 = 1 ;
if ( ! V_340 && V_2 -> V_3 == V_94 )
F_51 ( V_2 , 1 ) ;
V_460 = V_27 - V_2 -> V_21 . V_22 ;
F_8 ( V_460 > V_2 -> V_21 . V_33 ) ;
F_11 ( & V_2 -> V_103 -> V_52 ) ;
F_11 ( & V_2 -> V_52 ) ;
if ( F_237 ( V_35 , V_273 ) &&
V_2 -> V_265 < V_275 )
V_2 -> V_265 = V_275 ;
V_2 -> V_276 = 1 ;
V_459 = F_345 ( & V_2 -> V_133 ) ;
V_36 = F_293 ( V_458 , V_2 -> V_21 . V_33 - V_460 ) ;
if ( V_340 ) {
V_459 += V_36 ;
F_346 ( & V_2 -> V_133 , V_459 ) ;
V_2 -> V_10 -= V_36 ;
V_2 -> V_103 -> V_297 -= V_36 ;
V_2 -> V_103 -> V_283 += V_36 ;
V_2 -> V_103 -> V_289 += V_36 * V_284 ;
F_13 ( & V_2 -> V_52 ) ;
F_13 ( & V_2 -> V_103 -> V_52 ) ;
} else {
V_459 -= V_36 ;
F_346 ( & V_2 -> V_133 , V_459 ) ;
V_2 -> V_9 += V_36 ;
V_2 -> V_103 -> V_296 += V_36 ;
V_2 -> V_103 -> V_283 -= V_36 ;
V_2 -> V_103 -> V_289 -= V_36 * V_284 ;
F_13 ( & V_2 -> V_52 ) ;
F_13 ( & V_2 -> V_103 -> V_52 ) ;
F_347 ( V_13 -> V_59 ,
V_27 , V_27 + V_36 - 1 ,
V_40 | V_462 ) ;
}
F_6 ( V_2 ) ;
V_458 -= V_36 ;
V_27 += V_36 ;
}
return 0 ;
}
static T_2 V_26 ( struct V_34 * V_35 , T_2 V_463 )
{
struct V_1 * V_2 ;
T_2 V_27 ;
F_11 ( & V_35 -> V_37 -> V_18 ) ;
V_27 = V_35 -> V_37 -> V_26 ;
F_13 ( & V_35 -> V_37 -> V_18 ) ;
if ( V_27 < ( T_2 ) - 1 )
return V_27 ;
V_2 = F_67 ( V_35 -> V_37 , V_463 ) ;
if ( ! V_2 )
return 0 ;
V_27 = V_2 -> V_21 . V_22 ;
F_6 ( V_2 ) ;
return V_27 ;
}
static int F_348 ( struct V_34 * V_35 ,
struct V_1 * V_2 ,
T_2 V_27 , T_2 V_36 , int V_10 )
{
F_11 ( & V_2 -> V_103 -> V_52 ) ;
F_11 ( & V_2 -> V_52 ) ;
V_2 -> V_9 += V_36 ;
V_2 -> V_103 -> V_296 += V_36 ;
if ( V_10 ) {
V_2 -> V_10 -= V_36 ;
V_2 -> V_103 -> V_297 -= V_36 ;
}
F_13 ( & V_2 -> V_52 ) ;
F_13 ( & V_2 -> V_103 -> V_52 ) ;
F_347 ( V_35 -> V_37 -> V_59 , V_27 ,
V_27 + V_36 - 1 , V_40 | V_462 ) ;
if ( V_10 )
F_349 ( V_35 , V_27 , V_36 ) ;
return 0 ;
}
int F_161 ( struct V_34 * V_35 ,
T_2 V_27 , T_2 V_36 , int V_10 )
{
struct V_1 * V_2 ;
V_2 = F_68 ( V_35 -> V_37 , V_27 ) ;
F_30 ( ! V_2 ) ;
F_348 ( V_35 , V_2 , V_27 , V_36 , V_10 ) ;
F_6 ( V_2 ) ;
return 0 ;
}
int F_350 ( struct V_34 * V_35 ,
T_2 V_27 , T_2 V_36 )
{
struct V_1 * V_2 ;
int V_29 ;
V_2 = F_68 ( V_35 -> V_37 , V_27 ) ;
if ( ! V_2 )
return - V_464 ;
F_51 ( V_2 , 1 ) ;
F_348 ( V_35 , V_2 , V_27 , V_36 , 0 ) ;
V_29 = F_351 ( V_2 , V_27 , V_36 ) ;
F_6 ( V_2 ) ;
return V_29 ;
}
static int F_352 ( struct V_34 * V_35 , T_2 V_32 , T_2 V_36 )
{
int V_29 ;
struct V_1 * V_14 ;
struct V_50 * V_54 ;
V_14 = F_68 ( V_35 -> V_37 , V_32 ) ;
if ( ! V_14 )
return - V_464 ;
F_51 ( V_14 , 0 ) ;
V_54 = F_25 ( V_14 ) ;
if ( ! V_54 ) {
F_30 ( ! F_1 ( V_14 ) ) ;
V_29 = F_351 ( V_14 , V_32 , V_36 ) ;
} else {
F_35 ( & V_54 -> V_79 ) ;
if ( V_32 >= V_54 -> V_85 ) {
V_29 = F_17 ( V_35 , V_32 , V_36 ) ;
} else if ( V_32 + V_36 <= V_54 -> V_85 ) {
V_29 = F_351 ( V_14 ,
V_32 , V_36 ) ;
} else {
V_36 = V_54 -> V_85 - V_32 ;
V_29 = F_351 ( V_14 ,
V_32 , V_36 ) ;
if ( V_29 )
goto V_465;
V_36 = ( V_32 + V_36 ) -
V_54 -> V_85 ;
V_32 = V_54 -> V_85 ;
V_29 = F_17 ( V_35 , V_32 , V_36 ) ;
}
V_465:
F_46 ( & V_54 -> V_79 ) ;
F_26 ( V_54 ) ;
}
F_6 ( V_14 ) ;
return V_29 ;
}
int F_353 ( struct V_34 * log ,
struct V_66 * V_466 )
{
struct V_253 * V_133 ;
struct V_68 V_21 ;
int V_467 ;
int V_43 ;
if ( ! F_76 ( log -> V_37 , V_468 ) )
return 0 ;
for ( V_43 = 0 ; V_43 < F_38 ( V_466 ) ; V_43 ++ ) {
F_40 ( V_466 , & V_21 , V_43 ) ;
if ( V_21 . type != V_257 )
continue;
V_133 = F_78 ( V_466 , V_43 , struct V_253 ) ;
V_467 = F_215 ( V_466 , V_133 ) ;
if ( V_467 == V_258 )
continue;
if ( F_216 ( V_466 , V_133 ) == 0 )
continue;
V_21 . V_22 = F_216 ( V_466 , V_133 ) ;
V_21 . V_33 = F_217 ( V_466 , V_133 ) ;
F_352 ( log , V_21 . V_22 , V_21 . V_33 ) ;
}
return 0 ;
}
static int F_354 ( struct V_1 * V_2 ,
T_2 V_36 , int V_440 )
{
struct V_100 * V_103 = V_2 -> V_103 ;
int V_29 = 0 ;
F_11 ( & V_103 -> V_52 ) ;
F_11 ( & V_2 -> V_52 ) ;
if ( V_440 != V_469 ) {
if ( V_2 -> V_267 ) {
V_29 = - V_175 ;
} else {
V_2 -> V_10 += V_36 ;
V_103 -> V_297 += V_36 ;
if ( V_440 == V_470 ) {
F_271 ( V_2 -> V_37 ,
L_13 , V_103 -> V_7 ,
V_36 , 0 ) ;
V_103 -> V_299 -= V_36 ;
}
}
} else {
if ( V_2 -> V_267 )
V_103 -> V_298 += V_36 ;
V_2 -> V_10 -= V_36 ;
V_103 -> V_297 -= V_36 ;
}
F_13 ( & V_2 -> V_52 ) ;
F_13 ( & V_103 -> V_52 ) ;
return V_29 ;
}
void F_355 ( struct V_107 * V_108 ,
struct V_34 * V_35 )
{
struct V_12 * V_37 = V_35 -> V_37 ;
struct V_50 * V_81 ;
struct V_50 * V_54 ;
struct V_1 * V_2 ;
struct V_100 * V_103 ;
F_63 ( & V_37 -> V_80 ) ;
F_356 (caching_ctl, next,
&fs_info->caching_block_groups, list) {
V_2 = V_54 -> V_14 ;
if ( F_1 ( V_2 ) ) {
V_2 -> V_97 = ( T_2 ) - 1 ;
F_357 ( & V_54 -> V_91 ) ;
F_26 ( V_54 ) ;
} else {
V_2 -> V_97 = V_54 -> V_85 ;
}
}
if ( V_37 -> V_59 == & V_37 -> V_38 [ 0 ] )
V_37 -> V_59 = & V_37 -> V_38 [ 1 ] ;
else
V_37 -> V_59 = & V_37 -> V_38 [ 0 ] ;
F_65 ( & V_37 -> V_80 ) ;
F_71 (space_info, &fs_info->space_info, list)
F_358 ( & V_103 -> V_290 , 0 ) ;
F_320 ( V_37 ) ;
}
static int F_359 ( struct V_34 * V_35 , T_2 V_32 , T_2 V_31 )
{
struct V_12 * V_37 = V_35 -> V_37 ;
struct V_1 * V_2 = NULL ;
struct V_100 * V_103 ;
struct V_236 * V_237 = & V_37 -> V_238 ;
T_2 V_49 ;
bool V_278 ;
while ( V_32 <= V_31 ) {
V_278 = false ;
if ( ! V_2 ||
V_32 >= V_2 -> V_21 . V_22 + V_2 -> V_21 . V_33 ) {
if ( V_2 )
F_6 ( V_2 ) ;
V_2 = F_68 ( V_37 , V_32 ) ;
F_30 ( ! V_2 ) ;
}
V_49 = V_2 -> V_21 . V_22 + V_2 -> V_21 . V_33 - V_32 ;
V_49 = F_293 ( V_49 , V_31 + 1 - V_32 ) ;
if ( V_32 < V_2 -> V_97 ) {
V_49 = F_293 ( V_49 , V_2 -> V_97 - V_32 ) ;
F_29 ( V_2 , V_32 , V_49 ) ;
}
V_32 += V_49 ;
V_103 = V_2 -> V_103 ;
F_11 ( & V_103 -> V_52 ) ;
F_11 ( & V_2 -> V_52 ) ;
V_2 -> V_9 -= V_49 ;
V_103 -> V_296 -= V_49 ;
if ( V_2 -> V_267 ) {
V_103 -> V_298 += V_49 ;
V_278 = true ;
}
F_13 ( & V_2 -> V_52 ) ;
if ( ! V_278 && V_237 -> V_103 == V_103 ) {
F_11 ( & V_237 -> V_52 ) ;
if ( ! V_237 -> V_106 ) {
V_49 = F_293 ( V_49 , V_237 -> V_57 -
V_237 -> V_10 ) ;
V_237 -> V_10 += V_49 ;
V_103 -> V_299 += V_49 ;
if ( V_237 -> V_10 >= V_237 -> V_57 )
V_237 -> V_106 = 1 ;
}
F_13 ( & V_237 -> V_52 ) ;
}
F_13 ( & V_103 -> V_52 ) ;
}
if ( V_2 )
F_6 ( V_2 ) ;
return 0 ;
}
int F_360 ( struct V_107 * V_108 ,
struct V_34 * V_35 )
{
struct V_12 * V_37 = V_35 -> V_37 ;
struct V_471 * V_472 ;
T_2 V_32 ;
T_2 V_31 ;
int V_29 ;
if ( V_108 -> V_210 )
return 0 ;
if ( V_37 -> V_59 == & V_37 -> V_38 [ 0 ] )
V_472 = & V_37 -> V_38 [ 1 ] ;
else
V_472 = & V_37 -> V_38 [ 0 ] ;
while ( 1 ) {
V_29 = F_28 ( V_472 , 0 , & V_32 , & V_31 ,
V_60 , NULL ) ;
if ( V_29 )
break;
if ( F_237 ( V_35 , V_473 ) )
V_29 = F_142 ( V_35 , V_32 ,
V_31 + 1 - V_32 , NULL ) ;
F_361 ( V_472 , V_32 , V_31 , V_40 ) ;
F_359 ( V_35 , V_32 , V_31 ) ;
F_47 () ;
}
return 0 ;
}
static void F_362 ( struct V_12 * V_37 , T_2 V_36 ,
T_2 V_131 , T_2 V_144 )
{
struct V_100 * V_103 ;
T_2 V_7 ;
if ( V_131 < V_141 ) {
if ( V_144 == V_474 )
V_7 = V_281 ;
else
V_7 = V_279 ;
} else {
V_7 = V_280 ;
}
V_103 = F_69 ( V_37 , V_7 ) ;
F_30 ( ! V_103 ) ;
F_363 ( & V_103 -> V_290 , V_36 ) ;
}
static int F_153 ( struct V_107 * V_108 ,
struct V_34 * V_35 ,
T_2 V_27 , T_2 V_36 , T_2 V_17 ,
T_2 V_144 , T_2 V_475 ,
T_2 V_476 , int V_157 ,
struct V_177 * V_127 )
{
struct V_68 V_21 ;
struct V_64 * V_65 ;
struct V_12 * V_13 = V_35 -> V_37 ;
struct V_34 * V_63 = V_13 -> V_63 ;
struct V_66 * V_67 ;
struct V_114 * V_115 ;
struct V_160 * V_161 ;
int V_29 ;
int V_181 ;
int V_477 = 0 ;
int V_478 = 0 ;
int V_479 = 1 ;
T_3 V_116 ;
T_2 V_110 ;
bool V_170 = F_76 ( V_35 -> V_37 ,
V_119 ) ;
V_65 = F_33 () ;
if ( ! V_65 )
return - V_72 ;
V_65 -> V_76 = 1 ;
V_65 -> V_201 = 1 ;
V_181 = V_475 >= V_141 ;
F_30 ( ! V_181 && V_157 != 1 ) ;
if ( V_181 )
V_170 = 0 ;
V_29 = F_134 ( V_108 , V_63 , V_65 , & V_161 ,
V_27 , V_36 , V_17 ,
V_144 , V_475 ,
V_476 ) ;
if ( V_29 == 0 ) {
V_477 = V_65 -> V_84 [ 0 ] ;
while ( V_477 >= 0 ) {
F_40 ( V_65 -> V_83 [ 0 ] , & V_21 ,
V_477 ) ;
if ( V_21 . V_22 != V_27 )
break;
if ( V_21 . type == V_77 &&
V_21 . V_33 == V_36 ) {
V_478 = 1 ;
break;
}
if ( V_21 . type == V_86 &&
V_21 . V_33 == V_475 ) {
V_478 = 1 ;
break;
}
if ( V_65 -> V_84 [ 0 ] - V_477 > 5 )
break;
V_477 -- ;
}
#ifdef F_81
V_116 = F_77 ( V_65 -> V_83 [ 0 ] , V_477 ) ;
if ( V_478 && V_116 < sizeof( * V_115 ) )
V_478 = 0 ;
#endif
if ( ! V_478 ) {
F_30 ( V_161 ) ;
V_29 = F_139 ( V_108 , V_63 , V_65 ,
NULL , V_157 ,
V_181 ) ;
if ( V_29 ) {
F_148 ( V_108 , V_63 , V_29 ) ;
goto V_73;
}
F_44 ( V_65 ) ;
V_65 -> V_201 = 1 ;
V_21 . V_22 = V_27 ;
V_21 . type = V_77 ;
V_21 . V_33 = V_36 ;
if ( ! V_181 && V_170 ) {
V_21 . type = V_86 ;
V_21 . V_33 = V_475 ;
}
V_29 = F_37 ( V_108 , V_63 ,
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
V_21 . V_22 = V_27 ;
V_21 . type = V_77 ;
V_21 . V_33 = V_36 ;
F_44 ( V_65 ) ;
V_29 = F_37 ( V_108 , V_63 ,
& V_21 , V_65 , - 1 , 1 ) ;
}
if ( V_29 ) {
F_186 ( V_13 , L_18 ,
V_29 , V_27 ) ;
if ( V_29 > 0 )
F_364 ( V_63 ,
V_65 -> V_83 [ 0 ] ) ;
}
if ( V_29 < 0 ) {
F_148 ( V_108 , V_63 , V_29 ) ;
goto V_73;
}
V_477 = V_65 -> V_84 [ 0 ] ;
}
} else if ( F_8 ( V_29 == - V_151 ) ) {
F_364 ( V_63 , V_65 -> V_83 [ 0 ] ) ;
F_186 ( V_13 ,
L_19 ,
V_27 , V_17 , V_144 , V_475 ,
V_476 ) ;
F_148 ( V_108 , V_63 , V_29 ) ;
goto V_73;
} else {
F_148 ( V_108 , V_63 , V_29 ) ;
goto V_73;
}
V_67 = V_65 -> V_83 [ 0 ] ;
V_116 = F_77 ( V_67 , V_477 ) ;
#ifdef F_81
if ( V_116 < sizeof( * V_115 ) ) {
F_30 ( V_478 || V_477 != V_65 -> V_84 [ 0 ] ) ;
V_29 = F_87 ( V_108 , V_63 , V_65 ,
V_475 , 0 ) ;
if ( V_29 < 0 ) {
F_148 ( V_108 , V_63 , V_29 ) ;
goto V_73;
}
F_44 ( V_65 ) ;
V_65 -> V_201 = 1 ;
V_21 . V_22 = V_27 ;
V_21 . type = V_77 ;
V_21 . V_33 = V_36 ;
V_29 = F_37 ( V_108 , V_63 , & V_21 , V_65 ,
- 1 , 1 ) ;
if ( V_29 ) {
F_186 ( V_13 , L_18 ,
V_29 , V_27 ) ;
F_364 ( V_63 , V_65 -> V_83 [ 0 ] ) ;
}
if ( V_29 < 0 ) {
F_148 ( V_108 , V_63 , V_29 ) ;
goto V_73;
}
V_477 = V_65 -> V_84 [ 0 ] ;
V_67 = V_65 -> V_83 [ 0 ] ;
V_116 = F_77 ( V_67 , V_477 ) ;
}
#endif
F_30 ( V_116 < sizeof( * V_115 ) ) ;
V_115 = F_78 ( V_67 , V_477 ,
struct V_114 ) ;
if ( V_475 < V_141 &&
V_21 . type == V_77 ) {
struct V_136 * V_137 ;
F_30 ( V_116 < sizeof( * V_115 ) + sizeof( * V_137 ) ) ;
V_137 = (struct V_136 * ) ( V_115 + 1 ) ;
F_8 ( V_475 != F_365 ( V_67 , V_137 ) ) ;
}
V_110 = F_79 ( V_67 , V_115 ) ;
if ( V_110 < V_157 ) {
F_186 ( V_13 , L_20
L_21 , V_157 , V_110 , V_27 ) ;
V_29 = - V_464 ;
F_148 ( V_108 , V_63 , V_29 ) ;
goto V_73;
}
V_110 -= V_157 ;
if ( V_110 > 0 ) {
if ( V_127 )
F_130 ( V_127 , V_67 , V_115 ) ;
if ( V_161 ) {
F_30 ( ! V_478 ) ;
} else {
F_90 ( V_67 , V_115 , V_110 ) ;
F_95 ( V_67 ) ;
}
if ( V_478 ) {
V_29 = F_139 ( V_108 , V_63 , V_65 ,
V_161 , V_157 ,
V_181 ) ;
if ( V_29 ) {
F_148 ( V_108 , V_63 , V_29 ) ;
goto V_73;
}
}
F_362 ( V_35 -> V_37 , - V_36 , V_475 ,
V_144 ) ;
} else {
if ( V_478 ) {
F_30 ( V_181 && V_157 !=
F_118 ( V_35 , V_65 , V_161 ) ) ;
if ( V_161 ) {
F_30 ( V_65 -> V_84 [ 0 ] != V_477 ) ;
} else {
F_30 ( V_65 -> V_84 [ 0 ] != V_477 + 1 ) ;
V_65 -> V_84 [ 0 ] = V_477 ;
V_479 = 2 ;
}
}
V_29 = F_366 ( V_108 , V_63 , V_65 , V_65 -> V_84 [ 0 ] ,
V_479 ) ;
if ( V_29 ) {
F_148 ( V_108 , V_63 , V_29 ) ;
goto V_73;
}
F_44 ( V_65 ) ;
if ( V_181 ) {
V_29 = F_165 ( V_108 , V_35 , V_27 , V_36 ) ;
if ( V_29 ) {
F_148 ( V_108 , V_63 , V_29 ) ;
goto V_73;
}
}
V_29 = F_342 ( V_35 , V_27 , V_36 , 0 ) ;
if ( V_29 ) {
F_148 ( V_108 , V_63 , V_29 ) ;
goto V_73;
}
}
V_73:
F_50 ( V_65 ) ;
return V_29 ;
}
static T_1 int F_367 ( struct V_107 * V_108 ,
struct V_34 * V_35 , T_2 V_27 )
{
struct V_111 * V_102 ;
struct V_112 * V_113 ;
int V_29 = 0 ;
V_113 = & V_108 -> V_125 -> V_113 ;
F_11 ( & V_113 -> V_52 ) ;
V_102 = F_84 ( V_108 , V_27 ) ;
if ( ! V_102 )
goto V_480;
F_11 ( & V_102 -> V_52 ) ;
if ( F_176 ( & V_102 -> V_206 ) )
goto V_73;
if ( V_102 -> V_127 ) {
if ( ! V_102 -> V_214 )
goto V_73;
F_174 ( V_102 -> V_127 ) ;
V_102 -> V_127 = NULL ;
}
if ( ! F_85 ( & V_102 -> V_79 ) )
goto V_73;
V_102 -> V_126 . V_218 = 0 ;
F_177 ( & V_102 -> V_220 , & V_113 -> V_221 ) ;
F_178 ( & V_113 -> V_222 ) ;
V_113 -> V_219 -- ;
if ( V_102 -> V_216 == 0 )
V_113 -> V_217 -- ;
V_102 -> V_216 = 0 ;
F_13 ( & V_102 -> V_52 ) ;
F_13 ( & V_113 -> V_52 ) ;
F_30 ( V_102 -> V_127 ) ;
if ( V_102 -> V_214 )
V_29 = 1 ;
F_46 ( & V_102 -> V_79 ) ;
F_86 ( & V_102 -> V_126 ) ;
return V_29 ;
V_73:
F_13 ( & V_102 -> V_52 ) ;
V_480:
F_13 ( & V_113 -> V_52 ) ;
return 0 ;
}
void F_368 ( struct V_107 * V_108 ,
struct V_34 * V_35 ,
struct V_66 * V_250 ,
T_2 V_17 , int V_481 )
{
struct V_1 * V_2 = NULL ;
int V_482 = 1 ;
int V_29 ;
if ( V_35 -> V_246 . V_22 != V_199 ) {
V_29 = F_145 ( V_35 -> V_37 , V_108 ,
V_250 -> V_32 , V_250 -> V_49 ,
V_17 , V_35 -> V_246 . V_22 ,
F_213 ( V_250 ) ,
V_208 , NULL , 0 ) ;
F_30 ( V_29 ) ;
}
if ( ! V_481 )
return;
V_2 = F_68 ( V_35 -> V_37 , V_250 -> V_32 ) ;
if ( F_369 ( V_250 ) == V_108 -> V_269 ) {
if ( V_35 -> V_246 . V_22 != V_199 ) {
V_29 = F_367 ( V_108 , V_35 , V_250 -> V_32 ) ;
if ( ! V_29 )
goto V_73;
}
if ( F_370 ( V_250 , V_483 ) ) {
F_348 ( V_35 , V_2 , V_250 -> V_32 , V_250 -> V_49 , 1 ) ;
goto V_73;
}
F_8 ( F_337 ( V_484 , & V_250 -> V_485 ) ) ;
F_29 ( V_2 , V_250 -> V_32 , V_250 -> V_49 ) ;
F_354 ( V_2 , V_250 -> V_49 , V_469 ) ;
F_349 ( V_35 , V_250 -> V_32 , V_250 -> V_49 ) ;
V_482 = 0 ;
}
V_73:
if ( V_482 )
F_362 ( V_35 -> V_37 , V_250 -> V_49 ,
F_213 ( V_250 ) ,
V_35 -> V_246 . V_22 ) ;
F_371 ( V_486 , & V_250 -> V_485 ) ;
F_6 ( V_2 ) ;
}
int V_256 ( struct V_107 * V_108 , struct V_34 * V_35 ,
T_2 V_27 , T_2 V_36 , T_2 V_17 , T_2 V_144 ,
T_2 V_131 , T_2 V_33 , int V_198 )
{
int V_29 ;
struct V_12 * V_37 = V_35 -> V_37 ;
F_362 ( V_35 -> V_37 , V_36 , V_131 , V_144 ) ;
if ( V_144 == V_199 ) {
F_8 ( V_131 >= V_141 ) ;
F_161 ( V_35 , V_27 , V_36 , 1 ) ;
V_29 = 0 ;
} else if ( V_131 < V_141 ) {
V_29 = F_145 ( V_37 , V_108 , V_27 ,
V_36 ,
V_17 , V_144 , ( int ) V_131 ,
V_208 , NULL , V_198 ) ;
} else {
V_29 = F_146 ( V_37 , V_108 , V_27 ,
V_36 ,
V_17 , V_144 , V_131 ,
V_33 , V_208 ,
NULL , V_198 ) ;
}
return V_29 ;
}
static T_2 F_372 ( struct V_34 * V_35 ,
struct V_1 * V_2 ,
T_2 V_487 , T_2 V_36 )
{
T_2 V_29 = F_264 ( V_487 , V_35 -> V_488 ) ;
return V_29 ;
}
static T_1 void
F_373 ( struct V_1 * V_2 ,
T_2 V_36 )
{
struct V_50 * V_54 ;
V_54 = F_25 ( V_2 ) ;
if ( ! V_54 )
return;
F_294 ( V_54 -> V_89 , F_1 ( V_2 ) ||
( V_2 -> V_11 -> V_489 >= V_36 ) ) ;
F_26 ( V_54 ) ;
}
static T_1 int
F_374 ( struct V_1 * V_2 )
{
struct V_50 * V_54 ;
int V_29 = 0 ;
V_54 = F_25 ( V_2 ) ;
if ( ! V_54 )
return ( V_2 -> V_3 == V_5 ) ? - V_172 : 0 ;
F_294 ( V_54 -> V_89 , F_1 ( V_2 ) ) ;
if ( V_2 -> V_3 == V_5 )
V_29 = - V_172 ;
F_26 ( V_54 ) ;
return V_29 ;
}
int F_375 ( T_2 V_7 )
{
if ( V_7 & V_287 )
return V_490 ;
else if ( V_7 & V_286 )
return V_491 ;
else if ( V_7 & V_285 )
return V_492 ;
else if ( V_7 & V_328 )
return V_493 ;
else if ( V_7 & V_329 )
return V_494 ;
else if ( V_7 & V_330 )
return V_495 ;
return V_496 ;
}
int F_376 ( struct V_1 * V_2 )
{
return F_375 ( V_2 -> V_7 ) ;
}
static const char * F_377 ( enum V_497 type )
{
if ( type >= V_291 )
return NULL ;
return V_498 [ type ] ;
}
static T_1 int F_378 ( struct V_34 * V_499 ,
T_2 V_36 , T_2 V_500 ,
T_2 V_501 , struct V_68 * V_205 ,
T_2 V_7 )
{
int V_29 = 0 ;
struct V_34 * V_35 = V_499 -> V_37 -> V_63 ;
struct V_502 * V_503 = NULL ;
struct V_1 * V_14 = NULL ;
T_2 V_463 = 0 ;
T_2 V_504 = 0 ;
int V_505 = 2 * 1024 * 1024 ;
struct V_100 * V_103 ;
int V_506 = 0 ;
int V_507 = F_375 ( V_7 ) ;
int V_508 = ( V_7 & V_280 ) ?
V_509 : V_470 ;
bool V_510 = false ;
bool V_511 = false ;
bool V_512 = true ;
bool V_513 = false ;
F_8 ( V_36 < V_35 -> V_337 ) ;
F_379 ( V_205 , V_77 ) ;
V_205 -> V_22 = 0 ;
V_205 -> V_33 = 0 ;
F_380 ( V_499 , V_36 , V_500 , V_7 ) ;
V_103 = F_69 ( V_35 -> V_37 , V_7 ) ;
if ( ! V_103 ) {
F_186 ( V_35 -> V_37 , L_22 , V_7 ) ;
return - V_343 ;
}
if ( F_283 ( V_103 ) )
V_512 = false ;
if ( V_7 & V_279 && V_512 ) {
V_503 = & V_35 -> V_37 -> V_514 ;
if ( ! F_237 ( V_35 , V_515 ) )
V_505 = 64 * 1024 ;
}
if ( ( V_7 & V_280 ) && V_512 &&
F_237 ( V_35 , V_515 ) ) {
V_503 = & V_35 -> V_37 -> V_516 ;
}
if ( V_503 ) {
F_11 ( & V_503 -> V_52 ) ;
if ( V_503 -> V_14 )
V_501 = V_503 -> V_517 ;
F_13 ( & V_503 -> V_52 ) ;
}
V_463 = F_381 ( V_463 , V_26 ( V_35 , 0 ) ) ;
V_463 = F_381 ( V_463 , V_501 ) ;
if ( ! V_503 )
V_505 = 0 ;
if ( V_463 == V_501 ) {
V_14 = F_68 ( V_35 -> V_37 ,
V_463 ) ;
if ( V_14 && F_3 ( V_14 , V_7 ) &&
V_14 -> V_3 != V_94 ) {
F_36 ( & V_103 -> V_295 ) ;
if ( F_185 ( & V_14 -> V_91 ) ||
V_14 -> V_267 ) {
F_6 ( V_14 ) ;
F_45 ( & V_103 -> V_295 ) ;
} else {
V_507 = F_376 ( V_14 ) ;
goto V_518;
}
} else if ( V_14 ) {
F_6 ( V_14 ) ;
}
}
V_519:
V_513 = false ;
F_36 ( & V_103 -> V_295 ) ;
F_382 (block_group, &space_info->block_groups[index],
list) {
T_2 V_33 ;
int V_3 ;
F_4 ( V_14 ) ;
V_463 = V_14 -> V_21 . V_22 ;
if ( ! F_3 ( V_14 , V_7 ) ) {
T_2 V_520 = V_285 |
V_286 |
V_329 |
V_330 |
V_287 ;
if ( ( V_7 & V_520 ) && ! ( V_14 -> V_7 & V_520 ) )
goto V_506;
}
V_518:
V_3 = F_1 ( V_14 ) ;
if ( F_301 ( ! V_3 ) ) {
V_29 = F_51 ( V_14 , 0 ) ;
F_30 ( V_29 < 0 ) ;
V_29 = 0 ;
}
if ( F_301 ( V_14 -> V_3 == V_5 ) )
goto V_506;
if ( F_301 ( V_14 -> V_267 ) )
goto V_506;
if ( V_503 ) {
struct V_1 * V_521 ;
unsigned long V_522 ;
F_11 ( & V_503 -> V_523 ) ;
V_521 = V_503 -> V_14 ;
if ( V_521 != V_14 &&
( ! V_521 ||
V_521 -> V_267 ||
! F_3 ( V_521 , V_7 ) ) )
goto V_524;
if ( V_521 != V_14 )
F_4 ( V_521 ) ;
V_33 = F_383 ( V_521 ,
V_503 ,
V_36 ,
V_521 -> V_21 . V_22 ,
& V_504 ) ;
if ( V_33 ) {
F_13 ( & V_503 -> V_523 ) ;
F_384 ( V_35 ,
V_521 ,
V_463 , V_36 ) ;
if ( V_521 != V_14 ) {
F_6 ( V_14 ) ;
V_14 = V_521 ;
}
goto V_525;
}
F_8 ( V_503 -> V_14 != V_521 ) ;
if ( V_521 != V_14 )
F_6 ( V_521 ) ;
V_524:
if ( V_506 >= V_526 &&
V_503 -> V_14 != V_14 ) {
F_13 ( & V_503 -> V_523 ) ;
goto V_527;
}
F_385 ( NULL , V_503 ) ;
if ( V_506 >= V_526 ) {
F_13 ( & V_503 -> V_523 ) ;
goto V_527;
}
V_522 = F_34 (unsigned long,
empty_cluster + empty_size,
block_group->full_stripe_len) ;
V_29 = F_386 ( V_35 , V_14 ,
V_503 , V_463 ,
V_36 ,
V_522 ) ;
if ( V_29 == 0 ) {
V_33 = F_383 ( V_14 ,
V_503 ,
V_36 ,
V_463 ,
& V_504 ) ;
if ( V_33 ) {
F_13 ( & V_503 -> V_523 ) ;
F_384 ( V_35 ,
V_14 , V_463 ,
V_36 ) ;
goto V_525;
}
} else if ( ! V_3 && V_506 > V_528
&& ! V_510 ) {
F_13 ( & V_503 -> V_523 ) ;
V_510 = true ;
F_373 ( V_14 ,
V_36 + V_505 + V_500 ) ;
goto V_518;
}
F_385 ( NULL , V_503 ) ;
F_13 ( & V_503 -> V_523 ) ;
goto V_506;
}
V_527:
F_11 ( & V_14 -> V_11 -> V_529 ) ;
if ( V_3 &&
V_14 -> V_11 -> V_489 <
V_36 + V_505 + V_500 ) {
if ( V_14 -> V_11 -> V_489 >
V_504 )
V_504 =
V_14 -> V_11 -> V_489 ;
F_13 ( & V_14 -> V_11 -> V_529 ) ;
goto V_506;
}
F_13 ( & V_14 -> V_11 -> V_529 ) ;
V_33 = F_387 ( V_14 , V_463 ,
V_36 , V_500 ,
& V_504 ) ;
if ( ! V_33 && ! V_511 && ! V_3 &&
V_506 > V_528 ) {
F_373 ( V_14 ,
V_36 + V_500 ) ;
V_511 = true ;
goto V_518;
} else if ( ! V_33 ) {
if ( ! V_3 )
V_513 = true ;
goto V_506;
}
V_525:
V_463 = F_372 ( V_35 , V_14 ,
V_33 , V_36 ) ;
if ( V_463 + V_36 >
V_14 -> V_21 . V_22 + V_14 -> V_21 . V_33 ) {
F_29 ( V_14 , V_33 , V_36 ) ;
goto V_506;
}
if ( V_33 < V_463 )
F_29 ( V_14 , V_33 ,
V_463 - V_33 ) ;
F_30 ( V_33 > V_463 ) ;
V_29 = F_354 ( V_14 , V_36 ,
V_508 ) ;
if ( V_29 == - V_175 ) {
F_29 ( V_14 , V_33 , V_36 ) ;
goto V_506;
}
V_205 -> V_22 = V_463 ;
V_205 -> V_33 = V_36 ;
F_388 ( V_499 , V_14 ,
V_463 , V_36 ) ;
F_6 ( V_14 ) ;
break;
V_506:
V_510 = false ;
V_511 = false ;
F_30 ( V_507 != F_376 ( V_14 ) ) ;
F_6 ( V_14 ) ;
}
F_45 ( & V_103 -> V_295 ) ;
if ( ! V_205 -> V_22 && V_506 >= V_530 && V_513 )
goto V_519;
if ( ! V_205 -> V_22 && ++ V_507 < V_291 )
goto V_519;
if ( ! V_205 -> V_22 && V_506 < V_526 ) {
V_507 = 0 ;
V_506 ++ ;
if ( V_506 == V_531 ) {
struct V_107 * V_108 ;
V_108 = F_266 ( V_35 ) ;
if ( F_229 ( V_108 ) ) {
V_29 = F_230 ( V_108 ) ;
goto V_73;
}
V_29 = F_267 ( V_108 , V_35 , V_7 ,
V_342 ) ;
if ( V_29 < 0 && V_29 != - V_343 )
F_148 ( V_108 ,
V_35 , V_29 ) ;
else
V_29 = 0 ;
F_268 ( V_108 , V_35 ) ;
if ( V_29 )
goto V_73;
}
if ( V_506 == V_526 ) {
V_500 = 0 ;
V_505 = 0 ;
}
goto V_519;
} else if ( ! V_205 -> V_22 ) {
V_29 = - V_343 ;
} else if ( V_205 -> V_22 ) {
V_29 = 0 ;
}
V_73:
if ( V_29 == - V_343 )
V_205 -> V_33 = V_504 ;
return V_29 ;
}
static void F_281 ( struct V_100 * V_13 , T_2 V_333 ,
int V_532 )
{
struct V_1 * V_2 ;
int V_507 = 0 ;
F_11 ( & V_13 -> V_52 ) ;
F_389 ( V_533 L_23 ,
V_13 -> V_7 ,
V_13 -> V_282 - V_13 -> V_283 - V_13 -> V_296 -
V_13 -> V_297 - V_13 -> V_298 ,
( V_13 -> V_106 ) ? L_4 : L_24 ) ;
F_389 ( V_533 L_25
L_26 ,
V_13 -> V_282 , V_13 -> V_283 , V_13 -> V_296 ,
V_13 -> V_297 , V_13 -> V_299 ,
V_13 -> V_298 ) ;
F_13 ( & V_13 -> V_52 ) ;
if ( ! V_532 )
return;
F_36 ( & V_13 -> V_295 ) ;
V_78:
F_382 (cache, &info->block_groups[index], list) {
F_11 ( & V_2 -> V_52 ) ;
F_389 ( V_533 L_27
L_28
L_29 ,
V_2 -> V_21 . V_22 , V_2 -> V_21 . V_33 ,
F_345 ( & V_2 -> V_133 ) , V_2 -> V_9 ,
V_2 -> V_10 , V_2 -> V_267 ? L_30 : L_4 ) ;
F_390 ( V_2 , V_333 ) ;
F_13 ( & V_2 -> V_52 ) ;
}
if ( ++ V_507 < V_291 )
goto V_78;
F_45 ( & V_13 -> V_295 ) ;
}
int F_391 ( struct V_34 * V_35 ,
T_2 V_36 , T_2 V_534 ,
T_2 V_500 , T_2 V_501 ,
struct V_68 * V_205 , int V_181 )
{
bool V_535 = false ;
T_2 V_7 ;
int V_29 ;
V_7 = F_263 ( V_35 , V_181 ) ;
V_78:
F_8 ( V_36 < V_35 -> V_337 ) ;
V_29 = F_378 ( V_35 , V_36 , V_500 , V_501 , V_205 ,
V_7 ) ;
if ( V_29 == - V_343 ) {
if ( ! V_535 && V_205 -> V_33 ) {
V_36 = F_293 ( V_36 >> 1 , V_205 -> V_33 ) ;
V_36 = F_392 ( V_36 , V_35 -> V_337 ) ;
V_36 = F_381 ( V_36 , V_534 ) ;
if ( V_36 == V_534 )
V_535 = true ;
goto V_78;
} else if ( F_237 ( V_35 , V_355 ) ) {
struct V_100 * V_347 ;
V_347 = F_69 ( V_35 -> V_37 , V_7 ) ;
F_186 ( V_35 -> V_37 , L_31 ,
V_7 , V_36 ) ;
if ( V_347 )
F_281 ( V_347 , V_36 , 1 ) ;
}
}
return V_29 ;
}
static int F_393 ( struct V_34 * V_35 ,
T_2 V_32 , T_2 V_49 , int V_482 )
{
struct V_1 * V_2 ;
int V_29 = 0 ;
V_2 = F_68 ( V_35 -> V_37 , V_32 ) ;
if ( ! V_2 ) {
F_186 ( V_35 -> V_37 , L_32 ,
V_32 ) ;
return - V_343 ;
}
if ( F_237 ( V_35 , V_473 ) )
V_29 = F_142 ( V_35 , V_32 , V_49 , NULL ) ;
if ( V_482 )
F_348 ( V_35 , V_2 , V_32 , V_49 , 1 ) ;
else {
F_29 ( V_2 , V_32 , V_49 ) ;
F_354 ( V_2 , V_49 , V_469 ) ;
}
F_6 ( V_2 ) ;
F_349 ( V_35 , V_32 , V_49 ) ;
return V_29 ;
}
int F_394 ( struct V_34 * V_35 ,
T_2 V_32 , T_2 V_49 )
{
return F_393 ( V_35 , V_32 , V_49 , 0 ) ;
}
int F_395 ( struct V_34 * V_35 ,
T_2 V_32 , T_2 V_49 )
{
return F_393 ( V_35 , V_32 , V_49 , 1 ) ;
}
static int F_152 ( struct V_107 * V_108 ,
struct V_34 * V_35 ,
T_2 V_17 , T_2 V_144 ,
T_2 V_7 , T_2 V_131 , T_2 V_33 ,
struct V_68 * V_205 , int V_130 )
{
int V_29 ;
struct V_12 * V_37 = V_35 -> V_37 ;
struct V_114 * V_536 ;
struct V_160 * V_161 ;
struct V_64 * V_65 ;
struct V_66 * V_67 ;
int type ;
T_3 V_57 ;
if ( V_17 > 0 )
type = V_152 ;
else
type = V_153 ;
V_57 = sizeof( * V_536 ) + F_125 ( type ) ;
V_65 = F_33 () ;
if ( ! V_65 )
return - V_72 ;
V_65 -> V_201 = 1 ;
V_29 = F_106 ( V_108 , V_37 -> V_63 , V_65 ,
V_205 , V_57 ) ;
if ( V_29 ) {
F_50 ( V_65 ) ;
return V_29 ;
}
V_67 = V_65 -> V_83 [ 0 ] ;
V_536 = F_78 ( V_67 , V_65 -> V_84 [ 0 ] ,
struct V_114 ) ;
F_90 ( V_67 , V_536 , V_130 ) ;
F_91 ( V_67 , V_536 , V_108 -> V_269 ) ;
F_92 ( V_67 , V_536 ,
V_7 | V_143 ) ;
V_161 = (struct V_160 * ) ( V_536 + 1 ) ;
F_132 ( V_67 , V_161 , type ) ;
if ( V_17 > 0 ) {
struct V_156 * V_149 ;
V_149 = (struct V_156 * ) ( V_161 + 1 ) ;
F_133 ( V_67 , V_161 , V_17 ) ;
F_107 ( V_67 , V_149 , V_130 ) ;
} else {
struct V_148 * V_149 ;
V_149 = (struct V_148 * ) ( & V_161 -> V_33 ) ;
F_109 ( V_67 , V_149 , V_144 ) ;
F_110 ( V_67 , V_149 , V_131 ) ;
F_111 ( V_67 , V_149 , V_33 ) ;
F_112 ( V_67 , V_149 , V_130 ) ;
}
F_95 ( V_65 -> V_83 [ 0 ] ) ;
F_50 ( V_65 ) ;
V_29 = F_342 ( V_35 , V_205 -> V_22 , V_205 -> V_33 , 1 ) ;
if ( V_29 ) {
F_186 ( V_37 , L_33 ,
V_205 -> V_22 , V_205 -> V_33 ) ;
F_83 () ;
}
F_396 ( V_35 , V_205 -> V_22 , V_205 -> V_33 ) ;
return V_29 ;
}
static int F_159 ( struct V_107 * V_108 ,
struct V_34 * V_35 ,
T_2 V_17 , T_2 V_144 ,
T_2 V_7 , struct V_448 * V_21 ,
int V_164 , struct V_68 * V_205 )
{
int V_29 ;
struct V_12 * V_37 = V_35 -> V_37 ;
struct V_114 * V_536 ;
struct V_136 * V_537 ;
struct V_160 * V_161 ;
struct V_64 * V_65 ;
struct V_66 * V_67 ;
T_3 V_57 = sizeof( * V_536 ) + sizeof( * V_161 ) ;
bool V_170 = F_76 ( V_35 -> V_37 ,
V_119 ) ;
if ( ! V_170 )
V_57 += sizeof( * V_537 ) ;
V_65 = F_33 () ;
if ( ! V_65 ) {
F_395 ( V_35 , V_205 -> V_22 ,
V_35 -> V_88 ) ;
return - V_72 ;
}
V_65 -> V_201 = 1 ;
V_29 = F_106 ( V_108 , V_37 -> V_63 , V_65 ,
V_205 , V_57 ) ;
if ( V_29 ) {
F_395 ( V_35 , V_205 -> V_22 ,
V_35 -> V_88 ) ;
F_50 ( V_65 ) ;
return V_29 ;
}
V_67 = V_65 -> V_83 [ 0 ] ;
V_536 = F_78 ( V_67 , V_65 -> V_84 [ 0 ] ,
struct V_114 ) ;
F_90 ( V_67 , V_536 , 1 ) ;
F_91 ( V_67 , V_536 , V_108 -> V_269 ) ;
F_92 ( V_67 , V_536 ,
V_7 | V_142 ) ;
if ( V_170 ) {
V_161 = (struct V_160 * ) ( V_536 + 1 ) ;
} else {
V_537 = (struct V_136 * ) ( V_536 + 1 ) ;
F_154 ( V_67 , V_537 , V_21 ) ;
F_94 ( V_67 , V_537 , V_164 ) ;
V_161 = (struct V_160 * ) ( V_537 + 1 ) ;
}
if ( V_17 > 0 ) {
F_30 ( ! ( V_7 & V_124 ) ) ;
F_132 ( V_67 , V_161 ,
V_162 ) ;
F_133 ( V_67 , V_161 , V_17 ) ;
} else {
F_132 ( V_67 , V_161 ,
V_163 ) ;
F_133 ( V_67 , V_161 , V_144 ) ;
}
F_95 ( V_67 ) ;
F_50 ( V_65 ) ;
V_29 = F_342 ( V_35 , V_205 -> V_22 , V_35 -> V_88 , 1 ) ;
if ( V_29 ) {
F_186 ( V_37 , L_33 ,
V_205 -> V_22 , V_205 -> V_33 ) ;
F_83 () ;
}
F_396 ( V_35 , V_205 -> V_22 , V_35 -> V_88 ) ;
return V_29 ;
}
int F_397 ( struct V_107 * V_108 ,
struct V_34 * V_35 ,
T_2 V_144 , T_2 V_131 ,
T_2 V_33 , struct V_68 * V_205 )
{
int V_29 ;
F_30 ( V_144 == V_199 ) ;
V_29 = F_146 ( V_35 -> V_37 , V_108 , V_205 -> V_22 ,
V_205 -> V_33 , 0 ,
V_144 , V_131 , V_33 ,
V_223 , NULL , 0 ) ;
return V_29 ;
}
int F_398 ( struct V_107 * V_108 ,
struct V_34 * V_35 ,
T_2 V_144 , T_2 V_131 , T_2 V_33 ,
struct V_68 * V_205 )
{
int V_29 ;
struct V_1 * V_14 ;
if ( ! F_76 ( V_35 -> V_37 , V_468 ) ) {
V_29 = F_352 ( V_35 , V_205 -> V_22 , V_205 -> V_33 ) ;
if ( V_29 )
return V_29 ;
}
V_14 = F_68 ( V_35 -> V_37 , V_205 -> V_22 ) ;
if ( ! V_14 )
return - V_464 ;
V_29 = F_354 ( V_14 , V_205 -> V_33 ,
V_509 ) ;
F_30 ( V_29 ) ;
V_29 = F_152 ( V_108 , V_35 , 0 , V_144 ,
0 , V_131 , V_33 , V_205 , 1 ) ;
F_6 ( V_14 ) ;
return V_29 ;
}
static struct V_66 *
F_399 ( struct V_107 * V_108 , struct V_34 * V_35 ,
T_2 V_27 , T_3 V_538 , int V_164 )
{
struct V_66 * V_250 ;
V_250 = F_400 ( V_35 , V_27 , V_538 ) ;
if ( ! V_250 )
return F_401 ( - V_72 ) ;
F_402 ( V_250 , V_108 -> V_269 ) ;
F_403 ( V_35 -> V_246 . V_22 , V_250 , V_164 ) ;
F_404 ( V_250 ) ;
F_405 ( V_108 , V_35 , V_250 ) ;
F_371 ( V_539 , & V_250 -> V_485 ) ;
F_406 ( V_250 ) ;
F_407 ( V_250 ) ;
if ( V_35 -> V_246 . V_22 == V_199 ) {
if ( V_35 -> V_540 % 2 == 0 )
F_347 ( & V_35 -> V_541 , V_250 -> V_32 ,
V_250 -> V_32 + V_250 -> V_49 - 1 , V_40 ) ;
else
F_408 ( & V_35 -> V_541 , V_250 -> V_32 ,
V_250 -> V_32 + V_250 -> V_49 - 1 , V_40 ) ;
} else {
F_347 ( & V_108 -> V_125 -> V_542 , V_250 -> V_32 ,
V_250 -> V_32 + V_250 -> V_49 - 1 , V_40 ) ;
}
V_108 -> V_543 ++ ;
return V_250 ;
}
static struct V_236 *
F_409 ( struct V_107 * V_108 ,
struct V_34 * V_35 , T_3 V_538 )
{
struct V_236 * V_377 ;
struct V_236 * V_237 = & V_35 -> V_37 -> V_238 ;
int V_29 ;
bool V_544 = false ;
V_377 = F_304 ( V_108 , V_35 ) ;
if ( F_301 ( V_377 -> V_57 == 0 ) )
goto V_545;
V_78:
V_29 = F_302 ( V_377 , V_538 ) ;
if ( ! V_29 )
return V_377 ;
if ( V_377 -> V_546 )
return F_401 ( V_29 ) ;
if ( V_377 -> type == V_547 && ! V_544 ) {
V_544 = true ;
F_320 ( V_35 -> V_37 ) ;
goto V_78;
}
if ( F_237 ( V_35 , V_355 ) ) {
static F_410 ( V_548 ,
V_549 * 10 ,
1 ) ;
if ( F_411 ( & V_548 ) )
F_412 ( 1 , V_550
L_34 , V_29 ) ;
}
V_545:
V_29 = F_299 ( V_35 , V_377 , V_538 ,
V_389 ) ;
if ( ! V_29 )
return V_377 ;
if ( V_377 -> type != V_547 &&
V_377 -> V_103 == V_237 -> V_103 ) {
V_29 = F_302 ( V_237 , V_538 ) ;
if ( ! V_29 )
return V_237 ;
}
return F_401 ( V_29 ) ;
}
static void F_413 ( struct V_12 * V_37 ,
struct V_236 * V_377 , T_3 V_538 )
{
F_305 ( V_377 , V_538 , 0 ) ;
F_307 ( V_37 , V_377 , NULL , 0 ) ;
}
struct V_66 * F_414 ( struct V_107 * V_108 ,
struct V_34 * V_35 , T_3 V_538 ,
T_2 V_17 , T_2 V_144 ,
struct V_448 * V_21 , int V_164 ,
T_2 V_551 , T_2 V_500 )
{
struct V_68 V_205 ;
struct V_236 * V_377 ;
struct V_66 * V_250 ;
T_2 V_7 = 0 ;
int V_29 ;
bool V_170 = F_76 ( V_35 -> V_37 ,
V_119 ) ;
V_377 = F_409 ( V_108 , V_35 , V_538 ) ;
if ( F_229 ( V_377 ) )
return F_415 ( V_377 ) ;
V_29 = F_391 ( V_35 , V_538 , V_538 ,
V_500 , V_551 , & V_205 , 0 ) ;
if ( V_29 ) {
F_413 ( V_35 -> V_37 , V_377 , V_538 ) ;
return F_401 ( V_29 ) ;
}
V_250 = F_399 ( V_108 , V_35 , V_205 . V_22 ,
V_538 , V_164 ) ;
F_30 ( F_229 ( V_250 ) ) ;
if ( V_144 == V_552 ) {
if ( V_17 == 0 )
V_17 = V_205 . V_22 ;
V_7 |= V_124 ;
} else
F_30 ( V_17 > 0 ) ;
if ( V_144 != V_199 ) {
struct V_177 * V_127 ;
V_127 = F_203 () ;
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
V_29 = F_145 ( V_35 -> V_37 , V_108 ,
V_205 . V_22 ,
V_205 . V_33 , V_17 , V_144 ,
V_164 , V_223 ,
V_127 , 0 ) ;
F_30 ( V_29 ) ;
}
return V_250 ;
}
static T_1 void F_416 ( struct V_107 * V_108 ,
struct V_34 * V_35 ,
struct V_553 * V_554 ,
struct V_64 * V_65 )
{
T_2 V_27 ;
T_2 V_272 ;
T_2 V_110 ;
T_2 V_7 ;
T_3 V_71 ;
T_3 V_538 ;
struct V_68 V_21 ;
struct V_66 * V_466 ;
int V_29 ;
int V_555 ;
int V_556 = 0 ;
if ( V_65 -> V_84 [ V_554 -> V_164 ] < V_554 -> V_557 ) {
V_554 -> V_558 = V_554 -> V_558 * 2 / 3 ;
V_554 -> V_558 = F_381 ( V_554 -> V_558 , 2 ) ;
} else {
V_554 -> V_558 = V_554 -> V_558 * 3 / 2 ;
V_554 -> V_558 = F_24 ( int , V_554 -> V_558 ,
F_417 ( V_35 ) ) ;
}
V_466 = V_65 -> V_83 [ V_554 -> V_164 ] ;
V_71 = F_38 ( V_466 ) ;
V_538 = F_220 ( V_35 , V_554 -> V_164 - 1 ) ;
for ( V_555 = V_65 -> V_84 [ V_554 -> V_164 ] ; V_555 < V_71 ; V_555 ++ ) {
if ( V_556 >= V_554 -> V_558 )
break;
F_47 () ;
V_27 = F_219 ( V_466 , V_555 ) ;
V_272 = F_418 ( V_466 , V_555 ) ;
if ( V_555 == V_65 -> V_84 [ V_554 -> V_164 ] )
goto V_76;
if ( V_554 -> V_559 == V_560 &&
V_272 <= V_35 -> V_246 . V_33 )
continue;
V_29 = F_75 ( V_108 , V_35 , V_27 ,
V_554 -> V_164 - 1 , 1 , & V_110 ,
& V_7 ) ;
if ( V_29 < 0 )
continue;
F_30 ( V_110 == 0 ) ;
if ( V_554 -> V_559 == V_561 ) {
if ( V_110 == 1 )
goto V_76;
if ( V_554 -> V_164 == 1 &&
( V_7 & V_124 ) )
continue;
if ( ! V_554 -> V_562 ||
V_272 <= V_35 -> V_246 . V_33 )
continue;
F_123 ( V_466 , & V_21 , V_555 ) ;
V_29 = F_419 ( & V_21 ,
& V_554 -> V_563 ) ;
if ( V_29 < 0 )
continue;
} else {
if ( V_554 -> V_164 == 1 &&
( V_7 & V_124 ) )
continue;
}
V_76:
V_29 = F_420 ( V_35 , V_27 , V_538 ,
V_272 ) ;
if ( V_29 )
break;
V_556 ++ ;
}
V_554 -> V_557 = V_555 ;
}
static T_1 int F_421 ( struct V_107 * V_108 ,
struct V_34 * V_35 ,
struct V_64 * V_65 ,
struct V_553 * V_554 , int V_564 )
{
int V_164 = V_554 -> V_164 ;
struct V_66 * V_466 = V_65 -> V_83 [ V_164 ] ;
T_2 V_565 = V_124 ;
int V_29 ;
if ( V_554 -> V_559 == V_560 &&
F_212 ( V_466 ) != V_35 -> V_246 . V_22 )
return 1 ;
if ( V_564 &&
( ( V_554 -> V_559 == V_561 && V_554 -> V_110 [ V_164 ] != 1 ) ||
( V_554 -> V_559 == V_560 && ! ( V_554 -> V_7 [ V_164 ] & V_565 ) ) ) ) {
F_30 ( ! V_65 -> V_566 [ V_164 ] ) ;
V_29 = F_75 ( V_108 , V_35 ,
V_466 -> V_32 , V_164 , 1 ,
& V_554 -> V_110 [ V_164 ] ,
& V_554 -> V_7 [ V_164 ] ) ;
F_30 ( V_29 == - V_72 ) ;
if ( V_29 )
return V_29 ;
F_30 ( V_554 -> V_110 [ V_164 ] == 0 ) ;
}
if ( V_554 -> V_559 == V_561 ) {
if ( V_554 -> V_110 [ V_164 ] > 1 )
return 1 ;
if ( V_65 -> V_566 [ V_164 ] && ! V_554 -> V_171 ) {
F_422 ( V_466 , V_65 -> V_566 [ V_164 ] ) ;
V_65 -> V_566 [ V_164 ] = 0 ;
}
return 0 ;
}
if ( ! ( V_554 -> V_7 [ V_164 ] & V_565 ) ) {
F_30 ( ! V_65 -> V_566 [ V_164 ] ) ;
V_29 = F_221 ( V_108 , V_35 , V_466 , 1 , V_554 -> V_567 ) ;
F_30 ( V_29 ) ;
V_29 = F_222 ( V_108 , V_35 , V_466 , 0 , V_554 -> V_567 ) ;
F_30 ( V_29 ) ;
V_29 = F_202 ( V_108 , V_35 , V_466 -> V_32 ,
V_466 -> V_49 , V_565 ,
F_213 ( V_466 ) , 0 ) ;
F_30 ( V_29 ) ;
V_554 -> V_7 [ V_164 ] |= V_565 ;
}
if ( V_65 -> V_566 [ V_164 ] && V_164 > 0 ) {
F_422 ( V_466 , V_65 -> V_566 [ V_164 ] ) ;
V_65 -> V_566 [ V_164 ] = 0 ;
}
return 0 ;
}
static T_1 int F_423 ( struct V_107 * V_108 ,
struct V_34 * V_35 ,
struct V_64 * V_65 ,
struct V_553 * V_554 , int * V_564 )
{
T_2 V_27 ;
T_2 V_272 ;
T_2 V_17 ;
T_3 V_538 ;
struct V_68 V_21 ;
struct V_66 * V_81 ;
int V_164 = V_554 -> V_164 ;
int V_76 = 0 ;
int V_29 = 0 ;
V_272 = F_418 ( V_65 -> V_83 [ V_164 ] ,
V_65 -> V_84 [ V_164 ] ) ;
if ( V_554 -> V_559 == V_560 &&
V_272 <= V_35 -> V_246 . V_33 ) {
* V_564 = 1 ;
return 1 ;
}
V_27 = F_219 ( V_65 -> V_83 [ V_164 ] , V_65 -> V_84 [ V_164 ] ) ;
V_538 = F_220 ( V_35 , V_164 - 1 ) ;
V_81 = F_424 ( V_35 , V_27 , V_538 ) ;
if ( ! V_81 ) {
V_81 = F_400 ( V_35 , V_27 , V_538 ) ;
if ( ! V_81 )
return - V_72 ;
F_403 ( V_35 -> V_246 . V_22 , V_81 ,
V_164 - 1 ) ;
V_76 = 1 ;
}
F_404 ( V_81 ) ;
F_406 ( V_81 ) ;
V_29 = F_75 ( V_108 , V_35 , V_27 , V_164 - 1 , 1 ,
& V_554 -> V_110 [ V_164 - 1 ] ,
& V_554 -> V_7 [ V_164 - 1 ] ) ;
if ( V_29 < 0 ) {
F_425 ( V_81 ) ;
return V_29 ;
}
if ( F_301 ( V_554 -> V_110 [ V_164 - 1 ] == 0 ) ) {
F_186 ( V_35 -> V_37 , L_35 ) ;
F_83 () ;
}
* V_564 = 0 ;
if ( V_554 -> V_559 == V_561 ) {
if ( V_554 -> V_110 [ V_164 - 1 ] > 1 ) {
if ( V_164 == 1 &&
( V_554 -> V_7 [ 0 ] & V_124 ) )
goto V_568;
if ( ! V_554 -> V_562 ||
V_272 <= V_35 -> V_246 . V_33 )
goto V_568;
F_123 ( V_65 -> V_83 [ V_164 ] , & V_21 ,
V_65 -> V_84 [ V_164 ] ) ;
V_29 = F_419 ( & V_21 , & V_554 -> V_563 ) ;
if ( V_29 < 0 )
goto V_568;
V_554 -> V_559 = V_560 ;
V_554 -> V_569 = V_164 - 1 ;
}
} else {
if ( V_164 == 1 &&
( V_554 -> V_7 [ 0 ] & V_124 ) )
goto V_568;
}
if ( ! F_426 ( V_81 , V_272 , 0 ) ) {
F_425 ( V_81 ) ;
F_427 ( V_81 ) ;
V_81 = NULL ;
* V_564 = 1 ;
}
if ( ! V_81 ) {
if ( V_76 && V_164 == 1 )
F_416 ( V_108 , V_35 , V_554 , V_65 ) ;
V_81 = F_428 ( V_35 , V_27 , V_538 , V_272 ) ;
if ( ! V_81 || ! F_429 ( V_81 ) ) {
F_427 ( V_81 ) ;
return - V_172 ;
}
F_404 ( V_81 ) ;
F_406 ( V_81 ) ;
}
V_164 -- ;
F_30 ( V_164 != F_213 ( V_81 ) ) ;
V_65 -> V_83 [ V_164 ] = V_81 ;
V_65 -> V_84 [ V_164 ] = 0 ;
V_65 -> V_566 [ V_164 ] = V_570 ;
V_554 -> V_164 = V_164 ;
if ( V_554 -> V_164 == 1 )
V_554 -> V_557 = 0 ;
return 0 ;
V_568:
V_554 -> V_110 [ V_164 - 1 ] = 0 ;
V_554 -> V_7 [ V_164 - 1 ] = 0 ;
if ( V_554 -> V_559 == V_561 ) {
if ( V_554 -> V_7 [ V_164 ] & V_124 ) {
V_17 = V_65 -> V_83 [ V_164 ] -> V_32 ;
} else {
F_30 ( V_35 -> V_246 . V_22 !=
F_212 ( V_65 -> V_83 [ V_164 ] ) ) ;
V_17 = 0 ;
}
V_29 = V_256 ( V_108 , V_35 , V_27 , V_538 , V_17 ,
V_35 -> V_246 . V_22 , V_164 - 1 , 0 , 0 ) ;
F_30 ( V_29 ) ;
}
F_425 ( V_81 ) ;
F_427 ( V_81 ) ;
* V_564 = 1 ;
return 1 ;
}
static T_1 int F_430 ( struct V_107 * V_108 ,
struct V_34 * V_35 ,
struct V_64 * V_65 ,
struct V_553 * V_554 )
{
int V_29 ;
int V_164 = V_554 -> V_164 ;
struct V_66 * V_466 = V_65 -> V_83 [ V_164 ] ;
T_2 V_17 = 0 ;
if ( V_554 -> V_559 == V_560 ) {
F_30 ( V_554 -> V_569 < V_164 ) ;
if ( V_164 < V_554 -> V_569 )
goto V_73;
V_29 = F_41 ( V_65 , V_164 + 1 , & V_554 -> V_563 ) ;
if ( V_29 > 0 )
V_554 -> V_562 = 0 ;
V_554 -> V_559 = V_561 ;
V_554 -> V_569 = - 1 ;
V_65 -> V_84 [ V_164 ] = 0 ;
if ( ! V_65 -> V_566 [ V_164 ] ) {
F_30 ( V_164 == 0 ) ;
F_404 ( V_466 ) ;
F_406 ( V_466 ) ;
V_65 -> V_566 [ V_164 ] = V_570 ;
V_29 = F_75 ( V_108 , V_35 ,
V_466 -> V_32 , V_164 , 1 ,
& V_554 -> V_110 [ V_164 ] ,
& V_554 -> V_7 [ V_164 ] ) ;
if ( V_29 < 0 ) {
F_422 ( V_466 , V_65 -> V_566 [ V_164 ] ) ;
V_65 -> V_566 [ V_164 ] = 0 ;
return V_29 ;
}
F_30 ( V_554 -> V_110 [ V_164 ] == 0 ) ;
if ( V_554 -> V_110 [ V_164 ] == 1 ) {
F_422 ( V_466 , V_65 -> V_566 [ V_164 ] ) ;
V_65 -> V_566 [ V_164 ] = 0 ;
return 1 ;
}
}
}
F_30 ( V_554 -> V_110 [ V_164 ] > 1 && ! V_65 -> V_566 [ V_164 ] ) ;
if ( V_554 -> V_110 [ V_164 ] == 1 ) {
if ( V_164 == 0 ) {
if ( V_554 -> V_7 [ V_164 ] & V_124 )
V_29 = F_222 ( V_108 , V_35 , V_466 , 1 ,
V_554 -> V_567 ) ;
else
V_29 = F_222 ( V_108 , V_35 , V_466 , 0 ,
V_554 -> V_567 ) ;
F_30 ( V_29 ) ;
}
if ( ! V_65 -> V_566 [ V_164 ] &&
F_369 ( V_466 ) == V_108 -> V_269 ) {
F_404 ( V_466 ) ;
F_406 ( V_466 ) ;
V_65 -> V_566 [ V_164 ] = V_570 ;
}
F_405 ( V_108 , V_35 , V_466 ) ;
}
if ( V_466 == V_35 -> V_126 ) {
if ( V_554 -> V_7 [ V_164 ] & V_124 )
V_17 = V_466 -> V_32 ;
else
F_30 ( V_35 -> V_246 . V_22 !=
F_212 ( V_466 ) ) ;
} else {
if ( V_554 -> V_7 [ V_164 + 1 ] & V_124 )
V_17 = V_65 -> V_83 [ V_164 + 1 ] -> V_32 ;
else
F_30 ( V_35 -> V_246 . V_22 !=
F_212 ( V_65 -> V_83 [ V_164 + 1 ] ) ) ;
}
F_368 ( V_108 , V_35 , V_466 , V_17 , V_554 -> V_110 [ V_164 ] == 1 ) ;
V_73:
V_554 -> V_110 [ V_164 ] = 0 ;
V_554 -> V_7 [ V_164 ] = 0 ;
return 0 ;
}
static T_1 int F_431 ( struct V_107 * V_108 ,
struct V_34 * V_35 ,
struct V_64 * V_65 ,
struct V_553 * V_554 )
{
int V_164 = V_554 -> V_164 ;
int V_564 = 1 ;
int V_29 ;
while ( V_164 >= 0 ) {
V_29 = F_421 ( V_108 , V_35 , V_65 , V_554 , V_564 ) ;
if ( V_29 > 0 )
break;
if ( V_164 == 0 )
break;
if ( V_65 -> V_84 [ V_164 ] >=
F_38 ( V_65 -> V_83 [ V_164 ] ) )
break;
V_29 = F_423 ( V_108 , V_35 , V_65 , V_554 , & V_564 ) ;
if ( V_29 > 0 ) {
V_65 -> V_84 [ V_164 ] ++ ;
continue;
} else if ( V_29 < 0 )
return V_29 ;
V_164 = V_554 -> V_164 ;
}
return 0 ;
}
static T_1 int F_432 ( struct V_107 * V_108 ,
struct V_34 * V_35 ,
struct V_64 * V_65 ,
struct V_553 * V_554 , int V_571 )
{
int V_164 = V_554 -> V_164 ;
int V_29 ;
V_65 -> V_84 [ V_164 ] = F_38 ( V_65 -> V_83 [ V_164 ] ) ;
while ( V_164 < V_571 && V_65 -> V_83 [ V_164 ] ) {
V_554 -> V_164 = V_164 ;
if ( V_65 -> V_84 [ V_164 ] + 1 <
F_38 ( V_65 -> V_83 [ V_164 ] ) ) {
V_65 -> V_84 [ V_164 ] ++ ;
return 0 ;
} else {
V_29 = F_430 ( V_108 , V_35 , V_65 , V_554 ) ;
if ( V_29 > 0 )
return 0 ;
if ( V_65 -> V_566 [ V_164 ] ) {
F_422 ( V_65 -> V_83 [ V_164 ] ,
V_65 -> V_566 [ V_164 ] ) ;
V_65 -> V_566 [ V_164 ] = 0 ;
}
F_427 ( V_65 -> V_83 [ V_164 ] ) ;
V_65 -> V_83 [ V_164 ] = NULL ;
V_164 ++ ;
}
}
return 1 ;
}
int F_433 ( struct V_34 * V_35 ,
struct V_236 * V_377 , int V_562 ,
int V_567 )
{
struct V_64 * V_65 ;
struct V_107 * V_108 ;
struct V_34 * V_87 = V_35 -> V_37 -> V_87 ;
struct V_572 * V_247 = & V_35 -> V_247 ;
struct V_553 * V_554 ;
struct V_68 V_21 ;
int V_82 = 0 ;
int V_29 ;
int V_164 ;
bool V_573 = false ;
V_65 = F_33 () ;
if ( ! V_65 ) {
V_82 = - V_72 ;
goto V_73;
}
V_554 = F_53 ( sizeof( * V_554 ) , V_40 ) ;
if ( ! V_554 ) {
F_50 ( V_65 ) ;
V_82 = - V_72 ;
goto V_73;
}
V_108 = F_434 ( V_87 , 0 ) ;
if ( F_229 ( V_108 ) ) {
V_82 = F_230 ( V_108 ) ;
goto V_121;
}
if ( V_377 )
V_108 -> V_377 = V_377 ;
if ( F_435 ( & V_247 -> V_574 ) == 0 ) {
V_164 = F_213 ( V_35 -> V_126 ) ;
V_65 -> V_83 [ V_164 ] = F_436 ( V_35 ) ;
F_406 ( V_65 -> V_83 [ V_164 ] ) ;
V_65 -> V_84 [ V_164 ] = 0 ;
V_65 -> V_566 [ V_164 ] = V_570 ;
memset ( & V_554 -> V_563 , 0 ,
sizeof( V_554 -> V_563 ) ) ;
} else {
F_437 ( & V_21 , & V_247 -> V_574 ) ;
memcpy ( & V_554 -> V_563 , & V_21 ,
sizeof( V_554 -> V_563 ) ) ;
V_164 = V_247 -> V_575 ;
F_30 ( V_164 == 0 ) ;
V_65 -> V_576 = V_164 ;
V_29 = F_37 ( NULL , V_35 , & V_21 , V_65 , 0 , 0 ) ;
V_65 -> V_576 = 0 ;
if ( V_29 < 0 ) {
V_82 = V_29 ;
goto V_577;
}
F_8 ( V_29 > 0 ) ;
F_128 ( V_65 , 0 ) ;
V_164 = F_213 ( V_35 -> V_126 ) ;
while ( 1 ) {
F_404 ( V_65 -> V_83 [ V_164 ] ) ;
F_406 ( V_65 -> V_83 [ V_164 ] ) ;
V_65 -> V_566 [ V_164 ] = V_570 ;
V_29 = F_75 ( V_108 , V_35 ,
V_65 -> V_83 [ V_164 ] -> V_32 ,
V_164 , 1 , & V_554 -> V_110 [ V_164 ] ,
& V_554 -> V_7 [ V_164 ] ) ;
if ( V_29 < 0 ) {
V_82 = V_29 ;
goto V_577;
}
F_30 ( V_554 -> V_110 [ V_164 ] == 0 ) ;
if ( V_164 == V_247 -> V_575 )
break;
F_425 ( V_65 -> V_83 [ V_164 ] ) ;
V_65 -> V_566 [ V_164 ] = 0 ;
F_8 ( V_554 -> V_110 [ V_164 ] != 1 ) ;
V_164 -- ;
}
}
V_554 -> V_164 = V_164 ;
V_554 -> V_569 = - 1 ;
V_554 -> V_559 = V_561 ;
V_554 -> V_562 = V_562 ;
V_554 -> V_171 = 0 ;
V_554 -> V_567 = V_567 ;
V_554 -> V_558 = F_417 ( V_35 ) ;
while ( 1 ) {
V_29 = F_431 ( V_108 , V_35 , V_65 , V_554 ) ;
if ( V_29 < 0 ) {
V_82 = V_29 ;
break;
}
V_29 = F_432 ( V_108 , V_35 , V_65 , V_554 , V_165 ) ;
if ( V_29 < 0 ) {
V_82 = V_29 ;
break;
}
if ( V_29 > 0 ) {
F_30 ( V_554 -> V_559 != V_561 ) ;
break;
}
if ( V_554 -> V_559 == V_561 ) {
V_164 = V_554 -> V_164 ;
F_438 ( V_65 -> V_83 [ V_164 ] ,
& V_247 -> V_574 ,
V_65 -> V_84 [ V_164 ] ) ;
V_247 -> V_575 = V_164 ;
}
F_30 ( V_554 -> V_164 == 0 ) ;
if ( F_439 ( V_108 , V_87 ) ||
( ! V_567 && F_440 ( V_35 ) ) ) {
V_29 = F_441 ( V_108 , V_87 ,
& V_35 -> V_246 ,
V_247 ) ;
if ( V_29 ) {
F_148 ( V_108 , V_87 , V_29 ) ;
V_82 = V_29 ;
goto V_577;
}
F_442 ( V_108 , V_87 ) ;
if ( ! V_567 && F_440 ( V_35 ) ) {
F_443 ( L_36 ) ;
V_82 = - V_175 ;
goto V_121;
}
V_108 = F_434 ( V_87 , 0 ) ;
if ( F_229 ( V_108 ) ) {
V_82 = F_230 ( V_108 ) ;
goto V_121;
}
if ( V_377 )
V_108 -> V_377 = V_377 ;
}
}
F_44 ( V_65 ) ;
if ( V_82 )
goto V_577;
V_29 = F_444 ( V_108 , V_87 , & V_35 -> V_246 ) ;
if ( V_29 ) {
F_148 ( V_108 , V_87 , V_29 ) ;
goto V_577;
}
if ( V_35 -> V_246 . V_22 != V_552 ) {
V_29 = F_445 ( V_87 , & V_35 -> V_246 , V_65 ,
NULL , NULL ) ;
if ( V_29 < 0 ) {
F_148 ( V_108 , V_87 , V_29 ) ;
V_82 = V_29 ;
goto V_577;
} else if ( V_29 > 0 ) {
F_446 ( V_108 , V_87 ,
V_35 -> V_246 . V_22 ) ;
}
}
if ( V_35 -> V_578 ) {
F_447 ( V_87 -> V_37 , V_35 ) ;
} else {
F_427 ( V_35 -> V_126 ) ;
F_427 ( V_35 -> V_579 ) ;
F_448 ( V_35 ) ;
}
V_573 = true ;
V_577:
F_442 ( V_108 , V_87 ) ;
V_121:
F_9 ( V_554 ) ;
F_50 ( V_65 ) ;
V_73:
if ( ! V_567 && V_573 == false )
F_449 ( V_35 ) ;
if ( V_82 && V_82 != - V_175 )
F_450 ( V_35 -> V_37 , V_82 ) ;
return V_82 ;
}
int F_451 ( struct V_107 * V_108 ,
struct V_34 * V_35 ,
struct V_66 * V_126 ,
struct V_66 * V_17 )
{
struct V_64 * V_65 ;
struct V_553 * V_554 ;
int V_164 ;
int V_580 ;
int V_29 = 0 ;
int V_581 ;
F_30 ( V_35 -> V_246 . V_22 != V_552 ) ;
V_65 = F_33 () ;
if ( ! V_65 )
return - V_72 ;
V_554 = F_53 ( sizeof( * V_554 ) , V_40 ) ;
if ( ! V_554 ) {
F_50 ( V_65 ) ;
return - V_72 ;
}
F_452 ( V_17 ) ;
V_580 = F_213 ( V_17 ) ;
F_453 ( V_17 ) ;
V_65 -> V_83 [ V_580 ] = V_17 ;
V_65 -> V_84 [ V_580 ] = F_38 ( V_17 ) ;
F_452 ( V_126 ) ;
V_164 = F_213 ( V_126 ) ;
V_65 -> V_83 [ V_164 ] = V_126 ;
V_65 -> V_84 [ V_164 ] = 0 ;
V_65 -> V_566 [ V_164 ] = V_570 ;
V_554 -> V_110 [ V_580 ] = 1 ;
V_554 -> V_7 [ V_580 ] = V_124 ;
V_554 -> V_164 = V_164 ;
V_554 -> V_569 = - 1 ;
V_554 -> V_559 = V_561 ;
V_554 -> V_562 = 0 ;
V_554 -> V_171 = 1 ;
V_554 -> V_567 = 1 ;
V_554 -> V_558 = F_417 ( V_35 ) ;
while ( 1 ) {
V_581 = F_431 ( V_108 , V_35 , V_65 , V_554 ) ;
if ( V_581 < 0 ) {
V_29 = V_581 ;
break;
}
V_581 = F_432 ( V_108 , V_35 , V_65 , V_554 , V_580 ) ;
if ( V_581 < 0 )
V_29 = V_581 ;
if ( V_581 != 0 )
break;
}
F_9 ( V_554 ) ;
F_50 ( V_65 ) ;
return V_29 ;
}
static T_2 F_454 ( struct V_34 * V_35 , T_2 V_7 )
{
T_2 V_322 ;
T_2 V_582 ;
V_582 = F_257 ( V_35 -> V_37 , V_7 ) ;
if ( V_582 )
return F_259 ( V_582 ) ;
V_322 = V_35 -> V_37 -> V_323 -> V_324 +
V_35 -> V_37 -> V_323 -> V_325 ;
V_582 = V_328 |
V_329 | V_330 |
V_286 | V_287 ;
if ( V_322 == 1 ) {
V_582 |= V_285 ;
V_582 = V_7 & ~ V_582 ;
if ( V_7 & V_328 )
return V_582 ;
if ( V_7 & ( V_286 |
V_287 ) )
return V_582 | V_285 ;
} else {
if ( V_7 & V_582 )
return V_7 ;
V_582 |= V_285 ;
V_582 = V_7 & ~ V_582 ;
if ( V_7 & V_285 )
return V_582 | V_286 ;
}
return V_7 ;
}
static int F_455 ( struct V_1 * V_2 , int V_348 )
{
struct V_100 * V_347 = V_2 -> V_103 ;
T_2 V_36 ;
T_2 V_583 ;
int V_29 = - V_343 ;
if ( ( V_347 -> V_7 &
( V_281 | V_279 ) ) &&
! V_348 )
V_583 = 1 * 1024 * 1024 ;
else
V_583 = 0 ;
F_11 ( & V_347 -> V_52 ) ;
F_11 ( & V_2 -> V_52 ) ;
if ( V_2 -> V_267 ) {
V_29 = 0 ;
goto V_73;
}
V_36 = V_2 -> V_21 . V_33 - V_2 -> V_10 - V_2 -> V_9 -
V_2 -> V_46 - F_345 ( & V_2 -> V_133 ) ;
if ( V_347 -> V_283 + V_347 -> V_297 + V_347 -> V_296 +
V_347 -> V_299 + V_347 -> V_298 + V_36 +
V_583 <= V_347 -> V_282 ) {
V_347 -> V_298 += V_36 ;
V_2 -> V_267 = 1 ;
V_29 = 0 ;
}
V_73:
F_13 ( & V_2 -> V_52 ) ;
F_13 ( & V_347 -> V_52 ) ;
return V_29 ;
}
int F_456 ( struct V_34 * V_35 ,
struct V_1 * V_2 )
{
struct V_107 * V_108 ;
T_2 V_584 ;
int V_29 ;
F_30 ( V_2 -> V_267 ) ;
V_108 = F_266 ( V_35 ) ;
if ( F_229 ( V_108 ) )
return F_230 ( V_108 ) ;
V_584 = F_454 ( V_35 , V_2 -> V_7 ) ;
if ( V_584 != V_2 -> V_7 ) {
V_29 = F_267 ( V_108 , V_35 , V_584 ,
V_342 ) ;
if ( V_29 < 0 )
goto V_73;
}
V_29 = F_455 ( V_2 , 0 ) ;
if ( ! V_29 )
goto V_73;
V_584 = F_260 ( V_35 , V_2 -> V_103 -> V_7 ) ;
V_29 = F_267 ( V_108 , V_35 , V_584 ,
V_342 ) ;
if ( V_29 < 0 )
goto V_73;
V_29 = F_455 ( V_2 , 0 ) ;
V_73:
F_268 ( V_108 , V_35 ) ;
return V_29 ;
}
int F_457 ( struct V_107 * V_108 ,
struct V_34 * V_35 , T_2 type )
{
T_2 V_584 = F_260 ( V_35 , type ) ;
return F_267 ( V_108 , V_35 , V_584 ,
V_342 ) ;
}
static T_2 F_458 ( struct V_101 * V_585 )
{
struct V_1 * V_14 ;
T_2 V_586 = 0 ;
int V_284 ;
F_382 (block_group, groups_list, list) {
F_11 ( & V_14 -> V_52 ) ;
if ( ! V_14 -> V_267 ) {
F_13 ( & V_14 -> V_52 ) ;
continue;
}
if ( V_14 -> V_7 & ( V_286 |
V_287 |
V_285 ) )
V_284 = 2 ;
else
V_284 = 1 ;
V_586 += ( V_14 -> V_21 . V_33 -
F_345 ( & V_14 -> V_133 ) ) *
V_284 ;
F_13 ( & V_14 -> V_52 ) ;
}
return V_586 ;
}
T_2 F_459 ( struct V_100 * V_347 )
{
int V_43 ;
T_2 V_586 = 0 ;
F_11 ( & V_347 -> V_52 ) ;
for ( V_43 = 0 ; V_43 < V_291 ; V_43 ++ )
if ( ! F_185 ( & V_347 -> V_292 [ V_43 ] ) )
V_586 += F_458 (
& V_347 -> V_292 [ V_43 ] ) ;
F_13 ( & V_347 -> V_52 ) ;
return V_586 ;
}
void F_460 ( struct V_34 * V_35 ,
struct V_1 * V_2 )
{
struct V_100 * V_347 = V_2 -> V_103 ;
T_2 V_36 ;
F_30 ( ! V_2 -> V_267 ) ;
F_11 ( & V_347 -> V_52 ) ;
F_11 ( & V_2 -> V_52 ) ;
V_36 = V_2 -> V_21 . V_33 - V_2 -> V_10 - V_2 -> V_9 -
V_2 -> V_46 - F_345 ( & V_2 -> V_133 ) ;
V_347 -> V_298 -= V_36 ;
V_2 -> V_267 = 0 ;
F_13 ( & V_2 -> V_52 ) ;
F_13 ( & V_347 -> V_52 ) ;
}
int F_461 ( struct V_34 * V_35 , T_2 V_27 )
{
struct V_1 * V_14 ;
struct V_100 * V_103 ;
struct V_587 * V_323 = V_35 -> V_37 -> V_323 ;
struct V_588 * V_589 ;
struct V_107 * V_108 ;
T_2 V_590 ;
T_2 V_591 = 1 ;
T_2 V_592 = 0 ;
T_2 V_317 ;
int V_507 ;
int V_106 = 0 ;
int V_29 = 0 ;
V_14 = F_68 ( V_35 -> V_37 , V_27 ) ;
if ( ! V_14 )
return - 1 ;
V_590 = F_345 ( & V_14 -> V_133 ) ;
if ( ! V_590 )
goto V_73;
V_103 = V_14 -> V_103 ;
F_11 ( & V_103 -> V_52 ) ;
V_106 = V_103 -> V_106 ;
if ( ( V_103 -> V_282 != V_14 -> V_21 . V_33 ) &&
( V_103 -> V_283 + V_103 -> V_297 +
V_103 -> V_296 + V_103 -> V_298 +
V_590 < V_103 -> V_282 ) ) {
F_13 ( & V_103 -> V_52 ) ;
goto V_73;
}
F_13 ( & V_103 -> V_52 ) ;
V_29 = - 1 ;
V_317 = F_257 ( V_35 -> V_37 , V_14 -> V_7 ) ;
if ( V_317 ) {
V_507 = F_375 ( F_259 ( V_317 ) ) ;
} else {
if ( V_106 )
goto V_73;
V_507 = F_376 ( V_14 ) ;
}
if ( V_507 == V_490 ) {
V_591 = 4 ;
V_590 >>= 1 ;
} else if ( V_507 == V_491 ) {
V_591 = 2 ;
} else if ( V_507 == V_492 ) {
V_590 <<= 1 ;
} else if ( V_507 == V_493 ) {
V_591 = V_323 -> V_324 ;
F_462 ( V_590 , V_591 ) ;
}
V_108 = F_266 ( V_35 ) ;
if ( F_229 ( V_108 ) ) {
V_29 = F_230 ( V_108 ) ;
goto V_73;
}
F_35 ( & V_35 -> V_37 -> V_358 ) ;
F_382 (device, &fs_devices->alloc_list, dev_alloc_list) {
T_2 V_593 ;
if ( V_589 -> V_282 > V_589 -> V_283 + V_590 &&
! V_589 -> V_594 ) {
V_29 = F_463 ( V_108 , V_589 , V_590 ,
& V_593 , NULL ) ;
if ( ! V_29 )
V_592 ++ ;
if ( V_592 >= V_591 )
break;
V_29 = - 1 ;
}
}
F_46 ( & V_35 -> V_37 -> V_358 ) ;
F_268 ( V_108 , V_35 ) ;
V_73:
F_6 ( V_14 ) ;
return V_29 ;
}
static int F_464 ( struct V_34 * V_35 ,
struct V_64 * V_65 , struct V_68 * V_21 )
{
int V_29 = 0 ;
struct V_68 V_138 ;
struct V_66 * V_67 ;
int V_555 ;
V_29 = F_37 ( NULL , V_35 , V_21 , V_65 , 0 , 0 ) ;
if ( V_29 < 0 )
goto V_73;
while ( 1 ) {
V_555 = V_65 -> V_84 [ 0 ] ;
V_67 = V_65 -> V_83 [ 0 ] ;
if ( V_555 >= F_38 ( V_67 ) ) {
V_29 = F_48 ( V_35 , V_65 ) ;
if ( V_29 == 0 )
continue;
if ( V_29 < 0 )
goto V_73;
break;
}
F_40 ( V_67 , & V_138 , V_555 ) ;
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
void F_465 ( struct V_12 * V_13 )
{
struct V_1 * V_14 ;
T_2 V_70 = 0 ;
while ( 1 ) {
struct V_259 * V_259 ;
V_14 = F_67 ( V_13 , V_70 ) ;
while ( V_14 ) {
F_11 ( & V_14 -> V_52 ) ;
if ( V_14 -> V_161 )
break;
F_13 ( & V_14 -> V_52 ) ;
V_14 = F_226 ( V_13 -> V_87 ,
V_14 ) ;
}
if ( ! V_14 ) {
if ( V_70 == 0 )
break;
V_70 = 0 ;
continue;
}
V_259 = V_14 -> V_259 ;
V_14 -> V_161 = 0 ;
V_14 -> V_259 = NULL ;
F_13 ( & V_14 -> V_52 ) ;
F_241 ( V_259 ) ;
V_70 = V_14 -> V_21 . V_22 + V_14 -> V_21 . V_33 ;
F_6 ( V_14 ) ;
}
}
int F_466 ( struct V_12 * V_13 )
{
struct V_1 * V_14 ;
struct V_100 * V_103 ;
struct V_50 * V_54 ;
struct V_15 * V_30 ;
F_63 ( & V_13 -> V_80 ) ;
while ( ! F_185 ( & V_13 -> V_98 ) ) {
V_54 = F_467 ( V_13 -> V_98 . V_81 ,
struct V_50 , V_91 ) ;
F_188 ( & V_54 -> V_91 ) ;
F_26 ( V_54 ) ;
}
F_65 ( & V_13 -> V_80 ) ;
F_11 ( & V_13 -> V_18 ) ;
while ( ( V_30 = F_183 ( & V_13 -> V_19 ) ) != NULL ) {
V_14 = F_12 ( V_30 , struct V_1 ,
V_20 ) ;
F_177 ( & V_14 -> V_20 ,
& V_13 -> V_19 ) ;
F_13 ( & V_13 -> V_18 ) ;
F_63 ( & V_14 -> V_103 -> V_295 ) ;
F_188 ( & V_14 -> V_91 ) ;
F_65 ( & V_14 -> V_103 -> V_295 ) ;
if ( V_14 -> V_3 == V_53 )
F_374 ( V_14 ) ;
if ( V_14 -> V_3 == V_94 ||
V_14 -> V_3 == V_5 )
F_19 ( V_13 -> V_63 , V_14 ) ;
F_468 ( V_14 ) ;
F_6 ( V_14 ) ;
F_11 ( & V_13 -> V_18 ) ;
}
F_13 ( & V_13 -> V_18 ) ;
F_469 () ;
F_322 ( V_13 ) ;
while ( ! F_185 ( & V_13 -> V_103 ) ) {
int V_43 ;
V_103 = F_467 ( V_13 -> V_103 . V_81 ,
struct V_100 ,
V_91 ) ;
if ( F_237 ( V_13 -> V_87 , V_355 ) ) {
if ( F_8 ( V_103 -> V_296 > 0 ||
V_103 -> V_297 > 0 ||
V_103 -> V_299 > 0 ) ) {
F_281 ( V_103 , 0 , 0 ) ;
}
}
F_188 ( & V_103 -> V_91 ) ;
for ( V_43 = 0 ; V_43 < V_291 ; V_43 ++ ) {
struct V_595 * V_304 ;
V_304 = & V_103 -> V_293 [ V_43 ] ;
if ( V_304 -> V_17 ) {
F_470 ( V_304 ) ;
F_471 ( V_304 ) ;
}
}
F_470 ( & V_103 -> V_304 ) ;
F_471 ( & V_103 -> V_304 ) ;
}
return 0 ;
}
static void F_472 ( struct V_100 * V_103 ,
struct V_1 * V_2 )
{
int V_507 = F_376 ( V_2 ) ;
bool V_231 = false ;
F_63 ( & V_103 -> V_295 ) ;
if ( F_185 ( & V_103 -> V_292 [ V_507 ] ) )
V_231 = true ;
F_64 ( & V_2 -> V_91 , & V_103 -> V_292 [ V_507 ] ) ;
F_65 ( & V_103 -> V_295 ) ;
if ( V_231 ) {
struct V_595 * V_304 = & V_103 -> V_293 [ V_507 ] ;
int V_29 ;
F_473 ( & V_103 -> V_304 ) ;
V_29 = F_474 ( V_304 , & V_103 -> V_304 , L_11 ,
F_377 ( V_507 ) ) ;
if ( V_29 ) {
F_475 ( L_37 ) ;
F_471 ( & V_103 -> V_304 ) ;
}
}
}
static struct V_1 *
F_476 ( struct V_34 * V_35 , T_2 V_32 , T_2 V_57 )
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
V_2 -> V_21 . type = V_176 ;
V_2 -> V_337 = V_35 -> V_337 ;
V_2 -> V_37 = V_35 -> V_37 ;
V_2 -> V_596 = F_477 ( V_35 ,
& V_35 -> V_37 -> V_48 ,
V_32 ) ;
F_57 ( & V_2 -> V_8 , 1 ) ;
F_250 ( & V_2 -> V_52 ) ;
F_54 ( & V_2 -> V_91 ) ;
F_54 ( & V_2 -> V_597 ) ;
F_54 ( & V_2 -> V_598 ) ;
F_478 ( V_2 ) ;
return V_2 ;
}
int F_479 ( struct V_34 * V_35 )
{
struct V_64 * V_65 ;
int V_29 ;
struct V_1 * V_2 ;
struct V_12 * V_13 = V_35 -> V_37 ;
struct V_100 * V_103 ;
struct V_68 V_21 ;
struct V_68 V_138 ;
struct V_66 * V_67 ;
int V_599 = 0 ;
T_2 V_600 ;
V_35 = V_13 -> V_63 ;
V_21 . V_22 = 0 ;
V_21 . V_33 = 0 ;
F_379 ( & V_21 , V_176 ) ;
V_65 = F_33 () ;
if ( ! V_65 )
return - V_72 ;
V_65 -> V_76 = 1 ;
V_600 = F_480 ( V_35 -> V_37 -> V_352 ) ;
if ( F_237 ( V_35 , V_273 ) &&
F_481 ( V_35 -> V_37 -> V_352 ) != V_600 )
V_599 = 1 ;
if ( F_237 ( V_35 , V_601 ) )
V_599 = 1 ;
while ( 1 ) {
V_29 = F_464 ( V_35 , V_65 , & V_21 ) ;
if ( V_29 > 0 )
break;
if ( V_29 != 0 )
goto error;
V_67 = V_65 -> V_83 [ 0 ] ;
F_40 ( V_67 , & V_138 , V_65 -> V_84 [ 0 ] ) ;
V_2 = F_476 ( V_35 , V_138 . V_22 ,
V_138 . V_33 ) ;
if ( ! V_2 ) {
V_29 = - V_72 ;
goto error;
}
if ( V_599 ) {
V_2 -> V_265 = V_275 ;
if ( F_237 ( V_35 , V_273 ) )
V_2 -> V_276 = 1 ;
}
F_482 ( V_67 , & V_2 -> V_133 ,
F_224 ( V_67 , V_65 -> V_84 [ 0 ] ) ,
sizeof( V_2 -> V_133 ) ) ;
V_2 -> V_7 = F_483 ( & V_2 -> V_133 ) ;
V_21 . V_22 = V_138 . V_22 + V_138 . V_33 ;
F_44 ( V_65 ) ;
V_29 = F_21 ( V_35 , V_2 ) ;
if ( V_29 ) {
F_19 ( V_35 , V_2 ) ;
F_6 ( V_2 ) ;
goto error;
}
if ( V_138 . V_33 == F_345 ( & V_2 -> V_133 ) ) {
V_2 -> V_97 = ( T_2 ) - 1 ;
V_2 -> V_3 = V_4 ;
F_19 ( V_35 , V_2 ) ;
} else if ( F_345 ( & V_2 -> V_133 ) == 0 ) {
V_2 -> V_97 = ( T_2 ) - 1 ;
V_2 -> V_3 = V_4 ;
F_27 ( V_2 , V_35 -> V_37 ,
V_138 . V_22 ,
V_138 . V_22 +
V_138 . V_33 ) ;
F_19 ( V_35 , V_2 ) ;
}
V_29 = F_10 ( V_35 -> V_37 , V_2 ) ;
if ( V_29 ) {
F_468 ( V_2 ) ;
F_6 ( V_2 ) ;
goto error;
}
V_29 = F_246 ( V_13 , V_2 -> V_7 , V_138 . V_33 ,
F_345 ( & V_2 -> V_133 ) ,
& V_103 ) ;
if ( V_29 ) {
F_468 ( V_2 ) ;
F_11 ( & V_13 -> V_18 ) ;
F_177 ( & V_2 -> V_20 ,
& V_13 -> V_19 ) ;
F_13 ( & V_13 -> V_18 ) ;
F_6 ( V_2 ) ;
goto error;
}
V_2 -> V_103 = V_103 ;
F_11 ( & V_2 -> V_103 -> V_52 ) ;
V_2 -> V_103 -> V_298 += V_2 -> V_46 ;
F_13 ( & V_2 -> V_103 -> V_52 ) ;
F_472 ( V_103 , V_2 ) ;
F_253 ( V_35 -> V_37 , V_2 -> V_7 ) ;
if ( F_484 ( V_35 , V_2 -> V_21 . V_22 ) )
F_455 ( V_2 , 1 ) ;
}
F_71 (space_info, &root->fs_info->space_info, list) {
if ( ! ( F_260 ( V_35 , V_103 -> V_7 ) &
( V_287 |
V_286 |
V_329 |
V_330 |
V_285 ) ) )
continue;
F_382 (cache,
&space_info->block_groups[BTRFS_RAID_RAID0],
list)
F_455 ( V_2 , 1 ) ;
F_382 (cache,
&space_info->block_groups[BTRFS_RAID_SINGLE],
list)
F_455 ( V_2 , 1 ) ;
}
F_321 ( V_13 ) ;
V_29 = 0 ;
error:
F_50 ( V_65 ) ;
return V_29 ;
}
void F_199 ( struct V_107 * V_108 ,
struct V_34 * V_35 )
{
struct V_1 * V_14 , * V_326 ;
struct V_34 * V_63 = V_35 -> V_37 -> V_63 ;
struct V_602 V_133 ;
struct V_68 V_21 ;
int V_29 = 0 ;
F_356 (block_group, tmp, &trans->new_bgs,
new_bg_list) {
F_357 ( & V_14 -> V_598 ) ;
if ( V_29 )
continue;
F_11 ( & V_14 -> V_52 ) ;
memcpy ( & V_133 , & V_14 -> V_133 , sizeof( V_133 ) ) ;
memcpy ( & V_21 , & V_14 -> V_21 , sizeof( V_21 ) ) ;
F_13 ( & V_14 -> V_52 ) ;
V_29 = F_485 ( V_108 , V_63 , & V_21 , & V_133 ,
sizeof( V_133 ) ) ;
if ( V_29 )
F_148 ( V_108 , V_63 , V_29 ) ;
V_29 = F_486 ( V_108 , V_63 ,
V_21 . V_22 , V_21 . V_33 ) ;
if ( V_29 )
F_148 ( V_108 , V_63 , V_29 ) ;
}
}
int F_487 ( struct V_107 * V_108 ,
struct V_34 * V_35 , T_2 V_283 ,
T_2 type , T_2 V_603 , T_2 V_604 ,
T_2 V_57 )
{
int V_29 ;
struct V_34 * V_63 ;
struct V_1 * V_2 ;
V_63 = V_35 -> V_37 -> V_63 ;
V_35 -> V_37 -> V_605 = V_108 -> V_269 ;
V_2 = F_476 ( V_35 , V_604 , V_57 ) ;
if ( ! V_2 )
return - V_72 ;
F_346 ( & V_2 -> V_133 , V_283 ) ;
F_488 ( & V_2 -> V_133 , V_603 ) ;
F_489 ( & V_2 -> V_133 , type ) ;
V_2 -> V_7 = type ;
V_2 -> V_97 = ( T_2 ) - 1 ;
V_2 -> V_3 = V_4 ;
V_29 = F_21 ( V_35 , V_2 ) ;
if ( V_29 ) {
F_19 ( V_35 , V_2 ) ;
F_6 ( V_2 ) ;
return V_29 ;
}
F_27 ( V_2 , V_35 -> V_37 , V_604 ,
V_604 + V_57 ) ;
F_19 ( V_35 , V_2 ) ;
V_29 = F_10 ( V_35 -> V_37 , V_2 ) ;
if ( V_29 ) {
F_468 ( V_2 ) ;
F_6 ( V_2 ) ;
return V_29 ;
}
V_29 = F_246 ( V_35 -> V_37 , V_2 -> V_7 , V_57 , V_283 ,
& V_2 -> V_103 ) ;
if ( V_29 ) {
F_468 ( V_2 ) ;
F_11 ( & V_35 -> V_37 -> V_18 ) ;
F_177 ( & V_2 -> V_20 ,
& V_35 -> V_37 -> V_19 ) ;
F_13 ( & V_35 -> V_37 -> V_18 ) ;
F_6 ( V_2 ) ;
return V_29 ;
}
F_320 ( V_35 -> V_37 ) ;
F_11 ( & V_2 -> V_103 -> V_52 ) ;
V_2 -> V_103 -> V_298 += V_2 -> V_46 ;
F_13 ( & V_2 -> V_103 -> V_52 ) ;
F_472 ( V_2 -> V_103 , V_2 ) ;
F_64 ( & V_2 -> V_598 , & V_108 -> V_244 ) ;
F_253 ( V_63 -> V_37 , type ) ;
return 0 ;
}
static void F_490 ( struct V_12 * V_37 , T_2 V_7 )
{
T_2 V_308 = F_254 ( V_7 ) &
V_309 ;
F_255 ( & V_37 -> V_310 ) ;
if ( V_7 & V_280 )
V_37 -> V_311 &= ~ V_308 ;
if ( V_7 & V_279 )
V_37 -> V_312 &= ~ V_308 ;
if ( V_7 & V_281 )
V_37 -> V_313 &= ~ V_308 ;
F_256 ( & V_37 -> V_310 ) ;
}
int F_491 ( struct V_107 * V_108 ,
struct V_34 * V_35 , T_2 V_606 )
{
struct V_64 * V_65 ;
struct V_1 * V_14 ;
struct V_502 * V_607 ;
struct V_34 * V_87 = V_35 -> V_37 -> V_87 ;
struct V_68 V_21 ;
struct V_259 * V_259 ;
int V_29 ;
int V_507 ;
int V_284 ;
V_35 = V_35 -> V_37 -> V_63 ;
V_14 = F_68 ( V_35 -> V_37 , V_606 ) ;
F_30 ( ! V_14 ) ;
F_30 ( ! V_14 -> V_267 ) ;
F_19 ( V_35 , V_14 ) ;
memcpy ( & V_21 , & V_14 -> V_21 , sizeof( V_21 ) ) ;
V_507 = F_376 ( V_14 ) ;
if ( V_14 -> V_7 & ( V_285 |
V_286 |
V_287 ) )
V_284 = 2 ;
else
V_284 = 1 ;
V_607 = & V_35 -> V_37 -> V_516 ;
F_11 ( & V_607 -> V_523 ) ;
F_385 ( V_14 , V_607 ) ;
F_13 ( & V_607 -> V_523 ) ;
V_607 = & V_35 -> V_37 -> V_514 ;
F_11 ( & V_607 -> V_523 ) ;
F_385 ( V_14 , V_607 ) ;
F_13 ( & V_607 -> V_523 ) ;
V_65 = F_33 () ;
if ( ! V_65 ) {
V_29 = - V_72 ;
goto V_73;
}
V_259 = F_228 ( V_87 , V_14 , V_65 ) ;
if ( ! F_229 ( V_259 ) ) {
V_29 = F_492 ( V_108 , V_259 ) ;
if ( V_29 ) {
F_493 ( V_259 ) ;
goto V_73;
}
F_494 ( V_259 ) ;
F_11 ( & V_14 -> V_52 ) ;
if ( V_14 -> V_161 ) {
V_14 -> V_161 = 0 ;
V_14 -> V_259 = NULL ;
F_13 ( & V_14 -> V_52 ) ;
F_241 ( V_259 ) ;
} else {
F_13 ( & V_14 -> V_52 ) ;
}
F_493 ( V_259 ) ;
}
V_21 . V_22 = V_608 ;
V_21 . V_33 = V_14 -> V_21 . V_22 ;
V_21 . type = 0 ;
V_29 = F_37 ( V_108 , V_87 , & V_21 , V_65 , - 1 , 1 ) ;
if ( V_29 < 0 )
goto V_73;
if ( V_29 > 0 )
F_44 ( V_65 ) ;
if ( V_29 == 0 ) {
V_29 = F_116 ( V_108 , V_87 , V_65 ) ;
if ( V_29 )
goto V_73;
F_44 ( V_65 ) ;
}
F_11 ( & V_35 -> V_37 -> V_18 ) ;
F_177 ( & V_14 -> V_20 ,
& V_35 -> V_37 -> V_19 ) ;
if ( V_35 -> V_37 -> V_26 == V_14 -> V_21 . V_22 )
V_35 -> V_37 -> V_26 = ( T_2 ) - 1 ;
F_13 ( & V_35 -> V_37 -> V_18 ) ;
F_63 ( & V_14 -> V_103 -> V_295 ) ;
F_357 ( & V_14 -> V_91 ) ;
if ( F_185 ( & V_14 -> V_103 -> V_292 [ V_507 ] ) ) {
F_470 ( & V_14 -> V_103 -> V_293 [ V_507 ] ) ;
F_471 ( & V_14 -> V_103 -> V_293 [ V_507 ] ) ;
F_490 ( V_35 -> V_37 , V_14 -> V_7 ) ;
}
F_65 ( & V_14 -> V_103 -> V_295 ) ;
if ( V_14 -> V_3 == V_53 )
F_374 ( V_14 ) ;
F_468 ( V_14 ) ;
F_11 ( & V_14 -> V_103 -> V_52 ) ;
V_14 -> V_103 -> V_282 -= V_14 -> V_21 . V_33 ;
V_14 -> V_103 -> V_298 -= V_14 -> V_21 . V_33 ;
V_14 -> V_103 -> V_288 -= V_14 -> V_21 . V_33 * V_284 ;
F_13 ( & V_14 -> V_103 -> V_52 ) ;
memcpy ( & V_21 , & V_14 -> V_21 , sizeof( V_21 ) ) ;
F_73 ( V_35 -> V_37 ) ;
F_6 ( V_14 ) ;
F_6 ( V_14 ) ;
V_29 = F_37 ( V_108 , V_35 , & V_21 , V_65 , - 1 , 1 ) ;
if ( V_29 > 0 )
V_29 = - V_172 ;
if ( V_29 < 0 )
goto V_73;
V_29 = F_116 ( V_108 , V_35 , V_65 ) ;
V_73:
F_50 ( V_65 ) ;
return V_29 ;
}
int F_495 ( struct V_12 * V_37 )
{
struct V_100 * V_103 ;
struct V_609 * V_610 ;
T_2 V_611 ;
T_2 V_7 ;
int V_612 = 0 ;
int V_29 ;
V_610 = V_37 -> V_352 ;
if ( ! F_496 ( V_610 ) )
return 1 ;
V_611 = F_497 ( V_610 ) ;
if ( V_611 & V_613 )
V_612 = 1 ;
V_7 = V_281 ;
V_29 = F_246 ( V_37 , V_7 , 0 , 0 , & V_103 ) ;
if ( V_29 )
goto V_73;
if ( V_612 ) {
V_7 = V_279 | V_280 ;
V_29 = F_246 ( V_37 , V_7 , 0 , 0 , & V_103 ) ;
} else {
V_7 = V_279 ;
V_29 = F_246 ( V_37 , V_7 , 0 , 0 , & V_103 ) ;
if ( V_29 )
goto V_73;
V_7 = V_280 ;
V_29 = F_246 ( V_37 , V_7 , 0 , 0 , & V_103 ) ;
}
V_73:
return V_29 ;
}
int F_498 ( struct V_34 * V_35 , T_2 V_32 , T_2 V_31 )
{
return F_359 ( V_35 , V_32 , V_31 ) ;
}
int F_499 ( struct V_34 * V_35 , T_2 V_27 ,
T_2 V_36 , T_2 * V_184 )
{
return F_142 ( V_35 , V_27 , V_36 , V_184 ) ;
}
int F_500 ( struct V_34 * V_35 , struct V_614 * V_615 )
{
struct V_12 * V_37 = V_35 -> V_37 ;
struct V_1 * V_2 = NULL ;
T_2 V_616 ;
T_2 V_32 ;
T_2 V_31 ;
T_2 V_617 = 0 ;
T_2 V_282 = F_275 ( V_37 -> V_352 ) ;
int V_29 = 0 ;
if ( V_615 -> V_49 == V_282 )
V_2 = F_67 ( V_37 , V_615 -> V_32 ) ;
else
V_2 = F_68 ( V_37 , V_615 -> V_32 ) ;
while ( V_2 ) {
if ( V_2 -> V_21 . V_22 >= ( V_615 -> V_32 + V_615 -> V_49 ) ) {
F_6 ( V_2 ) ;
break;
}
V_32 = F_381 ( V_615 -> V_32 , V_2 -> V_21 . V_22 ) ;
V_31 = F_293 ( V_615 -> V_32 + V_615 -> V_49 ,
V_2 -> V_21 . V_22 + V_2 -> V_21 . V_33 ) ;
if ( V_31 - V_32 >= V_615 -> V_618 ) {
if ( ! F_1 ( V_2 ) ) {
V_29 = F_51 ( V_2 , 0 ) ;
if ( V_29 ) {
F_6 ( V_2 ) ;
break;
}
V_29 = F_374 ( V_2 ) ;
if ( V_29 ) {
F_6 ( V_2 ) ;
break;
}
}
V_29 = F_501 ( V_2 ,
& V_616 ,
V_32 ,
V_31 ,
V_615 -> V_618 ) ;
V_617 += V_616 ;
if ( V_29 ) {
F_6 ( V_2 ) ;
break;
}
}
V_2 = F_226 ( V_37 -> V_87 , V_2 ) ;
}
V_615 -> V_49 = V_617 ;
return V_29 ;
}
void F_502 ( struct V_34 * V_35 )
{
F_503 ( & V_35 -> V_619 -> V_620 ) ;
F_2 () ;
if ( F_504 ( & V_35 -> V_619 -> V_89 ) )
F_49 ( & V_35 -> V_619 -> V_89 ) ;
}
int F_505 ( struct V_34 * V_35 )
{
if ( F_301 ( F_196 ( & V_35 -> V_621 ) ) )
return 0 ;
F_506 ( & V_35 -> V_619 -> V_620 ) ;
F_2 () ;
if ( F_301 ( F_196 ( & V_35 -> V_621 ) ) ) {
F_502 ( V_35 ) ;
return 0 ;
}
return 1 ;
}
