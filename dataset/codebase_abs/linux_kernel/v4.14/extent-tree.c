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
int F_109 ( const struct V_67 * V_157 ,
struct V_158 * V_159 ,
enum V_160 V_161 )
{
int type = F_110 ( V_157 , V_159 ) ;
T_2 V_35 = F_111 ( V_157 , V_159 ) ;
if ( type == V_162 ||
type == V_163 ||
type == V_164 ||
type == V_165 ) {
if ( V_161 == V_166 ) {
if ( type == V_162 )
return type ;
if ( type == V_163 ) {
ASSERT ( V_157 -> V_36 ) ;
if ( V_35 &&
F_112 ( V_35 , V_157 -> V_36 -> V_54 ) )
return type ;
}
} else if ( V_161 == V_167 ) {
if ( type == V_165 )
return type ;
if ( type == V_164 ) {
ASSERT ( V_157 -> V_36 ) ;
if ( V_35 &&
F_112 ( V_35 , V_157 -> V_36 -> V_54 ) )
return type ;
}
} else {
ASSERT ( V_161 == V_168 ) ;
return type ;
}
}
F_113 ( (struct V_67 * ) V_157 ) ;
F_114 ( V_157 -> V_36 , L_1 ,
V_157 -> V_34 , type ) ;
F_8 ( 1 ) ;
return V_169 ;
}
static T_2 F_115 ( T_2 V_116 , T_2 V_115 , T_2 V_35 )
{
T_3 V_170 = ~ ( T_3 ) 0 ;
T_3 V_171 = ~ ( T_3 ) 0 ;
T_5 V_172 ;
V_172 = F_116 ( V_116 ) ;
V_170 = F_117 ( V_170 , & V_172 , sizeof( V_172 ) ) ;
V_172 = F_116 ( V_115 ) ;
V_171 = F_117 ( V_171 , & V_172 , sizeof( V_172 ) ) ;
V_172 = F_116 ( V_35 ) ;
V_171 = F_117 ( V_171 , & V_172 , sizeof( V_172 ) ) ;
return ( ( T_2 ) V_170 << 31 ) ^ ( T_2 ) V_171 ;
}
static T_2 F_118 ( struct V_67 * V_68 ,
struct V_173 * V_174 )
{
return F_115 ( F_119 ( V_68 , V_174 ) ,
F_120 ( V_68 , V_174 ) ,
F_121 ( V_68 , V_174 ) ) ;
}
static int F_122 ( struct V_67 * V_68 ,
struct V_173 * V_174 ,
T_2 V_116 , T_2 V_115 , T_2 V_35 )
{
if ( F_119 ( V_68 , V_174 ) != V_116 ||
F_120 ( V_68 , V_174 ) != V_115 ||
F_121 ( V_68 , V_174 ) != V_35 )
return 0 ;
return 1 ;
}
static T_1 int F_123 ( struct V_123 * V_124 ,
struct V_14 * V_36 ,
struct V_65 * V_66 ,
T_2 V_29 , T_2 V_19 ,
T_2 V_116 ,
T_2 V_115 , T_2 V_35 )
{
struct V_63 * V_12 = V_36 -> V_64 ;
struct V_69 V_23 ;
struct V_173 * V_174 ;
struct V_67 * V_68 ;
T_3 V_72 ;
int V_31 ;
int V_175 ;
int V_176 = - V_177 ;
V_23 . V_24 = V_29 ;
if ( V_19 ) {
V_23 . type = V_164 ;
V_23 . V_35 = V_19 ;
} else {
V_23 . type = V_165 ;
V_23 . V_35 = F_115 ( V_116 ,
V_115 , V_35 ) ;
}
V_178:
V_175 = 0 ;
V_31 = F_41 ( V_124 , V_12 , & V_23 , V_66 , - 1 , 1 ) ;
if ( V_31 < 0 ) {
V_176 = V_31 ;
goto V_179;
}
if ( V_19 ) {
if ( ! V_31 )
return 0 ;
#ifdef F_94
V_23 . type = V_154 ;
F_48 ( V_66 ) ;
V_31 = F_41 ( V_124 , V_12 , & V_23 , V_66 , - 1 , 1 ) ;
if ( V_31 < 0 ) {
V_176 = V_31 ;
goto V_179;
}
if ( ! V_31 )
return 0 ;
#endif
goto V_179;
}
V_68 = V_66 -> V_82 [ 0 ] ;
V_72 = F_42 ( V_68 ) ;
while ( 1 ) {
if ( V_66 -> V_83 [ 0 ] >= V_72 ) {
V_31 = F_54 ( V_12 , V_66 ) ;
if ( V_31 < 0 )
V_176 = V_31 ;
if ( V_31 )
goto V_179;
V_68 = V_66 -> V_82 [ 0 ] ;
V_72 = F_42 ( V_68 ) ;
V_175 = 1 ;
}
F_44 ( V_68 , & V_23 , V_66 -> V_83 [ 0 ] ) ;
if ( V_23 . V_24 != V_29 ||
V_23 . type != V_165 )
goto V_179;
V_174 = F_91 ( V_68 , V_66 -> V_83 [ 0 ] ,
struct V_173 ) ;
if ( F_122 ( V_68 , V_174 , V_116 ,
V_115 , V_35 ) ) {
if ( V_175 ) {
F_48 ( V_66 ) ;
goto V_178;
}
V_176 = 0 ;
break;
}
V_66 -> V_83 [ 0 ] ++ ;
}
V_179:
return V_176 ;
}
static T_1 int F_124 ( struct V_123 * V_124 ,
struct V_14 * V_36 ,
struct V_65 * V_66 ,
T_2 V_29 , T_2 V_19 ,
T_2 V_116 , T_2 V_115 ,
T_2 V_35 , int V_180 )
{
struct V_63 * V_12 = V_36 -> V_64 ;
struct V_69 V_23 ;
struct V_67 * V_68 ;
T_3 V_59 ;
T_3 V_133 ;
int V_31 ;
V_23 . V_24 = V_29 ;
if ( V_19 ) {
V_23 . type = V_164 ;
V_23 . V_35 = V_19 ;
V_59 = sizeof( struct V_181 ) ;
} else {
V_23 . type = V_165 ;
V_23 . V_35 = F_115 ( V_116 ,
V_115 , V_35 ) ;
V_59 = sizeof( struct V_173 ) ;
}
V_31 = F_125 ( V_124 , V_12 , V_66 , & V_23 , V_59 ) ;
if ( V_31 && V_31 != - V_27 )
goto V_179;
V_68 = V_66 -> V_82 [ 0 ] ;
if ( V_19 ) {
struct V_181 * V_174 ;
V_174 = F_91 ( V_68 , V_66 -> V_83 [ 0 ] ,
struct V_181 ) ;
if ( V_31 == 0 ) {
F_126 ( V_68 , V_174 , V_180 ) ;
} else {
V_133 = F_127 ( V_68 , V_174 ) ;
V_133 += V_180 ;
F_126 ( V_68 , V_174 , V_133 ) ;
}
} else {
struct V_173 * V_174 ;
while ( V_31 == - V_27 ) {
V_174 = F_91 ( V_68 , V_66 -> V_83 [ 0 ] ,
struct V_173 ) ;
if ( F_122 ( V_68 , V_174 , V_116 ,
V_115 , V_35 ) )
break;
F_48 ( V_66 ) ;
V_23 . V_35 ++ ;
V_31 = F_125 ( V_124 , V_12 , V_66 , & V_23 ,
V_59 ) ;
if ( V_31 && V_31 != - V_27 )
goto V_179;
V_68 = V_66 -> V_82 [ 0 ] ;
}
V_174 = F_91 ( V_68 , V_66 -> V_83 [ 0 ] ,
struct V_173 ) ;
if ( V_31 == 0 ) {
F_128 ( V_68 , V_174 ,
V_116 ) ;
F_129 ( V_68 , V_174 , V_115 ) ;
F_130 ( V_68 , V_174 , V_35 ) ;
F_131 ( V_68 , V_174 , V_180 ) ;
} else {
V_133 = F_132 ( V_68 , V_174 ) ;
V_133 += V_180 ;
F_131 ( V_68 , V_174 , V_133 ) ;
}
}
F_108 ( V_68 ) ;
V_31 = 0 ;
V_179:
F_48 ( V_66 ) ;
return V_31 ;
}
static T_1 int F_133 ( struct V_123 * V_124 ,
struct V_14 * V_36 ,
struct V_65 * V_66 ,
int V_182 , int * V_183 )
{
struct V_69 V_23 ;
struct V_173 * V_184 = NULL ;
struct V_181 * V_185 = NULL ;
struct V_67 * V_68 ;
T_3 V_133 = 0 ;
int V_31 = 0 ;
V_68 = V_66 -> V_82 [ 0 ] ;
F_44 ( V_68 , & V_23 , V_66 -> V_83 [ 0 ] ) ;
if ( V_23 . type == V_165 ) {
V_184 = F_91 ( V_68 , V_66 -> V_83 [ 0 ] ,
struct V_173 ) ;
V_133 = F_132 ( V_68 , V_184 ) ;
} else if ( V_23 . type == V_164 ) {
V_185 = F_91 ( V_68 , V_66 -> V_83 [ 0 ] ,
struct V_181 ) ;
V_133 = F_127 ( V_68 , V_185 ) ;
#ifdef F_94
} else if ( V_23 . type == V_154 ) {
struct V_148 * V_149 ;
V_149 = F_91 ( V_68 , V_66 -> V_83 [ 0 ] ,
struct V_148 ) ;
V_133 = F_134 ( V_68 , V_149 ) ;
#endif
} else {
F_96 () ;
}
F_35 ( V_133 < V_182 ) ;
V_133 -= V_182 ;
if ( V_133 == 0 ) {
V_31 = F_135 ( V_124 , V_36 -> V_64 , V_66 ) ;
* V_183 = 1 ;
} else {
if ( V_23 . type == V_165 )
F_131 ( V_68 , V_184 , V_133 ) ;
else if ( V_23 . type == V_164 )
F_126 ( V_68 , V_185 , V_133 ) ;
#ifdef F_94
else {
struct V_148 * V_149 ;
V_149 = F_91 ( V_68 , V_66 -> V_83 [ 0 ] ,
struct V_148 ) ;
F_136 ( V_68 , V_149 , V_133 ) ;
}
#endif
F_108 ( V_68 ) ;
}
return V_31 ;
}
static T_1 T_3 F_137 ( struct V_65 * V_66 ,
struct V_158 * V_159 )
{
struct V_69 V_23 ;
struct V_67 * V_68 ;
struct V_173 * V_184 ;
struct V_181 * V_185 ;
T_3 V_133 = 0 ;
int type ;
V_68 = V_66 -> V_82 [ 0 ] ;
F_44 ( V_68 , & V_23 , V_66 -> V_83 [ 0 ] ) ;
if ( V_159 ) {
type = F_109 ( V_68 , V_159 , V_167 ) ;
ASSERT ( type != V_169 ) ;
if ( type == V_165 ) {
V_184 = (struct V_173 * ) ( & V_159 -> V_35 ) ;
V_133 = F_132 ( V_68 , V_184 ) ;
} else {
V_185 = (struct V_181 * ) ( V_159 + 1 ) ;
V_133 = F_127 ( V_68 , V_185 ) ;
}
} else if ( V_23 . type == V_165 ) {
V_184 = F_91 ( V_68 , V_66 -> V_83 [ 0 ] ,
struct V_173 ) ;
V_133 = F_132 ( V_68 , V_184 ) ;
} else if ( V_23 . type == V_164 ) {
V_185 = F_91 ( V_68 , V_66 -> V_83 [ 0 ] ,
struct V_181 ) ;
V_133 = F_127 ( V_68 , V_185 ) ;
#ifdef F_94
} else if ( V_23 . type == V_154 ) {
struct V_148 * V_149 ;
V_149 = F_91 ( V_68 , V_66 -> V_83 [ 0 ] ,
struct V_148 ) ;
V_133 = F_134 ( V_68 , V_149 ) ;
#endif
} else {
F_8 ( 1 ) ;
}
return V_133 ;
}
static T_1 int F_138 ( struct V_123 * V_124 ,
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
V_23 . type = V_163 ;
V_23 . V_35 = V_19 ;
} else {
V_23 . type = V_162 ;
V_23 . V_35 = V_116 ;
}
V_31 = F_41 ( V_124 , V_12 , & V_23 , V_66 , - 1 , 1 ) ;
if ( V_31 > 0 )
V_31 = - V_177 ;
#ifdef F_94
if ( V_31 == - V_177 && V_19 ) {
F_48 ( V_66 ) ;
V_23 . type = V_154 ;
V_31 = F_41 ( V_124 , V_12 , & V_23 , V_66 , - 1 , 1 ) ;
if ( V_31 > 0 )
V_31 = - V_177 ;
}
#endif
return V_31 ;
}
static T_1 int F_139 ( struct V_123 * V_124 ,
struct V_14 * V_36 ,
struct V_65 * V_66 ,
T_2 V_29 , T_2 V_19 ,
T_2 V_116 )
{
struct V_69 V_23 ;
int V_31 ;
V_23 . V_24 = V_29 ;
if ( V_19 ) {
V_23 . type = V_163 ;
V_23 . V_35 = V_19 ;
} else {
V_23 . type = V_162 ;
V_23 . V_35 = V_116 ;
}
V_31 = F_125 ( V_124 , V_36 -> V_64 ,
V_66 , & V_23 , 0 ) ;
F_48 ( V_66 ) ;
return V_31 ;
}
static inline int F_140 ( T_2 V_19 , T_2 V_115 )
{
int type ;
if ( V_115 < V_117 ) {
if ( V_19 > 0 )
type = V_163 ;
else
type = V_162 ;
} else {
if ( V_19 > 0 )
type = V_164 ;
else
type = V_165 ;
}
return type ;
}
static int F_45 ( struct V_65 * V_66 , int V_186 ,
struct V_69 * V_23 )
{
for (; V_186 < V_187 ; V_186 ++ ) {
if ( ! V_66 -> V_82 [ V_186 ] )
break;
if ( V_66 -> V_83 [ V_186 ] + 1 >=
F_42 ( V_66 -> V_82 [ V_186 ] ) )
continue;
if ( V_186 == 0 )
F_44 ( V_66 -> V_82 [ V_186 ] , V_23 ,
V_66 -> V_83 [ V_186 ] + 1 ) ;
else
F_141 ( V_66 -> V_82 [ V_186 ] , V_23 ,
V_66 -> V_83 [ V_186 ] + 1 ) ;
return 0 ;
}
return 1 ;
}
static T_6
int F_142 ( struct V_123 * V_124 ,
struct V_14 * V_36 ,
struct V_65 * V_66 ,
struct V_158 * * V_188 ,
T_2 V_29 , T_2 V_37 ,
T_2 V_19 , T_2 V_116 ,
T_2 V_115 , T_2 V_35 , int V_189 )
{
struct V_63 * V_12 = V_36 -> V_64 ;
struct V_69 V_23 ;
struct V_67 * V_68 ;
struct V_130 * V_131 ;
struct V_158 * V_159 ;
T_2 V_7 ;
T_2 V_132 ;
unsigned long V_190 ;
unsigned long V_33 ;
int V_147 ;
int type ;
int V_191 ;
int V_31 ;
int V_176 = 0 ;
bool V_192 = F_89 ( V_36 , V_135 ) ;
int V_193 ;
V_23 . V_24 = V_29 ;
V_23 . type = V_79 ;
V_23 . V_35 = V_37 ;
V_191 = F_140 ( V_19 , V_115 ) ;
if ( V_189 ) {
V_147 = F_143 ( V_191 ) ;
V_66 -> V_194 = 1 ;
} else
V_147 = - 1 ;
if ( V_192 && V_115 < V_117 ) {
V_23 . type = V_87 ;
V_23 . V_35 = V_115 ;
}
V_178:
V_31 = F_41 ( V_124 , V_12 , & V_23 , V_66 , V_147 , 1 ) ;
if ( V_31 < 0 ) {
V_176 = V_31 ;
goto V_81;
}
if ( V_31 > 0 && V_192 ) {
V_192 = false ;
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
goto V_178;
}
}
if ( V_31 && ! V_189 ) {
V_176 = - V_177 ;
goto V_81;
} else if ( F_8 ( V_31 ) ) {
V_176 = - V_195 ;
goto V_81;
}
V_68 = V_66 -> V_82 [ 0 ] ;
V_132 = F_90 ( V_68 , V_66 -> V_83 [ 0 ] ) ;
#ifdef F_94
if ( V_132 < sizeof( * V_131 ) ) {
if ( ! V_189 ) {
V_176 = - V_177 ;
goto V_81;
}
V_31 = F_100 ( V_124 , V_36 , V_66 , V_115 ,
V_147 ) ;
if ( V_31 < 0 ) {
V_176 = V_31 ;
goto V_81;
}
V_68 = V_66 -> V_82 [ 0 ] ;
V_132 = F_90 ( V_68 , V_66 -> V_83 [ 0 ] ) ;
}
#endif
F_35 ( V_132 < sizeof( * V_131 ) ) ;
V_131 = F_91 ( V_68 , V_66 -> V_83 [ 0 ] , struct V_130 ) ;
V_7 = F_93 ( V_68 , V_131 ) ;
V_190 = ( unsigned long ) ( V_131 + 1 ) ;
V_33 = ( unsigned long ) V_131 + V_132 ;
if ( V_7 & V_155 && ! V_192 ) {
V_190 += sizeof( struct V_150 ) ;
F_35 ( V_190 > V_33 ) ;
}
if ( V_115 >= V_117 )
V_193 = V_167 ;
else
V_193 = V_166 ;
V_176 = - V_177 ;
while ( 1 ) {
if ( V_190 >= V_33 ) {
F_8 ( V_190 > V_33 ) ;
break;
}
V_159 = (struct V_158 * ) V_190 ;
type = F_109 ( V_68 , V_159 , V_193 ) ;
if ( type == V_169 ) {
V_176 = - V_196 ;
goto V_81;
}
if ( V_191 < type )
break;
if ( V_191 > type ) {
V_190 += F_143 ( type ) ;
continue;
}
if ( type == V_165 ) {
struct V_173 * V_197 ;
V_197 = (struct V_173 * ) ( & V_159 -> V_35 ) ;
if ( F_122 ( V_68 , V_197 , V_116 ,
V_115 , V_35 ) ) {
V_176 = 0 ;
break;
}
if ( F_118 ( V_68 , V_197 ) <
F_115 ( V_116 , V_115 , V_35 ) )
break;
} else {
T_2 V_198 ;
V_198 = F_111 ( V_68 , V_159 ) ;
if ( V_19 > 0 ) {
if ( V_19 == V_198 ) {
V_176 = 0 ;
break;
}
if ( V_198 < V_19 )
break;
} else {
if ( V_116 == V_198 ) {
V_176 = 0 ;
break;
}
if ( V_198 < V_116 )
break;
}
}
V_190 += F_143 ( type ) ;
}
if ( V_176 == - V_177 && V_189 ) {
if ( V_132 + V_147 >=
F_144 ( V_12 ) ) {
V_176 = - V_199 ;
goto V_81;
}
if ( F_45 ( V_66 , 0 , & V_23 ) == 0 &&
V_23 . V_24 == V_29 &&
V_23 . type < V_200 ) {
V_176 = - V_199 ;
goto V_81;
}
}
* V_188 = (struct V_158 * ) V_190 ;
V_81:
if ( V_189 ) {
V_66 -> V_194 = 0 ;
F_145 ( V_66 , 1 ) ;
}
return V_176 ;
}
static T_6
void F_146 ( struct V_14 * V_36 ,
struct V_65 * V_66 ,
struct V_158 * V_159 ,
T_2 V_19 , T_2 V_116 ,
T_2 V_115 , T_2 V_35 , int V_180 ,
struct V_201 * V_143 )
{
struct V_67 * V_68 ;
struct V_130 * V_131 ;
unsigned long V_190 ;
unsigned long V_33 ;
unsigned long V_202 ;
T_2 V_126 ;
int V_59 ;
int type ;
V_68 = V_66 -> V_82 [ 0 ] ;
V_131 = F_91 ( V_68 , V_66 -> V_83 [ 0 ] , struct V_130 ) ;
V_202 = ( unsigned long ) V_159 - ( unsigned long ) V_131 ;
type = F_140 ( V_19 , V_115 ) ;
V_59 = F_143 ( type ) ;
F_102 ( V_36 , V_66 , V_59 ) ;
V_131 = F_91 ( V_68 , V_66 -> V_83 [ 0 ] , struct V_130 ) ;
V_126 = F_92 ( V_68 , V_131 ) ;
V_126 += V_180 ;
F_103 ( V_68 , V_131 , V_126 ) ;
if ( V_143 )
F_147 ( V_143 , V_68 , V_131 ) ;
V_190 = ( unsigned long ) V_131 + V_202 ;
V_33 = ( unsigned long ) V_131 + F_90 ( V_68 , V_66 -> V_83 [ 0 ] ) ;
if ( V_190 < V_33 - V_59 )
F_148 ( V_68 , V_190 + V_59 , V_190 ,
V_33 - V_59 - V_190 ) ;
V_159 = (struct V_158 * ) V_190 ;
F_149 ( V_68 , V_159 , type ) ;
if ( type == V_165 ) {
struct V_173 * V_197 ;
V_197 = (struct V_173 * ) ( & V_159 -> V_35 ) ;
F_128 ( V_68 , V_197 , V_116 ) ;
F_129 ( V_68 , V_197 , V_115 ) ;
F_130 ( V_68 , V_197 , V_35 ) ;
F_131 ( V_68 , V_197 , V_180 ) ;
} else if ( type == V_164 ) {
struct V_181 * V_203 ;
V_203 = (struct V_181 * ) ( V_159 + 1 ) ;
F_126 ( V_68 , V_203 , V_180 ) ;
F_150 ( V_68 , V_159 , V_19 ) ;
} else if ( type == V_163 ) {
F_150 ( V_68 , V_159 , V_19 ) ;
} else {
F_150 ( V_68 , V_159 , V_116 ) ;
}
F_108 ( V_68 ) ;
}
static int F_151 ( struct V_123 * V_124 ,
struct V_14 * V_36 ,
struct V_65 * V_66 ,
struct V_158 * * V_188 ,
T_2 V_29 , T_2 V_37 , T_2 V_19 ,
T_2 V_116 , T_2 V_115 , T_2 V_35 )
{
int V_31 ;
V_31 = F_142 ( V_124 , V_36 , V_66 , V_188 ,
V_29 , V_37 , V_19 ,
V_116 , V_115 , V_35 , 0 ) ;
if ( V_31 != - V_177 )
return V_31 ;
F_48 ( V_66 ) ;
* V_188 = NULL ;
if ( V_115 < V_117 ) {
V_31 = F_138 ( V_124 , V_36 , V_66 , V_29 ,
V_19 , V_116 ) ;
} else {
V_31 = F_123 ( V_124 , V_36 , V_66 , V_29 ,
V_19 , V_116 , V_115 ,
V_35 ) ;
}
return V_31 ;
}
static T_6
void F_152 ( struct V_14 * V_36 ,
struct V_65 * V_66 ,
struct V_158 * V_159 ,
int V_204 ,
struct V_201 * V_143 ,
int * V_183 )
{
struct V_67 * V_68 ;
struct V_130 * V_131 ;
struct V_173 * V_197 = NULL ;
struct V_181 * V_203 = NULL ;
unsigned long V_190 ;
unsigned long V_33 ;
T_3 V_132 ;
int V_59 ;
int type ;
T_2 V_126 ;
V_68 = V_66 -> V_82 [ 0 ] ;
V_131 = F_91 ( V_68 , V_66 -> V_83 [ 0 ] , struct V_130 ) ;
V_126 = F_92 ( V_68 , V_131 ) ;
F_8 ( V_204 < 0 && V_126 + V_204 <= 0 ) ;
V_126 += V_204 ;
F_103 ( V_68 , V_131 , V_126 ) ;
if ( V_143 )
F_147 ( V_143 , V_68 , V_131 ) ;
type = F_109 ( V_68 , V_159 , V_168 ) ;
ASSERT ( type != V_169 ) ;
if ( type == V_165 ) {
V_197 = (struct V_173 * ) ( & V_159 -> V_35 ) ;
V_126 = F_132 ( V_68 , V_197 ) ;
} else if ( type == V_164 ) {
V_203 = (struct V_181 * ) ( V_159 + 1 ) ;
V_126 = F_127 ( V_68 , V_203 ) ;
} else {
V_126 = 1 ;
F_35 ( V_204 != - 1 ) ;
}
F_35 ( V_204 < 0 && V_126 < - V_204 ) ;
V_126 += V_204 ;
if ( V_126 > 0 ) {
if ( type == V_165 )
F_131 ( V_68 , V_197 , V_126 ) ;
else
F_126 ( V_68 , V_203 , V_126 ) ;
} else {
* V_183 = 1 ;
V_59 = F_143 ( type ) ;
V_132 = F_90 ( V_68 , V_66 -> V_83 [ 0 ] ) ;
V_190 = ( unsigned long ) V_159 ;
V_33 = ( unsigned long ) V_131 + V_132 ;
if ( V_190 + V_59 < V_33 )
F_148 ( V_68 , V_190 , V_190 + V_59 ,
V_33 - V_190 - V_59 ) ;
V_132 -= V_59 ;
F_153 ( V_36 , V_66 , V_132 , 1 ) ;
}
F_108 ( V_68 ) ;
}
static T_6
int F_154 ( struct V_123 * V_124 ,
struct V_14 * V_36 ,
struct V_65 * V_66 ,
T_2 V_29 , T_2 V_37 , T_2 V_19 ,
T_2 V_116 , T_2 V_115 ,
T_2 V_35 , int V_180 ,
struct V_201 * V_143 )
{
struct V_158 * V_159 ;
int V_31 ;
V_31 = F_142 ( V_124 , V_36 , V_66 , & V_159 ,
V_29 , V_37 , V_19 ,
V_116 , V_115 , V_35 , 1 ) ;
if ( V_31 == 0 ) {
F_35 ( V_115 < V_117 ) ;
F_152 ( V_36 , V_66 , V_159 ,
V_180 , V_143 , NULL ) ;
} else if ( V_31 == - V_177 ) {
F_146 ( V_36 , V_66 , V_159 , V_19 ,
V_116 , V_115 , V_35 ,
V_180 , V_143 ) ;
V_31 = 0 ;
}
return V_31 ;
}
static int F_155 ( struct V_123 * V_124 ,
struct V_14 * V_36 ,
struct V_65 * V_66 ,
T_2 V_29 , T_2 V_19 , T_2 V_116 ,
T_2 V_115 , T_2 V_35 , int V_180 )
{
int V_31 ;
if ( V_115 < V_117 ) {
F_35 ( V_180 != 1 ) ;
V_31 = F_139 ( V_124 , V_36 , V_66 , V_29 ,
V_19 , V_116 ) ;
} else {
V_31 = F_124 ( V_124 , V_36 , V_66 , V_29 ,
V_19 , V_116 ,
V_115 , V_35 , V_180 ) ;
}
return V_31 ;
}
static int F_156 ( struct V_123 * V_124 ,
struct V_14 * V_36 ,
struct V_65 * V_66 ,
struct V_158 * V_159 ,
int V_182 , int V_161 , int * V_183 )
{
int V_31 = 0 ;
F_35 ( ! V_161 && V_182 != 1 ) ;
if ( V_159 ) {
F_152 ( V_36 , V_66 , V_159 ,
- V_182 , NULL , V_183 ) ;
} else if ( V_161 ) {
V_31 = F_133 ( V_124 , V_36 , V_66 , V_182 ,
V_183 ) ;
} else {
* V_183 = 1 ;
V_31 = F_135 ( V_124 , V_36 -> V_64 , V_66 ) ;
}
return V_31 ;
}
static int F_157 ( struct V_205 * V_206 , T_2 V_34 , T_2 V_47 ,
T_2 * V_207 )
{
int V_208 , V_31 = 0 ;
T_2 V_209 , V_33 ;
T_2 V_210 = F_158 ( V_34 , 1 << 9 ) ;
if ( F_8 ( V_34 != V_210 ) ) {
V_47 -= V_210 - V_34 ;
V_47 = F_159 ( V_47 , 1 << 9 ) ;
V_34 = V_210 ;
}
* V_207 = 0 ;
if ( ! V_47 )
return 0 ;
V_33 = V_34 + V_47 ;
V_209 = V_47 ;
for ( V_208 = 0 ; V_208 < V_46 ; V_208 ++ ) {
T_2 V_211 = F_23 ( V_208 ) ;
T_2 V_212 = V_211 + V_213 ;
T_2 V_59 = V_211 - V_34 ;
if ( ! F_160 ( V_211 , V_34 , V_209 ) &&
! F_160 ( V_212 , V_34 , V_209 ) &&
! F_160 ( V_34 , V_211 , V_213 ) )
continue;
if ( V_211 <= V_34 ) {
V_34 += V_212 - V_34 ;
if ( V_34 > V_33 ) {
V_209 = 0 ;
break;
}
V_209 = V_33 - V_34 ;
continue;
}
if ( V_59 ) {
V_31 = F_161 ( V_206 , V_34 >> 9 , V_59 >> 9 ,
V_97 , 0 ) ;
if ( ! V_31 )
* V_207 += V_59 ;
else if ( V_31 != - V_214 )
return V_31 ;
}
V_34 = V_212 ;
if ( V_34 > V_33 ) {
V_209 = 0 ;
break;
}
V_209 = V_33 - V_34 ;
}
if ( V_209 ) {
V_31 = F_161 ( V_206 , V_34 >> 9 , V_209 >> 9 ,
V_97 , 0 ) ;
if ( ! V_31 )
* V_207 += V_209 ;
}
return V_31 ;
}
int F_162 ( struct V_14 * V_36 , T_2 V_29 ,
T_2 V_37 , T_2 * V_215 )
{
int V_31 ;
T_2 V_207 = 0 ;
struct V_216 * V_217 = NULL ;
F_163 ( V_36 ) ;
V_31 = F_164 ( V_36 , V_218 , V_29 , & V_37 ,
& V_217 , 0 ) ;
if ( ! V_31 ) {
struct V_219 * V_220 = V_217 -> V_221 ;
int V_42 ;
for ( V_42 = 0 ; V_42 < V_217 -> V_222 ; V_42 ++ , V_220 ++ ) {
T_2 V_223 ;
if ( ! V_220 -> V_224 -> V_225 )
continue;
V_31 = F_157 ( V_220 -> V_224 -> V_206 ,
V_220 -> V_226 ,
V_220 -> V_227 ,
& V_223 ) ;
if ( ! V_31 )
V_207 += V_223 ;
else if ( V_31 != - V_214 )
break;
V_31 = 0 ;
}
F_165 ( V_217 ) ;
}
F_166 ( V_36 ) ;
if ( V_215 )
* V_215 = V_207 ;
if ( V_31 == - V_214 )
V_31 = 0 ;
return V_31 ;
}
int F_167 ( struct V_123 * V_124 ,
struct V_14 * V_36 ,
T_2 V_29 , T_2 V_37 , T_2 V_19 ,
T_2 V_116 , T_2 V_115 , T_2 V_35 )
{
int V_228 , V_229 ;
int V_31 ;
F_35 ( V_115 < V_117 &&
V_116 == V_230 ) ;
if ( V_115 < V_117 ) {
V_31 = F_168 ( V_36 , V_124 , V_29 ,
V_37 , V_19 ,
V_116 , ( int ) V_115 ,
V_231 , NULL ,
& V_228 , & V_229 ) ;
} else {
V_31 = F_169 ( V_36 , V_124 , V_29 ,
V_37 , V_19 ,
V_116 , V_115 , V_35 ,
0 , V_231 ,
& V_228 , & V_229 ) ;
}
if ( V_31 == 0 && V_228 < 0 && V_229 >= 0 )
F_84 ( V_36 , - V_37 , V_115 , V_116 ) ;
return V_31 ;
}
static int F_170 ( struct V_123 * V_124 ,
struct V_14 * V_36 ,
struct V_232 * V_142 ,
T_2 V_19 , T_2 V_116 ,
T_2 V_115 , T_2 V_35 , int V_180 ,
struct V_201 * V_143 )
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
V_66 -> V_233 = 1 ;
V_31 = F_154 ( V_124 , V_36 , V_66 , V_29 ,
V_37 , V_19 , V_116 ,
V_115 , V_35 ,
V_180 , V_143 ) ;
if ( ( V_31 < 0 && V_31 != - V_199 ) || ! V_31 )
goto V_81;
V_68 = V_66 -> V_82 [ 0 ] ;
F_44 ( V_68 , & V_23 , V_66 -> V_83 [ 0 ] ) ;
V_95 = F_91 ( V_68 , V_66 -> V_83 [ 0 ] , struct V_130 ) ;
V_126 = F_92 ( V_68 , V_95 ) ;
F_103 ( V_68 , V_95 , V_126 + V_180 ) ;
if ( V_143 )
F_147 ( V_143 , V_68 , V_95 ) ;
F_108 ( V_68 ) ;
F_48 ( V_66 ) ;
V_66 -> V_77 = V_78 ;
V_66 -> V_233 = 1 ;
V_31 = F_155 ( V_124 , V_36 , V_66 , V_29 , V_19 ,
V_116 , V_115 , V_35 , V_180 ) ;
if ( V_31 )
F_171 ( V_124 , V_31 ) ;
V_81:
F_56 ( V_66 ) ;
return V_31 ;
}
static int F_172 ( struct V_123 * V_124 ,
struct V_14 * V_36 ,
struct V_232 * V_142 ,
struct V_201 * V_143 ,
int V_234 )
{
int V_31 = 0 ;
struct V_235 * V_174 ;
struct V_69 V_236 ;
T_2 V_19 = 0 ;
T_2 V_237 = 0 ;
T_2 V_7 = 0 ;
V_236 . V_24 = V_142 -> V_29 ;
V_236 . V_35 = V_142 -> V_37 ;
V_236 . type = V_79 ;
V_174 = F_173 ( V_142 ) ;
F_174 ( V_36 , V_142 , V_174 , V_142 -> V_238 ) ;
if ( V_142 -> type == V_164 )
V_19 = V_174 -> V_19 ;
V_237 = V_174 -> V_12 ;
if ( V_142 -> V_238 == V_231 && V_234 ) {
if ( V_143 )
V_7 |= V_143 -> V_145 ;
V_31 = F_175 ( V_124 , V_36 ,
V_19 , V_237 , V_7 ,
V_174 -> V_24 , V_174 -> V_35 ,
& V_236 , V_142 -> V_146 ) ;
} else if ( V_142 -> V_238 == V_231 ) {
V_31 = F_170 ( V_124 , V_36 , V_142 , V_19 ,
V_237 , V_174 -> V_24 ,
V_174 -> V_35 , V_142 -> V_146 ,
V_143 ) ;
} else if ( V_142 -> V_238 == V_239 ) {
V_31 = F_176 ( V_124 , V_36 , V_142 , V_19 ,
V_237 , V_174 -> V_24 ,
V_174 -> V_35 , V_142 -> V_146 ,
V_143 ) ;
} else {
F_96 () ;
}
return V_31 ;
}
static void F_147 ( struct V_201 * V_143 ,
struct V_67 * V_68 ,
struct V_130 * V_131 )
{
T_2 V_7 = F_93 ( V_68 , V_131 ) ;
if ( V_143 -> V_144 ) {
V_7 |= V_143 -> V_145 ;
F_105 ( V_68 , V_131 , V_7 ) ;
}
if ( V_143 -> V_240 ) {
struct V_150 * V_151 ;
F_35 ( ! ( V_7 & V_155 ) ) ;
V_151 = (struct V_150 * ) ( V_131 + 1 ) ;
F_177 ( V_68 , V_151 , & V_143 -> V_23 ) ;
}
}
static int F_178 ( struct V_123 * V_124 ,
struct V_14 * V_36 ,
struct V_232 * V_142 ,
struct V_201 * V_143 )
{
struct V_69 V_23 ;
struct V_65 * V_66 ;
struct V_130 * V_131 ;
struct V_67 * V_68 ;
T_3 V_132 ;
int V_31 ;
int V_176 = 0 ;
int V_125 = ! V_143 -> V_161 ;
if ( V_124 -> V_241 )
return 0 ;
if ( V_125 && ! F_89 ( V_36 , V_135 ) )
V_125 = 0 ;
V_66 = F_37 () ;
if ( ! V_66 )
return - V_74 ;
V_23 . V_24 = V_142 -> V_29 ;
if ( V_125 ) {
V_23 . type = V_87 ;
V_23 . V_35 = V_143 -> V_186 ;
} else {
V_23 . type = V_79 ;
V_23 . V_35 = V_142 -> V_37 ;
}
V_178:
V_66 -> V_77 = V_78 ;
V_66 -> V_233 = 1 ;
V_31 = F_41 ( V_124 , V_36 -> V_64 , & V_23 , V_66 , 0 , 1 ) ;
if ( V_31 < 0 ) {
V_176 = V_31 ;
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
goto V_178;
}
} else {
V_176 = - V_195 ;
goto V_81;
}
}
V_68 = V_66 -> V_82 [ 0 ] ;
V_132 = F_90 ( V_68 , V_66 -> V_83 [ 0 ] ) ;
#ifdef F_94
if ( V_132 < sizeof( * V_131 ) ) {
V_31 = F_100 ( V_124 , V_36 , V_66 , ( T_2 ) - 1 , 0 ) ;
if ( V_31 < 0 ) {
V_176 = V_31 ;
goto V_81;
}
V_68 = V_66 -> V_82 [ 0 ] ;
V_132 = F_90 ( V_68 , V_66 -> V_83 [ 0 ] ) ;
}
#endif
F_35 ( V_132 < sizeof( * V_131 ) ) ;
V_131 = F_91 ( V_68 , V_66 -> V_83 [ 0 ] , struct V_130 ) ;
F_147 ( V_143 , V_68 , V_131 ) ;
F_108 ( V_68 ) ;
V_81:
F_56 ( V_66 ) ;
return V_176 ;
}
static int F_179 ( struct V_123 * V_124 ,
struct V_14 * V_36 ,
struct V_232 * V_142 ,
struct V_201 * V_143 ,
int V_234 )
{
int V_31 = 0 ;
struct V_242 * V_174 ;
struct V_69 V_236 ;
T_2 V_19 = 0 ;
T_2 V_237 = 0 ;
bool V_192 = F_89 ( V_36 , V_135 ) ;
V_174 = F_180 ( V_142 ) ;
F_181 ( V_36 , V_142 , V_174 , V_142 -> V_238 ) ;
if ( V_142 -> type == V_163 )
V_19 = V_174 -> V_19 ;
V_237 = V_174 -> V_12 ;
V_236 . V_24 = V_142 -> V_29 ;
if ( V_192 ) {
V_236 . V_35 = V_174 -> V_186 ;
V_236 . type = V_87 ;
} else {
V_236 . V_35 = V_142 -> V_37 ;
V_236 . type = V_79 ;
}
if ( V_142 -> V_146 != 1 ) {
F_114 ( V_36 ,
L_2 ,
V_142 -> V_29 , V_142 -> V_146 , V_142 -> V_238 , V_237 ,
V_19 ) ;
return - V_195 ;
}
if ( V_142 -> V_238 == V_231 && V_234 ) {
F_35 ( ! V_143 || ! V_143 -> V_144 ) ;
V_31 = F_182 ( V_124 , V_36 ,
V_19 , V_237 ,
V_143 -> V_145 ,
& V_143 -> V_23 ,
V_174 -> V_186 , & V_236 ) ;
} else if ( V_142 -> V_238 == V_231 ) {
V_31 = F_170 ( V_124 , V_36 , V_142 ,
V_19 , V_237 ,
V_174 -> V_186 , 0 , 1 ,
V_143 ) ;
} else if ( V_142 -> V_238 == V_239 ) {
V_31 = F_176 ( V_124 , V_36 , V_142 ,
V_19 , V_237 ,
V_174 -> V_186 , 0 , 1 , V_143 ) ;
} else {
F_96 () ;
}
return V_31 ;
}
static int F_183 ( struct V_123 * V_124 ,
struct V_14 * V_36 ,
struct V_232 * V_142 ,
struct V_201 * V_143 ,
int V_234 )
{
int V_31 = 0 ;
if ( V_124 -> V_241 ) {
if ( V_234 )
F_184 ( V_36 , V_142 -> V_29 ,
V_142 -> V_37 , 1 ) ;
return 0 ;
}
if ( F_185 ( V_142 ) ) {
struct V_127 * V_112 ;
F_35 ( V_143 ) ;
V_112 = F_186 ( V_142 ) ;
F_187 ( V_36 , V_142 , V_112 , V_142 -> V_238 ) ;
if ( V_112 -> V_243 < 0 ) {
struct V_1 * V_2 ;
V_2 = F_79 ( V_36 , V_142 -> V_29 ) ;
ASSERT ( V_2 ) ;
F_85 ( & V_2 -> V_94 -> V_121 ,
- V_142 -> V_37 ) ;
F_6 ( V_2 ) ;
}
if ( V_234 ) {
F_184 ( V_36 , V_142 -> V_29 ,
V_142 -> V_37 , 1 ) ;
if ( V_112 -> V_161 ) {
V_31 = F_188 ( V_124 , V_36 ,
V_142 -> V_29 ,
V_142 -> V_37 ) ;
}
}
F_189 ( V_36 , V_112 -> V_244 ,
V_112 -> V_245 ) ;
return V_31 ;
}
if ( V_142 -> type == V_162 ||
V_142 -> type == V_163 )
V_31 = F_179 ( V_124 , V_36 , V_142 , V_143 ,
V_234 ) ;
else if ( V_142 -> type == V_165 ||
V_142 -> type == V_164 )
V_31 = F_172 ( V_124 , V_36 , V_142 , V_143 ,
V_234 ) ;
else
F_96 () ;
return V_31 ;
}
static inline struct V_232 *
F_190 ( struct V_127 * V_112 )
{
struct V_232 * V_174 ;
if ( F_191 ( & V_112 -> V_246 ) )
return NULL ;
if ( ! F_191 ( & V_112 -> V_247 ) )
return F_192 ( & V_112 -> V_247 ,
struct V_232 , V_248 ) ;
V_174 = F_192 ( & V_112 -> V_246 , struct V_232 ,
V_98 ) ;
ASSERT ( F_191 ( & V_174 -> V_248 ) ) ;
return V_174 ;
}
static T_1 int F_193 ( struct V_123 * V_124 ,
struct V_14 * V_36 ,
unsigned long V_43 )
{
struct V_128 * V_129 ;
struct V_232 * V_174 ;
struct V_127 * V_249 = NULL ;
struct V_201 * V_143 ;
T_7 V_34 = F_194 () ;
int V_31 ;
unsigned long V_8 = 0 ;
unsigned long V_250 = 0 ;
int V_251 = 0 ;
V_129 = & V_124 -> V_141 -> V_129 ;
while ( 1 ) {
if ( ! V_249 ) {
if ( V_8 >= V_43 )
break;
F_12 ( & V_129 -> V_50 ) ;
V_249 = F_195 ( V_124 ) ;
if ( ! V_249 ) {
F_14 ( & V_129 -> V_50 ) ;
break;
}
V_31 = F_196 ( V_124 , V_249 ) ;
F_14 ( & V_129 -> V_50 ) ;
if ( V_31 == - V_199 ) {
V_249 = NULL ;
V_8 ++ ;
continue;
}
}
F_12 ( & V_249 -> V_50 ) ;
F_197 ( V_124 , V_36 , V_129 ,
V_249 ) ;
V_174 = F_190 ( V_249 ) ;
if ( V_174 && V_174 -> V_252 &&
F_198 ( V_36 , V_129 , V_174 -> V_252 ) ) {
F_14 ( & V_249 -> V_50 ) ;
F_12 ( & V_129 -> V_50 ) ;
V_249 -> V_253 = 0 ;
V_129 -> V_254 ++ ;
F_14 ( & V_129 -> V_50 ) ;
F_199 ( V_249 ) ;
V_249 = NULL ;
F_51 () ;
V_8 ++ ;
continue;
}
V_251 = V_249 -> V_251 ;
V_249 -> V_251 = 0 ;
V_143 = V_249 -> V_143 ;
V_249 -> V_143 = NULL ;
if ( ! V_174 ) {
V_174 = & V_249 -> V_142 ;
if ( V_143 && V_251 ) {
F_200 ( V_143 ) ;
V_143 = NULL ;
}
if ( V_143 ) {
F_14 ( & V_249 -> V_50 ) ;
V_31 = F_178 ( V_124 , V_36 ,
V_174 , V_143 ) ;
F_200 ( V_143 ) ;
if ( V_31 ) {
if ( V_251 )
V_249 -> V_251 = 1 ;
F_12 ( & V_129 -> V_50 ) ;
V_249 -> V_253 = 0 ;
V_129 -> V_254 ++ ;
F_14 ( & V_129 -> V_50 ) ;
F_201 ( V_36 ,
L_3 ,
V_31 ) ;
F_199 ( V_249 ) ;
return V_31 ;
}
continue;
}
F_14 ( & V_249 -> V_50 ) ;
F_12 ( & V_129 -> V_50 ) ;
F_12 ( & V_249 -> V_50 ) ;
if ( ! F_191 ( & V_249 -> V_246 ) ||
V_249 -> V_143 ) {
F_14 ( & V_249 -> V_50 ) ;
F_14 ( & V_129 -> V_50 ) ;
continue;
}
V_174 -> V_255 = 0 ;
V_129 -> V_256 -- ;
F_202 ( & V_249 -> V_257 ,
& V_129 -> V_258 ) ;
F_14 ( & V_129 -> V_50 ) ;
} else {
V_250 ++ ;
V_174 -> V_255 = 0 ;
F_203 ( & V_174 -> V_98 ) ;
if ( ! F_191 ( & V_174 -> V_248 ) )
F_203 ( & V_174 -> V_248 ) ;
}
F_204 ( & V_129 -> V_259 ) ;
if ( ! F_185 ( V_174 ) ) {
switch ( V_174 -> V_238 ) {
case V_231 :
case V_260 :
V_249 -> V_142 . V_146 -= V_174 -> V_146 ;
break;
case V_239 :
V_249 -> V_142 . V_146 += V_174 -> V_146 ;
break;
default:
F_8 ( 1 ) ;
}
}
F_14 ( & V_249 -> V_50 ) ;
V_31 = F_183 ( V_124 , V_36 , V_174 , V_143 ,
V_251 ) ;
F_200 ( V_143 ) ;
if ( V_31 ) {
F_12 ( & V_129 -> V_50 ) ;
V_249 -> V_253 = 0 ;
V_129 -> V_254 ++ ;
F_14 ( & V_129 -> V_50 ) ;
F_199 ( V_249 ) ;
F_99 ( V_174 ) ;
F_201 ( V_36 , L_4 ,
V_31 ) ;
return V_31 ;
}
if ( F_185 ( V_174 ) ) {
if ( V_249 -> V_161 &&
V_249 -> V_243 < 0 ) {
F_12 ( & V_129 -> V_50 ) ;
V_129 -> V_261 -= V_174 -> V_37 ;
F_14 ( & V_129 -> V_50 ) ;
}
F_199 ( V_249 ) ;
V_249 = NULL ;
}
F_99 ( V_174 ) ;
V_8 ++ ;
F_51 () ;
}
if ( V_250 > 0 ) {
T_2 V_262 = F_205 ( F_206 ( F_194 () , V_34 ) ) ;
T_2 V_263 ;
F_12 ( & V_129 -> V_50 ) ;
V_263 = V_36 -> V_264 * 3 + V_262 ;
V_36 -> V_264 = V_263 >> 2 ;
F_14 ( & V_129 -> V_50 ) ;
}
return 0 ;
}
static T_2 F_207 ( struct V_265 * V_12 )
{
struct V_17 * V_32 = V_12 -> V_17 ;
struct V_232 * V_266 ;
int V_267 = 1 ;
T_2 V_268 ;
T_2 V_269 = 0 , V_71 = 0 ;
V_32 = F_208 ( V_12 ) ;
if ( V_32 ) {
V_266 = F_13 ( V_32 , struct V_232 , V_17 ) ;
V_269 = V_266 -> V_29 ;
}
V_32 = F_209 ( V_12 ) ;
if ( V_32 ) {
V_266 = F_13 ( V_32 , struct V_232 , V_17 ) ;
V_71 = V_266 -> V_29 ;
}
V_32 = V_12 -> V_17 ;
while ( V_32 ) {
V_266 = F_13 ( V_32 , struct V_232 , V_17 ) ;
F_8 ( ! V_266 -> V_255 ) ;
V_268 = V_266 -> V_29 ;
if ( V_267 )
V_32 = V_32 -> V_25 ;
else
V_32 = V_32 -> V_26 ;
V_267 = 1 - V_267 ;
}
return V_268 ;
}
static inline T_2 F_210 ( struct V_14 * V_36 , T_2 V_270 )
{
T_2 V_37 ;
V_37 = V_270 * ( sizeof( struct V_130 ) +
sizeof( struct V_158 ) ) ;
if ( ! F_89 ( V_36 , V_135 ) )
V_37 += V_270 * sizeof( struct V_150 ) ;
return F_211 ( V_37 , F_212 ( V_36 ) ) ;
}
T_2 F_213 ( struct V_14 * V_36 , T_2 V_271 )
{
T_2 V_272 ;
T_2 V_273 ;
T_2 V_274 ;
V_272 = F_214 ( V_36 ) ;
V_273 = F_215 ( V_272 ,
( T_2 ) F_216 ( V_36 -> V_275 ) ) ;
V_274 = F_215 ( V_271 , V_36 -> V_55 ) ;
V_274 += V_273 - 1 ;
V_274 = F_215 ( V_274 , V_273 ) ;
return V_274 ;
}
int F_217 ( struct V_123 * V_124 ,
struct V_14 * V_36 )
{
struct V_276 * V_277 ;
T_2 V_256 = V_124 -> V_141 -> V_129 . V_254 ;
T_2 V_271 = V_124 -> V_141 -> V_129 . V_261 ;
T_2 V_278 = V_124 -> V_141 -> V_278 ;
T_2 V_37 , V_279 ;
int V_31 = 0 ;
V_37 = F_218 ( V_36 , 1 ) ;
V_256 = F_210 ( V_36 , V_256 ) ;
if ( V_256 > 1 )
V_37 += ( V_256 - 1 ) * V_36 -> V_54 ;
V_37 <<= 1 ;
V_37 += F_213 ( V_36 , V_271 ) *
V_36 -> V_54 ;
V_279 = F_218 ( V_36 ,
V_278 ) ;
V_277 = & V_36 -> V_280 ;
if ( V_277 -> V_94 -> V_122 ) {
V_279 <<= 1 ;
V_37 <<= 1 ;
}
F_12 ( & V_277 -> V_50 ) ;
if ( V_277 -> V_10 <= V_37 + V_279 )
V_31 = 1 ;
F_14 ( & V_277 -> V_50 ) ;
return V_31 ;
}
int F_219 ( struct V_123 * V_124 ,
struct V_14 * V_36 )
{
T_2 V_259 =
F_220 ( & V_124 -> V_141 -> V_129 . V_259 ) ;
T_2 V_281 ;
T_2 V_282 ;
F_2 () ;
V_281 = V_36 -> V_264 ;
V_282 = V_259 * V_281 ;
if ( V_282 >= V_283 )
return 1 ;
if ( V_282 >= V_283 / 2 )
return 2 ;
return F_217 ( V_124 , V_36 ) ;
}
static inline struct V_284 *
F_221 ( struct V_90 * V_91 )
{
return F_58 ( V_91 , struct V_284 , V_91 ) ;
}
static void F_222 ( struct V_90 * V_91 )
{
struct V_284 * V_285 = F_221 ( V_91 ) ;
struct V_123 * V_124 ;
struct V_14 * V_36 = V_285 -> V_12 -> V_36 ;
int V_31 ;
if ( F_223 ( V_36 ) )
goto V_286;
V_124 = F_224 ( V_285 -> V_12 ) ;
if ( F_225 ( V_124 ) ) {
V_285 -> error = F_226 ( V_124 ) ;
goto V_286;
}
V_124 -> V_287 = true ;
if ( V_124 -> V_288 > V_285 -> V_288 )
goto V_33;
V_31 = F_227 ( V_124 , V_36 , V_285 -> V_8 ) ;
if ( V_31 )
V_285 -> error = V_31 ;
V_33:
V_31 = F_228 ( V_124 ) ;
if ( V_31 && ! V_285 -> error )
V_285 -> error = V_31 ;
V_286:
if ( V_285 -> V_287 )
F_229 ( & V_285 -> V_89 ) ;
else
F_10 ( V_285 ) ;
}
int F_230 ( struct V_14 * V_36 ,
unsigned long V_8 , T_2 V_288 , int V_89 )
{
struct V_284 * V_285 ;
int V_31 ;
V_285 = F_231 ( sizeof( * V_285 ) , V_97 ) ;
if ( ! V_285 )
return - V_74 ;
V_285 -> V_12 = V_36 -> V_289 ;
V_285 -> V_8 = V_8 ;
V_285 -> error = 0 ;
V_285 -> V_288 = V_288 ;
if ( V_89 )
V_285 -> V_287 = 1 ;
else
V_285 -> V_287 = 0 ;
F_232 ( & V_285 -> V_89 ) ;
F_69 ( & V_285 -> V_91 , V_290 ,
F_222 , NULL , NULL ) ;
F_77 ( V_36 -> V_291 , & V_285 -> V_91 ) ;
if ( V_89 ) {
F_233 ( & V_285 -> V_89 ) ;
V_31 = V_285 -> error ;
F_10 ( V_285 ) ;
return V_31 ;
}
return 0 ;
}
int F_227 ( struct V_123 * V_124 ,
struct V_14 * V_36 , unsigned long V_8 )
{
struct V_17 * V_142 ;
struct V_128 * V_129 ;
struct V_127 * V_112 ;
int V_31 ;
int V_292 = V_8 == ( unsigned long ) - 1 ;
bool V_293 = V_124 -> V_293 ;
if ( V_124 -> V_241 )
return 0 ;
if ( F_234 ( V_294 , & V_36 -> V_7 ) )
return 0 ;
V_129 = & V_124 -> V_141 -> V_129 ;
if ( V_8 == 0 )
V_8 = F_220 ( & V_129 -> V_259 ) * 2 ;
V_178:
#ifdef F_235
V_129 -> V_295 = F_207 ( & V_129 -> V_12 ) ;
#endif
V_124 -> V_293 = false ;
V_31 = F_193 ( V_124 , V_36 , V_8 ) ;
if ( V_31 < 0 ) {
F_171 ( V_124 , V_31 ) ;
return V_31 ;
}
if ( V_292 ) {
if ( ! F_191 ( & V_124 -> V_296 ) )
F_236 ( V_124 , V_36 ) ;
F_12 ( & V_129 -> V_50 ) ;
V_142 = F_208 ( & V_129 -> V_258 ) ;
if ( ! V_142 ) {
F_14 ( & V_129 -> V_50 ) ;
goto V_81;
}
while ( V_142 ) {
V_112 = F_13 ( V_142 , struct V_127 ,
V_257 ) ;
if ( F_185 ( & V_112 -> V_142 ) ) {
struct V_232 * V_174 ;
V_174 = & V_112 -> V_142 ;
F_27 ( & V_174 -> V_126 ) ;
F_14 ( & V_129 -> V_50 ) ;
F_52 ( & V_112 -> V_86 ) ;
F_50 ( & V_112 -> V_86 ) ;
F_99 ( V_174 ) ;
F_51 () ;
goto V_178;
} else {
F_8 ( 1 ) ;
}
V_142 = F_237 ( V_142 ) ;
}
F_14 ( & V_129 -> V_50 ) ;
F_51 () ;
goto V_178;
}
V_81:
V_124 -> V_293 = V_293 ;
return 0 ;
}
int F_238 ( struct V_123 * V_124 ,
struct V_14 * V_36 ,
T_2 V_29 , T_2 V_37 , T_2 V_7 ,
int V_186 , int V_161 )
{
struct V_201 * V_143 ;
int V_31 ;
V_143 = F_239 () ;
if ( ! V_143 )
return - V_74 ;
V_143 -> V_145 = V_7 ;
V_143 -> V_144 = true ;
V_143 -> V_240 = false ;
V_143 -> V_161 = V_161 ? true : false ;
V_143 -> V_186 = V_186 ;
V_31 = F_240 ( V_36 , V_124 , V_29 ,
V_37 , V_143 ) ;
if ( V_31 )
F_200 ( V_143 ) ;
return V_31 ;
}
static T_1 int F_241 ( struct V_63 * V_12 ,
struct V_65 * V_66 ,
T_2 V_24 , T_2 V_35 , T_2 V_29 )
{
struct V_127 * V_112 ;
struct V_232 * V_174 ;
struct V_235 * V_297 ;
struct V_128 * V_129 ;
struct V_298 * V_299 ;
int V_31 = 0 ;
V_299 = V_12 -> V_36 -> V_300 ;
if ( ! V_299 )
return 0 ;
V_129 = & V_299 -> V_129 ;
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
return - V_199 ;
}
F_14 ( & V_129 -> V_50 ) ;
F_12 ( & V_112 -> V_50 ) ;
F_242 (ref, &head->ref_list, list) {
if ( V_174 -> type != V_165 ) {
V_31 = 1 ;
break;
}
V_297 = F_173 ( V_174 ) ;
if ( V_297 -> V_12 != V_12 -> V_301 . V_24 ||
V_297 -> V_24 != V_24 ||
V_297 -> V_35 != V_35 ) {
V_31 = 1 ;
break;
}
}
F_14 ( & V_112 -> V_50 ) ;
F_50 ( & V_112 -> V_86 ) ;
return V_31 ;
}
static T_1 int F_243 ( struct V_63 * V_12 ,
struct V_65 * V_66 ,
T_2 V_24 , T_2 V_35 , T_2 V_29 )
{
struct V_14 * V_36 = V_12 -> V_36 ;
struct V_63 * V_64 = V_36 -> V_64 ;
struct V_67 * V_68 ;
struct V_173 * V_174 ;
struct V_158 * V_159 ;
struct V_130 * V_131 ;
struct V_69 V_23 ;
T_3 V_132 ;
int type ;
int V_31 ;
V_23 . V_24 = V_29 ;
V_23 . V_35 = ( T_2 ) - 1 ;
V_23 . type = V_79 ;
V_31 = F_41 ( NULL , V_64 , & V_23 , V_66 , 0 , 0 ) ;
if ( V_31 < 0 )
goto V_81;
F_35 ( V_31 == 0 ) ;
V_31 = - V_177 ;
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
F_143 ( V_165 ) )
goto V_81;
if ( F_244 ( V_68 , V_131 ) <=
F_245 ( & V_12 -> V_302 ) )
goto V_81;
V_159 = (struct V_158 * ) ( V_131 + 1 ) ;
type = F_109 ( V_68 , V_159 , V_167 ) ;
if ( type != V_165 )
goto V_81;
V_174 = (struct V_173 * ) ( & V_159 -> V_35 ) ;
if ( F_92 ( V_68 , V_131 ) !=
F_132 ( V_68 , V_174 ) ||
F_119 ( V_68 , V_174 ) !=
V_12 -> V_301 . V_24 ||
F_120 ( V_68 , V_174 ) != V_24 ||
F_121 ( V_68 , V_174 ) != V_35 )
goto V_81;
V_31 = 0 ;
V_81:
return V_31 ;
}
int F_246 ( struct V_63 * V_12 , T_2 V_24 , T_2 V_35 ,
T_2 V_29 )
{
struct V_65 * V_66 ;
int V_31 ;
int V_303 ;
V_66 = F_37 () ;
if ( ! V_66 )
return - V_177 ;
do {
V_31 = F_243 ( V_12 , V_66 , V_24 ,
V_35 , V_29 ) ;
if ( V_31 && V_31 != - V_177 )
goto V_81;
V_303 = F_241 ( V_12 , V_66 , V_24 ,
V_35 , V_29 ) ;
} while ( V_303 == - V_199 );
if ( V_303 && V_303 != - V_177 ) {
V_31 = V_303 ;
goto V_81;
}
if ( V_31 != - V_177 || V_303 != - V_177 )
V_31 = 0 ;
V_81:
F_56 ( V_66 ) ;
if ( V_12 -> V_301 . V_24 == V_304 )
F_8 ( V_31 > 0 ) ;
return V_31 ;
}
static int F_247 ( struct V_123 * V_124 ,
struct V_63 * V_12 ,
struct V_67 * V_305 ,
int V_306 , int V_307 )
{
struct V_14 * V_36 = V_12 -> V_36 ;
T_2 V_29 ;
T_2 V_37 ;
T_2 V_19 ;
T_2 V_237 ;
T_3 V_72 ;
struct V_69 V_23 ;
struct V_308 * V_309 ;
int V_42 ;
int V_186 ;
int V_31 = 0 ;
int (* F_248)( struct V_123 * ,
struct V_14 * ,
T_2 , T_2 , T_2 , T_2 , T_2 , T_2 );
if ( F_249 ( V_36 ) )
return 0 ;
V_237 = F_250 ( V_305 ) ;
V_72 = F_42 ( V_305 ) ;
V_186 = F_251 ( V_305 ) ;
if ( ! F_234 ( V_310 , & V_12 -> V_311 ) && V_186 == 0 )
return 0 ;
if ( V_307 )
F_248 = F_167 ;
else
F_248 = V_312 ;
if ( V_306 )
V_19 = V_305 -> V_34 ;
else
V_19 = 0 ;
for ( V_42 = 0 ; V_42 < V_72 ; V_42 ++ ) {
if ( V_186 == 0 ) {
F_44 ( V_305 , & V_23 , V_42 ) ;
if ( V_23 . type != V_313 )
continue;
V_309 = F_91 ( V_305 , V_42 ,
struct V_308 ) ;
if ( F_252 ( V_305 , V_309 ) ==
V_314 )
continue;
V_29 = F_253 ( V_305 , V_309 ) ;
if ( V_29 == 0 )
continue;
V_37 = F_254 ( V_305 , V_309 ) ;
V_23 . V_35 -= F_255 ( V_305 , V_309 ) ;
V_31 = F_248 ( V_124 , V_36 , V_29 , V_37 ,
V_19 , V_237 , V_23 . V_24 ,
V_23 . V_35 ) ;
if ( V_31 )
goto V_179;
} else {
V_29 = F_256 ( V_305 , V_42 ) ;
V_37 = V_36 -> V_54 ;
V_31 = F_248 ( V_124 , V_36 , V_29 , V_37 ,
V_19 , V_237 , V_186 - 1 , 0 ) ;
if ( V_31 )
goto V_179;
}
}
return 0 ;
V_179:
return V_31 ;
}
int F_257 ( struct V_123 * V_124 , struct V_63 * V_12 ,
struct V_67 * V_305 , int V_306 )
{
return F_247 ( V_124 , V_12 , V_305 , V_306 , 1 ) ;
}
int F_258 ( struct V_123 * V_124 , struct V_63 * V_12 ,
struct V_67 * V_305 , int V_306 )
{
return F_247 ( V_124 , V_12 , V_305 , V_306 , 0 ) ;
}
static int F_259 ( struct V_123 * V_124 ,
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
V_31 = - V_177 ;
goto V_179;
}
V_68 = V_66 -> V_82 [ 0 ] ;
V_151 = F_260 ( V_68 , V_66 -> V_83 [ 0 ] ) ;
F_261 ( V_68 , & V_2 -> V_95 , V_151 , sizeof( V_2 -> V_95 ) ) ;
F_108 ( V_68 ) ;
V_179:
F_48 ( V_66 ) ;
return V_31 ;
}
static struct V_1 *
F_262 ( struct V_14 * V_36 ,
struct V_1 * V_2 )
{
struct V_17 * V_142 ;
F_12 ( & V_36 -> V_20 ) ;
if ( F_263 ( & V_2 -> V_22 ) ) {
const T_2 V_315 = V_2 -> V_23 . V_24 + V_2 -> V_23 . V_35 ;
F_14 ( & V_36 -> V_20 ) ;
F_6 ( V_2 ) ;
V_2 = F_78 ( V_36 , V_315 ) ; return V_2 ;
}
V_142 = F_237 ( & V_2 -> V_22 ) ;
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
static int F_264 ( struct V_1 * V_16 ,
struct V_123 * V_124 ,
struct V_65 * V_66 )
{
struct V_14 * V_36 = V_16 -> V_36 ;
struct V_63 * V_12 = V_36 -> V_289 ;
struct V_316 * V_316 = NULL ;
struct V_317 * V_318 = NULL ;
T_2 V_319 = 0 ;
int V_320 = V_321 ;
T_2 V_322 = 0 ;
int V_323 = 0 ;
int V_31 = 0 ;
if ( V_16 -> V_23 . V_35 < ( 100 * V_324 ) ) {
F_12 ( & V_16 -> V_50 ) ;
V_16 -> V_325 = V_326 ;
F_14 ( & V_16 -> V_50 ) ;
return 0 ;
}
if ( V_124 -> V_241 )
return 0 ;
V_178:
V_316 = F_265 ( V_36 , V_16 , V_66 ) ;
if ( F_225 ( V_316 ) && F_226 ( V_316 ) != - V_177 ) {
V_31 = F_226 ( V_316 ) ;
F_48 ( V_66 ) ;
goto V_81;
}
if ( F_225 ( V_316 ) ) {
F_35 ( V_323 ) ;
V_323 ++ ;
if ( V_16 -> V_327 )
goto V_137;
V_31 = F_266 ( V_36 , V_124 , V_16 ,
V_66 ) ;
if ( V_31 )
goto V_137;
goto V_178;
}
if ( V_16 -> V_328 == V_124 -> V_288 &&
F_267 ( V_316 ) ) {
V_320 = V_329 ;
goto V_330;
}
F_268 ( V_316 ) -> V_331 = 0 ;
V_31 = F_269 ( V_124 , V_12 , V_316 ) ;
if ( V_31 ) {
F_171 ( V_124 , V_31 ) ;
goto V_330;
}
F_8 ( V_31 ) ;
if ( F_267 ( V_316 ) > 0 ) {
V_31 = F_270 ( V_36 ,
& V_36 -> V_280 ) ;
if ( V_31 )
goto V_330;
V_31 = F_271 ( V_124 , NULL , V_316 ) ;
if ( V_31 )
goto V_330;
}
F_12 ( & V_16 -> V_50 ) ;
if ( V_16 -> V_3 != V_4 ||
! F_272 ( V_36 , V_332 ) ) {
V_320 = V_326 ;
F_14 ( & V_16 -> V_50 ) ;
goto V_330;
}
F_14 ( & V_16 -> V_50 ) ;
if ( F_234 ( V_333 , & V_124 -> V_141 -> V_7 ) ) {
V_31 = - V_334 ;
goto V_330;
}
V_322 = F_211 ( V_16 -> V_23 . V_35 , V_335 ) ;
if ( ! V_322 )
V_322 = 1 ;
V_322 *= 16 ;
V_322 *= V_336 ;
V_31 = F_273 ( V_316 , & V_318 , 0 , V_322 ) ;
if ( V_31 )
goto V_330;
V_31 = F_274 ( V_316 , V_124 , 0 , 0 , V_322 ,
V_322 , V_322 ,
& V_319 ) ;
if ( ! V_31 )
V_320 = V_329 ;
else if ( V_31 == - V_334 )
F_275 ( V_333 , & V_124 -> V_141 -> V_7 ) ;
V_330:
F_276 ( V_316 ) ;
V_137:
F_48 ( V_66 ) ;
V_81:
F_12 ( & V_16 -> V_50 ) ;
if ( ! V_31 && V_320 == V_329 )
V_16 -> V_328 = V_124 -> V_288 ;
V_16 -> V_325 = V_320 ;
F_14 ( & V_16 -> V_50 ) ;
F_277 ( V_318 ) ;
return V_31 ;
}
int F_278 ( struct V_123 * V_124 ,
struct V_14 * V_36 )
{
struct V_1 * V_2 , * V_337 ;
struct V_298 * V_299 = V_124 -> V_141 ;
struct V_65 * V_66 ;
if ( F_191 ( & V_299 -> V_338 ) ||
! F_272 ( V_36 , V_332 ) )
return 0 ;
V_66 = F_37 () ;
if ( ! V_66 )
return - V_74 ;
F_279 (cache, tmp, &cur_trans->dirty_bgs,
dirty_list) {
if ( V_2 -> V_325 == V_339 )
F_264 ( V_2 , V_124 , V_66 ) ;
}
F_56 ( V_66 ) ;
return 0 ;
}
int F_280 ( struct V_123 * V_124 ,
struct V_14 * V_36 )
{
struct V_1 * V_2 ;
struct V_298 * V_299 = V_124 -> V_141 ;
int V_31 = 0 ;
int V_340 ;
struct V_65 * V_66 = NULL ;
F_281 ( V_341 ) ;
struct V_111 * V_342 = & V_299 -> V_343 ;
int V_344 = 0 ;
int V_345 = 0 ;
F_12 ( & V_299 -> V_346 ) ;
if ( F_191 ( & V_299 -> V_338 ) ) {
F_14 ( & V_299 -> V_346 ) ;
return 0 ;
}
F_282 ( & V_299 -> V_338 , & V_341 ) ;
F_14 ( & V_299 -> V_346 ) ;
V_178:
F_236 ( V_124 , V_36 ) ;
if ( ! V_66 ) {
V_66 = F_37 () ;
if ( ! V_66 )
return - V_74 ;
}
F_52 ( & V_124 -> V_141 -> V_347 ) ;
while ( ! F_191 ( & V_341 ) ) {
V_2 = F_192 ( & V_341 ,
struct V_1 ,
V_348 ) ;
if ( ! F_191 ( & V_2 -> V_349 ) ) {
F_283 ( & V_2 -> V_349 ) ;
F_284 ( V_124 , V_2 , V_66 ) ;
F_6 ( V_2 ) ;
}
F_12 ( & V_299 -> V_346 ) ;
F_283 ( & V_2 -> V_348 ) ;
F_14 ( & V_299 -> V_346 ) ;
V_340 = 1 ;
F_264 ( V_2 , V_124 , V_66 ) ;
if ( V_2 -> V_325 == V_329 ) {
V_2 -> V_350 . V_316 = NULL ;
V_31 = F_285 ( V_36 , V_124 ,
V_2 , V_66 ) ;
if ( V_31 == 0 && V_2 -> V_350 . V_316 ) {
V_344 ++ ;
V_340 = 0 ;
F_75 ( & V_2 -> V_349 , V_342 ) ;
} else {
V_31 = 0 ;
}
}
if ( ! V_31 ) {
V_31 = F_259 ( V_124 , V_36 ,
V_66 , V_2 ) ;
if ( V_31 == - V_177 ) {
V_31 = 0 ;
F_12 ( & V_299 -> V_346 ) ;
if ( F_191 ( & V_2 -> V_348 ) ) {
F_75 ( & V_2 -> V_348 ,
& V_299 -> V_338 ) ;
F_4 ( V_2 ) ;
}
F_14 ( & V_299 -> V_346 ) ;
} else if ( V_31 ) {
F_171 ( V_124 , V_31 ) ;
}
}
if ( V_340 )
F_6 ( V_2 ) ;
if ( V_31 )
break;
F_50 ( & V_124 -> V_141 -> V_347 ) ;
F_52 ( & V_124 -> V_141 -> V_347 ) ;
}
F_50 ( & V_124 -> V_141 -> V_347 ) ;
V_31 = F_227 ( V_124 , V_36 , 0 ) ;
if ( ! V_31 && V_345 == 0 ) {
V_345 ++ ;
F_12 ( & V_299 -> V_346 ) ;
F_282 ( & V_299 -> V_338 , & V_341 ) ;
if ( ! F_191 ( & V_341 ) ) {
F_14 ( & V_299 -> V_346 ) ;
goto V_178;
}
F_14 ( & V_299 -> V_346 ) ;
} else if ( V_31 < 0 ) {
F_286 ( V_299 , V_36 ) ;
}
F_56 ( V_66 ) ;
return V_31 ;
}
int F_287 ( struct V_123 * V_124 ,
struct V_14 * V_36 )
{
struct V_1 * V_2 ;
struct V_298 * V_299 = V_124 -> V_141 ;
int V_31 = 0 ;
int V_340 ;
struct V_65 * V_66 ;
struct V_111 * V_342 = & V_299 -> V_343 ;
int V_344 = 0 ;
V_66 = F_37 () ;
if ( ! V_66 )
return - V_74 ;
F_12 ( & V_299 -> V_346 ) ;
while ( ! F_191 ( & V_299 -> V_338 ) ) {
V_2 = F_192 ( & V_299 -> V_338 ,
struct V_1 ,
V_348 ) ;
if ( ! F_191 ( & V_2 -> V_349 ) ) {
F_14 ( & V_299 -> V_346 ) ;
F_283 ( & V_2 -> V_349 ) ;
F_284 ( V_124 , V_2 , V_66 ) ;
F_6 ( V_2 ) ;
F_12 ( & V_299 -> V_346 ) ;
}
F_283 ( & V_2 -> V_348 ) ;
F_14 ( & V_299 -> V_346 ) ;
V_340 = 1 ;
F_264 ( V_2 , V_124 , V_66 ) ;
if ( ! V_31 )
V_31 = F_227 ( V_124 , V_36 ,
( unsigned long ) - 1 ) ;
if ( ! V_31 && V_2 -> V_325 == V_329 ) {
V_2 -> V_350 . V_316 = NULL ;
V_31 = F_285 ( V_36 , V_124 ,
V_2 , V_66 ) ;
if ( V_31 == 0 && V_2 -> V_350 . V_316 ) {
V_344 ++ ;
V_340 = 0 ;
F_75 ( & V_2 -> V_349 , V_342 ) ;
} else {
V_31 = 0 ;
}
}
if ( ! V_31 ) {
V_31 = F_259 ( V_124 , V_36 ,
V_66 , V_2 ) ;
if ( V_31 == - V_177 ) {
F_288 ( V_299 -> V_351 ,
F_220 ( & V_299 -> V_352 ) == 1 ) ;
V_31 = F_259 ( V_124 , V_36 ,
V_66 , V_2 ) ;
}
if ( V_31 )
F_171 ( V_124 , V_31 ) ;
}
if ( V_340 )
F_6 ( V_2 ) ;
F_12 ( & V_299 -> V_346 ) ;
}
F_14 ( & V_299 -> V_346 ) ;
while ( ! F_191 ( V_342 ) ) {
V_2 = F_192 ( V_342 , struct V_1 ,
V_349 ) ;
F_283 ( & V_2 -> V_349 ) ;
F_284 ( V_124 , V_2 , V_66 ) ;
F_6 ( V_2 ) ;
}
F_56 ( V_66 ) ;
return V_31 ;
}
int F_289 ( struct V_14 * V_36 , T_2 V_29 )
{
struct V_1 * V_16 ;
int V_353 = 0 ;
V_16 = F_79 ( V_36 , V_29 ) ;
if ( ! V_16 || V_16 -> V_327 )
V_353 = 1 ;
if ( V_16 )
F_6 ( V_16 ) ;
return V_353 ;
}
bool F_290 ( struct V_14 * V_36 , T_2 V_29 )
{
struct V_1 * V_354 ;
bool V_31 = true ;
V_354 = F_79 ( V_36 , V_29 ) ;
if ( ! V_354 )
return false ;
F_12 ( & V_354 -> V_50 ) ;
if ( V_354 -> V_327 )
V_31 = false ;
else
F_5 ( & V_354 -> V_355 ) ;
F_14 ( & V_354 -> V_50 ) ;
if ( ! V_31 )
F_6 ( V_354 ) ;
return V_31 ;
}
void F_291 ( struct V_14 * V_36 , T_2 V_29 )
{
struct V_1 * V_354 ;
V_354 = F_79 ( V_36 , V_29 ) ;
ASSERT ( V_354 ) ;
if ( F_7 ( & V_354 -> V_355 ) )
F_292 ( & V_354 -> V_355 ) ;
F_6 ( V_354 ) ;
F_6 ( V_354 ) ;
}
static int F_293 ( T_8 * V_356 )
{
F_71 () ;
return 0 ;
}
void F_294 ( struct V_1 * V_354 )
{
F_295 ( & V_354 -> V_355 ,
F_293 ,
V_101 ) ;
}
static const char * F_296 ( T_2 V_7 )
{
switch ( V_7 ) {
case V_53 | V_120 :
return L_5 ;
case V_53 :
return L_6 ;
case V_120 :
return L_7 ;
case V_119 :
return L_8 ;
default:
F_8 ( 1 ) ;
return L_9 ;
} ;
}
static int F_297 ( struct V_14 * V_15 , T_2 V_7 ,
struct V_110 * * V_357 )
{
struct V_110 * V_94 ;
int V_42 ;
int V_31 ;
V_94 = F_64 ( sizeof( * V_94 ) , V_97 ) ;
if ( ! V_94 )
return - V_74 ;
V_31 = F_298 ( & V_94 -> V_121 , 0 ,
V_358 ) ;
if ( V_31 ) {
F_10 ( V_94 ) ;
return V_31 ;
}
for ( V_42 = 0 ; V_42 < V_359 ; V_42 ++ )
F_65 ( & V_94 -> V_360 [ V_42 ] ) ;
F_299 ( & V_94 -> V_361 ) ;
F_300 ( & V_94 -> V_50 ) ;
V_94 -> V_7 = V_7 & V_114 ;
V_94 -> V_362 = V_363 ;
F_67 ( & V_94 -> V_89 ) ;
F_65 ( & V_94 -> V_364 ) ;
F_65 ( & V_94 -> V_365 ) ;
F_65 ( & V_94 -> V_366 ) ;
V_31 = F_301 ( & V_94 -> V_367 , & V_368 ,
V_15 -> V_369 , L_10 ,
F_296 ( V_94 -> V_7 ) ) ;
if ( V_31 ) {
F_302 ( & V_94 -> V_121 ) ;
F_10 ( V_94 ) ;
return V_31 ;
}
* V_357 = V_94 ;
F_303 ( & V_94 -> V_98 , & V_15 -> V_94 ) ;
if ( V_7 & V_120 )
V_15 -> V_370 = V_94 ;
return V_31 ;
}
static void F_304 ( struct V_14 * V_15 , T_2 V_7 ,
T_2 V_371 , T_2 V_93 ,
T_2 V_372 ,
struct V_110 * * V_94 )
{
struct V_110 * V_113 ;
int V_373 ;
if ( V_7 & ( V_374 | V_375 |
V_376 ) )
V_373 = 2 ;
else
V_373 = 1 ;
V_113 = F_80 ( V_15 , V_7 ) ;
ASSERT ( V_113 ) ;
F_12 ( & V_113 -> V_50 ) ;
V_113 -> V_371 += V_371 ;
V_113 -> V_377 += V_371 * V_373 ;
V_113 -> V_93 += V_93 ;
V_113 -> V_378 += V_93 * V_373 ;
V_113 -> V_372 += V_372 ;
if ( V_371 > 0 )
V_113 -> V_122 = 0 ;
F_305 ( V_15 , V_113 , V_371 -
V_93 - V_372 ) ;
F_14 ( & V_113 -> V_50 ) ;
* V_94 = V_113 ;
}
static void F_306 ( struct V_14 * V_36 , T_2 V_7 )
{
T_2 V_379 = F_307 ( V_7 ) &
V_380 ;
F_308 ( & V_36 -> V_381 ) ;
if ( V_7 & V_120 )
V_36 -> V_382 |= V_379 ;
if ( V_7 & V_53 )
V_36 -> V_383 |= V_379 ;
if ( V_7 & V_119 )
V_36 -> V_384 |= V_379 ;
F_309 ( & V_36 -> V_381 ) ;
}
static T_2 F_310 ( struct V_14 * V_36 , T_2 V_7 )
{
struct V_385 * V_386 = V_36 -> V_387 ;
T_2 V_388 = 0 ;
if ( ! V_386 )
return 0 ;
if ( V_7 & V_120 &&
V_386 -> V_389 . V_7 & V_390 ) {
V_388 = V_120 | V_386 -> V_389 . V_388 ;
} else if ( V_7 & V_119 &&
V_386 -> V_391 . V_7 & V_390 ) {
V_388 = V_119 | V_386 -> V_391 . V_388 ;
} else if ( V_7 & V_53 &&
V_386 -> V_392 . V_7 & V_390 ) {
V_388 = V_53 | V_386 -> V_392 . V_388 ;
}
return V_388 ;
}
static T_2 F_311 ( struct V_14 * V_36 , T_2 V_7 )
{
T_2 V_393 = V_36 -> V_394 -> V_395 ;
T_2 V_388 ;
T_2 V_396 ;
T_2 V_397 = 0 ;
F_12 ( & V_36 -> V_398 ) ;
V_388 = F_310 ( V_36 , V_7 ) ;
if ( V_388 ) {
if ( ( V_7 & V_388 ) & V_380 ) {
F_14 ( & V_36 -> V_398 ) ;
return F_312 ( V_388 ) ;
}
}
F_14 ( & V_36 -> V_398 ) ;
for ( V_396 = 0 ; V_396 < V_359 ; V_396 ++ ) {
if ( V_393 >= V_399 [ V_396 ] . V_400 )
V_397 |= V_401 [ V_396 ] ;
}
V_397 &= V_7 ;
if ( V_397 & V_402 )
V_397 = V_402 ;
else if ( V_397 & V_403 )
V_397 = V_403 ;
else if ( V_397 & V_376 )
V_397 = V_376 ;
else if ( V_397 & V_375 )
V_397 = V_375 ;
else if ( V_397 & V_404 )
V_397 = V_404 ;
V_7 &= ~ V_405 ;
return F_312 ( V_7 | V_397 ) ;
}
static T_2 F_313 ( struct V_14 * V_36 , T_2 V_406 )
{
unsigned V_252 ;
T_2 V_7 ;
do {
V_7 = V_406 ;
V_252 = F_314 ( & V_36 -> V_381 ) ;
if ( V_7 & V_120 )
V_7 |= V_36 -> V_382 ;
else if ( V_7 & V_119 )
V_7 |= V_36 -> V_384 ;
else if ( V_7 & V_53 )
V_7 |= V_36 -> V_383 ;
} while ( F_315 ( & V_36 -> V_381 , V_252 ) );
return F_311 ( V_36 , V_7 ) ;
}
static T_2 F_316 ( struct V_63 * V_12 , int V_389 )
{
struct V_14 * V_36 = V_12 -> V_36 ;
T_2 V_7 ;
T_2 V_31 ;
if ( V_389 )
V_7 = V_120 ;
else if ( V_12 == V_36 -> V_407 )
V_7 = V_119 ;
else
V_7 = V_53 ;
V_31 = F_313 ( V_36 , V_7 ) ;
return V_31 ;
}
T_2 F_317 ( struct V_14 * V_36 )
{
return F_313 ( V_36 , V_120 ) ;
}
T_2 F_318 ( struct V_14 * V_36 )
{
return F_313 ( V_36 , V_53 ) ;
}
T_2 F_319 ( struct V_14 * V_36 )
{
return F_313 ( V_36 , V_119 ) ;
}
static T_2 F_320 ( struct V_110 * V_408 ,
bool V_409 )
{
ASSERT ( V_408 ) ;
return V_408 -> V_93 + V_408 -> V_410 +
V_408 -> V_411 + V_408 -> V_372 +
( V_409 ? V_408 -> V_412 : 0 ) ;
}
int F_321 ( struct V_413 * V_316 , T_2 V_223 )
{
struct V_63 * V_12 = V_316 -> V_12 ;
struct V_14 * V_36 = V_12 -> V_36 ;
struct V_110 * V_370 = V_36 -> V_370 ;
T_2 V_414 ;
int V_31 = 0 ;
int V_415 = 2 ;
int V_416 ;
V_223 = F_158 ( V_223 , V_36 -> V_55 ) ;
if ( F_322 ( V_316 ) ) {
V_415 = 0 ;
ASSERT ( V_417 -> V_418 ) ;
}
V_178:
F_12 ( & V_370 -> V_50 ) ;
V_414 = F_320 ( V_370 , true ) ;
if ( V_414 + V_223 > V_370 -> V_371 ) {
struct V_123 * V_124 ;
if ( ! V_370 -> V_122 ) {
T_2 V_419 ;
V_370 -> V_362 = V_420 ;
F_14 ( & V_370 -> V_50 ) ;
V_419 = F_317 ( V_36 ) ;
V_124 = F_224 ( V_12 ) ;
if ( F_225 ( V_124 ) )
return F_226 ( V_124 ) ;
V_31 = F_323 ( V_124 , V_36 , V_419 ,
V_363 ) ;
F_228 ( V_124 ) ;
if ( V_31 < 0 ) {
if ( V_31 != - V_334 )
return V_31 ;
else {
V_416 = 1 ;
goto V_421;
}
}
goto V_178;
}
V_416 = F_324 (
& V_370 -> V_121 ,
V_414 + V_223 - V_370 -> V_371 ) ;
F_14 ( & V_370 -> V_50 ) ;
V_421:
if ( V_415 &&
! F_220 ( & V_36 -> V_422 ) ) {
V_415 -- ;
if ( V_415 > 0 ) {
F_325 ( V_36 , 0 , - 1 ) ;
F_326 ( V_36 , V_423 , 0 ,
( T_2 ) - 1 ) ;
}
V_124 = F_224 ( V_12 ) ;
if ( F_225 ( V_124 ) )
return F_226 ( V_124 ) ;
if ( V_416 >= 0 ||
F_234 ( V_424 ,
& V_124 -> V_141 -> V_7 ) ||
V_415 > 0 ) {
V_31 = F_327 ( V_124 ) ;
if ( V_31 )
return V_31 ;
F_52 ( & V_36 -> V_425 ) ;
F_50 ( & V_36 -> V_425 ) ;
goto V_178;
} else {
F_228 ( V_124 ) ;
}
}
F_328 ( V_36 ,
L_11 ,
V_370 -> V_7 , V_223 , 1 ) ;
return - V_334 ;
}
V_370 -> V_412 += V_223 ;
F_328 ( V_36 , L_12 ,
V_370 -> V_7 , V_223 , 1 ) ;
F_14 ( & V_370 -> V_50 ) ;
return V_31 ;
}
int F_273 ( struct V_316 * V_316 ,
struct V_317 * * V_10 , T_2 V_34 , T_2 V_47 )
{
struct V_14 * V_36 = F_329 ( V_316 -> V_426 ) ;
int V_31 ;
V_47 = F_330 ( V_34 + V_47 , V_36 -> V_55 ) -
F_159 ( V_34 , V_36 -> V_55 ) ;
V_34 = F_159 ( V_34 , V_36 -> V_55 ) ;
V_31 = F_321 ( F_268 ( V_316 ) , V_47 ) ;
if ( V_31 < 0 )
return V_31 ;
V_31 = F_331 ( V_316 , V_10 , V_34 , V_47 ) ;
if ( V_31 < 0 )
F_332 ( V_316 , V_34 , V_47 ) ;
else
V_31 = 0 ;
return V_31 ;
}
void F_332 ( struct V_316 * V_316 , T_2 V_34 ,
T_2 V_47 )
{
struct V_14 * V_36 = F_329 ( V_316 -> V_426 ) ;
struct V_110 * V_370 ;
V_47 = F_330 ( V_34 + V_47 , V_36 -> V_55 ) -
F_159 ( V_34 , V_36 -> V_55 ) ;
V_34 = F_159 ( V_34 , V_36 -> V_55 ) ;
V_370 = V_36 -> V_370 ;
F_12 ( & V_370 -> V_50 ) ;
if ( F_8 ( V_370 -> V_412 < V_47 ) )
V_370 -> V_412 = 0 ;
else
V_370 -> V_412 -= V_47 ;
F_328 ( V_36 , L_12 ,
V_370 -> V_7 , V_47 , 0 ) ;
F_14 ( & V_370 -> V_50 ) ;
}
void F_333 ( struct V_316 * V_316 ,
struct V_317 * V_10 , T_2 V_34 , T_2 V_47 )
{
struct V_63 * V_12 = F_268 ( V_316 ) -> V_12 ;
V_47 = F_330 ( V_34 + V_47 , V_12 -> V_36 -> V_55 ) -
F_159 ( V_34 , V_12 -> V_36 -> V_55 ) ;
V_34 = F_159 ( V_34 , V_12 -> V_36 -> V_55 ) ;
F_332 ( V_316 , V_34 , V_47 ) ;
F_334 ( V_316 , V_10 , V_34 , V_47 ) ;
}
static void F_335 ( struct V_14 * V_15 )
{
struct V_111 * V_112 = & V_15 -> V_94 ;
struct V_110 * V_113 ;
F_81 () ;
F_82 (found, head, list) {
if ( V_113 -> V_7 & V_53 )
V_113 -> V_362 = V_420 ;
}
F_83 () ;
}
static inline T_2 F_336 ( struct V_276 * V_427 )
{
return ( V_427 -> V_59 << 1 ) ;
}
static int F_337 ( struct V_14 * V_36 ,
struct V_110 * V_428 , int V_429 )
{
struct V_276 * V_277 = & V_36 -> V_280 ;
T_2 V_93 = F_320 ( V_428 , false ) ;
T_2 V_430 ;
if ( V_429 == V_420 )
return 1 ;
if ( V_428 -> V_7 & V_53 )
V_93 += F_336 ( V_277 ) ;
if ( V_429 == V_431 ) {
V_430 = F_338 ( V_36 -> V_275 ) ;
V_430 = F_38 ( T_2 , V_432 , F_339 ( V_430 , 1 ) ) ;
if ( V_428 -> V_371 - V_93 < V_430 )
return 1 ;
}
if ( V_93 + V_433 < F_340 ( V_428 -> V_371 , 8 ) )
return 0 ;
return 1 ;
}
static T_2 F_341 ( struct V_14 * V_36 , T_2 type )
{
T_2 V_434 ;
if ( type & ( V_376 |
V_404 |
V_403 |
V_402 ) )
V_434 = V_36 -> V_394 -> V_395 ;
else if ( type & V_375 )
V_434 = 2 ;
else
V_434 = 1 ;
return V_434 ;
}
void F_342 ( struct V_123 * V_124 ,
struct V_14 * V_36 , T_2 type )
{
struct V_110 * V_15 ;
T_2 V_435 ;
T_2 V_430 ;
int V_31 = 0 ;
T_2 V_436 ;
ASSERT ( F_343 ( & V_36 -> V_437 ) ) ;
V_15 = F_80 ( V_36 , V_119 ) ;
F_12 ( & V_15 -> V_50 ) ;
V_435 = V_15 -> V_371 - F_320 ( V_15 , true ) ;
F_14 ( & V_15 -> V_50 ) ;
V_436 = F_341 ( V_36 , type ) ;
V_430 = F_344 ( V_36 , V_436 ) +
F_218 ( V_36 , 1 ) ;
if ( V_435 < V_430 && F_272 ( V_36 , V_438 ) ) {
F_345 ( V_36 , L_13 ,
V_435 , V_430 , type ) ;
F_346 ( V_36 , V_15 , 0 , 0 ) ;
}
if ( V_435 < V_430 ) {
T_2 V_7 = F_319 ( V_36 ) ;
V_31 = F_347 ( V_124 , V_36 , V_7 ) ;
}
if ( ! V_31 ) {
V_31 = F_348 ( V_36 -> V_407 ,
& V_36 -> V_439 ,
V_430 , V_440 ) ;
if ( ! V_31 )
V_124 -> V_441 += V_430 ;
}
}
static int F_323 ( struct V_123 * V_124 ,
struct V_14 * V_36 , T_2 V_7 , int V_429 )
{
struct V_110 * V_94 ;
int V_442 = 0 ;
int V_31 = 0 ;
if ( V_124 -> V_443 )
return - V_334 ;
V_94 = F_80 ( V_36 , V_7 ) ;
if ( ! V_94 ) {
V_31 = F_297 ( V_36 , V_7 , & V_94 ) ;
if ( V_31 )
return V_31 ;
}
V_178:
F_12 ( & V_94 -> V_50 ) ;
if ( V_429 < V_94 -> V_362 )
V_429 = V_94 -> V_362 ;
if ( V_94 -> V_122 ) {
if ( F_337 ( V_36 , V_94 , V_429 ) )
V_31 = - V_334 ;
else
V_31 = 0 ;
F_14 ( & V_94 -> V_50 ) ;
return V_31 ;
}
if ( ! F_337 ( V_36 , V_94 , V_429 ) ) {
F_14 ( & V_94 -> V_50 ) ;
return 0 ;
} else if ( V_94 -> V_444 ) {
V_442 = 1 ;
} else {
V_94 -> V_444 = 1 ;
}
F_14 ( & V_94 -> V_50 ) ;
F_52 ( & V_36 -> V_437 ) ;
if ( V_442 ) {
F_50 ( & V_36 -> V_437 ) ;
V_442 = 0 ;
goto V_178;
}
V_124 -> V_443 = true ;
if ( F_349 ( V_94 ) )
V_7 |= ( V_120 | V_53 ) ;
if ( V_7 & V_120 && V_36 -> V_445 ) {
V_36 -> V_446 ++ ;
if ( ! ( V_36 -> V_446 %
V_36 -> V_445 ) )
F_335 ( V_36 ) ;
}
F_342 ( V_124 , V_36 , V_7 ) ;
V_31 = F_347 ( V_124 , V_36 , V_7 ) ;
V_124 -> V_443 = false ;
F_12 ( & V_94 -> V_50 ) ;
if ( V_31 < 0 && V_31 != - V_334 )
goto V_81;
if ( V_31 )
V_94 -> V_122 = 1 ;
else
V_31 = 1 ;
V_94 -> V_362 = V_363 ;
V_81:
V_94 -> V_444 = 0 ;
F_14 ( & V_94 -> V_50 ) ;
F_50 ( & V_36 -> V_437 ) ;
if ( V_124 -> V_293 &&
V_124 -> V_441 >= ( T_2 ) V_433 ) {
F_236 ( V_124 , V_36 ) ;
F_350 ( V_124 ) ;
}
return V_31 ;
}
static int F_351 ( struct V_14 * V_36 ,
struct V_110 * V_94 , T_2 V_223 ,
enum V_447 V_448 ,
bool V_449 )
{
struct V_276 * V_277 = & V_36 -> V_280 ;
T_2 V_450 ;
T_2 V_451 ;
T_2 V_452 ;
T_2 V_414 ;
if ( V_94 -> V_7 & V_120 )
return 0 ;
if ( V_449 )
V_450 = F_319 ( V_36 ) ;
else
V_450 = F_318 ( V_36 ) ;
V_414 = F_320 ( V_94 , false ) ;
F_12 ( & V_277 -> V_50 ) ;
V_451 = F_336 ( V_277 ) ;
F_14 ( & V_277 -> V_50 ) ;
if ( V_414 + V_451 >= V_94 -> V_371 )
return 0 ;
V_414 += V_94 -> V_412 ;
V_452 = F_352 ( & V_36 -> V_453 ) ;
if ( V_450 & ( V_374 |
V_375 |
V_376 ) )
V_452 >>= 1 ;
if ( V_448 == V_454 )
V_452 >>= 3 ;
else
V_452 >>= 1 ;
if ( V_414 + V_223 < V_94 -> V_371 + V_452 )
return 1 ;
return 0 ;
}
static void F_353 ( struct V_14 * V_36 ,
unsigned long V_455 , int V_456 )
{
struct V_457 * V_458 = V_36 -> V_458 ;
if ( F_354 ( & V_458 -> V_459 ) ) {
F_355 ( V_458 , V_455 , V_460 ) ;
F_49 ( & V_458 -> V_459 ) ;
} else {
F_325 ( V_36 , 0 , V_456 ) ;
if ( ! V_417 -> V_418 )
F_326 ( V_36 , V_456 , 0 , ( T_2 ) - 1 ) ;
}
}
static inline T_2 F_356 ( struct V_14 * V_36 ,
T_2 V_461 )
{
T_2 V_223 ;
T_2 V_43 ;
V_223 = F_218 ( V_36 , 1 ) ;
V_43 = F_215 ( V_461 , V_223 ) ;
if ( ! V_43 )
V_43 = 1 ;
return V_43 ;
}
static void F_357 ( struct V_14 * V_36 , T_2 V_461 ,
T_2 V_462 , bool V_463 )
{
struct V_276 * V_464 ;
struct V_110 * V_94 ;
struct V_123 * V_124 ;
T_2 V_465 ;
T_2 V_466 ;
T_2 V_467 ;
long V_468 ;
unsigned long V_455 ;
int V_345 ;
enum V_447 V_448 ;
V_467 = F_356 ( V_36 , V_461 ) ;
V_461 = V_467 * V_469 ;
V_124 = (struct V_123 * ) V_417 -> V_418 ;
V_464 = & V_36 -> V_470 ;
V_94 = V_464 -> V_94 ;
V_465 = F_358 (
& V_36 -> V_465 ) ;
if ( V_465 == 0 ) {
if ( V_124 )
return;
if ( V_463 )
F_326 ( V_36 , V_467 , 0 , ( T_2 ) - 1 ) ;
return;
}
V_345 = 0 ;
while ( V_465 && V_345 < 3 ) {
V_466 = F_359 ( V_465 , V_461 ) ;
V_455 = V_466 >> V_471 ;
F_353 ( V_36 , V_455 , V_467 ) ;
V_466 = F_220 ( & V_36 -> V_472 ) ;
if ( ! V_466 )
goto V_473;
if ( V_466 <= V_455 )
V_466 = 0 ;
else
V_466 -= V_455 ;
F_288 ( V_36 -> V_474 ,
F_220 ( & V_36 -> V_472 ) <=
( int ) V_466 ) ;
V_473:
if ( ! V_124 )
V_448 = V_454 ;
else
V_448 = V_440 ;
F_12 ( & V_94 -> V_50 ) ;
if ( F_191 ( & V_94 -> V_365 ) &&
F_191 ( & V_94 -> V_366 ) ) {
F_14 ( & V_94 -> V_50 ) ;
break;
}
F_14 ( & V_94 -> V_50 ) ;
V_345 ++ ;
if ( V_463 && ! V_124 ) {
F_326 ( V_36 , V_467 , 0 , ( T_2 ) - 1 ) ;
} else {
V_468 = F_360 ( 1 ) ;
if ( V_468 )
break;
}
V_465 = F_358 (
& V_36 -> V_465 ) ;
}
}
static int F_361 ( struct V_14 * V_36 ,
struct V_110 * V_94 ,
T_2 V_223 , int V_429 )
{
struct V_276 * V_475 = & V_36 -> V_476 ;
struct V_123 * V_124 ;
V_124 = (struct V_123 * ) V_417 -> V_418 ;
if ( V_124 )
return - V_199 ;
if ( V_429 )
goto V_477;
if ( F_324 ( & V_94 -> V_121 ,
V_223 ) >= 0 )
goto V_477;
if ( V_94 != V_475 -> V_94 )
return - V_334 ;
F_12 ( & V_475 -> V_50 ) ;
if ( F_324 ( & V_94 -> V_121 ,
V_223 - V_475 -> V_59 ) < 0 ) {
F_14 ( & V_475 -> V_50 ) ;
return - V_334 ;
}
F_14 ( & V_475 -> V_50 ) ;
V_477:
V_124 = F_224 ( V_36 -> V_64 ) ;
if ( F_225 ( V_124 ) )
return - V_334 ;
return F_327 ( V_124 ) ;
}
static void F_362 ( struct V_14 * V_36 ,
struct V_110 * V_94 , T_2 V_37 ,
int V_311 )
{
struct V_63 * V_12 = V_36 -> V_64 ;
struct V_123 * V_124 ;
int V_43 ;
int V_31 = 0 ;
switch ( V_311 ) {
case V_478 :
case V_479 :
if ( V_311 == V_478 )
V_43 = F_356 ( V_36 , V_37 ) * 2 ;
else
V_43 = - 1 ;
V_124 = F_224 ( V_12 ) ;
if ( F_225 ( V_124 ) ) {
V_31 = F_226 ( V_124 ) ;
break;
}
V_31 = F_363 ( V_124 , V_36 , V_43 ) ;
F_228 ( V_124 ) ;
break;
case V_480 :
case V_481 :
F_357 ( V_36 , V_37 * 2 , V_37 ,
V_311 == V_481 ) ;
break;
case V_482 :
V_124 = F_224 ( V_12 ) ;
if ( F_225 ( V_124 ) ) {
V_31 = F_226 ( V_124 ) ;
break;
}
V_31 = F_323 ( V_124 , V_36 ,
F_318 ( V_36 ) ,
V_363 ) ;
F_228 ( V_124 ) ;
if ( V_31 > 0 || V_31 == - V_334 )
V_31 = 0 ;
break;
case V_483 :
V_31 = F_361 ( V_36 , V_94 ,
V_37 , 0 ) ;
break;
default:
V_31 = - V_334 ;
break;
}
F_364 ( V_36 , V_94 -> V_7 , V_37 , V_311 ,
V_31 ) ;
return;
}
static inline T_2
F_365 ( struct V_14 * V_36 ,
struct V_110 * V_94 ,
bool V_449 )
{
struct V_484 * V_485 ;
T_2 V_414 ;
T_2 V_486 ;
T_2 V_461 = 0 ;
F_242 (ticket, &space_info->tickets, list)
V_461 += V_485 -> V_223 ;
F_242 (ticket, &space_info->priority_tickets, list)
V_461 += V_485 -> V_223 ;
if ( V_461 )
return V_461 ;
V_461 = F_25 ( T_2 , F_366 () * V_324 , V_487 ) ;
if ( F_351 ( V_36 , V_94 , V_461 ,
V_454 , V_449 ) )
return 0 ;
V_414 = F_320 ( V_94 , true ) ;
if ( F_351 ( V_36 , V_94 , V_324 ,
V_454 , V_449 ) )
V_486 = F_339 ( V_94 -> V_371 , 95 ) ;
else
V_486 = F_339 ( V_94 -> V_371 , 90 ) ;
if ( V_414 > V_486 )
V_461 = V_414 - V_486 ;
else
V_461 = 0 ;
V_461 = F_359 ( V_461 , V_94 -> V_412 +
V_94 -> V_410 ) ;
return V_461 ;
}
static inline int F_367 ( struct V_14 * V_36 ,
struct V_110 * V_94 ,
T_2 V_414 , bool V_449 )
{
T_2 V_430 = F_339 ( V_94 -> V_371 , 98 ) ;
if ( ( V_94 -> V_93 + V_94 -> V_410 ) >= V_430 )
return 0 ;
if ( ! F_365 ( V_36 , V_94 ,
V_449 ) )
return 0 ;
return ( V_414 >= V_430 && ! F_43 ( V_36 ) &&
! F_234 ( V_488 , & V_36 -> V_489 ) ) ;
}
static void F_368 ( struct V_111 * V_112 )
{
struct V_484 * V_485 ;
while ( ! F_191 ( V_112 ) ) {
V_485 = F_192 ( V_112 , struct V_484 , V_98 ) ;
F_283 ( & V_485 -> V_98 ) ;
V_485 -> error = - V_334 ;
F_55 ( & V_485 -> V_89 ) ;
}
}
static void F_369 ( struct V_490 * V_91 )
{
struct V_14 * V_36 ;
struct V_110 * V_94 ;
T_2 V_461 ;
int V_491 ;
int V_492 = 0 ;
T_2 V_493 ;
V_36 = F_58 ( V_91 , struct V_14 , V_494 ) ;
V_94 = F_80 ( V_36 , V_53 ) ;
F_12 ( & V_94 -> V_50 ) ;
V_461 = F_365 ( V_36 , V_94 ,
false ) ;
if ( ! V_461 ) {
V_94 -> V_448 = 0 ;
F_14 ( & V_94 -> V_50 ) ;
return;
}
V_493 = V_94 -> V_495 ;
F_14 ( & V_94 -> V_50 ) ;
V_491 = V_478 ;
do {
F_362 ( V_36 , V_94 , V_461 , V_491 ) ;
F_12 ( & V_94 -> V_50 ) ;
if ( F_191 ( & V_94 -> V_365 ) ) {
V_94 -> V_448 = 0 ;
F_14 ( & V_94 -> V_50 ) ;
return;
}
V_461 = F_365 ( V_36 ,
V_94 ,
false ) ;
if ( V_493 == V_94 -> V_495 ) {
V_491 ++ ;
} else {
V_493 = V_94 -> V_495 ;
V_491 = V_478 ;
if ( V_492 )
V_492 -- ;
}
if ( V_491 > V_483 ) {
V_492 ++ ;
if ( V_492 > 2 ) {
F_368 ( & V_94 -> V_365 ) ;
V_94 -> V_448 = 0 ;
} else {
V_491 = V_478 ;
}
}
F_14 ( & V_94 -> V_50 ) ;
} while ( V_491 <= V_483 );
}
void F_370 ( struct V_490 * V_91 )
{
F_371 ( V_91 , F_369 ) ;
}
static void F_372 ( struct V_14 * V_36 ,
struct V_110 * V_94 ,
struct V_484 * V_485 )
{
T_2 V_461 ;
int V_491 = V_478 ;
F_12 ( & V_94 -> V_50 ) ;
V_461 = F_365 ( V_36 , V_94 ,
false ) ;
if ( ! V_461 ) {
F_14 ( & V_94 -> V_50 ) ;
return;
}
F_14 ( & V_94 -> V_50 ) ;
do {
F_362 ( V_36 , V_94 , V_461 , V_491 ) ;
V_491 ++ ;
F_12 ( & V_94 -> V_50 ) ;
if ( V_485 -> V_223 == 0 ) {
F_14 ( & V_94 -> V_50 ) ;
return;
}
F_14 ( & V_94 -> V_50 ) ;
if ( V_491 == V_480 ||
V_491 == V_481 )
V_491 = V_482 ;
} while ( V_491 < V_483 );
}
static int F_373 ( struct V_14 * V_36 ,
struct V_110 * V_94 ,
struct V_484 * V_485 , T_2 V_496 )
{
F_63 ( V_89 ) ;
int V_31 = 0 ;
F_12 ( & V_94 -> V_50 ) ;
while ( V_485 -> V_223 > 0 && V_485 -> error == 0 ) {
V_31 = F_374 ( & V_485 -> V_89 , & V_89 , V_497 ) ;
if ( V_31 ) {
V_31 = - V_498 ;
break;
}
F_14 ( & V_94 -> V_50 ) ;
F_71 () ;
F_72 ( & V_485 -> V_89 , & V_89 ) ;
F_12 ( & V_94 -> V_50 ) ;
}
if ( ! V_31 )
V_31 = V_485 -> error ;
if ( ! F_191 ( & V_485 -> V_98 ) )
F_283 ( & V_485 -> V_98 ) ;
if ( V_485 -> V_223 && V_485 -> V_223 < V_496 ) {
T_2 V_37 = V_496 - V_485 -> V_223 ;
V_94 -> V_412 -= V_37 ;
F_328 ( V_36 , L_12 ,
V_94 -> V_7 , V_37 , 0 ) ;
}
F_14 ( & V_94 -> V_50 ) ;
return V_31 ;
}
static int F_375 ( struct V_14 * V_36 ,
struct V_110 * V_94 ,
T_2 V_496 ,
enum V_447 V_448 ,
bool V_449 )
{
struct V_484 V_485 ;
T_2 V_414 ;
int V_31 = 0 ;
ASSERT ( V_496 ) ;
ASSERT ( ! V_417 -> V_418 || V_448 != V_454 ) ;
F_12 ( & V_94 -> V_50 ) ;
V_31 = - V_334 ;
V_414 = F_320 ( V_94 , true ) ;
if ( V_414 + V_496 <= V_94 -> V_371 ) {
V_94 -> V_412 += V_496 ;
F_328 ( V_36 , L_12 ,
V_94 -> V_7 , V_496 , 1 ) ;
V_31 = 0 ;
} else if ( F_351 ( V_36 , V_94 , V_496 , V_448 ,
V_449 ) ) {
V_94 -> V_412 += V_496 ;
F_328 ( V_36 , L_12 ,
V_94 -> V_7 , V_496 , 1 ) ;
V_31 = 0 ;
}
if ( V_31 && V_448 != V_440 ) {
V_485 . V_223 = V_496 ;
V_485 . error = 0 ;
F_67 ( & V_485 . V_89 ) ;
if ( V_448 == V_454 ) {
F_75 ( & V_485 . V_98 , & V_94 -> V_365 ) ;
if ( ! V_94 -> V_448 ) {
V_94 -> V_448 = 1 ;
F_376 ( V_36 ,
V_94 -> V_7 ,
V_496 , V_448 ,
L_14 ) ;
F_377 ( V_499 ,
& V_36 -> V_494 ) ;
}
} else {
F_75 ( & V_485 . V_98 ,
& V_94 -> V_366 ) ;
}
} else if ( ! V_31 && V_94 -> V_7 & V_53 ) {
V_414 += V_496 ;
if ( ! F_234 ( V_500 , & V_36 -> V_7 ) &&
F_367 ( V_36 , V_94 ,
V_414 , V_449 ) &&
! F_378 ( & V_36 -> V_494 ) ) {
F_376 ( V_36 , V_94 -> V_7 ,
V_496 , V_448 , L_15 ) ;
F_377 ( V_499 ,
& V_36 -> V_494 ) ;
}
}
F_14 ( & V_94 -> V_50 ) ;
if ( ! V_31 || V_448 == V_440 )
return V_31 ;
if ( V_448 == V_454 )
return F_373 ( V_36 , V_94 , & V_485 ,
V_496 ) ;
V_31 = 0 ;
F_372 ( V_36 , V_94 , & V_485 ) ;
F_12 ( & V_94 -> V_50 ) ;
if ( V_485 . V_223 ) {
if ( V_485 . V_223 < V_496 ) {
T_2 V_37 = V_496 - V_485 . V_223 ;
V_94 -> V_412 -= V_37 ;
F_328 ( V_36 , L_12 ,
V_94 -> V_7 ,
V_37 , 0 ) ;
}
F_283 ( & V_485 . V_98 ) ;
V_31 = - V_334 ;
}
F_14 ( & V_94 -> V_50 ) ;
ASSERT ( F_191 ( & V_485 . V_98 ) ) ;
return V_31 ;
}
static int F_379 ( struct V_63 * V_12 ,
struct V_276 * V_464 ,
T_2 V_496 ,
enum V_447 V_448 )
{
struct V_14 * V_36 = V_12 -> V_36 ;
struct V_276 * V_277 = & V_36 -> V_280 ;
int V_31 ;
bool V_449 = ( V_12 == V_36 -> V_407 ) ;
V_31 = F_375 ( V_36 , V_464 -> V_94 ,
V_496 , V_448 , V_449 ) ;
if ( V_31 == - V_334 &&
F_380 ( V_12 -> V_501 == V_502 ) ) {
if ( V_464 != V_277 &&
! F_381 ( V_277 , V_496 ) )
V_31 = 0 ;
}
if ( V_31 == - V_334 )
F_328 ( V_36 , L_11 ,
V_464 -> V_94 -> V_7 ,
V_496 , 1 ) ;
return V_31 ;
}
static struct V_276 * F_382 (
const struct V_123 * V_124 ,
const struct V_63 * V_12 )
{
struct V_14 * V_36 = V_12 -> V_36 ;
struct V_276 * V_464 = NULL ;
if ( F_234 ( V_310 , & V_12 -> V_311 ) ||
( V_12 == V_36 -> V_503 && V_124 -> V_504 ) ||
( V_12 == V_36 -> V_505 ) )
V_464 = V_124 -> V_464 ;
if ( ! V_464 )
V_464 = V_12 -> V_464 ;
if ( ! V_464 )
V_464 = & V_36 -> V_506 ;
return V_464 ;
}
static int F_381 ( struct V_276 * V_464 ,
T_2 V_37 )
{
int V_31 = - V_334 ;
F_12 ( & V_464 -> V_50 ) ;
if ( V_464 -> V_10 >= V_37 ) {
V_464 -> V_10 -= V_37 ;
if ( V_464 -> V_10 < V_464 -> V_59 )
V_464 -> V_122 = 0 ;
V_31 = 0 ;
}
F_14 ( & V_464 -> V_50 ) ;
return V_31 ;
}
static void F_383 ( struct V_276 * V_464 ,
T_2 V_37 , int V_507 )
{
F_12 ( & V_464 -> V_50 ) ;
V_464 -> V_10 += V_37 ;
if ( V_507 )
V_464 -> V_59 += V_37 ;
else if ( V_464 -> V_10 >= V_464 -> V_59 )
V_464 -> V_122 = 1 ;
F_14 ( & V_464 -> V_50 ) ;
}
int F_384 ( struct V_14 * V_36 ,
struct V_276 * V_508 , T_2 V_37 ,
int V_509 )
{
struct V_276 * V_277 = & V_36 -> V_280 ;
T_2 V_510 ;
if ( V_277 -> V_94 != V_508 -> V_94 )
return - V_334 ;
F_12 ( & V_277 -> V_50 ) ;
V_510 = F_340 ( V_277 -> V_59 , V_509 ) ;
if ( V_277 -> V_10 < V_510 + V_37 ) {
F_14 ( & V_277 -> V_50 ) ;
return - V_334 ;
}
V_277 -> V_10 -= V_37 ;
if ( V_277 -> V_10 < V_277 -> V_59 )
V_277 -> V_122 = 0 ;
F_14 ( & V_277 -> V_50 ) ;
F_383 ( V_508 , V_37 , 1 ) ;
return 0 ;
}
static void F_385 ( struct V_14 * V_36 ,
struct V_110 * V_94 ,
T_2 V_37 )
{
struct V_484 * V_485 ;
struct V_111 * V_112 ;
T_2 V_414 ;
enum V_447 V_448 = V_440 ;
bool V_511 = false ;
F_12 ( & V_94 -> V_50 ) ;
V_112 = & V_94 -> V_366 ;
V_414 = F_320 ( V_94 , true ) ;
if ( V_414 - V_37 >= V_94 -> V_371 )
V_511 = true ;
V_178:
while ( ! F_191 ( V_112 ) && V_37 ) {
V_485 = F_192 ( V_112 , struct V_484 ,
V_98 ) ;
if ( V_511 &&
! F_351 ( V_36 , V_94 , 0 , V_448 , false ) )
break;
if ( V_37 >= V_485 -> V_223 ) {
F_283 ( & V_485 -> V_98 ) ;
V_37 -= V_485 -> V_223 ;
V_485 -> V_223 = 0 ;
V_94 -> V_495 ++ ;
F_55 ( & V_485 -> V_89 ) ;
} else {
V_485 -> V_223 -= V_37 ;
V_37 = 0 ;
}
}
if ( V_37 && V_112 == & V_94 -> V_366 ) {
V_112 = & V_94 -> V_365 ;
V_448 = V_454 ;
goto V_178;
}
V_94 -> V_412 -= V_37 ;
F_328 ( V_36 , L_12 ,
V_94 -> V_7 , V_37 , 0 ) ;
F_14 ( & V_94 -> V_50 ) ;
}
static void F_305 ( struct V_14 * V_36 ,
struct V_110 * V_94 ,
T_2 V_37 )
{
struct V_484 * V_485 ;
struct V_111 * V_112 = & V_94 -> V_366 ;
V_178:
while ( ! F_191 ( V_112 ) && V_37 ) {
V_485 = F_192 ( V_112 , struct V_484 ,
V_98 ) ;
if ( V_37 >= V_485 -> V_223 ) {
F_328 ( V_36 , L_12 ,
V_94 -> V_7 ,
V_485 -> V_223 , 1 ) ;
F_283 ( & V_485 -> V_98 ) ;
V_37 -= V_485 -> V_223 ;
V_94 -> V_412 += V_485 -> V_223 ;
V_485 -> V_223 = 0 ;
V_94 -> V_495 ++ ;
F_55 ( & V_485 -> V_89 ) ;
} else {
F_328 ( V_36 , L_12 ,
V_94 -> V_7 ,
V_37 , 1 ) ;
V_94 -> V_412 += V_37 ;
V_485 -> V_223 -= V_37 ;
V_37 = 0 ;
}
}
if ( V_37 && V_112 == & V_94 -> V_366 ) {
V_112 = & V_94 -> V_365 ;
goto V_178;
}
}
static void F_386 ( struct V_14 * V_36 ,
struct V_276 * V_464 ,
struct V_276 * V_508 , T_2 V_37 )
{
struct V_110 * V_94 = V_464 -> V_94 ;
F_12 ( & V_464 -> V_50 ) ;
if ( V_37 == ( T_2 ) - 1 )
V_37 = V_464 -> V_59 ;
V_464 -> V_59 -= V_37 ;
if ( V_464 -> V_10 >= V_464 -> V_59 ) {
V_37 = V_464 -> V_10 - V_464 -> V_59 ;
V_464 -> V_10 = V_464 -> V_59 ;
V_464 -> V_122 = 1 ;
} else {
V_37 = 0 ;
}
F_14 ( & V_464 -> V_50 ) ;
if ( V_37 > 0 ) {
if ( V_508 ) {
F_12 ( & V_508 -> V_50 ) ;
if ( ! V_508 -> V_122 ) {
T_2 V_512 ;
V_512 = V_508 -> V_59 - V_508 -> V_10 ;
V_512 = F_359 ( V_37 , V_512 ) ;
V_508 -> V_10 += V_512 ;
if ( V_508 -> V_10 >= V_508 -> V_59 )
V_508 -> V_122 = 1 ;
V_37 -= V_512 ;
}
F_14 ( & V_508 -> V_50 ) ;
}
if ( V_37 )
F_385 ( V_36 , V_94 ,
V_37 ) ;
}
}
int F_387 ( struct V_276 * V_513 ,
struct V_276 * V_514 , T_2 V_37 ,
int V_507 )
{
int V_31 ;
V_31 = F_381 ( V_513 , V_37 ) ;
if ( V_31 )
return V_31 ;
F_383 ( V_514 , V_37 , V_507 ) ;
return 0 ;
}
void F_388 ( struct V_276 * V_515 , unsigned short type )
{
memset ( V_515 , 0 , sizeof( * V_515 ) ) ;
F_300 ( & V_515 -> V_50 ) ;
V_515 -> type = type ;
}
struct V_276 * F_389 ( struct V_14 * V_36 ,
unsigned short type )
{
struct V_276 * V_464 ;
V_464 = F_231 ( sizeof( * V_464 ) , V_97 ) ;
if ( ! V_464 )
return NULL ;
F_388 ( V_464 , type ) ;
V_464 -> V_94 = F_80 ( V_36 ,
V_53 ) ;
return V_464 ;
}
void F_390 ( struct V_14 * V_36 ,
struct V_276 * V_515 )
{
if ( ! V_515 )
return;
F_391 ( V_36 , V_515 , ( T_2 ) - 1 ) ;
F_10 ( V_515 ) ;
}
void F_392 ( struct V_276 * V_515 )
{
F_10 ( V_515 ) ;
}
int F_348 ( struct V_63 * V_12 ,
struct V_276 * V_464 , T_2 V_37 ,
enum V_447 V_448 )
{
int V_31 ;
if ( V_37 == 0 )
return 0 ;
V_31 = F_379 ( V_12 , V_464 , V_37 , V_448 ) ;
if ( ! V_31 ) {
F_383 ( V_464 , V_37 , 1 ) ;
return 0 ;
}
return V_31 ;
}
int F_393 ( struct V_276 * V_464 , int V_509 )
{
T_2 V_37 = 0 ;
int V_31 = - V_334 ;
if ( ! V_464 )
return 0 ;
F_12 ( & V_464 -> V_50 ) ;
V_37 = F_340 ( V_464 -> V_59 , V_509 ) ;
if ( V_464 -> V_10 >= V_37 )
V_31 = 0 ;
F_14 ( & V_464 -> V_50 ) ;
return V_31 ;
}
int F_394 ( struct V_63 * V_12 ,
struct V_276 * V_464 , T_2 V_516 ,
enum V_447 V_448 )
{
T_2 V_37 = 0 ;
int V_31 = - V_334 ;
if ( ! V_464 )
return 0 ;
F_12 ( & V_464 -> V_50 ) ;
V_37 = V_516 ;
if ( V_464 -> V_10 >= V_37 )
V_31 = 0 ;
else
V_37 -= V_464 -> V_10 ;
F_14 ( & V_464 -> V_50 ) ;
if ( ! V_31 )
return 0 ;
V_31 = F_379 ( V_12 , V_464 , V_37 , V_448 ) ;
if ( ! V_31 ) {
F_383 ( V_464 , V_37 , 0 ) ;
return 0 ;
}
return V_31 ;
}
void F_391 ( struct V_14 * V_36 ,
struct V_276 * V_464 ,
T_2 V_37 )
{
struct V_276 * V_277 = & V_36 -> V_280 ;
if ( V_277 == V_464 ||
V_464 -> V_94 != V_277 -> V_94 )
V_277 = NULL ;
F_386 ( V_36 , V_464 , V_277 , V_37 ) ;
}
static void F_395 ( struct V_14 * V_36 )
{
struct V_276 * V_464 = & V_36 -> V_280 ;
struct V_110 * V_428 = V_464 -> V_94 ;
T_2 V_37 ;
V_37 = F_396 ( & V_36 -> V_64 -> V_302 ) +
F_396 ( & V_36 -> V_503 -> V_302 ) +
F_396 ( & V_36 -> V_289 -> V_302 ) ;
V_37 = F_38 ( T_2 , V_37 , V_487 ) ;
F_12 ( & V_428 -> V_50 ) ;
F_12 ( & V_464 -> V_50 ) ;
V_464 -> V_59 = F_25 ( T_2 , V_37 , V_517 ) ;
if ( V_464 -> V_10 < V_464 -> V_59 ) {
V_37 = F_320 ( V_428 , true ) ;
if ( V_428 -> V_371 > V_37 ) {
V_37 = V_428 -> V_371 - V_37 ;
V_37 = F_359 ( V_37 ,
V_464 -> V_59 - V_464 -> V_10 ) ;
V_464 -> V_10 += V_37 ;
V_428 -> V_412 += V_37 ;
F_328 ( V_36 , L_12 ,
V_428 -> V_7 , V_37 ,
1 ) ;
}
} else if ( V_464 -> V_10 > V_464 -> V_59 ) {
V_37 = V_464 -> V_10 - V_464 -> V_59 ;
V_428 -> V_412 -= V_37 ;
F_328 ( V_36 , L_12 ,
V_428 -> V_7 , V_37 , 0 ) ;
V_464 -> V_10 = V_464 -> V_59 ;
}
if ( V_464 -> V_10 == V_464 -> V_59 )
V_464 -> V_122 = 1 ;
else
V_464 -> V_122 = 0 ;
F_14 ( & V_464 -> V_50 ) ;
F_14 ( & V_428 -> V_50 ) ;
}
static void F_397 ( struct V_14 * V_36 )
{
struct V_110 * V_94 ;
V_94 = F_80 ( V_36 , V_119 ) ;
V_36 -> V_439 . V_94 = V_94 ;
V_94 = F_80 ( V_36 , V_53 ) ;
V_36 -> V_280 . V_94 = V_94 ;
V_36 -> V_470 . V_94 = V_94 ;
V_36 -> V_518 . V_94 = V_94 ;
V_36 -> V_506 . V_94 = V_94 ;
V_36 -> V_476 . V_94 = V_94 ;
V_36 -> V_64 -> V_464 = & V_36 -> V_280 ;
V_36 -> V_503 -> V_464 = & V_36 -> V_280 ;
V_36 -> V_519 -> V_464 = & V_36 -> V_280 ;
V_36 -> V_289 -> V_464 = & V_36 -> V_280 ;
if ( V_36 -> V_520 )
V_36 -> V_520 -> V_464 = & V_36 -> V_280 ;
V_36 -> V_407 -> V_464 = & V_36 -> V_439 ;
F_395 ( V_36 ) ;
}
static void F_398 ( struct V_14 * V_36 )
{
F_386 ( V_36 , & V_36 -> V_280 , NULL ,
( T_2 ) - 1 ) ;
F_8 ( V_36 -> V_470 . V_59 > 0 ) ;
F_8 ( V_36 -> V_470 . V_10 > 0 ) ;
F_8 ( V_36 -> V_518 . V_59 > 0 ) ;
F_8 ( V_36 -> V_518 . V_10 > 0 ) ;
F_8 ( V_36 -> V_439 . V_59 > 0 ) ;
F_8 ( V_36 -> V_439 . V_10 > 0 ) ;
F_8 ( V_36 -> V_476 . V_59 > 0 ) ;
F_8 ( V_36 -> V_476 . V_10 > 0 ) ;
}
void F_399 ( struct V_123 * V_124 ,
struct V_14 * V_36 )
{
if ( ! V_124 -> V_464 )
return;
if ( ! V_124 -> V_410 )
return;
F_328 ( V_36 , L_16 ,
V_124 -> V_288 , V_124 -> V_410 , 0 ) ;
F_391 ( V_36 , V_124 -> V_464 ,
V_124 -> V_410 ) ;
V_124 -> V_410 = 0 ;
}
void F_350 ( struct V_123 * V_124 )
{
struct V_14 * V_36 = V_124 -> V_36 ;
if ( ! V_124 -> V_441 )
return;
F_400 ( ! F_191 ( & V_124 -> V_296 ) ) ;
F_386 ( V_36 , & V_36 -> V_439 , NULL ,
V_124 -> V_441 ) ;
V_124 -> V_441 = 0 ;
}
int F_401 ( struct V_123 * V_124 ,
struct V_413 * V_316 )
{
struct V_14 * V_36 = F_329 ( V_316 -> V_521 . V_426 ) ;
struct V_63 * V_12 = V_316 -> V_12 ;
struct V_276 * V_522 = V_124 -> V_464 ;
struct V_276 * V_523 = V_12 -> V_524 ;
T_2 V_37 = F_218 ( V_36 , 1 ) ;
F_328 ( V_36 , L_17 , F_402 ( V_316 ) ,
V_37 , 1 ) ;
return F_387 ( V_522 , V_523 , V_37 , 1 ) ;
}
void F_403 ( struct V_413 * V_316 )
{
struct V_14 * V_36 = F_329 ( V_316 -> V_521 . V_426 ) ;
struct V_63 * V_12 = V_316 -> V_12 ;
T_2 V_37 = F_218 ( V_36 , 1 ) ;
F_328 ( V_36 , L_17 , F_402 ( V_316 ) ,
V_37 , 0 ) ;
F_391 ( V_36 , V_12 -> V_524 , V_37 ) ;
}
int F_404 ( struct V_63 * V_12 ,
struct V_276 * V_515 ,
int V_467 ,
T_2 * V_245 ,
bool V_525 )
{
T_2 V_37 ;
int V_31 ;
struct V_14 * V_36 = V_12 -> V_36 ;
struct V_276 * V_277 = & V_36 -> V_280 ;
if ( F_234 ( V_526 , & V_36 -> V_7 ) ) {
V_37 = 3 * V_36 -> V_54 ;
V_31 = F_405 ( V_12 , V_37 , true ) ;
if ( V_31 )
return V_31 ;
} else {
V_37 = 0 ;
}
* V_245 = V_37 ;
V_37 = F_218 ( V_36 , V_467 ) ;
V_515 -> V_94 = F_80 ( V_36 ,
V_53 ) ;
V_31 = F_348 ( V_12 , V_515 , V_37 ,
V_454 ) ;
if ( V_31 == - V_334 && V_525 )
V_31 = F_387 ( V_277 , V_515 , V_37 , 1 ) ;
if ( V_31 && * V_245 )
F_406 ( V_12 , * V_245 ) ;
return V_31 ;
}
void F_407 ( struct V_14 * V_36 ,
struct V_276 * V_515 )
{
F_391 ( V_36 , V_515 , ( T_2 ) - 1 ) ;
}
static unsigned F_408 ( struct V_413 * V_316 ,
T_2 V_37 )
{
unsigned V_527 = 0 ;
unsigned V_528 = 0 ;
unsigned V_529 ;
V_529 = F_409 ( V_37 ) ;
ASSERT ( V_529 ) ;
ASSERT ( V_316 -> V_530 >= V_529 ) ;
V_316 -> V_530 -= V_529 ;
if ( V_316 -> V_530 == 0 &&
F_410 ( V_531 ,
& V_316 -> V_532 ) )
V_527 = 1 ;
if ( V_316 -> V_530 >= V_316 -> V_533 )
return V_527 ;
V_528 = V_316 -> V_533 - V_316 -> V_530 ;
V_316 -> V_533 -= V_528 ;
return V_528 + V_527 ;
}
static T_2 F_411 ( struct V_413 * V_316 , T_2 V_37 ,
int V_534 )
{
struct V_14 * V_36 = F_329 ( V_316 -> V_521 . V_426 ) ;
T_2 V_535 , V_274 ;
if ( V_316 -> V_7 & V_536 && V_316 -> V_271 == 0 )
return 0 ;
V_535 = F_213 ( V_36 , V_316 -> V_271 ) ;
if ( V_534 )
V_316 -> V_271 += V_37 ;
else
V_316 -> V_271 -= V_37 ;
V_274 = F_213 ( V_36 , V_316 -> V_271 ) ;
if ( V_535 == V_274 )
return 0 ;
if ( V_534 )
return F_218 ( V_36 ,
V_274 - V_535 ) ;
return F_218 ( V_36 , V_535 - V_274 ) ;
}
int F_412 ( struct V_413 * V_316 , T_2 V_37 )
{
struct V_14 * V_36 = F_329 ( V_316 -> V_521 . V_426 ) ;
struct V_63 * V_12 = V_316 -> V_12 ;
struct V_276 * V_464 = & V_36 -> V_470 ;
T_2 V_537 = 0 ;
T_2 V_271 ;
unsigned V_538 ;
enum V_447 V_448 = V_454 ;
int V_31 = 0 ;
bool V_539 = true ;
T_2 V_540 = 0 ;
unsigned V_541 ;
bool V_542 = false ;
if ( F_322 ( V_316 ) ) {
V_448 = V_440 ;
V_539 = false ;
} else if ( V_417 -> V_418 ) {
V_448 = V_543 ;
}
if ( V_448 != V_440 &&
F_413 ( V_36 ) )
F_414 ( 1 ) ;
if ( V_539 )
F_52 ( & V_316 -> V_544 ) ;
V_37 = F_158 ( V_37 , V_36 -> V_55 ) ;
F_12 ( & V_316 -> V_50 ) ;
V_538 = F_409 ( V_37 ) ;
V_316 -> V_530 += V_538 ;
V_538 = 0 ;
if ( V_316 -> V_530 > V_316 -> V_533 )
V_538 += V_316 -> V_530 -
V_316 -> V_533 ;
V_537 = F_218 ( V_36 , V_538 + 1 ) ;
V_537 += F_411 ( V_316 , V_37 , 1 ) ;
V_271 = V_316 -> V_271 ;
F_14 ( & V_316 -> V_50 ) ;
if ( F_234 ( V_526 , & V_36 -> V_7 ) ) {
V_31 = F_405 ( V_12 ,
V_538 * V_36 -> V_54 , true ) ;
if ( V_31 )
goto V_545;
}
V_31 = F_348 ( V_12 , V_464 , V_537 , V_448 ) ;
if ( F_380 ( V_31 ) ) {
F_406 ( V_12 ,
V_538 * V_36 -> V_54 ) ;
goto V_545;
}
F_12 ( & V_316 -> V_50 ) ;
if ( F_415 ( V_531 ,
& V_316 -> V_532 ) ) {
V_537 -= F_218 ( V_36 , 1 ) ;
V_542 = true ;
}
V_316 -> V_533 += V_538 ;
F_14 ( & V_316 -> V_50 ) ;
if ( V_539 )
F_50 ( & V_316 -> V_544 ) ;
if ( V_537 )
F_328 ( V_36 , L_18 ,
F_402 ( V_316 ) , V_537 , 1 ) ;
if ( V_542 )
F_391 ( V_36 , V_464 ,
F_218 ( V_36 , 1 ) ) ;
return 0 ;
V_545:
F_12 ( & V_316 -> V_50 ) ;
V_541 = F_408 ( V_316 , V_37 ) ;
if ( V_316 -> V_271 == V_271 ) {
F_411 ( V_316 , V_37 , 0 ) ;
} else {
T_2 V_546 = V_316 -> V_271 ;
T_2 V_223 ;
V_223 = V_271 - V_316 -> V_271 ;
V_316 -> V_271 = V_271 ;
V_540 = F_411 ( V_316 , V_223 , 0 ) ;
V_316 -> V_271 = V_271 - V_37 ;
V_223 = V_271 - V_546 ;
V_223 = F_411 ( V_316 , V_223 , 0 ) ;
V_316 -> V_271 = V_546 - V_37 ;
if ( V_223 > V_540 )
V_540 = V_223 - V_540 ;
else
V_540 = 0 ;
}
F_14 ( & V_316 -> V_50 ) ;
if ( V_541 )
V_540 += F_218 ( V_36 , V_541 ) ;
if ( V_540 ) {
F_391 ( V_36 , V_464 , V_540 ) ;
F_328 ( V_36 , L_18 ,
F_402 ( V_316 ) , V_540 , 0 ) ;
}
if ( V_539 )
F_50 ( & V_316 -> V_544 ) ;
return V_31 ;
}
void F_416 ( struct V_413 * V_316 , T_2 V_37 )
{
struct V_14 * V_36 = F_329 ( V_316 -> V_521 . V_426 ) ;
T_2 V_540 = 0 ;
unsigned V_541 ;
V_37 = F_158 ( V_37 , V_36 -> V_55 ) ;
F_12 ( & V_316 -> V_50 ) ;
V_541 = F_408 ( V_316 , V_37 ) ;
if ( V_37 )
V_540 = F_411 ( V_316 , V_37 , 0 ) ;
F_14 ( & V_316 -> V_50 ) ;
if ( V_541 > 0 )
V_540 += F_218 ( V_36 , V_541 ) ;
if ( F_249 ( V_36 ) )
return;
F_328 ( V_36 , L_18 , F_402 ( V_316 ) ,
V_540 , 0 ) ;
F_391 ( V_36 , & V_36 -> V_470 , V_540 ) ;
}
int F_417 ( struct V_316 * V_316 ,
struct V_317 * * V_10 , T_2 V_34 , T_2 V_47 )
{
int V_31 ;
V_31 = F_273 ( V_316 , V_10 , V_34 , V_47 ) ;
if ( V_31 < 0 )
return V_31 ;
V_31 = F_412 ( F_268 ( V_316 ) , V_47 ) ;
if ( V_31 < 0 )
F_333 ( V_316 , * V_10 , V_34 , V_47 ) ;
return V_31 ;
}
void F_418 ( struct V_316 * V_316 ,
struct V_317 * V_10 , T_2 V_34 , T_2 V_47 )
{
F_416 ( F_268 ( V_316 ) , V_47 ) ;
F_333 ( V_316 , V_10 , V_34 , V_47 ) ;
}
static int F_419 ( struct V_123 * V_124 ,
struct V_14 * V_15 , T_2 V_29 ,
T_2 V_37 , int V_547 )
{
struct V_1 * V_2 = NULL ;
T_2 V_548 = V_37 ;
T_2 V_549 ;
T_2 V_550 ;
int V_373 ;
F_12 ( & V_15 -> V_551 ) ;
V_549 = F_420 ( V_15 -> V_275 ) ;
if ( V_547 )
V_549 += V_37 ;
else
V_549 -= V_37 ;
F_421 ( V_15 -> V_275 , V_549 ) ;
F_14 ( & V_15 -> V_551 ) ;
while ( V_548 ) {
V_2 = F_79 ( V_15 , V_29 ) ;
if ( ! V_2 )
return - V_177 ;
if ( V_2 -> V_7 & ( V_374 |
V_375 |
V_376 ) )
V_373 = 2 ;
else
V_373 = 1 ;
if ( ! V_547 && V_2 -> V_3 == V_102 )
F_62 ( V_2 , 1 ) ;
V_550 = V_29 - V_2 -> V_23 . V_24 ;
F_8 ( V_550 > V_2 -> V_23 . V_35 ) ;
F_12 ( & V_2 -> V_94 -> V_50 ) ;
F_12 ( & V_2 -> V_50 ) ;
if ( F_272 ( V_15 , V_332 ) &&
V_2 -> V_325 < V_339 )
V_2 -> V_325 = V_339 ;
V_549 = F_61 ( & V_2 -> V_95 ) ;
V_37 = F_359 ( V_548 , V_2 -> V_23 . V_35 - V_550 ) ;
if ( V_547 ) {
V_549 += V_37 ;
F_422 ( & V_2 -> V_95 , V_549 ) ;
V_2 -> V_10 -= V_37 ;
V_2 -> V_94 -> V_410 -= V_37 ;
V_2 -> V_94 -> V_93 += V_37 ;
V_2 -> V_94 -> V_378 += V_37 * V_373 ;
F_14 ( & V_2 -> V_50 ) ;
F_14 ( & V_2 -> V_94 -> V_50 ) ;
} else {
V_549 -= V_37 ;
F_422 ( & V_2 -> V_95 , V_549 ) ;
V_2 -> V_9 += V_37 ;
V_2 -> V_94 -> V_411 += V_37 ;
V_2 -> V_94 -> V_93 -= V_37 ;
V_2 -> V_94 -> V_378 -= V_37 * V_373 ;
F_14 ( & V_2 -> V_50 ) ;
F_14 ( & V_2 -> V_94 -> V_50 ) ;
F_328 ( V_15 , L_19 ,
V_2 -> V_94 -> V_7 ,
V_37 , 1 ) ;
F_85 ( & V_2 -> V_94 -> V_121 ,
V_37 ) ;
F_423 ( V_15 -> V_61 ,
V_29 , V_29 + V_37 - 1 ,
V_97 | V_552 ) ;
}
F_12 ( & V_124 -> V_141 -> V_346 ) ;
if ( F_191 ( & V_2 -> V_348 ) ) {
F_75 ( & V_2 -> V_348 ,
& V_124 -> V_141 -> V_338 ) ;
V_124 -> V_141 -> V_278 ++ ;
F_4 ( V_2 ) ;
}
F_14 ( & V_124 -> V_141 -> V_346 ) ;
if ( ! V_547 && V_549 == 0 ) {
F_12 ( & V_15 -> V_553 ) ;
if ( F_191 ( & V_2 -> V_554 ) ) {
F_4 ( V_2 ) ;
F_75 ( & V_2 -> V_554 ,
& V_15 -> V_555 ) ;
}
F_14 ( & V_15 -> V_553 ) ;
}
F_6 ( V_2 ) ;
V_548 -= V_37 ;
V_29 += V_37 ;
}
return 0 ;
}
static T_2 V_28 ( struct V_14 * V_36 , T_2 V_556 )
{
struct V_1 * V_2 ;
T_2 V_29 ;
F_12 ( & V_36 -> V_20 ) ;
V_29 = V_36 -> V_28 ;
F_14 ( & V_36 -> V_20 ) ;
if ( V_29 < ( T_2 ) - 1 )
return V_29 ;
V_2 = F_78 ( V_36 , V_556 ) ;
if ( ! V_2 )
return 0 ;
V_29 = V_2 -> V_23 . V_24 ;
F_6 ( V_2 ) ;
return V_29 ;
}
static int F_424 ( struct V_14 * V_36 ,
struct V_1 * V_2 ,
T_2 V_29 , T_2 V_37 , int V_10 )
{
F_12 ( & V_2 -> V_94 -> V_50 ) ;
F_12 ( & V_2 -> V_50 ) ;
V_2 -> V_9 += V_37 ;
V_2 -> V_94 -> V_411 += V_37 ;
if ( V_10 ) {
V_2 -> V_10 -= V_37 ;
V_2 -> V_94 -> V_410 -= V_37 ;
}
F_14 ( & V_2 -> V_50 ) ;
F_14 ( & V_2 -> V_94 -> V_50 ) ;
F_328 ( V_36 , L_19 ,
V_2 -> V_94 -> V_7 , V_37 , 1 ) ;
F_85 ( & V_2 -> V_94 -> V_121 , V_37 ) ;
F_423 ( V_36 -> V_61 , V_29 ,
V_29 + V_37 - 1 , V_97 | V_552 ) ;
return 0 ;
}
int F_184 ( struct V_14 * V_36 ,
T_2 V_29 , T_2 V_37 , int V_10 )
{
struct V_1 * V_2 ;
V_2 = F_79 ( V_36 , V_29 ) ;
F_35 ( ! V_2 ) ;
F_424 ( V_36 , V_2 , V_29 , V_37 , V_10 ) ;
F_6 ( V_2 ) ;
return 0 ;
}
int F_425 ( struct V_14 * V_36 ,
T_2 V_29 , T_2 V_37 )
{
struct V_1 * V_2 ;
int V_31 ;
V_2 = F_79 ( V_36 , V_29 ) ;
if ( ! V_2 )
return - V_196 ;
F_62 ( V_2 , 1 ) ;
F_424 ( V_36 , V_2 , V_29 , V_37 , 0 ) ;
V_31 = F_31 ( V_2 , V_29 , V_37 ) ;
F_6 ( V_2 ) ;
return V_31 ;
}
static int F_426 ( struct V_14 * V_36 ,
T_2 V_34 , T_2 V_37 )
{
int V_31 ;
struct V_1 * V_16 ;
struct V_48 * V_51 ;
V_16 = F_79 ( V_36 , V_34 ) ;
if ( ! V_16 )
return - V_196 ;
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
goto V_557;
V_37 = ( V_34 + V_37 ) -
V_51 -> V_85 ;
V_34 = V_51 -> V_85 ;
V_31 = F_18 ( V_36 , V_34 , V_37 ) ;
}
V_557:
F_50 ( & V_51 -> V_86 ) ;
F_28 ( V_51 ) ;
}
F_6 ( V_16 ) ;
return V_31 ;
}
int F_427 ( struct V_14 * V_36 ,
struct V_67 * V_157 )
{
struct V_308 * V_95 ;
struct V_69 V_23 ;
int V_558 ;
int V_42 ;
if ( ! F_89 ( V_36 , V_559 ) )
return 0 ;
for ( V_42 = 0 ; V_42 < F_42 ( V_157 ) ; V_42 ++ ) {
F_44 ( V_157 , & V_23 , V_42 ) ;
if ( V_23 . type != V_313 )
continue;
V_95 = F_91 ( V_157 , V_42 , struct V_308 ) ;
V_558 = F_252 ( V_157 , V_95 ) ;
if ( V_558 == V_314 )
continue;
if ( F_253 ( V_157 , V_95 ) == 0 )
continue;
V_23 . V_24 = F_253 ( V_157 , V_95 ) ;
V_23 . V_35 = F_254 ( V_157 , V_95 ) ;
F_426 ( V_36 , V_23 . V_24 , V_23 . V_35 ) ;
}
return 0 ;
}
static void
F_428 ( struct V_1 * V_354 )
{
F_5 ( & V_354 -> V_560 ) ;
}
void F_429 ( struct V_14 * V_36 ,
const T_2 V_34 )
{
struct V_1 * V_354 ;
V_354 = F_79 ( V_36 , V_34 ) ;
ASSERT ( V_354 ) ;
if ( F_7 ( & V_354 -> V_560 ) )
F_292 ( & V_354 -> V_560 ) ;
F_6 ( V_354 ) ;
}
static int F_430 ( T_8 * V_356 )
{
F_71 () ;
return 0 ;
}
void F_431 ( struct V_1 * V_354 )
{
struct V_110 * V_94 = V_354 -> V_94 ;
ASSERT ( V_354 -> V_327 ) ;
if ( ! ( V_354 -> V_7 & V_120 ) )
return;
F_74 ( & V_94 -> V_361 ) ;
F_76 ( & V_94 -> V_361 ) ;
F_295 ( & V_354 -> V_560 ,
F_430 ,
V_101 ) ;
}
static int F_432 ( struct V_1 * V_2 ,
T_2 V_561 , T_2 V_37 , int V_562 )
{
struct V_110 * V_94 = V_2 -> V_94 ;
int V_31 = 0 ;
F_12 ( & V_94 -> V_50 ) ;
F_12 ( & V_2 -> V_50 ) ;
if ( V_2 -> V_327 ) {
V_31 = - V_199 ;
} else {
V_2 -> V_10 += V_37 ;
V_94 -> V_410 += V_37 ;
F_328 ( V_2 -> V_36 ,
L_12 , V_94 -> V_7 ,
V_561 , 0 ) ;
V_94 -> V_412 -= V_561 ;
if ( V_562 )
V_2 -> V_465 += V_37 ;
}
F_14 ( & V_2 -> V_50 ) ;
F_14 ( & V_94 -> V_50 ) ;
return V_31 ;
}
static int F_433 ( struct V_1 * V_2 ,
T_2 V_37 , int V_562 )
{
struct V_110 * V_94 = V_2 -> V_94 ;
int V_31 = 0 ;
F_12 ( & V_94 -> V_50 ) ;
F_12 ( & V_2 -> V_50 ) ;
if ( V_2 -> V_327 )
V_94 -> V_372 += V_37 ;
V_2 -> V_10 -= V_37 ;
V_94 -> V_410 -= V_37 ;
if ( V_562 )
V_2 -> V_465 -= V_37 ;
F_14 ( & V_2 -> V_50 ) ;
F_14 ( & V_94 -> V_50 ) ;
return V_31 ;
}
void F_434 ( struct V_14 * V_36 )
{
struct V_48 * V_80 ;
struct V_48 * V_51 ;
struct V_1 * V_2 ;
F_74 ( & V_36 -> V_84 ) ;
F_279 (caching_ctl, next,
&fs_info->caching_block_groups, list) {
V_2 = V_51 -> V_16 ;
if ( F_1 ( V_2 ) ) {
V_2 -> V_105 = ( T_2 ) - 1 ;
F_283 ( & V_51 -> V_98 ) ;
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
F_395 ( V_36 ) ;
}
static struct V_563 *
F_435 ( struct V_14 * V_36 ,
struct V_110 * V_94 , T_2 * V_564 )
{
struct V_563 * V_31 = NULL ;
* V_564 = 0 ;
if ( F_349 ( V_94 ) )
return V_31 ;
if ( V_94 -> V_7 & V_53 ) {
V_31 = & V_36 -> V_565 ;
if ( F_272 ( V_36 , V_566 ) )
* V_564 = V_433 ;
else
* V_564 = V_567 ;
} else if ( ( V_94 -> V_7 & V_120 ) &&
F_272 ( V_36 , V_568 ) ) {
* V_564 = V_433 ;
V_31 = & V_36 -> V_569 ;
}
return V_31 ;
}
static int F_436 ( struct V_14 * V_36 ,
T_2 V_34 , T_2 V_33 ,
const bool V_570 )
{
struct V_1 * V_2 = NULL ;
struct V_110 * V_94 ;
struct V_276 * V_277 = & V_36 -> V_280 ;
struct V_563 * V_571 = NULL ;
T_2 V_47 ;
T_2 V_572 = 0 ;
T_2 V_564 = 0 ;
bool V_353 ;
while ( V_34 <= V_33 ) {
V_353 = false ;
if ( ! V_2 ||
V_34 >= V_2 -> V_23 . V_24 + V_2 -> V_23 . V_35 ) {
if ( V_2 )
F_6 ( V_2 ) ;
V_572 = 0 ;
V_2 = F_79 ( V_36 , V_34 ) ;
F_35 ( ! V_2 ) ;
V_571 = F_435 ( V_36 ,
V_2 -> V_94 ,
& V_564 ) ;
V_564 <<= 1 ;
}
V_47 = V_2 -> V_23 . V_24 + V_2 -> V_23 . V_35 - V_34 ;
V_47 = F_359 ( V_47 , V_33 + 1 - V_34 ) ;
if ( V_34 < V_2 -> V_105 ) {
V_47 = F_359 ( V_47 , V_2 -> V_105 - V_34 ) ;
if ( V_570 )
F_34 ( V_2 , V_34 , V_47 ) ;
}
V_34 += V_47 ;
V_572 += V_47 ;
V_94 = V_2 -> V_94 ;
if ( V_571 && V_571 -> V_573 &&
V_572 > V_564 ) {
F_12 ( & V_571 -> V_50 ) ;
V_571 -> V_573 = 0 ;
F_14 ( & V_571 -> V_50 ) ;
}
F_12 ( & V_94 -> V_50 ) ;
F_12 ( & V_2 -> V_50 ) ;
V_2 -> V_9 -= V_47 ;
V_94 -> V_411 -= V_47 ;
F_328 ( V_36 , L_19 ,
V_94 -> V_7 , V_47 , 0 ) ;
V_94 -> V_574 = 0 ;
F_85 ( & V_94 -> V_121 , - V_47 ) ;
if ( V_2 -> V_327 ) {
V_94 -> V_372 += V_47 ;
V_353 = true ;
}
F_14 ( & V_2 -> V_50 ) ;
if ( ! V_353 && V_570 &&
V_277 -> V_94 == V_94 ) {
T_2 V_575 = V_47 ;
F_12 ( & V_277 -> V_50 ) ;
if ( ! V_277 -> V_122 ) {
V_575 = F_359 ( V_47 , V_277 -> V_59 -
V_277 -> V_10 ) ;
V_277 -> V_10 += V_575 ;
V_94 -> V_412 += V_575 ;
if ( V_277 -> V_10 >= V_277 -> V_59 )
V_277 -> V_122 = 1 ;
F_328 ( V_36 ,
L_12 ,
V_94 -> V_7 ,
V_575 , 1 ) ;
V_47 -= V_575 ;
}
F_14 ( & V_277 -> V_50 ) ;
if ( V_47 )
F_305 ( V_36 , V_94 ,
V_47 ) ;
}
F_14 ( & V_94 -> V_50 ) ;
}
if ( V_2 )
F_6 ( V_2 ) ;
return 0 ;
}
int F_437 ( struct V_123 * V_124 ,
struct V_14 * V_36 )
{
struct V_1 * V_16 , * V_337 ;
struct V_111 * V_576 ;
struct V_577 * V_578 ;
T_2 V_34 ;
T_2 V_33 ;
int V_31 ;
if ( V_36 -> V_61 == & V_36 -> V_38 [ 0 ] )
V_578 = & V_36 -> V_38 [ 1 ] ;
else
V_578 = & V_36 -> V_38 [ 0 ] ;
while ( ! V_124 -> V_241 ) {
F_52 ( & V_36 -> V_579 ) ;
V_31 = F_33 ( V_578 , 0 , & V_34 , & V_33 ,
V_62 , NULL ) ;
if ( V_31 ) {
F_50 ( & V_36 -> V_579 ) ;
break;
}
if ( F_272 ( V_36 , V_580 ) )
V_31 = F_162 ( V_36 , V_34 ,
V_33 + 1 - V_34 , NULL ) ;
F_438 ( V_578 , V_34 , V_33 ) ;
F_436 ( V_36 , V_34 , V_33 , true ) ;
F_50 ( & V_36 -> V_579 ) ;
F_51 () ;
}
V_576 = & V_124 -> V_141 -> V_576 ;
F_279 (block_group, tmp, deleted_bgs, bg_list) {
T_2 V_581 = 0 ;
V_31 = - V_582 ;
if ( ! V_124 -> V_241 )
V_31 = F_162 ( V_36 ,
V_16 -> V_23 . V_24 ,
V_16 -> V_23 . V_35 ,
& V_581 ) ;
F_283 ( & V_16 -> V_554 ) ;
F_439 ( V_16 ) ;
F_6 ( V_16 ) ;
if ( V_31 ) {
const char * V_583 = F_440 ( V_31 ) ;
F_441 ( V_36 ,
L_20 ,
V_31 , V_583 ) ;
}
}
return 0 ;
}
static int F_176 ( struct V_123 * V_124 ,
struct V_14 * V_15 ,
struct V_232 * V_142 , T_2 V_19 ,
T_2 V_116 , T_2 V_584 ,
T_2 V_585 , int V_182 ,
struct V_201 * V_143 )
{
struct V_69 V_23 ;
struct V_65 * V_66 ;
struct V_63 * V_64 = V_15 -> V_64 ;
struct V_67 * V_68 ;
struct V_130 * V_131 ;
struct V_158 * V_159 ;
int V_31 ;
int V_161 ;
int V_586 = 0 ;
int V_587 = 0 ;
int V_588 = 1 ;
T_3 V_132 ;
T_2 V_126 ;
T_2 V_29 = V_142 -> V_29 ;
T_2 V_37 = V_142 -> V_37 ;
int V_183 = 0 ;
bool V_192 = F_89 ( V_15 , V_135 ) ;
V_66 = F_37 () ;
if ( ! V_66 )
return - V_74 ;
V_66 -> V_77 = V_78 ;
V_66 -> V_233 = 1 ;
V_161 = V_584 >= V_117 ;
F_35 ( ! V_161 && V_182 != 1 ) ;
if ( V_161 )
V_192 = 0 ;
V_31 = F_151 ( V_124 , V_15 , V_66 , & V_159 ,
V_29 , V_37 , V_19 ,
V_116 , V_584 ,
V_585 ) ;
if ( V_31 == 0 ) {
V_586 = V_66 -> V_83 [ 0 ] ;
while ( V_586 >= 0 ) {
F_44 ( V_66 -> V_82 [ 0 ] , & V_23 ,
V_586 ) ;
if ( V_23 . V_24 != V_29 )
break;
if ( V_23 . type == V_79 &&
V_23 . V_35 == V_37 ) {
V_587 = 1 ;
break;
}
if ( V_23 . type == V_87 &&
V_23 . V_35 == V_584 ) {
V_587 = 1 ;
break;
}
if ( V_66 -> V_83 [ 0 ] - V_586 > 5 )
break;
V_586 -- ;
}
#ifdef F_94
V_132 = F_90 ( V_66 -> V_82 [ 0 ] , V_586 ) ;
if ( V_587 && V_132 < sizeof( * V_131 ) )
V_587 = 0 ;
#endif
if ( ! V_587 ) {
F_35 ( V_159 ) ;
V_31 = F_156 ( V_124 , V_15 , V_66 , NULL ,
V_182 ,
V_161 , & V_183 ) ;
if ( V_31 ) {
F_171 ( V_124 , V_31 ) ;
goto V_81;
}
F_48 ( V_66 ) ;
V_66 -> V_233 = 1 ;
V_23 . V_24 = V_29 ;
V_23 . type = V_79 ;
V_23 . V_35 = V_37 ;
if ( ! V_161 && V_192 ) {
V_23 . type = V_87 ;
V_23 . V_35 = V_584 ;
}
V_31 = F_41 ( V_124 , V_64 ,
& V_23 , V_66 , - 1 , 1 ) ;
if ( V_31 > 0 && V_192 && V_66 -> V_83 [ 0 ] ) {
V_66 -> V_83 [ 0 ] -- ;
F_44 ( V_66 -> V_82 [ 0 ] , & V_23 ,
V_66 -> V_83 [ 0 ] ) ;
if ( V_23 . V_24 == V_29 &&
V_23 . type == V_79 &&
V_23 . V_35 == V_37 )
V_31 = 0 ;
}
if ( V_31 > 0 && V_192 ) {
V_192 = false ;
V_23 . V_24 = V_29 ;
V_23 . type = V_79 ;
V_23 . V_35 = V_37 ;
F_48 ( V_66 ) ;
V_31 = F_41 ( V_124 , V_64 ,
& V_23 , V_66 , - 1 , 1 ) ;
}
if ( V_31 ) {
F_114 ( V_15 ,
L_21 ,
V_31 , V_29 ) ;
if ( V_31 > 0 )
F_113 ( V_66 -> V_82 [ 0 ] ) ;
}
if ( V_31 < 0 ) {
F_171 ( V_124 , V_31 ) ;
goto V_81;
}
V_586 = V_66 -> V_83 [ 0 ] ;
}
} else if ( F_8 ( V_31 == - V_177 ) ) {
F_113 ( V_66 -> V_82 [ 0 ] ) ;
F_114 ( V_15 ,
L_22 ,
V_29 , V_19 , V_116 , V_584 ,
V_585 ) ;
F_171 ( V_124 , V_31 ) ;
goto V_81;
} else {
F_171 ( V_124 , V_31 ) ;
goto V_81;
}
V_68 = V_66 -> V_82 [ 0 ] ;
V_132 = F_90 ( V_68 , V_586 ) ;
#ifdef F_94
if ( V_132 < sizeof( * V_131 ) ) {
F_35 ( V_587 || V_586 != V_66 -> V_83 [ 0 ] ) ;
V_31 = F_100 ( V_124 , V_15 , V_66 , V_584 ,
0 ) ;
if ( V_31 < 0 ) {
F_171 ( V_124 , V_31 ) ;
goto V_81;
}
F_48 ( V_66 ) ;
V_66 -> V_233 = 1 ;
V_23 . V_24 = V_29 ;
V_23 . type = V_79 ;
V_23 . V_35 = V_37 ;
V_31 = F_41 ( V_124 , V_64 , & V_23 , V_66 ,
- 1 , 1 ) ;
if ( V_31 ) {
F_114 ( V_15 ,
L_21 ,
V_31 , V_29 ) ;
F_113 ( V_66 -> V_82 [ 0 ] ) ;
}
if ( V_31 < 0 ) {
F_171 ( V_124 , V_31 ) ;
goto V_81;
}
V_586 = V_66 -> V_83 [ 0 ] ;
V_68 = V_66 -> V_82 [ 0 ] ;
V_132 = F_90 ( V_68 , V_586 ) ;
}
#endif
F_35 ( V_132 < sizeof( * V_131 ) ) ;
V_131 = F_91 ( V_68 , V_586 ,
struct V_130 ) ;
if ( V_584 < V_117 &&
V_23 . type == V_79 ) {
struct V_150 * V_151 ;
F_35 ( V_132 < sizeof( * V_131 ) + sizeof( * V_151 ) ) ;
V_151 = (struct V_150 * ) ( V_131 + 1 ) ;
F_8 ( V_584 != F_442 ( V_68 , V_151 ) ) ;
}
V_126 = F_92 ( V_68 , V_131 ) ;
if ( V_126 < V_182 ) {
F_114 ( V_15 ,
L_23 ,
V_182 , V_126 , V_29 ) ;
V_31 = - V_196 ;
F_171 ( V_124 , V_31 ) ;
goto V_81;
}
V_126 -= V_182 ;
if ( V_126 > 0 ) {
if ( V_143 )
F_147 ( V_143 , V_68 , V_131 ) ;
if ( V_159 ) {
F_35 ( ! V_587 ) ;
} else {
F_103 ( V_68 , V_131 , V_126 ) ;
F_108 ( V_68 ) ;
}
if ( V_587 ) {
V_31 = F_156 ( V_124 , V_15 , V_66 ,
V_159 , V_182 ,
V_161 , & V_183 ) ;
if ( V_31 ) {
F_171 ( V_124 , V_31 ) ;
goto V_81;
}
}
} else {
if ( V_587 ) {
F_35 ( V_161 && V_182 !=
F_137 ( V_66 , V_159 ) ) ;
if ( V_159 ) {
F_35 ( V_66 -> V_83 [ 0 ] != V_586 ) ;
} else {
F_35 ( V_66 -> V_83 [ 0 ] != V_586 + 1 ) ;
V_66 -> V_83 [ 0 ] = V_586 ;
V_588 = 2 ;
}
}
V_183 = 1 ;
V_31 = F_443 ( V_124 , V_64 , V_66 , V_66 -> V_83 [ 0 ] ,
V_588 ) ;
if ( V_31 ) {
F_171 ( V_124 , V_31 ) ;
goto V_81;
}
F_48 ( V_66 ) ;
if ( V_161 ) {
V_31 = F_188 ( V_124 , V_15 , V_29 , V_37 ) ;
if ( V_31 ) {
F_171 ( V_124 , V_31 ) ;
goto V_81;
}
}
V_31 = F_444 ( V_124 , V_15 , V_29 , V_37 ) ;
if ( V_31 ) {
F_171 ( V_124 , V_31 ) ;
goto V_81;
}
V_31 = F_419 ( V_124 , V_15 , V_29 , V_37 , 0 ) ;
if ( V_31 ) {
F_171 ( V_124 , V_31 ) ;
goto V_81;
}
}
F_48 ( V_66 ) ;
V_81:
F_56 ( V_66 ) ;
return V_31 ;
}
static T_1 int F_445 ( struct V_123 * V_124 ,
T_2 V_29 )
{
struct V_127 * V_112 ;
struct V_128 * V_129 ;
int V_31 = 0 ;
V_129 = & V_124 -> V_141 -> V_129 ;
F_12 ( & V_129 -> V_50 ) ;
V_112 = F_97 ( V_129 , V_29 ) ;
if ( ! V_112 )
goto V_589;
F_12 ( & V_112 -> V_50 ) ;
if ( ! F_191 ( & V_112 -> V_246 ) )
goto V_81;
if ( V_112 -> V_143 ) {
if ( ! V_112 -> V_251 )
goto V_81;
F_200 ( V_112 -> V_143 ) ;
V_112 -> V_143 = NULL ;
}
if ( ! F_98 ( & V_112 -> V_86 ) )
goto V_81;
V_112 -> V_142 . V_255 = 0 ;
F_202 ( & V_112 -> V_257 , & V_129 -> V_258 ) ;
F_204 ( & V_129 -> V_259 ) ;
V_129 -> V_256 -- ;
if ( V_112 -> V_253 == 0 )
V_129 -> V_254 -- ;
V_112 -> V_253 = 0 ;
F_14 ( & V_112 -> V_50 ) ;
F_14 ( & V_129 -> V_50 ) ;
F_35 ( V_112 -> V_143 ) ;
if ( V_112 -> V_251 )
V_31 = 1 ;
F_50 ( & V_112 -> V_86 ) ;
F_99 ( & V_112 -> V_142 ) ;
return V_31 ;
V_81:
F_14 ( & V_112 -> V_50 ) ;
V_589:
F_14 ( & V_129 -> V_50 ) ;
return 0 ;
}
void F_446 ( struct V_123 * V_124 ,
struct V_63 * V_12 ,
struct V_67 * V_305 ,
T_2 V_19 , int V_183 )
{
struct V_14 * V_36 = V_12 -> V_36 ;
int V_590 = 1 ;
int V_31 ;
if ( V_12 -> V_301 . V_24 != V_230 ) {
int V_228 , V_229 ;
V_31 = F_168 ( V_36 , V_124 , V_305 -> V_34 ,
V_305 -> V_47 , V_19 ,
V_12 -> V_301 . V_24 ,
F_251 ( V_305 ) ,
V_239 , NULL ,
& V_228 , & V_229 ) ;
F_35 ( V_31 ) ;
V_590 = V_228 >= 0 && V_229 < 0 ;
}
if ( V_183 && F_447 ( V_305 ) == V_124 -> V_288 ) {
struct V_1 * V_2 ;
if ( V_12 -> V_301 . V_24 != V_230 ) {
V_31 = F_445 ( V_124 , V_305 -> V_34 ) ;
if ( ! V_31 )
goto V_81;
}
V_590 = 0 ;
V_2 = F_79 ( V_36 , V_305 -> V_34 ) ;
if ( F_448 ( V_305 , V_591 ) ) {
F_424 ( V_36 , V_2 , V_305 -> V_34 ,
V_305 -> V_47 , 1 ) ;
F_6 ( V_2 ) ;
goto V_81;
}
F_8 ( F_234 ( V_592 , & V_305 -> V_593 ) ) ;
F_34 ( V_2 , V_305 -> V_34 , V_305 -> V_47 ) ;
F_433 ( V_2 , V_305 -> V_47 , 0 ) ;
F_6 ( V_2 ) ;
F_449 ( V_36 , V_305 -> V_34 , V_305 -> V_47 ) ;
}
V_81:
if ( V_590 )
F_84 ( V_36 , V_305 -> V_47 , F_251 ( V_305 ) ,
V_12 -> V_301 . V_24 ) ;
if ( V_183 ) {
F_450 ( V_594 , & V_305 -> V_593 ) ;
}
}
int V_312 ( struct V_123 * V_124 ,
struct V_14 * V_36 ,
T_2 V_29 , T_2 V_37 , T_2 V_19 , T_2 V_116 ,
T_2 V_115 , T_2 V_35 )
{
int V_228 , V_229 ;
int V_31 ;
if ( F_249 ( V_36 ) )
return 0 ;
if ( V_116 == V_230 ) {
F_8 ( V_115 >= V_117 ) ;
F_184 ( V_36 , V_29 , V_37 , 1 ) ;
V_228 = V_229 = 0 ;
V_31 = 0 ;
} else if ( V_115 < V_117 ) {
V_31 = F_168 ( V_36 , V_124 , V_29 ,
V_37 , V_19 ,
V_116 , ( int ) V_115 ,
V_239 , NULL ,
& V_228 , & V_229 ) ;
} else {
V_31 = F_169 ( V_36 , V_124 , V_29 ,
V_37 , V_19 ,
V_116 , V_115 , V_35 ,
0 , V_239 ,
& V_228 , & V_229 ) ;
}
if ( V_31 == 0 && V_228 >= 0 && V_229 < 0 )
F_84 ( V_36 , V_37 , V_115 , V_116 ) ;
return V_31 ;
}
static T_1 void
F_451 ( struct V_1 * V_2 ,
T_2 V_37 )
{
struct V_48 * V_51 ;
V_51 = F_26 ( V_2 ) ;
if ( ! V_51 )
return;
F_288 ( V_51 -> V_89 , F_1 ( V_2 ) ||
( V_2 -> V_13 -> V_595 >= V_37 ) ) ;
F_28 ( V_51 ) ;
}
static T_1 int
F_452 ( struct V_1 * V_2 )
{
struct V_48 * V_51 ;
int V_31 = 0 ;
V_51 = F_26 ( V_2 ) ;
if ( ! V_51 )
return ( V_2 -> V_3 == V_5 ) ? - V_195 : 0 ;
F_288 ( V_51 -> V_89 , F_1 ( V_2 ) ) ;
if ( V_2 -> V_3 == V_5 )
V_31 = - V_195 ;
F_28 ( V_51 ) ;
return V_31 ;
}
int F_453 ( T_2 V_7 )
{
if ( V_7 & V_376 )
return V_596 ;
else if ( V_7 & V_375 )
return V_597 ;
else if ( V_7 & V_374 )
return V_598 ;
else if ( V_7 & V_404 )
return V_599 ;
else if ( V_7 & V_403 )
return V_600 ;
else if ( V_7 & V_402 )
return V_601 ;
return V_602 ;
}
int F_454 ( struct V_1 * V_2 )
{
return F_453 ( V_2 -> V_7 ) ;
}
static const char * F_455 ( enum V_603 type )
{
if ( type >= V_359 )
return NULL ;
return V_604 [ type ] ;
}
static inline void
F_456 ( struct V_1 * V_2 ,
int V_562 )
{
if ( V_562 )
F_53 ( & V_2 -> V_605 ) ;
}
static inline void
F_457 ( struct V_1 * V_2 ,
int V_562 )
{
F_4 ( V_2 ) ;
if ( V_562 )
F_53 ( & V_2 -> V_605 ) ;
}
static struct V_1 *
F_458 ( struct V_1 * V_16 ,
struct V_563 * V_571 ,
int V_562 )
{
struct V_1 * V_606 = NULL ;
F_12 ( & V_571 -> V_607 ) ;
while ( 1 ) {
V_606 = V_571 -> V_16 ;
if ( ! V_606 )
return NULL ;
if ( V_606 == V_16 )
return V_606 ;
F_4 ( V_606 ) ;
if ( ! V_562 )
return V_606 ;
if ( F_354 ( & V_606 -> V_605 ) )
return V_606 ;
F_14 ( & V_571 -> V_607 ) ;
F_459 ( & V_606 -> V_605 , V_608 ) ;
F_12 ( & V_571 -> V_607 ) ;
if ( V_606 == V_571 -> V_16 )
return V_606 ;
F_49 ( & V_606 -> V_605 ) ;
F_6 ( V_606 ) ;
}
}
static inline void
F_460 ( struct V_1 * V_2 ,
int V_562 )
{
if ( V_562 )
F_49 ( & V_2 -> V_605 ) ;
F_6 ( V_2 ) ;
}
static T_1 int F_461 ( struct V_14 * V_36 ,
T_2 V_561 , T_2 V_37 , T_2 V_609 ,
T_2 V_610 , struct V_69 * V_236 ,
T_2 V_7 , int V_562 )
{
int V_31 = 0 ;
struct V_63 * V_12 = V_36 -> V_64 ;
struct V_563 * V_611 = NULL ;
struct V_1 * V_16 = NULL ;
T_2 V_556 = 0 ;
T_2 V_574 = 0 ;
T_2 V_564 = 0 ;
struct V_110 * V_94 ;
int V_612 = 0 ;
int V_613 = F_453 ( V_7 ) ;
bool V_614 = false ;
bool V_615 = false ;
bool V_616 = true ;
bool V_617 = false ;
bool V_618 = false ;
bool V_619 = false ;
F_8 ( V_37 < V_36 -> V_55 ) ;
V_236 -> type = V_79 ;
V_236 -> V_24 = 0 ;
V_236 -> V_35 = 0 ;
F_462 ( V_36 , V_37 , V_609 , V_7 ) ;
V_94 = F_80 ( V_36 , V_7 ) ;
if ( ! V_94 ) {
F_114 ( V_36 , L_24 , V_7 ) ;
return - V_334 ;
}
if ( F_380 ( V_94 -> V_574 ) ) {
F_12 ( & V_94 -> V_50 ) ;
if ( V_94 -> V_574 &&
V_37 > V_94 -> V_574 ) {
V_236 -> V_35 = V_94 -> V_574 ;
F_14 ( & V_94 -> V_50 ) ;
return - V_334 ;
} else if ( V_94 -> V_574 ) {
V_616 = false ;
}
F_14 ( & V_94 -> V_50 ) ;
}
V_611 = F_435 ( V_36 , V_94 , & V_564 ) ;
if ( V_611 ) {
F_12 ( & V_611 -> V_50 ) ;
if ( V_611 -> V_16 )
V_610 = V_611 -> V_620 ;
if ( V_611 -> V_573 ) {
V_610 = V_611 -> V_620 ;
V_616 = false ;
}
F_14 ( & V_611 -> V_50 ) ;
}
V_556 = F_463 ( V_556 , V_28 ( V_36 , 0 ) ) ;
V_556 = F_463 ( V_556 , V_610 ) ;
if ( V_556 == V_610 ) {
V_16 = F_79 ( V_36 , V_556 ) ;
if ( V_16 && F_3 ( V_16 , V_7 ) &&
V_16 -> V_3 != V_102 ) {
F_53 ( & V_94 -> V_361 ) ;
if ( F_191 ( & V_16 -> V_98 ) ||
V_16 -> V_327 ) {
F_6 ( V_16 ) ;
F_49 ( & V_94 -> V_361 ) ;
} else {
V_613 = F_454 ( V_16 ) ;
F_456 ( V_16 , V_562 ) ;
goto V_621;
}
} else if ( V_16 ) {
F_6 ( V_16 ) ;
}
}
V_622:
V_617 = false ;
if ( V_613 == 0 || V_613 == F_453 ( V_7 ) )
V_619 = true ;
F_53 ( & V_94 -> V_361 ) ;
F_242 (block_group, &space_info->block_groups[index],
list) {
T_2 V_35 ;
int V_3 ;
if ( F_380 ( V_16 -> V_327 ) )
continue;
F_457 ( V_16 , V_562 ) ;
V_556 = V_16 -> V_23 . V_24 ;
if ( ! F_3 ( V_16 , V_7 ) ) {
T_2 V_623 = V_374 |
V_375 |
V_403 |
V_402 |
V_376 ;
if ( ( V_7 & V_623 ) && ! ( V_16 -> V_7 & V_623 ) )
goto V_612;
}
V_621:
V_3 = F_1 ( V_16 ) ;
if ( F_380 ( ! V_3 ) ) {
V_617 = true ;
V_31 = F_62 ( V_16 , 0 ) ;
F_35 ( V_31 < 0 ) ;
V_31 = 0 ;
}
if ( F_380 ( V_16 -> V_3 == V_5 ) )
goto V_612;
if ( V_611 && V_616 ) {
struct V_1 * V_624 ;
unsigned long V_625 ;
V_624 = F_458 ( V_16 ,
V_611 ,
V_562 ) ;
if ( ! V_624 )
goto V_626;
if ( V_624 != V_16 &&
( V_624 -> V_327 ||
! F_3 ( V_624 , V_7 ) ) )
goto V_627;
V_35 = F_464 ( V_624 ,
V_611 ,
V_37 ,
V_624 -> V_23 . V_24 ,
& V_574 ) ;
if ( V_35 ) {
F_14 ( & V_611 -> V_607 ) ;
F_465 ( V_36 ,
V_624 ,
V_556 , V_37 ) ;
if ( V_624 != V_16 ) {
F_460 ( V_16 ,
V_562 ) ;
V_16 = V_624 ;
}
goto V_628;
}
F_8 ( V_611 -> V_16 != V_624 ) ;
V_627:
if ( V_612 >= V_629 &&
V_624 != V_16 ) {
F_14 ( & V_611 -> V_607 ) ;
F_460 ( V_624 ,
V_562 ) ;
goto V_630;
}
F_466 ( NULL , V_611 ) ;
if ( V_624 != V_16 )
F_460 ( V_624 ,
V_562 ) ;
V_626:
if ( V_612 >= V_629 ) {
F_14 ( & V_611 -> V_607 ) ;
goto V_630;
}
V_625 = F_38 (unsigned long,
empty_cluster + empty_size,
block_group->full_stripe_len) ;
V_31 = F_467 ( V_36 , V_16 ,
V_611 , V_556 ,
V_37 ,
V_625 ) ;
if ( V_31 == 0 ) {
V_35 = F_464 ( V_16 ,
V_611 ,
V_37 ,
V_556 ,
& V_574 ) ;
if ( V_35 ) {
F_14 ( & V_611 -> V_607 ) ;
F_465 ( V_36 ,
V_16 , V_556 ,
V_37 ) ;
goto V_628;
}
} else if ( ! V_3 && V_612 > V_631
&& ! V_614 ) {
F_14 ( & V_611 -> V_607 ) ;
V_614 = true ;
F_451 ( V_16 ,
V_37 + V_564 + V_609 ) ;
goto V_621;
}
F_466 ( NULL , V_611 ) ;
F_14 ( & V_611 -> V_607 ) ;
goto V_612;
}
V_630:
if ( F_380 ( V_611 ) ) {
F_12 ( & V_611 -> V_50 ) ;
V_611 -> V_573 = 1 ;
F_14 ( & V_611 -> V_50 ) ;
}
if ( V_3 ) {
struct V_632 * V_49 =
V_16 -> V_13 ;
F_12 ( & V_49 -> V_633 ) ;
if ( V_49 -> V_595 <
V_37 + V_564 + V_609 ) {
if ( V_49 -> V_595 > V_574 )
V_574 = V_49 -> V_595 ;
F_14 ( & V_49 -> V_633 ) ;
goto V_612;
}
F_14 ( & V_49 -> V_633 ) ;
}
V_35 = F_468 ( V_16 , V_556 ,
V_37 , V_609 ,
& V_574 ) ;
if ( ! V_35 && ! V_615 && ! V_3 &&
V_612 > V_631 ) {
F_451 ( V_16 ,
V_37 + V_609 ) ;
V_615 = true ;
goto V_621;
} else if ( ! V_35 ) {
goto V_612;
}
V_628:
V_556 = F_158 ( V_35 , V_36 -> V_634 ) ;
if ( V_556 + V_37 >
V_16 -> V_23 . V_24 + V_16 -> V_23 . V_35 ) {
F_34 ( V_16 , V_35 , V_37 ) ;
goto V_612;
}
if ( V_35 < V_556 )
F_34 ( V_16 , V_35 ,
V_556 - V_35 ) ;
F_35 ( V_35 > V_556 ) ;
V_31 = F_432 ( V_16 , V_561 ,
V_37 , V_562 ) ;
if ( V_31 == - V_199 ) {
F_34 ( V_16 , V_35 , V_37 ) ;
goto V_612;
}
F_428 ( V_16 ) ;
V_236 -> V_24 = V_556 ;
V_236 -> V_35 = V_37 ;
F_469 ( V_36 , V_16 ,
V_556 , V_37 ) ;
F_460 ( V_16 , V_562 ) ;
break;
V_612:
V_614 = false ;
V_615 = false ;
F_35 ( V_613 != F_454 ( V_16 ) ) ;
F_460 ( V_16 , V_562 ) ;
F_51 () ;
}
F_49 ( & V_94 -> V_361 ) ;
if ( ( V_612 == V_631 ) && V_617
&& ! V_618 )
V_618 = true ;
if ( ! V_236 -> V_24 && V_612 >= V_635 && V_617 )
goto V_622;
if ( ! V_236 -> V_24 && ++ V_613 < V_359 )
goto V_622;
if ( ! V_236 -> V_24 && V_612 < V_629 ) {
V_613 = 0 ;
if ( V_612 == V_631 ) {
if ( V_618 || ! V_619 )
V_612 = V_635 ;
else
V_612 = V_636 ;
} else {
V_612 ++ ;
}
if ( V_612 == V_636 ) {
struct V_123 * V_124 ;
int V_637 = 0 ;
V_124 = V_417 -> V_418 ;
if ( V_124 )
V_637 = 1 ;
else
V_124 = F_224 ( V_12 ) ;
if ( F_225 ( V_124 ) ) {
V_31 = F_226 ( V_124 ) ;
goto V_81;
}
V_31 = F_323 ( V_124 , V_36 , V_7 ,
V_420 ) ;
if ( V_31 == - V_334 )
V_612 = V_629 ;
if ( V_31 < 0 && V_31 != - V_334 )
F_171 ( V_124 , V_31 ) ;
else
V_31 = 0 ;
if ( ! V_637 )
F_228 ( V_124 ) ;
if ( V_31 )
goto V_81;
}
if ( V_612 == V_629 ) {
if ( V_609 == 0 &&
V_564 == 0 ) {
V_31 = - V_334 ;
goto V_81;
}
V_609 = 0 ;
V_564 = 0 ;
}
goto V_622;
} else if ( ! V_236 -> V_24 ) {
V_31 = - V_334 ;
} else if ( V_236 -> V_24 ) {
if ( ! V_616 && V_611 ) {
F_12 ( & V_611 -> V_50 ) ;
V_611 -> V_620 = V_236 -> V_24 ;
F_14 ( & V_611 -> V_50 ) ;
}
V_31 = 0 ;
}
V_81:
if ( V_31 == - V_334 ) {
F_12 ( & V_94 -> V_50 ) ;
V_94 -> V_574 = V_574 ;
F_14 ( & V_94 -> V_50 ) ;
V_236 -> V_35 = V_574 ;
}
return V_31 ;
}
static void F_346 ( struct V_14 * V_36 ,
struct V_110 * V_15 , T_2 V_223 ,
int V_638 )
{
struct V_1 * V_2 ;
int V_613 = 0 ;
F_12 ( & V_15 -> V_50 ) ;
F_345 ( V_36 , L_25 ,
V_15 -> V_7 ,
V_15 -> V_371 - F_320 ( V_15 , true ) ,
V_15 -> V_122 ? L_26 : L_27 ) ;
F_345 ( V_36 ,
L_28 ,
V_15 -> V_371 , V_15 -> V_93 , V_15 -> V_411 ,
V_15 -> V_410 , V_15 -> V_412 ,
V_15 -> V_372 ) ;
F_14 ( & V_15 -> V_50 ) ;
if ( ! V_638 )
return;
F_53 ( & V_15 -> V_361 ) ;
V_178:
F_242 (cache, &info->block_groups[index], list) {
F_12 ( & V_2 -> V_50 ) ;
F_345 ( V_36 ,
L_29 ,
V_2 -> V_23 . V_24 , V_2 -> V_23 . V_35 ,
F_61 ( & V_2 -> V_95 ) , V_2 -> V_9 ,
V_2 -> V_10 , V_2 -> V_327 ? L_30 : L_26 ) ;
F_470 ( V_2 , V_223 ) ;
F_14 ( & V_2 -> V_50 ) ;
}
if ( ++ V_613 < V_359 )
goto V_178;
F_49 ( & V_15 -> V_361 ) ;
}
int F_471 ( struct V_63 * V_12 , T_2 V_561 ,
T_2 V_37 , T_2 V_639 ,
T_2 V_609 , T_2 V_610 ,
struct V_69 * V_236 , int V_161 , int V_562 )
{
struct V_14 * V_36 = V_12 -> V_36 ;
bool V_640 = V_37 == V_639 ;
T_2 V_7 ;
int V_31 ;
V_7 = F_316 ( V_12 , V_161 ) ;
V_178:
F_8 ( V_37 < V_36 -> V_55 ) ;
V_31 = F_461 ( V_36 , V_561 , V_37 , V_609 ,
V_610 , V_236 , V_7 , V_562 ) ;
if ( ! V_31 && ! V_161 ) {
F_429 ( V_36 , V_236 -> V_24 ) ;
} else if ( V_31 == - V_334 ) {
if ( ! V_640 && V_236 -> V_35 ) {
V_37 = F_359 ( V_37 >> 1 , V_236 -> V_35 ) ;
V_37 = F_159 ( V_37 ,
V_36 -> V_55 ) ;
V_37 = F_463 ( V_37 , V_639 ) ;
V_561 = V_37 ;
if ( V_37 == V_639 )
V_640 = true ;
goto V_178;
} else if ( F_272 ( V_36 , V_438 ) ) {
struct V_110 * V_428 ;
V_428 = F_80 ( V_36 , V_7 ) ;
F_114 ( V_36 ,
L_31 ,
V_7 , V_37 ) ;
if ( V_428 )
F_346 ( V_36 , V_428 , V_37 , 1 ) ;
}
}
return V_31 ;
}
static int F_472 ( struct V_14 * V_36 ,
T_2 V_34 , T_2 V_47 ,
int V_590 , int V_562 )
{
struct V_1 * V_2 ;
int V_31 = 0 ;
V_2 = F_79 ( V_36 , V_34 ) ;
if ( ! V_2 ) {
F_114 ( V_36 , L_32 ,
V_34 ) ;
return - V_334 ;
}
if ( V_590 )
F_424 ( V_36 , V_2 , V_34 , V_47 , 1 ) ;
else {
if ( F_272 ( V_36 , V_580 ) )
V_31 = F_162 ( V_36 , V_34 , V_47 , NULL ) ;
F_34 ( V_2 , V_34 , V_47 ) ;
F_433 ( V_2 , V_47 , V_562 ) ;
F_449 ( V_36 , V_34 , V_47 ) ;
}
F_6 ( V_2 ) ;
return V_31 ;
}
int F_473 ( struct V_14 * V_36 ,
T_2 V_34 , T_2 V_47 , int V_562 )
{
return F_472 ( V_36 , V_34 , V_47 , 0 , V_562 ) ;
}
int F_474 ( struct V_14 * V_36 ,
T_2 V_34 , T_2 V_47 )
{
return F_472 ( V_36 , V_34 , V_47 , 1 , 0 ) ;
}
static int F_175 ( struct V_123 * V_124 ,
struct V_14 * V_36 ,
T_2 V_19 , T_2 V_116 ,
T_2 V_7 , T_2 V_115 , T_2 V_35 ,
struct V_69 * V_236 , int V_146 )
{
int V_31 ;
struct V_130 * V_641 ;
struct V_158 * V_159 ;
struct V_65 * V_66 ;
struct V_67 * V_68 ;
int type ;
T_3 V_59 ;
if ( V_19 > 0 )
type = V_164 ;
else
type = V_165 ;
V_59 = sizeof( * V_641 ) + F_143 ( type ) ;
V_66 = F_37 () ;
if ( ! V_66 )
return - V_74 ;
V_66 -> V_233 = 1 ;
V_31 = F_125 ( V_124 , V_36 -> V_64 , V_66 ,
V_236 , V_59 ) ;
if ( V_31 ) {
F_56 ( V_66 ) ;
return V_31 ;
}
V_68 = V_66 -> V_82 [ 0 ] ;
V_641 = F_91 ( V_68 , V_66 -> V_83 [ 0 ] ,
struct V_130 ) ;
F_103 ( V_68 , V_641 , V_146 ) ;
F_104 ( V_68 , V_641 , V_124 -> V_288 ) ;
F_105 ( V_68 , V_641 ,
V_7 | V_156 ) ;
V_159 = (struct V_158 * ) ( V_641 + 1 ) ;
F_149 ( V_68 , V_159 , type ) ;
if ( V_19 > 0 ) {
struct V_181 * V_174 ;
V_174 = (struct V_181 * ) ( V_159 + 1 ) ;
F_150 ( V_68 , V_159 , V_19 ) ;
F_126 ( V_68 , V_174 , V_146 ) ;
} else {
struct V_173 * V_174 ;
V_174 = (struct V_173 * ) ( & V_159 -> V_35 ) ;
F_128 ( V_68 , V_174 , V_116 ) ;
F_129 ( V_68 , V_174 , V_115 ) ;
F_130 ( V_68 , V_174 , V_35 ) ;
F_131 ( V_68 , V_174 , V_146 ) ;
}
F_108 ( V_66 -> V_82 [ 0 ] ) ;
F_56 ( V_66 ) ;
V_31 = F_475 ( V_124 , V_36 , V_236 -> V_24 ,
V_236 -> V_35 ) ;
if ( V_31 )
return V_31 ;
V_31 = F_419 ( V_124 , V_36 , V_236 -> V_24 , V_236 -> V_35 , 1 ) ;
if ( V_31 ) {
F_114 ( V_36 , L_33 ,
V_236 -> V_24 , V_236 -> V_35 ) ;
F_96 () ;
}
F_476 ( V_36 , V_236 -> V_24 , V_236 -> V_35 ) ;
return V_31 ;
}
static int F_182 ( struct V_123 * V_124 ,
struct V_14 * V_36 ,
T_2 V_19 , T_2 V_116 ,
T_2 V_7 , struct V_642 * V_23 ,
int V_186 , struct V_69 * V_236 )
{
int V_31 ;
struct V_130 * V_641 ;
struct V_150 * V_643 ;
struct V_158 * V_159 ;
struct V_65 * V_66 ;
struct V_67 * V_68 ;
T_3 V_59 = sizeof( * V_641 ) + sizeof( * V_159 ) ;
T_2 V_37 = V_236 -> V_35 ;
bool V_192 = F_89 ( V_36 , V_135 ) ;
if ( ! V_192 )
V_59 += sizeof( * V_643 ) ;
V_66 = F_37 () ;
if ( ! V_66 ) {
F_474 ( V_36 , V_236 -> V_24 ,
V_36 -> V_54 ) ;
return - V_74 ;
}
V_66 -> V_233 = 1 ;
V_31 = F_125 ( V_124 , V_36 -> V_64 , V_66 ,
V_236 , V_59 ) ;
if ( V_31 ) {
F_56 ( V_66 ) ;
F_474 ( V_36 , V_236 -> V_24 ,
V_36 -> V_54 ) ;
return V_31 ;
}
V_68 = V_66 -> V_82 [ 0 ] ;
V_641 = F_91 ( V_68 , V_66 -> V_83 [ 0 ] ,
struct V_130 ) ;
F_103 ( V_68 , V_641 , 1 ) ;
F_104 ( V_68 , V_641 , V_124 -> V_288 ) ;
F_105 ( V_68 , V_641 ,
V_7 | V_155 ) ;
if ( V_192 ) {
V_159 = (struct V_158 * ) ( V_641 + 1 ) ;
V_37 = V_36 -> V_54 ;
} else {
V_643 = (struct V_150 * ) ( V_641 + 1 ) ;
F_177 ( V_68 , V_643 , V_23 ) ;
F_107 ( V_68 , V_643 , V_186 ) ;
V_159 = (struct V_158 * ) ( V_643 + 1 ) ;
}
if ( V_19 > 0 ) {
F_35 ( ! ( V_7 & V_140 ) ) ;
F_149 ( V_68 , V_159 ,
V_163 ) ;
F_150 ( V_68 , V_159 , V_19 ) ;
} else {
F_149 ( V_68 , V_159 ,
V_162 ) ;
F_150 ( V_68 , V_159 , V_116 ) ;
}
F_108 ( V_68 ) ;
F_56 ( V_66 ) ;
V_31 = F_475 ( V_124 , V_36 , V_236 -> V_24 ,
V_37 ) ;
if ( V_31 )
return V_31 ;
V_31 = F_419 ( V_124 , V_36 , V_236 -> V_24 ,
V_36 -> V_54 , 1 ) ;
if ( V_31 ) {
F_114 ( V_36 , L_33 ,
V_236 -> V_24 , V_236 -> V_35 ) ;
F_96 () ;
}
F_476 ( V_36 , V_236 -> V_24 ,
V_36 -> V_54 ) ;
return V_31 ;
}
int F_477 ( struct V_123 * V_124 ,
T_2 V_116 , T_2 V_115 ,
T_2 V_35 , T_2 V_561 ,
struct V_69 * V_236 )
{
struct V_14 * V_36 = V_124 -> V_36 ;
int V_31 ;
F_35 ( V_116 == V_230 ) ;
V_31 = F_169 ( V_36 , V_124 , V_236 -> V_24 ,
V_236 -> V_35 , 0 , V_116 , V_115 ,
V_35 , V_561 ,
V_260 , NULL , NULL ) ;
return V_31 ;
}
int F_478 ( struct V_123 * V_124 ,
struct V_14 * V_36 ,
T_2 V_116 , T_2 V_115 , T_2 V_35 ,
struct V_69 * V_236 )
{
int V_31 ;
struct V_1 * V_16 ;
struct V_110 * V_94 ;
if ( ! F_89 ( V_36 , V_559 ) ) {
V_31 = F_426 ( V_36 , V_236 -> V_24 ,
V_236 -> V_35 ) ;
if ( V_31 )
return V_31 ;
}
V_16 = F_79 ( V_36 , V_236 -> V_24 ) ;
if ( ! V_16 )
return - V_196 ;
V_94 = V_16 -> V_94 ;
F_12 ( & V_94 -> V_50 ) ;
F_12 ( & V_16 -> V_50 ) ;
V_94 -> V_410 += V_236 -> V_35 ;
V_16 -> V_10 += V_236 -> V_35 ;
F_14 ( & V_16 -> V_50 ) ;
F_14 ( & V_94 -> V_50 ) ;
V_31 = F_175 ( V_124 , V_36 , 0 , V_116 ,
0 , V_115 , V_35 , V_236 , 1 ) ;
F_6 ( V_16 ) ;
return V_31 ;
}
static struct V_67 *
F_479 ( struct V_123 * V_124 , struct V_63 * V_12 ,
T_2 V_29 , int V_186 )
{
struct V_14 * V_36 = V_12 -> V_36 ;
struct V_67 * V_305 ;
V_305 = F_480 ( V_36 , V_29 ) ;
if ( F_225 ( V_305 ) )
return V_305 ;
F_481 ( V_305 , V_124 -> V_288 ) ;
F_482 ( V_12 -> V_301 . V_24 , V_305 , V_186 ) ;
F_483 ( V_305 ) ;
F_484 ( V_36 , V_305 ) ;
F_450 ( V_644 , & V_305 -> V_593 ) ;
F_485 ( V_305 ) ;
F_486 ( V_305 ) ;
if ( V_12 -> V_301 . V_24 == V_230 ) {
V_305 -> V_645 = V_12 -> V_646 % 2 ;
if ( V_305 -> V_645 == 0 )
F_423 ( & V_12 -> V_647 , V_305 -> V_34 ,
V_305 -> V_34 + V_305 -> V_47 - 1 , V_97 ) ;
else
F_487 ( & V_12 -> V_647 , V_305 -> V_34 ,
V_305 -> V_34 + V_305 -> V_47 - 1 ) ;
} else {
V_305 -> V_645 = - 1 ;
F_423 ( & V_124 -> V_141 -> V_648 , V_305 -> V_34 ,
V_305 -> V_34 + V_305 -> V_47 - 1 , V_97 ) ;
}
V_124 -> V_341 = true ;
return V_305 ;
}
static struct V_276 *
F_488 ( struct V_123 * V_124 ,
struct V_63 * V_12 , T_3 V_649 )
{
struct V_14 * V_36 = V_12 -> V_36 ;
struct V_276 * V_464 ;
struct V_276 * V_277 = & V_36 -> V_280 ;
int V_31 ;
bool V_650 = false ;
V_464 = F_382 ( V_124 , V_12 ) ;
if ( F_380 ( V_464 -> V_59 == 0 ) )
goto V_651;
V_178:
V_31 = F_381 ( V_464 , V_649 ) ;
if ( ! V_31 )
return V_464 ;
if ( V_464 -> V_652 )
return F_489 ( V_31 ) ;
if ( V_464 -> type == V_653 && ! V_650 ) {
V_650 = true ;
F_395 ( V_36 ) ;
goto V_178;
}
if ( F_272 ( V_36 , V_438 ) ) {
static F_490 ( V_654 ,
V_655 * 10 ,
1 ) ;
if ( F_491 ( & V_654 ) )
F_492 ( 1 , V_656
L_34 , V_31 ) ;
}
V_651:
V_31 = F_379 ( V_12 , V_464 , V_649 ,
V_440 ) ;
if ( ! V_31 )
return V_464 ;
if ( V_464 -> type != V_653 &&
V_464 -> V_94 == V_277 -> V_94 ) {
V_31 = F_381 ( V_277 , V_649 ) ;
if ( ! V_31 )
return V_277 ;
}
return F_489 ( V_31 ) ;
}
static void F_493 ( struct V_14 * V_36 ,
struct V_276 * V_464 , T_3 V_649 )
{
F_383 ( V_464 , V_649 , 0 ) ;
F_386 ( V_36 , V_464 , NULL , 0 ) ;
}
struct V_67 * F_494 ( struct V_123 * V_124 ,
struct V_63 * V_12 ,
T_2 V_19 , T_2 V_116 ,
const struct V_642 * V_23 ,
int V_186 , T_2 V_657 ,
T_2 V_609 )
{
struct V_14 * V_36 = V_12 -> V_36 ;
struct V_69 V_236 ;
struct V_276 * V_464 ;
struct V_67 * V_305 ;
struct V_201 * V_143 ;
T_2 V_7 = 0 ;
int V_31 ;
T_3 V_649 = V_36 -> V_54 ;
bool V_192 = F_89 ( V_36 , V_135 ) ;
#ifdef F_495
if ( F_249 ( V_36 ) ) {
V_305 = F_479 ( V_124 , V_12 , V_12 -> V_658 ,
V_186 ) ;
if ( ! F_225 ( V_305 ) )
V_12 -> V_658 += V_649 ;
return V_305 ;
}
#endif
V_464 = F_488 ( V_124 , V_12 , V_649 ) ;
if ( F_225 ( V_464 ) )
return F_496 ( V_464 ) ;
V_31 = F_471 ( V_12 , V_649 , V_649 , V_649 ,
V_609 , V_657 , & V_236 , 0 , 0 ) ;
if ( V_31 )
goto V_659;
V_305 = F_479 ( V_124 , V_12 , V_236 . V_24 , V_186 ) ;
if ( F_225 ( V_305 ) ) {
V_31 = F_226 ( V_305 ) ;
goto V_660;
}
if ( V_116 == V_661 ) {
if ( V_19 == 0 )
V_19 = V_236 . V_24 ;
V_7 |= V_140 ;
} else
F_35 ( V_19 > 0 ) ;
if ( V_116 != V_230 ) {
V_143 = F_239 () ;
if ( ! V_143 ) {
V_31 = - V_74 ;
goto V_662;
}
if ( V_23 )
memcpy ( & V_143 -> V_23 , V_23 , sizeof( V_143 -> V_23 ) ) ;
else
memset ( & V_143 -> V_23 , 0 , sizeof( V_143 -> V_23 ) ) ;
V_143 -> V_145 = V_7 ;
V_143 -> V_240 = V_192 ? false : true ;
V_143 -> V_144 = true ;
V_143 -> V_161 = false ;
V_143 -> V_186 = V_186 ;
V_31 = F_168 ( V_36 , V_124 , V_236 . V_24 ,
V_236 . V_35 , V_19 ,
V_116 , V_186 ,
V_260 ,
V_143 , NULL , NULL ) ;
if ( V_31 )
goto V_663;
}
return V_305 ;
V_663:
F_200 ( V_143 ) ;
V_662:
F_497 ( V_305 ) ;
V_660:
F_473 ( V_36 , V_236 . V_24 , V_236 . V_35 , 0 ) ;
V_659:
F_493 ( V_36 , V_464 , V_649 ) ;
return F_489 ( V_31 ) ;
}
static T_1 void F_498 ( struct V_123 * V_124 ,
struct V_63 * V_12 ,
struct V_664 * V_665 ,
struct V_65 * V_66 )
{
struct V_14 * V_36 = V_12 -> V_36 ;
T_2 V_29 ;
T_2 V_331 ;
T_2 V_126 ;
T_2 V_7 ;
T_3 V_72 ;
struct V_69 V_23 ;
struct V_67 * V_157 ;
int V_31 ;
int V_666 ;
int V_667 = 0 ;
if ( V_66 -> V_83 [ V_665 -> V_186 ] < V_665 -> V_668 ) {
V_665 -> V_669 = V_665 -> V_669 * 2 / 3 ;
V_665 -> V_669 = F_463 ( V_665 -> V_669 , 2 ) ;
} else {
V_665 -> V_669 = V_665 -> V_669 * 3 / 2 ;
V_665 -> V_669 = F_25 ( int , V_665 -> V_669 ,
F_499 ( V_36 ) ) ;
}
V_157 = V_66 -> V_82 [ V_665 -> V_186 ] ;
V_72 = F_42 ( V_157 ) ;
for ( V_666 = V_66 -> V_83 [ V_665 -> V_186 ] ; V_666 < V_72 ; V_666 ++ ) {
if ( V_667 >= V_665 -> V_669 )
break;
F_51 () ;
V_29 = F_256 ( V_157 , V_666 ) ;
V_331 = F_500 ( V_157 , V_666 ) ;
if ( V_666 == V_66 -> V_83 [ V_665 -> V_186 ] )
goto V_77;
if ( V_665 -> V_670 == V_671 &&
V_331 <= V_12 -> V_301 . V_35 )
continue;
V_31 = F_88 ( V_124 , V_36 , V_29 ,
V_665 -> V_186 - 1 , 1 , & V_126 ,
& V_7 ) ;
if ( V_31 < 0 )
continue;
F_35 ( V_126 == 0 ) ;
if ( V_665 -> V_670 == V_672 ) {
if ( V_126 == 1 )
goto V_77;
if ( V_665 -> V_186 == 1 &&
( V_7 & V_140 ) )
continue;
if ( ! V_665 -> V_673 ||
V_331 <= V_12 -> V_301 . V_35 )
continue;
F_141 ( V_157 , & V_23 , V_666 ) ;
V_31 = F_501 ( & V_23 ,
& V_665 -> V_674 ) ;
if ( V_31 < 0 )
continue;
} else {
if ( V_665 -> V_186 == 1 &&
( V_7 & V_140 ) )
continue;
}
V_77:
F_502 ( V_36 , V_29 ) ;
V_667 ++ ;
}
V_665 -> V_668 = V_666 ;
}
static T_1 int F_503 ( struct V_123 * V_124 ,
struct V_63 * V_12 ,
struct V_65 * V_66 ,
struct V_664 * V_665 , int V_675 )
{
struct V_14 * V_36 = V_12 -> V_36 ;
int V_186 = V_665 -> V_186 ;
struct V_67 * V_157 = V_66 -> V_82 [ V_186 ] ;
T_2 V_676 = V_140 ;
int V_31 ;
if ( V_665 -> V_670 == V_671 &&
F_250 ( V_157 ) != V_12 -> V_301 . V_24 )
return 1 ;
if ( V_675 &&
( ( V_665 -> V_670 == V_672 && V_665 -> V_126 [ V_186 ] != 1 ) ||
( V_665 -> V_670 == V_671 && ! ( V_665 -> V_7 [ V_186 ] & V_676 ) ) ) ) {
F_35 ( ! V_66 -> V_677 [ V_186 ] ) ;
V_31 = F_88 ( V_124 , V_36 ,
V_157 -> V_34 , V_186 , 1 ,
& V_665 -> V_126 [ V_186 ] ,
& V_665 -> V_7 [ V_186 ] ) ;
F_35 ( V_31 == - V_74 ) ;
if ( V_31 )
return V_31 ;
F_35 ( V_665 -> V_126 [ V_186 ] == 0 ) ;
}
if ( V_665 -> V_670 == V_672 ) {
if ( V_665 -> V_126 [ V_186 ] > 1 )
return 1 ;
if ( V_66 -> V_677 [ V_186 ] && ! V_665 -> V_194 ) {
F_504 ( V_157 , V_66 -> V_677 [ V_186 ] ) ;
V_66 -> V_677 [ V_186 ] = 0 ;
}
return 0 ;
}
if ( ! ( V_665 -> V_7 [ V_186 ] & V_676 ) ) {
F_35 ( ! V_66 -> V_677 [ V_186 ] ) ;
V_31 = F_257 ( V_124 , V_12 , V_157 , 1 ) ;
F_35 ( V_31 ) ;
V_31 = F_258 ( V_124 , V_12 , V_157 , 0 ) ;
F_35 ( V_31 ) ;
V_31 = F_238 ( V_124 , V_36 , V_157 -> V_34 ,
V_157 -> V_47 , V_676 ,
F_251 ( V_157 ) , 0 ) ;
F_35 ( V_31 ) ;
V_665 -> V_7 [ V_186 ] |= V_676 ;
}
if ( V_66 -> V_677 [ V_186 ] && V_186 > 0 ) {
F_504 ( V_157 , V_66 -> V_677 [ V_186 ] ) ;
V_66 -> V_677 [ V_186 ] = 0 ;
}
return 0 ;
}
static T_1 int F_505 ( struct V_123 * V_124 ,
struct V_63 * V_12 ,
struct V_65 * V_66 ,
struct V_664 * V_665 , int * V_675 )
{
struct V_14 * V_36 = V_12 -> V_36 ;
T_2 V_29 ;
T_2 V_331 ;
T_2 V_19 ;
T_3 V_649 ;
struct V_69 V_23 ;
struct V_67 * V_80 ;
int V_186 = V_665 -> V_186 ;
int V_77 = 0 ;
int V_31 = 0 ;
bool V_678 = false ;
V_331 = F_500 ( V_66 -> V_82 [ V_186 ] ,
V_66 -> V_83 [ V_186 ] ) ;
if ( V_665 -> V_670 == V_671 &&
V_331 <= V_12 -> V_301 . V_35 ) {
* V_675 = 1 ;
return 1 ;
}
V_29 = F_256 ( V_66 -> V_82 [ V_186 ] , V_66 -> V_83 [ V_186 ] ) ;
V_649 = V_36 -> V_54 ;
V_80 = F_506 ( V_36 , V_29 ) ;
if ( ! V_80 ) {
V_80 = F_480 ( V_36 , V_29 ) ;
if ( F_225 ( V_80 ) )
return F_226 ( V_80 ) ;
F_482 ( V_12 -> V_301 . V_24 , V_80 ,
V_186 - 1 ) ;
V_77 = 1 ;
}
F_483 ( V_80 ) ;
F_485 ( V_80 ) ;
V_31 = F_88 ( V_124 , V_36 , V_29 , V_186 - 1 , 1 ,
& V_665 -> V_126 [ V_186 - 1 ] ,
& V_665 -> V_7 [ V_186 - 1 ] ) ;
if ( V_31 < 0 )
goto V_679;
if ( F_380 ( V_665 -> V_126 [ V_186 - 1 ] == 0 ) ) {
F_114 ( V_36 , L_35 ) ;
V_31 = - V_195 ;
goto V_679;
}
* V_675 = 0 ;
if ( V_665 -> V_670 == V_672 ) {
if ( V_665 -> V_126 [ V_186 - 1 ] > 1 ) {
V_678 = true ;
if ( V_186 == 1 &&
( V_665 -> V_7 [ 0 ] & V_140 ) )
goto V_680;
if ( ! V_665 -> V_673 ||
V_331 <= V_12 -> V_301 . V_35 )
goto V_680;
F_141 ( V_66 -> V_82 [ V_186 ] , & V_23 ,
V_66 -> V_83 [ V_186 ] ) ;
V_31 = F_501 ( & V_23 , & V_665 -> V_674 ) ;
if ( V_31 < 0 )
goto V_680;
V_665 -> V_670 = V_671 ;
V_665 -> V_681 = V_186 - 1 ;
}
} else {
if ( V_186 == 1 &&
( V_665 -> V_7 [ 0 ] & V_140 ) )
goto V_680;
}
if ( ! F_507 ( V_80 , V_331 , 0 ) ) {
F_508 ( V_80 ) ;
F_497 ( V_80 ) ;
V_80 = NULL ;
* V_675 = 1 ;
}
if ( ! V_80 ) {
if ( V_77 && V_186 == 1 )
F_498 ( V_124 , V_12 , V_665 , V_66 ) ;
V_80 = F_509 ( V_36 , V_29 , V_331 ) ;
if ( F_225 ( V_80 ) ) {
return F_226 ( V_80 ) ;
} else if ( ! F_510 ( V_80 ) ) {
F_497 ( V_80 ) ;
return - V_195 ;
}
F_483 ( V_80 ) ;
F_485 ( V_80 ) ;
}
V_186 -- ;
ASSERT ( V_186 == F_251 ( V_80 ) ) ;
if ( V_186 != F_251 ( V_80 ) ) {
F_114 ( V_12 -> V_36 , L_36 ) ;
V_31 = - V_195 ;
goto V_679;
}
V_66 -> V_82 [ V_186 ] = V_80 ;
V_66 -> V_83 [ V_186 ] = 0 ;
V_66 -> V_677 [ V_186 ] = V_682 ;
V_665 -> V_186 = V_186 ;
if ( V_665 -> V_186 == 1 )
V_665 -> V_668 = 0 ;
return 0 ;
V_680:
V_665 -> V_126 [ V_186 - 1 ] = 0 ;
V_665 -> V_7 [ V_186 - 1 ] = 0 ;
if ( V_665 -> V_670 == V_672 ) {
if ( V_665 -> V_7 [ V_186 ] & V_140 ) {
V_19 = V_66 -> V_82 [ V_186 ] -> V_34 ;
} else {
ASSERT ( V_12 -> V_301 . V_24 ==
F_250 ( V_66 -> V_82 [ V_186 ] ) ) ;
if ( V_12 -> V_301 . V_24 !=
F_250 ( V_66 -> V_82 [ V_186 ] ) ) {
F_114 ( V_12 -> V_36 ,
L_37 ) ;
V_31 = - V_195 ;
goto V_679;
}
V_19 = 0 ;
}
if ( V_678 ) {
V_31 = F_511 ( V_124 , V_12 , V_80 ,
V_331 , V_186 - 1 ) ;
if ( V_31 ) {
F_512 ( V_36 ,
L_38 ,
V_31 ) ;
}
}
V_31 = V_312 ( V_124 , V_36 , V_29 , V_649 ,
V_19 , V_12 -> V_301 . V_24 ,
V_186 - 1 , 0 ) ;
if ( V_31 )
goto V_679;
}
* V_675 = 1 ;
V_31 = 1 ;
V_679:
F_508 ( V_80 ) ;
F_497 ( V_80 ) ;
return V_31 ;
}
static T_1 int F_513 ( struct V_123 * V_124 ,
struct V_63 * V_12 ,
struct V_65 * V_66 ,
struct V_664 * V_665 )
{
struct V_14 * V_36 = V_12 -> V_36 ;
int V_31 ;
int V_186 = V_665 -> V_186 ;
struct V_67 * V_157 = V_66 -> V_82 [ V_186 ] ;
T_2 V_19 = 0 ;
if ( V_665 -> V_670 == V_671 ) {
F_35 ( V_665 -> V_681 < V_186 ) ;
if ( V_186 < V_665 -> V_681 )
goto V_81;
V_31 = F_45 ( V_66 , V_186 + 1 , & V_665 -> V_674 ) ;
if ( V_31 > 0 )
V_665 -> V_673 = 0 ;
V_665 -> V_670 = V_672 ;
V_665 -> V_681 = - 1 ;
V_66 -> V_83 [ V_186 ] = 0 ;
if ( ! V_66 -> V_677 [ V_186 ] ) {
F_35 ( V_186 == 0 ) ;
F_483 ( V_157 ) ;
F_485 ( V_157 ) ;
V_66 -> V_677 [ V_186 ] = V_682 ;
V_31 = F_88 ( V_124 , V_36 ,
V_157 -> V_34 , V_186 , 1 ,
& V_665 -> V_126 [ V_186 ] ,
& V_665 -> V_7 [ V_186 ] ) ;
if ( V_31 < 0 ) {
F_504 ( V_157 , V_66 -> V_677 [ V_186 ] ) ;
V_66 -> V_677 [ V_186 ] = 0 ;
return V_31 ;
}
F_35 ( V_665 -> V_126 [ V_186 ] == 0 ) ;
if ( V_665 -> V_126 [ V_186 ] == 1 ) {
F_504 ( V_157 , V_66 -> V_677 [ V_186 ] ) ;
V_66 -> V_677 [ V_186 ] = 0 ;
return 1 ;
}
}
}
F_35 ( V_665 -> V_126 [ V_186 ] > 1 && ! V_66 -> V_677 [ V_186 ] ) ;
if ( V_665 -> V_126 [ V_186 ] == 1 ) {
if ( V_186 == 0 ) {
if ( V_665 -> V_7 [ V_186 ] & V_140 )
V_31 = F_258 ( V_124 , V_12 , V_157 , 1 ) ;
else
V_31 = F_258 ( V_124 , V_12 , V_157 , 0 ) ;
F_35 ( V_31 ) ;
V_31 = F_514 ( V_124 , V_36 , V_157 ) ;
if ( V_31 ) {
F_512 ( V_36 ,
L_39 ,
V_31 ) ;
}
}
if ( ! V_66 -> V_677 [ V_186 ] &&
F_447 ( V_157 ) == V_124 -> V_288 ) {
F_483 ( V_157 ) ;
F_485 ( V_157 ) ;
V_66 -> V_677 [ V_186 ] = V_682 ;
}
F_484 ( V_36 , V_157 ) ;
}
if ( V_157 == V_12 -> V_142 ) {
if ( V_665 -> V_7 [ V_186 ] & V_140 )
V_19 = V_157 -> V_34 ;
else
F_35 ( V_12 -> V_301 . V_24 !=
F_250 ( V_157 ) ) ;
} else {
if ( V_665 -> V_7 [ V_186 + 1 ] & V_140 )
V_19 = V_66 -> V_82 [ V_186 + 1 ] -> V_34 ;
else
F_35 ( V_12 -> V_301 . V_24 !=
F_250 ( V_66 -> V_82 [ V_186 + 1 ] ) ) ;
}
F_446 ( V_124 , V_12 , V_157 , V_19 , V_665 -> V_126 [ V_186 ] == 1 ) ;
V_81:
V_665 -> V_126 [ V_186 ] = 0 ;
V_665 -> V_7 [ V_186 ] = 0 ;
return 0 ;
}
static T_1 int F_515 ( struct V_123 * V_124 ,
struct V_63 * V_12 ,
struct V_65 * V_66 ,
struct V_664 * V_665 )
{
int V_186 = V_665 -> V_186 ;
int V_675 = 1 ;
int V_31 ;
while ( V_186 >= 0 ) {
V_31 = F_503 ( V_124 , V_12 , V_66 , V_665 , V_675 ) ;
if ( V_31 > 0 )
break;
if ( V_186 == 0 )
break;
if ( V_66 -> V_83 [ V_186 ] >=
F_42 ( V_66 -> V_82 [ V_186 ] ) )
break;
V_31 = F_505 ( V_124 , V_12 , V_66 , V_665 , & V_675 ) ;
if ( V_31 > 0 ) {
V_66 -> V_83 [ V_186 ] ++ ;
continue;
} else if ( V_31 < 0 )
return V_31 ;
V_186 = V_665 -> V_186 ;
}
return 0 ;
}
static T_1 int F_516 ( struct V_123 * V_124 ,
struct V_63 * V_12 ,
struct V_65 * V_66 ,
struct V_664 * V_665 , int V_683 )
{
int V_186 = V_665 -> V_186 ;
int V_31 ;
V_66 -> V_83 [ V_186 ] = F_42 ( V_66 -> V_82 [ V_186 ] ) ;
while ( V_186 < V_683 && V_66 -> V_82 [ V_186 ] ) {
V_665 -> V_186 = V_186 ;
if ( V_66 -> V_83 [ V_186 ] + 1 <
F_42 ( V_66 -> V_82 [ V_186 ] ) ) {
V_66 -> V_83 [ V_186 ] ++ ;
return 0 ;
} else {
V_31 = F_513 ( V_124 , V_12 , V_66 , V_665 ) ;
if ( V_31 > 0 )
return 0 ;
if ( V_66 -> V_677 [ V_186 ] ) {
F_504 ( V_66 -> V_82 [ V_186 ] ,
V_66 -> V_677 [ V_186 ] ) ;
V_66 -> V_677 [ V_186 ] = 0 ;
}
F_497 ( V_66 -> V_82 [ V_186 ] ) ;
V_66 -> V_82 [ V_186 ] = NULL ;
V_186 ++ ;
}
}
return 1 ;
}
int F_517 ( struct V_63 * V_12 ,
struct V_276 * V_464 , int V_673 ,
int V_684 )
{
struct V_14 * V_36 = V_12 -> V_36 ;
struct V_65 * V_66 ;
struct V_123 * V_124 ;
struct V_63 * V_289 = V_36 -> V_289 ;
struct V_685 * V_302 = & V_12 -> V_302 ;
struct V_664 * V_665 ;
struct V_69 V_23 ;
int V_176 = 0 ;
int V_31 ;
int V_186 ;
bool V_686 = false ;
F_201 ( V_36 , L_40 , V_12 -> V_24 ) ;
V_66 = F_37 () ;
if ( ! V_66 ) {
V_176 = - V_74 ;
goto V_81;
}
V_665 = F_64 ( sizeof( * V_665 ) , V_97 ) ;
if ( ! V_665 ) {
F_56 ( V_66 ) ;
V_176 = - V_74 ;
goto V_81;
}
V_124 = F_518 ( V_289 , 0 ) ;
if ( F_225 ( V_124 ) ) {
V_176 = F_226 ( V_124 ) ;
goto V_137;
}
if ( V_464 )
V_124 -> V_464 = V_464 ;
if ( F_519 ( & V_302 -> V_687 ) == 0 ) {
V_186 = F_251 ( V_12 -> V_142 ) ;
V_66 -> V_82 [ V_186 ] = F_520 ( V_12 ) ;
F_485 ( V_66 -> V_82 [ V_186 ] ) ;
V_66 -> V_83 [ V_186 ] = 0 ;
V_66 -> V_677 [ V_186 ] = V_682 ;
memset ( & V_665 -> V_674 , 0 ,
sizeof( V_665 -> V_674 ) ) ;
} else {
F_521 ( & V_23 , & V_302 -> V_687 ) ;
memcpy ( & V_665 -> V_674 , & V_23 ,
sizeof( V_665 -> V_674 ) ) ;
V_186 = V_302 -> V_688 ;
F_35 ( V_186 == 0 ) ;
V_66 -> V_689 = V_186 ;
V_31 = F_41 ( NULL , V_12 , & V_23 , V_66 , 0 , 0 ) ;
V_66 -> V_689 = 0 ;
if ( V_31 < 0 ) {
V_176 = V_31 ;
goto V_690;
}
F_8 ( V_31 > 0 ) ;
F_145 ( V_66 , 0 ) ;
V_186 = F_251 ( V_12 -> V_142 ) ;
while ( 1 ) {
F_483 ( V_66 -> V_82 [ V_186 ] ) ;
F_485 ( V_66 -> V_82 [ V_186 ] ) ;
V_66 -> V_677 [ V_186 ] = V_682 ;
V_31 = F_88 ( V_124 , V_36 ,
V_66 -> V_82 [ V_186 ] -> V_34 ,
V_186 , 1 , & V_665 -> V_126 [ V_186 ] ,
& V_665 -> V_7 [ V_186 ] ) ;
if ( V_31 < 0 ) {
V_176 = V_31 ;
goto V_690;
}
F_35 ( V_665 -> V_126 [ V_186 ] == 0 ) ;
if ( V_186 == V_302 -> V_688 )
break;
F_508 ( V_66 -> V_82 [ V_186 ] ) ;
V_66 -> V_677 [ V_186 ] = 0 ;
F_8 ( V_665 -> V_126 [ V_186 ] != 1 ) ;
V_186 -- ;
}
}
V_665 -> V_186 = V_186 ;
V_665 -> V_681 = - 1 ;
V_665 -> V_670 = V_672 ;
V_665 -> V_673 = V_673 ;
V_665 -> V_194 = 0 ;
V_665 -> V_684 = V_684 ;
V_665 -> V_669 = F_499 ( V_36 ) ;
while ( 1 ) {
V_31 = F_515 ( V_124 , V_12 , V_66 , V_665 ) ;
if ( V_31 < 0 ) {
V_176 = V_31 ;
break;
}
V_31 = F_516 ( V_124 , V_12 , V_66 , V_665 , V_187 ) ;
if ( V_31 < 0 ) {
V_176 = V_31 ;
break;
}
if ( V_31 > 0 ) {
F_35 ( V_665 -> V_670 != V_672 ) ;
break;
}
if ( V_665 -> V_670 == V_672 ) {
V_186 = V_665 -> V_186 ;
F_522 ( V_66 -> V_82 [ V_186 ] ,
& V_302 -> V_687 ,
V_66 -> V_83 [ V_186 ] ) ;
V_302 -> V_688 = V_186 ;
}
F_35 ( V_665 -> V_186 == 0 ) ;
if ( F_523 ( V_124 ) ||
( ! V_684 && F_524 ( V_36 ) ) ) {
V_31 = F_525 ( V_124 , V_289 ,
& V_12 -> V_301 ,
V_302 ) ;
if ( V_31 ) {
F_171 ( V_124 , V_31 ) ;
V_176 = V_31 ;
goto V_690;
}
F_526 ( V_124 ) ;
if ( ! V_684 && F_524 ( V_36 ) ) {
F_201 ( V_36 ,
L_41 ) ;
V_176 = - V_199 ;
goto V_137;
}
V_124 = F_518 ( V_289 , 0 ) ;
if ( F_225 ( V_124 ) ) {
V_176 = F_226 ( V_124 ) ;
goto V_137;
}
if ( V_464 )
V_124 -> V_464 = V_464 ;
}
}
F_48 ( V_66 ) ;
if ( V_176 )
goto V_690;
V_31 = F_527 ( V_124 , V_36 , & V_12 -> V_301 ) ;
if ( V_31 ) {
F_171 ( V_124 , V_31 ) ;
goto V_690;
}
if ( V_12 -> V_301 . V_24 != V_661 ) {
V_31 = F_528 ( V_289 , & V_12 -> V_301 , V_66 ,
NULL , NULL ) ;
if ( V_31 < 0 ) {
F_171 ( V_124 , V_31 ) ;
V_176 = V_31 ;
goto V_690;
} else if ( V_31 > 0 ) {
F_529 ( V_124 , V_289 ,
V_12 -> V_301 . V_24 ) ;
}
}
if ( F_234 ( V_691 , & V_12 -> V_311 ) ) {
F_530 ( V_124 , V_12 ) ;
} else {
F_497 ( V_12 -> V_142 ) ;
F_497 ( V_12 -> V_692 ) ;
F_531 ( V_12 ) ;
}
V_686 = true ;
V_690:
F_526 ( V_124 ) ;
V_137:
F_10 ( V_665 ) ;
F_56 ( V_66 ) ;
V_81:
if ( ! V_684 && V_686 == false )
F_532 ( V_12 ) ;
if ( V_176 && V_176 != - V_199 )
F_533 ( V_36 , V_176 , NULL ) ;
return V_176 ;
}
int F_534 ( struct V_123 * V_124 ,
struct V_63 * V_12 ,
struct V_67 * V_142 ,
struct V_67 * V_19 )
{
struct V_14 * V_36 = V_12 -> V_36 ;
struct V_65 * V_66 ;
struct V_664 * V_665 ;
int V_186 ;
int V_693 ;
int V_31 = 0 ;
int V_694 ;
F_35 ( V_12 -> V_301 . V_24 != V_661 ) ;
V_66 = F_37 () ;
if ( ! V_66 )
return - V_74 ;
V_665 = F_64 ( sizeof( * V_665 ) , V_97 ) ;
if ( ! V_665 ) {
F_56 ( V_66 ) ;
return - V_74 ;
}
F_535 ( V_19 ) ;
V_693 = F_251 ( V_19 ) ;
F_536 ( V_19 ) ;
V_66 -> V_82 [ V_693 ] = V_19 ;
V_66 -> V_83 [ V_693 ] = F_42 ( V_19 ) ;
F_535 ( V_142 ) ;
V_186 = F_251 ( V_142 ) ;
V_66 -> V_82 [ V_186 ] = V_142 ;
V_66 -> V_83 [ V_186 ] = 0 ;
V_66 -> V_677 [ V_186 ] = V_682 ;
V_665 -> V_126 [ V_693 ] = 1 ;
V_665 -> V_7 [ V_693 ] = V_140 ;
V_665 -> V_186 = V_186 ;
V_665 -> V_681 = - 1 ;
V_665 -> V_670 = V_672 ;
V_665 -> V_673 = 0 ;
V_665 -> V_194 = 1 ;
V_665 -> V_684 = 1 ;
V_665 -> V_669 = F_499 ( V_36 ) ;
while ( 1 ) {
V_694 = F_515 ( V_124 , V_12 , V_66 , V_665 ) ;
if ( V_694 < 0 ) {
V_31 = V_694 ;
break;
}
V_694 = F_516 ( V_124 , V_12 , V_66 , V_665 , V_693 ) ;
if ( V_694 < 0 )
V_31 = V_694 ;
if ( V_694 != 0 )
break;
}
F_10 ( V_665 ) ;
F_56 ( V_66 ) ;
return V_31 ;
}
static T_2 F_537 ( struct V_14 * V_36 , T_2 V_7 )
{
T_2 V_393 ;
T_2 V_695 ;
V_695 = F_310 ( V_36 , V_7 ) ;
if ( V_695 )
return F_312 ( V_695 ) ;
V_393 = V_36 -> V_394 -> V_395 ;
V_695 = V_404 |
V_403 | V_402 |
V_375 | V_376 ;
if ( V_393 == 1 ) {
V_695 |= V_374 ;
V_695 = V_7 & ~ V_695 ;
if ( V_7 & V_404 )
return V_695 ;
if ( V_7 & ( V_375 |
V_376 ) )
return V_695 | V_374 ;
} else {
if ( V_7 & V_695 )
return V_7 ;
V_695 |= V_374 ;
V_695 = V_7 & ~ V_695 ;
if ( V_7 & V_374 )
return V_695 | V_375 ;
}
return V_7 ;
}
static int F_538 ( struct V_1 * V_2 , int V_429 )
{
struct V_110 * V_428 = V_2 -> V_94 ;
T_2 V_37 ;
T_2 V_696 ;
int V_31 = - V_334 ;
if ( ( V_428 -> V_7 &
( V_119 | V_53 ) ) &&
! V_429 )
V_696 = V_324 ;
else
V_696 = 0 ;
F_12 ( & V_428 -> V_50 ) ;
F_12 ( & V_2 -> V_50 ) ;
if ( V_2 -> V_327 ) {
V_2 -> V_327 ++ ;
V_31 = 0 ;
goto V_81;
}
V_37 = V_2 -> V_23 . V_35 - V_2 -> V_10 - V_2 -> V_9 -
V_2 -> V_45 - F_61 ( & V_2 -> V_95 ) ;
if ( F_320 ( V_428 , true ) + V_37 +
V_696 <= V_428 -> V_371 ) {
V_428 -> V_372 += V_37 ;
V_2 -> V_327 ++ ;
F_75 ( & V_2 -> V_697 , & V_428 -> V_364 ) ;
V_31 = 0 ;
}
V_81:
F_14 ( & V_2 -> V_50 ) ;
F_14 ( & V_428 -> V_50 ) ;
return V_31 ;
}
int F_539 ( struct V_14 * V_36 ,
struct V_1 * V_2 )
{
struct V_123 * V_124 ;
T_2 V_698 ;
int V_31 ;
V_178:
V_124 = F_224 ( V_36 -> V_64 ) ;
if ( F_225 ( V_124 ) )
return F_226 ( V_124 ) ;
F_52 ( & V_36 -> V_699 ) ;
if ( F_234 ( V_700 , & V_124 -> V_141 -> V_7 ) ) {
T_2 V_288 = V_124 -> V_288 ;
F_50 ( & V_36 -> V_699 ) ;
F_228 ( V_124 ) ;
V_31 = F_540 ( V_36 , V_288 ) ;
if ( V_31 )
return V_31 ;
goto V_178;
}
V_698 = F_537 ( V_36 , V_2 -> V_7 ) ;
if ( V_698 != V_2 -> V_7 ) {
V_31 = F_323 ( V_124 , V_36 , V_698 ,
V_420 ) ;
if ( V_31 == - V_334 )
V_31 = 0 ;
if ( V_31 < 0 )
goto V_81;
}
V_31 = F_538 ( V_2 , 0 ) ;
if ( ! V_31 )
goto V_81;
V_698 = F_313 ( V_36 , V_2 -> V_94 -> V_7 ) ;
V_31 = F_323 ( V_124 , V_36 , V_698 ,
V_420 ) ;
if ( V_31 < 0 )
goto V_81;
V_31 = F_538 ( V_2 , 0 ) ;
V_81:
if ( V_2 -> V_7 & V_119 ) {
V_698 = F_537 ( V_36 , V_2 -> V_7 ) ;
F_52 ( & V_36 -> V_437 ) ;
F_342 ( V_124 , V_36 , V_698 ) ;
F_50 ( & V_36 -> V_437 ) ;
}
F_50 ( & V_36 -> V_699 ) ;
F_228 ( V_124 ) ;
return V_31 ;
}
int F_541 ( struct V_123 * V_124 ,
struct V_14 * V_36 , T_2 type )
{
T_2 V_698 = F_313 ( V_36 , type ) ;
return F_323 ( V_124 , V_36 , V_698 , V_420 ) ;
}
T_2 F_542 ( struct V_110 * V_428 )
{
struct V_1 * V_16 ;
T_2 V_701 = 0 ;
int V_373 ;
if ( F_191 ( & V_428 -> V_364 ) )
return 0 ;
F_12 ( & V_428 -> V_50 ) ;
F_242 (block_group, &sinfo->ro_bgs, ro_list) {
F_12 ( & V_16 -> V_50 ) ;
if ( ! V_16 -> V_327 ) {
F_14 ( & V_16 -> V_50 ) ;
continue;
}
if ( V_16 -> V_7 & ( V_375 |
V_376 |
V_374 ) )
V_373 = 2 ;
else
V_373 = 1 ;
V_701 += ( V_16 -> V_23 . V_35 -
F_61 ( & V_16 -> V_95 ) ) *
V_373 ;
F_14 ( & V_16 -> V_50 ) ;
}
F_14 ( & V_428 -> V_50 ) ;
return V_701 ;
}
void F_543 ( struct V_1 * V_2 )
{
struct V_110 * V_428 = V_2 -> V_94 ;
T_2 V_37 ;
F_35 ( ! V_2 -> V_327 ) ;
F_12 ( & V_428 -> V_50 ) ;
F_12 ( & V_2 -> V_50 ) ;
if ( ! -- V_2 -> V_327 ) {
V_37 = V_2 -> V_23 . V_35 - V_2 -> V_10 -
V_2 -> V_9 - V_2 -> V_45 -
F_61 ( & V_2 -> V_95 ) ;
V_428 -> V_372 -= V_37 ;
F_283 ( & V_2 -> V_697 ) ;
}
F_14 ( & V_2 -> V_50 ) ;
F_14 ( & V_428 -> V_50 ) ;
}
int F_544 ( struct V_14 * V_36 , T_2 V_29 )
{
struct V_63 * V_12 = V_36 -> V_64 ;
struct V_1 * V_16 ;
struct V_110 * V_94 ;
struct V_702 * V_394 = V_36 -> V_394 ;
struct V_703 * V_704 ;
struct V_123 * V_124 ;
T_2 V_705 ;
T_2 V_706 = 1 ;
T_2 V_707 = 0 ;
T_2 V_388 ;
int V_708 ;
int V_613 ;
int V_122 = 0 ;
int V_31 = 0 ;
V_708 = F_272 ( V_36 , V_438 ) ;
V_16 = F_79 ( V_36 , V_29 ) ;
if ( ! V_16 ) {
if ( V_708 )
F_441 ( V_36 ,
L_42 ,
V_29 ) ;
return - 1 ;
}
V_705 = F_61 ( & V_16 -> V_95 ) ;
if ( ! V_705 )
goto V_81;
V_94 = V_16 -> V_94 ;
F_12 ( & V_94 -> V_50 ) ;
V_122 = V_94 -> V_122 ;
if ( ( V_94 -> V_371 != V_16 -> V_23 . V_35 ) &&
( F_320 ( V_94 , false ) + V_705 <
V_94 -> V_371 ) ) {
F_14 ( & V_94 -> V_50 ) ;
goto V_81;
}
F_14 ( & V_94 -> V_50 ) ;
V_31 = - 1 ;
V_388 = F_310 ( V_36 , V_16 -> V_7 ) ;
if ( V_388 ) {
V_613 = F_453 ( F_312 ( V_388 ) ) ;
} else {
if ( V_122 ) {
if ( V_708 )
F_441 ( V_36 ,
L_43 ,
V_16 -> V_23 . V_24 ) ;
goto V_81;
}
V_613 = F_454 ( V_16 ) ;
}
if ( V_613 == V_596 ) {
V_706 = 4 ;
V_705 >>= 1 ;
} else if ( V_613 == V_597 ) {
V_706 = 2 ;
} else if ( V_613 == V_598 ) {
V_705 <<= 1 ;
} else if ( V_613 == V_599 ) {
V_706 = V_394 -> V_395 ;
V_705 = F_215 ( V_705 , V_706 ) ;
}
V_124 = F_224 ( V_12 ) ;
if ( F_225 ( V_124 ) ) {
V_31 = F_226 ( V_124 ) ;
goto V_81;
}
F_52 ( & V_36 -> V_437 ) ;
F_242 (device, &fs_devices->alloc_list, dev_alloc_list) {
T_2 V_709 ;
if ( V_704 -> V_371 > V_704 -> V_93 + V_705 &&
! V_704 -> V_710 ) {
V_31 = F_545 ( V_124 , V_704 , V_705 ,
& V_709 , NULL ) ;
if ( ! V_31 )
V_707 ++ ;
if ( V_707 >= V_706 )
break;
V_31 = - 1 ;
}
}
if ( V_708 && V_31 == - 1 )
F_441 ( V_36 ,
L_44 ,
V_16 -> V_23 . V_24 ) ;
F_50 ( & V_36 -> V_437 ) ;
F_228 ( V_124 ) ;
V_81:
F_6 ( V_16 ) ;
return V_31 ;
}
static int F_546 ( struct V_14 * V_36 ,
struct V_65 * V_66 ,
struct V_69 * V_23 )
{
struct V_63 * V_12 = V_36 -> V_64 ;
int V_31 = 0 ;
struct V_69 V_152 ;
struct V_67 * V_68 ;
int V_666 ;
V_31 = F_41 ( NULL , V_12 , V_23 , V_66 , 0 , 0 ) ;
if ( V_31 < 0 )
goto V_81;
while ( 1 ) {
V_666 = V_66 -> V_83 [ 0 ] ;
V_68 = V_66 -> V_82 [ 0 ] ;
if ( V_666 >= F_42 ( V_68 ) ) {
V_31 = F_54 ( V_12 , V_66 ) ;
if ( V_31 == 0 )
continue;
if ( V_31 < 0 )
goto V_81;
break;
}
F_44 ( V_68 , & V_152 , V_666 ) ;
if ( V_152 . V_24 >= V_23 -> V_24 &&
V_152 . type == V_200 ) {
struct V_711 * V_712 ;
struct V_713 * V_714 ;
V_712 = & V_12 -> V_36 -> V_715 . V_716 ;
F_547 ( & V_712 -> V_50 ) ;
V_714 = F_548 ( V_712 , V_152 . V_24 ,
V_152 . V_35 ) ;
F_549 ( & V_712 -> V_50 ) ;
if ( ! V_714 ) {
F_114 ( V_36 ,
L_45 ,
V_152 . V_24 , V_152 . V_35 ) ;
V_31 = - V_177 ;
} else {
V_31 = 0 ;
}
F_550 ( V_714 ) ;
goto V_81;
}
V_66 -> V_83 [ 0 ] ++ ;
}
V_81:
return V_31 ;
}
void F_551 ( struct V_14 * V_15 )
{
struct V_1 * V_16 ;
T_2 V_71 = 0 ;
while ( 1 ) {
struct V_316 * V_316 ;
V_16 = F_78 ( V_15 , V_71 ) ;
while ( V_16 ) {
F_12 ( & V_16 -> V_50 ) ;
if ( V_16 -> V_159 )
break;
F_14 ( & V_16 -> V_50 ) ;
V_16 = F_262 ( V_15 , V_16 ) ;
}
if ( ! V_16 ) {
if ( V_71 == 0 )
break;
V_71 = 0 ;
continue;
}
V_316 = V_16 -> V_316 ;
V_16 -> V_159 = 0 ;
V_16 -> V_316 = NULL ;
F_14 ( & V_16 -> V_50 ) ;
ASSERT ( V_16 -> V_350 . V_316 == NULL ) ;
F_276 ( V_316 ) ;
V_71 = V_16 -> V_23 . V_24 + V_16 -> V_23 . V_35 ;
F_6 ( V_16 ) ;
}
}
int F_552 ( struct V_14 * V_15 )
{
struct V_1 * V_16 ;
struct V_110 * V_94 ;
struct V_48 * V_51 ;
struct V_17 * V_32 ;
F_74 ( & V_15 -> V_84 ) ;
while ( ! F_191 ( & V_15 -> V_108 ) ) {
V_51 = F_553 ( V_15 -> V_108 . V_80 ,
struct V_48 , V_98 ) ;
F_203 ( & V_51 -> V_98 ) ;
F_28 ( V_51 ) ;
}
F_76 ( & V_15 -> V_84 ) ;
F_12 ( & V_15 -> V_553 ) ;
while ( ! F_191 ( & V_15 -> V_555 ) ) {
V_16 = F_192 ( & V_15 -> V_555 ,
struct V_1 ,
V_554 ) ;
F_283 ( & V_16 -> V_554 ) ;
F_6 ( V_16 ) ;
}
F_14 ( & V_15 -> V_553 ) ;
F_12 ( & V_15 -> V_20 ) ;
while ( ( V_32 = F_209 ( & V_15 -> V_21 ) ) != NULL ) {
V_16 = F_13 ( V_32 , struct V_1 ,
V_22 ) ;
F_202 ( & V_16 -> V_22 ,
& V_15 -> V_21 ) ;
F_554 ( & V_16 -> V_22 ) ;
F_14 ( & V_15 -> V_20 ) ;
F_74 ( & V_16 -> V_94 -> V_361 ) ;
F_203 ( & V_16 -> V_98 ) ;
F_76 ( & V_16 -> V_94 -> V_361 ) ;
if ( V_16 -> V_3 == V_102 ||
V_16 -> V_3 == V_5 )
F_20 ( V_15 , V_16 ) ;
F_555 ( V_16 ) ;
ASSERT ( V_16 -> V_3 != V_106 ) ;
ASSERT ( F_191 ( & V_16 -> V_348 ) ) ;
ASSERT ( F_191 ( & V_16 -> V_349 ) ) ;
ASSERT ( F_191 ( & V_16 -> V_554 ) ) ;
ASSERT ( F_220 ( & V_16 -> V_8 ) == 1 ) ;
F_6 ( V_16 ) ;
F_12 ( & V_15 -> V_20 ) ;
}
F_14 ( & V_15 -> V_20 ) ;
F_556 () ;
F_398 ( V_15 ) ;
while ( ! F_191 ( & V_15 -> V_94 ) ) {
int V_42 ;
V_94 = F_553 ( V_15 -> V_94 . V_80 ,
struct V_110 ,
V_98 ) ;
if ( F_8 ( V_94 -> V_411 > 0 ||
V_94 -> V_410 > 0 ||
V_94 -> V_412 > 0 ) )
F_346 ( V_15 , V_94 , 0 , 0 ) ;
F_203 ( & V_94 -> V_98 ) ;
for ( V_42 = 0 ; V_42 < V_359 ; V_42 ++ ) {
struct V_717 * V_367 ;
V_367 = V_94 -> V_718 [ V_42 ] ;
V_94 -> V_718 [ V_42 ] = NULL ;
if ( V_367 ) {
F_557 ( V_367 ) ;
F_558 ( V_367 ) ;
}
}
F_557 ( & V_94 -> V_367 ) ;
F_558 ( & V_94 -> V_367 ) ;
}
return 0 ;
}
static void F_559 ( struct V_110 * V_94 ,
struct V_1 * V_2 )
{
int V_613 = F_454 ( V_2 ) ;
bool V_269 = false ;
F_74 ( & V_94 -> V_361 ) ;
if ( F_191 ( & V_94 -> V_360 [ V_613 ] ) )
V_269 = true ;
F_75 ( & V_2 -> V_98 , & V_94 -> V_360 [ V_613 ] ) ;
F_76 ( & V_94 -> V_361 ) ;
if ( V_269 ) {
struct V_719 * V_720 ;
int V_31 ;
V_720 = F_64 ( sizeof( * V_720 ) , V_97 ) ;
if ( ! V_720 )
goto V_721;
V_720 -> V_396 = V_613 ;
F_560 ( & V_720 -> V_367 , & V_722 ) ;
V_31 = F_561 ( & V_720 -> V_367 , & V_94 -> V_367 ,
L_10 , F_455 ( V_613 ) ) ;
if ( V_31 ) {
F_558 ( & V_720 -> V_367 ) ;
goto V_721;
}
V_94 -> V_718 [ V_613 ] = & V_720 -> V_367 ;
}
return;
V_721:
F_441 ( V_2 -> V_36 ,
L_46 ) ;
}
static struct V_1 *
F_562 ( struct V_14 * V_36 ,
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
V_2 -> V_23 . type = V_200 ;
V_2 -> V_36 = V_36 ;
V_2 -> V_723 = F_563 ( V_36 , V_34 ) ;
F_564 ( V_2 ) ;
F_565 ( & V_2 -> V_8 , 1 ) ;
F_300 ( & V_2 -> V_50 ) ;
F_299 ( & V_2 -> V_605 ) ;
F_65 ( & V_2 -> V_98 ) ;
F_65 ( & V_2 -> V_724 ) ;
F_65 ( & V_2 -> V_554 ) ;
F_65 ( & V_2 -> V_697 ) ;
F_65 ( & V_2 -> V_348 ) ;
F_65 ( & V_2 -> V_349 ) ;
F_566 ( V_2 ) ;
F_565 ( & V_2 -> V_725 , 0 ) ;
F_66 ( & V_2 -> V_726 ) ;
F_567 ( & V_2 -> V_11 ) ;
return V_2 ;
}
int F_568 ( struct V_14 * V_15 )
{
struct V_65 * V_66 ;
int V_31 ;
struct V_1 * V_2 ;
struct V_110 * V_94 ;
struct V_69 V_23 ;
struct V_69 V_152 ;
struct V_67 * V_68 ;
int V_727 = 0 ;
T_2 V_728 ;
T_2 V_729 ;
int V_730 ;
V_729 = F_569 ( V_15 -> V_275 ) ;
V_730 = ! ! ( V_729 & V_731 ) ;
V_23 . V_24 = 0 ;
V_23 . V_35 = 0 ;
V_23 . type = V_200 ;
V_66 = F_37 () ;
if ( ! V_66 )
return - V_74 ;
V_66 -> V_77 = V_78 ;
V_728 = F_570 ( V_15 -> V_275 ) ;
if ( F_272 ( V_15 , V_332 ) &&
F_571 ( V_15 -> V_275 ) != V_728 )
V_727 = 1 ;
if ( F_272 ( V_15 , V_732 ) )
V_727 = 1 ;
while ( 1 ) {
V_31 = F_546 ( V_15 , V_66 , & V_23 ) ;
if ( V_31 > 0 )
break;
if ( V_31 != 0 )
goto error;
V_68 = V_66 -> V_82 [ 0 ] ;
F_44 ( V_68 , & V_152 , V_66 -> V_83 [ 0 ] ) ;
V_2 = F_562 ( V_15 , V_152 . V_24 ,
V_152 . V_35 ) ;
if ( ! V_2 ) {
V_31 = - V_74 ;
goto error;
}
if ( V_727 ) {
if ( F_272 ( V_15 , V_332 ) )
V_2 -> V_325 = V_339 ;
}
F_572 ( V_68 , & V_2 -> V_95 ,
F_260 ( V_68 , V_66 -> V_83 [ 0 ] ) ,
sizeof( V_2 -> V_95 ) ) ;
V_2 -> V_7 = F_573 ( & V_2 -> V_95 ) ;
if ( ! V_730 &&
( ( V_2 -> V_7 & V_53 ) &&
( V_2 -> V_7 & V_120 ) ) ) {
F_114 ( V_15 ,
L_47 ,
V_2 -> V_23 . V_24 ) ;
V_31 = - V_196 ;
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
F_555 ( V_2 ) ;
F_6 ( V_2 ) ;
goto error;
}
F_574 ( V_15 , V_2 , 0 ) ;
F_304 ( V_15 , V_2 -> V_7 , V_152 . V_35 ,
F_61 ( & V_2 -> V_95 ) ,
V_2 -> V_45 , & V_94 ) ;
V_2 -> V_94 = V_94 ;
F_559 ( V_94 , V_2 ) ;
F_306 ( V_15 , V_2 -> V_7 ) ;
if ( F_575 ( V_15 , V_2 -> V_23 . V_24 ) ) {
F_538 ( V_2 , 1 ) ;
} else if ( F_61 ( & V_2 -> V_95 ) == 0 ) {
F_12 ( & V_15 -> V_553 ) ;
if ( F_191 ( & V_2 -> V_554 ) ) {
F_4 ( V_2 ) ;
F_75 ( & V_2 -> V_554 ,
& V_15 -> V_555 ) ;
}
F_14 ( & V_15 -> V_553 ) ;
}
}
F_82 (space_info, &info->space_info, list) {
if ( ! ( F_313 ( V_15 , V_94 -> V_7 ) &
( V_376 |
V_375 |
V_403 |
V_402 |
V_374 ) ) )
continue;
F_242 (cache,
&space_info->block_groups[BTRFS_RAID_RAID0],
list)
F_538 ( V_2 , 1 ) ;
F_242 (cache,
&space_info->block_groups[BTRFS_RAID_SINGLE],
list)
F_538 ( V_2 , 1 ) ;
}
F_397 ( V_15 ) ;
V_31 = 0 ;
error:
F_56 ( V_66 ) ;
return V_31 ;
}
void F_236 ( struct V_123 * V_124 ,
struct V_14 * V_36 )
{
struct V_1 * V_16 , * V_337 ;
struct V_63 * V_64 = V_36 -> V_64 ;
struct V_733 V_95 ;
struct V_69 V_23 ;
int V_31 = 0 ;
bool V_293 = V_124 -> V_293 ;
V_124 -> V_293 = false ;
F_279 (block_group, tmp, &trans->new_bgs, bg_list) {
if ( V_31 )
goto V_80;
F_12 ( & V_16 -> V_50 ) ;
memcpy ( & V_95 , & V_16 -> V_95 , sizeof( V_95 ) ) ;
memcpy ( & V_23 , & V_16 -> V_23 , sizeof( V_23 ) ) ;
F_14 ( & V_16 -> V_50 ) ;
V_31 = F_576 ( V_124 , V_64 , & V_23 , & V_95 ,
sizeof( V_95 ) ) ;
if ( V_31 )
F_171 ( V_124 , V_31 ) ;
V_31 = F_577 ( V_124 , V_36 , V_23 . V_24 ,
V_23 . V_35 ) ;
if ( V_31 )
F_171 ( V_124 , V_31 ) ;
F_578 ( V_124 , V_36 , V_16 ) ;
V_80:
F_283 ( & V_16 -> V_554 ) ;
}
V_124 -> V_293 = V_293 ;
}
int F_579 ( struct V_123 * V_124 ,
struct V_14 * V_36 , T_2 V_93 ,
T_2 type , T_2 V_734 , T_2 V_59 )
{
struct V_1 * V_2 ;
int V_31 ;
F_580 ( V_36 , V_124 ) ;
V_2 = F_562 ( V_36 , V_734 , V_59 ) ;
if ( ! V_2 )
return - V_74 ;
F_422 ( & V_2 -> V_95 , V_93 ) ;
F_581 ( & V_2 -> V_95 ,
V_735 ) ;
F_582 ( & V_2 -> V_95 , type ) ;
V_2 -> V_7 = type ;
V_2 -> V_105 = ( T_2 ) - 1 ;
V_2 -> V_3 = V_4 ;
V_2 -> V_736 = 1 ;
V_31 = F_22 ( V_36 , V_2 ) ;
if ( V_31 ) {
F_20 ( V_36 , V_2 ) ;
F_6 ( V_2 ) ;
return V_31 ;
}
F_32 ( V_2 , V_36 , V_734 , V_734 + V_59 ) ;
F_20 ( V_36 , V_2 ) ;
#ifdef F_39
if ( F_40 ( V_2 ) ) {
T_2 V_737 = V_59 - V_93 ;
V_93 += V_737 >> 1 ;
F_30 ( V_2 ) ;
}
#endif
V_2 -> V_94 = F_80 ( V_36 , V_2 -> V_7 ) ;
if ( ! V_2 -> V_94 ) {
V_31 = F_297 ( V_36 , V_2 -> V_7 ,
& V_2 -> V_94 ) ;
if ( V_31 ) {
F_555 ( V_2 ) ;
F_6 ( V_2 ) ;
return V_31 ;
}
}
V_31 = F_11 ( V_36 , V_2 ) ;
if ( V_31 ) {
F_555 ( V_2 ) ;
F_6 ( V_2 ) ;
return V_31 ;
}
F_574 ( V_36 , V_2 , 1 ) ;
F_304 ( V_36 , V_2 -> V_7 , V_59 , V_93 ,
V_2 -> V_45 , & V_2 -> V_94 ) ;
F_395 ( V_36 ) ;
F_559 ( V_2 -> V_94 , V_2 ) ;
F_75 ( & V_2 -> V_554 , & V_124 -> V_296 ) ;
F_306 ( V_36 , type ) ;
return 0 ;
}
static void F_583 ( struct V_14 * V_36 , T_2 V_7 )
{
T_2 V_379 = F_307 ( V_7 ) &
V_380 ;
F_308 ( & V_36 -> V_381 ) ;
if ( V_7 & V_120 )
V_36 -> V_382 &= ~ V_379 ;
if ( V_7 & V_53 )
V_36 -> V_383 &= ~ V_379 ;
if ( V_7 & V_119 )
V_36 -> V_384 &= ~ V_379 ;
F_309 ( & V_36 -> V_381 ) ;
}
int F_584 ( struct V_123 * V_124 ,
struct V_14 * V_36 , T_2 V_738 ,
struct V_713 * V_714 )
{
struct V_63 * V_12 = V_36 -> V_64 ;
struct V_65 * V_66 ;
struct V_1 * V_16 ;
struct V_563 * V_571 ;
struct V_63 * V_289 = V_36 -> V_289 ;
struct V_69 V_23 ;
struct V_316 * V_316 ;
struct V_717 * V_367 = NULL ;
int V_31 ;
int V_613 ;
int V_373 ;
struct V_48 * V_51 = NULL ;
bool V_739 ;
V_16 = F_79 ( V_36 , V_738 ) ;
F_35 ( ! V_16 ) ;
F_35 ( ! V_16 -> V_327 ) ;
F_20 ( V_36 , V_16 ) ;
memcpy ( & V_23 , & V_16 -> V_23 , sizeof( V_23 ) ) ;
V_613 = F_454 ( V_16 ) ;
if ( V_16 -> V_7 & ( V_374 |
V_375 |
V_376 ) )
V_373 = 2 ;
else
V_373 = 1 ;
V_571 = & V_36 -> V_569 ;
F_12 ( & V_571 -> V_607 ) ;
F_466 ( V_16 , V_571 ) ;
F_14 ( & V_571 -> V_607 ) ;
V_571 = & V_36 -> V_565 ;
F_12 ( & V_571 -> V_607 ) ;
F_466 ( V_16 , V_571 ) ;
F_14 ( & V_571 -> V_607 ) ;
V_66 = F_37 () ;
if ( ! V_66 ) {
V_31 = - V_74 ;
goto V_81;
}
V_316 = F_265 ( V_36 , V_16 , V_66 ) ;
F_52 ( & V_124 -> V_141 -> V_347 ) ;
F_12 ( & V_124 -> V_141 -> V_346 ) ;
if ( ! F_191 ( & V_16 -> V_349 ) ) {
F_283 ( & V_16 -> V_349 ) ;
F_8 ( ! F_225 ( V_316 ) && V_316 != V_16 -> V_350 . V_316 ) ;
F_14 ( & V_124 -> V_141 -> V_346 ) ;
F_284 ( V_124 , V_16 , V_66 ) ;
F_6 ( V_16 ) ;
F_12 ( & V_124 -> V_141 -> V_346 ) ;
}
if ( ! F_191 ( & V_16 -> V_348 ) ) {
F_283 ( & V_16 -> V_348 ) ;
F_6 ( V_16 ) ;
}
F_14 ( & V_124 -> V_141 -> V_346 ) ;
F_50 ( & V_124 -> V_141 -> V_347 ) ;
if ( ! F_225 ( V_316 ) ) {
V_31 = F_585 ( V_124 , F_268 ( V_316 ) ) ;
if ( V_31 ) {
F_586 ( V_316 ) ;
goto V_81;
}
F_587 ( V_316 ) ;
F_12 ( & V_16 -> V_50 ) ;
if ( V_16 -> V_159 ) {
V_16 -> V_159 = 0 ;
V_16 -> V_316 = NULL ;
F_14 ( & V_16 -> V_50 ) ;
F_276 ( V_316 ) ;
} else {
F_14 ( & V_16 -> V_50 ) ;
}
F_586 ( V_316 ) ;
}
V_23 . V_24 = V_740 ;
V_23 . V_35 = V_16 -> V_23 . V_24 ;
V_23 . type = 0 ;
V_31 = F_41 ( V_124 , V_289 , & V_23 , V_66 , - 1 , 1 ) ;
if ( V_31 < 0 )
goto V_81;
if ( V_31 > 0 )
F_48 ( V_66 ) ;
if ( V_31 == 0 ) {
V_31 = F_135 ( V_124 , V_289 , V_66 ) ;
if ( V_31 )
goto V_81;
F_48 ( V_66 ) ;
}
F_12 ( & V_36 -> V_20 ) ;
F_202 ( & V_16 -> V_22 ,
& V_36 -> V_21 ) ;
F_554 ( & V_16 -> V_22 ) ;
if ( V_36 -> V_28 == V_16 -> V_23 . V_24 )
V_36 -> V_28 = ( T_2 ) - 1 ;
F_14 ( & V_36 -> V_20 ) ;
F_74 ( & V_16 -> V_94 -> V_361 ) ;
F_283 ( & V_16 -> V_98 ) ;
if ( F_191 ( & V_16 -> V_94 -> V_360 [ V_613 ] ) ) {
V_367 = V_16 -> V_94 -> V_718 [ V_613 ] ;
V_16 -> V_94 -> V_718 [ V_613 ] = NULL ;
F_583 ( V_36 , V_16 -> V_7 ) ;
}
F_76 ( & V_16 -> V_94 -> V_361 ) ;
if ( V_367 ) {
F_557 ( V_367 ) ;
F_558 ( V_367 ) ;
}
if ( V_16 -> V_107 )
V_51 = F_26 ( V_16 ) ;
if ( V_16 -> V_3 == V_106 )
F_452 ( V_16 ) ;
if ( V_16 -> V_107 ) {
F_74 ( & V_36 -> V_84 ) ;
if ( ! V_51 ) {
struct V_48 * V_49 ;
F_242 (ctl,
&fs_info->caching_block_groups, list)
if ( V_49 -> V_16 == V_16 ) {
V_51 = V_49 ;
F_27 ( & V_51 -> V_8 ) ;
break;
}
}
if ( V_51 )
F_283 ( & V_51 -> V_98 ) ;
F_76 ( & V_36 -> V_84 ) ;
if ( V_51 ) {
F_28 ( V_51 ) ;
F_28 ( V_51 ) ;
}
}
F_12 ( & V_124 -> V_141 -> V_346 ) ;
if ( ! F_191 ( & V_16 -> V_348 ) ) {
F_8 ( 1 ) ;
}
if ( ! F_191 ( & V_16 -> V_349 ) ) {
F_8 ( 1 ) ;
}
F_14 ( & V_124 -> V_141 -> V_346 ) ;
F_555 ( V_16 ) ;
F_12 ( & V_16 -> V_94 -> V_50 ) ;
F_283 ( & V_16 -> V_697 ) ;
if ( F_272 ( V_36 , V_438 ) ) {
F_8 ( V_16 -> V_94 -> V_371
< V_16 -> V_23 . V_35 ) ;
F_8 ( V_16 -> V_94 -> V_372
< V_16 -> V_23 . V_35 ) ;
F_8 ( V_16 -> V_94 -> V_377
< V_16 -> V_23 . V_35 * V_373 ) ;
}
V_16 -> V_94 -> V_371 -= V_16 -> V_23 . V_35 ;
V_16 -> V_94 -> V_372 -= V_16 -> V_23 . V_35 ;
V_16 -> V_94 -> V_377 -= V_16 -> V_23 . V_35 * V_373 ;
F_14 ( & V_16 -> V_94 -> V_50 ) ;
memcpy ( & V_23 , & V_16 -> V_23 , sizeof( V_23 ) ) ;
F_52 ( & V_36 -> V_437 ) ;
if ( ! F_191 ( & V_714 -> V_98 ) ) {
F_550 ( V_714 ) ;
}
F_12 ( & V_16 -> V_50 ) ;
V_16 -> V_741 = 1 ;
V_739 = ( F_220 ( & V_16 -> V_725 ) == 0 ) ;
if ( ! V_739 ) {
F_588 ( & V_714 -> V_98 , & V_36 -> V_742 ) ;
}
F_14 ( & V_16 -> V_50 ) ;
if ( V_739 ) {
struct V_711 * V_712 ;
V_712 = & V_36 -> V_715 . V_716 ;
F_589 ( & V_712 -> V_50 ) ;
F_590 ( V_712 , V_714 ) ;
F_591 ( & V_712 -> V_50 ) ;
F_550 ( V_714 ) ;
}
F_50 ( & V_36 -> V_437 ) ;
V_31 = F_592 ( V_124 , V_36 , V_16 ) ;
if ( V_31 )
goto V_81;
F_6 ( V_16 ) ;
F_6 ( V_16 ) ;
V_31 = F_41 ( V_124 , V_12 , & V_23 , V_66 , - 1 , 1 ) ;
if ( V_31 > 0 )
V_31 = - V_195 ;
if ( V_31 < 0 )
goto V_81;
V_31 = F_135 ( V_124 , V_12 , V_66 ) ;
V_81:
F_56 ( V_66 ) ;
return V_31 ;
}
struct V_123 *
F_593 ( struct V_14 * V_36 ,
const T_2 V_734 )
{
struct V_711 * V_712 = & V_36 -> V_715 . V_716 ;
struct V_713 * V_714 ;
struct V_743 * V_744 ;
unsigned int V_745 ;
F_547 ( & V_712 -> V_50 ) ;
V_714 = F_548 ( V_712 , V_734 , 1 ) ;
F_549 ( & V_712 -> V_50 ) ;
ASSERT ( V_714 && V_714 -> V_34 == V_734 ) ;
V_744 = V_714 -> V_743 ;
V_745 = 3 + V_744 -> V_222 ;
F_550 ( V_714 ) ;
return F_594 ( V_36 -> V_64 ,
V_745 , 1 ) ;
}
void F_595 ( struct V_14 * V_36 )
{
struct V_1 * V_16 ;
struct V_110 * V_94 ;
struct V_123 * V_124 ;
int V_31 = 0 ;
if ( ! F_234 ( V_746 , & V_36 -> V_7 ) )
return;
F_12 ( & V_36 -> V_553 ) ;
while ( ! F_191 ( & V_36 -> V_555 ) ) {
T_2 V_34 , V_33 ;
int V_725 ;
V_16 = F_192 ( & V_36 -> V_555 ,
struct V_1 ,
V_554 ) ;
F_283 ( & V_16 -> V_554 ) ;
V_94 = V_16 -> V_94 ;
if ( V_31 || F_349 ( V_94 ) ) {
F_6 ( V_16 ) ;
continue;
}
F_14 ( & V_36 -> V_553 ) ;
F_52 ( & V_36 -> V_747 ) ;
F_74 ( & V_94 -> V_361 ) ;
F_12 ( & V_16 -> V_50 ) ;
if ( V_16 -> V_10 ||
F_61 ( & V_16 -> V_95 ) ||
V_16 -> V_327 ||
F_596 ( & V_16 -> V_98 ) ) {
F_14 ( & V_16 -> V_50 ) ;
F_76 ( & V_94 -> V_361 ) ;
goto V_80;
}
F_14 ( & V_16 -> V_50 ) ;
V_31 = F_538 ( V_16 , 0 ) ;
F_76 ( & V_94 -> V_361 ) ;
if ( V_31 < 0 ) {
V_31 = 0 ;
goto V_80;
}
V_124 = F_593 ( V_36 ,
V_16 -> V_23 . V_24 ) ;
if ( F_225 ( V_124 ) ) {
F_543 ( V_16 ) ;
V_31 = F_226 ( V_124 ) ;
goto V_80;
}
V_34 = V_16 -> V_23 . V_24 ;
V_33 = V_34 + V_16 -> V_23 . V_35 - 1 ;
F_52 ( & V_36 -> V_579 ) ;
V_31 = F_21 ( & V_36 -> V_38 [ 0 ] , V_34 , V_33 ,
V_62 ) ;
if ( V_31 ) {
F_50 ( & V_36 -> V_579 ) ;
F_543 ( V_16 ) ;
goto V_748;
}
V_31 = F_21 ( & V_36 -> V_38 [ 1 ] , V_34 , V_33 ,
V_62 ) ;
if ( V_31 ) {
F_50 ( & V_36 -> V_579 ) ;
F_543 ( V_16 ) ;
goto V_748;
}
F_50 ( & V_36 -> V_579 ) ;
F_12 ( & V_94 -> V_50 ) ;
F_12 ( & V_16 -> V_50 ) ;
V_94 -> V_411 -= V_16 -> V_9 ;
V_94 -> V_372 += V_16 -> V_9 ;
F_85 ( & V_94 -> V_121 ,
- V_16 -> V_9 ) ;
V_16 -> V_9 = 0 ;
F_14 ( & V_16 -> V_50 ) ;
F_14 ( & V_94 -> V_50 ) ;
V_725 = F_272 ( V_36 , V_580 ) ;
if ( V_725 )
F_597 ( V_16 ) ;
V_31 = F_598 ( V_124 , V_36 ,
V_16 -> V_23 . V_24 ) ;
if ( V_31 ) {
if ( V_725 )
F_439 ( V_16 ) ;
goto V_748;
}
if ( V_725 ) {
F_12 ( & V_36 -> V_553 ) ;
F_599 ( & V_16 -> V_554 ,
& V_124 -> V_141 -> V_576 ) ;
F_14 ( & V_36 -> V_553 ) ;
F_4 ( V_16 ) ;
}
V_748:
F_228 ( V_124 ) ;
V_80:
F_50 ( & V_36 -> V_747 ) ;
F_6 ( V_16 ) ;
F_12 ( & V_36 -> V_553 ) ;
}
F_14 ( & V_36 -> V_553 ) ;
}
int F_600 ( struct V_14 * V_36 )
{
struct V_110 * V_94 ;
struct V_749 * V_750 ;
T_2 V_751 ;
T_2 V_7 ;
int V_730 = 0 ;
int V_31 ;
V_750 = V_36 -> V_275 ;
if ( ! F_601 ( V_750 ) )
return - V_196 ;
V_751 = F_569 ( V_750 ) ;
if ( V_751 & V_731 )
V_730 = 1 ;
V_7 = V_119 ;
V_31 = F_297 ( V_36 , V_7 , & V_94 ) ;
if ( V_31 )
goto V_81;
if ( V_730 ) {
V_7 = V_53 | V_120 ;
V_31 = F_297 ( V_36 , V_7 , & V_94 ) ;
} else {
V_7 = V_53 ;
V_31 = F_297 ( V_36 , V_7 , & V_94 ) ;
if ( V_31 )
goto V_81;
V_7 = V_120 ;
V_31 = F_297 ( V_36 , V_7 , & V_94 ) ;
}
V_81:
return V_31 ;
}
int F_602 ( struct V_14 * V_36 ,
T_2 V_34 , T_2 V_33 )
{
return F_436 ( V_36 , V_34 , V_33 , false ) ;
}
static int F_603 ( struct V_703 * V_704 ,
T_2 V_752 , T_2 * V_581 )
{
T_2 V_34 = 0 , V_47 = 0 ;
int V_31 ;
* V_581 = 0 ;
if ( ! V_704 -> V_753 )
return 0 ;
if ( V_704 -> V_371 <= V_704 -> V_93 )
return 0 ;
V_31 = 0 ;
while ( 1 ) {
struct V_14 * V_36 = V_704 -> V_36 ;
struct V_298 * V_124 ;
T_2 V_223 ;
V_31 = F_604 ( & V_36 -> V_437 ) ;
if ( V_31 )
return V_31 ;
F_53 ( & V_36 -> V_84 ) ;
F_12 ( & V_36 -> V_754 ) ;
V_124 = V_36 -> V_300 ;
if ( V_124 )
F_27 ( & V_124 -> V_755 ) ;
F_14 ( & V_36 -> V_754 ) ;
V_31 = F_605 ( V_124 , V_704 , V_752 , V_34 ,
& V_34 , & V_47 ) ;
if ( V_124 )
F_606 ( V_124 ) ;
if ( V_31 ) {
F_49 ( & V_36 -> V_84 ) ;
F_50 ( & V_36 -> V_437 ) ;
if ( V_31 == - V_334 )
V_31 = 0 ;
break;
}
V_31 = F_157 ( V_704 -> V_206 , V_34 , V_47 , & V_223 ) ;
F_49 ( & V_36 -> V_84 ) ;
F_50 ( & V_36 -> V_437 ) ;
if ( V_31 )
break;
V_34 += V_47 ;
* V_581 += V_223 ;
if ( F_607 ( V_417 ) ) {
V_31 = - V_756 ;
break;
}
F_51 () ;
}
return V_31 ;
}
int F_608 ( struct V_14 * V_36 , struct V_757 * V_758 )
{
struct V_1 * V_2 = NULL ;
struct V_703 * V_704 ;
struct V_111 * V_759 ;
T_2 V_760 ;
T_2 V_34 ;
T_2 V_33 ;
T_2 V_581 = 0 ;
T_2 V_371 = F_338 ( V_36 -> V_275 ) ;
int V_31 = 0 ;
if ( V_758 -> V_47 == V_371 )
V_2 = F_78 ( V_36 , V_758 -> V_34 ) ;
else
V_2 = F_79 ( V_36 , V_758 -> V_34 ) ;
while ( V_2 ) {
if ( V_2 -> V_23 . V_24 >= ( V_758 -> V_34 + V_758 -> V_47 ) ) {
F_6 ( V_2 ) ;
break;
}
V_34 = F_463 ( V_758 -> V_34 , V_2 -> V_23 . V_24 ) ;
V_33 = F_359 ( V_758 -> V_34 + V_758 -> V_47 ,
V_2 -> V_23 . V_24 + V_2 -> V_23 . V_35 ) ;
if ( V_33 - V_34 >= V_758 -> V_752 ) {
if ( ! F_1 ( V_2 ) ) {
V_31 = F_62 ( V_2 , 0 ) ;
if ( V_31 ) {
F_6 ( V_2 ) ;
break;
}
V_31 = F_452 ( V_2 ) ;
if ( V_31 ) {
F_6 ( V_2 ) ;
break;
}
}
V_31 = F_609 ( V_2 ,
& V_760 ,
V_34 ,
V_33 ,
V_758 -> V_752 ) ;
V_581 += V_760 ;
if ( V_31 ) {
F_6 ( V_2 ) ;
break;
}
}
V_2 = F_262 ( V_36 , V_2 ) ;
}
F_52 ( & V_36 -> V_394 -> V_761 ) ;
V_759 = & V_36 -> V_394 -> V_762 ;
F_242 (device, devices, dev_alloc_list) {
V_31 = F_603 ( V_704 , V_758 -> V_752 ,
& V_760 ) ;
if ( V_31 )
break;
V_581 += V_760 ;
}
F_50 ( & V_36 -> V_394 -> V_761 ) ;
V_758 -> V_47 = V_581 ;
return V_31 ;
}
void F_610 ( struct V_63 * V_12 )
{
F_611 ( & V_12 -> V_763 -> V_764 ) ;
F_2 () ;
if ( F_612 ( & V_12 -> V_763 -> V_89 ) )
F_55 ( & V_12 -> V_763 -> V_89 ) ;
}
int F_613 ( struct V_63 * V_12 )
{
if ( F_220 ( & V_12 -> V_765 ) )
return 0 ;
F_614 ( & V_12 -> V_763 -> V_764 ) ;
F_2 () ;
if ( F_220 ( & V_12 -> V_765 ) ) {
F_610 ( V_12 ) ;
return 0 ;
}
return 1 ;
}
static int F_615 ( T_8 * V_356 )
{
F_71 () ;
return 0 ;
}
void F_616 ( struct V_63 * V_12 )
{
while ( true ) {
int V_31 ;
V_31 = F_613 ( V_12 ) ;
if ( V_31 )
break;
F_295 ( & V_12 -> V_765 ,
F_615 ,
V_101 ) ;
}
}
