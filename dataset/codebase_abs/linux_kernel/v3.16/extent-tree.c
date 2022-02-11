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
int V_157 , int * V_158 )
{
struct V_68 V_21 ;
struct V_148 * V_159 = NULL ;
struct V_156 * V_160 = NULL ;
struct V_66 * V_67 ;
T_3 V_117 = 0 ;
int V_29 = 0 ;
V_67 = V_65 -> V_83 [ 0 ] ;
F_40 ( V_67 , & V_21 , V_65 -> V_84 [ 0 ] ) ;
if ( V_21 . type == V_153 ) {
V_159 = F_78 ( V_67 , V_65 -> V_84 [ 0 ] ,
struct V_148 ) ;
V_117 = F_113 ( V_67 , V_159 ) ;
} else if ( V_21 . type == V_152 ) {
V_160 = F_78 ( V_67 , V_65 -> V_84 [ 0 ] ,
struct V_156 ) ;
V_117 = F_108 ( V_67 , V_160 ) ;
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
* V_158 = 1 ;
} else {
if ( V_21 . type == V_153 )
F_112 ( V_67 , V_159 , V_117 ) ;
else if ( V_21 . type == V_152 )
F_107 ( V_67 , V_160 , V_117 ) ;
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
struct V_161 * V_162 )
{
struct V_68 V_21 ;
struct V_66 * V_67 ;
struct V_148 * V_159 ;
struct V_156 * V_160 ;
T_3 V_117 = 0 ;
V_67 = V_65 -> V_83 [ 0 ] ;
F_40 ( V_67 , & V_21 , V_65 -> V_84 [ 0 ] ) ;
if ( V_162 ) {
if ( F_119 ( V_67 , V_162 ) ==
V_153 ) {
V_159 = (struct V_148 * ) ( & V_162 -> V_33 ) ;
V_117 = F_113 ( V_67 , V_159 ) ;
} else {
V_160 = (struct V_156 * ) ( V_162 + 1 ) ;
V_117 = F_108 ( V_67 , V_160 ) ;
}
} else if ( V_21 . type == V_153 ) {
V_159 = F_78 ( V_67 , V_65 -> V_84 [ 0 ] ,
struct V_148 ) ;
V_117 = F_113 ( V_67 , V_159 ) ;
} else if ( V_21 . type == V_152 ) {
V_160 = F_78 ( V_67 , V_65 -> V_84 [ 0 ] ,
struct V_156 ) ;
V_117 = F_108 ( V_67 , V_160 ) ;
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
V_21 . type = V_163 ;
V_21 . V_33 = V_17 ;
} else {
V_21 . type = V_164 ;
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
V_21 . type = V_163 ;
V_21 . V_33 = V_17 ;
} else {
V_21 . type = V_164 ;
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
type = V_163 ;
else
type = V_164 ;
} else {
if ( V_17 > 0 )
type = V_152 ;
else
type = V_153 ;
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
F_123 ( V_65 -> V_83 [ V_165 ] , V_21 ,
V_65 -> V_84 [ V_165 ] + 1 ) ;
return 0 ;
}
return 1 ;
}
static T_5
int F_124 ( struct V_107 * V_108 ,
struct V_34 * V_35 ,
struct V_64 * V_65 ,
struct V_161 * * V_167 ,
T_2 V_27 , T_2 V_36 ,
T_2 V_17 , T_2 V_144 ,
T_2 V_131 , T_2 V_33 , int V_168 )
{
struct V_68 V_21 ;
struct V_66 * V_67 ;
struct V_114 * V_115 ;
struct V_161 * V_162 ;
T_2 V_7 ;
T_2 V_116 ;
unsigned long V_169 ;
unsigned long V_31 ;
int V_132 ;
int type ;
int V_170 ;
int V_29 ;
int V_82 = 0 ;
bool V_171 = F_76 ( V_35 -> V_37 ,
V_119 ) ;
V_21 . V_22 = V_27 ;
V_21 . type = V_77 ;
V_21 . V_33 = V_36 ;
V_170 = F_122 ( V_17 , V_131 ) ;
if ( V_168 ) {
V_132 = F_125 ( V_170 ) ;
V_65 -> V_172 = 1 ;
} else
V_132 = - 1 ;
if ( V_171 && V_131 < V_141 ) {
V_21 . type = V_86 ;
V_21 . V_33 = V_131 ;
}
V_78:
V_29 = F_37 ( V_108 , V_35 , & V_21 , V_65 , V_132 , 1 ) ;
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
V_21 . V_22 = V_27 ;
V_21 . type = V_77 ;
V_21 . V_33 = V_36 ;
F_44 ( V_65 ) ;
goto V_78;
}
}
if ( V_29 && ! V_168 ) {
V_82 = - V_151 ;
goto V_73;
} else if ( F_8 ( V_29 ) ) {
V_82 = - V_173 ;
goto V_73;
}
V_67 = V_65 -> V_83 [ 0 ] ;
V_116 = F_77 ( V_67 , V_65 -> V_84 [ 0 ] ) ;
#ifdef F_81
if ( V_116 < sizeof( * V_115 ) ) {
if ( ! V_168 ) {
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
V_169 = ( unsigned long ) ( V_115 + 1 ) ;
V_31 = ( unsigned long ) V_115 + V_116 ;
if ( V_7 & V_142 && ! V_171 ) {
V_169 += sizeof( struct V_136 ) ;
F_30 ( V_169 > V_31 ) ;
}
V_82 = - V_151 ;
while ( 1 ) {
if ( V_169 >= V_31 ) {
F_8 ( V_169 > V_31 ) ;
break;
}
V_162 = (struct V_161 * ) V_169 ;
type = F_119 ( V_67 , V_162 ) ;
if ( V_170 < type )
break;
if ( V_170 > type ) {
V_169 += F_125 ( type ) ;
continue;
}
if ( type == V_153 ) {
struct V_148 * V_174 ;
V_174 = (struct V_148 * ) ( & V_162 -> V_33 ) ;
if ( F_103 ( V_67 , V_174 , V_144 ,
V_131 , V_33 ) ) {
V_82 = 0 ;
break;
}
if ( F_99 ( V_67 , V_174 ) <
F_96 ( V_144 , V_131 , V_33 ) )
break;
} else {
T_2 V_175 ;
V_175 = F_126 ( V_67 , V_162 ) ;
if ( V_17 > 0 ) {
if ( V_17 == V_175 ) {
V_82 = 0 ;
break;
}
if ( V_175 < V_17 )
break;
} else {
if ( V_144 == V_175 ) {
V_82 = 0 ;
break;
}
if ( V_175 < V_144 )
break;
}
}
V_169 += F_125 ( type ) ;
}
if ( V_82 == - V_151 && V_168 ) {
if ( V_116 + V_132 >=
F_127 ( V_35 ) ) {
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
F_128 ( V_65 , 1 ) ;
}
return V_82 ;
}
static T_5
void F_129 ( struct V_34 * V_35 ,
struct V_64 * V_65 ,
struct V_161 * V_162 ,
T_2 V_17 , T_2 V_144 ,
T_2 V_131 , T_2 V_33 , int V_155 ,
struct V_178 * V_127 )
{
struct V_66 * V_67 ;
struct V_114 * V_115 ;
unsigned long V_169 ;
unsigned long V_31 ;
unsigned long V_179 ;
T_2 V_110 ;
int V_57 ;
int type ;
V_67 = V_65 -> V_83 [ 0 ] ;
V_115 = F_78 ( V_67 , V_65 -> V_84 [ 0 ] , struct V_114 ) ;
V_179 = ( unsigned long ) V_162 - ( unsigned long ) V_115 ;
type = F_122 ( V_17 , V_131 ) ;
V_57 = F_125 ( type ) ;
F_89 ( V_35 , V_65 , V_57 ) ;
V_115 = F_78 ( V_67 , V_65 -> V_84 [ 0 ] , struct V_114 ) ;
V_110 = F_79 ( V_67 , V_115 ) ;
V_110 += V_155 ;
F_90 ( V_67 , V_115 , V_110 ) ;
if ( V_127 )
F_130 ( V_127 , V_67 , V_115 ) ;
V_169 = ( unsigned long ) V_115 + V_179 ;
V_31 = ( unsigned long ) V_115 + F_77 ( V_67 , V_65 -> V_84 [ 0 ] ) ;
if ( V_169 < V_31 - V_57 )
F_131 ( V_67 , V_169 + V_57 , V_169 ,
V_31 - V_57 - V_169 ) ;
V_162 = (struct V_161 * ) V_169 ;
F_132 ( V_67 , V_162 , type ) ;
if ( type == V_153 ) {
struct V_148 * V_174 ;
V_174 = (struct V_148 * ) ( & V_162 -> V_33 ) ;
F_109 ( V_67 , V_174 , V_144 ) ;
F_110 ( V_67 , V_174 , V_131 ) ;
F_111 ( V_67 , V_174 , V_33 ) ;
F_112 ( V_67 , V_174 , V_155 ) ;
} else if ( type == V_152 ) {
struct V_156 * V_180 ;
V_180 = (struct V_156 * ) ( V_162 + 1 ) ;
F_107 ( V_67 , V_180 , V_155 ) ;
F_133 ( V_67 , V_162 , V_17 ) ;
} else if ( type == V_163 ) {
F_133 ( V_67 , V_162 , V_17 ) ;
} else {
F_133 ( V_67 , V_162 , V_144 ) ;
}
F_95 ( V_67 ) ;
}
static int F_134 ( struct V_107 * V_108 ,
struct V_34 * V_35 ,
struct V_64 * V_65 ,
struct V_161 * * V_167 ,
T_2 V_27 , T_2 V_36 , T_2 V_17 ,
T_2 V_144 , T_2 V_131 , T_2 V_33 )
{
int V_29 ;
V_29 = F_124 ( V_108 , V_35 , V_65 , V_167 ,
V_27 , V_36 , V_17 ,
V_144 , V_131 , V_33 , 0 ) ;
if ( V_29 != - V_151 )
return V_29 ;
F_44 ( V_65 ) ;
* V_167 = NULL ;
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
struct V_161 * V_162 ,
int V_181 ,
struct V_178 * V_127 ,
int * V_158 )
{
struct V_66 * V_67 ;
struct V_114 * V_115 ;
struct V_148 * V_174 = NULL ;
struct V_156 * V_180 = NULL ;
unsigned long V_169 ;
unsigned long V_31 ;
T_3 V_116 ;
int V_57 ;
int type ;
T_2 V_110 ;
V_67 = V_65 -> V_83 [ 0 ] ;
V_115 = F_78 ( V_67 , V_65 -> V_84 [ 0 ] , struct V_114 ) ;
V_110 = F_79 ( V_67 , V_115 ) ;
F_8 ( V_181 < 0 && V_110 + V_181 <= 0 ) ;
V_110 += V_181 ;
F_90 ( V_67 , V_115 , V_110 ) ;
if ( V_127 )
F_130 ( V_127 , V_67 , V_115 ) ;
type = F_119 ( V_67 , V_162 ) ;
if ( type == V_153 ) {
V_174 = (struct V_148 * ) ( & V_162 -> V_33 ) ;
V_110 = F_113 ( V_67 , V_174 ) ;
} else if ( type == V_152 ) {
V_180 = (struct V_156 * ) ( V_162 + 1 ) ;
V_110 = F_108 ( V_67 , V_180 ) ;
} else {
V_110 = 1 ;
F_30 ( V_181 != - 1 ) ;
}
F_30 ( V_181 < 0 && V_110 < - V_181 ) ;
V_110 += V_181 ;
if ( V_110 > 0 ) {
if ( type == V_153 )
F_112 ( V_67 , V_174 , V_110 ) ;
else
F_107 ( V_67 , V_180 , V_110 ) ;
} else {
* V_158 = 1 ;
V_57 = F_125 ( type ) ;
V_116 = F_77 ( V_67 , V_65 -> V_84 [ 0 ] ) ;
V_169 = ( unsigned long ) V_162 ;
V_31 = ( unsigned long ) V_115 + V_116 ;
if ( V_169 + V_57 < V_31 )
F_131 ( V_67 , V_169 , V_169 + V_57 ,
V_31 - V_169 - V_57 ) ;
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
struct V_178 * V_127 )
{
struct V_161 * V_162 ;
int V_29 ;
V_29 = F_124 ( V_108 , V_35 , V_65 , & V_162 ,
V_27 , V_36 , V_17 ,
V_144 , V_131 , V_33 , 1 ) ;
if ( V_29 == 0 ) {
F_30 ( V_131 < V_141 ) ;
F_135 ( V_35 , V_65 , V_162 ,
V_155 , V_127 , NULL ) ;
} else if ( V_29 == - V_151 ) {
F_129 ( V_35 , V_65 , V_162 , V_17 ,
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
struct V_161 * V_162 ,
int V_157 , int V_182 , int * V_158 )
{
int V_29 = 0 ;
F_30 ( ! V_182 && V_157 != 1 ) ;
if ( V_162 ) {
F_135 ( V_35 , V_65 , V_162 ,
- V_157 , NULL , V_158 ) ;
} else if ( V_182 ) {
V_29 = F_114 ( V_108 , V_35 , V_65 , V_157 ,
V_158 ) ;
} else {
* V_158 = 1 ;
V_29 = F_116 ( V_108 , V_35 , V_65 ) ;
}
return V_29 ;
}
static int F_140 ( struct V_183 * V_184 ,
T_2 V_32 , T_2 V_49 )
{
return F_141 ( V_184 , V_32 >> 9 , V_49 >> 9 , V_40 , 0 ) ;
}
static int F_142 ( struct V_34 * V_35 , T_2 V_27 ,
T_2 V_36 , T_2 * V_185 )
{
int V_29 ;
T_2 V_186 = 0 ;
struct V_187 * V_188 = NULL ;
V_29 = F_143 ( V_35 -> V_37 , V_189 ,
V_27 , & V_36 , & V_188 , 0 ) ;
if ( ! V_29 ) {
struct V_190 * V_191 = V_188 -> V_192 ;
int V_43 ;
for ( V_43 = 0 ; V_43 < V_188 -> V_193 ; V_43 ++ , V_191 ++ ) {
if ( ! V_191 -> V_194 -> V_195 )
continue;
V_29 = F_140 ( V_191 -> V_194 -> V_184 ,
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
int F_144 ( struct V_107 * V_108 ,
struct V_34 * V_35 ,
T_2 V_27 , T_2 V_36 , T_2 V_17 ,
T_2 V_144 , T_2 V_131 , T_2 V_33 ,
int V_199 )
{
int V_29 ;
struct V_12 * V_37 = V_35 -> V_37 ;
F_30 ( V_131 < V_141 &&
V_144 == V_200 ) ;
if ( V_131 < V_141 ) {
V_29 = F_145 ( V_37 , V_108 , V_27 ,
V_36 ,
V_17 , V_144 , ( int ) V_131 ,
V_201 , NULL , V_199 ) ;
} else {
V_29 = F_146 ( V_37 , V_108 , V_27 ,
V_36 ,
V_17 , V_144 , V_131 , V_33 ,
V_201 , NULL , V_199 ) ;
}
return V_29 ;
}
static int F_147 ( struct V_107 * V_108 ,
struct V_34 * V_35 ,
T_2 V_27 , T_2 V_36 ,
T_2 V_17 , T_2 V_144 ,
T_2 V_131 , T_2 V_33 , int V_155 ,
int V_199 ,
struct V_178 * V_127 )
{
struct V_12 * V_37 = V_35 -> V_37 ;
struct V_64 * V_65 ;
struct V_66 * V_67 ;
struct V_114 * V_133 ;
struct V_68 V_21 ;
T_2 V_110 ;
int V_29 ;
enum V_202 type = V_203 ;
V_65 = F_33 () ;
if ( ! V_65 )
return - V_72 ;
if ( ! F_148 ( V_144 ) || ! V_35 -> V_37 -> V_204 )
V_199 = 1 ;
V_65 -> V_76 = 1 ;
V_65 -> V_205 = 1 ;
V_29 = F_137 ( V_108 , V_37 -> V_63 , V_65 ,
V_27 , V_36 , V_17 ,
V_144 , V_131 , V_33 ,
V_155 , V_127 ) ;
if ( ( V_29 < 0 && V_29 != - V_176 ) || ( ! V_29 && V_199 ) )
goto V_73;
if ( ! V_29 && ! V_199 ) {
ASSERT ( V_35 -> V_37 -> V_204 ) ;
V_67 = V_65 -> V_83 [ 0 ] ;
F_40 ( V_67 , & V_21 , V_65 -> V_84 [ 0 ] ) ;
V_133 = F_78 ( V_67 , V_65 -> V_84 [ 0 ] ,
struct V_114 ) ;
if ( F_79 ( V_67 , V_133 ) > ( T_2 ) V_155 )
type = V_206 ;
F_44 ( V_65 ) ;
V_29 = F_149 ( V_108 , V_37 , V_144 ,
V_27 , V_36 , type , 0 ) ;
goto V_73;
}
V_67 = V_65 -> V_83 [ 0 ] ;
F_40 ( V_67 , & V_21 , V_65 -> V_84 [ 0 ] ) ;
V_133 = F_78 ( V_67 , V_65 -> V_84 [ 0 ] , struct V_114 ) ;
V_110 = F_79 ( V_67 , V_133 ) ;
if ( V_110 )
type = V_206 ;
F_90 ( V_67 , V_133 , V_110 + V_155 ) ;
if ( V_127 )
F_130 ( V_127 , V_67 , V_133 ) ;
F_95 ( V_67 ) ;
F_44 ( V_65 ) ;
if ( ! V_199 ) {
V_29 = F_149 ( V_108 , V_37 , V_144 ,
V_27 , V_36 , type , 0 ) ;
if ( V_29 )
goto V_73;
}
V_65 -> V_76 = 1 ;
V_65 -> V_205 = 1 ;
V_29 = F_138 ( V_108 , V_35 -> V_37 -> V_63 ,
V_65 , V_27 , V_17 , V_144 ,
V_131 , V_33 , V_155 ) ;
if ( V_29 )
F_150 ( V_108 , V_35 , V_29 ) ;
V_73:
F_50 ( V_65 ) ;
return V_29 ;
}
static int F_151 ( struct V_107 * V_108 ,
struct V_34 * V_35 ,
struct V_207 * V_126 ,
struct V_178 * V_127 ,
int V_208 )
{
int V_29 = 0 ;
struct V_209 * V_149 ;
struct V_68 V_210 ;
T_2 V_17 = 0 ;
T_2 V_211 = 0 ;
T_2 V_7 = 0 ;
V_210 . V_22 = V_126 -> V_27 ;
V_210 . V_33 = V_126 -> V_36 ;
V_210 . type = V_77 ;
V_149 = F_152 ( V_126 ) ;
F_153 ( V_126 , V_149 , V_126 -> V_212 ) ;
if ( V_126 -> type == V_152 )
V_17 = V_149 -> V_17 ;
V_211 = V_149 -> V_35 ;
if ( V_126 -> V_212 == V_201 && V_208 ) {
if ( V_127 )
V_7 |= V_127 -> V_129 ;
V_29 = F_154 ( V_108 , V_35 ,
V_17 , V_211 , V_7 ,
V_149 -> V_22 , V_149 -> V_33 ,
& V_210 , V_126 -> V_130 ) ;
} else if ( V_126 -> V_212 == V_201 ) {
V_29 = F_147 ( V_108 , V_35 , V_126 -> V_27 ,
V_126 -> V_36 , V_17 ,
V_211 , V_149 -> V_22 ,
V_149 -> V_33 , V_126 -> V_130 ,
V_126 -> V_199 , V_127 ) ;
} else if ( V_126 -> V_212 == V_213 ) {
V_29 = F_155 ( V_108 , V_35 , V_126 -> V_27 ,
V_126 -> V_36 , V_17 ,
V_211 , V_149 -> V_22 ,
V_149 -> V_33 , V_126 -> V_130 ,
V_127 , V_126 -> V_199 ) ;
} else {
F_83 () ;
}
return V_29 ;
}
static void F_130 ( struct V_178 * V_127 ,
struct V_66 * V_67 ,
struct V_114 * V_115 )
{
T_2 V_7 = F_80 ( V_67 , V_115 ) ;
if ( V_127 -> V_128 ) {
V_7 |= V_127 -> V_129 ;
F_92 ( V_67 , V_115 , V_7 ) ;
}
if ( V_127 -> V_214 ) {
struct V_136 * V_137 ;
F_30 ( ! ( V_7 & V_142 ) ) ;
V_137 = (struct V_136 * ) ( V_115 + 1 ) ;
F_156 ( V_67 , V_137 , & V_127 -> V_21 ) ;
}
}
static int F_157 ( struct V_107 * V_108 ,
struct V_34 * V_35 ,
struct V_207 * V_126 ,
struct V_178 * V_127 )
{
struct V_68 V_21 ;
struct V_64 * V_65 ;
struct V_114 * V_115 ;
struct V_66 * V_67 ;
T_3 V_116 ;
int V_29 ;
int V_82 = 0 ;
int V_109 = ! V_127 -> V_182 ;
if ( V_108 -> V_215 )
return 0 ;
if ( V_109 && ! F_76 ( V_35 -> V_37 , V_119 ) )
V_109 = 0 ;
V_65 = F_33 () ;
if ( ! V_65 )
return - V_72 ;
V_21 . V_22 = V_126 -> V_27 ;
if ( V_109 ) {
V_21 . type = V_86 ;
V_21 . V_33 = V_127 -> V_165 ;
} else {
V_21 . type = V_77 ;
V_21 . V_33 = V_126 -> V_36 ;
}
V_78:
V_65 -> V_76 = 1 ;
V_65 -> V_205 = 1 ;
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
V_82 = - V_173 ;
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
static int F_158 ( struct V_107 * V_108 ,
struct V_34 * V_35 ,
struct V_207 * V_126 ,
struct V_178 * V_127 ,
int V_208 )
{
int V_29 = 0 ;
struct V_216 * V_149 ;
struct V_68 V_210 ;
T_2 V_17 = 0 ;
T_2 V_211 = 0 ;
bool V_171 = F_76 ( V_35 -> V_37 ,
V_119 ) ;
V_149 = F_159 ( V_126 ) ;
F_160 ( V_126 , V_149 , V_126 -> V_212 ) ;
if ( V_126 -> type == V_163 )
V_17 = V_149 -> V_17 ;
V_211 = V_149 -> V_35 ;
V_210 . V_22 = V_126 -> V_27 ;
if ( V_171 ) {
V_210 . V_33 = V_149 -> V_165 ;
V_210 . type = V_86 ;
} else {
V_210 . V_33 = V_126 -> V_36 ;
V_210 . type = V_77 ;
}
F_30 ( V_126 -> V_130 != 1 ) ;
if ( V_126 -> V_212 == V_201 && V_208 ) {
F_30 ( ! V_127 || ! V_127 -> V_128 ) ;
V_29 = F_161 ( V_108 , V_35 ,
V_17 , V_211 ,
V_127 -> V_129 ,
& V_127 -> V_21 ,
V_149 -> V_165 , & V_210 ,
V_126 -> V_199 ) ;
} else if ( V_126 -> V_212 == V_201 ) {
V_29 = F_147 ( V_108 , V_35 , V_126 -> V_27 ,
V_126 -> V_36 , V_17 , V_211 ,
V_149 -> V_165 , 0 , 1 , V_126 -> V_199 ,
V_127 ) ;
} else if ( V_126 -> V_212 == V_213 ) {
V_29 = F_155 ( V_108 , V_35 , V_126 -> V_27 ,
V_126 -> V_36 , V_17 , V_211 ,
V_149 -> V_165 , 0 , 1 , V_127 ,
V_126 -> V_199 ) ;
} else {
F_83 () ;
}
return V_29 ;
}
static int F_162 ( struct V_107 * V_108 ,
struct V_34 * V_35 ,
struct V_207 * V_126 ,
struct V_178 * V_127 ,
int V_208 )
{
int V_29 = 0 ;
if ( V_108 -> V_215 ) {
if ( V_208 )
F_163 ( V_35 , V_126 -> V_27 ,
V_126 -> V_36 , 1 ) ;
return 0 ;
}
if ( F_164 ( V_126 ) ) {
struct V_111 * V_102 ;
F_30 ( V_127 ) ;
V_102 = F_165 ( V_126 ) ;
F_166 ( V_126 , V_102 , V_126 -> V_212 ) ;
if ( V_208 ) {
F_163 ( V_35 , V_126 -> V_27 ,
V_126 -> V_36 , 1 ) ;
if ( V_102 -> V_182 ) {
V_29 = F_167 ( V_108 , V_35 ,
V_126 -> V_27 ,
V_126 -> V_36 ) ;
}
}
return V_29 ;
}
if ( V_126 -> type == V_164 ||
V_126 -> type == V_163 )
V_29 = F_158 ( V_108 , V_35 , V_126 , V_127 ,
V_208 ) ;
else if ( V_126 -> type == V_153 ||
V_126 -> type == V_152 )
V_29 = F_151 ( V_108 , V_35 , V_126 , V_127 ,
V_208 ) ;
else
F_83 () ;
return V_29 ;
}
T_1 int F_168 ( struct V_107 * V_108 ,
struct V_34 * V_35 ,
unsigned long V_44 )
{
struct V_112 * V_113 ;
struct V_207 * V_149 ;
struct V_111 * V_217 = NULL ;
struct V_178 * V_127 ;
struct V_12 * V_37 = V_35 -> V_37 ;
T_6 V_32 = F_169 () ;
int V_29 ;
unsigned long V_8 = 0 ;
unsigned long V_218 = 0 ;
int V_219 = 0 ;
V_113 = & V_108 -> V_125 -> V_113 ;
while ( 1 ) {
if ( ! V_217 ) {
if ( V_8 >= V_44 )
break;
F_11 ( & V_113 -> V_52 ) ;
V_217 = F_170 ( V_108 ) ;
if ( ! V_217 ) {
F_13 ( & V_113 -> V_52 ) ;
break;
}
V_29 = F_171 ( V_108 , V_217 ) ;
F_13 ( & V_113 -> V_52 ) ;
if ( V_29 == - V_176 ) {
V_217 = NULL ;
V_8 ++ ;
continue;
}
}
F_11 ( & V_217 -> V_52 ) ;
F_172 ( V_108 , V_37 , V_113 ,
V_217 ) ;
V_149 = F_173 ( V_217 ) ;
if ( V_149 && V_149 -> V_220 &&
F_174 ( V_37 , V_113 , V_149 -> V_220 ) ) {
F_13 ( & V_217 -> V_52 ) ;
F_175 ( V_217 ) ;
F_11 ( & V_113 -> V_52 ) ;
V_217 -> V_221 = 0 ;
V_113 -> V_222 ++ ;
F_13 ( & V_113 -> V_52 ) ;
V_217 = NULL ;
F_47 () ;
V_8 ++ ;
continue;
}
V_219 = V_217 -> V_219 ;
V_217 -> V_219 = 0 ;
V_127 = V_217 -> V_127 ;
V_217 -> V_127 = NULL ;
if ( ! V_149 ) {
V_149 = & V_217 -> V_126 ;
if ( V_127 && V_219 ) {
F_176 ( V_127 ) ;
V_127 = NULL ;
}
if ( V_127 ) {
F_13 ( & V_217 -> V_52 ) ;
V_29 = F_157 ( V_108 , V_35 ,
V_149 , V_127 ) ;
F_176 ( V_127 ) ;
if ( V_29 ) {
if ( V_219 )
V_217 -> V_219 = 1 ;
V_217 -> V_221 = 0 ;
F_177 ( V_37 , L_1 , V_29 ) ;
F_175 ( V_217 ) ;
return V_29 ;
}
continue;
}
F_13 ( & V_217 -> V_52 ) ;
F_11 ( & V_113 -> V_52 ) ;
F_11 ( & V_217 -> V_52 ) ;
if ( F_178 ( & V_217 -> V_211 ) ||
V_217 -> V_127 ) {
F_13 ( & V_217 -> V_52 ) ;
F_13 ( & V_113 -> V_52 ) ;
continue;
}
V_149 -> V_223 = 0 ;
V_113 -> V_224 -- ;
F_179 ( & V_217 -> V_225 ,
& V_113 -> V_226 ) ;
F_13 ( & V_113 -> V_52 ) ;
} else {
V_218 ++ ;
V_149 -> V_223 = 0 ;
F_179 ( & V_149 -> V_15 , & V_217 -> V_211 ) ;
}
F_180 ( & V_113 -> V_227 ) ;
if ( ! F_164 ( V_149 ) ) {
switch ( V_149 -> V_212 ) {
case V_201 :
case V_228 :
V_217 -> V_126 . V_130 -= V_149 -> V_130 ;
break;
case V_213 :
V_217 -> V_126 . V_130 += V_149 -> V_130 ;
break;
default:
F_8 ( 1 ) ;
}
}
F_13 ( & V_217 -> V_52 ) ;
V_29 = F_162 ( V_108 , V_35 , V_149 , V_127 ,
V_219 ) ;
F_176 ( V_127 ) ;
if ( V_29 ) {
V_217 -> V_221 = 0 ;
F_175 ( V_217 ) ;
F_86 ( V_149 ) ;
F_177 ( V_37 , L_2 , V_29 ) ;
return V_29 ;
}
if ( F_164 ( V_149 ) ) {
F_175 ( V_217 ) ;
V_217 = NULL ;
}
F_86 ( V_149 ) ;
V_8 ++ ;
F_47 () ;
}
if ( V_218 > 0 ) {
T_2 V_229 = F_181 ( F_182 ( F_169 () , V_32 ) ) ;
T_2 V_230 ;
F_11 ( & V_113 -> V_52 ) ;
V_230 = V_37 -> V_231 * 3 + V_229 ;
V_230 = F_183 ( V_230 , 4 ) ;
V_37 -> V_231 = V_230 ;
F_13 ( & V_113 -> V_52 ) ;
}
return 0 ;
}
static T_2 F_184 ( struct V_232 * V_35 )
{
struct V_15 * V_30 = V_35 -> V_15 ;
struct V_207 * V_233 ;
int V_234 = 1 ;
T_2 V_235 ;
T_2 V_236 = 0 , V_70 = 0 ;
V_30 = F_178 ( V_35 ) ;
if ( V_30 ) {
V_233 = F_12 ( V_30 , struct V_207 , V_15 ) ;
V_236 = V_233 -> V_27 ;
}
V_30 = F_185 ( V_35 ) ;
if ( V_30 ) {
V_233 = F_12 ( V_30 , struct V_207 , V_15 ) ;
V_70 = V_233 -> V_27 ;
}
V_30 = V_35 -> V_15 ;
while ( V_30 ) {
V_233 = F_12 ( V_30 , struct V_207 , V_15 ) ;
F_8 ( ! V_233 -> V_223 ) ;
V_235 = V_233 -> V_27 ;
if ( V_234 )
V_30 = V_30 -> V_23 ;
else
V_30 = V_30 -> V_24 ;
V_234 = 1 - V_234 ;
}
return V_235 ;
}
static inline T_2 F_186 ( struct V_34 * V_35 , T_2 V_237 )
{
T_2 V_36 ;
V_36 = V_237 * ( sizeof( struct V_114 ) +
sizeof( struct V_161 ) ) ;
if ( ! F_76 ( V_35 -> V_37 , V_119 ) )
V_36 += V_237 * sizeof( struct V_136 ) ;
return F_183 ( V_36 , F_187 ( V_35 ) ) ;
}
int F_188 ( struct V_107 * V_108 ,
struct V_34 * V_35 )
{
struct V_238 * V_239 ;
T_2 V_224 = V_108 -> V_125 -> V_113 . V_222 ;
T_2 V_36 ;
int V_29 = 0 ;
V_36 = F_189 ( V_35 , 1 ) ;
V_224 = F_186 ( V_35 , V_224 ) ;
if ( V_224 > 1 )
V_36 += ( V_224 - 1 ) * V_35 -> V_88 ;
V_36 <<= 1 ;
V_239 = & V_35 -> V_37 -> V_240 ;
if ( V_239 -> V_103 -> V_106 )
V_36 <<= 1 ;
F_11 ( & V_239 -> V_52 ) ;
if ( V_239 -> V_10 <= V_36 )
V_29 = 1 ;
F_13 ( & V_239 -> V_52 ) ;
return V_29 ;
}
int F_190 ( struct V_107 * V_108 ,
struct V_34 * V_35 )
{
struct V_12 * V_37 = V_35 -> V_37 ;
T_2 V_227 =
F_191 ( & V_108 -> V_125 -> V_113 . V_227 ) ;
T_2 V_241 ;
T_2 V_242 ;
F_2 () ;
V_241 = V_37 -> V_231 ;
V_242 = V_227 * V_241 ;
if ( V_227 * V_241 >= V_243 )
return 1 ;
if ( V_242 >= V_243 / 2 )
return 2 ;
return F_188 ( V_108 , V_35 ) ;
}
static void F_192 ( struct V_61 * V_62 )
{
struct V_244 * V_245 ;
struct V_107 * V_108 ;
int V_29 ;
V_245 = F_32 ( V_62 , struct V_244 , V_62 ) ;
V_108 = F_193 ( V_245 -> V_35 ) ;
if ( F_194 ( V_108 ) ) {
V_245 -> error = F_195 ( V_108 ) ;
goto V_246;
}
V_108 -> V_247 = true ;
V_29 = F_196 ( V_108 , V_245 -> V_35 , V_245 -> V_8 ) ;
if ( V_29 )
V_245 -> error = V_29 ;
V_29 = F_197 ( V_108 , V_245 -> V_35 ) ;
if ( V_29 && ! V_245 -> error )
V_245 -> error = V_29 ;
V_246:
if ( V_245 -> V_247 )
F_198 ( & V_245 -> V_89 ) ;
else
F_9 ( V_245 ) ;
}
int F_199 ( struct V_34 * V_35 ,
unsigned long V_8 , int V_89 )
{
struct V_244 * V_245 ;
int V_29 ;
V_245 = F_200 ( sizeof( * V_245 ) , V_40 ) ;
if ( ! V_245 )
return - V_72 ;
V_245 -> V_35 = V_35 -> V_37 -> V_87 ;
V_245 -> V_8 = V_8 ;
V_245 -> error = 0 ;
if ( V_89 )
V_245 -> V_247 = 1 ;
else
V_245 -> V_247 = 0 ;
F_201 ( & V_245 -> V_89 ) ;
F_58 ( & V_245 -> V_62 , F_192 ,
NULL , NULL ) ;
F_66 ( V_35 -> V_37 -> V_248 , & V_245 -> V_62 ) ;
if ( V_89 ) {
F_202 ( & V_245 -> V_89 ) ;
V_29 = V_245 -> error ;
F_9 ( V_245 ) ;
return V_29 ;
}
return 0 ;
}
int F_196 ( struct V_107 * V_108 ,
struct V_34 * V_35 , unsigned long V_8 )
{
struct V_15 * V_126 ;
struct V_112 * V_113 ;
struct V_111 * V_102 ;
int V_29 ;
int V_249 = V_8 == ( unsigned long ) - 1 ;
int V_250 = 0 ;
if ( V_108 -> V_215 )
return 0 ;
if ( V_35 == V_35 -> V_37 -> V_63 )
V_35 = V_35 -> V_37 -> V_87 ;
V_113 = & V_108 -> V_125 -> V_113 ;
if ( V_8 == 0 ) {
V_8 = F_191 ( & V_113 -> V_227 ) * 2 ;
V_250 = 1 ;
}
V_78:
#ifdef F_203
V_113 -> V_251 = F_184 ( & V_113 -> V_35 ) ;
#endif
V_29 = F_168 ( V_108 , V_35 , V_8 ) ;
if ( V_29 < 0 ) {
F_150 ( V_108 , V_35 , V_29 ) ;
return V_29 ;
}
if ( V_249 ) {
if ( ! F_204 ( & V_108 -> V_252 ) )
F_205 ( V_108 , V_35 ) ;
F_11 ( & V_113 -> V_52 ) ;
V_126 = F_178 ( & V_113 -> V_226 ) ;
if ( ! V_126 ) {
F_13 ( & V_113 -> V_52 ) ;
goto V_73;
}
V_8 = ( unsigned long ) - 1 ;
while ( V_126 ) {
V_102 = F_12 ( V_126 , struct V_111 ,
V_225 ) ;
if ( F_164 ( & V_102 -> V_126 ) ) {
struct V_207 * V_149 ;
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
V_126 = F_206 ( V_126 ) ;
}
F_13 ( & V_113 -> V_52 ) ;
F_47 () ;
goto V_78;
}
V_73:
V_29 = F_207 ( V_108 , V_35 -> V_37 ) ;
if ( V_29 )
return V_29 ;
F_208 ( V_108 ) ;
return 0 ;
}
int F_209 ( struct V_107 * V_108 ,
struct V_34 * V_35 ,
T_2 V_27 , T_2 V_36 , T_2 V_7 ,
int V_165 , int V_182 )
{
struct V_178 * V_127 ;
int V_29 ;
V_127 = F_210 () ;
if ( ! V_127 )
return - V_72 ;
V_127 -> V_129 = V_7 ;
V_127 -> V_128 = 1 ;
V_127 -> V_214 = 0 ;
V_127 -> V_182 = V_182 ? 1 : 0 ;
V_127 -> V_165 = V_165 ;
V_29 = F_211 ( V_35 -> V_37 , V_108 , V_27 ,
V_36 , V_127 ) ;
if ( V_29 )
F_176 ( V_127 ) ;
return V_29 ;
}
static T_1 int F_212 ( struct V_107 * V_108 ,
struct V_34 * V_35 ,
struct V_64 * V_65 ,
T_2 V_22 , T_2 V_33 , T_2 V_27 )
{
struct V_111 * V_102 ;
struct V_207 * V_149 ;
struct V_209 * V_253 ;
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
return - V_176 ;
}
F_13 ( & V_113 -> V_52 ) ;
F_11 ( & V_102 -> V_52 ) ;
V_126 = F_178 ( & V_102 -> V_211 ) ;
while ( V_126 ) {
V_149 = F_12 ( V_126 , struct V_207 , V_15 ) ;
V_126 = F_206 ( V_126 ) ;
if ( V_149 -> type != V_153 ) {
V_29 = 1 ;
break;
}
V_253 = F_152 ( V_149 ) ;
if ( V_253 -> V_35 != V_35 -> V_254 . V_22 ||
V_253 -> V_22 != V_22 ||
V_253 -> V_33 != V_33 ) {
V_29 = 1 ;
break;
}
}
F_13 ( & V_102 -> V_52 ) ;
F_46 ( & V_102 -> V_79 ) ;
return V_29 ;
}
static T_1 int F_213 ( struct V_107 * V_108 ,
struct V_34 * V_35 ,
struct V_64 * V_65 ,
T_2 V_22 , T_2 V_33 , T_2 V_27 )
{
struct V_34 * V_63 = V_35 -> V_37 -> V_63 ;
struct V_66 * V_67 ;
struct V_148 * V_149 ;
struct V_161 * V_162 ;
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
if ( F_214 ( V_67 , V_115 ) <=
F_215 ( & V_35 -> V_255 ) )
goto V_73;
V_162 = (struct V_161 * ) ( V_115 + 1 ) ;
if ( F_119 ( V_67 , V_162 ) !=
V_153 )
goto V_73;
V_149 = (struct V_148 * ) ( & V_162 -> V_33 ) ;
if ( F_79 ( V_67 , V_115 ) !=
F_113 ( V_67 , V_149 ) ||
F_100 ( V_67 , V_149 ) !=
V_35 -> V_254 . V_22 ||
F_101 ( V_67 , V_149 ) != V_22 ||
F_102 ( V_67 , V_149 ) != V_33 )
goto V_73;
V_29 = 0 ;
V_73:
return V_29 ;
}
int F_216 ( struct V_107 * V_108 ,
struct V_34 * V_35 ,
T_2 V_22 , T_2 V_33 , T_2 V_27 )
{
struct V_64 * V_65 ;
int V_29 ;
int V_256 ;
V_65 = F_33 () ;
if ( ! V_65 )
return - V_151 ;
do {
V_29 = F_213 ( V_108 , V_35 , V_65 , V_22 ,
V_33 , V_27 ) ;
if ( V_29 && V_29 != - V_151 )
goto V_73;
V_256 = F_212 ( V_108 , V_35 , V_65 , V_22 ,
V_33 , V_27 ) ;
} while ( V_256 == - V_176 );
if ( V_256 && V_256 != - V_151 ) {
V_29 = V_256 ;
goto V_73;
}
if ( V_29 != - V_151 || V_256 != - V_151 )
V_29 = 0 ;
V_73:
F_50 ( V_65 ) ;
if ( V_35 -> V_254 . V_22 == V_257 )
F_8 ( V_29 > 0 ) ;
return V_29 ;
}
static int F_217 ( struct V_107 * V_108 ,
struct V_34 * V_35 ,
struct V_66 * V_258 ,
int V_259 , int V_260 , int V_199 )
{
T_2 V_27 ;
T_2 V_36 ;
T_2 V_17 ;
T_2 V_211 ;
T_3 V_71 ;
struct V_68 V_21 ;
struct V_261 * V_262 ;
int V_43 ;
int V_165 ;
int V_29 = 0 ;
int (* F_218)( struct V_107 * , struct V_34 * ,
T_2 , T_2 , T_2 , T_2 , T_2 , T_2 , int );
#ifdef F_219
if ( F_220 ( F_221 ( V_263 , & V_35 -> V_264 ) ) )
return 0 ;
#endif
V_211 = F_222 ( V_258 ) ;
V_71 = F_38 ( V_258 ) ;
V_165 = F_223 ( V_258 ) ;
if ( ! F_221 ( V_265 , & V_35 -> V_264 ) && V_165 == 0 )
return 0 ;
if ( V_260 )
F_218 = F_144 ;
else
F_218 = V_266 ;
if ( V_259 )
V_17 = V_258 -> V_32 ;
else
V_17 = 0 ;
for ( V_43 = 0 ; V_43 < V_71 ; V_43 ++ ) {
if ( V_165 == 0 ) {
F_40 ( V_258 , & V_21 , V_43 ) ;
if ( F_224 ( & V_21 ) != V_267 )
continue;
V_262 = F_78 ( V_258 , V_43 ,
struct V_261 ) ;
if ( F_225 ( V_258 , V_262 ) ==
V_268 )
continue;
V_27 = F_226 ( V_258 , V_262 ) ;
if ( V_27 == 0 )
continue;
V_36 = F_227 ( V_258 , V_262 ) ;
V_21 . V_33 -= F_228 ( V_258 , V_262 ) ;
V_29 = F_218 ( V_108 , V_35 , V_27 , V_36 ,
V_17 , V_211 , V_21 . V_22 ,
V_21 . V_33 , V_199 ) ;
if ( V_29 )
goto V_154;
} else {
V_27 = F_229 ( V_258 , V_43 ) ;
V_36 = F_230 ( V_35 , V_165 - 1 ) ;
V_29 = F_218 ( V_108 , V_35 , V_27 , V_36 ,
V_17 , V_211 , V_165 - 1 , 0 ,
V_199 ) ;
if ( V_29 )
goto V_154;
}
}
return 0 ;
V_154:
return V_29 ;
}
int F_231 ( struct V_107 * V_108 , struct V_34 * V_35 ,
struct V_66 * V_258 , int V_259 , int V_199 )
{
return F_217 ( V_108 , V_35 , V_258 , V_259 , 1 , V_199 ) ;
}
int F_232 ( struct V_107 * V_108 , struct V_34 * V_35 ,
struct V_66 * V_258 , int V_259 , int V_199 )
{
return F_217 ( V_108 , V_35 , V_258 , V_259 , 0 , V_199 ) ;
}
static int F_233 ( struct V_107 * V_108 ,
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
V_137 = F_234 ( V_67 , V_65 -> V_84 [ 0 ] ) ;
F_235 ( V_67 , & V_2 -> V_133 , V_137 , sizeof( V_2 -> V_133 ) ) ;
F_95 ( V_67 ) ;
F_44 ( V_65 ) ;
V_154:
if ( V_29 ) {
F_150 ( V_108 , V_35 , V_29 ) ;
return V_29 ;
}
return 0 ;
}
static struct V_1 *
F_236 ( struct V_34 * V_35 ,
struct V_1 * V_2 )
{
struct V_15 * V_126 ;
F_11 ( & V_35 -> V_37 -> V_18 ) ;
V_126 = F_206 ( & V_2 -> V_20 ) ;
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
static int F_237 ( struct V_1 * V_14 ,
struct V_107 * V_108 ,
struct V_64 * V_65 )
{
struct V_34 * V_35 = V_14 -> V_37 -> V_87 ;
struct V_269 * V_269 = NULL ;
T_2 V_270 = 0 ;
int V_271 = V_272 ;
int V_273 = 0 ;
int V_274 = 0 ;
int V_29 = 0 ;
if ( V_14 -> V_21 . V_33 < ( 100 * 1024 * 1024 ) ) {
F_11 ( & V_14 -> V_52 ) ;
V_14 -> V_275 = V_276 ;
F_13 ( & V_14 -> V_52 ) ;
return 0 ;
}
V_78:
V_269 = F_238 ( V_35 , V_14 , V_65 ) ;
if ( F_194 ( V_269 ) && F_195 ( V_269 ) != - V_151 ) {
V_29 = F_195 ( V_269 ) ;
F_44 ( V_65 ) ;
goto V_73;
}
if ( F_194 ( V_269 ) ) {
F_30 ( V_274 ) ;
V_274 ++ ;
if ( V_14 -> V_277 )
goto V_121;
V_29 = F_239 ( V_35 , V_108 , V_14 , V_65 ) ;
if ( V_29 )
goto V_121;
goto V_78;
}
if ( V_14 -> V_278 == V_108 -> V_279 &&
F_240 ( V_269 ) ) {
V_271 = V_280 ;
goto V_281;
}
F_241 ( V_269 ) -> V_282 = 0 ;
V_29 = F_242 ( V_108 , V_35 , V_269 ) ;
F_8 ( V_29 ) ;
if ( F_240 ( V_269 ) > 0 ) {
V_29 = F_243 ( V_35 ,
& V_35 -> V_37 -> V_240 ) ;
if ( V_29 )
goto V_281;
V_29 = F_244 ( V_35 , V_108 , V_269 ) ;
if ( V_29 )
goto V_281;
}
F_11 ( & V_14 -> V_52 ) ;
if ( V_14 -> V_3 != V_4 ||
! F_245 ( V_35 , V_283 ) ||
V_14 -> V_284 ) {
V_271 = V_276 ;
F_13 ( & V_14 -> V_52 ) ;
goto V_281;
}
F_13 ( & V_14 -> V_52 ) ;
V_273 = ( int ) F_183 ( V_14 -> V_21 . V_33 , 256 * 1024 * 1024 ) ;
if ( ! V_273 )
V_273 = 1 ;
V_273 *= 16 ;
V_273 *= V_285 ;
V_29 = F_246 ( V_269 , V_273 ) ;
if ( V_29 )
goto V_281;
V_29 = F_247 ( V_269 , V_108 , 0 , 0 , V_273 ,
V_273 , V_273 ,
& V_270 ) ;
if ( ! V_29 )
V_271 = V_280 ;
F_248 ( V_269 , V_273 ) ;
V_281:
F_249 ( V_269 ) ;
V_121:
F_44 ( V_65 ) ;
V_73:
F_11 ( & V_14 -> V_52 ) ;
if ( ! V_29 && V_271 == V_280 )
V_14 -> V_278 = V_108 -> V_279 ;
V_14 -> V_275 = V_271 ;
F_13 ( & V_14 -> V_52 ) ;
return V_29 ;
}
int F_250 ( struct V_107 * V_108 ,
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
if ( V_2 -> V_275 == V_286 )
break;
V_2 = F_236 ( V_35 , V_2 ) ;
}
if ( ! V_2 ) {
if ( V_70 == 0 )
break;
V_70 = 0 ;
continue;
}
V_82 = F_237 ( V_2 , V_108 , V_65 ) ;
V_70 = V_2 -> V_21 . V_22 + V_2 -> V_21 . V_33 ;
F_6 ( V_2 ) ;
}
while ( 1 ) {
if ( V_70 == 0 ) {
V_82 = F_196 ( V_108 , V_35 ,
( unsigned long ) - 1 ) ;
if ( V_82 )
goto V_73;
}
V_2 = F_67 ( V_35 -> V_37 , V_70 ) ;
while ( V_2 ) {
if ( V_2 -> V_275 == V_286 ) {
F_6 ( V_2 ) ;
goto V_78;
}
if ( V_2 -> V_287 )
break;
V_2 = F_236 ( V_35 , V_2 ) ;
}
if ( ! V_2 ) {
if ( V_70 == 0 )
break;
V_70 = 0 ;
continue;
}
if ( V_2 -> V_275 == V_280 )
V_2 -> V_275 = V_288 ;
V_2 -> V_287 = 0 ;
V_70 = V_2 -> V_21 . V_22 + V_2 -> V_21 . V_33 ;
V_82 = F_233 ( V_108 , V_35 , V_65 , V_2 ) ;
F_6 ( V_2 ) ;
if ( V_82 )
goto V_73;
}
while ( 1 ) {
if ( V_70 == 0 ) {
V_82 = F_196 ( V_108 , V_35 ,
( unsigned long ) - 1 ) ;
if ( V_82 )
goto V_73;
}
V_2 = F_67 ( V_35 -> V_37 , V_70 ) ;
while ( V_2 ) {
if ( V_2 -> V_287 ) {
F_6 ( V_2 ) ;
goto V_78;
}
if ( V_2 -> V_275 == V_288 )
break;
V_2 = F_236 ( V_35 , V_2 ) ;
}
if ( ! V_2 ) {
if ( V_70 == 0 )
break;
V_70 = 0 ;
continue;
}
V_82 = F_251 ( V_35 , V_108 , V_2 , V_65 ) ;
if ( ! V_82 && V_2 -> V_275 == V_288 )
V_2 -> V_275 = V_276 ;
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
int V_289 = 0 ;
V_14 = F_68 ( V_35 -> V_37 , V_27 ) ;
if ( ! V_14 || V_14 -> V_277 )
V_289 = 1 ;
if ( V_14 )
F_6 ( V_14 ) ;
return V_289 ;
}
static const char * F_253 ( T_2 V_7 )
{
switch ( V_7 ) {
case V_290 | V_291 :
return L_3 ;
case V_290 :
return L_4 ;
case V_291 :
return L_5 ;
case V_292 :
return L_6 ;
default:
F_8 ( 1 ) ;
return L_7 ;
} ;
}
static int F_254 ( struct V_12 * V_13 , T_2 V_7 ,
T_2 V_293 , T_2 V_294 ,
struct V_100 * * V_103 )
{
struct V_100 * V_104 ;
int V_43 ;
int V_295 ;
int V_29 ;
if ( V_7 & ( V_296 | V_297 |
V_298 ) )
V_295 = 2 ;
else
V_295 = 1 ;
V_104 = F_69 ( V_13 , V_7 ) ;
if ( V_104 ) {
F_11 ( & V_104 -> V_52 ) ;
V_104 -> V_293 += V_293 ;
V_104 -> V_299 += V_293 * V_295 ;
V_104 -> V_294 += V_294 ;
V_104 -> V_300 += V_294 * V_295 ;
V_104 -> V_106 = 0 ;
F_13 ( & V_104 -> V_52 ) ;
* V_103 = V_104 ;
return 0 ;
}
V_104 = F_53 ( sizeof( * V_104 ) , V_40 ) ;
if ( ! V_104 )
return - V_72 ;
V_29 = F_255 ( & V_104 -> V_301 , 0 ) ;
if ( V_29 ) {
F_9 ( V_104 ) ;
return V_29 ;
}
for ( V_43 = 0 ; V_43 < V_302 ; V_43 ++ )
F_54 ( & V_104 -> V_303 [ V_43 ] ) ;
F_256 ( & V_104 -> V_304 ) ;
F_257 ( & V_104 -> V_52 ) ;
V_104 -> V_7 = V_7 & V_105 ;
V_104 -> V_293 = V_293 ;
V_104 -> V_299 = V_293 * V_295 ;
V_104 -> V_294 = V_294 ;
V_104 -> V_300 = V_294 * V_295 ;
V_104 -> V_305 = 0 ;
V_104 -> V_306 = 0 ;
V_104 -> V_307 = 0 ;
V_104 -> V_308 = 0 ;
V_104 -> V_106 = 0 ;
V_104 -> V_309 = V_310 ;
V_104 -> V_311 = 0 ;
V_104 -> V_312 = 0 ;
F_56 ( & V_104 -> V_89 ) ;
V_29 = F_258 ( & V_104 -> V_313 , & V_314 ,
V_13 -> V_315 , L_8 ,
F_253 ( V_104 -> V_7 ) ) ;
if ( V_29 ) {
F_9 ( V_104 ) ;
return V_29 ;
}
* V_103 = V_104 ;
F_259 ( & V_104 -> V_91 , & V_13 -> V_103 ) ;
if ( V_7 & V_291 )
V_13 -> V_316 = V_104 ;
return V_29 ;
}
static void F_260 ( struct V_12 * V_37 , T_2 V_7 )
{
T_2 V_317 = F_261 ( V_7 ) &
V_318 ;
F_262 ( & V_37 -> V_319 ) ;
if ( V_7 & V_291 )
V_37 -> V_320 |= V_317 ;
if ( V_7 & V_290 )
V_37 -> V_321 |= V_317 ;
if ( V_7 & V_292 )
V_37 -> V_322 |= V_317 ;
F_263 ( & V_37 -> V_319 ) ;
}
static T_2 F_264 ( struct V_12 * V_37 , T_2 V_7 )
{
struct V_323 * V_324 = V_37 -> V_325 ;
T_2 V_326 = 0 ;
if ( ! V_324 )
return 0 ;
if ( V_7 & V_291 &&
V_324 -> V_327 . V_7 & V_328 ) {
V_326 = V_291 | V_324 -> V_327 . V_326 ;
} else if ( V_7 & V_292 &&
V_324 -> V_329 . V_7 & V_328 ) {
V_326 = V_292 | V_324 -> V_329 . V_326 ;
} else if ( V_7 & V_290 &&
V_324 -> V_330 . V_7 & V_328 ) {
V_326 = V_290 | V_324 -> V_330 . V_326 ;
}
return V_326 ;
}
static T_2 F_265 ( struct V_34 * V_35 , T_2 V_7 )
{
T_2 V_331 = V_35 -> V_37 -> V_332 -> V_333 +
V_35 -> V_37 -> V_332 -> V_334 ;
T_2 V_326 ;
T_2 V_335 ;
F_11 ( & V_35 -> V_37 -> V_336 ) ;
V_326 = F_264 ( V_35 -> V_37 , V_7 ) ;
if ( V_326 ) {
if ( ( V_7 & V_326 ) & V_318 ) {
F_13 ( & V_35 -> V_37 -> V_336 ) ;
return F_266 ( V_326 ) ;
}
}
F_13 ( & V_35 -> V_37 -> V_336 ) ;
if ( V_331 == 1 )
V_7 &= ~ ( V_297 | V_337 |
V_338 ) ;
if ( V_331 < 3 )
V_7 &= ~ V_339 ;
if ( V_331 < 4 )
V_7 &= ~ V_298 ;
V_335 = V_7 & ( V_296 | V_337 |
V_297 | V_338 |
V_339 | V_298 ) ;
V_7 &= ~ V_335 ;
if ( V_335 & V_339 )
V_335 = V_339 ;
else if ( V_335 & V_338 )
V_335 = V_338 ;
else if ( V_335 & V_298 )
V_335 = V_298 ;
else if ( V_335 & V_297 )
V_335 = V_297 ;
else if ( V_335 & V_337 )
V_335 = V_337 ;
return F_266 ( V_7 | V_335 ) ;
}
static T_2 F_267 ( struct V_34 * V_35 , T_2 V_340 )
{
unsigned V_220 ;
T_2 V_7 ;
do {
V_7 = V_340 ;
V_220 = F_268 ( & V_35 -> V_37 -> V_319 ) ;
if ( V_7 & V_291 )
V_7 |= V_35 -> V_37 -> V_320 ;
else if ( V_7 & V_292 )
V_7 |= V_35 -> V_37 -> V_322 ;
else if ( V_7 & V_290 )
V_7 |= V_35 -> V_37 -> V_321 ;
} while ( F_269 ( & V_35 -> V_37 -> V_319 , V_220 ) );
return F_265 ( V_35 , V_7 ) ;
}
T_2 F_270 ( struct V_34 * V_35 , int V_327 )
{
T_2 V_7 ;
T_2 V_29 ;
if ( V_327 )
V_7 = V_291 ;
else if ( V_35 == V_35 -> V_37 -> V_341 )
V_7 = V_292 ;
else
V_7 = V_290 ;
V_29 = F_267 ( V_35 , V_7 ) ;
return V_29 ;
}
int F_246 ( struct V_269 * V_269 , T_2 V_342 )
{
struct V_100 * V_316 ;
struct V_34 * V_35 = F_241 ( V_269 ) -> V_35 ;
struct V_12 * V_37 = V_35 -> V_37 ;
T_2 V_343 ;
int V_29 = 0 , V_344 = 0 , V_345 = 1 ;
V_342 = F_271 ( V_342 , V_35 -> V_346 ) ;
if ( F_272 ( V_269 ) ) {
V_344 = 1 ;
ASSERT ( V_347 -> V_348 ) ;
}
V_316 = V_37 -> V_316 ;
if ( ! V_316 )
goto V_349;
V_78:
F_11 ( & V_316 -> V_52 ) ;
V_343 = V_316 -> V_294 + V_316 -> V_306 +
V_316 -> V_305 + V_316 -> V_307 +
V_316 -> V_308 ;
if ( V_343 + V_342 > V_316 -> V_293 ) {
struct V_107 * V_108 ;
if ( ! V_316 -> V_106 && V_345 ) {
T_2 V_350 ;
V_316 -> V_309 = V_351 ;
F_13 ( & V_316 -> V_52 ) ;
V_349:
V_350 = F_270 ( V_35 , 1 ) ;
V_108 = F_193 ( V_35 ) ;
if ( F_194 ( V_108 ) )
return F_195 ( V_108 ) ;
V_29 = F_273 ( V_108 , V_35 -> V_37 -> V_63 ,
V_350 ,
V_310 ) ;
F_197 ( V_108 , V_35 ) ;
if ( V_29 < 0 ) {
if ( V_29 != - V_352 )
return V_29 ;
else
goto V_353;
}
if ( ! V_316 )
V_316 = V_37 -> V_316 ;
goto V_78;
}
if ( F_274 ( & V_316 -> V_301 ,
V_342 ) < 0 )
V_344 = 1 ;
F_13 ( & V_316 -> V_52 ) ;
V_353:
if ( ! V_344 &&
! F_191 ( & V_35 -> V_37 -> V_354 ) ) {
V_344 = 1 ;
V_108 = F_193 ( V_35 ) ;
if ( F_194 ( V_108 ) )
return F_195 ( V_108 ) ;
V_29 = F_275 ( V_108 , V_35 ) ;
if ( V_29 )
return V_29 ;
goto V_78;
}
F_276 ( V_35 -> V_37 ,
L_9 ,
V_316 -> V_7 , V_342 , 1 ) ;
return - V_352 ;
}
V_316 -> V_308 += V_342 ;
F_276 ( V_35 -> V_37 , L_10 ,
V_316 -> V_7 , V_342 , 1 ) ;
F_13 ( & V_316 -> V_52 ) ;
return 0 ;
}
void F_248 ( struct V_269 * V_269 , T_2 V_342 )
{
struct V_34 * V_35 = F_241 ( V_269 ) -> V_35 ;
struct V_100 * V_316 ;
V_342 = F_271 ( V_342 , V_35 -> V_346 ) ;
V_316 = V_35 -> V_37 -> V_316 ;
F_11 ( & V_316 -> V_52 ) ;
F_8 ( V_316 -> V_308 < V_342 ) ;
V_316 -> V_308 -= V_342 ;
F_276 ( V_35 -> V_37 , L_10 ,
V_316 -> V_7 , V_342 , 0 ) ;
F_13 ( & V_316 -> V_52 ) ;
}
static void F_277 ( struct V_12 * V_13 )
{
struct V_101 * V_102 = & V_13 -> V_103 ;
struct V_100 * V_104 ;
F_70 () ;
F_71 (found, head, list) {
if ( V_104 -> V_7 & V_290 )
V_104 -> V_309 = V_351 ;
}
F_72 () ;
}
static inline T_2 F_278 ( struct V_238 * V_355 )
{
return ( V_355 -> V_57 << 1 ) ;
}
static int F_279 ( struct V_34 * V_35 ,
struct V_100 * V_356 , int V_357 )
{
struct V_238 * V_239 = & V_35 -> V_37 -> V_240 ;
T_2 V_36 = V_356 -> V_293 - V_356 -> V_307 ;
T_2 V_358 = V_356 -> V_294 + V_356 -> V_306 ;
T_2 V_359 ;
if ( V_357 == V_351 )
return 1 ;
if ( V_356 -> V_7 & V_290 )
V_358 += F_278 ( V_239 ) ;
if ( V_357 == V_360 ) {
V_359 = F_280 ( V_35 -> V_37 -> V_361 ) ;
V_359 = F_34 ( T_2 , 64 * 1024 * 1024 ,
F_281 ( V_359 , 1 ) ) ;
if ( V_36 - V_358 < V_359 )
return 1 ;
}
if ( V_358 + 2 * 1024 * 1024 < F_282 ( V_36 , 8 ) )
return 0 ;
return 1 ;
}
static T_2 F_283 ( struct V_34 * V_35 , T_2 type )
{
T_2 V_362 ;
if ( type & ( V_298 |
V_337 |
V_338 |
V_339 ) )
V_362 = V_35 -> V_37 -> V_332 -> V_333 ;
else if ( type & V_297 )
V_362 = 2 ;
else
V_362 = 1 ;
return F_189 ( V_35 , V_362 + 1 ) ;
}
static void F_284 ( struct V_107 * V_108 ,
struct V_34 * V_35 , T_2 type )
{
struct V_100 * V_13 ;
T_2 V_363 ;
T_2 V_359 ;
V_13 = F_69 ( V_35 -> V_37 , V_292 ) ;
F_11 ( & V_13 -> V_52 ) ;
V_363 = V_13 -> V_293 - V_13 -> V_294 - V_13 -> V_305 -
V_13 -> V_306 - V_13 -> V_307 ;
F_13 ( & V_13 -> V_52 ) ;
V_359 = F_283 ( V_35 , type ) ;
if ( V_363 < V_359 && F_245 ( V_35 , V_364 ) ) {
F_285 ( V_35 -> V_37 , L_11 ,
V_363 , V_359 , type ) ;
F_286 ( V_13 , 0 , 0 ) ;
}
if ( V_363 < V_359 ) {
T_2 V_7 ;
V_7 = F_270 ( V_35 -> V_37 -> V_341 , 0 ) ;
F_287 ( V_108 , V_35 , V_7 ) ;
}
}
static int F_273 ( struct V_107 * V_108 ,
struct V_34 * V_63 , T_2 V_7 , int V_357 )
{
struct V_100 * V_103 ;
struct V_12 * V_37 = V_63 -> V_37 ;
int V_365 = 0 ;
int V_29 = 0 ;
if ( V_108 -> V_366 )
return - V_352 ;
V_103 = F_69 ( V_63 -> V_37 , V_7 ) ;
if ( ! V_103 ) {
V_29 = F_254 ( V_63 -> V_37 , V_7 ,
0 , 0 , & V_103 ) ;
F_30 ( V_29 ) ;
}
F_30 ( ! V_103 ) ;
V_78:
F_11 ( & V_103 -> V_52 ) ;
if ( V_357 < V_103 -> V_309 )
V_357 = V_103 -> V_309 ;
if ( V_103 -> V_106 ) {
if ( F_279 ( V_63 , V_103 , V_357 ) )
V_29 = - V_352 ;
else
V_29 = 0 ;
F_13 ( & V_103 -> V_52 ) ;
return V_29 ;
}
if ( ! F_279 ( V_63 , V_103 , V_357 ) ) {
F_13 ( & V_103 -> V_52 ) ;
return 0 ;
} else if ( V_103 -> V_311 ) {
V_365 = 1 ;
} else {
V_103 -> V_311 = 1 ;
}
F_13 ( & V_103 -> V_52 ) ;
F_35 ( & V_37 -> V_367 ) ;
if ( V_365 ) {
F_46 ( & V_37 -> V_367 ) ;
V_365 = 0 ;
goto V_78;
}
V_108 -> V_366 = true ;
if ( F_288 ( V_103 ) )
V_7 |= ( V_291 | V_290 ) ;
if ( V_7 & V_291 && V_37 -> V_368 ) {
V_37 -> V_369 ++ ;
if ( ! ( V_37 -> V_369 %
V_37 -> V_368 ) )
F_277 ( V_37 ) ;
}
F_284 ( V_108 , V_63 , V_7 ) ;
V_29 = F_287 ( V_108 , V_63 , V_7 ) ;
V_108 -> V_366 = false ;
F_11 ( & V_103 -> V_52 ) ;
if ( V_29 < 0 && V_29 != - V_352 )
goto V_73;
if ( V_29 )
V_103 -> V_106 = 1 ;
else
V_29 = 1 ;
V_103 -> V_309 = V_310 ;
V_73:
V_103 -> V_311 = 0 ;
F_13 ( & V_103 -> V_52 ) ;
F_46 ( & V_37 -> V_367 ) ;
return V_29 ;
}
static int F_289 ( struct V_34 * V_35 ,
struct V_100 * V_103 , T_2 V_342 ,
enum V_370 V_312 )
{
struct V_238 * V_239 = & V_35 -> V_37 -> V_240 ;
T_2 V_371 = F_270 ( V_35 , 0 ) ;
T_2 V_372 ;
T_2 V_373 ;
T_2 V_343 ;
V_343 = V_103 -> V_294 + V_103 -> V_306 +
V_103 -> V_305 + V_103 -> V_307 ;
F_11 ( & V_239 -> V_52 ) ;
V_372 = F_278 ( V_239 ) ;
F_13 ( & V_239 -> V_52 ) ;
if ( V_343 + V_372 >= V_103 -> V_293 )
return 0 ;
V_343 += V_103 -> V_308 ;
F_11 ( & V_35 -> V_37 -> V_374 ) ;
V_373 = V_35 -> V_37 -> V_375 ;
F_13 ( & V_35 -> V_37 -> V_374 ) ;
if ( V_371 & ( V_296 |
V_297 |
V_298 ) )
V_373 >>= 1 ;
if ( V_312 == V_376 )
V_373 >>= 3 ;
else
V_373 >>= 1 ;
if ( V_343 + V_342 < V_103 -> V_293 + V_373 )
return 1 ;
return 0 ;
}
static void F_290 ( struct V_34 * V_35 ,
unsigned long V_377 , int V_378 )
{
struct V_379 * V_380 = V_35 -> V_37 -> V_380 ;
if ( F_291 ( & V_380 -> V_381 ) ) {
F_292 ( V_380 , V_377 , V_382 ) ;
F_45 ( & V_380 -> V_381 ) ;
} else {
F_293 ( V_35 -> V_37 , 0 , V_378 ) ;
if ( ! V_347 -> V_348 )
F_294 ( V_35 -> V_37 , V_378 ) ;
}
}
static inline int F_295 ( struct V_34 * V_35 , T_2 V_383 )
{
T_2 V_342 ;
int V_44 ;
V_342 = F_189 ( V_35 , 1 ) ;
V_44 = ( int ) F_183 ( V_383 , V_342 ) ;
if ( ! V_44 )
V_44 = 1 ;
return V_44 ;
}
static void F_296 ( struct V_34 * V_35 , T_2 V_383 , T_2 V_384 ,
bool V_385 )
{
struct V_238 * V_386 ;
struct V_100 * V_103 ;
struct V_107 * V_108 ;
T_2 V_284 ;
T_2 V_387 ;
long V_388 ;
unsigned long V_377 ;
int V_389 ;
int V_390 ;
enum V_370 V_312 ;
V_390 = F_295 ( V_35 , V_383 ) ;
V_383 = V_390 * V_391 ;
V_108 = (struct V_107 * ) V_347 -> V_348 ;
V_386 = & V_35 -> V_37 -> V_392 ;
V_103 = V_386 -> V_103 ;
V_284 = F_297 (
& V_35 -> V_37 -> V_284 ) ;
if ( V_284 == 0 ) {
if ( V_108 )
return;
if ( V_385 )
F_294 ( V_35 -> V_37 , V_390 ) ;
return;
}
V_389 = 0 ;
while ( V_284 && V_389 < 3 ) {
V_387 = F_298 ( V_284 , V_383 ) ;
V_377 = V_387 >> V_393 ;
F_290 ( V_35 , V_377 , V_390 ) ;
V_387 = F_191 ( & V_35 -> V_37 -> V_394 ) ;
if ( ! V_387 )
goto V_395;
if ( V_387 <= V_377 )
V_387 = 0 ;
else
V_387 -= V_377 ;
F_299 ( V_35 -> V_37 -> V_396 ,
F_191 ( & V_35 -> V_37 -> V_394 ) <=
( int ) V_387 ) ;
V_395:
if ( ! V_108 )
V_312 = V_376 ;
else
V_312 = V_397 ;
F_11 ( & V_103 -> V_52 ) ;
if ( F_289 ( V_35 , V_103 , V_384 , V_312 ) ) {
F_13 ( & V_103 -> V_52 ) ;
break;
}
F_13 ( & V_103 -> V_52 ) ;
V_389 ++ ;
if ( V_385 && ! V_108 ) {
F_294 ( V_35 -> V_37 , V_390 ) ;
} else {
V_388 = F_300 ( 1 ) ;
if ( V_388 )
break;
}
V_284 = F_297 (
& V_35 -> V_37 -> V_284 ) ;
}
}
static int F_301 ( struct V_34 * V_35 ,
struct V_100 * V_103 ,
T_2 V_342 , int V_357 )
{
struct V_238 * V_398 = & V_35 -> V_37 -> V_399 ;
struct V_107 * V_108 ;
V_108 = (struct V_107 * ) V_347 -> V_348 ;
if ( V_108 )
return - V_176 ;
if ( V_357 )
goto V_400;
if ( F_274 ( & V_103 -> V_301 ,
V_342 ) >= 0 )
goto V_400;
if ( V_103 != V_398 -> V_103 )
return - V_352 ;
F_11 ( & V_398 -> V_52 ) ;
if ( F_274 ( & V_103 -> V_301 ,
V_342 - V_398 -> V_57 ) >= 0 ) {
F_13 ( & V_398 -> V_52 ) ;
return - V_352 ;
}
F_13 ( & V_398 -> V_52 ) ;
V_400:
V_108 = F_193 ( V_35 ) ;
if ( F_194 ( V_108 ) )
return - V_352 ;
return F_275 ( V_108 , V_35 ) ;
}
static int F_302 ( struct V_34 * V_35 ,
struct V_100 * V_103 , T_2 V_36 ,
T_2 V_401 , int V_264 )
{
struct V_107 * V_108 ;
int V_44 ;
int V_29 = 0 ;
switch ( V_264 ) {
case V_402 :
case V_403 :
if ( V_264 == V_402 )
V_44 = F_295 ( V_35 , V_36 ) * 2 ;
else
V_44 = - 1 ;
V_108 = F_193 ( V_35 ) ;
if ( F_194 ( V_108 ) ) {
V_29 = F_195 ( V_108 ) ;
break;
}
V_29 = F_303 ( V_108 , V_35 , V_44 ) ;
F_197 ( V_108 , V_35 ) ;
break;
case V_404 :
case V_405 :
F_296 ( V_35 , V_36 * 2 , V_401 ,
V_264 == V_405 ) ;
break;
case V_406 :
V_108 = F_193 ( V_35 ) ;
if ( F_194 ( V_108 ) ) {
V_29 = F_195 ( V_108 ) ;
break;
}
V_29 = F_273 ( V_108 , V_35 -> V_37 -> V_63 ,
F_270 ( V_35 , 0 ) ,
V_310 ) ;
F_197 ( V_108 , V_35 ) ;
if ( V_29 == - V_352 )
V_29 = 0 ;
break;
case V_407 :
V_29 = F_301 ( V_35 , V_103 , V_401 , 0 ) ;
break;
default:
V_29 = - V_352 ;
break;
}
return V_29 ;
}
static inline T_2
F_304 ( struct V_34 * V_35 ,
struct V_100 * V_103 )
{
T_2 V_343 ;
T_2 V_408 ;
T_2 V_383 ;
V_383 = F_24 ( T_2 , F_305 () * 1024 * 1024 ,
16 * 1024 * 1024 ) ;
F_11 ( & V_103 -> V_52 ) ;
if ( F_289 ( V_35 , V_103 , V_383 ,
V_376 ) ) {
V_383 = 0 ;
goto V_73;
}
V_343 = V_103 -> V_294 + V_103 -> V_306 +
V_103 -> V_305 + V_103 -> V_307 +
V_103 -> V_308 ;
if ( F_289 ( V_35 , V_103 , 1024 * 1024 ,
V_376 ) )
V_408 = F_281 ( V_103 -> V_293 , 95 ) ;
else
V_408 = F_281 ( V_103 -> V_293 , 90 ) ;
if ( V_343 > V_408 )
V_383 = V_343 - V_408 ;
else
V_383 = 0 ;
V_383 = F_298 ( V_383 , V_103 -> V_308 +
V_103 -> V_306 ) ;
V_73:
F_13 ( & V_103 -> V_52 ) ;
return V_383 ;
}
static inline int F_306 ( struct V_100 * V_103 ,
struct V_12 * V_37 , T_2 V_343 )
{
return ( V_343 >= F_281 ( V_103 -> V_293 , 98 ) &&
! F_39 ( V_37 ) &&
! F_221 ( V_409 , & V_37 -> V_410 ) ) ;
}
static int F_307 ( struct V_100 * V_103 ,
struct V_12 * V_37 )
{
T_2 V_343 ;
F_11 ( & V_103 -> V_52 ) ;
V_343 = V_103 -> V_294 + V_103 -> V_306 +
V_103 -> V_305 + V_103 -> V_307 +
V_103 -> V_308 ;
if ( F_306 ( V_103 , V_37 , V_343 ) ) {
F_13 ( & V_103 -> V_52 ) ;
return 1 ;
}
F_13 ( & V_103 -> V_52 ) ;
return 0 ;
}
static void F_308 ( struct V_411 * V_62 )
{
struct V_12 * V_37 ;
struct V_100 * V_103 ;
T_2 V_383 ;
int V_412 ;
V_37 = F_32 ( V_62 , struct V_12 , V_413 ) ;
V_103 = F_69 ( V_37 , V_290 ) ;
V_383 = F_304 ( V_37 -> V_414 ,
V_103 ) ;
if ( ! V_383 )
return;
V_412 = V_402 ;
do {
F_302 ( V_37 -> V_414 , V_103 , V_383 ,
V_383 , V_412 ) ;
V_412 ++ ;
if ( ! F_307 ( V_103 , V_37 ) )
return;
} while ( V_412 <= V_407 );
if ( F_307 ( V_103 , V_37 ) )
F_309 ( V_415 , V_62 ) ;
}
void F_310 ( struct V_411 * V_62 )
{
F_311 ( V_62 , F_308 ) ;
}
static int F_312 ( struct V_34 * V_35 ,
struct V_238 * V_386 ,
T_2 V_401 ,
enum V_370 V_312 )
{
struct V_100 * V_103 = V_386 -> V_103 ;
T_2 V_343 ;
T_2 V_36 = V_401 ;
int V_412 = V_402 ;
int V_29 = 0 ;
bool V_416 = false ;
V_78:
V_29 = 0 ;
F_11 ( & V_103 -> V_52 ) ;
while ( V_312 == V_376 && ! V_416 &&
V_103 -> V_312 ) {
F_13 ( & V_103 -> V_52 ) ;
if ( V_347 -> V_348 )
return - V_176 ;
V_29 = F_313 ( V_103 -> V_89 , ! V_103 -> V_312 ) ;
if ( V_29 )
return - V_417 ;
F_11 ( & V_103 -> V_52 ) ;
}
V_29 = - V_352 ;
V_343 = V_103 -> V_294 + V_103 -> V_306 +
V_103 -> V_305 + V_103 -> V_307 +
V_103 -> V_308 ;
if ( V_343 <= V_103 -> V_293 ) {
if ( V_343 + V_401 <= V_103 -> V_293 ) {
V_103 -> V_308 += V_401 ;
F_276 ( V_35 -> V_37 ,
L_10 , V_103 -> V_7 , V_401 , 1 ) ;
V_29 = 0 ;
} else {
V_36 = V_401 ;
}
} else {
V_36 = V_343 - V_103 -> V_293 +
( V_401 * 2 ) ;
}
if ( V_29 && F_289 ( V_35 , V_103 , V_401 , V_312 ) ) {
V_103 -> V_308 += V_401 ;
F_276 ( V_35 -> V_37 , L_10 ,
V_103 -> V_7 , V_401 ,
1 ) ;
V_29 = 0 ;
}
if ( V_29 && V_312 != V_397 ) {
V_416 = true ;
V_103 -> V_312 = 1 ;
} else if ( ! V_29 && V_103 -> V_7 & V_290 ) {
V_343 += V_401 ;
if ( F_306 ( V_103 , V_35 -> V_37 , V_343 ) &&
! F_314 ( & V_35 -> V_37 -> V_413 ) )
F_309 ( V_415 ,
& V_35 -> V_37 -> V_413 ) ;
}
F_13 ( & V_103 -> V_52 ) ;
if ( ! V_29 || V_312 == V_397 )
goto V_73;
V_29 = F_302 ( V_35 , V_103 , V_36 , V_401 ,
V_412 ) ;
V_412 ++ ;
if ( V_312 == V_418 &&
( V_412 == V_404 ||
V_412 == V_405 ) )
V_412 = V_406 ;
if ( ! V_29 )
goto V_78;
else if ( V_312 == V_418 &&
V_412 < V_407 )
goto V_78;
else if ( V_312 == V_376 &&
V_412 <= V_407 )
goto V_78;
V_73:
if ( V_29 == - V_352 &&
F_220 ( V_35 -> V_419 == V_420 ) ) {
struct V_238 * V_239 =
& V_35 -> V_37 -> V_240 ;
if ( V_386 != V_239 &&
! F_315 ( V_239 , V_401 ) )
V_29 = 0 ;
}
if ( V_29 == - V_352 )
F_276 ( V_35 -> V_37 ,
L_9 ,
V_103 -> V_7 , V_401 , 1 ) ;
if ( V_416 ) {
F_11 ( & V_103 -> V_52 ) ;
V_103 -> V_312 = 0 ;
F_316 ( & V_103 -> V_89 ) ;
F_13 ( & V_103 -> V_52 ) ;
}
return V_29 ;
}
static struct V_238 * F_317 (
const struct V_107 * V_108 ,
const struct V_34 * V_35 )
{
struct V_238 * V_386 = NULL ;
if ( F_221 ( V_265 , & V_35 -> V_264 ) )
V_386 = V_108 -> V_386 ;
if ( V_35 == V_35 -> V_37 -> V_421 && V_108 -> V_422 )
V_386 = V_108 -> V_386 ;
if ( V_35 == V_35 -> V_37 -> V_423 )
V_386 = V_108 -> V_386 ;
if ( ! V_386 )
V_386 = V_35 -> V_386 ;
if ( ! V_386 )
V_386 = & V_35 -> V_37 -> V_424 ;
return V_386 ;
}
static int F_315 ( struct V_238 * V_386 ,
T_2 V_36 )
{
int V_29 = - V_352 ;
F_11 ( & V_386 -> V_52 ) ;
if ( V_386 -> V_10 >= V_36 ) {
V_386 -> V_10 -= V_36 ;
if ( V_386 -> V_10 < V_386 -> V_57 )
V_386 -> V_106 = 0 ;
V_29 = 0 ;
}
F_13 ( & V_386 -> V_52 ) ;
return V_29 ;
}
static void F_318 ( struct V_238 * V_386 ,
T_2 V_36 , int V_425 )
{
F_11 ( & V_386 -> V_52 ) ;
V_386 -> V_10 += V_36 ;
if ( V_425 )
V_386 -> V_57 += V_36 ;
else if ( V_386 -> V_10 >= V_386 -> V_57 )
V_386 -> V_106 = 1 ;
F_13 ( & V_386 -> V_52 ) ;
}
int F_319 ( struct V_12 * V_37 ,
struct V_238 * V_426 , T_2 V_36 ,
int V_427 )
{
struct V_238 * V_239 = & V_37 -> V_240 ;
T_2 V_428 ;
if ( V_239 -> V_103 != V_426 -> V_103 )
return - V_352 ;
F_11 ( & V_239 -> V_52 ) ;
V_428 = F_282 ( V_239 -> V_57 , V_427 ) ;
if ( V_239 -> V_10 < V_428 + V_36 ) {
F_13 ( & V_239 -> V_52 ) ;
return - V_352 ;
}
V_239 -> V_10 -= V_36 ;
if ( V_239 -> V_10 < V_239 -> V_57 )
V_239 -> V_106 = 0 ;
F_13 ( & V_239 -> V_52 ) ;
F_318 ( V_426 , V_36 , 1 ) ;
return 0 ;
}
static void F_320 ( struct V_12 * V_37 ,
struct V_238 * V_386 ,
struct V_238 * V_426 , T_2 V_36 )
{
struct V_100 * V_103 = V_386 -> V_103 ;
F_11 ( & V_386 -> V_52 ) ;
if ( V_36 == ( T_2 ) - 1 )
V_36 = V_386 -> V_57 ;
V_386 -> V_57 -= V_36 ;
if ( V_386 -> V_10 >= V_386 -> V_57 ) {
V_36 = V_386 -> V_10 - V_386 -> V_57 ;
V_386 -> V_10 = V_386 -> V_57 ;
V_386 -> V_106 = 1 ;
} else {
V_36 = 0 ;
}
F_13 ( & V_386 -> V_52 ) ;
if ( V_36 > 0 ) {
if ( V_426 ) {
F_11 ( & V_426 -> V_52 ) ;
if ( ! V_426 -> V_106 ) {
T_2 V_429 ;
V_429 = V_426 -> V_57 - V_426 -> V_10 ;
V_429 = F_298 ( V_36 , V_429 ) ;
V_426 -> V_10 += V_429 ;
if ( V_426 -> V_10 >= V_426 -> V_57 )
V_426 -> V_106 = 1 ;
V_36 -= V_429 ;
}
F_13 ( & V_426 -> V_52 ) ;
}
if ( V_36 ) {
F_11 ( & V_103 -> V_52 ) ;
V_103 -> V_308 -= V_36 ;
F_276 ( V_37 , L_10 ,
V_103 -> V_7 , V_36 , 0 ) ;
F_13 ( & V_103 -> V_52 ) ;
}
}
}
static int F_321 ( struct V_238 * V_430 ,
struct V_238 * V_431 , T_2 V_36 )
{
int V_29 ;
V_29 = F_315 ( V_430 , V_36 ) ;
if ( V_29 )
return V_29 ;
F_318 ( V_431 , V_36 , 1 ) ;
return 0 ;
}
void F_322 ( struct V_238 * V_432 , unsigned short type )
{
memset ( V_432 , 0 , sizeof( * V_432 ) ) ;
F_257 ( & V_432 -> V_52 ) ;
V_432 -> type = type ;
}
struct V_238 * F_323 ( struct V_34 * V_35 ,
unsigned short type )
{
struct V_238 * V_386 ;
struct V_12 * V_37 = V_35 -> V_37 ;
V_386 = F_200 ( sizeof( * V_386 ) , V_40 ) ;
if ( ! V_386 )
return NULL ;
F_322 ( V_386 , type ) ;
V_386 -> V_103 = F_69 ( V_37 ,
V_290 ) ;
return V_386 ;
}
void F_324 ( struct V_34 * V_35 ,
struct V_238 * V_432 )
{
if ( ! V_432 )
return;
F_325 ( V_35 , V_432 , ( T_2 ) - 1 ) ;
F_9 ( V_432 ) ;
}
int F_326 ( struct V_34 * V_35 ,
struct V_238 * V_386 , T_2 V_36 ,
enum V_370 V_312 )
{
int V_29 ;
if ( V_36 == 0 )
return 0 ;
V_29 = F_312 ( V_35 , V_386 , V_36 , V_312 ) ;
if ( ! V_29 ) {
F_318 ( V_386 , V_36 , 1 ) ;
return 0 ;
}
return V_29 ;
}
int F_327 ( struct V_34 * V_35 ,
struct V_238 * V_386 , int V_427 )
{
T_2 V_36 = 0 ;
int V_29 = - V_352 ;
if ( ! V_386 )
return 0 ;
F_11 ( & V_386 -> V_52 ) ;
V_36 = F_282 ( V_386 -> V_57 , V_427 ) ;
if ( V_386 -> V_10 >= V_36 )
V_29 = 0 ;
F_13 ( & V_386 -> V_52 ) ;
return V_29 ;
}
int F_328 ( struct V_34 * V_35 ,
struct V_238 * V_386 , T_2 V_433 ,
enum V_370 V_312 )
{
T_2 V_36 = 0 ;
int V_29 = - V_352 ;
if ( ! V_386 )
return 0 ;
F_11 ( & V_386 -> V_52 ) ;
V_36 = V_433 ;
if ( V_386 -> V_10 >= V_36 )
V_29 = 0 ;
else
V_36 -= V_386 -> V_10 ;
F_13 ( & V_386 -> V_52 ) ;
if ( ! V_29 )
return 0 ;
V_29 = F_312 ( V_35 , V_386 , V_36 , V_312 ) ;
if ( ! V_29 ) {
F_318 ( V_386 , V_36 , 0 ) ;
return 0 ;
}
return V_29 ;
}
int F_329 ( struct V_238 * V_434 ,
struct V_238 * V_435 ,
T_2 V_36 )
{
return F_321 ( V_434 , V_435 , V_36 ) ;
}
void F_325 ( struct V_34 * V_35 ,
struct V_238 * V_386 ,
T_2 V_36 )
{
struct V_238 * V_239 = & V_35 -> V_37 -> V_240 ;
if ( V_239 == V_386 ||
V_386 -> V_103 != V_239 -> V_103 )
V_239 = NULL ;
F_320 ( V_35 -> V_37 , V_386 , V_239 ,
V_36 ) ;
}
static T_2 F_330 ( struct V_12 * V_37 )
{
struct V_100 * V_356 ;
T_2 V_36 ;
T_2 V_436 ;
T_2 V_437 ;
int V_438 = F_331 ( V_37 -> V_361 ) ;
V_356 = F_69 ( V_37 , V_291 ) ;
F_11 ( & V_356 -> V_52 ) ;
V_437 = V_356 -> V_294 ;
F_13 ( & V_356 -> V_52 ) ;
V_356 = F_69 ( V_37 , V_290 ) ;
F_11 ( & V_356 -> V_52 ) ;
if ( V_356 -> V_7 & V_291 )
V_437 = 0 ;
V_436 = V_356 -> V_294 ;
F_13 ( & V_356 -> V_52 ) ;
V_36 = ( V_437 >> V_37 -> V_380 -> V_439 ) *
V_438 * 2 ;
V_36 += F_183 ( V_437 + V_436 , 50 ) ;
if ( V_36 * 3 > V_436 )
V_36 = F_183 ( V_436 , 3 ) ;
return F_271 ( V_36 , V_37 -> V_63 -> V_88 << 10 ) ;
}
static void F_332 ( struct V_12 * V_37 )
{
struct V_238 * V_386 = & V_37 -> V_240 ;
struct V_100 * V_356 = V_386 -> V_103 ;
T_2 V_36 ;
V_36 = F_330 ( V_37 ) ;
F_11 ( & V_356 -> V_52 ) ;
F_11 ( & V_386 -> V_52 ) ;
V_386 -> V_57 = F_24 ( T_2 , V_36 , 512 * 1024 * 1024 ) ;
V_36 = V_356 -> V_294 + V_356 -> V_305 +
V_356 -> V_306 + V_356 -> V_307 +
V_356 -> V_308 ;
if ( V_356 -> V_293 > V_36 ) {
V_36 = V_356 -> V_293 - V_36 ;
V_386 -> V_10 += V_36 ;
V_356 -> V_308 += V_36 ;
F_276 ( V_37 , L_10 ,
V_356 -> V_7 , V_36 , 1 ) ;
}
if ( V_386 -> V_10 >= V_386 -> V_57 ) {
V_36 = V_386 -> V_10 - V_386 -> V_57 ;
V_356 -> V_308 -= V_36 ;
F_276 ( V_37 , L_10 ,
V_356 -> V_7 , V_36 , 0 ) ;
V_386 -> V_10 = V_386 -> V_57 ;
V_386 -> V_106 = 1 ;
}
F_13 ( & V_386 -> V_52 ) ;
F_13 ( & V_356 -> V_52 ) ;
}
static void F_333 ( struct V_12 * V_37 )
{
struct V_100 * V_103 ;
V_103 = F_69 ( V_37 , V_292 ) ;
V_37 -> V_440 . V_103 = V_103 ;
V_103 = F_69 ( V_37 , V_290 ) ;
V_37 -> V_240 . V_103 = V_103 ;
V_37 -> V_392 . V_103 = V_103 ;
V_37 -> V_441 . V_103 = V_103 ;
V_37 -> V_424 . V_103 = V_103 ;
V_37 -> V_399 . V_103 = V_103 ;
V_37 -> V_63 -> V_386 = & V_37 -> V_240 ;
V_37 -> V_421 -> V_386 = & V_37 -> V_240 ;
V_37 -> V_442 -> V_386 = & V_37 -> V_240 ;
V_37 -> V_87 -> V_386 = & V_37 -> V_240 ;
if ( V_37 -> V_443 )
V_37 -> V_443 -> V_386 = & V_37 -> V_240 ;
V_37 -> V_341 -> V_386 = & V_37 -> V_440 ;
F_332 ( V_37 ) ;
}
static void F_334 ( struct V_12 * V_37 )
{
F_320 ( V_37 , & V_37 -> V_240 , NULL ,
( T_2 ) - 1 ) ;
F_8 ( V_37 -> V_392 . V_57 > 0 ) ;
F_8 ( V_37 -> V_392 . V_10 > 0 ) ;
F_8 ( V_37 -> V_441 . V_57 > 0 ) ;
F_8 ( V_37 -> V_441 . V_10 > 0 ) ;
F_8 ( V_37 -> V_440 . V_57 > 0 ) ;
F_8 ( V_37 -> V_440 . V_10 > 0 ) ;
F_8 ( V_37 -> V_399 . V_57 > 0 ) ;
F_8 ( V_37 -> V_399 . V_10 > 0 ) ;
}
void F_335 ( struct V_107 * V_108 ,
struct V_34 * V_35 )
{
if ( ! V_108 -> V_386 )
return;
if ( ! V_108 -> V_306 )
return;
F_276 ( V_35 -> V_37 , L_12 ,
V_108 -> V_279 , V_108 -> V_306 , 0 ) ;
F_325 ( V_35 , V_108 -> V_386 , V_108 -> V_306 ) ;
V_108 -> V_306 = 0 ;
}
int F_336 ( struct V_107 * V_108 ,
struct V_269 * V_269 )
{
struct V_34 * V_35 = F_241 ( V_269 ) -> V_35 ;
struct V_238 * V_434 = F_317 ( V_108 , V_35 ) ;
struct V_238 * V_435 = V_35 -> V_444 ;
T_2 V_36 = F_189 ( V_35 , 1 ) ;
F_276 ( V_35 -> V_37 , L_13 ,
F_337 ( V_269 ) , V_36 , 1 ) ;
return F_321 ( V_434 , V_435 , V_36 ) ;
}
void F_338 ( struct V_269 * V_269 )
{
struct V_34 * V_35 = F_241 ( V_269 ) -> V_35 ;
T_2 V_36 = F_189 ( V_35 , 1 ) ;
F_276 ( V_35 -> V_37 , L_13 ,
F_337 ( V_269 ) , V_36 , 0 ) ;
F_325 ( V_35 , V_35 -> V_444 , V_36 ) ;
}
int F_339 ( struct V_34 * V_35 ,
struct V_238 * V_432 ,
int V_390 ,
T_2 * V_445 ,
bool V_446 )
{
T_2 V_36 ;
int V_29 ;
struct V_238 * V_239 = & V_35 -> V_37 -> V_240 ;
if ( V_35 -> V_37 -> V_204 ) {
V_36 = 3 * V_35 -> V_88 ;
V_29 = F_340 ( V_35 , V_36 ) ;
if ( V_29 )
return V_29 ;
} else {
V_36 = 0 ;
}
* V_445 = V_36 ;
V_36 = F_189 ( V_35 , V_390 ) ;
V_432 -> V_103 = F_69 ( V_35 -> V_37 ,
V_290 ) ;
V_29 = F_326 ( V_35 , V_432 , V_36 ,
V_376 ) ;
if ( V_29 == - V_352 && V_446 )
V_29 = F_329 ( V_239 , V_432 , V_36 ) ;
if ( V_29 ) {
if ( * V_445 )
F_341 ( V_35 , * V_445 ) ;
}
return V_29 ;
}
void F_342 ( struct V_34 * V_35 ,
struct V_238 * V_432 ,
T_2 V_445 )
{
F_325 ( V_35 , V_432 , ( T_2 ) - 1 ) ;
if ( V_445 )
F_341 ( V_35 , V_445 ) ;
}
static unsigned F_343 ( struct V_269 * V_269 )
{
unsigned V_447 = 0 ;
unsigned V_448 = 0 ;
F_30 ( ! F_241 ( V_269 ) -> V_449 ) ;
F_241 ( V_269 ) -> V_449 -- ;
if ( F_241 ( V_269 ) -> V_449 == 0 &&
F_344 ( V_450 ,
& F_241 ( V_269 ) -> V_451 ) )
V_447 = 1 ;
if ( F_241 ( V_269 ) -> V_449 >=
F_241 ( V_269 ) -> V_452 )
return V_447 ;
V_448 = F_241 ( V_269 ) -> V_452 -
F_241 ( V_269 ) -> V_449 ;
F_241 ( V_269 ) -> V_452 -= V_448 ;
return V_448 + V_447 ;
}
static T_2 F_345 ( struct V_269 * V_269 , T_2 V_36 ,
int V_453 )
{
struct V_34 * V_35 = F_241 ( V_269 ) -> V_35 ;
T_2 V_438 ;
int V_454 ;
int V_455 ;
int V_456 ;
if ( F_241 ( V_269 ) -> V_7 & V_457 &&
F_241 ( V_269 ) -> V_458 == 0 )
return 0 ;
V_456 = ( int ) F_183 ( F_241 ( V_269 ) -> V_458 , V_35 -> V_346 ) ;
if ( V_453 )
F_241 ( V_269 ) -> V_458 += V_36 ;
else
F_241 ( V_269 ) -> V_458 -= V_36 ;
V_438 = F_187 ( V_35 ) - sizeof( struct V_459 ) ;
V_454 = ( int ) F_183 ( V_438 ,
sizeof( struct V_460 ) +
sizeof( struct V_461 ) ) ;
V_455 = ( int ) F_183 ( F_241 ( V_269 ) -> V_458 , V_35 -> V_346 ) ;
V_455 = V_455 + V_454 - 1 ;
V_455 = V_455 / V_454 ;
V_456 = V_456 + V_454 - 1 ;
V_456 = V_456 / V_454 ;
if ( V_456 == V_455 )
return 0 ;
if ( V_453 )
return F_189 ( V_35 ,
V_455 - V_456 ) ;
return F_189 ( V_35 , V_456 - V_455 ) ;
}
int F_346 ( struct V_269 * V_269 , T_2 V_36 )
{
struct V_34 * V_35 = F_241 ( V_269 ) -> V_35 ;
struct V_238 * V_386 = & V_35 -> V_37 -> V_392 ;
T_2 V_462 = 0 ;
T_2 V_458 ;
unsigned V_463 = 0 ;
int V_464 = 0 ;
enum V_370 V_312 = V_376 ;
int V_29 = 0 ;
bool V_465 = true ;
T_2 V_466 = 0 ;
unsigned V_467 ;
if ( F_272 ( V_269 ) ) {
V_312 = V_397 ;
V_465 = false ;
}
if ( V_312 != V_397 &&
F_347 ( V_35 -> V_37 ) )
F_348 ( 1 ) ;
if ( V_465 )
F_35 ( & F_241 ( V_269 ) -> V_468 ) ;
V_36 = F_271 ( V_36 , V_35 -> V_346 ) ;
F_11 ( & F_241 ( V_269 ) -> V_52 ) ;
F_241 ( V_269 ) -> V_449 ++ ;
if ( F_241 ( V_269 ) -> V_449 >
F_241 ( V_269 ) -> V_452 )
V_463 = F_241 ( V_269 ) -> V_449 -
F_241 ( V_269 ) -> V_452 ;
if ( ! F_221 ( V_450 ,
& F_241 ( V_269 ) -> V_451 ) ) {
V_463 ++ ;
V_464 = 1 ;
}
V_462 = F_189 ( V_35 , V_463 ) ;
V_462 += F_345 ( V_269 , V_36 , 1 ) ;
V_458 = F_241 ( V_269 ) -> V_458 ;
F_13 ( & F_241 ( V_269 ) -> V_52 ) ;
if ( V_35 -> V_37 -> V_204 ) {
V_29 = F_340 ( V_35 , V_36 +
V_463 * V_35 -> V_88 ) ;
if ( V_29 )
goto V_469;
}
V_29 = F_312 ( V_35 , V_386 , V_462 , V_312 ) ;
if ( F_220 ( V_29 ) ) {
if ( V_35 -> V_37 -> V_204 )
F_341 ( V_35 , V_36 +
V_463 * V_35 -> V_88 ) ;
goto V_469;
}
F_11 ( & F_241 ( V_269 ) -> V_52 ) ;
if ( V_464 ) {
F_349 ( V_450 ,
& F_241 ( V_269 ) -> V_451 ) ;
V_463 -- ;
}
F_241 ( V_269 ) -> V_452 += V_463 ;
F_13 ( & F_241 ( V_269 ) -> V_52 ) ;
if ( V_465 )
F_46 ( & F_241 ( V_269 ) -> V_468 ) ;
if ( V_462 )
F_276 ( V_35 -> V_37 , L_14 ,
F_337 ( V_269 ) , V_462 , 1 ) ;
F_318 ( V_386 , V_462 , 1 ) ;
return 0 ;
V_469:
F_11 ( & F_241 ( V_269 ) -> V_52 ) ;
V_467 = F_343 ( V_269 ) ;
if ( F_241 ( V_269 ) -> V_458 == V_458 ) {
F_345 ( V_269 , V_36 , 0 ) ;
} else {
T_2 V_470 = F_241 ( V_269 ) -> V_458 ;
T_2 V_342 ;
V_342 = V_458 - F_241 ( V_269 ) -> V_458 ;
F_241 ( V_269 ) -> V_458 = V_458 ;
V_466 = F_345 ( V_269 , V_342 , 0 ) ;
F_241 ( V_269 ) -> V_458 = V_458 - V_36 ;
V_342 = V_458 - V_470 ;
V_342 = F_345 ( V_269 , V_342 , 0 ) ;
F_241 ( V_269 ) -> V_458 = V_470 - V_36 ;
if ( V_342 > V_466 )
V_466 = V_342 - V_466 ;
else
V_466 = 0 ;
}
F_13 ( & F_241 ( V_269 ) -> V_52 ) ;
if ( V_467 )
V_466 += F_189 ( V_35 , V_467 ) ;
if ( V_466 ) {
F_325 ( V_35 , V_386 , V_466 ) ;
F_276 ( V_35 -> V_37 , L_14 ,
F_337 ( V_269 ) , V_466 , 0 ) ;
}
if ( V_465 )
F_46 ( & F_241 ( V_269 ) -> V_468 ) ;
return V_29 ;
}
void F_350 ( struct V_269 * V_269 , T_2 V_36 )
{
struct V_34 * V_35 = F_241 ( V_269 ) -> V_35 ;
T_2 V_466 = 0 ;
unsigned V_467 ;
V_36 = F_271 ( V_36 , V_35 -> V_346 ) ;
F_11 ( & F_241 ( V_269 ) -> V_52 ) ;
V_467 = F_343 ( V_269 ) ;
if ( V_36 )
V_466 = F_345 ( V_269 , V_36 , 0 ) ;
F_13 ( & F_241 ( V_269 ) -> V_52 ) ;
if ( V_467 > 0 )
V_466 += F_189 ( V_35 , V_467 ) ;
F_276 ( V_35 -> V_37 , L_14 ,
F_337 ( V_269 ) , V_466 , 0 ) ;
if ( V_35 -> V_37 -> V_204 ) {
F_341 ( V_35 , V_36 +
V_467 * V_35 -> V_88 ) ;
}
F_325 ( V_35 , & V_35 -> V_37 -> V_392 ,
V_466 ) ;
}
int F_351 ( struct V_269 * V_269 , T_2 V_36 )
{
int V_29 ;
V_29 = F_246 ( V_269 , V_36 ) ;
if ( V_29 )
return V_29 ;
V_29 = F_346 ( V_269 , V_36 ) ;
if ( V_29 ) {
F_248 ( V_269 , V_36 ) ;
return V_29 ;
}
return 0 ;
}
void F_352 ( struct V_269 * V_269 , T_2 V_36 )
{
F_350 ( V_269 , V_36 ) ;
F_248 ( V_269 , V_36 ) ;
}
static int F_353 ( struct V_34 * V_35 ,
T_2 V_27 , T_2 V_36 , int V_349 )
{
struct V_1 * V_2 = NULL ;
struct V_12 * V_13 = V_35 -> V_37 ;
T_2 V_471 = V_36 ;
T_2 V_472 ;
T_2 V_473 ;
int V_295 ;
F_11 ( & V_13 -> V_474 ) ;
V_472 = F_354 ( V_13 -> V_361 ) ;
if ( V_349 )
V_472 += V_36 ;
else
V_472 -= V_36 ;
F_355 ( V_13 -> V_361 , V_472 ) ;
F_13 ( & V_13 -> V_474 ) ;
while ( V_471 ) {
V_2 = F_68 ( V_13 , V_27 ) ;
if ( ! V_2 )
return - V_151 ;
if ( V_2 -> V_7 & ( V_296 |
V_297 |
V_298 ) )
V_295 = 2 ;
else
V_295 = 1 ;
if ( ! V_349 && V_2 -> V_3 == V_94 )
F_51 ( V_2 , 1 ) ;
V_473 = V_27 - V_2 -> V_21 . V_22 ;
F_8 ( V_473 > V_2 -> V_21 . V_33 ) ;
F_11 ( & V_2 -> V_103 -> V_52 ) ;
F_11 ( & V_2 -> V_52 ) ;
if ( F_245 ( V_35 , V_283 ) &&
V_2 -> V_275 < V_286 )
V_2 -> V_275 = V_286 ;
V_2 -> V_287 = 1 ;
V_472 = F_356 ( & V_2 -> V_133 ) ;
V_36 = F_298 ( V_471 , V_2 -> V_21 . V_33 - V_473 ) ;
if ( V_349 ) {
V_472 += V_36 ;
F_357 ( & V_2 -> V_133 , V_472 ) ;
V_2 -> V_10 -= V_36 ;
V_2 -> V_103 -> V_306 -= V_36 ;
V_2 -> V_103 -> V_294 += V_36 ;
V_2 -> V_103 -> V_300 += V_36 * V_295 ;
F_13 ( & V_2 -> V_52 ) ;
F_13 ( & V_2 -> V_103 -> V_52 ) ;
} else {
V_472 -= V_36 ;
F_357 ( & V_2 -> V_133 , V_472 ) ;
V_2 -> V_9 += V_36 ;
V_2 -> V_103 -> V_305 += V_36 ;
V_2 -> V_103 -> V_294 -= V_36 ;
V_2 -> V_103 -> V_300 -= V_36 * V_295 ;
F_13 ( & V_2 -> V_52 ) ;
F_13 ( & V_2 -> V_103 -> V_52 ) ;
F_358 ( V_13 -> V_59 ,
V_27 , V_27 + V_36 - 1 ,
V_40 | V_475 ) ;
}
F_6 ( V_2 ) ;
V_471 -= V_36 ;
V_27 += V_36 ;
}
return 0 ;
}
static T_2 V_26 ( struct V_34 * V_35 , T_2 V_476 )
{
struct V_1 * V_2 ;
T_2 V_27 ;
F_11 ( & V_35 -> V_37 -> V_18 ) ;
V_27 = V_35 -> V_37 -> V_26 ;
F_13 ( & V_35 -> V_37 -> V_18 ) ;
if ( V_27 < ( T_2 ) - 1 )
return V_27 ;
V_2 = F_67 ( V_35 -> V_37 , V_476 ) ;
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
F_11 ( & V_2 -> V_103 -> V_52 ) ;
F_11 ( & V_2 -> V_52 ) ;
V_2 -> V_9 += V_36 ;
V_2 -> V_103 -> V_305 += V_36 ;
if ( V_10 ) {
V_2 -> V_10 -= V_36 ;
V_2 -> V_103 -> V_306 -= V_36 ;
}
F_13 ( & V_2 -> V_52 ) ;
F_13 ( & V_2 -> V_103 -> V_52 ) ;
F_358 ( V_35 -> V_37 -> V_59 , V_27 ,
V_27 + V_36 - 1 , V_40 | V_475 ) ;
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
return - V_477 ;
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
return - V_477 ;
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
goto V_478;
V_36 = ( V_32 + V_36 ) -
V_54 -> V_85 ;
V_32 = V_54 -> V_85 ;
V_29 = F_17 ( V_35 , V_32 , V_36 ) ;
}
V_478:
F_46 ( & V_54 -> V_79 ) ;
F_26 ( V_54 ) ;
}
F_6 ( V_14 ) ;
return V_29 ;
}
int F_364 ( struct V_34 * log ,
struct V_66 * V_479 )
{
struct V_261 * V_133 ;
struct V_68 V_21 ;
int V_480 ;
int V_43 ;
if ( ! F_76 ( log -> V_37 , V_481 ) )
return 0 ;
for ( V_43 = 0 ; V_43 < F_38 ( V_479 ) ; V_43 ++ ) {
F_40 ( V_479 , & V_21 , V_43 ) ;
if ( V_21 . type != V_267 )
continue;
V_133 = F_78 ( V_479 , V_43 , struct V_261 ) ;
V_480 = F_225 ( V_479 , V_133 ) ;
if ( V_480 == V_268 )
continue;
if ( F_226 ( V_479 , V_133 ) == 0 )
continue;
V_21 . V_22 = F_226 ( V_479 , V_133 ) ;
V_21 . V_33 = F_227 ( V_479 , V_133 ) ;
F_363 ( log , V_21 . V_22 , V_21 . V_33 ) ;
}
return 0 ;
}
static int F_365 ( struct V_1 * V_2 ,
T_2 V_36 , int V_453 , int V_482 )
{
struct V_100 * V_103 = V_2 -> V_103 ;
int V_29 = 0 ;
F_11 ( & V_103 -> V_52 ) ;
F_11 ( & V_2 -> V_52 ) ;
if ( V_453 != V_483 ) {
if ( V_2 -> V_277 ) {
V_29 = - V_176 ;
} else {
V_2 -> V_10 += V_36 ;
V_103 -> V_306 += V_36 ;
if ( V_453 == V_484 ) {
F_276 ( V_2 -> V_37 ,
L_10 , V_103 -> V_7 ,
V_36 , 0 ) ;
V_103 -> V_308 -= V_36 ;
}
if ( V_482 )
V_2 -> V_284 += V_36 ;
}
} else {
if ( V_2 -> V_277 )
V_103 -> V_307 += V_36 ;
V_2 -> V_10 -= V_36 ;
V_103 -> V_306 -= V_36 ;
if ( V_482 )
V_2 -> V_284 -= V_36 ;
}
F_13 ( & V_2 -> V_52 ) ;
F_13 ( & V_103 -> V_52 ) ;
return V_29 ;
}
void F_366 ( struct V_107 * V_108 ,
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
V_2 -> V_97 = ( T_2 ) - 1 ;
F_368 ( & V_54 -> V_91 ) ;
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
F_332 ( V_37 ) ;
}
static int F_369 ( struct V_34 * V_35 , T_2 V_32 , T_2 V_31 )
{
struct V_12 * V_37 = V_35 -> V_37 ;
struct V_1 * V_2 = NULL ;
struct V_100 * V_103 ;
struct V_238 * V_239 = & V_37 -> V_240 ;
T_2 V_49 ;
bool V_289 ;
while ( V_32 <= V_31 ) {
V_289 = false ;
if ( ! V_2 ||
V_32 >= V_2 -> V_21 . V_22 + V_2 -> V_21 . V_33 ) {
if ( V_2 )
F_6 ( V_2 ) ;
V_2 = F_68 ( V_37 , V_32 ) ;
F_30 ( ! V_2 ) ;
}
V_49 = V_2 -> V_21 . V_22 + V_2 -> V_21 . V_33 - V_32 ;
V_49 = F_298 ( V_49 , V_31 + 1 - V_32 ) ;
if ( V_32 < V_2 -> V_97 ) {
V_49 = F_298 ( V_49 , V_2 -> V_97 - V_32 ) ;
F_29 ( V_2 , V_32 , V_49 ) ;
}
V_32 += V_49 ;
V_103 = V_2 -> V_103 ;
F_11 ( & V_103 -> V_52 ) ;
F_11 ( & V_2 -> V_52 ) ;
V_2 -> V_9 -= V_49 ;
V_103 -> V_305 -= V_49 ;
F_370 ( & V_103 -> V_301 , - V_49 ) ;
if ( V_2 -> V_277 ) {
V_103 -> V_307 += V_49 ;
V_289 = true ;
}
F_13 ( & V_2 -> V_52 ) ;
if ( ! V_289 && V_239 -> V_103 == V_103 ) {
F_11 ( & V_239 -> V_52 ) ;
if ( ! V_239 -> V_106 ) {
V_49 = F_298 ( V_49 , V_239 -> V_57 -
V_239 -> V_10 ) ;
V_239 -> V_10 += V_49 ;
V_103 -> V_308 += V_49 ;
if ( V_239 -> V_10 >= V_239 -> V_57 )
V_239 -> V_106 = 1 ;
}
F_13 ( & V_239 -> V_52 ) ;
}
F_13 ( & V_103 -> V_52 ) ;
}
if ( V_2 )
F_6 ( V_2 ) ;
return 0 ;
}
int F_371 ( struct V_107 * V_108 ,
struct V_34 * V_35 )
{
struct V_12 * V_37 = V_35 -> V_37 ;
struct V_485 * V_486 ;
T_2 V_32 ;
T_2 V_31 ;
int V_29 ;
if ( V_108 -> V_215 )
return 0 ;
if ( V_37 -> V_59 == & V_37 -> V_38 [ 0 ] )
V_486 = & V_37 -> V_38 [ 1 ] ;
else
V_486 = & V_37 -> V_38 [ 0 ] ;
while ( 1 ) {
V_29 = F_28 ( V_486 , 0 , & V_32 , & V_31 ,
V_60 , NULL ) ;
if ( V_29 )
break;
if ( F_245 ( V_35 , V_487 ) )
V_29 = F_142 ( V_35 , V_32 ,
V_31 + 1 - V_32 , NULL ) ;
F_372 ( V_486 , V_32 , V_31 , V_40 ) ;
F_369 ( V_35 , V_32 , V_31 ) ;
F_47 () ;
}
return 0 ;
}
static void F_373 ( struct V_12 * V_37 , T_2 V_36 ,
T_2 V_131 , T_2 V_144 )
{
struct V_100 * V_103 ;
T_2 V_7 ;
if ( V_131 < V_141 ) {
if ( V_144 == V_488 )
V_7 = V_292 ;
else
V_7 = V_290 ;
} else {
V_7 = V_291 ;
}
V_103 = F_69 ( V_37 , V_7 ) ;
F_30 ( ! V_103 ) ;
F_370 ( & V_103 -> V_301 , V_36 ) ;
}
static int F_155 ( struct V_107 * V_108 ,
struct V_34 * V_35 ,
T_2 V_27 , T_2 V_36 , T_2 V_17 ,
T_2 V_144 , T_2 V_489 ,
T_2 V_490 , int V_157 ,
struct V_178 * V_127 ,
int V_199 )
{
struct V_68 V_21 ;
struct V_64 * V_65 ;
struct V_12 * V_13 = V_35 -> V_37 ;
struct V_34 * V_63 = V_13 -> V_63 ;
struct V_66 * V_67 ;
struct V_114 * V_115 ;
struct V_161 * V_162 ;
int V_29 ;
int V_182 ;
int V_491 = 0 ;
int V_492 = 0 ;
int V_493 = 1 ;
T_3 V_116 ;
T_2 V_110 ;
int V_158 = 0 ;
enum V_202 type = V_494 ;
bool V_171 = F_76 ( V_35 -> V_37 ,
V_119 ) ;
if ( ! V_13 -> V_204 || ! F_148 ( V_144 ) )
V_199 = 1 ;
V_65 = F_33 () ;
if ( ! V_65 )
return - V_72 ;
V_65 -> V_76 = 1 ;
V_65 -> V_205 = 1 ;
V_182 = V_489 >= V_141 ;
F_30 ( ! V_182 && V_157 != 1 ) ;
if ( V_182 )
V_171 = 0 ;
V_29 = F_134 ( V_108 , V_63 , V_65 , & V_162 ,
V_27 , V_36 , V_17 ,
V_144 , V_489 ,
V_490 ) ;
if ( V_29 == 0 ) {
V_491 = V_65 -> V_84 [ 0 ] ;
while ( V_491 >= 0 ) {
F_40 ( V_65 -> V_83 [ 0 ] , & V_21 ,
V_491 ) ;
if ( V_21 . V_22 != V_27 )
break;
if ( V_21 . type == V_77 &&
V_21 . V_33 == V_36 ) {
V_492 = 1 ;
break;
}
if ( V_21 . type == V_86 &&
V_21 . V_33 == V_489 ) {
V_492 = 1 ;
break;
}
if ( V_65 -> V_84 [ 0 ] - V_491 > 5 )
break;
V_491 -- ;
}
#ifdef F_81
V_116 = F_77 ( V_65 -> V_83 [ 0 ] , V_491 ) ;
if ( V_492 && V_116 < sizeof( * V_115 ) )
V_492 = 0 ;
#endif
if ( ! V_492 ) {
F_30 ( V_162 ) ;
V_29 = F_139 ( V_108 , V_63 , V_65 ,
NULL , V_157 ,
V_182 , & V_158 ) ;
if ( V_29 ) {
F_150 ( V_108 , V_63 , V_29 ) ;
goto V_73;
}
F_44 ( V_65 ) ;
V_65 -> V_205 = 1 ;
V_21 . V_22 = V_27 ;
V_21 . type = V_77 ;
V_21 . V_33 = V_36 ;
if ( ! V_182 && V_171 ) {
V_21 . type = V_86 ;
V_21 . V_33 = V_489 ;
}
V_29 = F_37 ( V_108 , V_63 ,
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
V_21 . V_22 = V_27 ;
V_21 . type = V_77 ;
V_21 . V_33 = V_36 ;
F_44 ( V_65 ) ;
V_29 = F_37 ( V_108 , V_63 ,
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
F_150 ( V_108 , V_63 , V_29 ) ;
goto V_73;
}
V_491 = V_65 -> V_84 [ 0 ] ;
}
} else if ( F_8 ( V_29 == - V_151 ) ) {
F_375 ( V_63 , V_65 -> V_83 [ 0 ] ) ;
F_374 ( V_13 ,
L_16 ,
V_27 , V_17 , V_144 , V_489 ,
V_490 ) ;
F_150 ( V_108 , V_63 , V_29 ) ;
goto V_73;
} else {
F_150 ( V_108 , V_63 , V_29 ) ;
goto V_73;
}
V_67 = V_65 -> V_83 [ 0 ] ;
V_116 = F_77 ( V_67 , V_491 ) ;
#ifdef F_81
if ( V_116 < sizeof( * V_115 ) ) {
F_30 ( V_492 || V_491 != V_65 -> V_84 [ 0 ] ) ;
V_29 = F_87 ( V_108 , V_63 , V_65 ,
V_489 , 0 ) ;
if ( V_29 < 0 ) {
F_150 ( V_108 , V_63 , V_29 ) ;
goto V_73;
}
F_44 ( V_65 ) ;
V_65 -> V_205 = 1 ;
V_21 . V_22 = V_27 ;
V_21 . type = V_77 ;
V_21 . V_33 = V_36 ;
V_29 = F_37 ( V_108 , V_63 , & V_21 , V_65 ,
- 1 , 1 ) ;
if ( V_29 ) {
F_374 ( V_13 , L_15 ,
V_29 , V_27 ) ;
F_375 ( V_63 , V_65 -> V_83 [ 0 ] ) ;
}
if ( V_29 < 0 ) {
F_150 ( V_108 , V_63 , V_29 ) ;
goto V_73;
}
V_491 = V_65 -> V_84 [ 0 ] ;
V_67 = V_65 -> V_83 [ 0 ] ;
V_116 = F_77 ( V_67 , V_491 ) ;
}
#endif
F_30 ( V_116 < sizeof( * V_115 ) ) ;
V_115 = F_78 ( V_67 , V_491 ,
struct V_114 ) ;
if ( V_489 < V_141 &&
V_21 . type == V_77 ) {
struct V_136 * V_137 ;
F_30 ( V_116 < sizeof( * V_115 ) + sizeof( * V_137 ) ) ;
V_137 = (struct V_136 * ) ( V_115 + 1 ) ;
F_8 ( V_489 != F_376 ( V_67 , V_137 ) ) ;
}
V_110 = F_79 ( V_67 , V_115 ) ;
if ( V_110 < V_157 ) {
F_374 ( V_13 , L_17
L_18 , V_157 , V_110 , V_27 ) ;
V_29 = - V_477 ;
F_150 ( V_108 , V_63 , V_29 ) ;
goto V_73;
}
V_110 -= V_157 ;
if ( V_110 > 0 ) {
type = V_495 ;
if ( V_127 )
F_130 ( V_127 , V_67 , V_115 ) ;
if ( V_162 ) {
F_30 ( ! V_492 ) ;
} else {
F_90 ( V_67 , V_115 , V_110 ) ;
F_95 ( V_67 ) ;
}
if ( V_492 ) {
V_29 = F_139 ( V_108 , V_63 , V_65 ,
V_162 , V_157 ,
V_182 , & V_158 ) ;
if ( V_29 ) {
F_150 ( V_108 , V_63 , V_29 ) ;
goto V_73;
}
}
F_373 ( V_35 -> V_37 , - V_36 , V_489 ,
V_144 ) ;
} else {
if ( V_492 ) {
F_30 ( V_182 && V_157 !=
F_118 ( V_35 , V_65 , V_162 ) ) ;
if ( V_162 ) {
F_30 ( V_65 -> V_84 [ 0 ] != V_491 ) ;
} else {
F_30 ( V_65 -> V_84 [ 0 ] != V_491 + 1 ) ;
V_65 -> V_84 [ 0 ] = V_491 ;
V_493 = 2 ;
}
}
V_158 = 1 ;
V_29 = F_377 ( V_108 , V_63 , V_65 , V_65 -> V_84 [ 0 ] ,
V_493 ) ;
if ( V_29 ) {
F_150 ( V_108 , V_63 , V_29 ) ;
goto V_73;
}
F_44 ( V_65 ) ;
if ( V_182 ) {
V_29 = F_167 ( V_108 , V_35 , V_27 , V_36 ) ;
if ( V_29 ) {
F_150 ( V_108 , V_63 , V_29 ) ;
goto V_73;
}
}
V_29 = F_353 ( V_35 , V_27 , V_36 , 0 ) ;
if ( V_29 ) {
F_150 ( V_108 , V_63 , V_29 ) ;
goto V_73;
}
}
F_44 ( V_65 ) ;
if ( ! V_29 && V_158 && ! V_199 ) {
int V_496 = 0 ;
if ( V_489 >= V_141 &&
type == V_495 )
V_496 = 1 ;
V_29 = F_149 ( V_108 , V_13 , V_144 ,
V_27 , V_36 , type ,
V_496 ) ;
}
V_73:
F_50 ( V_65 ) ;
return V_29 ;
}
static T_1 int F_378 ( struct V_107 * V_108 ,
struct V_34 * V_35 , T_2 V_27 )
{
struct V_111 * V_102 ;
struct V_112 * V_113 ;
int V_29 = 0 ;
V_113 = & V_108 -> V_125 -> V_113 ;
F_11 ( & V_113 -> V_52 ) ;
V_102 = F_84 ( V_108 , V_27 ) ;
if ( ! V_102 )
goto V_497;
F_11 ( & V_102 -> V_52 ) ;
if ( F_178 ( & V_102 -> V_211 ) )
goto V_73;
if ( V_102 -> V_127 ) {
if ( ! V_102 -> V_219 )
goto V_73;
F_176 ( V_102 -> V_127 ) ;
V_102 -> V_127 = NULL ;
}
if ( ! F_85 ( & V_102 -> V_79 ) )
goto V_73;
V_102 -> V_126 . V_223 = 0 ;
F_179 ( & V_102 -> V_225 , & V_113 -> V_226 ) ;
F_180 ( & V_113 -> V_227 ) ;
V_113 -> V_224 -- ;
if ( V_102 -> V_221 == 0 )
V_113 -> V_222 -- ;
V_102 -> V_221 = 0 ;
F_13 ( & V_102 -> V_52 ) ;
F_13 ( & V_113 -> V_52 ) ;
F_30 ( V_102 -> V_127 ) ;
if ( V_102 -> V_219 )
V_29 = 1 ;
F_46 ( & V_102 -> V_79 ) ;
F_86 ( & V_102 -> V_126 ) ;
return V_29 ;
V_73:
F_13 ( & V_102 -> V_52 ) ;
V_497:
F_13 ( & V_113 -> V_52 ) ;
return 0 ;
}
void F_379 ( struct V_107 * V_108 ,
struct V_34 * V_35 ,
struct V_66 * V_258 ,
T_2 V_17 , int V_158 )
{
struct V_1 * V_2 = NULL ;
int V_498 = 1 ;
int V_29 ;
if ( V_35 -> V_254 . V_22 != V_200 ) {
V_29 = F_145 ( V_35 -> V_37 , V_108 ,
V_258 -> V_32 , V_258 -> V_49 ,
V_17 , V_35 -> V_254 . V_22 ,
F_223 ( V_258 ) ,
V_213 , NULL , 0 ) ;
F_30 ( V_29 ) ;
}
if ( ! V_158 )
return;
V_2 = F_68 ( V_35 -> V_37 , V_258 -> V_32 ) ;
if ( F_380 ( V_258 ) == V_108 -> V_279 ) {
if ( V_35 -> V_254 . V_22 != V_200 ) {
V_29 = F_378 ( V_108 , V_35 , V_258 -> V_32 ) ;
if ( ! V_29 )
goto V_73;
}
if ( F_381 ( V_258 , V_499 ) ) {
F_359 ( V_35 , V_2 , V_258 -> V_32 , V_258 -> V_49 , 1 ) ;
goto V_73;
}
F_8 ( F_221 ( V_500 , & V_258 -> V_501 ) ) ;
F_29 ( V_2 , V_258 -> V_32 , V_258 -> V_49 ) ;
F_365 ( V_2 , V_258 -> V_49 , V_483 , 0 ) ;
F_360 ( V_35 , V_258 -> V_32 , V_258 -> V_49 ) ;
V_498 = 0 ;
}
V_73:
if ( V_498 )
F_373 ( V_35 -> V_37 , V_258 -> V_49 ,
F_223 ( V_258 ) ,
V_35 -> V_254 . V_22 ) ;
F_382 ( V_502 , & V_258 -> V_501 ) ;
F_6 ( V_2 ) ;
}
int V_266 ( struct V_107 * V_108 , struct V_34 * V_35 ,
T_2 V_27 , T_2 V_36 , T_2 V_17 , T_2 V_144 ,
T_2 V_131 , T_2 V_33 , int V_199 )
{
int V_29 ;
struct V_12 * V_37 = V_35 -> V_37 ;
#ifdef F_219
if ( F_220 ( F_221 ( V_263 , & V_35 -> V_264 ) ) )
return 0 ;
#endif
F_373 ( V_35 -> V_37 , V_36 , V_131 , V_144 ) ;
if ( V_144 == V_200 ) {
F_8 ( V_131 >= V_141 ) ;
F_163 ( V_35 , V_27 , V_36 , 1 ) ;
V_29 = 0 ;
} else if ( V_131 < V_141 ) {
V_29 = F_145 ( V_37 , V_108 , V_27 ,
V_36 ,
V_17 , V_144 , ( int ) V_131 ,
V_213 , NULL , V_199 ) ;
} else {
V_29 = F_146 ( V_37 , V_108 , V_27 ,
V_36 ,
V_17 , V_144 , V_131 ,
V_33 , V_213 ,
NULL , V_199 ) ;
}
return V_29 ;
}
static T_2 F_383 ( struct V_34 * V_35 ,
struct V_1 * V_2 ,
T_2 V_242 , T_2 V_36 )
{
T_2 V_29 = F_271 ( V_242 , V_35 -> V_503 ) ;
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
( V_2 -> V_11 -> V_504 >= V_36 ) ) ;
F_26 ( V_54 ) ;
}
static T_1 int
F_385 ( struct V_1 * V_2 )
{
struct V_50 * V_54 ;
int V_29 = 0 ;
V_54 = F_25 ( V_2 ) ;
if ( ! V_54 )
return ( V_2 -> V_3 == V_5 ) ? - V_173 : 0 ;
F_299 ( V_54 -> V_89 , F_1 ( V_2 ) ) ;
if ( V_2 -> V_3 == V_5 )
V_29 = - V_173 ;
F_26 ( V_54 ) ;
return V_29 ;
}
int F_386 ( T_2 V_7 )
{
if ( V_7 & V_298 )
return V_505 ;
else if ( V_7 & V_297 )
return V_506 ;
else if ( V_7 & V_296 )
return V_507 ;
else if ( V_7 & V_337 )
return V_508 ;
else if ( V_7 & V_338 )
return V_509 ;
else if ( V_7 & V_339 )
return V_510 ;
return V_511 ;
}
int F_387 ( struct V_1 * V_2 )
{
return F_386 ( V_2 -> V_7 ) ;
}
static const char * F_388 ( enum V_512 type )
{
if ( type >= V_302 )
return NULL ;
return V_513 [ type ] ;
}
static inline void
F_389 ( struct V_1 * V_2 ,
int V_482 )
{
if ( V_482 )
F_36 ( & V_2 -> V_514 ) ;
}
static inline void
F_390 ( struct V_1 * V_2 ,
int V_482 )
{
F_4 ( V_2 ) ;
if ( V_482 )
F_36 ( & V_2 -> V_514 ) ;
}
static struct V_1 *
F_391 ( struct V_1 * V_14 ,
struct V_515 * V_516 ,
int V_482 )
{
struct V_1 * V_517 ;
bool V_518 = false ;
V_78:
F_11 ( & V_516 -> V_519 ) ;
if ( V_518 ) {
if ( V_517 == V_516 -> V_14 )
return V_517 ;
F_45 ( & V_517 -> V_514 ) ;
F_6 ( V_517 ) ;
}
V_517 = V_516 -> V_14 ;
if ( ! V_517 )
return NULL ;
if ( V_517 == V_14 )
return V_517 ;
F_4 ( V_517 ) ;
if ( ! V_482 )
return V_517 ;
if ( F_291 ( & V_517 -> V_514 ) )
return V_517 ;
F_13 ( & V_516 -> V_519 ) ;
F_36 ( & V_517 -> V_514 ) ;
V_518 = true ;
goto V_78;
}
static inline void
F_392 ( struct V_1 * V_2 ,
int V_482 )
{
if ( V_482 )
F_45 ( & V_2 -> V_514 ) ;
F_6 ( V_2 ) ;
}
static T_1 int F_393 ( struct V_34 * V_520 ,
T_2 V_36 , T_2 V_521 ,
T_2 V_522 , struct V_68 * V_210 ,
T_2 V_7 , int V_482 )
{
int V_29 = 0 ;
struct V_34 * V_35 = V_520 -> V_37 -> V_63 ;
struct V_515 * V_523 = NULL ;
struct V_1 * V_14 = NULL ;
T_2 V_476 = 0 ;
T_2 V_524 = 0 ;
int V_525 = 2 * 1024 * 1024 ;
struct V_100 * V_103 ;
int V_526 = 0 ;
int V_527 = F_386 ( V_7 ) ;
int V_528 = ( V_7 & V_291 ) ?
V_529 : V_484 ;
bool V_530 = false ;
bool V_531 = false ;
bool V_532 = true ;
bool V_533 = false ;
F_8 ( V_36 < V_35 -> V_346 ) ;
F_394 ( V_210 , V_77 ) ;
V_210 -> V_22 = 0 ;
V_210 -> V_33 = 0 ;
F_395 ( V_520 , V_36 , V_521 , V_7 ) ;
V_103 = F_69 ( V_35 -> V_37 , V_7 ) ;
if ( ! V_103 ) {
F_374 ( V_35 -> V_37 , L_19 , V_7 ) ;
return - V_352 ;
}
if ( F_288 ( V_103 ) )
V_532 = false ;
if ( V_7 & V_290 && V_532 ) {
V_523 = & V_35 -> V_37 -> V_534 ;
if ( ! F_245 ( V_35 , V_535 ) )
V_525 = 64 * 1024 ;
}
if ( ( V_7 & V_291 ) && V_532 &&
F_245 ( V_35 , V_535 ) ) {
V_523 = & V_35 -> V_37 -> V_536 ;
}
if ( V_523 ) {
F_11 ( & V_523 -> V_52 ) ;
if ( V_523 -> V_14 )
V_522 = V_523 -> V_537 ;
F_13 ( & V_523 -> V_52 ) ;
}
V_476 = F_396 ( V_476 , V_26 ( V_35 , 0 ) ) ;
V_476 = F_396 ( V_476 , V_522 ) ;
if ( ! V_523 )
V_525 = 0 ;
if ( V_476 == V_522 ) {
V_14 = F_68 ( V_35 -> V_37 ,
V_476 ) ;
if ( V_14 && F_3 ( V_14 , V_7 ) &&
V_14 -> V_3 != V_94 ) {
F_36 ( & V_103 -> V_304 ) ;
if ( F_204 ( & V_14 -> V_91 ) ||
V_14 -> V_277 ) {
F_6 ( V_14 ) ;
F_45 ( & V_103 -> V_304 ) ;
} else {
V_527 = F_387 ( V_14 ) ;
F_389 ( V_14 , V_482 ) ;
goto V_538;
}
} else if ( V_14 ) {
F_6 ( V_14 ) ;
}
}
V_539:
V_533 = false ;
F_36 ( & V_103 -> V_304 ) ;
F_397 (block_group, &space_info->block_groups[index],
list) {
T_2 V_33 ;
int V_3 ;
F_390 ( V_14 , V_482 ) ;
V_476 = V_14 -> V_21 . V_22 ;
if ( ! F_3 ( V_14 , V_7 ) ) {
T_2 V_540 = V_296 |
V_297 |
V_338 |
V_339 |
V_298 ;
if ( ( V_7 & V_540 ) && ! ( V_14 -> V_7 & V_540 ) )
goto V_526;
}
V_538:
V_3 = F_1 ( V_14 ) ;
if ( F_220 ( ! V_3 ) ) {
V_29 = F_51 ( V_14 , 0 ) ;
F_30 ( V_29 < 0 ) ;
V_29 = 0 ;
}
if ( F_220 ( V_14 -> V_3 == V_5 ) )
goto V_526;
if ( F_220 ( V_14 -> V_277 ) )
goto V_526;
if ( V_523 ) {
struct V_1 * V_541 ;
unsigned long V_542 ;
V_541 = F_391 ( V_14 ,
V_523 ,
V_482 ) ;
if ( ! V_541 )
goto V_543;
if ( V_541 != V_14 &&
( V_541 -> V_277 ||
! F_3 ( V_541 , V_7 ) ) )
goto V_544;
V_33 = F_398 ( V_541 ,
V_523 ,
V_36 ,
V_541 -> V_21 . V_22 ,
& V_524 ) ;
if ( V_33 ) {
F_13 ( & V_523 -> V_519 ) ;
F_399 ( V_35 ,
V_541 ,
V_476 , V_36 ) ;
if ( V_541 != V_14 ) {
F_392 ( V_14 ,
V_482 ) ;
V_14 = V_541 ;
}
goto V_545;
}
F_8 ( V_523 -> V_14 != V_541 ) ;
V_544:
if ( V_526 >= V_546 &&
V_541 != V_14 ) {
F_13 ( & V_523 -> V_519 ) ;
F_392 ( V_541 ,
V_482 ) ;
goto V_547;
}
F_400 ( NULL , V_523 ) ;
if ( V_541 != V_14 )
F_392 ( V_541 ,
V_482 ) ;
V_543:
if ( V_526 >= V_546 ) {
F_13 ( & V_523 -> V_519 ) ;
goto V_547;
}
V_542 = F_34 (unsigned long,
empty_cluster + empty_size,
block_group->full_stripe_len) ;
V_29 = F_401 ( V_35 , V_14 ,
V_523 , V_476 ,
V_36 ,
V_542 ) ;
if ( V_29 == 0 ) {
V_33 = F_398 ( V_14 ,
V_523 ,
V_36 ,
V_476 ,
& V_524 ) ;
if ( V_33 ) {
F_13 ( & V_523 -> V_519 ) ;
F_399 ( V_35 ,
V_14 , V_476 ,
V_36 ) ;
goto V_545;
}
} else if ( ! V_3 && V_526 > V_548
&& ! V_530 ) {
F_13 ( & V_523 -> V_519 ) ;
V_530 = true ;
F_384 ( V_14 ,
V_36 + V_525 + V_521 ) ;
goto V_538;
}
F_400 ( NULL , V_523 ) ;
F_13 ( & V_523 -> V_519 ) ;
goto V_526;
}
V_547:
F_11 ( & V_14 -> V_11 -> V_549 ) ;
if ( V_3 &&
V_14 -> V_11 -> V_504 <
V_36 + V_525 + V_521 ) {
if ( V_14 -> V_11 -> V_504 >
V_524 )
V_524 =
V_14 -> V_11 -> V_504 ;
F_13 ( & V_14 -> V_11 -> V_549 ) ;
goto V_526;
}
F_13 ( & V_14 -> V_11 -> V_549 ) ;
V_33 = F_402 ( V_14 , V_476 ,
V_36 , V_521 ,
& V_524 ) ;
if ( ! V_33 && ! V_531 && ! V_3 &&
V_526 > V_548 ) {
F_384 ( V_14 ,
V_36 + V_521 ) ;
V_531 = true ;
goto V_538;
} else if ( ! V_33 ) {
if ( ! V_3 )
V_533 = true ;
goto V_526;
}
V_545:
V_476 = F_383 ( V_35 , V_14 ,
V_33 , V_36 ) ;
if ( V_476 + V_36 >
V_14 -> V_21 . V_22 + V_14 -> V_21 . V_33 ) {
F_29 ( V_14 , V_33 , V_36 ) ;
goto V_526;
}
if ( V_33 < V_476 )
F_29 ( V_14 , V_33 ,
V_476 - V_33 ) ;
F_30 ( V_33 > V_476 ) ;
V_29 = F_365 ( V_14 , V_36 ,
V_528 , V_482 ) ;
if ( V_29 == - V_176 ) {
F_29 ( V_14 , V_33 , V_36 ) ;
goto V_526;
}
V_210 -> V_22 = V_476 ;
V_210 -> V_33 = V_36 ;
F_403 ( V_520 , V_14 ,
V_476 , V_36 ) ;
F_392 ( V_14 , V_482 ) ;
break;
V_526:
V_530 = false ;
V_531 = false ;
F_30 ( V_527 != F_387 ( V_14 ) ) ;
F_392 ( V_14 , V_482 ) ;
}
F_45 ( & V_103 -> V_304 ) ;
if ( ! V_210 -> V_22 && V_526 >= V_550 && V_533 )
goto V_539;
if ( ! V_210 -> V_22 && ++ V_527 < V_302 )
goto V_539;
if ( ! V_210 -> V_22 && V_526 < V_546 ) {
V_527 = 0 ;
V_526 ++ ;
if ( V_526 == V_551 ) {
struct V_107 * V_108 ;
int V_552 = 0 ;
V_108 = V_347 -> V_348 ;
if ( V_108 )
V_552 = 1 ;
else
V_108 = F_193 ( V_35 ) ;
if ( F_194 ( V_108 ) ) {
V_29 = F_195 ( V_108 ) ;
goto V_73;
}
V_29 = F_273 ( V_108 , V_35 , V_7 ,
V_351 ) ;
if ( V_29 < 0 && V_29 != - V_352 )
F_150 ( V_108 ,
V_35 , V_29 ) ;
else
V_29 = 0 ;
if ( ! V_552 )
F_197 ( V_108 , V_35 ) ;
if ( V_29 )
goto V_73;
}
if ( V_526 == V_546 ) {
V_521 = 0 ;
V_525 = 0 ;
}
goto V_539;
} else if ( ! V_210 -> V_22 ) {
V_29 = - V_352 ;
} else if ( V_210 -> V_22 ) {
V_29 = 0 ;
}
V_73:
if ( V_29 == - V_352 )
V_210 -> V_33 = V_524 ;
return V_29 ;
}
static void F_286 ( struct V_100 * V_13 , T_2 V_342 ,
int V_553 )
{
struct V_1 * V_2 ;
int V_527 = 0 ;
F_11 ( & V_13 -> V_52 ) ;
F_404 ( V_554 L_20 ,
V_13 -> V_7 ,
V_13 -> V_293 - V_13 -> V_294 - V_13 -> V_305 -
V_13 -> V_306 - V_13 -> V_307 ,
( V_13 -> V_106 ) ? L_21 : L_22 ) ;
F_404 ( V_554 L_23
L_24 ,
V_13 -> V_293 , V_13 -> V_294 , V_13 -> V_305 ,
V_13 -> V_306 , V_13 -> V_308 ,
V_13 -> V_307 ) ;
F_13 ( & V_13 -> V_52 ) ;
if ( ! V_553 )
return;
F_36 ( & V_13 -> V_304 ) ;
V_78:
F_397 (cache, &info->block_groups[index], list) {
F_11 ( & V_2 -> V_52 ) ;
F_404 ( V_554 L_25
L_26
L_27 ,
V_2 -> V_21 . V_22 , V_2 -> V_21 . V_33 ,
F_356 ( & V_2 -> V_133 ) , V_2 -> V_9 ,
V_2 -> V_10 , V_2 -> V_277 ? L_28 : L_21 ) ;
F_405 ( V_2 , V_342 ) ;
F_13 ( & V_2 -> V_52 ) ;
}
if ( ++ V_527 < V_302 )
goto V_78;
F_45 ( & V_13 -> V_304 ) ;
}
int F_406 ( struct V_34 * V_35 ,
T_2 V_36 , T_2 V_555 ,
T_2 V_521 , T_2 V_522 ,
struct V_68 * V_210 , int V_182 , int V_482 )
{
bool V_556 = false ;
T_2 V_7 ;
int V_29 ;
V_7 = F_270 ( V_35 , V_182 ) ;
V_78:
F_8 ( V_36 < V_35 -> V_346 ) ;
V_29 = F_393 ( V_35 , V_36 , V_521 , V_522 , V_210 ,
V_7 , V_482 ) ;
if ( V_29 == - V_352 ) {
if ( ! V_556 && V_210 -> V_33 ) {
V_36 = F_298 ( V_36 >> 1 , V_210 -> V_33 ) ;
V_36 = F_407 ( V_36 , V_35 -> V_346 ) ;
V_36 = F_396 ( V_36 , V_555 ) ;
if ( V_36 == V_555 )
V_556 = true ;
goto V_78;
} else if ( F_245 ( V_35 , V_364 ) ) {
struct V_100 * V_356 ;
V_356 = F_69 ( V_35 -> V_37 , V_7 ) ;
F_374 ( V_35 -> V_37 , L_29 ,
V_7 , V_36 ) ;
if ( V_356 )
F_286 ( V_356 , V_36 , 1 ) ;
}
}
return V_29 ;
}
static int F_408 ( struct V_34 * V_35 ,
T_2 V_32 , T_2 V_49 ,
int V_498 , int V_482 )
{
struct V_1 * V_2 ;
int V_29 = 0 ;
V_2 = F_68 ( V_35 -> V_37 , V_32 ) ;
if ( ! V_2 ) {
F_374 ( V_35 -> V_37 , L_30 ,
V_32 ) ;
return - V_352 ;
}
if ( F_245 ( V_35 , V_487 ) )
V_29 = F_142 ( V_35 , V_32 , V_49 , NULL ) ;
if ( V_498 )
F_359 ( V_35 , V_2 , V_32 , V_49 , 1 ) ;
else {
F_29 ( V_2 , V_32 , V_49 ) ;
F_365 ( V_2 , V_49 , V_483 , V_482 ) ;
}
F_6 ( V_2 ) ;
F_360 ( V_35 , V_32 , V_49 ) ;
return V_29 ;
}
int F_409 ( struct V_34 * V_35 ,
T_2 V_32 , T_2 V_49 , int V_482 )
{
return F_408 ( V_35 , V_32 , V_49 , 0 , V_482 ) ;
}
int F_410 ( struct V_34 * V_35 ,
T_2 V_32 , T_2 V_49 )
{
return F_408 ( V_35 , V_32 , V_49 , 1 , 0 ) ;
}
static int F_154 ( struct V_107 * V_108 ,
struct V_34 * V_35 ,
T_2 V_17 , T_2 V_144 ,
T_2 V_7 , T_2 V_131 , T_2 V_33 ,
struct V_68 * V_210 , int V_130 )
{
int V_29 ;
struct V_12 * V_37 = V_35 -> V_37 ;
struct V_114 * V_557 ;
struct V_161 * V_162 ;
struct V_64 * V_65 ;
struct V_66 * V_67 ;
int type ;
T_3 V_57 ;
if ( V_17 > 0 )
type = V_152 ;
else
type = V_153 ;
V_57 = sizeof( * V_557 ) + F_125 ( type ) ;
V_65 = F_33 () ;
if ( ! V_65 )
return - V_72 ;
V_65 -> V_205 = 1 ;
V_29 = F_106 ( V_108 , V_37 -> V_63 , V_65 ,
V_210 , V_57 ) ;
if ( V_29 ) {
F_50 ( V_65 ) ;
return V_29 ;
}
V_67 = V_65 -> V_83 [ 0 ] ;
V_557 = F_78 ( V_67 , V_65 -> V_84 [ 0 ] ,
struct V_114 ) ;
F_90 ( V_67 , V_557 , V_130 ) ;
F_91 ( V_67 , V_557 , V_108 -> V_279 ) ;
F_92 ( V_67 , V_557 ,
V_7 | V_143 ) ;
V_162 = (struct V_161 * ) ( V_557 + 1 ) ;
F_132 ( V_67 , V_162 , type ) ;
if ( V_17 > 0 ) {
struct V_156 * V_149 ;
V_149 = (struct V_156 * ) ( V_162 + 1 ) ;
F_133 ( V_67 , V_162 , V_17 ) ;
F_107 ( V_67 , V_149 , V_130 ) ;
} else {
struct V_148 * V_149 ;
V_149 = (struct V_148 * ) ( & V_162 -> V_33 ) ;
F_109 ( V_67 , V_149 , V_144 ) ;
F_110 ( V_67 , V_149 , V_131 ) ;
F_111 ( V_67 , V_149 , V_33 ) ;
F_112 ( V_67 , V_149 , V_130 ) ;
}
F_95 ( V_65 -> V_83 [ 0 ] ) ;
F_50 ( V_65 ) ;
V_29 = F_149 ( V_108 , V_37 , V_144 ,
V_210 -> V_22 , V_210 -> V_33 ,
V_203 , 0 ) ;
if ( V_29 )
return V_29 ;
V_29 = F_353 ( V_35 , V_210 -> V_22 , V_210 -> V_33 , 1 ) ;
if ( V_29 ) {
F_374 ( V_37 , L_31 ,
V_210 -> V_22 , V_210 -> V_33 ) ;
F_83 () ;
}
F_411 ( V_35 , V_210 -> V_22 , V_210 -> V_33 ) ;
return V_29 ;
}
static int F_161 ( struct V_107 * V_108 ,
struct V_34 * V_35 ,
T_2 V_17 , T_2 V_144 ,
T_2 V_7 , struct V_461 * V_21 ,
int V_165 , struct V_68 * V_210 ,
int V_199 )
{
int V_29 ;
struct V_12 * V_37 = V_35 -> V_37 ;
struct V_114 * V_557 ;
struct V_136 * V_558 ;
struct V_161 * V_162 ;
struct V_64 * V_65 ;
struct V_66 * V_67 ;
T_3 V_57 = sizeof( * V_557 ) + sizeof( * V_162 ) ;
T_2 V_36 = V_210 -> V_33 ;
bool V_171 = F_76 ( V_35 -> V_37 ,
V_119 ) ;
if ( ! V_171 )
V_57 += sizeof( * V_558 ) ;
V_65 = F_33 () ;
if ( ! V_65 ) {
F_410 ( V_35 , V_210 -> V_22 ,
V_35 -> V_88 ) ;
return - V_72 ;
}
V_65 -> V_205 = 1 ;
V_29 = F_106 ( V_108 , V_37 -> V_63 , V_65 ,
V_210 , V_57 ) ;
if ( V_29 ) {
F_410 ( V_35 , V_210 -> V_22 ,
V_35 -> V_88 ) ;
F_50 ( V_65 ) ;
return V_29 ;
}
V_67 = V_65 -> V_83 [ 0 ] ;
V_557 = F_78 ( V_67 , V_65 -> V_84 [ 0 ] ,
struct V_114 ) ;
F_90 ( V_67 , V_557 , 1 ) ;
F_91 ( V_67 , V_557 , V_108 -> V_279 ) ;
F_92 ( V_67 , V_557 ,
V_7 | V_142 ) ;
if ( V_171 ) {
V_162 = (struct V_161 * ) ( V_557 + 1 ) ;
V_36 = V_35 -> V_88 ;
} else {
V_558 = (struct V_136 * ) ( V_557 + 1 ) ;
F_156 ( V_67 , V_558 , V_21 ) ;
F_94 ( V_67 , V_558 , V_165 ) ;
V_162 = (struct V_161 * ) ( V_558 + 1 ) ;
}
if ( V_17 > 0 ) {
F_30 ( ! ( V_7 & V_124 ) ) ;
F_132 ( V_67 , V_162 ,
V_163 ) ;
F_133 ( V_67 , V_162 , V_17 ) ;
} else {
F_132 ( V_67 , V_162 ,
V_164 ) ;
F_133 ( V_67 , V_162 , V_144 ) ;
}
F_95 ( V_67 ) ;
F_50 ( V_65 ) ;
if ( ! V_199 ) {
V_29 = F_149 ( V_108 , V_37 , V_144 ,
V_210 -> V_22 , V_36 ,
V_203 , 0 ) ;
if ( V_29 )
return V_29 ;
}
V_29 = F_353 ( V_35 , V_210 -> V_22 , V_35 -> V_88 , 1 ) ;
if ( V_29 ) {
F_374 ( V_37 , L_31 ,
V_210 -> V_22 , V_210 -> V_33 ) ;
F_83 () ;
}
F_411 ( V_35 , V_210 -> V_22 , V_35 -> V_88 ) ;
return V_29 ;
}
int F_412 ( struct V_107 * V_108 ,
struct V_34 * V_35 ,
T_2 V_144 , T_2 V_131 ,
T_2 V_33 , struct V_68 * V_210 )
{
int V_29 ;
F_30 ( V_144 == V_200 ) ;
V_29 = F_146 ( V_35 -> V_37 , V_108 , V_210 -> V_22 ,
V_210 -> V_33 , 0 ,
V_144 , V_131 , V_33 ,
V_228 , NULL , 0 ) ;
return V_29 ;
}
int F_413 ( struct V_107 * V_108 ,
struct V_34 * V_35 ,
T_2 V_144 , T_2 V_131 , T_2 V_33 ,
struct V_68 * V_210 )
{
int V_29 ;
struct V_1 * V_14 ;
if ( ! F_76 ( V_35 -> V_37 , V_481 ) ) {
V_29 = F_363 ( V_35 , V_210 -> V_22 , V_210 -> V_33 ) ;
if ( V_29 )
return V_29 ;
}
V_14 = F_68 ( V_35 -> V_37 , V_210 -> V_22 ) ;
if ( ! V_14 )
return - V_477 ;
V_29 = F_365 ( V_14 , V_210 -> V_33 ,
V_529 , 0 ) ;
F_30 ( V_29 ) ;
V_29 = F_154 ( V_108 , V_35 , 0 , V_144 ,
0 , V_131 , V_33 , V_210 , 1 ) ;
F_6 ( V_14 ) ;
return V_29 ;
}
static struct V_66 *
F_414 ( struct V_107 * V_108 , struct V_34 * V_35 ,
T_2 V_27 , T_3 V_559 , int V_165 )
{
struct V_66 * V_258 ;
V_258 = F_415 ( V_35 , V_27 , V_559 ) ;
if ( ! V_258 )
return F_416 ( - V_72 ) ;
F_417 ( V_258 , V_108 -> V_279 ) ;
F_418 ( V_35 -> V_254 . V_22 , V_258 , V_165 ) ;
F_419 ( V_258 ) ;
F_420 ( V_108 , V_35 , V_258 ) ;
F_382 ( V_560 , & V_258 -> V_501 ) ;
F_421 ( V_258 ) ;
F_422 ( V_258 ) ;
if ( V_35 -> V_254 . V_22 == V_200 ) {
if ( V_35 -> V_561 % 2 == 0 )
F_358 ( & V_35 -> V_562 , V_258 -> V_32 ,
V_258 -> V_32 + V_258 -> V_49 - 1 , V_40 ) ;
else
F_423 ( & V_35 -> V_562 , V_258 -> V_32 ,
V_258 -> V_32 + V_258 -> V_49 - 1 , V_40 ) ;
} else {
F_358 ( & V_108 -> V_125 -> V_563 , V_258 -> V_32 ,
V_258 -> V_32 + V_258 -> V_49 - 1 , V_40 ) ;
}
V_108 -> V_564 ++ ;
return V_258 ;
}
static struct V_238 *
F_424 ( struct V_107 * V_108 ,
struct V_34 * V_35 , T_3 V_559 )
{
struct V_238 * V_386 ;
struct V_238 * V_239 = & V_35 -> V_37 -> V_240 ;
int V_29 ;
bool V_565 = false ;
V_386 = F_317 ( V_108 , V_35 ) ;
if ( F_220 ( V_386 -> V_57 == 0 ) )
goto V_566;
V_78:
V_29 = F_315 ( V_386 , V_559 ) ;
if ( ! V_29 )
return V_386 ;
if ( V_386 -> V_567 )
return F_416 ( V_29 ) ;
if ( V_386 -> type == V_568 && ! V_565 ) {
V_565 = true ;
F_332 ( V_35 -> V_37 ) ;
goto V_78;
}
if ( F_245 ( V_35 , V_364 ) ) {
static F_425 ( V_569 ,
V_570 * 10 ,
1 ) ;
if ( F_426 ( & V_569 ) )
F_427 ( 1 , V_571
L_32 , V_29 ) ;
}
V_566:
V_29 = F_312 ( V_35 , V_386 , V_559 ,
V_397 ) ;
if ( ! V_29 )
return V_386 ;
if ( V_386 -> type != V_568 &&
V_386 -> V_103 == V_239 -> V_103 ) {
V_29 = F_315 ( V_239 , V_559 ) ;
if ( ! V_29 )
return V_239 ;
}
return F_416 ( V_29 ) ;
}
static void F_428 ( struct V_12 * V_37 ,
struct V_238 * V_386 , T_3 V_559 )
{
F_318 ( V_386 , V_559 , 0 ) ;
F_320 ( V_37 , V_386 , NULL , 0 ) ;
}
struct V_66 * F_429 ( struct V_107 * V_108 ,
struct V_34 * V_35 , T_3 V_559 ,
T_2 V_17 , T_2 V_144 ,
struct V_461 * V_21 , int V_165 ,
T_2 V_572 , T_2 V_521 )
{
struct V_68 V_210 ;
struct V_238 * V_386 ;
struct V_66 * V_258 ;
T_2 V_7 = 0 ;
int V_29 ;
bool V_171 = F_76 ( V_35 -> V_37 ,
V_119 ) ;
#ifdef F_219
if ( F_220 ( F_221 ( V_263 , & V_35 -> V_264 ) ) ) {
V_258 = F_414 ( V_108 , V_35 , V_35 -> V_573 ,
V_559 , V_165 ) ;
if ( ! F_194 ( V_258 ) )
V_35 -> V_573 += V_559 ;
return V_258 ;
}
#endif
V_386 = F_424 ( V_108 , V_35 , V_559 ) ;
if ( F_194 ( V_386 ) )
return F_430 ( V_386 ) ;
V_29 = F_406 ( V_35 , V_559 , V_559 ,
V_521 , V_572 , & V_210 , 0 , 0 ) ;
if ( V_29 ) {
F_428 ( V_35 -> V_37 , V_386 , V_559 ) ;
return F_416 ( V_29 ) ;
}
V_258 = F_414 ( V_108 , V_35 , V_210 . V_22 ,
V_559 , V_165 ) ;
F_30 ( F_194 ( V_258 ) ) ;
if ( V_144 == V_574 ) {
if ( V_17 == 0 )
V_17 = V_210 . V_22 ;
V_7 |= V_124 ;
} else
F_30 ( V_17 > 0 ) ;
if ( V_144 != V_200 ) {
struct V_178 * V_127 ;
V_127 = F_210 () ;
F_30 ( ! V_127 ) ;
if ( V_21 )
memcpy ( & V_127 -> V_21 , V_21 , sizeof( V_127 -> V_21 ) ) ;
else
memset ( & V_127 -> V_21 , 0 , sizeof( V_127 -> V_21 ) ) ;
V_127 -> V_129 = V_7 ;
if ( V_171 )
V_127 -> V_214 = 0 ;
else
V_127 -> V_214 = 1 ;
V_127 -> V_128 = 1 ;
V_127 -> V_182 = 0 ;
V_127 -> V_165 = V_165 ;
V_29 = F_145 ( V_35 -> V_37 , V_108 ,
V_210 . V_22 ,
V_210 . V_33 , V_17 , V_144 ,
V_165 , V_228 ,
V_127 , 0 ) ;
F_30 ( V_29 ) ;
}
return V_258 ;
}
static T_1 void F_431 ( struct V_107 * V_108 ,
struct V_34 * V_35 ,
struct V_575 * V_576 ,
struct V_64 * V_65 )
{
T_2 V_27 ;
T_2 V_282 ;
T_2 V_110 ;
T_2 V_7 ;
T_3 V_71 ;
T_3 V_559 ;
struct V_68 V_21 ;
struct V_66 * V_479 ;
int V_29 ;
int V_577 ;
int V_578 = 0 ;
if ( V_65 -> V_84 [ V_576 -> V_165 ] < V_576 -> V_579 ) {
V_576 -> V_580 = V_576 -> V_580 * 2 / 3 ;
V_576 -> V_580 = F_396 ( V_576 -> V_580 , 2 ) ;
} else {
V_576 -> V_580 = V_576 -> V_580 * 3 / 2 ;
V_576 -> V_580 = F_24 ( int , V_576 -> V_580 ,
F_432 ( V_35 ) ) ;
}
V_479 = V_65 -> V_83 [ V_576 -> V_165 ] ;
V_71 = F_38 ( V_479 ) ;
V_559 = F_230 ( V_35 , V_576 -> V_165 - 1 ) ;
for ( V_577 = V_65 -> V_84 [ V_576 -> V_165 ] ; V_577 < V_71 ; V_577 ++ ) {
if ( V_578 >= V_576 -> V_580 )
break;
F_47 () ;
V_27 = F_229 ( V_479 , V_577 ) ;
V_282 = F_433 ( V_479 , V_577 ) ;
if ( V_577 == V_65 -> V_84 [ V_576 -> V_165 ] )
goto V_76;
if ( V_576 -> V_581 == V_582 &&
V_282 <= V_35 -> V_254 . V_33 )
continue;
V_29 = F_75 ( V_108 , V_35 , V_27 ,
V_576 -> V_165 - 1 , 1 , & V_110 ,
& V_7 ) ;
if ( V_29 < 0 )
continue;
F_30 ( V_110 == 0 ) ;
if ( V_576 -> V_581 == V_583 ) {
if ( V_110 == 1 )
goto V_76;
if ( V_576 -> V_165 == 1 &&
( V_7 & V_124 ) )
continue;
if ( ! V_576 -> V_584 ||
V_282 <= V_35 -> V_254 . V_33 )
continue;
F_123 ( V_479 , & V_21 , V_577 ) ;
V_29 = F_434 ( & V_21 ,
& V_576 -> V_585 ) ;
if ( V_29 < 0 )
continue;
} else {
if ( V_576 -> V_165 == 1 &&
( V_7 & V_124 ) )
continue;
}
V_76:
V_29 = F_435 ( V_35 , V_27 , V_559 ,
V_282 ) ;
if ( V_29 )
break;
V_578 ++ ;
}
V_576 -> V_579 = V_577 ;
}
static T_1 int F_436 ( struct V_107 * V_108 ,
struct V_34 * V_35 ,
struct V_64 * V_65 ,
struct V_575 * V_576 , int V_586 )
{
int V_165 = V_576 -> V_165 ;
struct V_66 * V_479 = V_65 -> V_83 [ V_165 ] ;
T_2 V_587 = V_124 ;
int V_29 ;
if ( V_576 -> V_581 == V_582 &&
F_222 ( V_479 ) != V_35 -> V_254 . V_22 )
return 1 ;
if ( V_586 &&
( ( V_576 -> V_581 == V_583 && V_576 -> V_110 [ V_165 ] != 1 ) ||
( V_576 -> V_581 == V_582 && ! ( V_576 -> V_7 [ V_165 ] & V_587 ) ) ) ) {
F_30 ( ! V_65 -> V_588 [ V_165 ] ) ;
V_29 = F_75 ( V_108 , V_35 ,
V_479 -> V_32 , V_165 , 1 ,
& V_576 -> V_110 [ V_165 ] ,
& V_576 -> V_7 [ V_165 ] ) ;
F_30 ( V_29 == - V_72 ) ;
if ( V_29 )
return V_29 ;
F_30 ( V_576 -> V_110 [ V_165 ] == 0 ) ;
}
if ( V_576 -> V_581 == V_583 ) {
if ( V_576 -> V_110 [ V_165 ] > 1 )
return 1 ;
if ( V_65 -> V_588 [ V_165 ] && ! V_576 -> V_172 ) {
F_437 ( V_479 , V_65 -> V_588 [ V_165 ] ) ;
V_65 -> V_588 [ V_165 ] = 0 ;
}
return 0 ;
}
if ( ! ( V_576 -> V_7 [ V_165 ] & V_587 ) ) {
F_30 ( ! V_65 -> V_588 [ V_165 ] ) ;
V_29 = F_231 ( V_108 , V_35 , V_479 , 1 , V_576 -> V_589 ) ;
F_30 ( V_29 ) ;
V_29 = F_232 ( V_108 , V_35 , V_479 , 0 , V_576 -> V_589 ) ;
F_30 ( V_29 ) ;
V_29 = F_209 ( V_108 , V_35 , V_479 -> V_32 ,
V_479 -> V_49 , V_587 ,
F_223 ( V_479 ) , 0 ) ;
F_30 ( V_29 ) ;
V_576 -> V_7 [ V_165 ] |= V_587 ;
}
if ( V_65 -> V_588 [ V_165 ] && V_165 > 0 ) {
F_437 ( V_479 , V_65 -> V_588 [ V_165 ] ) ;
V_65 -> V_588 [ V_165 ] = 0 ;
}
return 0 ;
}
static T_1 int F_438 ( struct V_107 * V_108 ,
struct V_34 * V_35 ,
struct V_64 * V_65 ,
struct V_575 * V_576 , int * V_586 )
{
T_2 V_27 ;
T_2 V_282 ;
T_2 V_17 ;
T_3 V_559 ;
struct V_68 V_21 ;
struct V_66 * V_81 ;
int V_165 = V_576 -> V_165 ;
int V_76 = 0 ;
int V_29 = 0 ;
V_282 = F_433 ( V_65 -> V_83 [ V_165 ] ,
V_65 -> V_84 [ V_165 ] ) ;
if ( V_576 -> V_581 == V_582 &&
V_282 <= V_35 -> V_254 . V_33 ) {
* V_586 = 1 ;
return 1 ;
}
V_27 = F_229 ( V_65 -> V_83 [ V_165 ] , V_65 -> V_84 [ V_165 ] ) ;
V_559 = F_230 ( V_35 , V_165 - 1 ) ;
V_81 = F_439 ( V_35 , V_27 , V_559 ) ;
if ( ! V_81 ) {
V_81 = F_415 ( V_35 , V_27 , V_559 ) ;
if ( ! V_81 )
return - V_72 ;
F_418 ( V_35 -> V_254 . V_22 , V_81 ,
V_165 - 1 ) ;
V_76 = 1 ;
}
F_419 ( V_81 ) ;
F_421 ( V_81 ) ;
V_29 = F_75 ( V_108 , V_35 , V_27 , V_165 - 1 , 1 ,
& V_576 -> V_110 [ V_165 - 1 ] ,
& V_576 -> V_7 [ V_165 - 1 ] ) ;
if ( V_29 < 0 ) {
F_440 ( V_81 ) ;
return V_29 ;
}
if ( F_220 ( V_576 -> V_110 [ V_165 - 1 ] == 0 ) ) {
F_374 ( V_35 -> V_37 , L_33 ) ;
F_83 () ;
}
* V_586 = 0 ;
if ( V_576 -> V_581 == V_583 ) {
if ( V_576 -> V_110 [ V_165 - 1 ] > 1 ) {
if ( V_165 == 1 &&
( V_576 -> V_7 [ 0 ] & V_124 ) )
goto V_590;
if ( ! V_576 -> V_584 ||
V_282 <= V_35 -> V_254 . V_33 )
goto V_590;
F_123 ( V_65 -> V_83 [ V_165 ] , & V_21 ,
V_65 -> V_84 [ V_165 ] ) ;
V_29 = F_434 ( & V_21 , & V_576 -> V_585 ) ;
if ( V_29 < 0 )
goto V_590;
V_576 -> V_581 = V_582 ;
V_576 -> V_591 = V_165 - 1 ;
}
} else {
if ( V_165 == 1 &&
( V_576 -> V_7 [ 0 ] & V_124 ) )
goto V_590;
}
if ( ! F_441 ( V_81 , V_282 , 0 ) ) {
F_440 ( V_81 ) ;
F_442 ( V_81 ) ;
V_81 = NULL ;
* V_586 = 1 ;
}
if ( ! V_81 ) {
if ( V_76 && V_165 == 1 )
F_431 ( V_108 , V_35 , V_576 , V_65 ) ;
V_81 = F_443 ( V_35 , V_27 , V_559 , V_282 ) ;
if ( ! V_81 || ! F_444 ( V_81 ) ) {
F_442 ( V_81 ) ;
return - V_173 ;
}
F_419 ( V_81 ) ;
F_421 ( V_81 ) ;
}
V_165 -- ;
F_30 ( V_165 != F_223 ( V_81 ) ) ;
V_65 -> V_83 [ V_165 ] = V_81 ;
V_65 -> V_84 [ V_165 ] = 0 ;
V_65 -> V_588 [ V_165 ] = V_592 ;
V_576 -> V_165 = V_165 ;
if ( V_576 -> V_165 == 1 )
V_576 -> V_579 = 0 ;
return 0 ;
V_590:
V_576 -> V_110 [ V_165 - 1 ] = 0 ;
V_576 -> V_7 [ V_165 - 1 ] = 0 ;
if ( V_576 -> V_581 == V_583 ) {
if ( V_576 -> V_7 [ V_165 ] & V_124 ) {
V_17 = V_65 -> V_83 [ V_165 ] -> V_32 ;
} else {
F_30 ( V_35 -> V_254 . V_22 !=
F_222 ( V_65 -> V_83 [ V_165 ] ) ) ;
V_17 = 0 ;
}
V_29 = V_266 ( V_108 , V_35 , V_27 , V_559 , V_17 ,
V_35 -> V_254 . V_22 , V_165 - 1 , 0 , 0 ) ;
F_30 ( V_29 ) ;
}
F_440 ( V_81 ) ;
F_442 ( V_81 ) ;
* V_586 = 1 ;
return 1 ;
}
static T_1 int F_445 ( struct V_107 * V_108 ,
struct V_34 * V_35 ,
struct V_64 * V_65 ,
struct V_575 * V_576 )
{
int V_29 ;
int V_165 = V_576 -> V_165 ;
struct V_66 * V_479 = V_65 -> V_83 [ V_165 ] ;
T_2 V_17 = 0 ;
if ( V_576 -> V_581 == V_582 ) {
F_30 ( V_576 -> V_591 < V_165 ) ;
if ( V_165 < V_576 -> V_591 )
goto V_73;
V_29 = F_41 ( V_65 , V_165 + 1 , & V_576 -> V_585 ) ;
if ( V_29 > 0 )
V_576 -> V_584 = 0 ;
V_576 -> V_581 = V_583 ;
V_576 -> V_591 = - 1 ;
V_65 -> V_84 [ V_165 ] = 0 ;
if ( ! V_65 -> V_588 [ V_165 ] ) {
F_30 ( V_165 == 0 ) ;
F_419 ( V_479 ) ;
F_421 ( V_479 ) ;
V_65 -> V_588 [ V_165 ] = V_592 ;
V_29 = F_75 ( V_108 , V_35 ,
V_479 -> V_32 , V_165 , 1 ,
& V_576 -> V_110 [ V_165 ] ,
& V_576 -> V_7 [ V_165 ] ) ;
if ( V_29 < 0 ) {
F_437 ( V_479 , V_65 -> V_588 [ V_165 ] ) ;
V_65 -> V_588 [ V_165 ] = 0 ;
return V_29 ;
}
F_30 ( V_576 -> V_110 [ V_165 ] == 0 ) ;
if ( V_576 -> V_110 [ V_165 ] == 1 ) {
F_437 ( V_479 , V_65 -> V_588 [ V_165 ] ) ;
V_65 -> V_588 [ V_165 ] = 0 ;
return 1 ;
}
}
}
F_30 ( V_576 -> V_110 [ V_165 ] > 1 && ! V_65 -> V_588 [ V_165 ] ) ;
if ( V_576 -> V_110 [ V_165 ] == 1 ) {
if ( V_165 == 0 ) {
if ( V_576 -> V_7 [ V_165 ] & V_124 )
V_29 = F_232 ( V_108 , V_35 , V_479 , 1 ,
V_576 -> V_589 ) ;
else
V_29 = F_232 ( V_108 , V_35 , V_479 , 0 ,
V_576 -> V_589 ) ;
F_30 ( V_29 ) ;
}
if ( ! V_65 -> V_588 [ V_165 ] &&
F_380 ( V_479 ) == V_108 -> V_279 ) {
F_419 ( V_479 ) ;
F_421 ( V_479 ) ;
V_65 -> V_588 [ V_165 ] = V_592 ;
}
F_420 ( V_108 , V_35 , V_479 ) ;
}
if ( V_479 == V_35 -> V_126 ) {
if ( V_576 -> V_7 [ V_165 ] & V_124 )
V_17 = V_479 -> V_32 ;
else
F_30 ( V_35 -> V_254 . V_22 !=
F_222 ( V_479 ) ) ;
} else {
if ( V_576 -> V_7 [ V_165 + 1 ] & V_124 )
V_17 = V_65 -> V_83 [ V_165 + 1 ] -> V_32 ;
else
F_30 ( V_35 -> V_254 . V_22 !=
F_222 ( V_65 -> V_83 [ V_165 + 1 ] ) ) ;
}
F_379 ( V_108 , V_35 , V_479 , V_17 , V_576 -> V_110 [ V_165 ] == 1 ) ;
V_73:
V_576 -> V_110 [ V_165 ] = 0 ;
V_576 -> V_7 [ V_165 ] = 0 ;
return 0 ;
}
static T_1 int F_446 ( struct V_107 * V_108 ,
struct V_34 * V_35 ,
struct V_64 * V_65 ,
struct V_575 * V_576 )
{
int V_165 = V_576 -> V_165 ;
int V_586 = 1 ;
int V_29 ;
while ( V_165 >= 0 ) {
V_29 = F_436 ( V_108 , V_35 , V_65 , V_576 , V_586 ) ;
if ( V_29 > 0 )
break;
if ( V_165 == 0 )
break;
if ( V_65 -> V_84 [ V_165 ] >=
F_38 ( V_65 -> V_83 [ V_165 ] ) )
break;
V_29 = F_438 ( V_108 , V_35 , V_65 , V_576 , & V_586 ) ;
if ( V_29 > 0 ) {
V_65 -> V_84 [ V_165 ] ++ ;
continue;
} else if ( V_29 < 0 )
return V_29 ;
V_165 = V_576 -> V_165 ;
}
return 0 ;
}
static T_1 int F_447 ( struct V_107 * V_108 ,
struct V_34 * V_35 ,
struct V_64 * V_65 ,
struct V_575 * V_576 , int V_593 )
{
int V_165 = V_576 -> V_165 ;
int V_29 ;
V_65 -> V_84 [ V_165 ] = F_38 ( V_65 -> V_83 [ V_165 ] ) ;
while ( V_165 < V_593 && V_65 -> V_83 [ V_165 ] ) {
V_576 -> V_165 = V_165 ;
if ( V_65 -> V_84 [ V_165 ] + 1 <
F_38 ( V_65 -> V_83 [ V_165 ] ) ) {
V_65 -> V_84 [ V_165 ] ++ ;
return 0 ;
} else {
V_29 = F_445 ( V_108 , V_35 , V_65 , V_576 ) ;
if ( V_29 > 0 )
return 0 ;
if ( V_65 -> V_588 [ V_165 ] ) {
F_437 ( V_65 -> V_83 [ V_165 ] ,
V_65 -> V_588 [ V_165 ] ) ;
V_65 -> V_588 [ V_165 ] = 0 ;
}
F_442 ( V_65 -> V_83 [ V_165 ] ) ;
V_65 -> V_83 [ V_165 ] = NULL ;
V_165 ++ ;
}
}
return 1 ;
}
int F_448 ( struct V_34 * V_35 ,
struct V_238 * V_386 , int V_584 ,
int V_589 )
{
struct V_64 * V_65 ;
struct V_107 * V_108 ;
struct V_34 * V_87 = V_35 -> V_37 -> V_87 ;
struct V_594 * V_255 = & V_35 -> V_255 ;
struct V_575 * V_576 ;
struct V_68 V_21 ;
int V_82 = 0 ;
int V_29 ;
int V_165 ;
bool V_595 = false ;
V_65 = F_33 () ;
if ( ! V_65 ) {
V_82 = - V_72 ;
goto V_73;
}
V_576 = F_53 ( sizeof( * V_576 ) , V_40 ) ;
if ( ! V_576 ) {
F_50 ( V_65 ) ;
V_82 = - V_72 ;
goto V_73;
}
V_108 = F_449 ( V_87 , 0 ) ;
if ( F_194 ( V_108 ) ) {
V_82 = F_195 ( V_108 ) ;
goto V_121;
}
if ( V_386 )
V_108 -> V_386 = V_386 ;
if ( F_450 ( & V_255 -> V_596 ) == 0 ) {
V_165 = F_223 ( V_35 -> V_126 ) ;
V_65 -> V_83 [ V_165 ] = F_451 ( V_35 ) ;
F_421 ( V_65 -> V_83 [ V_165 ] ) ;
V_65 -> V_84 [ V_165 ] = 0 ;
V_65 -> V_588 [ V_165 ] = V_592 ;
memset ( & V_576 -> V_585 , 0 ,
sizeof( V_576 -> V_585 ) ) ;
} else {
F_452 ( & V_21 , & V_255 -> V_596 ) ;
memcpy ( & V_576 -> V_585 , & V_21 ,
sizeof( V_576 -> V_585 ) ) ;
V_165 = V_255 -> V_597 ;
F_30 ( V_165 == 0 ) ;
V_65 -> V_598 = V_165 ;
V_29 = F_37 ( NULL , V_35 , & V_21 , V_65 , 0 , 0 ) ;
V_65 -> V_598 = 0 ;
if ( V_29 < 0 ) {
V_82 = V_29 ;
goto V_599;
}
F_8 ( V_29 > 0 ) ;
F_128 ( V_65 , 0 ) ;
V_165 = F_223 ( V_35 -> V_126 ) ;
while ( 1 ) {
F_419 ( V_65 -> V_83 [ V_165 ] ) ;
F_421 ( V_65 -> V_83 [ V_165 ] ) ;
V_65 -> V_588 [ V_165 ] = V_592 ;
V_29 = F_75 ( V_108 , V_35 ,
V_65 -> V_83 [ V_165 ] -> V_32 ,
V_165 , 1 , & V_576 -> V_110 [ V_165 ] ,
& V_576 -> V_7 [ V_165 ] ) ;
if ( V_29 < 0 ) {
V_82 = V_29 ;
goto V_599;
}
F_30 ( V_576 -> V_110 [ V_165 ] == 0 ) ;
if ( V_165 == V_255 -> V_597 )
break;
F_440 ( V_65 -> V_83 [ V_165 ] ) ;
V_65 -> V_588 [ V_165 ] = 0 ;
F_8 ( V_576 -> V_110 [ V_165 ] != 1 ) ;
V_165 -- ;
}
}
V_576 -> V_165 = V_165 ;
V_576 -> V_591 = - 1 ;
V_576 -> V_581 = V_583 ;
V_576 -> V_584 = V_584 ;
V_576 -> V_172 = 0 ;
V_576 -> V_589 = V_589 ;
V_576 -> V_580 = F_432 ( V_35 ) ;
while ( 1 ) {
V_29 = F_446 ( V_108 , V_35 , V_65 , V_576 ) ;
if ( V_29 < 0 ) {
V_82 = V_29 ;
break;
}
V_29 = F_447 ( V_108 , V_35 , V_65 , V_576 , V_166 ) ;
if ( V_29 < 0 ) {
V_82 = V_29 ;
break;
}
if ( V_29 > 0 ) {
F_30 ( V_576 -> V_581 != V_583 ) ;
break;
}
if ( V_576 -> V_581 == V_583 ) {
V_165 = V_576 -> V_165 ;
F_453 ( V_65 -> V_83 [ V_165 ] ,
& V_255 -> V_596 ,
V_65 -> V_84 [ V_165 ] ) ;
V_255 -> V_597 = V_165 ;
}
F_30 ( V_576 -> V_165 == 0 ) ;
if ( F_454 ( V_108 , V_87 ) ||
( ! V_589 && F_455 ( V_35 ) ) ) {
V_29 = F_456 ( V_108 , V_87 ,
& V_35 -> V_254 ,
V_255 ) ;
if ( V_29 ) {
F_150 ( V_108 , V_87 , V_29 ) ;
V_82 = V_29 ;
goto V_599;
}
F_457 ( V_108 , V_87 ) ;
if ( ! V_589 && F_455 ( V_35 ) ) {
F_458 ( L_34 ) ;
V_82 = - V_176 ;
goto V_121;
}
V_108 = F_449 ( V_87 , 0 ) ;
if ( F_194 ( V_108 ) ) {
V_82 = F_195 ( V_108 ) ;
goto V_121;
}
if ( V_386 )
V_108 -> V_386 = V_386 ;
}
}
F_44 ( V_65 ) ;
if ( V_82 )
goto V_599;
V_29 = F_459 ( V_108 , V_87 , & V_35 -> V_254 ) ;
if ( V_29 ) {
F_150 ( V_108 , V_87 , V_29 ) ;
goto V_599;
}
if ( V_35 -> V_254 . V_22 != V_574 ) {
V_29 = F_460 ( V_87 , & V_35 -> V_254 , V_65 ,
NULL , NULL ) ;
if ( V_29 < 0 ) {
F_150 ( V_108 , V_87 , V_29 ) ;
V_82 = V_29 ;
goto V_599;
} else if ( V_29 > 0 ) {
F_461 ( V_108 , V_87 ,
V_35 -> V_254 . V_22 ) ;
}
}
if ( F_221 ( V_600 , & V_35 -> V_264 ) ) {
F_462 ( V_87 -> V_37 , V_35 ) ;
} else {
F_442 ( V_35 -> V_126 ) ;
F_442 ( V_35 -> V_601 ) ;
F_463 ( V_35 ) ;
}
V_595 = true ;
V_599:
F_457 ( V_108 , V_87 ) ;
V_121:
F_9 ( V_576 ) ;
F_50 ( V_65 ) ;
V_73:
if ( ! V_589 && V_595 == false )
F_464 ( V_35 ) ;
if ( V_82 && V_82 != - V_176 )
F_465 ( V_35 -> V_37 , V_82 ) ;
return V_82 ;
}
int F_466 ( struct V_107 * V_108 ,
struct V_34 * V_35 ,
struct V_66 * V_126 ,
struct V_66 * V_17 )
{
struct V_64 * V_65 ;
struct V_575 * V_576 ;
int V_165 ;
int V_602 ;
int V_29 = 0 ;
int V_603 ;
F_30 ( V_35 -> V_254 . V_22 != V_574 ) ;
V_65 = F_33 () ;
if ( ! V_65 )
return - V_72 ;
V_576 = F_53 ( sizeof( * V_576 ) , V_40 ) ;
if ( ! V_576 ) {
F_50 ( V_65 ) ;
return - V_72 ;
}
F_467 ( V_17 ) ;
V_602 = F_223 ( V_17 ) ;
F_468 ( V_17 ) ;
V_65 -> V_83 [ V_602 ] = V_17 ;
V_65 -> V_84 [ V_602 ] = F_38 ( V_17 ) ;
F_467 ( V_126 ) ;
V_165 = F_223 ( V_126 ) ;
V_65 -> V_83 [ V_165 ] = V_126 ;
V_65 -> V_84 [ V_165 ] = 0 ;
V_65 -> V_588 [ V_165 ] = V_592 ;
V_576 -> V_110 [ V_602 ] = 1 ;
V_576 -> V_7 [ V_602 ] = V_124 ;
V_576 -> V_165 = V_165 ;
V_576 -> V_591 = - 1 ;
V_576 -> V_581 = V_583 ;
V_576 -> V_584 = 0 ;
V_576 -> V_172 = 1 ;
V_576 -> V_589 = 1 ;
V_576 -> V_580 = F_432 ( V_35 ) ;
while ( 1 ) {
V_603 = F_446 ( V_108 , V_35 , V_65 , V_576 ) ;
if ( V_603 < 0 ) {
V_29 = V_603 ;
break;
}
V_603 = F_447 ( V_108 , V_35 , V_65 , V_576 , V_602 ) ;
if ( V_603 < 0 )
V_29 = V_603 ;
if ( V_603 != 0 )
break;
}
F_9 ( V_576 ) ;
F_50 ( V_65 ) ;
return V_29 ;
}
static T_2 F_469 ( struct V_34 * V_35 , T_2 V_7 )
{
T_2 V_331 ;
T_2 V_604 ;
V_604 = F_264 ( V_35 -> V_37 , V_7 ) ;
if ( V_604 )
return F_266 ( V_604 ) ;
V_331 = V_35 -> V_37 -> V_332 -> V_333 +
V_35 -> V_37 -> V_332 -> V_334 ;
V_604 = V_337 |
V_338 | V_339 |
V_297 | V_298 ;
if ( V_331 == 1 ) {
V_604 |= V_296 ;
V_604 = V_7 & ~ V_604 ;
if ( V_7 & V_337 )
return V_604 ;
if ( V_7 & ( V_297 |
V_298 ) )
return V_604 | V_296 ;
} else {
if ( V_7 & V_604 )
return V_7 ;
V_604 |= V_296 ;
V_604 = V_7 & ~ V_604 ;
if ( V_7 & V_296 )
return V_604 | V_297 ;
}
return V_7 ;
}
static int F_470 ( struct V_1 * V_2 , int V_357 )
{
struct V_100 * V_356 = V_2 -> V_103 ;
T_2 V_36 ;
T_2 V_605 ;
int V_29 = - V_352 ;
if ( ( V_356 -> V_7 &
( V_292 | V_290 ) ) &&
! V_357 )
V_605 = 1 * 1024 * 1024 ;
else
V_605 = 0 ;
F_11 ( & V_356 -> V_52 ) ;
F_11 ( & V_2 -> V_52 ) ;
if ( V_2 -> V_277 ) {
V_29 = 0 ;
goto V_73;
}
V_36 = V_2 -> V_21 . V_33 - V_2 -> V_10 - V_2 -> V_9 -
V_2 -> V_46 - F_356 ( & V_2 -> V_133 ) ;
if ( V_356 -> V_294 + V_356 -> V_306 + V_356 -> V_305 +
V_356 -> V_308 + V_356 -> V_307 + V_36 +
V_605 <= V_356 -> V_293 ) {
V_356 -> V_307 += V_36 ;
V_2 -> V_277 = 1 ;
V_29 = 0 ;
}
V_73:
F_13 ( & V_2 -> V_52 ) ;
F_13 ( & V_356 -> V_52 ) ;
return V_29 ;
}
int F_471 ( struct V_34 * V_35 ,
struct V_1 * V_2 )
{
struct V_107 * V_108 ;
T_2 V_606 ;
int V_29 ;
F_30 ( V_2 -> V_277 ) ;
V_108 = F_193 ( V_35 ) ;
if ( F_194 ( V_108 ) )
return F_195 ( V_108 ) ;
V_606 = F_469 ( V_35 , V_2 -> V_7 ) ;
if ( V_606 != V_2 -> V_7 ) {
V_29 = F_273 ( V_108 , V_35 , V_606 ,
V_351 ) ;
if ( V_29 < 0 )
goto V_73;
}
V_29 = F_470 ( V_2 , 0 ) ;
if ( ! V_29 )
goto V_73;
V_606 = F_267 ( V_35 , V_2 -> V_103 -> V_7 ) ;
V_29 = F_273 ( V_108 , V_35 , V_606 ,
V_351 ) ;
if ( V_29 < 0 )
goto V_73;
V_29 = F_470 ( V_2 , 0 ) ;
V_73:
F_197 ( V_108 , V_35 ) ;
return V_29 ;
}
int F_472 ( struct V_107 * V_108 ,
struct V_34 * V_35 , T_2 type )
{
T_2 V_606 = F_267 ( V_35 , type ) ;
return F_273 ( V_108 , V_35 , V_606 ,
V_351 ) ;
}
static T_2 F_473 ( struct V_101 * V_607 )
{
struct V_1 * V_14 ;
T_2 V_608 = 0 ;
int V_295 ;
F_397 (block_group, groups_list, list) {
F_11 ( & V_14 -> V_52 ) ;
if ( ! V_14 -> V_277 ) {
F_13 ( & V_14 -> V_52 ) ;
continue;
}
if ( V_14 -> V_7 & ( V_297 |
V_298 |
V_296 ) )
V_295 = 2 ;
else
V_295 = 1 ;
V_608 += ( V_14 -> V_21 . V_33 -
F_356 ( & V_14 -> V_133 ) ) *
V_295 ;
F_13 ( & V_14 -> V_52 ) ;
}
return V_608 ;
}
T_2 F_474 ( struct V_100 * V_356 )
{
int V_43 ;
T_2 V_608 = 0 ;
F_11 ( & V_356 -> V_52 ) ;
for ( V_43 = 0 ; V_43 < V_302 ; V_43 ++ )
if ( ! F_204 ( & V_356 -> V_303 [ V_43 ] ) )
V_608 += F_473 (
& V_356 -> V_303 [ V_43 ] ) ;
F_13 ( & V_356 -> V_52 ) ;
return V_608 ;
}
void F_475 ( struct V_34 * V_35 ,
struct V_1 * V_2 )
{
struct V_100 * V_356 = V_2 -> V_103 ;
T_2 V_36 ;
F_30 ( ! V_2 -> V_277 ) ;
F_11 ( & V_356 -> V_52 ) ;
F_11 ( & V_2 -> V_52 ) ;
V_36 = V_2 -> V_21 . V_33 - V_2 -> V_10 - V_2 -> V_9 -
V_2 -> V_46 - F_356 ( & V_2 -> V_133 ) ;
V_356 -> V_307 -= V_36 ;
V_2 -> V_277 = 0 ;
F_13 ( & V_2 -> V_52 ) ;
F_13 ( & V_356 -> V_52 ) ;
}
int F_476 ( struct V_34 * V_35 , T_2 V_27 )
{
struct V_1 * V_14 ;
struct V_100 * V_103 ;
struct V_609 * V_332 = V_35 -> V_37 -> V_332 ;
struct V_610 * V_611 ;
struct V_107 * V_108 ;
T_2 V_612 ;
T_2 V_613 = 1 ;
T_2 V_614 = 0 ;
T_2 V_326 ;
int V_527 ;
int V_106 = 0 ;
int V_29 = 0 ;
V_14 = F_68 ( V_35 -> V_37 , V_27 ) ;
if ( ! V_14 )
return - 1 ;
V_612 = F_356 ( & V_14 -> V_133 ) ;
if ( ! V_612 )
goto V_73;
V_103 = V_14 -> V_103 ;
F_11 ( & V_103 -> V_52 ) ;
V_106 = V_103 -> V_106 ;
if ( ( V_103 -> V_293 != V_14 -> V_21 . V_33 ) &&
( V_103 -> V_294 + V_103 -> V_306 +
V_103 -> V_305 + V_103 -> V_307 +
V_612 < V_103 -> V_293 ) ) {
F_13 ( & V_103 -> V_52 ) ;
goto V_73;
}
F_13 ( & V_103 -> V_52 ) ;
V_29 = - 1 ;
V_326 = F_264 ( V_35 -> V_37 , V_14 -> V_7 ) ;
if ( V_326 ) {
V_527 = F_386 ( F_266 ( V_326 ) ) ;
} else {
if ( V_106 )
goto V_73;
V_527 = F_387 ( V_14 ) ;
}
if ( V_527 == V_505 ) {
V_613 = 4 ;
V_612 >>= 1 ;
} else if ( V_527 == V_506 ) {
V_613 = 2 ;
} else if ( V_527 == V_507 ) {
V_612 <<= 1 ;
} else if ( V_527 == V_508 ) {
V_613 = V_332 -> V_333 ;
F_477 ( V_612 , V_613 ) ;
}
V_108 = F_193 ( V_35 ) ;
if ( F_194 ( V_108 ) ) {
V_29 = F_195 ( V_108 ) ;
goto V_73;
}
F_35 ( & V_35 -> V_37 -> V_367 ) ;
F_397 (device, &fs_devices->alloc_list, dev_alloc_list) {
T_2 V_615 ;
if ( V_611 -> V_293 > V_611 -> V_294 + V_612 &&
! V_611 -> V_616 ) {
V_29 = F_478 ( V_108 , V_611 , V_612 ,
& V_615 , NULL ) ;
if ( ! V_29 )
V_614 ++ ;
if ( V_614 >= V_613 )
break;
V_29 = - 1 ;
}
}
F_46 ( & V_35 -> V_37 -> V_367 ) ;
F_197 ( V_108 , V_35 ) ;
V_73:
F_6 ( V_14 ) ;
return V_29 ;
}
static int F_479 ( struct V_34 * V_35 ,
struct V_64 * V_65 , struct V_68 * V_21 )
{
int V_29 = 0 ;
struct V_68 V_138 ;
struct V_66 * V_67 ;
int V_577 ;
V_29 = F_37 ( NULL , V_35 , V_21 , V_65 , 0 , 0 ) ;
if ( V_29 < 0 )
goto V_73;
while ( 1 ) {
V_577 = V_65 -> V_84 [ 0 ] ;
V_67 = V_65 -> V_83 [ 0 ] ;
if ( V_577 >= F_38 ( V_67 ) ) {
V_29 = F_48 ( V_35 , V_65 ) ;
if ( V_29 == 0 )
continue;
if ( V_29 < 0 )
goto V_73;
break;
}
F_40 ( V_67 , & V_138 , V_577 ) ;
if ( V_138 . V_22 >= V_21 -> V_22 &&
V_138 . type == V_177 ) {
V_29 = 0 ;
goto V_73;
}
V_65 -> V_84 [ 0 ] ++ ;
}
V_73:
return V_29 ;
}
void F_480 ( struct V_12 * V_13 )
{
struct V_1 * V_14 ;
T_2 V_70 = 0 ;
while ( 1 ) {
struct V_269 * V_269 ;
V_14 = F_67 ( V_13 , V_70 ) ;
while ( V_14 ) {
F_11 ( & V_14 -> V_52 ) ;
if ( V_14 -> V_162 )
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
V_269 = V_14 -> V_269 ;
V_14 -> V_162 = 0 ;
V_14 -> V_269 = NULL ;
F_13 ( & V_14 -> V_52 ) ;
F_249 ( V_269 ) ;
V_70 = V_14 -> V_21 . V_22 + V_14 -> V_21 . V_33 ;
F_6 ( V_14 ) ;
}
}
int F_481 ( struct V_12 * V_13 )
{
struct V_1 * V_14 ;
struct V_100 * V_103 ;
struct V_50 * V_54 ;
struct V_15 * V_30 ;
F_63 ( & V_13 -> V_80 ) ;
while ( ! F_204 ( & V_13 -> V_98 ) ) {
V_54 = F_482 ( V_13 -> V_98 . V_81 ,
struct V_50 , V_91 ) ;
F_483 ( & V_54 -> V_91 ) ;
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
F_63 ( & V_14 -> V_103 -> V_304 ) ;
F_483 ( & V_14 -> V_91 ) ;
F_65 ( & V_14 -> V_103 -> V_304 ) ;
if ( V_14 -> V_3 == V_53 )
F_385 ( V_14 ) ;
if ( V_14 -> V_3 == V_94 ||
V_14 -> V_3 == V_5 )
F_19 ( V_13 -> V_63 , V_14 ) ;
F_484 ( V_14 ) ;
F_6 ( V_14 ) ;
F_11 ( & V_13 -> V_18 ) ;
}
F_13 ( & V_13 -> V_18 ) ;
F_485 () ;
F_334 ( V_13 ) ;
while ( ! F_204 ( & V_13 -> V_103 ) ) {
int V_43 ;
V_103 = F_482 ( V_13 -> V_103 . V_81 ,
struct V_100 ,
V_91 ) ;
if ( F_245 ( V_13 -> V_87 , V_364 ) ) {
if ( F_8 ( V_103 -> V_305 > 0 ||
V_103 -> V_306 > 0 ||
V_103 -> V_308 > 0 ) ) {
F_286 ( V_103 , 0 , 0 ) ;
}
}
F_483 ( & V_103 -> V_91 ) ;
for ( V_43 = 0 ; V_43 < V_302 ; V_43 ++ ) {
struct V_617 * V_313 ;
V_313 = V_103 -> V_618 [ V_43 ] ;
V_103 -> V_618 [ V_43 ] = NULL ;
if ( V_313 ) {
F_486 ( V_313 ) ;
F_487 ( V_313 ) ;
}
}
F_486 ( & V_103 -> V_313 ) ;
F_487 ( & V_103 -> V_313 ) ;
}
return 0 ;
}
static void F_488 ( struct V_100 * V_103 ,
struct V_1 * V_2 )
{
int V_527 = F_387 ( V_2 ) ;
bool V_236 = false ;
F_63 ( & V_103 -> V_304 ) ;
if ( F_204 ( & V_103 -> V_303 [ V_527 ] ) )
V_236 = true ;
F_64 ( & V_2 -> V_91 , & V_103 -> V_303 [ V_527 ] ) ;
F_65 ( & V_103 -> V_304 ) ;
if ( V_236 ) {
struct V_619 * V_620 ;
int V_29 ;
V_620 = F_53 ( sizeof( * V_620 ) , V_40 ) ;
if ( ! V_620 )
goto V_621;
V_620 -> V_622 = V_527 ;
F_489 ( & V_620 -> V_313 , & V_623 ) ;
V_29 = F_490 ( & V_620 -> V_313 , & V_103 -> V_313 ,
L_8 , F_388 ( V_527 ) ) ;
if ( V_29 ) {
F_487 ( & V_620 -> V_313 ) ;
goto V_621;
}
V_103 -> V_618 [ V_527 ] = & V_620 -> V_313 ;
}
return;
V_621:
F_491 ( L_35 ) ;
}
static struct V_1 *
F_492 ( struct V_34 * V_35 , T_2 V_32 , T_2 V_57 )
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
V_2 -> V_346 = V_35 -> V_346 ;
V_2 -> V_37 = V_35 -> V_37 ;
V_2 -> V_624 = F_493 ( V_35 ,
& V_35 -> V_37 -> V_48 ,
V_32 ) ;
F_57 ( & V_2 -> V_8 , 1 ) ;
F_257 ( & V_2 -> V_52 ) ;
F_256 ( & V_2 -> V_514 ) ;
F_54 ( & V_2 -> V_91 ) ;
F_54 ( & V_2 -> V_625 ) ;
F_54 ( & V_2 -> V_626 ) ;
F_494 ( V_2 ) ;
return V_2 ;
}
int F_495 ( struct V_34 * V_35 )
{
struct V_64 * V_65 ;
int V_29 ;
struct V_1 * V_2 ;
struct V_12 * V_13 = V_35 -> V_37 ;
struct V_100 * V_103 ;
struct V_68 V_21 ;
struct V_68 V_138 ;
struct V_66 * V_67 ;
int V_627 = 0 ;
T_2 V_628 ;
V_35 = V_13 -> V_63 ;
V_21 . V_22 = 0 ;
V_21 . V_33 = 0 ;
F_394 ( & V_21 , V_177 ) ;
V_65 = F_33 () ;
if ( ! V_65 )
return - V_72 ;
V_65 -> V_76 = 1 ;
V_628 = F_496 ( V_35 -> V_37 -> V_361 ) ;
if ( F_245 ( V_35 , V_283 ) &&
F_497 ( V_35 -> V_37 -> V_361 ) != V_628 )
V_627 = 1 ;
if ( F_245 ( V_35 , V_629 ) )
V_627 = 1 ;
while ( 1 ) {
V_29 = F_479 ( V_35 , V_65 , & V_21 ) ;
if ( V_29 > 0 )
break;
if ( V_29 != 0 )
goto error;
V_67 = V_65 -> V_83 [ 0 ] ;
F_40 ( V_67 , & V_138 , V_65 -> V_84 [ 0 ] ) ;
V_2 = F_492 ( V_35 , V_138 . V_22 ,
V_138 . V_33 ) ;
if ( ! V_2 ) {
V_29 = - V_72 ;
goto error;
}
if ( V_627 ) {
V_2 -> V_275 = V_286 ;
if ( F_245 ( V_35 , V_283 ) )
V_2 -> V_287 = 1 ;
}
F_498 ( V_67 , & V_2 -> V_133 ,
F_234 ( V_67 , V_65 -> V_84 [ 0 ] ) ,
sizeof( V_2 -> V_133 ) ) ;
V_2 -> V_7 = F_499 ( & V_2 -> V_133 ) ;
V_21 . V_22 = V_138 . V_22 + V_138 . V_33 ;
F_44 ( V_65 ) ;
V_29 = F_21 ( V_35 , V_2 ) ;
if ( V_29 ) {
F_19 ( V_35 , V_2 ) ;
F_6 ( V_2 ) ;
goto error;
}
if ( V_138 . V_33 == F_356 ( & V_2 -> V_133 ) ) {
V_2 -> V_97 = ( T_2 ) - 1 ;
V_2 -> V_3 = V_4 ;
F_19 ( V_35 , V_2 ) ;
} else if ( F_356 ( & V_2 -> V_133 ) == 0 ) {
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
F_484 ( V_2 ) ;
F_6 ( V_2 ) ;
goto error;
}
V_29 = F_254 ( V_13 , V_2 -> V_7 , V_138 . V_33 ,
F_356 ( & V_2 -> V_133 ) ,
& V_103 ) ;
if ( V_29 ) {
F_484 ( V_2 ) ;
F_11 ( & V_13 -> V_18 ) ;
F_179 ( & V_2 -> V_20 ,
& V_13 -> V_19 ) ;
F_13 ( & V_13 -> V_18 ) ;
F_6 ( V_2 ) ;
goto error;
}
V_2 -> V_103 = V_103 ;
F_11 ( & V_2 -> V_103 -> V_52 ) ;
V_2 -> V_103 -> V_307 += V_2 -> V_46 ;
F_13 ( & V_2 -> V_103 -> V_52 ) ;
F_488 ( V_103 , V_2 ) ;
F_260 ( V_35 -> V_37 , V_2 -> V_7 ) ;
if ( F_500 ( V_35 , V_2 -> V_21 . V_22 ) )
F_470 ( V_2 , 1 ) ;
}
F_71 (space_info, &root->fs_info->space_info, list) {
if ( ! ( F_267 ( V_35 , V_103 -> V_7 ) &
( V_298 |
V_297 |
V_338 |
V_339 |
V_296 ) ) )
continue;
F_397 (cache,
&space_info->block_groups[BTRFS_RAID_RAID0],
list)
F_470 ( V_2 , 1 ) ;
F_397 (cache,
&space_info->block_groups[BTRFS_RAID_SINGLE],
list)
F_470 ( V_2 , 1 ) ;
}
F_333 ( V_13 ) ;
V_29 = 0 ;
error:
F_50 ( V_65 ) ;
return V_29 ;
}
void F_205 ( struct V_107 * V_108 ,
struct V_34 * V_35 )
{
struct V_1 * V_14 , * V_335 ;
struct V_34 * V_63 = V_35 -> V_37 -> V_63 ;
struct V_630 V_133 ;
struct V_68 V_21 ;
int V_29 = 0 ;
F_367 (block_group, tmp, &trans->new_bgs,
new_bg_list) {
F_368 ( & V_14 -> V_626 ) ;
if ( V_29 )
continue;
F_11 ( & V_14 -> V_52 ) ;
memcpy ( & V_133 , & V_14 -> V_133 , sizeof( V_133 ) ) ;
memcpy ( & V_21 , & V_14 -> V_21 , sizeof( V_21 ) ) ;
F_13 ( & V_14 -> V_52 ) ;
V_29 = F_501 ( V_108 , V_63 , & V_21 , & V_133 ,
sizeof( V_133 ) ) ;
if ( V_29 )
F_150 ( V_108 , V_63 , V_29 ) ;
V_29 = F_502 ( V_108 , V_63 ,
V_21 . V_22 , V_21 . V_33 ) ;
if ( V_29 )
F_150 ( V_108 , V_63 , V_29 ) ;
}
}
int F_503 ( struct V_107 * V_108 ,
struct V_34 * V_35 , T_2 V_294 ,
T_2 type , T_2 V_631 , T_2 V_632 ,
T_2 V_57 )
{
int V_29 ;
struct V_34 * V_63 ;
struct V_1 * V_2 ;
V_63 = V_35 -> V_37 -> V_63 ;
F_504 ( V_35 -> V_37 , V_108 ) ;
V_2 = F_492 ( V_35 , V_632 , V_57 ) ;
if ( ! V_2 )
return - V_72 ;
F_357 ( & V_2 -> V_133 , V_294 ) ;
F_505 ( & V_2 -> V_133 , V_631 ) ;
F_506 ( & V_2 -> V_133 , type ) ;
V_2 -> V_7 = type ;
V_2 -> V_97 = ( T_2 ) - 1 ;
V_2 -> V_3 = V_4 ;
V_29 = F_21 ( V_35 , V_2 ) ;
if ( V_29 ) {
F_19 ( V_35 , V_2 ) ;
F_6 ( V_2 ) ;
return V_29 ;
}
F_27 ( V_2 , V_35 -> V_37 , V_632 ,
V_632 + V_57 ) ;
F_19 ( V_35 , V_2 ) ;
V_29 = F_10 ( V_35 -> V_37 , V_2 ) ;
if ( V_29 ) {
F_484 ( V_2 ) ;
F_6 ( V_2 ) ;
return V_29 ;
}
V_29 = F_254 ( V_35 -> V_37 , V_2 -> V_7 , V_57 , V_294 ,
& V_2 -> V_103 ) ;
if ( V_29 ) {
F_484 ( V_2 ) ;
F_11 ( & V_35 -> V_37 -> V_18 ) ;
F_179 ( & V_2 -> V_20 ,
& V_35 -> V_37 -> V_19 ) ;
F_13 ( & V_35 -> V_37 -> V_18 ) ;
F_6 ( V_2 ) ;
return V_29 ;
}
F_332 ( V_35 -> V_37 ) ;
F_11 ( & V_2 -> V_103 -> V_52 ) ;
V_2 -> V_103 -> V_307 += V_2 -> V_46 ;
F_13 ( & V_2 -> V_103 -> V_52 ) ;
F_488 ( V_2 -> V_103 , V_2 ) ;
F_64 ( & V_2 -> V_626 , & V_108 -> V_252 ) ;
F_260 ( V_63 -> V_37 , type ) ;
return 0 ;
}
static void F_507 ( struct V_12 * V_37 , T_2 V_7 )
{
T_2 V_317 = F_261 ( V_7 ) &
V_318 ;
F_262 ( & V_37 -> V_319 ) ;
if ( V_7 & V_291 )
V_37 -> V_320 &= ~ V_317 ;
if ( V_7 & V_290 )
V_37 -> V_321 &= ~ V_317 ;
if ( V_7 & V_292 )
V_37 -> V_322 &= ~ V_317 ;
F_263 ( & V_37 -> V_319 ) ;
}
int F_508 ( struct V_107 * V_108 ,
struct V_34 * V_35 , T_2 V_633 )
{
struct V_64 * V_65 ;
struct V_1 * V_14 ;
struct V_515 * V_516 ;
struct V_34 * V_87 = V_35 -> V_37 -> V_87 ;
struct V_68 V_21 ;
struct V_269 * V_269 ;
struct V_617 * V_313 = NULL ;
int V_29 ;
int V_527 ;
int V_295 ;
V_35 = V_35 -> V_37 -> V_63 ;
V_14 = F_68 ( V_35 -> V_37 , V_633 ) ;
F_30 ( ! V_14 ) ;
F_30 ( ! V_14 -> V_277 ) ;
F_19 ( V_35 , V_14 ) ;
memcpy ( & V_21 , & V_14 -> V_21 , sizeof( V_21 ) ) ;
V_527 = F_387 ( V_14 ) ;
if ( V_14 -> V_7 & ( V_296 |
V_297 |
V_298 ) )
V_295 = 2 ;
else
V_295 = 1 ;
V_516 = & V_35 -> V_37 -> V_536 ;
F_11 ( & V_516 -> V_519 ) ;
F_400 ( V_14 , V_516 ) ;
F_13 ( & V_516 -> V_519 ) ;
V_516 = & V_35 -> V_37 -> V_534 ;
F_11 ( & V_516 -> V_519 ) ;
F_400 ( V_14 , V_516 ) ;
F_13 ( & V_516 -> V_519 ) ;
V_65 = F_33 () ;
if ( ! V_65 ) {
V_29 = - V_72 ;
goto V_73;
}
V_269 = F_238 ( V_87 , V_14 , V_65 ) ;
if ( ! F_194 ( V_269 ) ) {
V_29 = F_509 ( V_108 , V_269 ) ;
if ( V_29 ) {
F_510 ( V_269 ) ;
goto V_73;
}
F_511 ( V_269 ) ;
F_11 ( & V_14 -> V_52 ) ;
if ( V_14 -> V_162 ) {
V_14 -> V_162 = 0 ;
V_14 -> V_269 = NULL ;
F_13 ( & V_14 -> V_52 ) ;
F_249 ( V_269 ) ;
} else {
F_13 ( & V_14 -> V_52 ) ;
}
F_510 ( V_269 ) ;
}
V_21 . V_22 = V_634 ;
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
F_179 ( & V_14 -> V_20 ,
& V_35 -> V_37 -> V_19 ) ;
if ( V_35 -> V_37 -> V_26 == V_14 -> V_21 . V_22 )
V_35 -> V_37 -> V_26 = ( T_2 ) - 1 ;
F_13 ( & V_35 -> V_37 -> V_18 ) ;
F_63 ( & V_14 -> V_103 -> V_304 ) ;
F_368 ( & V_14 -> V_91 ) ;
if ( F_204 ( & V_14 -> V_103 -> V_303 [ V_527 ] ) ) {
V_313 = V_14 -> V_103 -> V_618 [ V_527 ] ;
V_14 -> V_103 -> V_618 [ V_527 ] = NULL ;
F_507 ( V_35 -> V_37 , V_14 -> V_7 ) ;
}
F_65 ( & V_14 -> V_103 -> V_304 ) ;
if ( V_313 ) {
F_486 ( V_313 ) ;
F_487 ( V_313 ) ;
}
if ( V_14 -> V_3 == V_53 )
F_385 ( V_14 ) ;
F_484 ( V_14 ) ;
F_11 ( & V_14 -> V_103 -> V_52 ) ;
V_14 -> V_103 -> V_293 -= V_14 -> V_21 . V_33 ;
V_14 -> V_103 -> V_307 -= V_14 -> V_21 . V_33 ;
V_14 -> V_103 -> V_299 -= V_14 -> V_21 . V_33 * V_295 ;
F_13 ( & V_14 -> V_103 -> V_52 ) ;
memcpy ( & V_21 , & V_14 -> V_21 , sizeof( V_21 ) ) ;
F_73 ( V_35 -> V_37 ) ;
F_6 ( V_14 ) ;
F_6 ( V_14 ) ;
V_29 = F_37 ( V_108 , V_35 , & V_21 , V_65 , - 1 , 1 ) ;
if ( V_29 > 0 )
V_29 = - V_173 ;
if ( V_29 < 0 )
goto V_73;
V_29 = F_116 ( V_108 , V_35 , V_65 ) ;
V_73:
F_50 ( V_65 ) ;
return V_29 ;
}
int F_512 ( struct V_12 * V_37 )
{
struct V_100 * V_103 ;
struct V_635 * V_636 ;
T_2 V_637 ;
T_2 V_7 ;
int V_638 = 0 ;
int V_29 ;
V_636 = V_37 -> V_361 ;
if ( ! F_513 ( V_636 ) )
return 1 ;
V_637 = F_514 ( V_636 ) ;
if ( V_637 & V_639 )
V_638 = 1 ;
V_7 = V_292 ;
V_29 = F_254 ( V_37 , V_7 , 0 , 0 , & V_103 ) ;
if ( V_29 )
goto V_73;
if ( V_638 ) {
V_7 = V_290 | V_291 ;
V_29 = F_254 ( V_37 , V_7 , 0 , 0 , & V_103 ) ;
} else {
V_7 = V_290 ;
V_29 = F_254 ( V_37 , V_7 , 0 , 0 , & V_103 ) ;
if ( V_29 )
goto V_73;
V_7 = V_291 ;
V_29 = F_254 ( V_37 , V_7 , 0 , 0 , & V_103 ) ;
}
V_73:
return V_29 ;
}
int F_515 ( struct V_34 * V_35 , T_2 V_32 , T_2 V_31 )
{
return F_369 ( V_35 , V_32 , V_31 ) ;
}
int F_516 ( struct V_34 * V_35 , T_2 V_27 ,
T_2 V_36 , T_2 * V_185 )
{
return F_142 ( V_35 , V_27 , V_36 , V_185 ) ;
}
int F_517 ( struct V_34 * V_35 , struct V_640 * V_641 )
{
struct V_12 * V_37 = V_35 -> V_37 ;
struct V_1 * V_2 = NULL ;
T_2 V_642 ;
T_2 V_32 ;
T_2 V_31 ;
T_2 V_643 = 0 ;
T_2 V_293 = F_280 ( V_37 -> V_361 ) ;
int V_29 = 0 ;
if ( V_641 -> V_49 == V_293 )
V_2 = F_67 ( V_37 , V_641 -> V_32 ) ;
else
V_2 = F_68 ( V_37 , V_641 -> V_32 ) ;
while ( V_2 ) {
if ( V_2 -> V_21 . V_22 >= ( V_641 -> V_32 + V_641 -> V_49 ) ) {
F_6 ( V_2 ) ;
break;
}
V_32 = F_396 ( V_641 -> V_32 , V_2 -> V_21 . V_22 ) ;
V_31 = F_298 ( V_641 -> V_32 + V_641 -> V_49 ,
V_2 -> V_21 . V_22 + V_2 -> V_21 . V_33 ) ;
if ( V_31 - V_32 >= V_641 -> V_644 ) {
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
V_29 = F_518 ( V_2 ,
& V_642 ,
V_32 ,
V_31 ,
V_641 -> V_644 ) ;
V_643 += V_642 ;
if ( V_29 ) {
F_6 ( V_2 ) ;
break;
}
}
V_2 = F_236 ( V_37 -> V_87 , V_2 ) ;
}
V_641 -> V_49 = V_643 ;
return V_29 ;
}
void F_519 ( struct V_34 * V_35 )
{
F_520 ( & V_35 -> V_645 -> V_646 ) ;
F_2 () ;
if ( F_521 ( & V_35 -> V_645 -> V_89 ) )
F_49 ( & V_35 -> V_645 -> V_89 ) ;
}
int F_522 ( struct V_34 * V_35 )
{
if ( F_220 ( F_191 ( & V_35 -> V_647 ) ) )
return 0 ;
F_523 ( & V_35 -> V_645 -> V_646 ) ;
F_2 () ;
if ( F_220 ( F_191 ( & V_35 -> V_647 ) ) ) {
F_519 ( V_35 ) ;
return 0 ;
}
return 1 ;
}
