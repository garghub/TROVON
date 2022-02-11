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
T_2 F_29 ( struct V_1 * V_14 ,
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
static int F_33 ( struct V_50 * V_53 )
{
struct V_1 * V_14 ;
struct V_12 * V_37 ;
struct V_34 * V_65 ;
struct V_66 * V_67 ;
struct V_68 * V_69 ;
struct V_70 V_21 ;
T_2 V_71 = 0 ;
T_2 V_72 = 0 ;
T_3 V_73 ;
int V_29 ;
bool V_74 = true ;
V_14 = V_53 -> V_14 ;
V_37 = V_14 -> V_37 ;
V_65 = V_37 -> V_65 ;
V_67 = F_34 () ;
if ( ! V_67 )
return - V_75 ;
V_72 = F_35 ( T_2 , V_14 -> V_21 . V_22 , V_45 ) ;
#ifdef F_36
if ( F_37 ( V_65 , V_14 ) )
V_74 = false ;
#endif
V_67 -> V_76 = 1 ;
V_67 -> V_77 = 1 ;
V_67 -> V_78 = V_79 ;
V_21 . V_22 = V_72 ;
V_21 . V_33 = 0 ;
V_21 . type = V_80 ;
V_81:
V_29 = F_38 ( NULL , V_65 , & V_21 , V_67 , 0 , 0 ) ;
if ( V_29 < 0 )
goto V_82;
V_69 = V_67 -> V_83 [ 0 ] ;
V_73 = F_39 ( V_69 ) ;
while ( 1 ) {
if ( F_40 ( V_37 ) > 1 ) {
V_72 = ( T_2 ) - 1 ;
break;
}
if ( V_67 -> V_84 [ 0 ] < V_73 ) {
F_41 ( V_69 , & V_21 , V_67 -> V_84 [ 0 ] ) ;
} else {
V_29 = F_42 ( V_67 , 0 , & V_21 ) ;
if ( V_29 )
break;
if ( F_43 () ||
F_44 ( & V_37 -> V_85 ) ) {
if ( V_74 )
V_53 -> V_86 = V_72 ;
F_45 ( V_67 ) ;
F_46 ( & V_37 -> V_85 ) ;
F_47 ( & V_53 -> V_87 ) ;
F_48 () ;
F_49 ( & V_53 -> V_87 ) ;
F_50 ( & V_37 -> V_85 ) ;
goto V_81;
}
V_29 = F_51 ( V_65 , V_67 ) ;
if ( V_29 < 0 )
goto V_82;
if ( V_29 )
break;
V_69 = V_67 -> V_83 [ 0 ] ;
V_73 = F_39 ( V_69 ) ;
continue;
}
if ( V_21 . V_22 < V_72 ) {
V_21 . V_22 = V_72 ;
V_21 . V_33 = 0 ;
V_21 . type = V_80 ;
if ( V_74 )
V_53 -> V_86 = V_72 ;
F_45 ( V_67 ) ;
goto V_81;
}
if ( V_21 . V_22 < V_14 -> V_21 . V_22 ) {
V_67 -> V_84 [ 0 ] ++ ;
continue;
}
if ( V_21 . V_22 >= V_14 -> V_21 . V_22 +
V_14 -> V_21 . V_33 )
break;
if ( V_21 . type == V_80 ||
V_21 . type == V_88 ) {
V_71 += F_29 ( V_14 ,
V_37 , V_72 ,
V_21 . V_22 ) ;
if ( V_21 . type == V_88 )
V_72 = V_21 . V_22 +
V_37 -> V_89 -> V_56 ;
else
V_72 = V_21 . V_22 + V_21 . V_33 ;
if ( V_71 > V_90 ) {
V_71 = 0 ;
if ( V_74 )
F_52 ( & V_53 -> V_91 ) ;
}
}
V_67 -> V_84 [ 0 ] ++ ;
}
V_29 = 0 ;
V_71 += F_29 ( V_14 , V_37 , V_72 ,
V_14 -> V_21 . V_22 +
V_14 -> V_21 . V_33 ) ;
V_53 -> V_86 = ( T_2 ) - 1 ;
V_82:
F_53 ( V_67 ) ;
return V_29 ;
}
static T_1 void F_54 ( struct V_92 * V_93 )
{
struct V_1 * V_14 ;
struct V_12 * V_37 ;
struct V_50 * V_53 ;
struct V_34 * V_65 ;
int V_29 ;
V_53 = F_55 ( V_93 , struct V_50 , V_93 ) ;
V_14 = V_53 -> V_14 ;
V_37 = V_14 -> V_37 ;
V_65 = V_37 -> V_65 ;
F_49 ( & V_53 -> V_87 ) ;
F_50 ( & V_37 -> V_85 ) ;
if ( F_56 ( V_37 , V_94 ) )
V_29 = F_57 ( V_53 ) ;
else
V_29 = F_33 ( V_53 ) ;
F_11 ( & V_14 -> V_52 ) ;
V_14 -> V_53 = NULL ;
V_14 -> V_3 = V_29 ? V_5 : V_4 ;
F_13 ( & V_14 -> V_52 ) ;
#ifdef F_36
if ( F_37 ( V_65 , V_14 ) ) {
T_2 V_95 ;
F_11 ( & V_14 -> V_96 -> V_52 ) ;
F_11 ( & V_14 -> V_52 ) ;
V_95 = V_14 -> V_21 . V_33 -
F_58 ( & V_14 -> V_97 ) ;
V_14 -> V_96 -> V_95 += V_95 >> 1 ;
F_13 ( & V_14 -> V_52 ) ;
F_13 ( & V_14 -> V_96 -> V_52 ) ;
F_27 ( V_65 , V_14 ) ;
}
#endif
V_53 -> V_86 = ( T_2 ) - 1 ;
F_46 ( & V_37 -> V_85 ) ;
F_19 ( V_37 -> V_65 , V_14 ) ;
F_47 ( & V_53 -> V_87 ) ;
F_52 ( & V_53 -> V_91 ) ;
F_26 ( V_53 ) ;
F_6 ( V_14 ) ;
}
static int F_59 ( struct V_1 * V_2 ,
int V_98 )
{
F_60 ( V_91 ) ;
struct V_12 * V_37 = V_2 -> V_37 ;
struct V_50 * V_53 ;
int V_29 = 0 ;
V_53 = F_61 ( sizeof( * V_53 ) , V_40 ) ;
if ( ! V_53 )
return - V_75 ;
F_62 ( & V_53 -> V_99 ) ;
F_63 ( & V_53 -> V_87 ) ;
F_64 ( & V_53 -> V_91 ) ;
V_53 -> V_14 = V_2 ;
V_53 -> V_86 = V_2 -> V_21 . V_22 ;
F_65 ( & V_53 -> V_8 , 1 ) ;
F_66 ( & V_53 -> V_93 , V_100 ,
F_54 , NULL , NULL ) ;
F_11 ( & V_2 -> V_52 ) ;
while ( V_2 -> V_3 == V_101 ) {
struct V_50 * V_51 ;
V_51 = V_2 -> V_53 ;
F_5 ( & V_51 -> V_8 ) ;
F_67 ( & V_51 -> V_91 , & V_91 , V_102 ) ;
F_13 ( & V_2 -> V_52 ) ;
F_68 () ;
F_69 ( & V_51 -> V_91 , & V_91 ) ;
F_26 ( V_51 ) ;
F_11 ( & V_2 -> V_52 ) ;
}
if ( V_2 -> V_3 != V_103 ) {
F_13 ( & V_2 -> V_52 ) ;
F_9 ( V_53 ) ;
return 0 ;
}
F_8 ( V_2 -> V_53 ) ;
V_2 -> V_53 = V_53 ;
V_2 -> V_3 = V_101 ;
F_13 ( & V_2 -> V_52 ) ;
if ( V_37 -> V_104 & V_105 ) {
F_49 ( & V_53 -> V_87 ) ;
V_29 = F_70 ( V_37 , V_2 ) ;
F_11 ( & V_2 -> V_52 ) ;
if ( V_29 == 1 ) {
V_2 -> V_53 = NULL ;
V_2 -> V_3 = V_4 ;
V_2 -> V_106 = ( T_2 ) - 1 ;
V_53 -> V_86 = ( T_2 ) - 1 ;
} else {
if ( V_98 ) {
V_2 -> V_53 = NULL ;
V_2 -> V_3 = V_103 ;
} else {
V_2 -> V_3 = V_107 ;
V_2 -> V_108 = 1 ;
}
}
F_13 ( & V_2 -> V_52 ) ;
#ifdef F_36
if ( V_29 == 1 &&
F_37 ( V_37 -> V_65 ,
V_2 ) ) {
T_2 V_95 ;
F_11 ( & V_2 -> V_96 -> V_52 ) ;
F_11 ( & V_2 -> V_52 ) ;
V_95 = V_2 -> V_21 . V_33 -
F_58 ( & V_2 -> V_97 ) ;
V_2 -> V_96 -> V_95 += V_95 >> 1 ;
F_13 ( & V_2 -> V_52 ) ;
F_13 ( & V_2 -> V_96 -> V_52 ) ;
F_27 ( V_37 -> V_65 , V_2 ) ;
}
#endif
F_47 ( & V_53 -> V_87 ) ;
F_52 ( & V_53 -> V_91 ) ;
if ( V_29 == 1 ) {
F_26 ( V_53 ) ;
F_19 ( V_37 -> V_65 , V_2 ) ;
return 0 ;
}
} else {
F_11 ( & V_2 -> V_52 ) ;
if ( V_98 ) {
V_2 -> V_53 = NULL ;
V_2 -> V_3 = V_103 ;
} else {
V_2 -> V_3 = V_107 ;
V_2 -> V_108 = 1 ;
}
F_13 ( & V_2 -> V_52 ) ;
F_52 ( & V_53 -> V_91 ) ;
}
if ( V_98 ) {
F_26 ( V_53 ) ;
return 0 ;
}
F_71 ( & V_37 -> V_85 ) ;
F_5 ( & V_53 -> V_8 ) ;
F_72 ( & V_53 -> V_99 , & V_37 -> V_109 ) ;
F_73 ( & V_37 -> V_85 ) ;
F_4 ( V_2 ) ;
F_74 ( V_37 -> V_110 , & V_53 -> V_93 ) ;
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
struct V_112 * V_113 = & V_13 -> V_96 ;
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
struct V_112 * V_113 = & V_13 -> V_96 ;
struct V_111 * V_114 ;
F_78 () ;
F_79 (found, head, list)
V_114 -> V_116 = 0 ;
F_80 () ;
}
int F_82 ( struct V_34 * V_35 , T_2 V_32 , T_2 V_49 )
{
int V_29 ;
struct V_70 V_21 ;
struct V_66 * V_67 ;
V_67 = F_34 () ;
if ( ! V_67 )
return - V_75 ;
V_21 . V_22 = V_32 ;
V_21 . V_33 = V_49 ;
V_21 . type = V_80 ;
V_29 = F_38 ( NULL , V_35 -> V_37 -> V_65 , & V_21 , V_67 ,
0 , 0 ) ;
F_53 ( V_67 ) ;
return V_29 ;
}
int F_83 ( struct V_117 * V_118 ,
struct V_34 * V_35 , T_2 V_27 ,
T_2 V_33 , int V_119 , T_2 * V_120 , T_2 * V_7 )
{
struct V_121 * V_113 ;
struct V_122 * V_123 ;
struct V_66 * V_67 ;
struct V_124 * V_125 ;
struct V_68 * V_69 ;
struct V_70 V_21 ;
T_3 V_126 ;
T_2 V_127 ;
T_2 V_128 ;
int V_29 ;
if ( V_119 && ! F_84 ( V_35 -> V_37 , V_129 ) ) {
V_33 = V_35 -> V_56 ;
V_119 = 0 ;
}
V_67 = F_34 () ;
if ( ! V_67 )
return - V_75 ;
if ( ! V_118 ) {
V_67 -> V_76 = 1 ;
V_67 -> V_77 = 1 ;
}
V_130:
V_21 . V_22 = V_27 ;
V_21 . V_33 = V_33 ;
if ( V_119 )
V_21 . type = V_88 ;
else
V_21 . type = V_80 ;
V_29 = F_38 ( V_118 , V_35 -> V_37 -> V_65 ,
& V_21 , V_67 , 0 , 0 ) ;
if ( V_29 < 0 )
goto V_131;
if ( V_29 > 0 && V_119 && V_21 . type == V_88 ) {
if ( V_67 -> V_84 [ 0 ] ) {
V_67 -> V_84 [ 0 ] -- ;
F_41 ( V_67 -> V_83 [ 0 ] , & V_21 ,
V_67 -> V_84 [ 0 ] ) ;
if ( V_21 . V_22 == V_27 &&
V_21 . type == V_80 &&
V_21 . V_33 == V_35 -> V_56 )
V_29 = 0 ;
}
}
if ( V_29 == 0 ) {
V_69 = V_67 -> V_83 [ 0 ] ;
V_126 = F_85 ( V_69 , V_67 -> V_84 [ 0 ] ) ;
if ( V_126 >= sizeof( * V_125 ) ) {
V_125 = F_86 ( V_69 , V_67 -> V_84 [ 0 ] ,
struct V_124 ) ;
V_127 = F_87 ( V_69 , V_125 ) ;
V_128 = F_88 ( V_69 , V_125 ) ;
} else {
#ifdef F_89
struct V_132 * V_133 ;
F_32 ( V_126 != sizeof( * V_133 ) ) ;
V_133 = F_86 ( V_69 , V_67 -> V_84 [ 0 ] ,
struct V_132 ) ;
V_127 = F_90 ( V_69 , V_133 ) ;
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
goto V_82;
V_123 = & V_118 -> V_135 -> V_123 ;
F_11 ( & V_123 -> V_52 ) ;
V_113 = F_92 ( V_118 , V_27 ) ;
if ( V_113 ) {
if ( ! F_93 ( & V_113 -> V_87 ) ) {
F_5 ( & V_113 -> V_136 . V_120 ) ;
F_13 ( & V_123 -> V_52 ) ;
F_45 ( V_67 ) ;
F_49 ( & V_113 -> V_87 ) ;
F_47 ( & V_113 -> V_87 ) ;
F_94 ( & V_113 -> V_136 ) ;
goto V_130;
}
F_11 ( & V_113 -> V_52 ) ;
if ( V_113 -> V_137 && V_113 -> V_137 -> V_138 )
V_128 |= V_113 -> V_137 -> V_139 ;
else
F_32 ( V_127 == 0 ) ;
V_127 += V_113 -> V_136 . V_140 ;
F_13 ( & V_113 -> V_52 ) ;
F_47 ( & V_113 -> V_87 ) ;
}
F_13 ( & V_123 -> V_52 ) ;
V_82:
F_8 ( V_127 == 0 ) ;
if ( V_120 )
* V_120 = V_127 ;
if ( V_7 )
* V_7 = V_128 ;
V_131:
F_53 ( V_67 ) ;
return V_29 ;
}
static int F_95 ( struct V_117 * V_118 ,
struct V_34 * V_35 ,
struct V_66 * V_67 ,
T_2 V_141 , T_3 V_142 )
{
struct V_124 * V_97 ;
struct V_132 * V_133 ;
struct V_143 * V_144 ;
struct V_145 * V_146 ;
struct V_68 * V_69 ;
struct V_70 V_21 ;
struct V_70 V_147 ;
T_3 V_148 = sizeof( * V_97 ) ;
T_2 V_120 ;
int V_29 ;
V_69 = V_67 -> V_83 [ 0 ] ;
F_32 ( F_85 ( V_69 , V_67 -> V_84 [ 0 ] ) != sizeof( * V_133 ) ) ;
F_41 ( V_69 , & V_21 , V_67 -> V_84 [ 0 ] ) ;
V_133 = F_86 ( V_69 , V_67 -> V_84 [ 0 ] ,
struct V_132 ) ;
V_120 = F_90 ( V_69 , V_133 ) ;
if ( V_141 == ( T_2 ) - 1 ) {
while ( 1 ) {
if ( V_67 -> V_84 [ 0 ] >= F_39 ( V_69 ) ) {
V_29 = F_51 ( V_35 , V_67 ) ;
if ( V_29 < 0 )
return V_29 ;
F_32 ( V_29 > 0 ) ;
V_69 = V_67 -> V_83 [ 0 ] ;
}
F_41 ( V_69 , & V_147 ,
V_67 -> V_84 [ 0 ] ) ;
F_32 ( V_21 . V_22 != V_147 . V_22 ) ;
if ( V_147 . type != V_149 ) {
V_67 -> V_84 [ 0 ] ++ ;
continue;
}
V_144 = F_86 ( V_69 , V_67 -> V_84 [ 0 ] ,
struct V_143 ) ;
V_141 = F_96 ( V_69 , V_144 ) ;
break;
}
}
F_45 ( V_67 ) ;
if ( V_141 < V_150 )
V_148 += sizeof( * V_146 ) ;
V_148 -= sizeof( * V_133 ) ;
V_29 = F_38 ( V_118 , V_35 , & V_21 , V_67 ,
V_148 + V_142 , 1 ) ;
if ( V_29 < 0 )
return V_29 ;
F_32 ( V_29 ) ;
F_97 ( V_35 , V_67 , V_148 ) ;
V_69 = V_67 -> V_83 [ 0 ] ;
V_97 = F_86 ( V_69 , V_67 -> V_84 [ 0 ] , struct V_124 ) ;
F_98 ( V_69 , V_97 , V_120 ) ;
F_99 ( V_69 , V_97 , 0 ) ;
if ( V_141 < V_150 ) {
F_100 ( V_69 , V_97 ,
V_151 |
V_134 ) ;
V_146 = (struct V_145 * ) ( V_97 + 1 ) ;
F_101 ( V_69 , 0 , ( unsigned long ) V_146 , sizeof( * V_146 ) ) ;
F_102 ( V_69 , V_146 , ( int ) V_141 ) ;
} else {
F_100 ( V_69 , V_97 , V_152 ) ;
}
F_103 ( V_69 ) ;
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
static T_2 F_107 ( struct V_68 * V_69 ,
struct V_157 * V_158 )
{
return F_104 ( F_108 ( V_69 , V_158 ) ,
F_109 ( V_69 , V_158 ) ,
F_110 ( V_69 , V_158 ) ) ;
}
static int F_111 ( struct V_68 * V_69 ,
struct V_157 * V_158 ,
T_2 V_153 , T_2 V_141 , T_2 V_33 )
{
if ( F_108 ( V_69 , V_158 ) != V_153 ||
F_109 ( V_69 , V_158 ) != V_141 ||
F_110 ( V_69 , V_158 ) != V_33 )
return 0 ;
return 1 ;
}
static T_1 int F_112 ( struct V_117 * V_118 ,
struct V_34 * V_35 ,
struct V_66 * V_67 ,
T_2 V_27 , T_2 V_17 ,
T_2 V_153 ,
T_2 V_141 , T_2 V_33 )
{
struct V_70 V_21 ;
struct V_157 * V_158 ;
struct V_68 * V_69 ;
T_3 V_73 ;
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
V_29 = F_38 ( V_118 , V_35 , & V_21 , V_67 , - 1 , 1 ) ;
if ( V_29 < 0 ) {
V_160 = V_29 ;
goto V_165;
}
if ( V_17 ) {
if ( ! V_29 )
return 0 ;
#ifdef F_89
V_21 . type = V_149 ;
F_45 ( V_67 ) ;
V_29 = F_38 ( V_118 , V_35 , & V_21 , V_67 , - 1 , 1 ) ;
if ( V_29 < 0 ) {
V_160 = V_29 ;
goto V_165;
}
if ( ! V_29 )
return 0 ;
#endif
goto V_165;
}
V_69 = V_67 -> V_83 [ 0 ] ;
V_73 = F_39 ( V_69 ) ;
while ( 1 ) {
if ( V_67 -> V_84 [ 0 ] >= V_73 ) {
V_29 = F_51 ( V_35 , V_67 ) ;
if ( V_29 < 0 )
V_160 = V_29 ;
if ( V_29 )
goto V_165;
V_69 = V_67 -> V_83 [ 0 ] ;
V_73 = F_39 ( V_69 ) ;
V_159 = 1 ;
}
F_41 ( V_69 , & V_21 , V_67 -> V_84 [ 0 ] ) ;
if ( V_21 . V_22 != V_27 ||
V_21 . type != V_163 )
goto V_165;
V_158 = F_86 ( V_69 , V_67 -> V_84 [ 0 ] ,
struct V_157 ) ;
if ( F_111 ( V_69 , V_158 , V_153 ,
V_141 , V_33 ) ) {
if ( V_159 ) {
F_45 ( V_67 ) ;
goto V_164;
}
V_160 = 0 ;
break;
}
V_67 -> V_84 [ 0 ] ++ ;
}
V_165:
return V_160 ;
}
static T_1 int F_113 ( struct V_117 * V_118 ,
struct V_34 * V_35 ,
struct V_66 * V_67 ,
T_2 V_27 , T_2 V_17 ,
T_2 V_153 , T_2 V_141 ,
T_2 V_33 , int V_166 )
{
struct V_70 V_21 ;
struct V_68 * V_69 ;
T_3 V_61 ;
T_3 V_127 ;
int V_29 ;
V_21 . V_22 = V_27 ;
if ( V_17 ) {
V_21 . type = V_162 ;
V_21 . V_33 = V_17 ;
V_61 = sizeof( struct V_167 ) ;
} else {
V_21 . type = V_163 ;
V_21 . V_33 = F_104 ( V_153 ,
V_141 , V_33 ) ;
V_61 = sizeof( struct V_157 ) ;
}
V_29 = F_114 ( V_118 , V_35 , V_67 , & V_21 , V_61 ) ;
if ( V_29 && V_29 != - V_25 )
goto V_165;
V_69 = V_67 -> V_83 [ 0 ] ;
if ( V_17 ) {
struct V_167 * V_158 ;
V_158 = F_86 ( V_69 , V_67 -> V_84 [ 0 ] ,
struct V_167 ) ;
if ( V_29 == 0 ) {
F_115 ( V_69 , V_158 , V_166 ) ;
} else {
V_127 = F_116 ( V_69 , V_158 ) ;
V_127 += V_166 ;
F_115 ( V_69 , V_158 , V_127 ) ;
}
} else {
struct V_157 * V_158 ;
while ( V_29 == - V_25 ) {
V_158 = F_86 ( V_69 , V_67 -> V_84 [ 0 ] ,
struct V_157 ) ;
if ( F_111 ( V_69 , V_158 , V_153 ,
V_141 , V_33 ) )
break;
F_45 ( V_67 ) ;
V_21 . V_33 ++ ;
V_29 = F_114 ( V_118 , V_35 , V_67 , & V_21 ,
V_61 ) ;
if ( V_29 && V_29 != - V_25 )
goto V_165;
V_69 = V_67 -> V_83 [ 0 ] ;
}
V_158 = F_86 ( V_69 , V_67 -> V_84 [ 0 ] ,
struct V_157 ) ;
if ( V_29 == 0 ) {
F_117 ( V_69 , V_158 ,
V_153 ) ;
F_118 ( V_69 , V_158 , V_141 ) ;
F_119 ( V_69 , V_158 , V_33 ) ;
F_120 ( V_69 , V_158 , V_166 ) ;
} else {
V_127 = F_121 ( V_69 , V_158 ) ;
V_127 += V_166 ;
F_120 ( V_69 , V_158 , V_127 ) ;
}
}
F_103 ( V_69 ) ;
V_29 = 0 ;
V_165:
F_45 ( V_67 ) ;
return V_29 ;
}
static T_1 int F_122 ( struct V_117 * V_118 ,
struct V_34 * V_35 ,
struct V_66 * V_67 ,
int V_168 , int * V_169 )
{
struct V_70 V_21 ;
struct V_157 * V_170 = NULL ;
struct V_167 * V_171 = NULL ;
struct V_68 * V_69 ;
T_3 V_127 = 0 ;
int V_29 = 0 ;
V_69 = V_67 -> V_83 [ 0 ] ;
F_41 ( V_69 , & V_21 , V_67 -> V_84 [ 0 ] ) ;
if ( V_21 . type == V_163 ) {
V_170 = F_86 ( V_69 , V_67 -> V_84 [ 0 ] ,
struct V_157 ) ;
V_127 = F_121 ( V_69 , V_170 ) ;
} else if ( V_21 . type == V_162 ) {
V_171 = F_86 ( V_69 , V_67 -> V_84 [ 0 ] ,
struct V_167 ) ;
V_127 = F_116 ( V_69 , V_171 ) ;
#ifdef F_89
} else if ( V_21 . type == V_149 ) {
struct V_143 * V_144 ;
V_144 = F_86 ( V_69 , V_67 -> V_84 [ 0 ] ,
struct V_143 ) ;
V_127 = F_123 ( V_69 , V_144 ) ;
#endif
} else {
F_91 () ;
}
F_32 ( V_127 < V_168 ) ;
V_127 -= V_168 ;
if ( V_127 == 0 ) {
V_29 = F_124 ( V_118 , V_35 , V_67 ) ;
* V_169 = 1 ;
} else {
if ( V_21 . type == V_163 )
F_120 ( V_69 , V_170 , V_127 ) ;
else if ( V_21 . type == V_162 )
F_115 ( V_69 , V_171 , V_127 ) ;
#ifdef F_89
else {
struct V_143 * V_144 ;
V_144 = F_86 ( V_69 , V_67 -> V_84 [ 0 ] ,
struct V_143 ) ;
F_125 ( V_69 , V_144 , V_127 ) ;
}
#endif
F_103 ( V_69 ) ;
}
return V_29 ;
}
static T_1 T_3 F_126 ( struct V_66 * V_67 ,
struct V_172 * V_173 )
{
struct V_70 V_21 ;
struct V_68 * V_69 ;
struct V_157 * V_170 ;
struct V_167 * V_171 ;
T_3 V_127 = 0 ;
V_69 = V_67 -> V_83 [ 0 ] ;
F_41 ( V_69 , & V_21 , V_67 -> V_84 [ 0 ] ) ;
if ( V_173 ) {
if ( F_127 ( V_69 , V_173 ) ==
V_163 ) {
V_170 = (struct V_157 * ) ( & V_173 -> V_33 ) ;
V_127 = F_121 ( V_69 , V_170 ) ;
} else {
V_171 = (struct V_167 * ) ( V_173 + 1 ) ;
V_127 = F_116 ( V_69 , V_171 ) ;
}
} else if ( V_21 . type == V_163 ) {
V_170 = F_86 ( V_69 , V_67 -> V_84 [ 0 ] ,
struct V_157 ) ;
V_127 = F_121 ( V_69 , V_170 ) ;
} else if ( V_21 . type == V_162 ) {
V_171 = F_86 ( V_69 , V_67 -> V_84 [ 0 ] ,
struct V_167 ) ;
V_127 = F_116 ( V_69 , V_171 ) ;
#ifdef F_89
} else if ( V_21 . type == V_149 ) {
struct V_143 * V_144 ;
V_144 = F_86 ( V_69 , V_67 -> V_84 [ 0 ] ,
struct V_143 ) ;
V_127 = F_123 ( V_69 , V_144 ) ;
#endif
} else {
F_8 ( 1 ) ;
}
return V_127 ;
}
static T_1 int F_128 ( struct V_117 * V_118 ,
struct V_34 * V_35 ,
struct V_66 * V_67 ,
T_2 V_27 , T_2 V_17 ,
T_2 V_153 )
{
struct V_70 V_21 ;
int V_29 ;
V_21 . V_22 = V_27 ;
if ( V_17 ) {
V_21 . type = V_174 ;
V_21 . V_33 = V_17 ;
} else {
V_21 . type = V_175 ;
V_21 . V_33 = V_153 ;
}
V_29 = F_38 ( V_118 , V_35 , & V_21 , V_67 , - 1 , 1 ) ;
if ( V_29 > 0 )
V_29 = - V_161 ;
#ifdef F_89
if ( V_29 == - V_161 && V_17 ) {
F_45 ( V_67 ) ;
V_21 . type = V_149 ;
V_29 = F_38 ( V_118 , V_35 , & V_21 , V_67 , - 1 , 1 ) ;
if ( V_29 > 0 )
V_29 = - V_161 ;
}
#endif
return V_29 ;
}
static T_1 int F_129 ( struct V_117 * V_118 ,
struct V_34 * V_35 ,
struct V_66 * V_67 ,
T_2 V_27 , T_2 V_17 ,
T_2 V_153 )
{
struct V_70 V_21 ;
int V_29 ;
V_21 . V_22 = V_27 ;
if ( V_17 ) {
V_21 . type = V_174 ;
V_21 . V_33 = V_17 ;
} else {
V_21 . type = V_175 ;
V_21 . V_33 = V_153 ;
}
V_29 = F_114 ( V_118 , V_35 , V_67 , & V_21 , 0 ) ;
F_45 ( V_67 ) ;
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
static int F_42 ( struct V_66 * V_67 , int V_176 ,
struct V_70 * V_21 )
{
for (; V_176 < V_177 ; V_176 ++ ) {
if ( ! V_67 -> V_83 [ V_176 ] )
break;
if ( V_67 -> V_84 [ V_176 ] + 1 >=
F_39 ( V_67 -> V_83 [ V_176 ] ) )
continue;
if ( V_176 == 0 )
F_41 ( V_67 -> V_83 [ V_176 ] , V_21 ,
V_67 -> V_84 [ V_176 ] + 1 ) ;
else
F_131 ( V_67 -> V_83 [ V_176 ] , V_21 ,
V_67 -> V_84 [ V_176 ] + 1 ) ;
return 0 ;
}
return 1 ;
}
static T_5
int F_132 ( struct V_117 * V_118 ,
struct V_34 * V_35 ,
struct V_66 * V_67 ,
struct V_172 * * V_178 ,
T_2 V_27 , T_2 V_36 ,
T_2 V_17 , T_2 V_153 ,
T_2 V_141 , T_2 V_33 , int V_179 )
{
struct V_70 V_21 ;
struct V_68 * V_69 ;
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
V_21 . type = V_80 ;
V_21 . V_33 = V_36 ;
V_181 = F_130 ( V_17 , V_141 ) ;
if ( V_179 ) {
V_142 = F_133 ( V_181 ) ;
V_67 -> V_183 = 1 ;
} else
V_142 = - 1 ;
if ( V_182 && V_141 < V_150 ) {
V_21 . type = V_88 ;
V_21 . V_33 = V_141 ;
}
V_164:
V_29 = F_38 ( V_118 , V_35 , & V_21 , V_67 , V_142 , 1 ) ;
if ( V_29 < 0 ) {
V_160 = V_29 ;
goto V_82;
}
if ( V_29 > 0 && V_182 ) {
V_182 = false ;
if ( V_67 -> V_84 [ 0 ] ) {
V_67 -> V_84 [ 0 ] -- ;
F_41 ( V_67 -> V_83 [ 0 ] , & V_21 ,
V_67 -> V_84 [ 0 ] ) ;
if ( V_21 . V_22 == V_27 &&
V_21 . type == V_80 &&
V_21 . V_33 == V_36 )
V_29 = 0 ;
}
if ( V_29 ) {
V_21 . V_22 = V_27 ;
V_21 . type = V_80 ;
V_21 . V_33 = V_36 ;
F_45 ( V_67 ) ;
goto V_164;
}
}
if ( V_29 && ! V_179 ) {
V_160 = - V_161 ;
goto V_82;
} else if ( F_8 ( V_29 ) ) {
V_160 = - V_184 ;
goto V_82;
}
V_69 = V_67 -> V_83 [ 0 ] ;
V_126 = F_85 ( V_69 , V_67 -> V_84 [ 0 ] ) ;
#ifdef F_89
if ( V_126 < sizeof( * V_125 ) ) {
if ( ! V_179 ) {
V_160 = - V_161 ;
goto V_82;
}
V_29 = F_95 ( V_118 , V_35 , V_67 , V_141 ,
V_142 ) ;
if ( V_29 < 0 ) {
V_160 = V_29 ;
goto V_82;
}
V_69 = V_67 -> V_83 [ 0 ] ;
V_126 = F_85 ( V_69 , V_67 -> V_84 [ 0 ] ) ;
}
#endif
F_32 ( V_126 < sizeof( * V_125 ) ) ;
V_125 = F_86 ( V_69 , V_67 -> V_84 [ 0 ] , struct V_124 ) ;
V_7 = F_88 ( V_69 , V_125 ) ;
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
type = F_127 ( V_69 , V_173 ) ;
if ( V_181 < type )
break;
if ( V_181 > type ) {
V_180 += F_133 ( type ) ;
continue;
}
if ( type == V_163 ) {
struct V_157 * V_185 ;
V_185 = (struct V_157 * ) ( & V_173 -> V_33 ) ;
if ( F_111 ( V_69 , V_185 , V_153 ,
V_141 , V_33 ) ) {
V_160 = 0 ;
break;
}
if ( F_107 ( V_69 , V_185 ) <
F_104 ( V_153 , V_141 , V_33 ) )
break;
} else {
T_2 V_186 ;
V_186 = F_134 ( V_69 , V_173 ) ;
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
goto V_82;
}
if ( F_42 ( V_67 , 0 , & V_21 ) == 0 &&
V_21 . V_22 == V_27 &&
V_21 . type < V_188 ) {
V_160 = - V_187 ;
goto V_82;
}
}
* V_178 = (struct V_172 * ) V_180 ;
V_82:
if ( V_179 ) {
V_67 -> V_183 = 0 ;
F_136 ( V_67 , 1 ) ;
}
return V_160 ;
}
static T_5
void F_137 ( struct V_34 * V_35 ,
struct V_66 * V_67 ,
struct V_172 * V_173 ,
T_2 V_17 , T_2 V_153 ,
T_2 V_141 , T_2 V_33 , int V_166 ,
struct V_189 * V_137 )
{
struct V_68 * V_69 ;
struct V_124 * V_125 ;
unsigned long V_180 ;
unsigned long V_31 ;
unsigned long V_190 ;
T_2 V_120 ;
int V_61 ;
int type ;
V_69 = V_67 -> V_83 [ 0 ] ;
V_125 = F_86 ( V_69 , V_67 -> V_84 [ 0 ] , struct V_124 ) ;
V_190 = ( unsigned long ) V_173 - ( unsigned long ) V_125 ;
type = F_130 ( V_17 , V_141 ) ;
V_61 = F_133 ( type ) ;
F_97 ( V_35 , V_67 , V_61 ) ;
V_125 = F_86 ( V_69 , V_67 -> V_84 [ 0 ] , struct V_124 ) ;
V_120 = F_87 ( V_69 , V_125 ) ;
V_120 += V_166 ;
F_98 ( V_69 , V_125 , V_120 ) ;
if ( V_137 )
F_138 ( V_137 , V_69 , V_125 ) ;
V_180 = ( unsigned long ) V_125 + V_190 ;
V_31 = ( unsigned long ) V_125 + F_85 ( V_69 , V_67 -> V_84 [ 0 ] ) ;
if ( V_180 < V_31 - V_61 )
F_139 ( V_69 , V_180 + V_61 , V_180 ,
V_31 - V_61 - V_180 ) ;
V_173 = (struct V_172 * ) V_180 ;
F_140 ( V_69 , V_173 , type ) ;
if ( type == V_163 ) {
struct V_157 * V_185 ;
V_185 = (struct V_157 * ) ( & V_173 -> V_33 ) ;
F_117 ( V_69 , V_185 , V_153 ) ;
F_118 ( V_69 , V_185 , V_141 ) ;
F_119 ( V_69 , V_185 , V_33 ) ;
F_120 ( V_69 , V_185 , V_166 ) ;
} else if ( type == V_162 ) {
struct V_167 * V_191 ;
V_191 = (struct V_167 * ) ( V_173 + 1 ) ;
F_115 ( V_69 , V_191 , V_166 ) ;
F_141 ( V_69 , V_173 , V_17 ) ;
} else if ( type == V_174 ) {
F_141 ( V_69 , V_173 , V_17 ) ;
} else {
F_141 ( V_69 , V_173 , V_153 ) ;
}
F_103 ( V_69 ) ;
}
static int F_142 ( struct V_117 * V_118 ,
struct V_34 * V_35 ,
struct V_66 * V_67 ,
struct V_172 * * V_178 ,
T_2 V_27 , T_2 V_36 , T_2 V_17 ,
T_2 V_153 , T_2 V_141 , T_2 V_33 )
{
int V_29 ;
V_29 = F_132 ( V_118 , V_35 , V_67 , V_178 ,
V_27 , V_36 , V_17 ,
V_153 , V_141 , V_33 , 0 ) ;
if ( V_29 != - V_161 )
return V_29 ;
F_45 ( V_67 ) ;
* V_178 = NULL ;
if ( V_141 < V_150 ) {
V_29 = F_128 ( V_118 , V_35 , V_67 , V_27 , V_17 ,
V_153 ) ;
} else {
V_29 = F_112 ( V_118 , V_35 , V_67 , V_27 , V_17 ,
V_153 , V_141 , V_33 ) ;
}
return V_29 ;
}
static T_5
void F_143 ( struct V_34 * V_35 ,
struct V_66 * V_67 ,
struct V_172 * V_173 ,
int V_192 ,
struct V_189 * V_137 ,
int * V_169 )
{
struct V_68 * V_69 ;
struct V_124 * V_125 ;
struct V_157 * V_185 = NULL ;
struct V_167 * V_191 = NULL ;
unsigned long V_180 ;
unsigned long V_31 ;
T_3 V_126 ;
int V_61 ;
int type ;
T_2 V_120 ;
V_69 = V_67 -> V_83 [ 0 ] ;
V_125 = F_86 ( V_69 , V_67 -> V_84 [ 0 ] , struct V_124 ) ;
V_120 = F_87 ( V_69 , V_125 ) ;
F_8 ( V_192 < 0 && V_120 + V_192 <= 0 ) ;
V_120 += V_192 ;
F_98 ( V_69 , V_125 , V_120 ) ;
if ( V_137 )
F_138 ( V_137 , V_69 , V_125 ) ;
type = F_127 ( V_69 , V_173 ) ;
if ( type == V_163 ) {
V_185 = (struct V_157 * ) ( & V_173 -> V_33 ) ;
V_120 = F_121 ( V_69 , V_185 ) ;
} else if ( type == V_162 ) {
V_191 = (struct V_167 * ) ( V_173 + 1 ) ;
V_120 = F_116 ( V_69 , V_191 ) ;
} else {
V_120 = 1 ;
F_32 ( V_192 != - 1 ) ;
}
F_32 ( V_192 < 0 && V_120 < - V_192 ) ;
V_120 += V_192 ;
if ( V_120 > 0 ) {
if ( type == V_163 )
F_120 ( V_69 , V_185 , V_120 ) ;
else
F_115 ( V_69 , V_191 , V_120 ) ;
} else {
* V_169 = 1 ;
V_61 = F_133 ( type ) ;
V_126 = F_85 ( V_69 , V_67 -> V_84 [ 0 ] ) ;
V_180 = ( unsigned long ) V_173 ;
V_31 = ( unsigned long ) V_125 + V_126 ;
if ( V_180 + V_61 < V_31 )
F_139 ( V_69 , V_180 , V_180 + V_61 ,
V_31 - V_180 - V_61 ) ;
V_126 -= V_61 ;
F_144 ( V_35 , V_67 , V_126 , 1 ) ;
}
F_103 ( V_69 ) ;
}
static T_5
int F_145 ( struct V_117 * V_118 ,
struct V_34 * V_35 ,
struct V_66 * V_67 ,
T_2 V_27 , T_2 V_36 , T_2 V_17 ,
T_2 V_153 , T_2 V_141 ,
T_2 V_33 , int V_166 ,
struct V_189 * V_137 )
{
struct V_172 * V_173 ;
int V_29 ;
V_29 = F_132 ( V_118 , V_35 , V_67 , & V_173 ,
V_27 , V_36 , V_17 ,
V_153 , V_141 , V_33 , 1 ) ;
if ( V_29 == 0 ) {
F_32 ( V_141 < V_150 ) ;
F_143 ( V_35 , V_67 , V_173 ,
V_166 , V_137 , NULL ) ;
} else if ( V_29 == - V_161 ) {
F_137 ( V_35 , V_67 , V_173 , V_17 ,
V_153 , V_141 , V_33 ,
V_166 , V_137 ) ;
V_29 = 0 ;
}
return V_29 ;
}
static int F_146 ( struct V_117 * V_118 ,
struct V_34 * V_35 ,
struct V_66 * V_67 ,
T_2 V_27 , T_2 V_17 , T_2 V_153 ,
T_2 V_141 , T_2 V_33 , int V_166 )
{
int V_29 ;
if ( V_141 < V_150 ) {
F_32 ( V_166 != 1 ) ;
V_29 = F_129 ( V_118 , V_35 , V_67 , V_27 ,
V_17 , V_153 ) ;
} else {
V_29 = F_113 ( V_118 , V_35 , V_67 , V_27 ,
V_17 , V_153 ,
V_141 , V_33 , V_166 ) ;
}
return V_29 ;
}
static int F_147 ( struct V_117 * V_118 ,
struct V_34 * V_35 ,
struct V_66 * V_67 ,
struct V_172 * V_173 ,
int V_168 , int V_193 , int * V_169 )
{
int V_29 = 0 ;
F_32 ( ! V_193 && V_168 != 1 ) ;
if ( V_173 ) {
F_143 ( V_35 , V_67 , V_173 ,
- V_168 , NULL , V_169 ) ;
} else if ( V_193 ) {
V_29 = F_122 ( V_118 , V_35 , V_67 , V_168 ,
V_169 ) ;
} else {
* V_169 = 1 ;
V_29 = F_124 ( V_118 , V_35 , V_67 ) ;
}
return V_29 ;
}
static int F_148 ( struct V_194 * V_195 , T_2 V_32 , T_2 V_49 ,
T_2 * V_196 )
{
int V_197 , V_29 = 0 ;
T_2 V_198 , V_31 ;
T_2 V_199 = F_149 ( V_32 , 1 << 9 ) ;
if ( F_8 ( V_32 != V_199 ) ) {
V_49 -= V_199 - V_32 ;
V_49 = F_150 ( V_49 , 1 << 9 ) ;
V_32 = V_199 ;
}
* V_196 = 0 ;
if ( ! V_49 )
return 0 ;
V_31 = V_32 + V_49 ;
V_198 = V_49 ;
for ( V_197 = 0 ; V_197 < V_47 ; V_197 ++ ) {
T_2 V_200 = F_22 ( V_197 ) ;
T_2 V_201 = V_200 + V_202 ;
T_2 V_61 = V_200 - V_32 ;
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
if ( V_61 ) {
V_29 = F_152 ( V_195 , V_32 >> 9 , V_61 >> 9 ,
V_40 , 0 ) ;
if ( ! V_29 )
* V_196 += V_61 ;
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
V_40 , 0 ) ;
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
V_29 = F_154 ( V_35 -> V_37 , V_207 ,
V_27 , & V_36 , & V_206 , 0 ) ;
if ( ! V_29 ) {
struct V_208 * V_209 = V_206 -> V_210 ;
int V_43 ;
for ( V_43 = 0 ; V_43 < V_206 -> V_211 ; V_43 ++ , V_209 ++ ) {
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
F_155 ( V_206 ) ;
}
if ( V_204 )
* V_204 = V_196 ;
if ( V_29 == - V_203 )
V_29 = 0 ;
return V_29 ;
}
int F_156 ( struct V_117 * V_118 ,
struct V_34 * V_35 ,
T_2 V_27 , T_2 V_36 , T_2 V_17 ,
T_2 V_153 , T_2 V_141 , T_2 V_33 )
{
int V_29 ;
struct V_12 * V_37 = V_35 -> V_37 ;
F_32 ( V_141 < V_150 &&
V_153 == V_217 ) ;
if ( V_141 < V_150 ) {
V_29 = F_157 ( V_37 , V_118 , V_27 ,
V_36 ,
V_17 , V_153 , ( int ) V_141 ,
V_218 , NULL ) ;
} else {
V_29 = F_158 ( V_37 , V_118 , V_27 ,
V_36 , V_17 , V_153 ,
V_141 , V_33 , 0 ,
V_218 , NULL ) ;
}
return V_29 ;
}
static int F_159 ( struct V_117 * V_118 ,
struct V_34 * V_35 ,
struct V_219 * V_136 ,
T_2 V_17 , T_2 V_153 ,
T_2 V_141 , T_2 V_33 , int V_166 ,
struct V_189 * V_137 )
{
struct V_12 * V_37 = V_35 -> V_37 ;
struct V_66 * V_67 ;
struct V_68 * V_69 ;
struct V_124 * V_97 ;
struct V_70 V_21 ;
T_2 V_27 = V_136 -> V_27 ;
T_2 V_36 = V_136 -> V_36 ;
T_2 V_120 ;
int V_29 ;
V_67 = F_34 () ;
if ( ! V_67 )
return - V_75 ;
V_67 -> V_78 = V_79 ;
V_67 -> V_220 = 1 ;
V_29 = F_145 ( V_118 , V_37 -> V_65 , V_67 ,
V_27 , V_36 , V_17 ,
V_153 , V_141 , V_33 ,
V_166 , V_137 ) ;
if ( ( V_29 < 0 && V_29 != - V_187 ) || ! V_29 )
goto V_82;
V_69 = V_67 -> V_83 [ 0 ] ;
F_41 ( V_69 , & V_21 , V_67 -> V_84 [ 0 ] ) ;
V_97 = F_86 ( V_69 , V_67 -> V_84 [ 0 ] , struct V_124 ) ;
V_120 = F_87 ( V_69 , V_97 ) ;
F_98 ( V_69 , V_97 , V_120 + V_166 ) ;
if ( V_137 )
F_138 ( V_137 , V_69 , V_97 ) ;
F_103 ( V_69 ) ;
F_45 ( V_67 ) ;
V_67 -> V_78 = V_79 ;
V_67 -> V_220 = 1 ;
V_29 = F_146 ( V_118 , V_35 -> V_37 -> V_65 ,
V_67 , V_27 , V_17 , V_153 ,
V_141 , V_33 , V_166 ) ;
if ( V_29 )
F_160 ( V_118 , V_35 , V_29 ) ;
V_82:
F_53 ( V_67 ) ;
return V_29 ;
}
static int F_161 ( struct V_117 * V_118 ,
struct V_34 * V_35 ,
struct V_219 * V_136 ,
struct V_189 * V_137 ,
int V_221 )
{
int V_29 = 0 ;
struct V_222 * V_158 ;
struct V_70 V_223 ;
T_2 V_17 = 0 ;
T_2 V_224 = 0 ;
T_2 V_7 = 0 ;
V_223 . V_22 = V_136 -> V_27 ;
V_223 . V_33 = V_136 -> V_36 ;
V_223 . type = V_80 ;
V_158 = F_162 ( V_136 ) ;
F_163 ( V_136 , V_158 , V_136 -> V_225 ) ;
if ( V_136 -> type == V_162 )
V_17 = V_158 -> V_17 ;
V_224 = V_158 -> V_35 ;
if ( V_136 -> V_225 == V_218 && V_221 ) {
if ( V_137 )
V_7 |= V_137 -> V_139 ;
V_29 = F_164 ( V_118 , V_35 ,
V_17 , V_224 , V_7 ,
V_158 -> V_22 , V_158 -> V_33 ,
& V_223 , V_136 -> V_140 ) ;
} else if ( V_136 -> V_225 == V_218 ) {
V_29 = F_159 ( V_118 , V_35 , V_136 , V_17 ,
V_224 , V_158 -> V_22 ,
V_158 -> V_33 , V_136 -> V_140 ,
V_137 ) ;
} else if ( V_136 -> V_225 == V_226 ) {
V_29 = F_165 ( V_118 , V_35 , V_136 , V_17 ,
V_224 , V_158 -> V_22 ,
V_158 -> V_33 , V_136 -> V_140 ,
V_137 ) ;
} else {
F_91 () ;
}
return V_29 ;
}
static void F_138 ( struct V_189 * V_137 ,
struct V_68 * V_69 ,
struct V_124 * V_125 )
{
T_2 V_7 = F_88 ( V_69 , V_125 ) ;
if ( V_137 -> V_138 ) {
V_7 |= V_137 -> V_139 ;
F_100 ( V_69 , V_125 , V_7 ) ;
}
if ( V_137 -> V_227 ) {
struct V_145 * V_146 ;
F_32 ( ! ( V_7 & V_151 ) ) ;
V_146 = (struct V_145 * ) ( V_125 + 1 ) ;
F_166 ( V_69 , V_146 , & V_137 -> V_21 ) ;
}
}
static int F_167 ( struct V_117 * V_118 ,
struct V_34 * V_35 ,
struct V_219 * V_136 ,
struct V_189 * V_137 )
{
struct V_70 V_21 ;
struct V_66 * V_67 ;
struct V_124 * V_125 ;
struct V_68 * V_69 ;
T_3 V_126 ;
int V_29 ;
int V_160 = 0 ;
int V_119 = ! V_137 -> V_193 ;
if ( V_118 -> V_228 )
return 0 ;
if ( V_119 && ! F_84 ( V_35 -> V_37 , V_129 ) )
V_119 = 0 ;
V_67 = F_34 () ;
if ( ! V_67 )
return - V_75 ;
V_21 . V_22 = V_136 -> V_27 ;
if ( V_119 ) {
V_21 . type = V_88 ;
V_21 . V_33 = V_137 -> V_176 ;
} else {
V_21 . type = V_80 ;
V_21 . V_33 = V_136 -> V_36 ;
}
V_164:
V_67 -> V_78 = V_79 ;
V_67 -> V_220 = 1 ;
V_29 = F_38 ( V_118 , V_35 -> V_37 -> V_65 , & V_21 ,
V_67 , 0 , 1 ) ;
if ( V_29 < 0 ) {
V_160 = V_29 ;
goto V_82;
}
if ( V_29 > 0 ) {
if ( V_119 ) {
if ( V_67 -> V_84 [ 0 ] > 0 ) {
V_67 -> V_84 [ 0 ] -- ;
F_41 ( V_67 -> V_83 [ 0 ] , & V_21 ,
V_67 -> V_84 [ 0 ] ) ;
if ( V_21 . V_22 == V_136 -> V_27 &&
V_21 . type == V_80 &&
V_21 . V_33 == V_136 -> V_36 )
V_29 = 0 ;
}
if ( V_29 > 0 ) {
F_45 ( V_67 ) ;
V_119 = 0 ;
V_21 . V_22 = V_136 -> V_27 ;
V_21 . V_33 = V_136 -> V_36 ;
V_21 . type = V_80 ;
goto V_164;
}
} else {
V_160 = - V_184 ;
goto V_82;
}
}
V_69 = V_67 -> V_83 [ 0 ] ;
V_126 = F_85 ( V_69 , V_67 -> V_84 [ 0 ] ) ;
#ifdef F_89
if ( V_126 < sizeof( * V_125 ) ) {
V_29 = F_95 ( V_118 , V_35 -> V_37 -> V_65 ,
V_67 , ( T_2 ) - 1 , 0 ) ;
if ( V_29 < 0 ) {
V_160 = V_29 ;
goto V_82;
}
V_69 = V_67 -> V_83 [ 0 ] ;
V_126 = F_85 ( V_69 , V_67 -> V_84 [ 0 ] ) ;
}
#endif
F_32 ( V_126 < sizeof( * V_125 ) ) ;
V_125 = F_86 ( V_69 , V_67 -> V_84 [ 0 ] , struct V_124 ) ;
F_138 ( V_137 , V_69 , V_125 ) ;
F_103 ( V_69 ) ;
V_82:
F_53 ( V_67 ) ;
return V_160 ;
}
static int F_168 ( struct V_117 * V_118 ,
struct V_34 * V_35 ,
struct V_219 * V_136 ,
struct V_189 * V_137 ,
int V_221 )
{
int V_29 = 0 ;
struct V_229 * V_158 ;
struct V_70 V_223 ;
T_2 V_17 = 0 ;
T_2 V_224 = 0 ;
bool V_182 = F_84 ( V_35 -> V_37 ,
V_129 ) ;
V_158 = F_169 ( V_136 ) ;
F_170 ( V_136 , V_158 , V_136 -> V_225 ) ;
if ( V_136 -> type == V_174 )
V_17 = V_158 -> V_17 ;
V_224 = V_158 -> V_35 ;
V_223 . V_22 = V_136 -> V_27 ;
if ( V_182 ) {
V_223 . V_33 = V_158 -> V_176 ;
V_223 . type = V_88 ;
} else {
V_223 . V_33 = V_136 -> V_36 ;
V_223 . type = V_80 ;
}
F_32 ( V_136 -> V_140 != 1 ) ;
if ( V_136 -> V_225 == V_218 && V_221 ) {
F_32 ( ! V_137 || ! V_137 -> V_138 ) ;
V_29 = F_171 ( V_118 , V_35 ,
V_17 , V_224 ,
V_137 -> V_139 ,
& V_137 -> V_21 ,
V_158 -> V_176 , & V_223 ) ;
} else if ( V_136 -> V_225 == V_218 ) {
V_29 = F_159 ( V_118 , V_35 , V_136 ,
V_17 , V_224 ,
V_158 -> V_176 , 0 , 1 ,
V_137 ) ;
} else if ( V_136 -> V_225 == V_226 ) {
V_29 = F_165 ( V_118 , V_35 , V_136 ,
V_17 , V_224 ,
V_158 -> V_176 , 0 , 1 , V_137 ) ;
} else {
F_91 () ;
}
return V_29 ;
}
static int F_172 ( struct V_117 * V_118 ,
struct V_34 * V_35 ,
struct V_219 * V_136 ,
struct V_189 * V_137 ,
int V_221 )
{
int V_29 = 0 ;
if ( V_118 -> V_228 ) {
if ( V_221 )
F_173 ( V_35 , V_136 -> V_27 ,
V_136 -> V_36 , 1 ) ;
return 0 ;
}
if ( F_174 ( V_136 ) ) {
struct V_121 * V_113 ;
F_32 ( V_137 ) ;
V_113 = F_175 ( V_136 ) ;
F_176 ( V_136 , V_113 , V_136 -> V_225 ) ;
if ( V_221 ) {
F_173 ( V_35 , V_136 -> V_27 ,
V_136 -> V_36 , 1 ) ;
if ( V_113 -> V_193 ) {
V_29 = F_177 ( V_118 , V_35 ,
V_136 -> V_27 ,
V_136 -> V_36 ) ;
}
}
F_178 ( V_35 -> V_37 ,
V_113 -> V_230 ,
V_113 -> V_231 ) ;
return V_29 ;
}
if ( V_136 -> type == V_175 ||
V_136 -> type == V_174 )
V_29 = F_168 ( V_118 , V_35 , V_136 , V_137 ,
V_221 ) ;
else if ( V_136 -> type == V_163 ||
V_136 -> type == V_162 )
V_29 = F_161 ( V_118 , V_35 , V_136 , V_137 ,
V_221 ) ;
else
F_91 () ;
return V_29 ;
}
static inline struct V_219 *
F_179 ( struct V_121 * V_113 )
{
struct V_219 * V_158 ;
if ( F_180 ( & V_113 -> V_232 ) )
return NULL ;
F_181 (ref, &head->ref_list, list) {
if ( V_158 -> V_225 == V_218 )
return V_158 ;
}
return F_182 ( V_113 -> V_232 . V_81 , struct V_219 ,
V_99 ) ;
}
static T_1 int F_183 ( struct V_117 * V_118 ,
struct V_34 * V_35 ,
unsigned long V_44 )
{
struct V_122 * V_123 ;
struct V_219 * V_158 ;
struct V_121 * V_233 = NULL ;
struct V_189 * V_137 ;
struct V_12 * V_37 = V_35 -> V_37 ;
T_6 V_32 = F_184 () ;
int V_29 ;
unsigned long V_8 = 0 ;
unsigned long V_234 = 0 ;
int V_235 = 0 ;
V_123 = & V_118 -> V_135 -> V_123 ;
while ( 1 ) {
if ( ! V_233 ) {
if ( V_8 >= V_44 )
break;
F_11 ( & V_123 -> V_52 ) ;
V_233 = F_185 ( V_118 ) ;
if ( ! V_233 ) {
F_13 ( & V_123 -> V_52 ) ;
break;
}
V_29 = F_186 ( V_118 , V_233 ) ;
F_13 ( & V_123 -> V_52 ) ;
if ( V_29 == - V_187 ) {
V_233 = NULL ;
V_8 ++ ;
continue;
}
}
F_11 ( & V_233 -> V_52 ) ;
F_187 ( V_118 , V_37 , V_123 ,
V_233 ) ;
V_158 = F_179 ( V_233 ) ;
if ( V_158 && V_158 -> V_236 &&
F_188 ( V_37 , V_123 , V_158 -> V_236 ) ) {
F_13 ( & V_233 -> V_52 ) ;
F_189 ( V_233 ) ;
F_11 ( & V_123 -> V_52 ) ;
V_233 -> V_237 = 0 ;
V_123 -> V_238 ++ ;
F_13 ( & V_123 -> V_52 ) ;
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
F_190 ( V_137 ) ;
V_137 = NULL ;
}
if ( V_137 ) {
F_13 ( & V_233 -> V_52 ) ;
V_29 = F_167 ( V_118 , V_35 ,
V_158 , V_137 ) ;
F_190 ( V_137 ) ;
if ( V_29 ) {
if ( V_235 )
V_233 -> V_235 = 1 ;
V_233 -> V_237 = 0 ;
F_191 ( V_37 , L_1 , V_29 ) ;
F_189 ( V_233 ) ;
return V_29 ;
}
continue;
}
F_13 ( & V_233 -> V_52 ) ;
F_11 ( & V_123 -> V_52 ) ;
F_11 ( & V_233 -> V_52 ) ;
if ( ! F_180 ( & V_233 -> V_232 ) ||
V_233 -> V_137 ) {
F_13 ( & V_233 -> V_52 ) ;
F_13 ( & V_123 -> V_52 ) ;
continue;
}
V_158 -> V_239 = 0 ;
V_123 -> V_240 -- ;
F_192 ( & V_233 -> V_241 ,
& V_123 -> V_242 ) ;
F_13 ( & V_123 -> V_52 ) ;
} else {
V_234 ++ ;
V_158 -> V_239 = 0 ;
F_193 ( & V_158 -> V_99 ) ;
}
F_194 ( & V_123 -> V_243 ) ;
if ( ! F_174 ( V_158 ) ) {
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
F_13 ( & V_233 -> V_52 ) ;
V_29 = F_172 ( V_118 , V_35 , V_158 , V_137 ,
V_235 ) ;
F_190 ( V_137 ) ;
if ( V_29 ) {
V_233 -> V_237 = 0 ;
F_189 ( V_233 ) ;
F_94 ( V_158 ) ;
F_191 ( V_37 , L_2 , V_29 ) ;
return V_29 ;
}
if ( F_174 ( V_158 ) ) {
if ( V_233 -> V_193 &&
V_233 -> V_245 < 0 ) {
F_11 ( & V_123 -> V_52 ) ;
V_123 -> V_246 -= V_158 -> V_36 ;
F_13 ( & V_123 -> V_52 ) ;
}
F_189 ( V_233 ) ;
V_233 = NULL ;
}
F_94 ( V_158 ) ;
V_8 ++ ;
F_48 () ;
}
if ( V_234 > 0 ) {
T_2 V_247 = F_195 ( F_196 ( F_184 () , V_32 ) ) ;
T_2 V_248 ;
F_11 ( & V_123 -> V_52 ) ;
V_248 = V_37 -> V_249 * 3 + V_247 ;
V_37 -> V_249 = V_248 >> 2 ;
F_13 ( & V_123 -> V_52 ) ;
}
return 0 ;
}
static T_2 F_197 ( struct V_250 * V_35 )
{
struct V_15 * V_30 = V_35 -> V_15 ;
struct V_219 * V_251 ;
int V_252 = 1 ;
T_2 V_253 ;
T_2 V_254 = 0 , V_72 = 0 ;
V_30 = F_198 ( V_35 ) ;
if ( V_30 ) {
V_251 = F_12 ( V_30 , struct V_219 , V_15 ) ;
V_254 = V_251 -> V_27 ;
}
V_30 = F_199 ( V_35 ) ;
if ( V_30 ) {
V_251 = F_12 ( V_30 , struct V_219 , V_15 ) ;
V_72 = V_251 -> V_27 ;
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
static inline T_2 F_200 ( struct V_34 * V_35 , T_2 V_255 )
{
T_2 V_36 ;
V_36 = V_255 * ( sizeof( struct V_124 ) +
sizeof( struct V_172 ) ) ;
if ( ! F_84 ( V_35 -> V_37 , V_129 ) )
V_36 += V_255 * sizeof( struct V_145 ) ;
return F_201 ( V_36 , F_202 ( V_35 ) ) ;
}
T_2 F_203 ( struct V_34 * V_35 , T_2 V_256 )
{
T_2 V_257 ;
T_2 V_258 ;
T_2 V_259 ;
V_257 = F_202 ( V_35 ) - sizeof( struct V_260 ) ;
V_258 = F_204 ( V_257 ,
( T_2 ) F_205 ( V_35 -> V_37 -> V_261 ) ) ;
V_259 = F_204 ( V_256 , V_35 -> V_57 ) ;
V_259 += V_258 - 1 ;
V_259 = F_204 ( V_259 , V_258 ) ;
return V_259 ;
}
int F_206 ( struct V_117 * V_118 ,
struct V_34 * V_35 )
{
struct V_262 * V_263 ;
T_2 V_240 = V_118 -> V_135 -> V_123 . V_238 ;
T_2 V_256 = V_118 -> V_135 -> V_123 . V_246 ;
T_2 V_264 = V_118 -> V_135 -> V_264 ;
T_2 V_36 , V_265 ;
int V_29 = 0 ;
V_36 = F_207 ( V_35 , 1 ) ;
V_240 = F_200 ( V_35 , V_240 ) ;
if ( V_240 > 1 )
V_36 += ( V_240 - 1 ) * V_35 -> V_56 ;
V_36 <<= 1 ;
V_36 += F_203 ( V_35 , V_256 ) * V_35 -> V_56 ;
V_265 = F_207 ( V_35 ,
V_264 ) ;
V_263 = & V_35 -> V_37 -> V_266 ;
if ( V_263 -> V_96 -> V_116 ) {
V_265 <<= 1 ;
V_36 <<= 1 ;
}
F_11 ( & V_263 -> V_52 ) ;
if ( V_263 -> V_10 <= V_36 + V_265 )
V_29 = 1 ;
F_13 ( & V_263 -> V_52 ) ;
return V_29 ;
}
int F_208 ( struct V_117 * V_118 ,
struct V_34 * V_35 )
{
struct V_12 * V_37 = V_35 -> V_37 ;
T_2 V_243 =
F_209 ( & V_118 -> V_135 -> V_123 . V_243 ) ;
T_2 V_267 ;
T_2 V_268 ;
F_2 () ;
V_267 = V_37 -> V_249 ;
V_268 = V_243 * V_267 ;
if ( V_243 * V_267 >= V_269 )
return 1 ;
if ( V_268 >= V_269 / 2 )
return 2 ;
return F_206 ( V_118 , V_35 ) ;
}
static void F_210 ( struct V_92 * V_93 )
{
struct V_270 * V_271 ;
struct V_117 * V_118 ;
int V_29 ;
V_271 = F_55 ( V_93 , struct V_270 , V_93 ) ;
V_118 = F_211 ( V_271 -> V_35 ) ;
if ( F_212 ( V_118 ) ) {
V_271 -> error = F_213 ( V_118 ) ;
goto V_272;
}
V_118 -> V_273 = true ;
V_29 = F_214 ( V_118 , V_271 -> V_35 , V_271 -> V_8 ) ;
if ( V_29 )
V_271 -> error = V_29 ;
V_29 = F_215 ( V_118 , V_271 -> V_35 ) ;
if ( V_29 && ! V_271 -> error )
V_271 -> error = V_29 ;
V_272:
if ( V_271 -> V_273 )
F_216 ( & V_271 -> V_91 ) ;
else
F_9 ( V_271 ) ;
}
int F_217 ( struct V_34 * V_35 ,
unsigned long V_8 , int V_91 )
{
struct V_270 * V_271 ;
int V_29 ;
V_271 = F_218 ( sizeof( * V_271 ) , V_40 ) ;
if ( ! V_271 )
return - V_75 ;
V_271 -> V_35 = V_35 -> V_37 -> V_89 ;
V_271 -> V_8 = V_8 ;
V_271 -> error = 0 ;
if ( V_91 )
V_271 -> V_273 = 1 ;
else
V_271 -> V_273 = 0 ;
F_219 ( & V_271 -> V_91 ) ;
F_66 ( & V_271 -> V_93 , V_274 ,
F_210 , NULL , NULL ) ;
F_74 ( V_35 -> V_37 -> V_275 , & V_271 -> V_93 ) ;
if ( V_91 ) {
F_220 ( & V_271 -> V_91 ) ;
V_29 = V_271 -> error ;
F_9 ( V_271 ) ;
return V_29 ;
}
return 0 ;
}
int F_214 ( struct V_117 * V_118 ,
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
if ( V_35 == V_35 -> V_37 -> V_65 )
V_35 = V_35 -> V_37 -> V_89 ;
V_123 = & V_118 -> V_135 -> V_123 ;
if ( V_8 == 0 )
V_8 = F_209 ( & V_123 -> V_243 ) * 2 ;
V_164:
#ifdef F_221
V_123 -> V_279 = F_197 ( & V_123 -> V_35 ) ;
#endif
V_118 -> V_277 = false ;
V_29 = F_183 ( V_118 , V_35 , V_8 ) ;
if ( V_29 < 0 ) {
F_160 ( V_118 , V_35 , V_29 ) ;
return V_29 ;
}
if ( V_276 ) {
if ( ! F_180 ( & V_118 -> V_280 ) )
F_222 ( V_118 , V_35 ) ;
F_11 ( & V_123 -> V_52 ) ;
V_136 = F_198 ( & V_123 -> V_242 ) ;
if ( ! V_136 ) {
F_13 ( & V_123 -> V_52 ) ;
goto V_82;
}
V_8 = ( unsigned long ) - 1 ;
while ( V_136 ) {
V_113 = F_12 ( V_136 , struct V_121 ,
V_241 ) ;
if ( F_174 ( & V_113 -> V_136 ) ) {
struct V_219 * V_158 ;
V_158 = & V_113 -> V_136 ;
F_5 ( & V_158 -> V_120 ) ;
F_13 ( & V_123 -> V_52 ) ;
F_49 ( & V_113 -> V_87 ) ;
F_47 ( & V_113 -> V_87 ) ;
F_94 ( V_158 ) ;
F_48 () ;
goto V_164;
} else {
F_8 ( 1 ) ;
}
V_136 = F_223 ( V_136 ) ;
}
F_13 ( & V_123 -> V_52 ) ;
F_48 () ;
goto V_164;
}
V_82:
F_224 ( V_118 ) ;
V_118 -> V_277 = V_277 ;
return 0 ;
}
int F_225 ( struct V_117 * V_118 ,
struct V_34 * V_35 ,
T_2 V_27 , T_2 V_36 , T_2 V_7 ,
int V_176 , int V_193 )
{
struct V_189 * V_137 ;
int V_29 ;
V_137 = F_226 () ;
if ( ! V_137 )
return - V_75 ;
V_137 -> V_139 = V_7 ;
V_137 -> V_138 = true ;
V_137 -> V_227 = false ;
V_137 -> V_193 = V_193 ? true : false ;
V_137 -> V_176 = V_176 ;
V_29 = F_227 ( V_35 -> V_37 , V_118 , V_27 ,
V_36 , V_137 ) ;
if ( V_29 )
F_190 ( V_137 ) ;
return V_29 ;
}
static T_1 int F_228 ( struct V_117 * V_118 ,
struct V_34 * V_35 ,
struct V_66 * V_67 ,
T_2 V_22 , T_2 V_33 , T_2 V_27 )
{
struct V_121 * V_113 ;
struct V_219 * V_158 ;
struct V_222 * V_281 ;
struct V_122 * V_123 ;
int V_29 = 0 ;
V_123 = & V_118 -> V_135 -> V_123 ;
F_11 ( & V_123 -> V_52 ) ;
V_113 = F_92 ( V_118 , V_27 ) ;
if ( ! V_113 ) {
F_13 ( & V_123 -> V_52 ) ;
return 0 ;
}
if ( ! F_93 ( & V_113 -> V_87 ) ) {
F_5 ( & V_113 -> V_136 . V_120 ) ;
F_13 ( & V_123 -> V_52 ) ;
F_45 ( V_67 ) ;
F_49 ( & V_113 -> V_87 ) ;
F_47 ( & V_113 -> V_87 ) ;
F_94 ( & V_113 -> V_136 ) ;
return - V_187 ;
}
F_13 ( & V_123 -> V_52 ) ;
F_11 ( & V_113 -> V_52 ) ;
F_181 (ref, &head->ref_list, list) {
if ( V_158 -> type != V_163 ) {
V_29 = 1 ;
break;
}
V_281 = F_162 ( V_158 ) ;
if ( V_281 -> V_35 != V_35 -> V_282 . V_22 ||
V_281 -> V_22 != V_22 ||
V_281 -> V_33 != V_33 ) {
V_29 = 1 ;
break;
}
}
F_13 ( & V_113 -> V_52 ) ;
F_47 ( & V_113 -> V_87 ) ;
return V_29 ;
}
static T_1 int F_229 ( struct V_117 * V_118 ,
struct V_34 * V_35 ,
struct V_66 * V_67 ,
T_2 V_22 , T_2 V_33 , T_2 V_27 )
{
struct V_34 * V_65 = V_35 -> V_37 -> V_65 ;
struct V_68 * V_69 ;
struct V_157 * V_158 ;
struct V_172 * V_173 ;
struct V_124 * V_125 ;
struct V_70 V_21 ;
T_3 V_126 ;
int V_29 ;
V_21 . V_22 = V_27 ;
V_21 . V_33 = ( T_2 ) - 1 ;
V_21 . type = V_80 ;
V_29 = F_38 ( NULL , V_65 , & V_21 , V_67 , 0 , 0 ) ;
if ( V_29 < 0 )
goto V_82;
F_32 ( V_29 == 0 ) ;
V_29 = - V_161 ;
if ( V_67 -> V_84 [ 0 ] == 0 )
goto V_82;
V_67 -> V_84 [ 0 ] -- ;
V_69 = V_67 -> V_83 [ 0 ] ;
F_41 ( V_69 , & V_21 , V_67 -> V_84 [ 0 ] ) ;
if ( V_21 . V_22 != V_27 || V_21 . type != V_80 )
goto V_82;
V_29 = 1 ;
V_126 = F_85 ( V_69 , V_67 -> V_84 [ 0 ] ) ;
#ifdef F_89
if ( V_126 < sizeof( * V_125 ) ) {
F_8 ( V_126 != sizeof( struct V_132 ) ) ;
goto V_82;
}
#endif
V_125 = F_86 ( V_69 , V_67 -> V_84 [ 0 ] , struct V_124 ) ;
if ( V_126 != sizeof( * V_125 ) +
F_133 ( V_163 ) )
goto V_82;
if ( F_230 ( V_69 , V_125 ) <=
F_231 ( & V_35 -> V_283 ) )
goto V_82;
V_173 = (struct V_172 * ) ( V_125 + 1 ) ;
if ( F_127 ( V_69 , V_173 ) !=
V_163 )
goto V_82;
V_158 = (struct V_157 * ) ( & V_173 -> V_33 ) ;
if ( F_87 ( V_69 , V_125 ) !=
F_121 ( V_69 , V_158 ) ||
F_108 ( V_69 , V_158 ) !=
V_35 -> V_282 . V_22 ||
F_109 ( V_69 , V_158 ) != V_22 ||
F_110 ( V_69 , V_158 ) != V_33 )
goto V_82;
V_29 = 0 ;
V_82:
return V_29 ;
}
int F_232 ( struct V_117 * V_118 ,
struct V_34 * V_35 ,
T_2 V_22 , T_2 V_33 , T_2 V_27 )
{
struct V_66 * V_67 ;
int V_29 ;
int V_284 ;
V_67 = F_34 () ;
if ( ! V_67 )
return - V_161 ;
do {
V_29 = F_229 ( V_118 , V_35 , V_67 , V_22 ,
V_33 , V_27 ) ;
if ( V_29 && V_29 != - V_161 )
goto V_82;
V_284 = F_228 ( V_118 , V_35 , V_67 , V_22 ,
V_33 , V_27 ) ;
} while ( V_284 == - V_187 );
if ( V_284 && V_284 != - V_161 ) {
V_29 = V_284 ;
goto V_82;
}
if ( V_29 != - V_161 || V_284 != - V_161 )
V_29 = 0 ;
V_82:
F_53 ( V_67 ) ;
if ( V_35 -> V_282 . V_22 == V_285 )
F_8 ( V_29 > 0 ) ;
return V_29 ;
}
static int F_233 ( struct V_117 * V_118 ,
struct V_34 * V_35 ,
struct V_68 * V_286 ,
int V_287 , int V_288 )
{
T_2 V_27 ;
T_2 V_36 ;
T_2 V_17 ;
T_2 V_224 ;
T_3 V_73 ;
struct V_70 V_21 ;
struct V_289 * V_290 ;
int V_43 ;
int V_176 ;
int V_29 = 0 ;
int (* F_234)( struct V_117 * , struct V_34 * ,
T_2 , T_2 , T_2 , T_2 , T_2 , T_2 );
if ( F_235 ( V_35 ) )
return 0 ;
V_224 = F_236 ( V_286 ) ;
V_73 = F_39 ( V_286 ) ;
V_176 = F_237 ( V_286 ) ;
if ( ! F_238 ( V_291 , & V_35 -> V_292 ) && V_176 == 0 )
return 0 ;
if ( V_288 )
F_234 = F_156 ;
else
F_234 = V_293 ;
if ( V_287 )
V_17 = V_286 -> V_32 ;
else
V_17 = 0 ;
for ( V_43 = 0 ; V_43 < V_73 ; V_43 ++ ) {
if ( V_176 == 0 ) {
F_41 ( V_286 , & V_21 , V_43 ) ;
if ( V_21 . type != V_294 )
continue;
V_290 = F_86 ( V_286 , V_43 ,
struct V_289 ) ;
if ( F_239 ( V_286 , V_290 ) ==
V_295 )
continue;
V_27 = F_240 ( V_286 , V_290 ) ;
if ( V_27 == 0 )
continue;
V_36 = F_241 ( V_286 , V_290 ) ;
V_21 . V_33 -= F_242 ( V_286 , V_290 ) ;
V_29 = F_234 ( V_118 , V_35 , V_27 , V_36 ,
V_17 , V_224 , V_21 . V_22 ,
V_21 . V_33 ) ;
if ( V_29 )
goto V_165;
} else {
V_27 = F_243 ( V_286 , V_43 ) ;
V_36 = V_35 -> V_56 ;
V_29 = F_234 ( V_118 , V_35 , V_27 , V_36 ,
V_17 , V_224 , V_176 - 1 , 0 ) ;
if ( V_29 )
goto V_165;
}
}
return 0 ;
V_165:
return V_29 ;
}
int F_244 ( struct V_117 * V_118 , struct V_34 * V_35 ,
struct V_68 * V_286 , int V_287 )
{
return F_233 ( V_118 , V_35 , V_286 , V_287 , 1 ) ;
}
int F_245 ( struct V_117 * V_118 , struct V_34 * V_35 ,
struct V_68 * V_286 , int V_287 )
{
return F_233 ( V_118 , V_35 , V_286 , V_287 , 0 ) ;
}
static int F_246 ( struct V_117 * V_118 ,
struct V_34 * V_35 ,
struct V_66 * V_67 ,
struct V_1 * V_2 )
{
int V_29 ;
struct V_34 * V_65 = V_35 -> V_37 -> V_65 ;
unsigned long V_146 ;
struct V_68 * V_69 ;
V_29 = F_38 ( V_118 , V_65 , & V_2 -> V_21 , V_67 , 0 , 1 ) ;
if ( V_29 ) {
if ( V_29 > 0 )
V_29 = - V_161 ;
goto V_165;
}
V_69 = V_67 -> V_83 [ 0 ] ;
V_146 = F_247 ( V_69 , V_67 -> V_84 [ 0 ] ) ;
F_248 ( V_69 , & V_2 -> V_97 , V_146 , sizeof( V_2 -> V_97 ) ) ;
F_103 ( V_69 ) ;
V_165:
F_45 ( V_67 ) ;
return V_29 ;
}
static struct V_1 *
F_249 ( struct V_34 * V_35 ,
struct V_1 * V_2 )
{
struct V_15 * V_136 ;
F_11 ( & V_35 -> V_37 -> V_18 ) ;
if ( F_250 ( & V_2 -> V_20 ) ) {
const T_2 V_296 = V_2 -> V_21 . V_22 + V_2 -> V_21 . V_33 ;
F_13 ( & V_35 -> V_37 -> V_18 ) ;
F_6 ( V_2 ) ;
V_2 = F_75 ( V_35 -> V_37 ,
V_296 ) ;
return V_2 ;
}
V_136 = F_223 ( & V_2 -> V_20 ) ;
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
static int F_251 ( struct V_1 * V_14 ,
struct V_117 * V_118 ,
struct V_66 * V_67 )
{
struct V_34 * V_35 = V_14 -> V_37 -> V_89 ;
struct V_297 * V_297 = NULL ;
T_2 V_298 = 0 ;
int V_299 = V_300 ;
T_2 V_301 = 0 ;
int V_302 = 0 ;
int V_29 = 0 ;
if ( V_14 -> V_21 . V_33 < ( 100 * V_303 ) ) {
F_11 ( & V_14 -> V_52 ) ;
V_14 -> V_304 = V_305 ;
F_13 ( & V_14 -> V_52 ) ;
return 0 ;
}
if ( V_118 -> V_228 )
return 0 ;
V_164:
V_297 = F_252 ( V_35 , V_14 , V_67 ) ;
if ( F_212 ( V_297 ) && F_213 ( V_297 ) != - V_161 ) {
V_29 = F_213 ( V_297 ) ;
F_45 ( V_67 ) ;
goto V_82;
}
if ( F_212 ( V_297 ) ) {
F_32 ( V_302 ) ;
V_302 ++ ;
if ( V_14 -> V_306 )
goto V_131;
V_29 = F_253 ( V_35 , V_118 , V_14 , V_67 ) ;
if ( V_29 )
goto V_131;
goto V_164;
}
if ( V_14 -> V_307 == V_118 -> V_308 &&
F_254 ( V_297 ) ) {
V_299 = V_309 ;
goto V_310;
}
F_255 ( V_297 ) -> V_311 = 0 ;
V_29 = F_256 ( V_118 , V_35 , V_297 ) ;
if ( V_29 ) {
F_160 ( V_118 , V_35 , V_29 ) ;
goto V_310;
}
F_8 ( V_29 ) ;
if ( F_254 ( V_297 ) > 0 ) {
V_29 = F_257 ( V_35 ,
& V_35 -> V_37 -> V_266 ) ;
if ( V_29 )
goto V_310;
V_29 = F_258 ( V_35 , V_118 , NULL , V_297 ) ;
if ( V_29 )
goto V_310;
}
F_11 ( & V_14 -> V_52 ) ;
if ( V_14 -> V_3 != V_4 ||
! F_259 ( V_35 , V_312 ) ) {
V_299 = V_305 ;
F_13 ( & V_14 -> V_52 ) ;
goto V_310;
}
F_13 ( & V_14 -> V_52 ) ;
if ( F_238 ( V_313 , & V_118 -> V_135 -> V_7 ) ) {
V_29 = - V_314 ;
goto V_310;
}
V_301 = F_201 ( V_14 -> V_21 . V_33 , V_315 ) ;
if ( ! V_301 )
V_301 = 1 ;
V_301 *= 16 ;
V_301 *= V_316 ;
V_29 = F_260 ( V_297 , 0 , V_301 ) ;
if ( V_29 )
goto V_310;
V_29 = F_261 ( V_297 , V_118 , 0 , 0 , V_301 ,
V_301 , V_301 ,
& V_298 ) ;
if ( ! V_29 )
V_299 = V_309 ;
else if ( V_29 == - V_314 )
F_262 ( V_313 , & V_118 -> V_135 -> V_7 ) ;
F_263 ( V_297 , 0 , V_301 ) ;
V_310:
F_264 ( V_297 ) ;
V_131:
F_45 ( V_67 ) ;
V_82:
F_11 ( & V_14 -> V_52 ) ;
if ( ! V_29 && V_299 == V_309 )
V_14 -> V_307 = V_118 -> V_308 ;
V_14 -> V_304 = V_299 ;
F_13 ( & V_14 -> V_52 ) ;
return V_29 ;
}
int F_265 ( struct V_117 * V_118 ,
struct V_34 * V_35 )
{
struct V_1 * V_2 , * V_317 ;
struct V_318 * V_319 = V_118 -> V_135 ;
struct V_66 * V_67 ;
if ( F_180 ( & V_319 -> V_320 ) ||
! F_259 ( V_35 , V_312 ) )
return 0 ;
V_67 = F_34 () ;
if ( ! V_67 )
return - V_75 ;
F_266 (cache, tmp, &cur_trans->dirty_bgs,
dirty_list) {
if ( V_2 -> V_304 == V_321 )
F_251 ( V_2 , V_118 , V_67 ) ;
}
F_53 ( V_67 ) ;
return 0 ;
}
int F_267 ( struct V_117 * V_118 ,
struct V_34 * V_35 )
{
struct V_1 * V_2 ;
struct V_318 * V_319 = V_118 -> V_135 ;
int V_29 = 0 ;
int V_322 ;
struct V_66 * V_67 = NULL ;
F_268 ( V_323 ) ;
struct V_112 * V_324 = & V_319 -> V_325 ;
int V_326 = 0 ;
int V_327 = 0 ;
F_11 ( & V_319 -> V_328 ) ;
if ( F_180 ( & V_319 -> V_320 ) ) {
F_13 ( & V_319 -> V_328 ) ;
return 0 ;
}
F_269 ( & V_319 -> V_320 , & V_323 ) ;
F_13 ( & V_319 -> V_328 ) ;
V_164:
F_222 ( V_118 , V_35 ) ;
if ( ! V_67 ) {
V_67 = F_34 () ;
if ( ! V_67 )
return - V_75 ;
}
F_49 ( & V_118 -> V_135 -> V_329 ) ;
while ( ! F_180 ( & V_323 ) ) {
V_2 = F_270 ( & V_323 ,
struct V_1 ,
V_330 ) ;
if ( ! F_180 ( & V_2 -> V_331 ) ) {
F_271 ( & V_2 -> V_331 ) ;
F_272 ( V_35 , V_118 , V_2 ,
& V_2 -> V_332 , V_67 ,
V_2 -> V_21 . V_22 ) ;
F_6 ( V_2 ) ;
}
F_11 ( & V_319 -> V_328 ) ;
F_271 ( & V_2 -> V_330 ) ;
F_13 ( & V_319 -> V_328 ) ;
V_322 = 1 ;
F_251 ( V_2 , V_118 , V_67 ) ;
if ( V_2 -> V_304 == V_309 ) {
V_2 -> V_332 . V_297 = NULL ;
V_29 = F_273 ( V_35 , V_118 , V_2 , V_67 ) ;
if ( V_29 == 0 && V_2 -> V_332 . V_297 ) {
V_326 ++ ;
V_322 = 0 ;
F_72 ( & V_2 -> V_331 , V_324 ) ;
} else {
V_29 = 0 ;
}
}
if ( ! V_29 ) {
V_29 = F_246 ( V_118 , V_35 , V_67 , V_2 ) ;
if ( V_29 == - V_161 ) {
V_29 = 0 ;
F_11 ( & V_319 -> V_328 ) ;
if ( F_180 ( & V_2 -> V_330 ) ) {
F_72 ( & V_2 -> V_330 ,
& V_319 -> V_320 ) ;
F_4 ( V_2 ) ;
}
F_13 ( & V_319 -> V_328 ) ;
} else if ( V_29 ) {
F_160 ( V_118 , V_35 , V_29 ) ;
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
V_29 = F_214 ( V_118 , V_35 , 0 ) ;
if ( ! V_29 && V_327 == 0 ) {
V_327 ++ ;
F_11 ( & V_319 -> V_328 ) ;
F_269 ( & V_319 -> V_320 , & V_323 ) ;
if ( ! F_180 ( & V_323 ) ) {
F_13 ( & V_319 -> V_328 ) ;
goto V_164;
}
F_13 ( & V_319 -> V_328 ) ;
}
F_53 ( V_67 ) ;
return V_29 ;
}
int F_274 ( struct V_117 * V_118 ,
struct V_34 * V_35 )
{
struct V_1 * V_2 ;
struct V_318 * V_319 = V_118 -> V_135 ;
int V_29 = 0 ;
int V_322 ;
struct V_66 * V_67 ;
struct V_112 * V_324 = & V_319 -> V_325 ;
int V_326 = 0 ;
V_67 = F_34 () ;
if ( ! V_67 )
return - V_75 ;
F_11 ( & V_319 -> V_328 ) ;
while ( ! F_180 ( & V_319 -> V_320 ) ) {
V_2 = F_270 ( & V_319 -> V_320 ,
struct V_1 ,
V_330 ) ;
if ( ! F_180 ( & V_2 -> V_331 ) ) {
F_13 ( & V_319 -> V_328 ) ;
F_271 ( & V_2 -> V_331 ) ;
F_272 ( V_35 , V_118 , V_2 ,
& V_2 -> V_332 , V_67 ,
V_2 -> V_21 . V_22 ) ;
F_6 ( V_2 ) ;
F_11 ( & V_319 -> V_328 ) ;
}
F_271 ( & V_2 -> V_330 ) ;
F_13 ( & V_319 -> V_328 ) ;
V_322 = 1 ;
F_251 ( V_2 , V_118 , V_67 ) ;
if ( ! V_29 )
V_29 = F_214 ( V_118 , V_35 , ( unsigned long ) - 1 ) ;
if ( ! V_29 && V_2 -> V_304 == V_309 ) {
V_2 -> V_332 . V_297 = NULL ;
V_29 = F_273 ( V_35 , V_118 , V_2 , V_67 ) ;
if ( V_29 == 0 && V_2 -> V_332 . V_297 ) {
V_326 ++ ;
V_322 = 0 ;
F_72 ( & V_2 -> V_331 , V_324 ) ;
} else {
V_29 = 0 ;
}
}
if ( ! V_29 ) {
V_29 = F_246 ( V_118 , V_35 , V_67 , V_2 ) ;
if ( V_29 == - V_161 ) {
F_275 ( V_319 -> V_333 ,
F_209 ( & V_319 -> V_334 ) == 1 ) ;
V_29 = F_246 ( V_118 , V_35 , V_67 ,
V_2 ) ;
}
if ( V_29 )
F_160 ( V_118 , V_35 , V_29 ) ;
}
if ( V_322 )
F_6 ( V_2 ) ;
F_11 ( & V_319 -> V_328 ) ;
}
F_13 ( & V_319 -> V_328 ) ;
while ( ! F_180 ( V_324 ) ) {
V_2 = F_270 ( V_324 , struct V_1 ,
V_331 ) ;
F_271 ( & V_2 -> V_331 ) ;
F_272 ( V_35 , V_118 , V_2 ,
& V_2 -> V_332 , V_67 , V_2 -> V_21 . V_22 ) ;
F_6 ( V_2 ) ;
}
F_53 ( V_67 ) ;
return V_29 ;
}
int F_276 ( struct V_34 * V_35 , T_2 V_27 )
{
struct V_1 * V_14 ;
int V_335 = 0 ;
V_14 = F_76 ( V_35 -> V_37 , V_27 ) ;
if ( ! V_14 || V_14 -> V_306 )
V_335 = 1 ;
if ( V_14 )
F_6 ( V_14 ) ;
return V_335 ;
}
static const char * F_277 ( T_2 V_7 )
{
switch ( V_7 ) {
case V_55 | V_336 :
return L_3 ;
case V_55 :
return L_4 ;
case V_336 :
return L_5 ;
case V_337 :
return L_6 ;
default:
F_8 ( 1 ) ;
return L_7 ;
} ;
}
static int F_278 ( struct V_12 * V_13 , T_2 V_7 ,
T_2 V_338 , T_2 V_95 ,
struct V_111 * * V_96 )
{
struct V_111 * V_114 ;
int V_43 ;
int V_339 ;
int V_29 ;
if ( V_7 & ( V_340 | V_341 |
V_342 ) )
V_339 = 2 ;
else
V_339 = 1 ;
V_114 = F_77 ( V_13 , V_7 ) ;
if ( V_114 ) {
F_11 ( & V_114 -> V_52 ) ;
V_114 -> V_338 += V_338 ;
V_114 -> V_343 += V_338 * V_339 ;
V_114 -> V_95 += V_95 ;
V_114 -> V_344 += V_95 * V_339 ;
if ( V_338 > 0 )
V_114 -> V_116 = 0 ;
F_13 ( & V_114 -> V_52 ) ;
* V_96 = V_114 ;
return 0 ;
}
V_114 = F_61 ( sizeof( * V_114 ) , V_40 ) ;
if ( ! V_114 )
return - V_75 ;
V_29 = F_279 ( & V_114 -> V_345 , 0 , V_346 ) ;
if ( V_29 ) {
F_9 ( V_114 ) ;
return V_29 ;
}
for ( V_43 = 0 ; V_43 < V_347 ; V_43 ++ )
F_62 ( & V_114 -> V_348 [ V_43 ] ) ;
F_280 ( & V_114 -> V_349 ) ;
F_281 ( & V_114 -> V_52 ) ;
V_114 -> V_7 = V_7 & V_115 ;
V_114 -> V_338 = V_338 ;
V_114 -> V_343 = V_338 * V_339 ;
V_114 -> V_95 = V_95 ;
V_114 -> V_344 = V_95 * V_339 ;
V_114 -> V_350 = 0 ;
V_114 -> V_351 = 0 ;
V_114 -> V_352 = 0 ;
V_114 -> V_353 = 0 ;
V_114 -> V_116 = 0 ;
V_114 -> V_354 = 0 ;
V_114 -> V_355 = V_356 ;
V_114 -> V_357 = 0 ;
V_114 -> V_358 = 0 ;
F_64 ( & V_114 -> V_91 ) ;
F_62 ( & V_114 -> V_359 ) ;
V_29 = F_282 ( & V_114 -> V_360 , & V_361 ,
V_13 -> V_362 , L_8 ,
F_277 ( V_114 -> V_7 ) ) ;
if ( V_29 ) {
F_9 ( V_114 ) ;
return V_29 ;
}
* V_96 = V_114 ;
F_283 ( & V_114 -> V_99 , & V_13 -> V_96 ) ;
if ( V_7 & V_336 )
V_13 -> V_363 = V_114 ;
return V_29 ;
}
static void F_284 ( struct V_12 * V_37 , T_2 V_7 )
{
T_2 V_364 = F_285 ( V_7 ) &
V_365 ;
F_286 ( & V_37 -> V_366 ) ;
if ( V_7 & V_336 )
V_37 -> V_367 |= V_364 ;
if ( V_7 & V_55 )
V_37 -> V_368 |= V_364 ;
if ( V_7 & V_337 )
V_37 -> V_369 |= V_364 ;
F_287 ( & V_37 -> V_366 ) ;
}
static T_2 F_288 ( struct V_12 * V_37 , T_2 V_7 )
{
struct V_370 * V_371 = V_37 -> V_372 ;
T_2 V_373 = 0 ;
if ( ! V_371 )
return 0 ;
if ( V_7 & V_336 &&
V_371 -> V_374 . V_7 & V_375 ) {
V_373 = V_336 | V_371 -> V_374 . V_373 ;
} else if ( V_7 & V_337 &&
V_371 -> V_376 . V_7 & V_375 ) {
V_373 = V_337 | V_371 -> V_376 . V_373 ;
} else if ( V_7 & V_55 &&
V_371 -> V_377 . V_7 & V_375 ) {
V_373 = V_55 | V_371 -> V_377 . V_373 ;
}
return V_373 ;
}
static T_2 F_289 ( struct V_34 * V_35 , T_2 V_7 )
{
T_2 V_378 = V_35 -> V_37 -> V_379 -> V_380 ;
T_2 V_373 ;
T_2 V_381 ;
T_2 V_382 = 0 ;
F_11 ( & V_35 -> V_37 -> V_383 ) ;
V_373 = F_288 ( V_35 -> V_37 , V_7 ) ;
if ( V_373 ) {
if ( ( V_7 & V_373 ) & V_365 ) {
F_13 ( & V_35 -> V_37 -> V_383 ) ;
return F_290 ( V_373 ) ;
}
}
F_13 ( & V_35 -> V_37 -> V_383 ) ;
for ( V_381 = 0 ; V_381 < V_347 ; V_381 ++ ) {
if ( V_378 >= V_384 [ V_381 ] . V_385 )
V_382 |= V_386 [ V_381 ] ;
}
V_382 &= V_7 ;
if ( V_382 & V_387 )
V_382 = V_387 ;
else if ( V_382 & V_388 )
V_382 = V_388 ;
else if ( V_382 & V_342 )
V_382 = V_342 ;
else if ( V_382 & V_341 )
V_382 = V_341 ;
else if ( V_382 & V_389 )
V_382 = V_389 ;
V_7 &= ~ V_390 ;
return F_290 ( V_7 | V_382 ) ;
}
static T_2 F_291 ( struct V_34 * V_35 , T_2 V_391 )
{
unsigned V_236 ;
T_2 V_7 ;
do {
V_7 = V_391 ;
V_236 = F_292 ( & V_35 -> V_37 -> V_366 ) ;
if ( V_7 & V_336 )
V_7 |= V_35 -> V_37 -> V_367 ;
else if ( V_7 & V_337 )
V_7 |= V_35 -> V_37 -> V_369 ;
else if ( V_7 & V_55 )
V_7 |= V_35 -> V_37 -> V_368 ;
} while ( F_293 ( & V_35 -> V_37 -> V_366 , V_236 ) );
return F_289 ( V_35 , V_7 ) ;
}
T_2 F_294 ( struct V_34 * V_35 , int V_374 )
{
T_2 V_7 ;
T_2 V_29 ;
if ( V_374 )
V_7 = V_336 ;
else if ( V_35 == V_35 -> V_37 -> V_392 )
V_7 = V_337 ;
else
V_7 = V_55 ;
V_29 = F_291 ( V_35 , V_7 ) ;
return V_29 ;
}
int F_295 ( struct V_297 * V_297 , T_2 V_212 )
{
struct V_111 * V_363 ;
struct V_34 * V_35 = F_255 ( V_297 ) -> V_35 ;
struct V_12 * V_37 = V_35 -> V_37 ;
T_2 V_393 ;
int V_29 = 0 ;
int V_394 = 2 ;
int V_395 ;
V_212 = F_149 ( V_212 , V_35 -> V_57 ) ;
if ( F_296 ( V_297 ) ) {
V_394 = 0 ;
ASSERT ( V_396 -> V_397 ) ;
}
V_363 = V_37 -> V_363 ;
if ( ! V_363 )
goto V_398;
V_164:
F_11 ( & V_363 -> V_52 ) ;
V_393 = V_363 -> V_95 + V_363 -> V_351 +
V_363 -> V_350 + V_363 -> V_352 +
V_363 -> V_353 ;
if ( V_393 + V_212 > V_363 -> V_338 ) {
struct V_117 * V_118 ;
if ( ! V_363 -> V_116 ) {
T_2 V_399 ;
V_363 -> V_355 = V_400 ;
F_13 ( & V_363 -> V_52 ) ;
V_398:
V_399 = F_294 ( V_35 , 1 ) ;
V_118 = F_211 ( V_35 ) ;
if ( F_212 ( V_118 ) )
return F_213 ( V_118 ) ;
V_29 = F_297 ( V_118 , V_35 -> V_37 -> V_65 ,
V_399 ,
V_356 ) ;
F_215 ( V_118 , V_35 ) ;
if ( V_29 < 0 ) {
if ( V_29 != - V_314 )
return V_29 ;
else {
V_395 = 1 ;
goto V_401;
}
}
if ( ! V_363 )
V_363 = V_37 -> V_363 ;
goto V_164;
}
V_395 = F_298 (
& V_363 -> V_345 ,
V_393 + V_212 - V_363 -> V_338 ) ;
F_13 ( & V_363 -> V_52 ) ;
V_401:
if ( V_394 &&
! F_209 ( & V_35 -> V_37 -> V_402 ) ) {
V_394 -- ;
if ( V_394 > 0 ) {
F_299 ( V_37 , 0 , - 1 ) ;
F_300 ( V_37 , - 1 ) ;
}
V_118 = F_211 ( V_35 ) ;
if ( F_212 ( V_118 ) )
return F_213 ( V_118 ) ;
if ( V_395 >= 0 ||
F_238 ( V_403 ,
& V_118 -> V_135 -> V_7 ) ||
V_394 > 0 ) {
V_29 = F_301 ( V_118 , V_35 ) ;
if ( V_29 )
return V_29 ;
F_49 ( & V_35 -> V_37 -> V_404 ) ;
F_47 ( & V_35 -> V_37 -> V_404 ) ;
goto V_164;
} else {
F_215 ( V_118 , V_35 ) ;
}
}
F_302 ( V_35 -> V_37 ,
L_9 ,
V_363 -> V_7 , V_212 , 1 ) ;
return - V_314 ;
}
V_363 -> V_353 += V_212 ;
F_302 ( V_35 -> V_37 , L_10 ,
V_363 -> V_7 , V_212 , 1 ) ;
F_13 ( & V_363 -> V_52 ) ;
return V_29 ;
}
int F_260 ( struct V_297 * V_297 , T_2 V_32 , T_2 V_49 )
{
struct V_34 * V_35 = F_255 ( V_297 ) -> V_35 ;
int V_29 ;
V_49 = F_303 ( V_32 + V_49 , V_35 -> V_57 ) -
F_150 ( V_32 , V_35 -> V_57 ) ;
V_32 = F_150 ( V_32 , V_35 -> V_57 ) ;
V_29 = F_295 ( V_297 , V_49 ) ;
if ( V_29 < 0 )
return V_29 ;
V_29 = F_304 ( V_297 , V_32 , V_49 ) ;
return V_29 ;
}
void F_305 ( struct V_297 * V_297 , T_2 V_32 ,
T_2 V_49 )
{
struct V_34 * V_35 = F_255 ( V_297 ) -> V_35 ;
struct V_111 * V_363 ;
V_49 = F_303 ( V_32 + V_49 , V_35 -> V_57 ) -
F_150 ( V_32 , V_35 -> V_57 ) ;
V_32 = F_150 ( V_32 , V_35 -> V_57 ) ;
V_363 = V_35 -> V_37 -> V_363 ;
F_11 ( & V_363 -> V_52 ) ;
if ( F_8 ( V_363 -> V_353 < V_49 ) )
V_363 -> V_353 = 0 ;
else
V_363 -> V_353 -= V_49 ;
F_302 ( V_35 -> V_37 , L_10 ,
V_363 -> V_7 , V_49 , 0 ) ;
F_13 ( & V_363 -> V_52 ) ;
}
void F_263 ( struct V_297 * V_297 , T_2 V_32 , T_2 V_49 )
{
F_305 ( V_297 , V_32 , V_49 ) ;
F_306 ( V_297 , V_32 , V_49 ) ;
}
static void F_307 ( struct V_12 * V_13 )
{
struct V_112 * V_113 = & V_13 -> V_96 ;
struct V_111 * V_114 ;
F_78 () ;
F_79 (found, head, list) {
if ( V_114 -> V_7 & V_55 )
V_114 -> V_355 = V_400 ;
}
F_80 () ;
}
static inline T_2 F_308 ( struct V_262 * V_405 )
{
return ( V_405 -> V_61 << 1 ) ;
}
static int F_309 ( struct V_34 * V_35 ,
struct V_111 * V_406 , int V_407 )
{
struct V_262 * V_263 = & V_35 -> V_37 -> V_266 ;
T_2 V_36 = V_406 -> V_338 - V_406 -> V_352 ;
T_2 V_408 = V_406 -> V_95 + V_406 -> V_351 ;
T_2 V_409 ;
if ( V_407 == V_400 )
return 1 ;
if ( V_406 -> V_7 & V_55 )
V_408 += F_308 ( V_263 ) ;
if ( V_407 == V_410 ) {
V_409 = F_310 ( V_35 -> V_37 -> V_261 ) ;
V_409 = F_35 ( T_2 , V_411 , F_311 ( V_409 , 1 ) ) ;
if ( V_36 - V_408 < V_409 )
return 1 ;
}
if ( V_408 + V_412 < F_312 ( V_36 , 8 ) )
return 0 ;
return 1 ;
}
static T_2 F_313 ( struct V_34 * V_35 , T_2 type )
{
T_2 V_413 ;
if ( type & ( V_342 |
V_389 |
V_388 |
V_387 ) )
V_413 = V_35 -> V_37 -> V_379 -> V_380 ;
else if ( type & V_341 )
V_413 = 2 ;
else
V_413 = 1 ;
return V_413 ;
}
void F_314 ( struct V_117 * V_118 ,
struct V_34 * V_35 ,
T_2 type )
{
struct V_111 * V_13 ;
T_2 V_414 ;
T_2 V_409 ;
int V_29 = 0 ;
T_2 V_415 ;
ASSERT ( F_315 ( & V_35 -> V_37 -> V_416 ) ) ;
V_13 = F_77 ( V_35 -> V_37 , V_337 ) ;
F_11 ( & V_13 -> V_52 ) ;
V_414 = V_13 -> V_338 - V_13 -> V_95 - V_13 -> V_350 -
V_13 -> V_351 - V_13 -> V_352 -
V_13 -> V_353 ;
F_13 ( & V_13 -> V_52 ) ;
V_415 = F_313 ( V_35 , type ) ;
V_409 = F_316 ( V_35 , V_415 ) +
F_207 ( V_35 , 1 ) ;
if ( V_414 < V_409 && F_259 ( V_35 , V_417 ) ) {
F_317 ( V_35 -> V_37 , L_11 ,
V_414 , V_409 , type ) ;
F_318 ( V_13 , 0 , 0 ) ;
}
if ( V_414 < V_409 ) {
T_2 V_7 ;
V_7 = F_294 ( V_35 -> V_37 -> V_392 , 0 ) ;
V_29 = F_319 ( V_118 , V_35 , V_7 ) ;
}
if ( ! V_29 ) {
V_29 = F_320 ( V_35 -> V_37 -> V_392 ,
& V_35 -> V_37 -> V_418 ,
V_409 , V_419 ) ;
if ( ! V_29 )
V_118 -> V_420 += V_409 ;
}
}
static int F_297 ( struct V_117 * V_118 ,
struct V_34 * V_65 , T_2 V_7 , int V_407 )
{
struct V_111 * V_96 ;
struct V_12 * V_37 = V_65 -> V_37 ;
int V_421 = 0 ;
int V_29 = 0 ;
if ( V_118 -> V_422 )
return - V_314 ;
V_96 = F_77 ( V_65 -> V_37 , V_7 ) ;
if ( ! V_96 ) {
V_29 = F_278 ( V_65 -> V_37 , V_7 ,
0 , 0 , & V_96 ) ;
F_32 ( V_29 ) ;
}
F_32 ( ! V_96 ) ;
V_164:
F_11 ( & V_96 -> V_52 ) ;
if ( V_407 < V_96 -> V_355 )
V_407 = V_96 -> V_355 ;
if ( V_96 -> V_116 ) {
if ( F_309 ( V_65 , V_96 , V_407 ) )
V_29 = - V_314 ;
else
V_29 = 0 ;
F_13 ( & V_96 -> V_52 ) ;
return V_29 ;
}
if ( ! F_309 ( V_65 , V_96 , V_407 ) ) {
F_13 ( & V_96 -> V_52 ) ;
return 0 ;
} else if ( V_96 -> V_357 ) {
V_421 = 1 ;
} else {
V_96 -> V_357 = 1 ;
}
F_13 ( & V_96 -> V_52 ) ;
F_49 ( & V_37 -> V_416 ) ;
if ( V_421 ) {
F_47 ( & V_37 -> V_416 ) ;
V_421 = 0 ;
goto V_164;
}
V_118 -> V_422 = true ;
if ( F_321 ( V_96 ) )
V_7 |= ( V_336 | V_55 ) ;
if ( V_7 & V_336 && V_37 -> V_423 ) {
V_37 -> V_424 ++ ;
if ( ! ( V_37 -> V_424 %
V_37 -> V_423 ) )
F_307 ( V_37 ) ;
}
F_314 ( V_118 , V_65 , V_7 ) ;
V_29 = F_319 ( V_118 , V_65 , V_7 ) ;
V_118 -> V_422 = false ;
F_11 ( & V_96 -> V_52 ) ;
if ( V_29 < 0 && V_29 != - V_314 )
goto V_82;
if ( V_29 )
V_96 -> V_116 = 1 ;
else
V_29 = 1 ;
V_96 -> V_355 = V_356 ;
V_82:
V_96 -> V_357 = 0 ;
F_13 ( & V_96 -> V_52 ) ;
F_47 ( & V_37 -> V_416 ) ;
if ( V_118 -> V_277 &&
V_118 -> V_420 >= ( T_2 ) V_412 ) {
F_222 ( V_118 , V_118 -> V_35 ) ;
F_322 ( V_118 ) ;
}
return V_29 ;
}
static int F_323 ( struct V_34 * V_35 ,
struct V_111 * V_96 , T_2 V_212 ,
enum V_425 V_358 )
{
struct V_262 * V_263 = & V_35 -> V_37 -> V_266 ;
T_2 V_426 = F_294 ( V_35 , 0 ) ;
T_2 V_427 ;
T_2 V_428 ;
T_2 V_393 ;
V_393 = V_96 -> V_95 + V_96 -> V_351 +
V_96 -> V_350 + V_96 -> V_352 ;
F_11 ( & V_263 -> V_52 ) ;
V_427 = F_308 ( V_263 ) ;
F_13 ( & V_263 -> V_52 ) ;
if ( V_393 + V_427 >= V_96 -> V_338 )
return 0 ;
V_393 += V_96 -> V_353 ;
F_11 ( & V_35 -> V_37 -> V_429 ) ;
V_428 = V_35 -> V_37 -> V_430 ;
F_13 ( & V_35 -> V_37 -> V_429 ) ;
if ( V_426 & ( V_340 |
V_341 |
V_342 ) )
V_428 >>= 1 ;
if ( V_358 == V_431 )
V_428 >>= 3 ;
else
V_428 >>= 1 ;
if ( V_393 + V_212 < V_96 -> V_338 + V_428 )
return 1 ;
return 0 ;
}
static void F_324 ( struct V_34 * V_35 ,
unsigned long V_432 , int V_433 )
{
struct V_434 * V_435 = V_35 -> V_37 -> V_435 ;
if ( F_325 ( & V_435 -> V_436 ) ) {
F_326 ( V_435 , V_432 , V_437 ) ;
F_46 ( & V_435 -> V_436 ) ;
} else {
F_299 ( V_35 -> V_37 , 0 , V_433 ) ;
if ( ! V_396 -> V_397 )
F_300 ( V_35 -> V_37 , V_433 ) ;
}
}
static inline int F_327 ( struct V_34 * V_35 , T_2 V_438 )
{
T_2 V_212 ;
int V_44 ;
V_212 = F_207 ( V_35 , 1 ) ;
V_44 = ( int ) F_204 ( V_438 , V_212 ) ;
if ( ! V_44 )
V_44 = 1 ;
return V_44 ;
}
static void F_328 ( struct V_34 * V_35 , T_2 V_438 , T_2 V_439 ,
bool V_440 )
{
struct V_262 * V_441 ;
struct V_111 * V_96 ;
struct V_117 * V_118 ;
T_2 V_442 ;
T_2 V_443 ;
long V_444 ;
unsigned long V_432 ;
int V_327 ;
int V_445 ;
enum V_425 V_358 ;
V_445 = F_327 ( V_35 , V_438 ) ;
V_438 = V_445 * V_446 ;
V_118 = (struct V_117 * ) V_396 -> V_397 ;
V_441 = & V_35 -> V_37 -> V_447 ;
V_96 = V_441 -> V_96 ;
V_442 = F_329 (
& V_35 -> V_37 -> V_442 ) ;
if ( V_442 == 0 ) {
if ( V_118 )
return;
if ( V_440 )
F_300 ( V_35 -> V_37 , V_445 ) ;
return;
}
V_327 = 0 ;
while ( V_442 && V_327 < 3 ) {
V_443 = F_330 ( V_442 , V_438 ) ;
V_432 = V_443 >> V_448 ;
F_324 ( V_35 , V_432 , V_445 ) ;
V_443 = F_209 ( & V_35 -> V_37 -> V_449 ) ;
if ( ! V_443 )
goto V_450;
if ( V_443 <= V_432 )
V_443 = 0 ;
else
V_443 -= V_432 ;
F_275 ( V_35 -> V_37 -> V_451 ,
F_209 ( & V_35 -> V_37 -> V_449 ) <=
( int ) V_443 ) ;
V_450:
if ( ! V_118 )
V_358 = V_431 ;
else
V_358 = V_419 ;
F_11 ( & V_96 -> V_52 ) ;
if ( F_323 ( V_35 , V_96 , V_439 , V_358 ) ) {
F_13 ( & V_96 -> V_52 ) ;
break;
}
F_13 ( & V_96 -> V_52 ) ;
V_327 ++ ;
if ( V_440 && ! V_118 ) {
F_300 ( V_35 -> V_37 , V_445 ) ;
} else {
V_444 = F_331 ( 1 ) ;
if ( V_444 )
break;
}
V_442 = F_329 (
& V_35 -> V_37 -> V_442 ) ;
}
}
static int F_332 ( struct V_34 * V_35 ,
struct V_111 * V_96 ,
T_2 V_212 , int V_407 )
{
struct V_262 * V_452 = & V_35 -> V_37 -> V_453 ;
struct V_117 * V_118 ;
V_118 = (struct V_117 * ) V_396 -> V_397 ;
if ( V_118 )
return - V_187 ;
if ( V_407 )
goto V_454;
if ( F_298 ( & V_96 -> V_345 ,
V_212 ) >= 0 )
goto V_454;
if ( V_96 != V_452 -> V_96 )
return - V_314 ;
F_11 ( & V_452 -> V_52 ) ;
if ( F_298 ( & V_96 -> V_345 ,
V_212 - V_452 -> V_61 ) >= 0 ) {
F_13 ( & V_452 -> V_52 ) ;
return - V_314 ;
}
F_13 ( & V_452 -> V_52 ) ;
V_454:
V_118 = F_211 ( V_35 ) ;
if ( F_212 ( V_118 ) )
return - V_314 ;
return F_301 ( V_118 , V_35 ) ;
}
static int F_333 ( struct V_34 * V_35 ,
struct V_111 * V_96 , T_2 V_36 ,
T_2 V_455 , int V_292 )
{
struct V_117 * V_118 ;
int V_44 ;
int V_29 = 0 ;
switch ( V_292 ) {
case V_456 :
case V_457 :
if ( V_292 == V_456 )
V_44 = F_327 ( V_35 , V_36 ) * 2 ;
else
V_44 = - 1 ;
V_118 = F_211 ( V_35 ) ;
if ( F_212 ( V_118 ) ) {
V_29 = F_213 ( V_118 ) ;
break;
}
V_29 = F_334 ( V_118 , V_35 , V_44 ) ;
F_215 ( V_118 , V_35 ) ;
break;
case V_458 :
case V_459 :
F_328 ( V_35 , V_36 * 2 , V_455 ,
V_292 == V_459 ) ;
break;
case V_460 :
V_118 = F_211 ( V_35 ) ;
if ( F_212 ( V_118 ) ) {
V_29 = F_213 ( V_118 ) ;
break;
}
V_29 = F_297 ( V_118 , V_35 -> V_37 -> V_65 ,
F_294 ( V_35 , 0 ) ,
V_356 ) ;
F_215 ( V_118 , V_35 ) ;
if ( V_29 == - V_314 )
V_29 = 0 ;
break;
case V_461 :
V_29 = F_332 ( V_35 , V_96 , V_455 , 0 ) ;
break;
default:
V_29 = - V_314 ;
break;
}
return V_29 ;
}
static inline T_2
F_335 ( struct V_34 * V_35 ,
struct V_111 * V_96 )
{
T_2 V_393 ;
T_2 V_462 ;
T_2 V_438 ;
V_438 = F_24 ( T_2 , F_336 () * V_303 , V_463 ) ;
F_11 ( & V_96 -> V_52 ) ;
if ( F_323 ( V_35 , V_96 , V_438 ,
V_431 ) ) {
V_438 = 0 ;
goto V_82;
}
V_393 = V_96 -> V_95 + V_96 -> V_351 +
V_96 -> V_350 + V_96 -> V_352 +
V_96 -> V_353 ;
if ( F_323 ( V_35 , V_96 , V_303 , V_431 ) )
V_462 = F_311 ( V_96 -> V_338 , 95 ) ;
else
V_462 = F_311 ( V_96 -> V_338 , 90 ) ;
if ( V_393 > V_462 )
V_438 = V_393 - V_462 ;
else
V_438 = 0 ;
V_438 = F_330 ( V_438 , V_96 -> V_353 +
V_96 -> V_351 ) ;
V_82:
F_13 ( & V_96 -> V_52 ) ;
return V_438 ;
}
static inline int F_337 ( struct V_111 * V_96 ,
struct V_12 * V_37 , T_2 V_393 )
{
T_2 V_409 = F_311 ( V_96 -> V_338 , 98 ) ;
if ( V_96 -> V_95 >= V_409 )
return 0 ;
return ( V_393 >= V_409 && ! F_40 ( V_37 ) &&
! F_238 ( V_464 , & V_37 -> V_465 ) ) ;
}
static int F_338 ( struct V_111 * V_96 ,
struct V_12 * V_37 ,
int V_466 )
{
T_2 V_393 ;
F_11 ( & V_96 -> V_52 ) ;
if ( V_466 > V_461 && V_96 -> V_116 ) {
F_13 ( & V_96 -> V_52 ) ;
return 0 ;
}
V_393 = V_96 -> V_95 + V_96 -> V_351 +
V_96 -> V_350 + V_96 -> V_352 +
V_96 -> V_353 ;
if ( F_337 ( V_96 , V_37 , V_393 ) ) {
F_13 ( & V_96 -> V_52 ) ;
return 1 ;
}
F_13 ( & V_96 -> V_52 ) ;
return 0 ;
}
static void F_339 ( struct V_467 * V_93 )
{
struct V_12 * V_37 ;
struct V_111 * V_96 ;
T_2 V_438 ;
int V_466 ;
V_37 = F_55 ( V_93 , struct V_12 , V_468 ) ;
V_96 = F_77 ( V_37 , V_55 ) ;
V_438 = F_335 ( V_37 -> V_469 ,
V_96 ) ;
if ( ! V_438 )
return;
V_466 = V_456 ;
do {
F_333 ( V_37 -> V_469 , V_96 , V_438 ,
V_438 , V_466 ) ;
V_466 ++ ;
if ( ! F_338 ( V_96 , V_37 ,
V_466 ) )
return;
} while ( V_466 < V_461 );
}
void F_340 ( struct V_467 * V_93 )
{
F_341 ( V_93 , F_339 ) ;
}
static int F_342 ( struct V_34 * V_35 ,
struct V_262 * V_441 ,
T_2 V_455 ,
enum V_425 V_358 )
{
struct V_111 * V_96 = V_441 -> V_96 ;
T_2 V_393 ;
T_2 V_36 = V_455 ;
int V_466 = V_456 ;
int V_29 = 0 ;
bool V_470 = false ;
V_164:
V_29 = 0 ;
F_11 ( & V_96 -> V_52 ) ;
while ( V_358 == V_431 && ! V_470 &&
V_96 -> V_358 ) {
F_13 ( & V_96 -> V_52 ) ;
if ( V_396 -> V_397 )
return - V_187 ;
V_29 = F_343 ( V_96 -> V_91 , ! V_96 -> V_358 ) ;
if ( V_29 )
return - V_471 ;
F_11 ( & V_96 -> V_52 ) ;
}
V_29 = - V_314 ;
V_393 = V_96 -> V_95 + V_96 -> V_351 +
V_96 -> V_350 + V_96 -> V_352 +
V_96 -> V_353 ;
if ( V_393 <= V_96 -> V_338 ) {
if ( V_393 + V_455 <= V_96 -> V_338 ) {
V_96 -> V_353 += V_455 ;
F_302 ( V_35 -> V_37 ,
L_10 , V_96 -> V_7 , V_455 , 1 ) ;
V_29 = 0 ;
} else {
V_36 = V_455 ;
}
} else {
V_36 = V_393 - V_96 -> V_338 +
( V_455 * 2 ) ;
}
if ( V_29 && F_323 ( V_35 , V_96 , V_455 , V_358 ) ) {
V_96 -> V_353 += V_455 ;
F_302 ( V_35 -> V_37 , L_10 ,
V_96 -> V_7 , V_455 ,
1 ) ;
V_29 = 0 ;
}
if ( V_29 && V_358 != V_419 ) {
V_470 = true ;
V_96 -> V_358 = 1 ;
} else if ( ! V_29 && V_96 -> V_7 & V_55 ) {
V_393 += V_455 ;
if ( ! V_35 -> V_37 -> V_472 &&
F_337 ( V_96 , V_35 -> V_37 , V_393 ) &&
! F_344 ( & V_35 -> V_37 -> V_468 ) )
F_345 ( V_473 ,
& V_35 -> V_37 -> V_468 ) ;
}
F_13 ( & V_96 -> V_52 ) ;
if ( ! V_29 || V_358 == V_419 )
goto V_82;
V_29 = F_333 ( V_35 , V_96 , V_36 , V_455 ,
V_466 ) ;
V_466 ++ ;
if ( V_358 == V_474 &&
( V_466 == V_458 ||
V_466 == V_459 ) )
V_466 = V_460 ;
if ( ! V_29 )
goto V_164;
else if ( V_358 == V_474 &&
V_466 < V_461 )
goto V_164;
else if ( V_358 == V_431 &&
V_466 <= V_461 )
goto V_164;
V_82:
if ( V_29 == - V_314 &&
F_346 ( V_35 -> V_475 == V_476 ) ) {
struct V_262 * V_263 =
& V_35 -> V_37 -> V_266 ;
if ( V_441 != V_263 &&
! F_347 ( V_263 , V_455 ) )
V_29 = 0 ;
}
if ( V_29 == - V_314 )
F_302 ( V_35 -> V_37 ,
L_9 ,
V_96 -> V_7 , V_455 , 1 ) ;
if ( V_470 ) {
F_11 ( & V_96 -> V_52 ) ;
V_96 -> V_358 = 0 ;
F_348 ( & V_96 -> V_91 ) ;
F_13 ( & V_96 -> V_52 ) ;
}
return V_29 ;
}
static struct V_262 * F_349 (
const struct V_117 * V_118 ,
const struct V_34 * V_35 )
{
struct V_262 * V_441 = NULL ;
if ( F_238 ( V_291 , & V_35 -> V_292 ) ||
( V_35 == V_35 -> V_37 -> V_477 && V_118 -> V_478 ) ||
( V_35 == V_35 -> V_37 -> V_479 ) )
V_441 = V_118 -> V_441 ;
if ( ! V_441 )
V_441 = V_35 -> V_441 ;
if ( ! V_441 )
V_441 = & V_35 -> V_37 -> V_480 ;
return V_441 ;
}
static int F_347 ( struct V_262 * V_441 ,
T_2 V_36 )
{
int V_29 = - V_314 ;
F_11 ( & V_441 -> V_52 ) ;
if ( V_441 -> V_10 >= V_36 ) {
V_441 -> V_10 -= V_36 ;
if ( V_441 -> V_10 < V_441 -> V_61 )
V_441 -> V_116 = 0 ;
V_29 = 0 ;
}
F_13 ( & V_441 -> V_52 ) ;
return V_29 ;
}
static void F_350 ( struct V_262 * V_441 ,
T_2 V_36 , int V_481 )
{
F_11 ( & V_441 -> V_52 ) ;
V_441 -> V_10 += V_36 ;
if ( V_481 )
V_441 -> V_61 += V_36 ;
else if ( V_441 -> V_10 >= V_441 -> V_61 )
V_441 -> V_116 = 1 ;
F_13 ( & V_441 -> V_52 ) ;
}
int F_351 ( struct V_12 * V_37 ,
struct V_262 * V_482 , T_2 V_36 ,
int V_483 )
{
struct V_262 * V_263 = & V_37 -> V_266 ;
T_2 V_484 ;
if ( V_263 -> V_96 != V_482 -> V_96 )
return - V_314 ;
F_11 ( & V_263 -> V_52 ) ;
V_484 = F_312 ( V_263 -> V_61 , V_483 ) ;
if ( V_263 -> V_10 < V_484 + V_36 ) {
F_13 ( & V_263 -> V_52 ) ;
return - V_314 ;
}
V_263 -> V_10 -= V_36 ;
if ( V_263 -> V_10 < V_263 -> V_61 )
V_263 -> V_116 = 0 ;
F_13 ( & V_263 -> V_52 ) ;
F_350 ( V_482 , V_36 , 1 ) ;
return 0 ;
}
static void F_352 ( struct V_12 * V_37 ,
struct V_262 * V_441 ,
struct V_262 * V_482 , T_2 V_36 )
{
struct V_111 * V_96 = V_441 -> V_96 ;
F_11 ( & V_441 -> V_52 ) ;
if ( V_36 == ( T_2 ) - 1 )
V_36 = V_441 -> V_61 ;
V_441 -> V_61 -= V_36 ;
if ( V_441 -> V_10 >= V_441 -> V_61 ) {
V_36 = V_441 -> V_10 - V_441 -> V_61 ;
V_441 -> V_10 = V_441 -> V_61 ;
V_441 -> V_116 = 1 ;
} else {
V_36 = 0 ;
}
F_13 ( & V_441 -> V_52 ) ;
if ( V_36 > 0 ) {
if ( V_482 ) {
F_11 ( & V_482 -> V_52 ) ;
if ( ! V_482 -> V_116 ) {
T_2 V_485 ;
V_485 = V_482 -> V_61 - V_482 -> V_10 ;
V_485 = F_330 ( V_36 , V_485 ) ;
V_482 -> V_10 += V_485 ;
if ( V_482 -> V_10 >= V_482 -> V_61 )
V_482 -> V_116 = 1 ;
V_36 -= V_485 ;
}
F_13 ( & V_482 -> V_52 ) ;
}
if ( V_36 ) {
F_11 ( & V_96 -> V_52 ) ;
V_96 -> V_353 -= V_36 ;
F_302 ( V_37 , L_10 ,
V_96 -> V_7 , V_36 , 0 ) ;
F_13 ( & V_96 -> V_52 ) ;
}
}
}
static int F_353 ( struct V_262 * V_486 ,
struct V_262 * V_487 , T_2 V_36 )
{
int V_29 ;
V_29 = F_347 ( V_486 , V_36 ) ;
if ( V_29 )
return V_29 ;
F_350 ( V_487 , V_36 , 1 ) ;
return 0 ;
}
void F_354 ( struct V_262 * V_488 , unsigned short type )
{
memset ( V_488 , 0 , sizeof( * V_488 ) ) ;
F_281 ( & V_488 -> V_52 ) ;
V_488 -> type = type ;
}
struct V_262 * F_355 ( struct V_34 * V_35 ,
unsigned short type )
{
struct V_262 * V_441 ;
struct V_12 * V_37 = V_35 -> V_37 ;
V_441 = F_218 ( sizeof( * V_441 ) , V_40 ) ;
if ( ! V_441 )
return NULL ;
F_354 ( V_441 , type ) ;
V_441 -> V_96 = F_77 ( V_37 ,
V_55 ) ;
return V_441 ;
}
void F_356 ( struct V_34 * V_35 ,
struct V_262 * V_488 )
{
if ( ! V_488 )
return;
F_357 ( V_35 , V_488 , ( T_2 ) - 1 ) ;
F_9 ( V_488 ) ;
}
void F_358 ( struct V_262 * V_488 )
{
F_9 ( V_488 ) ;
}
int F_320 ( struct V_34 * V_35 ,
struct V_262 * V_441 , T_2 V_36 ,
enum V_425 V_358 )
{
int V_29 ;
if ( V_36 == 0 )
return 0 ;
V_29 = F_342 ( V_35 , V_441 , V_36 , V_358 ) ;
if ( ! V_29 ) {
F_350 ( V_441 , V_36 , 1 ) ;
return 0 ;
}
return V_29 ;
}
int F_359 ( struct V_34 * V_35 ,
struct V_262 * V_441 , int V_483 )
{
T_2 V_36 = 0 ;
int V_29 = - V_314 ;
if ( ! V_441 )
return 0 ;
F_11 ( & V_441 -> V_52 ) ;
V_36 = F_312 ( V_441 -> V_61 , V_483 ) ;
if ( V_441 -> V_10 >= V_36 )
V_29 = 0 ;
F_13 ( & V_441 -> V_52 ) ;
return V_29 ;
}
int F_360 ( struct V_34 * V_35 ,
struct V_262 * V_441 , T_2 V_489 ,
enum V_425 V_358 )
{
T_2 V_36 = 0 ;
int V_29 = - V_314 ;
if ( ! V_441 )
return 0 ;
F_11 ( & V_441 -> V_52 ) ;
V_36 = V_489 ;
if ( V_441 -> V_10 >= V_36 )
V_29 = 0 ;
else
V_36 -= V_441 -> V_10 ;
F_13 ( & V_441 -> V_52 ) ;
if ( ! V_29 )
return 0 ;
V_29 = F_342 ( V_35 , V_441 , V_36 , V_358 ) ;
if ( ! V_29 ) {
F_350 ( V_441 , V_36 , 0 ) ;
return 0 ;
}
return V_29 ;
}
int F_361 ( struct V_262 * V_490 ,
struct V_262 * V_491 ,
T_2 V_36 )
{
return F_353 ( V_490 , V_491 , V_36 ) ;
}
void F_357 ( struct V_34 * V_35 ,
struct V_262 * V_441 ,
T_2 V_36 )
{
struct V_262 * V_263 = & V_35 -> V_37 -> V_266 ;
if ( V_263 == V_441 ||
V_441 -> V_96 != V_263 -> V_96 )
V_263 = NULL ;
F_352 ( V_35 -> V_37 , V_441 , V_263 ,
V_36 ) ;
}
static T_2 F_362 ( struct V_12 * V_37 )
{
struct V_111 * V_406 ;
T_2 V_36 ;
T_2 V_492 ;
T_2 V_493 ;
int V_257 = F_205 ( V_37 -> V_261 ) ;
V_406 = F_77 ( V_37 , V_336 ) ;
F_11 ( & V_406 -> V_52 ) ;
V_493 = V_406 -> V_95 ;
F_13 ( & V_406 -> V_52 ) ;
V_406 = F_77 ( V_37 , V_55 ) ;
F_11 ( & V_406 -> V_52 ) ;
if ( V_406 -> V_7 & V_336 )
V_493 = 0 ;
V_492 = V_406 -> V_95 ;
F_13 ( & V_406 -> V_52 ) ;
V_36 = ( V_493 >> V_37 -> V_435 -> V_494 ) *
V_257 * 2 ;
V_36 += F_201 ( V_493 + V_492 , 50 ) ;
if ( V_36 * 3 > V_492 )
V_36 = F_201 ( V_492 , 3 ) ;
return F_149 ( V_36 , V_37 -> V_65 -> V_56 << 10 ) ;
}
static void F_363 ( struct V_12 * V_37 )
{
struct V_262 * V_441 = & V_37 -> V_266 ;
struct V_111 * V_406 = V_441 -> V_96 ;
T_2 V_36 ;
V_36 = F_362 ( V_37 ) ;
F_11 ( & V_406 -> V_52 ) ;
F_11 ( & V_441 -> V_52 ) ;
V_441 -> V_61 = F_24 ( T_2 , V_36 , V_495 ) ;
V_36 = V_406 -> V_95 + V_406 -> V_350 +
V_406 -> V_351 + V_406 -> V_352 +
V_406 -> V_353 ;
if ( V_406 -> V_338 > V_36 ) {
V_36 = V_406 -> V_338 - V_36 ;
V_441 -> V_10 += V_36 ;
V_406 -> V_353 += V_36 ;
F_302 ( V_37 , L_10 ,
V_406 -> V_7 , V_36 , 1 ) ;
}
if ( V_441 -> V_10 >= V_441 -> V_61 ) {
V_36 = V_441 -> V_10 - V_441 -> V_61 ;
V_406 -> V_353 -= V_36 ;
F_302 ( V_37 , L_10 ,
V_406 -> V_7 , V_36 , 0 ) ;
V_441 -> V_10 = V_441 -> V_61 ;
V_441 -> V_116 = 1 ;
}
F_13 ( & V_441 -> V_52 ) ;
F_13 ( & V_406 -> V_52 ) ;
}
static void F_364 ( struct V_12 * V_37 )
{
struct V_111 * V_96 ;
V_96 = F_77 ( V_37 , V_337 ) ;
V_37 -> V_418 . V_96 = V_96 ;
V_96 = F_77 ( V_37 , V_55 ) ;
V_37 -> V_266 . V_96 = V_96 ;
V_37 -> V_447 . V_96 = V_96 ;
V_37 -> V_496 . V_96 = V_96 ;
V_37 -> V_480 . V_96 = V_96 ;
V_37 -> V_453 . V_96 = V_96 ;
V_37 -> V_65 -> V_441 = & V_37 -> V_266 ;
V_37 -> V_477 -> V_441 = & V_37 -> V_266 ;
V_37 -> V_497 -> V_441 = & V_37 -> V_266 ;
V_37 -> V_89 -> V_441 = & V_37 -> V_266 ;
if ( V_37 -> V_498 )
V_37 -> V_498 -> V_441 = & V_37 -> V_266 ;
V_37 -> V_392 -> V_441 = & V_37 -> V_418 ;
F_363 ( V_37 ) ;
}
static void F_365 ( struct V_12 * V_37 )
{
F_352 ( V_37 , & V_37 -> V_266 , NULL ,
( T_2 ) - 1 ) ;
F_8 ( V_37 -> V_447 . V_61 > 0 ) ;
F_8 ( V_37 -> V_447 . V_10 > 0 ) ;
F_8 ( V_37 -> V_496 . V_61 > 0 ) ;
F_8 ( V_37 -> V_496 . V_10 > 0 ) ;
F_8 ( V_37 -> V_418 . V_61 > 0 ) ;
F_8 ( V_37 -> V_418 . V_10 > 0 ) ;
F_8 ( V_37 -> V_453 . V_61 > 0 ) ;
F_8 ( V_37 -> V_453 . V_10 > 0 ) ;
}
void F_366 ( struct V_117 * V_118 ,
struct V_34 * V_35 )
{
if ( ! V_118 -> V_441 )
return;
if ( ! V_118 -> V_351 )
return;
F_302 ( V_35 -> V_37 , L_12 ,
V_118 -> V_308 , V_118 -> V_351 , 0 ) ;
F_357 ( V_35 , V_118 -> V_441 , V_118 -> V_351 ) ;
V_118 -> V_351 = 0 ;
}
void F_322 ( struct V_117 * V_118 )
{
struct V_12 * V_37 = V_118 -> V_35 -> V_37 ;
if ( ! V_118 -> V_420 )
return;
F_367 ( ! F_180 ( & V_118 -> V_280 ) ) ;
F_352 ( V_37 , & V_37 -> V_418 , NULL ,
V_118 -> V_420 ) ;
V_118 -> V_420 = 0 ;
}
int F_368 ( struct V_117 * V_118 ,
struct V_297 * V_297 )
{
struct V_34 * V_35 = F_255 ( V_297 ) -> V_35 ;
struct V_262 * V_490 = F_349 ( V_118 , V_35 ) ;
struct V_262 * V_491 = V_35 -> V_499 ;
T_2 V_36 = F_207 ( V_35 , 1 ) ;
F_302 ( V_35 -> V_37 , L_13 ,
F_369 ( V_297 ) , V_36 , 1 ) ;
return F_353 ( V_490 , V_491 , V_36 ) ;
}
void F_370 ( struct V_297 * V_297 )
{
struct V_34 * V_35 = F_255 ( V_297 ) -> V_35 ;
T_2 V_36 = F_207 ( V_35 , 1 ) ;
F_302 ( V_35 -> V_37 , L_13 ,
F_369 ( V_297 ) , V_36 , 0 ) ;
F_357 ( V_35 , V_35 -> V_499 , V_36 ) ;
}
int F_371 ( struct V_34 * V_35 ,
struct V_262 * V_488 ,
int V_445 ,
T_2 * V_231 ,
bool V_500 )
{
T_2 V_36 ;
int V_29 ;
struct V_262 * V_263 = & V_35 -> V_37 -> V_266 ;
if ( V_35 -> V_37 -> V_501 ) {
V_36 = 3 * V_35 -> V_56 ;
V_29 = F_372 ( V_35 , V_36 ) ;
if ( V_29 )
return V_29 ;
} else {
V_36 = 0 ;
}
* V_231 = V_36 ;
V_36 = F_207 ( V_35 , V_445 ) ;
V_488 -> V_96 = F_77 ( V_35 -> V_37 ,
V_55 ) ;
V_29 = F_320 ( V_35 , V_488 , V_36 ,
V_431 ) ;
if ( V_29 == - V_314 && V_500 )
V_29 = F_361 ( V_263 , V_488 , V_36 ) ;
if ( V_29 && * V_231 )
F_373 ( V_35 , * V_231 ) ;
return V_29 ;
}
void F_374 ( struct V_34 * V_35 ,
struct V_262 * V_488 ,
T_2 V_231 )
{
F_357 ( V_35 , V_488 , ( T_2 ) - 1 ) ;
}
static unsigned F_375 ( struct V_297 * V_297 , T_2 V_36 )
{
unsigned V_502 = 0 ;
unsigned V_503 = 0 ;
unsigned V_504 = 0 ;
V_504 = ( unsigned ) F_204 ( V_36 +
V_505 - 1 ,
V_505 ) ;
ASSERT ( V_504 ) ;
ASSERT ( F_255 ( V_297 ) -> V_506 >= V_504 ) ;
F_255 ( V_297 ) -> V_506 -= V_504 ;
if ( F_255 ( V_297 ) -> V_506 == 0 &&
F_376 ( V_507 ,
& F_255 ( V_297 ) -> V_508 ) )
V_502 = 1 ;
if ( F_255 ( V_297 ) -> V_506 >=
F_255 ( V_297 ) -> V_509 )
return V_502 ;
V_503 = F_255 ( V_297 ) -> V_509 -
F_255 ( V_297 ) -> V_506 ;
F_255 ( V_297 ) -> V_509 -= V_503 ;
return V_503 + V_502 ;
}
static T_2 F_377 ( struct V_297 * V_297 , T_2 V_36 ,
int V_510 )
{
struct V_34 * V_35 = F_255 ( V_297 ) -> V_35 ;
T_2 V_511 , V_259 ;
if ( F_255 ( V_297 ) -> V_7 & V_512 &&
F_255 ( V_297 ) -> V_256 == 0 )
return 0 ;
V_511 = F_203 ( V_35 , F_255 ( V_297 ) -> V_256 ) ;
if ( V_510 )
F_255 ( V_297 ) -> V_256 += V_36 ;
else
F_255 ( V_297 ) -> V_256 -= V_36 ;
V_259 = F_203 ( V_35 , F_255 ( V_297 ) -> V_256 ) ;
if ( V_511 == V_259 )
return 0 ;
if ( V_510 )
return F_207 ( V_35 ,
V_259 - V_511 ) ;
return F_207 ( V_35 , V_511 - V_259 ) ;
}
int F_378 ( struct V_297 * V_297 , T_2 V_36 )
{
struct V_34 * V_35 = F_255 ( V_297 ) -> V_35 ;
struct V_262 * V_441 = & V_35 -> V_37 -> V_447 ;
T_2 V_513 = 0 ;
T_2 V_256 ;
unsigned V_514 = 0 ;
int V_515 = 0 ;
enum V_425 V_358 = V_431 ;
int V_29 = 0 ;
bool V_516 = true ;
T_2 V_517 = 0 ;
unsigned V_518 ;
if ( F_296 ( V_297 ) ) {
V_358 = V_419 ;
V_516 = false ;
}
if ( V_358 != V_419 &&
F_379 ( V_35 -> V_37 ) )
F_380 ( 1 ) ;
if ( V_516 )
F_49 ( & F_255 ( V_297 ) -> V_519 ) ;
V_36 = F_149 ( V_36 , V_35 -> V_57 ) ;
F_11 ( & F_255 ( V_297 ) -> V_52 ) ;
V_514 = ( unsigned ) F_204 ( V_36 +
V_505 - 1 ,
V_505 ) ;
F_255 ( V_297 ) -> V_506 += V_514 ;
V_514 = 0 ;
if ( F_255 ( V_297 ) -> V_506 >
F_255 ( V_297 ) -> V_509 )
V_514 = F_255 ( V_297 ) -> V_506 -
F_255 ( V_297 ) -> V_509 ;
if ( ! F_238 ( V_507 ,
& F_255 ( V_297 ) -> V_508 ) ) {
V_514 ++ ;
V_515 = 1 ;
}
V_513 = F_207 ( V_35 , V_514 ) ;
V_513 += F_377 ( V_297 , V_36 , 1 ) ;
V_256 = F_255 ( V_297 ) -> V_256 ;
F_13 ( & F_255 ( V_297 ) -> V_52 ) ;
if ( V_35 -> V_37 -> V_501 ) {
V_29 = F_372 ( V_35 ,
V_514 * V_35 -> V_56 ) ;
if ( V_29 )
goto V_520;
}
V_29 = F_342 ( V_35 , V_441 , V_513 , V_358 ) ;
if ( F_346 ( V_29 ) ) {
F_373 ( V_35 , V_514 * V_35 -> V_56 ) ;
goto V_520;
}
F_11 ( & F_255 ( V_297 ) -> V_52 ) ;
if ( V_515 ) {
F_262 ( V_507 ,
& F_255 ( V_297 ) -> V_508 ) ;
V_514 -- ;
}
F_255 ( V_297 ) -> V_509 += V_514 ;
F_13 ( & F_255 ( V_297 ) -> V_52 ) ;
if ( V_516 )
F_47 ( & F_255 ( V_297 ) -> V_519 ) ;
if ( V_513 )
F_302 ( V_35 -> V_37 , L_14 ,
F_369 ( V_297 ) , V_513 , 1 ) ;
F_350 ( V_441 , V_513 , 1 ) ;
return 0 ;
V_520:
F_11 ( & F_255 ( V_297 ) -> V_52 ) ;
V_518 = F_375 ( V_297 , V_36 ) ;
if ( F_255 ( V_297 ) -> V_256 == V_256 ) {
F_377 ( V_297 , V_36 , 0 ) ;
} else {
T_2 V_521 = F_255 ( V_297 ) -> V_256 ;
T_2 V_212 ;
V_212 = V_256 - F_255 ( V_297 ) -> V_256 ;
F_255 ( V_297 ) -> V_256 = V_256 ;
V_517 = F_377 ( V_297 , V_212 , 0 ) ;
F_255 ( V_297 ) -> V_256 = V_256 - V_36 ;
V_212 = V_256 - V_521 ;
V_212 = F_377 ( V_297 , V_212 , 0 ) ;
F_255 ( V_297 ) -> V_256 = V_521 - V_36 ;
if ( V_212 > V_517 )
V_517 = V_212 - V_517 ;
else
V_517 = 0 ;
}
F_13 ( & F_255 ( V_297 ) -> V_52 ) ;
if ( V_518 )
V_517 += F_207 ( V_35 , V_518 ) ;
if ( V_517 ) {
F_357 ( V_35 , V_441 , V_517 ) ;
F_302 ( V_35 -> V_37 , L_14 ,
F_369 ( V_297 ) , V_517 , 0 ) ;
}
if ( V_516 )
F_47 ( & F_255 ( V_297 ) -> V_519 ) ;
return V_29 ;
}
void F_381 ( struct V_297 * V_297 , T_2 V_36 )
{
struct V_34 * V_35 = F_255 ( V_297 ) -> V_35 ;
T_2 V_517 = 0 ;
unsigned V_518 ;
V_36 = F_149 ( V_36 , V_35 -> V_57 ) ;
F_11 ( & F_255 ( V_297 ) -> V_52 ) ;
V_518 = F_375 ( V_297 , V_36 ) ;
if ( V_36 )
V_517 = F_377 ( V_297 , V_36 , 0 ) ;
F_13 ( & F_255 ( V_297 ) -> V_52 ) ;
if ( V_518 > 0 )
V_517 += F_207 ( V_35 , V_518 ) ;
if ( F_235 ( V_35 ) )
return;
F_302 ( V_35 -> V_37 , L_14 ,
F_369 ( V_297 ) , V_517 , 0 ) ;
F_357 ( V_35 , & V_35 -> V_37 -> V_447 ,
V_517 ) ;
}
int F_382 ( struct V_297 * V_297 , T_2 V_32 , T_2 V_49 )
{
int V_29 ;
V_29 = F_260 ( V_297 , V_32 , V_49 ) ;
if ( V_29 < 0 )
return V_29 ;
V_29 = F_378 ( V_297 , V_49 ) ;
if ( V_29 < 0 )
F_263 ( V_297 , V_32 , V_49 ) ;
return V_29 ;
}
void F_383 ( struct V_297 * V_297 , T_2 V_32 , T_2 V_49 )
{
F_381 ( V_297 , V_49 ) ;
F_263 ( V_297 , V_32 , V_49 ) ;
}
static int F_384 ( struct V_117 * V_118 ,
struct V_34 * V_35 , T_2 V_27 ,
T_2 V_36 , int V_398 )
{
struct V_1 * V_2 = NULL ;
struct V_12 * V_13 = V_35 -> V_37 ;
T_2 V_522 = V_36 ;
T_2 V_523 ;
T_2 V_524 ;
int V_339 ;
F_11 ( & V_13 -> V_525 ) ;
V_523 = F_385 ( V_13 -> V_261 ) ;
if ( V_398 )
V_523 += V_36 ;
else
V_523 -= V_36 ;
F_386 ( V_13 -> V_261 , V_523 ) ;
F_13 ( & V_13 -> V_525 ) ;
while ( V_522 ) {
V_2 = F_76 ( V_13 , V_27 ) ;
if ( ! V_2 )
return - V_161 ;
if ( V_2 -> V_7 & ( V_340 |
V_341 |
V_342 ) )
V_339 = 2 ;
else
V_339 = 1 ;
if ( ! V_398 && V_2 -> V_3 == V_103 )
F_59 ( V_2 , 1 ) ;
V_524 = V_27 - V_2 -> V_21 . V_22 ;
F_8 ( V_524 > V_2 -> V_21 . V_33 ) ;
F_11 ( & V_2 -> V_96 -> V_52 ) ;
F_11 ( & V_2 -> V_52 ) ;
if ( F_259 ( V_35 , V_312 ) &&
V_2 -> V_304 < V_321 )
V_2 -> V_304 = V_321 ;
V_523 = F_58 ( & V_2 -> V_97 ) ;
V_36 = F_330 ( V_522 , V_2 -> V_21 . V_33 - V_524 ) ;
if ( V_398 ) {
V_523 += V_36 ;
F_387 ( & V_2 -> V_97 , V_523 ) ;
V_2 -> V_10 -= V_36 ;
V_2 -> V_96 -> V_351 -= V_36 ;
V_2 -> V_96 -> V_95 += V_36 ;
V_2 -> V_96 -> V_344 += V_36 * V_339 ;
F_13 ( & V_2 -> V_52 ) ;
F_13 ( & V_2 -> V_96 -> V_52 ) ;
} else {
V_523 -= V_36 ;
F_387 ( & V_2 -> V_97 , V_523 ) ;
V_2 -> V_9 += V_36 ;
V_2 -> V_96 -> V_350 += V_36 ;
V_2 -> V_96 -> V_95 -= V_36 ;
V_2 -> V_96 -> V_344 -= V_36 * V_339 ;
F_13 ( & V_2 -> V_52 ) ;
F_13 ( & V_2 -> V_96 -> V_52 ) ;
F_388 ( V_13 -> V_63 ,
V_27 , V_27 + V_36 - 1 ,
V_40 | V_526 ) ;
}
F_11 ( & V_118 -> V_135 -> V_328 ) ;
if ( F_180 ( & V_2 -> V_330 ) ) {
F_72 ( & V_2 -> V_330 ,
& V_118 -> V_135 -> V_320 ) ;
V_118 -> V_135 -> V_264 ++ ;
F_4 ( V_2 ) ;
}
F_13 ( & V_118 -> V_135 -> V_328 ) ;
if ( ! V_398 && V_523 == 0 ) {
F_11 ( & V_13 -> V_527 ) ;
if ( F_180 ( & V_2 -> V_528 ) ) {
F_4 ( V_2 ) ;
F_72 ( & V_2 -> V_528 ,
& V_13 -> V_529 ) ;
}
F_13 ( & V_13 -> V_527 ) ;
}
F_6 ( V_2 ) ;
V_522 -= V_36 ;
V_27 += V_36 ;
}
return 0 ;
}
static T_2 V_26 ( struct V_34 * V_35 , T_2 V_530 )
{
struct V_1 * V_2 ;
T_2 V_27 ;
F_11 ( & V_35 -> V_37 -> V_18 ) ;
V_27 = V_35 -> V_37 -> V_26 ;
F_13 ( & V_35 -> V_37 -> V_18 ) ;
if ( V_27 < ( T_2 ) - 1 )
return V_27 ;
V_2 = F_75 ( V_35 -> V_37 , V_530 ) ;
if ( ! V_2 )
return 0 ;
V_27 = V_2 -> V_21 . V_22 ;
F_6 ( V_2 ) ;
return V_27 ;
}
static int F_389 ( struct V_34 * V_35 ,
struct V_1 * V_2 ,
T_2 V_27 , T_2 V_36 , int V_10 )
{
F_11 ( & V_2 -> V_96 -> V_52 ) ;
F_11 ( & V_2 -> V_52 ) ;
V_2 -> V_9 += V_36 ;
V_2 -> V_96 -> V_350 += V_36 ;
if ( V_10 ) {
V_2 -> V_10 -= V_36 ;
V_2 -> V_96 -> V_351 -= V_36 ;
}
F_13 ( & V_2 -> V_52 ) ;
F_13 ( & V_2 -> V_96 -> V_52 ) ;
F_388 ( V_35 -> V_37 -> V_63 , V_27 ,
V_27 + V_36 - 1 , V_40 | V_526 ) ;
if ( V_10 )
F_390 ( V_35 , V_27 , V_36 ) ;
return 0 ;
}
int F_173 ( struct V_34 * V_35 ,
T_2 V_27 , T_2 V_36 , int V_10 )
{
struct V_1 * V_2 ;
V_2 = F_76 ( V_35 -> V_37 , V_27 ) ;
F_32 ( ! V_2 ) ;
F_389 ( V_35 , V_2 , V_27 , V_36 , V_10 ) ;
F_6 ( V_2 ) ;
return 0 ;
}
int F_391 ( struct V_34 * V_35 ,
T_2 V_27 , T_2 V_36 )
{
struct V_1 * V_2 ;
int V_29 ;
V_2 = F_76 ( V_35 -> V_37 , V_27 ) ;
if ( ! V_2 )
return - V_531 ;
F_59 ( V_2 , 1 ) ;
F_389 ( V_35 , V_2 , V_27 , V_36 , 0 ) ;
V_29 = F_28 ( V_2 , V_27 , V_36 ) ;
F_6 ( V_2 ) ;
return V_29 ;
}
static int F_392 ( struct V_34 * V_35 , T_2 V_32 , T_2 V_36 )
{
int V_29 ;
struct V_1 * V_14 ;
struct V_50 * V_53 ;
V_14 = F_76 ( V_35 -> V_37 , V_32 ) ;
if ( ! V_14 )
return - V_531 ;
F_59 ( V_14 , 0 ) ;
V_53 = F_25 ( V_14 ) ;
if ( ! V_53 ) {
F_32 ( ! F_1 ( V_14 ) ) ;
V_29 = F_28 ( V_14 , V_32 , V_36 ) ;
} else {
F_49 ( & V_53 -> V_87 ) ;
if ( V_32 >= V_53 -> V_86 ) {
V_29 = F_17 ( V_35 , V_32 , V_36 ) ;
} else if ( V_32 + V_36 <= V_53 -> V_86 ) {
V_29 = F_28 ( V_14 ,
V_32 , V_36 ) ;
} else {
V_36 = V_53 -> V_86 - V_32 ;
V_29 = F_28 ( V_14 ,
V_32 , V_36 ) ;
if ( V_29 )
goto V_532;
V_36 = ( V_32 + V_36 ) -
V_53 -> V_86 ;
V_32 = V_53 -> V_86 ;
V_29 = F_17 ( V_35 , V_32 , V_36 ) ;
}
V_532:
F_47 ( & V_53 -> V_87 ) ;
F_26 ( V_53 ) ;
}
F_6 ( V_14 ) ;
return V_29 ;
}
int F_393 ( struct V_34 * log ,
struct V_68 * V_533 )
{
struct V_289 * V_97 ;
struct V_70 V_21 ;
int V_534 ;
int V_43 ;
if ( ! F_84 ( log -> V_37 , V_535 ) )
return 0 ;
for ( V_43 = 0 ; V_43 < F_39 ( V_533 ) ; V_43 ++ ) {
F_41 ( V_533 , & V_21 , V_43 ) ;
if ( V_21 . type != V_294 )
continue;
V_97 = F_86 ( V_533 , V_43 , struct V_289 ) ;
V_534 = F_239 ( V_533 , V_97 ) ;
if ( V_534 == V_295 )
continue;
if ( F_240 ( V_533 , V_97 ) == 0 )
continue;
V_21 . V_22 = F_240 ( V_533 , V_97 ) ;
V_21 . V_33 = F_241 ( V_533 , V_97 ) ;
F_392 ( log , V_21 . V_22 , V_21 . V_33 ) ;
}
return 0 ;
}
static int F_394 ( struct V_1 * V_2 ,
T_2 V_36 , int V_510 , int V_536 )
{
struct V_111 * V_96 = V_2 -> V_96 ;
int V_29 = 0 ;
F_11 ( & V_96 -> V_52 ) ;
F_11 ( & V_2 -> V_52 ) ;
if ( V_510 != V_537 ) {
if ( V_2 -> V_306 ) {
V_29 = - V_187 ;
} else {
V_2 -> V_10 += V_36 ;
V_96 -> V_351 += V_36 ;
if ( V_510 == V_538 ) {
F_302 ( V_2 -> V_37 ,
L_10 , V_96 -> V_7 ,
V_36 , 0 ) ;
V_96 -> V_353 -= V_36 ;
}
if ( V_536 )
V_2 -> V_442 += V_36 ;
}
} else {
if ( V_2 -> V_306 )
V_96 -> V_352 += V_36 ;
V_2 -> V_10 -= V_36 ;
V_96 -> V_351 -= V_36 ;
if ( V_536 )
V_2 -> V_442 -= V_36 ;
}
F_13 ( & V_2 -> V_52 ) ;
F_13 ( & V_96 -> V_52 ) ;
return V_29 ;
}
void F_395 ( struct V_117 * V_118 ,
struct V_34 * V_35 )
{
struct V_12 * V_37 = V_35 -> V_37 ;
struct V_50 * V_81 ;
struct V_50 * V_53 ;
struct V_1 * V_2 ;
F_71 ( & V_37 -> V_85 ) ;
F_266 (caching_ctl, next,
&fs_info->caching_block_groups, list) {
V_2 = V_53 -> V_14 ;
if ( F_1 ( V_2 ) ) {
V_2 -> V_106 = ( T_2 ) - 1 ;
F_271 ( & V_53 -> V_99 ) ;
F_26 ( V_53 ) ;
} else {
V_2 -> V_106 = V_53 -> V_86 ;
}
}
if ( V_37 -> V_63 == & V_37 -> V_38 [ 0 ] )
V_37 -> V_63 = & V_37 -> V_38 [ 1 ] ;
else
V_37 -> V_63 = & V_37 -> V_38 [ 0 ] ;
F_73 ( & V_37 -> V_85 ) ;
F_363 ( V_37 ) ;
}
static struct V_539 *
F_396 ( struct V_34 * V_35 , struct V_111 * V_96 ,
T_2 * V_540 )
{
struct V_539 * V_29 = NULL ;
bool V_541 = F_259 ( V_35 , V_542 ) ;
* V_540 = 0 ;
if ( F_321 ( V_96 ) )
return V_29 ;
if ( V_541 )
* V_540 = V_412 ;
if ( V_96 -> V_7 & V_55 ) {
V_29 = & V_35 -> V_37 -> V_543 ;
if ( ! V_541 )
* V_540 = V_544 ;
} else if ( ( V_96 -> V_7 & V_336 ) && V_541 ) {
V_29 = & V_35 -> V_37 -> V_545 ;
}
return V_29 ;
}
static int F_397 ( struct V_34 * V_35 , T_2 V_32 , T_2 V_31 ,
const bool V_546 )
{
struct V_12 * V_37 = V_35 -> V_37 ;
struct V_1 * V_2 = NULL ;
struct V_111 * V_96 ;
struct V_262 * V_263 = & V_37 -> V_266 ;
struct V_539 * V_547 = NULL ;
T_2 V_49 ;
T_2 V_548 = 0 ;
T_2 V_540 = 0 ;
bool V_335 ;
while ( V_32 <= V_31 ) {
V_335 = false ;
if ( ! V_2 ||
V_32 >= V_2 -> V_21 . V_22 + V_2 -> V_21 . V_33 ) {
if ( V_2 )
F_6 ( V_2 ) ;
V_548 = 0 ;
V_2 = F_76 ( V_37 , V_32 ) ;
F_32 ( ! V_2 ) ;
V_547 = F_396 ( V_35 ,
V_2 -> V_96 ,
& V_540 ) ;
V_540 <<= 1 ;
}
V_49 = V_2 -> V_21 . V_22 + V_2 -> V_21 . V_33 - V_32 ;
V_49 = F_330 ( V_49 , V_31 + 1 - V_32 ) ;
if ( V_32 < V_2 -> V_106 ) {
V_49 = F_330 ( V_49 , V_2 -> V_106 - V_32 ) ;
if ( V_546 )
F_31 ( V_2 , V_32 , V_49 ) ;
}
V_32 += V_49 ;
V_548 += V_49 ;
V_96 = V_2 -> V_96 ;
if ( V_547 && V_547 -> V_549 &&
V_548 > V_540 ) {
F_11 ( & V_547 -> V_52 ) ;
V_547 -> V_549 = 0 ;
F_13 ( & V_547 -> V_52 ) ;
}
F_11 ( & V_96 -> V_52 ) ;
F_11 ( & V_2 -> V_52 ) ;
V_2 -> V_9 -= V_49 ;
V_96 -> V_350 -= V_49 ;
V_96 -> V_354 = 0 ;
F_398 ( & V_96 -> V_345 , - V_49 ) ;
if ( V_2 -> V_306 ) {
V_96 -> V_352 += V_49 ;
V_335 = true ;
}
F_13 ( & V_2 -> V_52 ) ;
if ( ! V_335 && V_263 -> V_96 == V_96 ) {
F_11 ( & V_263 -> V_52 ) ;
if ( ! V_263 -> V_116 ) {
V_49 = F_330 ( V_49 , V_263 -> V_61 -
V_263 -> V_10 ) ;
V_263 -> V_10 += V_49 ;
V_96 -> V_353 += V_49 ;
if ( V_263 -> V_10 >= V_263 -> V_61 )
V_263 -> V_116 = 1 ;
}
F_13 ( & V_263 -> V_52 ) ;
}
F_13 ( & V_96 -> V_52 ) ;
}
if ( V_2 )
F_6 ( V_2 ) ;
return 0 ;
}
int F_399 ( struct V_117 * V_118 ,
struct V_34 * V_35 )
{
struct V_12 * V_37 = V_35 -> V_37 ;
struct V_1 * V_14 , * V_317 ;
struct V_112 * V_550 ;
struct V_551 * V_552 ;
T_2 V_32 ;
T_2 V_31 ;
int V_29 ;
if ( V_37 -> V_63 == & V_37 -> V_38 [ 0 ] )
V_552 = & V_37 -> V_38 [ 1 ] ;
else
V_552 = & V_37 -> V_38 [ 0 ] ;
while ( ! V_118 -> V_228 ) {
F_49 ( & V_37 -> V_553 ) ;
V_29 = F_30 ( V_552 , 0 , & V_32 , & V_31 ,
V_64 , NULL ) ;
if ( V_29 ) {
F_47 ( & V_37 -> V_553 ) ;
break;
}
if ( F_259 ( V_35 , V_554 ) )
V_29 = F_153 ( V_35 , V_32 ,
V_31 + 1 - V_32 , NULL ) ;
F_400 ( V_552 , V_32 , V_31 , V_40 ) ;
F_397 ( V_35 , V_32 , V_31 , true ) ;
F_47 ( & V_37 -> V_553 ) ;
F_48 () ;
}
V_550 = & V_118 -> V_135 -> V_550 ;
F_266 (block_group, tmp, deleted_bgs, bg_list) {
T_2 V_555 = 0 ;
V_29 = - V_556 ;
if ( ! V_118 -> V_228 )
V_29 = F_153 ( V_35 ,
V_14 -> V_21 . V_22 ,
V_14 -> V_21 . V_33 ,
& V_555 ) ;
F_271 ( & V_14 -> V_528 ) ;
F_401 ( V_14 ) ;
F_6 ( V_14 ) ;
if ( V_29 ) {
const char * V_557 = F_402 ( V_29 ) ;
F_403 ( V_37 ,
L_15 ,
V_29 , V_557 ) ;
}
}
return 0 ;
}
static void F_404 ( struct V_12 * V_37 , T_2 V_36 ,
T_2 V_141 , T_2 V_153 )
{
struct V_111 * V_96 ;
T_2 V_7 ;
if ( V_141 < V_150 ) {
if ( V_153 == V_558 )
V_7 = V_337 ;
else
V_7 = V_55 ;
} else {
V_7 = V_336 ;
}
V_96 = F_77 ( V_37 , V_7 ) ;
F_32 ( ! V_96 ) ;
F_398 ( & V_96 -> V_345 , V_36 ) ;
}
static int F_165 ( struct V_117 * V_118 ,
struct V_34 * V_35 ,
struct V_219 * V_136 , T_2 V_17 ,
T_2 V_153 , T_2 V_559 ,
T_2 V_560 , int V_168 ,
struct V_189 * V_137 )
{
struct V_70 V_21 ;
struct V_66 * V_67 ;
struct V_12 * V_13 = V_35 -> V_37 ;
struct V_34 * V_65 = V_13 -> V_65 ;
struct V_68 * V_69 ;
struct V_124 * V_125 ;
struct V_172 * V_173 ;
int V_29 ;
int V_193 ;
int V_561 = 0 ;
int V_562 = 0 ;
int V_563 = 1 ;
T_3 V_126 ;
T_2 V_120 ;
T_2 V_27 = V_136 -> V_27 ;
T_2 V_36 = V_136 -> V_36 ;
int V_169 = 0 ;
bool V_182 = F_84 ( V_35 -> V_37 ,
V_129 ) ;
V_67 = F_34 () ;
if ( ! V_67 )
return - V_75 ;
V_67 -> V_78 = V_79 ;
V_67 -> V_220 = 1 ;
V_193 = V_559 >= V_150 ;
F_32 ( ! V_193 && V_168 != 1 ) ;
if ( V_193 )
V_182 = 0 ;
V_29 = F_142 ( V_118 , V_65 , V_67 , & V_173 ,
V_27 , V_36 , V_17 ,
V_153 , V_559 ,
V_560 ) ;
if ( V_29 == 0 ) {
V_561 = V_67 -> V_84 [ 0 ] ;
while ( V_561 >= 0 ) {
F_41 ( V_67 -> V_83 [ 0 ] , & V_21 ,
V_561 ) ;
if ( V_21 . V_22 != V_27 )
break;
if ( V_21 . type == V_80 &&
V_21 . V_33 == V_36 ) {
V_562 = 1 ;
break;
}
if ( V_21 . type == V_88 &&
V_21 . V_33 == V_559 ) {
V_562 = 1 ;
break;
}
if ( V_67 -> V_84 [ 0 ] - V_561 > 5 )
break;
V_561 -- ;
}
#ifdef F_89
V_126 = F_85 ( V_67 -> V_83 [ 0 ] , V_561 ) ;
if ( V_562 && V_126 < sizeof( * V_125 ) )
V_562 = 0 ;
#endif
if ( ! V_562 ) {
F_32 ( V_173 ) ;
V_29 = F_147 ( V_118 , V_65 , V_67 ,
NULL , V_168 ,
V_193 , & V_169 ) ;
if ( V_29 ) {
F_160 ( V_118 , V_65 , V_29 ) ;
goto V_82;
}
F_45 ( V_67 ) ;
V_67 -> V_220 = 1 ;
V_21 . V_22 = V_27 ;
V_21 . type = V_80 ;
V_21 . V_33 = V_36 ;
if ( ! V_193 && V_182 ) {
V_21 . type = V_88 ;
V_21 . V_33 = V_559 ;
}
V_29 = F_38 ( V_118 , V_65 ,
& V_21 , V_67 , - 1 , 1 ) ;
if ( V_29 > 0 && V_182 && V_67 -> V_84 [ 0 ] ) {
V_67 -> V_84 [ 0 ] -- ;
F_41 ( V_67 -> V_83 [ 0 ] , & V_21 ,
V_67 -> V_84 [ 0 ] ) ;
if ( V_21 . V_22 == V_27 &&
V_21 . type == V_80 &&
V_21 . V_33 == V_36 )
V_29 = 0 ;
}
if ( V_29 > 0 && V_182 ) {
V_182 = false ;
V_21 . V_22 = V_27 ;
V_21 . type = V_80 ;
V_21 . V_33 = V_36 ;
F_45 ( V_67 ) ;
V_29 = F_38 ( V_118 , V_65 ,
& V_21 , V_67 , - 1 , 1 ) ;
}
if ( V_29 ) {
F_405 ( V_13 , L_16 ,
V_29 , V_27 ) ;
if ( V_29 > 0 )
F_406 ( V_65 ,
V_67 -> V_83 [ 0 ] ) ;
}
if ( V_29 < 0 ) {
F_160 ( V_118 , V_65 , V_29 ) ;
goto V_82;
}
V_561 = V_67 -> V_84 [ 0 ] ;
}
} else if ( F_8 ( V_29 == - V_161 ) ) {
F_406 ( V_65 , V_67 -> V_83 [ 0 ] ) ;
F_405 ( V_13 ,
L_17 ,
V_27 , V_17 , V_153 , V_559 ,
V_560 ) ;
F_160 ( V_118 , V_65 , V_29 ) ;
goto V_82;
} else {
F_160 ( V_118 , V_65 , V_29 ) ;
goto V_82;
}
V_69 = V_67 -> V_83 [ 0 ] ;
V_126 = F_85 ( V_69 , V_561 ) ;
#ifdef F_89
if ( V_126 < sizeof( * V_125 ) ) {
F_32 ( V_562 || V_561 != V_67 -> V_84 [ 0 ] ) ;
V_29 = F_95 ( V_118 , V_65 , V_67 ,
V_559 , 0 ) ;
if ( V_29 < 0 ) {
F_160 ( V_118 , V_65 , V_29 ) ;
goto V_82;
}
F_45 ( V_67 ) ;
V_67 -> V_220 = 1 ;
V_21 . V_22 = V_27 ;
V_21 . type = V_80 ;
V_21 . V_33 = V_36 ;
V_29 = F_38 ( V_118 , V_65 , & V_21 , V_67 ,
- 1 , 1 ) ;
if ( V_29 ) {
F_405 ( V_13 , L_16 ,
V_29 , V_27 ) ;
F_406 ( V_65 , V_67 -> V_83 [ 0 ] ) ;
}
if ( V_29 < 0 ) {
F_160 ( V_118 , V_65 , V_29 ) ;
goto V_82;
}
V_561 = V_67 -> V_84 [ 0 ] ;
V_69 = V_67 -> V_83 [ 0 ] ;
V_126 = F_85 ( V_69 , V_561 ) ;
}
#endif
F_32 ( V_126 < sizeof( * V_125 ) ) ;
V_125 = F_86 ( V_69 , V_561 ,
struct V_124 ) ;
if ( V_559 < V_150 &&
V_21 . type == V_80 ) {
struct V_145 * V_146 ;
F_32 ( V_126 < sizeof( * V_125 ) + sizeof( * V_146 ) ) ;
V_146 = (struct V_145 * ) ( V_125 + 1 ) ;
F_8 ( V_559 != F_407 ( V_69 , V_146 ) ) ;
}
V_120 = F_87 ( V_69 , V_125 ) ;
if ( V_120 < V_168 ) {
F_405 ( V_13 , L_18
L_19 , V_168 , V_120 , V_27 ) ;
V_29 = - V_531 ;
F_160 ( V_118 , V_65 , V_29 ) ;
goto V_82;
}
V_120 -= V_168 ;
if ( V_120 > 0 ) {
if ( V_137 )
F_138 ( V_137 , V_69 , V_125 ) ;
if ( V_173 ) {
F_32 ( ! V_562 ) ;
} else {
F_98 ( V_69 , V_125 , V_120 ) ;
F_103 ( V_69 ) ;
}
if ( V_562 ) {
V_29 = F_147 ( V_118 , V_65 , V_67 ,
V_173 , V_168 ,
V_193 , & V_169 ) ;
if ( V_29 ) {
F_160 ( V_118 , V_65 , V_29 ) ;
goto V_82;
}
}
F_404 ( V_35 -> V_37 , - V_36 , V_559 ,
V_153 ) ;
} else {
if ( V_562 ) {
F_32 ( V_193 && V_168 !=
F_126 ( V_67 , V_173 ) ) ;
if ( V_173 ) {
F_32 ( V_67 -> V_84 [ 0 ] != V_561 ) ;
} else {
F_32 ( V_67 -> V_84 [ 0 ] != V_561 + 1 ) ;
V_67 -> V_84 [ 0 ] = V_561 ;
V_563 = 2 ;
}
}
V_169 = 1 ;
V_29 = F_408 ( V_118 , V_65 , V_67 , V_67 -> V_84 [ 0 ] ,
V_563 ) ;
if ( V_29 ) {
F_160 ( V_118 , V_65 , V_29 ) ;
goto V_82;
}
F_45 ( V_67 ) ;
if ( V_193 ) {
V_29 = F_177 ( V_118 , V_35 , V_27 , V_36 ) ;
if ( V_29 ) {
F_160 ( V_118 , V_65 , V_29 ) ;
goto V_82;
}
}
V_29 = F_409 ( V_118 , V_35 -> V_37 , V_27 ,
V_36 ) ;
if ( V_29 ) {
F_160 ( V_118 , V_65 , V_29 ) ;
goto V_82;
}
V_29 = F_384 ( V_118 , V_35 , V_27 , V_36 , 0 ) ;
if ( V_29 ) {
F_160 ( V_118 , V_65 , V_29 ) ;
goto V_82;
}
}
F_45 ( V_67 ) ;
V_82:
F_53 ( V_67 ) ;
return V_29 ;
}
static T_1 int F_410 ( struct V_117 * V_118 ,
struct V_34 * V_35 , T_2 V_27 )
{
struct V_121 * V_113 ;
struct V_122 * V_123 ;
int V_29 = 0 ;
V_123 = & V_118 -> V_135 -> V_123 ;
F_11 ( & V_123 -> V_52 ) ;
V_113 = F_92 ( V_118 , V_27 ) ;
if ( ! V_113 )
goto V_564;
F_11 ( & V_113 -> V_52 ) ;
if ( ! F_180 ( & V_113 -> V_232 ) )
goto V_82;
if ( V_113 -> V_137 ) {
if ( ! V_113 -> V_235 )
goto V_82;
F_190 ( V_113 -> V_137 ) ;
V_113 -> V_137 = NULL ;
}
if ( ! F_93 ( & V_113 -> V_87 ) )
goto V_82;
V_113 -> V_136 . V_239 = 0 ;
F_192 ( & V_113 -> V_241 , & V_123 -> V_242 ) ;
F_194 ( & V_123 -> V_243 ) ;
V_123 -> V_240 -- ;
if ( V_113 -> V_237 == 0 )
V_123 -> V_238 -- ;
V_113 -> V_237 = 0 ;
F_13 ( & V_113 -> V_52 ) ;
F_13 ( & V_123 -> V_52 ) ;
F_32 ( V_113 -> V_137 ) ;
if ( V_113 -> V_235 )
V_29 = 1 ;
F_47 ( & V_113 -> V_87 ) ;
F_94 ( & V_113 -> V_136 ) ;
return V_29 ;
V_82:
F_13 ( & V_113 -> V_52 ) ;
V_564:
F_13 ( & V_123 -> V_52 ) ;
return 0 ;
}
void F_411 ( struct V_117 * V_118 ,
struct V_34 * V_35 ,
struct V_68 * V_286 ,
T_2 V_17 , int V_169 )
{
int V_565 = 1 ;
int V_29 ;
if ( V_35 -> V_282 . V_22 != V_217 ) {
V_29 = F_157 ( V_35 -> V_37 , V_118 ,
V_286 -> V_32 , V_286 -> V_49 ,
V_17 , V_35 -> V_282 . V_22 ,
F_237 ( V_286 ) ,
V_226 , NULL ) ;
F_32 ( V_29 ) ;
}
if ( ! V_169 )
return;
if ( F_412 ( V_286 ) == V_118 -> V_308 ) {
struct V_1 * V_2 ;
if ( V_35 -> V_282 . V_22 != V_217 ) {
V_29 = F_410 ( V_118 , V_35 , V_286 -> V_32 ) ;
if ( ! V_29 )
goto V_82;
}
V_2 = F_76 ( V_35 -> V_37 , V_286 -> V_32 ) ;
if ( F_413 ( V_286 , V_566 ) ) {
F_389 ( V_35 , V_2 , V_286 -> V_32 , V_286 -> V_49 , 1 ) ;
F_6 ( V_2 ) ;
goto V_82;
}
F_8 ( F_238 ( V_567 , & V_286 -> V_568 ) ) ;
F_31 ( V_2 , V_286 -> V_32 , V_286 -> V_49 ) ;
F_394 ( V_2 , V_286 -> V_49 , V_537 , 0 ) ;
F_6 ( V_2 ) ;
F_390 ( V_35 , V_286 -> V_32 , V_286 -> V_49 ) ;
V_565 = 0 ;
}
V_82:
if ( V_565 )
F_404 ( V_35 -> V_37 , V_286 -> V_49 ,
F_237 ( V_286 ) ,
V_35 -> V_282 . V_22 ) ;
F_414 ( V_569 , & V_286 -> V_568 ) ;
}
int V_293 ( struct V_117 * V_118 , struct V_34 * V_35 ,
T_2 V_27 , T_2 V_36 , T_2 V_17 , T_2 V_153 ,
T_2 V_141 , T_2 V_33 )
{
int V_29 ;
struct V_12 * V_37 = V_35 -> V_37 ;
if ( F_235 ( V_35 ) )
return 0 ;
F_404 ( V_35 -> V_37 , V_36 , V_141 , V_153 ) ;
if ( V_153 == V_217 ) {
F_8 ( V_141 >= V_150 ) ;
F_173 ( V_35 , V_27 , V_36 , 1 ) ;
V_29 = 0 ;
} else if ( V_141 < V_150 ) {
V_29 = F_157 ( V_37 , V_118 , V_27 ,
V_36 ,
V_17 , V_153 , ( int ) V_141 ,
V_226 , NULL ) ;
} else {
V_29 = F_158 ( V_37 , V_118 , V_27 ,
V_36 ,
V_17 , V_153 , V_141 ,
V_33 , 0 ,
V_226 , NULL ) ;
}
return V_29 ;
}
static T_1 void
F_415 ( struct V_1 * V_2 ,
T_2 V_36 )
{
struct V_50 * V_53 ;
V_53 = F_25 ( V_2 ) ;
if ( ! V_53 )
return;
F_275 ( V_53 -> V_91 , F_1 ( V_2 ) ||
( V_2 -> V_11 -> V_570 >= V_36 ) ) ;
F_26 ( V_53 ) ;
}
static T_1 int
F_416 ( struct V_1 * V_2 )
{
struct V_50 * V_53 ;
int V_29 = 0 ;
V_53 = F_25 ( V_2 ) ;
if ( ! V_53 )
return ( V_2 -> V_3 == V_5 ) ? - V_184 : 0 ;
F_275 ( V_53 -> V_91 , F_1 ( V_2 ) ) ;
if ( V_2 -> V_3 == V_5 )
V_29 = - V_184 ;
F_26 ( V_53 ) ;
return V_29 ;
}
int F_417 ( T_2 V_7 )
{
if ( V_7 & V_342 )
return V_571 ;
else if ( V_7 & V_341 )
return V_572 ;
else if ( V_7 & V_340 )
return V_573 ;
else if ( V_7 & V_389 )
return V_574 ;
else if ( V_7 & V_388 )
return V_575 ;
else if ( V_7 & V_387 )
return V_576 ;
return V_577 ;
}
int F_418 ( struct V_1 * V_2 )
{
return F_417 ( V_2 -> V_7 ) ;
}
static const char * F_419 ( enum V_578 type )
{
if ( type >= V_347 )
return NULL ;
return V_579 [ type ] ;
}
static inline void
F_420 ( struct V_1 * V_2 ,
int V_536 )
{
if ( V_536 )
F_50 ( & V_2 -> V_580 ) ;
}
static inline void
F_421 ( struct V_1 * V_2 ,
int V_536 )
{
F_4 ( V_2 ) ;
if ( V_536 )
F_50 ( & V_2 -> V_580 ) ;
}
static struct V_1 *
F_422 ( struct V_1 * V_14 ,
struct V_539 * V_547 ,
int V_536 )
{
struct V_1 * V_581 ;
bool V_582 = false ;
V_164:
F_11 ( & V_547 -> V_583 ) ;
if ( V_582 ) {
if ( V_581 == V_547 -> V_14 )
return V_581 ;
F_46 ( & V_581 -> V_580 ) ;
F_6 ( V_581 ) ;
}
V_581 = V_547 -> V_14 ;
if ( ! V_581 )
return NULL ;
if ( V_581 == V_14 )
return V_581 ;
F_4 ( V_581 ) ;
if ( ! V_536 )
return V_581 ;
if ( F_325 ( & V_581 -> V_580 ) )
return V_581 ;
F_13 ( & V_547 -> V_583 ) ;
F_50 ( & V_581 -> V_580 ) ;
V_582 = true ;
goto V_164;
}
static inline void
F_423 ( struct V_1 * V_2 ,
int V_536 )
{
if ( V_536 )
F_46 ( & V_2 -> V_580 ) ;
F_6 ( V_2 ) ;
}
static T_1 int F_424 ( struct V_34 * V_584 ,
T_2 V_36 , T_2 V_585 ,
T_2 V_586 , struct V_70 * V_223 ,
T_2 V_7 , int V_536 )
{
int V_29 = 0 ;
struct V_34 * V_35 = V_584 -> V_37 -> V_65 ;
struct V_539 * V_587 = NULL ;
struct V_1 * V_14 = NULL ;
T_2 V_530 = 0 ;
T_2 V_354 = 0 ;
T_2 V_540 = 0 ;
struct V_111 * V_96 ;
int V_588 = 0 ;
int V_589 = F_417 ( V_7 ) ;
int V_590 = ( V_7 & V_336 ) ?
V_591 : V_538 ;
bool V_592 = false ;
bool V_593 = false ;
bool V_594 = true ;
bool V_595 = false ;
bool V_596 = false ;
bool V_597 = false ;
F_8 ( V_36 < V_35 -> V_57 ) ;
V_223 -> type = V_80 ;
V_223 -> V_22 = 0 ;
V_223 -> V_33 = 0 ;
F_425 ( V_584 , V_36 , V_585 , V_7 ) ;
V_96 = F_77 ( V_35 -> V_37 , V_7 ) ;
if ( ! V_96 ) {
F_405 ( V_35 -> V_37 , L_20 , V_7 ) ;
return - V_314 ;
}
if ( F_346 ( V_96 -> V_354 ) ) {
F_11 ( & V_96 -> V_52 ) ;
if ( V_96 -> V_354 &&
V_36 > V_96 -> V_354 ) {
V_223 -> V_33 = V_96 -> V_354 ;
F_13 ( & V_96 -> V_52 ) ;
return - V_314 ;
} else if ( V_96 -> V_354 ) {
V_594 = false ;
}
F_13 ( & V_96 -> V_52 ) ;
}
V_587 = F_396 ( V_584 , V_96 , & V_540 ) ;
if ( V_587 ) {
F_11 ( & V_587 -> V_52 ) ;
if ( V_587 -> V_14 )
V_586 = V_587 -> V_598 ;
if ( V_587 -> V_549 ) {
V_586 = V_587 -> V_598 ;
V_594 = false ;
}
F_13 ( & V_587 -> V_52 ) ;
}
V_530 = F_426 ( V_530 , V_26 ( V_35 , 0 ) ) ;
V_530 = F_426 ( V_530 , V_586 ) ;
if ( V_530 == V_586 ) {
V_14 = F_76 ( V_35 -> V_37 ,
V_530 ) ;
if ( V_14 && F_3 ( V_14 , V_7 ) &&
V_14 -> V_3 != V_103 ) {
F_50 ( & V_96 -> V_349 ) ;
if ( F_180 ( & V_14 -> V_99 ) ||
V_14 -> V_306 ) {
F_6 ( V_14 ) ;
F_46 ( & V_96 -> V_349 ) ;
} else {
V_589 = F_418 ( V_14 ) ;
F_420 ( V_14 , V_536 ) ;
goto V_599;
}
} else if ( V_14 ) {
F_6 ( V_14 ) ;
}
}
V_600:
V_595 = false ;
if ( V_589 == 0 || V_589 == F_417 ( V_7 ) )
V_597 = true ;
F_50 ( & V_96 -> V_349 ) ;
F_181 (block_group, &space_info->block_groups[index],
list) {
T_2 V_33 ;
int V_3 ;
F_421 ( V_14 , V_536 ) ;
V_530 = V_14 -> V_21 . V_22 ;
if ( ! F_3 ( V_14 , V_7 ) ) {
T_2 V_601 = V_340 |
V_341 |
V_388 |
V_387 |
V_342 ;
if ( ( V_7 & V_601 ) && ! ( V_14 -> V_7 & V_601 ) )
goto V_588;
}
V_599:
V_3 = F_1 ( V_14 ) ;
if ( F_346 ( ! V_3 ) ) {
V_595 = true ;
V_29 = F_59 ( V_14 , 0 ) ;
F_32 ( V_29 < 0 ) ;
V_29 = 0 ;
}
if ( F_346 ( V_14 -> V_3 == V_5 ) )
goto V_588;
if ( F_346 ( V_14 -> V_306 ) )
goto V_588;
if ( V_587 && V_594 ) {
struct V_1 * V_602 ;
unsigned long V_603 ;
V_602 = F_422 ( V_14 ,
V_587 ,
V_536 ) ;
if ( ! V_602 )
goto V_604;
if ( V_602 != V_14 &&
( V_602 -> V_306 ||
! F_3 ( V_602 , V_7 ) ) )
goto V_605;
V_33 = F_427 ( V_602 ,
V_587 ,
V_36 ,
V_602 -> V_21 . V_22 ,
& V_354 ) ;
if ( V_33 ) {
F_13 ( & V_587 -> V_583 ) ;
F_428 ( V_35 ,
V_602 ,
V_530 , V_36 ) ;
if ( V_602 != V_14 ) {
F_423 ( V_14 ,
V_536 ) ;
V_14 = V_602 ;
}
goto V_606;
}
F_8 ( V_587 -> V_14 != V_602 ) ;
V_605:
if ( V_588 >= V_607 &&
V_602 != V_14 ) {
F_13 ( & V_587 -> V_583 ) ;
F_423 ( V_602 ,
V_536 ) ;
goto V_608;
}
F_429 ( NULL , V_587 ) ;
if ( V_602 != V_14 )
F_423 ( V_602 ,
V_536 ) ;
V_604:
if ( V_588 >= V_607 ) {
F_13 ( & V_587 -> V_583 ) ;
goto V_608;
}
V_603 = F_35 (unsigned long,
empty_cluster + empty_size,
block_group->full_stripe_len) ;
V_29 = F_430 ( V_35 , V_14 ,
V_587 , V_530 ,
V_36 ,
V_603 ) ;
if ( V_29 == 0 ) {
V_33 = F_427 ( V_14 ,
V_587 ,
V_36 ,
V_530 ,
& V_354 ) ;
if ( V_33 ) {
F_13 ( & V_587 -> V_583 ) ;
F_428 ( V_35 ,
V_14 , V_530 ,
V_36 ) ;
goto V_606;
}
} else if ( ! V_3 && V_588 > V_609
&& ! V_592 ) {
F_13 ( & V_587 -> V_583 ) ;
V_592 = true ;
F_415 ( V_14 ,
V_36 + V_540 + V_585 ) ;
goto V_599;
}
F_429 ( NULL , V_587 ) ;
F_13 ( & V_587 -> V_583 ) ;
goto V_588;
}
V_608:
if ( F_346 ( V_587 ) ) {
F_11 ( & V_587 -> V_52 ) ;
V_587 -> V_549 = 1 ;
F_13 ( & V_587 -> V_52 ) ;
}
F_11 ( & V_14 -> V_11 -> V_610 ) ;
if ( V_3 &&
V_14 -> V_11 -> V_570 <
V_36 + V_540 + V_585 ) {
if ( V_14 -> V_11 -> V_570 >
V_354 )
V_354 =
V_14 -> V_11 -> V_570 ;
F_13 ( & V_14 -> V_11 -> V_610 ) ;
goto V_588;
}
F_13 ( & V_14 -> V_11 -> V_610 ) ;
V_33 = F_431 ( V_14 , V_530 ,
V_36 , V_585 ,
& V_354 ) ;
if ( ! V_33 && ! V_593 && ! V_3 &&
V_588 > V_609 ) {
F_415 ( V_14 ,
V_36 + V_585 ) ;
V_593 = true ;
goto V_599;
} else if ( ! V_33 ) {
goto V_588;
}
V_606:
V_530 = F_149 ( V_33 , V_35 -> V_611 ) ;
if ( V_530 + V_36 >
V_14 -> V_21 . V_22 + V_14 -> V_21 . V_33 ) {
F_31 ( V_14 , V_33 , V_36 ) ;
goto V_588;
}
if ( V_33 < V_530 )
F_31 ( V_14 , V_33 ,
V_530 - V_33 ) ;
F_32 ( V_33 > V_530 ) ;
V_29 = F_394 ( V_14 , V_36 ,
V_590 , V_536 ) ;
if ( V_29 == - V_187 ) {
F_31 ( V_14 , V_33 , V_36 ) ;
goto V_588;
}
V_223 -> V_22 = V_530 ;
V_223 -> V_33 = V_36 ;
F_432 ( V_584 , V_14 ,
V_530 , V_36 ) ;
F_423 ( V_14 , V_536 ) ;
break;
V_588:
V_592 = false ;
V_593 = false ;
F_32 ( V_589 != F_418 ( V_14 ) ) ;
F_423 ( V_14 , V_536 ) ;
}
F_46 ( & V_96 -> V_349 ) ;
if ( ( V_588 == V_609 ) && V_595
&& ! V_596 )
V_596 = true ;
if ( ! V_223 -> V_22 && V_588 >= V_612 && V_595 )
goto V_600;
if ( ! V_223 -> V_22 && ++ V_589 < V_347 )
goto V_600;
if ( ! V_223 -> V_22 && V_588 < V_607 ) {
V_589 = 0 ;
if ( V_588 == V_609 ) {
if ( V_596 || ! V_597 )
V_588 = V_612 ;
else
V_588 = V_613 ;
} else {
V_588 ++ ;
}
if ( V_588 == V_613 ) {
struct V_117 * V_118 ;
int V_614 = 0 ;
V_118 = V_396 -> V_397 ;
if ( V_118 )
V_614 = 1 ;
else
V_118 = F_211 ( V_35 ) ;
if ( F_212 ( V_118 ) ) {
V_29 = F_213 ( V_118 ) ;
goto V_82;
}
V_29 = F_297 ( V_118 , V_35 , V_7 ,
V_400 ) ;
if ( V_29 == - V_314 )
V_588 = V_607 ;
if ( V_29 < 0 && V_29 != - V_314 )
F_160 ( V_118 ,
V_35 , V_29 ) ;
else
V_29 = 0 ;
if ( ! V_614 )
F_215 ( V_118 , V_35 ) ;
if ( V_29 )
goto V_82;
}
if ( V_588 == V_607 ) {
if ( V_585 == 0 &&
V_540 == 0 ) {
V_29 = - V_314 ;
goto V_82;
}
V_585 = 0 ;
V_540 = 0 ;
}
goto V_600;
} else if ( ! V_223 -> V_22 ) {
V_29 = - V_314 ;
} else if ( V_223 -> V_22 ) {
if ( ! V_594 && V_587 ) {
F_11 ( & V_587 -> V_52 ) ;
V_587 -> V_598 = V_223 -> V_22 ;
F_13 ( & V_587 -> V_52 ) ;
}
V_29 = 0 ;
}
V_82:
if ( V_29 == - V_314 ) {
F_11 ( & V_96 -> V_52 ) ;
V_96 -> V_354 = V_354 ;
F_13 ( & V_96 -> V_52 ) ;
V_223 -> V_33 = V_354 ;
}
return V_29 ;
}
static void F_318 ( struct V_111 * V_13 , T_2 V_212 ,
int V_615 )
{
struct V_1 * V_2 ;
int V_589 = 0 ;
F_11 ( & V_13 -> V_52 ) ;
F_433 ( V_616 L_21 ,
V_13 -> V_7 ,
V_13 -> V_338 - V_13 -> V_95 - V_13 -> V_350 -
V_13 -> V_351 - V_13 -> V_352 ,
( V_13 -> V_116 ) ? L_22 : L_23 ) ;
F_433 ( V_616 L_24
L_25 ,
V_13 -> V_338 , V_13 -> V_95 , V_13 -> V_350 ,
V_13 -> V_351 , V_13 -> V_353 ,
V_13 -> V_352 ) ;
F_13 ( & V_13 -> V_52 ) ;
if ( ! V_615 )
return;
F_50 ( & V_13 -> V_349 ) ;
V_164:
F_181 (cache, &info->block_groups[index], list) {
F_11 ( & V_2 -> V_52 ) ;
F_433 ( V_616 L_26
L_27
L_28 ,
V_2 -> V_21 . V_22 , V_2 -> V_21 . V_33 ,
F_58 ( & V_2 -> V_97 ) , V_2 -> V_9 ,
V_2 -> V_10 , V_2 -> V_306 ? L_29 : L_22 ) ;
F_434 ( V_2 , V_212 ) ;
F_13 ( & V_2 -> V_52 ) ;
}
if ( ++ V_589 < V_347 )
goto V_164;
F_46 ( & V_13 -> V_349 ) ;
}
int F_435 ( struct V_34 * V_35 ,
T_2 V_36 , T_2 V_617 ,
T_2 V_585 , T_2 V_586 ,
struct V_70 * V_223 , int V_193 , int V_536 )
{
bool V_618 = V_36 == V_617 ;
T_2 V_7 ;
int V_29 ;
V_7 = F_294 ( V_35 , V_193 ) ;
V_164:
F_8 ( V_36 < V_35 -> V_57 ) ;
V_29 = F_424 ( V_35 , V_36 , V_585 , V_586 , V_223 ,
V_7 , V_536 ) ;
if ( V_29 == - V_314 ) {
if ( ! V_618 && V_223 -> V_33 ) {
V_36 = F_330 ( V_36 >> 1 , V_223 -> V_33 ) ;
V_36 = F_150 ( V_36 , V_35 -> V_57 ) ;
V_36 = F_426 ( V_36 , V_617 ) ;
if ( V_36 == V_617 )
V_618 = true ;
goto V_164;
} else if ( F_259 ( V_35 , V_417 ) ) {
struct V_111 * V_406 ;
V_406 = F_77 ( V_35 -> V_37 , V_7 ) ;
F_405 ( V_35 -> V_37 , L_30 ,
V_7 , V_36 ) ;
if ( V_406 )
F_318 ( V_406 , V_36 , 1 ) ;
}
}
return V_29 ;
}
static int F_436 ( struct V_34 * V_35 ,
T_2 V_32 , T_2 V_49 ,
int V_565 , int V_536 )
{
struct V_1 * V_2 ;
int V_29 = 0 ;
V_2 = F_76 ( V_35 -> V_37 , V_32 ) ;
if ( ! V_2 ) {
F_405 ( V_35 -> V_37 , L_31 ,
V_32 ) ;
return - V_314 ;
}
if ( V_565 )
F_389 ( V_35 , V_2 , V_32 , V_49 , 1 ) ;
else {
if ( F_259 ( V_35 , V_554 ) )
V_29 = F_153 ( V_35 , V_32 , V_49 , NULL ) ;
F_31 ( V_2 , V_32 , V_49 ) ;
F_394 ( V_2 , V_49 , V_537 , V_536 ) ;
}
F_6 ( V_2 ) ;
F_390 ( V_35 , V_32 , V_49 ) ;
return V_29 ;
}
int F_437 ( struct V_34 * V_35 ,
T_2 V_32 , T_2 V_49 , int V_536 )
{
return F_436 ( V_35 , V_32 , V_49 , 0 , V_536 ) ;
}
int F_438 ( struct V_34 * V_35 ,
T_2 V_32 , T_2 V_49 )
{
return F_436 ( V_35 , V_32 , V_49 , 1 , 0 ) ;
}
static int F_164 ( struct V_117 * V_118 ,
struct V_34 * V_35 ,
T_2 V_17 , T_2 V_153 ,
T_2 V_7 , T_2 V_141 , T_2 V_33 ,
struct V_70 * V_223 , int V_140 )
{
int V_29 ;
struct V_12 * V_37 = V_35 -> V_37 ;
struct V_124 * V_619 ;
struct V_172 * V_173 ;
struct V_66 * V_67 ;
struct V_68 * V_69 ;
int type ;
T_3 V_61 ;
if ( V_17 > 0 )
type = V_162 ;
else
type = V_163 ;
V_61 = sizeof( * V_619 ) + F_133 ( type ) ;
V_67 = F_34 () ;
if ( ! V_67 )
return - V_75 ;
V_67 -> V_220 = 1 ;
V_29 = F_114 ( V_118 , V_37 -> V_65 , V_67 ,
V_223 , V_61 ) ;
if ( V_29 ) {
F_53 ( V_67 ) ;
return V_29 ;
}
V_69 = V_67 -> V_83 [ 0 ] ;
V_619 = F_86 ( V_69 , V_67 -> V_84 [ 0 ] ,
struct V_124 ) ;
F_98 ( V_69 , V_619 , V_140 ) ;
F_99 ( V_69 , V_619 , V_118 -> V_308 ) ;
F_100 ( V_69 , V_619 ,
V_7 | V_152 ) ;
V_173 = (struct V_172 * ) ( V_619 + 1 ) ;
F_140 ( V_69 , V_173 , type ) ;
if ( V_17 > 0 ) {
struct V_167 * V_158 ;
V_158 = (struct V_167 * ) ( V_173 + 1 ) ;
F_141 ( V_69 , V_173 , V_17 ) ;
F_115 ( V_69 , V_158 , V_140 ) ;
} else {
struct V_157 * V_158 ;
V_158 = (struct V_157 * ) ( & V_173 -> V_33 ) ;
F_117 ( V_69 , V_158 , V_153 ) ;
F_118 ( V_69 , V_158 , V_141 ) ;
F_119 ( V_69 , V_158 , V_33 ) ;
F_120 ( V_69 , V_158 , V_140 ) ;
}
F_103 ( V_67 -> V_83 [ 0 ] ) ;
F_53 ( V_67 ) ;
V_29 = F_439 ( V_118 , V_37 , V_223 -> V_22 ,
V_223 -> V_33 ) ;
if ( V_29 )
return V_29 ;
V_29 = F_384 ( V_118 , V_35 , V_223 -> V_22 , V_223 -> V_33 , 1 ) ;
if ( V_29 ) {
F_405 ( V_37 , L_32 ,
V_223 -> V_22 , V_223 -> V_33 ) ;
F_91 () ;
}
F_440 ( V_35 , V_223 -> V_22 , V_223 -> V_33 ) ;
return V_29 ;
}
static int F_171 ( struct V_117 * V_118 ,
struct V_34 * V_35 ,
T_2 V_17 , T_2 V_153 ,
T_2 V_7 , struct V_620 * V_21 ,
int V_176 , struct V_70 * V_223 )
{
int V_29 ;
struct V_12 * V_37 = V_35 -> V_37 ;
struct V_124 * V_619 ;
struct V_145 * V_621 ;
struct V_172 * V_173 ;
struct V_66 * V_67 ;
struct V_68 * V_69 ;
T_3 V_61 = sizeof( * V_619 ) + sizeof( * V_173 ) ;
T_2 V_36 = V_223 -> V_33 ;
bool V_182 = F_84 ( V_35 -> V_37 ,
V_129 ) ;
if ( ! V_182 )
V_61 += sizeof( * V_621 ) ;
V_67 = F_34 () ;
if ( ! V_67 ) {
F_438 ( V_35 , V_223 -> V_22 ,
V_35 -> V_56 ) ;
return - V_75 ;
}
V_67 -> V_220 = 1 ;
V_29 = F_114 ( V_118 , V_37 -> V_65 , V_67 ,
V_223 , V_61 ) ;
if ( V_29 ) {
F_53 ( V_67 ) ;
F_438 ( V_35 , V_223 -> V_22 ,
V_35 -> V_56 ) ;
return V_29 ;
}
V_69 = V_67 -> V_83 [ 0 ] ;
V_619 = F_86 ( V_69 , V_67 -> V_84 [ 0 ] ,
struct V_124 ) ;
F_98 ( V_69 , V_619 , 1 ) ;
F_99 ( V_69 , V_619 , V_118 -> V_308 ) ;
F_100 ( V_69 , V_619 ,
V_7 | V_151 ) ;
if ( V_182 ) {
V_173 = (struct V_172 * ) ( V_619 + 1 ) ;
V_36 = V_35 -> V_56 ;
} else {
V_621 = (struct V_145 * ) ( V_619 + 1 ) ;
F_166 ( V_69 , V_621 , V_21 ) ;
F_102 ( V_69 , V_621 , V_176 ) ;
V_173 = (struct V_172 * ) ( V_621 + 1 ) ;
}
if ( V_17 > 0 ) {
F_32 ( ! ( V_7 & V_134 ) ) ;
F_140 ( V_69 , V_173 ,
V_174 ) ;
F_141 ( V_69 , V_173 , V_17 ) ;
} else {
F_140 ( V_69 , V_173 ,
V_175 ) ;
F_141 ( V_69 , V_173 , V_153 ) ;
}
F_103 ( V_69 ) ;
F_53 ( V_67 ) ;
V_29 = F_439 ( V_118 , V_37 , V_223 -> V_22 ,
V_36 ) ;
if ( V_29 )
return V_29 ;
V_29 = F_384 ( V_118 , V_35 , V_223 -> V_22 , V_35 -> V_56 ,
1 ) ;
if ( V_29 ) {
F_405 ( V_37 , L_32 ,
V_223 -> V_22 , V_223 -> V_33 ) ;
F_91 () ;
}
F_440 ( V_35 , V_223 -> V_22 , V_35 -> V_56 ) ;
return V_29 ;
}
int F_441 ( struct V_117 * V_118 ,
struct V_34 * V_35 ,
T_2 V_153 , T_2 V_141 ,
T_2 V_33 , T_2 V_622 ,
struct V_70 * V_223 )
{
int V_29 ;
F_32 ( V_153 == V_217 ) ;
V_29 = F_158 ( V_35 -> V_37 , V_118 , V_223 -> V_22 ,
V_223 -> V_33 , 0 ,
V_153 , V_141 , V_33 ,
V_622 , V_244 ,
NULL ) ;
return V_29 ;
}
int F_442 ( struct V_117 * V_118 ,
struct V_34 * V_35 ,
T_2 V_153 , T_2 V_141 , T_2 V_33 ,
struct V_70 * V_223 )
{
int V_29 ;
struct V_1 * V_14 ;
if ( ! F_84 ( V_35 -> V_37 , V_535 ) ) {
V_29 = F_392 ( V_35 , V_223 -> V_22 , V_223 -> V_33 ) ;
if ( V_29 )
return V_29 ;
}
V_14 = F_76 ( V_35 -> V_37 , V_223 -> V_22 ) ;
if ( ! V_14 )
return - V_531 ;
V_29 = F_394 ( V_14 , V_223 -> V_33 ,
V_591 , 0 ) ;
F_32 ( V_29 ) ;
V_29 = F_164 ( V_118 , V_35 , 0 , V_153 ,
0 , V_141 , V_33 , V_223 , 1 ) ;
F_6 ( V_14 ) ;
return V_29 ;
}
static struct V_68 *
F_443 ( struct V_117 * V_118 , struct V_34 * V_35 ,
T_2 V_27 , int V_176 )
{
struct V_68 * V_286 ;
V_286 = F_444 ( V_35 , V_27 ) ;
if ( ! V_286 )
return F_445 ( - V_75 ) ;
F_446 ( V_286 , V_118 -> V_308 ) ;
F_447 ( V_35 -> V_282 . V_22 , V_286 , V_176 ) ;
F_448 ( V_286 ) ;
F_449 ( V_118 , V_35 -> V_37 , V_286 ) ;
F_414 ( V_623 , & V_286 -> V_568 ) ;
F_450 ( V_286 ) ;
F_451 ( V_286 ) ;
if ( V_35 -> V_282 . V_22 == V_217 ) {
V_286 -> V_624 = V_35 -> V_625 % 2 ;
if ( V_286 -> V_624 == 0 )
F_388 ( & V_35 -> V_626 , V_286 -> V_32 ,
V_286 -> V_32 + V_286 -> V_49 - 1 , V_40 ) ;
else
F_452 ( & V_35 -> V_626 , V_286 -> V_32 ,
V_286 -> V_32 + V_286 -> V_49 - 1 , V_40 ) ;
} else {
V_286 -> V_624 = - 1 ;
F_388 ( & V_118 -> V_135 -> V_627 , V_286 -> V_32 ,
V_286 -> V_32 + V_286 -> V_49 - 1 , V_40 ) ;
}
V_118 -> V_628 ++ ;
return V_286 ;
}
static struct V_262 *
F_453 ( struct V_117 * V_118 ,
struct V_34 * V_35 , T_3 V_629 )
{
struct V_262 * V_441 ;
struct V_262 * V_263 = & V_35 -> V_37 -> V_266 ;
int V_29 ;
bool V_630 = false ;
V_441 = F_349 ( V_118 , V_35 ) ;
if ( F_346 ( V_441 -> V_61 == 0 ) )
goto V_631;
V_164:
V_29 = F_347 ( V_441 , V_629 ) ;
if ( ! V_29 )
return V_441 ;
if ( V_441 -> V_632 )
return F_445 ( V_29 ) ;
if ( V_441 -> type == V_633 && ! V_630 ) {
V_630 = true ;
F_363 ( V_35 -> V_37 ) ;
goto V_164;
}
if ( F_259 ( V_35 , V_417 ) ) {
static F_454 ( V_634 ,
V_635 * 10 ,
1 ) ;
if ( F_455 ( & V_634 ) )
F_456 ( 1 , V_636
L_33 , V_29 ) ;
}
V_631:
V_29 = F_342 ( V_35 , V_441 , V_629 ,
V_419 ) ;
if ( ! V_29 )
return V_441 ;
if ( V_441 -> type != V_633 &&
V_441 -> V_96 == V_263 -> V_96 ) {
V_29 = F_347 ( V_263 , V_629 ) ;
if ( ! V_29 )
return V_263 ;
}
return F_445 ( V_29 ) ;
}
static void F_457 ( struct V_12 * V_37 ,
struct V_262 * V_441 , T_3 V_629 )
{
F_350 ( V_441 , V_629 , 0 ) ;
F_352 ( V_37 , V_441 , NULL , 0 ) ;
}
struct V_68 * F_458 ( struct V_117 * V_118 ,
struct V_34 * V_35 ,
T_2 V_17 , T_2 V_153 ,
struct V_620 * V_21 , int V_176 ,
T_2 V_637 , T_2 V_585 )
{
struct V_70 V_223 ;
struct V_262 * V_441 ;
struct V_68 * V_286 ;
struct V_189 * V_137 ;
T_2 V_7 = 0 ;
int V_29 ;
T_3 V_629 = V_35 -> V_56 ;
bool V_182 = F_84 ( V_35 -> V_37 ,
V_129 ) ;
if ( F_235 ( V_35 ) ) {
V_286 = F_443 ( V_118 , V_35 , V_35 -> V_638 ,
V_176 ) ;
if ( ! F_212 ( V_286 ) )
V_35 -> V_638 += V_629 ;
return V_286 ;
}
V_441 = F_453 ( V_118 , V_35 , V_629 ) ;
if ( F_212 ( V_441 ) )
return F_459 ( V_441 ) ;
V_29 = F_435 ( V_35 , V_629 , V_629 ,
V_585 , V_637 , & V_223 , 0 , 0 ) ;
if ( V_29 )
goto V_639;
V_286 = F_443 ( V_118 , V_35 , V_223 . V_22 , V_176 ) ;
if ( F_212 ( V_286 ) ) {
V_29 = F_213 ( V_286 ) ;
goto V_640;
}
if ( V_153 == V_641 ) {
if ( V_17 == 0 )
V_17 = V_223 . V_22 ;
V_7 |= V_134 ;
} else
F_32 ( V_17 > 0 ) ;
if ( V_153 != V_217 ) {
V_137 = F_226 () ;
if ( ! V_137 ) {
V_29 = - V_75 ;
goto V_642;
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
V_29 = F_157 ( V_35 -> V_37 , V_118 ,
V_223 . V_22 , V_223 . V_33 ,
V_17 , V_153 , V_176 ,
V_244 ,
V_137 ) ;
if ( V_29 )
goto V_643;
}
return V_286 ;
V_643:
F_190 ( V_137 ) ;
V_642:
F_460 ( V_286 ) ;
V_640:
F_437 ( V_35 , V_223 . V_22 , V_223 . V_33 , 0 ) ;
V_639:
F_457 ( V_35 -> V_37 , V_441 , V_629 ) ;
return F_445 ( V_29 ) ;
}
static T_1 void F_461 ( struct V_117 * V_118 ,
struct V_34 * V_35 ,
struct V_644 * V_645 ,
struct V_66 * V_67 )
{
T_2 V_27 ;
T_2 V_311 ;
T_2 V_120 ;
T_2 V_7 ;
T_3 V_73 ;
T_3 V_629 ;
struct V_70 V_21 ;
struct V_68 * V_533 ;
int V_29 ;
int V_646 ;
int V_647 = 0 ;
if ( V_67 -> V_84 [ V_645 -> V_176 ] < V_645 -> V_648 ) {
V_645 -> V_649 = V_645 -> V_649 * 2 / 3 ;
V_645 -> V_649 = F_426 ( V_645 -> V_649 , 2 ) ;
} else {
V_645 -> V_649 = V_645 -> V_649 * 3 / 2 ;
V_645 -> V_649 = F_24 ( int , V_645 -> V_649 ,
F_462 ( V_35 ) ) ;
}
V_533 = V_67 -> V_83 [ V_645 -> V_176 ] ;
V_73 = F_39 ( V_533 ) ;
V_629 = V_35 -> V_56 ;
for ( V_646 = V_67 -> V_84 [ V_645 -> V_176 ] ; V_646 < V_73 ; V_646 ++ ) {
if ( V_647 >= V_645 -> V_649 )
break;
F_48 () ;
V_27 = F_243 ( V_533 , V_646 ) ;
V_311 = F_463 ( V_533 , V_646 ) ;
if ( V_646 == V_67 -> V_84 [ V_645 -> V_176 ] )
goto V_78;
if ( V_645 -> V_650 == V_651 &&
V_311 <= V_35 -> V_282 . V_33 )
continue;
V_29 = F_83 ( V_118 , V_35 , V_27 ,
V_645 -> V_176 - 1 , 1 , & V_120 ,
& V_7 ) ;
if ( V_29 < 0 )
continue;
F_32 ( V_120 == 0 ) ;
if ( V_645 -> V_650 == V_652 ) {
if ( V_120 == 1 )
goto V_78;
if ( V_645 -> V_176 == 1 &&
( V_7 & V_134 ) )
continue;
if ( ! V_645 -> V_653 ||
V_311 <= V_35 -> V_282 . V_33 )
continue;
F_131 ( V_533 , & V_21 , V_646 ) ;
V_29 = F_464 ( & V_21 ,
& V_645 -> V_654 ) ;
if ( V_29 < 0 )
continue;
} else {
if ( V_645 -> V_176 == 1 &&
( V_7 & V_134 ) )
continue;
}
V_78:
F_465 ( V_35 , V_27 ) ;
V_647 ++ ;
}
V_645 -> V_648 = V_646 ;
}
static int F_466 ( struct V_117 * V_118 ,
struct V_34 * V_35 , T_2 V_27 ,
T_2 V_36 )
{
struct V_655 * V_656 ;
struct V_122 * V_123 ;
V_656 = F_218 ( sizeof( * V_656 ) , V_40 ) ;
if ( ! V_656 )
return - V_75 ;
V_656 -> V_27 = V_27 ;
V_656 -> V_36 = V_36 ;
V_656 -> V_657 = NULL ;
V_123 = & V_118 -> V_135 -> V_123 ;
F_11 ( & V_123 -> V_52 ) ;
if ( F_467 ( V_123 , V_656 ) )
F_9 ( V_656 ) ;
F_13 ( & V_123 -> V_52 ) ;
return 0 ;
}
static int F_468 ( struct V_117 * V_118 ,
struct V_34 * V_35 ,
struct V_68 * V_533 )
{
int V_44 = F_39 ( V_533 ) ;
int V_43 , V_658 , V_29 ;
struct V_70 V_21 ;
struct V_289 * V_290 ;
T_2 V_27 , V_36 ;
if ( ! V_35 -> V_37 -> V_501 )
return 0 ;
for ( V_43 = 0 ; V_43 < V_44 ; V_43 ++ ) {
F_41 ( V_533 , & V_21 , V_43 ) ;
if ( V_21 . type != V_294 )
continue;
V_290 = F_86 ( V_533 , V_43 , struct V_289 ) ;
V_658 = F_239 ( V_533 , V_290 ) ;
if ( V_658 == V_295 )
continue;
V_27 = F_240 ( V_533 , V_290 ) ;
if ( ! V_27 )
continue;
V_36 = F_241 ( V_533 , V_290 ) ;
V_29 = F_466 ( V_118 , V_35 , V_27 , V_36 ) ;
if ( V_29 )
return V_29 ;
}
return 0 ;
}
static int F_469 ( struct V_34 * V_35 ,
struct V_66 * V_67 , int V_659 )
{
int V_176 = 0 ;
int V_44 , V_646 ;
struct V_68 * V_533 ;
if ( V_659 == 0 )
return 1 ;
while ( V_176 <= V_659 ) {
V_533 = V_67 -> V_83 [ V_176 ] ;
V_44 = F_39 ( V_533 ) ;
V_67 -> V_84 [ V_176 ] ++ ;
V_646 = V_67 -> V_84 [ V_176 ] ;
if ( V_646 >= V_44 || V_176 == 0 ) {
if ( V_176 != V_659 ) {
F_470 ( V_533 , V_67 -> V_660 [ V_176 ] ) ;
V_67 -> V_660 [ V_176 ] = 0 ;
F_460 ( V_533 ) ;
V_67 -> V_83 [ V_176 ] = NULL ;
V_67 -> V_84 [ V_176 ] = 0 ;
}
} else {
break;
}
V_176 ++ ;
}
V_533 = V_67 -> V_83 [ V_659 ] ;
if ( V_67 -> V_84 [ V_659 ] >= F_39 ( V_533 ) )
return 1 ;
return 0 ;
}
static int F_471 ( struct V_117 * V_118 ,
struct V_34 * V_35 ,
struct V_68 * V_661 ,
T_2 V_662 ,
int V_659 )
{
int V_29 = 0 ;
int V_176 ;
struct V_68 * V_533 = V_661 ;
struct V_66 * V_67 = NULL ;
F_32 ( V_659 < 0 || V_659 > V_177 ) ;
F_32 ( V_661 == NULL ) ;
if ( ! V_35 -> V_37 -> V_501 )
return 0 ;
if ( ! F_472 ( V_661 ) ) {
V_29 = F_473 ( V_661 , V_662 ) ;
if ( V_29 )
goto V_82;
}
if ( V_659 == 0 ) {
V_29 = F_468 ( V_118 , V_35 , V_661 ) ;
goto V_82;
}
V_67 = F_34 () ;
if ( ! V_67 )
return - V_75 ;
F_474 ( V_661 ) ;
V_67 -> V_83 [ V_659 ] = V_661 ;
V_67 -> V_84 [ V_659 ] = 0 ;
V_67 -> V_660 [ V_659 ] = 0 ;
V_663:
V_176 = V_659 ;
while ( V_176 >= 0 ) {
if ( V_67 -> V_83 [ V_176 ] == NULL ) {
int V_664 ;
T_2 V_665 ;
T_2 V_666 ;
V_533 = V_67 -> V_83 [ V_176 + 1 ] ;
V_664 = V_67 -> V_84 [ V_176 + 1 ] ;
V_666 = F_243 ( V_533 , V_664 ) ;
V_665 = F_463 ( V_533 , V_664 ) ;
V_533 = F_475 ( V_35 , V_666 , V_665 ) ;
if ( F_212 ( V_533 ) ) {
V_29 = F_213 ( V_533 ) ;
goto V_82;
} else if ( ! F_472 ( V_533 ) ) {
F_460 ( V_533 ) ;
V_29 = - V_184 ;
goto V_82;
}
V_67 -> V_83 [ V_176 ] = V_533 ;
V_67 -> V_84 [ V_176 ] = 0 ;
F_476 ( V_533 ) ;
F_477 ( V_533 , V_667 ) ;
V_67 -> V_660 [ V_176 ] = V_668 ;
V_29 = F_466 ( V_118 , V_35 , V_666 ,
V_35 -> V_56 ) ;
if ( V_29 )
goto V_82;
}
if ( V_176 == 0 ) {
V_29 = F_468 ( V_118 , V_35 , V_67 -> V_83 [ V_176 ] ) ;
if ( V_29 )
goto V_82;
V_29 = F_469 ( V_35 , V_67 , V_659 ) ;
if ( V_29 )
break;
goto V_663;
}
V_176 -- ;
}
V_29 = 0 ;
V_82:
F_53 ( V_67 ) ;
return V_29 ;
}
static T_1 int F_478 ( struct V_117 * V_118 ,
struct V_34 * V_35 ,
struct V_66 * V_67 ,
struct V_644 * V_645 , int V_669 )
{
int V_176 = V_645 -> V_176 ;
struct V_68 * V_533 = V_67 -> V_83 [ V_176 ] ;
T_2 V_670 = V_134 ;
int V_29 ;
if ( V_645 -> V_650 == V_651 &&
F_236 ( V_533 ) != V_35 -> V_282 . V_22 )
return 1 ;
if ( V_669 &&
( ( V_645 -> V_650 == V_652 && V_645 -> V_120 [ V_176 ] != 1 ) ||
( V_645 -> V_650 == V_651 && ! ( V_645 -> V_7 [ V_176 ] & V_670 ) ) ) ) {
F_32 ( ! V_67 -> V_660 [ V_176 ] ) ;
V_29 = F_83 ( V_118 , V_35 ,
V_533 -> V_32 , V_176 , 1 ,
& V_645 -> V_120 [ V_176 ] ,
& V_645 -> V_7 [ V_176 ] ) ;
F_32 ( V_29 == - V_75 ) ;
if ( V_29 )
return V_29 ;
F_32 ( V_645 -> V_120 [ V_176 ] == 0 ) ;
}
if ( V_645 -> V_650 == V_652 ) {
if ( V_645 -> V_120 [ V_176 ] > 1 )
return 1 ;
if ( V_67 -> V_660 [ V_176 ] && ! V_645 -> V_183 ) {
F_470 ( V_533 , V_67 -> V_660 [ V_176 ] ) ;
V_67 -> V_660 [ V_176 ] = 0 ;
}
return 0 ;
}
if ( ! ( V_645 -> V_7 [ V_176 ] & V_670 ) ) {
F_32 ( ! V_67 -> V_660 [ V_176 ] ) ;
V_29 = F_244 ( V_118 , V_35 , V_533 , 1 ) ;
F_32 ( V_29 ) ;
V_29 = F_245 ( V_118 , V_35 , V_533 , 0 ) ;
F_32 ( V_29 ) ;
V_29 = F_225 ( V_118 , V_35 , V_533 -> V_32 ,
V_533 -> V_49 , V_670 ,
F_237 ( V_533 ) , 0 ) ;
F_32 ( V_29 ) ;
V_645 -> V_7 [ V_176 ] |= V_670 ;
}
if ( V_67 -> V_660 [ V_176 ] && V_176 > 0 ) {
F_470 ( V_533 , V_67 -> V_660 [ V_176 ] ) ;
V_67 -> V_660 [ V_176 ] = 0 ;
}
return 0 ;
}
static T_1 int F_479 ( struct V_117 * V_118 ,
struct V_34 * V_35 ,
struct V_66 * V_67 ,
struct V_644 * V_645 , int * V_669 )
{
T_2 V_27 ;
T_2 V_311 ;
T_2 V_17 ;
T_3 V_629 ;
struct V_70 V_21 ;
struct V_68 * V_81 ;
int V_176 = V_645 -> V_176 ;
int V_78 = 0 ;
int V_29 = 0 ;
bool V_671 = false ;
V_311 = F_463 ( V_67 -> V_83 [ V_176 ] ,
V_67 -> V_84 [ V_176 ] ) ;
if ( V_645 -> V_650 == V_651 &&
V_311 <= V_35 -> V_282 . V_33 ) {
* V_669 = 1 ;
return 1 ;
}
V_27 = F_243 ( V_67 -> V_83 [ V_176 ] , V_67 -> V_84 [ V_176 ] ) ;
V_629 = V_35 -> V_56 ;
V_81 = F_480 ( V_35 -> V_37 , V_27 ) ;
if ( ! V_81 ) {
V_81 = F_444 ( V_35 , V_27 ) ;
if ( ! V_81 )
return - V_75 ;
F_447 ( V_35 -> V_282 . V_22 , V_81 ,
V_176 - 1 ) ;
V_78 = 1 ;
}
F_448 ( V_81 ) ;
F_450 ( V_81 ) ;
V_29 = F_83 ( V_118 , V_35 , V_27 , V_176 - 1 , 1 ,
& V_645 -> V_120 [ V_176 - 1 ] ,
& V_645 -> V_7 [ V_176 - 1 ] ) ;
if ( V_29 < 0 ) {
F_481 ( V_81 ) ;
return V_29 ;
}
if ( F_346 ( V_645 -> V_120 [ V_176 - 1 ] == 0 ) ) {
F_405 ( V_35 -> V_37 , L_34 ) ;
F_91 () ;
}
* V_669 = 0 ;
if ( V_645 -> V_650 == V_652 ) {
if ( V_645 -> V_120 [ V_176 - 1 ] > 1 ) {
V_671 = true ;
if ( V_176 == 1 &&
( V_645 -> V_7 [ 0 ] & V_134 ) )
goto V_672;
if ( ! V_645 -> V_653 ||
V_311 <= V_35 -> V_282 . V_33 )
goto V_672;
F_131 ( V_67 -> V_83 [ V_176 ] , & V_21 ,
V_67 -> V_84 [ V_176 ] ) ;
V_29 = F_464 ( & V_21 , & V_645 -> V_654 ) ;
if ( V_29 < 0 )
goto V_672;
V_645 -> V_650 = V_651 ;
V_645 -> V_673 = V_176 - 1 ;
}
} else {
if ( V_176 == 1 &&
( V_645 -> V_7 [ 0 ] & V_134 ) )
goto V_672;
}
if ( ! F_482 ( V_81 , V_311 , 0 ) ) {
F_481 ( V_81 ) ;
F_460 ( V_81 ) ;
V_81 = NULL ;
* V_669 = 1 ;
}
if ( ! V_81 ) {
if ( V_78 && V_176 == 1 )
F_461 ( V_118 , V_35 , V_645 , V_67 ) ;
V_81 = F_475 ( V_35 , V_27 , V_311 ) ;
if ( F_212 ( V_81 ) ) {
return F_213 ( V_81 ) ;
} else if ( ! F_472 ( V_81 ) ) {
F_460 ( V_81 ) ;
return - V_184 ;
}
F_448 ( V_81 ) ;
F_450 ( V_81 ) ;
}
V_176 -- ;
F_32 ( V_176 != F_237 ( V_81 ) ) ;
V_67 -> V_83 [ V_176 ] = V_81 ;
V_67 -> V_84 [ V_176 ] = 0 ;
V_67 -> V_660 [ V_176 ] = V_674 ;
V_645 -> V_176 = V_176 ;
if ( V_645 -> V_176 == 1 )
V_645 -> V_648 = 0 ;
return 0 ;
V_672:
V_645 -> V_120 [ V_176 - 1 ] = 0 ;
V_645 -> V_7 [ V_176 - 1 ] = 0 ;
if ( V_645 -> V_650 == V_652 ) {
if ( V_645 -> V_7 [ V_176 ] & V_134 ) {
V_17 = V_67 -> V_83 [ V_176 ] -> V_32 ;
} else {
F_32 ( V_35 -> V_282 . V_22 !=
F_236 ( V_67 -> V_83 [ V_176 ] ) ) ;
V_17 = 0 ;
}
if ( V_671 ) {
V_29 = F_471 ( V_118 , V_35 , V_81 ,
V_311 , V_176 - 1 ) ;
if ( V_29 ) {
F_483 ( V_35 -> V_37 ,
L_35
L_36
L_37 ,
V_29 ) ;
}
}
V_29 = V_293 ( V_118 , V_35 , V_27 , V_629 , V_17 ,
V_35 -> V_282 . V_22 , V_176 - 1 , 0 ) ;
F_32 ( V_29 ) ;
}
F_481 ( V_81 ) ;
F_460 ( V_81 ) ;
* V_669 = 1 ;
return 1 ;
}
static T_1 int F_484 ( struct V_117 * V_118 ,
struct V_34 * V_35 ,
struct V_66 * V_67 ,
struct V_644 * V_645 )
{
int V_29 ;
int V_176 = V_645 -> V_176 ;
struct V_68 * V_533 = V_67 -> V_83 [ V_176 ] ;
T_2 V_17 = 0 ;
if ( V_645 -> V_650 == V_651 ) {
F_32 ( V_645 -> V_673 < V_176 ) ;
if ( V_176 < V_645 -> V_673 )
goto V_82;
V_29 = F_42 ( V_67 , V_176 + 1 , & V_645 -> V_654 ) ;
if ( V_29 > 0 )
V_645 -> V_653 = 0 ;
V_645 -> V_650 = V_652 ;
V_645 -> V_673 = - 1 ;
V_67 -> V_84 [ V_176 ] = 0 ;
if ( ! V_67 -> V_660 [ V_176 ] ) {
F_32 ( V_176 == 0 ) ;
F_448 ( V_533 ) ;
F_450 ( V_533 ) ;
V_67 -> V_660 [ V_176 ] = V_674 ;
V_29 = F_83 ( V_118 , V_35 ,
V_533 -> V_32 , V_176 , 1 ,
& V_645 -> V_120 [ V_176 ] ,
& V_645 -> V_7 [ V_176 ] ) ;
if ( V_29 < 0 ) {
F_470 ( V_533 , V_67 -> V_660 [ V_176 ] ) ;
V_67 -> V_660 [ V_176 ] = 0 ;
return V_29 ;
}
F_32 ( V_645 -> V_120 [ V_176 ] == 0 ) ;
if ( V_645 -> V_120 [ V_176 ] == 1 ) {
F_470 ( V_533 , V_67 -> V_660 [ V_176 ] ) ;
V_67 -> V_660 [ V_176 ] = 0 ;
return 1 ;
}
}
}
F_32 ( V_645 -> V_120 [ V_176 ] > 1 && ! V_67 -> V_660 [ V_176 ] ) ;
if ( V_645 -> V_120 [ V_176 ] == 1 ) {
if ( V_176 == 0 ) {
if ( V_645 -> V_7 [ V_176 ] & V_134 )
V_29 = F_245 ( V_118 , V_35 , V_533 , 1 ) ;
else
V_29 = F_245 ( V_118 , V_35 , V_533 , 0 ) ;
F_32 ( V_29 ) ;
V_29 = F_468 ( V_118 , V_35 , V_533 ) ;
if ( V_29 ) {
F_483 ( V_35 -> V_37 ,
L_38
L_39
L_37 ,
V_29 ) ;
}
}
if ( ! V_67 -> V_660 [ V_176 ] &&
F_412 ( V_533 ) == V_118 -> V_308 ) {
F_448 ( V_533 ) ;
F_450 ( V_533 ) ;
V_67 -> V_660 [ V_176 ] = V_674 ;
}
F_449 ( V_118 , V_35 -> V_37 , V_533 ) ;
}
if ( V_533 == V_35 -> V_136 ) {
if ( V_645 -> V_7 [ V_176 ] & V_134 )
V_17 = V_533 -> V_32 ;
else
F_32 ( V_35 -> V_282 . V_22 !=
F_236 ( V_533 ) ) ;
} else {
if ( V_645 -> V_7 [ V_176 + 1 ] & V_134 )
V_17 = V_67 -> V_83 [ V_176 + 1 ] -> V_32 ;
else
F_32 ( V_35 -> V_282 . V_22 !=
F_236 ( V_67 -> V_83 [ V_176 + 1 ] ) ) ;
}
F_411 ( V_118 , V_35 , V_533 , V_17 , V_645 -> V_120 [ V_176 ] == 1 ) ;
V_82:
V_645 -> V_120 [ V_176 ] = 0 ;
V_645 -> V_7 [ V_176 ] = 0 ;
return 0 ;
}
static T_1 int F_485 ( struct V_117 * V_118 ,
struct V_34 * V_35 ,
struct V_66 * V_67 ,
struct V_644 * V_645 )
{
int V_176 = V_645 -> V_176 ;
int V_669 = 1 ;
int V_29 ;
while ( V_176 >= 0 ) {
V_29 = F_478 ( V_118 , V_35 , V_67 , V_645 , V_669 ) ;
if ( V_29 > 0 )
break;
if ( V_176 == 0 )
break;
if ( V_67 -> V_84 [ V_176 ] >=
F_39 ( V_67 -> V_83 [ V_176 ] ) )
break;
V_29 = F_479 ( V_118 , V_35 , V_67 , V_645 , & V_669 ) ;
if ( V_29 > 0 ) {
V_67 -> V_84 [ V_176 ] ++ ;
continue;
} else if ( V_29 < 0 )
return V_29 ;
V_176 = V_645 -> V_176 ;
}
return 0 ;
}
static T_1 int F_486 ( struct V_117 * V_118 ,
struct V_34 * V_35 ,
struct V_66 * V_67 ,
struct V_644 * V_645 , int V_675 )
{
int V_176 = V_645 -> V_176 ;
int V_29 ;
V_67 -> V_84 [ V_176 ] = F_39 ( V_67 -> V_83 [ V_176 ] ) ;
while ( V_176 < V_675 && V_67 -> V_83 [ V_176 ] ) {
V_645 -> V_176 = V_176 ;
if ( V_67 -> V_84 [ V_176 ] + 1 <
F_39 ( V_67 -> V_83 [ V_176 ] ) ) {
V_67 -> V_84 [ V_176 ] ++ ;
return 0 ;
} else {
V_29 = F_484 ( V_118 , V_35 , V_67 , V_645 ) ;
if ( V_29 > 0 )
return 0 ;
if ( V_67 -> V_660 [ V_176 ] ) {
F_470 ( V_67 -> V_83 [ V_176 ] ,
V_67 -> V_660 [ V_176 ] ) ;
V_67 -> V_660 [ V_176 ] = 0 ;
}
F_460 ( V_67 -> V_83 [ V_176 ] ) ;
V_67 -> V_83 [ V_176 ] = NULL ;
V_176 ++ ;
}
}
return 1 ;
}
int F_487 ( struct V_34 * V_35 ,
struct V_262 * V_441 , int V_653 ,
int V_676 )
{
struct V_66 * V_67 ;
struct V_117 * V_118 ;
struct V_34 * V_89 = V_35 -> V_37 -> V_89 ;
struct V_677 * V_283 = & V_35 -> V_283 ;
struct V_644 * V_645 ;
struct V_70 V_21 ;
int V_160 = 0 ;
int V_29 ;
int V_176 ;
bool V_678 = false ;
F_191 ( V_35 -> V_37 , L_40 , V_35 -> V_22 ) ;
V_67 = F_34 () ;
if ( ! V_67 ) {
V_160 = - V_75 ;
goto V_82;
}
V_645 = F_61 ( sizeof( * V_645 ) , V_40 ) ;
if ( ! V_645 ) {
F_53 ( V_67 ) ;
V_160 = - V_75 ;
goto V_82;
}
V_118 = F_488 ( V_89 , 0 ) ;
if ( F_212 ( V_118 ) ) {
V_160 = F_213 ( V_118 ) ;
goto V_131;
}
if ( V_441 )
V_118 -> V_441 = V_441 ;
if ( F_489 ( & V_283 -> V_679 ) == 0 ) {
V_176 = F_237 ( V_35 -> V_136 ) ;
V_67 -> V_83 [ V_176 ] = F_490 ( V_35 ) ;
F_450 ( V_67 -> V_83 [ V_176 ] ) ;
V_67 -> V_84 [ V_176 ] = 0 ;
V_67 -> V_660 [ V_176 ] = V_674 ;
memset ( & V_645 -> V_654 , 0 ,
sizeof( V_645 -> V_654 ) ) ;
} else {
F_491 ( & V_21 , & V_283 -> V_679 ) ;
memcpy ( & V_645 -> V_654 , & V_21 ,
sizeof( V_645 -> V_654 ) ) ;
V_176 = V_283 -> V_680 ;
F_32 ( V_176 == 0 ) ;
V_67 -> V_681 = V_176 ;
V_29 = F_38 ( NULL , V_35 , & V_21 , V_67 , 0 , 0 ) ;
V_67 -> V_681 = 0 ;
if ( V_29 < 0 ) {
V_160 = V_29 ;
goto V_682;
}
F_8 ( V_29 > 0 ) ;
F_136 ( V_67 , 0 ) ;
V_176 = F_237 ( V_35 -> V_136 ) ;
while ( 1 ) {
F_448 ( V_67 -> V_83 [ V_176 ] ) ;
F_450 ( V_67 -> V_83 [ V_176 ] ) ;
V_67 -> V_660 [ V_176 ] = V_674 ;
V_29 = F_83 ( V_118 , V_35 ,
V_67 -> V_83 [ V_176 ] -> V_32 ,
V_176 , 1 , & V_645 -> V_120 [ V_176 ] ,
& V_645 -> V_7 [ V_176 ] ) ;
if ( V_29 < 0 ) {
V_160 = V_29 ;
goto V_682;
}
F_32 ( V_645 -> V_120 [ V_176 ] == 0 ) ;
if ( V_176 == V_283 -> V_680 )
break;
F_481 ( V_67 -> V_83 [ V_176 ] ) ;
V_67 -> V_660 [ V_176 ] = 0 ;
F_8 ( V_645 -> V_120 [ V_176 ] != 1 ) ;
V_176 -- ;
}
}
V_645 -> V_176 = V_176 ;
V_645 -> V_673 = - 1 ;
V_645 -> V_650 = V_652 ;
V_645 -> V_653 = V_653 ;
V_645 -> V_183 = 0 ;
V_645 -> V_676 = V_676 ;
V_645 -> V_649 = F_462 ( V_35 ) ;
while ( 1 ) {
V_29 = F_485 ( V_118 , V_35 , V_67 , V_645 ) ;
if ( V_29 < 0 ) {
V_160 = V_29 ;
break;
}
V_29 = F_486 ( V_118 , V_35 , V_67 , V_645 , V_177 ) ;
if ( V_29 < 0 ) {
V_160 = V_29 ;
break;
}
if ( V_29 > 0 ) {
F_32 ( V_645 -> V_650 != V_652 ) ;
break;
}
if ( V_645 -> V_650 == V_652 ) {
V_176 = V_645 -> V_176 ;
F_492 ( V_67 -> V_83 [ V_176 ] ,
& V_283 -> V_679 ,
V_67 -> V_84 [ V_176 ] ) ;
V_283 -> V_680 = V_176 ;
}
F_32 ( V_645 -> V_176 == 0 ) ;
if ( F_493 ( V_118 , V_89 ) ||
( ! V_676 && F_494 ( V_35 ) ) ) {
V_29 = F_495 ( V_118 , V_89 ,
& V_35 -> V_282 ,
V_283 ) ;
if ( V_29 ) {
F_160 ( V_118 , V_89 , V_29 ) ;
V_160 = V_29 ;
goto V_682;
}
F_496 ( V_118 , V_89 ) ;
if ( ! V_676 && F_494 ( V_35 ) ) {
F_497 ( L_41 ) ;
V_160 = - V_187 ;
goto V_131;
}
V_118 = F_488 ( V_89 , 0 ) ;
if ( F_212 ( V_118 ) ) {
V_160 = F_213 ( V_118 ) ;
goto V_131;
}
if ( V_441 )
V_118 -> V_441 = V_441 ;
}
}
F_45 ( V_67 ) ;
if ( V_160 )
goto V_682;
V_29 = F_498 ( V_118 , V_89 , & V_35 -> V_282 ) ;
if ( V_29 ) {
F_160 ( V_118 , V_89 , V_29 ) ;
goto V_682;
}
if ( V_35 -> V_282 . V_22 != V_641 ) {
V_29 = F_499 ( V_89 , & V_35 -> V_282 , V_67 ,
NULL , NULL ) ;
if ( V_29 < 0 ) {
F_160 ( V_118 , V_89 , V_29 ) ;
V_160 = V_29 ;
goto V_682;
} else if ( V_29 > 0 ) {
F_500 ( V_118 , V_89 ,
V_35 -> V_282 . V_22 ) ;
}
}
if ( F_238 ( V_683 , & V_35 -> V_292 ) ) {
F_501 ( V_118 , V_35 ) ;
} else {
F_460 ( V_35 -> V_136 ) ;
F_460 ( V_35 -> V_684 ) ;
F_502 ( V_35 ) ;
}
V_678 = true ;
V_682:
F_496 ( V_118 , V_89 ) ;
V_131:
F_9 ( V_645 ) ;
F_53 ( V_67 ) ;
V_82:
if ( ! V_676 && V_678 == false )
F_503 ( V_35 ) ;
if ( V_160 && V_160 != - V_187 )
F_504 ( V_35 -> V_37 , V_160 , NULL ) ;
return V_160 ;
}
int F_505 ( struct V_117 * V_118 ,
struct V_34 * V_35 ,
struct V_68 * V_136 ,
struct V_68 * V_17 )
{
struct V_66 * V_67 ;
struct V_644 * V_645 ;
int V_176 ;
int V_685 ;
int V_29 = 0 ;
int V_686 ;
F_32 ( V_35 -> V_282 . V_22 != V_641 ) ;
V_67 = F_34 () ;
if ( ! V_67 )
return - V_75 ;
V_645 = F_61 ( sizeof( * V_645 ) , V_40 ) ;
if ( ! V_645 ) {
F_53 ( V_67 ) ;
return - V_75 ;
}
F_506 ( V_17 ) ;
V_685 = F_237 ( V_17 ) ;
F_474 ( V_17 ) ;
V_67 -> V_83 [ V_685 ] = V_17 ;
V_67 -> V_84 [ V_685 ] = F_39 ( V_17 ) ;
F_506 ( V_136 ) ;
V_176 = F_237 ( V_136 ) ;
V_67 -> V_83 [ V_176 ] = V_136 ;
V_67 -> V_84 [ V_176 ] = 0 ;
V_67 -> V_660 [ V_176 ] = V_674 ;
V_645 -> V_120 [ V_685 ] = 1 ;
V_645 -> V_7 [ V_685 ] = V_134 ;
V_645 -> V_176 = V_176 ;
V_645 -> V_673 = - 1 ;
V_645 -> V_650 = V_652 ;
V_645 -> V_653 = 0 ;
V_645 -> V_183 = 1 ;
V_645 -> V_676 = 1 ;
V_645 -> V_649 = F_462 ( V_35 ) ;
while ( 1 ) {
V_686 = F_485 ( V_118 , V_35 , V_67 , V_645 ) ;
if ( V_686 < 0 ) {
V_29 = V_686 ;
break;
}
V_686 = F_486 ( V_118 , V_35 , V_67 , V_645 , V_685 ) ;
if ( V_686 < 0 )
V_29 = V_686 ;
if ( V_686 != 0 )
break;
}
F_9 ( V_645 ) ;
F_53 ( V_67 ) ;
return V_29 ;
}
static T_2 F_507 ( struct V_34 * V_35 , T_2 V_7 )
{
T_2 V_378 ;
T_2 V_687 ;
V_687 = F_288 ( V_35 -> V_37 , V_7 ) ;
if ( V_687 )
return F_290 ( V_687 ) ;
V_378 = V_35 -> V_37 -> V_379 -> V_380 ;
V_687 = V_389 |
V_388 | V_387 |
V_341 | V_342 ;
if ( V_378 == 1 ) {
V_687 |= V_340 ;
V_687 = V_7 & ~ V_687 ;
if ( V_7 & V_389 )
return V_687 ;
if ( V_7 & ( V_341 |
V_342 ) )
return V_687 | V_340 ;
} else {
if ( V_7 & V_687 )
return V_7 ;
V_687 |= V_340 ;
V_687 = V_7 & ~ V_687 ;
if ( V_7 & V_340 )
return V_687 | V_341 ;
}
return V_7 ;
}
static int F_508 ( struct V_1 * V_2 , int V_407 )
{
struct V_111 * V_406 = V_2 -> V_96 ;
T_2 V_36 ;
T_2 V_688 ;
int V_29 = - V_314 ;
if ( ( V_406 -> V_7 &
( V_337 | V_55 ) ) &&
! V_407 )
V_688 = V_303 ;
else
V_688 = 0 ;
F_11 ( & V_406 -> V_52 ) ;
F_11 ( & V_2 -> V_52 ) ;
if ( V_2 -> V_306 ) {
V_2 -> V_306 ++ ;
V_29 = 0 ;
goto V_82;
}
V_36 = V_2 -> V_21 . V_33 - V_2 -> V_10 - V_2 -> V_9 -
V_2 -> V_46 - F_58 ( & V_2 -> V_97 ) ;
if ( V_406 -> V_95 + V_406 -> V_351 + V_406 -> V_350 +
V_406 -> V_353 + V_406 -> V_352 + V_36 +
V_688 <= V_406 -> V_338 ) {
V_406 -> V_352 += V_36 ;
V_2 -> V_306 ++ ;
F_72 ( & V_2 -> V_689 , & V_406 -> V_359 ) ;
V_29 = 0 ;
}
V_82:
F_13 ( & V_2 -> V_52 ) ;
F_13 ( & V_406 -> V_52 ) ;
return V_29 ;
}
int F_509 ( struct V_34 * V_35 ,
struct V_1 * V_2 )
{
struct V_117 * V_118 ;
T_2 V_690 ;
int V_29 ;
V_164:
V_118 = F_211 ( V_35 ) ;
if ( F_212 ( V_118 ) )
return F_213 ( V_118 ) ;
F_49 ( & V_35 -> V_37 -> V_691 ) ;
if ( F_238 ( V_692 , & V_118 -> V_135 -> V_7 ) ) {
T_2 V_308 = V_118 -> V_308 ;
F_47 ( & V_35 -> V_37 -> V_691 ) ;
F_215 ( V_118 , V_35 ) ;
V_29 = F_510 ( V_35 , V_308 ) ;
if ( V_29 )
return V_29 ;
goto V_164;
}
V_690 = F_507 ( V_35 , V_2 -> V_7 ) ;
if ( V_690 != V_2 -> V_7 ) {
V_29 = F_297 ( V_118 , V_35 , V_690 ,
V_400 ) ;
if ( V_29 == - V_314 )
V_29 = 0 ;
if ( V_29 < 0 )
goto V_82;
}
V_29 = F_508 ( V_2 , 0 ) ;
if ( ! V_29 )
goto V_82;
V_690 = F_291 ( V_35 , V_2 -> V_96 -> V_7 ) ;
V_29 = F_297 ( V_118 , V_35 , V_690 ,
V_400 ) ;
if ( V_29 < 0 )
goto V_82;
V_29 = F_508 ( V_2 , 0 ) ;
V_82:
if ( V_2 -> V_7 & V_337 ) {
V_690 = F_507 ( V_35 , V_2 -> V_7 ) ;
F_511 ( V_35 -> V_37 -> V_392 ) ;
F_314 ( V_118 , V_35 , V_690 ) ;
F_512 ( V_35 -> V_37 -> V_392 ) ;
}
F_47 ( & V_35 -> V_37 -> V_691 ) ;
F_215 ( V_118 , V_35 ) ;
return V_29 ;
}
int F_513 ( struct V_117 * V_118 ,
struct V_34 * V_35 , T_2 type )
{
T_2 V_690 = F_291 ( V_35 , type ) ;
return F_297 ( V_118 , V_35 , V_690 ,
V_400 ) ;
}
T_2 F_514 ( struct V_111 * V_406 )
{
struct V_1 * V_14 ;
T_2 V_693 = 0 ;
int V_339 ;
if ( F_180 ( & V_406 -> V_359 ) )
return 0 ;
F_11 ( & V_406 -> V_52 ) ;
F_181 (block_group, &sinfo->ro_bgs, ro_list) {
F_11 ( & V_14 -> V_52 ) ;
if ( ! V_14 -> V_306 ) {
F_13 ( & V_14 -> V_52 ) ;
continue;
}
if ( V_14 -> V_7 & ( V_341 |
V_342 |
V_340 ) )
V_339 = 2 ;
else
V_339 = 1 ;
V_693 += ( V_14 -> V_21 . V_33 -
F_58 ( & V_14 -> V_97 ) ) *
V_339 ;
F_13 ( & V_14 -> V_52 ) ;
}
F_13 ( & V_406 -> V_52 ) ;
return V_693 ;
}
void F_515 ( struct V_34 * V_35 ,
struct V_1 * V_2 )
{
struct V_111 * V_406 = V_2 -> V_96 ;
T_2 V_36 ;
F_32 ( ! V_2 -> V_306 ) ;
F_11 ( & V_406 -> V_52 ) ;
F_11 ( & V_2 -> V_52 ) ;
if ( ! -- V_2 -> V_306 ) {
V_36 = V_2 -> V_21 . V_33 - V_2 -> V_10 -
V_2 -> V_9 - V_2 -> V_46 -
F_58 ( & V_2 -> V_97 ) ;
V_406 -> V_352 -= V_36 ;
F_271 ( & V_2 -> V_689 ) ;
}
F_13 ( & V_2 -> V_52 ) ;
F_13 ( & V_406 -> V_52 ) ;
}
int F_516 ( struct V_34 * V_35 , T_2 V_27 )
{
struct V_1 * V_14 ;
struct V_111 * V_96 ;
struct V_694 * V_379 = V_35 -> V_37 -> V_379 ;
struct V_695 * V_696 ;
struct V_117 * V_118 ;
T_2 V_697 ;
T_2 V_698 = 1 ;
T_2 V_699 = 0 ;
T_2 V_373 ;
int V_589 ;
int V_116 = 0 ;
int V_29 = 0 ;
V_14 = F_76 ( V_35 -> V_37 , V_27 ) ;
if ( ! V_14 )
return - 1 ;
V_697 = F_58 ( & V_14 -> V_97 ) ;
if ( ! V_697 )
goto V_82;
V_96 = V_14 -> V_96 ;
F_11 ( & V_96 -> V_52 ) ;
V_116 = V_96 -> V_116 ;
if ( ( V_96 -> V_338 != V_14 -> V_21 . V_33 ) &&
( V_96 -> V_95 + V_96 -> V_351 +
V_96 -> V_350 + V_96 -> V_352 +
V_697 < V_96 -> V_338 ) ) {
F_13 ( & V_96 -> V_52 ) ;
goto V_82;
}
F_13 ( & V_96 -> V_52 ) ;
V_29 = - 1 ;
V_373 = F_288 ( V_35 -> V_37 , V_14 -> V_7 ) ;
if ( V_373 ) {
V_589 = F_417 ( F_290 ( V_373 ) ) ;
} else {
if ( V_116 )
goto V_82;
V_589 = F_418 ( V_14 ) ;
}
if ( V_589 == V_571 ) {
V_698 = 4 ;
V_697 >>= 1 ;
} else if ( V_589 == V_572 ) {
V_698 = 2 ;
} else if ( V_589 == V_573 ) {
V_697 <<= 1 ;
} else if ( V_589 == V_574 ) {
V_698 = V_379 -> V_380 ;
V_697 = F_204 ( V_697 , V_698 ) ;
}
V_118 = F_211 ( V_35 ) ;
if ( F_212 ( V_118 ) ) {
V_29 = F_213 ( V_118 ) ;
goto V_82;
}
F_49 ( & V_35 -> V_37 -> V_416 ) ;
F_181 (device, &fs_devices->alloc_list, dev_alloc_list) {
T_2 V_700 ;
if ( V_696 -> V_338 > V_696 -> V_95 + V_697 &&
! V_696 -> V_701 ) {
V_29 = F_517 ( V_118 , V_696 , V_697 ,
& V_700 , NULL ) ;
if ( ! V_29 )
V_699 ++ ;
if ( V_699 >= V_698 )
break;
V_29 = - 1 ;
}
}
F_47 ( & V_35 -> V_37 -> V_416 ) ;
F_215 ( V_118 , V_35 ) ;
V_82:
F_6 ( V_14 ) ;
return V_29 ;
}
static int F_518 ( struct V_34 * V_35 ,
struct V_66 * V_67 , struct V_70 * V_21 )
{
int V_29 = 0 ;
struct V_70 V_147 ;
struct V_68 * V_69 ;
int V_646 ;
V_29 = F_38 ( NULL , V_35 , V_21 , V_67 , 0 , 0 ) ;
if ( V_29 < 0 )
goto V_82;
while ( 1 ) {
V_646 = V_67 -> V_84 [ 0 ] ;
V_69 = V_67 -> V_83 [ 0 ] ;
if ( V_646 >= F_39 ( V_69 ) ) {
V_29 = F_51 ( V_35 , V_67 ) ;
if ( V_29 == 0 )
continue;
if ( V_29 < 0 )
goto V_82;
break;
}
F_41 ( V_69 , & V_147 , V_646 ) ;
if ( V_147 . V_22 >= V_21 -> V_22 &&
V_147 . type == V_188 ) {
V_29 = 0 ;
goto V_82;
}
V_67 -> V_84 [ 0 ] ++ ;
}
V_82:
return V_29 ;
}
void F_519 ( struct V_12 * V_13 )
{
struct V_1 * V_14 ;
T_2 V_72 = 0 ;
while ( 1 ) {
struct V_297 * V_297 ;
V_14 = F_75 ( V_13 , V_72 ) ;
while ( V_14 ) {
F_11 ( & V_14 -> V_52 ) ;
if ( V_14 -> V_173 )
break;
F_13 ( & V_14 -> V_52 ) ;
V_14 = F_249 ( V_13 -> V_89 ,
V_14 ) ;
}
if ( ! V_14 ) {
if ( V_72 == 0 )
break;
V_72 = 0 ;
continue;
}
V_297 = V_14 -> V_297 ;
V_14 -> V_173 = 0 ;
V_14 -> V_297 = NULL ;
F_13 ( & V_14 -> V_52 ) ;
F_264 ( V_297 ) ;
V_72 = V_14 -> V_21 . V_22 + V_14 -> V_21 . V_33 ;
F_6 ( V_14 ) ;
}
}
int F_520 ( struct V_12 * V_13 )
{
struct V_1 * V_14 ;
struct V_111 * V_96 ;
struct V_50 * V_53 ;
struct V_15 * V_30 ;
F_71 ( & V_13 -> V_85 ) ;
while ( ! F_180 ( & V_13 -> V_109 ) ) {
V_53 = F_182 ( V_13 -> V_109 . V_81 ,
struct V_50 , V_99 ) ;
F_193 ( & V_53 -> V_99 ) ;
F_26 ( V_53 ) ;
}
F_73 ( & V_13 -> V_85 ) ;
F_11 ( & V_13 -> V_527 ) ;
while ( ! F_180 ( & V_13 -> V_529 ) ) {
V_14 = F_270 ( & V_13 -> V_529 ,
struct V_1 ,
V_528 ) ;
F_271 ( & V_14 -> V_528 ) ;
F_6 ( V_14 ) ;
}
F_13 ( & V_13 -> V_527 ) ;
F_11 ( & V_13 -> V_18 ) ;
while ( ( V_30 = F_199 ( & V_13 -> V_19 ) ) != NULL ) {
V_14 = F_12 ( V_30 , struct V_1 ,
V_20 ) ;
F_192 ( & V_14 -> V_20 ,
& V_13 -> V_19 ) ;
F_521 ( & V_14 -> V_20 ) ;
F_13 ( & V_13 -> V_18 ) ;
F_71 ( & V_14 -> V_96 -> V_349 ) ;
F_193 ( & V_14 -> V_99 ) ;
F_73 ( & V_14 -> V_96 -> V_349 ) ;
if ( V_14 -> V_3 == V_107 )
F_416 ( V_14 ) ;
if ( V_14 -> V_3 == V_103 ||
V_14 -> V_3 == V_5 )
F_19 ( V_13 -> V_65 , V_14 ) ;
F_522 ( V_14 ) ;
F_6 ( V_14 ) ;
F_11 ( & V_13 -> V_18 ) ;
}
F_13 ( & V_13 -> V_18 ) ;
F_523 () ;
F_365 ( V_13 ) ;
while ( ! F_180 ( & V_13 -> V_96 ) ) {
int V_43 ;
V_96 = F_182 ( V_13 -> V_96 . V_81 ,
struct V_111 ,
V_99 ) ;
if ( F_259 ( V_13 -> V_89 , V_417 ) ) {
if ( F_8 ( V_96 -> V_350 > 0 ||
V_96 -> V_351 > 0 ||
V_96 -> V_353 > 0 ) ) {
F_318 ( V_96 , 0 , 0 ) ;
}
}
F_193 ( & V_96 -> V_99 ) ;
for ( V_43 = 0 ; V_43 < V_347 ; V_43 ++ ) {
struct V_702 * V_360 ;
V_360 = V_96 -> V_703 [ V_43 ] ;
V_96 -> V_703 [ V_43 ] = NULL ;
if ( V_360 ) {
F_524 ( V_360 ) ;
F_525 ( V_360 ) ;
}
}
F_524 ( & V_96 -> V_360 ) ;
F_525 ( & V_96 -> V_360 ) ;
}
return 0 ;
}
static void F_526 ( struct V_111 * V_96 ,
struct V_1 * V_2 )
{
int V_589 = F_418 ( V_2 ) ;
bool V_254 = false ;
F_71 ( & V_96 -> V_349 ) ;
if ( F_180 ( & V_96 -> V_348 [ V_589 ] ) )
V_254 = true ;
F_72 ( & V_2 -> V_99 , & V_96 -> V_348 [ V_589 ] ) ;
F_73 ( & V_96 -> V_349 ) ;
if ( V_254 ) {
struct V_704 * V_705 ;
int V_29 ;
V_705 = F_61 ( sizeof( * V_705 ) , V_40 ) ;
if ( ! V_705 )
goto V_706;
V_705 -> V_381 = V_589 ;
F_527 ( & V_705 -> V_360 , & V_707 ) ;
V_29 = F_528 ( & V_705 -> V_360 , & V_96 -> V_360 ,
L_8 , F_419 ( V_589 ) ) ;
if ( V_29 ) {
F_525 ( & V_705 -> V_360 ) ;
goto V_706;
}
V_96 -> V_703 [ V_589 ] = & V_705 -> V_360 ;
}
return;
V_706:
F_529 ( L_42 ) ;
}
static struct V_1 *
F_530 ( struct V_34 * V_35 , T_2 V_32 , T_2 V_61 )
{
struct V_1 * V_2 ;
V_2 = F_61 ( sizeof( * V_2 ) , V_40 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_11 = F_61 ( sizeof( * V_2 -> V_11 ) ,
V_40 ) ;
if ( ! V_2 -> V_11 ) {
F_9 ( V_2 ) ;
return NULL ;
}
V_2 -> V_21 . V_22 = V_32 ;
V_2 -> V_21 . V_33 = V_61 ;
V_2 -> V_21 . type = V_188 ;
V_2 -> V_57 = V_35 -> V_57 ;
V_2 -> V_37 = V_35 -> V_37 ;
V_2 -> V_708 = F_531 ( V_35 ,
& V_35 -> V_37 -> V_48 ,
V_32 ) ;
F_532 ( V_2 ) ;
F_65 ( & V_2 -> V_8 , 1 ) ;
F_281 ( & V_2 -> V_52 ) ;
F_280 ( & V_2 -> V_580 ) ;
F_62 ( & V_2 -> V_99 ) ;
F_62 ( & V_2 -> V_709 ) ;
F_62 ( & V_2 -> V_528 ) ;
F_62 ( & V_2 -> V_689 ) ;
F_62 ( & V_2 -> V_330 ) ;
F_62 ( & V_2 -> V_331 ) ;
F_533 ( V_2 ) ;
F_65 ( & V_2 -> V_710 , 0 ) ;
F_63 ( & V_2 -> V_711 ) ;
return V_2 ;
}
int F_534 ( struct V_34 * V_35 )
{
struct V_66 * V_67 ;
int V_29 ;
struct V_1 * V_2 ;
struct V_12 * V_13 = V_35 -> V_37 ;
struct V_111 * V_96 ;
struct V_70 V_21 ;
struct V_70 V_147 ;
struct V_68 * V_69 ;
int V_712 = 0 ;
T_2 V_713 ;
V_35 = V_13 -> V_65 ;
V_21 . V_22 = 0 ;
V_21 . V_33 = 0 ;
V_21 . type = V_188 ;
V_67 = F_34 () ;
if ( ! V_67 )
return - V_75 ;
V_67 -> V_78 = V_79 ;
V_713 = F_535 ( V_35 -> V_37 -> V_261 ) ;
if ( F_259 ( V_35 , V_312 ) &&
F_536 ( V_35 -> V_37 -> V_261 ) != V_713 )
V_712 = 1 ;
if ( F_259 ( V_35 , V_714 ) )
V_712 = 1 ;
while ( 1 ) {
V_29 = F_518 ( V_35 , V_67 , & V_21 ) ;
if ( V_29 > 0 )
break;
if ( V_29 != 0 )
goto error;
V_69 = V_67 -> V_83 [ 0 ] ;
F_41 ( V_69 , & V_147 , V_67 -> V_84 [ 0 ] ) ;
V_2 = F_530 ( V_35 , V_147 . V_22 ,
V_147 . V_33 ) ;
if ( ! V_2 ) {
V_29 = - V_75 ;
goto error;
}
if ( V_712 ) {
if ( F_259 ( V_35 , V_312 ) )
V_2 -> V_304 = V_321 ;
}
F_537 ( V_69 , & V_2 -> V_97 ,
F_247 ( V_69 , V_67 -> V_84 [ 0 ] ) ,
sizeof( V_2 -> V_97 ) ) ;
V_2 -> V_7 = F_538 ( & V_2 -> V_97 ) ;
V_21 . V_22 = V_147 . V_22 + V_147 . V_33 ;
F_45 ( V_67 ) ;
V_29 = F_21 ( V_35 , V_2 ) ;
if ( V_29 ) {
F_19 ( V_35 , V_2 ) ;
F_6 ( V_2 ) ;
goto error;
}
if ( V_147 . V_33 == F_58 ( & V_2 -> V_97 ) ) {
V_2 -> V_106 = ( T_2 ) - 1 ;
V_2 -> V_3 = V_4 ;
F_19 ( V_35 , V_2 ) ;
} else if ( F_58 ( & V_2 -> V_97 ) == 0 ) {
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
F_522 ( V_2 ) ;
F_6 ( V_2 ) ;
goto error;
}
V_29 = F_278 ( V_13 , V_2 -> V_7 , V_147 . V_33 ,
F_58 ( & V_2 -> V_97 ) ,
& V_96 ) ;
if ( V_29 ) {
F_522 ( V_2 ) ;
F_11 ( & V_13 -> V_18 ) ;
F_192 ( & V_2 -> V_20 ,
& V_13 -> V_19 ) ;
F_521 ( & V_2 -> V_20 ) ;
F_13 ( & V_13 -> V_18 ) ;
F_6 ( V_2 ) ;
goto error;
}
V_2 -> V_96 = V_96 ;
F_11 ( & V_2 -> V_96 -> V_52 ) ;
V_2 -> V_96 -> V_352 += V_2 -> V_46 ;
F_13 ( & V_2 -> V_96 -> V_52 ) ;
F_526 ( V_96 , V_2 ) ;
F_284 ( V_35 -> V_37 , V_2 -> V_7 ) ;
if ( F_539 ( V_35 , V_2 -> V_21 . V_22 ) ) {
F_508 ( V_2 , 1 ) ;
} else if ( F_58 ( & V_2 -> V_97 ) == 0 ) {
F_11 ( & V_13 -> V_527 ) ;
if ( F_180 ( & V_2 -> V_528 ) ) {
F_4 ( V_2 ) ;
F_72 ( & V_2 -> V_528 ,
& V_13 -> V_529 ) ;
}
F_13 ( & V_13 -> V_527 ) ;
}
}
F_79 (space_info, &root->fs_info->space_info, list) {
if ( ! ( F_291 ( V_35 , V_96 -> V_7 ) &
( V_342 |
V_341 |
V_388 |
V_387 |
V_340 ) ) )
continue;
F_181 (cache,
&space_info->block_groups[BTRFS_RAID_RAID0],
list)
F_508 ( V_2 , 1 ) ;
F_181 (cache,
&space_info->block_groups[BTRFS_RAID_SINGLE],
list)
F_508 ( V_2 , 1 ) ;
}
F_364 ( V_13 ) ;
V_29 = 0 ;
error:
F_53 ( V_67 ) ;
return V_29 ;
}
void F_222 ( struct V_117 * V_118 ,
struct V_34 * V_35 )
{
struct V_1 * V_14 , * V_317 ;
struct V_34 * V_65 = V_35 -> V_37 -> V_65 ;
struct V_715 V_97 ;
struct V_70 V_21 ;
int V_29 = 0 ;
bool V_277 = V_118 -> V_277 ;
V_118 -> V_277 = false ;
F_266 (block_group, tmp, &trans->new_bgs, bg_list) {
if ( V_29 )
goto V_81;
F_11 ( & V_14 -> V_52 ) ;
memcpy ( & V_97 , & V_14 -> V_97 , sizeof( V_97 ) ) ;
memcpy ( & V_21 , & V_14 -> V_21 , sizeof( V_21 ) ) ;
F_13 ( & V_14 -> V_52 ) ;
V_29 = F_540 ( V_118 , V_65 , & V_21 , & V_97 ,
sizeof( V_97 ) ) ;
if ( V_29 )
F_160 ( V_118 , V_65 , V_29 ) ;
V_29 = F_541 ( V_118 , V_65 ,
V_21 . V_22 , V_21 . V_33 ) ;
if ( V_29 )
F_160 ( V_118 , V_65 , V_29 ) ;
F_542 ( V_118 , V_35 -> V_37 , V_14 ) ;
V_81:
F_271 ( & V_14 -> V_528 ) ;
}
V_118 -> V_277 = V_277 ;
}
int F_543 ( struct V_117 * V_118 ,
struct V_34 * V_35 , T_2 V_95 ,
T_2 type , T_2 V_716 , T_2 V_717 ,
T_2 V_61 )
{
int V_29 ;
struct V_34 * V_65 ;
struct V_1 * V_2 ;
V_65 = V_35 -> V_37 -> V_65 ;
F_544 ( V_35 -> V_37 , V_118 ) ;
V_2 = F_530 ( V_35 , V_717 , V_61 ) ;
if ( ! V_2 )
return - V_75 ;
F_387 ( & V_2 -> V_97 , V_95 ) ;
F_545 ( & V_2 -> V_97 , V_716 ) ;
F_546 ( & V_2 -> V_97 , type ) ;
V_2 -> V_7 = type ;
V_2 -> V_106 = ( T_2 ) - 1 ;
V_2 -> V_3 = V_4 ;
V_2 -> V_718 = 1 ;
V_29 = F_21 ( V_35 , V_2 ) ;
if ( V_29 ) {
F_19 ( V_35 , V_2 ) ;
F_6 ( V_2 ) ;
return V_29 ;
}
F_29 ( V_2 , V_35 -> V_37 , V_717 ,
V_717 + V_61 ) ;
F_19 ( V_35 , V_2 ) ;
#ifdef F_36
if ( F_37 ( V_35 , V_2 ) ) {
T_2 V_719 = V_61 - V_95 ;
V_95 += V_719 >> 1 ;
F_27 ( V_35 , V_2 ) ;
}
#endif
V_29 = F_278 ( V_35 -> V_37 , V_2 -> V_7 , 0 , 0 ,
& V_2 -> V_96 ) ;
if ( V_29 ) {
F_522 ( V_2 ) ;
F_6 ( V_2 ) ;
return V_29 ;
}
V_29 = F_10 ( V_35 -> V_37 , V_2 ) ;
if ( V_29 ) {
F_522 ( V_2 ) ;
F_6 ( V_2 ) ;
return V_29 ;
}
V_29 = F_278 ( V_35 -> V_37 , V_2 -> V_7 , V_61 , V_95 ,
& V_2 -> V_96 ) ;
if ( V_29 ) {
F_522 ( V_2 ) ;
F_11 ( & V_35 -> V_37 -> V_18 ) ;
F_192 ( & V_2 -> V_20 ,
& V_35 -> V_37 -> V_19 ) ;
F_521 ( & V_2 -> V_20 ) ;
F_13 ( & V_35 -> V_37 -> V_18 ) ;
F_6 ( V_2 ) ;
return V_29 ;
}
F_363 ( V_35 -> V_37 ) ;
F_11 ( & V_2 -> V_96 -> V_52 ) ;
V_2 -> V_96 -> V_352 += V_2 -> V_46 ;
F_13 ( & V_2 -> V_96 -> V_52 ) ;
F_526 ( V_2 -> V_96 , V_2 ) ;
F_72 ( & V_2 -> V_528 , & V_118 -> V_280 ) ;
F_284 ( V_65 -> V_37 , type ) ;
return 0 ;
}
static void F_547 ( struct V_12 * V_37 , T_2 V_7 )
{
T_2 V_364 = F_285 ( V_7 ) &
V_365 ;
F_286 ( & V_37 -> V_366 ) ;
if ( V_7 & V_336 )
V_37 -> V_367 &= ~ V_364 ;
if ( V_7 & V_55 )
V_37 -> V_368 &= ~ V_364 ;
if ( V_7 & V_337 )
V_37 -> V_369 &= ~ V_364 ;
F_287 ( & V_37 -> V_366 ) ;
}
int F_548 ( struct V_117 * V_118 ,
struct V_34 * V_35 , T_2 V_720 ,
struct V_721 * V_722 )
{
struct V_66 * V_67 ;
struct V_1 * V_14 ;
struct V_539 * V_547 ;
struct V_34 * V_89 = V_35 -> V_37 -> V_89 ;
struct V_70 V_21 ;
struct V_297 * V_297 ;
struct V_702 * V_360 = NULL ;
int V_29 ;
int V_589 ;
int V_339 ;
struct V_50 * V_53 = NULL ;
bool V_723 ;
V_35 = V_35 -> V_37 -> V_65 ;
V_14 = F_76 ( V_35 -> V_37 , V_720 ) ;
F_32 ( ! V_14 ) ;
F_32 ( ! V_14 -> V_306 ) ;
F_19 ( V_35 , V_14 ) ;
memcpy ( & V_21 , & V_14 -> V_21 , sizeof( V_21 ) ) ;
V_589 = F_418 ( V_14 ) ;
if ( V_14 -> V_7 & ( V_340 |
V_341 |
V_342 ) )
V_339 = 2 ;
else
V_339 = 1 ;
V_547 = & V_35 -> V_37 -> V_545 ;
F_11 ( & V_547 -> V_583 ) ;
F_429 ( V_14 , V_547 ) ;
F_13 ( & V_547 -> V_583 ) ;
V_547 = & V_35 -> V_37 -> V_543 ;
F_11 ( & V_547 -> V_583 ) ;
F_429 ( V_14 , V_547 ) ;
F_13 ( & V_547 -> V_583 ) ;
V_67 = F_34 () ;
if ( ! V_67 ) {
V_29 = - V_75 ;
goto V_82;
}
V_297 = F_252 ( V_89 , V_14 , V_67 ) ;
F_49 ( & V_118 -> V_135 -> V_329 ) ;
F_11 ( & V_118 -> V_135 -> V_328 ) ;
if ( ! F_180 ( & V_14 -> V_331 ) ) {
F_271 ( & V_14 -> V_331 ) ;
F_8 ( ! F_212 ( V_297 ) && V_297 != V_14 -> V_332 . V_297 ) ;
F_13 ( & V_118 -> V_135 -> V_328 ) ;
F_272 ( V_35 , V_118 , V_14 ,
& V_14 -> V_332 , V_67 ,
V_14 -> V_21 . V_22 ) ;
F_6 ( V_14 ) ;
F_11 ( & V_118 -> V_135 -> V_328 ) ;
}
if ( ! F_180 ( & V_14 -> V_330 ) ) {
F_271 ( & V_14 -> V_330 ) ;
F_6 ( V_14 ) ;
}
F_13 ( & V_118 -> V_135 -> V_328 ) ;
F_47 ( & V_118 -> V_135 -> V_329 ) ;
if ( ! F_212 ( V_297 ) ) {
V_29 = F_549 ( V_118 , V_297 ) ;
if ( V_29 ) {
F_550 ( V_297 ) ;
goto V_82;
}
F_551 ( V_297 ) ;
F_11 ( & V_14 -> V_52 ) ;
if ( V_14 -> V_173 ) {
V_14 -> V_173 = 0 ;
V_14 -> V_297 = NULL ;
F_13 ( & V_14 -> V_52 ) ;
F_264 ( V_297 ) ;
} else {
F_13 ( & V_14 -> V_52 ) ;
}
F_550 ( V_297 ) ;
}
V_21 . V_22 = V_724 ;
V_21 . V_33 = V_14 -> V_21 . V_22 ;
V_21 . type = 0 ;
V_29 = F_38 ( V_118 , V_89 , & V_21 , V_67 , - 1 , 1 ) ;
if ( V_29 < 0 )
goto V_82;
if ( V_29 > 0 )
F_45 ( V_67 ) ;
if ( V_29 == 0 ) {
V_29 = F_124 ( V_118 , V_89 , V_67 ) ;
if ( V_29 )
goto V_82;
F_45 ( V_67 ) ;
}
F_11 ( & V_35 -> V_37 -> V_18 ) ;
F_192 ( & V_14 -> V_20 ,
& V_35 -> V_37 -> V_19 ) ;
F_521 ( & V_14 -> V_20 ) ;
if ( V_35 -> V_37 -> V_26 == V_14 -> V_21 . V_22 )
V_35 -> V_37 -> V_26 = ( T_2 ) - 1 ;
F_13 ( & V_35 -> V_37 -> V_18 ) ;
F_71 ( & V_14 -> V_96 -> V_349 ) ;
F_271 ( & V_14 -> V_99 ) ;
if ( F_180 ( & V_14 -> V_96 -> V_348 [ V_589 ] ) ) {
V_360 = V_14 -> V_96 -> V_703 [ V_589 ] ;
V_14 -> V_96 -> V_703 [ V_589 ] = NULL ;
F_547 ( V_35 -> V_37 , V_14 -> V_7 ) ;
}
F_73 ( & V_14 -> V_96 -> V_349 ) ;
if ( V_360 ) {
F_524 ( V_360 ) ;
F_525 ( V_360 ) ;
}
if ( V_14 -> V_108 )
V_53 = F_25 ( V_14 ) ;
if ( V_14 -> V_3 == V_107 )
F_416 ( V_14 ) ;
if ( V_14 -> V_108 ) {
F_71 ( & V_35 -> V_37 -> V_85 ) ;
if ( ! V_53 ) {
struct V_50 * V_51 ;
F_181 (ctl,
&root->fs_info->caching_block_groups, list)
if ( V_51 -> V_14 == V_14 ) {
V_53 = V_51 ;
F_5 ( & V_53 -> V_8 ) ;
break;
}
}
if ( V_53 )
F_271 ( & V_53 -> V_99 ) ;
F_73 ( & V_35 -> V_37 -> V_85 ) ;
if ( V_53 ) {
F_26 ( V_53 ) ;
F_26 ( V_53 ) ;
}
}
F_11 ( & V_118 -> V_135 -> V_328 ) ;
if ( ! F_180 ( & V_14 -> V_330 ) ) {
F_8 ( 1 ) ;
}
if ( ! F_180 ( & V_14 -> V_331 ) ) {
F_8 ( 1 ) ;
}
F_13 ( & V_118 -> V_135 -> V_328 ) ;
F_522 ( V_14 ) ;
F_11 ( & V_14 -> V_96 -> V_52 ) ;
F_271 ( & V_14 -> V_689 ) ;
if ( F_259 ( V_35 , V_417 ) ) {
F_8 ( V_14 -> V_96 -> V_338
< V_14 -> V_21 . V_33 ) ;
F_8 ( V_14 -> V_96 -> V_352
< V_14 -> V_21 . V_33 ) ;
F_8 ( V_14 -> V_96 -> V_343
< V_14 -> V_21 . V_33 * V_339 ) ;
}
V_14 -> V_96 -> V_338 -= V_14 -> V_21 . V_33 ;
V_14 -> V_96 -> V_352 -= V_14 -> V_21 . V_33 ;
V_14 -> V_96 -> V_343 -= V_14 -> V_21 . V_33 * V_339 ;
F_13 ( & V_14 -> V_96 -> V_52 ) ;
memcpy ( & V_21 , & V_14 -> V_21 , sizeof( V_21 ) ) ;
F_511 ( V_35 ) ;
if ( ! F_180 ( & V_722 -> V_99 ) ) {
F_552 ( V_722 ) ;
}
F_11 ( & V_14 -> V_52 ) ;
V_14 -> V_725 = 1 ;
V_723 = ( F_209 ( & V_14 -> V_710 ) == 0 ) ;
if ( ! V_723 ) {
F_553 ( & V_722 -> V_99 , & V_35 -> V_37 -> V_726 ) ;
}
F_13 ( & V_14 -> V_52 ) ;
if ( V_723 ) {
struct V_727 * V_728 ;
V_728 = & V_35 -> V_37 -> V_48 . V_729 ;
F_554 ( & V_728 -> V_52 ) ;
F_555 ( V_728 , V_722 ) ;
F_556 ( & V_728 -> V_52 ) ;
F_552 ( V_722 ) ;
}
F_512 ( V_35 ) ;
V_29 = F_557 ( V_118 , V_35 -> V_37 , V_14 ) ;
if ( V_29 )
goto V_82;
F_6 ( V_14 ) ;
F_6 ( V_14 ) ;
V_29 = F_38 ( V_118 , V_35 , & V_21 , V_67 , - 1 , 1 ) ;
if ( V_29 > 0 )
V_29 = - V_184 ;
if ( V_29 < 0 )
goto V_82;
V_29 = F_124 ( V_118 , V_35 , V_67 ) ;
V_82:
F_53 ( V_67 ) ;
return V_29 ;
}
struct V_117 *
F_558 ( struct V_12 * V_37 ,
const T_2 V_717 )
{
struct V_727 * V_728 = & V_37 -> V_48 . V_729 ;
struct V_721 * V_722 ;
struct V_730 * V_731 ;
unsigned int V_732 ;
F_559 ( & V_728 -> V_52 ) ;
V_722 = F_560 ( V_728 , V_717 , 1 ) ;
F_561 ( & V_728 -> V_52 ) ;
ASSERT ( V_722 && V_722 -> V_32 == V_717 ) ;
V_731 = V_722 -> V_730 ;
V_732 = 3 + V_731 -> V_211 ;
F_552 ( V_722 ) ;
return F_562 ( V_37 -> V_65 ,
V_732 , 1 ) ;
}
void F_563 ( struct V_12 * V_37 )
{
struct V_1 * V_14 ;
struct V_111 * V_96 ;
struct V_34 * V_35 = V_37 -> V_65 ;
struct V_117 * V_118 ;
int V_29 = 0 ;
if ( ! V_37 -> V_733 )
return;
F_11 ( & V_37 -> V_527 ) ;
while ( ! F_180 ( & V_37 -> V_529 ) ) {
T_2 V_32 , V_31 ;
int V_710 ;
V_14 = F_270 ( & V_37 -> V_529 ,
struct V_1 ,
V_528 ) ;
F_271 ( & V_14 -> V_528 ) ;
V_96 = V_14 -> V_96 ;
if ( V_29 || F_321 ( V_96 ) ) {
F_6 ( V_14 ) ;
continue;
}
F_13 ( & V_37 -> V_527 ) ;
F_49 ( & V_37 -> V_734 ) ;
F_71 ( & V_96 -> V_349 ) ;
F_11 ( & V_14 -> V_52 ) ;
if ( V_14 -> V_10 ||
F_58 ( & V_14 -> V_97 ) ||
V_14 -> V_306 ||
F_564 ( & V_14 -> V_99 ) ) {
F_13 ( & V_14 -> V_52 ) ;
F_73 ( & V_96 -> V_349 ) ;
goto V_81;
}
F_13 ( & V_14 -> V_52 ) ;
V_29 = F_508 ( V_14 , 0 ) ;
F_73 ( & V_96 -> V_349 ) ;
if ( V_29 < 0 ) {
V_29 = 0 ;
goto V_81;
}
V_118 = F_558 ( V_37 ,
V_14 -> V_21 . V_22 ) ;
if ( F_212 ( V_118 ) ) {
F_515 ( V_35 , V_14 ) ;
V_29 = F_213 ( V_118 ) ;
goto V_81;
}
V_32 = V_14 -> V_21 . V_22 ;
V_31 = V_32 + V_14 -> V_21 . V_33 - 1 ;
F_49 ( & V_37 -> V_553 ) ;
V_29 = F_20 ( & V_37 -> V_38 [ 0 ] , V_32 , V_31 ,
V_64 , V_40 ) ;
if ( V_29 ) {
F_47 ( & V_37 -> V_553 ) ;
F_515 ( V_35 , V_14 ) ;
goto V_735;
}
V_29 = F_20 ( & V_37 -> V_38 [ 1 ] , V_32 , V_31 ,
V_64 , V_40 ) ;
if ( V_29 ) {
F_47 ( & V_37 -> V_553 ) ;
F_515 ( V_35 , V_14 ) ;
goto V_735;
}
F_47 ( & V_37 -> V_553 ) ;
F_11 ( & V_96 -> V_52 ) ;
F_11 ( & V_14 -> V_52 ) ;
V_96 -> V_350 -= V_14 -> V_9 ;
V_96 -> V_352 += V_14 -> V_9 ;
F_398 ( & V_96 -> V_345 ,
- V_14 -> V_9 ) ;
V_14 -> V_9 = 0 ;
F_13 ( & V_14 -> V_52 ) ;
F_13 ( & V_96 -> V_52 ) ;
V_710 = F_259 ( V_35 , V_554 ) ;
if ( V_710 )
F_565 ( V_14 ) ;
V_29 = F_566 ( V_118 , V_35 ,
V_14 -> V_21 . V_22 ) ;
if ( V_29 ) {
if ( V_710 )
F_401 ( V_14 ) ;
goto V_735;
}
if ( V_710 ) {
F_11 ( & V_37 -> V_527 ) ;
F_567 ( & V_14 -> V_528 ,
& V_118 -> V_135 -> V_550 ) ;
F_13 ( & V_37 -> V_527 ) ;
F_4 ( V_14 ) ;
}
V_735:
F_215 ( V_118 , V_35 ) ;
V_81:
F_47 ( & V_37 -> V_734 ) ;
F_6 ( V_14 ) ;
F_11 ( & V_37 -> V_527 ) ;
}
F_13 ( & V_37 -> V_527 ) ;
}
int F_568 ( struct V_12 * V_37 )
{
struct V_111 * V_96 ;
struct V_736 * V_737 ;
T_2 V_738 ;
T_2 V_7 ;
int V_739 = 0 ;
int V_29 ;
V_737 = V_37 -> V_261 ;
if ( ! F_569 ( V_737 ) )
return - V_531 ;
V_738 = F_570 ( V_737 ) ;
if ( V_738 & V_740 )
V_739 = 1 ;
V_7 = V_337 ;
V_29 = F_278 ( V_37 , V_7 , 0 , 0 , & V_96 ) ;
if ( V_29 )
goto V_82;
if ( V_739 ) {
V_7 = V_55 | V_336 ;
V_29 = F_278 ( V_37 , V_7 , 0 , 0 , & V_96 ) ;
} else {
V_7 = V_55 ;
V_29 = F_278 ( V_37 , V_7 , 0 , 0 , & V_96 ) ;
if ( V_29 )
goto V_82;
V_7 = V_336 ;
V_29 = F_278 ( V_37 , V_7 , 0 , 0 , & V_96 ) ;
}
V_82:
return V_29 ;
}
int F_571 ( struct V_34 * V_35 , T_2 V_32 , T_2 V_31 )
{
return F_397 ( V_35 , V_32 , V_31 , false ) ;
}
static int F_572 ( struct V_695 * V_696 ,
T_2 V_741 , T_2 * V_555 )
{
T_2 V_32 = 0 , V_49 = 0 ;
int V_29 ;
* V_555 = 0 ;
if ( ! V_696 -> V_742 )
return 0 ;
if ( V_696 -> V_338 <= V_696 -> V_95 )
return 0 ;
V_29 = 0 ;
while ( 1 ) {
struct V_12 * V_37 = V_696 -> V_497 -> V_37 ;
struct V_318 * V_118 ;
T_2 V_212 ;
V_29 = F_573 ( & V_37 -> V_416 ) ;
if ( V_29 )
return V_29 ;
F_50 ( & V_37 -> V_85 ) ;
F_11 ( & V_37 -> V_743 ) ;
V_118 = V_37 -> V_744 ;
if ( V_118 )
F_5 ( & V_118 -> V_745 ) ;
F_13 ( & V_37 -> V_743 ) ;
V_29 = F_574 ( V_118 , V_696 , V_741 , V_32 ,
& V_32 , & V_49 ) ;
if ( V_118 )
F_575 ( V_118 ) ;
if ( V_29 ) {
F_46 ( & V_37 -> V_85 ) ;
F_47 ( & V_37 -> V_416 ) ;
if ( V_29 == - V_314 )
V_29 = 0 ;
break;
}
V_29 = F_148 ( V_696 -> V_195 , V_32 , V_49 , & V_212 ) ;
F_46 ( & V_37 -> V_85 ) ;
F_47 ( & V_37 -> V_416 ) ;
if ( V_29 )
break;
V_32 += V_49 ;
* V_555 += V_212 ;
if ( F_576 ( V_396 ) ) {
V_29 = - V_746 ;
break;
}
F_48 () ;
}
return V_29 ;
}
int F_577 ( struct V_34 * V_35 , struct V_747 * V_748 )
{
struct V_12 * V_37 = V_35 -> V_37 ;
struct V_1 * V_2 = NULL ;
struct V_695 * V_696 ;
struct V_112 * V_749 ;
T_2 V_750 ;
T_2 V_32 ;
T_2 V_31 ;
T_2 V_555 = 0 ;
T_2 V_338 = F_310 ( V_37 -> V_261 ) ;
int V_29 = 0 ;
if ( V_748 -> V_49 == V_338 )
V_2 = F_75 ( V_37 , V_748 -> V_32 ) ;
else
V_2 = F_76 ( V_37 , V_748 -> V_32 ) ;
while ( V_2 ) {
if ( V_2 -> V_21 . V_22 >= ( V_748 -> V_32 + V_748 -> V_49 ) ) {
F_6 ( V_2 ) ;
break;
}
V_32 = F_426 ( V_748 -> V_32 , V_2 -> V_21 . V_22 ) ;
V_31 = F_330 ( V_748 -> V_32 + V_748 -> V_49 ,
V_2 -> V_21 . V_22 + V_2 -> V_21 . V_33 ) ;
if ( V_31 - V_32 >= V_748 -> V_741 ) {
if ( ! F_1 ( V_2 ) ) {
V_29 = F_59 ( V_2 , 0 ) ;
if ( V_29 ) {
F_6 ( V_2 ) ;
break;
}
V_29 = F_416 ( V_2 ) ;
if ( V_29 ) {
F_6 ( V_2 ) ;
break;
}
}
V_29 = F_578 ( V_2 ,
& V_750 ,
V_32 ,
V_31 ,
V_748 -> V_741 ) ;
V_555 += V_750 ;
if ( V_29 ) {
F_6 ( V_2 ) ;
break;
}
}
V_2 = F_249 ( V_37 -> V_89 , V_2 ) ;
}
F_49 ( & V_35 -> V_37 -> V_379 -> V_751 ) ;
V_749 = & V_35 -> V_37 -> V_379 -> V_752 ;
F_181 (device, devices, dev_alloc_list) {
V_29 = F_572 ( V_696 , V_748 -> V_741 ,
& V_750 ) ;
if ( V_29 )
break;
V_555 += V_750 ;
}
F_47 ( & V_35 -> V_37 -> V_379 -> V_751 ) ;
V_748 -> V_49 = V_555 ;
return V_29 ;
}
void F_579 ( struct V_34 * V_35 )
{
F_580 ( & V_35 -> V_753 -> V_754 ) ;
F_2 () ;
if ( F_581 ( & V_35 -> V_753 -> V_91 ) )
F_52 ( & V_35 -> V_753 -> V_91 ) ;
}
int F_582 ( struct V_34 * V_35 )
{
if ( F_209 ( & V_35 -> V_755 ) )
return 0 ;
F_583 ( & V_35 -> V_753 -> V_754 ) ;
F_2 () ;
if ( F_209 ( & V_35 -> V_755 ) ) {
F_579 ( V_35 ) ;
return 0 ;
}
return 1 ;
}
static int F_584 ( T_7 * V_756 )
{
F_68 () ;
return 0 ;
}
void F_585 ( struct V_34 * V_35 )
{
while ( true ) {
int V_29 ;
V_29 = F_582 ( V_35 ) ;
if ( V_29 )
break;
F_586 ( & V_35 -> V_755 ,
F_584 ,
V_102 ) ;
}
}
