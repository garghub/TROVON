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
F_13 ( & V_12 -> V_17 ) ;
return 0 ;
}
static struct V_1 *
F_16 ( struct V_11 * V_12 , T_2 V_25 ,
int V_26 )
{
struct V_1 * V_2 , * V_27 = NULL ;
struct V_14 * V_28 ;
T_2 V_29 , V_30 ;
F_11 ( & V_12 -> V_17 ) ;
V_28 = V_12 -> V_18 . V_14 ;
while ( V_28 ) {
V_2 = F_12 ( V_28 , struct V_1 ,
V_19 ) ;
V_29 = V_2 -> V_20 . V_21 + V_2 -> V_20 . V_31 - 1 ;
V_30 = V_2 -> V_20 . V_21 ;
if ( V_25 < V_30 ) {
if ( ! V_26 && ( ! V_27 || V_30 < V_27 -> V_20 . V_21 ) )
V_27 = V_2 ;
V_28 = V_28 -> V_22 ;
} else if ( V_25 > V_30 ) {
if ( V_26 && V_25 <= V_29 ) {
V_27 = V_2 ;
break;
}
V_28 = V_28 -> V_23 ;
} else {
V_27 = V_2 ;
break;
}
}
if ( V_27 )
F_4 ( V_27 ) ;
F_13 ( & V_12 -> V_17 ) ;
return V_27 ;
}
static int F_17 ( struct V_32 * V_33 ,
T_2 V_30 , T_2 V_34 )
{
T_2 V_29 = V_30 + V_34 - 1 ;
F_18 ( & V_33 -> V_35 -> V_36 [ 0 ] ,
V_30 , V_29 , V_37 , V_38 ) ;
F_18 ( & V_33 -> V_35 -> V_36 [ 1 ] ,
V_30 , V_29 , V_37 , V_38 ) ;
return 0 ;
}
static void F_19 ( struct V_32 * V_33 ,
struct V_1 * V_2 )
{
T_2 V_30 , V_29 ;
V_30 = V_2 -> V_20 . V_21 ;
V_29 = V_30 + V_2 -> V_20 . V_31 - 1 ;
F_20 ( & V_33 -> V_35 -> V_36 [ 0 ] ,
V_30 , V_29 , V_37 , V_38 ) ;
F_20 ( & V_33 -> V_35 -> V_36 [ 1 ] ,
V_30 , V_29 , V_37 , V_38 ) ;
}
static int F_21 ( struct V_32 * V_33 ,
struct V_1 * V_2 )
{
T_2 V_25 ;
T_2 * V_39 ;
int V_40 ;
int V_41 , V_42 , V_27 ;
if ( V_2 -> V_20 . V_21 < V_43 ) {
V_40 = V_43 - V_2 -> V_20 . V_21 ;
V_2 -> V_44 += V_40 ;
V_27 = F_17 ( V_33 , V_2 -> V_20 . V_21 ,
V_40 ) ;
F_22 ( V_27 ) ;
}
for ( V_41 = 0 ; V_41 < V_45 ; V_41 ++ ) {
V_25 = F_23 ( V_41 ) ;
V_27 = F_24 ( & V_33 -> V_35 -> V_46 ,
V_2 -> V_20 . V_21 , V_25 ,
0 , & V_39 , & V_42 , & V_40 ) ;
F_22 ( V_27 ) ;
while ( V_42 -- ) {
V_2 -> V_44 += V_40 ;
V_27 = F_17 ( V_33 , V_39 [ V_42 ] ,
V_40 ) ;
F_22 ( V_27 ) ;
}
F_9 ( V_39 ) ;
}
return 0 ;
}
static struct V_47 *
F_25 ( struct V_1 * V_2 )
{
struct V_47 * V_48 ;
F_11 ( & V_2 -> V_49 ) ;
if ( V_2 -> V_3 != V_50 ) {
F_13 ( & V_2 -> V_49 ) ;
return NULL ;
}
if ( ! V_2 -> V_51 ) {
F_13 ( & V_2 -> V_49 ) ;
return NULL ;
}
V_48 = V_2 -> V_51 ;
F_5 ( & V_48 -> V_7 ) ;
F_13 ( & V_2 -> V_49 ) ;
return V_48 ;
}
static void F_26 ( struct V_47 * V_48 )
{
if ( F_7 ( & V_48 -> V_7 ) )
F_9 ( V_48 ) ;
}
static T_2 F_27 ( struct V_1 * V_13 ,
struct V_11 * V_12 , T_2 V_30 , T_2 V_29 )
{
T_2 V_52 , V_53 , V_54 , V_55 = 0 ;
int V_27 ;
while ( V_30 < V_29 ) {
V_27 = F_28 ( V_12 -> V_56 , V_30 ,
& V_52 , & V_53 ,
V_57 | V_37 ) ;
if ( V_27 )
break;
if ( V_52 <= V_30 ) {
V_30 = V_53 + 1 ;
} else if ( V_52 > V_30 && V_52 < V_29 ) {
V_54 = V_52 - V_30 ;
V_55 += V_54 ;
V_27 = F_29 ( V_13 , V_30 ,
V_54 ) ;
F_22 ( V_27 ) ;
V_30 = V_53 + 1 ;
} else {
break;
}
}
if ( V_30 < V_29 ) {
V_54 = V_29 - V_30 ;
V_55 += V_54 ;
V_27 = F_29 ( V_13 , V_30 , V_54 ) ;
F_22 ( V_27 ) ;
}
return V_55 ;
}
static T_1 void F_30 ( struct V_58 * V_59 )
{
struct V_1 * V_13 ;
struct V_11 * V_35 ;
struct V_47 * V_51 ;
struct V_32 * V_60 ;
struct V_61 * V_62 ;
struct V_63 * V_64 ;
struct V_65 V_20 ;
T_2 V_66 = 0 ;
T_2 V_67 = 0 ;
T_3 V_68 ;
int V_27 = 0 ;
V_51 = F_31 ( V_59 , struct V_47 , V_59 ) ;
V_13 = V_51 -> V_13 ;
V_35 = V_13 -> V_35 ;
V_60 = V_35 -> V_60 ;
V_62 = F_32 () ;
if ( ! V_62 )
goto V_69;
V_67 = F_33 ( T_2 , V_13 -> V_20 . V_21 , V_43 ) ;
V_62 -> V_70 = 1 ;
V_62 -> V_71 = 1 ;
V_62 -> V_72 = 1 ;
V_20 . V_21 = V_67 ;
V_20 . V_31 = 0 ;
V_20 . type = V_73 ;
V_74:
F_34 ( & V_51 -> V_75 ) ;
F_35 ( & V_35 -> V_76 ) ;
V_27 = F_36 ( NULL , V_60 , & V_20 , V_62 , 0 , 0 ) ;
if ( V_27 < 0 )
goto V_77;
V_64 = V_62 -> V_78 [ 0 ] ;
V_68 = F_37 ( V_64 ) ;
while ( 1 ) {
if ( F_38 ( V_35 ) > 1 ) {
V_67 = ( T_2 ) - 1 ;
break;
}
if ( V_62 -> V_79 [ 0 ] < V_68 ) {
F_39 ( V_64 , & V_20 , V_62 -> V_79 [ 0 ] ) ;
} else {
V_27 = F_40 ( V_62 , 0 , & V_20 ) ;
if ( V_27 )
break;
if ( F_41 () ||
F_42 ( V_60 , V_62 ) ) {
V_51 -> V_80 = V_67 ;
F_43 ( V_62 ) ;
F_44 ( & V_35 -> V_76 ) ;
F_45 ( & V_51 -> V_75 ) ;
F_46 () ;
goto V_74;
}
V_64 = V_62 -> V_78 [ 0 ] ;
V_68 = F_37 ( V_64 ) ;
continue;
}
if ( V_20 . V_21 < V_13 -> V_20 . V_21 ) {
V_62 -> V_79 [ 0 ] ++ ;
continue;
}
if ( V_20 . V_21 >= V_13 -> V_20 . V_21 +
V_13 -> V_20 . V_31 )
break;
if ( V_20 . type == V_73 ) {
V_66 += F_27 ( V_13 ,
V_35 , V_67 ,
V_20 . V_21 ) ;
V_67 = V_20 . V_21 + V_20 . V_31 ;
if ( V_66 > ( 1024 * 1024 * 2 ) ) {
V_66 = 0 ;
F_47 ( & V_51 -> V_81 ) ;
}
}
V_62 -> V_79 [ 0 ] ++ ;
}
V_27 = 0 ;
V_66 += F_27 ( V_13 , V_35 , V_67 ,
V_13 -> V_20 . V_21 +
V_13 -> V_20 . V_31 ) ;
V_51 -> V_80 = ( T_2 ) - 1 ;
F_11 ( & V_13 -> V_49 ) ;
V_13 -> V_51 = NULL ;
V_13 -> V_3 = V_4 ;
F_13 ( & V_13 -> V_49 ) ;
V_77:
F_48 ( V_62 ) ;
F_44 ( & V_35 -> V_76 ) ;
F_19 ( V_60 , V_13 ) ;
F_45 ( & V_51 -> V_75 ) ;
V_69:
F_47 ( & V_51 -> V_81 ) ;
F_26 ( V_51 ) ;
F_6 ( V_13 ) ;
}
static int F_49 ( struct V_1 * V_2 ,
struct V_82 * V_83 ,
struct V_32 * V_33 ,
int V_84 )
{
F_50 ( V_81 ) ;
struct V_11 * V_35 = V_2 -> V_35 ;
struct V_47 * V_51 ;
int V_27 = 0 ;
V_51 = F_51 ( sizeof( * V_51 ) , V_38 ) ;
F_22 ( ! V_51 ) ;
F_52 ( & V_51 -> V_85 ) ;
F_53 ( & V_51 -> V_75 ) ;
F_54 ( & V_51 -> V_81 ) ;
V_51 -> V_13 = V_2 ;
V_51 -> V_80 = V_2 -> V_20 . V_21 ;
F_55 ( & V_51 -> V_7 , 1 ) ;
V_51 -> V_59 . V_86 = F_30 ;
F_11 ( & V_2 -> V_49 ) ;
while ( V_2 -> V_3 == V_87 ) {
struct V_47 * V_48 ;
V_48 = V_2 -> V_51 ;
F_5 ( & V_48 -> V_7 ) ;
F_56 ( & V_48 -> V_81 , & V_81 , V_88 ) ;
F_13 ( & V_2 -> V_49 ) ;
F_57 () ;
F_58 ( & V_48 -> V_81 , & V_81 ) ;
F_26 ( V_48 ) ;
F_11 ( & V_2 -> V_49 ) ;
}
if ( V_2 -> V_3 != V_89 ) {
F_13 ( & V_2 -> V_49 ) ;
F_9 ( V_51 ) ;
return 0 ;
}
F_8 ( V_2 -> V_51 ) ;
V_2 -> V_51 = V_51 ;
V_2 -> V_3 = V_87 ;
F_13 ( & V_2 -> V_49 ) ;
if ( V_83 && ( ! V_83 -> V_90 -> V_91 ) &&
( V_33 && V_33 != V_33 -> V_35 -> V_92 ) &&
F_59 ( V_33 , V_93 ) ) {
V_27 = F_60 ( V_35 , V_2 ) ;
F_11 ( & V_2 -> V_49 ) ;
if ( V_27 == 1 ) {
V_2 -> V_51 = NULL ;
V_2 -> V_3 = V_4 ;
V_2 -> V_94 = ( T_2 ) - 1 ;
} else {
if ( V_84 ) {
V_2 -> V_51 = NULL ;
V_2 -> V_3 = V_89 ;
} else {
V_2 -> V_3 = V_50 ;
}
}
F_13 ( & V_2 -> V_49 ) ;
F_47 ( & V_51 -> V_81 ) ;
if ( V_27 == 1 ) {
F_26 ( V_51 ) ;
F_19 ( V_35 -> V_60 , V_2 ) ;
return 0 ;
}
} else {
F_11 ( & V_2 -> V_49 ) ;
if ( V_84 ) {
V_2 -> V_51 = NULL ;
V_2 -> V_3 = V_89 ;
} else {
V_2 -> V_3 = V_50 ;
}
F_13 ( & V_2 -> V_49 ) ;
F_47 ( & V_51 -> V_81 ) ;
}
if ( V_84 ) {
F_26 ( V_51 ) ;
return 0 ;
}
F_61 ( & V_35 -> V_76 ) ;
F_5 ( & V_51 -> V_7 ) ;
F_62 ( & V_51 -> V_85 , & V_35 -> V_95 ) ;
F_63 ( & V_35 -> V_76 ) ;
F_4 ( V_2 ) ;
F_64 ( & V_35 -> V_96 , & V_51 -> V_59 ) ;
return V_27 ;
}
static struct V_1 *
F_65 ( struct V_11 * V_12 , T_2 V_25 )
{
struct V_1 * V_2 ;
V_2 = F_16 ( V_12 , V_25 , 0 ) ;
return V_2 ;
}
struct V_1 * F_66 (
struct V_11 * V_12 ,
T_2 V_25 )
{
struct V_1 * V_2 ;
V_2 = F_16 ( V_12 , V_25 , 1 ) ;
return V_2 ;
}
static struct V_97 * F_67 ( struct V_11 * V_12 ,
T_2 V_6 )
{
struct V_98 * V_99 = & V_12 -> V_100 ;
struct V_97 * V_101 ;
V_6 &= V_102 ;
F_68 () ;
F_69 (found, head, list) {
if ( V_101 -> V_6 & V_6 ) {
F_70 () ;
return V_101 ;
}
}
F_70 () ;
return NULL ;
}
void F_71 ( struct V_11 * V_12 )
{
struct V_98 * V_99 = & V_12 -> V_100 ;
struct V_97 * V_101 ;
F_68 () ;
F_69 (found, head, list)
V_101 -> V_103 = 0 ;
F_70 () ;
}
static T_2 F_72 ( T_2 V_104 , int V_105 )
{
if ( V_105 == 10 )
return V_104 ;
V_104 *= V_105 ;
F_73 ( V_104 , 10 ) ;
return V_104 ;
}
static T_2 F_74 ( T_2 V_104 , int V_105 )
{
if ( V_105 == 100 )
return V_104 ;
V_104 *= V_105 ;
F_73 ( V_104 , 100 ) ;
return V_104 ;
}
T_2 F_75 ( struct V_32 * V_33 ,
T_2 V_106 , T_2 V_107 , int V_108 )
{
struct V_1 * V_2 ;
T_2 V_109 ;
T_2 V_67 = F_76 ( V_107 , V_106 ) ;
T_2 V_110 = 0 ;
int V_111 = 0 ;
int V_105 = 9 ;
int V_112 = 0 ;
V_74:
while ( 1 ) {
V_2 = F_65 ( V_33 -> V_35 , V_67 ) ;
if ( ! V_2 )
break;
F_11 ( & V_2 -> V_49 ) ;
V_67 = V_2 -> V_20 . V_21 + V_2 -> V_20 . V_31 ;
V_109 = F_77 ( & V_2 -> V_113 ) ;
if ( ( V_111 || ! V_2 -> V_114 ) &&
F_3 ( V_2 , V_115 ) ) {
if ( V_109 + V_2 -> V_8 + V_2 -> V_9 <
F_72 ( V_2 -> V_20 . V_31 , V_105 ) ) {
V_110 = V_2 -> V_20 . V_21 ;
F_13 ( & V_2 -> V_49 ) ;
F_6 ( V_2 ) ;
goto V_101;
}
}
F_13 ( & V_2 -> V_49 ) ;
F_6 ( V_2 ) ;
F_46 () ;
}
if ( ! V_112 ) {
V_67 = V_106 ;
V_112 = 1 ;
goto V_74;
}
if ( ! V_111 && V_105 < 10 ) {
V_67 = V_106 ;
V_111 = 1 ;
V_105 = 10 ;
goto V_74;
}
V_101:
return V_110 ;
}
int F_78 ( struct V_32 * V_33 , T_2 V_30 , T_2 V_116 )
{
int V_27 ;
struct V_65 V_20 ;
struct V_61 * V_62 ;
V_62 = F_32 () ;
if ( ! V_62 )
return - V_117 ;
V_20 . V_21 = V_30 ;
V_20 . V_31 = V_116 ;
F_79 ( & V_20 , V_73 ) ;
V_27 = F_36 ( NULL , V_33 -> V_35 -> V_60 , & V_20 , V_62 ,
0 , 0 ) ;
F_48 ( V_62 ) ;
return V_27 ;
}
int F_80 ( struct V_82 * V_83 ,
struct V_32 * V_33 , T_2 V_25 ,
T_2 V_34 , T_2 * V_118 , T_2 * V_6 )
{
struct V_119 * V_99 ;
struct V_120 * V_121 ;
struct V_61 * V_62 ;
struct V_122 * V_123 ;
struct V_63 * V_64 ;
struct V_65 V_20 ;
T_3 V_124 ;
T_2 V_125 ;
T_2 V_126 ;
int V_27 ;
V_62 = F_32 () ;
if ( ! V_62 )
return - V_117 ;
V_20 . V_21 = V_25 ;
V_20 . type = V_73 ;
V_20 . V_31 = V_34 ;
if ( ! V_83 ) {
V_62 -> V_70 = 1 ;
V_62 -> V_71 = 1 ;
}
V_74:
V_27 = F_36 ( V_83 , V_33 -> V_35 -> V_60 ,
& V_20 , V_62 , 0 , 0 ) ;
if ( V_27 < 0 )
goto V_127;
if ( V_27 == 0 ) {
V_64 = V_62 -> V_78 [ 0 ] ;
V_124 = F_81 ( V_64 , V_62 -> V_79 [ 0 ] ) ;
if ( V_124 >= sizeof( * V_123 ) ) {
V_123 = F_82 ( V_64 , V_62 -> V_79 [ 0 ] ,
struct V_122 ) ;
V_125 = F_83 ( V_64 , V_123 ) ;
V_126 = F_84 ( V_64 , V_123 ) ;
} else {
#ifdef F_85
struct V_128 * V_129 ;
F_22 ( V_124 != sizeof( * V_129 ) ) ;
V_129 = F_82 ( V_64 , V_62 -> V_79 [ 0 ] ,
struct V_128 ) ;
V_125 = F_86 ( V_64 , V_129 ) ;
V_126 = V_130 ;
#else
F_87 () ;
#endif
}
F_22 ( V_125 == 0 ) ;
} else {
V_125 = 0 ;
V_126 = 0 ;
V_27 = 0 ;
}
if ( ! V_83 )
goto V_69;
V_121 = & V_83 -> V_90 -> V_121 ;
F_11 ( & V_121 -> V_49 ) ;
V_99 = F_88 ( V_83 , V_25 ) ;
if ( V_99 ) {
if ( ! F_89 ( & V_99 -> V_75 ) ) {
F_5 ( & V_99 -> V_131 . V_118 ) ;
F_13 ( & V_121 -> V_49 ) ;
F_43 ( V_62 ) ;
F_34 ( & V_99 -> V_75 ) ;
F_45 ( & V_99 -> V_75 ) ;
F_90 ( & V_99 -> V_131 ) ;
goto V_74;
}
if ( V_99 -> V_132 && V_99 -> V_132 -> V_133 )
V_126 |= V_99 -> V_132 -> V_134 ;
else
F_22 ( V_125 == 0 ) ;
V_125 += V_99 -> V_131 . V_135 ;
F_45 ( & V_99 -> V_75 ) ;
}
F_13 ( & V_121 -> V_49 ) ;
V_69:
F_8 ( V_125 == 0 ) ;
if ( V_118 )
* V_118 = V_125 ;
if ( V_6 )
* V_6 = V_126 ;
V_127:
F_48 ( V_62 ) ;
return V_27 ;
}
static int F_91 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_61 * V_62 ,
T_2 V_108 , T_3 V_136 )
{
struct V_122 * V_113 ;
struct V_128 * V_129 ;
struct V_137 * V_138 ;
struct V_139 * V_140 ;
struct V_63 * V_64 ;
struct V_65 V_20 ;
struct V_65 V_141 ;
T_3 V_142 = sizeof( * V_113 ) ;
T_2 V_118 ;
int V_27 ;
V_64 = V_62 -> V_78 [ 0 ] ;
F_22 ( F_81 ( V_64 , V_62 -> V_79 [ 0 ] ) != sizeof( * V_129 ) ) ;
F_39 ( V_64 , & V_20 , V_62 -> V_79 [ 0 ] ) ;
V_129 = F_82 ( V_64 , V_62 -> V_79 [ 0 ] ,
struct V_128 ) ;
V_118 = F_86 ( V_64 , V_129 ) ;
if ( V_108 == ( T_2 ) - 1 ) {
while ( 1 ) {
if ( V_62 -> V_79 [ 0 ] >= F_37 ( V_64 ) ) {
V_27 = F_42 ( V_33 , V_62 ) ;
if ( V_27 < 0 )
return V_27 ;
F_22 ( V_27 > 0 ) ;
V_64 = V_62 -> V_78 [ 0 ] ;
}
F_39 ( V_64 , & V_141 ,
V_62 -> V_79 [ 0 ] ) ;
F_22 ( V_20 . V_21 != V_141 . V_21 ) ;
if ( V_141 . type != V_143 ) {
V_62 -> V_79 [ 0 ] ++ ;
continue;
}
V_138 = F_82 ( V_64 , V_62 -> V_79 [ 0 ] ,
struct V_137 ) ;
V_108 = F_92 ( V_64 , V_138 ) ;
break;
}
}
F_43 ( V_62 ) ;
if ( V_108 < V_144 )
V_142 += sizeof( * V_140 ) ;
V_142 -= sizeof( * V_129 ) ;
V_27 = F_36 ( V_83 , V_33 , & V_20 , V_62 ,
V_142 + V_136 , 1 ) ;
if ( V_27 < 0 )
return V_27 ;
F_22 ( V_27 ) ;
V_27 = F_93 ( V_83 , V_33 , V_62 , V_142 ) ;
V_64 = V_62 -> V_78 [ 0 ] ;
V_113 = F_82 ( V_64 , V_62 -> V_79 [ 0 ] , struct V_122 ) ;
F_94 ( V_64 , V_113 , V_118 ) ;
F_95 ( V_64 , V_113 , 0 ) ;
if ( V_108 < V_144 ) {
F_96 ( V_64 , V_113 ,
V_145 |
V_130 ) ;
V_140 = (struct V_139 * ) ( V_113 + 1 ) ;
F_97 ( V_64 , 0 , ( unsigned long ) V_140 , sizeof( * V_140 ) ) ;
F_98 ( V_64 , V_140 , ( int ) V_108 ) ;
} else {
F_96 ( V_64 , V_113 , V_146 ) ;
}
F_99 ( V_64 ) ;
return 0 ;
}
static T_2 F_100 ( T_2 V_147 , T_2 V_108 , T_2 V_31 )
{
T_3 V_148 = ~ ( T_3 ) 0 ;
T_3 V_149 = ~ ( T_3 ) 0 ;
T_4 V_150 ;
V_150 = F_101 ( V_147 ) ;
V_148 = F_102 ( V_148 , & V_150 , sizeof( V_150 ) ) ;
V_150 = F_101 ( V_108 ) ;
V_149 = F_102 ( V_149 , & V_150 , sizeof( V_150 ) ) ;
V_150 = F_101 ( V_31 ) ;
V_149 = F_102 ( V_149 , & V_150 , sizeof( V_150 ) ) ;
return ( ( T_2 ) V_148 << 31 ) ^ ( T_2 ) V_149 ;
}
static T_2 F_103 ( struct V_63 * V_64 ,
struct V_151 * V_152 )
{
return F_100 ( F_104 ( V_64 , V_152 ) ,
F_105 ( V_64 , V_152 ) ,
F_106 ( V_64 , V_152 ) ) ;
}
static int F_107 ( struct V_63 * V_64 ,
struct V_151 * V_152 ,
T_2 V_147 , T_2 V_108 , T_2 V_31 )
{
if ( F_104 ( V_64 , V_152 ) != V_147 ||
F_105 ( V_64 , V_152 ) != V_108 ||
F_106 ( V_64 , V_152 ) != V_31 )
return 0 ;
return 1 ;
}
static T_1 int F_108 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_61 * V_62 ,
T_2 V_25 , T_2 V_16 ,
T_2 V_147 ,
T_2 V_108 , T_2 V_31 )
{
struct V_65 V_20 ;
struct V_151 * V_152 ;
struct V_63 * V_64 ;
T_3 V_68 ;
int V_27 ;
int V_153 ;
int V_77 = - V_154 ;
V_20 . V_21 = V_25 ;
if ( V_16 ) {
V_20 . type = V_155 ;
V_20 . V_31 = V_16 ;
} else {
V_20 . type = V_156 ;
V_20 . V_31 = F_100 ( V_147 ,
V_108 , V_31 ) ;
}
V_74:
V_153 = 0 ;
V_27 = F_36 ( V_83 , V_33 , & V_20 , V_62 , - 1 , 1 ) ;
if ( V_27 < 0 ) {
V_77 = V_27 ;
goto V_157;
}
if ( V_16 ) {
if ( ! V_27 )
return 0 ;
#ifdef F_85
V_20 . type = V_143 ;
F_43 ( V_62 ) ;
V_27 = F_36 ( V_83 , V_33 , & V_20 , V_62 , - 1 , 1 ) ;
if ( V_27 < 0 ) {
V_77 = V_27 ;
goto V_157;
}
if ( ! V_27 )
return 0 ;
#endif
goto V_157;
}
V_64 = V_62 -> V_78 [ 0 ] ;
V_68 = F_37 ( V_64 ) ;
while ( 1 ) {
if ( V_62 -> V_79 [ 0 ] >= V_68 ) {
V_27 = F_42 ( V_33 , V_62 ) ;
if ( V_27 < 0 )
V_77 = V_27 ;
if ( V_27 )
goto V_157;
V_64 = V_62 -> V_78 [ 0 ] ;
V_68 = F_37 ( V_64 ) ;
V_153 = 1 ;
}
F_39 ( V_64 , & V_20 , V_62 -> V_79 [ 0 ] ) ;
if ( V_20 . V_21 != V_25 ||
V_20 . type != V_156 )
goto V_157;
V_152 = F_82 ( V_64 , V_62 -> V_79 [ 0 ] ,
struct V_151 ) ;
if ( F_107 ( V_64 , V_152 , V_147 ,
V_108 , V_31 ) ) {
if ( V_153 ) {
F_43 ( V_62 ) ;
goto V_74;
}
V_77 = 0 ;
break;
}
V_62 -> V_79 [ 0 ] ++ ;
}
V_157:
return V_77 ;
}
static T_1 int F_109 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_61 * V_62 ,
T_2 V_25 , T_2 V_16 ,
T_2 V_147 , T_2 V_108 ,
T_2 V_31 , int V_158 )
{
struct V_65 V_20 ;
struct V_63 * V_64 ;
T_3 V_54 ;
T_3 V_125 ;
int V_27 ;
V_20 . V_21 = V_25 ;
if ( V_16 ) {
V_20 . type = V_155 ;
V_20 . V_31 = V_16 ;
V_54 = sizeof( struct V_159 ) ;
} else {
V_20 . type = V_156 ;
V_20 . V_31 = F_100 ( V_147 ,
V_108 , V_31 ) ;
V_54 = sizeof( struct V_151 ) ;
}
V_27 = F_110 ( V_83 , V_33 , V_62 , & V_20 , V_54 ) ;
if ( V_27 && V_27 != - V_24 )
goto V_157;
V_64 = V_62 -> V_78 [ 0 ] ;
if ( V_16 ) {
struct V_159 * V_152 ;
V_152 = F_82 ( V_64 , V_62 -> V_79 [ 0 ] ,
struct V_159 ) ;
if ( V_27 == 0 ) {
F_111 ( V_64 , V_152 , V_158 ) ;
} else {
V_125 = F_112 ( V_64 , V_152 ) ;
V_125 += V_158 ;
F_111 ( V_64 , V_152 , V_125 ) ;
}
} else {
struct V_151 * V_152 ;
while ( V_27 == - V_24 ) {
V_152 = F_82 ( V_64 , V_62 -> V_79 [ 0 ] ,
struct V_151 ) ;
if ( F_107 ( V_64 , V_152 , V_147 ,
V_108 , V_31 ) )
break;
F_43 ( V_62 ) ;
V_20 . V_31 ++ ;
V_27 = F_110 ( V_83 , V_33 , V_62 , & V_20 ,
V_54 ) ;
if ( V_27 && V_27 != - V_24 )
goto V_157;
V_64 = V_62 -> V_78 [ 0 ] ;
}
V_152 = F_82 ( V_64 , V_62 -> V_79 [ 0 ] ,
struct V_151 ) ;
if ( V_27 == 0 ) {
F_113 ( V_64 , V_152 ,
V_147 ) ;
F_114 ( V_64 , V_152 , V_108 ) ;
F_115 ( V_64 , V_152 , V_31 ) ;
F_116 ( V_64 , V_152 , V_158 ) ;
} else {
V_125 = F_117 ( V_64 , V_152 ) ;
V_125 += V_158 ;
F_116 ( V_64 , V_152 , V_125 ) ;
}
}
F_99 ( V_64 ) ;
V_27 = 0 ;
V_157:
F_43 ( V_62 ) ;
return V_27 ;
}
static T_1 int F_118 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_61 * V_62 ,
int V_160 )
{
struct V_65 V_20 ;
struct V_151 * V_161 = NULL ;
struct V_159 * V_162 = NULL ;
struct V_63 * V_64 ;
T_3 V_125 = 0 ;
int V_27 = 0 ;
V_64 = V_62 -> V_78 [ 0 ] ;
F_39 ( V_64 , & V_20 , V_62 -> V_79 [ 0 ] ) ;
if ( V_20 . type == V_156 ) {
V_161 = F_82 ( V_64 , V_62 -> V_79 [ 0 ] ,
struct V_151 ) ;
V_125 = F_117 ( V_64 , V_161 ) ;
} else if ( V_20 . type == V_155 ) {
V_162 = F_82 ( V_64 , V_62 -> V_79 [ 0 ] ,
struct V_159 ) ;
V_125 = F_112 ( V_64 , V_162 ) ;
#ifdef F_85
} else if ( V_20 . type == V_143 ) {
struct V_137 * V_138 ;
V_138 = F_82 ( V_64 , V_62 -> V_79 [ 0 ] ,
struct V_137 ) ;
V_125 = F_119 ( V_64 , V_138 ) ;
#endif
} else {
F_87 () ;
}
F_22 ( V_125 < V_160 ) ;
V_125 -= V_160 ;
if ( V_125 == 0 ) {
V_27 = F_120 ( V_83 , V_33 , V_62 ) ;
} else {
if ( V_20 . type == V_156 )
F_116 ( V_64 , V_161 , V_125 ) ;
else if ( V_20 . type == V_155 )
F_111 ( V_64 , V_162 , V_125 ) ;
#ifdef F_85
else {
struct V_137 * V_138 ;
V_138 = F_82 ( V_64 , V_62 -> V_79 [ 0 ] ,
struct V_137 ) ;
F_121 ( V_64 , V_138 , V_125 ) ;
}
#endif
F_99 ( V_64 ) ;
}
return V_27 ;
}
static T_1 T_3 F_122 ( struct V_32 * V_33 ,
struct V_61 * V_62 ,
struct V_163 * V_164 )
{
struct V_65 V_20 ;
struct V_63 * V_64 ;
struct V_151 * V_161 ;
struct V_159 * V_162 ;
T_3 V_125 = 0 ;
V_64 = V_62 -> V_78 [ 0 ] ;
F_39 ( V_64 , & V_20 , V_62 -> V_79 [ 0 ] ) ;
if ( V_164 ) {
if ( F_123 ( V_64 , V_164 ) ==
V_156 ) {
V_161 = (struct V_151 * ) ( & V_164 -> V_31 ) ;
V_125 = F_117 ( V_64 , V_161 ) ;
} else {
V_162 = (struct V_159 * ) ( V_164 + 1 ) ;
V_125 = F_112 ( V_64 , V_162 ) ;
}
} else if ( V_20 . type == V_156 ) {
V_161 = F_82 ( V_64 , V_62 -> V_79 [ 0 ] ,
struct V_151 ) ;
V_125 = F_117 ( V_64 , V_161 ) ;
} else if ( V_20 . type == V_155 ) {
V_162 = F_82 ( V_64 , V_62 -> V_79 [ 0 ] ,
struct V_159 ) ;
V_125 = F_112 ( V_64 , V_162 ) ;
#ifdef F_85
} else if ( V_20 . type == V_143 ) {
struct V_137 * V_138 ;
V_138 = F_82 ( V_64 , V_62 -> V_79 [ 0 ] ,
struct V_137 ) ;
V_125 = F_119 ( V_64 , V_138 ) ;
#endif
} else {
F_8 ( 1 ) ;
}
return V_125 ;
}
static T_1 int F_124 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_61 * V_62 ,
T_2 V_25 , T_2 V_16 ,
T_2 V_147 )
{
struct V_65 V_20 ;
int V_27 ;
V_20 . V_21 = V_25 ;
if ( V_16 ) {
V_20 . type = V_165 ;
V_20 . V_31 = V_16 ;
} else {
V_20 . type = V_166 ;
V_20 . V_31 = V_147 ;
}
V_27 = F_36 ( V_83 , V_33 , & V_20 , V_62 , - 1 , 1 ) ;
if ( V_27 > 0 )
V_27 = - V_154 ;
#ifdef F_85
if ( V_27 == - V_154 && V_16 ) {
F_43 ( V_62 ) ;
V_20 . type = V_143 ;
V_27 = F_36 ( V_83 , V_33 , & V_20 , V_62 , - 1 , 1 ) ;
if ( V_27 > 0 )
V_27 = - V_154 ;
}
#endif
return V_27 ;
}
static T_1 int F_125 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_61 * V_62 ,
T_2 V_25 , T_2 V_16 ,
T_2 V_147 )
{
struct V_65 V_20 ;
int V_27 ;
V_20 . V_21 = V_25 ;
if ( V_16 ) {
V_20 . type = V_165 ;
V_20 . V_31 = V_16 ;
} else {
V_20 . type = V_166 ;
V_20 . V_31 = V_147 ;
}
V_27 = F_110 ( V_83 , V_33 , V_62 , & V_20 , 0 ) ;
F_43 ( V_62 ) ;
return V_27 ;
}
static inline int F_126 ( T_2 V_16 , T_2 V_108 )
{
int type ;
if ( V_108 < V_144 ) {
if ( V_16 > 0 )
type = V_165 ;
else
type = V_166 ;
} else {
if ( V_16 > 0 )
type = V_155 ;
else
type = V_156 ;
}
return type ;
}
static int F_40 ( struct V_61 * V_62 , int V_167 ,
struct V_65 * V_20 )
{
for (; V_167 < V_168 ; V_167 ++ ) {
if ( ! V_62 -> V_78 [ V_167 ] )
break;
if ( V_62 -> V_79 [ V_167 ] + 1 >=
F_37 ( V_62 -> V_78 [ V_167 ] ) )
continue;
if ( V_167 == 0 )
F_39 ( V_62 -> V_78 [ V_167 ] , V_20 ,
V_62 -> V_79 [ V_167 ] + 1 ) ;
else
F_127 ( V_62 -> V_78 [ V_167 ] , V_20 ,
V_62 -> V_79 [ V_167 ] + 1 ) ;
return 0 ;
}
return 1 ;
}
static T_5
int F_128 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_61 * V_62 ,
struct V_163 * * V_169 ,
T_2 V_25 , T_2 V_34 ,
T_2 V_16 , T_2 V_147 ,
T_2 V_108 , T_2 V_31 , int V_170 )
{
struct V_65 V_20 ;
struct V_63 * V_64 ;
struct V_122 * V_123 ;
struct V_163 * V_164 ;
T_2 V_6 ;
T_2 V_124 ;
unsigned long V_171 ;
unsigned long V_29 ;
int V_136 ;
int type ;
int V_172 ;
int V_27 ;
int V_77 = 0 ;
V_20 . V_21 = V_25 ;
V_20 . type = V_73 ;
V_20 . V_31 = V_34 ;
V_172 = F_126 ( V_16 , V_108 ) ;
if ( V_170 ) {
V_136 = F_129 ( V_172 ) ;
V_62 -> V_173 = 1 ;
} else
V_136 = - 1 ;
V_27 = F_36 ( V_83 , V_33 , & V_20 , V_62 , V_136 , 1 ) ;
if ( V_27 < 0 ) {
V_77 = V_27 ;
goto V_69;
}
F_22 ( V_27 ) ;
V_64 = V_62 -> V_78 [ 0 ] ;
V_124 = F_81 ( V_64 , V_62 -> V_79 [ 0 ] ) ;
#ifdef F_85
if ( V_124 < sizeof( * V_123 ) ) {
if ( ! V_170 ) {
V_77 = - V_154 ;
goto V_69;
}
V_27 = F_91 ( V_83 , V_33 , V_62 , V_108 ,
V_136 ) ;
if ( V_27 < 0 ) {
V_77 = V_27 ;
goto V_69;
}
V_64 = V_62 -> V_78 [ 0 ] ;
V_124 = F_81 ( V_64 , V_62 -> V_79 [ 0 ] ) ;
}
#endif
F_22 ( V_124 < sizeof( * V_123 ) ) ;
V_123 = F_82 ( V_64 , V_62 -> V_79 [ 0 ] , struct V_122 ) ;
V_6 = F_84 ( V_64 , V_123 ) ;
V_171 = ( unsigned long ) ( V_123 + 1 ) ;
V_29 = ( unsigned long ) V_123 + V_124 ;
if ( V_6 & V_145 ) {
V_171 += sizeof( struct V_139 ) ;
F_22 ( V_171 > V_29 ) ;
} else {
F_22 ( ! ( V_6 & V_146 ) ) ;
}
V_77 = - V_154 ;
while ( 1 ) {
if ( V_171 >= V_29 ) {
F_8 ( V_171 > V_29 ) ;
break;
}
V_164 = (struct V_163 * ) V_171 ;
type = F_123 ( V_64 , V_164 ) ;
if ( V_172 < type )
break;
if ( V_172 > type ) {
V_171 += F_129 ( type ) ;
continue;
}
if ( type == V_156 ) {
struct V_151 * V_174 ;
V_174 = (struct V_151 * ) ( & V_164 -> V_31 ) ;
if ( F_107 ( V_64 , V_174 , V_147 ,
V_108 , V_31 ) ) {
V_77 = 0 ;
break;
}
if ( F_103 ( V_64 , V_174 ) <
F_100 ( V_147 , V_108 , V_31 ) )
break;
} else {
T_2 V_175 ;
V_175 = F_130 ( V_64 , V_164 ) ;
if ( V_16 > 0 ) {
if ( V_16 == V_175 ) {
V_77 = 0 ;
break;
}
if ( V_175 < V_16 )
break;
} else {
if ( V_147 == V_175 ) {
V_77 = 0 ;
break;
}
if ( V_175 < V_147 )
break;
}
}
V_171 += F_129 ( type ) ;
}
if ( V_77 == - V_154 && V_170 ) {
if ( V_124 + V_136 >=
F_131 ( V_33 ) ) {
V_77 = - V_176 ;
goto V_69;
}
if ( F_40 ( V_62 , 0 , & V_20 ) == 0 &&
V_20 . V_21 == V_25 &&
V_20 . type < V_177 ) {
V_77 = - V_176 ;
goto V_69;
}
}
* V_169 = (struct V_163 * ) V_171 ;
V_69:
if ( V_170 ) {
V_62 -> V_173 = 0 ;
F_132 ( V_62 , 1 ) ;
}
return V_77 ;
}
static T_5
int F_133 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_61 * V_62 ,
struct V_163 * V_164 ,
T_2 V_16 , T_2 V_147 ,
T_2 V_108 , T_2 V_31 , int V_158 ,
struct V_178 * V_132 )
{
struct V_63 * V_64 ;
struct V_122 * V_123 ;
unsigned long V_171 ;
unsigned long V_29 ;
unsigned long V_179 ;
T_2 V_118 ;
int V_54 ;
int type ;
int V_27 ;
V_64 = V_62 -> V_78 [ 0 ] ;
V_123 = F_82 ( V_64 , V_62 -> V_79 [ 0 ] , struct V_122 ) ;
V_179 = ( unsigned long ) V_164 - ( unsigned long ) V_123 ;
type = F_126 ( V_16 , V_108 ) ;
V_54 = F_129 ( type ) ;
V_27 = F_93 ( V_83 , V_33 , V_62 , V_54 ) ;
V_123 = F_82 ( V_64 , V_62 -> V_79 [ 0 ] , struct V_122 ) ;
V_118 = F_83 ( V_64 , V_123 ) ;
V_118 += V_158 ;
F_94 ( V_64 , V_123 , V_118 ) ;
if ( V_132 )
F_134 ( V_132 , V_64 , V_123 ) ;
V_171 = ( unsigned long ) V_123 + V_179 ;
V_29 = ( unsigned long ) V_123 + F_81 ( V_64 , V_62 -> V_79 [ 0 ] ) ;
if ( V_171 < V_29 - V_54 )
F_135 ( V_64 , V_171 + V_54 , V_171 ,
V_29 - V_54 - V_171 ) ;
V_164 = (struct V_163 * ) V_171 ;
F_136 ( V_64 , V_164 , type ) ;
if ( type == V_156 ) {
struct V_151 * V_174 ;
V_174 = (struct V_151 * ) ( & V_164 -> V_31 ) ;
F_113 ( V_64 , V_174 , V_147 ) ;
F_114 ( V_64 , V_174 , V_108 ) ;
F_115 ( V_64 , V_174 , V_31 ) ;
F_116 ( V_64 , V_174 , V_158 ) ;
} else if ( type == V_155 ) {
struct V_159 * V_180 ;
V_180 = (struct V_159 * ) ( V_164 + 1 ) ;
F_111 ( V_64 , V_180 , V_158 ) ;
F_137 ( V_64 , V_164 , V_16 ) ;
} else if ( type == V_165 ) {
F_137 ( V_64 , V_164 , V_16 ) ;
} else {
F_137 ( V_64 , V_164 , V_147 ) ;
}
F_99 ( V_64 ) ;
return 0 ;
}
static int F_138 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_61 * V_62 ,
struct V_163 * * V_169 ,
T_2 V_25 , T_2 V_34 , T_2 V_16 ,
T_2 V_147 , T_2 V_108 , T_2 V_31 )
{
int V_27 ;
V_27 = F_128 ( V_83 , V_33 , V_62 , V_169 ,
V_25 , V_34 , V_16 ,
V_147 , V_108 , V_31 , 0 ) ;
if ( V_27 != - V_154 )
return V_27 ;
F_43 ( V_62 ) ;
* V_169 = NULL ;
if ( V_108 < V_144 ) {
V_27 = F_124 ( V_83 , V_33 , V_62 , V_25 , V_16 ,
V_147 ) ;
} else {
V_27 = F_108 ( V_83 , V_33 , V_62 , V_25 , V_16 ,
V_147 , V_108 , V_31 ) ;
}
return V_27 ;
}
static T_5
int F_139 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_61 * V_62 ,
struct V_163 * V_164 ,
int V_181 ,
struct V_178 * V_132 )
{
struct V_63 * V_64 ;
struct V_122 * V_123 ;
struct V_151 * V_174 = NULL ;
struct V_159 * V_180 = NULL ;
unsigned long V_171 ;
unsigned long V_29 ;
T_3 V_124 ;
int V_54 ;
int type ;
int V_27 ;
T_2 V_118 ;
V_64 = V_62 -> V_78 [ 0 ] ;
V_123 = F_82 ( V_64 , V_62 -> V_79 [ 0 ] , struct V_122 ) ;
V_118 = F_83 ( V_64 , V_123 ) ;
F_8 ( V_181 < 0 && V_118 + V_181 <= 0 ) ;
V_118 += V_181 ;
F_94 ( V_64 , V_123 , V_118 ) ;
if ( V_132 )
F_134 ( V_132 , V_64 , V_123 ) ;
type = F_123 ( V_64 , V_164 ) ;
if ( type == V_156 ) {
V_174 = (struct V_151 * ) ( & V_164 -> V_31 ) ;
V_118 = F_117 ( V_64 , V_174 ) ;
} else if ( type == V_155 ) {
V_180 = (struct V_159 * ) ( V_164 + 1 ) ;
V_118 = F_112 ( V_64 , V_180 ) ;
} else {
V_118 = 1 ;
F_22 ( V_181 != - 1 ) ;
}
F_22 ( V_181 < 0 && V_118 < - V_181 ) ;
V_118 += V_181 ;
if ( V_118 > 0 ) {
if ( type == V_156 )
F_116 ( V_64 , V_174 , V_118 ) ;
else
F_111 ( V_64 , V_180 , V_118 ) ;
} else {
V_54 = F_129 ( type ) ;
V_124 = F_81 ( V_64 , V_62 -> V_79 [ 0 ] ) ;
V_171 = ( unsigned long ) V_164 ;
V_29 = ( unsigned long ) V_123 + V_124 ;
if ( V_171 + V_54 < V_29 )
F_135 ( V_64 , V_171 , V_171 + V_54 ,
V_29 - V_171 - V_54 ) ;
V_124 -= V_54 ;
V_27 = F_140 ( V_83 , V_33 , V_62 , V_124 , 1 ) ;
}
F_99 ( V_64 ) ;
return 0 ;
}
static T_5
int F_141 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_61 * V_62 ,
T_2 V_25 , T_2 V_34 , T_2 V_16 ,
T_2 V_147 , T_2 V_108 ,
T_2 V_31 , int V_158 ,
struct V_178 * V_132 )
{
struct V_163 * V_164 ;
int V_27 ;
V_27 = F_128 ( V_83 , V_33 , V_62 , & V_164 ,
V_25 , V_34 , V_16 ,
V_147 , V_108 , V_31 , 1 ) ;
if ( V_27 == 0 ) {
F_22 ( V_108 < V_144 ) ;
V_27 = F_139 ( V_83 , V_33 , V_62 , V_164 ,
V_158 , V_132 ) ;
} else if ( V_27 == - V_154 ) {
V_27 = F_133 ( V_83 , V_33 , V_62 , V_164 ,
V_16 , V_147 ,
V_108 , V_31 , V_158 ,
V_132 ) ;
}
return V_27 ;
}
static int F_142 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_61 * V_62 ,
T_2 V_25 , T_2 V_16 , T_2 V_147 ,
T_2 V_108 , T_2 V_31 , int V_158 )
{
int V_27 ;
if ( V_108 < V_144 ) {
F_22 ( V_158 != 1 ) ;
V_27 = F_125 ( V_83 , V_33 , V_62 , V_25 ,
V_16 , V_147 ) ;
} else {
V_27 = F_109 ( V_83 , V_33 , V_62 , V_25 ,
V_16 , V_147 ,
V_108 , V_31 , V_158 ) ;
}
return V_27 ;
}
static int F_143 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_61 * V_62 ,
struct V_163 * V_164 ,
int V_160 , int V_182 )
{
int V_27 ;
F_22 ( ! V_182 && V_160 != 1 ) ;
if ( V_164 ) {
V_27 = F_139 ( V_83 , V_33 , V_62 , V_164 ,
- V_160 , NULL ) ;
} else if ( V_182 ) {
V_27 = F_118 ( V_83 , V_33 , V_62 , V_160 ) ;
} else {
V_27 = F_120 ( V_83 , V_33 , V_62 ) ;
}
return V_27 ;
}
static int F_144 ( struct V_183 * V_184 ,
T_2 V_30 , T_2 V_116 )
{
return F_145 ( V_184 , V_30 >> 9 , V_116 >> 9 , V_38 , 0 ) ;
}
static int F_146 ( struct V_32 * V_33 , T_2 V_25 ,
T_2 V_34 , T_2 * V_185 )
{
int V_27 ;
T_2 V_186 = 0 ;
struct V_187 * V_188 = NULL ;
V_27 = F_147 ( & V_33 -> V_35 -> V_46 , V_189 ,
V_25 , & V_34 , & V_188 , 0 ) ;
if ( ! V_27 ) {
struct V_190 * V_191 = V_188 -> V_192 ;
int V_41 ;
for ( V_41 = 0 ; V_41 < V_188 -> V_193 ; V_41 ++ , V_191 ++ ) {
if ( ! V_191 -> V_194 -> V_195 )
continue;
V_27 = F_144 ( V_191 -> V_194 -> V_184 ,
V_191 -> V_196 ,
V_191 -> V_197 ) ;
if ( ! V_27 )
V_186 += V_191 -> V_197 ;
else if ( V_27 != - V_198 )
break;
V_27 = 0 ;
}
F_9 ( V_188 ) ;
}
if ( V_185 )
* V_185 = V_186 ;
return V_27 ;
}
int F_148 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
T_2 V_25 , T_2 V_34 , T_2 V_16 ,
T_2 V_147 , T_2 V_108 , T_2 V_31 , int V_199 )
{
int V_27 ;
struct V_11 * V_35 = V_33 -> V_35 ;
F_22 ( V_108 < V_144 &&
V_147 == V_200 ) ;
if ( V_108 < V_144 ) {
V_27 = F_149 ( V_35 , V_83 , V_25 ,
V_34 ,
V_16 , V_147 , ( int ) V_108 ,
V_201 , NULL , V_199 ) ;
} else {
V_27 = F_150 ( V_35 , V_83 , V_25 ,
V_34 ,
V_16 , V_147 , V_108 , V_31 ,
V_201 , NULL , V_199 ) ;
}
return V_27 ;
}
static int F_151 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
T_2 V_25 , T_2 V_34 ,
T_2 V_16 , T_2 V_147 ,
T_2 V_108 , T_2 V_31 , int V_158 ,
struct V_178 * V_132 )
{
struct V_61 * V_62 ;
struct V_63 * V_64 ;
struct V_122 * V_113 ;
T_2 V_118 ;
int V_27 ;
int V_77 = 0 ;
V_62 = F_32 () ;
if ( ! V_62 )
return - V_117 ;
V_62 -> V_72 = 1 ;
V_62 -> V_202 = 1 ;
V_27 = F_141 ( V_83 , V_33 -> V_35 -> V_60 ,
V_62 , V_25 , V_34 , V_16 ,
V_147 , V_108 , V_31 ,
V_158 , V_132 ) ;
if ( V_27 == 0 )
goto V_69;
if ( V_27 != - V_176 ) {
V_77 = V_27 ;
goto V_69;
}
V_64 = V_62 -> V_78 [ 0 ] ;
V_113 = F_82 ( V_64 , V_62 -> V_79 [ 0 ] , struct V_122 ) ;
V_118 = F_83 ( V_64 , V_113 ) ;
F_94 ( V_64 , V_113 , V_118 + V_158 ) ;
if ( V_132 )
F_134 ( V_132 , V_64 , V_113 ) ;
F_99 ( V_64 ) ;
F_43 ( V_62 ) ;
V_62 -> V_72 = 1 ;
V_62 -> V_202 = 1 ;
V_27 = F_142 ( V_83 , V_33 -> V_35 -> V_60 ,
V_62 , V_25 , V_16 , V_147 ,
V_108 , V_31 , V_158 ) ;
F_22 ( V_27 ) ;
V_69:
F_48 ( V_62 ) ;
return V_77 ;
}
static int F_152 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_203 * V_131 ,
struct V_178 * V_132 ,
int V_204 )
{
int V_27 = 0 ;
struct V_205 * V_152 ;
struct V_65 V_206 ;
T_2 V_16 = 0 ;
T_2 V_207 = 0 ;
T_2 V_6 = 0 ;
V_206 . V_21 = V_131 -> V_25 ;
V_206 . V_31 = V_131 -> V_34 ;
V_206 . type = V_73 ;
V_152 = F_153 ( V_131 ) ;
if ( V_131 -> type == V_155 )
V_16 = V_152 -> V_16 ;
else
V_207 = V_152 -> V_33 ;
if ( V_131 -> V_208 == V_201 && V_204 ) {
if ( V_132 ) {
F_22 ( V_132 -> V_209 ) ;
V_6 |= V_132 -> V_134 ;
}
V_27 = F_154 ( V_83 , V_33 ,
V_16 , V_207 , V_6 ,
V_152 -> V_21 , V_152 -> V_31 ,
& V_206 , V_131 -> V_135 ) ;
} else if ( V_131 -> V_208 == V_201 ) {
V_27 = F_151 ( V_83 , V_33 , V_131 -> V_25 ,
V_131 -> V_34 , V_16 ,
V_207 , V_152 -> V_21 ,
V_152 -> V_31 , V_131 -> V_135 ,
V_132 ) ;
} else if ( V_131 -> V_208 == V_210 ) {
V_27 = F_155 ( V_83 , V_33 , V_131 -> V_25 ,
V_131 -> V_34 , V_16 ,
V_207 , V_152 -> V_21 ,
V_152 -> V_31 , V_131 -> V_135 ,
V_132 ) ;
} else {
F_87 () ;
}
return V_27 ;
}
static void F_134 ( struct V_178 * V_132 ,
struct V_63 * V_64 ,
struct V_122 * V_123 )
{
T_2 V_6 = F_84 ( V_64 , V_123 ) ;
if ( V_132 -> V_133 ) {
V_6 |= V_132 -> V_134 ;
F_96 ( V_64 , V_123 , V_6 ) ;
}
if ( V_132 -> V_209 ) {
struct V_139 * V_140 ;
F_22 ( ! ( V_6 & V_145 ) ) ;
V_140 = (struct V_139 * ) ( V_123 + 1 ) ;
F_156 ( V_64 , V_140 , & V_132 -> V_20 ) ;
}
}
static int F_157 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_203 * V_131 ,
struct V_178 * V_132 )
{
struct V_65 V_20 ;
struct V_61 * V_62 ;
struct V_122 * V_123 ;
struct V_63 * V_64 ;
T_3 V_124 ;
int V_27 ;
int V_77 = 0 ;
V_62 = F_32 () ;
if ( ! V_62 )
return - V_117 ;
V_20 . V_21 = V_131 -> V_25 ;
V_20 . type = V_73 ;
V_20 . V_31 = V_131 -> V_34 ;
V_62 -> V_72 = 1 ;
V_62 -> V_202 = 1 ;
V_27 = F_36 ( V_83 , V_33 -> V_35 -> V_60 , & V_20 ,
V_62 , 0 , 1 ) ;
if ( V_27 < 0 ) {
V_77 = V_27 ;
goto V_69;
}
if ( V_27 > 0 ) {
V_77 = - V_211 ;
goto V_69;
}
V_64 = V_62 -> V_78 [ 0 ] ;
V_124 = F_81 ( V_64 , V_62 -> V_79 [ 0 ] ) ;
#ifdef F_85
if ( V_124 < sizeof( * V_123 ) ) {
V_27 = F_91 ( V_83 , V_33 -> V_35 -> V_60 ,
V_62 , ( T_2 ) - 1 , 0 ) ;
if ( V_27 < 0 ) {
V_77 = V_27 ;
goto V_69;
}
V_64 = V_62 -> V_78 [ 0 ] ;
V_124 = F_81 ( V_64 , V_62 -> V_79 [ 0 ] ) ;
}
#endif
F_22 ( V_124 < sizeof( * V_123 ) ) ;
V_123 = F_82 ( V_64 , V_62 -> V_79 [ 0 ] , struct V_122 ) ;
F_134 ( V_132 , V_64 , V_123 ) ;
F_99 ( V_64 ) ;
V_69:
F_48 ( V_62 ) ;
return V_77 ;
}
static int F_158 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_203 * V_131 ,
struct V_178 * V_132 ,
int V_204 )
{
int V_27 = 0 ;
struct V_212 * V_152 ;
struct V_65 V_206 ;
T_2 V_16 = 0 ;
T_2 V_207 = 0 ;
V_206 . V_21 = V_131 -> V_25 ;
V_206 . V_31 = V_131 -> V_34 ;
V_206 . type = V_73 ;
V_152 = F_159 ( V_131 ) ;
if ( V_131 -> type == V_165 )
V_16 = V_152 -> V_16 ;
else
V_207 = V_152 -> V_33 ;
F_22 ( V_131 -> V_135 != 1 ) ;
if ( V_131 -> V_208 == V_201 && V_204 ) {
F_22 ( ! V_132 || ! V_132 -> V_133 ||
! V_132 -> V_209 ) ;
V_27 = F_160 ( V_83 , V_33 ,
V_16 , V_207 ,
V_132 -> V_134 ,
& V_132 -> V_20 ,
V_152 -> V_167 , & V_206 ) ;
} else if ( V_131 -> V_208 == V_201 ) {
V_27 = F_151 ( V_83 , V_33 , V_131 -> V_25 ,
V_131 -> V_34 , V_16 , V_207 ,
V_152 -> V_167 , 0 , 1 , V_132 ) ;
} else if ( V_131 -> V_208 == V_210 ) {
V_27 = F_155 ( V_83 , V_33 , V_131 -> V_25 ,
V_131 -> V_34 , V_16 , V_207 ,
V_152 -> V_167 , 0 , 1 , V_132 ) ;
} else {
F_87 () ;
}
return V_27 ;
}
static int F_161 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_203 * V_131 ,
struct V_178 * V_132 ,
int V_204 )
{
int V_27 ;
if ( F_162 ( V_131 ) ) {
struct V_119 * V_99 ;
F_22 ( V_132 ) ;
V_99 = F_163 ( V_131 ) ;
if ( V_204 ) {
F_164 ( V_33 , V_131 -> V_25 ,
V_131 -> V_34 , 1 ) ;
if ( V_99 -> V_182 ) {
V_27 = F_165 ( V_83 , V_33 ,
V_131 -> V_25 ,
V_131 -> V_34 ) ;
F_22 ( V_27 ) ;
}
}
F_45 ( & V_99 -> V_75 ) ;
return 0 ;
}
if ( V_131 -> type == V_166 ||
V_131 -> type == V_165 )
V_27 = F_158 ( V_83 , V_33 , V_131 , V_132 ,
V_204 ) ;
else if ( V_131 -> type == V_156 ||
V_131 -> type == V_155 )
V_27 = F_152 ( V_83 , V_33 , V_131 , V_132 ,
V_204 ) ;
else
F_87 () ;
return V_27 ;
}
T_1 int F_166 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_98 * V_213 )
{
struct V_120 * V_121 ;
struct V_203 * V_152 ;
struct V_119 * V_214 = NULL ;
struct V_178 * V_132 ;
int V_27 ;
int V_7 = 0 ;
int V_215 = 0 ;
V_121 = & V_83 -> V_90 -> V_121 ;
while ( 1 ) {
if ( ! V_214 ) {
if ( F_167 ( V_213 ) )
break;
V_214 = F_168 ( V_213 -> V_216 ,
struct V_119 , V_213 ) ;
V_27 = F_169 ( V_83 , V_214 ) ;
if ( V_27 == - V_176 ) {
V_214 = NULL ;
V_7 ++ ;
continue;
}
}
V_152 = F_170 ( V_214 ) ;
if ( V_152 && V_152 -> V_217 &&
F_171 ( V_121 , V_152 -> V_217 ) ) {
F_172 ( & V_214 -> V_213 ) ;
F_45 ( & V_214 -> V_75 ) ;
V_214 = NULL ;
V_121 -> V_218 ++ ;
F_13 ( & V_121 -> V_49 ) ;
F_46 () ;
F_11 ( & V_121 -> V_49 ) ;
continue;
}
V_215 = V_214 -> V_215 ;
V_214 -> V_215 = 0 ;
V_132 = V_214 -> V_132 ;
V_214 -> V_132 = NULL ;
if ( ! V_152 ) {
V_152 = & V_214 -> V_131 ;
if ( V_132 && V_215 ) {
F_9 ( V_132 ) ;
V_132 = NULL ;
}
if ( V_132 ) {
F_13 ( & V_121 -> V_49 ) ;
V_27 = F_157 ( V_83 , V_33 ,
V_152 , V_132 ) ;
F_22 ( V_27 ) ;
F_9 ( V_132 ) ;
goto V_216;
}
F_172 ( & V_214 -> V_213 ) ;
V_214 = NULL ;
}
V_152 -> V_219 = 0 ;
F_173 ( & V_152 -> V_14 , & V_121 -> V_33 ) ;
V_121 -> V_220 -- ;
F_13 ( & V_121 -> V_49 ) ;
V_27 = F_161 ( V_83 , V_33 , V_152 , V_132 ,
V_215 ) ;
F_22 ( V_27 ) ;
F_90 ( V_152 ) ;
F_9 ( V_132 ) ;
V_7 ++ ;
V_216:
F_174 ( V_83 , V_33 -> V_35 -> V_60 ,
2 * 1024 * 1024 ,
F_175 ( V_33 , 0 ) ,
V_221 ) ;
F_46 () ;
F_11 ( & V_121 -> V_49 ) ;
}
return V_7 ;
}
static void F_176 ( struct V_120 * V_121 ,
unsigned long V_125 )
{
struct V_98 * V_222 = V_121 -> V_223 . V_216 ;
F_13 ( & V_121 -> V_49 ) ;
F_177 ( L_1 ,
V_125 , V_222 ) ;
F_178 ( V_121 -> V_224 ,
V_125 != V_121 -> V_220 ||
V_121 -> V_223 . V_216 != V_222 ) ;
F_177 ( L_2 ,
V_121 -> V_220 , V_121 -> V_223 . V_216 ) ;
F_11 ( & V_121 -> V_49 ) ;
}
int F_179 ( struct V_82 * V_83 ,
struct V_32 * V_33 , unsigned long V_7 )
{
struct V_14 * V_131 ;
struct V_120 * V_121 ;
struct V_203 * V_152 ;
struct V_98 V_213 ;
int V_27 ;
T_2 V_225 ;
int V_226 = V_7 == ( unsigned long ) - 1 ;
int V_227 = 0 ;
unsigned long V_125 = 0 ;
int V_228 ;
if ( V_33 == V_33 -> V_35 -> V_60 )
V_33 = V_33 -> V_35 -> V_92 ;
F_174 ( V_83 , V_33 -> V_35 -> V_60 ,
2 * 1024 * 1024 , F_175 ( V_33 , 0 ) ,
V_221 ) ;
V_121 = & V_83 -> V_90 -> V_121 ;
F_52 ( & V_213 ) ;
V_74:
V_228 = 0 ;
F_11 ( & V_121 -> V_49 ) ;
if ( V_7 == 0 ) {
V_7 = V_121 -> V_220 * 2 ;
V_227 = 1 ;
}
while ( 1 ) {
if ( ! ( V_226 || V_227 ) &&
V_121 -> V_218 < 64 )
break;
V_225 = V_121 -> V_229 ;
V_27 = F_180 ( V_83 , & V_213 ,
V_121 -> V_229 ) ;
if ( V_27 )
break;
if ( V_225 >= V_121 -> V_229 ) {
if ( V_228 == 0 ) {
V_228 = 1 ;
V_125 = V_121 -> V_220 ;
} else {
F_176 ( V_121 , V_125 ) ;
V_228 = 0 ;
}
}
V_27 = F_166 ( V_83 , V_33 , & V_213 ) ;
F_22 ( V_27 < 0 ) ;
V_7 -= F_181 (unsigned long, ret, count) ;
if ( V_7 == 0 )
break;
if ( V_27 || V_121 -> V_229 == 0 ) {
V_228 = 0 ;
}
}
if ( V_226 ) {
V_131 = F_182 ( & V_121 -> V_33 ) ;
if ( ! V_131 )
goto V_69;
V_7 = ( unsigned long ) - 1 ;
while ( V_131 ) {
V_152 = F_12 ( V_131 , struct V_203 ,
V_14 ) ;
if ( F_162 ( V_152 ) ) {
struct V_119 * V_99 ;
V_99 = F_163 ( V_152 ) ;
F_5 ( & V_152 -> V_118 ) ;
F_13 ( & V_121 -> V_49 ) ;
F_34 ( & V_99 -> V_75 ) ;
F_45 ( & V_99 -> V_75 ) ;
F_90 ( V_152 ) ;
F_46 () ;
goto V_74;
}
V_131 = F_183 ( V_131 ) ;
}
F_13 ( & V_121 -> V_49 ) ;
F_184 ( 1 ) ;
goto V_74;
}
V_69:
F_13 ( & V_121 -> V_49 ) ;
return 0 ;
}
int F_185 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
T_2 V_25 , T_2 V_34 , T_2 V_6 ,
int V_182 )
{
struct V_178 * V_132 ;
int V_27 ;
V_132 = F_186 ( sizeof( * V_132 ) , V_38 ) ;
if ( ! V_132 )
return - V_117 ;
V_132 -> V_134 = V_6 ;
V_132 -> V_133 = 1 ;
V_132 -> V_209 = 0 ;
V_132 -> V_182 = V_182 ? 1 : 0 ;
V_27 = F_187 ( V_33 -> V_35 , V_83 , V_25 ,
V_34 , V_132 ) ;
if ( V_27 )
F_9 ( V_132 ) ;
return V_27 ;
}
static T_1 int F_188 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_61 * V_62 ,
T_2 V_21 , T_2 V_31 , T_2 V_25 )
{
struct V_119 * V_99 ;
struct V_203 * V_152 ;
struct V_205 * V_230 ;
struct V_120 * V_121 ;
struct V_14 * V_131 ;
int V_27 = 0 ;
V_27 = - V_154 ;
V_121 = & V_83 -> V_90 -> V_121 ;
F_11 ( & V_121 -> V_49 ) ;
V_99 = F_88 ( V_83 , V_25 ) ;
if ( ! V_99 )
goto V_69;
if ( ! F_89 ( & V_99 -> V_75 ) ) {
F_5 ( & V_99 -> V_131 . V_118 ) ;
F_13 ( & V_121 -> V_49 ) ;
F_43 ( V_62 ) ;
F_34 ( & V_99 -> V_75 ) ;
F_45 ( & V_99 -> V_75 ) ;
F_90 ( & V_99 -> V_131 ) ;
return - V_176 ;
}
V_131 = F_189 ( & V_99 -> V_131 . V_14 ) ;
if ( ! V_131 )
goto V_231;
V_152 = F_12 ( V_131 , struct V_203 , V_14 ) ;
if ( V_152 -> V_25 != V_25 )
goto V_231;
V_27 = 1 ;
if ( V_152 -> type != V_156 )
goto V_231;
V_230 = F_153 ( V_152 ) ;
V_131 = F_189 ( V_131 ) ;
if ( V_131 ) {
V_152 = F_12 ( V_131 , struct V_203 , V_14 ) ;
if ( V_152 -> V_25 == V_25 )
goto V_231;
}
if ( V_230 -> V_33 != V_33 -> V_232 . V_21 ||
V_230 -> V_21 != V_21 || V_230 -> V_31 != V_31 )
goto V_231;
V_27 = 0 ;
V_231:
F_45 ( & V_99 -> V_75 ) ;
V_69:
F_13 ( & V_121 -> V_49 ) ;
return V_27 ;
}
static T_1 int F_190 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_61 * V_62 ,
T_2 V_21 , T_2 V_31 , T_2 V_25 )
{
struct V_32 * V_60 = V_33 -> V_35 -> V_60 ;
struct V_63 * V_64 ;
struct V_151 * V_152 ;
struct V_163 * V_164 ;
struct V_122 * V_123 ;
struct V_65 V_20 ;
T_3 V_124 ;
int V_27 ;
V_20 . V_21 = V_25 ;
V_20 . V_31 = ( T_2 ) - 1 ;
V_20 . type = V_73 ;
V_27 = F_36 ( NULL , V_60 , & V_20 , V_62 , 0 , 0 ) ;
if ( V_27 < 0 )
goto V_69;
F_22 ( V_27 == 0 ) ;
V_27 = - V_154 ;
if ( V_62 -> V_79 [ 0 ] == 0 )
goto V_69;
V_62 -> V_79 [ 0 ] -- ;
V_64 = V_62 -> V_78 [ 0 ] ;
F_39 ( V_64 , & V_20 , V_62 -> V_79 [ 0 ] ) ;
if ( V_20 . V_21 != V_25 || V_20 . type != V_73 )
goto V_69;
V_27 = 1 ;
V_124 = F_81 ( V_64 , V_62 -> V_79 [ 0 ] ) ;
#ifdef F_85
if ( V_124 < sizeof( * V_123 ) ) {
F_8 ( V_124 != sizeof( struct V_128 ) ) ;
goto V_69;
}
#endif
V_123 = F_82 ( V_64 , V_62 -> V_79 [ 0 ] , struct V_122 ) ;
if ( V_124 != sizeof( * V_123 ) +
F_129 ( V_156 ) )
goto V_69;
if ( F_191 ( V_64 , V_123 ) <=
F_192 ( & V_33 -> V_233 ) )
goto V_69;
V_164 = (struct V_163 * ) ( V_123 + 1 ) ;
if ( F_123 ( V_64 , V_164 ) !=
V_156 )
goto V_69;
V_152 = (struct V_151 * ) ( & V_164 -> V_31 ) ;
if ( F_83 ( V_64 , V_123 ) !=
F_117 ( V_64 , V_152 ) ||
F_104 ( V_64 , V_152 ) !=
V_33 -> V_232 . V_21 ||
F_105 ( V_64 , V_152 ) != V_21 ||
F_106 ( V_64 , V_152 ) != V_31 )
goto V_69;
V_27 = 0 ;
V_69:
return V_27 ;
}
int F_193 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
T_2 V_21 , T_2 V_31 , T_2 V_25 )
{
struct V_61 * V_62 ;
int V_27 ;
int V_234 ;
V_62 = F_32 () ;
if ( ! V_62 )
return - V_154 ;
do {
V_27 = F_190 ( V_83 , V_33 , V_62 , V_21 ,
V_31 , V_25 ) ;
if ( V_27 && V_27 != - V_154 )
goto V_69;
V_234 = F_188 ( V_83 , V_33 , V_62 , V_21 ,
V_31 , V_25 ) ;
} while ( V_234 == - V_176 );
if ( V_234 && V_234 != - V_154 ) {
V_27 = V_234 ;
goto V_69;
}
if ( V_27 != - V_154 || V_234 != - V_154 )
V_27 = 0 ;
V_69:
F_48 ( V_62 ) ;
if ( V_33 -> V_232 . V_21 == V_235 )
F_8 ( V_27 > 0 ) ;
return V_27 ;
}
static int F_194 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_63 * V_236 ,
int V_237 , int V_238 , int V_199 )
{
T_2 V_25 ;
T_2 V_34 ;
T_2 V_16 ;
T_2 V_207 ;
T_3 V_68 ;
struct V_65 V_20 ;
struct V_239 * V_240 ;
int V_41 ;
int V_167 ;
int V_27 = 0 ;
int (* F_195)( struct V_82 * , struct V_32 * ,
T_2 , T_2 , T_2 , T_2 , T_2 , T_2 , int );
V_207 = F_196 ( V_236 ) ;
V_68 = F_37 ( V_236 ) ;
V_167 = F_197 ( V_236 ) ;
if ( ! V_33 -> V_241 && V_167 == 0 )
return 0 ;
if ( V_238 )
F_195 = F_148 ;
else
F_195 = V_242 ;
if ( V_237 )
V_16 = V_236 -> V_30 ;
else
V_16 = 0 ;
for ( V_41 = 0 ; V_41 < V_68 ; V_41 ++ ) {
if ( V_167 == 0 ) {
F_39 ( V_236 , & V_20 , V_41 ) ;
if ( F_198 ( & V_20 ) != V_243 )
continue;
V_240 = F_82 ( V_236 , V_41 ,
struct V_239 ) ;
if ( F_199 ( V_236 , V_240 ) ==
V_244 )
continue;
V_25 = F_200 ( V_236 , V_240 ) ;
if ( V_25 == 0 )
continue;
V_34 = F_201 ( V_236 , V_240 ) ;
V_20 . V_31 -= F_202 ( V_236 , V_240 ) ;
V_27 = F_195 ( V_83 , V_33 , V_25 , V_34 ,
V_16 , V_207 , V_20 . V_21 ,
V_20 . V_31 , V_199 ) ;
if ( V_27 )
goto V_157;
} else {
V_25 = F_203 ( V_236 , V_41 ) ;
V_34 = F_204 ( V_33 , V_167 - 1 ) ;
V_27 = F_195 ( V_83 , V_33 , V_25 , V_34 ,
V_16 , V_207 , V_167 - 1 , 0 ,
V_199 ) ;
if ( V_27 )
goto V_157;
}
}
return 0 ;
V_157:
F_87 () ;
return V_27 ;
}
int F_205 ( struct V_82 * V_83 , struct V_32 * V_33 ,
struct V_63 * V_236 , int V_237 , int V_199 )
{
return F_194 ( V_83 , V_33 , V_236 , V_237 , 1 , V_199 ) ;
}
int F_206 ( struct V_82 * V_83 , struct V_32 * V_33 ,
struct V_63 * V_236 , int V_237 , int V_199 )
{
return F_194 ( V_83 , V_33 , V_236 , V_237 , 0 , V_199 ) ;
}
static int F_207 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_61 * V_62 ,
struct V_1 * V_2 )
{
int V_27 ;
struct V_32 * V_60 = V_33 -> V_35 -> V_60 ;
unsigned long V_140 ;
struct V_63 * V_64 ;
V_27 = F_36 ( V_83 , V_60 , & V_2 -> V_20 , V_62 , 0 , 1 ) ;
if ( V_27 < 0 )
goto V_157;
F_22 ( V_27 ) ;
V_64 = V_62 -> V_78 [ 0 ] ;
V_140 = F_208 ( V_64 , V_62 -> V_79 [ 0 ] ) ;
F_209 ( V_64 , & V_2 -> V_113 , V_140 , sizeof( V_2 -> V_113 ) ) ;
F_99 ( V_64 ) ;
F_43 ( V_62 ) ;
V_157:
if ( V_27 )
return V_27 ;
return 0 ;
}
static struct V_1 *
F_210 ( struct V_32 * V_33 ,
struct V_1 * V_2 )
{
struct V_14 * V_131 ;
F_11 ( & V_33 -> V_35 -> V_17 ) ;
V_131 = F_183 ( & V_2 -> V_19 ) ;
F_6 ( V_2 ) ;
if ( V_131 ) {
V_2 = F_12 ( V_131 , struct V_1 ,
V_19 ) ;
F_4 ( V_2 ) ;
} else
V_2 = NULL ;
F_13 ( & V_33 -> V_35 -> V_17 ) ;
return V_2 ;
}
static int F_211 ( struct V_1 * V_13 ,
struct V_82 * V_83 ,
struct V_61 * V_62 )
{
struct V_32 * V_33 = V_13 -> V_35 -> V_92 ;
struct V_245 * V_245 = NULL ;
T_2 V_246 = 0 ;
int V_247 = V_248 ;
int V_249 = 0 ;
int V_250 = 0 ;
int V_27 = 0 ;
if ( V_13 -> V_20 . V_31 < ( 100 * 1024 * 1024 ) ) {
F_11 ( & V_13 -> V_49 ) ;
V_13 -> V_251 = V_252 ;
F_13 ( & V_13 -> V_49 ) ;
return 0 ;
}
V_74:
V_245 = F_212 ( V_33 , V_13 , V_62 ) ;
if ( F_213 ( V_245 ) && F_214 ( V_245 ) != - V_154 ) {
V_27 = F_214 ( V_245 ) ;
F_43 ( V_62 ) ;
goto V_69;
}
if ( F_213 ( V_245 ) ) {
F_22 ( V_250 ) ;
V_250 ++ ;
if ( V_13 -> V_114 )
goto V_127;
V_27 = F_215 ( V_33 , V_83 , V_13 , V_62 ) ;
if ( V_27 )
goto V_127;
goto V_74;
}
if ( V_13 -> V_253 == V_83 -> V_254 &&
F_216 ( V_245 ) ) {
V_247 = V_255 ;
goto V_256;
}
F_217 ( V_245 ) -> V_257 = 0 ;
V_27 = F_218 ( V_83 , V_33 , V_245 ) ;
F_8 ( V_27 ) ;
if ( F_216 ( V_245 ) > 0 ) {
V_27 = F_219 ( V_33 , V_83 , V_62 ,
V_245 ) ;
if ( V_27 )
goto V_256;
}
F_11 ( & V_13 -> V_49 ) ;
if ( V_13 -> V_3 != V_4 ) {
V_247 = V_252 ;
F_13 ( & V_13 -> V_49 ) ;
goto V_256;
}
F_13 ( & V_13 -> V_49 ) ;
V_249 = ( int ) F_220 ( V_13 -> V_20 . V_31 , 1024 * 1024 * 1024 ) ;
if ( ! V_249 )
V_249 = 1 ;
V_249 *= 16 ;
V_249 *= V_258 ;
V_27 = F_221 ( V_245 , V_249 ) ;
if ( V_27 )
goto V_256;
V_27 = F_222 ( V_245 , V_83 , 0 , 0 , V_249 ,
V_249 , V_249 ,
& V_246 ) ;
if ( ! V_27 )
V_247 = V_255 ;
F_223 ( V_245 , V_249 ) ;
V_256:
F_224 ( V_245 ) ;
V_127:
F_43 ( V_62 ) ;
V_69:
F_11 ( & V_13 -> V_49 ) ;
if ( ! V_27 && V_247 == V_255 )
V_13 -> V_253 = V_83 -> V_254 ;
V_13 -> V_251 = V_247 ;
F_13 ( & V_13 -> V_49 ) ;
return V_27 ;
}
int F_225 ( struct V_82 * V_83 ,
struct V_32 * V_33 )
{
struct V_1 * V_2 ;
int V_77 = 0 ;
struct V_61 * V_62 ;
T_2 V_67 = 0 ;
V_62 = F_32 () ;
if ( ! V_62 )
return - V_117 ;
V_74:
while ( 1 ) {
V_2 = F_65 ( V_33 -> V_35 , V_67 ) ;
while ( V_2 ) {
if ( V_2 -> V_251 == V_259 )
break;
V_2 = F_210 ( V_33 , V_2 ) ;
}
if ( ! V_2 ) {
if ( V_67 == 0 )
break;
V_67 = 0 ;
continue;
}
V_77 = F_211 ( V_2 , V_83 , V_62 ) ;
V_67 = V_2 -> V_20 . V_21 + V_2 -> V_20 . V_31 ;
F_6 ( V_2 ) ;
}
while ( 1 ) {
if ( V_67 == 0 ) {
V_77 = F_179 ( V_83 , V_33 ,
( unsigned long ) - 1 ) ;
F_22 ( V_77 ) ;
}
V_2 = F_65 ( V_33 -> V_35 , V_67 ) ;
while ( V_2 ) {
if ( V_2 -> V_251 == V_259 ) {
F_6 ( V_2 ) ;
goto V_74;
}
if ( V_2 -> V_260 )
break;
V_2 = F_210 ( V_33 , V_2 ) ;
}
if ( ! V_2 ) {
if ( V_67 == 0 )
break;
V_67 = 0 ;
continue;
}
if ( V_2 -> V_251 == V_255 )
V_2 -> V_251 = V_261 ;
V_2 -> V_260 = 0 ;
V_67 = V_2 -> V_20 . V_21 + V_2 -> V_20 . V_31 ;
V_77 = F_207 ( V_83 , V_33 , V_62 , V_2 ) ;
F_22 ( V_77 ) ;
F_6 ( V_2 ) ;
}
while ( 1 ) {
if ( V_67 == 0 ) {
V_77 = F_179 ( V_83 , V_33 ,
( unsigned long ) - 1 ) ;
F_22 ( V_77 ) ;
}
V_2 = F_65 ( V_33 -> V_35 , V_67 ) ;
while ( V_2 ) {
if ( V_2 -> V_260 ) {
F_6 ( V_2 ) ;
goto V_74;
}
if ( V_2 -> V_251 == V_261 )
break;
V_2 = F_210 ( V_33 , V_2 ) ;
}
if ( ! V_2 ) {
if ( V_67 == 0 )
break;
V_67 = 0 ;
continue;
}
F_226 ( V_33 , V_83 , V_2 , V_62 ) ;
if ( V_2 -> V_251 == V_261 )
V_2 -> V_251 = V_252 ;
V_67 = V_2 -> V_20 . V_21 + V_2 -> V_20 . V_31 ;
F_6 ( V_2 ) ;
}
F_48 ( V_62 ) ;
return 0 ;
}
int F_227 ( struct V_32 * V_33 , T_2 V_25 )
{
struct V_1 * V_13 ;
int V_262 = 0 ;
V_13 = F_66 ( V_33 -> V_35 , V_25 ) ;
if ( ! V_13 || V_13 -> V_114 )
V_262 = 1 ;
if ( V_13 )
F_6 ( V_13 ) ;
return V_262 ;
}
static int F_228 ( struct V_11 * V_12 , T_2 V_6 ,
T_2 V_263 , T_2 V_264 ,
struct V_97 * * V_100 )
{
struct V_97 * V_101 ;
int V_41 ;
int V_105 ;
if ( V_6 & ( V_265 | V_266 |
V_267 ) )
V_105 = 2 ;
else
V_105 = 1 ;
V_101 = F_67 ( V_12 , V_6 ) ;
if ( V_101 ) {
F_11 ( & V_101 -> V_49 ) ;
V_101 -> V_263 += V_263 ;
V_101 -> V_268 += V_263 * V_105 ;
V_101 -> V_264 += V_264 ;
V_101 -> V_269 += V_264 * V_105 ;
V_101 -> V_103 = 0 ;
F_13 ( & V_101 -> V_49 ) ;
* V_100 = V_101 ;
return 0 ;
}
V_101 = F_51 ( sizeof( * V_101 ) , V_38 ) ;
if ( ! V_101 )
return - V_117 ;
for ( V_41 = 0 ; V_41 < V_270 ; V_41 ++ )
F_52 ( & V_101 -> V_271 [ V_41 ] ) ;
F_229 ( & V_101 -> V_272 ) ;
F_230 ( & V_101 -> V_49 ) ;
V_101 -> V_6 = V_6 & V_102 ;
V_101 -> V_263 = V_263 ;
V_101 -> V_268 = V_263 * V_105 ;
V_101 -> V_264 = V_264 ;
V_101 -> V_269 = V_264 * V_105 ;
V_101 -> V_273 = 0 ;
V_101 -> V_274 = 0 ;
V_101 -> V_275 = 0 ;
V_101 -> V_276 = 0 ;
V_101 -> V_103 = 0 ;
V_101 -> V_277 = V_221 ;
V_101 -> V_278 = 0 ;
V_101 -> V_279 = 0 ;
F_54 ( & V_101 -> V_81 ) ;
* V_100 = V_101 ;
F_231 ( & V_101 -> V_85 , & V_12 -> V_100 ) ;
return 0 ;
}
static void F_232 ( struct V_11 * V_35 , T_2 V_6 )
{
T_2 V_280 = V_6 & V_281 ;
if ( V_280 == 0 )
V_280 = V_282 ;
if ( V_6 & V_283 )
V_35 -> V_284 |= V_280 ;
if ( V_6 & V_115 )
V_35 -> V_285 |= V_280 ;
if ( V_6 & V_286 )
V_35 -> V_287 |= V_280 ;
}
T_2 F_233 ( struct V_32 * V_33 , T_2 V_6 )
{
T_2 V_288 = V_33 -> V_35 -> V_289 -> V_290 +
V_33 -> V_35 -> V_289 -> V_291 ;
F_11 ( & V_33 -> V_35 -> V_292 ) ;
if ( V_33 -> V_35 -> V_293 ) {
struct V_294 * V_295 = V_33 -> V_35 -> V_293 ;
T_2 V_296 = 0 ;
if ( ( V_6 & V_283 ) &&
( V_295 -> V_297 . V_6 & V_298 ) &&
( V_6 & V_295 -> V_297 . V_299 ) ) {
V_296 = V_283 | V_295 -> V_297 . V_299 ;
} else if ( ( V_6 & V_286 ) &&
( V_295 -> V_300 . V_6 & V_298 ) &&
( V_6 & V_295 -> V_300 . V_299 ) ) {
V_296 = V_286 | V_295 -> V_300 . V_299 ;
} else if ( ( V_6 & V_115 ) &&
( V_295 -> V_301 . V_6 & V_298 ) &&
( V_6 & V_295 -> V_301 . V_299 ) ) {
V_296 = V_115 | V_295 -> V_301 . V_299 ;
}
if ( V_296 ) {
F_13 ( & V_33 -> V_35 -> V_292 ) ;
V_6 = V_296 ;
goto V_69;
}
}
F_13 ( & V_33 -> V_35 -> V_292 ) ;
if ( V_288 == 1 )
V_6 &= ~ ( V_266 | V_302 ) ;
if ( V_288 < 4 )
V_6 &= ~ V_267 ;
if ( ( V_6 & V_265 ) &&
( V_6 & ( V_266 |
V_267 ) ) ) {
V_6 &= ~ V_265 ;
}
if ( ( V_6 & V_266 ) &&
( V_6 & V_267 ) ) {
V_6 &= ~ V_266 ;
}
if ( ( V_6 & V_302 ) &&
( ( V_6 & V_266 ) |
( V_6 & V_267 ) |
( V_6 & V_265 ) ) ) {
V_6 &= ~ V_302 ;
}
V_69:
V_6 &= ~ V_282 ;
return V_6 ;
}
static T_2 F_234 ( struct V_32 * V_33 , T_2 V_6 )
{
if ( V_6 & V_283 )
V_6 |= V_33 -> V_35 -> V_284 ;
else if ( V_6 & V_286 )
V_6 |= V_33 -> V_35 -> V_287 ;
else if ( V_6 & V_115 )
V_6 |= V_33 -> V_35 -> V_285 ;
return F_233 ( V_33 , V_6 ) ;
}
T_2 F_175 ( struct V_32 * V_33 , int V_297 )
{
T_2 V_6 ;
if ( V_297 )
V_6 = V_283 ;
else if ( V_33 == V_33 -> V_35 -> V_303 )
V_6 = V_286 ;
else
V_6 = V_115 ;
return F_234 ( V_33 , V_6 ) ;
}
void F_235 ( struct V_32 * V_33 , struct V_245 * V_245 )
{
F_217 ( V_245 ) -> V_100 = F_67 ( V_33 -> V_35 ,
V_283 ) ;
}
int F_221 ( struct V_245 * V_245 , T_2 V_304 )
{
struct V_97 * V_305 ;
struct V_32 * V_33 = F_217 ( V_245 ) -> V_33 ;
T_2 V_109 ;
int V_27 = 0 , V_306 = 0 , V_307 = 1 ;
V_304 = ( V_304 + V_33 -> V_308 - 1 ) & ~ ( ( T_2 ) V_33 -> V_308 - 1 ) ;
if ( V_33 == V_33 -> V_35 -> V_92 ||
F_217 ( V_245 ) -> V_309 . V_21 == V_310 ) {
V_307 = 0 ;
V_306 = 1 ;
}
V_305 = F_217 ( V_245 ) -> V_100 ;
if ( ! V_305 )
goto V_311;
V_74:
F_11 ( & V_305 -> V_49 ) ;
V_109 = V_305 -> V_264 + V_305 -> V_274 +
V_305 -> V_273 + V_305 -> V_275 +
V_305 -> V_276 ;
if ( V_109 + V_304 > V_305 -> V_263 ) {
struct V_82 * V_83 ;
if ( ! V_305 -> V_103 && V_307 ) {
T_2 V_312 ;
V_305 -> V_277 = V_313 ;
F_13 ( & V_305 -> V_49 ) ;
V_311:
V_312 = F_175 ( V_33 , 1 ) ;
V_83 = F_236 ( V_33 ) ;
if ( F_213 ( V_83 ) )
return F_214 ( V_83 ) ;
V_27 = F_174 ( V_83 , V_33 -> V_35 -> V_60 ,
V_304 + 2 * 1024 * 1024 ,
V_312 ,
V_221 ) ;
F_237 ( V_83 , V_33 ) ;
if ( V_27 < 0 ) {
if ( V_27 != - V_314 )
return V_27 ;
else
goto V_315;
}
if ( ! V_305 ) {
F_235 ( V_33 , V_245 ) ;
V_305 = F_217 ( V_245 ) -> V_100 ;
}
goto V_74;
}
if ( V_305 -> V_273 < V_304 )
V_306 = 1 ;
F_13 ( & V_305 -> V_49 ) ;
V_315:
if ( ! V_306 &&
! F_238 ( & V_33 -> V_35 -> V_316 ) ) {
V_306 = 1 ;
V_83 = F_236 ( V_33 ) ;
if ( F_213 ( V_83 ) )
return F_214 ( V_83 ) ;
V_27 = F_239 ( V_83 , V_33 ) ;
if ( V_27 )
return V_27 ;
goto V_74;
}
return - V_314 ;
}
V_305 -> V_276 += V_304 ;
F_240 ( V_33 -> V_35 , L_3 ,
( T_2 ) ( unsigned long ) V_305 ,
V_304 , 1 ) ;
F_13 ( & V_305 -> V_49 ) ;
return 0 ;
}
void F_223 ( struct V_245 * V_245 , T_2 V_304 )
{
struct V_32 * V_33 = F_217 ( V_245 ) -> V_33 ;
struct V_97 * V_305 ;
V_304 = ( V_304 + V_33 -> V_308 - 1 ) & ~ ( ( T_2 ) V_33 -> V_308 - 1 ) ;
V_305 = F_217 ( V_245 ) -> V_100 ;
F_11 ( & V_305 -> V_49 ) ;
V_305 -> V_276 -= V_304 ;
F_240 ( V_33 -> V_35 , L_3 ,
( T_2 ) ( unsigned long ) V_305 ,
V_304 , 0 ) ;
F_13 ( & V_305 -> V_49 ) ;
}
static void F_241 ( struct V_11 * V_12 )
{
struct V_98 * V_99 = & V_12 -> V_100 ;
struct V_97 * V_101 ;
F_68 () ;
F_69 (found, head, list) {
if ( V_101 -> V_6 & V_115 )
V_101 -> V_277 = V_313 ;
}
F_70 () ;
}
static int F_242 ( struct V_32 * V_33 ,
struct V_97 * V_317 , T_2 V_318 ,
int V_319 )
{
struct V_320 * V_321 = & V_33 -> V_35 -> V_322 ;
T_2 V_34 = V_317 -> V_263 - V_317 -> V_275 ;
T_2 V_323 = V_317 -> V_264 + V_317 -> V_274 ;
T_2 V_324 ;
if ( V_319 == V_313 )
return 1 ;
V_323 += V_321 -> V_54 ;
if ( V_319 == V_325 ) {
V_324 = F_243 ( V_33 -> V_35 -> V_326 ) ;
V_324 = F_33 ( T_2 , 64 * 1024 * 1024 ,
F_74 ( V_324 , 1 ) ) ;
if ( V_34 - V_323 < V_324 )
return 1 ;
}
V_324 = F_243 ( V_33 -> V_35 -> V_326 ) ;
V_324 = F_33 ( T_2 , 256 * 1024 * 1024 , F_74 ( V_324 , 2 ) ) ;
if ( V_317 -> V_6 & V_286 )
V_324 = 32 * 1024 * 1024 ;
if ( V_34 > V_324 && V_317 -> V_264 < F_72 ( V_34 , 8 ) )
return 0 ;
return 1 ;
}
static int F_174 ( struct V_82 * V_83 ,
struct V_32 * V_60 , T_2 V_318 ,
T_2 V_6 , int V_319 )
{
struct V_97 * V_100 ;
struct V_11 * V_35 = V_60 -> V_35 ;
int V_327 = 0 ;
int V_27 = 0 ;
F_22 ( ! F_244 ( V_6 , 0 ) ) ;
V_100 = F_67 ( V_60 -> V_35 , V_6 ) ;
if ( ! V_100 ) {
V_27 = F_228 ( V_60 -> V_35 , V_6 ,
0 , 0 , & V_100 ) ;
F_22 ( V_27 ) ;
}
F_22 ( ! V_100 ) ;
V_74:
F_11 ( & V_100 -> V_49 ) ;
if ( V_319 < V_100 -> V_277 )
V_319 = V_100 -> V_277 ;
if ( V_100 -> V_103 ) {
F_13 ( & V_100 -> V_49 ) ;
return 0 ;
}
if ( ! F_242 ( V_60 , V_100 , V_318 , V_319 ) ) {
F_13 ( & V_100 -> V_49 ) ;
return 0 ;
} else if ( V_100 -> V_278 ) {
V_327 = 1 ;
} else {
V_100 -> V_278 = 1 ;
}
F_13 ( & V_100 -> V_49 ) ;
F_34 ( & V_35 -> V_328 ) ;
if ( V_327 ) {
F_45 ( & V_35 -> V_328 ) ;
V_327 = 0 ;
goto V_74;
}
if ( F_245 ( V_100 ) )
V_6 |= ( V_283 | V_115 ) ;
if ( V_6 & V_283 && V_35 -> V_329 ) {
V_35 -> V_330 ++ ;
if ( ! ( V_35 -> V_330 %
V_35 -> V_329 ) )
F_241 ( V_35 ) ;
}
V_27 = F_246 ( V_83 , V_60 , V_6 ) ;
if ( V_27 < 0 && V_27 != - V_314 )
goto V_69;
F_11 ( & V_100 -> V_49 ) ;
if ( V_27 )
V_100 -> V_103 = 1 ;
else
V_27 = 1 ;
V_100 -> V_277 = V_221 ;
V_100 -> V_278 = 0 ;
F_13 ( & V_100 -> V_49 ) ;
V_69:
F_45 ( & V_60 -> V_35 -> V_328 ) ;
return V_27 ;
}
static int F_247 ( struct V_32 * V_33 , T_2 V_331 ,
bool V_332 )
{
struct V_320 * V_333 ;
struct V_97 * V_100 ;
struct V_82 * V_83 ;
T_2 V_9 ;
T_2 V_334 ;
T_2 V_335 = 0 ;
long V_336 ;
unsigned long V_337 = ( 2 * 1024 * 1024 ) >> V_338 ;
int V_339 = 0 ;
unsigned long V_80 ;
V_83 = (struct V_82 * ) V_340 -> V_341 ;
V_333 = & V_33 -> V_35 -> V_342 ;
V_100 = V_333 -> V_100 ;
F_2 () ;
V_9 = V_100 -> V_276 ;
V_80 = V_100 -> V_343 ;
if ( V_9 == 0 )
return 0 ;
F_2 () ;
if ( V_33 -> V_35 -> V_344 == 0 ) {
if ( V_83 )
return 0 ;
F_248 ( V_33 , 0 , 0 ) ;
return 0 ;
}
V_334 = F_249 ( V_9 , V_331 ) ;
V_337 = F_33 (unsigned long, nr_pages,
max_reclaim >> PAGE_CACHE_SHIFT) ;
while ( V_339 < 1024 ) {
F_2 () ;
V_337 = F_181 (unsigned long, nr_pages,
root->fs_info->delalloc_bytes >> PAGE_CACHE_SHIFT) ;
F_250 ( V_33 -> V_35 -> V_345 , V_337 ,
V_346 ) ;
F_11 ( & V_100 -> V_49 ) ;
if ( V_9 > V_100 -> V_276 )
V_335 += V_9 - V_100 -> V_276 ;
V_9 = V_100 -> V_276 ;
F_13 ( & V_100 -> V_49 ) ;
V_339 ++ ;
if ( V_9 == 0 || V_335 >= V_334 )
break;
if ( V_83 && V_83 -> V_90 -> V_347 )
return - V_176 ;
if ( V_332 && ! V_83 ) {
F_248 ( V_33 , 0 , 0 ) ;
} else {
V_336 = F_251 ( 1 ) ;
if ( V_336 )
break;
}
if ( V_339 > 3 ) {
F_2 () ;
if ( V_80 != V_100 -> V_343 )
break;
}
}
return V_335 >= V_331 ;
}
static int F_252 ( struct V_32 * V_33 ,
struct V_97 * V_100 ,
T_2 V_304 , int V_319 )
{
struct V_320 * V_348 = & V_33 -> V_35 -> V_349 ;
struct V_82 * V_83 ;
V_83 = (struct V_82 * ) V_340 -> V_341 ;
if ( V_83 )
return - V_176 ;
if ( V_319 )
goto V_350;
F_11 ( & V_100 -> V_49 ) ;
if ( V_100 -> V_273 >= V_304 ) {
F_13 ( & V_100 -> V_49 ) ;
goto V_350;
}
F_13 ( & V_100 -> V_49 ) ;
if ( V_100 != V_348 -> V_100 )
return - V_314 ;
F_11 ( & V_100 -> V_49 ) ;
F_11 ( & V_348 -> V_49 ) ;
if ( V_100 -> V_273 + V_348 -> V_54 < V_304 ) {
F_13 ( & V_348 -> V_49 ) ;
F_13 ( & V_100 -> V_49 ) ;
return - V_314 ;
}
F_13 ( & V_348 -> V_49 ) ;
F_13 ( & V_100 -> V_49 ) ;
V_350:
V_83 = F_236 ( V_33 ) ;
if ( F_213 ( V_83 ) )
return - V_314 ;
return F_239 ( V_83 , V_33 ) ;
}
static int F_253 ( struct V_32 * V_33 ,
struct V_320 * V_333 ,
T_2 V_351 , int V_279 )
{
struct V_97 * V_100 = V_333 -> V_100 ;
T_2 V_109 ;
T_2 V_34 = V_351 ;
int V_250 = 0 ;
int V_27 = 0 ;
bool V_306 = false ;
bool V_352 = false ;
bool V_332 = false ;
V_74:
V_27 = 0 ;
F_11 ( & V_100 -> V_49 ) ;
while ( V_279 && ! V_352 && V_100 -> V_279 ) {
F_13 ( & V_100 -> V_49 ) ;
if ( V_340 -> V_341 )
return - V_176 ;
V_27 = F_254 ( V_100 -> V_81 ,
! V_100 -> V_279 ) ;
if ( V_27 )
return - V_353 ;
F_11 ( & V_100 -> V_49 ) ;
}
V_27 = - V_314 ;
V_109 = V_100 -> V_264 + V_100 -> V_274 +
V_100 -> V_273 + V_100 -> V_275 +
V_100 -> V_276 ;
if ( V_109 <= V_100 -> V_263 ) {
if ( V_109 + V_351 <= V_100 -> V_263 ) {
V_100 -> V_276 += V_351 ;
F_240 ( V_33 -> V_35 ,
L_3 ,
( T_2 ) ( unsigned long ) V_100 ,
V_351 , 1 ) ;
V_27 = 0 ;
} else {
V_34 = V_351 ;
}
} else {
V_332 = true ;
V_34 = V_109 - V_100 -> V_263 +
( V_351 * ( V_250 + 1 ) ) ;
}
if ( V_27 ) {
T_2 V_354 = F_175 ( V_33 , 0 ) ;
T_2 V_355 ;
V_355 = ( V_100 -> V_263 - V_100 -> V_264 ) * 8 ;
F_73 ( V_355 , 10 ) ;
if ( V_100 -> V_273 >= V_355 && V_279 && ! V_306 ) {
V_100 -> V_279 = 1 ;
V_352 = true ;
F_13 ( & V_100 -> V_49 ) ;
V_27 = F_252 ( V_33 , V_100 ,
V_351 , 1 ) ;
if ( V_27 )
goto V_69;
V_306 = true ;
goto V_74;
}
F_11 ( & V_33 -> V_35 -> V_356 ) ;
V_355 = V_33 -> V_35 -> V_357 ;
if ( V_354 & ( V_265 |
V_266 |
V_267 ) )
V_355 >>= 1 ;
if ( V_279 )
V_355 >>= 3 ;
else
V_355 >>= 1 ;
F_13 ( & V_33 -> V_35 -> V_356 ) ;
if ( V_109 + V_34 < V_100 -> V_263 + V_355 ) {
V_100 -> V_276 += V_351 ;
F_240 ( V_33 -> V_35 ,
L_3 ,
( T_2 ) ( unsigned long ) V_100 ,
V_351 , 1 ) ;
V_27 = 0 ;
} else {
V_332 = true ;
}
}
if ( V_27 && V_279 ) {
V_352 = true ;
V_100 -> V_279 = 1 ;
}
F_13 ( & V_100 -> V_49 ) ;
if ( ! V_27 || ! V_279 )
goto V_69;
V_27 = F_247 ( V_33 , V_34 , V_332 ) ;
if ( V_27 < 0 )
goto V_69;
V_27 = 0 ;
if ( V_250 < 2 ) {
V_332 = true ;
V_250 ++ ;
goto V_74;
}
V_27 = - V_314 ;
if ( V_306 )
goto V_69;
V_27 = F_252 ( V_33 , V_100 , V_351 , 0 ) ;
if ( ! V_27 ) {
V_306 = true ;
goto V_74;
}
V_69:
if ( V_352 ) {
F_11 ( & V_100 -> V_49 ) ;
V_100 -> V_279 = 0 ;
F_255 ( & V_100 -> V_81 ) ;
F_13 ( & V_100 -> V_49 ) ;
}
return V_27 ;
}
static struct V_320 * F_256 ( struct V_82 * V_83 ,
struct V_32 * V_33 )
{
struct V_320 * V_333 = NULL ;
if ( V_33 -> V_241 || V_33 == V_33 -> V_35 -> V_358 )
V_333 = V_83 -> V_333 ;
if ( ! V_333 )
V_333 = V_33 -> V_333 ;
if ( ! V_333 )
V_333 = & V_33 -> V_35 -> V_359 ;
return V_333 ;
}
static int F_257 ( struct V_320 * V_333 ,
T_2 V_34 )
{
int V_27 = - V_314 ;
F_11 ( & V_333 -> V_49 ) ;
if ( V_333 -> V_9 >= V_34 ) {
V_333 -> V_9 -= V_34 ;
if ( V_333 -> V_9 < V_333 -> V_54 )
V_333 -> V_103 = 0 ;
V_27 = 0 ;
}
F_13 ( & V_333 -> V_49 ) ;
return V_27 ;
}
static void F_258 ( struct V_320 * V_333 ,
T_2 V_34 , int V_360 )
{
F_11 ( & V_333 -> V_49 ) ;
V_333 -> V_9 += V_34 ;
if ( V_360 )
V_333 -> V_54 += V_34 ;
else if ( V_333 -> V_9 >= V_333 -> V_54 )
V_333 -> V_103 = 1 ;
F_13 ( & V_333 -> V_49 ) ;
}
static void F_259 ( struct V_11 * V_35 ,
struct V_320 * V_333 ,
struct V_320 * V_361 , T_2 V_34 )
{
struct V_97 * V_100 = V_333 -> V_100 ;
F_11 ( & V_333 -> V_49 ) ;
if ( V_34 == ( T_2 ) - 1 )
V_34 = V_333 -> V_54 ;
V_333 -> V_54 -= V_34 ;
if ( V_333 -> V_9 >= V_333 -> V_54 ) {
V_34 = V_333 -> V_9 - V_333 -> V_54 ;
V_333 -> V_9 = V_333 -> V_54 ;
V_333 -> V_103 = 1 ;
} else {
V_34 = 0 ;
}
F_13 ( & V_333 -> V_49 ) ;
if ( V_34 > 0 ) {
if ( V_361 ) {
F_11 ( & V_361 -> V_49 ) ;
if ( ! V_361 -> V_103 ) {
T_2 V_362 ;
V_362 = V_361 -> V_54 - V_361 -> V_9 ;
V_362 = F_249 ( V_34 , V_362 ) ;
V_361 -> V_9 += V_362 ;
if ( V_361 -> V_9 >= V_361 -> V_54 )
V_361 -> V_103 = 1 ;
V_34 -= V_362 ;
}
F_13 ( & V_361 -> V_49 ) ;
}
if ( V_34 ) {
F_11 ( & V_100 -> V_49 ) ;
V_100 -> V_276 -= V_34 ;
F_240 ( V_35 , L_3 ,
( T_2 ) ( unsigned long ) V_100 ,
V_34 , 0 ) ;
V_100 -> V_343 ++ ;
F_13 ( & V_100 -> V_49 ) ;
}
}
}
static int F_260 ( struct V_320 * V_363 ,
struct V_320 * V_364 , T_2 V_34 )
{
int V_27 ;
V_27 = F_257 ( V_363 , V_34 ) ;
if ( V_27 )
return V_27 ;
F_258 ( V_364 , V_34 , 1 ) ;
return 0 ;
}
void F_261 ( struct V_320 * V_365 )
{
memset ( V_365 , 0 , sizeof( * V_365 ) ) ;
F_230 ( & V_365 -> V_49 ) ;
}
struct V_320 * F_262 ( struct V_32 * V_33 )
{
struct V_320 * V_333 ;
struct V_11 * V_35 = V_33 -> V_35 ;
V_333 = F_186 ( sizeof( * V_333 ) , V_38 ) ;
if ( ! V_333 )
return NULL ;
F_261 ( V_333 ) ;
V_333 -> V_100 = F_67 ( V_35 ,
V_115 ) ;
return V_333 ;
}
void F_263 ( struct V_32 * V_33 ,
struct V_320 * V_365 )
{
F_264 ( V_33 , V_365 , ( T_2 ) - 1 ) ;
F_9 ( V_365 ) ;
}
static inline int F_265 ( struct V_32 * V_33 ,
struct V_320 * V_333 ,
T_2 V_34 , int V_279 )
{
int V_27 ;
if ( V_34 == 0 )
return 0 ;
V_27 = F_253 ( V_33 , V_333 , V_34 , V_279 ) ;
if ( ! V_27 ) {
F_258 ( V_333 , V_34 , 1 ) ;
return 0 ;
}
return V_27 ;
}
int F_266 ( struct V_32 * V_33 ,
struct V_320 * V_333 ,
T_2 V_34 )
{
return F_265 ( V_33 , V_333 , V_34 , 1 ) ;
}
int F_267 ( struct V_32 * V_33 ,
struct V_320 * V_333 ,
T_2 V_34 )
{
return F_265 ( V_33 , V_333 , V_34 , 0 ) ;
}
int F_268 ( struct V_32 * V_33 ,
struct V_320 * V_333 , int V_366 )
{
T_2 V_34 = 0 ;
int V_27 = - V_314 ;
if ( ! V_333 )
return 0 ;
F_11 ( & V_333 -> V_49 ) ;
V_34 = F_72 ( V_333 -> V_54 , V_366 ) ;
if ( V_333 -> V_9 >= V_34 )
V_27 = 0 ;
F_13 ( & V_333 -> V_49 ) ;
return V_27 ;
}
static inline int F_269 ( struct V_32 * V_33 ,
struct V_320 * V_333 ,
T_2 V_367 , int V_279 )
{
T_2 V_34 = 0 ;
int V_27 = - V_314 ;
if ( ! V_333 )
return 0 ;
F_11 ( & V_333 -> V_49 ) ;
V_34 = V_367 ;
if ( V_333 -> V_9 >= V_34 )
V_27 = 0 ;
else
V_34 -= V_333 -> V_9 ;
F_13 ( & V_333 -> V_49 ) ;
if ( ! V_27 )
return 0 ;
V_27 = F_253 ( V_33 , V_333 , V_34 , V_279 ) ;
if ( ! V_27 ) {
F_258 ( V_333 , V_34 , 0 ) ;
return 0 ;
}
return V_27 ;
}
int F_270 ( struct V_32 * V_33 ,
struct V_320 * V_333 ,
T_2 V_367 )
{
return F_269 ( V_33 , V_333 , V_367 , 1 ) ;
}
int F_271 ( struct V_32 * V_33 ,
struct V_320 * V_333 ,
T_2 V_367 )
{
return F_269 ( V_33 , V_333 , V_367 , 0 ) ;
}
int F_272 ( struct V_320 * V_368 ,
struct V_320 * V_369 ,
T_2 V_34 )
{
return F_260 ( V_368 , V_369 , V_34 ) ;
}
void F_264 ( struct V_32 * V_33 ,
struct V_320 * V_333 ,
T_2 V_34 )
{
struct V_320 * V_321 = & V_33 -> V_35 -> V_322 ;
if ( V_321 -> V_103 || V_321 == V_333 ||
V_333 -> V_100 != V_321 -> V_100 )
V_321 = NULL ;
F_259 ( V_33 -> V_35 , V_333 , V_321 ,
V_34 ) ;
}
static T_2 F_273 ( struct V_11 * V_35 )
{
struct V_97 * V_317 ;
T_2 V_34 ;
T_2 V_370 ;
T_2 V_371 ;
int V_372 = F_274 ( V_35 -> V_326 ) ;
V_317 = F_67 ( V_35 , V_283 ) ;
F_11 ( & V_317 -> V_49 ) ;
V_371 = V_317 -> V_264 ;
F_13 ( & V_317 -> V_49 ) ;
V_317 = F_67 ( V_35 , V_115 ) ;
F_11 ( & V_317 -> V_49 ) ;
if ( V_317 -> V_6 & V_283 )
V_371 = 0 ;
V_370 = V_317 -> V_264 ;
F_13 ( & V_317 -> V_49 ) ;
V_34 = ( V_371 >> V_35 -> V_345 -> V_373 ) *
V_372 * 2 ;
V_34 += F_220 ( V_371 + V_370 , 50 ) ;
if ( V_34 * 3 > V_370 )
V_34 = F_220 ( V_370 , 3 ) * 2 ;
return F_275 ( V_34 , V_35 -> V_60 -> V_374 << 10 ) ;
}
static void F_276 ( struct V_11 * V_35 )
{
struct V_320 * V_333 = & V_35 -> V_322 ;
struct V_97 * V_317 = V_333 -> V_100 ;
T_2 V_34 ;
V_34 = F_273 ( V_35 ) ;
F_11 ( & V_333 -> V_49 ) ;
F_11 ( & V_317 -> V_49 ) ;
V_333 -> V_54 = V_34 ;
V_34 = V_317 -> V_264 + V_317 -> V_273 +
V_317 -> V_274 + V_317 -> V_275 +
V_317 -> V_276 ;
if ( V_317 -> V_263 > V_34 ) {
V_34 = V_317 -> V_263 - V_34 ;
V_333 -> V_9 += V_34 ;
V_317 -> V_276 += V_34 ;
F_240 ( V_35 , L_3 ,
( T_2 ) ( unsigned long ) V_317 , V_34 , 1 ) ;
}
if ( V_333 -> V_9 >= V_333 -> V_54 ) {
V_34 = V_333 -> V_9 - V_333 -> V_54 ;
V_317 -> V_276 -= V_34 ;
F_240 ( V_35 , L_3 ,
( T_2 ) ( unsigned long ) V_317 , V_34 , 0 ) ;
V_317 -> V_343 ++ ;
V_333 -> V_9 = V_333 -> V_54 ;
V_333 -> V_103 = 1 ;
}
F_13 ( & V_317 -> V_49 ) ;
F_13 ( & V_333 -> V_49 ) ;
}
static void F_277 ( struct V_11 * V_35 )
{
struct V_97 * V_100 ;
V_100 = F_67 ( V_35 , V_286 ) ;
V_35 -> V_375 . V_100 = V_100 ;
V_100 = F_67 ( V_35 , V_115 ) ;
V_35 -> V_322 . V_100 = V_100 ;
V_35 -> V_342 . V_100 = V_100 ;
V_35 -> V_376 . V_100 = V_100 ;
V_35 -> V_359 . V_100 = V_100 ;
V_35 -> V_349 . V_100 = V_100 ;
V_35 -> V_60 -> V_333 = & V_35 -> V_322 ;
V_35 -> V_358 -> V_333 = & V_35 -> V_322 ;
V_35 -> V_377 -> V_333 = & V_35 -> V_322 ;
V_35 -> V_92 -> V_333 = & V_35 -> V_322 ;
V_35 -> V_303 -> V_333 = & V_35 -> V_375 ;
F_276 ( V_35 ) ;
}
static void F_278 ( struct V_11 * V_35 )
{
F_259 ( V_35 , & V_35 -> V_322 , NULL ,
( T_2 ) - 1 ) ;
F_8 ( V_35 -> V_342 . V_54 > 0 ) ;
F_8 ( V_35 -> V_342 . V_9 > 0 ) ;
F_8 ( V_35 -> V_376 . V_54 > 0 ) ;
F_8 ( V_35 -> V_376 . V_9 > 0 ) ;
F_8 ( V_35 -> V_375 . V_54 > 0 ) ;
F_8 ( V_35 -> V_375 . V_9 > 0 ) ;
F_8 ( V_35 -> V_349 . V_54 > 0 ) ;
F_8 ( V_35 -> V_349 . V_9 > 0 ) ;
}
void F_279 ( struct V_82 * V_83 ,
struct V_32 * V_33 )
{
if ( ! V_83 -> V_274 )
return;
F_240 ( V_33 -> V_35 , L_4 ,
( T_2 ) ( unsigned long ) V_83 ,
V_83 -> V_274 , 0 ) ;
F_264 ( V_33 , V_83 -> V_333 , V_83 -> V_274 ) ;
V_83 -> V_274 = 0 ;
}
int F_280 ( struct V_82 * V_83 ,
struct V_245 * V_245 )
{
struct V_32 * V_33 = F_217 ( V_245 ) -> V_33 ;
struct V_320 * V_368 = F_256 ( V_83 , V_33 ) ;
struct V_320 * V_369 = V_33 -> V_378 ;
T_2 V_34 = F_281 ( V_33 , 1 ) ;
F_240 ( V_33 -> V_35 , L_5 ,
F_282 ( V_245 ) , V_34 , 1 ) ;
return F_260 ( V_368 , V_369 , V_34 ) ;
}
void F_283 ( struct V_245 * V_245 )
{
struct V_32 * V_33 = F_217 ( V_245 ) -> V_33 ;
T_2 V_34 = F_281 ( V_33 , 1 ) ;
F_240 ( V_33 -> V_35 , L_5 ,
F_282 ( V_245 ) , V_34 , 0 ) ;
F_264 ( V_33 , V_33 -> V_378 , V_34 ) ;
}
int F_284 ( struct V_82 * V_83 ,
struct V_379 * V_380 )
{
struct V_32 * V_33 = V_380 -> V_33 ;
struct V_320 * V_368 = F_256 ( V_83 , V_33 ) ;
struct V_320 * V_369 = & V_380 -> V_333 ;
T_2 V_34 = F_281 ( V_33 , 5 ) ;
V_369 -> V_100 = V_368 -> V_100 ;
return F_260 ( V_368 , V_369 , V_34 ) ;
}
static unsigned F_285 ( struct V_245 * V_245 )
{
unsigned V_381 = 0 ;
unsigned V_382 = 0 ;
F_22 ( ! F_217 ( V_245 ) -> V_383 ) ;
F_217 ( V_245 ) -> V_383 -- ;
if ( F_217 ( V_245 ) -> V_383 == 0 &&
F_217 ( V_245 ) -> V_384 ) {
V_381 = 1 ;
F_217 ( V_245 ) -> V_384 = 0 ;
}
if ( F_217 ( V_245 ) -> V_383 >=
F_217 ( V_245 ) -> V_385 )
return V_381 ;
V_382 = F_217 ( V_245 ) -> V_385 -
F_217 ( V_245 ) -> V_383 ;
F_217 ( V_245 ) -> V_385 -= V_382 ;
return V_382 + V_381 ;
}
static T_2 F_286 ( struct V_245 * V_245 , T_2 V_34 ,
int V_386 )
{
struct V_32 * V_33 = F_217 ( V_245 ) -> V_33 ;
T_2 V_372 ;
int V_387 ;
int V_388 ;
int V_389 ;
if ( F_217 ( V_245 ) -> V_6 & V_390 &&
F_217 ( V_245 ) -> V_391 == 0 )
return 0 ;
V_389 = ( int ) F_220 ( F_217 ( V_245 ) -> V_391 , V_33 -> V_308 ) ;
if ( V_386 )
F_217 ( V_245 ) -> V_391 += V_34 ;
else
F_217 ( V_245 ) -> V_391 -= V_34 ;
V_372 = F_287 ( V_33 ) - sizeof( struct V_392 ) ;
V_387 = ( int ) F_220 ( V_372 ,
sizeof( struct V_393 ) +
sizeof( struct V_394 ) ) ;
V_388 = ( int ) F_220 ( F_217 ( V_245 ) -> V_391 , V_33 -> V_308 ) ;
V_388 = V_388 + V_387 - 1 ;
V_388 = V_388 / V_387 ;
V_389 = V_389 + V_387 - 1 ;
V_389 = V_389 / V_387 ;
if ( V_389 == V_388 )
return 0 ;
if ( V_386 )
return F_281 ( V_33 ,
V_388 - V_389 ) ;
return F_281 ( V_33 , V_389 - V_388 ) ;
}
int F_288 ( struct V_245 * V_245 , T_2 V_34 )
{
struct V_32 * V_33 = F_217 ( V_245 ) -> V_33 ;
struct V_320 * V_333 = & V_33 -> V_35 -> V_342 ;
T_2 V_395 = 0 ;
T_2 V_391 ;
unsigned V_396 = 0 ;
int V_397 = 0 ;
int V_279 = 1 ;
int V_27 ;
if ( F_289 ( V_33 , V_245 ) )
V_279 = 0 ;
if ( V_279 && F_290 ( V_33 -> V_35 ) )
F_184 ( 1 ) ;
F_34 ( & F_217 ( V_245 ) -> V_398 ) ;
V_34 = F_275 ( V_34 , V_33 -> V_308 ) ;
F_11 ( & F_217 ( V_245 ) -> V_49 ) ;
F_217 ( V_245 ) -> V_383 ++ ;
if ( F_217 ( V_245 ) -> V_383 >
F_217 ( V_245 ) -> V_385 )
V_396 = F_217 ( V_245 ) -> V_383 -
F_217 ( V_245 ) -> V_385 ;
if ( ! F_217 ( V_245 ) -> V_384 ) {
V_396 ++ ;
V_397 = 1 ;
}
V_395 = F_281 ( V_33 , V_396 ) ;
V_395 += F_286 ( V_245 , V_34 , 1 ) ;
V_391 = F_217 ( V_245 ) -> V_391 ;
F_13 ( & F_217 ( V_245 ) -> V_49 ) ;
V_27 = F_253 ( V_33 , V_333 , V_395 , V_279 ) ;
if ( V_27 ) {
T_2 V_399 = 0 ;
unsigned V_400 ;
F_11 ( & F_217 ( V_245 ) -> V_49 ) ;
V_400 = F_285 ( V_245 ) ;
if ( F_217 ( V_245 ) -> V_391 == V_391 )
F_286 ( V_245 , V_34 , 0 ) ;
else
V_399 = F_286 ( V_245 , V_34 , 0 ) ;
F_13 ( & F_217 ( V_245 ) -> V_49 ) ;
if ( V_400 )
V_399 += F_281 ( V_33 , V_400 ) ;
if ( V_399 ) {
F_264 ( V_33 , V_333 , V_399 ) ;
F_240 ( V_33 -> V_35 ,
L_6 ,
F_282 ( V_245 ) ,
V_399 , 0 ) ;
}
F_45 ( & F_217 ( V_245 ) -> V_398 ) ;
return V_27 ;
}
F_11 ( & F_217 ( V_245 ) -> V_49 ) ;
if ( V_397 ) {
F_217 ( V_245 ) -> V_384 = 1 ;
V_396 -- ;
}
F_217 ( V_245 ) -> V_385 += V_396 ;
F_13 ( & F_217 ( V_245 ) -> V_49 ) ;
F_45 ( & F_217 ( V_245 ) -> V_398 ) ;
if ( V_395 )
F_240 ( V_33 -> V_35 , L_6 ,
F_282 ( V_245 ) , V_395 , 1 ) ;
F_258 ( V_333 , V_395 , 1 ) ;
return 0 ;
}
void F_291 ( struct V_245 * V_245 , T_2 V_34 )
{
struct V_32 * V_33 = F_217 ( V_245 ) -> V_33 ;
T_2 V_399 = 0 ;
unsigned V_400 ;
V_34 = F_275 ( V_34 , V_33 -> V_308 ) ;
F_11 ( & F_217 ( V_245 ) -> V_49 ) ;
V_400 = F_285 ( V_245 ) ;
V_399 = F_286 ( V_245 , V_34 , 0 ) ;
F_13 ( & F_217 ( V_245 ) -> V_49 ) ;
if ( V_400 > 0 )
V_399 += F_281 ( V_33 , V_400 ) ;
F_240 ( V_33 -> V_35 , L_6 ,
F_282 ( V_245 ) , V_399 , 0 ) ;
F_264 ( V_33 , & V_33 -> V_35 -> V_342 ,
V_399 ) ;
}
int F_292 ( struct V_245 * V_245 , T_2 V_34 )
{
int V_27 ;
V_27 = F_221 ( V_245 , V_34 ) ;
if ( V_27 )
return V_27 ;
V_27 = F_288 ( V_245 , V_34 ) ;
if ( V_27 ) {
F_223 ( V_245 , V_34 ) ;
return V_27 ;
}
return 0 ;
}
void F_293 ( struct V_245 * V_245 , T_2 V_34 )
{
F_291 ( V_245 , V_34 ) ;
F_223 ( V_245 , V_34 ) ;
}
static int F_294 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
T_2 V_25 , T_2 V_34 , int V_311 )
{
struct V_1 * V_2 = NULL ;
struct V_11 * V_12 = V_33 -> V_35 ;
T_2 V_401 = V_34 ;
T_2 V_402 ;
T_2 V_403 ;
int V_105 ;
F_11 ( & V_12 -> V_404 ) ;
V_402 = F_295 ( V_12 -> V_326 ) ;
if ( V_311 )
V_402 += V_34 ;
else
V_402 -= V_34 ;
F_296 ( V_12 -> V_326 , V_402 ) ;
F_13 ( & V_12 -> V_404 ) ;
while ( V_401 ) {
V_2 = F_66 ( V_12 , V_25 ) ;
if ( ! V_2 )
return - 1 ;
if ( V_2 -> V_6 & ( V_265 |
V_266 |
V_267 ) )
V_105 = 2 ;
else
V_105 = 1 ;
if ( ! V_311 && V_2 -> V_3 == V_89 )
F_49 ( V_2 , V_83 , NULL , 1 ) ;
V_403 = V_25 - V_2 -> V_20 . V_21 ;
F_8 ( V_403 > V_2 -> V_20 . V_31 ) ;
F_11 ( & V_2 -> V_100 -> V_49 ) ;
F_11 ( & V_2 -> V_49 ) ;
if ( F_59 ( V_33 , V_93 ) &&
V_2 -> V_251 < V_259 )
V_2 -> V_251 = V_259 ;
V_2 -> V_260 = 1 ;
V_402 = F_77 ( & V_2 -> V_113 ) ;
V_34 = F_249 ( V_401 , V_2 -> V_20 . V_31 - V_403 ) ;
if ( V_311 ) {
V_402 += V_34 ;
F_297 ( & V_2 -> V_113 , V_402 ) ;
V_2 -> V_9 -= V_34 ;
V_2 -> V_100 -> V_274 -= V_34 ;
V_2 -> V_100 -> V_264 += V_34 ;
V_2 -> V_100 -> V_269 += V_34 * V_105 ;
F_13 ( & V_2 -> V_49 ) ;
F_13 ( & V_2 -> V_100 -> V_49 ) ;
} else {
V_402 -= V_34 ;
F_297 ( & V_2 -> V_113 , V_402 ) ;
V_2 -> V_8 += V_34 ;
V_2 -> V_100 -> V_273 += V_34 ;
V_2 -> V_100 -> V_264 -= V_34 ;
V_2 -> V_100 -> V_269 -= V_34 * V_105 ;
F_13 ( & V_2 -> V_49 ) ;
F_13 ( & V_2 -> V_100 -> V_49 ) ;
F_298 ( V_12 -> V_56 ,
V_25 , V_25 + V_34 - 1 ,
V_38 | V_405 ) ;
}
F_6 ( V_2 ) ;
V_401 -= V_34 ;
V_25 += V_34 ;
}
return 0 ;
}
static T_2 F_299 ( struct V_32 * V_33 , T_2 V_106 )
{
struct V_1 * V_2 ;
T_2 V_25 ;
V_2 = F_65 ( V_33 -> V_35 , V_106 ) ;
if ( ! V_2 )
return 0 ;
V_25 = V_2 -> V_20 . V_21 ;
F_6 ( V_2 ) ;
return V_25 ;
}
static int F_300 ( struct V_32 * V_33 ,
struct V_1 * V_2 ,
T_2 V_25 , T_2 V_34 , int V_9 )
{
F_11 ( & V_2 -> V_100 -> V_49 ) ;
F_11 ( & V_2 -> V_49 ) ;
V_2 -> V_8 += V_34 ;
V_2 -> V_100 -> V_273 += V_34 ;
if ( V_9 ) {
V_2 -> V_9 -= V_34 ;
V_2 -> V_100 -> V_274 -= V_34 ;
}
F_13 ( & V_2 -> V_49 ) ;
F_13 ( & V_2 -> V_100 -> V_49 ) ;
F_298 ( V_33 -> V_35 -> V_56 , V_25 ,
V_25 + V_34 - 1 , V_38 | V_405 ) ;
return 0 ;
}
int F_164 ( struct V_32 * V_33 ,
T_2 V_25 , T_2 V_34 , int V_9 )
{
struct V_1 * V_2 ;
V_2 = F_66 ( V_33 -> V_35 , V_25 ) ;
F_22 ( ! V_2 ) ;
F_300 ( V_33 , V_2 , V_25 , V_34 , V_9 ) ;
F_6 ( V_2 ) ;
return 0 ;
}
int F_301 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
T_2 V_25 , T_2 V_34 )
{
struct V_1 * V_2 ;
V_2 = F_66 ( V_33 -> V_35 , V_25 ) ;
F_22 ( ! V_2 ) ;
F_49 ( V_2 , V_83 , V_33 , 1 ) ;
F_300 ( V_33 , V_2 , V_25 , V_34 , 0 ) ;
F_302 ( V_2 , V_25 , V_34 ) ;
F_6 ( V_2 ) ;
return 0 ;
}
static int F_303 ( struct V_1 * V_2 ,
T_2 V_34 , int V_386 )
{
struct V_97 * V_100 = V_2 -> V_100 ;
int V_27 = 0 ;
F_11 ( & V_100 -> V_49 ) ;
F_11 ( & V_2 -> V_49 ) ;
if ( V_386 != V_406 ) {
if ( V_2 -> V_114 ) {
V_27 = - V_176 ;
} else {
V_2 -> V_9 += V_34 ;
V_100 -> V_274 += V_34 ;
if ( V_386 == V_407 ) {
F_240 ( V_2 -> V_35 ,
L_3 ,
( T_2 ) ( unsigned long ) V_100 ,
V_34 , 0 ) ;
V_100 -> V_276 -= V_34 ;
}
}
} else {
if ( V_2 -> V_114 )
V_100 -> V_275 += V_34 ;
V_2 -> V_9 -= V_34 ;
V_100 -> V_274 -= V_34 ;
V_100 -> V_343 ++ ;
}
F_13 ( & V_2 -> V_49 ) ;
F_13 ( & V_100 -> V_49 ) ;
return V_27 ;
}
int F_304 ( struct V_82 * V_83 ,
struct V_32 * V_33 )
{
struct V_11 * V_35 = V_33 -> V_35 ;
struct V_47 * V_216 ;
struct V_47 * V_51 ;
struct V_1 * V_2 ;
F_61 ( & V_35 -> V_76 ) ;
F_305 (caching_ctl, next,
&fs_info->caching_block_groups, list) {
V_2 = V_51 -> V_13 ;
if ( F_1 ( V_2 ) ) {
V_2 -> V_94 = ( T_2 ) - 1 ;
F_172 ( & V_51 -> V_85 ) ;
F_26 ( V_51 ) ;
} else {
V_2 -> V_94 = V_51 -> V_80 ;
}
}
if ( V_35 -> V_56 == & V_35 -> V_36 [ 0 ] )
V_35 -> V_56 = & V_35 -> V_36 [ 1 ] ;
else
V_35 -> V_56 = & V_35 -> V_36 [ 0 ] ;
F_63 ( & V_35 -> V_76 ) ;
F_276 ( V_35 ) ;
return 0 ;
}
static int F_306 ( struct V_32 * V_33 , T_2 V_30 , T_2 V_29 )
{
struct V_11 * V_35 = V_33 -> V_35 ;
struct V_1 * V_2 = NULL ;
T_2 V_116 ;
while ( V_30 <= V_29 ) {
if ( ! V_2 ||
V_30 >= V_2 -> V_20 . V_21 + V_2 -> V_20 . V_31 ) {
if ( V_2 )
F_6 ( V_2 ) ;
V_2 = F_66 ( V_35 , V_30 ) ;
F_22 ( ! V_2 ) ;
}
V_116 = V_2 -> V_20 . V_21 + V_2 -> V_20 . V_31 - V_30 ;
V_116 = F_249 ( V_116 , V_29 + 1 - V_30 ) ;
if ( V_30 < V_2 -> V_94 ) {
V_116 = F_249 ( V_116 , V_2 -> V_94 - V_30 ) ;
F_29 ( V_2 , V_30 , V_116 ) ;
}
V_30 += V_116 ;
F_11 ( & V_2 -> V_100 -> V_49 ) ;
F_11 ( & V_2 -> V_49 ) ;
V_2 -> V_8 -= V_116 ;
V_2 -> V_100 -> V_273 -= V_116 ;
if ( V_2 -> V_114 )
V_2 -> V_100 -> V_275 += V_116 ;
F_13 ( & V_2 -> V_49 ) ;
F_13 ( & V_2 -> V_100 -> V_49 ) ;
}
if ( V_2 )
F_6 ( V_2 ) ;
return 0 ;
}
int F_307 ( struct V_82 * V_83 ,
struct V_32 * V_33 )
{
struct V_11 * V_35 = V_33 -> V_35 ;
struct V_408 * V_409 ;
T_2 V_30 ;
T_2 V_29 ;
int V_27 ;
if ( V_35 -> V_56 == & V_35 -> V_36 [ 0 ] )
V_409 = & V_35 -> V_36 [ 1 ] ;
else
V_409 = & V_35 -> V_36 [ 0 ] ;
while ( 1 ) {
V_27 = F_28 ( V_409 , 0 , & V_30 , & V_29 ,
V_57 ) ;
if ( V_27 )
break;
if ( F_59 ( V_33 , V_410 ) )
V_27 = F_146 ( V_33 , V_30 ,
V_29 + 1 - V_30 , NULL ) ;
F_308 ( V_409 , V_30 , V_29 , V_38 ) ;
F_306 ( V_33 , V_30 , V_29 ) ;
F_46 () ;
}
return 0 ;
}
static int F_155 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
T_2 V_25 , T_2 V_34 , T_2 V_16 ,
T_2 V_147 , T_2 V_411 ,
T_2 V_412 , int V_160 ,
struct V_178 * V_132 )
{
struct V_65 V_20 ;
struct V_61 * V_62 ;
struct V_11 * V_12 = V_33 -> V_35 ;
struct V_32 * V_60 = V_12 -> V_60 ;
struct V_63 * V_64 ;
struct V_122 * V_123 ;
struct V_163 * V_164 ;
int V_27 ;
int V_182 ;
int V_413 = 0 ;
int V_414 = 0 ;
int V_415 = 1 ;
T_3 V_124 ;
T_2 V_118 ;
V_62 = F_32 () ;
if ( ! V_62 )
return - V_117 ;
V_62 -> V_72 = 1 ;
V_62 -> V_202 = 1 ;
V_182 = V_411 >= V_144 ;
F_22 ( ! V_182 && V_160 != 1 ) ;
V_27 = F_138 ( V_83 , V_60 , V_62 , & V_164 ,
V_25 , V_34 , V_16 ,
V_147 , V_411 ,
V_412 ) ;
if ( V_27 == 0 ) {
V_413 = V_62 -> V_79 [ 0 ] ;
while ( V_413 >= 0 ) {
F_39 ( V_62 -> V_78 [ 0 ] , & V_20 ,
V_413 ) ;
if ( V_20 . V_21 != V_25 )
break;
if ( V_20 . type == V_73 &&
V_20 . V_31 == V_34 ) {
V_414 = 1 ;
break;
}
if ( V_62 -> V_79 [ 0 ] - V_413 > 5 )
break;
V_413 -- ;
}
#ifdef F_85
V_124 = F_81 ( V_62 -> V_78 [ 0 ] , V_413 ) ;
if ( V_414 && V_124 < sizeof( * V_123 ) )
V_414 = 0 ;
#endif
if ( ! V_414 ) {
F_22 ( V_164 ) ;
V_27 = F_143 ( V_83 , V_60 , V_62 ,
NULL , V_160 ,
V_182 ) ;
F_22 ( V_27 ) ;
F_43 ( V_62 ) ;
V_62 -> V_202 = 1 ;
V_20 . V_21 = V_25 ;
V_20 . type = V_73 ;
V_20 . V_31 = V_34 ;
V_27 = F_36 ( V_83 , V_60 ,
& V_20 , V_62 , - 1 , 1 ) ;
if ( V_27 ) {
F_309 ( V_416 L_7
L_8 , V_27 ,
( unsigned long long ) V_25 ) ;
if ( V_27 > 0 )
F_310 ( V_60 ,
V_62 -> V_78 [ 0 ] ) ;
}
F_22 ( V_27 ) ;
V_413 = V_62 -> V_79 [ 0 ] ;
}
} else {
F_310 ( V_60 , V_62 -> V_78 [ 0 ] ) ;
F_8 ( 1 ) ;
F_309 ( V_416 L_9
L_10 ,
( unsigned long long ) V_25 ,
( unsigned long long ) V_16 ,
( unsigned long long ) V_147 ,
( unsigned long long ) V_411 ,
( unsigned long long ) V_412 ) ;
}
V_64 = V_62 -> V_78 [ 0 ] ;
V_124 = F_81 ( V_64 , V_413 ) ;
#ifdef F_85
if ( V_124 < sizeof( * V_123 ) ) {
F_22 ( V_414 || V_413 != V_62 -> V_79 [ 0 ] ) ;
V_27 = F_91 ( V_83 , V_60 , V_62 ,
V_411 , 0 ) ;
F_22 ( V_27 < 0 ) ;
F_43 ( V_62 ) ;
V_62 -> V_202 = 1 ;
V_20 . V_21 = V_25 ;
V_20 . type = V_73 ;
V_20 . V_31 = V_34 ;
V_27 = F_36 ( V_83 , V_60 , & V_20 , V_62 ,
- 1 , 1 ) ;
if ( V_27 ) {
F_309 ( V_416 L_7
L_8 , V_27 ,
( unsigned long long ) V_25 ) ;
F_310 ( V_60 , V_62 -> V_78 [ 0 ] ) ;
}
F_22 ( V_27 ) ;
V_413 = V_62 -> V_79 [ 0 ] ;
V_64 = V_62 -> V_78 [ 0 ] ;
V_124 = F_81 ( V_64 , V_413 ) ;
}
#endif
F_22 ( V_124 < sizeof( * V_123 ) ) ;
V_123 = F_82 ( V_64 , V_413 ,
struct V_122 ) ;
if ( V_411 < V_144 ) {
struct V_139 * V_140 ;
F_22 ( V_124 < sizeof( * V_123 ) + sizeof( * V_140 ) ) ;
V_140 = (struct V_139 * ) ( V_123 + 1 ) ;
F_8 ( V_411 != F_311 ( V_64 , V_140 ) ) ;
}
V_118 = F_83 ( V_64 , V_123 ) ;
F_22 ( V_118 < V_160 ) ;
V_118 -= V_160 ;
if ( V_118 > 0 ) {
if ( V_132 )
F_134 ( V_132 , V_64 , V_123 ) ;
if ( V_164 ) {
F_22 ( ! V_414 ) ;
} else {
F_94 ( V_64 , V_123 , V_118 ) ;
F_99 ( V_64 ) ;
}
if ( V_414 ) {
V_27 = F_143 ( V_83 , V_60 , V_62 ,
V_164 , V_160 ,
V_182 ) ;
F_22 ( V_27 ) ;
}
} else {
if ( V_414 ) {
F_22 ( V_182 && V_160 !=
F_122 ( V_33 , V_62 , V_164 ) ) ;
if ( V_164 ) {
F_22 ( V_62 -> V_79 [ 0 ] != V_413 ) ;
} else {
F_22 ( V_62 -> V_79 [ 0 ] != V_413 + 1 ) ;
V_62 -> V_79 [ 0 ] = V_413 ;
V_415 = 2 ;
}
}
V_27 = F_312 ( V_83 , V_60 , V_62 , V_62 -> V_79 [ 0 ] ,
V_415 ) ;
F_22 ( V_27 ) ;
F_43 ( V_62 ) ;
if ( V_182 ) {
V_27 = F_165 ( V_83 , V_33 , V_25 , V_34 ) ;
F_22 ( V_27 ) ;
} else {
F_313 ( V_12 -> V_417 -> V_418 ,
V_25 >> V_338 ,
( V_25 + V_34 - 1 ) >> V_338 ) ;
}
V_27 = F_294 ( V_83 , V_33 , V_25 , V_34 , 0 ) ;
F_22 ( V_27 ) ;
}
F_48 ( V_62 ) ;
return V_27 ;
}
static T_1 int F_314 ( struct V_82 * V_83 ,
struct V_32 * V_33 , T_2 V_25 )
{
struct V_119 * V_99 ;
struct V_120 * V_121 ;
struct V_203 * V_152 ;
struct V_14 * V_131 ;
int V_27 = 0 ;
V_121 = & V_83 -> V_90 -> V_121 ;
F_11 ( & V_121 -> V_49 ) ;
V_99 = F_88 ( V_83 , V_25 ) ;
if ( ! V_99 )
goto V_69;
V_131 = F_189 ( & V_99 -> V_131 . V_14 ) ;
if ( ! V_131 )
goto V_69;
V_152 = F_12 ( V_131 , struct V_203 , V_14 ) ;
if ( V_152 -> V_25 == V_25 )
goto V_69;
if ( V_99 -> V_132 ) {
if ( ! V_99 -> V_215 )
goto V_69;
F_9 ( V_99 -> V_132 ) ;
V_99 -> V_132 = NULL ;
}
if ( ! F_89 ( & V_99 -> V_75 ) )
goto V_69;
V_99 -> V_131 . V_219 = 0 ;
F_173 ( & V_99 -> V_131 . V_14 , & V_121 -> V_33 ) ;
V_121 -> V_220 -- ;
if ( F_315 ( & V_121 -> V_224 ) )
F_47 ( & V_121 -> V_224 ) ;
V_121 -> V_419 -- ;
if ( F_167 ( & V_99 -> V_213 ) )
V_121 -> V_218 -- ;
F_172 ( & V_99 -> V_213 ) ;
F_13 ( & V_121 -> V_49 ) ;
F_22 ( V_99 -> V_132 ) ;
if ( V_99 -> V_215 )
V_27 = 1 ;
F_45 ( & V_99 -> V_75 ) ;
F_90 ( & V_99 -> V_131 ) ;
return V_27 ;
V_69:
F_13 ( & V_121 -> V_49 ) ;
return 0 ;
}
void F_316 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_63 * V_236 ,
T_2 V_16 , int V_420 , int V_199 )
{
struct V_1 * V_2 = NULL ;
int V_27 ;
if ( V_33 -> V_232 . V_21 != V_200 ) {
V_27 = F_149 ( V_33 -> V_35 , V_83 ,
V_236 -> V_30 , V_236 -> V_116 ,
V_16 , V_33 -> V_232 . V_21 ,
F_197 ( V_236 ) ,
V_210 , NULL , V_199 ) ;
F_22 ( V_27 ) ;
}
if ( ! V_420 )
return;
V_2 = F_66 ( V_33 -> V_35 , V_236 -> V_30 ) ;
if ( F_317 ( V_236 ) == V_83 -> V_254 ) {
if ( V_33 -> V_232 . V_21 != V_200 ) {
V_27 = F_314 ( V_83 , V_33 , V_236 -> V_30 ) ;
if ( ! V_27 )
goto V_69;
}
if ( F_318 ( V_236 , V_421 ) ) {
F_300 ( V_33 , V_2 , V_236 -> V_30 , V_236 -> V_116 , 1 ) ;
goto V_69;
}
F_8 ( F_319 ( V_422 , & V_236 -> V_423 ) ) ;
F_29 ( V_2 , V_236 -> V_30 , V_236 -> V_116 ) ;
F_303 ( V_2 , V_236 -> V_116 , V_406 ) ;
}
V_69:
F_320 ( V_424 , & V_236 -> V_423 ) ;
F_6 ( V_2 ) ;
}
int V_242 ( struct V_82 * V_83 , struct V_32 * V_33 ,
T_2 V_25 , T_2 V_34 , T_2 V_16 , T_2 V_147 ,
T_2 V_108 , T_2 V_31 , int V_199 )
{
int V_27 ;
struct V_11 * V_35 = V_33 -> V_35 ;
if ( V_147 == V_200 ) {
F_8 ( V_108 >= V_144 ) ;
F_164 ( V_33 , V_25 , V_34 , 1 ) ;
V_27 = 0 ;
} else if ( V_108 < V_144 ) {
V_27 = F_149 ( V_35 , V_83 , V_25 ,
V_34 ,
V_16 , V_147 , ( int ) V_108 ,
V_210 , NULL , V_199 ) ;
F_22 ( V_27 ) ;
} else {
V_27 = F_150 ( V_35 , V_83 , V_25 ,
V_34 ,
V_16 , V_147 , V_108 ,
V_31 , V_210 ,
NULL , V_199 ) ;
F_22 ( V_27 ) ;
}
return V_27 ;
}
static T_2 F_321 ( struct V_32 * V_33 , T_2 V_425 )
{
T_2 V_426 = ( ( T_2 ) V_33 -> V_427 - 1 ) ;
T_2 V_27 = ( V_425 + V_426 ) & ~ V_426 ;
return V_27 ;
}
static T_1 int
F_322 ( struct V_1 * V_2 ,
T_2 V_34 )
{
struct V_47 * V_51 ;
F_50 ( V_81 ) ;
V_51 = F_25 ( V_2 ) ;
if ( ! V_51 )
return 0 ;
F_178 ( V_51 -> V_81 , F_1 ( V_2 ) ||
( V_2 -> V_10 -> V_428 >= V_34 ) ) ;
F_26 ( V_51 ) ;
return 0 ;
}
static T_1 int
F_323 ( struct V_1 * V_2 )
{
struct V_47 * V_51 ;
F_50 ( V_81 ) ;
V_51 = F_25 ( V_2 ) ;
if ( ! V_51 )
return 0 ;
F_178 ( V_51 -> V_81 , F_1 ( V_2 ) ) ;
F_26 ( V_51 ) ;
return 0 ;
}
static int F_324 ( struct V_1 * V_2 )
{
int V_429 ;
if ( V_2 -> V_6 & V_267 )
V_429 = 0 ;
else if ( V_2 -> V_6 & V_266 )
V_429 = 1 ;
else if ( V_2 -> V_6 & V_265 )
V_429 = 2 ;
else if ( V_2 -> V_6 & V_302 )
V_429 = 3 ;
else
V_429 = 4 ;
return V_429 ;
}
static T_1 int F_325 ( struct V_82 * V_83 ,
struct V_32 * V_430 ,
T_2 V_34 , T_2 V_431 ,
T_2 V_106 , T_2 V_432 ,
T_2 V_433 , struct V_65 * V_206 ,
T_2 V_297 )
{
int V_27 = 0 ;
struct V_32 * V_33 = V_430 -> V_35 -> V_60 ;
struct V_434 * V_435 = NULL ;
struct V_1 * V_13 = NULL ;
struct V_1 * V_436 ;
int V_437 = 2 * 1024 * 1024 ;
int V_438 = 0 ;
int V_439 = 0 ;
struct V_97 * V_100 ;
int V_440 = 0 ;
int V_429 = 0 ;
int V_441 = ( V_297 & V_283 ) ?
V_442 : V_407 ;
bool V_443 = false ;
bool V_444 = false ;
bool V_445 = false ;
bool V_446 = true ;
bool V_447 = false ;
T_2 V_448 = 0 ;
T_2 V_449 = 0 ;
F_8 ( V_34 < V_33 -> V_308 ) ;
F_79 ( V_206 , V_73 ) ;
V_206 -> V_21 = 0 ;
V_206 -> V_31 = 0 ;
F_326 ( V_430 , V_34 , V_431 , V_297 ) ;
V_100 = F_67 ( V_33 -> V_35 , V_297 ) ;
if ( ! V_100 ) {
F_309 ( V_416 L_11 , V_297 ) ;
return - V_314 ;
}
if ( F_245 ( V_100 ) )
V_446 = false ;
if ( V_430 -> V_241 || V_431 )
V_438 = 1 ;
if ( V_297 & V_115 && V_446 ) {
V_435 = & V_33 -> V_35 -> V_450 ;
if ( ! F_59 ( V_33 , V_451 ) )
V_437 = 64 * 1024 ;
}
if ( ( V_297 & V_283 ) && V_446 &&
F_59 ( V_33 , V_451 ) ) {
V_435 = & V_33 -> V_35 -> V_452 ;
}
if ( V_435 ) {
F_11 ( & V_435 -> V_49 ) ;
if ( V_435 -> V_13 )
V_433 = V_435 -> V_453 ;
F_13 ( & V_435 -> V_49 ) ;
}
V_106 = F_76 ( V_106 , F_299 ( V_33 , 0 ) ) ;
V_106 = F_76 ( V_106 , V_433 ) ;
if ( ! V_435 )
V_437 = 0 ;
if ( V_106 == V_433 ) {
V_454:
V_13 = F_66 ( V_33 -> V_35 ,
V_106 ) ;
V_436 = V_13 ;
if ( V_13 && F_3 ( V_13 , V_297 ) &&
( V_13 -> V_3 != V_89 ||
V_106 == V_449 ) ) {
F_35 ( & V_100 -> V_272 ) ;
if ( F_167 ( & V_13 -> V_85 ) ||
V_13 -> V_114 ) {
F_6 ( V_13 ) ;
F_44 ( & V_100 -> V_272 ) ;
} else {
V_429 = F_324 ( V_13 ) ;
goto V_455;
}
} else if ( V_13 ) {
F_6 ( V_13 ) ;
}
}
V_456:
V_447 = false ;
F_35 ( & V_100 -> V_272 ) ;
F_327 (block_group, &space_info->block_groups[index],
list) {
T_2 V_31 ;
int V_3 ;
V_436 = V_13 ;
F_4 ( V_13 ) ;
V_106 = V_13 -> V_20 . V_21 ;
if ( ! F_3 ( V_13 , V_297 ) ) {
T_2 V_457 = V_265 |
V_266 |
V_267 ;
if ( ( V_297 & V_457 ) && ! ( V_13 -> V_6 & V_457 ) )
goto V_440;
}
V_455:
V_3 = F_1 ( V_13 ) ;
if ( F_328 ( ! V_3 ) ) {
T_2 V_458 ;
V_443 = true ;
V_27 = F_49 ( V_13 , V_83 ,
V_430 , 1 ) ;
if ( V_13 -> V_3 == V_4 )
goto V_311;
V_458 = F_77 ( & V_13 -> V_113 ) ;
V_458 *= 100 ;
V_458 = F_220 ( V_458 ,
V_13 -> V_20 . V_31 ) ;
V_458 = 100 - V_458 ;
if ( V_458 > V_448 &&
F_329 ( ! V_13 -> V_114 ) ) {
V_449 = V_13 -> V_20 . V_21 ;
V_448 = V_458 ;
}
if ( V_440 > V_459 ) {
V_27 = F_49 ( V_13 , V_83 ,
V_430 , 0 ) ;
F_22 ( V_27 ) ;
}
if ( V_440 == V_459 )
goto V_440;
}
V_311:
if ( F_328 ( V_13 -> V_114 ) )
goto V_440;
if ( V_435 ) {
F_11 ( & V_435 -> V_460 ) ;
V_436 = V_435 -> V_13 ;
if ( V_436 != V_13 &&
( ! V_436 ||
V_436 -> V_114 ||
! F_3 ( V_436 , V_297 ) ) ) {
V_436 = V_13 ;
goto V_461;
}
if ( V_436 != V_13 )
F_4 ( V_436 ) ;
V_31 = F_330 ( V_436 ,
V_435 , V_34 , V_436 -> V_20 . V_21 ) ;
if ( V_31 ) {
F_13 ( & V_435 -> V_460 ) ;
F_331 ( V_33 ,
V_13 , V_106 , V_34 ) ;
goto V_462;
}
F_8 ( V_435 -> V_13 != V_436 ) ;
if ( V_436 != V_13 ) {
F_6 ( V_436 ) ;
V_436 = V_13 ;
}
V_461:
F_22 ( V_436 != V_13 ) ;
if ( V_440 >= V_463 &&
V_435 -> V_13 != V_13 ) {
F_13 ( & V_435 -> V_460 ) ;
goto V_464;
}
F_332 ( NULL , V_435 ) ;
if ( V_440 >= V_463 ) {
F_13 ( & V_435 -> V_460 ) ;
goto V_464;
}
V_27 = F_333 ( V_83 , V_33 ,
V_13 , V_435 ,
V_106 , V_34 ,
V_437 + V_431 ) ;
if ( V_27 == 0 ) {
V_31 = F_330 ( V_13 ,
V_435 , V_34 ,
V_106 ) ;
if ( V_31 ) {
F_13 ( & V_435 -> V_460 ) ;
F_331 ( V_33 ,
V_13 , V_106 ,
V_34 ) ;
goto V_462;
}
} else if ( ! V_3 && V_440 > V_465
&& ! V_444 ) {
F_13 ( & V_435 -> V_460 ) ;
V_444 = true ;
F_322 ( V_13 ,
V_34 + V_437 + V_431 ) ;
goto V_455;
}
F_332 ( NULL , V_435 ) ;
F_13 ( & V_435 -> V_460 ) ;
goto V_440;
}
V_464:
F_11 ( & V_13 -> V_10 -> V_466 ) ;
if ( V_3 &&
V_13 -> V_10 -> V_428 <
V_34 + V_437 + V_431 ) {
F_13 ( & V_13 -> V_10 -> V_466 ) ;
goto V_440;
}
F_13 ( & V_13 -> V_10 -> V_466 ) ;
V_31 = F_334 ( V_13 , V_106 ,
V_34 , V_431 ) ;
if ( ! V_31 && ! V_445 && ! V_3 &&
V_440 > V_465 ) {
F_322 ( V_13 ,
V_34 + V_431 ) ;
V_445 = true ;
goto V_455;
} else if ( ! V_31 ) {
if ( ! V_3 )
V_447 = true ;
goto V_440;
}
V_462:
V_106 = F_321 ( V_33 , V_31 ) ;
if ( V_106 + V_34 >= V_432 ) {
F_29 ( V_436 , V_31 , V_34 ) ;
goto V_440;
}
if ( V_106 + V_34 >
V_436 -> V_20 . V_21 + V_436 -> V_20 . V_31 ) {
F_29 ( V_436 , V_31 , V_34 ) ;
goto V_440;
}
if ( V_31 < V_106 )
F_29 ( V_436 , V_31 ,
V_106 - V_31 ) ;
F_22 ( V_31 > V_106 ) ;
V_27 = F_303 ( V_436 , V_34 ,
V_441 ) ;
if ( V_27 == - V_176 ) {
F_29 ( V_436 , V_31 , V_34 ) ;
goto V_440;
}
V_206 -> V_21 = V_106 ;
V_206 -> V_31 = V_34 ;
F_335 ( V_430 , V_13 ,
V_106 , V_34 ) ;
if ( V_31 < V_106 )
F_29 ( V_436 , V_31 ,
V_106 - V_31 ) ;
F_22 ( V_31 > V_106 ) ;
if ( V_436 != V_13 )
F_6 ( V_436 ) ;
F_6 ( V_13 ) ;
break;
V_440:
V_444 = false ;
V_445 = false ;
F_22 ( V_429 != F_324 ( V_13 ) ) ;
if ( V_436 != V_13 )
F_6 ( V_436 ) ;
F_6 ( V_13 ) ;
}
F_44 ( & V_100 -> V_272 ) ;
if ( ! V_206 -> V_21 && V_440 >= V_467 && V_447 )
goto V_456;
if ( ! V_206 -> V_21 && ++ V_429 < V_270 )
goto V_456;
if ( ! V_206 -> V_21 && V_440 < V_463 ) {
V_429 = 0 ;
if ( V_440 == V_459 && V_443 ) {
V_443 = false ;
V_440 ++ ;
if ( ! V_448 )
goto V_456;
V_440 = V_467 ;
V_106 = V_449 ;
V_448 = 0 ;
goto V_454;
} else if ( V_440 == V_459 ) {
V_440 = V_467 ;
goto V_456;
}
V_440 ++ ;
if ( V_440 == V_468 ) {
if ( V_438 ) {
V_27 = F_174 ( V_83 , V_33 , V_34 +
2 * 1024 * 1024 , V_297 ,
V_325 ) ;
V_438 = 0 ;
if ( V_27 == 1 )
V_439 = 1 ;
} else if ( ! V_439 &&
V_100 -> V_277 ==
V_221 ) {
V_100 -> V_277 = V_325 ;
}
if ( ! V_439 )
V_440 = V_463 ;
}
if ( V_440 == V_463 ) {
V_431 = 0 ;
V_437 = 0 ;
}
goto V_456;
} else if ( ! V_206 -> V_21 ) {
V_27 = - V_314 ;
} else if ( V_206 -> V_21 ) {
V_27 = 0 ;
}
return V_27 ;
}
static void F_336 ( struct V_97 * V_12 , T_2 V_304 ,
int V_469 )
{
struct V_1 * V_2 ;
int V_429 = 0 ;
F_11 ( & V_12 -> V_49 ) ;
F_309 ( V_470 L_12 ,
( unsigned long long ) V_12 -> V_6 ,
( unsigned long long ) ( V_12 -> V_263 - V_12 -> V_264 -
V_12 -> V_273 - V_12 -> V_274 -
V_12 -> V_275 ) ,
( V_12 -> V_103 ) ? L_13 : L_14 ) ;
F_309 ( V_470 L_15
L_16 ,
( unsigned long long ) V_12 -> V_263 ,
( unsigned long long ) V_12 -> V_264 ,
( unsigned long long ) V_12 -> V_273 ,
( unsigned long long ) V_12 -> V_274 ,
( unsigned long long ) V_12 -> V_276 ,
( unsigned long long ) V_12 -> V_275 ) ;
F_13 ( & V_12 -> V_49 ) ;
if ( ! V_469 )
return;
F_35 ( & V_12 -> V_272 ) ;
V_74:
F_327 (cache, &info->block_groups[index], list) {
F_11 ( & V_2 -> V_49 ) ;
F_309 ( V_470 L_17
L_18 ,
( unsigned long long ) V_2 -> V_20 . V_21 ,
( unsigned long long ) V_2 -> V_20 . V_31 ,
( unsigned long long ) F_77 ( & V_2 -> V_113 ) ,
( unsigned long long ) V_2 -> V_8 ,
( unsigned long long ) V_2 -> V_9 ) ;
F_337 ( V_2 , V_304 ) ;
F_13 ( & V_2 -> V_49 ) ;
}
if ( ++ V_429 < V_270 )
goto V_74;
F_44 ( & V_12 -> V_272 ) ;
}
int F_338 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
T_2 V_34 , T_2 V_471 ,
T_2 V_431 , T_2 V_433 ,
T_2 V_432 , struct V_65 * V_206 ,
T_2 V_297 )
{
bool V_472 = false ;
int V_27 ;
T_2 V_106 = 0 ;
V_297 = F_175 ( V_33 , V_297 ) ;
V_74:
if ( V_431 || V_33 -> V_241 )
V_27 = F_174 ( V_83 , V_33 -> V_35 -> V_60 ,
V_34 + 2 * 1024 * 1024 , V_297 ,
V_221 ) ;
F_8 ( V_34 < V_33 -> V_308 ) ;
V_27 = F_325 ( V_83 , V_33 , V_34 , V_431 ,
V_106 , V_432 , V_433 ,
V_206 , V_297 ) ;
if ( V_27 == - V_314 ) {
if ( ! V_472 ) {
V_34 = V_34 >> 1 ;
V_34 = V_34 & ~ ( V_33 -> V_308 - 1 ) ;
V_34 = F_76 ( V_34 , V_471 ) ;
F_174 ( V_83 , V_33 -> V_35 -> V_60 ,
V_34 , V_297 , V_313 ) ;
if ( V_34 == V_471 )
V_472 = true ;
goto V_74;
} else if ( F_59 ( V_33 , V_473 ) ) {
struct V_97 * V_317 ;
V_317 = F_67 ( V_33 -> V_35 , V_297 ) ;
F_309 ( V_416 L_19
L_20 , ( unsigned long long ) V_297 ,
( unsigned long long ) V_34 ) ;
F_336 ( V_317 , V_34 , 1 ) ;
}
}
F_339 ( V_33 , V_206 -> V_21 , V_206 -> V_31 ) ;
return V_27 ;
}
static int F_340 ( struct V_32 * V_33 ,
T_2 V_30 , T_2 V_116 , int V_474 )
{
struct V_1 * V_2 ;
int V_27 = 0 ;
V_2 = F_66 ( V_33 -> V_35 , V_30 ) ;
if ( ! V_2 ) {
F_309 ( V_416 L_21 ,
( unsigned long long ) V_30 ) ;
return - V_314 ;
}
if ( F_59 ( V_33 , V_410 ) )
V_27 = F_146 ( V_33 , V_30 , V_116 , NULL ) ;
if ( V_474 )
F_300 ( V_33 , V_2 , V_30 , V_116 , 1 ) ;
else {
F_29 ( V_2 , V_30 , V_116 ) ;
F_303 ( V_2 , V_116 , V_406 ) ;
}
F_6 ( V_2 ) ;
F_341 ( V_33 , V_30 , V_116 ) ;
return V_27 ;
}
int F_342 ( struct V_32 * V_33 ,
T_2 V_30 , T_2 V_116 )
{
return F_340 ( V_33 , V_30 , V_116 , 0 ) ;
}
int F_343 ( struct V_32 * V_33 ,
T_2 V_30 , T_2 V_116 )
{
return F_340 ( V_33 , V_30 , V_116 , 1 ) ;
}
static int F_154 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
T_2 V_16 , T_2 V_147 ,
T_2 V_6 , T_2 V_108 , T_2 V_31 ,
struct V_65 * V_206 , int V_135 )
{
int V_27 ;
struct V_11 * V_35 = V_33 -> V_35 ;
struct V_122 * V_475 ;
struct V_163 * V_164 ;
struct V_61 * V_62 ;
struct V_63 * V_64 ;
int type ;
T_3 V_54 ;
if ( V_16 > 0 )
type = V_155 ;
else
type = V_156 ;
V_54 = sizeof( * V_475 ) + F_129 ( type ) ;
V_62 = F_32 () ;
if ( ! V_62 )
return - V_117 ;
V_62 -> V_202 = 1 ;
V_27 = F_110 ( V_83 , V_35 -> V_60 , V_62 ,
V_206 , V_54 ) ;
F_22 ( V_27 ) ;
V_64 = V_62 -> V_78 [ 0 ] ;
V_475 = F_82 ( V_64 , V_62 -> V_79 [ 0 ] ,
struct V_122 ) ;
F_94 ( V_64 , V_475 , V_135 ) ;
F_95 ( V_64 , V_475 , V_83 -> V_254 ) ;
F_96 ( V_64 , V_475 ,
V_6 | V_146 ) ;
V_164 = (struct V_163 * ) ( V_475 + 1 ) ;
F_136 ( V_64 , V_164 , type ) ;
if ( V_16 > 0 ) {
struct V_159 * V_152 ;
V_152 = (struct V_159 * ) ( V_164 + 1 ) ;
F_137 ( V_64 , V_164 , V_16 ) ;
F_111 ( V_64 , V_152 , V_135 ) ;
} else {
struct V_151 * V_152 ;
V_152 = (struct V_151 * ) ( & V_164 -> V_31 ) ;
F_113 ( V_64 , V_152 , V_147 ) ;
F_114 ( V_64 , V_152 , V_108 ) ;
F_115 ( V_64 , V_152 , V_31 ) ;
F_116 ( V_64 , V_152 , V_135 ) ;
}
F_99 ( V_62 -> V_78 [ 0 ] ) ;
F_48 ( V_62 ) ;
V_27 = F_294 ( V_83 , V_33 , V_206 -> V_21 , V_206 -> V_31 , 1 ) ;
if ( V_27 ) {
F_309 ( V_416 L_22
L_23 , ( unsigned long long ) V_206 -> V_21 ,
( unsigned long long ) V_206 -> V_31 ) ;
F_87 () ;
}
return V_27 ;
}
static int F_160 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
T_2 V_16 , T_2 V_147 ,
T_2 V_6 , struct V_394 * V_20 ,
int V_167 , struct V_65 * V_206 )
{
int V_27 ;
struct V_11 * V_35 = V_33 -> V_35 ;
struct V_122 * V_475 ;
struct V_139 * V_476 ;
struct V_163 * V_164 ;
struct V_61 * V_62 ;
struct V_63 * V_64 ;
T_3 V_54 = sizeof( * V_475 ) + sizeof( * V_476 ) + sizeof( * V_164 ) ;
V_62 = F_32 () ;
if ( ! V_62 )
return - V_117 ;
V_62 -> V_202 = 1 ;
V_27 = F_110 ( V_83 , V_35 -> V_60 , V_62 ,
V_206 , V_54 ) ;
F_22 ( V_27 ) ;
V_64 = V_62 -> V_78 [ 0 ] ;
V_475 = F_82 ( V_64 , V_62 -> V_79 [ 0 ] ,
struct V_122 ) ;
F_94 ( V_64 , V_475 , 1 ) ;
F_95 ( V_64 , V_475 , V_83 -> V_254 ) ;
F_96 ( V_64 , V_475 ,
V_6 | V_145 ) ;
V_476 = (struct V_139 * ) ( V_475 + 1 ) ;
F_156 ( V_64 , V_476 , V_20 ) ;
F_98 ( V_64 , V_476 , V_167 ) ;
V_164 = (struct V_163 * ) ( V_476 + 1 ) ;
if ( V_16 > 0 ) {
F_22 ( ! ( V_6 & V_130 ) ) ;
F_136 ( V_64 , V_164 ,
V_165 ) ;
F_137 ( V_64 , V_164 , V_16 ) ;
} else {
F_136 ( V_64 , V_164 ,
V_166 ) ;
F_137 ( V_64 , V_164 , V_147 ) ;
}
F_99 ( V_64 ) ;
F_48 ( V_62 ) ;
V_27 = F_294 ( V_83 , V_33 , V_206 -> V_21 , V_206 -> V_31 , 1 ) ;
if ( V_27 ) {
F_309 ( V_416 L_22
L_23 , ( unsigned long long ) V_206 -> V_21 ,
( unsigned long long ) V_206 -> V_31 ) ;
F_87 () ;
}
return V_27 ;
}
int F_344 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
T_2 V_147 , T_2 V_108 ,
T_2 V_31 , struct V_65 * V_206 )
{
int V_27 ;
F_22 ( V_147 == V_200 ) ;
V_27 = F_150 ( V_33 -> V_35 , V_83 , V_206 -> V_21 ,
V_206 -> V_31 , 0 ,
V_147 , V_108 , V_31 ,
V_477 , NULL , 0 ) ;
return V_27 ;
}
int F_345 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
T_2 V_147 , T_2 V_108 , T_2 V_31 ,
struct V_65 * V_206 )
{
int V_27 ;
struct V_1 * V_13 ;
struct V_47 * V_51 ;
T_2 V_30 = V_206 -> V_21 ;
T_2 V_34 = V_206 -> V_31 ;
V_13 = F_66 ( V_33 -> V_35 , V_206 -> V_21 ) ;
F_49 ( V_13 , V_83 , NULL , 0 ) ;
V_51 = F_25 ( V_13 ) ;
if ( ! V_51 ) {
F_22 ( ! F_1 ( V_13 ) ) ;
V_27 = F_302 ( V_13 , V_30 , V_34 ) ;
F_22 ( V_27 ) ;
} else {
F_34 ( & V_51 -> V_75 ) ;
if ( V_30 >= V_51 -> V_80 ) {
V_27 = F_17 ( V_33 , V_30 , V_34 ) ;
F_22 ( V_27 ) ;
} else if ( V_30 + V_34 <= V_51 -> V_80 ) {
V_27 = F_302 ( V_13 ,
V_30 , V_34 ) ;
F_22 ( V_27 ) ;
} else {
V_34 = V_51 -> V_80 - V_30 ;
V_27 = F_302 ( V_13 ,
V_30 , V_34 ) ;
F_22 ( V_27 ) ;
V_30 = V_51 -> V_80 ;
V_34 = V_206 -> V_21 + V_206 -> V_31 -
V_51 -> V_80 ;
V_27 = F_17 ( V_33 , V_30 , V_34 ) ;
F_22 ( V_27 ) ;
}
F_45 ( & V_51 -> V_75 ) ;
F_26 ( V_51 ) ;
}
V_27 = F_303 ( V_13 , V_206 -> V_31 ,
V_442 ) ;
F_22 ( V_27 ) ;
F_6 ( V_13 ) ;
V_27 = F_154 ( V_83 , V_33 , 0 , V_147 ,
0 , V_108 , V_31 , V_206 , 1 ) ;
return V_27 ;
}
struct V_63 * F_346 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
T_2 V_25 , T_3 V_478 ,
int V_167 )
{
struct V_63 * V_236 ;
V_236 = F_347 ( V_33 , V_25 , V_478 ) ;
if ( ! V_236 )
return F_348 ( - V_117 ) ;
F_349 ( V_236 , V_83 -> V_254 ) ;
F_350 ( V_33 -> V_232 . V_21 , V_236 , V_167 ) ;
F_351 ( V_236 ) ;
F_352 ( V_83 , V_33 , V_236 ) ;
F_353 ( V_236 ) ;
F_354 ( V_236 ) ;
if ( V_33 -> V_232 . V_21 == V_200 ) {
if ( V_33 -> V_479 % 2 == 0 )
F_298 ( & V_33 -> V_480 , V_236 -> V_30 ,
V_236 -> V_30 + V_236 -> V_116 - 1 , V_38 ) ;
else
F_355 ( & V_33 -> V_480 , V_236 -> V_30 ,
V_236 -> V_30 + V_236 -> V_116 - 1 , V_38 ) ;
} else {
F_298 ( & V_83 -> V_90 -> V_481 , V_236 -> V_30 ,
V_236 -> V_30 + V_236 -> V_116 - 1 , V_38 ) ;
}
V_83 -> V_482 ++ ;
return V_236 ;
}
static struct V_320 *
F_356 ( struct V_82 * V_83 ,
struct V_32 * V_33 , T_3 V_478 )
{
struct V_320 * V_333 ;
struct V_320 * V_321 = & V_33 -> V_35 -> V_322 ;
int V_27 ;
V_333 = F_256 ( V_83 , V_33 ) ;
if ( V_333 -> V_54 == 0 ) {
V_27 = F_253 ( V_33 , V_333 , V_478 , 0 ) ;
if ( V_27 && V_333 != V_321 ) {
V_27 = F_257 ( V_321 , V_478 ) ;
if ( ! V_27 )
return V_321 ;
return F_348 ( V_27 ) ;
} else if ( V_27 ) {
return F_348 ( V_27 ) ;
}
return V_333 ;
}
V_27 = F_257 ( V_333 , V_478 ) ;
if ( ! V_27 )
return V_333 ;
if ( V_27 ) {
static F_357 ( V_483 ,
V_484 ,
2 ) ;
if ( F_358 ( & V_483 ) ) {
F_309 ( V_485 L_24 , V_27 ) ;
F_8 ( 1 ) ;
}
V_27 = F_253 ( V_33 , V_333 , V_478 , 0 ) ;
if ( ! V_27 ) {
return V_333 ;
} else if ( V_27 && V_333 != V_321 ) {
V_27 = F_257 ( V_321 , V_478 ) ;
if ( ! V_27 )
return V_321 ;
}
}
return F_348 ( - V_314 ) ;
}
static void F_359 ( struct V_11 * V_35 ,
struct V_320 * V_333 , T_3 V_478 )
{
F_258 ( V_333 , V_478 , 0 ) ;
F_259 ( V_35 , V_333 , NULL , 0 ) ;
}
struct V_63 * F_360 ( struct V_82 * V_83 ,
struct V_32 * V_33 , T_3 V_478 ,
T_2 V_16 , T_2 V_147 ,
struct V_394 * V_20 , int V_167 ,
T_2 V_486 , T_2 V_431 , int V_199 )
{
struct V_65 V_206 ;
struct V_320 * V_333 ;
struct V_63 * V_236 ;
T_2 V_6 = 0 ;
int V_27 ;
V_333 = F_356 ( V_83 , V_33 , V_478 ) ;
if ( F_213 ( V_333 ) )
return F_361 ( V_333 ) ;
V_27 = F_338 ( V_83 , V_33 , V_478 , V_478 ,
V_431 , V_486 , ( T_2 ) - 1 , & V_206 , 0 ) ;
if ( V_27 ) {
F_359 ( V_33 -> V_35 , V_333 , V_478 ) ;
return F_348 ( V_27 ) ;
}
V_236 = F_346 ( V_83 , V_33 , V_206 . V_21 ,
V_478 , V_167 ) ;
F_22 ( F_213 ( V_236 ) ) ;
if ( V_147 == V_487 ) {
if ( V_16 == 0 )
V_16 = V_206 . V_21 ;
V_6 |= V_130 ;
} else
F_22 ( V_16 > 0 ) ;
if ( V_147 != V_200 ) {
struct V_178 * V_132 ;
V_132 = F_186 ( sizeof( * V_132 ) , V_38 ) ;
F_22 ( ! V_132 ) ;
if ( V_20 )
memcpy ( & V_132 -> V_20 , V_20 , sizeof( V_132 -> V_20 ) ) ;
else
memset ( & V_132 -> V_20 , 0 , sizeof( V_132 -> V_20 ) ) ;
V_132 -> V_134 = V_6 ;
V_132 -> V_209 = 1 ;
V_132 -> V_133 = 1 ;
V_132 -> V_182 = 0 ;
V_27 = F_149 ( V_33 -> V_35 , V_83 ,
V_206 . V_21 ,
V_206 . V_31 , V_16 , V_147 ,
V_167 , V_477 ,
V_132 , V_199 ) ;
F_22 ( V_27 ) ;
}
return V_236 ;
}
static T_1 void F_362 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_488 * V_489 ,
struct V_61 * V_62 )
{
T_2 V_25 ;
T_2 V_257 ;
T_2 V_118 ;
T_2 V_6 ;
T_3 V_68 ;
T_3 V_478 ;
struct V_65 V_20 ;
struct V_63 * V_490 ;
int V_27 ;
int V_491 ;
int V_492 = 0 ;
if ( V_62 -> V_79 [ V_489 -> V_167 ] < V_489 -> V_493 ) {
V_489 -> V_494 = V_489 -> V_494 * 2 / 3 ;
V_489 -> V_494 = F_76 ( V_489 -> V_494 , 2 ) ;
} else {
V_489 -> V_494 = V_489 -> V_494 * 3 / 2 ;
V_489 -> V_494 = F_181 ( int , V_489 -> V_494 ,
F_363 ( V_33 ) ) ;
}
V_490 = V_62 -> V_78 [ V_489 -> V_167 ] ;
V_68 = F_37 ( V_490 ) ;
V_478 = F_204 ( V_33 , V_489 -> V_167 - 1 ) ;
for ( V_491 = V_62 -> V_79 [ V_489 -> V_167 ] ; V_491 < V_68 ; V_491 ++ ) {
if ( V_492 >= V_489 -> V_494 )
break;
F_46 () ;
V_25 = F_203 ( V_490 , V_491 ) ;
V_257 = F_364 ( V_490 , V_491 ) ;
if ( V_491 == V_62 -> V_79 [ V_489 -> V_167 ] )
goto V_72;
if ( V_489 -> V_495 == V_496 &&
V_257 <= V_33 -> V_232 . V_31 )
continue;
V_27 = F_80 ( V_83 , V_33 , V_25 , V_478 ,
& V_118 , & V_6 ) ;
F_22 ( V_27 ) ;
F_22 ( V_118 == 0 ) ;
if ( V_489 -> V_495 == V_497 ) {
if ( V_118 == 1 )
goto V_72;
if ( V_489 -> V_167 == 1 &&
( V_6 & V_130 ) )
continue;
if ( ! V_489 -> V_498 ||
V_257 <= V_33 -> V_232 . V_31 )
continue;
F_127 ( V_490 , & V_20 , V_491 ) ;
V_27 = F_365 ( & V_20 ,
& V_489 -> V_499 ) ;
if ( V_27 < 0 )
continue;
} else {
if ( V_489 -> V_167 == 1 &&
( V_6 & V_130 ) )
continue;
}
V_72:
V_27 = F_366 ( V_33 , V_25 , V_478 ,
V_257 ) ;
if ( V_27 )
break;
V_492 ++ ;
}
V_489 -> V_493 = V_491 ;
}
static T_1 int F_367 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_61 * V_62 ,
struct V_488 * V_489 , int V_500 )
{
int V_167 = V_489 -> V_167 ;
struct V_63 * V_490 = V_62 -> V_78 [ V_167 ] ;
T_2 V_501 = V_130 ;
int V_27 ;
if ( V_489 -> V_495 == V_496 &&
F_196 ( V_490 ) != V_33 -> V_232 . V_21 )
return 1 ;
if ( V_500 &&
( ( V_489 -> V_495 == V_497 && V_489 -> V_118 [ V_167 ] != 1 ) ||
( V_489 -> V_495 == V_496 && ! ( V_489 -> V_6 [ V_167 ] & V_501 ) ) ) ) {
F_22 ( ! V_62 -> V_502 [ V_167 ] ) ;
V_27 = F_80 ( V_83 , V_33 ,
V_490 -> V_30 , V_490 -> V_116 ,
& V_489 -> V_118 [ V_167 ] ,
& V_489 -> V_6 [ V_167 ] ) ;
F_22 ( V_27 ) ;
F_22 ( V_489 -> V_118 [ V_167 ] == 0 ) ;
}
if ( V_489 -> V_495 == V_497 ) {
if ( V_489 -> V_118 [ V_167 ] > 1 )
return 1 ;
if ( V_62 -> V_502 [ V_167 ] && ! V_489 -> V_173 ) {
F_368 ( V_490 , V_62 -> V_502 [ V_167 ] ) ;
V_62 -> V_502 [ V_167 ] = 0 ;
}
return 0 ;
}
if ( ! ( V_489 -> V_6 [ V_167 ] & V_501 ) ) {
F_22 ( ! V_62 -> V_502 [ V_167 ] ) ;
V_27 = F_205 ( V_83 , V_33 , V_490 , 1 , V_489 -> V_503 ) ;
F_22 ( V_27 ) ;
V_27 = F_206 ( V_83 , V_33 , V_490 , 0 , V_489 -> V_503 ) ;
F_22 ( V_27 ) ;
V_27 = F_185 ( V_83 , V_33 , V_490 -> V_30 ,
V_490 -> V_116 , V_501 , 0 ) ;
F_22 ( V_27 ) ;
V_489 -> V_6 [ V_167 ] |= V_501 ;
}
if ( V_62 -> V_502 [ V_167 ] && V_167 > 0 ) {
F_368 ( V_490 , V_62 -> V_502 [ V_167 ] ) ;
V_62 -> V_502 [ V_167 ] = 0 ;
}
return 0 ;
}
static T_1 int F_369 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_61 * V_62 ,
struct V_488 * V_489 , int * V_500 )
{
T_2 V_25 ;
T_2 V_257 ;
T_2 V_16 ;
T_3 V_478 ;
struct V_65 V_20 ;
struct V_63 * V_216 ;
int V_167 = V_489 -> V_167 ;
int V_72 = 0 ;
int V_27 = 0 ;
V_257 = F_364 ( V_62 -> V_78 [ V_167 ] ,
V_62 -> V_79 [ V_167 ] ) ;
if ( V_489 -> V_495 == V_496 &&
V_257 <= V_33 -> V_232 . V_31 ) {
* V_500 = 1 ;
return 1 ;
}
V_25 = F_203 ( V_62 -> V_78 [ V_167 ] , V_62 -> V_79 [ V_167 ] ) ;
V_478 = F_204 ( V_33 , V_167 - 1 ) ;
V_216 = F_370 ( V_33 , V_25 , V_478 ) ;
if ( ! V_216 ) {
V_216 = F_347 ( V_33 , V_25 , V_478 ) ;
if ( ! V_216 )
return - V_117 ;
V_72 = 1 ;
}
F_351 ( V_216 ) ;
F_353 ( V_216 ) ;
V_27 = F_80 ( V_83 , V_33 , V_25 , V_478 ,
& V_489 -> V_118 [ V_167 - 1 ] ,
& V_489 -> V_6 [ V_167 - 1 ] ) ;
F_22 ( V_27 ) ;
F_22 ( V_489 -> V_118 [ V_167 - 1 ] == 0 ) ;
* V_500 = 0 ;
if ( V_489 -> V_495 == V_497 ) {
if ( V_489 -> V_118 [ V_167 - 1 ] > 1 ) {
if ( V_167 == 1 &&
( V_489 -> V_6 [ 0 ] & V_130 ) )
goto V_504;
if ( ! V_489 -> V_498 ||
V_257 <= V_33 -> V_232 . V_31 )
goto V_504;
F_127 ( V_62 -> V_78 [ V_167 ] , & V_20 ,
V_62 -> V_79 [ V_167 ] ) ;
V_27 = F_365 ( & V_20 , & V_489 -> V_499 ) ;
if ( V_27 < 0 )
goto V_504;
V_489 -> V_495 = V_496 ;
V_489 -> V_505 = V_167 - 1 ;
}
} else {
if ( V_167 == 1 &&
( V_489 -> V_6 [ 0 ] & V_130 ) )
goto V_504;
}
if ( ! F_371 ( V_216 , V_257 ) ) {
F_372 ( V_216 ) ;
F_373 ( V_216 ) ;
V_216 = NULL ;
* V_500 = 1 ;
}
if ( ! V_216 ) {
if ( V_72 && V_167 == 1 )
F_362 ( V_83 , V_33 , V_489 , V_62 ) ;
V_216 = F_374 ( V_33 , V_25 , V_478 , V_257 ) ;
if ( ! V_216 )
return - V_211 ;
F_351 ( V_216 ) ;
F_353 ( V_216 ) ;
}
V_167 -- ;
F_22 ( V_167 != F_197 ( V_216 ) ) ;
V_62 -> V_78 [ V_167 ] = V_216 ;
V_62 -> V_79 [ V_167 ] = 0 ;
V_62 -> V_502 [ V_167 ] = V_506 ;
V_489 -> V_167 = V_167 ;
if ( V_489 -> V_167 == 1 )
V_489 -> V_493 = 0 ;
return 0 ;
V_504:
V_489 -> V_118 [ V_167 - 1 ] = 0 ;
V_489 -> V_6 [ V_167 - 1 ] = 0 ;
if ( V_489 -> V_495 == V_497 ) {
if ( V_489 -> V_6 [ V_167 ] & V_130 ) {
V_16 = V_62 -> V_78 [ V_167 ] -> V_30 ;
} else {
F_22 ( V_33 -> V_232 . V_21 !=
F_196 ( V_62 -> V_78 [ V_167 ] ) ) ;
V_16 = 0 ;
}
V_27 = V_242 ( V_83 , V_33 , V_25 , V_478 , V_16 ,
V_33 -> V_232 . V_21 , V_167 - 1 , 0 , 0 ) ;
F_22 ( V_27 ) ;
}
F_372 ( V_216 ) ;
F_373 ( V_216 ) ;
* V_500 = 1 ;
return 1 ;
}
static T_1 int F_375 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_61 * V_62 ,
struct V_488 * V_489 )
{
int V_27 ;
int V_167 = V_489 -> V_167 ;
struct V_63 * V_490 = V_62 -> V_78 [ V_167 ] ;
T_2 V_16 = 0 ;
if ( V_489 -> V_495 == V_496 ) {
F_22 ( V_489 -> V_505 < V_167 ) ;
if ( V_167 < V_489 -> V_505 )
goto V_69;
V_27 = F_40 ( V_62 , V_167 + 1 , & V_489 -> V_499 ) ;
if ( V_27 > 0 )
V_489 -> V_498 = 0 ;
V_489 -> V_495 = V_497 ;
V_489 -> V_505 = - 1 ;
V_62 -> V_79 [ V_167 ] = 0 ;
if ( ! V_62 -> V_502 [ V_167 ] ) {
F_22 ( V_167 == 0 ) ;
F_351 ( V_490 ) ;
F_353 ( V_490 ) ;
V_62 -> V_502 [ V_167 ] = V_506 ;
V_27 = F_80 ( V_83 , V_33 ,
V_490 -> V_30 , V_490 -> V_116 ,
& V_489 -> V_118 [ V_167 ] ,
& V_489 -> V_6 [ V_167 ] ) ;
F_22 ( V_27 ) ;
F_22 ( V_489 -> V_118 [ V_167 ] == 0 ) ;
if ( V_489 -> V_118 [ V_167 ] == 1 ) {
F_368 ( V_490 , V_62 -> V_502 [ V_167 ] ) ;
return 1 ;
}
}
}
F_22 ( V_489 -> V_118 [ V_167 ] > 1 && ! V_62 -> V_502 [ V_167 ] ) ;
if ( V_489 -> V_118 [ V_167 ] == 1 ) {
if ( V_167 == 0 ) {
if ( V_489 -> V_6 [ V_167 ] & V_130 )
V_27 = F_206 ( V_83 , V_33 , V_490 , 1 ,
V_489 -> V_503 ) ;
else
V_27 = F_206 ( V_83 , V_33 , V_490 , 0 ,
V_489 -> V_503 ) ;
F_22 ( V_27 ) ;
}
if ( ! V_62 -> V_502 [ V_167 ] &&
F_317 ( V_490 ) == V_83 -> V_254 ) {
F_351 ( V_490 ) ;
F_353 ( V_490 ) ;
V_62 -> V_502 [ V_167 ] = V_506 ;
}
F_352 ( V_83 , V_33 , V_490 ) ;
}
if ( V_490 == V_33 -> V_131 ) {
if ( V_489 -> V_6 [ V_167 ] & V_130 )
V_16 = V_490 -> V_30 ;
else
F_22 ( V_33 -> V_232 . V_21 !=
F_196 ( V_490 ) ) ;
} else {
if ( V_489 -> V_6 [ V_167 + 1 ] & V_130 )
V_16 = V_62 -> V_78 [ V_167 + 1 ] -> V_30 ;
else
F_22 ( V_33 -> V_232 . V_21 !=
F_196 ( V_62 -> V_78 [ V_167 + 1 ] ) ) ;
}
F_316 ( V_83 , V_33 , V_490 , V_16 , V_489 -> V_118 [ V_167 ] == 1 , 0 ) ;
V_69:
V_489 -> V_118 [ V_167 ] = 0 ;
V_489 -> V_6 [ V_167 ] = 0 ;
return 0 ;
}
static T_1 int F_376 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_61 * V_62 ,
struct V_488 * V_489 )
{
int V_167 = V_489 -> V_167 ;
int V_500 = 1 ;
int V_27 ;
while ( V_167 >= 0 ) {
V_27 = F_367 ( V_83 , V_33 , V_62 , V_489 , V_500 ) ;
if ( V_27 > 0 )
break;
if ( V_167 == 0 )
break;
if ( V_62 -> V_79 [ V_167 ] >=
F_37 ( V_62 -> V_78 [ V_167 ] ) )
break;
V_27 = F_369 ( V_83 , V_33 , V_62 , V_489 , & V_500 ) ;
if ( V_27 > 0 ) {
V_62 -> V_79 [ V_167 ] ++ ;
continue;
} else if ( V_27 < 0 )
return V_27 ;
V_167 = V_489 -> V_167 ;
}
return 0 ;
}
static T_1 int F_377 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_61 * V_62 ,
struct V_488 * V_489 , int V_507 )
{
int V_167 = V_489 -> V_167 ;
int V_27 ;
V_62 -> V_79 [ V_167 ] = F_37 ( V_62 -> V_78 [ V_167 ] ) ;
while ( V_167 < V_507 && V_62 -> V_78 [ V_167 ] ) {
V_489 -> V_167 = V_167 ;
if ( V_62 -> V_79 [ V_167 ] + 1 <
F_37 ( V_62 -> V_78 [ V_167 ] ) ) {
V_62 -> V_79 [ V_167 ] ++ ;
return 0 ;
} else {
V_27 = F_375 ( V_83 , V_33 , V_62 , V_489 ) ;
if ( V_27 > 0 )
return 0 ;
if ( V_62 -> V_502 [ V_167 ] ) {
F_368 ( V_62 -> V_78 [ V_167 ] ,
V_62 -> V_502 [ V_167 ] ) ;
V_62 -> V_502 [ V_167 ] = 0 ;
}
F_373 ( V_62 -> V_78 [ V_167 ] ) ;
V_62 -> V_78 [ V_167 ] = NULL ;
V_167 ++ ;
}
}
return 1 ;
}
void F_378 ( struct V_32 * V_33 ,
struct V_320 * V_333 , int V_498 ,
int V_503 )
{
struct V_61 * V_62 ;
struct V_82 * V_83 ;
struct V_32 * V_92 = V_33 -> V_35 -> V_92 ;
struct V_508 * V_233 = & V_33 -> V_233 ;
struct V_488 * V_489 ;
struct V_65 V_20 ;
int V_77 = 0 ;
int V_27 ;
int V_167 ;
V_62 = F_32 () ;
if ( ! V_62 ) {
V_77 = - V_117 ;
goto V_69;
}
V_489 = F_51 ( sizeof( * V_489 ) , V_38 ) ;
if ( ! V_489 ) {
F_48 ( V_62 ) ;
V_77 = - V_117 ;
goto V_69;
}
V_83 = F_379 ( V_92 , 0 ) ;
F_22 ( F_213 ( V_83 ) ) ;
if ( V_333 )
V_83 -> V_333 = V_333 ;
if ( F_380 ( & V_233 -> V_509 ) == 0 ) {
V_167 = F_197 ( V_33 -> V_131 ) ;
V_62 -> V_78 [ V_167 ] = F_381 ( V_33 ) ;
F_353 ( V_62 -> V_78 [ V_167 ] ) ;
V_62 -> V_79 [ V_167 ] = 0 ;
V_62 -> V_502 [ V_167 ] = V_506 ;
memset ( & V_489 -> V_499 , 0 ,
sizeof( V_489 -> V_499 ) ) ;
} else {
F_382 ( & V_20 , & V_233 -> V_509 ) ;
memcpy ( & V_489 -> V_499 , & V_20 ,
sizeof( V_489 -> V_499 ) ) ;
V_167 = V_233 -> V_510 ;
F_22 ( V_167 == 0 ) ;
V_62 -> V_511 = V_167 ;
V_27 = F_36 ( NULL , V_33 , & V_20 , V_62 , 0 , 0 ) ;
V_62 -> V_511 = 0 ;
if ( V_27 < 0 ) {
V_77 = V_27 ;
goto V_127;
}
F_8 ( V_27 > 0 ) ;
F_132 ( V_62 , 0 ) ;
V_167 = F_197 ( V_33 -> V_131 ) ;
while ( 1 ) {
F_351 ( V_62 -> V_78 [ V_167 ] ) ;
F_353 ( V_62 -> V_78 [ V_167 ] ) ;
V_27 = F_80 ( V_83 , V_33 ,
V_62 -> V_78 [ V_167 ] -> V_30 ,
V_62 -> V_78 [ V_167 ] -> V_116 ,
& V_489 -> V_118 [ V_167 ] ,
& V_489 -> V_6 [ V_167 ] ) ;
F_22 ( V_27 ) ;
F_22 ( V_489 -> V_118 [ V_167 ] == 0 ) ;
if ( V_167 == V_233 -> V_510 )
break;
F_372 ( V_62 -> V_78 [ V_167 ] ) ;
F_8 ( V_489 -> V_118 [ V_167 ] != 1 ) ;
V_167 -- ;
}
}
V_489 -> V_167 = V_167 ;
V_489 -> V_505 = - 1 ;
V_489 -> V_495 = V_497 ;
V_489 -> V_498 = V_498 ;
V_489 -> V_173 = 0 ;
V_489 -> V_503 = V_503 ;
V_489 -> V_494 = F_363 ( V_33 ) ;
while ( 1 ) {
V_27 = F_376 ( V_83 , V_33 , V_62 , V_489 ) ;
if ( V_27 < 0 ) {
V_77 = V_27 ;
break;
}
V_27 = F_377 ( V_83 , V_33 , V_62 , V_489 , V_168 ) ;
if ( V_27 < 0 ) {
V_77 = V_27 ;
break;
}
if ( V_27 > 0 ) {
F_22 ( V_489 -> V_495 != V_497 ) ;
break;
}
if ( V_489 -> V_495 == V_497 ) {
V_167 = V_489 -> V_167 ;
F_383 ( V_62 -> V_78 [ V_167 ] ,
& V_233 -> V_509 ,
V_62 -> V_79 [ V_167 ] ) ;
V_233 -> V_510 = V_167 ;
}
F_22 ( V_489 -> V_167 == 0 ) ;
if ( F_384 ( V_83 , V_92 ) ) {
V_27 = F_385 ( V_83 , V_92 ,
& V_33 -> V_232 ,
V_233 ) ;
F_22 ( V_27 ) ;
F_386 ( V_83 , V_92 ) ;
V_83 = F_379 ( V_92 , 0 ) ;
F_22 ( F_213 ( V_83 ) ) ;
if ( V_333 )
V_83 -> V_333 = V_333 ;
}
}
F_43 ( V_62 ) ;
F_22 ( V_77 ) ;
V_27 = F_387 ( V_83 , V_92 , & V_33 -> V_232 ) ;
F_22 ( V_27 ) ;
if ( V_33 -> V_232 . V_21 != V_487 ) {
V_27 = F_388 ( V_92 , V_33 -> V_232 . V_21 ,
NULL , NULL ) ;
F_22 ( V_27 < 0 ) ;
if ( V_27 > 0 ) {
F_389 ( V_83 , V_92 ,
V_33 -> V_232 . V_21 ) ;
}
}
if ( V_33 -> V_512 ) {
F_390 ( V_92 -> V_35 , V_33 ) ;
} else {
F_373 ( V_33 -> V_131 ) ;
F_373 ( V_33 -> V_513 ) ;
F_9 ( V_33 ) ;
}
V_127:
F_386 ( V_83 , V_92 ) ;
F_9 ( V_489 ) ;
F_48 ( V_62 ) ;
V_69:
if ( V_77 )
F_391 ( V_33 -> V_35 , V_77 ) ;
return;
}
int F_392 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_63 * V_131 ,
struct V_63 * V_16 )
{
struct V_61 * V_62 ;
struct V_488 * V_489 ;
int V_167 ;
int V_514 ;
int V_27 = 0 ;
int V_515 ;
F_22 ( V_33 -> V_232 . V_21 != V_487 ) ;
V_62 = F_32 () ;
if ( ! V_62 )
return - V_117 ;
V_489 = F_51 ( sizeof( * V_489 ) , V_38 ) ;
if ( ! V_489 ) {
F_48 ( V_62 ) ;
return - V_117 ;
}
F_393 ( V_16 ) ;
V_514 = F_197 ( V_16 ) ;
F_394 ( V_16 ) ;
V_62 -> V_78 [ V_514 ] = V_16 ;
V_62 -> V_79 [ V_514 ] = F_37 ( V_16 ) ;
F_393 ( V_131 ) ;
V_167 = F_197 ( V_131 ) ;
V_62 -> V_78 [ V_167 ] = V_131 ;
V_62 -> V_79 [ V_167 ] = 0 ;
V_62 -> V_502 [ V_167 ] = V_506 ;
V_489 -> V_118 [ V_514 ] = 1 ;
V_489 -> V_6 [ V_514 ] = V_130 ;
V_489 -> V_167 = V_167 ;
V_489 -> V_505 = - 1 ;
V_489 -> V_495 = V_497 ;
V_489 -> V_498 = 0 ;
V_489 -> V_173 = 1 ;
V_489 -> V_503 = 1 ;
V_489 -> V_494 = F_363 ( V_33 ) ;
while ( 1 ) {
V_515 = F_376 ( V_83 , V_33 , V_62 , V_489 ) ;
if ( V_515 < 0 ) {
V_27 = V_515 ;
break;
}
V_515 = F_377 ( V_83 , V_33 , V_62 , V_489 , V_514 ) ;
if ( V_515 < 0 )
V_27 = V_515 ;
if ( V_515 != 0 )
break;
}
F_9 ( V_489 ) ;
F_48 ( V_62 ) ;
return V_27 ;
}
static T_2 F_395 ( struct V_32 * V_33 , T_2 V_6 )
{
T_2 V_288 ;
T_2 V_516 = V_302 |
V_266 | V_267 ;
if ( V_33 -> V_35 -> V_293 ) {
struct V_294 * V_295 = V_33 -> V_35 -> V_293 ;
T_2 V_296 = 0 ;
if ( V_6 & V_283 &&
V_295 -> V_297 . V_6 & V_298 ) {
V_296 = V_283 | V_295 -> V_297 . V_299 ;
} else if ( V_6 & V_286 &&
V_295 -> V_300 . V_6 & V_298 ) {
V_296 = V_286 | V_295 -> V_300 . V_299 ;
} else if ( V_6 & V_115 &&
V_295 -> V_301 . V_6 & V_298 ) {
V_296 = V_115 | V_295 -> V_301 . V_299 ;
}
if ( V_296 ) {
V_296 &= ~ V_282 ;
return V_296 ;
}
}
V_288 = V_33 -> V_35 -> V_289 -> V_290 +
V_33 -> V_35 -> V_289 -> V_291 ;
if ( V_288 == 1 ) {
V_516 |= V_265 ;
V_516 = V_6 & ~ V_516 ;
if ( V_6 & V_302 )
return V_516 ;
if ( V_6 & ( V_266 |
V_267 ) )
return V_516 | V_265 ;
return V_6 ;
} else {
if ( V_6 & V_516 )
return V_6 ;
V_516 |= V_265 ;
V_516 = V_6 & ~ V_516 ;
if ( V_6 & V_265 )
return V_516 | V_266 ;
return V_516 | V_302 ;
}
return V_6 ;
}
static int F_396 ( struct V_1 * V_2 , int V_319 )
{
struct V_97 * V_317 = V_2 -> V_100 ;
T_2 V_34 ;
T_2 V_517 ;
int V_27 = - V_314 ;
if ( ( V_317 -> V_6 &
( V_286 | V_115 ) ) &&
! V_319 )
V_517 = 1 * 1024 * 1024 ;
else
V_517 = 0 ;
F_11 ( & V_317 -> V_49 ) ;
F_11 ( & V_2 -> V_49 ) ;
if ( V_2 -> V_114 ) {
V_27 = 0 ;
goto V_69;
}
V_34 = V_2 -> V_20 . V_31 - V_2 -> V_9 - V_2 -> V_8 -
V_2 -> V_44 - F_77 ( & V_2 -> V_113 ) ;
if ( V_317 -> V_264 + V_317 -> V_274 + V_317 -> V_273 +
V_317 -> V_276 + V_317 -> V_275 + V_34 +
V_517 <= V_317 -> V_263 ) {
V_317 -> V_275 += V_34 ;
V_2 -> V_114 = 1 ;
V_27 = 0 ;
}
V_69:
F_13 ( & V_2 -> V_49 ) ;
F_13 ( & V_317 -> V_49 ) ;
return V_27 ;
}
int F_397 ( struct V_32 * V_33 ,
struct V_1 * V_2 )
{
struct V_82 * V_83 ;
T_2 V_518 ;
int V_27 ;
F_22 ( V_2 -> V_114 ) ;
V_83 = F_236 ( V_33 ) ;
F_22 ( F_213 ( V_83 ) ) ;
V_518 = F_395 ( V_33 , V_2 -> V_6 ) ;
if ( V_518 != V_2 -> V_6 )
F_174 ( V_83 , V_33 , 2 * 1024 * 1024 , V_518 ,
V_313 ) ;
V_27 = F_396 ( V_2 , 0 ) ;
if ( ! V_27 )
goto V_69;
V_518 = F_234 ( V_33 , V_2 -> V_100 -> V_6 ) ;
V_27 = F_174 ( V_83 , V_33 , 2 * 1024 * 1024 , V_518 ,
V_313 ) ;
if ( V_27 < 0 )
goto V_69;
V_27 = F_396 ( V_2 , 0 ) ;
V_69:
F_237 ( V_83 , V_33 ) ;
return V_27 ;
}
int F_398 ( struct V_82 * V_83 ,
struct V_32 * V_33 , T_2 type )
{
T_2 V_518 = F_234 ( V_33 , type ) ;
return F_174 ( V_83 , V_33 , 2 * 1024 * 1024 , V_518 ,
V_313 ) ;
}
static T_2 F_399 ( struct V_98 * V_519 )
{
struct V_1 * V_13 ;
T_2 V_520 = 0 ;
int V_105 ;
F_327 (block_group, groups_list, list) {
F_11 ( & V_13 -> V_49 ) ;
if ( ! V_13 -> V_114 ) {
F_13 ( & V_13 -> V_49 ) ;
continue;
}
if ( V_13 -> V_6 & ( V_266 |
V_267 |
V_265 ) )
V_105 = 2 ;
else
V_105 = 1 ;
V_520 += ( V_13 -> V_20 . V_31 -
F_77 ( & V_13 -> V_113 ) ) *
V_105 ;
F_13 ( & V_13 -> V_49 ) ;
}
return V_520 ;
}
T_2 F_400 ( struct V_97 * V_317 )
{
int V_41 ;
T_2 V_520 = 0 ;
F_11 ( & V_317 -> V_49 ) ;
for( V_41 = 0 ; V_41 < V_270 ; V_41 ++ )
if ( ! F_167 ( & V_317 -> V_271 [ V_41 ] ) )
V_520 += F_399 (
& V_317 -> V_271 [ V_41 ] ) ;
F_13 ( & V_317 -> V_49 ) ;
return V_520 ;
}
int F_401 ( struct V_32 * V_33 ,
struct V_1 * V_2 )
{
struct V_97 * V_317 = V_2 -> V_100 ;
T_2 V_34 ;
F_22 ( ! V_2 -> V_114 ) ;
F_11 ( & V_317 -> V_49 ) ;
F_11 ( & V_2 -> V_49 ) ;
V_34 = V_2 -> V_20 . V_31 - V_2 -> V_9 - V_2 -> V_8 -
V_2 -> V_44 - F_77 ( & V_2 -> V_113 ) ;
V_317 -> V_275 -= V_34 ;
V_2 -> V_114 = 0 ;
F_13 ( & V_2 -> V_49 ) ;
F_13 ( & V_317 -> V_49 ) ;
return 0 ;
}
int F_402 ( struct V_32 * V_33 , T_2 V_25 )
{
struct V_1 * V_13 ;
struct V_97 * V_100 ;
struct V_521 * V_289 = V_33 -> V_35 -> V_289 ;
struct V_522 * V_523 ;
T_2 V_524 ;
T_2 V_525 = 1 ;
T_2 V_526 = 0 ;
int V_429 ;
int V_103 = 0 ;
int V_27 = 0 ;
V_13 = F_66 ( V_33 -> V_35 , V_25 ) ;
if ( ! V_13 )
return - 1 ;
V_524 = F_77 ( & V_13 -> V_113 ) ;
if ( ! V_524 )
goto V_69;
V_100 = V_13 -> V_100 ;
F_11 ( & V_100 -> V_49 ) ;
V_103 = V_100 -> V_103 ;
if ( ( V_100 -> V_263 != V_13 -> V_20 . V_31 ) &&
( V_100 -> V_264 + V_100 -> V_274 +
V_100 -> V_273 + V_100 -> V_275 +
V_524 < V_100 -> V_263 ) ) {
F_13 ( & V_100 -> V_49 ) ;
goto V_69;
}
F_13 ( & V_100 -> V_49 ) ;
V_27 = - 1 ;
if ( V_103 )
goto V_69;
V_429 = F_324 ( V_13 ) ;
if ( V_429 == 0 ) {
V_525 = 4 ;
V_524 >>= 1 ;
} else if ( V_429 == 1 ) {
V_525 = 2 ;
} else if ( V_429 == 2 ) {
V_524 <<= 1 ;
} else if ( V_429 == 3 ) {
V_525 = V_289 -> V_290 ;
F_73 ( V_524 , V_525 ) ;
}
F_34 ( & V_33 -> V_35 -> V_328 ) ;
F_327 (device, &fs_devices->alloc_list, dev_alloc_list) {
T_2 V_527 ;
if ( V_523 -> V_263 > V_523 -> V_264 + V_524 ) {
V_27 = F_403 ( V_523 , V_524 ,
& V_527 , NULL ) ;
if ( ! V_27 )
V_526 ++ ;
if ( V_526 >= V_525 )
break;
V_27 = - 1 ;
}
}
F_45 ( & V_33 -> V_35 -> V_328 ) ;
V_69:
F_6 ( V_13 ) ;
return V_27 ;
}
static int F_404 ( struct V_32 * V_33 ,
struct V_61 * V_62 , struct V_65 * V_20 )
{
int V_27 = 0 ;
struct V_65 V_141 ;
struct V_63 * V_64 ;
int V_491 ;
V_27 = F_36 ( NULL , V_33 , V_20 , V_62 , 0 , 0 ) ;
if ( V_27 < 0 )
goto V_69;
while ( 1 ) {
V_491 = V_62 -> V_79 [ 0 ] ;
V_64 = V_62 -> V_78 [ 0 ] ;
if ( V_491 >= F_37 ( V_64 ) ) {
V_27 = F_42 ( V_33 , V_62 ) ;
if ( V_27 == 0 )
continue;
if ( V_27 < 0 )
goto V_69;
break;
}
F_39 ( V_64 , & V_141 , V_491 ) ;
if ( V_141 . V_21 >= V_20 -> V_21 &&
V_141 . type == V_177 ) {
V_27 = 0 ;
goto V_69;
}
V_62 -> V_79 [ 0 ] ++ ;
}
V_69:
return V_27 ;
}
void F_405 ( struct V_11 * V_12 )
{
struct V_1 * V_13 ;
T_2 V_67 = 0 ;
while ( 1 ) {
struct V_245 * V_245 ;
V_13 = F_65 ( V_12 , V_67 ) ;
while ( V_13 ) {
F_11 ( & V_13 -> V_49 ) ;
if ( V_13 -> V_164 )
break;
F_13 ( & V_13 -> V_49 ) ;
V_13 = F_210 ( V_12 -> V_92 ,
V_13 ) ;
}
if ( ! V_13 ) {
if ( V_67 == 0 )
break;
V_67 = 0 ;
continue;
}
V_245 = V_13 -> V_245 ;
V_13 -> V_164 = 0 ;
V_13 -> V_245 = NULL ;
F_13 ( & V_13 -> V_49 ) ;
F_224 ( V_245 ) ;
V_67 = V_13 -> V_20 . V_21 + V_13 -> V_20 . V_31 ;
F_6 ( V_13 ) ;
}
}
int F_406 ( struct V_11 * V_12 )
{
struct V_1 * V_13 ;
struct V_97 * V_100 ;
struct V_47 * V_51 ;
struct V_14 * V_28 ;
F_61 ( & V_12 -> V_76 ) ;
while ( ! F_167 ( & V_12 -> V_95 ) ) {
V_51 = F_168 ( V_12 -> V_95 . V_216 ,
struct V_47 , V_85 ) ;
F_407 ( & V_51 -> V_85 ) ;
F_26 ( V_51 ) ;
}
F_63 ( & V_12 -> V_76 ) ;
F_11 ( & V_12 -> V_17 ) ;
while ( ( V_28 = F_408 ( & V_12 -> V_18 ) ) != NULL ) {
V_13 = F_12 ( V_28 , struct V_1 ,
V_19 ) ;
F_173 ( & V_13 -> V_19 ,
& V_12 -> V_18 ) ;
F_13 ( & V_12 -> V_17 ) ;
F_61 ( & V_13 -> V_100 -> V_272 ) ;
F_407 ( & V_13 -> V_85 ) ;
F_63 ( & V_13 -> V_100 -> V_272 ) ;
if ( V_13 -> V_3 == V_50 )
F_323 ( V_13 ) ;
if ( V_13 -> V_3 == V_89 )
F_19 ( V_12 -> V_60 , V_13 ) ;
F_409 ( V_13 ) ;
F_6 ( V_13 ) ;
F_11 ( & V_12 -> V_17 ) ;
}
F_13 ( & V_12 -> V_17 ) ;
F_410 () ;
F_278 ( V_12 ) ;
while( ! F_167 ( & V_12 -> V_100 ) ) {
V_100 = F_168 ( V_12 -> V_100 . V_216 ,
struct V_97 ,
V_85 ) ;
if ( V_100 -> V_273 > 0 ||
V_100 -> V_274 > 0 ||
V_100 -> V_276 > 0 ) {
F_8 ( 1 ) ;
F_336 ( V_100 , 0 , 0 ) ;
}
F_407 ( & V_100 -> V_85 ) ;
F_9 ( V_100 ) ;
}
return 0 ;
}
static void F_411 ( struct V_97 * V_100 ,
struct V_1 * V_2 )
{
int V_429 = F_324 ( V_2 ) ;
F_61 ( & V_100 -> V_272 ) ;
F_62 ( & V_2 -> V_85 , & V_100 -> V_271 [ V_429 ] ) ;
F_63 ( & V_100 -> V_272 ) ;
}
int F_412 ( struct V_32 * V_33 )
{
struct V_61 * V_62 ;
int V_27 ;
struct V_1 * V_2 ;
struct V_11 * V_12 = V_33 -> V_35 ;
struct V_97 * V_100 ;
struct V_65 V_20 ;
struct V_65 V_141 ;
struct V_63 * V_64 ;
int V_528 = 0 ;
T_2 V_529 ;
V_33 = V_12 -> V_60 ;
V_20 . V_21 = 0 ;
V_20 . V_31 = 0 ;
F_79 ( & V_20 , V_177 ) ;
V_62 = F_32 () ;
if ( ! V_62 )
return - V_117 ;
V_62 -> V_72 = 1 ;
V_529 = F_413 ( V_33 -> V_35 -> V_326 ) ;
if ( F_59 ( V_33 , V_93 ) &&
F_414 ( V_33 -> V_35 -> V_326 ) != V_529 )
V_528 = 1 ;
if ( F_59 ( V_33 , V_530 ) )
V_528 = 1 ;
while ( 1 ) {
V_27 = F_404 ( V_33 , V_62 , & V_20 ) ;
if ( V_27 > 0 )
break;
if ( V_27 != 0 )
goto error;
V_64 = V_62 -> V_78 [ 0 ] ;
F_39 ( V_64 , & V_141 , V_62 -> V_79 [ 0 ] ) ;
V_2 = F_51 ( sizeof( * V_2 ) , V_38 ) ;
if ( ! V_2 ) {
V_27 = - V_117 ;
goto error;
}
V_2 -> V_10 = F_51 ( sizeof( * V_2 -> V_10 ) ,
V_38 ) ;
if ( ! V_2 -> V_10 ) {
F_9 ( V_2 ) ;
V_27 = - V_117 ;
goto error;
}
F_55 ( & V_2 -> V_7 , 1 ) ;
F_230 ( & V_2 -> V_49 ) ;
V_2 -> V_35 = V_12 ;
F_52 ( & V_2 -> V_85 ) ;
F_52 ( & V_2 -> V_531 ) ;
if ( V_528 )
V_2 -> V_251 = V_259 ;
F_415 ( V_64 , & V_2 -> V_113 ,
F_208 ( V_64 , V_62 -> V_79 [ 0 ] ) ,
sizeof( V_2 -> V_113 ) ) ;
memcpy ( & V_2 -> V_20 , & V_141 , sizeof( V_141 ) ) ;
V_20 . V_21 = V_141 . V_21 + V_141 . V_31 ;
F_43 ( V_62 ) ;
V_2 -> V_6 = F_416 ( & V_2 -> V_113 ) ;
V_2 -> V_308 = V_33 -> V_308 ;
F_417 ( V_2 ) ;
F_21 ( V_33 , V_2 ) ;
if ( V_141 . V_31 == F_77 ( & V_2 -> V_113 ) ) {
V_2 -> V_94 = ( T_2 ) - 1 ;
V_2 -> V_3 = V_4 ;
F_19 ( V_33 , V_2 ) ;
} else if ( F_77 ( & V_2 -> V_113 ) == 0 ) {
V_2 -> V_94 = ( T_2 ) - 1 ;
V_2 -> V_3 = V_4 ;
F_27 ( V_2 , V_33 -> V_35 ,
V_141 . V_21 ,
V_141 . V_21 +
V_141 . V_31 ) ;
F_19 ( V_33 , V_2 ) ;
}
V_27 = F_228 ( V_12 , V_2 -> V_6 , V_141 . V_31 ,
F_77 ( & V_2 -> V_113 ) ,
& V_100 ) ;
F_22 ( V_27 ) ;
V_2 -> V_100 = V_100 ;
F_11 ( & V_2 -> V_100 -> V_49 ) ;
V_2 -> V_100 -> V_275 += V_2 -> V_44 ;
F_13 ( & V_2 -> V_100 -> V_49 ) ;
F_411 ( V_100 , V_2 ) ;
V_27 = F_10 ( V_33 -> V_35 , V_2 ) ;
F_22 ( V_27 ) ;
F_232 ( V_33 -> V_35 , V_2 -> V_6 ) ;
if ( F_418 ( V_33 , V_2 -> V_20 . V_21 ) )
F_396 ( V_2 , 1 ) ;
}
F_69 (space_info, &root->fs_info->space_info, list) {
if ( ! ( F_234 ( V_33 , V_100 -> V_6 ) &
( V_267 |
V_266 |
V_265 ) ) )
continue;
F_327 (cache, &space_info->block_groups[3], list)
F_396 ( V_2 , 1 ) ;
F_327 (cache, &space_info->block_groups[4], list)
F_396 ( V_2 , 1 ) ;
}
F_277 ( V_12 ) ;
V_27 = 0 ;
error:
F_48 ( V_62 ) ;
return V_27 ;
}
int F_419 ( struct V_82 * V_83 ,
struct V_32 * V_33 , T_2 V_264 ,
T_2 type , T_2 V_532 , T_2 V_533 ,
T_2 V_54 )
{
int V_27 ;
struct V_32 * V_60 ;
struct V_1 * V_2 ;
V_60 = V_33 -> V_35 -> V_60 ;
V_33 -> V_35 -> V_534 = V_83 -> V_254 ;
V_2 = F_51 ( sizeof( * V_2 ) , V_38 ) ;
if ( ! V_2 )
return - V_117 ;
V_2 -> V_10 = F_51 ( sizeof( * V_2 -> V_10 ) ,
V_38 ) ;
if ( ! V_2 -> V_10 ) {
F_9 ( V_2 ) ;
return - V_117 ;
}
V_2 -> V_20 . V_21 = V_533 ;
V_2 -> V_20 . V_31 = V_54 ;
V_2 -> V_20 . type = V_177 ;
V_2 -> V_308 = V_33 -> V_308 ;
V_2 -> V_35 = V_33 -> V_35 ;
F_55 ( & V_2 -> V_7 , 1 ) ;
F_230 ( & V_2 -> V_49 ) ;
F_52 ( & V_2 -> V_85 ) ;
F_52 ( & V_2 -> V_531 ) ;
F_417 ( V_2 ) ;
F_297 ( & V_2 -> V_113 , V_264 ) ;
F_420 ( & V_2 -> V_113 , V_532 ) ;
V_2 -> V_6 = type ;
F_421 ( & V_2 -> V_113 , type ) ;
V_2 -> V_94 = ( T_2 ) - 1 ;
V_2 -> V_3 = V_4 ;
F_21 ( V_33 , V_2 ) ;
F_27 ( V_2 , V_33 -> V_35 , V_533 ,
V_533 + V_54 ) ;
F_19 ( V_33 , V_2 ) ;
V_27 = F_228 ( V_33 -> V_35 , V_2 -> V_6 , V_54 , V_264 ,
& V_2 -> V_100 ) ;
F_22 ( V_27 ) ;
F_276 ( V_33 -> V_35 ) ;
F_11 ( & V_2 -> V_100 -> V_49 ) ;
V_2 -> V_100 -> V_275 += V_2 -> V_44 ;
F_13 ( & V_2 -> V_100 -> V_49 ) ;
F_411 ( V_2 -> V_100 , V_2 ) ;
V_27 = F_10 ( V_33 -> V_35 , V_2 ) ;
F_22 ( V_27 ) ;
V_27 = F_422 ( V_83 , V_60 , & V_2 -> V_20 , & V_2 -> V_113 ,
sizeof( V_2 -> V_113 ) ) ;
F_22 ( V_27 ) ;
F_232 ( V_60 -> V_35 , type ) ;
return 0 ;
}
static void F_423 ( struct V_11 * V_35 , T_2 V_6 )
{
T_2 V_280 = V_6 & V_281 ;
if ( V_280 == 0 )
V_280 = V_282 ;
if ( V_6 & V_283 )
V_35 -> V_284 &= ~ V_280 ;
if ( V_6 & V_115 )
V_35 -> V_285 &= ~ V_280 ;
if ( V_6 & V_286 )
V_35 -> V_287 &= ~ V_280 ;
}
int F_424 ( struct V_82 * V_83 ,
struct V_32 * V_33 , T_2 V_110 )
{
struct V_61 * V_62 ;
struct V_1 * V_13 ;
struct V_434 * V_213 ;
struct V_32 * V_92 = V_33 -> V_35 -> V_92 ;
struct V_65 V_20 ;
struct V_245 * V_245 ;
int V_27 ;
int V_429 ;
int V_105 ;
V_33 = V_33 -> V_35 -> V_60 ;
V_13 = F_66 ( V_33 -> V_35 , V_110 ) ;
F_22 ( ! V_13 ) ;
F_22 ( ! V_13 -> V_114 ) ;
F_19 ( V_33 , V_13 ) ;
memcpy ( & V_20 , & V_13 -> V_20 , sizeof( V_20 ) ) ;
V_429 = F_324 ( V_13 ) ;
if ( V_13 -> V_6 & ( V_265 |
V_266 |
V_267 ) )
V_105 = 2 ;
else
V_105 = 1 ;
V_213 = & V_33 -> V_35 -> V_452 ;
F_11 ( & V_213 -> V_460 ) ;
F_332 ( V_13 , V_213 ) ;
F_13 ( & V_213 -> V_460 ) ;
V_213 = & V_33 -> V_35 -> V_450 ;
F_11 ( & V_213 -> V_460 ) ;
F_332 ( V_13 , V_213 ) ;
F_13 ( & V_213 -> V_460 ) ;
V_62 = F_32 () ;
if ( ! V_62 ) {
V_27 = - V_117 ;
goto V_69;
}
V_245 = F_212 ( V_92 , V_13 , V_62 ) ;
if ( ! F_213 ( V_245 ) ) {
V_27 = F_425 ( V_83 , V_245 ) ;
F_22 ( V_27 ) ;
F_426 ( V_245 ) ;
F_11 ( & V_13 -> V_49 ) ;
if ( V_13 -> V_164 ) {
V_13 -> V_164 = 0 ;
V_13 -> V_245 = NULL ;
F_13 ( & V_13 -> V_49 ) ;
F_224 ( V_245 ) ;
} else {
F_13 ( & V_13 -> V_49 ) ;
}
F_427 ( V_245 ) ;
}
V_20 . V_21 = V_535 ;
V_20 . V_31 = V_13 -> V_20 . V_21 ;
V_20 . type = 0 ;
V_27 = F_36 ( V_83 , V_92 , & V_20 , V_62 , - 1 , 1 ) ;
if ( V_27 < 0 )
goto V_69;
if ( V_27 > 0 )
F_43 ( V_62 ) ;
if ( V_27 == 0 ) {
V_27 = F_120 ( V_83 , V_92 , V_62 ) ;
if ( V_27 )
goto V_69;
F_43 ( V_62 ) ;
}
F_11 ( & V_33 -> V_35 -> V_17 ) ;
F_173 ( & V_13 -> V_19 ,
& V_33 -> V_35 -> V_18 ) ;
F_13 ( & V_33 -> V_35 -> V_17 ) ;
F_61 ( & V_13 -> V_100 -> V_272 ) ;
F_172 ( & V_13 -> V_85 ) ;
if ( F_167 ( & V_13 -> V_100 -> V_271 [ V_429 ] ) )
F_423 ( V_33 -> V_35 , V_13 -> V_6 ) ;
F_63 ( & V_13 -> V_100 -> V_272 ) ;
if ( V_13 -> V_3 == V_50 )
F_323 ( V_13 ) ;
F_409 ( V_13 ) ;
F_11 ( & V_13 -> V_100 -> V_49 ) ;
V_13 -> V_100 -> V_263 -= V_13 -> V_20 . V_31 ;
V_13 -> V_100 -> V_275 -= V_13 -> V_20 . V_31 ;
V_13 -> V_100 -> V_268 -= V_13 -> V_20 . V_31 * V_105 ;
F_13 ( & V_13 -> V_100 -> V_49 ) ;
memcpy ( & V_20 , & V_13 -> V_20 , sizeof( V_20 ) ) ;
F_71 ( V_33 -> V_35 ) ;
F_6 ( V_13 ) ;
F_6 ( V_13 ) ;
V_27 = F_36 ( V_83 , V_33 , & V_20 , V_62 , - 1 , 1 ) ;
if ( V_27 > 0 )
V_27 = - V_211 ;
if ( V_27 < 0 )
goto V_69;
V_27 = F_120 ( V_83 , V_33 , V_62 ) ;
V_69:
F_48 ( V_62 ) ;
return V_27 ;
}
int F_428 ( struct V_11 * V_35 )
{
struct V_97 * V_100 ;
struct V_536 * V_537 ;
T_2 V_538 ;
T_2 V_6 ;
int V_539 = 0 ;
int V_27 ;
V_537 = V_35 -> V_326 ;
if ( ! F_429 ( V_537 ) )
return 1 ;
V_538 = F_430 ( V_537 ) ;
if ( V_538 & V_540 )
V_539 = 1 ;
V_6 = V_286 ;
V_27 = F_228 ( V_35 , V_6 , 0 , 0 , & V_100 ) ;
if ( V_27 )
goto V_69;
if ( V_539 ) {
V_6 = V_115 | V_283 ;
V_27 = F_228 ( V_35 , V_6 , 0 , 0 , & V_100 ) ;
} else {
V_6 = V_115 ;
V_27 = F_228 ( V_35 , V_6 , 0 , 0 , & V_100 ) ;
if ( V_27 )
goto V_69;
V_6 = V_283 ;
V_27 = F_228 ( V_35 , V_6 , 0 , 0 , & V_100 ) ;
}
V_69:
return V_27 ;
}
int F_431 ( struct V_32 * V_33 , T_2 V_30 , T_2 V_29 )
{
return F_306 ( V_33 , V_30 , V_29 ) ;
}
int F_432 ( struct V_32 * V_33 , T_2 V_25 ,
T_2 V_34 , T_2 * V_185 )
{
return F_146 ( V_33 , V_25 , V_34 , V_185 ) ;
}
int F_433 ( struct V_32 * V_33 , struct V_541 * V_542 )
{
struct V_11 * V_35 = V_33 -> V_35 ;
struct V_1 * V_2 = NULL ;
T_2 V_543 ;
T_2 V_30 ;
T_2 V_29 ;
T_2 V_544 = 0 ;
T_2 V_263 = F_243 ( V_35 -> V_326 ) ;
int V_27 = 0 ;
if ( V_542 -> V_116 == V_263 )
V_2 = F_65 ( V_35 , V_542 -> V_30 ) ;
else
V_2 = F_66 ( V_35 , V_542 -> V_30 ) ;
while ( V_2 ) {
if ( V_2 -> V_20 . V_21 >= ( V_542 -> V_30 + V_542 -> V_116 ) ) {
F_6 ( V_2 ) ;
break;
}
V_30 = F_76 ( V_542 -> V_30 , V_2 -> V_20 . V_21 ) ;
V_29 = F_249 ( V_542 -> V_30 + V_542 -> V_116 ,
V_2 -> V_20 . V_21 + V_2 -> V_20 . V_31 ) ;
if ( V_29 - V_30 >= V_542 -> V_545 ) {
if ( ! F_1 ( V_2 ) ) {
V_27 = F_49 ( V_2 , NULL , V_33 , 0 ) ;
if ( ! V_27 )
F_323 ( V_2 ) ;
}
V_27 = F_434 ( V_2 ,
& V_543 ,
V_30 ,
V_29 ,
V_542 -> V_545 ) ;
V_544 += V_543 ;
if ( V_27 ) {
F_6 ( V_2 ) ;
break;
}
}
V_2 = F_210 ( V_35 -> V_92 , V_2 ) ;
}
V_542 -> V_116 = V_544 ;
return V_27 ;
}
