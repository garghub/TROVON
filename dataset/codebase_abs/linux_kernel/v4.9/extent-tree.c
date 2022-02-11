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
V_32 , V_31 , V_39 ) ;
F_18 ( & V_35 -> V_37 -> V_38 [ 1 ] ,
V_32 , V_31 , V_39 ) ;
return 0 ;
}
static void F_19 ( struct V_34 * V_35 ,
struct V_1 * V_2 )
{
T_2 V_32 , V_31 ;
V_32 = V_2 -> V_21 . V_22 ;
V_31 = V_32 + V_2 -> V_21 . V_33 - 1 ;
F_20 ( & V_35 -> V_37 -> V_38 [ 0 ] ,
V_32 , V_31 , V_39 ) ;
F_20 ( & V_35 -> V_37 -> V_38 [ 1 ] ,
V_32 , V_31 , V_39 ) ;
}
static int F_21 ( struct V_34 * V_35 ,
struct V_1 * V_2 )
{
T_2 V_27 ;
T_2 * V_40 ;
int V_41 ;
int V_42 , V_43 , V_29 ;
if ( V_2 -> V_21 . V_22 < V_44 ) {
V_41 = V_44 - V_2 -> V_21 . V_22 ;
V_2 -> V_45 += V_41 ;
V_29 = F_17 ( V_35 , V_2 -> V_21 . V_22 ,
V_41 ) ;
if ( V_29 )
return V_29 ;
}
for ( V_42 = 0 ; V_42 < V_46 ; V_42 ++ ) {
V_27 = F_22 ( V_42 ) ;
V_29 = F_23 ( V_35 -> V_37 , V_2 -> V_21 . V_22 ,
V_27 , 0 , & V_40 , & V_43 , & V_41 ) ;
if ( V_29 )
return V_29 ;
while ( V_43 -- ) {
T_2 V_32 , V_47 ;
if ( V_40 [ V_43 ] > V_2 -> V_21 . V_22 +
V_2 -> V_21 . V_33 )
continue;
if ( V_40 [ V_43 ] + V_41 <= V_2 -> V_21 . V_22 )
continue;
V_32 = V_40 [ V_43 ] ;
if ( V_32 < V_2 -> V_21 . V_22 ) {
V_32 = V_2 -> V_21 . V_22 ;
V_47 = ( V_40 [ V_43 ] + V_41 ) - V_32 ;
} else {
V_47 = F_24 ( T_2 , V_41 ,
V_2 -> V_21 . V_22 +
V_2 -> V_21 . V_33 - V_32 ) ;
}
V_2 -> V_45 += V_47 ;
V_29 = F_17 ( V_35 , V_32 , V_47 ) ;
if ( V_29 ) {
F_9 ( V_40 ) ;
return V_29 ;
}
}
F_9 ( V_40 ) ;
}
return 0 ;
}
static struct V_48 *
F_25 ( struct V_1 * V_2 )
{
struct V_48 * V_49 ;
F_11 ( & V_2 -> V_50 ) ;
if ( ! V_2 -> V_51 ) {
F_13 ( & V_2 -> V_50 ) ;
return NULL ;
}
V_49 = V_2 -> V_51 ;
F_5 ( & V_49 -> V_8 ) ;
F_13 ( & V_2 -> V_50 ) ;
return V_49 ;
}
static void F_26 ( struct V_48 * V_49 )
{
if ( F_7 ( & V_49 -> V_8 ) )
F_9 ( V_49 ) ;
}
static void F_27 ( struct V_34 * V_35 ,
struct V_1 * V_14 )
{
T_2 V_32 = V_14 -> V_21 . V_22 ;
T_2 V_47 = V_14 -> V_21 . V_33 ;
T_2 V_52 = V_14 -> V_7 & V_53 ?
V_35 -> V_54 : V_35 -> V_55 ;
T_2 V_56 = V_52 << 1 ;
while ( V_47 > V_52 ) {
F_28 ( V_14 , V_32 , V_52 ) ;
V_32 += V_56 ;
if ( V_47 < V_56 )
V_47 = 0 ;
else
V_47 -= V_56 ;
}
}
T_2 F_29 ( struct V_1 * V_14 ,
struct V_12 * V_13 , T_2 V_32 , T_2 V_31 )
{
T_2 V_57 , V_58 , V_59 , V_60 = 0 ;
int V_29 ;
while ( V_32 < V_31 ) {
V_29 = F_30 ( V_13 -> V_61 , V_32 ,
& V_57 , & V_58 ,
V_62 | V_39 ,
NULL ) ;
if ( V_29 )
break;
if ( V_57 <= V_32 ) {
V_32 = V_58 + 1 ;
} else if ( V_57 > V_32 && V_57 < V_31 ) {
V_59 = V_57 - V_32 ;
V_60 += V_59 ;
V_29 = F_31 ( V_14 , V_32 ,
V_59 ) ;
F_32 ( V_29 ) ;
V_32 = V_58 + 1 ;
} else {
break;
}
}
if ( V_32 < V_31 ) {
V_59 = V_31 - V_32 ;
V_60 += V_59 ;
V_29 = F_31 ( V_14 , V_32 , V_59 ) ;
F_32 ( V_29 ) ;
}
return V_60 ;
}
static int F_33 ( struct V_48 * V_51 )
{
struct V_1 * V_14 ;
struct V_12 * V_37 ;
struct V_34 * V_63 ;
struct V_64 * V_65 ;
struct V_66 * V_67 ;
struct V_68 V_21 ;
T_2 V_69 = 0 ;
T_2 V_70 = 0 ;
T_3 V_71 ;
int V_29 ;
bool V_72 = true ;
V_14 = V_51 -> V_14 ;
V_37 = V_14 -> V_37 ;
V_63 = V_37 -> V_63 ;
V_65 = F_34 () ;
if ( ! V_65 )
return - V_73 ;
V_70 = F_35 ( T_2 , V_14 -> V_21 . V_22 , V_44 ) ;
#ifdef F_36
if ( F_37 ( V_63 , V_14 ) )
V_72 = false ;
#endif
V_65 -> V_74 = 1 ;
V_65 -> V_75 = 1 ;
V_65 -> V_76 = V_77 ;
V_21 . V_22 = V_70 ;
V_21 . V_33 = 0 ;
V_21 . type = V_78 ;
V_79:
V_29 = F_38 ( NULL , V_63 , & V_21 , V_65 , 0 , 0 ) ;
if ( V_29 < 0 )
goto V_80;
V_67 = V_65 -> V_81 [ 0 ] ;
V_71 = F_39 ( V_67 ) ;
while ( 1 ) {
if ( F_40 ( V_37 ) > 1 ) {
V_70 = ( T_2 ) - 1 ;
break;
}
if ( V_65 -> V_82 [ 0 ] < V_71 ) {
F_41 ( V_67 , & V_21 , V_65 -> V_82 [ 0 ] ) ;
} else {
V_29 = F_42 ( V_65 , 0 , & V_21 ) ;
if ( V_29 )
break;
if ( F_43 () ||
F_44 ( & V_37 -> V_83 ) ) {
if ( V_72 )
V_51 -> V_84 = V_70 ;
F_45 ( V_65 ) ;
F_46 ( & V_37 -> V_83 ) ;
F_47 ( & V_51 -> V_85 ) ;
F_48 () ;
F_49 ( & V_51 -> V_85 ) ;
F_50 ( & V_37 -> V_83 ) ;
goto V_79;
}
V_29 = F_51 ( V_63 , V_65 ) ;
if ( V_29 < 0 )
goto V_80;
if ( V_29 )
break;
V_67 = V_65 -> V_81 [ 0 ] ;
V_71 = F_39 ( V_67 ) ;
continue;
}
if ( V_21 . V_22 < V_70 ) {
V_21 . V_22 = V_70 ;
V_21 . V_33 = 0 ;
V_21 . type = V_78 ;
if ( V_72 )
V_51 -> V_84 = V_70 ;
F_45 ( V_65 ) ;
goto V_79;
}
if ( V_21 . V_22 < V_14 -> V_21 . V_22 ) {
V_65 -> V_82 [ 0 ] ++ ;
continue;
}
if ( V_21 . V_22 >= V_14 -> V_21 . V_22 +
V_14 -> V_21 . V_33 )
break;
if ( V_21 . type == V_78 ||
V_21 . type == V_86 ) {
V_69 += F_29 ( V_14 ,
V_37 , V_70 ,
V_21 . V_22 ) ;
if ( V_21 . type == V_86 )
V_70 = V_21 . V_22 +
V_37 -> V_87 -> V_54 ;
else
V_70 = V_21 . V_22 + V_21 . V_33 ;
if ( V_69 > V_88 ) {
V_69 = 0 ;
if ( V_72 )
F_52 ( & V_51 -> V_89 ) ;
}
}
V_65 -> V_82 [ 0 ] ++ ;
}
V_29 = 0 ;
V_69 += F_29 ( V_14 , V_37 , V_70 ,
V_14 -> V_21 . V_22 +
V_14 -> V_21 . V_33 ) ;
V_51 -> V_84 = ( T_2 ) - 1 ;
V_80:
F_53 ( V_65 ) ;
return V_29 ;
}
static T_1 void F_54 ( struct V_90 * V_91 )
{
struct V_1 * V_14 ;
struct V_12 * V_37 ;
struct V_48 * V_51 ;
struct V_34 * V_63 ;
int V_29 ;
V_51 = F_55 ( V_91 , struct V_48 , V_91 ) ;
V_14 = V_51 -> V_14 ;
V_37 = V_14 -> V_37 ;
V_63 = V_37 -> V_63 ;
F_49 ( & V_51 -> V_85 ) ;
F_50 ( & V_37 -> V_83 ) ;
if ( F_56 ( V_37 , V_92 ) )
V_29 = F_57 ( V_51 ) ;
else
V_29 = F_33 ( V_51 ) ;
F_11 ( & V_14 -> V_50 ) ;
V_14 -> V_51 = NULL ;
V_14 -> V_3 = V_29 ? V_5 : V_4 ;
F_13 ( & V_14 -> V_50 ) ;
#ifdef F_36
if ( F_37 ( V_63 , V_14 ) ) {
T_2 V_93 ;
F_11 ( & V_14 -> V_94 -> V_50 ) ;
F_11 ( & V_14 -> V_50 ) ;
V_93 = V_14 -> V_21 . V_33 -
F_58 ( & V_14 -> V_95 ) ;
V_14 -> V_94 -> V_93 += V_93 >> 1 ;
F_13 ( & V_14 -> V_50 ) ;
F_13 ( & V_14 -> V_94 -> V_50 ) ;
F_27 ( V_63 , V_14 ) ;
}
#endif
V_51 -> V_84 = ( T_2 ) - 1 ;
F_46 ( & V_37 -> V_83 ) ;
F_19 ( V_37 -> V_63 , V_14 ) ;
F_47 ( & V_51 -> V_85 ) ;
F_52 ( & V_51 -> V_89 ) ;
F_26 ( V_51 ) ;
F_6 ( V_14 ) ;
}
static int F_59 ( struct V_1 * V_2 ,
int V_96 )
{
F_60 ( V_89 ) ;
struct V_12 * V_37 = V_2 -> V_37 ;
struct V_48 * V_51 ;
int V_29 = 0 ;
V_51 = F_61 ( sizeof( * V_51 ) , V_97 ) ;
if ( ! V_51 )
return - V_73 ;
F_62 ( & V_51 -> V_98 ) ;
F_63 ( & V_51 -> V_85 ) ;
F_64 ( & V_51 -> V_89 ) ;
V_51 -> V_14 = V_2 ;
V_51 -> V_84 = V_2 -> V_21 . V_22 ;
F_65 ( & V_51 -> V_8 , 1 ) ;
F_66 ( & V_51 -> V_91 , V_99 ,
F_54 , NULL , NULL ) ;
F_11 ( & V_2 -> V_50 ) ;
while ( V_2 -> V_3 == V_100 ) {
struct V_48 * V_49 ;
V_49 = V_2 -> V_51 ;
F_5 ( & V_49 -> V_8 ) ;
F_67 ( & V_49 -> V_89 , & V_89 , V_101 ) ;
F_13 ( & V_2 -> V_50 ) ;
F_68 () ;
F_69 ( & V_49 -> V_89 , & V_89 ) ;
F_26 ( V_49 ) ;
F_11 ( & V_2 -> V_50 ) ;
}
if ( V_2 -> V_3 != V_102 ) {
F_13 ( & V_2 -> V_50 ) ;
F_9 ( V_51 ) ;
return 0 ;
}
F_8 ( V_2 -> V_51 ) ;
V_2 -> V_51 = V_51 ;
V_2 -> V_3 = V_100 ;
F_13 ( & V_2 -> V_50 ) ;
if ( V_37 -> V_103 & V_104 ) {
F_49 ( & V_51 -> V_85 ) ;
V_29 = F_70 ( V_37 , V_2 ) ;
F_11 ( & V_2 -> V_50 ) ;
if ( V_29 == 1 ) {
V_2 -> V_51 = NULL ;
V_2 -> V_3 = V_4 ;
V_2 -> V_105 = ( T_2 ) - 1 ;
V_51 -> V_84 = ( T_2 ) - 1 ;
} else {
if ( V_96 ) {
V_2 -> V_51 = NULL ;
V_2 -> V_3 = V_102 ;
} else {
V_2 -> V_3 = V_106 ;
V_2 -> V_107 = 1 ;
}
}
F_13 ( & V_2 -> V_50 ) ;
#ifdef F_36
if ( V_29 == 1 &&
F_37 ( V_37 -> V_63 ,
V_2 ) ) {
T_2 V_93 ;
F_11 ( & V_2 -> V_94 -> V_50 ) ;
F_11 ( & V_2 -> V_50 ) ;
V_93 = V_2 -> V_21 . V_33 -
F_58 ( & V_2 -> V_95 ) ;
V_2 -> V_94 -> V_93 += V_93 >> 1 ;
F_13 ( & V_2 -> V_50 ) ;
F_13 ( & V_2 -> V_94 -> V_50 ) ;
F_27 ( V_37 -> V_63 , V_2 ) ;
}
#endif
F_47 ( & V_51 -> V_85 ) ;
F_52 ( & V_51 -> V_89 ) ;
if ( V_29 == 1 ) {
F_26 ( V_51 ) ;
F_19 ( V_37 -> V_63 , V_2 ) ;
return 0 ;
}
} else {
F_11 ( & V_2 -> V_50 ) ;
if ( V_96 ) {
V_2 -> V_51 = NULL ;
V_2 -> V_3 = V_102 ;
} else {
V_2 -> V_3 = V_106 ;
V_2 -> V_107 = 1 ;
}
F_13 ( & V_2 -> V_50 ) ;
F_52 ( & V_51 -> V_89 ) ;
}
if ( V_96 ) {
F_26 ( V_51 ) ;
return 0 ;
}
F_71 ( & V_37 -> V_83 ) ;
F_5 ( & V_51 -> V_8 ) ;
F_72 ( & V_51 -> V_98 , & V_37 -> V_108 ) ;
F_73 ( & V_37 -> V_83 ) ;
F_4 ( V_2 ) ;
F_74 ( V_37 -> V_109 , & V_51 -> V_91 ) ;
return V_29 ;
}
static struct V_1 *
F_75 ( struct V_12 * V_13 , T_2 V_27 )
{
return F_16 ( V_13 , V_27 , 0 ) ;
}
struct V_1 * F_76 (
struct V_12 * V_13 ,
T_2 V_27 )
{
return F_16 ( V_13 , V_27 , 1 ) ;
}
static struct V_110 * F_77 ( struct V_12 * V_13 ,
T_2 V_7 )
{
struct V_111 * V_112 = & V_13 -> V_94 ;
struct V_110 * V_113 ;
V_7 &= V_114 ;
F_78 () ;
F_79 (found, head, list) {
if ( V_113 -> V_7 & V_7 ) {
F_80 () ;
return V_113 ;
}
}
F_80 () ;
return NULL ;
}
void F_81 ( struct V_12 * V_13 )
{
struct V_111 * V_112 = & V_13 -> V_94 ;
struct V_110 * V_113 ;
F_78 () ;
F_79 (found, head, list)
V_113 -> V_115 = 0 ;
F_80 () ;
}
int F_82 ( struct V_34 * V_35 , T_2 V_32 , T_2 V_47 )
{
int V_29 ;
struct V_68 V_21 ;
struct V_64 * V_65 ;
V_65 = F_34 () ;
if ( ! V_65 )
return - V_73 ;
V_21 . V_22 = V_32 ;
V_21 . V_33 = V_47 ;
V_21 . type = V_78 ;
V_29 = F_38 ( NULL , V_35 -> V_37 -> V_63 , & V_21 , V_65 ,
0 , 0 ) ;
F_53 ( V_65 ) ;
return V_29 ;
}
int F_83 ( struct V_116 * V_117 ,
struct V_34 * V_35 , T_2 V_27 ,
T_2 V_33 , int V_118 , T_2 * V_119 , T_2 * V_7 )
{
struct V_120 * V_112 ;
struct V_121 * V_122 ;
struct V_64 * V_65 ;
struct V_123 * V_124 ;
struct V_66 * V_67 ;
struct V_68 V_21 ;
T_3 V_125 ;
T_2 V_126 ;
T_2 V_127 ;
int V_29 ;
if ( V_118 && ! F_84 ( V_35 -> V_37 , V_128 ) ) {
V_33 = V_35 -> V_54 ;
V_118 = 0 ;
}
V_65 = F_34 () ;
if ( ! V_65 )
return - V_73 ;
if ( ! V_117 ) {
V_65 -> V_74 = 1 ;
V_65 -> V_75 = 1 ;
}
V_129:
V_21 . V_22 = V_27 ;
V_21 . V_33 = V_33 ;
if ( V_118 )
V_21 . type = V_86 ;
else
V_21 . type = V_78 ;
V_29 = F_38 ( V_117 , V_35 -> V_37 -> V_63 ,
& V_21 , V_65 , 0 , 0 ) ;
if ( V_29 < 0 )
goto V_130;
if ( V_29 > 0 && V_118 && V_21 . type == V_86 ) {
if ( V_65 -> V_82 [ 0 ] ) {
V_65 -> V_82 [ 0 ] -- ;
F_41 ( V_65 -> V_81 [ 0 ] , & V_21 ,
V_65 -> V_82 [ 0 ] ) ;
if ( V_21 . V_22 == V_27 &&
V_21 . type == V_78 &&
V_21 . V_33 == V_35 -> V_54 )
V_29 = 0 ;
}
}
if ( V_29 == 0 ) {
V_67 = V_65 -> V_81 [ 0 ] ;
V_125 = F_85 ( V_67 , V_65 -> V_82 [ 0 ] ) ;
if ( V_125 >= sizeof( * V_124 ) ) {
V_124 = F_86 ( V_67 , V_65 -> V_82 [ 0 ] ,
struct V_123 ) ;
V_126 = F_87 ( V_67 , V_124 ) ;
V_127 = F_88 ( V_67 , V_124 ) ;
} else {
#ifdef F_89
struct V_131 * V_132 ;
F_32 ( V_125 != sizeof( * V_132 ) ) ;
V_132 = F_86 ( V_67 , V_65 -> V_82 [ 0 ] ,
struct V_131 ) ;
V_126 = F_90 ( V_67 , V_132 ) ;
V_127 = V_133 ;
#else
F_91 () ;
#endif
}
F_32 ( V_126 == 0 ) ;
} else {
V_126 = 0 ;
V_127 = 0 ;
V_29 = 0 ;
}
if ( ! V_117 )
goto V_80;
V_122 = & V_117 -> V_134 -> V_122 ;
F_11 ( & V_122 -> V_50 ) ;
V_112 = F_92 ( V_117 , V_27 ) ;
if ( V_112 ) {
if ( ! F_93 ( & V_112 -> V_85 ) ) {
F_5 ( & V_112 -> V_135 . V_119 ) ;
F_13 ( & V_122 -> V_50 ) ;
F_45 ( V_65 ) ;
F_49 ( & V_112 -> V_85 ) ;
F_47 ( & V_112 -> V_85 ) ;
F_94 ( & V_112 -> V_135 ) ;
goto V_129;
}
F_11 ( & V_112 -> V_50 ) ;
if ( V_112 -> V_136 && V_112 -> V_136 -> V_137 )
V_127 |= V_112 -> V_136 -> V_138 ;
else
F_32 ( V_126 == 0 ) ;
V_126 += V_112 -> V_135 . V_139 ;
F_13 ( & V_112 -> V_50 ) ;
F_47 ( & V_112 -> V_85 ) ;
}
F_13 ( & V_122 -> V_50 ) ;
V_80:
F_8 ( V_126 == 0 ) ;
if ( V_119 )
* V_119 = V_126 ;
if ( V_7 )
* V_7 = V_127 ;
V_130:
F_53 ( V_65 ) ;
return V_29 ;
}
static int F_95 ( struct V_116 * V_117 ,
struct V_34 * V_35 ,
struct V_64 * V_65 ,
T_2 V_140 , T_3 V_141 )
{
struct V_123 * V_95 ;
struct V_131 * V_132 ;
struct V_142 * V_143 ;
struct V_144 * V_145 ;
struct V_66 * V_67 ;
struct V_68 V_21 ;
struct V_68 V_146 ;
T_3 V_147 = sizeof( * V_95 ) ;
T_2 V_119 ;
int V_29 ;
V_67 = V_65 -> V_81 [ 0 ] ;
F_32 ( F_85 ( V_67 , V_65 -> V_82 [ 0 ] ) != sizeof( * V_132 ) ) ;
F_41 ( V_67 , & V_21 , V_65 -> V_82 [ 0 ] ) ;
V_132 = F_86 ( V_67 , V_65 -> V_82 [ 0 ] ,
struct V_131 ) ;
V_119 = F_90 ( V_67 , V_132 ) ;
if ( V_140 == ( T_2 ) - 1 ) {
while ( 1 ) {
if ( V_65 -> V_82 [ 0 ] >= F_39 ( V_67 ) ) {
V_29 = F_51 ( V_35 , V_65 ) ;
if ( V_29 < 0 )
return V_29 ;
F_32 ( V_29 > 0 ) ;
V_67 = V_65 -> V_81 [ 0 ] ;
}
F_41 ( V_67 , & V_146 ,
V_65 -> V_82 [ 0 ] ) ;
F_32 ( V_21 . V_22 != V_146 . V_22 ) ;
if ( V_146 . type != V_148 ) {
V_65 -> V_82 [ 0 ] ++ ;
continue;
}
V_143 = F_86 ( V_67 , V_65 -> V_82 [ 0 ] ,
struct V_142 ) ;
V_140 = F_96 ( V_67 , V_143 ) ;
break;
}
}
F_45 ( V_65 ) ;
if ( V_140 < V_149 )
V_147 += sizeof( * V_145 ) ;
V_147 -= sizeof( * V_132 ) ;
V_29 = F_38 ( V_117 , V_35 , & V_21 , V_65 ,
V_147 + V_141 , 1 ) ;
if ( V_29 < 0 )
return V_29 ;
F_32 ( V_29 ) ;
F_97 ( V_35 , V_65 , V_147 ) ;
V_67 = V_65 -> V_81 [ 0 ] ;
V_95 = F_86 ( V_67 , V_65 -> V_82 [ 0 ] , struct V_123 ) ;
F_98 ( V_67 , V_95 , V_119 ) ;
F_99 ( V_67 , V_95 , 0 ) ;
if ( V_140 < V_149 ) {
F_100 ( V_67 , V_95 ,
V_150 |
V_133 ) ;
V_145 = (struct V_144 * ) ( V_95 + 1 ) ;
F_101 ( V_67 , 0 , ( unsigned long ) V_145 , sizeof( * V_145 ) ) ;
F_102 ( V_67 , V_145 , ( int ) V_140 ) ;
} else {
F_100 ( V_67 , V_95 , V_151 ) ;
}
F_103 ( V_67 ) ;
return 0 ;
}
static T_2 F_104 ( T_2 V_152 , T_2 V_140 , T_2 V_33 )
{
T_3 V_153 = ~ ( T_3 ) 0 ;
T_3 V_154 = ~ ( T_3 ) 0 ;
T_4 V_155 ;
V_155 = F_105 ( V_152 ) ;
V_153 = F_106 ( V_153 , & V_155 , sizeof( V_155 ) ) ;
V_155 = F_105 ( V_140 ) ;
V_154 = F_106 ( V_154 , & V_155 , sizeof( V_155 ) ) ;
V_155 = F_105 ( V_33 ) ;
V_154 = F_106 ( V_154 , & V_155 , sizeof( V_155 ) ) ;
return ( ( T_2 ) V_153 << 31 ) ^ ( T_2 ) V_154 ;
}
static T_2 F_107 ( struct V_66 * V_67 ,
struct V_156 * V_157 )
{
return F_104 ( F_108 ( V_67 , V_157 ) ,
F_109 ( V_67 , V_157 ) ,
F_110 ( V_67 , V_157 ) ) ;
}
static int F_111 ( struct V_66 * V_67 ,
struct V_156 * V_157 ,
T_2 V_152 , T_2 V_140 , T_2 V_33 )
{
if ( F_108 ( V_67 , V_157 ) != V_152 ||
F_109 ( V_67 , V_157 ) != V_140 ||
F_110 ( V_67 , V_157 ) != V_33 )
return 0 ;
return 1 ;
}
static T_1 int F_112 ( struct V_116 * V_117 ,
struct V_34 * V_35 ,
struct V_64 * V_65 ,
T_2 V_27 , T_2 V_17 ,
T_2 V_152 ,
T_2 V_140 , T_2 V_33 )
{
struct V_68 V_21 ;
struct V_156 * V_157 ;
struct V_66 * V_67 ;
T_3 V_71 ;
int V_29 ;
int V_158 ;
int V_159 = - V_160 ;
V_21 . V_22 = V_27 ;
if ( V_17 ) {
V_21 . type = V_161 ;
V_21 . V_33 = V_17 ;
} else {
V_21 . type = V_162 ;
V_21 . V_33 = F_104 ( V_152 ,
V_140 , V_33 ) ;
}
V_163:
V_158 = 0 ;
V_29 = F_38 ( V_117 , V_35 , & V_21 , V_65 , - 1 , 1 ) ;
if ( V_29 < 0 ) {
V_159 = V_29 ;
goto V_164;
}
if ( V_17 ) {
if ( ! V_29 )
return 0 ;
#ifdef F_89
V_21 . type = V_148 ;
F_45 ( V_65 ) ;
V_29 = F_38 ( V_117 , V_35 , & V_21 , V_65 , - 1 , 1 ) ;
if ( V_29 < 0 ) {
V_159 = V_29 ;
goto V_164;
}
if ( ! V_29 )
return 0 ;
#endif
goto V_164;
}
V_67 = V_65 -> V_81 [ 0 ] ;
V_71 = F_39 ( V_67 ) ;
while ( 1 ) {
if ( V_65 -> V_82 [ 0 ] >= V_71 ) {
V_29 = F_51 ( V_35 , V_65 ) ;
if ( V_29 < 0 )
V_159 = V_29 ;
if ( V_29 )
goto V_164;
V_67 = V_65 -> V_81 [ 0 ] ;
V_71 = F_39 ( V_67 ) ;
V_158 = 1 ;
}
F_41 ( V_67 , & V_21 , V_65 -> V_82 [ 0 ] ) ;
if ( V_21 . V_22 != V_27 ||
V_21 . type != V_162 )
goto V_164;
V_157 = F_86 ( V_67 , V_65 -> V_82 [ 0 ] ,
struct V_156 ) ;
if ( F_111 ( V_67 , V_157 , V_152 ,
V_140 , V_33 ) ) {
if ( V_158 ) {
F_45 ( V_65 ) ;
goto V_163;
}
V_159 = 0 ;
break;
}
V_65 -> V_82 [ 0 ] ++ ;
}
V_164:
return V_159 ;
}
static T_1 int F_113 ( struct V_116 * V_117 ,
struct V_34 * V_35 ,
struct V_64 * V_65 ,
T_2 V_27 , T_2 V_17 ,
T_2 V_152 , T_2 V_140 ,
T_2 V_33 , int V_165 )
{
struct V_68 V_21 ;
struct V_66 * V_67 ;
T_3 V_59 ;
T_3 V_126 ;
int V_29 ;
V_21 . V_22 = V_27 ;
if ( V_17 ) {
V_21 . type = V_161 ;
V_21 . V_33 = V_17 ;
V_59 = sizeof( struct V_166 ) ;
} else {
V_21 . type = V_162 ;
V_21 . V_33 = F_104 ( V_152 ,
V_140 , V_33 ) ;
V_59 = sizeof( struct V_156 ) ;
}
V_29 = F_114 ( V_117 , V_35 , V_65 , & V_21 , V_59 ) ;
if ( V_29 && V_29 != - V_25 )
goto V_164;
V_67 = V_65 -> V_81 [ 0 ] ;
if ( V_17 ) {
struct V_166 * V_157 ;
V_157 = F_86 ( V_67 , V_65 -> V_82 [ 0 ] ,
struct V_166 ) ;
if ( V_29 == 0 ) {
F_115 ( V_67 , V_157 , V_165 ) ;
} else {
V_126 = F_116 ( V_67 , V_157 ) ;
V_126 += V_165 ;
F_115 ( V_67 , V_157 , V_126 ) ;
}
} else {
struct V_156 * V_157 ;
while ( V_29 == - V_25 ) {
V_157 = F_86 ( V_67 , V_65 -> V_82 [ 0 ] ,
struct V_156 ) ;
if ( F_111 ( V_67 , V_157 , V_152 ,
V_140 , V_33 ) )
break;
F_45 ( V_65 ) ;
V_21 . V_33 ++ ;
V_29 = F_114 ( V_117 , V_35 , V_65 , & V_21 ,
V_59 ) ;
if ( V_29 && V_29 != - V_25 )
goto V_164;
V_67 = V_65 -> V_81 [ 0 ] ;
}
V_157 = F_86 ( V_67 , V_65 -> V_82 [ 0 ] ,
struct V_156 ) ;
if ( V_29 == 0 ) {
F_117 ( V_67 , V_157 ,
V_152 ) ;
F_118 ( V_67 , V_157 , V_140 ) ;
F_119 ( V_67 , V_157 , V_33 ) ;
F_120 ( V_67 , V_157 , V_165 ) ;
} else {
V_126 = F_121 ( V_67 , V_157 ) ;
V_126 += V_165 ;
F_120 ( V_67 , V_157 , V_126 ) ;
}
}
F_103 ( V_67 ) ;
V_29 = 0 ;
V_164:
F_45 ( V_65 ) ;
return V_29 ;
}
static T_1 int F_122 ( struct V_116 * V_117 ,
struct V_34 * V_35 ,
struct V_64 * V_65 ,
int V_167 , int * V_168 )
{
struct V_68 V_21 ;
struct V_156 * V_169 = NULL ;
struct V_166 * V_170 = NULL ;
struct V_66 * V_67 ;
T_3 V_126 = 0 ;
int V_29 = 0 ;
V_67 = V_65 -> V_81 [ 0 ] ;
F_41 ( V_67 , & V_21 , V_65 -> V_82 [ 0 ] ) ;
if ( V_21 . type == V_162 ) {
V_169 = F_86 ( V_67 , V_65 -> V_82 [ 0 ] ,
struct V_156 ) ;
V_126 = F_121 ( V_67 , V_169 ) ;
} else if ( V_21 . type == V_161 ) {
V_170 = F_86 ( V_67 , V_65 -> V_82 [ 0 ] ,
struct V_166 ) ;
V_126 = F_116 ( V_67 , V_170 ) ;
#ifdef F_89
} else if ( V_21 . type == V_148 ) {
struct V_142 * V_143 ;
V_143 = F_86 ( V_67 , V_65 -> V_82 [ 0 ] ,
struct V_142 ) ;
V_126 = F_123 ( V_67 , V_143 ) ;
#endif
} else {
F_91 () ;
}
F_32 ( V_126 < V_167 ) ;
V_126 -= V_167 ;
if ( V_126 == 0 ) {
V_29 = F_124 ( V_117 , V_35 , V_65 ) ;
* V_168 = 1 ;
} else {
if ( V_21 . type == V_162 )
F_120 ( V_67 , V_169 , V_126 ) ;
else if ( V_21 . type == V_161 )
F_115 ( V_67 , V_170 , V_126 ) ;
#ifdef F_89
else {
struct V_142 * V_143 ;
V_143 = F_86 ( V_67 , V_65 -> V_82 [ 0 ] ,
struct V_142 ) ;
F_125 ( V_67 , V_143 , V_126 ) ;
}
#endif
F_103 ( V_67 ) ;
}
return V_29 ;
}
static T_1 T_3 F_126 ( struct V_64 * V_65 ,
struct V_171 * V_172 )
{
struct V_68 V_21 ;
struct V_66 * V_67 ;
struct V_156 * V_169 ;
struct V_166 * V_170 ;
T_3 V_126 = 0 ;
V_67 = V_65 -> V_81 [ 0 ] ;
F_41 ( V_67 , & V_21 , V_65 -> V_82 [ 0 ] ) ;
if ( V_172 ) {
if ( F_127 ( V_67 , V_172 ) ==
V_162 ) {
V_169 = (struct V_156 * ) ( & V_172 -> V_33 ) ;
V_126 = F_121 ( V_67 , V_169 ) ;
} else {
V_170 = (struct V_166 * ) ( V_172 + 1 ) ;
V_126 = F_116 ( V_67 , V_170 ) ;
}
} else if ( V_21 . type == V_162 ) {
V_169 = F_86 ( V_67 , V_65 -> V_82 [ 0 ] ,
struct V_156 ) ;
V_126 = F_121 ( V_67 , V_169 ) ;
} else if ( V_21 . type == V_161 ) {
V_170 = F_86 ( V_67 , V_65 -> V_82 [ 0 ] ,
struct V_166 ) ;
V_126 = F_116 ( V_67 , V_170 ) ;
#ifdef F_89
} else if ( V_21 . type == V_148 ) {
struct V_142 * V_143 ;
V_143 = F_86 ( V_67 , V_65 -> V_82 [ 0 ] ,
struct V_142 ) ;
V_126 = F_123 ( V_67 , V_143 ) ;
#endif
} else {
F_8 ( 1 ) ;
}
return V_126 ;
}
static T_1 int F_128 ( struct V_116 * V_117 ,
struct V_34 * V_35 ,
struct V_64 * V_65 ,
T_2 V_27 , T_2 V_17 ,
T_2 V_152 )
{
struct V_68 V_21 ;
int V_29 ;
V_21 . V_22 = V_27 ;
if ( V_17 ) {
V_21 . type = V_173 ;
V_21 . V_33 = V_17 ;
} else {
V_21 . type = V_174 ;
V_21 . V_33 = V_152 ;
}
V_29 = F_38 ( V_117 , V_35 , & V_21 , V_65 , - 1 , 1 ) ;
if ( V_29 > 0 )
V_29 = - V_160 ;
#ifdef F_89
if ( V_29 == - V_160 && V_17 ) {
F_45 ( V_65 ) ;
V_21 . type = V_148 ;
V_29 = F_38 ( V_117 , V_35 , & V_21 , V_65 , - 1 , 1 ) ;
if ( V_29 > 0 )
V_29 = - V_160 ;
}
#endif
return V_29 ;
}
static T_1 int F_129 ( struct V_116 * V_117 ,
struct V_34 * V_35 ,
struct V_64 * V_65 ,
T_2 V_27 , T_2 V_17 ,
T_2 V_152 )
{
struct V_68 V_21 ;
int V_29 ;
V_21 . V_22 = V_27 ;
if ( V_17 ) {
V_21 . type = V_173 ;
V_21 . V_33 = V_17 ;
} else {
V_21 . type = V_174 ;
V_21 . V_33 = V_152 ;
}
V_29 = F_114 ( V_117 , V_35 , V_65 , & V_21 , 0 ) ;
F_45 ( V_65 ) ;
return V_29 ;
}
static inline int F_130 ( T_2 V_17 , T_2 V_140 )
{
int type ;
if ( V_140 < V_149 ) {
if ( V_17 > 0 )
type = V_173 ;
else
type = V_174 ;
} else {
if ( V_17 > 0 )
type = V_161 ;
else
type = V_162 ;
}
return type ;
}
static int F_42 ( struct V_64 * V_65 , int V_175 ,
struct V_68 * V_21 )
{
for (; V_175 < V_176 ; V_175 ++ ) {
if ( ! V_65 -> V_81 [ V_175 ] )
break;
if ( V_65 -> V_82 [ V_175 ] + 1 >=
F_39 ( V_65 -> V_81 [ V_175 ] ) )
continue;
if ( V_175 == 0 )
F_41 ( V_65 -> V_81 [ V_175 ] , V_21 ,
V_65 -> V_82 [ V_175 ] + 1 ) ;
else
F_131 ( V_65 -> V_81 [ V_175 ] , V_21 ,
V_65 -> V_82 [ V_175 ] + 1 ) ;
return 0 ;
}
return 1 ;
}
static T_5
int F_132 ( struct V_116 * V_117 ,
struct V_34 * V_35 ,
struct V_64 * V_65 ,
struct V_171 * * V_177 ,
T_2 V_27 , T_2 V_36 ,
T_2 V_17 , T_2 V_152 ,
T_2 V_140 , T_2 V_33 , int V_178 )
{
struct V_68 V_21 ;
struct V_66 * V_67 ;
struct V_123 * V_124 ;
struct V_171 * V_172 ;
T_2 V_7 ;
T_2 V_125 ;
unsigned long V_179 ;
unsigned long V_31 ;
int V_141 ;
int type ;
int V_180 ;
int V_29 ;
int V_159 = 0 ;
bool V_181 = F_84 ( V_35 -> V_37 ,
V_128 ) ;
V_21 . V_22 = V_27 ;
V_21 . type = V_78 ;
V_21 . V_33 = V_36 ;
V_180 = F_130 ( V_17 , V_140 ) ;
if ( V_178 ) {
V_141 = F_133 ( V_180 ) ;
V_65 -> V_182 = 1 ;
} else
V_141 = - 1 ;
if ( V_181 && V_140 < V_149 ) {
V_21 . type = V_86 ;
V_21 . V_33 = V_140 ;
}
V_163:
V_29 = F_38 ( V_117 , V_35 , & V_21 , V_65 , V_141 , 1 ) ;
if ( V_29 < 0 ) {
V_159 = V_29 ;
goto V_80;
}
if ( V_29 > 0 && V_181 ) {
V_181 = false ;
if ( V_65 -> V_82 [ 0 ] ) {
V_65 -> V_82 [ 0 ] -- ;
F_41 ( V_65 -> V_81 [ 0 ] , & V_21 ,
V_65 -> V_82 [ 0 ] ) ;
if ( V_21 . V_22 == V_27 &&
V_21 . type == V_78 &&
V_21 . V_33 == V_36 )
V_29 = 0 ;
}
if ( V_29 ) {
V_21 . V_22 = V_27 ;
V_21 . type = V_78 ;
V_21 . V_33 = V_36 ;
F_45 ( V_65 ) ;
goto V_163;
}
}
if ( V_29 && ! V_178 ) {
V_159 = - V_160 ;
goto V_80;
} else if ( F_8 ( V_29 ) ) {
V_159 = - V_183 ;
goto V_80;
}
V_67 = V_65 -> V_81 [ 0 ] ;
V_125 = F_85 ( V_67 , V_65 -> V_82 [ 0 ] ) ;
#ifdef F_89
if ( V_125 < sizeof( * V_124 ) ) {
if ( ! V_178 ) {
V_159 = - V_160 ;
goto V_80;
}
V_29 = F_95 ( V_117 , V_35 , V_65 , V_140 ,
V_141 ) ;
if ( V_29 < 0 ) {
V_159 = V_29 ;
goto V_80;
}
V_67 = V_65 -> V_81 [ 0 ] ;
V_125 = F_85 ( V_67 , V_65 -> V_82 [ 0 ] ) ;
}
#endif
F_32 ( V_125 < sizeof( * V_124 ) ) ;
V_124 = F_86 ( V_67 , V_65 -> V_82 [ 0 ] , struct V_123 ) ;
V_7 = F_88 ( V_67 , V_124 ) ;
V_179 = ( unsigned long ) ( V_124 + 1 ) ;
V_31 = ( unsigned long ) V_124 + V_125 ;
if ( V_7 & V_150 && ! V_181 ) {
V_179 += sizeof( struct V_144 ) ;
F_32 ( V_179 > V_31 ) ;
}
V_159 = - V_160 ;
while ( 1 ) {
if ( V_179 >= V_31 ) {
F_8 ( V_179 > V_31 ) ;
break;
}
V_172 = (struct V_171 * ) V_179 ;
type = F_127 ( V_67 , V_172 ) ;
if ( V_180 < type )
break;
if ( V_180 > type ) {
V_179 += F_133 ( type ) ;
continue;
}
if ( type == V_162 ) {
struct V_156 * V_184 ;
V_184 = (struct V_156 * ) ( & V_172 -> V_33 ) ;
if ( F_111 ( V_67 , V_184 , V_152 ,
V_140 , V_33 ) ) {
V_159 = 0 ;
break;
}
if ( F_107 ( V_67 , V_184 ) <
F_104 ( V_152 , V_140 , V_33 ) )
break;
} else {
T_2 V_185 ;
V_185 = F_134 ( V_67 , V_172 ) ;
if ( V_17 > 0 ) {
if ( V_17 == V_185 ) {
V_159 = 0 ;
break;
}
if ( V_185 < V_17 )
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
V_179 += F_133 ( type ) ;
}
if ( V_159 == - V_160 && V_178 ) {
if ( V_125 + V_141 >=
F_135 ( V_35 ) ) {
V_159 = - V_186 ;
goto V_80;
}
if ( F_42 ( V_65 , 0 , & V_21 ) == 0 &&
V_21 . V_22 == V_27 &&
V_21 . type < V_187 ) {
V_159 = - V_186 ;
goto V_80;
}
}
* V_177 = (struct V_171 * ) V_179 ;
V_80:
if ( V_178 ) {
V_65 -> V_182 = 0 ;
F_136 ( V_65 , 1 ) ;
}
return V_159 ;
}
static T_5
void F_137 ( struct V_34 * V_35 ,
struct V_64 * V_65 ,
struct V_171 * V_172 ,
T_2 V_17 , T_2 V_152 ,
T_2 V_140 , T_2 V_33 , int V_165 ,
struct V_188 * V_136 )
{
struct V_66 * V_67 ;
struct V_123 * V_124 ;
unsigned long V_179 ;
unsigned long V_31 ;
unsigned long V_189 ;
T_2 V_119 ;
int V_59 ;
int type ;
V_67 = V_65 -> V_81 [ 0 ] ;
V_124 = F_86 ( V_67 , V_65 -> V_82 [ 0 ] , struct V_123 ) ;
V_189 = ( unsigned long ) V_172 - ( unsigned long ) V_124 ;
type = F_130 ( V_17 , V_140 ) ;
V_59 = F_133 ( type ) ;
F_97 ( V_35 , V_65 , V_59 ) ;
V_124 = F_86 ( V_67 , V_65 -> V_82 [ 0 ] , struct V_123 ) ;
V_119 = F_87 ( V_67 , V_124 ) ;
V_119 += V_165 ;
F_98 ( V_67 , V_124 , V_119 ) ;
if ( V_136 )
F_138 ( V_136 , V_67 , V_124 ) ;
V_179 = ( unsigned long ) V_124 + V_189 ;
V_31 = ( unsigned long ) V_124 + F_85 ( V_67 , V_65 -> V_82 [ 0 ] ) ;
if ( V_179 < V_31 - V_59 )
F_139 ( V_67 , V_179 + V_59 , V_179 ,
V_31 - V_59 - V_179 ) ;
V_172 = (struct V_171 * ) V_179 ;
F_140 ( V_67 , V_172 , type ) ;
if ( type == V_162 ) {
struct V_156 * V_184 ;
V_184 = (struct V_156 * ) ( & V_172 -> V_33 ) ;
F_117 ( V_67 , V_184 , V_152 ) ;
F_118 ( V_67 , V_184 , V_140 ) ;
F_119 ( V_67 , V_184 , V_33 ) ;
F_120 ( V_67 , V_184 , V_165 ) ;
} else if ( type == V_161 ) {
struct V_166 * V_190 ;
V_190 = (struct V_166 * ) ( V_172 + 1 ) ;
F_115 ( V_67 , V_190 , V_165 ) ;
F_141 ( V_67 , V_172 , V_17 ) ;
} else if ( type == V_173 ) {
F_141 ( V_67 , V_172 , V_17 ) ;
} else {
F_141 ( V_67 , V_172 , V_152 ) ;
}
F_103 ( V_67 ) ;
}
static int F_142 ( struct V_116 * V_117 ,
struct V_34 * V_35 ,
struct V_64 * V_65 ,
struct V_171 * * V_177 ,
T_2 V_27 , T_2 V_36 , T_2 V_17 ,
T_2 V_152 , T_2 V_140 , T_2 V_33 )
{
int V_29 ;
V_29 = F_132 ( V_117 , V_35 , V_65 , V_177 ,
V_27 , V_36 , V_17 ,
V_152 , V_140 , V_33 , 0 ) ;
if ( V_29 != - V_160 )
return V_29 ;
F_45 ( V_65 ) ;
* V_177 = NULL ;
if ( V_140 < V_149 ) {
V_29 = F_128 ( V_117 , V_35 , V_65 , V_27 , V_17 ,
V_152 ) ;
} else {
V_29 = F_112 ( V_117 , V_35 , V_65 , V_27 , V_17 ,
V_152 , V_140 , V_33 ) ;
}
return V_29 ;
}
static T_5
void F_143 ( struct V_34 * V_35 ,
struct V_64 * V_65 ,
struct V_171 * V_172 ,
int V_191 ,
struct V_188 * V_136 ,
int * V_168 )
{
struct V_66 * V_67 ;
struct V_123 * V_124 ;
struct V_156 * V_184 = NULL ;
struct V_166 * V_190 = NULL ;
unsigned long V_179 ;
unsigned long V_31 ;
T_3 V_125 ;
int V_59 ;
int type ;
T_2 V_119 ;
V_67 = V_65 -> V_81 [ 0 ] ;
V_124 = F_86 ( V_67 , V_65 -> V_82 [ 0 ] , struct V_123 ) ;
V_119 = F_87 ( V_67 , V_124 ) ;
F_8 ( V_191 < 0 && V_119 + V_191 <= 0 ) ;
V_119 += V_191 ;
F_98 ( V_67 , V_124 , V_119 ) ;
if ( V_136 )
F_138 ( V_136 , V_67 , V_124 ) ;
type = F_127 ( V_67 , V_172 ) ;
if ( type == V_162 ) {
V_184 = (struct V_156 * ) ( & V_172 -> V_33 ) ;
V_119 = F_121 ( V_67 , V_184 ) ;
} else if ( type == V_161 ) {
V_190 = (struct V_166 * ) ( V_172 + 1 ) ;
V_119 = F_116 ( V_67 , V_190 ) ;
} else {
V_119 = 1 ;
F_32 ( V_191 != - 1 ) ;
}
F_32 ( V_191 < 0 && V_119 < - V_191 ) ;
V_119 += V_191 ;
if ( V_119 > 0 ) {
if ( type == V_162 )
F_120 ( V_67 , V_184 , V_119 ) ;
else
F_115 ( V_67 , V_190 , V_119 ) ;
} else {
* V_168 = 1 ;
V_59 = F_133 ( type ) ;
V_125 = F_85 ( V_67 , V_65 -> V_82 [ 0 ] ) ;
V_179 = ( unsigned long ) V_172 ;
V_31 = ( unsigned long ) V_124 + V_125 ;
if ( V_179 + V_59 < V_31 )
F_139 ( V_67 , V_179 , V_179 + V_59 ,
V_31 - V_179 - V_59 ) ;
V_125 -= V_59 ;
F_144 ( V_35 , V_65 , V_125 , 1 ) ;
}
F_103 ( V_67 ) ;
}
static T_5
int F_145 ( struct V_116 * V_117 ,
struct V_34 * V_35 ,
struct V_64 * V_65 ,
T_2 V_27 , T_2 V_36 , T_2 V_17 ,
T_2 V_152 , T_2 V_140 ,
T_2 V_33 , int V_165 ,
struct V_188 * V_136 )
{
struct V_171 * V_172 ;
int V_29 ;
V_29 = F_132 ( V_117 , V_35 , V_65 , & V_172 ,
V_27 , V_36 , V_17 ,
V_152 , V_140 , V_33 , 1 ) ;
if ( V_29 == 0 ) {
F_32 ( V_140 < V_149 ) ;
F_143 ( V_35 , V_65 , V_172 ,
V_165 , V_136 , NULL ) ;
} else if ( V_29 == - V_160 ) {
F_137 ( V_35 , V_65 , V_172 , V_17 ,
V_152 , V_140 , V_33 ,
V_165 , V_136 ) ;
V_29 = 0 ;
}
return V_29 ;
}
static int F_146 ( struct V_116 * V_117 ,
struct V_34 * V_35 ,
struct V_64 * V_65 ,
T_2 V_27 , T_2 V_17 , T_2 V_152 ,
T_2 V_140 , T_2 V_33 , int V_165 )
{
int V_29 ;
if ( V_140 < V_149 ) {
F_32 ( V_165 != 1 ) ;
V_29 = F_129 ( V_117 , V_35 , V_65 , V_27 ,
V_17 , V_152 ) ;
} else {
V_29 = F_113 ( V_117 , V_35 , V_65 , V_27 ,
V_17 , V_152 ,
V_140 , V_33 , V_165 ) ;
}
return V_29 ;
}
static int F_147 ( struct V_116 * V_117 ,
struct V_34 * V_35 ,
struct V_64 * V_65 ,
struct V_171 * V_172 ,
int V_167 , int V_192 , int * V_168 )
{
int V_29 = 0 ;
F_32 ( ! V_192 && V_167 != 1 ) ;
if ( V_172 ) {
F_143 ( V_35 , V_65 , V_172 ,
- V_167 , NULL , V_168 ) ;
} else if ( V_192 ) {
V_29 = F_122 ( V_117 , V_35 , V_65 , V_167 ,
V_168 ) ;
} else {
* V_168 = 1 ;
V_29 = F_124 ( V_117 , V_35 , V_65 ) ;
}
return V_29 ;
}
static int F_148 ( struct V_193 * V_194 , T_2 V_32 , T_2 V_47 ,
T_2 * V_195 )
{
int V_196 , V_29 = 0 ;
T_2 V_197 , V_31 ;
T_2 V_198 = F_149 ( V_32 , 1 << 9 ) ;
if ( F_8 ( V_32 != V_198 ) ) {
V_47 -= V_198 - V_32 ;
V_47 = F_150 ( V_47 , 1 << 9 ) ;
V_32 = V_198 ;
}
* V_195 = 0 ;
if ( ! V_47 )
return 0 ;
V_31 = V_32 + V_47 ;
V_197 = V_47 ;
for ( V_196 = 0 ; V_196 < V_46 ; V_196 ++ ) {
T_2 V_199 = F_22 ( V_196 ) ;
T_2 V_200 = V_199 + V_201 ;
T_2 V_59 = V_199 - V_32 ;
if ( ! F_151 ( V_199 , V_32 , V_197 ) &&
! F_151 ( V_200 , V_32 , V_197 ) &&
! F_151 ( V_32 , V_199 , V_201 ) )
continue;
if ( V_199 <= V_32 ) {
V_32 += V_200 - V_32 ;
if ( V_32 > V_31 ) {
V_197 = 0 ;
break;
}
V_197 = V_31 - V_32 ;
continue;
}
if ( V_59 ) {
V_29 = F_152 ( V_194 , V_32 >> 9 , V_59 >> 9 ,
V_97 , 0 ) ;
if ( ! V_29 )
* V_195 += V_59 ;
else if ( V_29 != - V_202 )
return V_29 ;
}
V_32 = V_200 ;
if ( V_32 > V_31 ) {
V_197 = 0 ;
break;
}
V_197 = V_31 - V_32 ;
}
if ( V_197 ) {
V_29 = F_152 ( V_194 , V_32 >> 9 , V_197 >> 9 ,
V_97 , 0 ) ;
if ( ! V_29 )
* V_195 += V_197 ;
}
return V_29 ;
}
int F_153 ( struct V_34 * V_35 , T_2 V_27 ,
T_2 V_36 , T_2 * V_203 )
{
int V_29 ;
T_2 V_195 = 0 ;
struct V_204 * V_205 = NULL ;
F_154 ( V_35 -> V_37 ) ;
V_29 = F_155 ( V_35 -> V_37 , V_206 ,
V_27 , & V_36 , & V_205 , 0 ) ;
if ( ! V_29 ) {
struct V_207 * V_208 = V_205 -> V_209 ;
int V_42 ;
for ( V_42 = 0 ; V_42 < V_205 -> V_210 ; V_42 ++ , V_208 ++ ) {
T_2 V_211 ;
if ( ! V_208 -> V_212 -> V_213 )
continue;
V_29 = F_148 ( V_208 -> V_212 -> V_194 ,
V_208 -> V_214 ,
V_208 -> V_215 ,
& V_211 ) ;
if ( ! V_29 )
V_195 += V_211 ;
else if ( V_29 != - V_202 )
break;
V_29 = 0 ;
}
F_156 ( V_205 ) ;
}
F_157 ( V_35 -> V_37 ) ;
if ( V_203 )
* V_203 = V_195 ;
if ( V_29 == - V_202 )
V_29 = 0 ;
return V_29 ;
}
int F_158 ( struct V_116 * V_117 ,
struct V_34 * V_35 ,
T_2 V_27 , T_2 V_36 , T_2 V_17 ,
T_2 V_152 , T_2 V_140 , T_2 V_33 )
{
int V_29 ;
struct V_12 * V_37 = V_35 -> V_37 ;
F_32 ( V_140 < V_149 &&
V_152 == V_216 ) ;
if ( V_140 < V_149 ) {
V_29 = F_159 ( V_37 , V_117 , V_27 ,
V_36 ,
V_17 , V_152 , ( int ) V_140 ,
V_217 , NULL ) ;
} else {
V_29 = F_160 ( V_37 , V_117 , V_27 ,
V_36 , V_17 , V_152 ,
V_140 , V_33 , 0 ,
V_217 , NULL ) ;
}
return V_29 ;
}
static int F_161 ( struct V_116 * V_117 ,
struct V_34 * V_35 ,
struct V_218 * V_135 ,
T_2 V_17 , T_2 V_152 ,
T_2 V_140 , T_2 V_33 , int V_165 ,
struct V_188 * V_136 )
{
struct V_12 * V_37 = V_35 -> V_37 ;
struct V_64 * V_65 ;
struct V_66 * V_67 ;
struct V_123 * V_95 ;
struct V_68 V_21 ;
T_2 V_27 = V_135 -> V_27 ;
T_2 V_36 = V_135 -> V_36 ;
T_2 V_119 ;
int V_29 ;
V_65 = F_34 () ;
if ( ! V_65 )
return - V_73 ;
V_65 -> V_76 = V_77 ;
V_65 -> V_219 = 1 ;
V_29 = F_145 ( V_117 , V_37 -> V_63 , V_65 ,
V_27 , V_36 , V_17 ,
V_152 , V_140 , V_33 ,
V_165 , V_136 ) ;
if ( ( V_29 < 0 && V_29 != - V_186 ) || ! V_29 )
goto V_80;
V_67 = V_65 -> V_81 [ 0 ] ;
F_41 ( V_67 , & V_21 , V_65 -> V_82 [ 0 ] ) ;
V_95 = F_86 ( V_67 , V_65 -> V_82 [ 0 ] , struct V_123 ) ;
V_119 = F_87 ( V_67 , V_95 ) ;
F_98 ( V_67 , V_95 , V_119 + V_165 ) ;
if ( V_136 )
F_138 ( V_136 , V_67 , V_95 ) ;
F_103 ( V_67 ) ;
F_45 ( V_65 ) ;
V_65 -> V_76 = V_77 ;
V_65 -> V_219 = 1 ;
V_29 = F_146 ( V_117 , V_35 -> V_37 -> V_63 ,
V_65 , V_27 , V_17 , V_152 ,
V_140 , V_33 , V_165 ) ;
if ( V_29 )
F_162 ( V_117 , V_29 ) ;
V_80:
F_53 ( V_65 ) ;
return V_29 ;
}
static int F_163 ( struct V_116 * V_117 ,
struct V_34 * V_35 ,
struct V_218 * V_135 ,
struct V_188 * V_136 ,
int V_220 )
{
int V_29 = 0 ;
struct V_221 * V_157 ;
struct V_68 V_222 ;
T_2 V_17 = 0 ;
T_2 V_223 = 0 ;
T_2 V_7 = 0 ;
V_222 . V_22 = V_135 -> V_27 ;
V_222 . V_33 = V_135 -> V_36 ;
V_222 . type = V_78 ;
V_157 = F_164 ( V_135 ) ;
F_165 ( V_35 -> V_37 , V_135 , V_157 , V_135 -> V_224 ) ;
if ( V_135 -> type == V_161 )
V_17 = V_157 -> V_17 ;
V_223 = V_157 -> V_35 ;
if ( V_135 -> V_224 == V_217 && V_220 ) {
if ( V_136 )
V_7 |= V_136 -> V_138 ;
V_29 = F_166 ( V_117 , V_35 ,
V_17 , V_223 , V_7 ,
V_157 -> V_22 , V_157 -> V_33 ,
& V_222 , V_135 -> V_139 ) ;
} else if ( V_135 -> V_224 == V_217 ) {
V_29 = F_161 ( V_117 , V_35 , V_135 , V_17 ,
V_223 , V_157 -> V_22 ,
V_157 -> V_33 , V_135 -> V_139 ,
V_136 ) ;
} else if ( V_135 -> V_224 == V_225 ) {
V_29 = F_167 ( V_117 , V_35 , V_135 , V_17 ,
V_223 , V_157 -> V_22 ,
V_157 -> V_33 , V_135 -> V_139 ,
V_136 ) ;
} else {
F_91 () ;
}
return V_29 ;
}
static void F_138 ( struct V_188 * V_136 ,
struct V_66 * V_67 ,
struct V_123 * V_124 )
{
T_2 V_7 = F_88 ( V_67 , V_124 ) ;
if ( V_136 -> V_137 ) {
V_7 |= V_136 -> V_138 ;
F_100 ( V_67 , V_124 , V_7 ) ;
}
if ( V_136 -> V_226 ) {
struct V_144 * V_145 ;
F_32 ( ! ( V_7 & V_150 ) ) ;
V_145 = (struct V_144 * ) ( V_124 + 1 ) ;
F_168 ( V_67 , V_145 , & V_136 -> V_21 ) ;
}
}
static int F_169 ( struct V_116 * V_117 ,
struct V_34 * V_35 ,
struct V_218 * V_135 ,
struct V_188 * V_136 )
{
struct V_68 V_21 ;
struct V_64 * V_65 ;
struct V_123 * V_124 ;
struct V_66 * V_67 ;
T_3 V_125 ;
int V_29 ;
int V_159 = 0 ;
int V_118 = ! V_136 -> V_192 ;
if ( V_117 -> V_227 )
return 0 ;
if ( V_118 && ! F_84 ( V_35 -> V_37 , V_128 ) )
V_118 = 0 ;
V_65 = F_34 () ;
if ( ! V_65 )
return - V_73 ;
V_21 . V_22 = V_135 -> V_27 ;
if ( V_118 ) {
V_21 . type = V_86 ;
V_21 . V_33 = V_136 -> V_175 ;
} else {
V_21 . type = V_78 ;
V_21 . V_33 = V_135 -> V_36 ;
}
V_163:
V_65 -> V_76 = V_77 ;
V_65 -> V_219 = 1 ;
V_29 = F_38 ( V_117 , V_35 -> V_37 -> V_63 , & V_21 ,
V_65 , 0 , 1 ) ;
if ( V_29 < 0 ) {
V_159 = V_29 ;
goto V_80;
}
if ( V_29 > 0 ) {
if ( V_118 ) {
if ( V_65 -> V_82 [ 0 ] > 0 ) {
V_65 -> V_82 [ 0 ] -- ;
F_41 ( V_65 -> V_81 [ 0 ] , & V_21 ,
V_65 -> V_82 [ 0 ] ) ;
if ( V_21 . V_22 == V_135 -> V_27 &&
V_21 . type == V_78 &&
V_21 . V_33 == V_135 -> V_36 )
V_29 = 0 ;
}
if ( V_29 > 0 ) {
F_45 ( V_65 ) ;
V_118 = 0 ;
V_21 . V_22 = V_135 -> V_27 ;
V_21 . V_33 = V_135 -> V_36 ;
V_21 . type = V_78 ;
goto V_163;
}
} else {
V_159 = - V_183 ;
goto V_80;
}
}
V_67 = V_65 -> V_81 [ 0 ] ;
V_125 = F_85 ( V_67 , V_65 -> V_82 [ 0 ] ) ;
#ifdef F_89
if ( V_125 < sizeof( * V_124 ) ) {
V_29 = F_95 ( V_117 , V_35 -> V_37 -> V_63 ,
V_65 , ( T_2 ) - 1 , 0 ) ;
if ( V_29 < 0 ) {
V_159 = V_29 ;
goto V_80;
}
V_67 = V_65 -> V_81 [ 0 ] ;
V_125 = F_85 ( V_67 , V_65 -> V_82 [ 0 ] ) ;
}
#endif
F_32 ( V_125 < sizeof( * V_124 ) ) ;
V_124 = F_86 ( V_67 , V_65 -> V_82 [ 0 ] , struct V_123 ) ;
F_138 ( V_136 , V_67 , V_124 ) ;
F_103 ( V_67 ) ;
V_80:
F_53 ( V_65 ) ;
return V_159 ;
}
static int F_170 ( struct V_116 * V_117 ,
struct V_34 * V_35 ,
struct V_218 * V_135 ,
struct V_188 * V_136 ,
int V_220 )
{
int V_29 = 0 ;
struct V_228 * V_157 ;
struct V_68 V_222 ;
T_2 V_17 = 0 ;
T_2 V_223 = 0 ;
bool V_181 = F_84 ( V_35 -> V_37 ,
V_128 ) ;
V_157 = F_171 ( V_135 ) ;
F_172 ( V_35 -> V_37 , V_135 , V_157 , V_135 -> V_224 ) ;
if ( V_135 -> type == V_173 )
V_17 = V_157 -> V_17 ;
V_223 = V_157 -> V_35 ;
V_222 . V_22 = V_135 -> V_27 ;
if ( V_181 ) {
V_222 . V_33 = V_157 -> V_175 ;
V_222 . type = V_86 ;
} else {
V_222 . V_33 = V_135 -> V_36 ;
V_222 . type = V_78 ;
}
if ( V_135 -> V_139 != 1 ) {
F_173 ( V_35 -> V_37 ,
L_1 ,
V_135 -> V_27 , V_135 -> V_139 , V_135 -> V_224 , V_223 ,
V_17 ) ;
return - V_183 ;
}
if ( V_135 -> V_224 == V_217 && V_220 ) {
F_32 ( ! V_136 || ! V_136 -> V_137 ) ;
V_29 = F_174 ( V_117 , V_35 ,
V_17 , V_223 ,
V_136 -> V_138 ,
& V_136 -> V_21 ,
V_157 -> V_175 , & V_222 ) ;
} else if ( V_135 -> V_224 == V_217 ) {
V_29 = F_161 ( V_117 , V_35 , V_135 ,
V_17 , V_223 ,
V_157 -> V_175 , 0 , 1 ,
V_136 ) ;
} else if ( V_135 -> V_224 == V_225 ) {
V_29 = F_167 ( V_117 , V_35 , V_135 ,
V_17 , V_223 ,
V_157 -> V_175 , 0 , 1 , V_136 ) ;
} else {
F_91 () ;
}
return V_29 ;
}
static int F_175 ( struct V_116 * V_117 ,
struct V_34 * V_35 ,
struct V_218 * V_135 ,
struct V_188 * V_136 ,
int V_220 )
{
int V_29 = 0 ;
if ( V_117 -> V_227 ) {
if ( V_220 )
F_176 ( V_35 , V_135 -> V_27 ,
V_135 -> V_36 , 1 ) ;
return 0 ;
}
if ( F_177 ( V_135 ) ) {
struct V_120 * V_112 ;
F_32 ( V_136 ) ;
V_112 = F_178 ( V_135 ) ;
F_179 ( V_35 -> V_37 , V_135 , V_112 ,
V_135 -> V_224 ) ;
if ( V_220 ) {
F_176 ( V_35 , V_135 -> V_27 ,
V_135 -> V_36 , 1 ) ;
if ( V_112 -> V_192 ) {
V_29 = F_180 ( V_117 , V_35 ,
V_135 -> V_27 ,
V_135 -> V_36 ) ;
}
}
F_181 ( V_35 -> V_37 ,
V_112 -> V_229 ,
V_112 -> V_230 ) ;
return V_29 ;
}
if ( V_135 -> type == V_174 ||
V_135 -> type == V_173 )
V_29 = F_170 ( V_117 , V_35 , V_135 , V_136 ,
V_220 ) ;
else if ( V_135 -> type == V_162 ||
V_135 -> type == V_161 )
V_29 = F_163 ( V_117 , V_35 , V_135 , V_136 ,
V_220 ) ;
else
F_91 () ;
return V_29 ;
}
static inline struct V_218 *
F_182 ( struct V_120 * V_112 )
{
struct V_218 * V_157 ;
if ( F_183 ( & V_112 -> V_231 ) )
return NULL ;
F_184 (ref, &head->ref_list, list) {
if ( V_157 -> V_224 == V_217 )
return V_157 ;
}
return F_185 ( V_112 -> V_231 . V_79 , struct V_218 ,
V_98 ) ;
}
static T_1 int F_186 ( struct V_116 * V_117 ,
struct V_34 * V_35 ,
unsigned long V_43 )
{
struct V_121 * V_122 ;
struct V_218 * V_157 ;
struct V_120 * V_232 = NULL ;
struct V_188 * V_136 ;
struct V_12 * V_37 = V_35 -> V_37 ;
T_6 V_32 = F_187 () ;
int V_29 ;
unsigned long V_8 = 0 ;
unsigned long V_233 = 0 ;
int V_234 = 0 ;
V_122 = & V_117 -> V_134 -> V_122 ;
while ( 1 ) {
if ( ! V_232 ) {
if ( V_8 >= V_43 )
break;
F_11 ( & V_122 -> V_50 ) ;
V_232 = F_188 ( V_117 ) ;
if ( ! V_232 ) {
F_13 ( & V_122 -> V_50 ) ;
break;
}
V_29 = F_189 ( V_117 , V_232 ) ;
F_13 ( & V_122 -> V_50 ) ;
if ( V_29 == - V_186 ) {
V_232 = NULL ;
V_8 ++ ;
continue;
}
}
F_11 ( & V_232 -> V_50 ) ;
F_190 ( V_117 , V_37 , V_122 ,
V_232 ) ;
V_157 = F_182 ( V_232 ) ;
if ( V_157 && V_157 -> V_235 &&
F_191 ( V_37 , V_122 , V_157 -> V_235 ) ) {
F_13 ( & V_232 -> V_50 ) ;
F_192 ( V_232 ) ;
F_11 ( & V_122 -> V_50 ) ;
V_232 -> V_236 = 0 ;
V_122 -> V_237 ++ ;
F_13 ( & V_122 -> V_50 ) ;
V_232 = NULL ;
F_48 () ;
V_8 ++ ;
continue;
}
V_234 = V_232 -> V_234 ;
V_232 -> V_234 = 0 ;
V_136 = V_232 -> V_136 ;
V_232 -> V_136 = NULL ;
if ( ! V_157 ) {
V_157 = & V_232 -> V_135 ;
if ( V_136 && V_234 ) {
F_193 ( V_136 ) ;
V_136 = NULL ;
}
if ( V_136 ) {
F_13 ( & V_232 -> V_50 ) ;
V_29 = F_169 ( V_117 , V_35 ,
V_157 , V_136 ) ;
F_193 ( V_136 ) ;
if ( V_29 ) {
if ( V_234 )
V_232 -> V_234 = 1 ;
V_232 -> V_236 = 0 ;
F_194 ( V_37 ,
L_2 ,
V_29 ) ;
F_192 ( V_232 ) ;
return V_29 ;
}
continue;
}
F_13 ( & V_232 -> V_50 ) ;
F_11 ( & V_122 -> V_50 ) ;
F_11 ( & V_232 -> V_50 ) ;
if ( ! F_183 ( & V_232 -> V_231 ) ||
V_232 -> V_136 ) {
F_13 ( & V_232 -> V_50 ) ;
F_13 ( & V_122 -> V_50 ) ;
continue;
}
V_157 -> V_238 = 0 ;
V_122 -> V_239 -- ;
F_195 ( & V_232 -> V_240 ,
& V_122 -> V_241 ) ;
F_13 ( & V_122 -> V_50 ) ;
} else {
V_233 ++ ;
V_157 -> V_238 = 0 ;
F_196 ( & V_157 -> V_98 ) ;
}
F_197 ( & V_122 -> V_242 ) ;
if ( ! F_177 ( V_157 ) ) {
switch ( V_157 -> V_224 ) {
case V_217 :
case V_243 :
V_232 -> V_135 . V_139 -= V_157 -> V_139 ;
break;
case V_225 :
V_232 -> V_135 . V_139 += V_157 -> V_139 ;
break;
default:
F_8 ( 1 ) ;
}
}
F_13 ( & V_232 -> V_50 ) ;
V_29 = F_175 ( V_117 , V_35 , V_157 , V_136 ,
V_234 ) ;
F_193 ( V_136 ) ;
if ( V_29 ) {
F_11 ( & V_122 -> V_50 ) ;
V_232 -> V_236 = 0 ;
V_122 -> V_237 ++ ;
F_13 ( & V_122 -> V_50 ) ;
F_192 ( V_232 ) ;
F_94 ( V_157 ) ;
F_194 ( V_37 , L_3 ,
V_29 ) ;
return V_29 ;
}
if ( F_177 ( V_157 ) ) {
if ( V_232 -> V_192 &&
V_232 -> V_244 < 0 ) {
F_11 ( & V_122 -> V_50 ) ;
V_122 -> V_245 -= V_157 -> V_36 ;
F_13 ( & V_122 -> V_50 ) ;
}
F_192 ( V_232 ) ;
V_232 = NULL ;
}
F_94 ( V_157 ) ;
V_8 ++ ;
F_48 () ;
}
if ( V_233 > 0 ) {
T_2 V_246 = F_198 ( F_199 ( F_187 () , V_32 ) ) ;
T_2 V_247 ;
F_11 ( & V_122 -> V_50 ) ;
V_247 = V_37 -> V_248 * 3 + V_246 ;
V_37 -> V_248 = V_247 >> 2 ;
F_13 ( & V_122 -> V_50 ) ;
}
return 0 ;
}
static T_2 F_200 ( struct V_249 * V_35 )
{
struct V_15 * V_30 = V_35 -> V_15 ;
struct V_218 * V_250 ;
int V_251 = 1 ;
T_2 V_252 ;
T_2 V_253 = 0 , V_70 = 0 ;
V_30 = F_201 ( V_35 ) ;
if ( V_30 ) {
V_250 = F_12 ( V_30 , struct V_218 , V_15 ) ;
V_253 = V_250 -> V_27 ;
}
V_30 = F_202 ( V_35 ) ;
if ( V_30 ) {
V_250 = F_12 ( V_30 , struct V_218 , V_15 ) ;
V_70 = V_250 -> V_27 ;
}
V_30 = V_35 -> V_15 ;
while ( V_30 ) {
V_250 = F_12 ( V_30 , struct V_218 , V_15 ) ;
F_8 ( ! V_250 -> V_238 ) ;
V_252 = V_250 -> V_27 ;
if ( V_251 )
V_30 = V_30 -> V_23 ;
else
V_30 = V_30 -> V_24 ;
V_251 = 1 - V_251 ;
}
return V_252 ;
}
static inline T_2 F_203 ( struct V_34 * V_35 , T_2 V_254 )
{
T_2 V_36 ;
V_36 = V_254 * ( sizeof( struct V_123 ) +
sizeof( struct V_171 ) ) ;
if ( ! F_84 ( V_35 -> V_37 , V_128 ) )
V_36 += V_254 * sizeof( struct V_144 ) ;
return F_204 ( V_36 , F_205 ( V_35 ) ) ;
}
T_2 F_206 ( struct V_34 * V_35 , T_2 V_255 )
{
T_2 V_256 ;
T_2 V_257 ;
T_2 V_258 ;
V_256 = F_207 ( V_35 ) ;
V_257 = F_208 ( V_256 ,
( T_2 ) F_209 ( V_35 -> V_37 -> V_259 ) ) ;
V_258 = F_208 ( V_255 , V_35 -> V_55 ) ;
V_258 += V_257 - 1 ;
V_258 = F_208 ( V_258 , V_257 ) ;
return V_258 ;
}
int F_210 ( struct V_116 * V_117 ,
struct V_34 * V_35 )
{
struct V_260 * V_261 ;
T_2 V_239 = V_117 -> V_134 -> V_122 . V_237 ;
T_2 V_255 = V_117 -> V_134 -> V_122 . V_245 ;
T_2 V_262 = V_117 -> V_134 -> V_262 ;
T_2 V_36 , V_263 ;
int V_29 = 0 ;
V_36 = F_211 ( V_35 , 1 ) ;
V_239 = F_203 ( V_35 , V_239 ) ;
if ( V_239 > 1 )
V_36 += ( V_239 - 1 ) * V_35 -> V_54 ;
V_36 <<= 1 ;
V_36 += F_206 ( V_35 , V_255 ) * V_35 -> V_54 ;
V_263 = F_211 ( V_35 ,
V_262 ) ;
V_261 = & V_35 -> V_37 -> V_264 ;
if ( V_261 -> V_94 -> V_115 ) {
V_263 <<= 1 ;
V_36 <<= 1 ;
}
F_11 ( & V_261 -> V_50 ) ;
if ( V_261 -> V_10 <= V_36 + V_263 )
V_29 = 1 ;
F_13 ( & V_261 -> V_50 ) ;
return V_29 ;
}
int F_212 ( struct V_116 * V_117 ,
struct V_34 * V_35 )
{
struct V_12 * V_37 = V_35 -> V_37 ;
T_2 V_242 =
F_213 ( & V_117 -> V_134 -> V_122 . V_242 ) ;
T_2 V_265 ;
T_2 V_266 ;
F_2 () ;
V_265 = V_37 -> V_248 ;
V_266 = V_242 * V_265 ;
if ( V_242 * V_265 >= V_267 )
return 1 ;
if ( V_266 >= V_267 / 2 )
return 2 ;
return F_210 ( V_117 , V_35 ) ;
}
static void F_214 ( struct V_90 * V_91 )
{
struct V_268 * V_269 ;
struct V_116 * V_117 ;
int V_29 ;
V_269 = F_55 ( V_91 , struct V_268 , V_91 ) ;
if ( F_215 ( V_269 -> V_35 -> V_37 ) )
goto V_270;
V_117 = F_216 ( V_269 -> V_35 ) ;
if ( F_217 ( V_117 ) ) {
V_269 -> error = F_218 ( V_117 ) ;
goto V_270;
}
V_117 -> V_271 = true ;
if ( V_117 -> V_272 > V_269 -> V_272 )
goto V_31;
V_29 = F_219 ( V_117 , V_269 -> V_35 , V_269 -> V_8 ) ;
if ( V_29 )
V_269 -> error = V_29 ;
V_31:
V_29 = F_220 ( V_117 , V_269 -> V_35 ) ;
if ( V_29 && ! V_269 -> error )
V_269 -> error = V_29 ;
V_270:
if ( V_269 -> V_271 )
F_221 ( & V_269 -> V_89 ) ;
else
F_9 ( V_269 ) ;
}
int F_222 ( struct V_34 * V_35 ,
unsigned long V_8 , T_2 V_272 , int V_89 )
{
struct V_268 * V_269 ;
int V_29 ;
V_269 = F_223 ( sizeof( * V_269 ) , V_97 ) ;
if ( ! V_269 )
return - V_73 ;
V_269 -> V_35 = V_35 -> V_37 -> V_87 ;
V_269 -> V_8 = V_8 ;
V_269 -> error = 0 ;
V_269 -> V_272 = V_272 ;
if ( V_89 )
V_269 -> V_271 = 1 ;
else
V_269 -> V_271 = 0 ;
F_224 ( & V_269 -> V_89 ) ;
F_66 ( & V_269 -> V_91 , V_273 ,
F_214 , NULL , NULL ) ;
F_74 ( V_35 -> V_37 -> V_274 , & V_269 -> V_91 ) ;
if ( V_89 ) {
F_225 ( & V_269 -> V_89 ) ;
V_29 = V_269 -> error ;
F_9 ( V_269 ) ;
return V_29 ;
}
return 0 ;
}
int F_219 ( struct V_116 * V_117 ,
struct V_34 * V_35 , unsigned long V_8 )
{
struct V_15 * V_135 ;
struct V_121 * V_122 ;
struct V_120 * V_112 ;
int V_29 ;
int V_275 = V_8 == ( unsigned long ) - 1 ;
bool V_276 = V_117 -> V_276 ;
if ( V_117 -> V_227 )
return 0 ;
if ( F_226 ( V_277 , & V_35 -> V_37 -> V_7 ) )
return 0 ;
if ( V_35 == V_35 -> V_37 -> V_63 )
V_35 = V_35 -> V_37 -> V_87 ;
V_122 = & V_117 -> V_134 -> V_122 ;
if ( V_8 == 0 )
V_8 = F_213 ( & V_122 -> V_242 ) * 2 ;
V_163:
#ifdef F_227
V_122 -> V_278 = F_200 ( & V_122 -> V_35 ) ;
#endif
V_117 -> V_276 = false ;
V_29 = F_186 ( V_117 , V_35 , V_8 ) ;
if ( V_29 < 0 ) {
F_162 ( V_117 , V_29 ) ;
return V_29 ;
}
if ( V_275 ) {
if ( ! F_183 ( & V_117 -> V_279 ) )
F_228 ( V_117 , V_35 ) ;
F_11 ( & V_122 -> V_50 ) ;
V_135 = F_201 ( & V_122 -> V_241 ) ;
if ( ! V_135 ) {
F_13 ( & V_122 -> V_50 ) ;
goto V_80;
}
while ( V_135 ) {
V_112 = F_12 ( V_135 , struct V_120 ,
V_240 ) ;
if ( F_177 ( & V_112 -> V_135 ) ) {
struct V_218 * V_157 ;
V_157 = & V_112 -> V_135 ;
F_5 ( & V_157 -> V_119 ) ;
F_13 ( & V_122 -> V_50 ) ;
F_49 ( & V_112 -> V_85 ) ;
F_47 ( & V_112 -> V_85 ) ;
F_94 ( V_157 ) ;
F_48 () ;
goto V_163;
} else {
F_8 ( 1 ) ;
}
V_135 = F_229 ( V_135 ) ;
}
F_13 ( & V_122 -> V_50 ) ;
F_48 () ;
goto V_163;
}
V_80:
F_230 ( V_117 ) ;
V_117 -> V_276 = V_276 ;
return 0 ;
}
int F_231 ( struct V_116 * V_117 ,
struct V_34 * V_35 ,
T_2 V_27 , T_2 V_36 , T_2 V_7 ,
int V_175 , int V_192 )
{
struct V_188 * V_136 ;
int V_29 ;
V_136 = F_232 () ;
if ( ! V_136 )
return - V_73 ;
V_136 -> V_138 = V_7 ;
V_136 -> V_137 = true ;
V_136 -> V_226 = false ;
V_136 -> V_192 = V_192 ? true : false ;
V_136 -> V_175 = V_175 ;
V_29 = F_233 ( V_35 -> V_37 , V_117 , V_27 ,
V_36 , V_136 ) ;
if ( V_29 )
F_193 ( V_136 ) ;
return V_29 ;
}
static T_1 int F_234 ( struct V_116 * V_117 ,
struct V_34 * V_35 ,
struct V_64 * V_65 ,
T_2 V_22 , T_2 V_33 , T_2 V_27 )
{
struct V_120 * V_112 ;
struct V_218 * V_157 ;
struct V_221 * V_280 ;
struct V_121 * V_122 ;
int V_29 = 0 ;
V_122 = & V_117 -> V_134 -> V_122 ;
F_11 ( & V_122 -> V_50 ) ;
V_112 = F_92 ( V_117 , V_27 ) ;
if ( ! V_112 ) {
F_13 ( & V_122 -> V_50 ) ;
return 0 ;
}
if ( ! F_93 ( & V_112 -> V_85 ) ) {
F_5 ( & V_112 -> V_135 . V_119 ) ;
F_13 ( & V_122 -> V_50 ) ;
F_45 ( V_65 ) ;
F_49 ( & V_112 -> V_85 ) ;
F_47 ( & V_112 -> V_85 ) ;
F_94 ( & V_112 -> V_135 ) ;
return - V_186 ;
}
F_13 ( & V_122 -> V_50 ) ;
F_11 ( & V_112 -> V_50 ) ;
F_184 (ref, &head->ref_list, list) {
if ( V_157 -> type != V_162 ) {
V_29 = 1 ;
break;
}
V_280 = F_164 ( V_157 ) ;
if ( V_280 -> V_35 != V_35 -> V_281 . V_22 ||
V_280 -> V_22 != V_22 ||
V_280 -> V_33 != V_33 ) {
V_29 = 1 ;
break;
}
}
F_13 ( & V_112 -> V_50 ) ;
F_47 ( & V_112 -> V_85 ) ;
return V_29 ;
}
static T_1 int F_235 ( struct V_116 * V_117 ,
struct V_34 * V_35 ,
struct V_64 * V_65 ,
T_2 V_22 , T_2 V_33 , T_2 V_27 )
{
struct V_34 * V_63 = V_35 -> V_37 -> V_63 ;
struct V_66 * V_67 ;
struct V_156 * V_157 ;
struct V_171 * V_172 ;
struct V_123 * V_124 ;
struct V_68 V_21 ;
T_3 V_125 ;
int V_29 ;
V_21 . V_22 = V_27 ;
V_21 . V_33 = ( T_2 ) - 1 ;
V_21 . type = V_78 ;
V_29 = F_38 ( NULL , V_63 , & V_21 , V_65 , 0 , 0 ) ;
if ( V_29 < 0 )
goto V_80;
F_32 ( V_29 == 0 ) ;
V_29 = - V_160 ;
if ( V_65 -> V_82 [ 0 ] == 0 )
goto V_80;
V_65 -> V_82 [ 0 ] -- ;
V_67 = V_65 -> V_81 [ 0 ] ;
F_41 ( V_67 , & V_21 , V_65 -> V_82 [ 0 ] ) ;
if ( V_21 . V_22 != V_27 || V_21 . type != V_78 )
goto V_80;
V_29 = 1 ;
V_125 = F_85 ( V_67 , V_65 -> V_82 [ 0 ] ) ;
#ifdef F_89
if ( V_125 < sizeof( * V_124 ) ) {
F_8 ( V_125 != sizeof( struct V_131 ) ) ;
goto V_80;
}
#endif
V_124 = F_86 ( V_67 , V_65 -> V_82 [ 0 ] , struct V_123 ) ;
if ( V_125 != sizeof( * V_124 ) +
F_133 ( V_162 ) )
goto V_80;
if ( F_236 ( V_67 , V_124 ) <=
F_237 ( & V_35 -> V_282 ) )
goto V_80;
V_172 = (struct V_171 * ) ( V_124 + 1 ) ;
if ( F_127 ( V_67 , V_172 ) !=
V_162 )
goto V_80;
V_157 = (struct V_156 * ) ( & V_172 -> V_33 ) ;
if ( F_87 ( V_67 , V_124 ) !=
F_121 ( V_67 , V_157 ) ||
F_108 ( V_67 , V_157 ) !=
V_35 -> V_281 . V_22 ||
F_109 ( V_67 , V_157 ) != V_22 ||
F_110 ( V_67 , V_157 ) != V_33 )
goto V_80;
V_29 = 0 ;
V_80:
return V_29 ;
}
int F_238 ( struct V_116 * V_117 ,
struct V_34 * V_35 ,
T_2 V_22 , T_2 V_33 , T_2 V_27 )
{
struct V_64 * V_65 ;
int V_29 ;
int V_283 ;
V_65 = F_34 () ;
if ( ! V_65 )
return - V_160 ;
do {
V_29 = F_235 ( V_117 , V_35 , V_65 , V_22 ,
V_33 , V_27 ) ;
if ( V_29 && V_29 != - V_160 )
goto V_80;
V_283 = F_234 ( V_117 , V_35 , V_65 , V_22 ,
V_33 , V_27 ) ;
} while ( V_283 == - V_186 );
if ( V_283 && V_283 != - V_160 ) {
V_29 = V_283 ;
goto V_80;
}
if ( V_29 != - V_160 || V_283 != - V_160 )
V_29 = 0 ;
V_80:
F_53 ( V_65 ) ;
if ( V_35 -> V_281 . V_22 == V_284 )
F_8 ( V_29 > 0 ) ;
return V_29 ;
}
static int F_239 ( struct V_116 * V_117 ,
struct V_34 * V_35 ,
struct V_66 * V_285 ,
int V_286 , int V_287 )
{
T_2 V_27 ;
T_2 V_36 ;
T_2 V_17 ;
T_2 V_223 ;
T_3 V_71 ;
struct V_68 V_21 ;
struct V_288 * V_289 ;
int V_42 ;
int V_175 ;
int V_29 = 0 ;
int (* F_240)( struct V_116 * , struct V_34 * ,
T_2 , T_2 , T_2 , T_2 , T_2 , T_2 );
if ( F_241 ( V_35 -> V_37 ) )
return 0 ;
V_223 = F_242 ( V_285 ) ;
V_71 = F_39 ( V_285 ) ;
V_175 = F_243 ( V_285 ) ;
if ( ! F_226 ( V_290 , & V_35 -> V_291 ) && V_175 == 0 )
return 0 ;
if ( V_287 )
F_240 = F_158 ;
else
F_240 = V_292 ;
if ( V_286 )
V_17 = V_285 -> V_32 ;
else
V_17 = 0 ;
for ( V_42 = 0 ; V_42 < V_71 ; V_42 ++ ) {
if ( V_175 == 0 ) {
F_41 ( V_285 , & V_21 , V_42 ) ;
if ( V_21 . type != V_293 )
continue;
V_289 = F_86 ( V_285 , V_42 ,
struct V_288 ) ;
if ( F_244 ( V_285 , V_289 ) ==
V_294 )
continue;
V_27 = F_245 ( V_285 , V_289 ) ;
if ( V_27 == 0 )
continue;
V_36 = F_246 ( V_285 , V_289 ) ;
V_21 . V_33 -= F_247 ( V_285 , V_289 ) ;
V_29 = F_240 ( V_117 , V_35 , V_27 , V_36 ,
V_17 , V_223 , V_21 . V_22 ,
V_21 . V_33 ) ;
if ( V_29 )
goto V_164;
} else {
V_27 = F_248 ( V_285 , V_42 ) ;
V_36 = V_35 -> V_54 ;
V_29 = F_240 ( V_117 , V_35 , V_27 , V_36 ,
V_17 , V_223 , V_175 - 1 , 0 ) ;
if ( V_29 )
goto V_164;
}
}
return 0 ;
V_164:
return V_29 ;
}
int F_249 ( struct V_116 * V_117 , struct V_34 * V_35 ,
struct V_66 * V_285 , int V_286 )
{
return F_239 ( V_117 , V_35 , V_285 , V_286 , 1 ) ;
}
int F_250 ( struct V_116 * V_117 , struct V_34 * V_35 ,
struct V_66 * V_285 , int V_286 )
{
return F_239 ( V_117 , V_35 , V_285 , V_286 , 0 ) ;
}
static int F_251 ( struct V_116 * V_117 ,
struct V_34 * V_35 ,
struct V_64 * V_65 ,
struct V_1 * V_2 )
{
int V_29 ;
struct V_34 * V_63 = V_35 -> V_37 -> V_63 ;
unsigned long V_145 ;
struct V_66 * V_67 ;
V_29 = F_38 ( V_117 , V_63 , & V_2 -> V_21 , V_65 , 0 , 1 ) ;
if ( V_29 ) {
if ( V_29 > 0 )
V_29 = - V_160 ;
goto V_164;
}
V_67 = V_65 -> V_81 [ 0 ] ;
V_145 = F_252 ( V_67 , V_65 -> V_82 [ 0 ] ) ;
F_253 ( V_67 , & V_2 -> V_95 , V_145 , sizeof( V_2 -> V_95 ) ) ;
F_103 ( V_67 ) ;
V_164:
F_45 ( V_65 ) ;
return V_29 ;
}
static struct V_1 *
F_254 ( struct V_34 * V_35 ,
struct V_1 * V_2 )
{
struct V_15 * V_135 ;
F_11 ( & V_35 -> V_37 -> V_18 ) ;
if ( F_255 ( & V_2 -> V_20 ) ) {
const T_2 V_295 = V_2 -> V_21 . V_22 + V_2 -> V_21 . V_33 ;
F_13 ( & V_35 -> V_37 -> V_18 ) ;
F_6 ( V_2 ) ;
V_2 = F_75 ( V_35 -> V_37 ,
V_295 ) ;
return V_2 ;
}
V_135 = F_229 ( & V_2 -> V_20 ) ;
F_6 ( V_2 ) ;
if ( V_135 ) {
V_2 = F_12 ( V_135 , struct V_1 ,
V_20 ) ;
F_4 ( V_2 ) ;
} else
V_2 = NULL ;
F_13 ( & V_35 -> V_37 -> V_18 ) ;
return V_2 ;
}
static int F_256 ( struct V_1 * V_14 ,
struct V_116 * V_117 ,
struct V_64 * V_65 )
{
struct V_34 * V_35 = V_14 -> V_37 -> V_87 ;
struct V_296 * V_296 = NULL ;
T_2 V_297 = 0 ;
int V_298 = V_299 ;
T_2 V_300 = 0 ;
int V_301 = 0 ;
int V_29 = 0 ;
if ( V_14 -> V_21 . V_33 < ( 100 * V_302 ) ) {
F_11 ( & V_14 -> V_50 ) ;
V_14 -> V_303 = V_304 ;
F_13 ( & V_14 -> V_50 ) ;
return 0 ;
}
if ( V_117 -> V_227 )
return 0 ;
V_163:
V_296 = F_257 ( V_35 , V_14 , V_65 ) ;
if ( F_217 ( V_296 ) && F_218 ( V_296 ) != - V_160 ) {
V_29 = F_218 ( V_296 ) ;
F_45 ( V_65 ) ;
goto V_80;
}
if ( F_217 ( V_296 ) ) {
F_32 ( V_301 ) ;
V_301 ++ ;
if ( V_14 -> V_305 )
goto V_130;
V_29 = F_258 ( V_35 , V_117 , V_14 , V_65 ) ;
if ( V_29 )
goto V_130;
goto V_163;
}
if ( V_14 -> V_306 == V_117 -> V_272 &&
F_259 ( V_296 ) ) {
V_298 = V_307 ;
goto V_308;
}
F_260 ( V_296 ) -> V_309 = 0 ;
V_29 = F_261 ( V_117 , V_35 , V_296 ) ;
if ( V_29 ) {
F_162 ( V_117 , V_29 ) ;
goto V_308;
}
F_8 ( V_29 ) ;
if ( F_259 ( V_296 ) > 0 ) {
V_29 = F_262 ( V_35 ,
& V_35 -> V_37 -> V_264 ) ;
if ( V_29 )
goto V_308;
V_29 = F_263 ( V_35 , V_117 , NULL , V_296 ) ;
if ( V_29 )
goto V_308;
}
F_11 ( & V_14 -> V_50 ) ;
if ( V_14 -> V_3 != V_4 ||
! F_264 ( V_35 -> V_37 , V_310 ) ) {
V_298 = V_304 ;
F_13 ( & V_14 -> V_50 ) ;
goto V_308;
}
F_13 ( & V_14 -> V_50 ) ;
if ( F_226 ( V_311 , & V_117 -> V_134 -> V_7 ) ) {
V_29 = - V_312 ;
goto V_308;
}
V_300 = F_204 ( V_14 -> V_21 . V_33 , V_313 ) ;
if ( ! V_300 )
V_300 = 1 ;
V_300 *= 16 ;
V_300 *= V_314 ;
V_29 = F_265 ( V_296 , 0 , V_300 ) ;
if ( V_29 )
goto V_308;
V_29 = F_266 ( V_296 , V_117 , 0 , 0 , V_300 ,
V_300 , V_300 ,
& V_297 ) ;
if ( ! V_29 )
V_298 = V_307 ;
else if ( V_29 == - V_312 )
F_267 ( V_311 , & V_117 -> V_134 -> V_7 ) ;
V_308:
F_268 ( V_296 ) ;
V_130:
F_45 ( V_65 ) ;
V_80:
F_11 ( & V_14 -> V_50 ) ;
if ( ! V_29 && V_298 == V_307 )
V_14 -> V_306 = V_117 -> V_272 ;
V_14 -> V_303 = V_298 ;
F_13 ( & V_14 -> V_50 ) ;
return V_29 ;
}
int F_269 ( struct V_116 * V_117 ,
struct V_34 * V_35 )
{
struct V_1 * V_2 , * V_315 ;
struct V_316 * V_317 = V_117 -> V_134 ;
struct V_64 * V_65 ;
if ( F_183 ( & V_317 -> V_318 ) ||
! F_264 ( V_35 -> V_37 , V_310 ) )
return 0 ;
V_65 = F_34 () ;
if ( ! V_65 )
return - V_73 ;
F_270 (cache, tmp, &cur_trans->dirty_bgs,
dirty_list) {
if ( V_2 -> V_303 == V_319 )
F_256 ( V_2 , V_117 , V_65 ) ;
}
F_53 ( V_65 ) ;
return 0 ;
}
int F_271 ( struct V_116 * V_117 ,
struct V_34 * V_35 )
{
struct V_1 * V_2 ;
struct V_316 * V_317 = V_117 -> V_134 ;
int V_29 = 0 ;
int V_320 ;
struct V_64 * V_65 = NULL ;
F_272 ( V_321 ) ;
struct V_111 * V_322 = & V_317 -> V_323 ;
int V_324 = 0 ;
int V_325 = 0 ;
F_11 ( & V_317 -> V_326 ) ;
if ( F_183 ( & V_317 -> V_318 ) ) {
F_13 ( & V_317 -> V_326 ) ;
return 0 ;
}
F_273 ( & V_317 -> V_318 , & V_321 ) ;
F_13 ( & V_317 -> V_326 ) ;
V_163:
F_228 ( V_117 , V_35 ) ;
if ( ! V_65 ) {
V_65 = F_34 () ;
if ( ! V_65 )
return - V_73 ;
}
F_49 ( & V_117 -> V_134 -> V_327 ) ;
while ( ! F_183 ( & V_321 ) ) {
V_2 = F_274 ( & V_321 ,
struct V_1 ,
V_328 ) ;
if ( ! F_183 ( & V_2 -> V_329 ) ) {
F_275 ( & V_2 -> V_329 ) ;
F_276 ( V_35 , V_117 , V_2 ,
& V_2 -> V_330 , V_65 ,
V_2 -> V_21 . V_22 ) ;
F_6 ( V_2 ) ;
}
F_11 ( & V_317 -> V_326 ) ;
F_275 ( & V_2 -> V_328 ) ;
F_13 ( & V_317 -> V_326 ) ;
V_320 = 1 ;
F_256 ( V_2 , V_117 , V_65 ) ;
if ( V_2 -> V_303 == V_307 ) {
V_2 -> V_330 . V_296 = NULL ;
V_29 = F_277 ( V_35 , V_117 , V_2 , V_65 ) ;
if ( V_29 == 0 && V_2 -> V_330 . V_296 ) {
V_324 ++ ;
V_320 = 0 ;
F_72 ( & V_2 -> V_329 , V_322 ) ;
} else {
V_29 = 0 ;
}
}
if ( ! V_29 ) {
V_29 = F_251 ( V_117 , V_35 , V_65 , V_2 ) ;
if ( V_29 == - V_160 ) {
V_29 = 0 ;
F_11 ( & V_317 -> V_326 ) ;
if ( F_183 ( & V_2 -> V_328 ) ) {
F_72 ( & V_2 -> V_328 ,
& V_317 -> V_318 ) ;
F_4 ( V_2 ) ;
}
F_13 ( & V_317 -> V_326 ) ;
} else if ( V_29 ) {
F_162 ( V_117 , V_29 ) ;
}
}
if ( V_320 )
F_6 ( V_2 ) ;
if ( V_29 )
break;
F_47 ( & V_117 -> V_134 -> V_327 ) ;
F_49 ( & V_117 -> V_134 -> V_327 ) ;
}
F_47 ( & V_117 -> V_134 -> V_327 ) ;
V_29 = F_219 ( V_117 , V_35 , 0 ) ;
if ( ! V_29 && V_325 == 0 ) {
V_325 ++ ;
F_11 ( & V_317 -> V_326 ) ;
F_273 ( & V_317 -> V_318 , & V_321 ) ;
if ( ! F_183 ( & V_321 ) ) {
F_13 ( & V_317 -> V_326 ) ;
goto V_163;
}
F_13 ( & V_317 -> V_326 ) ;
} else if ( V_29 < 0 ) {
F_278 ( V_317 , V_35 ) ;
}
F_53 ( V_65 ) ;
return V_29 ;
}
int F_279 ( struct V_116 * V_117 ,
struct V_34 * V_35 )
{
struct V_1 * V_2 ;
struct V_316 * V_317 = V_117 -> V_134 ;
int V_29 = 0 ;
int V_320 ;
struct V_64 * V_65 ;
struct V_111 * V_322 = & V_317 -> V_323 ;
int V_324 = 0 ;
V_65 = F_34 () ;
if ( ! V_65 )
return - V_73 ;
F_11 ( & V_317 -> V_326 ) ;
while ( ! F_183 ( & V_317 -> V_318 ) ) {
V_2 = F_274 ( & V_317 -> V_318 ,
struct V_1 ,
V_328 ) ;
if ( ! F_183 ( & V_2 -> V_329 ) ) {
F_13 ( & V_317 -> V_326 ) ;
F_275 ( & V_2 -> V_329 ) ;
F_276 ( V_35 , V_117 , V_2 ,
& V_2 -> V_330 , V_65 ,
V_2 -> V_21 . V_22 ) ;
F_6 ( V_2 ) ;
F_11 ( & V_317 -> V_326 ) ;
}
F_275 ( & V_2 -> V_328 ) ;
F_13 ( & V_317 -> V_326 ) ;
V_320 = 1 ;
F_256 ( V_2 , V_117 , V_65 ) ;
if ( ! V_29 )
V_29 = F_219 ( V_117 , V_35 , ( unsigned long ) - 1 ) ;
if ( ! V_29 && V_2 -> V_303 == V_307 ) {
V_2 -> V_330 . V_296 = NULL ;
V_29 = F_277 ( V_35 , V_117 , V_2 , V_65 ) ;
if ( V_29 == 0 && V_2 -> V_330 . V_296 ) {
V_324 ++ ;
V_320 = 0 ;
F_72 ( & V_2 -> V_329 , V_322 ) ;
} else {
V_29 = 0 ;
}
}
if ( ! V_29 ) {
V_29 = F_251 ( V_117 , V_35 , V_65 , V_2 ) ;
if ( V_29 == - V_160 ) {
F_280 ( V_317 -> V_331 ,
F_213 ( & V_317 -> V_332 ) == 1 ) ;
V_29 = F_251 ( V_117 , V_35 , V_65 ,
V_2 ) ;
}
if ( V_29 )
F_162 ( V_117 , V_29 ) ;
}
if ( V_320 )
F_6 ( V_2 ) ;
F_11 ( & V_317 -> V_326 ) ;
}
F_13 ( & V_317 -> V_326 ) ;
while ( ! F_183 ( V_322 ) ) {
V_2 = F_274 ( V_322 , struct V_1 ,
V_329 ) ;
F_275 ( & V_2 -> V_329 ) ;
F_276 ( V_35 , V_117 , V_2 ,
& V_2 -> V_330 , V_65 , V_2 -> V_21 . V_22 ) ;
F_6 ( V_2 ) ;
}
F_53 ( V_65 ) ;
return V_29 ;
}
int F_281 ( struct V_34 * V_35 , T_2 V_27 )
{
struct V_1 * V_14 ;
int V_333 = 0 ;
V_14 = F_76 ( V_35 -> V_37 , V_27 ) ;
if ( ! V_14 || V_14 -> V_305 )
V_333 = 1 ;
if ( V_14 )
F_6 ( V_14 ) ;
return V_333 ;
}
bool F_282 ( struct V_12 * V_37 , T_2 V_27 )
{
struct V_1 * V_334 ;
bool V_29 = true ;
V_334 = F_76 ( V_37 , V_27 ) ;
if ( ! V_334 )
return false ;
F_11 ( & V_334 -> V_50 ) ;
if ( V_334 -> V_305 )
V_29 = false ;
else
F_5 ( & V_334 -> V_335 ) ;
F_13 ( & V_334 -> V_50 ) ;
if ( ! V_29 )
F_6 ( V_334 ) ;
return V_29 ;
}
void F_283 ( struct V_12 * V_37 , T_2 V_27 )
{
struct V_1 * V_334 ;
V_334 = F_76 ( V_37 , V_27 ) ;
ASSERT ( V_334 ) ;
if ( F_7 ( & V_334 -> V_335 ) )
F_284 ( & V_334 -> V_335 ) ;
F_6 ( V_334 ) ;
F_6 ( V_334 ) ;
}
static int F_285 ( T_7 * V_336 )
{
F_68 () ;
return 0 ;
}
void F_286 ( struct V_1 * V_334 )
{
F_287 ( & V_334 -> V_335 ,
F_285 ,
V_101 ) ;
}
static const char * F_288 ( T_2 V_7 )
{
switch ( V_7 ) {
case V_53 | V_337 :
return L_4 ;
case V_53 :
return L_5 ;
case V_337 :
return L_6 ;
case V_338 :
return L_7 ;
default:
F_8 ( 1 ) ;
return L_8 ;
} ;
}
static int F_289 ( struct V_12 * V_13 , T_2 V_7 ,
T_2 V_339 , T_2 V_93 ,
T_2 V_340 ,
struct V_110 * * V_94 )
{
struct V_110 * V_113 ;
int V_42 ;
int V_341 ;
int V_29 ;
if ( V_7 & ( V_342 | V_343 |
V_344 ) )
V_341 = 2 ;
else
V_341 = 1 ;
V_113 = F_77 ( V_13 , V_7 ) ;
if ( V_113 ) {
F_11 ( & V_113 -> V_50 ) ;
V_113 -> V_339 += V_339 ;
V_113 -> V_345 += V_339 * V_341 ;
V_113 -> V_93 += V_93 ;
V_113 -> V_346 += V_93 * V_341 ;
V_113 -> V_340 += V_340 ;
if ( V_339 > 0 )
V_113 -> V_115 = 0 ;
F_290 ( V_13 , V_113 , V_339 -
V_93 - V_340 ) ;
F_13 ( & V_113 -> V_50 ) ;
* V_94 = V_113 ;
return 0 ;
}
V_113 = F_61 ( sizeof( * V_113 ) , V_97 ) ;
if ( ! V_113 )
return - V_73 ;
V_29 = F_291 ( & V_113 -> V_347 , 0 , V_348 ) ;
if ( V_29 ) {
F_9 ( V_113 ) ;
return V_29 ;
}
for ( V_42 = 0 ; V_42 < V_349 ; V_42 ++ )
F_62 ( & V_113 -> V_350 [ V_42 ] ) ;
F_292 ( & V_113 -> V_351 ) ;
F_293 ( & V_113 -> V_50 ) ;
V_113 -> V_7 = V_7 & V_114 ;
V_113 -> V_339 = V_339 ;
V_113 -> V_345 = V_339 * V_341 ;
V_113 -> V_93 = V_93 ;
V_113 -> V_346 = V_93 * V_341 ;
V_113 -> V_352 = 0 ;
V_113 -> V_353 = 0 ;
V_113 -> V_340 = V_340 ;
V_113 -> V_354 = 0 ;
V_113 -> V_115 = 0 ;
V_113 -> V_355 = 0 ;
V_113 -> V_356 = V_357 ;
V_113 -> V_358 = 0 ;
V_113 -> V_359 = 0 ;
F_64 ( & V_113 -> V_89 ) ;
F_62 ( & V_113 -> V_360 ) ;
F_62 ( & V_113 -> V_361 ) ;
F_62 ( & V_113 -> V_362 ) ;
V_29 = F_294 ( & V_113 -> V_363 , & V_364 ,
V_13 -> V_365 , L_9 ,
F_288 ( V_113 -> V_7 ) ) ;
if ( V_29 ) {
F_9 ( V_113 ) ;
return V_29 ;
}
* V_94 = V_113 ;
F_295 ( & V_113 -> V_98 , & V_13 -> V_94 ) ;
if ( V_7 & V_337 )
V_13 -> V_366 = V_113 ;
return V_29 ;
}
static void F_296 ( struct V_12 * V_37 , T_2 V_7 )
{
T_2 V_367 = F_297 ( V_7 ) &
V_368 ;
F_298 ( & V_37 -> V_369 ) ;
if ( V_7 & V_337 )
V_37 -> V_370 |= V_367 ;
if ( V_7 & V_53 )
V_37 -> V_371 |= V_367 ;
if ( V_7 & V_338 )
V_37 -> V_372 |= V_367 ;
F_299 ( & V_37 -> V_369 ) ;
}
static T_2 F_300 ( struct V_12 * V_37 , T_2 V_7 )
{
struct V_373 * V_374 = V_37 -> V_375 ;
T_2 V_376 = 0 ;
if ( ! V_374 )
return 0 ;
if ( V_7 & V_337 &&
V_374 -> V_377 . V_7 & V_378 ) {
V_376 = V_337 | V_374 -> V_377 . V_376 ;
} else if ( V_7 & V_338 &&
V_374 -> V_379 . V_7 & V_378 ) {
V_376 = V_338 | V_374 -> V_379 . V_376 ;
} else if ( V_7 & V_53 &&
V_374 -> V_380 . V_7 & V_378 ) {
V_376 = V_53 | V_374 -> V_380 . V_376 ;
}
return V_376 ;
}
static T_2 F_301 ( struct V_34 * V_35 , T_2 V_7 )
{
T_2 V_381 = V_35 -> V_37 -> V_382 -> V_383 ;
T_2 V_376 ;
T_2 V_384 ;
T_2 V_385 = 0 ;
F_11 ( & V_35 -> V_37 -> V_386 ) ;
V_376 = F_300 ( V_35 -> V_37 , V_7 ) ;
if ( V_376 ) {
if ( ( V_7 & V_376 ) & V_368 ) {
F_13 ( & V_35 -> V_37 -> V_386 ) ;
return F_302 ( V_376 ) ;
}
}
F_13 ( & V_35 -> V_37 -> V_386 ) ;
for ( V_384 = 0 ; V_384 < V_349 ; V_384 ++ ) {
if ( V_381 >= V_387 [ V_384 ] . V_388 )
V_385 |= V_389 [ V_384 ] ;
}
V_385 &= V_7 ;
if ( V_385 & V_390 )
V_385 = V_390 ;
else if ( V_385 & V_391 )
V_385 = V_391 ;
else if ( V_385 & V_344 )
V_385 = V_344 ;
else if ( V_385 & V_343 )
V_385 = V_343 ;
else if ( V_385 & V_392 )
V_385 = V_392 ;
V_7 &= ~ V_393 ;
return F_302 ( V_7 | V_385 ) ;
}
static T_2 F_303 ( struct V_34 * V_35 , T_2 V_394 )
{
unsigned V_235 ;
T_2 V_7 ;
do {
V_7 = V_394 ;
V_235 = F_304 ( & V_35 -> V_37 -> V_369 ) ;
if ( V_7 & V_337 )
V_7 |= V_35 -> V_37 -> V_370 ;
else if ( V_7 & V_338 )
V_7 |= V_35 -> V_37 -> V_372 ;
else if ( V_7 & V_53 )
V_7 |= V_35 -> V_37 -> V_371 ;
} while ( F_305 ( & V_35 -> V_37 -> V_369 , V_235 ) );
return F_301 ( V_35 , V_7 ) ;
}
T_2 F_306 ( struct V_34 * V_35 , int V_377 )
{
T_2 V_7 ;
T_2 V_29 ;
if ( V_377 )
V_7 = V_337 ;
else if ( V_35 == V_35 -> V_37 -> V_395 )
V_7 = V_338 ;
else
V_7 = V_53 ;
V_29 = F_303 ( V_35 , V_7 ) ;
return V_29 ;
}
int F_307 ( struct V_296 * V_296 , T_2 V_211 )
{
struct V_110 * V_366 ;
struct V_34 * V_35 = F_260 ( V_296 ) -> V_35 ;
struct V_12 * V_37 = V_35 -> V_37 ;
T_2 V_396 ;
int V_29 = 0 ;
int V_397 = 2 ;
int V_398 ;
V_211 = F_149 ( V_211 , V_35 -> V_55 ) ;
if ( F_308 ( V_296 ) ) {
V_397 = 0 ;
ASSERT ( V_399 -> V_400 ) ;
}
V_366 = V_37 -> V_366 ;
if ( ! V_366 )
goto V_401;
V_163:
F_11 ( & V_366 -> V_50 ) ;
V_396 = V_366 -> V_93 + V_366 -> V_353 +
V_366 -> V_352 + V_366 -> V_340 +
V_366 -> V_354 ;
if ( V_396 + V_211 > V_366 -> V_339 ) {
struct V_116 * V_117 ;
if ( ! V_366 -> V_115 ) {
T_2 V_402 ;
V_366 -> V_356 = V_403 ;
F_13 ( & V_366 -> V_50 ) ;
V_401:
V_402 = F_306 ( V_35 , 1 ) ;
V_117 = F_216 ( V_35 ) ;
if ( F_217 ( V_117 ) )
return F_218 ( V_117 ) ;
V_29 = F_309 ( V_117 , V_35 -> V_37 -> V_63 ,
V_402 ,
V_357 ) ;
F_220 ( V_117 , V_35 ) ;
if ( V_29 < 0 ) {
if ( V_29 != - V_312 )
return V_29 ;
else {
V_398 = 1 ;
goto V_404;
}
}
if ( ! V_366 )
V_366 = V_37 -> V_366 ;
goto V_163;
}
V_398 = F_310 (
& V_366 -> V_347 ,
V_396 + V_211 - V_366 -> V_339 ) ;
F_13 ( & V_366 -> V_50 ) ;
V_404:
if ( V_397 &&
! F_213 ( & V_35 -> V_37 -> V_405 ) ) {
V_397 -- ;
if ( V_397 > 0 ) {
F_311 ( V_37 , 0 , - 1 ) ;
F_312 ( V_37 , - 1 , 0 , ( T_2 ) - 1 ) ;
}
V_117 = F_216 ( V_35 ) ;
if ( F_217 ( V_117 ) )
return F_218 ( V_117 ) ;
if ( V_398 >= 0 ||
F_226 ( V_406 ,
& V_117 -> V_134 -> V_7 ) ||
V_397 > 0 ) {
V_29 = F_313 ( V_117 , V_35 ) ;
if ( V_29 )
return V_29 ;
F_49 ( & V_35 -> V_37 -> V_407 ) ;
F_47 ( & V_35 -> V_37 -> V_407 ) ;
goto V_163;
} else {
F_220 ( V_117 , V_35 ) ;
}
}
F_314 ( V_35 -> V_37 ,
L_10 ,
V_366 -> V_7 , V_211 , 1 ) ;
return - V_312 ;
}
V_366 -> V_354 += V_211 ;
F_314 ( V_35 -> V_37 , L_11 ,
V_366 -> V_7 , V_211 , 1 ) ;
F_13 ( & V_366 -> V_50 ) ;
return V_29 ;
}
int F_265 ( struct V_296 * V_296 , T_2 V_32 , T_2 V_47 )
{
struct V_34 * V_35 = F_260 ( V_296 ) -> V_35 ;
int V_29 ;
V_47 = F_315 ( V_32 + V_47 , V_35 -> V_55 ) -
F_150 ( V_32 , V_35 -> V_55 ) ;
V_32 = F_150 ( V_32 , V_35 -> V_55 ) ;
V_29 = F_307 ( V_296 , V_47 ) ;
if ( V_29 < 0 )
return V_29 ;
V_29 = F_316 ( V_296 , V_32 , V_47 ) ;
if ( V_29 )
F_317 ( V_296 , V_32 , V_47 ) ;
return V_29 ;
}
void F_317 ( struct V_296 * V_296 , T_2 V_32 ,
T_2 V_47 )
{
struct V_34 * V_35 = F_260 ( V_296 ) -> V_35 ;
struct V_110 * V_366 ;
V_47 = F_315 ( V_32 + V_47 , V_35 -> V_55 ) -
F_150 ( V_32 , V_35 -> V_55 ) ;
V_32 = F_150 ( V_32 , V_35 -> V_55 ) ;
V_366 = V_35 -> V_37 -> V_366 ;
F_11 ( & V_366 -> V_50 ) ;
if ( F_8 ( V_366 -> V_354 < V_47 ) )
V_366 -> V_354 = 0 ;
else
V_366 -> V_354 -= V_47 ;
F_314 ( V_35 -> V_37 , L_11 ,
V_366 -> V_7 , V_47 , 0 ) ;
F_13 ( & V_366 -> V_50 ) ;
}
void F_318 ( struct V_296 * V_296 , T_2 V_32 , T_2 V_47 )
{
F_317 ( V_296 , V_32 , V_47 ) ;
F_319 ( V_296 , V_32 , V_47 ) ;
}
static void F_320 ( struct V_12 * V_13 )
{
struct V_111 * V_112 = & V_13 -> V_94 ;
struct V_110 * V_113 ;
F_78 () ;
F_79 (found, head, list) {
if ( V_113 -> V_7 & V_53 )
V_113 -> V_356 = V_403 ;
}
F_80 () ;
}
static inline T_2 F_321 ( struct V_260 * V_408 )
{
return ( V_408 -> V_59 << 1 ) ;
}
static int F_322 ( struct V_34 * V_35 ,
struct V_110 * V_409 , int V_410 )
{
struct V_260 * V_261 = & V_35 -> V_37 -> V_264 ;
T_2 V_36 = V_409 -> V_339 - V_409 -> V_340 ;
T_2 V_411 = V_409 -> V_93 + V_409 -> V_353 ;
T_2 V_412 ;
if ( V_410 == V_403 )
return 1 ;
if ( V_409 -> V_7 & V_53 )
V_411 += F_321 ( V_261 ) ;
if ( V_410 == V_413 ) {
V_412 = F_323 ( V_35 -> V_37 -> V_259 ) ;
V_412 = F_35 ( T_2 , V_414 , F_324 ( V_412 , 1 ) ) ;
if ( V_36 - V_411 < V_412 )
return 1 ;
}
if ( V_411 + V_415 < F_325 ( V_36 , 8 ) )
return 0 ;
return 1 ;
}
static T_2 F_326 ( struct V_34 * V_35 , T_2 type )
{
T_2 V_416 ;
if ( type & ( V_344 |
V_392 |
V_391 |
V_390 ) )
V_416 = V_35 -> V_37 -> V_382 -> V_383 ;
else if ( type & V_343 )
V_416 = 2 ;
else
V_416 = 1 ;
return V_416 ;
}
void F_327 ( struct V_116 * V_117 ,
struct V_34 * V_35 ,
T_2 type )
{
struct V_110 * V_13 ;
T_2 V_417 ;
T_2 V_412 ;
int V_29 = 0 ;
T_2 V_418 ;
ASSERT ( F_328 ( & V_35 -> V_37 -> V_419 ) ) ;
V_13 = F_77 ( V_35 -> V_37 , V_338 ) ;
F_11 ( & V_13 -> V_50 ) ;
V_417 = V_13 -> V_339 - V_13 -> V_93 - V_13 -> V_352 -
V_13 -> V_353 - V_13 -> V_340 -
V_13 -> V_354 ;
F_13 ( & V_13 -> V_50 ) ;
V_418 = F_326 ( V_35 , type ) ;
V_412 = F_329 ( V_35 , V_418 ) +
F_211 ( V_35 , 1 ) ;
if ( V_417 < V_412 && F_264 ( V_35 -> V_37 , V_420 ) ) {
F_330 ( V_35 -> V_37 , L_12 ,
V_417 , V_412 , type ) ;
F_331 ( V_35 -> V_37 , V_13 , 0 , 0 ) ;
}
if ( V_417 < V_412 ) {
T_2 V_7 ;
V_7 = F_306 ( V_35 -> V_37 -> V_395 , 0 ) ;
V_29 = F_332 ( V_117 , V_35 , V_7 ) ;
}
if ( ! V_29 ) {
V_29 = F_333 ( V_35 -> V_37 -> V_395 ,
& V_35 -> V_37 -> V_421 ,
V_412 , V_422 ) ;
if ( ! V_29 )
V_117 -> V_423 += V_412 ;
}
}
static int F_309 ( struct V_116 * V_117 ,
struct V_34 * V_63 , T_2 V_7 , int V_410 )
{
struct V_110 * V_94 ;
struct V_12 * V_37 = V_63 -> V_37 ;
int V_424 = 0 ;
int V_29 = 0 ;
if ( V_117 -> V_425 )
return - V_312 ;
V_94 = F_77 ( V_63 -> V_37 , V_7 ) ;
if ( ! V_94 ) {
V_29 = F_289 ( V_63 -> V_37 , V_7 ,
0 , 0 , 0 , & V_94 ) ;
F_32 ( V_29 ) ;
}
F_32 ( ! V_94 ) ;
V_163:
F_11 ( & V_94 -> V_50 ) ;
if ( V_410 < V_94 -> V_356 )
V_410 = V_94 -> V_356 ;
if ( V_94 -> V_115 ) {
if ( F_322 ( V_63 , V_94 , V_410 ) )
V_29 = - V_312 ;
else
V_29 = 0 ;
F_13 ( & V_94 -> V_50 ) ;
return V_29 ;
}
if ( ! F_322 ( V_63 , V_94 , V_410 ) ) {
F_13 ( & V_94 -> V_50 ) ;
return 0 ;
} else if ( V_94 -> V_358 ) {
V_424 = 1 ;
} else {
V_94 -> V_358 = 1 ;
}
F_13 ( & V_94 -> V_50 ) ;
F_49 ( & V_37 -> V_419 ) ;
if ( V_424 ) {
F_47 ( & V_37 -> V_419 ) ;
V_424 = 0 ;
goto V_163;
}
V_117 -> V_425 = true ;
if ( F_334 ( V_94 ) )
V_7 |= ( V_337 | V_53 ) ;
if ( V_7 & V_337 && V_37 -> V_426 ) {
V_37 -> V_427 ++ ;
if ( ! ( V_37 -> V_427 %
V_37 -> V_426 ) )
F_320 ( V_37 ) ;
}
F_327 ( V_117 , V_63 , V_7 ) ;
V_29 = F_332 ( V_117 , V_63 , V_7 ) ;
V_117 -> V_425 = false ;
F_11 ( & V_94 -> V_50 ) ;
if ( V_29 < 0 && V_29 != - V_312 )
goto V_80;
if ( V_29 )
V_94 -> V_115 = 1 ;
else
V_29 = 1 ;
V_94 -> V_356 = V_357 ;
V_80:
V_94 -> V_358 = 0 ;
F_13 ( & V_94 -> V_50 ) ;
F_47 ( & V_37 -> V_419 ) ;
if ( V_117 -> V_276 &&
V_117 -> V_423 >= ( T_2 ) V_415 ) {
F_228 ( V_117 , V_63 ) ;
F_335 ( V_117 ) ;
}
return V_29 ;
}
static int F_336 ( struct V_34 * V_35 ,
struct V_110 * V_94 , T_2 V_211 ,
enum V_428 V_359 )
{
struct V_260 * V_261 ;
T_2 V_429 ;
T_2 V_430 ;
T_2 V_431 ;
T_2 V_396 ;
if ( V_94 -> V_7 & V_337 )
return 0 ;
F_32 ( V_35 -> V_37 == NULL ) ;
V_261 = & V_35 -> V_37 -> V_264 ;
V_429 = F_306 ( V_35 , 0 ) ;
V_396 = V_94 -> V_93 + V_94 -> V_353 +
V_94 -> V_352 + V_94 -> V_340 ;
F_11 ( & V_261 -> V_50 ) ;
V_430 = F_321 ( V_261 ) ;
F_13 ( & V_261 -> V_50 ) ;
if ( V_396 + V_430 >= V_94 -> V_339 )
return 0 ;
V_396 += V_94 -> V_354 ;
F_11 ( & V_35 -> V_37 -> V_432 ) ;
V_431 = V_35 -> V_37 -> V_433 ;
F_13 ( & V_35 -> V_37 -> V_432 ) ;
if ( V_429 & ( V_342 |
V_343 |
V_344 ) )
V_431 >>= 1 ;
if ( V_359 == V_434 )
V_431 >>= 3 ;
else
V_431 >>= 1 ;
if ( V_396 + V_211 < V_94 -> V_339 + V_431 )
return 1 ;
return 0 ;
}
static void F_337 ( struct V_34 * V_35 ,
unsigned long V_435 , int V_436 )
{
struct V_437 * V_438 = V_35 -> V_37 -> V_438 ;
if ( F_338 ( & V_438 -> V_439 ) ) {
F_339 ( V_438 , V_435 , V_440 ) ;
F_46 ( & V_438 -> V_439 ) ;
} else {
F_311 ( V_35 -> V_37 , 0 , V_436 ) ;
if ( ! V_399 -> V_400 )
F_312 ( V_35 -> V_37 , V_436 ,
0 , ( T_2 ) - 1 ) ;
}
}
static inline int F_340 ( struct V_34 * V_35 , T_2 V_441 )
{
T_2 V_211 ;
int V_43 ;
V_211 = F_211 ( V_35 , 1 ) ;
V_43 = ( int ) F_208 ( V_441 , V_211 ) ;
if ( ! V_43 )
V_43 = 1 ;
return V_43 ;
}
static void F_341 ( struct V_34 * V_35 , T_2 V_441 , T_2 V_442 ,
bool V_443 )
{
struct V_260 * V_444 ;
struct V_110 * V_94 ;
struct V_116 * V_117 ;
T_2 V_445 ;
T_2 V_446 ;
long V_447 ;
unsigned long V_435 ;
int V_325 ;
int V_448 ;
enum V_428 V_359 ;
V_448 = F_340 ( V_35 , V_441 ) ;
V_441 = ( T_2 ) V_448 * V_449 ;
V_117 = (struct V_116 * ) V_399 -> V_400 ;
V_444 = & V_35 -> V_37 -> V_450 ;
V_94 = V_444 -> V_94 ;
V_445 = F_342 (
& V_35 -> V_37 -> V_445 ) ;
if ( V_445 == 0 ) {
if ( V_117 )
return;
if ( V_443 )
F_312 ( V_35 -> V_37 , V_448 ,
0 , ( T_2 ) - 1 ) ;
return;
}
V_325 = 0 ;
while ( V_445 && V_325 < 3 ) {
V_446 = F_343 ( V_445 , V_441 ) ;
V_435 = V_446 >> V_451 ;
F_337 ( V_35 , V_435 , V_448 ) ;
V_446 = F_213 ( & V_35 -> V_37 -> V_452 ) ;
if ( ! V_446 )
goto V_453;
if ( V_446 <= V_435 )
V_446 = 0 ;
else
V_446 -= V_435 ;
F_280 ( V_35 -> V_37 -> V_454 ,
F_213 ( & V_35 -> V_37 -> V_452 ) <=
( int ) V_446 ) ;
V_453:
if ( ! V_117 )
V_359 = V_434 ;
else
V_359 = V_422 ;
F_11 ( & V_94 -> V_50 ) ;
if ( F_336 ( V_35 , V_94 , V_442 , V_359 ) ) {
F_13 ( & V_94 -> V_50 ) ;
break;
}
if ( F_183 ( & V_94 -> V_361 ) &&
F_183 ( & V_94 -> V_362 ) ) {
F_13 ( & V_94 -> V_50 ) ;
break;
}
F_13 ( & V_94 -> V_50 ) ;
V_325 ++ ;
if ( V_443 && ! V_117 ) {
F_312 ( V_35 -> V_37 , V_448 ,
0 , ( T_2 ) - 1 ) ;
} else {
V_447 = F_344 ( 1 ) ;
if ( V_447 )
break;
}
V_445 = F_342 (
& V_35 -> V_37 -> V_445 ) ;
}
}
static int F_345 ( struct V_34 * V_35 ,
struct V_110 * V_94 ,
T_2 V_211 , int V_410 )
{
struct V_260 * V_455 = & V_35 -> V_37 -> V_456 ;
struct V_116 * V_117 ;
V_117 = (struct V_116 * ) V_399 -> V_400 ;
if ( V_117 )
return - V_186 ;
if ( V_410 )
goto V_457;
if ( F_310 ( & V_94 -> V_347 ,
V_211 ) >= 0 )
goto V_457;
if ( V_94 != V_455 -> V_94 )
return - V_312 ;
F_11 ( & V_455 -> V_50 ) ;
if ( F_310 ( & V_94 -> V_347 ,
V_211 - V_455 -> V_59 ) >= 0 ) {
F_13 ( & V_455 -> V_50 ) ;
return - V_312 ;
}
F_13 ( & V_455 -> V_50 ) ;
V_457:
V_117 = F_216 ( V_35 ) ;
if ( F_217 ( V_117 ) )
return - V_312 ;
return F_313 ( V_117 , V_35 ) ;
}
static int F_346 ( struct V_34 * V_35 ,
struct V_110 * V_94 , T_2 V_36 ,
T_2 V_458 , int V_291 )
{
struct V_116 * V_117 ;
int V_43 ;
int V_29 = 0 ;
switch ( V_291 ) {
case V_459 :
case V_460 :
if ( V_291 == V_459 )
V_43 = F_340 ( V_35 , V_36 ) * 2 ;
else
V_43 = - 1 ;
V_117 = F_216 ( V_35 ) ;
if ( F_217 ( V_117 ) ) {
V_29 = F_218 ( V_117 ) ;
break;
}
V_29 = F_347 ( V_117 , V_35 , V_43 ) ;
F_220 ( V_117 , V_35 ) ;
break;
case V_461 :
case V_462 :
F_341 ( V_35 , V_36 * 2 , V_458 ,
V_291 == V_462 ) ;
break;
case V_463 :
V_117 = F_216 ( V_35 ) ;
if ( F_217 ( V_117 ) ) {
V_29 = F_218 ( V_117 ) ;
break;
}
V_29 = F_309 ( V_117 , V_35 -> V_37 -> V_63 ,
F_306 ( V_35 , 0 ) ,
V_357 ) ;
F_220 ( V_117 , V_35 ) ;
if ( V_29 > 0 || V_29 == - V_312 )
V_29 = 0 ;
break;
case V_464 :
V_29 = F_345 ( V_35 , V_94 , V_458 , 0 ) ;
break;
default:
V_29 = - V_312 ;
break;
}
F_348 ( V_35 -> V_37 , V_94 -> V_7 , V_36 ,
V_458 , V_291 , V_29 ) ;
return V_29 ;
}
static inline T_2
F_349 ( struct V_34 * V_35 ,
struct V_110 * V_94 )
{
struct V_465 * V_466 ;
T_2 V_396 ;
T_2 V_467 ;
T_2 V_441 = 0 ;
F_184 (ticket, &space_info->tickets, list)
V_441 += V_466 -> V_211 ;
F_184 (ticket, &space_info->priority_tickets, list)
V_441 += V_466 -> V_211 ;
if ( V_441 )
return V_441 ;
V_441 = F_24 ( T_2 , F_350 () * V_302 , V_468 ) ;
if ( F_336 ( V_35 , V_94 , V_441 ,
V_434 ) )
return 0 ;
V_396 = V_94 -> V_93 + V_94 -> V_353 +
V_94 -> V_352 + V_94 -> V_340 +
V_94 -> V_354 ;
if ( F_336 ( V_35 , V_94 , V_302 , V_434 ) )
V_467 = F_324 ( V_94 -> V_339 , 95 ) ;
else
V_467 = F_324 ( V_94 -> V_339 , 90 ) ;
if ( V_396 > V_467 )
V_441 = V_396 - V_467 ;
else
V_441 = 0 ;
V_441 = F_343 ( V_441 , V_94 -> V_354 +
V_94 -> V_353 ) ;
return V_441 ;
}
static inline int F_351 ( struct V_110 * V_94 ,
struct V_34 * V_35 , T_2 V_396 )
{
T_2 V_412 = F_324 ( V_94 -> V_339 , 98 ) ;
if ( ( V_94 -> V_93 + V_94 -> V_353 ) >= V_412 )
return 0 ;
if ( ! F_349 ( V_35 , V_94 ) )
return 0 ;
return ( V_396 >= V_412 && ! F_40 ( V_35 -> V_37 ) &&
! F_226 ( V_469 ,
& V_35 -> V_37 -> V_470 ) ) ;
}
static void F_352 ( struct V_111 * V_112 )
{
struct V_465 * V_466 ;
while ( ! F_183 ( V_112 ) ) {
V_466 = F_274 ( V_112 , struct V_465 , V_98 ) ;
F_275 ( & V_466 -> V_98 ) ;
V_466 -> error = - V_312 ;
F_52 ( & V_466 -> V_89 ) ;
}
}
static void F_353 ( struct V_471 * V_91 )
{
struct V_12 * V_37 ;
struct V_110 * V_94 ;
T_2 V_441 ;
int V_472 ;
int V_473 = 0 ;
T_2 V_474 ;
V_37 = F_55 ( V_91 , struct V_12 , V_475 ) ;
V_94 = F_77 ( V_37 , V_53 ) ;
F_11 ( & V_94 -> V_50 ) ;
V_441 = F_349 ( V_37 -> V_476 ,
V_94 ) ;
if ( ! V_441 ) {
V_94 -> V_359 = 0 ;
F_13 ( & V_94 -> V_50 ) ;
return;
}
V_474 = V_94 -> V_477 ;
F_13 ( & V_94 -> V_50 ) ;
V_472 = V_459 ;
do {
struct V_465 * V_466 ;
int V_29 ;
V_29 = F_346 ( V_37 -> V_476 , V_94 , V_441 ,
V_441 , V_472 ) ;
F_11 ( & V_94 -> V_50 ) ;
if ( F_183 ( & V_94 -> V_361 ) ) {
V_94 -> V_359 = 0 ;
F_13 ( & V_94 -> V_50 ) ;
return;
}
V_441 = F_349 ( V_37 -> V_476 ,
V_94 ) ;
V_466 = F_274 ( & V_94 -> V_361 ,
struct V_465 , V_98 ) ;
if ( V_474 == V_94 -> V_477 ) {
V_472 ++ ;
} else {
V_474 = V_94 -> V_477 ;
V_472 = V_459 ;
if ( V_473 )
V_473 -- ;
}
if ( V_472 > V_464 ) {
V_473 ++ ;
if ( V_473 > 2 ) {
F_352 ( & V_94 -> V_361 ) ;
V_94 -> V_359 = 0 ;
} else {
V_472 = V_459 ;
}
}
F_13 ( & V_94 -> V_50 ) ;
} while ( V_472 <= V_464 );
}
void F_354 ( struct V_471 * V_91 )
{
F_355 ( V_91 , F_353 ) ;
}
static void F_356 ( struct V_12 * V_37 ,
struct V_110 * V_94 ,
struct V_465 * V_466 )
{
T_2 V_441 ;
int V_472 = V_459 ;
F_11 ( & V_94 -> V_50 ) ;
V_441 = F_349 ( V_37 -> V_476 ,
V_94 ) ;
if ( ! V_441 ) {
F_13 ( & V_94 -> V_50 ) ;
return;
}
F_13 ( & V_94 -> V_50 ) ;
do {
F_346 ( V_37 -> V_476 , V_94 , V_441 ,
V_441 , V_472 ) ;
V_472 ++ ;
F_11 ( & V_94 -> V_50 ) ;
if ( V_466 -> V_211 == 0 ) {
F_13 ( & V_94 -> V_50 ) ;
return;
}
F_13 ( & V_94 -> V_50 ) ;
if ( V_472 == V_461 ||
V_472 == V_462 )
V_472 = V_463 ;
} while ( V_472 < V_464 );
}
static int F_357 ( struct V_12 * V_37 ,
struct V_110 * V_94 ,
struct V_465 * V_466 , T_2 V_458 )
{
F_60 ( V_89 ) ;
int V_29 = 0 ;
F_11 ( & V_94 -> V_50 ) ;
while ( V_466 -> V_211 > 0 && V_466 -> error == 0 ) {
V_29 = F_358 ( & V_466 -> V_89 , & V_89 , V_478 ) ;
if ( V_29 ) {
V_29 = - V_479 ;
break;
}
F_13 ( & V_94 -> V_50 ) ;
F_68 () ;
F_69 ( & V_466 -> V_89 , & V_89 ) ;
F_11 ( & V_94 -> V_50 ) ;
}
if ( ! V_29 )
V_29 = V_466 -> error ;
if ( ! F_183 ( & V_466 -> V_98 ) )
F_275 ( & V_466 -> V_98 ) ;
if ( V_466 -> V_211 && V_466 -> V_211 < V_458 ) {
T_2 V_36 = V_458 - V_466 -> V_211 ;
V_94 -> V_354 -= V_36 ;
F_314 ( V_37 , L_11 ,
V_94 -> V_7 , V_36 , 0 ) ;
}
F_13 ( & V_94 -> V_50 ) ;
return V_29 ;
}
static int F_359 ( struct V_34 * V_35 ,
struct V_110 * V_94 ,
T_2 V_458 ,
enum V_428 V_359 )
{
struct V_465 V_466 ;
T_2 V_396 ;
int V_29 = 0 ;
ASSERT ( V_458 ) ;
ASSERT ( ! V_399 -> V_400 || V_359 != V_434 ) ;
F_11 ( & V_94 -> V_50 ) ;
V_29 = - V_312 ;
V_396 = V_94 -> V_93 + V_94 -> V_353 +
V_94 -> V_352 + V_94 -> V_340 +
V_94 -> V_354 ;
if ( V_396 + V_458 <= V_94 -> V_339 ) {
V_94 -> V_354 += V_458 ;
F_314 ( V_35 -> V_37 , L_11 ,
V_94 -> V_7 , V_458 ,
1 ) ;
V_29 = 0 ;
} else if ( F_336 ( V_35 , V_94 , V_458 , V_359 ) ) {
V_94 -> V_354 += V_458 ;
F_314 ( V_35 -> V_37 , L_11 ,
V_94 -> V_7 , V_458 ,
1 ) ;
V_29 = 0 ;
}
if ( V_29 && V_359 != V_422 ) {
V_466 . V_211 = V_458 ;
V_466 . error = 0 ;
F_64 ( & V_466 . V_89 ) ;
if ( V_359 == V_434 ) {
F_72 ( & V_466 . V_98 , & V_94 -> V_361 ) ;
if ( ! V_94 -> V_359 ) {
V_94 -> V_359 = 1 ;
F_360 ( V_35 -> V_37 ,
V_94 -> V_7 ,
V_458 , V_359 ,
L_13 ) ;
F_361 ( V_480 ,
& V_35 -> V_37 -> V_475 ) ;
}
} else {
F_72 ( & V_466 . V_98 ,
& V_94 -> V_362 ) ;
}
} else if ( ! V_29 && V_94 -> V_7 & V_53 ) {
V_396 += V_458 ;
if ( ! F_226 ( V_481 , & V_35 -> V_37 -> V_7 ) &&
F_351 ( V_94 , V_35 , V_396 ) &&
! F_362 ( & V_35 -> V_37 -> V_475 ) ) {
F_360 ( V_35 -> V_37 ,
V_94 -> V_7 ,
V_458 , V_359 ,
L_14 ) ;
F_361 ( V_480 ,
& V_35 -> V_37 -> V_475 ) ;
}
}
F_13 ( & V_94 -> V_50 ) ;
if ( ! V_29 || V_359 == V_422 )
return V_29 ;
if ( V_359 == V_434 )
return F_357 ( V_35 -> V_37 , V_94 , & V_466 ,
V_458 ) ;
V_29 = 0 ;
F_356 ( V_35 -> V_37 , V_94 , & V_466 ) ;
F_11 ( & V_94 -> V_50 ) ;
if ( V_466 . V_211 ) {
if ( V_466 . V_211 < V_458 ) {
T_2 V_36 = V_458 - V_466 . V_211 ;
V_94 -> V_354 -= V_36 ;
F_314 ( V_35 -> V_37 ,
L_11 , V_94 -> V_7 ,
V_36 , 0 ) ;
}
F_275 ( & V_466 . V_98 ) ;
V_29 = - V_312 ;
}
F_13 ( & V_94 -> V_50 ) ;
ASSERT ( F_183 ( & V_466 . V_98 ) ) ;
return V_29 ;
}
static int F_363 ( struct V_34 * V_35 ,
struct V_260 * V_444 ,
T_2 V_458 ,
enum V_428 V_359 )
{
int V_29 ;
V_29 = F_359 ( V_35 , V_444 -> V_94 , V_458 ,
V_359 ) ;
if ( V_29 == - V_312 &&
F_364 ( V_35 -> V_482 == V_483 ) ) {
struct V_260 * V_261 =
& V_35 -> V_37 -> V_264 ;
if ( V_444 != V_261 &&
! F_365 ( V_261 , V_458 ) )
V_29 = 0 ;
}
if ( V_29 == - V_312 )
F_314 ( V_35 -> V_37 ,
L_10 ,
V_444 -> V_94 -> V_7 ,
V_458 , 1 ) ;
return V_29 ;
}
static struct V_260 * F_366 (
const struct V_116 * V_117 ,
const struct V_34 * V_35 )
{
struct V_260 * V_444 = NULL ;
if ( F_226 ( V_290 , & V_35 -> V_291 ) ||
( V_35 == V_35 -> V_37 -> V_484 && V_117 -> V_485 ) ||
( V_35 == V_35 -> V_37 -> V_486 ) )
V_444 = V_117 -> V_444 ;
if ( ! V_444 )
V_444 = V_35 -> V_444 ;
if ( ! V_444 )
V_444 = & V_35 -> V_37 -> V_487 ;
return V_444 ;
}
static int F_365 ( struct V_260 * V_444 ,
T_2 V_36 )
{
int V_29 = - V_312 ;
F_11 ( & V_444 -> V_50 ) ;
if ( V_444 -> V_10 >= V_36 ) {
V_444 -> V_10 -= V_36 ;
if ( V_444 -> V_10 < V_444 -> V_59 )
V_444 -> V_115 = 0 ;
V_29 = 0 ;
}
F_13 ( & V_444 -> V_50 ) ;
return V_29 ;
}
static void F_367 ( struct V_260 * V_444 ,
T_2 V_36 , int V_488 )
{
F_11 ( & V_444 -> V_50 ) ;
V_444 -> V_10 += V_36 ;
if ( V_488 )
V_444 -> V_59 += V_36 ;
else if ( V_444 -> V_10 >= V_444 -> V_59 )
V_444 -> V_115 = 1 ;
F_13 ( & V_444 -> V_50 ) ;
}
int F_368 ( struct V_12 * V_37 ,
struct V_260 * V_489 , T_2 V_36 ,
int V_490 )
{
struct V_260 * V_261 = & V_37 -> V_264 ;
T_2 V_491 ;
if ( V_261 -> V_94 != V_489 -> V_94 )
return - V_312 ;
F_11 ( & V_261 -> V_50 ) ;
V_491 = F_325 ( V_261 -> V_59 , V_490 ) ;
if ( V_261 -> V_10 < V_491 + V_36 ) {
F_13 ( & V_261 -> V_50 ) ;
return - V_312 ;
}
V_261 -> V_10 -= V_36 ;
if ( V_261 -> V_10 < V_261 -> V_59 )
V_261 -> V_115 = 0 ;
F_13 ( & V_261 -> V_50 ) ;
F_367 ( V_489 , V_36 , 1 ) ;
return 0 ;
}
static void F_369 ( struct V_12 * V_37 ,
struct V_110 * V_94 ,
T_2 V_36 )
{
struct V_465 * V_466 ;
struct V_111 * V_112 ;
T_2 V_396 ;
enum V_428 V_359 = V_422 ;
bool V_492 = false ;
F_11 ( & V_94 -> V_50 ) ;
V_112 = & V_94 -> V_362 ;
V_396 = V_94 -> V_93 + V_94 -> V_353 +
V_94 -> V_352 + V_94 -> V_340 +
V_94 -> V_354 ;
if ( V_396 - V_36 >= V_94 -> V_339 )
V_492 = true ;
V_163:
while ( ! F_183 ( V_112 ) && V_36 ) {
V_466 = F_274 ( V_112 , struct V_465 ,
V_98 ) ;
if ( V_492 &&
! F_336 ( V_37 -> V_63 , V_94 , 0 ,
V_359 ) )
break;
if ( V_36 >= V_466 -> V_211 ) {
F_275 ( & V_466 -> V_98 ) ;
V_36 -= V_466 -> V_211 ;
V_466 -> V_211 = 0 ;
V_94 -> V_477 ++ ;
F_52 ( & V_466 -> V_89 ) ;
} else {
V_466 -> V_211 -= V_36 ;
V_36 = 0 ;
}
}
if ( V_36 && V_112 == & V_94 -> V_362 ) {
V_112 = & V_94 -> V_361 ;
V_359 = V_434 ;
goto V_163;
}
V_94 -> V_354 -= V_36 ;
F_314 ( V_37 , L_11 ,
V_94 -> V_7 , V_36 , 0 ) ;
F_13 ( & V_94 -> V_50 ) ;
}
static void F_290 ( struct V_12 * V_37 ,
struct V_110 * V_94 ,
T_2 V_36 )
{
struct V_465 * V_466 ;
struct V_111 * V_112 = & V_94 -> V_362 ;
V_163:
while ( ! F_183 ( V_112 ) && V_36 ) {
V_466 = F_274 ( V_112 , struct V_465 ,
V_98 ) ;
if ( V_36 >= V_466 -> V_211 ) {
F_314 ( V_37 , L_11 ,
V_94 -> V_7 ,
V_466 -> V_211 , 1 ) ;
F_275 ( & V_466 -> V_98 ) ;
V_36 -= V_466 -> V_211 ;
V_94 -> V_354 += V_466 -> V_211 ;
V_466 -> V_211 = 0 ;
V_94 -> V_477 ++ ;
F_52 ( & V_466 -> V_89 ) ;
} else {
F_314 ( V_37 , L_11 ,
V_94 -> V_7 ,
V_36 , 1 ) ;
V_94 -> V_354 += V_36 ;
V_466 -> V_211 -= V_36 ;
V_36 = 0 ;
}
}
if ( V_36 && V_112 == & V_94 -> V_362 ) {
V_112 = & V_94 -> V_361 ;
goto V_163;
}
}
static void F_370 ( struct V_12 * V_37 ,
struct V_260 * V_444 ,
struct V_260 * V_489 , T_2 V_36 )
{
struct V_110 * V_94 = V_444 -> V_94 ;
F_11 ( & V_444 -> V_50 ) ;
if ( V_36 == ( T_2 ) - 1 )
V_36 = V_444 -> V_59 ;
V_444 -> V_59 -= V_36 ;
if ( V_444 -> V_10 >= V_444 -> V_59 ) {
V_36 = V_444 -> V_10 - V_444 -> V_59 ;
V_444 -> V_10 = V_444 -> V_59 ;
V_444 -> V_115 = 1 ;
} else {
V_36 = 0 ;
}
F_13 ( & V_444 -> V_50 ) ;
if ( V_36 > 0 ) {
if ( V_489 ) {
F_11 ( & V_489 -> V_50 ) ;
if ( ! V_489 -> V_115 ) {
T_2 V_493 ;
V_493 = V_489 -> V_59 - V_489 -> V_10 ;
V_493 = F_343 ( V_36 , V_493 ) ;
V_489 -> V_10 += V_493 ;
if ( V_489 -> V_10 >= V_489 -> V_59 )
V_489 -> V_115 = 1 ;
V_36 -= V_493 ;
}
F_13 ( & V_489 -> V_50 ) ;
}
if ( V_36 )
F_369 ( V_37 , V_94 ,
V_36 ) ;
}
}
int F_371 ( struct V_260 * V_494 ,
struct V_260 * V_495 , T_2 V_36 ,
int V_488 )
{
int V_29 ;
V_29 = F_365 ( V_494 , V_36 ) ;
if ( V_29 )
return V_29 ;
F_367 ( V_495 , V_36 , V_488 ) ;
return 0 ;
}
void F_372 ( struct V_260 * V_496 , unsigned short type )
{
memset ( V_496 , 0 , sizeof( * V_496 ) ) ;
F_293 ( & V_496 -> V_50 ) ;
V_496 -> type = type ;
}
struct V_260 * F_373 ( struct V_34 * V_35 ,
unsigned short type )
{
struct V_260 * V_444 ;
struct V_12 * V_37 = V_35 -> V_37 ;
V_444 = F_223 ( sizeof( * V_444 ) , V_97 ) ;
if ( ! V_444 )
return NULL ;
F_372 ( V_444 , type ) ;
V_444 -> V_94 = F_77 ( V_37 ,
V_53 ) ;
return V_444 ;
}
void F_374 ( struct V_34 * V_35 ,
struct V_260 * V_496 )
{
if ( ! V_496 )
return;
F_375 ( V_35 , V_496 , ( T_2 ) - 1 ) ;
F_9 ( V_496 ) ;
}
void F_376 ( struct V_260 * V_496 )
{
F_9 ( V_496 ) ;
}
int F_333 ( struct V_34 * V_35 ,
struct V_260 * V_444 , T_2 V_36 ,
enum V_428 V_359 )
{
int V_29 ;
if ( V_36 == 0 )
return 0 ;
V_29 = F_363 ( V_35 , V_444 , V_36 , V_359 ) ;
if ( ! V_29 ) {
F_367 ( V_444 , V_36 , 1 ) ;
return 0 ;
}
return V_29 ;
}
int F_377 ( struct V_34 * V_35 ,
struct V_260 * V_444 , int V_490 )
{
T_2 V_36 = 0 ;
int V_29 = - V_312 ;
if ( ! V_444 )
return 0 ;
F_11 ( & V_444 -> V_50 ) ;
V_36 = F_325 ( V_444 -> V_59 , V_490 ) ;
if ( V_444 -> V_10 >= V_36 )
V_29 = 0 ;
F_13 ( & V_444 -> V_50 ) ;
return V_29 ;
}
int F_378 ( struct V_34 * V_35 ,
struct V_260 * V_444 , T_2 V_497 ,
enum V_428 V_359 )
{
T_2 V_36 = 0 ;
int V_29 = - V_312 ;
if ( ! V_444 )
return 0 ;
F_11 ( & V_444 -> V_50 ) ;
V_36 = V_497 ;
if ( V_444 -> V_10 >= V_36 )
V_29 = 0 ;
else
V_36 -= V_444 -> V_10 ;
F_13 ( & V_444 -> V_50 ) ;
if ( ! V_29 )
return 0 ;
V_29 = F_363 ( V_35 , V_444 , V_36 , V_359 ) ;
if ( ! V_29 ) {
F_367 ( V_444 , V_36 , 0 ) ;
return 0 ;
}
return V_29 ;
}
void F_375 ( struct V_34 * V_35 ,
struct V_260 * V_444 ,
T_2 V_36 )
{
struct V_260 * V_261 = & V_35 -> V_37 -> V_264 ;
if ( V_261 == V_444 ||
V_444 -> V_94 != V_261 -> V_94 )
V_261 = NULL ;
F_370 ( V_35 -> V_37 , V_444 , V_261 ,
V_36 ) ;
}
static void F_379 ( struct V_12 * V_37 )
{
struct V_260 * V_444 = & V_37 -> V_264 ;
struct V_110 * V_409 = V_444 -> V_94 ;
T_2 V_36 ;
V_36 = F_380 ( & V_37 -> V_63 -> V_282 ) +
F_380 ( & V_37 -> V_484 -> V_282 ) +
F_380 ( & V_37 -> V_87 -> V_282 ) ;
V_36 = F_35 ( T_2 , V_36 , V_468 ) ;
F_11 ( & V_409 -> V_50 ) ;
F_11 ( & V_444 -> V_50 ) ;
V_444 -> V_59 = F_24 ( T_2 , V_36 , V_498 ) ;
if ( V_444 -> V_10 < V_444 -> V_59 ) {
V_36 = V_409 -> V_93 + V_409 -> V_352 +
V_409 -> V_353 + V_409 -> V_340 +
V_409 -> V_354 ;
if ( V_409 -> V_339 > V_36 ) {
V_36 = V_409 -> V_339 - V_36 ;
V_36 = F_343 ( V_36 ,
V_444 -> V_59 - V_444 -> V_10 ) ;
V_444 -> V_10 += V_36 ;
V_409 -> V_354 += V_36 ;
F_314 ( V_37 , L_11 ,
V_409 -> V_7 , V_36 ,
1 ) ;
}
} else if ( V_444 -> V_10 > V_444 -> V_59 ) {
V_36 = V_444 -> V_10 - V_444 -> V_59 ;
V_409 -> V_354 -= V_36 ;
F_314 ( V_37 , L_11 ,
V_409 -> V_7 , V_36 , 0 ) ;
V_444 -> V_10 = V_444 -> V_59 ;
}
if ( V_444 -> V_10 == V_444 -> V_59 )
V_444 -> V_115 = 1 ;
else
V_444 -> V_115 = 0 ;
F_13 ( & V_444 -> V_50 ) ;
F_13 ( & V_409 -> V_50 ) ;
}
static void F_381 ( struct V_12 * V_37 )
{
struct V_110 * V_94 ;
V_94 = F_77 ( V_37 , V_338 ) ;
V_37 -> V_421 . V_94 = V_94 ;
V_94 = F_77 ( V_37 , V_53 ) ;
V_37 -> V_264 . V_94 = V_94 ;
V_37 -> V_450 . V_94 = V_94 ;
V_37 -> V_499 . V_94 = V_94 ;
V_37 -> V_487 . V_94 = V_94 ;
V_37 -> V_456 . V_94 = V_94 ;
V_37 -> V_63 -> V_444 = & V_37 -> V_264 ;
V_37 -> V_484 -> V_444 = & V_37 -> V_264 ;
V_37 -> V_500 -> V_444 = & V_37 -> V_264 ;
V_37 -> V_87 -> V_444 = & V_37 -> V_264 ;
if ( V_37 -> V_501 )
V_37 -> V_501 -> V_444 = & V_37 -> V_264 ;
V_37 -> V_395 -> V_444 = & V_37 -> V_421 ;
F_379 ( V_37 ) ;
}
static void F_382 ( struct V_12 * V_37 )
{
F_370 ( V_37 , & V_37 -> V_264 , NULL ,
( T_2 ) - 1 ) ;
F_8 ( V_37 -> V_450 . V_59 > 0 ) ;
F_8 ( V_37 -> V_450 . V_10 > 0 ) ;
F_8 ( V_37 -> V_499 . V_59 > 0 ) ;
F_8 ( V_37 -> V_499 . V_10 > 0 ) ;
F_8 ( V_37 -> V_421 . V_59 > 0 ) ;
F_8 ( V_37 -> V_421 . V_10 > 0 ) ;
F_8 ( V_37 -> V_456 . V_59 > 0 ) ;
F_8 ( V_37 -> V_456 . V_10 > 0 ) ;
}
void F_383 ( struct V_116 * V_117 ,
struct V_34 * V_35 )
{
if ( ! V_117 -> V_444 )
return;
if ( ! V_117 -> V_353 )
return;
F_314 ( V_35 -> V_37 , L_15 ,
V_117 -> V_272 , V_117 -> V_353 , 0 ) ;
F_375 ( V_35 , V_117 -> V_444 , V_117 -> V_353 ) ;
V_117 -> V_353 = 0 ;
}
void F_335 ( struct V_116 * V_117 )
{
struct V_12 * V_37 = V_117 -> V_37 ;
if ( ! V_117 -> V_423 )
return;
F_384 ( ! F_183 ( & V_117 -> V_279 ) ) ;
F_370 ( V_37 , & V_37 -> V_421 , NULL ,
V_117 -> V_423 ) ;
V_117 -> V_423 = 0 ;
}
int F_385 ( struct V_116 * V_117 ,
struct V_296 * V_296 )
{
struct V_34 * V_35 = F_260 ( V_296 ) -> V_35 ;
struct V_260 * V_502 = V_117 -> V_444 ;
struct V_260 * V_503 = V_35 -> V_504 ;
T_2 V_36 = F_211 ( V_35 , 1 ) ;
F_314 ( V_35 -> V_37 , L_16 ,
F_386 ( V_296 ) , V_36 , 1 ) ;
return F_371 ( V_502 , V_503 , V_36 , 1 ) ;
}
void F_387 ( struct V_296 * V_296 )
{
struct V_34 * V_35 = F_260 ( V_296 ) -> V_35 ;
T_2 V_36 = F_211 ( V_35 , 1 ) ;
F_314 ( V_35 -> V_37 , L_16 ,
F_386 ( V_296 ) , V_36 , 0 ) ;
F_375 ( V_35 , V_35 -> V_504 , V_36 ) ;
}
int F_388 ( struct V_34 * V_35 ,
struct V_260 * V_496 ,
int V_448 ,
T_2 * V_230 ,
bool V_505 )
{
T_2 V_36 ;
int V_29 ;
struct V_260 * V_261 = & V_35 -> V_37 -> V_264 ;
if ( F_226 ( V_506 , & V_35 -> V_37 -> V_7 ) ) {
V_36 = 3 * V_35 -> V_54 ;
V_29 = F_389 ( V_35 , V_36 ) ;
if ( V_29 )
return V_29 ;
} else {
V_36 = 0 ;
}
* V_230 = V_36 ;
V_36 = F_211 ( V_35 , V_448 ) ;
V_496 -> V_94 = F_77 ( V_35 -> V_37 ,
V_53 ) ;
V_29 = F_333 ( V_35 , V_496 , V_36 ,
V_434 ) ;
if ( V_29 == - V_312 && V_505 )
V_29 = F_371 ( V_261 , V_496 , V_36 , 1 ) ;
if ( V_29 && * V_230 )
F_390 ( V_35 , * V_230 ) ;
return V_29 ;
}
void F_391 ( struct V_34 * V_35 ,
struct V_260 * V_496 ,
T_2 V_230 )
{
F_375 ( V_35 , V_496 , ( T_2 ) - 1 ) ;
}
static unsigned F_392 ( struct V_296 * V_296 , T_2 V_36 )
{
unsigned V_507 = 0 ;
unsigned V_508 = 0 ;
unsigned V_509 = 0 ;
V_509 = ( unsigned ) F_208 ( V_36 +
V_510 - 1 ,
V_510 ) ;
ASSERT ( V_509 ) ;
ASSERT ( F_260 ( V_296 ) -> V_511 >= V_509 ) ;
F_260 ( V_296 ) -> V_511 -= V_509 ;
if ( F_260 ( V_296 ) -> V_511 == 0 &&
F_393 ( V_512 ,
& F_260 ( V_296 ) -> V_513 ) )
V_507 = 1 ;
if ( F_260 ( V_296 ) -> V_511 >=
F_260 ( V_296 ) -> V_514 )
return V_507 ;
V_508 = F_260 ( V_296 ) -> V_514 -
F_260 ( V_296 ) -> V_511 ;
F_260 ( V_296 ) -> V_514 -= V_508 ;
return V_508 + V_507 ;
}
static T_2 F_394 ( struct V_296 * V_296 , T_2 V_36 ,
int V_515 )
{
struct V_34 * V_35 = F_260 ( V_296 ) -> V_35 ;
T_2 V_516 , V_258 ;
if ( F_260 ( V_296 ) -> V_7 & V_517 &&
F_260 ( V_296 ) -> V_255 == 0 )
return 0 ;
V_516 = F_206 ( V_35 , F_260 ( V_296 ) -> V_255 ) ;
if ( V_515 )
F_260 ( V_296 ) -> V_255 += V_36 ;
else
F_260 ( V_296 ) -> V_255 -= V_36 ;
V_258 = F_206 ( V_35 , F_260 ( V_296 ) -> V_255 ) ;
if ( V_516 == V_258 )
return 0 ;
if ( V_515 )
return F_211 ( V_35 ,
V_258 - V_516 ) ;
return F_211 ( V_35 , V_516 - V_258 ) ;
}
int F_395 ( struct V_296 * V_296 , T_2 V_36 )
{
struct V_34 * V_35 = F_260 ( V_296 ) -> V_35 ;
struct V_260 * V_444 = & V_35 -> V_37 -> V_450 ;
T_2 V_518 = 0 ;
T_2 V_255 ;
unsigned V_519 = 0 ;
enum V_428 V_359 = V_434 ;
int V_29 = 0 ;
bool V_520 = true ;
T_2 V_521 = 0 ;
unsigned V_522 ;
bool V_523 = false ;
if ( F_308 ( V_296 ) ) {
V_359 = V_422 ;
V_520 = false ;
} else if ( V_399 -> V_400 ) {
V_359 = V_524 ;
}
if ( V_359 != V_422 &&
F_396 ( V_35 -> V_37 ) )
F_397 ( 1 ) ;
if ( V_520 )
F_49 ( & F_260 ( V_296 ) -> V_525 ) ;
V_36 = F_149 ( V_36 , V_35 -> V_55 ) ;
F_11 ( & F_260 ( V_296 ) -> V_50 ) ;
V_519 = ( unsigned ) F_208 ( V_36 +
V_510 - 1 ,
V_510 ) ;
F_260 ( V_296 ) -> V_511 += V_519 ;
V_519 = 0 ;
if ( F_260 ( V_296 ) -> V_511 >
F_260 ( V_296 ) -> V_514 )
V_519 += F_260 ( V_296 ) -> V_511 -
F_260 ( V_296 ) -> V_514 ;
V_518 = F_211 ( V_35 , V_519 + 1 ) ;
V_518 += F_394 ( V_296 , V_36 , 1 ) ;
V_255 = F_260 ( V_296 ) -> V_255 ;
F_13 ( & F_260 ( V_296 ) -> V_50 ) ;
if ( F_226 ( V_506 , & V_35 -> V_37 -> V_7 ) ) {
V_29 = F_389 ( V_35 ,
V_519 * V_35 -> V_54 ) ;
if ( V_29 )
goto V_526;
}
V_29 = F_333 ( V_35 , V_444 , V_518 , V_359 ) ;
if ( F_364 ( V_29 ) ) {
F_390 ( V_35 , V_519 * V_35 -> V_54 ) ;
goto V_526;
}
F_11 ( & F_260 ( V_296 ) -> V_50 ) ;
if ( F_398 ( V_512 ,
& F_260 ( V_296 ) -> V_513 ) ) {
V_518 -= F_211 ( V_35 , 1 ) ;
V_523 = true ;
}
F_260 ( V_296 ) -> V_514 += V_519 ;
F_13 ( & F_260 ( V_296 ) -> V_50 ) ;
if ( V_520 )
F_47 ( & F_260 ( V_296 ) -> V_525 ) ;
if ( V_518 )
F_314 ( V_35 -> V_37 , L_17 ,
F_386 ( V_296 ) , V_518 , 1 ) ;
if ( V_523 )
F_375 ( V_35 , V_444 ,
F_211 ( V_35 ,
1 ) ) ;
return 0 ;
V_526:
F_11 ( & F_260 ( V_296 ) -> V_50 ) ;
V_522 = F_392 ( V_296 , V_36 ) ;
if ( F_260 ( V_296 ) -> V_255 == V_255 ) {
F_394 ( V_296 , V_36 , 0 ) ;
} else {
T_2 V_527 = F_260 ( V_296 ) -> V_255 ;
T_2 V_211 ;
V_211 = V_255 - F_260 ( V_296 ) -> V_255 ;
F_260 ( V_296 ) -> V_255 = V_255 ;
V_521 = F_394 ( V_296 , V_211 , 0 ) ;
F_260 ( V_296 ) -> V_255 = V_255 - V_36 ;
V_211 = V_255 - V_527 ;
V_211 = F_394 ( V_296 , V_211 , 0 ) ;
F_260 ( V_296 ) -> V_255 = V_527 - V_36 ;
if ( V_211 > V_521 )
V_521 = V_211 - V_521 ;
else
V_521 = 0 ;
}
F_13 ( & F_260 ( V_296 ) -> V_50 ) ;
if ( V_522 )
V_521 += F_211 ( V_35 , V_522 ) ;
if ( V_521 ) {
F_375 ( V_35 , V_444 , V_521 ) ;
F_314 ( V_35 -> V_37 , L_17 ,
F_386 ( V_296 ) , V_521 , 0 ) ;
}
if ( V_520 )
F_47 ( & F_260 ( V_296 ) -> V_525 ) ;
return V_29 ;
}
void F_399 ( struct V_296 * V_296 , T_2 V_36 )
{
struct V_34 * V_35 = F_260 ( V_296 ) -> V_35 ;
T_2 V_521 = 0 ;
unsigned V_522 ;
V_36 = F_149 ( V_36 , V_35 -> V_55 ) ;
F_11 ( & F_260 ( V_296 ) -> V_50 ) ;
V_522 = F_392 ( V_296 , V_36 ) ;
if ( V_36 )
V_521 = F_394 ( V_296 , V_36 , 0 ) ;
F_13 ( & F_260 ( V_296 ) -> V_50 ) ;
if ( V_522 > 0 )
V_521 += F_211 ( V_35 , V_522 ) ;
if ( F_241 ( V_35 -> V_37 ) )
return;
F_314 ( V_35 -> V_37 , L_17 ,
F_386 ( V_296 ) , V_521 , 0 ) ;
F_375 ( V_35 , & V_35 -> V_37 -> V_450 ,
V_521 ) ;
}
int F_400 ( struct V_296 * V_296 , T_2 V_32 , T_2 V_47 )
{
int V_29 ;
V_29 = F_265 ( V_296 , V_32 , V_47 ) ;
if ( V_29 < 0 )
return V_29 ;
V_29 = F_395 ( V_296 , V_47 ) ;
if ( V_29 < 0 )
F_318 ( V_296 , V_32 , V_47 ) ;
return V_29 ;
}
void F_401 ( struct V_296 * V_296 , T_2 V_32 , T_2 V_47 )
{
F_399 ( V_296 , V_47 ) ;
F_318 ( V_296 , V_32 , V_47 ) ;
}
static int F_402 ( struct V_116 * V_117 ,
struct V_34 * V_35 , T_2 V_27 ,
T_2 V_36 , int V_401 )
{
struct V_1 * V_2 = NULL ;
struct V_12 * V_13 = V_35 -> V_37 ;
T_2 V_528 = V_36 ;
T_2 V_529 ;
T_2 V_530 ;
int V_341 ;
F_11 ( & V_13 -> V_531 ) ;
V_529 = F_403 ( V_13 -> V_259 ) ;
if ( V_401 )
V_529 += V_36 ;
else
V_529 -= V_36 ;
F_404 ( V_13 -> V_259 , V_529 ) ;
F_13 ( & V_13 -> V_531 ) ;
while ( V_528 ) {
V_2 = F_76 ( V_13 , V_27 ) ;
if ( ! V_2 )
return - V_160 ;
if ( V_2 -> V_7 & ( V_342 |
V_343 |
V_344 ) )
V_341 = 2 ;
else
V_341 = 1 ;
if ( ! V_401 && V_2 -> V_3 == V_102 )
F_59 ( V_2 , 1 ) ;
V_530 = V_27 - V_2 -> V_21 . V_22 ;
F_8 ( V_530 > V_2 -> V_21 . V_33 ) ;
F_11 ( & V_2 -> V_94 -> V_50 ) ;
F_11 ( & V_2 -> V_50 ) ;
if ( F_264 ( V_35 -> V_37 , V_310 ) &&
V_2 -> V_303 < V_319 )
V_2 -> V_303 = V_319 ;
V_529 = F_58 ( & V_2 -> V_95 ) ;
V_36 = F_343 ( V_528 , V_2 -> V_21 . V_33 - V_530 ) ;
if ( V_401 ) {
V_529 += V_36 ;
F_405 ( & V_2 -> V_95 , V_529 ) ;
V_2 -> V_10 -= V_36 ;
V_2 -> V_94 -> V_353 -= V_36 ;
V_2 -> V_94 -> V_93 += V_36 ;
V_2 -> V_94 -> V_346 += V_36 * V_341 ;
F_13 ( & V_2 -> V_50 ) ;
F_13 ( & V_2 -> V_94 -> V_50 ) ;
} else {
V_529 -= V_36 ;
F_405 ( & V_2 -> V_95 , V_529 ) ;
V_2 -> V_9 += V_36 ;
V_2 -> V_94 -> V_352 += V_36 ;
V_2 -> V_94 -> V_93 -= V_36 ;
V_2 -> V_94 -> V_346 -= V_36 * V_341 ;
F_13 ( & V_2 -> V_50 ) ;
F_13 ( & V_2 -> V_94 -> V_50 ) ;
F_314 ( V_35 -> V_37 , L_18 ,
V_2 -> V_94 -> V_7 ,
V_36 , 1 ) ;
F_406 ( V_13 -> V_61 ,
V_27 , V_27 + V_36 - 1 ,
V_97 | V_532 ) ;
}
F_11 ( & V_117 -> V_134 -> V_326 ) ;
if ( F_183 ( & V_2 -> V_328 ) ) {
F_72 ( & V_2 -> V_328 ,
& V_117 -> V_134 -> V_318 ) ;
V_117 -> V_134 -> V_262 ++ ;
F_4 ( V_2 ) ;
}
F_13 ( & V_117 -> V_134 -> V_326 ) ;
if ( ! V_401 && V_529 == 0 ) {
F_11 ( & V_13 -> V_533 ) ;
if ( F_183 ( & V_2 -> V_534 ) ) {
F_4 ( V_2 ) ;
F_72 ( & V_2 -> V_534 ,
& V_13 -> V_535 ) ;
}
F_13 ( & V_13 -> V_533 ) ;
}
F_6 ( V_2 ) ;
V_528 -= V_36 ;
V_27 += V_36 ;
}
return 0 ;
}
static T_2 V_26 ( struct V_34 * V_35 , T_2 V_536 )
{
struct V_1 * V_2 ;
T_2 V_27 ;
F_11 ( & V_35 -> V_37 -> V_18 ) ;
V_27 = V_35 -> V_37 -> V_26 ;
F_13 ( & V_35 -> V_37 -> V_18 ) ;
if ( V_27 < ( T_2 ) - 1 )
return V_27 ;
V_2 = F_75 ( V_35 -> V_37 , V_536 ) ;
if ( ! V_2 )
return 0 ;
V_27 = V_2 -> V_21 . V_22 ;
F_6 ( V_2 ) ;
return V_27 ;
}
static int F_407 ( struct V_34 * V_35 ,
struct V_1 * V_2 ,
T_2 V_27 , T_2 V_36 , int V_10 )
{
F_11 ( & V_2 -> V_94 -> V_50 ) ;
F_11 ( & V_2 -> V_50 ) ;
V_2 -> V_9 += V_36 ;
V_2 -> V_94 -> V_352 += V_36 ;
if ( V_10 ) {
V_2 -> V_10 -= V_36 ;
V_2 -> V_94 -> V_353 -= V_36 ;
}
F_13 ( & V_2 -> V_50 ) ;
F_13 ( & V_2 -> V_94 -> V_50 ) ;
F_314 ( V_35 -> V_37 , L_18 ,
V_2 -> V_94 -> V_7 , V_36 , 1 ) ;
F_406 ( V_35 -> V_37 -> V_61 , V_27 ,
V_27 + V_36 - 1 , V_97 | V_532 ) ;
return 0 ;
}
int F_176 ( struct V_34 * V_35 ,
T_2 V_27 , T_2 V_36 , int V_10 )
{
struct V_1 * V_2 ;
V_2 = F_76 ( V_35 -> V_37 , V_27 ) ;
F_32 ( ! V_2 ) ;
F_407 ( V_35 , V_2 , V_27 , V_36 , V_10 ) ;
F_6 ( V_2 ) ;
return 0 ;
}
int F_408 ( struct V_34 * V_35 ,
T_2 V_27 , T_2 V_36 )
{
struct V_1 * V_2 ;
int V_29 ;
V_2 = F_76 ( V_35 -> V_37 , V_27 ) ;
if ( ! V_2 )
return - V_537 ;
F_59 ( V_2 , 1 ) ;
F_407 ( V_35 , V_2 , V_27 , V_36 , 0 ) ;
V_29 = F_28 ( V_2 , V_27 , V_36 ) ;
F_6 ( V_2 ) ;
return V_29 ;
}
static int F_409 ( struct V_34 * V_35 , T_2 V_32 , T_2 V_36 )
{
int V_29 ;
struct V_1 * V_14 ;
struct V_48 * V_51 ;
V_14 = F_76 ( V_35 -> V_37 , V_32 ) ;
if ( ! V_14 )
return - V_537 ;
F_59 ( V_14 , 0 ) ;
V_51 = F_25 ( V_14 ) ;
if ( ! V_51 ) {
F_32 ( ! F_1 ( V_14 ) ) ;
V_29 = F_28 ( V_14 , V_32 , V_36 ) ;
} else {
F_49 ( & V_51 -> V_85 ) ;
if ( V_32 >= V_51 -> V_84 ) {
V_29 = F_17 ( V_35 , V_32 , V_36 ) ;
} else if ( V_32 + V_36 <= V_51 -> V_84 ) {
V_29 = F_28 ( V_14 ,
V_32 , V_36 ) ;
} else {
V_36 = V_51 -> V_84 - V_32 ;
V_29 = F_28 ( V_14 ,
V_32 , V_36 ) ;
if ( V_29 )
goto V_538;
V_36 = ( V_32 + V_36 ) -
V_51 -> V_84 ;
V_32 = V_51 -> V_84 ;
V_29 = F_17 ( V_35 , V_32 , V_36 ) ;
}
V_538:
F_47 ( & V_51 -> V_85 ) ;
F_26 ( V_51 ) ;
}
F_6 ( V_14 ) ;
return V_29 ;
}
int F_410 ( struct V_34 * log ,
struct V_66 * V_539 )
{
struct V_288 * V_95 ;
struct V_68 V_21 ;
int V_540 ;
int V_42 ;
if ( ! F_84 ( log -> V_37 , V_541 ) )
return 0 ;
for ( V_42 = 0 ; V_42 < F_39 ( V_539 ) ; V_42 ++ ) {
F_41 ( V_539 , & V_21 , V_42 ) ;
if ( V_21 . type != V_293 )
continue;
V_95 = F_86 ( V_539 , V_42 , struct V_288 ) ;
V_540 = F_244 ( V_539 , V_95 ) ;
if ( V_540 == V_294 )
continue;
if ( F_245 ( V_539 , V_95 ) == 0 )
continue;
V_21 . V_22 = F_245 ( V_539 , V_95 ) ;
V_21 . V_33 = F_246 ( V_539 , V_95 ) ;
F_409 ( log , V_21 . V_22 , V_21 . V_33 ) ;
}
return 0 ;
}
static void
F_411 ( struct V_1 * V_334 )
{
F_5 ( & V_334 -> V_542 ) ;
}
void F_412 ( struct V_12 * V_37 ,
const T_2 V_32 )
{
struct V_1 * V_334 ;
V_334 = F_76 ( V_37 , V_32 ) ;
ASSERT ( V_334 ) ;
if ( F_7 ( & V_334 -> V_542 ) )
F_284 ( & V_334 -> V_542 ) ;
F_6 ( V_334 ) ;
}
static int F_413 ( T_7 * V_336 )
{
F_68 () ;
return 0 ;
}
void F_414 ( struct V_1 * V_334 )
{
struct V_110 * V_94 = V_334 -> V_94 ;
ASSERT ( V_334 -> V_305 ) ;
if ( ! ( V_334 -> V_7 & V_337 ) )
return;
F_71 ( & V_94 -> V_351 ) ;
F_73 ( & V_94 -> V_351 ) ;
F_287 ( & V_334 -> V_542 ,
F_413 ,
V_101 ) ;
}
static int F_415 ( struct V_1 * V_2 ,
T_2 V_543 , T_2 V_36 , int V_544 )
{
struct V_110 * V_94 = V_2 -> V_94 ;
int V_29 = 0 ;
F_11 ( & V_94 -> V_50 ) ;
F_11 ( & V_2 -> V_50 ) ;
if ( V_2 -> V_305 ) {
V_29 = - V_186 ;
} else {
V_2 -> V_10 += V_36 ;
V_94 -> V_353 += V_36 ;
F_314 ( V_2 -> V_37 ,
L_11 , V_94 -> V_7 ,
V_543 , 0 ) ;
V_94 -> V_354 -= V_543 ;
if ( V_544 )
V_2 -> V_445 += V_36 ;
}
F_13 ( & V_2 -> V_50 ) ;
F_13 ( & V_94 -> V_50 ) ;
return V_29 ;
}
static int F_416 ( struct V_1 * V_2 ,
T_2 V_36 , int V_544 )
{
struct V_110 * V_94 = V_2 -> V_94 ;
int V_29 = 0 ;
F_11 ( & V_94 -> V_50 ) ;
F_11 ( & V_2 -> V_50 ) ;
if ( V_2 -> V_305 )
V_94 -> V_340 += V_36 ;
V_2 -> V_10 -= V_36 ;
V_94 -> V_353 -= V_36 ;
if ( V_544 )
V_2 -> V_445 -= V_36 ;
F_13 ( & V_2 -> V_50 ) ;
F_13 ( & V_94 -> V_50 ) ;
return V_29 ;
}
void F_417 ( struct V_116 * V_117 ,
struct V_34 * V_35 )
{
struct V_12 * V_37 = V_35 -> V_37 ;
struct V_48 * V_79 ;
struct V_48 * V_51 ;
struct V_1 * V_2 ;
F_71 ( & V_37 -> V_83 ) ;
F_270 (caching_ctl, next,
&fs_info->caching_block_groups, list) {
V_2 = V_51 -> V_14 ;
if ( F_1 ( V_2 ) ) {
V_2 -> V_105 = ( T_2 ) - 1 ;
F_275 ( & V_51 -> V_98 ) ;
F_26 ( V_51 ) ;
} else {
V_2 -> V_105 = V_51 -> V_84 ;
}
}
if ( V_37 -> V_61 == & V_37 -> V_38 [ 0 ] )
V_37 -> V_61 = & V_37 -> V_38 [ 1 ] ;
else
V_37 -> V_61 = & V_37 -> V_38 [ 0 ] ;
F_73 ( & V_37 -> V_83 ) ;
F_379 ( V_37 ) ;
}
static struct V_545 *
F_418 ( struct V_34 * V_35 , struct V_110 * V_94 ,
T_2 * V_546 )
{
struct V_545 * V_29 = NULL ;
bool V_547 = F_264 ( V_35 -> V_37 , V_548 ) ;
* V_546 = 0 ;
if ( F_334 ( V_94 ) )
return V_29 ;
if ( V_547 )
* V_546 = V_415 ;
if ( V_94 -> V_7 & V_53 ) {
V_29 = & V_35 -> V_37 -> V_549 ;
if ( ! V_547 )
* V_546 = V_550 ;
} else if ( ( V_94 -> V_7 & V_337 ) && V_547 ) {
V_29 = & V_35 -> V_37 -> V_551 ;
}
return V_29 ;
}
static int F_419 ( struct V_34 * V_35 , T_2 V_32 , T_2 V_31 ,
const bool V_552 )
{
struct V_12 * V_37 = V_35 -> V_37 ;
struct V_1 * V_2 = NULL ;
struct V_110 * V_94 ;
struct V_260 * V_261 = & V_37 -> V_264 ;
struct V_545 * V_553 = NULL ;
T_2 V_47 ;
T_2 V_554 = 0 ;
T_2 V_546 = 0 ;
bool V_333 ;
while ( V_32 <= V_31 ) {
V_333 = false ;
if ( ! V_2 ||
V_32 >= V_2 -> V_21 . V_22 + V_2 -> V_21 . V_33 ) {
if ( V_2 )
F_6 ( V_2 ) ;
V_554 = 0 ;
V_2 = F_76 ( V_37 , V_32 ) ;
F_32 ( ! V_2 ) ;
V_553 = F_418 ( V_35 ,
V_2 -> V_94 ,
& V_546 ) ;
V_546 <<= 1 ;
}
V_47 = V_2 -> V_21 . V_22 + V_2 -> V_21 . V_33 - V_32 ;
V_47 = F_343 ( V_47 , V_31 + 1 - V_32 ) ;
if ( V_32 < V_2 -> V_105 ) {
V_47 = F_343 ( V_47 , V_2 -> V_105 - V_32 ) ;
if ( V_552 )
F_31 ( V_2 , V_32 , V_47 ) ;
}
V_32 += V_47 ;
V_554 += V_47 ;
V_94 = V_2 -> V_94 ;
if ( V_553 && V_553 -> V_555 &&
V_554 > V_546 ) {
F_11 ( & V_553 -> V_50 ) ;
V_553 -> V_555 = 0 ;
F_13 ( & V_553 -> V_50 ) ;
}
F_11 ( & V_94 -> V_50 ) ;
F_11 ( & V_2 -> V_50 ) ;
V_2 -> V_9 -= V_47 ;
V_94 -> V_352 -= V_47 ;
F_314 ( V_37 , L_18 ,
V_94 -> V_7 , V_47 , 0 ) ;
V_94 -> V_355 = 0 ;
F_420 ( & V_94 -> V_347 , - V_47 ) ;
if ( V_2 -> V_305 ) {
V_94 -> V_340 += V_47 ;
V_333 = true ;
}
F_13 ( & V_2 -> V_50 ) ;
if ( ! V_333 && V_552 &&
V_261 -> V_94 == V_94 ) {
T_2 V_556 = V_47 ;
F_8 ( ! V_552 ) ;
F_11 ( & V_261 -> V_50 ) ;
if ( ! V_261 -> V_115 ) {
V_556 = F_343 ( V_47 , V_261 -> V_59 -
V_261 -> V_10 ) ;
V_261 -> V_10 += V_556 ;
V_94 -> V_354 += V_556 ;
if ( V_261 -> V_10 >= V_261 -> V_59 )
V_261 -> V_115 = 1 ;
F_314 ( V_37 ,
L_11 ,
V_94 -> V_7 ,
V_556 , 1 ) ;
V_47 -= V_556 ;
}
F_13 ( & V_261 -> V_50 ) ;
if ( V_47 )
F_290 ( V_37 , V_94 ,
V_47 ) ;
}
F_13 ( & V_94 -> V_50 ) ;
}
if ( V_2 )
F_6 ( V_2 ) ;
return 0 ;
}
int F_421 ( struct V_116 * V_117 ,
struct V_34 * V_35 )
{
struct V_12 * V_37 = V_35 -> V_37 ;
struct V_1 * V_14 , * V_315 ;
struct V_111 * V_557 ;
struct V_558 * V_559 ;
T_2 V_32 ;
T_2 V_31 ;
int V_29 ;
if ( V_37 -> V_61 == & V_37 -> V_38 [ 0 ] )
V_559 = & V_37 -> V_38 [ 1 ] ;
else
V_559 = & V_37 -> V_38 [ 0 ] ;
while ( ! V_117 -> V_227 ) {
F_49 ( & V_37 -> V_560 ) ;
V_29 = F_30 ( V_559 , 0 , & V_32 , & V_31 ,
V_62 , NULL ) ;
if ( V_29 ) {
F_47 ( & V_37 -> V_560 ) ;
break;
}
if ( F_264 ( V_35 -> V_37 , V_561 ) )
V_29 = F_153 ( V_35 , V_32 ,
V_31 + 1 - V_32 , NULL ) ;
F_422 ( V_559 , V_32 , V_31 ) ;
F_419 ( V_35 , V_32 , V_31 , true ) ;
F_47 ( & V_37 -> V_560 ) ;
F_48 () ;
}
V_557 = & V_117 -> V_134 -> V_557 ;
F_270 (block_group, tmp, deleted_bgs, bg_list) {
T_2 V_562 = 0 ;
V_29 = - V_563 ;
if ( ! V_117 -> V_227 )
V_29 = F_153 ( V_35 ,
V_14 -> V_21 . V_22 ,
V_14 -> V_21 . V_33 ,
& V_562 ) ;
F_275 ( & V_14 -> V_534 ) ;
F_423 ( V_14 ) ;
F_6 ( V_14 ) ;
if ( V_29 ) {
const char * V_564 = F_424 ( V_29 ) ;
F_425 ( V_37 ,
L_19 ,
V_29 , V_564 ) ;
}
}
return 0 ;
}
static void F_426 ( struct V_12 * V_37 , T_2 V_36 ,
T_2 V_140 , T_2 V_152 )
{
struct V_110 * V_94 ;
T_2 V_7 ;
if ( V_140 < V_149 ) {
if ( V_152 == V_565 )
V_7 = V_338 ;
else
V_7 = V_53 ;
} else {
V_7 = V_337 ;
}
V_94 = F_77 ( V_37 , V_7 ) ;
F_32 ( ! V_94 ) ;
F_420 ( & V_94 -> V_347 , V_36 ) ;
}
static int F_167 ( struct V_116 * V_117 ,
struct V_34 * V_35 ,
struct V_218 * V_135 , T_2 V_17 ,
T_2 V_152 , T_2 V_566 ,
T_2 V_567 , int V_167 ,
struct V_188 * V_136 )
{
struct V_68 V_21 ;
struct V_64 * V_65 ;
struct V_12 * V_13 = V_35 -> V_37 ;
struct V_34 * V_63 = V_13 -> V_63 ;
struct V_66 * V_67 ;
struct V_123 * V_124 ;
struct V_171 * V_172 ;
int V_29 ;
int V_192 ;
int V_568 = 0 ;
int V_569 = 0 ;
int V_570 = 1 ;
T_3 V_125 ;
T_2 V_119 ;
T_2 V_27 = V_135 -> V_27 ;
T_2 V_36 = V_135 -> V_36 ;
int V_168 = 0 ;
bool V_181 = F_84 ( V_35 -> V_37 ,
V_128 ) ;
V_65 = F_34 () ;
if ( ! V_65 )
return - V_73 ;
V_65 -> V_76 = V_77 ;
V_65 -> V_219 = 1 ;
V_192 = V_566 >= V_149 ;
F_32 ( ! V_192 && V_167 != 1 ) ;
if ( V_192 )
V_181 = 0 ;
V_29 = F_142 ( V_117 , V_63 , V_65 , & V_172 ,
V_27 , V_36 , V_17 ,
V_152 , V_566 ,
V_567 ) ;
if ( V_29 == 0 ) {
V_568 = V_65 -> V_82 [ 0 ] ;
while ( V_568 >= 0 ) {
F_41 ( V_65 -> V_81 [ 0 ] , & V_21 ,
V_568 ) ;
if ( V_21 . V_22 != V_27 )
break;
if ( V_21 . type == V_78 &&
V_21 . V_33 == V_36 ) {
V_569 = 1 ;
break;
}
if ( V_21 . type == V_86 &&
V_21 . V_33 == V_566 ) {
V_569 = 1 ;
break;
}
if ( V_65 -> V_82 [ 0 ] - V_568 > 5 )
break;
V_568 -- ;
}
#ifdef F_89
V_125 = F_85 ( V_65 -> V_81 [ 0 ] , V_568 ) ;
if ( V_569 && V_125 < sizeof( * V_124 ) )
V_569 = 0 ;
#endif
if ( ! V_569 ) {
F_32 ( V_172 ) ;
V_29 = F_147 ( V_117 , V_63 , V_65 ,
NULL , V_167 ,
V_192 , & V_168 ) ;
if ( V_29 ) {
F_162 ( V_117 , V_29 ) ;
goto V_80;
}
F_45 ( V_65 ) ;
V_65 -> V_219 = 1 ;
V_21 . V_22 = V_27 ;
V_21 . type = V_78 ;
V_21 . V_33 = V_36 ;
if ( ! V_192 && V_181 ) {
V_21 . type = V_86 ;
V_21 . V_33 = V_566 ;
}
V_29 = F_38 ( V_117 , V_63 ,
& V_21 , V_65 , - 1 , 1 ) ;
if ( V_29 > 0 && V_181 && V_65 -> V_82 [ 0 ] ) {
V_65 -> V_82 [ 0 ] -- ;
F_41 ( V_65 -> V_81 [ 0 ] , & V_21 ,
V_65 -> V_82 [ 0 ] ) ;
if ( V_21 . V_22 == V_27 &&
V_21 . type == V_78 &&
V_21 . V_33 == V_36 )
V_29 = 0 ;
}
if ( V_29 > 0 && V_181 ) {
V_181 = false ;
V_21 . V_22 = V_27 ;
V_21 . type = V_78 ;
V_21 . V_33 = V_36 ;
F_45 ( V_65 ) ;
V_29 = F_38 ( V_117 , V_63 ,
& V_21 , V_65 , - 1 , 1 ) ;
}
if ( V_29 ) {
F_173 ( V_13 ,
L_20 ,
V_29 , V_27 ) ;
if ( V_29 > 0 )
F_427 ( V_63 ,
V_65 -> V_81 [ 0 ] ) ;
}
if ( V_29 < 0 ) {
F_162 ( V_117 , V_29 ) ;
goto V_80;
}
V_568 = V_65 -> V_82 [ 0 ] ;
}
} else if ( F_8 ( V_29 == - V_160 ) ) {
F_427 ( V_63 , V_65 -> V_81 [ 0 ] ) ;
F_173 ( V_13 ,
L_21 ,
V_27 , V_17 , V_152 , V_566 ,
V_567 ) ;
F_162 ( V_117 , V_29 ) ;
goto V_80;
} else {
F_162 ( V_117 , V_29 ) ;
goto V_80;
}
V_67 = V_65 -> V_81 [ 0 ] ;
V_125 = F_85 ( V_67 , V_568 ) ;
#ifdef F_89
if ( V_125 < sizeof( * V_124 ) ) {
F_32 ( V_569 || V_568 != V_65 -> V_82 [ 0 ] ) ;
V_29 = F_95 ( V_117 , V_63 , V_65 ,
V_566 , 0 ) ;
if ( V_29 < 0 ) {
F_162 ( V_117 , V_29 ) ;
goto V_80;
}
F_45 ( V_65 ) ;
V_65 -> V_219 = 1 ;
V_21 . V_22 = V_27 ;
V_21 . type = V_78 ;
V_21 . V_33 = V_36 ;
V_29 = F_38 ( V_117 , V_63 , & V_21 , V_65 ,
- 1 , 1 ) ;
if ( V_29 ) {
F_173 ( V_13 ,
L_20 ,
V_29 , V_27 ) ;
F_427 ( V_63 , V_65 -> V_81 [ 0 ] ) ;
}
if ( V_29 < 0 ) {
F_162 ( V_117 , V_29 ) ;
goto V_80;
}
V_568 = V_65 -> V_82 [ 0 ] ;
V_67 = V_65 -> V_81 [ 0 ] ;
V_125 = F_85 ( V_67 , V_568 ) ;
}
#endif
F_32 ( V_125 < sizeof( * V_124 ) ) ;
V_124 = F_86 ( V_67 , V_568 ,
struct V_123 ) ;
if ( V_566 < V_149 &&
V_21 . type == V_78 ) {
struct V_144 * V_145 ;
F_32 ( V_125 < sizeof( * V_124 ) + sizeof( * V_145 ) ) ;
V_145 = (struct V_144 * ) ( V_124 + 1 ) ;
F_8 ( V_566 != F_428 ( V_67 , V_145 ) ) ;
}
V_119 = F_87 ( V_67 , V_124 ) ;
if ( V_119 < V_167 ) {
F_173 ( V_13 ,
L_22 ,
V_167 , V_119 , V_27 ) ;
V_29 = - V_537 ;
F_162 ( V_117 , V_29 ) ;
goto V_80;
}
V_119 -= V_167 ;
if ( V_119 > 0 ) {
if ( V_136 )
F_138 ( V_136 , V_67 , V_124 ) ;
if ( V_172 ) {
F_32 ( ! V_569 ) ;
} else {
F_98 ( V_67 , V_124 , V_119 ) ;
F_103 ( V_67 ) ;
}
if ( V_569 ) {
V_29 = F_147 ( V_117 , V_63 , V_65 ,
V_172 , V_167 ,
V_192 , & V_168 ) ;
if ( V_29 ) {
F_162 ( V_117 , V_29 ) ;
goto V_80;
}
}
F_426 ( V_35 -> V_37 , - V_36 , V_566 ,
V_152 ) ;
} else {
if ( V_569 ) {
F_32 ( V_192 && V_167 !=
F_126 ( V_65 , V_172 ) ) ;
if ( V_172 ) {
F_32 ( V_65 -> V_82 [ 0 ] != V_568 ) ;
} else {
F_32 ( V_65 -> V_82 [ 0 ] != V_568 + 1 ) ;
V_65 -> V_82 [ 0 ] = V_568 ;
V_570 = 2 ;
}
}
V_168 = 1 ;
V_29 = F_429 ( V_117 , V_63 , V_65 , V_65 -> V_82 [ 0 ] ,
V_570 ) ;
if ( V_29 ) {
F_162 ( V_117 , V_29 ) ;
goto V_80;
}
F_45 ( V_65 ) ;
if ( V_192 ) {
V_29 = F_180 ( V_117 , V_35 , V_27 , V_36 ) ;
if ( V_29 ) {
F_162 ( V_117 , V_29 ) ;
goto V_80;
}
}
V_29 = F_430 ( V_117 , V_35 -> V_37 , V_27 ,
V_36 ) ;
if ( V_29 ) {
F_162 ( V_117 , V_29 ) ;
goto V_80;
}
V_29 = F_402 ( V_117 , V_35 , V_27 , V_36 , 0 ) ;
if ( V_29 ) {
F_162 ( V_117 , V_29 ) ;
goto V_80;
}
}
F_45 ( V_65 ) ;
V_80:
F_53 ( V_65 ) ;
return V_29 ;
}
static T_1 int F_431 ( struct V_116 * V_117 ,
struct V_34 * V_35 , T_2 V_27 )
{
struct V_120 * V_112 ;
struct V_121 * V_122 ;
int V_29 = 0 ;
V_122 = & V_117 -> V_134 -> V_122 ;
F_11 ( & V_122 -> V_50 ) ;
V_112 = F_92 ( V_117 , V_27 ) ;
if ( ! V_112 )
goto V_571;
F_11 ( & V_112 -> V_50 ) ;
if ( ! F_183 ( & V_112 -> V_231 ) )
goto V_80;
if ( V_112 -> V_136 ) {
if ( ! V_112 -> V_234 )
goto V_80;
F_193 ( V_112 -> V_136 ) ;
V_112 -> V_136 = NULL ;
}
if ( ! F_93 ( & V_112 -> V_85 ) )
goto V_80;
V_112 -> V_135 . V_238 = 0 ;
F_195 ( & V_112 -> V_240 , & V_122 -> V_241 ) ;
F_197 ( & V_122 -> V_242 ) ;
V_122 -> V_239 -- ;
if ( V_112 -> V_236 == 0 )
V_122 -> V_237 -- ;
V_112 -> V_236 = 0 ;
F_13 ( & V_112 -> V_50 ) ;
F_13 ( & V_122 -> V_50 ) ;
F_32 ( V_112 -> V_136 ) ;
if ( V_112 -> V_234 )
V_29 = 1 ;
F_47 ( & V_112 -> V_85 ) ;
F_94 ( & V_112 -> V_135 ) ;
return V_29 ;
V_80:
F_13 ( & V_112 -> V_50 ) ;
V_571:
F_13 ( & V_122 -> V_50 ) ;
return 0 ;
}
void F_432 ( struct V_116 * V_117 ,
struct V_34 * V_35 ,
struct V_66 * V_285 ,
T_2 V_17 , int V_168 )
{
int V_572 = 1 ;
int V_29 ;
if ( V_35 -> V_281 . V_22 != V_216 ) {
V_29 = F_159 ( V_35 -> V_37 , V_117 ,
V_285 -> V_32 , V_285 -> V_47 ,
V_17 , V_35 -> V_281 . V_22 ,
F_243 ( V_285 ) ,
V_225 , NULL ) ;
F_32 ( V_29 ) ;
}
if ( ! V_168 )
return;
if ( F_433 ( V_285 ) == V_117 -> V_272 ) {
struct V_1 * V_2 ;
if ( V_35 -> V_281 . V_22 != V_216 ) {
V_29 = F_431 ( V_117 , V_35 , V_285 -> V_32 ) ;
if ( ! V_29 )
goto V_80;
}
V_2 = F_76 ( V_35 -> V_37 , V_285 -> V_32 ) ;
if ( F_434 ( V_285 , V_573 ) ) {
F_407 ( V_35 , V_2 , V_285 -> V_32 , V_285 -> V_47 , 1 ) ;
F_6 ( V_2 ) ;
goto V_80;
}
F_8 ( F_226 ( V_574 , & V_285 -> V_575 ) ) ;
F_31 ( V_2 , V_285 -> V_32 , V_285 -> V_47 ) ;
F_416 ( V_2 , V_285 -> V_47 , 0 ) ;
F_6 ( V_2 ) ;
F_435 ( V_35 , V_285 -> V_32 , V_285 -> V_47 ) ;
V_572 = 0 ;
}
V_80:
if ( V_572 )
F_426 ( V_35 -> V_37 , V_285 -> V_47 ,
F_243 ( V_285 ) ,
V_35 -> V_281 . V_22 ) ;
F_436 ( V_576 , & V_285 -> V_575 ) ;
}
int V_292 ( struct V_116 * V_117 , struct V_34 * V_35 ,
T_2 V_27 , T_2 V_36 , T_2 V_17 , T_2 V_152 ,
T_2 V_140 , T_2 V_33 )
{
int V_29 ;
struct V_12 * V_37 = V_35 -> V_37 ;
if ( F_241 ( V_37 ) )
return 0 ;
F_426 ( V_35 -> V_37 , V_36 , V_140 , V_152 ) ;
if ( V_152 == V_216 ) {
F_8 ( V_140 >= V_149 ) ;
F_176 ( V_35 , V_27 , V_36 , 1 ) ;
V_29 = 0 ;
} else if ( V_140 < V_149 ) {
V_29 = F_159 ( V_37 , V_117 , V_27 ,
V_36 ,
V_17 , V_152 , ( int ) V_140 ,
V_225 , NULL ) ;
} else {
V_29 = F_160 ( V_37 , V_117 , V_27 ,
V_36 ,
V_17 , V_152 , V_140 ,
V_33 , 0 ,
V_225 , NULL ) ;
}
return V_29 ;
}
static T_1 void
F_437 ( struct V_1 * V_2 ,
T_2 V_36 )
{
struct V_48 * V_51 ;
V_51 = F_25 ( V_2 ) ;
if ( ! V_51 )
return;
F_280 ( V_51 -> V_89 , F_1 ( V_2 ) ||
( V_2 -> V_11 -> V_577 >= V_36 ) ) ;
F_26 ( V_51 ) ;
}
static T_1 int
F_438 ( struct V_1 * V_2 )
{
struct V_48 * V_51 ;
int V_29 = 0 ;
V_51 = F_25 ( V_2 ) ;
if ( ! V_51 )
return ( V_2 -> V_3 == V_5 ) ? - V_183 : 0 ;
F_280 ( V_51 -> V_89 , F_1 ( V_2 ) ) ;
if ( V_2 -> V_3 == V_5 )
V_29 = - V_183 ;
F_26 ( V_51 ) ;
return V_29 ;
}
int F_439 ( T_2 V_7 )
{
if ( V_7 & V_344 )
return V_578 ;
else if ( V_7 & V_343 )
return V_579 ;
else if ( V_7 & V_342 )
return V_580 ;
else if ( V_7 & V_392 )
return V_581 ;
else if ( V_7 & V_391 )
return V_582 ;
else if ( V_7 & V_390 )
return V_583 ;
return V_584 ;
}
int F_440 ( struct V_1 * V_2 )
{
return F_439 ( V_2 -> V_7 ) ;
}
static const char * F_441 ( enum V_585 type )
{
if ( type >= V_349 )
return NULL ;
return V_586 [ type ] ;
}
static inline void
F_442 ( struct V_1 * V_2 ,
int V_544 )
{
if ( V_544 )
F_50 ( & V_2 -> V_587 ) ;
}
static inline void
F_443 ( struct V_1 * V_2 ,
int V_544 )
{
F_4 ( V_2 ) ;
if ( V_544 )
F_50 ( & V_2 -> V_587 ) ;
}
static struct V_1 *
F_444 ( struct V_1 * V_14 ,
struct V_545 * V_553 ,
int V_544 )
{
struct V_1 * V_588 = NULL ;
F_11 ( & V_553 -> V_589 ) ;
while ( 1 ) {
V_588 = V_553 -> V_14 ;
if ( ! V_588 )
return NULL ;
if ( V_588 == V_14 )
return V_588 ;
F_4 ( V_588 ) ;
if ( ! V_544 )
return V_588 ;
if ( F_338 ( & V_588 -> V_587 ) )
return V_588 ;
F_13 ( & V_553 -> V_589 ) ;
F_50 ( & V_588 -> V_587 ) ;
F_11 ( & V_553 -> V_589 ) ;
if ( V_588 == V_553 -> V_14 )
return V_588 ;
F_46 ( & V_588 -> V_587 ) ;
F_6 ( V_588 ) ;
}
}
static inline void
F_445 ( struct V_1 * V_2 ,
int V_544 )
{
if ( V_544 )
F_46 ( & V_2 -> V_587 ) ;
F_6 ( V_2 ) ;
}
static T_1 int F_446 ( struct V_34 * V_590 ,
T_2 V_543 , T_2 V_36 , T_2 V_591 ,
T_2 V_592 , struct V_68 * V_222 ,
T_2 V_7 , int V_544 )
{
int V_29 = 0 ;
struct V_34 * V_35 = V_590 -> V_37 -> V_63 ;
struct V_545 * V_593 = NULL ;
struct V_1 * V_14 = NULL ;
T_2 V_536 = 0 ;
T_2 V_355 = 0 ;
T_2 V_546 = 0 ;
struct V_110 * V_94 ;
int V_594 = 0 ;
int V_595 = F_439 ( V_7 ) ;
bool V_596 = false ;
bool V_597 = false ;
bool V_598 = true ;
bool V_599 = false ;
bool V_600 = false ;
bool V_601 = false ;
F_8 ( V_36 < V_35 -> V_55 ) ;
V_222 -> type = V_78 ;
V_222 -> V_22 = 0 ;
V_222 -> V_33 = 0 ;
F_447 ( V_590 , V_36 , V_591 , V_7 ) ;
V_94 = F_77 ( V_35 -> V_37 , V_7 ) ;
if ( ! V_94 ) {
F_173 ( V_35 -> V_37 , L_23 , V_7 ) ;
return - V_312 ;
}
if ( F_364 ( V_94 -> V_355 ) ) {
F_11 ( & V_94 -> V_50 ) ;
if ( V_94 -> V_355 &&
V_36 > V_94 -> V_355 ) {
V_222 -> V_33 = V_94 -> V_355 ;
F_13 ( & V_94 -> V_50 ) ;
return - V_312 ;
} else if ( V_94 -> V_355 ) {
V_598 = false ;
}
F_13 ( & V_94 -> V_50 ) ;
}
V_593 = F_418 ( V_590 , V_94 , & V_546 ) ;
if ( V_593 ) {
F_11 ( & V_593 -> V_50 ) ;
if ( V_593 -> V_14 )
V_592 = V_593 -> V_602 ;
if ( V_593 -> V_555 ) {
V_592 = V_593 -> V_602 ;
V_598 = false ;
}
F_13 ( & V_593 -> V_50 ) ;
}
V_536 = F_448 ( V_536 , V_26 ( V_35 , 0 ) ) ;
V_536 = F_448 ( V_536 , V_592 ) ;
if ( V_536 == V_592 ) {
V_14 = F_76 ( V_35 -> V_37 ,
V_536 ) ;
if ( V_14 && F_3 ( V_14 , V_7 ) &&
V_14 -> V_3 != V_102 ) {
F_50 ( & V_94 -> V_351 ) ;
if ( F_183 ( & V_14 -> V_98 ) ||
V_14 -> V_305 ) {
F_6 ( V_14 ) ;
F_46 ( & V_94 -> V_351 ) ;
} else {
V_595 = F_440 ( V_14 ) ;
F_442 ( V_14 , V_544 ) ;
goto V_603;
}
} else if ( V_14 ) {
F_6 ( V_14 ) ;
}
}
V_604:
V_599 = false ;
if ( V_595 == 0 || V_595 == F_439 ( V_7 ) )
V_601 = true ;
F_50 ( & V_94 -> V_351 ) ;
F_184 (block_group, &space_info->block_groups[index],
list) {
T_2 V_33 ;
int V_3 ;
F_443 ( V_14 , V_544 ) ;
V_536 = V_14 -> V_21 . V_22 ;
if ( ! F_3 ( V_14 , V_7 ) ) {
T_2 V_605 = V_342 |
V_343 |
V_391 |
V_390 |
V_344 ;
if ( ( V_7 & V_605 ) && ! ( V_14 -> V_7 & V_605 ) )
goto V_594;
}
V_603:
V_3 = F_1 ( V_14 ) ;
if ( F_364 ( ! V_3 ) ) {
V_599 = true ;
V_29 = F_59 ( V_14 , 0 ) ;
F_32 ( V_29 < 0 ) ;
V_29 = 0 ;
}
if ( F_364 ( V_14 -> V_3 == V_5 ) )
goto V_594;
if ( F_364 ( V_14 -> V_305 ) )
goto V_594;
if ( V_593 && V_598 ) {
struct V_1 * V_606 ;
unsigned long V_607 ;
V_606 = F_444 ( V_14 ,
V_593 ,
V_544 ) ;
if ( ! V_606 )
goto V_608;
if ( V_606 != V_14 &&
( V_606 -> V_305 ||
! F_3 ( V_606 , V_7 ) ) )
goto V_609;
V_33 = F_449 ( V_606 ,
V_593 ,
V_36 ,
V_606 -> V_21 . V_22 ,
& V_355 ) ;
if ( V_33 ) {
F_13 ( & V_593 -> V_589 ) ;
F_450 ( V_35 ,
V_606 ,
V_536 , V_36 ) ;
if ( V_606 != V_14 ) {
F_445 ( V_14 ,
V_544 ) ;
V_14 = V_606 ;
}
goto V_610;
}
F_8 ( V_593 -> V_14 != V_606 ) ;
V_609:
if ( V_594 >= V_611 &&
V_606 != V_14 ) {
F_13 ( & V_593 -> V_589 ) ;
F_445 ( V_606 ,
V_544 ) ;
goto V_612;
}
F_451 ( NULL , V_593 ) ;
if ( V_606 != V_14 )
F_445 ( V_606 ,
V_544 ) ;
V_608:
if ( V_594 >= V_611 ) {
F_13 ( & V_593 -> V_589 ) ;
goto V_612;
}
V_607 = F_35 (unsigned long,
empty_cluster + empty_size,
block_group->full_stripe_len) ;
V_29 = F_452 ( V_35 , V_14 ,
V_593 , V_536 ,
V_36 ,
V_607 ) ;
if ( V_29 == 0 ) {
V_33 = F_449 ( V_14 ,
V_593 ,
V_36 ,
V_536 ,
& V_355 ) ;
if ( V_33 ) {
F_13 ( & V_593 -> V_589 ) ;
F_450 ( V_35 ,
V_14 , V_536 ,
V_36 ) ;
goto V_610;
}
} else if ( ! V_3 && V_594 > V_613
&& ! V_596 ) {
F_13 ( & V_593 -> V_589 ) ;
V_596 = true ;
F_437 ( V_14 ,
V_36 + V_546 + V_591 ) ;
goto V_603;
}
F_451 ( NULL , V_593 ) ;
F_13 ( & V_593 -> V_589 ) ;
goto V_594;
}
V_612:
if ( F_364 ( V_593 ) ) {
F_11 ( & V_593 -> V_50 ) ;
V_593 -> V_555 = 1 ;
F_13 ( & V_593 -> V_50 ) ;
}
F_11 ( & V_14 -> V_11 -> V_614 ) ;
if ( V_3 &&
V_14 -> V_11 -> V_577 <
V_36 + V_546 + V_591 ) {
if ( V_14 -> V_11 -> V_577 >
V_355 )
V_355 =
V_14 -> V_11 -> V_577 ;
F_13 ( & V_14 -> V_11 -> V_614 ) ;
goto V_594;
}
F_13 ( & V_14 -> V_11 -> V_614 ) ;
V_33 = F_453 ( V_14 , V_536 ,
V_36 , V_591 ,
& V_355 ) ;
if ( ! V_33 && ! V_597 && ! V_3 &&
V_594 > V_613 ) {
F_437 ( V_14 ,
V_36 + V_591 ) ;
V_597 = true ;
goto V_603;
} else if ( ! V_33 ) {
goto V_594;
}
V_610:
V_536 = F_149 ( V_33 , V_35 -> V_615 ) ;
if ( V_536 + V_36 >
V_14 -> V_21 . V_22 + V_14 -> V_21 . V_33 ) {
F_31 ( V_14 , V_33 , V_36 ) ;
goto V_594;
}
if ( V_33 < V_536 )
F_31 ( V_14 , V_33 ,
V_536 - V_33 ) ;
F_32 ( V_33 > V_536 ) ;
V_29 = F_415 ( V_14 , V_543 ,
V_36 , V_544 ) ;
if ( V_29 == - V_186 ) {
F_31 ( V_14 , V_33 , V_36 ) ;
goto V_594;
}
F_411 ( V_14 ) ;
V_222 -> V_22 = V_536 ;
V_222 -> V_33 = V_36 ;
F_454 ( V_590 , V_14 ,
V_536 , V_36 ) ;
F_445 ( V_14 , V_544 ) ;
break;
V_594:
V_596 = false ;
V_597 = false ;
F_32 ( V_595 != F_440 ( V_14 ) ) ;
F_445 ( V_14 , V_544 ) ;
}
F_46 ( & V_94 -> V_351 ) ;
if ( ( V_594 == V_613 ) && V_599
&& ! V_600 )
V_600 = true ;
if ( ! V_222 -> V_22 && V_594 >= V_616 && V_599 )
goto V_604;
if ( ! V_222 -> V_22 && ++ V_595 < V_349 )
goto V_604;
if ( ! V_222 -> V_22 && V_594 < V_611 ) {
V_595 = 0 ;
if ( V_594 == V_613 ) {
if ( V_600 || ! V_601 )
V_594 = V_616 ;
else
V_594 = V_617 ;
} else {
V_594 ++ ;
}
if ( V_594 == V_617 ) {
struct V_116 * V_117 ;
int V_618 = 0 ;
V_117 = V_399 -> V_400 ;
if ( V_117 )
V_618 = 1 ;
else
V_117 = F_216 ( V_35 ) ;
if ( F_217 ( V_117 ) ) {
V_29 = F_218 ( V_117 ) ;
goto V_80;
}
V_29 = F_309 ( V_117 , V_35 , V_7 ,
V_403 ) ;
if ( V_29 == - V_312 )
V_594 = V_611 ;
if ( V_29 < 0 && V_29 != - V_312 )
F_162 ( V_117 , V_29 ) ;
else
V_29 = 0 ;
if ( ! V_618 )
F_220 ( V_117 , V_35 ) ;
if ( V_29 )
goto V_80;
}
if ( V_594 == V_611 ) {
if ( V_591 == 0 &&
V_546 == 0 ) {
V_29 = - V_312 ;
goto V_80;
}
V_591 = 0 ;
V_546 = 0 ;
}
goto V_604;
} else if ( ! V_222 -> V_22 ) {
V_29 = - V_312 ;
} else if ( V_222 -> V_22 ) {
if ( ! V_598 && V_593 ) {
F_11 ( & V_593 -> V_50 ) ;
V_593 -> V_602 = V_222 -> V_22 ;
F_13 ( & V_593 -> V_50 ) ;
}
V_29 = 0 ;
}
V_80:
if ( V_29 == - V_312 ) {
F_11 ( & V_94 -> V_50 ) ;
V_94 -> V_355 = V_355 ;
F_13 ( & V_94 -> V_50 ) ;
V_222 -> V_33 = V_355 ;
}
return V_29 ;
}
static void F_331 ( struct V_12 * V_37 ,
struct V_110 * V_13 , T_2 V_211 ,
int V_619 )
{
struct V_1 * V_2 ;
int V_595 = 0 ;
F_11 ( & V_13 -> V_50 ) ;
F_330 ( V_37 , L_24 ,
V_13 -> V_7 ,
V_13 -> V_339 - V_13 -> V_93 - V_13 -> V_352 -
V_13 -> V_353 - V_13 -> V_340 -
V_13 -> V_354 , ( V_13 -> V_115 ) ? L_25 : L_26 ) ;
F_330 ( V_37 ,
L_27 ,
V_13 -> V_339 , V_13 -> V_93 , V_13 -> V_352 ,
V_13 -> V_353 , V_13 -> V_354 ,
V_13 -> V_340 ) ;
F_13 ( & V_13 -> V_50 ) ;
if ( ! V_619 )
return;
F_50 ( & V_13 -> V_351 ) ;
V_163:
F_184 (cache, &info->block_groups[index], list) {
F_11 ( & V_2 -> V_50 ) ;
F_330 ( V_37 ,
L_28 ,
V_2 -> V_21 . V_22 , V_2 -> V_21 . V_33 ,
F_58 ( & V_2 -> V_95 ) , V_2 -> V_9 ,
V_2 -> V_10 , V_2 -> V_305 ? L_29 : L_25 ) ;
F_455 ( V_2 , V_211 ) ;
F_13 ( & V_2 -> V_50 ) ;
}
if ( ++ V_595 < V_349 )
goto V_163;
F_46 ( & V_13 -> V_351 ) ;
}
int F_456 ( struct V_34 * V_35 , T_2 V_543 ,
T_2 V_36 , T_2 V_620 ,
T_2 V_591 , T_2 V_592 ,
struct V_68 * V_222 , int V_192 , int V_544 )
{
struct V_12 * V_37 = V_35 -> V_37 ;
bool V_621 = V_36 == V_620 ;
T_2 V_7 ;
int V_29 ;
V_7 = F_306 ( V_35 , V_192 ) ;
V_163:
F_8 ( V_36 < V_35 -> V_55 ) ;
V_29 = F_446 ( V_35 , V_543 , V_36 , V_591 ,
V_592 , V_222 , V_7 , V_544 ) ;
if ( ! V_29 && ! V_192 ) {
F_412 ( V_37 , V_222 -> V_22 ) ;
} else if ( V_29 == - V_312 ) {
if ( ! V_621 && V_222 -> V_33 ) {
V_36 = F_343 ( V_36 >> 1 , V_222 -> V_33 ) ;
V_36 = F_150 ( V_36 , V_35 -> V_55 ) ;
V_36 = F_448 ( V_36 , V_620 ) ;
V_543 = V_36 ;
if ( V_36 == V_620 )
V_621 = true ;
goto V_163;
} else if ( F_264 ( V_37 , V_420 ) ) {
struct V_110 * V_409 ;
V_409 = F_77 ( V_37 , V_7 ) ;
F_173 ( V_35 -> V_37 ,
L_30 ,
V_7 , V_36 ) ;
if ( V_409 )
F_331 ( V_37 , V_409 , V_36 , 1 ) ;
}
}
return V_29 ;
}
static int F_457 ( struct V_34 * V_35 ,
T_2 V_32 , T_2 V_47 ,
int V_572 , int V_544 )
{
struct V_1 * V_2 ;
int V_29 = 0 ;
V_2 = F_76 ( V_35 -> V_37 , V_32 ) ;
if ( ! V_2 ) {
F_173 ( V_35 -> V_37 , L_31 ,
V_32 ) ;
return - V_312 ;
}
if ( V_572 )
F_407 ( V_35 , V_2 , V_32 , V_47 , 1 ) ;
else {
if ( F_264 ( V_35 -> V_37 , V_561 ) )
V_29 = F_153 ( V_35 , V_32 , V_47 , NULL ) ;
F_31 ( V_2 , V_32 , V_47 ) ;
F_416 ( V_2 , V_47 , V_544 ) ;
F_435 ( V_35 , V_32 , V_47 ) ;
}
F_6 ( V_2 ) ;
return V_29 ;
}
int F_458 ( struct V_34 * V_35 ,
T_2 V_32 , T_2 V_47 , int V_544 )
{
return F_457 ( V_35 , V_32 , V_47 , 0 , V_544 ) ;
}
int F_459 ( struct V_34 * V_35 ,
T_2 V_32 , T_2 V_47 )
{
return F_457 ( V_35 , V_32 , V_47 , 1 , 0 ) ;
}
static int F_166 ( struct V_116 * V_117 ,
struct V_34 * V_35 ,
T_2 V_17 , T_2 V_152 ,
T_2 V_7 , T_2 V_140 , T_2 V_33 ,
struct V_68 * V_222 , int V_139 )
{
int V_29 ;
struct V_12 * V_37 = V_35 -> V_37 ;
struct V_123 * V_622 ;
struct V_171 * V_172 ;
struct V_64 * V_65 ;
struct V_66 * V_67 ;
int type ;
T_3 V_59 ;
if ( V_17 > 0 )
type = V_161 ;
else
type = V_162 ;
V_59 = sizeof( * V_622 ) + F_133 ( type ) ;
V_65 = F_34 () ;
if ( ! V_65 )
return - V_73 ;
V_65 -> V_219 = 1 ;
V_29 = F_114 ( V_117 , V_37 -> V_63 , V_65 ,
V_222 , V_59 ) ;
if ( V_29 ) {
F_53 ( V_65 ) ;
return V_29 ;
}
V_67 = V_65 -> V_81 [ 0 ] ;
V_622 = F_86 ( V_67 , V_65 -> V_82 [ 0 ] ,
struct V_123 ) ;
F_98 ( V_67 , V_622 , V_139 ) ;
F_99 ( V_67 , V_622 , V_117 -> V_272 ) ;
F_100 ( V_67 , V_622 ,
V_7 | V_151 ) ;
V_172 = (struct V_171 * ) ( V_622 + 1 ) ;
F_140 ( V_67 , V_172 , type ) ;
if ( V_17 > 0 ) {
struct V_166 * V_157 ;
V_157 = (struct V_166 * ) ( V_172 + 1 ) ;
F_141 ( V_67 , V_172 , V_17 ) ;
F_115 ( V_67 , V_157 , V_139 ) ;
} else {
struct V_156 * V_157 ;
V_157 = (struct V_156 * ) ( & V_172 -> V_33 ) ;
F_117 ( V_67 , V_157 , V_152 ) ;
F_118 ( V_67 , V_157 , V_140 ) ;
F_119 ( V_67 , V_157 , V_33 ) ;
F_120 ( V_67 , V_157 , V_139 ) ;
}
F_103 ( V_65 -> V_81 [ 0 ] ) ;
F_53 ( V_65 ) ;
V_29 = F_460 ( V_117 , V_37 , V_222 -> V_22 ,
V_222 -> V_33 ) ;
if ( V_29 )
return V_29 ;
V_29 = F_402 ( V_117 , V_35 , V_222 -> V_22 , V_222 -> V_33 , 1 ) ;
if ( V_29 ) {
F_173 ( V_37 , L_32 ,
V_222 -> V_22 , V_222 -> V_33 ) ;
F_91 () ;
}
F_461 ( V_35 , V_222 -> V_22 , V_222 -> V_33 ) ;
return V_29 ;
}
static int F_174 ( struct V_116 * V_117 ,
struct V_34 * V_35 ,
T_2 V_17 , T_2 V_152 ,
T_2 V_7 , struct V_623 * V_21 ,
int V_175 , struct V_68 * V_222 )
{
int V_29 ;
struct V_12 * V_37 = V_35 -> V_37 ;
struct V_123 * V_622 ;
struct V_144 * V_624 ;
struct V_171 * V_172 ;
struct V_64 * V_65 ;
struct V_66 * V_67 ;
T_3 V_59 = sizeof( * V_622 ) + sizeof( * V_172 ) ;
T_2 V_36 = V_222 -> V_33 ;
bool V_181 = F_84 ( V_35 -> V_37 ,
V_128 ) ;
if ( ! V_181 )
V_59 += sizeof( * V_624 ) ;
V_65 = F_34 () ;
if ( ! V_65 ) {
F_459 ( V_35 , V_222 -> V_22 ,
V_35 -> V_54 ) ;
return - V_73 ;
}
V_65 -> V_219 = 1 ;
V_29 = F_114 ( V_117 , V_37 -> V_63 , V_65 ,
V_222 , V_59 ) ;
if ( V_29 ) {
F_53 ( V_65 ) ;
F_459 ( V_35 , V_222 -> V_22 ,
V_35 -> V_54 ) ;
return V_29 ;
}
V_67 = V_65 -> V_81 [ 0 ] ;
V_622 = F_86 ( V_67 , V_65 -> V_82 [ 0 ] ,
struct V_123 ) ;
F_98 ( V_67 , V_622 , 1 ) ;
F_99 ( V_67 , V_622 , V_117 -> V_272 ) ;
F_100 ( V_67 , V_622 ,
V_7 | V_150 ) ;
if ( V_181 ) {
V_172 = (struct V_171 * ) ( V_622 + 1 ) ;
V_36 = V_35 -> V_54 ;
} else {
V_624 = (struct V_144 * ) ( V_622 + 1 ) ;
F_168 ( V_67 , V_624 , V_21 ) ;
F_102 ( V_67 , V_624 , V_175 ) ;
V_172 = (struct V_171 * ) ( V_624 + 1 ) ;
}
if ( V_17 > 0 ) {
F_32 ( ! ( V_7 & V_133 ) ) ;
F_140 ( V_67 , V_172 ,
V_173 ) ;
F_141 ( V_67 , V_172 , V_17 ) ;
} else {
F_140 ( V_67 , V_172 ,
V_174 ) ;
F_141 ( V_67 , V_172 , V_152 ) ;
}
F_103 ( V_67 ) ;
F_53 ( V_65 ) ;
V_29 = F_460 ( V_117 , V_37 , V_222 -> V_22 ,
V_36 ) ;
if ( V_29 )
return V_29 ;
V_29 = F_402 ( V_117 , V_35 , V_222 -> V_22 , V_35 -> V_54 ,
1 ) ;
if ( V_29 ) {
F_173 ( V_37 , L_32 ,
V_222 -> V_22 , V_222 -> V_33 ) ;
F_91 () ;
}
F_461 ( V_35 , V_222 -> V_22 , V_35 -> V_54 ) ;
return V_29 ;
}
int F_462 ( struct V_116 * V_117 ,
struct V_34 * V_35 ,
T_2 V_152 , T_2 V_140 ,
T_2 V_33 , T_2 V_543 ,
struct V_68 * V_222 )
{
int V_29 ;
F_32 ( V_152 == V_216 ) ;
V_29 = F_160 ( V_35 -> V_37 , V_117 , V_222 -> V_22 ,
V_222 -> V_33 , 0 ,
V_152 , V_140 , V_33 ,
V_543 , V_243 ,
NULL ) ;
return V_29 ;
}
int F_463 ( struct V_116 * V_117 ,
struct V_34 * V_35 ,
T_2 V_152 , T_2 V_140 , T_2 V_33 ,
struct V_68 * V_222 )
{
int V_29 ;
struct V_1 * V_14 ;
struct V_110 * V_94 ;
if ( ! F_84 ( V_35 -> V_37 , V_541 ) ) {
V_29 = F_409 ( V_35 , V_222 -> V_22 , V_222 -> V_33 ) ;
if ( V_29 )
return V_29 ;
}
V_14 = F_76 ( V_35 -> V_37 , V_222 -> V_22 ) ;
if ( ! V_14 )
return - V_537 ;
V_94 = V_14 -> V_94 ;
F_11 ( & V_94 -> V_50 ) ;
F_11 ( & V_14 -> V_50 ) ;
V_94 -> V_353 += V_222 -> V_33 ;
V_14 -> V_10 += V_222 -> V_33 ;
F_13 ( & V_14 -> V_50 ) ;
F_13 ( & V_94 -> V_50 ) ;
V_29 = F_166 ( V_117 , V_35 , 0 , V_152 ,
0 , V_140 , V_33 , V_222 , 1 ) ;
F_6 ( V_14 ) ;
return V_29 ;
}
static struct V_66 *
F_464 ( struct V_116 * V_117 , struct V_34 * V_35 ,
T_2 V_27 , int V_175 )
{
struct V_66 * V_285 ;
V_285 = F_465 ( V_35 , V_27 ) ;
if ( F_217 ( V_285 ) )
return V_285 ;
F_466 ( V_285 , V_117 -> V_272 ) ;
F_467 ( V_35 -> V_281 . V_22 , V_285 , V_175 ) ;
F_468 ( V_285 ) ;
F_469 ( V_117 , V_35 -> V_37 , V_285 ) ;
F_436 ( V_625 , & V_285 -> V_575 ) ;
F_470 ( V_285 ) ;
F_471 ( V_285 ) ;
if ( V_35 -> V_281 . V_22 == V_216 ) {
V_285 -> V_626 = V_35 -> V_627 % 2 ;
if ( V_285 -> V_626 == 0 )
F_406 ( & V_35 -> V_628 , V_285 -> V_32 ,
V_285 -> V_32 + V_285 -> V_47 - 1 , V_97 ) ;
else
F_472 ( & V_35 -> V_628 , V_285 -> V_32 ,
V_285 -> V_32 + V_285 -> V_47 - 1 ) ;
} else {
V_285 -> V_626 = - 1 ;
F_406 ( & V_117 -> V_134 -> V_629 , V_285 -> V_32 ,
V_285 -> V_32 + V_285 -> V_47 - 1 , V_97 ) ;
}
V_117 -> V_321 = true ;
return V_285 ;
}
static struct V_260 *
F_473 ( struct V_116 * V_117 ,
struct V_34 * V_35 , T_3 V_630 )
{
struct V_260 * V_444 ;
struct V_260 * V_261 = & V_35 -> V_37 -> V_264 ;
int V_29 ;
bool V_631 = false ;
V_444 = F_366 ( V_117 , V_35 ) ;
if ( F_364 ( V_444 -> V_59 == 0 ) )
goto V_632;
V_163:
V_29 = F_365 ( V_444 , V_630 ) ;
if ( ! V_29 )
return V_444 ;
if ( V_444 -> V_633 )
return F_474 ( V_29 ) ;
if ( V_444 -> type == V_634 && ! V_631 ) {
V_631 = true ;
F_379 ( V_35 -> V_37 ) ;
goto V_163;
}
if ( F_264 ( V_35 -> V_37 , V_420 ) ) {
static F_475 ( V_635 ,
V_636 * 10 ,
1 ) ;
if ( F_476 ( & V_635 ) )
F_477 ( 1 , V_637
L_33 , V_29 ) ;
}
V_632:
V_29 = F_363 ( V_35 , V_444 , V_630 ,
V_422 ) ;
if ( ! V_29 )
return V_444 ;
if ( V_444 -> type != V_634 &&
V_444 -> V_94 == V_261 -> V_94 ) {
V_29 = F_365 ( V_261 , V_630 ) ;
if ( ! V_29 )
return V_261 ;
}
return F_474 ( V_29 ) ;
}
static void F_478 ( struct V_12 * V_37 ,
struct V_260 * V_444 , T_3 V_630 )
{
F_367 ( V_444 , V_630 , 0 ) ;
F_370 ( V_37 , V_444 , NULL , 0 ) ;
}
struct V_66 * F_479 ( struct V_116 * V_117 ,
struct V_34 * V_35 ,
T_2 V_17 , T_2 V_152 ,
struct V_623 * V_21 , int V_175 ,
T_2 V_638 , T_2 V_591 )
{
struct V_68 V_222 ;
struct V_260 * V_444 ;
struct V_66 * V_285 ;
struct V_188 * V_136 ;
T_2 V_7 = 0 ;
int V_29 ;
T_3 V_630 = V_35 -> V_54 ;
bool V_181 = F_84 ( V_35 -> V_37 ,
V_128 ) ;
#ifdef F_480
if ( F_241 ( V_35 -> V_37 ) ) {
V_285 = F_464 ( V_117 , V_35 , V_35 -> V_639 ,
V_175 ) ;
if ( ! F_217 ( V_285 ) )
V_35 -> V_639 += V_630 ;
return V_285 ;
}
#endif
V_444 = F_473 ( V_117 , V_35 , V_630 ) ;
if ( F_217 ( V_444 ) )
return F_481 ( V_444 ) ;
V_29 = F_456 ( V_35 , V_630 , V_630 , V_630 ,
V_591 , V_638 , & V_222 , 0 , 0 ) ;
if ( V_29 )
goto V_640;
V_285 = F_464 ( V_117 , V_35 , V_222 . V_22 , V_175 ) ;
if ( F_217 ( V_285 ) ) {
V_29 = F_218 ( V_285 ) ;
goto V_641;
}
if ( V_152 == V_642 ) {
if ( V_17 == 0 )
V_17 = V_222 . V_22 ;
V_7 |= V_133 ;
} else
F_32 ( V_17 > 0 ) ;
if ( V_152 != V_216 ) {
V_136 = F_232 () ;
if ( ! V_136 ) {
V_29 = - V_73 ;
goto V_643;
}
if ( V_21 )
memcpy ( & V_136 -> V_21 , V_21 , sizeof( V_136 -> V_21 ) ) ;
else
memset ( & V_136 -> V_21 , 0 , sizeof( V_136 -> V_21 ) ) ;
V_136 -> V_138 = V_7 ;
V_136 -> V_226 = V_181 ? false : true ;
V_136 -> V_137 = true ;
V_136 -> V_192 = false ;
V_136 -> V_175 = V_175 ;
V_29 = F_159 ( V_35 -> V_37 , V_117 ,
V_222 . V_22 , V_222 . V_33 ,
V_17 , V_152 , V_175 ,
V_243 ,
V_136 ) ;
if ( V_29 )
goto V_644;
}
return V_285 ;
V_644:
F_193 ( V_136 ) ;
V_643:
F_482 ( V_285 ) ;
V_641:
F_458 ( V_35 , V_222 . V_22 , V_222 . V_33 , 0 ) ;
V_640:
F_478 ( V_35 -> V_37 , V_444 , V_630 ) ;
return F_474 ( V_29 ) ;
}
static T_1 void F_483 ( struct V_116 * V_117 ,
struct V_34 * V_35 ,
struct V_645 * V_646 ,
struct V_64 * V_65 )
{
T_2 V_27 ;
T_2 V_309 ;
T_2 V_119 ;
T_2 V_7 ;
T_3 V_71 ;
struct V_68 V_21 ;
struct V_66 * V_539 ;
int V_29 ;
int V_647 ;
int V_648 = 0 ;
if ( V_65 -> V_82 [ V_646 -> V_175 ] < V_646 -> V_649 ) {
V_646 -> V_650 = V_646 -> V_650 * 2 / 3 ;
V_646 -> V_650 = F_448 ( V_646 -> V_650 , 2 ) ;
} else {
V_646 -> V_650 = V_646 -> V_650 * 3 / 2 ;
V_646 -> V_650 = F_24 ( int , V_646 -> V_650 ,
F_484 ( V_35 ) ) ;
}
V_539 = V_65 -> V_81 [ V_646 -> V_175 ] ;
V_71 = F_39 ( V_539 ) ;
for ( V_647 = V_65 -> V_82 [ V_646 -> V_175 ] ; V_647 < V_71 ; V_647 ++ ) {
if ( V_648 >= V_646 -> V_650 )
break;
F_48 () ;
V_27 = F_248 ( V_539 , V_647 ) ;
V_309 = F_485 ( V_539 , V_647 ) ;
if ( V_647 == V_65 -> V_82 [ V_646 -> V_175 ] )
goto V_76;
if ( V_646 -> V_651 == V_652 &&
V_309 <= V_35 -> V_281 . V_33 )
continue;
V_29 = F_83 ( V_117 , V_35 , V_27 ,
V_646 -> V_175 - 1 , 1 , & V_119 ,
& V_7 ) ;
if ( V_29 < 0 )
continue;
F_32 ( V_119 == 0 ) ;
if ( V_646 -> V_651 == V_653 ) {
if ( V_119 == 1 )
goto V_76;
if ( V_646 -> V_175 == 1 &&
( V_7 & V_133 ) )
continue;
if ( ! V_646 -> V_654 ||
V_309 <= V_35 -> V_281 . V_33 )
continue;
F_131 ( V_539 , & V_21 , V_647 ) ;
V_29 = F_486 ( & V_21 ,
& V_646 -> V_655 ) ;
if ( V_29 < 0 )
continue;
} else {
if ( V_646 -> V_175 == 1 &&
( V_7 & V_133 ) )
continue;
}
V_76:
F_487 ( V_35 , V_27 ) ;
V_648 ++ ;
}
V_646 -> V_649 = V_647 ;
}
static int F_488 ( struct V_116 * V_117 ,
struct V_34 * V_35 ,
struct V_66 * V_539 )
{
int V_43 = F_39 ( V_539 ) ;
int V_42 , V_656 , V_29 ;
struct V_68 V_21 ;
struct V_288 * V_289 ;
T_2 V_27 , V_36 ;
if ( ! F_226 ( V_506 , & V_35 -> V_37 -> V_7 ) )
return 0 ;
for ( V_42 = 0 ; V_42 < V_43 ; V_42 ++ ) {
F_41 ( V_539 , & V_21 , V_42 ) ;
if ( V_21 . type != V_293 )
continue;
V_289 = F_86 ( V_539 , V_42 , struct V_288 ) ;
V_656 = F_244 ( V_539 , V_289 ) ;
if ( V_656 == V_294 )
continue;
V_27 = F_245 ( V_539 , V_289 ) ;
if ( ! V_27 )
continue;
V_36 = F_246 ( V_539 , V_289 ) ;
V_29 = F_489 ( V_117 , V_35 -> V_37 ,
V_27 , V_36 , V_97 ) ;
if ( V_29 )
return V_29 ;
}
return 0 ;
}
static int F_490 ( struct V_34 * V_35 ,
struct V_64 * V_65 , int V_657 )
{
int V_175 = 0 ;
int V_43 , V_647 ;
struct V_66 * V_539 ;
if ( V_657 == 0 )
return 1 ;
while ( V_175 <= V_657 ) {
V_539 = V_65 -> V_81 [ V_175 ] ;
V_43 = F_39 ( V_539 ) ;
V_65 -> V_82 [ V_175 ] ++ ;
V_647 = V_65 -> V_82 [ V_175 ] ;
if ( V_647 >= V_43 || V_175 == 0 ) {
if ( V_175 != V_657 ) {
F_491 ( V_539 , V_65 -> V_658 [ V_175 ] ) ;
V_65 -> V_658 [ V_175 ] = 0 ;
F_482 ( V_539 ) ;
V_65 -> V_81 [ V_175 ] = NULL ;
V_65 -> V_82 [ V_175 ] = 0 ;
}
} else {
break;
}
V_175 ++ ;
}
V_539 = V_65 -> V_81 [ V_657 ] ;
if ( V_65 -> V_82 [ V_657 ] >= F_39 ( V_539 ) )
return 1 ;
return 0 ;
}
static int F_492 ( struct V_116 * V_117 ,
struct V_34 * V_35 ,
struct V_66 * V_659 ,
T_2 V_660 ,
int V_657 )
{
int V_29 = 0 ;
int V_175 ;
struct V_66 * V_539 = V_659 ;
struct V_64 * V_65 = NULL ;
F_32 ( V_657 < 0 || V_657 > V_176 ) ;
F_32 ( V_659 == NULL ) ;
if ( ! F_226 ( V_506 , & V_35 -> V_37 -> V_7 ) )
return 0 ;
if ( ! F_493 ( V_659 ) ) {
V_29 = F_494 ( V_659 , V_660 ) ;
if ( V_29 )
goto V_80;
}
if ( V_657 == 0 ) {
V_29 = F_488 ( V_117 , V_35 , V_659 ) ;
goto V_80;
}
V_65 = F_34 () ;
if ( ! V_65 )
return - V_73 ;
F_495 ( V_659 ) ;
V_65 -> V_81 [ V_657 ] = V_659 ;
V_65 -> V_82 [ V_657 ] = 0 ;
V_65 -> V_658 [ V_657 ] = 0 ;
V_661:
V_175 = V_657 ;
while ( V_175 >= 0 ) {
if ( V_65 -> V_81 [ V_175 ] == NULL ) {
int V_662 ;
T_2 V_663 ;
T_2 V_664 ;
V_539 = V_65 -> V_81 [ V_175 + 1 ] ;
V_662 = V_65 -> V_82 [ V_175 + 1 ] ;
V_664 = F_248 ( V_539 , V_662 ) ;
V_663 = F_485 ( V_539 , V_662 ) ;
V_539 = F_496 ( V_35 , V_664 , V_663 ) ;
if ( F_217 ( V_539 ) ) {
V_29 = F_218 ( V_539 ) ;
goto V_80;
} else if ( ! F_493 ( V_539 ) ) {
F_482 ( V_539 ) ;
V_29 = - V_183 ;
goto V_80;
}
V_65 -> V_81 [ V_175 ] = V_539 ;
V_65 -> V_82 [ V_175 ] = 0 ;
F_497 ( V_539 ) ;
F_498 ( V_539 , V_665 ) ;
V_65 -> V_658 [ V_175 ] = V_666 ;
V_29 = F_489 ( V_117 ,
V_35 -> V_37 , V_664 ,
V_35 -> V_54 , V_97 ) ;
if ( V_29 )
goto V_80;
}
if ( V_175 == 0 ) {
V_29 = F_488 ( V_117 , V_35 , V_65 -> V_81 [ V_175 ] ) ;
if ( V_29 )
goto V_80;
V_29 = F_490 ( V_35 , V_65 , V_657 ) ;
if ( V_29 )
break;
goto V_661;
}
V_175 -- ;
}
V_29 = 0 ;
V_80:
F_53 ( V_65 ) ;
return V_29 ;
}
static T_1 int F_499 ( struct V_116 * V_117 ,
struct V_34 * V_35 ,
struct V_64 * V_65 ,
struct V_645 * V_646 , int V_667 )
{
int V_175 = V_646 -> V_175 ;
struct V_66 * V_539 = V_65 -> V_81 [ V_175 ] ;
T_2 V_668 = V_133 ;
int V_29 ;
if ( V_646 -> V_651 == V_652 &&
F_242 ( V_539 ) != V_35 -> V_281 . V_22 )
return 1 ;
if ( V_667 &&
( ( V_646 -> V_651 == V_653 && V_646 -> V_119 [ V_175 ] != 1 ) ||
( V_646 -> V_651 == V_652 && ! ( V_646 -> V_7 [ V_175 ] & V_668 ) ) ) ) {
F_32 ( ! V_65 -> V_658 [ V_175 ] ) ;
V_29 = F_83 ( V_117 , V_35 ,
V_539 -> V_32 , V_175 , 1 ,
& V_646 -> V_119 [ V_175 ] ,
& V_646 -> V_7 [ V_175 ] ) ;
F_32 ( V_29 == - V_73 ) ;
if ( V_29 )
return V_29 ;
F_32 ( V_646 -> V_119 [ V_175 ] == 0 ) ;
}
if ( V_646 -> V_651 == V_653 ) {
if ( V_646 -> V_119 [ V_175 ] > 1 )
return 1 ;
if ( V_65 -> V_658 [ V_175 ] && ! V_646 -> V_182 ) {
F_491 ( V_539 , V_65 -> V_658 [ V_175 ] ) ;
V_65 -> V_658 [ V_175 ] = 0 ;
}
return 0 ;
}
if ( ! ( V_646 -> V_7 [ V_175 ] & V_668 ) ) {
F_32 ( ! V_65 -> V_658 [ V_175 ] ) ;
V_29 = F_249 ( V_117 , V_35 , V_539 , 1 ) ;
F_32 ( V_29 ) ;
V_29 = F_250 ( V_117 , V_35 , V_539 , 0 ) ;
F_32 ( V_29 ) ;
V_29 = F_231 ( V_117 , V_35 , V_539 -> V_32 ,
V_539 -> V_47 , V_668 ,
F_243 ( V_539 ) , 0 ) ;
F_32 ( V_29 ) ;
V_646 -> V_7 [ V_175 ] |= V_668 ;
}
if ( V_65 -> V_658 [ V_175 ] && V_175 > 0 ) {
F_491 ( V_539 , V_65 -> V_658 [ V_175 ] ) ;
V_65 -> V_658 [ V_175 ] = 0 ;
}
return 0 ;
}
static T_1 int F_500 ( struct V_116 * V_117 ,
struct V_34 * V_35 ,
struct V_64 * V_65 ,
struct V_645 * V_646 , int * V_667 )
{
T_2 V_27 ;
T_2 V_309 ;
T_2 V_17 ;
T_3 V_630 ;
struct V_68 V_21 ;
struct V_66 * V_79 ;
int V_175 = V_646 -> V_175 ;
int V_76 = 0 ;
int V_29 = 0 ;
bool V_669 = false ;
V_309 = F_485 ( V_65 -> V_81 [ V_175 ] ,
V_65 -> V_82 [ V_175 ] ) ;
if ( V_646 -> V_651 == V_652 &&
V_309 <= V_35 -> V_281 . V_33 ) {
* V_667 = 1 ;
return 1 ;
}
V_27 = F_248 ( V_65 -> V_81 [ V_175 ] , V_65 -> V_82 [ V_175 ] ) ;
V_630 = V_35 -> V_54 ;
V_79 = F_501 ( V_35 -> V_37 , V_27 ) ;
if ( ! V_79 ) {
V_79 = F_465 ( V_35 , V_27 ) ;
if ( F_217 ( V_79 ) )
return F_218 ( V_79 ) ;
F_467 ( V_35 -> V_281 . V_22 , V_79 ,
V_175 - 1 ) ;
V_76 = 1 ;
}
F_468 ( V_79 ) ;
F_470 ( V_79 ) ;
V_29 = F_83 ( V_117 , V_35 , V_27 , V_175 - 1 , 1 ,
& V_646 -> V_119 [ V_175 - 1 ] ,
& V_646 -> V_7 [ V_175 - 1 ] ) ;
if ( V_29 < 0 )
goto V_670;
if ( F_364 ( V_646 -> V_119 [ V_175 - 1 ] == 0 ) ) {
F_173 ( V_35 -> V_37 , L_34 ) ;
V_29 = - V_183 ;
goto V_670;
}
* V_667 = 0 ;
if ( V_646 -> V_651 == V_653 ) {
if ( V_646 -> V_119 [ V_175 - 1 ] > 1 ) {
V_669 = true ;
if ( V_175 == 1 &&
( V_646 -> V_7 [ 0 ] & V_133 ) )
goto V_671;
if ( ! V_646 -> V_654 ||
V_309 <= V_35 -> V_281 . V_33 )
goto V_671;
F_131 ( V_65 -> V_81 [ V_175 ] , & V_21 ,
V_65 -> V_82 [ V_175 ] ) ;
V_29 = F_486 ( & V_21 , & V_646 -> V_655 ) ;
if ( V_29 < 0 )
goto V_671;
V_646 -> V_651 = V_652 ;
V_646 -> V_672 = V_175 - 1 ;
}
} else {
if ( V_175 == 1 &&
( V_646 -> V_7 [ 0 ] & V_133 ) )
goto V_671;
}
if ( ! F_502 ( V_79 , V_309 , 0 ) ) {
F_503 ( V_79 ) ;
F_482 ( V_79 ) ;
V_79 = NULL ;
* V_667 = 1 ;
}
if ( ! V_79 ) {
if ( V_76 && V_175 == 1 )
F_483 ( V_117 , V_35 , V_646 , V_65 ) ;
V_79 = F_496 ( V_35 , V_27 , V_309 ) ;
if ( F_217 ( V_79 ) ) {
return F_218 ( V_79 ) ;
} else if ( ! F_493 ( V_79 ) ) {
F_482 ( V_79 ) ;
return - V_183 ;
}
F_468 ( V_79 ) ;
F_470 ( V_79 ) ;
}
V_175 -- ;
ASSERT ( V_175 == F_243 ( V_79 ) ) ;
if ( V_175 != F_243 ( V_79 ) ) {
F_173 ( V_35 -> V_37 , L_35 ) ;
V_29 = - V_183 ;
goto V_670;
}
V_65 -> V_81 [ V_175 ] = V_79 ;
V_65 -> V_82 [ V_175 ] = 0 ;
V_65 -> V_658 [ V_175 ] = V_673 ;
V_646 -> V_175 = V_175 ;
if ( V_646 -> V_175 == 1 )
V_646 -> V_649 = 0 ;
return 0 ;
V_671:
V_646 -> V_119 [ V_175 - 1 ] = 0 ;
V_646 -> V_7 [ V_175 - 1 ] = 0 ;
if ( V_646 -> V_651 == V_653 ) {
if ( V_646 -> V_7 [ V_175 ] & V_133 ) {
V_17 = V_65 -> V_81 [ V_175 ] -> V_32 ;
} else {
ASSERT ( V_35 -> V_281 . V_22 ==
F_242 ( V_65 -> V_81 [ V_175 ] ) ) ;
if ( V_35 -> V_281 . V_22 !=
F_242 ( V_65 -> V_81 [ V_175 ] ) ) {
F_173 ( V_35 -> V_37 ,
L_36 ) ;
V_29 = - V_183 ;
goto V_670;
}
V_17 = 0 ;
}
if ( V_669 ) {
V_29 = F_492 ( V_117 , V_35 , V_79 ,
V_309 , V_175 - 1 ) ;
if ( V_29 ) {
F_504 ( V_35 -> V_37 ,
L_37 ,
V_29 ) ;
}
}
V_29 = V_292 ( V_117 , V_35 , V_27 , V_630 , V_17 ,
V_35 -> V_281 . V_22 , V_175 - 1 , 0 ) ;
if ( V_29 )
goto V_670;
}
* V_667 = 1 ;
V_29 = 1 ;
V_670:
F_503 ( V_79 ) ;
F_482 ( V_79 ) ;
return V_29 ;
}
static T_1 int F_505 ( struct V_116 * V_117 ,
struct V_34 * V_35 ,
struct V_64 * V_65 ,
struct V_645 * V_646 )
{
int V_29 ;
int V_175 = V_646 -> V_175 ;
struct V_66 * V_539 = V_65 -> V_81 [ V_175 ] ;
T_2 V_17 = 0 ;
if ( V_646 -> V_651 == V_652 ) {
F_32 ( V_646 -> V_672 < V_175 ) ;
if ( V_175 < V_646 -> V_672 )
goto V_80;
V_29 = F_42 ( V_65 , V_175 + 1 , & V_646 -> V_655 ) ;
if ( V_29 > 0 )
V_646 -> V_654 = 0 ;
V_646 -> V_651 = V_653 ;
V_646 -> V_672 = - 1 ;
V_65 -> V_82 [ V_175 ] = 0 ;
if ( ! V_65 -> V_658 [ V_175 ] ) {
F_32 ( V_175 == 0 ) ;
F_468 ( V_539 ) ;
F_470 ( V_539 ) ;
V_65 -> V_658 [ V_175 ] = V_673 ;
V_29 = F_83 ( V_117 , V_35 ,
V_539 -> V_32 , V_175 , 1 ,
& V_646 -> V_119 [ V_175 ] ,
& V_646 -> V_7 [ V_175 ] ) ;
if ( V_29 < 0 ) {
F_491 ( V_539 , V_65 -> V_658 [ V_175 ] ) ;
V_65 -> V_658 [ V_175 ] = 0 ;
return V_29 ;
}
F_32 ( V_646 -> V_119 [ V_175 ] == 0 ) ;
if ( V_646 -> V_119 [ V_175 ] == 1 ) {
F_491 ( V_539 , V_65 -> V_658 [ V_175 ] ) ;
V_65 -> V_658 [ V_175 ] = 0 ;
return 1 ;
}
}
}
F_32 ( V_646 -> V_119 [ V_175 ] > 1 && ! V_65 -> V_658 [ V_175 ] ) ;
if ( V_646 -> V_119 [ V_175 ] == 1 ) {
if ( V_175 == 0 ) {
if ( V_646 -> V_7 [ V_175 ] & V_133 )
V_29 = F_250 ( V_117 , V_35 , V_539 , 1 ) ;
else
V_29 = F_250 ( V_117 , V_35 , V_539 , 0 ) ;
F_32 ( V_29 ) ;
V_29 = F_488 ( V_117 , V_35 , V_539 ) ;
if ( V_29 ) {
F_504 ( V_35 -> V_37 ,
L_38 ,
V_29 ) ;
}
}
if ( ! V_65 -> V_658 [ V_175 ] &&
F_433 ( V_539 ) == V_117 -> V_272 ) {
F_468 ( V_539 ) ;
F_470 ( V_539 ) ;
V_65 -> V_658 [ V_175 ] = V_673 ;
}
F_469 ( V_117 , V_35 -> V_37 , V_539 ) ;
}
if ( V_539 == V_35 -> V_135 ) {
if ( V_646 -> V_7 [ V_175 ] & V_133 )
V_17 = V_539 -> V_32 ;
else
F_32 ( V_35 -> V_281 . V_22 !=
F_242 ( V_539 ) ) ;
} else {
if ( V_646 -> V_7 [ V_175 + 1 ] & V_133 )
V_17 = V_65 -> V_81 [ V_175 + 1 ] -> V_32 ;
else
F_32 ( V_35 -> V_281 . V_22 !=
F_242 ( V_65 -> V_81 [ V_175 + 1 ] ) ) ;
}
F_432 ( V_117 , V_35 , V_539 , V_17 , V_646 -> V_119 [ V_175 ] == 1 ) ;
V_80:
V_646 -> V_119 [ V_175 ] = 0 ;
V_646 -> V_7 [ V_175 ] = 0 ;
return 0 ;
}
static T_1 int F_506 ( struct V_116 * V_117 ,
struct V_34 * V_35 ,
struct V_64 * V_65 ,
struct V_645 * V_646 )
{
int V_175 = V_646 -> V_175 ;
int V_667 = 1 ;
int V_29 ;
while ( V_175 >= 0 ) {
V_29 = F_499 ( V_117 , V_35 , V_65 , V_646 , V_667 ) ;
if ( V_29 > 0 )
break;
if ( V_175 == 0 )
break;
if ( V_65 -> V_82 [ V_175 ] >=
F_39 ( V_65 -> V_81 [ V_175 ] ) )
break;
V_29 = F_500 ( V_117 , V_35 , V_65 , V_646 , & V_667 ) ;
if ( V_29 > 0 ) {
V_65 -> V_82 [ V_175 ] ++ ;
continue;
} else if ( V_29 < 0 )
return V_29 ;
V_175 = V_646 -> V_175 ;
}
return 0 ;
}
static T_1 int F_507 ( struct V_116 * V_117 ,
struct V_34 * V_35 ,
struct V_64 * V_65 ,
struct V_645 * V_646 , int V_674 )
{
int V_175 = V_646 -> V_175 ;
int V_29 ;
V_65 -> V_82 [ V_175 ] = F_39 ( V_65 -> V_81 [ V_175 ] ) ;
while ( V_175 < V_674 && V_65 -> V_81 [ V_175 ] ) {
V_646 -> V_175 = V_175 ;
if ( V_65 -> V_82 [ V_175 ] + 1 <
F_39 ( V_65 -> V_81 [ V_175 ] ) ) {
V_65 -> V_82 [ V_175 ] ++ ;
return 0 ;
} else {
V_29 = F_505 ( V_117 , V_35 , V_65 , V_646 ) ;
if ( V_29 > 0 )
return 0 ;
if ( V_65 -> V_658 [ V_175 ] ) {
F_491 ( V_65 -> V_81 [ V_175 ] ,
V_65 -> V_658 [ V_175 ] ) ;
V_65 -> V_658 [ V_175 ] = 0 ;
}
F_482 ( V_65 -> V_81 [ V_175 ] ) ;
V_65 -> V_81 [ V_175 ] = NULL ;
V_175 ++ ;
}
}
return 1 ;
}
int F_508 ( struct V_34 * V_35 ,
struct V_260 * V_444 , int V_654 ,
int V_675 )
{
struct V_12 * V_37 = V_35 -> V_37 ;
struct V_64 * V_65 ;
struct V_116 * V_117 ;
struct V_34 * V_87 = V_37 -> V_87 ;
struct V_676 * V_282 = & V_35 -> V_282 ;
struct V_645 * V_646 ;
struct V_68 V_21 ;
int V_159 = 0 ;
int V_29 ;
int V_175 ;
bool V_677 = false ;
F_194 ( V_37 , L_39 , V_35 -> V_22 ) ;
V_65 = F_34 () ;
if ( ! V_65 ) {
V_159 = - V_73 ;
goto V_80;
}
V_646 = F_61 ( sizeof( * V_646 ) , V_97 ) ;
if ( ! V_646 ) {
F_53 ( V_65 ) ;
V_159 = - V_73 ;
goto V_80;
}
V_117 = F_509 ( V_87 , 0 ) ;
if ( F_217 ( V_117 ) ) {
V_159 = F_218 ( V_117 ) ;
goto V_130;
}
if ( V_444 )
V_117 -> V_444 = V_444 ;
if ( F_510 ( & V_282 -> V_678 ) == 0 ) {
V_175 = F_243 ( V_35 -> V_135 ) ;
V_65 -> V_81 [ V_175 ] = F_511 ( V_35 ) ;
F_470 ( V_65 -> V_81 [ V_175 ] ) ;
V_65 -> V_82 [ V_175 ] = 0 ;
V_65 -> V_658 [ V_175 ] = V_673 ;
memset ( & V_646 -> V_655 , 0 ,
sizeof( V_646 -> V_655 ) ) ;
} else {
F_512 ( & V_21 , & V_282 -> V_678 ) ;
memcpy ( & V_646 -> V_655 , & V_21 ,
sizeof( V_646 -> V_655 ) ) ;
V_175 = V_282 -> V_679 ;
F_32 ( V_175 == 0 ) ;
V_65 -> V_680 = V_175 ;
V_29 = F_38 ( NULL , V_35 , & V_21 , V_65 , 0 , 0 ) ;
V_65 -> V_680 = 0 ;
if ( V_29 < 0 ) {
V_159 = V_29 ;
goto V_681;
}
F_8 ( V_29 > 0 ) ;
F_136 ( V_65 , 0 ) ;
V_175 = F_243 ( V_35 -> V_135 ) ;
while ( 1 ) {
F_468 ( V_65 -> V_81 [ V_175 ] ) ;
F_470 ( V_65 -> V_81 [ V_175 ] ) ;
V_65 -> V_658 [ V_175 ] = V_673 ;
V_29 = F_83 ( V_117 , V_35 ,
V_65 -> V_81 [ V_175 ] -> V_32 ,
V_175 , 1 , & V_646 -> V_119 [ V_175 ] ,
& V_646 -> V_7 [ V_175 ] ) ;
if ( V_29 < 0 ) {
V_159 = V_29 ;
goto V_681;
}
F_32 ( V_646 -> V_119 [ V_175 ] == 0 ) ;
if ( V_175 == V_282 -> V_679 )
break;
F_503 ( V_65 -> V_81 [ V_175 ] ) ;
V_65 -> V_658 [ V_175 ] = 0 ;
F_8 ( V_646 -> V_119 [ V_175 ] != 1 ) ;
V_175 -- ;
}
}
V_646 -> V_175 = V_175 ;
V_646 -> V_672 = - 1 ;
V_646 -> V_651 = V_653 ;
V_646 -> V_654 = V_654 ;
V_646 -> V_182 = 0 ;
V_646 -> V_675 = V_675 ;
V_646 -> V_650 = F_484 ( V_35 ) ;
while ( 1 ) {
V_29 = F_506 ( V_117 , V_35 , V_65 , V_646 ) ;
if ( V_29 < 0 ) {
V_159 = V_29 ;
break;
}
V_29 = F_507 ( V_117 , V_35 , V_65 , V_646 , V_176 ) ;
if ( V_29 < 0 ) {
V_159 = V_29 ;
break;
}
if ( V_29 > 0 ) {
F_32 ( V_646 -> V_651 != V_653 ) ;
break;
}
if ( V_646 -> V_651 == V_653 ) {
V_175 = V_646 -> V_175 ;
F_513 ( V_65 -> V_81 [ V_175 ] ,
& V_282 -> V_678 ,
V_65 -> V_82 [ V_175 ] ) ;
V_282 -> V_679 = V_175 ;
}
F_32 ( V_646 -> V_175 == 0 ) ;
if ( F_514 ( V_117 , V_87 ) ||
( ! V_675 && F_515 ( V_35 ) ) ) {
V_29 = F_516 ( V_117 , V_87 ,
& V_35 -> V_281 ,
V_282 ) ;
if ( V_29 ) {
F_162 ( V_117 , V_29 ) ;
V_159 = V_29 ;
goto V_681;
}
F_517 ( V_117 , V_87 ) ;
if ( ! V_675 && F_515 ( V_35 ) ) {
F_194 ( V_37 ,
L_40 ) ;
V_159 = - V_186 ;
goto V_130;
}
V_117 = F_509 ( V_87 , 0 ) ;
if ( F_217 ( V_117 ) ) {
V_159 = F_218 ( V_117 ) ;
goto V_130;
}
if ( V_444 )
V_117 -> V_444 = V_444 ;
}
}
F_45 ( V_65 ) ;
if ( V_159 )
goto V_681;
V_29 = F_518 ( V_117 , V_87 , & V_35 -> V_281 ) ;
if ( V_29 ) {
F_162 ( V_117 , V_29 ) ;
goto V_681;
}
if ( V_35 -> V_281 . V_22 != V_642 ) {
V_29 = F_519 ( V_87 , & V_35 -> V_281 , V_65 ,
NULL , NULL ) ;
if ( V_29 < 0 ) {
F_162 ( V_117 , V_29 ) ;
V_159 = V_29 ;
goto V_681;
} else if ( V_29 > 0 ) {
F_520 ( V_117 , V_87 ,
V_35 -> V_281 . V_22 ) ;
}
}
if ( F_226 ( V_682 , & V_35 -> V_291 ) ) {
F_521 ( V_117 , V_35 ) ;
} else {
F_482 ( V_35 -> V_135 ) ;
F_482 ( V_35 -> V_683 ) ;
F_522 ( V_35 ) ;
}
V_677 = true ;
V_681:
F_517 ( V_117 , V_87 ) ;
V_130:
F_9 ( V_646 ) ;
F_53 ( V_65 ) ;
V_80:
if ( ! V_675 && V_677 == false )
F_523 ( V_35 ) ;
if ( V_159 && V_159 != - V_186 )
F_524 ( V_37 , V_159 , NULL ) ;
return V_159 ;
}
int F_525 ( struct V_116 * V_117 ,
struct V_34 * V_35 ,
struct V_66 * V_135 ,
struct V_66 * V_17 )
{
struct V_64 * V_65 ;
struct V_645 * V_646 ;
int V_175 ;
int V_684 ;
int V_29 = 0 ;
int V_685 ;
F_32 ( V_35 -> V_281 . V_22 != V_642 ) ;
V_65 = F_34 () ;
if ( ! V_65 )
return - V_73 ;
V_646 = F_61 ( sizeof( * V_646 ) , V_97 ) ;
if ( ! V_646 ) {
F_53 ( V_65 ) ;
return - V_73 ;
}
F_526 ( V_17 ) ;
V_684 = F_243 ( V_17 ) ;
F_495 ( V_17 ) ;
V_65 -> V_81 [ V_684 ] = V_17 ;
V_65 -> V_82 [ V_684 ] = F_39 ( V_17 ) ;
F_526 ( V_135 ) ;
V_175 = F_243 ( V_135 ) ;
V_65 -> V_81 [ V_175 ] = V_135 ;
V_65 -> V_82 [ V_175 ] = 0 ;
V_65 -> V_658 [ V_175 ] = V_673 ;
V_646 -> V_119 [ V_684 ] = 1 ;
V_646 -> V_7 [ V_684 ] = V_133 ;
V_646 -> V_175 = V_175 ;
V_646 -> V_672 = - 1 ;
V_646 -> V_651 = V_653 ;
V_646 -> V_654 = 0 ;
V_646 -> V_182 = 1 ;
V_646 -> V_675 = 1 ;
V_646 -> V_650 = F_484 ( V_35 ) ;
while ( 1 ) {
V_685 = F_506 ( V_117 , V_35 , V_65 , V_646 ) ;
if ( V_685 < 0 ) {
V_29 = V_685 ;
break;
}
V_685 = F_507 ( V_117 , V_35 , V_65 , V_646 , V_684 ) ;
if ( V_685 < 0 )
V_29 = V_685 ;
if ( V_685 != 0 )
break;
}
F_9 ( V_646 ) ;
F_53 ( V_65 ) ;
return V_29 ;
}
static T_2 F_527 ( struct V_34 * V_35 , T_2 V_7 )
{
T_2 V_381 ;
T_2 V_686 ;
V_686 = F_300 ( V_35 -> V_37 , V_7 ) ;
if ( V_686 )
return F_302 ( V_686 ) ;
V_381 = V_35 -> V_37 -> V_382 -> V_383 ;
V_686 = V_392 |
V_391 | V_390 |
V_343 | V_344 ;
if ( V_381 == 1 ) {
V_686 |= V_342 ;
V_686 = V_7 & ~ V_686 ;
if ( V_7 & V_392 )
return V_686 ;
if ( V_7 & ( V_343 |
V_344 ) )
return V_686 | V_342 ;
} else {
if ( V_7 & V_686 )
return V_7 ;
V_686 |= V_342 ;
V_686 = V_7 & ~ V_686 ;
if ( V_7 & V_342 )
return V_686 | V_343 ;
}
return V_7 ;
}
static int F_528 ( struct V_1 * V_2 , int V_410 )
{
struct V_110 * V_409 = V_2 -> V_94 ;
T_2 V_36 ;
T_2 V_687 ;
int V_29 = - V_312 ;
if ( ( V_409 -> V_7 &
( V_338 | V_53 ) ) &&
! V_410 )
V_687 = V_302 ;
else
V_687 = 0 ;
F_11 ( & V_409 -> V_50 ) ;
F_11 ( & V_2 -> V_50 ) ;
if ( V_2 -> V_305 ) {
V_2 -> V_305 ++ ;
V_29 = 0 ;
goto V_80;
}
V_36 = V_2 -> V_21 . V_33 - V_2 -> V_10 - V_2 -> V_9 -
V_2 -> V_45 - F_58 ( & V_2 -> V_95 ) ;
if ( V_409 -> V_93 + V_409 -> V_353 + V_409 -> V_352 +
V_409 -> V_354 + V_409 -> V_340 + V_36 +
V_687 <= V_409 -> V_339 ) {
V_409 -> V_340 += V_36 ;
V_2 -> V_305 ++ ;
F_72 ( & V_2 -> V_688 , & V_409 -> V_360 ) ;
V_29 = 0 ;
}
V_80:
F_13 ( & V_2 -> V_50 ) ;
F_13 ( & V_409 -> V_50 ) ;
return V_29 ;
}
int F_529 ( struct V_34 * V_35 ,
struct V_1 * V_2 )
{
struct V_116 * V_117 ;
T_2 V_689 ;
int V_29 ;
V_163:
V_117 = F_216 ( V_35 ) ;
if ( F_217 ( V_117 ) )
return F_218 ( V_117 ) ;
F_49 ( & V_35 -> V_37 -> V_690 ) ;
if ( F_226 ( V_691 , & V_117 -> V_134 -> V_7 ) ) {
T_2 V_272 = V_117 -> V_272 ;
F_47 ( & V_35 -> V_37 -> V_690 ) ;
F_220 ( V_117 , V_35 ) ;
V_29 = F_530 ( V_35 , V_272 ) ;
if ( V_29 )
return V_29 ;
goto V_163;
}
V_689 = F_527 ( V_35 , V_2 -> V_7 ) ;
if ( V_689 != V_2 -> V_7 ) {
V_29 = F_309 ( V_117 , V_35 , V_689 ,
V_403 ) ;
if ( V_29 == - V_312 )
V_29 = 0 ;
if ( V_29 < 0 )
goto V_80;
}
V_29 = F_528 ( V_2 , 0 ) ;
if ( ! V_29 )
goto V_80;
V_689 = F_303 ( V_35 , V_2 -> V_94 -> V_7 ) ;
V_29 = F_309 ( V_117 , V_35 , V_689 ,
V_403 ) ;
if ( V_29 < 0 )
goto V_80;
V_29 = F_528 ( V_2 , 0 ) ;
V_80:
if ( V_2 -> V_7 & V_338 ) {
V_689 = F_527 ( V_35 , V_2 -> V_7 ) ;
F_531 ( V_35 -> V_37 -> V_395 ) ;
F_327 ( V_117 , V_35 , V_689 ) ;
F_532 ( V_35 -> V_37 -> V_395 ) ;
}
F_47 ( & V_35 -> V_37 -> V_690 ) ;
F_220 ( V_117 , V_35 ) ;
return V_29 ;
}
int F_533 ( struct V_116 * V_117 ,
struct V_34 * V_35 , T_2 type )
{
T_2 V_689 = F_303 ( V_35 , type ) ;
return F_309 ( V_117 , V_35 , V_689 ,
V_403 ) ;
}
T_2 F_534 ( struct V_110 * V_409 )
{
struct V_1 * V_14 ;
T_2 V_692 = 0 ;
int V_341 ;
if ( F_183 ( & V_409 -> V_360 ) )
return 0 ;
F_11 ( & V_409 -> V_50 ) ;
F_184 (block_group, &sinfo->ro_bgs, ro_list) {
F_11 ( & V_14 -> V_50 ) ;
if ( ! V_14 -> V_305 ) {
F_13 ( & V_14 -> V_50 ) ;
continue;
}
if ( V_14 -> V_7 & ( V_343 |
V_344 |
V_342 ) )
V_341 = 2 ;
else
V_341 = 1 ;
V_692 += ( V_14 -> V_21 . V_33 -
F_58 ( & V_14 -> V_95 ) ) *
V_341 ;
F_13 ( & V_14 -> V_50 ) ;
}
F_13 ( & V_409 -> V_50 ) ;
return V_692 ;
}
void F_535 ( struct V_34 * V_35 ,
struct V_1 * V_2 )
{
struct V_110 * V_409 = V_2 -> V_94 ;
T_2 V_36 ;
F_32 ( ! V_2 -> V_305 ) ;
F_11 ( & V_409 -> V_50 ) ;
F_11 ( & V_2 -> V_50 ) ;
if ( ! -- V_2 -> V_305 ) {
V_36 = V_2 -> V_21 . V_33 - V_2 -> V_10 -
V_2 -> V_9 - V_2 -> V_45 -
F_58 ( & V_2 -> V_95 ) ;
V_409 -> V_340 -= V_36 ;
F_275 ( & V_2 -> V_688 ) ;
}
F_13 ( & V_2 -> V_50 ) ;
F_13 ( & V_409 -> V_50 ) ;
}
int F_536 ( struct V_34 * V_35 , T_2 V_27 )
{
struct V_1 * V_14 ;
struct V_110 * V_94 ;
struct V_693 * V_382 = V_35 -> V_37 -> V_382 ;
struct V_694 * V_695 ;
struct V_116 * V_117 ;
T_2 V_696 ;
T_2 V_697 = 1 ;
T_2 V_698 = 0 ;
T_2 V_376 ;
int V_699 ;
int V_595 ;
int V_115 = 0 ;
int V_29 = 0 ;
V_699 = F_264 ( V_35 -> V_37 , V_420 ) ;
V_14 = F_76 ( V_35 -> V_37 , V_27 ) ;
if ( ! V_14 ) {
if ( V_699 )
F_425 ( V_35 -> V_37 ,
L_41 ,
V_27 ) ;
return - 1 ;
}
V_696 = F_58 ( & V_14 -> V_95 ) ;
if ( ! V_696 )
goto V_80;
V_94 = V_14 -> V_94 ;
F_11 ( & V_94 -> V_50 ) ;
V_115 = V_94 -> V_115 ;
if ( ( V_94 -> V_339 != V_14 -> V_21 . V_33 ) &&
( V_94 -> V_93 + V_94 -> V_353 +
V_94 -> V_352 + V_94 -> V_340 +
V_696 < V_94 -> V_339 ) ) {
F_13 ( & V_94 -> V_50 ) ;
goto V_80;
}
F_13 ( & V_94 -> V_50 ) ;
V_29 = - 1 ;
V_376 = F_300 ( V_35 -> V_37 , V_14 -> V_7 ) ;
if ( V_376 ) {
V_595 = F_439 ( F_302 ( V_376 ) ) ;
} else {
if ( V_115 ) {
if ( V_699 )
F_425 ( V_35 -> V_37 ,
L_42 ,
V_14 -> V_21 . V_22 ) ;
goto V_80;
}
V_595 = F_440 ( V_14 ) ;
}
if ( V_595 == V_578 ) {
V_697 = 4 ;
V_696 >>= 1 ;
} else if ( V_595 == V_579 ) {
V_697 = 2 ;
} else if ( V_595 == V_580 ) {
V_696 <<= 1 ;
} else if ( V_595 == V_581 ) {
V_697 = V_382 -> V_383 ;
V_696 = F_208 ( V_696 , V_697 ) ;
}
V_117 = F_216 ( V_35 ) ;
if ( F_217 ( V_117 ) ) {
V_29 = F_218 ( V_117 ) ;
goto V_80;
}
F_49 ( & V_35 -> V_37 -> V_419 ) ;
F_184 (device, &fs_devices->alloc_list, dev_alloc_list) {
T_2 V_700 ;
if ( V_695 -> V_339 > V_695 -> V_93 + V_696 &&
! V_695 -> V_701 ) {
V_29 = F_537 ( V_117 , V_695 , V_696 ,
& V_700 , NULL ) ;
if ( ! V_29 )
V_698 ++ ;
if ( V_698 >= V_697 )
break;
V_29 = - 1 ;
}
}
if ( V_699 && V_29 == - 1 )
F_425 ( V_35 -> V_37 ,
L_43 ,
V_14 -> V_21 . V_22 ) ;
F_47 ( & V_35 -> V_37 -> V_419 ) ;
F_220 ( V_117 , V_35 ) ;
V_80:
F_6 ( V_14 ) ;
return V_29 ;
}
static int F_538 ( struct V_34 * V_35 ,
struct V_64 * V_65 , struct V_68 * V_21 )
{
int V_29 = 0 ;
struct V_68 V_146 ;
struct V_66 * V_67 ;
int V_647 ;
V_29 = F_38 ( NULL , V_35 , V_21 , V_65 , 0 , 0 ) ;
if ( V_29 < 0 )
goto V_80;
while ( 1 ) {
V_647 = V_65 -> V_82 [ 0 ] ;
V_67 = V_65 -> V_81 [ 0 ] ;
if ( V_647 >= F_39 ( V_67 ) ) {
V_29 = F_51 ( V_35 , V_65 ) ;
if ( V_29 == 0 )
continue;
if ( V_29 < 0 )
goto V_80;
break;
}
F_41 ( V_67 , & V_146 , V_647 ) ;
if ( V_146 . V_22 >= V_21 -> V_22 &&
V_146 . type == V_187 ) {
struct V_702 * V_703 ;
struct V_704 * V_705 ;
V_703 = & V_35 -> V_37 -> V_706 . V_707 ;
F_539 ( & V_703 -> V_50 ) ;
V_705 = F_540 ( V_703 , V_146 . V_22 ,
V_146 . V_33 ) ;
F_541 ( & V_703 -> V_50 ) ;
if ( ! V_705 ) {
F_173 ( V_35 -> V_37 ,
L_44 ,
V_146 . V_22 , V_146 . V_33 ) ;
V_29 = - V_160 ;
} else {
V_29 = 0 ;
}
F_542 ( V_705 ) ;
goto V_80;
}
V_65 -> V_82 [ 0 ] ++ ;
}
V_80:
return V_29 ;
}
void F_543 ( struct V_12 * V_13 )
{
struct V_1 * V_14 ;
T_2 V_70 = 0 ;
while ( 1 ) {
struct V_296 * V_296 ;
V_14 = F_75 ( V_13 , V_70 ) ;
while ( V_14 ) {
F_11 ( & V_14 -> V_50 ) ;
if ( V_14 -> V_172 )
break;
F_13 ( & V_14 -> V_50 ) ;
V_14 = F_254 ( V_13 -> V_87 ,
V_14 ) ;
}
if ( ! V_14 ) {
if ( V_70 == 0 )
break;
V_70 = 0 ;
continue;
}
V_296 = V_14 -> V_296 ;
V_14 -> V_172 = 0 ;
V_14 -> V_296 = NULL ;
F_13 ( & V_14 -> V_50 ) ;
ASSERT ( V_14 -> V_330 . V_296 == NULL ) ;
F_268 ( V_296 ) ;
V_70 = V_14 -> V_21 . V_22 + V_14 -> V_21 . V_33 ;
F_6 ( V_14 ) ;
}
}
int F_544 ( struct V_12 * V_13 )
{
struct V_1 * V_14 ;
struct V_110 * V_94 ;
struct V_48 * V_51 ;
struct V_15 * V_30 ;
F_71 ( & V_13 -> V_83 ) ;
while ( ! F_183 ( & V_13 -> V_108 ) ) {
V_51 = F_185 ( V_13 -> V_108 . V_79 ,
struct V_48 , V_98 ) ;
F_196 ( & V_51 -> V_98 ) ;
F_26 ( V_51 ) ;
}
F_73 ( & V_13 -> V_83 ) ;
F_11 ( & V_13 -> V_533 ) ;
while ( ! F_183 ( & V_13 -> V_535 ) ) {
V_14 = F_274 ( & V_13 -> V_535 ,
struct V_1 ,
V_534 ) ;
F_275 ( & V_14 -> V_534 ) ;
F_6 ( V_14 ) ;
}
F_13 ( & V_13 -> V_533 ) ;
F_11 ( & V_13 -> V_18 ) ;
while ( ( V_30 = F_202 ( & V_13 -> V_19 ) ) != NULL ) {
V_14 = F_12 ( V_30 , struct V_1 ,
V_20 ) ;
F_195 ( & V_14 -> V_20 ,
& V_13 -> V_19 ) ;
F_545 ( & V_14 -> V_20 ) ;
F_13 ( & V_13 -> V_18 ) ;
F_71 ( & V_14 -> V_94 -> V_351 ) ;
F_196 ( & V_14 -> V_98 ) ;
F_73 ( & V_14 -> V_94 -> V_351 ) ;
if ( V_14 -> V_3 == V_106 )
F_438 ( V_14 ) ;
if ( V_14 -> V_3 == V_102 ||
V_14 -> V_3 == V_5 )
F_19 ( V_13 -> V_63 , V_14 ) ;
F_546 ( V_14 ) ;
ASSERT ( F_183 ( & V_14 -> V_328 ) ) ;
ASSERT ( F_183 ( & V_14 -> V_329 ) ) ;
ASSERT ( F_183 ( & V_14 -> V_534 ) ) ;
ASSERT ( F_213 ( & V_14 -> V_8 ) == 1 ) ;
F_6 ( V_14 ) ;
F_11 ( & V_13 -> V_18 ) ;
}
F_13 ( & V_13 -> V_18 ) ;
F_547 () ;
F_382 ( V_13 ) ;
while ( ! F_183 ( & V_13 -> V_94 ) ) {
int V_42 ;
V_94 = F_185 ( V_13 -> V_94 . V_79 ,
struct V_110 ,
V_98 ) ;
if ( F_8 ( V_94 -> V_352 > 0 ||
V_94 -> V_353 > 0 ||
V_94 -> V_354 > 0 ) )
F_331 ( V_13 , V_94 , 0 , 0 ) ;
F_196 ( & V_94 -> V_98 ) ;
for ( V_42 = 0 ; V_42 < V_349 ; V_42 ++ ) {
struct V_708 * V_363 ;
V_363 = V_94 -> V_709 [ V_42 ] ;
V_94 -> V_709 [ V_42 ] = NULL ;
if ( V_363 ) {
F_548 ( V_363 ) ;
F_549 ( V_363 ) ;
}
}
F_548 ( & V_94 -> V_363 ) ;
F_549 ( & V_94 -> V_363 ) ;
}
return 0 ;
}
static void F_550 ( struct V_110 * V_94 ,
struct V_1 * V_2 )
{
int V_595 = F_440 ( V_2 ) ;
bool V_253 = false ;
F_71 ( & V_94 -> V_351 ) ;
if ( F_183 ( & V_94 -> V_350 [ V_595 ] ) )
V_253 = true ;
F_72 ( & V_2 -> V_98 , & V_94 -> V_350 [ V_595 ] ) ;
F_73 ( & V_94 -> V_351 ) ;
if ( V_253 ) {
struct V_710 * V_711 ;
int V_29 ;
V_711 = F_61 ( sizeof( * V_711 ) , V_97 ) ;
if ( ! V_711 )
goto V_712;
V_711 -> V_384 = V_595 ;
F_551 ( & V_711 -> V_363 , & V_713 ) ;
V_29 = F_552 ( & V_711 -> V_363 , & V_94 -> V_363 ,
L_9 , F_441 ( V_595 ) ) ;
if ( V_29 ) {
F_549 ( & V_711 -> V_363 ) ;
goto V_712;
}
V_94 -> V_709 [ V_595 ] = & V_711 -> V_363 ;
}
return;
V_712:
F_425 ( V_2 -> V_37 ,
L_45 ) ;
}
static struct V_1 *
F_553 ( struct V_34 * V_35 , T_2 V_32 , T_2 V_59 )
{
struct V_1 * V_2 ;
V_2 = F_61 ( sizeof( * V_2 ) , V_97 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_11 = F_61 ( sizeof( * V_2 -> V_11 ) ,
V_97 ) ;
if ( ! V_2 -> V_11 ) {
F_9 ( V_2 ) ;
return NULL ;
}
V_2 -> V_21 . V_22 = V_32 ;
V_2 -> V_21 . V_33 = V_59 ;
V_2 -> V_21 . type = V_187 ;
V_2 -> V_55 = V_35 -> V_55 ;
V_2 -> V_37 = V_35 -> V_37 ;
V_2 -> V_714 = F_554 ( V_35 ,
& V_35 -> V_37 -> V_706 ,
V_32 ) ;
F_555 ( V_2 ) ;
F_65 ( & V_2 -> V_8 , 1 ) ;
F_293 ( & V_2 -> V_50 ) ;
F_292 ( & V_2 -> V_587 ) ;
F_62 ( & V_2 -> V_98 ) ;
F_62 ( & V_2 -> V_715 ) ;
F_62 ( & V_2 -> V_534 ) ;
F_62 ( & V_2 -> V_688 ) ;
F_62 ( & V_2 -> V_328 ) ;
F_62 ( & V_2 -> V_329 ) ;
F_556 ( V_2 ) ;
F_65 ( & V_2 -> V_716 , 0 ) ;
F_63 ( & V_2 -> V_717 ) ;
return V_2 ;
}
int F_557 ( struct V_34 * V_35 )
{
struct V_64 * V_65 ;
int V_29 ;
struct V_1 * V_2 ;
struct V_12 * V_13 = V_35 -> V_37 ;
struct V_110 * V_94 ;
struct V_68 V_21 ;
struct V_68 V_146 ;
struct V_66 * V_67 ;
int V_718 = 0 ;
T_2 V_719 ;
T_2 V_720 ;
int V_721 ;
V_720 = F_558 ( V_13 -> V_259 ) ;
V_721 = ! ! ( V_720 & V_722 ) ;
V_35 = V_13 -> V_63 ;
V_21 . V_22 = 0 ;
V_21 . V_33 = 0 ;
V_21 . type = V_187 ;
V_65 = F_34 () ;
if ( ! V_65 )
return - V_73 ;
V_65 -> V_76 = V_77 ;
V_719 = F_559 ( V_35 -> V_37 -> V_259 ) ;
if ( F_264 ( V_35 -> V_37 , V_310 ) &&
F_560 ( V_35 -> V_37 -> V_259 ) != V_719 )
V_718 = 1 ;
if ( F_264 ( V_35 -> V_37 , V_723 ) )
V_718 = 1 ;
while ( 1 ) {
V_29 = F_538 ( V_35 , V_65 , & V_21 ) ;
if ( V_29 > 0 )
break;
if ( V_29 != 0 )
goto error;
V_67 = V_65 -> V_81 [ 0 ] ;
F_41 ( V_67 , & V_146 , V_65 -> V_82 [ 0 ] ) ;
V_2 = F_553 ( V_35 , V_146 . V_22 ,
V_146 . V_33 ) ;
if ( ! V_2 ) {
V_29 = - V_73 ;
goto error;
}
if ( V_718 ) {
if ( F_264 ( V_35 -> V_37 , V_310 ) )
V_2 -> V_303 = V_319 ;
}
F_561 ( V_67 , & V_2 -> V_95 ,
F_252 ( V_67 , V_65 -> V_82 [ 0 ] ) ,
sizeof( V_2 -> V_95 ) ) ;
V_2 -> V_7 = F_562 ( & V_2 -> V_95 ) ;
if ( ! V_721 &&
( ( V_2 -> V_7 & V_53 ) &&
( V_2 -> V_7 & V_337 ) ) ) {
F_173 ( V_13 ,
L_46 ,
V_2 -> V_21 . V_22 ) ;
V_29 = - V_537 ;
goto error;
}
V_21 . V_22 = V_146 . V_22 + V_146 . V_33 ;
F_45 ( V_65 ) ;
V_29 = F_21 ( V_35 , V_2 ) ;
if ( V_29 ) {
F_19 ( V_35 , V_2 ) ;
F_6 ( V_2 ) ;
goto error;
}
if ( V_146 . V_33 == F_58 ( & V_2 -> V_95 ) ) {
V_2 -> V_105 = ( T_2 ) - 1 ;
V_2 -> V_3 = V_4 ;
F_19 ( V_35 , V_2 ) ;
} else if ( F_58 ( & V_2 -> V_95 ) == 0 ) {
V_2 -> V_105 = ( T_2 ) - 1 ;
V_2 -> V_3 = V_4 ;
F_29 ( V_2 , V_35 -> V_37 ,
V_146 . V_22 ,
V_146 . V_22 +
V_146 . V_33 ) ;
F_19 ( V_35 , V_2 ) ;
}
V_29 = F_10 ( V_35 -> V_37 , V_2 ) ;
if ( V_29 ) {
F_546 ( V_2 ) ;
F_6 ( V_2 ) ;
goto error;
}
F_563 ( V_35 -> V_37 , V_2 , 0 ) ;
V_29 = F_289 ( V_13 , V_2 -> V_7 , V_146 . V_33 ,
F_58 ( & V_2 -> V_95 ) ,
V_2 -> V_45 , & V_94 ) ;
if ( V_29 ) {
F_546 ( V_2 ) ;
F_11 ( & V_13 -> V_18 ) ;
F_195 ( & V_2 -> V_20 ,
& V_13 -> V_19 ) ;
F_545 ( & V_2 -> V_20 ) ;
F_13 ( & V_13 -> V_18 ) ;
F_6 ( V_2 ) ;
goto error;
}
V_2 -> V_94 = V_94 ;
F_550 ( V_94 , V_2 ) ;
F_296 ( V_35 -> V_37 , V_2 -> V_7 ) ;
if ( F_564 ( V_35 , V_2 -> V_21 . V_22 ) ) {
F_528 ( V_2 , 1 ) ;
} else if ( F_58 ( & V_2 -> V_95 ) == 0 ) {
F_11 ( & V_13 -> V_533 ) ;
if ( F_183 ( & V_2 -> V_534 ) ) {
F_4 ( V_2 ) ;
F_72 ( & V_2 -> V_534 ,
& V_13 -> V_535 ) ;
}
F_13 ( & V_13 -> V_533 ) ;
}
}
F_79 (space_info, &root->fs_info->space_info, list) {
if ( ! ( F_303 ( V_35 , V_94 -> V_7 ) &
( V_344 |
V_343 |
V_391 |
V_390 |
V_342 ) ) )
continue;
F_184 (cache,
&space_info->block_groups[BTRFS_RAID_RAID0],
list)
F_528 ( V_2 , 1 ) ;
F_184 (cache,
&space_info->block_groups[BTRFS_RAID_SINGLE],
list)
F_528 ( V_2 , 1 ) ;
}
F_381 ( V_13 ) ;
V_29 = 0 ;
error:
F_53 ( V_65 ) ;
return V_29 ;
}
void F_228 ( struct V_116 * V_117 ,
struct V_34 * V_35 )
{
struct V_1 * V_14 , * V_315 ;
struct V_34 * V_63 = V_35 -> V_37 -> V_63 ;
struct V_724 V_95 ;
struct V_68 V_21 ;
int V_29 = 0 ;
bool V_276 = V_117 -> V_276 ;
V_117 -> V_276 = false ;
F_270 (block_group, tmp, &trans->new_bgs, bg_list) {
if ( V_29 )
goto V_79;
F_11 ( & V_14 -> V_50 ) ;
memcpy ( & V_95 , & V_14 -> V_95 , sizeof( V_95 ) ) ;
memcpy ( & V_21 , & V_14 -> V_21 , sizeof( V_21 ) ) ;
F_13 ( & V_14 -> V_50 ) ;
V_29 = F_565 ( V_117 , V_63 , & V_21 , & V_95 ,
sizeof( V_95 ) ) ;
if ( V_29 )
F_162 ( V_117 , V_29 ) ;
V_29 = F_566 ( V_117 , V_63 ,
V_21 . V_22 , V_21 . V_33 ) ;
if ( V_29 )
F_162 ( V_117 , V_29 ) ;
F_567 ( V_117 , V_35 -> V_37 , V_14 ) ;
V_79:
F_275 ( & V_14 -> V_534 ) ;
}
V_117 -> V_276 = V_276 ;
}
int F_568 ( struct V_116 * V_117 ,
struct V_34 * V_35 , T_2 V_93 ,
T_2 type , T_2 V_725 , T_2 V_726 ,
T_2 V_59 )
{
int V_29 ;
struct V_34 * V_63 ;
struct V_1 * V_2 ;
V_63 = V_35 -> V_37 -> V_63 ;
F_569 ( V_35 -> V_37 , V_117 ) ;
V_2 = F_553 ( V_35 , V_726 , V_59 ) ;
if ( ! V_2 )
return - V_73 ;
F_405 ( & V_2 -> V_95 , V_93 ) ;
F_570 ( & V_2 -> V_95 , V_725 ) ;
F_571 ( & V_2 -> V_95 , type ) ;
V_2 -> V_7 = type ;
V_2 -> V_105 = ( T_2 ) - 1 ;
V_2 -> V_3 = V_4 ;
V_2 -> V_727 = 1 ;
V_29 = F_21 ( V_35 , V_2 ) ;
if ( V_29 ) {
F_19 ( V_35 , V_2 ) ;
F_6 ( V_2 ) ;
return V_29 ;
}
F_29 ( V_2 , V_35 -> V_37 , V_726 ,
V_726 + V_59 ) ;
F_19 ( V_35 , V_2 ) ;
#ifdef F_36
if ( F_37 ( V_35 , V_2 ) ) {
T_2 V_728 = V_59 - V_93 ;
V_93 += V_728 >> 1 ;
F_27 ( V_35 , V_2 ) ;
}
#endif
V_29 = F_289 ( V_35 -> V_37 , V_2 -> V_7 , 0 , 0 , 0 ,
& V_2 -> V_94 ) ;
if ( V_29 ) {
F_546 ( V_2 ) ;
F_6 ( V_2 ) ;
return V_29 ;
}
V_29 = F_10 ( V_35 -> V_37 , V_2 ) ;
if ( V_29 ) {
F_546 ( V_2 ) ;
F_6 ( V_2 ) ;
return V_29 ;
}
F_563 ( V_35 -> V_37 , V_2 , 1 ) ;
V_29 = F_289 ( V_35 -> V_37 , V_2 -> V_7 , V_59 , V_93 ,
V_2 -> V_45 , & V_2 -> V_94 ) ;
if ( V_29 ) {
F_546 ( V_2 ) ;
F_11 ( & V_35 -> V_37 -> V_18 ) ;
F_195 ( & V_2 -> V_20 ,
& V_35 -> V_37 -> V_19 ) ;
F_545 ( & V_2 -> V_20 ) ;
F_13 ( & V_35 -> V_37 -> V_18 ) ;
F_6 ( V_2 ) ;
return V_29 ;
}
F_379 ( V_35 -> V_37 ) ;
F_550 ( V_2 -> V_94 , V_2 ) ;
F_72 ( & V_2 -> V_534 , & V_117 -> V_279 ) ;
F_296 ( V_63 -> V_37 , type ) ;
return 0 ;
}
static void F_572 ( struct V_12 * V_37 , T_2 V_7 )
{
T_2 V_367 = F_297 ( V_7 ) &
V_368 ;
F_298 ( & V_37 -> V_369 ) ;
if ( V_7 & V_337 )
V_37 -> V_370 &= ~ V_367 ;
if ( V_7 & V_53 )
V_37 -> V_371 &= ~ V_367 ;
if ( V_7 & V_338 )
V_37 -> V_372 &= ~ V_367 ;
F_299 ( & V_37 -> V_369 ) ;
}
int F_573 ( struct V_116 * V_117 ,
struct V_34 * V_35 , T_2 V_729 ,
struct V_704 * V_705 )
{
struct V_64 * V_65 ;
struct V_1 * V_14 ;
struct V_545 * V_553 ;
struct V_34 * V_87 = V_35 -> V_37 -> V_87 ;
struct V_68 V_21 ;
struct V_296 * V_296 ;
struct V_708 * V_363 = NULL ;
int V_29 ;
int V_595 ;
int V_341 ;
struct V_48 * V_51 = NULL ;
bool V_730 ;
V_35 = V_35 -> V_37 -> V_63 ;
V_14 = F_76 ( V_35 -> V_37 , V_729 ) ;
F_32 ( ! V_14 ) ;
F_32 ( ! V_14 -> V_305 ) ;
F_19 ( V_35 , V_14 ) ;
memcpy ( & V_21 , & V_14 -> V_21 , sizeof( V_21 ) ) ;
V_595 = F_440 ( V_14 ) ;
if ( V_14 -> V_7 & ( V_342 |
V_343 |
V_344 ) )
V_341 = 2 ;
else
V_341 = 1 ;
V_553 = & V_35 -> V_37 -> V_551 ;
F_11 ( & V_553 -> V_589 ) ;
F_451 ( V_14 , V_553 ) ;
F_13 ( & V_553 -> V_589 ) ;
V_553 = & V_35 -> V_37 -> V_549 ;
F_11 ( & V_553 -> V_589 ) ;
F_451 ( V_14 , V_553 ) ;
F_13 ( & V_553 -> V_589 ) ;
V_65 = F_34 () ;
if ( ! V_65 ) {
V_29 = - V_73 ;
goto V_80;
}
V_296 = F_257 ( V_87 , V_14 , V_65 ) ;
F_49 ( & V_117 -> V_134 -> V_327 ) ;
F_11 ( & V_117 -> V_134 -> V_326 ) ;
if ( ! F_183 ( & V_14 -> V_329 ) ) {
F_275 ( & V_14 -> V_329 ) ;
F_8 ( ! F_217 ( V_296 ) && V_296 != V_14 -> V_330 . V_296 ) ;
F_13 ( & V_117 -> V_134 -> V_326 ) ;
F_276 ( V_35 , V_117 , V_14 ,
& V_14 -> V_330 , V_65 ,
V_14 -> V_21 . V_22 ) ;
F_6 ( V_14 ) ;
F_11 ( & V_117 -> V_134 -> V_326 ) ;
}
if ( ! F_183 ( & V_14 -> V_328 ) ) {
F_275 ( & V_14 -> V_328 ) ;
F_6 ( V_14 ) ;
}
F_13 ( & V_117 -> V_134 -> V_326 ) ;
F_47 ( & V_117 -> V_134 -> V_327 ) ;
if ( ! F_217 ( V_296 ) ) {
V_29 = F_574 ( V_117 , V_296 ) ;
if ( V_29 ) {
F_575 ( V_296 ) ;
goto V_80;
}
F_576 ( V_296 ) ;
F_11 ( & V_14 -> V_50 ) ;
if ( V_14 -> V_172 ) {
V_14 -> V_172 = 0 ;
V_14 -> V_296 = NULL ;
F_13 ( & V_14 -> V_50 ) ;
F_268 ( V_296 ) ;
} else {
F_13 ( & V_14 -> V_50 ) ;
}
F_575 ( V_296 ) ;
}
V_21 . V_22 = V_731 ;
V_21 . V_33 = V_14 -> V_21 . V_22 ;
V_21 . type = 0 ;
V_29 = F_38 ( V_117 , V_87 , & V_21 , V_65 , - 1 , 1 ) ;
if ( V_29 < 0 )
goto V_80;
if ( V_29 > 0 )
F_45 ( V_65 ) ;
if ( V_29 == 0 ) {
V_29 = F_124 ( V_117 , V_87 , V_65 ) ;
if ( V_29 )
goto V_80;
F_45 ( V_65 ) ;
}
F_11 ( & V_35 -> V_37 -> V_18 ) ;
F_195 ( & V_14 -> V_20 ,
& V_35 -> V_37 -> V_19 ) ;
F_545 ( & V_14 -> V_20 ) ;
if ( V_35 -> V_37 -> V_26 == V_14 -> V_21 . V_22 )
V_35 -> V_37 -> V_26 = ( T_2 ) - 1 ;
F_13 ( & V_35 -> V_37 -> V_18 ) ;
F_71 ( & V_14 -> V_94 -> V_351 ) ;
F_275 ( & V_14 -> V_98 ) ;
if ( F_183 ( & V_14 -> V_94 -> V_350 [ V_595 ] ) ) {
V_363 = V_14 -> V_94 -> V_709 [ V_595 ] ;
V_14 -> V_94 -> V_709 [ V_595 ] = NULL ;
F_572 ( V_35 -> V_37 , V_14 -> V_7 ) ;
}
F_73 ( & V_14 -> V_94 -> V_351 ) ;
if ( V_363 ) {
F_548 ( V_363 ) ;
F_549 ( V_363 ) ;
}
if ( V_14 -> V_107 )
V_51 = F_25 ( V_14 ) ;
if ( V_14 -> V_3 == V_106 )
F_438 ( V_14 ) ;
if ( V_14 -> V_107 ) {
F_71 ( & V_35 -> V_37 -> V_83 ) ;
if ( ! V_51 ) {
struct V_48 * V_49 ;
F_184 (ctl,
&root->fs_info->caching_block_groups, list)
if ( V_49 -> V_14 == V_14 ) {
V_51 = V_49 ;
F_5 ( & V_51 -> V_8 ) ;
break;
}
}
if ( V_51 )
F_275 ( & V_51 -> V_98 ) ;
F_73 ( & V_35 -> V_37 -> V_83 ) ;
if ( V_51 ) {
F_26 ( V_51 ) ;
F_26 ( V_51 ) ;
}
}
F_11 ( & V_117 -> V_134 -> V_326 ) ;
if ( ! F_183 ( & V_14 -> V_328 ) ) {
F_8 ( 1 ) ;
}
if ( ! F_183 ( & V_14 -> V_329 ) ) {
F_8 ( 1 ) ;
}
F_13 ( & V_117 -> V_134 -> V_326 ) ;
F_546 ( V_14 ) ;
F_11 ( & V_14 -> V_94 -> V_50 ) ;
F_275 ( & V_14 -> V_688 ) ;
if ( F_264 ( V_35 -> V_37 , V_420 ) ) {
F_8 ( V_14 -> V_94 -> V_339
< V_14 -> V_21 . V_33 ) ;
F_8 ( V_14 -> V_94 -> V_340
< V_14 -> V_21 . V_33 ) ;
F_8 ( V_14 -> V_94 -> V_345
< V_14 -> V_21 . V_33 * V_341 ) ;
}
V_14 -> V_94 -> V_339 -= V_14 -> V_21 . V_33 ;
V_14 -> V_94 -> V_340 -= V_14 -> V_21 . V_33 ;
V_14 -> V_94 -> V_345 -= V_14 -> V_21 . V_33 * V_341 ;
F_13 ( & V_14 -> V_94 -> V_50 ) ;
memcpy ( & V_21 , & V_14 -> V_21 , sizeof( V_21 ) ) ;
F_531 ( V_35 ) ;
if ( ! F_183 ( & V_705 -> V_98 ) ) {
F_542 ( V_705 ) ;
}
F_11 ( & V_14 -> V_50 ) ;
V_14 -> V_732 = 1 ;
V_730 = ( F_213 ( & V_14 -> V_716 ) == 0 ) ;
if ( ! V_730 ) {
F_577 ( & V_705 -> V_98 , & V_35 -> V_37 -> V_733 ) ;
}
F_13 ( & V_14 -> V_50 ) ;
if ( V_730 ) {
struct V_702 * V_703 ;
V_703 = & V_35 -> V_37 -> V_706 . V_707 ;
F_578 ( & V_703 -> V_50 ) ;
F_579 ( V_703 , V_705 ) ;
F_580 ( & V_703 -> V_50 ) ;
F_542 ( V_705 ) ;
}
F_532 ( V_35 ) ;
V_29 = F_581 ( V_117 , V_35 -> V_37 , V_14 ) ;
if ( V_29 )
goto V_80;
F_6 ( V_14 ) ;
F_6 ( V_14 ) ;
V_29 = F_38 ( V_117 , V_35 , & V_21 , V_65 , - 1 , 1 ) ;
if ( V_29 > 0 )
V_29 = - V_183 ;
if ( V_29 < 0 )
goto V_80;
V_29 = F_124 ( V_117 , V_35 , V_65 ) ;
V_80:
F_53 ( V_65 ) ;
return V_29 ;
}
struct V_116 *
F_582 ( struct V_12 * V_37 ,
const T_2 V_726 )
{
struct V_702 * V_703 = & V_37 -> V_706 . V_707 ;
struct V_704 * V_705 ;
struct V_734 * V_735 ;
unsigned int V_736 ;
F_539 ( & V_703 -> V_50 ) ;
V_705 = F_540 ( V_703 , V_726 , 1 ) ;
F_541 ( & V_703 -> V_50 ) ;
ASSERT ( V_705 && V_705 -> V_32 == V_726 ) ;
V_735 = V_705 -> V_734 ;
V_736 = 3 + V_735 -> V_210 ;
F_542 ( V_705 ) ;
return F_583 ( V_37 -> V_63 ,
V_736 , 1 ) ;
}
void F_584 ( struct V_12 * V_37 )
{
struct V_1 * V_14 ;
struct V_110 * V_94 ;
struct V_34 * V_35 = V_37 -> V_63 ;
struct V_116 * V_117 ;
int V_29 = 0 ;
if ( ! F_226 ( V_737 , & V_37 -> V_7 ) )
return;
F_11 ( & V_37 -> V_533 ) ;
while ( ! F_183 ( & V_37 -> V_535 ) ) {
T_2 V_32 , V_31 ;
int V_716 ;
V_14 = F_274 ( & V_37 -> V_535 ,
struct V_1 ,
V_534 ) ;
F_275 ( & V_14 -> V_534 ) ;
V_94 = V_14 -> V_94 ;
if ( V_29 || F_334 ( V_94 ) ) {
F_6 ( V_14 ) ;
continue;
}
F_13 ( & V_37 -> V_533 ) ;
F_49 ( & V_37 -> V_738 ) ;
F_71 ( & V_94 -> V_351 ) ;
F_11 ( & V_14 -> V_50 ) ;
if ( V_14 -> V_10 ||
F_58 ( & V_14 -> V_95 ) ||
V_14 -> V_305 ||
F_585 ( & V_14 -> V_98 ) ) {
F_13 ( & V_14 -> V_50 ) ;
F_73 ( & V_94 -> V_351 ) ;
goto V_79;
}
F_13 ( & V_14 -> V_50 ) ;
V_29 = F_528 ( V_14 , 0 ) ;
F_73 ( & V_94 -> V_351 ) ;
if ( V_29 < 0 ) {
V_29 = 0 ;
goto V_79;
}
V_117 = F_582 ( V_37 ,
V_14 -> V_21 . V_22 ) ;
if ( F_217 ( V_117 ) ) {
F_535 ( V_35 , V_14 ) ;
V_29 = F_218 ( V_117 ) ;
goto V_79;
}
V_32 = V_14 -> V_21 . V_22 ;
V_31 = V_32 + V_14 -> V_21 . V_33 - 1 ;
F_49 ( & V_37 -> V_560 ) ;
V_29 = F_20 ( & V_37 -> V_38 [ 0 ] , V_32 , V_31 ,
V_62 ) ;
if ( V_29 ) {
F_47 ( & V_37 -> V_560 ) ;
F_535 ( V_35 , V_14 ) ;
goto V_739;
}
V_29 = F_20 ( & V_37 -> V_38 [ 1 ] , V_32 , V_31 ,
V_62 ) ;
if ( V_29 ) {
F_47 ( & V_37 -> V_560 ) ;
F_535 ( V_35 , V_14 ) ;
goto V_739;
}
F_47 ( & V_37 -> V_560 ) ;
F_11 ( & V_94 -> V_50 ) ;
F_11 ( & V_14 -> V_50 ) ;
V_94 -> V_352 -= V_14 -> V_9 ;
V_94 -> V_340 += V_14 -> V_9 ;
F_420 ( & V_94 -> V_347 ,
- V_14 -> V_9 ) ;
V_14 -> V_9 = 0 ;
F_13 ( & V_14 -> V_50 ) ;
F_13 ( & V_94 -> V_50 ) ;
V_716 = F_264 ( V_35 -> V_37 , V_561 ) ;
if ( V_716 )
F_586 ( V_14 ) ;
V_29 = F_587 ( V_117 , V_35 ,
V_14 -> V_21 . V_22 ) ;
if ( V_29 ) {
if ( V_716 )
F_423 ( V_14 ) ;
goto V_739;
}
if ( V_716 ) {
F_11 ( & V_37 -> V_533 ) ;
F_588 ( & V_14 -> V_534 ,
& V_117 -> V_134 -> V_557 ) ;
F_13 ( & V_37 -> V_533 ) ;
F_4 ( V_14 ) ;
}
V_739:
F_220 ( V_117 , V_35 ) ;
V_79:
F_47 ( & V_37 -> V_738 ) ;
F_6 ( V_14 ) ;
F_11 ( & V_37 -> V_533 ) ;
}
F_13 ( & V_37 -> V_533 ) ;
}
int F_589 ( struct V_12 * V_37 )
{
struct V_110 * V_94 ;
struct V_740 * V_741 ;
T_2 V_742 ;
T_2 V_7 ;
int V_721 = 0 ;
int V_29 ;
V_741 = V_37 -> V_259 ;
if ( ! F_590 ( V_741 ) )
return - V_537 ;
V_742 = F_558 ( V_741 ) ;
if ( V_742 & V_722 )
V_721 = 1 ;
V_7 = V_338 ;
V_29 = F_289 ( V_37 , V_7 , 0 , 0 , 0 , & V_94 ) ;
if ( V_29 )
goto V_80;
if ( V_721 ) {
V_7 = V_53 | V_337 ;
V_29 = F_289 ( V_37 , V_7 , 0 , 0 , 0 , & V_94 ) ;
} else {
V_7 = V_53 ;
V_29 = F_289 ( V_37 , V_7 , 0 , 0 , 0 , & V_94 ) ;
if ( V_29 )
goto V_80;
V_7 = V_337 ;
V_29 = F_289 ( V_37 , V_7 , 0 , 0 , 0 , & V_94 ) ;
}
V_80:
return V_29 ;
}
int F_591 ( struct V_34 * V_35 , T_2 V_32 , T_2 V_31 )
{
return F_419 ( V_35 , V_32 , V_31 , false ) ;
}
static int F_592 ( struct V_694 * V_695 ,
T_2 V_743 , T_2 * V_562 )
{
T_2 V_32 = 0 , V_47 = 0 ;
int V_29 ;
* V_562 = 0 ;
if ( ! V_695 -> V_744 )
return 0 ;
if ( V_695 -> V_339 <= V_695 -> V_93 )
return 0 ;
V_29 = 0 ;
while ( 1 ) {
struct V_12 * V_37 = V_695 -> V_500 -> V_37 ;
struct V_316 * V_117 ;
T_2 V_211 ;
V_29 = F_593 ( & V_37 -> V_419 ) ;
if ( V_29 )
return V_29 ;
F_50 ( & V_37 -> V_83 ) ;
F_11 ( & V_37 -> V_745 ) ;
V_117 = V_37 -> V_746 ;
if ( V_117 )
F_5 ( & V_117 -> V_747 ) ;
F_13 ( & V_37 -> V_745 ) ;
V_29 = F_594 ( V_117 , V_695 , V_743 , V_32 ,
& V_32 , & V_47 ) ;
if ( V_117 )
F_595 ( V_117 ) ;
if ( V_29 ) {
F_46 ( & V_37 -> V_83 ) ;
F_47 ( & V_37 -> V_419 ) ;
if ( V_29 == - V_312 )
V_29 = 0 ;
break;
}
V_29 = F_148 ( V_695 -> V_194 , V_32 , V_47 , & V_211 ) ;
F_46 ( & V_37 -> V_83 ) ;
F_47 ( & V_37 -> V_419 ) ;
if ( V_29 )
break;
V_32 += V_47 ;
* V_562 += V_211 ;
if ( F_596 ( V_399 ) ) {
V_29 = - V_748 ;
break;
}
F_48 () ;
}
return V_29 ;
}
int F_597 ( struct V_34 * V_35 , struct V_749 * V_750 )
{
struct V_12 * V_37 = V_35 -> V_37 ;
struct V_1 * V_2 = NULL ;
struct V_694 * V_695 ;
struct V_111 * V_751 ;
T_2 V_752 ;
T_2 V_32 ;
T_2 V_31 ;
T_2 V_562 = 0 ;
T_2 V_339 = F_323 ( V_37 -> V_259 ) ;
int V_29 = 0 ;
if ( V_750 -> V_47 == V_339 )
V_2 = F_75 ( V_37 , V_750 -> V_32 ) ;
else
V_2 = F_76 ( V_37 , V_750 -> V_32 ) ;
while ( V_2 ) {
if ( V_2 -> V_21 . V_22 >= ( V_750 -> V_32 + V_750 -> V_47 ) ) {
F_6 ( V_2 ) ;
break;
}
V_32 = F_448 ( V_750 -> V_32 , V_2 -> V_21 . V_22 ) ;
V_31 = F_343 ( V_750 -> V_32 + V_750 -> V_47 ,
V_2 -> V_21 . V_22 + V_2 -> V_21 . V_33 ) ;
if ( V_31 - V_32 >= V_750 -> V_743 ) {
if ( ! F_1 ( V_2 ) ) {
V_29 = F_59 ( V_2 , 0 ) ;
if ( V_29 ) {
F_6 ( V_2 ) ;
break;
}
V_29 = F_438 ( V_2 ) ;
if ( V_29 ) {
F_6 ( V_2 ) ;
break;
}
}
V_29 = F_598 ( V_2 ,
& V_752 ,
V_32 ,
V_31 ,
V_750 -> V_743 ) ;
V_562 += V_752 ;
if ( V_29 ) {
F_6 ( V_2 ) ;
break;
}
}
V_2 = F_254 ( V_37 -> V_87 , V_2 ) ;
}
F_49 ( & V_35 -> V_37 -> V_382 -> V_753 ) ;
V_751 = & V_35 -> V_37 -> V_382 -> V_754 ;
F_184 (device, devices, dev_alloc_list) {
V_29 = F_592 ( V_695 , V_750 -> V_743 ,
& V_752 ) ;
if ( V_29 )
break;
V_562 += V_752 ;
}
F_47 ( & V_35 -> V_37 -> V_382 -> V_753 ) ;
V_750 -> V_47 = V_562 ;
return V_29 ;
}
void F_599 ( struct V_34 * V_35 )
{
F_600 ( & V_35 -> V_755 -> V_756 ) ;
F_2 () ;
if ( F_601 ( & V_35 -> V_755 -> V_89 ) )
F_52 ( & V_35 -> V_755 -> V_89 ) ;
}
int F_602 ( struct V_34 * V_35 )
{
if ( F_213 ( & V_35 -> V_757 ) )
return 0 ;
F_603 ( & V_35 -> V_755 -> V_756 ) ;
F_2 () ;
if ( F_213 ( & V_35 -> V_757 ) ) {
F_599 ( V_35 ) ;
return 0 ;
}
return 1 ;
}
static int F_604 ( T_7 * V_336 )
{
F_68 () ;
return 0 ;
}
void F_605 ( struct V_34 * V_35 )
{
while ( true ) {
int V_29 ;
V_29 = F_602 ( V_35 ) ;
if ( V_29 )
break;
F_287 ( & V_35 -> V_757 ,
F_604 ,
V_101 ) ;
}
}
