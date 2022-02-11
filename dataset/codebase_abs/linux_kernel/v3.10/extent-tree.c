static T_1 int
F_1 ( struct V_1 * V_2 )
{
F_2 () ;
return V_2 -> V_3 == V_4 ;
}
static int F_3 ( struct V_1 * V_2 , T_2 V_5 )
{
return ( V_2 -> V_6 & V_5 ) == V_5 ;
}
static void F_4 ( struct V_1 * V_2 )
{
F_5 ( & V_2 -> V_7 ) ;
}
void F_6 ( struct V_1 * V_2 )
{
if ( F_7 ( & V_2 -> V_7 ) ) {
F_8 ( V_2 -> V_8 > 0 ) ;
F_8 ( V_2 -> V_9 > 0 ) ;
F_9 ( V_2 -> V_10 ) ;
F_9 ( V_2 ) ;
}
}
static int F_10 ( struct V_11 * V_12 ,
struct V_1 * V_13 )
{
struct V_14 * * V_15 ;
struct V_14 * V_16 = NULL ;
struct V_1 * V_2 ;
F_11 ( & V_12 -> V_17 ) ;
V_15 = & V_12 -> V_18 . V_14 ;
while ( * V_15 ) {
V_16 = * V_15 ;
V_2 = F_12 ( V_16 , struct V_1 ,
V_19 ) ;
if ( V_13 -> V_20 . V_21 < V_2 -> V_20 . V_21 ) {
V_15 = & ( * V_15 ) -> V_22 ;
} else if ( V_13 -> V_20 . V_21 > V_2 -> V_20 . V_21 ) {
V_15 = & ( * V_15 ) -> V_23 ;
} else {
F_13 ( & V_12 -> V_17 ) ;
return - V_24 ;
}
}
F_14 ( & V_13 -> V_19 , V_16 , V_15 ) ;
F_15 ( & V_13 -> V_19 ,
& V_12 -> V_18 ) ;
if ( V_12 -> V_25 > V_13 -> V_20 . V_21 )
V_12 -> V_25 = V_13 -> V_20 . V_21 ;
F_13 ( & V_12 -> V_17 ) ;
return 0 ;
}
static struct V_1 *
F_16 ( struct V_11 * V_12 , T_2 V_26 ,
int V_27 )
{
struct V_1 * V_2 , * V_28 = NULL ;
struct V_14 * V_29 ;
T_2 V_30 , V_31 ;
F_11 ( & V_12 -> V_17 ) ;
V_29 = V_12 -> V_18 . V_14 ;
while ( V_29 ) {
V_2 = F_12 ( V_29 , struct V_1 ,
V_19 ) ;
V_30 = V_2 -> V_20 . V_21 + V_2 -> V_20 . V_32 - 1 ;
V_31 = V_2 -> V_20 . V_21 ;
if ( V_26 < V_31 ) {
if ( ! V_27 && ( ! V_28 || V_31 < V_28 -> V_20 . V_21 ) )
V_28 = V_2 ;
V_29 = V_29 -> V_22 ;
} else if ( V_26 > V_31 ) {
if ( V_27 && V_26 <= V_30 ) {
V_28 = V_2 ;
break;
}
V_29 = V_29 -> V_23 ;
} else {
V_28 = V_2 ;
break;
}
}
if ( V_28 ) {
F_4 ( V_28 ) ;
if ( V_26 == 0 && V_12 -> V_25 > V_28 -> V_20 . V_21 )
V_12 -> V_25 = V_28 -> V_20 . V_21 ;
}
F_13 ( & V_12 -> V_17 ) ;
return V_28 ;
}
static int F_17 ( struct V_33 * V_34 ,
T_2 V_31 , T_2 V_35 )
{
T_2 V_30 = V_31 + V_35 - 1 ;
F_18 ( & V_34 -> V_36 -> V_37 [ 0 ] ,
V_31 , V_30 , V_38 , V_39 ) ;
F_18 ( & V_34 -> V_36 -> V_37 [ 1 ] ,
V_31 , V_30 , V_38 , V_39 ) ;
return 0 ;
}
static void F_19 ( struct V_33 * V_34 ,
struct V_1 * V_2 )
{
T_2 V_31 , V_30 ;
V_31 = V_2 -> V_20 . V_21 ;
V_30 = V_31 + V_2 -> V_20 . V_32 - 1 ;
F_20 ( & V_34 -> V_36 -> V_37 [ 0 ] ,
V_31 , V_30 , V_38 , V_39 ) ;
F_20 ( & V_34 -> V_36 -> V_37 [ 1 ] ,
V_31 , V_30 , V_38 , V_39 ) ;
}
static int F_21 ( struct V_33 * V_34 ,
struct V_1 * V_2 )
{
T_2 V_26 ;
T_2 * V_40 ;
int V_41 ;
int V_42 , V_43 , V_28 ;
if ( V_2 -> V_20 . V_21 < V_44 ) {
V_41 = V_44 - V_2 -> V_20 . V_21 ;
V_2 -> V_45 += V_41 ;
V_28 = F_17 ( V_34 , V_2 -> V_20 . V_21 ,
V_41 ) ;
if ( V_28 )
return V_28 ;
}
for ( V_42 = 0 ; V_42 < V_46 ; V_42 ++ ) {
V_26 = F_22 ( V_42 ) ;
V_28 = F_23 ( & V_34 -> V_36 -> V_47 ,
V_2 -> V_20 . V_21 , V_26 ,
0 , & V_40 , & V_43 , & V_41 ) ;
if ( V_28 )
return V_28 ;
while ( V_43 -- ) {
T_2 V_31 , V_48 ;
if ( V_40 [ V_43 ] > V_2 -> V_20 . V_21 +
V_2 -> V_20 . V_32 )
continue;
if ( V_40 [ V_43 ] + V_41 <= V_2 -> V_20 . V_21 )
continue;
V_31 = V_40 [ V_43 ] ;
if ( V_31 < V_2 -> V_20 . V_21 ) {
V_31 = V_2 -> V_20 . V_21 ;
V_48 = ( V_40 [ V_43 ] + V_41 ) - V_31 ;
} else {
V_48 = F_24 ( T_2 , V_41 ,
V_2 -> V_20 . V_21 +
V_2 -> V_20 . V_32 - V_31 ) ;
}
V_2 -> V_45 += V_48 ;
V_28 = F_17 ( V_34 , V_31 , V_48 ) ;
if ( V_28 ) {
F_9 ( V_40 ) ;
return V_28 ;
}
}
F_9 ( V_40 ) ;
}
return 0 ;
}
static struct V_49 *
F_25 ( struct V_1 * V_2 )
{
struct V_49 * V_50 ;
F_11 ( & V_2 -> V_51 ) ;
if ( V_2 -> V_3 != V_52 ) {
F_13 ( & V_2 -> V_51 ) ;
return NULL ;
}
if ( ! V_2 -> V_53 ) {
F_13 ( & V_2 -> V_51 ) ;
return NULL ;
}
V_50 = V_2 -> V_53 ;
F_5 ( & V_50 -> V_7 ) ;
F_13 ( & V_2 -> V_51 ) ;
return V_50 ;
}
static void F_26 ( struct V_49 * V_50 )
{
if ( F_7 ( & V_50 -> V_7 ) )
F_9 ( V_50 ) ;
}
static T_2 F_27 ( struct V_1 * V_13 ,
struct V_11 * V_12 , T_2 V_31 , T_2 V_30 )
{
T_2 V_54 , V_55 , V_56 , V_57 = 0 ;
int V_28 ;
while ( V_31 < V_30 ) {
V_28 = F_28 ( V_12 -> V_58 , V_31 ,
& V_54 , & V_55 ,
V_59 | V_38 ,
NULL ) ;
if ( V_28 )
break;
if ( V_54 <= V_31 ) {
V_31 = V_55 + 1 ;
} else if ( V_54 > V_31 && V_54 < V_30 ) {
V_56 = V_54 - V_31 ;
V_57 += V_56 ;
V_28 = F_29 ( V_13 , V_31 ,
V_56 ) ;
F_30 ( V_28 ) ;
V_31 = V_55 + 1 ;
} else {
break;
}
}
if ( V_31 < V_30 ) {
V_56 = V_30 - V_31 ;
V_57 += V_56 ;
V_28 = F_29 ( V_13 , V_31 , V_56 ) ;
F_30 ( V_28 ) ;
}
return V_57 ;
}
static T_1 void F_31 ( struct V_60 * V_61 )
{
struct V_1 * V_13 ;
struct V_11 * V_36 ;
struct V_49 * V_53 ;
struct V_33 * V_62 ;
struct V_63 * V_64 ;
struct V_65 * V_66 ;
struct V_67 V_20 ;
T_2 V_68 = 0 ;
T_2 V_69 = 0 ;
T_3 V_70 ;
int V_28 = 0 ;
V_53 = F_32 ( V_61 , struct V_49 , V_61 ) ;
V_13 = V_53 -> V_13 ;
V_36 = V_13 -> V_36 ;
V_62 = V_36 -> V_62 ;
V_64 = F_33 () ;
if ( ! V_64 )
goto V_71;
V_69 = F_34 ( T_2 , V_13 -> V_20 . V_21 , V_44 ) ;
V_64 -> V_72 = 1 ;
V_64 -> V_73 = 1 ;
V_64 -> V_74 = 1 ;
V_20 . V_21 = V_69 ;
V_20 . V_32 = 0 ;
V_20 . type = V_75 ;
V_76:
F_35 ( & V_53 -> V_77 ) ;
F_36 ( & V_36 -> V_78 ) ;
V_28 = F_37 ( NULL , V_62 , & V_20 , V_64 , 0 , 0 ) ;
if ( V_28 < 0 )
goto V_79;
V_66 = V_64 -> V_80 [ 0 ] ;
V_70 = F_38 ( V_66 ) ;
while ( 1 ) {
if ( F_39 ( V_36 ) > 1 ) {
V_69 = ( T_2 ) - 1 ;
break;
}
if ( V_64 -> V_81 [ 0 ] < V_70 ) {
F_40 ( V_66 , & V_20 , V_64 -> V_81 [ 0 ] ) ;
} else {
V_28 = F_41 ( V_64 , 0 , & V_20 ) ;
if ( V_28 )
break;
if ( F_42 () ) {
V_53 -> V_82 = V_69 ;
F_43 ( V_64 ) ;
F_44 ( & V_36 -> V_78 ) ;
F_45 ( & V_53 -> V_77 ) ;
F_46 () ;
goto V_76;
}
V_28 = F_47 ( V_62 , V_64 ) ;
if ( V_28 < 0 )
goto V_79;
if ( V_28 )
break;
V_66 = V_64 -> V_80 [ 0 ] ;
V_70 = F_38 ( V_66 ) ;
continue;
}
if ( V_20 . V_21 < V_13 -> V_20 . V_21 ) {
V_64 -> V_81 [ 0 ] ++ ;
continue;
}
if ( V_20 . V_21 >= V_13 -> V_20 . V_21 +
V_13 -> V_20 . V_32 )
break;
if ( V_20 . type == V_75 ||
V_20 . type == V_83 ) {
V_68 += F_27 ( V_13 ,
V_36 , V_69 ,
V_20 . V_21 ) ;
if ( V_20 . type == V_83 )
V_69 = V_20 . V_21 +
V_36 -> V_84 -> V_85 ;
else
V_69 = V_20 . V_21 + V_20 . V_32 ;
if ( V_68 > ( 1024 * 1024 * 2 ) ) {
V_68 = 0 ;
F_48 ( & V_53 -> V_86 ) ;
}
}
V_64 -> V_81 [ 0 ] ++ ;
}
V_28 = 0 ;
V_68 += F_27 ( V_13 , V_36 , V_69 ,
V_13 -> V_20 . V_21 +
V_13 -> V_20 . V_32 ) ;
V_53 -> V_82 = ( T_2 ) - 1 ;
F_11 ( & V_13 -> V_51 ) ;
V_13 -> V_53 = NULL ;
V_13 -> V_3 = V_4 ;
F_13 ( & V_13 -> V_51 ) ;
V_79:
F_49 ( V_64 ) ;
F_44 ( & V_36 -> V_78 ) ;
F_19 ( V_62 , V_13 ) ;
F_45 ( & V_53 -> V_77 ) ;
V_71:
F_48 ( & V_53 -> V_86 ) ;
F_26 ( V_53 ) ;
F_6 ( V_13 ) ;
}
static int F_50 ( struct V_1 * V_2 ,
int V_87 )
{
F_51 ( V_86 ) ;
struct V_11 * V_36 = V_2 -> V_36 ;
struct V_49 * V_53 ;
int V_28 = 0 ;
V_53 = F_52 ( sizeof( * V_53 ) , V_39 ) ;
if ( ! V_53 )
return - V_88 ;
F_53 ( & V_53 -> V_89 ) ;
F_54 ( & V_53 -> V_77 ) ;
F_55 ( & V_53 -> V_86 ) ;
V_53 -> V_13 = V_2 ;
V_53 -> V_82 = V_2 -> V_20 . V_21 ;
F_56 ( & V_53 -> V_7 , 1 ) ;
V_53 -> V_61 . V_90 = F_31 ;
F_11 ( & V_2 -> V_51 ) ;
while ( V_2 -> V_3 == V_91 ) {
struct V_49 * V_50 ;
V_50 = V_2 -> V_53 ;
F_5 ( & V_50 -> V_7 ) ;
F_57 ( & V_50 -> V_86 , & V_86 , V_92 ) ;
F_13 ( & V_2 -> V_51 ) ;
F_58 () ;
F_59 ( & V_50 -> V_86 , & V_86 ) ;
F_26 ( V_50 ) ;
F_11 ( & V_2 -> V_51 ) ;
}
if ( V_2 -> V_3 != V_93 ) {
F_13 ( & V_2 -> V_51 ) ;
F_9 ( V_53 ) ;
return 0 ;
}
F_8 ( V_2 -> V_53 ) ;
V_2 -> V_53 = V_53 ;
V_2 -> V_3 = V_91 ;
F_13 ( & V_2 -> V_51 ) ;
if ( V_36 -> V_94 & V_95 ) {
V_28 = F_60 ( V_36 , V_2 ) ;
F_11 ( & V_2 -> V_51 ) ;
if ( V_28 == 1 ) {
V_2 -> V_53 = NULL ;
V_2 -> V_3 = V_4 ;
V_2 -> V_96 = ( T_2 ) - 1 ;
} else {
if ( V_87 ) {
V_2 -> V_53 = NULL ;
V_2 -> V_3 = V_93 ;
} else {
V_2 -> V_3 = V_52 ;
}
}
F_13 ( & V_2 -> V_51 ) ;
F_48 ( & V_53 -> V_86 ) ;
if ( V_28 == 1 ) {
F_26 ( V_53 ) ;
F_19 ( V_36 -> V_62 , V_2 ) ;
return 0 ;
}
} else {
F_11 ( & V_2 -> V_51 ) ;
if ( V_87 ) {
V_2 -> V_53 = NULL ;
V_2 -> V_3 = V_93 ;
} else {
V_2 -> V_3 = V_52 ;
}
F_13 ( & V_2 -> V_51 ) ;
F_48 ( & V_53 -> V_86 ) ;
}
if ( V_87 ) {
F_26 ( V_53 ) ;
return 0 ;
}
F_61 ( & V_36 -> V_78 ) ;
F_5 ( & V_53 -> V_7 ) ;
F_62 ( & V_53 -> V_89 , & V_36 -> V_97 ) ;
F_63 ( & V_36 -> V_78 ) ;
F_4 ( V_2 ) ;
F_64 ( & V_36 -> V_98 , & V_53 -> V_61 ) ;
return V_28 ;
}
static struct V_1 *
F_65 ( struct V_11 * V_12 , T_2 V_26 )
{
struct V_1 * V_2 ;
V_2 = F_16 ( V_12 , V_26 , 0 ) ;
return V_2 ;
}
struct V_1 * F_66 (
struct V_11 * V_12 ,
T_2 V_26 )
{
struct V_1 * V_2 ;
V_2 = F_16 ( V_12 , V_26 , 1 ) ;
return V_2 ;
}
static struct V_99 * F_67 ( struct V_11 * V_12 ,
T_2 V_6 )
{
struct V_100 * V_101 = & V_12 -> V_102 ;
struct V_99 * V_103 ;
V_6 &= V_104 ;
F_68 () ;
F_69 (found, head, list) {
if ( V_103 -> V_6 & V_6 ) {
F_70 () ;
return V_103 ;
}
}
F_70 () ;
return NULL ;
}
void F_71 ( struct V_11 * V_12 )
{
struct V_100 * V_101 = & V_12 -> V_102 ;
struct V_99 * V_103 ;
F_68 () ;
F_69 (found, head, list)
V_103 -> V_105 = 0 ;
F_70 () ;
}
int F_72 ( struct V_33 * V_34 , T_2 V_31 , T_2 V_48 )
{
int V_28 ;
struct V_67 V_20 ;
struct V_63 * V_64 ;
V_64 = F_33 () ;
if ( ! V_64 )
return - V_88 ;
V_20 . V_21 = V_31 ;
V_20 . V_32 = V_48 ;
V_20 . type = V_75 ;
V_28 = F_37 ( NULL , V_34 -> V_36 -> V_62 , & V_20 , V_64 ,
0 , 0 ) ;
if ( V_28 > 0 ) {
F_40 ( V_64 -> V_80 [ 0 ] , & V_20 , V_64 -> V_81 [ 0 ] ) ;
if ( V_20 . V_21 == V_31 &&
V_20 . type == V_83 )
V_28 = 0 ;
}
F_49 ( V_64 ) ;
return V_28 ;
}
int F_73 ( struct V_106 * V_107 ,
struct V_33 * V_34 , T_2 V_26 ,
T_2 V_32 , int V_108 , T_2 * V_109 , T_2 * V_6 )
{
struct V_110 * V_101 ;
struct V_111 * V_112 ;
struct V_63 * V_64 ;
struct V_113 * V_114 ;
struct V_65 * V_66 ;
struct V_67 V_20 ;
T_3 V_115 ;
T_2 V_116 ;
T_2 V_117 ;
int V_28 ;
if ( V_108 && ! F_74 ( V_34 -> V_36 , V_118 ) ) {
V_32 = V_34 -> V_85 ;
V_108 = 0 ;
}
V_64 = F_33 () ;
if ( ! V_64 )
return - V_88 ;
if ( V_108 ) {
V_20 . V_21 = V_26 ;
V_20 . type = V_83 ;
V_20 . V_32 = V_32 ;
} else {
V_20 . V_21 = V_26 ;
V_20 . type = V_75 ;
V_20 . V_32 = V_32 ;
}
if ( ! V_107 ) {
V_64 -> V_72 = 1 ;
V_64 -> V_73 = 1 ;
}
V_76:
V_28 = F_37 ( V_107 , V_34 -> V_36 -> V_62 ,
& V_20 , V_64 , 0 , 0 ) ;
if ( V_28 < 0 )
goto V_119;
if ( V_28 > 0 && V_108 && V_20 . type == V_83 ) {
V_20 . type = V_75 ;
V_20 . V_32 = V_34 -> V_85 ;
F_43 ( V_64 ) ;
goto V_76;
}
if ( V_28 == 0 ) {
V_66 = V_64 -> V_80 [ 0 ] ;
V_115 = F_75 ( V_66 , V_64 -> V_81 [ 0 ] ) ;
if ( V_115 >= sizeof( * V_114 ) ) {
V_114 = F_76 ( V_66 , V_64 -> V_81 [ 0 ] ,
struct V_113 ) ;
V_116 = F_77 ( V_66 , V_114 ) ;
V_117 = F_78 ( V_66 , V_114 ) ;
} else {
#ifdef F_79
struct V_120 * V_121 ;
F_30 ( V_115 != sizeof( * V_121 ) ) ;
V_121 = F_76 ( V_66 , V_64 -> V_81 [ 0 ] ,
struct V_120 ) ;
V_116 = F_80 ( V_66 , V_121 ) ;
V_117 = V_122 ;
#else
F_81 () ;
#endif
}
F_30 ( V_116 == 0 ) ;
} else {
V_116 = 0 ;
V_117 = 0 ;
V_28 = 0 ;
}
if ( ! V_107 )
goto V_71;
V_112 = & V_107 -> V_123 -> V_112 ;
F_11 ( & V_112 -> V_51 ) ;
V_101 = F_82 ( V_107 , V_26 ) ;
if ( V_101 ) {
if ( ! F_83 ( & V_101 -> V_77 ) ) {
F_5 ( & V_101 -> V_124 . V_109 ) ;
F_13 ( & V_112 -> V_51 ) ;
F_43 ( V_64 ) ;
F_35 ( & V_101 -> V_77 ) ;
F_45 ( & V_101 -> V_77 ) ;
F_84 ( & V_101 -> V_124 ) ;
goto V_76;
}
if ( V_101 -> V_125 && V_101 -> V_125 -> V_126 )
V_117 |= V_101 -> V_125 -> V_127 ;
else
F_30 ( V_116 == 0 ) ;
V_116 += V_101 -> V_124 . V_128 ;
F_45 ( & V_101 -> V_77 ) ;
}
F_13 ( & V_112 -> V_51 ) ;
V_71:
F_8 ( V_116 == 0 ) ;
if ( V_109 )
* V_109 = V_116 ;
if ( V_6 )
* V_6 = V_117 ;
V_119:
F_49 ( V_64 ) ;
return V_28 ;
}
static int F_85 ( struct V_106 * V_107 ,
struct V_33 * V_34 ,
struct V_63 * V_64 ,
T_2 V_129 , T_3 V_130 )
{
struct V_113 * V_131 ;
struct V_120 * V_121 ;
struct V_132 * V_133 ;
struct V_134 * V_135 ;
struct V_65 * V_66 ;
struct V_67 V_20 ;
struct V_67 V_136 ;
T_3 V_137 = sizeof( * V_131 ) ;
T_2 V_109 ;
int V_28 ;
V_66 = V_64 -> V_80 [ 0 ] ;
F_30 ( F_75 ( V_66 , V_64 -> V_81 [ 0 ] ) != sizeof( * V_121 ) ) ;
F_40 ( V_66 , & V_20 , V_64 -> V_81 [ 0 ] ) ;
V_121 = F_76 ( V_66 , V_64 -> V_81 [ 0 ] ,
struct V_120 ) ;
V_109 = F_80 ( V_66 , V_121 ) ;
if ( V_129 == ( T_2 ) - 1 ) {
while ( 1 ) {
if ( V_64 -> V_81 [ 0 ] >= F_38 ( V_66 ) ) {
V_28 = F_47 ( V_34 , V_64 ) ;
if ( V_28 < 0 )
return V_28 ;
F_30 ( V_28 > 0 ) ;
V_66 = V_64 -> V_80 [ 0 ] ;
}
F_40 ( V_66 , & V_136 ,
V_64 -> V_81 [ 0 ] ) ;
F_30 ( V_20 . V_21 != V_136 . V_21 ) ;
if ( V_136 . type != V_138 ) {
V_64 -> V_81 [ 0 ] ++ ;
continue;
}
V_133 = F_76 ( V_66 , V_64 -> V_81 [ 0 ] ,
struct V_132 ) ;
V_129 = F_86 ( V_66 , V_133 ) ;
break;
}
}
F_43 ( V_64 ) ;
if ( V_129 < V_139 )
V_137 += sizeof( * V_135 ) ;
V_137 -= sizeof( * V_121 ) ;
V_28 = F_37 ( V_107 , V_34 , & V_20 , V_64 ,
V_137 + V_130 , 1 ) ;
if ( V_28 < 0 )
return V_28 ;
F_30 ( V_28 ) ;
F_87 ( V_34 , V_64 , V_137 ) ;
V_66 = V_64 -> V_80 [ 0 ] ;
V_131 = F_76 ( V_66 , V_64 -> V_81 [ 0 ] , struct V_113 ) ;
F_88 ( V_66 , V_131 , V_109 ) ;
F_89 ( V_66 , V_131 , 0 ) ;
if ( V_129 < V_139 ) {
F_90 ( V_66 , V_131 ,
V_140 |
V_122 ) ;
V_135 = (struct V_134 * ) ( V_131 + 1 ) ;
F_91 ( V_66 , 0 , ( unsigned long ) V_135 , sizeof( * V_135 ) ) ;
F_92 ( V_66 , V_135 , ( int ) V_129 ) ;
} else {
F_90 ( V_66 , V_131 , V_141 ) ;
}
F_93 ( V_66 ) ;
return 0 ;
}
static T_2 F_94 ( T_2 V_142 , T_2 V_129 , T_2 V_32 )
{
T_3 V_143 = ~ ( T_3 ) 0 ;
T_3 V_144 = ~ ( T_3 ) 0 ;
T_4 V_145 ;
V_145 = F_95 ( V_142 ) ;
V_143 = F_96 ( V_143 , & V_145 , sizeof( V_145 ) ) ;
V_145 = F_95 ( V_129 ) ;
V_144 = F_96 ( V_144 , & V_145 , sizeof( V_145 ) ) ;
V_145 = F_95 ( V_32 ) ;
V_144 = F_96 ( V_144 , & V_145 , sizeof( V_145 ) ) ;
return ( ( T_2 ) V_143 << 31 ) ^ ( T_2 ) V_144 ;
}
static T_2 F_97 ( struct V_65 * V_66 ,
struct V_146 * V_147 )
{
return F_94 ( F_98 ( V_66 , V_147 ) ,
F_99 ( V_66 , V_147 ) ,
F_100 ( V_66 , V_147 ) ) ;
}
static int F_101 ( struct V_65 * V_66 ,
struct V_146 * V_147 ,
T_2 V_142 , T_2 V_129 , T_2 V_32 )
{
if ( F_98 ( V_66 , V_147 ) != V_142 ||
F_99 ( V_66 , V_147 ) != V_129 ||
F_100 ( V_66 , V_147 ) != V_32 )
return 0 ;
return 1 ;
}
static T_1 int F_102 ( struct V_106 * V_107 ,
struct V_33 * V_34 ,
struct V_63 * V_64 ,
T_2 V_26 , T_2 V_16 ,
T_2 V_142 ,
T_2 V_129 , T_2 V_32 )
{
struct V_67 V_20 ;
struct V_146 * V_147 ;
struct V_65 * V_66 ;
T_3 V_70 ;
int V_28 ;
int V_148 ;
int V_79 = - V_149 ;
V_20 . V_21 = V_26 ;
if ( V_16 ) {
V_20 . type = V_150 ;
V_20 . V_32 = V_16 ;
} else {
V_20 . type = V_151 ;
V_20 . V_32 = F_94 ( V_142 ,
V_129 , V_32 ) ;
}
V_76:
V_148 = 0 ;
V_28 = F_37 ( V_107 , V_34 , & V_20 , V_64 , - 1 , 1 ) ;
if ( V_28 < 0 ) {
V_79 = V_28 ;
goto V_152;
}
if ( V_16 ) {
if ( ! V_28 )
return 0 ;
#ifdef F_79
V_20 . type = V_138 ;
F_43 ( V_64 ) ;
V_28 = F_37 ( V_107 , V_34 , & V_20 , V_64 , - 1 , 1 ) ;
if ( V_28 < 0 ) {
V_79 = V_28 ;
goto V_152;
}
if ( ! V_28 )
return 0 ;
#endif
goto V_152;
}
V_66 = V_64 -> V_80 [ 0 ] ;
V_70 = F_38 ( V_66 ) ;
while ( 1 ) {
if ( V_64 -> V_81 [ 0 ] >= V_70 ) {
V_28 = F_47 ( V_34 , V_64 ) ;
if ( V_28 < 0 )
V_79 = V_28 ;
if ( V_28 )
goto V_152;
V_66 = V_64 -> V_80 [ 0 ] ;
V_70 = F_38 ( V_66 ) ;
V_148 = 1 ;
}
F_40 ( V_66 , & V_20 , V_64 -> V_81 [ 0 ] ) ;
if ( V_20 . V_21 != V_26 ||
V_20 . type != V_151 )
goto V_152;
V_147 = F_76 ( V_66 , V_64 -> V_81 [ 0 ] ,
struct V_146 ) ;
if ( F_101 ( V_66 , V_147 , V_142 ,
V_129 , V_32 ) ) {
if ( V_148 ) {
F_43 ( V_64 ) ;
goto V_76;
}
V_79 = 0 ;
break;
}
V_64 -> V_81 [ 0 ] ++ ;
}
V_152:
return V_79 ;
}
static T_1 int F_103 ( struct V_106 * V_107 ,
struct V_33 * V_34 ,
struct V_63 * V_64 ,
T_2 V_26 , T_2 V_16 ,
T_2 V_142 , T_2 V_129 ,
T_2 V_32 , int V_153 )
{
struct V_67 V_20 ;
struct V_65 * V_66 ;
T_3 V_56 ;
T_3 V_116 ;
int V_28 ;
V_20 . V_21 = V_26 ;
if ( V_16 ) {
V_20 . type = V_150 ;
V_20 . V_32 = V_16 ;
V_56 = sizeof( struct V_154 ) ;
} else {
V_20 . type = V_151 ;
V_20 . V_32 = F_94 ( V_142 ,
V_129 , V_32 ) ;
V_56 = sizeof( struct V_146 ) ;
}
V_28 = F_104 ( V_107 , V_34 , V_64 , & V_20 , V_56 ) ;
if ( V_28 && V_28 != - V_24 )
goto V_152;
V_66 = V_64 -> V_80 [ 0 ] ;
if ( V_16 ) {
struct V_154 * V_147 ;
V_147 = F_76 ( V_66 , V_64 -> V_81 [ 0 ] ,
struct V_154 ) ;
if ( V_28 == 0 ) {
F_105 ( V_66 , V_147 , V_153 ) ;
} else {
V_116 = F_106 ( V_66 , V_147 ) ;
V_116 += V_153 ;
F_105 ( V_66 , V_147 , V_116 ) ;
}
} else {
struct V_146 * V_147 ;
while ( V_28 == - V_24 ) {
V_147 = F_76 ( V_66 , V_64 -> V_81 [ 0 ] ,
struct V_146 ) ;
if ( F_101 ( V_66 , V_147 , V_142 ,
V_129 , V_32 ) )
break;
F_43 ( V_64 ) ;
V_20 . V_32 ++ ;
V_28 = F_104 ( V_107 , V_34 , V_64 , & V_20 ,
V_56 ) ;
if ( V_28 && V_28 != - V_24 )
goto V_152;
V_66 = V_64 -> V_80 [ 0 ] ;
}
V_147 = F_76 ( V_66 , V_64 -> V_81 [ 0 ] ,
struct V_146 ) ;
if ( V_28 == 0 ) {
F_107 ( V_66 , V_147 ,
V_142 ) ;
F_108 ( V_66 , V_147 , V_129 ) ;
F_109 ( V_66 , V_147 , V_32 ) ;
F_110 ( V_66 , V_147 , V_153 ) ;
} else {
V_116 = F_111 ( V_66 , V_147 ) ;
V_116 += V_153 ;
F_110 ( V_66 , V_147 , V_116 ) ;
}
}
F_93 ( V_66 ) ;
V_28 = 0 ;
V_152:
F_43 ( V_64 ) ;
return V_28 ;
}
static T_1 int F_112 ( struct V_106 * V_107 ,
struct V_33 * V_34 ,
struct V_63 * V_64 ,
int V_155 )
{
struct V_67 V_20 ;
struct V_146 * V_156 = NULL ;
struct V_154 * V_157 = NULL ;
struct V_65 * V_66 ;
T_3 V_116 = 0 ;
int V_28 = 0 ;
V_66 = V_64 -> V_80 [ 0 ] ;
F_40 ( V_66 , & V_20 , V_64 -> V_81 [ 0 ] ) ;
if ( V_20 . type == V_151 ) {
V_156 = F_76 ( V_66 , V_64 -> V_81 [ 0 ] ,
struct V_146 ) ;
V_116 = F_111 ( V_66 , V_156 ) ;
} else if ( V_20 . type == V_150 ) {
V_157 = F_76 ( V_66 , V_64 -> V_81 [ 0 ] ,
struct V_154 ) ;
V_116 = F_106 ( V_66 , V_157 ) ;
#ifdef F_79
} else if ( V_20 . type == V_138 ) {
struct V_132 * V_133 ;
V_133 = F_76 ( V_66 , V_64 -> V_81 [ 0 ] ,
struct V_132 ) ;
V_116 = F_113 ( V_66 , V_133 ) ;
#endif
} else {
F_81 () ;
}
F_30 ( V_116 < V_155 ) ;
V_116 -= V_155 ;
if ( V_116 == 0 ) {
V_28 = F_114 ( V_107 , V_34 , V_64 ) ;
} else {
if ( V_20 . type == V_151 )
F_110 ( V_66 , V_156 , V_116 ) ;
else if ( V_20 . type == V_150 )
F_105 ( V_66 , V_157 , V_116 ) ;
#ifdef F_79
else {
struct V_132 * V_133 ;
V_133 = F_76 ( V_66 , V_64 -> V_81 [ 0 ] ,
struct V_132 ) ;
F_115 ( V_66 , V_133 , V_116 ) ;
}
#endif
F_93 ( V_66 ) ;
}
return V_28 ;
}
static T_1 T_3 F_116 ( struct V_33 * V_34 ,
struct V_63 * V_64 ,
struct V_158 * V_159 )
{
struct V_67 V_20 ;
struct V_65 * V_66 ;
struct V_146 * V_156 ;
struct V_154 * V_157 ;
T_3 V_116 = 0 ;
V_66 = V_64 -> V_80 [ 0 ] ;
F_40 ( V_66 , & V_20 , V_64 -> V_81 [ 0 ] ) ;
if ( V_159 ) {
if ( F_117 ( V_66 , V_159 ) ==
V_151 ) {
V_156 = (struct V_146 * ) ( & V_159 -> V_32 ) ;
V_116 = F_111 ( V_66 , V_156 ) ;
} else {
V_157 = (struct V_154 * ) ( V_159 + 1 ) ;
V_116 = F_106 ( V_66 , V_157 ) ;
}
} else if ( V_20 . type == V_151 ) {
V_156 = F_76 ( V_66 , V_64 -> V_81 [ 0 ] ,
struct V_146 ) ;
V_116 = F_111 ( V_66 , V_156 ) ;
} else if ( V_20 . type == V_150 ) {
V_157 = F_76 ( V_66 , V_64 -> V_81 [ 0 ] ,
struct V_154 ) ;
V_116 = F_106 ( V_66 , V_157 ) ;
#ifdef F_79
} else if ( V_20 . type == V_138 ) {
struct V_132 * V_133 ;
V_133 = F_76 ( V_66 , V_64 -> V_81 [ 0 ] ,
struct V_132 ) ;
V_116 = F_113 ( V_66 , V_133 ) ;
#endif
} else {
F_8 ( 1 ) ;
}
return V_116 ;
}
static T_1 int F_118 ( struct V_106 * V_107 ,
struct V_33 * V_34 ,
struct V_63 * V_64 ,
T_2 V_26 , T_2 V_16 ,
T_2 V_142 )
{
struct V_67 V_20 ;
int V_28 ;
V_20 . V_21 = V_26 ;
if ( V_16 ) {
V_20 . type = V_160 ;
V_20 . V_32 = V_16 ;
} else {
V_20 . type = V_161 ;
V_20 . V_32 = V_142 ;
}
V_28 = F_37 ( V_107 , V_34 , & V_20 , V_64 , - 1 , 1 ) ;
if ( V_28 > 0 )
V_28 = - V_149 ;
#ifdef F_79
if ( V_28 == - V_149 && V_16 ) {
F_43 ( V_64 ) ;
V_20 . type = V_138 ;
V_28 = F_37 ( V_107 , V_34 , & V_20 , V_64 , - 1 , 1 ) ;
if ( V_28 > 0 )
V_28 = - V_149 ;
}
#endif
return V_28 ;
}
static T_1 int F_119 ( struct V_106 * V_107 ,
struct V_33 * V_34 ,
struct V_63 * V_64 ,
T_2 V_26 , T_2 V_16 ,
T_2 V_142 )
{
struct V_67 V_20 ;
int V_28 ;
V_20 . V_21 = V_26 ;
if ( V_16 ) {
V_20 . type = V_160 ;
V_20 . V_32 = V_16 ;
} else {
V_20 . type = V_161 ;
V_20 . V_32 = V_142 ;
}
V_28 = F_104 ( V_107 , V_34 , V_64 , & V_20 , 0 ) ;
F_43 ( V_64 ) ;
return V_28 ;
}
static inline int F_120 ( T_2 V_16 , T_2 V_129 )
{
int type ;
if ( V_129 < V_139 ) {
if ( V_16 > 0 )
type = V_160 ;
else
type = V_161 ;
} else {
if ( V_16 > 0 )
type = V_150 ;
else
type = V_151 ;
}
return type ;
}
static int F_41 ( struct V_63 * V_64 , int V_162 ,
struct V_67 * V_20 )
{
for (; V_162 < V_163 ; V_162 ++ ) {
if ( ! V_64 -> V_80 [ V_162 ] )
break;
if ( V_64 -> V_81 [ V_162 ] + 1 >=
F_38 ( V_64 -> V_80 [ V_162 ] ) )
continue;
if ( V_162 == 0 )
F_40 ( V_64 -> V_80 [ V_162 ] , V_20 ,
V_64 -> V_81 [ V_162 ] + 1 ) ;
else
F_121 ( V_64 -> V_80 [ V_162 ] , V_20 ,
V_64 -> V_81 [ V_162 ] + 1 ) ;
return 0 ;
}
return 1 ;
}
static T_5
int F_122 ( struct V_106 * V_107 ,
struct V_33 * V_34 ,
struct V_63 * V_64 ,
struct V_158 * * V_164 ,
T_2 V_26 , T_2 V_35 ,
T_2 V_16 , T_2 V_142 ,
T_2 V_129 , T_2 V_32 , int V_165 )
{
struct V_67 V_20 ;
struct V_65 * V_66 ;
struct V_113 * V_114 ;
struct V_158 * V_159 ;
T_2 V_6 ;
T_2 V_115 ;
unsigned long V_166 ;
unsigned long V_30 ;
int V_130 ;
int type ;
int V_167 ;
int V_28 ;
int V_79 = 0 ;
bool V_168 = F_74 ( V_34 -> V_36 ,
V_118 ) ;
V_20 . V_21 = V_26 ;
V_20 . type = V_75 ;
V_20 . V_32 = V_35 ;
V_167 = F_120 ( V_16 , V_129 ) ;
if ( V_165 ) {
V_130 = F_123 ( V_167 ) ;
V_64 -> V_169 = 1 ;
} else
V_130 = - 1 ;
if ( V_168 && V_129 < V_139 ) {
V_20 . type = V_83 ;
V_20 . V_32 = V_129 ;
}
V_76:
V_28 = F_37 ( V_107 , V_34 , & V_20 , V_64 , V_130 , 1 ) ;
if ( V_28 < 0 ) {
V_79 = V_28 ;
goto V_71;
}
if ( V_28 > 0 && V_168 ) {
V_168 = false ;
if ( V_64 -> V_81 [ 0 ] ) {
V_64 -> V_81 [ 0 ] -- ;
F_40 ( V_64 -> V_80 [ 0 ] , & V_20 ,
V_64 -> V_81 [ 0 ] ) ;
if ( V_20 . V_21 == V_26 &&
V_20 . type == V_75 &&
V_20 . V_32 == V_35 )
V_28 = 0 ;
}
if ( V_28 ) {
V_20 . type = V_75 ;
V_20 . V_32 = V_35 ;
F_43 ( V_64 ) ;
goto V_76;
}
}
if ( V_28 && ! V_165 ) {
V_79 = - V_149 ;
goto V_71;
} else if ( V_28 ) {
V_79 = - V_170 ;
F_8 ( 1 ) ;
goto V_71;
}
V_66 = V_64 -> V_80 [ 0 ] ;
V_115 = F_75 ( V_66 , V_64 -> V_81 [ 0 ] ) ;
#ifdef F_79
if ( V_115 < sizeof( * V_114 ) ) {
if ( ! V_165 ) {
V_79 = - V_149 ;
goto V_71;
}
V_28 = F_85 ( V_107 , V_34 , V_64 , V_129 ,
V_130 ) ;
if ( V_28 < 0 ) {
V_79 = V_28 ;
goto V_71;
}
V_66 = V_64 -> V_80 [ 0 ] ;
V_115 = F_75 ( V_66 , V_64 -> V_81 [ 0 ] ) ;
}
#endif
F_30 ( V_115 < sizeof( * V_114 ) ) ;
V_114 = F_76 ( V_66 , V_64 -> V_81 [ 0 ] , struct V_113 ) ;
V_6 = F_78 ( V_66 , V_114 ) ;
V_166 = ( unsigned long ) ( V_114 + 1 ) ;
V_30 = ( unsigned long ) V_114 + V_115 ;
if ( V_6 & V_140 && ! V_168 ) {
V_166 += sizeof( struct V_134 ) ;
F_30 ( V_166 > V_30 ) ;
}
V_79 = - V_149 ;
while ( 1 ) {
if ( V_166 >= V_30 ) {
F_8 ( V_166 > V_30 ) ;
break;
}
V_159 = (struct V_158 * ) V_166 ;
type = F_117 ( V_66 , V_159 ) ;
if ( V_167 < type )
break;
if ( V_167 > type ) {
V_166 += F_123 ( type ) ;
continue;
}
if ( type == V_151 ) {
struct V_146 * V_171 ;
V_171 = (struct V_146 * ) ( & V_159 -> V_32 ) ;
if ( F_101 ( V_66 , V_171 , V_142 ,
V_129 , V_32 ) ) {
V_79 = 0 ;
break;
}
if ( F_97 ( V_66 , V_171 ) <
F_94 ( V_142 , V_129 , V_32 ) )
break;
} else {
T_2 V_172 ;
V_172 = F_124 ( V_66 , V_159 ) ;
if ( V_16 > 0 ) {
if ( V_16 == V_172 ) {
V_79 = 0 ;
break;
}
if ( V_172 < V_16 )
break;
} else {
if ( V_142 == V_172 ) {
V_79 = 0 ;
break;
}
if ( V_172 < V_142 )
break;
}
}
V_166 += F_123 ( type ) ;
}
if ( V_79 == - V_149 && V_165 ) {
if ( V_115 + V_130 >=
F_125 ( V_34 ) ) {
V_79 = - V_173 ;
goto V_71;
}
if ( F_41 ( V_64 , 0 , & V_20 ) == 0 &&
V_20 . V_21 == V_26 &&
V_20 . type < V_174 ) {
V_79 = - V_173 ;
goto V_71;
}
}
* V_164 = (struct V_158 * ) V_166 ;
V_71:
if ( V_165 ) {
V_64 -> V_169 = 0 ;
F_126 ( V_64 , 1 ) ;
}
return V_79 ;
}
static T_5
void F_127 ( struct V_33 * V_34 ,
struct V_63 * V_64 ,
struct V_158 * V_159 ,
T_2 V_16 , T_2 V_142 ,
T_2 V_129 , T_2 V_32 , int V_153 ,
struct V_175 * V_125 )
{
struct V_65 * V_66 ;
struct V_113 * V_114 ;
unsigned long V_166 ;
unsigned long V_30 ;
unsigned long V_176 ;
T_2 V_109 ;
int V_56 ;
int type ;
V_66 = V_64 -> V_80 [ 0 ] ;
V_114 = F_76 ( V_66 , V_64 -> V_81 [ 0 ] , struct V_113 ) ;
V_176 = ( unsigned long ) V_159 - ( unsigned long ) V_114 ;
type = F_120 ( V_16 , V_129 ) ;
V_56 = F_123 ( type ) ;
F_87 ( V_34 , V_64 , V_56 ) ;
V_114 = F_76 ( V_66 , V_64 -> V_81 [ 0 ] , struct V_113 ) ;
V_109 = F_77 ( V_66 , V_114 ) ;
V_109 += V_153 ;
F_88 ( V_66 , V_114 , V_109 ) ;
if ( V_125 )
F_128 ( V_125 , V_66 , V_114 ) ;
V_166 = ( unsigned long ) V_114 + V_176 ;
V_30 = ( unsigned long ) V_114 + F_75 ( V_66 , V_64 -> V_81 [ 0 ] ) ;
if ( V_166 < V_30 - V_56 )
F_129 ( V_66 , V_166 + V_56 , V_166 ,
V_30 - V_56 - V_166 ) ;
V_159 = (struct V_158 * ) V_166 ;
F_130 ( V_66 , V_159 , type ) ;
if ( type == V_151 ) {
struct V_146 * V_171 ;
V_171 = (struct V_146 * ) ( & V_159 -> V_32 ) ;
F_107 ( V_66 , V_171 , V_142 ) ;
F_108 ( V_66 , V_171 , V_129 ) ;
F_109 ( V_66 , V_171 , V_32 ) ;
F_110 ( V_66 , V_171 , V_153 ) ;
} else if ( type == V_150 ) {
struct V_154 * V_177 ;
V_177 = (struct V_154 * ) ( V_159 + 1 ) ;
F_105 ( V_66 , V_177 , V_153 ) ;
F_131 ( V_66 , V_159 , V_16 ) ;
} else if ( type == V_160 ) {
F_131 ( V_66 , V_159 , V_16 ) ;
} else {
F_131 ( V_66 , V_159 , V_142 ) ;
}
F_93 ( V_66 ) ;
}
static int F_132 ( struct V_106 * V_107 ,
struct V_33 * V_34 ,
struct V_63 * V_64 ,
struct V_158 * * V_164 ,
T_2 V_26 , T_2 V_35 , T_2 V_16 ,
T_2 V_142 , T_2 V_129 , T_2 V_32 )
{
int V_28 ;
V_28 = F_122 ( V_107 , V_34 , V_64 , V_164 ,
V_26 , V_35 , V_16 ,
V_142 , V_129 , V_32 , 0 ) ;
if ( V_28 != - V_149 )
return V_28 ;
F_43 ( V_64 ) ;
* V_164 = NULL ;
if ( V_129 < V_139 ) {
V_28 = F_118 ( V_107 , V_34 , V_64 , V_26 , V_16 ,
V_142 ) ;
} else {
V_28 = F_102 ( V_107 , V_34 , V_64 , V_26 , V_16 ,
V_142 , V_129 , V_32 ) ;
}
return V_28 ;
}
static T_5
void F_133 ( struct V_33 * V_34 ,
struct V_63 * V_64 ,
struct V_158 * V_159 ,
int V_178 ,
struct V_175 * V_125 )
{
struct V_65 * V_66 ;
struct V_113 * V_114 ;
struct V_146 * V_171 = NULL ;
struct V_154 * V_177 = NULL ;
unsigned long V_166 ;
unsigned long V_30 ;
T_3 V_115 ;
int V_56 ;
int type ;
T_2 V_109 ;
V_66 = V_64 -> V_80 [ 0 ] ;
V_114 = F_76 ( V_66 , V_64 -> V_81 [ 0 ] , struct V_113 ) ;
V_109 = F_77 ( V_66 , V_114 ) ;
F_8 ( V_178 < 0 && V_109 + V_178 <= 0 ) ;
V_109 += V_178 ;
F_88 ( V_66 , V_114 , V_109 ) ;
if ( V_125 )
F_128 ( V_125 , V_66 , V_114 ) ;
type = F_117 ( V_66 , V_159 ) ;
if ( type == V_151 ) {
V_171 = (struct V_146 * ) ( & V_159 -> V_32 ) ;
V_109 = F_111 ( V_66 , V_171 ) ;
} else if ( type == V_150 ) {
V_177 = (struct V_154 * ) ( V_159 + 1 ) ;
V_109 = F_106 ( V_66 , V_177 ) ;
} else {
V_109 = 1 ;
F_30 ( V_178 != - 1 ) ;
}
F_30 ( V_178 < 0 && V_109 < - V_178 ) ;
V_109 += V_178 ;
if ( V_109 > 0 ) {
if ( type == V_151 )
F_110 ( V_66 , V_171 , V_109 ) ;
else
F_105 ( V_66 , V_177 , V_109 ) ;
} else {
V_56 = F_123 ( type ) ;
V_115 = F_75 ( V_66 , V_64 -> V_81 [ 0 ] ) ;
V_166 = ( unsigned long ) V_159 ;
V_30 = ( unsigned long ) V_114 + V_115 ;
if ( V_166 + V_56 < V_30 )
F_129 ( V_66 , V_166 , V_166 + V_56 ,
V_30 - V_166 - V_56 ) ;
V_115 -= V_56 ;
F_134 ( V_34 , V_64 , V_115 , 1 ) ;
}
F_93 ( V_66 ) ;
}
static T_5
int F_135 ( struct V_106 * V_107 ,
struct V_33 * V_34 ,
struct V_63 * V_64 ,
T_2 V_26 , T_2 V_35 , T_2 V_16 ,
T_2 V_142 , T_2 V_129 ,
T_2 V_32 , int V_153 ,
struct V_175 * V_125 )
{
struct V_158 * V_159 ;
int V_28 ;
V_28 = F_122 ( V_107 , V_34 , V_64 , & V_159 ,
V_26 , V_35 , V_16 ,
V_142 , V_129 , V_32 , 1 ) ;
if ( V_28 == 0 ) {
F_30 ( V_129 < V_139 ) ;
F_133 ( V_34 , V_64 , V_159 ,
V_153 , V_125 ) ;
} else if ( V_28 == - V_149 ) {
F_127 ( V_34 , V_64 , V_159 , V_16 ,
V_142 , V_129 , V_32 ,
V_153 , V_125 ) ;
V_28 = 0 ;
}
return V_28 ;
}
static int F_136 ( struct V_106 * V_107 ,
struct V_33 * V_34 ,
struct V_63 * V_64 ,
T_2 V_26 , T_2 V_16 , T_2 V_142 ,
T_2 V_129 , T_2 V_32 , int V_153 )
{
int V_28 ;
if ( V_129 < V_139 ) {
F_30 ( V_153 != 1 ) ;
V_28 = F_119 ( V_107 , V_34 , V_64 , V_26 ,
V_16 , V_142 ) ;
} else {
V_28 = F_103 ( V_107 , V_34 , V_64 , V_26 ,
V_16 , V_142 ,
V_129 , V_32 , V_153 ) ;
}
return V_28 ;
}
static int F_137 ( struct V_106 * V_107 ,
struct V_33 * V_34 ,
struct V_63 * V_64 ,
struct V_158 * V_159 ,
int V_155 , int V_179 )
{
int V_28 = 0 ;
F_30 ( ! V_179 && V_155 != 1 ) ;
if ( V_159 ) {
F_133 ( V_34 , V_64 , V_159 ,
- V_155 , NULL ) ;
} else if ( V_179 ) {
V_28 = F_112 ( V_107 , V_34 , V_64 , V_155 ) ;
} else {
V_28 = F_114 ( V_107 , V_34 , V_64 ) ;
}
return V_28 ;
}
static int F_138 ( struct V_180 * V_181 ,
T_2 V_31 , T_2 V_48 )
{
return F_139 ( V_181 , V_31 >> 9 , V_48 >> 9 , V_39 , 0 ) ;
}
static int F_140 ( struct V_33 * V_34 , T_2 V_26 ,
T_2 V_35 , T_2 * V_182 )
{
int V_28 ;
T_2 V_183 = 0 ;
struct V_184 * V_185 = NULL ;
V_28 = F_141 ( V_34 -> V_36 , V_186 ,
V_26 , & V_35 , & V_185 , 0 ) ;
if ( ! V_28 ) {
struct V_187 * V_188 = V_185 -> V_189 ;
int V_42 ;
for ( V_42 = 0 ; V_42 < V_185 -> V_190 ; V_42 ++ , V_188 ++ ) {
if ( ! V_188 -> V_191 -> V_192 )
continue;
V_28 = F_138 ( V_188 -> V_191 -> V_181 ,
V_188 -> V_193 ,
V_188 -> V_194 ) ;
if ( ! V_28 )
V_183 += V_188 -> V_194 ;
else if ( V_28 != - V_195 )
break;
V_28 = 0 ;
}
F_9 ( V_185 ) ;
}
if ( V_182 )
* V_182 = V_183 ;
if ( V_28 == - V_195 )
V_28 = 0 ;
return V_28 ;
}
int F_142 ( struct V_106 * V_107 ,
struct V_33 * V_34 ,
T_2 V_26 , T_2 V_35 , T_2 V_16 ,
T_2 V_142 , T_2 V_129 , T_2 V_32 , int V_196 )
{
int V_28 ;
struct V_11 * V_36 = V_34 -> V_36 ;
F_30 ( V_129 < V_139 &&
V_142 == V_197 ) ;
if ( V_129 < V_139 ) {
V_28 = F_143 ( V_36 , V_107 , V_26 ,
V_35 ,
V_16 , V_142 , ( int ) V_129 ,
V_198 , NULL , V_196 ) ;
} else {
V_28 = F_144 ( V_36 , V_107 , V_26 ,
V_35 ,
V_16 , V_142 , V_129 , V_32 ,
V_198 , NULL , V_196 ) ;
}
return V_28 ;
}
static int F_145 ( struct V_106 * V_107 ,
struct V_33 * V_34 ,
T_2 V_26 , T_2 V_35 ,
T_2 V_16 , T_2 V_142 ,
T_2 V_129 , T_2 V_32 , int V_153 ,
struct V_175 * V_125 )
{
struct V_63 * V_64 ;
struct V_65 * V_66 ;
struct V_113 * V_131 ;
T_2 V_109 ;
int V_28 ;
int V_79 = 0 ;
V_64 = F_33 () ;
if ( ! V_64 )
return - V_88 ;
V_64 -> V_74 = 1 ;
V_64 -> V_199 = 1 ;
V_28 = F_135 ( V_107 , V_34 -> V_36 -> V_62 ,
V_64 , V_26 , V_35 , V_16 ,
V_142 , V_129 , V_32 ,
V_153 , V_125 ) ;
if ( V_28 == 0 )
goto V_71;
if ( V_28 != - V_173 ) {
V_79 = V_28 ;
goto V_71;
}
V_66 = V_64 -> V_80 [ 0 ] ;
V_131 = F_76 ( V_66 , V_64 -> V_81 [ 0 ] , struct V_113 ) ;
V_109 = F_77 ( V_66 , V_131 ) ;
F_88 ( V_66 , V_131 , V_109 + V_153 ) ;
if ( V_125 )
F_128 ( V_125 , V_66 , V_131 ) ;
F_93 ( V_66 ) ;
F_43 ( V_64 ) ;
V_64 -> V_74 = 1 ;
V_64 -> V_199 = 1 ;
V_28 = F_136 ( V_107 , V_34 -> V_36 -> V_62 ,
V_64 , V_26 , V_16 , V_142 ,
V_129 , V_32 , V_153 ) ;
if ( V_28 )
F_146 ( V_107 , V_34 , V_28 ) ;
V_71:
F_49 ( V_64 ) ;
return V_79 ;
}
static int F_147 ( struct V_106 * V_107 ,
struct V_33 * V_34 ,
struct V_200 * V_124 ,
struct V_175 * V_125 ,
int V_201 )
{
int V_28 = 0 ;
struct V_202 * V_147 ;
struct V_67 V_203 ;
T_2 V_16 = 0 ;
T_2 V_204 = 0 ;
T_2 V_6 = 0 ;
V_203 . V_21 = V_124 -> V_26 ;
V_203 . V_32 = V_124 -> V_35 ;
V_203 . type = V_75 ;
V_147 = F_148 ( V_124 ) ;
if ( V_124 -> type == V_150 )
V_16 = V_147 -> V_16 ;
else
V_204 = V_147 -> V_34 ;
if ( V_124 -> V_205 == V_198 && V_201 ) {
if ( V_125 )
V_6 |= V_125 -> V_127 ;
V_28 = F_149 ( V_107 , V_34 ,
V_16 , V_204 , V_6 ,
V_147 -> V_21 , V_147 -> V_32 ,
& V_203 , V_124 -> V_128 ) ;
} else if ( V_124 -> V_205 == V_198 ) {
V_28 = F_145 ( V_107 , V_34 , V_124 -> V_26 ,
V_124 -> V_35 , V_16 ,
V_204 , V_147 -> V_21 ,
V_147 -> V_32 , V_124 -> V_128 ,
V_125 ) ;
} else if ( V_124 -> V_205 == V_206 ) {
V_28 = F_150 ( V_107 , V_34 , V_124 -> V_26 ,
V_124 -> V_35 , V_16 ,
V_204 , V_147 -> V_21 ,
V_147 -> V_32 , V_124 -> V_128 ,
V_125 ) ;
} else {
F_81 () ;
}
return V_28 ;
}
static void F_128 ( struct V_175 * V_125 ,
struct V_65 * V_66 ,
struct V_113 * V_114 )
{
T_2 V_6 = F_78 ( V_66 , V_114 ) ;
if ( V_125 -> V_126 ) {
V_6 |= V_125 -> V_127 ;
F_90 ( V_66 , V_114 , V_6 ) ;
}
if ( V_125 -> V_207 ) {
struct V_134 * V_135 ;
F_30 ( ! ( V_6 & V_140 ) ) ;
V_135 = (struct V_134 * ) ( V_114 + 1 ) ;
F_151 ( V_66 , V_135 , & V_125 -> V_20 ) ;
}
}
static int F_152 ( struct V_106 * V_107 ,
struct V_33 * V_34 ,
struct V_200 * V_124 ,
struct V_175 * V_125 )
{
struct V_67 V_20 ;
struct V_63 * V_64 ;
struct V_113 * V_114 ;
struct V_65 * V_66 ;
T_3 V_115 ;
int V_28 ;
int V_79 = 0 ;
int V_108 = ! V_125 -> V_179 ;
if ( V_107 -> V_208 )
return 0 ;
if ( V_108 && ! F_74 ( V_34 -> V_36 , V_118 ) )
V_108 = 0 ;
V_64 = F_33 () ;
if ( ! V_64 )
return - V_88 ;
V_20 . V_21 = V_124 -> V_26 ;
if ( V_108 ) {
V_20 . type = V_83 ;
V_20 . V_32 = V_125 -> V_162 ;
} else {
V_20 . type = V_75 ;
V_20 . V_32 = V_124 -> V_35 ;
}
V_76:
V_64 -> V_74 = 1 ;
V_64 -> V_199 = 1 ;
V_28 = F_37 ( V_107 , V_34 -> V_36 -> V_62 , & V_20 ,
V_64 , 0 , 1 ) ;
if ( V_28 < 0 ) {
V_79 = V_28 ;
goto V_71;
}
if ( V_28 > 0 ) {
if ( V_108 ) {
F_43 ( V_64 ) ;
V_108 = 0 ;
V_20 . V_32 = V_124 -> V_35 ;
V_20 . type = V_75 ;
goto V_76;
}
V_79 = - V_170 ;
goto V_71;
}
V_66 = V_64 -> V_80 [ 0 ] ;
V_115 = F_75 ( V_66 , V_64 -> V_81 [ 0 ] ) ;
#ifdef F_79
if ( V_115 < sizeof( * V_114 ) ) {
V_28 = F_85 ( V_107 , V_34 -> V_36 -> V_62 ,
V_64 , ( T_2 ) - 1 , 0 ) ;
if ( V_28 < 0 ) {
V_79 = V_28 ;
goto V_71;
}
V_66 = V_64 -> V_80 [ 0 ] ;
V_115 = F_75 ( V_66 , V_64 -> V_81 [ 0 ] ) ;
}
#endif
F_30 ( V_115 < sizeof( * V_114 ) ) ;
V_114 = F_76 ( V_66 , V_64 -> V_81 [ 0 ] , struct V_113 ) ;
F_128 ( V_125 , V_66 , V_114 ) ;
F_93 ( V_66 ) ;
V_71:
F_49 ( V_64 ) ;
return V_79 ;
}
static int F_153 ( struct V_106 * V_107 ,
struct V_33 * V_34 ,
struct V_200 * V_124 ,
struct V_175 * V_125 ,
int V_201 )
{
int V_28 = 0 ;
struct V_209 * V_147 ;
struct V_67 V_203 ;
T_2 V_16 = 0 ;
T_2 V_204 = 0 ;
bool V_168 = F_74 ( V_34 -> V_36 ,
V_118 ) ;
V_147 = F_154 ( V_124 ) ;
if ( V_124 -> type == V_160 )
V_16 = V_147 -> V_16 ;
else
V_204 = V_147 -> V_34 ;
V_203 . V_21 = V_124 -> V_26 ;
if ( V_168 ) {
V_203 . V_32 = V_147 -> V_162 ;
V_203 . type = V_83 ;
} else {
V_203 . V_32 = V_124 -> V_35 ;
V_203 . type = V_75 ;
}
F_30 ( V_124 -> V_128 != 1 ) ;
if ( V_124 -> V_205 == V_198 && V_201 ) {
F_30 ( ! V_125 || ! V_125 -> V_126 ) ;
V_28 = F_155 ( V_107 , V_34 ,
V_16 , V_204 ,
V_125 -> V_127 ,
& V_125 -> V_20 ,
V_147 -> V_162 , & V_203 ) ;
} else if ( V_124 -> V_205 == V_198 ) {
V_28 = F_145 ( V_107 , V_34 , V_124 -> V_26 ,
V_124 -> V_35 , V_16 , V_204 ,
V_147 -> V_162 , 0 , 1 , V_125 ) ;
} else if ( V_124 -> V_205 == V_206 ) {
V_28 = F_150 ( V_107 , V_34 , V_124 -> V_26 ,
V_124 -> V_35 , V_16 , V_204 ,
V_147 -> V_162 , 0 , 1 , V_125 ) ;
} else {
F_81 () ;
}
return V_28 ;
}
static int F_156 ( struct V_106 * V_107 ,
struct V_33 * V_34 ,
struct V_200 * V_124 ,
struct V_175 * V_125 ,
int V_201 )
{
int V_28 = 0 ;
if ( V_107 -> V_208 )
return 0 ;
if ( F_157 ( V_124 ) ) {
struct V_110 * V_101 ;
F_30 ( V_125 ) ;
V_101 = F_158 ( V_124 ) ;
if ( V_201 ) {
F_159 ( V_34 , V_124 -> V_26 ,
V_124 -> V_35 , 1 ) ;
if ( V_101 -> V_179 ) {
V_28 = F_160 ( V_107 , V_34 ,
V_124 -> V_26 ,
V_124 -> V_35 ) ;
}
}
return V_28 ;
}
if ( V_124 -> type == V_161 ||
V_124 -> type == V_160 )
V_28 = F_153 ( V_107 , V_34 , V_124 , V_125 ,
V_201 ) ;
else if ( V_124 -> type == V_151 ||
V_124 -> type == V_150 )
V_28 = F_147 ( V_107 , V_34 , V_124 , V_125 ,
V_201 ) ;
else
F_81 () ;
return V_28 ;
}
T_1 int F_161 ( struct V_106 * V_107 ,
struct V_33 * V_34 ,
struct V_100 * V_210 )
{
struct V_111 * V_112 ;
struct V_200 * V_147 ;
struct V_110 * V_211 = NULL ;
struct V_175 * V_125 ;
struct V_11 * V_36 = V_34 -> V_36 ;
int V_28 ;
int V_7 = 0 ;
int V_212 = 0 ;
V_112 = & V_107 -> V_123 -> V_112 ;
while ( 1 ) {
if ( ! V_211 ) {
if ( F_162 ( V_210 ) )
break;
V_211 = F_163 ( V_210 -> V_213 ,
struct V_110 , V_210 ) ;
V_28 = F_164 ( V_107 , V_211 ) ;
if ( V_28 == - V_173 ) {
V_211 = NULL ;
V_7 ++ ;
continue;
}
}
F_165 ( V_107 , V_36 , V_112 ,
V_211 ) ;
V_147 = F_166 ( V_211 ) ;
if ( V_147 && V_147 -> V_214 &&
F_167 ( V_36 , V_112 , V_147 -> V_214 ) ) {
F_168 ( & V_211 -> V_210 ) ;
F_169 ( V_211 ) ;
V_211 = NULL ;
V_112 -> V_215 ++ ;
F_13 ( & V_112 -> V_51 ) ;
F_46 () ;
F_11 ( & V_112 -> V_51 ) ;
continue;
}
V_212 = V_211 -> V_212 ;
V_211 -> V_212 = 0 ;
V_125 = V_211 -> V_125 ;
V_211 -> V_125 = NULL ;
if ( ! V_147 ) {
V_147 = & V_211 -> V_124 ;
if ( V_125 && V_212 ) {
F_170 ( V_125 ) ;
V_125 = NULL ;
}
if ( V_125 ) {
F_13 ( & V_112 -> V_51 ) ;
V_28 = F_152 ( V_107 , V_34 ,
V_147 , V_125 ) ;
F_170 ( V_125 ) ;
if ( V_28 ) {
F_171 ( V_36 , L_1 , V_28 ) ;
F_11 ( & V_112 -> V_51 ) ;
F_169 ( V_211 ) ;
return V_28 ;
}
goto V_213;
}
}
V_147 -> V_216 = 0 ;
F_172 ( & V_147 -> V_14 , & V_112 -> V_34 ) ;
V_112 -> V_217 -- ;
if ( ! F_157 ( V_147 ) ) {
switch ( V_147 -> V_205 ) {
case V_198 :
case V_218 :
V_211 -> V_124 . V_128 -= V_147 -> V_128 ;
break;
case V_206 :
V_211 -> V_124 . V_128 += V_147 -> V_128 ;
break;
default:
F_8 ( 1 ) ;
}
}
F_13 ( & V_112 -> V_51 ) ;
V_28 = F_156 ( V_107 , V_34 , V_147 , V_125 ,
V_212 ) ;
F_170 ( V_125 ) ;
if ( V_28 ) {
F_169 ( V_211 ) ;
F_84 ( V_147 ) ;
F_171 ( V_36 , L_2 , V_28 ) ;
F_11 ( & V_112 -> V_51 ) ;
return V_28 ;
}
if ( F_157 ( V_147 ) ) {
F_168 ( & V_211 -> V_210 ) ;
F_169 ( V_211 ) ;
V_211 = NULL ;
}
F_84 ( V_147 ) ;
V_7 ++ ;
V_213:
F_46 () ;
F_11 ( & V_112 -> V_51 ) ;
}
return V_7 ;
}
static T_2 F_173 ( struct V_219 * V_34 )
{
struct V_14 * V_29 = V_34 -> V_14 ;
struct V_200 * V_220 ;
int V_221 = 1 ;
T_2 V_222 ;
T_2 V_223 = 0 , V_69 = 0 ;
V_29 = F_174 ( V_34 ) ;
if ( V_29 ) {
V_220 = F_12 ( V_29 , struct V_200 , V_14 ) ;
V_223 = V_220 -> V_26 ;
}
V_29 = F_175 ( V_34 ) ;
if ( V_29 ) {
V_220 = F_12 ( V_29 , struct V_200 , V_14 ) ;
V_69 = V_220 -> V_26 ;
}
V_29 = V_34 -> V_14 ;
while ( V_29 ) {
V_220 = F_12 ( V_29 , struct V_200 , V_14 ) ;
F_8 ( ! V_220 -> V_216 ) ;
V_222 = V_220 -> V_26 ;
if ( V_221 )
V_29 = V_29 -> V_22 ;
else
V_29 = V_29 -> V_23 ;
V_221 = 1 - V_221 ;
}
return V_222 ;
}
int F_176 ( struct V_106 * V_107 ,
struct V_11 * V_36 )
{
struct V_224 * V_224 ;
int V_28 = 0 ;
if ( F_162 ( & V_107 -> V_225 ) !=
! V_107 -> V_226 . V_214 ) {
F_177 ( V_36 ,
L_3 ,
F_162 ( & V_107 -> V_225 ) ? L_4 : L_5 ,
( T_3 ) ( V_107 -> V_226 . V_214 >> 32 ) ,
( T_3 ) V_107 -> V_226 . V_214 ) ;
F_81 () ;
}
if ( ! V_107 -> V_226 . V_214 )
return 0 ;
while ( ! F_162 ( & V_107 -> V_225 ) ) {
V_224 = F_178 ( & V_107 -> V_225 ,
struct V_224 , V_89 ) ;
F_179 ( & V_224 -> V_89 ) ;
if ( ! V_28 )
V_28 = F_180 (
V_107 , V_36 , V_224 -> V_124 ,
V_224 -> V_125 ) ;
F_9 ( V_224 ) ;
}
F_181 ( V_36 , & V_107 -> V_226 ) ;
return V_28 ;
}
static int F_182 ( struct V_111 * V_112 , int V_214 ,
int V_7 )
{
int V_227 = F_183 ( & V_112 -> V_228 ) ;
if ( V_227 < V_214 || V_227 >= V_214 + V_7 )
return 1 ;
return 0 ;
}
int F_184 ( struct V_106 * V_107 ,
struct V_33 * V_34 , unsigned long V_7 )
{
struct V_14 * V_124 ;
struct V_111 * V_112 ;
struct V_200 * V_147 ;
struct V_100 V_210 ;
int V_28 ;
T_2 V_229 ;
int V_230 = V_7 == ( unsigned long ) - 1 ;
int V_231 = 0 ;
int V_232 ;
if ( V_107 -> V_208 )
return 0 ;
if ( V_34 == V_34 -> V_36 -> V_62 )
V_34 = V_34 -> V_36 -> V_84 ;
F_176 ( V_107 , V_34 -> V_36 ) ;
V_112 = & V_107 -> V_123 -> V_112 ;
F_53 ( & V_210 ) ;
if ( V_7 == 0 ) {
V_7 = V_112 -> V_217 * 2 ;
V_231 = 1 ;
}
if ( ! V_230 && ! V_231 ) {
int V_233 ;
int V_214 = F_183 ( & V_112 -> V_228 ) ;
V_82:
V_233 = F_185 ( & V_112 -> V_234 , 0 , 1 ) ;
if ( V_233 ) {
F_51 ( V_235 ) ;
if ( V_112 -> V_217 < 16348 )
return 0 ;
F_57 ( & V_112 -> V_86 , & V_235 ,
V_92 ) ;
V_233 = F_185 ( & V_112 -> V_234 , 0 , 1 ) ;
if ( V_233 ) {
F_58 () ;
F_59 ( & V_112 -> V_86 , & V_235 ) ;
if ( ! F_182 ( V_112 , V_214 , 256 ) )
goto V_82;
else
return 0 ;
} else {
F_59 ( & V_112 -> V_86 , & V_235 ) ;
goto V_76;
}
}
} else {
F_5 ( & V_112 -> V_234 ) ;
}
V_76:
V_232 = 0 ;
F_11 ( & V_112 -> V_51 ) ;
#ifdef F_186
V_112 -> V_236 = F_173 ( & V_112 -> V_34 ) ;
#endif
while ( 1 ) {
if ( ! ( V_230 || V_231 ) &&
V_112 -> V_215 < 64 )
break;
V_229 = V_112 -> V_236 ;
V_28 = F_187 ( V_107 , & V_210 ,
V_112 -> V_236 ) ;
if ( V_28 )
break;
V_28 = F_161 ( V_107 , V_34 , & V_210 ) ;
if ( V_28 < 0 ) {
F_188 ( & V_210 ) ;
F_13 ( & V_112 -> V_51 ) ;
F_146 ( V_107 , V_34 , V_28 ) ;
F_189 ( & V_112 -> V_234 ) ;
return V_28 ;
}
F_190 ( V_28 , & V_112 -> V_228 ) ;
V_7 -= F_24 (unsigned long, ret, count) ;
if ( V_7 == 0 )
break;
if ( V_229 >= V_112 -> V_236 ) {
if ( V_232 == 0 ) {
V_232 = 1 ;
} else {
F_30 ( V_230 ) ;
break;
}
}
if ( V_28 ) {
V_232 = 0 ;
}
}
if ( V_230 ) {
if ( ! F_162 ( & V_107 -> V_237 ) ) {
F_13 ( & V_112 -> V_51 ) ;
F_191 ( V_107 , V_34 ) ;
F_11 ( & V_112 -> V_51 ) ;
}
V_124 = F_174 ( & V_112 -> V_34 ) ;
if ( ! V_124 )
goto V_71;
V_7 = ( unsigned long ) - 1 ;
while ( V_124 ) {
V_147 = F_12 ( V_124 , struct V_200 ,
V_14 ) ;
if ( F_157 ( V_147 ) ) {
struct V_110 * V_101 ;
V_101 = F_158 ( V_147 ) ;
F_5 ( & V_147 -> V_109 ) ;
F_13 ( & V_112 -> V_51 ) ;
F_35 ( & V_101 -> V_77 ) ;
F_45 ( & V_101 -> V_77 ) ;
F_84 ( V_147 ) ;
F_46 () ;
goto V_76;
}
V_124 = F_192 ( V_124 ) ;
}
F_13 ( & V_112 -> V_51 ) ;
F_193 ( 1 ) ;
goto V_76;
}
V_71:
F_189 ( & V_112 -> V_234 ) ;
F_2 () ;
if ( F_194 ( & V_112 -> V_86 ) )
F_48 ( & V_112 -> V_86 ) ;
F_13 ( & V_112 -> V_51 ) ;
F_195 ( V_107 ) ;
return 0 ;
}
int F_196 ( struct V_106 * V_107 ,
struct V_33 * V_34 ,
T_2 V_26 , T_2 V_35 , T_2 V_6 ,
int V_162 , int V_179 )
{
struct V_175 * V_125 ;
int V_28 ;
V_125 = F_197 () ;
if ( ! V_125 )
return - V_88 ;
V_125 -> V_127 = V_6 ;
V_125 -> V_126 = 1 ;
V_125 -> V_207 = 0 ;
V_125 -> V_179 = V_179 ? 1 : 0 ;
V_125 -> V_162 = V_162 ;
V_28 = F_198 ( V_34 -> V_36 , V_107 , V_26 ,
V_35 , V_125 ) ;
if ( V_28 )
F_170 ( V_125 ) ;
return V_28 ;
}
static T_1 int F_199 ( struct V_106 * V_107 ,
struct V_33 * V_34 ,
struct V_63 * V_64 ,
T_2 V_21 , T_2 V_32 , T_2 V_26 )
{
struct V_110 * V_101 ;
struct V_200 * V_147 ;
struct V_202 * V_238 ;
struct V_111 * V_112 ;
struct V_14 * V_124 ;
int V_28 = 0 ;
V_28 = - V_149 ;
V_112 = & V_107 -> V_123 -> V_112 ;
F_11 ( & V_112 -> V_51 ) ;
V_101 = F_82 ( V_107 , V_26 ) ;
if ( ! V_101 )
goto V_71;
if ( ! F_83 ( & V_101 -> V_77 ) ) {
F_5 ( & V_101 -> V_124 . V_109 ) ;
F_13 ( & V_112 -> V_51 ) ;
F_43 ( V_64 ) ;
F_35 ( & V_101 -> V_77 ) ;
F_45 ( & V_101 -> V_77 ) ;
F_84 ( & V_101 -> V_124 ) ;
return - V_173 ;
}
V_124 = F_200 ( & V_101 -> V_124 . V_14 ) ;
if ( ! V_124 )
goto V_239;
V_147 = F_12 ( V_124 , struct V_200 , V_14 ) ;
if ( V_147 -> V_26 != V_26 )
goto V_239;
V_28 = 1 ;
if ( V_147 -> type != V_151 )
goto V_239;
V_238 = F_148 ( V_147 ) ;
V_124 = F_200 ( V_124 ) ;
if ( V_124 ) {
int V_214 = V_147 -> V_214 ;
V_147 = F_12 ( V_124 , struct V_200 , V_14 ) ;
if ( V_147 -> V_26 == V_26 && V_147 -> V_214 == V_214 )
goto V_239;
}
if ( V_238 -> V_34 != V_34 -> V_240 . V_21 ||
V_238 -> V_21 != V_21 || V_238 -> V_32 != V_32 )
goto V_239;
V_28 = 0 ;
V_239:
F_45 ( & V_101 -> V_77 ) ;
V_71:
F_13 ( & V_112 -> V_51 ) ;
return V_28 ;
}
static T_1 int F_201 ( struct V_106 * V_107 ,
struct V_33 * V_34 ,
struct V_63 * V_64 ,
T_2 V_21 , T_2 V_32 , T_2 V_26 )
{
struct V_33 * V_62 = V_34 -> V_36 -> V_62 ;
struct V_65 * V_66 ;
struct V_146 * V_147 ;
struct V_158 * V_159 ;
struct V_113 * V_114 ;
struct V_67 V_20 ;
T_3 V_115 ;
int V_28 ;
V_20 . V_21 = V_26 ;
V_20 . V_32 = ( T_2 ) - 1 ;
V_20 . type = V_75 ;
V_28 = F_37 ( NULL , V_62 , & V_20 , V_64 , 0 , 0 ) ;
if ( V_28 < 0 )
goto V_71;
F_30 ( V_28 == 0 ) ;
V_28 = - V_149 ;
if ( V_64 -> V_81 [ 0 ] == 0 )
goto V_71;
V_64 -> V_81 [ 0 ] -- ;
V_66 = V_64 -> V_80 [ 0 ] ;
F_40 ( V_66 , & V_20 , V_64 -> V_81 [ 0 ] ) ;
if ( V_20 . V_21 != V_26 || V_20 . type != V_75 )
goto V_71;
V_28 = 1 ;
V_115 = F_75 ( V_66 , V_64 -> V_81 [ 0 ] ) ;
#ifdef F_79
if ( V_115 < sizeof( * V_114 ) ) {
F_8 ( V_115 != sizeof( struct V_120 ) ) ;
goto V_71;
}
#endif
V_114 = F_76 ( V_66 , V_64 -> V_81 [ 0 ] , struct V_113 ) ;
if ( V_115 != sizeof( * V_114 ) +
F_123 ( V_151 ) )
goto V_71;
if ( F_202 ( V_66 , V_114 ) <=
F_203 ( & V_34 -> V_241 ) )
goto V_71;
V_159 = (struct V_158 * ) ( V_114 + 1 ) ;
if ( F_117 ( V_66 , V_159 ) !=
V_151 )
goto V_71;
V_147 = (struct V_146 * ) ( & V_159 -> V_32 ) ;
if ( F_77 ( V_66 , V_114 ) !=
F_111 ( V_66 , V_147 ) ||
F_98 ( V_66 , V_147 ) !=
V_34 -> V_240 . V_21 ||
F_99 ( V_66 , V_147 ) != V_21 ||
F_100 ( V_66 , V_147 ) != V_32 )
goto V_71;
V_28 = 0 ;
V_71:
return V_28 ;
}
int F_204 ( struct V_106 * V_107 ,
struct V_33 * V_34 ,
T_2 V_21 , T_2 V_32 , T_2 V_26 )
{
struct V_63 * V_64 ;
int V_28 ;
int V_242 ;
V_64 = F_33 () ;
if ( ! V_64 )
return - V_149 ;
do {
V_28 = F_201 ( V_107 , V_34 , V_64 , V_21 ,
V_32 , V_26 ) ;
if ( V_28 && V_28 != - V_149 )
goto V_71;
V_242 = F_199 ( V_107 , V_34 , V_64 , V_21 ,
V_32 , V_26 ) ;
} while ( V_242 == - V_173 );
if ( V_242 && V_242 != - V_149 ) {
V_28 = V_242 ;
goto V_71;
}
if ( V_28 != - V_149 || V_242 != - V_149 )
V_28 = 0 ;
V_71:
F_49 ( V_64 ) ;
if ( V_34 -> V_240 . V_21 == V_243 )
F_8 ( V_28 > 0 ) ;
return V_28 ;
}
static int F_205 ( struct V_106 * V_107 ,
struct V_33 * V_34 ,
struct V_65 * V_244 ,
int V_245 , int V_246 , int V_196 )
{
T_2 V_26 ;
T_2 V_35 ;
T_2 V_16 ;
T_2 V_204 ;
T_3 V_70 ;
struct V_67 V_20 ;
struct V_247 * V_248 ;
int V_42 ;
int V_162 ;
int V_28 = 0 ;
int (* F_206)( struct V_106 * , struct V_33 * ,
T_2 , T_2 , T_2 , T_2 , T_2 , T_2 , int );
V_204 = F_207 ( V_244 ) ;
V_70 = F_38 ( V_244 ) ;
V_162 = F_208 ( V_244 ) ;
if ( ! V_34 -> V_249 && V_162 == 0 )
return 0 ;
if ( V_246 )
F_206 = F_142 ;
else
F_206 = V_250 ;
if ( V_245 )
V_16 = V_244 -> V_31 ;
else
V_16 = 0 ;
for ( V_42 = 0 ; V_42 < V_70 ; V_42 ++ ) {
if ( V_162 == 0 ) {
F_40 ( V_244 , & V_20 , V_42 ) ;
if ( F_209 ( & V_20 ) != V_251 )
continue;
V_248 = F_76 ( V_244 , V_42 ,
struct V_247 ) ;
if ( F_210 ( V_244 , V_248 ) ==
V_252 )
continue;
V_26 = F_211 ( V_244 , V_248 ) ;
if ( V_26 == 0 )
continue;
V_35 = F_212 ( V_244 , V_248 ) ;
V_20 . V_32 -= F_213 ( V_244 , V_248 ) ;
V_28 = F_206 ( V_107 , V_34 , V_26 , V_35 ,
V_16 , V_204 , V_20 . V_21 ,
V_20 . V_32 , V_196 ) ;
if ( V_28 )
goto V_152;
} else {
V_26 = F_214 ( V_244 , V_42 ) ;
V_35 = F_215 ( V_34 , V_162 - 1 ) ;
V_28 = F_206 ( V_107 , V_34 , V_26 , V_35 ,
V_16 , V_204 , V_162 - 1 , 0 ,
V_196 ) ;
if ( V_28 )
goto V_152;
}
}
return 0 ;
V_152:
return V_28 ;
}
int F_216 ( struct V_106 * V_107 , struct V_33 * V_34 ,
struct V_65 * V_244 , int V_245 , int V_196 )
{
return F_205 ( V_107 , V_34 , V_244 , V_245 , 1 , V_196 ) ;
}
int F_217 ( struct V_106 * V_107 , struct V_33 * V_34 ,
struct V_65 * V_244 , int V_245 , int V_196 )
{
return F_205 ( V_107 , V_34 , V_244 , V_245 , 0 , V_196 ) ;
}
static int F_218 ( struct V_106 * V_107 ,
struct V_33 * V_34 ,
struct V_63 * V_64 ,
struct V_1 * V_2 )
{
int V_28 ;
struct V_33 * V_62 = V_34 -> V_36 -> V_62 ;
unsigned long V_135 ;
struct V_65 * V_66 ;
V_28 = F_37 ( V_107 , V_62 , & V_2 -> V_20 , V_64 , 0 , 1 ) ;
if ( V_28 < 0 )
goto V_152;
F_30 ( V_28 ) ;
V_66 = V_64 -> V_80 [ 0 ] ;
V_135 = F_219 ( V_66 , V_64 -> V_81 [ 0 ] ) ;
F_220 ( V_66 , & V_2 -> V_131 , V_135 , sizeof( V_2 -> V_131 ) ) ;
F_93 ( V_66 ) ;
F_43 ( V_64 ) ;
V_152:
if ( V_28 ) {
F_146 ( V_107 , V_34 , V_28 ) ;
return V_28 ;
}
return 0 ;
}
static struct V_1 *
F_221 ( struct V_33 * V_34 ,
struct V_1 * V_2 )
{
struct V_14 * V_124 ;
F_11 ( & V_34 -> V_36 -> V_17 ) ;
V_124 = F_192 ( & V_2 -> V_19 ) ;
F_6 ( V_2 ) ;
if ( V_124 ) {
V_2 = F_12 ( V_124 , struct V_1 ,
V_19 ) ;
F_4 ( V_2 ) ;
} else
V_2 = NULL ;
F_13 ( & V_34 -> V_36 -> V_17 ) ;
return V_2 ;
}
static int F_222 ( struct V_1 * V_13 ,
struct V_106 * V_107 ,
struct V_63 * V_64 )
{
struct V_33 * V_34 = V_13 -> V_36 -> V_84 ;
struct V_253 * V_253 = NULL ;
T_2 V_254 = 0 ;
int V_255 = V_256 ;
int V_257 = 0 ;
int V_258 = 0 ;
int V_28 = 0 ;
if ( V_13 -> V_20 . V_32 < ( 100 * 1024 * 1024 ) ) {
F_11 ( & V_13 -> V_51 ) ;
V_13 -> V_259 = V_260 ;
F_13 ( & V_13 -> V_51 ) ;
return 0 ;
}
V_76:
V_253 = F_223 ( V_34 , V_13 , V_64 ) ;
if ( F_224 ( V_253 ) && F_225 ( V_253 ) != - V_149 ) {
V_28 = F_225 ( V_253 ) ;
F_43 ( V_64 ) ;
goto V_71;
}
if ( F_224 ( V_253 ) ) {
F_30 ( V_258 ) ;
V_258 ++ ;
if ( V_13 -> V_261 )
goto V_119;
V_28 = F_226 ( V_34 , V_107 , V_13 , V_64 ) ;
if ( V_28 )
goto V_119;
goto V_76;
}
if ( V_13 -> V_262 == V_107 -> V_263 &&
F_227 ( V_253 ) ) {
V_255 = V_264 ;
goto V_265;
}
F_228 ( V_253 ) -> V_266 = 0 ;
V_28 = F_229 ( V_107 , V_34 , V_253 ) ;
F_8 ( V_28 ) ;
if ( F_227 ( V_253 ) > 0 ) {
V_28 = F_230 ( V_34 ,
& V_34 -> V_36 -> V_267 ) ;
if ( V_28 )
goto V_265;
V_28 = F_231 ( V_34 , V_107 , V_64 ,
V_253 ) ;
if ( V_28 )
goto V_265;
}
F_11 ( & V_13 -> V_51 ) ;
if ( V_13 -> V_3 != V_4 ||
! F_232 ( V_34 , V_268 ) ) {
V_255 = V_260 ;
F_13 ( & V_13 -> V_51 ) ;
goto V_265;
}
F_13 ( & V_13 -> V_51 ) ;
V_257 = ( int ) F_233 ( V_13 -> V_20 . V_32 , 256 * 1024 * 1024 ) ;
if ( ! V_257 )
V_257 = 1 ;
V_257 *= 16 ;
V_257 *= V_269 ;
V_28 = F_234 ( V_253 , V_257 ) ;
if ( V_28 )
goto V_265;
V_28 = F_235 ( V_253 , V_107 , 0 , 0 , V_257 ,
V_257 , V_257 ,
& V_254 ) ;
if ( ! V_28 )
V_255 = V_264 ;
F_236 ( V_253 , V_257 ) ;
V_265:
F_237 ( V_253 ) ;
V_119:
F_43 ( V_64 ) ;
V_71:
F_11 ( & V_13 -> V_51 ) ;
if ( ! V_28 && V_255 == V_264 )
V_13 -> V_262 = V_107 -> V_263 ;
V_13 -> V_259 = V_255 ;
F_13 ( & V_13 -> V_51 ) ;
return V_28 ;
}
int F_238 ( struct V_106 * V_107 ,
struct V_33 * V_34 )
{
struct V_1 * V_2 ;
int V_79 = 0 ;
struct V_63 * V_64 ;
T_2 V_69 = 0 ;
V_64 = F_33 () ;
if ( ! V_64 )
return - V_88 ;
V_76:
while ( 1 ) {
V_2 = F_65 ( V_34 -> V_36 , V_69 ) ;
while ( V_2 ) {
if ( V_2 -> V_259 == V_270 )
break;
V_2 = F_221 ( V_34 , V_2 ) ;
}
if ( ! V_2 ) {
if ( V_69 == 0 )
break;
V_69 = 0 ;
continue;
}
V_79 = F_222 ( V_2 , V_107 , V_64 ) ;
V_69 = V_2 -> V_20 . V_21 + V_2 -> V_20 . V_32 ;
F_6 ( V_2 ) ;
}
while ( 1 ) {
if ( V_69 == 0 ) {
V_79 = F_184 ( V_107 , V_34 ,
( unsigned long ) - 1 ) ;
if ( V_79 )
goto V_71;
}
V_2 = F_65 ( V_34 -> V_36 , V_69 ) ;
while ( V_2 ) {
if ( V_2 -> V_259 == V_270 ) {
F_6 ( V_2 ) ;
goto V_76;
}
if ( V_2 -> V_271 )
break;
V_2 = F_221 ( V_34 , V_2 ) ;
}
if ( ! V_2 ) {
if ( V_69 == 0 )
break;
V_69 = 0 ;
continue;
}
if ( V_2 -> V_259 == V_264 )
V_2 -> V_259 = V_272 ;
V_2 -> V_271 = 0 ;
V_69 = V_2 -> V_20 . V_21 + V_2 -> V_20 . V_32 ;
V_79 = F_218 ( V_107 , V_34 , V_64 , V_2 ) ;
if ( V_79 )
goto V_71;
F_6 ( V_2 ) ;
}
while ( 1 ) {
if ( V_69 == 0 ) {
V_79 = F_184 ( V_107 , V_34 ,
( unsigned long ) - 1 ) ;
if ( V_79 )
goto V_71;
}
V_2 = F_65 ( V_34 -> V_36 , V_69 ) ;
while ( V_2 ) {
if ( V_2 -> V_271 ) {
F_6 ( V_2 ) ;
goto V_76;
}
if ( V_2 -> V_259 == V_272 )
break;
V_2 = F_221 ( V_34 , V_2 ) ;
}
if ( ! V_2 ) {
if ( V_69 == 0 )
break;
V_69 = 0 ;
continue;
}
V_79 = F_239 ( V_34 , V_107 , V_2 , V_64 ) ;
if ( ! V_79 && V_2 -> V_259 == V_272 )
V_2 -> V_259 = V_260 ;
V_69 = V_2 -> V_20 . V_21 + V_2 -> V_20 . V_32 ;
F_6 ( V_2 ) ;
}
V_71:
F_49 ( V_64 ) ;
return V_79 ;
}
int F_240 ( struct V_33 * V_34 , T_2 V_26 )
{
struct V_1 * V_13 ;
int V_273 = 0 ;
V_13 = F_66 ( V_34 -> V_36 , V_26 ) ;
if ( ! V_13 || V_13 -> V_261 )
V_273 = 1 ;
if ( V_13 )
F_6 ( V_13 ) ;
return V_273 ;
}
static int F_241 ( struct V_11 * V_12 , T_2 V_6 ,
T_2 V_274 , T_2 V_275 ,
struct V_99 * * V_102 )
{
struct V_99 * V_103 ;
int V_42 ;
int V_276 ;
if ( V_6 & ( V_277 | V_278 |
V_279 ) )
V_276 = 2 ;
else
V_276 = 1 ;
V_103 = F_67 ( V_12 , V_6 ) ;
if ( V_103 ) {
F_11 ( & V_103 -> V_51 ) ;
V_103 -> V_274 += V_274 ;
V_103 -> V_280 += V_274 * V_276 ;
V_103 -> V_275 += V_275 ;
V_103 -> V_281 += V_275 * V_276 ;
V_103 -> V_105 = 0 ;
F_13 ( & V_103 -> V_51 ) ;
* V_102 = V_103 ;
return 0 ;
}
V_103 = F_52 ( sizeof( * V_103 ) , V_39 ) ;
if ( ! V_103 )
return - V_88 ;
for ( V_42 = 0 ; V_42 < V_282 ; V_42 ++ )
F_53 ( & V_103 -> V_283 [ V_42 ] ) ;
F_242 ( & V_103 -> V_284 ) ;
F_243 ( & V_103 -> V_51 ) ;
V_103 -> V_6 = V_6 & V_104 ;
V_103 -> V_274 = V_274 ;
V_103 -> V_280 = V_274 * V_276 ;
V_103 -> V_275 = V_275 ;
V_103 -> V_281 = V_275 * V_276 ;
V_103 -> V_285 = 0 ;
V_103 -> V_286 = 0 ;
V_103 -> V_287 = 0 ;
V_103 -> V_288 = 0 ;
V_103 -> V_105 = 0 ;
V_103 -> V_289 = V_290 ;
V_103 -> V_291 = 0 ;
V_103 -> V_292 = 0 ;
F_55 ( & V_103 -> V_86 ) ;
* V_102 = V_103 ;
F_244 ( & V_103 -> V_89 , & V_12 -> V_102 ) ;
if ( V_6 & V_293 )
V_12 -> V_294 = V_103 ;
return 0 ;
}
static void F_245 ( struct V_11 * V_36 , T_2 V_6 )
{
T_2 V_295 = F_246 ( V_6 ) &
V_296 ;
F_247 ( & V_36 -> V_297 ) ;
if ( V_6 & V_293 )
V_36 -> V_298 |= V_295 ;
if ( V_6 & V_299 )
V_36 -> V_300 |= V_295 ;
if ( V_6 & V_301 )
V_36 -> V_302 |= V_295 ;
F_248 ( & V_36 -> V_297 ) ;
}
static T_2 F_249 ( struct V_11 * V_36 , T_2 V_6 )
{
struct V_303 * V_304 = V_36 -> V_305 ;
T_2 V_306 = 0 ;
if ( ! V_304 )
return 0 ;
if ( V_6 & V_293 &&
V_304 -> V_307 . V_6 & V_308 ) {
V_306 = V_293 | V_304 -> V_307 . V_306 ;
} else if ( V_6 & V_301 &&
V_304 -> V_309 . V_6 & V_308 ) {
V_306 = V_301 | V_304 -> V_309 . V_306 ;
} else if ( V_6 & V_299 &&
V_304 -> V_310 . V_6 & V_308 ) {
V_306 = V_299 | V_304 -> V_310 . V_306 ;
}
return V_306 ;
}
static T_2 F_250 ( struct V_33 * V_34 , T_2 V_6 )
{
T_2 V_311 = V_34 -> V_36 -> V_312 -> V_313 +
V_34 -> V_36 -> V_312 -> V_314 ;
T_2 V_306 ;
T_2 V_315 ;
F_11 ( & V_34 -> V_36 -> V_316 ) ;
V_306 = F_249 ( V_34 -> V_36 , V_6 ) ;
if ( V_306 ) {
if ( ( V_6 & V_306 ) & V_296 ) {
F_13 ( & V_34 -> V_36 -> V_316 ) ;
return F_251 ( V_306 ) ;
}
}
F_13 ( & V_34 -> V_36 -> V_316 ) ;
if ( V_311 == 1 )
V_6 &= ~ ( V_278 | V_317 |
V_318 ) ;
if ( V_311 < 3 )
V_6 &= ~ V_319 ;
if ( V_311 < 4 )
V_6 &= ~ V_279 ;
V_315 = V_6 & ( V_277 | V_317 |
V_278 | V_318 |
V_319 | V_279 ) ;
V_6 &= ~ V_315 ;
if ( V_315 & V_319 )
V_315 = V_319 ;
else if ( V_315 & V_318 )
V_315 = V_318 ;
else if ( V_315 & V_279 )
V_315 = V_279 ;
else if ( V_315 & V_278 )
V_315 = V_278 ;
else if ( V_315 & V_317 )
V_315 = V_317 ;
return F_251 ( V_6 | V_315 ) ;
}
static T_2 F_252 ( struct V_33 * V_34 , T_2 V_6 )
{
unsigned V_214 ;
do {
V_214 = F_253 ( & V_34 -> V_36 -> V_297 ) ;
if ( V_6 & V_293 )
V_6 |= V_34 -> V_36 -> V_298 ;
else if ( V_6 & V_301 )
V_6 |= V_34 -> V_36 -> V_302 ;
else if ( V_6 & V_299 )
V_6 |= V_34 -> V_36 -> V_300 ;
} while ( F_254 ( & V_34 -> V_36 -> V_297 , V_214 ) );
return F_250 ( V_34 , V_6 ) ;
}
T_2 F_255 ( struct V_33 * V_34 , int V_307 )
{
T_2 V_6 ;
T_2 V_28 ;
if ( V_307 )
V_6 = V_293 ;
else if ( V_34 == V_34 -> V_36 -> V_320 )
V_6 = V_301 ;
else
V_6 = V_299 ;
V_28 = F_252 ( V_34 , V_6 ) ;
return V_28 ;
}
int F_234 ( struct V_253 * V_253 , T_2 V_321 )
{
struct V_99 * V_294 ;
struct V_33 * V_34 = F_228 ( V_253 ) -> V_34 ;
struct V_11 * V_36 = V_34 -> V_36 ;
T_2 V_322 ;
int V_28 = 0 , V_323 = 0 , V_324 = 1 ;
V_321 = F_256 ( V_321 , V_34 -> V_325 ) ;
if ( V_34 == V_34 -> V_36 -> V_84 ||
F_228 ( V_253 ) -> V_326 . V_21 == V_327 ) {
V_324 = 0 ;
V_323 = 1 ;
}
V_294 = V_36 -> V_294 ;
if ( ! V_294 )
goto V_328;
V_76:
F_11 ( & V_294 -> V_51 ) ;
V_322 = V_294 -> V_275 + V_294 -> V_286 +
V_294 -> V_285 + V_294 -> V_287 +
V_294 -> V_288 ;
if ( V_322 + V_321 > V_294 -> V_274 ) {
struct V_106 * V_107 ;
if ( ! V_294 -> V_105 && V_324 ) {
T_2 V_329 ;
V_294 -> V_289 = V_330 ;
F_13 ( & V_294 -> V_51 ) ;
V_328:
V_329 = F_255 ( V_34 , 1 ) ;
V_107 = F_257 ( V_34 ) ;
if ( F_224 ( V_107 ) )
return F_225 ( V_107 ) ;
V_28 = F_258 ( V_107 , V_34 -> V_36 -> V_62 ,
V_329 ,
V_290 ) ;
F_259 ( V_107 , V_34 ) ;
if ( V_28 < 0 ) {
if ( V_28 != - V_331 )
return V_28 ;
else
goto V_332;
}
if ( ! V_294 )
V_294 = V_36 -> V_294 ;
goto V_76;
}
if ( V_294 -> V_285 < V_321 )
V_323 = 1 ;
F_13 ( & V_294 -> V_51 ) ;
V_332:
if ( ! V_323 &&
! F_183 ( & V_34 -> V_36 -> V_333 ) ) {
V_323 = 1 ;
V_107 = F_257 ( V_34 ) ;
if ( F_224 ( V_107 ) )
return F_225 ( V_107 ) ;
V_28 = F_260 ( V_107 , V_34 ) ;
if ( V_28 )
return V_28 ;
goto V_76;
}
return - V_331 ;
}
V_294 -> V_288 += V_321 ;
F_261 ( V_34 -> V_36 , L_6 ,
V_294 -> V_6 , V_321 , 1 ) ;
F_13 ( & V_294 -> V_51 ) ;
return 0 ;
}
void F_236 ( struct V_253 * V_253 , T_2 V_321 )
{
struct V_33 * V_34 = F_228 ( V_253 ) -> V_34 ;
struct V_99 * V_294 ;
V_321 = F_256 ( V_321 , V_34 -> V_325 ) ;
V_294 = V_34 -> V_36 -> V_294 ;
F_11 ( & V_294 -> V_51 ) ;
V_294 -> V_288 -= V_321 ;
F_261 ( V_34 -> V_36 , L_6 ,
V_294 -> V_6 , V_321 , 0 ) ;
F_13 ( & V_294 -> V_51 ) ;
}
static void F_262 ( struct V_11 * V_12 )
{
struct V_100 * V_101 = & V_12 -> V_102 ;
struct V_99 * V_103 ;
F_68 () ;
F_69 (found, head, list) {
if ( V_103 -> V_6 & V_299 )
V_103 -> V_289 = V_330 ;
}
F_70 () ;
}
static inline T_2 F_263 ( struct V_334 * V_335 )
{
return ( V_335 -> V_56 << 1 ) ;
}
static int F_264 ( struct V_33 * V_34 ,
struct V_99 * V_336 , int V_337 )
{
struct V_334 * V_338 = & V_34 -> V_36 -> V_267 ;
T_2 V_35 = V_336 -> V_274 - V_336 -> V_287 ;
T_2 V_339 = V_336 -> V_275 + V_336 -> V_286 ;
T_2 V_340 ;
if ( V_337 == V_330 )
return 1 ;
if ( V_336 -> V_6 & V_299 )
V_339 += F_263 ( V_338 ) ;
if ( V_337 == V_341 ) {
V_340 = F_265 ( V_34 -> V_36 -> V_342 ) ;
V_340 = F_34 ( T_2 , 64 * 1024 * 1024 ,
F_266 ( V_340 , 1 ) ) ;
if ( V_35 - V_339 < V_340 )
return 1 ;
}
if ( V_339 + 2 * 1024 * 1024 < F_267 ( V_35 , 8 ) )
return 0 ;
return 1 ;
}
static T_2 F_268 ( struct V_33 * V_34 , T_2 type )
{
T_2 V_343 ;
if ( type & ( V_279 |
V_317 |
V_318 |
V_319 ) )
V_343 = V_34 -> V_36 -> V_312 -> V_313 ;
else if ( type & V_278 )
V_343 = 2 ;
else
V_343 = 1 ;
return F_269 ( V_34 , V_343 + 1 ) ;
}
static void F_270 ( struct V_106 * V_107 ,
struct V_33 * V_34 , T_2 type )
{
struct V_99 * V_12 ;
T_2 V_344 ;
T_2 V_340 ;
V_12 = F_67 ( V_34 -> V_36 , V_301 ) ;
F_11 ( & V_12 -> V_51 ) ;
V_344 = V_12 -> V_274 - V_12 -> V_275 - V_12 -> V_285 -
V_12 -> V_286 - V_12 -> V_287 ;
F_13 ( & V_12 -> V_51 ) ;
V_340 = F_268 ( V_34 , type ) ;
if ( V_344 < V_340 && F_232 ( V_34 , V_345 ) ) {
F_271 ( V_34 -> V_36 , L_7 ,
V_344 , V_340 , type ) ;
F_272 ( V_12 , 0 , 0 ) ;
}
if ( V_344 < V_340 ) {
T_2 V_6 ;
V_6 = F_255 ( V_34 -> V_36 -> V_320 , 0 ) ;
F_273 ( V_107 , V_34 , V_6 ) ;
}
}
static int F_258 ( struct V_106 * V_107 ,
struct V_33 * V_62 , T_2 V_6 , int V_337 )
{
struct V_99 * V_102 ;
struct V_11 * V_36 = V_62 -> V_36 ;
int V_346 = 0 ;
int V_28 = 0 ;
if ( V_107 -> V_347 )
return - V_331 ;
V_102 = F_67 ( V_62 -> V_36 , V_6 ) ;
if ( ! V_102 ) {
V_28 = F_241 ( V_62 -> V_36 , V_6 ,
0 , 0 , & V_102 ) ;
F_30 ( V_28 ) ;
}
F_30 ( ! V_102 ) ;
V_76:
F_11 ( & V_102 -> V_51 ) ;
if ( V_337 < V_102 -> V_289 )
V_337 = V_102 -> V_289 ;
if ( V_102 -> V_105 ) {
F_13 ( & V_102 -> V_51 ) ;
return 0 ;
}
if ( ! F_264 ( V_62 , V_102 , V_337 ) ) {
F_13 ( & V_102 -> V_51 ) ;
return 0 ;
} else if ( V_102 -> V_291 ) {
V_346 = 1 ;
} else {
V_102 -> V_291 = 1 ;
}
F_13 ( & V_102 -> V_51 ) ;
F_35 ( & V_36 -> V_348 ) ;
if ( V_346 ) {
F_45 ( & V_36 -> V_348 ) ;
V_346 = 0 ;
goto V_76;
}
V_107 -> V_347 = true ;
if ( F_274 ( V_102 ) )
V_6 |= ( V_293 | V_299 ) ;
if ( V_6 & V_293 && V_36 -> V_349 ) {
V_36 -> V_350 ++ ;
if ( ! ( V_36 -> V_350 %
V_36 -> V_349 ) )
F_262 ( V_36 ) ;
}
F_270 ( V_107 , V_62 , V_6 ) ;
V_28 = F_273 ( V_107 , V_62 , V_6 ) ;
V_107 -> V_347 = false ;
F_11 ( & V_102 -> V_51 ) ;
if ( V_28 < 0 && V_28 != - V_331 )
goto V_71;
if ( V_28 )
V_102 -> V_105 = 1 ;
else
V_28 = 1 ;
V_102 -> V_289 = V_290 ;
V_71:
V_102 -> V_291 = 0 ;
F_13 ( & V_102 -> V_51 ) ;
F_45 ( & V_36 -> V_348 ) ;
return V_28 ;
}
static int F_275 ( struct V_33 * V_34 ,
struct V_99 * V_102 , T_2 V_321 ,
enum V_351 V_292 )
{
struct V_334 * V_338 = & V_34 -> V_36 -> V_267 ;
T_2 V_352 = F_255 ( V_34 , 0 ) ;
T_2 V_353 ;
T_2 V_354 ;
T_2 V_322 ;
T_2 V_355 ;
V_322 = V_102 -> V_275 + V_102 -> V_286 +
V_102 -> V_285 + V_102 -> V_287 ;
F_11 ( & V_338 -> V_51 ) ;
V_353 = F_263 ( V_338 ) ;
F_13 ( & V_338 -> V_51 ) ;
if ( V_322 + V_353 >= V_102 -> V_274 )
return 0 ;
V_322 += V_102 -> V_288 ;
F_11 ( & V_34 -> V_36 -> V_356 ) ;
V_354 = V_34 -> V_36 -> V_357 ;
F_13 ( & V_34 -> V_36 -> V_356 ) ;
if ( V_352 & ( V_277 |
V_278 |
V_279 ) )
V_354 >>= 1 ;
V_355 = V_102 -> V_274 ;
if ( V_292 == V_358 )
V_355 >>= 3 ;
else
V_355 >>= 1 ;
V_355 = F_276 ( V_354 , V_355 ) ;
if ( V_322 + V_321 < V_102 -> V_274 + V_355 )
return 1 ;
return 0 ;
}
static void F_277 ( struct V_33 * V_34 ,
unsigned long V_359 )
{
struct V_360 * V_361 = V_34 -> V_36 -> V_361 ;
int V_362 ;
V_362 = F_278 ( V_361 , V_359 ,
V_363 ) ;
if ( ! V_362 ) {
F_279 ( V_34 , 0 ) ;
if ( ! V_364 -> V_365 )
F_280 ( V_34 , 0 ) ;
}
}
static void F_281 ( struct V_33 * V_34 , T_2 V_366 , T_2 V_367 ,
bool V_368 )
{
struct V_334 * V_369 ;
struct V_99 * V_102 ;
struct V_106 * V_107 ;
T_2 V_370 ;
T_2 V_371 ;
long V_372 ;
unsigned long V_359 = ( 2 * 1024 * 1024 ) >> V_373 ;
int V_232 = 0 ;
enum V_351 V_292 ;
V_107 = (struct V_106 * ) V_364 -> V_365 ;
V_369 = & V_34 -> V_36 -> V_374 ;
V_102 = V_369 -> V_102 ;
F_2 () ;
V_370 = F_282 (
& V_34 -> V_36 -> V_370 ) ;
if ( V_370 == 0 ) {
if ( V_107 )
return;
F_280 ( V_34 , 0 ) ;
return;
}
while ( V_370 && V_232 < 3 ) {
V_371 = F_276 ( V_370 , V_366 ) ;
V_359 = V_371 >> V_373 ;
F_277 ( V_34 , V_359 ) ;
F_283 ( V_34 -> V_36 -> V_375 ,
! F_183 ( & V_34 -> V_36 -> V_376 ) ) ;
if ( ! V_107 )
V_292 = V_358 ;
else
V_292 = V_377 ;
F_11 ( & V_102 -> V_51 ) ;
if ( F_275 ( V_34 , V_102 , V_367 , V_292 ) ) {
F_13 ( & V_102 -> V_51 ) ;
break;
}
F_13 ( & V_102 -> V_51 ) ;
V_232 ++ ;
if ( V_368 && ! V_107 ) {
F_280 ( V_34 , 0 ) ;
} else {
V_372 = F_284 ( 1 ) ;
if ( V_372 )
break;
}
F_2 () ;
V_370 = F_282 (
& V_34 -> V_36 -> V_370 ) ;
}
}
static int F_285 ( struct V_33 * V_34 ,
struct V_99 * V_102 ,
T_2 V_321 , int V_337 )
{
struct V_334 * V_378 = & V_34 -> V_36 -> V_379 ;
struct V_106 * V_107 ;
V_107 = (struct V_106 * ) V_364 -> V_365 ;
if ( V_107 )
return - V_173 ;
if ( V_337 )
goto V_380;
F_11 ( & V_102 -> V_51 ) ;
if ( V_102 -> V_285 >= V_321 ) {
F_13 ( & V_102 -> V_51 ) ;
goto V_380;
}
F_13 ( & V_102 -> V_51 ) ;
if ( V_102 != V_378 -> V_102 )
return - V_331 ;
F_11 ( & V_102 -> V_51 ) ;
F_11 ( & V_378 -> V_51 ) ;
if ( V_102 -> V_285 + V_378 -> V_56 < V_321 ) {
F_13 ( & V_378 -> V_51 ) ;
F_13 ( & V_102 -> V_51 ) ;
return - V_331 ;
}
F_13 ( & V_378 -> V_51 ) ;
F_13 ( & V_102 -> V_51 ) ;
V_380:
V_107 = F_257 ( V_34 ) ;
if ( F_224 ( V_107 ) )
return - V_331 ;
return F_260 ( V_107 , V_34 ) ;
}
static int F_286 ( struct V_33 * V_34 ,
struct V_99 * V_102 , T_2 V_35 ,
T_2 V_381 , int V_382 )
{
struct V_106 * V_107 ;
int V_43 ;
int V_28 = 0 ;
switch ( V_382 ) {
case V_383 :
case V_384 :
if ( V_382 == V_383 ) {
T_2 V_321 = F_269 ( V_34 , 1 ) ;
V_43 = ( int ) F_233 ( V_35 , V_321 ) ;
if ( ! V_43 )
V_43 = 1 ;
V_43 *= 2 ;
} else {
V_43 = - 1 ;
}
V_107 = F_257 ( V_34 ) ;
if ( F_224 ( V_107 ) ) {
V_28 = F_225 ( V_107 ) ;
break;
}
V_28 = F_287 ( V_107 , V_34 , V_43 ) ;
F_259 ( V_107 , V_34 ) ;
break;
case V_385 :
case V_386 :
F_281 ( V_34 , V_35 , V_381 ,
V_382 == V_386 ) ;
break;
case V_387 :
V_107 = F_257 ( V_34 ) ;
if ( F_224 ( V_107 ) ) {
V_28 = F_225 ( V_107 ) ;
break;
}
V_28 = F_258 ( V_107 , V_34 -> V_36 -> V_62 ,
F_255 ( V_34 , 0 ) ,
V_290 ) ;
F_259 ( V_107 , V_34 ) ;
if ( V_28 == - V_331 )
V_28 = 0 ;
break;
case V_388 :
V_28 = F_285 ( V_34 , V_102 , V_381 , 0 ) ;
break;
default:
V_28 = - V_331 ;
break;
}
return V_28 ;
}
static int F_288 ( struct V_33 * V_34 ,
struct V_334 * V_369 ,
T_2 V_381 ,
enum V_351 V_292 )
{
struct V_99 * V_102 = V_369 -> V_102 ;
T_2 V_322 ;
T_2 V_35 = V_381 ;
int V_389 = V_383 ;
int V_28 = 0 ;
bool V_390 = false ;
V_76:
V_28 = 0 ;
F_11 ( & V_102 -> V_51 ) ;
while ( V_292 == V_358 && ! V_390 &&
V_102 -> V_292 ) {
F_13 ( & V_102 -> V_51 ) ;
if ( V_364 -> V_365 )
return - V_173 ;
V_28 = F_289 ( V_102 -> V_86 , ! V_102 -> V_292 ) ;
if ( V_28 )
return - V_391 ;
F_11 ( & V_102 -> V_51 ) ;
}
V_28 = - V_331 ;
V_322 = V_102 -> V_275 + V_102 -> V_286 +
V_102 -> V_285 + V_102 -> V_287 +
V_102 -> V_288 ;
if ( V_322 <= V_102 -> V_274 ) {
if ( V_322 + V_381 <= V_102 -> V_274 ) {
V_102 -> V_288 += V_381 ;
F_261 ( V_34 -> V_36 ,
L_6 , V_102 -> V_6 , V_381 , 1 ) ;
V_28 = 0 ;
} else {
V_35 = V_381 ;
}
} else {
V_35 = V_322 - V_102 -> V_274 +
( V_381 * 2 ) ;
}
if ( V_28 && F_275 ( V_34 , V_102 , V_381 , V_292 ) ) {
V_102 -> V_288 += V_381 ;
F_261 ( V_34 -> V_36 , L_6 ,
V_102 -> V_6 , V_381 ,
1 ) ;
V_28 = 0 ;
}
if ( V_28 && V_292 != V_377 ) {
V_390 = true ;
V_102 -> V_292 = 1 ;
}
F_13 ( & V_102 -> V_51 ) ;
if ( ! V_28 || V_292 == V_377 )
goto V_71;
V_28 = F_286 ( V_34 , V_102 , V_35 , V_381 ,
V_389 ) ;
V_389 ++ ;
if ( V_292 == V_392 &&
( V_389 == V_385 ||
V_389 == V_386 ) )
V_389 = V_387 ;
if ( ! V_28 )
goto V_76;
else if ( V_292 == V_392 &&
V_389 < V_388 )
goto V_76;
else if ( V_292 == V_358 &&
V_389 <= V_388 )
goto V_76;
V_71:
if ( V_28 == - V_331 &&
F_290 ( V_34 -> V_393 == V_394 ) ) {
struct V_334 * V_338 =
& V_34 -> V_36 -> V_267 ;
if ( V_369 != V_338 &&
! F_291 ( V_338 , V_381 ) )
V_28 = 0 ;
}
if ( V_390 ) {
F_11 ( & V_102 -> V_51 ) ;
V_102 -> V_292 = 0 ;
F_292 ( & V_102 -> V_86 ) ;
F_13 ( & V_102 -> V_51 ) ;
}
return V_28 ;
}
static struct V_334 * F_293 (
const struct V_106 * V_107 ,
const struct V_33 * V_34 )
{
struct V_334 * V_369 = NULL ;
if ( V_34 -> V_249 )
V_369 = V_107 -> V_369 ;
if ( V_34 == V_34 -> V_36 -> V_395 && V_107 -> V_396 )
V_369 = V_107 -> V_369 ;
if ( ! V_369 )
V_369 = V_34 -> V_369 ;
if ( ! V_369 )
V_369 = & V_34 -> V_36 -> V_397 ;
return V_369 ;
}
static int F_291 ( struct V_334 * V_369 ,
T_2 V_35 )
{
int V_28 = - V_331 ;
F_11 ( & V_369 -> V_51 ) ;
if ( V_369 -> V_9 >= V_35 ) {
V_369 -> V_9 -= V_35 ;
if ( V_369 -> V_9 < V_369 -> V_56 )
V_369 -> V_105 = 0 ;
V_28 = 0 ;
}
F_13 ( & V_369 -> V_51 ) ;
return V_28 ;
}
static void F_294 ( struct V_334 * V_369 ,
T_2 V_35 , int V_398 )
{
F_11 ( & V_369 -> V_51 ) ;
V_369 -> V_9 += V_35 ;
if ( V_398 )
V_369 -> V_56 += V_35 ;
else if ( V_369 -> V_9 >= V_369 -> V_56 )
V_369 -> V_105 = 1 ;
F_13 ( & V_369 -> V_51 ) ;
}
static void F_295 ( struct V_11 * V_36 ,
struct V_334 * V_369 ,
struct V_334 * V_399 , T_2 V_35 )
{
struct V_99 * V_102 = V_369 -> V_102 ;
F_11 ( & V_369 -> V_51 ) ;
if ( V_35 == ( T_2 ) - 1 )
V_35 = V_369 -> V_56 ;
V_369 -> V_56 -= V_35 ;
if ( V_369 -> V_9 >= V_369 -> V_56 ) {
V_35 = V_369 -> V_9 - V_369 -> V_56 ;
V_369 -> V_9 = V_369 -> V_56 ;
V_369 -> V_105 = 1 ;
} else {
V_35 = 0 ;
}
F_13 ( & V_369 -> V_51 ) ;
if ( V_35 > 0 ) {
if ( V_399 ) {
F_11 ( & V_399 -> V_51 ) ;
if ( ! V_399 -> V_105 ) {
T_2 V_400 ;
V_400 = V_399 -> V_56 - V_399 -> V_9 ;
V_400 = F_276 ( V_35 , V_400 ) ;
V_399 -> V_9 += V_400 ;
if ( V_399 -> V_9 >= V_399 -> V_56 )
V_399 -> V_105 = 1 ;
V_35 -= V_400 ;
}
F_13 ( & V_399 -> V_51 ) ;
}
if ( V_35 ) {
F_11 ( & V_102 -> V_51 ) ;
V_102 -> V_288 -= V_35 ;
F_261 ( V_36 , L_6 ,
V_102 -> V_6 , V_35 , 0 ) ;
V_102 -> V_401 ++ ;
F_13 ( & V_102 -> V_51 ) ;
}
}
}
static int F_296 ( struct V_334 * V_402 ,
struct V_334 * V_403 , T_2 V_35 )
{
int V_28 ;
V_28 = F_291 ( V_402 , V_35 ) ;
if ( V_28 )
return V_28 ;
F_294 ( V_403 , V_35 , 1 ) ;
return 0 ;
}
void F_297 ( struct V_334 * V_404 , unsigned short type )
{
memset ( V_404 , 0 , sizeof( * V_404 ) ) ;
F_243 ( & V_404 -> V_51 ) ;
V_404 -> type = type ;
}
struct V_334 * F_298 ( struct V_33 * V_34 ,
unsigned short type )
{
struct V_334 * V_369 ;
struct V_11 * V_36 = V_34 -> V_36 ;
V_369 = F_299 ( sizeof( * V_369 ) , V_39 ) ;
if ( ! V_369 )
return NULL ;
F_297 ( V_369 , type ) ;
V_369 -> V_102 = F_67 ( V_36 ,
V_299 ) ;
return V_369 ;
}
void F_300 ( struct V_33 * V_34 ,
struct V_334 * V_404 )
{
if ( ! V_404 )
return;
F_301 ( V_34 , V_404 , ( T_2 ) - 1 ) ;
F_9 ( V_404 ) ;
}
int F_302 ( struct V_33 * V_34 ,
struct V_334 * V_369 , T_2 V_35 ,
enum V_351 V_292 )
{
int V_28 ;
if ( V_35 == 0 )
return 0 ;
V_28 = F_288 ( V_34 , V_369 , V_35 , V_292 ) ;
if ( ! V_28 ) {
F_294 ( V_369 , V_35 , 1 ) ;
return 0 ;
}
return V_28 ;
}
int F_303 ( struct V_33 * V_34 ,
struct V_334 * V_369 , int V_405 )
{
T_2 V_35 = 0 ;
int V_28 = - V_331 ;
if ( ! V_369 )
return 0 ;
F_11 ( & V_369 -> V_51 ) ;
V_35 = F_267 ( V_369 -> V_56 , V_405 ) ;
if ( V_369 -> V_9 >= V_35 )
V_28 = 0 ;
F_13 ( & V_369 -> V_51 ) ;
return V_28 ;
}
int F_304 ( struct V_33 * V_34 ,
struct V_334 * V_369 , T_2 V_406 ,
enum V_351 V_292 )
{
T_2 V_35 = 0 ;
int V_28 = - V_331 ;
if ( ! V_369 )
return 0 ;
F_11 ( & V_369 -> V_51 ) ;
V_35 = V_406 ;
if ( V_369 -> V_9 >= V_35 )
V_28 = 0 ;
else
V_35 -= V_369 -> V_9 ;
F_13 ( & V_369 -> V_51 ) ;
if ( ! V_28 )
return 0 ;
V_28 = F_288 ( V_34 , V_369 , V_35 , V_292 ) ;
if ( ! V_28 ) {
F_294 ( V_369 , V_35 , 0 ) ;
return 0 ;
}
return V_28 ;
}
int F_305 ( struct V_334 * V_407 ,
struct V_334 * V_408 ,
T_2 V_35 )
{
return F_296 ( V_407 , V_408 , V_35 ) ;
}
void F_301 ( struct V_33 * V_34 ,
struct V_334 * V_369 ,
T_2 V_35 )
{
struct V_334 * V_338 = & V_34 -> V_36 -> V_267 ;
if ( V_338 -> V_105 || V_338 == V_369 ||
V_369 -> V_102 != V_338 -> V_102 )
V_338 = NULL ;
F_295 ( V_34 -> V_36 , V_369 , V_338 ,
V_35 ) ;
}
static T_2 F_306 ( struct V_11 * V_36 )
{
struct V_99 * V_336 ;
T_2 V_35 ;
T_2 V_409 ;
T_2 V_410 ;
int V_411 = F_307 ( V_36 -> V_342 ) ;
V_336 = F_67 ( V_36 , V_293 ) ;
F_11 ( & V_336 -> V_51 ) ;
V_410 = V_336 -> V_275 ;
F_13 ( & V_336 -> V_51 ) ;
V_336 = F_67 ( V_36 , V_299 ) ;
F_11 ( & V_336 -> V_51 ) ;
if ( V_336 -> V_6 & V_293 )
V_410 = 0 ;
V_409 = V_336 -> V_275 ;
F_13 ( & V_336 -> V_51 ) ;
V_35 = ( V_410 >> V_36 -> V_361 -> V_412 ) *
V_411 * 2 ;
V_35 += F_233 ( V_410 + V_409 , 50 ) ;
if ( V_35 * 3 > V_409 )
V_35 = F_233 ( V_409 , 3 ) ;
return F_256 ( V_35 , V_36 -> V_62 -> V_85 << 10 ) ;
}
static void F_308 ( struct V_11 * V_36 )
{
struct V_334 * V_369 = & V_36 -> V_267 ;
struct V_99 * V_336 = V_369 -> V_102 ;
T_2 V_35 ;
V_35 = F_306 ( V_36 ) ;
F_11 ( & V_336 -> V_51 ) ;
F_11 ( & V_369 -> V_51 ) ;
V_369 -> V_56 = F_24 ( T_2 , V_35 , 512 * 1024 * 1024 ) ;
V_35 = V_336 -> V_275 + V_336 -> V_285 +
V_336 -> V_286 + V_336 -> V_287 +
V_336 -> V_288 ;
if ( V_336 -> V_274 > V_35 ) {
V_35 = V_336 -> V_274 - V_35 ;
V_369 -> V_9 += V_35 ;
V_336 -> V_288 += V_35 ;
F_261 ( V_36 , L_6 ,
V_336 -> V_6 , V_35 , 1 ) ;
}
if ( V_369 -> V_9 >= V_369 -> V_56 ) {
V_35 = V_369 -> V_9 - V_369 -> V_56 ;
V_336 -> V_288 -= V_35 ;
F_261 ( V_36 , L_6 ,
V_336 -> V_6 , V_35 , 0 ) ;
V_336 -> V_401 ++ ;
V_369 -> V_9 = V_369 -> V_56 ;
V_369 -> V_105 = 1 ;
}
F_13 ( & V_369 -> V_51 ) ;
F_13 ( & V_336 -> V_51 ) ;
}
static void F_309 ( struct V_11 * V_36 )
{
struct V_99 * V_102 ;
V_102 = F_67 ( V_36 , V_301 ) ;
V_36 -> V_413 . V_102 = V_102 ;
V_102 = F_67 ( V_36 , V_299 ) ;
V_36 -> V_267 . V_102 = V_102 ;
V_36 -> V_374 . V_102 = V_102 ;
V_36 -> V_414 . V_102 = V_102 ;
V_36 -> V_397 . V_102 = V_102 ;
V_36 -> V_379 . V_102 = V_102 ;
V_36 -> V_62 -> V_369 = & V_36 -> V_267 ;
V_36 -> V_395 -> V_369 = & V_36 -> V_267 ;
V_36 -> V_415 -> V_369 = & V_36 -> V_267 ;
V_36 -> V_84 -> V_369 = & V_36 -> V_267 ;
if ( V_36 -> V_416 )
V_36 -> V_416 -> V_369 = & V_36 -> V_267 ;
V_36 -> V_320 -> V_369 = & V_36 -> V_413 ;
F_308 ( V_36 ) ;
}
static void F_310 ( struct V_11 * V_36 )
{
F_295 ( V_36 , & V_36 -> V_267 , NULL ,
( T_2 ) - 1 ) ;
F_8 ( V_36 -> V_374 . V_56 > 0 ) ;
F_8 ( V_36 -> V_374 . V_9 > 0 ) ;
F_8 ( V_36 -> V_414 . V_56 > 0 ) ;
F_8 ( V_36 -> V_414 . V_9 > 0 ) ;
F_8 ( V_36 -> V_413 . V_56 > 0 ) ;
F_8 ( V_36 -> V_413 . V_9 > 0 ) ;
F_8 ( V_36 -> V_379 . V_56 > 0 ) ;
F_8 ( V_36 -> V_379 . V_9 > 0 ) ;
}
void F_311 ( struct V_106 * V_107 ,
struct V_33 * V_34 )
{
if ( ! V_107 -> V_369 )
return;
if ( ! V_107 -> V_286 )
return;
F_261 ( V_34 -> V_36 , L_8 ,
V_107 -> V_263 , V_107 -> V_286 , 0 ) ;
F_301 ( V_34 , V_107 -> V_369 , V_107 -> V_286 ) ;
V_107 -> V_286 = 0 ;
}
int F_312 ( struct V_106 * V_107 ,
struct V_253 * V_253 )
{
struct V_33 * V_34 = F_228 ( V_253 ) -> V_34 ;
struct V_334 * V_407 = F_293 ( V_107 , V_34 ) ;
struct V_334 * V_408 = V_34 -> V_417 ;
T_2 V_35 = F_269 ( V_34 , 1 ) ;
F_261 ( V_34 -> V_36 , L_9 ,
F_313 ( V_253 ) , V_35 , 1 ) ;
return F_296 ( V_407 , V_408 , V_35 ) ;
}
void F_314 ( struct V_253 * V_253 )
{
struct V_33 * V_34 = F_228 ( V_253 ) -> V_34 ;
T_2 V_35 = F_269 ( V_34 , 1 ) ;
F_261 ( V_34 -> V_36 , L_9 ,
F_313 ( V_253 ) , V_35 , 0 ) ;
F_301 ( V_34 , V_34 -> V_417 , V_35 ) ;
}
int F_315 ( struct V_33 * V_34 ,
struct V_334 * V_404 ,
int V_418 ,
T_2 * V_419 )
{
T_2 V_35 ;
int V_28 ;
if ( V_34 -> V_36 -> V_420 ) {
V_35 = 3 * V_34 -> V_85 ;
V_28 = F_316 ( V_34 , V_35 ) ;
if ( V_28 )
return V_28 ;
} else {
V_35 = 0 ;
}
* V_419 = V_35 ;
V_35 = F_269 ( V_34 , V_418 ) ;
V_404 -> V_102 = F_67 ( V_34 -> V_36 ,
V_299 ) ;
V_28 = F_302 ( V_34 , V_404 , V_35 ,
V_358 ) ;
if ( V_28 ) {
if ( * V_419 )
F_317 ( V_34 , * V_419 ) ;
}
return V_28 ;
}
void F_318 ( struct V_33 * V_34 ,
struct V_334 * V_404 ,
T_2 V_419 )
{
F_301 ( V_34 , V_404 , ( T_2 ) - 1 ) ;
if ( V_419 )
F_317 ( V_34 , V_419 ) ;
}
static unsigned F_319 ( struct V_253 * V_253 )
{
unsigned V_421 = 0 ;
unsigned V_422 = 0 ;
F_30 ( ! F_228 ( V_253 ) -> V_423 ) ;
F_228 ( V_253 ) -> V_423 -- ;
if ( F_228 ( V_253 ) -> V_423 == 0 &&
F_320 ( V_424 ,
& F_228 ( V_253 ) -> V_425 ) )
V_421 = 1 ;
if ( F_228 ( V_253 ) -> V_423 >=
F_228 ( V_253 ) -> V_426 )
return V_421 ;
V_422 = F_228 ( V_253 ) -> V_426 -
F_228 ( V_253 ) -> V_423 ;
F_228 ( V_253 ) -> V_426 -= V_422 ;
return V_422 + V_421 ;
}
static T_2 F_321 ( struct V_253 * V_253 , T_2 V_35 ,
int V_427 )
{
struct V_33 * V_34 = F_228 ( V_253 ) -> V_34 ;
T_2 V_411 ;
int V_428 ;
int V_429 ;
int V_430 ;
if ( F_228 ( V_253 ) -> V_6 & V_431 &&
F_228 ( V_253 ) -> V_432 == 0 )
return 0 ;
V_430 = ( int ) F_233 ( F_228 ( V_253 ) -> V_432 , V_34 -> V_325 ) ;
if ( V_427 )
F_228 ( V_253 ) -> V_432 += V_35 ;
else
F_228 ( V_253 ) -> V_432 -= V_35 ;
V_411 = F_322 ( V_34 ) - sizeof( struct V_433 ) ;
V_428 = ( int ) F_233 ( V_411 ,
sizeof( struct V_434 ) +
sizeof( struct V_435 ) ) ;
V_429 = ( int ) F_233 ( F_228 ( V_253 ) -> V_432 , V_34 -> V_325 ) ;
V_429 = V_429 + V_428 - 1 ;
V_429 = V_429 / V_428 ;
V_430 = V_430 + V_428 - 1 ;
V_430 = V_430 / V_428 ;
if ( V_430 == V_429 )
return 0 ;
if ( V_427 )
return F_269 ( V_34 ,
V_429 - V_430 ) ;
return F_269 ( V_34 , V_430 - V_429 ) ;
}
int F_323 ( struct V_253 * V_253 , T_2 V_35 )
{
struct V_33 * V_34 = F_228 ( V_253 ) -> V_34 ;
struct V_334 * V_369 = & V_34 -> V_36 -> V_374 ;
T_2 V_436 = 0 ;
T_2 V_432 ;
unsigned V_437 = 0 ;
int V_438 = 0 ;
enum V_351 V_292 = V_358 ;
int V_28 = 0 ;
bool V_439 = true ;
T_2 V_440 = 0 ;
unsigned V_441 ;
if ( F_324 ( V_253 ) ) {
V_292 = V_377 ;
V_439 = false ;
}
if ( V_292 != V_377 &&
F_325 ( V_34 -> V_36 ) )
F_193 ( 1 ) ;
if ( V_439 )
F_35 ( & F_228 ( V_253 ) -> V_442 ) ;
V_35 = F_256 ( V_35 , V_34 -> V_325 ) ;
F_11 ( & F_228 ( V_253 ) -> V_51 ) ;
F_228 ( V_253 ) -> V_423 ++ ;
if ( F_228 ( V_253 ) -> V_423 >
F_228 ( V_253 ) -> V_426 )
V_437 = F_228 ( V_253 ) -> V_423 -
F_228 ( V_253 ) -> V_426 ;
if ( ! F_326 ( V_424 ,
& F_228 ( V_253 ) -> V_425 ) ) {
V_437 ++ ;
V_438 = 1 ;
}
V_436 = F_269 ( V_34 , V_437 ) ;
V_436 += F_321 ( V_253 , V_35 , 1 ) ;
V_432 = F_228 ( V_253 ) -> V_432 ;
F_13 ( & F_228 ( V_253 ) -> V_51 ) ;
if ( V_34 -> V_36 -> V_420 ) {
V_28 = F_316 ( V_34 , V_35 +
V_437 * V_34 -> V_85 ) ;
if ( V_28 )
goto V_443;
}
V_28 = F_288 ( V_34 , V_369 , V_436 , V_292 ) ;
if ( F_290 ( V_28 ) ) {
if ( V_34 -> V_36 -> V_420 )
F_317 ( V_34 , V_35 +
V_437 * V_34 -> V_85 ) ;
goto V_443;
}
F_11 ( & F_228 ( V_253 ) -> V_51 ) ;
if ( V_438 ) {
F_327 ( V_424 ,
& F_228 ( V_253 ) -> V_425 ) ;
V_437 -- ;
}
F_228 ( V_253 ) -> V_426 += V_437 ;
F_13 ( & F_228 ( V_253 ) -> V_51 ) ;
if ( V_439 )
F_45 ( & F_228 ( V_253 ) -> V_442 ) ;
if ( V_436 )
F_261 ( V_34 -> V_36 , L_10 ,
F_313 ( V_253 ) , V_436 , 1 ) ;
F_294 ( V_369 , V_436 , 1 ) ;
return 0 ;
V_443:
F_11 ( & F_228 ( V_253 ) -> V_51 ) ;
V_441 = F_319 ( V_253 ) ;
if ( F_228 ( V_253 ) -> V_432 == V_432 ) {
F_321 ( V_253 , V_35 , 0 ) ;
} else {
T_2 V_444 = F_228 ( V_253 ) -> V_432 ;
T_2 V_321 ;
V_321 = V_432 - F_228 ( V_253 ) -> V_432 ;
F_228 ( V_253 ) -> V_432 = V_432 ;
V_440 = F_321 ( V_253 , V_321 , 0 ) ;
F_228 ( V_253 ) -> V_432 = V_432 - V_35 ;
V_321 = V_432 - V_444 ;
V_321 = F_321 ( V_253 , V_321 , 0 ) ;
F_228 ( V_253 ) -> V_432 = V_444 - V_35 ;
if ( V_321 > V_440 )
V_440 = V_321 - V_440 ;
else
V_440 = 0 ;
}
F_13 ( & F_228 ( V_253 ) -> V_51 ) ;
if ( V_441 )
V_440 += F_269 ( V_34 , V_441 ) ;
if ( V_440 ) {
F_301 ( V_34 , V_369 , V_440 ) ;
F_261 ( V_34 -> V_36 , L_10 ,
F_313 ( V_253 ) , V_440 , 0 ) ;
}
if ( V_439 )
F_45 ( & F_228 ( V_253 ) -> V_442 ) ;
return V_28 ;
}
void F_328 ( struct V_253 * V_253 , T_2 V_35 )
{
struct V_33 * V_34 = F_228 ( V_253 ) -> V_34 ;
T_2 V_440 = 0 ;
unsigned V_441 ;
V_35 = F_256 ( V_35 , V_34 -> V_325 ) ;
F_11 ( & F_228 ( V_253 ) -> V_51 ) ;
V_441 = F_319 ( V_253 ) ;
if ( V_35 )
V_440 = F_321 ( V_253 , V_35 , 0 ) ;
F_13 ( & F_228 ( V_253 ) -> V_51 ) ;
if ( V_441 > 0 )
V_440 += F_269 ( V_34 , V_441 ) ;
F_261 ( V_34 -> V_36 , L_10 ,
F_313 ( V_253 ) , V_440 , 0 ) ;
if ( V_34 -> V_36 -> V_420 ) {
F_317 ( V_34 , V_35 +
V_441 * V_34 -> V_85 ) ;
}
F_301 ( V_34 , & V_34 -> V_36 -> V_374 ,
V_440 ) ;
}
int F_329 ( struct V_253 * V_253 , T_2 V_35 )
{
int V_28 ;
V_28 = F_234 ( V_253 , V_35 ) ;
if ( V_28 )
return V_28 ;
V_28 = F_323 ( V_253 , V_35 ) ;
if ( V_28 ) {
F_236 ( V_253 , V_35 ) ;
return V_28 ;
}
return 0 ;
}
void F_330 ( struct V_253 * V_253 , T_2 V_35 )
{
F_328 ( V_253 , V_35 ) ;
F_236 ( V_253 , V_35 ) ;
}
static int F_331 ( struct V_33 * V_34 ,
T_2 V_26 , T_2 V_35 , int V_328 )
{
struct V_1 * V_2 = NULL ;
struct V_11 * V_12 = V_34 -> V_36 ;
T_2 V_445 = V_35 ;
T_2 V_446 ;
T_2 V_447 ;
int V_276 ;
F_11 ( & V_12 -> V_439 ) ;
V_446 = F_332 ( V_12 -> V_342 ) ;
if ( V_328 )
V_446 += V_35 ;
else
V_446 -= V_35 ;
F_333 ( V_12 -> V_342 , V_446 ) ;
F_13 ( & V_12 -> V_439 ) ;
while ( V_445 ) {
V_2 = F_66 ( V_12 , V_26 ) ;
if ( ! V_2 )
return - V_149 ;
if ( V_2 -> V_6 & ( V_277 |
V_278 |
V_279 ) )
V_276 = 2 ;
else
V_276 = 1 ;
if ( ! V_328 && V_2 -> V_3 == V_93 )
F_50 ( V_2 , 1 ) ;
V_447 = V_26 - V_2 -> V_20 . V_21 ;
F_8 ( V_447 > V_2 -> V_20 . V_32 ) ;
F_11 ( & V_2 -> V_102 -> V_51 ) ;
F_11 ( & V_2 -> V_51 ) ;
if ( F_232 ( V_34 , V_268 ) &&
V_2 -> V_259 < V_270 )
V_2 -> V_259 = V_270 ;
V_2 -> V_271 = 1 ;
V_446 = F_334 ( & V_2 -> V_131 ) ;
V_35 = F_276 ( V_445 , V_2 -> V_20 . V_32 - V_447 ) ;
if ( V_328 ) {
V_446 += V_35 ;
F_335 ( & V_2 -> V_131 , V_446 ) ;
V_2 -> V_9 -= V_35 ;
V_2 -> V_102 -> V_286 -= V_35 ;
V_2 -> V_102 -> V_275 += V_35 ;
V_2 -> V_102 -> V_281 += V_35 * V_276 ;
F_13 ( & V_2 -> V_51 ) ;
F_13 ( & V_2 -> V_102 -> V_51 ) ;
} else {
V_446 -= V_35 ;
F_335 ( & V_2 -> V_131 , V_446 ) ;
V_2 -> V_8 += V_35 ;
V_2 -> V_102 -> V_285 += V_35 ;
V_2 -> V_102 -> V_275 -= V_35 ;
V_2 -> V_102 -> V_281 -= V_35 * V_276 ;
F_13 ( & V_2 -> V_51 ) ;
F_13 ( & V_2 -> V_102 -> V_51 ) ;
F_336 ( V_12 -> V_58 ,
V_26 , V_26 + V_35 - 1 ,
V_39 | V_448 ) ;
}
F_6 ( V_2 ) ;
V_445 -= V_35 ;
V_26 += V_35 ;
}
return 0 ;
}
static T_2 V_25 ( struct V_33 * V_34 , T_2 V_449 )
{
struct V_1 * V_2 ;
T_2 V_26 ;
F_11 ( & V_34 -> V_36 -> V_17 ) ;
V_26 = V_34 -> V_36 -> V_25 ;
F_13 ( & V_34 -> V_36 -> V_17 ) ;
if ( V_26 < ( T_2 ) - 1 )
return V_26 ;
V_2 = F_65 ( V_34 -> V_36 , V_449 ) ;
if ( ! V_2 )
return 0 ;
V_26 = V_2 -> V_20 . V_21 ;
F_6 ( V_2 ) ;
return V_26 ;
}
static int F_337 ( struct V_33 * V_34 ,
struct V_1 * V_2 ,
T_2 V_26 , T_2 V_35 , int V_9 )
{
F_11 ( & V_2 -> V_102 -> V_51 ) ;
F_11 ( & V_2 -> V_51 ) ;
V_2 -> V_8 += V_35 ;
V_2 -> V_102 -> V_285 += V_35 ;
if ( V_9 ) {
V_2 -> V_9 -= V_35 ;
V_2 -> V_102 -> V_286 -= V_35 ;
}
F_13 ( & V_2 -> V_51 ) ;
F_13 ( & V_2 -> V_102 -> V_51 ) ;
F_336 ( V_34 -> V_36 -> V_58 , V_26 ,
V_26 + V_35 - 1 , V_39 | V_448 ) ;
return 0 ;
}
int F_159 ( struct V_33 * V_34 ,
T_2 V_26 , T_2 V_35 , int V_9 )
{
struct V_1 * V_2 ;
V_2 = F_66 ( V_34 -> V_36 , V_26 ) ;
F_30 ( ! V_2 ) ;
F_337 ( V_34 , V_2 , V_26 , V_35 , V_9 ) ;
F_6 ( V_2 ) ;
return 0 ;
}
int F_338 ( struct V_33 * V_34 ,
T_2 V_26 , T_2 V_35 )
{
struct V_1 * V_2 ;
int V_28 ;
V_2 = F_66 ( V_34 -> V_36 , V_26 ) ;
if ( ! V_2 )
return - V_450 ;
F_50 ( V_2 , 1 ) ;
F_337 ( V_34 , V_2 , V_26 , V_35 , 0 ) ;
V_28 = F_339 ( V_2 , V_26 , V_35 ) ;
F_6 ( V_2 ) ;
return V_28 ;
}
static int F_340 ( struct V_1 * V_2 ,
T_2 V_35 , int V_427 )
{
struct V_99 * V_102 = V_2 -> V_102 ;
int V_28 = 0 ;
F_11 ( & V_102 -> V_51 ) ;
F_11 ( & V_2 -> V_51 ) ;
if ( V_427 != V_451 ) {
if ( V_2 -> V_261 ) {
V_28 = - V_173 ;
} else {
V_2 -> V_9 += V_35 ;
V_102 -> V_286 += V_35 ;
if ( V_427 == V_452 ) {
F_261 ( V_2 -> V_36 ,
L_6 , V_102 -> V_6 ,
V_35 , 0 ) ;
V_102 -> V_288 -= V_35 ;
}
}
} else {
if ( V_2 -> V_261 )
V_102 -> V_287 += V_35 ;
V_2 -> V_9 -= V_35 ;
V_102 -> V_286 -= V_35 ;
V_102 -> V_401 ++ ;
}
F_13 ( & V_2 -> V_51 ) ;
F_13 ( & V_102 -> V_51 ) ;
return V_28 ;
}
void F_341 ( struct V_106 * V_107 ,
struct V_33 * V_34 )
{
struct V_11 * V_36 = V_34 -> V_36 ;
struct V_49 * V_213 ;
struct V_49 * V_53 ;
struct V_1 * V_2 ;
F_61 ( & V_36 -> V_78 ) ;
F_342 (caching_ctl, next,
&fs_info->caching_block_groups, list) {
V_2 = V_53 -> V_13 ;
if ( F_1 ( V_2 ) ) {
V_2 -> V_96 = ( T_2 ) - 1 ;
F_168 ( & V_53 -> V_89 ) ;
F_26 ( V_53 ) ;
} else {
V_2 -> V_96 = V_53 -> V_82 ;
}
}
if ( V_36 -> V_58 == & V_36 -> V_37 [ 0 ] )
V_36 -> V_58 = & V_36 -> V_37 [ 1 ] ;
else
V_36 -> V_58 = & V_36 -> V_37 [ 0 ] ;
F_63 ( & V_36 -> V_78 ) ;
F_308 ( V_36 ) ;
}
static int F_343 ( struct V_33 * V_34 , T_2 V_31 , T_2 V_30 )
{
struct V_11 * V_36 = V_34 -> V_36 ;
struct V_1 * V_2 = NULL ;
struct V_99 * V_102 ;
struct V_334 * V_338 = & V_36 -> V_267 ;
T_2 V_48 ;
bool V_273 ;
while ( V_31 <= V_30 ) {
V_273 = false ;
if ( ! V_2 ||
V_31 >= V_2 -> V_20 . V_21 + V_2 -> V_20 . V_32 ) {
if ( V_2 )
F_6 ( V_2 ) ;
V_2 = F_66 ( V_36 , V_31 ) ;
F_30 ( ! V_2 ) ;
}
V_48 = V_2 -> V_20 . V_21 + V_2 -> V_20 . V_32 - V_31 ;
V_48 = F_276 ( V_48 , V_30 + 1 - V_31 ) ;
if ( V_31 < V_2 -> V_96 ) {
V_48 = F_276 ( V_48 , V_2 -> V_96 - V_31 ) ;
F_29 ( V_2 , V_31 , V_48 ) ;
}
V_31 += V_48 ;
V_102 = V_2 -> V_102 ;
F_11 ( & V_102 -> V_51 ) ;
F_11 ( & V_2 -> V_51 ) ;
V_2 -> V_8 -= V_48 ;
V_102 -> V_285 -= V_48 ;
if ( V_2 -> V_261 ) {
V_102 -> V_287 += V_48 ;
V_273 = true ;
}
F_13 ( & V_2 -> V_51 ) ;
if ( ! V_273 && V_338 -> V_102 == V_102 ) {
F_11 ( & V_338 -> V_51 ) ;
if ( ! V_338 -> V_105 ) {
V_48 = F_276 ( V_48 , V_338 -> V_56 -
V_338 -> V_9 ) ;
V_338 -> V_9 += V_48 ;
V_102 -> V_288 += V_48 ;
if ( V_338 -> V_9 >= V_338 -> V_56 )
V_338 -> V_105 = 1 ;
}
F_13 ( & V_338 -> V_51 ) ;
}
F_13 ( & V_102 -> V_51 ) ;
}
if ( V_2 )
F_6 ( V_2 ) ;
return 0 ;
}
int F_344 ( struct V_106 * V_107 ,
struct V_33 * V_34 )
{
struct V_11 * V_36 = V_34 -> V_36 ;
struct V_453 * V_454 ;
T_2 V_31 ;
T_2 V_30 ;
int V_28 ;
if ( V_107 -> V_208 )
return 0 ;
if ( V_36 -> V_58 == & V_36 -> V_37 [ 0 ] )
V_454 = & V_36 -> V_37 [ 1 ] ;
else
V_454 = & V_36 -> V_37 [ 0 ] ;
while ( 1 ) {
V_28 = F_28 ( V_454 , 0 , & V_31 , & V_30 ,
V_59 , NULL ) ;
if ( V_28 )
break;
if ( F_232 ( V_34 , V_455 ) )
V_28 = F_140 ( V_34 , V_31 ,
V_30 + 1 - V_31 , NULL ) ;
F_345 ( V_454 , V_31 , V_30 , V_39 ) ;
F_343 ( V_34 , V_31 , V_30 ) ;
F_46 () ;
}
return 0 ;
}
static int F_150 ( struct V_106 * V_107 ,
struct V_33 * V_34 ,
T_2 V_26 , T_2 V_35 , T_2 V_16 ,
T_2 V_142 , T_2 V_456 ,
T_2 V_457 , int V_155 ,
struct V_175 * V_125 )
{
struct V_67 V_20 ;
struct V_63 * V_64 ;
struct V_11 * V_12 = V_34 -> V_36 ;
struct V_33 * V_62 = V_12 -> V_62 ;
struct V_65 * V_66 ;
struct V_113 * V_114 ;
struct V_158 * V_159 ;
int V_28 ;
int V_179 ;
int V_458 = 0 ;
int V_459 = 0 ;
int V_460 = 1 ;
T_3 V_115 ;
T_2 V_109 ;
bool V_168 = F_74 ( V_34 -> V_36 ,
V_118 ) ;
V_64 = F_33 () ;
if ( ! V_64 )
return - V_88 ;
V_64 -> V_74 = 1 ;
V_64 -> V_199 = 1 ;
V_179 = V_456 >= V_139 ;
F_30 ( ! V_179 && V_155 != 1 ) ;
if ( V_179 )
V_168 = 0 ;
V_28 = F_132 ( V_107 , V_62 , V_64 , & V_159 ,
V_26 , V_35 , V_16 ,
V_142 , V_456 ,
V_457 ) ;
if ( V_28 == 0 ) {
V_458 = V_64 -> V_81 [ 0 ] ;
while ( V_458 >= 0 ) {
F_40 ( V_64 -> V_80 [ 0 ] , & V_20 ,
V_458 ) ;
if ( V_20 . V_21 != V_26 )
break;
if ( V_20 . type == V_75 &&
V_20 . V_32 == V_35 ) {
V_459 = 1 ;
break;
}
if ( V_20 . type == V_83 &&
V_20 . V_32 == V_456 ) {
V_459 = 1 ;
break;
}
if ( V_64 -> V_81 [ 0 ] - V_458 > 5 )
break;
V_458 -- ;
}
#ifdef F_79
V_115 = F_75 ( V_64 -> V_80 [ 0 ] , V_458 ) ;
if ( V_459 && V_115 < sizeof( * V_114 ) )
V_459 = 0 ;
#endif
if ( ! V_459 ) {
F_30 ( V_159 ) ;
V_28 = F_137 ( V_107 , V_62 , V_64 ,
NULL , V_155 ,
V_179 ) ;
if ( V_28 ) {
F_146 ( V_107 , V_62 , V_28 ) ;
goto V_71;
}
F_43 ( V_64 ) ;
V_64 -> V_199 = 1 ;
V_20 . V_21 = V_26 ;
V_20 . type = V_75 ;
V_20 . V_32 = V_35 ;
if ( ! V_179 && V_168 ) {
V_20 . type = V_83 ;
V_20 . V_32 = V_456 ;
}
V_28 = F_37 ( V_107 , V_62 ,
& V_20 , V_64 , - 1 , 1 ) ;
if ( V_28 > 0 && V_168 && V_64 -> V_81 [ 0 ] ) {
V_64 -> V_81 [ 0 ] -- ;
F_40 ( V_64 -> V_80 [ 0 ] , & V_20 ,
V_64 -> V_81 [ 0 ] ) ;
if ( V_20 . V_21 == V_26 &&
V_20 . type == V_75 &&
V_20 . V_32 == V_35 )
V_28 = 0 ;
}
if ( V_28 > 0 && V_168 ) {
V_168 = false ;
V_20 . type = V_75 ;
V_20 . V_32 = V_35 ;
F_43 ( V_64 ) ;
V_28 = F_37 ( V_107 , V_62 ,
& V_20 , V_64 , - 1 , 1 ) ;
}
if ( V_28 ) {
F_177 ( V_12 , L_11 ,
V_28 , ( unsigned long long ) V_26 ) ;
if ( V_28 > 0 )
F_346 ( V_62 ,
V_64 -> V_80 [ 0 ] ) ;
}
if ( V_28 < 0 ) {
F_146 ( V_107 , V_62 , V_28 ) ;
goto V_71;
}
V_458 = V_64 -> V_81 [ 0 ] ;
}
} else if ( V_28 == - V_149 ) {
F_346 ( V_62 , V_64 -> V_80 [ 0 ] ) ;
F_8 ( 1 ) ;
F_177 ( V_12 ,
L_12 ,
( unsigned long long ) V_26 ,
( unsigned long long ) V_16 ,
( unsigned long long ) V_142 ,
( unsigned long long ) V_456 ,
( unsigned long long ) V_457 ) ;
} else {
F_146 ( V_107 , V_62 , V_28 ) ;
goto V_71;
}
V_66 = V_64 -> V_80 [ 0 ] ;
V_115 = F_75 ( V_66 , V_458 ) ;
#ifdef F_79
if ( V_115 < sizeof( * V_114 ) ) {
F_30 ( V_459 || V_458 != V_64 -> V_81 [ 0 ] ) ;
V_28 = F_85 ( V_107 , V_62 , V_64 ,
V_456 , 0 ) ;
if ( V_28 < 0 ) {
F_146 ( V_107 , V_62 , V_28 ) ;
goto V_71;
}
F_43 ( V_64 ) ;
V_64 -> V_199 = 1 ;
V_20 . V_21 = V_26 ;
V_20 . type = V_75 ;
V_20 . V_32 = V_35 ;
V_28 = F_37 ( V_107 , V_62 , & V_20 , V_64 ,
- 1 , 1 ) ;
if ( V_28 ) {
F_177 ( V_12 , L_11 ,
V_28 , ( unsigned long long ) V_26 ) ;
F_346 ( V_62 , V_64 -> V_80 [ 0 ] ) ;
}
if ( V_28 < 0 ) {
F_146 ( V_107 , V_62 , V_28 ) ;
goto V_71;
}
V_458 = V_64 -> V_81 [ 0 ] ;
V_66 = V_64 -> V_80 [ 0 ] ;
V_115 = F_75 ( V_66 , V_458 ) ;
}
#endif
F_30 ( V_115 < sizeof( * V_114 ) ) ;
V_114 = F_76 ( V_66 , V_458 ,
struct V_113 ) ;
if ( V_456 < V_139 &&
V_20 . type == V_75 ) {
struct V_134 * V_135 ;
F_30 ( V_115 < sizeof( * V_114 ) + sizeof( * V_135 ) ) ;
V_135 = (struct V_134 * ) ( V_114 + 1 ) ;
F_8 ( V_456 != F_347 ( V_66 , V_135 ) ) ;
}
V_109 = F_77 ( V_66 , V_114 ) ;
if ( V_109 < V_155 ) {
F_177 ( V_12 , L_13
L_14 , V_155 , V_109 , V_26 ) ;
V_28 = - V_450 ;
F_146 ( V_107 , V_62 , V_28 ) ;
goto V_71;
}
V_109 -= V_155 ;
if ( V_109 > 0 ) {
if ( V_125 )
F_128 ( V_125 , V_66 , V_114 ) ;
if ( V_159 ) {
F_30 ( ! V_459 ) ;
} else {
F_88 ( V_66 , V_114 , V_109 ) ;
F_93 ( V_66 ) ;
}
if ( V_459 ) {
V_28 = F_137 ( V_107 , V_62 , V_64 ,
V_159 , V_155 ,
V_179 ) ;
if ( V_28 ) {
F_146 ( V_107 , V_62 , V_28 ) ;
goto V_71;
}
}
} else {
if ( V_459 ) {
F_30 ( V_179 && V_155 !=
F_116 ( V_34 , V_64 , V_159 ) ) ;
if ( V_159 ) {
F_30 ( V_64 -> V_81 [ 0 ] != V_458 ) ;
} else {
F_30 ( V_64 -> V_81 [ 0 ] != V_458 + 1 ) ;
V_64 -> V_81 [ 0 ] = V_458 ;
V_460 = 2 ;
}
}
V_28 = F_348 ( V_107 , V_62 , V_64 , V_64 -> V_81 [ 0 ] ,
V_460 ) ;
if ( V_28 ) {
F_146 ( V_107 , V_62 , V_28 ) ;
goto V_71;
}
F_43 ( V_64 ) ;
if ( V_179 ) {
V_28 = F_160 ( V_107 , V_34 , V_26 , V_35 ) ;
if ( V_28 ) {
F_146 ( V_107 , V_62 , V_28 ) ;
goto V_71;
}
}
V_28 = F_331 ( V_34 , V_26 , V_35 , 0 ) ;
if ( V_28 ) {
F_146 ( V_107 , V_62 , V_28 ) ;
goto V_71;
}
}
V_71:
F_49 ( V_64 ) ;
return V_28 ;
}
static T_1 int F_349 ( struct V_106 * V_107 ,
struct V_33 * V_34 , T_2 V_26 )
{
struct V_110 * V_101 ;
struct V_111 * V_112 ;
struct V_200 * V_147 ;
struct V_14 * V_124 ;
int V_28 = 0 ;
V_112 = & V_107 -> V_123 -> V_112 ;
F_11 ( & V_112 -> V_51 ) ;
V_101 = F_82 ( V_107 , V_26 ) ;
if ( ! V_101 )
goto V_71;
V_124 = F_200 ( & V_101 -> V_124 . V_14 ) ;
if ( ! V_124 )
goto V_71;
V_147 = F_12 ( V_124 , struct V_200 , V_14 ) ;
if ( V_147 -> V_26 == V_26 )
goto V_71;
if ( V_101 -> V_125 ) {
if ( ! V_101 -> V_212 )
goto V_71;
F_170 ( V_101 -> V_125 ) ;
V_101 -> V_125 = NULL ;
}
if ( ! F_83 ( & V_101 -> V_77 ) )
goto V_71;
V_101 -> V_124 . V_216 = 0 ;
F_172 ( & V_101 -> V_124 . V_14 , & V_112 -> V_34 ) ;
V_112 -> V_217 -- ;
V_112 -> V_461 -- ;
if ( F_162 ( & V_101 -> V_210 ) )
V_112 -> V_215 -- ;
F_168 ( & V_101 -> V_210 ) ;
F_13 ( & V_112 -> V_51 ) ;
F_30 ( V_101 -> V_125 ) ;
if ( V_101 -> V_212 )
V_28 = 1 ;
F_45 ( & V_101 -> V_77 ) ;
F_84 ( & V_101 -> V_124 ) ;
return V_28 ;
V_71:
F_13 ( & V_112 -> V_51 ) ;
return 0 ;
}
void F_350 ( struct V_106 * V_107 ,
struct V_33 * V_34 ,
struct V_65 * V_244 ,
T_2 V_16 , int V_462 )
{
struct V_1 * V_2 = NULL ;
int V_28 ;
if ( V_34 -> V_240 . V_21 != V_197 ) {
V_28 = F_143 ( V_34 -> V_36 , V_107 ,
V_244 -> V_31 , V_244 -> V_48 ,
V_16 , V_34 -> V_240 . V_21 ,
F_208 ( V_244 ) ,
V_206 , NULL , 0 ) ;
F_30 ( V_28 ) ;
}
if ( ! V_462 )
return;
V_2 = F_66 ( V_34 -> V_36 , V_244 -> V_31 ) ;
if ( F_351 ( V_244 ) == V_107 -> V_263 ) {
if ( V_34 -> V_240 . V_21 != V_197 ) {
V_28 = F_349 ( V_107 , V_34 , V_244 -> V_31 ) ;
if ( ! V_28 )
goto V_71;
}
if ( F_352 ( V_244 , V_463 ) ) {
F_337 ( V_34 , V_2 , V_244 -> V_31 , V_244 -> V_48 , 1 ) ;
goto V_71;
}
F_8 ( F_326 ( V_464 , & V_244 -> V_465 ) ) ;
F_29 ( V_2 , V_244 -> V_31 , V_244 -> V_48 ) ;
F_340 ( V_2 , V_244 -> V_48 , V_451 ) ;
}
V_71:
F_353 ( V_466 , & V_244 -> V_465 ) ;
F_6 ( V_2 ) ;
}
int V_250 ( struct V_106 * V_107 , struct V_33 * V_34 ,
T_2 V_26 , T_2 V_35 , T_2 V_16 , T_2 V_142 ,
T_2 V_129 , T_2 V_32 , int V_196 )
{
int V_28 ;
struct V_11 * V_36 = V_34 -> V_36 ;
if ( V_142 == V_197 ) {
F_8 ( V_129 >= V_139 ) ;
F_159 ( V_34 , V_26 , V_35 , 1 ) ;
V_28 = 0 ;
} else if ( V_129 < V_139 ) {
V_28 = F_143 ( V_36 , V_107 , V_26 ,
V_35 ,
V_16 , V_142 , ( int ) V_129 ,
V_206 , NULL , V_196 ) ;
} else {
V_28 = F_144 ( V_36 , V_107 , V_26 ,
V_35 ,
V_16 , V_142 , V_129 ,
V_32 , V_206 ,
NULL , V_196 ) ;
}
return V_28 ;
}
static T_2 F_354 ( struct V_33 * V_34 ,
struct V_1 * V_2 ,
T_2 V_227 , T_2 V_35 )
{
T_2 V_28 = F_256 ( V_227 , V_34 -> V_467 ) ;
return V_28 ;
}
static T_1 int
F_355 ( struct V_1 * V_2 ,
T_2 V_35 )
{
struct V_49 * V_53 ;
V_53 = F_25 ( V_2 ) ;
if ( ! V_53 )
return 0 ;
F_283 ( V_53 -> V_86 , F_1 ( V_2 ) ||
( V_2 -> V_10 -> V_468 >= V_35 ) ) ;
F_26 ( V_53 ) ;
return 0 ;
}
static T_1 int
F_356 ( struct V_1 * V_2 )
{
struct V_49 * V_53 ;
V_53 = F_25 ( V_2 ) ;
if ( ! V_53 )
return 0 ;
F_283 ( V_53 -> V_86 , F_1 ( V_2 ) ) ;
F_26 ( V_53 ) ;
return 0 ;
}
int F_357 ( T_2 V_6 )
{
if ( V_6 & V_279 )
return V_469 ;
else if ( V_6 & V_278 )
return V_470 ;
else if ( V_6 & V_277 )
return V_471 ;
else if ( V_6 & V_317 )
return V_472 ;
else if ( V_6 & V_318 )
return V_473 ;
else if ( V_6 & V_319 )
return V_474 ;
return V_475 ;
}
static int F_358 ( struct V_1 * V_2 )
{
return F_357 ( V_2 -> V_6 ) ;
}
static T_1 int F_359 ( struct V_106 * V_107 ,
struct V_33 * V_476 ,
T_2 V_35 , T_2 V_477 ,
T_2 V_478 , struct V_67 * V_203 ,
T_2 V_6 )
{
int V_28 = 0 ;
struct V_33 * V_34 = V_476 -> V_36 -> V_62 ;
struct V_479 * V_480 = NULL ;
struct V_1 * V_13 = NULL ;
struct V_1 * V_481 ;
T_2 V_449 = 0 ;
int V_482 = 2 * 1024 * 1024 ;
struct V_99 * V_102 ;
int V_483 = 0 ;
int V_484 = F_357 ( V_6 ) ;
int V_485 = ( V_6 & V_293 ) ?
V_486 : V_452 ;
bool V_487 = false ;
bool V_488 = false ;
bool V_489 = false ;
bool V_490 = true ;
bool V_491 = false ;
F_8 ( V_35 < V_34 -> V_325 ) ;
F_360 ( V_203 , V_75 ) ;
V_203 -> V_21 = 0 ;
V_203 -> V_32 = 0 ;
F_361 ( V_476 , V_35 , V_477 , V_6 ) ;
V_102 = F_67 ( V_34 -> V_36 , V_6 ) ;
if ( ! V_102 ) {
F_177 ( V_34 -> V_36 , L_15 , V_6 ) ;
return - V_331 ;
}
if ( F_274 ( V_102 ) )
V_490 = false ;
if ( V_6 & V_299 && V_490 ) {
V_480 = & V_34 -> V_36 -> V_492 ;
if ( ! F_232 ( V_34 , V_493 ) )
V_482 = 64 * 1024 ;
}
if ( ( V_6 & V_293 ) && V_490 &&
F_232 ( V_34 , V_493 ) ) {
V_480 = & V_34 -> V_36 -> V_494 ;
}
if ( V_480 ) {
F_11 ( & V_480 -> V_51 ) ;
if ( V_480 -> V_13 )
V_478 = V_480 -> V_495 ;
F_13 ( & V_480 -> V_51 ) ;
}
V_449 = F_362 ( V_449 , V_25 ( V_34 , 0 ) ) ;
V_449 = F_362 ( V_449 , V_478 ) ;
if ( ! V_480 )
V_482 = 0 ;
if ( V_449 == V_478 ) {
V_13 = F_66 ( V_34 -> V_36 ,
V_449 ) ;
V_481 = V_13 ;
if ( V_13 && F_3 ( V_13 , V_6 ) &&
V_13 -> V_3 != V_93 ) {
F_36 ( & V_102 -> V_284 ) ;
if ( F_162 ( & V_13 -> V_89 ) ||
V_13 -> V_261 ) {
F_6 ( V_13 ) ;
F_44 ( & V_102 -> V_284 ) ;
} else {
V_484 = F_358 ( V_13 ) ;
goto V_496;
}
} else if ( V_13 ) {
F_6 ( V_13 ) ;
}
}
V_497:
V_491 = false ;
F_36 ( & V_102 -> V_284 ) ;
F_363 (block_group, &space_info->block_groups[index],
list) {
T_2 V_32 ;
int V_3 ;
V_481 = V_13 ;
F_4 ( V_13 ) ;
V_449 = V_13 -> V_20 . V_21 ;
if ( ! F_3 ( V_13 , V_6 ) ) {
T_2 V_498 = V_277 |
V_278 |
V_318 |
V_319 |
V_279 ;
if ( ( V_6 & V_498 ) && ! ( V_13 -> V_6 & V_498 ) )
goto V_483;
}
V_496:
V_3 = F_1 ( V_13 ) ;
if ( F_290 ( ! V_3 ) ) {
V_487 = true ;
V_28 = F_50 ( V_13 , 0 ) ;
F_30 ( V_28 < 0 ) ;
V_28 = 0 ;
}
if ( F_290 ( V_13 -> V_261 ) )
goto V_483;
if ( V_480 ) {
unsigned long V_499 ;
F_11 ( & V_480 -> V_500 ) ;
V_481 = V_480 -> V_13 ;
if ( V_481 != V_13 &&
( ! V_481 ||
V_481 -> V_261 ||
! F_3 ( V_481 , V_6 ) ) ) {
V_481 = V_13 ;
goto V_501;
}
if ( V_481 != V_13 )
F_4 ( V_481 ) ;
V_32 = F_364 ( V_481 ,
V_480 , V_35 , V_481 -> V_20 . V_21 ) ;
if ( V_32 ) {
F_13 ( & V_480 -> V_500 ) ;
F_365 ( V_34 ,
V_13 , V_449 , V_35 ) ;
goto V_502;
}
F_8 ( V_480 -> V_13 != V_481 ) ;
if ( V_481 != V_13 ) {
F_6 ( V_481 ) ;
V_481 = V_13 ;
}
V_501:
F_30 ( V_481 != V_13 ) ;
if ( V_483 >= V_503 &&
V_480 -> V_13 != V_13 ) {
F_13 ( & V_480 -> V_500 ) ;
goto V_504;
}
F_366 ( NULL , V_480 ) ;
if ( V_483 >= V_503 ) {
F_13 ( & V_480 -> V_500 ) ;
goto V_504;
}
V_499 = F_34 (unsigned long,
empty_cluster + empty_size,
block_group->full_stripe_len) ;
V_28 = F_367 ( V_107 , V_34 ,
V_13 , V_480 ,
V_449 , V_35 ,
V_499 ) ;
if ( V_28 == 0 ) {
V_32 = F_364 ( V_13 ,
V_480 , V_35 ,
V_449 ) ;
if ( V_32 ) {
F_13 ( & V_480 -> V_500 ) ;
F_365 ( V_34 ,
V_13 , V_449 ,
V_35 ) ;
goto V_502;
}
} else if ( ! V_3 && V_483 > V_505
&& ! V_488 ) {
F_13 ( & V_480 -> V_500 ) ;
V_488 = true ;
F_355 ( V_13 ,
V_35 + V_482 + V_477 ) ;
goto V_496;
}
F_366 ( NULL , V_480 ) ;
F_13 ( & V_480 -> V_500 ) ;
goto V_483;
}
V_504:
F_11 ( & V_13 -> V_10 -> V_506 ) ;
if ( V_3 &&
V_13 -> V_10 -> V_468 <
V_35 + V_482 + V_477 ) {
F_13 ( & V_13 -> V_10 -> V_506 ) ;
goto V_483;
}
F_13 ( & V_13 -> V_10 -> V_506 ) ;
V_32 = F_368 ( V_13 , V_449 ,
V_35 , V_477 ) ;
if ( ! V_32 && ! V_489 && ! V_3 &&
V_483 > V_505 ) {
F_355 ( V_13 ,
V_35 + V_477 ) ;
V_489 = true ;
goto V_496;
} else if ( ! V_32 ) {
if ( ! V_3 )
V_491 = true ;
goto V_483;
}
V_502:
V_449 = F_354 ( V_34 , V_481 ,
V_32 , V_35 ) ;
if ( V_449 + V_35 >
V_481 -> V_20 . V_21 + V_481 -> V_20 . V_32 ) {
F_29 ( V_481 , V_32 , V_35 ) ;
goto V_483;
}
if ( V_32 < V_449 )
F_29 ( V_481 , V_32 ,
V_449 - V_32 ) ;
F_30 ( V_32 > V_449 ) ;
V_28 = F_340 ( V_481 , V_35 ,
V_485 ) ;
if ( V_28 == - V_173 ) {
F_29 ( V_481 , V_32 , V_35 ) ;
goto V_483;
}
V_203 -> V_21 = V_449 ;
V_203 -> V_32 = V_35 ;
F_369 ( V_476 , V_13 ,
V_449 , V_35 ) ;
if ( V_481 != V_13 )
F_6 ( V_481 ) ;
F_6 ( V_13 ) ;
break;
V_483:
V_488 = false ;
V_489 = false ;
F_30 ( V_484 != F_358 ( V_13 ) ) ;
if ( V_481 != V_13 )
F_6 ( V_481 ) ;
F_6 ( V_13 ) ;
}
F_44 ( & V_102 -> V_284 ) ;
if ( ! V_203 -> V_21 && V_483 >= V_507 && V_491 )
goto V_497;
if ( ! V_203 -> V_21 && ++ V_484 < V_282 )
goto V_497;
if ( ! V_203 -> V_21 && V_483 < V_503 ) {
V_484 = 0 ;
V_483 ++ ;
if ( V_483 == V_508 ) {
V_28 = F_258 ( V_107 , V_34 , V_6 ,
V_330 ) ;
if ( V_28 < 0 && V_28 != - V_331 ) {
F_146 ( V_107 ,
V_34 , V_28 ) ;
goto V_71;
}
}
if ( V_483 == V_503 ) {
V_477 = 0 ;
V_482 = 0 ;
}
goto V_497;
} else if ( ! V_203 -> V_21 ) {
V_28 = - V_331 ;
} else if ( V_203 -> V_21 ) {
V_28 = 0 ;
}
V_71:
return V_28 ;
}
static void F_272 ( struct V_99 * V_12 , T_2 V_321 ,
int V_509 )
{
struct V_1 * V_2 ;
int V_484 = 0 ;
F_11 ( & V_12 -> V_51 ) ;
F_370 ( V_510 L_16 ,
( unsigned long long ) V_12 -> V_6 ,
( unsigned long long ) ( V_12 -> V_274 - V_12 -> V_275 -
V_12 -> V_285 - V_12 -> V_286 -
V_12 -> V_287 ) ,
( V_12 -> V_105 ) ? L_4 : L_17 ) ;
F_370 ( V_510 L_18
L_19 ,
( unsigned long long ) V_12 -> V_274 ,
( unsigned long long ) V_12 -> V_275 ,
( unsigned long long ) V_12 -> V_285 ,
( unsigned long long ) V_12 -> V_286 ,
( unsigned long long ) V_12 -> V_288 ,
( unsigned long long ) V_12 -> V_287 ) ;
F_13 ( & V_12 -> V_51 ) ;
if ( ! V_509 )
return;
F_36 ( & V_12 -> V_284 ) ;
V_76:
F_363 (cache, &info->block_groups[index], list) {
F_11 ( & V_2 -> V_51 ) ;
F_370 ( V_510 L_20 ,
( unsigned long long ) V_2 -> V_20 . V_21 ,
( unsigned long long ) V_2 -> V_20 . V_32 ,
( unsigned long long ) F_334 ( & V_2 -> V_131 ) ,
( unsigned long long ) V_2 -> V_8 ,
( unsigned long long ) V_2 -> V_9 ,
V_2 -> V_261 ? L_21 : L_4 ) ;
F_371 ( V_2 , V_321 ) ;
F_13 ( & V_2 -> V_51 ) ;
}
if ( ++ V_484 < V_282 )
goto V_76;
F_44 ( & V_12 -> V_284 ) ;
}
int F_372 ( struct V_106 * V_107 ,
struct V_33 * V_34 ,
T_2 V_35 , T_2 V_511 ,
T_2 V_477 , T_2 V_478 ,
struct V_67 * V_203 , int V_179 )
{
bool V_512 = false ;
T_2 V_6 ;
int V_28 ;
V_6 = F_255 ( V_34 , V_179 ) ;
V_76:
F_8 ( V_35 < V_34 -> V_325 ) ;
V_28 = F_359 ( V_107 , V_34 , V_35 , V_477 ,
V_478 , V_203 , V_6 ) ;
if ( V_28 == - V_331 ) {
if ( ! V_512 ) {
V_35 = V_35 >> 1 ;
V_35 = F_373 ( V_35 , V_34 -> V_325 ) ;
V_35 = F_362 ( V_35 , V_511 ) ;
if ( V_35 == V_511 )
V_512 = true ;
goto V_76;
} else if ( F_232 ( V_34 , V_345 ) ) {
struct V_99 * V_336 ;
V_336 = F_67 ( V_34 -> V_36 , V_6 ) ;
F_177 ( V_34 -> V_36 , L_22 ,
( unsigned long long ) V_6 ,
( unsigned long long ) V_35 ) ;
if ( V_336 )
F_272 ( V_336 , V_35 , 1 ) ;
}
}
F_374 ( V_34 , V_203 -> V_21 , V_203 -> V_32 ) ;
return V_28 ;
}
static int F_375 ( struct V_33 * V_34 ,
T_2 V_31 , T_2 V_48 , int V_513 )
{
struct V_1 * V_2 ;
int V_28 = 0 ;
V_2 = F_66 ( V_34 -> V_36 , V_31 ) ;
if ( ! V_2 ) {
F_177 ( V_34 -> V_36 , L_23 ,
( unsigned long long ) V_31 ) ;
return - V_331 ;
}
if ( F_232 ( V_34 , V_455 ) )
V_28 = F_140 ( V_34 , V_31 , V_48 , NULL ) ;
if ( V_513 )
F_337 ( V_34 , V_2 , V_31 , V_48 , 1 ) ;
else {
F_29 ( V_2 , V_31 , V_48 ) ;
F_340 ( V_2 , V_48 , V_451 ) ;
}
F_6 ( V_2 ) ;
F_376 ( V_34 , V_31 , V_48 ) ;
return V_28 ;
}
int F_377 ( struct V_33 * V_34 ,
T_2 V_31 , T_2 V_48 )
{
return F_375 ( V_34 , V_31 , V_48 , 0 ) ;
}
int F_378 ( struct V_33 * V_34 ,
T_2 V_31 , T_2 V_48 )
{
return F_375 ( V_34 , V_31 , V_48 , 1 ) ;
}
static int F_149 ( struct V_106 * V_107 ,
struct V_33 * V_34 ,
T_2 V_16 , T_2 V_142 ,
T_2 V_6 , T_2 V_129 , T_2 V_32 ,
struct V_67 * V_203 , int V_128 )
{
int V_28 ;
struct V_11 * V_36 = V_34 -> V_36 ;
struct V_113 * V_514 ;
struct V_158 * V_159 ;
struct V_63 * V_64 ;
struct V_65 * V_66 ;
int type ;
T_3 V_56 ;
if ( V_16 > 0 )
type = V_150 ;
else
type = V_151 ;
V_56 = sizeof( * V_514 ) + F_123 ( type ) ;
V_64 = F_33 () ;
if ( ! V_64 )
return - V_88 ;
V_64 -> V_199 = 1 ;
V_28 = F_104 ( V_107 , V_36 -> V_62 , V_64 ,
V_203 , V_56 ) ;
if ( V_28 ) {
F_49 ( V_64 ) ;
return V_28 ;
}
V_66 = V_64 -> V_80 [ 0 ] ;
V_514 = F_76 ( V_66 , V_64 -> V_81 [ 0 ] ,
struct V_113 ) ;
F_88 ( V_66 , V_514 , V_128 ) ;
F_89 ( V_66 , V_514 , V_107 -> V_263 ) ;
F_90 ( V_66 , V_514 ,
V_6 | V_141 ) ;
V_159 = (struct V_158 * ) ( V_514 + 1 ) ;
F_130 ( V_66 , V_159 , type ) ;
if ( V_16 > 0 ) {
struct V_154 * V_147 ;
V_147 = (struct V_154 * ) ( V_159 + 1 ) ;
F_131 ( V_66 , V_159 , V_16 ) ;
F_105 ( V_66 , V_147 , V_128 ) ;
} else {
struct V_146 * V_147 ;
V_147 = (struct V_146 * ) ( & V_159 -> V_32 ) ;
F_107 ( V_66 , V_147 , V_142 ) ;
F_108 ( V_66 , V_147 , V_129 ) ;
F_109 ( V_66 , V_147 , V_32 ) ;
F_110 ( V_66 , V_147 , V_128 ) ;
}
F_93 ( V_64 -> V_80 [ 0 ] ) ;
F_49 ( V_64 ) ;
V_28 = F_331 ( V_34 , V_203 -> V_21 , V_203 -> V_32 , 1 ) ;
if ( V_28 ) {
F_177 ( V_36 , L_24 ,
( unsigned long long ) V_203 -> V_21 ,
( unsigned long long ) V_203 -> V_32 ) ;
F_81 () ;
}
return V_28 ;
}
static int F_155 ( struct V_106 * V_107 ,
struct V_33 * V_34 ,
T_2 V_16 , T_2 V_142 ,
T_2 V_6 , struct V_435 * V_20 ,
int V_162 , struct V_67 * V_203 )
{
int V_28 ;
struct V_11 * V_36 = V_34 -> V_36 ;
struct V_113 * V_514 ;
struct V_134 * V_515 ;
struct V_158 * V_159 ;
struct V_63 * V_64 ;
struct V_65 * V_66 ;
T_3 V_56 = sizeof( * V_514 ) + sizeof( * V_159 ) ;
bool V_168 = F_74 ( V_34 -> V_36 ,
V_118 ) ;
if ( ! V_168 )
V_56 += sizeof( * V_515 ) ;
V_64 = F_33 () ;
if ( ! V_64 )
return - V_88 ;
V_64 -> V_199 = 1 ;
V_28 = F_104 ( V_107 , V_36 -> V_62 , V_64 ,
V_203 , V_56 ) ;
if ( V_28 ) {
F_49 ( V_64 ) ;
return V_28 ;
}
V_66 = V_64 -> V_80 [ 0 ] ;
V_514 = F_76 ( V_66 , V_64 -> V_81 [ 0 ] ,
struct V_113 ) ;
F_88 ( V_66 , V_514 , 1 ) ;
F_89 ( V_66 , V_514 , V_107 -> V_263 ) ;
F_90 ( V_66 , V_514 ,
V_6 | V_140 ) ;
if ( V_168 ) {
V_159 = (struct V_158 * ) ( V_514 + 1 ) ;
} else {
V_515 = (struct V_134 * ) ( V_514 + 1 ) ;
F_151 ( V_66 , V_515 , V_20 ) ;
F_92 ( V_66 , V_515 , V_162 ) ;
V_159 = (struct V_158 * ) ( V_515 + 1 ) ;
}
if ( V_16 > 0 ) {
F_30 ( ! ( V_6 & V_122 ) ) ;
F_130 ( V_66 , V_159 ,
V_160 ) ;
F_131 ( V_66 , V_159 , V_16 ) ;
} else {
F_130 ( V_66 , V_159 ,
V_161 ) ;
F_131 ( V_66 , V_159 , V_142 ) ;
}
F_93 ( V_66 ) ;
F_49 ( V_64 ) ;
V_28 = F_331 ( V_34 , V_203 -> V_21 , V_34 -> V_85 , 1 ) ;
if ( V_28 ) {
F_177 ( V_36 , L_24 ,
( unsigned long long ) V_203 -> V_21 ,
( unsigned long long ) V_203 -> V_32 ) ;
F_81 () ;
}
return V_28 ;
}
int F_379 ( struct V_106 * V_107 ,
struct V_33 * V_34 ,
T_2 V_142 , T_2 V_129 ,
T_2 V_32 , struct V_67 * V_203 )
{
int V_28 ;
F_30 ( V_142 == V_197 ) ;
V_28 = F_144 ( V_34 -> V_36 , V_107 , V_203 -> V_21 ,
V_203 -> V_32 , 0 ,
V_142 , V_129 , V_32 ,
V_218 , NULL , 0 ) ;
return V_28 ;
}
int F_380 ( struct V_106 * V_107 ,
struct V_33 * V_34 ,
T_2 V_142 , T_2 V_129 , T_2 V_32 ,
struct V_67 * V_203 )
{
int V_28 ;
struct V_1 * V_13 ;
struct V_49 * V_53 ;
T_2 V_31 = V_203 -> V_21 ;
T_2 V_35 = V_203 -> V_32 ;
V_13 = F_66 ( V_34 -> V_36 , V_203 -> V_21 ) ;
F_50 ( V_13 , 0 ) ;
V_53 = F_25 ( V_13 ) ;
if ( ! V_53 ) {
F_30 ( ! F_1 ( V_13 ) ) ;
V_28 = F_339 ( V_13 , V_31 , V_35 ) ;
if ( V_28 )
goto V_71;
} else {
F_35 ( & V_53 -> V_77 ) ;
if ( V_31 >= V_53 -> V_82 ) {
V_28 = F_17 ( V_34 , V_31 , V_35 ) ;
} else if ( V_31 + V_35 <= V_53 -> V_82 ) {
V_28 = F_339 ( V_13 ,
V_31 , V_35 ) ;
} else {
V_35 = V_53 -> V_82 - V_31 ;
V_28 = F_339 ( V_13 ,
V_31 , V_35 ) ;
if ( V_28 )
goto V_516;
V_31 = V_53 -> V_82 ;
V_35 = V_203 -> V_21 + V_203 -> V_32 -
V_53 -> V_82 ;
V_28 = F_17 ( V_34 , V_31 , V_35 ) ;
}
V_516:
F_45 ( & V_53 -> V_77 ) ;
F_26 ( V_53 ) ;
if ( V_28 )
goto V_71;
}
V_28 = F_340 ( V_13 , V_203 -> V_32 ,
V_486 ) ;
F_30 ( V_28 ) ;
V_28 = F_149 ( V_107 , V_34 , 0 , V_142 ,
0 , V_129 , V_32 , V_203 , 1 ) ;
V_71:
F_6 ( V_13 ) ;
return V_28 ;
}
static struct V_65 *
F_381 ( struct V_106 * V_107 , struct V_33 * V_34 ,
T_2 V_26 , T_3 V_517 , int V_162 )
{
struct V_65 * V_244 ;
V_244 = F_382 ( V_34 , V_26 , V_517 ) ;
if ( ! V_244 )
return F_383 ( - V_88 ) ;
F_384 ( V_244 , V_107 -> V_263 ) ;
F_385 ( V_34 -> V_240 . V_21 , V_244 , V_162 ) ;
F_386 ( V_244 ) ;
F_387 ( V_107 , V_34 , V_244 ) ;
F_353 ( V_518 , & V_244 -> V_465 ) ;
F_388 ( V_244 ) ;
F_389 ( V_244 ) ;
if ( V_34 -> V_240 . V_21 == V_197 ) {
if ( V_34 -> V_519 % 2 == 0 )
F_336 ( & V_34 -> V_520 , V_244 -> V_31 ,
V_244 -> V_31 + V_244 -> V_48 - 1 , V_39 ) ;
else
F_390 ( & V_34 -> V_520 , V_244 -> V_31 ,
V_244 -> V_31 + V_244 -> V_48 - 1 , V_39 ) ;
} else {
F_336 ( & V_107 -> V_123 -> V_521 , V_244 -> V_31 ,
V_244 -> V_31 + V_244 -> V_48 - 1 , V_39 ) ;
}
V_107 -> V_522 ++ ;
return V_244 ;
}
static struct V_334 *
F_391 ( struct V_106 * V_107 ,
struct V_33 * V_34 , T_3 V_517 )
{
struct V_334 * V_369 ;
struct V_334 * V_338 = & V_34 -> V_36 -> V_267 ;
int V_28 ;
bool V_523 = false ;
V_369 = F_293 ( V_107 , V_34 ) ;
if ( F_290 ( V_369 -> V_56 == 0 ) )
goto V_524;
V_76:
V_28 = F_291 ( V_369 , V_517 ) ;
if ( ! V_28 )
return V_369 ;
if ( V_369 -> V_525 )
return F_383 ( V_28 ) ;
if ( V_369 -> type == V_526 && ! V_523 ) {
V_523 = true ;
F_308 ( V_34 -> V_36 ) ;
goto V_76;
}
if ( F_232 ( V_34 , V_345 ) ) {
static F_392 ( V_527 ,
V_528 * 10 ,
1 ) ;
if ( F_393 ( & V_527 ) )
F_394 ( 1 , V_529
L_25 , V_28 ) ;
}
V_524:
V_28 = F_288 ( V_34 , V_369 , V_517 ,
V_377 ) ;
if ( ! V_28 )
return V_369 ;
if ( V_369 -> type != V_526 &&
V_369 -> V_102 == V_338 -> V_102 ) {
V_28 = F_291 ( V_338 , V_517 ) ;
if ( ! V_28 )
return V_338 ;
}
return F_383 ( V_28 ) ;
}
static void F_395 ( struct V_11 * V_36 ,
struct V_334 * V_369 , T_3 V_517 )
{
F_294 ( V_369 , V_517 , 0 ) ;
F_295 ( V_36 , V_369 , NULL , 0 ) ;
}
struct V_65 * F_396 ( struct V_106 * V_107 ,
struct V_33 * V_34 , T_3 V_517 ,
T_2 V_16 , T_2 V_142 ,
struct V_435 * V_20 , int V_162 ,
T_2 V_530 , T_2 V_477 )
{
struct V_67 V_203 ;
struct V_334 * V_369 ;
struct V_65 * V_244 ;
T_2 V_6 = 0 ;
int V_28 ;
bool V_168 = F_74 ( V_34 -> V_36 ,
V_118 ) ;
V_369 = F_391 ( V_107 , V_34 , V_517 ) ;
if ( F_224 ( V_369 ) )
return F_397 ( V_369 ) ;
V_28 = F_372 ( V_107 , V_34 , V_517 , V_517 ,
V_477 , V_530 , & V_203 , 0 ) ;
if ( V_28 ) {
F_395 ( V_34 -> V_36 , V_369 , V_517 ) ;
return F_383 ( V_28 ) ;
}
V_244 = F_381 ( V_107 , V_34 , V_203 . V_21 ,
V_517 , V_162 ) ;
F_30 ( F_224 ( V_244 ) ) ;
if ( V_142 == V_531 ) {
if ( V_16 == 0 )
V_16 = V_203 . V_21 ;
V_6 |= V_122 ;
} else
F_30 ( V_16 > 0 ) ;
if ( V_142 != V_197 ) {
struct V_175 * V_125 ;
V_125 = F_197 () ;
F_30 ( ! V_125 ) ;
if ( V_20 )
memcpy ( & V_125 -> V_20 , V_20 , sizeof( V_125 -> V_20 ) ) ;
else
memset ( & V_125 -> V_20 , 0 , sizeof( V_125 -> V_20 ) ) ;
V_125 -> V_127 = V_6 ;
if ( V_168 )
V_125 -> V_207 = 0 ;
else
V_125 -> V_207 = 1 ;
V_125 -> V_126 = 1 ;
V_125 -> V_179 = 0 ;
V_125 -> V_162 = V_162 ;
V_28 = F_143 ( V_34 -> V_36 , V_107 ,
V_203 . V_21 ,
V_203 . V_32 , V_16 , V_142 ,
V_162 , V_218 ,
V_125 , 0 ) ;
F_30 ( V_28 ) ;
}
return V_244 ;
}
static T_1 void F_398 ( struct V_106 * V_107 ,
struct V_33 * V_34 ,
struct V_532 * V_533 ,
struct V_63 * V_64 )
{
T_2 V_26 ;
T_2 V_266 ;
T_2 V_109 ;
T_2 V_6 ;
T_3 V_70 ;
T_3 V_517 ;
struct V_67 V_20 ;
struct V_65 * V_534 ;
int V_28 ;
int V_535 ;
int V_536 = 0 ;
if ( V_64 -> V_81 [ V_533 -> V_162 ] < V_533 -> V_537 ) {
V_533 -> V_538 = V_533 -> V_538 * 2 / 3 ;
V_533 -> V_538 = F_362 ( V_533 -> V_538 , 2 ) ;
} else {
V_533 -> V_538 = V_533 -> V_538 * 3 / 2 ;
V_533 -> V_538 = F_24 ( int , V_533 -> V_538 ,
F_399 ( V_34 ) ) ;
}
V_534 = V_64 -> V_80 [ V_533 -> V_162 ] ;
V_70 = F_38 ( V_534 ) ;
V_517 = F_215 ( V_34 , V_533 -> V_162 - 1 ) ;
for ( V_535 = V_64 -> V_81 [ V_533 -> V_162 ] ; V_535 < V_70 ; V_535 ++ ) {
if ( V_536 >= V_533 -> V_538 )
break;
F_46 () ;
V_26 = F_214 ( V_534 , V_535 ) ;
V_266 = F_400 ( V_534 , V_535 ) ;
if ( V_535 == V_64 -> V_81 [ V_533 -> V_162 ] )
goto V_74;
if ( V_533 -> V_539 == V_540 &&
V_266 <= V_34 -> V_240 . V_32 )
continue;
V_28 = F_73 ( V_107 , V_34 , V_26 ,
V_533 -> V_162 - 1 , 1 , & V_109 ,
& V_6 ) ;
if ( V_28 < 0 )
continue;
F_30 ( V_109 == 0 ) ;
if ( V_533 -> V_539 == V_541 ) {
if ( V_109 == 1 )
goto V_74;
if ( V_533 -> V_162 == 1 &&
( V_6 & V_122 ) )
continue;
if ( ! V_533 -> V_542 ||
V_266 <= V_34 -> V_240 . V_32 )
continue;
F_121 ( V_534 , & V_20 , V_535 ) ;
V_28 = F_401 ( & V_20 ,
& V_533 -> V_543 ) ;
if ( V_28 < 0 )
continue;
} else {
if ( V_533 -> V_162 == 1 &&
( V_6 & V_122 ) )
continue;
}
V_74:
V_28 = F_402 ( V_34 , V_26 , V_517 ,
V_266 ) ;
if ( V_28 )
break;
V_536 ++ ;
}
V_533 -> V_537 = V_535 ;
}
static T_1 int F_403 ( struct V_106 * V_107 ,
struct V_33 * V_34 ,
struct V_63 * V_64 ,
struct V_532 * V_533 , int V_544 )
{
int V_162 = V_533 -> V_162 ;
struct V_65 * V_534 = V_64 -> V_80 [ V_162 ] ;
T_2 V_545 = V_122 ;
int V_28 ;
if ( V_533 -> V_539 == V_540 &&
F_207 ( V_534 ) != V_34 -> V_240 . V_21 )
return 1 ;
if ( V_544 &&
( ( V_533 -> V_539 == V_541 && V_533 -> V_109 [ V_162 ] != 1 ) ||
( V_533 -> V_539 == V_540 && ! ( V_533 -> V_6 [ V_162 ] & V_545 ) ) ) ) {
F_30 ( ! V_64 -> V_546 [ V_162 ] ) ;
V_28 = F_73 ( V_107 , V_34 ,
V_534 -> V_31 , V_162 , 1 ,
& V_533 -> V_109 [ V_162 ] ,
& V_533 -> V_6 [ V_162 ] ) ;
F_30 ( V_28 == - V_88 ) ;
if ( V_28 )
return V_28 ;
F_30 ( V_533 -> V_109 [ V_162 ] == 0 ) ;
}
if ( V_533 -> V_539 == V_541 ) {
if ( V_533 -> V_109 [ V_162 ] > 1 )
return 1 ;
if ( V_64 -> V_546 [ V_162 ] && ! V_533 -> V_169 ) {
F_404 ( V_534 , V_64 -> V_546 [ V_162 ] ) ;
V_64 -> V_546 [ V_162 ] = 0 ;
}
return 0 ;
}
if ( ! ( V_533 -> V_6 [ V_162 ] & V_545 ) ) {
F_30 ( ! V_64 -> V_546 [ V_162 ] ) ;
V_28 = F_216 ( V_107 , V_34 , V_534 , 1 , V_533 -> V_547 ) ;
F_30 ( V_28 ) ;
V_28 = F_217 ( V_107 , V_34 , V_534 , 0 , V_533 -> V_547 ) ;
F_30 ( V_28 ) ;
V_28 = F_196 ( V_107 , V_34 , V_534 -> V_31 ,
V_534 -> V_48 , V_545 ,
F_208 ( V_534 ) , 0 ) ;
F_30 ( V_28 ) ;
V_533 -> V_6 [ V_162 ] |= V_545 ;
}
if ( V_64 -> V_546 [ V_162 ] && V_162 > 0 ) {
F_404 ( V_534 , V_64 -> V_546 [ V_162 ] ) ;
V_64 -> V_546 [ V_162 ] = 0 ;
}
return 0 ;
}
static T_1 int F_405 ( struct V_106 * V_107 ,
struct V_33 * V_34 ,
struct V_63 * V_64 ,
struct V_532 * V_533 , int * V_544 )
{
T_2 V_26 ;
T_2 V_266 ;
T_2 V_16 ;
T_3 V_517 ;
struct V_67 V_20 ;
struct V_65 * V_213 ;
int V_162 = V_533 -> V_162 ;
int V_74 = 0 ;
int V_28 = 0 ;
V_266 = F_400 ( V_64 -> V_80 [ V_162 ] ,
V_64 -> V_81 [ V_162 ] ) ;
if ( V_533 -> V_539 == V_540 &&
V_266 <= V_34 -> V_240 . V_32 ) {
* V_544 = 1 ;
return 1 ;
}
V_26 = F_214 ( V_64 -> V_80 [ V_162 ] , V_64 -> V_81 [ V_162 ] ) ;
V_517 = F_215 ( V_34 , V_162 - 1 ) ;
V_213 = F_406 ( V_34 , V_26 , V_517 ) ;
if ( ! V_213 ) {
V_213 = F_382 ( V_34 , V_26 , V_517 ) ;
if ( ! V_213 )
return - V_88 ;
V_74 = 1 ;
}
F_386 ( V_213 ) ;
F_388 ( V_213 ) ;
V_28 = F_73 ( V_107 , V_34 , V_26 , V_162 - 1 , 1 ,
& V_533 -> V_109 [ V_162 - 1 ] ,
& V_533 -> V_6 [ V_162 - 1 ] ) ;
if ( V_28 < 0 ) {
F_407 ( V_213 ) ;
return V_28 ;
}
if ( F_290 ( V_533 -> V_109 [ V_162 - 1 ] == 0 ) ) {
F_177 ( V_34 -> V_36 , L_26 ) ;
F_81 () ;
}
* V_544 = 0 ;
if ( V_533 -> V_539 == V_541 ) {
if ( V_533 -> V_109 [ V_162 - 1 ] > 1 ) {
if ( V_162 == 1 &&
( V_533 -> V_6 [ 0 ] & V_122 ) )
goto V_548;
if ( ! V_533 -> V_542 ||
V_266 <= V_34 -> V_240 . V_32 )
goto V_548;
F_121 ( V_64 -> V_80 [ V_162 ] , & V_20 ,
V_64 -> V_81 [ V_162 ] ) ;
V_28 = F_401 ( & V_20 , & V_533 -> V_543 ) ;
if ( V_28 < 0 )
goto V_548;
V_533 -> V_539 = V_540 ;
V_533 -> V_549 = V_162 - 1 ;
}
} else {
if ( V_162 == 1 &&
( V_533 -> V_6 [ 0 ] & V_122 ) )
goto V_548;
}
if ( ! F_408 ( V_213 , V_266 , 0 ) ) {
F_407 ( V_213 ) ;
F_409 ( V_213 ) ;
V_213 = NULL ;
* V_544 = 1 ;
}
if ( ! V_213 ) {
if ( V_74 && V_162 == 1 )
F_398 ( V_107 , V_34 , V_533 , V_64 ) ;
V_213 = F_410 ( V_34 , V_26 , V_517 , V_266 ) ;
if ( ! V_213 || ! F_411 ( V_213 ) ) {
F_409 ( V_213 ) ;
return - V_170 ;
}
F_386 ( V_213 ) ;
F_388 ( V_213 ) ;
}
V_162 -- ;
F_30 ( V_162 != F_208 ( V_213 ) ) ;
V_64 -> V_80 [ V_162 ] = V_213 ;
V_64 -> V_81 [ V_162 ] = 0 ;
V_64 -> V_546 [ V_162 ] = V_550 ;
V_533 -> V_162 = V_162 ;
if ( V_533 -> V_162 == 1 )
V_533 -> V_537 = 0 ;
return 0 ;
V_548:
V_533 -> V_109 [ V_162 - 1 ] = 0 ;
V_533 -> V_6 [ V_162 - 1 ] = 0 ;
if ( V_533 -> V_539 == V_541 ) {
if ( V_533 -> V_6 [ V_162 ] & V_122 ) {
V_16 = V_64 -> V_80 [ V_162 ] -> V_31 ;
} else {
F_30 ( V_34 -> V_240 . V_21 !=
F_207 ( V_64 -> V_80 [ V_162 ] ) ) ;
V_16 = 0 ;
}
V_28 = V_250 ( V_107 , V_34 , V_26 , V_517 , V_16 ,
V_34 -> V_240 . V_21 , V_162 - 1 , 0 , 0 ) ;
F_30 ( V_28 ) ;
}
F_407 ( V_213 ) ;
F_409 ( V_213 ) ;
* V_544 = 1 ;
return 1 ;
}
static T_1 int F_412 ( struct V_106 * V_107 ,
struct V_33 * V_34 ,
struct V_63 * V_64 ,
struct V_532 * V_533 )
{
int V_28 ;
int V_162 = V_533 -> V_162 ;
struct V_65 * V_534 = V_64 -> V_80 [ V_162 ] ;
T_2 V_16 = 0 ;
if ( V_533 -> V_539 == V_540 ) {
F_30 ( V_533 -> V_549 < V_162 ) ;
if ( V_162 < V_533 -> V_549 )
goto V_71;
V_28 = F_41 ( V_64 , V_162 + 1 , & V_533 -> V_543 ) ;
if ( V_28 > 0 )
V_533 -> V_542 = 0 ;
V_533 -> V_539 = V_541 ;
V_533 -> V_549 = - 1 ;
V_64 -> V_81 [ V_162 ] = 0 ;
if ( ! V_64 -> V_546 [ V_162 ] ) {
F_30 ( V_162 == 0 ) ;
F_386 ( V_534 ) ;
F_388 ( V_534 ) ;
V_64 -> V_546 [ V_162 ] = V_550 ;
V_28 = F_73 ( V_107 , V_34 ,
V_534 -> V_31 , V_162 , 1 ,
& V_533 -> V_109 [ V_162 ] ,
& V_533 -> V_6 [ V_162 ] ) ;
if ( V_28 < 0 ) {
F_404 ( V_534 , V_64 -> V_546 [ V_162 ] ) ;
V_64 -> V_546 [ V_162 ] = 0 ;
return V_28 ;
}
F_30 ( V_533 -> V_109 [ V_162 ] == 0 ) ;
if ( V_533 -> V_109 [ V_162 ] == 1 ) {
F_404 ( V_534 , V_64 -> V_546 [ V_162 ] ) ;
V_64 -> V_546 [ V_162 ] = 0 ;
return 1 ;
}
}
}
F_30 ( V_533 -> V_109 [ V_162 ] > 1 && ! V_64 -> V_546 [ V_162 ] ) ;
if ( V_533 -> V_109 [ V_162 ] == 1 ) {
if ( V_162 == 0 ) {
if ( V_533 -> V_6 [ V_162 ] & V_122 )
V_28 = F_217 ( V_107 , V_34 , V_534 , 1 ,
V_533 -> V_547 ) ;
else
V_28 = F_217 ( V_107 , V_34 , V_534 , 0 ,
V_533 -> V_547 ) ;
F_30 ( V_28 ) ;
}
if ( ! V_64 -> V_546 [ V_162 ] &&
F_351 ( V_534 ) == V_107 -> V_263 ) {
F_386 ( V_534 ) ;
F_388 ( V_534 ) ;
V_64 -> V_546 [ V_162 ] = V_550 ;
}
F_387 ( V_107 , V_34 , V_534 ) ;
}
if ( V_534 == V_34 -> V_124 ) {
if ( V_533 -> V_6 [ V_162 ] & V_122 )
V_16 = V_534 -> V_31 ;
else
F_30 ( V_34 -> V_240 . V_21 !=
F_207 ( V_534 ) ) ;
} else {
if ( V_533 -> V_6 [ V_162 + 1 ] & V_122 )
V_16 = V_64 -> V_80 [ V_162 + 1 ] -> V_31 ;
else
F_30 ( V_34 -> V_240 . V_21 !=
F_207 ( V_64 -> V_80 [ V_162 + 1 ] ) ) ;
}
F_350 ( V_107 , V_34 , V_534 , V_16 , V_533 -> V_109 [ V_162 ] == 1 ) ;
V_71:
V_533 -> V_109 [ V_162 ] = 0 ;
V_533 -> V_6 [ V_162 ] = 0 ;
return 0 ;
}
static T_1 int F_413 ( struct V_106 * V_107 ,
struct V_33 * V_34 ,
struct V_63 * V_64 ,
struct V_532 * V_533 )
{
int V_162 = V_533 -> V_162 ;
int V_544 = 1 ;
int V_28 ;
while ( V_162 >= 0 ) {
V_28 = F_403 ( V_107 , V_34 , V_64 , V_533 , V_544 ) ;
if ( V_28 > 0 )
break;
if ( V_162 == 0 )
break;
if ( V_64 -> V_81 [ V_162 ] >=
F_38 ( V_64 -> V_80 [ V_162 ] ) )
break;
V_28 = F_405 ( V_107 , V_34 , V_64 , V_533 , & V_544 ) ;
if ( V_28 > 0 ) {
V_64 -> V_81 [ V_162 ] ++ ;
continue;
} else if ( V_28 < 0 )
return V_28 ;
V_162 = V_533 -> V_162 ;
}
return 0 ;
}
static T_1 int F_414 ( struct V_106 * V_107 ,
struct V_33 * V_34 ,
struct V_63 * V_64 ,
struct V_532 * V_533 , int V_551 )
{
int V_162 = V_533 -> V_162 ;
int V_28 ;
V_64 -> V_81 [ V_162 ] = F_38 ( V_64 -> V_80 [ V_162 ] ) ;
while ( V_162 < V_551 && V_64 -> V_80 [ V_162 ] ) {
V_533 -> V_162 = V_162 ;
if ( V_64 -> V_81 [ V_162 ] + 1 <
F_38 ( V_64 -> V_80 [ V_162 ] ) ) {
V_64 -> V_81 [ V_162 ] ++ ;
return 0 ;
} else {
V_28 = F_412 ( V_107 , V_34 , V_64 , V_533 ) ;
if ( V_28 > 0 )
return 0 ;
if ( V_64 -> V_546 [ V_162 ] ) {
F_404 ( V_64 -> V_80 [ V_162 ] ,
V_64 -> V_546 [ V_162 ] ) ;
V_64 -> V_546 [ V_162 ] = 0 ;
}
F_409 ( V_64 -> V_80 [ V_162 ] ) ;
V_64 -> V_80 [ V_162 ] = NULL ;
V_162 ++ ;
}
}
return 1 ;
}
int F_415 ( struct V_33 * V_34 ,
struct V_334 * V_369 , int V_542 ,
int V_547 )
{
struct V_63 * V_64 ;
struct V_106 * V_107 ;
struct V_33 * V_84 = V_34 -> V_36 -> V_84 ;
struct V_552 * V_241 = & V_34 -> V_241 ;
struct V_532 * V_533 ;
struct V_67 V_20 ;
int V_79 = 0 ;
int V_28 ;
int V_162 ;
V_64 = F_33 () ;
if ( ! V_64 ) {
V_79 = - V_88 ;
goto V_71;
}
V_533 = F_52 ( sizeof( * V_533 ) , V_39 ) ;
if ( ! V_533 ) {
F_49 ( V_64 ) ;
V_79 = - V_88 ;
goto V_71;
}
V_107 = F_416 ( V_84 , 0 ) ;
if ( F_224 ( V_107 ) ) {
V_79 = F_225 ( V_107 ) ;
goto V_119;
}
if ( V_369 )
V_107 -> V_369 = V_369 ;
if ( F_417 ( & V_241 -> V_553 ) == 0 ) {
V_162 = F_208 ( V_34 -> V_124 ) ;
V_64 -> V_80 [ V_162 ] = F_418 ( V_34 ) ;
F_388 ( V_64 -> V_80 [ V_162 ] ) ;
V_64 -> V_81 [ V_162 ] = 0 ;
V_64 -> V_546 [ V_162 ] = V_550 ;
memset ( & V_533 -> V_543 , 0 ,
sizeof( V_533 -> V_543 ) ) ;
} else {
F_419 ( & V_20 , & V_241 -> V_553 ) ;
memcpy ( & V_533 -> V_543 , & V_20 ,
sizeof( V_533 -> V_543 ) ) ;
V_162 = V_241 -> V_554 ;
F_30 ( V_162 == 0 ) ;
V_64 -> V_555 = V_162 ;
V_28 = F_37 ( NULL , V_34 , & V_20 , V_64 , 0 , 0 ) ;
V_64 -> V_555 = 0 ;
if ( V_28 < 0 ) {
V_79 = V_28 ;
goto V_556;
}
F_8 ( V_28 > 0 ) ;
F_126 ( V_64 , 0 ) ;
V_162 = F_208 ( V_34 -> V_124 ) ;
while ( 1 ) {
F_386 ( V_64 -> V_80 [ V_162 ] ) ;
F_388 ( V_64 -> V_80 [ V_162 ] ) ;
V_28 = F_73 ( V_107 , V_34 ,
V_64 -> V_80 [ V_162 ] -> V_31 ,
V_162 , 1 , & V_533 -> V_109 [ V_162 ] ,
& V_533 -> V_6 [ V_162 ] ) ;
if ( V_28 < 0 ) {
V_79 = V_28 ;
goto V_556;
}
F_30 ( V_533 -> V_109 [ V_162 ] == 0 ) ;
if ( V_162 == V_241 -> V_554 )
break;
F_407 ( V_64 -> V_80 [ V_162 ] ) ;
F_8 ( V_533 -> V_109 [ V_162 ] != 1 ) ;
V_162 -- ;
}
}
V_533 -> V_162 = V_162 ;
V_533 -> V_549 = - 1 ;
V_533 -> V_539 = V_541 ;
V_533 -> V_542 = V_542 ;
V_533 -> V_169 = 0 ;
V_533 -> V_547 = V_547 ;
V_533 -> V_538 = F_399 ( V_34 ) ;
while ( 1 ) {
if ( ! V_547 && F_39 ( V_34 -> V_36 ) ) {
F_420 ( L_27 ) ;
V_79 = - V_173 ;
goto V_556;
}
V_28 = F_413 ( V_107 , V_34 , V_64 , V_533 ) ;
if ( V_28 < 0 ) {
V_79 = V_28 ;
break;
}
V_28 = F_414 ( V_107 , V_34 , V_64 , V_533 , V_163 ) ;
if ( V_28 < 0 ) {
V_79 = V_28 ;
break;
}
if ( V_28 > 0 ) {
F_30 ( V_533 -> V_539 != V_541 ) ;
break;
}
if ( V_533 -> V_539 == V_541 ) {
V_162 = V_533 -> V_162 ;
F_421 ( V_64 -> V_80 [ V_162 ] ,
& V_241 -> V_553 ,
V_64 -> V_81 [ V_162 ] ) ;
V_241 -> V_554 = V_162 ;
}
F_30 ( V_533 -> V_162 == 0 ) ;
if ( F_422 ( V_107 , V_84 ) ) {
V_28 = F_423 ( V_107 , V_84 ,
& V_34 -> V_240 ,
V_241 ) ;
if ( V_28 ) {
F_146 ( V_107 , V_84 , V_28 ) ;
V_79 = V_28 ;
goto V_556;
}
F_424 ( V_107 , V_84 ) ;
V_107 = F_416 ( V_84 , 0 ) ;
if ( F_224 ( V_107 ) ) {
V_79 = F_225 ( V_107 ) ;
goto V_119;
}
if ( V_369 )
V_107 -> V_369 = V_369 ;
}
}
F_43 ( V_64 ) ;
if ( V_79 )
goto V_556;
V_28 = F_425 ( V_107 , V_84 , & V_34 -> V_240 ) ;
if ( V_28 ) {
F_146 ( V_107 , V_84 , V_28 ) ;
goto V_556;
}
if ( V_34 -> V_240 . V_21 != V_531 ) {
V_28 = F_426 ( V_84 , V_34 -> V_240 . V_21 ,
NULL , NULL ) ;
if ( V_28 < 0 ) {
F_146 ( V_107 , V_84 , V_28 ) ;
V_79 = V_28 ;
goto V_556;
} else if ( V_28 > 0 ) {
F_427 ( V_107 , V_84 ,
V_34 -> V_240 . V_21 ) ;
}
}
if ( V_34 -> V_557 ) {
F_428 ( V_84 -> V_36 , V_34 ) ;
} else {
F_409 ( V_34 -> V_124 ) ;
F_409 ( V_34 -> V_558 ) ;
F_9 ( V_34 ) ;
}
V_556:
F_424 ( V_107 , V_84 ) ;
V_119:
F_9 ( V_533 ) ;
F_49 ( V_64 ) ;
V_71:
if ( V_79 )
F_429 ( V_34 -> V_36 , V_79 ) ;
return V_79 ;
}
int F_430 ( struct V_106 * V_107 ,
struct V_33 * V_34 ,
struct V_65 * V_124 ,
struct V_65 * V_16 )
{
struct V_63 * V_64 ;
struct V_532 * V_533 ;
int V_162 ;
int V_559 ;
int V_28 = 0 ;
int V_560 ;
F_30 ( V_34 -> V_240 . V_21 != V_531 ) ;
V_64 = F_33 () ;
if ( ! V_64 )
return - V_88 ;
V_533 = F_52 ( sizeof( * V_533 ) , V_39 ) ;
if ( ! V_533 ) {
F_49 ( V_64 ) ;
return - V_88 ;
}
F_431 ( V_16 ) ;
V_559 = F_208 ( V_16 ) ;
F_432 ( V_16 ) ;
V_64 -> V_80 [ V_559 ] = V_16 ;
V_64 -> V_81 [ V_559 ] = F_38 ( V_16 ) ;
F_431 ( V_124 ) ;
V_162 = F_208 ( V_124 ) ;
V_64 -> V_80 [ V_162 ] = V_124 ;
V_64 -> V_81 [ V_162 ] = 0 ;
V_64 -> V_546 [ V_162 ] = V_550 ;
V_533 -> V_109 [ V_559 ] = 1 ;
V_533 -> V_6 [ V_559 ] = V_122 ;
V_533 -> V_162 = V_162 ;
V_533 -> V_549 = - 1 ;
V_533 -> V_539 = V_541 ;
V_533 -> V_542 = 0 ;
V_533 -> V_169 = 1 ;
V_533 -> V_547 = 1 ;
V_533 -> V_538 = F_399 ( V_34 ) ;
while ( 1 ) {
V_560 = F_413 ( V_107 , V_34 , V_64 , V_533 ) ;
if ( V_560 < 0 ) {
V_28 = V_560 ;
break;
}
V_560 = F_414 ( V_107 , V_34 , V_64 , V_533 , V_559 ) ;
if ( V_560 < 0 )
V_28 = V_560 ;
if ( V_560 != 0 )
break;
}
F_9 ( V_533 ) ;
F_49 ( V_64 ) ;
return V_28 ;
}
static T_2 F_433 ( struct V_33 * V_34 , T_2 V_6 )
{
T_2 V_311 ;
T_2 V_561 ;
V_561 = F_249 ( V_34 -> V_36 , V_6 ) ;
if ( V_561 )
return F_251 ( V_561 ) ;
V_311 = V_34 -> V_36 -> V_312 -> V_313 +
V_34 -> V_36 -> V_312 -> V_314 ;
V_561 = V_317 |
V_318 | V_319 |
V_278 | V_279 ;
if ( V_311 == 1 ) {
V_561 |= V_277 ;
V_561 = V_6 & ~ V_561 ;
if ( V_6 & V_317 )
return V_561 ;
if ( V_6 & ( V_278 |
V_279 ) )
return V_561 | V_277 ;
} else {
if ( V_6 & V_561 )
return V_6 ;
V_561 |= V_277 ;
V_561 = V_6 & ~ V_561 ;
if ( V_6 & V_277 )
return V_561 | V_278 ;
}
return V_6 ;
}
static int F_434 ( struct V_1 * V_2 , int V_337 )
{
struct V_99 * V_336 = V_2 -> V_102 ;
T_2 V_35 ;
T_2 V_562 ;
int V_28 = - V_331 ;
if ( ( V_336 -> V_6 &
( V_301 | V_299 ) ) &&
! V_337 )
V_562 = 1 * 1024 * 1024 ;
else
V_562 = 0 ;
F_11 ( & V_336 -> V_51 ) ;
F_11 ( & V_2 -> V_51 ) ;
if ( V_2 -> V_261 ) {
V_28 = 0 ;
goto V_71;
}
V_35 = V_2 -> V_20 . V_32 - V_2 -> V_9 - V_2 -> V_8 -
V_2 -> V_45 - F_334 ( & V_2 -> V_131 ) ;
if ( V_336 -> V_275 + V_336 -> V_286 + V_336 -> V_285 +
V_336 -> V_288 + V_336 -> V_287 + V_35 +
V_562 <= V_336 -> V_274 ) {
V_336 -> V_287 += V_35 ;
V_2 -> V_261 = 1 ;
V_28 = 0 ;
}
V_71:
F_13 ( & V_2 -> V_51 ) ;
F_13 ( & V_336 -> V_51 ) ;
return V_28 ;
}
int F_435 ( struct V_33 * V_34 ,
struct V_1 * V_2 )
{
struct V_106 * V_107 ;
T_2 V_563 ;
int V_28 ;
F_30 ( V_2 -> V_261 ) ;
V_107 = F_257 ( V_34 ) ;
if ( F_224 ( V_107 ) )
return F_225 ( V_107 ) ;
V_563 = F_433 ( V_34 , V_2 -> V_6 ) ;
if ( V_563 != V_2 -> V_6 ) {
V_28 = F_258 ( V_107 , V_34 , V_563 ,
V_330 ) ;
if ( V_28 < 0 )
goto V_71;
}
V_28 = F_434 ( V_2 , 0 ) ;
if ( ! V_28 )
goto V_71;
V_563 = F_252 ( V_34 , V_2 -> V_102 -> V_6 ) ;
V_28 = F_258 ( V_107 , V_34 , V_563 ,
V_330 ) ;
if ( V_28 < 0 )
goto V_71;
V_28 = F_434 ( V_2 , 0 ) ;
V_71:
F_259 ( V_107 , V_34 ) ;
return V_28 ;
}
int F_436 ( struct V_106 * V_107 ,
struct V_33 * V_34 , T_2 type )
{
T_2 V_563 = F_252 ( V_34 , type ) ;
return F_258 ( V_107 , V_34 , V_563 ,
V_330 ) ;
}
static T_2 F_437 ( struct V_100 * V_564 )
{
struct V_1 * V_13 ;
T_2 V_565 = 0 ;
int V_276 ;
F_363 (block_group, groups_list, list) {
F_11 ( & V_13 -> V_51 ) ;
if ( ! V_13 -> V_261 ) {
F_13 ( & V_13 -> V_51 ) ;
continue;
}
if ( V_13 -> V_6 & ( V_278 |
V_279 |
V_277 ) )
V_276 = 2 ;
else
V_276 = 1 ;
V_565 += ( V_13 -> V_20 . V_32 -
F_334 ( & V_13 -> V_131 ) ) *
V_276 ;
F_13 ( & V_13 -> V_51 ) ;
}
return V_565 ;
}
T_2 F_438 ( struct V_99 * V_336 )
{
int V_42 ;
T_2 V_565 = 0 ;
F_11 ( & V_336 -> V_51 ) ;
for( V_42 = 0 ; V_42 < V_282 ; V_42 ++ )
if ( ! F_162 ( & V_336 -> V_283 [ V_42 ] ) )
V_565 += F_437 (
& V_336 -> V_283 [ V_42 ] ) ;
F_13 ( & V_336 -> V_51 ) ;
return V_565 ;
}
void F_439 ( struct V_33 * V_34 ,
struct V_1 * V_2 )
{
struct V_99 * V_336 = V_2 -> V_102 ;
T_2 V_35 ;
F_30 ( ! V_2 -> V_261 ) ;
F_11 ( & V_336 -> V_51 ) ;
F_11 ( & V_2 -> V_51 ) ;
V_35 = V_2 -> V_20 . V_32 - V_2 -> V_9 - V_2 -> V_8 -
V_2 -> V_45 - F_334 ( & V_2 -> V_131 ) ;
V_336 -> V_287 -= V_35 ;
V_2 -> V_261 = 0 ;
F_13 ( & V_2 -> V_51 ) ;
F_13 ( & V_336 -> V_51 ) ;
}
int F_440 ( struct V_33 * V_34 , T_2 V_26 )
{
struct V_1 * V_13 ;
struct V_99 * V_102 ;
struct V_566 * V_312 = V_34 -> V_36 -> V_312 ;
struct V_567 * V_568 ;
T_2 V_569 ;
T_2 V_570 = 1 ;
T_2 V_571 = 0 ;
T_2 V_306 ;
int V_484 ;
int V_105 = 0 ;
int V_28 = 0 ;
V_13 = F_66 ( V_34 -> V_36 , V_26 ) ;
if ( ! V_13 )
return - 1 ;
V_569 = F_334 ( & V_13 -> V_131 ) ;
if ( ! V_569 )
goto V_71;
V_102 = V_13 -> V_102 ;
F_11 ( & V_102 -> V_51 ) ;
V_105 = V_102 -> V_105 ;
if ( ( V_102 -> V_274 != V_13 -> V_20 . V_32 ) &&
( V_102 -> V_275 + V_102 -> V_286 +
V_102 -> V_285 + V_102 -> V_287 +
V_569 < V_102 -> V_274 ) ) {
F_13 ( & V_102 -> V_51 ) ;
goto V_71;
}
F_13 ( & V_102 -> V_51 ) ;
V_28 = - 1 ;
V_306 = F_249 ( V_34 -> V_36 , V_13 -> V_6 ) ;
if ( V_306 ) {
V_484 = F_357 ( F_251 ( V_306 ) ) ;
} else {
if ( V_105 )
goto V_71;
V_484 = F_358 ( V_13 ) ;
}
if ( V_484 == V_469 ) {
V_570 = 4 ;
V_569 >>= 1 ;
} else if ( V_484 == V_470 ) {
V_570 = 2 ;
} else if ( V_484 == V_471 ) {
V_569 <<= 1 ;
} else if ( V_484 == V_472 ) {
V_570 = V_312 -> V_313 ;
F_441 ( V_569 , V_570 ) ;
}
F_35 ( & V_34 -> V_36 -> V_348 ) ;
F_363 (device, &fs_devices->alloc_list, dev_alloc_list) {
T_2 V_572 ;
if ( V_568 -> V_274 > V_568 -> V_275 + V_569 &&
! V_568 -> V_573 ) {
V_28 = F_442 ( V_568 , V_569 ,
& V_572 , NULL ) ;
if ( ! V_28 )
V_571 ++ ;
if ( V_571 >= V_570 )
break;
V_28 = - 1 ;
}
}
F_45 ( & V_34 -> V_36 -> V_348 ) ;
V_71:
F_6 ( V_13 ) ;
return V_28 ;
}
static int F_443 ( struct V_33 * V_34 ,
struct V_63 * V_64 , struct V_67 * V_20 )
{
int V_28 = 0 ;
struct V_67 V_136 ;
struct V_65 * V_66 ;
int V_535 ;
V_28 = F_37 ( NULL , V_34 , V_20 , V_64 , 0 , 0 ) ;
if ( V_28 < 0 )
goto V_71;
while ( 1 ) {
V_535 = V_64 -> V_81 [ 0 ] ;
V_66 = V_64 -> V_80 [ 0 ] ;
if ( V_535 >= F_38 ( V_66 ) ) {
V_28 = F_47 ( V_34 , V_64 ) ;
if ( V_28 == 0 )
continue;
if ( V_28 < 0 )
goto V_71;
break;
}
F_40 ( V_66 , & V_136 , V_535 ) ;
if ( V_136 . V_21 >= V_20 -> V_21 &&
V_136 . type == V_174 ) {
V_28 = 0 ;
goto V_71;
}
V_64 -> V_81 [ 0 ] ++ ;
}
V_71:
return V_28 ;
}
void F_444 ( struct V_11 * V_12 )
{
struct V_1 * V_13 ;
T_2 V_69 = 0 ;
while ( 1 ) {
struct V_253 * V_253 ;
V_13 = F_65 ( V_12 , V_69 ) ;
while ( V_13 ) {
F_11 ( & V_13 -> V_51 ) ;
if ( V_13 -> V_159 )
break;
F_13 ( & V_13 -> V_51 ) ;
V_13 = F_221 ( V_12 -> V_84 ,
V_13 ) ;
}
if ( ! V_13 ) {
if ( V_69 == 0 )
break;
V_69 = 0 ;
continue;
}
V_253 = V_13 -> V_253 ;
V_13 -> V_159 = 0 ;
V_13 -> V_253 = NULL ;
F_13 ( & V_13 -> V_51 ) ;
F_237 ( V_253 ) ;
V_69 = V_13 -> V_20 . V_21 + V_13 -> V_20 . V_32 ;
F_6 ( V_13 ) ;
}
}
int F_445 ( struct V_11 * V_12 )
{
struct V_1 * V_13 ;
struct V_99 * V_102 ;
struct V_49 * V_53 ;
struct V_14 * V_29 ;
F_61 ( & V_12 -> V_78 ) ;
while ( ! F_162 ( & V_12 -> V_97 ) ) {
V_53 = F_163 ( V_12 -> V_97 . V_213 ,
struct V_49 , V_89 ) ;
F_179 ( & V_53 -> V_89 ) ;
F_26 ( V_53 ) ;
}
F_63 ( & V_12 -> V_78 ) ;
F_11 ( & V_12 -> V_17 ) ;
while ( ( V_29 = F_175 ( & V_12 -> V_18 ) ) != NULL ) {
V_13 = F_12 ( V_29 , struct V_1 ,
V_19 ) ;
F_172 ( & V_13 -> V_19 ,
& V_12 -> V_18 ) ;
F_13 ( & V_12 -> V_17 ) ;
F_61 ( & V_13 -> V_102 -> V_284 ) ;
F_179 ( & V_13 -> V_89 ) ;
F_63 ( & V_13 -> V_102 -> V_284 ) ;
if ( V_13 -> V_3 == V_52 )
F_356 ( V_13 ) ;
if ( V_13 -> V_3 == V_93 )
F_19 ( V_12 -> V_62 , V_13 ) ;
F_446 ( V_13 ) ;
F_6 ( V_13 ) ;
F_11 ( & V_12 -> V_17 ) ;
}
F_13 ( & V_12 -> V_17 ) ;
F_447 () ;
F_310 ( V_12 ) ;
while( ! F_162 ( & V_12 -> V_102 ) ) {
V_102 = F_163 ( V_12 -> V_102 . V_213 ,
struct V_99 ,
V_89 ) ;
if ( F_232 ( V_12 -> V_84 , V_345 ) ) {
if ( V_102 -> V_285 > 0 ||
V_102 -> V_286 > 0 ||
V_102 -> V_288 > 0 ) {
F_8 ( 1 ) ;
F_272 ( V_102 , 0 , 0 ) ;
}
}
F_179 ( & V_102 -> V_89 ) ;
F_9 ( V_102 ) ;
}
return 0 ;
}
static void F_448 ( struct V_99 * V_102 ,
struct V_1 * V_2 )
{
int V_484 = F_358 ( V_2 ) ;
F_61 ( & V_102 -> V_284 ) ;
F_62 ( & V_2 -> V_89 , & V_102 -> V_283 [ V_484 ] ) ;
F_63 ( & V_102 -> V_284 ) ;
}
int F_449 ( struct V_33 * V_34 )
{
struct V_63 * V_64 ;
int V_28 ;
struct V_1 * V_2 ;
struct V_11 * V_12 = V_34 -> V_36 ;
struct V_99 * V_102 ;
struct V_67 V_20 ;
struct V_67 V_136 ;
struct V_65 * V_66 ;
int V_574 = 0 ;
T_2 V_575 ;
V_34 = V_12 -> V_62 ;
V_20 . V_21 = 0 ;
V_20 . V_32 = 0 ;
F_360 ( & V_20 , V_174 ) ;
V_64 = F_33 () ;
if ( ! V_64 )
return - V_88 ;
V_64 -> V_74 = 1 ;
V_575 = F_450 ( V_34 -> V_36 -> V_342 ) ;
if ( F_232 ( V_34 , V_268 ) &&
F_451 ( V_34 -> V_36 -> V_342 ) != V_575 )
V_574 = 1 ;
if ( F_232 ( V_34 , V_576 ) )
V_574 = 1 ;
while ( 1 ) {
V_28 = F_443 ( V_34 , V_64 , & V_20 ) ;
if ( V_28 > 0 )
break;
if ( V_28 != 0 )
goto error;
V_66 = V_64 -> V_80 [ 0 ] ;
F_40 ( V_66 , & V_136 , V_64 -> V_81 [ 0 ] ) ;
V_2 = F_52 ( sizeof( * V_2 ) , V_39 ) ;
if ( ! V_2 ) {
V_28 = - V_88 ;
goto error;
}
V_2 -> V_10 = F_52 ( sizeof( * V_2 -> V_10 ) ,
V_39 ) ;
if ( ! V_2 -> V_10 ) {
F_9 ( V_2 ) ;
V_28 = - V_88 ;
goto error;
}
F_56 ( & V_2 -> V_7 , 1 ) ;
F_243 ( & V_2 -> V_51 ) ;
V_2 -> V_36 = V_12 ;
F_53 ( & V_2 -> V_89 ) ;
F_53 ( & V_2 -> V_577 ) ;
if ( V_574 ) {
V_2 -> V_259 = V_270 ;
if ( F_232 ( V_34 , V_268 ) )
V_2 -> V_271 = 1 ;
}
F_452 ( V_66 , & V_2 -> V_131 ,
F_219 ( V_66 , V_64 -> V_81 [ 0 ] ) ,
sizeof( V_2 -> V_131 ) ) ;
memcpy ( & V_2 -> V_20 , & V_136 , sizeof( V_136 ) ) ;
V_20 . V_21 = V_136 . V_21 + V_136 . V_32 ;
F_43 ( V_64 ) ;
V_2 -> V_6 = F_453 ( & V_2 -> V_131 ) ;
V_2 -> V_325 = V_34 -> V_325 ;
V_2 -> V_578 = F_454 ( V_34 ,
& V_34 -> V_36 -> V_47 ,
V_136 . V_21 ) ;
F_455 ( V_2 ) ;
V_28 = F_21 ( V_34 , V_2 ) ;
if ( V_28 ) {
F_19 ( V_34 , V_2 ) ;
F_9 ( V_2 -> V_10 ) ;
F_9 ( V_2 ) ;
goto error;
}
if ( V_136 . V_32 == F_334 ( & V_2 -> V_131 ) ) {
V_2 -> V_96 = ( T_2 ) - 1 ;
V_2 -> V_3 = V_4 ;
F_19 ( V_34 , V_2 ) ;
} else if ( F_334 ( & V_2 -> V_131 ) == 0 ) {
V_2 -> V_96 = ( T_2 ) - 1 ;
V_2 -> V_3 = V_4 ;
F_27 ( V_2 , V_34 -> V_36 ,
V_136 . V_21 ,
V_136 . V_21 +
V_136 . V_32 ) ;
F_19 ( V_34 , V_2 ) ;
}
V_28 = F_10 ( V_34 -> V_36 , V_2 ) ;
if ( V_28 ) {
F_446 ( V_2 ) ;
F_6 ( V_2 ) ;
goto error;
}
V_28 = F_241 ( V_12 , V_2 -> V_6 , V_136 . V_32 ,
F_334 ( & V_2 -> V_131 ) ,
& V_102 ) ;
if ( V_28 ) {
F_446 ( V_2 ) ;
F_11 ( & V_12 -> V_17 ) ;
F_172 ( & V_2 -> V_19 ,
& V_12 -> V_18 ) ;
F_13 ( & V_12 -> V_17 ) ;
F_6 ( V_2 ) ;
goto error;
}
V_2 -> V_102 = V_102 ;
F_11 ( & V_2 -> V_102 -> V_51 ) ;
V_2 -> V_102 -> V_287 += V_2 -> V_45 ;
F_13 ( & V_2 -> V_102 -> V_51 ) ;
F_448 ( V_102 , V_2 ) ;
F_245 ( V_34 -> V_36 , V_2 -> V_6 ) ;
if ( F_456 ( V_34 , V_2 -> V_20 . V_21 ) )
F_434 ( V_2 , 1 ) ;
}
F_69 (space_info, &root->fs_info->space_info, list) {
if ( ! ( F_252 ( V_34 , V_102 -> V_6 ) &
( V_279 |
V_278 |
V_318 |
V_319 |
V_277 ) ) )
continue;
F_363 (cache, &space_info->block_groups[3], list)
F_434 ( V_2 , 1 ) ;
F_363 (cache, &space_info->block_groups[4], list)
F_434 ( V_2 , 1 ) ;
}
F_309 ( V_12 ) ;
V_28 = 0 ;
error:
F_49 ( V_64 ) ;
return V_28 ;
}
void F_191 ( struct V_106 * V_107 ,
struct V_33 * V_34 )
{
struct V_1 * V_13 , * V_315 ;
struct V_33 * V_62 = V_34 -> V_36 -> V_62 ;
struct V_579 V_131 ;
struct V_67 V_20 ;
int V_28 = 0 ;
F_342 (block_group, tmp, &trans->new_bgs,
new_bg_list) {
F_168 ( & V_13 -> V_580 ) ;
if ( V_28 )
continue;
F_11 ( & V_13 -> V_51 ) ;
memcpy ( & V_131 , & V_13 -> V_131 , sizeof( V_131 ) ) ;
memcpy ( & V_20 , & V_13 -> V_20 , sizeof( V_20 ) ) ;
F_13 ( & V_13 -> V_51 ) ;
V_28 = F_457 ( V_107 , V_62 , & V_20 , & V_131 ,
sizeof( V_131 ) ) ;
if ( V_28 )
F_146 ( V_107 , V_62 , V_28 ) ;
}
}
int F_458 ( struct V_106 * V_107 ,
struct V_33 * V_34 , T_2 V_275 ,
T_2 type , T_2 V_581 , T_2 V_582 ,
T_2 V_56 )
{
int V_28 ;
struct V_33 * V_62 ;
struct V_1 * V_2 ;
V_62 = V_34 -> V_36 -> V_62 ;
V_34 -> V_36 -> V_583 = V_107 -> V_263 ;
V_2 = F_52 ( sizeof( * V_2 ) , V_39 ) ;
if ( ! V_2 )
return - V_88 ;
V_2 -> V_10 = F_52 ( sizeof( * V_2 -> V_10 ) ,
V_39 ) ;
if ( ! V_2 -> V_10 ) {
F_9 ( V_2 ) ;
return - V_88 ;
}
V_2 -> V_20 . V_21 = V_582 ;
V_2 -> V_20 . V_32 = V_56 ;
V_2 -> V_20 . type = V_174 ;
V_2 -> V_325 = V_34 -> V_325 ;
V_2 -> V_36 = V_34 -> V_36 ;
V_2 -> V_578 = F_454 ( V_34 ,
& V_34 -> V_36 -> V_47 ,
V_582 ) ;
F_56 ( & V_2 -> V_7 , 1 ) ;
F_243 ( & V_2 -> V_51 ) ;
F_53 ( & V_2 -> V_89 ) ;
F_53 ( & V_2 -> V_577 ) ;
F_53 ( & V_2 -> V_580 ) ;
F_455 ( V_2 ) ;
F_335 ( & V_2 -> V_131 , V_275 ) ;
F_459 ( & V_2 -> V_131 , V_581 ) ;
V_2 -> V_6 = type ;
F_460 ( & V_2 -> V_131 , type ) ;
V_2 -> V_96 = ( T_2 ) - 1 ;
V_2 -> V_3 = V_4 ;
V_28 = F_21 ( V_34 , V_2 ) ;
if ( V_28 ) {
F_19 ( V_34 , V_2 ) ;
F_9 ( V_2 -> V_10 ) ;
F_9 ( V_2 ) ;
return V_28 ;
}
F_27 ( V_2 , V_34 -> V_36 , V_582 ,
V_582 + V_56 ) ;
F_19 ( V_34 , V_2 ) ;
V_28 = F_10 ( V_34 -> V_36 , V_2 ) ;
if ( V_28 ) {
F_446 ( V_2 ) ;
F_6 ( V_2 ) ;
return V_28 ;
}
V_28 = F_241 ( V_34 -> V_36 , V_2 -> V_6 , V_56 , V_275 ,
& V_2 -> V_102 ) ;
if ( V_28 ) {
F_446 ( V_2 ) ;
F_11 ( & V_34 -> V_36 -> V_17 ) ;
F_172 ( & V_2 -> V_19 ,
& V_34 -> V_36 -> V_18 ) ;
F_13 ( & V_34 -> V_36 -> V_17 ) ;
F_6 ( V_2 ) ;
return V_28 ;
}
F_308 ( V_34 -> V_36 ) ;
F_11 ( & V_2 -> V_102 -> V_51 ) ;
V_2 -> V_102 -> V_287 += V_2 -> V_45 ;
F_13 ( & V_2 -> V_102 -> V_51 ) ;
F_448 ( V_2 -> V_102 , V_2 ) ;
F_62 ( & V_2 -> V_580 , & V_107 -> V_237 ) ;
F_245 ( V_62 -> V_36 , type ) ;
return 0 ;
}
static void F_461 ( struct V_11 * V_36 , T_2 V_6 )
{
T_2 V_295 = F_246 ( V_6 ) &
V_296 ;
F_247 ( & V_36 -> V_297 ) ;
if ( V_6 & V_293 )
V_36 -> V_298 &= ~ V_295 ;
if ( V_6 & V_299 )
V_36 -> V_300 &= ~ V_295 ;
if ( V_6 & V_301 )
V_36 -> V_302 &= ~ V_295 ;
F_248 ( & V_36 -> V_297 ) ;
}
int F_462 ( struct V_106 * V_107 ,
struct V_33 * V_34 , T_2 V_584 )
{
struct V_63 * V_64 ;
struct V_1 * V_13 ;
struct V_479 * V_210 ;
struct V_33 * V_84 = V_34 -> V_36 -> V_84 ;
struct V_67 V_20 ;
struct V_253 * V_253 ;
int V_28 ;
int V_484 ;
int V_276 ;
V_34 = V_34 -> V_36 -> V_62 ;
V_13 = F_66 ( V_34 -> V_36 , V_584 ) ;
F_30 ( ! V_13 ) ;
F_30 ( ! V_13 -> V_261 ) ;
F_19 ( V_34 , V_13 ) ;
memcpy ( & V_20 , & V_13 -> V_20 , sizeof( V_20 ) ) ;
V_484 = F_358 ( V_13 ) ;
if ( V_13 -> V_6 & ( V_277 |
V_278 |
V_279 ) )
V_276 = 2 ;
else
V_276 = 1 ;
V_210 = & V_34 -> V_36 -> V_494 ;
F_11 ( & V_210 -> V_500 ) ;
F_366 ( V_13 , V_210 ) ;
F_13 ( & V_210 -> V_500 ) ;
V_210 = & V_34 -> V_36 -> V_492 ;
F_11 ( & V_210 -> V_500 ) ;
F_366 ( V_13 , V_210 ) ;
F_13 ( & V_210 -> V_500 ) ;
V_64 = F_33 () ;
if ( ! V_64 ) {
V_28 = - V_88 ;
goto V_71;
}
V_253 = F_223 ( V_84 , V_13 , V_64 ) ;
if ( ! F_224 ( V_253 ) ) {
V_28 = F_463 ( V_107 , V_253 ) ;
if ( V_28 ) {
F_464 ( V_253 ) ;
goto V_71;
}
F_465 ( V_253 ) ;
F_11 ( & V_13 -> V_51 ) ;
if ( V_13 -> V_159 ) {
V_13 -> V_159 = 0 ;
V_13 -> V_253 = NULL ;
F_13 ( & V_13 -> V_51 ) ;
F_237 ( V_253 ) ;
} else {
F_13 ( & V_13 -> V_51 ) ;
}
F_464 ( V_253 ) ;
}
V_20 . V_21 = V_585 ;
V_20 . V_32 = V_13 -> V_20 . V_21 ;
V_20 . type = 0 ;
V_28 = F_37 ( V_107 , V_84 , & V_20 , V_64 , - 1 , 1 ) ;
if ( V_28 < 0 )
goto V_71;
if ( V_28 > 0 )
F_43 ( V_64 ) ;
if ( V_28 == 0 ) {
V_28 = F_114 ( V_107 , V_84 , V_64 ) ;
if ( V_28 )
goto V_71;
F_43 ( V_64 ) ;
}
F_11 ( & V_34 -> V_36 -> V_17 ) ;
F_172 ( & V_13 -> V_19 ,
& V_34 -> V_36 -> V_18 ) ;
if ( V_34 -> V_36 -> V_25 == V_13 -> V_20 . V_21 )
V_34 -> V_36 -> V_25 = ( T_2 ) - 1 ;
F_13 ( & V_34 -> V_36 -> V_17 ) ;
F_61 ( & V_13 -> V_102 -> V_284 ) ;
F_168 ( & V_13 -> V_89 ) ;
if ( F_162 ( & V_13 -> V_102 -> V_283 [ V_484 ] ) )
F_461 ( V_34 -> V_36 , V_13 -> V_6 ) ;
F_63 ( & V_13 -> V_102 -> V_284 ) ;
if ( V_13 -> V_3 == V_52 )
F_356 ( V_13 ) ;
F_446 ( V_13 ) ;
F_11 ( & V_13 -> V_102 -> V_51 ) ;
V_13 -> V_102 -> V_274 -= V_13 -> V_20 . V_32 ;
V_13 -> V_102 -> V_287 -= V_13 -> V_20 . V_32 ;
V_13 -> V_102 -> V_280 -= V_13 -> V_20 . V_32 * V_276 ;
F_13 ( & V_13 -> V_102 -> V_51 ) ;
memcpy ( & V_20 , & V_13 -> V_20 , sizeof( V_20 ) ) ;
F_71 ( V_34 -> V_36 ) ;
F_6 ( V_13 ) ;
F_6 ( V_13 ) ;
V_28 = F_37 ( V_107 , V_34 , & V_20 , V_64 , - 1 , 1 ) ;
if ( V_28 > 0 )
V_28 = - V_170 ;
if ( V_28 < 0 )
goto V_71;
V_28 = F_114 ( V_107 , V_34 , V_64 ) ;
V_71:
F_49 ( V_64 ) ;
return V_28 ;
}
int F_466 ( struct V_11 * V_36 )
{
struct V_99 * V_102 ;
struct V_586 * V_587 ;
T_2 V_588 ;
T_2 V_6 ;
int V_589 = 0 ;
int V_28 ;
V_587 = V_36 -> V_342 ;
if ( ! F_467 ( V_587 ) )
return 1 ;
V_588 = F_468 ( V_587 ) ;
if ( V_588 & V_590 )
V_589 = 1 ;
V_6 = V_301 ;
V_28 = F_241 ( V_36 , V_6 , 0 , 0 , & V_102 ) ;
if ( V_28 )
goto V_71;
if ( V_589 ) {
V_6 = V_299 | V_293 ;
V_28 = F_241 ( V_36 , V_6 , 0 , 0 , & V_102 ) ;
} else {
V_6 = V_299 ;
V_28 = F_241 ( V_36 , V_6 , 0 , 0 , & V_102 ) ;
if ( V_28 )
goto V_71;
V_6 = V_293 ;
V_28 = F_241 ( V_36 , V_6 , 0 , 0 , & V_102 ) ;
}
V_71:
return V_28 ;
}
int F_469 ( struct V_33 * V_34 , T_2 V_31 , T_2 V_30 )
{
return F_343 ( V_34 , V_31 , V_30 ) ;
}
int F_470 ( struct V_33 * V_34 , T_2 V_26 ,
T_2 V_35 , T_2 * V_182 )
{
return F_140 ( V_34 , V_26 , V_35 , V_182 ) ;
}
int F_471 ( struct V_33 * V_34 , struct V_591 * V_592 )
{
struct V_11 * V_36 = V_34 -> V_36 ;
struct V_1 * V_2 = NULL ;
T_2 V_593 ;
T_2 V_31 ;
T_2 V_30 ;
T_2 V_594 = 0 ;
T_2 V_274 = F_265 ( V_36 -> V_342 ) ;
int V_28 = 0 ;
if ( V_592 -> V_48 == V_274 )
V_2 = F_65 ( V_36 , V_592 -> V_31 ) ;
else
V_2 = F_66 ( V_36 , V_592 -> V_31 ) ;
while ( V_2 ) {
if ( V_2 -> V_20 . V_21 >= ( V_592 -> V_31 + V_592 -> V_48 ) ) {
F_6 ( V_2 ) ;
break;
}
V_31 = F_362 ( V_592 -> V_31 , V_2 -> V_20 . V_21 ) ;
V_30 = F_276 ( V_592 -> V_31 + V_592 -> V_48 ,
V_2 -> V_20 . V_21 + V_2 -> V_20 . V_32 ) ;
if ( V_30 - V_31 >= V_592 -> V_595 ) {
if ( ! F_1 ( V_2 ) ) {
V_28 = F_50 ( V_2 , 0 ) ;
if ( ! V_28 )
F_356 ( V_2 ) ;
}
V_28 = F_472 ( V_2 ,
& V_593 ,
V_31 ,
V_30 ,
V_592 -> V_595 ) ;
V_594 += V_593 ;
if ( V_28 ) {
F_6 ( V_2 ) ;
break;
}
}
V_2 = F_221 ( V_36 -> V_84 , V_2 ) ;
}
V_592 -> V_48 = V_594 ;
return V_28 ;
}
