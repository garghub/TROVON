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
F_162 ( V_118 , V_29 ) ;
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
F_165 ( V_35 -> V_37 , V_136 , V_158 , V_136 -> V_225 ) ;
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
F_172 ( V_35 -> V_37 , V_136 , V_158 , V_136 -> V_225 ) ;
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
F_178 ( V_35 -> V_37 , V_136 , V_113 ,
V_136 -> V_225 ) ;
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
V_257 = F_206 ( V_35 ) ;
V_258 = F_207 ( V_257 ,
( T_2 ) F_208 ( V_35 -> V_37 -> V_260 ) ) ;
V_259 = F_207 ( V_256 , V_35 -> V_56 ) ;
V_259 += V_258 - 1 ;
V_259 = F_207 ( V_259 , V_258 ) ;
return V_259 ;
}
int F_209 ( struct V_117 * V_118 ,
struct V_34 * V_35 )
{
struct V_261 * V_262 ;
T_2 V_240 = V_118 -> V_135 -> V_123 . V_238 ;
T_2 V_256 = V_118 -> V_135 -> V_123 . V_246 ;
T_2 V_263 = V_118 -> V_135 -> V_263 ;
T_2 V_36 , V_264 ;
int V_29 = 0 ;
V_36 = F_210 ( V_35 , 1 ) ;
V_240 = F_202 ( V_35 , V_240 ) ;
if ( V_240 > 1 )
V_36 += ( V_240 - 1 ) * V_35 -> V_55 ;
V_36 <<= 1 ;
V_36 += F_205 ( V_35 , V_256 ) * V_35 -> V_55 ;
V_264 = F_210 ( V_35 ,
V_263 ) ;
V_262 = & V_35 -> V_37 -> V_265 ;
if ( V_262 -> V_95 -> V_116 ) {
V_264 <<= 1 ;
V_36 <<= 1 ;
}
F_11 ( & V_262 -> V_51 ) ;
if ( V_262 -> V_10 <= V_36 + V_264 )
V_29 = 1 ;
F_13 ( & V_262 -> V_51 ) ;
return V_29 ;
}
int F_211 ( struct V_117 * V_118 ,
struct V_34 * V_35 )
{
struct V_12 * V_37 = V_35 -> V_37 ;
T_2 V_243 =
F_212 ( & V_118 -> V_135 -> V_123 . V_243 ) ;
T_2 V_266 ;
T_2 V_267 ;
F_2 () ;
V_266 = V_37 -> V_249 ;
V_267 = V_243 * V_266 ;
if ( V_243 * V_266 >= V_268 )
return 1 ;
if ( V_267 >= V_268 / 2 )
return 2 ;
return F_209 ( V_118 , V_35 ) ;
}
static void F_213 ( struct V_91 * V_92 )
{
struct V_269 * V_270 ;
struct V_117 * V_118 ;
int V_29 ;
V_270 = F_55 ( V_92 , struct V_269 , V_92 ) ;
if ( F_214 ( V_270 -> V_35 -> V_37 ) )
goto V_271;
V_118 = F_215 ( V_270 -> V_35 ) ;
if ( F_216 ( V_118 ) ) {
V_270 -> error = F_217 ( V_118 ) ;
goto V_271;
}
V_118 -> V_272 = true ;
if ( V_118 -> V_273 > V_270 -> V_273 )
goto V_31;
V_29 = F_218 ( V_118 , V_270 -> V_35 , V_270 -> V_8 ) ;
if ( V_29 )
V_270 -> error = V_29 ;
V_31:
V_29 = F_219 ( V_118 , V_270 -> V_35 ) ;
if ( V_29 && ! V_270 -> error )
V_270 -> error = V_29 ;
V_271:
if ( V_270 -> V_272 )
F_220 ( & V_270 -> V_90 ) ;
else
F_9 ( V_270 ) ;
}
int F_221 ( struct V_34 * V_35 ,
unsigned long V_8 , T_2 V_273 , int V_90 )
{
struct V_269 * V_270 ;
int V_29 ;
V_270 = F_222 ( sizeof( * V_270 ) , V_98 ) ;
if ( ! V_270 )
return - V_74 ;
V_270 -> V_35 = V_35 -> V_37 -> V_88 ;
V_270 -> V_8 = V_8 ;
V_270 -> error = 0 ;
V_270 -> V_273 = V_273 ;
if ( V_90 )
V_270 -> V_272 = 1 ;
else
V_270 -> V_272 = 0 ;
F_223 ( & V_270 -> V_90 ) ;
F_66 ( & V_270 -> V_92 , V_274 ,
F_213 , NULL , NULL ) ;
F_74 ( V_35 -> V_37 -> V_275 , & V_270 -> V_92 ) ;
if ( V_90 ) {
F_224 ( & V_270 -> V_90 ) ;
V_29 = V_270 -> error ;
F_9 ( V_270 ) ;
return V_29 ;
}
return 0 ;
}
int F_218 ( struct V_117 * V_118 ,
struct V_34 * V_35 , unsigned long V_8 )
{
struct V_15 * V_136 ;
struct V_122 * V_123 ;
struct V_121 * V_113 ;
int V_29 ;
int V_276 = V_8 == ( unsigned long ) - 1 ;
bool V_277 = V_118 -> V_277 ;
if ( V_118 -> V_228 )
return 0 ;
if ( V_35 -> V_37 -> V_278 )
return 0 ;
if ( V_35 == V_35 -> V_37 -> V_64 )
V_35 = V_35 -> V_37 -> V_88 ;
V_123 = & V_118 -> V_135 -> V_123 ;
if ( V_8 == 0 )
V_8 = F_212 ( & V_123 -> V_243 ) * 2 ;
V_164:
#ifdef F_225
V_123 -> V_279 = F_199 ( & V_123 -> V_35 ) ;
#endif
V_118 -> V_277 = false ;
V_29 = F_185 ( V_118 , V_35 , V_8 ) ;
if ( V_29 < 0 ) {
F_162 ( V_118 , V_29 ) ;
return V_29 ;
}
if ( V_276 ) {
if ( ! F_182 ( & V_118 -> V_280 ) )
F_226 ( V_118 , V_35 ) ;
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
V_136 = F_227 ( V_136 ) ;
}
F_13 ( & V_123 -> V_51 ) ;
F_48 () ;
goto V_164;
}
V_81:
F_228 ( V_118 ) ;
V_118 -> V_277 = V_277 ;
return 0 ;
}
int F_229 ( struct V_117 * V_118 ,
struct V_34 * V_35 ,
T_2 V_27 , T_2 V_36 , T_2 V_7 ,
int V_176 , int V_193 )
{
struct V_189 * V_137 ;
int V_29 ;
V_137 = F_230 () ;
if ( ! V_137 )
return - V_74 ;
V_137 -> V_139 = V_7 ;
V_137 -> V_138 = true ;
V_137 -> V_227 = false ;
V_137 -> V_193 = V_193 ? true : false ;
V_137 -> V_176 = V_176 ;
V_29 = F_231 ( V_35 -> V_37 , V_118 , V_27 ,
V_36 , V_137 ) ;
if ( V_29 )
F_192 ( V_137 ) ;
return V_29 ;
}
static T_1 int F_232 ( struct V_117 * V_118 ,
struct V_34 * V_35 ,
struct V_65 * V_66 ,
T_2 V_22 , T_2 V_33 , T_2 V_27 )
{
struct V_121 * V_113 ;
struct V_219 * V_158 ;
struct V_222 * V_281 ;
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
V_281 = F_164 ( V_158 ) ;
if ( V_281 -> V_35 != V_35 -> V_282 . V_22 ||
V_281 -> V_22 != V_22 ||
V_281 -> V_33 != V_33 ) {
V_29 = 1 ;
break;
}
}
F_13 ( & V_113 -> V_51 ) ;
F_47 ( & V_113 -> V_86 ) ;
return V_29 ;
}
static T_1 int F_233 ( struct V_117 * V_118 ,
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
if ( F_234 ( V_68 , V_125 ) <=
F_235 ( & V_35 -> V_283 ) )
goto V_81;
V_173 = (struct V_172 * ) ( V_125 + 1 ) ;
if ( F_127 ( V_68 , V_173 ) !=
V_163 )
goto V_81;
V_158 = (struct V_157 * ) ( & V_173 -> V_33 ) ;
if ( F_87 ( V_68 , V_125 ) !=
F_121 ( V_68 , V_158 ) ||
F_108 ( V_68 , V_158 ) !=
V_35 -> V_282 . V_22 ||
F_109 ( V_68 , V_158 ) != V_22 ||
F_110 ( V_68 , V_158 ) != V_33 )
goto V_81;
V_29 = 0 ;
V_81:
return V_29 ;
}
int F_236 ( struct V_117 * V_118 ,
struct V_34 * V_35 ,
T_2 V_22 , T_2 V_33 , T_2 V_27 )
{
struct V_65 * V_66 ;
int V_29 ;
int V_284 ;
V_66 = F_34 () ;
if ( ! V_66 )
return - V_161 ;
do {
V_29 = F_233 ( V_118 , V_35 , V_66 , V_22 ,
V_33 , V_27 ) ;
if ( V_29 && V_29 != - V_161 )
goto V_81;
V_284 = F_232 ( V_118 , V_35 , V_66 , V_22 ,
V_33 , V_27 ) ;
} while ( V_284 == - V_187 );
if ( V_284 && V_284 != - V_161 ) {
V_29 = V_284 ;
goto V_81;
}
if ( V_29 != - V_161 || V_284 != - V_161 )
V_29 = 0 ;
V_81:
F_53 ( V_66 ) ;
if ( V_35 -> V_282 . V_22 == V_285 )
F_8 ( V_29 > 0 ) ;
return V_29 ;
}
static int F_237 ( struct V_117 * V_118 ,
struct V_34 * V_35 ,
struct V_67 * V_286 ,
int V_287 , int V_288 )
{
T_2 V_27 ;
T_2 V_36 ;
T_2 V_17 ;
T_2 V_224 ;
T_3 V_72 ;
struct V_69 V_21 ;
struct V_289 * V_290 ;
int V_42 ;
int V_176 ;
int V_29 = 0 ;
int (* F_238)( struct V_117 * , struct V_34 * ,
T_2 , T_2 , T_2 , T_2 , T_2 , T_2 );
if ( F_239 ( V_35 -> V_37 ) )
return 0 ;
V_224 = F_240 ( V_286 ) ;
V_72 = F_39 ( V_286 ) ;
V_176 = F_241 ( V_286 ) ;
if ( ! F_242 ( V_291 , & V_35 -> V_292 ) && V_176 == 0 )
return 0 ;
if ( V_288 )
F_238 = F_158 ;
else
F_238 = V_293 ;
if ( V_287 )
V_17 = V_286 -> V_32 ;
else
V_17 = 0 ;
for ( V_42 = 0 ; V_42 < V_72 ; V_42 ++ ) {
if ( V_176 == 0 ) {
F_41 ( V_286 , & V_21 , V_42 ) ;
if ( V_21 . type != V_294 )
continue;
V_290 = F_86 ( V_286 , V_42 ,
struct V_289 ) ;
if ( F_243 ( V_286 , V_290 ) ==
V_295 )
continue;
V_27 = F_244 ( V_286 , V_290 ) ;
if ( V_27 == 0 )
continue;
V_36 = F_245 ( V_286 , V_290 ) ;
V_21 . V_33 -= F_246 ( V_286 , V_290 ) ;
V_29 = F_238 ( V_118 , V_35 , V_27 , V_36 ,
V_17 , V_224 , V_21 . V_22 ,
V_21 . V_33 ) ;
if ( V_29 )
goto V_165;
} else {
V_27 = F_247 ( V_286 , V_42 ) ;
V_36 = V_35 -> V_55 ;
V_29 = F_238 ( V_118 , V_35 , V_27 , V_36 ,
V_17 , V_224 , V_176 - 1 , 0 ) ;
if ( V_29 )
goto V_165;
}
}
return 0 ;
V_165:
return V_29 ;
}
int F_248 ( struct V_117 * V_118 , struct V_34 * V_35 ,
struct V_67 * V_286 , int V_287 )
{
return F_237 ( V_118 , V_35 , V_286 , V_287 , 1 ) ;
}
int F_249 ( struct V_117 * V_118 , struct V_34 * V_35 ,
struct V_67 * V_286 , int V_287 )
{
return F_237 ( V_118 , V_35 , V_286 , V_287 , 0 ) ;
}
static int F_250 ( struct V_117 * V_118 ,
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
V_146 = F_251 ( V_68 , V_66 -> V_83 [ 0 ] ) ;
F_252 ( V_68 , & V_2 -> V_96 , V_146 , sizeof( V_2 -> V_96 ) ) ;
F_103 ( V_68 ) ;
V_165:
F_45 ( V_66 ) ;
return V_29 ;
}
static struct V_1 *
F_253 ( struct V_34 * V_35 ,
struct V_1 * V_2 )
{
struct V_15 * V_136 ;
F_11 ( & V_35 -> V_37 -> V_18 ) ;
if ( F_254 ( & V_2 -> V_20 ) ) {
const T_2 V_296 = V_2 -> V_21 . V_22 + V_2 -> V_21 . V_33 ;
F_13 ( & V_35 -> V_37 -> V_18 ) ;
F_6 ( V_2 ) ;
V_2 = F_75 ( V_35 -> V_37 ,
V_296 ) ;
return V_2 ;
}
V_136 = F_227 ( & V_2 -> V_20 ) ;
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
static int F_255 ( struct V_1 * V_14 ,
struct V_117 * V_118 ,
struct V_65 * V_66 )
{
struct V_34 * V_35 = V_14 -> V_37 -> V_88 ;
struct V_297 * V_297 = NULL ;
T_2 V_298 = 0 ;
int V_299 = V_300 ;
T_2 V_301 = 0 ;
int V_302 = 0 ;
int V_29 = 0 ;
if ( V_14 -> V_21 . V_33 < ( 100 * V_303 ) ) {
F_11 ( & V_14 -> V_51 ) ;
V_14 -> V_304 = V_305 ;
F_13 ( & V_14 -> V_51 ) ;
return 0 ;
}
if ( V_118 -> V_228 )
return 0 ;
V_164:
V_297 = F_256 ( V_35 , V_14 , V_66 ) ;
if ( F_216 ( V_297 ) && F_217 ( V_297 ) != - V_161 ) {
V_29 = F_217 ( V_297 ) ;
F_45 ( V_66 ) ;
goto V_81;
}
if ( F_216 ( V_297 ) ) {
F_32 ( V_302 ) ;
V_302 ++ ;
if ( V_14 -> V_306 )
goto V_131;
V_29 = F_257 ( V_35 , V_118 , V_14 , V_66 ) ;
if ( V_29 )
goto V_131;
goto V_164;
}
if ( V_14 -> V_307 == V_118 -> V_273 &&
F_258 ( V_297 ) ) {
V_299 = V_308 ;
goto V_309;
}
F_259 ( V_297 ) -> V_310 = 0 ;
V_29 = F_260 ( V_118 , V_35 , V_297 ) ;
if ( V_29 ) {
F_162 ( V_118 , V_29 ) ;
goto V_309;
}
F_8 ( V_29 ) ;
if ( F_258 ( V_297 ) > 0 ) {
V_29 = F_261 ( V_35 ,
& V_35 -> V_37 -> V_265 ) ;
if ( V_29 )
goto V_309;
V_29 = F_262 ( V_35 , V_118 , NULL , V_297 ) ;
if ( V_29 )
goto V_309;
}
F_11 ( & V_14 -> V_51 ) ;
if ( V_14 -> V_3 != V_4 ||
! F_263 ( V_35 -> V_37 , V_311 ) ) {
V_299 = V_305 ;
F_13 ( & V_14 -> V_51 ) ;
goto V_309;
}
F_13 ( & V_14 -> V_51 ) ;
if ( F_242 ( V_312 , & V_118 -> V_135 -> V_7 ) ) {
V_29 = - V_313 ;
goto V_309;
}
V_301 = F_203 ( V_14 -> V_21 . V_33 , V_314 ) ;
if ( ! V_301 )
V_301 = 1 ;
V_301 *= 16 ;
V_301 *= V_315 ;
V_29 = F_264 ( V_297 , 0 , V_301 ) ;
if ( V_29 )
goto V_309;
V_29 = F_265 ( V_297 , V_118 , 0 , 0 , V_301 ,
V_301 , V_301 ,
& V_298 ) ;
if ( ! V_29 )
V_299 = V_308 ;
else if ( V_29 == - V_313 )
F_266 ( V_312 , & V_118 -> V_135 -> V_7 ) ;
V_309:
F_267 ( V_297 ) ;
V_131:
F_45 ( V_66 ) ;
V_81:
F_11 ( & V_14 -> V_51 ) ;
if ( ! V_29 && V_299 == V_308 )
V_14 -> V_307 = V_118 -> V_273 ;
V_14 -> V_304 = V_299 ;
F_13 ( & V_14 -> V_51 ) ;
return V_29 ;
}
int F_268 ( struct V_117 * V_118 ,
struct V_34 * V_35 )
{
struct V_1 * V_2 , * V_316 ;
struct V_317 * V_318 = V_118 -> V_135 ;
struct V_65 * V_66 ;
if ( F_182 ( & V_318 -> V_319 ) ||
! F_263 ( V_35 -> V_37 , V_311 ) )
return 0 ;
V_66 = F_34 () ;
if ( ! V_66 )
return - V_74 ;
F_269 (cache, tmp, &cur_trans->dirty_bgs,
dirty_list) {
if ( V_2 -> V_304 == V_320 )
F_255 ( V_2 , V_118 , V_66 ) ;
}
F_53 ( V_66 ) ;
return 0 ;
}
int F_270 ( struct V_117 * V_118 ,
struct V_34 * V_35 )
{
struct V_1 * V_2 ;
struct V_317 * V_318 = V_118 -> V_135 ;
int V_29 = 0 ;
int V_321 ;
struct V_65 * V_66 = NULL ;
F_271 ( V_322 ) ;
struct V_112 * V_323 = & V_318 -> V_324 ;
int V_325 = 0 ;
int V_326 = 0 ;
F_11 ( & V_318 -> V_327 ) ;
if ( F_182 ( & V_318 -> V_319 ) ) {
F_13 ( & V_318 -> V_327 ) ;
return 0 ;
}
F_272 ( & V_318 -> V_319 , & V_322 ) ;
F_13 ( & V_318 -> V_327 ) ;
V_164:
F_226 ( V_118 , V_35 ) ;
if ( ! V_66 ) {
V_66 = F_34 () ;
if ( ! V_66 )
return - V_74 ;
}
F_49 ( & V_118 -> V_135 -> V_328 ) ;
while ( ! F_182 ( & V_322 ) ) {
V_2 = F_273 ( & V_322 ,
struct V_1 ,
V_329 ) ;
if ( ! F_182 ( & V_2 -> V_330 ) ) {
F_274 ( & V_2 -> V_330 ) ;
F_275 ( V_35 , V_118 , V_2 ,
& V_2 -> V_331 , V_66 ,
V_2 -> V_21 . V_22 ) ;
F_6 ( V_2 ) ;
}
F_11 ( & V_318 -> V_327 ) ;
F_274 ( & V_2 -> V_329 ) ;
F_13 ( & V_318 -> V_327 ) ;
V_321 = 1 ;
F_255 ( V_2 , V_118 , V_66 ) ;
if ( V_2 -> V_304 == V_308 ) {
V_2 -> V_331 . V_297 = NULL ;
V_29 = F_276 ( V_35 , V_118 , V_2 , V_66 ) ;
if ( V_29 == 0 && V_2 -> V_331 . V_297 ) {
V_325 ++ ;
V_321 = 0 ;
F_72 ( & V_2 -> V_330 , V_323 ) ;
} else {
V_29 = 0 ;
}
}
if ( ! V_29 ) {
V_29 = F_250 ( V_118 , V_35 , V_66 , V_2 ) ;
if ( V_29 == - V_161 ) {
V_29 = 0 ;
F_11 ( & V_318 -> V_327 ) ;
if ( F_182 ( & V_2 -> V_329 ) ) {
F_72 ( & V_2 -> V_329 ,
& V_318 -> V_319 ) ;
F_4 ( V_2 ) ;
}
F_13 ( & V_318 -> V_327 ) ;
} else if ( V_29 ) {
F_162 ( V_118 , V_29 ) ;
}
}
if ( V_321 )
F_6 ( V_2 ) ;
if ( V_29 )
break;
F_47 ( & V_118 -> V_135 -> V_328 ) ;
F_49 ( & V_118 -> V_135 -> V_328 ) ;
}
F_47 ( & V_118 -> V_135 -> V_328 ) ;
V_29 = F_218 ( V_118 , V_35 , 0 ) ;
if ( ! V_29 && V_326 == 0 ) {
V_326 ++ ;
F_11 ( & V_318 -> V_327 ) ;
F_272 ( & V_318 -> V_319 , & V_322 ) ;
if ( ! F_182 ( & V_322 ) ) {
F_13 ( & V_318 -> V_327 ) ;
goto V_164;
}
F_13 ( & V_318 -> V_327 ) ;
}
F_53 ( V_66 ) ;
return V_29 ;
}
int F_277 ( struct V_117 * V_118 ,
struct V_34 * V_35 )
{
struct V_1 * V_2 ;
struct V_317 * V_318 = V_118 -> V_135 ;
int V_29 = 0 ;
int V_321 ;
struct V_65 * V_66 ;
struct V_112 * V_323 = & V_318 -> V_324 ;
int V_325 = 0 ;
V_66 = F_34 () ;
if ( ! V_66 )
return - V_74 ;
F_11 ( & V_318 -> V_327 ) ;
while ( ! F_182 ( & V_318 -> V_319 ) ) {
V_2 = F_273 ( & V_318 -> V_319 ,
struct V_1 ,
V_329 ) ;
if ( ! F_182 ( & V_2 -> V_330 ) ) {
F_13 ( & V_318 -> V_327 ) ;
F_274 ( & V_2 -> V_330 ) ;
F_275 ( V_35 , V_118 , V_2 ,
& V_2 -> V_331 , V_66 ,
V_2 -> V_21 . V_22 ) ;
F_6 ( V_2 ) ;
F_11 ( & V_318 -> V_327 ) ;
}
F_274 ( & V_2 -> V_329 ) ;
F_13 ( & V_318 -> V_327 ) ;
V_321 = 1 ;
F_255 ( V_2 , V_118 , V_66 ) ;
if ( ! V_29 )
V_29 = F_218 ( V_118 , V_35 , ( unsigned long ) - 1 ) ;
if ( ! V_29 && V_2 -> V_304 == V_308 ) {
V_2 -> V_331 . V_297 = NULL ;
V_29 = F_276 ( V_35 , V_118 , V_2 , V_66 ) ;
if ( V_29 == 0 && V_2 -> V_331 . V_297 ) {
V_325 ++ ;
V_321 = 0 ;
F_72 ( & V_2 -> V_330 , V_323 ) ;
} else {
V_29 = 0 ;
}
}
if ( ! V_29 ) {
V_29 = F_250 ( V_118 , V_35 , V_66 , V_2 ) ;
if ( V_29 == - V_161 ) {
F_278 ( V_318 -> V_332 ,
F_212 ( & V_318 -> V_333 ) == 1 ) ;
V_29 = F_250 ( V_118 , V_35 , V_66 ,
V_2 ) ;
}
if ( V_29 )
F_162 ( V_118 , V_29 ) ;
}
if ( V_321 )
F_6 ( V_2 ) ;
F_11 ( & V_318 -> V_327 ) ;
}
F_13 ( & V_318 -> V_327 ) ;
while ( ! F_182 ( V_323 ) ) {
V_2 = F_273 ( V_323 , struct V_1 ,
V_330 ) ;
F_274 ( & V_2 -> V_330 ) ;
F_275 ( V_35 , V_118 , V_2 ,
& V_2 -> V_331 , V_66 , V_2 -> V_21 . V_22 ) ;
F_6 ( V_2 ) ;
}
F_53 ( V_66 ) ;
return V_29 ;
}
int F_279 ( struct V_34 * V_35 , T_2 V_27 )
{
struct V_1 * V_14 ;
int V_334 = 0 ;
V_14 = F_76 ( V_35 -> V_37 , V_27 ) ;
if ( ! V_14 || V_14 -> V_306 )
V_334 = 1 ;
if ( V_14 )
F_6 ( V_14 ) ;
return V_334 ;
}
bool F_280 ( struct V_12 * V_37 , T_2 V_27 )
{
struct V_1 * V_335 ;
bool V_29 = true ;
V_335 = F_76 ( V_37 , V_27 ) ;
if ( ! V_335 )
return false ;
F_11 ( & V_335 -> V_51 ) ;
if ( V_335 -> V_306 )
V_29 = false ;
else
F_5 ( & V_335 -> V_336 ) ;
F_13 ( & V_335 -> V_51 ) ;
if ( ! V_29 )
F_6 ( V_335 ) ;
return V_29 ;
}
void F_281 ( struct V_12 * V_37 , T_2 V_27 )
{
struct V_1 * V_335 ;
V_335 = F_76 ( V_37 , V_27 ) ;
ASSERT ( V_335 ) ;
if ( F_7 ( & V_335 -> V_336 ) )
F_282 ( & V_335 -> V_336 ) ;
F_6 ( V_335 ) ;
F_6 ( V_335 ) ;
}
static int F_283 ( T_7 * V_337 )
{
F_68 () ;
return 0 ;
}
void F_284 ( struct V_1 * V_335 )
{
F_285 ( & V_335 -> V_336 ,
F_283 ,
V_102 ) ;
}
static const char * F_286 ( T_2 V_7 )
{
switch ( V_7 ) {
case V_54 | V_338 :
return L_3 ;
case V_54 :
return L_4 ;
case V_338 :
return L_5 ;
case V_339 :
return L_6 ;
default:
F_8 ( 1 ) ;
return L_7 ;
} ;
}
static int F_287 ( struct V_12 * V_13 , T_2 V_7 ,
T_2 V_340 , T_2 V_94 ,
T_2 V_341 ,
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
V_114 -> V_340 += V_340 ;
V_114 -> V_346 += V_340 * V_342 ;
V_114 -> V_94 += V_94 ;
V_114 -> V_347 += V_94 * V_342 ;
V_114 -> V_341 += V_341 ;
if ( V_340 > 0 )
V_114 -> V_116 = 0 ;
F_288 ( V_13 , V_114 , V_340 -
V_94 - V_341 ) ;
F_13 ( & V_114 -> V_51 ) ;
* V_95 = V_114 ;
return 0 ;
}
V_114 = F_61 ( sizeof( * V_114 ) , V_98 ) ;
if ( ! V_114 )
return - V_74 ;
V_29 = F_289 ( & V_114 -> V_348 , 0 , V_349 ) ;
if ( V_29 ) {
F_9 ( V_114 ) ;
return V_29 ;
}
for ( V_42 = 0 ; V_42 < V_350 ; V_42 ++ )
F_62 ( & V_114 -> V_351 [ V_42 ] ) ;
F_290 ( & V_114 -> V_352 ) ;
F_291 ( & V_114 -> V_51 ) ;
V_114 -> V_7 = V_7 & V_115 ;
V_114 -> V_340 = V_340 ;
V_114 -> V_346 = V_340 * V_342 ;
V_114 -> V_94 = V_94 ;
V_114 -> V_347 = V_94 * V_342 ;
V_114 -> V_353 = 0 ;
V_114 -> V_354 = 0 ;
V_114 -> V_341 = V_341 ;
V_114 -> V_355 = 0 ;
V_114 -> V_116 = 0 ;
V_114 -> V_356 = 0 ;
V_114 -> V_357 = V_358 ;
V_114 -> V_359 = 0 ;
V_114 -> V_360 = 0 ;
F_64 ( & V_114 -> V_90 ) ;
F_62 ( & V_114 -> V_361 ) ;
F_62 ( & V_114 -> V_362 ) ;
F_62 ( & V_114 -> V_363 ) ;
V_29 = F_292 ( & V_114 -> V_364 , & V_365 ,
V_13 -> V_366 , L_8 ,
F_286 ( V_114 -> V_7 ) ) ;
if ( V_29 ) {
F_9 ( V_114 ) ;
return V_29 ;
}
* V_95 = V_114 ;
F_293 ( & V_114 -> V_99 , & V_13 -> V_95 ) ;
if ( V_7 & V_338 )
V_13 -> V_367 = V_114 ;
return V_29 ;
}
static void F_294 ( struct V_12 * V_37 , T_2 V_7 )
{
T_2 V_368 = F_295 ( V_7 ) &
V_369 ;
F_296 ( & V_37 -> V_370 ) ;
if ( V_7 & V_338 )
V_37 -> V_371 |= V_368 ;
if ( V_7 & V_54 )
V_37 -> V_372 |= V_368 ;
if ( V_7 & V_339 )
V_37 -> V_373 |= V_368 ;
F_297 ( & V_37 -> V_370 ) ;
}
static T_2 F_298 ( struct V_12 * V_37 , T_2 V_7 )
{
struct V_374 * V_375 = V_37 -> V_376 ;
T_2 V_377 = 0 ;
if ( ! V_375 )
return 0 ;
if ( V_7 & V_338 &&
V_375 -> V_378 . V_7 & V_379 ) {
V_377 = V_338 | V_375 -> V_378 . V_377 ;
} else if ( V_7 & V_339 &&
V_375 -> V_380 . V_7 & V_379 ) {
V_377 = V_339 | V_375 -> V_380 . V_377 ;
} else if ( V_7 & V_54 &&
V_375 -> V_381 . V_7 & V_379 ) {
V_377 = V_54 | V_375 -> V_381 . V_377 ;
}
return V_377 ;
}
static T_2 F_299 ( struct V_34 * V_35 , T_2 V_7 )
{
T_2 V_382 = V_35 -> V_37 -> V_383 -> V_384 ;
T_2 V_377 ;
T_2 V_385 ;
T_2 V_386 = 0 ;
F_11 ( & V_35 -> V_37 -> V_387 ) ;
V_377 = F_298 ( V_35 -> V_37 , V_7 ) ;
if ( V_377 ) {
if ( ( V_7 & V_377 ) & V_369 ) {
F_13 ( & V_35 -> V_37 -> V_387 ) ;
return F_300 ( V_377 ) ;
}
}
F_13 ( & V_35 -> V_37 -> V_387 ) ;
for ( V_385 = 0 ; V_385 < V_350 ; V_385 ++ ) {
if ( V_382 >= V_388 [ V_385 ] . V_389 )
V_386 |= V_390 [ V_385 ] ;
}
V_386 &= V_7 ;
if ( V_386 & V_391 )
V_386 = V_391 ;
else if ( V_386 & V_392 )
V_386 = V_392 ;
else if ( V_386 & V_345 )
V_386 = V_345 ;
else if ( V_386 & V_344 )
V_386 = V_344 ;
else if ( V_386 & V_393 )
V_386 = V_393 ;
V_7 &= ~ V_394 ;
return F_300 ( V_7 | V_386 ) ;
}
static T_2 F_301 ( struct V_34 * V_35 , T_2 V_395 )
{
unsigned V_236 ;
T_2 V_7 ;
do {
V_7 = V_395 ;
V_236 = F_302 ( & V_35 -> V_37 -> V_370 ) ;
if ( V_7 & V_338 )
V_7 |= V_35 -> V_37 -> V_371 ;
else if ( V_7 & V_339 )
V_7 |= V_35 -> V_37 -> V_373 ;
else if ( V_7 & V_54 )
V_7 |= V_35 -> V_37 -> V_372 ;
} while ( F_303 ( & V_35 -> V_37 -> V_370 , V_236 ) );
return F_299 ( V_35 , V_7 ) ;
}
T_2 F_304 ( struct V_34 * V_35 , int V_378 )
{
T_2 V_7 ;
T_2 V_29 ;
if ( V_378 )
V_7 = V_338 ;
else if ( V_35 == V_35 -> V_37 -> V_396 )
V_7 = V_339 ;
else
V_7 = V_54 ;
V_29 = F_301 ( V_35 , V_7 ) ;
return V_29 ;
}
int F_305 ( struct V_297 * V_297 , T_2 V_212 )
{
struct V_111 * V_367 ;
struct V_34 * V_35 = F_259 ( V_297 ) -> V_35 ;
struct V_12 * V_37 = V_35 -> V_37 ;
T_2 V_397 ;
int V_29 = 0 ;
int V_398 = 2 ;
int V_399 ;
V_212 = F_149 ( V_212 , V_35 -> V_56 ) ;
if ( F_306 ( V_297 ) ) {
V_398 = 0 ;
ASSERT ( V_400 -> V_401 ) ;
}
V_367 = V_37 -> V_367 ;
if ( ! V_367 )
goto V_402;
V_164:
F_11 ( & V_367 -> V_51 ) ;
V_397 = V_367 -> V_94 + V_367 -> V_354 +
V_367 -> V_353 + V_367 -> V_341 +
V_367 -> V_355 ;
if ( V_397 + V_212 > V_367 -> V_340 ) {
struct V_117 * V_118 ;
if ( ! V_367 -> V_116 ) {
T_2 V_403 ;
V_367 -> V_357 = V_404 ;
F_13 ( & V_367 -> V_51 ) ;
V_402:
V_403 = F_304 ( V_35 , 1 ) ;
V_118 = F_215 ( V_35 ) ;
if ( F_216 ( V_118 ) )
return F_217 ( V_118 ) ;
V_29 = F_307 ( V_118 , V_35 -> V_37 -> V_64 ,
V_403 ,
V_358 ) ;
F_219 ( V_118 , V_35 ) ;
if ( V_29 < 0 ) {
if ( V_29 != - V_313 )
return V_29 ;
else {
V_399 = 1 ;
goto V_405;
}
}
if ( ! V_367 )
V_367 = V_37 -> V_367 ;
goto V_164;
}
V_399 = F_308 (
& V_367 -> V_348 ,
V_397 + V_212 - V_367 -> V_340 ) ;
F_13 ( & V_367 -> V_51 ) ;
V_405:
if ( V_398 &&
! F_212 ( & V_35 -> V_37 -> V_406 ) ) {
V_398 -- ;
if ( V_398 > 0 ) {
F_309 ( V_37 , 0 , - 1 ) ;
F_310 ( V_37 , - 1 , 0 , ( T_2 ) - 1 ) ;
}
V_118 = F_215 ( V_35 ) ;
if ( F_216 ( V_118 ) )
return F_217 ( V_118 ) ;
if ( V_399 >= 0 ||
F_242 ( V_407 ,
& V_118 -> V_135 -> V_7 ) ||
V_398 > 0 ) {
V_29 = F_311 ( V_118 , V_35 ) ;
if ( V_29 )
return V_29 ;
F_49 ( & V_35 -> V_37 -> V_408 ) ;
F_47 ( & V_35 -> V_37 -> V_408 ) ;
goto V_164;
} else {
F_219 ( V_118 , V_35 ) ;
}
}
F_312 ( V_35 -> V_37 ,
L_9 ,
V_367 -> V_7 , V_212 , 1 ) ;
return - V_313 ;
}
V_367 -> V_355 += V_212 ;
F_312 ( V_35 -> V_37 , L_10 ,
V_367 -> V_7 , V_212 , 1 ) ;
F_13 ( & V_367 -> V_51 ) ;
return V_29 ;
}
int F_264 ( struct V_297 * V_297 , T_2 V_32 , T_2 V_48 )
{
struct V_34 * V_35 = F_259 ( V_297 ) -> V_35 ;
int V_29 ;
V_48 = F_313 ( V_32 + V_48 , V_35 -> V_56 ) -
F_150 ( V_32 , V_35 -> V_56 ) ;
V_32 = F_150 ( V_32 , V_35 -> V_56 ) ;
V_29 = F_305 ( V_297 , V_48 ) ;
if ( V_29 < 0 )
return V_29 ;
V_29 = F_314 ( V_297 , V_32 , V_48 ) ;
if ( V_29 )
F_315 ( V_297 , V_32 , V_48 ) ;
return V_29 ;
}
void F_315 ( struct V_297 * V_297 , T_2 V_32 ,
T_2 V_48 )
{
struct V_34 * V_35 = F_259 ( V_297 ) -> V_35 ;
struct V_111 * V_367 ;
V_48 = F_313 ( V_32 + V_48 , V_35 -> V_56 ) -
F_150 ( V_32 , V_35 -> V_56 ) ;
V_32 = F_150 ( V_32 , V_35 -> V_56 ) ;
V_367 = V_35 -> V_37 -> V_367 ;
F_11 ( & V_367 -> V_51 ) ;
if ( F_8 ( V_367 -> V_355 < V_48 ) )
V_367 -> V_355 = 0 ;
else
V_367 -> V_355 -= V_48 ;
F_312 ( V_35 -> V_37 , L_10 ,
V_367 -> V_7 , V_48 , 0 ) ;
F_13 ( & V_367 -> V_51 ) ;
}
void F_316 ( struct V_297 * V_297 , T_2 V_32 , T_2 V_48 )
{
F_315 ( V_297 , V_32 , V_48 ) ;
F_317 ( V_297 , V_32 , V_48 ) ;
}
static void F_318 ( struct V_12 * V_13 )
{
struct V_112 * V_113 = & V_13 -> V_95 ;
struct V_111 * V_114 ;
F_78 () ;
F_79 (found, head, list) {
if ( V_114 -> V_7 & V_54 )
V_114 -> V_357 = V_404 ;
}
F_80 () ;
}
static inline T_2 F_319 ( struct V_261 * V_409 )
{
return ( V_409 -> V_60 << 1 ) ;
}
static int F_320 ( struct V_34 * V_35 ,
struct V_111 * V_410 , int V_411 )
{
struct V_261 * V_262 = & V_35 -> V_37 -> V_265 ;
T_2 V_36 = V_410 -> V_340 - V_410 -> V_341 ;
T_2 V_412 = V_410 -> V_94 + V_410 -> V_354 ;
T_2 V_413 ;
if ( V_411 == V_404 )
return 1 ;
if ( V_410 -> V_7 & V_54 )
V_412 += F_319 ( V_262 ) ;
if ( V_411 == V_414 ) {
V_413 = F_321 ( V_35 -> V_37 -> V_260 ) ;
V_413 = F_35 ( T_2 , V_415 , F_322 ( V_413 , 1 ) ) ;
if ( V_36 - V_412 < V_413 )
return 1 ;
}
if ( V_412 + V_416 < F_323 ( V_36 , 8 ) )
return 0 ;
return 1 ;
}
static T_2 F_324 ( struct V_34 * V_35 , T_2 type )
{
T_2 V_417 ;
if ( type & ( V_345 |
V_393 |
V_392 |
V_391 ) )
V_417 = V_35 -> V_37 -> V_383 -> V_384 ;
else if ( type & V_344 )
V_417 = 2 ;
else
V_417 = 1 ;
return V_417 ;
}
void F_325 ( struct V_117 * V_118 ,
struct V_34 * V_35 ,
T_2 type )
{
struct V_111 * V_13 ;
T_2 V_418 ;
T_2 V_413 ;
int V_29 = 0 ;
T_2 V_419 ;
ASSERT ( F_326 ( & V_35 -> V_37 -> V_420 ) ) ;
V_13 = F_77 ( V_35 -> V_37 , V_339 ) ;
F_11 ( & V_13 -> V_51 ) ;
V_418 = V_13 -> V_340 - V_13 -> V_94 - V_13 -> V_353 -
V_13 -> V_354 - V_13 -> V_341 -
V_13 -> V_355 ;
F_13 ( & V_13 -> V_51 ) ;
V_419 = F_324 ( V_35 , type ) ;
V_413 = F_327 ( V_35 , V_419 ) +
F_210 ( V_35 , 1 ) ;
if ( V_418 < V_413 && F_263 ( V_35 -> V_37 , V_421 ) ) {
F_328 ( V_35 -> V_37 , L_11 ,
V_418 , V_413 , type ) ;
F_329 ( V_13 , 0 , 0 ) ;
}
if ( V_418 < V_413 ) {
T_2 V_7 ;
V_7 = F_304 ( V_35 -> V_37 -> V_396 , 0 ) ;
V_29 = F_330 ( V_118 , V_35 , V_7 ) ;
}
if ( ! V_29 ) {
V_29 = F_331 ( V_35 -> V_37 -> V_396 ,
& V_35 -> V_37 -> V_422 ,
V_413 , V_423 ) ;
if ( ! V_29 )
V_118 -> V_424 += V_413 ;
}
}
static int F_307 ( struct V_117 * V_118 ,
struct V_34 * V_64 , T_2 V_7 , int V_411 )
{
struct V_111 * V_95 ;
struct V_12 * V_37 = V_64 -> V_37 ;
int V_425 = 0 ;
int V_29 = 0 ;
if ( V_118 -> V_426 )
return - V_313 ;
V_95 = F_77 ( V_64 -> V_37 , V_7 ) ;
if ( ! V_95 ) {
V_29 = F_287 ( V_64 -> V_37 , V_7 ,
0 , 0 , 0 , & V_95 ) ;
F_32 ( V_29 ) ;
}
F_32 ( ! V_95 ) ;
V_164:
F_11 ( & V_95 -> V_51 ) ;
if ( V_411 < V_95 -> V_357 )
V_411 = V_95 -> V_357 ;
if ( V_95 -> V_116 ) {
if ( F_320 ( V_64 , V_95 , V_411 ) )
V_29 = - V_313 ;
else
V_29 = 0 ;
F_13 ( & V_95 -> V_51 ) ;
return V_29 ;
}
if ( ! F_320 ( V_64 , V_95 , V_411 ) ) {
F_13 ( & V_95 -> V_51 ) ;
return 0 ;
} else if ( V_95 -> V_359 ) {
V_425 = 1 ;
} else {
V_95 -> V_359 = 1 ;
}
F_13 ( & V_95 -> V_51 ) ;
F_49 ( & V_37 -> V_420 ) ;
if ( V_425 ) {
F_47 ( & V_37 -> V_420 ) ;
V_425 = 0 ;
goto V_164;
}
V_118 -> V_426 = true ;
if ( F_332 ( V_95 ) )
V_7 |= ( V_338 | V_54 ) ;
if ( V_7 & V_338 && V_37 -> V_427 ) {
V_37 -> V_428 ++ ;
if ( ! ( V_37 -> V_428 %
V_37 -> V_427 ) )
F_318 ( V_37 ) ;
}
F_325 ( V_118 , V_64 , V_7 ) ;
V_29 = F_330 ( V_118 , V_64 , V_7 ) ;
V_118 -> V_426 = false ;
F_11 ( & V_95 -> V_51 ) ;
if ( V_29 < 0 && V_29 != - V_313 )
goto V_81;
if ( V_29 )
V_95 -> V_116 = 1 ;
else
V_29 = 1 ;
V_95 -> V_357 = V_358 ;
V_81:
V_95 -> V_359 = 0 ;
F_13 ( & V_95 -> V_51 ) ;
F_47 ( & V_37 -> V_420 ) ;
if ( V_118 -> V_277 &&
V_118 -> V_424 >= ( T_2 ) V_416 ) {
F_226 ( V_118 , V_64 ) ;
F_333 ( V_118 ) ;
}
return V_29 ;
}
static int F_334 ( struct V_34 * V_35 ,
struct V_111 * V_95 , T_2 V_212 ,
enum V_429 V_360 )
{
struct V_261 * V_262 ;
T_2 V_430 ;
T_2 V_431 ;
T_2 V_432 ;
T_2 V_397 ;
if ( V_95 -> V_7 & V_338 )
return 0 ;
F_32 ( V_35 -> V_37 == NULL ) ;
V_262 = & V_35 -> V_37 -> V_265 ;
V_430 = F_304 ( V_35 , 0 ) ;
V_397 = V_95 -> V_94 + V_95 -> V_354 +
V_95 -> V_353 + V_95 -> V_341 ;
F_11 ( & V_262 -> V_51 ) ;
V_431 = F_319 ( V_262 ) ;
F_13 ( & V_262 -> V_51 ) ;
if ( V_397 + V_431 >= V_95 -> V_340 )
return 0 ;
V_397 += V_95 -> V_355 ;
F_11 ( & V_35 -> V_37 -> V_433 ) ;
V_432 = V_35 -> V_37 -> V_434 ;
F_13 ( & V_35 -> V_37 -> V_433 ) ;
if ( V_430 & ( V_343 |
V_344 |
V_345 ) )
V_432 >>= 1 ;
if ( V_360 == V_435 )
V_432 >>= 3 ;
else
V_432 >>= 1 ;
if ( V_397 + V_212 < V_95 -> V_340 + V_432 )
return 1 ;
return 0 ;
}
static void F_335 ( struct V_34 * V_35 ,
unsigned long V_436 , int V_437 )
{
struct V_438 * V_439 = V_35 -> V_37 -> V_439 ;
if ( F_336 ( & V_439 -> V_440 ) ) {
F_337 ( V_439 , V_436 , V_441 ) ;
F_46 ( & V_439 -> V_440 ) ;
} else {
F_309 ( V_35 -> V_37 , 0 , V_437 ) ;
if ( ! V_400 -> V_401 )
F_310 ( V_35 -> V_37 , V_437 ,
0 , ( T_2 ) - 1 ) ;
}
}
static inline int F_338 ( struct V_34 * V_35 , T_2 V_442 )
{
T_2 V_212 ;
int V_43 ;
V_212 = F_210 ( V_35 , 1 ) ;
V_43 = ( int ) F_207 ( V_442 , V_212 ) ;
if ( ! V_43 )
V_43 = 1 ;
return V_43 ;
}
static void F_339 ( struct V_34 * V_35 , T_2 V_442 , T_2 V_443 ,
bool V_444 )
{
struct V_261 * V_445 ;
struct V_111 * V_95 ;
struct V_117 * V_118 ;
T_2 V_446 ;
T_2 V_447 ;
long V_448 ;
unsigned long V_436 ;
int V_326 ;
int V_449 ;
enum V_429 V_360 ;
V_449 = F_338 ( V_35 , V_442 ) ;
V_442 = ( T_2 ) V_449 * V_450 ;
V_118 = (struct V_117 * ) V_400 -> V_401 ;
V_445 = & V_35 -> V_37 -> V_451 ;
V_95 = V_445 -> V_95 ;
V_446 = F_340 (
& V_35 -> V_37 -> V_446 ) ;
if ( V_446 == 0 ) {
if ( V_118 )
return;
if ( V_444 )
F_310 ( V_35 -> V_37 , V_449 ,
0 , ( T_2 ) - 1 ) ;
return;
}
V_326 = 0 ;
while ( V_446 && V_326 < 3 ) {
V_447 = F_341 ( V_446 , V_442 ) ;
V_436 = V_447 >> V_452 ;
F_335 ( V_35 , V_436 , V_449 ) ;
V_447 = F_212 ( & V_35 -> V_37 -> V_453 ) ;
if ( ! V_447 )
goto V_454;
if ( V_447 <= V_436 )
V_447 = 0 ;
else
V_447 -= V_436 ;
F_278 ( V_35 -> V_37 -> V_455 ,
F_212 ( & V_35 -> V_37 -> V_453 ) <=
( int ) V_447 ) ;
V_454:
if ( ! V_118 )
V_360 = V_435 ;
else
V_360 = V_423 ;
F_11 ( & V_95 -> V_51 ) ;
if ( F_334 ( V_35 , V_95 , V_443 , V_360 ) ) {
F_13 ( & V_95 -> V_51 ) ;
break;
}
if ( F_182 ( & V_95 -> V_362 ) &&
F_182 ( & V_95 -> V_363 ) ) {
F_13 ( & V_95 -> V_51 ) ;
break;
}
F_13 ( & V_95 -> V_51 ) ;
V_326 ++ ;
if ( V_444 && ! V_118 ) {
F_310 ( V_35 -> V_37 , V_449 ,
0 , ( T_2 ) - 1 ) ;
} else {
V_448 = F_342 ( 1 ) ;
if ( V_448 )
break;
}
V_446 = F_340 (
& V_35 -> V_37 -> V_446 ) ;
}
}
static int F_343 ( struct V_34 * V_35 ,
struct V_111 * V_95 ,
T_2 V_212 , int V_411 )
{
struct V_261 * V_456 = & V_35 -> V_37 -> V_457 ;
struct V_117 * V_118 ;
V_118 = (struct V_117 * ) V_400 -> V_401 ;
if ( V_118 )
return - V_187 ;
if ( V_411 )
goto V_458;
if ( F_308 ( & V_95 -> V_348 ,
V_212 ) >= 0 )
goto V_458;
if ( V_95 != V_456 -> V_95 )
return - V_313 ;
F_11 ( & V_456 -> V_51 ) ;
if ( F_308 ( & V_95 -> V_348 ,
V_212 - V_456 -> V_60 ) >= 0 ) {
F_13 ( & V_456 -> V_51 ) ;
return - V_313 ;
}
F_13 ( & V_456 -> V_51 ) ;
V_458:
V_118 = F_215 ( V_35 ) ;
if ( F_216 ( V_118 ) )
return - V_313 ;
return F_311 ( V_118 , V_35 ) ;
}
static int F_344 ( struct V_34 * V_35 ,
struct V_111 * V_95 , T_2 V_36 ,
T_2 V_459 , int V_292 )
{
struct V_117 * V_118 ;
int V_43 ;
int V_29 = 0 ;
switch ( V_292 ) {
case V_460 :
case V_461 :
if ( V_292 == V_460 )
V_43 = F_338 ( V_35 , V_36 ) * 2 ;
else
V_43 = - 1 ;
V_118 = F_215 ( V_35 ) ;
if ( F_216 ( V_118 ) ) {
V_29 = F_217 ( V_118 ) ;
break;
}
V_29 = F_345 ( V_118 , V_35 , V_43 ) ;
F_219 ( V_118 , V_35 ) ;
break;
case V_462 :
case V_463 :
F_339 ( V_35 , V_36 * 2 , V_459 ,
V_292 == V_463 ) ;
break;
case V_464 :
V_118 = F_215 ( V_35 ) ;
if ( F_216 ( V_118 ) ) {
V_29 = F_217 ( V_118 ) ;
break;
}
V_29 = F_307 ( V_118 , V_35 -> V_37 -> V_64 ,
F_304 ( V_35 , 0 ) ,
V_358 ) ;
F_219 ( V_118 , V_35 ) ;
if ( V_29 > 0 || V_29 == - V_313 )
V_29 = 0 ;
break;
case V_465 :
V_29 = F_343 ( V_35 , V_95 , V_459 , 0 ) ;
break;
default:
V_29 = - V_313 ;
break;
}
F_346 ( V_35 -> V_37 , V_95 -> V_7 , V_36 ,
V_459 , V_292 , V_29 ) ;
return V_29 ;
}
static inline T_2
F_347 ( struct V_34 * V_35 ,
struct V_111 * V_95 )
{
struct V_466 * V_467 ;
T_2 V_397 ;
T_2 V_468 ;
T_2 V_442 = 0 ;
F_183 (ticket, &space_info->tickets, list)
V_442 += V_467 -> V_212 ;
F_183 (ticket, &space_info->priority_tickets, list)
V_442 += V_467 -> V_212 ;
if ( V_442 )
return V_442 ;
V_442 = F_24 ( T_2 , F_348 () * V_303 , V_469 ) ;
if ( F_334 ( V_35 , V_95 , V_442 ,
V_435 ) )
return 0 ;
V_397 = V_95 -> V_94 + V_95 -> V_354 +
V_95 -> V_353 + V_95 -> V_341 +
V_95 -> V_355 ;
if ( F_334 ( V_35 , V_95 , V_303 , V_435 ) )
V_468 = F_322 ( V_95 -> V_340 , 95 ) ;
else
V_468 = F_322 ( V_95 -> V_340 , 90 ) ;
if ( V_397 > V_468 )
V_442 = V_397 - V_468 ;
else
V_442 = 0 ;
V_442 = F_341 ( V_442 , V_95 -> V_355 +
V_95 -> V_354 ) ;
return V_442 ;
}
static inline int F_349 ( struct V_111 * V_95 ,
struct V_34 * V_35 , T_2 V_397 )
{
T_2 V_413 = F_322 ( V_95 -> V_340 , 98 ) ;
if ( ( V_95 -> V_94 + V_95 -> V_354 ) >= V_413 )
return 0 ;
if ( ! F_347 ( V_35 , V_95 ) )
return 0 ;
return ( V_397 >= V_413 && ! F_40 ( V_35 -> V_37 ) &&
! F_242 ( V_470 ,
& V_35 -> V_37 -> V_471 ) ) ;
}
static void F_350 ( struct V_112 * V_113 )
{
struct V_466 * V_467 ;
while ( ! F_182 ( V_113 ) ) {
V_467 = F_273 ( V_113 , struct V_466 , V_99 ) ;
F_274 ( & V_467 -> V_99 ) ;
V_467 -> error = - V_313 ;
F_52 ( & V_467 -> V_90 ) ;
}
}
static void F_351 ( struct V_472 * V_92 )
{
struct V_12 * V_37 ;
struct V_111 * V_95 ;
T_2 V_442 ;
int V_473 ;
int V_474 = 0 ;
T_2 V_475 ;
V_37 = F_55 ( V_92 , struct V_12 , V_476 ) ;
V_95 = F_77 ( V_37 , V_54 ) ;
F_11 ( & V_95 -> V_51 ) ;
V_442 = F_347 ( V_37 -> V_477 ,
V_95 ) ;
if ( ! V_442 ) {
V_95 -> V_360 = 0 ;
F_13 ( & V_95 -> V_51 ) ;
return;
}
V_475 = V_95 -> V_478 ;
F_13 ( & V_95 -> V_51 ) ;
V_473 = V_460 ;
do {
struct V_466 * V_467 ;
int V_29 ;
V_29 = F_344 ( V_37 -> V_477 , V_95 , V_442 ,
V_442 , V_473 ) ;
F_11 ( & V_95 -> V_51 ) ;
if ( F_182 ( & V_95 -> V_362 ) ) {
V_95 -> V_360 = 0 ;
F_13 ( & V_95 -> V_51 ) ;
return;
}
V_442 = F_347 ( V_37 -> V_477 ,
V_95 ) ;
V_467 = F_273 ( & V_95 -> V_362 ,
struct V_466 , V_99 ) ;
if ( V_475 == V_95 -> V_478 ) {
V_473 ++ ;
} else {
V_475 = V_95 -> V_478 ;
V_473 = V_460 ;
if ( V_474 )
V_474 -- ;
}
if ( V_473 > V_465 ) {
V_474 ++ ;
if ( V_474 > 2 ) {
F_350 ( & V_95 -> V_362 ) ;
V_95 -> V_360 = 0 ;
} else {
V_473 = V_460 ;
}
}
F_13 ( & V_95 -> V_51 ) ;
} while ( V_473 <= V_465 );
}
void F_352 ( struct V_472 * V_92 )
{
F_353 ( V_92 , F_351 ) ;
}
static void F_354 ( struct V_12 * V_37 ,
struct V_111 * V_95 ,
struct V_466 * V_467 )
{
T_2 V_442 ;
int V_473 = V_460 ;
F_11 ( & V_95 -> V_51 ) ;
V_442 = F_347 ( V_37 -> V_477 ,
V_95 ) ;
if ( ! V_442 ) {
F_13 ( & V_95 -> V_51 ) ;
return;
}
F_13 ( & V_95 -> V_51 ) ;
do {
F_344 ( V_37 -> V_477 , V_95 , V_442 ,
V_442 , V_473 ) ;
V_473 ++ ;
F_11 ( & V_95 -> V_51 ) ;
if ( V_467 -> V_212 == 0 ) {
F_13 ( & V_95 -> V_51 ) ;
return;
}
F_13 ( & V_95 -> V_51 ) ;
if ( V_473 == V_462 ||
V_473 == V_463 )
V_473 = V_464 ;
} while ( V_473 < V_465 );
}
static int F_355 ( struct V_12 * V_37 ,
struct V_111 * V_95 ,
struct V_466 * V_467 , T_2 V_459 )
{
F_60 ( V_90 ) ;
int V_29 = 0 ;
F_11 ( & V_95 -> V_51 ) ;
while ( V_467 -> V_212 > 0 && V_467 -> error == 0 ) {
V_29 = F_356 ( & V_467 -> V_90 , & V_90 , V_479 ) ;
if ( V_29 ) {
V_29 = - V_480 ;
break;
}
F_13 ( & V_95 -> V_51 ) ;
F_68 () ;
F_69 ( & V_467 -> V_90 , & V_90 ) ;
F_11 ( & V_95 -> V_51 ) ;
}
if ( ! V_29 )
V_29 = V_467 -> error ;
if ( ! F_182 ( & V_467 -> V_99 ) )
F_274 ( & V_467 -> V_99 ) ;
if ( V_467 -> V_212 && V_467 -> V_212 < V_459 ) {
T_2 V_36 = V_459 - V_467 -> V_212 ;
V_95 -> V_355 -= V_36 ;
F_312 ( V_37 , L_10 ,
V_95 -> V_7 , V_36 , 0 ) ;
}
F_13 ( & V_95 -> V_51 ) ;
return V_29 ;
}
static int F_357 ( struct V_34 * V_35 ,
struct V_111 * V_95 ,
T_2 V_459 ,
enum V_429 V_360 )
{
struct V_466 V_467 ;
T_2 V_397 ;
int V_29 = 0 ;
ASSERT ( V_459 ) ;
ASSERT ( ! V_400 -> V_401 || V_360 != V_435 ) ;
F_11 ( & V_95 -> V_51 ) ;
V_29 = - V_313 ;
V_397 = V_95 -> V_94 + V_95 -> V_354 +
V_95 -> V_353 + V_95 -> V_341 +
V_95 -> V_355 ;
if ( V_397 + V_459 <= V_95 -> V_340 ) {
V_95 -> V_355 += V_459 ;
F_312 ( V_35 -> V_37 , L_10 ,
V_95 -> V_7 , V_459 ,
1 ) ;
V_29 = 0 ;
} else if ( F_334 ( V_35 , V_95 , V_459 , V_360 ) ) {
V_95 -> V_355 += V_459 ;
F_312 ( V_35 -> V_37 , L_10 ,
V_95 -> V_7 , V_459 ,
1 ) ;
V_29 = 0 ;
}
if ( V_29 && V_360 != V_423 ) {
V_467 . V_212 = V_459 ;
V_467 . error = 0 ;
F_64 ( & V_467 . V_90 ) ;
if ( V_360 == V_435 ) {
F_72 ( & V_467 . V_99 , & V_95 -> V_362 ) ;
if ( ! V_95 -> V_360 ) {
V_95 -> V_360 = 1 ;
F_358 ( V_35 -> V_37 ,
V_95 -> V_7 ,
V_459 , V_360 ,
L_12 ) ;
F_359 ( V_481 ,
& V_35 -> V_37 -> V_476 ) ;
}
} else {
F_72 ( & V_467 . V_99 ,
& V_95 -> V_363 ) ;
}
} else if ( ! V_29 && V_95 -> V_7 & V_54 ) {
V_397 += V_459 ;
if ( ! V_35 -> V_37 -> V_482 &&
F_349 ( V_95 , V_35 , V_397 ) &&
! F_360 ( & V_35 -> V_37 -> V_476 ) ) {
F_358 ( V_35 -> V_37 ,
V_95 -> V_7 ,
V_459 , V_360 ,
L_13 ) ;
F_359 ( V_481 ,
& V_35 -> V_37 -> V_476 ) ;
}
}
F_13 ( & V_95 -> V_51 ) ;
if ( ! V_29 || V_360 == V_423 )
return V_29 ;
if ( V_360 == V_435 )
return F_355 ( V_35 -> V_37 , V_95 , & V_467 ,
V_459 ) ;
V_29 = 0 ;
F_354 ( V_35 -> V_37 , V_95 , & V_467 ) ;
F_11 ( & V_95 -> V_51 ) ;
if ( V_467 . V_212 ) {
if ( V_467 . V_212 < V_459 ) {
T_2 V_36 = V_459 - V_467 . V_212 ;
V_95 -> V_355 -= V_36 ;
F_312 ( V_35 -> V_37 ,
L_10 , V_95 -> V_7 ,
V_36 , 0 ) ;
}
F_274 ( & V_467 . V_99 ) ;
V_29 = - V_313 ;
}
F_13 ( & V_95 -> V_51 ) ;
ASSERT ( F_182 ( & V_467 . V_99 ) ) ;
return V_29 ;
}
static int F_361 ( struct V_34 * V_35 ,
struct V_261 * V_445 ,
T_2 V_459 ,
enum V_429 V_360 )
{
int V_29 ;
V_29 = F_357 ( V_35 , V_445 -> V_95 , V_459 ,
V_360 ) ;
if ( V_29 == - V_313 &&
F_362 ( V_35 -> V_483 == V_484 ) ) {
struct V_261 * V_262 =
& V_35 -> V_37 -> V_265 ;
if ( V_445 != V_262 &&
! F_363 ( V_262 , V_459 ) )
V_29 = 0 ;
}
if ( V_29 == - V_313 )
F_312 ( V_35 -> V_37 ,
L_9 ,
V_445 -> V_95 -> V_7 ,
V_459 , 1 ) ;
return V_29 ;
}
static struct V_261 * F_364 (
const struct V_117 * V_118 ,
const struct V_34 * V_35 )
{
struct V_261 * V_445 = NULL ;
if ( F_242 ( V_291 , & V_35 -> V_292 ) ||
( V_35 == V_35 -> V_37 -> V_485 && V_118 -> V_486 ) ||
( V_35 == V_35 -> V_37 -> V_487 ) )
V_445 = V_118 -> V_445 ;
if ( ! V_445 )
V_445 = V_35 -> V_445 ;
if ( ! V_445 )
V_445 = & V_35 -> V_37 -> V_488 ;
return V_445 ;
}
static int F_363 ( struct V_261 * V_445 ,
T_2 V_36 )
{
int V_29 = - V_313 ;
F_11 ( & V_445 -> V_51 ) ;
if ( V_445 -> V_10 >= V_36 ) {
V_445 -> V_10 -= V_36 ;
if ( V_445 -> V_10 < V_445 -> V_60 )
V_445 -> V_116 = 0 ;
V_29 = 0 ;
}
F_13 ( & V_445 -> V_51 ) ;
return V_29 ;
}
static void F_365 ( struct V_261 * V_445 ,
T_2 V_36 , int V_489 )
{
F_11 ( & V_445 -> V_51 ) ;
V_445 -> V_10 += V_36 ;
if ( V_489 )
V_445 -> V_60 += V_36 ;
else if ( V_445 -> V_10 >= V_445 -> V_60 )
V_445 -> V_116 = 1 ;
F_13 ( & V_445 -> V_51 ) ;
}
int F_366 ( struct V_12 * V_37 ,
struct V_261 * V_490 , T_2 V_36 ,
int V_491 )
{
struct V_261 * V_262 = & V_37 -> V_265 ;
T_2 V_492 ;
if ( V_262 -> V_95 != V_490 -> V_95 )
return - V_313 ;
F_11 ( & V_262 -> V_51 ) ;
V_492 = F_323 ( V_262 -> V_60 , V_491 ) ;
if ( V_262 -> V_10 < V_492 + V_36 ) {
F_13 ( & V_262 -> V_51 ) ;
return - V_313 ;
}
V_262 -> V_10 -= V_36 ;
if ( V_262 -> V_10 < V_262 -> V_60 )
V_262 -> V_116 = 0 ;
F_13 ( & V_262 -> V_51 ) ;
F_365 ( V_490 , V_36 , 1 ) ;
return 0 ;
}
static void F_367 ( struct V_12 * V_37 ,
struct V_111 * V_95 ,
T_2 V_36 )
{
struct V_466 * V_467 ;
struct V_112 * V_113 ;
T_2 V_397 ;
enum V_429 V_360 = V_423 ;
bool V_493 = false ;
F_11 ( & V_95 -> V_51 ) ;
V_113 = & V_95 -> V_363 ;
V_397 = V_95 -> V_94 + V_95 -> V_354 +
V_95 -> V_353 + V_95 -> V_341 +
V_95 -> V_355 ;
if ( V_397 - V_36 >= V_95 -> V_340 )
V_493 = true ;
V_164:
while ( ! F_182 ( V_113 ) && V_36 ) {
V_467 = F_273 ( V_113 , struct V_466 ,
V_99 ) ;
if ( V_493 &&
! F_334 ( V_37 -> V_64 , V_95 , 0 ,
V_360 ) )
break;
if ( V_36 >= V_467 -> V_212 ) {
F_274 ( & V_467 -> V_99 ) ;
V_36 -= V_467 -> V_212 ;
V_467 -> V_212 = 0 ;
V_95 -> V_478 ++ ;
F_52 ( & V_467 -> V_90 ) ;
} else {
V_467 -> V_212 -= V_36 ;
V_36 = 0 ;
}
}
if ( V_36 && V_113 == & V_95 -> V_363 ) {
V_113 = & V_95 -> V_362 ;
V_360 = V_435 ;
goto V_164;
}
V_95 -> V_355 -= V_36 ;
F_312 ( V_37 , L_10 ,
V_95 -> V_7 , V_36 , 0 ) ;
F_13 ( & V_95 -> V_51 ) ;
}
static void F_288 ( struct V_12 * V_37 ,
struct V_111 * V_95 ,
T_2 V_36 )
{
struct V_466 * V_467 ;
struct V_112 * V_113 = & V_95 -> V_363 ;
V_164:
while ( ! F_182 ( V_113 ) && V_36 ) {
V_467 = F_273 ( V_113 , struct V_466 ,
V_99 ) ;
if ( V_36 >= V_467 -> V_212 ) {
F_312 ( V_37 , L_10 ,
V_95 -> V_7 ,
V_467 -> V_212 , 1 ) ;
F_274 ( & V_467 -> V_99 ) ;
V_36 -= V_467 -> V_212 ;
V_95 -> V_355 += V_467 -> V_212 ;
V_467 -> V_212 = 0 ;
V_95 -> V_478 ++ ;
F_52 ( & V_467 -> V_90 ) ;
} else {
F_312 ( V_37 , L_10 ,
V_95 -> V_7 ,
V_36 , 1 ) ;
V_95 -> V_355 += V_36 ;
V_467 -> V_212 -= V_36 ;
V_36 = 0 ;
}
}
if ( V_36 && V_113 == & V_95 -> V_363 ) {
V_113 = & V_95 -> V_362 ;
goto V_164;
}
}
static void F_368 ( struct V_12 * V_37 ,
struct V_261 * V_445 ,
struct V_261 * V_490 , T_2 V_36 )
{
struct V_111 * V_95 = V_445 -> V_95 ;
F_11 ( & V_445 -> V_51 ) ;
if ( V_36 == ( T_2 ) - 1 )
V_36 = V_445 -> V_60 ;
V_445 -> V_60 -= V_36 ;
if ( V_445 -> V_10 >= V_445 -> V_60 ) {
V_36 = V_445 -> V_10 - V_445 -> V_60 ;
V_445 -> V_10 = V_445 -> V_60 ;
V_445 -> V_116 = 1 ;
} else {
V_36 = 0 ;
}
F_13 ( & V_445 -> V_51 ) ;
if ( V_36 > 0 ) {
if ( V_490 ) {
F_11 ( & V_490 -> V_51 ) ;
if ( ! V_490 -> V_116 ) {
T_2 V_494 ;
V_494 = V_490 -> V_60 - V_490 -> V_10 ;
V_494 = F_341 ( V_36 , V_494 ) ;
V_490 -> V_10 += V_494 ;
if ( V_490 -> V_10 >= V_490 -> V_60 )
V_490 -> V_116 = 1 ;
V_36 -= V_494 ;
}
F_13 ( & V_490 -> V_51 ) ;
}
if ( V_36 )
F_367 ( V_37 , V_95 ,
V_36 ) ;
}
}
int F_369 ( struct V_261 * V_495 ,
struct V_261 * V_496 , T_2 V_36 ,
int V_489 )
{
int V_29 ;
V_29 = F_363 ( V_495 , V_36 ) ;
if ( V_29 )
return V_29 ;
F_365 ( V_496 , V_36 , V_489 ) ;
return 0 ;
}
void F_370 ( struct V_261 * V_497 , unsigned short type )
{
memset ( V_497 , 0 , sizeof( * V_497 ) ) ;
F_291 ( & V_497 -> V_51 ) ;
V_497 -> type = type ;
}
struct V_261 * F_371 ( struct V_34 * V_35 ,
unsigned short type )
{
struct V_261 * V_445 ;
struct V_12 * V_37 = V_35 -> V_37 ;
V_445 = F_222 ( sizeof( * V_445 ) , V_98 ) ;
if ( ! V_445 )
return NULL ;
F_370 ( V_445 , type ) ;
V_445 -> V_95 = F_77 ( V_37 ,
V_54 ) ;
return V_445 ;
}
void F_372 ( struct V_34 * V_35 ,
struct V_261 * V_497 )
{
if ( ! V_497 )
return;
F_373 ( V_35 , V_497 , ( T_2 ) - 1 ) ;
F_9 ( V_497 ) ;
}
void F_374 ( struct V_261 * V_497 )
{
F_9 ( V_497 ) ;
}
int F_331 ( struct V_34 * V_35 ,
struct V_261 * V_445 , T_2 V_36 ,
enum V_429 V_360 )
{
int V_29 ;
if ( V_36 == 0 )
return 0 ;
V_29 = F_361 ( V_35 , V_445 , V_36 , V_360 ) ;
if ( ! V_29 ) {
F_365 ( V_445 , V_36 , 1 ) ;
return 0 ;
}
return V_29 ;
}
int F_375 ( struct V_34 * V_35 ,
struct V_261 * V_445 , int V_491 )
{
T_2 V_36 = 0 ;
int V_29 = - V_313 ;
if ( ! V_445 )
return 0 ;
F_11 ( & V_445 -> V_51 ) ;
V_36 = F_323 ( V_445 -> V_60 , V_491 ) ;
if ( V_445 -> V_10 >= V_36 )
V_29 = 0 ;
F_13 ( & V_445 -> V_51 ) ;
return V_29 ;
}
int F_376 ( struct V_34 * V_35 ,
struct V_261 * V_445 , T_2 V_498 ,
enum V_429 V_360 )
{
T_2 V_36 = 0 ;
int V_29 = - V_313 ;
if ( ! V_445 )
return 0 ;
F_11 ( & V_445 -> V_51 ) ;
V_36 = V_498 ;
if ( V_445 -> V_10 >= V_36 )
V_29 = 0 ;
else
V_36 -= V_445 -> V_10 ;
F_13 ( & V_445 -> V_51 ) ;
if ( ! V_29 )
return 0 ;
V_29 = F_361 ( V_35 , V_445 , V_36 , V_360 ) ;
if ( ! V_29 ) {
F_365 ( V_445 , V_36 , 0 ) ;
return 0 ;
}
return V_29 ;
}
void F_373 ( struct V_34 * V_35 ,
struct V_261 * V_445 ,
T_2 V_36 )
{
struct V_261 * V_262 = & V_35 -> V_37 -> V_265 ;
if ( V_262 == V_445 ||
V_445 -> V_95 != V_262 -> V_95 )
V_262 = NULL ;
F_368 ( V_35 -> V_37 , V_445 , V_262 ,
V_36 ) ;
}
static void F_377 ( struct V_12 * V_37 )
{
struct V_261 * V_445 = & V_37 -> V_265 ;
struct V_111 * V_410 = V_445 -> V_95 ;
T_2 V_36 ;
V_36 = F_378 ( & V_37 -> V_64 -> V_283 ) +
F_378 ( & V_37 -> V_485 -> V_283 ) +
F_378 ( & V_37 -> V_88 -> V_283 ) ;
V_36 = F_35 ( T_2 , V_36 , V_469 ) ;
F_11 ( & V_410 -> V_51 ) ;
F_11 ( & V_445 -> V_51 ) ;
V_445 -> V_60 = F_24 ( T_2 , V_36 , V_499 ) ;
if ( V_445 -> V_10 < V_445 -> V_60 ) {
V_36 = V_410 -> V_94 + V_410 -> V_353 +
V_410 -> V_354 + V_410 -> V_341 +
V_410 -> V_355 ;
if ( V_410 -> V_340 > V_36 ) {
V_36 = V_410 -> V_340 - V_36 ;
V_36 = F_341 ( V_36 ,
V_445 -> V_60 - V_445 -> V_10 ) ;
V_445 -> V_10 += V_36 ;
V_410 -> V_355 += V_36 ;
F_312 ( V_37 , L_10 ,
V_410 -> V_7 , V_36 ,
1 ) ;
}
} else if ( V_445 -> V_10 > V_445 -> V_60 ) {
V_36 = V_445 -> V_10 - V_445 -> V_60 ;
V_410 -> V_355 -= V_36 ;
F_312 ( V_37 , L_10 ,
V_410 -> V_7 , V_36 , 0 ) ;
V_445 -> V_10 = V_445 -> V_60 ;
}
if ( V_445 -> V_10 == V_445 -> V_60 )
V_445 -> V_116 = 1 ;
else
V_445 -> V_116 = 0 ;
F_13 ( & V_445 -> V_51 ) ;
F_13 ( & V_410 -> V_51 ) ;
}
static void F_379 ( struct V_12 * V_37 )
{
struct V_111 * V_95 ;
V_95 = F_77 ( V_37 , V_339 ) ;
V_37 -> V_422 . V_95 = V_95 ;
V_95 = F_77 ( V_37 , V_54 ) ;
V_37 -> V_265 . V_95 = V_95 ;
V_37 -> V_451 . V_95 = V_95 ;
V_37 -> V_500 . V_95 = V_95 ;
V_37 -> V_488 . V_95 = V_95 ;
V_37 -> V_457 . V_95 = V_95 ;
V_37 -> V_64 -> V_445 = & V_37 -> V_265 ;
V_37 -> V_485 -> V_445 = & V_37 -> V_265 ;
V_37 -> V_501 -> V_445 = & V_37 -> V_265 ;
V_37 -> V_88 -> V_445 = & V_37 -> V_265 ;
if ( V_37 -> V_502 )
V_37 -> V_502 -> V_445 = & V_37 -> V_265 ;
V_37 -> V_396 -> V_445 = & V_37 -> V_422 ;
F_377 ( V_37 ) ;
}
static void F_380 ( struct V_12 * V_37 )
{
F_368 ( V_37 , & V_37 -> V_265 , NULL ,
( T_2 ) - 1 ) ;
F_8 ( V_37 -> V_451 . V_60 > 0 ) ;
F_8 ( V_37 -> V_451 . V_10 > 0 ) ;
F_8 ( V_37 -> V_500 . V_60 > 0 ) ;
F_8 ( V_37 -> V_500 . V_10 > 0 ) ;
F_8 ( V_37 -> V_422 . V_60 > 0 ) ;
F_8 ( V_37 -> V_422 . V_10 > 0 ) ;
F_8 ( V_37 -> V_457 . V_60 > 0 ) ;
F_8 ( V_37 -> V_457 . V_10 > 0 ) ;
}
void F_381 ( struct V_117 * V_118 ,
struct V_34 * V_35 )
{
if ( ! V_118 -> V_445 )
return;
if ( ! V_118 -> V_354 )
return;
F_312 ( V_35 -> V_37 , L_14 ,
V_118 -> V_273 , V_118 -> V_354 , 0 ) ;
F_373 ( V_35 , V_118 -> V_445 , V_118 -> V_354 ) ;
V_118 -> V_354 = 0 ;
}
void F_333 ( struct V_117 * V_118 )
{
struct V_12 * V_37 = V_118 -> V_37 ;
if ( ! V_118 -> V_424 )
return;
F_382 ( ! F_182 ( & V_118 -> V_280 ) ) ;
F_368 ( V_37 , & V_37 -> V_422 , NULL ,
V_118 -> V_424 ) ;
V_118 -> V_424 = 0 ;
}
int F_383 ( struct V_117 * V_118 ,
struct V_297 * V_297 )
{
struct V_34 * V_35 = F_259 ( V_297 ) -> V_35 ;
struct V_261 * V_503 = V_118 -> V_445 ;
struct V_261 * V_504 = V_35 -> V_505 ;
T_2 V_36 = F_210 ( V_35 , 1 ) ;
F_312 ( V_35 -> V_37 , L_15 ,
F_384 ( V_297 ) , V_36 , 1 ) ;
return F_369 ( V_503 , V_504 , V_36 , 1 ) ;
}
void F_385 ( struct V_297 * V_297 )
{
struct V_34 * V_35 = F_259 ( V_297 ) -> V_35 ;
T_2 V_36 = F_210 ( V_35 , 1 ) ;
F_312 ( V_35 -> V_37 , L_15 ,
F_384 ( V_297 ) , V_36 , 0 ) ;
F_373 ( V_35 , V_35 -> V_505 , V_36 ) ;
}
int F_386 ( struct V_34 * V_35 ,
struct V_261 * V_497 ,
int V_449 ,
T_2 * V_231 ,
bool V_506 )
{
T_2 V_36 ;
int V_29 ;
struct V_261 * V_262 = & V_35 -> V_37 -> V_265 ;
if ( V_35 -> V_37 -> V_507 ) {
V_36 = 3 * V_35 -> V_55 ;
V_29 = F_387 ( V_35 , V_36 ) ;
if ( V_29 )
return V_29 ;
} else {
V_36 = 0 ;
}
* V_231 = V_36 ;
V_36 = F_210 ( V_35 , V_449 ) ;
V_497 -> V_95 = F_77 ( V_35 -> V_37 ,
V_54 ) ;
V_29 = F_331 ( V_35 , V_497 , V_36 ,
V_435 ) ;
if ( V_29 == - V_313 && V_506 )
V_29 = F_369 ( V_262 , V_497 , V_36 , 1 ) ;
if ( V_29 && * V_231 )
F_388 ( V_35 , * V_231 ) ;
return V_29 ;
}
void F_389 ( struct V_34 * V_35 ,
struct V_261 * V_497 ,
T_2 V_231 )
{
F_373 ( V_35 , V_497 , ( T_2 ) - 1 ) ;
}
static unsigned F_390 ( struct V_297 * V_297 , T_2 V_36 )
{
unsigned V_508 = 0 ;
unsigned V_509 = 0 ;
unsigned V_510 = 0 ;
V_510 = ( unsigned ) F_207 ( V_36 +
V_511 - 1 ,
V_511 ) ;
ASSERT ( V_510 ) ;
ASSERT ( F_259 ( V_297 ) -> V_512 >= V_510 ) ;
F_259 ( V_297 ) -> V_512 -= V_510 ;
if ( F_259 ( V_297 ) -> V_512 == 0 &&
F_391 ( V_513 ,
& F_259 ( V_297 ) -> V_514 ) )
V_508 = 1 ;
if ( F_259 ( V_297 ) -> V_512 >=
F_259 ( V_297 ) -> V_515 )
return V_508 ;
V_509 = F_259 ( V_297 ) -> V_515 -
F_259 ( V_297 ) -> V_512 ;
F_259 ( V_297 ) -> V_515 -= V_509 ;
return V_509 + V_508 ;
}
static T_2 F_392 ( struct V_297 * V_297 , T_2 V_36 ,
int V_516 )
{
struct V_34 * V_35 = F_259 ( V_297 ) -> V_35 ;
T_2 V_517 , V_259 ;
if ( F_259 ( V_297 ) -> V_7 & V_518 &&
F_259 ( V_297 ) -> V_256 == 0 )
return 0 ;
V_517 = F_205 ( V_35 , F_259 ( V_297 ) -> V_256 ) ;
if ( V_516 )
F_259 ( V_297 ) -> V_256 += V_36 ;
else
F_259 ( V_297 ) -> V_256 -= V_36 ;
V_259 = F_205 ( V_35 , F_259 ( V_297 ) -> V_256 ) ;
if ( V_517 == V_259 )
return 0 ;
if ( V_516 )
return F_210 ( V_35 ,
V_259 - V_517 ) ;
return F_210 ( V_35 , V_517 - V_259 ) ;
}
int F_393 ( struct V_297 * V_297 , T_2 V_36 )
{
struct V_34 * V_35 = F_259 ( V_297 ) -> V_35 ;
struct V_261 * V_445 = & V_35 -> V_37 -> V_451 ;
T_2 V_519 = 0 ;
T_2 V_256 ;
unsigned V_520 = 0 ;
enum V_429 V_360 = V_435 ;
int V_29 = 0 ;
bool V_521 = true ;
T_2 V_522 = 0 ;
unsigned V_523 ;
bool V_524 = false ;
if ( F_306 ( V_297 ) ) {
V_360 = V_423 ;
V_521 = false ;
} else if ( V_400 -> V_401 ) {
V_360 = V_525 ;
}
if ( V_360 != V_423 &&
F_394 ( V_35 -> V_37 ) )
F_395 ( 1 ) ;
if ( V_521 )
F_49 ( & F_259 ( V_297 ) -> V_526 ) ;
V_36 = F_149 ( V_36 , V_35 -> V_56 ) ;
F_11 ( & F_259 ( V_297 ) -> V_51 ) ;
V_520 = ( unsigned ) F_207 ( V_36 +
V_511 - 1 ,
V_511 ) ;
F_259 ( V_297 ) -> V_512 += V_520 ;
V_520 = 0 ;
if ( F_259 ( V_297 ) -> V_512 >
F_259 ( V_297 ) -> V_515 )
V_520 += F_259 ( V_297 ) -> V_512 -
F_259 ( V_297 ) -> V_515 ;
V_519 = F_210 ( V_35 , V_520 + 1 ) ;
V_519 += F_392 ( V_297 , V_36 , 1 ) ;
V_256 = F_259 ( V_297 ) -> V_256 ;
F_13 ( & F_259 ( V_297 ) -> V_51 ) ;
if ( V_35 -> V_37 -> V_507 ) {
V_29 = F_387 ( V_35 ,
V_520 * V_35 -> V_55 ) ;
if ( V_29 )
goto V_527;
}
V_29 = F_331 ( V_35 , V_445 , V_519 , V_360 ) ;
if ( F_362 ( V_29 ) ) {
F_388 ( V_35 , V_520 * V_35 -> V_55 ) ;
goto V_527;
}
F_11 ( & F_259 ( V_297 ) -> V_51 ) ;
if ( F_396 ( V_513 ,
& F_259 ( V_297 ) -> V_514 ) ) {
V_519 -= F_210 ( V_35 , 1 ) ;
V_524 = true ;
}
F_259 ( V_297 ) -> V_515 += V_520 ;
F_13 ( & F_259 ( V_297 ) -> V_51 ) ;
if ( V_521 )
F_47 ( & F_259 ( V_297 ) -> V_526 ) ;
if ( V_519 )
F_312 ( V_35 -> V_37 , L_16 ,
F_384 ( V_297 ) , V_519 , 1 ) ;
if ( V_524 )
F_373 ( V_35 , V_445 ,
F_210 ( V_35 ,
1 ) ) ;
return 0 ;
V_527:
F_11 ( & F_259 ( V_297 ) -> V_51 ) ;
V_523 = F_390 ( V_297 , V_36 ) ;
if ( F_259 ( V_297 ) -> V_256 == V_256 ) {
F_392 ( V_297 , V_36 , 0 ) ;
} else {
T_2 V_528 = F_259 ( V_297 ) -> V_256 ;
T_2 V_212 ;
V_212 = V_256 - F_259 ( V_297 ) -> V_256 ;
F_259 ( V_297 ) -> V_256 = V_256 ;
V_522 = F_392 ( V_297 , V_212 , 0 ) ;
F_259 ( V_297 ) -> V_256 = V_256 - V_36 ;
V_212 = V_256 - V_528 ;
V_212 = F_392 ( V_297 , V_212 , 0 ) ;
F_259 ( V_297 ) -> V_256 = V_528 - V_36 ;
if ( V_212 > V_522 )
V_522 = V_212 - V_522 ;
else
V_522 = 0 ;
}
F_13 ( & F_259 ( V_297 ) -> V_51 ) ;
if ( V_523 )
V_522 += F_210 ( V_35 , V_523 ) ;
if ( V_522 ) {
F_373 ( V_35 , V_445 , V_522 ) ;
F_312 ( V_35 -> V_37 , L_16 ,
F_384 ( V_297 ) , V_522 , 0 ) ;
}
if ( V_521 )
F_47 ( & F_259 ( V_297 ) -> V_526 ) ;
return V_29 ;
}
void F_397 ( struct V_297 * V_297 , T_2 V_36 )
{
struct V_34 * V_35 = F_259 ( V_297 ) -> V_35 ;
T_2 V_522 = 0 ;
unsigned V_523 ;
V_36 = F_149 ( V_36 , V_35 -> V_56 ) ;
F_11 ( & F_259 ( V_297 ) -> V_51 ) ;
V_523 = F_390 ( V_297 , V_36 ) ;
if ( V_36 )
V_522 = F_392 ( V_297 , V_36 , 0 ) ;
F_13 ( & F_259 ( V_297 ) -> V_51 ) ;
if ( V_523 > 0 )
V_522 += F_210 ( V_35 , V_523 ) ;
if ( F_239 ( V_35 -> V_37 ) )
return;
F_312 ( V_35 -> V_37 , L_16 ,
F_384 ( V_297 ) , V_522 , 0 ) ;
F_373 ( V_35 , & V_35 -> V_37 -> V_451 ,
V_522 ) ;
}
int F_398 ( struct V_297 * V_297 , T_2 V_32 , T_2 V_48 )
{
int V_29 ;
V_29 = F_264 ( V_297 , V_32 , V_48 ) ;
if ( V_29 < 0 )
return V_29 ;
V_29 = F_393 ( V_297 , V_48 ) ;
if ( V_29 < 0 )
F_316 ( V_297 , V_32 , V_48 ) ;
return V_29 ;
}
void F_399 ( struct V_297 * V_297 , T_2 V_32 , T_2 V_48 )
{
F_397 ( V_297 , V_48 ) ;
F_316 ( V_297 , V_32 , V_48 ) ;
}
static int F_400 ( struct V_117 * V_118 ,
struct V_34 * V_35 , T_2 V_27 ,
T_2 V_36 , int V_402 )
{
struct V_1 * V_2 = NULL ;
struct V_12 * V_13 = V_35 -> V_37 ;
T_2 V_529 = V_36 ;
T_2 V_530 ;
T_2 V_531 ;
int V_342 ;
F_11 ( & V_13 -> V_532 ) ;
V_530 = F_401 ( V_13 -> V_260 ) ;
if ( V_402 )
V_530 += V_36 ;
else
V_530 -= V_36 ;
F_402 ( V_13 -> V_260 , V_530 ) ;
F_13 ( & V_13 -> V_532 ) ;
while ( V_529 ) {
V_2 = F_76 ( V_13 , V_27 ) ;
if ( ! V_2 )
return - V_161 ;
if ( V_2 -> V_7 & ( V_343 |
V_344 |
V_345 ) )
V_342 = 2 ;
else
V_342 = 1 ;
if ( ! V_402 && V_2 -> V_3 == V_103 )
F_59 ( V_2 , 1 ) ;
V_531 = V_27 - V_2 -> V_21 . V_22 ;
F_8 ( V_531 > V_2 -> V_21 . V_33 ) ;
F_11 ( & V_2 -> V_95 -> V_51 ) ;
F_11 ( & V_2 -> V_51 ) ;
if ( F_263 ( V_35 -> V_37 , V_311 ) &&
V_2 -> V_304 < V_320 )
V_2 -> V_304 = V_320 ;
V_530 = F_58 ( & V_2 -> V_96 ) ;
V_36 = F_341 ( V_529 , V_2 -> V_21 . V_33 - V_531 ) ;
if ( V_402 ) {
V_530 += V_36 ;
F_403 ( & V_2 -> V_96 , V_530 ) ;
V_2 -> V_10 -= V_36 ;
V_2 -> V_95 -> V_354 -= V_36 ;
V_2 -> V_95 -> V_94 += V_36 ;
V_2 -> V_95 -> V_347 += V_36 * V_342 ;
F_13 ( & V_2 -> V_51 ) ;
F_13 ( & V_2 -> V_95 -> V_51 ) ;
} else {
V_530 -= V_36 ;
F_403 ( & V_2 -> V_96 , V_530 ) ;
V_2 -> V_9 += V_36 ;
V_2 -> V_95 -> V_353 += V_36 ;
V_2 -> V_95 -> V_94 -= V_36 ;
V_2 -> V_95 -> V_347 -= V_36 * V_342 ;
F_13 ( & V_2 -> V_51 ) ;
F_13 ( & V_2 -> V_95 -> V_51 ) ;
F_312 ( V_35 -> V_37 , L_17 ,
V_2 -> V_95 -> V_7 ,
V_36 , 1 ) ;
F_404 ( V_13 -> V_62 ,
V_27 , V_27 + V_36 - 1 ,
V_98 | V_533 ) ;
}
F_11 ( & V_118 -> V_135 -> V_327 ) ;
if ( F_182 ( & V_2 -> V_329 ) ) {
F_72 ( & V_2 -> V_329 ,
& V_118 -> V_135 -> V_319 ) ;
V_118 -> V_135 -> V_263 ++ ;
F_4 ( V_2 ) ;
}
F_13 ( & V_118 -> V_135 -> V_327 ) ;
if ( ! V_402 && V_530 == 0 ) {
F_11 ( & V_13 -> V_534 ) ;
if ( F_182 ( & V_2 -> V_535 ) ) {
F_4 ( V_2 ) ;
F_72 ( & V_2 -> V_535 ,
& V_13 -> V_536 ) ;
}
F_13 ( & V_13 -> V_534 ) ;
}
F_6 ( V_2 ) ;
V_529 -= V_36 ;
V_27 += V_36 ;
}
return 0 ;
}
static T_2 V_26 ( struct V_34 * V_35 , T_2 V_537 )
{
struct V_1 * V_2 ;
T_2 V_27 ;
F_11 ( & V_35 -> V_37 -> V_18 ) ;
V_27 = V_35 -> V_37 -> V_26 ;
F_13 ( & V_35 -> V_37 -> V_18 ) ;
if ( V_27 < ( T_2 ) - 1 )
return V_27 ;
V_2 = F_75 ( V_35 -> V_37 , V_537 ) ;
if ( ! V_2 )
return 0 ;
V_27 = V_2 -> V_21 . V_22 ;
F_6 ( V_2 ) ;
return V_27 ;
}
static int F_405 ( struct V_34 * V_35 ,
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
F_312 ( V_35 -> V_37 , L_17 ,
V_2 -> V_95 -> V_7 , V_36 , 1 ) ;
F_404 ( V_35 -> V_37 -> V_62 , V_27 ,
V_27 + V_36 - 1 , V_98 | V_533 ) ;
return 0 ;
}
int F_175 ( struct V_34 * V_35 ,
T_2 V_27 , T_2 V_36 , int V_10 )
{
struct V_1 * V_2 ;
V_2 = F_76 ( V_35 -> V_37 , V_27 ) ;
F_32 ( ! V_2 ) ;
F_405 ( V_35 , V_2 , V_27 , V_36 , V_10 ) ;
F_6 ( V_2 ) ;
return 0 ;
}
int F_406 ( struct V_34 * V_35 ,
T_2 V_27 , T_2 V_36 )
{
struct V_1 * V_2 ;
int V_29 ;
V_2 = F_76 ( V_35 -> V_37 , V_27 ) ;
if ( ! V_2 )
return - V_538 ;
F_59 ( V_2 , 1 ) ;
F_405 ( V_35 , V_2 , V_27 , V_36 , 0 ) ;
V_29 = F_28 ( V_2 , V_27 , V_36 ) ;
F_6 ( V_2 ) ;
return V_29 ;
}
static int F_407 ( struct V_34 * V_35 , T_2 V_32 , T_2 V_36 )
{
int V_29 ;
struct V_1 * V_14 ;
struct V_49 * V_52 ;
V_14 = F_76 ( V_35 -> V_37 , V_32 ) ;
if ( ! V_14 )
return - V_538 ;
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
goto V_539;
V_36 = ( V_32 + V_36 ) -
V_52 -> V_85 ;
V_32 = V_52 -> V_85 ;
V_29 = F_17 ( V_35 , V_32 , V_36 ) ;
}
V_539:
F_47 ( & V_52 -> V_86 ) ;
F_26 ( V_52 ) ;
}
F_6 ( V_14 ) ;
return V_29 ;
}
int F_408 ( struct V_34 * log ,
struct V_67 * V_540 )
{
struct V_289 * V_96 ;
struct V_69 V_21 ;
int V_541 ;
int V_42 ;
if ( ! F_84 ( log -> V_37 , V_542 ) )
return 0 ;
for ( V_42 = 0 ; V_42 < F_39 ( V_540 ) ; V_42 ++ ) {
F_41 ( V_540 , & V_21 , V_42 ) ;
if ( V_21 . type != V_294 )
continue;
V_96 = F_86 ( V_540 , V_42 , struct V_289 ) ;
V_541 = F_243 ( V_540 , V_96 ) ;
if ( V_541 == V_295 )
continue;
if ( F_244 ( V_540 , V_96 ) == 0 )
continue;
V_21 . V_22 = F_244 ( V_540 , V_96 ) ;
V_21 . V_33 = F_245 ( V_540 , V_96 ) ;
F_407 ( log , V_21 . V_22 , V_21 . V_33 ) ;
}
return 0 ;
}
static void
F_409 ( struct V_1 * V_335 )
{
F_5 ( & V_335 -> V_543 ) ;
}
void F_410 ( struct V_12 * V_37 ,
const T_2 V_32 )
{
struct V_1 * V_335 ;
V_335 = F_76 ( V_37 , V_32 ) ;
ASSERT ( V_335 ) ;
if ( F_7 ( & V_335 -> V_543 ) )
F_282 ( & V_335 -> V_543 ) ;
F_6 ( V_335 ) ;
}
static int F_411 ( T_7 * V_337 )
{
F_68 () ;
return 0 ;
}
void F_412 ( struct V_1 * V_335 )
{
struct V_111 * V_95 = V_335 -> V_95 ;
ASSERT ( V_335 -> V_306 ) ;
if ( ! ( V_335 -> V_7 & V_338 ) )
return;
F_71 ( & V_95 -> V_352 ) ;
F_73 ( & V_95 -> V_352 ) ;
F_285 ( & V_335 -> V_543 ,
F_411 ,
V_102 ) ;
}
static int F_413 ( struct V_1 * V_2 ,
T_2 V_544 , T_2 V_36 , int V_545 )
{
struct V_111 * V_95 = V_2 -> V_95 ;
int V_29 = 0 ;
F_11 ( & V_95 -> V_51 ) ;
F_11 ( & V_2 -> V_51 ) ;
if ( V_2 -> V_306 ) {
V_29 = - V_187 ;
} else {
V_2 -> V_10 += V_36 ;
V_95 -> V_354 += V_36 ;
F_312 ( V_2 -> V_37 ,
L_10 , V_95 -> V_7 ,
V_544 , 0 ) ;
V_95 -> V_355 -= V_544 ;
if ( V_545 )
V_2 -> V_446 += V_36 ;
}
F_13 ( & V_2 -> V_51 ) ;
F_13 ( & V_95 -> V_51 ) ;
return V_29 ;
}
static int F_414 ( struct V_1 * V_2 ,
T_2 V_36 , int V_545 )
{
struct V_111 * V_95 = V_2 -> V_95 ;
int V_29 = 0 ;
F_11 ( & V_95 -> V_51 ) ;
F_11 ( & V_2 -> V_51 ) ;
if ( V_2 -> V_306 )
V_95 -> V_341 += V_36 ;
V_2 -> V_10 -= V_36 ;
V_95 -> V_354 -= V_36 ;
if ( V_545 )
V_2 -> V_446 -= V_36 ;
F_13 ( & V_2 -> V_51 ) ;
F_13 ( & V_95 -> V_51 ) ;
return V_29 ;
}
void F_415 ( struct V_117 * V_118 ,
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
F_377 ( V_37 ) ;
}
static struct V_546 *
F_416 ( struct V_34 * V_35 , struct V_111 * V_95 ,
T_2 * V_547 )
{
struct V_546 * V_29 = NULL ;
bool V_548 = F_263 ( V_35 -> V_37 , V_549 ) ;
* V_547 = 0 ;
if ( F_332 ( V_95 ) )
return V_29 ;
if ( V_548 )
* V_547 = V_416 ;
if ( V_95 -> V_7 & V_54 ) {
V_29 = & V_35 -> V_37 -> V_550 ;
if ( ! V_548 )
* V_547 = V_551 ;
} else if ( ( V_95 -> V_7 & V_338 ) && V_548 ) {
V_29 = & V_35 -> V_37 -> V_552 ;
}
return V_29 ;
}
static int F_417 ( struct V_34 * V_35 , T_2 V_32 , T_2 V_31 ,
const bool V_553 )
{
struct V_12 * V_37 = V_35 -> V_37 ;
struct V_1 * V_2 = NULL ;
struct V_111 * V_95 ;
struct V_261 * V_262 = & V_37 -> V_265 ;
struct V_546 * V_554 = NULL ;
T_2 V_48 ;
T_2 V_555 = 0 ;
T_2 V_547 = 0 ;
bool V_334 ;
while ( V_32 <= V_31 ) {
V_334 = false ;
if ( ! V_2 ||
V_32 >= V_2 -> V_21 . V_22 + V_2 -> V_21 . V_33 ) {
if ( V_2 )
F_6 ( V_2 ) ;
V_555 = 0 ;
V_2 = F_76 ( V_37 , V_32 ) ;
F_32 ( ! V_2 ) ;
V_554 = F_416 ( V_35 ,
V_2 -> V_95 ,
& V_547 ) ;
V_547 <<= 1 ;
}
V_48 = V_2 -> V_21 . V_22 + V_2 -> V_21 . V_33 - V_32 ;
V_48 = F_341 ( V_48 , V_31 + 1 - V_32 ) ;
if ( V_32 < V_2 -> V_106 ) {
V_48 = F_341 ( V_48 , V_2 -> V_106 - V_32 ) ;
if ( V_553 )
F_31 ( V_2 , V_32 , V_48 ) ;
}
V_32 += V_48 ;
V_555 += V_48 ;
V_95 = V_2 -> V_95 ;
if ( V_554 && V_554 -> V_556 &&
V_555 > V_547 ) {
F_11 ( & V_554 -> V_51 ) ;
V_554 -> V_556 = 0 ;
F_13 ( & V_554 -> V_51 ) ;
}
F_11 ( & V_95 -> V_51 ) ;
F_11 ( & V_2 -> V_51 ) ;
V_2 -> V_9 -= V_48 ;
V_95 -> V_353 -= V_48 ;
F_312 ( V_37 , L_17 ,
V_95 -> V_7 , V_48 , 0 ) ;
V_95 -> V_356 = 0 ;
F_418 ( & V_95 -> V_348 , - V_48 ) ;
if ( V_2 -> V_306 ) {
V_95 -> V_341 += V_48 ;
V_334 = true ;
}
F_13 ( & V_2 -> V_51 ) ;
if ( ! V_334 && V_553 &&
V_262 -> V_95 == V_95 ) {
T_2 V_557 = V_48 ;
F_8 ( ! V_553 ) ;
F_11 ( & V_262 -> V_51 ) ;
if ( ! V_262 -> V_116 ) {
V_557 = F_341 ( V_48 , V_262 -> V_60 -
V_262 -> V_10 ) ;
V_262 -> V_10 += V_557 ;
V_95 -> V_355 += V_557 ;
if ( V_262 -> V_10 >= V_262 -> V_60 )
V_262 -> V_116 = 1 ;
F_312 ( V_37 ,
L_10 ,
V_95 -> V_7 ,
V_557 , 1 ) ;
V_48 -= V_557 ;
}
F_13 ( & V_262 -> V_51 ) ;
if ( V_48 )
F_288 ( V_37 , V_95 ,
V_48 ) ;
}
F_13 ( & V_95 -> V_51 ) ;
}
if ( V_2 )
F_6 ( V_2 ) ;
return 0 ;
}
int F_419 ( struct V_117 * V_118 ,
struct V_34 * V_35 )
{
struct V_12 * V_37 = V_35 -> V_37 ;
struct V_1 * V_14 , * V_316 ;
struct V_112 * V_558 ;
struct V_559 * V_560 ;
T_2 V_32 ;
T_2 V_31 ;
int V_29 ;
if ( V_37 -> V_62 == & V_37 -> V_38 [ 0 ] )
V_560 = & V_37 -> V_38 [ 1 ] ;
else
V_560 = & V_37 -> V_38 [ 0 ] ;
while ( ! V_118 -> V_228 ) {
F_49 ( & V_37 -> V_561 ) ;
V_29 = F_30 ( V_560 , 0 , & V_32 , & V_31 ,
V_63 , NULL ) ;
if ( V_29 ) {
F_47 ( & V_37 -> V_561 ) ;
break;
}
if ( F_263 ( V_35 -> V_37 , V_562 ) )
V_29 = F_153 ( V_35 , V_32 ,
V_31 + 1 - V_32 , NULL ) ;
F_420 ( V_560 , V_32 , V_31 ) ;
F_417 ( V_35 , V_32 , V_31 , true ) ;
F_47 ( & V_37 -> V_561 ) ;
F_48 () ;
}
V_558 = & V_118 -> V_135 -> V_558 ;
F_269 (block_group, tmp, deleted_bgs, bg_list) {
T_2 V_563 = 0 ;
V_29 = - V_564 ;
if ( ! V_118 -> V_228 )
V_29 = F_153 ( V_35 ,
V_14 -> V_21 . V_22 ,
V_14 -> V_21 . V_33 ,
& V_563 ) ;
F_274 ( & V_14 -> V_535 ) ;
F_421 ( V_14 ) ;
F_6 ( V_14 ) ;
if ( V_29 ) {
const char * V_565 = F_422 ( V_29 ) ;
F_423 ( V_37 ,
L_18 ,
V_29 , V_565 ) ;
}
}
return 0 ;
}
static void F_424 ( struct V_12 * V_37 , T_2 V_36 ,
T_2 V_141 , T_2 V_153 )
{
struct V_111 * V_95 ;
T_2 V_7 ;
if ( V_141 < V_150 ) {
if ( V_153 == V_566 )
V_7 = V_339 ;
else
V_7 = V_54 ;
} else {
V_7 = V_338 ;
}
V_95 = F_77 ( V_37 , V_7 ) ;
F_32 ( ! V_95 ) ;
F_418 ( & V_95 -> V_348 , V_36 ) ;
}
static int F_167 ( struct V_117 * V_118 ,
struct V_34 * V_35 ,
struct V_219 * V_136 , T_2 V_17 ,
T_2 V_153 , T_2 V_567 ,
T_2 V_568 , int V_168 ,
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
int V_569 = 0 ;
int V_570 = 0 ;
int V_571 = 1 ;
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
V_193 = V_567 >= V_150 ;
F_32 ( ! V_193 && V_168 != 1 ) ;
if ( V_193 )
V_182 = 0 ;
V_29 = F_142 ( V_118 , V_64 , V_66 , & V_173 ,
V_27 , V_36 , V_17 ,
V_153 , V_567 ,
V_568 ) ;
if ( V_29 == 0 ) {
V_569 = V_66 -> V_83 [ 0 ] ;
while ( V_569 >= 0 ) {
F_41 ( V_66 -> V_82 [ 0 ] , & V_21 ,
V_569 ) ;
if ( V_21 . V_22 != V_27 )
break;
if ( V_21 . type == V_79 &&
V_21 . V_33 == V_36 ) {
V_570 = 1 ;
break;
}
if ( V_21 . type == V_87 &&
V_21 . V_33 == V_567 ) {
V_570 = 1 ;
break;
}
if ( V_66 -> V_83 [ 0 ] - V_569 > 5 )
break;
V_569 -- ;
}
#ifdef F_89
V_126 = F_85 ( V_66 -> V_82 [ 0 ] , V_569 ) ;
if ( V_570 && V_126 < sizeof( * V_125 ) )
V_570 = 0 ;
#endif
if ( ! V_570 ) {
F_32 ( V_173 ) ;
V_29 = F_147 ( V_118 , V_64 , V_66 ,
NULL , V_168 ,
V_193 , & V_169 ) ;
if ( V_29 ) {
F_162 ( V_118 , V_29 ) ;
goto V_81;
}
F_45 ( V_66 ) ;
V_66 -> V_220 = 1 ;
V_21 . V_22 = V_27 ;
V_21 . type = V_79 ;
V_21 . V_33 = V_36 ;
if ( ! V_193 && V_182 ) {
V_21 . type = V_87 ;
V_21 . V_33 = V_567 ;
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
F_425 ( V_13 , L_19 ,
V_29 , V_27 ) ;
if ( V_29 > 0 )
F_426 ( V_64 ,
V_66 -> V_82 [ 0 ] ) ;
}
if ( V_29 < 0 ) {
F_162 ( V_118 , V_29 ) ;
goto V_81;
}
V_569 = V_66 -> V_83 [ 0 ] ;
}
} else if ( F_8 ( V_29 == - V_161 ) ) {
F_426 ( V_64 , V_66 -> V_82 [ 0 ] ) ;
F_425 ( V_13 ,
L_20 ,
V_27 , V_17 , V_153 , V_567 ,
V_568 ) ;
F_162 ( V_118 , V_29 ) ;
goto V_81;
} else {
F_162 ( V_118 , V_29 ) ;
goto V_81;
}
V_68 = V_66 -> V_82 [ 0 ] ;
V_126 = F_85 ( V_68 , V_569 ) ;
#ifdef F_89
if ( V_126 < sizeof( * V_125 ) ) {
F_32 ( V_570 || V_569 != V_66 -> V_83 [ 0 ] ) ;
V_29 = F_95 ( V_118 , V_64 , V_66 ,
V_567 , 0 ) ;
if ( V_29 < 0 ) {
F_162 ( V_118 , V_29 ) ;
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
F_425 ( V_13 , L_19 ,
V_29 , V_27 ) ;
F_426 ( V_64 , V_66 -> V_82 [ 0 ] ) ;
}
if ( V_29 < 0 ) {
F_162 ( V_118 , V_29 ) ;
goto V_81;
}
V_569 = V_66 -> V_83 [ 0 ] ;
V_68 = V_66 -> V_82 [ 0 ] ;
V_126 = F_85 ( V_68 , V_569 ) ;
}
#endif
F_32 ( V_126 < sizeof( * V_125 ) ) ;
V_125 = F_86 ( V_68 , V_569 ,
struct V_124 ) ;
if ( V_567 < V_150 &&
V_21 . type == V_79 ) {
struct V_145 * V_146 ;
F_32 ( V_126 < sizeof( * V_125 ) + sizeof( * V_146 ) ) ;
V_146 = (struct V_145 * ) ( V_125 + 1 ) ;
F_8 ( V_567 != F_427 ( V_68 , V_146 ) ) ;
}
V_120 = F_87 ( V_68 , V_125 ) ;
if ( V_120 < V_168 ) {
F_425 ( V_13 , L_21
L_22 , V_168 , V_120 , V_27 ) ;
V_29 = - V_538 ;
F_162 ( V_118 , V_29 ) ;
goto V_81;
}
V_120 -= V_168 ;
if ( V_120 > 0 ) {
if ( V_137 )
F_138 ( V_137 , V_68 , V_125 ) ;
if ( V_173 ) {
F_32 ( ! V_570 ) ;
} else {
F_98 ( V_68 , V_125 , V_120 ) ;
F_103 ( V_68 ) ;
}
if ( V_570 ) {
V_29 = F_147 ( V_118 , V_64 , V_66 ,
V_173 , V_168 ,
V_193 , & V_169 ) ;
if ( V_29 ) {
F_162 ( V_118 , V_29 ) ;
goto V_81;
}
}
F_424 ( V_35 -> V_37 , - V_36 , V_567 ,
V_153 ) ;
} else {
if ( V_570 ) {
F_32 ( V_193 && V_168 !=
F_126 ( V_66 , V_173 ) ) ;
if ( V_173 ) {
F_32 ( V_66 -> V_83 [ 0 ] != V_569 ) ;
} else {
F_32 ( V_66 -> V_83 [ 0 ] != V_569 + 1 ) ;
V_66 -> V_83 [ 0 ] = V_569 ;
V_571 = 2 ;
}
}
V_169 = 1 ;
V_29 = F_428 ( V_118 , V_64 , V_66 , V_66 -> V_83 [ 0 ] ,
V_571 ) ;
if ( V_29 ) {
F_162 ( V_118 , V_29 ) ;
goto V_81;
}
F_45 ( V_66 ) ;
if ( V_193 ) {
V_29 = F_179 ( V_118 , V_35 , V_27 , V_36 ) ;
if ( V_29 ) {
F_162 ( V_118 , V_29 ) ;
goto V_81;
}
}
V_29 = F_429 ( V_118 , V_35 -> V_37 , V_27 ,
V_36 ) ;
if ( V_29 ) {
F_162 ( V_118 , V_29 ) ;
goto V_81;
}
V_29 = F_400 ( V_118 , V_35 , V_27 , V_36 , 0 ) ;
if ( V_29 ) {
F_162 ( V_118 , V_29 ) ;
goto V_81;
}
}
F_45 ( V_66 ) ;
V_81:
F_53 ( V_66 ) ;
return V_29 ;
}
static T_1 int F_430 ( struct V_117 * V_118 ,
struct V_34 * V_35 , T_2 V_27 )
{
struct V_121 * V_113 ;
struct V_122 * V_123 ;
int V_29 = 0 ;
V_123 = & V_118 -> V_135 -> V_123 ;
F_11 ( & V_123 -> V_51 ) ;
V_113 = F_92 ( V_118 , V_27 ) ;
if ( ! V_113 )
goto V_572;
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
V_572:
F_13 ( & V_123 -> V_51 ) ;
return 0 ;
}
void F_431 ( struct V_117 * V_118 ,
struct V_34 * V_35 ,
struct V_67 * V_286 ,
T_2 V_17 , int V_169 )
{
int V_573 = 1 ;
int V_29 ;
if ( V_35 -> V_282 . V_22 != V_217 ) {
V_29 = F_159 ( V_35 -> V_37 , V_118 ,
V_286 -> V_32 , V_286 -> V_48 ,
V_17 , V_35 -> V_282 . V_22 ,
F_241 ( V_286 ) ,
V_226 , NULL ) ;
F_32 ( V_29 ) ;
}
if ( ! V_169 )
return;
if ( F_432 ( V_286 ) == V_118 -> V_273 ) {
struct V_1 * V_2 ;
if ( V_35 -> V_282 . V_22 != V_217 ) {
V_29 = F_430 ( V_118 , V_35 , V_286 -> V_32 ) ;
if ( ! V_29 )
goto V_81;
}
V_2 = F_76 ( V_35 -> V_37 , V_286 -> V_32 ) ;
if ( F_433 ( V_286 , V_574 ) ) {
F_405 ( V_35 , V_2 , V_286 -> V_32 , V_286 -> V_48 , 1 ) ;
F_6 ( V_2 ) ;
goto V_81;
}
F_8 ( F_242 ( V_575 , & V_286 -> V_576 ) ) ;
F_31 ( V_2 , V_286 -> V_32 , V_286 -> V_48 ) ;
F_414 ( V_2 , V_286 -> V_48 , 0 ) ;
F_6 ( V_2 ) ;
F_434 ( V_35 , V_286 -> V_32 , V_286 -> V_48 ) ;
V_573 = 0 ;
}
V_81:
if ( V_573 )
F_424 ( V_35 -> V_37 , V_286 -> V_48 ,
F_241 ( V_286 ) ,
V_35 -> V_282 . V_22 ) ;
F_435 ( V_577 , & V_286 -> V_576 ) ;
}
int V_293 ( struct V_117 * V_118 , struct V_34 * V_35 ,
T_2 V_27 , T_2 V_36 , T_2 V_17 , T_2 V_153 ,
T_2 V_141 , T_2 V_33 )
{
int V_29 ;
struct V_12 * V_37 = V_35 -> V_37 ;
if ( F_239 ( V_37 ) )
return 0 ;
F_424 ( V_35 -> V_37 , V_36 , V_141 , V_153 ) ;
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
F_436 ( struct V_1 * V_2 ,
T_2 V_36 )
{
struct V_49 * V_52 ;
V_52 = F_25 ( V_2 ) ;
if ( ! V_52 )
return;
F_278 ( V_52 -> V_90 , F_1 ( V_2 ) ||
( V_2 -> V_11 -> V_578 >= V_36 ) ) ;
F_26 ( V_52 ) ;
}
static T_1 int
F_437 ( struct V_1 * V_2 )
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
int F_438 ( T_2 V_7 )
{
if ( V_7 & V_345 )
return V_579 ;
else if ( V_7 & V_344 )
return V_580 ;
else if ( V_7 & V_343 )
return V_581 ;
else if ( V_7 & V_393 )
return V_582 ;
else if ( V_7 & V_392 )
return V_583 ;
else if ( V_7 & V_391 )
return V_584 ;
return V_585 ;
}
int F_439 ( struct V_1 * V_2 )
{
return F_438 ( V_2 -> V_7 ) ;
}
static const char * F_440 ( enum V_586 type )
{
if ( type >= V_350 )
return NULL ;
return V_587 [ type ] ;
}
static inline void
F_441 ( struct V_1 * V_2 ,
int V_545 )
{
if ( V_545 )
F_50 ( & V_2 -> V_588 ) ;
}
static inline void
F_442 ( struct V_1 * V_2 ,
int V_545 )
{
F_4 ( V_2 ) ;
if ( V_545 )
F_50 ( & V_2 -> V_588 ) ;
}
static struct V_1 *
F_443 ( struct V_1 * V_14 ,
struct V_546 * V_554 ,
int V_545 )
{
struct V_1 * V_589 = NULL ;
F_11 ( & V_554 -> V_590 ) ;
while ( 1 ) {
V_589 = V_554 -> V_14 ;
if ( ! V_589 )
return NULL ;
if ( V_589 == V_14 )
return V_589 ;
F_4 ( V_589 ) ;
if ( ! V_545 )
return V_589 ;
if ( F_336 ( & V_589 -> V_588 ) )
return V_589 ;
F_13 ( & V_554 -> V_590 ) ;
F_50 ( & V_589 -> V_588 ) ;
F_11 ( & V_554 -> V_590 ) ;
if ( V_589 == V_554 -> V_14 )
return V_589 ;
F_46 ( & V_589 -> V_588 ) ;
F_6 ( V_589 ) ;
}
}
static inline void
F_444 ( struct V_1 * V_2 ,
int V_545 )
{
if ( V_545 )
F_46 ( & V_2 -> V_588 ) ;
F_6 ( V_2 ) ;
}
static T_1 int F_445 ( struct V_34 * V_591 ,
T_2 V_544 , T_2 V_36 , T_2 V_592 ,
T_2 V_593 , struct V_69 * V_223 ,
T_2 V_7 , int V_545 )
{
int V_29 = 0 ;
struct V_34 * V_35 = V_591 -> V_37 -> V_64 ;
struct V_546 * V_594 = NULL ;
struct V_1 * V_14 = NULL ;
T_2 V_537 = 0 ;
T_2 V_356 = 0 ;
T_2 V_547 = 0 ;
struct V_111 * V_95 ;
int V_595 = 0 ;
int V_596 = F_438 ( V_7 ) ;
bool V_597 = false ;
bool V_598 = false ;
bool V_599 = true ;
bool V_600 = false ;
bool V_601 = false ;
bool V_602 = false ;
F_8 ( V_36 < V_35 -> V_56 ) ;
V_223 -> type = V_79 ;
V_223 -> V_22 = 0 ;
V_223 -> V_33 = 0 ;
F_446 ( V_591 , V_36 , V_592 , V_7 ) ;
V_95 = F_77 ( V_35 -> V_37 , V_7 ) ;
if ( ! V_95 ) {
F_425 ( V_35 -> V_37 , L_23 , V_7 ) ;
return - V_313 ;
}
if ( F_362 ( V_95 -> V_356 ) ) {
F_11 ( & V_95 -> V_51 ) ;
if ( V_95 -> V_356 &&
V_36 > V_95 -> V_356 ) {
V_223 -> V_33 = V_95 -> V_356 ;
F_13 ( & V_95 -> V_51 ) ;
return - V_313 ;
} else if ( V_95 -> V_356 ) {
V_599 = false ;
}
F_13 ( & V_95 -> V_51 ) ;
}
V_594 = F_416 ( V_591 , V_95 , & V_547 ) ;
if ( V_594 ) {
F_11 ( & V_594 -> V_51 ) ;
if ( V_594 -> V_14 )
V_593 = V_594 -> V_603 ;
if ( V_594 -> V_556 ) {
V_593 = V_594 -> V_603 ;
V_599 = false ;
}
F_13 ( & V_594 -> V_51 ) ;
}
V_537 = F_447 ( V_537 , V_26 ( V_35 , 0 ) ) ;
V_537 = F_447 ( V_537 , V_593 ) ;
if ( V_537 == V_593 ) {
V_14 = F_76 ( V_35 -> V_37 ,
V_537 ) ;
if ( V_14 && F_3 ( V_14 , V_7 ) &&
V_14 -> V_3 != V_103 ) {
F_50 ( & V_95 -> V_352 ) ;
if ( F_182 ( & V_14 -> V_99 ) ||
V_14 -> V_306 ) {
F_6 ( V_14 ) ;
F_46 ( & V_95 -> V_352 ) ;
} else {
V_596 = F_439 ( V_14 ) ;
F_441 ( V_14 , V_545 ) ;
goto V_604;
}
} else if ( V_14 ) {
F_6 ( V_14 ) ;
}
}
V_605:
V_600 = false ;
if ( V_596 == 0 || V_596 == F_438 ( V_7 ) )
V_602 = true ;
F_50 ( & V_95 -> V_352 ) ;
F_183 (block_group, &space_info->block_groups[index],
list) {
T_2 V_33 ;
int V_3 ;
F_442 ( V_14 , V_545 ) ;
V_537 = V_14 -> V_21 . V_22 ;
if ( ! F_3 ( V_14 , V_7 ) ) {
T_2 V_606 = V_343 |
V_344 |
V_392 |
V_391 |
V_345 ;
if ( ( V_7 & V_606 ) && ! ( V_14 -> V_7 & V_606 ) )
goto V_595;
}
V_604:
V_3 = F_1 ( V_14 ) ;
if ( F_362 ( ! V_3 ) ) {
V_600 = true ;
V_29 = F_59 ( V_14 , 0 ) ;
F_32 ( V_29 < 0 ) ;
V_29 = 0 ;
}
if ( F_362 ( V_14 -> V_3 == V_5 ) )
goto V_595;
if ( F_362 ( V_14 -> V_306 ) )
goto V_595;
if ( V_594 && V_599 ) {
struct V_1 * V_607 ;
unsigned long V_608 ;
V_607 = F_443 ( V_14 ,
V_594 ,
V_545 ) ;
if ( ! V_607 )
goto V_609;
if ( V_607 != V_14 &&
( V_607 -> V_306 ||
! F_3 ( V_607 , V_7 ) ) )
goto V_610;
V_33 = F_448 ( V_607 ,
V_594 ,
V_36 ,
V_607 -> V_21 . V_22 ,
& V_356 ) ;
if ( V_33 ) {
F_13 ( & V_594 -> V_590 ) ;
F_449 ( V_35 ,
V_607 ,
V_537 , V_36 ) ;
if ( V_607 != V_14 ) {
F_444 ( V_14 ,
V_545 ) ;
V_14 = V_607 ;
}
goto V_611;
}
F_8 ( V_594 -> V_14 != V_607 ) ;
V_610:
if ( V_595 >= V_612 &&
V_607 != V_14 ) {
F_13 ( & V_594 -> V_590 ) ;
F_444 ( V_607 ,
V_545 ) ;
goto V_613;
}
F_450 ( NULL , V_594 ) ;
if ( V_607 != V_14 )
F_444 ( V_607 ,
V_545 ) ;
V_609:
if ( V_595 >= V_612 ) {
F_13 ( & V_594 -> V_590 ) ;
goto V_613;
}
V_608 = F_35 (unsigned long,
empty_cluster + empty_size,
block_group->full_stripe_len) ;
V_29 = F_451 ( V_35 , V_14 ,
V_594 , V_537 ,
V_36 ,
V_608 ) ;
if ( V_29 == 0 ) {
V_33 = F_448 ( V_14 ,
V_594 ,
V_36 ,
V_537 ,
& V_356 ) ;
if ( V_33 ) {
F_13 ( & V_594 -> V_590 ) ;
F_449 ( V_35 ,
V_14 , V_537 ,
V_36 ) ;
goto V_611;
}
} else if ( ! V_3 && V_595 > V_614
&& ! V_597 ) {
F_13 ( & V_594 -> V_590 ) ;
V_597 = true ;
F_436 ( V_14 ,
V_36 + V_547 + V_592 ) ;
goto V_604;
}
F_450 ( NULL , V_594 ) ;
F_13 ( & V_594 -> V_590 ) ;
goto V_595;
}
V_613:
if ( F_362 ( V_594 ) ) {
F_11 ( & V_594 -> V_51 ) ;
V_594 -> V_556 = 1 ;
F_13 ( & V_594 -> V_51 ) ;
}
F_11 ( & V_14 -> V_11 -> V_615 ) ;
if ( V_3 &&
V_14 -> V_11 -> V_578 <
V_36 + V_547 + V_592 ) {
if ( V_14 -> V_11 -> V_578 >
V_356 )
V_356 =
V_14 -> V_11 -> V_578 ;
F_13 ( & V_14 -> V_11 -> V_615 ) ;
goto V_595;
}
F_13 ( & V_14 -> V_11 -> V_615 ) ;
V_33 = F_452 ( V_14 , V_537 ,
V_36 , V_592 ,
& V_356 ) ;
if ( ! V_33 && ! V_598 && ! V_3 &&
V_595 > V_614 ) {
F_436 ( V_14 ,
V_36 + V_592 ) ;
V_598 = true ;
goto V_604;
} else if ( ! V_33 ) {
goto V_595;
}
V_611:
V_537 = F_149 ( V_33 , V_35 -> V_616 ) ;
if ( V_537 + V_36 >
V_14 -> V_21 . V_22 + V_14 -> V_21 . V_33 ) {
F_31 ( V_14 , V_33 , V_36 ) ;
goto V_595;
}
if ( V_33 < V_537 )
F_31 ( V_14 , V_33 ,
V_537 - V_33 ) ;
F_32 ( V_33 > V_537 ) ;
V_29 = F_413 ( V_14 , V_544 ,
V_36 , V_545 ) ;
if ( V_29 == - V_187 ) {
F_31 ( V_14 , V_33 , V_36 ) ;
goto V_595;
}
F_409 ( V_14 ) ;
V_223 -> V_22 = V_537 ;
V_223 -> V_33 = V_36 ;
F_453 ( V_591 , V_14 ,
V_537 , V_36 ) ;
F_444 ( V_14 , V_545 ) ;
break;
V_595:
V_597 = false ;
V_598 = false ;
F_32 ( V_596 != F_439 ( V_14 ) ) ;
F_444 ( V_14 , V_545 ) ;
}
F_46 ( & V_95 -> V_352 ) ;
if ( ( V_595 == V_614 ) && V_600
&& ! V_601 )
V_601 = true ;
if ( ! V_223 -> V_22 && V_595 >= V_617 && V_600 )
goto V_605;
if ( ! V_223 -> V_22 && ++ V_596 < V_350 )
goto V_605;
if ( ! V_223 -> V_22 && V_595 < V_612 ) {
V_596 = 0 ;
if ( V_595 == V_614 ) {
if ( V_601 || ! V_602 )
V_595 = V_617 ;
else
V_595 = V_618 ;
} else {
V_595 ++ ;
}
if ( V_595 == V_618 ) {
struct V_117 * V_118 ;
int V_619 = 0 ;
V_118 = V_400 -> V_401 ;
if ( V_118 )
V_619 = 1 ;
else
V_118 = F_215 ( V_35 ) ;
if ( F_216 ( V_118 ) ) {
V_29 = F_217 ( V_118 ) ;
goto V_81;
}
V_29 = F_307 ( V_118 , V_35 , V_7 ,
V_404 ) ;
if ( V_29 == - V_313 )
V_595 = V_612 ;
if ( V_29 < 0 && V_29 != - V_313 )
F_162 ( V_118 , V_29 ) ;
else
V_29 = 0 ;
if ( ! V_619 )
F_219 ( V_118 , V_35 ) ;
if ( V_29 )
goto V_81;
}
if ( V_595 == V_612 ) {
if ( V_592 == 0 &&
V_547 == 0 ) {
V_29 = - V_313 ;
goto V_81;
}
V_592 = 0 ;
V_547 = 0 ;
}
goto V_605;
} else if ( ! V_223 -> V_22 ) {
V_29 = - V_313 ;
} else if ( V_223 -> V_22 ) {
if ( ! V_599 && V_594 ) {
F_11 ( & V_594 -> V_51 ) ;
V_594 -> V_603 = V_223 -> V_22 ;
F_13 ( & V_594 -> V_51 ) ;
}
V_29 = 0 ;
}
V_81:
if ( V_29 == - V_313 ) {
F_11 ( & V_95 -> V_51 ) ;
V_95 -> V_356 = V_356 ;
F_13 ( & V_95 -> V_51 ) ;
V_223 -> V_33 = V_356 ;
}
return V_29 ;
}
static void F_329 ( struct V_111 * V_13 , T_2 V_212 ,
int V_620 )
{
struct V_1 * V_2 ;
int V_596 = 0 ;
F_11 ( & V_13 -> V_51 ) ;
F_454 ( V_621 L_24 ,
V_13 -> V_7 ,
V_13 -> V_340 - V_13 -> V_94 - V_13 -> V_353 -
V_13 -> V_354 - V_13 -> V_341 -
V_13 -> V_355 , ( V_13 -> V_116 ) ? L_25 : L_26 ) ;
F_454 ( V_621 L_27
L_28 ,
V_13 -> V_340 , V_13 -> V_94 , V_13 -> V_353 ,
V_13 -> V_354 , V_13 -> V_355 ,
V_13 -> V_341 ) ;
F_13 ( & V_13 -> V_51 ) ;
if ( ! V_620 )
return;
F_50 ( & V_13 -> V_352 ) ;
V_164:
F_183 (cache, &info->block_groups[index], list) {
F_11 ( & V_2 -> V_51 ) ;
F_454 ( V_621 L_29
L_30
L_31 ,
V_2 -> V_21 . V_22 , V_2 -> V_21 . V_33 ,
F_58 ( & V_2 -> V_96 ) , V_2 -> V_9 ,
V_2 -> V_10 , V_2 -> V_306 ? L_32 : L_25 ) ;
F_455 ( V_2 , V_212 ) ;
F_13 ( & V_2 -> V_51 ) ;
}
if ( ++ V_596 < V_350 )
goto V_164;
F_46 ( & V_13 -> V_352 ) ;
}
int F_456 ( struct V_34 * V_35 , T_2 V_544 ,
T_2 V_36 , T_2 V_622 ,
T_2 V_592 , T_2 V_593 ,
struct V_69 * V_223 , int V_193 , int V_545 )
{
bool V_623 = V_36 == V_622 ;
T_2 V_7 ;
int V_29 ;
V_7 = F_304 ( V_35 , V_193 ) ;
V_164:
F_8 ( V_36 < V_35 -> V_56 ) ;
V_29 = F_445 ( V_35 , V_544 , V_36 , V_592 ,
V_593 , V_223 , V_7 , V_545 ) ;
if ( ! V_29 && ! V_193 ) {
F_410 ( V_35 -> V_37 ,
V_223 -> V_22 ) ;
} else if ( V_29 == - V_313 ) {
if ( ! V_623 && V_223 -> V_33 ) {
V_36 = F_341 ( V_36 >> 1 , V_223 -> V_33 ) ;
V_36 = F_150 ( V_36 , V_35 -> V_56 ) ;
V_36 = F_447 ( V_36 , V_622 ) ;
V_544 = V_36 ;
if ( V_36 == V_622 )
V_623 = true ;
goto V_164;
} else if ( F_263 ( V_35 -> V_37 , V_421 ) ) {
struct V_111 * V_410 ;
V_410 = F_77 ( V_35 -> V_37 , V_7 ) ;
F_425 ( V_35 -> V_37 , L_33 ,
V_7 , V_36 ) ;
if ( V_410 )
F_329 ( V_410 , V_36 , 1 ) ;
}
}
return V_29 ;
}
static int F_457 ( struct V_34 * V_35 ,
T_2 V_32 , T_2 V_48 ,
int V_573 , int V_545 )
{
struct V_1 * V_2 ;
int V_29 = 0 ;
V_2 = F_76 ( V_35 -> V_37 , V_32 ) ;
if ( ! V_2 ) {
F_425 ( V_35 -> V_37 , L_34 ,
V_32 ) ;
return - V_313 ;
}
if ( V_573 )
F_405 ( V_35 , V_2 , V_32 , V_48 , 1 ) ;
else {
if ( F_263 ( V_35 -> V_37 , V_562 ) )
V_29 = F_153 ( V_35 , V_32 , V_48 , NULL ) ;
F_31 ( V_2 , V_32 , V_48 ) ;
F_414 ( V_2 , V_48 , V_545 ) ;
F_434 ( V_35 , V_32 , V_48 ) ;
}
F_6 ( V_2 ) ;
return V_29 ;
}
int F_458 ( struct V_34 * V_35 ,
T_2 V_32 , T_2 V_48 , int V_545 )
{
return F_457 ( V_35 , V_32 , V_48 , 0 , V_545 ) ;
}
int F_459 ( struct V_34 * V_35 ,
T_2 V_32 , T_2 V_48 )
{
return F_457 ( V_35 , V_32 , V_48 , 1 , 0 ) ;
}
static int F_166 ( struct V_117 * V_118 ,
struct V_34 * V_35 ,
T_2 V_17 , T_2 V_153 ,
T_2 V_7 , T_2 V_141 , T_2 V_33 ,
struct V_69 * V_223 , int V_140 )
{
int V_29 ;
struct V_12 * V_37 = V_35 -> V_37 ;
struct V_124 * V_624 ;
struct V_172 * V_173 ;
struct V_65 * V_66 ;
struct V_67 * V_68 ;
int type ;
T_3 V_60 ;
if ( V_17 > 0 )
type = V_162 ;
else
type = V_163 ;
V_60 = sizeof( * V_624 ) + F_133 ( type ) ;
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
V_624 = F_86 ( V_68 , V_66 -> V_83 [ 0 ] ,
struct V_124 ) ;
F_98 ( V_68 , V_624 , V_140 ) ;
F_99 ( V_68 , V_624 , V_118 -> V_273 ) ;
F_100 ( V_68 , V_624 ,
V_7 | V_152 ) ;
V_173 = (struct V_172 * ) ( V_624 + 1 ) ;
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
V_29 = F_460 ( V_118 , V_37 , V_223 -> V_22 ,
V_223 -> V_33 ) ;
if ( V_29 )
return V_29 ;
V_29 = F_400 ( V_118 , V_35 , V_223 -> V_22 , V_223 -> V_33 , 1 ) ;
if ( V_29 ) {
F_425 ( V_37 , L_35 ,
V_223 -> V_22 , V_223 -> V_33 ) ;
F_91 () ;
}
F_461 ( V_35 , V_223 -> V_22 , V_223 -> V_33 ) ;
return V_29 ;
}
static int F_173 ( struct V_117 * V_118 ,
struct V_34 * V_35 ,
T_2 V_17 , T_2 V_153 ,
T_2 V_7 , struct V_625 * V_21 ,
int V_176 , struct V_69 * V_223 )
{
int V_29 ;
struct V_12 * V_37 = V_35 -> V_37 ;
struct V_124 * V_624 ;
struct V_145 * V_626 ;
struct V_172 * V_173 ;
struct V_65 * V_66 ;
struct V_67 * V_68 ;
T_3 V_60 = sizeof( * V_624 ) + sizeof( * V_173 ) ;
T_2 V_36 = V_223 -> V_33 ;
bool V_182 = F_84 ( V_35 -> V_37 ,
V_129 ) ;
if ( ! V_182 )
V_60 += sizeof( * V_626 ) ;
V_66 = F_34 () ;
if ( ! V_66 ) {
F_459 ( V_35 , V_223 -> V_22 ,
V_35 -> V_55 ) ;
return - V_74 ;
}
V_66 -> V_220 = 1 ;
V_29 = F_114 ( V_118 , V_37 -> V_64 , V_66 ,
V_223 , V_60 ) ;
if ( V_29 ) {
F_53 ( V_66 ) ;
F_459 ( V_35 , V_223 -> V_22 ,
V_35 -> V_55 ) ;
return V_29 ;
}
V_68 = V_66 -> V_82 [ 0 ] ;
V_624 = F_86 ( V_68 , V_66 -> V_83 [ 0 ] ,
struct V_124 ) ;
F_98 ( V_68 , V_624 , 1 ) ;
F_99 ( V_68 , V_624 , V_118 -> V_273 ) ;
F_100 ( V_68 , V_624 ,
V_7 | V_151 ) ;
if ( V_182 ) {
V_173 = (struct V_172 * ) ( V_624 + 1 ) ;
V_36 = V_35 -> V_55 ;
} else {
V_626 = (struct V_145 * ) ( V_624 + 1 ) ;
F_168 ( V_68 , V_626 , V_21 ) ;
F_102 ( V_68 , V_626 , V_176 ) ;
V_173 = (struct V_172 * ) ( V_626 + 1 ) ;
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
V_29 = F_460 ( V_118 , V_37 , V_223 -> V_22 ,
V_36 ) ;
if ( V_29 )
return V_29 ;
V_29 = F_400 ( V_118 , V_35 , V_223 -> V_22 , V_35 -> V_55 ,
1 ) ;
if ( V_29 ) {
F_425 ( V_37 , L_35 ,
V_223 -> V_22 , V_223 -> V_33 ) ;
F_91 () ;
}
F_461 ( V_35 , V_223 -> V_22 , V_35 -> V_55 ) ;
return V_29 ;
}
int F_462 ( struct V_117 * V_118 ,
struct V_34 * V_35 ,
T_2 V_153 , T_2 V_141 ,
T_2 V_33 , T_2 V_544 ,
struct V_69 * V_223 )
{
int V_29 ;
F_32 ( V_153 == V_217 ) ;
V_29 = F_160 ( V_35 -> V_37 , V_118 , V_223 -> V_22 ,
V_223 -> V_33 , 0 ,
V_153 , V_141 , V_33 ,
V_544 , V_244 ,
NULL ) ;
return V_29 ;
}
int F_463 ( struct V_117 * V_118 ,
struct V_34 * V_35 ,
T_2 V_153 , T_2 V_141 , T_2 V_33 ,
struct V_69 * V_223 )
{
int V_29 ;
struct V_1 * V_14 ;
struct V_111 * V_95 ;
if ( ! F_84 ( V_35 -> V_37 , V_542 ) ) {
V_29 = F_407 ( V_35 , V_223 -> V_22 , V_223 -> V_33 ) ;
if ( V_29 )
return V_29 ;
}
V_14 = F_76 ( V_35 -> V_37 , V_223 -> V_22 ) ;
if ( ! V_14 )
return - V_538 ;
V_95 = V_14 -> V_95 ;
F_11 ( & V_95 -> V_51 ) ;
F_11 ( & V_14 -> V_51 ) ;
V_95 -> V_354 += V_223 -> V_33 ;
V_14 -> V_10 += V_223 -> V_33 ;
F_13 ( & V_14 -> V_51 ) ;
F_13 ( & V_95 -> V_51 ) ;
V_29 = F_166 ( V_118 , V_35 , 0 , V_153 ,
0 , V_141 , V_33 , V_223 , 1 ) ;
F_6 ( V_14 ) ;
return V_29 ;
}
static struct V_67 *
F_464 ( struct V_117 * V_118 , struct V_34 * V_35 ,
T_2 V_27 , int V_176 )
{
struct V_67 * V_286 ;
V_286 = F_465 ( V_35 , V_27 ) ;
if ( F_216 ( V_286 ) )
return V_286 ;
F_466 ( V_286 , V_118 -> V_273 ) ;
F_467 ( V_35 -> V_282 . V_22 , V_286 , V_176 ) ;
F_468 ( V_286 ) ;
F_469 ( V_118 , V_35 -> V_37 , V_286 ) ;
F_435 ( V_627 , & V_286 -> V_576 ) ;
F_470 ( V_286 ) ;
F_471 ( V_286 ) ;
if ( V_35 -> V_282 . V_22 == V_217 ) {
V_286 -> V_628 = V_35 -> V_629 % 2 ;
if ( V_286 -> V_628 == 0 )
F_404 ( & V_35 -> V_630 , V_286 -> V_32 ,
V_286 -> V_32 + V_286 -> V_48 - 1 , V_98 ) ;
else
F_472 ( & V_35 -> V_630 , V_286 -> V_32 ,
V_286 -> V_32 + V_286 -> V_48 - 1 ) ;
} else {
V_286 -> V_628 = - 1 ;
F_404 ( & V_118 -> V_135 -> V_631 , V_286 -> V_32 ,
V_286 -> V_32 + V_286 -> V_48 - 1 , V_98 ) ;
}
V_118 -> V_322 = true ;
return V_286 ;
}
static struct V_261 *
F_473 ( struct V_117 * V_118 ,
struct V_34 * V_35 , T_3 V_632 )
{
struct V_261 * V_445 ;
struct V_261 * V_262 = & V_35 -> V_37 -> V_265 ;
int V_29 ;
bool V_633 = false ;
V_445 = F_364 ( V_118 , V_35 ) ;
if ( F_362 ( V_445 -> V_60 == 0 ) )
goto V_634;
V_164:
V_29 = F_363 ( V_445 , V_632 ) ;
if ( ! V_29 )
return V_445 ;
if ( V_445 -> V_635 )
return F_474 ( V_29 ) ;
if ( V_445 -> type == V_636 && ! V_633 ) {
V_633 = true ;
F_377 ( V_35 -> V_37 ) ;
goto V_164;
}
if ( F_263 ( V_35 -> V_37 , V_421 ) ) {
static F_475 ( V_637 ,
V_638 * 10 ,
1 ) ;
if ( F_476 ( & V_637 ) )
F_477 ( 1 , V_639
L_36 , V_29 ) ;
}
V_634:
V_29 = F_361 ( V_35 , V_445 , V_632 ,
V_423 ) ;
if ( ! V_29 )
return V_445 ;
if ( V_445 -> type != V_636 &&
V_445 -> V_95 == V_262 -> V_95 ) {
V_29 = F_363 ( V_262 , V_632 ) ;
if ( ! V_29 )
return V_262 ;
}
return F_474 ( V_29 ) ;
}
static void F_478 ( struct V_12 * V_37 ,
struct V_261 * V_445 , T_3 V_632 )
{
F_365 ( V_445 , V_632 , 0 ) ;
F_368 ( V_37 , V_445 , NULL , 0 ) ;
}
struct V_67 * F_479 ( struct V_117 * V_118 ,
struct V_34 * V_35 ,
T_2 V_17 , T_2 V_153 ,
struct V_625 * V_21 , int V_176 ,
T_2 V_640 , T_2 V_592 )
{
struct V_69 V_223 ;
struct V_261 * V_445 ;
struct V_67 * V_286 ;
struct V_189 * V_137 ;
T_2 V_7 = 0 ;
int V_29 ;
T_3 V_632 = V_35 -> V_55 ;
bool V_182 = F_84 ( V_35 -> V_37 ,
V_129 ) ;
#ifdef F_480
if ( F_239 ( V_35 -> V_37 ) ) {
V_286 = F_464 ( V_118 , V_35 , V_35 -> V_641 ,
V_176 ) ;
if ( ! F_216 ( V_286 ) )
V_35 -> V_641 += V_632 ;
return V_286 ;
}
#endif
V_445 = F_473 ( V_118 , V_35 , V_632 ) ;
if ( F_216 ( V_445 ) )
return F_481 ( V_445 ) ;
V_29 = F_456 ( V_35 , V_632 , V_632 , V_632 ,
V_592 , V_640 , & V_223 , 0 , 0 ) ;
if ( V_29 )
goto V_642;
V_286 = F_464 ( V_118 , V_35 , V_223 . V_22 , V_176 ) ;
if ( F_216 ( V_286 ) ) {
V_29 = F_217 ( V_286 ) ;
goto V_643;
}
if ( V_153 == V_644 ) {
if ( V_17 == 0 )
V_17 = V_223 . V_22 ;
V_7 |= V_134 ;
} else
F_32 ( V_17 > 0 ) ;
if ( V_153 != V_217 ) {
V_137 = F_230 () ;
if ( ! V_137 ) {
V_29 = - V_74 ;
goto V_645;
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
goto V_646;
}
return V_286 ;
V_646:
F_192 ( V_137 ) ;
V_645:
F_482 ( V_286 ) ;
V_643:
F_458 ( V_35 , V_223 . V_22 , V_223 . V_33 , 0 ) ;
V_642:
F_478 ( V_35 -> V_37 , V_445 , V_632 ) ;
return F_474 ( V_29 ) ;
}
static T_1 void F_483 ( struct V_117 * V_118 ,
struct V_34 * V_35 ,
struct V_647 * V_648 ,
struct V_65 * V_66 )
{
T_2 V_27 ;
T_2 V_310 ;
T_2 V_120 ;
T_2 V_7 ;
T_3 V_72 ;
T_3 V_632 ;
struct V_69 V_21 ;
struct V_67 * V_540 ;
int V_29 ;
int V_649 ;
int V_650 = 0 ;
if ( V_66 -> V_83 [ V_648 -> V_176 ] < V_648 -> V_651 ) {
V_648 -> V_652 = V_648 -> V_652 * 2 / 3 ;
V_648 -> V_652 = F_447 ( V_648 -> V_652 , 2 ) ;
} else {
V_648 -> V_652 = V_648 -> V_652 * 3 / 2 ;
V_648 -> V_652 = F_24 ( int , V_648 -> V_652 ,
F_484 ( V_35 ) ) ;
}
V_540 = V_66 -> V_82 [ V_648 -> V_176 ] ;
V_72 = F_39 ( V_540 ) ;
V_632 = V_35 -> V_55 ;
for ( V_649 = V_66 -> V_83 [ V_648 -> V_176 ] ; V_649 < V_72 ; V_649 ++ ) {
if ( V_650 >= V_648 -> V_652 )
break;
F_48 () ;
V_27 = F_247 ( V_540 , V_649 ) ;
V_310 = F_485 ( V_540 , V_649 ) ;
if ( V_649 == V_66 -> V_83 [ V_648 -> V_176 ] )
goto V_77;
if ( V_648 -> V_653 == V_654 &&
V_310 <= V_35 -> V_282 . V_33 )
continue;
V_29 = F_83 ( V_118 , V_35 , V_27 ,
V_648 -> V_176 - 1 , 1 , & V_120 ,
& V_7 ) ;
if ( V_29 < 0 )
continue;
F_32 ( V_120 == 0 ) ;
if ( V_648 -> V_653 == V_655 ) {
if ( V_120 == 1 )
goto V_77;
if ( V_648 -> V_176 == 1 &&
( V_7 & V_134 ) )
continue;
if ( ! V_648 -> V_656 ||
V_310 <= V_35 -> V_282 . V_33 )
continue;
F_131 ( V_540 , & V_21 , V_649 ) ;
V_29 = F_486 ( & V_21 ,
& V_648 -> V_657 ) ;
if ( V_29 < 0 )
continue;
} else {
if ( V_648 -> V_176 == 1 &&
( V_7 & V_134 ) )
continue;
}
V_77:
F_487 ( V_35 , V_27 ) ;
V_650 ++ ;
}
V_648 -> V_651 = V_649 ;
}
static int F_488 ( struct V_117 * V_118 ,
struct V_34 * V_35 ,
struct V_67 * V_540 )
{
int V_43 = F_39 ( V_540 ) ;
int V_42 , V_658 , V_29 ;
struct V_69 V_21 ;
struct V_289 * V_290 ;
T_2 V_27 , V_36 ;
if ( ! V_35 -> V_37 -> V_507 )
return 0 ;
for ( V_42 = 0 ; V_42 < V_43 ; V_42 ++ ) {
F_41 ( V_540 , & V_21 , V_42 ) ;
if ( V_21 . type != V_294 )
continue;
V_290 = F_86 ( V_540 , V_42 , struct V_289 ) ;
V_658 = F_243 ( V_540 , V_290 ) ;
if ( V_658 == V_295 )
continue;
V_27 = F_244 ( V_540 , V_290 ) ;
if ( ! V_27 )
continue;
V_36 = F_245 ( V_540 , V_290 ) ;
V_29 = F_489 ( V_118 , V_35 -> V_37 ,
V_27 , V_36 , V_98 ) ;
if ( V_29 )
return V_29 ;
}
return 0 ;
}
static int F_490 ( struct V_34 * V_35 ,
struct V_65 * V_66 , int V_659 )
{
int V_176 = 0 ;
int V_43 , V_649 ;
struct V_67 * V_540 ;
if ( V_659 == 0 )
return 1 ;
while ( V_176 <= V_659 ) {
V_540 = V_66 -> V_82 [ V_176 ] ;
V_43 = F_39 ( V_540 ) ;
V_66 -> V_83 [ V_176 ] ++ ;
V_649 = V_66 -> V_83 [ V_176 ] ;
if ( V_649 >= V_43 || V_176 == 0 ) {
if ( V_176 != V_659 ) {
F_491 ( V_540 , V_66 -> V_660 [ V_176 ] ) ;
V_66 -> V_660 [ V_176 ] = 0 ;
F_482 ( V_540 ) ;
V_66 -> V_82 [ V_176 ] = NULL ;
V_66 -> V_83 [ V_176 ] = 0 ;
}
} else {
break;
}
V_176 ++ ;
}
V_540 = V_66 -> V_82 [ V_659 ] ;
if ( V_66 -> V_83 [ V_659 ] >= F_39 ( V_540 ) )
return 1 ;
return 0 ;
}
static int F_492 ( struct V_117 * V_118 ,
struct V_34 * V_35 ,
struct V_67 * V_661 ,
T_2 V_662 ,
int V_659 )
{
int V_29 = 0 ;
int V_176 ;
struct V_67 * V_540 = V_661 ;
struct V_65 * V_66 = NULL ;
F_32 ( V_659 < 0 || V_659 > V_177 ) ;
F_32 ( V_661 == NULL ) ;
if ( ! V_35 -> V_37 -> V_507 )
return 0 ;
if ( ! F_493 ( V_661 ) ) {
V_29 = F_494 ( V_661 , V_662 ) ;
if ( V_29 )
goto V_81;
}
if ( V_659 == 0 ) {
V_29 = F_488 ( V_118 , V_35 , V_661 ) ;
goto V_81;
}
V_66 = F_34 () ;
if ( ! V_66 )
return - V_74 ;
F_495 ( V_661 ) ;
V_66 -> V_82 [ V_659 ] = V_661 ;
V_66 -> V_83 [ V_659 ] = 0 ;
V_66 -> V_660 [ V_659 ] = 0 ;
V_663:
V_176 = V_659 ;
while ( V_176 >= 0 ) {
if ( V_66 -> V_82 [ V_176 ] == NULL ) {
int V_664 ;
T_2 V_665 ;
T_2 V_666 ;
V_540 = V_66 -> V_82 [ V_176 + 1 ] ;
V_664 = V_66 -> V_83 [ V_176 + 1 ] ;
V_666 = F_247 ( V_540 , V_664 ) ;
V_665 = F_485 ( V_540 , V_664 ) ;
V_540 = F_496 ( V_35 , V_666 , V_665 ) ;
if ( F_216 ( V_540 ) ) {
V_29 = F_217 ( V_540 ) ;
goto V_81;
} else if ( ! F_493 ( V_540 ) ) {
F_482 ( V_540 ) ;
V_29 = - V_184 ;
goto V_81;
}
V_66 -> V_82 [ V_176 ] = V_540 ;
V_66 -> V_83 [ V_176 ] = 0 ;
F_497 ( V_540 ) ;
F_498 ( V_540 , V_667 ) ;
V_66 -> V_660 [ V_176 ] = V_668 ;
V_29 = F_489 ( V_118 ,
V_35 -> V_37 , V_666 ,
V_35 -> V_55 , V_98 ) ;
if ( V_29 )
goto V_81;
}
if ( V_176 == 0 ) {
V_29 = F_488 ( V_118 , V_35 , V_66 -> V_82 [ V_176 ] ) ;
if ( V_29 )
goto V_81;
V_29 = F_490 ( V_35 , V_66 , V_659 ) ;
if ( V_29 )
break;
goto V_663;
}
V_176 -- ;
}
V_29 = 0 ;
V_81:
F_53 ( V_66 ) ;
return V_29 ;
}
static T_1 int F_499 ( struct V_117 * V_118 ,
struct V_34 * V_35 ,
struct V_65 * V_66 ,
struct V_647 * V_648 , int V_669 )
{
int V_176 = V_648 -> V_176 ;
struct V_67 * V_540 = V_66 -> V_82 [ V_176 ] ;
T_2 V_670 = V_134 ;
int V_29 ;
if ( V_648 -> V_653 == V_654 &&
F_240 ( V_540 ) != V_35 -> V_282 . V_22 )
return 1 ;
if ( V_669 &&
( ( V_648 -> V_653 == V_655 && V_648 -> V_120 [ V_176 ] != 1 ) ||
( V_648 -> V_653 == V_654 && ! ( V_648 -> V_7 [ V_176 ] & V_670 ) ) ) ) {
F_32 ( ! V_66 -> V_660 [ V_176 ] ) ;
V_29 = F_83 ( V_118 , V_35 ,
V_540 -> V_32 , V_176 , 1 ,
& V_648 -> V_120 [ V_176 ] ,
& V_648 -> V_7 [ V_176 ] ) ;
F_32 ( V_29 == - V_74 ) ;
if ( V_29 )
return V_29 ;
F_32 ( V_648 -> V_120 [ V_176 ] == 0 ) ;
}
if ( V_648 -> V_653 == V_655 ) {
if ( V_648 -> V_120 [ V_176 ] > 1 )
return 1 ;
if ( V_66 -> V_660 [ V_176 ] && ! V_648 -> V_183 ) {
F_491 ( V_540 , V_66 -> V_660 [ V_176 ] ) ;
V_66 -> V_660 [ V_176 ] = 0 ;
}
return 0 ;
}
if ( ! ( V_648 -> V_7 [ V_176 ] & V_670 ) ) {
F_32 ( ! V_66 -> V_660 [ V_176 ] ) ;
V_29 = F_248 ( V_118 , V_35 , V_540 , 1 ) ;
F_32 ( V_29 ) ;
V_29 = F_249 ( V_118 , V_35 , V_540 , 0 ) ;
F_32 ( V_29 ) ;
V_29 = F_229 ( V_118 , V_35 , V_540 -> V_32 ,
V_540 -> V_48 , V_670 ,
F_241 ( V_540 ) , 0 ) ;
F_32 ( V_29 ) ;
V_648 -> V_7 [ V_176 ] |= V_670 ;
}
if ( V_66 -> V_660 [ V_176 ] && V_176 > 0 ) {
F_491 ( V_540 , V_66 -> V_660 [ V_176 ] ) ;
V_66 -> V_660 [ V_176 ] = 0 ;
}
return 0 ;
}
static T_1 int F_500 ( struct V_117 * V_118 ,
struct V_34 * V_35 ,
struct V_65 * V_66 ,
struct V_647 * V_648 , int * V_669 )
{
T_2 V_27 ;
T_2 V_310 ;
T_2 V_17 ;
T_3 V_632 ;
struct V_69 V_21 ;
struct V_67 * V_80 ;
int V_176 = V_648 -> V_176 ;
int V_77 = 0 ;
int V_29 = 0 ;
bool V_671 = false ;
V_310 = F_485 ( V_66 -> V_82 [ V_176 ] ,
V_66 -> V_83 [ V_176 ] ) ;
if ( V_648 -> V_653 == V_654 &&
V_310 <= V_35 -> V_282 . V_33 ) {
* V_669 = 1 ;
return 1 ;
}
V_27 = F_247 ( V_66 -> V_82 [ V_176 ] , V_66 -> V_83 [ V_176 ] ) ;
V_632 = V_35 -> V_55 ;
V_80 = F_501 ( V_35 -> V_37 , V_27 ) ;
if ( ! V_80 ) {
V_80 = F_465 ( V_35 , V_27 ) ;
if ( F_216 ( V_80 ) )
return F_217 ( V_80 ) ;
F_467 ( V_35 -> V_282 . V_22 , V_80 ,
V_176 - 1 ) ;
V_77 = 1 ;
}
F_468 ( V_80 ) ;
F_470 ( V_80 ) ;
V_29 = F_83 ( V_118 , V_35 , V_27 , V_176 - 1 , 1 ,
& V_648 -> V_120 [ V_176 - 1 ] ,
& V_648 -> V_7 [ V_176 - 1 ] ) ;
if ( V_29 < 0 ) {
F_502 ( V_80 ) ;
return V_29 ;
}
if ( F_362 ( V_648 -> V_120 [ V_176 - 1 ] == 0 ) ) {
F_425 ( V_35 -> V_37 , L_37 ) ;
F_91 () ;
}
* V_669 = 0 ;
if ( V_648 -> V_653 == V_655 ) {
if ( V_648 -> V_120 [ V_176 - 1 ] > 1 ) {
V_671 = true ;
if ( V_176 == 1 &&
( V_648 -> V_7 [ 0 ] & V_134 ) )
goto V_672;
if ( ! V_648 -> V_656 ||
V_310 <= V_35 -> V_282 . V_33 )
goto V_672;
F_131 ( V_66 -> V_82 [ V_176 ] , & V_21 ,
V_66 -> V_83 [ V_176 ] ) ;
V_29 = F_486 ( & V_21 , & V_648 -> V_657 ) ;
if ( V_29 < 0 )
goto V_672;
V_648 -> V_653 = V_654 ;
V_648 -> V_673 = V_176 - 1 ;
}
} else {
if ( V_176 == 1 &&
( V_648 -> V_7 [ 0 ] & V_134 ) )
goto V_672;
}
if ( ! F_503 ( V_80 , V_310 , 0 ) ) {
F_502 ( V_80 ) ;
F_482 ( V_80 ) ;
V_80 = NULL ;
* V_669 = 1 ;
}
if ( ! V_80 ) {
if ( V_77 && V_176 == 1 )
F_483 ( V_118 , V_35 , V_648 , V_66 ) ;
V_80 = F_496 ( V_35 , V_27 , V_310 ) ;
if ( F_216 ( V_80 ) ) {
return F_217 ( V_80 ) ;
} else if ( ! F_493 ( V_80 ) ) {
F_482 ( V_80 ) ;
return - V_184 ;
}
F_468 ( V_80 ) ;
F_470 ( V_80 ) ;
}
V_176 -- ;
F_32 ( V_176 != F_241 ( V_80 ) ) ;
V_66 -> V_82 [ V_176 ] = V_80 ;
V_66 -> V_83 [ V_176 ] = 0 ;
V_66 -> V_660 [ V_176 ] = V_674 ;
V_648 -> V_176 = V_176 ;
if ( V_648 -> V_176 == 1 )
V_648 -> V_651 = 0 ;
return 0 ;
V_672:
V_648 -> V_120 [ V_176 - 1 ] = 0 ;
V_648 -> V_7 [ V_176 - 1 ] = 0 ;
if ( V_648 -> V_653 == V_655 ) {
if ( V_648 -> V_7 [ V_176 ] & V_134 ) {
V_17 = V_66 -> V_82 [ V_176 ] -> V_32 ;
} else {
F_32 ( V_35 -> V_282 . V_22 !=
F_240 ( V_66 -> V_82 [ V_176 ] ) ) ;
V_17 = 0 ;
}
if ( V_671 ) {
V_29 = F_492 ( V_118 , V_35 , V_80 ,
V_310 , V_176 - 1 ) ;
if ( V_29 ) {
F_504 ( V_35 -> V_37 ,
L_38
L_39
L_40 ,
V_29 ) ;
}
}
V_29 = V_293 ( V_118 , V_35 , V_27 , V_632 , V_17 ,
V_35 -> V_282 . V_22 , V_176 - 1 , 0 ) ;
F_32 ( V_29 ) ;
}
F_502 ( V_80 ) ;
F_482 ( V_80 ) ;
* V_669 = 1 ;
return 1 ;
}
static T_1 int F_505 ( struct V_117 * V_118 ,
struct V_34 * V_35 ,
struct V_65 * V_66 ,
struct V_647 * V_648 )
{
int V_29 ;
int V_176 = V_648 -> V_176 ;
struct V_67 * V_540 = V_66 -> V_82 [ V_176 ] ;
T_2 V_17 = 0 ;
if ( V_648 -> V_653 == V_654 ) {
F_32 ( V_648 -> V_673 < V_176 ) ;
if ( V_176 < V_648 -> V_673 )
goto V_81;
V_29 = F_42 ( V_66 , V_176 + 1 , & V_648 -> V_657 ) ;
if ( V_29 > 0 )
V_648 -> V_656 = 0 ;
V_648 -> V_653 = V_655 ;
V_648 -> V_673 = - 1 ;
V_66 -> V_83 [ V_176 ] = 0 ;
if ( ! V_66 -> V_660 [ V_176 ] ) {
F_32 ( V_176 == 0 ) ;
F_468 ( V_540 ) ;
F_470 ( V_540 ) ;
V_66 -> V_660 [ V_176 ] = V_674 ;
V_29 = F_83 ( V_118 , V_35 ,
V_540 -> V_32 , V_176 , 1 ,
& V_648 -> V_120 [ V_176 ] ,
& V_648 -> V_7 [ V_176 ] ) ;
if ( V_29 < 0 ) {
F_491 ( V_540 , V_66 -> V_660 [ V_176 ] ) ;
V_66 -> V_660 [ V_176 ] = 0 ;
return V_29 ;
}
F_32 ( V_648 -> V_120 [ V_176 ] == 0 ) ;
if ( V_648 -> V_120 [ V_176 ] == 1 ) {
F_491 ( V_540 , V_66 -> V_660 [ V_176 ] ) ;
V_66 -> V_660 [ V_176 ] = 0 ;
return 1 ;
}
}
}
F_32 ( V_648 -> V_120 [ V_176 ] > 1 && ! V_66 -> V_660 [ V_176 ] ) ;
if ( V_648 -> V_120 [ V_176 ] == 1 ) {
if ( V_176 == 0 ) {
if ( V_648 -> V_7 [ V_176 ] & V_134 )
V_29 = F_249 ( V_118 , V_35 , V_540 , 1 ) ;
else
V_29 = F_249 ( V_118 , V_35 , V_540 , 0 ) ;
F_32 ( V_29 ) ;
V_29 = F_488 ( V_118 , V_35 , V_540 ) ;
if ( V_29 ) {
F_504 ( V_35 -> V_37 ,
L_41
L_42
L_40 ,
V_29 ) ;
}
}
if ( ! V_66 -> V_660 [ V_176 ] &&
F_432 ( V_540 ) == V_118 -> V_273 ) {
F_468 ( V_540 ) ;
F_470 ( V_540 ) ;
V_66 -> V_660 [ V_176 ] = V_674 ;
}
F_469 ( V_118 , V_35 -> V_37 , V_540 ) ;
}
if ( V_540 == V_35 -> V_136 ) {
if ( V_648 -> V_7 [ V_176 ] & V_134 )
V_17 = V_540 -> V_32 ;
else
F_32 ( V_35 -> V_282 . V_22 !=
F_240 ( V_540 ) ) ;
} else {
if ( V_648 -> V_7 [ V_176 + 1 ] & V_134 )
V_17 = V_66 -> V_82 [ V_176 + 1 ] -> V_32 ;
else
F_32 ( V_35 -> V_282 . V_22 !=
F_240 ( V_66 -> V_82 [ V_176 + 1 ] ) ) ;
}
F_431 ( V_118 , V_35 , V_540 , V_17 , V_648 -> V_120 [ V_176 ] == 1 ) ;
V_81:
V_648 -> V_120 [ V_176 ] = 0 ;
V_648 -> V_7 [ V_176 ] = 0 ;
return 0 ;
}
static T_1 int F_506 ( struct V_117 * V_118 ,
struct V_34 * V_35 ,
struct V_65 * V_66 ,
struct V_647 * V_648 )
{
int V_176 = V_648 -> V_176 ;
int V_669 = 1 ;
int V_29 ;
while ( V_176 >= 0 ) {
V_29 = F_499 ( V_118 , V_35 , V_66 , V_648 , V_669 ) ;
if ( V_29 > 0 )
break;
if ( V_176 == 0 )
break;
if ( V_66 -> V_83 [ V_176 ] >=
F_39 ( V_66 -> V_82 [ V_176 ] ) )
break;
V_29 = F_500 ( V_118 , V_35 , V_66 , V_648 , & V_669 ) ;
if ( V_29 > 0 ) {
V_66 -> V_83 [ V_176 ] ++ ;
continue;
} else if ( V_29 < 0 )
return V_29 ;
V_176 = V_648 -> V_176 ;
}
return 0 ;
}
static T_1 int F_507 ( struct V_117 * V_118 ,
struct V_34 * V_35 ,
struct V_65 * V_66 ,
struct V_647 * V_648 , int V_675 )
{
int V_176 = V_648 -> V_176 ;
int V_29 ;
V_66 -> V_83 [ V_176 ] = F_39 ( V_66 -> V_82 [ V_176 ] ) ;
while ( V_176 < V_675 && V_66 -> V_82 [ V_176 ] ) {
V_648 -> V_176 = V_176 ;
if ( V_66 -> V_83 [ V_176 ] + 1 <
F_39 ( V_66 -> V_82 [ V_176 ] ) ) {
V_66 -> V_83 [ V_176 ] ++ ;
return 0 ;
} else {
V_29 = F_505 ( V_118 , V_35 , V_66 , V_648 ) ;
if ( V_29 > 0 )
return 0 ;
if ( V_66 -> V_660 [ V_176 ] ) {
F_491 ( V_66 -> V_82 [ V_176 ] ,
V_66 -> V_660 [ V_176 ] ) ;
V_66 -> V_660 [ V_176 ] = 0 ;
}
F_482 ( V_66 -> V_82 [ V_176 ] ) ;
V_66 -> V_82 [ V_176 ] = NULL ;
V_176 ++ ;
}
}
return 1 ;
}
int F_508 ( struct V_34 * V_35 ,
struct V_261 * V_445 , int V_656 ,
int V_676 )
{
struct V_65 * V_66 ;
struct V_117 * V_118 ;
struct V_34 * V_88 = V_35 -> V_37 -> V_88 ;
struct V_677 * V_283 = & V_35 -> V_283 ;
struct V_647 * V_648 ;
struct V_69 V_21 ;
int V_160 = 0 ;
int V_29 ;
int V_176 ;
bool V_678 = false ;
F_193 ( V_35 -> V_37 , L_43 , V_35 -> V_22 ) ;
V_66 = F_34 () ;
if ( ! V_66 ) {
V_160 = - V_74 ;
goto V_81;
}
V_648 = F_61 ( sizeof( * V_648 ) , V_98 ) ;
if ( ! V_648 ) {
F_53 ( V_66 ) ;
V_160 = - V_74 ;
goto V_81;
}
V_118 = F_509 ( V_88 , 0 ) ;
if ( F_216 ( V_118 ) ) {
V_160 = F_217 ( V_118 ) ;
goto V_131;
}
if ( V_445 )
V_118 -> V_445 = V_445 ;
if ( F_510 ( & V_283 -> V_679 ) == 0 ) {
V_176 = F_241 ( V_35 -> V_136 ) ;
V_66 -> V_82 [ V_176 ] = F_511 ( V_35 ) ;
F_470 ( V_66 -> V_82 [ V_176 ] ) ;
V_66 -> V_83 [ V_176 ] = 0 ;
V_66 -> V_660 [ V_176 ] = V_674 ;
memset ( & V_648 -> V_657 , 0 ,
sizeof( V_648 -> V_657 ) ) ;
} else {
F_512 ( & V_21 , & V_283 -> V_679 ) ;
memcpy ( & V_648 -> V_657 , & V_21 ,
sizeof( V_648 -> V_657 ) ) ;
V_176 = V_283 -> V_680 ;
F_32 ( V_176 == 0 ) ;
V_66 -> V_681 = V_176 ;
V_29 = F_38 ( NULL , V_35 , & V_21 , V_66 , 0 , 0 ) ;
V_66 -> V_681 = 0 ;
if ( V_29 < 0 ) {
V_160 = V_29 ;
goto V_682;
}
F_8 ( V_29 > 0 ) ;
F_136 ( V_66 , 0 ) ;
V_176 = F_241 ( V_35 -> V_136 ) ;
while ( 1 ) {
F_468 ( V_66 -> V_82 [ V_176 ] ) ;
F_470 ( V_66 -> V_82 [ V_176 ] ) ;
V_66 -> V_660 [ V_176 ] = V_674 ;
V_29 = F_83 ( V_118 , V_35 ,
V_66 -> V_82 [ V_176 ] -> V_32 ,
V_176 , 1 , & V_648 -> V_120 [ V_176 ] ,
& V_648 -> V_7 [ V_176 ] ) ;
if ( V_29 < 0 ) {
V_160 = V_29 ;
goto V_682;
}
F_32 ( V_648 -> V_120 [ V_176 ] == 0 ) ;
if ( V_176 == V_283 -> V_680 )
break;
F_502 ( V_66 -> V_82 [ V_176 ] ) ;
V_66 -> V_660 [ V_176 ] = 0 ;
F_8 ( V_648 -> V_120 [ V_176 ] != 1 ) ;
V_176 -- ;
}
}
V_648 -> V_176 = V_176 ;
V_648 -> V_673 = - 1 ;
V_648 -> V_653 = V_655 ;
V_648 -> V_656 = V_656 ;
V_648 -> V_183 = 0 ;
V_648 -> V_676 = V_676 ;
V_648 -> V_652 = F_484 ( V_35 ) ;
while ( 1 ) {
V_29 = F_506 ( V_118 , V_35 , V_66 , V_648 ) ;
if ( V_29 < 0 ) {
V_160 = V_29 ;
break;
}
V_29 = F_507 ( V_118 , V_35 , V_66 , V_648 , V_177 ) ;
if ( V_29 < 0 ) {
V_160 = V_29 ;
break;
}
if ( V_29 > 0 ) {
F_32 ( V_648 -> V_653 != V_655 ) ;
break;
}
if ( V_648 -> V_653 == V_655 ) {
V_176 = V_648 -> V_176 ;
F_513 ( V_66 -> V_82 [ V_176 ] ,
& V_283 -> V_679 ,
V_66 -> V_83 [ V_176 ] ) ;
V_283 -> V_680 = V_176 ;
}
F_32 ( V_648 -> V_176 == 0 ) ;
if ( F_514 ( V_118 , V_88 ) ||
( ! V_676 && F_515 ( V_35 ) ) ) {
V_29 = F_516 ( V_118 , V_88 ,
& V_35 -> V_282 ,
V_283 ) ;
if ( V_29 ) {
F_162 ( V_118 , V_29 ) ;
V_160 = V_29 ;
goto V_682;
}
F_517 ( V_118 , V_88 ) ;
if ( ! V_676 && F_515 ( V_35 ) ) {
F_518 ( L_44 ) ;
V_160 = - V_187 ;
goto V_131;
}
V_118 = F_509 ( V_88 , 0 ) ;
if ( F_216 ( V_118 ) ) {
V_160 = F_217 ( V_118 ) ;
goto V_131;
}
if ( V_445 )
V_118 -> V_445 = V_445 ;
}
}
F_45 ( V_66 ) ;
if ( V_160 )
goto V_682;
V_29 = F_519 ( V_118 , V_88 , & V_35 -> V_282 ) ;
if ( V_29 ) {
F_162 ( V_118 , V_29 ) ;
goto V_682;
}
if ( V_35 -> V_282 . V_22 != V_644 ) {
V_29 = F_520 ( V_88 , & V_35 -> V_282 , V_66 ,
NULL , NULL ) ;
if ( V_29 < 0 ) {
F_162 ( V_118 , V_29 ) ;
V_160 = V_29 ;
goto V_682;
} else if ( V_29 > 0 ) {
F_521 ( V_118 , V_88 ,
V_35 -> V_282 . V_22 ) ;
}
}
if ( F_242 ( V_683 , & V_35 -> V_292 ) ) {
F_522 ( V_118 , V_35 ) ;
} else {
F_482 ( V_35 -> V_136 ) ;
F_482 ( V_35 -> V_684 ) ;
F_523 ( V_35 ) ;
}
V_678 = true ;
V_682:
F_517 ( V_118 , V_88 ) ;
V_131:
F_9 ( V_648 ) ;
F_53 ( V_66 ) ;
V_81:
if ( ! V_676 && V_678 == false )
F_524 ( V_35 ) ;
if ( V_160 && V_160 != - V_187 )
F_525 ( V_35 -> V_37 , V_160 , NULL ) ;
return V_160 ;
}
int F_526 ( struct V_117 * V_118 ,
struct V_34 * V_35 ,
struct V_67 * V_136 ,
struct V_67 * V_17 )
{
struct V_65 * V_66 ;
struct V_647 * V_648 ;
int V_176 ;
int V_685 ;
int V_29 = 0 ;
int V_686 ;
F_32 ( V_35 -> V_282 . V_22 != V_644 ) ;
V_66 = F_34 () ;
if ( ! V_66 )
return - V_74 ;
V_648 = F_61 ( sizeof( * V_648 ) , V_98 ) ;
if ( ! V_648 ) {
F_53 ( V_66 ) ;
return - V_74 ;
}
F_527 ( V_17 ) ;
V_685 = F_241 ( V_17 ) ;
F_495 ( V_17 ) ;
V_66 -> V_82 [ V_685 ] = V_17 ;
V_66 -> V_83 [ V_685 ] = F_39 ( V_17 ) ;
F_527 ( V_136 ) ;
V_176 = F_241 ( V_136 ) ;
V_66 -> V_82 [ V_176 ] = V_136 ;
V_66 -> V_83 [ V_176 ] = 0 ;
V_66 -> V_660 [ V_176 ] = V_674 ;
V_648 -> V_120 [ V_685 ] = 1 ;
V_648 -> V_7 [ V_685 ] = V_134 ;
V_648 -> V_176 = V_176 ;
V_648 -> V_673 = - 1 ;
V_648 -> V_653 = V_655 ;
V_648 -> V_656 = 0 ;
V_648 -> V_183 = 1 ;
V_648 -> V_676 = 1 ;
V_648 -> V_652 = F_484 ( V_35 ) ;
while ( 1 ) {
V_686 = F_506 ( V_118 , V_35 , V_66 , V_648 ) ;
if ( V_686 < 0 ) {
V_29 = V_686 ;
break;
}
V_686 = F_507 ( V_118 , V_35 , V_66 , V_648 , V_685 ) ;
if ( V_686 < 0 )
V_29 = V_686 ;
if ( V_686 != 0 )
break;
}
F_9 ( V_648 ) ;
F_53 ( V_66 ) ;
return V_29 ;
}
static T_2 F_528 ( struct V_34 * V_35 , T_2 V_7 )
{
T_2 V_382 ;
T_2 V_687 ;
V_687 = F_298 ( V_35 -> V_37 , V_7 ) ;
if ( V_687 )
return F_300 ( V_687 ) ;
V_382 = V_35 -> V_37 -> V_383 -> V_384 ;
V_687 = V_393 |
V_392 | V_391 |
V_344 | V_345 ;
if ( V_382 == 1 ) {
V_687 |= V_343 ;
V_687 = V_7 & ~ V_687 ;
if ( V_7 & V_393 )
return V_687 ;
if ( V_7 & ( V_344 |
V_345 ) )
return V_687 | V_343 ;
} else {
if ( V_7 & V_687 )
return V_7 ;
V_687 |= V_343 ;
V_687 = V_7 & ~ V_687 ;
if ( V_7 & V_343 )
return V_687 | V_344 ;
}
return V_7 ;
}
static int F_529 ( struct V_1 * V_2 , int V_411 )
{
struct V_111 * V_410 = V_2 -> V_95 ;
T_2 V_36 ;
T_2 V_688 ;
int V_29 = - V_313 ;
if ( ( V_410 -> V_7 &
( V_339 | V_54 ) ) &&
! V_411 )
V_688 = V_303 ;
else
V_688 = 0 ;
F_11 ( & V_410 -> V_51 ) ;
F_11 ( & V_2 -> V_51 ) ;
if ( V_2 -> V_306 ) {
V_2 -> V_306 ++ ;
V_29 = 0 ;
goto V_81;
}
V_36 = V_2 -> V_21 . V_33 - V_2 -> V_10 - V_2 -> V_9 -
V_2 -> V_45 - F_58 ( & V_2 -> V_96 ) ;
if ( V_410 -> V_94 + V_410 -> V_354 + V_410 -> V_353 +
V_410 -> V_355 + V_410 -> V_341 + V_36 +
V_688 <= V_410 -> V_340 ) {
V_410 -> V_341 += V_36 ;
V_2 -> V_306 ++ ;
F_72 ( & V_2 -> V_689 , & V_410 -> V_361 ) ;
V_29 = 0 ;
}
V_81:
F_13 ( & V_2 -> V_51 ) ;
F_13 ( & V_410 -> V_51 ) ;
return V_29 ;
}
int F_530 ( struct V_34 * V_35 ,
struct V_1 * V_2 )
{
struct V_117 * V_118 ;
T_2 V_690 ;
int V_29 ;
V_164:
V_118 = F_215 ( V_35 ) ;
if ( F_216 ( V_118 ) )
return F_217 ( V_118 ) ;
F_49 ( & V_35 -> V_37 -> V_691 ) ;
if ( F_242 ( V_692 , & V_118 -> V_135 -> V_7 ) ) {
T_2 V_273 = V_118 -> V_273 ;
F_47 ( & V_35 -> V_37 -> V_691 ) ;
F_219 ( V_118 , V_35 ) ;
V_29 = F_531 ( V_35 , V_273 ) ;
if ( V_29 )
return V_29 ;
goto V_164;
}
V_690 = F_528 ( V_35 , V_2 -> V_7 ) ;
if ( V_690 != V_2 -> V_7 ) {
V_29 = F_307 ( V_118 , V_35 , V_690 ,
V_404 ) ;
if ( V_29 == - V_313 )
V_29 = 0 ;
if ( V_29 < 0 )
goto V_81;
}
V_29 = F_529 ( V_2 , 0 ) ;
if ( ! V_29 )
goto V_81;
V_690 = F_301 ( V_35 , V_2 -> V_95 -> V_7 ) ;
V_29 = F_307 ( V_118 , V_35 , V_690 ,
V_404 ) ;
if ( V_29 < 0 )
goto V_81;
V_29 = F_529 ( V_2 , 0 ) ;
V_81:
if ( V_2 -> V_7 & V_339 ) {
V_690 = F_528 ( V_35 , V_2 -> V_7 ) ;
F_532 ( V_35 -> V_37 -> V_396 ) ;
F_325 ( V_118 , V_35 , V_690 ) ;
F_533 ( V_35 -> V_37 -> V_396 ) ;
}
F_47 ( & V_35 -> V_37 -> V_691 ) ;
F_219 ( V_118 , V_35 ) ;
return V_29 ;
}
int F_534 ( struct V_117 * V_118 ,
struct V_34 * V_35 , T_2 type )
{
T_2 V_690 = F_301 ( V_35 , type ) ;
return F_307 ( V_118 , V_35 , V_690 ,
V_404 ) ;
}
T_2 F_535 ( struct V_111 * V_410 )
{
struct V_1 * V_14 ;
T_2 V_693 = 0 ;
int V_342 ;
if ( F_182 ( & V_410 -> V_361 ) )
return 0 ;
F_11 ( & V_410 -> V_51 ) ;
F_183 (block_group, &sinfo->ro_bgs, ro_list) {
F_11 ( & V_14 -> V_51 ) ;
if ( ! V_14 -> V_306 ) {
F_13 ( & V_14 -> V_51 ) ;
continue;
}
if ( V_14 -> V_7 & ( V_344 |
V_345 |
V_343 ) )
V_342 = 2 ;
else
V_342 = 1 ;
V_693 += ( V_14 -> V_21 . V_33 -
F_58 ( & V_14 -> V_96 ) ) *
V_342 ;
F_13 ( & V_14 -> V_51 ) ;
}
F_13 ( & V_410 -> V_51 ) ;
return V_693 ;
}
void F_536 ( struct V_34 * V_35 ,
struct V_1 * V_2 )
{
struct V_111 * V_410 = V_2 -> V_95 ;
T_2 V_36 ;
F_32 ( ! V_2 -> V_306 ) ;
F_11 ( & V_410 -> V_51 ) ;
F_11 ( & V_2 -> V_51 ) ;
if ( ! -- V_2 -> V_306 ) {
V_36 = V_2 -> V_21 . V_33 - V_2 -> V_10 -
V_2 -> V_9 - V_2 -> V_45 -
F_58 ( & V_2 -> V_96 ) ;
V_410 -> V_341 -= V_36 ;
F_274 ( & V_2 -> V_689 ) ;
}
F_13 ( & V_2 -> V_51 ) ;
F_13 ( & V_410 -> V_51 ) ;
}
int F_537 ( struct V_34 * V_35 , T_2 V_27 )
{
struct V_1 * V_14 ;
struct V_111 * V_95 ;
struct V_694 * V_383 = V_35 -> V_37 -> V_383 ;
struct V_695 * V_696 ;
struct V_117 * V_118 ;
T_2 V_697 ;
T_2 V_698 = 1 ;
T_2 V_699 = 0 ;
T_2 V_377 ;
int V_700 ;
int V_596 ;
int V_116 = 0 ;
int V_29 = 0 ;
V_700 = F_263 ( V_35 -> V_37 , V_421 ) ;
V_14 = F_76 ( V_35 -> V_37 , V_27 ) ;
if ( ! V_14 ) {
if ( V_700 )
F_423 ( V_35 -> V_37 ,
L_45 ,
V_27 ) ;
return - 1 ;
}
V_697 = F_58 ( & V_14 -> V_96 ) ;
if ( ! V_697 )
goto V_81;
V_95 = V_14 -> V_95 ;
F_11 ( & V_95 -> V_51 ) ;
V_116 = V_95 -> V_116 ;
if ( ( V_95 -> V_340 != V_14 -> V_21 . V_33 ) &&
( V_95 -> V_94 + V_95 -> V_354 +
V_95 -> V_353 + V_95 -> V_341 +
V_697 < V_95 -> V_340 ) ) {
F_13 ( & V_95 -> V_51 ) ;
goto V_81;
}
F_13 ( & V_95 -> V_51 ) ;
V_29 = - 1 ;
V_377 = F_298 ( V_35 -> V_37 , V_14 -> V_7 ) ;
if ( V_377 ) {
V_596 = F_438 ( F_300 ( V_377 ) ) ;
} else {
if ( V_116 ) {
if ( V_700 )
F_423 ( V_35 -> V_37 ,
L_46 ,
V_14 -> V_21 . V_22 ) ;
goto V_81;
}
V_596 = F_439 ( V_14 ) ;
}
if ( V_596 == V_579 ) {
V_698 = 4 ;
V_697 >>= 1 ;
} else if ( V_596 == V_580 ) {
V_698 = 2 ;
} else if ( V_596 == V_581 ) {
V_697 <<= 1 ;
} else if ( V_596 == V_582 ) {
V_698 = V_383 -> V_384 ;
V_697 = F_207 ( V_697 , V_698 ) ;
}
V_118 = F_215 ( V_35 ) ;
if ( F_216 ( V_118 ) ) {
V_29 = F_217 ( V_118 ) ;
goto V_81;
}
F_49 ( & V_35 -> V_37 -> V_420 ) ;
F_183 (device, &fs_devices->alloc_list, dev_alloc_list) {
T_2 V_701 ;
if ( V_696 -> V_340 > V_696 -> V_94 + V_697 &&
! V_696 -> V_702 ) {
V_29 = F_538 ( V_118 , V_696 , V_697 ,
& V_701 , NULL ) ;
if ( ! V_29 )
V_699 ++ ;
if ( V_699 >= V_698 )
break;
V_29 = - 1 ;
}
}
if ( V_700 && V_29 == - 1 )
F_423 ( V_35 -> V_37 ,
L_47 ,
V_14 -> V_21 . V_22 ) ;
F_47 ( & V_35 -> V_37 -> V_420 ) ;
F_219 ( V_118 , V_35 ) ;
V_81:
F_6 ( V_14 ) ;
return V_29 ;
}
static int F_539 ( struct V_34 * V_35 ,
struct V_65 * V_66 , struct V_69 * V_21 )
{
int V_29 = 0 ;
struct V_69 V_147 ;
struct V_67 * V_68 ;
int V_649 ;
V_29 = F_38 ( NULL , V_35 , V_21 , V_66 , 0 , 0 ) ;
if ( V_29 < 0 )
goto V_81;
while ( 1 ) {
V_649 = V_66 -> V_83 [ 0 ] ;
V_68 = V_66 -> V_82 [ 0 ] ;
if ( V_649 >= F_39 ( V_68 ) ) {
V_29 = F_51 ( V_35 , V_66 ) ;
if ( V_29 == 0 )
continue;
if ( V_29 < 0 )
goto V_81;
break;
}
F_41 ( V_68 , & V_147 , V_649 ) ;
if ( V_147 . V_22 >= V_21 -> V_22 &&
V_147 . type == V_188 ) {
struct V_703 * V_704 ;
struct V_705 * V_706 ;
V_704 = & V_35 -> V_37 -> V_47 . V_707 ;
F_540 ( & V_704 -> V_51 ) ;
V_706 = F_541 ( V_704 , V_147 . V_22 ,
V_147 . V_33 ) ;
F_542 ( & V_704 -> V_51 ) ;
if ( ! V_706 ) {
F_425 ( V_35 -> V_37 ,
L_48 ,
V_147 . V_22 , V_147 . V_33 ) ;
V_29 = - V_161 ;
} else {
V_29 = 0 ;
}
F_543 ( V_706 ) ;
goto V_81;
}
V_66 -> V_83 [ 0 ] ++ ;
}
V_81:
return V_29 ;
}
void F_544 ( struct V_12 * V_13 )
{
struct V_1 * V_14 ;
T_2 V_71 = 0 ;
while ( 1 ) {
struct V_297 * V_297 ;
V_14 = F_75 ( V_13 , V_71 ) ;
while ( V_14 ) {
F_11 ( & V_14 -> V_51 ) ;
if ( V_14 -> V_173 )
break;
F_13 ( & V_14 -> V_51 ) ;
V_14 = F_253 ( V_13 -> V_88 ,
V_14 ) ;
}
if ( ! V_14 ) {
if ( V_71 == 0 )
break;
V_71 = 0 ;
continue;
}
V_297 = V_14 -> V_297 ;
V_14 -> V_173 = 0 ;
V_14 -> V_297 = NULL ;
F_13 ( & V_14 -> V_51 ) ;
ASSERT ( V_14 -> V_331 . V_297 == NULL ) ;
F_267 ( V_297 ) ;
V_71 = V_14 -> V_21 . V_22 + V_14 -> V_21 . V_33 ;
F_6 ( V_14 ) ;
}
}
int F_545 ( struct V_12 * V_13 )
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
F_11 ( & V_13 -> V_534 ) ;
while ( ! F_182 ( & V_13 -> V_536 ) ) {
V_14 = F_273 ( & V_13 -> V_536 ,
struct V_1 ,
V_535 ) ;
F_274 ( & V_14 -> V_535 ) ;
F_6 ( V_14 ) ;
}
F_13 ( & V_13 -> V_534 ) ;
F_11 ( & V_13 -> V_18 ) ;
while ( ( V_30 = F_201 ( & V_13 -> V_19 ) ) != NULL ) {
V_14 = F_12 ( V_30 , struct V_1 ,
V_20 ) ;
F_194 ( & V_14 -> V_20 ,
& V_13 -> V_19 ) ;
F_546 ( & V_14 -> V_20 ) ;
F_13 ( & V_13 -> V_18 ) ;
F_71 ( & V_14 -> V_95 -> V_352 ) ;
F_195 ( & V_14 -> V_99 ) ;
F_73 ( & V_14 -> V_95 -> V_352 ) ;
if ( V_14 -> V_3 == V_107 )
F_437 ( V_14 ) ;
if ( V_14 -> V_3 == V_103 ||
V_14 -> V_3 == V_5 )
F_19 ( V_13 -> V_64 , V_14 ) ;
F_547 ( V_14 ) ;
ASSERT ( F_182 ( & V_14 -> V_329 ) ) ;
ASSERT ( F_182 ( & V_14 -> V_330 ) ) ;
ASSERT ( F_182 ( & V_14 -> V_535 ) ) ;
ASSERT ( F_212 ( & V_14 -> V_8 ) == 1 ) ;
F_6 ( V_14 ) ;
F_11 ( & V_13 -> V_18 ) ;
}
F_13 ( & V_13 -> V_18 ) ;
F_548 () ;
F_380 ( V_13 ) ;
while ( ! F_182 ( & V_13 -> V_95 ) ) {
int V_42 ;
V_95 = F_184 ( V_13 -> V_95 . V_80 ,
struct V_111 ,
V_99 ) ;
if ( F_8 ( V_95 -> V_353 > 0 ||
V_95 -> V_354 > 0 ||
V_95 -> V_355 > 0 ) )
F_329 ( V_95 , 0 , 0 ) ;
F_195 ( & V_95 -> V_99 ) ;
for ( V_42 = 0 ; V_42 < V_350 ; V_42 ++ ) {
struct V_708 * V_364 ;
V_364 = V_95 -> V_709 [ V_42 ] ;
V_95 -> V_709 [ V_42 ] = NULL ;
if ( V_364 ) {
F_549 ( V_364 ) ;
F_550 ( V_364 ) ;
}
}
F_549 ( & V_95 -> V_364 ) ;
F_550 ( & V_95 -> V_364 ) ;
}
return 0 ;
}
static void F_551 ( struct V_111 * V_95 ,
struct V_1 * V_2 )
{
int V_596 = F_439 ( V_2 ) ;
bool V_254 = false ;
F_71 ( & V_95 -> V_352 ) ;
if ( F_182 ( & V_95 -> V_351 [ V_596 ] ) )
V_254 = true ;
F_72 ( & V_2 -> V_99 , & V_95 -> V_351 [ V_596 ] ) ;
F_73 ( & V_95 -> V_352 ) ;
if ( V_254 ) {
struct V_710 * V_711 ;
int V_29 ;
V_711 = F_61 ( sizeof( * V_711 ) , V_98 ) ;
if ( ! V_711 )
goto V_712;
V_711 -> V_385 = V_596 ;
F_552 ( & V_711 -> V_364 , & V_713 ) ;
V_29 = F_553 ( & V_711 -> V_364 , & V_95 -> V_364 ,
L_8 , F_440 ( V_596 ) ) ;
if ( V_29 ) {
F_550 ( & V_711 -> V_364 ) ;
goto V_712;
}
V_95 -> V_709 [ V_596 ] = & V_711 -> V_364 ;
}
return;
V_712:
F_554 ( L_49 ) ;
}
static struct V_1 *
F_555 ( struct V_34 * V_35 , T_2 V_32 , T_2 V_60 )
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
V_2 -> V_714 = F_556 ( V_35 ,
& V_35 -> V_37 -> V_47 ,
V_32 ) ;
F_557 ( V_2 ) ;
F_65 ( & V_2 -> V_8 , 1 ) ;
F_291 ( & V_2 -> V_51 ) ;
F_290 ( & V_2 -> V_588 ) ;
F_62 ( & V_2 -> V_99 ) ;
F_62 ( & V_2 -> V_715 ) ;
F_62 ( & V_2 -> V_535 ) ;
F_62 ( & V_2 -> V_689 ) ;
F_62 ( & V_2 -> V_329 ) ;
F_62 ( & V_2 -> V_330 ) ;
F_558 ( V_2 ) ;
F_65 ( & V_2 -> V_716 , 0 ) ;
F_63 ( & V_2 -> V_717 ) ;
return V_2 ;
}
int F_559 ( struct V_34 * V_35 )
{
struct V_65 * V_66 ;
int V_29 ;
struct V_1 * V_2 ;
struct V_12 * V_13 = V_35 -> V_37 ;
struct V_111 * V_95 ;
struct V_69 V_21 ;
struct V_69 V_147 ;
struct V_67 * V_68 ;
int V_718 = 0 ;
T_2 V_719 ;
V_35 = V_13 -> V_64 ;
V_21 . V_22 = 0 ;
V_21 . V_33 = 0 ;
V_21 . type = V_188 ;
V_66 = F_34 () ;
if ( ! V_66 )
return - V_74 ;
V_66 -> V_77 = V_78 ;
V_719 = F_560 ( V_35 -> V_37 -> V_260 ) ;
if ( F_263 ( V_35 -> V_37 , V_311 ) &&
F_561 ( V_35 -> V_37 -> V_260 ) != V_719 )
V_718 = 1 ;
if ( F_263 ( V_35 -> V_37 , V_720 ) )
V_718 = 1 ;
while ( 1 ) {
V_29 = F_539 ( V_35 , V_66 , & V_21 ) ;
if ( V_29 > 0 )
break;
if ( V_29 != 0 )
goto error;
V_68 = V_66 -> V_82 [ 0 ] ;
F_41 ( V_68 , & V_147 , V_66 -> V_83 [ 0 ] ) ;
V_2 = F_555 ( V_35 , V_147 . V_22 ,
V_147 . V_33 ) ;
if ( ! V_2 ) {
V_29 = - V_74 ;
goto error;
}
if ( V_718 ) {
if ( F_263 ( V_35 -> V_37 , V_311 ) )
V_2 -> V_304 = V_320 ;
}
F_562 ( V_68 , & V_2 -> V_96 ,
F_251 ( V_68 , V_66 -> V_83 [ 0 ] ) ,
sizeof( V_2 -> V_96 ) ) ;
V_2 -> V_7 = F_563 ( & V_2 -> V_96 ) ;
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
F_547 ( V_2 ) ;
F_6 ( V_2 ) ;
goto error;
}
F_564 ( V_35 -> V_37 , V_2 , 0 ) ;
V_29 = F_287 ( V_13 , V_2 -> V_7 , V_147 . V_33 ,
F_58 ( & V_2 -> V_96 ) ,
V_2 -> V_45 , & V_95 ) ;
if ( V_29 ) {
F_547 ( V_2 ) ;
F_11 ( & V_13 -> V_18 ) ;
F_194 ( & V_2 -> V_20 ,
& V_13 -> V_19 ) ;
F_546 ( & V_2 -> V_20 ) ;
F_13 ( & V_13 -> V_18 ) ;
F_6 ( V_2 ) ;
goto error;
}
V_2 -> V_95 = V_95 ;
F_551 ( V_95 , V_2 ) ;
F_294 ( V_35 -> V_37 , V_2 -> V_7 ) ;
if ( F_565 ( V_35 , V_2 -> V_21 . V_22 ) ) {
F_529 ( V_2 , 1 ) ;
} else if ( F_58 ( & V_2 -> V_96 ) == 0 ) {
F_11 ( & V_13 -> V_534 ) ;
if ( F_182 ( & V_2 -> V_535 ) ) {
F_4 ( V_2 ) ;
F_72 ( & V_2 -> V_535 ,
& V_13 -> V_536 ) ;
}
F_13 ( & V_13 -> V_534 ) ;
}
}
F_79 (space_info, &root->fs_info->space_info, list) {
if ( ! ( F_301 ( V_35 , V_95 -> V_7 ) &
( V_345 |
V_344 |
V_392 |
V_391 |
V_343 ) ) )
continue;
F_183 (cache,
&space_info->block_groups[BTRFS_RAID_RAID0],
list)
F_529 ( V_2 , 1 ) ;
F_183 (cache,
&space_info->block_groups[BTRFS_RAID_SINGLE],
list)
F_529 ( V_2 , 1 ) ;
}
F_379 ( V_13 ) ;
V_29 = 0 ;
error:
F_53 ( V_66 ) ;
return V_29 ;
}
void F_226 ( struct V_117 * V_118 ,
struct V_34 * V_35 )
{
struct V_1 * V_14 , * V_316 ;
struct V_34 * V_64 = V_35 -> V_37 -> V_64 ;
struct V_721 V_96 ;
struct V_69 V_21 ;
int V_29 = 0 ;
bool V_277 = V_118 -> V_277 ;
V_118 -> V_277 = false ;
F_269 (block_group, tmp, &trans->new_bgs, bg_list) {
if ( V_29 )
goto V_80;
F_11 ( & V_14 -> V_51 ) ;
memcpy ( & V_96 , & V_14 -> V_96 , sizeof( V_96 ) ) ;
memcpy ( & V_21 , & V_14 -> V_21 , sizeof( V_21 ) ) ;
F_13 ( & V_14 -> V_51 ) ;
V_29 = F_566 ( V_118 , V_64 , & V_21 , & V_96 ,
sizeof( V_96 ) ) ;
if ( V_29 )
F_162 ( V_118 , V_29 ) ;
V_29 = F_567 ( V_118 , V_64 ,
V_21 . V_22 , V_21 . V_33 ) ;
if ( V_29 )
F_162 ( V_118 , V_29 ) ;
F_568 ( V_118 , V_35 -> V_37 , V_14 ) ;
V_80:
F_274 ( & V_14 -> V_535 ) ;
}
V_118 -> V_277 = V_277 ;
}
int F_569 ( struct V_117 * V_118 ,
struct V_34 * V_35 , T_2 V_94 ,
T_2 type , T_2 V_722 , T_2 V_723 ,
T_2 V_60 )
{
int V_29 ;
struct V_34 * V_64 ;
struct V_1 * V_2 ;
V_64 = V_35 -> V_37 -> V_64 ;
F_570 ( V_35 -> V_37 , V_118 ) ;
V_2 = F_555 ( V_35 , V_723 , V_60 ) ;
if ( ! V_2 )
return - V_74 ;
F_403 ( & V_2 -> V_96 , V_94 ) ;
F_571 ( & V_2 -> V_96 , V_722 ) ;
F_572 ( & V_2 -> V_96 , type ) ;
V_2 -> V_7 = type ;
V_2 -> V_106 = ( T_2 ) - 1 ;
V_2 -> V_3 = V_4 ;
V_2 -> V_724 = 1 ;
V_29 = F_21 ( V_35 , V_2 ) ;
if ( V_29 ) {
F_19 ( V_35 , V_2 ) ;
F_6 ( V_2 ) ;
return V_29 ;
}
F_29 ( V_2 , V_35 -> V_37 , V_723 ,
V_723 + V_60 ) ;
F_19 ( V_35 , V_2 ) ;
#ifdef F_36
if ( F_37 ( V_35 , V_2 ) ) {
T_2 V_725 = V_60 - V_94 ;
V_94 += V_725 >> 1 ;
F_27 ( V_35 , V_2 ) ;
}
#endif
V_29 = F_287 ( V_35 -> V_37 , V_2 -> V_7 , 0 , 0 , 0 ,
& V_2 -> V_95 ) ;
if ( V_29 ) {
F_547 ( V_2 ) ;
F_6 ( V_2 ) ;
return V_29 ;
}
V_29 = F_10 ( V_35 -> V_37 , V_2 ) ;
if ( V_29 ) {
F_547 ( V_2 ) ;
F_6 ( V_2 ) ;
return V_29 ;
}
F_564 ( V_35 -> V_37 , V_2 , 1 ) ;
V_29 = F_287 ( V_35 -> V_37 , V_2 -> V_7 , V_60 , V_94 ,
V_2 -> V_45 , & V_2 -> V_95 ) ;
if ( V_29 ) {
F_547 ( V_2 ) ;
F_11 ( & V_35 -> V_37 -> V_18 ) ;
F_194 ( & V_2 -> V_20 ,
& V_35 -> V_37 -> V_19 ) ;
F_546 ( & V_2 -> V_20 ) ;
F_13 ( & V_35 -> V_37 -> V_18 ) ;
F_6 ( V_2 ) ;
return V_29 ;
}
F_377 ( V_35 -> V_37 ) ;
F_551 ( V_2 -> V_95 , V_2 ) ;
F_72 ( & V_2 -> V_535 , & V_118 -> V_280 ) ;
F_294 ( V_64 -> V_37 , type ) ;
return 0 ;
}
static void F_573 ( struct V_12 * V_37 , T_2 V_7 )
{
T_2 V_368 = F_295 ( V_7 ) &
V_369 ;
F_296 ( & V_37 -> V_370 ) ;
if ( V_7 & V_338 )
V_37 -> V_371 &= ~ V_368 ;
if ( V_7 & V_54 )
V_37 -> V_372 &= ~ V_368 ;
if ( V_7 & V_339 )
V_37 -> V_373 &= ~ V_368 ;
F_297 ( & V_37 -> V_370 ) ;
}
int F_574 ( struct V_117 * V_118 ,
struct V_34 * V_35 , T_2 V_726 ,
struct V_705 * V_706 )
{
struct V_65 * V_66 ;
struct V_1 * V_14 ;
struct V_546 * V_554 ;
struct V_34 * V_88 = V_35 -> V_37 -> V_88 ;
struct V_69 V_21 ;
struct V_297 * V_297 ;
struct V_708 * V_364 = NULL ;
int V_29 ;
int V_596 ;
int V_342 ;
struct V_49 * V_52 = NULL ;
bool V_727 ;
V_35 = V_35 -> V_37 -> V_64 ;
V_14 = F_76 ( V_35 -> V_37 , V_726 ) ;
F_32 ( ! V_14 ) ;
F_32 ( ! V_14 -> V_306 ) ;
F_19 ( V_35 , V_14 ) ;
memcpy ( & V_21 , & V_14 -> V_21 , sizeof( V_21 ) ) ;
V_596 = F_439 ( V_14 ) ;
if ( V_14 -> V_7 & ( V_343 |
V_344 |
V_345 ) )
V_342 = 2 ;
else
V_342 = 1 ;
V_554 = & V_35 -> V_37 -> V_552 ;
F_11 ( & V_554 -> V_590 ) ;
F_450 ( V_14 , V_554 ) ;
F_13 ( & V_554 -> V_590 ) ;
V_554 = & V_35 -> V_37 -> V_550 ;
F_11 ( & V_554 -> V_590 ) ;
F_450 ( V_14 , V_554 ) ;
F_13 ( & V_554 -> V_590 ) ;
V_66 = F_34 () ;
if ( ! V_66 ) {
V_29 = - V_74 ;
goto V_81;
}
V_297 = F_256 ( V_88 , V_14 , V_66 ) ;
F_49 ( & V_118 -> V_135 -> V_328 ) ;
F_11 ( & V_118 -> V_135 -> V_327 ) ;
if ( ! F_182 ( & V_14 -> V_330 ) ) {
F_274 ( & V_14 -> V_330 ) ;
F_8 ( ! F_216 ( V_297 ) && V_297 != V_14 -> V_331 . V_297 ) ;
F_13 ( & V_118 -> V_135 -> V_327 ) ;
F_275 ( V_35 , V_118 , V_14 ,
& V_14 -> V_331 , V_66 ,
V_14 -> V_21 . V_22 ) ;
F_6 ( V_14 ) ;
F_11 ( & V_118 -> V_135 -> V_327 ) ;
}
if ( ! F_182 ( & V_14 -> V_329 ) ) {
F_274 ( & V_14 -> V_329 ) ;
F_6 ( V_14 ) ;
}
F_13 ( & V_118 -> V_135 -> V_327 ) ;
F_47 ( & V_118 -> V_135 -> V_328 ) ;
if ( ! F_216 ( V_297 ) ) {
V_29 = F_575 ( V_118 , V_297 ) ;
if ( V_29 ) {
F_576 ( V_297 ) ;
goto V_81;
}
F_577 ( V_297 ) ;
F_11 ( & V_14 -> V_51 ) ;
if ( V_14 -> V_173 ) {
V_14 -> V_173 = 0 ;
V_14 -> V_297 = NULL ;
F_13 ( & V_14 -> V_51 ) ;
F_267 ( V_297 ) ;
} else {
F_13 ( & V_14 -> V_51 ) ;
}
F_576 ( V_297 ) ;
}
V_21 . V_22 = V_728 ;
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
F_546 ( & V_14 -> V_20 ) ;
if ( V_35 -> V_37 -> V_26 == V_14 -> V_21 . V_22 )
V_35 -> V_37 -> V_26 = ( T_2 ) - 1 ;
F_13 ( & V_35 -> V_37 -> V_18 ) ;
F_71 ( & V_14 -> V_95 -> V_352 ) ;
F_274 ( & V_14 -> V_99 ) ;
if ( F_182 ( & V_14 -> V_95 -> V_351 [ V_596 ] ) ) {
V_364 = V_14 -> V_95 -> V_709 [ V_596 ] ;
V_14 -> V_95 -> V_709 [ V_596 ] = NULL ;
F_573 ( V_35 -> V_37 , V_14 -> V_7 ) ;
}
F_73 ( & V_14 -> V_95 -> V_352 ) ;
if ( V_364 ) {
F_549 ( V_364 ) ;
F_550 ( V_364 ) ;
}
if ( V_14 -> V_108 )
V_52 = F_25 ( V_14 ) ;
if ( V_14 -> V_3 == V_107 )
F_437 ( V_14 ) ;
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
F_11 ( & V_118 -> V_135 -> V_327 ) ;
if ( ! F_182 ( & V_14 -> V_329 ) ) {
F_8 ( 1 ) ;
}
if ( ! F_182 ( & V_14 -> V_330 ) ) {
F_8 ( 1 ) ;
}
F_13 ( & V_118 -> V_135 -> V_327 ) ;
F_547 ( V_14 ) ;
F_11 ( & V_14 -> V_95 -> V_51 ) ;
F_274 ( & V_14 -> V_689 ) ;
if ( F_263 ( V_35 -> V_37 , V_421 ) ) {
F_8 ( V_14 -> V_95 -> V_340
< V_14 -> V_21 . V_33 ) ;
F_8 ( V_14 -> V_95 -> V_341
< V_14 -> V_21 . V_33 ) ;
F_8 ( V_14 -> V_95 -> V_346
< V_14 -> V_21 . V_33 * V_342 ) ;
}
V_14 -> V_95 -> V_340 -= V_14 -> V_21 . V_33 ;
V_14 -> V_95 -> V_341 -= V_14 -> V_21 . V_33 ;
V_14 -> V_95 -> V_346 -= V_14 -> V_21 . V_33 * V_342 ;
F_13 ( & V_14 -> V_95 -> V_51 ) ;
memcpy ( & V_21 , & V_14 -> V_21 , sizeof( V_21 ) ) ;
F_532 ( V_35 ) ;
if ( ! F_182 ( & V_706 -> V_99 ) ) {
F_543 ( V_706 ) ;
}
F_11 ( & V_14 -> V_51 ) ;
V_14 -> V_729 = 1 ;
V_727 = ( F_212 ( & V_14 -> V_716 ) == 0 ) ;
if ( ! V_727 ) {
F_578 ( & V_706 -> V_99 , & V_35 -> V_37 -> V_730 ) ;
}
F_13 ( & V_14 -> V_51 ) ;
if ( V_727 ) {
struct V_703 * V_704 ;
V_704 = & V_35 -> V_37 -> V_47 . V_707 ;
F_579 ( & V_704 -> V_51 ) ;
F_580 ( V_704 , V_706 ) ;
F_581 ( & V_704 -> V_51 ) ;
F_543 ( V_706 ) ;
}
F_533 ( V_35 ) ;
V_29 = F_582 ( V_118 , V_35 -> V_37 , V_14 ) ;
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
F_583 ( struct V_12 * V_37 ,
const T_2 V_723 )
{
struct V_703 * V_704 = & V_37 -> V_47 . V_707 ;
struct V_705 * V_706 ;
struct V_731 * V_732 ;
unsigned int V_733 ;
F_540 ( & V_704 -> V_51 ) ;
V_706 = F_541 ( V_704 , V_723 , 1 ) ;
F_542 ( & V_704 -> V_51 ) ;
ASSERT ( V_706 && V_706 -> V_32 == V_723 ) ;
V_732 = V_706 -> V_731 ;
V_733 = 3 + V_732 -> V_211 ;
F_543 ( V_706 ) ;
return F_584 ( V_37 -> V_64 ,
V_733 , 1 ) ;
}
void F_585 ( struct V_12 * V_37 )
{
struct V_1 * V_14 ;
struct V_111 * V_95 ;
struct V_34 * V_35 = V_37 -> V_64 ;
struct V_117 * V_118 ;
int V_29 = 0 ;
if ( ! V_37 -> V_734 )
return;
F_11 ( & V_37 -> V_534 ) ;
while ( ! F_182 ( & V_37 -> V_536 ) ) {
T_2 V_32 , V_31 ;
int V_716 ;
V_14 = F_273 ( & V_37 -> V_536 ,
struct V_1 ,
V_535 ) ;
F_274 ( & V_14 -> V_535 ) ;
V_95 = V_14 -> V_95 ;
if ( V_29 || F_332 ( V_95 ) ) {
F_6 ( V_14 ) ;
continue;
}
F_13 ( & V_37 -> V_534 ) ;
F_49 ( & V_37 -> V_735 ) ;
F_71 ( & V_95 -> V_352 ) ;
F_11 ( & V_14 -> V_51 ) ;
if ( V_14 -> V_10 ||
F_58 ( & V_14 -> V_96 ) ||
V_14 -> V_306 ||
F_586 ( & V_14 -> V_99 ) ) {
F_13 ( & V_14 -> V_51 ) ;
F_73 ( & V_95 -> V_352 ) ;
goto V_80;
}
F_13 ( & V_14 -> V_51 ) ;
V_29 = F_529 ( V_14 , 0 ) ;
F_73 ( & V_95 -> V_352 ) ;
if ( V_29 < 0 ) {
V_29 = 0 ;
goto V_80;
}
V_118 = F_583 ( V_37 ,
V_14 -> V_21 . V_22 ) ;
if ( F_216 ( V_118 ) ) {
F_536 ( V_35 , V_14 ) ;
V_29 = F_217 ( V_118 ) ;
goto V_80;
}
V_32 = V_14 -> V_21 . V_22 ;
V_31 = V_32 + V_14 -> V_21 . V_33 - 1 ;
F_49 ( & V_37 -> V_561 ) ;
V_29 = F_20 ( & V_37 -> V_38 [ 0 ] , V_32 , V_31 ,
V_63 ) ;
if ( V_29 ) {
F_47 ( & V_37 -> V_561 ) ;
F_536 ( V_35 , V_14 ) ;
goto V_736;
}
V_29 = F_20 ( & V_37 -> V_38 [ 1 ] , V_32 , V_31 ,
V_63 ) ;
if ( V_29 ) {
F_47 ( & V_37 -> V_561 ) ;
F_536 ( V_35 , V_14 ) ;
goto V_736;
}
F_47 ( & V_37 -> V_561 ) ;
F_11 ( & V_95 -> V_51 ) ;
F_11 ( & V_14 -> V_51 ) ;
V_95 -> V_353 -= V_14 -> V_9 ;
V_95 -> V_341 += V_14 -> V_9 ;
F_418 ( & V_95 -> V_348 ,
- V_14 -> V_9 ) ;
V_14 -> V_9 = 0 ;
F_13 ( & V_14 -> V_51 ) ;
F_13 ( & V_95 -> V_51 ) ;
V_716 = F_263 ( V_35 -> V_37 , V_562 ) ;
if ( V_716 )
F_587 ( V_14 ) ;
V_29 = F_588 ( V_118 , V_35 ,
V_14 -> V_21 . V_22 ) ;
if ( V_29 ) {
if ( V_716 )
F_421 ( V_14 ) ;
goto V_736;
}
if ( V_716 ) {
F_11 ( & V_37 -> V_534 ) ;
F_589 ( & V_14 -> V_535 ,
& V_118 -> V_135 -> V_558 ) ;
F_13 ( & V_37 -> V_534 ) ;
F_4 ( V_14 ) ;
}
V_736:
F_219 ( V_118 , V_35 ) ;
V_80:
F_47 ( & V_37 -> V_735 ) ;
F_6 ( V_14 ) ;
F_11 ( & V_37 -> V_534 ) ;
}
F_13 ( & V_37 -> V_534 ) ;
}
int F_590 ( struct V_12 * V_37 )
{
struct V_111 * V_95 ;
struct V_737 * V_738 ;
T_2 V_739 ;
T_2 V_7 ;
int V_740 = 0 ;
int V_29 ;
V_738 = V_37 -> V_260 ;
if ( ! F_591 ( V_738 ) )
return - V_538 ;
V_739 = F_592 ( V_738 ) ;
if ( V_739 & V_741 )
V_740 = 1 ;
V_7 = V_339 ;
V_29 = F_287 ( V_37 , V_7 , 0 , 0 , 0 , & V_95 ) ;
if ( V_29 )
goto V_81;
if ( V_740 ) {
V_7 = V_54 | V_338 ;
V_29 = F_287 ( V_37 , V_7 , 0 , 0 , 0 , & V_95 ) ;
} else {
V_7 = V_54 ;
V_29 = F_287 ( V_37 , V_7 , 0 , 0 , 0 , & V_95 ) ;
if ( V_29 )
goto V_81;
V_7 = V_338 ;
V_29 = F_287 ( V_37 , V_7 , 0 , 0 , 0 , & V_95 ) ;
}
V_81:
return V_29 ;
}
int F_593 ( struct V_34 * V_35 , T_2 V_32 , T_2 V_31 )
{
return F_417 ( V_35 , V_32 , V_31 , false ) ;
}
static int F_594 ( struct V_695 * V_696 ,
T_2 V_742 , T_2 * V_563 )
{
T_2 V_32 = 0 , V_48 = 0 ;
int V_29 ;
* V_563 = 0 ;
if ( ! V_696 -> V_743 )
return 0 ;
if ( V_696 -> V_340 <= V_696 -> V_94 )
return 0 ;
V_29 = 0 ;
while ( 1 ) {
struct V_12 * V_37 = V_696 -> V_501 -> V_37 ;
struct V_317 * V_118 ;
T_2 V_212 ;
V_29 = F_595 ( & V_37 -> V_420 ) ;
if ( V_29 )
return V_29 ;
F_50 ( & V_37 -> V_84 ) ;
F_11 ( & V_37 -> V_744 ) ;
V_118 = V_37 -> V_745 ;
if ( V_118 )
F_5 ( & V_118 -> V_746 ) ;
F_13 ( & V_37 -> V_744 ) ;
V_29 = F_596 ( V_118 , V_696 , V_742 , V_32 ,
& V_32 , & V_48 ) ;
if ( V_118 )
F_597 ( V_118 ) ;
if ( V_29 ) {
F_46 ( & V_37 -> V_84 ) ;
F_47 ( & V_37 -> V_420 ) ;
if ( V_29 == - V_313 )
V_29 = 0 ;
break;
}
V_29 = F_148 ( V_696 -> V_195 , V_32 , V_48 , & V_212 ) ;
F_46 ( & V_37 -> V_84 ) ;
F_47 ( & V_37 -> V_420 ) ;
if ( V_29 )
break;
V_32 += V_48 ;
* V_563 += V_212 ;
if ( F_598 ( V_400 ) ) {
V_29 = - V_747 ;
break;
}
F_48 () ;
}
return V_29 ;
}
int F_599 ( struct V_34 * V_35 , struct V_748 * V_749 )
{
struct V_12 * V_37 = V_35 -> V_37 ;
struct V_1 * V_2 = NULL ;
struct V_695 * V_696 ;
struct V_112 * V_750 ;
T_2 V_751 ;
T_2 V_32 ;
T_2 V_31 ;
T_2 V_563 = 0 ;
T_2 V_340 = F_321 ( V_37 -> V_260 ) ;
int V_29 = 0 ;
if ( V_749 -> V_48 == V_340 )
V_2 = F_75 ( V_37 , V_749 -> V_32 ) ;
else
V_2 = F_76 ( V_37 , V_749 -> V_32 ) ;
while ( V_2 ) {
if ( V_2 -> V_21 . V_22 >= ( V_749 -> V_32 + V_749 -> V_48 ) ) {
F_6 ( V_2 ) ;
break;
}
V_32 = F_447 ( V_749 -> V_32 , V_2 -> V_21 . V_22 ) ;
V_31 = F_341 ( V_749 -> V_32 + V_749 -> V_48 ,
V_2 -> V_21 . V_22 + V_2 -> V_21 . V_33 ) ;
if ( V_31 - V_32 >= V_749 -> V_742 ) {
if ( ! F_1 ( V_2 ) ) {
V_29 = F_59 ( V_2 , 0 ) ;
if ( V_29 ) {
F_6 ( V_2 ) ;
break;
}
V_29 = F_437 ( V_2 ) ;
if ( V_29 ) {
F_6 ( V_2 ) ;
break;
}
}
V_29 = F_600 ( V_2 ,
& V_751 ,
V_32 ,
V_31 ,
V_749 -> V_742 ) ;
V_563 += V_751 ;
if ( V_29 ) {
F_6 ( V_2 ) ;
break;
}
}
V_2 = F_253 ( V_37 -> V_88 , V_2 ) ;
}
F_49 ( & V_35 -> V_37 -> V_383 -> V_752 ) ;
V_750 = & V_35 -> V_37 -> V_383 -> V_753 ;
F_183 (device, devices, dev_alloc_list) {
V_29 = F_594 ( V_696 , V_749 -> V_742 ,
& V_751 ) ;
if ( V_29 )
break;
V_563 += V_751 ;
}
F_47 ( & V_35 -> V_37 -> V_383 -> V_752 ) ;
V_749 -> V_48 = V_563 ;
return V_29 ;
}
void F_601 ( struct V_34 * V_35 )
{
F_602 ( & V_35 -> V_754 -> V_755 ) ;
F_2 () ;
if ( F_603 ( & V_35 -> V_754 -> V_90 ) )
F_52 ( & V_35 -> V_754 -> V_90 ) ;
}
int F_604 ( struct V_34 * V_35 )
{
if ( F_212 ( & V_35 -> V_756 ) )
return 0 ;
F_605 ( & V_35 -> V_754 -> V_755 ) ;
F_2 () ;
if ( F_212 ( & V_35 -> V_756 ) ) {
F_601 ( V_35 ) ;
return 0 ;
}
return 1 ;
}
static int F_606 ( T_7 * V_337 )
{
F_68 () ;
return 0 ;
}
void F_607 ( struct V_34 * V_35 )
{
while ( true ) {
int V_29 ;
V_29 = F_604 ( V_35 ) ;
if ( V_29 )
break;
F_285 ( & V_35 -> V_756 ,
F_606 ,
V_102 ) ;
}
}
