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
V_29 = F_23 ( & V_35 -> V_37 -> V_47 ,
V_2 -> V_21 . V_22 , V_27 ,
0 , & V_40 , & V_43 , & V_41 ) ;
if ( V_29 )
return V_29 ;
while ( V_43 -- ) {
T_2 V_32 , V_48 ;
if ( V_40 [ V_43 ] > V_2 -> V_21 . V_22 +
V_2 -> V_21 . V_33 )
continue;
if ( V_40 [ V_43 ] + V_41 <= V_2 -> V_21 . V_22 )
continue;
V_32 = V_40 [ V_43 ] ;
if ( V_32 < V_2 -> V_21 . V_22 ) {
V_32 = V_2 -> V_21 . V_22 ;
V_48 = ( V_40 [ V_43 ] + V_41 ) - V_32 ;
} else {
V_48 = F_24 ( T_2 , V_41 ,
V_2 -> V_21 . V_22 +
V_2 -> V_21 . V_33 - V_32 ) ;
}
V_2 -> V_45 += V_48 ;
V_29 = F_17 ( V_35 , V_32 , V_48 ) ;
if ( V_29 ) {
F_9 ( V_40 ) ;
return V_29 ;
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
if ( ! V_2 -> V_52 ) {
F_13 ( & V_2 -> V_51 ) ;
return NULL ;
}
V_50 = V_2 -> V_52 ;
F_5 ( & V_50 -> V_8 ) ;
F_13 ( & V_2 -> V_51 ) ;
return V_50 ;
}
static void F_26 ( struct V_49 * V_50 )
{
if ( F_7 ( & V_50 -> V_8 ) )
F_9 ( V_50 ) ;
}
static void F_27 ( struct V_34 * V_35 ,
struct V_1 * V_14 )
{
T_2 V_32 = V_14 -> V_21 . V_22 ;
T_2 V_48 = V_14 -> V_21 . V_33 ;
T_2 V_53 = V_14 -> V_7 & V_54 ?
V_35 -> V_55 : V_35 -> V_56 ;
T_2 V_57 = V_53 << 1 ;
while ( V_48 > V_53 ) {
F_28 ( V_14 , V_32 , V_53 ) ;
V_32 += V_57 ;
if ( V_48 < V_57 )
V_48 = 0 ;
else
V_48 -= V_57 ;
}
}
T_2 F_29 ( struct V_1 * V_14 ,
struct V_12 * V_13 , T_2 V_32 , T_2 V_31 )
{
T_2 V_58 , V_59 , V_60 , V_61 = 0 ;
int V_29 ;
while ( V_32 < V_31 ) {
V_29 = F_30 ( V_13 -> V_62 , V_32 ,
& V_58 , & V_59 ,
V_63 | V_39 ,
NULL ) ;
if ( V_29 )
break;
if ( V_58 <= V_32 ) {
V_32 = V_59 + 1 ;
} else if ( V_58 > V_32 && V_58 < V_31 ) {
V_60 = V_58 - V_32 ;
V_61 += V_60 ;
V_29 = F_31 ( V_14 , V_32 ,
V_60 ) ;
F_32 ( V_29 ) ;
V_32 = V_59 + 1 ;
} else {
break;
}
}
if ( V_32 < V_31 ) {
V_60 = V_31 - V_32 ;
V_61 += V_60 ;
V_29 = F_31 ( V_14 , V_32 , V_60 ) ;
F_32 ( V_29 ) ;
}
return V_61 ;
}
static int F_33 ( struct V_49 * V_52 )
{
struct V_1 * V_14 ;
struct V_12 * V_37 ;
struct V_34 * V_64 ;
struct V_65 * V_66 ;
struct V_67 * V_68 ;
struct V_69 V_21 ;
T_2 V_70 = 0 ;
T_2 V_71 = 0 ;
T_3 V_72 ;
int V_29 ;
bool V_73 = true ;
V_14 = V_52 -> V_14 ;
V_37 = V_14 -> V_37 ;
V_64 = V_37 -> V_64 ;
V_66 = F_34 () ;
if ( ! V_66 )
return - V_74 ;
V_71 = F_35 ( T_2 , V_14 -> V_21 . V_22 , V_44 ) ;
#ifdef F_36
if ( F_37 ( V_64 , V_14 ) )
V_73 = false ;
#endif
V_66 -> V_75 = 1 ;
V_66 -> V_76 = 1 ;
V_66 -> V_77 = V_78 ;
V_21 . V_22 = V_71 ;
V_21 . V_33 = 0 ;
V_21 . type = V_79 ;
V_80:
V_29 = F_38 ( NULL , V_64 , & V_21 , V_66 , 0 , 0 ) ;
if ( V_29 < 0 )
goto V_81;
V_68 = V_66 -> V_82 [ 0 ] ;
V_72 = F_39 ( V_68 ) ;
while ( 1 ) {
if ( F_40 ( V_37 ) > 1 ) {
V_71 = ( T_2 ) - 1 ;
break;
}
if ( V_66 -> V_83 [ 0 ] < V_72 ) {
F_41 ( V_68 , & V_21 , V_66 -> V_83 [ 0 ] ) ;
} else {
V_29 = F_42 ( V_66 , 0 , & V_21 ) ;
if ( V_29 )
break;
if ( F_43 () ||
F_44 ( & V_37 -> V_84 ) ) {
if ( V_73 )
V_52 -> V_85 = V_71 ;
F_45 ( V_66 ) ;
F_46 ( & V_37 -> V_84 ) ;
F_47 ( & V_52 -> V_86 ) ;
F_48 () ;
F_49 ( & V_52 -> V_86 ) ;
F_50 ( & V_37 -> V_84 ) ;
goto V_80;
}
V_29 = F_51 ( V_64 , V_66 ) ;
if ( V_29 < 0 )
goto V_81;
if ( V_29 )
break;
V_68 = V_66 -> V_82 [ 0 ] ;
V_72 = F_39 ( V_68 ) ;
continue;
}
if ( V_21 . V_22 < V_71 ) {
V_21 . V_22 = V_71 ;
V_21 . V_33 = 0 ;
V_21 . type = V_79 ;
if ( V_73 )
V_52 -> V_85 = V_71 ;
F_45 ( V_66 ) ;
goto V_80;
}
if ( V_21 . V_22 < V_14 -> V_21 . V_22 ) {
V_66 -> V_83 [ 0 ] ++ ;
continue;
}
if ( V_21 . V_22 >= V_14 -> V_21 . V_22 +
V_14 -> V_21 . V_33 )
break;
if ( V_21 . type == V_79 ||
V_21 . type == V_87 ) {
V_70 += F_29 ( V_14 ,
V_37 , V_71 ,
V_21 . V_22 ) ;
if ( V_21 . type == V_87 )
V_71 = V_21 . V_22 +
V_37 -> V_88 -> V_55 ;
else
V_71 = V_21 . V_22 + V_21 . V_33 ;
if ( V_70 > V_89 ) {
V_70 = 0 ;
if ( V_73 )
F_52 ( & V_52 -> V_90 ) ;
}
}
V_66 -> V_83 [ 0 ] ++ ;
}
V_29 = 0 ;
V_70 += F_29 ( V_14 , V_37 , V_71 ,
V_14 -> V_21 . V_22 +
V_14 -> V_21 . V_33 ) ;
V_52 -> V_85 = ( T_2 ) - 1 ;
V_81:
F_53 ( V_66 ) ;
return V_29 ;
}
static T_1 void F_54 ( struct V_91 * V_92 )
{
struct V_1 * V_14 ;
struct V_12 * V_37 ;
struct V_49 * V_52 ;
struct V_34 * V_64 ;
int V_29 ;
V_52 = F_55 ( V_92 , struct V_49 , V_92 ) ;
V_14 = V_52 -> V_14 ;
V_37 = V_14 -> V_37 ;
V_64 = V_37 -> V_64 ;
F_49 ( & V_52 -> V_86 ) ;
F_50 ( & V_37 -> V_84 ) ;
if ( F_56 ( V_37 , V_93 ) )
V_29 = F_57 ( V_52 ) ;
else
V_29 = F_33 ( V_52 ) ;
F_11 ( & V_14 -> V_51 ) ;
V_14 -> V_52 = NULL ;
V_14 -> V_3 = V_29 ? V_5 : V_4 ;
F_13 ( & V_14 -> V_51 ) ;
#ifdef F_36
if ( F_37 ( V_64 , V_14 ) ) {
T_2 V_94 ;
F_11 ( & V_14 -> V_95 -> V_51 ) ;
F_11 ( & V_14 -> V_51 ) ;
V_94 = V_14 -> V_21 . V_33 -
F_58 ( & V_14 -> V_96 ) ;
V_14 -> V_95 -> V_94 += V_94 >> 1 ;
F_13 ( & V_14 -> V_51 ) ;
F_13 ( & V_14 -> V_95 -> V_51 ) ;
F_27 ( V_64 , V_14 ) ;
}
#endif
V_52 -> V_85 = ( T_2 ) - 1 ;
F_46 ( & V_37 -> V_84 ) ;
F_19 ( V_37 -> V_64 , V_14 ) ;
F_47 ( & V_52 -> V_86 ) ;
F_52 ( & V_52 -> V_90 ) ;
F_26 ( V_52 ) ;
F_6 ( V_14 ) ;
}
static int F_59 ( struct V_1 * V_2 ,
int V_97 )
{
F_60 ( V_90 ) ;
struct V_12 * V_37 = V_2 -> V_37 ;
struct V_49 * V_52 ;
int V_29 = 0 ;
V_52 = F_61 ( sizeof( * V_52 ) , V_98 ) ;
if ( ! V_52 )
return - V_74 ;
F_62 ( & V_52 -> V_99 ) ;
F_63 ( & V_52 -> V_86 ) ;
F_64 ( & V_52 -> V_90 ) ;
V_52 -> V_14 = V_2 ;
V_52 -> V_85 = V_2 -> V_21 . V_22 ;
F_65 ( & V_52 -> V_8 , 1 ) ;
F_66 ( & V_52 -> V_92 , V_100 ,
F_54 , NULL , NULL ) ;
F_11 ( & V_2 -> V_51 ) ;
while ( V_2 -> V_3 == V_101 ) {
struct V_49 * V_50 ;
V_50 = V_2 -> V_52 ;
F_5 ( & V_50 -> V_8 ) ;
F_67 ( & V_50 -> V_90 , & V_90 , V_102 ) ;
F_13 ( & V_2 -> V_51 ) ;
F_68 () ;
F_69 ( & V_50 -> V_90 , & V_90 ) ;
F_26 ( V_50 ) ;
F_11 ( & V_2 -> V_51 ) ;
}
if ( V_2 -> V_3 != V_103 ) {
F_13 ( & V_2 -> V_51 ) ;
F_9 ( V_52 ) ;
return 0 ;
}
F_8 ( V_2 -> V_52 ) ;
V_2 -> V_52 = V_52 ;
V_2 -> V_3 = V_101 ;
F_13 ( & V_2 -> V_51 ) ;
if ( V_37 -> V_104 & V_105 ) {
F_49 ( & V_52 -> V_86 ) ;
V_29 = F_70 ( V_37 , V_2 ) ;
F_11 ( & V_2 -> V_51 ) ;
if ( V_29 == 1 ) {
V_2 -> V_52 = NULL ;
V_2 -> V_3 = V_4 ;
V_2 -> V_106 = ( T_2 ) - 1 ;
V_52 -> V_85 = ( T_2 ) - 1 ;
} else {
if ( V_97 ) {
V_2 -> V_52 = NULL ;
V_2 -> V_3 = V_103 ;
} else {
V_2 -> V_3 = V_107 ;
V_2 -> V_108 = 1 ;
}
}
F_13 ( & V_2 -> V_51 ) ;
#ifdef F_36
if ( V_29 == 1 &&
F_37 ( V_37 -> V_64 ,
V_2 ) ) {
T_2 V_94 ;
F_11 ( & V_2 -> V_95 -> V_51 ) ;
F_11 ( & V_2 -> V_51 ) ;
V_94 = V_2 -> V_21 . V_33 -
F_58 ( & V_2 -> V_96 ) ;
V_2 -> V_95 -> V_94 += V_94 >> 1 ;
F_13 ( & V_2 -> V_51 ) ;
F_13 ( & V_2 -> V_95 -> V_51 ) ;
F_27 ( V_37 -> V_64 , V_2 ) ;
}
#endif
F_47 ( & V_52 -> V_86 ) ;
F_52 ( & V_52 -> V_90 ) ;
if ( V_29 == 1 ) {
F_26 ( V_52 ) ;
F_19 ( V_37 -> V_64 , V_2 ) ;
return 0 ;
}
} else {
F_11 ( & V_2 -> V_51 ) ;
if ( V_97 ) {
V_2 -> V_52 = NULL ;
V_2 -> V_3 = V_103 ;
} else {
V_2 -> V_3 = V_107 ;
V_2 -> V_108 = 1 ;
}
F_13 ( & V_2 -> V_51 ) ;
F_52 ( & V_52 -> V_90 ) ;
}
if ( V_97 ) {
F_26 ( V_52 ) ;
return 0 ;
}
F_71 ( & V_37 -> V_84 ) ;
F_5 ( & V_52 -> V_8 ) ;
F_72 ( & V_52 -> V_99 , & V_37 -> V_109 ) ;
F_73 ( & V_37 -> V_84 ) ;
F_4 ( V_2 ) ;
F_74 ( V_37 -> V_110 , & V_52 -> V_92 ) ;
return V_29 ;
}
static struct V_1 *
F_75 ( struct V_12 * V_13 , T_2 V_27 )
{
struct V_1 * V_2 ;
V_2 = F_16 ( V_13 , V_27 , 0 ) ;
return V_2 ;
}
struct V_1 * F_76 (
struct V_12 * V_13 ,
T_2 V_27 )
{
struct V_1 * V_2 ;
V_2 = F_16 ( V_13 , V_27 , 1 ) ;
return V_2 ;
}
static struct V_111 * F_77 ( struct V_12 * V_13 ,
T_2 V_7 )
{
struct V_112 * V_113 = & V_13 -> V_95 ;
struct V_111 * V_114 ;
V_7 &= V_115 ;
F_78 () ;
F_79 (found, head, list) {
if ( V_114 -> V_7 & V_7 ) {
F_80 () ;
return V_114 ;
}
}
F_80 () ;
return NULL ;
}
void F_81 ( struct V_12 * V_13 )
{
struct V_112 * V_113 = & V_13 -> V_95 ;
struct V_111 * V_114 ;
F_78 () ;
F_79 (found, head, list)
V_114 -> V_116 = 0 ;
F_80 () ;
}
int F_82 ( struct V_34 * V_35 , T_2 V_32 , T_2 V_48 )
{
int V_29 ;
struct V_69 V_21 ;
struct V_65 * V_66 ;
V_66 = F_34 () ;
if ( ! V_66 )
return - V_74 ;
V_21 . V_22 = V_32 ;
V_21 . V_33 = V_48 ;
V_21 . type = V_79 ;
V_29 = F_38 ( NULL , V_35 -> V_37 -> V_64 , & V_21 , V_66 ,
0 , 0 ) ;
F_53 ( V_66 ) ;
return V_29 ;
}
int F_83 ( struct V_117 * V_118 ,
struct V_34 * V_35 , T_2 V_27 ,
T_2 V_33 , int V_119 , T_2 * V_120 , T_2 * V_7 )
{
struct V_121 * V_113 ;
struct V_122 * V_123 ;
struct V_65 * V_66 ;
struct V_124 * V_125 ;
struct V_67 * V_68 ;
struct V_69 V_21 ;
T_3 V_126 ;
T_2 V_127 ;
T_2 V_128 ;
int V_29 ;
if ( V_119 && ! F_84 ( V_35 -> V_37 , V_129 ) ) {
V_33 = V_35 -> V_55 ;
V_119 = 0 ;
}
V_66 = F_34 () ;
if ( ! V_66 )
return - V_74 ;
if ( ! V_118 ) {
V_66 -> V_75 = 1 ;
V_66 -> V_76 = 1 ;
}
V_130:
V_21 . V_22 = V_27 ;
V_21 . V_33 = V_33 ;
if ( V_119 )
V_21 . type = V_87 ;
else
V_21 . type = V_79 ;
V_29 = F_38 ( V_118 , V_35 -> V_37 -> V_64 ,
& V_21 , V_66 , 0 , 0 ) ;
if ( V_29 < 0 )
goto V_131;
if ( V_29 > 0 && V_119 && V_21 . type == V_87 ) {
if ( V_66 -> V_83 [ 0 ] ) {
V_66 -> V_83 [ 0 ] -- ;
F_41 ( V_66 -> V_82 [ 0 ] , & V_21 ,
V_66 -> V_83 [ 0 ] ) ;
if ( V_21 . V_22 == V_27 &&
V_21 . type == V_79 &&
V_21 . V_33 == V_35 -> V_55 )
V_29 = 0 ;
}
}
if ( V_29 == 0 ) {
V_68 = V_66 -> V_82 [ 0 ] ;
V_126 = F_85 ( V_68 , V_66 -> V_83 [ 0 ] ) ;
if ( V_126 >= sizeof( * V_125 ) ) {
V_125 = F_86 ( V_68 , V_66 -> V_83 [ 0 ] ,
struct V_124 ) ;
V_127 = F_87 ( V_68 , V_125 ) ;
V_128 = F_88 ( V_68 , V_125 ) ;
} else {
#ifdef F_89
struct V_132 * V_133 ;
F_32 ( V_126 != sizeof( * V_133 ) ) ;
V_133 = F_86 ( V_68 , V_66 -> V_83 [ 0 ] ,
struct V_132 ) ;
V_127 = F_90 ( V_68 , V_133 ) ;
V_128 = V_134 ;
#else
F_91 () ;
#endif
}
F_32 ( V_127 == 0 ) ;
} else {
V_127 = 0 ;
V_128 = 0 ;
V_29 = 0 ;
}
if ( ! V_118 )
goto V_81;
V_123 = & V_118 -> V_135 -> V_123 ;
F_11 ( & V_123 -> V_51 ) ;
V_113 = F_92 ( V_118 , V_27 ) ;
if ( V_113 ) {
if ( ! F_93 ( & V_113 -> V_86 ) ) {
F_5 ( & V_113 -> V_136 . V_120 ) ;
F_13 ( & V_123 -> V_51 ) ;
F_45 ( V_66 ) ;
F_49 ( & V_113 -> V_86 ) ;
F_47 ( & V_113 -> V_86 ) ;
F_94 ( & V_113 -> V_136 ) ;
goto V_130;
}
F_11 ( & V_113 -> V_51 ) ;
if ( V_113 -> V_137 && V_113 -> V_137 -> V_138 )
V_128 |= V_113 -> V_137 -> V_139 ;
else
F_32 ( V_127 == 0 ) ;
V_127 += V_113 -> V_136 . V_140 ;
F_13 ( & V_113 -> V_51 ) ;
F_47 ( & V_113 -> V_86 ) ;
}
F_13 ( & V_123 -> V_51 ) ;
V_81:
F_8 ( V_127 == 0 ) ;
if ( V_120 )
* V_120 = V_127 ;
if ( V_7 )
* V_7 = V_128 ;
V_131:
F_53 ( V_66 ) ;
return V_29 ;
}
static int F_95 ( struct V_117 * V_118 ,
struct V_34 * V_35 ,
struct V_65 * V_66 ,
T_2 V_141 , T_3 V_142 )
{
struct V_124 * V_96 ;
struct V_132 * V_133 ;
struct V_143 * V_144 ;
struct V_145 * V_146 ;
struct V_67 * V_68 ;
struct V_69 V_21 ;
struct V_69 V_147 ;
T_3 V_148 = sizeof( * V_96 ) ;
T_2 V_120 ;
int V_29 ;
V_68 = V_66 -> V_82 [ 0 ] ;
F_32 ( F_85 ( V_68 , V_66 -> V_83 [ 0 ] ) != sizeof( * V_133 ) ) ;
F_41 ( V_68 , & V_21 , V_66 -> V_83 [ 0 ] ) ;
V_133 = F_86 ( V_68 , V_66 -> V_83 [ 0 ] ,
struct V_132 ) ;
V_120 = F_90 ( V_68 , V_133 ) ;
if ( V_141 == ( T_2 ) - 1 ) {
while ( 1 ) {
if ( V_66 -> V_83 [ 0 ] >= F_39 ( V_68 ) ) {
V_29 = F_51 ( V_35 , V_66 ) ;
if ( V_29 < 0 )
return V_29 ;
F_32 ( V_29 > 0 ) ;
V_68 = V_66 -> V_82 [ 0 ] ;
}
F_41 ( V_68 , & V_147 ,
V_66 -> V_83 [ 0 ] ) ;
F_32 ( V_21 . V_22 != V_147 . V_22 ) ;
if ( V_147 . type != V_149 ) {
V_66 -> V_83 [ 0 ] ++ ;
continue;
}
V_144 = F_86 ( V_68 , V_66 -> V_83 [ 0 ] ,
struct V_143 ) ;
V_141 = F_96 ( V_68 , V_144 ) ;
break;
}
}
F_45 ( V_66 ) ;
if ( V_141 < V_150 )
V_148 += sizeof( * V_146 ) ;
V_148 -= sizeof( * V_133 ) ;
V_29 = F_38 ( V_118 , V_35 , & V_21 , V_66 ,
V_148 + V_142 , 1 ) ;
if ( V_29 < 0 )
return V_29 ;
F_32 ( V_29 ) ;
F_97 ( V_35 , V_66 , V_148 ) ;
V_68 = V_66 -> V_82 [ 0 ] ;
V_96 = F_86 ( V_68 , V_66 -> V_83 [ 0 ] , struct V_124 ) ;
F_98 ( V_68 , V_96 , V_120 ) ;
F_99 ( V_68 , V_96 , 0 ) ;
if ( V_141 < V_150 ) {
F_100 ( V_68 , V_96 ,
V_151 |
V_134 ) ;
V_146 = (struct V_145 * ) ( V_96 + 1 ) ;
F_101 ( V_68 , 0 , ( unsigned long ) V_146 , sizeof( * V_146 ) ) ;
F_102 ( V_68 , V_146 , ( int ) V_141 ) ;
} else {
F_100 ( V_68 , V_96 , V_152 ) ;
}
F_103 ( V_68 ) ;
return 0 ;
}
static T_2 F_104 ( T_2 V_153 , T_2 V_141 , T_2 V_33 )
{
T_3 V_154 = ~ ( T_3 ) 0 ;
T_3 V_155 = ~ ( T_3 ) 0 ;
T_4 V_156 ;
V_156 = F_105 ( V_153 ) ;
V_154 = F_106 ( V_154 , & V_156 , sizeof( V_156 ) ) ;
V_156 = F_105 ( V_141 ) ;
V_155 = F_106 ( V_155 , & V_156 , sizeof( V_156 ) ) ;
V_156 = F_105 ( V_33 ) ;
V_155 = F_106 ( V_155 , & V_156 , sizeof( V_156 ) ) ;
return ( ( T_2 ) V_154 << 31 ) ^ ( T_2 ) V_155 ;
}
static T_2 F_107 ( struct V_67 * V_68 ,
struct V_157 * V_158 )
{
return F_104 ( F_108 ( V_68 , V_158 ) ,
F_109 ( V_68 , V_158 ) ,
F_110 ( V_68 , V_158 ) ) ;
}
static int F_111 ( struct V_67 * V_68 ,
struct V_157 * V_158 ,
T_2 V_153 , T_2 V_141 , T_2 V_33 )
{
if ( F_108 ( V_68 , V_158 ) != V_153 ||
F_109 ( V_68 , V_158 ) != V_141 ||
F_110 ( V_68 , V_158 ) != V_33 )
return 0 ;
return 1 ;
}
static T_1 int F_112 ( struct V_117 * V_118 ,
struct V_34 * V_35 ,
struct V_65 * V_66 ,
T_2 V_27 , T_2 V_17 ,
T_2 V_153 ,
T_2 V_141 , T_2 V_33 )
{
struct V_69 V_21 ;
struct V_157 * V_158 ;
struct V_67 * V_68 ;
T_3 V_72 ;
int V_29 ;
int V_159 ;
int V_160 = - V_161 ;
V_21 . V_22 = V_27 ;
if ( V_17 ) {
V_21 . type = V_162 ;
V_21 . V_33 = V_17 ;
} else {
V_21 . type = V_163 ;
V_21 . V_33 = F_104 ( V_153 ,
V_141 , V_33 ) ;
}
V_164:
V_159 = 0 ;
V_29 = F_38 ( V_118 , V_35 , & V_21 , V_66 , - 1 , 1 ) ;
if ( V_29 < 0 ) {
V_160 = V_29 ;
goto V_165;
}
if ( V_17 ) {
if ( ! V_29 )
return 0 ;
#ifdef F_89
V_21 . type = V_149 ;
F_45 ( V_66 ) ;
V_29 = F_38 ( V_118 , V_35 , & V_21 , V_66 , - 1 , 1 ) ;
if ( V_29 < 0 ) {
V_160 = V_29 ;
goto V_165;
}
if ( ! V_29 )
return 0 ;
#endif
goto V_165;
}
V_68 = V_66 -> V_82 [ 0 ] ;
V_72 = F_39 ( V_68 ) ;
while ( 1 ) {
if ( V_66 -> V_83 [ 0 ] >= V_72 ) {
V_29 = F_51 ( V_35 , V_66 ) ;
if ( V_29 < 0 )
V_160 = V_29 ;
if ( V_29 )
goto V_165;
V_68 = V_66 -> V_82 [ 0 ] ;
V_72 = F_39 ( V_68 ) ;
V_159 = 1 ;
}
F_41 ( V_68 , & V_21 , V_66 -> V_83 [ 0 ] ) ;
if ( V_21 . V_22 != V_27 ||
V_21 . type != V_163 )
goto V_165;
V_158 = F_86 ( V_68 , V_66 -> V_83 [ 0 ] ,
struct V_157 ) ;
if ( F_111 ( V_68 , V_158 , V_153 ,
V_141 , V_33 ) ) {
if ( V_159 ) {
F_45 ( V_66 ) ;
goto V_164;
}
V_160 = 0 ;
break;
}
V_66 -> V_83 [ 0 ] ++ ;
}
V_165:
return V_160 ;
}
static T_1 int F_113 ( struct V_117 * V_118 ,
struct V_34 * V_35 ,
struct V_65 * V_66 ,
T_2 V_27 , T_2 V_17 ,
T_2 V_153 , T_2 V_141 ,
T_2 V_33 , int V_166 )
{
struct V_69 V_21 ;
struct V_67 * V_68 ;
T_3 V_60 ;
T_3 V_127 ;
int V_29 ;
V_21 . V_22 = V_27 ;
if ( V_17 ) {
V_21 . type = V_162 ;
V_21 . V_33 = V_17 ;
V_60 = sizeof( struct V_167 ) ;
} else {
V_21 . type = V_163 ;
V_21 . V_33 = F_104 ( V_153 ,
V_141 , V_33 ) ;
V_60 = sizeof( struct V_157 ) ;
}
V_29 = F_114 ( V_118 , V_35 , V_66 , & V_21 , V_60 ) ;
if ( V_29 && V_29 != - V_25 )
goto V_165;
V_68 = V_66 -> V_82 [ 0 ] ;
if ( V_17 ) {
struct V_167 * V_158 ;
V_158 = F_86 ( V_68 , V_66 -> V_83 [ 0 ] ,
struct V_167 ) ;
if ( V_29 == 0 ) {
F_115 ( V_68 , V_158 , V_166 ) ;
} else {
V_127 = F_116 ( V_68 , V_158 ) ;
V_127 += V_166 ;
F_115 ( V_68 , V_158 , V_127 ) ;
}
} else {
struct V_157 * V_158 ;
while ( V_29 == - V_25 ) {
V_158 = F_86 ( V_68 , V_66 -> V_83 [ 0 ] ,
struct V_157 ) ;
if ( F_111 ( V_68 , V_158 , V_153 ,
V_141 , V_33 ) )
break;
F_45 ( V_66 ) ;
V_21 . V_33 ++ ;
V_29 = F_114 ( V_118 , V_35 , V_66 , & V_21 ,
V_60 ) ;
if ( V_29 && V_29 != - V_25 )
goto V_165;
V_68 = V_66 -> V_82 [ 0 ] ;
}
V_158 = F_86 ( V_68 , V_66 -> V_83 [ 0 ] ,
struct V_157 ) ;
if ( V_29 == 0 ) {
F_117 ( V_68 , V_158 ,
V_153 ) ;
F_118 ( V_68 , V_158 , V_141 ) ;
F_119 ( V_68 , V_158 , V_33 ) ;
F_120 ( V_68 , V_158 , V_166 ) ;
} else {
V_127 = F_121 ( V_68 , V_158 ) ;
V_127 += V_166 ;
F_120 ( V_68 , V_158 , V_127 ) ;
}
}
F_103 ( V_68 ) ;
V_29 = 0 ;
V_165:
F_45 ( V_66 ) ;
return V_29 ;
}
static T_1 int F_122 ( struct V_117 * V_118 ,
struct V_34 * V_35 ,
struct V_65 * V_66 ,
int V_168 , int * V_169 )
{
struct V_69 V_21 ;
struct V_157 * V_170 = NULL ;
struct V_167 * V_171 = NULL ;
struct V_67 * V_68 ;
T_3 V_127 = 0 ;
int V_29 = 0 ;
V_68 = V_66 -> V_82 [ 0 ] ;
F_41 ( V_68 , & V_21 , V_66 -> V_83 [ 0 ] ) ;
if ( V_21 . type == V_163 ) {
V_170 = F_86 ( V_68 , V_66 -> V_83 [ 0 ] ,
struct V_157 ) ;
V_127 = F_121 ( V_68 , V_170 ) ;
} else if ( V_21 . type == V_162 ) {
V_171 = F_86 ( V_68 , V_66 -> V_83 [ 0 ] ,
struct V_167 ) ;
V_127 = F_116 ( V_68 , V_171 ) ;
#ifdef F_89
} else if ( V_21 . type == V_149 ) {
struct V_143 * V_144 ;
V_144 = F_86 ( V_68 , V_66 -> V_83 [ 0 ] ,
struct V_143 ) ;
V_127 = F_123 ( V_68 , V_144 ) ;
#endif
} else {
F_91 () ;
}
F_32 ( V_127 < V_168 ) ;
V_127 -= V_168 ;
if ( V_127 == 0 ) {
V_29 = F_124 ( V_118 , V_35 , V_66 ) ;
* V_169 = 1 ;
} else {
if ( V_21 . type == V_163 )
F_120 ( V_68 , V_170 , V_127 ) ;
else if ( V_21 . type == V_162 )
F_115 ( V_68 , V_171 , V_127 ) ;
#ifdef F_89
else {
struct V_143 * V_144 ;
V_144 = F_86 ( V_68 , V_66 -> V_83 [ 0 ] ,
struct V_143 ) ;
F_125 ( V_68 , V_144 , V_127 ) ;
}
#endif
F_103 ( V_68 ) ;
}
return V_29 ;
}
static T_1 T_3 F_126 ( struct V_65 * V_66 ,
struct V_172 * V_173 )
{
struct V_69 V_21 ;
struct V_67 * V_68 ;
struct V_157 * V_170 ;
struct V_167 * V_171 ;
T_3 V_127 = 0 ;
V_68 = V_66 -> V_82 [ 0 ] ;
F_41 ( V_68 , & V_21 , V_66 -> V_83 [ 0 ] ) ;
if ( V_173 ) {
if ( F_127 ( V_68 , V_173 ) ==
V_163 ) {
V_170 = (struct V_157 * ) ( & V_173 -> V_33 ) ;
V_127 = F_121 ( V_68 , V_170 ) ;
} else {
V_171 = (struct V_167 * ) ( V_173 + 1 ) ;
V_127 = F_116 ( V_68 , V_171 ) ;
}
} else if ( V_21 . type == V_163 ) {
V_170 = F_86 ( V_68 , V_66 -> V_83 [ 0 ] ,
struct V_157 ) ;
V_127 = F_121 ( V_68 , V_170 ) ;
} else if ( V_21 . type == V_162 ) {
V_171 = F_86 ( V_68 , V_66 -> V_83 [ 0 ] ,
struct V_167 ) ;
V_127 = F_116 ( V_68 , V_171 ) ;
#ifdef F_89
} else if ( V_21 . type == V_149 ) {
struct V_143 * V_144 ;
V_144 = F_86 ( V_68 , V_66 -> V_83 [ 0 ] ,
struct V_143 ) ;
V_127 = F_123 ( V_68 , V_144 ) ;
#endif
} else {
F_8 ( 1 ) ;
}
return V_127 ;
}
static T_1 int F_128 ( struct V_117 * V_118 ,
struct V_34 * V_35 ,
struct V_65 * V_66 ,
T_2 V_27 , T_2 V_17 ,
T_2 V_153 )
{
struct V_69 V_21 ;
int V_29 ;
V_21 . V_22 = V_27 ;
if ( V_17 ) {
V_21 . type = V_174 ;
V_21 . V_33 = V_17 ;
} else {
V_21 . type = V_175 ;
V_21 . V_33 = V_153 ;
}
V_29 = F_38 ( V_118 , V_35 , & V_21 , V_66 , - 1 , 1 ) ;
if ( V_29 > 0 )
V_29 = - V_161 ;
#ifdef F_89
if ( V_29 == - V_161 && V_17 ) {
F_45 ( V_66 ) ;
V_21 . type = V_149 ;
V_29 = F_38 ( V_118 , V_35 , & V_21 , V_66 , - 1 , 1 ) ;
if ( V_29 > 0 )
V_29 = - V_161 ;
}
#endif
return V_29 ;
}
static T_1 int F_129 ( struct V_117 * V_118 ,
struct V_34 * V_35 ,
struct V_65 * V_66 ,
T_2 V_27 , T_2 V_17 ,
T_2 V_153 )
{
struct V_69 V_21 ;
int V_29 ;
V_21 . V_22 = V_27 ;
if ( V_17 ) {
V_21 . type = V_174 ;
V_21 . V_33 = V_17 ;
} else {
V_21 . type = V_175 ;
V_21 . V_33 = V_153 ;
}
V_29 = F_114 ( V_118 , V_35 , V_66 , & V_21 , 0 ) ;
F_45 ( V_66 ) ;
return V_29 ;
}
static inline int F_130 ( T_2 V_17 , T_2 V_141 )
{
int type ;
if ( V_141 < V_150 ) {
if ( V_17 > 0 )
type = V_174 ;
else
type = V_175 ;
} else {
if ( V_17 > 0 )
type = V_162 ;
else
type = V_163 ;
}
return type ;
}
static int F_42 ( struct V_65 * V_66 , int V_176 ,
struct V_69 * V_21 )
{
for (; V_176 < V_177 ; V_176 ++ ) {
if ( ! V_66 -> V_82 [ V_176 ] )
break;
if ( V_66 -> V_83 [ V_176 ] + 1 >=
F_39 ( V_66 -> V_82 [ V_176 ] ) )
continue;
if ( V_176 == 0 )
F_41 ( V_66 -> V_82 [ V_176 ] , V_21 ,
V_66 -> V_83 [ V_176 ] + 1 ) ;
else
F_131 ( V_66 -> V_82 [ V_176 ] , V_21 ,
V_66 -> V_83 [ V_176 ] + 1 ) ;
return 0 ;
}
return 1 ;
}
static T_5
int F_132 ( struct V_117 * V_118 ,
struct V_34 * V_35 ,
struct V_65 * V_66 ,
struct V_172 * * V_178 ,
T_2 V_27 , T_2 V_36 ,
T_2 V_17 , T_2 V_153 ,
T_2 V_141 , T_2 V_33 , int V_179 )
{
struct V_69 V_21 ;
struct V_67 * V_68 ;
struct V_124 * V_125 ;
struct V_172 * V_173 ;
T_2 V_7 ;
T_2 V_126 ;
unsigned long V_180 ;
unsigned long V_31 ;
int V_142 ;
int type ;
int V_181 ;
int V_29 ;
int V_160 = 0 ;
bool V_182 = F_84 ( V_35 -> V_37 ,
V_129 ) ;
V_21 . V_22 = V_27 ;
V_21 . type = V_79 ;
V_21 . V_33 = V_36 ;
V_181 = F_130 ( V_17 , V_141 ) ;
if ( V_179 ) {
V_142 = F_133 ( V_181 ) ;
V_66 -> V_183 = 1 ;
} else
V_142 = - 1 ;
if ( V_182 && V_141 < V_150 ) {
V_21 . type = V_87 ;
V_21 . V_33 = V_141 ;
}
V_164:
V_29 = F_38 ( V_118 , V_35 , & V_21 , V_66 , V_142 , 1 ) ;
if ( V_29 < 0 ) {
V_160 = V_29 ;
goto V_81;
}
if ( V_29 > 0 && V_182 ) {
V_182 = false ;
if ( V_66 -> V_83 [ 0 ] ) {
V_66 -> V_83 [ 0 ] -- ;
F_41 ( V_66 -> V_82 [ 0 ] , & V_21 ,
V_66 -> V_83 [ 0 ] ) ;
if ( V_21 . V_22 == V_27 &&
V_21 . type == V_79 &&
V_21 . V_33 == V_36 )
V_29 = 0 ;
}
if ( V_29 ) {
V_21 . V_22 = V_27 ;
V_21 . type = V_79 ;
V_21 . V_33 = V_36 ;
F_45 ( V_66 ) ;
goto V_164;
}
}
if ( V_29 && ! V_179 ) {
V_160 = - V_161 ;
goto V_81;
} else if ( F_8 ( V_29 ) ) {
V_160 = - V_184 ;
goto V_81;
}
V_68 = V_66 -> V_82 [ 0 ] ;
V_126 = F_85 ( V_68 , V_66 -> V_83 [ 0 ] ) ;
#ifdef F_89
if ( V_126 < sizeof( * V_125 ) ) {
if ( ! V_179 ) {
V_160 = - V_161 ;
goto V_81;
}
V_29 = F_95 ( V_118 , V_35 , V_66 , V_141 ,
V_142 ) ;
if ( V_29 < 0 ) {
V_160 = V_29 ;
goto V_81;
}
V_68 = V_66 -> V_82 [ 0 ] ;
V_126 = F_85 ( V_68 , V_66 -> V_83 [ 0 ] ) ;
}
#endif
F_32 ( V_126 < sizeof( * V_125 ) ) ;
V_125 = F_86 ( V_68 , V_66 -> V_83 [ 0 ] , struct V_124 ) ;
V_7 = F_88 ( V_68 , V_125 ) ;
V_180 = ( unsigned long ) ( V_125 + 1 ) ;
V_31 = ( unsigned long ) V_125 + V_126 ;
if ( V_7 & V_151 && ! V_182 ) {
V_180 += sizeof( struct V_145 ) ;
F_32 ( V_180 > V_31 ) ;
}
V_160 = - V_161 ;
while ( 1 ) {
if ( V_180 >= V_31 ) {
F_8 ( V_180 > V_31 ) ;
break;
}
V_173 = (struct V_172 * ) V_180 ;
type = F_127 ( V_68 , V_173 ) ;
if ( V_181 < type )
break;
if ( V_181 > type ) {
V_180 += F_133 ( type ) ;
continue;
}
if ( type == V_163 ) {
struct V_157 * V_185 ;
V_185 = (struct V_157 * ) ( & V_173 -> V_33 ) ;
if ( F_111 ( V_68 , V_185 , V_153 ,
V_141 , V_33 ) ) {
V_160 = 0 ;
break;
}
if ( F_107 ( V_68 , V_185 ) <
F_104 ( V_153 , V_141 , V_33 ) )
break;
} else {
T_2 V_186 ;
V_186 = F_134 ( V_68 , V_173 ) ;
if ( V_17 > 0 ) {
if ( V_17 == V_186 ) {
V_160 = 0 ;
break;
}
if ( V_186 < V_17 )
break;
} else {
if ( V_153 == V_186 ) {
V_160 = 0 ;
break;
}
if ( V_186 < V_153 )
break;
}
}
V_180 += F_133 ( type ) ;
}
if ( V_160 == - V_161 && V_179 ) {
if ( V_126 + V_142 >=
F_135 ( V_35 ) ) {
V_160 = - V_187 ;
goto V_81;
}
if ( F_42 ( V_66 , 0 , & V_21 ) == 0 &&
V_21 . V_22 == V_27 &&
V_21 . type < V_188 ) {
V_160 = - V_187 ;
goto V_81;
}
}
* V_178 = (struct V_172 * ) V_180 ;
V_81:
if ( V_179 ) {
V_66 -> V_183 = 0 ;
F_136 ( V_66 , 1 ) ;
}
return V_160 ;
}
static T_5
void F_137 ( struct V_34 * V_35 ,
struct V_65 * V_66 ,
struct V_172 * V_173 ,
T_2 V_17 , T_2 V_153 ,
T_2 V_141 , T_2 V_33 , int V_166 ,
struct V_189 * V_137 )
{
struct V_67 * V_68 ;
struct V_124 * V_125 ;
unsigned long V_180 ;
unsigned long V_31 ;
unsigned long V_190 ;
T_2 V_120 ;
int V_60 ;
int type ;
V_68 = V_66 -> V_82 [ 0 ] ;
V_125 = F_86 ( V_68 , V_66 -> V_83 [ 0 ] , struct V_124 ) ;
V_190 = ( unsigned long ) V_173 - ( unsigned long ) V_125 ;
type = F_130 ( V_17 , V_141 ) ;
V_60 = F_133 ( type ) ;
F_97 ( V_35 , V_66 , V_60 ) ;
V_125 = F_86 ( V_68 , V_66 -> V_83 [ 0 ] , struct V_124 ) ;
V_120 = F_87 ( V_68 , V_125 ) ;
V_120 += V_166 ;
F_98 ( V_68 , V_125 , V_120 ) ;
if ( V_137 )
F_138 ( V_137 , V_68 , V_125 ) ;
V_180 = ( unsigned long ) V_125 + V_190 ;
V_31 = ( unsigned long ) V_125 + F_85 ( V_68 , V_66 -> V_83 [ 0 ] ) ;
if ( V_180 < V_31 - V_60 )
F_139 ( V_68 , V_180 + V_60 , V_180 ,
V_31 - V_60 - V_180 ) ;
V_173 = (struct V_172 * ) V_180 ;
F_140 ( V_68 , V_173 , type ) ;
if ( type == V_163 ) {
struct V_157 * V_185 ;
V_185 = (struct V_157 * ) ( & V_173 -> V_33 ) ;
F_117 ( V_68 , V_185 , V_153 ) ;
F_118 ( V_68 , V_185 , V_141 ) ;
F_119 ( V_68 , V_185 , V_33 ) ;
F_120 ( V_68 , V_185 , V_166 ) ;
} else if ( type == V_162 ) {
struct V_167 * V_191 ;
V_191 = (struct V_167 * ) ( V_173 + 1 ) ;
F_115 ( V_68 , V_191 , V_166 ) ;
F_141 ( V_68 , V_173 , V_17 ) ;
} else if ( type == V_174 ) {
F_141 ( V_68 , V_173 , V_17 ) ;
} else {
F_141 ( V_68 , V_173 , V_153 ) ;
}
F_103 ( V_68 ) ;
}
static int F_142 ( struct V_117 * V_118 ,
struct V_34 * V_35 ,
struct V_65 * V_66 ,
struct V_172 * * V_178 ,
T_2 V_27 , T_2 V_36 , T_2 V_17 ,
T_2 V_153 , T_2 V_141 , T_2 V_33 )
{
int V_29 ;
V_29 = F_132 ( V_118 , V_35 , V_66 , V_178 ,
V_27 , V_36 , V_17 ,
V_153 , V_141 , V_33 , 0 ) ;
if ( V_29 != - V_161 )
return V_29 ;
F_45 ( V_66 ) ;
* V_178 = NULL ;
if ( V_141 < V_150 ) {
V_29 = F_128 ( V_118 , V_35 , V_66 , V_27 , V_17 ,
V_153 ) ;
} else {
V_29 = F_112 ( V_118 , V_35 , V_66 , V_27 , V_17 ,
V_153 , V_141 , V_33 ) ;
}
return V_29 ;
}
static T_5
void F_143 ( struct V_34 * V_35 ,
struct V_65 * V_66 ,
struct V_172 * V_173 ,
int V_192 ,
struct V_189 * V_137 ,
int * V_169 )
{
struct V_67 * V_68 ;
struct V_124 * V_125 ;
struct V_157 * V_185 = NULL ;
struct V_167 * V_191 = NULL ;
unsigned long V_180 ;
unsigned long V_31 ;
T_3 V_126 ;
int V_60 ;
int type ;
T_2 V_120 ;
V_68 = V_66 -> V_82 [ 0 ] ;
V_125 = F_86 ( V_68 , V_66 -> V_83 [ 0 ] , struct V_124 ) ;
V_120 = F_87 ( V_68 , V_125 ) ;
F_8 ( V_192 < 0 && V_120 + V_192 <= 0 ) ;
V_120 += V_192 ;
F_98 ( V_68 , V_125 , V_120 ) ;
if ( V_137 )
F_138 ( V_137 , V_68 , V_125 ) ;
type = F_127 ( V_68 , V_173 ) ;
if ( type == V_163 ) {
V_185 = (struct V_157 * ) ( & V_173 -> V_33 ) ;
V_120 = F_121 ( V_68 , V_185 ) ;
} else if ( type == V_162 ) {
V_191 = (struct V_167 * ) ( V_173 + 1 ) ;
V_120 = F_116 ( V_68 , V_191 ) ;
} else {
V_120 = 1 ;
F_32 ( V_192 != - 1 ) ;
}
F_32 ( V_192 < 0 && V_120 < - V_192 ) ;
V_120 += V_192 ;
if ( V_120 > 0 ) {
if ( type == V_163 )
F_120 ( V_68 , V_185 , V_120 ) ;
else
F_115 ( V_68 , V_191 , V_120 ) ;
} else {
* V_169 = 1 ;
V_60 = F_133 ( type ) ;
V_126 = F_85 ( V_68 , V_66 -> V_83 [ 0 ] ) ;
V_180 = ( unsigned long ) V_173 ;
V_31 = ( unsigned long ) V_125 + V_126 ;
if ( V_180 + V_60 < V_31 )
F_139 ( V_68 , V_180 , V_180 + V_60 ,
V_31 - V_180 - V_60 ) ;
V_126 -= V_60 ;
F_144 ( V_35 , V_66 , V_126 , 1 ) ;
}
F_103 ( V_68 ) ;
}
static T_5
int F_145 ( struct V_117 * V_118 ,
struct V_34 * V_35 ,
struct V_65 * V_66 ,
T_2 V_27 , T_2 V_36 , T_2 V_17 ,
T_2 V_153 , T_2 V_141 ,
T_2 V_33 , int V_166 ,
struct V_189 * V_137 )
{
struct V_172 * V_173 ;
int V_29 ;
V_29 = F_132 ( V_118 , V_35 , V_66 , & V_173 ,
V_27 , V_36 , V_17 ,
V_153 , V_141 , V_33 , 1 ) ;
if ( V_29 == 0 ) {
F_32 ( V_141 < V_150 ) ;
F_143 ( V_35 , V_66 , V_173 ,
V_166 , V_137 , NULL ) ;
} else if ( V_29 == - V_161 ) {
F_137 ( V_35 , V_66 , V_173 , V_17 ,
V_153 , V_141 , V_33 ,
V_166 , V_137 ) ;
V_29 = 0 ;
}
return V_29 ;
}
static int F_146 ( struct V_117 * V_118 ,
struct V_34 * V_35 ,
struct V_65 * V_66 ,
T_2 V_27 , T_2 V_17 , T_2 V_153 ,
T_2 V_141 , T_2 V_33 , int V_166 )
{
int V_29 ;
if ( V_141 < V_150 ) {
F_32 ( V_166 != 1 ) ;
V_29 = F_129 ( V_118 , V_35 , V_66 , V_27 ,
V_17 , V_153 ) ;
} else {
V_29 = F_113 ( V_118 , V_35 , V_66 , V_27 ,
V_17 , V_153 ,
V_141 , V_33 , V_166 ) ;
}
return V_29 ;
}
static int F_147 ( struct V_117 * V_118 ,
struct V_34 * V_35 ,
struct V_65 * V_66 ,
struct V_172 * V_173 ,
int V_168 , int V_193 , int * V_169 )
{
int V_29 = 0 ;
F_32 ( ! V_193 && V_168 != 1 ) ;
if ( V_173 ) {
F_143 ( V_35 , V_66 , V_173 ,
- V_168 , NULL , V_169 ) ;
} else if ( V_193 ) {
V_29 = F_122 ( V_118 , V_35 , V_66 , V_168 ,
V_169 ) ;
} else {
* V_169 = 1 ;
V_29 = F_124 ( V_118 , V_35 , V_66 ) ;
}
return V_29 ;
}
static int F_148 ( struct V_194 * V_195 , T_2 V_32 , T_2 V_48 ,
T_2 * V_196 )
{
int V_197 , V_29 = 0 ;
T_2 V_198 , V_31 ;
T_2 V_199 = F_149 ( V_32 , 1 << 9 ) ;
if ( F_8 ( V_32 != V_199 ) ) {
V_48 -= V_199 - V_32 ;
V_48 = F_150 ( V_48 , 1 << 9 ) ;
V_32 = V_199 ;
}
* V_196 = 0 ;
if ( ! V_48 )
return 0 ;
V_31 = V_32 + V_48 ;
V_198 = V_48 ;
for ( V_197 = 0 ; V_197 < V_46 ; V_197 ++ ) {
T_2 V_200 = F_22 ( V_197 ) ;
T_2 V_201 = V_200 + V_202 ;
T_2 V_60 = V_200 - V_32 ;
if ( ! F_151 ( V_200 , V_32 , V_198 ) &&
! F_151 ( V_201 , V_32 , V_198 ) &&
! F_151 ( V_32 , V_200 , V_202 ) )
continue;
if ( V_200 <= V_32 ) {
V_32 += V_201 - V_32 ;
if ( V_32 > V_31 ) {
V_198 = 0 ;
break;
}
V_198 = V_31 - V_32 ;
continue;
}
if ( V_60 ) {
V_29 = F_152 ( V_195 , V_32 >> 9 , V_60 >> 9 ,
V_98 , 0 ) ;
if ( ! V_29 )
* V_196 += V_60 ;
else if ( V_29 != - V_203 )
return V_29 ;
}
V_32 = V_201 ;
if ( V_32 > V_31 ) {
V_198 = 0 ;
break;
}
V_198 = V_31 - V_32 ;
}
if ( V_198 ) {
V_29 = F_152 ( V_195 , V_32 >> 9 , V_198 >> 9 ,
V_98 , 0 ) ;
if ( ! V_29 )
* V_196 += V_198 ;
}
return V_29 ;
}
int F_153 ( struct V_34 * V_35 , T_2 V_27 ,
T_2 V_36 , T_2 * V_204 )
{
int V_29 ;
T_2 V_196 = 0 ;
struct V_205 * V_206 = NULL ;
F_154 ( V_35 -> V_37 ) ;
V_29 = F_155 ( V_35 -> V_37 , V_207 ,
V_27 , & V_36 , & V_206 , 0 ) ;
if ( ! V_29 ) {
struct V_208 * V_209 = V_206 -> V_210 ;
int V_42 ;
for ( V_42 = 0 ; V_42 < V_206 -> V_211 ; V_42 ++ , V_209 ++ ) {
T_2 V_212 ;
if ( ! V_209 -> V_213 -> V_214 )
continue;
V_29 = F_148 ( V_209 -> V_213 -> V_195 ,
V_209 -> V_215 ,
V_209 -> V_216 ,
& V_212 ) ;
if ( ! V_29 )
V_196 += V_212 ;
else if ( V_29 != - V_203 )
break;
V_29 = 0 ;
}
F_156 ( V_206 ) ;
}
F_157 ( V_35 -> V_37 ) ;
if ( V_204 )
* V_204 = V_196 ;
if ( V_29 == - V_203 )
V_29 = 0 ;
return V_29 ;
}
int F_158 ( struct V_117 * V_118 ,
struct V_34 * V_35 ,
T_2 V_27 , T_2 V_36 , T_2 V_17 ,
T_2 V_153 , T_2 V_141 , T_2 V_33 )
{
int V_29 ;
struct V_12 * V_37 = V_35 -> V_37 ;
F_32 ( V_141 < V_150 &&
V_153 == V_217 ) ;
if ( V_141 < V_150 ) {
V_29 = F_159 ( V_37 , V_118 , V_27 ,
V_36 ,
V_17 , V_153 , ( int ) V_141 ,
V_218 , NULL ) ;
} else {
V_29 = F_160 ( V_37 , V_118 , V_27 ,
V_36 , V_17 , V_153 ,
V_141 , V_33 , 0 ,
V_218 , NULL ) ;
}
return V_29 ;
}
static int F_161 ( struct V_117 * V_118 ,
struct V_34 * V_35 ,
struct V_219 * V_136 ,
T_2 V_17 , T_2 V_153 ,
T_2 V_141 , T_2 V_33 , int V_166 ,
struct V_189 * V_137 )
{
struct V_12 * V_37 = V_35 -> V_37 ;
struct V_65 * V_66 ;
struct V_67 * V_68 ;
struct V_124 * V_96 ;
struct V_69 V_21 ;
T_2 V_27 = V_136 -> V_27 ;
T_2 V_36 = V_136 -> V_36 ;
T_2 V_120 ;
int V_29 ;
V_66 = F_34 () ;
if ( ! V_66 )
return - V_74 ;
V_66 -> V_77 = V_78 ;
V_66 -> V_220 = 1 ;
V_29 = F_145 ( V_118 , V_37 -> V_64 , V_66 ,
V_27 , V_36 , V_17 ,
V_153 , V_141 , V_33 ,
V_166 , V_137 ) ;
if ( ( V_29 < 0 && V_29 != - V_187 ) || ! V_29 )
goto V_81;
V_68 = V_66 -> V_82 [ 0 ] ;
F_41 ( V_68 , & V_21 , V_66 -> V_83 [ 0 ] ) ;
V_96 = F_86 ( V_68 , V_66 -> V_83 [ 0 ] , struct V_124 ) ;
V_120 = F_87 ( V_68 , V_96 ) ;
F_98 ( V_68 , V_96 , V_120 + V_166 ) ;
if ( V_137 )
F_138 ( V_137 , V_68 , V_96 ) ;
F_103 ( V_68 ) ;
F_45 ( V_66 ) ;
V_66 -> V_77 = V_78 ;
V_66 -> V_220 = 1 ;
V_29 = F_146 ( V_118 , V_35 -> V_37 -> V_64 ,
V_66 , V_27 , V_17 , V_153 ,
V_141 , V_33 , V_166 ) ;
if ( V_29 )
F_162 ( V_118 , V_35 , V_29 ) ;
V_81:
F_53 ( V_66 ) ;
return V_29 ;
}
static int F_163 ( struct V_117 * V_118 ,
struct V_34 * V_35 ,
struct V_219 * V_136 ,
struct V_189 * V_137 ,
int V_221 )
{
int V_29 = 0 ;
struct V_222 * V_158 ;
struct V_69 V_223 ;
T_2 V_17 = 0 ;
T_2 V_224 = 0 ;
T_2 V_7 = 0 ;
V_223 . V_22 = V_136 -> V_27 ;
V_223 . V_33 = V_136 -> V_36 ;
V_223 . type = V_79 ;
V_158 = F_164 ( V_136 ) ;
F_165 ( V_136 , V_158 , V_136 -> V_225 ) ;
if ( V_136 -> type == V_162 )
V_17 = V_158 -> V_17 ;
V_224 = V_158 -> V_35 ;
if ( V_136 -> V_225 == V_218 && V_221 ) {
if ( V_137 )
V_7 |= V_137 -> V_139 ;
V_29 = F_166 ( V_118 , V_35 ,
V_17 , V_224 , V_7 ,
V_158 -> V_22 , V_158 -> V_33 ,
& V_223 , V_136 -> V_140 ) ;
} else if ( V_136 -> V_225 == V_218 ) {
V_29 = F_161 ( V_118 , V_35 , V_136 , V_17 ,
V_224 , V_158 -> V_22 ,
V_158 -> V_33 , V_136 -> V_140 ,
V_137 ) ;
} else if ( V_136 -> V_225 == V_226 ) {
V_29 = F_167 ( V_118 , V_35 , V_136 , V_17 ,
V_224 , V_158 -> V_22 ,
V_158 -> V_33 , V_136 -> V_140 ,
V_137 ) ;
} else {
F_91 () ;
}
return V_29 ;
}
static void F_138 ( struct V_189 * V_137 ,
struct V_67 * V_68 ,
struct V_124 * V_125 )
{
T_2 V_7 = F_88 ( V_68 , V_125 ) ;
if ( V_137 -> V_138 ) {
V_7 |= V_137 -> V_139 ;
F_100 ( V_68 , V_125 , V_7 ) ;
}
if ( V_137 -> V_227 ) {
struct V_145 * V_146 ;
F_32 ( ! ( V_7 & V_151 ) ) ;
V_146 = (struct V_145 * ) ( V_125 + 1 ) ;
F_168 ( V_68 , V_146 , & V_137 -> V_21 ) ;
}
}
static int F_169 ( struct V_117 * V_118 ,
struct V_34 * V_35 ,
struct V_219 * V_136 ,
struct V_189 * V_137 )
{
struct V_69 V_21 ;
struct V_65 * V_66 ;
struct V_124 * V_125 ;
struct V_67 * V_68 ;
T_3 V_126 ;
int V_29 ;
int V_160 = 0 ;
int V_119 = ! V_137 -> V_193 ;
if ( V_118 -> V_228 )
return 0 ;
if ( V_119 && ! F_84 ( V_35 -> V_37 , V_129 ) )
V_119 = 0 ;
V_66 = F_34 () ;
if ( ! V_66 )
return - V_74 ;
V_21 . V_22 = V_136 -> V_27 ;
if ( V_119 ) {
V_21 . type = V_87 ;
V_21 . V_33 = V_137 -> V_176 ;
} else {
V_21 . type = V_79 ;
V_21 . V_33 = V_136 -> V_36 ;
}
V_164:
V_66 -> V_77 = V_78 ;
V_66 -> V_220 = 1 ;
V_29 = F_38 ( V_118 , V_35 -> V_37 -> V_64 , & V_21 ,
V_66 , 0 , 1 ) ;
if ( V_29 < 0 ) {
V_160 = V_29 ;
goto V_81;
}
if ( V_29 > 0 ) {
if ( V_119 ) {
if ( V_66 -> V_83 [ 0 ] > 0 ) {
V_66 -> V_83 [ 0 ] -- ;
F_41 ( V_66 -> V_82 [ 0 ] , & V_21 ,
V_66 -> V_83 [ 0 ] ) ;
if ( V_21 . V_22 == V_136 -> V_27 &&
V_21 . type == V_79 &&
V_21 . V_33 == V_136 -> V_36 )
V_29 = 0 ;
}
if ( V_29 > 0 ) {
F_45 ( V_66 ) ;
V_119 = 0 ;
V_21 . V_22 = V_136 -> V_27 ;
V_21 . V_33 = V_136 -> V_36 ;
V_21 . type = V_79 ;
goto V_164;
}
} else {
V_160 = - V_184 ;
goto V_81;
}
}
V_68 = V_66 -> V_82 [ 0 ] ;
V_126 = F_85 ( V_68 , V_66 -> V_83 [ 0 ] ) ;
#ifdef F_89
if ( V_126 < sizeof( * V_125 ) ) {
V_29 = F_95 ( V_118 , V_35 -> V_37 -> V_64 ,
V_66 , ( T_2 ) - 1 , 0 ) ;
if ( V_29 < 0 ) {
V_160 = V_29 ;
goto V_81;
}
V_68 = V_66 -> V_82 [ 0 ] ;
V_126 = F_85 ( V_68 , V_66 -> V_83 [ 0 ] ) ;
}
#endif
F_32 ( V_126 < sizeof( * V_125 ) ) ;
V_125 = F_86 ( V_68 , V_66 -> V_83 [ 0 ] , struct V_124 ) ;
F_138 ( V_137 , V_68 , V_125 ) ;
F_103 ( V_68 ) ;
V_81:
F_53 ( V_66 ) ;
return V_160 ;
}
static int F_170 ( struct V_117 * V_118 ,
struct V_34 * V_35 ,
struct V_219 * V_136 ,
struct V_189 * V_137 ,
int V_221 )
{
int V_29 = 0 ;
struct V_229 * V_158 ;
struct V_69 V_223 ;
T_2 V_17 = 0 ;
T_2 V_224 = 0 ;
bool V_182 = F_84 ( V_35 -> V_37 ,
V_129 ) ;
V_158 = F_171 ( V_136 ) ;
F_172 ( V_136 , V_158 , V_136 -> V_225 ) ;
if ( V_136 -> type == V_174 )
V_17 = V_158 -> V_17 ;
V_224 = V_158 -> V_35 ;
V_223 . V_22 = V_136 -> V_27 ;
if ( V_182 ) {
V_223 . V_33 = V_158 -> V_176 ;
V_223 . type = V_87 ;
} else {
V_223 . V_33 = V_136 -> V_36 ;
V_223 . type = V_79 ;
}
F_32 ( V_136 -> V_140 != 1 ) ;
if ( V_136 -> V_225 == V_218 && V_221 ) {
F_32 ( ! V_137 || ! V_137 -> V_138 ) ;
V_29 = F_173 ( V_118 , V_35 ,
V_17 , V_224 ,
V_137 -> V_139 ,
& V_137 -> V_21 ,
V_158 -> V_176 , & V_223 ) ;
} else if ( V_136 -> V_225 == V_218 ) {
V_29 = F_161 ( V_118 , V_35 , V_136 ,
V_17 , V_224 ,
V_158 -> V_176 , 0 , 1 ,
V_137 ) ;
} else if ( V_136 -> V_225 == V_226 ) {
V_29 = F_167 ( V_118 , V_35 , V_136 ,
V_17 , V_224 ,
V_158 -> V_176 , 0 , 1 , V_137 ) ;
} else {
F_91 () ;
}
return V_29 ;
}
static int F_174 ( struct V_117 * V_118 ,
struct V_34 * V_35 ,
struct V_219 * V_136 ,
struct V_189 * V_137 ,
int V_221 )
{
int V_29 = 0 ;
if ( V_118 -> V_228 ) {
if ( V_221 )
F_175 ( V_35 , V_136 -> V_27 ,
V_136 -> V_36 , 1 ) ;
return 0 ;
}
if ( F_176 ( V_136 ) ) {
struct V_121 * V_113 ;
F_32 ( V_137 ) ;
V_113 = F_177 ( V_136 ) ;
F_178 ( V_136 , V_113 , V_136 -> V_225 ) ;
if ( V_221 ) {
F_175 ( V_35 , V_136 -> V_27 ,
V_136 -> V_36 , 1 ) ;
if ( V_113 -> V_193 ) {
V_29 = F_179 ( V_118 , V_35 ,
V_136 -> V_27 ,
V_136 -> V_36 ) ;
}
}
F_180 ( V_35 -> V_37 ,
V_113 -> V_230 ,
V_113 -> V_231 ) ;
return V_29 ;
}
if ( V_136 -> type == V_175 ||
V_136 -> type == V_174 )
V_29 = F_170 ( V_118 , V_35 , V_136 , V_137 ,
V_221 ) ;
else if ( V_136 -> type == V_163 ||
V_136 -> type == V_162 )
V_29 = F_163 ( V_118 , V_35 , V_136 , V_137 ,
V_221 ) ;
else
F_91 () ;
return V_29 ;
}
static inline struct V_219 *
F_181 ( struct V_121 * V_113 )
{
struct V_219 * V_158 ;
if ( F_182 ( & V_113 -> V_232 ) )
return NULL ;
F_183 (ref, &head->ref_list, list) {
if ( V_158 -> V_225 == V_218 )
return V_158 ;
}
return F_184 ( V_113 -> V_232 . V_80 , struct V_219 ,
V_99 ) ;
}
static T_1 int F_185 ( struct V_117 * V_118 ,
struct V_34 * V_35 ,
unsigned long V_43 )
{
struct V_122 * V_123 ;
struct V_219 * V_158 ;
struct V_121 * V_233 = NULL ;
struct V_189 * V_137 ;
struct V_12 * V_37 = V_35 -> V_37 ;
T_6 V_32 = F_186 () ;
int V_29 ;
unsigned long V_8 = 0 ;
unsigned long V_234 = 0 ;
int V_235 = 0 ;
V_123 = & V_118 -> V_135 -> V_123 ;
while ( 1 ) {
if ( ! V_233 ) {
if ( V_8 >= V_43 )
break;
F_11 ( & V_123 -> V_51 ) ;
V_233 = F_187 ( V_118 ) ;
if ( ! V_233 ) {
F_13 ( & V_123 -> V_51 ) ;
break;
}
V_29 = F_188 ( V_118 , V_233 ) ;
F_13 ( & V_123 -> V_51 ) ;
if ( V_29 == - V_187 ) {
V_233 = NULL ;
V_8 ++ ;
continue;
}
}
F_11 ( & V_233 -> V_51 ) ;
F_189 ( V_118 , V_37 , V_123 ,
V_233 ) ;
V_158 = F_181 ( V_233 ) ;
if ( V_158 && V_158 -> V_236 &&
F_190 ( V_37 , V_123 , V_158 -> V_236 ) ) {
F_13 ( & V_233 -> V_51 ) ;
F_191 ( V_233 ) ;
F_11 ( & V_123 -> V_51 ) ;
V_233 -> V_237 = 0 ;
V_123 -> V_238 ++ ;
F_13 ( & V_123 -> V_51 ) ;
V_233 = NULL ;
F_48 () ;
V_8 ++ ;
continue;
}
V_235 = V_233 -> V_235 ;
V_233 -> V_235 = 0 ;
V_137 = V_233 -> V_137 ;
V_233 -> V_137 = NULL ;
if ( ! V_158 ) {
V_158 = & V_233 -> V_136 ;
if ( V_137 && V_235 ) {
F_192 ( V_137 ) ;
V_137 = NULL ;
}
if ( V_137 ) {
F_13 ( & V_233 -> V_51 ) ;
V_29 = F_169 ( V_118 , V_35 ,
V_158 , V_137 ) ;
F_192 ( V_137 ) ;
if ( V_29 ) {
if ( V_235 )
V_233 -> V_235 = 1 ;
V_233 -> V_237 = 0 ;
F_193 ( V_37 , L_1 , V_29 ) ;
F_191 ( V_233 ) ;
return V_29 ;
}
continue;
}
F_13 ( & V_233 -> V_51 ) ;
F_11 ( & V_123 -> V_51 ) ;
F_11 ( & V_233 -> V_51 ) ;
if ( ! F_182 ( & V_233 -> V_232 ) ||
V_233 -> V_137 ) {
F_13 ( & V_233 -> V_51 ) ;
F_13 ( & V_123 -> V_51 ) ;
continue;
}
V_158 -> V_239 = 0 ;
V_123 -> V_240 -- ;
F_194 ( & V_233 -> V_241 ,
& V_123 -> V_242 ) ;
F_13 ( & V_123 -> V_51 ) ;
} else {
V_234 ++ ;
V_158 -> V_239 = 0 ;
F_195 ( & V_158 -> V_99 ) ;
}
F_196 ( & V_123 -> V_243 ) ;
if ( ! F_176 ( V_158 ) ) {
switch ( V_158 -> V_225 ) {
case V_218 :
case V_244 :
V_233 -> V_136 . V_140 -= V_158 -> V_140 ;
break;
case V_226 :
V_233 -> V_136 . V_140 += V_158 -> V_140 ;
break;
default:
F_8 ( 1 ) ;
}
}
F_13 ( & V_233 -> V_51 ) ;
V_29 = F_174 ( V_118 , V_35 , V_158 , V_137 ,
V_235 ) ;
F_192 ( V_137 ) ;
if ( V_29 ) {
V_233 -> V_237 = 0 ;
F_191 ( V_233 ) ;
F_94 ( V_158 ) ;
F_193 ( V_37 , L_2 , V_29 ) ;
return V_29 ;
}
if ( F_176 ( V_158 ) ) {
if ( V_233 -> V_193 &&
V_233 -> V_245 < 0 ) {
F_11 ( & V_123 -> V_51 ) ;
V_123 -> V_246 -= V_158 -> V_36 ;
F_13 ( & V_123 -> V_51 ) ;
}
F_191 ( V_233 ) ;
V_233 = NULL ;
}
F_94 ( V_158 ) ;
V_8 ++ ;
F_48 () ;
}
if ( V_234 > 0 ) {
T_2 V_247 = F_197 ( F_198 ( F_186 () , V_32 ) ) ;
T_2 V_248 ;
F_11 ( & V_123 -> V_51 ) ;
V_248 = V_37 -> V_249 * 3 + V_247 ;
V_37 -> V_249 = V_248 >> 2 ;
F_13 ( & V_123 -> V_51 ) ;
}
return 0 ;
}
static T_2 F_199 ( struct V_250 * V_35 )
{
struct V_15 * V_30 = V_35 -> V_15 ;
struct V_219 * V_251 ;
int V_252 = 1 ;
T_2 V_253 ;
T_2 V_254 = 0 , V_71 = 0 ;
V_30 = F_200 ( V_35 ) ;
if ( V_30 ) {
V_251 = F_12 ( V_30 , struct V_219 , V_15 ) ;
V_254 = V_251 -> V_27 ;
}
V_30 = F_201 ( V_35 ) ;
if ( V_30 ) {
V_251 = F_12 ( V_30 , struct V_219 , V_15 ) ;
V_71 = V_251 -> V_27 ;
}
V_30 = V_35 -> V_15 ;
while ( V_30 ) {
V_251 = F_12 ( V_30 , struct V_219 , V_15 ) ;
F_8 ( ! V_251 -> V_239 ) ;
V_253 = V_251 -> V_27 ;
if ( V_252 )
V_30 = V_30 -> V_23 ;
else
V_30 = V_30 -> V_24 ;
V_252 = 1 - V_252 ;
}
return V_253 ;
}
static inline T_2 F_202 ( struct V_34 * V_35 , T_2 V_255 )
{
T_2 V_36 ;
V_36 = V_255 * ( sizeof( struct V_124 ) +
sizeof( struct V_172 ) ) ;
if ( ! F_84 ( V_35 -> V_37 , V_129 ) )
V_36 += V_255 * sizeof( struct V_145 ) ;
return F_203 ( V_36 , F_204 ( V_35 ) ) ;
}
T_2 F_205 ( struct V_34 * V_35 , T_2 V_256 )
{
T_2 V_257 ;
T_2 V_258 ;
T_2 V_259 ;
V_257 = F_204 ( V_35 ) - sizeof( struct V_260 ) ;
V_258 = F_206 ( V_257 ,
( T_2 ) F_207 ( V_35 -> V_37 -> V_261 ) ) ;
V_259 = F_206 ( V_256 , V_35 -> V_56 ) ;
V_259 += V_258 - 1 ;
V_259 = F_206 ( V_259 , V_258 ) ;
return V_259 ;
}
int F_208 ( struct V_117 * V_118 ,
struct V_34 * V_35 )
{
struct V_262 * V_263 ;
T_2 V_240 = V_118 -> V_135 -> V_123 . V_238 ;
T_2 V_256 = V_118 -> V_135 -> V_123 . V_246 ;
T_2 V_264 = V_118 -> V_135 -> V_264 ;
T_2 V_36 , V_265 ;
int V_29 = 0 ;
V_36 = F_209 ( V_35 , 1 ) ;
V_240 = F_202 ( V_35 , V_240 ) ;
if ( V_240 > 1 )
V_36 += ( V_240 - 1 ) * V_35 -> V_55 ;
V_36 <<= 1 ;
V_36 += F_205 ( V_35 , V_256 ) * V_35 -> V_55 ;
V_265 = F_209 ( V_35 ,
V_264 ) ;
V_263 = & V_35 -> V_37 -> V_266 ;
if ( V_263 -> V_95 -> V_116 ) {
V_265 <<= 1 ;
V_36 <<= 1 ;
}
F_11 ( & V_263 -> V_51 ) ;
if ( V_263 -> V_10 <= V_36 + V_265 )
V_29 = 1 ;
F_13 ( & V_263 -> V_51 ) ;
return V_29 ;
}
int F_210 ( struct V_117 * V_118 ,
struct V_34 * V_35 )
{
struct V_12 * V_37 = V_35 -> V_37 ;
T_2 V_243 =
F_211 ( & V_118 -> V_135 -> V_123 . V_243 ) ;
T_2 V_267 ;
T_2 V_268 ;
F_2 () ;
V_267 = V_37 -> V_249 ;
V_268 = V_243 * V_267 ;
if ( V_243 * V_267 >= V_269 )
return 1 ;
if ( V_268 >= V_269 / 2 )
return 2 ;
return F_208 ( V_118 , V_35 ) ;
}
static void F_212 ( struct V_91 * V_92 )
{
struct V_270 * V_271 ;
struct V_117 * V_118 ;
int V_29 ;
V_271 = F_55 ( V_92 , struct V_270 , V_92 ) ;
if ( F_213 ( V_271 -> V_35 -> V_37 ) )
goto V_272;
V_118 = F_214 ( V_271 -> V_35 ) ;
if ( F_215 ( V_118 ) ) {
V_271 -> error = F_216 ( V_118 ) ;
goto V_272;
}
V_118 -> V_273 = true ;
if ( V_118 -> V_274 > V_271 -> V_274 )
goto V_31;
V_29 = F_217 ( V_118 , V_271 -> V_35 , V_271 -> V_8 ) ;
if ( V_29 )
V_271 -> error = V_29 ;
V_31:
V_29 = F_218 ( V_118 , V_271 -> V_35 ) ;
if ( V_29 && ! V_271 -> error )
V_271 -> error = V_29 ;
V_272:
if ( V_271 -> V_273 )
F_219 ( & V_271 -> V_90 ) ;
else
F_9 ( V_271 ) ;
}
int F_220 ( struct V_34 * V_35 ,
unsigned long V_8 , T_2 V_274 , int V_90 )
{
struct V_270 * V_271 ;
int V_29 ;
V_271 = F_221 ( sizeof( * V_271 ) , V_98 ) ;
if ( ! V_271 )
return - V_74 ;
V_271 -> V_35 = V_35 -> V_37 -> V_88 ;
V_271 -> V_8 = V_8 ;
V_271 -> error = 0 ;
V_271 -> V_274 = V_274 ;
if ( V_90 )
V_271 -> V_273 = 1 ;
else
V_271 -> V_273 = 0 ;
F_222 ( & V_271 -> V_90 ) ;
F_66 ( & V_271 -> V_92 , V_275 ,
F_212 , NULL , NULL ) ;
F_74 ( V_35 -> V_37 -> V_276 , & V_271 -> V_92 ) ;
if ( V_90 ) {
F_223 ( & V_271 -> V_90 ) ;
V_29 = V_271 -> error ;
F_9 ( V_271 ) ;
return V_29 ;
}
return 0 ;
}
int F_217 ( struct V_117 * V_118 ,
struct V_34 * V_35 , unsigned long V_8 )
{
struct V_15 * V_136 ;
struct V_122 * V_123 ;
struct V_121 * V_113 ;
int V_29 ;
int V_277 = V_8 == ( unsigned long ) - 1 ;
bool V_278 = V_118 -> V_278 ;
if ( V_118 -> V_228 )
return 0 ;
if ( V_35 -> V_37 -> V_279 )
return 0 ;
if ( V_35 == V_35 -> V_37 -> V_64 )
V_35 = V_35 -> V_37 -> V_88 ;
V_123 = & V_118 -> V_135 -> V_123 ;
if ( V_8 == 0 )
V_8 = F_211 ( & V_123 -> V_243 ) * 2 ;
V_164:
#ifdef F_224
V_123 -> V_280 = F_199 ( & V_123 -> V_35 ) ;
#endif
V_118 -> V_278 = false ;
V_29 = F_185 ( V_118 , V_35 , V_8 ) ;
if ( V_29 < 0 ) {
F_162 ( V_118 , V_35 , V_29 ) ;
return V_29 ;
}
if ( V_277 ) {
if ( ! F_182 ( & V_118 -> V_281 ) )
F_225 ( V_118 , V_35 ) ;
F_11 ( & V_123 -> V_51 ) ;
V_136 = F_200 ( & V_123 -> V_242 ) ;
if ( ! V_136 ) {
F_13 ( & V_123 -> V_51 ) ;
goto V_81;
}
V_8 = ( unsigned long ) - 1 ;
while ( V_136 ) {
V_113 = F_12 ( V_136 , struct V_121 ,
V_241 ) ;
if ( F_176 ( & V_113 -> V_136 ) ) {
struct V_219 * V_158 ;
V_158 = & V_113 -> V_136 ;
F_5 ( & V_158 -> V_120 ) ;
F_13 ( & V_123 -> V_51 ) ;
F_49 ( & V_113 -> V_86 ) ;
F_47 ( & V_113 -> V_86 ) ;
F_94 ( V_158 ) ;
F_48 () ;
goto V_164;
} else {
F_8 ( 1 ) ;
}
V_136 = F_226 ( V_136 ) ;
}
F_13 ( & V_123 -> V_51 ) ;
F_48 () ;
goto V_164;
}
V_81:
F_227 ( V_118 ) ;
V_118 -> V_278 = V_278 ;
return 0 ;
}
int F_228 ( struct V_117 * V_118 ,
struct V_34 * V_35 ,
T_2 V_27 , T_2 V_36 , T_2 V_7 ,
int V_176 , int V_193 )
{
struct V_189 * V_137 ;
int V_29 ;
V_137 = F_229 () ;
if ( ! V_137 )
return - V_74 ;
V_137 -> V_139 = V_7 ;
V_137 -> V_138 = true ;
V_137 -> V_227 = false ;
V_137 -> V_193 = V_193 ? true : false ;
V_137 -> V_176 = V_176 ;
V_29 = F_230 ( V_35 -> V_37 , V_118 , V_27 ,
V_36 , V_137 ) ;
if ( V_29 )
F_192 ( V_137 ) ;
return V_29 ;
}
static T_1 int F_231 ( struct V_117 * V_118 ,
struct V_34 * V_35 ,
struct V_65 * V_66 ,
T_2 V_22 , T_2 V_33 , T_2 V_27 )
{
struct V_121 * V_113 ;
struct V_219 * V_158 ;
struct V_222 * V_282 ;
struct V_122 * V_123 ;
int V_29 = 0 ;
V_123 = & V_118 -> V_135 -> V_123 ;
F_11 ( & V_123 -> V_51 ) ;
V_113 = F_92 ( V_118 , V_27 ) ;
if ( ! V_113 ) {
F_13 ( & V_123 -> V_51 ) ;
return 0 ;
}
if ( ! F_93 ( & V_113 -> V_86 ) ) {
F_5 ( & V_113 -> V_136 . V_120 ) ;
F_13 ( & V_123 -> V_51 ) ;
F_45 ( V_66 ) ;
F_49 ( & V_113 -> V_86 ) ;
F_47 ( & V_113 -> V_86 ) ;
F_94 ( & V_113 -> V_136 ) ;
return - V_187 ;
}
F_13 ( & V_123 -> V_51 ) ;
F_11 ( & V_113 -> V_51 ) ;
F_183 (ref, &head->ref_list, list) {
if ( V_158 -> type != V_163 ) {
V_29 = 1 ;
break;
}
V_282 = F_164 ( V_158 ) ;
if ( V_282 -> V_35 != V_35 -> V_283 . V_22 ||
V_282 -> V_22 != V_22 ||
V_282 -> V_33 != V_33 ) {
V_29 = 1 ;
break;
}
}
F_13 ( & V_113 -> V_51 ) ;
F_47 ( & V_113 -> V_86 ) ;
return V_29 ;
}
static T_1 int F_232 ( struct V_117 * V_118 ,
struct V_34 * V_35 ,
struct V_65 * V_66 ,
T_2 V_22 , T_2 V_33 , T_2 V_27 )
{
struct V_34 * V_64 = V_35 -> V_37 -> V_64 ;
struct V_67 * V_68 ;
struct V_157 * V_158 ;
struct V_172 * V_173 ;
struct V_124 * V_125 ;
struct V_69 V_21 ;
T_3 V_126 ;
int V_29 ;
V_21 . V_22 = V_27 ;
V_21 . V_33 = ( T_2 ) - 1 ;
V_21 . type = V_79 ;
V_29 = F_38 ( NULL , V_64 , & V_21 , V_66 , 0 , 0 ) ;
if ( V_29 < 0 )
goto V_81;
F_32 ( V_29 == 0 ) ;
V_29 = - V_161 ;
if ( V_66 -> V_83 [ 0 ] == 0 )
goto V_81;
V_66 -> V_83 [ 0 ] -- ;
V_68 = V_66 -> V_82 [ 0 ] ;
F_41 ( V_68 , & V_21 , V_66 -> V_83 [ 0 ] ) ;
if ( V_21 . V_22 != V_27 || V_21 . type != V_79 )
goto V_81;
V_29 = 1 ;
V_126 = F_85 ( V_68 , V_66 -> V_83 [ 0 ] ) ;
#ifdef F_89
if ( V_126 < sizeof( * V_125 ) ) {
F_8 ( V_126 != sizeof( struct V_132 ) ) ;
goto V_81;
}
#endif
V_125 = F_86 ( V_68 , V_66 -> V_83 [ 0 ] , struct V_124 ) ;
if ( V_126 != sizeof( * V_125 ) +
F_133 ( V_163 ) )
goto V_81;
if ( F_233 ( V_68 , V_125 ) <=
F_234 ( & V_35 -> V_284 ) )
goto V_81;
V_173 = (struct V_172 * ) ( V_125 + 1 ) ;
if ( F_127 ( V_68 , V_173 ) !=
V_163 )
goto V_81;
V_158 = (struct V_157 * ) ( & V_173 -> V_33 ) ;
if ( F_87 ( V_68 , V_125 ) !=
F_121 ( V_68 , V_158 ) ||
F_108 ( V_68 , V_158 ) !=
V_35 -> V_283 . V_22 ||
F_109 ( V_68 , V_158 ) != V_22 ||
F_110 ( V_68 , V_158 ) != V_33 )
goto V_81;
V_29 = 0 ;
V_81:
return V_29 ;
}
int F_235 ( struct V_117 * V_118 ,
struct V_34 * V_35 ,
T_2 V_22 , T_2 V_33 , T_2 V_27 )
{
struct V_65 * V_66 ;
int V_29 ;
int V_285 ;
V_66 = F_34 () ;
if ( ! V_66 )
return - V_161 ;
do {
V_29 = F_232 ( V_118 , V_35 , V_66 , V_22 ,
V_33 , V_27 ) ;
if ( V_29 && V_29 != - V_161 )
goto V_81;
V_285 = F_231 ( V_118 , V_35 , V_66 , V_22 ,
V_33 , V_27 ) ;
} while ( V_285 == - V_187 );
if ( V_285 && V_285 != - V_161 ) {
V_29 = V_285 ;
goto V_81;
}
if ( V_29 != - V_161 || V_285 != - V_161 )
V_29 = 0 ;
V_81:
F_53 ( V_66 ) ;
if ( V_35 -> V_283 . V_22 == V_286 )
F_8 ( V_29 > 0 ) ;
return V_29 ;
}
static int F_236 ( struct V_117 * V_118 ,
struct V_34 * V_35 ,
struct V_67 * V_287 ,
int V_288 , int V_289 )
{
T_2 V_27 ;
T_2 V_36 ;
T_2 V_17 ;
T_2 V_224 ;
T_3 V_72 ;
struct V_69 V_21 ;
struct V_290 * V_291 ;
int V_42 ;
int V_176 ;
int V_29 = 0 ;
int (* F_237)( struct V_117 * , struct V_34 * ,
T_2 , T_2 , T_2 , T_2 , T_2 , T_2 );
if ( F_238 ( V_35 ) )
return 0 ;
V_224 = F_239 ( V_287 ) ;
V_72 = F_39 ( V_287 ) ;
V_176 = F_240 ( V_287 ) ;
if ( ! F_241 ( V_292 , & V_35 -> V_293 ) && V_176 == 0 )
return 0 ;
if ( V_289 )
F_237 = F_158 ;
else
F_237 = V_294 ;
if ( V_288 )
V_17 = V_287 -> V_32 ;
else
V_17 = 0 ;
for ( V_42 = 0 ; V_42 < V_72 ; V_42 ++ ) {
if ( V_176 == 0 ) {
F_41 ( V_287 , & V_21 , V_42 ) ;
if ( V_21 . type != V_295 )
continue;
V_291 = F_86 ( V_287 , V_42 ,
struct V_290 ) ;
if ( F_242 ( V_287 , V_291 ) ==
V_296 )
continue;
V_27 = F_243 ( V_287 , V_291 ) ;
if ( V_27 == 0 )
continue;
V_36 = F_244 ( V_287 , V_291 ) ;
V_21 . V_33 -= F_245 ( V_287 , V_291 ) ;
V_29 = F_237 ( V_118 , V_35 , V_27 , V_36 ,
V_17 , V_224 , V_21 . V_22 ,
V_21 . V_33 ) ;
if ( V_29 )
goto V_165;
} else {
V_27 = F_246 ( V_287 , V_42 ) ;
V_36 = V_35 -> V_55 ;
V_29 = F_237 ( V_118 , V_35 , V_27 , V_36 ,
V_17 , V_224 , V_176 - 1 , 0 ) ;
if ( V_29 )
goto V_165;
}
}
return 0 ;
V_165:
return V_29 ;
}
int F_247 ( struct V_117 * V_118 , struct V_34 * V_35 ,
struct V_67 * V_287 , int V_288 )
{
return F_236 ( V_118 , V_35 , V_287 , V_288 , 1 ) ;
}
int F_248 ( struct V_117 * V_118 , struct V_34 * V_35 ,
struct V_67 * V_287 , int V_288 )
{
return F_236 ( V_118 , V_35 , V_287 , V_288 , 0 ) ;
}
static int F_249 ( struct V_117 * V_118 ,
struct V_34 * V_35 ,
struct V_65 * V_66 ,
struct V_1 * V_2 )
{
int V_29 ;
struct V_34 * V_64 = V_35 -> V_37 -> V_64 ;
unsigned long V_146 ;
struct V_67 * V_68 ;
V_29 = F_38 ( V_118 , V_64 , & V_2 -> V_21 , V_66 , 0 , 1 ) ;
if ( V_29 ) {
if ( V_29 > 0 )
V_29 = - V_161 ;
goto V_165;
}
V_68 = V_66 -> V_82 [ 0 ] ;
V_146 = F_250 ( V_68 , V_66 -> V_83 [ 0 ] ) ;
F_251 ( V_68 , & V_2 -> V_96 , V_146 , sizeof( V_2 -> V_96 ) ) ;
F_103 ( V_68 ) ;
V_165:
F_45 ( V_66 ) ;
return V_29 ;
}
static struct V_1 *
F_252 ( struct V_34 * V_35 ,
struct V_1 * V_2 )
{
struct V_15 * V_136 ;
F_11 ( & V_35 -> V_37 -> V_18 ) ;
if ( F_253 ( & V_2 -> V_20 ) ) {
const T_2 V_297 = V_2 -> V_21 . V_22 + V_2 -> V_21 . V_33 ;
F_13 ( & V_35 -> V_37 -> V_18 ) ;
F_6 ( V_2 ) ;
V_2 = F_75 ( V_35 -> V_37 ,
V_297 ) ;
return V_2 ;
}
V_136 = F_226 ( & V_2 -> V_20 ) ;
F_6 ( V_2 ) ;
if ( V_136 ) {
V_2 = F_12 ( V_136 , struct V_1 ,
V_20 ) ;
F_4 ( V_2 ) ;
} else
V_2 = NULL ;
F_13 ( & V_35 -> V_37 -> V_18 ) ;
return V_2 ;
}
static int F_254 ( struct V_1 * V_14 ,
struct V_117 * V_118 ,
struct V_65 * V_66 )
{
struct V_34 * V_35 = V_14 -> V_37 -> V_88 ;
struct V_298 * V_298 = NULL ;
T_2 V_299 = 0 ;
int V_300 = V_301 ;
T_2 V_302 = 0 ;
int V_303 = 0 ;
int V_29 = 0 ;
if ( V_14 -> V_21 . V_33 < ( 100 * V_304 ) ) {
F_11 ( & V_14 -> V_51 ) ;
V_14 -> V_305 = V_306 ;
F_13 ( & V_14 -> V_51 ) ;
return 0 ;
}
if ( V_118 -> V_228 )
return 0 ;
V_164:
V_298 = F_255 ( V_35 , V_14 , V_66 ) ;
if ( F_215 ( V_298 ) && F_216 ( V_298 ) != - V_161 ) {
V_29 = F_216 ( V_298 ) ;
F_45 ( V_66 ) ;
goto V_81;
}
if ( F_215 ( V_298 ) ) {
F_32 ( V_303 ) ;
V_303 ++ ;
if ( V_14 -> V_307 )
goto V_131;
V_29 = F_256 ( V_35 , V_118 , V_14 , V_66 ) ;
if ( V_29 )
goto V_131;
goto V_164;
}
if ( V_14 -> V_308 == V_118 -> V_274 &&
F_257 ( V_298 ) ) {
V_300 = V_309 ;
goto V_310;
}
F_258 ( V_298 ) -> V_311 = 0 ;
V_29 = F_259 ( V_118 , V_35 , V_298 ) ;
if ( V_29 ) {
F_162 ( V_118 , V_35 , V_29 ) ;
goto V_310;
}
F_8 ( V_29 ) ;
if ( F_257 ( V_298 ) > 0 ) {
V_29 = F_260 ( V_35 ,
& V_35 -> V_37 -> V_266 ) ;
if ( V_29 )
goto V_310;
V_29 = F_261 ( V_35 , V_118 , NULL , V_298 ) ;
if ( V_29 )
goto V_310;
}
F_11 ( & V_14 -> V_51 ) ;
if ( V_14 -> V_3 != V_4 ||
! F_262 ( V_35 , V_312 ) ) {
V_300 = V_306 ;
F_13 ( & V_14 -> V_51 ) ;
goto V_310;
}
F_13 ( & V_14 -> V_51 ) ;
if ( F_241 ( V_313 , & V_118 -> V_135 -> V_7 ) ) {
V_29 = - V_314 ;
goto V_310;
}
V_302 = F_203 ( V_14 -> V_21 . V_33 , V_315 ) ;
if ( ! V_302 )
V_302 = 1 ;
V_302 *= 16 ;
V_302 *= V_316 ;
V_29 = F_263 ( V_298 , 0 , V_302 ) ;
if ( V_29 )
goto V_310;
V_29 = F_264 ( V_298 , V_118 , 0 , 0 , V_302 ,
V_302 , V_302 ,
& V_299 ) ;
if ( ! V_29 )
V_300 = V_309 ;
else if ( V_29 == - V_314 )
F_265 ( V_313 , & V_118 -> V_135 -> V_7 ) ;
F_266 ( V_298 , 0 , V_302 ) ;
V_310:
F_267 ( V_298 ) ;
V_131:
F_45 ( V_66 ) ;
V_81:
F_11 ( & V_14 -> V_51 ) ;
if ( ! V_29 && V_300 == V_309 )
V_14 -> V_308 = V_118 -> V_274 ;
V_14 -> V_305 = V_300 ;
F_13 ( & V_14 -> V_51 ) ;
return V_29 ;
}
int F_268 ( struct V_117 * V_118 ,
struct V_34 * V_35 )
{
struct V_1 * V_2 , * V_317 ;
struct V_318 * V_319 = V_118 -> V_135 ;
struct V_65 * V_66 ;
if ( F_182 ( & V_319 -> V_320 ) ||
! F_262 ( V_35 , V_312 ) )
return 0 ;
V_66 = F_34 () ;
if ( ! V_66 )
return - V_74 ;
F_269 (cache, tmp, &cur_trans->dirty_bgs,
dirty_list) {
if ( V_2 -> V_305 == V_321 )
F_254 ( V_2 , V_118 , V_66 ) ;
}
F_53 ( V_66 ) ;
return 0 ;
}
int F_270 ( struct V_117 * V_118 ,
struct V_34 * V_35 )
{
struct V_1 * V_2 ;
struct V_318 * V_319 = V_118 -> V_135 ;
int V_29 = 0 ;
int V_322 ;
struct V_65 * V_66 = NULL ;
F_271 ( V_323 ) ;
struct V_112 * V_324 = & V_319 -> V_325 ;
int V_326 = 0 ;
int V_327 = 0 ;
F_11 ( & V_319 -> V_328 ) ;
if ( F_182 ( & V_319 -> V_320 ) ) {
F_13 ( & V_319 -> V_328 ) ;
return 0 ;
}
F_272 ( & V_319 -> V_320 , & V_323 ) ;
F_13 ( & V_319 -> V_328 ) ;
V_164:
F_225 ( V_118 , V_35 ) ;
if ( ! V_66 ) {
V_66 = F_34 () ;
if ( ! V_66 )
return - V_74 ;
}
F_49 ( & V_118 -> V_135 -> V_329 ) ;
while ( ! F_182 ( & V_323 ) ) {
V_2 = F_273 ( & V_323 ,
struct V_1 ,
V_330 ) ;
if ( ! F_182 ( & V_2 -> V_331 ) ) {
F_274 ( & V_2 -> V_331 ) ;
F_275 ( V_35 , V_118 , V_2 ,
& V_2 -> V_332 , V_66 ,
V_2 -> V_21 . V_22 ) ;
F_6 ( V_2 ) ;
}
F_11 ( & V_319 -> V_328 ) ;
F_274 ( & V_2 -> V_330 ) ;
F_13 ( & V_319 -> V_328 ) ;
V_322 = 1 ;
F_254 ( V_2 , V_118 , V_66 ) ;
if ( V_2 -> V_305 == V_309 ) {
V_2 -> V_332 . V_298 = NULL ;
V_29 = F_276 ( V_35 , V_118 , V_2 , V_66 ) ;
if ( V_29 == 0 && V_2 -> V_332 . V_298 ) {
V_326 ++ ;
V_322 = 0 ;
F_72 ( & V_2 -> V_331 , V_324 ) ;
} else {
V_29 = 0 ;
}
}
if ( ! V_29 ) {
V_29 = F_249 ( V_118 , V_35 , V_66 , V_2 ) ;
if ( V_29 == - V_161 ) {
V_29 = 0 ;
F_11 ( & V_319 -> V_328 ) ;
if ( F_182 ( & V_2 -> V_330 ) ) {
F_72 ( & V_2 -> V_330 ,
& V_319 -> V_320 ) ;
F_4 ( V_2 ) ;
}
F_13 ( & V_319 -> V_328 ) ;
} else if ( V_29 ) {
F_162 ( V_118 , V_35 , V_29 ) ;
}
}
if ( V_322 )
F_6 ( V_2 ) ;
if ( V_29 )
break;
F_47 ( & V_118 -> V_135 -> V_329 ) ;
F_49 ( & V_118 -> V_135 -> V_329 ) ;
}
F_47 ( & V_118 -> V_135 -> V_329 ) ;
V_29 = F_217 ( V_118 , V_35 , 0 ) ;
if ( ! V_29 && V_327 == 0 ) {
V_327 ++ ;
F_11 ( & V_319 -> V_328 ) ;
F_272 ( & V_319 -> V_320 , & V_323 ) ;
if ( ! F_182 ( & V_323 ) ) {
F_13 ( & V_319 -> V_328 ) ;
goto V_164;
}
F_13 ( & V_319 -> V_328 ) ;
}
F_53 ( V_66 ) ;
return V_29 ;
}
int F_277 ( struct V_117 * V_118 ,
struct V_34 * V_35 )
{
struct V_1 * V_2 ;
struct V_318 * V_319 = V_118 -> V_135 ;
int V_29 = 0 ;
int V_322 ;
struct V_65 * V_66 ;
struct V_112 * V_324 = & V_319 -> V_325 ;
int V_326 = 0 ;
V_66 = F_34 () ;
if ( ! V_66 )
return - V_74 ;
F_11 ( & V_319 -> V_328 ) ;
while ( ! F_182 ( & V_319 -> V_320 ) ) {
V_2 = F_273 ( & V_319 -> V_320 ,
struct V_1 ,
V_330 ) ;
if ( ! F_182 ( & V_2 -> V_331 ) ) {
F_13 ( & V_319 -> V_328 ) ;
F_274 ( & V_2 -> V_331 ) ;
F_275 ( V_35 , V_118 , V_2 ,
& V_2 -> V_332 , V_66 ,
V_2 -> V_21 . V_22 ) ;
F_6 ( V_2 ) ;
F_11 ( & V_319 -> V_328 ) ;
}
F_274 ( & V_2 -> V_330 ) ;
F_13 ( & V_319 -> V_328 ) ;
V_322 = 1 ;
F_254 ( V_2 , V_118 , V_66 ) ;
if ( ! V_29 )
V_29 = F_217 ( V_118 , V_35 , ( unsigned long ) - 1 ) ;
if ( ! V_29 && V_2 -> V_305 == V_309 ) {
V_2 -> V_332 . V_298 = NULL ;
V_29 = F_276 ( V_35 , V_118 , V_2 , V_66 ) ;
if ( V_29 == 0 && V_2 -> V_332 . V_298 ) {
V_326 ++ ;
V_322 = 0 ;
F_72 ( & V_2 -> V_331 , V_324 ) ;
} else {
V_29 = 0 ;
}
}
if ( ! V_29 ) {
V_29 = F_249 ( V_118 , V_35 , V_66 , V_2 ) ;
if ( V_29 == - V_161 ) {
F_278 ( V_319 -> V_333 ,
F_211 ( & V_319 -> V_334 ) == 1 ) ;
V_29 = F_249 ( V_118 , V_35 , V_66 ,
V_2 ) ;
}
if ( V_29 )
F_162 ( V_118 , V_35 , V_29 ) ;
}
if ( V_322 )
F_6 ( V_2 ) ;
F_11 ( & V_319 -> V_328 ) ;
}
F_13 ( & V_319 -> V_328 ) ;
while ( ! F_182 ( V_324 ) ) {
V_2 = F_273 ( V_324 , struct V_1 ,
V_331 ) ;
F_274 ( & V_2 -> V_331 ) ;
F_275 ( V_35 , V_118 , V_2 ,
& V_2 -> V_332 , V_66 , V_2 -> V_21 . V_22 ) ;
F_6 ( V_2 ) ;
}
F_53 ( V_66 ) ;
return V_29 ;
}
int F_279 ( struct V_34 * V_35 , T_2 V_27 )
{
struct V_1 * V_14 ;
int V_335 = 0 ;
V_14 = F_76 ( V_35 -> V_37 , V_27 ) ;
if ( ! V_14 || V_14 -> V_307 )
V_335 = 1 ;
if ( V_14 )
F_6 ( V_14 ) ;
return V_335 ;
}
bool F_280 ( struct V_12 * V_37 , T_2 V_27 )
{
struct V_1 * V_336 ;
bool V_29 = true ;
V_336 = F_76 ( V_37 , V_27 ) ;
if ( ! V_336 )
return false ;
F_11 ( & V_336 -> V_51 ) ;
if ( V_336 -> V_307 )
V_29 = false ;
else
F_5 ( & V_336 -> V_337 ) ;
F_13 ( & V_336 -> V_51 ) ;
if ( ! V_29 )
F_6 ( V_336 ) ;
return V_29 ;
}
void F_281 ( struct V_12 * V_37 , T_2 V_27 )
{
struct V_1 * V_336 ;
V_336 = F_76 ( V_37 , V_27 ) ;
ASSERT ( V_336 ) ;
if ( F_7 ( & V_336 -> V_337 ) )
F_282 ( & V_336 -> V_337 ) ;
F_6 ( V_336 ) ;
F_6 ( V_336 ) ;
}
static int F_283 ( T_7 * V_338 )
{
F_68 () ;
return 0 ;
}
void F_284 ( struct V_1 * V_336 )
{
F_285 ( & V_336 -> V_337 ,
F_283 ,
V_102 ) ;
}
static const char * F_286 ( T_2 V_7 )
{
switch ( V_7 ) {
case V_54 | V_339 :
return L_3 ;
case V_54 :
return L_4 ;
case V_339 :
return L_5 ;
case V_340 :
return L_6 ;
default:
F_8 ( 1 ) ;
return L_7 ;
} ;
}
static int F_287 ( struct V_12 * V_13 , T_2 V_7 ,
T_2 V_341 , T_2 V_94 ,
struct V_111 * * V_95 )
{
struct V_111 * V_114 ;
int V_42 ;
int V_342 ;
int V_29 ;
if ( V_7 & ( V_343 | V_344 |
V_345 ) )
V_342 = 2 ;
else
V_342 = 1 ;
V_114 = F_77 ( V_13 , V_7 ) ;
if ( V_114 ) {
F_11 ( & V_114 -> V_51 ) ;
V_114 -> V_341 += V_341 ;
V_114 -> V_346 += V_341 * V_342 ;
V_114 -> V_94 += V_94 ;
V_114 -> V_347 += V_94 * V_342 ;
if ( V_341 > 0 )
V_114 -> V_116 = 0 ;
F_13 ( & V_114 -> V_51 ) ;
* V_95 = V_114 ;
return 0 ;
}
V_114 = F_61 ( sizeof( * V_114 ) , V_98 ) ;
if ( ! V_114 )
return - V_74 ;
V_29 = F_288 ( & V_114 -> V_348 , 0 , V_349 ) ;
if ( V_29 ) {
F_9 ( V_114 ) ;
return V_29 ;
}
for ( V_42 = 0 ; V_42 < V_350 ; V_42 ++ )
F_62 ( & V_114 -> V_351 [ V_42 ] ) ;
F_289 ( & V_114 -> V_352 ) ;
F_290 ( & V_114 -> V_51 ) ;
V_114 -> V_7 = V_7 & V_115 ;
V_114 -> V_341 = V_341 ;
V_114 -> V_346 = V_341 * V_342 ;
V_114 -> V_94 = V_94 ;
V_114 -> V_347 = V_94 * V_342 ;
V_114 -> V_353 = 0 ;
V_114 -> V_354 = 0 ;
V_114 -> V_355 = 0 ;
V_114 -> V_356 = 0 ;
V_114 -> V_116 = 0 ;
V_114 -> V_357 = 0 ;
V_114 -> V_358 = V_359 ;
V_114 -> V_360 = 0 ;
V_114 -> V_361 = 0 ;
F_64 ( & V_114 -> V_90 ) ;
F_62 ( & V_114 -> V_362 ) ;
V_29 = F_291 ( & V_114 -> V_363 , & V_364 ,
V_13 -> V_365 , L_8 ,
F_286 ( V_114 -> V_7 ) ) ;
if ( V_29 ) {
F_9 ( V_114 ) ;
return V_29 ;
}
* V_95 = V_114 ;
F_292 ( & V_114 -> V_99 , & V_13 -> V_95 ) ;
if ( V_7 & V_339 )
V_13 -> V_366 = V_114 ;
return V_29 ;
}
static void F_293 ( struct V_12 * V_37 , T_2 V_7 )
{
T_2 V_367 = F_294 ( V_7 ) &
V_368 ;
F_295 ( & V_37 -> V_369 ) ;
if ( V_7 & V_339 )
V_37 -> V_370 |= V_367 ;
if ( V_7 & V_54 )
V_37 -> V_371 |= V_367 ;
if ( V_7 & V_340 )
V_37 -> V_372 |= V_367 ;
F_296 ( & V_37 -> V_369 ) ;
}
static T_2 F_297 ( struct V_12 * V_37 , T_2 V_7 )
{
struct V_373 * V_374 = V_37 -> V_375 ;
T_2 V_376 = 0 ;
if ( ! V_374 )
return 0 ;
if ( V_7 & V_339 &&
V_374 -> V_377 . V_7 & V_378 ) {
V_376 = V_339 | V_374 -> V_377 . V_376 ;
} else if ( V_7 & V_340 &&
V_374 -> V_379 . V_7 & V_378 ) {
V_376 = V_340 | V_374 -> V_379 . V_376 ;
} else if ( V_7 & V_54 &&
V_374 -> V_380 . V_7 & V_378 ) {
V_376 = V_54 | V_374 -> V_380 . V_376 ;
}
return V_376 ;
}
static T_2 F_298 ( struct V_34 * V_35 , T_2 V_7 )
{
T_2 V_381 = V_35 -> V_37 -> V_382 -> V_383 ;
T_2 V_376 ;
T_2 V_384 ;
T_2 V_385 = 0 ;
F_11 ( & V_35 -> V_37 -> V_386 ) ;
V_376 = F_297 ( V_35 -> V_37 , V_7 ) ;
if ( V_376 ) {
if ( ( V_7 & V_376 ) & V_368 ) {
F_13 ( & V_35 -> V_37 -> V_386 ) ;
return F_299 ( V_376 ) ;
}
}
F_13 ( & V_35 -> V_37 -> V_386 ) ;
for ( V_384 = 0 ; V_384 < V_350 ; V_384 ++ ) {
if ( V_381 >= V_387 [ V_384 ] . V_388 )
V_385 |= V_389 [ V_384 ] ;
}
V_385 &= V_7 ;
if ( V_385 & V_390 )
V_385 = V_390 ;
else if ( V_385 & V_391 )
V_385 = V_391 ;
else if ( V_385 & V_345 )
V_385 = V_345 ;
else if ( V_385 & V_344 )
V_385 = V_344 ;
else if ( V_385 & V_392 )
V_385 = V_392 ;
V_7 &= ~ V_393 ;
return F_299 ( V_7 | V_385 ) ;
}
static T_2 F_300 ( struct V_34 * V_35 , T_2 V_394 )
{
unsigned V_236 ;
T_2 V_7 ;
do {
V_7 = V_394 ;
V_236 = F_301 ( & V_35 -> V_37 -> V_369 ) ;
if ( V_7 & V_339 )
V_7 |= V_35 -> V_37 -> V_370 ;
else if ( V_7 & V_340 )
V_7 |= V_35 -> V_37 -> V_372 ;
else if ( V_7 & V_54 )
V_7 |= V_35 -> V_37 -> V_371 ;
} while ( F_302 ( & V_35 -> V_37 -> V_369 , V_236 ) );
return F_298 ( V_35 , V_7 ) ;
}
T_2 F_303 ( struct V_34 * V_35 , int V_377 )
{
T_2 V_7 ;
T_2 V_29 ;
if ( V_377 )
V_7 = V_339 ;
else if ( V_35 == V_35 -> V_37 -> V_395 )
V_7 = V_340 ;
else
V_7 = V_54 ;
V_29 = F_300 ( V_35 , V_7 ) ;
return V_29 ;
}
int F_304 ( struct V_298 * V_298 , T_2 V_212 )
{
struct V_111 * V_366 ;
struct V_34 * V_35 = F_258 ( V_298 ) -> V_35 ;
struct V_12 * V_37 = V_35 -> V_37 ;
T_2 V_396 ;
int V_29 = 0 ;
int V_397 = 2 ;
int V_398 ;
V_212 = F_149 ( V_212 , V_35 -> V_56 ) ;
if ( F_305 ( V_298 ) ) {
V_397 = 0 ;
ASSERT ( V_399 -> V_400 ) ;
}
V_366 = V_37 -> V_366 ;
if ( ! V_366 )
goto V_401;
V_164:
F_11 ( & V_366 -> V_51 ) ;
V_396 = V_366 -> V_94 + V_366 -> V_354 +
V_366 -> V_353 + V_366 -> V_355 +
V_366 -> V_356 ;
if ( V_396 + V_212 > V_366 -> V_341 ) {
struct V_117 * V_118 ;
if ( ! V_366 -> V_116 ) {
T_2 V_402 ;
V_366 -> V_358 = V_403 ;
F_13 ( & V_366 -> V_51 ) ;
V_401:
V_402 = F_303 ( V_35 , 1 ) ;
V_118 = F_214 ( V_35 ) ;
if ( F_215 ( V_118 ) )
return F_216 ( V_118 ) ;
V_29 = F_306 ( V_118 , V_35 -> V_37 -> V_64 ,
V_402 ,
V_359 ) ;
F_218 ( V_118 , V_35 ) ;
if ( V_29 < 0 ) {
if ( V_29 != - V_314 )
return V_29 ;
else {
V_398 = 1 ;
goto V_404;
}
}
if ( ! V_366 )
V_366 = V_37 -> V_366 ;
goto V_164;
}
V_398 = F_307 (
& V_366 -> V_348 ,
V_396 + V_212 - V_366 -> V_341 ) ;
F_13 ( & V_366 -> V_51 ) ;
V_404:
if ( V_397 &&
! F_211 ( & V_35 -> V_37 -> V_405 ) ) {
V_397 -- ;
if ( V_397 > 0 ) {
F_308 ( V_37 , 0 , - 1 ) ;
F_309 ( V_37 , - 1 , 0 , ( T_2 ) - 1 ) ;
}
V_118 = F_214 ( V_35 ) ;
if ( F_215 ( V_118 ) )
return F_216 ( V_118 ) ;
if ( V_398 >= 0 ||
F_241 ( V_406 ,
& V_118 -> V_135 -> V_7 ) ||
V_397 > 0 ) {
V_29 = F_310 ( V_118 , V_35 ) ;
if ( V_29 )
return V_29 ;
F_49 ( & V_35 -> V_37 -> V_407 ) ;
F_47 ( & V_35 -> V_37 -> V_407 ) ;
goto V_164;
} else {
F_218 ( V_118 , V_35 ) ;
}
}
F_311 ( V_35 -> V_37 ,
L_9 ,
V_366 -> V_7 , V_212 , 1 ) ;
return - V_314 ;
}
V_366 -> V_356 += V_212 ;
F_311 ( V_35 -> V_37 , L_10 ,
V_366 -> V_7 , V_212 , 1 ) ;
F_13 ( & V_366 -> V_51 ) ;
return V_29 ;
}
int F_263 ( struct V_298 * V_298 , T_2 V_32 , T_2 V_48 )
{
struct V_34 * V_35 = F_258 ( V_298 ) -> V_35 ;
int V_29 ;
V_48 = F_312 ( V_32 + V_48 , V_35 -> V_56 ) -
F_150 ( V_32 , V_35 -> V_56 ) ;
V_32 = F_150 ( V_32 , V_35 -> V_56 ) ;
V_29 = F_304 ( V_298 , V_48 ) ;
if ( V_29 < 0 )
return V_29 ;
V_29 = F_313 ( V_298 , V_32 , V_48 ) ;
return V_29 ;
}
void F_314 ( struct V_298 * V_298 , T_2 V_32 ,
T_2 V_48 )
{
struct V_34 * V_35 = F_258 ( V_298 ) -> V_35 ;
struct V_111 * V_366 ;
V_48 = F_312 ( V_32 + V_48 , V_35 -> V_56 ) -
F_150 ( V_32 , V_35 -> V_56 ) ;
V_32 = F_150 ( V_32 , V_35 -> V_56 ) ;
V_366 = V_35 -> V_37 -> V_366 ;
F_11 ( & V_366 -> V_51 ) ;
if ( F_8 ( V_366 -> V_356 < V_48 ) )
V_366 -> V_356 = 0 ;
else
V_366 -> V_356 -= V_48 ;
F_311 ( V_35 -> V_37 , L_10 ,
V_366 -> V_7 , V_48 , 0 ) ;
F_13 ( & V_366 -> V_51 ) ;
}
void F_266 ( struct V_298 * V_298 , T_2 V_32 , T_2 V_48 )
{
F_314 ( V_298 , V_32 , V_48 ) ;
F_315 ( V_298 , V_32 , V_48 ) ;
}
static void F_316 ( struct V_12 * V_13 )
{
struct V_112 * V_113 = & V_13 -> V_95 ;
struct V_111 * V_114 ;
F_78 () ;
F_79 (found, head, list) {
if ( V_114 -> V_7 & V_54 )
V_114 -> V_358 = V_403 ;
}
F_80 () ;
}
static inline T_2 F_317 ( struct V_262 * V_408 )
{
return ( V_408 -> V_60 << 1 ) ;
}
static int F_318 ( struct V_34 * V_35 ,
struct V_111 * V_409 , int V_410 )
{
struct V_262 * V_263 = & V_35 -> V_37 -> V_266 ;
T_2 V_36 = V_409 -> V_341 - V_409 -> V_355 ;
T_2 V_411 = V_409 -> V_94 + V_409 -> V_354 ;
T_2 V_412 ;
if ( V_410 == V_403 )
return 1 ;
if ( V_409 -> V_7 & V_54 )
V_411 += F_317 ( V_263 ) ;
if ( V_410 == V_413 ) {
V_412 = F_319 ( V_35 -> V_37 -> V_261 ) ;
V_412 = F_35 ( T_2 , V_414 , F_320 ( V_412 , 1 ) ) ;
if ( V_36 - V_411 < V_412 )
return 1 ;
}
if ( V_411 + V_415 < F_321 ( V_36 , 8 ) )
return 0 ;
return 1 ;
}
static T_2 F_322 ( struct V_34 * V_35 , T_2 type )
{
T_2 V_416 ;
if ( type & ( V_345 |
V_392 |
V_391 |
V_390 ) )
V_416 = V_35 -> V_37 -> V_382 -> V_383 ;
else if ( type & V_344 )
V_416 = 2 ;
else
V_416 = 1 ;
return V_416 ;
}
void F_323 ( struct V_117 * V_118 ,
struct V_34 * V_35 ,
T_2 type )
{
struct V_111 * V_13 ;
T_2 V_417 ;
T_2 V_412 ;
int V_29 = 0 ;
T_2 V_418 ;
ASSERT ( F_324 ( & V_35 -> V_37 -> V_419 ) ) ;
V_13 = F_77 ( V_35 -> V_37 , V_340 ) ;
F_11 ( & V_13 -> V_51 ) ;
V_417 = V_13 -> V_341 - V_13 -> V_94 - V_13 -> V_353 -
V_13 -> V_354 - V_13 -> V_355 -
V_13 -> V_356 ;
F_13 ( & V_13 -> V_51 ) ;
V_418 = F_322 ( V_35 , type ) ;
V_412 = F_325 ( V_35 , V_418 ) +
F_209 ( V_35 , 1 ) ;
if ( V_417 < V_412 && F_262 ( V_35 , V_420 ) ) {
F_326 ( V_35 -> V_37 , L_11 ,
V_417 , V_412 , type ) ;
F_327 ( V_13 , 0 , 0 ) ;
}
if ( V_417 < V_412 ) {
T_2 V_7 ;
V_7 = F_303 ( V_35 -> V_37 -> V_395 , 0 ) ;
V_29 = F_328 ( V_118 , V_35 , V_7 ) ;
}
if ( ! V_29 ) {
V_29 = F_329 ( V_35 -> V_37 -> V_395 ,
& V_35 -> V_37 -> V_421 ,
V_412 , V_422 ) ;
if ( ! V_29 )
V_118 -> V_423 += V_412 ;
}
}
static int F_306 ( struct V_117 * V_118 ,
struct V_34 * V_64 , T_2 V_7 , int V_410 )
{
struct V_111 * V_95 ;
struct V_12 * V_37 = V_64 -> V_37 ;
int V_424 = 0 ;
int V_29 = 0 ;
if ( V_118 -> V_425 )
return - V_314 ;
V_95 = F_77 ( V_64 -> V_37 , V_7 ) ;
if ( ! V_95 ) {
V_29 = F_287 ( V_64 -> V_37 , V_7 ,
0 , 0 , & V_95 ) ;
F_32 ( V_29 ) ;
}
F_32 ( ! V_95 ) ;
V_164:
F_11 ( & V_95 -> V_51 ) ;
if ( V_410 < V_95 -> V_358 )
V_410 = V_95 -> V_358 ;
if ( V_95 -> V_116 ) {
if ( F_318 ( V_64 , V_95 , V_410 ) )
V_29 = - V_314 ;
else
V_29 = 0 ;
F_13 ( & V_95 -> V_51 ) ;
return V_29 ;
}
if ( ! F_318 ( V_64 , V_95 , V_410 ) ) {
F_13 ( & V_95 -> V_51 ) ;
return 0 ;
} else if ( V_95 -> V_360 ) {
V_424 = 1 ;
} else {
V_95 -> V_360 = 1 ;
}
F_13 ( & V_95 -> V_51 ) ;
F_49 ( & V_37 -> V_419 ) ;
if ( V_424 ) {
F_47 ( & V_37 -> V_419 ) ;
V_424 = 0 ;
goto V_164;
}
V_118 -> V_425 = true ;
if ( F_330 ( V_95 ) )
V_7 |= ( V_339 | V_54 ) ;
if ( V_7 & V_339 && V_37 -> V_426 ) {
V_37 -> V_427 ++ ;
if ( ! ( V_37 -> V_427 %
V_37 -> V_426 ) )
F_316 ( V_37 ) ;
}
F_323 ( V_118 , V_64 , V_7 ) ;
V_29 = F_328 ( V_118 , V_64 , V_7 ) ;
V_118 -> V_425 = false ;
F_11 ( & V_95 -> V_51 ) ;
if ( V_29 < 0 && V_29 != - V_314 )
goto V_81;
if ( V_29 )
V_95 -> V_116 = 1 ;
else
V_29 = 1 ;
V_95 -> V_358 = V_359 ;
V_81:
V_95 -> V_360 = 0 ;
F_13 ( & V_95 -> V_51 ) ;
F_47 ( & V_37 -> V_419 ) ;
if ( V_118 -> V_278 &&
V_118 -> V_423 >= ( T_2 ) V_415 ) {
F_225 ( V_118 , V_118 -> V_35 ) ;
F_331 ( V_118 ) ;
}
return V_29 ;
}
static int F_332 ( struct V_34 * V_35 ,
struct V_111 * V_95 , T_2 V_212 ,
enum V_428 V_361 )
{
struct V_262 * V_263 = & V_35 -> V_37 -> V_266 ;
T_2 V_429 = F_303 ( V_35 , 0 ) ;
T_2 V_430 ;
T_2 V_431 ;
T_2 V_396 ;
V_396 = V_95 -> V_94 + V_95 -> V_354 +
V_95 -> V_353 + V_95 -> V_355 ;
F_11 ( & V_263 -> V_51 ) ;
V_430 = F_317 ( V_263 ) ;
F_13 ( & V_263 -> V_51 ) ;
if ( V_396 + V_430 >= V_95 -> V_341 )
return 0 ;
V_396 += V_95 -> V_356 ;
F_11 ( & V_35 -> V_37 -> V_432 ) ;
V_431 = V_35 -> V_37 -> V_433 ;
F_13 ( & V_35 -> V_37 -> V_432 ) ;
if ( V_429 & ( V_343 |
V_344 |
V_345 ) )
V_431 >>= 1 ;
if ( V_361 == V_434 )
V_431 >>= 3 ;
else
V_431 >>= 1 ;
if ( V_396 + V_212 < V_95 -> V_341 + V_431 )
return 1 ;
return 0 ;
}
static void F_333 ( struct V_34 * V_35 ,
unsigned long V_435 , int V_436 )
{
struct V_437 * V_438 = V_35 -> V_37 -> V_438 ;
if ( F_334 ( & V_438 -> V_439 ) ) {
F_335 ( V_438 , V_435 , V_440 ) ;
F_46 ( & V_438 -> V_439 ) ;
} else {
F_308 ( V_35 -> V_37 , 0 , V_436 ) ;
if ( ! V_399 -> V_400 )
F_309 ( V_35 -> V_37 , V_436 ,
0 , ( T_2 ) - 1 ) ;
}
}
static inline int F_336 ( struct V_34 * V_35 , T_2 V_441 )
{
T_2 V_212 ;
int V_43 ;
V_212 = F_209 ( V_35 , 1 ) ;
V_43 = ( int ) F_206 ( V_441 , V_212 ) ;
if ( ! V_43 )
V_43 = 1 ;
return V_43 ;
}
static void F_337 ( struct V_34 * V_35 , T_2 V_441 , T_2 V_442 ,
bool V_443 )
{
struct V_262 * V_444 ;
struct V_111 * V_95 ;
struct V_117 * V_118 ;
T_2 V_445 ;
T_2 V_446 ;
long V_447 ;
unsigned long V_435 ;
int V_327 ;
int V_448 ;
enum V_428 V_361 ;
V_448 = F_336 ( V_35 , V_441 ) ;
V_441 = ( T_2 ) V_448 * V_449 ;
V_118 = (struct V_117 * ) V_399 -> V_400 ;
V_444 = & V_35 -> V_37 -> V_450 ;
V_95 = V_444 -> V_95 ;
V_445 = F_338 (
& V_35 -> V_37 -> V_445 ) ;
if ( V_445 == 0 ) {
if ( V_118 )
return;
if ( V_443 )
F_309 ( V_35 -> V_37 , V_448 ,
0 , ( T_2 ) - 1 ) ;
return;
}
V_327 = 0 ;
while ( V_445 && V_327 < 3 ) {
V_446 = F_339 ( V_445 , V_441 ) ;
V_435 = V_446 >> V_451 ;
F_333 ( V_35 , V_435 , V_448 ) ;
V_446 = F_211 ( & V_35 -> V_37 -> V_452 ) ;
if ( ! V_446 )
goto V_453;
if ( V_446 <= V_435 )
V_446 = 0 ;
else
V_446 -= V_435 ;
F_278 ( V_35 -> V_37 -> V_454 ,
F_211 ( & V_35 -> V_37 -> V_452 ) <=
( int ) V_446 ) ;
V_453:
if ( ! V_118 )
V_361 = V_434 ;
else
V_361 = V_422 ;
F_11 ( & V_95 -> V_51 ) ;
if ( F_332 ( V_35 , V_95 , V_442 , V_361 ) ) {
F_13 ( & V_95 -> V_51 ) ;
break;
}
F_13 ( & V_95 -> V_51 ) ;
V_327 ++ ;
if ( V_443 && ! V_118 ) {
F_309 ( V_35 -> V_37 , V_448 ,
0 , ( T_2 ) - 1 ) ;
} else {
V_447 = F_340 ( 1 ) ;
if ( V_447 )
break;
}
V_445 = F_338 (
& V_35 -> V_37 -> V_445 ) ;
}
}
static int F_341 ( struct V_34 * V_35 ,
struct V_111 * V_95 ,
T_2 V_212 , int V_410 )
{
struct V_262 * V_455 = & V_35 -> V_37 -> V_456 ;
struct V_117 * V_118 ;
V_118 = (struct V_117 * ) V_399 -> V_400 ;
if ( V_118 )
return - V_187 ;
if ( V_410 )
goto V_457;
if ( F_307 ( & V_95 -> V_348 ,
V_212 ) >= 0 )
goto V_457;
if ( V_95 != V_455 -> V_95 )
return - V_314 ;
F_11 ( & V_455 -> V_51 ) ;
if ( F_307 ( & V_95 -> V_348 ,
V_212 - V_455 -> V_60 ) >= 0 ) {
F_13 ( & V_455 -> V_51 ) ;
return - V_314 ;
}
F_13 ( & V_455 -> V_51 ) ;
V_457:
V_118 = F_214 ( V_35 ) ;
if ( F_215 ( V_118 ) )
return - V_314 ;
return F_310 ( V_118 , V_35 ) ;
}
static int F_342 ( struct V_34 * V_35 ,
struct V_111 * V_95 , T_2 V_36 ,
T_2 V_458 , int V_293 )
{
struct V_117 * V_118 ;
int V_43 ;
int V_29 = 0 ;
switch ( V_293 ) {
case V_459 :
case V_460 :
if ( V_293 == V_459 )
V_43 = F_336 ( V_35 , V_36 ) * 2 ;
else
V_43 = - 1 ;
V_118 = F_214 ( V_35 ) ;
if ( F_215 ( V_118 ) ) {
V_29 = F_216 ( V_118 ) ;
break;
}
V_29 = F_343 ( V_118 , V_35 , V_43 ) ;
F_218 ( V_118 , V_35 ) ;
break;
case V_461 :
case V_462 :
F_337 ( V_35 , V_36 * 2 , V_458 ,
V_293 == V_462 ) ;
break;
case V_463 :
V_118 = F_214 ( V_35 ) ;
if ( F_215 ( V_118 ) ) {
V_29 = F_216 ( V_118 ) ;
break;
}
V_29 = F_306 ( V_118 , V_35 -> V_37 -> V_64 ,
F_303 ( V_35 , 0 ) ,
V_359 ) ;
F_218 ( V_118 , V_35 ) ;
if ( V_29 == - V_314 )
V_29 = 0 ;
break;
case V_464 :
V_29 = F_341 ( V_35 , V_95 , V_458 , 0 ) ;
break;
default:
V_29 = - V_314 ;
break;
}
return V_29 ;
}
static inline T_2
F_344 ( struct V_34 * V_35 ,
struct V_111 * V_95 )
{
T_2 V_396 ;
T_2 V_465 ;
T_2 V_441 ;
V_441 = F_24 ( T_2 , F_345 () * V_304 , V_466 ) ;
F_11 ( & V_95 -> V_51 ) ;
if ( F_332 ( V_35 , V_95 , V_441 ,
V_434 ) ) {
V_441 = 0 ;
goto V_81;
}
V_396 = V_95 -> V_94 + V_95 -> V_354 +
V_95 -> V_353 + V_95 -> V_355 +
V_95 -> V_356 ;
if ( F_332 ( V_35 , V_95 , V_304 , V_434 ) )
V_465 = F_320 ( V_95 -> V_341 , 95 ) ;
else
V_465 = F_320 ( V_95 -> V_341 , 90 ) ;
if ( V_396 > V_465 )
V_441 = V_396 - V_465 ;
else
V_441 = 0 ;
V_441 = F_339 ( V_441 , V_95 -> V_356 +
V_95 -> V_354 ) ;
V_81:
F_13 ( & V_95 -> V_51 ) ;
return V_441 ;
}
static inline int F_346 ( struct V_111 * V_95 ,
struct V_12 * V_37 , T_2 V_396 )
{
T_2 V_412 = F_320 ( V_95 -> V_341 , 98 ) ;
if ( ( V_95 -> V_94 + V_95 -> V_354 ) >= V_412 )
return 0 ;
return ( V_396 >= V_412 && ! F_40 ( V_37 ) &&
! F_241 ( V_467 , & V_37 -> V_468 ) ) ;
}
static int F_347 ( struct V_111 * V_95 ,
struct V_12 * V_37 ,
int V_469 )
{
T_2 V_396 ;
F_11 ( & V_95 -> V_51 ) ;
if ( V_469 > V_464 && V_95 -> V_116 ) {
F_13 ( & V_95 -> V_51 ) ;
return 0 ;
}
V_396 = V_95 -> V_94 + V_95 -> V_354 +
V_95 -> V_353 + V_95 -> V_355 +
V_95 -> V_356 ;
if ( F_346 ( V_95 , V_37 , V_396 ) ) {
F_13 ( & V_95 -> V_51 ) ;
return 1 ;
}
F_13 ( & V_95 -> V_51 ) ;
return 0 ;
}
static void F_348 ( struct V_470 * V_92 )
{
struct V_12 * V_37 ;
struct V_111 * V_95 ;
T_2 V_441 ;
int V_469 ;
V_37 = F_55 ( V_92 , struct V_12 , V_471 ) ;
V_95 = F_77 ( V_37 , V_54 ) ;
V_441 = F_344 ( V_37 -> V_472 ,
V_95 ) ;
if ( ! V_441 )
return;
V_469 = V_459 ;
do {
F_342 ( V_37 -> V_472 , V_95 , V_441 ,
V_441 , V_469 ) ;
V_469 ++ ;
if ( ! F_347 ( V_95 , V_37 ,
V_469 ) )
return;
} while ( V_469 < V_464 );
}
void F_349 ( struct V_470 * V_92 )
{
F_350 ( V_92 , F_348 ) ;
}
static int F_351 ( struct V_34 * V_35 ,
struct V_262 * V_444 ,
T_2 V_458 ,
enum V_428 V_361 )
{
struct V_111 * V_95 = V_444 -> V_95 ;
T_2 V_396 ;
T_2 V_36 = V_458 ;
int V_469 = V_459 ;
int V_29 = 0 ;
bool V_473 = false ;
V_164:
V_29 = 0 ;
F_11 ( & V_95 -> V_51 ) ;
while ( V_361 == V_434 && ! V_473 &&
V_95 -> V_361 ) {
F_13 ( & V_95 -> V_51 ) ;
if ( V_399 -> V_400 )
return - V_187 ;
V_29 = F_352 ( V_95 -> V_90 , ! V_95 -> V_361 ) ;
if ( V_29 )
return - V_474 ;
F_11 ( & V_95 -> V_51 ) ;
}
V_29 = - V_314 ;
V_396 = V_95 -> V_94 + V_95 -> V_354 +
V_95 -> V_353 + V_95 -> V_355 +
V_95 -> V_356 ;
if ( V_396 <= V_95 -> V_341 ) {
if ( V_396 + V_458 <= V_95 -> V_341 ) {
V_95 -> V_356 += V_458 ;
F_311 ( V_35 -> V_37 ,
L_10 , V_95 -> V_7 , V_458 , 1 ) ;
V_29 = 0 ;
} else {
V_36 = V_458 ;
}
} else {
V_36 = V_396 - V_95 -> V_341 +
( V_458 * 2 ) ;
}
if ( V_29 && F_332 ( V_35 , V_95 , V_458 , V_361 ) ) {
V_95 -> V_356 += V_458 ;
F_311 ( V_35 -> V_37 , L_10 ,
V_95 -> V_7 , V_458 ,
1 ) ;
V_29 = 0 ;
}
if ( V_29 && V_361 != V_422 ) {
V_473 = true ;
V_95 -> V_361 = 1 ;
} else if ( ! V_29 && V_95 -> V_7 & V_54 ) {
V_396 += V_458 ;
if ( ! V_35 -> V_37 -> V_475 &&
F_346 ( V_95 , V_35 -> V_37 , V_396 ) &&
! F_353 ( & V_35 -> V_37 -> V_471 ) )
F_354 ( V_476 ,
& V_35 -> V_37 -> V_471 ) ;
}
F_13 ( & V_95 -> V_51 ) ;
if ( ! V_29 || V_361 == V_422 )
goto V_81;
V_29 = F_342 ( V_35 , V_95 , V_36 , V_458 ,
V_469 ) ;
V_469 ++ ;
if ( V_361 == V_477 &&
( V_469 == V_461 ||
V_469 == V_462 ) )
V_469 = V_463 ;
if ( ! V_29 )
goto V_164;
else if ( V_361 == V_477 &&
V_469 < V_464 )
goto V_164;
else if ( V_361 == V_434 &&
V_469 <= V_464 )
goto V_164;
V_81:
if ( V_29 == - V_314 &&
F_355 ( V_35 -> V_478 == V_479 ) ) {
struct V_262 * V_263 =
& V_35 -> V_37 -> V_266 ;
if ( V_444 != V_263 &&
! F_356 ( V_263 , V_458 ) )
V_29 = 0 ;
}
if ( V_29 == - V_314 )
F_311 ( V_35 -> V_37 ,
L_9 ,
V_95 -> V_7 , V_458 , 1 ) ;
if ( V_473 ) {
F_11 ( & V_95 -> V_51 ) ;
V_95 -> V_361 = 0 ;
F_357 ( & V_95 -> V_90 ) ;
F_13 ( & V_95 -> V_51 ) ;
}
return V_29 ;
}
static struct V_262 * F_358 (
const struct V_117 * V_118 ,
const struct V_34 * V_35 )
{
struct V_262 * V_444 = NULL ;
if ( F_241 ( V_292 , & V_35 -> V_293 ) ||
( V_35 == V_35 -> V_37 -> V_480 && V_118 -> V_481 ) ||
( V_35 == V_35 -> V_37 -> V_482 ) )
V_444 = V_118 -> V_444 ;
if ( ! V_444 )
V_444 = V_35 -> V_444 ;
if ( ! V_444 )
V_444 = & V_35 -> V_37 -> V_483 ;
return V_444 ;
}
static int F_356 ( struct V_262 * V_444 ,
T_2 V_36 )
{
int V_29 = - V_314 ;
F_11 ( & V_444 -> V_51 ) ;
if ( V_444 -> V_10 >= V_36 ) {
V_444 -> V_10 -= V_36 ;
if ( V_444 -> V_10 < V_444 -> V_60 )
V_444 -> V_116 = 0 ;
V_29 = 0 ;
}
F_13 ( & V_444 -> V_51 ) ;
return V_29 ;
}
static void F_359 ( struct V_262 * V_444 ,
T_2 V_36 , int V_484 )
{
F_11 ( & V_444 -> V_51 ) ;
V_444 -> V_10 += V_36 ;
if ( V_484 )
V_444 -> V_60 += V_36 ;
else if ( V_444 -> V_10 >= V_444 -> V_60 )
V_444 -> V_116 = 1 ;
F_13 ( & V_444 -> V_51 ) ;
}
int F_360 ( struct V_12 * V_37 ,
struct V_262 * V_485 , T_2 V_36 ,
int V_486 )
{
struct V_262 * V_263 = & V_37 -> V_266 ;
T_2 V_487 ;
if ( V_263 -> V_95 != V_485 -> V_95 )
return - V_314 ;
F_11 ( & V_263 -> V_51 ) ;
V_487 = F_321 ( V_263 -> V_60 , V_486 ) ;
if ( V_263 -> V_10 < V_487 + V_36 ) {
F_13 ( & V_263 -> V_51 ) ;
return - V_314 ;
}
V_263 -> V_10 -= V_36 ;
if ( V_263 -> V_10 < V_263 -> V_60 )
V_263 -> V_116 = 0 ;
F_13 ( & V_263 -> V_51 ) ;
F_359 ( V_485 , V_36 , 1 ) ;
return 0 ;
}
static void F_361 ( struct V_12 * V_37 ,
struct V_262 * V_444 ,
struct V_262 * V_485 , T_2 V_36 )
{
struct V_111 * V_95 = V_444 -> V_95 ;
F_11 ( & V_444 -> V_51 ) ;
if ( V_36 == ( T_2 ) - 1 )
V_36 = V_444 -> V_60 ;
V_444 -> V_60 -= V_36 ;
if ( V_444 -> V_10 >= V_444 -> V_60 ) {
V_36 = V_444 -> V_10 - V_444 -> V_60 ;
V_444 -> V_10 = V_444 -> V_60 ;
V_444 -> V_116 = 1 ;
} else {
V_36 = 0 ;
}
F_13 ( & V_444 -> V_51 ) ;
if ( V_36 > 0 ) {
if ( V_485 ) {
F_11 ( & V_485 -> V_51 ) ;
if ( ! V_485 -> V_116 ) {
T_2 V_488 ;
V_488 = V_485 -> V_60 - V_485 -> V_10 ;
V_488 = F_339 ( V_36 , V_488 ) ;
V_485 -> V_10 += V_488 ;
if ( V_485 -> V_10 >= V_485 -> V_60 )
V_485 -> V_116 = 1 ;
V_36 -= V_488 ;
}
F_13 ( & V_485 -> V_51 ) ;
}
if ( V_36 ) {
F_11 ( & V_95 -> V_51 ) ;
V_95 -> V_356 -= V_36 ;
F_311 ( V_37 , L_10 ,
V_95 -> V_7 , V_36 , 0 ) ;
F_13 ( & V_95 -> V_51 ) ;
}
}
}
static int F_362 ( struct V_262 * V_489 ,
struct V_262 * V_490 , T_2 V_36 )
{
int V_29 ;
V_29 = F_356 ( V_489 , V_36 ) ;
if ( V_29 )
return V_29 ;
F_359 ( V_490 , V_36 , 1 ) ;
return 0 ;
}
void F_363 ( struct V_262 * V_491 , unsigned short type )
{
memset ( V_491 , 0 , sizeof( * V_491 ) ) ;
F_290 ( & V_491 -> V_51 ) ;
V_491 -> type = type ;
}
struct V_262 * F_364 ( struct V_34 * V_35 ,
unsigned short type )
{
struct V_262 * V_444 ;
struct V_12 * V_37 = V_35 -> V_37 ;
V_444 = F_221 ( sizeof( * V_444 ) , V_98 ) ;
if ( ! V_444 )
return NULL ;
F_363 ( V_444 , type ) ;
V_444 -> V_95 = F_77 ( V_37 ,
V_54 ) ;
return V_444 ;
}
void F_365 ( struct V_34 * V_35 ,
struct V_262 * V_491 )
{
if ( ! V_491 )
return;
F_366 ( V_35 , V_491 , ( T_2 ) - 1 ) ;
F_9 ( V_491 ) ;
}
void F_367 ( struct V_262 * V_491 )
{
F_9 ( V_491 ) ;
}
int F_329 ( struct V_34 * V_35 ,
struct V_262 * V_444 , T_2 V_36 ,
enum V_428 V_361 )
{
int V_29 ;
if ( V_36 == 0 )
return 0 ;
V_29 = F_351 ( V_35 , V_444 , V_36 , V_361 ) ;
if ( ! V_29 ) {
F_359 ( V_444 , V_36 , 1 ) ;
return 0 ;
}
return V_29 ;
}
int F_368 ( struct V_34 * V_35 ,
struct V_262 * V_444 , int V_486 )
{
T_2 V_36 = 0 ;
int V_29 = - V_314 ;
if ( ! V_444 )
return 0 ;
F_11 ( & V_444 -> V_51 ) ;
V_36 = F_321 ( V_444 -> V_60 , V_486 ) ;
if ( V_444 -> V_10 >= V_36 )
V_29 = 0 ;
F_13 ( & V_444 -> V_51 ) ;
return V_29 ;
}
int F_369 ( struct V_34 * V_35 ,
struct V_262 * V_444 , T_2 V_492 ,
enum V_428 V_361 )
{
T_2 V_36 = 0 ;
int V_29 = - V_314 ;
if ( ! V_444 )
return 0 ;
F_11 ( & V_444 -> V_51 ) ;
V_36 = V_492 ;
if ( V_444 -> V_10 >= V_36 )
V_29 = 0 ;
else
V_36 -= V_444 -> V_10 ;
F_13 ( & V_444 -> V_51 ) ;
if ( ! V_29 )
return 0 ;
V_29 = F_351 ( V_35 , V_444 , V_36 , V_361 ) ;
if ( ! V_29 ) {
F_359 ( V_444 , V_36 , 0 ) ;
return 0 ;
}
return V_29 ;
}
int F_370 ( struct V_262 * V_493 ,
struct V_262 * V_494 ,
T_2 V_36 )
{
return F_362 ( V_493 , V_494 , V_36 ) ;
}
void F_366 ( struct V_34 * V_35 ,
struct V_262 * V_444 ,
T_2 V_36 )
{
struct V_262 * V_263 = & V_35 -> V_37 -> V_266 ;
if ( V_263 == V_444 ||
V_444 -> V_95 != V_263 -> V_95 )
V_263 = NULL ;
F_361 ( V_35 -> V_37 , V_444 , V_263 ,
V_36 ) ;
}
static T_2 F_371 ( struct V_12 * V_37 )
{
struct V_111 * V_409 ;
T_2 V_36 ;
T_2 V_495 ;
T_2 V_496 ;
int V_257 = F_207 ( V_37 -> V_261 ) ;
V_409 = F_77 ( V_37 , V_339 ) ;
F_11 ( & V_409 -> V_51 ) ;
V_496 = V_409 -> V_94 ;
F_13 ( & V_409 -> V_51 ) ;
V_409 = F_77 ( V_37 , V_54 ) ;
F_11 ( & V_409 -> V_51 ) ;
if ( V_409 -> V_7 & V_339 )
V_496 = 0 ;
V_495 = V_409 -> V_94 ;
F_13 ( & V_409 -> V_51 ) ;
V_36 = ( V_496 >> V_37 -> V_438 -> V_497 ) *
V_257 * 2 ;
V_36 += F_203 ( V_496 + V_495 , 50 ) ;
if ( V_36 * 3 > V_495 )
V_36 = F_203 ( V_495 , 3 ) ;
return F_149 ( V_36 , V_37 -> V_64 -> V_55 << 10 ) ;
}
static void F_372 ( struct V_12 * V_37 )
{
struct V_262 * V_444 = & V_37 -> V_266 ;
struct V_111 * V_409 = V_444 -> V_95 ;
T_2 V_36 ;
V_36 = F_371 ( V_37 ) ;
F_11 ( & V_409 -> V_51 ) ;
F_11 ( & V_444 -> V_51 ) ;
V_444 -> V_60 = F_24 ( T_2 , V_36 , V_498 ) ;
if ( V_444 -> V_10 < V_444 -> V_60 ) {
V_36 = V_409 -> V_94 + V_409 -> V_353 +
V_409 -> V_354 + V_409 -> V_355 +
V_409 -> V_356 ;
if ( V_409 -> V_341 > V_36 ) {
V_36 = V_409 -> V_341 - V_36 ;
V_36 = F_339 ( V_36 ,
V_444 -> V_60 - V_444 -> V_10 ) ;
V_444 -> V_10 += V_36 ;
V_409 -> V_356 += V_36 ;
F_311 ( V_37 , L_10 ,
V_409 -> V_7 , V_36 ,
1 ) ;
}
} else if ( V_444 -> V_10 > V_444 -> V_60 ) {
V_36 = V_444 -> V_10 - V_444 -> V_60 ;
V_409 -> V_356 -= V_36 ;
F_311 ( V_37 , L_10 ,
V_409 -> V_7 , V_36 , 0 ) ;
V_444 -> V_10 = V_444 -> V_60 ;
}
if ( V_444 -> V_10 == V_444 -> V_60 )
V_444 -> V_116 = 1 ;
else
V_444 -> V_116 = 0 ;
F_13 ( & V_444 -> V_51 ) ;
F_13 ( & V_409 -> V_51 ) ;
}
static void F_373 ( struct V_12 * V_37 )
{
struct V_111 * V_95 ;
V_95 = F_77 ( V_37 , V_340 ) ;
V_37 -> V_421 . V_95 = V_95 ;
V_95 = F_77 ( V_37 , V_54 ) ;
V_37 -> V_266 . V_95 = V_95 ;
V_37 -> V_450 . V_95 = V_95 ;
V_37 -> V_499 . V_95 = V_95 ;
V_37 -> V_483 . V_95 = V_95 ;
V_37 -> V_456 . V_95 = V_95 ;
V_37 -> V_64 -> V_444 = & V_37 -> V_266 ;
V_37 -> V_480 -> V_444 = & V_37 -> V_266 ;
V_37 -> V_500 -> V_444 = & V_37 -> V_266 ;
V_37 -> V_88 -> V_444 = & V_37 -> V_266 ;
if ( V_37 -> V_501 )
V_37 -> V_501 -> V_444 = & V_37 -> V_266 ;
V_37 -> V_395 -> V_444 = & V_37 -> V_421 ;
F_372 ( V_37 ) ;
}
static void F_374 ( struct V_12 * V_37 )
{
F_361 ( V_37 , & V_37 -> V_266 , NULL ,
( T_2 ) - 1 ) ;
F_8 ( V_37 -> V_450 . V_60 > 0 ) ;
F_8 ( V_37 -> V_450 . V_10 > 0 ) ;
F_8 ( V_37 -> V_499 . V_60 > 0 ) ;
F_8 ( V_37 -> V_499 . V_10 > 0 ) ;
F_8 ( V_37 -> V_421 . V_60 > 0 ) ;
F_8 ( V_37 -> V_421 . V_10 > 0 ) ;
F_8 ( V_37 -> V_456 . V_60 > 0 ) ;
F_8 ( V_37 -> V_456 . V_10 > 0 ) ;
}
void F_375 ( struct V_117 * V_118 ,
struct V_34 * V_35 )
{
if ( ! V_118 -> V_444 )
return;
if ( ! V_118 -> V_354 )
return;
F_311 ( V_35 -> V_37 , L_12 ,
V_118 -> V_274 , V_118 -> V_354 , 0 ) ;
F_366 ( V_35 , V_118 -> V_444 , V_118 -> V_354 ) ;
V_118 -> V_354 = 0 ;
}
void F_331 ( struct V_117 * V_118 )
{
struct V_12 * V_37 = V_118 -> V_35 -> V_37 ;
if ( ! V_118 -> V_423 )
return;
F_376 ( ! F_182 ( & V_118 -> V_281 ) ) ;
F_361 ( V_37 , & V_37 -> V_421 , NULL ,
V_118 -> V_423 ) ;
V_118 -> V_423 = 0 ;
}
int F_377 ( struct V_117 * V_118 ,
struct V_298 * V_298 )
{
struct V_34 * V_35 = F_258 ( V_298 ) -> V_35 ;
struct V_262 * V_493 = F_358 ( V_118 , V_35 ) ;
struct V_262 * V_494 = V_35 -> V_502 ;
T_2 V_36 = F_209 ( V_35 , 1 ) ;
F_311 ( V_35 -> V_37 , L_13 ,
F_378 ( V_298 ) , V_36 , 1 ) ;
return F_362 ( V_493 , V_494 , V_36 ) ;
}
void F_379 ( struct V_298 * V_298 )
{
struct V_34 * V_35 = F_258 ( V_298 ) -> V_35 ;
T_2 V_36 = F_209 ( V_35 , 1 ) ;
F_311 ( V_35 -> V_37 , L_13 ,
F_378 ( V_298 ) , V_36 , 0 ) ;
F_366 ( V_35 , V_35 -> V_502 , V_36 ) ;
}
int F_380 ( struct V_34 * V_35 ,
struct V_262 * V_491 ,
int V_448 ,
T_2 * V_231 ,
bool V_503 )
{
T_2 V_36 ;
int V_29 ;
struct V_262 * V_263 = & V_35 -> V_37 -> V_266 ;
if ( V_35 -> V_37 -> V_504 ) {
V_36 = 3 * V_35 -> V_55 ;
V_29 = F_381 ( V_35 , V_36 ) ;
if ( V_29 )
return V_29 ;
} else {
V_36 = 0 ;
}
* V_231 = V_36 ;
V_36 = F_209 ( V_35 , V_448 ) ;
V_491 -> V_95 = F_77 ( V_35 -> V_37 ,
V_54 ) ;
V_29 = F_329 ( V_35 , V_491 , V_36 ,
V_434 ) ;
if ( V_29 == - V_314 && V_503 )
V_29 = F_370 ( V_263 , V_491 , V_36 ) ;
if ( V_29 && * V_231 )
F_382 ( V_35 , * V_231 ) ;
return V_29 ;
}
void F_383 ( struct V_34 * V_35 ,
struct V_262 * V_491 ,
T_2 V_231 )
{
F_366 ( V_35 , V_491 , ( T_2 ) - 1 ) ;
}
static unsigned F_384 ( struct V_298 * V_298 , T_2 V_36 )
{
unsigned V_505 = 0 ;
unsigned V_506 = 0 ;
unsigned V_507 = 0 ;
V_507 = ( unsigned ) F_206 ( V_36 +
V_508 - 1 ,
V_508 ) ;
ASSERT ( V_507 ) ;
ASSERT ( F_258 ( V_298 ) -> V_509 >= V_507 ) ;
F_258 ( V_298 ) -> V_509 -= V_507 ;
if ( F_258 ( V_298 ) -> V_509 == 0 &&
F_385 ( V_510 ,
& F_258 ( V_298 ) -> V_511 ) )
V_505 = 1 ;
if ( F_258 ( V_298 ) -> V_509 >=
F_258 ( V_298 ) -> V_512 )
return V_505 ;
V_506 = F_258 ( V_298 ) -> V_512 -
F_258 ( V_298 ) -> V_509 ;
F_258 ( V_298 ) -> V_512 -= V_506 ;
return V_506 + V_505 ;
}
static T_2 F_386 ( struct V_298 * V_298 , T_2 V_36 ,
int V_513 )
{
struct V_34 * V_35 = F_258 ( V_298 ) -> V_35 ;
T_2 V_514 , V_259 ;
if ( F_258 ( V_298 ) -> V_7 & V_515 &&
F_258 ( V_298 ) -> V_256 == 0 )
return 0 ;
V_514 = F_205 ( V_35 , F_258 ( V_298 ) -> V_256 ) ;
if ( V_513 )
F_258 ( V_298 ) -> V_256 += V_36 ;
else
F_258 ( V_298 ) -> V_256 -= V_36 ;
V_259 = F_205 ( V_35 , F_258 ( V_298 ) -> V_256 ) ;
if ( V_514 == V_259 )
return 0 ;
if ( V_513 )
return F_209 ( V_35 ,
V_259 - V_514 ) ;
return F_209 ( V_35 , V_514 - V_259 ) ;
}
int F_387 ( struct V_298 * V_298 , T_2 V_36 )
{
struct V_34 * V_35 = F_258 ( V_298 ) -> V_35 ;
struct V_262 * V_444 = & V_35 -> V_37 -> V_450 ;
T_2 V_516 = 0 ;
T_2 V_256 ;
unsigned V_517 = 0 ;
int V_518 = 0 ;
enum V_428 V_361 = V_434 ;
int V_29 = 0 ;
bool V_519 = true ;
T_2 V_520 = 0 ;
unsigned V_521 ;
if ( F_305 ( V_298 ) ) {
V_361 = V_422 ;
V_519 = false ;
}
if ( V_361 != V_422 &&
F_388 ( V_35 -> V_37 ) )
F_389 ( 1 ) ;
if ( V_519 )
F_49 ( & F_258 ( V_298 ) -> V_522 ) ;
V_36 = F_149 ( V_36 , V_35 -> V_56 ) ;
F_11 ( & F_258 ( V_298 ) -> V_51 ) ;
V_517 = ( unsigned ) F_206 ( V_36 +
V_508 - 1 ,
V_508 ) ;
F_258 ( V_298 ) -> V_509 += V_517 ;
V_517 = 0 ;
if ( F_258 ( V_298 ) -> V_509 >
F_258 ( V_298 ) -> V_512 )
V_517 = F_258 ( V_298 ) -> V_509 -
F_258 ( V_298 ) -> V_512 ;
if ( ! F_241 ( V_510 ,
& F_258 ( V_298 ) -> V_511 ) ) {
V_517 ++ ;
V_518 = 1 ;
}
V_516 = F_209 ( V_35 , V_517 ) ;
V_516 += F_386 ( V_298 , V_36 , 1 ) ;
V_256 = F_258 ( V_298 ) -> V_256 ;
F_13 ( & F_258 ( V_298 ) -> V_51 ) ;
if ( V_35 -> V_37 -> V_504 ) {
V_29 = F_381 ( V_35 ,
V_517 * V_35 -> V_55 ) ;
if ( V_29 )
goto V_523;
}
V_29 = F_351 ( V_35 , V_444 , V_516 , V_361 ) ;
if ( F_355 ( V_29 ) ) {
F_382 ( V_35 , V_517 * V_35 -> V_55 ) ;
goto V_523;
}
F_11 ( & F_258 ( V_298 ) -> V_51 ) ;
if ( V_518 ) {
F_265 ( V_510 ,
& F_258 ( V_298 ) -> V_511 ) ;
V_517 -- ;
}
F_258 ( V_298 ) -> V_512 += V_517 ;
F_13 ( & F_258 ( V_298 ) -> V_51 ) ;
if ( V_519 )
F_47 ( & F_258 ( V_298 ) -> V_522 ) ;
if ( V_516 )
F_311 ( V_35 -> V_37 , L_14 ,
F_378 ( V_298 ) , V_516 , 1 ) ;
F_359 ( V_444 , V_516 , 1 ) ;
return 0 ;
V_523:
F_11 ( & F_258 ( V_298 ) -> V_51 ) ;
V_521 = F_384 ( V_298 , V_36 ) ;
if ( F_258 ( V_298 ) -> V_256 == V_256 ) {
F_386 ( V_298 , V_36 , 0 ) ;
} else {
T_2 V_524 = F_258 ( V_298 ) -> V_256 ;
T_2 V_212 ;
V_212 = V_256 - F_258 ( V_298 ) -> V_256 ;
F_258 ( V_298 ) -> V_256 = V_256 ;
V_520 = F_386 ( V_298 , V_212 , 0 ) ;
F_258 ( V_298 ) -> V_256 = V_256 - V_36 ;
V_212 = V_256 - V_524 ;
V_212 = F_386 ( V_298 , V_212 , 0 ) ;
F_258 ( V_298 ) -> V_256 = V_524 - V_36 ;
if ( V_212 > V_520 )
V_520 = V_212 - V_520 ;
else
V_520 = 0 ;
}
F_13 ( & F_258 ( V_298 ) -> V_51 ) ;
if ( V_521 )
V_520 += F_209 ( V_35 , V_521 ) ;
if ( V_520 ) {
F_366 ( V_35 , V_444 , V_520 ) ;
F_311 ( V_35 -> V_37 , L_14 ,
F_378 ( V_298 ) , V_520 , 0 ) ;
}
if ( V_519 )
F_47 ( & F_258 ( V_298 ) -> V_522 ) ;
return V_29 ;
}
void F_390 ( struct V_298 * V_298 , T_2 V_36 )
{
struct V_34 * V_35 = F_258 ( V_298 ) -> V_35 ;
T_2 V_520 = 0 ;
unsigned V_521 ;
V_36 = F_149 ( V_36 , V_35 -> V_56 ) ;
F_11 ( & F_258 ( V_298 ) -> V_51 ) ;
V_521 = F_384 ( V_298 , V_36 ) ;
if ( V_36 )
V_520 = F_386 ( V_298 , V_36 , 0 ) ;
F_13 ( & F_258 ( V_298 ) -> V_51 ) ;
if ( V_521 > 0 )
V_520 += F_209 ( V_35 , V_521 ) ;
if ( F_238 ( V_35 ) )
return;
F_311 ( V_35 -> V_37 , L_14 ,
F_378 ( V_298 ) , V_520 , 0 ) ;
F_366 ( V_35 , & V_35 -> V_37 -> V_450 ,
V_520 ) ;
}
int F_391 ( struct V_298 * V_298 , T_2 V_32 , T_2 V_48 )
{
int V_29 ;
V_29 = F_263 ( V_298 , V_32 , V_48 ) ;
if ( V_29 < 0 )
return V_29 ;
V_29 = F_387 ( V_298 , V_48 ) ;
if ( V_29 < 0 )
F_266 ( V_298 , V_32 , V_48 ) ;
return V_29 ;
}
void F_392 ( struct V_298 * V_298 , T_2 V_32 , T_2 V_48 )
{
F_390 ( V_298 , V_48 ) ;
F_266 ( V_298 , V_32 , V_48 ) ;
}
static int F_393 ( struct V_117 * V_118 ,
struct V_34 * V_35 , T_2 V_27 ,
T_2 V_36 , int V_401 )
{
struct V_1 * V_2 = NULL ;
struct V_12 * V_13 = V_35 -> V_37 ;
T_2 V_525 = V_36 ;
T_2 V_526 ;
T_2 V_527 ;
int V_342 ;
F_11 ( & V_13 -> V_528 ) ;
V_526 = F_394 ( V_13 -> V_261 ) ;
if ( V_401 )
V_526 += V_36 ;
else
V_526 -= V_36 ;
F_395 ( V_13 -> V_261 , V_526 ) ;
F_13 ( & V_13 -> V_528 ) ;
while ( V_525 ) {
V_2 = F_76 ( V_13 , V_27 ) ;
if ( ! V_2 )
return - V_161 ;
if ( V_2 -> V_7 & ( V_343 |
V_344 |
V_345 ) )
V_342 = 2 ;
else
V_342 = 1 ;
if ( ! V_401 && V_2 -> V_3 == V_103 )
F_59 ( V_2 , 1 ) ;
V_527 = V_27 - V_2 -> V_21 . V_22 ;
F_8 ( V_527 > V_2 -> V_21 . V_33 ) ;
F_11 ( & V_2 -> V_95 -> V_51 ) ;
F_11 ( & V_2 -> V_51 ) ;
if ( F_262 ( V_35 , V_312 ) &&
V_2 -> V_305 < V_321 )
V_2 -> V_305 = V_321 ;
V_526 = F_58 ( & V_2 -> V_96 ) ;
V_36 = F_339 ( V_525 , V_2 -> V_21 . V_33 - V_527 ) ;
if ( V_401 ) {
V_526 += V_36 ;
F_396 ( & V_2 -> V_96 , V_526 ) ;
V_2 -> V_10 -= V_36 ;
V_2 -> V_95 -> V_354 -= V_36 ;
V_2 -> V_95 -> V_94 += V_36 ;
V_2 -> V_95 -> V_347 += V_36 * V_342 ;
F_13 ( & V_2 -> V_51 ) ;
F_13 ( & V_2 -> V_95 -> V_51 ) ;
} else {
V_526 -= V_36 ;
F_396 ( & V_2 -> V_96 , V_526 ) ;
V_2 -> V_9 += V_36 ;
V_2 -> V_95 -> V_353 += V_36 ;
V_2 -> V_95 -> V_94 -= V_36 ;
V_2 -> V_95 -> V_347 -= V_36 * V_342 ;
F_13 ( & V_2 -> V_51 ) ;
F_13 ( & V_2 -> V_95 -> V_51 ) ;
F_397 ( V_13 -> V_62 ,
V_27 , V_27 + V_36 - 1 ,
V_98 | V_529 ) ;
}
F_11 ( & V_118 -> V_135 -> V_328 ) ;
if ( F_182 ( & V_2 -> V_330 ) ) {
F_72 ( & V_2 -> V_330 ,
& V_118 -> V_135 -> V_320 ) ;
V_118 -> V_135 -> V_264 ++ ;
F_4 ( V_2 ) ;
}
F_13 ( & V_118 -> V_135 -> V_328 ) ;
if ( ! V_401 && V_526 == 0 ) {
F_11 ( & V_13 -> V_530 ) ;
if ( F_182 ( & V_2 -> V_531 ) ) {
F_4 ( V_2 ) ;
F_72 ( & V_2 -> V_531 ,
& V_13 -> V_532 ) ;
}
F_13 ( & V_13 -> V_530 ) ;
}
F_6 ( V_2 ) ;
V_525 -= V_36 ;
V_27 += V_36 ;
}
return 0 ;
}
static T_2 V_26 ( struct V_34 * V_35 , T_2 V_533 )
{
struct V_1 * V_2 ;
T_2 V_27 ;
F_11 ( & V_35 -> V_37 -> V_18 ) ;
V_27 = V_35 -> V_37 -> V_26 ;
F_13 ( & V_35 -> V_37 -> V_18 ) ;
if ( V_27 < ( T_2 ) - 1 )
return V_27 ;
V_2 = F_75 ( V_35 -> V_37 , V_533 ) ;
if ( ! V_2 )
return 0 ;
V_27 = V_2 -> V_21 . V_22 ;
F_6 ( V_2 ) ;
return V_27 ;
}
static int F_398 ( struct V_34 * V_35 ,
struct V_1 * V_2 ,
T_2 V_27 , T_2 V_36 , int V_10 )
{
F_11 ( & V_2 -> V_95 -> V_51 ) ;
F_11 ( & V_2 -> V_51 ) ;
V_2 -> V_9 += V_36 ;
V_2 -> V_95 -> V_353 += V_36 ;
if ( V_10 ) {
V_2 -> V_10 -= V_36 ;
V_2 -> V_95 -> V_354 -= V_36 ;
}
F_13 ( & V_2 -> V_51 ) ;
F_13 ( & V_2 -> V_95 -> V_51 ) ;
F_397 ( V_35 -> V_37 -> V_62 , V_27 ,
V_27 + V_36 - 1 , V_98 | V_529 ) ;
if ( V_10 )
F_399 ( V_35 , V_27 , V_36 ) ;
return 0 ;
}
int F_175 ( struct V_34 * V_35 ,
T_2 V_27 , T_2 V_36 , int V_10 )
{
struct V_1 * V_2 ;
V_2 = F_76 ( V_35 -> V_37 , V_27 ) ;
F_32 ( ! V_2 ) ;
F_398 ( V_35 , V_2 , V_27 , V_36 , V_10 ) ;
F_6 ( V_2 ) ;
return 0 ;
}
int F_400 ( struct V_34 * V_35 ,
T_2 V_27 , T_2 V_36 )
{
struct V_1 * V_2 ;
int V_29 ;
V_2 = F_76 ( V_35 -> V_37 , V_27 ) ;
if ( ! V_2 )
return - V_534 ;
F_59 ( V_2 , 1 ) ;
F_398 ( V_35 , V_2 , V_27 , V_36 , 0 ) ;
V_29 = F_28 ( V_2 , V_27 , V_36 ) ;
F_6 ( V_2 ) ;
return V_29 ;
}
static int F_401 ( struct V_34 * V_35 , T_2 V_32 , T_2 V_36 )
{
int V_29 ;
struct V_1 * V_14 ;
struct V_49 * V_52 ;
V_14 = F_76 ( V_35 -> V_37 , V_32 ) ;
if ( ! V_14 )
return - V_534 ;
F_59 ( V_14 , 0 ) ;
V_52 = F_25 ( V_14 ) ;
if ( ! V_52 ) {
F_32 ( ! F_1 ( V_14 ) ) ;
V_29 = F_28 ( V_14 , V_32 , V_36 ) ;
} else {
F_49 ( & V_52 -> V_86 ) ;
if ( V_32 >= V_52 -> V_85 ) {
V_29 = F_17 ( V_35 , V_32 , V_36 ) ;
} else if ( V_32 + V_36 <= V_52 -> V_85 ) {
V_29 = F_28 ( V_14 ,
V_32 , V_36 ) ;
} else {
V_36 = V_52 -> V_85 - V_32 ;
V_29 = F_28 ( V_14 ,
V_32 , V_36 ) ;
if ( V_29 )
goto V_535;
V_36 = ( V_32 + V_36 ) -
V_52 -> V_85 ;
V_32 = V_52 -> V_85 ;
V_29 = F_17 ( V_35 , V_32 , V_36 ) ;
}
V_535:
F_47 ( & V_52 -> V_86 ) ;
F_26 ( V_52 ) ;
}
F_6 ( V_14 ) ;
return V_29 ;
}
int F_402 ( struct V_34 * log ,
struct V_67 * V_536 )
{
struct V_290 * V_96 ;
struct V_69 V_21 ;
int V_537 ;
int V_42 ;
if ( ! F_84 ( log -> V_37 , V_538 ) )
return 0 ;
for ( V_42 = 0 ; V_42 < F_39 ( V_536 ) ; V_42 ++ ) {
F_41 ( V_536 , & V_21 , V_42 ) ;
if ( V_21 . type != V_295 )
continue;
V_96 = F_86 ( V_536 , V_42 , struct V_290 ) ;
V_537 = F_242 ( V_536 , V_96 ) ;
if ( V_537 == V_296 )
continue;
if ( F_243 ( V_536 , V_96 ) == 0 )
continue;
V_21 . V_22 = F_243 ( V_536 , V_96 ) ;
V_21 . V_33 = F_244 ( V_536 , V_96 ) ;
F_401 ( log , V_21 . V_22 , V_21 . V_33 ) ;
}
return 0 ;
}
static void
F_403 ( struct V_1 * V_336 )
{
F_5 ( & V_336 -> V_539 ) ;
}
void F_404 ( struct V_12 * V_37 ,
const T_2 V_32 )
{
struct V_1 * V_336 ;
V_336 = F_76 ( V_37 , V_32 ) ;
ASSERT ( V_336 ) ;
if ( F_7 ( & V_336 -> V_539 ) )
F_282 ( & V_336 -> V_539 ) ;
F_6 ( V_336 ) ;
}
static int F_405 ( T_7 * V_338 )
{
F_68 () ;
return 0 ;
}
void F_406 ( struct V_1 * V_336 )
{
struct V_111 * V_95 = V_336 -> V_95 ;
ASSERT ( V_336 -> V_307 ) ;
if ( ! ( V_336 -> V_7 & V_339 ) )
return;
F_71 ( & V_95 -> V_352 ) ;
F_73 ( & V_95 -> V_352 ) ;
F_285 ( & V_336 -> V_539 ,
F_405 ,
V_102 ) ;
}
static int F_407 ( struct V_1 * V_2 ,
T_2 V_36 , int V_513 , int V_540 )
{
struct V_111 * V_95 = V_2 -> V_95 ;
int V_29 = 0 ;
F_11 ( & V_95 -> V_51 ) ;
F_11 ( & V_2 -> V_51 ) ;
if ( V_513 != V_541 ) {
if ( V_2 -> V_307 ) {
V_29 = - V_187 ;
} else {
V_2 -> V_10 += V_36 ;
V_95 -> V_354 += V_36 ;
if ( V_513 == V_542 ) {
F_311 ( V_2 -> V_37 ,
L_10 , V_95 -> V_7 ,
V_36 , 0 ) ;
V_95 -> V_356 -= V_36 ;
}
if ( V_540 )
V_2 -> V_445 += V_36 ;
}
} else {
if ( V_2 -> V_307 )
V_95 -> V_355 += V_36 ;
V_2 -> V_10 -= V_36 ;
V_95 -> V_354 -= V_36 ;
if ( V_540 )
V_2 -> V_445 -= V_36 ;
}
F_13 ( & V_2 -> V_51 ) ;
F_13 ( & V_95 -> V_51 ) ;
return V_29 ;
}
void F_408 ( struct V_117 * V_118 ,
struct V_34 * V_35 )
{
struct V_12 * V_37 = V_35 -> V_37 ;
struct V_49 * V_80 ;
struct V_49 * V_52 ;
struct V_1 * V_2 ;
F_71 ( & V_37 -> V_84 ) ;
F_269 (caching_ctl, next,
&fs_info->caching_block_groups, list) {
V_2 = V_52 -> V_14 ;
if ( F_1 ( V_2 ) ) {
V_2 -> V_106 = ( T_2 ) - 1 ;
F_274 ( & V_52 -> V_99 ) ;
F_26 ( V_52 ) ;
} else {
V_2 -> V_106 = V_52 -> V_85 ;
}
}
if ( V_37 -> V_62 == & V_37 -> V_38 [ 0 ] )
V_37 -> V_62 = & V_37 -> V_38 [ 1 ] ;
else
V_37 -> V_62 = & V_37 -> V_38 [ 0 ] ;
F_73 ( & V_37 -> V_84 ) ;
F_372 ( V_37 ) ;
}
static struct V_543 *
F_409 ( struct V_34 * V_35 , struct V_111 * V_95 ,
T_2 * V_544 )
{
struct V_543 * V_29 = NULL ;
bool V_545 = F_262 ( V_35 , V_546 ) ;
* V_544 = 0 ;
if ( F_330 ( V_95 ) )
return V_29 ;
if ( V_545 )
* V_544 = V_415 ;
if ( V_95 -> V_7 & V_54 ) {
V_29 = & V_35 -> V_37 -> V_547 ;
if ( ! V_545 )
* V_544 = V_548 ;
} else if ( ( V_95 -> V_7 & V_339 ) && V_545 ) {
V_29 = & V_35 -> V_37 -> V_549 ;
}
return V_29 ;
}
static int F_410 ( struct V_34 * V_35 , T_2 V_32 , T_2 V_31 ,
const bool V_550 )
{
struct V_12 * V_37 = V_35 -> V_37 ;
struct V_1 * V_2 = NULL ;
struct V_111 * V_95 ;
struct V_262 * V_263 = & V_37 -> V_266 ;
struct V_543 * V_551 = NULL ;
T_2 V_48 ;
T_2 V_552 = 0 ;
T_2 V_544 = 0 ;
bool V_335 ;
while ( V_32 <= V_31 ) {
V_335 = false ;
if ( ! V_2 ||
V_32 >= V_2 -> V_21 . V_22 + V_2 -> V_21 . V_33 ) {
if ( V_2 )
F_6 ( V_2 ) ;
V_552 = 0 ;
V_2 = F_76 ( V_37 , V_32 ) ;
F_32 ( ! V_2 ) ;
V_551 = F_409 ( V_35 ,
V_2 -> V_95 ,
& V_544 ) ;
V_544 <<= 1 ;
}
V_48 = V_2 -> V_21 . V_22 + V_2 -> V_21 . V_33 - V_32 ;
V_48 = F_339 ( V_48 , V_31 + 1 - V_32 ) ;
if ( V_32 < V_2 -> V_106 ) {
V_48 = F_339 ( V_48 , V_2 -> V_106 - V_32 ) ;
if ( V_550 )
F_31 ( V_2 , V_32 , V_48 ) ;
}
V_32 += V_48 ;
V_552 += V_48 ;
V_95 = V_2 -> V_95 ;
if ( V_551 && V_551 -> V_553 &&
V_552 > V_544 ) {
F_11 ( & V_551 -> V_51 ) ;
V_551 -> V_553 = 0 ;
F_13 ( & V_551 -> V_51 ) ;
}
F_11 ( & V_95 -> V_51 ) ;
F_11 ( & V_2 -> V_51 ) ;
V_2 -> V_9 -= V_48 ;
V_95 -> V_353 -= V_48 ;
V_95 -> V_357 = 0 ;
F_411 ( & V_95 -> V_348 , - V_48 ) ;
if ( V_2 -> V_307 ) {
V_95 -> V_355 += V_48 ;
V_335 = true ;
}
F_13 ( & V_2 -> V_51 ) ;
if ( ! V_335 && V_263 -> V_95 == V_95 ) {
F_11 ( & V_263 -> V_51 ) ;
if ( ! V_263 -> V_116 ) {
V_48 = F_339 ( V_48 , V_263 -> V_60 -
V_263 -> V_10 ) ;
V_263 -> V_10 += V_48 ;
V_95 -> V_356 += V_48 ;
if ( V_263 -> V_10 >= V_263 -> V_60 )
V_263 -> V_116 = 1 ;
}
F_13 ( & V_263 -> V_51 ) ;
}
F_13 ( & V_95 -> V_51 ) ;
}
if ( V_2 )
F_6 ( V_2 ) ;
return 0 ;
}
int F_412 ( struct V_117 * V_118 ,
struct V_34 * V_35 )
{
struct V_12 * V_37 = V_35 -> V_37 ;
struct V_1 * V_14 , * V_317 ;
struct V_112 * V_554 ;
struct V_555 * V_556 ;
T_2 V_32 ;
T_2 V_31 ;
int V_29 ;
if ( V_37 -> V_62 == & V_37 -> V_38 [ 0 ] )
V_556 = & V_37 -> V_38 [ 1 ] ;
else
V_556 = & V_37 -> V_38 [ 0 ] ;
while ( ! V_118 -> V_228 ) {
F_49 ( & V_37 -> V_557 ) ;
V_29 = F_30 ( V_556 , 0 , & V_32 , & V_31 ,
V_63 , NULL ) ;
if ( V_29 ) {
F_47 ( & V_37 -> V_557 ) ;
break;
}
if ( F_262 ( V_35 , V_558 ) )
V_29 = F_153 ( V_35 , V_32 ,
V_31 + 1 - V_32 , NULL ) ;
F_413 ( V_556 , V_32 , V_31 ) ;
F_410 ( V_35 , V_32 , V_31 , true ) ;
F_47 ( & V_37 -> V_557 ) ;
F_48 () ;
}
V_554 = & V_118 -> V_135 -> V_554 ;
F_269 (block_group, tmp, deleted_bgs, bg_list) {
T_2 V_559 = 0 ;
V_29 = - V_560 ;
if ( ! V_118 -> V_228 )
V_29 = F_153 ( V_35 ,
V_14 -> V_21 . V_22 ,
V_14 -> V_21 . V_33 ,
& V_559 ) ;
F_274 ( & V_14 -> V_531 ) ;
F_414 ( V_14 ) ;
F_6 ( V_14 ) ;
if ( V_29 ) {
const char * V_561 = F_415 ( V_29 ) ;
F_416 ( V_37 ,
L_15 ,
V_29 , V_561 ) ;
}
}
return 0 ;
}
static void F_417 ( struct V_12 * V_37 , T_2 V_36 ,
T_2 V_141 , T_2 V_153 )
{
struct V_111 * V_95 ;
T_2 V_7 ;
if ( V_141 < V_150 ) {
if ( V_153 == V_562 )
V_7 = V_340 ;
else
V_7 = V_54 ;
} else {
V_7 = V_339 ;
}
V_95 = F_77 ( V_37 , V_7 ) ;
F_32 ( ! V_95 ) ;
F_411 ( & V_95 -> V_348 , V_36 ) ;
}
static int F_167 ( struct V_117 * V_118 ,
struct V_34 * V_35 ,
struct V_219 * V_136 , T_2 V_17 ,
T_2 V_153 , T_2 V_563 ,
T_2 V_564 , int V_168 ,
struct V_189 * V_137 )
{
struct V_69 V_21 ;
struct V_65 * V_66 ;
struct V_12 * V_13 = V_35 -> V_37 ;
struct V_34 * V_64 = V_13 -> V_64 ;
struct V_67 * V_68 ;
struct V_124 * V_125 ;
struct V_172 * V_173 ;
int V_29 ;
int V_193 ;
int V_565 = 0 ;
int V_566 = 0 ;
int V_567 = 1 ;
T_3 V_126 ;
T_2 V_120 ;
T_2 V_27 = V_136 -> V_27 ;
T_2 V_36 = V_136 -> V_36 ;
int V_169 = 0 ;
bool V_182 = F_84 ( V_35 -> V_37 ,
V_129 ) ;
V_66 = F_34 () ;
if ( ! V_66 )
return - V_74 ;
V_66 -> V_77 = V_78 ;
V_66 -> V_220 = 1 ;
V_193 = V_563 >= V_150 ;
F_32 ( ! V_193 && V_168 != 1 ) ;
if ( V_193 )
V_182 = 0 ;
V_29 = F_142 ( V_118 , V_64 , V_66 , & V_173 ,
V_27 , V_36 , V_17 ,
V_153 , V_563 ,
V_564 ) ;
if ( V_29 == 0 ) {
V_565 = V_66 -> V_83 [ 0 ] ;
while ( V_565 >= 0 ) {
F_41 ( V_66 -> V_82 [ 0 ] , & V_21 ,
V_565 ) ;
if ( V_21 . V_22 != V_27 )
break;
if ( V_21 . type == V_79 &&
V_21 . V_33 == V_36 ) {
V_566 = 1 ;
break;
}
if ( V_21 . type == V_87 &&
V_21 . V_33 == V_563 ) {
V_566 = 1 ;
break;
}
if ( V_66 -> V_83 [ 0 ] - V_565 > 5 )
break;
V_565 -- ;
}
#ifdef F_89
V_126 = F_85 ( V_66 -> V_82 [ 0 ] , V_565 ) ;
if ( V_566 && V_126 < sizeof( * V_125 ) )
V_566 = 0 ;
#endif
if ( ! V_566 ) {
F_32 ( V_173 ) ;
V_29 = F_147 ( V_118 , V_64 , V_66 ,
NULL , V_168 ,
V_193 , & V_169 ) ;
if ( V_29 ) {
F_162 ( V_118 , V_64 , V_29 ) ;
goto V_81;
}
F_45 ( V_66 ) ;
V_66 -> V_220 = 1 ;
V_21 . V_22 = V_27 ;
V_21 . type = V_79 ;
V_21 . V_33 = V_36 ;
if ( ! V_193 && V_182 ) {
V_21 . type = V_87 ;
V_21 . V_33 = V_563 ;
}
V_29 = F_38 ( V_118 , V_64 ,
& V_21 , V_66 , - 1 , 1 ) ;
if ( V_29 > 0 && V_182 && V_66 -> V_83 [ 0 ] ) {
V_66 -> V_83 [ 0 ] -- ;
F_41 ( V_66 -> V_82 [ 0 ] , & V_21 ,
V_66 -> V_83 [ 0 ] ) ;
if ( V_21 . V_22 == V_27 &&
V_21 . type == V_79 &&
V_21 . V_33 == V_36 )
V_29 = 0 ;
}
if ( V_29 > 0 && V_182 ) {
V_182 = false ;
V_21 . V_22 = V_27 ;
V_21 . type = V_79 ;
V_21 . V_33 = V_36 ;
F_45 ( V_66 ) ;
V_29 = F_38 ( V_118 , V_64 ,
& V_21 , V_66 , - 1 , 1 ) ;
}
if ( V_29 ) {
F_418 ( V_13 , L_16 ,
V_29 , V_27 ) ;
if ( V_29 > 0 )
F_419 ( V_64 ,
V_66 -> V_82 [ 0 ] ) ;
}
if ( V_29 < 0 ) {
F_162 ( V_118 , V_64 , V_29 ) ;
goto V_81;
}
V_565 = V_66 -> V_83 [ 0 ] ;
}
} else if ( F_8 ( V_29 == - V_161 ) ) {
F_419 ( V_64 , V_66 -> V_82 [ 0 ] ) ;
F_418 ( V_13 ,
L_17 ,
V_27 , V_17 , V_153 , V_563 ,
V_564 ) ;
F_162 ( V_118 , V_64 , V_29 ) ;
goto V_81;
} else {
F_162 ( V_118 , V_64 , V_29 ) ;
goto V_81;
}
V_68 = V_66 -> V_82 [ 0 ] ;
V_126 = F_85 ( V_68 , V_565 ) ;
#ifdef F_89
if ( V_126 < sizeof( * V_125 ) ) {
F_32 ( V_566 || V_565 != V_66 -> V_83 [ 0 ] ) ;
V_29 = F_95 ( V_118 , V_64 , V_66 ,
V_563 , 0 ) ;
if ( V_29 < 0 ) {
F_162 ( V_118 , V_64 , V_29 ) ;
goto V_81;
}
F_45 ( V_66 ) ;
V_66 -> V_220 = 1 ;
V_21 . V_22 = V_27 ;
V_21 . type = V_79 ;
V_21 . V_33 = V_36 ;
V_29 = F_38 ( V_118 , V_64 , & V_21 , V_66 ,
- 1 , 1 ) ;
if ( V_29 ) {
F_418 ( V_13 , L_16 ,
V_29 , V_27 ) ;
F_419 ( V_64 , V_66 -> V_82 [ 0 ] ) ;
}
if ( V_29 < 0 ) {
F_162 ( V_118 , V_64 , V_29 ) ;
goto V_81;
}
V_565 = V_66 -> V_83 [ 0 ] ;
V_68 = V_66 -> V_82 [ 0 ] ;
V_126 = F_85 ( V_68 , V_565 ) ;
}
#endif
F_32 ( V_126 < sizeof( * V_125 ) ) ;
V_125 = F_86 ( V_68 , V_565 ,
struct V_124 ) ;
if ( V_563 < V_150 &&
V_21 . type == V_79 ) {
struct V_145 * V_146 ;
F_32 ( V_126 < sizeof( * V_125 ) + sizeof( * V_146 ) ) ;
V_146 = (struct V_145 * ) ( V_125 + 1 ) ;
F_8 ( V_563 != F_420 ( V_68 , V_146 ) ) ;
}
V_120 = F_87 ( V_68 , V_125 ) ;
if ( V_120 < V_168 ) {
F_418 ( V_13 , L_18
L_19 , V_168 , V_120 , V_27 ) ;
V_29 = - V_534 ;
F_162 ( V_118 , V_64 , V_29 ) ;
goto V_81;
}
V_120 -= V_168 ;
if ( V_120 > 0 ) {
if ( V_137 )
F_138 ( V_137 , V_68 , V_125 ) ;
if ( V_173 ) {
F_32 ( ! V_566 ) ;
} else {
F_98 ( V_68 , V_125 , V_120 ) ;
F_103 ( V_68 ) ;
}
if ( V_566 ) {
V_29 = F_147 ( V_118 , V_64 , V_66 ,
V_173 , V_168 ,
V_193 , & V_169 ) ;
if ( V_29 ) {
F_162 ( V_118 , V_64 , V_29 ) ;
goto V_81;
}
}
F_417 ( V_35 -> V_37 , - V_36 , V_563 ,
V_153 ) ;
} else {
if ( V_566 ) {
F_32 ( V_193 && V_168 !=
F_126 ( V_66 , V_173 ) ) ;
if ( V_173 ) {
F_32 ( V_66 -> V_83 [ 0 ] != V_565 ) ;
} else {
F_32 ( V_66 -> V_83 [ 0 ] != V_565 + 1 ) ;
V_66 -> V_83 [ 0 ] = V_565 ;
V_567 = 2 ;
}
}
V_169 = 1 ;
V_29 = F_421 ( V_118 , V_64 , V_66 , V_66 -> V_83 [ 0 ] ,
V_567 ) ;
if ( V_29 ) {
F_162 ( V_118 , V_64 , V_29 ) ;
goto V_81;
}
F_45 ( V_66 ) ;
if ( V_193 ) {
V_29 = F_179 ( V_118 , V_35 , V_27 , V_36 ) ;
if ( V_29 ) {
F_162 ( V_118 , V_64 , V_29 ) ;
goto V_81;
}
}
V_29 = F_422 ( V_118 , V_35 -> V_37 , V_27 ,
V_36 ) ;
if ( V_29 ) {
F_162 ( V_118 , V_64 , V_29 ) ;
goto V_81;
}
V_29 = F_393 ( V_118 , V_35 , V_27 , V_36 , 0 ) ;
if ( V_29 ) {
F_162 ( V_118 , V_64 , V_29 ) ;
goto V_81;
}
}
F_45 ( V_66 ) ;
V_81:
F_53 ( V_66 ) ;
return V_29 ;
}
static T_1 int F_423 ( struct V_117 * V_118 ,
struct V_34 * V_35 , T_2 V_27 )
{
struct V_121 * V_113 ;
struct V_122 * V_123 ;
int V_29 = 0 ;
V_123 = & V_118 -> V_135 -> V_123 ;
F_11 ( & V_123 -> V_51 ) ;
V_113 = F_92 ( V_118 , V_27 ) ;
if ( ! V_113 )
goto V_568;
F_11 ( & V_113 -> V_51 ) ;
if ( ! F_182 ( & V_113 -> V_232 ) )
goto V_81;
if ( V_113 -> V_137 ) {
if ( ! V_113 -> V_235 )
goto V_81;
F_192 ( V_113 -> V_137 ) ;
V_113 -> V_137 = NULL ;
}
if ( ! F_93 ( & V_113 -> V_86 ) )
goto V_81;
V_113 -> V_136 . V_239 = 0 ;
F_194 ( & V_113 -> V_241 , & V_123 -> V_242 ) ;
F_196 ( & V_123 -> V_243 ) ;
V_123 -> V_240 -- ;
if ( V_113 -> V_237 == 0 )
V_123 -> V_238 -- ;
V_113 -> V_237 = 0 ;
F_13 ( & V_113 -> V_51 ) ;
F_13 ( & V_123 -> V_51 ) ;
F_32 ( V_113 -> V_137 ) ;
if ( V_113 -> V_235 )
V_29 = 1 ;
F_47 ( & V_113 -> V_86 ) ;
F_94 ( & V_113 -> V_136 ) ;
return V_29 ;
V_81:
F_13 ( & V_113 -> V_51 ) ;
V_568:
F_13 ( & V_123 -> V_51 ) ;
return 0 ;
}
void F_424 ( struct V_117 * V_118 ,
struct V_34 * V_35 ,
struct V_67 * V_287 ,
T_2 V_17 , int V_169 )
{
int V_569 = 1 ;
int V_29 ;
if ( V_35 -> V_283 . V_22 != V_217 ) {
V_29 = F_159 ( V_35 -> V_37 , V_118 ,
V_287 -> V_32 , V_287 -> V_48 ,
V_17 , V_35 -> V_283 . V_22 ,
F_240 ( V_287 ) ,
V_226 , NULL ) ;
F_32 ( V_29 ) ;
}
if ( ! V_169 )
return;
if ( F_425 ( V_287 ) == V_118 -> V_274 ) {
struct V_1 * V_2 ;
if ( V_35 -> V_283 . V_22 != V_217 ) {
V_29 = F_423 ( V_118 , V_35 , V_287 -> V_32 ) ;
if ( ! V_29 )
goto V_81;
}
V_2 = F_76 ( V_35 -> V_37 , V_287 -> V_32 ) ;
if ( F_426 ( V_287 , V_570 ) ) {
F_398 ( V_35 , V_2 , V_287 -> V_32 , V_287 -> V_48 , 1 ) ;
F_6 ( V_2 ) ;
goto V_81;
}
F_8 ( F_241 ( V_571 , & V_287 -> V_572 ) ) ;
F_31 ( V_2 , V_287 -> V_32 , V_287 -> V_48 ) ;
F_407 ( V_2 , V_287 -> V_48 , V_541 , 0 ) ;
F_6 ( V_2 ) ;
F_399 ( V_35 , V_287 -> V_32 , V_287 -> V_48 ) ;
V_569 = 0 ;
}
V_81:
if ( V_569 )
F_417 ( V_35 -> V_37 , V_287 -> V_48 ,
F_240 ( V_287 ) ,
V_35 -> V_283 . V_22 ) ;
F_427 ( V_573 , & V_287 -> V_572 ) ;
}
int V_294 ( struct V_117 * V_118 , struct V_34 * V_35 ,
T_2 V_27 , T_2 V_36 , T_2 V_17 , T_2 V_153 ,
T_2 V_141 , T_2 V_33 )
{
int V_29 ;
struct V_12 * V_37 = V_35 -> V_37 ;
if ( F_238 ( V_35 ) )
return 0 ;
F_417 ( V_35 -> V_37 , V_36 , V_141 , V_153 ) ;
if ( V_153 == V_217 ) {
F_8 ( V_141 >= V_150 ) ;
F_175 ( V_35 , V_27 , V_36 , 1 ) ;
V_29 = 0 ;
} else if ( V_141 < V_150 ) {
V_29 = F_159 ( V_37 , V_118 , V_27 ,
V_36 ,
V_17 , V_153 , ( int ) V_141 ,
V_226 , NULL ) ;
} else {
V_29 = F_160 ( V_37 , V_118 , V_27 ,
V_36 ,
V_17 , V_153 , V_141 ,
V_33 , 0 ,
V_226 , NULL ) ;
}
return V_29 ;
}
static T_1 void
F_428 ( struct V_1 * V_2 ,
T_2 V_36 )
{
struct V_49 * V_52 ;
V_52 = F_25 ( V_2 ) ;
if ( ! V_52 )
return;
F_278 ( V_52 -> V_90 , F_1 ( V_2 ) ||
( V_2 -> V_11 -> V_574 >= V_36 ) ) ;
F_26 ( V_52 ) ;
}
static T_1 int
F_429 ( struct V_1 * V_2 )
{
struct V_49 * V_52 ;
int V_29 = 0 ;
V_52 = F_25 ( V_2 ) ;
if ( ! V_52 )
return ( V_2 -> V_3 == V_5 ) ? - V_184 : 0 ;
F_278 ( V_52 -> V_90 , F_1 ( V_2 ) ) ;
if ( V_2 -> V_3 == V_5 )
V_29 = - V_184 ;
F_26 ( V_52 ) ;
return V_29 ;
}
int F_430 ( T_2 V_7 )
{
if ( V_7 & V_345 )
return V_575 ;
else if ( V_7 & V_344 )
return V_576 ;
else if ( V_7 & V_343 )
return V_577 ;
else if ( V_7 & V_392 )
return V_578 ;
else if ( V_7 & V_391 )
return V_579 ;
else if ( V_7 & V_390 )
return V_580 ;
return V_581 ;
}
int F_431 ( struct V_1 * V_2 )
{
return F_430 ( V_2 -> V_7 ) ;
}
static const char * F_432 ( enum V_582 type )
{
if ( type >= V_350 )
return NULL ;
return V_583 [ type ] ;
}
static inline void
F_433 ( struct V_1 * V_2 ,
int V_540 )
{
if ( V_540 )
F_50 ( & V_2 -> V_584 ) ;
}
static inline void
F_434 ( struct V_1 * V_2 ,
int V_540 )
{
F_4 ( V_2 ) ;
if ( V_540 )
F_50 ( & V_2 -> V_584 ) ;
}
static struct V_1 *
F_435 ( struct V_1 * V_14 ,
struct V_543 * V_551 ,
int V_540 )
{
struct V_1 * V_585 = NULL ;
F_11 ( & V_551 -> V_586 ) ;
while ( 1 ) {
V_585 = V_551 -> V_14 ;
if ( ! V_585 )
return NULL ;
if ( V_585 == V_14 )
return V_585 ;
F_4 ( V_585 ) ;
if ( ! V_540 )
return V_585 ;
if ( F_334 ( & V_585 -> V_584 ) )
return V_585 ;
F_13 ( & V_551 -> V_586 ) ;
F_50 ( & V_585 -> V_584 ) ;
F_11 ( & V_551 -> V_586 ) ;
if ( V_585 == V_551 -> V_14 )
return V_585 ;
F_46 ( & V_585 -> V_584 ) ;
F_6 ( V_585 ) ;
}
}
static inline void
F_436 ( struct V_1 * V_2 ,
int V_540 )
{
if ( V_540 )
F_46 ( & V_2 -> V_584 ) ;
F_6 ( V_2 ) ;
}
static T_1 int F_437 ( struct V_34 * V_587 ,
T_2 V_36 , T_2 V_588 ,
T_2 V_589 , struct V_69 * V_223 ,
T_2 V_7 , int V_540 )
{
int V_29 = 0 ;
struct V_34 * V_35 = V_587 -> V_37 -> V_64 ;
struct V_543 * V_590 = NULL ;
struct V_1 * V_14 = NULL ;
T_2 V_533 = 0 ;
T_2 V_357 = 0 ;
T_2 V_544 = 0 ;
struct V_111 * V_95 ;
int V_591 = 0 ;
int V_592 = F_430 ( V_7 ) ;
int V_593 = ( V_7 & V_339 ) ?
V_594 : V_542 ;
bool V_595 = false ;
bool V_596 = false ;
bool V_597 = true ;
bool V_598 = false ;
bool V_599 = false ;
bool V_600 = false ;
F_8 ( V_36 < V_35 -> V_56 ) ;
V_223 -> type = V_79 ;
V_223 -> V_22 = 0 ;
V_223 -> V_33 = 0 ;
F_438 ( V_587 , V_36 , V_588 , V_7 ) ;
V_95 = F_77 ( V_35 -> V_37 , V_7 ) ;
if ( ! V_95 ) {
F_418 ( V_35 -> V_37 , L_20 , V_7 ) ;
return - V_314 ;
}
if ( F_355 ( V_95 -> V_357 ) ) {
F_11 ( & V_95 -> V_51 ) ;
if ( V_95 -> V_357 &&
V_36 > V_95 -> V_357 ) {
V_223 -> V_33 = V_95 -> V_357 ;
F_13 ( & V_95 -> V_51 ) ;
return - V_314 ;
} else if ( V_95 -> V_357 ) {
V_597 = false ;
}
F_13 ( & V_95 -> V_51 ) ;
}
V_590 = F_409 ( V_587 , V_95 , & V_544 ) ;
if ( V_590 ) {
F_11 ( & V_590 -> V_51 ) ;
if ( V_590 -> V_14 )
V_589 = V_590 -> V_601 ;
if ( V_590 -> V_553 ) {
V_589 = V_590 -> V_601 ;
V_597 = false ;
}
F_13 ( & V_590 -> V_51 ) ;
}
V_533 = F_439 ( V_533 , V_26 ( V_35 , 0 ) ) ;
V_533 = F_439 ( V_533 , V_589 ) ;
if ( V_533 == V_589 ) {
V_14 = F_76 ( V_35 -> V_37 ,
V_533 ) ;
if ( V_14 && F_3 ( V_14 , V_7 ) &&
V_14 -> V_3 != V_103 ) {
F_50 ( & V_95 -> V_352 ) ;
if ( F_182 ( & V_14 -> V_99 ) ||
V_14 -> V_307 ) {
F_6 ( V_14 ) ;
F_46 ( & V_95 -> V_352 ) ;
} else {
V_592 = F_431 ( V_14 ) ;
F_433 ( V_14 , V_540 ) ;
goto V_602;
}
} else if ( V_14 ) {
F_6 ( V_14 ) ;
}
}
V_603:
V_598 = false ;
if ( V_592 == 0 || V_592 == F_430 ( V_7 ) )
V_600 = true ;
F_50 ( & V_95 -> V_352 ) ;
F_183 (block_group, &space_info->block_groups[index],
list) {
T_2 V_33 ;
int V_3 ;
F_434 ( V_14 , V_540 ) ;
V_533 = V_14 -> V_21 . V_22 ;
if ( ! F_3 ( V_14 , V_7 ) ) {
T_2 V_604 = V_343 |
V_344 |
V_391 |
V_390 |
V_345 ;
if ( ( V_7 & V_604 ) && ! ( V_14 -> V_7 & V_604 ) )
goto V_591;
}
V_602:
V_3 = F_1 ( V_14 ) ;
if ( F_355 ( ! V_3 ) ) {
V_598 = true ;
V_29 = F_59 ( V_14 , 0 ) ;
F_32 ( V_29 < 0 ) ;
V_29 = 0 ;
}
if ( F_355 ( V_14 -> V_3 == V_5 ) )
goto V_591;
if ( F_355 ( V_14 -> V_307 ) )
goto V_591;
if ( V_590 && V_597 ) {
struct V_1 * V_605 ;
unsigned long V_606 ;
V_605 = F_435 ( V_14 ,
V_590 ,
V_540 ) ;
if ( ! V_605 )
goto V_607;
if ( V_605 != V_14 &&
( V_605 -> V_307 ||
! F_3 ( V_605 , V_7 ) ) )
goto V_608;
V_33 = F_440 ( V_605 ,
V_590 ,
V_36 ,
V_605 -> V_21 . V_22 ,
& V_357 ) ;
if ( V_33 ) {
F_13 ( & V_590 -> V_586 ) ;
F_441 ( V_35 ,
V_605 ,
V_533 , V_36 ) ;
if ( V_605 != V_14 ) {
F_436 ( V_14 ,
V_540 ) ;
V_14 = V_605 ;
}
goto V_609;
}
F_8 ( V_590 -> V_14 != V_605 ) ;
V_608:
if ( V_591 >= V_610 &&
V_605 != V_14 ) {
F_13 ( & V_590 -> V_586 ) ;
F_436 ( V_605 ,
V_540 ) ;
goto V_611;
}
F_442 ( NULL , V_590 ) ;
if ( V_605 != V_14 )
F_436 ( V_605 ,
V_540 ) ;
V_607:
if ( V_591 >= V_610 ) {
F_13 ( & V_590 -> V_586 ) ;
goto V_611;
}
V_606 = F_35 (unsigned long,
empty_cluster + empty_size,
block_group->full_stripe_len) ;
V_29 = F_443 ( V_35 , V_14 ,
V_590 , V_533 ,
V_36 ,
V_606 ) ;
if ( V_29 == 0 ) {
V_33 = F_440 ( V_14 ,
V_590 ,
V_36 ,
V_533 ,
& V_357 ) ;
if ( V_33 ) {
F_13 ( & V_590 -> V_586 ) ;
F_441 ( V_35 ,
V_14 , V_533 ,
V_36 ) ;
goto V_609;
}
} else if ( ! V_3 && V_591 > V_612
&& ! V_595 ) {
F_13 ( & V_590 -> V_586 ) ;
V_595 = true ;
F_428 ( V_14 ,
V_36 + V_544 + V_588 ) ;
goto V_602;
}
F_442 ( NULL , V_590 ) ;
F_13 ( & V_590 -> V_586 ) ;
goto V_591;
}
V_611:
if ( F_355 ( V_590 ) ) {
F_11 ( & V_590 -> V_51 ) ;
V_590 -> V_553 = 1 ;
F_13 ( & V_590 -> V_51 ) ;
}
F_11 ( & V_14 -> V_11 -> V_613 ) ;
if ( V_3 &&
V_14 -> V_11 -> V_574 <
V_36 + V_544 + V_588 ) {
if ( V_14 -> V_11 -> V_574 >
V_357 )
V_357 =
V_14 -> V_11 -> V_574 ;
F_13 ( & V_14 -> V_11 -> V_613 ) ;
goto V_591;
}
F_13 ( & V_14 -> V_11 -> V_613 ) ;
V_33 = F_444 ( V_14 , V_533 ,
V_36 , V_588 ,
& V_357 ) ;
if ( ! V_33 && ! V_596 && ! V_3 &&
V_591 > V_612 ) {
F_428 ( V_14 ,
V_36 + V_588 ) ;
V_596 = true ;
goto V_602;
} else if ( ! V_33 ) {
goto V_591;
}
V_609:
V_533 = F_149 ( V_33 , V_35 -> V_614 ) ;
if ( V_533 + V_36 >
V_14 -> V_21 . V_22 + V_14 -> V_21 . V_33 ) {
F_31 ( V_14 , V_33 , V_36 ) ;
goto V_591;
}
if ( V_33 < V_533 )
F_31 ( V_14 , V_33 ,
V_533 - V_33 ) ;
F_32 ( V_33 > V_533 ) ;
V_29 = F_407 ( V_14 , V_36 ,
V_593 , V_540 ) ;
if ( V_29 == - V_187 ) {
F_31 ( V_14 , V_33 , V_36 ) ;
goto V_591;
}
F_403 ( V_14 ) ;
V_223 -> V_22 = V_533 ;
V_223 -> V_33 = V_36 ;
F_445 ( V_587 , V_14 ,
V_533 , V_36 ) ;
F_436 ( V_14 , V_540 ) ;
break;
V_591:
V_595 = false ;
V_596 = false ;
F_32 ( V_592 != F_431 ( V_14 ) ) ;
F_436 ( V_14 , V_540 ) ;
}
F_46 ( & V_95 -> V_352 ) ;
if ( ( V_591 == V_612 ) && V_598
&& ! V_599 )
V_599 = true ;
if ( ! V_223 -> V_22 && V_591 >= V_615 && V_598 )
goto V_603;
if ( ! V_223 -> V_22 && ++ V_592 < V_350 )
goto V_603;
if ( ! V_223 -> V_22 && V_591 < V_610 ) {
V_592 = 0 ;
if ( V_591 == V_612 ) {
if ( V_599 || ! V_600 )
V_591 = V_615 ;
else
V_591 = V_616 ;
} else {
V_591 ++ ;
}
if ( V_591 == V_616 ) {
struct V_117 * V_118 ;
int V_617 = 0 ;
V_118 = V_399 -> V_400 ;
if ( V_118 )
V_617 = 1 ;
else
V_118 = F_214 ( V_35 ) ;
if ( F_215 ( V_118 ) ) {
V_29 = F_216 ( V_118 ) ;
goto V_81;
}
V_29 = F_306 ( V_118 , V_35 , V_7 ,
V_403 ) ;
if ( V_29 == - V_314 )
V_591 = V_610 ;
if ( V_29 < 0 && V_29 != - V_314 )
F_162 ( V_118 ,
V_35 , V_29 ) ;
else
V_29 = 0 ;
if ( ! V_617 )
F_218 ( V_118 , V_35 ) ;
if ( V_29 )
goto V_81;
}
if ( V_591 == V_610 ) {
if ( V_588 == 0 &&
V_544 == 0 ) {
V_29 = - V_314 ;
goto V_81;
}
V_588 = 0 ;
V_544 = 0 ;
}
goto V_603;
} else if ( ! V_223 -> V_22 ) {
V_29 = - V_314 ;
} else if ( V_223 -> V_22 ) {
if ( ! V_597 && V_590 ) {
F_11 ( & V_590 -> V_51 ) ;
V_590 -> V_601 = V_223 -> V_22 ;
F_13 ( & V_590 -> V_51 ) ;
}
V_29 = 0 ;
}
V_81:
if ( V_29 == - V_314 ) {
F_11 ( & V_95 -> V_51 ) ;
V_95 -> V_357 = V_357 ;
F_13 ( & V_95 -> V_51 ) ;
V_223 -> V_33 = V_357 ;
}
return V_29 ;
}
static void F_327 ( struct V_111 * V_13 , T_2 V_212 ,
int V_618 )
{
struct V_1 * V_2 ;
int V_592 = 0 ;
F_11 ( & V_13 -> V_51 ) ;
F_446 ( V_619 L_21 ,
V_13 -> V_7 ,
V_13 -> V_341 - V_13 -> V_94 - V_13 -> V_353 -
V_13 -> V_354 - V_13 -> V_355 ,
( V_13 -> V_116 ) ? L_22 : L_23 ) ;
F_446 ( V_619 L_24
L_25 ,
V_13 -> V_341 , V_13 -> V_94 , V_13 -> V_353 ,
V_13 -> V_354 , V_13 -> V_356 ,
V_13 -> V_355 ) ;
F_13 ( & V_13 -> V_51 ) ;
if ( ! V_618 )
return;
F_50 ( & V_13 -> V_352 ) ;
V_164:
F_183 (cache, &info->block_groups[index], list) {
F_11 ( & V_2 -> V_51 ) ;
F_446 ( V_619 L_26
L_27
L_28 ,
V_2 -> V_21 . V_22 , V_2 -> V_21 . V_33 ,
F_58 ( & V_2 -> V_96 ) , V_2 -> V_9 ,
V_2 -> V_10 , V_2 -> V_307 ? L_29 : L_22 ) ;
F_447 ( V_2 , V_212 ) ;
F_13 ( & V_2 -> V_51 ) ;
}
if ( ++ V_592 < V_350 )
goto V_164;
F_46 ( & V_13 -> V_352 ) ;
}
int F_448 ( struct V_34 * V_35 ,
T_2 V_36 , T_2 V_620 ,
T_2 V_588 , T_2 V_589 ,
struct V_69 * V_223 , int V_193 , int V_540 )
{
bool V_621 = V_36 == V_620 ;
T_2 V_7 ;
int V_29 ;
V_7 = F_303 ( V_35 , V_193 ) ;
V_164:
F_8 ( V_36 < V_35 -> V_56 ) ;
V_29 = F_437 ( V_35 , V_36 , V_588 , V_589 , V_223 ,
V_7 , V_540 ) ;
if ( ! V_29 && ! V_193 ) {
F_404 ( V_35 -> V_37 ,
V_223 -> V_22 ) ;
} else if ( V_29 == - V_314 ) {
if ( ! V_621 && V_223 -> V_33 ) {
V_36 = F_339 ( V_36 >> 1 , V_223 -> V_33 ) ;
V_36 = F_150 ( V_36 , V_35 -> V_56 ) ;
V_36 = F_439 ( V_36 , V_620 ) ;
if ( V_36 == V_620 )
V_621 = true ;
goto V_164;
} else if ( F_262 ( V_35 , V_420 ) ) {
struct V_111 * V_409 ;
V_409 = F_77 ( V_35 -> V_37 , V_7 ) ;
F_418 ( V_35 -> V_37 , L_30 ,
V_7 , V_36 ) ;
if ( V_409 )
F_327 ( V_409 , V_36 , 1 ) ;
}
}
return V_29 ;
}
static int F_449 ( struct V_34 * V_35 ,
T_2 V_32 , T_2 V_48 ,
int V_569 , int V_540 )
{
struct V_1 * V_2 ;
int V_29 = 0 ;
V_2 = F_76 ( V_35 -> V_37 , V_32 ) ;
if ( ! V_2 ) {
F_418 ( V_35 -> V_37 , L_31 ,
V_32 ) ;
return - V_314 ;
}
if ( V_569 )
F_398 ( V_35 , V_2 , V_32 , V_48 , 1 ) ;
else {
if ( F_262 ( V_35 , V_558 ) )
V_29 = F_153 ( V_35 , V_32 , V_48 , NULL ) ;
F_31 ( V_2 , V_32 , V_48 ) ;
F_407 ( V_2 , V_48 , V_541 , V_540 ) ;
}
F_6 ( V_2 ) ;
F_399 ( V_35 , V_32 , V_48 ) ;
return V_29 ;
}
int F_450 ( struct V_34 * V_35 ,
T_2 V_32 , T_2 V_48 , int V_540 )
{
return F_449 ( V_35 , V_32 , V_48 , 0 , V_540 ) ;
}
int F_451 ( struct V_34 * V_35 ,
T_2 V_32 , T_2 V_48 )
{
return F_449 ( V_35 , V_32 , V_48 , 1 , 0 ) ;
}
static int F_166 ( struct V_117 * V_118 ,
struct V_34 * V_35 ,
T_2 V_17 , T_2 V_153 ,
T_2 V_7 , T_2 V_141 , T_2 V_33 ,
struct V_69 * V_223 , int V_140 )
{
int V_29 ;
struct V_12 * V_37 = V_35 -> V_37 ;
struct V_124 * V_622 ;
struct V_172 * V_173 ;
struct V_65 * V_66 ;
struct V_67 * V_68 ;
int type ;
T_3 V_60 ;
if ( V_17 > 0 )
type = V_162 ;
else
type = V_163 ;
V_60 = sizeof( * V_622 ) + F_133 ( type ) ;
V_66 = F_34 () ;
if ( ! V_66 )
return - V_74 ;
V_66 -> V_220 = 1 ;
V_29 = F_114 ( V_118 , V_37 -> V_64 , V_66 ,
V_223 , V_60 ) ;
if ( V_29 ) {
F_53 ( V_66 ) ;
return V_29 ;
}
V_68 = V_66 -> V_82 [ 0 ] ;
V_622 = F_86 ( V_68 , V_66 -> V_83 [ 0 ] ,
struct V_124 ) ;
F_98 ( V_68 , V_622 , V_140 ) ;
F_99 ( V_68 , V_622 , V_118 -> V_274 ) ;
F_100 ( V_68 , V_622 ,
V_7 | V_152 ) ;
V_173 = (struct V_172 * ) ( V_622 + 1 ) ;
F_140 ( V_68 , V_173 , type ) ;
if ( V_17 > 0 ) {
struct V_167 * V_158 ;
V_158 = (struct V_167 * ) ( V_173 + 1 ) ;
F_141 ( V_68 , V_173 , V_17 ) ;
F_115 ( V_68 , V_158 , V_140 ) ;
} else {
struct V_157 * V_158 ;
V_158 = (struct V_157 * ) ( & V_173 -> V_33 ) ;
F_117 ( V_68 , V_158 , V_153 ) ;
F_118 ( V_68 , V_158 , V_141 ) ;
F_119 ( V_68 , V_158 , V_33 ) ;
F_120 ( V_68 , V_158 , V_140 ) ;
}
F_103 ( V_66 -> V_82 [ 0 ] ) ;
F_53 ( V_66 ) ;
V_29 = F_452 ( V_118 , V_37 , V_223 -> V_22 ,
V_223 -> V_33 ) ;
if ( V_29 )
return V_29 ;
V_29 = F_393 ( V_118 , V_35 , V_223 -> V_22 , V_223 -> V_33 , 1 ) ;
if ( V_29 ) {
F_418 ( V_37 , L_32 ,
V_223 -> V_22 , V_223 -> V_33 ) ;
F_91 () ;
}
F_453 ( V_35 , V_223 -> V_22 , V_223 -> V_33 ) ;
return V_29 ;
}
static int F_173 ( struct V_117 * V_118 ,
struct V_34 * V_35 ,
T_2 V_17 , T_2 V_153 ,
T_2 V_7 , struct V_623 * V_21 ,
int V_176 , struct V_69 * V_223 )
{
int V_29 ;
struct V_12 * V_37 = V_35 -> V_37 ;
struct V_124 * V_622 ;
struct V_145 * V_624 ;
struct V_172 * V_173 ;
struct V_65 * V_66 ;
struct V_67 * V_68 ;
T_3 V_60 = sizeof( * V_622 ) + sizeof( * V_173 ) ;
T_2 V_36 = V_223 -> V_33 ;
bool V_182 = F_84 ( V_35 -> V_37 ,
V_129 ) ;
if ( ! V_182 )
V_60 += sizeof( * V_624 ) ;
V_66 = F_34 () ;
if ( ! V_66 ) {
F_451 ( V_35 , V_223 -> V_22 ,
V_35 -> V_55 ) ;
return - V_74 ;
}
V_66 -> V_220 = 1 ;
V_29 = F_114 ( V_118 , V_37 -> V_64 , V_66 ,
V_223 , V_60 ) ;
if ( V_29 ) {
F_53 ( V_66 ) ;
F_451 ( V_35 , V_223 -> V_22 ,
V_35 -> V_55 ) ;
return V_29 ;
}
V_68 = V_66 -> V_82 [ 0 ] ;
V_622 = F_86 ( V_68 , V_66 -> V_83 [ 0 ] ,
struct V_124 ) ;
F_98 ( V_68 , V_622 , 1 ) ;
F_99 ( V_68 , V_622 , V_118 -> V_274 ) ;
F_100 ( V_68 , V_622 ,
V_7 | V_151 ) ;
if ( V_182 ) {
V_173 = (struct V_172 * ) ( V_622 + 1 ) ;
V_36 = V_35 -> V_55 ;
} else {
V_624 = (struct V_145 * ) ( V_622 + 1 ) ;
F_168 ( V_68 , V_624 , V_21 ) ;
F_102 ( V_68 , V_624 , V_176 ) ;
V_173 = (struct V_172 * ) ( V_624 + 1 ) ;
}
if ( V_17 > 0 ) {
F_32 ( ! ( V_7 & V_134 ) ) ;
F_140 ( V_68 , V_173 ,
V_174 ) ;
F_141 ( V_68 , V_173 , V_17 ) ;
} else {
F_140 ( V_68 , V_173 ,
V_175 ) ;
F_141 ( V_68 , V_173 , V_153 ) ;
}
F_103 ( V_68 ) ;
F_53 ( V_66 ) ;
V_29 = F_452 ( V_118 , V_37 , V_223 -> V_22 ,
V_36 ) ;
if ( V_29 )
return V_29 ;
V_29 = F_393 ( V_118 , V_35 , V_223 -> V_22 , V_35 -> V_55 ,
1 ) ;
if ( V_29 ) {
F_418 ( V_37 , L_32 ,
V_223 -> V_22 , V_223 -> V_33 ) ;
F_91 () ;
}
F_453 ( V_35 , V_223 -> V_22 , V_35 -> V_55 ) ;
return V_29 ;
}
int F_454 ( struct V_117 * V_118 ,
struct V_34 * V_35 ,
T_2 V_153 , T_2 V_141 ,
T_2 V_33 , T_2 V_625 ,
struct V_69 * V_223 )
{
int V_29 ;
F_32 ( V_153 == V_217 ) ;
V_29 = F_160 ( V_35 -> V_37 , V_118 , V_223 -> V_22 ,
V_223 -> V_33 , 0 ,
V_153 , V_141 , V_33 ,
V_625 , V_244 ,
NULL ) ;
return V_29 ;
}
int F_455 ( struct V_117 * V_118 ,
struct V_34 * V_35 ,
T_2 V_153 , T_2 V_141 , T_2 V_33 ,
struct V_69 * V_223 )
{
int V_29 ;
struct V_1 * V_14 ;
if ( ! F_84 ( V_35 -> V_37 , V_538 ) ) {
V_29 = F_401 ( V_35 , V_223 -> V_22 , V_223 -> V_33 ) ;
if ( V_29 )
return V_29 ;
}
V_14 = F_76 ( V_35 -> V_37 , V_223 -> V_22 ) ;
if ( ! V_14 )
return - V_534 ;
V_29 = F_407 ( V_14 , V_223 -> V_33 ,
V_594 , 0 ) ;
F_32 ( V_29 ) ;
V_29 = F_166 ( V_118 , V_35 , 0 , V_153 ,
0 , V_141 , V_33 , V_223 , 1 ) ;
F_6 ( V_14 ) ;
return V_29 ;
}
static struct V_67 *
F_456 ( struct V_117 * V_118 , struct V_34 * V_35 ,
T_2 V_27 , int V_176 )
{
struct V_67 * V_287 ;
V_287 = F_457 ( V_35 , V_27 ) ;
if ( F_215 ( V_287 ) )
return V_287 ;
F_458 ( V_287 , V_118 -> V_274 ) ;
F_459 ( V_35 -> V_283 . V_22 , V_287 , V_176 ) ;
F_460 ( V_287 ) ;
F_461 ( V_118 , V_35 -> V_37 , V_287 ) ;
F_427 ( V_626 , & V_287 -> V_572 ) ;
F_462 ( V_287 ) ;
F_463 ( V_287 ) ;
if ( V_35 -> V_283 . V_22 == V_217 ) {
V_287 -> V_627 = V_35 -> V_628 % 2 ;
if ( V_287 -> V_627 == 0 )
F_397 ( & V_35 -> V_629 , V_287 -> V_32 ,
V_287 -> V_32 + V_287 -> V_48 - 1 , V_98 ) ;
else
F_464 ( & V_35 -> V_629 , V_287 -> V_32 ,
V_287 -> V_32 + V_287 -> V_48 - 1 ) ;
} else {
V_287 -> V_627 = - 1 ;
F_397 ( & V_118 -> V_135 -> V_630 , V_287 -> V_32 ,
V_287 -> V_32 + V_287 -> V_48 - 1 , V_98 ) ;
}
V_118 -> V_323 = true ;
return V_287 ;
}
static struct V_262 *
F_465 ( struct V_117 * V_118 ,
struct V_34 * V_35 , T_3 V_631 )
{
struct V_262 * V_444 ;
struct V_262 * V_263 = & V_35 -> V_37 -> V_266 ;
int V_29 ;
bool V_632 = false ;
V_444 = F_358 ( V_118 , V_35 ) ;
if ( F_355 ( V_444 -> V_60 == 0 ) )
goto V_633;
V_164:
V_29 = F_356 ( V_444 , V_631 ) ;
if ( ! V_29 )
return V_444 ;
if ( V_444 -> V_634 )
return F_466 ( V_29 ) ;
if ( V_444 -> type == V_635 && ! V_632 ) {
V_632 = true ;
F_372 ( V_35 -> V_37 ) ;
goto V_164;
}
if ( F_262 ( V_35 , V_420 ) ) {
static F_467 ( V_636 ,
V_637 * 10 ,
1 ) ;
if ( F_468 ( & V_636 ) )
F_469 ( 1 , V_638
L_33 , V_29 ) ;
}
V_633:
V_29 = F_351 ( V_35 , V_444 , V_631 ,
V_422 ) ;
if ( ! V_29 )
return V_444 ;
if ( V_444 -> type != V_635 &&
V_444 -> V_95 == V_263 -> V_95 ) {
V_29 = F_356 ( V_263 , V_631 ) ;
if ( ! V_29 )
return V_263 ;
}
return F_466 ( V_29 ) ;
}
static void F_470 ( struct V_12 * V_37 ,
struct V_262 * V_444 , T_3 V_631 )
{
F_359 ( V_444 , V_631 , 0 ) ;
F_361 ( V_37 , V_444 , NULL , 0 ) ;
}
struct V_67 * F_471 ( struct V_117 * V_118 ,
struct V_34 * V_35 ,
T_2 V_17 , T_2 V_153 ,
struct V_623 * V_21 , int V_176 ,
T_2 V_639 , T_2 V_588 )
{
struct V_69 V_223 ;
struct V_262 * V_444 ;
struct V_67 * V_287 ;
struct V_189 * V_137 ;
T_2 V_7 = 0 ;
int V_29 ;
T_3 V_631 = V_35 -> V_55 ;
bool V_182 = F_84 ( V_35 -> V_37 ,
V_129 ) ;
if ( F_238 ( V_35 ) ) {
V_287 = F_456 ( V_118 , V_35 , V_35 -> V_640 ,
V_176 ) ;
if ( ! F_215 ( V_287 ) )
V_35 -> V_640 += V_631 ;
return V_287 ;
}
V_444 = F_465 ( V_118 , V_35 , V_631 ) ;
if ( F_215 ( V_444 ) )
return F_472 ( V_444 ) ;
V_29 = F_448 ( V_35 , V_631 , V_631 ,
V_588 , V_639 , & V_223 , 0 , 0 ) ;
if ( V_29 )
goto V_641;
V_287 = F_456 ( V_118 , V_35 , V_223 . V_22 , V_176 ) ;
if ( F_215 ( V_287 ) ) {
V_29 = F_216 ( V_287 ) ;
goto V_642;
}
if ( V_153 == V_643 ) {
if ( V_17 == 0 )
V_17 = V_223 . V_22 ;
V_7 |= V_134 ;
} else
F_32 ( V_17 > 0 ) ;
if ( V_153 != V_217 ) {
V_137 = F_229 () ;
if ( ! V_137 ) {
V_29 = - V_74 ;
goto V_644;
}
if ( V_21 )
memcpy ( & V_137 -> V_21 , V_21 , sizeof( V_137 -> V_21 ) ) ;
else
memset ( & V_137 -> V_21 , 0 , sizeof( V_137 -> V_21 ) ) ;
V_137 -> V_139 = V_7 ;
V_137 -> V_227 = V_182 ? false : true ;
V_137 -> V_138 = true ;
V_137 -> V_193 = false ;
V_137 -> V_176 = V_176 ;
V_29 = F_159 ( V_35 -> V_37 , V_118 ,
V_223 . V_22 , V_223 . V_33 ,
V_17 , V_153 , V_176 ,
V_244 ,
V_137 ) ;
if ( V_29 )
goto V_645;
}
return V_287 ;
V_645:
F_192 ( V_137 ) ;
V_644:
F_473 ( V_287 ) ;
V_642:
F_450 ( V_35 , V_223 . V_22 , V_223 . V_33 , 0 ) ;
V_641:
F_470 ( V_35 -> V_37 , V_444 , V_631 ) ;
return F_466 ( V_29 ) ;
}
static T_1 void F_474 ( struct V_117 * V_118 ,
struct V_34 * V_35 ,
struct V_646 * V_647 ,
struct V_65 * V_66 )
{
T_2 V_27 ;
T_2 V_311 ;
T_2 V_120 ;
T_2 V_7 ;
T_3 V_72 ;
T_3 V_631 ;
struct V_69 V_21 ;
struct V_67 * V_536 ;
int V_29 ;
int V_648 ;
int V_649 = 0 ;
if ( V_66 -> V_83 [ V_647 -> V_176 ] < V_647 -> V_650 ) {
V_647 -> V_651 = V_647 -> V_651 * 2 / 3 ;
V_647 -> V_651 = F_439 ( V_647 -> V_651 , 2 ) ;
} else {
V_647 -> V_651 = V_647 -> V_651 * 3 / 2 ;
V_647 -> V_651 = F_24 ( int , V_647 -> V_651 ,
F_475 ( V_35 ) ) ;
}
V_536 = V_66 -> V_82 [ V_647 -> V_176 ] ;
V_72 = F_39 ( V_536 ) ;
V_631 = V_35 -> V_55 ;
for ( V_648 = V_66 -> V_83 [ V_647 -> V_176 ] ; V_648 < V_72 ; V_648 ++ ) {
if ( V_649 >= V_647 -> V_651 )
break;
F_48 () ;
V_27 = F_246 ( V_536 , V_648 ) ;
V_311 = F_476 ( V_536 , V_648 ) ;
if ( V_648 == V_66 -> V_83 [ V_647 -> V_176 ] )
goto V_77;
if ( V_647 -> V_652 == V_653 &&
V_311 <= V_35 -> V_283 . V_33 )
continue;
V_29 = F_83 ( V_118 , V_35 , V_27 ,
V_647 -> V_176 - 1 , 1 , & V_120 ,
& V_7 ) ;
if ( V_29 < 0 )
continue;
F_32 ( V_120 == 0 ) ;
if ( V_647 -> V_652 == V_654 ) {
if ( V_120 == 1 )
goto V_77;
if ( V_647 -> V_176 == 1 &&
( V_7 & V_134 ) )
continue;
if ( ! V_647 -> V_655 ||
V_311 <= V_35 -> V_283 . V_33 )
continue;
F_131 ( V_536 , & V_21 , V_648 ) ;
V_29 = F_477 ( & V_21 ,
& V_647 -> V_656 ) ;
if ( V_29 < 0 )
continue;
} else {
if ( V_647 -> V_176 == 1 &&
( V_7 & V_134 ) )
continue;
}
V_77:
F_478 ( V_35 , V_27 ) ;
V_649 ++ ;
}
V_647 -> V_650 = V_648 ;
}
static int F_479 ( struct V_117 * V_118 ,
struct V_34 * V_35 , T_2 V_27 ,
T_2 V_36 )
{
struct V_657 * V_658 ;
struct V_122 * V_123 ;
V_658 = F_221 ( sizeof( * V_658 ) , V_98 ) ;
if ( ! V_658 )
return - V_74 ;
V_658 -> V_27 = V_27 ;
V_658 -> V_36 = V_36 ;
V_658 -> V_659 = NULL ;
V_123 = & V_118 -> V_135 -> V_123 ;
F_11 ( & V_123 -> V_51 ) ;
if ( F_480 ( V_123 , V_658 ) )
F_9 ( V_658 ) ;
F_13 ( & V_123 -> V_51 ) ;
return 0 ;
}
static int F_481 ( struct V_117 * V_118 ,
struct V_34 * V_35 ,
struct V_67 * V_536 )
{
int V_43 = F_39 ( V_536 ) ;
int V_42 , V_660 , V_29 ;
struct V_69 V_21 ;
struct V_290 * V_291 ;
T_2 V_27 , V_36 ;
if ( ! V_35 -> V_37 -> V_504 )
return 0 ;
for ( V_42 = 0 ; V_42 < V_43 ; V_42 ++ ) {
F_41 ( V_536 , & V_21 , V_42 ) ;
if ( V_21 . type != V_295 )
continue;
V_291 = F_86 ( V_536 , V_42 , struct V_290 ) ;
V_660 = F_242 ( V_536 , V_291 ) ;
if ( V_660 == V_296 )
continue;
V_27 = F_243 ( V_536 , V_291 ) ;
if ( ! V_27 )
continue;
V_36 = F_244 ( V_536 , V_291 ) ;
V_29 = F_479 ( V_118 , V_35 , V_27 , V_36 ) ;
if ( V_29 )
return V_29 ;
}
return 0 ;
}
static int F_482 ( struct V_34 * V_35 ,
struct V_65 * V_66 , int V_661 )
{
int V_176 = 0 ;
int V_43 , V_648 ;
struct V_67 * V_536 ;
if ( V_661 == 0 )
return 1 ;
while ( V_176 <= V_661 ) {
V_536 = V_66 -> V_82 [ V_176 ] ;
V_43 = F_39 ( V_536 ) ;
V_66 -> V_83 [ V_176 ] ++ ;
V_648 = V_66 -> V_83 [ V_176 ] ;
if ( V_648 >= V_43 || V_176 == 0 ) {
if ( V_176 != V_661 ) {
F_483 ( V_536 , V_66 -> V_662 [ V_176 ] ) ;
V_66 -> V_662 [ V_176 ] = 0 ;
F_473 ( V_536 ) ;
V_66 -> V_82 [ V_176 ] = NULL ;
V_66 -> V_83 [ V_176 ] = 0 ;
}
} else {
break;
}
V_176 ++ ;
}
V_536 = V_66 -> V_82 [ V_661 ] ;
if ( V_66 -> V_83 [ V_661 ] >= F_39 ( V_536 ) )
return 1 ;
return 0 ;
}
static int F_484 ( struct V_117 * V_118 ,
struct V_34 * V_35 ,
struct V_67 * V_663 ,
T_2 V_664 ,
int V_661 )
{
int V_29 = 0 ;
int V_176 ;
struct V_67 * V_536 = V_663 ;
struct V_65 * V_66 = NULL ;
F_32 ( V_661 < 0 || V_661 > V_177 ) ;
F_32 ( V_663 == NULL ) ;
if ( ! V_35 -> V_37 -> V_504 )
return 0 ;
if ( ! F_485 ( V_663 ) ) {
V_29 = F_486 ( V_663 , V_664 ) ;
if ( V_29 )
goto V_81;
}
if ( V_661 == 0 ) {
V_29 = F_481 ( V_118 , V_35 , V_663 ) ;
goto V_81;
}
V_66 = F_34 () ;
if ( ! V_66 )
return - V_74 ;
F_487 ( V_663 ) ;
V_66 -> V_82 [ V_661 ] = V_663 ;
V_66 -> V_83 [ V_661 ] = 0 ;
V_66 -> V_662 [ V_661 ] = 0 ;
V_665:
V_176 = V_661 ;
while ( V_176 >= 0 ) {
if ( V_66 -> V_82 [ V_176 ] == NULL ) {
int V_666 ;
T_2 V_667 ;
T_2 V_668 ;
V_536 = V_66 -> V_82 [ V_176 + 1 ] ;
V_666 = V_66 -> V_83 [ V_176 + 1 ] ;
V_668 = F_246 ( V_536 , V_666 ) ;
V_667 = F_476 ( V_536 , V_666 ) ;
V_536 = F_488 ( V_35 , V_668 , V_667 ) ;
if ( F_215 ( V_536 ) ) {
V_29 = F_216 ( V_536 ) ;
goto V_81;
} else if ( ! F_485 ( V_536 ) ) {
F_473 ( V_536 ) ;
V_29 = - V_184 ;
goto V_81;
}
V_66 -> V_82 [ V_176 ] = V_536 ;
V_66 -> V_83 [ V_176 ] = 0 ;
F_489 ( V_536 ) ;
F_490 ( V_536 , V_669 ) ;
V_66 -> V_662 [ V_176 ] = V_670 ;
V_29 = F_479 ( V_118 , V_35 , V_668 ,
V_35 -> V_55 ) ;
if ( V_29 )
goto V_81;
}
if ( V_176 == 0 ) {
V_29 = F_481 ( V_118 , V_35 , V_66 -> V_82 [ V_176 ] ) ;
if ( V_29 )
goto V_81;
V_29 = F_482 ( V_35 , V_66 , V_661 ) ;
if ( V_29 )
break;
goto V_665;
}
V_176 -- ;
}
V_29 = 0 ;
V_81:
F_53 ( V_66 ) ;
return V_29 ;
}
static T_1 int F_491 ( struct V_117 * V_118 ,
struct V_34 * V_35 ,
struct V_65 * V_66 ,
struct V_646 * V_647 , int V_671 )
{
int V_176 = V_647 -> V_176 ;
struct V_67 * V_536 = V_66 -> V_82 [ V_176 ] ;
T_2 V_672 = V_134 ;
int V_29 ;
if ( V_647 -> V_652 == V_653 &&
F_239 ( V_536 ) != V_35 -> V_283 . V_22 )
return 1 ;
if ( V_671 &&
( ( V_647 -> V_652 == V_654 && V_647 -> V_120 [ V_176 ] != 1 ) ||
( V_647 -> V_652 == V_653 && ! ( V_647 -> V_7 [ V_176 ] & V_672 ) ) ) ) {
F_32 ( ! V_66 -> V_662 [ V_176 ] ) ;
V_29 = F_83 ( V_118 , V_35 ,
V_536 -> V_32 , V_176 , 1 ,
& V_647 -> V_120 [ V_176 ] ,
& V_647 -> V_7 [ V_176 ] ) ;
F_32 ( V_29 == - V_74 ) ;
if ( V_29 )
return V_29 ;
F_32 ( V_647 -> V_120 [ V_176 ] == 0 ) ;
}
if ( V_647 -> V_652 == V_654 ) {
if ( V_647 -> V_120 [ V_176 ] > 1 )
return 1 ;
if ( V_66 -> V_662 [ V_176 ] && ! V_647 -> V_183 ) {
F_483 ( V_536 , V_66 -> V_662 [ V_176 ] ) ;
V_66 -> V_662 [ V_176 ] = 0 ;
}
return 0 ;
}
if ( ! ( V_647 -> V_7 [ V_176 ] & V_672 ) ) {
F_32 ( ! V_66 -> V_662 [ V_176 ] ) ;
V_29 = F_247 ( V_118 , V_35 , V_536 , 1 ) ;
F_32 ( V_29 ) ;
V_29 = F_248 ( V_118 , V_35 , V_536 , 0 ) ;
F_32 ( V_29 ) ;
V_29 = F_228 ( V_118 , V_35 , V_536 -> V_32 ,
V_536 -> V_48 , V_672 ,
F_240 ( V_536 ) , 0 ) ;
F_32 ( V_29 ) ;
V_647 -> V_7 [ V_176 ] |= V_672 ;
}
if ( V_66 -> V_662 [ V_176 ] && V_176 > 0 ) {
F_483 ( V_536 , V_66 -> V_662 [ V_176 ] ) ;
V_66 -> V_662 [ V_176 ] = 0 ;
}
return 0 ;
}
static T_1 int F_492 ( struct V_117 * V_118 ,
struct V_34 * V_35 ,
struct V_65 * V_66 ,
struct V_646 * V_647 , int * V_671 )
{
T_2 V_27 ;
T_2 V_311 ;
T_2 V_17 ;
T_3 V_631 ;
struct V_69 V_21 ;
struct V_67 * V_80 ;
int V_176 = V_647 -> V_176 ;
int V_77 = 0 ;
int V_29 = 0 ;
bool V_673 = false ;
V_311 = F_476 ( V_66 -> V_82 [ V_176 ] ,
V_66 -> V_83 [ V_176 ] ) ;
if ( V_647 -> V_652 == V_653 &&
V_311 <= V_35 -> V_283 . V_33 ) {
* V_671 = 1 ;
return 1 ;
}
V_27 = F_246 ( V_66 -> V_82 [ V_176 ] , V_66 -> V_83 [ V_176 ] ) ;
V_631 = V_35 -> V_55 ;
V_80 = F_493 ( V_35 -> V_37 , V_27 ) ;
if ( ! V_80 ) {
V_80 = F_457 ( V_35 , V_27 ) ;
if ( F_215 ( V_80 ) )
return F_216 ( V_80 ) ;
F_459 ( V_35 -> V_283 . V_22 , V_80 ,
V_176 - 1 ) ;
V_77 = 1 ;
}
F_460 ( V_80 ) ;
F_462 ( V_80 ) ;
V_29 = F_83 ( V_118 , V_35 , V_27 , V_176 - 1 , 1 ,
& V_647 -> V_120 [ V_176 - 1 ] ,
& V_647 -> V_7 [ V_176 - 1 ] ) ;
if ( V_29 < 0 ) {
F_494 ( V_80 ) ;
return V_29 ;
}
if ( F_355 ( V_647 -> V_120 [ V_176 - 1 ] == 0 ) ) {
F_418 ( V_35 -> V_37 , L_34 ) ;
F_91 () ;
}
* V_671 = 0 ;
if ( V_647 -> V_652 == V_654 ) {
if ( V_647 -> V_120 [ V_176 - 1 ] > 1 ) {
V_673 = true ;
if ( V_176 == 1 &&
( V_647 -> V_7 [ 0 ] & V_134 ) )
goto V_674;
if ( ! V_647 -> V_655 ||
V_311 <= V_35 -> V_283 . V_33 )
goto V_674;
F_131 ( V_66 -> V_82 [ V_176 ] , & V_21 ,
V_66 -> V_83 [ V_176 ] ) ;
V_29 = F_477 ( & V_21 , & V_647 -> V_656 ) ;
if ( V_29 < 0 )
goto V_674;
V_647 -> V_652 = V_653 ;
V_647 -> V_675 = V_176 - 1 ;
}
} else {
if ( V_176 == 1 &&
( V_647 -> V_7 [ 0 ] & V_134 ) )
goto V_674;
}
if ( ! F_495 ( V_80 , V_311 , 0 ) ) {
F_494 ( V_80 ) ;
F_473 ( V_80 ) ;
V_80 = NULL ;
* V_671 = 1 ;
}
if ( ! V_80 ) {
if ( V_77 && V_176 == 1 )
F_474 ( V_118 , V_35 , V_647 , V_66 ) ;
V_80 = F_488 ( V_35 , V_27 , V_311 ) ;
if ( F_215 ( V_80 ) ) {
return F_216 ( V_80 ) ;
} else if ( ! F_485 ( V_80 ) ) {
F_473 ( V_80 ) ;
return - V_184 ;
}
F_460 ( V_80 ) ;
F_462 ( V_80 ) ;
}
V_176 -- ;
F_32 ( V_176 != F_240 ( V_80 ) ) ;
V_66 -> V_82 [ V_176 ] = V_80 ;
V_66 -> V_83 [ V_176 ] = 0 ;
V_66 -> V_662 [ V_176 ] = V_676 ;
V_647 -> V_176 = V_176 ;
if ( V_647 -> V_176 == 1 )
V_647 -> V_650 = 0 ;
return 0 ;
V_674:
V_647 -> V_120 [ V_176 - 1 ] = 0 ;
V_647 -> V_7 [ V_176 - 1 ] = 0 ;
if ( V_647 -> V_652 == V_654 ) {
if ( V_647 -> V_7 [ V_176 ] & V_134 ) {
V_17 = V_66 -> V_82 [ V_176 ] -> V_32 ;
} else {
F_32 ( V_35 -> V_283 . V_22 !=
F_239 ( V_66 -> V_82 [ V_176 ] ) ) ;
V_17 = 0 ;
}
if ( V_673 ) {
V_29 = F_484 ( V_118 , V_35 , V_80 ,
V_311 , V_176 - 1 ) ;
if ( V_29 ) {
F_496 ( V_35 -> V_37 ,
L_35
L_36
L_37 ,
V_29 ) ;
}
}
V_29 = V_294 ( V_118 , V_35 , V_27 , V_631 , V_17 ,
V_35 -> V_283 . V_22 , V_176 - 1 , 0 ) ;
F_32 ( V_29 ) ;
}
F_494 ( V_80 ) ;
F_473 ( V_80 ) ;
* V_671 = 1 ;
return 1 ;
}
static T_1 int F_497 ( struct V_117 * V_118 ,
struct V_34 * V_35 ,
struct V_65 * V_66 ,
struct V_646 * V_647 )
{
int V_29 ;
int V_176 = V_647 -> V_176 ;
struct V_67 * V_536 = V_66 -> V_82 [ V_176 ] ;
T_2 V_17 = 0 ;
if ( V_647 -> V_652 == V_653 ) {
F_32 ( V_647 -> V_675 < V_176 ) ;
if ( V_176 < V_647 -> V_675 )
goto V_81;
V_29 = F_42 ( V_66 , V_176 + 1 , & V_647 -> V_656 ) ;
if ( V_29 > 0 )
V_647 -> V_655 = 0 ;
V_647 -> V_652 = V_654 ;
V_647 -> V_675 = - 1 ;
V_66 -> V_83 [ V_176 ] = 0 ;
if ( ! V_66 -> V_662 [ V_176 ] ) {
F_32 ( V_176 == 0 ) ;
F_460 ( V_536 ) ;
F_462 ( V_536 ) ;
V_66 -> V_662 [ V_176 ] = V_676 ;
V_29 = F_83 ( V_118 , V_35 ,
V_536 -> V_32 , V_176 , 1 ,
& V_647 -> V_120 [ V_176 ] ,
& V_647 -> V_7 [ V_176 ] ) ;
if ( V_29 < 0 ) {
F_483 ( V_536 , V_66 -> V_662 [ V_176 ] ) ;
V_66 -> V_662 [ V_176 ] = 0 ;
return V_29 ;
}
F_32 ( V_647 -> V_120 [ V_176 ] == 0 ) ;
if ( V_647 -> V_120 [ V_176 ] == 1 ) {
F_483 ( V_536 , V_66 -> V_662 [ V_176 ] ) ;
V_66 -> V_662 [ V_176 ] = 0 ;
return 1 ;
}
}
}
F_32 ( V_647 -> V_120 [ V_176 ] > 1 && ! V_66 -> V_662 [ V_176 ] ) ;
if ( V_647 -> V_120 [ V_176 ] == 1 ) {
if ( V_176 == 0 ) {
if ( V_647 -> V_7 [ V_176 ] & V_134 )
V_29 = F_248 ( V_118 , V_35 , V_536 , 1 ) ;
else
V_29 = F_248 ( V_118 , V_35 , V_536 , 0 ) ;
F_32 ( V_29 ) ;
V_29 = F_481 ( V_118 , V_35 , V_536 ) ;
if ( V_29 ) {
F_496 ( V_35 -> V_37 ,
L_38
L_39
L_37 ,
V_29 ) ;
}
}
if ( ! V_66 -> V_662 [ V_176 ] &&
F_425 ( V_536 ) == V_118 -> V_274 ) {
F_460 ( V_536 ) ;
F_462 ( V_536 ) ;
V_66 -> V_662 [ V_176 ] = V_676 ;
}
F_461 ( V_118 , V_35 -> V_37 , V_536 ) ;
}
if ( V_536 == V_35 -> V_136 ) {
if ( V_647 -> V_7 [ V_176 ] & V_134 )
V_17 = V_536 -> V_32 ;
else
F_32 ( V_35 -> V_283 . V_22 !=
F_239 ( V_536 ) ) ;
} else {
if ( V_647 -> V_7 [ V_176 + 1 ] & V_134 )
V_17 = V_66 -> V_82 [ V_176 + 1 ] -> V_32 ;
else
F_32 ( V_35 -> V_283 . V_22 !=
F_239 ( V_66 -> V_82 [ V_176 + 1 ] ) ) ;
}
F_424 ( V_118 , V_35 , V_536 , V_17 , V_647 -> V_120 [ V_176 ] == 1 ) ;
V_81:
V_647 -> V_120 [ V_176 ] = 0 ;
V_647 -> V_7 [ V_176 ] = 0 ;
return 0 ;
}
static T_1 int F_498 ( struct V_117 * V_118 ,
struct V_34 * V_35 ,
struct V_65 * V_66 ,
struct V_646 * V_647 )
{
int V_176 = V_647 -> V_176 ;
int V_671 = 1 ;
int V_29 ;
while ( V_176 >= 0 ) {
V_29 = F_491 ( V_118 , V_35 , V_66 , V_647 , V_671 ) ;
if ( V_29 > 0 )
break;
if ( V_176 == 0 )
break;
if ( V_66 -> V_83 [ V_176 ] >=
F_39 ( V_66 -> V_82 [ V_176 ] ) )
break;
V_29 = F_492 ( V_118 , V_35 , V_66 , V_647 , & V_671 ) ;
if ( V_29 > 0 ) {
V_66 -> V_83 [ V_176 ] ++ ;
continue;
} else if ( V_29 < 0 )
return V_29 ;
V_176 = V_647 -> V_176 ;
}
return 0 ;
}
static T_1 int F_499 ( struct V_117 * V_118 ,
struct V_34 * V_35 ,
struct V_65 * V_66 ,
struct V_646 * V_647 , int V_677 )
{
int V_176 = V_647 -> V_176 ;
int V_29 ;
V_66 -> V_83 [ V_176 ] = F_39 ( V_66 -> V_82 [ V_176 ] ) ;
while ( V_176 < V_677 && V_66 -> V_82 [ V_176 ] ) {
V_647 -> V_176 = V_176 ;
if ( V_66 -> V_83 [ V_176 ] + 1 <
F_39 ( V_66 -> V_82 [ V_176 ] ) ) {
V_66 -> V_83 [ V_176 ] ++ ;
return 0 ;
} else {
V_29 = F_497 ( V_118 , V_35 , V_66 , V_647 ) ;
if ( V_29 > 0 )
return 0 ;
if ( V_66 -> V_662 [ V_176 ] ) {
F_483 ( V_66 -> V_82 [ V_176 ] ,
V_66 -> V_662 [ V_176 ] ) ;
V_66 -> V_662 [ V_176 ] = 0 ;
}
F_473 ( V_66 -> V_82 [ V_176 ] ) ;
V_66 -> V_82 [ V_176 ] = NULL ;
V_176 ++ ;
}
}
return 1 ;
}
int F_500 ( struct V_34 * V_35 ,
struct V_262 * V_444 , int V_655 ,
int V_678 )
{
struct V_65 * V_66 ;
struct V_117 * V_118 ;
struct V_34 * V_88 = V_35 -> V_37 -> V_88 ;
struct V_679 * V_284 = & V_35 -> V_284 ;
struct V_646 * V_647 ;
struct V_69 V_21 ;
int V_160 = 0 ;
int V_29 ;
int V_176 ;
bool V_680 = false ;
F_193 ( V_35 -> V_37 , L_40 , V_35 -> V_22 ) ;
V_66 = F_34 () ;
if ( ! V_66 ) {
V_160 = - V_74 ;
goto V_81;
}
V_647 = F_61 ( sizeof( * V_647 ) , V_98 ) ;
if ( ! V_647 ) {
F_53 ( V_66 ) ;
V_160 = - V_74 ;
goto V_81;
}
V_118 = F_501 ( V_88 , 0 ) ;
if ( F_215 ( V_118 ) ) {
V_160 = F_216 ( V_118 ) ;
goto V_131;
}
if ( V_444 )
V_118 -> V_444 = V_444 ;
if ( F_502 ( & V_284 -> V_681 ) == 0 ) {
V_176 = F_240 ( V_35 -> V_136 ) ;
V_66 -> V_82 [ V_176 ] = F_503 ( V_35 ) ;
F_462 ( V_66 -> V_82 [ V_176 ] ) ;
V_66 -> V_83 [ V_176 ] = 0 ;
V_66 -> V_662 [ V_176 ] = V_676 ;
memset ( & V_647 -> V_656 , 0 ,
sizeof( V_647 -> V_656 ) ) ;
} else {
F_504 ( & V_21 , & V_284 -> V_681 ) ;
memcpy ( & V_647 -> V_656 , & V_21 ,
sizeof( V_647 -> V_656 ) ) ;
V_176 = V_284 -> V_682 ;
F_32 ( V_176 == 0 ) ;
V_66 -> V_683 = V_176 ;
V_29 = F_38 ( NULL , V_35 , & V_21 , V_66 , 0 , 0 ) ;
V_66 -> V_683 = 0 ;
if ( V_29 < 0 ) {
V_160 = V_29 ;
goto V_684;
}
F_8 ( V_29 > 0 ) ;
F_136 ( V_66 , 0 ) ;
V_176 = F_240 ( V_35 -> V_136 ) ;
while ( 1 ) {
F_460 ( V_66 -> V_82 [ V_176 ] ) ;
F_462 ( V_66 -> V_82 [ V_176 ] ) ;
V_66 -> V_662 [ V_176 ] = V_676 ;
V_29 = F_83 ( V_118 , V_35 ,
V_66 -> V_82 [ V_176 ] -> V_32 ,
V_176 , 1 , & V_647 -> V_120 [ V_176 ] ,
& V_647 -> V_7 [ V_176 ] ) ;
if ( V_29 < 0 ) {
V_160 = V_29 ;
goto V_684;
}
F_32 ( V_647 -> V_120 [ V_176 ] == 0 ) ;
if ( V_176 == V_284 -> V_682 )
break;
F_494 ( V_66 -> V_82 [ V_176 ] ) ;
V_66 -> V_662 [ V_176 ] = 0 ;
F_8 ( V_647 -> V_120 [ V_176 ] != 1 ) ;
V_176 -- ;
}
}
V_647 -> V_176 = V_176 ;
V_647 -> V_675 = - 1 ;
V_647 -> V_652 = V_654 ;
V_647 -> V_655 = V_655 ;
V_647 -> V_183 = 0 ;
V_647 -> V_678 = V_678 ;
V_647 -> V_651 = F_475 ( V_35 ) ;
while ( 1 ) {
V_29 = F_498 ( V_118 , V_35 , V_66 , V_647 ) ;
if ( V_29 < 0 ) {
V_160 = V_29 ;
break;
}
V_29 = F_499 ( V_118 , V_35 , V_66 , V_647 , V_177 ) ;
if ( V_29 < 0 ) {
V_160 = V_29 ;
break;
}
if ( V_29 > 0 ) {
F_32 ( V_647 -> V_652 != V_654 ) ;
break;
}
if ( V_647 -> V_652 == V_654 ) {
V_176 = V_647 -> V_176 ;
F_505 ( V_66 -> V_82 [ V_176 ] ,
& V_284 -> V_681 ,
V_66 -> V_83 [ V_176 ] ) ;
V_284 -> V_682 = V_176 ;
}
F_32 ( V_647 -> V_176 == 0 ) ;
if ( F_506 ( V_118 , V_88 ) ||
( ! V_678 && F_507 ( V_35 ) ) ) {
V_29 = F_508 ( V_118 , V_88 ,
& V_35 -> V_283 ,
V_284 ) ;
if ( V_29 ) {
F_162 ( V_118 , V_88 , V_29 ) ;
V_160 = V_29 ;
goto V_684;
}
F_509 ( V_118 , V_88 ) ;
if ( ! V_678 && F_507 ( V_35 ) ) {
F_510 ( L_41 ) ;
V_160 = - V_187 ;
goto V_131;
}
V_118 = F_501 ( V_88 , 0 ) ;
if ( F_215 ( V_118 ) ) {
V_160 = F_216 ( V_118 ) ;
goto V_131;
}
if ( V_444 )
V_118 -> V_444 = V_444 ;
}
}
F_45 ( V_66 ) ;
if ( V_160 )
goto V_684;
V_29 = F_511 ( V_118 , V_88 , & V_35 -> V_283 ) ;
if ( V_29 ) {
F_162 ( V_118 , V_88 , V_29 ) ;
goto V_684;
}
if ( V_35 -> V_283 . V_22 != V_643 ) {
V_29 = F_512 ( V_88 , & V_35 -> V_283 , V_66 ,
NULL , NULL ) ;
if ( V_29 < 0 ) {
F_162 ( V_118 , V_88 , V_29 ) ;
V_160 = V_29 ;
goto V_684;
} else if ( V_29 > 0 ) {
F_513 ( V_118 , V_88 ,
V_35 -> V_283 . V_22 ) ;
}
}
if ( F_241 ( V_685 , & V_35 -> V_293 ) ) {
F_514 ( V_118 , V_35 ) ;
} else {
F_473 ( V_35 -> V_136 ) ;
F_473 ( V_35 -> V_686 ) ;
F_515 ( V_35 ) ;
}
V_680 = true ;
V_684:
F_509 ( V_118 , V_88 ) ;
V_131:
F_9 ( V_647 ) ;
F_53 ( V_66 ) ;
V_81:
if ( ! V_678 && V_680 == false )
F_516 ( V_35 ) ;
if ( V_160 && V_160 != - V_187 )
F_517 ( V_35 -> V_37 , V_160 , NULL ) ;
return V_160 ;
}
int F_518 ( struct V_117 * V_118 ,
struct V_34 * V_35 ,
struct V_67 * V_136 ,
struct V_67 * V_17 )
{
struct V_65 * V_66 ;
struct V_646 * V_647 ;
int V_176 ;
int V_687 ;
int V_29 = 0 ;
int V_688 ;
F_32 ( V_35 -> V_283 . V_22 != V_643 ) ;
V_66 = F_34 () ;
if ( ! V_66 )
return - V_74 ;
V_647 = F_61 ( sizeof( * V_647 ) , V_98 ) ;
if ( ! V_647 ) {
F_53 ( V_66 ) ;
return - V_74 ;
}
F_519 ( V_17 ) ;
V_687 = F_240 ( V_17 ) ;
F_487 ( V_17 ) ;
V_66 -> V_82 [ V_687 ] = V_17 ;
V_66 -> V_83 [ V_687 ] = F_39 ( V_17 ) ;
F_519 ( V_136 ) ;
V_176 = F_240 ( V_136 ) ;
V_66 -> V_82 [ V_176 ] = V_136 ;
V_66 -> V_83 [ V_176 ] = 0 ;
V_66 -> V_662 [ V_176 ] = V_676 ;
V_647 -> V_120 [ V_687 ] = 1 ;
V_647 -> V_7 [ V_687 ] = V_134 ;
V_647 -> V_176 = V_176 ;
V_647 -> V_675 = - 1 ;
V_647 -> V_652 = V_654 ;
V_647 -> V_655 = 0 ;
V_647 -> V_183 = 1 ;
V_647 -> V_678 = 1 ;
V_647 -> V_651 = F_475 ( V_35 ) ;
while ( 1 ) {
V_688 = F_498 ( V_118 , V_35 , V_66 , V_647 ) ;
if ( V_688 < 0 ) {
V_29 = V_688 ;
break;
}
V_688 = F_499 ( V_118 , V_35 , V_66 , V_647 , V_687 ) ;
if ( V_688 < 0 )
V_29 = V_688 ;
if ( V_688 != 0 )
break;
}
F_9 ( V_647 ) ;
F_53 ( V_66 ) ;
return V_29 ;
}
static T_2 F_520 ( struct V_34 * V_35 , T_2 V_7 )
{
T_2 V_381 ;
T_2 V_689 ;
V_689 = F_297 ( V_35 -> V_37 , V_7 ) ;
if ( V_689 )
return F_299 ( V_689 ) ;
V_381 = V_35 -> V_37 -> V_382 -> V_383 ;
V_689 = V_392 |
V_391 | V_390 |
V_344 | V_345 ;
if ( V_381 == 1 ) {
V_689 |= V_343 ;
V_689 = V_7 & ~ V_689 ;
if ( V_7 & V_392 )
return V_689 ;
if ( V_7 & ( V_344 |
V_345 ) )
return V_689 | V_343 ;
} else {
if ( V_7 & V_689 )
return V_7 ;
V_689 |= V_343 ;
V_689 = V_7 & ~ V_689 ;
if ( V_7 & V_343 )
return V_689 | V_344 ;
}
return V_7 ;
}
static int F_521 ( struct V_1 * V_2 , int V_410 )
{
struct V_111 * V_409 = V_2 -> V_95 ;
T_2 V_36 ;
T_2 V_690 ;
int V_29 = - V_314 ;
if ( ( V_409 -> V_7 &
( V_340 | V_54 ) ) &&
! V_410 )
V_690 = V_304 ;
else
V_690 = 0 ;
F_11 ( & V_409 -> V_51 ) ;
F_11 ( & V_2 -> V_51 ) ;
if ( V_2 -> V_307 ) {
V_2 -> V_307 ++ ;
V_29 = 0 ;
goto V_81;
}
V_36 = V_2 -> V_21 . V_33 - V_2 -> V_10 - V_2 -> V_9 -
V_2 -> V_45 - F_58 ( & V_2 -> V_96 ) ;
if ( V_409 -> V_94 + V_409 -> V_354 + V_409 -> V_353 +
V_409 -> V_356 + V_409 -> V_355 + V_36 +
V_690 <= V_409 -> V_341 ) {
V_409 -> V_355 += V_36 ;
V_2 -> V_307 ++ ;
F_72 ( & V_2 -> V_691 , & V_409 -> V_362 ) ;
V_29 = 0 ;
}
V_81:
F_13 ( & V_2 -> V_51 ) ;
F_13 ( & V_409 -> V_51 ) ;
return V_29 ;
}
int F_522 ( struct V_34 * V_35 ,
struct V_1 * V_2 )
{
struct V_117 * V_118 ;
T_2 V_692 ;
int V_29 ;
V_164:
V_118 = F_214 ( V_35 ) ;
if ( F_215 ( V_118 ) )
return F_216 ( V_118 ) ;
F_49 ( & V_35 -> V_37 -> V_693 ) ;
if ( F_241 ( V_694 , & V_118 -> V_135 -> V_7 ) ) {
T_2 V_274 = V_118 -> V_274 ;
F_47 ( & V_35 -> V_37 -> V_693 ) ;
F_218 ( V_118 , V_35 ) ;
V_29 = F_523 ( V_35 , V_274 ) ;
if ( V_29 )
return V_29 ;
goto V_164;
}
V_692 = F_520 ( V_35 , V_2 -> V_7 ) ;
if ( V_692 != V_2 -> V_7 ) {
V_29 = F_306 ( V_118 , V_35 , V_692 ,
V_403 ) ;
if ( V_29 == - V_314 )
V_29 = 0 ;
if ( V_29 < 0 )
goto V_81;
}
V_29 = F_521 ( V_2 , 0 ) ;
if ( ! V_29 )
goto V_81;
V_692 = F_300 ( V_35 , V_2 -> V_95 -> V_7 ) ;
V_29 = F_306 ( V_118 , V_35 , V_692 ,
V_403 ) ;
if ( V_29 < 0 )
goto V_81;
V_29 = F_521 ( V_2 , 0 ) ;
V_81:
if ( V_2 -> V_7 & V_340 ) {
V_692 = F_520 ( V_35 , V_2 -> V_7 ) ;
F_524 ( V_35 -> V_37 -> V_395 ) ;
F_323 ( V_118 , V_35 , V_692 ) ;
F_525 ( V_35 -> V_37 -> V_395 ) ;
}
F_47 ( & V_35 -> V_37 -> V_693 ) ;
F_218 ( V_118 , V_35 ) ;
return V_29 ;
}
int F_526 ( struct V_117 * V_118 ,
struct V_34 * V_35 , T_2 type )
{
T_2 V_692 = F_300 ( V_35 , type ) ;
return F_306 ( V_118 , V_35 , V_692 ,
V_403 ) ;
}
T_2 F_527 ( struct V_111 * V_409 )
{
struct V_1 * V_14 ;
T_2 V_695 = 0 ;
int V_342 ;
if ( F_182 ( & V_409 -> V_362 ) )
return 0 ;
F_11 ( & V_409 -> V_51 ) ;
F_183 (block_group, &sinfo->ro_bgs, ro_list) {
F_11 ( & V_14 -> V_51 ) ;
if ( ! V_14 -> V_307 ) {
F_13 ( & V_14 -> V_51 ) ;
continue;
}
if ( V_14 -> V_7 & ( V_344 |
V_345 |
V_343 ) )
V_342 = 2 ;
else
V_342 = 1 ;
V_695 += ( V_14 -> V_21 . V_33 -
F_58 ( & V_14 -> V_96 ) ) *
V_342 ;
F_13 ( & V_14 -> V_51 ) ;
}
F_13 ( & V_409 -> V_51 ) ;
return V_695 ;
}
void F_528 ( struct V_34 * V_35 ,
struct V_1 * V_2 )
{
struct V_111 * V_409 = V_2 -> V_95 ;
T_2 V_36 ;
F_32 ( ! V_2 -> V_307 ) ;
F_11 ( & V_409 -> V_51 ) ;
F_11 ( & V_2 -> V_51 ) ;
if ( ! -- V_2 -> V_307 ) {
V_36 = V_2 -> V_21 . V_33 - V_2 -> V_10 -
V_2 -> V_9 - V_2 -> V_45 -
F_58 ( & V_2 -> V_96 ) ;
V_409 -> V_355 -= V_36 ;
F_274 ( & V_2 -> V_691 ) ;
}
F_13 ( & V_2 -> V_51 ) ;
F_13 ( & V_409 -> V_51 ) ;
}
int F_529 ( struct V_34 * V_35 , T_2 V_27 )
{
struct V_1 * V_14 ;
struct V_111 * V_95 ;
struct V_696 * V_382 = V_35 -> V_37 -> V_382 ;
struct V_697 * V_698 ;
struct V_117 * V_118 ;
T_2 V_699 ;
T_2 V_700 = 1 ;
T_2 V_701 = 0 ;
T_2 V_376 ;
int V_702 ;
int V_592 ;
int V_116 = 0 ;
int V_29 = 0 ;
V_702 = F_262 ( V_35 , V_420 ) ;
V_14 = F_76 ( V_35 -> V_37 , V_27 ) ;
if ( ! V_14 ) {
if ( V_702 )
F_416 ( V_35 -> V_37 ,
L_42 ,
V_27 ) ;
return - 1 ;
}
V_699 = F_58 ( & V_14 -> V_96 ) ;
if ( ! V_699 )
goto V_81;
V_95 = V_14 -> V_95 ;
F_11 ( & V_95 -> V_51 ) ;
V_116 = V_95 -> V_116 ;
if ( ( V_95 -> V_341 != V_14 -> V_21 . V_33 ) &&
( V_95 -> V_94 + V_95 -> V_354 +
V_95 -> V_353 + V_95 -> V_355 +
V_699 < V_95 -> V_341 ) ) {
F_13 ( & V_95 -> V_51 ) ;
goto V_81;
}
F_13 ( & V_95 -> V_51 ) ;
V_29 = - 1 ;
V_376 = F_297 ( V_35 -> V_37 , V_14 -> V_7 ) ;
if ( V_376 ) {
V_592 = F_430 ( F_299 ( V_376 ) ) ;
} else {
if ( V_116 ) {
if ( V_702 )
F_416 ( V_35 -> V_37 ,
L_43 ,
V_14 -> V_21 . V_22 ) ;
goto V_81;
}
V_592 = F_431 ( V_14 ) ;
}
if ( V_592 == V_575 ) {
V_700 = 4 ;
V_699 >>= 1 ;
} else if ( V_592 == V_576 ) {
V_700 = 2 ;
} else if ( V_592 == V_577 ) {
V_699 <<= 1 ;
} else if ( V_592 == V_578 ) {
V_700 = V_382 -> V_383 ;
V_699 = F_206 ( V_699 , V_700 ) ;
}
V_118 = F_214 ( V_35 ) ;
if ( F_215 ( V_118 ) ) {
V_29 = F_216 ( V_118 ) ;
goto V_81;
}
F_49 ( & V_35 -> V_37 -> V_419 ) ;
F_183 (device, &fs_devices->alloc_list, dev_alloc_list) {
T_2 V_703 ;
if ( V_698 -> V_341 > V_698 -> V_94 + V_699 &&
! V_698 -> V_704 ) {
V_29 = F_530 ( V_118 , V_698 , V_699 ,
& V_703 , NULL ) ;
if ( ! V_29 )
V_701 ++ ;
if ( V_701 >= V_700 )
break;
V_29 = - 1 ;
}
}
if ( V_702 && V_29 == - 1 )
F_416 ( V_35 -> V_37 ,
L_44 ,
V_14 -> V_21 . V_22 ) ;
F_47 ( & V_35 -> V_37 -> V_419 ) ;
F_218 ( V_118 , V_35 ) ;
V_81:
F_6 ( V_14 ) ;
return V_29 ;
}
static int F_531 ( struct V_34 * V_35 ,
struct V_65 * V_66 , struct V_69 * V_21 )
{
int V_29 = 0 ;
struct V_69 V_147 ;
struct V_67 * V_68 ;
int V_648 ;
V_29 = F_38 ( NULL , V_35 , V_21 , V_66 , 0 , 0 ) ;
if ( V_29 < 0 )
goto V_81;
while ( 1 ) {
V_648 = V_66 -> V_83 [ 0 ] ;
V_68 = V_66 -> V_82 [ 0 ] ;
if ( V_648 >= F_39 ( V_68 ) ) {
V_29 = F_51 ( V_35 , V_66 ) ;
if ( V_29 == 0 )
continue;
if ( V_29 < 0 )
goto V_81;
break;
}
F_41 ( V_68 , & V_147 , V_648 ) ;
if ( V_147 . V_22 >= V_21 -> V_22 &&
V_147 . type == V_188 ) {
V_29 = 0 ;
goto V_81;
}
V_66 -> V_83 [ 0 ] ++ ;
}
V_81:
return V_29 ;
}
void F_532 ( struct V_12 * V_13 )
{
struct V_1 * V_14 ;
T_2 V_71 = 0 ;
while ( 1 ) {
struct V_298 * V_298 ;
V_14 = F_75 ( V_13 , V_71 ) ;
while ( V_14 ) {
F_11 ( & V_14 -> V_51 ) ;
if ( V_14 -> V_173 )
break;
F_13 ( & V_14 -> V_51 ) ;
V_14 = F_252 ( V_13 -> V_88 ,
V_14 ) ;
}
if ( ! V_14 ) {
if ( V_71 == 0 )
break;
V_71 = 0 ;
continue;
}
V_298 = V_14 -> V_298 ;
V_14 -> V_173 = 0 ;
V_14 -> V_298 = NULL ;
F_13 ( & V_14 -> V_51 ) ;
F_267 ( V_298 ) ;
V_71 = V_14 -> V_21 . V_22 + V_14 -> V_21 . V_33 ;
F_6 ( V_14 ) ;
}
}
int F_533 ( struct V_12 * V_13 )
{
struct V_1 * V_14 ;
struct V_111 * V_95 ;
struct V_49 * V_52 ;
struct V_15 * V_30 ;
F_71 ( & V_13 -> V_84 ) ;
while ( ! F_182 ( & V_13 -> V_109 ) ) {
V_52 = F_184 ( V_13 -> V_109 . V_80 ,
struct V_49 , V_99 ) ;
F_195 ( & V_52 -> V_99 ) ;
F_26 ( V_52 ) ;
}
F_73 ( & V_13 -> V_84 ) ;
F_11 ( & V_13 -> V_530 ) ;
while ( ! F_182 ( & V_13 -> V_532 ) ) {
V_14 = F_273 ( & V_13 -> V_532 ,
struct V_1 ,
V_531 ) ;
F_274 ( & V_14 -> V_531 ) ;
F_6 ( V_14 ) ;
}
F_13 ( & V_13 -> V_530 ) ;
F_11 ( & V_13 -> V_18 ) ;
while ( ( V_30 = F_201 ( & V_13 -> V_19 ) ) != NULL ) {
V_14 = F_12 ( V_30 , struct V_1 ,
V_20 ) ;
F_194 ( & V_14 -> V_20 ,
& V_13 -> V_19 ) ;
F_534 ( & V_14 -> V_20 ) ;
F_13 ( & V_13 -> V_18 ) ;
F_71 ( & V_14 -> V_95 -> V_352 ) ;
F_195 ( & V_14 -> V_99 ) ;
F_73 ( & V_14 -> V_95 -> V_352 ) ;
if ( V_14 -> V_3 == V_107 )
F_429 ( V_14 ) ;
if ( V_14 -> V_3 == V_103 ||
V_14 -> V_3 == V_5 )
F_19 ( V_13 -> V_64 , V_14 ) ;
F_535 ( V_14 ) ;
F_6 ( V_14 ) ;
F_11 ( & V_13 -> V_18 ) ;
}
F_13 ( & V_13 -> V_18 ) ;
F_536 () ;
F_374 ( V_13 ) ;
while ( ! F_182 ( & V_13 -> V_95 ) ) {
int V_42 ;
V_95 = F_184 ( V_13 -> V_95 . V_80 ,
struct V_111 ,
V_99 ) ;
if ( F_262 ( V_13 -> V_88 , V_420 ) ) {
if ( F_8 ( V_95 -> V_353 > 0 ||
V_95 -> V_354 > 0 ||
V_95 -> V_356 > 0 ) ) {
F_327 ( V_95 , 0 , 0 ) ;
}
}
F_195 ( & V_95 -> V_99 ) ;
for ( V_42 = 0 ; V_42 < V_350 ; V_42 ++ ) {
struct V_705 * V_363 ;
V_363 = V_95 -> V_706 [ V_42 ] ;
V_95 -> V_706 [ V_42 ] = NULL ;
if ( V_363 ) {
F_537 ( V_363 ) ;
F_538 ( V_363 ) ;
}
}
F_537 ( & V_95 -> V_363 ) ;
F_538 ( & V_95 -> V_363 ) ;
}
return 0 ;
}
static void F_539 ( struct V_111 * V_95 ,
struct V_1 * V_2 )
{
int V_592 = F_431 ( V_2 ) ;
bool V_254 = false ;
F_71 ( & V_95 -> V_352 ) ;
if ( F_182 ( & V_95 -> V_351 [ V_592 ] ) )
V_254 = true ;
F_72 ( & V_2 -> V_99 , & V_95 -> V_351 [ V_592 ] ) ;
F_73 ( & V_95 -> V_352 ) ;
if ( V_254 ) {
struct V_707 * V_708 ;
int V_29 ;
V_708 = F_61 ( sizeof( * V_708 ) , V_98 ) ;
if ( ! V_708 )
goto V_709;
V_708 -> V_384 = V_592 ;
F_540 ( & V_708 -> V_363 , & V_710 ) ;
V_29 = F_541 ( & V_708 -> V_363 , & V_95 -> V_363 ,
L_8 , F_432 ( V_592 ) ) ;
if ( V_29 ) {
F_538 ( & V_708 -> V_363 ) ;
goto V_709;
}
V_95 -> V_706 [ V_592 ] = & V_708 -> V_363 ;
}
return;
V_709:
F_542 ( L_45 ) ;
}
static struct V_1 *
F_543 ( struct V_34 * V_35 , T_2 V_32 , T_2 V_60 )
{
struct V_1 * V_2 ;
V_2 = F_61 ( sizeof( * V_2 ) , V_98 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_11 = F_61 ( sizeof( * V_2 -> V_11 ) ,
V_98 ) ;
if ( ! V_2 -> V_11 ) {
F_9 ( V_2 ) ;
return NULL ;
}
V_2 -> V_21 . V_22 = V_32 ;
V_2 -> V_21 . V_33 = V_60 ;
V_2 -> V_21 . type = V_188 ;
V_2 -> V_56 = V_35 -> V_56 ;
V_2 -> V_37 = V_35 -> V_37 ;
V_2 -> V_711 = F_544 ( V_35 ,
& V_35 -> V_37 -> V_47 ,
V_32 ) ;
F_545 ( V_2 ) ;
F_65 ( & V_2 -> V_8 , 1 ) ;
F_290 ( & V_2 -> V_51 ) ;
F_289 ( & V_2 -> V_584 ) ;
F_62 ( & V_2 -> V_99 ) ;
F_62 ( & V_2 -> V_712 ) ;
F_62 ( & V_2 -> V_531 ) ;
F_62 ( & V_2 -> V_691 ) ;
F_62 ( & V_2 -> V_330 ) ;
F_62 ( & V_2 -> V_331 ) ;
F_546 ( V_2 ) ;
F_65 ( & V_2 -> V_713 , 0 ) ;
F_63 ( & V_2 -> V_714 ) ;
return V_2 ;
}
int F_547 ( struct V_34 * V_35 )
{
struct V_65 * V_66 ;
int V_29 ;
struct V_1 * V_2 ;
struct V_12 * V_13 = V_35 -> V_37 ;
struct V_111 * V_95 ;
struct V_69 V_21 ;
struct V_69 V_147 ;
struct V_67 * V_68 ;
int V_715 = 0 ;
T_2 V_716 ;
V_35 = V_13 -> V_64 ;
V_21 . V_22 = 0 ;
V_21 . V_33 = 0 ;
V_21 . type = V_188 ;
V_66 = F_34 () ;
if ( ! V_66 )
return - V_74 ;
V_66 -> V_77 = V_78 ;
V_716 = F_548 ( V_35 -> V_37 -> V_261 ) ;
if ( F_262 ( V_35 , V_312 ) &&
F_549 ( V_35 -> V_37 -> V_261 ) != V_716 )
V_715 = 1 ;
if ( F_262 ( V_35 , V_717 ) )
V_715 = 1 ;
while ( 1 ) {
V_29 = F_531 ( V_35 , V_66 , & V_21 ) ;
if ( V_29 > 0 )
break;
if ( V_29 != 0 )
goto error;
V_68 = V_66 -> V_82 [ 0 ] ;
F_41 ( V_68 , & V_147 , V_66 -> V_83 [ 0 ] ) ;
V_2 = F_543 ( V_35 , V_147 . V_22 ,
V_147 . V_33 ) ;
if ( ! V_2 ) {
V_29 = - V_74 ;
goto error;
}
if ( V_715 ) {
if ( F_262 ( V_35 , V_312 ) )
V_2 -> V_305 = V_321 ;
}
F_550 ( V_68 , & V_2 -> V_96 ,
F_250 ( V_68 , V_66 -> V_83 [ 0 ] ) ,
sizeof( V_2 -> V_96 ) ) ;
V_2 -> V_7 = F_551 ( & V_2 -> V_96 ) ;
V_21 . V_22 = V_147 . V_22 + V_147 . V_33 ;
F_45 ( V_66 ) ;
V_29 = F_21 ( V_35 , V_2 ) ;
if ( V_29 ) {
F_19 ( V_35 , V_2 ) ;
F_6 ( V_2 ) ;
goto error;
}
if ( V_147 . V_33 == F_58 ( & V_2 -> V_96 ) ) {
V_2 -> V_106 = ( T_2 ) - 1 ;
V_2 -> V_3 = V_4 ;
F_19 ( V_35 , V_2 ) ;
} else if ( F_58 ( & V_2 -> V_96 ) == 0 ) {
V_2 -> V_106 = ( T_2 ) - 1 ;
V_2 -> V_3 = V_4 ;
F_29 ( V_2 , V_35 -> V_37 ,
V_147 . V_22 ,
V_147 . V_22 +
V_147 . V_33 ) ;
F_19 ( V_35 , V_2 ) ;
}
V_29 = F_10 ( V_35 -> V_37 , V_2 ) ;
if ( V_29 ) {
F_535 ( V_2 ) ;
F_6 ( V_2 ) ;
goto error;
}
V_29 = F_287 ( V_13 , V_2 -> V_7 , V_147 . V_33 ,
F_58 ( & V_2 -> V_96 ) ,
& V_95 ) ;
if ( V_29 ) {
F_535 ( V_2 ) ;
F_11 ( & V_13 -> V_18 ) ;
F_194 ( & V_2 -> V_20 ,
& V_13 -> V_19 ) ;
F_534 ( & V_2 -> V_20 ) ;
F_13 ( & V_13 -> V_18 ) ;
F_6 ( V_2 ) ;
goto error;
}
V_2 -> V_95 = V_95 ;
F_11 ( & V_2 -> V_95 -> V_51 ) ;
V_2 -> V_95 -> V_355 += V_2 -> V_45 ;
F_13 ( & V_2 -> V_95 -> V_51 ) ;
F_539 ( V_95 , V_2 ) ;
F_293 ( V_35 -> V_37 , V_2 -> V_7 ) ;
if ( F_552 ( V_35 , V_2 -> V_21 . V_22 ) ) {
F_521 ( V_2 , 1 ) ;
} else if ( F_58 ( & V_2 -> V_96 ) == 0 ) {
F_11 ( & V_13 -> V_530 ) ;
if ( F_182 ( & V_2 -> V_531 ) ) {
F_4 ( V_2 ) ;
F_72 ( & V_2 -> V_531 ,
& V_13 -> V_532 ) ;
}
F_13 ( & V_13 -> V_530 ) ;
}
}
F_79 (space_info, &root->fs_info->space_info, list) {
if ( ! ( F_300 ( V_35 , V_95 -> V_7 ) &
( V_345 |
V_344 |
V_391 |
V_390 |
V_343 ) ) )
continue;
F_183 (cache,
&space_info->block_groups[BTRFS_RAID_RAID0],
list)
F_521 ( V_2 , 1 ) ;
F_183 (cache,
&space_info->block_groups[BTRFS_RAID_SINGLE],
list)
F_521 ( V_2 , 1 ) ;
}
F_373 ( V_13 ) ;
V_29 = 0 ;
error:
F_53 ( V_66 ) ;
return V_29 ;
}
void F_225 ( struct V_117 * V_118 ,
struct V_34 * V_35 )
{
struct V_1 * V_14 , * V_317 ;
struct V_34 * V_64 = V_35 -> V_37 -> V_64 ;
struct V_718 V_96 ;
struct V_69 V_21 ;
int V_29 = 0 ;
bool V_278 = V_118 -> V_278 ;
V_118 -> V_278 = false ;
F_269 (block_group, tmp, &trans->new_bgs, bg_list) {
if ( V_29 )
goto V_80;
F_11 ( & V_14 -> V_51 ) ;
memcpy ( & V_96 , & V_14 -> V_96 , sizeof( V_96 ) ) ;
memcpy ( & V_21 , & V_14 -> V_21 , sizeof( V_21 ) ) ;
F_13 ( & V_14 -> V_51 ) ;
V_29 = F_553 ( V_118 , V_64 , & V_21 , & V_96 ,
sizeof( V_96 ) ) ;
if ( V_29 )
F_162 ( V_118 , V_64 , V_29 ) ;
V_29 = F_554 ( V_118 , V_64 ,
V_21 . V_22 , V_21 . V_33 ) ;
if ( V_29 )
F_162 ( V_118 , V_64 , V_29 ) ;
F_555 ( V_118 , V_35 -> V_37 , V_14 ) ;
V_80:
F_274 ( & V_14 -> V_531 ) ;
}
V_118 -> V_278 = V_278 ;
}
int F_556 ( struct V_117 * V_118 ,
struct V_34 * V_35 , T_2 V_94 ,
T_2 type , T_2 V_719 , T_2 V_720 ,
T_2 V_60 )
{
int V_29 ;
struct V_34 * V_64 ;
struct V_1 * V_2 ;
V_64 = V_35 -> V_37 -> V_64 ;
F_557 ( V_35 -> V_37 , V_118 ) ;
V_2 = F_543 ( V_35 , V_720 , V_60 ) ;
if ( ! V_2 )
return - V_74 ;
F_396 ( & V_2 -> V_96 , V_94 ) ;
F_558 ( & V_2 -> V_96 , V_719 ) ;
F_559 ( & V_2 -> V_96 , type ) ;
V_2 -> V_7 = type ;
V_2 -> V_106 = ( T_2 ) - 1 ;
V_2 -> V_3 = V_4 ;
V_2 -> V_721 = 1 ;
V_29 = F_21 ( V_35 , V_2 ) ;
if ( V_29 ) {
F_19 ( V_35 , V_2 ) ;
F_6 ( V_2 ) ;
return V_29 ;
}
F_29 ( V_2 , V_35 -> V_37 , V_720 ,
V_720 + V_60 ) ;
F_19 ( V_35 , V_2 ) ;
#ifdef F_36
if ( F_37 ( V_35 , V_2 ) ) {
T_2 V_722 = V_60 - V_94 ;
V_94 += V_722 >> 1 ;
F_27 ( V_35 , V_2 ) ;
}
#endif
V_29 = F_287 ( V_35 -> V_37 , V_2 -> V_7 , 0 , 0 ,
& V_2 -> V_95 ) ;
if ( V_29 ) {
F_535 ( V_2 ) ;
F_6 ( V_2 ) ;
return V_29 ;
}
V_29 = F_10 ( V_35 -> V_37 , V_2 ) ;
if ( V_29 ) {
F_535 ( V_2 ) ;
F_6 ( V_2 ) ;
return V_29 ;
}
V_29 = F_287 ( V_35 -> V_37 , V_2 -> V_7 , V_60 , V_94 ,
& V_2 -> V_95 ) ;
if ( V_29 ) {
F_535 ( V_2 ) ;
F_11 ( & V_35 -> V_37 -> V_18 ) ;
F_194 ( & V_2 -> V_20 ,
& V_35 -> V_37 -> V_19 ) ;
F_534 ( & V_2 -> V_20 ) ;
F_13 ( & V_35 -> V_37 -> V_18 ) ;
F_6 ( V_2 ) ;
return V_29 ;
}
F_372 ( V_35 -> V_37 ) ;
F_11 ( & V_2 -> V_95 -> V_51 ) ;
V_2 -> V_95 -> V_355 += V_2 -> V_45 ;
F_13 ( & V_2 -> V_95 -> V_51 ) ;
F_539 ( V_2 -> V_95 , V_2 ) ;
F_72 ( & V_2 -> V_531 , & V_118 -> V_281 ) ;
F_293 ( V_64 -> V_37 , type ) ;
return 0 ;
}
static void F_560 ( struct V_12 * V_37 , T_2 V_7 )
{
T_2 V_367 = F_294 ( V_7 ) &
V_368 ;
F_295 ( & V_37 -> V_369 ) ;
if ( V_7 & V_339 )
V_37 -> V_370 &= ~ V_367 ;
if ( V_7 & V_54 )
V_37 -> V_371 &= ~ V_367 ;
if ( V_7 & V_340 )
V_37 -> V_372 &= ~ V_367 ;
F_296 ( & V_37 -> V_369 ) ;
}
int F_561 ( struct V_117 * V_118 ,
struct V_34 * V_35 , T_2 V_723 ,
struct V_724 * V_725 )
{
struct V_65 * V_66 ;
struct V_1 * V_14 ;
struct V_543 * V_551 ;
struct V_34 * V_88 = V_35 -> V_37 -> V_88 ;
struct V_69 V_21 ;
struct V_298 * V_298 ;
struct V_705 * V_363 = NULL ;
int V_29 ;
int V_592 ;
int V_342 ;
struct V_49 * V_52 = NULL ;
bool V_726 ;
V_35 = V_35 -> V_37 -> V_64 ;
V_14 = F_76 ( V_35 -> V_37 , V_723 ) ;
F_32 ( ! V_14 ) ;
F_32 ( ! V_14 -> V_307 ) ;
F_19 ( V_35 , V_14 ) ;
memcpy ( & V_21 , & V_14 -> V_21 , sizeof( V_21 ) ) ;
V_592 = F_431 ( V_14 ) ;
if ( V_14 -> V_7 & ( V_343 |
V_344 |
V_345 ) )
V_342 = 2 ;
else
V_342 = 1 ;
V_551 = & V_35 -> V_37 -> V_549 ;
F_11 ( & V_551 -> V_586 ) ;
F_442 ( V_14 , V_551 ) ;
F_13 ( & V_551 -> V_586 ) ;
V_551 = & V_35 -> V_37 -> V_547 ;
F_11 ( & V_551 -> V_586 ) ;
F_442 ( V_14 , V_551 ) ;
F_13 ( & V_551 -> V_586 ) ;
V_66 = F_34 () ;
if ( ! V_66 ) {
V_29 = - V_74 ;
goto V_81;
}
V_298 = F_255 ( V_88 , V_14 , V_66 ) ;
F_49 ( & V_118 -> V_135 -> V_329 ) ;
F_11 ( & V_118 -> V_135 -> V_328 ) ;
if ( ! F_182 ( & V_14 -> V_331 ) ) {
F_274 ( & V_14 -> V_331 ) ;
F_8 ( ! F_215 ( V_298 ) && V_298 != V_14 -> V_332 . V_298 ) ;
F_13 ( & V_118 -> V_135 -> V_328 ) ;
F_275 ( V_35 , V_118 , V_14 ,
& V_14 -> V_332 , V_66 ,
V_14 -> V_21 . V_22 ) ;
F_6 ( V_14 ) ;
F_11 ( & V_118 -> V_135 -> V_328 ) ;
}
if ( ! F_182 ( & V_14 -> V_330 ) ) {
F_274 ( & V_14 -> V_330 ) ;
F_6 ( V_14 ) ;
}
F_13 ( & V_118 -> V_135 -> V_328 ) ;
F_47 ( & V_118 -> V_135 -> V_329 ) ;
if ( ! F_215 ( V_298 ) ) {
V_29 = F_562 ( V_118 , V_298 ) ;
if ( V_29 ) {
F_563 ( V_298 ) ;
goto V_81;
}
F_564 ( V_298 ) ;
F_11 ( & V_14 -> V_51 ) ;
if ( V_14 -> V_173 ) {
V_14 -> V_173 = 0 ;
V_14 -> V_298 = NULL ;
F_13 ( & V_14 -> V_51 ) ;
F_267 ( V_298 ) ;
} else {
F_13 ( & V_14 -> V_51 ) ;
}
F_563 ( V_298 ) ;
}
V_21 . V_22 = V_727 ;
V_21 . V_33 = V_14 -> V_21 . V_22 ;
V_21 . type = 0 ;
V_29 = F_38 ( V_118 , V_88 , & V_21 , V_66 , - 1 , 1 ) ;
if ( V_29 < 0 )
goto V_81;
if ( V_29 > 0 )
F_45 ( V_66 ) ;
if ( V_29 == 0 ) {
V_29 = F_124 ( V_118 , V_88 , V_66 ) ;
if ( V_29 )
goto V_81;
F_45 ( V_66 ) ;
}
F_11 ( & V_35 -> V_37 -> V_18 ) ;
F_194 ( & V_14 -> V_20 ,
& V_35 -> V_37 -> V_19 ) ;
F_534 ( & V_14 -> V_20 ) ;
if ( V_35 -> V_37 -> V_26 == V_14 -> V_21 . V_22 )
V_35 -> V_37 -> V_26 = ( T_2 ) - 1 ;
F_13 ( & V_35 -> V_37 -> V_18 ) ;
F_71 ( & V_14 -> V_95 -> V_352 ) ;
F_274 ( & V_14 -> V_99 ) ;
if ( F_182 ( & V_14 -> V_95 -> V_351 [ V_592 ] ) ) {
V_363 = V_14 -> V_95 -> V_706 [ V_592 ] ;
V_14 -> V_95 -> V_706 [ V_592 ] = NULL ;
F_560 ( V_35 -> V_37 , V_14 -> V_7 ) ;
}
F_73 ( & V_14 -> V_95 -> V_352 ) ;
if ( V_363 ) {
F_537 ( V_363 ) ;
F_538 ( V_363 ) ;
}
if ( V_14 -> V_108 )
V_52 = F_25 ( V_14 ) ;
if ( V_14 -> V_3 == V_107 )
F_429 ( V_14 ) ;
if ( V_14 -> V_108 ) {
F_71 ( & V_35 -> V_37 -> V_84 ) ;
if ( ! V_52 ) {
struct V_49 * V_50 ;
F_183 (ctl,
&root->fs_info->caching_block_groups, list)
if ( V_50 -> V_14 == V_14 ) {
V_52 = V_50 ;
F_5 ( & V_52 -> V_8 ) ;
break;
}
}
if ( V_52 )
F_274 ( & V_52 -> V_99 ) ;
F_73 ( & V_35 -> V_37 -> V_84 ) ;
if ( V_52 ) {
F_26 ( V_52 ) ;
F_26 ( V_52 ) ;
}
}
F_11 ( & V_118 -> V_135 -> V_328 ) ;
if ( ! F_182 ( & V_14 -> V_330 ) ) {
F_8 ( 1 ) ;
}
if ( ! F_182 ( & V_14 -> V_331 ) ) {
F_8 ( 1 ) ;
}
F_13 ( & V_118 -> V_135 -> V_328 ) ;
F_535 ( V_14 ) ;
F_11 ( & V_14 -> V_95 -> V_51 ) ;
F_274 ( & V_14 -> V_691 ) ;
if ( F_262 ( V_35 , V_420 ) ) {
F_8 ( V_14 -> V_95 -> V_341
< V_14 -> V_21 . V_33 ) ;
F_8 ( V_14 -> V_95 -> V_355
< V_14 -> V_21 . V_33 ) ;
F_8 ( V_14 -> V_95 -> V_346
< V_14 -> V_21 . V_33 * V_342 ) ;
}
V_14 -> V_95 -> V_341 -= V_14 -> V_21 . V_33 ;
V_14 -> V_95 -> V_355 -= V_14 -> V_21 . V_33 ;
V_14 -> V_95 -> V_346 -= V_14 -> V_21 . V_33 * V_342 ;
F_13 ( & V_14 -> V_95 -> V_51 ) ;
memcpy ( & V_21 , & V_14 -> V_21 , sizeof( V_21 ) ) ;
F_524 ( V_35 ) ;
if ( ! F_182 ( & V_725 -> V_99 ) ) {
F_565 ( V_725 ) ;
}
F_11 ( & V_14 -> V_51 ) ;
V_14 -> V_728 = 1 ;
V_726 = ( F_211 ( & V_14 -> V_713 ) == 0 ) ;
if ( ! V_726 ) {
F_566 ( & V_725 -> V_99 , & V_35 -> V_37 -> V_729 ) ;
}
F_13 ( & V_14 -> V_51 ) ;
if ( V_726 ) {
struct V_730 * V_731 ;
V_731 = & V_35 -> V_37 -> V_47 . V_732 ;
F_567 ( & V_731 -> V_51 ) ;
F_568 ( V_731 , V_725 ) ;
F_569 ( & V_731 -> V_51 ) ;
F_565 ( V_725 ) ;
}
F_525 ( V_35 ) ;
V_29 = F_570 ( V_118 , V_35 -> V_37 , V_14 ) ;
if ( V_29 )
goto V_81;
F_6 ( V_14 ) ;
F_6 ( V_14 ) ;
V_29 = F_38 ( V_118 , V_35 , & V_21 , V_66 , - 1 , 1 ) ;
if ( V_29 > 0 )
V_29 = - V_184 ;
if ( V_29 < 0 )
goto V_81;
V_29 = F_124 ( V_118 , V_35 , V_66 ) ;
V_81:
F_53 ( V_66 ) ;
return V_29 ;
}
struct V_117 *
F_571 ( struct V_12 * V_37 ,
const T_2 V_720 )
{
struct V_730 * V_731 = & V_37 -> V_47 . V_732 ;
struct V_724 * V_725 ;
struct V_733 * V_734 ;
unsigned int V_735 ;
F_572 ( & V_731 -> V_51 ) ;
V_725 = F_573 ( V_731 , V_720 , 1 ) ;
F_574 ( & V_731 -> V_51 ) ;
ASSERT ( V_725 && V_725 -> V_32 == V_720 ) ;
V_734 = V_725 -> V_733 ;
V_735 = 3 + V_734 -> V_211 ;
F_565 ( V_725 ) ;
return F_575 ( V_37 -> V_64 ,
V_735 , 1 ) ;
}
void F_576 ( struct V_12 * V_37 )
{
struct V_1 * V_14 ;
struct V_111 * V_95 ;
struct V_34 * V_35 = V_37 -> V_64 ;
struct V_117 * V_118 ;
int V_29 = 0 ;
if ( ! V_37 -> V_736 )
return;
F_11 ( & V_37 -> V_530 ) ;
while ( ! F_182 ( & V_37 -> V_532 ) ) {
T_2 V_32 , V_31 ;
int V_713 ;
V_14 = F_273 ( & V_37 -> V_532 ,
struct V_1 ,
V_531 ) ;
F_274 ( & V_14 -> V_531 ) ;
V_95 = V_14 -> V_95 ;
if ( V_29 || F_330 ( V_95 ) ) {
F_6 ( V_14 ) ;
continue;
}
F_13 ( & V_37 -> V_530 ) ;
F_49 ( & V_37 -> V_737 ) ;
F_71 ( & V_95 -> V_352 ) ;
F_11 ( & V_14 -> V_51 ) ;
if ( V_14 -> V_10 ||
F_58 ( & V_14 -> V_96 ) ||
V_14 -> V_307 ||
F_577 ( & V_14 -> V_99 ) ) {
F_13 ( & V_14 -> V_51 ) ;
F_73 ( & V_95 -> V_352 ) ;
goto V_80;
}
F_13 ( & V_14 -> V_51 ) ;
V_29 = F_521 ( V_14 , 0 ) ;
F_73 ( & V_95 -> V_352 ) ;
if ( V_29 < 0 ) {
V_29 = 0 ;
goto V_80;
}
V_118 = F_571 ( V_37 ,
V_14 -> V_21 . V_22 ) ;
if ( F_215 ( V_118 ) ) {
F_528 ( V_35 , V_14 ) ;
V_29 = F_216 ( V_118 ) ;
goto V_80;
}
V_32 = V_14 -> V_21 . V_22 ;
V_31 = V_32 + V_14 -> V_21 . V_33 - 1 ;
F_49 ( & V_37 -> V_557 ) ;
V_29 = F_20 ( & V_37 -> V_38 [ 0 ] , V_32 , V_31 ,
V_63 ) ;
if ( V_29 ) {
F_47 ( & V_37 -> V_557 ) ;
F_528 ( V_35 , V_14 ) ;
goto V_738;
}
V_29 = F_20 ( & V_37 -> V_38 [ 1 ] , V_32 , V_31 ,
V_63 ) ;
if ( V_29 ) {
F_47 ( & V_37 -> V_557 ) ;
F_528 ( V_35 , V_14 ) ;
goto V_738;
}
F_47 ( & V_37 -> V_557 ) ;
F_11 ( & V_95 -> V_51 ) ;
F_11 ( & V_14 -> V_51 ) ;
V_95 -> V_353 -= V_14 -> V_9 ;
V_95 -> V_355 += V_14 -> V_9 ;
F_411 ( & V_95 -> V_348 ,
- V_14 -> V_9 ) ;
V_14 -> V_9 = 0 ;
F_13 ( & V_14 -> V_51 ) ;
F_13 ( & V_95 -> V_51 ) ;
V_713 = F_262 ( V_35 , V_558 ) ;
if ( V_713 )
F_578 ( V_14 ) ;
V_29 = F_579 ( V_118 , V_35 ,
V_14 -> V_21 . V_22 ) ;
if ( V_29 ) {
if ( V_713 )
F_414 ( V_14 ) ;
goto V_738;
}
if ( V_713 ) {
F_11 ( & V_37 -> V_530 ) ;
F_580 ( & V_14 -> V_531 ,
& V_118 -> V_135 -> V_554 ) ;
F_13 ( & V_37 -> V_530 ) ;
F_4 ( V_14 ) ;
}
V_738:
F_218 ( V_118 , V_35 ) ;
V_80:
F_47 ( & V_37 -> V_737 ) ;
F_6 ( V_14 ) ;
F_11 ( & V_37 -> V_530 ) ;
}
F_13 ( & V_37 -> V_530 ) ;
}
int F_581 ( struct V_12 * V_37 )
{
struct V_111 * V_95 ;
struct V_739 * V_740 ;
T_2 V_741 ;
T_2 V_7 ;
int V_742 = 0 ;
int V_29 ;
V_740 = V_37 -> V_261 ;
if ( ! F_582 ( V_740 ) )
return - V_534 ;
V_741 = F_583 ( V_740 ) ;
if ( V_741 & V_743 )
V_742 = 1 ;
V_7 = V_340 ;
V_29 = F_287 ( V_37 , V_7 , 0 , 0 , & V_95 ) ;
if ( V_29 )
goto V_81;
if ( V_742 ) {
V_7 = V_54 | V_339 ;
V_29 = F_287 ( V_37 , V_7 , 0 , 0 , & V_95 ) ;
} else {
V_7 = V_54 ;
V_29 = F_287 ( V_37 , V_7 , 0 , 0 , & V_95 ) ;
if ( V_29 )
goto V_81;
V_7 = V_339 ;
V_29 = F_287 ( V_37 , V_7 , 0 , 0 , & V_95 ) ;
}
V_81:
return V_29 ;
}
int F_584 ( struct V_34 * V_35 , T_2 V_32 , T_2 V_31 )
{
return F_410 ( V_35 , V_32 , V_31 , false ) ;
}
static int F_585 ( struct V_697 * V_698 ,
T_2 V_744 , T_2 * V_559 )
{
T_2 V_32 = 0 , V_48 = 0 ;
int V_29 ;
* V_559 = 0 ;
if ( ! V_698 -> V_745 )
return 0 ;
if ( V_698 -> V_341 <= V_698 -> V_94 )
return 0 ;
V_29 = 0 ;
while ( 1 ) {
struct V_12 * V_37 = V_698 -> V_500 -> V_37 ;
struct V_318 * V_118 ;
T_2 V_212 ;
V_29 = F_586 ( & V_37 -> V_419 ) ;
if ( V_29 )
return V_29 ;
F_50 ( & V_37 -> V_84 ) ;
F_11 ( & V_37 -> V_746 ) ;
V_118 = V_37 -> V_747 ;
if ( V_118 )
F_5 ( & V_118 -> V_748 ) ;
F_13 ( & V_37 -> V_746 ) ;
V_29 = F_587 ( V_118 , V_698 , V_744 , V_32 ,
& V_32 , & V_48 ) ;
if ( V_118 )
F_588 ( V_118 ) ;
if ( V_29 ) {
F_46 ( & V_37 -> V_84 ) ;
F_47 ( & V_37 -> V_419 ) ;
if ( V_29 == - V_314 )
V_29 = 0 ;
break;
}
V_29 = F_148 ( V_698 -> V_195 , V_32 , V_48 , & V_212 ) ;
F_46 ( & V_37 -> V_84 ) ;
F_47 ( & V_37 -> V_419 ) ;
if ( V_29 )
break;
V_32 += V_48 ;
* V_559 += V_212 ;
if ( F_589 ( V_399 ) ) {
V_29 = - V_749 ;
break;
}
F_48 () ;
}
return V_29 ;
}
int F_590 ( struct V_34 * V_35 , struct V_750 * V_751 )
{
struct V_12 * V_37 = V_35 -> V_37 ;
struct V_1 * V_2 = NULL ;
struct V_697 * V_698 ;
struct V_112 * V_752 ;
T_2 V_753 ;
T_2 V_32 ;
T_2 V_31 ;
T_2 V_559 = 0 ;
T_2 V_341 = F_319 ( V_37 -> V_261 ) ;
int V_29 = 0 ;
if ( V_751 -> V_48 == V_341 )
V_2 = F_75 ( V_37 , V_751 -> V_32 ) ;
else
V_2 = F_76 ( V_37 , V_751 -> V_32 ) ;
while ( V_2 ) {
if ( V_2 -> V_21 . V_22 >= ( V_751 -> V_32 + V_751 -> V_48 ) ) {
F_6 ( V_2 ) ;
break;
}
V_32 = F_439 ( V_751 -> V_32 , V_2 -> V_21 . V_22 ) ;
V_31 = F_339 ( V_751 -> V_32 + V_751 -> V_48 ,
V_2 -> V_21 . V_22 + V_2 -> V_21 . V_33 ) ;
if ( V_31 - V_32 >= V_751 -> V_744 ) {
if ( ! F_1 ( V_2 ) ) {
V_29 = F_59 ( V_2 , 0 ) ;
if ( V_29 ) {
F_6 ( V_2 ) ;
break;
}
V_29 = F_429 ( V_2 ) ;
if ( V_29 ) {
F_6 ( V_2 ) ;
break;
}
}
V_29 = F_591 ( V_2 ,
& V_753 ,
V_32 ,
V_31 ,
V_751 -> V_744 ) ;
V_559 += V_753 ;
if ( V_29 ) {
F_6 ( V_2 ) ;
break;
}
}
V_2 = F_252 ( V_37 -> V_88 , V_2 ) ;
}
F_49 ( & V_35 -> V_37 -> V_382 -> V_754 ) ;
V_752 = & V_35 -> V_37 -> V_382 -> V_755 ;
F_183 (device, devices, dev_alloc_list) {
V_29 = F_585 ( V_698 , V_751 -> V_744 ,
& V_753 ) ;
if ( V_29 )
break;
V_559 += V_753 ;
}
F_47 ( & V_35 -> V_37 -> V_382 -> V_754 ) ;
V_751 -> V_48 = V_559 ;
return V_29 ;
}
void F_592 ( struct V_34 * V_35 )
{
F_593 ( & V_35 -> V_756 -> V_757 ) ;
F_2 () ;
if ( F_594 ( & V_35 -> V_756 -> V_90 ) )
F_52 ( & V_35 -> V_756 -> V_90 ) ;
}
int F_595 ( struct V_34 * V_35 )
{
if ( F_211 ( & V_35 -> V_758 ) )
return 0 ;
F_596 ( & V_35 -> V_756 -> V_757 ) ;
F_2 () ;
if ( F_211 ( & V_35 -> V_758 ) ) {
F_592 ( V_35 ) ;
return 0 ;
}
return 1 ;
}
static int F_597 ( T_7 * V_338 )
{
F_68 () ;
return 0 ;
}
void F_598 ( struct V_34 * V_35 )
{
while ( true ) {
int V_29 ;
V_29 = F_595 ( V_35 ) ;
if ( V_29 )
break;
F_285 ( & V_35 -> V_758 ,
F_597 ,
V_102 ) ;
}
}
