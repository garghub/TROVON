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
static inline T_2 F_184 ( struct V_33 * V_34 , T_2 V_229 )
{
T_2 V_35 ;
V_35 = V_229 * ( sizeof( struct V_113 ) +
sizeof( struct V_158 ) ) ;
if ( ! F_74 ( V_34 -> V_36 , V_118 ) )
V_35 += V_229 * sizeof( struct V_134 ) ;
return F_185 ( V_35 , F_186 ( V_34 ) ) ;
}
int F_187 ( struct V_106 * V_107 ,
struct V_33 * V_34 )
{
struct V_230 * V_231 ;
T_2 V_232 = V_107 -> V_123 -> V_112 . V_215 ;
T_2 V_35 ;
int V_28 = 0 ;
V_35 = F_188 ( V_34 , 1 ) ;
V_232 = F_184 ( V_34 , V_232 ) ;
if ( V_232 > 1 )
V_35 += ( V_232 - 1 ) * V_34 -> V_85 ;
V_35 <<= 1 ;
V_231 = & V_34 -> V_36 -> V_233 ;
if ( V_231 -> V_102 -> V_105 )
V_35 <<= 1 ;
F_11 ( & V_231 -> V_51 ) ;
if ( V_231 -> V_9 <= V_35 )
V_28 = 1 ;
F_13 ( & V_231 -> V_51 ) ;
return V_28 ;
}
int F_189 ( struct V_106 * V_107 ,
struct V_33 * V_34 , unsigned long V_7 )
{
struct V_14 * V_124 ;
struct V_111 * V_112 ;
struct V_200 * V_147 ;
struct V_100 V_210 ;
int V_28 ;
T_2 V_234 ;
int V_235 = V_7 == ( unsigned long ) - 1 ;
int V_236 = 0 ;
int V_237 ;
if ( V_107 -> V_208 )
return 0 ;
if ( V_34 == V_34 -> V_36 -> V_62 )
V_34 = V_34 -> V_36 -> V_84 ;
F_176 ( V_107 , V_34 -> V_36 ) ;
V_112 = & V_107 -> V_123 -> V_112 ;
F_53 ( & V_210 ) ;
if ( V_7 == 0 ) {
V_7 = V_112 -> V_217 * 2 ;
V_236 = 1 ;
}
if ( ! V_235 && ! V_236 ) {
int V_238 ;
int V_214 = F_183 ( & V_112 -> V_228 ) ;
V_82:
V_238 = F_190 ( & V_112 -> V_239 , 0 , 1 ) ;
if ( V_238 ) {
F_51 ( V_240 ) ;
if ( V_112 -> V_241 ||
! F_187 ( V_107 , V_34 ) )
return 0 ;
F_57 ( & V_112 -> V_86 , & V_240 ,
V_92 ) ;
V_238 = F_190 ( & V_112 -> V_239 , 0 , 1 ) ;
if ( V_238 ) {
F_58 () ;
F_59 ( & V_112 -> V_86 , & V_240 ) ;
if ( ! F_182 ( V_112 , V_214 , 256 ) )
goto V_82;
else
return 0 ;
} else {
F_59 ( & V_112 -> V_86 , & V_240 ) ;
goto V_76;
}
}
} else {
F_5 ( & V_112 -> V_239 ) ;
}
V_76:
V_237 = 0 ;
F_11 ( & V_112 -> V_51 ) ;
#ifdef F_191
V_112 -> V_242 = F_173 ( & V_112 -> V_34 ) ;
#endif
while ( 1 ) {
if ( ! ( V_235 || V_236 ) &&
! F_187 ( V_107 , V_34 ) )
break;
V_234 = V_112 -> V_242 ;
V_28 = F_192 ( V_107 , & V_210 ,
V_112 -> V_242 ) ;
if ( V_28 )
break;
V_28 = F_161 ( V_107 , V_34 , & V_210 ) ;
if ( V_28 < 0 ) {
F_193 ( & V_210 ) ;
F_13 ( & V_112 -> V_51 ) ;
F_146 ( V_107 , V_34 , V_28 ) ;
F_194 ( & V_112 -> V_239 ) ;
F_48 ( & V_112 -> V_86 ) ;
return V_28 ;
}
F_195 ( V_28 , & V_112 -> V_228 ) ;
V_7 -= F_24 (unsigned long, ret, count) ;
if ( V_7 == 0 )
break;
if ( V_234 >= V_112 -> V_242 ) {
if ( V_237 == 0 ) {
V_237 = 1 ;
} else {
F_30 ( V_235 ) ;
break;
}
}
if ( V_28 ) {
V_237 = 0 ;
}
}
if ( V_235 ) {
if ( ! F_162 ( & V_107 -> V_243 ) ) {
F_13 ( & V_112 -> V_51 ) ;
F_196 ( V_107 , V_34 ) ;
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
V_124 = F_197 ( V_124 ) ;
}
F_13 ( & V_112 -> V_51 ) ;
F_198 ( 1 ) ;
goto V_76;
}
V_71:
F_194 ( & V_112 -> V_239 ) ;
F_2 () ;
if ( F_199 ( & V_112 -> V_86 ) )
F_48 ( & V_112 -> V_86 ) ;
F_13 ( & V_112 -> V_51 ) ;
F_200 ( V_107 ) ;
return 0 ;
}
int F_201 ( struct V_106 * V_107 ,
struct V_33 * V_34 ,
T_2 V_26 , T_2 V_35 , T_2 V_6 ,
int V_162 , int V_179 )
{
struct V_175 * V_125 ;
int V_28 ;
V_125 = F_202 () ;
if ( ! V_125 )
return - V_88 ;
V_125 -> V_127 = V_6 ;
V_125 -> V_126 = 1 ;
V_125 -> V_207 = 0 ;
V_125 -> V_179 = V_179 ? 1 : 0 ;
V_125 -> V_162 = V_162 ;
V_28 = F_203 ( V_34 -> V_36 , V_107 , V_26 ,
V_35 , V_125 ) ;
if ( V_28 )
F_170 ( V_125 ) ;
return V_28 ;
}
static T_1 int F_204 ( struct V_106 * V_107 ,
struct V_33 * V_34 ,
struct V_63 * V_64 ,
T_2 V_21 , T_2 V_32 , T_2 V_26 )
{
struct V_110 * V_101 ;
struct V_200 * V_147 ;
struct V_202 * V_244 ;
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
V_124 = F_205 ( & V_101 -> V_124 . V_14 ) ;
if ( ! V_124 )
goto V_245;
V_147 = F_12 ( V_124 , struct V_200 , V_14 ) ;
if ( V_147 -> V_26 != V_26 )
goto V_245;
V_28 = 1 ;
if ( V_147 -> type != V_151 )
goto V_245;
V_244 = F_148 ( V_147 ) ;
V_124 = F_205 ( V_124 ) ;
if ( V_124 ) {
int V_214 = V_147 -> V_214 ;
V_147 = F_12 ( V_124 , struct V_200 , V_14 ) ;
if ( V_147 -> V_26 == V_26 && V_147 -> V_214 == V_214 )
goto V_245;
}
if ( V_244 -> V_34 != V_34 -> V_246 . V_21 ||
V_244 -> V_21 != V_21 || V_244 -> V_32 != V_32 )
goto V_245;
V_28 = 0 ;
V_245:
F_45 ( & V_101 -> V_77 ) ;
V_71:
F_13 ( & V_112 -> V_51 ) ;
return V_28 ;
}
static T_1 int F_206 ( struct V_106 * V_107 ,
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
if ( F_207 ( V_66 , V_114 ) <=
F_208 ( & V_34 -> V_247 ) )
goto V_71;
V_159 = (struct V_158 * ) ( V_114 + 1 ) ;
if ( F_117 ( V_66 , V_159 ) !=
V_151 )
goto V_71;
V_147 = (struct V_146 * ) ( & V_159 -> V_32 ) ;
if ( F_77 ( V_66 , V_114 ) !=
F_111 ( V_66 , V_147 ) ||
F_98 ( V_66 , V_147 ) !=
V_34 -> V_246 . V_21 ||
F_99 ( V_66 , V_147 ) != V_21 ||
F_100 ( V_66 , V_147 ) != V_32 )
goto V_71;
V_28 = 0 ;
V_71:
return V_28 ;
}
int F_209 ( struct V_106 * V_107 ,
struct V_33 * V_34 ,
T_2 V_21 , T_2 V_32 , T_2 V_26 )
{
struct V_63 * V_64 ;
int V_28 ;
int V_248 ;
V_64 = F_33 () ;
if ( ! V_64 )
return - V_149 ;
do {
V_28 = F_206 ( V_107 , V_34 , V_64 , V_21 ,
V_32 , V_26 ) ;
if ( V_28 && V_28 != - V_149 )
goto V_71;
V_248 = F_204 ( V_107 , V_34 , V_64 , V_21 ,
V_32 , V_26 ) ;
} while ( V_248 == - V_173 );
if ( V_248 && V_248 != - V_149 ) {
V_28 = V_248 ;
goto V_71;
}
if ( V_28 != - V_149 || V_248 != - V_149 )
V_28 = 0 ;
V_71:
F_49 ( V_64 ) ;
if ( V_34 -> V_246 . V_21 == V_249 )
F_8 ( V_28 > 0 ) ;
return V_28 ;
}
static int F_210 ( struct V_106 * V_107 ,
struct V_33 * V_34 ,
struct V_65 * V_250 ,
int V_251 , int V_252 , int V_196 )
{
T_2 V_26 ;
T_2 V_35 ;
T_2 V_16 ;
T_2 V_204 ;
T_3 V_70 ;
struct V_67 V_20 ;
struct V_253 * V_254 ;
int V_42 ;
int V_162 ;
int V_28 = 0 ;
int (* F_211)( struct V_106 * , struct V_33 * ,
T_2 , T_2 , T_2 , T_2 , T_2 , T_2 , int );
V_204 = F_212 ( V_250 ) ;
V_70 = F_38 ( V_250 ) ;
V_162 = F_213 ( V_250 ) ;
if ( ! V_34 -> V_255 && V_162 == 0 )
return 0 ;
if ( V_252 )
F_211 = F_142 ;
else
F_211 = V_256 ;
if ( V_251 )
V_16 = V_250 -> V_31 ;
else
V_16 = 0 ;
for ( V_42 = 0 ; V_42 < V_70 ; V_42 ++ ) {
if ( V_162 == 0 ) {
F_40 ( V_250 , & V_20 , V_42 ) ;
if ( F_214 ( & V_20 ) != V_257 )
continue;
V_254 = F_76 ( V_250 , V_42 ,
struct V_253 ) ;
if ( F_215 ( V_250 , V_254 ) ==
V_258 )
continue;
V_26 = F_216 ( V_250 , V_254 ) ;
if ( V_26 == 0 )
continue;
V_35 = F_217 ( V_250 , V_254 ) ;
V_20 . V_32 -= F_218 ( V_250 , V_254 ) ;
V_28 = F_211 ( V_107 , V_34 , V_26 , V_35 ,
V_16 , V_204 , V_20 . V_21 ,
V_20 . V_32 , V_196 ) ;
if ( V_28 )
goto V_152;
} else {
V_26 = F_219 ( V_250 , V_42 ) ;
V_35 = F_220 ( V_34 , V_162 - 1 ) ;
V_28 = F_211 ( V_107 , V_34 , V_26 , V_35 ,
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
int F_221 ( struct V_106 * V_107 , struct V_33 * V_34 ,
struct V_65 * V_250 , int V_251 , int V_196 )
{
return F_210 ( V_107 , V_34 , V_250 , V_251 , 1 , V_196 ) ;
}
int F_222 ( struct V_106 * V_107 , struct V_33 * V_34 ,
struct V_65 * V_250 , int V_251 , int V_196 )
{
return F_210 ( V_107 , V_34 , V_250 , V_251 , 0 , V_196 ) ;
}
static int F_223 ( struct V_106 * V_107 ,
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
V_135 = F_224 ( V_66 , V_64 -> V_81 [ 0 ] ) ;
F_225 ( V_66 , & V_2 -> V_131 , V_135 , sizeof( V_2 -> V_131 ) ) ;
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
F_226 ( struct V_33 * V_34 ,
struct V_1 * V_2 )
{
struct V_14 * V_124 ;
F_11 ( & V_34 -> V_36 -> V_17 ) ;
V_124 = F_197 ( & V_2 -> V_19 ) ;
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
static int F_227 ( struct V_1 * V_13 ,
struct V_106 * V_107 ,
struct V_63 * V_64 )
{
struct V_33 * V_34 = V_13 -> V_36 -> V_84 ;
struct V_259 * V_259 = NULL ;
T_2 V_260 = 0 ;
int V_261 = V_262 ;
int V_263 = 0 ;
int V_264 = 0 ;
int V_28 = 0 ;
if ( V_13 -> V_20 . V_32 < ( 100 * 1024 * 1024 ) ) {
F_11 ( & V_13 -> V_51 ) ;
V_13 -> V_265 = V_266 ;
F_13 ( & V_13 -> V_51 ) ;
return 0 ;
}
V_76:
V_259 = F_228 ( V_34 , V_13 , V_64 ) ;
if ( F_229 ( V_259 ) && F_230 ( V_259 ) != - V_149 ) {
V_28 = F_230 ( V_259 ) ;
F_43 ( V_64 ) ;
goto V_71;
}
if ( F_229 ( V_259 ) ) {
F_30 ( V_264 ) ;
V_264 ++ ;
if ( V_13 -> V_267 )
goto V_119;
V_28 = F_231 ( V_34 , V_107 , V_13 , V_64 ) ;
if ( V_28 )
goto V_119;
goto V_76;
}
if ( V_13 -> V_268 == V_107 -> V_269 &&
F_232 ( V_259 ) ) {
V_261 = V_270 ;
goto V_271;
}
F_233 ( V_259 ) -> V_272 = 0 ;
V_28 = F_234 ( V_107 , V_34 , V_259 ) ;
F_8 ( V_28 ) ;
if ( F_232 ( V_259 ) > 0 ) {
V_28 = F_235 ( V_34 ,
& V_34 -> V_36 -> V_233 ) ;
if ( V_28 )
goto V_271;
V_28 = F_236 ( V_34 , V_107 , V_64 ,
V_259 ) ;
if ( V_28 )
goto V_271;
}
F_11 ( & V_13 -> V_51 ) ;
if ( V_13 -> V_3 != V_4 ||
! F_237 ( V_34 , V_273 ) ) {
V_261 = V_266 ;
F_13 ( & V_13 -> V_51 ) ;
goto V_271;
}
F_13 ( & V_13 -> V_51 ) ;
V_263 = ( int ) F_185 ( V_13 -> V_20 . V_32 , 256 * 1024 * 1024 ) ;
if ( ! V_263 )
V_263 = 1 ;
V_263 *= 16 ;
V_263 *= V_274 ;
V_28 = F_238 ( V_259 , V_263 ) ;
if ( V_28 )
goto V_271;
V_28 = F_239 ( V_259 , V_107 , 0 , 0 , V_263 ,
V_263 , V_263 ,
& V_260 ) ;
if ( ! V_28 )
V_261 = V_270 ;
F_240 ( V_259 , V_263 ) ;
V_271:
F_241 ( V_259 ) ;
V_119:
F_43 ( V_64 ) ;
V_71:
F_11 ( & V_13 -> V_51 ) ;
if ( ! V_28 && V_261 == V_270 )
V_13 -> V_268 = V_107 -> V_269 ;
V_13 -> V_265 = V_261 ;
F_13 ( & V_13 -> V_51 ) ;
return V_28 ;
}
int F_242 ( struct V_106 * V_107 ,
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
if ( V_2 -> V_265 == V_275 )
break;
V_2 = F_226 ( V_34 , V_2 ) ;
}
if ( ! V_2 ) {
if ( V_69 == 0 )
break;
V_69 = 0 ;
continue;
}
V_79 = F_227 ( V_2 , V_107 , V_64 ) ;
V_69 = V_2 -> V_20 . V_21 + V_2 -> V_20 . V_32 ;
F_6 ( V_2 ) ;
}
while ( 1 ) {
if ( V_69 == 0 ) {
V_79 = F_189 ( V_107 , V_34 ,
( unsigned long ) - 1 ) ;
if ( V_79 )
goto V_71;
}
V_2 = F_65 ( V_34 -> V_36 , V_69 ) ;
while ( V_2 ) {
if ( V_2 -> V_265 == V_275 ) {
F_6 ( V_2 ) ;
goto V_76;
}
if ( V_2 -> V_276 )
break;
V_2 = F_226 ( V_34 , V_2 ) ;
}
if ( ! V_2 ) {
if ( V_69 == 0 )
break;
V_69 = 0 ;
continue;
}
if ( V_2 -> V_265 == V_270 )
V_2 -> V_265 = V_277 ;
V_2 -> V_276 = 0 ;
V_69 = V_2 -> V_20 . V_21 + V_2 -> V_20 . V_32 ;
V_79 = F_223 ( V_107 , V_34 , V_64 , V_2 ) ;
if ( V_79 )
goto V_71;
F_6 ( V_2 ) ;
}
while ( 1 ) {
if ( V_69 == 0 ) {
V_79 = F_189 ( V_107 , V_34 ,
( unsigned long ) - 1 ) ;
if ( V_79 )
goto V_71;
}
V_2 = F_65 ( V_34 -> V_36 , V_69 ) ;
while ( V_2 ) {
if ( V_2 -> V_276 ) {
F_6 ( V_2 ) ;
goto V_76;
}
if ( V_2 -> V_265 == V_277 )
break;
V_2 = F_226 ( V_34 , V_2 ) ;
}
if ( ! V_2 ) {
if ( V_69 == 0 )
break;
V_69 = 0 ;
continue;
}
V_79 = F_243 ( V_34 , V_107 , V_2 , V_64 ) ;
if ( ! V_79 && V_2 -> V_265 == V_277 )
V_2 -> V_265 = V_266 ;
V_69 = V_2 -> V_20 . V_21 + V_2 -> V_20 . V_32 ;
F_6 ( V_2 ) ;
}
V_71:
F_49 ( V_64 ) ;
return V_79 ;
}
int F_244 ( struct V_33 * V_34 , T_2 V_26 )
{
struct V_1 * V_13 ;
int V_278 = 0 ;
V_13 = F_66 ( V_34 -> V_36 , V_26 ) ;
if ( ! V_13 || V_13 -> V_267 )
V_278 = 1 ;
if ( V_13 )
F_6 ( V_13 ) ;
return V_278 ;
}
static int F_245 ( struct V_11 * V_12 , T_2 V_6 ,
T_2 V_279 , T_2 V_280 ,
struct V_99 * * V_102 )
{
struct V_99 * V_103 ;
int V_42 ;
int V_281 ;
int V_28 ;
if ( V_6 & ( V_282 | V_283 |
V_284 ) )
V_281 = 2 ;
else
V_281 = 1 ;
V_103 = F_67 ( V_12 , V_6 ) ;
if ( V_103 ) {
F_11 ( & V_103 -> V_51 ) ;
V_103 -> V_279 += V_279 ;
V_103 -> V_285 += V_279 * V_281 ;
V_103 -> V_280 += V_280 ;
V_103 -> V_286 += V_280 * V_281 ;
V_103 -> V_105 = 0 ;
F_13 ( & V_103 -> V_51 ) ;
* V_102 = V_103 ;
return 0 ;
}
V_103 = F_52 ( sizeof( * V_103 ) , V_39 ) ;
if ( ! V_103 )
return - V_88 ;
V_28 = F_246 ( & V_103 -> V_287 , 0 ) ;
if ( V_28 ) {
F_9 ( V_103 ) ;
return V_28 ;
}
for ( V_42 = 0 ; V_42 < V_288 ; V_42 ++ )
F_53 ( & V_103 -> V_289 [ V_42 ] ) ;
F_247 ( & V_103 -> V_290 ) ;
F_248 ( & V_103 -> V_51 ) ;
V_103 -> V_6 = V_6 & V_104 ;
V_103 -> V_279 = V_279 ;
V_103 -> V_285 = V_279 * V_281 ;
V_103 -> V_280 = V_280 ;
V_103 -> V_286 = V_280 * V_281 ;
V_103 -> V_291 = 0 ;
V_103 -> V_292 = 0 ;
V_103 -> V_293 = 0 ;
V_103 -> V_294 = 0 ;
V_103 -> V_105 = 0 ;
V_103 -> V_295 = V_296 ;
V_103 -> V_297 = 0 ;
V_103 -> V_298 = 0 ;
F_55 ( & V_103 -> V_86 ) ;
* V_102 = V_103 ;
F_249 ( & V_103 -> V_89 , & V_12 -> V_102 ) ;
if ( V_6 & V_299 )
V_12 -> V_300 = V_103 ;
return 0 ;
}
static void F_250 ( struct V_11 * V_36 , T_2 V_6 )
{
T_2 V_301 = F_251 ( V_6 ) &
V_302 ;
F_252 ( & V_36 -> V_303 ) ;
if ( V_6 & V_299 )
V_36 -> V_304 |= V_301 ;
if ( V_6 & V_305 )
V_36 -> V_306 |= V_301 ;
if ( V_6 & V_307 )
V_36 -> V_308 |= V_301 ;
F_253 ( & V_36 -> V_303 ) ;
}
static T_2 F_254 ( struct V_11 * V_36 , T_2 V_6 )
{
struct V_309 * V_310 = V_36 -> V_311 ;
T_2 V_312 = 0 ;
if ( ! V_310 )
return 0 ;
if ( V_6 & V_299 &&
V_310 -> V_313 . V_6 & V_314 ) {
V_312 = V_299 | V_310 -> V_313 . V_312 ;
} else if ( V_6 & V_307 &&
V_310 -> V_315 . V_6 & V_314 ) {
V_312 = V_307 | V_310 -> V_315 . V_312 ;
} else if ( V_6 & V_305 &&
V_310 -> V_316 . V_6 & V_314 ) {
V_312 = V_305 | V_310 -> V_316 . V_312 ;
}
return V_312 ;
}
static T_2 F_255 ( struct V_33 * V_34 , T_2 V_6 )
{
T_2 V_317 = V_34 -> V_36 -> V_318 -> V_319 +
V_34 -> V_36 -> V_318 -> V_320 ;
T_2 V_312 ;
T_2 V_321 ;
F_11 ( & V_34 -> V_36 -> V_322 ) ;
V_312 = F_254 ( V_34 -> V_36 , V_6 ) ;
if ( V_312 ) {
if ( ( V_6 & V_312 ) & V_302 ) {
F_13 ( & V_34 -> V_36 -> V_322 ) ;
return F_256 ( V_312 ) ;
}
}
F_13 ( & V_34 -> V_36 -> V_322 ) ;
if ( V_317 == 1 )
V_6 &= ~ ( V_283 | V_323 |
V_324 ) ;
if ( V_317 < 3 )
V_6 &= ~ V_325 ;
if ( V_317 < 4 )
V_6 &= ~ V_284 ;
V_321 = V_6 & ( V_282 | V_323 |
V_283 | V_324 |
V_325 | V_284 ) ;
V_6 &= ~ V_321 ;
if ( V_321 & V_325 )
V_321 = V_325 ;
else if ( V_321 & V_324 )
V_321 = V_324 ;
else if ( V_321 & V_284 )
V_321 = V_284 ;
else if ( V_321 & V_283 )
V_321 = V_283 ;
else if ( V_321 & V_323 )
V_321 = V_323 ;
return F_256 ( V_6 | V_321 ) ;
}
static T_2 F_257 ( struct V_33 * V_34 , T_2 V_6 )
{
unsigned V_214 ;
do {
V_214 = F_258 ( & V_34 -> V_36 -> V_303 ) ;
if ( V_6 & V_299 )
V_6 |= V_34 -> V_36 -> V_304 ;
else if ( V_6 & V_307 )
V_6 |= V_34 -> V_36 -> V_308 ;
else if ( V_6 & V_305 )
V_6 |= V_34 -> V_36 -> V_306 ;
} while ( F_259 ( & V_34 -> V_36 -> V_303 , V_214 ) );
return F_255 ( V_34 , V_6 ) ;
}
T_2 F_260 ( struct V_33 * V_34 , int V_313 )
{
T_2 V_6 ;
T_2 V_28 ;
if ( V_313 )
V_6 = V_299 ;
else if ( V_34 == V_34 -> V_36 -> V_326 )
V_6 = V_307 ;
else
V_6 = V_305 ;
V_28 = F_257 ( V_34 , V_6 ) ;
return V_28 ;
}
int F_238 ( struct V_259 * V_259 , T_2 V_327 )
{
struct V_99 * V_300 ;
struct V_33 * V_34 = F_233 ( V_259 ) -> V_34 ;
struct V_11 * V_36 = V_34 -> V_36 ;
T_2 V_328 ;
int V_28 = 0 , V_329 = 0 , V_330 = 1 ;
V_327 = F_261 ( V_327 , V_34 -> V_331 ) ;
if ( V_34 == V_34 -> V_36 -> V_84 ||
F_233 ( V_259 ) -> V_332 . V_21 == V_333 ) {
V_330 = 0 ;
V_329 = 1 ;
}
V_300 = V_36 -> V_300 ;
if ( ! V_300 )
goto V_334;
V_76:
F_11 ( & V_300 -> V_51 ) ;
V_328 = V_300 -> V_280 + V_300 -> V_292 +
V_300 -> V_291 + V_300 -> V_293 +
V_300 -> V_294 ;
if ( V_328 + V_327 > V_300 -> V_279 ) {
struct V_106 * V_107 ;
if ( ! V_300 -> V_105 && V_330 ) {
T_2 V_335 ;
V_300 -> V_295 = V_336 ;
F_13 ( & V_300 -> V_51 ) ;
V_334:
V_335 = F_260 ( V_34 , 1 ) ;
V_107 = F_262 ( V_34 ) ;
if ( F_229 ( V_107 ) )
return F_230 ( V_107 ) ;
V_28 = F_263 ( V_107 , V_34 -> V_36 -> V_62 ,
V_335 ,
V_296 ) ;
F_264 ( V_107 , V_34 ) ;
if ( V_28 < 0 ) {
if ( V_28 != - V_337 )
return V_28 ;
else
goto V_338;
}
if ( ! V_300 )
V_300 = V_36 -> V_300 ;
goto V_76;
}
if ( F_265 ( & V_300 -> V_287 ,
V_327 ) < 0 )
V_329 = 1 ;
F_13 ( & V_300 -> V_51 ) ;
V_338:
if ( ! V_329 &&
! F_183 ( & V_34 -> V_36 -> V_339 ) ) {
V_329 = 1 ;
V_107 = F_262 ( V_34 ) ;
if ( F_229 ( V_107 ) )
return F_230 ( V_107 ) ;
V_28 = F_266 ( V_107 , V_34 ) ;
if ( V_28 )
return V_28 ;
goto V_76;
}
return - V_337 ;
}
V_300 -> V_294 += V_327 ;
F_267 ( V_34 -> V_36 , L_6 ,
V_300 -> V_6 , V_327 , 1 ) ;
F_13 ( & V_300 -> V_51 ) ;
return 0 ;
}
void F_240 ( struct V_259 * V_259 , T_2 V_327 )
{
struct V_33 * V_34 = F_233 ( V_259 ) -> V_34 ;
struct V_99 * V_300 ;
V_327 = F_261 ( V_327 , V_34 -> V_331 ) ;
V_300 = V_34 -> V_36 -> V_300 ;
F_11 ( & V_300 -> V_51 ) ;
F_8 ( V_300 -> V_294 < V_327 ) ;
V_300 -> V_294 -= V_327 ;
F_267 ( V_34 -> V_36 , L_6 ,
V_300 -> V_6 , V_327 , 0 ) ;
F_13 ( & V_300 -> V_51 ) ;
}
static void F_268 ( struct V_11 * V_12 )
{
struct V_100 * V_101 = & V_12 -> V_102 ;
struct V_99 * V_103 ;
F_68 () ;
F_69 (found, head, list) {
if ( V_103 -> V_6 & V_305 )
V_103 -> V_295 = V_336 ;
}
F_70 () ;
}
static inline T_2 F_269 ( struct V_230 * V_340 )
{
return ( V_340 -> V_56 << 1 ) ;
}
static int F_270 ( struct V_33 * V_34 ,
struct V_99 * V_341 , int V_342 )
{
struct V_230 * V_231 = & V_34 -> V_36 -> V_233 ;
T_2 V_35 = V_341 -> V_279 - V_341 -> V_293 ;
T_2 V_343 = V_341 -> V_280 + V_341 -> V_292 ;
T_2 V_344 ;
if ( V_342 == V_336 )
return 1 ;
if ( V_341 -> V_6 & V_305 )
V_343 += F_269 ( V_231 ) ;
if ( V_342 == V_345 ) {
V_344 = F_271 ( V_34 -> V_36 -> V_346 ) ;
V_344 = F_34 ( T_2 , 64 * 1024 * 1024 ,
F_272 ( V_344 , 1 ) ) ;
if ( V_35 - V_343 < V_344 )
return 1 ;
}
if ( V_343 + 2 * 1024 * 1024 < F_273 ( V_35 , 8 ) )
return 0 ;
return 1 ;
}
static T_2 F_274 ( struct V_33 * V_34 , T_2 type )
{
T_2 V_347 ;
if ( type & ( V_284 |
V_323 |
V_324 |
V_325 ) )
V_347 = V_34 -> V_36 -> V_318 -> V_319 ;
else if ( type & V_283 )
V_347 = 2 ;
else
V_347 = 1 ;
return F_188 ( V_34 , V_347 + 1 ) ;
}
static void F_275 ( struct V_106 * V_107 ,
struct V_33 * V_34 , T_2 type )
{
struct V_99 * V_12 ;
T_2 V_348 ;
T_2 V_344 ;
V_12 = F_67 ( V_34 -> V_36 , V_307 ) ;
F_11 ( & V_12 -> V_51 ) ;
V_348 = V_12 -> V_279 - V_12 -> V_280 - V_12 -> V_291 -
V_12 -> V_292 - V_12 -> V_293 ;
F_13 ( & V_12 -> V_51 ) ;
V_344 = F_274 ( V_34 , type ) ;
if ( V_348 < V_344 && F_237 ( V_34 , V_349 ) ) {
F_276 ( V_34 -> V_36 , L_7 ,
V_348 , V_344 , type ) ;
F_277 ( V_12 , 0 , 0 ) ;
}
if ( V_348 < V_344 ) {
T_2 V_6 ;
V_6 = F_260 ( V_34 -> V_36 -> V_326 , 0 ) ;
F_278 ( V_107 , V_34 , V_6 ) ;
}
}
static int F_263 ( struct V_106 * V_107 ,
struct V_33 * V_62 , T_2 V_6 , int V_342 )
{
struct V_99 * V_102 ;
struct V_11 * V_36 = V_62 -> V_36 ;
int V_350 = 0 ;
int V_28 = 0 ;
if ( V_107 -> V_351 )
return - V_337 ;
V_102 = F_67 ( V_62 -> V_36 , V_6 ) ;
if ( ! V_102 ) {
V_28 = F_245 ( V_62 -> V_36 , V_6 ,
0 , 0 , & V_102 ) ;
F_30 ( V_28 ) ;
}
F_30 ( ! V_102 ) ;
V_76:
F_11 ( & V_102 -> V_51 ) ;
if ( V_342 < V_102 -> V_295 )
V_342 = V_102 -> V_295 ;
if ( V_102 -> V_105 ) {
F_13 ( & V_102 -> V_51 ) ;
return 0 ;
}
if ( ! F_270 ( V_62 , V_102 , V_342 ) ) {
F_13 ( & V_102 -> V_51 ) ;
return 0 ;
} else if ( V_102 -> V_297 ) {
V_350 = 1 ;
} else {
V_102 -> V_297 = 1 ;
}
F_13 ( & V_102 -> V_51 ) ;
F_35 ( & V_36 -> V_352 ) ;
if ( V_350 ) {
F_45 ( & V_36 -> V_352 ) ;
V_350 = 0 ;
goto V_76;
}
V_107 -> V_351 = true ;
if ( F_279 ( V_102 ) )
V_6 |= ( V_299 | V_305 ) ;
if ( V_6 & V_299 && V_36 -> V_353 ) {
V_36 -> V_354 ++ ;
if ( ! ( V_36 -> V_354 %
V_36 -> V_353 ) )
F_268 ( V_36 ) ;
}
F_275 ( V_107 , V_62 , V_6 ) ;
V_28 = F_278 ( V_107 , V_62 , V_6 ) ;
V_107 -> V_351 = false ;
F_11 ( & V_102 -> V_51 ) ;
if ( V_28 < 0 && V_28 != - V_337 )
goto V_71;
if ( V_28 )
V_102 -> V_105 = 1 ;
else
V_28 = 1 ;
V_102 -> V_295 = V_296 ;
V_71:
V_102 -> V_297 = 0 ;
F_13 ( & V_102 -> V_51 ) ;
F_45 ( & V_36 -> V_352 ) ;
return V_28 ;
}
static int F_280 ( struct V_33 * V_34 ,
struct V_99 * V_102 , T_2 V_327 ,
enum V_355 V_298 )
{
struct V_230 * V_231 = & V_34 -> V_36 -> V_233 ;
T_2 V_356 = F_260 ( V_34 , 0 ) ;
T_2 V_357 ;
T_2 V_358 ;
T_2 V_328 ;
T_2 V_359 ;
V_328 = V_102 -> V_280 + V_102 -> V_292 +
V_102 -> V_291 + V_102 -> V_293 ;
F_11 ( & V_231 -> V_51 ) ;
V_357 = F_269 ( V_231 ) ;
F_13 ( & V_231 -> V_51 ) ;
if ( V_328 + V_357 >= V_102 -> V_279 )
return 0 ;
V_328 += V_102 -> V_294 ;
F_11 ( & V_34 -> V_36 -> V_360 ) ;
V_358 = V_34 -> V_36 -> V_361 ;
F_13 ( & V_34 -> V_36 -> V_360 ) ;
if ( V_356 & ( V_282 |
V_283 |
V_284 ) )
V_358 >>= 1 ;
V_359 = V_102 -> V_279 ;
if ( V_298 == V_362 )
V_359 >>= 3 ;
else
V_359 >>= 1 ;
V_359 = F_281 ( V_358 , V_359 ) ;
if ( V_328 + V_327 < V_102 -> V_279 + V_359 )
return 1 ;
return 0 ;
}
static void F_282 ( struct V_33 * V_34 ,
unsigned long V_363 )
{
struct V_364 * V_365 = V_34 -> V_36 -> V_365 ;
if ( F_283 ( & V_365 -> V_366 ) ) {
F_284 ( V_365 , V_363 , V_367 ) ;
F_44 ( & V_365 -> V_366 ) ;
} else {
F_285 ( V_34 -> V_36 , 0 ) ;
if ( ! V_368 -> V_369 )
F_286 ( V_34 -> V_36 , 0 ) ;
}
}
static void F_287 ( struct V_33 * V_34 , T_2 V_370 , T_2 V_371 ,
bool V_372 )
{
struct V_230 * V_373 ;
struct V_99 * V_102 ;
struct V_106 * V_107 ;
T_2 V_374 ;
T_2 V_375 ;
long V_376 ;
unsigned long V_363 = ( 2 * 1024 * 1024 ) >> V_377 ;
int V_237 = 0 ;
enum V_355 V_298 ;
V_107 = (struct V_106 * ) V_368 -> V_369 ;
V_373 = & V_34 -> V_36 -> V_378 ;
V_102 = V_373 -> V_102 ;
F_2 () ;
V_374 = F_288 (
& V_34 -> V_36 -> V_374 ) ;
if ( V_374 == 0 ) {
if ( V_107 )
return;
F_286 ( V_34 -> V_36 , 0 ) ;
return;
}
while ( V_374 && V_237 < 3 ) {
V_375 = F_281 ( V_374 , V_370 ) ;
V_363 = V_375 >> V_377 ;
F_282 ( V_34 , V_363 ) ;
F_289 ( V_34 -> V_36 -> V_379 ,
! F_183 ( & V_34 -> V_36 -> V_380 ) ) ;
if ( ! V_107 )
V_298 = V_362 ;
else
V_298 = V_381 ;
F_11 ( & V_102 -> V_51 ) ;
if ( F_280 ( V_34 , V_102 , V_371 , V_298 ) ) {
F_13 ( & V_102 -> V_51 ) ;
break;
}
F_13 ( & V_102 -> V_51 ) ;
V_237 ++ ;
if ( V_372 && ! V_107 ) {
F_286 ( V_34 -> V_36 , 0 ) ;
} else {
V_376 = F_290 ( 1 ) ;
if ( V_376 )
break;
}
F_2 () ;
V_374 = F_288 (
& V_34 -> V_36 -> V_374 ) ;
}
}
static int F_291 ( struct V_33 * V_34 ,
struct V_99 * V_102 ,
T_2 V_327 , int V_342 )
{
struct V_230 * V_382 = & V_34 -> V_36 -> V_383 ;
struct V_106 * V_107 ;
V_107 = (struct V_106 * ) V_368 -> V_369 ;
if ( V_107 )
return - V_173 ;
if ( V_342 )
goto V_384;
F_11 ( & V_102 -> V_51 ) ;
if ( F_265 ( & V_102 -> V_287 ,
V_327 ) >= 0 ) {
F_13 ( & V_102 -> V_51 ) ;
goto V_384;
}
F_13 ( & V_102 -> V_51 ) ;
if ( V_102 != V_382 -> V_102 )
return - V_337 ;
F_11 ( & V_102 -> V_51 ) ;
F_11 ( & V_382 -> V_51 ) ;
if ( F_265 ( & V_102 -> V_287 ,
V_327 - V_382 -> V_56 ) >= 0 ) {
F_13 ( & V_382 -> V_51 ) ;
F_13 ( & V_102 -> V_51 ) ;
return - V_337 ;
}
F_13 ( & V_382 -> V_51 ) ;
F_13 ( & V_102 -> V_51 ) ;
V_384:
V_107 = F_262 ( V_34 ) ;
if ( F_229 ( V_107 ) )
return - V_337 ;
return F_266 ( V_107 , V_34 ) ;
}
static int F_292 ( struct V_33 * V_34 ,
struct V_99 * V_102 , T_2 V_35 ,
T_2 V_385 , int V_386 )
{
struct V_106 * V_107 ;
int V_43 ;
int V_28 = 0 ;
switch ( V_386 ) {
case V_387 :
case V_388 :
if ( V_386 == V_387 ) {
T_2 V_327 = F_188 ( V_34 , 1 ) ;
V_43 = ( int ) F_185 ( V_35 , V_327 ) ;
if ( ! V_43 )
V_43 = 1 ;
V_43 *= 2 ;
} else {
V_43 = - 1 ;
}
V_107 = F_262 ( V_34 ) ;
if ( F_229 ( V_107 ) ) {
V_28 = F_230 ( V_107 ) ;
break;
}
V_28 = F_293 ( V_107 , V_34 , V_43 ) ;
F_264 ( V_107 , V_34 ) ;
break;
case V_389 :
case V_390 :
F_287 ( V_34 , V_35 , V_385 ,
V_386 == V_390 ) ;
break;
case V_391 :
V_107 = F_262 ( V_34 ) ;
if ( F_229 ( V_107 ) ) {
V_28 = F_230 ( V_107 ) ;
break;
}
V_28 = F_263 ( V_107 , V_34 -> V_36 -> V_62 ,
F_260 ( V_34 , 0 ) ,
V_296 ) ;
F_264 ( V_107 , V_34 ) ;
if ( V_28 == - V_337 )
V_28 = 0 ;
break;
case V_392 :
V_28 = F_291 ( V_34 , V_102 , V_385 , 0 ) ;
break;
default:
V_28 = - V_337 ;
break;
}
return V_28 ;
}
static int F_294 ( struct V_33 * V_34 ,
struct V_230 * V_373 ,
T_2 V_385 ,
enum V_355 V_298 )
{
struct V_99 * V_102 = V_373 -> V_102 ;
T_2 V_328 ;
T_2 V_35 = V_385 ;
int V_393 = V_387 ;
int V_28 = 0 ;
bool V_241 = false ;
V_76:
V_28 = 0 ;
F_11 ( & V_102 -> V_51 ) ;
while ( V_298 == V_362 && ! V_241 &&
V_102 -> V_298 ) {
F_13 ( & V_102 -> V_51 ) ;
if ( V_368 -> V_369 )
return - V_173 ;
V_28 = F_295 ( V_102 -> V_86 , ! V_102 -> V_298 ) ;
if ( V_28 )
return - V_394 ;
F_11 ( & V_102 -> V_51 ) ;
}
V_28 = - V_337 ;
V_328 = V_102 -> V_280 + V_102 -> V_292 +
V_102 -> V_291 + V_102 -> V_293 +
V_102 -> V_294 ;
if ( V_328 <= V_102 -> V_279 ) {
if ( V_328 + V_385 <= V_102 -> V_279 ) {
V_102 -> V_294 += V_385 ;
F_267 ( V_34 -> V_36 ,
L_6 , V_102 -> V_6 , V_385 , 1 ) ;
V_28 = 0 ;
} else {
V_35 = V_385 ;
}
} else {
V_35 = V_328 - V_102 -> V_279 +
( V_385 * 2 ) ;
}
if ( V_28 && F_280 ( V_34 , V_102 , V_385 , V_298 ) ) {
V_102 -> V_294 += V_385 ;
F_267 ( V_34 -> V_36 , L_6 ,
V_102 -> V_6 , V_385 ,
1 ) ;
V_28 = 0 ;
}
if ( V_28 && V_298 != V_381 ) {
V_241 = true ;
V_102 -> V_298 = 1 ;
}
F_13 ( & V_102 -> V_51 ) ;
if ( ! V_28 || V_298 == V_381 )
goto V_71;
V_28 = F_292 ( V_34 , V_102 , V_35 , V_385 ,
V_393 ) ;
V_393 ++ ;
if ( V_298 == V_395 &&
( V_393 == V_389 ||
V_393 == V_390 ) )
V_393 = V_391 ;
if ( ! V_28 )
goto V_76;
else if ( V_298 == V_395 &&
V_393 < V_392 )
goto V_76;
else if ( V_298 == V_362 &&
V_393 <= V_392 )
goto V_76;
V_71:
if ( V_28 == - V_337 &&
F_296 ( V_34 -> V_396 == V_397 ) ) {
struct V_230 * V_231 =
& V_34 -> V_36 -> V_233 ;
if ( V_373 != V_231 &&
! F_297 ( V_231 , V_385 ) )
V_28 = 0 ;
}
if ( V_241 ) {
F_11 ( & V_102 -> V_51 ) ;
V_102 -> V_298 = 0 ;
F_298 ( & V_102 -> V_86 ) ;
F_13 ( & V_102 -> V_51 ) ;
}
return V_28 ;
}
static struct V_230 * F_299 (
const struct V_106 * V_107 ,
const struct V_33 * V_34 )
{
struct V_230 * V_373 = NULL ;
if ( V_34 -> V_255 )
V_373 = V_107 -> V_373 ;
if ( V_34 == V_34 -> V_36 -> V_398 && V_107 -> V_399 )
V_373 = V_107 -> V_373 ;
if ( ! V_373 )
V_373 = V_34 -> V_373 ;
if ( ! V_373 )
V_373 = & V_34 -> V_36 -> V_400 ;
return V_373 ;
}
static int F_297 ( struct V_230 * V_373 ,
T_2 V_35 )
{
int V_28 = - V_337 ;
F_11 ( & V_373 -> V_51 ) ;
if ( V_373 -> V_9 >= V_35 ) {
V_373 -> V_9 -= V_35 ;
if ( V_373 -> V_9 < V_373 -> V_56 )
V_373 -> V_105 = 0 ;
V_28 = 0 ;
}
F_13 ( & V_373 -> V_51 ) ;
return V_28 ;
}
static void F_300 ( struct V_230 * V_373 ,
T_2 V_35 , int V_401 )
{
F_11 ( & V_373 -> V_51 ) ;
V_373 -> V_9 += V_35 ;
if ( V_401 )
V_373 -> V_56 += V_35 ;
else if ( V_373 -> V_9 >= V_373 -> V_56 )
V_373 -> V_105 = 1 ;
F_13 ( & V_373 -> V_51 ) ;
}
int F_301 ( struct V_11 * V_36 ,
struct V_230 * V_402 , T_2 V_35 ,
int V_403 )
{
struct V_230 * V_231 = & V_36 -> V_233 ;
T_2 V_404 ;
if ( V_231 -> V_102 != V_402 -> V_102 )
return - V_337 ;
F_11 ( & V_231 -> V_51 ) ;
V_404 = F_273 ( V_231 -> V_56 , V_403 ) ;
if ( V_231 -> V_9 < V_404 + V_35 ) {
F_13 ( & V_231 -> V_51 ) ;
return - V_337 ;
}
V_231 -> V_9 -= V_35 ;
if ( V_231 -> V_9 < V_231 -> V_56 )
V_231 -> V_105 = 0 ;
F_13 ( & V_231 -> V_51 ) ;
F_300 ( V_402 , V_35 , 1 ) ;
return 0 ;
}
static void F_302 ( struct V_11 * V_36 ,
struct V_230 * V_373 ,
struct V_230 * V_402 , T_2 V_35 )
{
struct V_99 * V_102 = V_373 -> V_102 ;
F_11 ( & V_373 -> V_51 ) ;
if ( V_35 == ( T_2 ) - 1 )
V_35 = V_373 -> V_56 ;
V_373 -> V_56 -= V_35 ;
if ( V_373 -> V_9 >= V_373 -> V_56 ) {
V_35 = V_373 -> V_9 - V_373 -> V_56 ;
V_373 -> V_9 = V_373 -> V_56 ;
V_373 -> V_105 = 1 ;
} else {
V_35 = 0 ;
}
F_13 ( & V_373 -> V_51 ) ;
if ( V_35 > 0 ) {
if ( V_402 ) {
F_11 ( & V_402 -> V_51 ) ;
if ( ! V_402 -> V_105 ) {
T_2 V_405 ;
V_405 = V_402 -> V_56 - V_402 -> V_9 ;
V_405 = F_281 ( V_35 , V_405 ) ;
V_402 -> V_9 += V_405 ;
if ( V_402 -> V_9 >= V_402 -> V_56 )
V_402 -> V_105 = 1 ;
V_35 -= V_405 ;
}
F_13 ( & V_402 -> V_51 ) ;
}
if ( V_35 ) {
F_11 ( & V_102 -> V_51 ) ;
V_102 -> V_294 -= V_35 ;
F_267 ( V_36 , L_6 ,
V_102 -> V_6 , V_35 , 0 ) ;
V_102 -> V_406 ++ ;
F_13 ( & V_102 -> V_51 ) ;
}
}
}
static int F_303 ( struct V_230 * V_407 ,
struct V_230 * V_408 , T_2 V_35 )
{
int V_28 ;
V_28 = F_297 ( V_407 , V_35 ) ;
if ( V_28 )
return V_28 ;
F_300 ( V_408 , V_35 , 1 ) ;
return 0 ;
}
void F_304 ( struct V_230 * V_409 , unsigned short type )
{
memset ( V_409 , 0 , sizeof( * V_409 ) ) ;
F_248 ( & V_409 -> V_51 ) ;
V_409 -> type = type ;
}
struct V_230 * F_305 ( struct V_33 * V_34 ,
unsigned short type )
{
struct V_230 * V_373 ;
struct V_11 * V_36 = V_34 -> V_36 ;
V_373 = F_306 ( sizeof( * V_373 ) , V_39 ) ;
if ( ! V_373 )
return NULL ;
F_304 ( V_373 , type ) ;
V_373 -> V_102 = F_67 ( V_36 ,
V_305 ) ;
return V_373 ;
}
void F_307 ( struct V_33 * V_34 ,
struct V_230 * V_409 )
{
if ( ! V_409 )
return;
F_308 ( V_34 , V_409 , ( T_2 ) - 1 ) ;
F_9 ( V_409 ) ;
}
int F_309 ( struct V_33 * V_34 ,
struct V_230 * V_373 , T_2 V_35 ,
enum V_355 V_298 )
{
int V_28 ;
if ( V_35 == 0 )
return 0 ;
V_28 = F_294 ( V_34 , V_373 , V_35 , V_298 ) ;
if ( ! V_28 ) {
F_300 ( V_373 , V_35 , 1 ) ;
return 0 ;
}
return V_28 ;
}
int F_310 ( struct V_33 * V_34 ,
struct V_230 * V_373 , int V_403 )
{
T_2 V_35 = 0 ;
int V_28 = - V_337 ;
if ( ! V_373 )
return 0 ;
F_11 ( & V_373 -> V_51 ) ;
V_35 = F_273 ( V_373 -> V_56 , V_403 ) ;
if ( V_373 -> V_9 >= V_35 )
V_28 = 0 ;
F_13 ( & V_373 -> V_51 ) ;
return V_28 ;
}
int F_311 ( struct V_33 * V_34 ,
struct V_230 * V_373 , T_2 V_410 ,
enum V_355 V_298 )
{
T_2 V_35 = 0 ;
int V_28 = - V_337 ;
if ( ! V_373 )
return 0 ;
F_11 ( & V_373 -> V_51 ) ;
V_35 = V_410 ;
if ( V_373 -> V_9 >= V_35 )
V_28 = 0 ;
else
V_35 -= V_373 -> V_9 ;
F_13 ( & V_373 -> V_51 ) ;
if ( ! V_28 )
return 0 ;
V_28 = F_294 ( V_34 , V_373 , V_35 , V_298 ) ;
if ( ! V_28 ) {
F_300 ( V_373 , V_35 , 0 ) ;
return 0 ;
}
return V_28 ;
}
int F_312 ( struct V_230 * V_411 ,
struct V_230 * V_412 ,
T_2 V_35 )
{
return F_303 ( V_411 , V_412 , V_35 ) ;
}
void F_308 ( struct V_33 * V_34 ,
struct V_230 * V_373 ,
T_2 V_35 )
{
struct V_230 * V_231 = & V_34 -> V_36 -> V_233 ;
if ( V_231 -> V_105 || V_231 == V_373 ||
V_373 -> V_102 != V_231 -> V_102 )
V_231 = NULL ;
F_302 ( V_34 -> V_36 , V_373 , V_231 ,
V_35 ) ;
}
static T_2 F_313 ( struct V_11 * V_36 )
{
struct V_99 * V_341 ;
T_2 V_35 ;
T_2 V_413 ;
T_2 V_414 ;
int V_415 = F_314 ( V_36 -> V_346 ) ;
V_341 = F_67 ( V_36 , V_299 ) ;
F_11 ( & V_341 -> V_51 ) ;
V_414 = V_341 -> V_280 ;
F_13 ( & V_341 -> V_51 ) ;
V_341 = F_67 ( V_36 , V_305 ) ;
F_11 ( & V_341 -> V_51 ) ;
if ( V_341 -> V_6 & V_299 )
V_414 = 0 ;
V_413 = V_341 -> V_280 ;
F_13 ( & V_341 -> V_51 ) ;
V_35 = ( V_414 >> V_36 -> V_365 -> V_416 ) *
V_415 * 2 ;
V_35 += F_185 ( V_414 + V_413 , 50 ) ;
if ( V_35 * 3 > V_413 )
V_35 = F_185 ( V_413 , 3 ) ;
return F_261 ( V_35 , V_36 -> V_62 -> V_85 << 10 ) ;
}
static void F_315 ( struct V_11 * V_36 )
{
struct V_230 * V_373 = & V_36 -> V_233 ;
struct V_99 * V_341 = V_373 -> V_102 ;
T_2 V_35 ;
V_35 = F_313 ( V_36 ) ;
F_11 ( & V_341 -> V_51 ) ;
F_11 ( & V_373 -> V_51 ) ;
V_373 -> V_56 = F_24 ( T_2 , V_35 , 512 * 1024 * 1024 ) ;
V_35 = V_341 -> V_280 + V_341 -> V_291 +
V_341 -> V_292 + V_341 -> V_293 +
V_341 -> V_294 ;
if ( V_341 -> V_279 > V_35 ) {
V_35 = V_341 -> V_279 - V_35 ;
V_373 -> V_9 += V_35 ;
V_341 -> V_294 += V_35 ;
F_267 ( V_36 , L_6 ,
V_341 -> V_6 , V_35 , 1 ) ;
}
if ( V_373 -> V_9 >= V_373 -> V_56 ) {
V_35 = V_373 -> V_9 - V_373 -> V_56 ;
V_341 -> V_294 -= V_35 ;
F_267 ( V_36 , L_6 ,
V_341 -> V_6 , V_35 , 0 ) ;
V_341 -> V_406 ++ ;
V_373 -> V_9 = V_373 -> V_56 ;
V_373 -> V_105 = 1 ;
}
F_13 ( & V_373 -> V_51 ) ;
F_13 ( & V_341 -> V_51 ) ;
}
static void F_316 ( struct V_11 * V_36 )
{
struct V_99 * V_102 ;
V_102 = F_67 ( V_36 , V_307 ) ;
V_36 -> V_417 . V_102 = V_102 ;
V_102 = F_67 ( V_36 , V_305 ) ;
V_36 -> V_233 . V_102 = V_102 ;
V_36 -> V_378 . V_102 = V_102 ;
V_36 -> V_418 . V_102 = V_102 ;
V_36 -> V_400 . V_102 = V_102 ;
V_36 -> V_383 . V_102 = V_102 ;
V_36 -> V_62 -> V_373 = & V_36 -> V_233 ;
V_36 -> V_398 -> V_373 = & V_36 -> V_233 ;
V_36 -> V_419 -> V_373 = & V_36 -> V_233 ;
V_36 -> V_84 -> V_373 = & V_36 -> V_233 ;
if ( V_36 -> V_420 )
V_36 -> V_420 -> V_373 = & V_36 -> V_233 ;
V_36 -> V_326 -> V_373 = & V_36 -> V_417 ;
F_315 ( V_36 ) ;
}
static void F_317 ( struct V_11 * V_36 )
{
F_302 ( V_36 , & V_36 -> V_233 , NULL ,
( T_2 ) - 1 ) ;
F_8 ( V_36 -> V_378 . V_56 > 0 ) ;
F_8 ( V_36 -> V_378 . V_9 > 0 ) ;
F_8 ( V_36 -> V_418 . V_56 > 0 ) ;
F_8 ( V_36 -> V_418 . V_9 > 0 ) ;
F_8 ( V_36 -> V_417 . V_56 > 0 ) ;
F_8 ( V_36 -> V_417 . V_9 > 0 ) ;
F_8 ( V_36 -> V_383 . V_56 > 0 ) ;
F_8 ( V_36 -> V_383 . V_9 > 0 ) ;
}
void F_318 ( struct V_106 * V_107 ,
struct V_33 * V_34 )
{
if ( ! V_107 -> V_373 )
return;
if ( ! V_107 -> V_292 )
return;
F_267 ( V_34 -> V_36 , L_8 ,
V_107 -> V_269 , V_107 -> V_292 , 0 ) ;
F_308 ( V_34 , V_107 -> V_373 , V_107 -> V_292 ) ;
V_107 -> V_292 = 0 ;
}
int F_319 ( struct V_106 * V_107 ,
struct V_259 * V_259 )
{
struct V_33 * V_34 = F_233 ( V_259 ) -> V_34 ;
struct V_230 * V_411 = F_299 ( V_107 , V_34 ) ;
struct V_230 * V_412 = V_34 -> V_421 ;
T_2 V_35 = F_188 ( V_34 , 1 ) ;
F_267 ( V_34 -> V_36 , L_9 ,
F_320 ( V_259 ) , V_35 , 1 ) ;
return F_303 ( V_411 , V_412 , V_35 ) ;
}
void F_321 ( struct V_259 * V_259 )
{
struct V_33 * V_34 = F_233 ( V_259 ) -> V_34 ;
T_2 V_35 = F_188 ( V_34 , 1 ) ;
F_267 ( V_34 -> V_36 , L_9 ,
F_320 ( V_259 ) , V_35 , 0 ) ;
F_308 ( V_34 , V_34 -> V_421 , V_35 ) ;
}
int F_322 ( struct V_33 * V_34 ,
struct V_230 * V_409 ,
int V_422 ,
T_2 * V_423 )
{
T_2 V_35 ;
int V_28 ;
if ( V_34 -> V_36 -> V_424 ) {
V_35 = 3 * V_34 -> V_85 ;
V_28 = F_323 ( V_34 , V_35 ) ;
if ( V_28 )
return V_28 ;
} else {
V_35 = 0 ;
}
* V_423 = V_35 ;
V_35 = F_188 ( V_34 , V_422 ) ;
V_409 -> V_102 = F_67 ( V_34 -> V_36 ,
V_305 ) ;
V_28 = F_309 ( V_34 , V_409 , V_35 ,
V_362 ) ;
if ( V_28 ) {
if ( * V_423 )
F_324 ( V_34 , * V_423 ) ;
}
return V_28 ;
}
void F_325 ( struct V_33 * V_34 ,
struct V_230 * V_409 ,
T_2 V_423 )
{
F_308 ( V_34 , V_409 , ( T_2 ) - 1 ) ;
if ( V_423 )
F_324 ( V_34 , V_423 ) ;
}
static unsigned F_326 ( struct V_259 * V_259 )
{
unsigned V_425 = 0 ;
unsigned V_426 = 0 ;
F_30 ( ! F_233 ( V_259 ) -> V_427 ) ;
F_233 ( V_259 ) -> V_427 -- ;
if ( F_233 ( V_259 ) -> V_427 == 0 &&
F_327 ( V_428 ,
& F_233 ( V_259 ) -> V_429 ) )
V_425 = 1 ;
if ( F_233 ( V_259 ) -> V_427 >=
F_233 ( V_259 ) -> V_430 )
return V_425 ;
V_426 = F_233 ( V_259 ) -> V_430 -
F_233 ( V_259 ) -> V_427 ;
F_233 ( V_259 ) -> V_430 -= V_426 ;
return V_426 + V_425 ;
}
static T_2 F_328 ( struct V_259 * V_259 , T_2 V_35 ,
int V_431 )
{
struct V_33 * V_34 = F_233 ( V_259 ) -> V_34 ;
T_2 V_415 ;
int V_432 ;
int V_433 ;
int V_434 ;
if ( F_233 ( V_259 ) -> V_6 & V_435 &&
F_233 ( V_259 ) -> V_436 == 0 )
return 0 ;
V_434 = ( int ) F_185 ( F_233 ( V_259 ) -> V_436 , V_34 -> V_331 ) ;
if ( V_431 )
F_233 ( V_259 ) -> V_436 += V_35 ;
else
F_233 ( V_259 ) -> V_436 -= V_35 ;
V_415 = F_186 ( V_34 ) - sizeof( struct V_437 ) ;
V_432 = ( int ) F_185 ( V_415 ,
sizeof( struct V_438 ) +
sizeof( struct V_439 ) ) ;
V_433 = ( int ) F_185 ( F_233 ( V_259 ) -> V_436 , V_34 -> V_331 ) ;
V_433 = V_433 + V_432 - 1 ;
V_433 = V_433 / V_432 ;
V_434 = V_434 + V_432 - 1 ;
V_434 = V_434 / V_432 ;
if ( V_434 == V_433 )
return 0 ;
if ( V_431 )
return F_188 ( V_34 ,
V_433 - V_434 ) ;
return F_188 ( V_34 , V_434 - V_433 ) ;
}
int F_329 ( struct V_259 * V_259 , T_2 V_35 )
{
struct V_33 * V_34 = F_233 ( V_259 ) -> V_34 ;
struct V_230 * V_373 = & V_34 -> V_36 -> V_378 ;
T_2 V_440 = 0 ;
T_2 V_436 ;
unsigned V_441 = 0 ;
int V_442 = 0 ;
enum V_355 V_298 = V_362 ;
int V_28 = 0 ;
bool V_443 = true ;
T_2 V_444 = 0 ;
unsigned V_445 ;
if ( F_330 ( V_259 ) ) {
V_298 = V_381 ;
V_443 = false ;
}
if ( V_298 != V_381 &&
F_331 ( V_34 -> V_36 ) )
F_198 ( 1 ) ;
if ( V_443 )
F_35 ( & F_233 ( V_259 ) -> V_446 ) ;
V_35 = F_261 ( V_35 , V_34 -> V_331 ) ;
F_11 ( & F_233 ( V_259 ) -> V_51 ) ;
F_233 ( V_259 ) -> V_427 ++ ;
if ( F_233 ( V_259 ) -> V_427 >
F_233 ( V_259 ) -> V_430 )
V_441 = F_233 ( V_259 ) -> V_427 -
F_233 ( V_259 ) -> V_430 ;
if ( ! F_332 ( V_428 ,
& F_233 ( V_259 ) -> V_429 ) ) {
V_441 ++ ;
V_442 = 1 ;
}
V_440 = F_188 ( V_34 , V_441 ) ;
V_440 += F_328 ( V_259 , V_35 , 1 ) ;
V_436 = F_233 ( V_259 ) -> V_436 ;
F_13 ( & F_233 ( V_259 ) -> V_51 ) ;
if ( V_34 -> V_36 -> V_424 ) {
V_28 = F_323 ( V_34 , V_35 +
V_441 * V_34 -> V_85 ) ;
if ( V_28 )
goto V_447;
}
V_28 = F_294 ( V_34 , V_373 , V_440 , V_298 ) ;
if ( F_296 ( V_28 ) ) {
if ( V_34 -> V_36 -> V_424 )
F_324 ( V_34 , V_35 +
V_441 * V_34 -> V_85 ) ;
goto V_447;
}
F_11 ( & F_233 ( V_259 ) -> V_51 ) ;
if ( V_442 ) {
F_333 ( V_428 ,
& F_233 ( V_259 ) -> V_429 ) ;
V_441 -- ;
}
F_233 ( V_259 ) -> V_430 += V_441 ;
F_13 ( & F_233 ( V_259 ) -> V_51 ) ;
if ( V_443 )
F_45 ( & F_233 ( V_259 ) -> V_446 ) ;
if ( V_440 )
F_267 ( V_34 -> V_36 , L_10 ,
F_320 ( V_259 ) , V_440 , 1 ) ;
F_300 ( V_373 , V_440 , 1 ) ;
return 0 ;
V_447:
F_11 ( & F_233 ( V_259 ) -> V_51 ) ;
V_445 = F_326 ( V_259 ) ;
if ( F_233 ( V_259 ) -> V_436 == V_436 ) {
F_328 ( V_259 , V_35 , 0 ) ;
} else {
T_2 V_448 = F_233 ( V_259 ) -> V_436 ;
T_2 V_327 ;
V_327 = V_436 - F_233 ( V_259 ) -> V_436 ;
F_233 ( V_259 ) -> V_436 = V_436 ;
V_444 = F_328 ( V_259 , V_327 , 0 ) ;
F_233 ( V_259 ) -> V_436 = V_436 - V_35 ;
V_327 = V_436 - V_448 ;
V_327 = F_328 ( V_259 , V_327 , 0 ) ;
F_233 ( V_259 ) -> V_436 = V_448 - V_35 ;
if ( V_327 > V_444 )
V_444 = V_327 - V_444 ;
else
V_444 = 0 ;
}
F_13 ( & F_233 ( V_259 ) -> V_51 ) ;
if ( V_445 )
V_444 += F_188 ( V_34 , V_445 ) ;
if ( V_444 ) {
F_308 ( V_34 , V_373 , V_444 ) ;
F_267 ( V_34 -> V_36 , L_10 ,
F_320 ( V_259 ) , V_444 , 0 ) ;
}
if ( V_443 )
F_45 ( & F_233 ( V_259 ) -> V_446 ) ;
return V_28 ;
}
void F_334 ( struct V_259 * V_259 , T_2 V_35 )
{
struct V_33 * V_34 = F_233 ( V_259 ) -> V_34 ;
T_2 V_444 = 0 ;
unsigned V_445 ;
V_35 = F_261 ( V_35 , V_34 -> V_331 ) ;
F_11 ( & F_233 ( V_259 ) -> V_51 ) ;
V_445 = F_326 ( V_259 ) ;
if ( V_35 )
V_444 = F_328 ( V_259 , V_35 , 0 ) ;
F_13 ( & F_233 ( V_259 ) -> V_51 ) ;
if ( V_445 > 0 )
V_444 += F_188 ( V_34 , V_445 ) ;
F_267 ( V_34 -> V_36 , L_10 ,
F_320 ( V_259 ) , V_444 , 0 ) ;
if ( V_34 -> V_36 -> V_424 ) {
F_324 ( V_34 , V_35 +
V_445 * V_34 -> V_85 ) ;
}
F_308 ( V_34 , & V_34 -> V_36 -> V_378 ,
V_444 ) ;
}
int F_335 ( struct V_259 * V_259 , T_2 V_35 )
{
int V_28 ;
V_28 = F_238 ( V_259 , V_35 ) ;
if ( V_28 )
return V_28 ;
V_28 = F_329 ( V_259 , V_35 ) ;
if ( V_28 ) {
F_240 ( V_259 , V_35 ) ;
return V_28 ;
}
return 0 ;
}
void F_336 ( struct V_259 * V_259 , T_2 V_35 )
{
F_334 ( V_259 , V_35 ) ;
F_240 ( V_259 , V_35 ) ;
}
static int F_337 ( struct V_33 * V_34 ,
T_2 V_26 , T_2 V_35 , int V_334 )
{
struct V_1 * V_2 = NULL ;
struct V_11 * V_12 = V_34 -> V_36 ;
T_2 V_449 = V_35 ;
T_2 V_450 ;
T_2 V_451 ;
int V_281 ;
F_11 ( & V_12 -> V_452 ) ;
V_450 = F_338 ( V_12 -> V_346 ) ;
if ( V_334 )
V_450 += V_35 ;
else
V_450 -= V_35 ;
F_339 ( V_12 -> V_346 , V_450 ) ;
F_13 ( & V_12 -> V_452 ) ;
while ( V_449 ) {
V_2 = F_66 ( V_12 , V_26 ) ;
if ( ! V_2 )
return - V_149 ;
if ( V_2 -> V_6 & ( V_282 |
V_283 |
V_284 ) )
V_281 = 2 ;
else
V_281 = 1 ;
if ( ! V_334 && V_2 -> V_3 == V_93 )
F_50 ( V_2 , 1 ) ;
V_451 = V_26 - V_2 -> V_20 . V_21 ;
F_8 ( V_451 > V_2 -> V_20 . V_32 ) ;
F_11 ( & V_2 -> V_102 -> V_51 ) ;
F_11 ( & V_2 -> V_51 ) ;
if ( F_237 ( V_34 , V_273 ) &&
V_2 -> V_265 < V_275 )
V_2 -> V_265 = V_275 ;
V_2 -> V_276 = 1 ;
V_450 = F_340 ( & V_2 -> V_131 ) ;
V_35 = F_281 ( V_449 , V_2 -> V_20 . V_32 - V_451 ) ;
if ( V_334 ) {
V_450 += V_35 ;
F_341 ( & V_2 -> V_131 , V_450 ) ;
V_2 -> V_9 -= V_35 ;
V_2 -> V_102 -> V_292 -= V_35 ;
V_2 -> V_102 -> V_280 += V_35 ;
V_2 -> V_102 -> V_286 += V_35 * V_281 ;
F_13 ( & V_2 -> V_51 ) ;
F_13 ( & V_2 -> V_102 -> V_51 ) ;
} else {
V_450 -= V_35 ;
F_341 ( & V_2 -> V_131 , V_450 ) ;
V_2 -> V_8 += V_35 ;
V_2 -> V_102 -> V_291 += V_35 ;
V_2 -> V_102 -> V_280 -= V_35 ;
V_2 -> V_102 -> V_286 -= V_35 * V_281 ;
F_13 ( & V_2 -> V_51 ) ;
F_13 ( & V_2 -> V_102 -> V_51 ) ;
F_342 ( V_12 -> V_58 ,
V_26 , V_26 + V_35 - 1 ,
V_39 | V_453 ) ;
}
F_6 ( V_2 ) ;
V_449 -= V_35 ;
V_26 += V_35 ;
}
return 0 ;
}
static T_2 V_25 ( struct V_33 * V_34 , T_2 V_454 )
{
struct V_1 * V_2 ;
T_2 V_26 ;
F_11 ( & V_34 -> V_36 -> V_17 ) ;
V_26 = V_34 -> V_36 -> V_25 ;
F_13 ( & V_34 -> V_36 -> V_17 ) ;
if ( V_26 < ( T_2 ) - 1 )
return V_26 ;
V_2 = F_65 ( V_34 -> V_36 , V_454 ) ;
if ( ! V_2 )
return 0 ;
V_26 = V_2 -> V_20 . V_21 ;
F_6 ( V_2 ) ;
return V_26 ;
}
static int F_343 ( struct V_33 * V_34 ,
struct V_1 * V_2 ,
T_2 V_26 , T_2 V_35 , int V_9 )
{
F_11 ( & V_2 -> V_102 -> V_51 ) ;
F_11 ( & V_2 -> V_51 ) ;
V_2 -> V_8 += V_35 ;
V_2 -> V_102 -> V_291 += V_35 ;
if ( V_9 ) {
V_2 -> V_9 -= V_35 ;
V_2 -> V_102 -> V_292 -= V_35 ;
}
F_13 ( & V_2 -> V_51 ) ;
F_13 ( & V_2 -> V_102 -> V_51 ) ;
F_342 ( V_34 -> V_36 -> V_58 , V_26 ,
V_26 + V_35 - 1 , V_39 | V_453 ) ;
return 0 ;
}
int F_159 ( struct V_33 * V_34 ,
T_2 V_26 , T_2 V_35 , int V_9 )
{
struct V_1 * V_2 ;
V_2 = F_66 ( V_34 -> V_36 , V_26 ) ;
F_30 ( ! V_2 ) ;
F_343 ( V_34 , V_2 , V_26 , V_35 , V_9 ) ;
F_6 ( V_2 ) ;
return 0 ;
}
int F_344 ( struct V_33 * V_34 ,
T_2 V_26 , T_2 V_35 )
{
struct V_1 * V_2 ;
int V_28 ;
V_2 = F_66 ( V_34 -> V_36 , V_26 ) ;
if ( ! V_2 )
return - V_455 ;
F_50 ( V_2 , 1 ) ;
F_343 ( V_34 , V_2 , V_26 , V_35 , 0 ) ;
V_28 = F_345 ( V_2 , V_26 , V_35 ) ;
F_6 ( V_2 ) ;
return V_28 ;
}
static int F_346 ( struct V_33 * V_34 , T_2 V_31 , T_2 V_35 )
{
int V_28 ;
struct V_1 * V_13 ;
struct V_49 * V_53 ;
V_13 = F_66 ( V_34 -> V_36 , V_31 ) ;
if ( ! V_13 )
return - V_455 ;
F_50 ( V_13 , 0 ) ;
V_53 = F_25 ( V_13 ) ;
if ( ! V_53 ) {
F_30 ( ! F_1 ( V_13 ) ) ;
V_28 = F_345 ( V_13 , V_31 , V_35 ) ;
} else {
F_35 ( & V_53 -> V_77 ) ;
if ( V_31 >= V_53 -> V_82 ) {
V_28 = F_17 ( V_34 , V_31 , V_35 ) ;
} else if ( V_31 + V_35 <= V_53 -> V_82 ) {
V_28 = F_345 ( V_13 ,
V_31 , V_35 ) ;
} else {
V_35 = V_53 -> V_82 - V_31 ;
V_28 = F_345 ( V_13 ,
V_31 , V_35 ) ;
if ( V_28 )
goto V_456;
V_35 = ( V_31 + V_35 ) -
V_53 -> V_82 ;
V_31 = V_53 -> V_82 ;
V_28 = F_17 ( V_34 , V_31 , V_35 ) ;
}
V_456:
F_45 ( & V_53 -> V_77 ) ;
F_26 ( V_53 ) ;
}
F_6 ( V_13 ) ;
return V_28 ;
}
int F_347 ( struct V_33 * log ,
struct V_65 * V_457 )
{
struct V_253 * V_131 ;
struct V_67 V_20 ;
int V_458 ;
int V_42 ;
if ( ! F_74 ( log -> V_36 , V_459 ) )
return 0 ;
for ( V_42 = 0 ; V_42 < F_38 ( V_457 ) ; V_42 ++ ) {
F_40 ( V_457 , & V_20 , V_42 ) ;
if ( V_20 . type != V_257 )
continue;
V_131 = F_76 ( V_457 , V_42 , struct V_253 ) ;
V_458 = F_215 ( V_457 , V_131 ) ;
if ( V_458 == V_258 )
continue;
if ( F_216 ( V_457 , V_131 ) == 0 )
continue;
V_20 . V_21 = F_216 ( V_457 , V_131 ) ;
V_20 . V_32 = F_217 ( V_457 , V_131 ) ;
F_346 ( log , V_20 . V_21 , V_20 . V_32 ) ;
}
return 0 ;
}
static int F_348 ( struct V_1 * V_2 ,
T_2 V_35 , int V_431 )
{
struct V_99 * V_102 = V_2 -> V_102 ;
int V_28 = 0 ;
F_11 ( & V_102 -> V_51 ) ;
F_11 ( & V_2 -> V_51 ) ;
if ( V_431 != V_460 ) {
if ( V_2 -> V_267 ) {
V_28 = - V_173 ;
} else {
V_2 -> V_9 += V_35 ;
V_102 -> V_292 += V_35 ;
if ( V_431 == V_461 ) {
F_267 ( V_2 -> V_36 ,
L_6 , V_102 -> V_6 ,
V_35 , 0 ) ;
V_102 -> V_294 -= V_35 ;
}
}
} else {
if ( V_2 -> V_267 )
V_102 -> V_293 += V_35 ;
V_2 -> V_9 -= V_35 ;
V_102 -> V_292 -= V_35 ;
V_102 -> V_406 ++ ;
}
F_13 ( & V_2 -> V_51 ) ;
F_13 ( & V_102 -> V_51 ) ;
return V_28 ;
}
void F_349 ( struct V_106 * V_107 ,
struct V_33 * V_34 )
{
struct V_11 * V_36 = V_34 -> V_36 ;
struct V_49 * V_213 ;
struct V_49 * V_53 ;
struct V_1 * V_2 ;
struct V_99 * V_102 ;
F_61 ( & V_36 -> V_78 ) ;
F_350 (caching_ctl, next,
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
F_69 (space_info, &fs_info->space_info, list)
F_351 ( & V_102 -> V_287 , 0 ) ;
F_315 ( V_36 ) ;
}
static int F_352 ( struct V_33 * V_34 , T_2 V_31 , T_2 V_30 )
{
struct V_11 * V_36 = V_34 -> V_36 ;
struct V_1 * V_2 = NULL ;
struct V_99 * V_102 ;
struct V_230 * V_231 = & V_36 -> V_233 ;
T_2 V_48 ;
bool V_278 ;
while ( V_31 <= V_30 ) {
V_278 = false ;
if ( ! V_2 ||
V_31 >= V_2 -> V_20 . V_21 + V_2 -> V_20 . V_32 ) {
if ( V_2 )
F_6 ( V_2 ) ;
V_2 = F_66 ( V_36 , V_31 ) ;
F_30 ( ! V_2 ) ;
}
V_48 = V_2 -> V_20 . V_21 + V_2 -> V_20 . V_32 - V_31 ;
V_48 = F_281 ( V_48 , V_30 + 1 - V_31 ) ;
if ( V_31 < V_2 -> V_96 ) {
V_48 = F_281 ( V_48 , V_2 -> V_96 - V_31 ) ;
F_29 ( V_2 , V_31 , V_48 ) ;
}
V_31 += V_48 ;
V_102 = V_2 -> V_102 ;
F_11 ( & V_102 -> V_51 ) ;
F_11 ( & V_2 -> V_51 ) ;
V_2 -> V_8 -= V_48 ;
V_102 -> V_291 -= V_48 ;
if ( V_2 -> V_267 ) {
V_102 -> V_293 += V_48 ;
V_278 = true ;
}
F_13 ( & V_2 -> V_51 ) ;
if ( ! V_278 && V_231 -> V_102 == V_102 ) {
F_11 ( & V_231 -> V_51 ) ;
if ( ! V_231 -> V_105 ) {
V_48 = F_281 ( V_48 , V_231 -> V_56 -
V_231 -> V_9 ) ;
V_231 -> V_9 += V_48 ;
V_102 -> V_294 += V_48 ;
if ( V_231 -> V_9 >= V_231 -> V_56 )
V_231 -> V_105 = 1 ;
}
F_13 ( & V_231 -> V_51 ) ;
}
F_13 ( & V_102 -> V_51 ) ;
}
if ( V_2 )
F_6 ( V_2 ) ;
return 0 ;
}
int F_353 ( struct V_106 * V_107 ,
struct V_33 * V_34 )
{
struct V_11 * V_36 = V_34 -> V_36 ;
struct V_462 * V_463 ;
T_2 V_31 ;
T_2 V_30 ;
int V_28 ;
if ( V_107 -> V_208 )
return 0 ;
if ( V_36 -> V_58 == & V_36 -> V_37 [ 0 ] )
V_463 = & V_36 -> V_37 [ 1 ] ;
else
V_463 = & V_36 -> V_37 [ 0 ] ;
while ( 1 ) {
V_28 = F_28 ( V_463 , 0 , & V_31 , & V_30 ,
V_59 , NULL ) ;
if ( V_28 )
break;
if ( F_237 ( V_34 , V_464 ) )
V_28 = F_140 ( V_34 , V_31 ,
V_30 + 1 - V_31 , NULL ) ;
F_354 ( V_463 , V_31 , V_30 , V_39 ) ;
F_352 ( V_34 , V_31 , V_30 ) ;
F_46 () ;
}
return 0 ;
}
static void F_355 ( struct V_11 * V_36 , T_2 V_35 ,
T_2 V_129 , T_2 V_142 )
{
struct V_99 * V_102 ;
T_2 V_6 ;
if ( V_129 < V_139 ) {
if ( V_142 == V_465 )
V_6 = V_307 ;
else
V_6 = V_305 ;
} else {
V_6 = V_299 ;
}
V_102 = F_67 ( V_36 , V_6 ) ;
F_30 ( ! V_102 ) ;
F_356 ( & V_102 -> V_287 , V_35 ) ;
}
static int F_150 ( struct V_106 * V_107 ,
struct V_33 * V_34 ,
T_2 V_26 , T_2 V_35 , T_2 V_16 ,
T_2 V_142 , T_2 V_466 ,
T_2 V_467 , int V_155 ,
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
int V_468 = 0 ;
int V_469 = 0 ;
int V_470 = 1 ;
T_3 V_115 ;
T_2 V_109 ;
bool V_168 = F_74 ( V_34 -> V_36 ,
V_118 ) ;
V_64 = F_33 () ;
if ( ! V_64 )
return - V_88 ;
V_64 -> V_74 = 1 ;
V_64 -> V_199 = 1 ;
V_179 = V_466 >= V_139 ;
F_30 ( ! V_179 && V_155 != 1 ) ;
if ( V_179 )
V_168 = 0 ;
V_28 = F_132 ( V_107 , V_62 , V_64 , & V_159 ,
V_26 , V_35 , V_16 ,
V_142 , V_466 ,
V_467 ) ;
if ( V_28 == 0 ) {
V_468 = V_64 -> V_81 [ 0 ] ;
while ( V_468 >= 0 ) {
F_40 ( V_64 -> V_80 [ 0 ] , & V_20 ,
V_468 ) ;
if ( V_20 . V_21 != V_26 )
break;
if ( V_20 . type == V_75 &&
V_20 . V_32 == V_35 ) {
V_469 = 1 ;
break;
}
if ( V_20 . type == V_83 &&
V_20 . V_32 == V_466 ) {
V_469 = 1 ;
break;
}
if ( V_64 -> V_81 [ 0 ] - V_468 > 5 )
break;
V_468 -- ;
}
#ifdef F_79
V_115 = F_75 ( V_64 -> V_80 [ 0 ] , V_468 ) ;
if ( V_469 && V_115 < sizeof( * V_114 ) )
V_469 = 0 ;
#endif
if ( ! V_469 ) {
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
V_20 . V_32 = V_466 ;
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
F_357 ( V_62 ,
V_64 -> V_80 [ 0 ] ) ;
}
if ( V_28 < 0 ) {
F_146 ( V_107 , V_62 , V_28 ) ;
goto V_71;
}
V_468 = V_64 -> V_81 [ 0 ] ;
}
} else if ( V_28 == - V_149 ) {
F_357 ( V_62 , V_64 -> V_80 [ 0 ] ) ;
F_8 ( 1 ) ;
F_177 ( V_12 ,
L_12 ,
( unsigned long long ) V_26 ,
( unsigned long long ) V_16 ,
( unsigned long long ) V_142 ,
( unsigned long long ) V_466 ,
( unsigned long long ) V_467 ) ;
} else {
F_146 ( V_107 , V_62 , V_28 ) ;
goto V_71;
}
V_66 = V_64 -> V_80 [ 0 ] ;
V_115 = F_75 ( V_66 , V_468 ) ;
#ifdef F_79
if ( V_115 < sizeof( * V_114 ) ) {
F_30 ( V_469 || V_468 != V_64 -> V_81 [ 0 ] ) ;
V_28 = F_85 ( V_107 , V_62 , V_64 ,
V_466 , 0 ) ;
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
F_357 ( V_62 , V_64 -> V_80 [ 0 ] ) ;
}
if ( V_28 < 0 ) {
F_146 ( V_107 , V_62 , V_28 ) ;
goto V_71;
}
V_468 = V_64 -> V_81 [ 0 ] ;
V_66 = V_64 -> V_80 [ 0 ] ;
V_115 = F_75 ( V_66 , V_468 ) ;
}
#endif
F_30 ( V_115 < sizeof( * V_114 ) ) ;
V_114 = F_76 ( V_66 , V_468 ,
struct V_113 ) ;
if ( V_466 < V_139 &&
V_20 . type == V_75 ) {
struct V_134 * V_135 ;
F_30 ( V_115 < sizeof( * V_114 ) + sizeof( * V_135 ) ) ;
V_135 = (struct V_134 * ) ( V_114 + 1 ) ;
F_8 ( V_466 != F_358 ( V_66 , V_135 ) ) ;
}
V_109 = F_77 ( V_66 , V_114 ) ;
if ( V_109 < V_155 ) {
F_177 ( V_12 , L_13
L_14 , V_155 , V_109 , V_26 ) ;
V_28 = - V_455 ;
F_146 ( V_107 , V_62 , V_28 ) ;
goto V_71;
}
V_109 -= V_155 ;
if ( V_109 > 0 ) {
if ( V_125 )
F_128 ( V_125 , V_66 , V_114 ) ;
if ( V_159 ) {
F_30 ( ! V_469 ) ;
} else {
F_88 ( V_66 , V_114 , V_109 ) ;
F_93 ( V_66 ) ;
}
if ( V_469 ) {
V_28 = F_137 ( V_107 , V_62 , V_64 ,
V_159 , V_155 ,
V_179 ) ;
if ( V_28 ) {
F_146 ( V_107 , V_62 , V_28 ) ;
goto V_71;
}
}
F_355 ( V_34 -> V_36 , - V_35 , V_466 ,
V_142 ) ;
} else {
if ( V_469 ) {
F_30 ( V_179 && V_155 !=
F_116 ( V_34 , V_64 , V_159 ) ) ;
if ( V_159 ) {
F_30 ( V_64 -> V_81 [ 0 ] != V_468 ) ;
} else {
F_30 ( V_64 -> V_81 [ 0 ] != V_468 + 1 ) ;
V_64 -> V_81 [ 0 ] = V_468 ;
V_470 = 2 ;
}
}
V_28 = F_359 ( V_107 , V_62 , V_64 , V_64 -> V_81 [ 0 ] ,
V_470 ) ;
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
V_28 = F_337 ( V_34 , V_26 , V_35 , 0 ) ;
if ( V_28 ) {
F_146 ( V_107 , V_62 , V_28 ) ;
goto V_71;
}
}
V_71:
F_49 ( V_64 ) ;
return V_28 ;
}
static T_1 int F_360 ( struct V_106 * V_107 ,
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
V_124 = F_205 ( & V_101 -> V_124 . V_14 ) ;
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
V_112 -> V_232 -- ;
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
void F_361 ( struct V_106 * V_107 ,
struct V_33 * V_34 ,
struct V_65 * V_250 ,
T_2 V_16 , int V_471 )
{
struct V_1 * V_2 = NULL ;
int V_472 = 1 ;
int V_28 ;
if ( V_34 -> V_246 . V_21 != V_197 ) {
V_28 = F_143 ( V_34 -> V_36 , V_107 ,
V_250 -> V_31 , V_250 -> V_48 ,
V_16 , V_34 -> V_246 . V_21 ,
F_213 ( V_250 ) ,
V_206 , NULL , 0 ) ;
F_30 ( V_28 ) ;
}
if ( ! V_471 )
return;
V_2 = F_66 ( V_34 -> V_36 , V_250 -> V_31 ) ;
if ( F_362 ( V_250 ) == V_107 -> V_269 ) {
if ( V_34 -> V_246 . V_21 != V_197 ) {
V_28 = F_360 ( V_107 , V_34 , V_250 -> V_31 ) ;
if ( ! V_28 )
goto V_71;
}
if ( F_363 ( V_250 , V_473 ) ) {
F_343 ( V_34 , V_2 , V_250 -> V_31 , V_250 -> V_48 , 1 ) ;
goto V_71;
}
F_8 ( F_332 ( V_474 , & V_250 -> V_475 ) ) ;
F_29 ( V_2 , V_250 -> V_31 , V_250 -> V_48 ) ;
F_348 ( V_2 , V_250 -> V_48 , V_460 ) ;
V_472 = 0 ;
}
V_71:
if ( V_472 )
F_355 ( V_34 -> V_36 , V_250 -> V_48 ,
F_213 ( V_250 ) ,
V_34 -> V_246 . V_21 ) ;
F_364 ( V_476 , & V_250 -> V_475 ) ;
F_6 ( V_2 ) ;
}
int V_256 ( struct V_106 * V_107 , struct V_33 * V_34 ,
T_2 V_26 , T_2 V_35 , T_2 V_16 , T_2 V_142 ,
T_2 V_129 , T_2 V_32 , int V_196 )
{
int V_28 ;
struct V_11 * V_36 = V_34 -> V_36 ;
F_355 ( V_34 -> V_36 , V_35 , V_129 , V_142 ) ;
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
static T_2 F_365 ( struct V_33 * V_34 ,
struct V_1 * V_2 ,
T_2 V_227 , T_2 V_35 )
{
T_2 V_28 = F_261 ( V_227 , V_34 -> V_477 ) ;
return V_28 ;
}
static T_1 int
F_366 ( struct V_1 * V_2 ,
T_2 V_35 )
{
struct V_49 * V_53 ;
V_53 = F_25 ( V_2 ) ;
if ( ! V_53 )
return 0 ;
F_289 ( V_53 -> V_86 , F_1 ( V_2 ) ||
( V_2 -> V_10 -> V_478 >= V_35 ) ) ;
F_26 ( V_53 ) ;
return 0 ;
}
static T_1 int
F_367 ( struct V_1 * V_2 )
{
struct V_49 * V_53 ;
V_53 = F_25 ( V_2 ) ;
if ( ! V_53 )
return 0 ;
F_289 ( V_53 -> V_86 , F_1 ( V_2 ) ) ;
F_26 ( V_53 ) ;
return 0 ;
}
int F_368 ( T_2 V_6 )
{
if ( V_6 & V_284 )
return V_479 ;
else if ( V_6 & V_283 )
return V_480 ;
else if ( V_6 & V_282 )
return V_481 ;
else if ( V_6 & V_323 )
return V_482 ;
else if ( V_6 & V_324 )
return V_483 ;
else if ( V_6 & V_325 )
return V_484 ;
return V_485 ;
}
static int F_369 ( struct V_1 * V_2 )
{
return F_368 ( V_2 -> V_6 ) ;
}
static T_1 int F_370 ( struct V_106 * V_107 ,
struct V_33 * V_486 ,
T_2 V_35 , T_2 V_487 ,
T_2 V_488 , struct V_67 * V_203 ,
T_2 V_6 )
{
int V_28 = 0 ;
struct V_33 * V_34 = V_486 -> V_36 -> V_62 ;
struct V_489 * V_490 = NULL ;
struct V_1 * V_13 = NULL ;
struct V_1 * V_491 ;
T_2 V_454 = 0 ;
int V_492 = 2 * 1024 * 1024 ;
struct V_99 * V_102 ;
int V_493 = 0 ;
int V_494 = F_368 ( V_6 ) ;
int V_495 = ( V_6 & V_299 ) ?
V_496 : V_461 ;
bool V_497 = false ;
bool V_498 = false ;
bool V_499 = false ;
bool V_500 = true ;
bool V_501 = false ;
F_8 ( V_35 < V_34 -> V_331 ) ;
F_371 ( V_203 , V_75 ) ;
V_203 -> V_21 = 0 ;
V_203 -> V_32 = 0 ;
F_372 ( V_486 , V_35 , V_487 , V_6 ) ;
V_102 = F_67 ( V_34 -> V_36 , V_6 ) ;
if ( ! V_102 ) {
F_177 ( V_34 -> V_36 , L_15 , V_6 ) ;
return - V_337 ;
}
if ( F_279 ( V_102 ) )
V_500 = false ;
if ( V_6 & V_305 && V_500 ) {
V_490 = & V_34 -> V_36 -> V_502 ;
if ( ! F_237 ( V_34 , V_503 ) )
V_492 = 64 * 1024 ;
}
if ( ( V_6 & V_299 ) && V_500 &&
F_237 ( V_34 , V_503 ) ) {
V_490 = & V_34 -> V_36 -> V_504 ;
}
if ( V_490 ) {
F_11 ( & V_490 -> V_51 ) ;
if ( V_490 -> V_13 )
V_488 = V_490 -> V_505 ;
F_13 ( & V_490 -> V_51 ) ;
}
V_454 = F_373 ( V_454 , V_25 ( V_34 , 0 ) ) ;
V_454 = F_373 ( V_454 , V_488 ) ;
if ( ! V_490 )
V_492 = 0 ;
if ( V_454 == V_488 ) {
V_13 = F_66 ( V_34 -> V_36 ,
V_454 ) ;
V_491 = V_13 ;
if ( V_13 && F_3 ( V_13 , V_6 ) &&
V_13 -> V_3 != V_93 ) {
F_36 ( & V_102 -> V_290 ) ;
if ( F_162 ( & V_13 -> V_89 ) ||
V_13 -> V_267 ) {
F_6 ( V_13 ) ;
F_44 ( & V_102 -> V_290 ) ;
} else {
V_494 = F_369 ( V_13 ) ;
goto V_506;
}
} else if ( V_13 ) {
F_6 ( V_13 ) ;
}
}
V_507:
V_501 = false ;
F_36 ( & V_102 -> V_290 ) ;
F_374 (block_group, &space_info->block_groups[index],
list) {
T_2 V_32 ;
int V_3 ;
V_491 = V_13 ;
F_4 ( V_13 ) ;
V_454 = V_13 -> V_20 . V_21 ;
if ( ! F_3 ( V_13 , V_6 ) ) {
T_2 V_508 = V_282 |
V_283 |
V_324 |
V_325 |
V_284 ;
if ( ( V_6 & V_508 ) && ! ( V_13 -> V_6 & V_508 ) )
goto V_493;
}
V_506:
V_3 = F_1 ( V_13 ) ;
if ( F_296 ( ! V_3 ) ) {
V_497 = true ;
V_28 = F_50 ( V_13 , 0 ) ;
F_30 ( V_28 < 0 ) ;
V_28 = 0 ;
}
if ( F_296 ( V_13 -> V_267 ) )
goto V_493;
if ( V_490 ) {
unsigned long V_509 ;
F_11 ( & V_490 -> V_510 ) ;
V_491 = V_490 -> V_13 ;
if ( V_491 != V_13 &&
( ! V_491 ||
V_491 -> V_267 ||
! F_3 ( V_491 , V_6 ) ) ) {
V_491 = V_13 ;
goto V_511;
}
if ( V_491 != V_13 )
F_4 ( V_491 ) ;
V_32 = F_375 ( V_491 ,
V_490 , V_35 , V_491 -> V_20 . V_21 ) ;
if ( V_32 ) {
F_13 ( & V_490 -> V_510 ) ;
F_376 ( V_34 ,
V_13 , V_454 , V_35 ) ;
goto V_512;
}
F_8 ( V_490 -> V_13 != V_491 ) ;
if ( V_491 != V_13 ) {
F_6 ( V_491 ) ;
V_491 = V_13 ;
}
V_511:
F_30 ( V_491 != V_13 ) ;
if ( V_493 >= V_513 &&
V_490 -> V_13 != V_13 ) {
F_13 ( & V_490 -> V_510 ) ;
goto V_514;
}
F_377 ( NULL , V_490 ) ;
if ( V_493 >= V_513 ) {
F_13 ( & V_490 -> V_510 ) ;
goto V_514;
}
V_509 = F_34 (unsigned long,
empty_cluster + empty_size,
block_group->full_stripe_len) ;
V_28 = F_378 ( V_107 , V_34 ,
V_13 , V_490 ,
V_454 , V_35 ,
V_509 ) ;
if ( V_28 == 0 ) {
V_32 = F_375 ( V_13 ,
V_490 , V_35 ,
V_454 ) ;
if ( V_32 ) {
F_13 ( & V_490 -> V_510 ) ;
F_376 ( V_34 ,
V_13 , V_454 ,
V_35 ) ;
goto V_512;
}
} else if ( ! V_3 && V_493 > V_515
&& ! V_498 ) {
F_13 ( & V_490 -> V_510 ) ;
V_498 = true ;
F_366 ( V_13 ,
V_35 + V_492 + V_487 ) ;
goto V_506;
}
F_377 ( NULL , V_490 ) ;
F_13 ( & V_490 -> V_510 ) ;
goto V_493;
}
V_514:
F_11 ( & V_13 -> V_10 -> V_516 ) ;
if ( V_3 &&
V_13 -> V_10 -> V_478 <
V_35 + V_492 + V_487 ) {
F_13 ( & V_13 -> V_10 -> V_516 ) ;
goto V_493;
}
F_13 ( & V_13 -> V_10 -> V_516 ) ;
V_32 = F_379 ( V_13 , V_454 ,
V_35 , V_487 ) ;
if ( ! V_32 && ! V_499 && ! V_3 &&
V_493 > V_515 ) {
F_366 ( V_13 ,
V_35 + V_487 ) ;
V_499 = true ;
goto V_506;
} else if ( ! V_32 ) {
if ( ! V_3 )
V_501 = true ;
goto V_493;
}
V_512:
V_454 = F_365 ( V_34 , V_491 ,
V_32 , V_35 ) ;
if ( V_454 + V_35 >
V_491 -> V_20 . V_21 + V_491 -> V_20 . V_32 ) {
F_29 ( V_491 , V_32 , V_35 ) ;
goto V_493;
}
if ( V_32 < V_454 )
F_29 ( V_491 , V_32 ,
V_454 - V_32 ) ;
F_30 ( V_32 > V_454 ) ;
V_28 = F_348 ( V_491 , V_35 ,
V_495 ) ;
if ( V_28 == - V_173 ) {
F_29 ( V_491 , V_32 , V_35 ) ;
goto V_493;
}
V_203 -> V_21 = V_454 ;
V_203 -> V_32 = V_35 ;
F_380 ( V_486 , V_13 ,
V_454 , V_35 ) ;
if ( V_491 != V_13 )
F_6 ( V_491 ) ;
F_6 ( V_13 ) ;
break;
V_493:
V_498 = false ;
V_499 = false ;
F_30 ( V_494 != F_369 ( V_13 ) ) ;
if ( V_491 != V_13 )
F_6 ( V_491 ) ;
F_6 ( V_13 ) ;
}
F_44 ( & V_102 -> V_290 ) ;
if ( ! V_203 -> V_21 && V_493 >= V_517 && V_501 )
goto V_507;
if ( ! V_203 -> V_21 && ++ V_494 < V_288 )
goto V_507;
if ( ! V_203 -> V_21 && V_493 < V_513 ) {
V_494 = 0 ;
V_493 ++ ;
if ( V_493 == V_518 ) {
V_28 = F_263 ( V_107 , V_34 , V_6 ,
V_336 ) ;
if ( V_28 < 0 && V_28 != - V_337 ) {
F_146 ( V_107 ,
V_34 , V_28 ) ;
goto V_71;
}
}
if ( V_493 == V_513 ) {
V_487 = 0 ;
V_492 = 0 ;
}
goto V_507;
} else if ( ! V_203 -> V_21 ) {
V_28 = - V_337 ;
} else if ( V_203 -> V_21 ) {
V_28 = 0 ;
}
V_71:
return V_28 ;
}
static void F_277 ( struct V_99 * V_12 , T_2 V_327 ,
int V_519 )
{
struct V_1 * V_2 ;
int V_494 = 0 ;
F_11 ( & V_12 -> V_51 ) ;
F_381 ( V_520 L_16 ,
( unsigned long long ) V_12 -> V_6 ,
( unsigned long long ) ( V_12 -> V_279 - V_12 -> V_280 -
V_12 -> V_291 - V_12 -> V_292 -
V_12 -> V_293 ) ,
( V_12 -> V_105 ) ? L_4 : L_17 ) ;
F_381 ( V_520 L_18
L_19 ,
( unsigned long long ) V_12 -> V_279 ,
( unsigned long long ) V_12 -> V_280 ,
( unsigned long long ) V_12 -> V_291 ,
( unsigned long long ) V_12 -> V_292 ,
( unsigned long long ) V_12 -> V_294 ,
( unsigned long long ) V_12 -> V_293 ) ;
F_13 ( & V_12 -> V_51 ) ;
if ( ! V_519 )
return;
F_36 ( & V_12 -> V_290 ) ;
V_76:
F_374 (cache, &info->block_groups[index], list) {
F_11 ( & V_2 -> V_51 ) ;
F_381 ( V_520 L_20 ,
( unsigned long long ) V_2 -> V_20 . V_21 ,
( unsigned long long ) V_2 -> V_20 . V_32 ,
( unsigned long long ) F_340 ( & V_2 -> V_131 ) ,
( unsigned long long ) V_2 -> V_8 ,
( unsigned long long ) V_2 -> V_9 ,
V_2 -> V_267 ? L_21 : L_4 ) ;
F_382 ( V_2 , V_327 ) ;
F_13 ( & V_2 -> V_51 ) ;
}
if ( ++ V_494 < V_288 )
goto V_76;
F_44 ( & V_12 -> V_290 ) ;
}
int F_383 ( struct V_106 * V_107 ,
struct V_33 * V_34 ,
T_2 V_35 , T_2 V_521 ,
T_2 V_487 , T_2 V_488 ,
struct V_67 * V_203 , int V_179 )
{
bool V_522 = false ;
T_2 V_6 ;
int V_28 ;
V_6 = F_260 ( V_34 , V_179 ) ;
V_76:
F_8 ( V_35 < V_34 -> V_331 ) ;
V_28 = F_370 ( V_107 , V_34 , V_35 , V_487 ,
V_488 , V_203 , V_6 ) ;
if ( V_28 == - V_337 ) {
if ( ! V_522 ) {
V_35 = V_35 >> 1 ;
V_35 = F_384 ( V_35 , V_34 -> V_331 ) ;
V_35 = F_373 ( V_35 , V_521 ) ;
if ( V_35 == V_521 )
V_522 = true ;
goto V_76;
} else if ( F_237 ( V_34 , V_349 ) ) {
struct V_99 * V_341 ;
V_341 = F_67 ( V_34 -> V_36 , V_6 ) ;
F_177 ( V_34 -> V_36 , L_22 ,
( unsigned long long ) V_6 ,
( unsigned long long ) V_35 ) ;
if ( V_341 )
F_277 ( V_341 , V_35 , 1 ) ;
}
}
F_385 ( V_34 , V_203 -> V_21 , V_203 -> V_32 ) ;
return V_28 ;
}
static int F_386 ( struct V_33 * V_34 ,
T_2 V_31 , T_2 V_48 , int V_472 )
{
struct V_1 * V_2 ;
int V_28 = 0 ;
V_2 = F_66 ( V_34 -> V_36 , V_31 ) ;
if ( ! V_2 ) {
F_177 ( V_34 -> V_36 , L_23 ,
( unsigned long long ) V_31 ) ;
return - V_337 ;
}
if ( F_237 ( V_34 , V_464 ) )
V_28 = F_140 ( V_34 , V_31 , V_48 , NULL ) ;
if ( V_472 )
F_343 ( V_34 , V_2 , V_31 , V_48 , 1 ) ;
else {
F_29 ( V_2 , V_31 , V_48 ) ;
F_348 ( V_2 , V_48 , V_460 ) ;
}
F_6 ( V_2 ) ;
F_387 ( V_34 , V_31 , V_48 ) ;
return V_28 ;
}
int F_388 ( struct V_33 * V_34 ,
T_2 V_31 , T_2 V_48 )
{
return F_386 ( V_34 , V_31 , V_48 , 0 ) ;
}
int F_389 ( struct V_33 * V_34 ,
T_2 V_31 , T_2 V_48 )
{
return F_386 ( V_34 , V_31 , V_48 , 1 ) ;
}
static int F_149 ( struct V_106 * V_107 ,
struct V_33 * V_34 ,
T_2 V_16 , T_2 V_142 ,
T_2 V_6 , T_2 V_129 , T_2 V_32 ,
struct V_67 * V_203 , int V_128 )
{
int V_28 ;
struct V_11 * V_36 = V_34 -> V_36 ;
struct V_113 * V_523 ;
struct V_158 * V_159 ;
struct V_63 * V_64 ;
struct V_65 * V_66 ;
int type ;
T_3 V_56 ;
if ( V_16 > 0 )
type = V_150 ;
else
type = V_151 ;
V_56 = sizeof( * V_523 ) + F_123 ( type ) ;
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
V_523 = F_76 ( V_66 , V_64 -> V_81 [ 0 ] ,
struct V_113 ) ;
F_88 ( V_66 , V_523 , V_128 ) ;
F_89 ( V_66 , V_523 , V_107 -> V_269 ) ;
F_90 ( V_66 , V_523 ,
V_6 | V_141 ) ;
V_159 = (struct V_158 * ) ( V_523 + 1 ) ;
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
V_28 = F_337 ( V_34 , V_203 -> V_21 , V_203 -> V_32 , 1 ) ;
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
T_2 V_6 , struct V_439 * V_20 ,
int V_162 , struct V_67 * V_203 )
{
int V_28 ;
struct V_11 * V_36 = V_34 -> V_36 ;
struct V_113 * V_523 ;
struct V_134 * V_524 ;
struct V_158 * V_159 ;
struct V_63 * V_64 ;
struct V_65 * V_66 ;
T_3 V_56 = sizeof( * V_523 ) + sizeof( * V_159 ) ;
bool V_168 = F_74 ( V_34 -> V_36 ,
V_118 ) ;
if ( ! V_168 )
V_56 += sizeof( * V_524 ) ;
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
V_523 = F_76 ( V_66 , V_64 -> V_81 [ 0 ] ,
struct V_113 ) ;
F_88 ( V_66 , V_523 , 1 ) ;
F_89 ( V_66 , V_523 , V_107 -> V_269 ) ;
F_90 ( V_66 , V_523 ,
V_6 | V_140 ) ;
if ( V_168 ) {
V_159 = (struct V_158 * ) ( V_523 + 1 ) ;
} else {
V_524 = (struct V_134 * ) ( V_523 + 1 ) ;
F_151 ( V_66 , V_524 , V_20 ) ;
F_92 ( V_66 , V_524 , V_162 ) ;
V_159 = (struct V_158 * ) ( V_524 + 1 ) ;
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
V_28 = F_337 ( V_34 , V_203 -> V_21 , V_34 -> V_85 , 1 ) ;
if ( V_28 ) {
F_177 ( V_36 , L_24 ,
( unsigned long long ) V_203 -> V_21 ,
( unsigned long long ) V_203 -> V_32 ) ;
F_81 () ;
}
return V_28 ;
}
int F_390 ( struct V_106 * V_107 ,
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
int F_391 ( struct V_106 * V_107 ,
struct V_33 * V_34 ,
T_2 V_142 , T_2 V_129 , T_2 V_32 ,
struct V_67 * V_203 )
{
int V_28 ;
struct V_1 * V_13 ;
if ( ! F_74 ( V_34 -> V_36 , V_459 ) ) {
V_28 = F_346 ( V_34 , V_203 -> V_21 , V_203 -> V_32 ) ;
if ( V_28 )
return V_28 ;
}
V_13 = F_66 ( V_34 -> V_36 , V_203 -> V_21 ) ;
if ( ! V_13 )
return - V_455 ;
V_28 = F_348 ( V_13 , V_203 -> V_32 ,
V_496 ) ;
F_30 ( V_28 ) ;
V_28 = F_149 ( V_107 , V_34 , 0 , V_142 ,
0 , V_129 , V_32 , V_203 , 1 ) ;
F_6 ( V_13 ) ;
return V_28 ;
}
static struct V_65 *
F_392 ( struct V_106 * V_107 , struct V_33 * V_34 ,
T_2 V_26 , T_3 V_525 , int V_162 )
{
struct V_65 * V_250 ;
V_250 = F_393 ( V_34 , V_26 , V_525 ) ;
if ( ! V_250 )
return F_394 ( - V_88 ) ;
F_395 ( V_250 , V_107 -> V_269 ) ;
F_396 ( V_34 -> V_246 . V_21 , V_250 , V_162 ) ;
F_397 ( V_250 ) ;
F_398 ( V_107 , V_34 , V_250 ) ;
F_364 ( V_526 , & V_250 -> V_475 ) ;
F_399 ( V_250 ) ;
F_400 ( V_250 ) ;
if ( V_34 -> V_246 . V_21 == V_197 ) {
if ( V_34 -> V_527 % 2 == 0 )
F_342 ( & V_34 -> V_528 , V_250 -> V_31 ,
V_250 -> V_31 + V_250 -> V_48 - 1 , V_39 ) ;
else
F_401 ( & V_34 -> V_528 , V_250 -> V_31 ,
V_250 -> V_31 + V_250 -> V_48 - 1 , V_39 ) ;
} else {
F_342 ( & V_107 -> V_123 -> V_529 , V_250 -> V_31 ,
V_250 -> V_31 + V_250 -> V_48 - 1 , V_39 ) ;
}
V_107 -> V_530 ++ ;
return V_250 ;
}
static struct V_230 *
F_402 ( struct V_106 * V_107 ,
struct V_33 * V_34 , T_3 V_525 )
{
struct V_230 * V_373 ;
struct V_230 * V_231 = & V_34 -> V_36 -> V_233 ;
int V_28 ;
bool V_531 = false ;
V_373 = F_299 ( V_107 , V_34 ) ;
if ( F_296 ( V_373 -> V_56 == 0 ) )
goto V_532;
V_76:
V_28 = F_297 ( V_373 , V_525 ) ;
if ( ! V_28 )
return V_373 ;
if ( V_373 -> V_533 )
return F_394 ( V_28 ) ;
if ( V_373 -> type == V_534 && ! V_531 ) {
V_531 = true ;
F_315 ( V_34 -> V_36 ) ;
goto V_76;
}
if ( F_237 ( V_34 , V_349 ) ) {
static F_403 ( V_535 ,
V_536 * 10 ,
1 ) ;
if ( F_404 ( & V_535 ) )
F_405 ( 1 , V_537
L_25 , V_28 ) ;
}
V_532:
V_28 = F_294 ( V_34 , V_373 , V_525 ,
V_381 ) ;
if ( ! V_28 )
return V_373 ;
if ( V_373 -> type != V_534 &&
V_373 -> V_102 == V_231 -> V_102 ) {
V_28 = F_297 ( V_231 , V_525 ) ;
if ( ! V_28 )
return V_231 ;
}
return F_394 ( V_28 ) ;
}
static void F_406 ( struct V_11 * V_36 ,
struct V_230 * V_373 , T_3 V_525 )
{
F_300 ( V_373 , V_525 , 0 ) ;
F_302 ( V_36 , V_373 , NULL , 0 ) ;
}
struct V_65 * F_407 ( struct V_106 * V_107 ,
struct V_33 * V_34 , T_3 V_525 ,
T_2 V_16 , T_2 V_142 ,
struct V_439 * V_20 , int V_162 ,
T_2 V_538 , T_2 V_487 )
{
struct V_67 V_203 ;
struct V_230 * V_373 ;
struct V_65 * V_250 ;
T_2 V_6 = 0 ;
int V_28 ;
bool V_168 = F_74 ( V_34 -> V_36 ,
V_118 ) ;
V_373 = F_402 ( V_107 , V_34 , V_525 ) ;
if ( F_229 ( V_373 ) )
return F_408 ( V_373 ) ;
V_28 = F_383 ( V_107 , V_34 , V_525 , V_525 ,
V_487 , V_538 , & V_203 , 0 ) ;
if ( V_28 ) {
F_406 ( V_34 -> V_36 , V_373 , V_525 ) ;
return F_394 ( V_28 ) ;
}
V_250 = F_392 ( V_107 , V_34 , V_203 . V_21 ,
V_525 , V_162 ) ;
F_30 ( F_229 ( V_250 ) ) ;
if ( V_142 == V_539 ) {
if ( V_16 == 0 )
V_16 = V_203 . V_21 ;
V_6 |= V_122 ;
} else
F_30 ( V_16 > 0 ) ;
if ( V_142 != V_197 ) {
struct V_175 * V_125 ;
V_125 = F_202 () ;
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
return V_250 ;
}
static T_1 void F_409 ( struct V_106 * V_107 ,
struct V_33 * V_34 ,
struct V_540 * V_541 ,
struct V_63 * V_64 )
{
T_2 V_26 ;
T_2 V_272 ;
T_2 V_109 ;
T_2 V_6 ;
T_3 V_70 ;
T_3 V_525 ;
struct V_67 V_20 ;
struct V_65 * V_457 ;
int V_28 ;
int V_542 ;
int V_543 = 0 ;
if ( V_64 -> V_81 [ V_541 -> V_162 ] < V_541 -> V_544 ) {
V_541 -> V_545 = V_541 -> V_545 * 2 / 3 ;
V_541 -> V_545 = F_373 ( V_541 -> V_545 , 2 ) ;
} else {
V_541 -> V_545 = V_541 -> V_545 * 3 / 2 ;
V_541 -> V_545 = F_24 ( int , V_541 -> V_545 ,
F_410 ( V_34 ) ) ;
}
V_457 = V_64 -> V_80 [ V_541 -> V_162 ] ;
V_70 = F_38 ( V_457 ) ;
V_525 = F_220 ( V_34 , V_541 -> V_162 - 1 ) ;
for ( V_542 = V_64 -> V_81 [ V_541 -> V_162 ] ; V_542 < V_70 ; V_542 ++ ) {
if ( V_543 >= V_541 -> V_545 )
break;
F_46 () ;
V_26 = F_219 ( V_457 , V_542 ) ;
V_272 = F_411 ( V_457 , V_542 ) ;
if ( V_542 == V_64 -> V_81 [ V_541 -> V_162 ] )
goto V_74;
if ( V_541 -> V_546 == V_547 &&
V_272 <= V_34 -> V_246 . V_32 )
continue;
V_28 = F_73 ( V_107 , V_34 , V_26 ,
V_541 -> V_162 - 1 , 1 , & V_109 ,
& V_6 ) ;
if ( V_28 < 0 )
continue;
F_30 ( V_109 == 0 ) ;
if ( V_541 -> V_546 == V_548 ) {
if ( V_109 == 1 )
goto V_74;
if ( V_541 -> V_162 == 1 &&
( V_6 & V_122 ) )
continue;
if ( ! V_541 -> V_549 ||
V_272 <= V_34 -> V_246 . V_32 )
continue;
F_121 ( V_457 , & V_20 , V_542 ) ;
V_28 = F_412 ( & V_20 ,
& V_541 -> V_550 ) ;
if ( V_28 < 0 )
continue;
} else {
if ( V_541 -> V_162 == 1 &&
( V_6 & V_122 ) )
continue;
}
V_74:
V_28 = F_413 ( V_34 , V_26 , V_525 ,
V_272 ) ;
if ( V_28 )
break;
V_543 ++ ;
}
V_541 -> V_544 = V_542 ;
}
static T_1 int F_414 ( struct V_106 * V_107 ,
struct V_33 * V_34 ,
struct V_63 * V_64 ,
struct V_540 * V_541 , int V_551 )
{
int V_162 = V_541 -> V_162 ;
struct V_65 * V_457 = V_64 -> V_80 [ V_162 ] ;
T_2 V_552 = V_122 ;
int V_28 ;
if ( V_541 -> V_546 == V_547 &&
F_212 ( V_457 ) != V_34 -> V_246 . V_21 )
return 1 ;
if ( V_551 &&
( ( V_541 -> V_546 == V_548 && V_541 -> V_109 [ V_162 ] != 1 ) ||
( V_541 -> V_546 == V_547 && ! ( V_541 -> V_6 [ V_162 ] & V_552 ) ) ) ) {
F_30 ( ! V_64 -> V_553 [ V_162 ] ) ;
V_28 = F_73 ( V_107 , V_34 ,
V_457 -> V_31 , V_162 , 1 ,
& V_541 -> V_109 [ V_162 ] ,
& V_541 -> V_6 [ V_162 ] ) ;
F_30 ( V_28 == - V_88 ) ;
if ( V_28 )
return V_28 ;
F_30 ( V_541 -> V_109 [ V_162 ] == 0 ) ;
}
if ( V_541 -> V_546 == V_548 ) {
if ( V_541 -> V_109 [ V_162 ] > 1 )
return 1 ;
if ( V_64 -> V_553 [ V_162 ] && ! V_541 -> V_169 ) {
F_415 ( V_457 , V_64 -> V_553 [ V_162 ] ) ;
V_64 -> V_553 [ V_162 ] = 0 ;
}
return 0 ;
}
if ( ! ( V_541 -> V_6 [ V_162 ] & V_552 ) ) {
F_30 ( ! V_64 -> V_553 [ V_162 ] ) ;
V_28 = F_221 ( V_107 , V_34 , V_457 , 1 , V_541 -> V_554 ) ;
F_30 ( V_28 ) ;
V_28 = F_222 ( V_107 , V_34 , V_457 , 0 , V_541 -> V_554 ) ;
F_30 ( V_28 ) ;
V_28 = F_201 ( V_107 , V_34 , V_457 -> V_31 ,
V_457 -> V_48 , V_552 ,
F_213 ( V_457 ) , 0 ) ;
F_30 ( V_28 ) ;
V_541 -> V_6 [ V_162 ] |= V_552 ;
}
if ( V_64 -> V_553 [ V_162 ] && V_162 > 0 ) {
F_415 ( V_457 , V_64 -> V_553 [ V_162 ] ) ;
V_64 -> V_553 [ V_162 ] = 0 ;
}
return 0 ;
}
static T_1 int F_416 ( struct V_106 * V_107 ,
struct V_33 * V_34 ,
struct V_63 * V_64 ,
struct V_540 * V_541 , int * V_551 )
{
T_2 V_26 ;
T_2 V_272 ;
T_2 V_16 ;
T_3 V_525 ;
struct V_67 V_20 ;
struct V_65 * V_213 ;
int V_162 = V_541 -> V_162 ;
int V_74 = 0 ;
int V_28 = 0 ;
V_272 = F_411 ( V_64 -> V_80 [ V_162 ] ,
V_64 -> V_81 [ V_162 ] ) ;
if ( V_541 -> V_546 == V_547 &&
V_272 <= V_34 -> V_246 . V_32 ) {
* V_551 = 1 ;
return 1 ;
}
V_26 = F_219 ( V_64 -> V_80 [ V_162 ] , V_64 -> V_81 [ V_162 ] ) ;
V_525 = F_220 ( V_34 , V_162 - 1 ) ;
V_213 = F_417 ( V_34 , V_26 , V_525 ) ;
if ( ! V_213 ) {
V_213 = F_393 ( V_34 , V_26 , V_525 ) ;
if ( ! V_213 )
return - V_88 ;
V_74 = 1 ;
}
F_397 ( V_213 ) ;
F_399 ( V_213 ) ;
V_28 = F_73 ( V_107 , V_34 , V_26 , V_162 - 1 , 1 ,
& V_541 -> V_109 [ V_162 - 1 ] ,
& V_541 -> V_6 [ V_162 - 1 ] ) ;
if ( V_28 < 0 ) {
F_418 ( V_213 ) ;
return V_28 ;
}
if ( F_296 ( V_541 -> V_109 [ V_162 - 1 ] == 0 ) ) {
F_177 ( V_34 -> V_36 , L_26 ) ;
F_81 () ;
}
* V_551 = 0 ;
if ( V_541 -> V_546 == V_548 ) {
if ( V_541 -> V_109 [ V_162 - 1 ] > 1 ) {
if ( V_162 == 1 &&
( V_541 -> V_6 [ 0 ] & V_122 ) )
goto V_555;
if ( ! V_541 -> V_549 ||
V_272 <= V_34 -> V_246 . V_32 )
goto V_555;
F_121 ( V_64 -> V_80 [ V_162 ] , & V_20 ,
V_64 -> V_81 [ V_162 ] ) ;
V_28 = F_412 ( & V_20 , & V_541 -> V_550 ) ;
if ( V_28 < 0 )
goto V_555;
V_541 -> V_546 = V_547 ;
V_541 -> V_556 = V_162 - 1 ;
}
} else {
if ( V_162 == 1 &&
( V_541 -> V_6 [ 0 ] & V_122 ) )
goto V_555;
}
if ( ! F_419 ( V_213 , V_272 , 0 ) ) {
F_418 ( V_213 ) ;
F_420 ( V_213 ) ;
V_213 = NULL ;
* V_551 = 1 ;
}
if ( ! V_213 ) {
if ( V_74 && V_162 == 1 )
F_409 ( V_107 , V_34 , V_541 , V_64 ) ;
V_213 = F_421 ( V_34 , V_26 , V_525 , V_272 ) ;
if ( ! V_213 || ! F_422 ( V_213 ) ) {
F_420 ( V_213 ) ;
return - V_170 ;
}
F_397 ( V_213 ) ;
F_399 ( V_213 ) ;
}
V_162 -- ;
F_30 ( V_162 != F_213 ( V_213 ) ) ;
V_64 -> V_80 [ V_162 ] = V_213 ;
V_64 -> V_81 [ V_162 ] = 0 ;
V_64 -> V_553 [ V_162 ] = V_557 ;
V_541 -> V_162 = V_162 ;
if ( V_541 -> V_162 == 1 )
V_541 -> V_544 = 0 ;
return 0 ;
V_555:
V_541 -> V_109 [ V_162 - 1 ] = 0 ;
V_541 -> V_6 [ V_162 - 1 ] = 0 ;
if ( V_541 -> V_546 == V_548 ) {
if ( V_541 -> V_6 [ V_162 ] & V_122 ) {
V_16 = V_64 -> V_80 [ V_162 ] -> V_31 ;
} else {
F_30 ( V_34 -> V_246 . V_21 !=
F_212 ( V_64 -> V_80 [ V_162 ] ) ) ;
V_16 = 0 ;
}
V_28 = V_256 ( V_107 , V_34 , V_26 , V_525 , V_16 ,
V_34 -> V_246 . V_21 , V_162 - 1 , 0 , 0 ) ;
F_30 ( V_28 ) ;
}
F_418 ( V_213 ) ;
F_420 ( V_213 ) ;
* V_551 = 1 ;
return 1 ;
}
static T_1 int F_423 ( struct V_106 * V_107 ,
struct V_33 * V_34 ,
struct V_63 * V_64 ,
struct V_540 * V_541 )
{
int V_28 ;
int V_162 = V_541 -> V_162 ;
struct V_65 * V_457 = V_64 -> V_80 [ V_162 ] ;
T_2 V_16 = 0 ;
if ( V_541 -> V_546 == V_547 ) {
F_30 ( V_541 -> V_556 < V_162 ) ;
if ( V_162 < V_541 -> V_556 )
goto V_71;
V_28 = F_41 ( V_64 , V_162 + 1 , & V_541 -> V_550 ) ;
if ( V_28 > 0 )
V_541 -> V_549 = 0 ;
V_541 -> V_546 = V_548 ;
V_541 -> V_556 = - 1 ;
V_64 -> V_81 [ V_162 ] = 0 ;
if ( ! V_64 -> V_553 [ V_162 ] ) {
F_30 ( V_162 == 0 ) ;
F_397 ( V_457 ) ;
F_399 ( V_457 ) ;
V_64 -> V_553 [ V_162 ] = V_557 ;
V_28 = F_73 ( V_107 , V_34 ,
V_457 -> V_31 , V_162 , 1 ,
& V_541 -> V_109 [ V_162 ] ,
& V_541 -> V_6 [ V_162 ] ) ;
if ( V_28 < 0 ) {
F_415 ( V_457 , V_64 -> V_553 [ V_162 ] ) ;
V_64 -> V_553 [ V_162 ] = 0 ;
return V_28 ;
}
F_30 ( V_541 -> V_109 [ V_162 ] == 0 ) ;
if ( V_541 -> V_109 [ V_162 ] == 1 ) {
F_415 ( V_457 , V_64 -> V_553 [ V_162 ] ) ;
V_64 -> V_553 [ V_162 ] = 0 ;
return 1 ;
}
}
}
F_30 ( V_541 -> V_109 [ V_162 ] > 1 && ! V_64 -> V_553 [ V_162 ] ) ;
if ( V_541 -> V_109 [ V_162 ] == 1 ) {
if ( V_162 == 0 ) {
if ( V_541 -> V_6 [ V_162 ] & V_122 )
V_28 = F_222 ( V_107 , V_34 , V_457 , 1 ,
V_541 -> V_554 ) ;
else
V_28 = F_222 ( V_107 , V_34 , V_457 , 0 ,
V_541 -> V_554 ) ;
F_30 ( V_28 ) ;
}
if ( ! V_64 -> V_553 [ V_162 ] &&
F_362 ( V_457 ) == V_107 -> V_269 ) {
F_397 ( V_457 ) ;
F_399 ( V_457 ) ;
V_64 -> V_553 [ V_162 ] = V_557 ;
}
F_398 ( V_107 , V_34 , V_457 ) ;
}
if ( V_457 == V_34 -> V_124 ) {
if ( V_541 -> V_6 [ V_162 ] & V_122 )
V_16 = V_457 -> V_31 ;
else
F_30 ( V_34 -> V_246 . V_21 !=
F_212 ( V_457 ) ) ;
} else {
if ( V_541 -> V_6 [ V_162 + 1 ] & V_122 )
V_16 = V_64 -> V_80 [ V_162 + 1 ] -> V_31 ;
else
F_30 ( V_34 -> V_246 . V_21 !=
F_212 ( V_64 -> V_80 [ V_162 + 1 ] ) ) ;
}
F_361 ( V_107 , V_34 , V_457 , V_16 , V_541 -> V_109 [ V_162 ] == 1 ) ;
V_71:
V_541 -> V_109 [ V_162 ] = 0 ;
V_541 -> V_6 [ V_162 ] = 0 ;
return 0 ;
}
static T_1 int F_424 ( struct V_106 * V_107 ,
struct V_33 * V_34 ,
struct V_63 * V_64 ,
struct V_540 * V_541 )
{
int V_162 = V_541 -> V_162 ;
int V_551 = 1 ;
int V_28 ;
while ( V_162 >= 0 ) {
V_28 = F_414 ( V_107 , V_34 , V_64 , V_541 , V_551 ) ;
if ( V_28 > 0 )
break;
if ( V_162 == 0 )
break;
if ( V_64 -> V_81 [ V_162 ] >=
F_38 ( V_64 -> V_80 [ V_162 ] ) )
break;
V_28 = F_416 ( V_107 , V_34 , V_64 , V_541 , & V_551 ) ;
if ( V_28 > 0 ) {
V_64 -> V_81 [ V_162 ] ++ ;
continue;
} else if ( V_28 < 0 )
return V_28 ;
V_162 = V_541 -> V_162 ;
}
return 0 ;
}
static T_1 int F_425 ( struct V_106 * V_107 ,
struct V_33 * V_34 ,
struct V_63 * V_64 ,
struct V_540 * V_541 , int V_558 )
{
int V_162 = V_541 -> V_162 ;
int V_28 ;
V_64 -> V_81 [ V_162 ] = F_38 ( V_64 -> V_80 [ V_162 ] ) ;
while ( V_162 < V_558 && V_64 -> V_80 [ V_162 ] ) {
V_541 -> V_162 = V_162 ;
if ( V_64 -> V_81 [ V_162 ] + 1 <
F_38 ( V_64 -> V_80 [ V_162 ] ) ) {
V_64 -> V_81 [ V_162 ] ++ ;
return 0 ;
} else {
V_28 = F_423 ( V_107 , V_34 , V_64 , V_541 ) ;
if ( V_28 > 0 )
return 0 ;
if ( V_64 -> V_553 [ V_162 ] ) {
F_415 ( V_64 -> V_80 [ V_162 ] ,
V_64 -> V_553 [ V_162 ] ) ;
V_64 -> V_553 [ V_162 ] = 0 ;
}
F_420 ( V_64 -> V_80 [ V_162 ] ) ;
V_64 -> V_80 [ V_162 ] = NULL ;
V_162 ++ ;
}
}
return 1 ;
}
int F_426 ( struct V_33 * V_34 ,
struct V_230 * V_373 , int V_549 ,
int V_554 )
{
struct V_63 * V_64 ;
struct V_106 * V_107 ;
struct V_33 * V_84 = V_34 -> V_36 -> V_84 ;
struct V_559 * V_247 = & V_34 -> V_247 ;
struct V_540 * V_541 ;
struct V_67 V_20 ;
int V_79 = 0 ;
int V_28 ;
int V_162 ;
bool V_560 = false ;
V_64 = F_33 () ;
if ( ! V_64 ) {
V_79 = - V_88 ;
goto V_71;
}
V_541 = F_52 ( sizeof( * V_541 ) , V_39 ) ;
if ( ! V_541 ) {
F_49 ( V_64 ) ;
V_79 = - V_88 ;
goto V_71;
}
V_107 = F_427 ( V_84 , 0 ) ;
if ( F_229 ( V_107 ) ) {
V_79 = F_230 ( V_107 ) ;
goto V_119;
}
if ( V_373 )
V_107 -> V_373 = V_373 ;
if ( F_428 ( & V_247 -> V_561 ) == 0 ) {
V_162 = F_213 ( V_34 -> V_124 ) ;
V_64 -> V_80 [ V_162 ] = F_429 ( V_34 ) ;
F_399 ( V_64 -> V_80 [ V_162 ] ) ;
V_64 -> V_81 [ V_162 ] = 0 ;
V_64 -> V_553 [ V_162 ] = V_557 ;
memset ( & V_541 -> V_550 , 0 ,
sizeof( V_541 -> V_550 ) ) ;
} else {
F_430 ( & V_20 , & V_247 -> V_561 ) ;
memcpy ( & V_541 -> V_550 , & V_20 ,
sizeof( V_541 -> V_550 ) ) ;
V_162 = V_247 -> V_562 ;
F_30 ( V_162 == 0 ) ;
V_64 -> V_563 = V_162 ;
V_28 = F_37 ( NULL , V_34 , & V_20 , V_64 , 0 , 0 ) ;
V_64 -> V_563 = 0 ;
if ( V_28 < 0 ) {
V_79 = V_28 ;
goto V_564;
}
F_8 ( V_28 > 0 ) ;
F_126 ( V_64 , 0 ) ;
V_162 = F_213 ( V_34 -> V_124 ) ;
while ( 1 ) {
F_397 ( V_64 -> V_80 [ V_162 ] ) ;
F_399 ( V_64 -> V_80 [ V_162 ] ) ;
V_64 -> V_553 [ V_162 ] = V_557 ;
V_28 = F_73 ( V_107 , V_34 ,
V_64 -> V_80 [ V_162 ] -> V_31 ,
V_162 , 1 , & V_541 -> V_109 [ V_162 ] ,
& V_541 -> V_6 [ V_162 ] ) ;
if ( V_28 < 0 ) {
V_79 = V_28 ;
goto V_564;
}
F_30 ( V_541 -> V_109 [ V_162 ] == 0 ) ;
if ( V_162 == V_247 -> V_562 )
break;
F_418 ( V_64 -> V_80 [ V_162 ] ) ;
V_64 -> V_553 [ V_162 ] = 0 ;
F_8 ( V_541 -> V_109 [ V_162 ] != 1 ) ;
V_162 -- ;
}
}
V_541 -> V_162 = V_162 ;
V_541 -> V_556 = - 1 ;
V_541 -> V_546 = V_548 ;
V_541 -> V_549 = V_549 ;
V_541 -> V_169 = 0 ;
V_541 -> V_554 = V_554 ;
V_541 -> V_545 = F_410 ( V_34 ) ;
while ( 1 ) {
V_28 = F_424 ( V_107 , V_34 , V_64 , V_541 ) ;
if ( V_28 < 0 ) {
V_79 = V_28 ;
break;
}
V_28 = F_425 ( V_107 , V_34 , V_64 , V_541 , V_163 ) ;
if ( V_28 < 0 ) {
V_79 = V_28 ;
break;
}
if ( V_28 > 0 ) {
F_30 ( V_541 -> V_546 != V_548 ) ;
break;
}
if ( V_541 -> V_546 == V_548 ) {
V_162 = V_541 -> V_162 ;
F_431 ( V_64 -> V_80 [ V_162 ] ,
& V_247 -> V_561 ,
V_64 -> V_81 [ V_162 ] ) ;
V_247 -> V_562 = V_162 ;
}
F_30 ( V_541 -> V_162 == 0 ) ;
if ( F_432 ( V_107 , V_84 ) ||
( ! V_554 && F_433 ( V_34 ) ) ) {
V_28 = F_434 ( V_107 , V_84 ,
& V_34 -> V_246 ,
V_247 ) ;
if ( V_28 ) {
F_146 ( V_107 , V_84 , V_28 ) ;
V_79 = V_28 ;
goto V_564;
}
F_435 ( V_107 , V_84 ) ;
if ( ! V_554 && F_433 ( V_34 ) ) {
F_436 ( L_27 ) ;
V_79 = - V_173 ;
goto V_119;
}
V_107 = F_427 ( V_84 , 0 ) ;
if ( F_229 ( V_107 ) ) {
V_79 = F_230 ( V_107 ) ;
goto V_119;
}
if ( V_373 )
V_107 -> V_373 = V_373 ;
}
}
F_43 ( V_64 ) ;
if ( V_79 )
goto V_564;
V_28 = F_437 ( V_107 , V_84 , & V_34 -> V_246 ) ;
if ( V_28 ) {
F_146 ( V_107 , V_84 , V_28 ) ;
goto V_564;
}
if ( V_34 -> V_246 . V_21 != V_539 ) {
V_28 = F_438 ( V_84 , & V_34 -> V_246 , V_64 ,
NULL , NULL ) ;
if ( V_28 < 0 ) {
F_146 ( V_107 , V_84 , V_28 ) ;
V_79 = V_28 ;
goto V_564;
} else if ( V_28 > 0 ) {
F_439 ( V_107 , V_84 ,
V_34 -> V_246 . V_21 ) ;
}
}
if ( V_34 -> V_565 ) {
F_440 ( V_84 -> V_36 , V_34 ) ;
} else {
F_420 ( V_34 -> V_124 ) ;
F_420 ( V_34 -> V_566 ) ;
F_441 ( V_34 ) ;
}
V_560 = true ;
V_564:
F_435 ( V_107 , V_84 ) ;
V_119:
F_9 ( V_541 ) ;
F_49 ( V_64 ) ;
V_71:
if ( V_560 == false )
F_442 ( V_34 ) ;
if ( V_79 )
F_443 ( V_34 -> V_36 , V_79 ) ;
return V_79 ;
}
int F_444 ( struct V_106 * V_107 ,
struct V_33 * V_34 ,
struct V_65 * V_124 ,
struct V_65 * V_16 )
{
struct V_63 * V_64 ;
struct V_540 * V_541 ;
int V_162 ;
int V_567 ;
int V_28 = 0 ;
int V_568 ;
F_30 ( V_34 -> V_246 . V_21 != V_539 ) ;
V_64 = F_33 () ;
if ( ! V_64 )
return - V_88 ;
V_541 = F_52 ( sizeof( * V_541 ) , V_39 ) ;
if ( ! V_541 ) {
F_49 ( V_64 ) ;
return - V_88 ;
}
F_445 ( V_16 ) ;
V_567 = F_213 ( V_16 ) ;
F_446 ( V_16 ) ;
V_64 -> V_80 [ V_567 ] = V_16 ;
V_64 -> V_81 [ V_567 ] = F_38 ( V_16 ) ;
F_445 ( V_124 ) ;
V_162 = F_213 ( V_124 ) ;
V_64 -> V_80 [ V_162 ] = V_124 ;
V_64 -> V_81 [ V_162 ] = 0 ;
V_64 -> V_553 [ V_162 ] = V_557 ;
V_541 -> V_109 [ V_567 ] = 1 ;
V_541 -> V_6 [ V_567 ] = V_122 ;
V_541 -> V_162 = V_162 ;
V_541 -> V_556 = - 1 ;
V_541 -> V_546 = V_548 ;
V_541 -> V_549 = 0 ;
V_541 -> V_169 = 1 ;
V_541 -> V_554 = 1 ;
V_541 -> V_545 = F_410 ( V_34 ) ;
while ( 1 ) {
V_568 = F_424 ( V_107 , V_34 , V_64 , V_541 ) ;
if ( V_568 < 0 ) {
V_28 = V_568 ;
break;
}
V_568 = F_425 ( V_107 , V_34 , V_64 , V_541 , V_567 ) ;
if ( V_568 < 0 )
V_28 = V_568 ;
if ( V_568 != 0 )
break;
}
F_9 ( V_541 ) ;
F_49 ( V_64 ) ;
return V_28 ;
}
static T_2 F_447 ( struct V_33 * V_34 , T_2 V_6 )
{
T_2 V_317 ;
T_2 V_569 ;
V_569 = F_254 ( V_34 -> V_36 , V_6 ) ;
if ( V_569 )
return F_256 ( V_569 ) ;
V_317 = V_34 -> V_36 -> V_318 -> V_319 +
V_34 -> V_36 -> V_318 -> V_320 ;
V_569 = V_323 |
V_324 | V_325 |
V_283 | V_284 ;
if ( V_317 == 1 ) {
V_569 |= V_282 ;
V_569 = V_6 & ~ V_569 ;
if ( V_6 & V_323 )
return V_569 ;
if ( V_6 & ( V_283 |
V_284 ) )
return V_569 | V_282 ;
} else {
if ( V_6 & V_569 )
return V_6 ;
V_569 |= V_282 ;
V_569 = V_6 & ~ V_569 ;
if ( V_6 & V_282 )
return V_569 | V_283 ;
}
return V_6 ;
}
static int F_448 ( struct V_1 * V_2 , int V_342 )
{
struct V_99 * V_341 = V_2 -> V_102 ;
T_2 V_35 ;
T_2 V_570 ;
int V_28 = - V_337 ;
if ( ( V_341 -> V_6 &
( V_307 | V_305 ) ) &&
! V_342 )
V_570 = 1 * 1024 * 1024 ;
else
V_570 = 0 ;
F_11 ( & V_341 -> V_51 ) ;
F_11 ( & V_2 -> V_51 ) ;
if ( V_2 -> V_267 ) {
V_28 = 0 ;
goto V_71;
}
V_35 = V_2 -> V_20 . V_32 - V_2 -> V_9 - V_2 -> V_8 -
V_2 -> V_45 - F_340 ( & V_2 -> V_131 ) ;
if ( V_341 -> V_280 + V_341 -> V_292 + V_341 -> V_291 +
V_341 -> V_294 + V_341 -> V_293 + V_35 +
V_570 <= V_341 -> V_279 ) {
V_341 -> V_293 += V_35 ;
V_2 -> V_267 = 1 ;
V_28 = 0 ;
}
V_71:
F_13 ( & V_2 -> V_51 ) ;
F_13 ( & V_341 -> V_51 ) ;
return V_28 ;
}
int F_449 ( struct V_33 * V_34 ,
struct V_1 * V_2 )
{
struct V_106 * V_107 ;
T_2 V_571 ;
int V_28 ;
F_30 ( V_2 -> V_267 ) ;
V_107 = F_262 ( V_34 ) ;
if ( F_229 ( V_107 ) )
return F_230 ( V_107 ) ;
V_571 = F_447 ( V_34 , V_2 -> V_6 ) ;
if ( V_571 != V_2 -> V_6 ) {
V_28 = F_263 ( V_107 , V_34 , V_571 ,
V_336 ) ;
if ( V_28 < 0 )
goto V_71;
}
V_28 = F_448 ( V_2 , 0 ) ;
if ( ! V_28 )
goto V_71;
V_571 = F_257 ( V_34 , V_2 -> V_102 -> V_6 ) ;
V_28 = F_263 ( V_107 , V_34 , V_571 ,
V_336 ) ;
if ( V_28 < 0 )
goto V_71;
V_28 = F_448 ( V_2 , 0 ) ;
V_71:
F_264 ( V_107 , V_34 ) ;
return V_28 ;
}
int F_450 ( struct V_106 * V_107 ,
struct V_33 * V_34 , T_2 type )
{
T_2 V_571 = F_257 ( V_34 , type ) ;
return F_263 ( V_107 , V_34 , V_571 ,
V_336 ) ;
}
static T_2 F_451 ( struct V_100 * V_572 )
{
struct V_1 * V_13 ;
T_2 V_573 = 0 ;
int V_281 ;
F_374 (block_group, groups_list, list) {
F_11 ( & V_13 -> V_51 ) ;
if ( ! V_13 -> V_267 ) {
F_13 ( & V_13 -> V_51 ) ;
continue;
}
if ( V_13 -> V_6 & ( V_283 |
V_284 |
V_282 ) )
V_281 = 2 ;
else
V_281 = 1 ;
V_573 += ( V_13 -> V_20 . V_32 -
F_340 ( & V_13 -> V_131 ) ) *
V_281 ;
F_13 ( & V_13 -> V_51 ) ;
}
return V_573 ;
}
T_2 F_452 ( struct V_99 * V_341 )
{
int V_42 ;
T_2 V_573 = 0 ;
F_11 ( & V_341 -> V_51 ) ;
for( V_42 = 0 ; V_42 < V_288 ; V_42 ++ )
if ( ! F_162 ( & V_341 -> V_289 [ V_42 ] ) )
V_573 += F_451 (
& V_341 -> V_289 [ V_42 ] ) ;
F_13 ( & V_341 -> V_51 ) ;
return V_573 ;
}
void F_453 ( struct V_33 * V_34 ,
struct V_1 * V_2 )
{
struct V_99 * V_341 = V_2 -> V_102 ;
T_2 V_35 ;
F_30 ( ! V_2 -> V_267 ) ;
F_11 ( & V_341 -> V_51 ) ;
F_11 ( & V_2 -> V_51 ) ;
V_35 = V_2 -> V_20 . V_32 - V_2 -> V_9 - V_2 -> V_8 -
V_2 -> V_45 - F_340 ( & V_2 -> V_131 ) ;
V_341 -> V_293 -= V_35 ;
V_2 -> V_267 = 0 ;
F_13 ( & V_2 -> V_51 ) ;
F_13 ( & V_341 -> V_51 ) ;
}
int F_454 ( struct V_33 * V_34 , T_2 V_26 )
{
struct V_1 * V_13 ;
struct V_99 * V_102 ;
struct V_574 * V_318 = V_34 -> V_36 -> V_318 ;
struct V_575 * V_576 ;
struct V_106 * V_107 ;
T_2 V_577 ;
T_2 V_578 = 1 ;
T_2 V_579 = 0 ;
T_2 V_312 ;
int V_494 ;
int V_105 = 0 ;
int V_28 = 0 ;
V_13 = F_66 ( V_34 -> V_36 , V_26 ) ;
if ( ! V_13 )
return - 1 ;
V_577 = F_340 ( & V_13 -> V_131 ) ;
if ( ! V_577 )
goto V_71;
V_102 = V_13 -> V_102 ;
F_11 ( & V_102 -> V_51 ) ;
V_105 = V_102 -> V_105 ;
if ( ( V_102 -> V_279 != V_13 -> V_20 . V_32 ) &&
( V_102 -> V_280 + V_102 -> V_292 +
V_102 -> V_291 + V_102 -> V_293 +
V_577 < V_102 -> V_279 ) ) {
F_13 ( & V_102 -> V_51 ) ;
goto V_71;
}
F_13 ( & V_102 -> V_51 ) ;
V_28 = - 1 ;
V_312 = F_254 ( V_34 -> V_36 , V_13 -> V_6 ) ;
if ( V_312 ) {
V_494 = F_368 ( F_256 ( V_312 ) ) ;
} else {
if ( V_105 )
goto V_71;
V_494 = F_369 ( V_13 ) ;
}
if ( V_494 == V_479 ) {
V_578 = 4 ;
V_577 >>= 1 ;
} else if ( V_494 == V_480 ) {
V_578 = 2 ;
} else if ( V_494 == V_481 ) {
V_577 <<= 1 ;
} else if ( V_494 == V_482 ) {
V_578 = V_318 -> V_319 ;
F_455 ( V_577 , V_578 ) ;
}
V_107 = F_262 ( V_34 ) ;
if ( F_229 ( V_107 ) ) {
V_28 = F_230 ( V_107 ) ;
goto V_71;
}
F_35 ( & V_34 -> V_36 -> V_352 ) ;
F_374 (device, &fs_devices->alloc_list, dev_alloc_list) {
T_2 V_580 ;
if ( V_576 -> V_279 > V_576 -> V_280 + V_577 &&
! V_576 -> V_581 ) {
V_28 = F_456 ( V_107 , V_576 , V_577 ,
& V_580 , NULL ) ;
if ( ! V_28 )
V_579 ++ ;
if ( V_579 >= V_578 )
break;
V_28 = - 1 ;
}
}
F_45 ( & V_34 -> V_36 -> V_352 ) ;
F_264 ( V_107 , V_34 ) ;
V_71:
F_6 ( V_13 ) ;
return V_28 ;
}
static int F_457 ( struct V_33 * V_34 ,
struct V_63 * V_64 , struct V_67 * V_20 )
{
int V_28 = 0 ;
struct V_67 V_136 ;
struct V_65 * V_66 ;
int V_542 ;
V_28 = F_37 ( NULL , V_34 , V_20 , V_64 , 0 , 0 ) ;
if ( V_28 < 0 )
goto V_71;
while ( 1 ) {
V_542 = V_64 -> V_81 [ 0 ] ;
V_66 = V_64 -> V_80 [ 0 ] ;
if ( V_542 >= F_38 ( V_66 ) ) {
V_28 = F_47 ( V_34 , V_64 ) ;
if ( V_28 == 0 )
continue;
if ( V_28 < 0 )
goto V_71;
break;
}
F_40 ( V_66 , & V_136 , V_542 ) ;
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
void F_458 ( struct V_11 * V_12 )
{
struct V_1 * V_13 ;
T_2 V_69 = 0 ;
while ( 1 ) {
struct V_259 * V_259 ;
V_13 = F_65 ( V_12 , V_69 ) ;
while ( V_13 ) {
F_11 ( & V_13 -> V_51 ) ;
if ( V_13 -> V_159 )
break;
F_13 ( & V_13 -> V_51 ) ;
V_13 = F_226 ( V_12 -> V_84 ,
V_13 ) ;
}
if ( ! V_13 ) {
if ( V_69 == 0 )
break;
V_69 = 0 ;
continue;
}
V_259 = V_13 -> V_259 ;
V_13 -> V_159 = 0 ;
V_13 -> V_259 = NULL ;
F_13 ( & V_13 -> V_51 ) ;
F_241 ( V_259 ) ;
V_69 = V_13 -> V_20 . V_21 + V_13 -> V_20 . V_32 ;
F_6 ( V_13 ) ;
}
}
int F_459 ( struct V_11 * V_12 )
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
F_61 ( & V_13 -> V_102 -> V_290 ) ;
F_179 ( & V_13 -> V_89 ) ;
F_63 ( & V_13 -> V_102 -> V_290 ) ;
if ( V_13 -> V_3 == V_52 )
F_367 ( V_13 ) ;
if ( V_13 -> V_3 == V_93 )
F_19 ( V_12 -> V_62 , V_13 ) ;
F_460 ( V_13 ) ;
F_6 ( V_13 ) ;
F_11 ( & V_12 -> V_17 ) ;
}
F_13 ( & V_12 -> V_17 ) ;
F_461 () ;
F_317 ( V_12 ) ;
while( ! F_162 ( & V_12 -> V_102 ) ) {
V_102 = F_163 ( V_12 -> V_102 . V_213 ,
struct V_99 ,
V_89 ) ;
if ( F_237 ( V_12 -> V_84 , V_349 ) ) {
if ( V_102 -> V_291 > 0 ||
V_102 -> V_292 > 0 ||
V_102 -> V_294 > 0 ) {
F_8 ( 1 ) ;
F_277 ( V_102 , 0 , 0 ) ;
}
}
F_462 ( & V_102 -> V_287 ) ;
F_179 ( & V_102 -> V_89 ) ;
F_9 ( V_102 ) ;
}
return 0 ;
}
static void F_463 ( struct V_99 * V_102 ,
struct V_1 * V_2 )
{
int V_494 = F_369 ( V_2 ) ;
F_61 ( & V_102 -> V_290 ) ;
F_62 ( & V_2 -> V_89 , & V_102 -> V_289 [ V_494 ] ) ;
F_63 ( & V_102 -> V_290 ) ;
}
int F_464 ( struct V_33 * V_34 )
{
struct V_63 * V_64 ;
int V_28 ;
struct V_1 * V_2 ;
struct V_11 * V_12 = V_34 -> V_36 ;
struct V_99 * V_102 ;
struct V_67 V_20 ;
struct V_67 V_136 ;
struct V_65 * V_66 ;
int V_582 = 0 ;
T_2 V_583 ;
V_34 = V_12 -> V_62 ;
V_20 . V_21 = 0 ;
V_20 . V_32 = 0 ;
F_371 ( & V_20 , V_174 ) ;
V_64 = F_33 () ;
if ( ! V_64 )
return - V_88 ;
V_64 -> V_74 = 1 ;
V_583 = F_465 ( V_34 -> V_36 -> V_346 ) ;
if ( F_237 ( V_34 , V_273 ) &&
F_466 ( V_34 -> V_36 -> V_346 ) != V_583 )
V_582 = 1 ;
if ( F_237 ( V_34 , V_584 ) )
V_582 = 1 ;
while ( 1 ) {
V_28 = F_457 ( V_34 , V_64 , & V_20 ) ;
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
F_248 ( & V_2 -> V_51 ) ;
V_2 -> V_36 = V_12 ;
F_53 ( & V_2 -> V_89 ) ;
F_53 ( & V_2 -> V_585 ) ;
if ( V_582 ) {
V_2 -> V_265 = V_275 ;
if ( F_237 ( V_34 , V_273 ) )
V_2 -> V_276 = 1 ;
}
F_467 ( V_66 , & V_2 -> V_131 ,
F_224 ( V_66 , V_64 -> V_81 [ 0 ] ) ,
sizeof( V_2 -> V_131 ) ) ;
memcpy ( & V_2 -> V_20 , & V_136 , sizeof( V_136 ) ) ;
V_20 . V_21 = V_136 . V_21 + V_136 . V_32 ;
F_43 ( V_64 ) ;
V_2 -> V_6 = F_468 ( & V_2 -> V_131 ) ;
V_2 -> V_331 = V_34 -> V_331 ;
V_2 -> V_586 = F_469 ( V_34 ,
& V_34 -> V_36 -> V_47 ,
V_136 . V_21 ) ;
F_470 ( V_2 ) ;
V_28 = F_21 ( V_34 , V_2 ) ;
if ( V_28 ) {
F_19 ( V_34 , V_2 ) ;
F_9 ( V_2 -> V_10 ) ;
F_9 ( V_2 ) ;
goto error;
}
if ( V_136 . V_32 == F_340 ( & V_2 -> V_131 ) ) {
V_2 -> V_96 = ( T_2 ) - 1 ;
V_2 -> V_3 = V_4 ;
F_19 ( V_34 , V_2 ) ;
} else if ( F_340 ( & V_2 -> V_131 ) == 0 ) {
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
F_460 ( V_2 ) ;
F_6 ( V_2 ) ;
goto error;
}
V_28 = F_245 ( V_12 , V_2 -> V_6 , V_136 . V_32 ,
F_340 ( & V_2 -> V_131 ) ,
& V_102 ) ;
if ( V_28 ) {
F_460 ( V_2 ) ;
F_11 ( & V_12 -> V_17 ) ;
F_172 ( & V_2 -> V_19 ,
& V_12 -> V_18 ) ;
F_13 ( & V_12 -> V_17 ) ;
F_6 ( V_2 ) ;
goto error;
}
V_2 -> V_102 = V_102 ;
F_11 ( & V_2 -> V_102 -> V_51 ) ;
V_2 -> V_102 -> V_293 += V_2 -> V_45 ;
F_13 ( & V_2 -> V_102 -> V_51 ) ;
F_463 ( V_102 , V_2 ) ;
F_250 ( V_34 -> V_36 , V_2 -> V_6 ) ;
if ( F_471 ( V_34 , V_2 -> V_20 . V_21 ) )
F_448 ( V_2 , 1 ) ;
}
F_69 (space_info, &root->fs_info->space_info, list) {
if ( ! ( F_257 ( V_34 , V_102 -> V_6 ) &
( V_284 |
V_283 |
V_324 |
V_325 |
V_282 ) ) )
continue;
F_374 (cache, &space_info->block_groups[3], list)
F_448 ( V_2 , 1 ) ;
F_374 (cache, &space_info->block_groups[4], list)
F_448 ( V_2 , 1 ) ;
}
F_316 ( V_12 ) ;
V_28 = 0 ;
error:
F_49 ( V_64 ) ;
return V_28 ;
}
void F_196 ( struct V_106 * V_107 ,
struct V_33 * V_34 )
{
struct V_1 * V_13 , * V_321 ;
struct V_33 * V_62 = V_34 -> V_36 -> V_62 ;
struct V_587 V_131 ;
struct V_67 V_20 ;
int V_28 = 0 ;
F_350 (block_group, tmp, &trans->new_bgs,
new_bg_list) {
F_168 ( & V_13 -> V_588 ) ;
if ( V_28 )
continue;
F_11 ( & V_13 -> V_51 ) ;
memcpy ( & V_131 , & V_13 -> V_131 , sizeof( V_131 ) ) ;
memcpy ( & V_20 , & V_13 -> V_20 , sizeof( V_20 ) ) ;
F_13 ( & V_13 -> V_51 ) ;
V_28 = F_472 ( V_107 , V_62 , & V_20 , & V_131 ,
sizeof( V_131 ) ) ;
if ( V_28 )
F_146 ( V_107 , V_62 , V_28 ) ;
V_28 = F_473 ( V_107 , V_62 ,
V_20 . V_21 , V_20 . V_32 ) ;
if ( V_28 )
F_146 ( V_107 , V_62 , V_28 ) ;
}
}
int F_474 ( struct V_106 * V_107 ,
struct V_33 * V_34 , T_2 V_280 ,
T_2 type , T_2 V_589 , T_2 V_590 ,
T_2 V_56 )
{
int V_28 ;
struct V_33 * V_62 ;
struct V_1 * V_2 ;
V_62 = V_34 -> V_36 -> V_62 ;
V_34 -> V_36 -> V_591 = V_107 -> V_269 ;
V_2 = F_52 ( sizeof( * V_2 ) , V_39 ) ;
if ( ! V_2 )
return - V_88 ;
V_2 -> V_10 = F_52 ( sizeof( * V_2 -> V_10 ) ,
V_39 ) ;
if ( ! V_2 -> V_10 ) {
F_9 ( V_2 ) ;
return - V_88 ;
}
V_2 -> V_20 . V_21 = V_590 ;
V_2 -> V_20 . V_32 = V_56 ;
V_2 -> V_20 . type = V_174 ;
V_2 -> V_331 = V_34 -> V_331 ;
V_2 -> V_36 = V_34 -> V_36 ;
V_2 -> V_586 = F_469 ( V_34 ,
& V_34 -> V_36 -> V_47 ,
V_590 ) ;
F_56 ( & V_2 -> V_7 , 1 ) ;
F_248 ( & V_2 -> V_51 ) ;
F_53 ( & V_2 -> V_89 ) ;
F_53 ( & V_2 -> V_585 ) ;
F_53 ( & V_2 -> V_588 ) ;
F_470 ( V_2 ) ;
F_341 ( & V_2 -> V_131 , V_280 ) ;
F_475 ( & V_2 -> V_131 , V_589 ) ;
V_2 -> V_6 = type ;
F_476 ( & V_2 -> V_131 , type ) ;
V_2 -> V_96 = ( T_2 ) - 1 ;
V_2 -> V_3 = V_4 ;
V_28 = F_21 ( V_34 , V_2 ) ;
if ( V_28 ) {
F_19 ( V_34 , V_2 ) ;
F_9 ( V_2 -> V_10 ) ;
F_9 ( V_2 ) ;
return V_28 ;
}
F_27 ( V_2 , V_34 -> V_36 , V_590 ,
V_590 + V_56 ) ;
F_19 ( V_34 , V_2 ) ;
V_28 = F_10 ( V_34 -> V_36 , V_2 ) ;
if ( V_28 ) {
F_460 ( V_2 ) ;
F_6 ( V_2 ) ;
return V_28 ;
}
V_28 = F_245 ( V_34 -> V_36 , V_2 -> V_6 , V_56 , V_280 ,
& V_2 -> V_102 ) ;
if ( V_28 ) {
F_460 ( V_2 ) ;
F_11 ( & V_34 -> V_36 -> V_17 ) ;
F_172 ( & V_2 -> V_19 ,
& V_34 -> V_36 -> V_18 ) ;
F_13 ( & V_34 -> V_36 -> V_17 ) ;
F_6 ( V_2 ) ;
return V_28 ;
}
F_315 ( V_34 -> V_36 ) ;
F_11 ( & V_2 -> V_102 -> V_51 ) ;
V_2 -> V_102 -> V_293 += V_2 -> V_45 ;
F_13 ( & V_2 -> V_102 -> V_51 ) ;
F_463 ( V_2 -> V_102 , V_2 ) ;
F_62 ( & V_2 -> V_588 , & V_107 -> V_243 ) ;
F_250 ( V_62 -> V_36 , type ) ;
return 0 ;
}
static void F_477 ( struct V_11 * V_36 , T_2 V_6 )
{
T_2 V_301 = F_251 ( V_6 ) &
V_302 ;
F_252 ( & V_36 -> V_303 ) ;
if ( V_6 & V_299 )
V_36 -> V_304 &= ~ V_301 ;
if ( V_6 & V_305 )
V_36 -> V_306 &= ~ V_301 ;
if ( V_6 & V_307 )
V_36 -> V_308 &= ~ V_301 ;
F_253 ( & V_36 -> V_303 ) ;
}
int F_478 ( struct V_106 * V_107 ,
struct V_33 * V_34 , T_2 V_592 )
{
struct V_63 * V_64 ;
struct V_1 * V_13 ;
struct V_489 * V_210 ;
struct V_33 * V_84 = V_34 -> V_36 -> V_84 ;
struct V_67 V_20 ;
struct V_259 * V_259 ;
int V_28 ;
int V_494 ;
int V_281 ;
V_34 = V_34 -> V_36 -> V_62 ;
V_13 = F_66 ( V_34 -> V_36 , V_592 ) ;
F_30 ( ! V_13 ) ;
F_30 ( ! V_13 -> V_267 ) ;
F_19 ( V_34 , V_13 ) ;
memcpy ( & V_20 , & V_13 -> V_20 , sizeof( V_20 ) ) ;
V_494 = F_369 ( V_13 ) ;
if ( V_13 -> V_6 & ( V_282 |
V_283 |
V_284 ) )
V_281 = 2 ;
else
V_281 = 1 ;
V_210 = & V_34 -> V_36 -> V_504 ;
F_11 ( & V_210 -> V_510 ) ;
F_377 ( V_13 , V_210 ) ;
F_13 ( & V_210 -> V_510 ) ;
V_210 = & V_34 -> V_36 -> V_502 ;
F_11 ( & V_210 -> V_510 ) ;
F_377 ( V_13 , V_210 ) ;
F_13 ( & V_210 -> V_510 ) ;
V_64 = F_33 () ;
if ( ! V_64 ) {
V_28 = - V_88 ;
goto V_71;
}
V_259 = F_228 ( V_84 , V_13 , V_64 ) ;
if ( ! F_229 ( V_259 ) ) {
V_28 = F_479 ( V_107 , V_259 ) ;
if ( V_28 ) {
F_480 ( V_259 ) ;
goto V_71;
}
F_481 ( V_259 ) ;
F_11 ( & V_13 -> V_51 ) ;
if ( V_13 -> V_159 ) {
V_13 -> V_159 = 0 ;
V_13 -> V_259 = NULL ;
F_13 ( & V_13 -> V_51 ) ;
F_241 ( V_259 ) ;
} else {
F_13 ( & V_13 -> V_51 ) ;
}
F_480 ( V_259 ) ;
}
V_20 . V_21 = V_593 ;
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
F_61 ( & V_13 -> V_102 -> V_290 ) ;
F_168 ( & V_13 -> V_89 ) ;
if ( F_162 ( & V_13 -> V_102 -> V_289 [ V_494 ] ) )
F_477 ( V_34 -> V_36 , V_13 -> V_6 ) ;
F_63 ( & V_13 -> V_102 -> V_290 ) ;
if ( V_13 -> V_3 == V_52 )
F_367 ( V_13 ) ;
F_460 ( V_13 ) ;
F_11 ( & V_13 -> V_102 -> V_51 ) ;
V_13 -> V_102 -> V_279 -= V_13 -> V_20 . V_32 ;
V_13 -> V_102 -> V_293 -= V_13 -> V_20 . V_32 ;
V_13 -> V_102 -> V_285 -= V_13 -> V_20 . V_32 * V_281 ;
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
int F_482 ( struct V_11 * V_36 )
{
struct V_99 * V_102 ;
struct V_594 * V_595 ;
T_2 V_596 ;
T_2 V_6 ;
int V_597 = 0 ;
int V_28 ;
V_595 = V_36 -> V_346 ;
if ( ! F_483 ( V_595 ) )
return 1 ;
V_596 = F_484 ( V_595 ) ;
if ( V_596 & V_598 )
V_597 = 1 ;
V_6 = V_307 ;
V_28 = F_245 ( V_36 , V_6 , 0 , 0 , & V_102 ) ;
if ( V_28 )
goto V_71;
if ( V_597 ) {
V_6 = V_305 | V_299 ;
V_28 = F_245 ( V_36 , V_6 , 0 , 0 , & V_102 ) ;
} else {
V_6 = V_305 ;
V_28 = F_245 ( V_36 , V_6 , 0 , 0 , & V_102 ) ;
if ( V_28 )
goto V_71;
V_6 = V_299 ;
V_28 = F_245 ( V_36 , V_6 , 0 , 0 , & V_102 ) ;
}
V_71:
return V_28 ;
}
int F_485 ( struct V_33 * V_34 , T_2 V_31 , T_2 V_30 )
{
return F_352 ( V_34 , V_31 , V_30 ) ;
}
int F_486 ( struct V_33 * V_34 , T_2 V_26 ,
T_2 V_35 , T_2 * V_182 )
{
return F_140 ( V_34 , V_26 , V_35 , V_182 ) ;
}
int F_487 ( struct V_33 * V_34 , struct V_599 * V_600 )
{
struct V_11 * V_36 = V_34 -> V_36 ;
struct V_1 * V_2 = NULL ;
T_2 V_601 ;
T_2 V_31 ;
T_2 V_30 ;
T_2 V_602 = 0 ;
T_2 V_279 = F_271 ( V_36 -> V_346 ) ;
int V_28 = 0 ;
if ( V_600 -> V_48 == V_279 )
V_2 = F_65 ( V_36 , V_600 -> V_31 ) ;
else
V_2 = F_66 ( V_36 , V_600 -> V_31 ) ;
while ( V_2 ) {
if ( V_2 -> V_20 . V_21 >= ( V_600 -> V_31 + V_600 -> V_48 ) ) {
F_6 ( V_2 ) ;
break;
}
V_31 = F_373 ( V_600 -> V_31 , V_2 -> V_20 . V_21 ) ;
V_30 = F_281 ( V_600 -> V_31 + V_600 -> V_48 ,
V_2 -> V_20 . V_21 + V_2 -> V_20 . V_32 ) ;
if ( V_30 - V_31 >= V_600 -> V_603 ) {
if ( ! F_1 ( V_2 ) ) {
V_28 = F_50 ( V_2 , 0 ) ;
if ( V_28 ) {
F_6 ( V_2 ) ;
break;
}
V_28 = F_367 ( V_2 ) ;
if ( V_28 ) {
F_6 ( V_2 ) ;
break;
}
}
V_28 = F_488 ( V_2 ,
& V_601 ,
V_31 ,
V_30 ,
V_600 -> V_603 ) ;
V_602 += V_601 ;
if ( V_28 ) {
F_6 ( V_2 ) ;
break;
}
}
V_2 = F_226 ( V_36 -> V_84 , V_2 ) ;
}
V_600 -> V_48 = V_602 ;
return V_28 ;
}
