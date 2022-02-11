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
void F_4 ( struct V_1 * V_2 )
{
F_5 ( & V_2 -> V_8 ) ;
}
void F_6 ( struct V_1 * V_2 )
{
if ( F_7 ( & V_2 -> V_8 ) ) {
F_8 ( V_2 -> V_9 > 0 ) ;
F_8 ( V_2 -> V_10 > 0 ) ;
F_8 ( ! F_9 ( & V_2 -> V_11 . V_12 ) ) ;
F_10 ( V_2 -> V_13 ) ;
F_10 ( V_2 ) ;
}
}
static int F_11 ( struct V_14 * V_15 ,
struct V_1 * V_16 )
{
struct V_17 * * V_18 ;
struct V_17 * V_19 = NULL ;
struct V_1 * V_2 ;
F_12 ( & V_15 -> V_20 ) ;
V_18 = & V_15 -> V_21 . V_17 ;
while ( * V_18 ) {
V_19 = * V_18 ;
V_2 = F_13 ( V_19 , struct V_1 ,
V_22 ) ;
if ( V_16 -> V_23 . V_24 < V_2 -> V_23 . V_24 ) {
V_18 = & ( * V_18 ) -> V_25 ;
} else if ( V_16 -> V_23 . V_24 > V_2 -> V_23 . V_24 ) {
V_18 = & ( * V_18 ) -> V_26 ;
} else {
F_14 ( & V_15 -> V_20 ) ;
return - V_27 ;
}
}
F_15 ( & V_16 -> V_22 , V_19 , V_18 ) ;
F_16 ( & V_16 -> V_22 ,
& V_15 -> V_21 ) ;
if ( V_15 -> V_28 > V_16 -> V_23 . V_24 )
V_15 -> V_28 = V_16 -> V_23 . V_24 ;
F_14 ( & V_15 -> V_20 ) ;
return 0 ;
}
static struct V_1 *
F_17 ( struct V_14 * V_15 , T_2 V_29 ,
int V_30 )
{
struct V_1 * V_2 , * V_31 = NULL ;
struct V_17 * V_32 ;
T_2 V_33 , V_34 ;
F_12 ( & V_15 -> V_20 ) ;
V_32 = V_15 -> V_21 . V_17 ;
while ( V_32 ) {
V_2 = F_13 ( V_32 , struct V_1 ,
V_22 ) ;
V_33 = V_2 -> V_23 . V_24 + V_2 -> V_23 . V_35 - 1 ;
V_34 = V_2 -> V_23 . V_24 ;
if ( V_29 < V_34 ) {
if ( ! V_30 && ( ! V_31 || V_34 < V_31 -> V_23 . V_24 ) )
V_31 = V_2 ;
V_32 = V_32 -> V_25 ;
} else if ( V_29 > V_34 ) {
if ( V_30 && V_29 <= V_33 ) {
V_31 = V_2 ;
break;
}
V_32 = V_32 -> V_26 ;
} else {
V_31 = V_2 ;
break;
}
}
if ( V_31 ) {
F_4 ( V_31 ) ;
if ( V_29 == 0 && V_15 -> V_28 > V_31 -> V_23 . V_24 )
V_15 -> V_28 = V_31 -> V_23 . V_24 ;
}
F_14 ( & V_15 -> V_20 ) ;
return V_31 ;
}
static int F_18 ( struct V_14 * V_36 ,
T_2 V_34 , T_2 V_37 )
{
T_2 V_33 = V_34 + V_37 - 1 ;
F_19 ( & V_36 -> V_38 [ 0 ] ,
V_34 , V_33 , V_39 ) ;
F_19 ( & V_36 -> V_38 [ 1 ] ,
V_34 , V_33 , V_39 ) ;
return 0 ;
}
static void F_20 ( struct V_14 * V_36 ,
struct V_1 * V_2 )
{
T_2 V_34 , V_33 ;
V_34 = V_2 -> V_23 . V_24 ;
V_33 = V_34 + V_2 -> V_23 . V_35 - 1 ;
F_21 ( & V_36 -> V_38 [ 0 ] ,
V_34 , V_33 , V_39 ) ;
F_21 ( & V_36 -> V_38 [ 1 ] ,
V_34 , V_33 , V_39 ) ;
}
static int F_22 ( struct V_14 * V_36 ,
struct V_1 * V_2 )
{
T_2 V_29 ;
T_2 * V_40 ;
int V_41 ;
int V_42 , V_43 , V_31 ;
if ( V_2 -> V_23 . V_24 < V_44 ) {
V_41 = V_44 - V_2 -> V_23 . V_24 ;
V_2 -> V_45 += V_41 ;
V_31 = F_18 ( V_36 , V_2 -> V_23 . V_24 ,
V_41 ) ;
if ( V_31 )
return V_31 ;
}
for ( V_42 = 0 ; V_42 < V_46 ; V_42 ++ ) {
V_29 = F_23 ( V_42 ) ;
V_31 = F_24 ( V_36 , V_2 -> V_23 . V_24 ,
V_29 , 0 , & V_40 , & V_43 , & V_41 ) ;
if ( V_31 )
return V_31 ;
while ( V_43 -- ) {
T_2 V_34 , V_47 ;
if ( V_40 [ V_43 ] > V_2 -> V_23 . V_24 +
V_2 -> V_23 . V_35 )
continue;
if ( V_40 [ V_43 ] + V_41 <= V_2 -> V_23 . V_24 )
continue;
V_34 = V_40 [ V_43 ] ;
if ( V_34 < V_2 -> V_23 . V_24 ) {
V_34 = V_2 -> V_23 . V_24 ;
V_47 = ( V_40 [ V_43 ] + V_41 ) - V_34 ;
} else {
V_47 = F_25 ( T_2 , V_41 ,
V_2 -> V_23 . V_24 +
V_2 -> V_23 . V_35 - V_34 ) ;
}
V_2 -> V_45 += V_47 ;
V_31 = F_18 ( V_36 , V_34 , V_47 ) ;
if ( V_31 ) {
F_10 ( V_40 ) ;
return V_31 ;
}
}
F_10 ( V_40 ) ;
}
return 0 ;
}
static struct V_48 *
F_26 ( struct V_1 * V_2 )
{
struct V_48 * V_49 ;
F_12 ( & V_2 -> V_50 ) ;
if ( ! V_2 -> V_51 ) {
F_14 ( & V_2 -> V_50 ) ;
return NULL ;
}
V_49 = V_2 -> V_51 ;
F_27 ( & V_49 -> V_8 ) ;
F_14 ( & V_2 -> V_50 ) ;
return V_49 ;
}
static void F_28 ( struct V_48 * V_49 )
{
if ( F_29 ( & V_49 -> V_8 ) )
F_10 ( V_49 ) ;
}
static void F_30 ( struct V_1 * V_16 )
{
struct V_14 * V_36 = V_16 -> V_36 ;
T_2 V_34 = V_16 -> V_23 . V_24 ;
T_2 V_47 = V_16 -> V_23 . V_35 ;
T_2 V_52 = V_16 -> V_7 & V_53 ?
V_36 -> V_54 : V_36 -> V_55 ;
T_2 V_56 = V_52 << 1 ;
while ( V_47 > V_52 ) {
F_31 ( V_16 , V_34 , V_52 ) ;
V_34 += V_56 ;
if ( V_47 < V_56 )
V_47 = 0 ;
else
V_47 -= V_56 ;
}
}
T_2 F_32 ( struct V_1 * V_16 ,
struct V_14 * V_15 , T_2 V_34 , T_2 V_33 )
{
T_2 V_57 , V_58 , V_59 , V_60 = 0 ;
int V_31 ;
while ( V_34 < V_33 ) {
V_31 = F_33 ( V_15 -> V_61 , V_34 ,
& V_57 , & V_58 ,
V_62 | V_39 ,
NULL ) ;
if ( V_31 )
break;
if ( V_57 <= V_34 ) {
V_34 = V_58 + 1 ;
} else if ( V_57 > V_34 && V_57 < V_33 ) {
V_59 = V_57 - V_34 ;
V_60 += V_59 ;
V_31 = F_34 ( V_16 , V_34 ,
V_59 ) ;
F_35 ( V_31 ) ;
V_34 = V_58 + 1 ;
} else {
break;
}
}
if ( V_34 < V_33 ) {
V_59 = V_33 - V_34 ;
V_60 += V_59 ;
V_31 = F_34 ( V_16 , V_34 , V_59 ) ;
F_35 ( V_31 ) ;
}
return V_60 ;
}
static int F_36 ( struct V_48 * V_51 )
{
struct V_1 * V_16 = V_51 -> V_16 ;
struct V_14 * V_36 = V_16 -> V_36 ;
struct V_63 * V_64 = V_36 -> V_64 ;
struct V_65 * V_66 ;
struct V_67 * V_68 ;
struct V_69 V_23 ;
T_2 V_70 = 0 ;
T_2 V_71 = 0 ;
T_3 V_72 ;
int V_31 ;
bool V_73 = true ;
V_66 = F_37 () ;
if ( ! V_66 )
return - V_74 ;
V_71 = F_38 ( T_2 , V_16 -> V_23 . V_24 , V_44 ) ;
#ifdef F_39
if ( F_40 ( V_16 ) )
V_73 = false ;
#endif
V_66 -> V_75 = 1 ;
V_66 -> V_76 = 1 ;
V_66 -> V_77 = V_78 ;
V_23 . V_24 = V_71 ;
V_23 . V_35 = 0 ;
V_23 . type = V_79 ;
V_80:
V_31 = F_41 ( NULL , V_64 , & V_23 , V_66 , 0 , 0 ) ;
if ( V_31 < 0 )
goto V_81;
V_68 = V_66 -> V_82 [ 0 ] ;
V_72 = F_42 ( V_68 ) ;
while ( 1 ) {
if ( F_43 ( V_36 ) > 1 ) {
V_71 = ( T_2 ) - 1 ;
break;
}
if ( V_66 -> V_83 [ 0 ] < V_72 ) {
F_44 ( V_68 , & V_23 , V_66 -> V_83 [ 0 ] ) ;
} else {
V_31 = F_45 ( V_66 , 0 , & V_23 ) ;
if ( V_31 )
break;
if ( F_46 () ||
F_47 ( & V_36 -> V_84 ) ) {
if ( V_73 )
V_51 -> V_85 = V_71 ;
F_48 ( V_66 ) ;
F_49 ( & V_36 -> V_84 ) ;
F_50 ( & V_51 -> V_86 ) ;
F_51 () ;
F_52 ( & V_51 -> V_86 ) ;
F_53 ( & V_36 -> V_84 ) ;
goto V_80;
}
V_31 = F_54 ( V_64 , V_66 ) ;
if ( V_31 < 0 )
goto V_81;
if ( V_31 )
break;
V_68 = V_66 -> V_82 [ 0 ] ;
V_72 = F_42 ( V_68 ) ;
continue;
}
if ( V_23 . V_24 < V_71 ) {
V_23 . V_24 = V_71 ;
V_23 . V_35 = 0 ;
V_23 . type = V_79 ;
if ( V_73 )
V_51 -> V_85 = V_71 ;
F_48 ( V_66 ) ;
goto V_80;
}
if ( V_23 . V_24 < V_16 -> V_23 . V_24 ) {
V_66 -> V_83 [ 0 ] ++ ;
continue;
}
if ( V_23 . V_24 >= V_16 -> V_23 . V_24 +
V_16 -> V_23 . V_35 )
break;
if ( V_23 . type == V_79 ||
V_23 . type == V_87 ) {
V_70 += F_32 ( V_16 ,
V_36 , V_71 ,
V_23 . V_24 ) ;
if ( V_23 . type == V_87 )
V_71 = V_23 . V_24 +
V_36 -> V_54 ;
else
V_71 = V_23 . V_24 + V_23 . V_35 ;
if ( V_70 > V_88 ) {
V_70 = 0 ;
if ( V_73 )
F_55 ( & V_51 -> V_89 ) ;
}
}
V_66 -> V_83 [ 0 ] ++ ;
}
V_31 = 0 ;
V_70 += F_32 ( V_16 , V_36 , V_71 ,
V_16 -> V_23 . V_24 +
V_16 -> V_23 . V_35 ) ;
V_51 -> V_85 = ( T_2 ) - 1 ;
V_81:
F_56 ( V_66 ) ;
return V_31 ;
}
static T_1 void F_57 ( struct V_90 * V_91 )
{
struct V_1 * V_16 ;
struct V_14 * V_36 ;
struct V_48 * V_51 ;
struct V_63 * V_64 ;
int V_31 ;
V_51 = F_58 ( V_91 , struct V_48 , V_91 ) ;
V_16 = V_51 -> V_16 ;
V_36 = V_16 -> V_36 ;
V_64 = V_36 -> V_64 ;
F_52 ( & V_51 -> V_86 ) ;
F_53 ( & V_36 -> V_84 ) ;
if ( F_59 ( V_36 , V_92 ) )
V_31 = F_60 ( V_51 ) ;
else
V_31 = F_36 ( V_51 ) ;
F_12 ( & V_16 -> V_50 ) ;
V_16 -> V_51 = NULL ;
V_16 -> V_3 = V_31 ? V_5 : V_4 ;
F_14 ( & V_16 -> V_50 ) ;
#ifdef F_39
if ( F_40 ( V_16 ) ) {
T_2 V_93 ;
F_12 ( & V_16 -> V_94 -> V_50 ) ;
F_12 ( & V_16 -> V_50 ) ;
V_93 = V_16 -> V_23 . V_35 -
F_61 ( & V_16 -> V_95 ) ;
V_16 -> V_94 -> V_93 += V_93 >> 1 ;
F_14 ( & V_16 -> V_50 ) ;
F_14 ( & V_16 -> V_94 -> V_50 ) ;
F_30 ( V_16 ) ;
}
#endif
V_51 -> V_85 = ( T_2 ) - 1 ;
F_49 ( & V_36 -> V_84 ) ;
F_20 ( V_36 , V_16 ) ;
F_50 ( & V_51 -> V_86 ) ;
F_55 ( & V_51 -> V_89 ) ;
F_28 ( V_51 ) ;
F_6 ( V_16 ) ;
}
static int F_62 ( struct V_1 * V_2 ,
int V_96 )
{
F_63 ( V_89 ) ;
struct V_14 * V_36 = V_2 -> V_36 ;
struct V_48 * V_51 ;
int V_31 = 0 ;
V_51 = F_64 ( sizeof( * V_51 ) , V_97 ) ;
if ( ! V_51 )
return - V_74 ;
F_65 ( & V_51 -> V_98 ) ;
F_66 ( & V_51 -> V_86 ) ;
F_67 ( & V_51 -> V_89 ) ;
V_51 -> V_16 = V_2 ;
V_51 -> V_85 = V_2 -> V_23 . V_24 ;
F_68 ( & V_51 -> V_8 , 1 ) ;
F_69 ( & V_51 -> V_91 , V_99 ,
F_57 , NULL , NULL ) ;
F_12 ( & V_2 -> V_50 ) ;
while ( V_2 -> V_3 == V_100 ) {
struct V_48 * V_49 ;
V_49 = V_2 -> V_51 ;
F_27 ( & V_49 -> V_8 ) ;
F_70 ( & V_49 -> V_89 , & V_89 , V_101 ) ;
F_14 ( & V_2 -> V_50 ) ;
F_71 () ;
F_72 ( & V_49 -> V_89 , & V_89 ) ;
F_28 ( V_49 ) ;
F_12 ( & V_2 -> V_50 ) ;
}
if ( V_2 -> V_3 != V_102 ) {
F_14 ( & V_2 -> V_50 ) ;
F_10 ( V_51 ) ;
return 0 ;
}
F_8 ( V_2 -> V_51 ) ;
V_2 -> V_51 = V_51 ;
V_2 -> V_3 = V_100 ;
F_14 ( & V_2 -> V_50 ) ;
if ( V_36 -> V_103 & V_104 ) {
F_52 ( & V_51 -> V_86 ) ;
V_31 = F_73 ( V_36 , V_2 ) ;
F_12 ( & V_2 -> V_50 ) ;
if ( V_31 == 1 ) {
V_2 -> V_51 = NULL ;
V_2 -> V_3 = V_4 ;
V_2 -> V_105 = ( T_2 ) - 1 ;
V_51 -> V_85 = ( T_2 ) - 1 ;
} else {
if ( V_96 ) {
V_2 -> V_51 = NULL ;
V_2 -> V_3 = V_102 ;
} else {
V_2 -> V_3 = V_106 ;
V_2 -> V_107 = 1 ;
}
}
F_14 ( & V_2 -> V_50 ) ;
#ifdef F_39
if ( V_31 == 1 &&
F_40 ( V_2 ) ) {
T_2 V_93 ;
F_12 ( & V_2 -> V_94 -> V_50 ) ;
F_12 ( & V_2 -> V_50 ) ;
V_93 = V_2 -> V_23 . V_35 -
F_61 ( & V_2 -> V_95 ) ;
V_2 -> V_94 -> V_93 += V_93 >> 1 ;
F_14 ( & V_2 -> V_50 ) ;
F_14 ( & V_2 -> V_94 -> V_50 ) ;
F_30 ( V_2 ) ;
}
#endif
F_50 ( & V_51 -> V_86 ) ;
F_55 ( & V_51 -> V_89 ) ;
if ( V_31 == 1 ) {
F_28 ( V_51 ) ;
F_20 ( V_36 , V_2 ) ;
return 0 ;
}
} else {
F_12 ( & V_2 -> V_50 ) ;
if ( V_96 ) {
V_2 -> V_51 = NULL ;
V_2 -> V_3 = V_102 ;
} else {
V_2 -> V_3 = V_106 ;
V_2 -> V_107 = 1 ;
}
F_14 ( & V_2 -> V_50 ) ;
F_55 ( & V_51 -> V_89 ) ;
}
if ( V_96 ) {
F_28 ( V_51 ) ;
return 0 ;
}
F_74 ( & V_36 -> V_84 ) ;
F_27 ( & V_51 -> V_8 ) ;
F_75 ( & V_51 -> V_98 , & V_36 -> V_108 ) ;
F_76 ( & V_36 -> V_84 ) ;
F_4 ( V_2 ) ;
F_77 ( V_36 -> V_109 , & V_51 -> V_91 ) ;
return V_31 ;
}
static struct V_1 *
F_78 ( struct V_14 * V_15 , T_2 V_29 )
{
return F_17 ( V_15 , V_29 , 0 ) ;
}
struct V_1 * F_79 (
struct V_14 * V_15 ,
T_2 V_29 )
{
return F_17 ( V_15 , V_29 , 1 ) ;
}
static struct V_110 * F_80 ( struct V_14 * V_15 ,
T_2 V_7 )
{
struct V_111 * V_112 = & V_15 -> V_94 ;
struct V_110 * V_113 ;
V_7 &= V_114 ;
F_81 () ;
F_82 (found, head, list) {
if ( V_113 -> V_7 & V_7 ) {
F_83 () ;
return V_113 ;
}
}
F_83 () ;
return NULL ;
}
static void F_84 ( struct V_14 * V_36 , T_4 V_37 ,
T_2 V_115 , T_2 V_116 )
{
struct V_110 * V_94 ;
T_2 V_7 ;
if ( V_115 < V_117 ) {
if ( V_116 == V_118 )
V_7 = V_119 ;
else
V_7 = V_53 ;
} else {
V_7 = V_120 ;
}
V_94 = F_80 ( V_36 , V_7 ) ;
ASSERT ( V_94 ) ;
F_85 ( & V_94 -> V_121 , V_37 ) ;
}
void F_86 ( struct V_14 * V_15 )
{
struct V_111 * V_112 = & V_15 -> V_94 ;
struct V_110 * V_113 ;
F_81 () ;
F_82 (found, head, list)
V_113 -> V_122 = 0 ;
F_83 () ;
}
int F_87 ( struct V_14 * V_36 , T_2 V_34 , T_2 V_47 )
{
int V_31 ;
struct V_69 V_23 ;
struct V_65 * V_66 ;
V_66 = F_37 () ;
if ( ! V_66 )
return - V_74 ;
V_23 . V_24 = V_34 ;
V_23 . V_35 = V_47 ;
V_23 . type = V_79 ;
V_31 = F_41 ( NULL , V_36 -> V_64 , & V_23 , V_66 , 0 , 0 ) ;
F_56 ( V_66 ) ;
return V_31 ;
}
int F_88 ( struct V_123 * V_124 ,
struct V_14 * V_36 , T_2 V_29 ,
T_2 V_35 , int V_125 , T_2 * V_126 , T_2 * V_7 )
{
struct V_127 * V_112 ;
struct V_128 * V_129 ;
struct V_65 * V_66 ;
struct V_130 * V_131 ;
struct V_67 * V_68 ;
struct V_69 V_23 ;
T_3 V_132 ;
T_2 V_133 ;
T_2 V_134 ;
int V_31 ;
if ( V_125 && ! F_89 ( V_36 , V_135 ) ) {
V_35 = V_36 -> V_54 ;
V_125 = 0 ;
}
V_66 = F_37 () ;
if ( ! V_66 )
return - V_74 ;
if ( ! V_124 ) {
V_66 -> V_75 = 1 ;
V_66 -> V_76 = 1 ;
}
V_136:
V_23 . V_24 = V_29 ;
V_23 . V_35 = V_35 ;
if ( V_125 )
V_23 . type = V_87 ;
else
V_23 . type = V_79 ;
V_31 = F_41 ( V_124 , V_36 -> V_64 , & V_23 , V_66 , 0 , 0 ) ;
if ( V_31 < 0 )
goto V_137;
if ( V_31 > 0 && V_125 && V_23 . type == V_87 ) {
if ( V_66 -> V_83 [ 0 ] ) {
V_66 -> V_83 [ 0 ] -- ;
F_44 ( V_66 -> V_82 [ 0 ] , & V_23 ,
V_66 -> V_83 [ 0 ] ) ;
if ( V_23 . V_24 == V_29 &&
V_23 . type == V_79 &&
V_23 . V_35 == V_36 -> V_54 )
V_31 = 0 ;
}
}
if ( V_31 == 0 ) {
V_68 = V_66 -> V_82 [ 0 ] ;
V_132 = F_90 ( V_68 , V_66 -> V_83 [ 0 ] ) ;
if ( V_132 >= sizeof( * V_131 ) ) {
V_131 = F_91 ( V_68 , V_66 -> V_83 [ 0 ] ,
struct V_130 ) ;
V_133 = F_92 ( V_68 , V_131 ) ;
V_134 = F_93 ( V_68 , V_131 ) ;
} else {
#ifdef F_94
struct V_138 * V_139 ;
F_35 ( V_132 != sizeof( * V_139 ) ) ;
V_139 = F_91 ( V_68 , V_66 -> V_83 [ 0 ] ,
struct V_138 ) ;
V_133 = F_95 ( V_68 , V_139 ) ;
V_134 = V_140 ;
#else
F_96 () ;
#endif
}
F_35 ( V_133 == 0 ) ;
} else {
V_133 = 0 ;
V_134 = 0 ;
V_31 = 0 ;
}
if ( ! V_124 )
goto V_81;
V_129 = & V_124 -> V_141 -> V_129 ;
F_12 ( & V_129 -> V_50 ) ;
V_112 = F_97 ( V_129 , V_29 ) ;
if ( V_112 ) {
if ( ! F_98 ( & V_112 -> V_86 ) ) {
F_27 ( & V_112 -> V_142 . V_126 ) ;
F_14 ( & V_129 -> V_50 ) ;
F_48 ( V_66 ) ;
F_52 ( & V_112 -> V_86 ) ;
F_50 ( & V_112 -> V_86 ) ;
F_99 ( & V_112 -> V_142 ) ;
goto V_136;
}
F_12 ( & V_112 -> V_50 ) ;
if ( V_112 -> V_143 && V_112 -> V_143 -> V_144 )
V_134 |= V_112 -> V_143 -> V_145 ;
else
F_35 ( V_133 == 0 ) ;
V_133 += V_112 -> V_142 . V_146 ;
F_14 ( & V_112 -> V_50 ) ;
F_50 ( & V_112 -> V_86 ) ;
}
F_14 ( & V_129 -> V_50 ) ;
V_81:
F_8 ( V_133 == 0 ) ;
if ( V_126 )
* V_126 = V_133 ;
if ( V_7 )
* V_7 = V_134 ;
V_137:
F_56 ( V_66 ) ;
return V_31 ;
}
static int F_100 ( struct V_123 * V_124 ,
struct V_14 * V_36 ,
struct V_65 * V_66 ,
T_2 V_115 , T_3 V_147 )
{
struct V_63 * V_12 = V_36 -> V_64 ;
struct V_130 * V_95 ;
struct V_138 * V_139 ;
struct V_148 * V_149 ;
struct V_150 * V_151 ;
struct V_67 * V_68 ;
struct V_69 V_23 ;
struct V_69 V_152 ;
T_3 V_153 = sizeof( * V_95 ) ;
T_2 V_126 ;
int V_31 ;
V_68 = V_66 -> V_82 [ 0 ] ;
F_35 ( F_90 ( V_68 , V_66 -> V_83 [ 0 ] ) != sizeof( * V_139 ) ) ;
F_44 ( V_68 , & V_23 , V_66 -> V_83 [ 0 ] ) ;
V_139 = F_91 ( V_68 , V_66 -> V_83 [ 0 ] ,
struct V_138 ) ;
V_126 = F_95 ( V_68 , V_139 ) ;
if ( V_115 == ( T_2 ) - 1 ) {
while ( 1 ) {
if ( V_66 -> V_83 [ 0 ] >= F_42 ( V_68 ) ) {
V_31 = F_54 ( V_12 , V_66 ) ;
if ( V_31 < 0 )
return V_31 ;
F_35 ( V_31 > 0 ) ;
V_68 = V_66 -> V_82 [ 0 ] ;
}
F_44 ( V_68 , & V_152 ,
V_66 -> V_83 [ 0 ] ) ;
F_35 ( V_23 . V_24 != V_152 . V_24 ) ;
if ( V_152 . type != V_154 ) {
V_66 -> V_83 [ 0 ] ++ ;
continue;
}
V_149 = F_91 ( V_68 , V_66 -> V_83 [ 0 ] ,
struct V_148 ) ;
V_115 = F_101 ( V_68 , V_149 ) ;
break;
}
}
F_48 ( V_66 ) ;
if ( V_115 < V_117 )
V_153 += sizeof( * V_151 ) ;
V_153 -= sizeof( * V_139 ) ;
V_31 = F_41 ( V_124 , V_12 , & V_23 , V_66 ,
V_153 + V_147 , 1 ) ;
if ( V_31 < 0 )
return V_31 ;
F_35 ( V_31 ) ;
F_102 ( V_36 , V_66 , V_153 ) ;
V_68 = V_66 -> V_82 [ 0 ] ;
V_95 = F_91 ( V_68 , V_66 -> V_83 [ 0 ] , struct V_130 ) ;
F_103 ( V_68 , V_95 , V_126 ) ;
F_104 ( V_68 , V_95 , 0 ) ;
if ( V_115 < V_117 ) {
F_105 ( V_68 , V_95 ,
V_155 |
V_140 ) ;
V_151 = (struct V_150 * ) ( V_95 + 1 ) ;
F_106 ( V_68 , ( unsigned long ) V_151 , sizeof( * V_151 ) ) ;
F_107 ( V_68 , V_151 , ( int ) V_115 ) ;
} else {
F_105 ( V_68 , V_95 , V_156 ) ;
}
F_108 ( V_68 ) ;
return 0 ;
}
static T_2 F_109 ( T_2 V_116 , T_2 V_115 , T_2 V_35 )
{
T_3 V_157 = ~ ( T_3 ) 0 ;
T_3 V_158 = ~ ( T_3 ) 0 ;
T_5 V_159 ;
V_159 = F_110 ( V_116 ) ;
V_157 = F_111 ( V_157 , & V_159 , sizeof( V_159 ) ) ;
V_159 = F_110 ( V_115 ) ;
V_158 = F_111 ( V_158 , & V_159 , sizeof( V_159 ) ) ;
V_159 = F_110 ( V_35 ) ;
V_158 = F_111 ( V_158 , & V_159 , sizeof( V_159 ) ) ;
return ( ( T_2 ) V_157 << 31 ) ^ ( T_2 ) V_158 ;
}
static T_2 F_112 ( struct V_67 * V_68 ,
struct V_160 * V_161 )
{
return F_109 ( F_113 ( V_68 , V_161 ) ,
F_114 ( V_68 , V_161 ) ,
F_115 ( V_68 , V_161 ) ) ;
}
static int F_116 ( struct V_67 * V_68 ,
struct V_160 * V_161 ,
T_2 V_116 , T_2 V_115 , T_2 V_35 )
{
if ( F_113 ( V_68 , V_161 ) != V_116 ||
F_114 ( V_68 , V_161 ) != V_115 ||
F_115 ( V_68 , V_161 ) != V_35 )
return 0 ;
return 1 ;
}
static T_1 int F_117 ( struct V_123 * V_124 ,
struct V_14 * V_36 ,
struct V_65 * V_66 ,
T_2 V_29 , T_2 V_19 ,
T_2 V_116 ,
T_2 V_115 , T_2 V_35 )
{
struct V_63 * V_12 = V_36 -> V_64 ;
struct V_69 V_23 ;
struct V_160 * V_161 ;
struct V_67 * V_68 ;
T_3 V_72 ;
int V_31 ;
int V_162 ;
int V_163 = - V_164 ;
V_23 . V_24 = V_29 ;
if ( V_19 ) {
V_23 . type = V_165 ;
V_23 . V_35 = V_19 ;
} else {
V_23 . type = V_166 ;
V_23 . V_35 = F_109 ( V_116 ,
V_115 , V_35 ) ;
}
V_167:
V_162 = 0 ;
V_31 = F_41 ( V_124 , V_12 , & V_23 , V_66 , - 1 , 1 ) ;
if ( V_31 < 0 ) {
V_163 = V_31 ;
goto V_168;
}
if ( V_19 ) {
if ( ! V_31 )
return 0 ;
#ifdef F_94
V_23 . type = V_154 ;
F_48 ( V_66 ) ;
V_31 = F_41 ( V_124 , V_12 , & V_23 , V_66 , - 1 , 1 ) ;
if ( V_31 < 0 ) {
V_163 = V_31 ;
goto V_168;
}
if ( ! V_31 )
return 0 ;
#endif
goto V_168;
}
V_68 = V_66 -> V_82 [ 0 ] ;
V_72 = F_42 ( V_68 ) ;
while ( 1 ) {
if ( V_66 -> V_83 [ 0 ] >= V_72 ) {
V_31 = F_54 ( V_12 , V_66 ) ;
if ( V_31 < 0 )
V_163 = V_31 ;
if ( V_31 )
goto V_168;
V_68 = V_66 -> V_82 [ 0 ] ;
V_72 = F_42 ( V_68 ) ;
V_162 = 1 ;
}
F_44 ( V_68 , & V_23 , V_66 -> V_83 [ 0 ] ) ;
if ( V_23 . V_24 != V_29 ||
V_23 . type != V_166 )
goto V_168;
V_161 = F_91 ( V_68 , V_66 -> V_83 [ 0 ] ,
struct V_160 ) ;
if ( F_116 ( V_68 , V_161 , V_116 ,
V_115 , V_35 ) ) {
if ( V_162 ) {
F_48 ( V_66 ) ;
goto V_167;
}
V_163 = 0 ;
break;
}
V_66 -> V_83 [ 0 ] ++ ;
}
V_168:
return V_163 ;
}
static T_1 int F_118 ( struct V_123 * V_124 ,
struct V_14 * V_36 ,
struct V_65 * V_66 ,
T_2 V_29 , T_2 V_19 ,
T_2 V_116 , T_2 V_115 ,
T_2 V_35 , int V_169 )
{
struct V_63 * V_12 = V_36 -> V_64 ;
struct V_69 V_23 ;
struct V_67 * V_68 ;
T_3 V_59 ;
T_3 V_133 ;
int V_31 ;
V_23 . V_24 = V_29 ;
if ( V_19 ) {
V_23 . type = V_165 ;
V_23 . V_35 = V_19 ;
V_59 = sizeof( struct V_170 ) ;
} else {
V_23 . type = V_166 ;
V_23 . V_35 = F_109 ( V_116 ,
V_115 , V_35 ) ;
V_59 = sizeof( struct V_160 ) ;
}
V_31 = F_119 ( V_124 , V_12 , V_66 , & V_23 , V_59 ) ;
if ( V_31 && V_31 != - V_27 )
goto V_168;
V_68 = V_66 -> V_82 [ 0 ] ;
if ( V_19 ) {
struct V_170 * V_161 ;
V_161 = F_91 ( V_68 , V_66 -> V_83 [ 0 ] ,
struct V_170 ) ;
if ( V_31 == 0 ) {
F_120 ( V_68 , V_161 , V_169 ) ;
} else {
V_133 = F_121 ( V_68 , V_161 ) ;
V_133 += V_169 ;
F_120 ( V_68 , V_161 , V_133 ) ;
}
} else {
struct V_160 * V_161 ;
while ( V_31 == - V_27 ) {
V_161 = F_91 ( V_68 , V_66 -> V_83 [ 0 ] ,
struct V_160 ) ;
if ( F_116 ( V_68 , V_161 , V_116 ,
V_115 , V_35 ) )
break;
F_48 ( V_66 ) ;
V_23 . V_35 ++ ;
V_31 = F_119 ( V_124 , V_12 , V_66 , & V_23 ,
V_59 ) ;
if ( V_31 && V_31 != - V_27 )
goto V_168;
V_68 = V_66 -> V_82 [ 0 ] ;
}
V_161 = F_91 ( V_68 , V_66 -> V_83 [ 0 ] ,
struct V_160 ) ;
if ( V_31 == 0 ) {
F_122 ( V_68 , V_161 ,
V_116 ) ;
F_123 ( V_68 , V_161 , V_115 ) ;
F_124 ( V_68 , V_161 , V_35 ) ;
F_125 ( V_68 , V_161 , V_169 ) ;
} else {
V_133 = F_126 ( V_68 , V_161 ) ;
V_133 += V_169 ;
F_125 ( V_68 , V_161 , V_133 ) ;
}
}
F_108 ( V_68 ) ;
V_31 = 0 ;
V_168:
F_48 ( V_66 ) ;
return V_31 ;
}
static T_1 int F_127 ( struct V_123 * V_124 ,
struct V_14 * V_36 ,
struct V_65 * V_66 ,
int V_171 , int * V_172 )
{
struct V_69 V_23 ;
struct V_160 * V_173 = NULL ;
struct V_170 * V_174 = NULL ;
struct V_67 * V_68 ;
T_3 V_133 = 0 ;
int V_31 = 0 ;
V_68 = V_66 -> V_82 [ 0 ] ;
F_44 ( V_68 , & V_23 , V_66 -> V_83 [ 0 ] ) ;
if ( V_23 . type == V_166 ) {
V_173 = F_91 ( V_68 , V_66 -> V_83 [ 0 ] ,
struct V_160 ) ;
V_133 = F_126 ( V_68 , V_173 ) ;
} else if ( V_23 . type == V_165 ) {
V_174 = F_91 ( V_68 , V_66 -> V_83 [ 0 ] ,
struct V_170 ) ;
V_133 = F_121 ( V_68 , V_174 ) ;
#ifdef F_94
} else if ( V_23 . type == V_154 ) {
struct V_148 * V_149 ;
V_149 = F_91 ( V_68 , V_66 -> V_83 [ 0 ] ,
struct V_148 ) ;
V_133 = F_128 ( V_68 , V_149 ) ;
#endif
} else {
F_96 () ;
}
F_35 ( V_133 < V_171 ) ;
V_133 -= V_171 ;
if ( V_133 == 0 ) {
V_31 = F_129 ( V_124 , V_36 -> V_64 , V_66 ) ;
* V_172 = 1 ;
} else {
if ( V_23 . type == V_166 )
F_125 ( V_68 , V_173 , V_133 ) ;
else if ( V_23 . type == V_165 )
F_120 ( V_68 , V_174 , V_133 ) ;
#ifdef F_94
else {
struct V_148 * V_149 ;
V_149 = F_91 ( V_68 , V_66 -> V_83 [ 0 ] ,
struct V_148 ) ;
F_130 ( V_68 , V_149 , V_133 ) ;
}
#endif
F_108 ( V_68 ) ;
}
return V_31 ;
}
static T_1 T_3 F_131 ( struct V_65 * V_66 ,
struct V_175 * V_176 )
{
struct V_69 V_23 ;
struct V_67 * V_68 ;
struct V_160 * V_173 ;
struct V_170 * V_174 ;
T_3 V_133 = 0 ;
V_68 = V_66 -> V_82 [ 0 ] ;
F_44 ( V_68 , & V_23 , V_66 -> V_83 [ 0 ] ) ;
if ( V_176 ) {
if ( F_132 ( V_68 , V_176 ) ==
V_166 ) {
V_173 = (struct V_160 * ) ( & V_176 -> V_35 ) ;
V_133 = F_126 ( V_68 , V_173 ) ;
} else {
V_174 = (struct V_170 * ) ( V_176 + 1 ) ;
V_133 = F_121 ( V_68 , V_174 ) ;
}
} else if ( V_23 . type == V_166 ) {
V_173 = F_91 ( V_68 , V_66 -> V_83 [ 0 ] ,
struct V_160 ) ;
V_133 = F_126 ( V_68 , V_173 ) ;
} else if ( V_23 . type == V_165 ) {
V_174 = F_91 ( V_68 , V_66 -> V_83 [ 0 ] ,
struct V_170 ) ;
V_133 = F_121 ( V_68 , V_174 ) ;
#ifdef F_94
} else if ( V_23 . type == V_154 ) {
struct V_148 * V_149 ;
V_149 = F_91 ( V_68 , V_66 -> V_83 [ 0 ] ,
struct V_148 ) ;
V_133 = F_128 ( V_68 , V_149 ) ;
#endif
} else {
F_8 ( 1 ) ;
}
return V_133 ;
}
static T_1 int F_133 ( struct V_123 * V_124 ,
struct V_14 * V_36 ,
struct V_65 * V_66 ,
T_2 V_29 , T_2 V_19 ,
T_2 V_116 )
{
struct V_63 * V_12 = V_36 -> V_64 ;
struct V_69 V_23 ;
int V_31 ;
V_23 . V_24 = V_29 ;
if ( V_19 ) {
V_23 . type = V_177 ;
V_23 . V_35 = V_19 ;
} else {
V_23 . type = V_178 ;
V_23 . V_35 = V_116 ;
}
V_31 = F_41 ( V_124 , V_12 , & V_23 , V_66 , - 1 , 1 ) ;
if ( V_31 > 0 )
V_31 = - V_164 ;
#ifdef F_94
if ( V_31 == - V_164 && V_19 ) {
F_48 ( V_66 ) ;
V_23 . type = V_154 ;
V_31 = F_41 ( V_124 , V_12 , & V_23 , V_66 , - 1 , 1 ) ;
if ( V_31 > 0 )
V_31 = - V_164 ;
}
#endif
return V_31 ;
}
static T_1 int F_134 ( struct V_123 * V_124 ,
struct V_14 * V_36 ,
struct V_65 * V_66 ,
T_2 V_29 , T_2 V_19 ,
T_2 V_116 )
{
struct V_69 V_23 ;
int V_31 ;
V_23 . V_24 = V_29 ;
if ( V_19 ) {
V_23 . type = V_177 ;
V_23 . V_35 = V_19 ;
} else {
V_23 . type = V_178 ;
V_23 . V_35 = V_116 ;
}
V_31 = F_119 ( V_124 , V_36 -> V_64 ,
V_66 , & V_23 , 0 ) ;
F_48 ( V_66 ) ;
return V_31 ;
}
static inline int F_135 ( T_2 V_19 , T_2 V_115 )
{
int type ;
if ( V_115 < V_117 ) {
if ( V_19 > 0 )
type = V_177 ;
else
type = V_178 ;
} else {
if ( V_19 > 0 )
type = V_165 ;
else
type = V_166 ;
}
return type ;
}
static int F_45 ( struct V_65 * V_66 , int V_179 ,
struct V_69 * V_23 )
{
for (; V_179 < V_180 ; V_179 ++ ) {
if ( ! V_66 -> V_82 [ V_179 ] )
break;
if ( V_66 -> V_83 [ V_179 ] + 1 >=
F_42 ( V_66 -> V_82 [ V_179 ] ) )
continue;
if ( V_179 == 0 )
F_44 ( V_66 -> V_82 [ V_179 ] , V_23 ,
V_66 -> V_83 [ V_179 ] + 1 ) ;
else
F_136 ( V_66 -> V_82 [ V_179 ] , V_23 ,
V_66 -> V_83 [ V_179 ] + 1 ) ;
return 0 ;
}
return 1 ;
}
static T_6
int F_137 ( struct V_123 * V_124 ,
struct V_14 * V_36 ,
struct V_65 * V_66 ,
struct V_175 * * V_181 ,
T_2 V_29 , T_2 V_37 ,
T_2 V_19 , T_2 V_116 ,
T_2 V_115 , T_2 V_35 , int V_182 )
{
struct V_63 * V_12 = V_36 -> V_64 ;
struct V_69 V_23 ;
struct V_67 * V_68 ;
struct V_130 * V_131 ;
struct V_175 * V_176 ;
T_2 V_7 ;
T_2 V_132 ;
unsigned long V_183 ;
unsigned long V_33 ;
int V_147 ;
int type ;
int V_184 ;
int V_31 ;
int V_163 = 0 ;
bool V_185 = F_89 ( V_36 , V_135 ) ;
V_23 . V_24 = V_29 ;
V_23 . type = V_79 ;
V_23 . V_35 = V_37 ;
V_184 = F_135 ( V_19 , V_115 ) ;
if ( V_182 ) {
V_147 = F_138 ( V_184 ) ;
V_66 -> V_186 = 1 ;
} else
V_147 = - 1 ;
if ( V_185 && V_115 < V_117 ) {
V_23 . type = V_87 ;
V_23 . V_35 = V_115 ;
}
V_167:
V_31 = F_41 ( V_124 , V_12 , & V_23 , V_66 , V_147 , 1 ) ;
if ( V_31 < 0 ) {
V_163 = V_31 ;
goto V_81;
}
if ( V_31 > 0 && V_185 ) {
V_185 = false ;
if ( V_66 -> V_83 [ 0 ] ) {
V_66 -> V_83 [ 0 ] -- ;
F_44 ( V_66 -> V_82 [ 0 ] , & V_23 ,
V_66 -> V_83 [ 0 ] ) ;
if ( V_23 . V_24 == V_29 &&
V_23 . type == V_79 &&
V_23 . V_35 == V_37 )
V_31 = 0 ;
}
if ( V_31 ) {
V_23 . V_24 = V_29 ;
V_23 . type = V_79 ;
V_23 . V_35 = V_37 ;
F_48 ( V_66 ) ;
goto V_167;
}
}
if ( V_31 && ! V_182 ) {
V_163 = - V_164 ;
goto V_81;
} else if ( F_8 ( V_31 ) ) {
V_163 = - V_187 ;
goto V_81;
}
V_68 = V_66 -> V_82 [ 0 ] ;
V_132 = F_90 ( V_68 , V_66 -> V_83 [ 0 ] ) ;
#ifdef F_94
if ( V_132 < sizeof( * V_131 ) ) {
if ( ! V_182 ) {
V_163 = - V_164 ;
goto V_81;
}
V_31 = F_100 ( V_124 , V_36 , V_66 , V_115 ,
V_147 ) ;
if ( V_31 < 0 ) {
V_163 = V_31 ;
goto V_81;
}
V_68 = V_66 -> V_82 [ 0 ] ;
V_132 = F_90 ( V_68 , V_66 -> V_83 [ 0 ] ) ;
}
#endif
F_35 ( V_132 < sizeof( * V_131 ) ) ;
V_131 = F_91 ( V_68 , V_66 -> V_83 [ 0 ] , struct V_130 ) ;
V_7 = F_93 ( V_68 , V_131 ) ;
V_183 = ( unsigned long ) ( V_131 + 1 ) ;
V_33 = ( unsigned long ) V_131 + V_132 ;
if ( V_7 & V_155 && ! V_185 ) {
V_183 += sizeof( struct V_150 ) ;
F_35 ( V_183 > V_33 ) ;
}
V_163 = - V_164 ;
while ( 1 ) {
if ( V_183 >= V_33 ) {
F_8 ( V_183 > V_33 ) ;
break;
}
V_176 = (struct V_175 * ) V_183 ;
type = F_132 ( V_68 , V_176 ) ;
if ( V_184 < type )
break;
if ( V_184 > type ) {
V_183 += F_138 ( type ) ;
continue;
}
if ( type == V_166 ) {
struct V_160 * V_188 ;
V_188 = (struct V_160 * ) ( & V_176 -> V_35 ) ;
if ( F_116 ( V_68 , V_188 , V_116 ,
V_115 , V_35 ) ) {
V_163 = 0 ;
break;
}
if ( F_112 ( V_68 , V_188 ) <
F_109 ( V_116 , V_115 , V_35 ) )
break;
} else {
T_2 V_189 ;
V_189 = F_139 ( V_68 , V_176 ) ;
if ( V_19 > 0 ) {
if ( V_19 == V_189 ) {
V_163 = 0 ;
break;
}
if ( V_189 < V_19 )
break;
} else {
if ( V_116 == V_189 ) {
V_163 = 0 ;
break;
}
if ( V_189 < V_116 )
break;
}
}
V_183 += F_138 ( type ) ;
}
if ( V_163 == - V_164 && V_182 ) {
if ( V_132 + V_147 >=
F_140 ( V_12 ) ) {
V_163 = - V_190 ;
goto V_81;
}
if ( F_45 ( V_66 , 0 , & V_23 ) == 0 &&
V_23 . V_24 == V_29 &&
V_23 . type < V_191 ) {
V_163 = - V_190 ;
goto V_81;
}
}
* V_181 = (struct V_175 * ) V_183 ;
V_81:
if ( V_182 ) {
V_66 -> V_186 = 0 ;
F_141 ( V_66 , 1 ) ;
}
return V_163 ;
}
static T_6
void F_142 ( struct V_14 * V_36 ,
struct V_65 * V_66 ,
struct V_175 * V_176 ,
T_2 V_19 , T_2 V_116 ,
T_2 V_115 , T_2 V_35 , int V_169 ,
struct V_192 * V_143 )
{
struct V_67 * V_68 ;
struct V_130 * V_131 ;
unsigned long V_183 ;
unsigned long V_33 ;
unsigned long V_193 ;
T_2 V_126 ;
int V_59 ;
int type ;
V_68 = V_66 -> V_82 [ 0 ] ;
V_131 = F_91 ( V_68 , V_66 -> V_83 [ 0 ] , struct V_130 ) ;
V_193 = ( unsigned long ) V_176 - ( unsigned long ) V_131 ;
type = F_135 ( V_19 , V_115 ) ;
V_59 = F_138 ( type ) ;
F_102 ( V_36 , V_66 , V_59 ) ;
V_131 = F_91 ( V_68 , V_66 -> V_83 [ 0 ] , struct V_130 ) ;
V_126 = F_92 ( V_68 , V_131 ) ;
V_126 += V_169 ;
F_103 ( V_68 , V_131 , V_126 ) ;
if ( V_143 )
F_143 ( V_143 , V_68 , V_131 ) ;
V_183 = ( unsigned long ) V_131 + V_193 ;
V_33 = ( unsigned long ) V_131 + F_90 ( V_68 , V_66 -> V_83 [ 0 ] ) ;
if ( V_183 < V_33 - V_59 )
F_144 ( V_68 , V_183 + V_59 , V_183 ,
V_33 - V_59 - V_183 ) ;
V_176 = (struct V_175 * ) V_183 ;
F_145 ( V_68 , V_176 , type ) ;
if ( type == V_166 ) {
struct V_160 * V_188 ;
V_188 = (struct V_160 * ) ( & V_176 -> V_35 ) ;
F_122 ( V_68 , V_188 , V_116 ) ;
F_123 ( V_68 , V_188 , V_115 ) ;
F_124 ( V_68 , V_188 , V_35 ) ;
F_125 ( V_68 , V_188 , V_169 ) ;
} else if ( type == V_165 ) {
struct V_170 * V_194 ;
V_194 = (struct V_170 * ) ( V_176 + 1 ) ;
F_120 ( V_68 , V_194 , V_169 ) ;
F_146 ( V_68 , V_176 , V_19 ) ;
} else if ( type == V_177 ) {
F_146 ( V_68 , V_176 , V_19 ) ;
} else {
F_146 ( V_68 , V_176 , V_116 ) ;
}
F_108 ( V_68 ) ;
}
static int F_147 ( struct V_123 * V_124 ,
struct V_14 * V_36 ,
struct V_65 * V_66 ,
struct V_175 * * V_181 ,
T_2 V_29 , T_2 V_37 , T_2 V_19 ,
T_2 V_116 , T_2 V_115 , T_2 V_35 )
{
int V_31 ;
V_31 = F_137 ( V_124 , V_36 , V_66 , V_181 ,
V_29 , V_37 , V_19 ,
V_116 , V_115 , V_35 , 0 ) ;
if ( V_31 != - V_164 )
return V_31 ;
F_48 ( V_66 ) ;
* V_181 = NULL ;
if ( V_115 < V_117 ) {
V_31 = F_133 ( V_124 , V_36 , V_66 , V_29 ,
V_19 , V_116 ) ;
} else {
V_31 = F_117 ( V_124 , V_36 , V_66 , V_29 ,
V_19 , V_116 , V_115 ,
V_35 ) ;
}
return V_31 ;
}
static T_6
void F_148 ( struct V_14 * V_36 ,
struct V_65 * V_66 ,
struct V_175 * V_176 ,
int V_195 ,
struct V_192 * V_143 ,
int * V_172 )
{
struct V_67 * V_68 ;
struct V_130 * V_131 ;
struct V_160 * V_188 = NULL ;
struct V_170 * V_194 = NULL ;
unsigned long V_183 ;
unsigned long V_33 ;
T_3 V_132 ;
int V_59 ;
int type ;
T_2 V_126 ;
V_68 = V_66 -> V_82 [ 0 ] ;
V_131 = F_91 ( V_68 , V_66 -> V_83 [ 0 ] , struct V_130 ) ;
V_126 = F_92 ( V_68 , V_131 ) ;
F_8 ( V_195 < 0 && V_126 + V_195 <= 0 ) ;
V_126 += V_195 ;
F_103 ( V_68 , V_131 , V_126 ) ;
if ( V_143 )
F_143 ( V_143 , V_68 , V_131 ) ;
type = F_132 ( V_68 , V_176 ) ;
if ( type == V_166 ) {
V_188 = (struct V_160 * ) ( & V_176 -> V_35 ) ;
V_126 = F_126 ( V_68 , V_188 ) ;
} else if ( type == V_165 ) {
V_194 = (struct V_170 * ) ( V_176 + 1 ) ;
V_126 = F_121 ( V_68 , V_194 ) ;
} else {
V_126 = 1 ;
F_35 ( V_195 != - 1 ) ;
}
F_35 ( V_195 < 0 && V_126 < - V_195 ) ;
V_126 += V_195 ;
if ( V_126 > 0 ) {
if ( type == V_166 )
F_125 ( V_68 , V_188 , V_126 ) ;
else
F_120 ( V_68 , V_194 , V_126 ) ;
} else {
* V_172 = 1 ;
V_59 = F_138 ( type ) ;
V_132 = F_90 ( V_68 , V_66 -> V_83 [ 0 ] ) ;
V_183 = ( unsigned long ) V_176 ;
V_33 = ( unsigned long ) V_131 + V_132 ;
if ( V_183 + V_59 < V_33 )
F_144 ( V_68 , V_183 , V_183 + V_59 ,
V_33 - V_183 - V_59 ) ;
V_132 -= V_59 ;
F_149 ( V_36 , V_66 , V_132 , 1 ) ;
}
F_108 ( V_68 ) ;
}
static T_6
int F_150 ( struct V_123 * V_124 ,
struct V_14 * V_36 ,
struct V_65 * V_66 ,
T_2 V_29 , T_2 V_37 , T_2 V_19 ,
T_2 V_116 , T_2 V_115 ,
T_2 V_35 , int V_169 ,
struct V_192 * V_143 )
{
struct V_175 * V_176 ;
int V_31 ;
V_31 = F_137 ( V_124 , V_36 , V_66 , & V_176 ,
V_29 , V_37 , V_19 ,
V_116 , V_115 , V_35 , 1 ) ;
if ( V_31 == 0 ) {
F_35 ( V_115 < V_117 ) ;
F_148 ( V_36 , V_66 , V_176 ,
V_169 , V_143 , NULL ) ;
} else if ( V_31 == - V_164 ) {
F_142 ( V_36 , V_66 , V_176 , V_19 ,
V_116 , V_115 , V_35 ,
V_169 , V_143 ) ;
V_31 = 0 ;
}
return V_31 ;
}
static int F_151 ( struct V_123 * V_124 ,
struct V_14 * V_36 ,
struct V_65 * V_66 ,
T_2 V_29 , T_2 V_19 , T_2 V_116 ,
T_2 V_115 , T_2 V_35 , int V_169 )
{
int V_31 ;
if ( V_115 < V_117 ) {
F_35 ( V_169 != 1 ) ;
V_31 = F_134 ( V_124 , V_36 , V_66 , V_29 ,
V_19 , V_116 ) ;
} else {
V_31 = F_118 ( V_124 , V_36 , V_66 , V_29 ,
V_19 , V_116 ,
V_115 , V_35 , V_169 ) ;
}
return V_31 ;
}
static int F_152 ( struct V_123 * V_124 ,
struct V_14 * V_36 ,
struct V_65 * V_66 ,
struct V_175 * V_176 ,
int V_171 , int V_196 , int * V_172 )
{
int V_31 = 0 ;
F_35 ( ! V_196 && V_171 != 1 ) ;
if ( V_176 ) {
F_148 ( V_36 , V_66 , V_176 ,
- V_171 , NULL , V_172 ) ;
} else if ( V_196 ) {
V_31 = F_127 ( V_124 , V_36 , V_66 , V_171 ,
V_172 ) ;
} else {
* V_172 = 1 ;
V_31 = F_129 ( V_124 , V_36 -> V_64 , V_66 ) ;
}
return V_31 ;
}
static int F_153 ( struct V_197 * V_198 , T_2 V_34 , T_2 V_47 ,
T_2 * V_199 )
{
int V_200 , V_31 = 0 ;
T_2 V_201 , V_33 ;
T_2 V_202 = F_154 ( V_34 , 1 << 9 ) ;
if ( F_8 ( V_34 != V_202 ) ) {
V_47 -= V_202 - V_34 ;
V_47 = F_155 ( V_47 , 1 << 9 ) ;
V_34 = V_202 ;
}
* V_199 = 0 ;
if ( ! V_47 )
return 0 ;
V_33 = V_34 + V_47 ;
V_201 = V_47 ;
for ( V_200 = 0 ; V_200 < V_46 ; V_200 ++ ) {
T_2 V_203 = F_23 ( V_200 ) ;
T_2 V_204 = V_203 + V_205 ;
T_2 V_59 = V_203 - V_34 ;
if ( ! F_156 ( V_203 , V_34 , V_201 ) &&
! F_156 ( V_204 , V_34 , V_201 ) &&
! F_156 ( V_34 , V_203 , V_205 ) )
continue;
if ( V_203 <= V_34 ) {
V_34 += V_204 - V_34 ;
if ( V_34 > V_33 ) {
V_201 = 0 ;
break;
}
V_201 = V_33 - V_34 ;
continue;
}
if ( V_59 ) {
V_31 = F_157 ( V_198 , V_34 >> 9 , V_59 >> 9 ,
V_97 , 0 ) ;
if ( ! V_31 )
* V_199 += V_59 ;
else if ( V_31 != - V_206 )
return V_31 ;
}
V_34 = V_204 ;
if ( V_34 > V_33 ) {
V_201 = 0 ;
break;
}
V_201 = V_33 - V_34 ;
}
if ( V_201 ) {
V_31 = F_157 ( V_198 , V_34 >> 9 , V_201 >> 9 ,
V_97 , 0 ) ;
if ( ! V_31 )
* V_199 += V_201 ;
}
return V_31 ;
}
int F_158 ( struct V_14 * V_36 , T_2 V_29 ,
T_2 V_37 , T_2 * V_207 )
{
int V_31 ;
T_2 V_199 = 0 ;
struct V_208 * V_209 = NULL ;
F_159 ( V_36 ) ;
V_31 = F_160 ( V_36 , V_210 , V_29 , & V_37 ,
& V_209 , 0 ) ;
if ( ! V_31 ) {
struct V_211 * V_212 = V_209 -> V_213 ;
int V_42 ;
for ( V_42 = 0 ; V_42 < V_209 -> V_214 ; V_42 ++ , V_212 ++ ) {
T_2 V_215 ;
if ( ! V_212 -> V_216 -> V_217 )
continue;
V_31 = F_153 ( V_212 -> V_216 -> V_198 ,
V_212 -> V_218 ,
V_212 -> V_219 ,
& V_215 ) ;
if ( ! V_31 )
V_199 += V_215 ;
else if ( V_31 != - V_206 )
break;
V_31 = 0 ;
}
F_161 ( V_209 ) ;
}
F_162 ( V_36 ) ;
if ( V_207 )
* V_207 = V_199 ;
if ( V_31 == - V_206 )
V_31 = 0 ;
return V_31 ;
}
int F_163 ( struct V_123 * V_124 ,
struct V_14 * V_36 ,
T_2 V_29 , T_2 V_37 , T_2 V_19 ,
T_2 V_116 , T_2 V_115 , T_2 V_35 )
{
int V_220 , V_221 ;
int V_31 ;
F_35 ( V_115 < V_117 &&
V_116 == V_222 ) ;
if ( V_115 < V_117 ) {
V_31 = F_164 ( V_36 , V_124 , V_29 ,
V_37 , V_19 ,
V_116 , ( int ) V_115 ,
V_223 , NULL ,
& V_220 , & V_221 ) ;
} else {
V_31 = F_165 ( V_36 , V_124 , V_29 ,
V_37 , V_19 ,
V_116 , V_115 , V_35 ,
0 , V_223 ,
& V_220 , & V_221 ) ;
}
if ( V_31 == 0 && V_220 < 0 && V_221 >= 0 )
F_84 ( V_36 , - V_37 , V_115 , V_116 ) ;
return V_31 ;
}
static int F_166 ( struct V_123 * V_124 ,
struct V_14 * V_36 ,
struct V_224 * V_142 ,
T_2 V_19 , T_2 V_116 ,
T_2 V_115 , T_2 V_35 , int V_169 ,
struct V_192 * V_143 )
{
struct V_65 * V_66 ;
struct V_67 * V_68 ;
struct V_130 * V_95 ;
struct V_69 V_23 ;
T_2 V_29 = V_142 -> V_29 ;
T_2 V_37 = V_142 -> V_37 ;
T_2 V_126 ;
int V_31 ;
V_66 = F_37 () ;
if ( ! V_66 )
return - V_74 ;
V_66 -> V_77 = V_78 ;
V_66 -> V_225 = 1 ;
V_31 = F_150 ( V_124 , V_36 , V_66 , V_29 ,
V_37 , V_19 , V_116 ,
V_115 , V_35 ,
V_169 , V_143 ) ;
if ( ( V_31 < 0 && V_31 != - V_190 ) || ! V_31 )
goto V_81;
V_68 = V_66 -> V_82 [ 0 ] ;
F_44 ( V_68 , & V_23 , V_66 -> V_83 [ 0 ] ) ;
V_95 = F_91 ( V_68 , V_66 -> V_83 [ 0 ] , struct V_130 ) ;
V_126 = F_92 ( V_68 , V_95 ) ;
F_103 ( V_68 , V_95 , V_126 + V_169 ) ;
if ( V_143 )
F_143 ( V_143 , V_68 , V_95 ) ;
F_108 ( V_68 ) ;
F_48 ( V_66 ) ;
V_66 -> V_77 = V_78 ;
V_66 -> V_225 = 1 ;
V_31 = F_151 ( V_124 , V_36 , V_66 , V_29 , V_19 ,
V_116 , V_115 , V_35 , V_169 ) ;
if ( V_31 )
F_167 ( V_124 , V_31 ) ;
V_81:
F_56 ( V_66 ) ;
return V_31 ;
}
static int F_168 ( struct V_123 * V_124 ,
struct V_14 * V_36 ,
struct V_224 * V_142 ,
struct V_192 * V_143 ,
int V_226 )
{
int V_31 = 0 ;
struct V_227 * V_161 ;
struct V_69 V_228 ;
T_2 V_19 = 0 ;
T_2 V_229 = 0 ;
T_2 V_7 = 0 ;
V_228 . V_24 = V_142 -> V_29 ;
V_228 . V_35 = V_142 -> V_37 ;
V_228 . type = V_79 ;
V_161 = F_169 ( V_142 ) ;
F_170 ( V_36 , V_142 , V_161 , V_142 -> V_230 ) ;
if ( V_142 -> type == V_165 )
V_19 = V_161 -> V_19 ;
V_229 = V_161 -> V_12 ;
if ( V_142 -> V_230 == V_223 && V_226 ) {
if ( V_143 )
V_7 |= V_143 -> V_145 ;
V_31 = F_171 ( V_124 , V_36 ,
V_19 , V_229 , V_7 ,
V_161 -> V_24 , V_161 -> V_35 ,
& V_228 , V_142 -> V_146 ) ;
} else if ( V_142 -> V_230 == V_223 ) {
V_31 = F_166 ( V_124 , V_36 , V_142 , V_19 ,
V_229 , V_161 -> V_24 ,
V_161 -> V_35 , V_142 -> V_146 ,
V_143 ) ;
} else if ( V_142 -> V_230 == V_231 ) {
V_31 = F_172 ( V_124 , V_36 , V_142 , V_19 ,
V_229 , V_161 -> V_24 ,
V_161 -> V_35 , V_142 -> V_146 ,
V_143 ) ;
} else {
F_96 () ;
}
return V_31 ;
}
static void F_143 ( struct V_192 * V_143 ,
struct V_67 * V_68 ,
struct V_130 * V_131 )
{
T_2 V_7 = F_93 ( V_68 , V_131 ) ;
if ( V_143 -> V_144 ) {
V_7 |= V_143 -> V_145 ;
F_105 ( V_68 , V_131 , V_7 ) ;
}
if ( V_143 -> V_232 ) {
struct V_150 * V_151 ;
F_35 ( ! ( V_7 & V_155 ) ) ;
V_151 = (struct V_150 * ) ( V_131 + 1 ) ;
F_173 ( V_68 , V_151 , & V_143 -> V_23 ) ;
}
}
static int F_174 ( struct V_123 * V_124 ,
struct V_14 * V_36 ,
struct V_224 * V_142 ,
struct V_192 * V_143 )
{
struct V_69 V_23 ;
struct V_65 * V_66 ;
struct V_130 * V_131 ;
struct V_67 * V_68 ;
T_3 V_132 ;
int V_31 ;
int V_163 = 0 ;
int V_125 = ! V_143 -> V_196 ;
if ( V_124 -> V_233 )
return 0 ;
if ( V_125 && ! F_89 ( V_36 , V_135 ) )
V_125 = 0 ;
V_66 = F_37 () ;
if ( ! V_66 )
return - V_74 ;
V_23 . V_24 = V_142 -> V_29 ;
if ( V_125 ) {
V_23 . type = V_87 ;
V_23 . V_35 = V_143 -> V_179 ;
} else {
V_23 . type = V_79 ;
V_23 . V_35 = V_142 -> V_37 ;
}
V_167:
V_66 -> V_77 = V_78 ;
V_66 -> V_225 = 1 ;
V_31 = F_41 ( V_124 , V_36 -> V_64 , & V_23 , V_66 , 0 , 1 ) ;
if ( V_31 < 0 ) {
V_163 = V_31 ;
goto V_81;
}
if ( V_31 > 0 ) {
if ( V_125 ) {
if ( V_66 -> V_83 [ 0 ] > 0 ) {
V_66 -> V_83 [ 0 ] -- ;
F_44 ( V_66 -> V_82 [ 0 ] , & V_23 ,
V_66 -> V_83 [ 0 ] ) ;
if ( V_23 . V_24 == V_142 -> V_29 &&
V_23 . type == V_79 &&
V_23 . V_35 == V_142 -> V_37 )
V_31 = 0 ;
}
if ( V_31 > 0 ) {
F_48 ( V_66 ) ;
V_125 = 0 ;
V_23 . V_24 = V_142 -> V_29 ;
V_23 . V_35 = V_142 -> V_37 ;
V_23 . type = V_79 ;
goto V_167;
}
} else {
V_163 = - V_187 ;
goto V_81;
}
}
V_68 = V_66 -> V_82 [ 0 ] ;
V_132 = F_90 ( V_68 , V_66 -> V_83 [ 0 ] ) ;
#ifdef F_94
if ( V_132 < sizeof( * V_131 ) ) {
V_31 = F_100 ( V_124 , V_36 , V_66 , ( T_2 ) - 1 , 0 ) ;
if ( V_31 < 0 ) {
V_163 = V_31 ;
goto V_81;
}
V_68 = V_66 -> V_82 [ 0 ] ;
V_132 = F_90 ( V_68 , V_66 -> V_83 [ 0 ] ) ;
}
#endif
F_35 ( V_132 < sizeof( * V_131 ) ) ;
V_131 = F_91 ( V_68 , V_66 -> V_83 [ 0 ] , struct V_130 ) ;
F_143 ( V_143 , V_68 , V_131 ) ;
F_108 ( V_68 ) ;
V_81:
F_56 ( V_66 ) ;
return V_163 ;
}
static int F_175 ( struct V_123 * V_124 ,
struct V_14 * V_36 ,
struct V_224 * V_142 ,
struct V_192 * V_143 ,
int V_226 )
{
int V_31 = 0 ;
struct V_234 * V_161 ;
struct V_69 V_228 ;
T_2 V_19 = 0 ;
T_2 V_229 = 0 ;
bool V_185 = F_89 ( V_36 , V_135 ) ;
V_161 = F_176 ( V_142 ) ;
F_177 ( V_36 , V_142 , V_161 , V_142 -> V_230 ) ;
if ( V_142 -> type == V_177 )
V_19 = V_161 -> V_19 ;
V_229 = V_161 -> V_12 ;
V_228 . V_24 = V_142 -> V_29 ;
if ( V_185 ) {
V_228 . V_35 = V_161 -> V_179 ;
V_228 . type = V_87 ;
} else {
V_228 . V_35 = V_142 -> V_37 ;
V_228 . type = V_79 ;
}
if ( V_142 -> V_146 != 1 ) {
F_178 ( V_36 ,
L_1 ,
V_142 -> V_29 , V_142 -> V_146 , V_142 -> V_230 , V_229 ,
V_19 ) ;
return - V_187 ;
}
if ( V_142 -> V_230 == V_223 && V_226 ) {
F_35 ( ! V_143 || ! V_143 -> V_144 ) ;
V_31 = F_179 ( V_124 , V_36 ,
V_19 , V_229 ,
V_143 -> V_145 ,
& V_143 -> V_23 ,
V_161 -> V_179 , & V_228 ) ;
} else if ( V_142 -> V_230 == V_223 ) {
V_31 = F_166 ( V_124 , V_36 , V_142 ,
V_19 , V_229 ,
V_161 -> V_179 , 0 , 1 ,
V_143 ) ;
} else if ( V_142 -> V_230 == V_231 ) {
V_31 = F_172 ( V_124 , V_36 , V_142 ,
V_19 , V_229 ,
V_161 -> V_179 , 0 , 1 , V_143 ) ;
} else {
F_96 () ;
}
return V_31 ;
}
static int F_180 ( struct V_123 * V_124 ,
struct V_14 * V_36 ,
struct V_224 * V_142 ,
struct V_192 * V_143 ,
int V_226 )
{
int V_31 = 0 ;
if ( V_124 -> V_233 ) {
if ( V_226 )
F_181 ( V_36 , V_142 -> V_29 ,
V_142 -> V_37 , 1 ) ;
return 0 ;
}
if ( F_182 ( V_142 ) ) {
struct V_127 * V_112 ;
F_35 ( V_143 ) ;
V_112 = F_183 ( V_142 ) ;
F_184 ( V_36 , V_142 , V_112 , V_142 -> V_230 ) ;
if ( V_112 -> V_235 < 0 ) {
struct V_1 * V_2 ;
V_2 = F_79 ( V_36 , V_142 -> V_29 ) ;
ASSERT ( V_2 ) ;
F_85 ( & V_2 -> V_94 -> V_121 ,
- V_142 -> V_37 ) ;
F_6 ( V_2 ) ;
}
if ( V_226 ) {
F_181 ( V_36 , V_142 -> V_29 ,
V_142 -> V_37 , 1 ) ;
if ( V_112 -> V_196 ) {
V_31 = F_185 ( V_124 , V_36 ,
V_142 -> V_29 ,
V_142 -> V_37 ) ;
}
}
F_186 ( V_36 , V_112 -> V_236 ,
V_112 -> V_237 ) ;
return V_31 ;
}
if ( V_142 -> type == V_178 ||
V_142 -> type == V_177 )
V_31 = F_175 ( V_124 , V_36 , V_142 , V_143 ,
V_226 ) ;
else if ( V_142 -> type == V_166 ||
V_142 -> type == V_165 )
V_31 = F_168 ( V_124 , V_36 , V_142 , V_143 ,
V_226 ) ;
else
F_96 () ;
return V_31 ;
}
static inline struct V_224 *
F_187 ( struct V_127 * V_112 )
{
struct V_224 * V_161 ;
if ( F_188 ( & V_112 -> V_238 ) )
return NULL ;
if ( ! F_188 ( & V_112 -> V_239 ) )
return F_189 ( & V_112 -> V_239 ,
struct V_224 , V_240 ) ;
V_161 = F_189 ( & V_112 -> V_238 , struct V_224 ,
V_98 ) ;
ASSERT ( F_188 ( & V_161 -> V_240 ) ) ;
return V_161 ;
}
static T_1 int F_190 ( struct V_123 * V_124 ,
struct V_14 * V_36 ,
unsigned long V_43 )
{
struct V_128 * V_129 ;
struct V_224 * V_161 ;
struct V_127 * V_241 = NULL ;
struct V_192 * V_143 ;
T_7 V_34 = F_191 () ;
int V_31 ;
unsigned long V_8 = 0 ;
unsigned long V_242 = 0 ;
int V_243 = 0 ;
V_129 = & V_124 -> V_141 -> V_129 ;
while ( 1 ) {
if ( ! V_241 ) {
if ( V_8 >= V_43 )
break;
F_12 ( & V_129 -> V_50 ) ;
V_241 = F_192 ( V_124 ) ;
if ( ! V_241 ) {
F_14 ( & V_129 -> V_50 ) ;
break;
}
V_31 = F_193 ( V_124 , V_241 ) ;
F_14 ( & V_129 -> V_50 ) ;
if ( V_31 == - V_190 ) {
V_241 = NULL ;
V_8 ++ ;
continue;
}
}
F_12 ( & V_241 -> V_50 ) ;
F_194 ( V_124 , V_36 , V_129 ,
V_241 ) ;
V_161 = F_187 ( V_241 ) ;
if ( V_161 && V_161 -> V_244 &&
F_195 ( V_36 , V_129 , V_161 -> V_244 ) ) {
F_14 ( & V_241 -> V_50 ) ;
F_12 ( & V_129 -> V_50 ) ;
V_241 -> V_245 = 0 ;
V_129 -> V_246 ++ ;
F_14 ( & V_129 -> V_50 ) ;
F_196 ( V_241 ) ;
V_241 = NULL ;
F_51 () ;
V_8 ++ ;
continue;
}
V_243 = V_241 -> V_243 ;
V_241 -> V_243 = 0 ;
V_143 = V_241 -> V_143 ;
V_241 -> V_143 = NULL ;
if ( ! V_161 ) {
V_161 = & V_241 -> V_142 ;
if ( V_143 && V_243 ) {
F_197 ( V_143 ) ;
V_143 = NULL ;
}
if ( V_143 ) {
F_14 ( & V_241 -> V_50 ) ;
V_31 = F_174 ( V_124 , V_36 ,
V_161 , V_143 ) ;
F_197 ( V_143 ) ;
if ( V_31 ) {
if ( V_243 )
V_241 -> V_243 = 1 ;
F_12 ( & V_129 -> V_50 ) ;
V_241 -> V_245 = 0 ;
V_129 -> V_246 ++ ;
F_14 ( & V_129 -> V_50 ) ;
F_198 ( V_36 ,
L_2 ,
V_31 ) ;
F_196 ( V_241 ) ;
return V_31 ;
}
continue;
}
F_14 ( & V_241 -> V_50 ) ;
F_12 ( & V_129 -> V_50 ) ;
F_12 ( & V_241 -> V_50 ) ;
if ( ! F_188 ( & V_241 -> V_238 ) ||
V_241 -> V_143 ) {
F_14 ( & V_241 -> V_50 ) ;
F_14 ( & V_129 -> V_50 ) ;
continue;
}
V_161 -> V_247 = 0 ;
V_129 -> V_248 -- ;
F_199 ( & V_241 -> V_249 ,
& V_129 -> V_250 ) ;
F_14 ( & V_129 -> V_50 ) ;
} else {
V_242 ++ ;
V_161 -> V_247 = 0 ;
F_200 ( & V_161 -> V_98 ) ;
if ( ! F_188 ( & V_161 -> V_240 ) )
F_200 ( & V_161 -> V_240 ) ;
}
F_201 ( & V_129 -> V_251 ) ;
if ( ! F_182 ( V_161 ) ) {
switch ( V_161 -> V_230 ) {
case V_223 :
case V_252 :
V_241 -> V_142 . V_146 -= V_161 -> V_146 ;
break;
case V_231 :
V_241 -> V_142 . V_146 += V_161 -> V_146 ;
break;
default:
F_8 ( 1 ) ;
}
}
F_14 ( & V_241 -> V_50 ) ;
V_31 = F_180 ( V_124 , V_36 , V_161 , V_143 ,
V_243 ) ;
F_197 ( V_143 ) ;
if ( V_31 ) {
F_12 ( & V_129 -> V_50 ) ;
V_241 -> V_245 = 0 ;
V_129 -> V_246 ++ ;
F_14 ( & V_129 -> V_50 ) ;
F_196 ( V_241 ) ;
F_99 ( V_161 ) ;
F_198 ( V_36 , L_3 ,
V_31 ) ;
return V_31 ;
}
if ( F_182 ( V_161 ) ) {
if ( V_241 -> V_196 &&
V_241 -> V_235 < 0 ) {
F_12 ( & V_129 -> V_50 ) ;
V_129 -> V_253 -= V_161 -> V_37 ;
F_14 ( & V_129 -> V_50 ) ;
}
F_196 ( V_241 ) ;
V_241 = NULL ;
}
F_99 ( V_161 ) ;
V_8 ++ ;
F_51 () ;
}
if ( V_242 > 0 ) {
T_2 V_254 = F_202 ( F_203 ( F_191 () , V_34 ) ) ;
T_2 V_255 ;
F_12 ( & V_129 -> V_50 ) ;
V_255 = V_36 -> V_256 * 3 + V_254 ;
V_36 -> V_256 = V_255 >> 2 ;
F_14 ( & V_129 -> V_50 ) ;
}
return 0 ;
}
static T_2 F_204 ( struct V_257 * V_12 )
{
struct V_17 * V_32 = V_12 -> V_17 ;
struct V_224 * V_258 ;
int V_259 = 1 ;
T_2 V_260 ;
T_2 V_261 = 0 , V_71 = 0 ;
V_32 = F_205 ( V_12 ) ;
if ( V_32 ) {
V_258 = F_13 ( V_32 , struct V_224 , V_17 ) ;
V_261 = V_258 -> V_29 ;
}
V_32 = F_206 ( V_12 ) ;
if ( V_32 ) {
V_258 = F_13 ( V_32 , struct V_224 , V_17 ) ;
V_71 = V_258 -> V_29 ;
}
V_32 = V_12 -> V_17 ;
while ( V_32 ) {
V_258 = F_13 ( V_32 , struct V_224 , V_17 ) ;
F_8 ( ! V_258 -> V_247 ) ;
V_260 = V_258 -> V_29 ;
if ( V_259 )
V_32 = V_32 -> V_25 ;
else
V_32 = V_32 -> V_26 ;
V_259 = 1 - V_259 ;
}
return V_260 ;
}
static inline T_2 F_207 ( struct V_14 * V_36 , T_2 V_262 )
{
T_2 V_37 ;
V_37 = V_262 * ( sizeof( struct V_130 ) +
sizeof( struct V_175 ) ) ;
if ( ! F_89 ( V_36 , V_135 ) )
V_37 += V_262 * sizeof( struct V_150 ) ;
return F_208 ( V_37 , F_209 ( V_36 ) ) ;
}
T_2 F_210 ( struct V_14 * V_36 , T_2 V_263 )
{
T_2 V_264 ;
T_2 V_265 ;
T_2 V_266 ;
V_264 = F_211 ( V_36 ) ;
V_265 = F_212 ( V_264 ,
( T_2 ) F_213 ( V_36 -> V_267 ) ) ;
V_266 = F_212 ( V_263 , V_36 -> V_55 ) ;
V_266 += V_265 - 1 ;
V_266 = F_212 ( V_266 , V_265 ) ;
return V_266 ;
}
int F_214 ( struct V_123 * V_124 ,
struct V_14 * V_36 )
{
struct V_268 * V_269 ;
T_2 V_248 = V_124 -> V_141 -> V_129 . V_246 ;
T_2 V_263 = V_124 -> V_141 -> V_129 . V_253 ;
T_2 V_270 = V_124 -> V_141 -> V_270 ;
T_2 V_37 , V_271 ;
int V_31 = 0 ;
V_37 = F_215 ( V_36 , 1 ) ;
V_248 = F_207 ( V_36 , V_248 ) ;
if ( V_248 > 1 )
V_37 += ( V_248 - 1 ) * V_36 -> V_54 ;
V_37 <<= 1 ;
V_37 += F_210 ( V_36 , V_263 ) *
V_36 -> V_54 ;
V_271 = F_215 ( V_36 ,
V_270 ) ;
V_269 = & V_36 -> V_272 ;
if ( V_269 -> V_94 -> V_122 ) {
V_271 <<= 1 ;
V_37 <<= 1 ;
}
F_12 ( & V_269 -> V_50 ) ;
if ( V_269 -> V_10 <= V_37 + V_271 )
V_31 = 1 ;
F_14 ( & V_269 -> V_50 ) ;
return V_31 ;
}
int F_216 ( struct V_123 * V_124 ,
struct V_14 * V_36 )
{
T_2 V_251 =
F_217 ( & V_124 -> V_141 -> V_129 . V_251 ) ;
T_2 V_273 ;
T_2 V_274 ;
F_2 () ;
V_273 = V_36 -> V_256 ;
V_274 = V_251 * V_273 ;
if ( V_274 >= V_275 )
return 1 ;
if ( V_274 >= V_275 / 2 )
return 2 ;
return F_214 ( V_124 , V_36 ) ;
}
static inline struct V_276 *
F_218 ( struct V_90 * V_91 )
{
return F_58 ( V_91 , struct V_276 , V_91 ) ;
}
static void F_219 ( struct V_90 * V_91 )
{
struct V_276 * V_277 = F_218 ( V_91 ) ;
struct V_123 * V_124 ;
struct V_14 * V_36 = V_277 -> V_12 -> V_36 ;
int V_31 ;
if ( F_220 ( V_36 ) )
goto V_278;
V_124 = F_221 ( V_277 -> V_12 ) ;
if ( F_222 ( V_124 ) ) {
V_277 -> error = F_223 ( V_124 ) ;
goto V_278;
}
V_124 -> V_279 = true ;
if ( V_124 -> V_280 > V_277 -> V_280 )
goto V_33;
V_31 = F_224 ( V_124 , V_36 , V_277 -> V_8 ) ;
if ( V_31 )
V_277 -> error = V_31 ;
V_33:
V_31 = F_225 ( V_124 ) ;
if ( V_31 && ! V_277 -> error )
V_277 -> error = V_31 ;
V_278:
if ( V_277 -> V_279 )
F_226 ( & V_277 -> V_89 ) ;
else
F_10 ( V_277 ) ;
}
int F_227 ( struct V_14 * V_36 ,
unsigned long V_8 , T_2 V_280 , int V_89 )
{
struct V_276 * V_277 ;
int V_31 ;
V_277 = F_228 ( sizeof( * V_277 ) , V_97 ) ;
if ( ! V_277 )
return - V_74 ;
V_277 -> V_12 = V_36 -> V_281 ;
V_277 -> V_8 = V_8 ;
V_277 -> error = 0 ;
V_277 -> V_280 = V_280 ;
if ( V_89 )
V_277 -> V_279 = 1 ;
else
V_277 -> V_279 = 0 ;
F_229 ( & V_277 -> V_89 ) ;
F_69 ( & V_277 -> V_91 , V_282 ,
F_219 , NULL , NULL ) ;
F_77 ( V_36 -> V_283 , & V_277 -> V_91 ) ;
if ( V_89 ) {
F_230 ( & V_277 -> V_89 ) ;
V_31 = V_277 -> error ;
F_10 ( V_277 ) ;
return V_31 ;
}
return 0 ;
}
int F_224 ( struct V_123 * V_124 ,
struct V_14 * V_36 , unsigned long V_8 )
{
struct V_17 * V_142 ;
struct V_128 * V_129 ;
struct V_127 * V_112 ;
int V_31 ;
int V_284 = V_8 == ( unsigned long ) - 1 ;
bool V_285 = V_124 -> V_285 ;
if ( V_124 -> V_233 )
return 0 ;
if ( F_231 ( V_286 , & V_36 -> V_7 ) )
return 0 ;
V_129 = & V_124 -> V_141 -> V_129 ;
if ( V_8 == 0 )
V_8 = F_217 ( & V_129 -> V_251 ) * 2 ;
V_167:
#ifdef F_232
V_129 -> V_287 = F_204 ( & V_129 -> V_12 ) ;
#endif
V_124 -> V_285 = false ;
V_31 = F_190 ( V_124 , V_36 , V_8 ) ;
if ( V_31 < 0 ) {
F_167 ( V_124 , V_31 ) ;
return V_31 ;
}
if ( V_284 ) {
if ( ! F_188 ( & V_124 -> V_288 ) )
F_233 ( V_124 , V_36 ) ;
F_12 ( & V_129 -> V_50 ) ;
V_142 = F_205 ( & V_129 -> V_250 ) ;
if ( ! V_142 ) {
F_14 ( & V_129 -> V_50 ) ;
goto V_81;
}
while ( V_142 ) {
V_112 = F_13 ( V_142 , struct V_127 ,
V_249 ) ;
if ( F_182 ( & V_112 -> V_142 ) ) {
struct V_224 * V_161 ;
V_161 = & V_112 -> V_142 ;
F_27 ( & V_161 -> V_126 ) ;
F_14 ( & V_129 -> V_50 ) ;
F_52 ( & V_112 -> V_86 ) ;
F_50 ( & V_112 -> V_86 ) ;
F_99 ( V_161 ) ;
F_51 () ;
goto V_167;
} else {
F_8 ( 1 ) ;
}
V_142 = F_234 ( V_142 ) ;
}
F_14 ( & V_129 -> V_50 ) ;
F_51 () ;
goto V_167;
}
V_81:
V_124 -> V_285 = V_285 ;
return 0 ;
}
int F_235 ( struct V_123 * V_124 ,
struct V_14 * V_36 ,
T_2 V_29 , T_2 V_37 , T_2 V_7 ,
int V_179 , int V_196 )
{
struct V_192 * V_143 ;
int V_31 ;
V_143 = F_236 () ;
if ( ! V_143 )
return - V_74 ;
V_143 -> V_145 = V_7 ;
V_143 -> V_144 = true ;
V_143 -> V_232 = false ;
V_143 -> V_196 = V_196 ? true : false ;
V_143 -> V_179 = V_179 ;
V_31 = F_237 ( V_36 , V_124 , V_29 ,
V_37 , V_143 ) ;
if ( V_31 )
F_197 ( V_143 ) ;
return V_31 ;
}
static T_1 int F_238 ( struct V_63 * V_12 ,
struct V_65 * V_66 ,
T_2 V_24 , T_2 V_35 , T_2 V_29 )
{
struct V_127 * V_112 ;
struct V_224 * V_161 ;
struct V_227 * V_289 ;
struct V_128 * V_129 ;
struct V_290 * V_291 ;
int V_31 = 0 ;
V_291 = V_12 -> V_36 -> V_292 ;
if ( ! V_291 )
return 0 ;
V_129 = & V_291 -> V_129 ;
F_12 ( & V_129 -> V_50 ) ;
V_112 = F_97 ( V_129 , V_29 ) ;
if ( ! V_112 ) {
F_14 ( & V_129 -> V_50 ) ;
return 0 ;
}
if ( ! F_98 ( & V_112 -> V_86 ) ) {
F_27 ( & V_112 -> V_142 . V_126 ) ;
F_14 ( & V_129 -> V_50 ) ;
F_48 ( V_66 ) ;
F_52 ( & V_112 -> V_86 ) ;
F_50 ( & V_112 -> V_86 ) ;
F_99 ( & V_112 -> V_142 ) ;
return - V_190 ;
}
F_14 ( & V_129 -> V_50 ) ;
F_12 ( & V_112 -> V_50 ) ;
F_239 (ref, &head->ref_list, list) {
if ( V_161 -> type != V_166 ) {
V_31 = 1 ;
break;
}
V_289 = F_169 ( V_161 ) ;
if ( V_289 -> V_12 != V_12 -> V_293 . V_24 ||
V_289 -> V_24 != V_24 ||
V_289 -> V_35 != V_35 ) {
V_31 = 1 ;
break;
}
}
F_14 ( & V_112 -> V_50 ) ;
F_50 ( & V_112 -> V_86 ) ;
return V_31 ;
}
static T_1 int F_240 ( struct V_63 * V_12 ,
struct V_65 * V_66 ,
T_2 V_24 , T_2 V_35 , T_2 V_29 )
{
struct V_14 * V_36 = V_12 -> V_36 ;
struct V_63 * V_64 = V_36 -> V_64 ;
struct V_67 * V_68 ;
struct V_160 * V_161 ;
struct V_175 * V_176 ;
struct V_130 * V_131 ;
struct V_69 V_23 ;
T_3 V_132 ;
int V_31 ;
V_23 . V_24 = V_29 ;
V_23 . V_35 = ( T_2 ) - 1 ;
V_23 . type = V_79 ;
V_31 = F_41 ( NULL , V_64 , & V_23 , V_66 , 0 , 0 ) ;
if ( V_31 < 0 )
goto V_81;
F_35 ( V_31 == 0 ) ;
V_31 = - V_164 ;
if ( V_66 -> V_83 [ 0 ] == 0 )
goto V_81;
V_66 -> V_83 [ 0 ] -- ;
V_68 = V_66 -> V_82 [ 0 ] ;
F_44 ( V_68 , & V_23 , V_66 -> V_83 [ 0 ] ) ;
if ( V_23 . V_24 != V_29 || V_23 . type != V_79 )
goto V_81;
V_31 = 1 ;
V_132 = F_90 ( V_68 , V_66 -> V_83 [ 0 ] ) ;
#ifdef F_94
if ( V_132 < sizeof( * V_131 ) ) {
F_8 ( V_132 != sizeof( struct V_138 ) ) ;
goto V_81;
}
#endif
V_131 = F_91 ( V_68 , V_66 -> V_83 [ 0 ] , struct V_130 ) ;
if ( V_132 != sizeof( * V_131 ) +
F_138 ( V_166 ) )
goto V_81;
if ( F_241 ( V_68 , V_131 ) <=
F_242 ( & V_12 -> V_294 ) )
goto V_81;
V_176 = (struct V_175 * ) ( V_131 + 1 ) ;
if ( F_132 ( V_68 , V_176 ) !=
V_166 )
goto V_81;
V_161 = (struct V_160 * ) ( & V_176 -> V_35 ) ;
if ( F_92 ( V_68 , V_131 ) !=
F_126 ( V_68 , V_161 ) ||
F_113 ( V_68 , V_161 ) !=
V_12 -> V_293 . V_24 ||
F_114 ( V_68 , V_161 ) != V_24 ||
F_115 ( V_68 , V_161 ) != V_35 )
goto V_81;
V_31 = 0 ;
V_81:
return V_31 ;
}
int F_243 ( struct V_63 * V_12 , T_2 V_24 , T_2 V_35 ,
T_2 V_29 )
{
struct V_65 * V_66 ;
int V_31 ;
int V_295 ;
V_66 = F_37 () ;
if ( ! V_66 )
return - V_164 ;
do {
V_31 = F_240 ( V_12 , V_66 , V_24 ,
V_35 , V_29 ) ;
if ( V_31 && V_31 != - V_164 )
goto V_81;
V_295 = F_238 ( V_12 , V_66 , V_24 ,
V_35 , V_29 ) ;
} while ( V_295 == - V_190 );
if ( V_295 && V_295 != - V_164 ) {
V_31 = V_295 ;
goto V_81;
}
if ( V_31 != - V_164 || V_295 != - V_164 )
V_31 = 0 ;
V_81:
F_56 ( V_66 ) ;
if ( V_12 -> V_293 . V_24 == V_296 )
F_8 ( V_31 > 0 ) ;
return V_31 ;
}
static int F_244 ( struct V_123 * V_124 ,
struct V_63 * V_12 ,
struct V_67 * V_297 ,
int V_298 , int V_299 )
{
struct V_14 * V_36 = V_12 -> V_36 ;
T_2 V_29 ;
T_2 V_37 ;
T_2 V_19 ;
T_2 V_229 ;
T_3 V_72 ;
struct V_69 V_23 ;
struct V_300 * V_301 ;
int V_42 ;
int V_179 ;
int V_31 = 0 ;
int (* F_245)( struct V_123 * ,
struct V_14 * ,
T_2 , T_2 , T_2 , T_2 , T_2 , T_2 );
if ( F_246 ( V_36 ) )
return 0 ;
V_229 = F_247 ( V_297 ) ;
V_72 = F_42 ( V_297 ) ;
V_179 = F_248 ( V_297 ) ;
if ( ! F_231 ( V_302 , & V_12 -> V_303 ) && V_179 == 0 )
return 0 ;
if ( V_299 )
F_245 = F_163 ;
else
F_245 = V_304 ;
if ( V_298 )
V_19 = V_297 -> V_34 ;
else
V_19 = 0 ;
for ( V_42 = 0 ; V_42 < V_72 ; V_42 ++ ) {
if ( V_179 == 0 ) {
F_44 ( V_297 , & V_23 , V_42 ) ;
if ( V_23 . type != V_305 )
continue;
V_301 = F_91 ( V_297 , V_42 ,
struct V_300 ) ;
if ( F_249 ( V_297 , V_301 ) ==
V_306 )
continue;
V_29 = F_250 ( V_297 , V_301 ) ;
if ( V_29 == 0 )
continue;
V_37 = F_251 ( V_297 , V_301 ) ;
V_23 . V_35 -= F_252 ( V_297 , V_301 ) ;
V_31 = F_245 ( V_124 , V_36 , V_29 , V_37 ,
V_19 , V_229 , V_23 . V_24 ,
V_23 . V_35 ) ;
if ( V_31 )
goto V_168;
} else {
V_29 = F_253 ( V_297 , V_42 ) ;
V_37 = V_36 -> V_54 ;
V_31 = F_245 ( V_124 , V_36 , V_29 , V_37 ,
V_19 , V_229 , V_179 - 1 , 0 ) ;
if ( V_31 )
goto V_168;
}
}
return 0 ;
V_168:
return V_31 ;
}
int F_254 ( struct V_123 * V_124 , struct V_63 * V_12 ,
struct V_67 * V_297 , int V_298 )
{
return F_244 ( V_124 , V_12 , V_297 , V_298 , 1 ) ;
}
int F_255 ( struct V_123 * V_124 , struct V_63 * V_12 ,
struct V_67 * V_297 , int V_298 )
{
return F_244 ( V_124 , V_12 , V_297 , V_298 , 0 ) ;
}
static int F_256 ( struct V_123 * V_124 ,
struct V_14 * V_36 ,
struct V_65 * V_66 ,
struct V_1 * V_2 )
{
int V_31 ;
struct V_63 * V_64 = V_36 -> V_64 ;
unsigned long V_151 ;
struct V_67 * V_68 ;
V_31 = F_41 ( V_124 , V_64 , & V_2 -> V_23 , V_66 , 0 , 1 ) ;
if ( V_31 ) {
if ( V_31 > 0 )
V_31 = - V_164 ;
goto V_168;
}
V_68 = V_66 -> V_82 [ 0 ] ;
V_151 = F_257 ( V_68 , V_66 -> V_83 [ 0 ] ) ;
F_258 ( V_68 , & V_2 -> V_95 , V_151 , sizeof( V_2 -> V_95 ) ) ;
F_108 ( V_68 ) ;
V_168:
F_48 ( V_66 ) ;
return V_31 ;
}
static struct V_1 *
F_259 ( struct V_14 * V_36 ,
struct V_1 * V_2 )
{
struct V_17 * V_142 ;
F_12 ( & V_36 -> V_20 ) ;
if ( F_260 ( & V_2 -> V_22 ) ) {
const T_2 V_307 = V_2 -> V_23 . V_24 + V_2 -> V_23 . V_35 ;
F_14 ( & V_36 -> V_20 ) ;
F_6 ( V_2 ) ;
V_2 = F_78 ( V_36 , V_307 ) ; return V_2 ;
}
V_142 = F_234 ( & V_2 -> V_22 ) ;
F_6 ( V_2 ) ;
if ( V_142 ) {
V_2 = F_13 ( V_142 , struct V_1 ,
V_22 ) ;
F_4 ( V_2 ) ;
} else
V_2 = NULL ;
F_14 ( & V_36 -> V_20 ) ;
return V_2 ;
}
static int F_261 ( struct V_1 * V_16 ,
struct V_123 * V_124 ,
struct V_65 * V_66 )
{
struct V_14 * V_36 = V_16 -> V_36 ;
struct V_63 * V_12 = V_36 -> V_281 ;
struct V_308 * V_308 = NULL ;
struct V_309 * V_310 = NULL ;
T_2 V_311 = 0 ;
int V_312 = V_313 ;
T_2 V_314 = 0 ;
int V_315 = 0 ;
int V_31 = 0 ;
if ( V_16 -> V_23 . V_35 < ( 100 * V_316 ) ) {
F_12 ( & V_16 -> V_50 ) ;
V_16 -> V_317 = V_318 ;
F_14 ( & V_16 -> V_50 ) ;
return 0 ;
}
if ( V_124 -> V_233 )
return 0 ;
V_167:
V_308 = F_262 ( V_36 , V_16 , V_66 ) ;
if ( F_222 ( V_308 ) && F_223 ( V_308 ) != - V_164 ) {
V_31 = F_223 ( V_308 ) ;
F_48 ( V_66 ) ;
goto V_81;
}
if ( F_222 ( V_308 ) ) {
F_35 ( V_315 ) ;
V_315 ++ ;
if ( V_16 -> V_319 )
goto V_137;
V_31 = F_263 ( V_36 , V_124 , V_16 ,
V_66 ) ;
if ( V_31 )
goto V_137;
goto V_167;
}
if ( V_16 -> V_320 == V_124 -> V_280 &&
F_264 ( V_308 ) ) {
V_312 = V_321 ;
goto V_322;
}
F_265 ( V_308 ) -> V_323 = 0 ;
V_31 = F_266 ( V_124 , V_12 , V_308 ) ;
if ( V_31 ) {
F_167 ( V_124 , V_31 ) ;
goto V_322;
}
F_8 ( V_31 ) ;
if ( F_264 ( V_308 ) > 0 ) {
V_31 = F_267 ( V_36 ,
& V_36 -> V_272 ) ;
if ( V_31 )
goto V_322;
V_31 = F_268 ( V_124 , NULL , V_308 ) ;
if ( V_31 )
goto V_322;
}
F_12 ( & V_16 -> V_50 ) ;
if ( V_16 -> V_3 != V_4 ||
! F_269 ( V_36 , V_324 ) ) {
V_312 = V_318 ;
F_14 ( & V_16 -> V_50 ) ;
goto V_322;
}
F_14 ( & V_16 -> V_50 ) ;
if ( F_231 ( V_325 , & V_124 -> V_141 -> V_7 ) ) {
V_31 = - V_326 ;
goto V_322;
}
V_314 = F_208 ( V_16 -> V_23 . V_35 , V_327 ) ;
if ( ! V_314 )
V_314 = 1 ;
V_314 *= 16 ;
V_314 *= V_328 ;
V_31 = F_270 ( V_308 , & V_310 , 0 , V_314 ) ;
if ( V_31 )
goto V_322;
V_31 = F_271 ( V_308 , V_124 , 0 , 0 , V_314 ,
V_314 , V_314 ,
& V_311 ) ;
if ( ! V_31 )
V_312 = V_321 ;
else if ( V_31 == - V_326 )
F_272 ( V_325 , & V_124 -> V_141 -> V_7 ) ;
V_322:
F_273 ( V_308 ) ;
V_137:
F_48 ( V_66 ) ;
V_81:
F_12 ( & V_16 -> V_50 ) ;
if ( ! V_31 && V_312 == V_321 )
V_16 -> V_320 = V_124 -> V_280 ;
V_16 -> V_317 = V_312 ;
F_14 ( & V_16 -> V_50 ) ;
F_274 ( V_310 ) ;
return V_31 ;
}
int F_275 ( struct V_123 * V_124 ,
struct V_14 * V_36 )
{
struct V_1 * V_2 , * V_329 ;
struct V_290 * V_291 = V_124 -> V_141 ;
struct V_65 * V_66 ;
if ( F_188 ( & V_291 -> V_330 ) ||
! F_269 ( V_36 , V_324 ) )
return 0 ;
V_66 = F_37 () ;
if ( ! V_66 )
return - V_74 ;
F_276 (cache, tmp, &cur_trans->dirty_bgs,
dirty_list) {
if ( V_2 -> V_317 == V_331 )
F_261 ( V_2 , V_124 , V_66 ) ;
}
F_56 ( V_66 ) ;
return 0 ;
}
int F_277 ( struct V_123 * V_124 ,
struct V_14 * V_36 )
{
struct V_1 * V_2 ;
struct V_290 * V_291 = V_124 -> V_141 ;
int V_31 = 0 ;
int V_332 ;
struct V_65 * V_66 = NULL ;
F_278 ( V_333 ) ;
struct V_111 * V_334 = & V_291 -> V_335 ;
int V_336 = 0 ;
int V_337 = 0 ;
F_12 ( & V_291 -> V_338 ) ;
if ( F_188 ( & V_291 -> V_330 ) ) {
F_14 ( & V_291 -> V_338 ) ;
return 0 ;
}
F_279 ( & V_291 -> V_330 , & V_333 ) ;
F_14 ( & V_291 -> V_338 ) ;
V_167:
F_233 ( V_124 , V_36 ) ;
if ( ! V_66 ) {
V_66 = F_37 () ;
if ( ! V_66 )
return - V_74 ;
}
F_52 ( & V_124 -> V_141 -> V_339 ) ;
while ( ! F_188 ( & V_333 ) ) {
V_2 = F_189 ( & V_333 ,
struct V_1 ,
V_340 ) ;
if ( ! F_188 ( & V_2 -> V_341 ) ) {
F_280 ( & V_2 -> V_341 ) ;
F_281 ( V_124 , V_2 , V_66 ) ;
F_6 ( V_2 ) ;
}
F_12 ( & V_291 -> V_338 ) ;
F_280 ( & V_2 -> V_340 ) ;
F_14 ( & V_291 -> V_338 ) ;
V_332 = 1 ;
F_261 ( V_2 , V_124 , V_66 ) ;
if ( V_2 -> V_317 == V_321 ) {
V_2 -> V_342 . V_308 = NULL ;
V_31 = F_282 ( V_36 , V_124 ,
V_2 , V_66 ) ;
if ( V_31 == 0 && V_2 -> V_342 . V_308 ) {
V_336 ++ ;
V_332 = 0 ;
F_75 ( & V_2 -> V_341 , V_334 ) ;
} else {
V_31 = 0 ;
}
}
if ( ! V_31 ) {
V_31 = F_256 ( V_124 , V_36 ,
V_66 , V_2 ) ;
if ( V_31 == - V_164 ) {
V_31 = 0 ;
F_12 ( & V_291 -> V_338 ) ;
if ( F_188 ( & V_2 -> V_340 ) ) {
F_75 ( & V_2 -> V_340 ,
& V_291 -> V_330 ) ;
F_4 ( V_2 ) ;
}
F_14 ( & V_291 -> V_338 ) ;
} else if ( V_31 ) {
F_167 ( V_124 , V_31 ) ;
}
}
if ( V_332 )
F_6 ( V_2 ) ;
if ( V_31 )
break;
F_50 ( & V_124 -> V_141 -> V_339 ) ;
F_52 ( & V_124 -> V_141 -> V_339 ) ;
}
F_50 ( & V_124 -> V_141 -> V_339 ) ;
V_31 = F_224 ( V_124 , V_36 , 0 ) ;
if ( ! V_31 && V_337 == 0 ) {
V_337 ++ ;
F_12 ( & V_291 -> V_338 ) ;
F_279 ( & V_291 -> V_330 , & V_333 ) ;
if ( ! F_188 ( & V_333 ) ) {
F_14 ( & V_291 -> V_338 ) ;
goto V_167;
}
F_14 ( & V_291 -> V_338 ) ;
} else if ( V_31 < 0 ) {
F_283 ( V_291 , V_36 ) ;
}
F_56 ( V_66 ) ;
return V_31 ;
}
int F_284 ( struct V_123 * V_124 ,
struct V_14 * V_36 )
{
struct V_1 * V_2 ;
struct V_290 * V_291 = V_124 -> V_141 ;
int V_31 = 0 ;
int V_332 ;
struct V_65 * V_66 ;
struct V_111 * V_334 = & V_291 -> V_335 ;
int V_336 = 0 ;
V_66 = F_37 () ;
if ( ! V_66 )
return - V_74 ;
F_12 ( & V_291 -> V_338 ) ;
while ( ! F_188 ( & V_291 -> V_330 ) ) {
V_2 = F_189 ( & V_291 -> V_330 ,
struct V_1 ,
V_340 ) ;
if ( ! F_188 ( & V_2 -> V_341 ) ) {
F_14 ( & V_291 -> V_338 ) ;
F_280 ( & V_2 -> V_341 ) ;
F_281 ( V_124 , V_2 , V_66 ) ;
F_6 ( V_2 ) ;
F_12 ( & V_291 -> V_338 ) ;
}
F_280 ( & V_2 -> V_340 ) ;
F_14 ( & V_291 -> V_338 ) ;
V_332 = 1 ;
F_261 ( V_2 , V_124 , V_66 ) ;
if ( ! V_31 )
V_31 = F_224 ( V_124 , V_36 ,
( unsigned long ) - 1 ) ;
if ( ! V_31 && V_2 -> V_317 == V_321 ) {
V_2 -> V_342 . V_308 = NULL ;
V_31 = F_282 ( V_36 , V_124 ,
V_2 , V_66 ) ;
if ( V_31 == 0 && V_2 -> V_342 . V_308 ) {
V_336 ++ ;
V_332 = 0 ;
F_75 ( & V_2 -> V_341 , V_334 ) ;
} else {
V_31 = 0 ;
}
}
if ( ! V_31 ) {
V_31 = F_256 ( V_124 , V_36 ,
V_66 , V_2 ) ;
if ( V_31 == - V_164 ) {
F_285 ( V_291 -> V_343 ,
F_217 ( & V_291 -> V_344 ) == 1 ) ;
V_31 = F_256 ( V_124 , V_36 ,
V_66 , V_2 ) ;
}
if ( V_31 )
F_167 ( V_124 , V_31 ) ;
}
if ( V_332 )
F_6 ( V_2 ) ;
F_12 ( & V_291 -> V_338 ) ;
}
F_14 ( & V_291 -> V_338 ) ;
while ( ! F_188 ( V_334 ) ) {
V_2 = F_189 ( V_334 , struct V_1 ,
V_341 ) ;
F_280 ( & V_2 -> V_341 ) ;
F_281 ( V_124 , V_2 , V_66 ) ;
F_6 ( V_2 ) ;
}
F_56 ( V_66 ) ;
return V_31 ;
}
int F_286 ( struct V_14 * V_36 , T_2 V_29 )
{
struct V_1 * V_16 ;
int V_345 = 0 ;
V_16 = F_79 ( V_36 , V_29 ) ;
if ( ! V_16 || V_16 -> V_319 )
V_345 = 1 ;
if ( V_16 )
F_6 ( V_16 ) ;
return V_345 ;
}
bool F_287 ( struct V_14 * V_36 , T_2 V_29 )
{
struct V_1 * V_346 ;
bool V_31 = true ;
V_346 = F_79 ( V_36 , V_29 ) ;
if ( ! V_346 )
return false ;
F_12 ( & V_346 -> V_50 ) ;
if ( V_346 -> V_319 )
V_31 = false ;
else
F_5 ( & V_346 -> V_347 ) ;
F_14 ( & V_346 -> V_50 ) ;
if ( ! V_31 )
F_6 ( V_346 ) ;
return V_31 ;
}
void F_288 ( struct V_14 * V_36 , T_2 V_29 )
{
struct V_1 * V_346 ;
V_346 = F_79 ( V_36 , V_29 ) ;
ASSERT ( V_346 ) ;
if ( F_7 ( & V_346 -> V_347 ) )
F_289 ( & V_346 -> V_347 ) ;
F_6 ( V_346 ) ;
F_6 ( V_346 ) ;
}
static int F_290 ( T_8 * V_348 )
{
F_71 () ;
return 0 ;
}
void F_291 ( struct V_1 * V_346 )
{
F_292 ( & V_346 -> V_347 ,
F_290 ,
V_101 ) ;
}
static const char * F_293 ( T_2 V_7 )
{
switch ( V_7 ) {
case V_53 | V_120 :
return L_4 ;
case V_53 :
return L_5 ;
case V_120 :
return L_6 ;
case V_119 :
return L_7 ;
default:
F_8 ( 1 ) ;
return L_8 ;
} ;
}
static int F_294 ( struct V_14 * V_15 , T_2 V_7 ,
struct V_110 * * V_349 )
{
struct V_110 * V_94 ;
int V_42 ;
int V_31 ;
V_94 = F_64 ( sizeof( * V_94 ) , V_97 ) ;
if ( ! V_94 )
return - V_74 ;
V_31 = F_295 ( & V_94 -> V_121 , 0 ,
V_350 ) ;
if ( V_31 ) {
F_10 ( V_94 ) ;
return V_31 ;
}
for ( V_42 = 0 ; V_42 < V_351 ; V_42 ++ )
F_65 ( & V_94 -> V_352 [ V_42 ] ) ;
F_296 ( & V_94 -> V_353 ) ;
F_297 ( & V_94 -> V_50 ) ;
V_94 -> V_7 = V_7 & V_114 ;
V_94 -> V_354 = V_355 ;
F_67 ( & V_94 -> V_89 ) ;
F_65 ( & V_94 -> V_356 ) ;
F_65 ( & V_94 -> V_357 ) ;
F_65 ( & V_94 -> V_358 ) ;
V_31 = F_298 ( & V_94 -> V_359 , & V_360 ,
V_15 -> V_361 , L_9 ,
F_293 ( V_94 -> V_7 ) ) ;
if ( V_31 ) {
F_299 ( & V_94 -> V_121 ) ;
F_10 ( V_94 ) ;
return V_31 ;
}
* V_349 = V_94 ;
F_300 ( & V_94 -> V_98 , & V_15 -> V_94 ) ;
if ( V_7 & V_120 )
V_15 -> V_362 = V_94 ;
return V_31 ;
}
static void F_301 ( struct V_14 * V_15 , T_2 V_7 ,
T_2 V_363 , T_2 V_93 ,
T_2 V_364 ,
struct V_110 * * V_94 )
{
struct V_110 * V_113 ;
int V_365 ;
if ( V_7 & ( V_366 | V_367 |
V_368 ) )
V_365 = 2 ;
else
V_365 = 1 ;
V_113 = F_80 ( V_15 , V_7 ) ;
ASSERT ( V_113 ) ;
F_12 ( & V_113 -> V_50 ) ;
V_113 -> V_363 += V_363 ;
V_113 -> V_369 += V_363 * V_365 ;
V_113 -> V_93 += V_93 ;
V_113 -> V_370 += V_93 * V_365 ;
V_113 -> V_364 += V_364 ;
if ( V_363 > 0 )
V_113 -> V_122 = 0 ;
F_302 ( V_15 , V_113 , V_363 -
V_93 - V_364 ) ;
F_14 ( & V_113 -> V_50 ) ;
* V_94 = V_113 ;
}
static void F_303 ( struct V_14 * V_36 , T_2 V_7 )
{
T_2 V_371 = F_304 ( V_7 ) &
V_372 ;
F_305 ( & V_36 -> V_373 ) ;
if ( V_7 & V_120 )
V_36 -> V_374 |= V_371 ;
if ( V_7 & V_53 )
V_36 -> V_375 |= V_371 ;
if ( V_7 & V_119 )
V_36 -> V_376 |= V_371 ;
F_306 ( & V_36 -> V_373 ) ;
}
static T_2 F_307 ( struct V_14 * V_36 , T_2 V_7 )
{
struct V_377 * V_378 = V_36 -> V_379 ;
T_2 V_380 = 0 ;
if ( ! V_378 )
return 0 ;
if ( V_7 & V_120 &&
V_378 -> V_381 . V_7 & V_382 ) {
V_380 = V_120 | V_378 -> V_381 . V_380 ;
} else if ( V_7 & V_119 &&
V_378 -> V_383 . V_7 & V_382 ) {
V_380 = V_119 | V_378 -> V_383 . V_380 ;
} else if ( V_7 & V_53 &&
V_378 -> V_384 . V_7 & V_382 ) {
V_380 = V_53 | V_378 -> V_384 . V_380 ;
}
return V_380 ;
}
static T_2 F_308 ( struct V_14 * V_36 , T_2 V_7 )
{
T_2 V_385 = V_36 -> V_386 -> V_387 ;
T_2 V_380 ;
T_2 V_388 ;
T_2 V_389 = 0 ;
F_12 ( & V_36 -> V_390 ) ;
V_380 = F_307 ( V_36 , V_7 ) ;
if ( V_380 ) {
if ( ( V_7 & V_380 ) & V_372 ) {
F_14 ( & V_36 -> V_390 ) ;
return F_309 ( V_380 ) ;
}
}
F_14 ( & V_36 -> V_390 ) ;
for ( V_388 = 0 ; V_388 < V_351 ; V_388 ++ ) {
if ( V_385 >= V_391 [ V_388 ] . V_392 )
V_389 |= V_393 [ V_388 ] ;
}
V_389 &= V_7 ;
if ( V_389 & V_394 )
V_389 = V_394 ;
else if ( V_389 & V_395 )
V_389 = V_395 ;
else if ( V_389 & V_368 )
V_389 = V_368 ;
else if ( V_389 & V_367 )
V_389 = V_367 ;
else if ( V_389 & V_396 )
V_389 = V_396 ;
V_7 &= ~ V_397 ;
return F_309 ( V_7 | V_389 ) ;
}
static T_2 F_310 ( struct V_14 * V_36 , T_2 V_398 )
{
unsigned V_244 ;
T_2 V_7 ;
do {
V_7 = V_398 ;
V_244 = F_311 ( & V_36 -> V_373 ) ;
if ( V_7 & V_120 )
V_7 |= V_36 -> V_374 ;
else if ( V_7 & V_119 )
V_7 |= V_36 -> V_376 ;
else if ( V_7 & V_53 )
V_7 |= V_36 -> V_375 ;
} while ( F_312 ( & V_36 -> V_373 , V_244 ) );
return F_308 ( V_36 , V_7 ) ;
}
static T_2 F_313 ( struct V_63 * V_12 , int V_381 )
{
struct V_14 * V_36 = V_12 -> V_36 ;
T_2 V_7 ;
T_2 V_31 ;
if ( V_381 )
V_7 = V_120 ;
else if ( V_12 == V_36 -> V_399 )
V_7 = V_119 ;
else
V_7 = V_53 ;
V_31 = F_310 ( V_36 , V_7 ) ;
return V_31 ;
}
T_2 F_314 ( struct V_14 * V_36 )
{
return F_310 ( V_36 , V_120 ) ;
}
T_2 F_315 ( struct V_14 * V_36 )
{
return F_310 ( V_36 , V_53 ) ;
}
T_2 F_316 ( struct V_14 * V_36 )
{
return F_310 ( V_36 , V_119 ) ;
}
static T_2 F_317 ( struct V_110 * V_400 ,
bool V_401 )
{
ASSERT ( V_400 ) ;
return V_400 -> V_93 + V_400 -> V_402 +
V_400 -> V_403 + V_400 -> V_364 +
( V_401 ? V_400 -> V_404 : 0 ) ;
}
int F_318 ( struct V_405 * V_308 , T_2 V_215 )
{
struct V_110 * V_362 ;
struct V_63 * V_12 = V_308 -> V_12 ;
struct V_14 * V_36 = V_12 -> V_36 ;
T_2 V_406 ;
int V_31 = 0 ;
int V_407 = 2 ;
int V_408 ;
V_215 = F_154 ( V_215 , V_36 -> V_55 ) ;
if ( F_319 ( V_308 ) ) {
V_407 = 0 ;
ASSERT ( V_409 -> V_410 ) ;
}
V_362 = V_36 -> V_362 ;
if ( ! V_362 )
goto V_411;
V_167:
F_12 ( & V_362 -> V_50 ) ;
V_406 = F_317 ( V_362 , true ) ;
if ( V_406 + V_215 > V_362 -> V_363 ) {
struct V_123 * V_124 ;
if ( ! V_362 -> V_122 ) {
T_2 V_412 ;
V_362 -> V_354 = V_413 ;
F_14 ( & V_362 -> V_50 ) ;
V_411:
V_412 = F_314 ( V_36 ) ;
V_124 = F_221 ( V_12 ) ;
if ( F_222 ( V_124 ) )
return F_223 ( V_124 ) ;
V_31 = F_320 ( V_124 , V_36 , V_412 ,
V_355 ) ;
F_225 ( V_124 ) ;
if ( V_31 < 0 ) {
if ( V_31 != - V_326 )
return V_31 ;
else {
V_408 = 1 ;
goto V_414;
}
}
if ( ! V_362 )
V_362 = V_36 -> V_362 ;
goto V_167;
}
V_408 = F_321 (
& V_362 -> V_121 ,
V_406 + V_215 - V_362 -> V_363 ) ;
F_14 ( & V_362 -> V_50 ) ;
V_414:
if ( V_407 &&
! F_217 ( & V_36 -> V_415 ) ) {
V_407 -- ;
if ( V_407 > 0 ) {
F_322 ( V_36 , 0 , - 1 ) ;
F_323 ( V_36 , V_416 , 0 ,
( T_2 ) - 1 ) ;
}
V_124 = F_221 ( V_12 ) ;
if ( F_222 ( V_124 ) )
return F_223 ( V_124 ) ;
if ( V_408 >= 0 ||
F_231 ( V_417 ,
& V_124 -> V_141 -> V_7 ) ||
V_407 > 0 ) {
V_31 = F_324 ( V_124 ) ;
if ( V_31 )
return V_31 ;
F_52 ( & V_36 -> V_418 ) ;
F_50 ( & V_36 -> V_418 ) ;
goto V_167;
} else {
F_225 ( V_124 ) ;
}
}
F_325 ( V_36 ,
L_10 ,
V_362 -> V_7 , V_215 , 1 ) ;
return - V_326 ;
}
V_362 -> V_404 += V_215 ;
F_325 ( V_36 , L_11 ,
V_362 -> V_7 , V_215 , 1 ) ;
F_14 ( & V_362 -> V_50 ) ;
return V_31 ;
}
int F_270 ( struct V_308 * V_308 ,
struct V_309 * * V_10 , T_2 V_34 , T_2 V_47 )
{
struct V_14 * V_36 = F_326 ( V_308 -> V_419 ) ;
int V_31 ;
V_47 = F_327 ( V_34 + V_47 , V_36 -> V_55 ) -
F_155 ( V_34 , V_36 -> V_55 ) ;
V_34 = F_155 ( V_34 , V_36 -> V_55 ) ;
V_31 = F_318 ( F_265 ( V_308 ) , V_47 ) ;
if ( V_31 < 0 )
return V_31 ;
V_31 = F_328 ( V_308 , V_10 , V_34 , V_47 ) ;
if ( V_31 < 0 )
F_329 ( V_308 , V_34 , V_47 ) ;
else
V_31 = 0 ;
return V_31 ;
}
void F_329 ( struct V_308 * V_308 , T_2 V_34 ,
T_2 V_47 )
{
struct V_14 * V_36 = F_326 ( V_308 -> V_419 ) ;
struct V_110 * V_362 ;
V_47 = F_327 ( V_34 + V_47 , V_36 -> V_55 ) -
F_155 ( V_34 , V_36 -> V_55 ) ;
V_34 = F_155 ( V_34 , V_36 -> V_55 ) ;
V_362 = V_36 -> V_362 ;
F_12 ( & V_362 -> V_50 ) ;
if ( F_8 ( V_362 -> V_404 < V_47 ) )
V_362 -> V_404 = 0 ;
else
V_362 -> V_404 -= V_47 ;
F_325 ( V_36 , L_11 ,
V_362 -> V_7 , V_47 , 0 ) ;
F_14 ( & V_362 -> V_50 ) ;
}
void F_330 ( struct V_308 * V_308 ,
struct V_309 * V_10 , T_2 V_34 , T_2 V_47 )
{
struct V_63 * V_12 = F_265 ( V_308 ) -> V_12 ;
V_47 = F_327 ( V_34 + V_47 , V_12 -> V_36 -> V_55 ) -
F_155 ( V_34 , V_12 -> V_36 -> V_55 ) ;
V_34 = F_155 ( V_34 , V_12 -> V_36 -> V_55 ) ;
F_329 ( V_308 , V_34 , V_47 ) ;
F_331 ( V_308 , V_10 , V_34 , V_47 ) ;
}
static void F_332 ( struct V_14 * V_15 )
{
struct V_111 * V_112 = & V_15 -> V_94 ;
struct V_110 * V_113 ;
F_81 () ;
F_82 (found, head, list) {
if ( V_113 -> V_7 & V_53 )
V_113 -> V_354 = V_413 ;
}
F_83 () ;
}
static inline T_2 F_333 ( struct V_268 * V_420 )
{
return ( V_420 -> V_59 << 1 ) ;
}
static int F_334 ( struct V_14 * V_36 ,
struct V_110 * V_421 , int V_422 )
{
struct V_268 * V_269 = & V_36 -> V_272 ;
T_2 V_37 = V_421 -> V_363 - V_421 -> V_364 ;
T_2 V_423 = V_421 -> V_93 + V_421 -> V_402 ;
T_2 V_424 ;
if ( V_422 == V_413 )
return 1 ;
if ( V_421 -> V_7 & V_53 )
V_423 += F_333 ( V_269 ) ;
if ( V_422 == V_425 ) {
V_424 = F_335 ( V_36 -> V_267 ) ;
V_424 = F_38 ( T_2 , V_426 , F_336 ( V_424 , 1 ) ) ;
if ( V_37 - V_423 < V_424 )
return 1 ;
}
if ( V_423 + V_427 < F_337 ( V_37 , 8 ) )
return 0 ;
return 1 ;
}
static T_2 F_338 ( struct V_14 * V_36 , T_2 type )
{
T_2 V_428 ;
if ( type & ( V_368 |
V_396 |
V_395 |
V_394 ) )
V_428 = V_36 -> V_386 -> V_387 ;
else if ( type & V_367 )
V_428 = 2 ;
else
V_428 = 1 ;
return V_428 ;
}
void F_339 ( struct V_123 * V_124 ,
struct V_14 * V_36 , T_2 type )
{
struct V_110 * V_15 ;
T_2 V_429 ;
T_2 V_424 ;
int V_31 = 0 ;
T_2 V_430 ;
ASSERT ( F_340 ( & V_36 -> V_431 ) ) ;
V_15 = F_80 ( V_36 , V_119 ) ;
F_12 ( & V_15 -> V_50 ) ;
V_429 = V_15 -> V_363 - F_317 ( V_15 , true ) ;
F_14 ( & V_15 -> V_50 ) ;
V_430 = F_338 ( V_36 , type ) ;
V_424 = F_341 ( V_36 , V_430 ) +
F_215 ( V_36 , 1 ) ;
if ( V_429 < V_424 && F_269 ( V_36 , V_432 ) ) {
F_342 ( V_36 , L_12 ,
V_429 , V_424 , type ) ;
F_343 ( V_36 , V_15 , 0 , 0 ) ;
}
if ( V_429 < V_424 ) {
T_2 V_7 = F_316 ( V_36 ) ;
V_31 = F_344 ( V_124 , V_36 , V_7 ) ;
}
if ( ! V_31 ) {
V_31 = F_345 ( V_36 -> V_399 ,
& V_36 -> V_433 ,
V_424 , V_434 ) ;
if ( ! V_31 )
V_124 -> V_435 += V_424 ;
}
}
static int F_320 ( struct V_123 * V_124 ,
struct V_14 * V_36 , T_2 V_7 , int V_422 )
{
struct V_110 * V_94 ;
int V_436 = 0 ;
int V_31 = 0 ;
if ( V_124 -> V_437 )
return - V_326 ;
V_94 = F_80 ( V_36 , V_7 ) ;
if ( ! V_94 ) {
V_31 = F_294 ( V_36 , V_7 , & V_94 ) ;
if ( V_31 )
return V_31 ;
}
V_167:
F_12 ( & V_94 -> V_50 ) ;
if ( V_422 < V_94 -> V_354 )
V_422 = V_94 -> V_354 ;
if ( V_94 -> V_122 ) {
if ( F_334 ( V_36 , V_94 , V_422 ) )
V_31 = - V_326 ;
else
V_31 = 0 ;
F_14 ( & V_94 -> V_50 ) ;
return V_31 ;
}
if ( ! F_334 ( V_36 , V_94 , V_422 ) ) {
F_14 ( & V_94 -> V_50 ) ;
return 0 ;
} else if ( V_94 -> V_438 ) {
V_436 = 1 ;
} else {
V_94 -> V_438 = 1 ;
}
F_14 ( & V_94 -> V_50 ) ;
F_52 ( & V_36 -> V_431 ) ;
if ( V_436 ) {
F_50 ( & V_36 -> V_431 ) ;
V_436 = 0 ;
goto V_167;
}
V_124 -> V_437 = true ;
if ( F_346 ( V_94 ) )
V_7 |= ( V_120 | V_53 ) ;
if ( V_7 & V_120 && V_36 -> V_439 ) {
V_36 -> V_440 ++ ;
if ( ! ( V_36 -> V_440 %
V_36 -> V_439 ) )
F_332 ( V_36 ) ;
}
F_339 ( V_124 , V_36 , V_7 ) ;
V_31 = F_344 ( V_124 , V_36 , V_7 ) ;
V_124 -> V_437 = false ;
F_12 ( & V_94 -> V_50 ) ;
if ( V_31 < 0 && V_31 != - V_326 )
goto V_81;
if ( V_31 )
V_94 -> V_122 = 1 ;
else
V_31 = 1 ;
V_94 -> V_354 = V_355 ;
V_81:
V_94 -> V_438 = 0 ;
F_14 ( & V_94 -> V_50 ) ;
F_50 ( & V_36 -> V_431 ) ;
if ( V_124 -> V_285 &&
V_124 -> V_435 >= ( T_2 ) V_427 ) {
F_233 ( V_124 , V_36 ) ;
F_347 ( V_124 ) ;
}
return V_31 ;
}
static int F_348 ( struct V_14 * V_36 ,
struct V_110 * V_94 , T_2 V_215 ,
enum V_441 V_442 ,
bool V_443 )
{
struct V_268 * V_269 = & V_36 -> V_272 ;
T_2 V_444 ;
T_2 V_445 ;
T_2 V_446 ;
T_2 V_406 ;
if ( V_94 -> V_7 & V_120 )
return 0 ;
if ( V_443 )
V_444 = F_316 ( V_36 ) ;
else
V_444 = F_315 ( V_36 ) ;
V_406 = F_317 ( V_94 , false ) ;
F_12 ( & V_269 -> V_50 ) ;
V_445 = F_333 ( V_269 ) ;
F_14 ( & V_269 -> V_50 ) ;
if ( V_406 + V_445 >= V_94 -> V_363 )
return 0 ;
V_406 += V_94 -> V_404 ;
V_446 = F_349 ( & V_36 -> V_447 ) ;
if ( V_444 & ( V_366 |
V_367 |
V_368 ) )
V_446 >>= 1 ;
if ( V_442 == V_448 )
V_446 >>= 3 ;
else
V_446 >>= 1 ;
if ( V_406 + V_215 < V_94 -> V_363 + V_446 )
return 1 ;
return 0 ;
}
static void F_350 ( struct V_14 * V_36 ,
unsigned long V_449 , int V_450 )
{
struct V_451 * V_452 = V_36 -> V_452 ;
if ( F_351 ( & V_452 -> V_453 ) ) {
F_352 ( V_452 , V_449 , V_454 ) ;
F_49 ( & V_452 -> V_453 ) ;
} else {
F_322 ( V_36 , 0 , V_450 ) ;
if ( ! V_409 -> V_410 )
F_323 ( V_36 , V_450 , 0 , ( T_2 ) - 1 ) ;
}
}
static inline T_2 F_353 ( struct V_14 * V_36 ,
T_2 V_455 )
{
T_2 V_215 ;
T_2 V_43 ;
V_215 = F_215 ( V_36 , 1 ) ;
V_43 = F_212 ( V_455 , V_215 ) ;
if ( ! V_43 )
V_43 = 1 ;
return V_43 ;
}
static void F_354 ( struct V_14 * V_36 , T_2 V_455 ,
T_2 V_456 , bool V_457 )
{
struct V_268 * V_458 ;
struct V_110 * V_94 ;
struct V_123 * V_124 ;
T_2 V_459 ;
T_2 V_460 ;
T_2 V_461 ;
long V_462 ;
unsigned long V_449 ;
int V_337 ;
enum V_441 V_442 ;
V_461 = F_353 ( V_36 , V_455 ) ;
V_455 = V_461 * V_463 ;
V_124 = (struct V_123 * ) V_409 -> V_410 ;
V_458 = & V_36 -> V_464 ;
V_94 = V_458 -> V_94 ;
V_459 = F_355 (
& V_36 -> V_459 ) ;
if ( V_459 == 0 ) {
if ( V_124 )
return;
if ( V_457 )
F_323 ( V_36 , V_461 , 0 , ( T_2 ) - 1 ) ;
return;
}
V_337 = 0 ;
while ( V_459 && V_337 < 3 ) {
V_460 = F_356 ( V_459 , V_455 ) ;
V_449 = V_460 >> V_465 ;
F_350 ( V_36 , V_449 , V_461 ) ;
V_460 = F_217 ( & V_36 -> V_466 ) ;
if ( ! V_460 )
goto V_467;
if ( V_460 <= V_449 )
V_460 = 0 ;
else
V_460 -= V_449 ;
F_285 ( V_36 -> V_468 ,
F_217 ( & V_36 -> V_466 ) <=
( int ) V_460 ) ;
V_467:
if ( ! V_124 )
V_442 = V_448 ;
else
V_442 = V_434 ;
F_12 ( & V_94 -> V_50 ) ;
if ( F_188 ( & V_94 -> V_357 ) &&
F_188 ( & V_94 -> V_358 ) ) {
F_14 ( & V_94 -> V_50 ) ;
break;
}
F_14 ( & V_94 -> V_50 ) ;
V_337 ++ ;
if ( V_457 && ! V_124 ) {
F_323 ( V_36 , V_461 , 0 , ( T_2 ) - 1 ) ;
} else {
V_462 = F_357 ( 1 ) ;
if ( V_462 )
break;
}
V_459 = F_355 (
& V_36 -> V_459 ) ;
}
}
static int F_358 ( struct V_14 * V_36 ,
struct V_110 * V_94 ,
T_2 V_215 , int V_422 )
{
struct V_268 * V_469 = & V_36 -> V_470 ;
struct V_123 * V_124 ;
V_124 = (struct V_123 * ) V_409 -> V_410 ;
if ( V_124 )
return - V_190 ;
if ( V_422 )
goto V_471;
if ( F_321 ( & V_94 -> V_121 ,
V_215 ) >= 0 )
goto V_471;
if ( V_94 != V_469 -> V_94 )
return - V_326 ;
F_12 ( & V_469 -> V_50 ) ;
if ( F_321 ( & V_94 -> V_121 ,
V_215 - V_469 -> V_59 ) < 0 ) {
F_14 ( & V_469 -> V_50 ) ;
return - V_326 ;
}
F_14 ( & V_469 -> V_50 ) ;
V_471:
V_124 = F_221 ( V_36 -> V_64 ) ;
if ( F_222 ( V_124 ) )
return - V_326 ;
return F_324 ( V_124 ) ;
}
static int F_359 ( struct V_14 * V_36 ,
struct V_110 * V_94 , T_2 V_37 ,
T_2 V_472 , int V_303 )
{
struct V_63 * V_12 = V_36 -> V_64 ;
struct V_123 * V_124 ;
int V_43 ;
int V_31 = 0 ;
switch ( V_303 ) {
case V_473 :
case V_474 :
if ( V_303 == V_473 )
V_43 = F_353 ( V_36 , V_37 ) * 2 ;
else
V_43 = - 1 ;
V_124 = F_221 ( V_12 ) ;
if ( F_222 ( V_124 ) ) {
V_31 = F_223 ( V_124 ) ;
break;
}
V_31 = F_360 ( V_124 , V_36 , V_43 ) ;
F_225 ( V_124 ) ;
break;
case V_475 :
case V_476 :
F_354 ( V_36 , V_37 * 2 , V_472 ,
V_303 == V_476 ) ;
break;
case V_477 :
V_124 = F_221 ( V_12 ) ;
if ( F_222 ( V_124 ) ) {
V_31 = F_223 ( V_124 ) ;
break;
}
V_31 = F_320 ( V_124 , V_36 ,
F_315 ( V_36 ) ,
V_355 ) ;
F_225 ( V_124 ) ;
if ( V_31 > 0 || V_31 == - V_326 )
V_31 = 0 ;
break;
case V_478 :
V_31 = F_358 ( V_36 , V_94 ,
V_472 , 0 ) ;
break;
default:
V_31 = - V_326 ;
break;
}
F_361 ( V_36 , V_94 -> V_7 , V_37 ,
V_472 , V_303 , V_31 ) ;
return V_31 ;
}
static inline T_2
F_362 ( struct V_14 * V_36 ,
struct V_110 * V_94 ,
bool V_443 )
{
struct V_479 * V_480 ;
T_2 V_406 ;
T_2 V_481 ;
T_2 V_455 = 0 ;
F_239 (ticket, &space_info->tickets, list)
V_455 += V_480 -> V_215 ;
F_239 (ticket, &space_info->priority_tickets, list)
V_455 += V_480 -> V_215 ;
if ( V_455 )
return V_455 ;
V_455 = F_25 ( T_2 , F_363 () * V_316 , V_482 ) ;
if ( F_348 ( V_36 , V_94 , V_455 ,
V_448 , V_443 ) )
return 0 ;
V_406 = F_317 ( V_94 , true ) ;
if ( F_348 ( V_36 , V_94 , V_316 ,
V_448 , V_443 ) )
V_481 = F_336 ( V_94 -> V_363 , 95 ) ;
else
V_481 = F_336 ( V_94 -> V_363 , 90 ) ;
if ( V_406 > V_481 )
V_455 = V_406 - V_481 ;
else
V_455 = 0 ;
V_455 = F_356 ( V_455 , V_94 -> V_404 +
V_94 -> V_402 ) ;
return V_455 ;
}
static inline int F_364 ( struct V_14 * V_36 ,
struct V_110 * V_94 ,
T_2 V_406 , bool V_443 )
{
T_2 V_424 = F_336 ( V_94 -> V_363 , 98 ) ;
if ( ( V_94 -> V_93 + V_94 -> V_402 ) >= V_424 )
return 0 ;
if ( ! F_362 ( V_36 , V_94 ,
V_443 ) )
return 0 ;
return ( V_406 >= V_424 && ! F_43 ( V_36 ) &&
! F_231 ( V_483 , & V_36 -> V_484 ) ) ;
}
static void F_365 ( struct V_111 * V_112 )
{
struct V_479 * V_480 ;
while ( ! F_188 ( V_112 ) ) {
V_480 = F_189 ( V_112 , struct V_479 , V_98 ) ;
F_280 ( & V_480 -> V_98 ) ;
V_480 -> error = - V_326 ;
F_55 ( & V_480 -> V_89 ) ;
}
}
static void F_366 ( struct V_485 * V_91 )
{
struct V_14 * V_36 ;
struct V_110 * V_94 ;
T_2 V_455 ;
int V_486 ;
int V_487 = 0 ;
T_2 V_488 ;
V_36 = F_58 ( V_91 , struct V_14 , V_489 ) ;
V_94 = F_80 ( V_36 , V_53 ) ;
F_12 ( & V_94 -> V_50 ) ;
V_455 = F_362 ( V_36 , V_94 ,
false ) ;
if ( ! V_455 ) {
V_94 -> V_442 = 0 ;
F_14 ( & V_94 -> V_50 ) ;
return;
}
V_488 = V_94 -> V_490 ;
F_14 ( & V_94 -> V_50 ) ;
V_486 = V_473 ;
do {
struct V_479 * V_480 ;
int V_31 ;
V_31 = F_359 ( V_36 , V_94 , V_455 , V_455 ,
V_486 ) ;
F_12 ( & V_94 -> V_50 ) ;
if ( F_188 ( & V_94 -> V_357 ) ) {
V_94 -> V_442 = 0 ;
F_14 ( & V_94 -> V_50 ) ;
return;
}
V_455 = F_362 ( V_36 ,
V_94 ,
false ) ;
V_480 = F_189 ( & V_94 -> V_357 ,
struct V_479 , V_98 ) ;
if ( V_488 == V_94 -> V_490 ) {
V_486 ++ ;
} else {
V_488 = V_94 -> V_490 ;
V_486 = V_473 ;
if ( V_487 )
V_487 -- ;
}
if ( V_486 > V_478 ) {
V_487 ++ ;
if ( V_487 > 2 ) {
F_365 ( & V_94 -> V_357 ) ;
V_94 -> V_442 = 0 ;
} else {
V_486 = V_473 ;
}
}
F_14 ( & V_94 -> V_50 ) ;
} while ( V_486 <= V_478 );
}
void F_367 ( struct V_485 * V_91 )
{
F_368 ( V_91 , F_366 ) ;
}
static void F_369 ( struct V_14 * V_36 ,
struct V_110 * V_94 ,
struct V_479 * V_480 )
{
T_2 V_455 ;
int V_486 = V_473 ;
F_12 ( & V_94 -> V_50 ) ;
V_455 = F_362 ( V_36 , V_94 ,
false ) ;
if ( ! V_455 ) {
F_14 ( & V_94 -> V_50 ) ;
return;
}
F_14 ( & V_94 -> V_50 ) ;
do {
F_359 ( V_36 , V_94 , V_455 , V_455 ,
V_486 ) ;
V_486 ++ ;
F_12 ( & V_94 -> V_50 ) ;
if ( V_480 -> V_215 == 0 ) {
F_14 ( & V_94 -> V_50 ) ;
return;
}
F_14 ( & V_94 -> V_50 ) ;
if ( V_486 == V_475 ||
V_486 == V_476 )
V_486 = V_477 ;
} while ( V_486 < V_478 );
}
static int F_370 ( struct V_14 * V_36 ,
struct V_110 * V_94 ,
struct V_479 * V_480 , T_2 V_472 )
{
F_63 ( V_89 ) ;
int V_31 = 0 ;
F_12 ( & V_94 -> V_50 ) ;
while ( V_480 -> V_215 > 0 && V_480 -> error == 0 ) {
V_31 = F_371 ( & V_480 -> V_89 , & V_89 , V_491 ) ;
if ( V_31 ) {
V_31 = - V_492 ;
break;
}
F_14 ( & V_94 -> V_50 ) ;
F_71 () ;
F_72 ( & V_480 -> V_89 , & V_89 ) ;
F_12 ( & V_94 -> V_50 ) ;
}
if ( ! V_31 )
V_31 = V_480 -> error ;
if ( ! F_188 ( & V_480 -> V_98 ) )
F_280 ( & V_480 -> V_98 ) ;
if ( V_480 -> V_215 && V_480 -> V_215 < V_472 ) {
T_2 V_37 = V_472 - V_480 -> V_215 ;
V_94 -> V_404 -= V_37 ;
F_325 ( V_36 , L_11 ,
V_94 -> V_7 , V_37 , 0 ) ;
}
F_14 ( & V_94 -> V_50 ) ;
return V_31 ;
}
static int F_372 ( struct V_14 * V_36 ,
struct V_110 * V_94 ,
T_2 V_472 ,
enum V_441 V_442 ,
bool V_443 )
{
struct V_479 V_480 ;
T_2 V_406 ;
int V_31 = 0 ;
ASSERT ( V_472 ) ;
ASSERT ( ! V_409 -> V_410 || V_442 != V_448 ) ;
F_12 ( & V_94 -> V_50 ) ;
V_31 = - V_326 ;
V_406 = F_317 ( V_94 , true ) ;
if ( V_406 + V_472 <= V_94 -> V_363 ) {
V_94 -> V_404 += V_472 ;
F_325 ( V_36 , L_11 ,
V_94 -> V_7 , V_472 , 1 ) ;
V_31 = 0 ;
} else if ( F_348 ( V_36 , V_94 , V_472 , V_442 ,
V_443 ) ) {
V_94 -> V_404 += V_472 ;
F_325 ( V_36 , L_11 ,
V_94 -> V_7 , V_472 , 1 ) ;
V_31 = 0 ;
}
if ( V_31 && V_442 != V_434 ) {
V_480 . V_215 = V_472 ;
V_480 . error = 0 ;
F_67 ( & V_480 . V_89 ) ;
if ( V_442 == V_448 ) {
F_75 ( & V_480 . V_98 , & V_94 -> V_357 ) ;
if ( ! V_94 -> V_442 ) {
V_94 -> V_442 = 1 ;
F_373 ( V_36 ,
V_94 -> V_7 ,
V_472 , V_442 ,
L_13 ) ;
F_374 ( V_493 ,
& V_36 -> V_489 ) ;
}
} else {
F_75 ( & V_480 . V_98 ,
& V_94 -> V_358 ) ;
}
} else if ( ! V_31 && V_94 -> V_7 & V_53 ) {
V_406 += V_472 ;
if ( ! F_231 ( V_494 , & V_36 -> V_7 ) &&
F_364 ( V_36 , V_94 ,
V_406 , V_443 ) &&
! F_375 ( & V_36 -> V_489 ) ) {
F_373 ( V_36 , V_94 -> V_7 ,
V_472 , V_442 , L_14 ) ;
F_374 ( V_493 ,
& V_36 -> V_489 ) ;
}
}
F_14 ( & V_94 -> V_50 ) ;
if ( ! V_31 || V_442 == V_434 )
return V_31 ;
if ( V_442 == V_448 )
return F_370 ( V_36 , V_94 , & V_480 ,
V_472 ) ;
V_31 = 0 ;
F_369 ( V_36 , V_94 , & V_480 ) ;
F_12 ( & V_94 -> V_50 ) ;
if ( V_480 . V_215 ) {
if ( V_480 . V_215 < V_472 ) {
T_2 V_37 = V_472 - V_480 . V_215 ;
V_94 -> V_404 -= V_37 ;
F_325 ( V_36 , L_11 ,
V_94 -> V_7 ,
V_37 , 0 ) ;
}
F_280 ( & V_480 . V_98 ) ;
V_31 = - V_326 ;
}
F_14 ( & V_94 -> V_50 ) ;
ASSERT ( F_188 ( & V_480 . V_98 ) ) ;
return V_31 ;
}
static int F_376 ( struct V_63 * V_12 ,
struct V_268 * V_458 ,
T_2 V_472 ,
enum V_441 V_442 )
{
struct V_14 * V_36 = V_12 -> V_36 ;
struct V_268 * V_269 = & V_36 -> V_272 ;
int V_31 ;
bool V_443 = ( V_12 == V_36 -> V_399 ) ;
V_31 = F_372 ( V_36 , V_458 -> V_94 ,
V_472 , V_442 , V_443 ) ;
if ( V_31 == - V_326 &&
F_377 ( V_12 -> V_495 == V_496 ) ) {
if ( V_458 != V_269 &&
! F_378 ( V_269 , V_472 ) )
V_31 = 0 ;
}
if ( V_31 == - V_326 )
F_325 ( V_36 , L_10 ,
V_458 -> V_94 -> V_7 ,
V_472 , 1 ) ;
return V_31 ;
}
static struct V_268 * F_379 (
const struct V_123 * V_124 ,
const struct V_63 * V_12 )
{
struct V_14 * V_36 = V_12 -> V_36 ;
struct V_268 * V_458 = NULL ;
if ( F_231 ( V_302 , & V_12 -> V_303 ) ||
( V_12 == V_36 -> V_497 && V_124 -> V_498 ) ||
( V_12 == V_36 -> V_499 ) )
V_458 = V_124 -> V_458 ;
if ( ! V_458 )
V_458 = V_12 -> V_458 ;
if ( ! V_458 )
V_458 = & V_36 -> V_500 ;
return V_458 ;
}
static int F_378 ( struct V_268 * V_458 ,
T_2 V_37 )
{
int V_31 = - V_326 ;
F_12 ( & V_458 -> V_50 ) ;
if ( V_458 -> V_10 >= V_37 ) {
V_458 -> V_10 -= V_37 ;
if ( V_458 -> V_10 < V_458 -> V_59 )
V_458 -> V_122 = 0 ;
V_31 = 0 ;
}
F_14 ( & V_458 -> V_50 ) ;
return V_31 ;
}
static void F_380 ( struct V_268 * V_458 ,
T_2 V_37 , int V_501 )
{
F_12 ( & V_458 -> V_50 ) ;
V_458 -> V_10 += V_37 ;
if ( V_501 )
V_458 -> V_59 += V_37 ;
else if ( V_458 -> V_10 >= V_458 -> V_59 )
V_458 -> V_122 = 1 ;
F_14 ( & V_458 -> V_50 ) ;
}
int F_381 ( struct V_14 * V_36 ,
struct V_268 * V_502 , T_2 V_37 ,
int V_503 )
{
struct V_268 * V_269 = & V_36 -> V_272 ;
T_2 V_504 ;
if ( V_269 -> V_94 != V_502 -> V_94 )
return - V_326 ;
F_12 ( & V_269 -> V_50 ) ;
V_504 = F_337 ( V_269 -> V_59 , V_503 ) ;
if ( V_269 -> V_10 < V_504 + V_37 ) {
F_14 ( & V_269 -> V_50 ) ;
return - V_326 ;
}
V_269 -> V_10 -= V_37 ;
if ( V_269 -> V_10 < V_269 -> V_59 )
V_269 -> V_122 = 0 ;
F_14 ( & V_269 -> V_50 ) ;
F_380 ( V_502 , V_37 , 1 ) ;
return 0 ;
}
static void F_382 ( struct V_14 * V_36 ,
struct V_110 * V_94 ,
T_2 V_37 )
{
struct V_479 * V_480 ;
struct V_111 * V_112 ;
T_2 V_406 ;
enum V_441 V_442 = V_434 ;
bool V_505 = false ;
F_12 ( & V_94 -> V_50 ) ;
V_112 = & V_94 -> V_358 ;
V_406 = F_317 ( V_94 , true ) ;
if ( V_406 - V_37 >= V_94 -> V_363 )
V_505 = true ;
V_167:
while ( ! F_188 ( V_112 ) && V_37 ) {
V_480 = F_189 ( V_112 , struct V_479 ,
V_98 ) ;
if ( V_505 &&
! F_348 ( V_36 , V_94 , 0 , V_442 , false ) )
break;
if ( V_37 >= V_480 -> V_215 ) {
F_280 ( & V_480 -> V_98 ) ;
V_37 -= V_480 -> V_215 ;
V_480 -> V_215 = 0 ;
V_94 -> V_490 ++ ;
F_55 ( & V_480 -> V_89 ) ;
} else {
V_480 -> V_215 -= V_37 ;
V_37 = 0 ;
}
}
if ( V_37 && V_112 == & V_94 -> V_358 ) {
V_112 = & V_94 -> V_357 ;
V_442 = V_448 ;
goto V_167;
}
V_94 -> V_404 -= V_37 ;
F_325 ( V_36 , L_11 ,
V_94 -> V_7 , V_37 , 0 ) ;
F_14 ( & V_94 -> V_50 ) ;
}
static void F_302 ( struct V_14 * V_36 ,
struct V_110 * V_94 ,
T_2 V_37 )
{
struct V_479 * V_480 ;
struct V_111 * V_112 = & V_94 -> V_358 ;
V_167:
while ( ! F_188 ( V_112 ) && V_37 ) {
V_480 = F_189 ( V_112 , struct V_479 ,
V_98 ) ;
if ( V_37 >= V_480 -> V_215 ) {
F_325 ( V_36 , L_11 ,
V_94 -> V_7 ,
V_480 -> V_215 , 1 ) ;
F_280 ( & V_480 -> V_98 ) ;
V_37 -= V_480 -> V_215 ;
V_94 -> V_404 += V_480 -> V_215 ;
V_480 -> V_215 = 0 ;
V_94 -> V_490 ++ ;
F_55 ( & V_480 -> V_89 ) ;
} else {
F_325 ( V_36 , L_11 ,
V_94 -> V_7 ,
V_37 , 1 ) ;
V_94 -> V_404 += V_37 ;
V_480 -> V_215 -= V_37 ;
V_37 = 0 ;
}
}
if ( V_37 && V_112 == & V_94 -> V_358 ) {
V_112 = & V_94 -> V_357 ;
goto V_167;
}
}
static void F_383 ( struct V_14 * V_36 ,
struct V_268 * V_458 ,
struct V_268 * V_502 , T_2 V_37 )
{
struct V_110 * V_94 = V_458 -> V_94 ;
F_12 ( & V_458 -> V_50 ) ;
if ( V_37 == ( T_2 ) - 1 )
V_37 = V_458 -> V_59 ;
V_458 -> V_59 -= V_37 ;
if ( V_458 -> V_10 >= V_458 -> V_59 ) {
V_37 = V_458 -> V_10 - V_458 -> V_59 ;
V_458 -> V_10 = V_458 -> V_59 ;
V_458 -> V_122 = 1 ;
} else {
V_37 = 0 ;
}
F_14 ( & V_458 -> V_50 ) ;
if ( V_37 > 0 ) {
if ( V_502 ) {
F_12 ( & V_502 -> V_50 ) ;
if ( ! V_502 -> V_122 ) {
T_2 V_506 ;
V_506 = V_502 -> V_59 - V_502 -> V_10 ;
V_506 = F_356 ( V_37 , V_506 ) ;
V_502 -> V_10 += V_506 ;
if ( V_502 -> V_10 >= V_502 -> V_59 )
V_502 -> V_122 = 1 ;
V_37 -= V_506 ;
}
F_14 ( & V_502 -> V_50 ) ;
}
if ( V_37 )
F_382 ( V_36 , V_94 ,
V_37 ) ;
}
}
int F_384 ( struct V_268 * V_507 ,
struct V_268 * V_508 , T_2 V_37 ,
int V_501 )
{
int V_31 ;
V_31 = F_378 ( V_507 , V_37 ) ;
if ( V_31 )
return V_31 ;
F_380 ( V_508 , V_37 , V_501 ) ;
return 0 ;
}
void F_385 ( struct V_268 * V_509 , unsigned short type )
{
memset ( V_509 , 0 , sizeof( * V_509 ) ) ;
F_297 ( & V_509 -> V_50 ) ;
V_509 -> type = type ;
}
struct V_268 * F_386 ( struct V_14 * V_36 ,
unsigned short type )
{
struct V_268 * V_458 ;
V_458 = F_228 ( sizeof( * V_458 ) , V_97 ) ;
if ( ! V_458 )
return NULL ;
F_385 ( V_458 , type ) ;
V_458 -> V_94 = F_80 ( V_36 ,
V_53 ) ;
return V_458 ;
}
void F_387 ( struct V_14 * V_36 ,
struct V_268 * V_509 )
{
if ( ! V_509 )
return;
F_388 ( V_36 , V_509 , ( T_2 ) - 1 ) ;
F_10 ( V_509 ) ;
}
void F_389 ( struct V_268 * V_509 )
{
F_10 ( V_509 ) ;
}
int F_345 ( struct V_63 * V_12 ,
struct V_268 * V_458 , T_2 V_37 ,
enum V_441 V_442 )
{
int V_31 ;
if ( V_37 == 0 )
return 0 ;
V_31 = F_376 ( V_12 , V_458 , V_37 , V_442 ) ;
if ( ! V_31 ) {
F_380 ( V_458 , V_37 , 1 ) ;
return 0 ;
}
return V_31 ;
}
int F_390 ( struct V_268 * V_458 , int V_503 )
{
T_2 V_37 = 0 ;
int V_31 = - V_326 ;
if ( ! V_458 )
return 0 ;
F_12 ( & V_458 -> V_50 ) ;
V_37 = F_337 ( V_458 -> V_59 , V_503 ) ;
if ( V_458 -> V_10 >= V_37 )
V_31 = 0 ;
F_14 ( & V_458 -> V_50 ) ;
return V_31 ;
}
int F_391 ( struct V_63 * V_12 ,
struct V_268 * V_458 , T_2 V_510 ,
enum V_441 V_442 )
{
T_2 V_37 = 0 ;
int V_31 = - V_326 ;
if ( ! V_458 )
return 0 ;
F_12 ( & V_458 -> V_50 ) ;
V_37 = V_510 ;
if ( V_458 -> V_10 >= V_37 )
V_31 = 0 ;
else
V_37 -= V_458 -> V_10 ;
F_14 ( & V_458 -> V_50 ) ;
if ( ! V_31 )
return 0 ;
V_31 = F_376 ( V_12 , V_458 , V_37 , V_442 ) ;
if ( ! V_31 ) {
F_380 ( V_458 , V_37 , 0 ) ;
return 0 ;
}
return V_31 ;
}
void F_388 ( struct V_14 * V_36 ,
struct V_268 * V_458 ,
T_2 V_37 )
{
struct V_268 * V_269 = & V_36 -> V_272 ;
if ( V_269 == V_458 ||
V_458 -> V_94 != V_269 -> V_94 )
V_269 = NULL ;
F_383 ( V_36 , V_458 , V_269 , V_37 ) ;
}
static void F_392 ( struct V_14 * V_36 )
{
struct V_268 * V_458 = & V_36 -> V_272 ;
struct V_110 * V_421 = V_458 -> V_94 ;
T_2 V_37 ;
V_37 = F_393 ( & V_36 -> V_64 -> V_294 ) +
F_393 ( & V_36 -> V_497 -> V_294 ) +
F_393 ( & V_36 -> V_281 -> V_294 ) ;
V_37 = F_38 ( T_2 , V_37 , V_482 ) ;
F_12 ( & V_421 -> V_50 ) ;
F_12 ( & V_458 -> V_50 ) ;
V_458 -> V_59 = F_25 ( T_2 , V_37 , V_511 ) ;
if ( V_458 -> V_10 < V_458 -> V_59 ) {
V_37 = F_317 ( V_421 , true ) ;
if ( V_421 -> V_363 > V_37 ) {
V_37 = V_421 -> V_363 - V_37 ;
V_37 = F_356 ( V_37 ,
V_458 -> V_59 - V_458 -> V_10 ) ;
V_458 -> V_10 += V_37 ;
V_421 -> V_404 += V_37 ;
F_325 ( V_36 , L_11 ,
V_421 -> V_7 , V_37 ,
1 ) ;
}
} else if ( V_458 -> V_10 > V_458 -> V_59 ) {
V_37 = V_458 -> V_10 - V_458 -> V_59 ;
V_421 -> V_404 -= V_37 ;
F_325 ( V_36 , L_11 ,
V_421 -> V_7 , V_37 , 0 ) ;
V_458 -> V_10 = V_458 -> V_59 ;
}
if ( V_458 -> V_10 == V_458 -> V_59 )
V_458 -> V_122 = 1 ;
else
V_458 -> V_122 = 0 ;
F_14 ( & V_458 -> V_50 ) ;
F_14 ( & V_421 -> V_50 ) ;
}
static void F_394 ( struct V_14 * V_36 )
{
struct V_110 * V_94 ;
V_94 = F_80 ( V_36 , V_119 ) ;
V_36 -> V_433 . V_94 = V_94 ;
V_94 = F_80 ( V_36 , V_53 ) ;
V_36 -> V_272 . V_94 = V_94 ;
V_36 -> V_464 . V_94 = V_94 ;
V_36 -> V_512 . V_94 = V_94 ;
V_36 -> V_500 . V_94 = V_94 ;
V_36 -> V_470 . V_94 = V_94 ;
V_36 -> V_64 -> V_458 = & V_36 -> V_272 ;
V_36 -> V_497 -> V_458 = & V_36 -> V_272 ;
V_36 -> V_513 -> V_458 = & V_36 -> V_272 ;
V_36 -> V_281 -> V_458 = & V_36 -> V_272 ;
if ( V_36 -> V_514 )
V_36 -> V_514 -> V_458 = & V_36 -> V_272 ;
V_36 -> V_399 -> V_458 = & V_36 -> V_433 ;
F_392 ( V_36 ) ;
}
static void F_395 ( struct V_14 * V_36 )
{
F_383 ( V_36 , & V_36 -> V_272 , NULL ,
( T_2 ) - 1 ) ;
F_8 ( V_36 -> V_464 . V_59 > 0 ) ;
F_8 ( V_36 -> V_464 . V_10 > 0 ) ;
F_8 ( V_36 -> V_512 . V_59 > 0 ) ;
F_8 ( V_36 -> V_512 . V_10 > 0 ) ;
F_8 ( V_36 -> V_433 . V_59 > 0 ) ;
F_8 ( V_36 -> V_433 . V_10 > 0 ) ;
F_8 ( V_36 -> V_470 . V_59 > 0 ) ;
F_8 ( V_36 -> V_470 . V_10 > 0 ) ;
}
void F_396 ( struct V_123 * V_124 ,
struct V_14 * V_36 )
{
if ( ! V_124 -> V_458 )
return;
if ( ! V_124 -> V_402 )
return;
F_325 ( V_36 , L_15 ,
V_124 -> V_280 , V_124 -> V_402 , 0 ) ;
F_388 ( V_36 , V_124 -> V_458 ,
V_124 -> V_402 ) ;
V_124 -> V_402 = 0 ;
}
void F_347 ( struct V_123 * V_124 )
{
struct V_14 * V_36 = V_124 -> V_36 ;
if ( ! V_124 -> V_435 )
return;
F_397 ( ! F_188 ( & V_124 -> V_288 ) ) ;
F_383 ( V_36 , & V_36 -> V_433 , NULL ,
V_124 -> V_435 ) ;
V_124 -> V_435 = 0 ;
}
int F_398 ( struct V_123 * V_124 ,
struct V_405 * V_308 )
{
struct V_14 * V_36 = F_326 ( V_308 -> V_515 . V_419 ) ;
struct V_63 * V_12 = V_308 -> V_12 ;
struct V_268 * V_516 = V_124 -> V_458 ;
struct V_268 * V_517 = V_12 -> V_518 ;
T_2 V_37 = F_215 ( V_36 , 1 ) ;
F_325 ( V_36 , L_16 , F_399 ( V_308 ) ,
V_37 , 1 ) ;
return F_384 ( V_516 , V_517 , V_37 , 1 ) ;
}
void F_400 ( struct V_405 * V_308 )
{
struct V_14 * V_36 = F_326 ( V_308 -> V_515 . V_419 ) ;
struct V_63 * V_12 = V_308 -> V_12 ;
T_2 V_37 = F_215 ( V_36 , 1 ) ;
F_325 ( V_36 , L_16 , F_399 ( V_308 ) ,
V_37 , 0 ) ;
F_388 ( V_36 , V_12 -> V_518 , V_37 ) ;
}
int F_401 ( struct V_63 * V_12 ,
struct V_268 * V_509 ,
int V_461 ,
T_2 * V_237 ,
bool V_519 )
{
T_2 V_37 ;
int V_31 ;
struct V_14 * V_36 = V_12 -> V_36 ;
struct V_268 * V_269 = & V_36 -> V_272 ;
if ( F_231 ( V_520 , & V_36 -> V_7 ) ) {
V_37 = 3 * V_36 -> V_54 ;
V_31 = F_402 ( V_12 , V_37 , true ) ;
if ( V_31 )
return V_31 ;
} else {
V_37 = 0 ;
}
* V_237 = V_37 ;
V_37 = F_215 ( V_36 , V_461 ) ;
V_509 -> V_94 = F_80 ( V_36 ,
V_53 ) ;
V_31 = F_345 ( V_12 , V_509 , V_37 ,
V_448 ) ;
if ( V_31 == - V_326 && V_519 )
V_31 = F_384 ( V_269 , V_509 , V_37 , 1 ) ;
if ( V_31 && * V_237 )
F_403 ( V_12 , * V_237 ) ;
return V_31 ;
}
void F_404 ( struct V_14 * V_36 ,
struct V_268 * V_509 )
{
F_388 ( V_36 , V_509 , ( T_2 ) - 1 ) ;
}
static unsigned F_405 ( struct V_405 * V_308 ,
T_2 V_37 )
{
unsigned V_521 = 0 ;
unsigned V_522 = 0 ;
unsigned V_523 ;
V_523 = F_406 ( V_37 ) ;
ASSERT ( V_523 ) ;
ASSERT ( V_308 -> V_524 >= V_523 ) ;
V_308 -> V_524 -= V_523 ;
if ( V_308 -> V_524 == 0 &&
F_407 ( V_525 ,
& V_308 -> V_526 ) )
V_521 = 1 ;
if ( V_308 -> V_524 >= V_308 -> V_527 )
return V_521 ;
V_522 = V_308 -> V_527 - V_308 -> V_524 ;
V_308 -> V_527 -= V_522 ;
return V_522 + V_521 ;
}
static T_2 F_408 ( struct V_405 * V_308 , T_2 V_37 ,
int V_528 )
{
struct V_14 * V_36 = F_326 ( V_308 -> V_515 . V_419 ) ;
T_2 V_529 , V_266 ;
if ( V_308 -> V_7 & V_530 && V_308 -> V_263 == 0 )
return 0 ;
V_529 = F_210 ( V_36 , V_308 -> V_263 ) ;
if ( V_528 )
V_308 -> V_263 += V_37 ;
else
V_308 -> V_263 -= V_37 ;
V_266 = F_210 ( V_36 , V_308 -> V_263 ) ;
if ( V_529 == V_266 )
return 0 ;
if ( V_528 )
return F_215 ( V_36 ,
V_266 - V_529 ) ;
return F_215 ( V_36 , V_529 - V_266 ) ;
}
int F_409 ( struct V_405 * V_308 , T_2 V_37 )
{
struct V_14 * V_36 = F_326 ( V_308 -> V_515 . V_419 ) ;
struct V_63 * V_12 = V_308 -> V_12 ;
struct V_268 * V_458 = & V_36 -> V_464 ;
T_2 V_531 = 0 ;
T_2 V_263 ;
unsigned V_532 ;
enum V_441 V_442 = V_448 ;
int V_31 = 0 ;
bool V_533 = true ;
T_2 V_534 = 0 ;
unsigned V_535 ;
bool V_536 = false ;
if ( F_319 ( V_308 ) ) {
V_442 = V_434 ;
V_533 = false ;
} else if ( V_409 -> V_410 ) {
V_442 = V_537 ;
}
if ( V_442 != V_434 &&
F_410 ( V_36 ) )
F_411 ( 1 ) ;
if ( V_533 )
F_52 ( & V_308 -> V_538 ) ;
V_37 = F_154 ( V_37 , V_36 -> V_55 ) ;
F_12 ( & V_308 -> V_50 ) ;
V_532 = F_406 ( V_37 ) ;
V_308 -> V_524 += V_532 ;
V_532 = 0 ;
if ( V_308 -> V_524 > V_308 -> V_527 )
V_532 += V_308 -> V_524 -
V_308 -> V_527 ;
V_531 = F_215 ( V_36 , V_532 + 1 ) ;
V_531 += F_408 ( V_308 , V_37 , 1 ) ;
V_263 = V_308 -> V_263 ;
F_14 ( & V_308 -> V_50 ) ;
if ( F_231 ( V_520 , & V_36 -> V_7 ) ) {
V_31 = F_402 ( V_12 ,
V_532 * V_36 -> V_54 , true ) ;
if ( V_31 )
goto V_539;
}
V_31 = F_345 ( V_12 , V_458 , V_531 , V_442 ) ;
if ( F_377 ( V_31 ) ) {
F_403 ( V_12 ,
V_532 * V_36 -> V_54 ) ;
goto V_539;
}
F_12 ( & V_308 -> V_50 ) ;
if ( F_412 ( V_525 ,
& V_308 -> V_526 ) ) {
V_531 -= F_215 ( V_36 , 1 ) ;
V_536 = true ;
}
V_308 -> V_527 += V_532 ;
F_14 ( & V_308 -> V_50 ) ;
if ( V_533 )
F_50 ( & V_308 -> V_538 ) ;
if ( V_531 )
F_325 ( V_36 , L_17 ,
F_399 ( V_308 ) , V_531 , 1 ) ;
if ( V_536 )
F_388 ( V_36 , V_458 ,
F_215 ( V_36 , 1 ) ) ;
return 0 ;
V_539:
F_12 ( & V_308 -> V_50 ) ;
V_535 = F_405 ( V_308 , V_37 ) ;
if ( V_308 -> V_263 == V_263 ) {
F_408 ( V_308 , V_37 , 0 ) ;
} else {
T_2 V_540 = V_308 -> V_263 ;
T_2 V_215 ;
V_215 = V_263 - V_308 -> V_263 ;
V_308 -> V_263 = V_263 ;
V_534 = F_408 ( V_308 , V_215 , 0 ) ;
V_308 -> V_263 = V_263 - V_37 ;
V_215 = V_263 - V_540 ;
V_215 = F_408 ( V_308 , V_215 , 0 ) ;
V_308 -> V_263 = V_540 - V_37 ;
if ( V_215 > V_534 )
V_534 = V_215 - V_534 ;
else
V_534 = 0 ;
}
F_14 ( & V_308 -> V_50 ) ;
if ( V_535 )
V_534 += F_215 ( V_36 , V_535 ) ;
if ( V_534 ) {
F_388 ( V_36 , V_458 , V_534 ) ;
F_325 ( V_36 , L_17 ,
F_399 ( V_308 ) , V_534 , 0 ) ;
}
if ( V_533 )
F_50 ( & V_308 -> V_538 ) ;
return V_31 ;
}
void F_413 ( struct V_405 * V_308 , T_2 V_37 )
{
struct V_14 * V_36 = F_326 ( V_308 -> V_515 . V_419 ) ;
T_2 V_534 = 0 ;
unsigned V_535 ;
V_37 = F_154 ( V_37 , V_36 -> V_55 ) ;
F_12 ( & V_308 -> V_50 ) ;
V_535 = F_405 ( V_308 , V_37 ) ;
if ( V_37 )
V_534 = F_408 ( V_308 , V_37 , 0 ) ;
F_14 ( & V_308 -> V_50 ) ;
if ( V_535 > 0 )
V_534 += F_215 ( V_36 , V_535 ) ;
if ( F_246 ( V_36 ) )
return;
F_325 ( V_36 , L_17 , F_399 ( V_308 ) ,
V_534 , 0 ) ;
F_388 ( V_36 , & V_36 -> V_464 , V_534 ) ;
}
int F_414 ( struct V_308 * V_308 ,
struct V_309 * * V_10 , T_2 V_34 , T_2 V_47 )
{
int V_31 ;
V_31 = F_270 ( V_308 , V_10 , V_34 , V_47 ) ;
if ( V_31 < 0 )
return V_31 ;
V_31 = F_409 ( F_265 ( V_308 ) , V_47 ) ;
if ( V_31 < 0 )
F_330 ( V_308 , * V_10 , V_34 , V_47 ) ;
return V_31 ;
}
void F_415 ( struct V_308 * V_308 ,
struct V_309 * V_10 , T_2 V_34 , T_2 V_47 )
{
F_413 ( F_265 ( V_308 ) , V_47 ) ;
F_330 ( V_308 , V_10 , V_34 , V_47 ) ;
}
static int F_416 ( struct V_123 * V_124 ,
struct V_14 * V_15 , T_2 V_29 ,
T_2 V_37 , int V_411 )
{
struct V_1 * V_2 = NULL ;
T_2 V_541 = V_37 ;
T_2 V_542 ;
T_2 V_543 ;
int V_365 ;
F_12 ( & V_15 -> V_544 ) ;
V_542 = F_417 ( V_15 -> V_267 ) ;
if ( V_411 )
V_542 += V_37 ;
else
V_542 -= V_37 ;
F_418 ( V_15 -> V_267 , V_542 ) ;
F_14 ( & V_15 -> V_544 ) ;
while ( V_541 ) {
V_2 = F_79 ( V_15 , V_29 ) ;
if ( ! V_2 )
return - V_164 ;
if ( V_2 -> V_7 & ( V_366 |
V_367 |
V_368 ) )
V_365 = 2 ;
else
V_365 = 1 ;
if ( ! V_411 && V_2 -> V_3 == V_102 )
F_62 ( V_2 , 1 ) ;
V_543 = V_29 - V_2 -> V_23 . V_24 ;
F_8 ( V_543 > V_2 -> V_23 . V_35 ) ;
F_12 ( & V_2 -> V_94 -> V_50 ) ;
F_12 ( & V_2 -> V_50 ) ;
if ( F_269 ( V_15 , V_324 ) &&
V_2 -> V_317 < V_331 )
V_2 -> V_317 = V_331 ;
V_542 = F_61 ( & V_2 -> V_95 ) ;
V_37 = F_356 ( V_541 , V_2 -> V_23 . V_35 - V_543 ) ;
if ( V_411 ) {
V_542 += V_37 ;
F_419 ( & V_2 -> V_95 , V_542 ) ;
V_2 -> V_10 -= V_37 ;
V_2 -> V_94 -> V_402 -= V_37 ;
V_2 -> V_94 -> V_93 += V_37 ;
V_2 -> V_94 -> V_370 += V_37 * V_365 ;
F_14 ( & V_2 -> V_50 ) ;
F_14 ( & V_2 -> V_94 -> V_50 ) ;
} else {
V_542 -= V_37 ;
F_419 ( & V_2 -> V_95 , V_542 ) ;
V_2 -> V_9 += V_37 ;
V_2 -> V_94 -> V_403 += V_37 ;
V_2 -> V_94 -> V_93 -= V_37 ;
V_2 -> V_94 -> V_370 -= V_37 * V_365 ;
F_14 ( & V_2 -> V_50 ) ;
F_14 ( & V_2 -> V_94 -> V_50 ) ;
F_325 ( V_15 , L_18 ,
V_2 -> V_94 -> V_7 ,
V_37 , 1 ) ;
F_85 ( & V_2 -> V_94 -> V_121 ,
V_37 ) ;
F_420 ( V_15 -> V_61 ,
V_29 , V_29 + V_37 - 1 ,
V_97 | V_545 ) ;
}
F_12 ( & V_124 -> V_141 -> V_338 ) ;
if ( F_188 ( & V_2 -> V_340 ) ) {
F_75 ( & V_2 -> V_340 ,
& V_124 -> V_141 -> V_330 ) ;
V_124 -> V_141 -> V_270 ++ ;
F_4 ( V_2 ) ;
}
F_14 ( & V_124 -> V_141 -> V_338 ) ;
if ( ! V_411 && V_542 == 0 ) {
F_12 ( & V_15 -> V_546 ) ;
if ( F_188 ( & V_2 -> V_547 ) ) {
F_4 ( V_2 ) ;
F_75 ( & V_2 -> V_547 ,
& V_15 -> V_548 ) ;
}
F_14 ( & V_15 -> V_546 ) ;
}
F_6 ( V_2 ) ;
V_541 -= V_37 ;
V_29 += V_37 ;
}
return 0 ;
}
static T_2 V_28 ( struct V_14 * V_36 , T_2 V_549 )
{
struct V_1 * V_2 ;
T_2 V_29 ;
F_12 ( & V_36 -> V_20 ) ;
V_29 = V_36 -> V_28 ;
F_14 ( & V_36 -> V_20 ) ;
if ( V_29 < ( T_2 ) - 1 )
return V_29 ;
V_2 = F_78 ( V_36 , V_549 ) ;
if ( ! V_2 )
return 0 ;
V_29 = V_2 -> V_23 . V_24 ;
F_6 ( V_2 ) ;
return V_29 ;
}
static int F_421 ( struct V_14 * V_36 ,
struct V_1 * V_2 ,
T_2 V_29 , T_2 V_37 , int V_10 )
{
F_12 ( & V_2 -> V_94 -> V_50 ) ;
F_12 ( & V_2 -> V_50 ) ;
V_2 -> V_9 += V_37 ;
V_2 -> V_94 -> V_403 += V_37 ;
if ( V_10 ) {
V_2 -> V_10 -= V_37 ;
V_2 -> V_94 -> V_402 -= V_37 ;
}
F_14 ( & V_2 -> V_50 ) ;
F_14 ( & V_2 -> V_94 -> V_50 ) ;
F_325 ( V_36 , L_18 ,
V_2 -> V_94 -> V_7 , V_37 , 1 ) ;
F_85 ( & V_2 -> V_94 -> V_121 , V_37 ) ;
F_420 ( V_36 -> V_61 , V_29 ,
V_29 + V_37 - 1 , V_97 | V_545 ) ;
return 0 ;
}
int F_181 ( struct V_14 * V_36 ,
T_2 V_29 , T_2 V_37 , int V_10 )
{
struct V_1 * V_2 ;
V_2 = F_79 ( V_36 , V_29 ) ;
F_35 ( ! V_2 ) ;
F_421 ( V_36 , V_2 , V_29 , V_37 , V_10 ) ;
F_6 ( V_2 ) ;
return 0 ;
}
int F_422 ( struct V_14 * V_36 ,
T_2 V_29 , T_2 V_37 )
{
struct V_1 * V_2 ;
int V_31 ;
V_2 = F_79 ( V_36 , V_29 ) ;
if ( ! V_2 )
return - V_550 ;
F_62 ( V_2 , 1 ) ;
F_421 ( V_36 , V_2 , V_29 , V_37 , 0 ) ;
V_31 = F_31 ( V_2 , V_29 , V_37 ) ;
F_6 ( V_2 ) ;
return V_31 ;
}
static int F_423 ( struct V_14 * V_36 ,
T_2 V_34 , T_2 V_37 )
{
int V_31 ;
struct V_1 * V_16 ;
struct V_48 * V_51 ;
V_16 = F_79 ( V_36 , V_34 ) ;
if ( ! V_16 )
return - V_550 ;
F_62 ( V_16 , 0 ) ;
V_51 = F_26 ( V_16 ) ;
if ( ! V_51 ) {
F_35 ( ! F_1 ( V_16 ) ) ;
V_31 = F_31 ( V_16 , V_34 , V_37 ) ;
} else {
F_52 ( & V_51 -> V_86 ) ;
if ( V_34 >= V_51 -> V_85 ) {
V_31 = F_18 ( V_36 , V_34 , V_37 ) ;
} else if ( V_34 + V_37 <= V_51 -> V_85 ) {
V_31 = F_31 ( V_16 ,
V_34 , V_37 ) ;
} else {
V_37 = V_51 -> V_85 - V_34 ;
V_31 = F_31 ( V_16 ,
V_34 , V_37 ) ;
if ( V_31 )
goto V_551;
V_37 = ( V_34 + V_37 ) -
V_51 -> V_85 ;
V_34 = V_51 -> V_85 ;
V_31 = F_18 ( V_36 , V_34 , V_37 ) ;
}
V_551:
F_50 ( & V_51 -> V_86 ) ;
F_28 ( V_51 ) ;
}
F_6 ( V_16 ) ;
return V_31 ;
}
int F_424 ( struct V_14 * V_36 ,
struct V_67 * V_552 )
{
struct V_300 * V_95 ;
struct V_69 V_23 ;
int V_553 ;
int V_42 ;
if ( ! F_89 ( V_36 , V_554 ) )
return 0 ;
for ( V_42 = 0 ; V_42 < F_42 ( V_552 ) ; V_42 ++ ) {
F_44 ( V_552 , & V_23 , V_42 ) ;
if ( V_23 . type != V_305 )
continue;
V_95 = F_91 ( V_552 , V_42 , struct V_300 ) ;
V_553 = F_249 ( V_552 , V_95 ) ;
if ( V_553 == V_306 )
continue;
if ( F_250 ( V_552 , V_95 ) == 0 )
continue;
V_23 . V_24 = F_250 ( V_552 , V_95 ) ;
V_23 . V_35 = F_251 ( V_552 , V_95 ) ;
F_423 ( V_36 , V_23 . V_24 , V_23 . V_35 ) ;
}
return 0 ;
}
static void
F_425 ( struct V_1 * V_346 )
{
F_5 ( & V_346 -> V_555 ) ;
}
void F_426 ( struct V_14 * V_36 ,
const T_2 V_34 )
{
struct V_1 * V_346 ;
V_346 = F_79 ( V_36 , V_34 ) ;
ASSERT ( V_346 ) ;
if ( F_7 ( & V_346 -> V_555 ) )
F_289 ( & V_346 -> V_555 ) ;
F_6 ( V_346 ) ;
}
static int F_427 ( T_8 * V_348 )
{
F_71 () ;
return 0 ;
}
void F_428 ( struct V_1 * V_346 )
{
struct V_110 * V_94 = V_346 -> V_94 ;
ASSERT ( V_346 -> V_319 ) ;
if ( ! ( V_346 -> V_7 & V_120 ) )
return;
F_74 ( & V_94 -> V_353 ) ;
F_76 ( & V_94 -> V_353 ) ;
F_292 ( & V_346 -> V_555 ,
F_427 ,
V_101 ) ;
}
static int F_429 ( struct V_1 * V_2 ,
T_2 V_556 , T_2 V_37 , int V_557 )
{
struct V_110 * V_94 = V_2 -> V_94 ;
int V_31 = 0 ;
F_12 ( & V_94 -> V_50 ) ;
F_12 ( & V_2 -> V_50 ) ;
if ( V_2 -> V_319 ) {
V_31 = - V_190 ;
} else {
V_2 -> V_10 += V_37 ;
V_94 -> V_402 += V_37 ;
F_325 ( V_2 -> V_36 ,
L_11 , V_94 -> V_7 ,
V_556 , 0 ) ;
V_94 -> V_404 -= V_556 ;
if ( V_557 )
V_2 -> V_459 += V_37 ;
}
F_14 ( & V_2 -> V_50 ) ;
F_14 ( & V_94 -> V_50 ) ;
return V_31 ;
}
static int F_430 ( struct V_1 * V_2 ,
T_2 V_37 , int V_557 )
{
struct V_110 * V_94 = V_2 -> V_94 ;
int V_31 = 0 ;
F_12 ( & V_94 -> V_50 ) ;
F_12 ( & V_2 -> V_50 ) ;
if ( V_2 -> V_319 )
V_94 -> V_364 += V_37 ;
V_2 -> V_10 -= V_37 ;
V_94 -> V_402 -= V_37 ;
if ( V_557 )
V_2 -> V_459 -= V_37 ;
F_14 ( & V_2 -> V_50 ) ;
F_14 ( & V_94 -> V_50 ) ;
return V_31 ;
}
void F_431 ( struct V_14 * V_36 )
{
struct V_48 * V_80 ;
struct V_48 * V_51 ;
struct V_1 * V_2 ;
F_74 ( & V_36 -> V_84 ) ;
F_276 (caching_ctl, next,
&fs_info->caching_block_groups, list) {
V_2 = V_51 -> V_16 ;
if ( F_1 ( V_2 ) ) {
V_2 -> V_105 = ( T_2 ) - 1 ;
F_280 ( & V_51 -> V_98 ) ;
F_28 ( V_51 ) ;
} else {
V_2 -> V_105 = V_51 -> V_85 ;
}
}
if ( V_36 -> V_61 == & V_36 -> V_38 [ 0 ] )
V_36 -> V_61 = & V_36 -> V_38 [ 1 ] ;
else
V_36 -> V_61 = & V_36 -> V_38 [ 0 ] ;
F_76 ( & V_36 -> V_84 ) ;
F_392 ( V_36 ) ;
}
static struct V_558 *
F_432 ( struct V_14 * V_36 ,
struct V_110 * V_94 , T_2 * V_559 )
{
struct V_558 * V_31 = NULL ;
bool V_560 = F_269 ( V_36 , V_561 ) ;
* V_559 = 0 ;
if ( F_346 ( V_94 ) )
return V_31 ;
if ( V_560 )
* V_559 = V_427 ;
if ( V_94 -> V_7 & V_53 ) {
V_31 = & V_36 -> V_562 ;
if ( ! V_560 )
* V_559 = V_563 ;
} else if ( ( V_94 -> V_7 & V_120 ) && V_560 ) {
V_31 = & V_36 -> V_564 ;
}
return V_31 ;
}
static int F_433 ( struct V_14 * V_36 ,
T_2 V_34 , T_2 V_33 ,
const bool V_565 )
{
struct V_1 * V_2 = NULL ;
struct V_110 * V_94 ;
struct V_268 * V_269 = & V_36 -> V_272 ;
struct V_558 * V_566 = NULL ;
T_2 V_47 ;
T_2 V_567 = 0 ;
T_2 V_559 = 0 ;
bool V_345 ;
while ( V_34 <= V_33 ) {
V_345 = false ;
if ( ! V_2 ||
V_34 >= V_2 -> V_23 . V_24 + V_2 -> V_23 . V_35 ) {
if ( V_2 )
F_6 ( V_2 ) ;
V_567 = 0 ;
V_2 = F_79 ( V_36 , V_34 ) ;
F_35 ( ! V_2 ) ;
V_566 = F_432 ( V_36 ,
V_2 -> V_94 ,
& V_559 ) ;
V_559 <<= 1 ;
}
V_47 = V_2 -> V_23 . V_24 + V_2 -> V_23 . V_35 - V_34 ;
V_47 = F_356 ( V_47 , V_33 + 1 - V_34 ) ;
if ( V_34 < V_2 -> V_105 ) {
V_47 = F_356 ( V_47 , V_2 -> V_105 - V_34 ) ;
if ( V_565 )
F_34 ( V_2 , V_34 , V_47 ) ;
}
V_34 += V_47 ;
V_567 += V_47 ;
V_94 = V_2 -> V_94 ;
if ( V_566 && V_566 -> V_568 &&
V_567 > V_559 ) {
F_12 ( & V_566 -> V_50 ) ;
V_566 -> V_568 = 0 ;
F_14 ( & V_566 -> V_50 ) ;
}
F_12 ( & V_94 -> V_50 ) ;
F_12 ( & V_2 -> V_50 ) ;
V_2 -> V_9 -= V_47 ;
V_94 -> V_403 -= V_47 ;
F_325 ( V_36 , L_18 ,
V_94 -> V_7 , V_47 , 0 ) ;
V_94 -> V_569 = 0 ;
F_85 ( & V_94 -> V_121 , - V_47 ) ;
if ( V_2 -> V_319 ) {
V_94 -> V_364 += V_47 ;
V_345 = true ;
}
F_14 ( & V_2 -> V_50 ) ;
if ( ! V_345 && V_565 &&
V_269 -> V_94 == V_94 ) {
T_2 V_570 = V_47 ;
F_8 ( ! V_565 ) ;
F_12 ( & V_269 -> V_50 ) ;
if ( ! V_269 -> V_122 ) {
V_570 = F_356 ( V_47 , V_269 -> V_59 -
V_269 -> V_10 ) ;
V_269 -> V_10 += V_570 ;
V_94 -> V_404 += V_570 ;
if ( V_269 -> V_10 >= V_269 -> V_59 )
V_269 -> V_122 = 1 ;
F_325 ( V_36 ,
L_11 ,
V_94 -> V_7 ,
V_570 , 1 ) ;
V_47 -= V_570 ;
}
F_14 ( & V_269 -> V_50 ) ;
if ( V_47 )
F_302 ( V_36 , V_94 ,
V_47 ) ;
}
F_14 ( & V_94 -> V_50 ) ;
}
if ( V_2 )
F_6 ( V_2 ) ;
return 0 ;
}
int F_434 ( struct V_123 * V_124 ,
struct V_14 * V_36 )
{
struct V_1 * V_16 , * V_329 ;
struct V_111 * V_571 ;
struct V_572 * V_573 ;
T_2 V_34 ;
T_2 V_33 ;
int V_31 ;
if ( V_36 -> V_61 == & V_36 -> V_38 [ 0 ] )
V_573 = & V_36 -> V_38 [ 1 ] ;
else
V_573 = & V_36 -> V_38 [ 0 ] ;
while ( ! V_124 -> V_233 ) {
F_52 ( & V_36 -> V_574 ) ;
V_31 = F_33 ( V_573 , 0 , & V_34 , & V_33 ,
V_62 , NULL ) ;
if ( V_31 ) {
F_50 ( & V_36 -> V_574 ) ;
break;
}
if ( F_269 ( V_36 , V_575 ) )
V_31 = F_158 ( V_36 , V_34 ,
V_33 + 1 - V_34 , NULL ) ;
F_435 ( V_573 , V_34 , V_33 ) ;
F_433 ( V_36 , V_34 , V_33 , true ) ;
F_50 ( & V_36 -> V_574 ) ;
F_51 () ;
}
V_571 = & V_124 -> V_141 -> V_571 ;
F_276 (block_group, tmp, deleted_bgs, bg_list) {
T_2 V_576 = 0 ;
V_31 = - V_577 ;
if ( ! V_124 -> V_233 )
V_31 = F_158 ( V_36 ,
V_16 -> V_23 . V_24 ,
V_16 -> V_23 . V_35 ,
& V_576 ) ;
F_280 ( & V_16 -> V_547 ) ;
F_436 ( V_16 ) ;
F_6 ( V_16 ) ;
if ( V_31 ) {
const char * V_578 = F_437 ( V_31 ) ;
F_438 ( V_36 ,
L_19 ,
V_31 , V_578 ) ;
}
}
return 0 ;
}
static int F_172 ( struct V_123 * V_124 ,
struct V_14 * V_15 ,
struct V_224 * V_142 , T_2 V_19 ,
T_2 V_116 , T_2 V_579 ,
T_2 V_580 , int V_171 ,
struct V_192 * V_143 )
{
struct V_69 V_23 ;
struct V_65 * V_66 ;
struct V_63 * V_64 = V_15 -> V_64 ;
struct V_67 * V_68 ;
struct V_130 * V_131 ;
struct V_175 * V_176 ;
int V_31 ;
int V_196 ;
int V_581 = 0 ;
int V_582 = 0 ;
int V_583 = 1 ;
T_3 V_132 ;
T_2 V_126 ;
T_2 V_29 = V_142 -> V_29 ;
T_2 V_37 = V_142 -> V_37 ;
int V_172 = 0 ;
bool V_185 = F_89 ( V_15 , V_135 ) ;
V_66 = F_37 () ;
if ( ! V_66 )
return - V_74 ;
V_66 -> V_77 = V_78 ;
V_66 -> V_225 = 1 ;
V_196 = V_579 >= V_117 ;
F_35 ( ! V_196 && V_171 != 1 ) ;
if ( V_196 )
V_185 = 0 ;
V_31 = F_147 ( V_124 , V_15 , V_66 , & V_176 ,
V_29 , V_37 , V_19 ,
V_116 , V_579 ,
V_580 ) ;
if ( V_31 == 0 ) {
V_581 = V_66 -> V_83 [ 0 ] ;
while ( V_581 >= 0 ) {
F_44 ( V_66 -> V_82 [ 0 ] , & V_23 ,
V_581 ) ;
if ( V_23 . V_24 != V_29 )
break;
if ( V_23 . type == V_79 &&
V_23 . V_35 == V_37 ) {
V_582 = 1 ;
break;
}
if ( V_23 . type == V_87 &&
V_23 . V_35 == V_579 ) {
V_582 = 1 ;
break;
}
if ( V_66 -> V_83 [ 0 ] - V_581 > 5 )
break;
V_581 -- ;
}
#ifdef F_94
V_132 = F_90 ( V_66 -> V_82 [ 0 ] , V_581 ) ;
if ( V_582 && V_132 < sizeof( * V_131 ) )
V_582 = 0 ;
#endif
if ( ! V_582 ) {
F_35 ( V_176 ) ;
V_31 = F_152 ( V_124 , V_15 , V_66 , NULL ,
V_171 ,
V_196 , & V_172 ) ;
if ( V_31 ) {
F_167 ( V_124 , V_31 ) ;
goto V_81;
}
F_48 ( V_66 ) ;
V_66 -> V_225 = 1 ;
V_23 . V_24 = V_29 ;
V_23 . type = V_79 ;
V_23 . V_35 = V_37 ;
if ( ! V_196 && V_185 ) {
V_23 . type = V_87 ;
V_23 . V_35 = V_579 ;
}
V_31 = F_41 ( V_124 , V_64 ,
& V_23 , V_66 , - 1 , 1 ) ;
if ( V_31 > 0 && V_185 && V_66 -> V_83 [ 0 ] ) {
V_66 -> V_83 [ 0 ] -- ;
F_44 ( V_66 -> V_82 [ 0 ] , & V_23 ,
V_66 -> V_83 [ 0 ] ) ;
if ( V_23 . V_24 == V_29 &&
V_23 . type == V_79 &&
V_23 . V_35 == V_37 )
V_31 = 0 ;
}
if ( V_31 > 0 && V_185 ) {
V_185 = false ;
V_23 . V_24 = V_29 ;
V_23 . type = V_79 ;
V_23 . V_35 = V_37 ;
F_48 ( V_66 ) ;
V_31 = F_41 ( V_124 , V_64 ,
& V_23 , V_66 , - 1 , 1 ) ;
}
if ( V_31 ) {
F_178 ( V_15 ,
L_20 ,
V_31 , V_29 ) ;
if ( V_31 > 0 )
F_439 ( V_15 , V_66 -> V_82 [ 0 ] ) ;
}
if ( V_31 < 0 ) {
F_167 ( V_124 , V_31 ) ;
goto V_81;
}
V_581 = V_66 -> V_83 [ 0 ] ;
}
} else if ( F_8 ( V_31 == - V_164 ) ) {
F_439 ( V_15 , V_66 -> V_82 [ 0 ] ) ;
F_178 ( V_15 ,
L_21 ,
V_29 , V_19 , V_116 , V_579 ,
V_580 ) ;
F_167 ( V_124 , V_31 ) ;
goto V_81;
} else {
F_167 ( V_124 , V_31 ) ;
goto V_81;
}
V_68 = V_66 -> V_82 [ 0 ] ;
V_132 = F_90 ( V_68 , V_581 ) ;
#ifdef F_94
if ( V_132 < sizeof( * V_131 ) ) {
F_35 ( V_582 || V_581 != V_66 -> V_83 [ 0 ] ) ;
V_31 = F_100 ( V_124 , V_15 , V_66 , V_579 ,
0 ) ;
if ( V_31 < 0 ) {
F_167 ( V_124 , V_31 ) ;
goto V_81;
}
F_48 ( V_66 ) ;
V_66 -> V_225 = 1 ;
V_23 . V_24 = V_29 ;
V_23 . type = V_79 ;
V_23 . V_35 = V_37 ;
V_31 = F_41 ( V_124 , V_64 , & V_23 , V_66 ,
- 1 , 1 ) ;
if ( V_31 ) {
F_178 ( V_15 ,
L_20 ,
V_31 , V_29 ) ;
F_439 ( V_15 , V_66 -> V_82 [ 0 ] ) ;
}
if ( V_31 < 0 ) {
F_167 ( V_124 , V_31 ) ;
goto V_81;
}
V_581 = V_66 -> V_83 [ 0 ] ;
V_68 = V_66 -> V_82 [ 0 ] ;
V_132 = F_90 ( V_68 , V_581 ) ;
}
#endif
F_35 ( V_132 < sizeof( * V_131 ) ) ;
V_131 = F_91 ( V_68 , V_581 ,
struct V_130 ) ;
if ( V_579 < V_117 &&
V_23 . type == V_79 ) {
struct V_150 * V_151 ;
F_35 ( V_132 < sizeof( * V_131 ) + sizeof( * V_151 ) ) ;
V_151 = (struct V_150 * ) ( V_131 + 1 ) ;
F_8 ( V_579 != F_440 ( V_68 , V_151 ) ) ;
}
V_126 = F_92 ( V_68 , V_131 ) ;
if ( V_126 < V_171 ) {
F_178 ( V_15 ,
L_22 ,
V_171 , V_126 , V_29 ) ;
V_31 = - V_550 ;
F_167 ( V_124 , V_31 ) ;
goto V_81;
}
V_126 -= V_171 ;
if ( V_126 > 0 ) {
if ( V_143 )
F_143 ( V_143 , V_68 , V_131 ) ;
if ( V_176 ) {
F_35 ( ! V_582 ) ;
} else {
F_103 ( V_68 , V_131 , V_126 ) ;
F_108 ( V_68 ) ;
}
if ( V_582 ) {
V_31 = F_152 ( V_124 , V_15 , V_66 ,
V_176 , V_171 ,
V_196 , & V_172 ) ;
if ( V_31 ) {
F_167 ( V_124 , V_31 ) ;
goto V_81;
}
}
} else {
if ( V_582 ) {
F_35 ( V_196 && V_171 !=
F_131 ( V_66 , V_176 ) ) ;
if ( V_176 ) {
F_35 ( V_66 -> V_83 [ 0 ] != V_581 ) ;
} else {
F_35 ( V_66 -> V_83 [ 0 ] != V_581 + 1 ) ;
V_66 -> V_83 [ 0 ] = V_581 ;
V_583 = 2 ;
}
}
V_172 = 1 ;
V_31 = F_441 ( V_124 , V_64 , V_66 , V_66 -> V_83 [ 0 ] ,
V_583 ) ;
if ( V_31 ) {
F_167 ( V_124 , V_31 ) ;
goto V_81;
}
F_48 ( V_66 ) ;
if ( V_196 ) {
V_31 = F_185 ( V_124 , V_15 , V_29 , V_37 ) ;
if ( V_31 ) {
F_167 ( V_124 , V_31 ) ;
goto V_81;
}
}
V_31 = F_442 ( V_124 , V_15 , V_29 , V_37 ) ;
if ( V_31 ) {
F_167 ( V_124 , V_31 ) ;
goto V_81;
}
V_31 = F_416 ( V_124 , V_15 , V_29 , V_37 , 0 ) ;
if ( V_31 ) {
F_167 ( V_124 , V_31 ) ;
goto V_81;
}
}
F_48 ( V_66 ) ;
V_81:
F_56 ( V_66 ) ;
return V_31 ;
}
static T_1 int F_443 ( struct V_123 * V_124 ,
T_2 V_29 )
{
struct V_127 * V_112 ;
struct V_128 * V_129 ;
int V_31 = 0 ;
V_129 = & V_124 -> V_141 -> V_129 ;
F_12 ( & V_129 -> V_50 ) ;
V_112 = F_97 ( V_129 , V_29 ) ;
if ( ! V_112 )
goto V_584;
F_12 ( & V_112 -> V_50 ) ;
if ( ! F_188 ( & V_112 -> V_238 ) )
goto V_81;
if ( V_112 -> V_143 ) {
if ( ! V_112 -> V_243 )
goto V_81;
F_197 ( V_112 -> V_143 ) ;
V_112 -> V_143 = NULL ;
}
if ( ! F_98 ( & V_112 -> V_86 ) )
goto V_81;
V_112 -> V_142 . V_247 = 0 ;
F_199 ( & V_112 -> V_249 , & V_129 -> V_250 ) ;
F_201 ( & V_129 -> V_251 ) ;
V_129 -> V_248 -- ;
if ( V_112 -> V_245 == 0 )
V_129 -> V_246 -- ;
V_112 -> V_245 = 0 ;
F_14 ( & V_112 -> V_50 ) ;
F_14 ( & V_129 -> V_50 ) ;
F_35 ( V_112 -> V_143 ) ;
if ( V_112 -> V_243 )
V_31 = 1 ;
F_50 ( & V_112 -> V_86 ) ;
F_99 ( & V_112 -> V_142 ) ;
return V_31 ;
V_81:
F_14 ( & V_112 -> V_50 ) ;
V_584:
F_14 ( & V_129 -> V_50 ) ;
return 0 ;
}
void F_444 ( struct V_123 * V_124 ,
struct V_63 * V_12 ,
struct V_67 * V_297 ,
T_2 V_19 , int V_172 )
{
struct V_14 * V_36 = V_12 -> V_36 ;
int V_585 = 1 ;
int V_31 ;
if ( V_12 -> V_293 . V_24 != V_222 ) {
int V_220 , V_221 ;
V_31 = F_164 ( V_36 , V_124 , V_297 -> V_34 ,
V_297 -> V_47 , V_19 ,
V_12 -> V_293 . V_24 ,
F_248 ( V_297 ) ,
V_231 , NULL ,
& V_220 , & V_221 ) ;
F_35 ( V_31 ) ;
V_585 = V_220 >= 0 && V_221 < 0 ;
}
if ( V_172 && F_445 ( V_297 ) == V_124 -> V_280 ) {
struct V_1 * V_2 ;
if ( V_12 -> V_293 . V_24 != V_222 ) {
V_31 = F_443 ( V_124 , V_297 -> V_34 ) ;
if ( ! V_31 )
goto V_81;
}
V_585 = 0 ;
V_2 = F_79 ( V_36 , V_297 -> V_34 ) ;
if ( F_446 ( V_297 , V_586 ) ) {
F_421 ( V_36 , V_2 , V_297 -> V_34 ,
V_297 -> V_47 , 1 ) ;
F_6 ( V_2 ) ;
goto V_81;
}
F_8 ( F_231 ( V_587 , & V_297 -> V_588 ) ) ;
F_34 ( V_2 , V_297 -> V_34 , V_297 -> V_47 ) ;
F_430 ( V_2 , V_297 -> V_47 , 0 ) ;
F_6 ( V_2 ) ;
F_447 ( V_36 , V_297 -> V_34 , V_297 -> V_47 ) ;
}
V_81:
if ( V_585 )
F_84 ( V_36 , V_297 -> V_47 , F_248 ( V_297 ) ,
V_12 -> V_293 . V_24 ) ;
if ( V_172 ) {
F_448 ( V_589 , & V_297 -> V_588 ) ;
}
}
int V_304 ( struct V_123 * V_124 ,
struct V_14 * V_36 ,
T_2 V_29 , T_2 V_37 , T_2 V_19 , T_2 V_116 ,
T_2 V_115 , T_2 V_35 )
{
int V_220 , V_221 ;
int V_31 ;
if ( F_246 ( V_36 ) )
return 0 ;
if ( V_116 == V_222 ) {
F_8 ( V_115 >= V_117 ) ;
F_181 ( V_36 , V_29 , V_37 , 1 ) ;
V_220 = V_221 = 0 ;
V_31 = 0 ;
} else if ( V_115 < V_117 ) {
V_31 = F_164 ( V_36 , V_124 , V_29 ,
V_37 , V_19 ,
V_116 , ( int ) V_115 ,
V_231 , NULL ,
& V_220 , & V_221 ) ;
} else {
V_31 = F_165 ( V_36 , V_124 , V_29 ,
V_37 , V_19 ,
V_116 , V_115 , V_35 ,
0 , V_231 ,
& V_220 , & V_221 ) ;
}
if ( V_31 == 0 && V_220 >= 0 && V_221 < 0 )
F_84 ( V_36 , V_37 , V_115 , V_116 ) ;
return V_31 ;
}
static T_1 void
F_449 ( struct V_1 * V_2 ,
T_2 V_37 )
{
struct V_48 * V_51 ;
V_51 = F_26 ( V_2 ) ;
if ( ! V_51 )
return;
F_285 ( V_51 -> V_89 , F_1 ( V_2 ) ||
( V_2 -> V_13 -> V_590 >= V_37 ) ) ;
F_28 ( V_51 ) ;
}
static T_1 int
F_450 ( struct V_1 * V_2 )
{
struct V_48 * V_51 ;
int V_31 = 0 ;
V_51 = F_26 ( V_2 ) ;
if ( ! V_51 )
return ( V_2 -> V_3 == V_5 ) ? - V_187 : 0 ;
F_285 ( V_51 -> V_89 , F_1 ( V_2 ) ) ;
if ( V_2 -> V_3 == V_5 )
V_31 = - V_187 ;
F_28 ( V_51 ) ;
return V_31 ;
}
int F_451 ( T_2 V_7 )
{
if ( V_7 & V_368 )
return V_591 ;
else if ( V_7 & V_367 )
return V_592 ;
else if ( V_7 & V_366 )
return V_593 ;
else if ( V_7 & V_396 )
return V_594 ;
else if ( V_7 & V_395 )
return V_595 ;
else if ( V_7 & V_394 )
return V_596 ;
return V_597 ;
}
int F_452 ( struct V_1 * V_2 )
{
return F_451 ( V_2 -> V_7 ) ;
}
static const char * F_453 ( enum V_598 type )
{
if ( type >= V_351 )
return NULL ;
return V_599 [ type ] ;
}
static inline void
F_454 ( struct V_1 * V_2 ,
int V_557 )
{
if ( V_557 )
F_53 ( & V_2 -> V_600 ) ;
}
static inline void
F_455 ( struct V_1 * V_2 ,
int V_557 )
{
F_4 ( V_2 ) ;
if ( V_557 )
F_53 ( & V_2 -> V_600 ) ;
}
static struct V_1 *
F_456 ( struct V_1 * V_16 ,
struct V_558 * V_566 ,
int V_557 )
{
struct V_1 * V_601 = NULL ;
F_12 ( & V_566 -> V_602 ) ;
while ( 1 ) {
V_601 = V_566 -> V_16 ;
if ( ! V_601 )
return NULL ;
if ( V_601 == V_16 )
return V_601 ;
F_4 ( V_601 ) ;
if ( ! V_557 )
return V_601 ;
if ( F_351 ( & V_601 -> V_600 ) )
return V_601 ;
F_14 ( & V_566 -> V_602 ) ;
F_457 ( & V_601 -> V_600 , V_603 ) ;
F_12 ( & V_566 -> V_602 ) ;
if ( V_601 == V_566 -> V_16 )
return V_601 ;
F_49 ( & V_601 -> V_600 ) ;
F_6 ( V_601 ) ;
}
}
static inline void
F_458 ( struct V_1 * V_2 ,
int V_557 )
{
if ( V_557 )
F_49 ( & V_2 -> V_600 ) ;
F_6 ( V_2 ) ;
}
static T_1 int F_459 ( struct V_14 * V_36 ,
T_2 V_556 , T_2 V_37 , T_2 V_604 ,
T_2 V_605 , struct V_69 * V_228 ,
T_2 V_7 , int V_557 )
{
int V_31 = 0 ;
struct V_63 * V_12 = V_36 -> V_64 ;
struct V_558 * V_606 = NULL ;
struct V_1 * V_16 = NULL ;
T_2 V_549 = 0 ;
T_2 V_569 = 0 ;
T_2 V_559 = 0 ;
struct V_110 * V_94 ;
int V_607 = 0 ;
int V_608 = F_451 ( V_7 ) ;
bool V_609 = false ;
bool V_610 = false ;
bool V_611 = true ;
bool V_612 = false ;
bool V_613 = false ;
bool V_614 = false ;
F_8 ( V_37 < V_36 -> V_55 ) ;
V_228 -> type = V_79 ;
V_228 -> V_24 = 0 ;
V_228 -> V_35 = 0 ;
F_460 ( V_36 , V_37 , V_604 , V_7 ) ;
V_94 = F_80 ( V_36 , V_7 ) ;
if ( ! V_94 ) {
F_178 ( V_36 , L_23 , V_7 ) ;
return - V_326 ;
}
if ( F_377 ( V_94 -> V_569 ) ) {
F_12 ( & V_94 -> V_50 ) ;
if ( V_94 -> V_569 &&
V_37 > V_94 -> V_569 ) {
V_228 -> V_35 = V_94 -> V_569 ;
F_14 ( & V_94 -> V_50 ) ;
return - V_326 ;
} else if ( V_94 -> V_569 ) {
V_611 = false ;
}
F_14 ( & V_94 -> V_50 ) ;
}
V_606 = F_432 ( V_36 , V_94 , & V_559 ) ;
if ( V_606 ) {
F_12 ( & V_606 -> V_50 ) ;
if ( V_606 -> V_16 )
V_605 = V_606 -> V_615 ;
if ( V_606 -> V_568 ) {
V_605 = V_606 -> V_615 ;
V_611 = false ;
}
F_14 ( & V_606 -> V_50 ) ;
}
V_549 = F_461 ( V_549 , V_28 ( V_36 , 0 ) ) ;
V_549 = F_461 ( V_549 , V_605 ) ;
if ( V_549 == V_605 ) {
V_16 = F_79 ( V_36 , V_549 ) ;
if ( V_16 && F_3 ( V_16 , V_7 ) &&
V_16 -> V_3 != V_102 ) {
F_53 ( & V_94 -> V_353 ) ;
if ( F_188 ( & V_16 -> V_98 ) ||
V_16 -> V_319 ) {
F_6 ( V_16 ) ;
F_49 ( & V_94 -> V_353 ) ;
} else {
V_608 = F_452 ( V_16 ) ;
F_454 ( V_16 , V_557 ) ;
goto V_616;
}
} else if ( V_16 ) {
F_6 ( V_16 ) ;
}
}
V_617:
V_612 = false ;
if ( V_608 == 0 || V_608 == F_451 ( V_7 ) )
V_614 = true ;
F_53 ( & V_94 -> V_353 ) ;
F_239 (block_group, &space_info->block_groups[index],
list) {
T_2 V_35 ;
int V_3 ;
if ( F_377 ( V_16 -> V_319 ) )
continue;
F_455 ( V_16 , V_557 ) ;
V_549 = V_16 -> V_23 . V_24 ;
if ( ! F_3 ( V_16 , V_7 ) ) {
T_2 V_618 = V_366 |
V_367 |
V_395 |
V_394 |
V_368 ;
if ( ( V_7 & V_618 ) && ! ( V_16 -> V_7 & V_618 ) )
goto V_607;
}
V_616:
V_3 = F_1 ( V_16 ) ;
if ( F_377 ( ! V_3 ) ) {
V_612 = true ;
V_31 = F_62 ( V_16 , 0 ) ;
F_35 ( V_31 < 0 ) ;
V_31 = 0 ;
}
if ( F_377 ( V_16 -> V_3 == V_5 ) )
goto V_607;
if ( V_606 && V_611 ) {
struct V_1 * V_619 ;
unsigned long V_620 ;
V_619 = F_456 ( V_16 ,
V_606 ,
V_557 ) ;
if ( ! V_619 )
goto V_621;
if ( V_619 != V_16 &&
( V_619 -> V_319 ||
! F_3 ( V_619 , V_7 ) ) )
goto V_622;
V_35 = F_462 ( V_619 ,
V_606 ,
V_37 ,
V_619 -> V_23 . V_24 ,
& V_569 ) ;
if ( V_35 ) {
F_14 ( & V_606 -> V_602 ) ;
F_463 ( V_36 ,
V_619 ,
V_549 , V_37 ) ;
if ( V_619 != V_16 ) {
F_458 ( V_16 ,
V_557 ) ;
V_16 = V_619 ;
}
goto V_623;
}
F_8 ( V_606 -> V_16 != V_619 ) ;
V_622:
if ( V_607 >= V_624 &&
V_619 != V_16 ) {
F_14 ( & V_606 -> V_602 ) ;
F_458 ( V_619 ,
V_557 ) ;
goto V_625;
}
F_464 ( NULL , V_606 ) ;
if ( V_619 != V_16 )
F_458 ( V_619 ,
V_557 ) ;
V_621:
if ( V_607 >= V_624 ) {
F_14 ( & V_606 -> V_602 ) ;
goto V_625;
}
V_620 = F_38 (unsigned long,
empty_cluster + empty_size,
block_group->full_stripe_len) ;
V_31 = F_465 ( V_36 , V_16 ,
V_606 , V_549 ,
V_37 ,
V_620 ) ;
if ( V_31 == 0 ) {
V_35 = F_462 ( V_16 ,
V_606 ,
V_37 ,
V_549 ,
& V_569 ) ;
if ( V_35 ) {
F_14 ( & V_606 -> V_602 ) ;
F_463 ( V_36 ,
V_16 , V_549 ,
V_37 ) ;
goto V_623;
}
} else if ( ! V_3 && V_607 > V_626
&& ! V_609 ) {
F_14 ( & V_606 -> V_602 ) ;
V_609 = true ;
F_449 ( V_16 ,
V_37 + V_559 + V_604 ) ;
goto V_616;
}
F_464 ( NULL , V_606 ) ;
F_14 ( & V_606 -> V_602 ) ;
goto V_607;
}
V_625:
if ( F_377 ( V_606 ) ) {
F_12 ( & V_606 -> V_50 ) ;
V_606 -> V_568 = 1 ;
F_14 ( & V_606 -> V_50 ) ;
}
if ( V_3 ) {
struct V_627 * V_49 =
V_16 -> V_13 ;
F_12 ( & V_49 -> V_628 ) ;
if ( V_49 -> V_590 <
V_37 + V_559 + V_604 ) {
if ( V_49 -> V_590 > V_569 )
V_569 = V_49 -> V_590 ;
F_14 ( & V_49 -> V_628 ) ;
goto V_607;
}
F_14 ( & V_49 -> V_628 ) ;
}
V_35 = F_466 ( V_16 , V_549 ,
V_37 , V_604 ,
& V_569 ) ;
if ( ! V_35 && ! V_610 && ! V_3 &&
V_607 > V_626 ) {
F_449 ( V_16 ,
V_37 + V_604 ) ;
V_610 = true ;
goto V_616;
} else if ( ! V_35 ) {
goto V_607;
}
V_623:
V_549 = F_154 ( V_35 , V_36 -> V_629 ) ;
if ( V_549 + V_37 >
V_16 -> V_23 . V_24 + V_16 -> V_23 . V_35 ) {
F_34 ( V_16 , V_35 , V_37 ) ;
goto V_607;
}
if ( V_35 < V_549 )
F_34 ( V_16 , V_35 ,
V_549 - V_35 ) ;
F_35 ( V_35 > V_549 ) ;
V_31 = F_429 ( V_16 , V_556 ,
V_37 , V_557 ) ;
if ( V_31 == - V_190 ) {
F_34 ( V_16 , V_35 , V_37 ) ;
goto V_607;
}
F_425 ( V_16 ) ;
V_228 -> V_24 = V_549 ;
V_228 -> V_35 = V_37 ;
F_467 ( V_36 , V_16 ,
V_549 , V_37 ) ;
F_458 ( V_16 , V_557 ) ;
break;
V_607:
V_609 = false ;
V_610 = false ;
F_35 ( V_608 != F_452 ( V_16 ) ) ;
F_458 ( V_16 , V_557 ) ;
F_51 () ;
}
F_49 ( & V_94 -> V_353 ) ;
if ( ( V_607 == V_626 ) && V_612
&& ! V_613 )
V_613 = true ;
if ( ! V_228 -> V_24 && V_607 >= V_630 && V_612 )
goto V_617;
if ( ! V_228 -> V_24 && ++ V_608 < V_351 )
goto V_617;
if ( ! V_228 -> V_24 && V_607 < V_624 ) {
V_608 = 0 ;
if ( V_607 == V_626 ) {
if ( V_613 || ! V_614 )
V_607 = V_630 ;
else
V_607 = V_631 ;
} else {
V_607 ++ ;
}
if ( V_607 == V_631 ) {
struct V_123 * V_124 ;
int V_632 = 0 ;
V_124 = V_409 -> V_410 ;
if ( V_124 )
V_632 = 1 ;
else
V_124 = F_221 ( V_12 ) ;
if ( F_222 ( V_124 ) ) {
V_31 = F_223 ( V_124 ) ;
goto V_81;
}
V_31 = F_320 ( V_124 , V_36 , V_7 ,
V_413 ) ;
if ( V_31 == - V_326 )
V_607 = V_624 ;
if ( V_31 < 0 && V_31 != - V_326 )
F_167 ( V_124 , V_31 ) ;
else
V_31 = 0 ;
if ( ! V_632 )
F_225 ( V_124 ) ;
if ( V_31 )
goto V_81;
}
if ( V_607 == V_624 ) {
if ( V_604 == 0 &&
V_559 == 0 ) {
V_31 = - V_326 ;
goto V_81;
}
V_604 = 0 ;
V_559 = 0 ;
}
goto V_617;
} else if ( ! V_228 -> V_24 ) {
V_31 = - V_326 ;
} else if ( V_228 -> V_24 ) {
if ( ! V_611 && V_606 ) {
F_12 ( & V_606 -> V_50 ) ;
V_606 -> V_615 = V_228 -> V_24 ;
F_14 ( & V_606 -> V_50 ) ;
}
V_31 = 0 ;
}
V_81:
if ( V_31 == - V_326 ) {
F_12 ( & V_94 -> V_50 ) ;
V_94 -> V_569 = V_569 ;
F_14 ( & V_94 -> V_50 ) ;
V_228 -> V_35 = V_569 ;
}
return V_31 ;
}
static void F_343 ( struct V_14 * V_36 ,
struct V_110 * V_15 , T_2 V_215 ,
int V_633 )
{
struct V_1 * V_2 ;
int V_608 = 0 ;
F_12 ( & V_15 -> V_50 ) ;
F_342 ( V_36 , L_24 ,
V_15 -> V_7 ,
V_15 -> V_363 - F_317 ( V_15 , true ) ,
V_15 -> V_122 ? L_25 : L_26 ) ;
F_342 ( V_36 ,
L_27 ,
V_15 -> V_363 , V_15 -> V_93 , V_15 -> V_403 ,
V_15 -> V_402 , V_15 -> V_404 ,
V_15 -> V_364 ) ;
F_14 ( & V_15 -> V_50 ) ;
if ( ! V_633 )
return;
F_53 ( & V_15 -> V_353 ) ;
V_167:
F_239 (cache, &info->block_groups[index], list) {
F_12 ( & V_2 -> V_50 ) ;
F_342 ( V_36 ,
L_28 ,
V_2 -> V_23 . V_24 , V_2 -> V_23 . V_35 ,
F_61 ( & V_2 -> V_95 ) , V_2 -> V_9 ,
V_2 -> V_10 , V_2 -> V_319 ? L_29 : L_25 ) ;
F_468 ( V_2 , V_215 ) ;
F_14 ( & V_2 -> V_50 ) ;
}
if ( ++ V_608 < V_351 )
goto V_167;
F_49 ( & V_15 -> V_353 ) ;
}
int F_469 ( struct V_63 * V_12 , T_2 V_556 ,
T_2 V_37 , T_2 V_634 ,
T_2 V_604 , T_2 V_605 ,
struct V_69 * V_228 , int V_196 , int V_557 )
{
struct V_14 * V_36 = V_12 -> V_36 ;
bool V_635 = V_37 == V_634 ;
T_2 V_7 ;
int V_31 ;
V_7 = F_313 ( V_12 , V_196 ) ;
V_167:
F_8 ( V_37 < V_36 -> V_55 ) ;
V_31 = F_459 ( V_36 , V_556 , V_37 , V_604 ,
V_605 , V_228 , V_7 , V_557 ) ;
if ( ! V_31 && ! V_196 ) {
F_426 ( V_36 , V_228 -> V_24 ) ;
} else if ( V_31 == - V_326 ) {
if ( ! V_635 && V_228 -> V_35 ) {
V_37 = F_356 ( V_37 >> 1 , V_228 -> V_35 ) ;
V_37 = F_155 ( V_37 ,
V_36 -> V_55 ) ;
V_37 = F_461 ( V_37 , V_634 ) ;
V_556 = V_37 ;
if ( V_37 == V_634 )
V_635 = true ;
goto V_167;
} else if ( F_269 ( V_36 , V_432 ) ) {
struct V_110 * V_421 ;
V_421 = F_80 ( V_36 , V_7 ) ;
F_178 ( V_36 ,
L_30 ,
V_7 , V_37 ) ;
if ( V_421 )
F_343 ( V_36 , V_421 , V_37 , 1 ) ;
}
}
return V_31 ;
}
static int F_470 ( struct V_14 * V_36 ,
T_2 V_34 , T_2 V_47 ,
int V_585 , int V_557 )
{
struct V_1 * V_2 ;
int V_31 = 0 ;
V_2 = F_79 ( V_36 , V_34 ) ;
if ( ! V_2 ) {
F_178 ( V_36 , L_31 ,
V_34 ) ;
return - V_326 ;
}
if ( V_585 )
F_421 ( V_36 , V_2 , V_34 , V_47 , 1 ) ;
else {
if ( F_269 ( V_36 , V_575 ) )
V_31 = F_158 ( V_36 , V_34 , V_47 , NULL ) ;
F_34 ( V_2 , V_34 , V_47 ) ;
F_430 ( V_2 , V_47 , V_557 ) ;
F_447 ( V_36 , V_34 , V_47 ) ;
}
F_6 ( V_2 ) ;
return V_31 ;
}
int F_471 ( struct V_14 * V_36 ,
T_2 V_34 , T_2 V_47 , int V_557 )
{
return F_470 ( V_36 , V_34 , V_47 , 0 , V_557 ) ;
}
int F_472 ( struct V_14 * V_36 ,
T_2 V_34 , T_2 V_47 )
{
return F_470 ( V_36 , V_34 , V_47 , 1 , 0 ) ;
}
static int F_171 ( struct V_123 * V_124 ,
struct V_14 * V_36 ,
T_2 V_19 , T_2 V_116 ,
T_2 V_7 , T_2 V_115 , T_2 V_35 ,
struct V_69 * V_228 , int V_146 )
{
int V_31 ;
struct V_130 * V_636 ;
struct V_175 * V_176 ;
struct V_65 * V_66 ;
struct V_67 * V_68 ;
int type ;
T_3 V_59 ;
if ( V_19 > 0 )
type = V_165 ;
else
type = V_166 ;
V_59 = sizeof( * V_636 ) + F_138 ( type ) ;
V_66 = F_37 () ;
if ( ! V_66 )
return - V_74 ;
V_66 -> V_225 = 1 ;
V_31 = F_119 ( V_124 , V_36 -> V_64 , V_66 ,
V_228 , V_59 ) ;
if ( V_31 ) {
F_56 ( V_66 ) ;
return V_31 ;
}
V_68 = V_66 -> V_82 [ 0 ] ;
V_636 = F_91 ( V_68 , V_66 -> V_83 [ 0 ] ,
struct V_130 ) ;
F_103 ( V_68 , V_636 , V_146 ) ;
F_104 ( V_68 , V_636 , V_124 -> V_280 ) ;
F_105 ( V_68 , V_636 ,
V_7 | V_156 ) ;
V_176 = (struct V_175 * ) ( V_636 + 1 ) ;
F_145 ( V_68 , V_176 , type ) ;
if ( V_19 > 0 ) {
struct V_170 * V_161 ;
V_161 = (struct V_170 * ) ( V_176 + 1 ) ;
F_146 ( V_68 , V_176 , V_19 ) ;
F_120 ( V_68 , V_161 , V_146 ) ;
} else {
struct V_160 * V_161 ;
V_161 = (struct V_160 * ) ( & V_176 -> V_35 ) ;
F_122 ( V_68 , V_161 , V_116 ) ;
F_123 ( V_68 , V_161 , V_115 ) ;
F_124 ( V_68 , V_161 , V_35 ) ;
F_125 ( V_68 , V_161 , V_146 ) ;
}
F_108 ( V_66 -> V_82 [ 0 ] ) ;
F_56 ( V_66 ) ;
V_31 = F_473 ( V_124 , V_36 , V_228 -> V_24 ,
V_228 -> V_35 ) ;
if ( V_31 )
return V_31 ;
V_31 = F_416 ( V_124 , V_36 , V_228 -> V_24 , V_228 -> V_35 , 1 ) ;
if ( V_31 ) {
F_178 ( V_36 , L_32 ,
V_228 -> V_24 , V_228 -> V_35 ) ;
F_96 () ;
}
F_474 ( V_36 , V_228 -> V_24 , V_228 -> V_35 ) ;
return V_31 ;
}
static int F_179 ( struct V_123 * V_124 ,
struct V_14 * V_36 ,
T_2 V_19 , T_2 V_116 ,
T_2 V_7 , struct V_637 * V_23 ,
int V_179 , struct V_69 * V_228 )
{
int V_31 ;
struct V_130 * V_636 ;
struct V_150 * V_638 ;
struct V_175 * V_176 ;
struct V_65 * V_66 ;
struct V_67 * V_68 ;
T_3 V_59 = sizeof( * V_636 ) + sizeof( * V_176 ) ;
T_2 V_37 = V_228 -> V_35 ;
bool V_185 = F_89 ( V_36 , V_135 ) ;
if ( ! V_185 )
V_59 += sizeof( * V_638 ) ;
V_66 = F_37 () ;
if ( ! V_66 ) {
F_472 ( V_36 , V_228 -> V_24 ,
V_36 -> V_54 ) ;
return - V_74 ;
}
V_66 -> V_225 = 1 ;
V_31 = F_119 ( V_124 , V_36 -> V_64 , V_66 ,
V_228 , V_59 ) ;
if ( V_31 ) {
F_56 ( V_66 ) ;
F_472 ( V_36 , V_228 -> V_24 ,
V_36 -> V_54 ) ;
return V_31 ;
}
V_68 = V_66 -> V_82 [ 0 ] ;
V_636 = F_91 ( V_68 , V_66 -> V_83 [ 0 ] ,
struct V_130 ) ;
F_103 ( V_68 , V_636 , 1 ) ;
F_104 ( V_68 , V_636 , V_124 -> V_280 ) ;
F_105 ( V_68 , V_636 ,
V_7 | V_155 ) ;
if ( V_185 ) {
V_176 = (struct V_175 * ) ( V_636 + 1 ) ;
V_37 = V_36 -> V_54 ;
} else {
V_638 = (struct V_150 * ) ( V_636 + 1 ) ;
F_173 ( V_68 , V_638 , V_23 ) ;
F_107 ( V_68 , V_638 , V_179 ) ;
V_176 = (struct V_175 * ) ( V_638 + 1 ) ;
}
if ( V_19 > 0 ) {
F_35 ( ! ( V_7 & V_140 ) ) ;
F_145 ( V_68 , V_176 ,
V_177 ) ;
F_146 ( V_68 , V_176 , V_19 ) ;
} else {
F_145 ( V_68 , V_176 ,
V_178 ) ;
F_146 ( V_68 , V_176 , V_116 ) ;
}
F_108 ( V_68 ) ;
F_56 ( V_66 ) ;
V_31 = F_473 ( V_124 , V_36 , V_228 -> V_24 ,
V_37 ) ;
if ( V_31 )
return V_31 ;
V_31 = F_416 ( V_124 , V_36 , V_228 -> V_24 ,
V_36 -> V_54 , 1 ) ;
if ( V_31 ) {
F_178 ( V_36 , L_32 ,
V_228 -> V_24 , V_228 -> V_35 ) ;
F_96 () ;
}
F_474 ( V_36 , V_228 -> V_24 ,
V_36 -> V_54 ) ;
return V_31 ;
}
int F_475 ( struct V_123 * V_124 ,
T_2 V_116 , T_2 V_115 ,
T_2 V_35 , T_2 V_556 ,
struct V_69 * V_228 )
{
struct V_14 * V_36 = V_124 -> V_36 ;
int V_31 ;
F_35 ( V_116 == V_222 ) ;
V_31 = F_165 ( V_36 , V_124 , V_228 -> V_24 ,
V_228 -> V_35 , 0 , V_116 , V_115 ,
V_35 , V_556 ,
V_252 , NULL , NULL ) ;
return V_31 ;
}
int F_476 ( struct V_123 * V_124 ,
struct V_14 * V_36 ,
T_2 V_116 , T_2 V_115 , T_2 V_35 ,
struct V_69 * V_228 )
{
int V_31 ;
struct V_1 * V_16 ;
struct V_110 * V_94 ;
if ( ! F_89 ( V_36 , V_554 ) ) {
V_31 = F_423 ( V_36 , V_228 -> V_24 ,
V_228 -> V_35 ) ;
if ( V_31 )
return V_31 ;
}
V_16 = F_79 ( V_36 , V_228 -> V_24 ) ;
if ( ! V_16 )
return - V_550 ;
V_94 = V_16 -> V_94 ;
F_12 ( & V_94 -> V_50 ) ;
F_12 ( & V_16 -> V_50 ) ;
V_94 -> V_402 += V_228 -> V_35 ;
V_16 -> V_10 += V_228 -> V_35 ;
F_14 ( & V_16 -> V_50 ) ;
F_14 ( & V_94 -> V_50 ) ;
V_31 = F_171 ( V_124 , V_36 , 0 , V_116 ,
0 , V_115 , V_35 , V_228 , 1 ) ;
F_6 ( V_16 ) ;
return V_31 ;
}
static struct V_67 *
F_477 ( struct V_123 * V_124 , struct V_63 * V_12 ,
T_2 V_29 , int V_179 )
{
struct V_14 * V_36 = V_12 -> V_36 ;
struct V_67 * V_297 ;
V_297 = F_478 ( V_36 , V_29 ) ;
if ( F_222 ( V_297 ) )
return V_297 ;
F_479 ( V_297 , V_124 -> V_280 ) ;
F_480 ( V_12 -> V_293 . V_24 , V_297 , V_179 ) ;
F_481 ( V_297 ) ;
F_482 ( V_36 , V_297 ) ;
F_448 ( V_639 , & V_297 -> V_588 ) ;
F_483 ( V_297 ) ;
F_484 ( V_297 ) ;
if ( V_12 -> V_293 . V_24 == V_222 ) {
V_297 -> V_640 = V_12 -> V_641 % 2 ;
if ( V_297 -> V_640 == 0 )
F_420 ( & V_12 -> V_642 , V_297 -> V_34 ,
V_297 -> V_34 + V_297 -> V_47 - 1 , V_97 ) ;
else
F_485 ( & V_12 -> V_642 , V_297 -> V_34 ,
V_297 -> V_34 + V_297 -> V_47 - 1 ) ;
} else {
V_297 -> V_640 = - 1 ;
F_420 ( & V_124 -> V_141 -> V_643 , V_297 -> V_34 ,
V_297 -> V_34 + V_297 -> V_47 - 1 , V_97 ) ;
}
V_124 -> V_333 = true ;
return V_297 ;
}
static struct V_268 *
F_486 ( struct V_123 * V_124 ,
struct V_63 * V_12 , T_3 V_644 )
{
struct V_14 * V_36 = V_12 -> V_36 ;
struct V_268 * V_458 ;
struct V_268 * V_269 = & V_36 -> V_272 ;
int V_31 ;
bool V_645 = false ;
V_458 = F_379 ( V_124 , V_12 ) ;
if ( F_377 ( V_458 -> V_59 == 0 ) )
goto V_646;
V_167:
V_31 = F_378 ( V_458 , V_644 ) ;
if ( ! V_31 )
return V_458 ;
if ( V_458 -> V_647 )
return F_487 ( V_31 ) ;
if ( V_458 -> type == V_648 && ! V_645 ) {
V_645 = true ;
F_392 ( V_36 ) ;
goto V_167;
}
if ( F_269 ( V_36 , V_432 ) ) {
static F_488 ( V_649 ,
V_650 * 10 ,
1 ) ;
if ( F_489 ( & V_649 ) )
F_490 ( 1 , V_651
L_33 , V_31 ) ;
}
V_646:
V_31 = F_376 ( V_12 , V_458 , V_644 ,
V_434 ) ;
if ( ! V_31 )
return V_458 ;
if ( V_458 -> type != V_648 &&
V_458 -> V_94 == V_269 -> V_94 ) {
V_31 = F_378 ( V_269 , V_644 ) ;
if ( ! V_31 )
return V_269 ;
}
return F_487 ( V_31 ) ;
}
static void F_491 ( struct V_14 * V_36 ,
struct V_268 * V_458 , T_3 V_644 )
{
F_380 ( V_458 , V_644 , 0 ) ;
F_383 ( V_36 , V_458 , NULL , 0 ) ;
}
struct V_67 * F_492 ( struct V_123 * V_124 ,
struct V_63 * V_12 ,
T_2 V_19 , T_2 V_116 ,
const struct V_637 * V_23 ,
int V_179 , T_2 V_652 ,
T_2 V_604 )
{
struct V_14 * V_36 = V_12 -> V_36 ;
struct V_69 V_228 ;
struct V_268 * V_458 ;
struct V_67 * V_297 ;
struct V_192 * V_143 ;
T_2 V_7 = 0 ;
int V_31 ;
T_3 V_644 = V_36 -> V_54 ;
bool V_185 = F_89 ( V_36 , V_135 ) ;
#ifdef F_493
if ( F_246 ( V_36 ) ) {
V_297 = F_477 ( V_124 , V_12 , V_12 -> V_653 ,
V_179 ) ;
if ( ! F_222 ( V_297 ) )
V_12 -> V_653 += V_644 ;
return V_297 ;
}
#endif
V_458 = F_486 ( V_124 , V_12 , V_644 ) ;
if ( F_222 ( V_458 ) )
return F_494 ( V_458 ) ;
V_31 = F_469 ( V_12 , V_644 , V_644 , V_644 ,
V_604 , V_652 , & V_228 , 0 , 0 ) ;
if ( V_31 )
goto V_654;
V_297 = F_477 ( V_124 , V_12 , V_228 . V_24 , V_179 ) ;
if ( F_222 ( V_297 ) ) {
V_31 = F_223 ( V_297 ) ;
goto V_655;
}
if ( V_116 == V_656 ) {
if ( V_19 == 0 )
V_19 = V_228 . V_24 ;
V_7 |= V_140 ;
} else
F_35 ( V_19 > 0 ) ;
if ( V_116 != V_222 ) {
V_143 = F_236 () ;
if ( ! V_143 ) {
V_31 = - V_74 ;
goto V_657;
}
if ( V_23 )
memcpy ( & V_143 -> V_23 , V_23 , sizeof( V_143 -> V_23 ) ) ;
else
memset ( & V_143 -> V_23 , 0 , sizeof( V_143 -> V_23 ) ) ;
V_143 -> V_145 = V_7 ;
V_143 -> V_232 = V_185 ? false : true ;
V_143 -> V_144 = true ;
V_143 -> V_196 = false ;
V_143 -> V_179 = V_179 ;
V_31 = F_164 ( V_36 , V_124 , V_228 . V_24 ,
V_228 . V_35 , V_19 ,
V_116 , V_179 ,
V_252 ,
V_143 , NULL , NULL ) ;
if ( V_31 )
goto V_658;
}
return V_297 ;
V_658:
F_197 ( V_143 ) ;
V_657:
F_495 ( V_297 ) ;
V_655:
F_471 ( V_36 , V_228 . V_24 , V_228 . V_35 , 0 ) ;
V_654:
F_491 ( V_36 , V_458 , V_644 ) ;
return F_487 ( V_31 ) ;
}
static T_1 void F_496 ( struct V_123 * V_124 ,
struct V_63 * V_12 ,
struct V_659 * V_660 ,
struct V_65 * V_66 )
{
struct V_14 * V_36 = V_12 -> V_36 ;
T_2 V_29 ;
T_2 V_323 ;
T_2 V_126 ;
T_2 V_7 ;
T_3 V_72 ;
struct V_69 V_23 ;
struct V_67 * V_552 ;
int V_31 ;
int V_661 ;
int V_662 = 0 ;
if ( V_66 -> V_83 [ V_660 -> V_179 ] < V_660 -> V_663 ) {
V_660 -> V_664 = V_660 -> V_664 * 2 / 3 ;
V_660 -> V_664 = F_461 ( V_660 -> V_664 , 2 ) ;
} else {
V_660 -> V_664 = V_660 -> V_664 * 3 / 2 ;
V_660 -> V_664 = F_25 ( int , V_660 -> V_664 ,
F_497 ( V_36 ) ) ;
}
V_552 = V_66 -> V_82 [ V_660 -> V_179 ] ;
V_72 = F_42 ( V_552 ) ;
for ( V_661 = V_66 -> V_83 [ V_660 -> V_179 ] ; V_661 < V_72 ; V_661 ++ ) {
if ( V_662 >= V_660 -> V_664 )
break;
F_51 () ;
V_29 = F_253 ( V_552 , V_661 ) ;
V_323 = F_498 ( V_552 , V_661 ) ;
if ( V_661 == V_66 -> V_83 [ V_660 -> V_179 ] )
goto V_77;
if ( V_660 -> V_665 == V_666 &&
V_323 <= V_12 -> V_293 . V_35 )
continue;
V_31 = F_88 ( V_124 , V_36 , V_29 ,
V_660 -> V_179 - 1 , 1 , & V_126 ,
& V_7 ) ;
if ( V_31 < 0 )
continue;
F_35 ( V_126 == 0 ) ;
if ( V_660 -> V_665 == V_667 ) {
if ( V_126 == 1 )
goto V_77;
if ( V_660 -> V_179 == 1 &&
( V_7 & V_140 ) )
continue;
if ( ! V_660 -> V_668 ||
V_323 <= V_12 -> V_293 . V_35 )
continue;
F_136 ( V_552 , & V_23 , V_661 ) ;
V_31 = F_499 ( & V_23 ,
& V_660 -> V_669 ) ;
if ( V_31 < 0 )
continue;
} else {
if ( V_660 -> V_179 == 1 &&
( V_7 & V_140 ) )
continue;
}
V_77:
F_500 ( V_36 , V_29 ) ;
V_662 ++ ;
}
V_660 -> V_663 = V_661 ;
}
static T_1 int F_501 ( struct V_123 * V_124 ,
struct V_63 * V_12 ,
struct V_65 * V_66 ,
struct V_659 * V_660 , int V_670 )
{
struct V_14 * V_36 = V_12 -> V_36 ;
int V_179 = V_660 -> V_179 ;
struct V_67 * V_552 = V_66 -> V_82 [ V_179 ] ;
T_2 V_671 = V_140 ;
int V_31 ;
if ( V_660 -> V_665 == V_666 &&
F_247 ( V_552 ) != V_12 -> V_293 . V_24 )
return 1 ;
if ( V_670 &&
( ( V_660 -> V_665 == V_667 && V_660 -> V_126 [ V_179 ] != 1 ) ||
( V_660 -> V_665 == V_666 && ! ( V_660 -> V_7 [ V_179 ] & V_671 ) ) ) ) {
F_35 ( ! V_66 -> V_672 [ V_179 ] ) ;
V_31 = F_88 ( V_124 , V_36 ,
V_552 -> V_34 , V_179 , 1 ,
& V_660 -> V_126 [ V_179 ] ,
& V_660 -> V_7 [ V_179 ] ) ;
F_35 ( V_31 == - V_74 ) ;
if ( V_31 )
return V_31 ;
F_35 ( V_660 -> V_126 [ V_179 ] == 0 ) ;
}
if ( V_660 -> V_665 == V_667 ) {
if ( V_660 -> V_126 [ V_179 ] > 1 )
return 1 ;
if ( V_66 -> V_672 [ V_179 ] && ! V_660 -> V_186 ) {
F_502 ( V_552 , V_66 -> V_672 [ V_179 ] ) ;
V_66 -> V_672 [ V_179 ] = 0 ;
}
return 0 ;
}
if ( ! ( V_660 -> V_7 [ V_179 ] & V_671 ) ) {
F_35 ( ! V_66 -> V_672 [ V_179 ] ) ;
V_31 = F_254 ( V_124 , V_12 , V_552 , 1 ) ;
F_35 ( V_31 ) ;
V_31 = F_255 ( V_124 , V_12 , V_552 , 0 ) ;
F_35 ( V_31 ) ;
V_31 = F_235 ( V_124 , V_36 , V_552 -> V_34 ,
V_552 -> V_47 , V_671 ,
F_248 ( V_552 ) , 0 ) ;
F_35 ( V_31 ) ;
V_660 -> V_7 [ V_179 ] |= V_671 ;
}
if ( V_66 -> V_672 [ V_179 ] && V_179 > 0 ) {
F_502 ( V_552 , V_66 -> V_672 [ V_179 ] ) ;
V_66 -> V_672 [ V_179 ] = 0 ;
}
return 0 ;
}
static T_1 int F_503 ( struct V_123 * V_124 ,
struct V_63 * V_12 ,
struct V_65 * V_66 ,
struct V_659 * V_660 , int * V_670 )
{
struct V_14 * V_36 = V_12 -> V_36 ;
T_2 V_29 ;
T_2 V_323 ;
T_2 V_19 ;
T_3 V_644 ;
struct V_69 V_23 ;
struct V_67 * V_80 ;
int V_179 = V_660 -> V_179 ;
int V_77 = 0 ;
int V_31 = 0 ;
bool V_673 = false ;
V_323 = F_498 ( V_66 -> V_82 [ V_179 ] ,
V_66 -> V_83 [ V_179 ] ) ;
if ( V_660 -> V_665 == V_666 &&
V_323 <= V_12 -> V_293 . V_35 ) {
* V_670 = 1 ;
return 1 ;
}
V_29 = F_253 ( V_66 -> V_82 [ V_179 ] , V_66 -> V_83 [ V_179 ] ) ;
V_644 = V_36 -> V_54 ;
V_80 = F_504 ( V_36 , V_29 ) ;
if ( ! V_80 ) {
V_80 = F_478 ( V_36 , V_29 ) ;
if ( F_222 ( V_80 ) )
return F_223 ( V_80 ) ;
F_480 ( V_12 -> V_293 . V_24 , V_80 ,
V_179 - 1 ) ;
V_77 = 1 ;
}
F_481 ( V_80 ) ;
F_483 ( V_80 ) ;
V_31 = F_88 ( V_124 , V_36 , V_29 , V_179 - 1 , 1 ,
& V_660 -> V_126 [ V_179 - 1 ] ,
& V_660 -> V_7 [ V_179 - 1 ] ) ;
if ( V_31 < 0 )
goto V_674;
if ( F_377 ( V_660 -> V_126 [ V_179 - 1 ] == 0 ) ) {
F_178 ( V_36 , L_34 ) ;
V_31 = - V_187 ;
goto V_674;
}
* V_670 = 0 ;
if ( V_660 -> V_665 == V_667 ) {
if ( V_660 -> V_126 [ V_179 - 1 ] > 1 ) {
V_673 = true ;
if ( V_179 == 1 &&
( V_660 -> V_7 [ 0 ] & V_140 ) )
goto V_675;
if ( ! V_660 -> V_668 ||
V_323 <= V_12 -> V_293 . V_35 )
goto V_675;
F_136 ( V_66 -> V_82 [ V_179 ] , & V_23 ,
V_66 -> V_83 [ V_179 ] ) ;
V_31 = F_499 ( & V_23 , & V_660 -> V_669 ) ;
if ( V_31 < 0 )
goto V_675;
V_660 -> V_665 = V_666 ;
V_660 -> V_676 = V_179 - 1 ;
}
} else {
if ( V_179 == 1 &&
( V_660 -> V_7 [ 0 ] & V_140 ) )
goto V_675;
}
if ( ! F_505 ( V_80 , V_323 , 0 ) ) {
F_506 ( V_80 ) ;
F_495 ( V_80 ) ;
V_80 = NULL ;
* V_670 = 1 ;
}
if ( ! V_80 ) {
if ( V_77 && V_179 == 1 )
F_496 ( V_124 , V_12 , V_660 , V_66 ) ;
V_80 = F_507 ( V_36 , V_29 , V_323 ) ;
if ( F_222 ( V_80 ) ) {
return F_223 ( V_80 ) ;
} else if ( ! F_508 ( V_80 ) ) {
F_495 ( V_80 ) ;
return - V_187 ;
}
F_481 ( V_80 ) ;
F_483 ( V_80 ) ;
}
V_179 -- ;
ASSERT ( V_179 == F_248 ( V_80 ) ) ;
if ( V_179 != F_248 ( V_80 ) ) {
F_178 ( V_12 -> V_36 , L_35 ) ;
V_31 = - V_187 ;
goto V_674;
}
V_66 -> V_82 [ V_179 ] = V_80 ;
V_66 -> V_83 [ V_179 ] = 0 ;
V_66 -> V_672 [ V_179 ] = V_677 ;
V_660 -> V_179 = V_179 ;
if ( V_660 -> V_179 == 1 )
V_660 -> V_663 = 0 ;
return 0 ;
V_675:
V_660 -> V_126 [ V_179 - 1 ] = 0 ;
V_660 -> V_7 [ V_179 - 1 ] = 0 ;
if ( V_660 -> V_665 == V_667 ) {
if ( V_660 -> V_7 [ V_179 ] & V_140 ) {
V_19 = V_66 -> V_82 [ V_179 ] -> V_34 ;
} else {
ASSERT ( V_12 -> V_293 . V_24 ==
F_247 ( V_66 -> V_82 [ V_179 ] ) ) ;
if ( V_12 -> V_293 . V_24 !=
F_247 ( V_66 -> V_82 [ V_179 ] ) ) {
F_178 ( V_12 -> V_36 ,
L_36 ) ;
V_31 = - V_187 ;
goto V_674;
}
V_19 = 0 ;
}
if ( V_673 ) {
V_31 = F_509 ( V_124 , V_12 , V_80 ,
V_323 , V_179 - 1 ) ;
if ( V_31 ) {
F_510 ( V_36 ,
L_37 ,
V_31 ) ;
}
}
V_31 = V_304 ( V_124 , V_36 , V_29 , V_644 ,
V_19 , V_12 -> V_293 . V_24 ,
V_179 - 1 , 0 ) ;
if ( V_31 )
goto V_674;
}
* V_670 = 1 ;
V_31 = 1 ;
V_674:
F_506 ( V_80 ) ;
F_495 ( V_80 ) ;
return V_31 ;
}
static T_1 int F_511 ( struct V_123 * V_124 ,
struct V_63 * V_12 ,
struct V_65 * V_66 ,
struct V_659 * V_660 )
{
struct V_14 * V_36 = V_12 -> V_36 ;
int V_31 ;
int V_179 = V_660 -> V_179 ;
struct V_67 * V_552 = V_66 -> V_82 [ V_179 ] ;
T_2 V_19 = 0 ;
if ( V_660 -> V_665 == V_666 ) {
F_35 ( V_660 -> V_676 < V_179 ) ;
if ( V_179 < V_660 -> V_676 )
goto V_81;
V_31 = F_45 ( V_66 , V_179 + 1 , & V_660 -> V_669 ) ;
if ( V_31 > 0 )
V_660 -> V_668 = 0 ;
V_660 -> V_665 = V_667 ;
V_660 -> V_676 = - 1 ;
V_66 -> V_83 [ V_179 ] = 0 ;
if ( ! V_66 -> V_672 [ V_179 ] ) {
F_35 ( V_179 == 0 ) ;
F_481 ( V_552 ) ;
F_483 ( V_552 ) ;
V_66 -> V_672 [ V_179 ] = V_677 ;
V_31 = F_88 ( V_124 , V_36 ,
V_552 -> V_34 , V_179 , 1 ,
& V_660 -> V_126 [ V_179 ] ,
& V_660 -> V_7 [ V_179 ] ) ;
if ( V_31 < 0 ) {
F_502 ( V_552 , V_66 -> V_672 [ V_179 ] ) ;
V_66 -> V_672 [ V_179 ] = 0 ;
return V_31 ;
}
F_35 ( V_660 -> V_126 [ V_179 ] == 0 ) ;
if ( V_660 -> V_126 [ V_179 ] == 1 ) {
F_502 ( V_552 , V_66 -> V_672 [ V_179 ] ) ;
V_66 -> V_672 [ V_179 ] = 0 ;
return 1 ;
}
}
}
F_35 ( V_660 -> V_126 [ V_179 ] > 1 && ! V_66 -> V_672 [ V_179 ] ) ;
if ( V_660 -> V_126 [ V_179 ] == 1 ) {
if ( V_179 == 0 ) {
if ( V_660 -> V_7 [ V_179 ] & V_140 )
V_31 = F_255 ( V_124 , V_12 , V_552 , 1 ) ;
else
V_31 = F_255 ( V_124 , V_12 , V_552 , 0 ) ;
F_35 ( V_31 ) ;
V_31 = F_512 ( V_124 , V_36 , V_552 ) ;
if ( V_31 ) {
F_510 ( V_36 ,
L_38 ,
V_31 ) ;
}
}
if ( ! V_66 -> V_672 [ V_179 ] &&
F_445 ( V_552 ) == V_124 -> V_280 ) {
F_481 ( V_552 ) ;
F_483 ( V_552 ) ;
V_66 -> V_672 [ V_179 ] = V_677 ;
}
F_482 ( V_36 , V_552 ) ;
}
if ( V_552 == V_12 -> V_142 ) {
if ( V_660 -> V_7 [ V_179 ] & V_140 )
V_19 = V_552 -> V_34 ;
else
F_35 ( V_12 -> V_293 . V_24 !=
F_247 ( V_552 ) ) ;
} else {
if ( V_660 -> V_7 [ V_179 + 1 ] & V_140 )
V_19 = V_66 -> V_82 [ V_179 + 1 ] -> V_34 ;
else
F_35 ( V_12 -> V_293 . V_24 !=
F_247 ( V_66 -> V_82 [ V_179 + 1 ] ) ) ;
}
F_444 ( V_124 , V_12 , V_552 , V_19 , V_660 -> V_126 [ V_179 ] == 1 ) ;
V_81:
V_660 -> V_126 [ V_179 ] = 0 ;
V_660 -> V_7 [ V_179 ] = 0 ;
return 0 ;
}
static T_1 int F_513 ( struct V_123 * V_124 ,
struct V_63 * V_12 ,
struct V_65 * V_66 ,
struct V_659 * V_660 )
{
int V_179 = V_660 -> V_179 ;
int V_670 = 1 ;
int V_31 ;
while ( V_179 >= 0 ) {
V_31 = F_501 ( V_124 , V_12 , V_66 , V_660 , V_670 ) ;
if ( V_31 > 0 )
break;
if ( V_179 == 0 )
break;
if ( V_66 -> V_83 [ V_179 ] >=
F_42 ( V_66 -> V_82 [ V_179 ] ) )
break;
V_31 = F_503 ( V_124 , V_12 , V_66 , V_660 , & V_670 ) ;
if ( V_31 > 0 ) {
V_66 -> V_83 [ V_179 ] ++ ;
continue;
} else if ( V_31 < 0 )
return V_31 ;
V_179 = V_660 -> V_179 ;
}
return 0 ;
}
static T_1 int F_514 ( struct V_123 * V_124 ,
struct V_63 * V_12 ,
struct V_65 * V_66 ,
struct V_659 * V_660 , int V_678 )
{
int V_179 = V_660 -> V_179 ;
int V_31 ;
V_66 -> V_83 [ V_179 ] = F_42 ( V_66 -> V_82 [ V_179 ] ) ;
while ( V_179 < V_678 && V_66 -> V_82 [ V_179 ] ) {
V_660 -> V_179 = V_179 ;
if ( V_66 -> V_83 [ V_179 ] + 1 <
F_42 ( V_66 -> V_82 [ V_179 ] ) ) {
V_66 -> V_83 [ V_179 ] ++ ;
return 0 ;
} else {
V_31 = F_511 ( V_124 , V_12 , V_66 , V_660 ) ;
if ( V_31 > 0 )
return 0 ;
if ( V_66 -> V_672 [ V_179 ] ) {
F_502 ( V_66 -> V_82 [ V_179 ] ,
V_66 -> V_672 [ V_179 ] ) ;
V_66 -> V_672 [ V_179 ] = 0 ;
}
F_495 ( V_66 -> V_82 [ V_179 ] ) ;
V_66 -> V_82 [ V_179 ] = NULL ;
V_179 ++ ;
}
}
return 1 ;
}
int F_515 ( struct V_63 * V_12 ,
struct V_268 * V_458 , int V_668 ,
int V_679 )
{
struct V_14 * V_36 = V_12 -> V_36 ;
struct V_65 * V_66 ;
struct V_123 * V_124 ;
struct V_63 * V_281 = V_36 -> V_281 ;
struct V_680 * V_294 = & V_12 -> V_294 ;
struct V_659 * V_660 ;
struct V_69 V_23 ;
int V_163 = 0 ;
int V_31 ;
int V_179 ;
bool V_681 = false ;
F_198 ( V_36 , L_39 , V_12 -> V_24 ) ;
V_66 = F_37 () ;
if ( ! V_66 ) {
V_163 = - V_74 ;
goto V_81;
}
V_660 = F_64 ( sizeof( * V_660 ) , V_97 ) ;
if ( ! V_660 ) {
F_56 ( V_66 ) ;
V_163 = - V_74 ;
goto V_81;
}
V_124 = F_516 ( V_281 , 0 ) ;
if ( F_222 ( V_124 ) ) {
V_163 = F_223 ( V_124 ) ;
goto V_137;
}
if ( V_458 )
V_124 -> V_458 = V_458 ;
if ( F_517 ( & V_294 -> V_682 ) == 0 ) {
V_179 = F_248 ( V_12 -> V_142 ) ;
V_66 -> V_82 [ V_179 ] = F_518 ( V_12 ) ;
F_483 ( V_66 -> V_82 [ V_179 ] ) ;
V_66 -> V_83 [ V_179 ] = 0 ;
V_66 -> V_672 [ V_179 ] = V_677 ;
memset ( & V_660 -> V_669 , 0 ,
sizeof( V_660 -> V_669 ) ) ;
} else {
F_519 ( & V_23 , & V_294 -> V_682 ) ;
memcpy ( & V_660 -> V_669 , & V_23 ,
sizeof( V_660 -> V_669 ) ) ;
V_179 = V_294 -> V_683 ;
F_35 ( V_179 == 0 ) ;
V_66 -> V_684 = V_179 ;
V_31 = F_41 ( NULL , V_12 , & V_23 , V_66 , 0 , 0 ) ;
V_66 -> V_684 = 0 ;
if ( V_31 < 0 ) {
V_163 = V_31 ;
goto V_685;
}
F_8 ( V_31 > 0 ) ;
F_141 ( V_66 , 0 ) ;
V_179 = F_248 ( V_12 -> V_142 ) ;
while ( 1 ) {
F_481 ( V_66 -> V_82 [ V_179 ] ) ;
F_483 ( V_66 -> V_82 [ V_179 ] ) ;
V_66 -> V_672 [ V_179 ] = V_677 ;
V_31 = F_88 ( V_124 , V_36 ,
V_66 -> V_82 [ V_179 ] -> V_34 ,
V_179 , 1 , & V_660 -> V_126 [ V_179 ] ,
& V_660 -> V_7 [ V_179 ] ) ;
if ( V_31 < 0 ) {
V_163 = V_31 ;
goto V_685;
}
F_35 ( V_660 -> V_126 [ V_179 ] == 0 ) ;
if ( V_179 == V_294 -> V_683 )
break;
F_506 ( V_66 -> V_82 [ V_179 ] ) ;
V_66 -> V_672 [ V_179 ] = 0 ;
F_8 ( V_660 -> V_126 [ V_179 ] != 1 ) ;
V_179 -- ;
}
}
V_660 -> V_179 = V_179 ;
V_660 -> V_676 = - 1 ;
V_660 -> V_665 = V_667 ;
V_660 -> V_668 = V_668 ;
V_660 -> V_186 = 0 ;
V_660 -> V_679 = V_679 ;
V_660 -> V_664 = F_497 ( V_36 ) ;
while ( 1 ) {
V_31 = F_513 ( V_124 , V_12 , V_66 , V_660 ) ;
if ( V_31 < 0 ) {
V_163 = V_31 ;
break;
}
V_31 = F_514 ( V_124 , V_12 , V_66 , V_660 , V_180 ) ;
if ( V_31 < 0 ) {
V_163 = V_31 ;
break;
}
if ( V_31 > 0 ) {
F_35 ( V_660 -> V_665 != V_667 ) ;
break;
}
if ( V_660 -> V_665 == V_667 ) {
V_179 = V_660 -> V_179 ;
F_520 ( V_66 -> V_82 [ V_179 ] ,
& V_294 -> V_682 ,
V_66 -> V_83 [ V_179 ] ) ;
V_294 -> V_683 = V_179 ;
}
F_35 ( V_660 -> V_179 == 0 ) ;
if ( F_521 ( V_124 ) ||
( ! V_679 && F_522 ( V_36 ) ) ) {
V_31 = F_523 ( V_124 , V_281 ,
& V_12 -> V_293 ,
V_294 ) ;
if ( V_31 ) {
F_167 ( V_124 , V_31 ) ;
V_163 = V_31 ;
goto V_685;
}
F_524 ( V_124 ) ;
if ( ! V_679 && F_522 ( V_36 ) ) {
F_198 ( V_36 ,
L_40 ) ;
V_163 = - V_190 ;
goto V_137;
}
V_124 = F_516 ( V_281 , 0 ) ;
if ( F_222 ( V_124 ) ) {
V_163 = F_223 ( V_124 ) ;
goto V_137;
}
if ( V_458 )
V_124 -> V_458 = V_458 ;
}
}
F_48 ( V_66 ) ;
if ( V_163 )
goto V_685;
V_31 = F_525 ( V_124 , V_281 , & V_12 -> V_293 ) ;
if ( V_31 ) {
F_167 ( V_124 , V_31 ) ;
goto V_685;
}
if ( V_12 -> V_293 . V_24 != V_656 ) {
V_31 = F_526 ( V_281 , & V_12 -> V_293 , V_66 ,
NULL , NULL ) ;
if ( V_31 < 0 ) {
F_167 ( V_124 , V_31 ) ;
V_163 = V_31 ;
goto V_685;
} else if ( V_31 > 0 ) {
F_527 ( V_124 , V_281 ,
V_12 -> V_293 . V_24 ) ;
}
}
if ( F_231 ( V_686 , & V_12 -> V_303 ) ) {
F_528 ( V_124 , V_12 ) ;
} else {
F_495 ( V_12 -> V_142 ) ;
F_495 ( V_12 -> V_687 ) ;
F_529 ( V_12 ) ;
}
V_681 = true ;
V_685:
F_524 ( V_124 ) ;
V_137:
F_10 ( V_660 ) ;
F_56 ( V_66 ) ;
V_81:
if ( ! V_679 && V_681 == false )
F_530 ( V_12 ) ;
if ( V_163 && V_163 != - V_190 )
F_531 ( V_36 , V_163 , NULL ) ;
return V_163 ;
}
int F_532 ( struct V_123 * V_124 ,
struct V_63 * V_12 ,
struct V_67 * V_142 ,
struct V_67 * V_19 )
{
struct V_14 * V_36 = V_12 -> V_36 ;
struct V_65 * V_66 ;
struct V_659 * V_660 ;
int V_179 ;
int V_688 ;
int V_31 = 0 ;
int V_689 ;
F_35 ( V_12 -> V_293 . V_24 != V_656 ) ;
V_66 = F_37 () ;
if ( ! V_66 )
return - V_74 ;
V_660 = F_64 ( sizeof( * V_660 ) , V_97 ) ;
if ( ! V_660 ) {
F_56 ( V_66 ) ;
return - V_74 ;
}
F_533 ( V_19 ) ;
V_688 = F_248 ( V_19 ) ;
F_534 ( V_19 ) ;
V_66 -> V_82 [ V_688 ] = V_19 ;
V_66 -> V_83 [ V_688 ] = F_42 ( V_19 ) ;
F_533 ( V_142 ) ;
V_179 = F_248 ( V_142 ) ;
V_66 -> V_82 [ V_179 ] = V_142 ;
V_66 -> V_83 [ V_179 ] = 0 ;
V_66 -> V_672 [ V_179 ] = V_677 ;
V_660 -> V_126 [ V_688 ] = 1 ;
V_660 -> V_7 [ V_688 ] = V_140 ;
V_660 -> V_179 = V_179 ;
V_660 -> V_676 = - 1 ;
V_660 -> V_665 = V_667 ;
V_660 -> V_668 = 0 ;
V_660 -> V_186 = 1 ;
V_660 -> V_679 = 1 ;
V_660 -> V_664 = F_497 ( V_36 ) ;
while ( 1 ) {
V_689 = F_513 ( V_124 , V_12 , V_66 , V_660 ) ;
if ( V_689 < 0 ) {
V_31 = V_689 ;
break;
}
V_689 = F_514 ( V_124 , V_12 , V_66 , V_660 , V_688 ) ;
if ( V_689 < 0 )
V_31 = V_689 ;
if ( V_689 != 0 )
break;
}
F_10 ( V_660 ) ;
F_56 ( V_66 ) ;
return V_31 ;
}
static T_2 F_535 ( struct V_14 * V_36 , T_2 V_7 )
{
T_2 V_385 ;
T_2 V_690 ;
V_690 = F_307 ( V_36 , V_7 ) ;
if ( V_690 )
return F_309 ( V_690 ) ;
V_385 = V_36 -> V_386 -> V_387 ;
V_690 = V_396 |
V_395 | V_394 |
V_367 | V_368 ;
if ( V_385 == 1 ) {
V_690 |= V_366 ;
V_690 = V_7 & ~ V_690 ;
if ( V_7 & V_396 )
return V_690 ;
if ( V_7 & ( V_367 |
V_368 ) )
return V_690 | V_366 ;
} else {
if ( V_7 & V_690 )
return V_7 ;
V_690 |= V_366 ;
V_690 = V_7 & ~ V_690 ;
if ( V_7 & V_366 )
return V_690 | V_367 ;
}
return V_7 ;
}
static int F_536 ( struct V_1 * V_2 , int V_422 )
{
struct V_110 * V_421 = V_2 -> V_94 ;
T_2 V_37 ;
T_2 V_691 ;
int V_31 = - V_326 ;
if ( ( V_421 -> V_7 &
( V_119 | V_53 ) ) &&
! V_422 )
V_691 = V_316 ;
else
V_691 = 0 ;
F_12 ( & V_421 -> V_50 ) ;
F_12 ( & V_2 -> V_50 ) ;
if ( V_2 -> V_319 ) {
V_2 -> V_319 ++ ;
V_31 = 0 ;
goto V_81;
}
V_37 = V_2 -> V_23 . V_35 - V_2 -> V_10 - V_2 -> V_9 -
V_2 -> V_45 - F_61 ( & V_2 -> V_95 ) ;
if ( F_317 ( V_421 , true ) + V_37 +
V_691 <= V_421 -> V_363 ) {
V_421 -> V_364 += V_37 ;
V_2 -> V_319 ++ ;
F_75 ( & V_2 -> V_692 , & V_421 -> V_356 ) ;
V_31 = 0 ;
}
V_81:
F_14 ( & V_2 -> V_50 ) ;
F_14 ( & V_421 -> V_50 ) ;
return V_31 ;
}
int F_537 ( struct V_14 * V_36 ,
struct V_1 * V_2 )
{
struct V_123 * V_124 ;
T_2 V_693 ;
int V_31 ;
V_167:
V_124 = F_221 ( V_36 -> V_64 ) ;
if ( F_222 ( V_124 ) )
return F_223 ( V_124 ) ;
F_52 ( & V_36 -> V_694 ) ;
if ( F_231 ( V_695 , & V_124 -> V_141 -> V_7 ) ) {
T_2 V_280 = V_124 -> V_280 ;
F_50 ( & V_36 -> V_694 ) ;
F_225 ( V_124 ) ;
V_31 = F_538 ( V_36 , V_280 ) ;
if ( V_31 )
return V_31 ;
goto V_167;
}
V_693 = F_535 ( V_36 , V_2 -> V_7 ) ;
if ( V_693 != V_2 -> V_7 ) {
V_31 = F_320 ( V_124 , V_36 , V_693 ,
V_413 ) ;
if ( V_31 == - V_326 )
V_31 = 0 ;
if ( V_31 < 0 )
goto V_81;
}
V_31 = F_536 ( V_2 , 0 ) ;
if ( ! V_31 )
goto V_81;
V_693 = F_310 ( V_36 , V_2 -> V_94 -> V_7 ) ;
V_31 = F_320 ( V_124 , V_36 , V_693 ,
V_413 ) ;
if ( V_31 < 0 )
goto V_81;
V_31 = F_536 ( V_2 , 0 ) ;
V_81:
if ( V_2 -> V_7 & V_119 ) {
V_693 = F_535 ( V_36 , V_2 -> V_7 ) ;
F_52 ( & V_36 -> V_431 ) ;
F_339 ( V_124 , V_36 , V_693 ) ;
F_50 ( & V_36 -> V_431 ) ;
}
F_50 ( & V_36 -> V_694 ) ;
F_225 ( V_124 ) ;
return V_31 ;
}
int F_539 ( struct V_123 * V_124 ,
struct V_14 * V_36 , T_2 type )
{
T_2 V_693 = F_310 ( V_36 , type ) ;
return F_320 ( V_124 , V_36 , V_693 , V_413 ) ;
}
T_2 F_540 ( struct V_110 * V_421 )
{
struct V_1 * V_16 ;
T_2 V_696 = 0 ;
int V_365 ;
if ( F_188 ( & V_421 -> V_356 ) )
return 0 ;
F_12 ( & V_421 -> V_50 ) ;
F_239 (block_group, &sinfo->ro_bgs, ro_list) {
F_12 ( & V_16 -> V_50 ) ;
if ( ! V_16 -> V_319 ) {
F_14 ( & V_16 -> V_50 ) ;
continue;
}
if ( V_16 -> V_7 & ( V_367 |
V_368 |
V_366 ) )
V_365 = 2 ;
else
V_365 = 1 ;
V_696 += ( V_16 -> V_23 . V_35 -
F_61 ( & V_16 -> V_95 ) ) *
V_365 ;
F_14 ( & V_16 -> V_50 ) ;
}
F_14 ( & V_421 -> V_50 ) ;
return V_696 ;
}
void F_541 ( struct V_1 * V_2 )
{
struct V_110 * V_421 = V_2 -> V_94 ;
T_2 V_37 ;
F_35 ( ! V_2 -> V_319 ) ;
F_12 ( & V_421 -> V_50 ) ;
F_12 ( & V_2 -> V_50 ) ;
if ( ! -- V_2 -> V_319 ) {
V_37 = V_2 -> V_23 . V_35 - V_2 -> V_10 -
V_2 -> V_9 - V_2 -> V_45 -
F_61 ( & V_2 -> V_95 ) ;
V_421 -> V_364 -= V_37 ;
F_280 ( & V_2 -> V_692 ) ;
}
F_14 ( & V_2 -> V_50 ) ;
F_14 ( & V_421 -> V_50 ) ;
}
int F_542 ( struct V_14 * V_36 , T_2 V_29 )
{
struct V_63 * V_12 = V_36 -> V_64 ;
struct V_1 * V_16 ;
struct V_110 * V_94 ;
struct V_697 * V_386 = V_36 -> V_386 ;
struct V_698 * V_699 ;
struct V_123 * V_124 ;
T_2 V_700 ;
T_2 V_701 = 1 ;
T_2 V_702 = 0 ;
T_2 V_380 ;
int V_703 ;
int V_608 ;
int V_122 = 0 ;
int V_31 = 0 ;
V_703 = F_269 ( V_36 , V_432 ) ;
V_16 = F_79 ( V_36 , V_29 ) ;
if ( ! V_16 ) {
if ( V_703 )
F_438 ( V_36 ,
L_41 ,
V_29 ) ;
return - 1 ;
}
V_700 = F_61 ( & V_16 -> V_95 ) ;
if ( ! V_700 )
goto V_81;
V_94 = V_16 -> V_94 ;
F_12 ( & V_94 -> V_50 ) ;
V_122 = V_94 -> V_122 ;
if ( ( V_94 -> V_363 != V_16 -> V_23 . V_35 ) &&
( F_317 ( V_94 , false ) + V_700 <
V_94 -> V_363 ) ) {
F_14 ( & V_94 -> V_50 ) ;
goto V_81;
}
F_14 ( & V_94 -> V_50 ) ;
V_31 = - 1 ;
V_380 = F_307 ( V_36 , V_16 -> V_7 ) ;
if ( V_380 ) {
V_608 = F_451 ( F_309 ( V_380 ) ) ;
} else {
if ( V_122 ) {
if ( V_703 )
F_438 ( V_36 ,
L_42 ,
V_16 -> V_23 . V_24 ) ;
goto V_81;
}
V_608 = F_452 ( V_16 ) ;
}
if ( V_608 == V_591 ) {
V_701 = 4 ;
V_700 >>= 1 ;
} else if ( V_608 == V_592 ) {
V_701 = 2 ;
} else if ( V_608 == V_593 ) {
V_700 <<= 1 ;
} else if ( V_608 == V_594 ) {
V_701 = V_386 -> V_387 ;
V_700 = F_212 ( V_700 , V_701 ) ;
}
V_124 = F_221 ( V_12 ) ;
if ( F_222 ( V_124 ) ) {
V_31 = F_223 ( V_124 ) ;
goto V_81;
}
F_52 ( & V_36 -> V_431 ) ;
F_239 (device, &fs_devices->alloc_list, dev_alloc_list) {
T_2 V_704 ;
if ( V_699 -> V_363 > V_699 -> V_93 + V_700 &&
! V_699 -> V_705 ) {
V_31 = F_543 ( V_124 , V_699 , V_700 ,
& V_704 , NULL ) ;
if ( ! V_31 )
V_702 ++ ;
if ( V_702 >= V_701 )
break;
V_31 = - 1 ;
}
}
if ( V_703 && V_31 == - 1 )
F_438 ( V_36 ,
L_43 ,
V_16 -> V_23 . V_24 ) ;
F_50 ( & V_36 -> V_431 ) ;
F_225 ( V_124 ) ;
V_81:
F_6 ( V_16 ) ;
return V_31 ;
}
static int F_544 ( struct V_14 * V_36 ,
struct V_65 * V_66 ,
struct V_69 * V_23 )
{
struct V_63 * V_12 = V_36 -> V_64 ;
int V_31 = 0 ;
struct V_69 V_152 ;
struct V_67 * V_68 ;
int V_661 ;
V_31 = F_41 ( NULL , V_12 , V_23 , V_66 , 0 , 0 ) ;
if ( V_31 < 0 )
goto V_81;
while ( 1 ) {
V_661 = V_66 -> V_83 [ 0 ] ;
V_68 = V_66 -> V_82 [ 0 ] ;
if ( V_661 >= F_42 ( V_68 ) ) {
V_31 = F_54 ( V_12 , V_66 ) ;
if ( V_31 == 0 )
continue;
if ( V_31 < 0 )
goto V_81;
break;
}
F_44 ( V_68 , & V_152 , V_661 ) ;
if ( V_152 . V_24 >= V_23 -> V_24 &&
V_152 . type == V_191 ) {
struct V_706 * V_707 ;
struct V_708 * V_709 ;
V_707 = & V_12 -> V_36 -> V_710 . V_711 ;
F_545 ( & V_707 -> V_50 ) ;
V_709 = F_546 ( V_707 , V_152 . V_24 ,
V_152 . V_35 ) ;
F_547 ( & V_707 -> V_50 ) ;
if ( ! V_709 ) {
F_178 ( V_36 ,
L_44 ,
V_152 . V_24 , V_152 . V_35 ) ;
V_31 = - V_164 ;
} else {
V_31 = 0 ;
}
F_548 ( V_709 ) ;
goto V_81;
}
V_66 -> V_83 [ 0 ] ++ ;
}
V_81:
return V_31 ;
}
void F_549 ( struct V_14 * V_15 )
{
struct V_1 * V_16 ;
T_2 V_71 = 0 ;
while ( 1 ) {
struct V_308 * V_308 ;
V_16 = F_78 ( V_15 , V_71 ) ;
while ( V_16 ) {
F_12 ( & V_16 -> V_50 ) ;
if ( V_16 -> V_176 )
break;
F_14 ( & V_16 -> V_50 ) ;
V_16 = F_259 ( V_15 , V_16 ) ;
}
if ( ! V_16 ) {
if ( V_71 == 0 )
break;
V_71 = 0 ;
continue;
}
V_308 = V_16 -> V_308 ;
V_16 -> V_176 = 0 ;
V_16 -> V_308 = NULL ;
F_14 ( & V_16 -> V_50 ) ;
ASSERT ( V_16 -> V_342 . V_308 == NULL ) ;
F_273 ( V_308 ) ;
V_71 = V_16 -> V_23 . V_24 + V_16 -> V_23 . V_35 ;
F_6 ( V_16 ) ;
}
}
int F_550 ( struct V_14 * V_15 )
{
struct V_1 * V_16 ;
struct V_110 * V_94 ;
struct V_48 * V_51 ;
struct V_17 * V_32 ;
F_74 ( & V_15 -> V_84 ) ;
while ( ! F_188 ( & V_15 -> V_108 ) ) {
V_51 = F_551 ( V_15 -> V_108 . V_80 ,
struct V_48 , V_98 ) ;
F_200 ( & V_51 -> V_98 ) ;
F_28 ( V_51 ) ;
}
F_76 ( & V_15 -> V_84 ) ;
F_12 ( & V_15 -> V_546 ) ;
while ( ! F_188 ( & V_15 -> V_548 ) ) {
V_16 = F_189 ( & V_15 -> V_548 ,
struct V_1 ,
V_547 ) ;
F_280 ( & V_16 -> V_547 ) ;
F_6 ( V_16 ) ;
}
F_14 ( & V_15 -> V_546 ) ;
F_12 ( & V_15 -> V_20 ) ;
while ( ( V_32 = F_206 ( & V_15 -> V_21 ) ) != NULL ) {
V_16 = F_13 ( V_32 , struct V_1 ,
V_22 ) ;
F_199 ( & V_16 -> V_22 ,
& V_15 -> V_21 ) ;
F_552 ( & V_16 -> V_22 ) ;
F_14 ( & V_15 -> V_20 ) ;
F_74 ( & V_16 -> V_94 -> V_353 ) ;
F_200 ( & V_16 -> V_98 ) ;
F_76 ( & V_16 -> V_94 -> V_353 ) ;
if ( V_16 -> V_3 == V_102 ||
V_16 -> V_3 == V_5 )
F_20 ( V_15 , V_16 ) ;
F_553 ( V_16 ) ;
ASSERT ( V_16 -> V_3 != V_106 ) ;
ASSERT ( F_188 ( & V_16 -> V_340 ) ) ;
ASSERT ( F_188 ( & V_16 -> V_341 ) ) ;
ASSERT ( F_188 ( & V_16 -> V_547 ) ) ;
ASSERT ( F_217 ( & V_16 -> V_8 ) == 1 ) ;
F_6 ( V_16 ) ;
F_12 ( & V_15 -> V_20 ) ;
}
F_14 ( & V_15 -> V_20 ) ;
F_554 () ;
F_395 ( V_15 ) ;
while ( ! F_188 ( & V_15 -> V_94 ) ) {
int V_42 ;
V_94 = F_551 ( V_15 -> V_94 . V_80 ,
struct V_110 ,
V_98 ) ;
if ( F_8 ( V_94 -> V_403 > 0 ||
V_94 -> V_402 > 0 ||
V_94 -> V_404 > 0 ) )
F_343 ( V_15 , V_94 , 0 , 0 ) ;
F_200 ( & V_94 -> V_98 ) ;
for ( V_42 = 0 ; V_42 < V_351 ; V_42 ++ ) {
struct V_712 * V_359 ;
V_359 = V_94 -> V_713 [ V_42 ] ;
V_94 -> V_713 [ V_42 ] = NULL ;
if ( V_359 ) {
F_555 ( V_359 ) ;
F_556 ( V_359 ) ;
}
}
F_555 ( & V_94 -> V_359 ) ;
F_556 ( & V_94 -> V_359 ) ;
}
return 0 ;
}
static void F_557 ( struct V_110 * V_94 ,
struct V_1 * V_2 )
{
int V_608 = F_452 ( V_2 ) ;
bool V_261 = false ;
F_74 ( & V_94 -> V_353 ) ;
if ( F_188 ( & V_94 -> V_352 [ V_608 ] ) )
V_261 = true ;
F_75 ( & V_2 -> V_98 , & V_94 -> V_352 [ V_608 ] ) ;
F_76 ( & V_94 -> V_353 ) ;
if ( V_261 ) {
struct V_714 * V_715 ;
int V_31 ;
V_715 = F_64 ( sizeof( * V_715 ) , V_97 ) ;
if ( ! V_715 )
goto V_716;
V_715 -> V_388 = V_608 ;
F_558 ( & V_715 -> V_359 , & V_717 ) ;
V_31 = F_559 ( & V_715 -> V_359 , & V_94 -> V_359 ,
L_9 , F_453 ( V_608 ) ) ;
if ( V_31 ) {
F_556 ( & V_715 -> V_359 ) ;
goto V_716;
}
V_94 -> V_713 [ V_608 ] = & V_715 -> V_359 ;
}
return;
V_716:
F_438 ( V_2 -> V_36 ,
L_45 ) ;
}
static struct V_1 *
F_560 ( struct V_14 * V_36 ,
T_2 V_34 , T_2 V_59 )
{
struct V_1 * V_2 ;
V_2 = F_64 ( sizeof( * V_2 ) , V_97 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_13 = F_64 ( sizeof( * V_2 -> V_13 ) ,
V_97 ) ;
if ( ! V_2 -> V_13 ) {
F_10 ( V_2 ) ;
return NULL ;
}
V_2 -> V_23 . V_24 = V_34 ;
V_2 -> V_23 . V_35 = V_59 ;
V_2 -> V_23 . type = V_191 ;
V_2 -> V_55 = V_36 -> V_55 ;
V_2 -> V_36 = V_36 ;
V_2 -> V_718 = F_561 ( V_36 ,
& V_36 -> V_710 ,
V_34 ) ;
F_562 ( V_2 ) ;
F_563 ( & V_2 -> V_8 , 1 ) ;
F_297 ( & V_2 -> V_50 ) ;
F_296 ( & V_2 -> V_600 ) ;
F_65 ( & V_2 -> V_98 ) ;
F_65 ( & V_2 -> V_719 ) ;
F_65 ( & V_2 -> V_547 ) ;
F_65 ( & V_2 -> V_692 ) ;
F_65 ( & V_2 -> V_340 ) ;
F_65 ( & V_2 -> V_341 ) ;
F_564 ( V_2 ) ;
F_563 ( & V_2 -> V_720 , 0 ) ;
F_66 ( & V_2 -> V_721 ) ;
F_565 ( & V_2 -> V_11 ) ;
return V_2 ;
}
int F_566 ( struct V_14 * V_15 )
{
struct V_65 * V_66 ;
int V_31 ;
struct V_1 * V_2 ;
struct V_110 * V_94 ;
struct V_69 V_23 ;
struct V_69 V_152 ;
struct V_67 * V_68 ;
int V_722 = 0 ;
T_2 V_723 ;
T_2 V_724 ;
int V_725 ;
V_724 = F_567 ( V_15 -> V_267 ) ;
V_725 = ! ! ( V_724 & V_726 ) ;
V_23 . V_24 = 0 ;
V_23 . V_35 = 0 ;
V_23 . type = V_191 ;
V_66 = F_37 () ;
if ( ! V_66 )
return - V_74 ;
V_66 -> V_77 = V_78 ;
V_723 = F_568 ( V_15 -> V_267 ) ;
if ( F_269 ( V_15 , V_324 ) &&
F_569 ( V_15 -> V_267 ) != V_723 )
V_722 = 1 ;
if ( F_269 ( V_15 , V_727 ) )
V_722 = 1 ;
while ( 1 ) {
V_31 = F_544 ( V_15 , V_66 , & V_23 ) ;
if ( V_31 > 0 )
break;
if ( V_31 != 0 )
goto error;
V_68 = V_66 -> V_82 [ 0 ] ;
F_44 ( V_68 , & V_152 , V_66 -> V_83 [ 0 ] ) ;
V_2 = F_560 ( V_15 , V_152 . V_24 ,
V_152 . V_35 ) ;
if ( ! V_2 ) {
V_31 = - V_74 ;
goto error;
}
if ( V_722 ) {
if ( F_269 ( V_15 , V_324 ) )
V_2 -> V_317 = V_331 ;
}
F_570 ( V_68 , & V_2 -> V_95 ,
F_257 ( V_68 , V_66 -> V_83 [ 0 ] ) ,
sizeof( V_2 -> V_95 ) ) ;
V_2 -> V_7 = F_571 ( & V_2 -> V_95 ) ;
if ( ! V_725 &&
( ( V_2 -> V_7 & V_53 ) &&
( V_2 -> V_7 & V_120 ) ) ) {
F_178 ( V_15 ,
L_46 ,
V_2 -> V_23 . V_24 ) ;
V_31 = - V_550 ;
goto error;
}
V_23 . V_24 = V_152 . V_24 + V_152 . V_35 ;
F_48 ( V_66 ) ;
V_31 = F_22 ( V_15 , V_2 ) ;
if ( V_31 ) {
F_20 ( V_15 , V_2 ) ;
F_6 ( V_2 ) ;
goto error;
}
if ( V_152 . V_35 == F_61 ( & V_2 -> V_95 ) ) {
V_2 -> V_105 = ( T_2 ) - 1 ;
V_2 -> V_3 = V_4 ;
F_20 ( V_15 , V_2 ) ;
} else if ( F_61 ( & V_2 -> V_95 ) == 0 ) {
V_2 -> V_105 = ( T_2 ) - 1 ;
V_2 -> V_3 = V_4 ;
F_32 ( V_2 , V_15 ,
V_152 . V_24 ,
V_152 . V_24 +
V_152 . V_35 ) ;
F_20 ( V_15 , V_2 ) ;
}
V_31 = F_11 ( V_15 , V_2 ) ;
if ( V_31 ) {
F_553 ( V_2 ) ;
F_6 ( V_2 ) ;
goto error;
}
F_572 ( V_15 , V_2 , 0 ) ;
F_301 ( V_15 , V_2 -> V_7 , V_152 . V_35 ,
F_61 ( & V_2 -> V_95 ) ,
V_2 -> V_45 , & V_94 ) ;
V_2 -> V_94 = V_94 ;
F_557 ( V_94 , V_2 ) ;
F_303 ( V_15 , V_2 -> V_7 ) ;
if ( F_573 ( V_15 , V_2 -> V_23 . V_24 ) ) {
F_536 ( V_2 , 1 ) ;
} else if ( F_61 ( & V_2 -> V_95 ) == 0 ) {
F_12 ( & V_15 -> V_546 ) ;
if ( F_188 ( & V_2 -> V_547 ) ) {
F_4 ( V_2 ) ;
F_75 ( & V_2 -> V_547 ,
& V_15 -> V_548 ) ;
}
F_14 ( & V_15 -> V_546 ) ;
}
}
F_82 (space_info, &info->space_info, list) {
if ( ! ( F_310 ( V_15 , V_94 -> V_7 ) &
( V_368 |
V_367 |
V_395 |
V_394 |
V_366 ) ) )
continue;
F_239 (cache,
&space_info->block_groups[BTRFS_RAID_RAID0],
list)
F_536 ( V_2 , 1 ) ;
F_239 (cache,
&space_info->block_groups[BTRFS_RAID_SINGLE],
list)
F_536 ( V_2 , 1 ) ;
}
F_394 ( V_15 ) ;
V_31 = 0 ;
error:
F_56 ( V_66 ) ;
return V_31 ;
}
void F_233 ( struct V_123 * V_124 ,
struct V_14 * V_36 )
{
struct V_1 * V_16 , * V_329 ;
struct V_63 * V_64 = V_36 -> V_64 ;
struct V_728 V_95 ;
struct V_69 V_23 ;
int V_31 = 0 ;
bool V_285 = V_124 -> V_285 ;
V_124 -> V_285 = false ;
F_276 (block_group, tmp, &trans->new_bgs, bg_list) {
if ( V_31 )
goto V_80;
F_12 ( & V_16 -> V_50 ) ;
memcpy ( & V_95 , & V_16 -> V_95 , sizeof( V_95 ) ) ;
memcpy ( & V_23 , & V_16 -> V_23 , sizeof( V_23 ) ) ;
F_14 ( & V_16 -> V_50 ) ;
V_31 = F_574 ( V_124 , V_64 , & V_23 , & V_95 ,
sizeof( V_95 ) ) ;
if ( V_31 )
F_167 ( V_124 , V_31 ) ;
V_31 = F_575 ( V_124 , V_36 , V_23 . V_24 ,
V_23 . V_35 ) ;
if ( V_31 )
F_167 ( V_124 , V_31 ) ;
F_576 ( V_124 , V_36 , V_16 ) ;
V_80:
F_280 ( & V_16 -> V_547 ) ;
}
V_124 -> V_285 = V_285 ;
}
int F_577 ( struct V_123 * V_124 ,
struct V_14 * V_36 , T_2 V_93 ,
T_2 type , T_2 V_729 , T_2 V_730 ,
T_2 V_59 )
{
struct V_1 * V_2 ;
int V_31 ;
F_578 ( V_36 , V_124 ) ;
V_2 = F_560 ( V_36 , V_730 , V_59 ) ;
if ( ! V_2 )
return - V_74 ;
F_419 ( & V_2 -> V_95 , V_93 ) ;
F_579 ( & V_2 -> V_95 , V_729 ) ;
F_580 ( & V_2 -> V_95 , type ) ;
V_2 -> V_7 = type ;
V_2 -> V_105 = ( T_2 ) - 1 ;
V_2 -> V_3 = V_4 ;
V_2 -> V_731 = 1 ;
V_31 = F_22 ( V_36 , V_2 ) ;
if ( V_31 ) {
F_20 ( V_36 , V_2 ) ;
F_6 ( V_2 ) ;
return V_31 ;
}
F_32 ( V_2 , V_36 , V_730 , V_730 + V_59 ) ;
F_20 ( V_36 , V_2 ) ;
#ifdef F_39
if ( F_40 ( V_2 ) ) {
T_2 V_732 = V_59 - V_93 ;
V_93 += V_732 >> 1 ;
F_30 ( V_2 ) ;
}
#endif
V_2 -> V_94 = F_80 ( V_36 , V_2 -> V_7 ) ;
if ( ! V_2 -> V_94 ) {
V_31 = F_294 ( V_36 , V_2 -> V_7 ,
& V_2 -> V_94 ) ;
if ( V_31 ) {
F_553 ( V_2 ) ;
F_6 ( V_2 ) ;
return V_31 ;
}
}
V_31 = F_11 ( V_36 , V_2 ) ;
if ( V_31 ) {
F_553 ( V_2 ) ;
F_6 ( V_2 ) ;
return V_31 ;
}
F_572 ( V_36 , V_2 , 1 ) ;
F_301 ( V_36 , V_2 -> V_7 , V_59 , V_93 ,
V_2 -> V_45 , & V_2 -> V_94 ) ;
F_392 ( V_36 ) ;
F_557 ( V_2 -> V_94 , V_2 ) ;
F_75 ( & V_2 -> V_547 , & V_124 -> V_288 ) ;
F_303 ( V_36 , type ) ;
return 0 ;
}
static void F_581 ( struct V_14 * V_36 , T_2 V_7 )
{
T_2 V_371 = F_304 ( V_7 ) &
V_372 ;
F_305 ( & V_36 -> V_373 ) ;
if ( V_7 & V_120 )
V_36 -> V_374 &= ~ V_371 ;
if ( V_7 & V_53 )
V_36 -> V_375 &= ~ V_371 ;
if ( V_7 & V_119 )
V_36 -> V_376 &= ~ V_371 ;
F_306 ( & V_36 -> V_373 ) ;
}
int F_582 ( struct V_123 * V_124 ,
struct V_14 * V_36 , T_2 V_733 ,
struct V_708 * V_709 )
{
struct V_63 * V_12 = V_36 -> V_64 ;
struct V_65 * V_66 ;
struct V_1 * V_16 ;
struct V_558 * V_566 ;
struct V_63 * V_281 = V_36 -> V_281 ;
struct V_69 V_23 ;
struct V_308 * V_308 ;
struct V_712 * V_359 = NULL ;
int V_31 ;
int V_608 ;
int V_365 ;
struct V_48 * V_51 = NULL ;
bool V_734 ;
V_16 = F_79 ( V_36 , V_733 ) ;
F_35 ( ! V_16 ) ;
F_35 ( ! V_16 -> V_319 ) ;
F_20 ( V_36 , V_16 ) ;
memcpy ( & V_23 , & V_16 -> V_23 , sizeof( V_23 ) ) ;
V_608 = F_452 ( V_16 ) ;
if ( V_16 -> V_7 & ( V_366 |
V_367 |
V_368 ) )
V_365 = 2 ;
else
V_365 = 1 ;
V_566 = & V_36 -> V_564 ;
F_12 ( & V_566 -> V_602 ) ;
F_464 ( V_16 , V_566 ) ;
F_14 ( & V_566 -> V_602 ) ;
V_566 = & V_36 -> V_562 ;
F_12 ( & V_566 -> V_602 ) ;
F_464 ( V_16 , V_566 ) ;
F_14 ( & V_566 -> V_602 ) ;
V_66 = F_37 () ;
if ( ! V_66 ) {
V_31 = - V_74 ;
goto V_81;
}
V_308 = F_262 ( V_36 , V_16 , V_66 ) ;
F_52 ( & V_124 -> V_141 -> V_339 ) ;
F_12 ( & V_124 -> V_141 -> V_338 ) ;
if ( ! F_188 ( & V_16 -> V_341 ) ) {
F_280 ( & V_16 -> V_341 ) ;
F_8 ( ! F_222 ( V_308 ) && V_308 != V_16 -> V_342 . V_308 ) ;
F_14 ( & V_124 -> V_141 -> V_338 ) ;
F_281 ( V_124 , V_16 , V_66 ) ;
F_6 ( V_16 ) ;
F_12 ( & V_124 -> V_141 -> V_338 ) ;
}
if ( ! F_188 ( & V_16 -> V_340 ) ) {
F_280 ( & V_16 -> V_340 ) ;
F_6 ( V_16 ) ;
}
F_14 ( & V_124 -> V_141 -> V_338 ) ;
F_50 ( & V_124 -> V_141 -> V_339 ) ;
if ( ! F_222 ( V_308 ) ) {
V_31 = F_583 ( V_124 , F_265 ( V_308 ) ) ;
if ( V_31 ) {
F_584 ( V_308 ) ;
goto V_81;
}
F_585 ( V_308 ) ;
F_12 ( & V_16 -> V_50 ) ;
if ( V_16 -> V_176 ) {
V_16 -> V_176 = 0 ;
V_16 -> V_308 = NULL ;
F_14 ( & V_16 -> V_50 ) ;
F_273 ( V_308 ) ;
} else {
F_14 ( & V_16 -> V_50 ) ;
}
F_584 ( V_308 ) ;
}
V_23 . V_24 = V_735 ;
V_23 . V_35 = V_16 -> V_23 . V_24 ;
V_23 . type = 0 ;
V_31 = F_41 ( V_124 , V_281 , & V_23 , V_66 , - 1 , 1 ) ;
if ( V_31 < 0 )
goto V_81;
if ( V_31 > 0 )
F_48 ( V_66 ) ;
if ( V_31 == 0 ) {
V_31 = F_129 ( V_124 , V_281 , V_66 ) ;
if ( V_31 )
goto V_81;
F_48 ( V_66 ) ;
}
F_12 ( & V_36 -> V_20 ) ;
F_199 ( & V_16 -> V_22 ,
& V_36 -> V_21 ) ;
F_552 ( & V_16 -> V_22 ) ;
if ( V_36 -> V_28 == V_16 -> V_23 . V_24 )
V_36 -> V_28 = ( T_2 ) - 1 ;
F_14 ( & V_36 -> V_20 ) ;
F_74 ( & V_16 -> V_94 -> V_353 ) ;
F_280 ( & V_16 -> V_98 ) ;
if ( F_188 ( & V_16 -> V_94 -> V_352 [ V_608 ] ) ) {
V_359 = V_16 -> V_94 -> V_713 [ V_608 ] ;
V_16 -> V_94 -> V_713 [ V_608 ] = NULL ;
F_581 ( V_36 , V_16 -> V_7 ) ;
}
F_76 ( & V_16 -> V_94 -> V_353 ) ;
if ( V_359 ) {
F_555 ( V_359 ) ;
F_556 ( V_359 ) ;
}
if ( V_16 -> V_107 )
V_51 = F_26 ( V_16 ) ;
if ( V_16 -> V_3 == V_106 )
F_450 ( V_16 ) ;
if ( V_16 -> V_107 ) {
F_74 ( & V_36 -> V_84 ) ;
if ( ! V_51 ) {
struct V_48 * V_49 ;
F_239 (ctl,
&fs_info->caching_block_groups, list)
if ( V_49 -> V_16 == V_16 ) {
V_51 = V_49 ;
F_27 ( & V_51 -> V_8 ) ;
break;
}
}
if ( V_51 )
F_280 ( & V_51 -> V_98 ) ;
F_76 ( & V_36 -> V_84 ) ;
if ( V_51 ) {
F_28 ( V_51 ) ;
F_28 ( V_51 ) ;
}
}
F_12 ( & V_124 -> V_141 -> V_338 ) ;
if ( ! F_188 ( & V_16 -> V_340 ) ) {
F_8 ( 1 ) ;
}
if ( ! F_188 ( & V_16 -> V_341 ) ) {
F_8 ( 1 ) ;
}
F_14 ( & V_124 -> V_141 -> V_338 ) ;
F_553 ( V_16 ) ;
F_12 ( & V_16 -> V_94 -> V_50 ) ;
F_280 ( & V_16 -> V_692 ) ;
if ( F_269 ( V_36 , V_432 ) ) {
F_8 ( V_16 -> V_94 -> V_363
< V_16 -> V_23 . V_35 ) ;
F_8 ( V_16 -> V_94 -> V_364
< V_16 -> V_23 . V_35 ) ;
F_8 ( V_16 -> V_94 -> V_369
< V_16 -> V_23 . V_35 * V_365 ) ;
}
V_16 -> V_94 -> V_363 -= V_16 -> V_23 . V_35 ;
V_16 -> V_94 -> V_364 -= V_16 -> V_23 . V_35 ;
V_16 -> V_94 -> V_369 -= V_16 -> V_23 . V_35 * V_365 ;
F_14 ( & V_16 -> V_94 -> V_50 ) ;
memcpy ( & V_23 , & V_16 -> V_23 , sizeof( V_23 ) ) ;
F_52 ( & V_36 -> V_431 ) ;
if ( ! F_188 ( & V_709 -> V_98 ) ) {
F_548 ( V_709 ) ;
}
F_12 ( & V_16 -> V_50 ) ;
V_16 -> V_736 = 1 ;
V_734 = ( F_217 ( & V_16 -> V_720 ) == 0 ) ;
if ( ! V_734 ) {
F_586 ( & V_709 -> V_98 , & V_36 -> V_737 ) ;
}
F_14 ( & V_16 -> V_50 ) ;
if ( V_734 ) {
struct V_706 * V_707 ;
V_707 = & V_36 -> V_710 . V_711 ;
F_587 ( & V_707 -> V_50 ) ;
F_588 ( V_707 , V_709 ) ;
F_589 ( & V_707 -> V_50 ) ;
F_548 ( V_709 ) ;
}
F_50 ( & V_36 -> V_431 ) ;
V_31 = F_590 ( V_124 , V_36 , V_16 ) ;
if ( V_31 )
goto V_81;
F_6 ( V_16 ) ;
F_6 ( V_16 ) ;
V_31 = F_41 ( V_124 , V_12 , & V_23 , V_66 , - 1 , 1 ) ;
if ( V_31 > 0 )
V_31 = - V_187 ;
if ( V_31 < 0 )
goto V_81;
V_31 = F_129 ( V_124 , V_12 , V_66 ) ;
V_81:
F_56 ( V_66 ) ;
return V_31 ;
}
struct V_123 *
F_591 ( struct V_14 * V_36 ,
const T_2 V_730 )
{
struct V_706 * V_707 = & V_36 -> V_710 . V_711 ;
struct V_708 * V_709 ;
struct V_738 * V_739 ;
unsigned int V_740 ;
F_545 ( & V_707 -> V_50 ) ;
V_709 = F_546 ( V_707 , V_730 , 1 ) ;
F_547 ( & V_707 -> V_50 ) ;
ASSERT ( V_709 && V_709 -> V_34 == V_730 ) ;
V_739 = V_709 -> V_738 ;
V_740 = 3 + V_739 -> V_214 ;
F_548 ( V_709 ) ;
return F_592 ( V_36 -> V_64 ,
V_740 , 1 ) ;
}
void F_593 ( struct V_14 * V_36 )
{
struct V_1 * V_16 ;
struct V_110 * V_94 ;
struct V_123 * V_124 ;
int V_31 = 0 ;
if ( ! F_231 ( V_741 , & V_36 -> V_7 ) )
return;
F_12 ( & V_36 -> V_546 ) ;
while ( ! F_188 ( & V_36 -> V_548 ) ) {
T_2 V_34 , V_33 ;
int V_720 ;
V_16 = F_189 ( & V_36 -> V_548 ,
struct V_1 ,
V_547 ) ;
F_280 ( & V_16 -> V_547 ) ;
V_94 = V_16 -> V_94 ;
if ( V_31 || F_346 ( V_94 ) ) {
F_6 ( V_16 ) ;
continue;
}
F_14 ( & V_36 -> V_546 ) ;
F_52 ( & V_36 -> V_742 ) ;
F_74 ( & V_94 -> V_353 ) ;
F_12 ( & V_16 -> V_50 ) ;
if ( V_16 -> V_10 ||
F_61 ( & V_16 -> V_95 ) ||
V_16 -> V_319 ||
F_594 ( & V_16 -> V_98 ) ) {
F_14 ( & V_16 -> V_50 ) ;
F_76 ( & V_94 -> V_353 ) ;
goto V_80;
}
F_14 ( & V_16 -> V_50 ) ;
V_31 = F_536 ( V_16 , 0 ) ;
F_76 ( & V_94 -> V_353 ) ;
if ( V_31 < 0 ) {
V_31 = 0 ;
goto V_80;
}
V_124 = F_591 ( V_36 ,
V_16 -> V_23 . V_24 ) ;
if ( F_222 ( V_124 ) ) {
F_541 ( V_16 ) ;
V_31 = F_223 ( V_124 ) ;
goto V_80;
}
V_34 = V_16 -> V_23 . V_24 ;
V_33 = V_34 + V_16 -> V_23 . V_35 - 1 ;
F_52 ( & V_36 -> V_574 ) ;
V_31 = F_21 ( & V_36 -> V_38 [ 0 ] , V_34 , V_33 ,
V_62 ) ;
if ( V_31 ) {
F_50 ( & V_36 -> V_574 ) ;
F_541 ( V_16 ) ;
goto V_743;
}
V_31 = F_21 ( & V_36 -> V_38 [ 1 ] , V_34 , V_33 ,
V_62 ) ;
if ( V_31 ) {
F_50 ( & V_36 -> V_574 ) ;
F_541 ( V_16 ) ;
goto V_743;
}
F_50 ( & V_36 -> V_574 ) ;
F_12 ( & V_94 -> V_50 ) ;
F_12 ( & V_16 -> V_50 ) ;
V_94 -> V_403 -= V_16 -> V_9 ;
V_94 -> V_364 += V_16 -> V_9 ;
F_85 ( & V_94 -> V_121 ,
- V_16 -> V_9 ) ;
V_16 -> V_9 = 0 ;
F_14 ( & V_16 -> V_50 ) ;
F_14 ( & V_94 -> V_50 ) ;
V_720 = F_269 ( V_36 , V_575 ) ;
if ( V_720 )
F_595 ( V_16 ) ;
V_31 = F_596 ( V_124 , V_36 ,
V_16 -> V_23 . V_24 ) ;
if ( V_31 ) {
if ( V_720 )
F_436 ( V_16 ) ;
goto V_743;
}
if ( V_720 ) {
F_12 ( & V_36 -> V_546 ) ;
F_597 ( & V_16 -> V_547 ,
& V_124 -> V_141 -> V_571 ) ;
F_14 ( & V_36 -> V_546 ) ;
F_4 ( V_16 ) ;
}
V_743:
F_225 ( V_124 ) ;
V_80:
F_50 ( & V_36 -> V_742 ) ;
F_6 ( V_16 ) ;
F_12 ( & V_36 -> V_546 ) ;
}
F_14 ( & V_36 -> V_546 ) ;
}
int F_598 ( struct V_14 * V_36 )
{
struct V_110 * V_94 ;
struct V_744 * V_745 ;
T_2 V_746 ;
T_2 V_7 ;
int V_725 = 0 ;
int V_31 ;
V_745 = V_36 -> V_267 ;
if ( ! F_599 ( V_745 ) )
return - V_550 ;
V_746 = F_567 ( V_745 ) ;
if ( V_746 & V_726 )
V_725 = 1 ;
V_7 = V_119 ;
V_31 = F_294 ( V_36 , V_7 , & V_94 ) ;
if ( V_31 )
goto V_81;
if ( V_725 ) {
V_7 = V_53 | V_120 ;
V_31 = F_294 ( V_36 , V_7 , & V_94 ) ;
} else {
V_7 = V_53 ;
V_31 = F_294 ( V_36 , V_7 , & V_94 ) ;
if ( V_31 )
goto V_81;
V_7 = V_120 ;
V_31 = F_294 ( V_36 , V_7 , & V_94 ) ;
}
V_81:
return V_31 ;
}
int F_600 ( struct V_14 * V_36 ,
T_2 V_34 , T_2 V_33 )
{
return F_433 ( V_36 , V_34 , V_33 , false ) ;
}
static int F_601 ( struct V_698 * V_699 ,
T_2 V_747 , T_2 * V_576 )
{
T_2 V_34 = 0 , V_47 = 0 ;
int V_31 ;
* V_576 = 0 ;
if ( ! V_699 -> V_748 )
return 0 ;
if ( V_699 -> V_363 <= V_699 -> V_93 )
return 0 ;
V_31 = 0 ;
while ( 1 ) {
struct V_14 * V_36 = V_699 -> V_36 ;
struct V_290 * V_124 ;
T_2 V_215 ;
V_31 = F_602 ( & V_36 -> V_431 ) ;
if ( V_31 )
return V_31 ;
F_53 ( & V_36 -> V_84 ) ;
F_12 ( & V_36 -> V_749 ) ;
V_124 = V_36 -> V_292 ;
if ( V_124 )
F_27 ( & V_124 -> V_750 ) ;
F_14 ( & V_36 -> V_749 ) ;
V_31 = F_603 ( V_124 , V_699 , V_747 , V_34 ,
& V_34 , & V_47 ) ;
if ( V_124 )
F_604 ( V_124 ) ;
if ( V_31 ) {
F_49 ( & V_36 -> V_84 ) ;
F_50 ( & V_36 -> V_431 ) ;
if ( V_31 == - V_326 )
V_31 = 0 ;
break;
}
V_31 = F_153 ( V_699 -> V_198 , V_34 , V_47 , & V_215 ) ;
F_49 ( & V_36 -> V_84 ) ;
F_50 ( & V_36 -> V_431 ) ;
if ( V_31 )
break;
V_34 += V_47 ;
* V_576 += V_215 ;
if ( F_605 ( V_409 ) ) {
V_31 = - V_751 ;
break;
}
F_51 () ;
}
return V_31 ;
}
int F_606 ( struct V_14 * V_36 , struct V_752 * V_753 )
{
struct V_1 * V_2 = NULL ;
struct V_698 * V_699 ;
struct V_111 * V_754 ;
T_2 V_755 ;
T_2 V_34 ;
T_2 V_33 ;
T_2 V_576 = 0 ;
T_2 V_363 = F_335 ( V_36 -> V_267 ) ;
int V_31 = 0 ;
if ( V_753 -> V_47 == V_363 )
V_2 = F_78 ( V_36 , V_753 -> V_34 ) ;
else
V_2 = F_79 ( V_36 , V_753 -> V_34 ) ;
while ( V_2 ) {
if ( V_2 -> V_23 . V_24 >= ( V_753 -> V_34 + V_753 -> V_47 ) ) {
F_6 ( V_2 ) ;
break;
}
V_34 = F_461 ( V_753 -> V_34 , V_2 -> V_23 . V_24 ) ;
V_33 = F_356 ( V_753 -> V_34 + V_753 -> V_47 ,
V_2 -> V_23 . V_24 + V_2 -> V_23 . V_35 ) ;
if ( V_33 - V_34 >= V_753 -> V_747 ) {
if ( ! F_1 ( V_2 ) ) {
V_31 = F_62 ( V_2 , 0 ) ;
if ( V_31 ) {
F_6 ( V_2 ) ;
break;
}
V_31 = F_450 ( V_2 ) ;
if ( V_31 ) {
F_6 ( V_2 ) ;
break;
}
}
V_31 = F_607 ( V_2 ,
& V_755 ,
V_34 ,
V_33 ,
V_753 -> V_747 ) ;
V_576 += V_755 ;
if ( V_31 ) {
F_6 ( V_2 ) ;
break;
}
}
V_2 = F_259 ( V_36 , V_2 ) ;
}
F_52 ( & V_36 -> V_386 -> V_756 ) ;
V_754 = & V_36 -> V_386 -> V_757 ;
F_239 (device, devices, dev_alloc_list) {
V_31 = F_601 ( V_699 , V_753 -> V_747 ,
& V_755 ) ;
if ( V_31 )
break;
V_576 += V_755 ;
}
F_50 ( & V_36 -> V_386 -> V_756 ) ;
V_753 -> V_47 = V_576 ;
return V_31 ;
}
void F_608 ( struct V_63 * V_12 )
{
F_609 ( & V_12 -> V_758 -> V_759 ) ;
F_2 () ;
if ( F_610 ( & V_12 -> V_758 -> V_89 ) )
F_55 ( & V_12 -> V_758 -> V_89 ) ;
}
int F_611 ( struct V_63 * V_12 )
{
if ( F_217 ( & V_12 -> V_760 ) )
return 0 ;
F_612 ( & V_12 -> V_758 -> V_759 ) ;
F_2 () ;
if ( F_217 ( & V_12 -> V_760 ) ) {
F_608 ( V_12 ) ;
return 0 ;
}
return 1 ;
}
static int F_613 ( T_8 * V_348 )
{
F_71 () ;
return 0 ;
}
void F_614 ( struct V_63 * V_12 )
{
while ( true ) {
int V_31 ;
V_31 = F_611 ( V_12 ) ;
if ( V_31 )
break;
F_292 ( & V_12 -> V_760 ,
F_613 ,
V_101 ) ;
}
}
