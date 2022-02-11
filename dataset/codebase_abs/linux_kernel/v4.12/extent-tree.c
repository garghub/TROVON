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
void F_84 ( struct V_14 * V_15 )
{
struct V_111 * V_112 = & V_15 -> V_94 ;
struct V_110 * V_113 ;
F_81 () ;
F_82 (found, head, list)
V_113 -> V_115 = 0 ;
F_83 () ;
}
int F_85 ( struct V_14 * V_36 , T_2 V_34 , T_2 V_47 )
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
int F_86 ( struct V_116 * V_117 ,
struct V_14 * V_36 , T_2 V_29 ,
T_2 V_35 , int V_118 , T_2 * V_119 , T_2 * V_7 )
{
struct V_120 * V_112 ;
struct V_121 * V_122 ;
struct V_65 * V_66 ;
struct V_123 * V_124 ;
struct V_67 * V_68 ;
struct V_69 V_23 ;
T_3 V_125 ;
T_2 V_126 ;
T_2 V_127 ;
int V_31 ;
if ( V_118 && ! F_87 ( V_36 , V_128 ) ) {
V_35 = V_36 -> V_54 ;
V_118 = 0 ;
}
V_66 = F_37 () ;
if ( ! V_66 )
return - V_74 ;
if ( ! V_117 ) {
V_66 -> V_75 = 1 ;
V_66 -> V_76 = 1 ;
}
V_129:
V_23 . V_24 = V_29 ;
V_23 . V_35 = V_35 ;
if ( V_118 )
V_23 . type = V_87 ;
else
V_23 . type = V_79 ;
V_31 = F_41 ( V_117 , V_36 -> V_64 , & V_23 , V_66 , 0 , 0 ) ;
if ( V_31 < 0 )
goto V_130;
if ( V_31 > 0 && V_118 && V_23 . type == V_87 ) {
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
V_125 = F_88 ( V_68 , V_66 -> V_83 [ 0 ] ) ;
if ( V_125 >= sizeof( * V_124 ) ) {
V_124 = F_89 ( V_68 , V_66 -> V_83 [ 0 ] ,
struct V_123 ) ;
V_126 = F_90 ( V_68 , V_124 ) ;
V_127 = F_91 ( V_68 , V_124 ) ;
} else {
#ifdef F_92
struct V_131 * V_132 ;
F_35 ( V_125 != sizeof( * V_132 ) ) ;
V_132 = F_89 ( V_68 , V_66 -> V_83 [ 0 ] ,
struct V_131 ) ;
V_126 = F_93 ( V_68 , V_132 ) ;
V_127 = V_133 ;
#else
F_94 () ;
#endif
}
F_35 ( V_126 == 0 ) ;
} else {
V_126 = 0 ;
V_127 = 0 ;
V_31 = 0 ;
}
if ( ! V_117 )
goto V_81;
V_122 = & V_117 -> V_134 -> V_122 ;
F_12 ( & V_122 -> V_50 ) ;
V_112 = F_95 ( V_122 , V_29 ) ;
if ( V_112 ) {
if ( ! F_96 ( & V_112 -> V_86 ) ) {
F_27 ( & V_112 -> V_135 . V_119 ) ;
F_14 ( & V_122 -> V_50 ) ;
F_48 ( V_66 ) ;
F_52 ( & V_112 -> V_86 ) ;
F_50 ( & V_112 -> V_86 ) ;
F_97 ( & V_112 -> V_135 ) ;
goto V_129;
}
F_12 ( & V_112 -> V_50 ) ;
if ( V_112 -> V_136 && V_112 -> V_136 -> V_137 )
V_127 |= V_112 -> V_136 -> V_138 ;
else
F_35 ( V_126 == 0 ) ;
V_126 += V_112 -> V_135 . V_139 ;
F_14 ( & V_112 -> V_50 ) ;
F_50 ( & V_112 -> V_86 ) ;
}
F_14 ( & V_122 -> V_50 ) ;
V_81:
F_8 ( V_126 == 0 ) ;
if ( V_119 )
* V_119 = V_126 ;
if ( V_7 )
* V_7 = V_127 ;
V_130:
F_56 ( V_66 ) ;
return V_31 ;
}
static int F_98 ( struct V_116 * V_117 ,
struct V_14 * V_36 ,
struct V_65 * V_66 ,
T_2 V_140 , T_3 V_141 )
{
struct V_63 * V_12 = V_36 -> V_64 ;
struct V_123 * V_95 ;
struct V_131 * V_132 ;
struct V_142 * V_143 ;
struct V_144 * V_145 ;
struct V_67 * V_68 ;
struct V_69 V_23 ;
struct V_69 V_146 ;
T_3 V_147 = sizeof( * V_95 ) ;
T_2 V_119 ;
int V_31 ;
V_68 = V_66 -> V_82 [ 0 ] ;
F_35 ( F_88 ( V_68 , V_66 -> V_83 [ 0 ] ) != sizeof( * V_132 ) ) ;
F_44 ( V_68 , & V_23 , V_66 -> V_83 [ 0 ] ) ;
V_132 = F_89 ( V_68 , V_66 -> V_83 [ 0 ] ,
struct V_131 ) ;
V_119 = F_93 ( V_68 , V_132 ) ;
if ( V_140 == ( T_2 ) - 1 ) {
while ( 1 ) {
if ( V_66 -> V_83 [ 0 ] >= F_42 ( V_68 ) ) {
V_31 = F_54 ( V_12 , V_66 ) ;
if ( V_31 < 0 )
return V_31 ;
F_35 ( V_31 > 0 ) ;
V_68 = V_66 -> V_82 [ 0 ] ;
}
F_44 ( V_68 , & V_146 ,
V_66 -> V_83 [ 0 ] ) ;
F_35 ( V_23 . V_24 != V_146 . V_24 ) ;
if ( V_146 . type != V_148 ) {
V_66 -> V_83 [ 0 ] ++ ;
continue;
}
V_143 = F_89 ( V_68 , V_66 -> V_83 [ 0 ] ,
struct V_142 ) ;
V_140 = F_99 ( V_68 , V_143 ) ;
break;
}
}
F_48 ( V_66 ) ;
if ( V_140 < V_149 )
V_147 += sizeof( * V_145 ) ;
V_147 -= sizeof( * V_132 ) ;
V_31 = F_41 ( V_117 , V_12 , & V_23 , V_66 ,
V_147 + V_141 , 1 ) ;
if ( V_31 < 0 )
return V_31 ;
F_35 ( V_31 ) ;
F_100 ( V_36 , V_66 , V_147 ) ;
V_68 = V_66 -> V_82 [ 0 ] ;
V_95 = F_89 ( V_68 , V_66 -> V_83 [ 0 ] , struct V_123 ) ;
F_101 ( V_68 , V_95 , V_119 ) ;
F_102 ( V_68 , V_95 , 0 ) ;
if ( V_140 < V_149 ) {
F_103 ( V_68 , V_95 ,
V_150 |
V_133 ) ;
V_145 = (struct V_144 * ) ( V_95 + 1 ) ;
F_104 ( V_68 , ( unsigned long ) V_145 , sizeof( * V_145 ) ) ;
F_105 ( V_68 , V_145 , ( int ) V_140 ) ;
} else {
F_103 ( V_68 , V_95 , V_151 ) ;
}
F_106 ( V_68 ) ;
return 0 ;
}
static T_2 F_107 ( T_2 V_152 , T_2 V_140 , T_2 V_35 )
{
T_3 V_153 = ~ ( T_3 ) 0 ;
T_3 V_154 = ~ ( T_3 ) 0 ;
T_4 V_155 ;
V_155 = F_108 ( V_152 ) ;
V_153 = F_109 ( V_153 , & V_155 , sizeof( V_155 ) ) ;
V_155 = F_108 ( V_140 ) ;
V_154 = F_109 ( V_154 , & V_155 , sizeof( V_155 ) ) ;
V_155 = F_108 ( V_35 ) ;
V_154 = F_109 ( V_154 , & V_155 , sizeof( V_155 ) ) ;
return ( ( T_2 ) V_153 << 31 ) ^ ( T_2 ) V_154 ;
}
static T_2 F_110 ( struct V_67 * V_68 ,
struct V_156 * V_157 )
{
return F_107 ( F_111 ( V_68 , V_157 ) ,
F_112 ( V_68 , V_157 ) ,
F_113 ( V_68 , V_157 ) ) ;
}
static int F_114 ( struct V_67 * V_68 ,
struct V_156 * V_157 ,
T_2 V_152 , T_2 V_140 , T_2 V_35 )
{
if ( F_111 ( V_68 , V_157 ) != V_152 ||
F_112 ( V_68 , V_157 ) != V_140 ||
F_113 ( V_68 , V_157 ) != V_35 )
return 0 ;
return 1 ;
}
static T_1 int F_115 ( struct V_116 * V_117 ,
struct V_14 * V_36 ,
struct V_65 * V_66 ,
T_2 V_29 , T_2 V_19 ,
T_2 V_152 ,
T_2 V_140 , T_2 V_35 )
{
struct V_63 * V_12 = V_36 -> V_64 ;
struct V_69 V_23 ;
struct V_156 * V_157 ;
struct V_67 * V_68 ;
T_3 V_72 ;
int V_31 ;
int V_158 ;
int V_159 = - V_160 ;
V_23 . V_24 = V_29 ;
if ( V_19 ) {
V_23 . type = V_161 ;
V_23 . V_35 = V_19 ;
} else {
V_23 . type = V_162 ;
V_23 . V_35 = F_107 ( V_152 ,
V_140 , V_35 ) ;
}
V_163:
V_158 = 0 ;
V_31 = F_41 ( V_117 , V_12 , & V_23 , V_66 , - 1 , 1 ) ;
if ( V_31 < 0 ) {
V_159 = V_31 ;
goto V_164;
}
if ( V_19 ) {
if ( ! V_31 )
return 0 ;
#ifdef F_92
V_23 . type = V_148 ;
F_48 ( V_66 ) ;
V_31 = F_41 ( V_117 , V_12 , & V_23 , V_66 , - 1 , 1 ) ;
if ( V_31 < 0 ) {
V_159 = V_31 ;
goto V_164;
}
if ( ! V_31 )
return 0 ;
#endif
goto V_164;
}
V_68 = V_66 -> V_82 [ 0 ] ;
V_72 = F_42 ( V_68 ) ;
while ( 1 ) {
if ( V_66 -> V_83 [ 0 ] >= V_72 ) {
V_31 = F_54 ( V_12 , V_66 ) ;
if ( V_31 < 0 )
V_159 = V_31 ;
if ( V_31 )
goto V_164;
V_68 = V_66 -> V_82 [ 0 ] ;
V_72 = F_42 ( V_68 ) ;
V_158 = 1 ;
}
F_44 ( V_68 , & V_23 , V_66 -> V_83 [ 0 ] ) ;
if ( V_23 . V_24 != V_29 ||
V_23 . type != V_162 )
goto V_164;
V_157 = F_89 ( V_68 , V_66 -> V_83 [ 0 ] ,
struct V_156 ) ;
if ( F_114 ( V_68 , V_157 , V_152 ,
V_140 , V_35 ) ) {
if ( V_158 ) {
F_48 ( V_66 ) ;
goto V_163;
}
V_159 = 0 ;
break;
}
V_66 -> V_83 [ 0 ] ++ ;
}
V_164:
return V_159 ;
}
static T_1 int F_116 ( struct V_116 * V_117 ,
struct V_14 * V_36 ,
struct V_65 * V_66 ,
T_2 V_29 , T_2 V_19 ,
T_2 V_152 , T_2 V_140 ,
T_2 V_35 , int V_165 )
{
struct V_63 * V_12 = V_36 -> V_64 ;
struct V_69 V_23 ;
struct V_67 * V_68 ;
T_3 V_59 ;
T_3 V_126 ;
int V_31 ;
V_23 . V_24 = V_29 ;
if ( V_19 ) {
V_23 . type = V_161 ;
V_23 . V_35 = V_19 ;
V_59 = sizeof( struct V_166 ) ;
} else {
V_23 . type = V_162 ;
V_23 . V_35 = F_107 ( V_152 ,
V_140 , V_35 ) ;
V_59 = sizeof( struct V_156 ) ;
}
V_31 = F_117 ( V_117 , V_12 , V_66 , & V_23 , V_59 ) ;
if ( V_31 && V_31 != - V_27 )
goto V_164;
V_68 = V_66 -> V_82 [ 0 ] ;
if ( V_19 ) {
struct V_166 * V_157 ;
V_157 = F_89 ( V_68 , V_66 -> V_83 [ 0 ] ,
struct V_166 ) ;
if ( V_31 == 0 ) {
F_118 ( V_68 , V_157 , V_165 ) ;
} else {
V_126 = F_119 ( V_68 , V_157 ) ;
V_126 += V_165 ;
F_118 ( V_68 , V_157 , V_126 ) ;
}
} else {
struct V_156 * V_157 ;
while ( V_31 == - V_27 ) {
V_157 = F_89 ( V_68 , V_66 -> V_83 [ 0 ] ,
struct V_156 ) ;
if ( F_114 ( V_68 , V_157 , V_152 ,
V_140 , V_35 ) )
break;
F_48 ( V_66 ) ;
V_23 . V_35 ++ ;
V_31 = F_117 ( V_117 , V_12 , V_66 , & V_23 ,
V_59 ) ;
if ( V_31 && V_31 != - V_27 )
goto V_164;
V_68 = V_66 -> V_82 [ 0 ] ;
}
V_157 = F_89 ( V_68 , V_66 -> V_83 [ 0 ] ,
struct V_156 ) ;
if ( V_31 == 0 ) {
F_120 ( V_68 , V_157 ,
V_152 ) ;
F_121 ( V_68 , V_157 , V_140 ) ;
F_122 ( V_68 , V_157 , V_35 ) ;
F_123 ( V_68 , V_157 , V_165 ) ;
} else {
V_126 = F_124 ( V_68 , V_157 ) ;
V_126 += V_165 ;
F_123 ( V_68 , V_157 , V_126 ) ;
}
}
F_106 ( V_68 ) ;
V_31 = 0 ;
V_164:
F_48 ( V_66 ) ;
return V_31 ;
}
static T_1 int F_125 ( struct V_116 * V_117 ,
struct V_14 * V_36 ,
struct V_65 * V_66 ,
int V_167 , int * V_168 )
{
struct V_69 V_23 ;
struct V_156 * V_169 = NULL ;
struct V_166 * V_170 = NULL ;
struct V_67 * V_68 ;
T_3 V_126 = 0 ;
int V_31 = 0 ;
V_68 = V_66 -> V_82 [ 0 ] ;
F_44 ( V_68 , & V_23 , V_66 -> V_83 [ 0 ] ) ;
if ( V_23 . type == V_162 ) {
V_169 = F_89 ( V_68 , V_66 -> V_83 [ 0 ] ,
struct V_156 ) ;
V_126 = F_124 ( V_68 , V_169 ) ;
} else if ( V_23 . type == V_161 ) {
V_170 = F_89 ( V_68 , V_66 -> V_83 [ 0 ] ,
struct V_166 ) ;
V_126 = F_119 ( V_68 , V_170 ) ;
#ifdef F_92
} else if ( V_23 . type == V_148 ) {
struct V_142 * V_143 ;
V_143 = F_89 ( V_68 , V_66 -> V_83 [ 0 ] ,
struct V_142 ) ;
V_126 = F_126 ( V_68 , V_143 ) ;
#endif
} else {
F_94 () ;
}
F_35 ( V_126 < V_167 ) ;
V_126 -= V_167 ;
if ( V_126 == 0 ) {
V_31 = F_127 ( V_117 , V_36 -> V_64 , V_66 ) ;
* V_168 = 1 ;
} else {
if ( V_23 . type == V_162 )
F_123 ( V_68 , V_169 , V_126 ) ;
else if ( V_23 . type == V_161 )
F_118 ( V_68 , V_170 , V_126 ) ;
#ifdef F_92
else {
struct V_142 * V_143 ;
V_143 = F_89 ( V_68 , V_66 -> V_83 [ 0 ] ,
struct V_142 ) ;
F_128 ( V_68 , V_143 , V_126 ) ;
}
#endif
F_106 ( V_68 ) ;
}
return V_31 ;
}
static T_1 T_3 F_129 ( struct V_65 * V_66 ,
struct V_171 * V_172 )
{
struct V_69 V_23 ;
struct V_67 * V_68 ;
struct V_156 * V_169 ;
struct V_166 * V_170 ;
T_3 V_126 = 0 ;
V_68 = V_66 -> V_82 [ 0 ] ;
F_44 ( V_68 , & V_23 , V_66 -> V_83 [ 0 ] ) ;
if ( V_172 ) {
if ( F_130 ( V_68 , V_172 ) ==
V_162 ) {
V_169 = (struct V_156 * ) ( & V_172 -> V_35 ) ;
V_126 = F_124 ( V_68 , V_169 ) ;
} else {
V_170 = (struct V_166 * ) ( V_172 + 1 ) ;
V_126 = F_119 ( V_68 , V_170 ) ;
}
} else if ( V_23 . type == V_162 ) {
V_169 = F_89 ( V_68 , V_66 -> V_83 [ 0 ] ,
struct V_156 ) ;
V_126 = F_124 ( V_68 , V_169 ) ;
} else if ( V_23 . type == V_161 ) {
V_170 = F_89 ( V_68 , V_66 -> V_83 [ 0 ] ,
struct V_166 ) ;
V_126 = F_119 ( V_68 , V_170 ) ;
#ifdef F_92
} else if ( V_23 . type == V_148 ) {
struct V_142 * V_143 ;
V_143 = F_89 ( V_68 , V_66 -> V_83 [ 0 ] ,
struct V_142 ) ;
V_126 = F_126 ( V_68 , V_143 ) ;
#endif
} else {
F_8 ( 1 ) ;
}
return V_126 ;
}
static T_1 int F_131 ( struct V_116 * V_117 ,
struct V_14 * V_36 ,
struct V_65 * V_66 ,
T_2 V_29 , T_2 V_19 ,
T_2 V_152 )
{
struct V_63 * V_12 = V_36 -> V_64 ;
struct V_69 V_23 ;
int V_31 ;
V_23 . V_24 = V_29 ;
if ( V_19 ) {
V_23 . type = V_173 ;
V_23 . V_35 = V_19 ;
} else {
V_23 . type = V_174 ;
V_23 . V_35 = V_152 ;
}
V_31 = F_41 ( V_117 , V_12 , & V_23 , V_66 , - 1 , 1 ) ;
if ( V_31 > 0 )
V_31 = - V_160 ;
#ifdef F_92
if ( V_31 == - V_160 && V_19 ) {
F_48 ( V_66 ) ;
V_23 . type = V_148 ;
V_31 = F_41 ( V_117 , V_12 , & V_23 , V_66 , - 1 , 1 ) ;
if ( V_31 > 0 )
V_31 = - V_160 ;
}
#endif
return V_31 ;
}
static T_1 int F_132 ( struct V_116 * V_117 ,
struct V_14 * V_36 ,
struct V_65 * V_66 ,
T_2 V_29 , T_2 V_19 ,
T_2 V_152 )
{
struct V_69 V_23 ;
int V_31 ;
V_23 . V_24 = V_29 ;
if ( V_19 ) {
V_23 . type = V_173 ;
V_23 . V_35 = V_19 ;
} else {
V_23 . type = V_174 ;
V_23 . V_35 = V_152 ;
}
V_31 = F_117 ( V_117 , V_36 -> V_64 ,
V_66 , & V_23 , 0 ) ;
F_48 ( V_66 ) ;
return V_31 ;
}
static inline int F_133 ( T_2 V_19 , T_2 V_140 )
{
int type ;
if ( V_140 < V_149 ) {
if ( V_19 > 0 )
type = V_173 ;
else
type = V_174 ;
} else {
if ( V_19 > 0 )
type = V_161 ;
else
type = V_162 ;
}
return type ;
}
static int F_45 ( struct V_65 * V_66 , int V_175 ,
struct V_69 * V_23 )
{
for (; V_175 < V_176 ; V_175 ++ ) {
if ( ! V_66 -> V_82 [ V_175 ] )
break;
if ( V_66 -> V_83 [ V_175 ] + 1 >=
F_42 ( V_66 -> V_82 [ V_175 ] ) )
continue;
if ( V_175 == 0 )
F_44 ( V_66 -> V_82 [ V_175 ] , V_23 ,
V_66 -> V_83 [ V_175 ] + 1 ) ;
else
F_134 ( V_66 -> V_82 [ V_175 ] , V_23 ,
V_66 -> V_83 [ V_175 ] + 1 ) ;
return 0 ;
}
return 1 ;
}
static T_5
int F_135 ( struct V_116 * V_117 ,
struct V_14 * V_36 ,
struct V_65 * V_66 ,
struct V_171 * * V_177 ,
T_2 V_29 , T_2 V_37 ,
T_2 V_19 , T_2 V_152 ,
T_2 V_140 , T_2 V_35 , int V_178 )
{
struct V_63 * V_12 = V_36 -> V_64 ;
struct V_69 V_23 ;
struct V_67 * V_68 ;
struct V_123 * V_124 ;
struct V_171 * V_172 ;
T_2 V_7 ;
T_2 V_125 ;
unsigned long V_179 ;
unsigned long V_33 ;
int V_141 ;
int type ;
int V_180 ;
int V_31 ;
int V_159 = 0 ;
bool V_181 = F_87 ( V_36 , V_128 ) ;
V_23 . V_24 = V_29 ;
V_23 . type = V_79 ;
V_23 . V_35 = V_37 ;
V_180 = F_133 ( V_19 , V_140 ) ;
if ( V_178 ) {
V_141 = F_136 ( V_180 ) ;
V_66 -> V_182 = 1 ;
} else
V_141 = - 1 ;
if ( V_181 && V_140 < V_149 ) {
V_23 . type = V_87 ;
V_23 . V_35 = V_140 ;
}
V_163:
V_31 = F_41 ( V_117 , V_12 , & V_23 , V_66 , V_141 , 1 ) ;
if ( V_31 < 0 ) {
V_159 = V_31 ;
goto V_81;
}
if ( V_31 > 0 && V_181 ) {
V_181 = false ;
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
goto V_163;
}
}
if ( V_31 && ! V_178 ) {
V_159 = - V_160 ;
goto V_81;
} else if ( F_8 ( V_31 ) ) {
V_159 = - V_183 ;
goto V_81;
}
V_68 = V_66 -> V_82 [ 0 ] ;
V_125 = F_88 ( V_68 , V_66 -> V_83 [ 0 ] ) ;
#ifdef F_92
if ( V_125 < sizeof( * V_124 ) ) {
if ( ! V_178 ) {
V_159 = - V_160 ;
goto V_81;
}
V_31 = F_98 ( V_117 , V_36 , V_66 , V_140 ,
V_141 ) ;
if ( V_31 < 0 ) {
V_159 = V_31 ;
goto V_81;
}
V_68 = V_66 -> V_82 [ 0 ] ;
V_125 = F_88 ( V_68 , V_66 -> V_83 [ 0 ] ) ;
}
#endif
F_35 ( V_125 < sizeof( * V_124 ) ) ;
V_124 = F_89 ( V_68 , V_66 -> V_83 [ 0 ] , struct V_123 ) ;
V_7 = F_91 ( V_68 , V_124 ) ;
V_179 = ( unsigned long ) ( V_124 + 1 ) ;
V_33 = ( unsigned long ) V_124 + V_125 ;
if ( V_7 & V_150 && ! V_181 ) {
V_179 += sizeof( struct V_144 ) ;
F_35 ( V_179 > V_33 ) ;
}
V_159 = - V_160 ;
while ( 1 ) {
if ( V_179 >= V_33 ) {
F_8 ( V_179 > V_33 ) ;
break;
}
V_172 = (struct V_171 * ) V_179 ;
type = F_130 ( V_68 , V_172 ) ;
if ( V_180 < type )
break;
if ( V_180 > type ) {
V_179 += F_136 ( type ) ;
continue;
}
if ( type == V_162 ) {
struct V_156 * V_184 ;
V_184 = (struct V_156 * ) ( & V_172 -> V_35 ) ;
if ( F_114 ( V_68 , V_184 , V_152 ,
V_140 , V_35 ) ) {
V_159 = 0 ;
break;
}
if ( F_110 ( V_68 , V_184 ) <
F_107 ( V_152 , V_140 , V_35 ) )
break;
} else {
T_2 V_185 ;
V_185 = F_137 ( V_68 , V_172 ) ;
if ( V_19 > 0 ) {
if ( V_19 == V_185 ) {
V_159 = 0 ;
break;
}
if ( V_185 < V_19 )
break;
} else {
if ( V_152 == V_185 ) {
V_159 = 0 ;
break;
}
if ( V_185 < V_152 )
break;
}
}
V_179 += F_136 ( type ) ;
}
if ( V_159 == - V_160 && V_178 ) {
if ( V_125 + V_141 >=
F_138 ( V_12 ) ) {
V_159 = - V_186 ;
goto V_81;
}
if ( F_45 ( V_66 , 0 , & V_23 ) == 0 &&
V_23 . V_24 == V_29 &&
V_23 . type < V_187 ) {
V_159 = - V_186 ;
goto V_81;
}
}
* V_177 = (struct V_171 * ) V_179 ;
V_81:
if ( V_178 ) {
V_66 -> V_182 = 0 ;
F_139 ( V_66 , 1 ) ;
}
return V_159 ;
}
static T_5
void F_140 ( struct V_14 * V_36 ,
struct V_65 * V_66 ,
struct V_171 * V_172 ,
T_2 V_19 , T_2 V_152 ,
T_2 V_140 , T_2 V_35 , int V_165 ,
struct V_188 * V_136 )
{
struct V_67 * V_68 ;
struct V_123 * V_124 ;
unsigned long V_179 ;
unsigned long V_33 ;
unsigned long V_189 ;
T_2 V_119 ;
int V_59 ;
int type ;
V_68 = V_66 -> V_82 [ 0 ] ;
V_124 = F_89 ( V_68 , V_66 -> V_83 [ 0 ] , struct V_123 ) ;
V_189 = ( unsigned long ) V_172 - ( unsigned long ) V_124 ;
type = F_133 ( V_19 , V_140 ) ;
V_59 = F_136 ( type ) ;
F_100 ( V_36 , V_66 , V_59 ) ;
V_124 = F_89 ( V_68 , V_66 -> V_83 [ 0 ] , struct V_123 ) ;
V_119 = F_90 ( V_68 , V_124 ) ;
V_119 += V_165 ;
F_101 ( V_68 , V_124 , V_119 ) ;
if ( V_136 )
F_141 ( V_136 , V_68 , V_124 ) ;
V_179 = ( unsigned long ) V_124 + V_189 ;
V_33 = ( unsigned long ) V_124 + F_88 ( V_68 , V_66 -> V_83 [ 0 ] ) ;
if ( V_179 < V_33 - V_59 )
F_142 ( V_68 , V_179 + V_59 , V_179 ,
V_33 - V_59 - V_179 ) ;
V_172 = (struct V_171 * ) V_179 ;
F_143 ( V_68 , V_172 , type ) ;
if ( type == V_162 ) {
struct V_156 * V_184 ;
V_184 = (struct V_156 * ) ( & V_172 -> V_35 ) ;
F_120 ( V_68 , V_184 , V_152 ) ;
F_121 ( V_68 , V_184 , V_140 ) ;
F_122 ( V_68 , V_184 , V_35 ) ;
F_123 ( V_68 , V_184 , V_165 ) ;
} else if ( type == V_161 ) {
struct V_166 * V_190 ;
V_190 = (struct V_166 * ) ( V_172 + 1 ) ;
F_118 ( V_68 , V_190 , V_165 ) ;
F_144 ( V_68 , V_172 , V_19 ) ;
} else if ( type == V_173 ) {
F_144 ( V_68 , V_172 , V_19 ) ;
} else {
F_144 ( V_68 , V_172 , V_152 ) ;
}
F_106 ( V_68 ) ;
}
static int F_145 ( struct V_116 * V_117 ,
struct V_14 * V_36 ,
struct V_65 * V_66 ,
struct V_171 * * V_177 ,
T_2 V_29 , T_2 V_37 , T_2 V_19 ,
T_2 V_152 , T_2 V_140 , T_2 V_35 )
{
int V_31 ;
V_31 = F_135 ( V_117 , V_36 , V_66 , V_177 ,
V_29 , V_37 , V_19 ,
V_152 , V_140 , V_35 , 0 ) ;
if ( V_31 != - V_160 )
return V_31 ;
F_48 ( V_66 ) ;
* V_177 = NULL ;
if ( V_140 < V_149 ) {
V_31 = F_131 ( V_117 , V_36 , V_66 , V_29 ,
V_19 , V_152 ) ;
} else {
V_31 = F_115 ( V_117 , V_36 , V_66 , V_29 ,
V_19 , V_152 , V_140 ,
V_35 ) ;
}
return V_31 ;
}
static T_5
void F_146 ( struct V_14 * V_36 ,
struct V_65 * V_66 ,
struct V_171 * V_172 ,
int V_191 ,
struct V_188 * V_136 ,
int * V_168 )
{
struct V_67 * V_68 ;
struct V_123 * V_124 ;
struct V_156 * V_184 = NULL ;
struct V_166 * V_190 = NULL ;
unsigned long V_179 ;
unsigned long V_33 ;
T_3 V_125 ;
int V_59 ;
int type ;
T_2 V_119 ;
V_68 = V_66 -> V_82 [ 0 ] ;
V_124 = F_89 ( V_68 , V_66 -> V_83 [ 0 ] , struct V_123 ) ;
V_119 = F_90 ( V_68 , V_124 ) ;
F_8 ( V_191 < 0 && V_119 + V_191 <= 0 ) ;
V_119 += V_191 ;
F_101 ( V_68 , V_124 , V_119 ) ;
if ( V_136 )
F_141 ( V_136 , V_68 , V_124 ) ;
type = F_130 ( V_68 , V_172 ) ;
if ( type == V_162 ) {
V_184 = (struct V_156 * ) ( & V_172 -> V_35 ) ;
V_119 = F_124 ( V_68 , V_184 ) ;
} else if ( type == V_161 ) {
V_190 = (struct V_166 * ) ( V_172 + 1 ) ;
V_119 = F_119 ( V_68 , V_190 ) ;
} else {
V_119 = 1 ;
F_35 ( V_191 != - 1 ) ;
}
F_35 ( V_191 < 0 && V_119 < - V_191 ) ;
V_119 += V_191 ;
if ( V_119 > 0 ) {
if ( type == V_162 )
F_123 ( V_68 , V_184 , V_119 ) ;
else
F_118 ( V_68 , V_190 , V_119 ) ;
} else {
* V_168 = 1 ;
V_59 = F_136 ( type ) ;
V_125 = F_88 ( V_68 , V_66 -> V_83 [ 0 ] ) ;
V_179 = ( unsigned long ) V_172 ;
V_33 = ( unsigned long ) V_124 + V_125 ;
if ( V_179 + V_59 < V_33 )
F_142 ( V_68 , V_179 , V_179 + V_59 ,
V_33 - V_179 - V_59 ) ;
V_125 -= V_59 ;
F_147 ( V_36 , V_66 , V_125 , 1 ) ;
}
F_106 ( V_68 ) ;
}
static T_5
int F_148 ( struct V_116 * V_117 ,
struct V_14 * V_36 ,
struct V_65 * V_66 ,
T_2 V_29 , T_2 V_37 , T_2 V_19 ,
T_2 V_152 , T_2 V_140 ,
T_2 V_35 , int V_165 ,
struct V_188 * V_136 )
{
struct V_171 * V_172 ;
int V_31 ;
V_31 = F_135 ( V_117 , V_36 , V_66 , & V_172 ,
V_29 , V_37 , V_19 ,
V_152 , V_140 , V_35 , 1 ) ;
if ( V_31 == 0 ) {
F_35 ( V_140 < V_149 ) ;
F_146 ( V_36 , V_66 , V_172 ,
V_165 , V_136 , NULL ) ;
} else if ( V_31 == - V_160 ) {
F_140 ( V_36 , V_66 , V_172 , V_19 ,
V_152 , V_140 , V_35 ,
V_165 , V_136 ) ;
V_31 = 0 ;
}
return V_31 ;
}
static int F_149 ( struct V_116 * V_117 ,
struct V_14 * V_36 ,
struct V_65 * V_66 ,
T_2 V_29 , T_2 V_19 , T_2 V_152 ,
T_2 V_140 , T_2 V_35 , int V_165 )
{
int V_31 ;
if ( V_140 < V_149 ) {
F_35 ( V_165 != 1 ) ;
V_31 = F_132 ( V_117 , V_36 , V_66 , V_29 ,
V_19 , V_152 ) ;
} else {
V_31 = F_116 ( V_117 , V_36 , V_66 , V_29 ,
V_19 , V_152 ,
V_140 , V_35 , V_165 ) ;
}
return V_31 ;
}
static int F_150 ( struct V_116 * V_117 ,
struct V_14 * V_36 ,
struct V_65 * V_66 ,
struct V_171 * V_172 ,
int V_167 , int V_192 , int * V_168 )
{
int V_31 = 0 ;
F_35 ( ! V_192 && V_167 != 1 ) ;
if ( V_172 ) {
F_146 ( V_36 , V_66 , V_172 ,
- V_167 , NULL , V_168 ) ;
} else if ( V_192 ) {
V_31 = F_125 ( V_117 , V_36 , V_66 , V_167 ,
V_168 ) ;
} else {
* V_168 = 1 ;
V_31 = F_127 ( V_117 , V_36 -> V_64 , V_66 ) ;
}
return V_31 ;
}
static int F_151 ( struct V_193 * V_194 , T_2 V_34 , T_2 V_47 ,
T_2 * V_195 )
{
int V_196 , V_31 = 0 ;
T_2 V_197 , V_33 ;
T_2 V_198 = F_152 ( V_34 , 1 << 9 ) ;
if ( F_8 ( V_34 != V_198 ) ) {
V_47 -= V_198 - V_34 ;
V_47 = F_153 ( V_47 , 1 << 9 ) ;
V_34 = V_198 ;
}
* V_195 = 0 ;
if ( ! V_47 )
return 0 ;
V_33 = V_34 + V_47 ;
V_197 = V_47 ;
for ( V_196 = 0 ; V_196 < V_46 ; V_196 ++ ) {
T_2 V_199 = F_23 ( V_196 ) ;
T_2 V_200 = V_199 + V_201 ;
T_2 V_59 = V_199 - V_34 ;
if ( ! F_154 ( V_199 , V_34 , V_197 ) &&
! F_154 ( V_200 , V_34 , V_197 ) &&
! F_154 ( V_34 , V_199 , V_201 ) )
continue;
if ( V_199 <= V_34 ) {
V_34 += V_200 - V_34 ;
if ( V_34 > V_33 ) {
V_197 = 0 ;
break;
}
V_197 = V_33 - V_34 ;
continue;
}
if ( V_59 ) {
V_31 = F_155 ( V_194 , V_34 >> 9 , V_59 >> 9 ,
V_97 , 0 ) ;
if ( ! V_31 )
* V_195 += V_59 ;
else if ( V_31 != - V_202 )
return V_31 ;
}
V_34 = V_200 ;
if ( V_34 > V_33 ) {
V_197 = 0 ;
break;
}
V_197 = V_33 - V_34 ;
}
if ( V_197 ) {
V_31 = F_155 ( V_194 , V_34 >> 9 , V_197 >> 9 ,
V_97 , 0 ) ;
if ( ! V_31 )
* V_195 += V_197 ;
}
return V_31 ;
}
int F_156 ( struct V_14 * V_36 , T_2 V_29 ,
T_2 V_37 , T_2 * V_203 )
{
int V_31 ;
T_2 V_195 = 0 ;
struct V_204 * V_205 = NULL ;
F_157 ( V_36 ) ;
V_31 = F_158 ( V_36 , V_206 , V_29 , & V_37 ,
& V_205 , 0 ) ;
if ( ! V_31 ) {
struct V_207 * V_208 = V_205 -> V_209 ;
int V_42 ;
for ( V_42 = 0 ; V_42 < V_205 -> V_210 ; V_42 ++ , V_208 ++ ) {
T_2 V_211 ;
if ( ! V_208 -> V_212 -> V_213 )
continue;
V_31 = F_151 ( V_208 -> V_212 -> V_194 ,
V_208 -> V_214 ,
V_208 -> V_215 ,
& V_211 ) ;
if ( ! V_31 )
V_195 += V_211 ;
else if ( V_31 != - V_202 )
break;
V_31 = 0 ;
}
F_159 ( V_205 ) ;
}
F_160 ( V_36 ) ;
if ( V_203 )
* V_203 = V_195 ;
if ( V_31 == - V_202 )
V_31 = 0 ;
return V_31 ;
}
int F_161 ( struct V_116 * V_117 ,
struct V_14 * V_36 ,
T_2 V_29 , T_2 V_37 , T_2 V_19 ,
T_2 V_152 , T_2 V_140 , T_2 V_35 )
{
int V_31 ;
F_35 ( V_140 < V_149 &&
V_152 == V_216 ) ;
if ( V_140 < V_149 ) {
V_31 = F_162 ( V_36 , V_117 , V_29 ,
V_37 ,
V_19 , V_152 , ( int ) V_140 ,
V_217 , NULL ) ;
} else {
V_31 = F_163 ( V_36 , V_117 , V_29 ,
V_37 , V_19 , V_152 ,
V_140 , V_35 , 0 ,
V_217 ) ;
}
return V_31 ;
}
static int F_164 ( struct V_116 * V_117 ,
struct V_14 * V_36 ,
struct V_218 * V_135 ,
T_2 V_19 , T_2 V_152 ,
T_2 V_140 , T_2 V_35 , int V_165 ,
struct V_188 * V_136 )
{
struct V_65 * V_66 ;
struct V_67 * V_68 ;
struct V_123 * V_95 ;
struct V_69 V_23 ;
T_2 V_29 = V_135 -> V_29 ;
T_2 V_37 = V_135 -> V_37 ;
T_2 V_119 ;
int V_31 ;
V_66 = F_37 () ;
if ( ! V_66 )
return - V_74 ;
V_66 -> V_77 = V_78 ;
V_66 -> V_219 = 1 ;
V_31 = F_148 ( V_117 , V_36 , V_66 , V_29 ,
V_37 , V_19 , V_152 ,
V_140 , V_35 ,
V_165 , V_136 ) ;
if ( ( V_31 < 0 && V_31 != - V_186 ) || ! V_31 )
goto V_81;
V_68 = V_66 -> V_82 [ 0 ] ;
F_44 ( V_68 , & V_23 , V_66 -> V_83 [ 0 ] ) ;
V_95 = F_89 ( V_68 , V_66 -> V_83 [ 0 ] , struct V_123 ) ;
V_119 = F_90 ( V_68 , V_95 ) ;
F_101 ( V_68 , V_95 , V_119 + V_165 ) ;
if ( V_136 )
F_141 ( V_136 , V_68 , V_95 ) ;
F_106 ( V_68 ) ;
F_48 ( V_66 ) ;
V_66 -> V_77 = V_78 ;
V_66 -> V_219 = 1 ;
V_31 = F_149 ( V_117 , V_36 , V_66 , V_29 , V_19 ,
V_152 , V_140 , V_35 , V_165 ) ;
if ( V_31 )
F_165 ( V_117 , V_31 ) ;
V_81:
F_56 ( V_66 ) ;
return V_31 ;
}
static int F_166 ( struct V_116 * V_117 ,
struct V_14 * V_36 ,
struct V_218 * V_135 ,
struct V_188 * V_136 ,
int V_220 )
{
int V_31 = 0 ;
struct V_221 * V_157 ;
struct V_69 V_222 ;
T_2 V_19 = 0 ;
T_2 V_223 = 0 ;
T_2 V_7 = 0 ;
V_222 . V_24 = V_135 -> V_29 ;
V_222 . V_35 = V_135 -> V_37 ;
V_222 . type = V_79 ;
V_157 = F_167 ( V_135 ) ;
F_168 ( V_36 , V_135 , V_157 , V_135 -> V_224 ) ;
if ( V_135 -> type == V_161 )
V_19 = V_157 -> V_19 ;
V_223 = V_157 -> V_12 ;
if ( V_135 -> V_224 == V_217 && V_220 ) {
if ( V_136 )
V_7 |= V_136 -> V_138 ;
V_31 = F_169 ( V_117 , V_36 ,
V_19 , V_223 , V_7 ,
V_157 -> V_24 , V_157 -> V_35 ,
& V_222 , V_135 -> V_139 ) ;
} else if ( V_135 -> V_224 == V_217 ) {
V_31 = F_164 ( V_117 , V_36 , V_135 , V_19 ,
V_223 , V_157 -> V_24 ,
V_157 -> V_35 , V_135 -> V_139 ,
V_136 ) ;
} else if ( V_135 -> V_224 == V_225 ) {
V_31 = F_170 ( V_117 , V_36 , V_135 , V_19 ,
V_223 , V_157 -> V_24 ,
V_157 -> V_35 , V_135 -> V_139 ,
V_136 ) ;
} else {
F_94 () ;
}
return V_31 ;
}
static void F_141 ( struct V_188 * V_136 ,
struct V_67 * V_68 ,
struct V_123 * V_124 )
{
T_2 V_7 = F_91 ( V_68 , V_124 ) ;
if ( V_136 -> V_137 ) {
V_7 |= V_136 -> V_138 ;
F_103 ( V_68 , V_124 , V_7 ) ;
}
if ( V_136 -> V_226 ) {
struct V_144 * V_145 ;
F_35 ( ! ( V_7 & V_150 ) ) ;
V_145 = (struct V_144 * ) ( V_124 + 1 ) ;
F_171 ( V_68 , V_145 , & V_136 -> V_23 ) ;
}
}
static int F_172 ( struct V_116 * V_117 ,
struct V_14 * V_36 ,
struct V_218 * V_135 ,
struct V_188 * V_136 )
{
struct V_69 V_23 ;
struct V_65 * V_66 ;
struct V_123 * V_124 ;
struct V_67 * V_68 ;
T_3 V_125 ;
int V_31 ;
int V_159 = 0 ;
int V_118 = ! V_136 -> V_192 ;
if ( V_117 -> V_227 )
return 0 ;
if ( V_118 && ! F_87 ( V_36 , V_128 ) )
V_118 = 0 ;
V_66 = F_37 () ;
if ( ! V_66 )
return - V_74 ;
V_23 . V_24 = V_135 -> V_29 ;
if ( V_118 ) {
V_23 . type = V_87 ;
V_23 . V_35 = V_136 -> V_175 ;
} else {
V_23 . type = V_79 ;
V_23 . V_35 = V_135 -> V_37 ;
}
V_163:
V_66 -> V_77 = V_78 ;
V_66 -> V_219 = 1 ;
V_31 = F_41 ( V_117 , V_36 -> V_64 , & V_23 , V_66 , 0 , 1 ) ;
if ( V_31 < 0 ) {
V_159 = V_31 ;
goto V_81;
}
if ( V_31 > 0 ) {
if ( V_118 ) {
if ( V_66 -> V_83 [ 0 ] > 0 ) {
V_66 -> V_83 [ 0 ] -- ;
F_44 ( V_66 -> V_82 [ 0 ] , & V_23 ,
V_66 -> V_83 [ 0 ] ) ;
if ( V_23 . V_24 == V_135 -> V_29 &&
V_23 . type == V_79 &&
V_23 . V_35 == V_135 -> V_37 )
V_31 = 0 ;
}
if ( V_31 > 0 ) {
F_48 ( V_66 ) ;
V_118 = 0 ;
V_23 . V_24 = V_135 -> V_29 ;
V_23 . V_35 = V_135 -> V_37 ;
V_23 . type = V_79 ;
goto V_163;
}
} else {
V_159 = - V_183 ;
goto V_81;
}
}
V_68 = V_66 -> V_82 [ 0 ] ;
V_125 = F_88 ( V_68 , V_66 -> V_83 [ 0 ] ) ;
#ifdef F_92
if ( V_125 < sizeof( * V_124 ) ) {
V_31 = F_98 ( V_117 , V_36 , V_66 , ( T_2 ) - 1 , 0 ) ;
if ( V_31 < 0 ) {
V_159 = V_31 ;
goto V_81;
}
V_68 = V_66 -> V_82 [ 0 ] ;
V_125 = F_88 ( V_68 , V_66 -> V_83 [ 0 ] ) ;
}
#endif
F_35 ( V_125 < sizeof( * V_124 ) ) ;
V_124 = F_89 ( V_68 , V_66 -> V_83 [ 0 ] , struct V_123 ) ;
F_141 ( V_136 , V_68 , V_124 ) ;
F_106 ( V_68 ) ;
V_81:
F_56 ( V_66 ) ;
return V_159 ;
}
static int F_173 ( struct V_116 * V_117 ,
struct V_14 * V_36 ,
struct V_218 * V_135 ,
struct V_188 * V_136 ,
int V_220 )
{
int V_31 = 0 ;
struct V_228 * V_157 ;
struct V_69 V_222 ;
T_2 V_19 = 0 ;
T_2 V_223 = 0 ;
bool V_181 = F_87 ( V_36 , V_128 ) ;
V_157 = F_174 ( V_135 ) ;
F_175 ( V_36 , V_135 , V_157 , V_135 -> V_224 ) ;
if ( V_135 -> type == V_173 )
V_19 = V_157 -> V_19 ;
V_223 = V_157 -> V_12 ;
V_222 . V_24 = V_135 -> V_29 ;
if ( V_181 ) {
V_222 . V_35 = V_157 -> V_175 ;
V_222 . type = V_87 ;
} else {
V_222 . V_35 = V_135 -> V_37 ;
V_222 . type = V_79 ;
}
if ( V_135 -> V_139 != 1 ) {
F_176 ( V_36 ,
L_1 ,
V_135 -> V_29 , V_135 -> V_139 , V_135 -> V_224 , V_223 ,
V_19 ) ;
return - V_183 ;
}
if ( V_135 -> V_224 == V_217 && V_220 ) {
F_35 ( ! V_136 || ! V_136 -> V_137 ) ;
V_31 = F_177 ( V_117 , V_36 ,
V_19 , V_223 ,
V_136 -> V_138 ,
& V_136 -> V_23 ,
V_157 -> V_175 , & V_222 ) ;
} else if ( V_135 -> V_224 == V_217 ) {
V_31 = F_164 ( V_117 , V_36 , V_135 ,
V_19 , V_223 ,
V_157 -> V_175 , 0 , 1 ,
V_136 ) ;
} else if ( V_135 -> V_224 == V_225 ) {
V_31 = F_170 ( V_117 , V_36 , V_135 ,
V_19 , V_223 ,
V_157 -> V_175 , 0 , 1 , V_136 ) ;
} else {
F_94 () ;
}
return V_31 ;
}
static int F_178 ( struct V_116 * V_117 ,
struct V_14 * V_36 ,
struct V_218 * V_135 ,
struct V_188 * V_136 ,
int V_220 )
{
int V_31 = 0 ;
if ( V_117 -> V_227 ) {
if ( V_220 )
F_179 ( V_36 , V_135 -> V_29 ,
V_135 -> V_37 , 1 ) ;
return 0 ;
}
if ( F_180 ( V_135 ) ) {
struct V_120 * V_112 ;
F_35 ( V_136 ) ;
V_112 = F_181 ( V_135 ) ;
F_182 ( V_36 , V_135 , V_112 , V_135 -> V_224 ) ;
if ( V_220 ) {
F_179 ( V_36 , V_135 -> V_29 ,
V_135 -> V_37 , 1 ) ;
if ( V_112 -> V_192 ) {
V_31 = F_183 ( V_117 , V_36 ,
V_135 -> V_29 ,
V_135 -> V_37 ) ;
}
}
F_184 ( V_36 , V_112 -> V_229 ,
V_112 -> V_230 ) ;
return V_31 ;
}
if ( V_135 -> type == V_174 ||
V_135 -> type == V_173 )
V_31 = F_173 ( V_117 , V_36 , V_135 , V_136 ,
V_220 ) ;
else if ( V_135 -> type == V_162 ||
V_135 -> type == V_161 )
V_31 = F_166 ( V_117 , V_36 , V_135 , V_136 ,
V_220 ) ;
else
F_94 () ;
return V_31 ;
}
static inline struct V_218 *
F_185 ( struct V_120 * V_112 )
{
struct V_218 * V_157 ;
if ( F_186 ( & V_112 -> V_231 ) )
return NULL ;
if ( ! F_186 ( & V_112 -> V_232 ) )
return F_187 ( & V_112 -> V_232 ,
struct V_218 , V_233 ) ;
V_157 = F_187 ( & V_112 -> V_231 , struct V_218 ,
V_98 ) ;
ASSERT ( F_186 ( & V_157 -> V_233 ) ) ;
return V_157 ;
}
static T_1 int F_188 ( struct V_116 * V_117 ,
struct V_14 * V_36 ,
unsigned long V_43 )
{
struct V_121 * V_122 ;
struct V_218 * V_157 ;
struct V_120 * V_234 = NULL ;
struct V_188 * V_136 ;
T_6 V_34 = F_189 () ;
int V_31 ;
unsigned long V_8 = 0 ;
unsigned long V_235 = 0 ;
int V_236 = 0 ;
V_122 = & V_117 -> V_134 -> V_122 ;
while ( 1 ) {
if ( ! V_234 ) {
if ( V_8 >= V_43 )
break;
F_12 ( & V_122 -> V_50 ) ;
V_234 = F_190 ( V_117 ) ;
if ( ! V_234 ) {
F_14 ( & V_122 -> V_50 ) ;
break;
}
V_31 = F_191 ( V_117 , V_234 ) ;
F_14 ( & V_122 -> V_50 ) ;
if ( V_31 == - V_186 ) {
V_234 = NULL ;
V_8 ++ ;
continue;
}
}
F_12 ( & V_234 -> V_50 ) ;
F_192 ( V_117 , V_36 , V_122 ,
V_234 ) ;
V_157 = F_185 ( V_234 ) ;
if ( V_157 && V_157 -> V_237 &&
F_193 ( V_36 , V_122 , V_157 -> V_237 ) ) {
F_14 ( & V_234 -> V_50 ) ;
F_12 ( & V_122 -> V_50 ) ;
V_234 -> V_238 = 0 ;
V_122 -> V_239 ++ ;
F_14 ( & V_122 -> V_50 ) ;
F_194 ( V_234 ) ;
V_234 = NULL ;
F_51 () ;
V_8 ++ ;
continue;
}
V_236 = V_234 -> V_236 ;
V_234 -> V_236 = 0 ;
V_136 = V_234 -> V_136 ;
V_234 -> V_136 = NULL ;
if ( ! V_157 ) {
V_157 = & V_234 -> V_135 ;
if ( V_136 && V_236 ) {
F_195 ( V_136 ) ;
V_136 = NULL ;
}
if ( V_136 ) {
F_14 ( & V_234 -> V_50 ) ;
V_31 = F_172 ( V_117 , V_36 ,
V_157 , V_136 ) ;
F_195 ( V_136 ) ;
if ( V_31 ) {
if ( V_236 )
V_234 -> V_236 = 1 ;
F_12 ( & V_122 -> V_50 ) ;
V_234 -> V_238 = 0 ;
V_122 -> V_239 ++ ;
F_14 ( & V_122 -> V_50 ) ;
F_196 ( V_36 ,
L_2 ,
V_31 ) ;
F_194 ( V_234 ) ;
return V_31 ;
}
continue;
}
F_14 ( & V_234 -> V_50 ) ;
F_12 ( & V_122 -> V_50 ) ;
F_12 ( & V_234 -> V_50 ) ;
if ( ! F_186 ( & V_234 -> V_231 ) ||
V_234 -> V_136 ) {
F_14 ( & V_234 -> V_50 ) ;
F_14 ( & V_122 -> V_50 ) ;
continue;
}
V_157 -> V_240 = 0 ;
V_122 -> V_241 -- ;
F_197 ( & V_234 -> V_242 ,
& V_122 -> V_243 ) ;
F_14 ( & V_122 -> V_50 ) ;
} else {
V_235 ++ ;
V_157 -> V_240 = 0 ;
F_198 ( & V_157 -> V_98 ) ;
if ( ! F_186 ( & V_157 -> V_233 ) )
F_198 ( & V_157 -> V_233 ) ;
}
F_199 ( & V_122 -> V_244 ) ;
if ( ! F_180 ( V_157 ) ) {
switch ( V_157 -> V_224 ) {
case V_217 :
case V_245 :
V_234 -> V_135 . V_139 -= V_157 -> V_139 ;
break;
case V_225 :
V_234 -> V_135 . V_139 += V_157 -> V_139 ;
break;
default:
F_8 ( 1 ) ;
}
}
F_14 ( & V_234 -> V_50 ) ;
V_31 = F_178 ( V_117 , V_36 , V_157 , V_136 ,
V_236 ) ;
F_195 ( V_136 ) ;
if ( V_31 ) {
F_12 ( & V_122 -> V_50 ) ;
V_234 -> V_238 = 0 ;
V_122 -> V_239 ++ ;
F_14 ( & V_122 -> V_50 ) ;
F_194 ( V_234 ) ;
F_97 ( V_157 ) ;
F_196 ( V_36 , L_3 ,
V_31 ) ;
return V_31 ;
}
if ( F_180 ( V_157 ) ) {
if ( V_234 -> V_192 &&
V_234 -> V_246 < 0 ) {
F_12 ( & V_122 -> V_50 ) ;
V_122 -> V_247 -= V_157 -> V_37 ;
F_14 ( & V_122 -> V_50 ) ;
}
F_194 ( V_234 ) ;
V_234 = NULL ;
}
F_97 ( V_157 ) ;
V_8 ++ ;
F_51 () ;
}
if ( V_235 > 0 ) {
T_2 V_248 = F_200 ( F_201 ( F_189 () , V_34 ) ) ;
T_2 V_249 ;
F_12 ( & V_122 -> V_50 ) ;
V_249 = V_36 -> V_250 * 3 + V_248 ;
V_36 -> V_250 = V_249 >> 2 ;
F_14 ( & V_122 -> V_50 ) ;
}
return 0 ;
}
static T_2 F_202 ( struct V_251 * V_12 )
{
struct V_17 * V_32 = V_12 -> V_17 ;
struct V_218 * V_252 ;
int V_253 = 1 ;
T_2 V_254 ;
T_2 V_255 = 0 , V_71 = 0 ;
V_32 = F_203 ( V_12 ) ;
if ( V_32 ) {
V_252 = F_13 ( V_32 , struct V_218 , V_17 ) ;
V_255 = V_252 -> V_29 ;
}
V_32 = F_204 ( V_12 ) ;
if ( V_32 ) {
V_252 = F_13 ( V_32 , struct V_218 , V_17 ) ;
V_71 = V_252 -> V_29 ;
}
V_32 = V_12 -> V_17 ;
while ( V_32 ) {
V_252 = F_13 ( V_32 , struct V_218 , V_17 ) ;
F_8 ( ! V_252 -> V_240 ) ;
V_254 = V_252 -> V_29 ;
if ( V_253 )
V_32 = V_32 -> V_25 ;
else
V_32 = V_32 -> V_26 ;
V_253 = 1 - V_253 ;
}
return V_254 ;
}
static inline T_2 F_205 ( struct V_14 * V_36 , T_2 V_256 )
{
T_2 V_37 ;
V_37 = V_256 * ( sizeof( struct V_123 ) +
sizeof( struct V_171 ) ) ;
if ( ! F_87 ( V_36 , V_128 ) )
V_37 += V_256 * sizeof( struct V_144 ) ;
return F_206 ( V_37 , F_207 ( V_36 ) ) ;
}
T_2 F_208 ( struct V_14 * V_36 , T_2 V_257 )
{
T_2 V_258 ;
T_2 V_259 ;
T_2 V_260 ;
V_258 = F_209 ( V_36 ) ;
V_259 = F_210 ( V_258 ,
( T_2 ) F_211 ( V_36 -> V_261 ) ) ;
V_260 = F_210 ( V_257 , V_36 -> V_55 ) ;
V_260 += V_259 - 1 ;
V_260 = F_210 ( V_260 , V_259 ) ;
return V_260 ;
}
int F_212 ( struct V_116 * V_117 ,
struct V_14 * V_36 )
{
struct V_262 * V_263 ;
T_2 V_241 = V_117 -> V_134 -> V_122 . V_239 ;
T_2 V_257 = V_117 -> V_134 -> V_122 . V_247 ;
T_2 V_264 = V_117 -> V_134 -> V_264 ;
T_2 V_37 , V_265 ;
int V_31 = 0 ;
V_37 = F_213 ( V_36 , 1 ) ;
V_241 = F_205 ( V_36 , V_241 ) ;
if ( V_241 > 1 )
V_37 += ( V_241 - 1 ) * V_36 -> V_54 ;
V_37 <<= 1 ;
V_37 += F_208 ( V_36 , V_257 ) *
V_36 -> V_54 ;
V_265 = F_213 ( V_36 ,
V_264 ) ;
V_263 = & V_36 -> V_266 ;
if ( V_263 -> V_94 -> V_115 ) {
V_265 <<= 1 ;
V_37 <<= 1 ;
}
F_12 ( & V_263 -> V_50 ) ;
if ( V_263 -> V_10 <= V_37 + V_265 )
V_31 = 1 ;
F_14 ( & V_263 -> V_50 ) ;
return V_31 ;
}
int F_214 ( struct V_116 * V_117 ,
struct V_14 * V_36 )
{
T_2 V_244 =
F_215 ( & V_117 -> V_134 -> V_122 . V_244 ) ;
T_2 V_267 ;
T_2 V_268 ;
F_2 () ;
V_267 = V_36 -> V_250 ;
V_268 = V_244 * V_267 ;
if ( V_268 >= V_269 )
return 1 ;
if ( V_268 >= V_269 / 2 )
return 2 ;
return F_212 ( V_117 , V_36 ) ;
}
static inline struct V_270 *
F_216 ( struct V_90 * V_91 )
{
return F_58 ( V_91 , struct V_270 , V_91 ) ;
}
static void F_217 ( struct V_90 * V_91 )
{
struct V_270 * V_271 = F_216 ( V_91 ) ;
struct V_116 * V_117 ;
struct V_14 * V_36 = V_271 -> V_12 -> V_36 ;
int V_31 ;
if ( F_218 ( V_36 ) )
goto V_272;
V_117 = F_219 ( V_271 -> V_12 ) ;
if ( F_220 ( V_117 ) ) {
V_271 -> error = F_221 ( V_117 ) ;
goto V_272;
}
V_117 -> V_273 = true ;
if ( V_117 -> V_274 > V_271 -> V_274 )
goto V_33;
V_31 = F_222 ( V_117 , V_36 , V_271 -> V_8 ) ;
if ( V_31 )
V_271 -> error = V_31 ;
V_33:
V_31 = F_223 ( V_117 ) ;
if ( V_31 && ! V_271 -> error )
V_271 -> error = V_31 ;
V_272:
if ( V_271 -> V_273 )
F_224 ( & V_271 -> V_89 ) ;
else
F_10 ( V_271 ) ;
}
int F_225 ( struct V_14 * V_36 ,
unsigned long V_8 , T_2 V_274 , int V_89 )
{
struct V_270 * V_271 ;
int V_31 ;
V_271 = F_226 ( sizeof( * V_271 ) , V_97 ) ;
if ( ! V_271 )
return - V_74 ;
V_271 -> V_12 = V_36 -> V_275 ;
V_271 -> V_8 = V_8 ;
V_271 -> error = 0 ;
V_271 -> V_274 = V_274 ;
if ( V_89 )
V_271 -> V_273 = 1 ;
else
V_271 -> V_273 = 0 ;
F_227 ( & V_271 -> V_89 ) ;
F_69 ( & V_271 -> V_91 , V_276 ,
F_217 , NULL , NULL ) ;
F_77 ( V_36 -> V_277 , & V_271 -> V_91 ) ;
if ( V_89 ) {
F_228 ( & V_271 -> V_89 ) ;
V_31 = V_271 -> error ;
F_10 ( V_271 ) ;
return V_31 ;
}
return 0 ;
}
int F_222 ( struct V_116 * V_117 ,
struct V_14 * V_36 , unsigned long V_8 )
{
struct V_17 * V_135 ;
struct V_121 * V_122 ;
struct V_120 * V_112 ;
int V_31 ;
int V_278 = V_8 == ( unsigned long ) - 1 ;
bool V_279 = V_117 -> V_279 ;
if ( V_117 -> V_227 )
return 0 ;
if ( F_229 ( V_280 , & V_36 -> V_7 ) )
return 0 ;
V_122 = & V_117 -> V_134 -> V_122 ;
if ( V_8 == 0 )
V_8 = F_215 ( & V_122 -> V_244 ) * 2 ;
V_163:
#ifdef F_230
V_122 -> V_281 = F_202 ( & V_122 -> V_12 ) ;
#endif
V_117 -> V_279 = false ;
V_31 = F_188 ( V_117 , V_36 , V_8 ) ;
if ( V_31 < 0 ) {
F_165 ( V_117 , V_31 ) ;
return V_31 ;
}
if ( V_278 ) {
if ( ! F_186 ( & V_117 -> V_282 ) )
F_231 ( V_117 , V_36 ) ;
F_12 ( & V_122 -> V_50 ) ;
V_135 = F_203 ( & V_122 -> V_243 ) ;
if ( ! V_135 ) {
F_14 ( & V_122 -> V_50 ) ;
goto V_81;
}
while ( V_135 ) {
V_112 = F_13 ( V_135 , struct V_120 ,
V_242 ) ;
if ( F_180 ( & V_112 -> V_135 ) ) {
struct V_218 * V_157 ;
V_157 = & V_112 -> V_135 ;
F_27 ( & V_157 -> V_119 ) ;
F_14 ( & V_122 -> V_50 ) ;
F_52 ( & V_112 -> V_86 ) ;
F_50 ( & V_112 -> V_86 ) ;
F_97 ( V_157 ) ;
F_51 () ;
goto V_163;
} else {
F_8 ( 1 ) ;
}
V_135 = F_232 ( V_135 ) ;
}
F_14 ( & V_122 -> V_50 ) ;
F_51 () ;
goto V_163;
}
V_81:
V_117 -> V_279 = V_279 ;
return 0 ;
}
int F_233 ( struct V_116 * V_117 ,
struct V_14 * V_36 ,
T_2 V_29 , T_2 V_37 , T_2 V_7 ,
int V_175 , int V_192 )
{
struct V_188 * V_136 ;
int V_31 ;
V_136 = F_234 () ;
if ( ! V_136 )
return - V_74 ;
V_136 -> V_138 = V_7 ;
V_136 -> V_137 = true ;
V_136 -> V_226 = false ;
V_136 -> V_192 = V_192 ? true : false ;
V_136 -> V_175 = V_175 ;
V_31 = F_235 ( V_36 , V_117 , V_29 ,
V_37 , V_136 ) ;
if ( V_31 )
F_195 ( V_136 ) ;
return V_31 ;
}
static T_1 int F_236 ( struct V_63 * V_12 ,
struct V_65 * V_66 ,
T_2 V_24 , T_2 V_35 , T_2 V_29 )
{
struct V_120 * V_112 ;
struct V_218 * V_157 ;
struct V_221 * V_283 ;
struct V_121 * V_122 ;
struct V_284 * V_285 ;
int V_31 = 0 ;
V_285 = V_12 -> V_36 -> V_286 ;
if ( ! V_285 )
return 0 ;
V_122 = & V_285 -> V_122 ;
F_12 ( & V_122 -> V_50 ) ;
V_112 = F_95 ( V_122 , V_29 ) ;
if ( ! V_112 ) {
F_14 ( & V_122 -> V_50 ) ;
return 0 ;
}
if ( ! F_96 ( & V_112 -> V_86 ) ) {
F_27 ( & V_112 -> V_135 . V_119 ) ;
F_14 ( & V_122 -> V_50 ) ;
F_48 ( V_66 ) ;
F_52 ( & V_112 -> V_86 ) ;
F_50 ( & V_112 -> V_86 ) ;
F_97 ( & V_112 -> V_135 ) ;
return - V_186 ;
}
F_14 ( & V_122 -> V_50 ) ;
F_12 ( & V_112 -> V_50 ) ;
F_237 (ref, &head->ref_list, list) {
if ( V_157 -> type != V_162 ) {
V_31 = 1 ;
break;
}
V_283 = F_167 ( V_157 ) ;
if ( V_283 -> V_12 != V_12 -> V_287 . V_24 ||
V_283 -> V_24 != V_24 ||
V_283 -> V_35 != V_35 ) {
V_31 = 1 ;
break;
}
}
F_14 ( & V_112 -> V_50 ) ;
F_50 ( & V_112 -> V_86 ) ;
return V_31 ;
}
static T_1 int F_238 ( struct V_63 * V_12 ,
struct V_65 * V_66 ,
T_2 V_24 , T_2 V_35 , T_2 V_29 )
{
struct V_14 * V_36 = V_12 -> V_36 ;
struct V_63 * V_64 = V_36 -> V_64 ;
struct V_67 * V_68 ;
struct V_156 * V_157 ;
struct V_171 * V_172 ;
struct V_123 * V_124 ;
struct V_69 V_23 ;
T_3 V_125 ;
int V_31 ;
V_23 . V_24 = V_29 ;
V_23 . V_35 = ( T_2 ) - 1 ;
V_23 . type = V_79 ;
V_31 = F_41 ( NULL , V_64 , & V_23 , V_66 , 0 , 0 ) ;
if ( V_31 < 0 )
goto V_81;
F_35 ( V_31 == 0 ) ;
V_31 = - V_160 ;
if ( V_66 -> V_83 [ 0 ] == 0 )
goto V_81;
V_66 -> V_83 [ 0 ] -- ;
V_68 = V_66 -> V_82 [ 0 ] ;
F_44 ( V_68 , & V_23 , V_66 -> V_83 [ 0 ] ) ;
if ( V_23 . V_24 != V_29 || V_23 . type != V_79 )
goto V_81;
V_31 = 1 ;
V_125 = F_88 ( V_68 , V_66 -> V_83 [ 0 ] ) ;
#ifdef F_92
if ( V_125 < sizeof( * V_124 ) ) {
F_8 ( V_125 != sizeof( struct V_131 ) ) ;
goto V_81;
}
#endif
V_124 = F_89 ( V_68 , V_66 -> V_83 [ 0 ] , struct V_123 ) ;
if ( V_125 != sizeof( * V_124 ) +
F_136 ( V_162 ) )
goto V_81;
if ( F_239 ( V_68 , V_124 ) <=
F_240 ( & V_12 -> V_288 ) )
goto V_81;
V_172 = (struct V_171 * ) ( V_124 + 1 ) ;
if ( F_130 ( V_68 , V_172 ) !=
V_162 )
goto V_81;
V_157 = (struct V_156 * ) ( & V_172 -> V_35 ) ;
if ( F_90 ( V_68 , V_124 ) !=
F_124 ( V_68 , V_157 ) ||
F_111 ( V_68 , V_157 ) !=
V_12 -> V_287 . V_24 ||
F_112 ( V_68 , V_157 ) != V_24 ||
F_113 ( V_68 , V_157 ) != V_35 )
goto V_81;
V_31 = 0 ;
V_81:
return V_31 ;
}
int F_241 ( struct V_63 * V_12 , T_2 V_24 , T_2 V_35 ,
T_2 V_29 )
{
struct V_65 * V_66 ;
int V_31 ;
int V_289 ;
V_66 = F_37 () ;
if ( ! V_66 )
return - V_160 ;
do {
V_31 = F_238 ( V_12 , V_66 , V_24 ,
V_35 , V_29 ) ;
if ( V_31 && V_31 != - V_160 )
goto V_81;
V_289 = F_236 ( V_12 , V_66 , V_24 ,
V_35 , V_29 ) ;
} while ( V_289 == - V_186 );
if ( V_289 && V_289 != - V_160 ) {
V_31 = V_289 ;
goto V_81;
}
if ( V_31 != - V_160 || V_289 != - V_160 )
V_31 = 0 ;
V_81:
F_56 ( V_66 ) ;
if ( V_12 -> V_287 . V_24 == V_290 )
F_8 ( V_31 > 0 ) ;
return V_31 ;
}
static int F_242 ( struct V_116 * V_117 ,
struct V_63 * V_12 ,
struct V_67 * V_291 ,
int V_292 , int V_293 )
{
struct V_14 * V_36 = V_12 -> V_36 ;
T_2 V_29 ;
T_2 V_37 ;
T_2 V_19 ;
T_2 V_223 ;
T_3 V_72 ;
struct V_69 V_23 ;
struct V_294 * V_295 ;
int V_42 ;
int V_175 ;
int V_31 = 0 ;
int (* F_243)( struct V_116 * ,
struct V_14 * ,
T_2 , T_2 , T_2 , T_2 , T_2 , T_2 );
if ( F_244 ( V_36 ) )
return 0 ;
V_223 = F_245 ( V_291 ) ;
V_72 = F_42 ( V_291 ) ;
V_175 = F_246 ( V_291 ) ;
if ( ! F_229 ( V_296 , & V_12 -> V_297 ) && V_175 == 0 )
return 0 ;
if ( V_293 )
F_243 = F_161 ;
else
F_243 = V_298 ;
if ( V_292 )
V_19 = V_291 -> V_34 ;
else
V_19 = 0 ;
for ( V_42 = 0 ; V_42 < V_72 ; V_42 ++ ) {
if ( V_175 == 0 ) {
F_44 ( V_291 , & V_23 , V_42 ) ;
if ( V_23 . type != V_299 )
continue;
V_295 = F_89 ( V_291 , V_42 ,
struct V_294 ) ;
if ( F_247 ( V_291 , V_295 ) ==
V_300 )
continue;
V_29 = F_248 ( V_291 , V_295 ) ;
if ( V_29 == 0 )
continue;
V_37 = F_249 ( V_291 , V_295 ) ;
V_23 . V_35 -= F_250 ( V_291 , V_295 ) ;
V_31 = F_243 ( V_117 , V_36 , V_29 , V_37 ,
V_19 , V_223 , V_23 . V_24 ,
V_23 . V_35 ) ;
if ( V_31 )
goto V_164;
} else {
V_29 = F_251 ( V_291 , V_42 ) ;
V_37 = V_36 -> V_54 ;
V_31 = F_243 ( V_117 , V_36 , V_29 , V_37 ,
V_19 , V_223 , V_175 - 1 , 0 ) ;
if ( V_31 )
goto V_164;
}
}
return 0 ;
V_164:
return V_31 ;
}
int F_252 ( struct V_116 * V_117 , struct V_63 * V_12 ,
struct V_67 * V_291 , int V_292 )
{
return F_242 ( V_117 , V_12 , V_291 , V_292 , 1 ) ;
}
int F_253 ( struct V_116 * V_117 , struct V_63 * V_12 ,
struct V_67 * V_291 , int V_292 )
{
return F_242 ( V_117 , V_12 , V_291 , V_292 , 0 ) ;
}
static int F_254 ( struct V_116 * V_117 ,
struct V_14 * V_36 ,
struct V_65 * V_66 ,
struct V_1 * V_2 )
{
int V_31 ;
struct V_63 * V_64 = V_36 -> V_64 ;
unsigned long V_145 ;
struct V_67 * V_68 ;
V_31 = F_41 ( V_117 , V_64 , & V_2 -> V_23 , V_66 , 0 , 1 ) ;
if ( V_31 ) {
if ( V_31 > 0 )
V_31 = - V_160 ;
goto V_164;
}
V_68 = V_66 -> V_82 [ 0 ] ;
V_145 = F_255 ( V_68 , V_66 -> V_83 [ 0 ] ) ;
F_256 ( V_68 , & V_2 -> V_95 , V_145 , sizeof( V_2 -> V_95 ) ) ;
F_106 ( V_68 ) ;
V_164:
F_48 ( V_66 ) ;
return V_31 ;
}
static struct V_1 *
F_257 ( struct V_14 * V_36 ,
struct V_1 * V_2 )
{
struct V_17 * V_135 ;
F_12 ( & V_36 -> V_20 ) ;
if ( F_258 ( & V_2 -> V_22 ) ) {
const T_2 V_301 = V_2 -> V_23 . V_24 + V_2 -> V_23 . V_35 ;
F_14 ( & V_36 -> V_20 ) ;
F_6 ( V_2 ) ;
V_2 = F_78 ( V_36 , V_301 ) ; return V_2 ;
}
V_135 = F_232 ( & V_2 -> V_22 ) ;
F_6 ( V_2 ) ;
if ( V_135 ) {
V_2 = F_13 ( V_135 , struct V_1 ,
V_22 ) ;
F_4 ( V_2 ) ;
} else
V_2 = NULL ;
F_14 ( & V_36 -> V_20 ) ;
return V_2 ;
}
static int F_259 ( struct V_1 * V_16 ,
struct V_116 * V_117 ,
struct V_65 * V_66 )
{
struct V_14 * V_36 = V_16 -> V_36 ;
struct V_63 * V_12 = V_36 -> V_275 ;
struct V_302 * V_302 = NULL ;
T_2 V_303 = 0 ;
int V_304 = V_305 ;
T_2 V_306 = 0 ;
int V_307 = 0 ;
int V_31 = 0 ;
if ( V_16 -> V_23 . V_35 < ( 100 * V_308 ) ) {
F_12 ( & V_16 -> V_50 ) ;
V_16 -> V_309 = V_310 ;
F_14 ( & V_16 -> V_50 ) ;
return 0 ;
}
if ( V_117 -> V_227 )
return 0 ;
V_163:
V_302 = F_260 ( V_36 , V_16 , V_66 ) ;
if ( F_220 ( V_302 ) && F_221 ( V_302 ) != - V_160 ) {
V_31 = F_221 ( V_302 ) ;
F_48 ( V_66 ) ;
goto V_81;
}
if ( F_220 ( V_302 ) ) {
F_35 ( V_307 ) ;
V_307 ++ ;
if ( V_16 -> V_311 )
goto V_130;
V_31 = F_261 ( V_36 , V_117 , V_16 ,
V_66 ) ;
if ( V_31 )
goto V_130;
goto V_163;
}
if ( V_16 -> V_312 == V_117 -> V_274 &&
F_262 ( V_302 ) ) {
V_304 = V_313 ;
goto V_314;
}
F_263 ( V_302 ) -> V_315 = 0 ;
V_31 = F_264 ( V_117 , V_12 , V_302 ) ;
if ( V_31 ) {
F_165 ( V_117 , V_31 ) ;
goto V_314;
}
F_8 ( V_31 ) ;
if ( F_262 ( V_302 ) > 0 ) {
V_31 = F_265 ( V_36 ,
& V_36 -> V_266 ) ;
if ( V_31 )
goto V_314;
V_31 = F_266 ( V_117 , NULL , V_302 ) ;
if ( V_31 )
goto V_314;
}
F_12 ( & V_16 -> V_50 ) ;
if ( V_16 -> V_3 != V_4 ||
! F_267 ( V_36 , V_316 ) ) {
V_304 = V_310 ;
F_14 ( & V_16 -> V_50 ) ;
goto V_314;
}
F_14 ( & V_16 -> V_50 ) ;
if ( F_229 ( V_317 , & V_117 -> V_134 -> V_7 ) ) {
V_31 = - V_318 ;
goto V_314;
}
V_306 = F_206 ( V_16 -> V_23 . V_35 , V_319 ) ;
if ( ! V_306 )
V_306 = 1 ;
V_306 *= 16 ;
V_306 *= V_320 ;
V_31 = F_268 ( V_302 , 0 , V_306 ) ;
if ( V_31 )
goto V_314;
V_31 = F_269 ( V_302 , V_117 , 0 , 0 , V_306 ,
V_306 , V_306 ,
& V_303 ) ;
if ( ! V_31 )
V_304 = V_313 ;
else if ( V_31 == - V_318 )
F_270 ( V_317 , & V_117 -> V_134 -> V_7 ) ;
V_314:
F_271 ( V_302 ) ;
V_130:
F_48 ( V_66 ) ;
V_81:
F_12 ( & V_16 -> V_50 ) ;
if ( ! V_31 && V_304 == V_313 )
V_16 -> V_312 = V_117 -> V_274 ;
V_16 -> V_309 = V_304 ;
F_14 ( & V_16 -> V_50 ) ;
return V_31 ;
}
int F_272 ( struct V_116 * V_117 ,
struct V_14 * V_36 )
{
struct V_1 * V_2 , * V_321 ;
struct V_284 * V_285 = V_117 -> V_134 ;
struct V_65 * V_66 ;
if ( F_186 ( & V_285 -> V_322 ) ||
! F_267 ( V_36 , V_316 ) )
return 0 ;
V_66 = F_37 () ;
if ( ! V_66 )
return - V_74 ;
F_273 (cache, tmp, &cur_trans->dirty_bgs,
dirty_list) {
if ( V_2 -> V_309 == V_323 )
F_259 ( V_2 , V_117 , V_66 ) ;
}
F_56 ( V_66 ) ;
return 0 ;
}
int F_274 ( struct V_116 * V_117 ,
struct V_14 * V_36 )
{
struct V_1 * V_2 ;
struct V_284 * V_285 = V_117 -> V_134 ;
int V_31 = 0 ;
int V_324 ;
struct V_65 * V_66 = NULL ;
F_275 ( V_325 ) ;
struct V_111 * V_326 = & V_285 -> V_327 ;
int V_328 = 0 ;
int V_329 = 0 ;
F_12 ( & V_285 -> V_330 ) ;
if ( F_186 ( & V_285 -> V_322 ) ) {
F_14 ( & V_285 -> V_330 ) ;
return 0 ;
}
F_276 ( & V_285 -> V_322 , & V_325 ) ;
F_14 ( & V_285 -> V_330 ) ;
V_163:
F_231 ( V_117 , V_36 ) ;
if ( ! V_66 ) {
V_66 = F_37 () ;
if ( ! V_66 )
return - V_74 ;
}
F_52 ( & V_117 -> V_134 -> V_331 ) ;
while ( ! F_186 ( & V_325 ) ) {
V_2 = F_187 ( & V_325 ,
struct V_1 ,
V_332 ) ;
if ( ! F_186 ( & V_2 -> V_333 ) ) {
F_277 ( & V_2 -> V_333 ) ;
F_278 ( V_117 , V_2 , V_66 ) ;
F_6 ( V_2 ) ;
}
F_12 ( & V_285 -> V_330 ) ;
F_277 ( & V_2 -> V_332 ) ;
F_14 ( & V_285 -> V_330 ) ;
V_324 = 1 ;
F_259 ( V_2 , V_117 , V_66 ) ;
if ( V_2 -> V_309 == V_313 ) {
V_2 -> V_334 . V_302 = NULL ;
V_31 = F_279 ( V_36 , V_117 ,
V_2 , V_66 ) ;
if ( V_31 == 0 && V_2 -> V_334 . V_302 ) {
V_328 ++ ;
V_324 = 0 ;
F_75 ( & V_2 -> V_333 , V_326 ) ;
} else {
V_31 = 0 ;
}
}
if ( ! V_31 ) {
V_31 = F_254 ( V_117 , V_36 ,
V_66 , V_2 ) ;
if ( V_31 == - V_160 ) {
V_31 = 0 ;
F_12 ( & V_285 -> V_330 ) ;
if ( F_186 ( & V_2 -> V_332 ) ) {
F_75 ( & V_2 -> V_332 ,
& V_285 -> V_322 ) ;
F_4 ( V_2 ) ;
}
F_14 ( & V_285 -> V_330 ) ;
} else if ( V_31 ) {
F_165 ( V_117 , V_31 ) ;
}
}
if ( V_324 )
F_6 ( V_2 ) ;
if ( V_31 )
break;
F_50 ( & V_117 -> V_134 -> V_331 ) ;
F_52 ( & V_117 -> V_134 -> V_331 ) ;
}
F_50 ( & V_117 -> V_134 -> V_331 ) ;
V_31 = F_222 ( V_117 , V_36 , 0 ) ;
if ( ! V_31 && V_329 == 0 ) {
V_329 ++ ;
F_12 ( & V_285 -> V_330 ) ;
F_276 ( & V_285 -> V_322 , & V_325 ) ;
if ( ! F_186 ( & V_325 ) ) {
F_14 ( & V_285 -> V_330 ) ;
goto V_163;
}
F_14 ( & V_285 -> V_330 ) ;
} else if ( V_31 < 0 ) {
F_280 ( V_285 , V_36 ) ;
}
F_56 ( V_66 ) ;
return V_31 ;
}
int F_281 ( struct V_116 * V_117 ,
struct V_14 * V_36 )
{
struct V_1 * V_2 ;
struct V_284 * V_285 = V_117 -> V_134 ;
int V_31 = 0 ;
int V_324 ;
struct V_65 * V_66 ;
struct V_111 * V_326 = & V_285 -> V_327 ;
int V_328 = 0 ;
V_66 = F_37 () ;
if ( ! V_66 )
return - V_74 ;
F_12 ( & V_285 -> V_330 ) ;
while ( ! F_186 ( & V_285 -> V_322 ) ) {
V_2 = F_187 ( & V_285 -> V_322 ,
struct V_1 ,
V_332 ) ;
if ( ! F_186 ( & V_2 -> V_333 ) ) {
F_14 ( & V_285 -> V_330 ) ;
F_277 ( & V_2 -> V_333 ) ;
F_278 ( V_117 , V_2 , V_66 ) ;
F_6 ( V_2 ) ;
F_12 ( & V_285 -> V_330 ) ;
}
F_277 ( & V_2 -> V_332 ) ;
F_14 ( & V_285 -> V_330 ) ;
V_324 = 1 ;
F_259 ( V_2 , V_117 , V_66 ) ;
if ( ! V_31 )
V_31 = F_222 ( V_117 , V_36 ,
( unsigned long ) - 1 ) ;
if ( ! V_31 && V_2 -> V_309 == V_313 ) {
V_2 -> V_334 . V_302 = NULL ;
V_31 = F_279 ( V_36 , V_117 ,
V_2 , V_66 ) ;
if ( V_31 == 0 && V_2 -> V_334 . V_302 ) {
V_328 ++ ;
V_324 = 0 ;
F_75 ( & V_2 -> V_333 , V_326 ) ;
} else {
V_31 = 0 ;
}
}
if ( ! V_31 ) {
V_31 = F_254 ( V_117 , V_36 ,
V_66 , V_2 ) ;
if ( V_31 == - V_160 ) {
F_282 ( V_285 -> V_335 ,
F_215 ( & V_285 -> V_336 ) == 1 ) ;
V_31 = F_254 ( V_117 , V_36 ,
V_66 , V_2 ) ;
}
if ( V_31 )
F_165 ( V_117 , V_31 ) ;
}
if ( V_324 )
F_6 ( V_2 ) ;
F_12 ( & V_285 -> V_330 ) ;
}
F_14 ( & V_285 -> V_330 ) ;
while ( ! F_186 ( V_326 ) ) {
V_2 = F_187 ( V_326 , struct V_1 ,
V_333 ) ;
F_277 ( & V_2 -> V_333 ) ;
F_278 ( V_117 , V_2 , V_66 ) ;
F_6 ( V_2 ) ;
}
F_56 ( V_66 ) ;
return V_31 ;
}
int F_283 ( struct V_14 * V_36 , T_2 V_29 )
{
struct V_1 * V_16 ;
int V_337 = 0 ;
V_16 = F_79 ( V_36 , V_29 ) ;
if ( ! V_16 || V_16 -> V_311 )
V_337 = 1 ;
if ( V_16 )
F_6 ( V_16 ) ;
return V_337 ;
}
bool F_284 ( struct V_14 * V_36 , T_2 V_29 )
{
struct V_1 * V_338 ;
bool V_31 = true ;
V_338 = F_79 ( V_36 , V_29 ) ;
if ( ! V_338 )
return false ;
F_12 ( & V_338 -> V_50 ) ;
if ( V_338 -> V_311 )
V_31 = false ;
else
F_5 ( & V_338 -> V_339 ) ;
F_14 ( & V_338 -> V_50 ) ;
if ( ! V_31 )
F_6 ( V_338 ) ;
return V_31 ;
}
void F_285 ( struct V_14 * V_36 , T_2 V_29 )
{
struct V_1 * V_338 ;
V_338 = F_79 ( V_36 , V_29 ) ;
ASSERT ( V_338 ) ;
if ( F_7 ( & V_338 -> V_339 ) )
F_286 ( & V_338 -> V_339 ) ;
F_6 ( V_338 ) ;
F_6 ( V_338 ) ;
}
static int F_287 ( T_7 * V_340 )
{
F_71 () ;
return 0 ;
}
void F_288 ( struct V_1 * V_338 )
{
F_289 ( & V_338 -> V_339 ,
F_287 ,
V_101 ) ;
}
static const char * F_290 ( T_2 V_7 )
{
switch ( V_7 ) {
case V_53 | V_341 :
return L_4 ;
case V_53 :
return L_5 ;
case V_341 :
return L_6 ;
case V_342 :
return L_7 ;
default:
F_8 ( 1 ) ;
return L_8 ;
} ;
}
static int F_291 ( struct V_14 * V_15 , T_2 V_7 ,
T_2 V_343 , T_2 V_93 ,
T_2 V_344 ,
struct V_110 * * V_94 )
{
struct V_110 * V_113 ;
int V_42 ;
int V_345 ;
int V_31 ;
if ( V_7 & ( V_346 | V_347 |
V_348 ) )
V_345 = 2 ;
else
V_345 = 1 ;
V_113 = F_80 ( V_15 , V_7 ) ;
if ( V_113 ) {
F_12 ( & V_113 -> V_50 ) ;
V_113 -> V_343 += V_343 ;
V_113 -> V_349 += V_343 * V_345 ;
V_113 -> V_93 += V_93 ;
V_113 -> V_350 += V_93 * V_345 ;
V_113 -> V_344 += V_344 ;
if ( V_343 > 0 )
V_113 -> V_115 = 0 ;
F_292 ( V_15 , V_113 , V_343 -
V_93 - V_344 ) ;
F_14 ( & V_113 -> V_50 ) ;
* V_94 = V_113 ;
return 0 ;
}
V_113 = F_64 ( sizeof( * V_113 ) , V_97 ) ;
if ( ! V_113 )
return - V_74 ;
V_31 = F_293 ( & V_113 -> V_351 , 0 , V_352 ) ;
if ( V_31 ) {
F_10 ( V_113 ) ;
return V_31 ;
}
for ( V_42 = 0 ; V_42 < V_353 ; V_42 ++ )
F_65 ( & V_113 -> V_354 [ V_42 ] ) ;
F_294 ( & V_113 -> V_355 ) ;
F_295 ( & V_113 -> V_50 ) ;
V_113 -> V_7 = V_7 & V_114 ;
V_113 -> V_343 = V_343 ;
V_113 -> V_349 = V_343 * V_345 ;
V_113 -> V_93 = V_93 ;
V_113 -> V_350 = V_93 * V_345 ;
V_113 -> V_356 = 0 ;
V_113 -> V_357 = 0 ;
V_113 -> V_344 = V_344 ;
V_113 -> V_358 = 0 ;
V_113 -> V_115 = 0 ;
V_113 -> V_359 = 0 ;
V_113 -> V_360 = V_361 ;
V_113 -> V_362 = 0 ;
V_113 -> V_363 = 0 ;
F_67 ( & V_113 -> V_89 ) ;
F_65 ( & V_113 -> V_364 ) ;
F_65 ( & V_113 -> V_365 ) ;
F_65 ( & V_113 -> V_366 ) ;
V_31 = F_296 ( & V_113 -> V_367 , & V_368 ,
V_15 -> V_369 , L_9 ,
F_290 ( V_113 -> V_7 ) ) ;
if ( V_31 ) {
F_297 ( & V_113 -> V_351 ) ;
F_10 ( V_113 ) ;
return V_31 ;
}
* V_94 = V_113 ;
F_298 ( & V_113 -> V_98 , & V_15 -> V_94 ) ;
if ( V_7 & V_341 )
V_15 -> V_370 = V_113 ;
return V_31 ;
}
static void F_299 ( struct V_14 * V_36 , T_2 V_7 )
{
T_2 V_371 = F_300 ( V_7 ) &
V_372 ;
F_301 ( & V_36 -> V_373 ) ;
if ( V_7 & V_341 )
V_36 -> V_374 |= V_371 ;
if ( V_7 & V_53 )
V_36 -> V_375 |= V_371 ;
if ( V_7 & V_342 )
V_36 -> V_376 |= V_371 ;
F_302 ( & V_36 -> V_373 ) ;
}
static T_2 F_303 ( struct V_14 * V_36 , T_2 V_7 )
{
struct V_377 * V_378 = V_36 -> V_379 ;
T_2 V_380 = 0 ;
if ( ! V_378 )
return 0 ;
if ( V_7 & V_341 &&
V_378 -> V_381 . V_7 & V_382 ) {
V_380 = V_341 | V_378 -> V_381 . V_380 ;
} else if ( V_7 & V_342 &&
V_378 -> V_383 . V_7 & V_382 ) {
V_380 = V_342 | V_378 -> V_383 . V_380 ;
} else if ( V_7 & V_53 &&
V_378 -> V_384 . V_7 & V_382 ) {
V_380 = V_53 | V_378 -> V_384 . V_380 ;
}
return V_380 ;
}
static T_2 F_304 ( struct V_14 * V_36 , T_2 V_7 )
{
T_2 V_385 = V_36 -> V_386 -> V_387 ;
T_2 V_380 ;
T_2 V_388 ;
T_2 V_389 = 0 ;
F_12 ( & V_36 -> V_390 ) ;
V_380 = F_303 ( V_36 , V_7 ) ;
if ( V_380 ) {
if ( ( V_7 & V_380 ) & V_372 ) {
F_14 ( & V_36 -> V_390 ) ;
return F_305 ( V_380 ) ;
}
}
F_14 ( & V_36 -> V_390 ) ;
for ( V_388 = 0 ; V_388 < V_353 ; V_388 ++ ) {
if ( V_385 >= V_391 [ V_388 ] . V_392 )
V_389 |= V_393 [ V_388 ] ;
}
V_389 &= V_7 ;
if ( V_389 & V_394 )
V_389 = V_394 ;
else if ( V_389 & V_395 )
V_389 = V_395 ;
else if ( V_389 & V_348 )
V_389 = V_348 ;
else if ( V_389 & V_347 )
V_389 = V_347 ;
else if ( V_389 & V_396 )
V_389 = V_396 ;
V_7 &= ~ V_397 ;
return F_305 ( V_7 | V_389 ) ;
}
static T_2 F_306 ( struct V_14 * V_36 , T_2 V_398 )
{
unsigned V_237 ;
T_2 V_7 ;
do {
V_7 = V_398 ;
V_237 = F_307 ( & V_36 -> V_373 ) ;
if ( V_7 & V_341 )
V_7 |= V_36 -> V_374 ;
else if ( V_7 & V_342 )
V_7 |= V_36 -> V_376 ;
else if ( V_7 & V_53 )
V_7 |= V_36 -> V_375 ;
} while ( F_308 ( & V_36 -> V_373 , V_237 ) );
return F_304 ( V_36 , V_7 ) ;
}
T_2 F_309 ( struct V_63 * V_12 , int V_381 )
{
struct V_14 * V_36 = V_12 -> V_36 ;
T_2 V_7 ;
T_2 V_31 ;
if ( V_381 )
V_7 = V_341 ;
else if ( V_12 == V_36 -> V_399 )
V_7 = V_342 ;
else
V_7 = V_53 ;
V_31 = F_306 ( V_36 , V_7 ) ;
return V_31 ;
}
static T_2 F_310 ( struct V_110 * V_400 ,
bool V_401 )
{
ASSERT ( V_400 ) ;
return V_400 -> V_93 + V_400 -> V_357 +
V_400 -> V_356 + V_400 -> V_344 +
( V_401 ? V_400 -> V_358 : 0 ) ;
}
int F_311 ( struct V_402 * V_302 , T_2 V_211 )
{
struct V_110 * V_370 ;
struct V_63 * V_12 = V_302 -> V_12 ;
struct V_14 * V_36 = V_12 -> V_36 ;
T_2 V_403 ;
int V_31 = 0 ;
int V_404 = 2 ;
int V_405 ;
V_211 = F_152 ( V_211 , V_36 -> V_55 ) ;
if ( F_312 ( V_302 ) ) {
V_404 = 0 ;
ASSERT ( V_406 -> V_407 ) ;
}
V_370 = V_36 -> V_370 ;
if ( ! V_370 )
goto V_408;
V_163:
F_12 ( & V_370 -> V_50 ) ;
V_403 = F_310 ( V_370 , true ) ;
if ( V_403 + V_211 > V_370 -> V_343 ) {
struct V_116 * V_117 ;
if ( ! V_370 -> V_115 ) {
T_2 V_409 ;
V_370 -> V_360 = V_410 ;
F_14 ( & V_370 -> V_50 ) ;
V_408:
V_409 = F_309 ( V_12 , 1 ) ;
V_117 = F_219 ( V_12 ) ;
if ( F_220 ( V_117 ) )
return F_221 ( V_117 ) ;
V_31 = F_313 ( V_117 , V_36 , V_409 ,
V_361 ) ;
F_223 ( V_117 ) ;
if ( V_31 < 0 ) {
if ( V_31 != - V_318 )
return V_31 ;
else {
V_405 = 1 ;
goto V_411;
}
}
if ( ! V_370 )
V_370 = V_36 -> V_370 ;
goto V_163;
}
V_405 = F_314 (
& V_370 -> V_351 ,
V_403 + V_211 - V_370 -> V_343 ) ;
F_14 ( & V_370 -> V_50 ) ;
V_411:
if ( V_404 &&
! F_215 ( & V_36 -> V_412 ) ) {
V_404 -- ;
if ( V_404 > 0 ) {
F_315 ( V_36 , 0 , - 1 ) ;
F_316 ( V_36 , - 1 , 0 ,
( T_2 ) - 1 ) ;
}
V_117 = F_219 ( V_12 ) ;
if ( F_220 ( V_117 ) )
return F_221 ( V_117 ) ;
if ( V_405 >= 0 ||
F_229 ( V_413 ,
& V_117 -> V_134 -> V_7 ) ||
V_404 > 0 ) {
V_31 = F_317 ( V_117 ) ;
if ( V_31 )
return V_31 ;
F_52 ( & V_36 -> V_414 ) ;
F_50 ( & V_36 -> V_414 ) ;
goto V_163;
} else {
F_223 ( V_117 ) ;
}
}
F_318 ( V_36 ,
L_10 ,
V_370 -> V_7 , V_211 , 1 ) ;
return - V_318 ;
}
V_370 -> V_358 += V_211 ;
F_318 ( V_36 , L_11 ,
V_370 -> V_7 , V_211 , 1 ) ;
F_14 ( & V_370 -> V_50 ) ;
return V_31 ;
}
int F_268 ( struct V_302 * V_302 , T_2 V_34 , T_2 V_47 )
{
struct V_14 * V_36 = F_319 ( V_302 -> V_415 ) ;
int V_31 ;
V_47 = F_320 ( V_34 + V_47 , V_36 -> V_55 ) -
F_153 ( V_34 , V_36 -> V_55 ) ;
V_34 = F_153 ( V_34 , V_36 -> V_55 ) ;
V_31 = F_311 ( F_263 ( V_302 ) , V_47 ) ;
if ( V_31 < 0 )
return V_31 ;
V_31 = F_321 ( V_302 , V_34 , V_47 ) ;
if ( V_31 )
F_322 ( V_302 , V_34 , V_47 ) ;
return V_31 ;
}
void F_322 ( struct V_302 * V_302 , T_2 V_34 ,
T_2 V_47 )
{
struct V_14 * V_36 = F_319 ( V_302 -> V_415 ) ;
struct V_110 * V_370 ;
V_47 = F_320 ( V_34 + V_47 , V_36 -> V_55 ) -
F_153 ( V_34 , V_36 -> V_55 ) ;
V_34 = F_153 ( V_34 , V_36 -> V_55 ) ;
V_370 = V_36 -> V_370 ;
F_12 ( & V_370 -> V_50 ) ;
if ( F_8 ( V_370 -> V_358 < V_47 ) )
V_370 -> V_358 = 0 ;
else
V_370 -> V_358 -= V_47 ;
F_318 ( V_36 , L_11 ,
V_370 -> V_7 , V_47 , 0 ) ;
F_14 ( & V_370 -> V_50 ) ;
}
void F_323 ( struct V_302 * V_302 , T_2 V_34 , T_2 V_47 )
{
struct V_63 * V_12 = F_263 ( V_302 ) -> V_12 ;
V_47 = F_320 ( V_34 + V_47 , V_12 -> V_36 -> V_55 ) -
F_153 ( V_34 , V_12 -> V_36 -> V_55 ) ;
V_34 = F_153 ( V_34 , V_12 -> V_36 -> V_55 ) ;
F_322 ( V_302 , V_34 , V_47 ) ;
F_324 ( V_302 , V_34 , V_47 ) ;
}
static void F_325 ( struct V_14 * V_15 )
{
struct V_111 * V_112 = & V_15 -> V_94 ;
struct V_110 * V_113 ;
F_81 () ;
F_82 (found, head, list) {
if ( V_113 -> V_7 & V_53 )
V_113 -> V_360 = V_410 ;
}
F_83 () ;
}
static inline T_2 F_326 ( struct V_262 * V_416 )
{
return ( V_416 -> V_59 << 1 ) ;
}
static int F_327 ( struct V_14 * V_36 ,
struct V_110 * V_417 , int V_418 )
{
struct V_262 * V_263 = & V_36 -> V_266 ;
T_2 V_37 = V_417 -> V_343 - V_417 -> V_344 ;
T_2 V_419 = V_417 -> V_93 + V_417 -> V_357 ;
T_2 V_420 ;
if ( V_418 == V_410 )
return 1 ;
if ( V_417 -> V_7 & V_53 )
V_419 += F_326 ( V_263 ) ;
if ( V_418 == V_421 ) {
V_420 = F_328 ( V_36 -> V_261 ) ;
V_420 = F_38 ( T_2 , V_422 , F_329 ( V_420 , 1 ) ) ;
if ( V_37 - V_419 < V_420 )
return 1 ;
}
if ( V_419 + V_423 < F_330 ( V_37 , 8 ) )
return 0 ;
return 1 ;
}
static T_2 F_331 ( struct V_14 * V_36 , T_2 type )
{
T_2 V_424 ;
if ( type & ( V_348 |
V_396 |
V_395 |
V_394 ) )
V_424 = V_36 -> V_386 -> V_387 ;
else if ( type & V_347 )
V_424 = 2 ;
else
V_424 = 1 ;
return V_424 ;
}
void F_332 ( struct V_116 * V_117 ,
struct V_14 * V_36 , T_2 type )
{
struct V_110 * V_15 ;
T_2 V_425 ;
T_2 V_420 ;
int V_31 = 0 ;
T_2 V_426 ;
ASSERT ( F_333 ( & V_36 -> V_427 ) ) ;
V_15 = F_80 ( V_36 , V_342 ) ;
F_12 ( & V_15 -> V_50 ) ;
V_425 = V_15 -> V_343 - F_310 ( V_15 , true ) ;
F_14 ( & V_15 -> V_50 ) ;
V_426 = F_331 ( V_36 , type ) ;
V_420 = F_334 ( V_36 , V_426 ) +
F_213 ( V_36 , 1 ) ;
if ( V_425 < V_420 && F_267 ( V_36 , V_428 ) ) {
F_335 ( V_36 , L_12 ,
V_425 , V_420 , type ) ;
F_336 ( V_36 , V_15 , 0 , 0 ) ;
}
if ( V_425 < V_420 ) {
T_2 V_7 ;
V_7 = F_309 ( V_36 -> V_399 , 0 ) ;
V_31 = F_337 ( V_117 , V_36 , V_7 ) ;
}
if ( ! V_31 ) {
V_31 = F_338 ( V_36 -> V_399 ,
& V_36 -> V_429 ,
V_420 , V_430 ) ;
if ( ! V_31 )
V_117 -> V_431 += V_420 ;
}
}
static int F_313 ( struct V_116 * V_117 ,
struct V_14 * V_36 , T_2 V_7 , int V_418 )
{
struct V_110 * V_94 ;
int V_432 = 0 ;
int V_31 = 0 ;
if ( V_117 -> V_433 )
return - V_318 ;
V_94 = F_80 ( V_36 , V_7 ) ;
if ( ! V_94 ) {
V_31 = F_291 ( V_36 , V_7 , 0 , 0 , 0 , & V_94 ) ;
F_35 ( V_31 ) ;
}
F_35 ( ! V_94 ) ;
V_163:
F_12 ( & V_94 -> V_50 ) ;
if ( V_418 < V_94 -> V_360 )
V_418 = V_94 -> V_360 ;
if ( V_94 -> V_115 ) {
if ( F_327 ( V_36 , V_94 , V_418 ) )
V_31 = - V_318 ;
else
V_31 = 0 ;
F_14 ( & V_94 -> V_50 ) ;
return V_31 ;
}
if ( ! F_327 ( V_36 , V_94 , V_418 ) ) {
F_14 ( & V_94 -> V_50 ) ;
return 0 ;
} else if ( V_94 -> V_362 ) {
V_432 = 1 ;
} else {
V_94 -> V_362 = 1 ;
}
F_14 ( & V_94 -> V_50 ) ;
F_52 ( & V_36 -> V_427 ) ;
if ( V_432 ) {
F_50 ( & V_36 -> V_427 ) ;
V_432 = 0 ;
goto V_163;
}
V_117 -> V_433 = true ;
if ( F_339 ( V_94 ) )
V_7 |= ( V_341 | V_53 ) ;
if ( V_7 & V_341 && V_36 -> V_434 ) {
V_36 -> V_435 ++ ;
if ( ! ( V_36 -> V_435 %
V_36 -> V_434 ) )
F_325 ( V_36 ) ;
}
F_332 ( V_117 , V_36 , V_7 ) ;
V_31 = F_337 ( V_117 , V_36 , V_7 ) ;
V_117 -> V_433 = false ;
F_12 ( & V_94 -> V_50 ) ;
if ( V_31 < 0 && V_31 != - V_318 )
goto V_81;
if ( V_31 )
V_94 -> V_115 = 1 ;
else
V_31 = 1 ;
V_94 -> V_360 = V_361 ;
V_81:
V_94 -> V_362 = 0 ;
F_14 ( & V_94 -> V_50 ) ;
F_50 ( & V_36 -> V_427 ) ;
if ( V_117 -> V_279 &&
V_117 -> V_431 >= ( T_2 ) V_423 ) {
F_231 ( V_117 , V_36 ) ;
F_340 ( V_117 ) ;
}
return V_31 ;
}
static int F_341 ( struct V_63 * V_12 ,
struct V_110 * V_94 , T_2 V_211 ,
enum V_436 V_363 )
{
struct V_14 * V_36 = V_12 -> V_36 ;
struct V_262 * V_263 = & V_36 -> V_266 ;
T_2 V_437 ;
T_2 V_438 ;
T_2 V_439 ;
T_2 V_403 ;
if ( V_94 -> V_7 & V_341 )
return 0 ;
V_437 = F_309 ( V_12 , 0 ) ;
V_403 = F_310 ( V_94 , false ) ;
F_12 ( & V_263 -> V_50 ) ;
V_438 = F_326 ( V_263 ) ;
F_14 ( & V_263 -> V_50 ) ;
if ( V_403 + V_438 >= V_94 -> V_343 )
return 0 ;
V_403 += V_94 -> V_358 ;
F_12 ( & V_36 -> V_440 ) ;
V_439 = V_36 -> V_441 ;
F_14 ( & V_36 -> V_440 ) ;
if ( V_437 & ( V_346 |
V_347 |
V_348 ) )
V_439 >>= 1 ;
if ( V_363 == V_442 )
V_439 >>= 3 ;
else
V_439 >>= 1 ;
if ( V_403 + V_211 < V_94 -> V_343 + V_439 )
return 1 ;
return 0 ;
}
static void F_342 ( struct V_14 * V_36 ,
unsigned long V_443 , int V_444 )
{
struct V_445 * V_446 = V_36 -> V_446 ;
if ( F_343 ( & V_446 -> V_447 ) ) {
F_344 ( V_446 , V_443 , V_448 ) ;
F_49 ( & V_446 -> V_447 ) ;
} else {
F_315 ( V_36 , 0 , V_444 ) ;
if ( ! V_406 -> V_407 )
F_316 ( V_36 , V_444 , 0 , ( T_2 ) - 1 ) ;
}
}
static inline int F_345 ( struct V_14 * V_36 ,
T_2 V_449 )
{
T_2 V_211 ;
int V_43 ;
V_211 = F_213 ( V_36 , 1 ) ;
V_43 = ( int ) F_210 ( V_449 , V_211 ) ;
if ( ! V_43 )
V_43 = 1 ;
return V_43 ;
}
static void F_346 ( struct V_63 * V_12 , T_2 V_449 , T_2 V_450 ,
bool V_451 )
{
struct V_14 * V_36 = V_12 -> V_36 ;
struct V_262 * V_452 ;
struct V_110 * V_94 ;
struct V_116 * V_117 ;
T_2 V_453 ;
T_2 V_454 ;
long V_455 ;
unsigned long V_443 ;
int V_329 ;
int V_456 ;
enum V_436 V_363 ;
V_456 = F_345 ( V_36 , V_449 ) ;
V_449 = ( T_2 ) V_456 * V_457 ;
V_117 = (struct V_116 * ) V_406 -> V_407 ;
V_452 = & V_36 -> V_458 ;
V_94 = V_452 -> V_94 ;
V_453 = F_347 (
& V_36 -> V_453 ) ;
if ( V_453 == 0 ) {
if ( V_117 )
return;
if ( V_451 )
F_316 ( V_36 , V_456 , 0 , ( T_2 ) - 1 ) ;
return;
}
V_329 = 0 ;
while ( V_453 && V_329 < 3 ) {
V_454 = F_348 ( V_453 , V_449 ) ;
V_443 = V_454 >> V_459 ;
F_342 ( V_36 , V_443 , V_456 ) ;
V_454 = F_215 ( & V_36 -> V_460 ) ;
if ( ! V_454 )
goto V_461;
if ( V_454 <= V_443 )
V_454 = 0 ;
else
V_454 -= V_443 ;
F_282 ( V_36 -> V_462 ,
F_215 ( & V_36 -> V_460 ) <=
( int ) V_454 ) ;
V_461:
if ( ! V_117 )
V_363 = V_442 ;
else
V_363 = V_430 ;
F_12 ( & V_94 -> V_50 ) ;
if ( F_341 ( V_12 , V_94 , V_450 , V_363 ) ) {
F_14 ( & V_94 -> V_50 ) ;
break;
}
if ( F_186 ( & V_94 -> V_365 ) &&
F_186 ( & V_94 -> V_366 ) ) {
F_14 ( & V_94 -> V_50 ) ;
break;
}
F_14 ( & V_94 -> V_50 ) ;
V_329 ++ ;
if ( V_451 && ! V_117 ) {
F_316 ( V_36 , V_456 , 0 , ( T_2 ) - 1 ) ;
} else {
V_455 = F_349 ( 1 ) ;
if ( V_455 )
break;
}
V_453 = F_347 (
& V_36 -> V_453 ) ;
}
}
static int F_350 ( struct V_14 * V_36 ,
struct V_110 * V_94 ,
T_2 V_211 , int V_418 )
{
struct V_262 * V_463 = & V_36 -> V_464 ;
struct V_116 * V_117 ;
V_117 = (struct V_116 * ) V_406 -> V_407 ;
if ( V_117 )
return - V_186 ;
if ( V_418 )
goto V_465;
if ( F_314 ( & V_94 -> V_351 ,
V_211 ) >= 0 )
goto V_465;
if ( V_94 != V_463 -> V_94 )
return - V_318 ;
F_12 ( & V_463 -> V_50 ) ;
if ( F_314 ( & V_94 -> V_351 ,
V_211 - V_463 -> V_59 ) >= 0 ) {
F_14 ( & V_463 -> V_50 ) ;
return - V_318 ;
}
F_14 ( & V_463 -> V_50 ) ;
V_465:
V_117 = F_219 ( V_36 -> V_64 ) ;
if ( F_220 ( V_117 ) )
return - V_318 ;
return F_317 ( V_117 ) ;
}
static int F_351 ( struct V_14 * V_36 ,
struct V_110 * V_94 , T_2 V_37 ,
T_2 V_466 , int V_297 )
{
struct V_63 * V_12 = V_36 -> V_64 ;
struct V_116 * V_117 ;
int V_43 ;
int V_31 = 0 ;
switch ( V_297 ) {
case V_467 :
case V_468 :
if ( V_297 == V_467 )
V_43 = F_345 ( V_36 , V_37 ) * 2 ;
else
V_43 = - 1 ;
V_117 = F_219 ( V_12 ) ;
if ( F_220 ( V_117 ) ) {
V_31 = F_221 ( V_117 ) ;
break;
}
V_31 = F_352 ( V_117 , V_36 , V_43 ) ;
F_223 ( V_117 ) ;
break;
case V_469 :
case V_470 :
F_346 ( V_12 , V_37 * 2 , V_466 ,
V_297 == V_470 ) ;
break;
case V_471 :
V_117 = F_219 ( V_12 ) ;
if ( F_220 ( V_117 ) ) {
V_31 = F_221 ( V_117 ) ;
break;
}
V_31 = F_313 ( V_117 , V_36 ,
F_309 ( V_12 , 0 ) ,
V_361 ) ;
F_223 ( V_117 ) ;
if ( V_31 > 0 || V_31 == - V_318 )
V_31 = 0 ;
break;
case V_472 :
V_31 = F_350 ( V_36 , V_94 ,
V_466 , 0 ) ;
break;
default:
V_31 = - V_318 ;
break;
}
F_353 ( V_36 , V_94 -> V_7 , V_37 ,
V_466 , V_297 , V_31 ) ;
return V_31 ;
}
static inline T_2
F_354 ( struct V_63 * V_12 ,
struct V_110 * V_94 )
{
struct V_473 * V_474 ;
T_2 V_403 ;
T_2 V_475 ;
T_2 V_449 = 0 ;
F_237 (ticket, &space_info->tickets, list)
V_449 += V_474 -> V_211 ;
F_237 (ticket, &space_info->priority_tickets, list)
V_449 += V_474 -> V_211 ;
if ( V_449 )
return V_449 ;
V_449 = F_25 ( T_2 , F_355 () * V_308 , V_476 ) ;
if ( F_341 ( V_12 , V_94 , V_449 ,
V_442 ) )
return 0 ;
V_403 = V_94 -> V_93 + V_94 -> V_357 +
V_94 -> V_356 + V_94 -> V_344 +
V_94 -> V_358 ;
if ( F_341 ( V_12 , V_94 , V_308 , V_442 ) )
V_475 = F_329 ( V_94 -> V_343 , 95 ) ;
else
V_475 = F_329 ( V_94 -> V_343 , 90 ) ;
if ( V_403 > V_475 )
V_449 = V_403 - V_475 ;
else
V_449 = 0 ;
V_449 = F_348 ( V_449 , V_94 -> V_358 +
V_94 -> V_357 ) ;
return V_449 ;
}
static inline int F_356 ( struct V_110 * V_94 ,
struct V_63 * V_12 , T_2 V_403 )
{
struct V_14 * V_36 = V_12 -> V_36 ;
T_2 V_420 = F_329 ( V_94 -> V_343 , 98 ) ;
if ( ( V_94 -> V_93 + V_94 -> V_357 ) >= V_420 )
return 0 ;
if ( ! F_354 ( V_12 , V_94 ) )
return 0 ;
return ( V_403 >= V_420 && ! F_43 ( V_36 ) &&
! F_229 ( V_477 , & V_36 -> V_478 ) ) ;
}
static void F_357 ( struct V_111 * V_112 )
{
struct V_473 * V_474 ;
while ( ! F_186 ( V_112 ) ) {
V_474 = F_187 ( V_112 , struct V_473 , V_98 ) ;
F_277 ( & V_474 -> V_98 ) ;
V_474 -> error = - V_318 ;
F_55 ( & V_474 -> V_89 ) ;
}
}
static void F_358 ( struct V_479 * V_91 )
{
struct V_14 * V_36 ;
struct V_110 * V_94 ;
T_2 V_449 ;
int V_480 ;
int V_481 = 0 ;
T_2 V_482 ;
V_36 = F_58 ( V_91 , struct V_14 , V_483 ) ;
V_94 = F_80 ( V_36 , V_53 ) ;
F_12 ( & V_94 -> V_50 ) ;
V_449 = F_354 ( V_36 -> V_484 ,
V_94 ) ;
if ( ! V_449 ) {
V_94 -> V_363 = 0 ;
F_14 ( & V_94 -> V_50 ) ;
return;
}
V_482 = V_94 -> V_485 ;
F_14 ( & V_94 -> V_50 ) ;
V_480 = V_467 ;
do {
struct V_473 * V_474 ;
int V_31 ;
V_31 = F_351 ( V_36 , V_94 , V_449 , V_449 ,
V_480 ) ;
F_12 ( & V_94 -> V_50 ) ;
if ( F_186 ( & V_94 -> V_365 ) ) {
V_94 -> V_363 = 0 ;
F_14 ( & V_94 -> V_50 ) ;
return;
}
V_449 = F_354 ( V_36 -> V_484 ,
V_94 ) ;
V_474 = F_187 ( & V_94 -> V_365 ,
struct V_473 , V_98 ) ;
if ( V_482 == V_94 -> V_485 ) {
V_480 ++ ;
} else {
V_482 = V_94 -> V_485 ;
V_480 = V_467 ;
if ( V_481 )
V_481 -- ;
}
if ( V_480 > V_472 ) {
V_481 ++ ;
if ( V_481 > 2 ) {
F_357 ( & V_94 -> V_365 ) ;
V_94 -> V_363 = 0 ;
} else {
V_480 = V_467 ;
}
}
F_14 ( & V_94 -> V_50 ) ;
} while ( V_480 <= V_472 );
}
void F_359 ( struct V_479 * V_91 )
{
F_360 ( V_91 , F_358 ) ;
}
static void F_361 ( struct V_14 * V_36 ,
struct V_110 * V_94 ,
struct V_473 * V_474 )
{
T_2 V_449 ;
int V_480 = V_467 ;
F_12 ( & V_94 -> V_50 ) ;
V_449 = F_354 ( V_36 -> V_64 ,
V_94 ) ;
if ( ! V_449 ) {
F_14 ( & V_94 -> V_50 ) ;
return;
}
F_14 ( & V_94 -> V_50 ) ;
do {
F_351 ( V_36 , V_94 , V_449 , V_449 ,
V_480 ) ;
V_480 ++ ;
F_12 ( & V_94 -> V_50 ) ;
if ( V_474 -> V_211 == 0 ) {
F_14 ( & V_94 -> V_50 ) ;
return;
}
F_14 ( & V_94 -> V_50 ) ;
if ( V_480 == V_469 ||
V_480 == V_470 )
V_480 = V_471 ;
} while ( V_480 < V_472 );
}
static int F_362 ( struct V_14 * V_36 ,
struct V_110 * V_94 ,
struct V_473 * V_474 , T_2 V_466 )
{
F_63 ( V_89 ) ;
int V_31 = 0 ;
F_12 ( & V_94 -> V_50 ) ;
while ( V_474 -> V_211 > 0 && V_474 -> error == 0 ) {
V_31 = F_363 ( & V_474 -> V_89 , & V_89 , V_486 ) ;
if ( V_31 ) {
V_31 = - V_487 ;
break;
}
F_14 ( & V_94 -> V_50 ) ;
F_71 () ;
F_72 ( & V_474 -> V_89 , & V_89 ) ;
F_12 ( & V_94 -> V_50 ) ;
}
if ( ! V_31 )
V_31 = V_474 -> error ;
if ( ! F_186 ( & V_474 -> V_98 ) )
F_277 ( & V_474 -> V_98 ) ;
if ( V_474 -> V_211 && V_474 -> V_211 < V_466 ) {
T_2 V_37 = V_466 - V_474 -> V_211 ;
V_94 -> V_358 -= V_37 ;
F_318 ( V_36 , L_11 ,
V_94 -> V_7 , V_37 , 0 ) ;
}
F_14 ( & V_94 -> V_50 ) ;
return V_31 ;
}
static int F_364 ( struct V_63 * V_12 ,
struct V_110 * V_94 ,
T_2 V_466 ,
enum V_436 V_363 )
{
struct V_14 * V_36 = V_12 -> V_36 ;
struct V_473 V_474 ;
T_2 V_403 ;
int V_31 = 0 ;
ASSERT ( V_466 ) ;
ASSERT ( ! V_406 -> V_407 || V_363 != V_442 ) ;
F_12 ( & V_94 -> V_50 ) ;
V_31 = - V_318 ;
V_403 = F_310 ( V_94 , true ) ;
if ( V_403 + V_466 <= V_94 -> V_343 ) {
V_94 -> V_358 += V_466 ;
F_318 ( V_36 , L_11 ,
V_94 -> V_7 , V_466 , 1 ) ;
V_31 = 0 ;
} else if ( F_341 ( V_12 , V_94 , V_466 , V_363 ) ) {
V_94 -> V_358 += V_466 ;
F_318 ( V_36 , L_11 ,
V_94 -> V_7 , V_466 , 1 ) ;
V_31 = 0 ;
}
if ( V_31 && V_363 != V_430 ) {
V_474 . V_211 = V_466 ;
V_474 . error = 0 ;
F_67 ( & V_474 . V_89 ) ;
if ( V_363 == V_442 ) {
F_75 ( & V_474 . V_98 , & V_94 -> V_365 ) ;
if ( ! V_94 -> V_363 ) {
V_94 -> V_363 = 1 ;
F_365 ( V_36 ,
V_94 -> V_7 ,
V_466 , V_363 ,
L_13 ) ;
F_366 ( V_488 ,
& V_12 -> V_36 -> V_483 ) ;
}
} else {
F_75 ( & V_474 . V_98 ,
& V_94 -> V_366 ) ;
}
} else if ( ! V_31 && V_94 -> V_7 & V_53 ) {
V_403 += V_466 ;
if ( ! F_229 ( V_489 , & V_36 -> V_7 ) &&
F_356 ( V_94 , V_12 , V_403 ) &&
! F_367 ( & V_36 -> V_483 ) ) {
F_365 ( V_36 , V_94 -> V_7 ,
V_466 , V_363 , L_14 ) ;
F_366 ( V_488 ,
& V_36 -> V_483 ) ;
}
}
F_14 ( & V_94 -> V_50 ) ;
if ( ! V_31 || V_363 == V_430 )
return V_31 ;
if ( V_363 == V_442 )
return F_362 ( V_36 , V_94 , & V_474 ,
V_466 ) ;
V_31 = 0 ;
F_361 ( V_36 , V_94 , & V_474 ) ;
F_12 ( & V_94 -> V_50 ) ;
if ( V_474 . V_211 ) {
if ( V_474 . V_211 < V_466 ) {
T_2 V_37 = V_466 - V_474 . V_211 ;
V_94 -> V_358 -= V_37 ;
F_318 ( V_36 , L_11 ,
V_94 -> V_7 ,
V_37 , 0 ) ;
}
F_277 ( & V_474 . V_98 ) ;
V_31 = - V_318 ;
}
F_14 ( & V_94 -> V_50 ) ;
ASSERT ( F_186 ( & V_474 . V_98 ) ) ;
return V_31 ;
}
static int F_368 ( struct V_63 * V_12 ,
struct V_262 * V_452 ,
T_2 V_466 ,
enum V_436 V_363 )
{
struct V_14 * V_36 = V_12 -> V_36 ;
struct V_262 * V_263 = & V_36 -> V_266 ;
int V_31 ;
V_31 = F_364 ( V_12 , V_452 -> V_94 , V_466 ,
V_363 ) ;
if ( V_31 == - V_318 &&
F_369 ( V_12 -> V_490 == V_491 ) ) {
if ( V_452 != V_263 &&
! F_370 ( V_263 , V_466 ) )
V_31 = 0 ;
}
if ( V_31 == - V_318 )
F_318 ( V_36 , L_10 ,
V_452 -> V_94 -> V_7 ,
V_466 , 1 ) ;
return V_31 ;
}
static struct V_262 * F_371 (
const struct V_116 * V_117 ,
const struct V_63 * V_12 )
{
struct V_14 * V_36 = V_12 -> V_36 ;
struct V_262 * V_452 = NULL ;
if ( F_229 ( V_296 , & V_12 -> V_297 ) ||
( V_12 == V_36 -> V_492 && V_117 -> V_493 ) ||
( V_12 == V_36 -> V_494 ) )
V_452 = V_117 -> V_452 ;
if ( ! V_452 )
V_452 = V_12 -> V_452 ;
if ( ! V_452 )
V_452 = & V_36 -> V_495 ;
return V_452 ;
}
static int F_370 ( struct V_262 * V_452 ,
T_2 V_37 )
{
int V_31 = - V_318 ;
F_12 ( & V_452 -> V_50 ) ;
if ( V_452 -> V_10 >= V_37 ) {
V_452 -> V_10 -= V_37 ;
if ( V_452 -> V_10 < V_452 -> V_59 )
V_452 -> V_115 = 0 ;
V_31 = 0 ;
}
F_14 ( & V_452 -> V_50 ) ;
return V_31 ;
}
static void F_372 ( struct V_262 * V_452 ,
T_2 V_37 , int V_496 )
{
F_12 ( & V_452 -> V_50 ) ;
V_452 -> V_10 += V_37 ;
if ( V_496 )
V_452 -> V_59 += V_37 ;
else if ( V_452 -> V_10 >= V_452 -> V_59 )
V_452 -> V_115 = 1 ;
F_14 ( & V_452 -> V_50 ) ;
}
int F_373 ( struct V_14 * V_36 ,
struct V_262 * V_497 , T_2 V_37 ,
int V_498 )
{
struct V_262 * V_263 = & V_36 -> V_266 ;
T_2 V_499 ;
if ( V_263 -> V_94 != V_497 -> V_94 )
return - V_318 ;
F_12 ( & V_263 -> V_50 ) ;
V_499 = F_330 ( V_263 -> V_59 , V_498 ) ;
if ( V_263 -> V_10 < V_499 + V_37 ) {
F_14 ( & V_263 -> V_50 ) ;
return - V_318 ;
}
V_263 -> V_10 -= V_37 ;
if ( V_263 -> V_10 < V_263 -> V_59 )
V_263 -> V_115 = 0 ;
F_14 ( & V_263 -> V_50 ) ;
F_372 ( V_497 , V_37 , 1 ) ;
return 0 ;
}
static void F_374 ( struct V_14 * V_36 ,
struct V_110 * V_94 ,
T_2 V_37 )
{
struct V_473 * V_474 ;
struct V_111 * V_112 ;
T_2 V_403 ;
enum V_436 V_363 = V_430 ;
bool V_500 = false ;
F_12 ( & V_94 -> V_50 ) ;
V_112 = & V_94 -> V_366 ;
V_403 = V_94 -> V_93 + V_94 -> V_357 +
V_94 -> V_356 + V_94 -> V_344 +
V_94 -> V_358 ;
if ( V_403 - V_37 >= V_94 -> V_343 )
V_500 = true ;
V_163:
while ( ! F_186 ( V_112 ) && V_37 ) {
V_474 = F_187 ( V_112 , struct V_473 ,
V_98 ) ;
if ( V_500 &&
! F_341 ( V_36 -> V_64 , V_94 , 0 ,
V_363 ) )
break;
if ( V_37 >= V_474 -> V_211 ) {
F_277 ( & V_474 -> V_98 ) ;
V_37 -= V_474 -> V_211 ;
V_474 -> V_211 = 0 ;
V_94 -> V_485 ++ ;
F_55 ( & V_474 -> V_89 ) ;
} else {
V_474 -> V_211 -= V_37 ;
V_37 = 0 ;
}
}
if ( V_37 && V_112 == & V_94 -> V_366 ) {
V_112 = & V_94 -> V_365 ;
V_363 = V_442 ;
goto V_163;
}
V_94 -> V_358 -= V_37 ;
F_318 ( V_36 , L_11 ,
V_94 -> V_7 , V_37 , 0 ) ;
F_14 ( & V_94 -> V_50 ) ;
}
static void F_292 ( struct V_14 * V_36 ,
struct V_110 * V_94 ,
T_2 V_37 )
{
struct V_473 * V_474 ;
struct V_111 * V_112 = & V_94 -> V_366 ;
V_163:
while ( ! F_186 ( V_112 ) && V_37 ) {
V_474 = F_187 ( V_112 , struct V_473 ,
V_98 ) ;
if ( V_37 >= V_474 -> V_211 ) {
F_318 ( V_36 , L_11 ,
V_94 -> V_7 ,
V_474 -> V_211 , 1 ) ;
F_277 ( & V_474 -> V_98 ) ;
V_37 -= V_474 -> V_211 ;
V_94 -> V_358 += V_474 -> V_211 ;
V_474 -> V_211 = 0 ;
V_94 -> V_485 ++ ;
F_55 ( & V_474 -> V_89 ) ;
} else {
F_318 ( V_36 , L_11 ,
V_94 -> V_7 ,
V_37 , 1 ) ;
V_94 -> V_358 += V_37 ;
V_474 -> V_211 -= V_37 ;
V_37 = 0 ;
}
}
if ( V_37 && V_112 == & V_94 -> V_366 ) {
V_112 = & V_94 -> V_365 ;
goto V_163;
}
}
static void F_375 ( struct V_14 * V_36 ,
struct V_262 * V_452 ,
struct V_262 * V_497 , T_2 V_37 )
{
struct V_110 * V_94 = V_452 -> V_94 ;
F_12 ( & V_452 -> V_50 ) ;
if ( V_37 == ( T_2 ) - 1 )
V_37 = V_452 -> V_59 ;
V_452 -> V_59 -= V_37 ;
if ( V_452 -> V_10 >= V_452 -> V_59 ) {
V_37 = V_452 -> V_10 - V_452 -> V_59 ;
V_452 -> V_10 = V_452 -> V_59 ;
V_452 -> V_115 = 1 ;
} else {
V_37 = 0 ;
}
F_14 ( & V_452 -> V_50 ) ;
if ( V_37 > 0 ) {
if ( V_497 ) {
F_12 ( & V_497 -> V_50 ) ;
if ( ! V_497 -> V_115 ) {
T_2 V_501 ;
V_501 = V_497 -> V_59 - V_497 -> V_10 ;
V_501 = F_348 ( V_37 , V_501 ) ;
V_497 -> V_10 += V_501 ;
if ( V_497 -> V_10 >= V_497 -> V_59 )
V_497 -> V_115 = 1 ;
V_37 -= V_501 ;
}
F_14 ( & V_497 -> V_50 ) ;
}
if ( V_37 )
F_374 ( V_36 , V_94 ,
V_37 ) ;
}
}
int F_376 ( struct V_262 * V_502 ,
struct V_262 * V_503 , T_2 V_37 ,
int V_496 )
{
int V_31 ;
V_31 = F_370 ( V_502 , V_37 ) ;
if ( V_31 )
return V_31 ;
F_372 ( V_503 , V_37 , V_496 ) ;
return 0 ;
}
void F_377 ( struct V_262 * V_504 , unsigned short type )
{
memset ( V_504 , 0 , sizeof( * V_504 ) ) ;
F_295 ( & V_504 -> V_50 ) ;
V_504 -> type = type ;
}
struct V_262 * F_378 ( struct V_14 * V_36 ,
unsigned short type )
{
struct V_262 * V_452 ;
V_452 = F_226 ( sizeof( * V_452 ) , V_97 ) ;
if ( ! V_452 )
return NULL ;
F_377 ( V_452 , type ) ;
V_452 -> V_94 = F_80 ( V_36 ,
V_53 ) ;
return V_452 ;
}
void F_379 ( struct V_14 * V_36 ,
struct V_262 * V_504 )
{
if ( ! V_504 )
return;
F_380 ( V_36 , V_504 , ( T_2 ) - 1 ) ;
F_10 ( V_504 ) ;
}
void F_381 ( struct V_262 * V_504 )
{
F_10 ( V_504 ) ;
}
int F_338 ( struct V_63 * V_12 ,
struct V_262 * V_452 , T_2 V_37 ,
enum V_436 V_363 )
{
int V_31 ;
if ( V_37 == 0 )
return 0 ;
V_31 = F_368 ( V_12 , V_452 , V_37 , V_363 ) ;
if ( ! V_31 ) {
F_372 ( V_452 , V_37 , 1 ) ;
return 0 ;
}
return V_31 ;
}
int F_382 ( struct V_262 * V_452 , int V_498 )
{
T_2 V_37 = 0 ;
int V_31 = - V_318 ;
if ( ! V_452 )
return 0 ;
F_12 ( & V_452 -> V_50 ) ;
V_37 = F_330 ( V_452 -> V_59 , V_498 ) ;
if ( V_452 -> V_10 >= V_37 )
V_31 = 0 ;
F_14 ( & V_452 -> V_50 ) ;
return V_31 ;
}
int F_383 ( struct V_63 * V_12 ,
struct V_262 * V_452 , T_2 V_505 ,
enum V_436 V_363 )
{
T_2 V_37 = 0 ;
int V_31 = - V_318 ;
if ( ! V_452 )
return 0 ;
F_12 ( & V_452 -> V_50 ) ;
V_37 = V_505 ;
if ( V_452 -> V_10 >= V_37 )
V_31 = 0 ;
else
V_37 -= V_452 -> V_10 ;
F_14 ( & V_452 -> V_50 ) ;
if ( ! V_31 )
return 0 ;
V_31 = F_368 ( V_12 , V_452 , V_37 , V_363 ) ;
if ( ! V_31 ) {
F_372 ( V_452 , V_37 , 0 ) ;
return 0 ;
}
return V_31 ;
}
void F_380 ( struct V_14 * V_36 ,
struct V_262 * V_452 ,
T_2 V_37 )
{
struct V_262 * V_263 = & V_36 -> V_266 ;
if ( V_263 == V_452 ||
V_452 -> V_94 != V_263 -> V_94 )
V_263 = NULL ;
F_375 ( V_36 , V_452 , V_263 , V_37 ) ;
}
static void F_384 ( struct V_14 * V_36 )
{
struct V_262 * V_452 = & V_36 -> V_266 ;
struct V_110 * V_417 = V_452 -> V_94 ;
T_2 V_37 ;
V_37 = F_385 ( & V_36 -> V_64 -> V_288 ) +
F_385 ( & V_36 -> V_492 -> V_288 ) +
F_385 ( & V_36 -> V_275 -> V_288 ) ;
V_37 = F_38 ( T_2 , V_37 , V_476 ) ;
F_12 ( & V_417 -> V_50 ) ;
F_12 ( & V_452 -> V_50 ) ;
V_452 -> V_59 = F_25 ( T_2 , V_37 , V_506 ) ;
if ( V_452 -> V_10 < V_452 -> V_59 ) {
V_37 = F_310 ( V_417 , true ) ;
if ( V_417 -> V_343 > V_37 ) {
V_37 = V_417 -> V_343 - V_37 ;
V_37 = F_348 ( V_37 ,
V_452 -> V_59 - V_452 -> V_10 ) ;
V_452 -> V_10 += V_37 ;
V_417 -> V_358 += V_37 ;
F_318 ( V_36 , L_11 ,
V_417 -> V_7 , V_37 ,
1 ) ;
}
} else if ( V_452 -> V_10 > V_452 -> V_59 ) {
V_37 = V_452 -> V_10 - V_452 -> V_59 ;
V_417 -> V_358 -= V_37 ;
F_318 ( V_36 , L_11 ,
V_417 -> V_7 , V_37 , 0 ) ;
V_452 -> V_10 = V_452 -> V_59 ;
}
if ( V_452 -> V_10 == V_452 -> V_59 )
V_452 -> V_115 = 1 ;
else
V_452 -> V_115 = 0 ;
F_14 ( & V_452 -> V_50 ) ;
F_14 ( & V_417 -> V_50 ) ;
}
static void F_386 ( struct V_14 * V_36 )
{
struct V_110 * V_94 ;
V_94 = F_80 ( V_36 , V_342 ) ;
V_36 -> V_429 . V_94 = V_94 ;
V_94 = F_80 ( V_36 , V_53 ) ;
V_36 -> V_266 . V_94 = V_94 ;
V_36 -> V_458 . V_94 = V_94 ;
V_36 -> V_507 . V_94 = V_94 ;
V_36 -> V_495 . V_94 = V_94 ;
V_36 -> V_464 . V_94 = V_94 ;
V_36 -> V_64 -> V_452 = & V_36 -> V_266 ;
V_36 -> V_492 -> V_452 = & V_36 -> V_266 ;
V_36 -> V_508 -> V_452 = & V_36 -> V_266 ;
V_36 -> V_275 -> V_452 = & V_36 -> V_266 ;
if ( V_36 -> V_509 )
V_36 -> V_509 -> V_452 = & V_36 -> V_266 ;
V_36 -> V_399 -> V_452 = & V_36 -> V_429 ;
F_384 ( V_36 ) ;
}
static void F_387 ( struct V_14 * V_36 )
{
F_375 ( V_36 , & V_36 -> V_266 , NULL ,
( T_2 ) - 1 ) ;
F_8 ( V_36 -> V_458 . V_59 > 0 ) ;
F_8 ( V_36 -> V_458 . V_10 > 0 ) ;
F_8 ( V_36 -> V_507 . V_59 > 0 ) ;
F_8 ( V_36 -> V_507 . V_10 > 0 ) ;
F_8 ( V_36 -> V_429 . V_59 > 0 ) ;
F_8 ( V_36 -> V_429 . V_10 > 0 ) ;
F_8 ( V_36 -> V_464 . V_59 > 0 ) ;
F_8 ( V_36 -> V_464 . V_10 > 0 ) ;
}
void F_388 ( struct V_116 * V_117 ,
struct V_14 * V_36 )
{
if ( ! V_117 -> V_452 )
return;
if ( ! V_117 -> V_357 )
return;
F_318 ( V_36 , L_15 ,
V_117 -> V_274 , V_117 -> V_357 , 0 ) ;
F_380 ( V_36 , V_117 -> V_452 ,
V_117 -> V_357 ) ;
V_117 -> V_357 = 0 ;
}
void F_340 ( struct V_116 * V_117 )
{
struct V_14 * V_36 = V_117 -> V_36 ;
if ( ! V_117 -> V_431 )
return;
F_389 ( ! F_186 ( & V_117 -> V_282 ) ) ;
F_375 ( V_36 , & V_36 -> V_429 , NULL ,
V_117 -> V_431 ) ;
V_117 -> V_431 = 0 ;
}
int F_390 ( struct V_116 * V_117 ,
struct V_402 * V_302 )
{
struct V_14 * V_36 = F_319 ( V_302 -> V_510 . V_415 ) ;
struct V_63 * V_12 = V_302 -> V_12 ;
struct V_262 * V_511 = V_117 -> V_452 ;
struct V_262 * V_512 = V_12 -> V_513 ;
T_2 V_37 = F_213 ( V_36 , 1 ) ;
F_318 ( V_36 , L_16 , F_391 ( V_302 ) ,
V_37 , 1 ) ;
return F_376 ( V_511 , V_512 , V_37 , 1 ) ;
}
void F_392 ( struct V_402 * V_302 )
{
struct V_14 * V_36 = F_319 ( V_302 -> V_510 . V_415 ) ;
struct V_63 * V_12 = V_302 -> V_12 ;
T_2 V_37 = F_213 ( V_36 , 1 ) ;
F_318 ( V_36 , L_16 , F_391 ( V_302 ) ,
V_37 , 0 ) ;
F_380 ( V_36 , V_12 -> V_513 , V_37 ) ;
}
int F_393 ( struct V_63 * V_12 ,
struct V_262 * V_504 ,
int V_456 ,
T_2 * V_230 ,
bool V_514 )
{
T_2 V_37 ;
int V_31 ;
struct V_14 * V_36 = V_12 -> V_36 ;
struct V_262 * V_263 = & V_36 -> V_266 ;
if ( F_229 ( V_515 , & V_36 -> V_7 ) ) {
V_37 = 3 * V_36 -> V_54 ;
V_31 = F_394 ( V_12 , V_37 , true ) ;
if ( V_31 )
return V_31 ;
} else {
V_37 = 0 ;
}
* V_230 = V_37 ;
V_37 = F_213 ( V_36 , V_456 ) ;
V_504 -> V_94 = F_80 ( V_36 ,
V_53 ) ;
V_31 = F_338 ( V_12 , V_504 , V_37 ,
V_442 ) ;
if ( V_31 == - V_318 && V_514 )
V_31 = F_376 ( V_263 , V_504 , V_37 , 1 ) ;
if ( V_31 && * V_230 )
F_395 ( V_12 , * V_230 ) ;
return V_31 ;
}
void F_396 ( struct V_14 * V_36 ,
struct V_262 * V_504 )
{
F_380 ( V_36 , V_504 , ( T_2 ) - 1 ) ;
}
static unsigned F_397 ( struct V_402 * V_302 ,
T_2 V_37 )
{
unsigned V_516 = 0 ;
unsigned V_517 = 0 ;
unsigned V_518 ;
V_518 = F_398 ( V_37 ) ;
ASSERT ( V_518 ) ;
ASSERT ( V_302 -> V_519 >= V_518 ) ;
V_302 -> V_519 -= V_518 ;
if ( V_302 -> V_519 == 0 &&
F_399 ( V_520 ,
& V_302 -> V_521 ) )
V_516 = 1 ;
if ( V_302 -> V_519 >= V_302 -> V_522 )
return V_516 ;
V_517 = V_302 -> V_522 - V_302 -> V_519 ;
V_302 -> V_522 -= V_517 ;
return V_517 + V_516 ;
}
static T_2 F_400 ( struct V_402 * V_302 , T_2 V_37 ,
int V_523 )
{
struct V_14 * V_36 = F_319 ( V_302 -> V_510 . V_415 ) ;
T_2 V_524 , V_260 ;
if ( V_302 -> V_7 & V_525 && V_302 -> V_257 == 0 )
return 0 ;
V_524 = F_208 ( V_36 , V_302 -> V_257 ) ;
if ( V_523 )
V_302 -> V_257 += V_37 ;
else
V_302 -> V_257 -= V_37 ;
V_260 = F_208 ( V_36 , V_302 -> V_257 ) ;
if ( V_524 == V_260 )
return 0 ;
if ( V_523 )
return F_213 ( V_36 ,
V_260 - V_524 ) ;
return F_213 ( V_36 , V_524 - V_260 ) ;
}
int F_401 ( struct V_402 * V_302 , T_2 V_37 )
{
struct V_14 * V_36 = F_319 ( V_302 -> V_510 . V_415 ) ;
struct V_63 * V_12 = V_302 -> V_12 ;
struct V_262 * V_452 = & V_36 -> V_458 ;
T_2 V_526 = 0 ;
T_2 V_257 ;
unsigned V_527 ;
enum V_436 V_363 = V_442 ;
int V_31 = 0 ;
bool V_528 = true ;
T_2 V_529 = 0 ;
unsigned V_530 ;
bool V_531 = false ;
if ( F_312 ( V_302 ) ) {
V_363 = V_430 ;
V_528 = false ;
} else if ( V_406 -> V_407 ) {
V_363 = V_532 ;
}
if ( V_363 != V_430 &&
F_402 ( V_36 ) )
F_403 ( 1 ) ;
if ( V_528 )
F_52 ( & V_302 -> V_533 ) ;
V_37 = F_152 ( V_37 , V_36 -> V_55 ) ;
F_12 ( & V_302 -> V_50 ) ;
V_527 = F_398 ( V_37 ) ;
V_302 -> V_519 += V_527 ;
V_527 = 0 ;
if ( V_302 -> V_519 > V_302 -> V_522 )
V_527 += V_302 -> V_519 -
V_302 -> V_522 ;
V_526 = F_213 ( V_36 , V_527 + 1 ) ;
V_526 += F_400 ( V_302 , V_37 , 1 ) ;
V_257 = V_302 -> V_257 ;
F_14 ( & V_302 -> V_50 ) ;
if ( F_229 ( V_515 , & V_36 -> V_7 ) ) {
V_31 = F_394 ( V_12 ,
V_527 * V_36 -> V_54 , true ) ;
if ( V_31 )
goto V_534;
}
V_31 = F_338 ( V_12 , V_452 , V_526 , V_363 ) ;
if ( F_369 ( V_31 ) ) {
F_395 ( V_12 ,
V_527 * V_36 -> V_54 ) ;
goto V_534;
}
F_12 ( & V_302 -> V_50 ) ;
if ( F_404 ( V_520 ,
& V_302 -> V_521 ) ) {
V_526 -= F_213 ( V_36 , 1 ) ;
V_531 = true ;
}
V_302 -> V_522 += V_527 ;
F_14 ( & V_302 -> V_50 ) ;
if ( V_528 )
F_50 ( & V_302 -> V_533 ) ;
if ( V_526 )
F_318 ( V_36 , L_17 ,
F_391 ( V_302 ) , V_526 , 1 ) ;
if ( V_531 )
F_380 ( V_36 , V_452 ,
F_213 ( V_36 , 1 ) ) ;
return 0 ;
V_534:
F_12 ( & V_302 -> V_50 ) ;
V_530 = F_397 ( V_302 , V_37 ) ;
if ( V_302 -> V_257 == V_257 ) {
F_400 ( V_302 , V_37 , 0 ) ;
} else {
T_2 V_535 = V_302 -> V_257 ;
T_2 V_211 ;
V_211 = V_257 - V_302 -> V_257 ;
V_302 -> V_257 = V_257 ;
V_529 = F_400 ( V_302 , V_211 , 0 ) ;
V_302 -> V_257 = V_257 - V_37 ;
V_211 = V_257 - V_535 ;
V_211 = F_400 ( V_302 , V_211 , 0 ) ;
V_302 -> V_257 = V_535 - V_37 ;
if ( V_211 > V_529 )
V_529 = V_211 - V_529 ;
else
V_529 = 0 ;
}
F_14 ( & V_302 -> V_50 ) ;
if ( V_530 )
V_529 += F_213 ( V_36 , V_530 ) ;
if ( V_529 ) {
F_380 ( V_36 , V_452 , V_529 ) ;
F_318 ( V_36 , L_17 ,
F_391 ( V_302 ) , V_529 , 0 ) ;
}
if ( V_528 )
F_50 ( & V_302 -> V_533 ) ;
return V_31 ;
}
void F_405 ( struct V_402 * V_302 , T_2 V_37 )
{
struct V_14 * V_36 = F_319 ( V_302 -> V_510 . V_415 ) ;
T_2 V_529 = 0 ;
unsigned V_530 ;
V_37 = F_152 ( V_37 , V_36 -> V_55 ) ;
F_12 ( & V_302 -> V_50 ) ;
V_530 = F_397 ( V_302 , V_37 ) ;
if ( V_37 )
V_529 = F_400 ( V_302 , V_37 , 0 ) ;
F_14 ( & V_302 -> V_50 ) ;
if ( V_530 > 0 )
V_529 += F_213 ( V_36 , V_530 ) ;
if ( F_244 ( V_36 ) )
return;
F_318 ( V_36 , L_17 , F_391 ( V_302 ) ,
V_529 , 0 ) ;
F_380 ( V_36 , & V_36 -> V_458 , V_529 ) ;
}
int F_406 ( struct V_302 * V_302 , T_2 V_34 , T_2 V_47 )
{
int V_31 ;
V_31 = F_268 ( V_302 , V_34 , V_47 ) ;
if ( V_31 < 0 )
return V_31 ;
V_31 = F_401 ( F_263 ( V_302 ) , V_47 ) ;
if ( V_31 < 0 )
F_323 ( V_302 , V_34 , V_47 ) ;
return V_31 ;
}
void F_407 ( struct V_302 * V_302 , T_2 V_34 , T_2 V_47 )
{
F_405 ( F_263 ( V_302 ) , V_47 ) ;
F_323 ( V_302 , V_34 , V_47 ) ;
}
static int F_408 ( struct V_116 * V_117 ,
struct V_14 * V_15 , T_2 V_29 ,
T_2 V_37 , int V_408 )
{
struct V_1 * V_2 = NULL ;
T_2 V_536 = V_37 ;
T_2 V_537 ;
T_2 V_538 ;
int V_345 ;
F_12 ( & V_15 -> V_539 ) ;
V_537 = F_409 ( V_15 -> V_261 ) ;
if ( V_408 )
V_537 += V_37 ;
else
V_537 -= V_37 ;
F_410 ( V_15 -> V_261 , V_537 ) ;
F_14 ( & V_15 -> V_539 ) ;
while ( V_536 ) {
V_2 = F_79 ( V_15 , V_29 ) ;
if ( ! V_2 )
return - V_160 ;
if ( V_2 -> V_7 & ( V_346 |
V_347 |
V_348 ) )
V_345 = 2 ;
else
V_345 = 1 ;
if ( ! V_408 && V_2 -> V_3 == V_102 )
F_62 ( V_2 , 1 ) ;
V_538 = V_29 - V_2 -> V_23 . V_24 ;
F_8 ( V_538 > V_2 -> V_23 . V_35 ) ;
F_12 ( & V_2 -> V_94 -> V_50 ) ;
F_12 ( & V_2 -> V_50 ) ;
if ( F_267 ( V_15 , V_316 ) &&
V_2 -> V_309 < V_323 )
V_2 -> V_309 = V_323 ;
V_537 = F_61 ( & V_2 -> V_95 ) ;
V_37 = F_348 ( V_536 , V_2 -> V_23 . V_35 - V_538 ) ;
if ( V_408 ) {
V_537 += V_37 ;
F_411 ( & V_2 -> V_95 , V_537 ) ;
V_2 -> V_10 -= V_37 ;
V_2 -> V_94 -> V_357 -= V_37 ;
V_2 -> V_94 -> V_93 += V_37 ;
V_2 -> V_94 -> V_350 += V_37 * V_345 ;
F_14 ( & V_2 -> V_50 ) ;
F_14 ( & V_2 -> V_94 -> V_50 ) ;
} else {
V_537 -= V_37 ;
F_411 ( & V_2 -> V_95 , V_537 ) ;
V_2 -> V_9 += V_37 ;
V_2 -> V_94 -> V_356 += V_37 ;
V_2 -> V_94 -> V_93 -= V_37 ;
V_2 -> V_94 -> V_350 -= V_37 * V_345 ;
F_14 ( & V_2 -> V_50 ) ;
F_14 ( & V_2 -> V_94 -> V_50 ) ;
F_318 ( V_15 , L_18 ,
V_2 -> V_94 -> V_7 ,
V_37 , 1 ) ;
F_412 ( V_15 -> V_61 ,
V_29 , V_29 + V_37 - 1 ,
V_97 | V_540 ) ;
}
F_12 ( & V_117 -> V_134 -> V_330 ) ;
if ( F_186 ( & V_2 -> V_332 ) ) {
F_75 ( & V_2 -> V_332 ,
& V_117 -> V_134 -> V_322 ) ;
V_117 -> V_134 -> V_264 ++ ;
F_4 ( V_2 ) ;
}
F_14 ( & V_117 -> V_134 -> V_330 ) ;
if ( ! V_408 && V_537 == 0 ) {
F_12 ( & V_15 -> V_541 ) ;
if ( F_186 ( & V_2 -> V_542 ) ) {
F_4 ( V_2 ) ;
F_75 ( & V_2 -> V_542 ,
& V_15 -> V_543 ) ;
}
F_14 ( & V_15 -> V_541 ) ;
}
F_6 ( V_2 ) ;
V_536 -= V_37 ;
V_29 += V_37 ;
}
return 0 ;
}
static T_2 V_28 ( struct V_14 * V_36 , T_2 V_544 )
{
struct V_1 * V_2 ;
T_2 V_29 ;
F_12 ( & V_36 -> V_20 ) ;
V_29 = V_36 -> V_28 ;
F_14 ( & V_36 -> V_20 ) ;
if ( V_29 < ( T_2 ) - 1 )
return V_29 ;
V_2 = F_78 ( V_36 , V_544 ) ;
if ( ! V_2 )
return 0 ;
V_29 = V_2 -> V_23 . V_24 ;
F_6 ( V_2 ) ;
return V_29 ;
}
static int F_413 ( struct V_14 * V_36 ,
struct V_1 * V_2 ,
T_2 V_29 , T_2 V_37 , int V_10 )
{
F_12 ( & V_2 -> V_94 -> V_50 ) ;
F_12 ( & V_2 -> V_50 ) ;
V_2 -> V_9 += V_37 ;
V_2 -> V_94 -> V_356 += V_37 ;
if ( V_10 ) {
V_2 -> V_10 -= V_37 ;
V_2 -> V_94 -> V_357 -= V_37 ;
}
F_14 ( & V_2 -> V_50 ) ;
F_14 ( & V_2 -> V_94 -> V_50 ) ;
F_318 ( V_36 , L_18 ,
V_2 -> V_94 -> V_7 , V_37 , 1 ) ;
F_412 ( V_36 -> V_61 , V_29 ,
V_29 + V_37 - 1 , V_97 | V_540 ) ;
return 0 ;
}
int F_179 ( struct V_14 * V_36 ,
T_2 V_29 , T_2 V_37 , int V_10 )
{
struct V_1 * V_2 ;
V_2 = F_79 ( V_36 , V_29 ) ;
F_35 ( ! V_2 ) ;
F_413 ( V_36 , V_2 , V_29 , V_37 , V_10 ) ;
F_6 ( V_2 ) ;
return 0 ;
}
int F_414 ( struct V_14 * V_36 ,
T_2 V_29 , T_2 V_37 )
{
struct V_1 * V_2 ;
int V_31 ;
V_2 = F_79 ( V_36 , V_29 ) ;
if ( ! V_2 )
return - V_545 ;
F_62 ( V_2 , 1 ) ;
F_413 ( V_36 , V_2 , V_29 , V_37 , 0 ) ;
V_31 = F_31 ( V_2 , V_29 , V_37 ) ;
F_6 ( V_2 ) ;
return V_31 ;
}
static int F_415 ( struct V_14 * V_36 ,
T_2 V_34 , T_2 V_37 )
{
int V_31 ;
struct V_1 * V_16 ;
struct V_48 * V_51 ;
V_16 = F_79 ( V_36 , V_34 ) ;
if ( ! V_16 )
return - V_545 ;
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
goto V_546;
V_37 = ( V_34 + V_37 ) -
V_51 -> V_85 ;
V_34 = V_51 -> V_85 ;
V_31 = F_18 ( V_36 , V_34 , V_37 ) ;
}
V_546:
F_50 ( & V_51 -> V_86 ) ;
F_28 ( V_51 ) ;
}
F_6 ( V_16 ) ;
return V_31 ;
}
int F_416 ( struct V_14 * V_36 ,
struct V_67 * V_547 )
{
struct V_294 * V_95 ;
struct V_69 V_23 ;
int V_548 ;
int V_42 ;
if ( ! F_87 ( V_36 , V_549 ) )
return 0 ;
for ( V_42 = 0 ; V_42 < F_42 ( V_547 ) ; V_42 ++ ) {
F_44 ( V_547 , & V_23 , V_42 ) ;
if ( V_23 . type != V_299 )
continue;
V_95 = F_89 ( V_547 , V_42 , struct V_294 ) ;
V_548 = F_247 ( V_547 , V_95 ) ;
if ( V_548 == V_300 )
continue;
if ( F_248 ( V_547 , V_95 ) == 0 )
continue;
V_23 . V_24 = F_248 ( V_547 , V_95 ) ;
V_23 . V_35 = F_249 ( V_547 , V_95 ) ;
F_415 ( V_36 , V_23 . V_24 , V_23 . V_35 ) ;
}
return 0 ;
}
static void
F_417 ( struct V_1 * V_338 )
{
F_5 ( & V_338 -> V_550 ) ;
}
void F_418 ( struct V_14 * V_36 ,
const T_2 V_34 )
{
struct V_1 * V_338 ;
V_338 = F_79 ( V_36 , V_34 ) ;
ASSERT ( V_338 ) ;
if ( F_7 ( & V_338 -> V_550 ) )
F_286 ( & V_338 -> V_550 ) ;
F_6 ( V_338 ) ;
}
static int F_419 ( T_7 * V_340 )
{
F_71 () ;
return 0 ;
}
void F_420 ( struct V_1 * V_338 )
{
struct V_110 * V_94 = V_338 -> V_94 ;
ASSERT ( V_338 -> V_311 ) ;
if ( ! ( V_338 -> V_7 & V_341 ) )
return;
F_74 ( & V_94 -> V_355 ) ;
F_76 ( & V_94 -> V_355 ) ;
F_289 ( & V_338 -> V_550 ,
F_419 ,
V_101 ) ;
}
static int F_421 ( struct V_1 * V_2 ,
T_2 V_551 , T_2 V_37 , int V_552 )
{
struct V_110 * V_94 = V_2 -> V_94 ;
int V_31 = 0 ;
F_12 ( & V_94 -> V_50 ) ;
F_12 ( & V_2 -> V_50 ) ;
if ( V_2 -> V_311 ) {
V_31 = - V_186 ;
} else {
V_2 -> V_10 += V_37 ;
V_94 -> V_357 += V_37 ;
F_318 ( V_2 -> V_36 ,
L_11 , V_94 -> V_7 ,
V_551 , 0 ) ;
V_94 -> V_358 -= V_551 ;
if ( V_552 )
V_2 -> V_453 += V_37 ;
}
F_14 ( & V_2 -> V_50 ) ;
F_14 ( & V_94 -> V_50 ) ;
return V_31 ;
}
static int F_422 ( struct V_1 * V_2 ,
T_2 V_37 , int V_552 )
{
struct V_110 * V_94 = V_2 -> V_94 ;
int V_31 = 0 ;
F_12 ( & V_94 -> V_50 ) ;
F_12 ( & V_2 -> V_50 ) ;
if ( V_2 -> V_311 )
V_94 -> V_344 += V_37 ;
V_2 -> V_10 -= V_37 ;
V_94 -> V_357 -= V_37 ;
if ( V_552 )
V_2 -> V_453 -= V_37 ;
F_14 ( & V_2 -> V_50 ) ;
F_14 ( & V_94 -> V_50 ) ;
return V_31 ;
}
void F_423 ( struct V_14 * V_36 )
{
struct V_48 * V_80 ;
struct V_48 * V_51 ;
struct V_1 * V_2 ;
F_74 ( & V_36 -> V_84 ) ;
F_273 (caching_ctl, next,
&fs_info->caching_block_groups, list) {
V_2 = V_51 -> V_16 ;
if ( F_1 ( V_2 ) ) {
V_2 -> V_105 = ( T_2 ) - 1 ;
F_277 ( & V_51 -> V_98 ) ;
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
F_384 ( V_36 ) ;
}
static struct V_553 *
F_424 ( struct V_14 * V_36 ,
struct V_110 * V_94 , T_2 * V_554 )
{
struct V_553 * V_31 = NULL ;
bool V_555 = F_267 ( V_36 , V_556 ) ;
* V_554 = 0 ;
if ( F_339 ( V_94 ) )
return V_31 ;
if ( V_555 )
* V_554 = V_423 ;
if ( V_94 -> V_7 & V_53 ) {
V_31 = & V_36 -> V_557 ;
if ( ! V_555 )
* V_554 = V_558 ;
} else if ( ( V_94 -> V_7 & V_341 ) && V_555 ) {
V_31 = & V_36 -> V_559 ;
}
return V_31 ;
}
static int F_425 ( struct V_14 * V_36 ,
T_2 V_34 , T_2 V_33 ,
const bool V_560 )
{
struct V_1 * V_2 = NULL ;
struct V_110 * V_94 ;
struct V_262 * V_263 = & V_36 -> V_266 ;
struct V_553 * V_561 = NULL ;
T_2 V_47 ;
T_2 V_562 = 0 ;
T_2 V_554 = 0 ;
bool V_337 ;
while ( V_34 <= V_33 ) {
V_337 = false ;
if ( ! V_2 ||
V_34 >= V_2 -> V_23 . V_24 + V_2 -> V_23 . V_35 ) {
if ( V_2 )
F_6 ( V_2 ) ;
V_562 = 0 ;
V_2 = F_79 ( V_36 , V_34 ) ;
F_35 ( ! V_2 ) ;
V_561 = F_424 ( V_36 ,
V_2 -> V_94 ,
& V_554 ) ;
V_554 <<= 1 ;
}
V_47 = V_2 -> V_23 . V_24 + V_2 -> V_23 . V_35 - V_34 ;
V_47 = F_348 ( V_47 , V_33 + 1 - V_34 ) ;
if ( V_34 < V_2 -> V_105 ) {
V_47 = F_348 ( V_47 , V_2 -> V_105 - V_34 ) ;
if ( V_560 )
F_34 ( V_2 , V_34 , V_47 ) ;
}
V_34 += V_47 ;
V_562 += V_47 ;
V_94 = V_2 -> V_94 ;
if ( V_561 && V_561 -> V_563 &&
V_562 > V_554 ) {
F_12 ( & V_561 -> V_50 ) ;
V_561 -> V_563 = 0 ;
F_14 ( & V_561 -> V_50 ) ;
}
F_12 ( & V_94 -> V_50 ) ;
F_12 ( & V_2 -> V_50 ) ;
V_2 -> V_9 -= V_47 ;
V_94 -> V_356 -= V_47 ;
F_318 ( V_36 , L_18 ,
V_94 -> V_7 , V_47 , 0 ) ;
V_94 -> V_359 = 0 ;
F_426 ( & V_94 -> V_351 , - V_47 ) ;
if ( V_2 -> V_311 ) {
V_94 -> V_344 += V_47 ;
V_337 = true ;
}
F_14 ( & V_2 -> V_50 ) ;
if ( ! V_337 && V_560 &&
V_263 -> V_94 == V_94 ) {
T_2 V_564 = V_47 ;
F_8 ( ! V_560 ) ;
F_12 ( & V_263 -> V_50 ) ;
if ( ! V_263 -> V_115 ) {
V_564 = F_348 ( V_47 , V_263 -> V_59 -
V_263 -> V_10 ) ;
V_263 -> V_10 += V_564 ;
V_94 -> V_358 += V_564 ;
if ( V_263 -> V_10 >= V_263 -> V_59 )
V_263 -> V_115 = 1 ;
F_318 ( V_36 ,
L_11 ,
V_94 -> V_7 ,
V_564 , 1 ) ;
V_47 -= V_564 ;
}
F_14 ( & V_263 -> V_50 ) ;
if ( V_47 )
F_292 ( V_36 , V_94 ,
V_47 ) ;
}
F_14 ( & V_94 -> V_50 ) ;
}
if ( V_2 )
F_6 ( V_2 ) ;
return 0 ;
}
int F_427 ( struct V_116 * V_117 ,
struct V_14 * V_36 )
{
struct V_1 * V_16 , * V_321 ;
struct V_111 * V_565 ;
struct V_566 * V_567 ;
T_2 V_34 ;
T_2 V_33 ;
int V_31 ;
if ( V_36 -> V_61 == & V_36 -> V_38 [ 0 ] )
V_567 = & V_36 -> V_38 [ 1 ] ;
else
V_567 = & V_36 -> V_38 [ 0 ] ;
while ( ! V_117 -> V_227 ) {
F_52 ( & V_36 -> V_568 ) ;
V_31 = F_33 ( V_567 , 0 , & V_34 , & V_33 ,
V_62 , NULL ) ;
if ( V_31 ) {
F_50 ( & V_36 -> V_568 ) ;
break;
}
if ( F_267 ( V_36 , V_569 ) )
V_31 = F_156 ( V_36 , V_34 ,
V_33 + 1 - V_34 , NULL ) ;
F_428 ( V_567 , V_34 , V_33 ) ;
F_425 ( V_36 , V_34 , V_33 , true ) ;
F_50 ( & V_36 -> V_568 ) ;
F_51 () ;
}
V_565 = & V_117 -> V_134 -> V_565 ;
F_273 (block_group, tmp, deleted_bgs, bg_list) {
T_2 V_570 = 0 ;
V_31 = - V_571 ;
if ( ! V_117 -> V_227 )
V_31 = F_156 ( V_36 ,
V_16 -> V_23 . V_24 ,
V_16 -> V_23 . V_35 ,
& V_570 ) ;
F_277 ( & V_16 -> V_542 ) ;
F_429 ( V_16 ) ;
F_6 ( V_16 ) ;
if ( V_31 ) {
const char * V_572 = F_430 ( V_31 ) ;
F_431 ( V_36 ,
L_19 ,
V_31 , V_572 ) ;
}
}
return 0 ;
}
static void F_432 ( struct V_14 * V_36 , T_2 V_37 ,
T_2 V_140 , T_2 V_152 )
{
struct V_110 * V_94 ;
T_2 V_7 ;
if ( V_140 < V_149 ) {
if ( V_152 == V_573 )
V_7 = V_342 ;
else
V_7 = V_53 ;
} else {
V_7 = V_341 ;
}
V_94 = F_80 ( V_36 , V_7 ) ;
F_35 ( ! V_94 ) ;
F_426 ( & V_94 -> V_351 , V_37 ) ;
}
static int F_170 ( struct V_116 * V_117 ,
struct V_14 * V_15 ,
struct V_218 * V_135 , T_2 V_19 ,
T_2 V_152 , T_2 V_574 ,
T_2 V_575 , int V_167 ,
struct V_188 * V_136 )
{
struct V_69 V_23 ;
struct V_65 * V_66 ;
struct V_63 * V_64 = V_15 -> V_64 ;
struct V_67 * V_68 ;
struct V_123 * V_124 ;
struct V_171 * V_172 ;
int V_31 ;
int V_192 ;
int V_576 = 0 ;
int V_577 = 0 ;
int V_578 = 1 ;
T_3 V_125 ;
T_2 V_119 ;
T_2 V_29 = V_135 -> V_29 ;
T_2 V_37 = V_135 -> V_37 ;
int V_168 = 0 ;
bool V_181 = F_87 ( V_15 , V_128 ) ;
V_66 = F_37 () ;
if ( ! V_66 )
return - V_74 ;
V_66 -> V_77 = V_78 ;
V_66 -> V_219 = 1 ;
V_192 = V_574 >= V_149 ;
F_35 ( ! V_192 && V_167 != 1 ) ;
if ( V_192 )
V_181 = 0 ;
V_31 = F_145 ( V_117 , V_15 , V_66 , & V_172 ,
V_29 , V_37 , V_19 ,
V_152 , V_574 ,
V_575 ) ;
if ( V_31 == 0 ) {
V_576 = V_66 -> V_83 [ 0 ] ;
while ( V_576 >= 0 ) {
F_44 ( V_66 -> V_82 [ 0 ] , & V_23 ,
V_576 ) ;
if ( V_23 . V_24 != V_29 )
break;
if ( V_23 . type == V_79 &&
V_23 . V_35 == V_37 ) {
V_577 = 1 ;
break;
}
if ( V_23 . type == V_87 &&
V_23 . V_35 == V_574 ) {
V_577 = 1 ;
break;
}
if ( V_66 -> V_83 [ 0 ] - V_576 > 5 )
break;
V_576 -- ;
}
#ifdef F_92
V_125 = F_88 ( V_66 -> V_82 [ 0 ] , V_576 ) ;
if ( V_577 && V_125 < sizeof( * V_124 ) )
V_577 = 0 ;
#endif
if ( ! V_577 ) {
F_35 ( V_172 ) ;
V_31 = F_150 ( V_117 , V_15 , V_66 , NULL ,
V_167 ,
V_192 , & V_168 ) ;
if ( V_31 ) {
F_165 ( V_117 , V_31 ) ;
goto V_81;
}
F_48 ( V_66 ) ;
V_66 -> V_219 = 1 ;
V_23 . V_24 = V_29 ;
V_23 . type = V_79 ;
V_23 . V_35 = V_37 ;
if ( ! V_192 && V_181 ) {
V_23 . type = V_87 ;
V_23 . V_35 = V_574 ;
}
V_31 = F_41 ( V_117 , V_64 ,
& V_23 , V_66 , - 1 , 1 ) ;
if ( V_31 > 0 && V_181 && V_66 -> V_83 [ 0 ] ) {
V_66 -> V_83 [ 0 ] -- ;
F_44 ( V_66 -> V_82 [ 0 ] , & V_23 ,
V_66 -> V_83 [ 0 ] ) ;
if ( V_23 . V_24 == V_29 &&
V_23 . type == V_79 &&
V_23 . V_35 == V_37 )
V_31 = 0 ;
}
if ( V_31 > 0 && V_181 ) {
V_181 = false ;
V_23 . V_24 = V_29 ;
V_23 . type = V_79 ;
V_23 . V_35 = V_37 ;
F_48 ( V_66 ) ;
V_31 = F_41 ( V_117 , V_64 ,
& V_23 , V_66 , - 1 , 1 ) ;
}
if ( V_31 ) {
F_176 ( V_15 ,
L_20 ,
V_31 , V_29 ) ;
if ( V_31 > 0 )
F_433 ( V_15 , V_66 -> V_82 [ 0 ] ) ;
}
if ( V_31 < 0 ) {
F_165 ( V_117 , V_31 ) ;
goto V_81;
}
V_576 = V_66 -> V_83 [ 0 ] ;
}
} else if ( F_8 ( V_31 == - V_160 ) ) {
F_433 ( V_15 , V_66 -> V_82 [ 0 ] ) ;
F_176 ( V_15 ,
L_21 ,
V_29 , V_19 , V_152 , V_574 ,
V_575 ) ;
F_165 ( V_117 , V_31 ) ;
goto V_81;
} else {
F_165 ( V_117 , V_31 ) ;
goto V_81;
}
V_68 = V_66 -> V_82 [ 0 ] ;
V_125 = F_88 ( V_68 , V_576 ) ;
#ifdef F_92
if ( V_125 < sizeof( * V_124 ) ) {
F_35 ( V_577 || V_576 != V_66 -> V_83 [ 0 ] ) ;
V_31 = F_98 ( V_117 , V_15 , V_66 , V_574 ,
0 ) ;
if ( V_31 < 0 ) {
F_165 ( V_117 , V_31 ) ;
goto V_81;
}
F_48 ( V_66 ) ;
V_66 -> V_219 = 1 ;
V_23 . V_24 = V_29 ;
V_23 . type = V_79 ;
V_23 . V_35 = V_37 ;
V_31 = F_41 ( V_117 , V_64 , & V_23 , V_66 ,
- 1 , 1 ) ;
if ( V_31 ) {
F_176 ( V_15 ,
L_20 ,
V_31 , V_29 ) ;
F_433 ( V_15 , V_66 -> V_82 [ 0 ] ) ;
}
if ( V_31 < 0 ) {
F_165 ( V_117 , V_31 ) ;
goto V_81;
}
V_576 = V_66 -> V_83 [ 0 ] ;
V_68 = V_66 -> V_82 [ 0 ] ;
V_125 = F_88 ( V_68 , V_576 ) ;
}
#endif
F_35 ( V_125 < sizeof( * V_124 ) ) ;
V_124 = F_89 ( V_68 , V_576 ,
struct V_123 ) ;
if ( V_574 < V_149 &&
V_23 . type == V_79 ) {
struct V_144 * V_145 ;
F_35 ( V_125 < sizeof( * V_124 ) + sizeof( * V_145 ) ) ;
V_145 = (struct V_144 * ) ( V_124 + 1 ) ;
F_8 ( V_574 != F_434 ( V_68 , V_145 ) ) ;
}
V_119 = F_90 ( V_68 , V_124 ) ;
if ( V_119 < V_167 ) {
F_176 ( V_15 ,
L_22 ,
V_167 , V_119 , V_29 ) ;
V_31 = - V_545 ;
F_165 ( V_117 , V_31 ) ;
goto V_81;
}
V_119 -= V_167 ;
if ( V_119 > 0 ) {
if ( V_136 )
F_141 ( V_136 , V_68 , V_124 ) ;
if ( V_172 ) {
F_35 ( ! V_577 ) ;
} else {
F_101 ( V_68 , V_124 , V_119 ) ;
F_106 ( V_68 ) ;
}
if ( V_577 ) {
V_31 = F_150 ( V_117 , V_15 , V_66 ,
V_172 , V_167 ,
V_192 , & V_168 ) ;
if ( V_31 ) {
F_165 ( V_117 , V_31 ) ;
goto V_81;
}
}
F_432 ( V_15 , - V_37 , V_574 ,
V_152 ) ;
} else {
if ( V_577 ) {
F_35 ( V_192 && V_167 !=
F_129 ( V_66 , V_172 ) ) ;
if ( V_172 ) {
F_35 ( V_66 -> V_83 [ 0 ] != V_576 ) ;
} else {
F_35 ( V_66 -> V_83 [ 0 ] != V_576 + 1 ) ;
V_66 -> V_83 [ 0 ] = V_576 ;
V_578 = 2 ;
}
}
V_168 = 1 ;
V_31 = F_435 ( V_117 , V_64 , V_66 , V_66 -> V_83 [ 0 ] ,
V_578 ) ;
if ( V_31 ) {
F_165 ( V_117 , V_31 ) ;
goto V_81;
}
F_48 ( V_66 ) ;
if ( V_192 ) {
V_31 = F_183 ( V_117 , V_15 , V_29 , V_37 ) ;
if ( V_31 ) {
F_165 ( V_117 , V_31 ) ;
goto V_81;
}
}
V_31 = F_436 ( V_117 , V_15 , V_29 , V_37 ) ;
if ( V_31 ) {
F_165 ( V_117 , V_31 ) ;
goto V_81;
}
V_31 = F_408 ( V_117 , V_15 , V_29 , V_37 , 0 ) ;
if ( V_31 ) {
F_165 ( V_117 , V_31 ) ;
goto V_81;
}
}
F_48 ( V_66 ) ;
V_81:
F_56 ( V_66 ) ;
return V_31 ;
}
static T_1 int F_437 ( struct V_116 * V_117 ,
T_2 V_29 )
{
struct V_120 * V_112 ;
struct V_121 * V_122 ;
int V_31 = 0 ;
V_122 = & V_117 -> V_134 -> V_122 ;
F_12 ( & V_122 -> V_50 ) ;
V_112 = F_95 ( V_122 , V_29 ) ;
if ( ! V_112 )
goto V_579;
F_12 ( & V_112 -> V_50 ) ;
if ( ! F_186 ( & V_112 -> V_231 ) )
goto V_81;
if ( V_112 -> V_136 ) {
if ( ! V_112 -> V_236 )
goto V_81;
F_195 ( V_112 -> V_136 ) ;
V_112 -> V_136 = NULL ;
}
if ( ! F_96 ( & V_112 -> V_86 ) )
goto V_81;
V_112 -> V_135 . V_240 = 0 ;
F_197 ( & V_112 -> V_242 , & V_122 -> V_243 ) ;
F_199 ( & V_122 -> V_244 ) ;
V_122 -> V_241 -- ;
if ( V_112 -> V_238 == 0 )
V_122 -> V_239 -- ;
V_112 -> V_238 = 0 ;
F_14 ( & V_112 -> V_50 ) ;
F_14 ( & V_122 -> V_50 ) ;
F_35 ( V_112 -> V_136 ) ;
if ( V_112 -> V_236 )
V_31 = 1 ;
F_50 ( & V_112 -> V_86 ) ;
F_97 ( & V_112 -> V_135 ) ;
return V_31 ;
V_81:
F_14 ( & V_112 -> V_50 ) ;
V_579:
F_14 ( & V_122 -> V_50 ) ;
return 0 ;
}
void F_438 ( struct V_116 * V_117 ,
struct V_63 * V_12 ,
struct V_67 * V_291 ,
T_2 V_19 , int V_168 )
{
struct V_14 * V_36 = V_12 -> V_36 ;
int V_580 = 1 ;
int V_31 ;
if ( V_12 -> V_287 . V_24 != V_216 ) {
V_31 = F_162 ( V_36 , V_117 ,
V_291 -> V_34 , V_291 -> V_47 ,
V_19 ,
V_12 -> V_287 . V_24 ,
F_246 ( V_291 ) ,
V_225 , NULL ) ;
F_35 ( V_31 ) ;
}
if ( ! V_168 )
return;
if ( F_439 ( V_291 ) == V_117 -> V_274 ) {
struct V_1 * V_2 ;
if ( V_12 -> V_287 . V_24 != V_216 ) {
V_31 = F_437 ( V_117 , V_291 -> V_34 ) ;
if ( ! V_31 )
goto V_81;
}
V_2 = F_79 ( V_36 , V_291 -> V_34 ) ;
if ( F_440 ( V_291 , V_581 ) ) {
F_413 ( V_36 , V_2 , V_291 -> V_34 ,
V_291 -> V_47 , 1 ) ;
F_6 ( V_2 ) ;
goto V_81;
}
F_8 ( F_229 ( V_582 , & V_291 -> V_583 ) ) ;
F_34 ( V_2 , V_291 -> V_34 , V_291 -> V_47 ) ;
F_422 ( V_2 , V_291 -> V_47 , 0 ) ;
F_6 ( V_2 ) ;
F_441 ( V_36 , V_291 -> V_34 , V_291 -> V_47 ) ;
V_580 = 0 ;
}
V_81:
if ( V_580 )
F_432 ( V_36 , V_291 -> V_47 , F_246 ( V_291 ) ,
V_12 -> V_287 . V_24 ) ;
F_442 ( V_584 , & V_291 -> V_583 ) ;
}
int V_298 ( struct V_116 * V_117 ,
struct V_14 * V_36 ,
T_2 V_29 , T_2 V_37 , T_2 V_19 , T_2 V_152 ,
T_2 V_140 , T_2 V_35 )
{
int V_31 ;
if ( F_244 ( V_36 ) )
return 0 ;
F_432 ( V_36 , V_37 , V_140 , V_152 ) ;
if ( V_152 == V_216 ) {
F_8 ( V_140 >= V_149 ) ;
F_179 ( V_36 , V_29 , V_37 , 1 ) ;
V_31 = 0 ;
} else if ( V_140 < V_149 ) {
V_31 = F_162 ( V_36 , V_117 , V_29 ,
V_37 ,
V_19 , V_152 , ( int ) V_140 ,
V_225 , NULL ) ;
} else {
V_31 = F_163 ( V_36 , V_117 , V_29 ,
V_37 ,
V_19 , V_152 , V_140 ,
V_35 , 0 ,
V_225 ) ;
}
return V_31 ;
}
static T_1 void
F_443 ( struct V_1 * V_2 ,
T_2 V_37 )
{
struct V_48 * V_51 ;
V_51 = F_26 ( V_2 ) ;
if ( ! V_51 )
return;
F_282 ( V_51 -> V_89 , F_1 ( V_2 ) ||
( V_2 -> V_13 -> V_585 >= V_37 ) ) ;
F_28 ( V_51 ) ;
}
static T_1 int
F_444 ( struct V_1 * V_2 )
{
struct V_48 * V_51 ;
int V_31 = 0 ;
V_51 = F_26 ( V_2 ) ;
if ( ! V_51 )
return ( V_2 -> V_3 == V_5 ) ? - V_183 : 0 ;
F_282 ( V_51 -> V_89 , F_1 ( V_2 ) ) ;
if ( V_2 -> V_3 == V_5 )
V_31 = - V_183 ;
F_28 ( V_51 ) ;
return V_31 ;
}
int F_445 ( T_2 V_7 )
{
if ( V_7 & V_348 )
return V_586 ;
else if ( V_7 & V_347 )
return V_587 ;
else if ( V_7 & V_346 )
return V_588 ;
else if ( V_7 & V_396 )
return V_589 ;
else if ( V_7 & V_395 )
return V_590 ;
else if ( V_7 & V_394 )
return V_591 ;
return V_592 ;
}
int F_446 ( struct V_1 * V_2 )
{
return F_445 ( V_2 -> V_7 ) ;
}
static const char * F_447 ( enum V_593 type )
{
if ( type >= V_353 )
return NULL ;
return V_594 [ type ] ;
}
static inline void
F_448 ( struct V_1 * V_2 ,
int V_552 )
{
if ( V_552 )
F_53 ( & V_2 -> V_595 ) ;
}
static inline void
F_449 ( struct V_1 * V_2 ,
int V_552 )
{
F_4 ( V_2 ) ;
if ( V_552 )
F_53 ( & V_2 -> V_595 ) ;
}
static struct V_1 *
F_450 ( struct V_1 * V_16 ,
struct V_553 * V_561 ,
int V_552 )
{
struct V_1 * V_596 = NULL ;
F_12 ( & V_561 -> V_597 ) ;
while ( 1 ) {
V_596 = V_561 -> V_16 ;
if ( ! V_596 )
return NULL ;
if ( V_596 == V_16 )
return V_596 ;
F_4 ( V_596 ) ;
if ( ! V_552 )
return V_596 ;
if ( F_343 ( & V_596 -> V_595 ) )
return V_596 ;
F_14 ( & V_561 -> V_597 ) ;
F_451 ( & V_596 -> V_595 , V_598 ) ;
F_12 ( & V_561 -> V_597 ) ;
if ( V_596 == V_561 -> V_16 )
return V_596 ;
F_49 ( & V_596 -> V_595 ) ;
F_6 ( V_596 ) ;
}
}
static inline void
F_452 ( struct V_1 * V_2 ,
int V_552 )
{
if ( V_552 )
F_49 ( & V_2 -> V_595 ) ;
F_6 ( V_2 ) ;
}
static T_1 int F_453 ( struct V_14 * V_36 ,
T_2 V_551 , T_2 V_37 , T_2 V_599 ,
T_2 V_600 , struct V_69 * V_222 ,
T_2 V_7 , int V_552 )
{
int V_31 = 0 ;
struct V_63 * V_12 = V_36 -> V_64 ;
struct V_553 * V_601 = NULL ;
struct V_1 * V_16 = NULL ;
T_2 V_544 = 0 ;
T_2 V_359 = 0 ;
T_2 V_554 = 0 ;
struct V_110 * V_94 ;
int V_602 = 0 ;
int V_603 = F_445 ( V_7 ) ;
bool V_604 = false ;
bool V_605 = false ;
bool V_606 = true ;
bool V_607 = false ;
bool V_608 = false ;
bool V_609 = false ;
F_8 ( V_37 < V_36 -> V_55 ) ;
V_222 -> type = V_79 ;
V_222 -> V_24 = 0 ;
V_222 -> V_35 = 0 ;
F_454 ( V_36 , V_37 , V_599 , V_7 ) ;
V_94 = F_80 ( V_36 , V_7 ) ;
if ( ! V_94 ) {
F_176 ( V_36 , L_23 , V_7 ) ;
return - V_318 ;
}
if ( F_369 ( V_94 -> V_359 ) ) {
F_12 ( & V_94 -> V_50 ) ;
if ( V_94 -> V_359 &&
V_37 > V_94 -> V_359 ) {
V_222 -> V_35 = V_94 -> V_359 ;
F_14 ( & V_94 -> V_50 ) ;
return - V_318 ;
} else if ( V_94 -> V_359 ) {
V_606 = false ;
}
F_14 ( & V_94 -> V_50 ) ;
}
V_601 = F_424 ( V_36 , V_94 , & V_554 ) ;
if ( V_601 ) {
F_12 ( & V_601 -> V_50 ) ;
if ( V_601 -> V_16 )
V_600 = V_601 -> V_610 ;
if ( V_601 -> V_563 ) {
V_600 = V_601 -> V_610 ;
V_606 = false ;
}
F_14 ( & V_601 -> V_50 ) ;
}
V_544 = F_455 ( V_544 , V_28 ( V_36 , 0 ) ) ;
V_544 = F_455 ( V_544 , V_600 ) ;
if ( V_544 == V_600 ) {
V_16 = F_79 ( V_36 , V_544 ) ;
if ( V_16 && F_3 ( V_16 , V_7 ) &&
V_16 -> V_3 != V_102 ) {
F_53 ( & V_94 -> V_355 ) ;
if ( F_186 ( & V_16 -> V_98 ) ||
V_16 -> V_311 ) {
F_6 ( V_16 ) ;
F_49 ( & V_94 -> V_355 ) ;
} else {
V_603 = F_446 ( V_16 ) ;
F_448 ( V_16 , V_552 ) ;
goto V_611;
}
} else if ( V_16 ) {
F_6 ( V_16 ) ;
}
}
V_612:
V_607 = false ;
if ( V_603 == 0 || V_603 == F_445 ( V_7 ) )
V_609 = true ;
F_53 ( & V_94 -> V_355 ) ;
F_237 (block_group, &space_info->block_groups[index],
list) {
T_2 V_35 ;
int V_3 ;
F_449 ( V_16 , V_552 ) ;
V_544 = V_16 -> V_23 . V_24 ;
if ( ! F_3 ( V_16 , V_7 ) ) {
T_2 V_613 = V_346 |
V_347 |
V_395 |
V_394 |
V_348 ;
if ( ( V_7 & V_613 ) && ! ( V_16 -> V_7 & V_613 ) )
goto V_602;
}
V_611:
V_3 = F_1 ( V_16 ) ;
if ( F_369 ( ! V_3 ) ) {
V_607 = true ;
V_31 = F_62 ( V_16 , 0 ) ;
F_35 ( V_31 < 0 ) ;
V_31 = 0 ;
}
if ( F_369 ( V_16 -> V_3 == V_5 ) )
goto V_602;
if ( F_369 ( V_16 -> V_311 ) )
goto V_602;
if ( V_601 && V_606 ) {
struct V_1 * V_614 ;
unsigned long V_615 ;
V_614 = F_450 ( V_16 ,
V_601 ,
V_552 ) ;
if ( ! V_614 )
goto V_616;
if ( V_614 != V_16 &&
( V_614 -> V_311 ||
! F_3 ( V_614 , V_7 ) ) )
goto V_617;
V_35 = F_456 ( V_614 ,
V_601 ,
V_37 ,
V_614 -> V_23 . V_24 ,
& V_359 ) ;
if ( V_35 ) {
F_14 ( & V_601 -> V_597 ) ;
F_457 ( V_36 ,
V_614 ,
V_544 , V_37 ) ;
if ( V_614 != V_16 ) {
F_452 ( V_16 ,
V_552 ) ;
V_16 = V_614 ;
}
goto V_618;
}
F_8 ( V_601 -> V_16 != V_614 ) ;
V_617:
if ( V_602 >= V_619 &&
V_614 != V_16 ) {
F_14 ( & V_601 -> V_597 ) ;
F_452 ( V_614 ,
V_552 ) ;
goto V_620;
}
F_458 ( NULL , V_601 ) ;
if ( V_614 != V_16 )
F_452 ( V_614 ,
V_552 ) ;
V_616:
if ( V_602 >= V_619 ) {
F_14 ( & V_601 -> V_597 ) ;
goto V_620;
}
V_615 = F_38 (unsigned long,
empty_cluster + empty_size,
block_group->full_stripe_len) ;
V_31 = F_459 ( V_36 , V_16 ,
V_601 , V_544 ,
V_37 ,
V_615 ) ;
if ( V_31 == 0 ) {
V_35 = F_456 ( V_16 ,
V_601 ,
V_37 ,
V_544 ,
& V_359 ) ;
if ( V_35 ) {
F_14 ( & V_601 -> V_597 ) ;
F_457 ( V_36 ,
V_16 , V_544 ,
V_37 ) ;
goto V_618;
}
} else if ( ! V_3 && V_602 > V_621
&& ! V_604 ) {
F_14 ( & V_601 -> V_597 ) ;
V_604 = true ;
F_443 ( V_16 ,
V_37 + V_554 + V_599 ) ;
goto V_611;
}
F_458 ( NULL , V_601 ) ;
F_14 ( & V_601 -> V_597 ) ;
goto V_602;
}
V_620:
if ( F_369 ( V_601 ) ) {
F_12 ( & V_601 -> V_50 ) ;
V_601 -> V_563 = 1 ;
F_14 ( & V_601 -> V_50 ) ;
}
if ( V_3 ) {
struct V_622 * V_49 =
V_16 -> V_13 ;
F_12 ( & V_49 -> V_623 ) ;
if ( V_49 -> V_585 <
V_37 + V_554 + V_599 ) {
if ( V_49 -> V_585 > V_359 )
V_359 = V_49 -> V_585 ;
F_14 ( & V_49 -> V_623 ) ;
goto V_602;
}
F_14 ( & V_49 -> V_623 ) ;
}
V_35 = F_460 ( V_16 , V_544 ,
V_37 , V_599 ,
& V_359 ) ;
if ( ! V_35 && ! V_605 && ! V_3 &&
V_602 > V_621 ) {
F_443 ( V_16 ,
V_37 + V_599 ) ;
V_605 = true ;
goto V_611;
} else if ( ! V_35 ) {
goto V_602;
}
V_618:
V_544 = F_152 ( V_35 , V_36 -> V_624 ) ;
if ( V_544 + V_37 >
V_16 -> V_23 . V_24 + V_16 -> V_23 . V_35 ) {
F_34 ( V_16 , V_35 , V_37 ) ;
goto V_602;
}
if ( V_35 < V_544 )
F_34 ( V_16 , V_35 ,
V_544 - V_35 ) ;
F_35 ( V_35 > V_544 ) ;
V_31 = F_421 ( V_16 , V_551 ,
V_37 , V_552 ) ;
if ( V_31 == - V_186 ) {
F_34 ( V_16 , V_35 , V_37 ) ;
goto V_602;
}
F_417 ( V_16 ) ;
V_222 -> V_24 = V_544 ;
V_222 -> V_35 = V_37 ;
F_461 ( V_36 , V_16 ,
V_544 , V_37 ) ;
F_452 ( V_16 , V_552 ) ;
break;
V_602:
V_604 = false ;
V_605 = false ;
F_35 ( V_603 != F_446 ( V_16 ) ) ;
F_452 ( V_16 , V_552 ) ;
}
F_49 ( & V_94 -> V_355 ) ;
if ( ( V_602 == V_621 ) && V_607
&& ! V_608 )
V_608 = true ;
if ( ! V_222 -> V_24 && V_602 >= V_625 && V_607 )
goto V_612;
if ( ! V_222 -> V_24 && ++ V_603 < V_353 )
goto V_612;
if ( ! V_222 -> V_24 && V_602 < V_619 ) {
V_603 = 0 ;
if ( V_602 == V_621 ) {
if ( V_608 || ! V_609 )
V_602 = V_625 ;
else
V_602 = V_626 ;
} else {
V_602 ++ ;
}
if ( V_602 == V_626 ) {
struct V_116 * V_117 ;
int V_627 = 0 ;
V_117 = V_406 -> V_407 ;
if ( V_117 )
V_627 = 1 ;
else
V_117 = F_219 ( V_12 ) ;
if ( F_220 ( V_117 ) ) {
V_31 = F_221 ( V_117 ) ;
goto V_81;
}
V_31 = F_313 ( V_117 , V_36 , V_7 ,
V_410 ) ;
if ( V_31 == - V_318 )
V_602 = V_619 ;
if ( V_31 < 0 && V_31 != - V_318 )
F_165 ( V_117 , V_31 ) ;
else
V_31 = 0 ;
if ( ! V_627 )
F_223 ( V_117 ) ;
if ( V_31 )
goto V_81;
}
if ( V_602 == V_619 ) {
if ( V_599 == 0 &&
V_554 == 0 ) {
V_31 = - V_318 ;
goto V_81;
}
V_599 = 0 ;
V_554 = 0 ;
}
goto V_612;
} else if ( ! V_222 -> V_24 ) {
V_31 = - V_318 ;
} else if ( V_222 -> V_24 ) {
if ( ! V_606 && V_601 ) {
F_12 ( & V_601 -> V_50 ) ;
V_601 -> V_610 = V_222 -> V_24 ;
F_14 ( & V_601 -> V_50 ) ;
}
V_31 = 0 ;
}
V_81:
if ( V_31 == - V_318 ) {
F_12 ( & V_94 -> V_50 ) ;
V_94 -> V_359 = V_359 ;
F_14 ( & V_94 -> V_50 ) ;
V_222 -> V_35 = V_359 ;
}
return V_31 ;
}
static void F_336 ( struct V_14 * V_36 ,
struct V_110 * V_15 , T_2 V_211 ,
int V_628 )
{
struct V_1 * V_2 ;
int V_603 = 0 ;
F_12 ( & V_15 -> V_50 ) ;
F_335 ( V_36 , L_24 ,
V_15 -> V_7 ,
V_15 -> V_343 - F_310 ( V_15 , true ) ,
V_15 -> V_115 ? L_25 : L_26 ) ;
F_335 ( V_36 ,
L_27 ,
V_15 -> V_343 , V_15 -> V_93 , V_15 -> V_356 ,
V_15 -> V_357 , V_15 -> V_358 ,
V_15 -> V_344 ) ;
F_14 ( & V_15 -> V_50 ) ;
if ( ! V_628 )
return;
F_53 ( & V_15 -> V_355 ) ;
V_163:
F_237 (cache, &info->block_groups[index], list) {
F_12 ( & V_2 -> V_50 ) ;
F_335 ( V_36 ,
L_28 ,
V_2 -> V_23 . V_24 , V_2 -> V_23 . V_35 ,
F_61 ( & V_2 -> V_95 ) , V_2 -> V_9 ,
V_2 -> V_10 , V_2 -> V_311 ? L_29 : L_25 ) ;
F_462 ( V_2 , V_211 ) ;
F_14 ( & V_2 -> V_50 ) ;
}
if ( ++ V_603 < V_353 )
goto V_163;
F_49 ( & V_15 -> V_355 ) ;
}
int F_463 ( struct V_63 * V_12 , T_2 V_551 ,
T_2 V_37 , T_2 V_629 ,
T_2 V_599 , T_2 V_600 ,
struct V_69 * V_222 , int V_192 , int V_552 )
{
struct V_14 * V_36 = V_12 -> V_36 ;
bool V_630 = V_37 == V_629 ;
T_2 V_7 ;
int V_31 ;
V_7 = F_309 ( V_12 , V_192 ) ;
V_163:
F_8 ( V_37 < V_36 -> V_55 ) ;
V_31 = F_453 ( V_36 , V_551 , V_37 , V_599 ,
V_600 , V_222 , V_7 , V_552 ) ;
if ( ! V_31 && ! V_192 ) {
F_418 ( V_36 , V_222 -> V_24 ) ;
} else if ( V_31 == - V_318 ) {
if ( ! V_630 && V_222 -> V_35 ) {
V_37 = F_348 ( V_37 >> 1 , V_222 -> V_35 ) ;
V_37 = F_153 ( V_37 ,
V_36 -> V_55 ) ;
V_37 = F_455 ( V_37 , V_629 ) ;
V_551 = V_37 ;
if ( V_37 == V_629 )
V_630 = true ;
goto V_163;
} else if ( F_267 ( V_36 , V_428 ) ) {
struct V_110 * V_417 ;
V_417 = F_80 ( V_36 , V_7 ) ;
F_176 ( V_36 ,
L_30 ,
V_7 , V_37 ) ;
if ( V_417 )
F_336 ( V_36 , V_417 , V_37 , 1 ) ;
}
}
return V_31 ;
}
static int F_464 ( struct V_14 * V_36 ,
T_2 V_34 , T_2 V_47 ,
int V_580 , int V_552 )
{
struct V_1 * V_2 ;
int V_31 = 0 ;
V_2 = F_79 ( V_36 , V_34 ) ;
if ( ! V_2 ) {
F_176 ( V_36 , L_31 ,
V_34 ) ;
return - V_318 ;
}
if ( V_580 )
F_413 ( V_36 , V_2 , V_34 , V_47 , 1 ) ;
else {
if ( F_267 ( V_36 , V_569 ) )
V_31 = F_156 ( V_36 , V_34 , V_47 , NULL ) ;
F_34 ( V_2 , V_34 , V_47 ) ;
F_422 ( V_2 , V_47 , V_552 ) ;
F_441 ( V_36 , V_34 , V_47 ) ;
}
F_6 ( V_2 ) ;
return V_31 ;
}
int F_465 ( struct V_14 * V_36 ,
T_2 V_34 , T_2 V_47 , int V_552 )
{
return F_464 ( V_36 , V_34 , V_47 , 0 , V_552 ) ;
}
int F_466 ( struct V_14 * V_36 ,
T_2 V_34 , T_2 V_47 )
{
return F_464 ( V_36 , V_34 , V_47 , 1 , 0 ) ;
}
static int F_169 ( struct V_116 * V_117 ,
struct V_14 * V_36 ,
T_2 V_19 , T_2 V_152 ,
T_2 V_7 , T_2 V_140 , T_2 V_35 ,
struct V_69 * V_222 , int V_139 )
{
int V_31 ;
struct V_123 * V_631 ;
struct V_171 * V_172 ;
struct V_65 * V_66 ;
struct V_67 * V_68 ;
int type ;
T_3 V_59 ;
if ( V_19 > 0 )
type = V_161 ;
else
type = V_162 ;
V_59 = sizeof( * V_631 ) + F_136 ( type ) ;
V_66 = F_37 () ;
if ( ! V_66 )
return - V_74 ;
V_66 -> V_219 = 1 ;
V_31 = F_117 ( V_117 , V_36 -> V_64 , V_66 ,
V_222 , V_59 ) ;
if ( V_31 ) {
F_56 ( V_66 ) ;
return V_31 ;
}
V_68 = V_66 -> V_82 [ 0 ] ;
V_631 = F_89 ( V_68 , V_66 -> V_83 [ 0 ] ,
struct V_123 ) ;
F_101 ( V_68 , V_631 , V_139 ) ;
F_102 ( V_68 , V_631 , V_117 -> V_274 ) ;
F_103 ( V_68 , V_631 ,
V_7 | V_151 ) ;
V_172 = (struct V_171 * ) ( V_631 + 1 ) ;
F_143 ( V_68 , V_172 , type ) ;
if ( V_19 > 0 ) {
struct V_166 * V_157 ;
V_157 = (struct V_166 * ) ( V_172 + 1 ) ;
F_144 ( V_68 , V_172 , V_19 ) ;
F_118 ( V_68 , V_157 , V_139 ) ;
} else {
struct V_156 * V_157 ;
V_157 = (struct V_156 * ) ( & V_172 -> V_35 ) ;
F_120 ( V_68 , V_157 , V_152 ) ;
F_121 ( V_68 , V_157 , V_140 ) ;
F_122 ( V_68 , V_157 , V_35 ) ;
F_123 ( V_68 , V_157 , V_139 ) ;
}
F_106 ( V_66 -> V_82 [ 0 ] ) ;
F_56 ( V_66 ) ;
V_31 = F_467 ( V_117 , V_36 , V_222 -> V_24 ,
V_222 -> V_35 ) ;
if ( V_31 )
return V_31 ;
V_31 = F_408 ( V_117 , V_36 , V_222 -> V_24 , V_222 -> V_35 , 1 ) ;
if ( V_31 ) {
F_176 ( V_36 , L_32 ,
V_222 -> V_24 , V_222 -> V_35 ) ;
F_94 () ;
}
F_468 ( V_36 , V_222 -> V_24 , V_222 -> V_35 ) ;
return V_31 ;
}
static int F_177 ( struct V_116 * V_117 ,
struct V_14 * V_36 ,
T_2 V_19 , T_2 V_152 ,
T_2 V_7 , struct V_632 * V_23 ,
int V_175 , struct V_69 * V_222 )
{
int V_31 ;
struct V_123 * V_631 ;
struct V_144 * V_633 ;
struct V_171 * V_172 ;
struct V_65 * V_66 ;
struct V_67 * V_68 ;
T_3 V_59 = sizeof( * V_631 ) + sizeof( * V_172 ) ;
T_2 V_37 = V_222 -> V_35 ;
bool V_181 = F_87 ( V_36 , V_128 ) ;
if ( ! V_181 )
V_59 += sizeof( * V_633 ) ;
V_66 = F_37 () ;
if ( ! V_66 ) {
F_466 ( V_36 , V_222 -> V_24 ,
V_36 -> V_54 ) ;
return - V_74 ;
}
V_66 -> V_219 = 1 ;
V_31 = F_117 ( V_117 , V_36 -> V_64 , V_66 ,
V_222 , V_59 ) ;
if ( V_31 ) {
F_56 ( V_66 ) ;
F_466 ( V_36 , V_222 -> V_24 ,
V_36 -> V_54 ) ;
return V_31 ;
}
V_68 = V_66 -> V_82 [ 0 ] ;
V_631 = F_89 ( V_68 , V_66 -> V_83 [ 0 ] ,
struct V_123 ) ;
F_101 ( V_68 , V_631 , 1 ) ;
F_102 ( V_68 , V_631 , V_117 -> V_274 ) ;
F_103 ( V_68 , V_631 ,
V_7 | V_150 ) ;
if ( V_181 ) {
V_172 = (struct V_171 * ) ( V_631 + 1 ) ;
V_37 = V_36 -> V_54 ;
} else {
V_633 = (struct V_144 * ) ( V_631 + 1 ) ;
F_171 ( V_68 , V_633 , V_23 ) ;
F_105 ( V_68 , V_633 , V_175 ) ;
V_172 = (struct V_171 * ) ( V_633 + 1 ) ;
}
if ( V_19 > 0 ) {
F_35 ( ! ( V_7 & V_133 ) ) ;
F_143 ( V_68 , V_172 ,
V_173 ) ;
F_144 ( V_68 , V_172 , V_19 ) ;
} else {
F_143 ( V_68 , V_172 ,
V_174 ) ;
F_144 ( V_68 , V_172 , V_152 ) ;
}
F_106 ( V_68 ) ;
F_56 ( V_66 ) ;
V_31 = F_467 ( V_117 , V_36 , V_222 -> V_24 ,
V_37 ) ;
if ( V_31 )
return V_31 ;
V_31 = F_408 ( V_117 , V_36 , V_222 -> V_24 ,
V_36 -> V_54 , 1 ) ;
if ( V_31 ) {
F_176 ( V_36 , L_32 ,
V_222 -> V_24 , V_222 -> V_35 ) ;
F_94 () ;
}
F_468 ( V_36 , V_222 -> V_24 ,
V_36 -> V_54 ) ;
return V_31 ;
}
int F_469 ( struct V_116 * V_117 ,
T_2 V_152 , T_2 V_140 ,
T_2 V_35 , T_2 V_551 ,
struct V_69 * V_222 )
{
struct V_14 * V_36 = V_117 -> V_36 ;
int V_31 ;
F_35 ( V_152 == V_216 ) ;
V_31 = F_163 ( V_36 , V_117 , V_222 -> V_24 ,
V_222 -> V_35 , 0 ,
V_152 , V_140 , V_35 ,
V_551 , V_245 ) ;
return V_31 ;
}
int F_470 ( struct V_116 * V_117 ,
struct V_14 * V_36 ,
T_2 V_152 , T_2 V_140 , T_2 V_35 ,
struct V_69 * V_222 )
{
int V_31 ;
struct V_1 * V_16 ;
struct V_110 * V_94 ;
if ( ! F_87 ( V_36 , V_549 ) ) {
V_31 = F_415 ( V_36 , V_222 -> V_24 ,
V_222 -> V_35 ) ;
if ( V_31 )
return V_31 ;
}
V_16 = F_79 ( V_36 , V_222 -> V_24 ) ;
if ( ! V_16 )
return - V_545 ;
V_94 = V_16 -> V_94 ;
F_12 ( & V_94 -> V_50 ) ;
F_12 ( & V_16 -> V_50 ) ;
V_94 -> V_357 += V_222 -> V_35 ;
V_16 -> V_10 += V_222 -> V_35 ;
F_14 ( & V_16 -> V_50 ) ;
F_14 ( & V_94 -> V_50 ) ;
V_31 = F_169 ( V_117 , V_36 , 0 , V_152 ,
0 , V_140 , V_35 , V_222 , 1 ) ;
F_6 ( V_16 ) ;
return V_31 ;
}
static struct V_67 *
F_471 ( struct V_116 * V_117 , struct V_63 * V_12 ,
T_2 V_29 , int V_175 )
{
struct V_14 * V_36 = V_12 -> V_36 ;
struct V_67 * V_291 ;
V_291 = F_472 ( V_36 , V_29 ) ;
if ( F_220 ( V_291 ) )
return V_291 ;
F_473 ( V_291 , V_117 -> V_274 ) ;
F_474 ( V_12 -> V_287 . V_24 , V_291 , V_175 ) ;
F_475 ( V_291 ) ;
F_476 ( V_36 , V_291 ) ;
F_442 ( V_634 , & V_291 -> V_583 ) ;
F_477 ( V_291 ) ;
F_478 ( V_291 ) ;
if ( V_12 -> V_287 . V_24 == V_216 ) {
V_291 -> V_635 = V_12 -> V_636 % 2 ;
if ( V_291 -> V_635 == 0 )
F_412 ( & V_12 -> V_637 , V_291 -> V_34 ,
V_291 -> V_34 + V_291 -> V_47 - 1 , V_97 ) ;
else
F_479 ( & V_12 -> V_637 , V_291 -> V_34 ,
V_291 -> V_34 + V_291 -> V_47 - 1 ) ;
} else {
V_291 -> V_635 = - 1 ;
F_412 ( & V_117 -> V_134 -> V_638 , V_291 -> V_34 ,
V_291 -> V_34 + V_291 -> V_47 - 1 , V_97 ) ;
}
V_117 -> V_325 = true ;
return V_291 ;
}
static struct V_262 *
F_480 ( struct V_116 * V_117 ,
struct V_63 * V_12 , T_3 V_639 )
{
struct V_14 * V_36 = V_12 -> V_36 ;
struct V_262 * V_452 ;
struct V_262 * V_263 = & V_36 -> V_266 ;
int V_31 ;
bool V_640 = false ;
V_452 = F_371 ( V_117 , V_12 ) ;
if ( F_369 ( V_452 -> V_59 == 0 ) )
goto V_641;
V_163:
V_31 = F_370 ( V_452 , V_639 ) ;
if ( ! V_31 )
return V_452 ;
if ( V_452 -> V_642 )
return F_481 ( V_31 ) ;
if ( V_452 -> type == V_643 && ! V_640 ) {
V_640 = true ;
F_384 ( V_36 ) ;
goto V_163;
}
if ( F_267 ( V_36 , V_428 ) ) {
static F_482 ( V_644 ,
V_645 * 10 ,
1 ) ;
if ( F_483 ( & V_644 ) )
F_484 ( 1 , V_646
L_33 , V_31 ) ;
}
V_641:
V_31 = F_368 ( V_12 , V_452 , V_639 ,
V_430 ) ;
if ( ! V_31 )
return V_452 ;
if ( V_452 -> type != V_643 &&
V_452 -> V_94 == V_263 -> V_94 ) {
V_31 = F_370 ( V_263 , V_639 ) ;
if ( ! V_31 )
return V_263 ;
}
return F_481 ( V_31 ) ;
}
static void F_485 ( struct V_14 * V_36 ,
struct V_262 * V_452 , T_3 V_639 )
{
F_372 ( V_452 , V_639 , 0 ) ;
F_375 ( V_36 , V_452 , NULL , 0 ) ;
}
struct V_67 * F_486 ( struct V_116 * V_117 ,
struct V_63 * V_12 ,
T_2 V_19 , T_2 V_152 ,
const struct V_632 * V_23 ,
int V_175 , T_2 V_647 ,
T_2 V_599 )
{
struct V_14 * V_36 = V_12 -> V_36 ;
struct V_69 V_222 ;
struct V_262 * V_452 ;
struct V_67 * V_291 ;
struct V_188 * V_136 ;
T_2 V_7 = 0 ;
int V_31 ;
T_3 V_639 = V_36 -> V_54 ;
bool V_181 = F_87 ( V_36 , V_128 ) ;
#ifdef F_487
if ( F_244 ( V_36 ) ) {
V_291 = F_471 ( V_117 , V_12 , V_12 -> V_648 ,
V_175 ) ;
if ( ! F_220 ( V_291 ) )
V_12 -> V_648 += V_639 ;
return V_291 ;
}
#endif
V_452 = F_480 ( V_117 , V_12 , V_639 ) ;
if ( F_220 ( V_452 ) )
return F_488 ( V_452 ) ;
V_31 = F_463 ( V_12 , V_639 , V_639 , V_639 ,
V_599 , V_647 , & V_222 , 0 , 0 ) ;
if ( V_31 )
goto V_649;
V_291 = F_471 ( V_117 , V_12 , V_222 . V_24 , V_175 ) ;
if ( F_220 ( V_291 ) ) {
V_31 = F_221 ( V_291 ) ;
goto V_650;
}
if ( V_152 == V_651 ) {
if ( V_19 == 0 )
V_19 = V_222 . V_24 ;
V_7 |= V_133 ;
} else
F_35 ( V_19 > 0 ) ;
if ( V_152 != V_216 ) {
V_136 = F_234 () ;
if ( ! V_136 ) {
V_31 = - V_74 ;
goto V_652;
}
if ( V_23 )
memcpy ( & V_136 -> V_23 , V_23 , sizeof( V_136 -> V_23 ) ) ;
else
memset ( & V_136 -> V_23 , 0 , sizeof( V_136 -> V_23 ) ) ;
V_136 -> V_138 = V_7 ;
V_136 -> V_226 = V_181 ? false : true ;
V_136 -> V_137 = true ;
V_136 -> V_192 = false ;
V_136 -> V_175 = V_175 ;
V_31 = F_162 ( V_36 , V_117 ,
V_222 . V_24 , V_222 . V_35 ,
V_19 , V_152 , V_175 ,
V_245 ,
V_136 ) ;
if ( V_31 )
goto V_653;
}
return V_291 ;
V_653:
F_195 ( V_136 ) ;
V_652:
F_489 ( V_291 ) ;
V_650:
F_465 ( V_36 , V_222 . V_24 , V_222 . V_35 , 0 ) ;
V_649:
F_485 ( V_36 , V_452 , V_639 ) ;
return F_481 ( V_31 ) ;
}
static T_1 void F_490 ( struct V_116 * V_117 ,
struct V_63 * V_12 ,
struct V_654 * V_655 ,
struct V_65 * V_66 )
{
struct V_14 * V_36 = V_12 -> V_36 ;
T_2 V_29 ;
T_2 V_315 ;
T_2 V_119 ;
T_2 V_7 ;
T_3 V_72 ;
struct V_69 V_23 ;
struct V_67 * V_547 ;
int V_31 ;
int V_656 ;
int V_657 = 0 ;
if ( V_66 -> V_83 [ V_655 -> V_175 ] < V_655 -> V_658 ) {
V_655 -> V_659 = V_655 -> V_659 * 2 / 3 ;
V_655 -> V_659 = F_455 ( V_655 -> V_659 , 2 ) ;
} else {
V_655 -> V_659 = V_655 -> V_659 * 3 / 2 ;
V_655 -> V_659 = F_25 ( int , V_655 -> V_659 ,
F_491 ( V_36 ) ) ;
}
V_547 = V_66 -> V_82 [ V_655 -> V_175 ] ;
V_72 = F_42 ( V_547 ) ;
for ( V_656 = V_66 -> V_83 [ V_655 -> V_175 ] ; V_656 < V_72 ; V_656 ++ ) {
if ( V_657 >= V_655 -> V_659 )
break;
F_51 () ;
V_29 = F_251 ( V_547 , V_656 ) ;
V_315 = F_492 ( V_547 , V_656 ) ;
if ( V_656 == V_66 -> V_83 [ V_655 -> V_175 ] )
goto V_77;
if ( V_655 -> V_660 == V_661 &&
V_315 <= V_12 -> V_287 . V_35 )
continue;
V_31 = F_86 ( V_117 , V_36 , V_29 ,
V_655 -> V_175 - 1 , 1 , & V_119 ,
& V_7 ) ;
if ( V_31 < 0 )
continue;
F_35 ( V_119 == 0 ) ;
if ( V_655 -> V_660 == V_662 ) {
if ( V_119 == 1 )
goto V_77;
if ( V_655 -> V_175 == 1 &&
( V_7 & V_133 ) )
continue;
if ( ! V_655 -> V_663 ||
V_315 <= V_12 -> V_287 . V_35 )
continue;
F_134 ( V_547 , & V_23 , V_656 ) ;
V_31 = F_493 ( & V_23 ,
& V_655 -> V_664 ) ;
if ( V_31 < 0 )
continue;
} else {
if ( V_655 -> V_175 == 1 &&
( V_7 & V_133 ) )
continue;
}
V_77:
F_494 ( V_36 , V_29 ) ;
V_657 ++ ;
}
V_655 -> V_658 = V_656 ;
}
static T_1 int F_495 ( struct V_116 * V_117 ,
struct V_63 * V_12 ,
struct V_65 * V_66 ,
struct V_654 * V_655 , int V_665 )
{
struct V_14 * V_36 = V_12 -> V_36 ;
int V_175 = V_655 -> V_175 ;
struct V_67 * V_547 = V_66 -> V_82 [ V_175 ] ;
T_2 V_666 = V_133 ;
int V_31 ;
if ( V_655 -> V_660 == V_661 &&
F_245 ( V_547 ) != V_12 -> V_287 . V_24 )
return 1 ;
if ( V_665 &&
( ( V_655 -> V_660 == V_662 && V_655 -> V_119 [ V_175 ] != 1 ) ||
( V_655 -> V_660 == V_661 && ! ( V_655 -> V_7 [ V_175 ] & V_666 ) ) ) ) {
F_35 ( ! V_66 -> V_667 [ V_175 ] ) ;
V_31 = F_86 ( V_117 , V_36 ,
V_547 -> V_34 , V_175 , 1 ,
& V_655 -> V_119 [ V_175 ] ,
& V_655 -> V_7 [ V_175 ] ) ;
F_35 ( V_31 == - V_74 ) ;
if ( V_31 )
return V_31 ;
F_35 ( V_655 -> V_119 [ V_175 ] == 0 ) ;
}
if ( V_655 -> V_660 == V_662 ) {
if ( V_655 -> V_119 [ V_175 ] > 1 )
return 1 ;
if ( V_66 -> V_667 [ V_175 ] && ! V_655 -> V_182 ) {
F_496 ( V_547 , V_66 -> V_667 [ V_175 ] ) ;
V_66 -> V_667 [ V_175 ] = 0 ;
}
return 0 ;
}
if ( ! ( V_655 -> V_7 [ V_175 ] & V_666 ) ) {
F_35 ( ! V_66 -> V_667 [ V_175 ] ) ;
V_31 = F_252 ( V_117 , V_12 , V_547 , 1 ) ;
F_35 ( V_31 ) ;
V_31 = F_253 ( V_117 , V_12 , V_547 , 0 ) ;
F_35 ( V_31 ) ;
V_31 = F_233 ( V_117 , V_36 , V_547 -> V_34 ,
V_547 -> V_47 , V_666 ,
F_246 ( V_547 ) , 0 ) ;
F_35 ( V_31 ) ;
V_655 -> V_7 [ V_175 ] |= V_666 ;
}
if ( V_66 -> V_667 [ V_175 ] && V_175 > 0 ) {
F_496 ( V_547 , V_66 -> V_667 [ V_175 ] ) ;
V_66 -> V_667 [ V_175 ] = 0 ;
}
return 0 ;
}
static T_1 int F_497 ( struct V_116 * V_117 ,
struct V_63 * V_12 ,
struct V_65 * V_66 ,
struct V_654 * V_655 , int * V_665 )
{
struct V_14 * V_36 = V_12 -> V_36 ;
T_2 V_29 ;
T_2 V_315 ;
T_2 V_19 ;
T_3 V_639 ;
struct V_69 V_23 ;
struct V_67 * V_80 ;
int V_175 = V_655 -> V_175 ;
int V_77 = 0 ;
int V_31 = 0 ;
bool V_668 = false ;
V_315 = F_492 ( V_66 -> V_82 [ V_175 ] ,
V_66 -> V_83 [ V_175 ] ) ;
if ( V_655 -> V_660 == V_661 &&
V_315 <= V_12 -> V_287 . V_35 ) {
* V_665 = 1 ;
return 1 ;
}
V_29 = F_251 ( V_66 -> V_82 [ V_175 ] , V_66 -> V_83 [ V_175 ] ) ;
V_639 = V_36 -> V_54 ;
V_80 = F_498 ( V_36 , V_29 ) ;
if ( ! V_80 ) {
V_80 = F_472 ( V_36 , V_29 ) ;
if ( F_220 ( V_80 ) )
return F_221 ( V_80 ) ;
F_474 ( V_12 -> V_287 . V_24 , V_80 ,
V_175 - 1 ) ;
V_77 = 1 ;
}
F_475 ( V_80 ) ;
F_477 ( V_80 ) ;
V_31 = F_86 ( V_117 , V_36 , V_29 , V_175 - 1 , 1 ,
& V_655 -> V_119 [ V_175 - 1 ] ,
& V_655 -> V_7 [ V_175 - 1 ] ) ;
if ( V_31 < 0 )
goto V_669;
if ( F_369 ( V_655 -> V_119 [ V_175 - 1 ] == 0 ) ) {
F_176 ( V_36 , L_34 ) ;
V_31 = - V_183 ;
goto V_669;
}
* V_665 = 0 ;
if ( V_655 -> V_660 == V_662 ) {
if ( V_655 -> V_119 [ V_175 - 1 ] > 1 ) {
V_668 = true ;
if ( V_175 == 1 &&
( V_655 -> V_7 [ 0 ] & V_133 ) )
goto V_670;
if ( ! V_655 -> V_663 ||
V_315 <= V_12 -> V_287 . V_35 )
goto V_670;
F_134 ( V_66 -> V_82 [ V_175 ] , & V_23 ,
V_66 -> V_83 [ V_175 ] ) ;
V_31 = F_493 ( & V_23 , & V_655 -> V_664 ) ;
if ( V_31 < 0 )
goto V_670;
V_655 -> V_660 = V_661 ;
V_655 -> V_671 = V_175 - 1 ;
}
} else {
if ( V_175 == 1 &&
( V_655 -> V_7 [ 0 ] & V_133 ) )
goto V_670;
}
if ( ! F_499 ( V_80 , V_315 , 0 ) ) {
F_500 ( V_80 ) ;
F_489 ( V_80 ) ;
V_80 = NULL ;
* V_665 = 1 ;
}
if ( ! V_80 ) {
if ( V_77 && V_175 == 1 )
F_490 ( V_117 , V_12 , V_655 , V_66 ) ;
V_80 = F_501 ( V_36 , V_29 , V_315 ) ;
if ( F_220 ( V_80 ) ) {
return F_221 ( V_80 ) ;
} else if ( ! F_502 ( V_80 ) ) {
F_489 ( V_80 ) ;
return - V_183 ;
}
F_475 ( V_80 ) ;
F_477 ( V_80 ) ;
}
V_175 -- ;
ASSERT ( V_175 == F_246 ( V_80 ) ) ;
if ( V_175 != F_246 ( V_80 ) ) {
F_176 ( V_12 -> V_36 , L_35 ) ;
V_31 = - V_183 ;
goto V_669;
}
V_66 -> V_82 [ V_175 ] = V_80 ;
V_66 -> V_83 [ V_175 ] = 0 ;
V_66 -> V_667 [ V_175 ] = V_672 ;
V_655 -> V_175 = V_175 ;
if ( V_655 -> V_175 == 1 )
V_655 -> V_658 = 0 ;
return 0 ;
V_670:
V_655 -> V_119 [ V_175 - 1 ] = 0 ;
V_655 -> V_7 [ V_175 - 1 ] = 0 ;
if ( V_655 -> V_660 == V_662 ) {
if ( V_655 -> V_7 [ V_175 ] & V_133 ) {
V_19 = V_66 -> V_82 [ V_175 ] -> V_34 ;
} else {
ASSERT ( V_12 -> V_287 . V_24 ==
F_245 ( V_66 -> V_82 [ V_175 ] ) ) ;
if ( V_12 -> V_287 . V_24 !=
F_245 ( V_66 -> V_82 [ V_175 ] ) ) {
F_176 ( V_12 -> V_36 ,
L_36 ) ;
V_31 = - V_183 ;
goto V_669;
}
V_19 = 0 ;
}
if ( V_668 ) {
V_31 = F_503 ( V_117 , V_12 , V_80 ,
V_315 , V_175 - 1 ) ;
if ( V_31 ) {
F_504 ( V_36 ,
L_37 ,
V_31 ) ;
}
}
V_31 = V_298 ( V_117 , V_36 , V_29 , V_639 ,
V_19 , V_12 -> V_287 . V_24 ,
V_175 - 1 , 0 ) ;
if ( V_31 )
goto V_669;
}
* V_665 = 1 ;
V_31 = 1 ;
V_669:
F_500 ( V_80 ) ;
F_489 ( V_80 ) ;
return V_31 ;
}
static T_1 int F_505 ( struct V_116 * V_117 ,
struct V_63 * V_12 ,
struct V_65 * V_66 ,
struct V_654 * V_655 )
{
struct V_14 * V_36 = V_12 -> V_36 ;
int V_31 ;
int V_175 = V_655 -> V_175 ;
struct V_67 * V_547 = V_66 -> V_82 [ V_175 ] ;
T_2 V_19 = 0 ;
if ( V_655 -> V_660 == V_661 ) {
F_35 ( V_655 -> V_671 < V_175 ) ;
if ( V_175 < V_655 -> V_671 )
goto V_81;
V_31 = F_45 ( V_66 , V_175 + 1 , & V_655 -> V_664 ) ;
if ( V_31 > 0 )
V_655 -> V_663 = 0 ;
V_655 -> V_660 = V_662 ;
V_655 -> V_671 = - 1 ;
V_66 -> V_83 [ V_175 ] = 0 ;
if ( ! V_66 -> V_667 [ V_175 ] ) {
F_35 ( V_175 == 0 ) ;
F_475 ( V_547 ) ;
F_477 ( V_547 ) ;
V_66 -> V_667 [ V_175 ] = V_672 ;
V_31 = F_86 ( V_117 , V_36 ,
V_547 -> V_34 , V_175 , 1 ,
& V_655 -> V_119 [ V_175 ] ,
& V_655 -> V_7 [ V_175 ] ) ;
if ( V_31 < 0 ) {
F_496 ( V_547 , V_66 -> V_667 [ V_175 ] ) ;
V_66 -> V_667 [ V_175 ] = 0 ;
return V_31 ;
}
F_35 ( V_655 -> V_119 [ V_175 ] == 0 ) ;
if ( V_655 -> V_119 [ V_175 ] == 1 ) {
F_496 ( V_547 , V_66 -> V_667 [ V_175 ] ) ;
V_66 -> V_667 [ V_175 ] = 0 ;
return 1 ;
}
}
}
F_35 ( V_655 -> V_119 [ V_175 ] > 1 && ! V_66 -> V_667 [ V_175 ] ) ;
if ( V_655 -> V_119 [ V_175 ] == 1 ) {
if ( V_175 == 0 ) {
if ( V_655 -> V_7 [ V_175 ] & V_133 )
V_31 = F_253 ( V_117 , V_12 , V_547 , 1 ) ;
else
V_31 = F_253 ( V_117 , V_12 , V_547 , 0 ) ;
F_35 ( V_31 ) ;
V_31 = F_506 ( V_117 , V_36 , V_547 ) ;
if ( V_31 ) {
F_504 ( V_36 ,
L_38 ,
V_31 ) ;
}
}
if ( ! V_66 -> V_667 [ V_175 ] &&
F_439 ( V_547 ) == V_117 -> V_274 ) {
F_475 ( V_547 ) ;
F_477 ( V_547 ) ;
V_66 -> V_667 [ V_175 ] = V_672 ;
}
F_476 ( V_36 , V_547 ) ;
}
if ( V_547 == V_12 -> V_135 ) {
if ( V_655 -> V_7 [ V_175 ] & V_133 )
V_19 = V_547 -> V_34 ;
else
F_35 ( V_12 -> V_287 . V_24 !=
F_245 ( V_547 ) ) ;
} else {
if ( V_655 -> V_7 [ V_175 + 1 ] & V_133 )
V_19 = V_66 -> V_82 [ V_175 + 1 ] -> V_34 ;
else
F_35 ( V_12 -> V_287 . V_24 !=
F_245 ( V_66 -> V_82 [ V_175 + 1 ] ) ) ;
}
F_438 ( V_117 , V_12 , V_547 , V_19 , V_655 -> V_119 [ V_175 ] == 1 ) ;
V_81:
V_655 -> V_119 [ V_175 ] = 0 ;
V_655 -> V_7 [ V_175 ] = 0 ;
return 0 ;
}
static T_1 int F_507 ( struct V_116 * V_117 ,
struct V_63 * V_12 ,
struct V_65 * V_66 ,
struct V_654 * V_655 )
{
int V_175 = V_655 -> V_175 ;
int V_665 = 1 ;
int V_31 ;
while ( V_175 >= 0 ) {
V_31 = F_495 ( V_117 , V_12 , V_66 , V_655 , V_665 ) ;
if ( V_31 > 0 )
break;
if ( V_175 == 0 )
break;
if ( V_66 -> V_83 [ V_175 ] >=
F_42 ( V_66 -> V_82 [ V_175 ] ) )
break;
V_31 = F_497 ( V_117 , V_12 , V_66 , V_655 , & V_665 ) ;
if ( V_31 > 0 ) {
V_66 -> V_83 [ V_175 ] ++ ;
continue;
} else if ( V_31 < 0 )
return V_31 ;
V_175 = V_655 -> V_175 ;
}
return 0 ;
}
static T_1 int F_508 ( struct V_116 * V_117 ,
struct V_63 * V_12 ,
struct V_65 * V_66 ,
struct V_654 * V_655 , int V_673 )
{
int V_175 = V_655 -> V_175 ;
int V_31 ;
V_66 -> V_83 [ V_175 ] = F_42 ( V_66 -> V_82 [ V_175 ] ) ;
while ( V_175 < V_673 && V_66 -> V_82 [ V_175 ] ) {
V_655 -> V_175 = V_175 ;
if ( V_66 -> V_83 [ V_175 ] + 1 <
F_42 ( V_66 -> V_82 [ V_175 ] ) ) {
V_66 -> V_83 [ V_175 ] ++ ;
return 0 ;
} else {
V_31 = F_505 ( V_117 , V_12 , V_66 , V_655 ) ;
if ( V_31 > 0 )
return 0 ;
if ( V_66 -> V_667 [ V_175 ] ) {
F_496 ( V_66 -> V_82 [ V_175 ] ,
V_66 -> V_667 [ V_175 ] ) ;
V_66 -> V_667 [ V_175 ] = 0 ;
}
F_489 ( V_66 -> V_82 [ V_175 ] ) ;
V_66 -> V_82 [ V_175 ] = NULL ;
V_175 ++ ;
}
}
return 1 ;
}
int F_509 ( struct V_63 * V_12 ,
struct V_262 * V_452 , int V_663 ,
int V_674 )
{
struct V_14 * V_36 = V_12 -> V_36 ;
struct V_65 * V_66 ;
struct V_116 * V_117 ;
struct V_63 * V_275 = V_36 -> V_275 ;
struct V_675 * V_288 = & V_12 -> V_288 ;
struct V_654 * V_655 ;
struct V_69 V_23 ;
int V_159 = 0 ;
int V_31 ;
int V_175 ;
bool V_676 = false ;
F_196 ( V_36 , L_39 , V_12 -> V_24 ) ;
V_66 = F_37 () ;
if ( ! V_66 ) {
V_159 = - V_74 ;
goto V_81;
}
V_655 = F_64 ( sizeof( * V_655 ) , V_97 ) ;
if ( ! V_655 ) {
F_56 ( V_66 ) ;
V_159 = - V_74 ;
goto V_81;
}
V_117 = F_510 ( V_275 , 0 ) ;
if ( F_220 ( V_117 ) ) {
V_159 = F_221 ( V_117 ) ;
goto V_130;
}
if ( V_452 )
V_117 -> V_452 = V_452 ;
if ( F_511 ( & V_288 -> V_677 ) == 0 ) {
V_175 = F_246 ( V_12 -> V_135 ) ;
V_66 -> V_82 [ V_175 ] = F_512 ( V_12 ) ;
F_477 ( V_66 -> V_82 [ V_175 ] ) ;
V_66 -> V_83 [ V_175 ] = 0 ;
V_66 -> V_667 [ V_175 ] = V_672 ;
memset ( & V_655 -> V_664 , 0 ,
sizeof( V_655 -> V_664 ) ) ;
} else {
F_513 ( & V_23 , & V_288 -> V_677 ) ;
memcpy ( & V_655 -> V_664 , & V_23 ,
sizeof( V_655 -> V_664 ) ) ;
V_175 = V_288 -> V_678 ;
F_35 ( V_175 == 0 ) ;
V_66 -> V_679 = V_175 ;
V_31 = F_41 ( NULL , V_12 , & V_23 , V_66 , 0 , 0 ) ;
V_66 -> V_679 = 0 ;
if ( V_31 < 0 ) {
V_159 = V_31 ;
goto V_680;
}
F_8 ( V_31 > 0 ) ;
F_139 ( V_66 , 0 ) ;
V_175 = F_246 ( V_12 -> V_135 ) ;
while ( 1 ) {
F_475 ( V_66 -> V_82 [ V_175 ] ) ;
F_477 ( V_66 -> V_82 [ V_175 ] ) ;
V_66 -> V_667 [ V_175 ] = V_672 ;
V_31 = F_86 ( V_117 , V_36 ,
V_66 -> V_82 [ V_175 ] -> V_34 ,
V_175 , 1 , & V_655 -> V_119 [ V_175 ] ,
& V_655 -> V_7 [ V_175 ] ) ;
if ( V_31 < 0 ) {
V_159 = V_31 ;
goto V_680;
}
F_35 ( V_655 -> V_119 [ V_175 ] == 0 ) ;
if ( V_175 == V_288 -> V_678 )
break;
F_500 ( V_66 -> V_82 [ V_175 ] ) ;
V_66 -> V_667 [ V_175 ] = 0 ;
F_8 ( V_655 -> V_119 [ V_175 ] != 1 ) ;
V_175 -- ;
}
}
V_655 -> V_175 = V_175 ;
V_655 -> V_671 = - 1 ;
V_655 -> V_660 = V_662 ;
V_655 -> V_663 = V_663 ;
V_655 -> V_182 = 0 ;
V_655 -> V_674 = V_674 ;
V_655 -> V_659 = F_491 ( V_36 ) ;
while ( 1 ) {
V_31 = F_507 ( V_117 , V_12 , V_66 , V_655 ) ;
if ( V_31 < 0 ) {
V_159 = V_31 ;
break;
}
V_31 = F_508 ( V_117 , V_12 , V_66 , V_655 , V_176 ) ;
if ( V_31 < 0 ) {
V_159 = V_31 ;
break;
}
if ( V_31 > 0 ) {
F_35 ( V_655 -> V_660 != V_662 ) ;
break;
}
if ( V_655 -> V_660 == V_662 ) {
V_175 = V_655 -> V_175 ;
F_514 ( V_66 -> V_82 [ V_175 ] ,
& V_288 -> V_677 ,
V_66 -> V_83 [ V_175 ] ) ;
V_288 -> V_678 = V_175 ;
}
F_35 ( V_655 -> V_175 == 0 ) ;
if ( F_515 ( V_117 ) ||
( ! V_674 && F_516 ( V_36 ) ) ) {
V_31 = F_517 ( V_117 , V_275 ,
& V_12 -> V_287 ,
V_288 ) ;
if ( V_31 ) {
F_165 ( V_117 , V_31 ) ;
V_159 = V_31 ;
goto V_680;
}
F_518 ( V_117 ) ;
if ( ! V_674 && F_516 ( V_36 ) ) {
F_196 ( V_36 ,
L_40 ) ;
V_159 = - V_186 ;
goto V_130;
}
V_117 = F_510 ( V_275 , 0 ) ;
if ( F_220 ( V_117 ) ) {
V_159 = F_221 ( V_117 ) ;
goto V_130;
}
if ( V_452 )
V_117 -> V_452 = V_452 ;
}
}
F_48 ( V_66 ) ;
if ( V_159 )
goto V_680;
V_31 = F_519 ( V_117 , V_275 , & V_12 -> V_287 ) ;
if ( V_31 ) {
F_165 ( V_117 , V_31 ) ;
goto V_680;
}
if ( V_12 -> V_287 . V_24 != V_651 ) {
V_31 = F_520 ( V_275 , & V_12 -> V_287 , V_66 ,
NULL , NULL ) ;
if ( V_31 < 0 ) {
F_165 ( V_117 , V_31 ) ;
V_159 = V_31 ;
goto V_680;
} else if ( V_31 > 0 ) {
F_521 ( V_117 , V_275 ,
V_12 -> V_287 . V_24 ) ;
}
}
if ( F_229 ( V_681 , & V_12 -> V_297 ) ) {
F_522 ( V_117 , V_12 ) ;
} else {
F_489 ( V_12 -> V_135 ) ;
F_489 ( V_12 -> V_682 ) ;
F_523 ( V_12 ) ;
}
V_676 = true ;
V_680:
F_518 ( V_117 ) ;
V_130:
F_10 ( V_655 ) ;
F_56 ( V_66 ) ;
V_81:
if ( ! V_674 && V_676 == false )
F_524 ( V_12 ) ;
if ( V_159 && V_159 != - V_186 )
F_525 ( V_36 , V_159 , NULL ) ;
return V_159 ;
}
int F_526 ( struct V_116 * V_117 ,
struct V_63 * V_12 ,
struct V_67 * V_135 ,
struct V_67 * V_19 )
{
struct V_14 * V_36 = V_12 -> V_36 ;
struct V_65 * V_66 ;
struct V_654 * V_655 ;
int V_175 ;
int V_683 ;
int V_31 = 0 ;
int V_684 ;
F_35 ( V_12 -> V_287 . V_24 != V_651 ) ;
V_66 = F_37 () ;
if ( ! V_66 )
return - V_74 ;
V_655 = F_64 ( sizeof( * V_655 ) , V_97 ) ;
if ( ! V_655 ) {
F_56 ( V_66 ) ;
return - V_74 ;
}
F_527 ( V_19 ) ;
V_683 = F_246 ( V_19 ) ;
F_528 ( V_19 ) ;
V_66 -> V_82 [ V_683 ] = V_19 ;
V_66 -> V_83 [ V_683 ] = F_42 ( V_19 ) ;
F_527 ( V_135 ) ;
V_175 = F_246 ( V_135 ) ;
V_66 -> V_82 [ V_175 ] = V_135 ;
V_66 -> V_83 [ V_175 ] = 0 ;
V_66 -> V_667 [ V_175 ] = V_672 ;
V_655 -> V_119 [ V_683 ] = 1 ;
V_655 -> V_7 [ V_683 ] = V_133 ;
V_655 -> V_175 = V_175 ;
V_655 -> V_671 = - 1 ;
V_655 -> V_660 = V_662 ;
V_655 -> V_663 = 0 ;
V_655 -> V_182 = 1 ;
V_655 -> V_674 = 1 ;
V_655 -> V_659 = F_491 ( V_36 ) ;
while ( 1 ) {
V_684 = F_507 ( V_117 , V_12 , V_66 , V_655 ) ;
if ( V_684 < 0 ) {
V_31 = V_684 ;
break;
}
V_684 = F_508 ( V_117 , V_12 , V_66 , V_655 , V_683 ) ;
if ( V_684 < 0 )
V_31 = V_684 ;
if ( V_684 != 0 )
break;
}
F_10 ( V_655 ) ;
F_56 ( V_66 ) ;
return V_31 ;
}
static T_2 F_529 ( struct V_14 * V_36 , T_2 V_7 )
{
T_2 V_385 ;
T_2 V_685 ;
V_685 = F_303 ( V_36 , V_7 ) ;
if ( V_685 )
return F_305 ( V_685 ) ;
V_385 = V_36 -> V_386 -> V_387 ;
V_685 = V_396 |
V_395 | V_394 |
V_347 | V_348 ;
if ( V_385 == 1 ) {
V_685 |= V_346 ;
V_685 = V_7 & ~ V_685 ;
if ( V_7 & V_396 )
return V_685 ;
if ( V_7 & ( V_347 |
V_348 ) )
return V_685 | V_346 ;
} else {
if ( V_7 & V_685 )
return V_7 ;
V_685 |= V_346 ;
V_685 = V_7 & ~ V_685 ;
if ( V_7 & V_346 )
return V_685 | V_347 ;
}
return V_7 ;
}
static int F_530 ( struct V_1 * V_2 , int V_418 )
{
struct V_110 * V_417 = V_2 -> V_94 ;
T_2 V_37 ;
T_2 V_686 ;
int V_31 = - V_318 ;
if ( ( V_417 -> V_7 &
( V_342 | V_53 ) ) &&
! V_418 )
V_686 = V_308 ;
else
V_686 = 0 ;
F_12 ( & V_417 -> V_50 ) ;
F_12 ( & V_2 -> V_50 ) ;
if ( V_2 -> V_311 ) {
V_2 -> V_311 ++ ;
V_31 = 0 ;
goto V_81;
}
V_37 = V_2 -> V_23 . V_35 - V_2 -> V_10 - V_2 -> V_9 -
V_2 -> V_45 - F_61 ( & V_2 -> V_95 ) ;
if ( F_310 ( V_417 , true ) + V_37 +
V_686 <= V_417 -> V_343 ) {
V_417 -> V_344 += V_37 ;
V_2 -> V_311 ++ ;
F_75 ( & V_2 -> V_687 , & V_417 -> V_364 ) ;
V_31 = 0 ;
}
V_81:
F_14 ( & V_2 -> V_50 ) ;
F_14 ( & V_417 -> V_50 ) ;
return V_31 ;
}
int F_531 ( struct V_14 * V_36 ,
struct V_1 * V_2 )
{
struct V_116 * V_117 ;
T_2 V_688 ;
int V_31 ;
V_163:
V_117 = F_219 ( V_36 -> V_64 ) ;
if ( F_220 ( V_117 ) )
return F_221 ( V_117 ) ;
F_52 ( & V_36 -> V_689 ) ;
if ( F_229 ( V_690 , & V_117 -> V_134 -> V_7 ) ) {
T_2 V_274 = V_117 -> V_274 ;
F_50 ( & V_36 -> V_689 ) ;
F_223 ( V_117 ) ;
V_31 = F_532 ( V_36 , V_274 ) ;
if ( V_31 )
return V_31 ;
goto V_163;
}
V_688 = F_529 ( V_36 , V_2 -> V_7 ) ;
if ( V_688 != V_2 -> V_7 ) {
V_31 = F_313 ( V_117 , V_36 , V_688 ,
V_410 ) ;
if ( V_31 == - V_318 )
V_31 = 0 ;
if ( V_31 < 0 )
goto V_81;
}
V_31 = F_530 ( V_2 , 0 ) ;
if ( ! V_31 )
goto V_81;
V_688 = F_306 ( V_36 , V_2 -> V_94 -> V_7 ) ;
V_31 = F_313 ( V_117 , V_36 , V_688 ,
V_410 ) ;
if ( V_31 < 0 )
goto V_81;
V_31 = F_530 ( V_2 , 0 ) ;
V_81:
if ( V_2 -> V_7 & V_342 ) {
V_688 = F_529 ( V_36 , V_2 -> V_7 ) ;
F_52 ( & V_36 -> V_427 ) ;
F_332 ( V_117 , V_36 , V_688 ) ;
F_50 ( & V_36 -> V_427 ) ;
}
F_50 ( & V_36 -> V_689 ) ;
F_223 ( V_117 ) ;
return V_31 ;
}
int F_533 ( struct V_116 * V_117 ,
struct V_14 * V_36 , T_2 type )
{
T_2 V_688 = F_306 ( V_36 , type ) ;
return F_313 ( V_117 , V_36 , V_688 , V_410 ) ;
}
T_2 F_534 ( struct V_110 * V_417 )
{
struct V_1 * V_16 ;
T_2 V_691 = 0 ;
int V_345 ;
if ( F_186 ( & V_417 -> V_364 ) )
return 0 ;
F_12 ( & V_417 -> V_50 ) ;
F_237 (block_group, &sinfo->ro_bgs, ro_list) {
F_12 ( & V_16 -> V_50 ) ;
if ( ! V_16 -> V_311 ) {
F_14 ( & V_16 -> V_50 ) ;
continue;
}
if ( V_16 -> V_7 & ( V_347 |
V_348 |
V_346 ) )
V_345 = 2 ;
else
V_345 = 1 ;
V_691 += ( V_16 -> V_23 . V_35 -
F_61 ( & V_16 -> V_95 ) ) *
V_345 ;
F_14 ( & V_16 -> V_50 ) ;
}
F_14 ( & V_417 -> V_50 ) ;
return V_691 ;
}
void F_535 ( struct V_1 * V_2 )
{
struct V_110 * V_417 = V_2 -> V_94 ;
T_2 V_37 ;
F_35 ( ! V_2 -> V_311 ) ;
F_12 ( & V_417 -> V_50 ) ;
F_12 ( & V_2 -> V_50 ) ;
if ( ! -- V_2 -> V_311 ) {
V_37 = V_2 -> V_23 . V_35 - V_2 -> V_10 -
V_2 -> V_9 - V_2 -> V_45 -
F_61 ( & V_2 -> V_95 ) ;
V_417 -> V_344 -= V_37 ;
F_277 ( & V_2 -> V_687 ) ;
}
F_14 ( & V_2 -> V_50 ) ;
F_14 ( & V_417 -> V_50 ) ;
}
int F_536 ( struct V_14 * V_36 , T_2 V_29 )
{
struct V_63 * V_12 = V_36 -> V_64 ;
struct V_1 * V_16 ;
struct V_110 * V_94 ;
struct V_692 * V_386 = V_36 -> V_386 ;
struct V_693 * V_694 ;
struct V_116 * V_117 ;
T_2 V_695 ;
T_2 V_696 = 1 ;
T_2 V_697 = 0 ;
T_2 V_380 ;
int V_698 ;
int V_603 ;
int V_115 = 0 ;
int V_31 = 0 ;
V_698 = F_267 ( V_36 , V_428 ) ;
V_16 = F_79 ( V_36 , V_29 ) ;
if ( ! V_16 ) {
if ( V_698 )
F_431 ( V_36 ,
L_41 ,
V_29 ) ;
return - 1 ;
}
V_695 = F_61 ( & V_16 -> V_95 ) ;
if ( ! V_695 )
goto V_81;
V_94 = V_16 -> V_94 ;
F_12 ( & V_94 -> V_50 ) ;
V_115 = V_94 -> V_115 ;
if ( ( V_94 -> V_343 != V_16 -> V_23 . V_35 ) &&
( F_310 ( V_94 , false ) + V_695 <
V_94 -> V_343 ) ) {
F_14 ( & V_94 -> V_50 ) ;
goto V_81;
}
F_14 ( & V_94 -> V_50 ) ;
V_31 = - 1 ;
V_380 = F_303 ( V_36 , V_16 -> V_7 ) ;
if ( V_380 ) {
V_603 = F_445 ( F_305 ( V_380 ) ) ;
} else {
if ( V_115 ) {
if ( V_698 )
F_431 ( V_36 ,
L_42 ,
V_16 -> V_23 . V_24 ) ;
goto V_81;
}
V_603 = F_446 ( V_16 ) ;
}
if ( V_603 == V_586 ) {
V_696 = 4 ;
V_695 >>= 1 ;
} else if ( V_603 == V_587 ) {
V_696 = 2 ;
} else if ( V_603 == V_588 ) {
V_695 <<= 1 ;
} else if ( V_603 == V_589 ) {
V_696 = V_386 -> V_387 ;
V_695 = F_210 ( V_695 , V_696 ) ;
}
V_117 = F_219 ( V_12 ) ;
if ( F_220 ( V_117 ) ) {
V_31 = F_221 ( V_117 ) ;
goto V_81;
}
F_52 ( & V_36 -> V_427 ) ;
F_237 (device, &fs_devices->alloc_list, dev_alloc_list) {
T_2 V_699 ;
if ( V_694 -> V_343 > V_694 -> V_93 + V_695 &&
! V_694 -> V_700 ) {
V_31 = F_537 ( V_117 , V_694 , V_695 ,
& V_699 , NULL ) ;
if ( ! V_31 )
V_697 ++ ;
if ( V_697 >= V_696 )
break;
V_31 = - 1 ;
}
}
if ( V_698 && V_31 == - 1 )
F_431 ( V_36 ,
L_43 ,
V_16 -> V_23 . V_24 ) ;
F_50 ( & V_36 -> V_427 ) ;
F_223 ( V_117 ) ;
V_81:
F_6 ( V_16 ) ;
return V_31 ;
}
static int F_538 ( struct V_14 * V_36 ,
struct V_65 * V_66 ,
struct V_69 * V_23 )
{
struct V_63 * V_12 = V_36 -> V_64 ;
int V_31 = 0 ;
struct V_69 V_146 ;
struct V_67 * V_68 ;
int V_656 ;
V_31 = F_41 ( NULL , V_12 , V_23 , V_66 , 0 , 0 ) ;
if ( V_31 < 0 )
goto V_81;
while ( 1 ) {
V_656 = V_66 -> V_83 [ 0 ] ;
V_68 = V_66 -> V_82 [ 0 ] ;
if ( V_656 >= F_42 ( V_68 ) ) {
V_31 = F_54 ( V_12 , V_66 ) ;
if ( V_31 == 0 )
continue;
if ( V_31 < 0 )
goto V_81;
break;
}
F_44 ( V_68 , & V_146 , V_656 ) ;
if ( V_146 . V_24 >= V_23 -> V_24 &&
V_146 . type == V_187 ) {
struct V_701 * V_702 ;
struct V_703 * V_704 ;
V_702 = & V_12 -> V_36 -> V_705 . V_706 ;
F_539 ( & V_702 -> V_50 ) ;
V_704 = F_540 ( V_702 , V_146 . V_24 ,
V_146 . V_35 ) ;
F_541 ( & V_702 -> V_50 ) ;
if ( ! V_704 ) {
F_176 ( V_36 ,
L_44 ,
V_146 . V_24 , V_146 . V_35 ) ;
V_31 = - V_160 ;
} else {
V_31 = 0 ;
}
F_542 ( V_704 ) ;
goto V_81;
}
V_66 -> V_83 [ 0 ] ++ ;
}
V_81:
return V_31 ;
}
void F_543 ( struct V_14 * V_15 )
{
struct V_1 * V_16 ;
T_2 V_71 = 0 ;
while ( 1 ) {
struct V_302 * V_302 ;
V_16 = F_78 ( V_15 , V_71 ) ;
while ( V_16 ) {
F_12 ( & V_16 -> V_50 ) ;
if ( V_16 -> V_172 )
break;
F_14 ( & V_16 -> V_50 ) ;
V_16 = F_257 ( V_15 , V_16 ) ;
}
if ( ! V_16 ) {
if ( V_71 == 0 )
break;
V_71 = 0 ;
continue;
}
V_302 = V_16 -> V_302 ;
V_16 -> V_172 = 0 ;
V_16 -> V_302 = NULL ;
F_14 ( & V_16 -> V_50 ) ;
ASSERT ( V_16 -> V_334 . V_302 == NULL ) ;
F_271 ( V_302 ) ;
V_71 = V_16 -> V_23 . V_24 + V_16 -> V_23 . V_35 ;
F_6 ( V_16 ) ;
}
}
int F_544 ( struct V_14 * V_15 )
{
struct V_1 * V_16 ;
struct V_110 * V_94 ;
struct V_48 * V_51 ;
struct V_17 * V_32 ;
F_74 ( & V_15 -> V_84 ) ;
while ( ! F_186 ( & V_15 -> V_108 ) ) {
V_51 = F_545 ( V_15 -> V_108 . V_80 ,
struct V_48 , V_98 ) ;
F_198 ( & V_51 -> V_98 ) ;
F_28 ( V_51 ) ;
}
F_76 ( & V_15 -> V_84 ) ;
F_12 ( & V_15 -> V_541 ) ;
while ( ! F_186 ( & V_15 -> V_543 ) ) {
V_16 = F_187 ( & V_15 -> V_543 ,
struct V_1 ,
V_542 ) ;
F_277 ( & V_16 -> V_542 ) ;
F_6 ( V_16 ) ;
}
F_14 ( & V_15 -> V_541 ) ;
F_12 ( & V_15 -> V_20 ) ;
while ( ( V_32 = F_204 ( & V_15 -> V_21 ) ) != NULL ) {
V_16 = F_13 ( V_32 , struct V_1 ,
V_22 ) ;
F_197 ( & V_16 -> V_22 ,
& V_15 -> V_21 ) ;
F_546 ( & V_16 -> V_22 ) ;
F_14 ( & V_15 -> V_20 ) ;
F_74 ( & V_16 -> V_94 -> V_355 ) ;
F_198 ( & V_16 -> V_98 ) ;
F_76 ( & V_16 -> V_94 -> V_355 ) ;
if ( V_16 -> V_3 == V_102 ||
V_16 -> V_3 == V_5 )
F_20 ( V_15 , V_16 ) ;
F_547 ( V_16 ) ;
ASSERT ( V_16 -> V_3 != V_106 ) ;
ASSERT ( F_186 ( & V_16 -> V_332 ) ) ;
ASSERT ( F_186 ( & V_16 -> V_333 ) ) ;
ASSERT ( F_186 ( & V_16 -> V_542 ) ) ;
ASSERT ( F_215 ( & V_16 -> V_8 ) == 1 ) ;
F_6 ( V_16 ) ;
F_12 ( & V_15 -> V_20 ) ;
}
F_14 ( & V_15 -> V_20 ) ;
F_548 () ;
F_387 ( V_15 ) ;
while ( ! F_186 ( & V_15 -> V_94 ) ) {
int V_42 ;
V_94 = F_545 ( V_15 -> V_94 . V_80 ,
struct V_110 ,
V_98 ) ;
if ( F_8 ( V_94 -> V_356 > 0 ||
V_94 -> V_357 > 0 ||
V_94 -> V_358 > 0 ) )
F_336 ( V_15 , V_94 , 0 , 0 ) ;
F_198 ( & V_94 -> V_98 ) ;
for ( V_42 = 0 ; V_42 < V_353 ; V_42 ++ ) {
struct V_707 * V_367 ;
V_367 = V_94 -> V_708 [ V_42 ] ;
V_94 -> V_708 [ V_42 ] = NULL ;
if ( V_367 ) {
F_549 ( V_367 ) ;
F_550 ( V_367 ) ;
}
}
F_549 ( & V_94 -> V_367 ) ;
F_550 ( & V_94 -> V_367 ) ;
}
return 0 ;
}
static void F_551 ( struct V_110 * V_94 ,
struct V_1 * V_2 )
{
int V_603 = F_446 ( V_2 ) ;
bool V_255 = false ;
F_74 ( & V_94 -> V_355 ) ;
if ( F_186 ( & V_94 -> V_354 [ V_603 ] ) )
V_255 = true ;
F_75 ( & V_2 -> V_98 , & V_94 -> V_354 [ V_603 ] ) ;
F_76 ( & V_94 -> V_355 ) ;
if ( V_255 ) {
struct V_709 * V_710 ;
int V_31 ;
V_710 = F_64 ( sizeof( * V_710 ) , V_97 ) ;
if ( ! V_710 )
goto V_711;
V_710 -> V_388 = V_603 ;
F_552 ( & V_710 -> V_367 , & V_712 ) ;
V_31 = F_553 ( & V_710 -> V_367 , & V_94 -> V_367 ,
L_9 , F_447 ( V_603 ) ) ;
if ( V_31 ) {
F_550 ( & V_710 -> V_367 ) ;
goto V_711;
}
V_94 -> V_708 [ V_603 ] = & V_710 -> V_367 ;
}
return;
V_711:
F_431 ( V_2 -> V_36 ,
L_45 ) ;
}
static struct V_1 *
F_554 ( struct V_14 * V_36 ,
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
V_2 -> V_23 . type = V_187 ;
V_2 -> V_55 = V_36 -> V_55 ;
V_2 -> V_36 = V_36 ;
V_2 -> V_713 = F_555 ( V_36 ,
& V_36 -> V_705 ,
V_34 ) ;
F_556 ( V_2 ) ;
F_557 ( & V_2 -> V_8 , 1 ) ;
F_295 ( & V_2 -> V_50 ) ;
F_294 ( & V_2 -> V_595 ) ;
F_65 ( & V_2 -> V_98 ) ;
F_65 ( & V_2 -> V_714 ) ;
F_65 ( & V_2 -> V_542 ) ;
F_65 ( & V_2 -> V_687 ) ;
F_65 ( & V_2 -> V_332 ) ;
F_65 ( & V_2 -> V_333 ) ;
F_558 ( V_2 ) ;
F_557 ( & V_2 -> V_715 , 0 ) ;
F_66 ( & V_2 -> V_716 ) ;
F_559 ( & V_2 -> V_11 ) ;
return V_2 ;
}
int F_560 ( struct V_14 * V_15 )
{
struct V_65 * V_66 ;
int V_31 ;
struct V_1 * V_2 ;
struct V_110 * V_94 ;
struct V_69 V_23 ;
struct V_69 V_146 ;
struct V_67 * V_68 ;
int V_717 = 0 ;
T_2 V_718 ;
T_2 V_719 ;
int V_720 ;
V_719 = F_561 ( V_15 -> V_261 ) ;
V_720 = ! ! ( V_719 & V_721 ) ;
V_23 . V_24 = 0 ;
V_23 . V_35 = 0 ;
V_23 . type = V_187 ;
V_66 = F_37 () ;
if ( ! V_66 )
return - V_74 ;
V_66 -> V_77 = V_78 ;
V_718 = F_562 ( V_15 -> V_261 ) ;
if ( F_267 ( V_15 , V_316 ) &&
F_563 ( V_15 -> V_261 ) != V_718 )
V_717 = 1 ;
if ( F_267 ( V_15 , V_722 ) )
V_717 = 1 ;
while ( 1 ) {
V_31 = F_538 ( V_15 , V_66 , & V_23 ) ;
if ( V_31 > 0 )
break;
if ( V_31 != 0 )
goto error;
V_68 = V_66 -> V_82 [ 0 ] ;
F_44 ( V_68 , & V_146 , V_66 -> V_83 [ 0 ] ) ;
V_2 = F_554 ( V_15 , V_146 . V_24 ,
V_146 . V_35 ) ;
if ( ! V_2 ) {
V_31 = - V_74 ;
goto error;
}
if ( V_717 ) {
if ( F_267 ( V_15 , V_316 ) )
V_2 -> V_309 = V_323 ;
}
F_564 ( V_68 , & V_2 -> V_95 ,
F_255 ( V_68 , V_66 -> V_83 [ 0 ] ) ,
sizeof( V_2 -> V_95 ) ) ;
V_2 -> V_7 = F_565 ( & V_2 -> V_95 ) ;
if ( ! V_720 &&
( ( V_2 -> V_7 & V_53 ) &&
( V_2 -> V_7 & V_341 ) ) ) {
F_176 ( V_15 ,
L_46 ,
V_2 -> V_23 . V_24 ) ;
V_31 = - V_545 ;
goto error;
}
V_23 . V_24 = V_146 . V_24 + V_146 . V_35 ;
F_48 ( V_66 ) ;
V_31 = F_22 ( V_15 , V_2 ) ;
if ( V_31 ) {
F_20 ( V_15 , V_2 ) ;
F_6 ( V_2 ) ;
goto error;
}
if ( V_146 . V_35 == F_61 ( & V_2 -> V_95 ) ) {
V_2 -> V_105 = ( T_2 ) - 1 ;
V_2 -> V_3 = V_4 ;
F_20 ( V_15 , V_2 ) ;
} else if ( F_61 ( & V_2 -> V_95 ) == 0 ) {
V_2 -> V_105 = ( T_2 ) - 1 ;
V_2 -> V_3 = V_4 ;
F_32 ( V_2 , V_15 ,
V_146 . V_24 ,
V_146 . V_24 +
V_146 . V_35 ) ;
F_20 ( V_15 , V_2 ) ;
}
V_31 = F_11 ( V_15 , V_2 ) ;
if ( V_31 ) {
F_547 ( V_2 ) ;
F_6 ( V_2 ) ;
goto error;
}
F_566 ( V_15 , V_2 , 0 ) ;
V_31 = F_291 ( V_15 , V_2 -> V_7 , V_146 . V_35 ,
F_61 ( & V_2 -> V_95 ) ,
V_2 -> V_45 , & V_94 ) ;
if ( V_31 ) {
F_547 ( V_2 ) ;
F_12 ( & V_15 -> V_20 ) ;
F_197 ( & V_2 -> V_22 ,
& V_15 -> V_21 ) ;
F_546 ( & V_2 -> V_22 ) ;
F_14 ( & V_15 -> V_20 ) ;
F_6 ( V_2 ) ;
goto error;
}
V_2 -> V_94 = V_94 ;
F_551 ( V_94 , V_2 ) ;
F_299 ( V_15 , V_2 -> V_7 ) ;
if ( F_567 ( V_15 , V_2 -> V_23 . V_24 ) ) {
F_530 ( V_2 , 1 ) ;
} else if ( F_61 ( & V_2 -> V_95 ) == 0 ) {
F_12 ( & V_15 -> V_541 ) ;
if ( F_186 ( & V_2 -> V_542 ) ) {
F_4 ( V_2 ) ;
F_75 ( & V_2 -> V_542 ,
& V_15 -> V_543 ) ;
}
F_14 ( & V_15 -> V_541 ) ;
}
}
F_82 (space_info, &info->space_info, list) {
if ( ! ( F_306 ( V_15 , V_94 -> V_7 ) &
( V_348 |
V_347 |
V_395 |
V_394 |
V_346 ) ) )
continue;
F_237 (cache,
&space_info->block_groups[BTRFS_RAID_RAID0],
list)
F_530 ( V_2 , 1 ) ;
F_237 (cache,
&space_info->block_groups[BTRFS_RAID_SINGLE],
list)
F_530 ( V_2 , 1 ) ;
}
F_386 ( V_15 ) ;
V_31 = 0 ;
error:
F_56 ( V_66 ) ;
return V_31 ;
}
void F_231 ( struct V_116 * V_117 ,
struct V_14 * V_36 )
{
struct V_1 * V_16 , * V_321 ;
struct V_63 * V_64 = V_36 -> V_64 ;
struct V_723 V_95 ;
struct V_69 V_23 ;
int V_31 = 0 ;
bool V_279 = V_117 -> V_279 ;
V_117 -> V_279 = false ;
F_273 (block_group, tmp, &trans->new_bgs, bg_list) {
if ( V_31 )
goto V_80;
F_12 ( & V_16 -> V_50 ) ;
memcpy ( & V_95 , & V_16 -> V_95 , sizeof( V_95 ) ) ;
memcpy ( & V_23 , & V_16 -> V_23 , sizeof( V_23 ) ) ;
F_14 ( & V_16 -> V_50 ) ;
V_31 = F_568 ( V_117 , V_64 , & V_23 , & V_95 ,
sizeof( V_95 ) ) ;
if ( V_31 )
F_165 ( V_117 , V_31 ) ;
V_31 = F_569 ( V_117 , V_36 , V_23 . V_24 ,
V_23 . V_35 ) ;
if ( V_31 )
F_165 ( V_117 , V_31 ) ;
F_570 ( V_117 , V_36 , V_16 ) ;
V_80:
F_277 ( & V_16 -> V_542 ) ;
}
V_117 -> V_279 = V_279 ;
}
int F_571 ( struct V_116 * V_117 ,
struct V_14 * V_36 , T_2 V_93 ,
T_2 type , T_2 V_724 , T_2 V_725 ,
T_2 V_59 )
{
struct V_1 * V_2 ;
int V_31 ;
F_572 ( V_36 , V_117 ) ;
V_2 = F_554 ( V_36 , V_725 , V_59 ) ;
if ( ! V_2 )
return - V_74 ;
F_411 ( & V_2 -> V_95 , V_93 ) ;
F_573 ( & V_2 -> V_95 , V_724 ) ;
F_574 ( & V_2 -> V_95 , type ) ;
V_2 -> V_7 = type ;
V_2 -> V_105 = ( T_2 ) - 1 ;
V_2 -> V_3 = V_4 ;
V_2 -> V_726 = 1 ;
V_31 = F_22 ( V_36 , V_2 ) ;
if ( V_31 ) {
F_20 ( V_36 , V_2 ) ;
F_6 ( V_2 ) ;
return V_31 ;
}
F_32 ( V_2 , V_36 , V_725 , V_725 + V_59 ) ;
F_20 ( V_36 , V_2 ) ;
#ifdef F_39
if ( F_40 ( V_2 ) ) {
T_2 V_727 = V_59 - V_93 ;
V_93 += V_727 >> 1 ;
F_30 ( V_2 ) ;
}
#endif
V_31 = F_291 ( V_36 , V_2 -> V_7 , 0 , 0 , 0 ,
& V_2 -> V_94 ) ;
if ( V_31 ) {
F_547 ( V_2 ) ;
F_6 ( V_2 ) ;
return V_31 ;
}
V_31 = F_11 ( V_36 , V_2 ) ;
if ( V_31 ) {
F_547 ( V_2 ) ;
F_6 ( V_2 ) ;
return V_31 ;
}
F_566 ( V_36 , V_2 , 1 ) ;
V_31 = F_291 ( V_36 , V_2 -> V_7 , V_59 , V_93 ,
V_2 -> V_45 , & V_2 -> V_94 ) ;
if ( V_31 ) {
F_547 ( V_2 ) ;
F_12 ( & V_36 -> V_20 ) ;
F_197 ( & V_2 -> V_22 ,
& V_36 -> V_21 ) ;
F_546 ( & V_2 -> V_22 ) ;
F_14 ( & V_36 -> V_20 ) ;
F_6 ( V_2 ) ;
return V_31 ;
}
F_384 ( V_36 ) ;
F_551 ( V_2 -> V_94 , V_2 ) ;
F_75 ( & V_2 -> V_542 , & V_117 -> V_282 ) ;
F_299 ( V_36 , type ) ;
return 0 ;
}
static void F_575 ( struct V_14 * V_36 , T_2 V_7 )
{
T_2 V_371 = F_300 ( V_7 ) &
V_372 ;
F_301 ( & V_36 -> V_373 ) ;
if ( V_7 & V_341 )
V_36 -> V_374 &= ~ V_371 ;
if ( V_7 & V_53 )
V_36 -> V_375 &= ~ V_371 ;
if ( V_7 & V_342 )
V_36 -> V_376 &= ~ V_371 ;
F_302 ( & V_36 -> V_373 ) ;
}
int F_576 ( struct V_116 * V_117 ,
struct V_14 * V_36 , T_2 V_728 ,
struct V_703 * V_704 )
{
struct V_63 * V_12 = V_36 -> V_64 ;
struct V_65 * V_66 ;
struct V_1 * V_16 ;
struct V_553 * V_561 ;
struct V_63 * V_275 = V_36 -> V_275 ;
struct V_69 V_23 ;
struct V_302 * V_302 ;
struct V_707 * V_367 = NULL ;
int V_31 ;
int V_603 ;
int V_345 ;
struct V_48 * V_51 = NULL ;
bool V_729 ;
V_16 = F_79 ( V_36 , V_728 ) ;
F_35 ( ! V_16 ) ;
F_35 ( ! V_16 -> V_311 ) ;
F_20 ( V_36 , V_16 ) ;
memcpy ( & V_23 , & V_16 -> V_23 , sizeof( V_23 ) ) ;
V_603 = F_446 ( V_16 ) ;
if ( V_16 -> V_7 & ( V_346 |
V_347 |
V_348 ) )
V_345 = 2 ;
else
V_345 = 1 ;
V_561 = & V_36 -> V_559 ;
F_12 ( & V_561 -> V_597 ) ;
F_458 ( V_16 , V_561 ) ;
F_14 ( & V_561 -> V_597 ) ;
V_561 = & V_36 -> V_557 ;
F_12 ( & V_561 -> V_597 ) ;
F_458 ( V_16 , V_561 ) ;
F_14 ( & V_561 -> V_597 ) ;
V_66 = F_37 () ;
if ( ! V_66 ) {
V_31 = - V_74 ;
goto V_81;
}
V_302 = F_260 ( V_36 , V_16 , V_66 ) ;
F_52 ( & V_117 -> V_134 -> V_331 ) ;
F_12 ( & V_117 -> V_134 -> V_330 ) ;
if ( ! F_186 ( & V_16 -> V_333 ) ) {
F_277 ( & V_16 -> V_333 ) ;
F_8 ( ! F_220 ( V_302 ) && V_302 != V_16 -> V_334 . V_302 ) ;
F_14 ( & V_117 -> V_134 -> V_330 ) ;
F_278 ( V_117 , V_16 , V_66 ) ;
F_6 ( V_16 ) ;
F_12 ( & V_117 -> V_134 -> V_330 ) ;
}
if ( ! F_186 ( & V_16 -> V_332 ) ) {
F_277 ( & V_16 -> V_332 ) ;
F_6 ( V_16 ) ;
}
F_14 ( & V_117 -> V_134 -> V_330 ) ;
F_50 ( & V_117 -> V_134 -> V_331 ) ;
if ( ! F_220 ( V_302 ) ) {
V_31 = F_577 ( V_117 , F_263 ( V_302 ) ) ;
if ( V_31 ) {
F_578 ( V_302 ) ;
goto V_81;
}
F_579 ( V_302 ) ;
F_12 ( & V_16 -> V_50 ) ;
if ( V_16 -> V_172 ) {
V_16 -> V_172 = 0 ;
V_16 -> V_302 = NULL ;
F_14 ( & V_16 -> V_50 ) ;
F_271 ( V_302 ) ;
} else {
F_14 ( & V_16 -> V_50 ) ;
}
F_578 ( V_302 ) ;
}
V_23 . V_24 = V_730 ;
V_23 . V_35 = V_16 -> V_23 . V_24 ;
V_23 . type = 0 ;
V_31 = F_41 ( V_117 , V_275 , & V_23 , V_66 , - 1 , 1 ) ;
if ( V_31 < 0 )
goto V_81;
if ( V_31 > 0 )
F_48 ( V_66 ) ;
if ( V_31 == 0 ) {
V_31 = F_127 ( V_117 , V_275 , V_66 ) ;
if ( V_31 )
goto V_81;
F_48 ( V_66 ) ;
}
F_12 ( & V_36 -> V_20 ) ;
F_197 ( & V_16 -> V_22 ,
& V_36 -> V_21 ) ;
F_546 ( & V_16 -> V_22 ) ;
if ( V_36 -> V_28 == V_16 -> V_23 . V_24 )
V_36 -> V_28 = ( T_2 ) - 1 ;
F_14 ( & V_36 -> V_20 ) ;
F_74 ( & V_16 -> V_94 -> V_355 ) ;
F_277 ( & V_16 -> V_98 ) ;
if ( F_186 ( & V_16 -> V_94 -> V_354 [ V_603 ] ) ) {
V_367 = V_16 -> V_94 -> V_708 [ V_603 ] ;
V_16 -> V_94 -> V_708 [ V_603 ] = NULL ;
F_575 ( V_36 , V_16 -> V_7 ) ;
}
F_76 ( & V_16 -> V_94 -> V_355 ) ;
if ( V_367 ) {
F_549 ( V_367 ) ;
F_550 ( V_367 ) ;
}
if ( V_16 -> V_107 )
V_51 = F_26 ( V_16 ) ;
if ( V_16 -> V_3 == V_106 )
F_444 ( V_16 ) ;
if ( V_16 -> V_107 ) {
F_74 ( & V_36 -> V_84 ) ;
if ( ! V_51 ) {
struct V_48 * V_49 ;
F_237 (ctl,
&fs_info->caching_block_groups, list)
if ( V_49 -> V_16 == V_16 ) {
V_51 = V_49 ;
F_27 ( & V_51 -> V_8 ) ;
break;
}
}
if ( V_51 )
F_277 ( & V_51 -> V_98 ) ;
F_76 ( & V_36 -> V_84 ) ;
if ( V_51 ) {
F_28 ( V_51 ) ;
F_28 ( V_51 ) ;
}
}
F_12 ( & V_117 -> V_134 -> V_330 ) ;
if ( ! F_186 ( & V_16 -> V_332 ) ) {
F_8 ( 1 ) ;
}
if ( ! F_186 ( & V_16 -> V_333 ) ) {
F_8 ( 1 ) ;
}
F_14 ( & V_117 -> V_134 -> V_330 ) ;
F_547 ( V_16 ) ;
F_12 ( & V_16 -> V_94 -> V_50 ) ;
F_277 ( & V_16 -> V_687 ) ;
if ( F_267 ( V_36 , V_428 ) ) {
F_8 ( V_16 -> V_94 -> V_343
< V_16 -> V_23 . V_35 ) ;
F_8 ( V_16 -> V_94 -> V_344
< V_16 -> V_23 . V_35 ) ;
F_8 ( V_16 -> V_94 -> V_349
< V_16 -> V_23 . V_35 * V_345 ) ;
}
V_16 -> V_94 -> V_343 -= V_16 -> V_23 . V_35 ;
V_16 -> V_94 -> V_344 -= V_16 -> V_23 . V_35 ;
V_16 -> V_94 -> V_349 -= V_16 -> V_23 . V_35 * V_345 ;
F_14 ( & V_16 -> V_94 -> V_50 ) ;
memcpy ( & V_23 , & V_16 -> V_23 , sizeof( V_23 ) ) ;
F_52 ( & V_36 -> V_427 ) ;
if ( ! F_186 ( & V_704 -> V_98 ) ) {
F_542 ( V_704 ) ;
}
F_12 ( & V_16 -> V_50 ) ;
V_16 -> V_731 = 1 ;
V_729 = ( F_215 ( & V_16 -> V_715 ) == 0 ) ;
if ( ! V_729 ) {
F_580 ( & V_704 -> V_98 , & V_36 -> V_732 ) ;
}
F_14 ( & V_16 -> V_50 ) ;
if ( V_729 ) {
struct V_701 * V_702 ;
V_702 = & V_36 -> V_705 . V_706 ;
F_581 ( & V_702 -> V_50 ) ;
F_582 ( V_702 , V_704 ) ;
F_583 ( & V_702 -> V_50 ) ;
F_542 ( V_704 ) ;
}
F_50 ( & V_36 -> V_427 ) ;
V_31 = F_584 ( V_117 , V_36 , V_16 ) ;
if ( V_31 )
goto V_81;
F_6 ( V_16 ) ;
F_6 ( V_16 ) ;
V_31 = F_41 ( V_117 , V_12 , & V_23 , V_66 , - 1 , 1 ) ;
if ( V_31 > 0 )
V_31 = - V_183 ;
if ( V_31 < 0 )
goto V_81;
V_31 = F_127 ( V_117 , V_12 , V_66 ) ;
V_81:
F_56 ( V_66 ) ;
return V_31 ;
}
struct V_116 *
F_585 ( struct V_14 * V_36 ,
const T_2 V_725 )
{
struct V_701 * V_702 = & V_36 -> V_705 . V_706 ;
struct V_703 * V_704 ;
struct V_733 * V_734 ;
unsigned int V_735 ;
F_539 ( & V_702 -> V_50 ) ;
V_704 = F_540 ( V_702 , V_725 , 1 ) ;
F_541 ( & V_702 -> V_50 ) ;
ASSERT ( V_704 && V_704 -> V_34 == V_725 ) ;
V_734 = V_704 -> V_733 ;
V_735 = 3 + V_734 -> V_210 ;
F_542 ( V_704 ) ;
return F_586 ( V_36 -> V_64 ,
V_735 , 1 ) ;
}
void F_587 ( struct V_14 * V_36 )
{
struct V_1 * V_16 ;
struct V_110 * V_94 ;
struct V_116 * V_117 ;
int V_31 = 0 ;
if ( ! F_229 ( V_736 , & V_36 -> V_7 ) )
return;
F_12 ( & V_36 -> V_541 ) ;
while ( ! F_186 ( & V_36 -> V_543 ) ) {
T_2 V_34 , V_33 ;
int V_715 ;
V_16 = F_187 ( & V_36 -> V_543 ,
struct V_1 ,
V_542 ) ;
F_277 ( & V_16 -> V_542 ) ;
V_94 = V_16 -> V_94 ;
if ( V_31 || F_339 ( V_94 ) ) {
F_6 ( V_16 ) ;
continue;
}
F_14 ( & V_36 -> V_541 ) ;
F_52 ( & V_36 -> V_737 ) ;
F_74 ( & V_94 -> V_355 ) ;
F_12 ( & V_16 -> V_50 ) ;
if ( V_16 -> V_10 ||
F_61 ( & V_16 -> V_95 ) ||
V_16 -> V_311 ||
F_588 ( & V_16 -> V_98 ) ) {
F_14 ( & V_16 -> V_50 ) ;
F_76 ( & V_94 -> V_355 ) ;
goto V_80;
}
F_14 ( & V_16 -> V_50 ) ;
V_31 = F_530 ( V_16 , 0 ) ;
F_76 ( & V_94 -> V_355 ) ;
if ( V_31 < 0 ) {
V_31 = 0 ;
goto V_80;
}
V_117 = F_585 ( V_36 ,
V_16 -> V_23 . V_24 ) ;
if ( F_220 ( V_117 ) ) {
F_535 ( V_16 ) ;
V_31 = F_221 ( V_117 ) ;
goto V_80;
}
V_34 = V_16 -> V_23 . V_24 ;
V_33 = V_34 + V_16 -> V_23 . V_35 - 1 ;
F_52 ( & V_36 -> V_568 ) ;
V_31 = F_21 ( & V_36 -> V_38 [ 0 ] , V_34 , V_33 ,
V_62 ) ;
if ( V_31 ) {
F_50 ( & V_36 -> V_568 ) ;
F_535 ( V_16 ) ;
goto V_738;
}
V_31 = F_21 ( & V_36 -> V_38 [ 1 ] , V_34 , V_33 ,
V_62 ) ;
if ( V_31 ) {
F_50 ( & V_36 -> V_568 ) ;
F_535 ( V_16 ) ;
goto V_738;
}
F_50 ( & V_36 -> V_568 ) ;
F_12 ( & V_94 -> V_50 ) ;
F_12 ( & V_16 -> V_50 ) ;
V_94 -> V_356 -= V_16 -> V_9 ;
V_94 -> V_344 += V_16 -> V_9 ;
F_426 ( & V_94 -> V_351 ,
- V_16 -> V_9 ) ;
V_16 -> V_9 = 0 ;
F_14 ( & V_16 -> V_50 ) ;
F_14 ( & V_94 -> V_50 ) ;
V_715 = F_267 ( V_36 , V_569 ) ;
if ( V_715 )
F_589 ( V_16 ) ;
V_31 = F_590 ( V_117 , V_36 ,
V_16 -> V_23 . V_24 ) ;
if ( V_31 ) {
if ( V_715 )
F_429 ( V_16 ) ;
goto V_738;
}
if ( V_715 ) {
F_12 ( & V_36 -> V_541 ) ;
F_591 ( & V_16 -> V_542 ,
& V_117 -> V_134 -> V_565 ) ;
F_14 ( & V_36 -> V_541 ) ;
F_4 ( V_16 ) ;
}
V_738:
F_223 ( V_117 ) ;
V_80:
F_50 ( & V_36 -> V_737 ) ;
F_6 ( V_16 ) ;
F_12 ( & V_36 -> V_541 ) ;
}
F_14 ( & V_36 -> V_541 ) ;
}
int F_592 ( struct V_14 * V_36 )
{
struct V_110 * V_94 ;
struct V_739 * V_740 ;
T_2 V_741 ;
T_2 V_7 ;
int V_720 = 0 ;
int V_31 ;
V_740 = V_36 -> V_261 ;
if ( ! F_593 ( V_740 ) )
return - V_545 ;
V_741 = F_561 ( V_740 ) ;
if ( V_741 & V_721 )
V_720 = 1 ;
V_7 = V_342 ;
V_31 = F_291 ( V_36 , V_7 , 0 , 0 , 0 , & V_94 ) ;
if ( V_31 )
goto V_81;
if ( V_720 ) {
V_7 = V_53 | V_341 ;
V_31 = F_291 ( V_36 , V_7 , 0 , 0 , 0 , & V_94 ) ;
} else {
V_7 = V_53 ;
V_31 = F_291 ( V_36 , V_7 , 0 , 0 , 0 , & V_94 ) ;
if ( V_31 )
goto V_81;
V_7 = V_341 ;
V_31 = F_291 ( V_36 , V_7 , 0 , 0 , 0 , & V_94 ) ;
}
V_81:
return V_31 ;
}
int F_594 ( struct V_14 * V_36 ,
T_2 V_34 , T_2 V_33 )
{
return F_425 ( V_36 , V_34 , V_33 , false ) ;
}
static int F_595 ( struct V_693 * V_694 ,
T_2 V_742 , T_2 * V_570 )
{
T_2 V_34 = 0 , V_47 = 0 ;
int V_31 ;
* V_570 = 0 ;
if ( ! V_694 -> V_743 )
return 0 ;
if ( V_694 -> V_343 <= V_694 -> V_93 )
return 0 ;
V_31 = 0 ;
while ( 1 ) {
struct V_14 * V_36 = V_694 -> V_36 ;
struct V_284 * V_117 ;
T_2 V_211 ;
V_31 = F_596 ( & V_36 -> V_427 ) ;
if ( V_31 )
return V_31 ;
F_53 ( & V_36 -> V_84 ) ;
F_12 ( & V_36 -> V_744 ) ;
V_117 = V_36 -> V_286 ;
if ( V_117 )
F_27 ( & V_117 -> V_745 ) ;
F_14 ( & V_36 -> V_744 ) ;
V_31 = F_597 ( V_117 , V_694 , V_742 , V_34 ,
& V_34 , & V_47 ) ;
if ( V_117 )
F_598 ( V_117 ) ;
if ( V_31 ) {
F_49 ( & V_36 -> V_84 ) ;
F_50 ( & V_36 -> V_427 ) ;
if ( V_31 == - V_318 )
V_31 = 0 ;
break;
}
V_31 = F_151 ( V_694 -> V_194 , V_34 , V_47 , & V_211 ) ;
F_49 ( & V_36 -> V_84 ) ;
F_50 ( & V_36 -> V_427 ) ;
if ( V_31 )
break;
V_34 += V_47 ;
* V_570 += V_211 ;
if ( F_599 ( V_406 ) ) {
V_31 = - V_746 ;
break;
}
F_51 () ;
}
return V_31 ;
}
int F_600 ( struct V_14 * V_36 , struct V_747 * V_748 )
{
struct V_1 * V_2 = NULL ;
struct V_693 * V_694 ;
struct V_111 * V_749 ;
T_2 V_750 ;
T_2 V_34 ;
T_2 V_33 ;
T_2 V_570 = 0 ;
T_2 V_343 = F_328 ( V_36 -> V_261 ) ;
int V_31 = 0 ;
if ( V_748 -> V_47 == V_343 )
V_2 = F_78 ( V_36 , V_748 -> V_34 ) ;
else
V_2 = F_79 ( V_36 , V_748 -> V_34 ) ;
while ( V_2 ) {
if ( V_2 -> V_23 . V_24 >= ( V_748 -> V_34 + V_748 -> V_47 ) ) {
F_6 ( V_2 ) ;
break;
}
V_34 = F_455 ( V_748 -> V_34 , V_2 -> V_23 . V_24 ) ;
V_33 = F_348 ( V_748 -> V_34 + V_748 -> V_47 ,
V_2 -> V_23 . V_24 + V_2 -> V_23 . V_35 ) ;
if ( V_33 - V_34 >= V_748 -> V_742 ) {
if ( ! F_1 ( V_2 ) ) {
V_31 = F_62 ( V_2 , 0 ) ;
if ( V_31 ) {
F_6 ( V_2 ) ;
break;
}
V_31 = F_444 ( V_2 ) ;
if ( V_31 ) {
F_6 ( V_2 ) ;
break;
}
}
V_31 = F_601 ( V_2 ,
& V_750 ,
V_34 ,
V_33 ,
V_748 -> V_742 ) ;
V_570 += V_750 ;
if ( V_31 ) {
F_6 ( V_2 ) ;
break;
}
}
V_2 = F_257 ( V_36 , V_2 ) ;
}
F_52 ( & V_36 -> V_386 -> V_751 ) ;
V_749 = & V_36 -> V_386 -> V_752 ;
F_237 (device, devices, dev_alloc_list) {
V_31 = F_595 ( V_694 , V_748 -> V_742 ,
& V_750 ) ;
if ( V_31 )
break;
V_570 += V_750 ;
}
F_50 ( & V_36 -> V_386 -> V_751 ) ;
V_748 -> V_47 = V_570 ;
return V_31 ;
}
void F_602 ( struct V_63 * V_12 )
{
F_603 ( & V_12 -> V_753 -> V_754 ) ;
F_2 () ;
if ( F_604 ( & V_12 -> V_753 -> V_89 ) )
F_55 ( & V_12 -> V_753 -> V_89 ) ;
}
int F_605 ( struct V_63 * V_12 )
{
if ( F_215 ( & V_12 -> V_755 ) )
return 0 ;
F_606 ( & V_12 -> V_753 -> V_754 ) ;
F_2 () ;
if ( F_215 ( & V_12 -> V_755 ) ) {
F_602 ( V_12 ) ;
return 0 ;
}
return 1 ;
}
static int F_607 ( T_7 * V_340 )
{
F_71 () ;
return 0 ;
}
void F_608 ( struct V_63 * V_12 )
{
while ( true ) {
int V_31 ;
V_31 = F_605 ( V_12 ) ;
if ( V_31 )
break;
F_289 ( & V_12 -> V_755 ,
F_607 ,
V_101 ) ;
}
}
