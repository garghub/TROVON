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
static void F_27 ( struct V_34 * V_35 ,
struct V_1 * V_14 )
{
T_2 V_32 = V_14 -> V_21 . V_22 ;
T_2 V_49 = V_14 -> V_21 . V_33 ;
T_2 V_54 = V_14 -> V_7 & V_55 ?
V_35 -> V_56 : V_35 -> V_57 ;
T_2 V_58 = V_54 << 1 ;
while ( V_49 > V_54 ) {
F_28 ( V_14 , V_32 , V_54 ) ;
V_32 += V_58 ;
if ( V_49 < V_58 )
V_49 = 0 ;
else
V_49 -= V_58 ;
}
}
static T_2 F_29 ( struct V_1 * V_14 ,
struct V_12 * V_13 , T_2 V_32 , T_2 V_31 )
{
T_2 V_59 , V_60 , V_61 , V_62 = 0 ;
int V_29 ;
while ( V_32 < V_31 ) {
V_29 = F_30 ( V_13 -> V_63 , V_32 ,
& V_59 , & V_60 ,
V_64 | V_39 ,
NULL ) ;
if ( V_29 )
break;
if ( V_59 <= V_32 ) {
V_32 = V_60 + 1 ;
} else if ( V_59 > V_32 && V_59 < V_31 ) {
V_61 = V_59 - V_32 ;
V_62 += V_61 ;
V_29 = F_31 ( V_14 , V_32 ,
V_61 ) ;
F_32 ( V_29 ) ;
V_32 = V_60 + 1 ;
} else {
break;
}
}
if ( V_32 < V_31 ) {
V_61 = V_31 - V_32 ;
V_62 += V_61 ;
V_29 = F_31 ( V_14 , V_32 , V_61 ) ;
F_32 ( V_29 ) ;
}
return V_62 ;
}
static T_1 void F_33 ( struct V_65 * V_66 )
{
struct V_1 * V_14 ;
struct V_12 * V_37 ;
struct V_50 * V_53 ;
struct V_34 * V_67 ;
struct V_68 * V_69 ;
struct V_70 * V_71 ;
struct V_72 V_21 ;
T_2 V_73 = 0 ;
T_2 V_74 = 0 ;
T_3 V_75 ;
int V_29 = - V_76 ;
bool V_77 = true ;
V_53 = F_34 ( V_66 , struct V_50 , V_66 ) ;
V_14 = V_53 -> V_14 ;
V_37 = V_14 -> V_37 ;
V_67 = V_37 -> V_67 ;
V_69 = F_35 () ;
if ( ! V_69 )
goto V_78;
V_74 = F_36 ( T_2 , V_14 -> V_21 . V_22 , V_45 ) ;
#ifdef F_37
if ( F_38 ( V_67 , V_14 ) )
V_77 = false ;
#endif
V_69 -> V_79 = 1 ;
V_69 -> V_80 = 1 ;
V_69 -> V_81 = 1 ;
V_21 . V_22 = V_74 ;
V_21 . V_33 = 0 ;
V_21 . type = V_82 ;
V_83:
F_39 ( & V_53 -> V_84 ) ;
F_40 ( & V_37 -> V_85 ) ;
V_86:
V_29 = F_41 ( NULL , V_67 , & V_21 , V_69 , 0 , 0 ) ;
if ( V_29 < 0 )
goto V_87;
V_71 = V_69 -> V_88 [ 0 ] ;
V_75 = F_42 ( V_71 ) ;
while ( 1 ) {
if ( F_43 ( V_37 ) > 1 ) {
V_74 = ( T_2 ) - 1 ;
break;
}
if ( V_69 -> V_89 [ 0 ] < V_75 ) {
F_44 ( V_71 , & V_21 , V_69 -> V_89 [ 0 ] ) ;
} else {
V_29 = F_45 ( V_69 , 0 , & V_21 ) ;
if ( V_29 )
break;
if ( F_46 () ||
F_47 ( & V_37 -> V_85 ) ) {
if ( V_77 )
V_53 -> V_90 = V_74 ;
F_48 ( V_69 ) ;
F_49 ( & V_37 -> V_85 ) ;
F_50 ( & V_53 -> V_84 ) ;
F_51 () ;
goto V_83;
}
V_29 = F_52 ( V_67 , V_69 ) ;
if ( V_29 < 0 )
goto V_87;
if ( V_29 )
break;
V_71 = V_69 -> V_88 [ 0 ] ;
V_75 = F_42 ( V_71 ) ;
continue;
}
if ( V_21 . V_22 < V_74 ) {
V_21 . V_22 = V_74 ;
V_21 . V_33 = 0 ;
V_21 . type = V_82 ;
if ( V_77 )
V_53 -> V_90 = V_74 ;
F_48 ( V_69 ) ;
goto V_86;
}
if ( V_21 . V_22 < V_14 -> V_21 . V_22 ) {
V_69 -> V_89 [ 0 ] ++ ;
continue;
}
if ( V_21 . V_22 >= V_14 -> V_21 . V_22 +
V_14 -> V_21 . V_33 )
break;
if ( V_21 . type == V_82 ||
V_21 . type == V_91 ) {
V_73 += F_29 ( V_14 ,
V_37 , V_74 ,
V_21 . V_22 ) ;
if ( V_21 . type == V_91 )
V_74 = V_21 . V_22 +
V_37 -> V_92 -> V_56 ;
else
V_74 = V_21 . V_22 + V_21 . V_33 ;
if ( V_73 > ( 1024 * 1024 * 2 ) ) {
V_73 = 0 ;
if ( V_77 )
F_53 ( & V_53 -> V_93 ) ;
}
}
V_69 -> V_89 [ 0 ] ++ ;
}
V_29 = 0 ;
V_73 += F_29 ( V_14 , V_37 , V_74 ,
V_14 -> V_21 . V_22 +
V_14 -> V_21 . V_33 ) ;
F_11 ( & V_14 -> V_52 ) ;
V_14 -> V_53 = NULL ;
V_14 -> V_3 = V_4 ;
F_13 ( & V_14 -> V_52 ) ;
#ifdef F_37
if ( F_38 ( V_67 , V_14 ) ) {
T_2 V_94 ;
F_11 ( & V_14 -> V_95 -> V_52 ) ;
F_11 ( & V_14 -> V_52 ) ;
V_94 = V_14 -> V_21 . V_33 -
F_54 ( & V_14 -> V_96 ) ;
V_14 -> V_95 -> V_94 += V_94 >> 1 ;
F_13 ( & V_14 -> V_52 ) ;
F_13 ( & V_14 -> V_95 -> V_52 ) ;
F_27 ( V_67 , V_14 ) ;
}
#endif
V_53 -> V_90 = ( T_2 ) - 1 ;
V_87:
F_55 ( V_69 ) ;
F_49 ( & V_37 -> V_85 ) ;
F_19 ( V_67 , V_14 ) ;
F_50 ( & V_53 -> V_84 ) ;
V_78:
if ( V_29 ) {
F_11 ( & V_14 -> V_52 ) ;
V_14 -> V_53 = NULL ;
V_14 -> V_3 = V_5 ;
F_13 ( & V_14 -> V_52 ) ;
}
F_53 ( & V_53 -> V_93 ) ;
F_26 ( V_53 ) ;
F_6 ( V_14 ) ;
}
static int F_56 ( struct V_1 * V_2 ,
int V_97 )
{
F_57 ( V_93 ) ;
struct V_12 * V_37 = V_2 -> V_37 ;
struct V_50 * V_53 ;
int V_29 = 0 ;
V_53 = F_58 ( sizeof( * V_53 ) , V_40 ) ;
if ( ! V_53 )
return - V_76 ;
F_59 ( & V_53 -> V_98 ) ;
F_60 ( & V_53 -> V_84 ) ;
F_61 ( & V_53 -> V_93 ) ;
V_53 -> V_14 = V_2 ;
V_53 -> V_90 = V_2 -> V_21 . V_22 ;
F_62 ( & V_53 -> V_8 , 1 ) ;
F_63 ( & V_53 -> V_66 , V_99 ,
F_33 , NULL , NULL ) ;
F_11 ( & V_2 -> V_52 ) ;
while ( V_2 -> V_3 == V_100 ) {
struct V_50 * V_51 ;
V_51 = V_2 -> V_53 ;
F_5 ( & V_51 -> V_8 ) ;
F_64 ( & V_51 -> V_93 , & V_93 , V_101 ) ;
F_13 ( & V_2 -> V_52 ) ;
F_65 () ;
F_66 ( & V_51 -> V_93 , & V_93 ) ;
F_26 ( V_51 ) ;
F_11 ( & V_2 -> V_52 ) ;
}
if ( V_2 -> V_3 != V_102 ) {
F_13 ( & V_2 -> V_52 ) ;
F_9 ( V_53 ) ;
return 0 ;
}
F_8 ( V_2 -> V_53 ) ;
V_2 -> V_53 = V_53 ;
V_2 -> V_3 = V_100 ;
F_13 ( & V_2 -> V_52 ) ;
if ( V_37 -> V_103 & V_104 ) {
F_39 ( & V_53 -> V_84 ) ;
V_29 = F_67 ( V_37 , V_2 ) ;
F_11 ( & V_2 -> V_52 ) ;
if ( V_29 == 1 ) {
V_2 -> V_53 = NULL ;
V_2 -> V_3 = V_4 ;
V_2 -> V_105 = ( T_2 ) - 1 ;
V_53 -> V_90 = ( T_2 ) - 1 ;
} else {
if ( V_97 ) {
V_2 -> V_53 = NULL ;
V_2 -> V_3 = V_102 ;
} else {
V_2 -> V_3 = V_106 ;
V_2 -> V_107 = 1 ;
}
}
F_13 ( & V_2 -> V_52 ) ;
#ifdef F_37
if ( V_29 == 1 &&
F_38 ( V_37 -> V_67 ,
V_2 ) ) {
T_2 V_94 ;
F_11 ( & V_2 -> V_95 -> V_52 ) ;
F_11 ( & V_2 -> V_52 ) ;
V_94 = V_2 -> V_21 . V_33 -
F_54 ( & V_2 -> V_96 ) ;
V_2 -> V_95 -> V_94 += V_94 >> 1 ;
F_13 ( & V_2 -> V_52 ) ;
F_13 ( & V_2 -> V_95 -> V_52 ) ;
F_27 ( V_37 -> V_67 , V_2 ) ;
}
#endif
F_50 ( & V_53 -> V_84 ) ;
F_53 ( & V_53 -> V_93 ) ;
if ( V_29 == 1 ) {
F_26 ( V_53 ) ;
F_19 ( V_37 -> V_67 , V_2 ) ;
return 0 ;
}
} else {
F_11 ( & V_2 -> V_52 ) ;
if ( V_97 ) {
V_2 -> V_53 = NULL ;
V_2 -> V_3 = V_102 ;
} else {
V_2 -> V_3 = V_106 ;
V_2 -> V_107 = 1 ;
}
F_13 ( & V_2 -> V_52 ) ;
F_53 ( & V_53 -> V_93 ) ;
}
if ( V_97 ) {
F_26 ( V_53 ) ;
return 0 ;
}
F_68 ( & V_37 -> V_85 ) ;
F_5 ( & V_53 -> V_8 ) ;
F_69 ( & V_53 -> V_98 , & V_37 -> V_108 ) ;
F_70 ( & V_37 -> V_85 ) ;
F_4 ( V_2 ) ;
F_71 ( V_37 -> V_109 , & V_53 -> V_66 ) ;
return V_29 ;
}
static struct V_1 *
F_72 ( struct V_12 * V_13 , T_2 V_27 )
{
struct V_1 * V_2 ;
V_2 = F_16 ( V_13 , V_27 , 0 ) ;
return V_2 ;
}
struct V_1 * F_73 (
struct V_12 * V_13 ,
T_2 V_27 )
{
struct V_1 * V_2 ;
V_2 = F_16 ( V_13 , V_27 , 1 ) ;
return V_2 ;
}
static struct V_110 * F_74 ( struct V_12 * V_13 ,
T_2 V_7 )
{
struct V_111 * V_112 = & V_13 -> V_95 ;
struct V_110 * V_113 ;
V_7 &= V_114 ;
F_75 () ;
F_76 (found, head, list) {
if ( V_113 -> V_7 & V_7 ) {
F_77 () ;
return V_113 ;
}
}
F_77 () ;
return NULL ;
}
void F_78 ( struct V_12 * V_13 )
{
struct V_111 * V_112 = & V_13 -> V_95 ;
struct V_110 * V_113 ;
F_75 () ;
F_76 (found, head, list)
V_113 -> V_115 = 0 ;
F_77 () ;
}
int F_79 ( struct V_34 * V_35 , T_2 V_32 , T_2 V_49 )
{
int V_29 ;
struct V_72 V_21 ;
struct V_68 * V_69 ;
V_69 = F_35 () ;
if ( ! V_69 )
return - V_76 ;
V_21 . V_22 = V_32 ;
V_21 . V_33 = V_49 ;
V_21 . type = V_82 ;
V_29 = F_41 ( NULL , V_35 -> V_37 -> V_67 , & V_21 , V_69 ,
0 , 0 ) ;
F_55 ( V_69 ) ;
return V_29 ;
}
int F_80 ( struct V_116 * V_117 ,
struct V_34 * V_35 , T_2 V_27 ,
T_2 V_33 , int V_118 , T_2 * V_119 , T_2 * V_7 )
{
struct V_120 * V_112 ;
struct V_121 * V_122 ;
struct V_68 * V_69 ;
struct V_123 * V_124 ;
struct V_70 * V_71 ;
struct V_72 V_21 ;
T_3 V_125 ;
T_2 V_126 ;
T_2 V_127 ;
int V_29 ;
if ( V_118 && ! F_81 ( V_35 -> V_37 , V_128 ) ) {
V_33 = V_35 -> V_56 ;
V_118 = 0 ;
}
V_69 = F_35 () ;
if ( ! V_69 )
return - V_76 ;
if ( ! V_117 ) {
V_69 -> V_79 = 1 ;
V_69 -> V_80 = 1 ;
}
V_129:
V_21 . V_22 = V_27 ;
V_21 . V_33 = V_33 ;
if ( V_118 )
V_21 . type = V_91 ;
else
V_21 . type = V_82 ;
V_29 = F_41 ( V_117 , V_35 -> V_37 -> V_67 ,
& V_21 , V_69 , 0 , 0 ) ;
if ( V_29 < 0 )
goto V_130;
if ( V_29 > 0 && V_118 && V_21 . type == V_91 ) {
if ( V_69 -> V_89 [ 0 ] ) {
V_69 -> V_89 [ 0 ] -- ;
F_44 ( V_69 -> V_88 [ 0 ] , & V_21 ,
V_69 -> V_89 [ 0 ] ) ;
if ( V_21 . V_22 == V_27 &&
V_21 . type == V_82 &&
V_21 . V_33 == V_35 -> V_56 )
V_29 = 0 ;
}
}
if ( V_29 == 0 ) {
V_71 = V_69 -> V_88 [ 0 ] ;
V_125 = F_82 ( V_71 , V_69 -> V_89 [ 0 ] ) ;
if ( V_125 >= sizeof( * V_124 ) ) {
V_124 = F_83 ( V_71 , V_69 -> V_89 [ 0 ] ,
struct V_123 ) ;
V_126 = F_84 ( V_71 , V_124 ) ;
V_127 = F_85 ( V_71 , V_124 ) ;
} else {
#ifdef F_86
struct V_131 * V_132 ;
F_32 ( V_125 != sizeof( * V_132 ) ) ;
V_132 = F_83 ( V_71 , V_69 -> V_89 [ 0 ] ,
struct V_131 ) ;
V_126 = F_87 ( V_71 , V_132 ) ;
V_127 = V_133 ;
#else
F_88 () ;
#endif
}
F_32 ( V_126 == 0 ) ;
} else {
V_126 = 0 ;
V_127 = 0 ;
V_29 = 0 ;
}
if ( ! V_117 )
goto V_78;
V_122 = & V_117 -> V_134 -> V_122 ;
F_11 ( & V_122 -> V_52 ) ;
V_112 = F_89 ( V_117 , V_27 ) ;
if ( V_112 ) {
if ( ! F_90 ( & V_112 -> V_84 ) ) {
F_5 ( & V_112 -> V_135 . V_119 ) ;
F_13 ( & V_122 -> V_52 ) ;
F_48 ( V_69 ) ;
F_39 ( & V_112 -> V_84 ) ;
F_50 ( & V_112 -> V_84 ) ;
F_91 ( & V_112 -> V_135 ) ;
goto V_129;
}
F_11 ( & V_112 -> V_52 ) ;
if ( V_112 -> V_136 && V_112 -> V_136 -> V_137 )
V_127 |= V_112 -> V_136 -> V_138 ;
else
F_32 ( V_126 == 0 ) ;
V_126 += V_112 -> V_135 . V_139 ;
F_13 ( & V_112 -> V_52 ) ;
F_50 ( & V_112 -> V_84 ) ;
}
F_13 ( & V_122 -> V_52 ) ;
V_78:
F_8 ( V_126 == 0 ) ;
if ( V_119 )
* V_119 = V_126 ;
if ( V_7 )
* V_7 = V_127 ;
V_130:
F_55 ( V_69 ) ;
return V_29 ;
}
static int F_92 ( struct V_116 * V_117 ,
struct V_34 * V_35 ,
struct V_68 * V_69 ,
T_2 V_140 , T_3 V_141 )
{
struct V_123 * V_96 ;
struct V_131 * V_132 ;
struct V_142 * V_143 ;
struct V_144 * V_145 ;
struct V_70 * V_71 ;
struct V_72 V_21 ;
struct V_72 V_146 ;
T_3 V_147 = sizeof( * V_96 ) ;
T_2 V_119 ;
int V_29 ;
V_71 = V_69 -> V_88 [ 0 ] ;
F_32 ( F_82 ( V_71 , V_69 -> V_89 [ 0 ] ) != sizeof( * V_132 ) ) ;
F_44 ( V_71 , & V_21 , V_69 -> V_89 [ 0 ] ) ;
V_132 = F_83 ( V_71 , V_69 -> V_89 [ 0 ] ,
struct V_131 ) ;
V_119 = F_87 ( V_71 , V_132 ) ;
if ( V_140 == ( T_2 ) - 1 ) {
while ( 1 ) {
if ( V_69 -> V_89 [ 0 ] >= F_42 ( V_71 ) ) {
V_29 = F_52 ( V_35 , V_69 ) ;
if ( V_29 < 0 )
return V_29 ;
F_32 ( V_29 > 0 ) ;
V_71 = V_69 -> V_88 [ 0 ] ;
}
F_44 ( V_71 , & V_146 ,
V_69 -> V_89 [ 0 ] ) ;
F_32 ( V_21 . V_22 != V_146 . V_22 ) ;
if ( V_146 . type != V_148 ) {
V_69 -> V_89 [ 0 ] ++ ;
continue;
}
V_143 = F_83 ( V_71 , V_69 -> V_89 [ 0 ] ,
struct V_142 ) ;
V_140 = F_93 ( V_71 , V_143 ) ;
break;
}
}
F_48 ( V_69 ) ;
if ( V_140 < V_149 )
V_147 += sizeof( * V_145 ) ;
V_147 -= sizeof( * V_132 ) ;
V_29 = F_41 ( V_117 , V_35 , & V_21 , V_69 ,
V_147 + V_141 , 1 ) ;
if ( V_29 < 0 )
return V_29 ;
F_32 ( V_29 ) ;
F_94 ( V_35 , V_69 , V_147 ) ;
V_71 = V_69 -> V_88 [ 0 ] ;
V_96 = F_83 ( V_71 , V_69 -> V_89 [ 0 ] , struct V_123 ) ;
F_95 ( V_71 , V_96 , V_119 ) ;
F_96 ( V_71 , V_96 , 0 ) ;
if ( V_140 < V_149 ) {
F_97 ( V_71 , V_96 ,
V_150 |
V_133 ) ;
V_145 = (struct V_144 * ) ( V_96 + 1 ) ;
F_98 ( V_71 , 0 , ( unsigned long ) V_145 , sizeof( * V_145 ) ) ;
F_99 ( V_71 , V_145 , ( int ) V_140 ) ;
} else {
F_97 ( V_71 , V_96 , V_151 ) ;
}
F_100 ( V_71 ) ;
return 0 ;
}
static T_2 F_101 ( T_2 V_152 , T_2 V_140 , T_2 V_33 )
{
T_3 V_153 = ~ ( T_3 ) 0 ;
T_3 V_154 = ~ ( T_3 ) 0 ;
T_4 V_155 ;
V_155 = F_102 ( V_152 ) ;
V_153 = F_103 ( V_153 , & V_155 , sizeof( V_155 ) ) ;
V_155 = F_102 ( V_140 ) ;
V_154 = F_103 ( V_154 , & V_155 , sizeof( V_155 ) ) ;
V_155 = F_102 ( V_33 ) ;
V_154 = F_103 ( V_154 , & V_155 , sizeof( V_155 ) ) ;
return ( ( T_2 ) V_153 << 31 ) ^ ( T_2 ) V_154 ;
}
static T_2 F_104 ( struct V_70 * V_71 ,
struct V_156 * V_157 )
{
return F_101 ( F_105 ( V_71 , V_157 ) ,
F_106 ( V_71 , V_157 ) ,
F_107 ( V_71 , V_157 ) ) ;
}
static int F_108 ( struct V_70 * V_71 ,
struct V_156 * V_157 ,
T_2 V_152 , T_2 V_140 , T_2 V_33 )
{
if ( F_105 ( V_71 , V_157 ) != V_152 ||
F_106 ( V_71 , V_157 ) != V_140 ||
F_107 ( V_71 , V_157 ) != V_33 )
return 0 ;
return 1 ;
}
static T_1 int F_109 ( struct V_116 * V_117 ,
struct V_34 * V_35 ,
struct V_68 * V_69 ,
T_2 V_27 , T_2 V_17 ,
T_2 V_152 ,
T_2 V_140 , T_2 V_33 )
{
struct V_72 V_21 ;
struct V_156 * V_157 ;
struct V_70 * V_71 ;
T_3 V_75 ;
int V_29 ;
int V_158 ;
int V_87 = - V_159 ;
V_21 . V_22 = V_27 ;
if ( V_17 ) {
V_21 . type = V_160 ;
V_21 . V_33 = V_17 ;
} else {
V_21 . type = V_161 ;
V_21 . V_33 = F_101 ( V_152 ,
V_140 , V_33 ) ;
}
V_83:
V_158 = 0 ;
V_29 = F_41 ( V_117 , V_35 , & V_21 , V_69 , - 1 , 1 ) ;
if ( V_29 < 0 ) {
V_87 = V_29 ;
goto V_162;
}
if ( V_17 ) {
if ( ! V_29 )
return 0 ;
#ifdef F_86
V_21 . type = V_148 ;
F_48 ( V_69 ) ;
V_29 = F_41 ( V_117 , V_35 , & V_21 , V_69 , - 1 , 1 ) ;
if ( V_29 < 0 ) {
V_87 = V_29 ;
goto V_162;
}
if ( ! V_29 )
return 0 ;
#endif
goto V_162;
}
V_71 = V_69 -> V_88 [ 0 ] ;
V_75 = F_42 ( V_71 ) ;
while ( 1 ) {
if ( V_69 -> V_89 [ 0 ] >= V_75 ) {
V_29 = F_52 ( V_35 , V_69 ) ;
if ( V_29 < 0 )
V_87 = V_29 ;
if ( V_29 )
goto V_162;
V_71 = V_69 -> V_88 [ 0 ] ;
V_75 = F_42 ( V_71 ) ;
V_158 = 1 ;
}
F_44 ( V_71 , & V_21 , V_69 -> V_89 [ 0 ] ) ;
if ( V_21 . V_22 != V_27 ||
V_21 . type != V_161 )
goto V_162;
V_157 = F_83 ( V_71 , V_69 -> V_89 [ 0 ] ,
struct V_156 ) ;
if ( F_108 ( V_71 , V_157 , V_152 ,
V_140 , V_33 ) ) {
if ( V_158 ) {
F_48 ( V_69 ) ;
goto V_83;
}
V_87 = 0 ;
break;
}
V_69 -> V_89 [ 0 ] ++ ;
}
V_162:
return V_87 ;
}
static T_1 int F_110 ( struct V_116 * V_117 ,
struct V_34 * V_35 ,
struct V_68 * V_69 ,
T_2 V_27 , T_2 V_17 ,
T_2 V_152 , T_2 V_140 ,
T_2 V_33 , int V_163 )
{
struct V_72 V_21 ;
struct V_70 * V_71 ;
T_3 V_61 ;
T_3 V_126 ;
int V_29 ;
V_21 . V_22 = V_27 ;
if ( V_17 ) {
V_21 . type = V_160 ;
V_21 . V_33 = V_17 ;
V_61 = sizeof( struct V_164 ) ;
} else {
V_21 . type = V_161 ;
V_21 . V_33 = F_101 ( V_152 ,
V_140 , V_33 ) ;
V_61 = sizeof( struct V_156 ) ;
}
V_29 = F_111 ( V_117 , V_35 , V_69 , & V_21 , V_61 ) ;
if ( V_29 && V_29 != - V_25 )
goto V_162;
V_71 = V_69 -> V_88 [ 0 ] ;
if ( V_17 ) {
struct V_164 * V_157 ;
V_157 = F_83 ( V_71 , V_69 -> V_89 [ 0 ] ,
struct V_164 ) ;
if ( V_29 == 0 ) {
F_112 ( V_71 , V_157 , V_163 ) ;
} else {
V_126 = F_113 ( V_71 , V_157 ) ;
V_126 += V_163 ;
F_112 ( V_71 , V_157 , V_126 ) ;
}
} else {
struct V_156 * V_157 ;
while ( V_29 == - V_25 ) {
V_157 = F_83 ( V_71 , V_69 -> V_89 [ 0 ] ,
struct V_156 ) ;
if ( F_108 ( V_71 , V_157 , V_152 ,
V_140 , V_33 ) )
break;
F_48 ( V_69 ) ;
V_21 . V_33 ++ ;
V_29 = F_111 ( V_117 , V_35 , V_69 , & V_21 ,
V_61 ) ;
if ( V_29 && V_29 != - V_25 )
goto V_162;
V_71 = V_69 -> V_88 [ 0 ] ;
}
V_157 = F_83 ( V_71 , V_69 -> V_89 [ 0 ] ,
struct V_156 ) ;
if ( V_29 == 0 ) {
F_114 ( V_71 , V_157 ,
V_152 ) ;
F_115 ( V_71 , V_157 , V_140 ) ;
F_116 ( V_71 , V_157 , V_33 ) ;
F_117 ( V_71 , V_157 , V_163 ) ;
} else {
V_126 = F_118 ( V_71 , V_157 ) ;
V_126 += V_163 ;
F_117 ( V_71 , V_157 , V_126 ) ;
}
}
F_100 ( V_71 ) ;
V_29 = 0 ;
V_162:
F_48 ( V_69 ) ;
return V_29 ;
}
static T_1 int F_119 ( struct V_116 * V_117 ,
struct V_34 * V_35 ,
struct V_68 * V_69 ,
int V_165 , int * V_166 )
{
struct V_72 V_21 ;
struct V_156 * V_167 = NULL ;
struct V_164 * V_168 = NULL ;
struct V_70 * V_71 ;
T_3 V_126 = 0 ;
int V_29 = 0 ;
V_71 = V_69 -> V_88 [ 0 ] ;
F_44 ( V_71 , & V_21 , V_69 -> V_89 [ 0 ] ) ;
if ( V_21 . type == V_161 ) {
V_167 = F_83 ( V_71 , V_69 -> V_89 [ 0 ] ,
struct V_156 ) ;
V_126 = F_118 ( V_71 , V_167 ) ;
} else if ( V_21 . type == V_160 ) {
V_168 = F_83 ( V_71 , V_69 -> V_89 [ 0 ] ,
struct V_164 ) ;
V_126 = F_113 ( V_71 , V_168 ) ;
#ifdef F_86
} else if ( V_21 . type == V_148 ) {
struct V_142 * V_143 ;
V_143 = F_83 ( V_71 , V_69 -> V_89 [ 0 ] ,
struct V_142 ) ;
V_126 = F_120 ( V_71 , V_143 ) ;
#endif
} else {
F_88 () ;
}
F_32 ( V_126 < V_165 ) ;
V_126 -= V_165 ;
if ( V_126 == 0 ) {
V_29 = F_121 ( V_117 , V_35 , V_69 ) ;
* V_166 = 1 ;
} else {
if ( V_21 . type == V_161 )
F_117 ( V_71 , V_167 , V_126 ) ;
else if ( V_21 . type == V_160 )
F_112 ( V_71 , V_168 , V_126 ) ;
#ifdef F_86
else {
struct V_142 * V_143 ;
V_143 = F_83 ( V_71 , V_69 -> V_89 [ 0 ] ,
struct V_142 ) ;
F_122 ( V_71 , V_143 , V_126 ) ;
}
#endif
F_100 ( V_71 ) ;
}
return V_29 ;
}
static T_1 T_3 F_123 ( struct V_68 * V_69 ,
struct V_169 * V_170 )
{
struct V_72 V_21 ;
struct V_70 * V_71 ;
struct V_156 * V_167 ;
struct V_164 * V_168 ;
T_3 V_126 = 0 ;
V_71 = V_69 -> V_88 [ 0 ] ;
F_44 ( V_71 , & V_21 , V_69 -> V_89 [ 0 ] ) ;
if ( V_170 ) {
if ( F_124 ( V_71 , V_170 ) ==
V_161 ) {
V_167 = (struct V_156 * ) ( & V_170 -> V_33 ) ;
V_126 = F_118 ( V_71 , V_167 ) ;
} else {
V_168 = (struct V_164 * ) ( V_170 + 1 ) ;
V_126 = F_113 ( V_71 , V_168 ) ;
}
} else if ( V_21 . type == V_161 ) {
V_167 = F_83 ( V_71 , V_69 -> V_89 [ 0 ] ,
struct V_156 ) ;
V_126 = F_118 ( V_71 , V_167 ) ;
} else if ( V_21 . type == V_160 ) {
V_168 = F_83 ( V_71 , V_69 -> V_89 [ 0 ] ,
struct V_164 ) ;
V_126 = F_113 ( V_71 , V_168 ) ;
#ifdef F_86
} else if ( V_21 . type == V_148 ) {
struct V_142 * V_143 ;
V_143 = F_83 ( V_71 , V_69 -> V_89 [ 0 ] ,
struct V_142 ) ;
V_126 = F_120 ( V_71 , V_143 ) ;
#endif
} else {
F_8 ( 1 ) ;
}
return V_126 ;
}
static T_1 int F_125 ( struct V_116 * V_117 ,
struct V_34 * V_35 ,
struct V_68 * V_69 ,
T_2 V_27 , T_2 V_17 ,
T_2 V_152 )
{
struct V_72 V_21 ;
int V_29 ;
V_21 . V_22 = V_27 ;
if ( V_17 ) {
V_21 . type = V_171 ;
V_21 . V_33 = V_17 ;
} else {
V_21 . type = V_172 ;
V_21 . V_33 = V_152 ;
}
V_29 = F_41 ( V_117 , V_35 , & V_21 , V_69 , - 1 , 1 ) ;
if ( V_29 > 0 )
V_29 = - V_159 ;
#ifdef F_86
if ( V_29 == - V_159 && V_17 ) {
F_48 ( V_69 ) ;
V_21 . type = V_148 ;
V_29 = F_41 ( V_117 , V_35 , & V_21 , V_69 , - 1 , 1 ) ;
if ( V_29 > 0 )
V_29 = - V_159 ;
}
#endif
return V_29 ;
}
static T_1 int F_126 ( struct V_116 * V_117 ,
struct V_34 * V_35 ,
struct V_68 * V_69 ,
T_2 V_27 , T_2 V_17 ,
T_2 V_152 )
{
struct V_72 V_21 ;
int V_29 ;
V_21 . V_22 = V_27 ;
if ( V_17 ) {
V_21 . type = V_171 ;
V_21 . V_33 = V_17 ;
} else {
V_21 . type = V_172 ;
V_21 . V_33 = V_152 ;
}
V_29 = F_111 ( V_117 , V_35 , V_69 , & V_21 , 0 ) ;
F_48 ( V_69 ) ;
return V_29 ;
}
static inline int F_127 ( T_2 V_17 , T_2 V_140 )
{
int type ;
if ( V_140 < V_149 ) {
if ( V_17 > 0 )
type = V_171 ;
else
type = V_172 ;
} else {
if ( V_17 > 0 )
type = V_160 ;
else
type = V_161 ;
}
return type ;
}
static int F_45 ( struct V_68 * V_69 , int V_173 ,
struct V_72 * V_21 )
{
for (; V_173 < V_174 ; V_173 ++ ) {
if ( ! V_69 -> V_88 [ V_173 ] )
break;
if ( V_69 -> V_89 [ V_173 ] + 1 >=
F_42 ( V_69 -> V_88 [ V_173 ] ) )
continue;
if ( V_173 == 0 )
F_44 ( V_69 -> V_88 [ V_173 ] , V_21 ,
V_69 -> V_89 [ V_173 ] + 1 ) ;
else
F_128 ( V_69 -> V_88 [ V_173 ] , V_21 ,
V_69 -> V_89 [ V_173 ] + 1 ) ;
return 0 ;
}
return 1 ;
}
static T_5
int F_129 ( struct V_116 * V_117 ,
struct V_34 * V_35 ,
struct V_68 * V_69 ,
struct V_169 * * V_175 ,
T_2 V_27 , T_2 V_36 ,
T_2 V_17 , T_2 V_152 ,
T_2 V_140 , T_2 V_33 , int V_176 )
{
struct V_72 V_21 ;
struct V_70 * V_71 ;
struct V_123 * V_124 ;
struct V_169 * V_170 ;
T_2 V_7 ;
T_2 V_125 ;
unsigned long V_177 ;
unsigned long V_31 ;
int V_141 ;
int type ;
int V_178 ;
int V_29 ;
int V_87 = 0 ;
bool V_179 = F_81 ( V_35 -> V_37 ,
V_128 ) ;
V_21 . V_22 = V_27 ;
V_21 . type = V_82 ;
V_21 . V_33 = V_36 ;
V_178 = F_127 ( V_17 , V_140 ) ;
if ( V_176 ) {
V_141 = F_130 ( V_178 ) ;
V_69 -> V_180 = 1 ;
} else
V_141 = - 1 ;
if ( V_179 && V_140 < V_149 ) {
V_21 . type = V_91 ;
V_21 . V_33 = V_140 ;
}
V_83:
V_29 = F_41 ( V_117 , V_35 , & V_21 , V_69 , V_141 , 1 ) ;
if ( V_29 < 0 ) {
V_87 = V_29 ;
goto V_78;
}
if ( V_29 > 0 && V_179 ) {
V_179 = false ;
if ( V_69 -> V_89 [ 0 ] ) {
V_69 -> V_89 [ 0 ] -- ;
F_44 ( V_69 -> V_88 [ 0 ] , & V_21 ,
V_69 -> V_89 [ 0 ] ) ;
if ( V_21 . V_22 == V_27 &&
V_21 . type == V_82 &&
V_21 . V_33 == V_36 )
V_29 = 0 ;
}
if ( V_29 ) {
V_21 . V_22 = V_27 ;
V_21 . type = V_82 ;
V_21 . V_33 = V_36 ;
F_48 ( V_69 ) ;
goto V_83;
}
}
if ( V_29 && ! V_176 ) {
V_87 = - V_159 ;
goto V_78;
} else if ( F_8 ( V_29 ) ) {
V_87 = - V_181 ;
goto V_78;
}
V_71 = V_69 -> V_88 [ 0 ] ;
V_125 = F_82 ( V_71 , V_69 -> V_89 [ 0 ] ) ;
#ifdef F_86
if ( V_125 < sizeof( * V_124 ) ) {
if ( ! V_176 ) {
V_87 = - V_159 ;
goto V_78;
}
V_29 = F_92 ( V_117 , V_35 , V_69 , V_140 ,
V_141 ) ;
if ( V_29 < 0 ) {
V_87 = V_29 ;
goto V_78;
}
V_71 = V_69 -> V_88 [ 0 ] ;
V_125 = F_82 ( V_71 , V_69 -> V_89 [ 0 ] ) ;
}
#endif
F_32 ( V_125 < sizeof( * V_124 ) ) ;
V_124 = F_83 ( V_71 , V_69 -> V_89 [ 0 ] , struct V_123 ) ;
V_7 = F_85 ( V_71 , V_124 ) ;
V_177 = ( unsigned long ) ( V_124 + 1 ) ;
V_31 = ( unsigned long ) V_124 + V_125 ;
if ( V_7 & V_150 && ! V_179 ) {
V_177 += sizeof( struct V_144 ) ;
F_32 ( V_177 > V_31 ) ;
}
V_87 = - V_159 ;
while ( 1 ) {
if ( V_177 >= V_31 ) {
F_8 ( V_177 > V_31 ) ;
break;
}
V_170 = (struct V_169 * ) V_177 ;
type = F_124 ( V_71 , V_170 ) ;
if ( V_178 < type )
break;
if ( V_178 > type ) {
V_177 += F_130 ( type ) ;
continue;
}
if ( type == V_161 ) {
struct V_156 * V_182 ;
V_182 = (struct V_156 * ) ( & V_170 -> V_33 ) ;
if ( F_108 ( V_71 , V_182 , V_152 ,
V_140 , V_33 ) ) {
V_87 = 0 ;
break;
}
if ( F_104 ( V_71 , V_182 ) <
F_101 ( V_152 , V_140 , V_33 ) )
break;
} else {
T_2 V_183 ;
V_183 = F_131 ( V_71 , V_170 ) ;
if ( V_17 > 0 ) {
if ( V_17 == V_183 ) {
V_87 = 0 ;
break;
}
if ( V_183 < V_17 )
break;
} else {
if ( V_152 == V_183 ) {
V_87 = 0 ;
break;
}
if ( V_183 < V_152 )
break;
}
}
V_177 += F_130 ( type ) ;
}
if ( V_87 == - V_159 && V_176 ) {
if ( V_125 + V_141 >=
F_132 ( V_35 ) ) {
V_87 = - V_184 ;
goto V_78;
}
if ( F_45 ( V_69 , 0 , & V_21 ) == 0 &&
V_21 . V_22 == V_27 &&
V_21 . type < V_185 ) {
V_87 = - V_184 ;
goto V_78;
}
}
* V_175 = (struct V_169 * ) V_177 ;
V_78:
if ( V_176 ) {
V_69 -> V_180 = 0 ;
F_133 ( V_69 , 1 ) ;
}
return V_87 ;
}
static T_5
void F_134 ( struct V_34 * V_35 ,
struct V_68 * V_69 ,
struct V_169 * V_170 ,
T_2 V_17 , T_2 V_152 ,
T_2 V_140 , T_2 V_33 , int V_163 ,
struct V_186 * V_136 )
{
struct V_70 * V_71 ;
struct V_123 * V_124 ;
unsigned long V_177 ;
unsigned long V_31 ;
unsigned long V_187 ;
T_2 V_119 ;
int V_61 ;
int type ;
V_71 = V_69 -> V_88 [ 0 ] ;
V_124 = F_83 ( V_71 , V_69 -> V_89 [ 0 ] , struct V_123 ) ;
V_187 = ( unsigned long ) V_170 - ( unsigned long ) V_124 ;
type = F_127 ( V_17 , V_140 ) ;
V_61 = F_130 ( type ) ;
F_94 ( V_35 , V_69 , V_61 ) ;
V_124 = F_83 ( V_71 , V_69 -> V_89 [ 0 ] , struct V_123 ) ;
V_119 = F_84 ( V_71 , V_124 ) ;
V_119 += V_163 ;
F_95 ( V_71 , V_124 , V_119 ) ;
if ( V_136 )
F_135 ( V_136 , V_71 , V_124 ) ;
V_177 = ( unsigned long ) V_124 + V_187 ;
V_31 = ( unsigned long ) V_124 + F_82 ( V_71 , V_69 -> V_89 [ 0 ] ) ;
if ( V_177 < V_31 - V_61 )
F_136 ( V_71 , V_177 + V_61 , V_177 ,
V_31 - V_61 - V_177 ) ;
V_170 = (struct V_169 * ) V_177 ;
F_137 ( V_71 , V_170 , type ) ;
if ( type == V_161 ) {
struct V_156 * V_182 ;
V_182 = (struct V_156 * ) ( & V_170 -> V_33 ) ;
F_114 ( V_71 , V_182 , V_152 ) ;
F_115 ( V_71 , V_182 , V_140 ) ;
F_116 ( V_71 , V_182 , V_33 ) ;
F_117 ( V_71 , V_182 , V_163 ) ;
} else if ( type == V_160 ) {
struct V_164 * V_188 ;
V_188 = (struct V_164 * ) ( V_170 + 1 ) ;
F_112 ( V_71 , V_188 , V_163 ) ;
F_138 ( V_71 , V_170 , V_17 ) ;
} else if ( type == V_171 ) {
F_138 ( V_71 , V_170 , V_17 ) ;
} else {
F_138 ( V_71 , V_170 , V_152 ) ;
}
F_100 ( V_71 ) ;
}
static int F_139 ( struct V_116 * V_117 ,
struct V_34 * V_35 ,
struct V_68 * V_69 ,
struct V_169 * * V_175 ,
T_2 V_27 , T_2 V_36 , T_2 V_17 ,
T_2 V_152 , T_2 V_140 , T_2 V_33 )
{
int V_29 ;
V_29 = F_129 ( V_117 , V_35 , V_69 , V_175 ,
V_27 , V_36 , V_17 ,
V_152 , V_140 , V_33 , 0 ) ;
if ( V_29 != - V_159 )
return V_29 ;
F_48 ( V_69 ) ;
* V_175 = NULL ;
if ( V_140 < V_149 ) {
V_29 = F_125 ( V_117 , V_35 , V_69 , V_27 , V_17 ,
V_152 ) ;
} else {
V_29 = F_109 ( V_117 , V_35 , V_69 , V_27 , V_17 ,
V_152 , V_140 , V_33 ) ;
}
return V_29 ;
}
static T_5
void F_140 ( struct V_34 * V_35 ,
struct V_68 * V_69 ,
struct V_169 * V_170 ,
int V_189 ,
struct V_186 * V_136 ,
int * V_166 )
{
struct V_70 * V_71 ;
struct V_123 * V_124 ;
struct V_156 * V_182 = NULL ;
struct V_164 * V_188 = NULL ;
unsigned long V_177 ;
unsigned long V_31 ;
T_3 V_125 ;
int V_61 ;
int type ;
T_2 V_119 ;
V_71 = V_69 -> V_88 [ 0 ] ;
V_124 = F_83 ( V_71 , V_69 -> V_89 [ 0 ] , struct V_123 ) ;
V_119 = F_84 ( V_71 , V_124 ) ;
F_8 ( V_189 < 0 && V_119 + V_189 <= 0 ) ;
V_119 += V_189 ;
F_95 ( V_71 , V_124 , V_119 ) ;
if ( V_136 )
F_135 ( V_136 , V_71 , V_124 ) ;
type = F_124 ( V_71 , V_170 ) ;
if ( type == V_161 ) {
V_182 = (struct V_156 * ) ( & V_170 -> V_33 ) ;
V_119 = F_118 ( V_71 , V_182 ) ;
} else if ( type == V_160 ) {
V_188 = (struct V_164 * ) ( V_170 + 1 ) ;
V_119 = F_113 ( V_71 , V_188 ) ;
} else {
V_119 = 1 ;
F_32 ( V_189 != - 1 ) ;
}
F_32 ( V_189 < 0 && V_119 < - V_189 ) ;
V_119 += V_189 ;
if ( V_119 > 0 ) {
if ( type == V_161 )
F_117 ( V_71 , V_182 , V_119 ) ;
else
F_112 ( V_71 , V_188 , V_119 ) ;
} else {
* V_166 = 1 ;
V_61 = F_130 ( type ) ;
V_125 = F_82 ( V_71 , V_69 -> V_89 [ 0 ] ) ;
V_177 = ( unsigned long ) V_170 ;
V_31 = ( unsigned long ) V_124 + V_125 ;
if ( V_177 + V_61 < V_31 )
F_136 ( V_71 , V_177 , V_177 + V_61 ,
V_31 - V_177 - V_61 ) ;
V_125 -= V_61 ;
F_141 ( V_35 , V_69 , V_125 , 1 ) ;
}
F_100 ( V_71 ) ;
}
static T_5
int F_142 ( struct V_116 * V_117 ,
struct V_34 * V_35 ,
struct V_68 * V_69 ,
T_2 V_27 , T_2 V_36 , T_2 V_17 ,
T_2 V_152 , T_2 V_140 ,
T_2 V_33 , int V_163 ,
struct V_186 * V_136 )
{
struct V_169 * V_170 ;
int V_29 ;
V_29 = F_129 ( V_117 , V_35 , V_69 , & V_170 ,
V_27 , V_36 , V_17 ,
V_152 , V_140 , V_33 , 1 ) ;
if ( V_29 == 0 ) {
F_32 ( V_140 < V_149 ) ;
F_140 ( V_35 , V_69 , V_170 ,
V_163 , V_136 , NULL ) ;
} else if ( V_29 == - V_159 ) {
F_134 ( V_35 , V_69 , V_170 , V_17 ,
V_152 , V_140 , V_33 ,
V_163 , V_136 ) ;
V_29 = 0 ;
}
return V_29 ;
}
static int F_143 ( struct V_116 * V_117 ,
struct V_34 * V_35 ,
struct V_68 * V_69 ,
T_2 V_27 , T_2 V_17 , T_2 V_152 ,
T_2 V_140 , T_2 V_33 , int V_163 )
{
int V_29 ;
if ( V_140 < V_149 ) {
F_32 ( V_163 != 1 ) ;
V_29 = F_126 ( V_117 , V_35 , V_69 , V_27 ,
V_17 , V_152 ) ;
} else {
V_29 = F_110 ( V_117 , V_35 , V_69 , V_27 ,
V_17 , V_152 ,
V_140 , V_33 , V_163 ) ;
}
return V_29 ;
}
static int F_144 ( struct V_116 * V_117 ,
struct V_34 * V_35 ,
struct V_68 * V_69 ,
struct V_169 * V_170 ,
int V_165 , int V_190 , int * V_166 )
{
int V_29 = 0 ;
F_32 ( ! V_190 && V_165 != 1 ) ;
if ( V_170 ) {
F_140 ( V_35 , V_69 , V_170 ,
- V_165 , NULL , V_166 ) ;
} else if ( V_190 ) {
V_29 = F_119 ( V_117 , V_35 , V_69 , V_165 ,
V_166 ) ;
} else {
* V_166 = 1 ;
V_29 = F_121 ( V_117 , V_35 , V_69 ) ;
}
return V_29 ;
}
static int F_145 ( struct V_191 * V_192 , T_2 V_32 , T_2 V_49 ,
T_2 * V_193 )
{
int V_194 , V_29 = 0 ;
T_2 V_195 , V_31 ;
T_2 V_196 = F_146 ( V_32 , 1 << 9 ) ;
if ( F_8 ( V_32 != V_196 ) ) {
V_49 -= V_196 - V_32 ;
V_49 = F_147 ( V_49 , 1 << 9 ) ;
V_32 = V_196 ;
}
* V_193 = 0 ;
if ( ! V_49 )
return 0 ;
V_31 = V_32 + V_49 ;
V_195 = V_49 ;
for ( V_194 = 0 ; V_194 < V_47 ; V_194 ++ ) {
T_2 V_197 = F_22 ( V_194 ) ;
T_2 V_198 = V_197 + V_199 ;
T_2 V_61 = V_197 - V_32 ;
if ( ! F_148 ( V_197 , V_32 , V_195 ) &&
! F_148 ( V_198 , V_32 , V_195 ) &&
! F_148 ( V_32 , V_197 , V_199 ) )
continue;
if ( V_197 <= V_32 ) {
V_32 += V_198 - V_32 ;
if ( V_32 > V_31 ) {
V_195 = 0 ;
break;
}
V_195 = V_31 - V_32 ;
continue;
}
if ( V_61 ) {
V_29 = F_149 ( V_192 , V_32 >> 9 , V_61 >> 9 ,
V_40 , 0 ) ;
if ( ! V_29 )
* V_193 += V_61 ;
else if ( V_29 != - V_200 )
return V_29 ;
}
V_32 = V_198 ;
if ( V_32 > V_31 ) {
V_195 = 0 ;
break;
}
V_195 = V_31 - V_32 ;
}
if ( V_195 ) {
V_29 = F_149 ( V_192 , V_32 >> 9 , V_195 >> 9 ,
V_40 , 0 ) ;
if ( ! V_29 )
* V_193 += V_195 ;
}
return V_29 ;
}
int F_150 ( struct V_34 * V_35 , T_2 V_27 ,
T_2 V_36 , T_2 * V_201 )
{
int V_29 ;
T_2 V_193 = 0 ;
struct V_202 * V_203 = NULL ;
V_29 = F_151 ( V_35 -> V_37 , V_204 ,
V_27 , & V_36 , & V_203 , 0 ) ;
if ( ! V_29 ) {
struct V_205 * V_206 = V_203 -> V_207 ;
int V_43 ;
for ( V_43 = 0 ; V_43 < V_203 -> V_208 ; V_43 ++ , V_206 ++ ) {
T_2 V_209 ;
if ( ! V_206 -> V_210 -> V_211 )
continue;
V_29 = F_145 ( V_206 -> V_210 -> V_192 ,
V_206 -> V_212 ,
V_206 -> V_213 ,
& V_209 ) ;
if ( ! V_29 )
V_193 += V_209 ;
else if ( V_29 != - V_200 )
break;
V_29 = 0 ;
}
F_152 ( V_203 ) ;
}
if ( V_201 )
* V_201 = V_193 ;
if ( V_29 == - V_200 )
V_29 = 0 ;
return V_29 ;
}
int F_153 ( struct V_116 * V_117 ,
struct V_34 * V_35 ,
T_2 V_27 , T_2 V_36 , T_2 V_17 ,
T_2 V_152 , T_2 V_140 , T_2 V_33 )
{
int V_29 ;
struct V_12 * V_37 = V_35 -> V_37 ;
F_32 ( V_140 < V_149 &&
V_152 == V_214 ) ;
if ( V_140 < V_149 ) {
V_29 = F_154 ( V_37 , V_117 , V_27 ,
V_36 ,
V_17 , V_152 , ( int ) V_140 ,
V_215 , NULL ) ;
} else {
V_29 = F_155 ( V_37 , V_117 , V_27 ,
V_36 , V_17 , V_152 ,
V_140 , V_33 , 0 ,
V_215 , NULL ) ;
}
return V_29 ;
}
static int F_156 ( struct V_116 * V_117 ,
struct V_34 * V_35 ,
struct V_216 * V_135 ,
T_2 V_17 , T_2 V_152 ,
T_2 V_140 , T_2 V_33 , int V_163 ,
struct V_186 * V_136 )
{
struct V_12 * V_37 = V_35 -> V_37 ;
struct V_68 * V_69 ;
struct V_70 * V_71 ;
struct V_123 * V_96 ;
struct V_72 V_21 ;
T_2 V_27 = V_135 -> V_27 ;
T_2 V_36 = V_135 -> V_36 ;
T_2 V_119 ;
int V_29 ;
V_69 = F_35 () ;
if ( ! V_69 )
return - V_76 ;
V_69 -> V_81 = 1 ;
V_69 -> V_217 = 1 ;
V_29 = F_142 ( V_117 , V_37 -> V_67 , V_69 ,
V_27 , V_36 , V_17 ,
V_152 , V_140 , V_33 ,
V_163 , V_136 ) ;
if ( ( V_29 < 0 && V_29 != - V_184 ) || ! V_29 )
goto V_78;
V_71 = V_69 -> V_88 [ 0 ] ;
F_44 ( V_71 , & V_21 , V_69 -> V_89 [ 0 ] ) ;
V_96 = F_83 ( V_71 , V_69 -> V_89 [ 0 ] , struct V_123 ) ;
V_119 = F_84 ( V_71 , V_96 ) ;
F_95 ( V_71 , V_96 , V_119 + V_163 ) ;
if ( V_136 )
F_135 ( V_136 , V_71 , V_96 ) ;
F_100 ( V_71 ) ;
F_48 ( V_69 ) ;
V_69 -> V_81 = 1 ;
V_69 -> V_217 = 1 ;
V_29 = F_143 ( V_117 , V_35 -> V_37 -> V_67 ,
V_69 , V_27 , V_17 , V_152 ,
V_140 , V_33 , V_163 ) ;
if ( V_29 )
F_157 ( V_117 , V_35 , V_29 ) ;
V_78:
F_55 ( V_69 ) ;
return V_29 ;
}
static int F_158 ( struct V_116 * V_117 ,
struct V_34 * V_35 ,
struct V_216 * V_135 ,
struct V_186 * V_136 ,
int V_218 )
{
int V_29 = 0 ;
struct V_219 * V_157 ;
struct V_72 V_220 ;
T_2 V_17 = 0 ;
T_2 V_221 = 0 ;
T_2 V_7 = 0 ;
V_220 . V_22 = V_135 -> V_27 ;
V_220 . V_33 = V_135 -> V_36 ;
V_220 . type = V_82 ;
V_157 = F_159 ( V_135 ) ;
F_160 ( V_135 , V_157 , V_135 -> V_222 ) ;
if ( V_135 -> type == V_160 )
V_17 = V_157 -> V_17 ;
V_221 = V_157 -> V_35 ;
if ( V_135 -> V_222 == V_215 && V_218 ) {
if ( V_136 )
V_7 |= V_136 -> V_138 ;
V_29 = F_161 ( V_117 , V_35 ,
V_17 , V_221 , V_7 ,
V_157 -> V_22 , V_157 -> V_33 ,
& V_220 , V_135 -> V_139 ) ;
} else if ( V_135 -> V_222 == V_215 ) {
V_29 = F_156 ( V_117 , V_35 , V_135 , V_17 ,
V_221 , V_157 -> V_22 ,
V_157 -> V_33 , V_135 -> V_139 ,
V_136 ) ;
} else if ( V_135 -> V_222 == V_223 ) {
V_29 = F_162 ( V_117 , V_35 , V_135 , V_17 ,
V_221 , V_157 -> V_22 ,
V_157 -> V_33 , V_135 -> V_139 ,
V_136 ) ;
} else {
F_88 () ;
}
return V_29 ;
}
static void F_135 ( struct V_186 * V_136 ,
struct V_70 * V_71 ,
struct V_123 * V_124 )
{
T_2 V_7 = F_85 ( V_71 , V_124 ) ;
if ( V_136 -> V_137 ) {
V_7 |= V_136 -> V_138 ;
F_97 ( V_71 , V_124 , V_7 ) ;
}
if ( V_136 -> V_224 ) {
struct V_144 * V_145 ;
F_32 ( ! ( V_7 & V_150 ) ) ;
V_145 = (struct V_144 * ) ( V_124 + 1 ) ;
F_163 ( V_71 , V_145 , & V_136 -> V_21 ) ;
}
}
static int F_164 ( struct V_116 * V_117 ,
struct V_34 * V_35 ,
struct V_216 * V_135 ,
struct V_186 * V_136 )
{
struct V_72 V_21 ;
struct V_68 * V_69 ;
struct V_123 * V_124 ;
struct V_70 * V_71 ;
T_3 V_125 ;
int V_29 ;
int V_87 = 0 ;
int V_118 = ! V_136 -> V_190 ;
if ( V_117 -> V_225 )
return 0 ;
if ( V_118 && ! F_81 ( V_35 -> V_37 , V_128 ) )
V_118 = 0 ;
V_69 = F_35 () ;
if ( ! V_69 )
return - V_76 ;
V_21 . V_22 = V_135 -> V_27 ;
if ( V_118 ) {
V_21 . type = V_91 ;
V_21 . V_33 = V_136 -> V_173 ;
} else {
V_21 . type = V_82 ;
V_21 . V_33 = V_135 -> V_36 ;
}
V_83:
V_69 -> V_81 = 1 ;
V_69 -> V_217 = 1 ;
V_29 = F_41 ( V_117 , V_35 -> V_37 -> V_67 , & V_21 ,
V_69 , 0 , 1 ) ;
if ( V_29 < 0 ) {
V_87 = V_29 ;
goto V_78;
}
if ( V_29 > 0 ) {
if ( V_118 ) {
if ( V_69 -> V_89 [ 0 ] > 0 ) {
V_69 -> V_89 [ 0 ] -- ;
F_44 ( V_69 -> V_88 [ 0 ] , & V_21 ,
V_69 -> V_89 [ 0 ] ) ;
if ( V_21 . V_22 == V_135 -> V_27 &&
V_21 . type == V_82 &&
V_21 . V_33 == V_135 -> V_36 )
V_29 = 0 ;
}
if ( V_29 > 0 ) {
F_48 ( V_69 ) ;
V_118 = 0 ;
V_21 . V_22 = V_135 -> V_27 ;
V_21 . V_33 = V_135 -> V_36 ;
V_21 . type = V_82 ;
goto V_83;
}
} else {
V_87 = - V_181 ;
goto V_78;
}
}
V_71 = V_69 -> V_88 [ 0 ] ;
V_125 = F_82 ( V_71 , V_69 -> V_89 [ 0 ] ) ;
#ifdef F_86
if ( V_125 < sizeof( * V_124 ) ) {
V_29 = F_92 ( V_117 , V_35 -> V_37 -> V_67 ,
V_69 , ( T_2 ) - 1 , 0 ) ;
if ( V_29 < 0 ) {
V_87 = V_29 ;
goto V_78;
}
V_71 = V_69 -> V_88 [ 0 ] ;
V_125 = F_82 ( V_71 , V_69 -> V_89 [ 0 ] ) ;
}
#endif
F_32 ( V_125 < sizeof( * V_124 ) ) ;
V_124 = F_83 ( V_71 , V_69 -> V_89 [ 0 ] , struct V_123 ) ;
F_135 ( V_136 , V_71 , V_124 ) ;
F_100 ( V_71 ) ;
V_78:
F_55 ( V_69 ) ;
return V_87 ;
}
static int F_165 ( struct V_116 * V_117 ,
struct V_34 * V_35 ,
struct V_216 * V_135 ,
struct V_186 * V_136 ,
int V_218 )
{
int V_29 = 0 ;
struct V_226 * V_157 ;
struct V_72 V_220 ;
T_2 V_17 = 0 ;
T_2 V_221 = 0 ;
bool V_179 = F_81 ( V_35 -> V_37 ,
V_128 ) ;
V_157 = F_166 ( V_135 ) ;
F_167 ( V_135 , V_157 , V_135 -> V_222 ) ;
if ( V_135 -> type == V_171 )
V_17 = V_157 -> V_17 ;
V_221 = V_157 -> V_35 ;
V_220 . V_22 = V_135 -> V_27 ;
if ( V_179 ) {
V_220 . V_33 = V_157 -> V_173 ;
V_220 . type = V_91 ;
} else {
V_220 . V_33 = V_135 -> V_36 ;
V_220 . type = V_82 ;
}
F_32 ( V_135 -> V_139 != 1 ) ;
if ( V_135 -> V_222 == V_215 && V_218 ) {
F_32 ( ! V_136 || ! V_136 -> V_137 ) ;
V_29 = F_168 ( V_117 , V_35 ,
V_17 , V_221 ,
V_136 -> V_138 ,
& V_136 -> V_21 ,
V_157 -> V_173 , & V_220 ) ;
} else if ( V_135 -> V_222 == V_215 ) {
V_29 = F_156 ( V_117 , V_35 , V_135 ,
V_17 , V_221 ,
V_157 -> V_173 , 0 , 1 ,
V_136 ) ;
} else if ( V_135 -> V_222 == V_223 ) {
V_29 = F_162 ( V_117 , V_35 , V_135 ,
V_17 , V_221 ,
V_157 -> V_173 , 0 , 1 , V_136 ) ;
} else {
F_88 () ;
}
return V_29 ;
}
static int F_169 ( struct V_116 * V_117 ,
struct V_34 * V_35 ,
struct V_216 * V_135 ,
struct V_186 * V_136 ,
int V_218 )
{
int V_29 = 0 ;
if ( V_117 -> V_225 ) {
if ( V_218 )
F_170 ( V_35 , V_135 -> V_27 ,
V_135 -> V_36 , 1 ) ;
return 0 ;
}
if ( F_171 ( V_135 ) ) {
struct V_120 * V_112 ;
F_32 ( V_136 ) ;
V_112 = F_172 ( V_135 ) ;
F_173 ( V_135 , V_112 , V_135 -> V_222 ) ;
if ( V_218 ) {
F_170 ( V_35 , V_135 -> V_27 ,
V_135 -> V_36 , 1 ) ;
if ( V_112 -> V_190 ) {
V_29 = F_174 ( V_117 , V_35 ,
V_135 -> V_27 ,
V_135 -> V_36 ) ;
}
}
F_175 ( V_35 -> V_37 ,
V_112 -> V_227 ,
V_112 -> V_228 ) ;
return V_29 ;
}
if ( V_135 -> type == V_172 ||
V_135 -> type == V_171 )
V_29 = F_165 ( V_117 , V_35 , V_135 , V_136 ,
V_218 ) ;
else if ( V_135 -> type == V_161 ||
V_135 -> type == V_160 )
V_29 = F_158 ( V_117 , V_35 , V_135 , V_136 ,
V_218 ) ;
else
F_88 () ;
return V_29 ;
}
static inline struct V_216 *
F_176 ( struct V_120 * V_112 )
{
struct V_216 * V_157 ;
if ( F_177 ( & V_112 -> V_229 ) )
return NULL ;
F_178 (ref, &head->ref_list, list) {
if ( V_157 -> V_222 == V_215 )
return V_157 ;
}
return F_179 ( V_112 -> V_229 . V_86 , struct V_216 ,
V_98 ) ;
}
static T_1 int F_180 ( struct V_116 * V_117 ,
struct V_34 * V_35 ,
unsigned long V_44 )
{
struct V_121 * V_122 ;
struct V_216 * V_157 ;
struct V_120 * V_230 = NULL ;
struct V_186 * V_136 ;
struct V_12 * V_37 = V_35 -> V_37 ;
T_6 V_32 = F_181 () ;
int V_29 ;
unsigned long V_8 = 0 ;
unsigned long V_231 = 0 ;
int V_232 = 0 ;
V_122 = & V_117 -> V_134 -> V_122 ;
while ( 1 ) {
if ( ! V_230 ) {
if ( V_8 >= V_44 )
break;
F_11 ( & V_122 -> V_52 ) ;
V_230 = F_182 ( V_117 ) ;
if ( ! V_230 ) {
F_13 ( & V_122 -> V_52 ) ;
break;
}
V_29 = F_183 ( V_117 , V_230 ) ;
F_13 ( & V_122 -> V_52 ) ;
if ( V_29 == - V_184 ) {
V_230 = NULL ;
V_8 ++ ;
continue;
}
}
F_11 ( & V_230 -> V_52 ) ;
F_184 ( V_117 , V_37 , V_122 ,
V_230 ) ;
V_157 = F_176 ( V_230 ) ;
if ( V_157 && V_157 -> V_233 &&
F_185 ( V_37 , V_122 , V_157 -> V_233 ) ) {
F_13 ( & V_230 -> V_52 ) ;
F_186 ( V_230 ) ;
F_11 ( & V_122 -> V_52 ) ;
V_230 -> V_234 = 0 ;
V_122 -> V_235 ++ ;
F_13 ( & V_122 -> V_52 ) ;
V_230 = NULL ;
F_51 () ;
V_8 ++ ;
continue;
}
V_232 = V_230 -> V_232 ;
V_230 -> V_232 = 0 ;
V_136 = V_230 -> V_136 ;
V_230 -> V_136 = NULL ;
if ( ! V_157 ) {
V_157 = & V_230 -> V_135 ;
if ( V_136 && V_232 ) {
F_187 ( V_136 ) ;
V_136 = NULL ;
}
if ( V_136 ) {
F_13 ( & V_230 -> V_52 ) ;
V_29 = F_164 ( V_117 , V_35 ,
V_157 , V_136 ) ;
F_187 ( V_136 ) ;
if ( V_29 ) {
if ( V_232 )
V_230 -> V_232 = 1 ;
V_230 -> V_234 = 0 ;
F_188 ( V_37 , L_1 , V_29 ) ;
F_186 ( V_230 ) ;
return V_29 ;
}
continue;
}
F_13 ( & V_230 -> V_52 ) ;
F_11 ( & V_122 -> V_52 ) ;
F_11 ( & V_230 -> V_52 ) ;
if ( ! F_177 ( & V_230 -> V_229 ) ||
V_230 -> V_136 ) {
F_13 ( & V_230 -> V_52 ) ;
F_13 ( & V_122 -> V_52 ) ;
continue;
}
V_157 -> V_236 = 0 ;
V_122 -> V_237 -- ;
F_189 ( & V_230 -> V_238 ,
& V_122 -> V_239 ) ;
F_13 ( & V_122 -> V_52 ) ;
} else {
V_231 ++ ;
V_157 -> V_236 = 0 ;
F_190 ( & V_157 -> V_98 ) ;
}
F_191 ( & V_122 -> V_240 ) ;
if ( ! F_171 ( V_157 ) ) {
switch ( V_157 -> V_222 ) {
case V_215 :
case V_241 :
V_230 -> V_135 . V_139 -= V_157 -> V_139 ;
break;
case V_223 :
V_230 -> V_135 . V_139 += V_157 -> V_139 ;
break;
default:
F_8 ( 1 ) ;
}
}
F_13 ( & V_230 -> V_52 ) ;
V_29 = F_169 ( V_117 , V_35 , V_157 , V_136 ,
V_232 ) ;
F_187 ( V_136 ) ;
if ( V_29 ) {
V_230 -> V_234 = 0 ;
F_186 ( V_230 ) ;
F_91 ( V_157 ) ;
F_188 ( V_37 , L_2 , V_29 ) ;
return V_29 ;
}
if ( F_171 ( V_157 ) ) {
if ( V_230 -> V_190 &&
V_230 -> V_242 < 0 ) {
F_11 ( & V_122 -> V_52 ) ;
V_122 -> V_243 -= V_157 -> V_36 ;
F_13 ( & V_122 -> V_52 ) ;
}
F_186 ( V_230 ) ;
V_230 = NULL ;
}
F_91 ( V_157 ) ;
V_8 ++ ;
F_51 () ;
}
if ( V_231 > 0 ) {
T_2 V_244 = F_192 ( F_193 ( F_181 () , V_32 ) ) ;
T_2 V_245 ;
F_11 ( & V_122 -> V_52 ) ;
V_245 = V_37 -> V_246 * 3 + V_244 ;
V_37 -> V_246 = V_245 >> 2 ;
F_13 ( & V_122 -> V_52 ) ;
}
return 0 ;
}
static T_2 F_194 ( struct V_247 * V_35 )
{
struct V_15 * V_30 = V_35 -> V_15 ;
struct V_216 * V_248 ;
int V_249 = 1 ;
T_2 V_250 ;
T_2 V_251 = 0 , V_74 = 0 ;
V_30 = F_195 ( V_35 ) ;
if ( V_30 ) {
V_248 = F_12 ( V_30 , struct V_216 , V_15 ) ;
V_251 = V_248 -> V_27 ;
}
V_30 = F_196 ( V_35 ) ;
if ( V_30 ) {
V_248 = F_12 ( V_30 , struct V_216 , V_15 ) ;
V_74 = V_248 -> V_27 ;
}
V_30 = V_35 -> V_15 ;
while ( V_30 ) {
V_248 = F_12 ( V_30 , struct V_216 , V_15 ) ;
F_8 ( ! V_248 -> V_236 ) ;
V_250 = V_248 -> V_27 ;
if ( V_249 )
V_30 = V_30 -> V_23 ;
else
V_30 = V_30 -> V_24 ;
V_249 = 1 - V_249 ;
}
return V_250 ;
}
static inline T_2 F_197 ( struct V_34 * V_35 , T_2 V_252 )
{
T_2 V_36 ;
V_36 = V_252 * ( sizeof( struct V_123 ) +
sizeof( struct V_169 ) ) ;
if ( ! F_81 ( V_35 -> V_37 , V_128 ) )
V_36 += V_252 * sizeof( struct V_144 ) ;
return F_198 ( V_36 , F_199 ( V_35 ) ) ;
}
T_2 F_200 ( struct V_34 * V_35 , T_2 V_253 )
{
T_2 V_254 ;
T_2 V_255 ;
T_2 V_256 ;
V_254 = F_199 ( V_35 ) - sizeof( struct V_257 ) ;
V_255 = F_201 ( V_254 ,
( T_2 ) F_202 ( V_35 -> V_37 -> V_258 ) ) ;
V_256 = F_201 ( V_253 , V_35 -> V_57 ) ;
V_256 += V_255 - 1 ;
V_256 = F_201 ( V_256 , V_255 ) ;
return V_256 ;
}
int F_203 ( struct V_116 * V_117 ,
struct V_34 * V_35 )
{
struct V_259 * V_260 ;
T_2 V_237 = V_117 -> V_134 -> V_122 . V_235 ;
T_2 V_253 = V_117 -> V_134 -> V_122 . V_243 ;
T_2 V_261 = V_117 -> V_134 -> V_261 ;
T_2 V_36 , V_262 ;
int V_29 = 0 ;
V_36 = F_204 ( V_35 , 1 ) ;
V_237 = F_197 ( V_35 , V_237 ) ;
if ( V_237 > 1 )
V_36 += ( V_237 - 1 ) * V_35 -> V_56 ;
V_36 <<= 1 ;
V_36 += F_200 ( V_35 , V_253 ) * V_35 -> V_56 ;
V_262 = F_204 ( V_35 ,
V_261 ) ;
V_260 = & V_35 -> V_37 -> V_263 ;
if ( V_260 -> V_95 -> V_115 ) {
V_262 <<= 1 ;
V_36 <<= 1 ;
}
F_11 ( & V_260 -> V_52 ) ;
if ( V_260 -> V_10 <= V_36 + V_262 )
V_29 = 1 ;
F_13 ( & V_260 -> V_52 ) ;
return V_29 ;
}
int F_205 ( struct V_116 * V_117 ,
struct V_34 * V_35 )
{
struct V_12 * V_37 = V_35 -> V_37 ;
T_2 V_240 =
F_206 ( & V_117 -> V_134 -> V_122 . V_240 ) ;
T_2 V_264 ;
T_2 V_265 ;
F_2 () ;
V_264 = V_37 -> V_246 ;
V_265 = V_240 * V_264 ;
if ( V_240 * V_264 >= V_266 )
return 1 ;
if ( V_265 >= V_266 / 2 )
return 2 ;
return F_203 ( V_117 , V_35 ) ;
}
static void F_207 ( struct V_65 * V_66 )
{
struct V_267 * V_268 ;
struct V_116 * V_117 ;
int V_29 ;
V_268 = F_34 ( V_66 , struct V_267 , V_66 ) ;
V_117 = F_208 ( V_268 -> V_35 ) ;
if ( F_209 ( V_117 ) ) {
V_268 -> error = F_210 ( V_117 ) ;
goto V_269;
}
V_117 -> V_270 = true ;
V_29 = F_211 ( V_117 , V_268 -> V_35 , V_268 -> V_8 ) ;
if ( V_29 )
V_268 -> error = V_29 ;
V_29 = F_212 ( V_117 , V_268 -> V_35 ) ;
if ( V_29 && ! V_268 -> error )
V_268 -> error = V_29 ;
V_269:
if ( V_268 -> V_270 )
F_213 ( & V_268 -> V_93 ) ;
else
F_9 ( V_268 ) ;
}
int F_214 ( struct V_34 * V_35 ,
unsigned long V_8 , int V_93 )
{
struct V_267 * V_268 ;
int V_29 ;
V_268 = F_215 ( sizeof( * V_268 ) , V_40 ) ;
if ( ! V_268 )
return - V_76 ;
V_268 -> V_35 = V_35 -> V_37 -> V_92 ;
V_268 -> V_8 = V_8 ;
V_268 -> error = 0 ;
if ( V_93 )
V_268 -> V_270 = 1 ;
else
V_268 -> V_270 = 0 ;
F_216 ( & V_268 -> V_93 ) ;
F_63 ( & V_268 -> V_66 , V_271 ,
F_207 , NULL , NULL ) ;
F_71 ( V_35 -> V_37 -> V_272 , & V_268 -> V_66 ) ;
if ( V_93 ) {
F_217 ( & V_268 -> V_93 ) ;
V_29 = V_268 -> error ;
F_9 ( V_268 ) ;
return V_29 ;
}
return 0 ;
}
int F_211 ( struct V_116 * V_117 ,
struct V_34 * V_35 , unsigned long V_8 )
{
struct V_15 * V_135 ;
struct V_121 * V_122 ;
struct V_120 * V_112 ;
int V_29 ;
int V_273 = V_8 == ( unsigned long ) - 1 ;
bool V_274 = V_117 -> V_274 ;
if ( V_117 -> V_225 )
return 0 ;
if ( V_35 == V_35 -> V_37 -> V_67 )
V_35 = V_35 -> V_37 -> V_92 ;
V_122 = & V_117 -> V_134 -> V_122 ;
if ( V_8 == 0 )
V_8 = F_206 ( & V_122 -> V_240 ) * 2 ;
V_83:
#ifdef F_218
V_122 -> V_275 = F_194 ( & V_122 -> V_35 ) ;
#endif
V_117 -> V_274 = false ;
V_29 = F_180 ( V_117 , V_35 , V_8 ) ;
if ( V_29 < 0 ) {
F_157 ( V_117 , V_35 , V_29 ) ;
return V_29 ;
}
if ( V_273 ) {
if ( ! F_177 ( & V_117 -> V_276 ) )
F_219 ( V_117 , V_35 ) ;
F_11 ( & V_122 -> V_52 ) ;
V_135 = F_195 ( & V_122 -> V_239 ) ;
if ( ! V_135 ) {
F_13 ( & V_122 -> V_52 ) ;
goto V_78;
}
V_8 = ( unsigned long ) - 1 ;
while ( V_135 ) {
V_112 = F_12 ( V_135 , struct V_120 ,
V_238 ) ;
if ( F_171 ( & V_112 -> V_135 ) ) {
struct V_216 * V_157 ;
V_157 = & V_112 -> V_135 ;
F_5 ( & V_157 -> V_119 ) ;
F_13 ( & V_122 -> V_52 ) ;
F_39 ( & V_112 -> V_84 ) ;
F_50 ( & V_112 -> V_84 ) ;
F_91 ( V_157 ) ;
F_51 () ;
goto V_83;
} else {
F_8 ( 1 ) ;
}
V_135 = F_220 ( V_135 ) ;
}
F_13 ( & V_122 -> V_52 ) ;
F_51 () ;
goto V_83;
}
V_78:
F_221 ( V_117 ) ;
V_117 -> V_274 = V_274 ;
return 0 ;
}
int F_222 ( struct V_116 * V_117 ,
struct V_34 * V_35 ,
T_2 V_27 , T_2 V_36 , T_2 V_7 ,
int V_173 , int V_190 )
{
struct V_186 * V_136 ;
int V_29 ;
V_136 = F_223 () ;
if ( ! V_136 )
return - V_76 ;
V_136 -> V_138 = V_7 ;
V_136 -> V_137 = 1 ;
V_136 -> V_224 = 0 ;
V_136 -> V_190 = V_190 ? 1 : 0 ;
V_136 -> V_173 = V_173 ;
V_29 = F_224 ( V_35 -> V_37 , V_117 , V_27 ,
V_36 , V_136 ) ;
if ( V_29 )
F_187 ( V_136 ) ;
return V_29 ;
}
static T_1 int F_225 ( struct V_116 * V_117 ,
struct V_34 * V_35 ,
struct V_68 * V_69 ,
T_2 V_22 , T_2 V_33 , T_2 V_27 )
{
struct V_120 * V_112 ;
struct V_216 * V_157 ;
struct V_219 * V_277 ;
struct V_121 * V_122 ;
int V_29 = 0 ;
V_122 = & V_117 -> V_134 -> V_122 ;
F_11 ( & V_122 -> V_52 ) ;
V_112 = F_89 ( V_117 , V_27 ) ;
if ( ! V_112 ) {
F_13 ( & V_122 -> V_52 ) ;
return 0 ;
}
if ( ! F_90 ( & V_112 -> V_84 ) ) {
F_5 ( & V_112 -> V_135 . V_119 ) ;
F_13 ( & V_122 -> V_52 ) ;
F_48 ( V_69 ) ;
F_39 ( & V_112 -> V_84 ) ;
F_50 ( & V_112 -> V_84 ) ;
F_91 ( & V_112 -> V_135 ) ;
return - V_184 ;
}
F_13 ( & V_122 -> V_52 ) ;
F_11 ( & V_112 -> V_52 ) ;
F_178 (ref, &head->ref_list, list) {
if ( V_157 -> type != V_161 ) {
V_29 = 1 ;
break;
}
V_277 = F_159 ( V_157 ) ;
if ( V_277 -> V_35 != V_35 -> V_278 . V_22 ||
V_277 -> V_22 != V_22 ||
V_277 -> V_33 != V_33 ) {
V_29 = 1 ;
break;
}
}
F_13 ( & V_112 -> V_52 ) ;
F_50 ( & V_112 -> V_84 ) ;
return V_29 ;
}
static T_1 int F_226 ( struct V_116 * V_117 ,
struct V_34 * V_35 ,
struct V_68 * V_69 ,
T_2 V_22 , T_2 V_33 , T_2 V_27 )
{
struct V_34 * V_67 = V_35 -> V_37 -> V_67 ;
struct V_70 * V_71 ;
struct V_156 * V_157 ;
struct V_169 * V_170 ;
struct V_123 * V_124 ;
struct V_72 V_21 ;
T_3 V_125 ;
int V_29 ;
V_21 . V_22 = V_27 ;
V_21 . V_33 = ( T_2 ) - 1 ;
V_21 . type = V_82 ;
V_29 = F_41 ( NULL , V_67 , & V_21 , V_69 , 0 , 0 ) ;
if ( V_29 < 0 )
goto V_78;
F_32 ( V_29 == 0 ) ;
V_29 = - V_159 ;
if ( V_69 -> V_89 [ 0 ] == 0 )
goto V_78;
V_69 -> V_89 [ 0 ] -- ;
V_71 = V_69 -> V_88 [ 0 ] ;
F_44 ( V_71 , & V_21 , V_69 -> V_89 [ 0 ] ) ;
if ( V_21 . V_22 != V_27 || V_21 . type != V_82 )
goto V_78;
V_29 = 1 ;
V_125 = F_82 ( V_71 , V_69 -> V_89 [ 0 ] ) ;
#ifdef F_86
if ( V_125 < sizeof( * V_124 ) ) {
F_8 ( V_125 != sizeof( struct V_131 ) ) ;
goto V_78;
}
#endif
V_124 = F_83 ( V_71 , V_69 -> V_89 [ 0 ] , struct V_123 ) ;
if ( V_125 != sizeof( * V_124 ) +
F_130 ( V_161 ) )
goto V_78;
if ( F_227 ( V_71 , V_124 ) <=
F_228 ( & V_35 -> V_279 ) )
goto V_78;
V_170 = (struct V_169 * ) ( V_124 + 1 ) ;
if ( F_124 ( V_71 , V_170 ) !=
V_161 )
goto V_78;
V_157 = (struct V_156 * ) ( & V_170 -> V_33 ) ;
if ( F_84 ( V_71 , V_124 ) !=
F_118 ( V_71 , V_157 ) ||
F_105 ( V_71 , V_157 ) !=
V_35 -> V_278 . V_22 ||
F_106 ( V_71 , V_157 ) != V_22 ||
F_107 ( V_71 , V_157 ) != V_33 )
goto V_78;
V_29 = 0 ;
V_78:
return V_29 ;
}
int F_229 ( struct V_116 * V_117 ,
struct V_34 * V_35 ,
T_2 V_22 , T_2 V_33 , T_2 V_27 )
{
struct V_68 * V_69 ;
int V_29 ;
int V_280 ;
V_69 = F_35 () ;
if ( ! V_69 )
return - V_159 ;
do {
V_29 = F_226 ( V_117 , V_35 , V_69 , V_22 ,
V_33 , V_27 ) ;
if ( V_29 && V_29 != - V_159 )
goto V_78;
V_280 = F_225 ( V_117 , V_35 , V_69 , V_22 ,
V_33 , V_27 ) ;
} while ( V_280 == - V_184 );
if ( V_280 && V_280 != - V_159 ) {
V_29 = V_280 ;
goto V_78;
}
if ( V_29 != - V_159 || V_280 != - V_159 )
V_29 = 0 ;
V_78:
F_55 ( V_69 ) ;
if ( V_35 -> V_278 . V_22 == V_281 )
F_8 ( V_29 > 0 ) ;
return V_29 ;
}
static int F_230 ( struct V_116 * V_117 ,
struct V_34 * V_35 ,
struct V_70 * V_282 ,
int V_283 , int V_284 )
{
T_2 V_27 ;
T_2 V_36 ;
T_2 V_17 ;
T_2 V_221 ;
T_3 V_75 ;
struct V_72 V_21 ;
struct V_285 * V_286 ;
int V_43 ;
int V_173 ;
int V_29 = 0 ;
int (* F_231)( struct V_116 * , struct V_34 * ,
T_2 , T_2 , T_2 , T_2 , T_2 , T_2 );
if ( F_232 ( V_35 ) )
return 0 ;
V_221 = F_233 ( V_282 ) ;
V_75 = F_42 ( V_282 ) ;
V_173 = F_234 ( V_282 ) ;
if ( ! F_235 ( V_287 , & V_35 -> V_288 ) && V_173 == 0 )
return 0 ;
if ( V_284 )
F_231 = F_153 ;
else
F_231 = V_289 ;
if ( V_283 )
V_17 = V_282 -> V_32 ;
else
V_17 = 0 ;
for ( V_43 = 0 ; V_43 < V_75 ; V_43 ++ ) {
if ( V_173 == 0 ) {
F_44 ( V_282 , & V_21 , V_43 ) ;
if ( V_21 . type != V_290 )
continue;
V_286 = F_83 ( V_282 , V_43 ,
struct V_285 ) ;
if ( F_236 ( V_282 , V_286 ) ==
V_291 )
continue;
V_27 = F_237 ( V_282 , V_286 ) ;
if ( V_27 == 0 )
continue;
V_36 = F_238 ( V_282 , V_286 ) ;
V_21 . V_33 -= F_239 ( V_282 , V_286 ) ;
V_29 = F_231 ( V_117 , V_35 , V_27 , V_36 ,
V_17 , V_221 , V_21 . V_22 ,
V_21 . V_33 ) ;
if ( V_29 )
goto V_162;
} else {
V_27 = F_240 ( V_282 , V_43 ) ;
V_36 = V_35 -> V_56 ;
V_29 = F_231 ( V_117 , V_35 , V_27 , V_36 ,
V_17 , V_221 , V_173 - 1 , 0 ) ;
if ( V_29 )
goto V_162;
}
}
return 0 ;
V_162:
return V_29 ;
}
int F_241 ( struct V_116 * V_117 , struct V_34 * V_35 ,
struct V_70 * V_282 , int V_283 )
{
return F_230 ( V_117 , V_35 , V_282 , V_283 , 1 ) ;
}
int F_242 ( struct V_116 * V_117 , struct V_34 * V_35 ,
struct V_70 * V_282 , int V_283 )
{
return F_230 ( V_117 , V_35 , V_282 , V_283 , 0 ) ;
}
static int F_243 ( struct V_116 * V_117 ,
struct V_34 * V_35 ,
struct V_68 * V_69 ,
struct V_1 * V_2 )
{
int V_29 ;
struct V_34 * V_67 = V_35 -> V_37 -> V_67 ;
unsigned long V_145 ;
struct V_70 * V_71 ;
V_29 = F_41 ( V_117 , V_67 , & V_2 -> V_21 , V_69 , 0 , 1 ) ;
if ( V_29 ) {
if ( V_29 > 0 )
V_29 = - V_159 ;
goto V_162;
}
V_71 = V_69 -> V_88 [ 0 ] ;
V_145 = F_244 ( V_71 , V_69 -> V_89 [ 0 ] ) ;
F_245 ( V_71 , & V_2 -> V_96 , V_145 , sizeof( V_2 -> V_96 ) ) ;
F_100 ( V_71 ) ;
V_162:
F_48 ( V_69 ) ;
return V_29 ;
}
static struct V_1 *
F_246 ( struct V_34 * V_35 ,
struct V_1 * V_2 )
{
struct V_15 * V_135 ;
F_11 ( & V_35 -> V_37 -> V_18 ) ;
if ( F_247 ( & V_2 -> V_20 ) ) {
const T_2 V_292 = V_2 -> V_21 . V_22 + V_2 -> V_21 . V_33 ;
F_13 ( & V_35 -> V_37 -> V_18 ) ;
F_6 ( V_2 ) ;
V_2 = F_72 ( V_35 -> V_37 ,
V_292 ) ;
return V_2 ;
}
V_135 = F_220 ( & V_2 -> V_20 ) ;
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
static int F_248 ( struct V_1 * V_14 ,
struct V_116 * V_117 ,
struct V_68 * V_69 )
{
struct V_34 * V_35 = V_14 -> V_37 -> V_92 ;
struct V_293 * V_293 = NULL ;
T_2 V_294 = 0 ;
int V_295 = V_296 ;
T_2 V_297 = 0 ;
int V_298 = 0 ;
int V_29 = 0 ;
if ( V_14 -> V_21 . V_33 < ( 100 * 1024 * 1024 ) ) {
F_11 ( & V_14 -> V_52 ) ;
V_14 -> V_299 = V_300 ;
F_13 ( & V_14 -> V_52 ) ;
return 0 ;
}
if ( V_117 -> V_225 )
return 0 ;
V_83:
V_293 = F_249 ( V_35 , V_14 , V_69 ) ;
if ( F_209 ( V_293 ) && F_210 ( V_293 ) != - V_159 ) {
V_29 = F_210 ( V_293 ) ;
F_48 ( V_69 ) ;
goto V_78;
}
if ( F_209 ( V_293 ) ) {
F_32 ( V_298 ) ;
V_298 ++ ;
if ( V_14 -> V_301 )
goto V_130;
V_29 = F_250 ( V_35 , V_117 , V_14 , V_69 ) ;
if ( V_29 )
goto V_130;
goto V_83;
}
if ( V_14 -> V_302 == V_117 -> V_303 &&
F_251 ( V_293 ) ) {
V_295 = V_304 ;
goto V_305;
}
F_252 ( V_293 ) -> V_306 = 0 ;
V_29 = F_253 ( V_117 , V_35 , V_293 ) ;
if ( V_29 ) {
F_157 ( V_117 , V_35 , V_29 ) ;
goto V_305;
}
F_8 ( V_29 ) ;
if ( F_251 ( V_293 ) > 0 ) {
V_29 = F_254 ( V_35 ,
& V_35 -> V_37 -> V_263 ) ;
if ( V_29 )
goto V_305;
V_29 = F_255 ( V_35 , V_117 , NULL , V_293 ) ;
if ( V_29 )
goto V_305;
}
F_11 ( & V_14 -> V_52 ) ;
if ( V_14 -> V_3 != V_4 ||
! F_256 ( V_35 , V_307 ) ) {
V_295 = V_300 ;
F_13 ( & V_14 -> V_52 ) ;
goto V_305;
}
F_13 ( & V_14 -> V_52 ) ;
if ( F_235 ( V_308 , & V_117 -> V_134 -> V_7 ) ) {
V_29 = - V_309 ;
goto V_305;
}
V_297 = F_198 ( V_14 -> V_21 . V_33 , 256 * 1024 * 1024 ) ;
if ( ! V_297 )
V_297 = 1 ;
V_297 *= 16 ;
V_297 *= V_310 ;
V_29 = F_257 ( V_293 , 0 , V_297 ) ;
if ( V_29 )
goto V_305;
V_29 = F_258 ( V_293 , V_117 , 0 , 0 , V_297 ,
V_297 , V_297 ,
& V_294 ) ;
if ( ! V_29 )
V_295 = V_304 ;
else if ( V_29 == - V_309 )
F_259 ( V_308 , & V_117 -> V_134 -> V_7 ) ;
F_260 ( V_293 , 0 , V_297 ) ;
V_305:
F_261 ( V_293 ) ;
V_130:
F_48 ( V_69 ) ;
V_78:
F_11 ( & V_14 -> V_52 ) ;
if ( ! V_29 && V_295 == V_304 )
V_14 -> V_302 = V_117 -> V_303 ;
V_14 -> V_299 = V_295 ;
F_13 ( & V_14 -> V_52 ) ;
return V_29 ;
}
int F_262 ( struct V_116 * V_117 ,
struct V_34 * V_35 )
{
struct V_1 * V_2 , * V_311 ;
struct V_312 * V_313 = V_117 -> V_134 ;
struct V_68 * V_69 ;
if ( F_177 ( & V_313 -> V_314 ) ||
! F_256 ( V_35 , V_307 ) )
return 0 ;
V_69 = F_35 () ;
if ( ! V_69 )
return - V_76 ;
F_263 (cache, tmp, &cur_trans->dirty_bgs,
dirty_list) {
if ( V_2 -> V_299 == V_315 )
F_248 ( V_2 , V_117 , V_69 ) ;
}
F_55 ( V_69 ) ;
return 0 ;
}
int F_264 ( struct V_116 * V_117 ,
struct V_34 * V_35 )
{
struct V_1 * V_2 ;
struct V_312 * V_313 = V_117 -> V_134 ;
int V_29 = 0 ;
int V_316 ;
struct V_68 * V_69 = NULL ;
F_265 ( V_317 ) ;
struct V_111 * V_318 = & V_313 -> V_319 ;
int V_320 = 0 ;
int V_321 = 0 ;
F_11 ( & V_313 -> V_322 ) ;
if ( F_177 ( & V_313 -> V_314 ) ) {
F_13 ( & V_313 -> V_322 ) ;
return 0 ;
}
F_266 ( & V_313 -> V_314 , & V_317 ) ;
F_13 ( & V_313 -> V_322 ) ;
V_83:
F_219 ( V_117 , V_35 ) ;
if ( ! V_69 ) {
V_69 = F_35 () ;
if ( ! V_69 )
return - V_76 ;
}
F_39 ( & V_117 -> V_134 -> V_323 ) ;
while ( ! F_177 ( & V_317 ) ) {
V_2 = F_267 ( & V_317 ,
struct V_1 ,
V_324 ) ;
if ( ! F_177 ( & V_2 -> V_325 ) ) {
F_268 ( & V_2 -> V_325 ) ;
F_269 ( V_35 , V_117 , V_2 ,
& V_2 -> V_326 , V_69 ,
V_2 -> V_21 . V_22 ) ;
F_6 ( V_2 ) ;
}
F_11 ( & V_313 -> V_322 ) ;
F_268 ( & V_2 -> V_324 ) ;
F_13 ( & V_313 -> V_322 ) ;
V_316 = 1 ;
F_248 ( V_2 , V_117 , V_69 ) ;
if ( V_2 -> V_299 == V_304 ) {
V_2 -> V_326 . V_293 = NULL ;
V_29 = F_270 ( V_35 , V_117 , V_2 , V_69 ) ;
if ( V_29 == 0 && V_2 -> V_326 . V_293 ) {
V_320 ++ ;
V_316 = 0 ;
F_69 ( & V_2 -> V_325 , V_318 ) ;
} else {
V_29 = 0 ;
}
}
if ( ! V_29 ) {
V_29 = F_243 ( V_117 , V_35 , V_69 , V_2 ) ;
if ( V_29 == - V_159 ) {
V_29 = 0 ;
F_11 ( & V_313 -> V_322 ) ;
if ( F_177 ( & V_2 -> V_324 ) ) {
F_69 ( & V_2 -> V_324 ,
& V_313 -> V_314 ) ;
F_4 ( V_2 ) ;
}
F_13 ( & V_313 -> V_322 ) ;
} else if ( V_29 ) {
F_157 ( V_117 , V_35 , V_29 ) ;
}
}
if ( V_316 )
F_6 ( V_2 ) ;
if ( V_29 )
break;
F_50 ( & V_117 -> V_134 -> V_323 ) ;
F_39 ( & V_117 -> V_134 -> V_323 ) ;
}
F_50 ( & V_117 -> V_134 -> V_323 ) ;
V_29 = F_211 ( V_117 , V_35 , 0 ) ;
if ( ! V_29 && V_321 == 0 ) {
V_321 ++ ;
F_11 ( & V_313 -> V_322 ) ;
F_266 ( & V_313 -> V_314 , & V_317 ) ;
if ( ! F_177 ( & V_317 ) ) {
F_13 ( & V_313 -> V_322 ) ;
goto V_83;
}
F_13 ( & V_313 -> V_322 ) ;
}
F_55 ( V_69 ) ;
return V_29 ;
}
int F_271 ( struct V_116 * V_117 ,
struct V_34 * V_35 )
{
struct V_1 * V_2 ;
struct V_312 * V_313 = V_117 -> V_134 ;
int V_29 = 0 ;
int V_316 ;
struct V_68 * V_69 ;
struct V_111 * V_318 = & V_313 -> V_319 ;
int V_320 = 0 ;
V_69 = F_35 () ;
if ( ! V_69 )
return - V_76 ;
while ( ! F_177 ( & V_313 -> V_314 ) ) {
V_2 = F_267 ( & V_313 -> V_314 ,
struct V_1 ,
V_324 ) ;
if ( ! F_177 ( & V_2 -> V_325 ) ) {
F_268 ( & V_2 -> V_325 ) ;
F_269 ( V_35 , V_117 , V_2 ,
& V_2 -> V_326 , V_69 ,
V_2 -> V_21 . V_22 ) ;
F_6 ( V_2 ) ;
}
F_268 ( & V_2 -> V_324 ) ;
V_316 = 1 ;
F_248 ( V_2 , V_117 , V_69 ) ;
if ( ! V_29 )
V_29 = F_211 ( V_117 , V_35 , ( unsigned long ) - 1 ) ;
if ( ! V_29 && V_2 -> V_299 == V_304 ) {
V_2 -> V_326 . V_293 = NULL ;
V_29 = F_270 ( V_35 , V_117 , V_2 , V_69 ) ;
if ( V_29 == 0 && V_2 -> V_326 . V_293 ) {
V_320 ++ ;
V_316 = 0 ;
F_69 ( & V_2 -> V_325 , V_318 ) ;
} else {
V_29 = 0 ;
}
}
if ( ! V_29 ) {
V_29 = F_243 ( V_117 , V_35 , V_69 , V_2 ) ;
if ( V_29 )
F_157 ( V_117 , V_35 , V_29 ) ;
}
if ( V_316 )
F_6 ( V_2 ) ;
}
while ( ! F_177 ( V_318 ) ) {
V_2 = F_267 ( V_318 , struct V_1 ,
V_325 ) ;
F_268 ( & V_2 -> V_325 ) ;
F_269 ( V_35 , V_117 , V_2 ,
& V_2 -> V_326 , V_69 , V_2 -> V_21 . V_22 ) ;
F_6 ( V_2 ) ;
}
F_55 ( V_69 ) ;
return V_29 ;
}
int F_272 ( struct V_34 * V_35 , T_2 V_27 )
{
struct V_1 * V_14 ;
int V_327 = 0 ;
V_14 = F_73 ( V_35 -> V_37 , V_27 ) ;
if ( ! V_14 || V_14 -> V_301 )
V_327 = 1 ;
if ( V_14 )
F_6 ( V_14 ) ;
return V_327 ;
}
static const char * F_273 ( T_2 V_7 )
{
switch ( V_7 ) {
case V_55 | V_328 :
return L_3 ;
case V_55 :
return L_4 ;
case V_328 :
return L_5 ;
case V_329 :
return L_6 ;
default:
F_8 ( 1 ) ;
return L_7 ;
} ;
}
static int F_274 ( struct V_12 * V_13 , T_2 V_7 ,
T_2 V_330 , T_2 V_94 ,
struct V_110 * * V_95 )
{
struct V_110 * V_113 ;
int V_43 ;
int V_331 ;
int V_29 ;
if ( V_7 & ( V_332 | V_333 |
V_334 ) )
V_331 = 2 ;
else
V_331 = 1 ;
V_113 = F_74 ( V_13 , V_7 ) ;
if ( V_113 ) {
F_11 ( & V_113 -> V_52 ) ;
V_113 -> V_330 += V_330 ;
V_113 -> V_335 += V_330 * V_331 ;
V_113 -> V_94 += V_94 ;
V_113 -> V_336 += V_94 * V_331 ;
if ( V_330 > 0 )
V_113 -> V_115 = 0 ;
F_13 ( & V_113 -> V_52 ) ;
* V_95 = V_113 ;
return 0 ;
}
V_113 = F_58 ( sizeof( * V_113 ) , V_40 ) ;
if ( ! V_113 )
return - V_76 ;
V_29 = F_275 ( & V_113 -> V_337 , 0 , V_338 ) ;
if ( V_29 ) {
F_9 ( V_113 ) ;
return V_29 ;
}
for ( V_43 = 0 ; V_43 < V_339 ; V_43 ++ )
F_59 ( & V_113 -> V_340 [ V_43 ] ) ;
F_276 ( & V_113 -> V_341 ) ;
F_277 ( & V_113 -> V_52 ) ;
V_113 -> V_7 = V_7 & V_114 ;
V_113 -> V_330 = V_330 ;
V_113 -> V_335 = V_330 * V_331 ;
V_113 -> V_94 = V_94 ;
V_113 -> V_336 = V_94 * V_331 ;
V_113 -> V_342 = 0 ;
V_113 -> V_343 = 0 ;
V_113 -> V_344 = 0 ;
V_113 -> V_345 = 0 ;
V_113 -> V_115 = 0 ;
V_113 -> V_346 = 0 ;
V_113 -> V_347 = V_348 ;
V_113 -> V_349 = 0 ;
V_113 -> V_350 = 0 ;
F_61 ( & V_113 -> V_93 ) ;
F_59 ( & V_113 -> V_351 ) ;
V_29 = F_278 ( & V_113 -> V_352 , & V_353 ,
V_13 -> V_354 , L_8 ,
F_273 ( V_113 -> V_7 ) ) ;
if ( V_29 ) {
F_9 ( V_113 ) ;
return V_29 ;
}
* V_95 = V_113 ;
F_279 ( & V_113 -> V_98 , & V_13 -> V_95 ) ;
if ( V_7 & V_328 )
V_13 -> V_355 = V_113 ;
return V_29 ;
}
static void F_280 ( struct V_12 * V_37 , T_2 V_7 )
{
T_2 V_356 = F_281 ( V_7 ) &
V_357 ;
F_282 ( & V_37 -> V_358 ) ;
if ( V_7 & V_328 )
V_37 -> V_359 |= V_356 ;
if ( V_7 & V_55 )
V_37 -> V_360 |= V_356 ;
if ( V_7 & V_329 )
V_37 -> V_361 |= V_356 ;
F_283 ( & V_37 -> V_358 ) ;
}
static T_2 F_284 ( struct V_12 * V_37 , T_2 V_7 )
{
struct V_362 * V_363 = V_37 -> V_364 ;
T_2 V_365 = 0 ;
if ( ! V_363 )
return 0 ;
if ( V_7 & V_328 &&
V_363 -> V_366 . V_7 & V_367 ) {
V_365 = V_328 | V_363 -> V_366 . V_365 ;
} else if ( V_7 & V_329 &&
V_363 -> V_368 . V_7 & V_367 ) {
V_365 = V_329 | V_363 -> V_368 . V_365 ;
} else if ( V_7 & V_55 &&
V_363 -> V_369 . V_7 & V_367 ) {
V_365 = V_55 | V_363 -> V_369 . V_365 ;
}
return V_365 ;
}
static T_2 F_285 ( struct V_34 * V_35 , T_2 V_7 )
{
T_2 V_370 = V_35 -> V_37 -> V_371 -> V_372 ;
T_2 V_365 ;
T_2 V_373 ;
T_2 V_374 = 0 ;
F_11 ( & V_35 -> V_37 -> V_375 ) ;
V_365 = F_284 ( V_35 -> V_37 , V_7 ) ;
if ( V_365 ) {
if ( ( V_7 & V_365 ) & V_357 ) {
F_13 ( & V_35 -> V_37 -> V_375 ) ;
return F_286 ( V_365 ) ;
}
}
F_13 ( & V_35 -> V_37 -> V_375 ) ;
for ( V_373 = 0 ; V_373 < V_339 ; V_373 ++ ) {
if ( V_370 >= V_376 [ V_373 ] . V_377 )
V_374 |= V_378 [ V_373 ] ;
}
V_374 &= V_7 ;
if ( V_374 & V_379 )
V_374 = V_379 ;
else if ( V_374 & V_380 )
V_374 = V_380 ;
else if ( V_374 & V_334 )
V_374 = V_334 ;
else if ( V_374 & V_333 )
V_374 = V_333 ;
else if ( V_374 & V_381 )
V_374 = V_381 ;
V_7 &= ~ V_382 ;
return F_286 ( V_7 | V_374 ) ;
}
static T_2 F_287 ( struct V_34 * V_35 , T_2 V_383 )
{
unsigned V_233 ;
T_2 V_7 ;
do {
V_7 = V_383 ;
V_233 = F_288 ( & V_35 -> V_37 -> V_358 ) ;
if ( V_7 & V_328 )
V_7 |= V_35 -> V_37 -> V_359 ;
else if ( V_7 & V_329 )
V_7 |= V_35 -> V_37 -> V_361 ;
else if ( V_7 & V_55 )
V_7 |= V_35 -> V_37 -> V_360 ;
} while ( F_289 ( & V_35 -> V_37 -> V_358 , V_233 ) );
return F_285 ( V_35 , V_7 ) ;
}
T_2 F_290 ( struct V_34 * V_35 , int V_366 )
{
T_2 V_7 ;
T_2 V_29 ;
if ( V_366 )
V_7 = V_328 ;
else if ( V_35 == V_35 -> V_37 -> V_384 )
V_7 = V_329 ;
else
V_7 = V_55 ;
V_29 = F_287 ( V_35 , V_7 ) ;
return V_29 ;
}
int F_291 ( struct V_293 * V_293 , T_2 V_209 )
{
struct V_110 * V_355 ;
struct V_34 * V_35 = F_252 ( V_293 ) -> V_35 ;
struct V_12 * V_37 = V_35 -> V_37 ;
T_2 V_385 ;
int V_29 = 0 ;
int V_386 = 2 ;
int V_387 ;
V_209 = F_146 ( V_209 , V_35 -> V_57 ) ;
if ( F_292 ( V_293 ) ) {
V_386 = 0 ;
ASSERT ( V_388 -> V_389 ) ;
}
V_355 = V_37 -> V_355 ;
if ( ! V_355 )
goto V_390;
V_83:
F_11 ( & V_355 -> V_52 ) ;
V_385 = V_355 -> V_94 + V_355 -> V_343 +
V_355 -> V_342 + V_355 -> V_344 +
V_355 -> V_345 ;
if ( V_385 + V_209 > V_355 -> V_330 ) {
struct V_116 * V_117 ;
if ( ! V_355 -> V_115 ) {
T_2 V_391 ;
V_355 -> V_347 = V_392 ;
F_13 ( & V_355 -> V_52 ) ;
V_390:
V_391 = F_290 ( V_35 , 1 ) ;
V_117 = F_208 ( V_35 ) ;
if ( F_209 ( V_117 ) )
return F_210 ( V_117 ) ;
V_29 = F_293 ( V_117 , V_35 -> V_37 -> V_67 ,
V_391 ,
V_348 ) ;
F_212 ( V_117 , V_35 ) ;
if ( V_29 < 0 ) {
if ( V_29 != - V_309 )
return V_29 ;
else {
V_387 = 1 ;
goto V_393;
}
}
if ( ! V_355 )
V_355 = V_37 -> V_355 ;
goto V_83;
}
V_387 = F_294 (
& V_355 -> V_337 ,
V_385 + V_209 - V_355 -> V_330 ) ;
F_13 ( & V_355 -> V_52 ) ;
V_393:
if ( V_386 &&
! F_206 ( & V_35 -> V_37 -> V_394 ) ) {
V_386 -- ;
if ( V_386 > 0 )
F_295 ( V_37 , - 1 ) ;
V_117 = F_208 ( V_35 ) ;
if ( F_209 ( V_117 ) )
return F_210 ( V_117 ) ;
if ( V_387 >= 0 ||
F_235 ( V_395 ,
& V_117 -> V_134 -> V_7 ) ||
V_386 > 0 ) {
V_29 = F_296 ( V_117 , V_35 ) ;
if ( V_29 )
return V_29 ;
F_68 ( & V_35 -> V_37 -> V_396 ) ;
F_70 ( & V_35 -> V_37 -> V_396 ) ;
goto V_83;
} else {
F_212 ( V_117 , V_35 ) ;
}
}
F_297 ( V_35 -> V_37 ,
L_9 ,
V_355 -> V_7 , V_209 , 1 ) ;
return - V_309 ;
}
V_355 -> V_345 += V_209 ;
F_297 ( V_35 -> V_37 , L_10 ,
V_355 -> V_7 , V_209 , 1 ) ;
F_13 ( & V_355 -> V_52 ) ;
return V_29 ;
}
int F_257 ( struct V_293 * V_293 , T_2 V_32 , T_2 V_49 )
{
struct V_34 * V_35 = F_252 ( V_293 ) -> V_35 ;
int V_29 ;
V_49 = F_298 ( V_32 + V_49 , V_35 -> V_57 ) -
F_147 ( V_32 , V_35 -> V_57 ) ;
V_32 = F_147 ( V_32 , V_35 -> V_57 ) ;
V_29 = F_291 ( V_293 , V_49 ) ;
if ( V_29 < 0 )
return V_29 ;
V_29 = F_299 ( V_293 , V_32 , V_49 ) ;
return V_29 ;
}
void F_300 ( struct V_293 * V_293 , T_2 V_32 ,
T_2 V_49 )
{
struct V_34 * V_35 = F_252 ( V_293 ) -> V_35 ;
struct V_110 * V_355 ;
V_49 = F_298 ( V_32 + V_49 , V_35 -> V_57 ) -
F_147 ( V_32 , V_35 -> V_57 ) ;
V_32 = F_147 ( V_32 , V_35 -> V_57 ) ;
V_355 = V_35 -> V_37 -> V_355 ;
F_11 ( & V_355 -> V_52 ) ;
if ( F_8 ( V_355 -> V_345 < V_49 ) )
V_355 -> V_345 = 0 ;
else
V_355 -> V_345 -= V_49 ;
F_297 ( V_35 -> V_37 , L_10 ,
V_355 -> V_7 , V_49 , 0 ) ;
F_13 ( & V_355 -> V_52 ) ;
}
void F_260 ( struct V_293 * V_293 , T_2 V_32 , T_2 V_49 )
{
F_300 ( V_293 , V_32 , V_49 ) ;
F_301 ( V_293 , V_32 , V_49 ) ;
}
static void F_302 ( struct V_12 * V_13 )
{
struct V_111 * V_112 = & V_13 -> V_95 ;
struct V_110 * V_113 ;
F_75 () ;
F_76 (found, head, list) {
if ( V_113 -> V_7 & V_55 )
V_113 -> V_347 = V_392 ;
}
F_77 () ;
}
static inline T_2 F_303 ( struct V_259 * V_397 )
{
return ( V_397 -> V_61 << 1 ) ;
}
static int F_304 ( struct V_34 * V_35 ,
struct V_110 * V_398 , int V_399 )
{
struct V_259 * V_260 = & V_35 -> V_37 -> V_263 ;
T_2 V_36 = V_398 -> V_330 - V_398 -> V_344 ;
T_2 V_400 = V_398 -> V_94 + V_398 -> V_343 ;
T_2 V_401 ;
if ( V_399 == V_392 )
return 1 ;
if ( V_398 -> V_7 & V_55 )
V_400 += F_303 ( V_260 ) ;
if ( V_399 == V_402 ) {
V_401 = F_305 ( V_35 -> V_37 -> V_258 ) ;
V_401 = F_36 ( T_2 , 64 * 1024 * 1024 ,
F_306 ( V_401 , 1 ) ) ;
if ( V_36 - V_400 < V_401 )
return 1 ;
}
if ( V_400 + 2 * 1024 * 1024 < F_307 ( V_36 , 8 ) )
return 0 ;
return 1 ;
}
static T_2 F_308 ( struct V_34 * V_35 , T_2 type )
{
T_2 V_403 ;
if ( type & ( V_334 |
V_381 |
V_380 |
V_379 ) )
V_403 = V_35 -> V_37 -> V_371 -> V_372 ;
else if ( type & V_333 )
V_403 = 2 ;
else
V_403 = 1 ;
return V_403 ;
}
void F_309 ( struct V_116 * V_117 ,
struct V_34 * V_35 ,
T_2 type )
{
struct V_110 * V_13 ;
T_2 V_404 ;
T_2 V_401 ;
int V_29 = 0 ;
T_2 V_405 ;
ASSERT ( F_310 ( & V_35 -> V_37 -> V_406 ) ) ;
V_13 = F_74 ( V_35 -> V_37 , V_329 ) ;
F_11 ( & V_13 -> V_52 ) ;
V_404 = V_13 -> V_330 - V_13 -> V_94 - V_13 -> V_342 -
V_13 -> V_343 - V_13 -> V_344 -
V_13 -> V_345 ;
F_13 ( & V_13 -> V_52 ) ;
V_405 = F_308 ( V_35 , type ) ;
V_401 = F_311 ( V_35 , V_405 ) +
F_204 ( V_35 , 1 ) ;
if ( V_404 < V_401 && F_256 ( V_35 , V_407 ) ) {
F_312 ( V_35 -> V_37 , L_11 ,
V_404 , V_401 , type ) ;
F_313 ( V_13 , 0 , 0 ) ;
}
if ( V_404 < V_401 ) {
T_2 V_7 ;
V_7 = F_290 ( V_35 -> V_37 -> V_384 , 0 ) ;
V_29 = F_314 ( V_117 , V_35 , V_7 ) ;
}
if ( ! V_29 ) {
V_29 = F_315 ( V_35 -> V_37 -> V_384 ,
& V_35 -> V_37 -> V_408 ,
V_401 , V_409 ) ;
if ( ! V_29 )
V_117 -> V_410 += V_401 ;
}
}
static int F_293 ( struct V_116 * V_117 ,
struct V_34 * V_67 , T_2 V_7 , int V_399 )
{
struct V_110 * V_95 ;
struct V_12 * V_37 = V_67 -> V_37 ;
int V_411 = 0 ;
int V_29 = 0 ;
if ( V_117 -> V_412 )
return - V_309 ;
V_95 = F_74 ( V_67 -> V_37 , V_7 ) ;
if ( ! V_95 ) {
V_29 = F_274 ( V_67 -> V_37 , V_7 ,
0 , 0 , & V_95 ) ;
F_32 ( V_29 ) ;
}
F_32 ( ! V_95 ) ;
V_83:
F_11 ( & V_95 -> V_52 ) ;
if ( V_399 < V_95 -> V_347 )
V_399 = V_95 -> V_347 ;
if ( V_95 -> V_115 ) {
if ( F_304 ( V_67 , V_95 , V_399 ) )
V_29 = - V_309 ;
else
V_29 = 0 ;
F_13 ( & V_95 -> V_52 ) ;
return V_29 ;
}
if ( ! F_304 ( V_67 , V_95 , V_399 ) ) {
F_13 ( & V_95 -> V_52 ) ;
return 0 ;
} else if ( V_95 -> V_349 ) {
V_411 = 1 ;
} else {
V_95 -> V_349 = 1 ;
}
F_13 ( & V_95 -> V_52 ) ;
F_39 ( & V_37 -> V_406 ) ;
if ( V_411 ) {
F_50 ( & V_37 -> V_406 ) ;
V_411 = 0 ;
goto V_83;
}
V_117 -> V_412 = true ;
if ( F_316 ( V_95 ) )
V_7 |= ( V_328 | V_55 ) ;
if ( V_7 & V_328 && V_37 -> V_413 ) {
V_37 -> V_414 ++ ;
if ( ! ( V_37 -> V_414 %
V_37 -> V_413 ) )
F_302 ( V_37 ) ;
}
F_309 ( V_117 , V_67 , V_7 ) ;
V_29 = F_314 ( V_117 , V_67 , V_7 ) ;
V_117 -> V_412 = false ;
F_11 ( & V_95 -> V_52 ) ;
if ( V_29 < 0 && V_29 != - V_309 )
goto V_78;
if ( V_29 )
V_95 -> V_115 = 1 ;
else
V_29 = 1 ;
V_95 -> V_347 = V_348 ;
V_78:
V_95 -> V_349 = 0 ;
F_13 ( & V_95 -> V_52 ) ;
F_50 ( & V_37 -> V_406 ) ;
if ( V_117 -> V_274 &&
V_117 -> V_410 >= ( 2 * 1024 * 1024ull ) ) {
F_219 ( V_117 , V_117 -> V_35 ) ;
F_317 ( V_117 ) ;
}
return V_29 ;
}
static int F_318 ( struct V_34 * V_35 ,
struct V_110 * V_95 , T_2 V_209 ,
enum V_415 V_350 )
{
struct V_259 * V_260 = & V_35 -> V_37 -> V_263 ;
T_2 V_416 = F_290 ( V_35 , 0 ) ;
T_2 V_417 ;
T_2 V_418 ;
T_2 V_385 ;
V_385 = V_95 -> V_94 + V_95 -> V_343 +
V_95 -> V_342 + V_95 -> V_344 ;
F_11 ( & V_260 -> V_52 ) ;
V_417 = F_303 ( V_260 ) ;
F_13 ( & V_260 -> V_52 ) ;
if ( V_385 + V_417 >= V_95 -> V_330 )
return 0 ;
V_385 += V_95 -> V_345 ;
F_11 ( & V_35 -> V_37 -> V_419 ) ;
V_418 = V_35 -> V_37 -> V_420 ;
F_13 ( & V_35 -> V_37 -> V_419 ) ;
if ( V_416 & ( V_332 |
V_333 |
V_334 ) )
V_418 >>= 1 ;
if ( V_350 == V_421 )
V_418 >>= 3 ;
else
V_418 >>= 1 ;
if ( V_385 + V_209 < V_95 -> V_330 + V_418 )
return 1 ;
return 0 ;
}
static void F_319 ( struct V_34 * V_35 ,
unsigned long V_422 , int V_423 )
{
struct V_424 * V_425 = V_35 -> V_37 -> V_425 ;
if ( F_320 ( & V_425 -> V_426 ) ) {
F_321 ( V_425 , V_422 , V_427 ) ;
F_49 ( & V_425 -> V_426 ) ;
} else {
F_322 ( V_35 -> V_37 , 0 , V_423 ) ;
if ( ! V_388 -> V_389 )
F_295 ( V_35 -> V_37 , V_423 ) ;
}
}
static inline int F_323 ( struct V_34 * V_35 , T_2 V_428 )
{
T_2 V_209 ;
int V_44 ;
V_209 = F_204 ( V_35 , 1 ) ;
V_44 = ( int ) F_201 ( V_428 , V_209 ) ;
if ( ! V_44 )
V_44 = 1 ;
return V_44 ;
}
static void F_324 ( struct V_34 * V_35 , T_2 V_428 , T_2 V_429 ,
bool V_430 )
{
struct V_259 * V_431 ;
struct V_110 * V_95 ;
struct V_116 * V_117 ;
T_2 V_432 ;
T_2 V_433 ;
long V_434 ;
unsigned long V_422 ;
int V_321 ;
int V_435 ;
enum V_415 V_350 ;
V_435 = F_323 ( V_35 , V_428 ) ;
V_428 = V_435 * V_436 ;
V_117 = (struct V_116 * ) V_388 -> V_389 ;
V_431 = & V_35 -> V_37 -> V_437 ;
V_95 = V_431 -> V_95 ;
V_432 = F_325 (
& V_35 -> V_37 -> V_432 ) ;
if ( V_432 == 0 ) {
if ( V_117 )
return;
if ( V_430 )
F_295 ( V_35 -> V_37 , V_435 ) ;
return;
}
V_321 = 0 ;
while ( V_432 && V_321 < 3 ) {
V_433 = F_326 ( V_432 , V_428 ) ;
V_422 = V_433 >> V_438 ;
F_319 ( V_35 , V_422 , V_435 ) ;
V_433 = F_206 ( & V_35 -> V_37 -> V_439 ) ;
if ( ! V_433 )
goto V_440;
if ( V_433 <= V_422 )
V_433 = 0 ;
else
V_433 -= V_422 ;
F_327 ( V_35 -> V_37 -> V_441 ,
F_206 ( & V_35 -> V_37 -> V_439 ) <=
( int ) V_433 ) ;
V_440:
if ( ! V_117 )
V_350 = V_421 ;
else
V_350 = V_409 ;
F_11 ( & V_95 -> V_52 ) ;
if ( F_318 ( V_35 , V_95 , V_429 , V_350 ) ) {
F_13 ( & V_95 -> V_52 ) ;
break;
}
F_13 ( & V_95 -> V_52 ) ;
V_321 ++ ;
if ( V_430 && ! V_117 ) {
F_295 ( V_35 -> V_37 , V_435 ) ;
} else {
V_434 = F_328 ( 1 ) ;
if ( V_434 )
break;
}
V_432 = F_325 (
& V_35 -> V_37 -> V_432 ) ;
}
}
static int F_329 ( struct V_34 * V_35 ,
struct V_110 * V_95 ,
T_2 V_209 , int V_399 )
{
struct V_259 * V_442 = & V_35 -> V_37 -> V_443 ;
struct V_116 * V_117 ;
V_117 = (struct V_116 * ) V_388 -> V_389 ;
if ( V_117 )
return - V_184 ;
if ( V_399 )
goto V_444;
if ( F_294 ( & V_95 -> V_337 ,
V_209 ) >= 0 )
goto V_444;
if ( V_95 != V_442 -> V_95 )
return - V_309 ;
F_11 ( & V_442 -> V_52 ) ;
if ( F_294 ( & V_95 -> V_337 ,
V_209 - V_442 -> V_61 ) >= 0 ) {
F_13 ( & V_442 -> V_52 ) ;
return - V_309 ;
}
F_13 ( & V_442 -> V_52 ) ;
V_444:
V_117 = F_208 ( V_35 ) ;
if ( F_209 ( V_117 ) )
return - V_309 ;
return F_296 ( V_117 , V_35 ) ;
}
static int F_330 ( struct V_34 * V_35 ,
struct V_110 * V_95 , T_2 V_36 ,
T_2 V_445 , int V_288 )
{
struct V_116 * V_117 ;
int V_44 ;
int V_29 = 0 ;
switch ( V_288 ) {
case V_446 :
case V_447 :
if ( V_288 == V_446 )
V_44 = F_323 ( V_35 , V_36 ) * 2 ;
else
V_44 = - 1 ;
V_117 = F_208 ( V_35 ) ;
if ( F_209 ( V_117 ) ) {
V_29 = F_210 ( V_117 ) ;
break;
}
V_29 = F_331 ( V_117 , V_35 , V_44 ) ;
F_212 ( V_117 , V_35 ) ;
break;
case V_448 :
case V_449 :
F_324 ( V_35 , V_36 * 2 , V_445 ,
V_288 == V_449 ) ;
break;
case V_450 :
V_117 = F_208 ( V_35 ) ;
if ( F_209 ( V_117 ) ) {
V_29 = F_210 ( V_117 ) ;
break;
}
V_29 = F_293 ( V_117 , V_35 -> V_37 -> V_67 ,
F_290 ( V_35 , 0 ) ,
V_348 ) ;
F_212 ( V_117 , V_35 ) ;
if ( V_29 == - V_309 )
V_29 = 0 ;
break;
case V_451 :
V_29 = F_329 ( V_35 , V_95 , V_445 , 0 ) ;
break;
default:
V_29 = - V_309 ;
break;
}
return V_29 ;
}
static inline T_2
F_332 ( struct V_34 * V_35 ,
struct V_110 * V_95 )
{
T_2 V_385 ;
T_2 V_452 ;
T_2 V_428 ;
V_428 = F_24 ( T_2 , F_333 () * 1024 * 1024 ,
16 * 1024 * 1024 ) ;
F_11 ( & V_95 -> V_52 ) ;
if ( F_318 ( V_35 , V_95 , V_428 ,
V_421 ) ) {
V_428 = 0 ;
goto V_78;
}
V_385 = V_95 -> V_94 + V_95 -> V_343 +
V_95 -> V_342 + V_95 -> V_344 +
V_95 -> V_345 ;
if ( F_318 ( V_35 , V_95 , 1024 * 1024 ,
V_421 ) )
V_452 = F_306 ( V_95 -> V_330 , 95 ) ;
else
V_452 = F_306 ( V_95 -> V_330 , 90 ) ;
if ( V_385 > V_452 )
V_428 = V_385 - V_452 ;
else
V_428 = 0 ;
V_428 = F_326 ( V_428 , V_95 -> V_345 +
V_95 -> V_343 ) ;
V_78:
F_13 ( & V_95 -> V_52 ) ;
return V_428 ;
}
static inline int F_334 ( struct V_110 * V_95 ,
struct V_12 * V_37 , T_2 V_385 )
{
T_2 V_401 = F_306 ( V_95 -> V_330 , 98 ) ;
if ( V_95 -> V_94 >= V_401 )
return 0 ;
return ( V_385 >= V_401 && ! F_43 ( V_37 ) &&
! F_235 ( V_453 , & V_37 -> V_454 ) ) ;
}
static int F_335 ( struct V_110 * V_95 ,
struct V_12 * V_37 ,
int V_455 )
{
T_2 V_385 ;
F_11 ( & V_95 -> V_52 ) ;
if ( V_455 > V_451 && V_95 -> V_115 ) {
F_13 ( & V_95 -> V_52 ) ;
return 0 ;
}
V_385 = V_95 -> V_94 + V_95 -> V_343 +
V_95 -> V_342 + V_95 -> V_344 +
V_95 -> V_345 ;
if ( F_334 ( V_95 , V_37 , V_385 ) ) {
F_13 ( & V_95 -> V_52 ) ;
return 1 ;
}
F_13 ( & V_95 -> V_52 ) ;
return 0 ;
}
static void F_336 ( struct V_456 * V_66 )
{
struct V_12 * V_37 ;
struct V_110 * V_95 ;
T_2 V_428 ;
int V_455 ;
V_37 = F_34 ( V_66 , struct V_12 , V_457 ) ;
V_95 = F_74 ( V_37 , V_55 ) ;
V_428 = F_332 ( V_37 -> V_458 ,
V_95 ) ;
if ( ! V_428 )
return;
V_455 = V_446 ;
do {
F_330 ( V_37 -> V_458 , V_95 , V_428 ,
V_428 , V_455 ) ;
V_455 ++ ;
if ( ! F_335 ( V_95 , V_37 ,
V_455 ) )
return;
} while ( V_455 < V_451 );
}
void F_337 ( struct V_456 * V_66 )
{
F_338 ( V_66 , F_336 ) ;
}
static int F_339 ( struct V_34 * V_35 ,
struct V_259 * V_431 ,
T_2 V_445 ,
enum V_415 V_350 )
{
struct V_110 * V_95 = V_431 -> V_95 ;
T_2 V_385 ;
T_2 V_36 = V_445 ;
int V_455 = V_446 ;
int V_29 = 0 ;
bool V_459 = false ;
V_83:
V_29 = 0 ;
F_11 ( & V_95 -> V_52 ) ;
while ( V_350 == V_421 && ! V_459 &&
V_95 -> V_350 ) {
F_13 ( & V_95 -> V_52 ) ;
if ( V_388 -> V_389 )
return - V_184 ;
V_29 = F_340 ( V_95 -> V_93 , ! V_95 -> V_350 ) ;
if ( V_29 )
return - V_460 ;
F_11 ( & V_95 -> V_52 ) ;
}
V_29 = - V_309 ;
V_385 = V_95 -> V_94 + V_95 -> V_343 +
V_95 -> V_342 + V_95 -> V_344 +
V_95 -> V_345 ;
if ( V_385 <= V_95 -> V_330 ) {
if ( V_385 + V_445 <= V_95 -> V_330 ) {
V_95 -> V_345 += V_445 ;
F_297 ( V_35 -> V_37 ,
L_10 , V_95 -> V_7 , V_445 , 1 ) ;
V_29 = 0 ;
} else {
V_36 = V_445 ;
}
} else {
V_36 = V_385 - V_95 -> V_330 +
( V_445 * 2 ) ;
}
if ( V_29 && F_318 ( V_35 , V_95 , V_445 , V_350 ) ) {
V_95 -> V_345 += V_445 ;
F_297 ( V_35 -> V_37 , L_10 ,
V_95 -> V_7 , V_445 ,
1 ) ;
V_29 = 0 ;
}
if ( V_29 && V_350 != V_409 ) {
V_459 = true ;
V_95 -> V_350 = 1 ;
} else if ( ! V_29 && V_95 -> V_7 & V_55 ) {
V_385 += V_445 ;
if ( ! V_35 -> V_37 -> V_461 &&
F_334 ( V_95 , V_35 -> V_37 , V_385 ) &&
! F_341 ( & V_35 -> V_37 -> V_457 ) )
F_342 ( V_462 ,
& V_35 -> V_37 -> V_457 ) ;
}
F_13 ( & V_95 -> V_52 ) ;
if ( ! V_29 || V_350 == V_409 )
goto V_78;
V_29 = F_330 ( V_35 , V_95 , V_36 , V_445 ,
V_455 ) ;
V_455 ++ ;
if ( V_350 == V_463 &&
( V_455 == V_448 ||
V_455 == V_449 ) )
V_455 = V_450 ;
if ( ! V_29 )
goto V_83;
else if ( V_350 == V_463 &&
V_455 < V_451 )
goto V_83;
else if ( V_350 == V_421 &&
V_455 <= V_451 )
goto V_83;
V_78:
if ( V_29 == - V_309 &&
F_343 ( V_35 -> V_464 == V_465 ) ) {
struct V_259 * V_260 =
& V_35 -> V_37 -> V_263 ;
if ( V_431 != V_260 &&
! F_344 ( V_260 , V_445 ) )
V_29 = 0 ;
}
if ( V_29 == - V_309 )
F_297 ( V_35 -> V_37 ,
L_9 ,
V_95 -> V_7 , V_445 , 1 ) ;
if ( V_459 ) {
F_11 ( & V_95 -> V_52 ) ;
V_95 -> V_350 = 0 ;
F_345 ( & V_95 -> V_93 ) ;
F_13 ( & V_95 -> V_52 ) ;
}
return V_29 ;
}
static struct V_259 * F_346 (
const struct V_116 * V_117 ,
const struct V_34 * V_35 )
{
struct V_259 * V_431 = NULL ;
if ( F_235 ( V_287 , & V_35 -> V_288 ) ||
( V_35 == V_35 -> V_37 -> V_466 && V_117 -> V_467 ) ||
( V_35 == V_35 -> V_37 -> V_468 ) )
V_431 = V_117 -> V_431 ;
if ( ! V_431 )
V_431 = V_35 -> V_431 ;
if ( ! V_431 )
V_431 = & V_35 -> V_37 -> V_469 ;
return V_431 ;
}
static int F_344 ( struct V_259 * V_431 ,
T_2 V_36 )
{
int V_29 = - V_309 ;
F_11 ( & V_431 -> V_52 ) ;
if ( V_431 -> V_10 >= V_36 ) {
V_431 -> V_10 -= V_36 ;
if ( V_431 -> V_10 < V_431 -> V_61 )
V_431 -> V_115 = 0 ;
V_29 = 0 ;
}
F_13 ( & V_431 -> V_52 ) ;
return V_29 ;
}
static void F_347 ( struct V_259 * V_431 ,
T_2 V_36 , int V_470 )
{
F_11 ( & V_431 -> V_52 ) ;
V_431 -> V_10 += V_36 ;
if ( V_470 )
V_431 -> V_61 += V_36 ;
else if ( V_431 -> V_10 >= V_431 -> V_61 )
V_431 -> V_115 = 1 ;
F_13 ( & V_431 -> V_52 ) ;
}
int F_348 ( struct V_12 * V_37 ,
struct V_259 * V_471 , T_2 V_36 ,
int V_472 )
{
struct V_259 * V_260 = & V_37 -> V_263 ;
T_2 V_473 ;
if ( V_260 -> V_95 != V_471 -> V_95 )
return - V_309 ;
F_11 ( & V_260 -> V_52 ) ;
V_473 = F_307 ( V_260 -> V_61 , V_472 ) ;
if ( V_260 -> V_10 < V_473 + V_36 ) {
F_13 ( & V_260 -> V_52 ) ;
return - V_309 ;
}
V_260 -> V_10 -= V_36 ;
if ( V_260 -> V_10 < V_260 -> V_61 )
V_260 -> V_115 = 0 ;
F_13 ( & V_260 -> V_52 ) ;
F_347 ( V_471 , V_36 , 1 ) ;
return 0 ;
}
static void F_349 ( struct V_12 * V_37 ,
struct V_259 * V_431 ,
struct V_259 * V_471 , T_2 V_36 )
{
struct V_110 * V_95 = V_431 -> V_95 ;
F_11 ( & V_431 -> V_52 ) ;
if ( V_36 == ( T_2 ) - 1 )
V_36 = V_431 -> V_61 ;
V_431 -> V_61 -= V_36 ;
if ( V_431 -> V_10 >= V_431 -> V_61 ) {
V_36 = V_431 -> V_10 - V_431 -> V_61 ;
V_431 -> V_10 = V_431 -> V_61 ;
V_431 -> V_115 = 1 ;
} else {
V_36 = 0 ;
}
F_13 ( & V_431 -> V_52 ) ;
if ( V_36 > 0 ) {
if ( V_471 ) {
F_11 ( & V_471 -> V_52 ) ;
if ( ! V_471 -> V_115 ) {
T_2 V_474 ;
V_474 = V_471 -> V_61 - V_471 -> V_10 ;
V_474 = F_326 ( V_36 , V_474 ) ;
V_471 -> V_10 += V_474 ;
if ( V_471 -> V_10 >= V_471 -> V_61 )
V_471 -> V_115 = 1 ;
V_36 -= V_474 ;
}
F_13 ( & V_471 -> V_52 ) ;
}
if ( V_36 ) {
F_11 ( & V_95 -> V_52 ) ;
V_95 -> V_345 -= V_36 ;
F_297 ( V_37 , L_10 ,
V_95 -> V_7 , V_36 , 0 ) ;
F_13 ( & V_95 -> V_52 ) ;
}
}
}
static int F_350 ( struct V_259 * V_475 ,
struct V_259 * V_476 , T_2 V_36 )
{
int V_29 ;
V_29 = F_344 ( V_475 , V_36 ) ;
if ( V_29 )
return V_29 ;
F_347 ( V_476 , V_36 , 1 ) ;
return 0 ;
}
void F_351 ( struct V_259 * V_477 , unsigned short type )
{
memset ( V_477 , 0 , sizeof( * V_477 ) ) ;
F_277 ( & V_477 -> V_52 ) ;
V_477 -> type = type ;
}
struct V_259 * F_352 ( struct V_34 * V_35 ,
unsigned short type )
{
struct V_259 * V_431 ;
struct V_12 * V_37 = V_35 -> V_37 ;
V_431 = F_215 ( sizeof( * V_431 ) , V_40 ) ;
if ( ! V_431 )
return NULL ;
F_351 ( V_431 , type ) ;
V_431 -> V_95 = F_74 ( V_37 ,
V_55 ) ;
return V_431 ;
}
void F_353 ( struct V_34 * V_35 ,
struct V_259 * V_477 )
{
if ( ! V_477 )
return;
F_354 ( V_35 , V_477 , ( T_2 ) - 1 ) ;
F_9 ( V_477 ) ;
}
void F_355 ( struct V_259 * V_477 )
{
F_9 ( V_477 ) ;
}
int F_315 ( struct V_34 * V_35 ,
struct V_259 * V_431 , T_2 V_36 ,
enum V_415 V_350 )
{
int V_29 ;
if ( V_36 == 0 )
return 0 ;
V_29 = F_339 ( V_35 , V_431 , V_36 , V_350 ) ;
if ( ! V_29 ) {
F_347 ( V_431 , V_36 , 1 ) ;
return 0 ;
}
return V_29 ;
}
int F_356 ( struct V_34 * V_35 ,
struct V_259 * V_431 , int V_472 )
{
T_2 V_36 = 0 ;
int V_29 = - V_309 ;
if ( ! V_431 )
return 0 ;
F_11 ( & V_431 -> V_52 ) ;
V_36 = F_307 ( V_431 -> V_61 , V_472 ) ;
if ( V_431 -> V_10 >= V_36 )
V_29 = 0 ;
F_13 ( & V_431 -> V_52 ) ;
return V_29 ;
}
int F_357 ( struct V_34 * V_35 ,
struct V_259 * V_431 , T_2 V_478 ,
enum V_415 V_350 )
{
T_2 V_36 = 0 ;
int V_29 = - V_309 ;
if ( ! V_431 )
return 0 ;
F_11 ( & V_431 -> V_52 ) ;
V_36 = V_478 ;
if ( V_431 -> V_10 >= V_36 )
V_29 = 0 ;
else
V_36 -= V_431 -> V_10 ;
F_13 ( & V_431 -> V_52 ) ;
if ( ! V_29 )
return 0 ;
V_29 = F_339 ( V_35 , V_431 , V_36 , V_350 ) ;
if ( ! V_29 ) {
F_347 ( V_431 , V_36 , 0 ) ;
return 0 ;
}
return V_29 ;
}
int F_358 ( struct V_259 * V_479 ,
struct V_259 * V_480 ,
T_2 V_36 )
{
return F_350 ( V_479 , V_480 , V_36 ) ;
}
void F_354 ( struct V_34 * V_35 ,
struct V_259 * V_431 ,
T_2 V_36 )
{
struct V_259 * V_260 = & V_35 -> V_37 -> V_263 ;
if ( V_260 == V_431 ||
V_431 -> V_95 != V_260 -> V_95 )
V_260 = NULL ;
F_349 ( V_35 -> V_37 , V_431 , V_260 ,
V_36 ) ;
}
static T_2 F_359 ( struct V_12 * V_37 )
{
struct V_110 * V_398 ;
T_2 V_36 ;
T_2 V_481 ;
T_2 V_482 ;
int V_254 = F_202 ( V_37 -> V_258 ) ;
V_398 = F_74 ( V_37 , V_328 ) ;
F_11 ( & V_398 -> V_52 ) ;
V_482 = V_398 -> V_94 ;
F_13 ( & V_398 -> V_52 ) ;
V_398 = F_74 ( V_37 , V_55 ) ;
F_11 ( & V_398 -> V_52 ) ;
if ( V_398 -> V_7 & V_328 )
V_482 = 0 ;
V_481 = V_398 -> V_94 ;
F_13 ( & V_398 -> V_52 ) ;
V_36 = ( V_482 >> V_37 -> V_425 -> V_483 ) *
V_254 * 2 ;
V_36 += F_198 ( V_482 + V_481 , 50 ) ;
if ( V_36 * 3 > V_481 )
V_36 = F_198 ( V_481 , 3 ) ;
return F_146 ( V_36 , V_37 -> V_67 -> V_56 << 10 ) ;
}
static void F_360 ( struct V_12 * V_37 )
{
struct V_259 * V_431 = & V_37 -> V_263 ;
struct V_110 * V_398 = V_431 -> V_95 ;
T_2 V_36 ;
V_36 = F_359 ( V_37 ) ;
F_11 ( & V_398 -> V_52 ) ;
F_11 ( & V_431 -> V_52 ) ;
V_431 -> V_61 = F_24 ( T_2 , V_36 , 512 * 1024 * 1024 ) ;
V_36 = V_398 -> V_94 + V_398 -> V_342 +
V_398 -> V_343 + V_398 -> V_344 +
V_398 -> V_345 ;
if ( V_398 -> V_330 > V_36 ) {
V_36 = V_398 -> V_330 - V_36 ;
V_431 -> V_10 += V_36 ;
V_398 -> V_345 += V_36 ;
F_297 ( V_37 , L_10 ,
V_398 -> V_7 , V_36 , 1 ) ;
}
if ( V_431 -> V_10 >= V_431 -> V_61 ) {
V_36 = V_431 -> V_10 - V_431 -> V_61 ;
V_398 -> V_345 -= V_36 ;
F_297 ( V_37 , L_10 ,
V_398 -> V_7 , V_36 , 0 ) ;
V_431 -> V_10 = V_431 -> V_61 ;
V_431 -> V_115 = 1 ;
}
F_13 ( & V_431 -> V_52 ) ;
F_13 ( & V_398 -> V_52 ) ;
}
static void F_361 ( struct V_12 * V_37 )
{
struct V_110 * V_95 ;
V_95 = F_74 ( V_37 , V_329 ) ;
V_37 -> V_408 . V_95 = V_95 ;
V_95 = F_74 ( V_37 , V_55 ) ;
V_37 -> V_263 . V_95 = V_95 ;
V_37 -> V_437 . V_95 = V_95 ;
V_37 -> V_484 . V_95 = V_95 ;
V_37 -> V_469 . V_95 = V_95 ;
V_37 -> V_443 . V_95 = V_95 ;
V_37 -> V_67 -> V_431 = & V_37 -> V_263 ;
V_37 -> V_466 -> V_431 = & V_37 -> V_263 ;
V_37 -> V_485 -> V_431 = & V_37 -> V_263 ;
V_37 -> V_92 -> V_431 = & V_37 -> V_263 ;
if ( V_37 -> V_486 )
V_37 -> V_486 -> V_431 = & V_37 -> V_263 ;
V_37 -> V_384 -> V_431 = & V_37 -> V_408 ;
F_360 ( V_37 ) ;
}
static void F_362 ( struct V_12 * V_37 )
{
F_349 ( V_37 , & V_37 -> V_263 , NULL ,
( T_2 ) - 1 ) ;
F_8 ( V_37 -> V_437 . V_61 > 0 ) ;
F_8 ( V_37 -> V_437 . V_10 > 0 ) ;
F_8 ( V_37 -> V_484 . V_61 > 0 ) ;
F_8 ( V_37 -> V_484 . V_10 > 0 ) ;
F_8 ( V_37 -> V_408 . V_61 > 0 ) ;
F_8 ( V_37 -> V_408 . V_10 > 0 ) ;
F_8 ( V_37 -> V_443 . V_61 > 0 ) ;
F_8 ( V_37 -> V_443 . V_10 > 0 ) ;
}
void F_363 ( struct V_116 * V_117 ,
struct V_34 * V_35 )
{
if ( ! V_117 -> V_431 )
return;
if ( ! V_117 -> V_343 )
return;
F_297 ( V_35 -> V_37 , L_12 ,
V_117 -> V_303 , V_117 -> V_343 , 0 ) ;
F_354 ( V_35 , V_117 -> V_431 , V_117 -> V_343 ) ;
V_117 -> V_343 = 0 ;
}
void F_317 ( struct V_116 * V_117 )
{
struct V_12 * V_37 = V_117 -> V_35 -> V_37 ;
if ( ! V_117 -> V_410 )
return;
F_364 ( ! F_177 ( & V_117 -> V_276 ) ) ;
F_349 ( V_37 , & V_37 -> V_408 , NULL ,
V_117 -> V_410 ) ;
V_117 -> V_410 = 0 ;
}
int F_365 ( struct V_116 * V_117 ,
struct V_293 * V_293 )
{
struct V_34 * V_35 = F_252 ( V_293 ) -> V_35 ;
struct V_259 * V_479 = F_346 ( V_117 , V_35 ) ;
struct V_259 * V_480 = V_35 -> V_487 ;
T_2 V_36 = F_204 ( V_35 , 1 ) ;
F_297 ( V_35 -> V_37 , L_13 ,
F_366 ( V_293 ) , V_36 , 1 ) ;
return F_350 ( V_479 , V_480 , V_36 ) ;
}
void F_367 ( struct V_293 * V_293 )
{
struct V_34 * V_35 = F_252 ( V_293 ) -> V_35 ;
T_2 V_36 = F_204 ( V_35 , 1 ) ;
F_297 ( V_35 -> V_37 , L_13 ,
F_366 ( V_293 ) , V_36 , 0 ) ;
F_354 ( V_35 , V_35 -> V_487 , V_36 ) ;
}
int F_368 ( struct V_34 * V_35 ,
struct V_259 * V_477 ,
int V_435 ,
T_2 * V_228 ,
bool V_488 )
{
T_2 V_36 ;
int V_29 ;
struct V_259 * V_260 = & V_35 -> V_37 -> V_263 ;
if ( V_35 -> V_37 -> V_489 ) {
V_36 = 3 * V_35 -> V_56 ;
V_29 = F_369 ( V_35 , V_36 ) ;
if ( V_29 )
return V_29 ;
} else {
V_36 = 0 ;
}
* V_228 = V_36 ;
V_36 = F_204 ( V_35 , V_435 ) ;
V_477 -> V_95 = F_74 ( V_35 -> V_37 ,
V_55 ) ;
V_29 = F_315 ( V_35 , V_477 , V_36 ,
V_421 ) ;
if ( V_29 == - V_309 && V_488 )
V_29 = F_358 ( V_260 , V_477 , V_36 ) ;
if ( V_29 && * V_228 )
F_370 ( V_35 , * V_228 ) ;
return V_29 ;
}
void F_371 ( struct V_34 * V_35 ,
struct V_259 * V_477 ,
T_2 V_228 )
{
F_354 ( V_35 , V_477 , ( T_2 ) - 1 ) ;
}
static unsigned F_372 ( struct V_293 * V_293 , T_2 V_36 )
{
unsigned V_490 = 0 ;
unsigned V_491 = 0 ;
unsigned V_492 = 0 ;
V_492 = ( unsigned ) F_201 ( V_36 +
V_493 - 1 ,
V_493 ) ;
ASSERT ( V_492 ) ;
ASSERT ( F_252 ( V_293 ) -> V_494 >= V_492 ) ;
F_252 ( V_293 ) -> V_494 -= V_492 ;
if ( F_252 ( V_293 ) -> V_494 == 0 &&
F_373 ( V_495 ,
& F_252 ( V_293 ) -> V_496 ) )
V_490 = 1 ;
if ( F_252 ( V_293 ) -> V_494 >=
F_252 ( V_293 ) -> V_497 )
return V_490 ;
V_491 = F_252 ( V_293 ) -> V_497 -
F_252 ( V_293 ) -> V_494 ;
F_252 ( V_293 ) -> V_497 -= V_491 ;
return V_491 + V_490 ;
}
static T_2 F_374 ( struct V_293 * V_293 , T_2 V_36 ,
int V_498 )
{
struct V_34 * V_35 = F_252 ( V_293 ) -> V_35 ;
T_2 V_499 , V_256 ;
if ( F_252 ( V_293 ) -> V_7 & V_500 &&
F_252 ( V_293 ) -> V_253 == 0 )
return 0 ;
V_499 = F_200 ( V_35 , F_252 ( V_293 ) -> V_253 ) ;
if ( V_498 )
F_252 ( V_293 ) -> V_253 += V_36 ;
else
F_252 ( V_293 ) -> V_253 -= V_36 ;
V_256 = F_200 ( V_35 , F_252 ( V_293 ) -> V_253 ) ;
if ( V_499 == V_256 )
return 0 ;
if ( V_498 )
return F_204 ( V_35 ,
V_256 - V_499 ) ;
return F_204 ( V_35 , V_499 - V_256 ) ;
}
int F_375 ( struct V_293 * V_293 , T_2 V_36 )
{
struct V_34 * V_35 = F_252 ( V_293 ) -> V_35 ;
struct V_259 * V_431 = & V_35 -> V_37 -> V_437 ;
T_2 V_501 = 0 ;
T_2 V_253 ;
unsigned V_502 = 0 ;
int V_503 = 0 ;
enum V_415 V_350 = V_421 ;
int V_29 = 0 ;
bool V_504 = true ;
T_2 V_505 = 0 ;
unsigned V_506 ;
if ( F_292 ( V_293 ) ) {
V_350 = V_409 ;
V_504 = false ;
}
if ( V_350 != V_409 &&
F_376 ( V_35 -> V_37 ) )
F_377 ( 1 ) ;
if ( V_504 )
F_39 ( & F_252 ( V_293 ) -> V_507 ) ;
V_36 = F_146 ( V_36 , V_35 -> V_57 ) ;
F_11 ( & F_252 ( V_293 ) -> V_52 ) ;
V_502 = ( unsigned ) F_201 ( V_36 +
V_493 - 1 ,
V_493 ) ;
F_252 ( V_293 ) -> V_494 += V_502 ;
V_502 = 0 ;
if ( F_252 ( V_293 ) -> V_494 >
F_252 ( V_293 ) -> V_497 )
V_502 = F_252 ( V_293 ) -> V_494 -
F_252 ( V_293 ) -> V_497 ;
if ( ! F_235 ( V_495 ,
& F_252 ( V_293 ) -> V_496 ) ) {
V_502 ++ ;
V_503 = 1 ;
}
V_501 = F_204 ( V_35 , V_502 ) ;
V_501 += F_374 ( V_293 , V_36 , 1 ) ;
V_253 = F_252 ( V_293 ) -> V_253 ;
F_13 ( & F_252 ( V_293 ) -> V_52 ) ;
if ( V_35 -> V_37 -> V_489 ) {
V_29 = F_369 ( V_35 ,
V_502 * V_35 -> V_56 ) ;
if ( V_29 )
goto V_508;
}
V_29 = F_339 ( V_35 , V_431 , V_501 , V_350 ) ;
if ( F_343 ( V_29 ) ) {
F_370 ( V_35 , V_502 * V_35 -> V_56 ) ;
goto V_508;
}
F_11 ( & F_252 ( V_293 ) -> V_52 ) ;
if ( V_503 ) {
F_259 ( V_495 ,
& F_252 ( V_293 ) -> V_496 ) ;
V_502 -- ;
}
F_252 ( V_293 ) -> V_497 += V_502 ;
F_13 ( & F_252 ( V_293 ) -> V_52 ) ;
if ( V_504 )
F_50 ( & F_252 ( V_293 ) -> V_507 ) ;
if ( V_501 )
F_297 ( V_35 -> V_37 , L_14 ,
F_366 ( V_293 ) , V_501 , 1 ) ;
F_347 ( V_431 , V_501 , 1 ) ;
return 0 ;
V_508:
F_11 ( & F_252 ( V_293 ) -> V_52 ) ;
V_506 = F_372 ( V_293 , V_36 ) ;
if ( F_252 ( V_293 ) -> V_253 == V_253 ) {
F_374 ( V_293 , V_36 , 0 ) ;
} else {
T_2 V_509 = F_252 ( V_293 ) -> V_253 ;
T_2 V_209 ;
V_209 = V_253 - F_252 ( V_293 ) -> V_253 ;
F_252 ( V_293 ) -> V_253 = V_253 ;
V_505 = F_374 ( V_293 , V_209 , 0 ) ;
F_252 ( V_293 ) -> V_253 = V_253 - V_36 ;
V_209 = V_253 - V_509 ;
V_209 = F_374 ( V_293 , V_209 , 0 ) ;
F_252 ( V_293 ) -> V_253 = V_509 - V_36 ;
if ( V_209 > V_505 )
V_505 = V_209 - V_505 ;
else
V_505 = 0 ;
}
F_13 ( & F_252 ( V_293 ) -> V_52 ) ;
if ( V_506 )
V_505 += F_204 ( V_35 , V_506 ) ;
if ( V_505 ) {
F_354 ( V_35 , V_431 , V_505 ) ;
F_297 ( V_35 -> V_37 , L_14 ,
F_366 ( V_293 ) , V_505 , 0 ) ;
}
if ( V_504 )
F_50 ( & F_252 ( V_293 ) -> V_507 ) ;
return V_29 ;
}
void F_378 ( struct V_293 * V_293 , T_2 V_36 )
{
struct V_34 * V_35 = F_252 ( V_293 ) -> V_35 ;
T_2 V_505 = 0 ;
unsigned V_506 ;
V_36 = F_146 ( V_36 , V_35 -> V_57 ) ;
F_11 ( & F_252 ( V_293 ) -> V_52 ) ;
V_506 = F_372 ( V_293 , V_36 ) ;
if ( V_36 )
V_505 = F_374 ( V_293 , V_36 , 0 ) ;
F_13 ( & F_252 ( V_293 ) -> V_52 ) ;
if ( V_506 > 0 )
V_505 += F_204 ( V_35 , V_506 ) ;
if ( F_232 ( V_35 ) )
return;
F_297 ( V_35 -> V_37 , L_14 ,
F_366 ( V_293 ) , V_505 , 0 ) ;
F_354 ( V_35 , & V_35 -> V_37 -> V_437 ,
V_505 ) ;
}
int F_379 ( struct V_293 * V_293 , T_2 V_32 , T_2 V_49 )
{
int V_29 ;
V_29 = F_257 ( V_293 , V_32 , V_49 ) ;
if ( V_29 < 0 )
return V_29 ;
V_29 = F_375 ( V_293 , V_49 ) ;
if ( V_29 < 0 )
F_260 ( V_293 , V_32 , V_49 ) ;
return V_29 ;
}
void F_380 ( struct V_293 * V_293 , T_2 V_32 , T_2 V_49 )
{
F_378 ( V_293 , V_49 ) ;
F_260 ( V_293 , V_32 , V_49 ) ;
}
static int F_381 ( struct V_116 * V_117 ,
struct V_34 * V_35 , T_2 V_27 ,
T_2 V_36 , int V_390 )
{
struct V_1 * V_2 = NULL ;
struct V_12 * V_13 = V_35 -> V_37 ;
T_2 V_510 = V_36 ;
T_2 V_511 ;
T_2 V_512 ;
int V_331 ;
F_11 ( & V_13 -> V_513 ) ;
V_511 = F_382 ( V_13 -> V_258 ) ;
if ( V_390 )
V_511 += V_36 ;
else
V_511 -= V_36 ;
F_383 ( V_13 -> V_258 , V_511 ) ;
F_13 ( & V_13 -> V_513 ) ;
while ( V_510 ) {
V_2 = F_73 ( V_13 , V_27 ) ;
if ( ! V_2 )
return - V_159 ;
if ( V_2 -> V_7 & ( V_332 |
V_333 |
V_334 ) )
V_331 = 2 ;
else
V_331 = 1 ;
if ( ! V_390 && V_2 -> V_3 == V_102 )
F_56 ( V_2 , 1 ) ;
V_512 = V_27 - V_2 -> V_21 . V_22 ;
F_8 ( V_512 > V_2 -> V_21 . V_33 ) ;
F_11 ( & V_2 -> V_95 -> V_52 ) ;
F_11 ( & V_2 -> V_52 ) ;
if ( F_256 ( V_35 , V_307 ) &&
V_2 -> V_299 < V_315 )
V_2 -> V_299 = V_315 ;
V_511 = F_54 ( & V_2 -> V_96 ) ;
V_36 = F_326 ( V_510 , V_2 -> V_21 . V_33 - V_512 ) ;
if ( V_390 ) {
V_511 += V_36 ;
F_384 ( & V_2 -> V_96 , V_511 ) ;
V_2 -> V_10 -= V_36 ;
V_2 -> V_95 -> V_343 -= V_36 ;
V_2 -> V_95 -> V_94 += V_36 ;
V_2 -> V_95 -> V_336 += V_36 * V_331 ;
F_13 ( & V_2 -> V_52 ) ;
F_13 ( & V_2 -> V_95 -> V_52 ) ;
} else {
V_511 -= V_36 ;
F_384 ( & V_2 -> V_96 , V_511 ) ;
V_2 -> V_9 += V_36 ;
V_2 -> V_95 -> V_342 += V_36 ;
V_2 -> V_95 -> V_94 -= V_36 ;
V_2 -> V_95 -> V_336 -= V_36 * V_331 ;
F_13 ( & V_2 -> V_52 ) ;
F_13 ( & V_2 -> V_95 -> V_52 ) ;
F_385 ( V_13 -> V_63 ,
V_27 , V_27 + V_36 - 1 ,
V_40 | V_514 ) ;
}
F_11 ( & V_117 -> V_134 -> V_322 ) ;
if ( F_177 ( & V_2 -> V_324 ) ) {
F_69 ( & V_2 -> V_324 ,
& V_117 -> V_134 -> V_314 ) ;
V_117 -> V_134 -> V_261 ++ ;
F_4 ( V_2 ) ;
}
F_13 ( & V_117 -> V_134 -> V_322 ) ;
if ( ! V_390 && V_511 == 0 ) {
F_11 ( & V_13 -> V_515 ) ;
if ( F_177 ( & V_2 -> V_516 ) ) {
F_4 ( V_2 ) ;
F_69 ( & V_2 -> V_516 ,
& V_13 -> V_517 ) ;
}
F_13 ( & V_13 -> V_515 ) ;
}
F_6 ( V_2 ) ;
V_510 -= V_36 ;
V_27 += V_36 ;
}
return 0 ;
}
static T_2 V_26 ( struct V_34 * V_35 , T_2 V_518 )
{
struct V_1 * V_2 ;
T_2 V_27 ;
F_11 ( & V_35 -> V_37 -> V_18 ) ;
V_27 = V_35 -> V_37 -> V_26 ;
F_13 ( & V_35 -> V_37 -> V_18 ) ;
if ( V_27 < ( T_2 ) - 1 )
return V_27 ;
V_2 = F_72 ( V_35 -> V_37 , V_518 ) ;
if ( ! V_2 )
return 0 ;
V_27 = V_2 -> V_21 . V_22 ;
F_6 ( V_2 ) ;
return V_27 ;
}
static int F_386 ( struct V_34 * V_35 ,
struct V_1 * V_2 ,
T_2 V_27 , T_2 V_36 , int V_10 )
{
F_11 ( & V_2 -> V_95 -> V_52 ) ;
F_11 ( & V_2 -> V_52 ) ;
V_2 -> V_9 += V_36 ;
V_2 -> V_95 -> V_342 += V_36 ;
if ( V_10 ) {
V_2 -> V_10 -= V_36 ;
V_2 -> V_95 -> V_343 -= V_36 ;
}
F_13 ( & V_2 -> V_52 ) ;
F_13 ( & V_2 -> V_95 -> V_52 ) ;
F_385 ( V_35 -> V_37 -> V_63 , V_27 ,
V_27 + V_36 - 1 , V_40 | V_514 ) ;
if ( V_10 )
F_387 ( V_35 , V_27 , V_36 ) ;
return 0 ;
}
int F_170 ( struct V_34 * V_35 ,
T_2 V_27 , T_2 V_36 , int V_10 )
{
struct V_1 * V_2 ;
V_2 = F_73 ( V_35 -> V_37 , V_27 ) ;
F_32 ( ! V_2 ) ;
F_386 ( V_35 , V_2 , V_27 , V_36 , V_10 ) ;
F_6 ( V_2 ) ;
return 0 ;
}
int F_388 ( struct V_34 * V_35 ,
T_2 V_27 , T_2 V_36 )
{
struct V_1 * V_2 ;
int V_29 ;
V_2 = F_73 ( V_35 -> V_37 , V_27 ) ;
if ( ! V_2 )
return - V_519 ;
F_56 ( V_2 , 1 ) ;
F_386 ( V_35 , V_2 , V_27 , V_36 , 0 ) ;
V_29 = F_28 ( V_2 , V_27 , V_36 ) ;
F_6 ( V_2 ) ;
return V_29 ;
}
static int F_389 ( struct V_34 * V_35 , T_2 V_32 , T_2 V_36 )
{
int V_29 ;
struct V_1 * V_14 ;
struct V_50 * V_53 ;
V_14 = F_73 ( V_35 -> V_37 , V_32 ) ;
if ( ! V_14 )
return - V_519 ;
F_56 ( V_14 , 0 ) ;
V_53 = F_25 ( V_14 ) ;
if ( ! V_53 ) {
F_32 ( ! F_1 ( V_14 ) ) ;
V_29 = F_28 ( V_14 , V_32 , V_36 ) ;
} else {
F_39 ( & V_53 -> V_84 ) ;
if ( V_32 >= V_53 -> V_90 ) {
V_29 = F_17 ( V_35 , V_32 , V_36 ) ;
} else if ( V_32 + V_36 <= V_53 -> V_90 ) {
V_29 = F_28 ( V_14 ,
V_32 , V_36 ) ;
} else {
V_36 = V_53 -> V_90 - V_32 ;
V_29 = F_28 ( V_14 ,
V_32 , V_36 ) ;
if ( V_29 )
goto V_520;
V_36 = ( V_32 + V_36 ) -
V_53 -> V_90 ;
V_32 = V_53 -> V_90 ;
V_29 = F_17 ( V_35 , V_32 , V_36 ) ;
}
V_520:
F_50 ( & V_53 -> V_84 ) ;
F_26 ( V_53 ) ;
}
F_6 ( V_14 ) ;
return V_29 ;
}
int F_390 ( struct V_34 * log ,
struct V_70 * V_521 )
{
struct V_285 * V_96 ;
struct V_72 V_21 ;
int V_522 ;
int V_43 ;
if ( ! F_81 ( log -> V_37 , V_523 ) )
return 0 ;
for ( V_43 = 0 ; V_43 < F_42 ( V_521 ) ; V_43 ++ ) {
F_44 ( V_521 , & V_21 , V_43 ) ;
if ( V_21 . type != V_290 )
continue;
V_96 = F_83 ( V_521 , V_43 , struct V_285 ) ;
V_522 = F_236 ( V_521 , V_96 ) ;
if ( V_522 == V_291 )
continue;
if ( F_237 ( V_521 , V_96 ) == 0 )
continue;
V_21 . V_22 = F_237 ( V_521 , V_96 ) ;
V_21 . V_33 = F_238 ( V_521 , V_96 ) ;
F_389 ( log , V_21 . V_22 , V_21 . V_33 ) ;
}
return 0 ;
}
static int F_391 ( struct V_1 * V_2 ,
T_2 V_36 , int V_498 , int V_524 )
{
struct V_110 * V_95 = V_2 -> V_95 ;
int V_29 = 0 ;
F_11 ( & V_95 -> V_52 ) ;
F_11 ( & V_2 -> V_52 ) ;
if ( V_498 != V_525 ) {
if ( V_2 -> V_301 ) {
V_29 = - V_184 ;
} else {
V_2 -> V_10 += V_36 ;
V_95 -> V_343 += V_36 ;
if ( V_498 == V_526 ) {
F_297 ( V_2 -> V_37 ,
L_10 , V_95 -> V_7 ,
V_36 , 0 ) ;
V_95 -> V_345 -= V_36 ;
}
if ( V_524 )
V_2 -> V_432 += V_36 ;
}
} else {
if ( V_2 -> V_301 )
V_95 -> V_344 += V_36 ;
V_2 -> V_10 -= V_36 ;
V_95 -> V_343 -= V_36 ;
if ( V_524 )
V_2 -> V_432 -= V_36 ;
}
F_13 ( & V_2 -> V_52 ) ;
F_13 ( & V_95 -> V_52 ) ;
return V_29 ;
}
void F_392 ( struct V_116 * V_117 ,
struct V_34 * V_35 )
{
struct V_12 * V_37 = V_35 -> V_37 ;
struct V_50 * V_86 ;
struct V_50 * V_53 ;
struct V_1 * V_2 ;
F_68 ( & V_37 -> V_85 ) ;
F_263 (caching_ctl, next,
&fs_info->caching_block_groups, list) {
V_2 = V_53 -> V_14 ;
if ( F_1 ( V_2 ) ) {
V_2 -> V_105 = ( T_2 ) - 1 ;
F_268 ( & V_53 -> V_98 ) ;
F_26 ( V_53 ) ;
} else {
V_2 -> V_105 = V_53 -> V_90 ;
}
}
if ( V_37 -> V_63 == & V_37 -> V_38 [ 0 ] )
V_37 -> V_63 = & V_37 -> V_38 [ 1 ] ;
else
V_37 -> V_63 = & V_37 -> V_38 [ 0 ] ;
F_70 ( & V_37 -> V_85 ) ;
F_360 ( V_37 ) ;
}
static struct V_527 *
F_393 ( struct V_34 * V_35 , struct V_110 * V_95 ,
T_2 * V_528 )
{
struct V_527 * V_29 = NULL ;
bool V_529 = F_256 ( V_35 , V_530 ) ;
* V_528 = 0 ;
if ( F_316 ( V_95 ) )
return V_29 ;
if ( V_529 )
* V_528 = 2 * 1024 * 1024 ;
if ( V_95 -> V_7 & V_55 ) {
V_29 = & V_35 -> V_37 -> V_531 ;
if ( ! V_529 )
* V_528 = 64 * 1024 ;
} else if ( ( V_95 -> V_7 & V_328 ) && V_529 ) {
V_29 = & V_35 -> V_37 -> V_532 ;
}
return V_29 ;
}
static int F_394 ( struct V_34 * V_35 , T_2 V_32 , T_2 V_31 ,
const bool V_533 )
{
struct V_12 * V_37 = V_35 -> V_37 ;
struct V_1 * V_2 = NULL ;
struct V_110 * V_95 ;
struct V_259 * V_260 = & V_37 -> V_263 ;
struct V_527 * V_534 = NULL ;
T_2 V_49 ;
T_2 V_535 = 0 ;
T_2 V_528 = 0 ;
bool V_327 ;
while ( V_32 <= V_31 ) {
V_327 = false ;
if ( ! V_2 ||
V_32 >= V_2 -> V_21 . V_22 + V_2 -> V_21 . V_33 ) {
if ( V_2 )
F_6 ( V_2 ) ;
V_535 = 0 ;
V_2 = F_73 ( V_37 , V_32 ) ;
F_32 ( ! V_2 ) ;
V_534 = F_393 ( V_35 ,
V_2 -> V_95 ,
& V_528 ) ;
V_528 <<= 1 ;
}
V_49 = V_2 -> V_21 . V_22 + V_2 -> V_21 . V_33 - V_32 ;
V_49 = F_326 ( V_49 , V_31 + 1 - V_32 ) ;
if ( V_32 < V_2 -> V_105 ) {
V_49 = F_326 ( V_49 , V_2 -> V_105 - V_32 ) ;
if ( V_533 )
F_31 ( V_2 , V_32 , V_49 ) ;
}
V_32 += V_49 ;
V_535 += V_49 ;
V_95 = V_2 -> V_95 ;
if ( V_534 && V_534 -> V_536 &&
V_535 > V_528 ) {
F_11 ( & V_534 -> V_52 ) ;
V_534 -> V_536 = 0 ;
F_13 ( & V_534 -> V_52 ) ;
}
F_11 ( & V_95 -> V_52 ) ;
F_11 ( & V_2 -> V_52 ) ;
V_2 -> V_9 -= V_49 ;
V_95 -> V_342 -= V_49 ;
V_95 -> V_346 = 0 ;
F_395 ( & V_95 -> V_337 , - V_49 ) ;
if ( V_2 -> V_301 ) {
V_95 -> V_344 += V_49 ;
V_327 = true ;
}
F_13 ( & V_2 -> V_52 ) ;
if ( ! V_327 && V_260 -> V_95 == V_95 ) {
F_11 ( & V_260 -> V_52 ) ;
if ( ! V_260 -> V_115 ) {
V_49 = F_326 ( V_49 , V_260 -> V_61 -
V_260 -> V_10 ) ;
V_260 -> V_10 += V_49 ;
V_95 -> V_345 += V_49 ;
if ( V_260 -> V_10 >= V_260 -> V_61 )
V_260 -> V_115 = 1 ;
}
F_13 ( & V_260 -> V_52 ) ;
}
F_13 ( & V_95 -> V_52 ) ;
}
if ( V_2 )
F_6 ( V_2 ) ;
return 0 ;
}
int F_396 ( struct V_116 * V_117 ,
struct V_34 * V_35 )
{
struct V_12 * V_37 = V_35 -> V_37 ;
struct V_1 * V_14 , * V_311 ;
struct V_111 * V_537 ;
struct V_538 * V_539 ;
T_2 V_32 ;
T_2 V_31 ;
int V_29 ;
if ( V_37 -> V_63 == & V_37 -> V_38 [ 0 ] )
V_539 = & V_37 -> V_38 [ 1 ] ;
else
V_539 = & V_37 -> V_38 [ 0 ] ;
while ( ! V_117 -> V_225 ) {
F_39 ( & V_37 -> V_540 ) ;
V_29 = F_30 ( V_539 , 0 , & V_32 , & V_31 ,
V_64 , NULL ) ;
if ( V_29 ) {
F_50 ( & V_37 -> V_540 ) ;
break;
}
if ( F_256 ( V_35 , V_541 ) )
V_29 = F_150 ( V_35 , V_32 ,
V_31 + 1 - V_32 , NULL ) ;
F_397 ( V_539 , V_32 , V_31 , V_40 ) ;
F_394 ( V_35 , V_32 , V_31 , true ) ;
F_50 ( & V_37 -> V_540 ) ;
F_51 () ;
}
V_537 = & V_117 -> V_134 -> V_537 ;
F_263 (block_group, tmp, deleted_bgs, bg_list) {
T_2 V_542 = 0 ;
V_29 = - V_543 ;
if ( ! V_117 -> V_225 )
V_29 = F_150 ( V_35 ,
V_14 -> V_21 . V_22 ,
V_14 -> V_21 . V_33 ,
& V_542 ) ;
F_268 ( & V_14 -> V_516 ) ;
F_398 ( V_14 ) ;
F_6 ( V_14 ) ;
if ( V_29 ) {
const char * V_544 = F_399 ( V_29 ) ;
F_400 ( V_37 ,
L_15 ,
V_29 , V_544 ) ;
}
}
return 0 ;
}
static void F_401 ( struct V_12 * V_37 , T_2 V_36 ,
T_2 V_140 , T_2 V_152 )
{
struct V_110 * V_95 ;
T_2 V_7 ;
if ( V_140 < V_149 ) {
if ( V_152 == V_545 )
V_7 = V_329 ;
else
V_7 = V_55 ;
} else {
V_7 = V_328 ;
}
V_95 = F_74 ( V_37 , V_7 ) ;
F_32 ( ! V_95 ) ;
F_395 ( & V_95 -> V_337 , V_36 ) ;
}
static int F_162 ( struct V_116 * V_117 ,
struct V_34 * V_35 ,
struct V_216 * V_135 , T_2 V_17 ,
T_2 V_152 , T_2 V_546 ,
T_2 V_547 , int V_165 ,
struct V_186 * V_136 )
{
struct V_72 V_21 ;
struct V_68 * V_69 ;
struct V_12 * V_13 = V_35 -> V_37 ;
struct V_34 * V_67 = V_13 -> V_67 ;
struct V_70 * V_71 ;
struct V_123 * V_124 ;
struct V_169 * V_170 ;
int V_29 ;
int V_190 ;
int V_548 = 0 ;
int V_549 = 0 ;
int V_550 = 1 ;
T_3 V_125 ;
T_2 V_119 ;
T_2 V_27 = V_135 -> V_27 ;
T_2 V_36 = V_135 -> V_36 ;
int V_166 = 0 ;
bool V_179 = F_81 ( V_35 -> V_37 ,
V_128 ) ;
V_69 = F_35 () ;
if ( ! V_69 )
return - V_76 ;
V_69 -> V_81 = 1 ;
V_69 -> V_217 = 1 ;
V_190 = V_546 >= V_149 ;
F_32 ( ! V_190 && V_165 != 1 ) ;
if ( V_190 )
V_179 = 0 ;
V_29 = F_139 ( V_117 , V_67 , V_69 , & V_170 ,
V_27 , V_36 , V_17 ,
V_152 , V_546 ,
V_547 ) ;
if ( V_29 == 0 ) {
V_548 = V_69 -> V_89 [ 0 ] ;
while ( V_548 >= 0 ) {
F_44 ( V_69 -> V_88 [ 0 ] , & V_21 ,
V_548 ) ;
if ( V_21 . V_22 != V_27 )
break;
if ( V_21 . type == V_82 &&
V_21 . V_33 == V_36 ) {
V_549 = 1 ;
break;
}
if ( V_21 . type == V_91 &&
V_21 . V_33 == V_546 ) {
V_549 = 1 ;
break;
}
if ( V_69 -> V_89 [ 0 ] - V_548 > 5 )
break;
V_548 -- ;
}
#ifdef F_86
V_125 = F_82 ( V_69 -> V_88 [ 0 ] , V_548 ) ;
if ( V_549 && V_125 < sizeof( * V_124 ) )
V_549 = 0 ;
#endif
if ( ! V_549 ) {
F_32 ( V_170 ) ;
V_29 = F_144 ( V_117 , V_67 , V_69 ,
NULL , V_165 ,
V_190 , & V_166 ) ;
if ( V_29 ) {
F_157 ( V_117 , V_67 , V_29 ) ;
goto V_78;
}
F_48 ( V_69 ) ;
V_69 -> V_217 = 1 ;
V_21 . V_22 = V_27 ;
V_21 . type = V_82 ;
V_21 . V_33 = V_36 ;
if ( ! V_190 && V_179 ) {
V_21 . type = V_91 ;
V_21 . V_33 = V_546 ;
}
V_29 = F_41 ( V_117 , V_67 ,
& V_21 , V_69 , - 1 , 1 ) ;
if ( V_29 > 0 && V_179 && V_69 -> V_89 [ 0 ] ) {
V_69 -> V_89 [ 0 ] -- ;
F_44 ( V_69 -> V_88 [ 0 ] , & V_21 ,
V_69 -> V_89 [ 0 ] ) ;
if ( V_21 . V_22 == V_27 &&
V_21 . type == V_82 &&
V_21 . V_33 == V_36 )
V_29 = 0 ;
}
if ( V_29 > 0 && V_179 ) {
V_179 = false ;
V_21 . V_22 = V_27 ;
V_21 . type = V_82 ;
V_21 . V_33 = V_36 ;
F_48 ( V_69 ) ;
V_29 = F_41 ( V_117 , V_67 ,
& V_21 , V_69 , - 1 , 1 ) ;
}
if ( V_29 ) {
F_402 ( V_13 , L_16 ,
V_29 , V_27 ) ;
if ( V_29 > 0 )
F_403 ( V_67 ,
V_69 -> V_88 [ 0 ] ) ;
}
if ( V_29 < 0 ) {
F_157 ( V_117 , V_67 , V_29 ) ;
goto V_78;
}
V_548 = V_69 -> V_89 [ 0 ] ;
}
} else if ( F_8 ( V_29 == - V_159 ) ) {
F_403 ( V_67 , V_69 -> V_88 [ 0 ] ) ;
F_402 ( V_13 ,
L_17 ,
V_27 , V_17 , V_152 , V_546 ,
V_547 ) ;
F_157 ( V_117 , V_67 , V_29 ) ;
goto V_78;
} else {
F_157 ( V_117 , V_67 , V_29 ) ;
goto V_78;
}
V_71 = V_69 -> V_88 [ 0 ] ;
V_125 = F_82 ( V_71 , V_548 ) ;
#ifdef F_86
if ( V_125 < sizeof( * V_124 ) ) {
F_32 ( V_549 || V_548 != V_69 -> V_89 [ 0 ] ) ;
V_29 = F_92 ( V_117 , V_67 , V_69 ,
V_546 , 0 ) ;
if ( V_29 < 0 ) {
F_157 ( V_117 , V_67 , V_29 ) ;
goto V_78;
}
F_48 ( V_69 ) ;
V_69 -> V_217 = 1 ;
V_21 . V_22 = V_27 ;
V_21 . type = V_82 ;
V_21 . V_33 = V_36 ;
V_29 = F_41 ( V_117 , V_67 , & V_21 , V_69 ,
- 1 , 1 ) ;
if ( V_29 ) {
F_402 ( V_13 , L_16 ,
V_29 , V_27 ) ;
F_403 ( V_67 , V_69 -> V_88 [ 0 ] ) ;
}
if ( V_29 < 0 ) {
F_157 ( V_117 , V_67 , V_29 ) ;
goto V_78;
}
V_548 = V_69 -> V_89 [ 0 ] ;
V_71 = V_69 -> V_88 [ 0 ] ;
V_125 = F_82 ( V_71 , V_548 ) ;
}
#endif
F_32 ( V_125 < sizeof( * V_124 ) ) ;
V_124 = F_83 ( V_71 , V_548 ,
struct V_123 ) ;
if ( V_546 < V_149 &&
V_21 . type == V_82 ) {
struct V_144 * V_145 ;
F_32 ( V_125 < sizeof( * V_124 ) + sizeof( * V_145 ) ) ;
V_145 = (struct V_144 * ) ( V_124 + 1 ) ;
F_8 ( V_546 != F_404 ( V_71 , V_145 ) ) ;
}
V_119 = F_84 ( V_71 , V_124 ) ;
if ( V_119 < V_165 ) {
F_402 ( V_13 , L_18
L_19 , V_165 , V_119 , V_27 ) ;
V_29 = - V_519 ;
F_157 ( V_117 , V_67 , V_29 ) ;
goto V_78;
}
V_119 -= V_165 ;
if ( V_119 > 0 ) {
if ( V_136 )
F_135 ( V_136 , V_71 , V_124 ) ;
if ( V_170 ) {
F_32 ( ! V_549 ) ;
} else {
F_95 ( V_71 , V_124 , V_119 ) ;
F_100 ( V_71 ) ;
}
if ( V_549 ) {
V_29 = F_144 ( V_117 , V_67 , V_69 ,
V_170 , V_165 ,
V_190 , & V_166 ) ;
if ( V_29 ) {
F_157 ( V_117 , V_67 , V_29 ) ;
goto V_78;
}
}
F_401 ( V_35 -> V_37 , - V_36 , V_546 ,
V_152 ) ;
} else {
if ( V_549 ) {
F_32 ( V_190 && V_165 !=
F_123 ( V_69 , V_170 ) ) ;
if ( V_170 ) {
F_32 ( V_69 -> V_89 [ 0 ] != V_548 ) ;
} else {
F_32 ( V_69 -> V_89 [ 0 ] != V_548 + 1 ) ;
V_69 -> V_89 [ 0 ] = V_548 ;
V_550 = 2 ;
}
}
V_166 = 1 ;
V_29 = F_405 ( V_117 , V_67 , V_69 , V_69 -> V_89 [ 0 ] ,
V_550 ) ;
if ( V_29 ) {
F_157 ( V_117 , V_67 , V_29 ) ;
goto V_78;
}
F_48 ( V_69 ) ;
if ( V_190 ) {
V_29 = F_174 ( V_117 , V_35 , V_27 , V_36 ) ;
if ( V_29 ) {
F_157 ( V_117 , V_67 , V_29 ) ;
goto V_78;
}
}
V_29 = F_381 ( V_117 , V_35 , V_27 , V_36 , 0 ) ;
if ( V_29 ) {
F_157 ( V_117 , V_67 , V_29 ) ;
goto V_78;
}
}
F_48 ( V_69 ) ;
V_78:
F_55 ( V_69 ) ;
return V_29 ;
}
static T_1 int F_406 ( struct V_116 * V_117 ,
struct V_34 * V_35 , T_2 V_27 )
{
struct V_120 * V_112 ;
struct V_121 * V_122 ;
int V_29 = 0 ;
V_122 = & V_117 -> V_134 -> V_122 ;
F_11 ( & V_122 -> V_52 ) ;
V_112 = F_89 ( V_117 , V_27 ) ;
if ( ! V_112 )
goto V_551;
F_11 ( & V_112 -> V_52 ) ;
if ( ! F_177 ( & V_112 -> V_229 ) )
goto V_78;
if ( V_112 -> V_136 ) {
if ( ! V_112 -> V_232 )
goto V_78;
F_187 ( V_112 -> V_136 ) ;
V_112 -> V_136 = NULL ;
}
if ( ! F_90 ( & V_112 -> V_84 ) )
goto V_78;
V_112 -> V_135 . V_236 = 0 ;
F_189 ( & V_112 -> V_238 , & V_122 -> V_239 ) ;
F_191 ( & V_122 -> V_240 ) ;
V_122 -> V_237 -- ;
if ( V_112 -> V_234 == 0 )
V_122 -> V_235 -- ;
V_112 -> V_234 = 0 ;
F_13 ( & V_112 -> V_52 ) ;
F_13 ( & V_122 -> V_52 ) ;
F_32 ( V_112 -> V_136 ) ;
if ( V_112 -> V_232 )
V_29 = 1 ;
F_50 ( & V_112 -> V_84 ) ;
F_91 ( & V_112 -> V_135 ) ;
return V_29 ;
V_78:
F_13 ( & V_112 -> V_52 ) ;
V_551:
F_13 ( & V_122 -> V_52 ) ;
return 0 ;
}
void F_407 ( struct V_116 * V_117 ,
struct V_34 * V_35 ,
struct V_70 * V_282 ,
T_2 V_17 , int V_166 )
{
int V_552 = 1 ;
int V_29 ;
if ( V_35 -> V_278 . V_22 != V_214 ) {
V_29 = F_154 ( V_35 -> V_37 , V_117 ,
V_282 -> V_32 , V_282 -> V_49 ,
V_17 , V_35 -> V_278 . V_22 ,
F_234 ( V_282 ) ,
V_223 , NULL ) ;
F_32 ( V_29 ) ;
}
if ( ! V_166 )
return;
if ( F_408 ( V_282 ) == V_117 -> V_303 ) {
struct V_1 * V_2 ;
if ( V_35 -> V_278 . V_22 != V_214 ) {
V_29 = F_406 ( V_117 , V_35 , V_282 -> V_32 ) ;
if ( ! V_29 )
goto V_78;
}
V_2 = F_73 ( V_35 -> V_37 , V_282 -> V_32 ) ;
if ( F_409 ( V_282 , V_553 ) ) {
F_386 ( V_35 , V_2 , V_282 -> V_32 , V_282 -> V_49 , 1 ) ;
F_6 ( V_2 ) ;
goto V_78;
}
F_8 ( F_235 ( V_554 , & V_282 -> V_555 ) ) ;
F_31 ( V_2 , V_282 -> V_32 , V_282 -> V_49 ) ;
F_391 ( V_2 , V_282 -> V_49 , V_525 , 0 ) ;
F_6 ( V_2 ) ;
F_387 ( V_35 , V_282 -> V_32 , V_282 -> V_49 ) ;
V_552 = 0 ;
}
V_78:
if ( V_552 )
F_401 ( V_35 -> V_37 , V_282 -> V_49 ,
F_234 ( V_282 ) ,
V_35 -> V_278 . V_22 ) ;
F_410 ( V_556 , & V_282 -> V_555 ) ;
}
int V_289 ( struct V_116 * V_117 , struct V_34 * V_35 ,
T_2 V_27 , T_2 V_36 , T_2 V_17 , T_2 V_152 ,
T_2 V_140 , T_2 V_33 )
{
int V_29 ;
struct V_12 * V_37 = V_35 -> V_37 ;
if ( F_232 ( V_35 ) )
return 0 ;
F_401 ( V_35 -> V_37 , V_36 , V_140 , V_152 ) ;
if ( V_152 == V_214 ) {
F_8 ( V_140 >= V_149 ) ;
F_170 ( V_35 , V_27 , V_36 , 1 ) ;
V_29 = 0 ;
} else if ( V_140 < V_149 ) {
V_29 = F_154 ( V_37 , V_117 , V_27 ,
V_36 ,
V_17 , V_152 , ( int ) V_140 ,
V_223 , NULL ) ;
} else {
V_29 = F_155 ( V_37 , V_117 , V_27 ,
V_36 ,
V_17 , V_152 , V_140 ,
V_33 , 0 ,
V_223 , NULL ) ;
}
return V_29 ;
}
static T_1 void
F_411 ( struct V_1 * V_2 ,
T_2 V_36 )
{
struct V_50 * V_53 ;
V_53 = F_25 ( V_2 ) ;
if ( ! V_53 )
return;
F_327 ( V_53 -> V_93 , F_1 ( V_2 ) ||
( V_2 -> V_11 -> V_557 >= V_36 ) ) ;
F_26 ( V_53 ) ;
}
static T_1 int
F_412 ( struct V_1 * V_2 )
{
struct V_50 * V_53 ;
int V_29 = 0 ;
V_53 = F_25 ( V_2 ) ;
if ( ! V_53 )
return ( V_2 -> V_3 == V_5 ) ? - V_181 : 0 ;
F_327 ( V_53 -> V_93 , F_1 ( V_2 ) ) ;
if ( V_2 -> V_3 == V_5 )
V_29 = - V_181 ;
F_26 ( V_53 ) ;
return V_29 ;
}
int F_413 ( T_2 V_7 )
{
if ( V_7 & V_334 )
return V_558 ;
else if ( V_7 & V_333 )
return V_559 ;
else if ( V_7 & V_332 )
return V_560 ;
else if ( V_7 & V_381 )
return V_561 ;
else if ( V_7 & V_380 )
return V_562 ;
else if ( V_7 & V_379 )
return V_563 ;
return V_564 ;
}
int F_414 ( struct V_1 * V_2 )
{
return F_413 ( V_2 -> V_7 ) ;
}
static const char * F_415 ( enum V_565 type )
{
if ( type >= V_339 )
return NULL ;
return V_566 [ type ] ;
}
static inline void
F_416 ( struct V_1 * V_2 ,
int V_524 )
{
if ( V_524 )
F_40 ( & V_2 -> V_567 ) ;
}
static inline void
F_417 ( struct V_1 * V_2 ,
int V_524 )
{
F_4 ( V_2 ) ;
if ( V_524 )
F_40 ( & V_2 -> V_567 ) ;
}
static struct V_1 *
F_418 ( struct V_1 * V_14 ,
struct V_527 * V_534 ,
int V_524 )
{
struct V_1 * V_568 ;
bool V_569 = false ;
V_83:
F_11 ( & V_534 -> V_570 ) ;
if ( V_569 ) {
if ( V_568 == V_534 -> V_14 )
return V_568 ;
F_49 ( & V_568 -> V_567 ) ;
F_6 ( V_568 ) ;
}
V_568 = V_534 -> V_14 ;
if ( ! V_568 )
return NULL ;
if ( V_568 == V_14 )
return V_568 ;
F_4 ( V_568 ) ;
if ( ! V_524 )
return V_568 ;
if ( F_320 ( & V_568 -> V_567 ) )
return V_568 ;
F_13 ( & V_534 -> V_570 ) ;
F_40 ( & V_568 -> V_567 ) ;
V_569 = true ;
goto V_83;
}
static inline void
F_419 ( struct V_1 * V_2 ,
int V_524 )
{
if ( V_524 )
F_49 ( & V_2 -> V_567 ) ;
F_6 ( V_2 ) ;
}
static T_1 int F_420 ( struct V_34 * V_571 ,
T_2 V_36 , T_2 V_572 ,
T_2 V_573 , struct V_72 * V_220 ,
T_2 V_7 , int V_524 )
{
int V_29 = 0 ;
struct V_34 * V_35 = V_571 -> V_37 -> V_67 ;
struct V_527 * V_574 = NULL ;
struct V_1 * V_14 = NULL ;
T_2 V_518 = 0 ;
T_2 V_346 = 0 ;
T_2 V_528 = 0 ;
struct V_110 * V_95 ;
int V_575 = 0 ;
int V_576 = F_413 ( V_7 ) ;
int V_577 = ( V_7 & V_328 ) ?
V_578 : V_526 ;
bool V_579 = false ;
bool V_580 = false ;
bool V_581 = true ;
bool V_582 = false ;
bool V_583 = false ;
bool V_584 = false ;
F_8 ( V_36 < V_35 -> V_57 ) ;
V_220 -> type = V_82 ;
V_220 -> V_22 = 0 ;
V_220 -> V_33 = 0 ;
F_421 ( V_571 , V_36 , V_572 , V_7 ) ;
V_95 = F_74 ( V_35 -> V_37 , V_7 ) ;
if ( ! V_95 ) {
F_402 ( V_35 -> V_37 , L_20 , V_7 ) ;
return - V_309 ;
}
if ( F_343 ( V_95 -> V_346 ) ) {
F_11 ( & V_95 -> V_52 ) ;
if ( V_95 -> V_346 &&
V_36 > V_95 -> V_346 ) {
V_220 -> V_33 = V_95 -> V_346 ;
F_13 ( & V_95 -> V_52 ) ;
return - V_309 ;
} else if ( V_95 -> V_346 ) {
V_581 = false ;
}
F_13 ( & V_95 -> V_52 ) ;
}
V_574 = F_393 ( V_571 , V_95 , & V_528 ) ;
if ( V_574 ) {
F_11 ( & V_574 -> V_52 ) ;
if ( V_574 -> V_14 )
V_573 = V_574 -> V_585 ;
if ( V_574 -> V_536 ) {
V_573 = V_574 -> V_585 ;
V_581 = false ;
}
F_13 ( & V_574 -> V_52 ) ;
}
V_518 = F_422 ( V_518 , V_26 ( V_35 , 0 ) ) ;
V_518 = F_422 ( V_518 , V_573 ) ;
if ( V_518 == V_573 ) {
V_14 = F_73 ( V_35 -> V_37 ,
V_518 ) ;
if ( V_14 && F_3 ( V_14 , V_7 ) &&
V_14 -> V_3 != V_102 ) {
F_40 ( & V_95 -> V_341 ) ;
if ( F_177 ( & V_14 -> V_98 ) ||
V_14 -> V_301 ) {
F_6 ( V_14 ) ;
F_49 ( & V_95 -> V_341 ) ;
} else {
V_576 = F_414 ( V_14 ) ;
F_416 ( V_14 , V_524 ) ;
goto V_586;
}
} else if ( V_14 ) {
F_6 ( V_14 ) ;
}
}
V_587:
V_582 = false ;
if ( V_576 == 0 || V_576 == F_413 ( V_7 ) )
V_584 = true ;
F_40 ( & V_95 -> V_341 ) ;
F_178 (block_group, &space_info->block_groups[index],
list) {
T_2 V_33 ;
int V_3 ;
F_417 ( V_14 , V_524 ) ;
V_518 = V_14 -> V_21 . V_22 ;
if ( ! F_3 ( V_14 , V_7 ) ) {
T_2 V_588 = V_332 |
V_333 |
V_380 |
V_379 |
V_334 ;
if ( ( V_7 & V_588 ) && ! ( V_14 -> V_7 & V_588 ) )
goto V_575;
}
V_586:
V_3 = F_1 ( V_14 ) ;
if ( F_343 ( ! V_3 ) ) {
V_582 = true ;
V_29 = F_56 ( V_14 , 0 ) ;
F_32 ( V_29 < 0 ) ;
V_29 = 0 ;
}
if ( F_343 ( V_14 -> V_3 == V_5 ) )
goto V_575;
if ( F_343 ( V_14 -> V_301 ) )
goto V_575;
if ( V_574 && V_581 ) {
struct V_1 * V_589 ;
unsigned long V_590 ;
V_589 = F_418 ( V_14 ,
V_574 ,
V_524 ) ;
if ( ! V_589 )
goto V_591;
if ( V_589 != V_14 &&
( V_589 -> V_301 ||
! F_3 ( V_589 , V_7 ) ) )
goto V_592;
V_33 = F_423 ( V_589 ,
V_574 ,
V_36 ,
V_589 -> V_21 . V_22 ,
& V_346 ) ;
if ( V_33 ) {
F_13 ( & V_574 -> V_570 ) ;
F_424 ( V_35 ,
V_589 ,
V_518 , V_36 ) ;
if ( V_589 != V_14 ) {
F_419 ( V_14 ,
V_524 ) ;
V_14 = V_589 ;
}
goto V_593;
}
F_8 ( V_574 -> V_14 != V_589 ) ;
V_592:
if ( V_575 >= V_594 &&
V_589 != V_14 ) {
F_13 ( & V_574 -> V_570 ) ;
F_419 ( V_589 ,
V_524 ) ;
goto V_595;
}
F_425 ( NULL , V_574 ) ;
if ( V_589 != V_14 )
F_419 ( V_589 ,
V_524 ) ;
V_591:
if ( V_575 >= V_594 ) {
F_13 ( & V_574 -> V_570 ) ;
goto V_595;
}
V_590 = F_36 (unsigned long,
empty_cluster + empty_size,
block_group->full_stripe_len) ;
V_29 = F_426 ( V_35 , V_14 ,
V_574 , V_518 ,
V_36 ,
V_590 ) ;
if ( V_29 == 0 ) {
V_33 = F_423 ( V_14 ,
V_574 ,
V_36 ,
V_518 ,
& V_346 ) ;
if ( V_33 ) {
F_13 ( & V_574 -> V_570 ) ;
F_424 ( V_35 ,
V_14 , V_518 ,
V_36 ) ;
goto V_593;
}
} else if ( ! V_3 && V_575 > V_596
&& ! V_579 ) {
F_13 ( & V_574 -> V_570 ) ;
V_579 = true ;
F_411 ( V_14 ,
V_36 + V_528 + V_572 ) ;
goto V_586;
}
F_425 ( NULL , V_574 ) ;
F_13 ( & V_574 -> V_570 ) ;
goto V_575;
}
V_595:
if ( F_343 ( V_574 ) ) {
F_11 ( & V_574 -> V_52 ) ;
V_574 -> V_536 = 1 ;
F_13 ( & V_574 -> V_52 ) ;
}
F_11 ( & V_14 -> V_11 -> V_597 ) ;
if ( V_3 &&
V_14 -> V_11 -> V_557 <
V_36 + V_528 + V_572 ) {
if ( V_14 -> V_11 -> V_557 >
V_346 )
V_346 =
V_14 -> V_11 -> V_557 ;
F_13 ( & V_14 -> V_11 -> V_597 ) ;
goto V_575;
}
F_13 ( & V_14 -> V_11 -> V_597 ) ;
V_33 = F_427 ( V_14 , V_518 ,
V_36 , V_572 ,
& V_346 ) ;
if ( ! V_33 && ! V_580 && ! V_3 &&
V_575 > V_596 ) {
F_411 ( V_14 ,
V_36 + V_572 ) ;
V_580 = true ;
goto V_586;
} else if ( ! V_33 ) {
goto V_575;
}
V_593:
V_518 = F_146 ( V_33 , V_35 -> V_598 ) ;
if ( V_518 + V_36 >
V_14 -> V_21 . V_22 + V_14 -> V_21 . V_33 ) {
F_31 ( V_14 , V_33 , V_36 ) ;
goto V_575;
}
if ( V_33 < V_518 )
F_31 ( V_14 , V_33 ,
V_518 - V_33 ) ;
F_32 ( V_33 > V_518 ) ;
V_29 = F_391 ( V_14 , V_36 ,
V_577 , V_524 ) ;
if ( V_29 == - V_184 ) {
F_31 ( V_14 , V_33 , V_36 ) ;
goto V_575;
}
V_220 -> V_22 = V_518 ;
V_220 -> V_33 = V_36 ;
F_428 ( V_571 , V_14 ,
V_518 , V_36 ) ;
F_419 ( V_14 , V_524 ) ;
break;
V_575:
V_579 = false ;
V_580 = false ;
F_32 ( V_576 != F_414 ( V_14 ) ) ;
F_419 ( V_14 , V_524 ) ;
}
F_49 ( & V_95 -> V_341 ) ;
if ( ( V_575 == V_596 ) && V_582
&& ! V_583 )
V_583 = true ;
if ( ! V_220 -> V_22 && V_575 >= V_599 && V_582 )
goto V_587;
if ( ! V_220 -> V_22 && ++ V_576 < V_339 )
goto V_587;
if ( ! V_220 -> V_22 && V_575 < V_594 ) {
V_576 = 0 ;
if ( V_575 == V_596 ) {
if ( V_583 || ! V_584 )
V_575 = V_599 ;
else
V_575 = V_600 ;
} else {
V_575 ++ ;
}
if ( V_575 == V_600 ) {
struct V_116 * V_117 ;
int V_601 = 0 ;
V_117 = V_388 -> V_389 ;
if ( V_117 )
V_601 = 1 ;
else
V_117 = F_208 ( V_35 ) ;
if ( F_209 ( V_117 ) ) {
V_29 = F_210 ( V_117 ) ;
goto V_78;
}
V_29 = F_293 ( V_117 , V_35 , V_7 ,
V_392 ) ;
if ( V_29 == - V_309 )
V_575 = V_594 ;
if ( V_29 < 0 && V_29 != - V_309 )
F_157 ( V_117 ,
V_35 , V_29 ) ;
else
V_29 = 0 ;
if ( ! V_601 )
F_212 ( V_117 , V_35 ) ;
if ( V_29 )
goto V_78;
}
if ( V_575 == V_594 ) {
if ( V_572 == 0 &&
V_528 == 0 ) {
V_29 = - V_309 ;
goto V_78;
}
V_572 = 0 ;
V_528 = 0 ;
}
goto V_587;
} else if ( ! V_220 -> V_22 ) {
V_29 = - V_309 ;
} else if ( V_220 -> V_22 ) {
if ( ! V_581 && V_574 ) {
F_11 ( & V_574 -> V_52 ) ;
V_574 -> V_585 = V_220 -> V_22 ;
F_13 ( & V_574 -> V_52 ) ;
}
V_29 = 0 ;
}
V_78:
if ( V_29 == - V_309 ) {
F_11 ( & V_95 -> V_52 ) ;
V_95 -> V_346 = V_346 ;
F_13 ( & V_95 -> V_52 ) ;
V_220 -> V_33 = V_346 ;
}
return V_29 ;
}
static void F_313 ( struct V_110 * V_13 , T_2 V_209 ,
int V_602 )
{
struct V_1 * V_2 ;
int V_576 = 0 ;
F_11 ( & V_13 -> V_52 ) ;
F_429 ( V_603 L_21 ,
V_13 -> V_7 ,
V_13 -> V_330 - V_13 -> V_94 - V_13 -> V_342 -
V_13 -> V_343 - V_13 -> V_344 ,
( V_13 -> V_115 ) ? L_22 : L_23 ) ;
F_429 ( V_603 L_24
L_25 ,
V_13 -> V_330 , V_13 -> V_94 , V_13 -> V_342 ,
V_13 -> V_343 , V_13 -> V_345 ,
V_13 -> V_344 ) ;
F_13 ( & V_13 -> V_52 ) ;
if ( ! V_602 )
return;
F_40 ( & V_13 -> V_341 ) ;
V_83:
F_178 (cache, &info->block_groups[index], list) {
F_11 ( & V_2 -> V_52 ) ;
F_429 ( V_603 L_26
L_27
L_28 ,
V_2 -> V_21 . V_22 , V_2 -> V_21 . V_33 ,
F_54 ( & V_2 -> V_96 ) , V_2 -> V_9 ,
V_2 -> V_10 , V_2 -> V_301 ? L_29 : L_22 ) ;
F_430 ( V_2 , V_209 ) ;
F_13 ( & V_2 -> V_52 ) ;
}
if ( ++ V_576 < V_339 )
goto V_83;
F_49 ( & V_13 -> V_341 ) ;
}
int F_431 ( struct V_34 * V_35 ,
T_2 V_36 , T_2 V_604 ,
T_2 V_572 , T_2 V_573 ,
struct V_72 * V_220 , int V_190 , int V_524 )
{
bool V_605 = V_36 == V_604 ;
T_2 V_7 ;
int V_29 ;
V_7 = F_290 ( V_35 , V_190 ) ;
V_83:
F_8 ( V_36 < V_35 -> V_57 ) ;
V_29 = F_420 ( V_35 , V_36 , V_572 , V_573 , V_220 ,
V_7 , V_524 ) ;
if ( V_29 == - V_309 ) {
if ( ! V_605 && V_220 -> V_33 ) {
V_36 = F_326 ( V_36 >> 1 , V_220 -> V_33 ) ;
V_36 = F_147 ( V_36 , V_35 -> V_57 ) ;
V_36 = F_422 ( V_36 , V_604 ) ;
if ( V_36 == V_604 )
V_605 = true ;
goto V_83;
} else if ( F_256 ( V_35 , V_407 ) ) {
struct V_110 * V_398 ;
V_398 = F_74 ( V_35 -> V_37 , V_7 ) ;
F_402 ( V_35 -> V_37 , L_30 ,
V_7 , V_36 ) ;
if ( V_398 )
F_313 ( V_398 , V_36 , 1 ) ;
}
}
return V_29 ;
}
static int F_432 ( struct V_34 * V_35 ,
T_2 V_32 , T_2 V_49 ,
int V_552 , int V_524 )
{
struct V_1 * V_2 ;
int V_29 = 0 ;
V_2 = F_73 ( V_35 -> V_37 , V_32 ) ;
if ( ! V_2 ) {
F_402 ( V_35 -> V_37 , L_31 ,
V_32 ) ;
return - V_309 ;
}
if ( V_552 )
F_386 ( V_35 , V_2 , V_32 , V_49 , 1 ) ;
else {
if ( F_256 ( V_35 , V_541 ) )
V_29 = F_150 ( V_35 , V_32 , V_49 , NULL ) ;
F_31 ( V_2 , V_32 , V_49 ) ;
F_391 ( V_2 , V_49 , V_525 , V_524 ) ;
}
F_6 ( V_2 ) ;
F_387 ( V_35 , V_32 , V_49 ) ;
return V_29 ;
}
int F_433 ( struct V_34 * V_35 ,
T_2 V_32 , T_2 V_49 , int V_524 )
{
return F_432 ( V_35 , V_32 , V_49 , 0 , V_524 ) ;
}
int F_434 ( struct V_34 * V_35 ,
T_2 V_32 , T_2 V_49 )
{
return F_432 ( V_35 , V_32 , V_49 , 1 , 0 ) ;
}
static int F_161 ( struct V_116 * V_117 ,
struct V_34 * V_35 ,
T_2 V_17 , T_2 V_152 ,
T_2 V_7 , T_2 V_140 , T_2 V_33 ,
struct V_72 * V_220 , int V_139 )
{
int V_29 ;
struct V_12 * V_37 = V_35 -> V_37 ;
struct V_123 * V_606 ;
struct V_169 * V_170 ;
struct V_68 * V_69 ;
struct V_70 * V_71 ;
int type ;
T_3 V_61 ;
if ( V_17 > 0 )
type = V_160 ;
else
type = V_161 ;
V_61 = sizeof( * V_606 ) + F_130 ( type ) ;
V_69 = F_35 () ;
if ( ! V_69 )
return - V_76 ;
V_69 -> V_217 = 1 ;
V_29 = F_111 ( V_117 , V_37 -> V_67 , V_69 ,
V_220 , V_61 ) ;
if ( V_29 ) {
F_55 ( V_69 ) ;
return V_29 ;
}
V_71 = V_69 -> V_88 [ 0 ] ;
V_606 = F_83 ( V_71 , V_69 -> V_89 [ 0 ] ,
struct V_123 ) ;
F_95 ( V_71 , V_606 , V_139 ) ;
F_96 ( V_71 , V_606 , V_117 -> V_303 ) ;
F_97 ( V_71 , V_606 ,
V_7 | V_151 ) ;
V_170 = (struct V_169 * ) ( V_606 + 1 ) ;
F_137 ( V_71 , V_170 , type ) ;
if ( V_17 > 0 ) {
struct V_164 * V_157 ;
V_157 = (struct V_164 * ) ( V_170 + 1 ) ;
F_138 ( V_71 , V_170 , V_17 ) ;
F_112 ( V_71 , V_157 , V_139 ) ;
} else {
struct V_156 * V_157 ;
V_157 = (struct V_156 * ) ( & V_170 -> V_33 ) ;
F_114 ( V_71 , V_157 , V_152 ) ;
F_115 ( V_71 , V_157 , V_140 ) ;
F_116 ( V_71 , V_157 , V_33 ) ;
F_117 ( V_71 , V_157 , V_139 ) ;
}
F_100 ( V_69 -> V_88 [ 0 ] ) ;
F_55 ( V_69 ) ;
V_29 = F_381 ( V_117 , V_35 , V_220 -> V_22 , V_220 -> V_33 , 1 ) ;
if ( V_29 ) {
F_402 ( V_37 , L_32 ,
V_220 -> V_22 , V_220 -> V_33 ) ;
F_88 () ;
}
F_435 ( V_35 , V_220 -> V_22 , V_220 -> V_33 ) ;
return V_29 ;
}
static int F_168 ( struct V_116 * V_117 ,
struct V_34 * V_35 ,
T_2 V_17 , T_2 V_152 ,
T_2 V_7 , struct V_607 * V_21 ,
int V_173 , struct V_72 * V_220 )
{
int V_29 ;
struct V_12 * V_37 = V_35 -> V_37 ;
struct V_123 * V_606 ;
struct V_144 * V_608 ;
struct V_169 * V_170 ;
struct V_68 * V_69 ;
struct V_70 * V_71 ;
T_3 V_61 = sizeof( * V_606 ) + sizeof( * V_170 ) ;
T_2 V_36 = V_220 -> V_33 ;
bool V_179 = F_81 ( V_35 -> V_37 ,
V_128 ) ;
if ( ! V_179 )
V_61 += sizeof( * V_608 ) ;
V_69 = F_35 () ;
if ( ! V_69 ) {
F_434 ( V_35 , V_220 -> V_22 ,
V_35 -> V_56 ) ;
return - V_76 ;
}
V_69 -> V_217 = 1 ;
V_29 = F_111 ( V_117 , V_37 -> V_67 , V_69 ,
V_220 , V_61 ) ;
if ( V_29 ) {
F_55 ( V_69 ) ;
F_434 ( V_35 , V_220 -> V_22 ,
V_35 -> V_56 ) ;
return V_29 ;
}
V_71 = V_69 -> V_88 [ 0 ] ;
V_606 = F_83 ( V_71 , V_69 -> V_89 [ 0 ] ,
struct V_123 ) ;
F_95 ( V_71 , V_606 , 1 ) ;
F_96 ( V_71 , V_606 , V_117 -> V_303 ) ;
F_97 ( V_71 , V_606 ,
V_7 | V_150 ) ;
if ( V_179 ) {
V_170 = (struct V_169 * ) ( V_606 + 1 ) ;
V_36 = V_35 -> V_56 ;
} else {
V_608 = (struct V_144 * ) ( V_606 + 1 ) ;
F_163 ( V_71 , V_608 , V_21 ) ;
F_99 ( V_71 , V_608 , V_173 ) ;
V_170 = (struct V_169 * ) ( V_608 + 1 ) ;
}
if ( V_17 > 0 ) {
F_32 ( ! ( V_7 & V_133 ) ) ;
F_137 ( V_71 , V_170 ,
V_171 ) ;
F_138 ( V_71 , V_170 , V_17 ) ;
} else {
F_137 ( V_71 , V_170 ,
V_172 ) ;
F_138 ( V_71 , V_170 , V_152 ) ;
}
F_100 ( V_71 ) ;
F_55 ( V_69 ) ;
V_29 = F_381 ( V_117 , V_35 , V_220 -> V_22 , V_35 -> V_56 ,
1 ) ;
if ( V_29 ) {
F_402 ( V_37 , L_32 ,
V_220 -> V_22 , V_220 -> V_33 ) ;
F_88 () ;
}
F_435 ( V_35 , V_220 -> V_22 , V_35 -> V_56 ) ;
return V_29 ;
}
int F_436 ( struct V_116 * V_117 ,
struct V_34 * V_35 ,
T_2 V_152 , T_2 V_140 ,
T_2 V_33 , T_2 V_609 ,
struct V_72 * V_220 )
{
int V_29 ;
F_32 ( V_152 == V_214 ) ;
V_29 = F_155 ( V_35 -> V_37 , V_117 , V_220 -> V_22 ,
V_220 -> V_33 , 0 ,
V_152 , V_140 , V_33 ,
V_609 , V_241 ,
NULL ) ;
return V_29 ;
}
int F_437 ( struct V_116 * V_117 ,
struct V_34 * V_35 ,
T_2 V_152 , T_2 V_140 , T_2 V_33 ,
struct V_72 * V_220 )
{
int V_29 ;
struct V_1 * V_14 ;
if ( ! F_81 ( V_35 -> V_37 , V_523 ) ) {
V_29 = F_389 ( V_35 , V_220 -> V_22 , V_220 -> V_33 ) ;
if ( V_29 )
return V_29 ;
}
V_14 = F_73 ( V_35 -> V_37 , V_220 -> V_22 ) ;
if ( ! V_14 )
return - V_519 ;
V_29 = F_391 ( V_14 , V_220 -> V_33 ,
V_578 , 0 ) ;
F_32 ( V_29 ) ;
V_29 = F_161 ( V_117 , V_35 , 0 , V_152 ,
0 , V_140 , V_33 , V_220 , 1 ) ;
F_6 ( V_14 ) ;
return V_29 ;
}
static struct V_70 *
F_438 ( struct V_116 * V_117 , struct V_34 * V_35 ,
T_2 V_27 , int V_173 )
{
struct V_70 * V_282 ;
V_282 = F_439 ( V_35 , V_27 ) ;
if ( ! V_282 )
return F_440 ( - V_76 ) ;
F_441 ( V_282 , V_117 -> V_303 ) ;
F_442 ( V_35 -> V_278 . V_22 , V_282 , V_173 ) ;
F_443 ( V_282 ) ;
F_444 ( V_117 , V_35 -> V_37 , V_282 ) ;
F_410 ( V_610 , & V_282 -> V_555 ) ;
F_445 ( V_282 ) ;
F_446 ( V_282 ) ;
if ( V_35 -> V_278 . V_22 == V_214 ) {
V_282 -> V_611 = V_35 -> V_612 % 2 ;
if ( V_282 -> V_611 == 0 )
F_385 ( & V_35 -> V_613 , V_282 -> V_32 ,
V_282 -> V_32 + V_282 -> V_49 - 1 , V_40 ) ;
else
F_447 ( & V_35 -> V_613 , V_282 -> V_32 ,
V_282 -> V_32 + V_282 -> V_49 - 1 , V_40 ) ;
} else {
V_282 -> V_611 = - 1 ;
F_385 ( & V_117 -> V_134 -> V_614 , V_282 -> V_32 ,
V_282 -> V_32 + V_282 -> V_49 - 1 , V_40 ) ;
}
V_117 -> V_615 ++ ;
return V_282 ;
}
static struct V_259 *
F_448 ( struct V_116 * V_117 ,
struct V_34 * V_35 , T_3 V_616 )
{
struct V_259 * V_431 ;
struct V_259 * V_260 = & V_35 -> V_37 -> V_263 ;
int V_29 ;
bool V_617 = false ;
V_431 = F_346 ( V_117 , V_35 ) ;
if ( F_343 ( V_431 -> V_61 == 0 ) )
goto V_618;
V_83:
V_29 = F_344 ( V_431 , V_616 ) ;
if ( ! V_29 )
return V_431 ;
if ( V_431 -> V_619 )
return F_440 ( V_29 ) ;
if ( V_431 -> type == V_620 && ! V_617 ) {
V_617 = true ;
F_360 ( V_35 -> V_37 ) ;
goto V_83;
}
if ( F_256 ( V_35 , V_407 ) ) {
static F_449 ( V_621 ,
V_622 * 10 ,
1 ) ;
if ( F_450 ( & V_621 ) )
F_451 ( 1 , V_623
L_33 , V_29 ) ;
}
V_618:
V_29 = F_339 ( V_35 , V_431 , V_616 ,
V_409 ) ;
if ( ! V_29 )
return V_431 ;
if ( V_431 -> type != V_620 &&
V_431 -> V_95 == V_260 -> V_95 ) {
V_29 = F_344 ( V_260 , V_616 ) ;
if ( ! V_29 )
return V_260 ;
}
return F_440 ( V_29 ) ;
}
static void F_452 ( struct V_12 * V_37 ,
struct V_259 * V_431 , T_3 V_616 )
{
F_347 ( V_431 , V_616 , 0 ) ;
F_349 ( V_37 , V_431 , NULL , 0 ) ;
}
struct V_70 * F_453 ( struct V_116 * V_117 ,
struct V_34 * V_35 ,
T_2 V_17 , T_2 V_152 ,
struct V_607 * V_21 , int V_173 ,
T_2 V_624 , T_2 V_572 )
{
struct V_72 V_220 ;
struct V_259 * V_431 ;
struct V_70 * V_282 ;
struct V_186 * V_136 ;
T_2 V_7 = 0 ;
int V_29 ;
T_3 V_616 = V_35 -> V_56 ;
bool V_179 = F_81 ( V_35 -> V_37 ,
V_128 ) ;
if ( F_232 ( V_35 ) ) {
V_282 = F_438 ( V_117 , V_35 , V_35 -> V_625 ,
V_173 ) ;
if ( ! F_209 ( V_282 ) )
V_35 -> V_625 += V_616 ;
return V_282 ;
}
V_431 = F_448 ( V_117 , V_35 , V_616 ) ;
if ( F_209 ( V_431 ) )
return F_454 ( V_431 ) ;
V_29 = F_431 ( V_35 , V_616 , V_616 ,
V_572 , V_624 , & V_220 , 0 , 0 ) ;
if ( V_29 )
goto V_626;
V_282 = F_438 ( V_117 , V_35 , V_220 . V_22 , V_173 ) ;
if ( F_209 ( V_282 ) ) {
V_29 = F_210 ( V_282 ) ;
goto V_627;
}
if ( V_152 == V_628 ) {
if ( V_17 == 0 )
V_17 = V_220 . V_22 ;
V_7 |= V_133 ;
} else
F_32 ( V_17 > 0 ) ;
if ( V_152 != V_214 ) {
V_136 = F_223 () ;
if ( ! V_136 ) {
V_29 = - V_76 ;
goto V_629;
}
if ( V_21 )
memcpy ( & V_136 -> V_21 , V_21 , sizeof( V_136 -> V_21 ) ) ;
else
memset ( & V_136 -> V_21 , 0 , sizeof( V_136 -> V_21 ) ) ;
V_136 -> V_138 = V_7 ;
if ( V_179 )
V_136 -> V_224 = 0 ;
else
V_136 -> V_224 = 1 ;
V_136 -> V_137 = 1 ;
V_136 -> V_190 = 0 ;
V_136 -> V_173 = V_173 ;
V_29 = F_154 ( V_35 -> V_37 , V_117 ,
V_220 . V_22 , V_220 . V_33 ,
V_17 , V_152 , V_173 ,
V_241 ,
V_136 ) ;
if ( V_29 )
goto V_630;
}
return V_282 ;
V_630:
F_187 ( V_136 ) ;
V_629:
F_455 ( V_282 ) ;
V_627:
F_433 ( V_35 , V_220 . V_22 , V_220 . V_33 , 0 ) ;
V_626:
F_452 ( V_35 -> V_37 , V_431 , V_616 ) ;
return F_440 ( V_29 ) ;
}
static T_1 void F_456 ( struct V_116 * V_117 ,
struct V_34 * V_35 ,
struct V_631 * V_632 ,
struct V_68 * V_69 )
{
T_2 V_27 ;
T_2 V_306 ;
T_2 V_119 ;
T_2 V_7 ;
T_3 V_75 ;
T_3 V_616 ;
struct V_72 V_21 ;
struct V_70 * V_521 ;
int V_29 ;
int V_633 ;
int V_634 = 0 ;
if ( V_69 -> V_89 [ V_632 -> V_173 ] < V_632 -> V_635 ) {
V_632 -> V_636 = V_632 -> V_636 * 2 / 3 ;
V_632 -> V_636 = F_422 ( V_632 -> V_636 , 2 ) ;
} else {
V_632 -> V_636 = V_632 -> V_636 * 3 / 2 ;
V_632 -> V_636 = F_24 ( int , V_632 -> V_636 ,
F_457 ( V_35 ) ) ;
}
V_521 = V_69 -> V_88 [ V_632 -> V_173 ] ;
V_75 = F_42 ( V_521 ) ;
V_616 = V_35 -> V_56 ;
for ( V_633 = V_69 -> V_89 [ V_632 -> V_173 ] ; V_633 < V_75 ; V_633 ++ ) {
if ( V_634 >= V_632 -> V_636 )
break;
F_51 () ;
V_27 = F_240 ( V_521 , V_633 ) ;
V_306 = F_458 ( V_521 , V_633 ) ;
if ( V_633 == V_69 -> V_89 [ V_632 -> V_173 ] )
goto V_81;
if ( V_632 -> V_637 == V_638 &&
V_306 <= V_35 -> V_278 . V_33 )
continue;
V_29 = F_80 ( V_117 , V_35 , V_27 ,
V_632 -> V_173 - 1 , 1 , & V_119 ,
& V_7 ) ;
if ( V_29 < 0 )
continue;
F_32 ( V_119 == 0 ) ;
if ( V_632 -> V_637 == V_639 ) {
if ( V_119 == 1 )
goto V_81;
if ( V_632 -> V_173 == 1 &&
( V_7 & V_133 ) )
continue;
if ( ! V_632 -> V_640 ||
V_306 <= V_35 -> V_278 . V_33 )
continue;
F_128 ( V_521 , & V_21 , V_633 ) ;
V_29 = F_459 ( & V_21 ,
& V_632 -> V_641 ) ;
if ( V_29 < 0 )
continue;
} else {
if ( V_632 -> V_173 == 1 &&
( V_7 & V_133 ) )
continue;
}
V_81:
F_460 ( V_35 , V_27 ) ;
V_634 ++ ;
}
V_632 -> V_635 = V_633 ;
}
static int F_461 ( struct V_116 * V_117 ,
struct V_34 * V_35 , T_2 V_27 ,
T_2 V_36 )
{
struct V_642 * V_643 ;
struct V_121 * V_122 ;
V_643 = F_215 ( sizeof( * V_643 ) , V_40 ) ;
if ( ! V_643 )
return - V_76 ;
V_643 -> V_27 = V_27 ;
V_643 -> V_36 = V_36 ;
V_643 -> V_644 = NULL ;
V_122 = & V_117 -> V_134 -> V_122 ;
F_11 ( & V_122 -> V_52 ) ;
if ( F_462 ( V_122 , V_643 ) )
F_9 ( V_643 ) ;
F_13 ( & V_122 -> V_52 ) ;
return 0 ;
}
static int F_463 ( struct V_116 * V_117 ,
struct V_34 * V_35 ,
struct V_70 * V_521 )
{
int V_44 = F_42 ( V_521 ) ;
int V_43 , V_645 , V_29 ;
struct V_72 V_21 ;
struct V_285 * V_286 ;
T_2 V_27 , V_36 ;
if ( ! V_35 -> V_37 -> V_489 )
return 0 ;
for ( V_43 = 0 ; V_43 < V_44 ; V_43 ++ ) {
F_44 ( V_521 , & V_21 , V_43 ) ;
if ( V_21 . type != V_290 )
continue;
V_286 = F_83 ( V_521 , V_43 , struct V_285 ) ;
V_645 = F_236 ( V_521 , V_286 ) ;
if ( V_645 == V_291 )
continue;
V_27 = F_237 ( V_521 , V_286 ) ;
if ( ! V_27 )
continue;
V_36 = F_238 ( V_521 , V_286 ) ;
V_29 = F_461 ( V_117 , V_35 , V_27 , V_36 ) ;
if ( V_29 )
return V_29 ;
}
return 0 ;
}
static int F_464 ( struct V_34 * V_35 ,
struct V_68 * V_69 , int V_646 )
{
int V_173 = 0 ;
int V_44 , V_633 ;
struct V_70 * V_521 ;
if ( V_646 == 0 )
return 1 ;
while ( V_173 <= V_646 ) {
V_521 = V_69 -> V_88 [ V_173 ] ;
V_44 = F_42 ( V_521 ) ;
V_69 -> V_89 [ V_173 ] ++ ;
V_633 = V_69 -> V_89 [ V_173 ] ;
if ( V_633 >= V_44 || V_173 == 0 ) {
if ( V_173 != V_646 ) {
F_465 ( V_521 , V_69 -> V_647 [ V_173 ] ) ;
V_69 -> V_647 [ V_173 ] = 0 ;
F_455 ( V_521 ) ;
V_69 -> V_88 [ V_173 ] = NULL ;
V_69 -> V_89 [ V_173 ] = 0 ;
}
} else {
break;
}
V_173 ++ ;
}
V_521 = V_69 -> V_88 [ V_646 ] ;
if ( V_69 -> V_89 [ V_646 ] >= F_42 ( V_521 ) )
return 1 ;
return 0 ;
}
static int F_466 ( struct V_116 * V_117 ,
struct V_34 * V_35 ,
struct V_70 * V_648 ,
T_2 V_649 ,
int V_646 )
{
int V_29 = 0 ;
int V_173 ;
struct V_70 * V_521 = V_648 ;
struct V_68 * V_69 = NULL ;
F_32 ( V_646 < 0 || V_646 > V_174 ) ;
F_32 ( V_648 == NULL ) ;
if ( ! V_35 -> V_37 -> V_489 )
return 0 ;
if ( ! F_467 ( V_648 ) ) {
V_29 = F_468 ( V_648 , V_649 ) ;
if ( V_29 )
goto V_78;
}
if ( V_646 == 0 ) {
V_29 = F_463 ( V_117 , V_35 , V_648 ) ;
goto V_78;
}
V_69 = F_35 () ;
if ( ! V_69 )
return - V_76 ;
F_469 ( V_648 ) ;
V_69 -> V_88 [ V_646 ] = V_648 ;
V_69 -> V_89 [ V_646 ] = 0 ;
V_69 -> V_647 [ V_646 ] = 0 ;
V_650:
V_173 = V_646 ;
while ( V_173 >= 0 ) {
if ( V_69 -> V_88 [ V_173 ] == NULL ) {
int V_651 ;
T_2 V_652 ;
T_2 V_653 ;
V_521 = V_69 -> V_88 [ V_173 + 1 ] ;
V_651 = V_69 -> V_89 [ V_173 + 1 ] ;
V_653 = F_240 ( V_521 , V_651 ) ;
V_652 = F_458 ( V_521 , V_651 ) ;
V_521 = F_470 ( V_35 , V_653 , V_652 ) ;
if ( F_209 ( V_521 ) ) {
V_29 = F_210 ( V_521 ) ;
goto V_78;
} else if ( ! F_467 ( V_521 ) ) {
F_455 ( V_521 ) ;
V_29 = - V_181 ;
goto V_78;
}
V_69 -> V_88 [ V_173 ] = V_521 ;
V_69 -> V_89 [ V_173 ] = 0 ;
F_471 ( V_521 ) ;
F_472 ( V_521 , V_654 ) ;
V_69 -> V_647 [ V_173 ] = V_655 ;
V_29 = F_461 ( V_117 , V_35 , V_653 ,
V_35 -> V_56 ) ;
if ( V_29 )
goto V_78;
}
if ( V_173 == 0 ) {
V_29 = F_463 ( V_117 , V_35 , V_69 -> V_88 [ V_173 ] ) ;
if ( V_29 )
goto V_78;
V_29 = F_464 ( V_35 , V_69 , V_646 ) ;
if ( V_29 )
break;
goto V_650;
}
V_173 -- ;
}
V_29 = 0 ;
V_78:
F_55 ( V_69 ) ;
return V_29 ;
}
static T_1 int F_473 ( struct V_116 * V_117 ,
struct V_34 * V_35 ,
struct V_68 * V_69 ,
struct V_631 * V_632 , int V_656 )
{
int V_173 = V_632 -> V_173 ;
struct V_70 * V_521 = V_69 -> V_88 [ V_173 ] ;
T_2 V_657 = V_133 ;
int V_29 ;
if ( V_632 -> V_637 == V_638 &&
F_233 ( V_521 ) != V_35 -> V_278 . V_22 )
return 1 ;
if ( V_656 &&
( ( V_632 -> V_637 == V_639 && V_632 -> V_119 [ V_173 ] != 1 ) ||
( V_632 -> V_637 == V_638 && ! ( V_632 -> V_7 [ V_173 ] & V_657 ) ) ) ) {
F_32 ( ! V_69 -> V_647 [ V_173 ] ) ;
V_29 = F_80 ( V_117 , V_35 ,
V_521 -> V_32 , V_173 , 1 ,
& V_632 -> V_119 [ V_173 ] ,
& V_632 -> V_7 [ V_173 ] ) ;
F_32 ( V_29 == - V_76 ) ;
if ( V_29 )
return V_29 ;
F_32 ( V_632 -> V_119 [ V_173 ] == 0 ) ;
}
if ( V_632 -> V_637 == V_639 ) {
if ( V_632 -> V_119 [ V_173 ] > 1 )
return 1 ;
if ( V_69 -> V_647 [ V_173 ] && ! V_632 -> V_180 ) {
F_465 ( V_521 , V_69 -> V_647 [ V_173 ] ) ;
V_69 -> V_647 [ V_173 ] = 0 ;
}
return 0 ;
}
if ( ! ( V_632 -> V_7 [ V_173 ] & V_657 ) ) {
F_32 ( ! V_69 -> V_647 [ V_173 ] ) ;
V_29 = F_241 ( V_117 , V_35 , V_521 , 1 ) ;
F_32 ( V_29 ) ;
V_29 = F_242 ( V_117 , V_35 , V_521 , 0 ) ;
F_32 ( V_29 ) ;
V_29 = F_222 ( V_117 , V_35 , V_521 -> V_32 ,
V_521 -> V_49 , V_657 ,
F_234 ( V_521 ) , 0 ) ;
F_32 ( V_29 ) ;
V_632 -> V_7 [ V_173 ] |= V_657 ;
}
if ( V_69 -> V_647 [ V_173 ] && V_173 > 0 ) {
F_465 ( V_521 , V_69 -> V_647 [ V_173 ] ) ;
V_69 -> V_647 [ V_173 ] = 0 ;
}
return 0 ;
}
static T_1 int F_474 ( struct V_116 * V_117 ,
struct V_34 * V_35 ,
struct V_68 * V_69 ,
struct V_631 * V_632 , int * V_656 )
{
T_2 V_27 ;
T_2 V_306 ;
T_2 V_17 ;
T_3 V_616 ;
struct V_72 V_21 ;
struct V_70 * V_86 ;
int V_173 = V_632 -> V_173 ;
int V_81 = 0 ;
int V_29 = 0 ;
bool V_658 = false ;
V_306 = F_458 ( V_69 -> V_88 [ V_173 ] ,
V_69 -> V_89 [ V_173 ] ) ;
if ( V_632 -> V_637 == V_638 &&
V_306 <= V_35 -> V_278 . V_33 ) {
* V_656 = 1 ;
return 1 ;
}
V_27 = F_240 ( V_69 -> V_88 [ V_173 ] , V_69 -> V_89 [ V_173 ] ) ;
V_616 = V_35 -> V_56 ;
V_86 = F_475 ( V_35 -> V_37 , V_27 ) ;
if ( ! V_86 ) {
V_86 = F_439 ( V_35 , V_27 ) ;
if ( ! V_86 )
return - V_76 ;
F_442 ( V_35 -> V_278 . V_22 , V_86 ,
V_173 - 1 ) ;
V_81 = 1 ;
}
F_443 ( V_86 ) ;
F_445 ( V_86 ) ;
V_29 = F_80 ( V_117 , V_35 , V_27 , V_173 - 1 , 1 ,
& V_632 -> V_119 [ V_173 - 1 ] ,
& V_632 -> V_7 [ V_173 - 1 ] ) ;
if ( V_29 < 0 ) {
F_476 ( V_86 ) ;
return V_29 ;
}
if ( F_343 ( V_632 -> V_119 [ V_173 - 1 ] == 0 ) ) {
F_402 ( V_35 -> V_37 , L_34 ) ;
F_88 () ;
}
* V_656 = 0 ;
if ( V_632 -> V_637 == V_639 ) {
if ( V_632 -> V_119 [ V_173 - 1 ] > 1 ) {
V_658 = true ;
if ( V_173 == 1 &&
( V_632 -> V_7 [ 0 ] & V_133 ) )
goto V_659;
if ( ! V_632 -> V_640 ||
V_306 <= V_35 -> V_278 . V_33 )
goto V_659;
F_128 ( V_69 -> V_88 [ V_173 ] , & V_21 ,
V_69 -> V_89 [ V_173 ] ) ;
V_29 = F_459 ( & V_21 , & V_632 -> V_641 ) ;
if ( V_29 < 0 )
goto V_659;
V_632 -> V_637 = V_638 ;
V_632 -> V_660 = V_173 - 1 ;
}
} else {
if ( V_173 == 1 &&
( V_632 -> V_7 [ 0 ] & V_133 ) )
goto V_659;
}
if ( ! F_477 ( V_86 , V_306 , 0 ) ) {
F_476 ( V_86 ) ;
F_455 ( V_86 ) ;
V_86 = NULL ;
* V_656 = 1 ;
}
if ( ! V_86 ) {
if ( V_81 && V_173 == 1 )
F_456 ( V_117 , V_35 , V_632 , V_69 ) ;
V_86 = F_470 ( V_35 , V_27 , V_306 ) ;
if ( F_209 ( V_86 ) ) {
return F_210 ( V_86 ) ;
} else if ( ! F_467 ( V_86 ) ) {
F_455 ( V_86 ) ;
return - V_181 ;
}
F_443 ( V_86 ) ;
F_445 ( V_86 ) ;
}
V_173 -- ;
F_32 ( V_173 != F_234 ( V_86 ) ) ;
V_69 -> V_88 [ V_173 ] = V_86 ;
V_69 -> V_89 [ V_173 ] = 0 ;
V_69 -> V_647 [ V_173 ] = V_661 ;
V_632 -> V_173 = V_173 ;
if ( V_632 -> V_173 == 1 )
V_632 -> V_635 = 0 ;
return 0 ;
V_659:
V_632 -> V_119 [ V_173 - 1 ] = 0 ;
V_632 -> V_7 [ V_173 - 1 ] = 0 ;
if ( V_632 -> V_637 == V_639 ) {
if ( V_632 -> V_7 [ V_173 ] & V_133 ) {
V_17 = V_69 -> V_88 [ V_173 ] -> V_32 ;
} else {
F_32 ( V_35 -> V_278 . V_22 !=
F_233 ( V_69 -> V_88 [ V_173 ] ) ) ;
V_17 = 0 ;
}
if ( V_658 ) {
V_29 = F_466 ( V_117 , V_35 , V_86 ,
V_306 , V_173 - 1 ) ;
if ( V_29 ) {
F_478 ( V_35 -> V_37 ,
L_35
L_36
L_37 ,
V_29 ) ;
}
}
V_29 = V_289 ( V_117 , V_35 , V_27 , V_616 , V_17 ,
V_35 -> V_278 . V_22 , V_173 - 1 , 0 ) ;
F_32 ( V_29 ) ;
}
F_476 ( V_86 ) ;
F_455 ( V_86 ) ;
* V_656 = 1 ;
return 1 ;
}
static T_1 int F_479 ( struct V_116 * V_117 ,
struct V_34 * V_35 ,
struct V_68 * V_69 ,
struct V_631 * V_632 )
{
int V_29 ;
int V_173 = V_632 -> V_173 ;
struct V_70 * V_521 = V_69 -> V_88 [ V_173 ] ;
T_2 V_17 = 0 ;
if ( V_632 -> V_637 == V_638 ) {
F_32 ( V_632 -> V_660 < V_173 ) ;
if ( V_173 < V_632 -> V_660 )
goto V_78;
V_29 = F_45 ( V_69 , V_173 + 1 , & V_632 -> V_641 ) ;
if ( V_29 > 0 )
V_632 -> V_640 = 0 ;
V_632 -> V_637 = V_639 ;
V_632 -> V_660 = - 1 ;
V_69 -> V_89 [ V_173 ] = 0 ;
if ( ! V_69 -> V_647 [ V_173 ] ) {
F_32 ( V_173 == 0 ) ;
F_443 ( V_521 ) ;
F_445 ( V_521 ) ;
V_69 -> V_647 [ V_173 ] = V_661 ;
V_29 = F_80 ( V_117 , V_35 ,
V_521 -> V_32 , V_173 , 1 ,
& V_632 -> V_119 [ V_173 ] ,
& V_632 -> V_7 [ V_173 ] ) ;
if ( V_29 < 0 ) {
F_465 ( V_521 , V_69 -> V_647 [ V_173 ] ) ;
V_69 -> V_647 [ V_173 ] = 0 ;
return V_29 ;
}
F_32 ( V_632 -> V_119 [ V_173 ] == 0 ) ;
if ( V_632 -> V_119 [ V_173 ] == 1 ) {
F_465 ( V_521 , V_69 -> V_647 [ V_173 ] ) ;
V_69 -> V_647 [ V_173 ] = 0 ;
return 1 ;
}
}
}
F_32 ( V_632 -> V_119 [ V_173 ] > 1 && ! V_69 -> V_647 [ V_173 ] ) ;
if ( V_632 -> V_119 [ V_173 ] == 1 ) {
if ( V_173 == 0 ) {
if ( V_632 -> V_7 [ V_173 ] & V_133 )
V_29 = F_242 ( V_117 , V_35 , V_521 , 1 ) ;
else
V_29 = F_242 ( V_117 , V_35 , V_521 , 0 ) ;
F_32 ( V_29 ) ;
V_29 = F_463 ( V_117 , V_35 , V_521 ) ;
if ( V_29 ) {
F_478 ( V_35 -> V_37 ,
L_38
L_39
L_37 ,
V_29 ) ;
}
}
if ( ! V_69 -> V_647 [ V_173 ] &&
F_408 ( V_521 ) == V_117 -> V_303 ) {
F_443 ( V_521 ) ;
F_445 ( V_521 ) ;
V_69 -> V_647 [ V_173 ] = V_661 ;
}
F_444 ( V_117 , V_35 -> V_37 , V_521 ) ;
}
if ( V_521 == V_35 -> V_135 ) {
if ( V_632 -> V_7 [ V_173 ] & V_133 )
V_17 = V_521 -> V_32 ;
else
F_32 ( V_35 -> V_278 . V_22 !=
F_233 ( V_521 ) ) ;
} else {
if ( V_632 -> V_7 [ V_173 + 1 ] & V_133 )
V_17 = V_69 -> V_88 [ V_173 + 1 ] -> V_32 ;
else
F_32 ( V_35 -> V_278 . V_22 !=
F_233 ( V_69 -> V_88 [ V_173 + 1 ] ) ) ;
}
F_407 ( V_117 , V_35 , V_521 , V_17 , V_632 -> V_119 [ V_173 ] == 1 ) ;
V_78:
V_632 -> V_119 [ V_173 ] = 0 ;
V_632 -> V_7 [ V_173 ] = 0 ;
return 0 ;
}
static T_1 int F_480 ( struct V_116 * V_117 ,
struct V_34 * V_35 ,
struct V_68 * V_69 ,
struct V_631 * V_632 )
{
int V_173 = V_632 -> V_173 ;
int V_656 = 1 ;
int V_29 ;
while ( V_173 >= 0 ) {
V_29 = F_473 ( V_117 , V_35 , V_69 , V_632 , V_656 ) ;
if ( V_29 > 0 )
break;
if ( V_173 == 0 )
break;
if ( V_69 -> V_89 [ V_173 ] >=
F_42 ( V_69 -> V_88 [ V_173 ] ) )
break;
V_29 = F_474 ( V_117 , V_35 , V_69 , V_632 , & V_656 ) ;
if ( V_29 > 0 ) {
V_69 -> V_89 [ V_173 ] ++ ;
continue;
} else if ( V_29 < 0 )
return V_29 ;
V_173 = V_632 -> V_173 ;
}
return 0 ;
}
static T_1 int F_481 ( struct V_116 * V_117 ,
struct V_34 * V_35 ,
struct V_68 * V_69 ,
struct V_631 * V_632 , int V_662 )
{
int V_173 = V_632 -> V_173 ;
int V_29 ;
V_69 -> V_89 [ V_173 ] = F_42 ( V_69 -> V_88 [ V_173 ] ) ;
while ( V_173 < V_662 && V_69 -> V_88 [ V_173 ] ) {
V_632 -> V_173 = V_173 ;
if ( V_69 -> V_89 [ V_173 ] + 1 <
F_42 ( V_69 -> V_88 [ V_173 ] ) ) {
V_69 -> V_89 [ V_173 ] ++ ;
return 0 ;
} else {
V_29 = F_479 ( V_117 , V_35 , V_69 , V_632 ) ;
if ( V_29 > 0 )
return 0 ;
if ( V_69 -> V_647 [ V_173 ] ) {
F_465 ( V_69 -> V_88 [ V_173 ] ,
V_69 -> V_647 [ V_173 ] ) ;
V_69 -> V_647 [ V_173 ] = 0 ;
}
F_455 ( V_69 -> V_88 [ V_173 ] ) ;
V_69 -> V_88 [ V_173 ] = NULL ;
V_173 ++ ;
}
}
return 1 ;
}
int F_482 ( struct V_34 * V_35 ,
struct V_259 * V_431 , int V_640 ,
int V_663 )
{
struct V_68 * V_69 ;
struct V_116 * V_117 ;
struct V_34 * V_92 = V_35 -> V_37 -> V_92 ;
struct V_664 * V_279 = & V_35 -> V_279 ;
struct V_631 * V_632 ;
struct V_72 V_21 ;
int V_87 = 0 ;
int V_29 ;
int V_173 ;
bool V_665 = false ;
F_188 ( V_35 -> V_37 , L_40 , V_35 -> V_22 ) ;
V_69 = F_35 () ;
if ( ! V_69 ) {
V_87 = - V_76 ;
goto V_78;
}
V_632 = F_58 ( sizeof( * V_632 ) , V_40 ) ;
if ( ! V_632 ) {
F_55 ( V_69 ) ;
V_87 = - V_76 ;
goto V_78;
}
V_117 = F_483 ( V_92 , 0 ) ;
if ( F_209 ( V_117 ) ) {
V_87 = F_210 ( V_117 ) ;
goto V_130;
}
if ( V_431 )
V_117 -> V_431 = V_431 ;
if ( F_484 ( & V_279 -> V_666 ) == 0 ) {
V_173 = F_234 ( V_35 -> V_135 ) ;
V_69 -> V_88 [ V_173 ] = F_485 ( V_35 ) ;
F_445 ( V_69 -> V_88 [ V_173 ] ) ;
V_69 -> V_89 [ V_173 ] = 0 ;
V_69 -> V_647 [ V_173 ] = V_661 ;
memset ( & V_632 -> V_641 , 0 ,
sizeof( V_632 -> V_641 ) ) ;
} else {
F_486 ( & V_21 , & V_279 -> V_666 ) ;
memcpy ( & V_632 -> V_641 , & V_21 ,
sizeof( V_632 -> V_641 ) ) ;
V_173 = V_279 -> V_667 ;
F_32 ( V_173 == 0 ) ;
V_69 -> V_668 = V_173 ;
V_29 = F_41 ( NULL , V_35 , & V_21 , V_69 , 0 , 0 ) ;
V_69 -> V_668 = 0 ;
if ( V_29 < 0 ) {
V_87 = V_29 ;
goto V_669;
}
F_8 ( V_29 > 0 ) ;
F_133 ( V_69 , 0 ) ;
V_173 = F_234 ( V_35 -> V_135 ) ;
while ( 1 ) {
F_443 ( V_69 -> V_88 [ V_173 ] ) ;
F_445 ( V_69 -> V_88 [ V_173 ] ) ;
V_69 -> V_647 [ V_173 ] = V_661 ;
V_29 = F_80 ( V_117 , V_35 ,
V_69 -> V_88 [ V_173 ] -> V_32 ,
V_173 , 1 , & V_632 -> V_119 [ V_173 ] ,
& V_632 -> V_7 [ V_173 ] ) ;
if ( V_29 < 0 ) {
V_87 = V_29 ;
goto V_669;
}
F_32 ( V_632 -> V_119 [ V_173 ] == 0 ) ;
if ( V_173 == V_279 -> V_667 )
break;
F_476 ( V_69 -> V_88 [ V_173 ] ) ;
V_69 -> V_647 [ V_173 ] = 0 ;
F_8 ( V_632 -> V_119 [ V_173 ] != 1 ) ;
V_173 -- ;
}
}
V_632 -> V_173 = V_173 ;
V_632 -> V_660 = - 1 ;
V_632 -> V_637 = V_639 ;
V_632 -> V_640 = V_640 ;
V_632 -> V_180 = 0 ;
V_632 -> V_663 = V_663 ;
V_632 -> V_636 = F_457 ( V_35 ) ;
while ( 1 ) {
V_29 = F_480 ( V_117 , V_35 , V_69 , V_632 ) ;
if ( V_29 < 0 ) {
V_87 = V_29 ;
break;
}
V_29 = F_481 ( V_117 , V_35 , V_69 , V_632 , V_174 ) ;
if ( V_29 < 0 ) {
V_87 = V_29 ;
break;
}
if ( V_29 > 0 ) {
F_32 ( V_632 -> V_637 != V_639 ) ;
break;
}
if ( V_632 -> V_637 == V_639 ) {
V_173 = V_632 -> V_173 ;
F_487 ( V_69 -> V_88 [ V_173 ] ,
& V_279 -> V_666 ,
V_69 -> V_89 [ V_173 ] ) ;
V_279 -> V_667 = V_173 ;
}
F_32 ( V_632 -> V_173 == 0 ) ;
if ( F_488 ( V_117 , V_92 ) ||
( ! V_663 && F_489 ( V_35 ) ) ) {
V_29 = F_490 ( V_117 , V_92 ,
& V_35 -> V_278 ,
V_279 ) ;
if ( V_29 ) {
F_157 ( V_117 , V_92 , V_29 ) ;
V_87 = V_29 ;
goto V_669;
}
F_491 ( V_117 , V_92 ) ;
if ( ! V_663 && F_489 ( V_35 ) ) {
F_492 ( L_41 ) ;
V_87 = - V_184 ;
goto V_130;
}
V_117 = F_483 ( V_92 , 0 ) ;
if ( F_209 ( V_117 ) ) {
V_87 = F_210 ( V_117 ) ;
goto V_130;
}
if ( V_431 )
V_117 -> V_431 = V_431 ;
}
}
F_48 ( V_69 ) ;
if ( V_87 )
goto V_669;
V_29 = F_493 ( V_117 , V_92 , & V_35 -> V_278 ) ;
if ( V_29 ) {
F_157 ( V_117 , V_92 , V_29 ) ;
goto V_669;
}
if ( V_35 -> V_278 . V_22 != V_628 ) {
V_29 = F_494 ( V_92 , & V_35 -> V_278 , V_69 ,
NULL , NULL ) ;
if ( V_29 < 0 ) {
F_157 ( V_117 , V_92 , V_29 ) ;
V_87 = V_29 ;
goto V_669;
} else if ( V_29 > 0 ) {
F_495 ( V_117 , V_92 ,
V_35 -> V_278 . V_22 ) ;
}
}
if ( F_235 ( V_670 , & V_35 -> V_288 ) ) {
F_496 ( V_117 , V_35 ) ;
} else {
F_455 ( V_35 -> V_135 ) ;
F_455 ( V_35 -> V_671 ) ;
F_497 ( V_35 ) ;
}
V_665 = true ;
V_669:
F_491 ( V_117 , V_92 ) ;
V_130:
F_9 ( V_632 ) ;
F_55 ( V_69 ) ;
V_78:
if ( ! V_663 && V_665 == false )
F_498 ( V_35 ) ;
if ( V_87 && V_87 != - V_184 )
F_499 ( V_35 -> V_37 , V_87 , NULL ) ;
return V_87 ;
}
int F_500 ( struct V_116 * V_117 ,
struct V_34 * V_35 ,
struct V_70 * V_135 ,
struct V_70 * V_17 )
{
struct V_68 * V_69 ;
struct V_631 * V_632 ;
int V_173 ;
int V_672 ;
int V_29 = 0 ;
int V_673 ;
F_32 ( V_35 -> V_278 . V_22 != V_628 ) ;
V_69 = F_35 () ;
if ( ! V_69 )
return - V_76 ;
V_632 = F_58 ( sizeof( * V_632 ) , V_40 ) ;
if ( ! V_632 ) {
F_55 ( V_69 ) ;
return - V_76 ;
}
F_501 ( V_17 ) ;
V_672 = F_234 ( V_17 ) ;
F_469 ( V_17 ) ;
V_69 -> V_88 [ V_672 ] = V_17 ;
V_69 -> V_89 [ V_672 ] = F_42 ( V_17 ) ;
F_501 ( V_135 ) ;
V_173 = F_234 ( V_135 ) ;
V_69 -> V_88 [ V_173 ] = V_135 ;
V_69 -> V_89 [ V_173 ] = 0 ;
V_69 -> V_647 [ V_173 ] = V_661 ;
V_632 -> V_119 [ V_672 ] = 1 ;
V_632 -> V_7 [ V_672 ] = V_133 ;
V_632 -> V_173 = V_173 ;
V_632 -> V_660 = - 1 ;
V_632 -> V_637 = V_639 ;
V_632 -> V_640 = 0 ;
V_632 -> V_180 = 1 ;
V_632 -> V_663 = 1 ;
V_632 -> V_636 = F_457 ( V_35 ) ;
while ( 1 ) {
V_673 = F_480 ( V_117 , V_35 , V_69 , V_632 ) ;
if ( V_673 < 0 ) {
V_29 = V_673 ;
break;
}
V_673 = F_481 ( V_117 , V_35 , V_69 , V_632 , V_672 ) ;
if ( V_673 < 0 )
V_29 = V_673 ;
if ( V_673 != 0 )
break;
}
F_9 ( V_632 ) ;
F_55 ( V_69 ) ;
return V_29 ;
}
static T_2 F_502 ( struct V_34 * V_35 , T_2 V_7 )
{
T_2 V_370 ;
T_2 V_674 ;
V_674 = F_284 ( V_35 -> V_37 , V_7 ) ;
if ( V_674 )
return F_286 ( V_674 ) ;
V_370 = V_35 -> V_37 -> V_371 -> V_372 ;
V_674 = V_381 |
V_380 | V_379 |
V_333 | V_334 ;
if ( V_370 == 1 ) {
V_674 |= V_332 ;
V_674 = V_7 & ~ V_674 ;
if ( V_7 & V_381 )
return V_674 ;
if ( V_7 & ( V_333 |
V_334 ) )
return V_674 | V_332 ;
} else {
if ( V_7 & V_674 )
return V_7 ;
V_674 |= V_332 ;
V_674 = V_7 & ~ V_674 ;
if ( V_7 & V_332 )
return V_674 | V_333 ;
}
return V_7 ;
}
static int F_503 ( struct V_1 * V_2 , int V_399 )
{
struct V_110 * V_398 = V_2 -> V_95 ;
T_2 V_36 ;
T_2 V_675 ;
int V_29 = - V_309 ;
if ( ( V_398 -> V_7 &
( V_329 | V_55 ) ) &&
! V_399 )
V_675 = 1 * 1024 * 1024 ;
else
V_675 = 0 ;
F_11 ( & V_398 -> V_52 ) ;
F_11 ( & V_2 -> V_52 ) ;
if ( V_2 -> V_301 ) {
V_2 -> V_301 ++ ;
V_29 = 0 ;
goto V_78;
}
V_36 = V_2 -> V_21 . V_33 - V_2 -> V_10 - V_2 -> V_9 -
V_2 -> V_46 - F_54 ( & V_2 -> V_96 ) ;
if ( V_398 -> V_94 + V_398 -> V_343 + V_398 -> V_342 +
V_398 -> V_345 + V_398 -> V_344 + V_36 +
V_675 <= V_398 -> V_330 ) {
V_398 -> V_344 += V_36 ;
V_2 -> V_301 ++ ;
F_69 ( & V_2 -> V_676 , & V_398 -> V_351 ) ;
V_29 = 0 ;
}
V_78:
F_13 ( & V_2 -> V_52 ) ;
F_13 ( & V_398 -> V_52 ) ;
return V_29 ;
}
int F_504 ( struct V_34 * V_35 ,
struct V_1 * V_2 )
{
struct V_116 * V_117 ;
T_2 V_677 ;
int V_29 ;
V_83:
V_117 = F_208 ( V_35 ) ;
if ( F_209 ( V_117 ) )
return F_210 ( V_117 ) ;
F_39 ( & V_35 -> V_37 -> V_678 ) ;
if ( F_235 ( V_679 , & V_117 -> V_134 -> V_7 ) ) {
T_2 V_303 = V_117 -> V_303 ;
F_50 ( & V_35 -> V_37 -> V_678 ) ;
F_212 ( V_117 , V_35 ) ;
V_29 = F_505 ( V_35 , V_303 ) ;
if ( V_29 )
return V_29 ;
goto V_83;
}
V_677 = F_502 ( V_35 , V_2 -> V_7 ) ;
if ( V_677 != V_2 -> V_7 ) {
V_29 = F_293 ( V_117 , V_35 , V_677 ,
V_392 ) ;
if ( V_29 == - V_309 )
V_29 = 0 ;
if ( V_29 < 0 )
goto V_78;
}
V_29 = F_503 ( V_2 , 0 ) ;
if ( ! V_29 )
goto V_78;
V_677 = F_287 ( V_35 , V_2 -> V_95 -> V_7 ) ;
V_29 = F_293 ( V_117 , V_35 , V_677 ,
V_392 ) ;
if ( V_29 < 0 )
goto V_78;
V_29 = F_503 ( V_2 , 0 ) ;
V_78:
if ( V_2 -> V_7 & V_329 ) {
V_677 = F_502 ( V_35 , V_2 -> V_7 ) ;
F_506 ( V_35 -> V_37 -> V_384 ) ;
F_309 ( V_117 , V_35 , V_677 ) ;
F_507 ( V_35 -> V_37 -> V_384 ) ;
}
F_50 ( & V_35 -> V_37 -> V_678 ) ;
F_212 ( V_117 , V_35 ) ;
return V_29 ;
}
int F_508 ( struct V_116 * V_117 ,
struct V_34 * V_35 , T_2 type )
{
T_2 V_677 = F_287 ( V_35 , type ) ;
return F_293 ( V_117 , V_35 , V_677 ,
V_392 ) ;
}
T_2 F_509 ( struct V_110 * V_398 )
{
struct V_1 * V_14 ;
T_2 V_680 = 0 ;
int V_331 ;
if ( F_177 ( & V_398 -> V_351 ) )
return 0 ;
F_11 ( & V_398 -> V_52 ) ;
F_178 (block_group, &sinfo->ro_bgs, ro_list) {
F_11 ( & V_14 -> V_52 ) ;
if ( ! V_14 -> V_301 ) {
F_13 ( & V_14 -> V_52 ) ;
continue;
}
if ( V_14 -> V_7 & ( V_333 |
V_334 |
V_332 ) )
V_331 = 2 ;
else
V_331 = 1 ;
V_680 += ( V_14 -> V_21 . V_33 -
F_54 ( & V_14 -> V_96 ) ) *
V_331 ;
F_13 ( & V_14 -> V_52 ) ;
}
F_13 ( & V_398 -> V_52 ) ;
return V_680 ;
}
void F_510 ( struct V_34 * V_35 ,
struct V_1 * V_2 )
{
struct V_110 * V_398 = V_2 -> V_95 ;
T_2 V_36 ;
F_32 ( ! V_2 -> V_301 ) ;
F_11 ( & V_398 -> V_52 ) ;
F_11 ( & V_2 -> V_52 ) ;
if ( ! -- V_2 -> V_301 ) {
V_36 = V_2 -> V_21 . V_33 - V_2 -> V_10 -
V_2 -> V_9 - V_2 -> V_46 -
F_54 ( & V_2 -> V_96 ) ;
V_398 -> V_344 -= V_36 ;
F_268 ( & V_2 -> V_676 ) ;
}
F_13 ( & V_2 -> V_52 ) ;
F_13 ( & V_398 -> V_52 ) ;
}
int F_511 ( struct V_34 * V_35 , T_2 V_27 )
{
struct V_1 * V_14 ;
struct V_110 * V_95 ;
struct V_681 * V_371 = V_35 -> V_37 -> V_371 ;
struct V_682 * V_683 ;
struct V_116 * V_117 ;
T_2 V_684 ;
T_2 V_685 = 1 ;
T_2 V_686 = 0 ;
T_2 V_365 ;
int V_576 ;
int V_115 = 0 ;
int V_29 = 0 ;
V_14 = F_73 ( V_35 -> V_37 , V_27 ) ;
if ( ! V_14 )
return - 1 ;
V_684 = F_54 ( & V_14 -> V_96 ) ;
if ( ! V_684 )
goto V_78;
V_95 = V_14 -> V_95 ;
F_11 ( & V_95 -> V_52 ) ;
V_115 = V_95 -> V_115 ;
if ( ( V_95 -> V_330 != V_14 -> V_21 . V_33 ) &&
( V_95 -> V_94 + V_95 -> V_343 +
V_95 -> V_342 + V_95 -> V_344 +
V_684 < V_95 -> V_330 ) ) {
F_13 ( & V_95 -> V_52 ) ;
goto V_78;
}
F_13 ( & V_95 -> V_52 ) ;
V_29 = - 1 ;
V_365 = F_284 ( V_35 -> V_37 , V_14 -> V_7 ) ;
if ( V_365 ) {
V_576 = F_413 ( F_286 ( V_365 ) ) ;
} else {
if ( V_115 )
goto V_78;
V_576 = F_414 ( V_14 ) ;
}
if ( V_576 == V_558 ) {
V_685 = 4 ;
V_684 >>= 1 ;
} else if ( V_576 == V_559 ) {
V_685 = 2 ;
} else if ( V_576 == V_560 ) {
V_684 <<= 1 ;
} else if ( V_576 == V_561 ) {
V_685 = V_371 -> V_372 ;
V_684 = F_201 ( V_684 , V_685 ) ;
}
V_117 = F_208 ( V_35 ) ;
if ( F_209 ( V_117 ) ) {
V_29 = F_210 ( V_117 ) ;
goto V_78;
}
F_39 ( & V_35 -> V_37 -> V_406 ) ;
F_178 (device, &fs_devices->alloc_list, dev_alloc_list) {
T_2 V_687 ;
if ( V_683 -> V_330 > V_683 -> V_94 + V_684 &&
! V_683 -> V_688 ) {
V_29 = F_512 ( V_117 , V_683 , V_684 ,
& V_687 , NULL ) ;
if ( ! V_29 )
V_686 ++ ;
if ( V_686 >= V_685 )
break;
V_29 = - 1 ;
}
}
F_50 ( & V_35 -> V_37 -> V_406 ) ;
F_212 ( V_117 , V_35 ) ;
V_78:
F_6 ( V_14 ) ;
return V_29 ;
}
static int F_513 ( struct V_34 * V_35 ,
struct V_68 * V_69 , struct V_72 * V_21 )
{
int V_29 = 0 ;
struct V_72 V_146 ;
struct V_70 * V_71 ;
int V_633 ;
V_29 = F_41 ( NULL , V_35 , V_21 , V_69 , 0 , 0 ) ;
if ( V_29 < 0 )
goto V_78;
while ( 1 ) {
V_633 = V_69 -> V_89 [ 0 ] ;
V_71 = V_69 -> V_88 [ 0 ] ;
if ( V_633 >= F_42 ( V_71 ) ) {
V_29 = F_52 ( V_35 , V_69 ) ;
if ( V_29 == 0 )
continue;
if ( V_29 < 0 )
goto V_78;
break;
}
F_44 ( V_71 , & V_146 , V_633 ) ;
if ( V_146 . V_22 >= V_21 -> V_22 &&
V_146 . type == V_185 ) {
V_29 = 0 ;
goto V_78;
}
V_69 -> V_89 [ 0 ] ++ ;
}
V_78:
return V_29 ;
}
void F_514 ( struct V_12 * V_13 )
{
struct V_1 * V_14 ;
T_2 V_74 = 0 ;
while ( 1 ) {
struct V_293 * V_293 ;
V_14 = F_72 ( V_13 , V_74 ) ;
while ( V_14 ) {
F_11 ( & V_14 -> V_52 ) ;
if ( V_14 -> V_170 )
break;
F_13 ( & V_14 -> V_52 ) ;
V_14 = F_246 ( V_13 -> V_92 ,
V_14 ) ;
}
if ( ! V_14 ) {
if ( V_74 == 0 )
break;
V_74 = 0 ;
continue;
}
V_293 = V_14 -> V_293 ;
V_14 -> V_170 = 0 ;
V_14 -> V_293 = NULL ;
F_13 ( & V_14 -> V_52 ) ;
F_261 ( V_293 ) ;
V_74 = V_14 -> V_21 . V_22 + V_14 -> V_21 . V_33 ;
F_6 ( V_14 ) ;
}
}
int F_515 ( struct V_12 * V_13 )
{
struct V_1 * V_14 ;
struct V_110 * V_95 ;
struct V_50 * V_53 ;
struct V_15 * V_30 ;
F_68 ( & V_13 -> V_85 ) ;
while ( ! F_177 ( & V_13 -> V_108 ) ) {
V_53 = F_179 ( V_13 -> V_108 . V_86 ,
struct V_50 , V_98 ) ;
F_190 ( & V_53 -> V_98 ) ;
F_26 ( V_53 ) ;
}
F_70 ( & V_13 -> V_85 ) ;
F_11 ( & V_13 -> V_515 ) ;
while ( ! F_177 ( & V_13 -> V_517 ) ) {
V_14 = F_267 ( & V_13 -> V_517 ,
struct V_1 ,
V_516 ) ;
F_268 ( & V_14 -> V_516 ) ;
F_6 ( V_14 ) ;
}
F_13 ( & V_13 -> V_515 ) ;
F_11 ( & V_13 -> V_18 ) ;
while ( ( V_30 = F_196 ( & V_13 -> V_19 ) ) != NULL ) {
V_14 = F_12 ( V_30 , struct V_1 ,
V_20 ) ;
F_189 ( & V_14 -> V_20 ,
& V_13 -> V_19 ) ;
F_516 ( & V_14 -> V_20 ) ;
F_13 ( & V_13 -> V_18 ) ;
F_68 ( & V_14 -> V_95 -> V_341 ) ;
F_190 ( & V_14 -> V_98 ) ;
F_70 ( & V_14 -> V_95 -> V_341 ) ;
if ( V_14 -> V_3 == V_106 )
F_412 ( V_14 ) ;
if ( V_14 -> V_3 == V_102 ||
V_14 -> V_3 == V_5 )
F_19 ( V_13 -> V_67 , V_14 ) ;
F_517 ( V_14 ) ;
F_6 ( V_14 ) ;
F_11 ( & V_13 -> V_18 ) ;
}
F_13 ( & V_13 -> V_18 ) ;
F_518 () ;
F_362 ( V_13 ) ;
while ( ! F_177 ( & V_13 -> V_95 ) ) {
int V_43 ;
V_95 = F_179 ( V_13 -> V_95 . V_86 ,
struct V_110 ,
V_98 ) ;
if ( F_256 ( V_13 -> V_92 , V_407 ) ) {
if ( F_8 ( V_95 -> V_342 > 0 ||
V_95 -> V_343 > 0 ||
V_95 -> V_345 > 0 ) ) {
F_313 ( V_95 , 0 , 0 ) ;
}
}
F_190 ( & V_95 -> V_98 ) ;
for ( V_43 = 0 ; V_43 < V_339 ; V_43 ++ ) {
struct V_689 * V_352 ;
V_352 = V_95 -> V_690 [ V_43 ] ;
V_95 -> V_690 [ V_43 ] = NULL ;
if ( V_352 ) {
F_519 ( V_352 ) ;
F_520 ( V_352 ) ;
}
}
F_519 ( & V_95 -> V_352 ) ;
F_520 ( & V_95 -> V_352 ) ;
}
return 0 ;
}
static void F_521 ( struct V_110 * V_95 ,
struct V_1 * V_2 )
{
int V_576 = F_414 ( V_2 ) ;
bool V_251 = false ;
F_68 ( & V_95 -> V_341 ) ;
if ( F_177 ( & V_95 -> V_340 [ V_576 ] ) )
V_251 = true ;
F_69 ( & V_2 -> V_98 , & V_95 -> V_340 [ V_576 ] ) ;
F_70 ( & V_95 -> V_341 ) ;
if ( V_251 ) {
struct V_691 * V_692 ;
int V_29 ;
V_692 = F_58 ( sizeof( * V_692 ) , V_40 ) ;
if ( ! V_692 )
goto V_693;
V_692 -> V_373 = V_576 ;
F_522 ( & V_692 -> V_352 , & V_694 ) ;
V_29 = F_523 ( & V_692 -> V_352 , & V_95 -> V_352 ,
L_8 , F_415 ( V_576 ) ) ;
if ( V_29 ) {
F_520 ( & V_692 -> V_352 ) ;
goto V_693;
}
V_95 -> V_690 [ V_576 ] = & V_692 -> V_352 ;
}
return;
V_693:
F_524 ( L_42 ) ;
}
static struct V_1 *
F_525 ( struct V_34 * V_35 , T_2 V_32 , T_2 V_61 )
{
struct V_1 * V_2 ;
V_2 = F_58 ( sizeof( * V_2 ) , V_40 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_11 = F_58 ( sizeof( * V_2 -> V_11 ) ,
V_40 ) ;
if ( ! V_2 -> V_11 ) {
F_9 ( V_2 ) ;
return NULL ;
}
V_2 -> V_21 . V_22 = V_32 ;
V_2 -> V_21 . V_33 = V_61 ;
V_2 -> V_21 . type = V_185 ;
V_2 -> V_57 = V_35 -> V_57 ;
V_2 -> V_37 = V_35 -> V_37 ;
V_2 -> V_695 = F_526 ( V_35 ,
& V_35 -> V_37 -> V_48 ,
V_32 ) ;
F_62 ( & V_2 -> V_8 , 1 ) ;
F_277 ( & V_2 -> V_52 ) ;
F_276 ( & V_2 -> V_567 ) ;
F_59 ( & V_2 -> V_98 ) ;
F_59 ( & V_2 -> V_696 ) ;
F_59 ( & V_2 -> V_516 ) ;
F_59 ( & V_2 -> V_676 ) ;
F_59 ( & V_2 -> V_324 ) ;
F_59 ( & V_2 -> V_325 ) ;
F_527 ( V_2 ) ;
F_62 ( & V_2 -> V_697 , 0 ) ;
return V_2 ;
}
int F_528 ( struct V_34 * V_35 )
{
struct V_68 * V_69 ;
int V_29 ;
struct V_1 * V_2 ;
struct V_12 * V_13 = V_35 -> V_37 ;
struct V_110 * V_95 ;
struct V_72 V_21 ;
struct V_72 V_146 ;
struct V_70 * V_71 ;
int V_698 = 0 ;
T_2 V_699 ;
V_35 = V_13 -> V_67 ;
V_21 . V_22 = 0 ;
V_21 . V_33 = 0 ;
V_21 . type = V_185 ;
V_69 = F_35 () ;
if ( ! V_69 )
return - V_76 ;
V_69 -> V_81 = 1 ;
V_699 = F_529 ( V_35 -> V_37 -> V_258 ) ;
if ( F_256 ( V_35 , V_307 ) &&
F_530 ( V_35 -> V_37 -> V_258 ) != V_699 )
V_698 = 1 ;
if ( F_256 ( V_35 , V_700 ) )
V_698 = 1 ;
while ( 1 ) {
V_29 = F_513 ( V_35 , V_69 , & V_21 ) ;
if ( V_29 > 0 )
break;
if ( V_29 != 0 )
goto error;
V_71 = V_69 -> V_88 [ 0 ] ;
F_44 ( V_71 , & V_146 , V_69 -> V_89 [ 0 ] ) ;
V_2 = F_525 ( V_35 , V_146 . V_22 ,
V_146 . V_33 ) ;
if ( ! V_2 ) {
V_29 = - V_76 ;
goto error;
}
if ( V_698 ) {
if ( F_256 ( V_35 , V_307 ) )
V_2 -> V_299 = V_315 ;
}
F_531 ( V_71 , & V_2 -> V_96 ,
F_244 ( V_71 , V_69 -> V_89 [ 0 ] ) ,
sizeof( V_2 -> V_96 ) ) ;
V_2 -> V_7 = F_532 ( & V_2 -> V_96 ) ;
V_21 . V_22 = V_146 . V_22 + V_146 . V_33 ;
F_48 ( V_69 ) ;
V_29 = F_21 ( V_35 , V_2 ) ;
if ( V_29 ) {
F_19 ( V_35 , V_2 ) ;
F_6 ( V_2 ) ;
goto error;
}
if ( V_146 . V_33 == F_54 ( & V_2 -> V_96 ) ) {
V_2 -> V_105 = ( T_2 ) - 1 ;
V_2 -> V_3 = V_4 ;
F_19 ( V_35 , V_2 ) ;
} else if ( F_54 ( & V_2 -> V_96 ) == 0 ) {
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
F_517 ( V_2 ) ;
F_6 ( V_2 ) ;
goto error;
}
V_29 = F_274 ( V_13 , V_2 -> V_7 , V_146 . V_33 ,
F_54 ( & V_2 -> V_96 ) ,
& V_95 ) ;
if ( V_29 ) {
F_517 ( V_2 ) ;
F_11 ( & V_13 -> V_18 ) ;
F_189 ( & V_2 -> V_20 ,
& V_13 -> V_19 ) ;
F_516 ( & V_2 -> V_20 ) ;
F_13 ( & V_13 -> V_18 ) ;
F_6 ( V_2 ) ;
goto error;
}
V_2 -> V_95 = V_95 ;
F_11 ( & V_2 -> V_95 -> V_52 ) ;
V_2 -> V_95 -> V_344 += V_2 -> V_46 ;
F_13 ( & V_2 -> V_95 -> V_52 ) ;
F_521 ( V_95 , V_2 ) ;
F_280 ( V_35 -> V_37 , V_2 -> V_7 ) ;
if ( F_533 ( V_35 , V_2 -> V_21 . V_22 ) ) {
F_503 ( V_2 , 1 ) ;
} else if ( F_54 ( & V_2 -> V_96 ) == 0 ) {
F_11 ( & V_13 -> V_515 ) ;
if ( F_177 ( & V_2 -> V_516 ) ) {
F_4 ( V_2 ) ;
F_69 ( & V_2 -> V_516 ,
& V_13 -> V_517 ) ;
}
F_13 ( & V_13 -> V_515 ) ;
}
}
F_76 (space_info, &root->fs_info->space_info, list) {
if ( ! ( F_287 ( V_35 , V_95 -> V_7 ) &
( V_334 |
V_333 |
V_380 |
V_379 |
V_332 ) ) )
continue;
F_178 (cache,
&space_info->block_groups[BTRFS_RAID_RAID0],
list)
F_503 ( V_2 , 1 ) ;
F_178 (cache,
&space_info->block_groups[BTRFS_RAID_SINGLE],
list)
F_503 ( V_2 , 1 ) ;
}
F_361 ( V_13 ) ;
V_29 = 0 ;
error:
F_55 ( V_69 ) ;
return V_29 ;
}
void F_219 ( struct V_116 * V_117 ,
struct V_34 * V_35 )
{
struct V_1 * V_14 , * V_311 ;
struct V_34 * V_67 = V_35 -> V_37 -> V_67 ;
struct V_701 V_96 ;
struct V_72 V_21 ;
int V_29 = 0 ;
bool V_274 = V_117 -> V_274 ;
V_117 -> V_274 = false ;
F_263 (block_group, tmp, &trans->new_bgs, bg_list) {
if ( V_29 )
goto V_86;
F_11 ( & V_14 -> V_52 ) ;
memcpy ( & V_96 , & V_14 -> V_96 , sizeof( V_96 ) ) ;
memcpy ( & V_21 , & V_14 -> V_21 , sizeof( V_21 ) ) ;
F_13 ( & V_14 -> V_52 ) ;
V_29 = F_534 ( V_117 , V_67 , & V_21 , & V_96 ,
sizeof( V_96 ) ) ;
if ( V_29 )
F_157 ( V_117 , V_67 , V_29 ) ;
V_29 = F_535 ( V_117 , V_67 ,
V_21 . V_22 , V_21 . V_33 ) ;
if ( V_29 )
F_157 ( V_117 , V_67 , V_29 ) ;
V_86:
F_268 ( & V_14 -> V_516 ) ;
}
V_117 -> V_274 = V_274 ;
}
int F_536 ( struct V_116 * V_117 ,
struct V_34 * V_35 , T_2 V_94 ,
T_2 type , T_2 V_702 , T_2 V_703 ,
T_2 V_61 )
{
int V_29 ;
struct V_34 * V_67 ;
struct V_1 * V_2 ;
V_67 = V_35 -> V_37 -> V_67 ;
F_537 ( V_35 -> V_37 , V_117 ) ;
V_2 = F_525 ( V_35 , V_703 , V_61 ) ;
if ( ! V_2 )
return - V_76 ;
F_384 ( & V_2 -> V_96 , V_94 ) ;
F_538 ( & V_2 -> V_96 , V_702 ) ;
F_539 ( & V_2 -> V_96 , type ) ;
V_2 -> V_7 = type ;
V_2 -> V_105 = ( T_2 ) - 1 ;
V_2 -> V_3 = V_4 ;
V_29 = F_21 ( V_35 , V_2 ) ;
if ( V_29 ) {
F_19 ( V_35 , V_2 ) ;
F_6 ( V_2 ) ;
return V_29 ;
}
F_29 ( V_2 , V_35 -> V_37 , V_703 ,
V_703 + V_61 ) ;
F_19 ( V_35 , V_2 ) ;
#ifdef F_37
if ( F_38 ( V_35 , V_2 ) ) {
T_2 V_704 = V_61 - V_94 ;
V_94 += V_704 >> 1 ;
F_27 ( V_35 , V_2 ) ;
}
#endif
V_29 = F_274 ( V_35 -> V_37 , V_2 -> V_7 , 0 , 0 ,
& V_2 -> V_95 ) ;
if ( V_29 ) {
F_517 ( V_2 ) ;
F_6 ( V_2 ) ;
return V_29 ;
}
V_29 = F_10 ( V_35 -> V_37 , V_2 ) ;
if ( V_29 ) {
F_517 ( V_2 ) ;
F_6 ( V_2 ) ;
return V_29 ;
}
V_29 = F_274 ( V_35 -> V_37 , V_2 -> V_7 , V_61 , V_94 ,
& V_2 -> V_95 ) ;
if ( V_29 ) {
F_517 ( V_2 ) ;
F_11 ( & V_35 -> V_37 -> V_18 ) ;
F_189 ( & V_2 -> V_20 ,
& V_35 -> V_37 -> V_19 ) ;
F_516 ( & V_2 -> V_20 ) ;
F_13 ( & V_35 -> V_37 -> V_18 ) ;
F_6 ( V_2 ) ;
return V_29 ;
}
F_360 ( V_35 -> V_37 ) ;
F_11 ( & V_2 -> V_95 -> V_52 ) ;
V_2 -> V_95 -> V_344 += V_2 -> V_46 ;
F_13 ( & V_2 -> V_95 -> V_52 ) ;
F_521 ( V_2 -> V_95 , V_2 ) ;
F_69 ( & V_2 -> V_516 , & V_117 -> V_276 ) ;
F_280 ( V_67 -> V_37 , type ) ;
return 0 ;
}
static void F_540 ( struct V_12 * V_37 , T_2 V_7 )
{
T_2 V_356 = F_281 ( V_7 ) &
V_357 ;
F_282 ( & V_37 -> V_358 ) ;
if ( V_7 & V_328 )
V_37 -> V_359 &= ~ V_356 ;
if ( V_7 & V_55 )
V_37 -> V_360 &= ~ V_356 ;
if ( V_7 & V_329 )
V_37 -> V_361 &= ~ V_356 ;
F_283 ( & V_37 -> V_358 ) ;
}
int F_541 ( struct V_116 * V_117 ,
struct V_34 * V_35 , T_2 V_705 ,
struct V_706 * V_707 )
{
struct V_68 * V_69 ;
struct V_1 * V_14 ;
struct V_527 * V_534 ;
struct V_34 * V_92 = V_35 -> V_37 -> V_92 ;
struct V_72 V_21 ;
struct V_293 * V_293 ;
struct V_689 * V_352 = NULL ;
int V_29 ;
int V_576 ;
int V_331 ;
struct V_50 * V_53 = NULL ;
bool V_708 ;
V_35 = V_35 -> V_37 -> V_67 ;
V_14 = F_73 ( V_35 -> V_37 , V_705 ) ;
F_32 ( ! V_14 ) ;
F_32 ( ! V_14 -> V_301 ) ;
F_19 ( V_35 , V_14 ) ;
memcpy ( & V_21 , & V_14 -> V_21 , sizeof( V_21 ) ) ;
V_576 = F_414 ( V_14 ) ;
if ( V_14 -> V_7 & ( V_332 |
V_333 |
V_334 ) )
V_331 = 2 ;
else
V_331 = 1 ;
V_534 = & V_35 -> V_37 -> V_532 ;
F_11 ( & V_534 -> V_570 ) ;
F_425 ( V_14 , V_534 ) ;
F_13 ( & V_534 -> V_570 ) ;
V_534 = & V_35 -> V_37 -> V_531 ;
F_11 ( & V_534 -> V_570 ) ;
F_425 ( V_14 , V_534 ) ;
F_13 ( & V_534 -> V_570 ) ;
V_69 = F_35 () ;
if ( ! V_69 ) {
V_29 = - V_76 ;
goto V_78;
}
V_293 = F_249 ( V_92 , V_14 , V_69 ) ;
F_39 ( & V_117 -> V_134 -> V_323 ) ;
F_11 ( & V_117 -> V_134 -> V_322 ) ;
if ( ! F_177 ( & V_14 -> V_325 ) ) {
F_268 ( & V_14 -> V_325 ) ;
F_8 ( ! F_209 ( V_293 ) && V_293 != V_14 -> V_326 . V_293 ) ;
F_13 ( & V_117 -> V_134 -> V_322 ) ;
F_269 ( V_35 , V_117 , V_14 ,
& V_14 -> V_326 , V_69 ,
V_14 -> V_21 . V_22 ) ;
F_6 ( V_14 ) ;
F_11 ( & V_117 -> V_134 -> V_322 ) ;
}
if ( ! F_177 ( & V_14 -> V_324 ) ) {
F_268 ( & V_14 -> V_324 ) ;
F_6 ( V_14 ) ;
}
F_13 ( & V_117 -> V_134 -> V_322 ) ;
F_50 ( & V_117 -> V_134 -> V_323 ) ;
if ( ! F_209 ( V_293 ) ) {
V_29 = F_542 ( V_117 , V_293 ) ;
if ( V_29 ) {
F_543 ( V_293 ) ;
goto V_78;
}
F_544 ( V_293 ) ;
F_11 ( & V_14 -> V_52 ) ;
if ( V_14 -> V_170 ) {
V_14 -> V_170 = 0 ;
V_14 -> V_293 = NULL ;
F_13 ( & V_14 -> V_52 ) ;
F_261 ( V_293 ) ;
} else {
F_13 ( & V_14 -> V_52 ) ;
}
F_543 ( V_293 ) ;
}
V_21 . V_22 = V_709 ;
V_21 . V_33 = V_14 -> V_21 . V_22 ;
V_21 . type = 0 ;
V_29 = F_41 ( V_117 , V_92 , & V_21 , V_69 , - 1 , 1 ) ;
if ( V_29 < 0 )
goto V_78;
if ( V_29 > 0 )
F_48 ( V_69 ) ;
if ( V_29 == 0 ) {
V_29 = F_121 ( V_117 , V_92 , V_69 ) ;
if ( V_29 )
goto V_78;
F_48 ( V_69 ) ;
}
F_11 ( & V_35 -> V_37 -> V_18 ) ;
F_189 ( & V_14 -> V_20 ,
& V_35 -> V_37 -> V_19 ) ;
F_516 ( & V_14 -> V_20 ) ;
if ( V_35 -> V_37 -> V_26 == V_14 -> V_21 . V_22 )
V_35 -> V_37 -> V_26 = ( T_2 ) - 1 ;
F_13 ( & V_35 -> V_37 -> V_18 ) ;
F_68 ( & V_14 -> V_95 -> V_341 ) ;
F_268 ( & V_14 -> V_98 ) ;
if ( F_177 ( & V_14 -> V_95 -> V_340 [ V_576 ] ) ) {
V_352 = V_14 -> V_95 -> V_690 [ V_576 ] ;
V_14 -> V_95 -> V_690 [ V_576 ] = NULL ;
F_540 ( V_35 -> V_37 , V_14 -> V_7 ) ;
}
F_70 ( & V_14 -> V_95 -> V_341 ) ;
if ( V_352 ) {
F_519 ( V_352 ) ;
F_520 ( V_352 ) ;
}
if ( V_14 -> V_107 )
V_53 = F_25 ( V_14 ) ;
if ( V_14 -> V_3 == V_106 )
F_412 ( V_14 ) ;
if ( V_14 -> V_107 ) {
F_68 ( & V_35 -> V_37 -> V_85 ) ;
if ( ! V_53 ) {
struct V_50 * V_51 ;
F_178 (ctl,
&root->fs_info->caching_block_groups, list)
if ( V_51 -> V_14 == V_14 ) {
V_53 = V_51 ;
F_5 ( & V_53 -> V_8 ) ;
break;
}
}
if ( V_53 )
F_268 ( & V_53 -> V_98 ) ;
F_70 ( & V_35 -> V_37 -> V_85 ) ;
if ( V_53 ) {
F_26 ( V_53 ) ;
F_26 ( V_53 ) ;
}
}
F_11 ( & V_117 -> V_134 -> V_322 ) ;
if ( ! F_177 ( & V_14 -> V_324 ) ) {
F_8 ( 1 ) ;
}
if ( ! F_177 ( & V_14 -> V_325 ) ) {
F_8 ( 1 ) ;
}
F_13 ( & V_117 -> V_134 -> V_322 ) ;
F_517 ( V_14 ) ;
F_11 ( & V_14 -> V_95 -> V_52 ) ;
F_268 ( & V_14 -> V_676 ) ;
if ( F_256 ( V_35 , V_407 ) ) {
F_8 ( V_14 -> V_95 -> V_330
< V_14 -> V_21 . V_33 ) ;
F_8 ( V_14 -> V_95 -> V_344
< V_14 -> V_21 . V_33 ) ;
F_8 ( V_14 -> V_95 -> V_335
< V_14 -> V_21 . V_33 * V_331 ) ;
}
V_14 -> V_95 -> V_330 -= V_14 -> V_21 . V_33 ;
V_14 -> V_95 -> V_344 -= V_14 -> V_21 . V_33 ;
V_14 -> V_95 -> V_335 -= V_14 -> V_21 . V_33 * V_331 ;
F_13 ( & V_14 -> V_95 -> V_52 ) ;
memcpy ( & V_21 , & V_14 -> V_21 , sizeof( V_21 ) ) ;
F_506 ( V_35 ) ;
if ( ! F_177 ( & V_707 -> V_98 ) ) {
F_545 ( V_707 ) ;
}
F_11 ( & V_14 -> V_52 ) ;
V_14 -> V_710 = 1 ;
V_708 = ( F_206 ( & V_14 -> V_697 ) == 0 ) ;
if ( ! V_708 ) {
F_546 ( & V_707 -> V_98 , & V_35 -> V_37 -> V_711 ) ;
}
F_13 ( & V_14 -> V_52 ) ;
if ( V_708 ) {
struct V_712 * V_713 ;
V_713 = & V_35 -> V_37 -> V_48 . V_714 ;
F_547 ( & V_713 -> V_52 ) ;
F_548 ( V_713 , V_707 ) ;
F_549 ( & V_713 -> V_52 ) ;
F_545 ( V_707 ) ;
}
F_507 ( V_35 ) ;
F_6 ( V_14 ) ;
F_6 ( V_14 ) ;
V_29 = F_41 ( V_117 , V_35 , & V_21 , V_69 , - 1 , 1 ) ;
if ( V_29 > 0 )
V_29 = - V_181 ;
if ( V_29 < 0 )
goto V_78;
V_29 = F_121 ( V_117 , V_35 , V_69 ) ;
V_78:
F_55 ( V_69 ) ;
return V_29 ;
}
struct V_116 *
F_550 ( struct V_12 * V_37 ,
const T_2 V_703 )
{
struct V_712 * V_713 = & V_37 -> V_48 . V_714 ;
struct V_706 * V_707 ;
struct V_715 * V_716 ;
unsigned int V_717 ;
F_551 ( & V_713 -> V_52 ) ;
V_707 = F_552 ( V_713 , V_703 , 1 ) ;
F_553 ( & V_713 -> V_52 ) ;
ASSERT ( V_707 && V_707 -> V_32 == V_703 ) ;
V_716 = (struct V_715 * ) V_707 -> V_192 ;
V_717 = 3 + V_716 -> V_208 ;
F_545 ( V_707 ) ;
return F_554 ( V_37 -> V_67 ,
V_717 , 1 ) ;
}
void F_555 ( struct V_12 * V_37 )
{
struct V_1 * V_14 ;
struct V_110 * V_95 ;
struct V_34 * V_35 = V_37 -> V_67 ;
struct V_116 * V_117 ;
int V_29 = 0 ;
if ( ! V_37 -> V_718 )
return;
F_11 ( & V_37 -> V_515 ) ;
while ( ! F_177 ( & V_37 -> V_517 ) ) {
T_2 V_32 , V_31 ;
int V_697 ;
V_14 = F_267 ( & V_37 -> V_517 ,
struct V_1 ,
V_516 ) ;
F_268 ( & V_14 -> V_516 ) ;
V_95 = V_14 -> V_95 ;
if ( V_29 || F_316 ( V_95 ) ) {
F_6 ( V_14 ) ;
continue;
}
F_13 ( & V_37 -> V_515 ) ;
F_39 ( & V_37 -> V_719 ) ;
F_68 ( & V_95 -> V_341 ) ;
F_11 ( & V_14 -> V_52 ) ;
if ( V_14 -> V_10 ||
F_54 ( & V_14 -> V_96 ) ||
V_14 -> V_301 ||
F_556 ( & V_14 -> V_98 ) ) {
F_13 ( & V_14 -> V_52 ) ;
F_70 ( & V_95 -> V_341 ) ;
goto V_86;
}
F_13 ( & V_14 -> V_52 ) ;
V_29 = F_503 ( V_14 , 0 ) ;
F_70 ( & V_95 -> V_341 ) ;
if ( V_29 < 0 ) {
V_29 = 0 ;
goto V_86;
}
V_117 = F_550 ( V_37 ,
V_14 -> V_21 . V_22 ) ;
if ( F_209 ( V_117 ) ) {
F_510 ( V_35 , V_14 ) ;
V_29 = F_210 ( V_117 ) ;
goto V_86;
}
V_32 = V_14 -> V_21 . V_22 ;
V_31 = V_32 + V_14 -> V_21 . V_33 - 1 ;
F_39 ( & V_37 -> V_540 ) ;
V_29 = F_20 ( & V_37 -> V_38 [ 0 ] , V_32 , V_31 ,
V_64 , V_40 ) ;
if ( V_29 ) {
F_50 ( & V_37 -> V_540 ) ;
F_510 ( V_35 , V_14 ) ;
goto V_720;
}
V_29 = F_20 ( & V_37 -> V_38 [ 1 ] , V_32 , V_31 ,
V_64 , V_40 ) ;
if ( V_29 ) {
F_50 ( & V_37 -> V_540 ) ;
F_510 ( V_35 , V_14 ) ;
goto V_720;
}
F_50 ( & V_37 -> V_540 ) ;
F_11 ( & V_95 -> V_52 ) ;
F_11 ( & V_14 -> V_52 ) ;
V_95 -> V_342 -= V_14 -> V_9 ;
V_95 -> V_344 += V_14 -> V_9 ;
F_395 ( & V_95 -> V_337 ,
- V_14 -> V_9 ) ;
V_14 -> V_9 = 0 ;
F_13 ( & V_14 -> V_52 ) ;
F_13 ( & V_95 -> V_52 ) ;
V_697 = F_256 ( V_35 , V_541 ) ;
if ( V_697 )
F_557 ( V_14 ) ;
V_29 = F_558 ( V_117 , V_35 ,
V_14 -> V_21 . V_22 ) ;
if ( V_29 ) {
if ( V_697 )
F_398 ( V_14 ) ;
goto V_720;
}
if ( V_697 ) {
F_11 ( & V_37 -> V_515 ) ;
F_559 ( & V_14 -> V_516 ,
& V_117 -> V_134 -> V_537 ) ;
F_13 ( & V_37 -> V_515 ) ;
F_4 ( V_14 ) ;
}
V_720:
F_212 ( V_117 , V_35 ) ;
V_86:
F_50 ( & V_37 -> V_719 ) ;
F_6 ( V_14 ) ;
F_11 ( & V_37 -> V_515 ) ;
}
F_13 ( & V_37 -> V_515 ) ;
}
int F_560 ( struct V_12 * V_37 )
{
struct V_110 * V_95 ;
struct V_721 * V_722 ;
T_2 V_723 ;
T_2 V_7 ;
int V_724 = 0 ;
int V_29 ;
V_722 = V_37 -> V_258 ;
if ( ! F_561 ( V_722 ) )
return 1 ;
V_723 = F_562 ( V_722 ) ;
if ( V_723 & V_725 )
V_724 = 1 ;
V_7 = V_329 ;
V_29 = F_274 ( V_37 , V_7 , 0 , 0 , & V_95 ) ;
if ( V_29 )
goto V_78;
if ( V_724 ) {
V_7 = V_55 | V_328 ;
V_29 = F_274 ( V_37 , V_7 , 0 , 0 , & V_95 ) ;
} else {
V_7 = V_55 ;
V_29 = F_274 ( V_37 , V_7 , 0 , 0 , & V_95 ) ;
if ( V_29 )
goto V_78;
V_7 = V_328 ;
V_29 = F_274 ( V_37 , V_7 , 0 , 0 , & V_95 ) ;
}
V_78:
return V_29 ;
}
int F_563 ( struct V_34 * V_35 , T_2 V_32 , T_2 V_31 )
{
return F_394 ( V_35 , V_32 , V_31 , false ) ;
}
static int F_564 ( struct V_682 * V_683 ,
T_2 V_726 , T_2 * V_542 )
{
T_2 V_32 = 0 , V_49 = 0 ;
int V_29 ;
* V_542 = 0 ;
if ( ! V_683 -> V_727 )
return 0 ;
if ( V_683 -> V_330 <= V_683 -> V_94 )
return 0 ;
V_29 = 0 ;
while ( 1 ) {
struct V_12 * V_37 = V_683 -> V_485 -> V_37 ;
struct V_312 * V_117 ;
T_2 V_209 ;
V_29 = F_565 ( & V_37 -> V_406 ) ;
if ( V_29 )
return V_29 ;
F_40 ( & V_37 -> V_85 ) ;
F_11 ( & V_37 -> V_728 ) ;
V_117 = V_37 -> V_729 ;
if ( V_117 )
F_5 ( & V_117 -> V_730 ) ;
F_13 ( & V_37 -> V_728 ) ;
V_29 = F_566 ( V_117 , V_683 , V_726 , V_32 ,
& V_32 , & V_49 ) ;
if ( V_117 )
F_567 ( V_117 ) ;
if ( V_29 ) {
F_49 ( & V_37 -> V_85 ) ;
F_50 ( & V_37 -> V_406 ) ;
if ( V_29 == - V_309 )
V_29 = 0 ;
break;
}
V_29 = F_145 ( V_683 -> V_192 , V_32 , V_49 , & V_209 ) ;
F_49 ( & V_37 -> V_85 ) ;
F_50 ( & V_37 -> V_406 ) ;
if ( V_29 )
break;
V_32 += V_49 ;
* V_542 += V_209 ;
if ( F_568 ( V_388 ) ) {
V_29 = - V_731 ;
break;
}
F_51 () ;
}
return V_29 ;
}
int F_569 ( struct V_34 * V_35 , struct V_732 * V_733 )
{
struct V_12 * V_37 = V_35 -> V_37 ;
struct V_1 * V_2 = NULL ;
struct V_682 * V_683 ;
struct V_111 * V_734 ;
T_2 V_735 ;
T_2 V_32 ;
T_2 V_31 ;
T_2 V_542 = 0 ;
T_2 V_330 = F_305 ( V_37 -> V_258 ) ;
int V_29 = 0 ;
if ( V_733 -> V_49 == V_330 )
V_2 = F_72 ( V_37 , V_733 -> V_32 ) ;
else
V_2 = F_73 ( V_37 , V_733 -> V_32 ) ;
while ( V_2 ) {
if ( V_2 -> V_21 . V_22 >= ( V_733 -> V_32 + V_733 -> V_49 ) ) {
F_6 ( V_2 ) ;
break;
}
V_32 = F_422 ( V_733 -> V_32 , V_2 -> V_21 . V_22 ) ;
V_31 = F_326 ( V_733 -> V_32 + V_733 -> V_49 ,
V_2 -> V_21 . V_22 + V_2 -> V_21 . V_33 ) ;
if ( V_31 - V_32 >= V_733 -> V_726 ) {
if ( ! F_1 ( V_2 ) ) {
V_29 = F_56 ( V_2 , 0 ) ;
if ( V_29 ) {
F_6 ( V_2 ) ;
break;
}
V_29 = F_412 ( V_2 ) ;
if ( V_29 ) {
F_6 ( V_2 ) ;
break;
}
}
V_29 = F_570 ( V_2 ,
& V_735 ,
V_32 ,
V_31 ,
V_733 -> V_726 ) ;
V_542 += V_735 ;
if ( V_29 ) {
F_6 ( V_2 ) ;
break;
}
}
V_2 = F_246 ( V_37 -> V_92 , V_2 ) ;
}
F_39 ( & V_35 -> V_37 -> V_371 -> V_736 ) ;
V_734 = & V_35 -> V_37 -> V_371 -> V_737 ;
F_178 (device, devices, dev_alloc_list) {
V_29 = F_564 ( V_683 , V_733 -> V_726 ,
& V_735 ) ;
if ( V_29 )
break;
V_542 += V_735 ;
}
F_50 ( & V_35 -> V_37 -> V_371 -> V_736 ) ;
V_733 -> V_49 = V_542 ;
return V_29 ;
}
void F_571 ( struct V_34 * V_35 )
{
F_572 ( & V_35 -> V_738 -> V_739 ) ;
F_2 () ;
if ( F_573 ( & V_35 -> V_738 -> V_93 ) )
F_53 ( & V_35 -> V_738 -> V_93 ) ;
}
int F_574 ( struct V_34 * V_35 )
{
if ( F_206 ( & V_35 -> V_740 ) )
return 0 ;
F_575 ( & V_35 -> V_738 -> V_739 ) ;
F_2 () ;
if ( F_206 ( & V_35 -> V_740 ) ) {
F_571 ( V_35 ) ;
return 0 ;
}
return 1 ;
}
