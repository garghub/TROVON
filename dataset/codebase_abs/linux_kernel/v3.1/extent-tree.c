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
F_13 ( & V_13 -> V_18 ) ;
return 0 ;
}
static struct V_1 *
F_16 ( struct V_12 * V_13 , T_2 V_26 ,
int V_27 )
{
struct V_1 * V_2 , * V_28 = NULL ;
struct V_15 * V_29 ;
T_2 V_30 , V_31 ;
F_11 ( & V_13 -> V_18 ) ;
V_29 = V_13 -> V_19 . V_15 ;
while ( V_29 ) {
V_2 = F_12 ( V_29 , struct V_1 ,
V_20 ) ;
V_30 = V_2 -> V_21 . V_22 + V_2 -> V_21 . V_32 - 1 ;
V_31 = V_2 -> V_21 . V_22 ;
if ( V_26 < V_31 ) {
if ( ! V_27 && ( ! V_28 || V_31 < V_28 -> V_21 . V_22 ) )
V_28 = V_2 ;
V_29 = V_29 -> V_23 ;
} else if ( V_26 > V_31 ) {
if ( V_27 && V_26 <= V_30 ) {
V_28 = V_2 ;
break;
}
V_29 = V_29 -> V_24 ;
} else {
V_28 = V_2 ;
break;
}
}
if ( V_28 )
F_4 ( V_28 ) ;
F_13 ( & V_13 -> V_18 ) ;
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
V_31 = V_2 -> V_21 . V_22 ;
V_30 = V_31 + V_2 -> V_21 . V_32 - 1 ;
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
if ( V_2 -> V_21 . V_22 < V_44 ) {
V_41 = V_44 - V_2 -> V_21 . V_22 ;
V_2 -> V_45 += V_41 ;
V_28 = F_17 ( V_34 , V_2 -> V_21 . V_22 ,
V_41 ) ;
F_22 ( V_28 ) ;
}
for ( V_42 = 0 ; V_42 < V_46 ; V_42 ++ ) {
V_26 = F_23 ( V_42 ) ;
V_28 = F_24 ( & V_34 -> V_36 -> V_47 ,
V_2 -> V_21 . V_22 , V_26 ,
0 , & V_40 , & V_43 , & V_41 ) ;
F_22 ( V_28 ) ;
while ( V_43 -- ) {
V_2 -> V_45 += V_41 ;
V_28 = F_17 ( V_34 , V_40 [ V_43 ] ,
V_41 ) ;
F_22 ( V_28 ) ;
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
if ( V_2 -> V_3 != V_51 ) {
F_13 ( & V_2 -> V_50 ) ;
return NULL ;
}
if ( ! V_2 -> V_52 ) {
F_13 ( & V_2 -> V_50 ) ;
return NULL ;
}
V_49 = V_2 -> V_52 ;
F_5 ( & V_49 -> V_7 ) ;
F_13 ( & V_2 -> V_50 ) ;
return V_49 ;
}
static void F_26 ( struct V_48 * V_49 )
{
if ( F_7 ( & V_49 -> V_7 ) )
F_9 ( V_49 ) ;
}
static T_2 F_27 ( struct V_1 * V_14 ,
struct V_12 * V_13 , T_2 V_31 , T_2 V_30 )
{
T_2 V_53 , V_54 , V_55 , V_56 = 0 ;
int V_28 ;
while ( V_31 < V_30 ) {
V_28 = F_28 ( V_13 -> V_57 , V_31 ,
& V_53 , & V_54 ,
V_58 | V_38 ) ;
if ( V_28 )
break;
if ( V_53 <= V_31 ) {
V_31 = V_54 + 1 ;
} else if ( V_53 > V_31 && V_53 < V_30 ) {
V_55 = V_53 - V_31 ;
V_56 += V_55 ;
V_28 = F_29 ( V_14 , V_31 ,
V_55 ) ;
F_22 ( V_28 ) ;
V_31 = V_54 + 1 ;
} else {
break;
}
}
if ( V_31 < V_30 ) {
V_55 = V_30 - V_31 ;
V_56 += V_55 ;
V_28 = F_29 ( V_14 , V_31 , V_55 ) ;
F_22 ( V_28 ) ;
}
return V_56 ;
}
static T_1 void F_30 ( struct V_59 * V_60 )
{
struct V_1 * V_14 ;
struct V_12 * V_36 ;
struct V_48 * V_52 ;
struct V_33 * V_61 ;
struct V_62 * V_63 ;
struct V_64 * V_65 ;
struct V_66 V_21 ;
T_2 V_67 = 0 ;
T_2 V_68 = 0 ;
T_3 V_69 ;
int V_28 = 0 ;
V_52 = F_31 ( V_60 , struct V_48 , V_60 ) ;
V_14 = V_52 -> V_14 ;
V_36 = V_14 -> V_36 ;
V_61 = V_36 -> V_61 ;
V_63 = F_32 () ;
if ( ! V_63 )
goto V_70;
V_68 = F_33 ( T_2 , V_14 -> V_21 . V_22 , V_44 ) ;
V_63 -> V_71 = 1 ;
V_63 -> V_72 = 1 ;
V_63 -> V_73 = 1 ;
V_21 . V_22 = V_68 ;
V_21 . V_32 = 0 ;
V_21 . type = V_74 ;
V_75:
F_34 ( & V_52 -> V_76 ) ;
F_35 ( & V_36 -> V_77 ) ;
V_28 = F_36 ( NULL , V_61 , & V_21 , V_63 , 0 , 0 ) ;
if ( V_28 < 0 )
goto V_78;
V_65 = V_63 -> V_79 [ 0 ] ;
V_69 = F_37 ( V_65 ) ;
while ( 1 ) {
if ( F_38 ( V_36 ) > 1 ) {
V_68 = ( T_2 ) - 1 ;
break;
}
if ( V_63 -> V_80 [ 0 ] < V_69 ) {
F_39 ( V_65 , & V_21 , V_63 -> V_80 [ 0 ] ) ;
} else {
V_28 = F_40 ( V_63 , 0 , & V_21 ) ;
if ( V_28 )
break;
if ( F_41 () ||
F_42 ( V_61 , V_63 ) ) {
V_52 -> V_81 = V_68 ;
F_43 ( V_63 ) ;
F_44 ( & V_36 -> V_77 ) ;
F_45 ( & V_52 -> V_76 ) ;
F_46 () ;
goto V_75;
}
V_65 = V_63 -> V_79 [ 0 ] ;
V_69 = F_37 ( V_65 ) ;
continue;
}
if ( V_21 . V_22 < V_14 -> V_21 . V_22 ) {
V_63 -> V_80 [ 0 ] ++ ;
continue;
}
if ( V_21 . V_22 >= V_14 -> V_21 . V_22 +
V_14 -> V_21 . V_32 )
break;
if ( V_21 . type == V_74 ) {
V_67 += F_27 ( V_14 ,
V_36 , V_68 ,
V_21 . V_22 ) ;
V_68 = V_21 . V_22 + V_21 . V_32 ;
if ( V_67 > ( 1024 * 1024 * 2 ) ) {
V_67 = 0 ;
F_47 ( & V_52 -> V_82 ) ;
}
}
V_63 -> V_80 [ 0 ] ++ ;
}
V_28 = 0 ;
V_67 += F_27 ( V_14 , V_36 , V_68 ,
V_14 -> V_21 . V_22 +
V_14 -> V_21 . V_32 ) ;
V_52 -> V_81 = ( T_2 ) - 1 ;
F_11 ( & V_14 -> V_50 ) ;
V_14 -> V_52 = NULL ;
V_14 -> V_3 = V_4 ;
F_13 ( & V_14 -> V_50 ) ;
V_78:
F_48 ( V_63 ) ;
F_44 ( & V_36 -> V_77 ) ;
F_19 ( V_61 , V_14 ) ;
F_45 ( & V_52 -> V_76 ) ;
V_70:
F_47 ( & V_52 -> V_82 ) ;
F_26 ( V_52 ) ;
F_6 ( V_14 ) ;
}
static int F_49 ( struct V_1 * V_2 ,
struct V_83 * V_84 ,
struct V_33 * V_34 ,
int V_85 )
{
struct V_12 * V_36 = V_2 -> V_36 ;
struct V_48 * V_52 ;
int V_28 = 0 ;
F_2 () ;
if ( V_2 -> V_3 != V_86 )
return 0 ;
if ( V_84 && ( ! V_84 -> V_87 -> V_88 ) &&
( V_34 && V_34 != V_34 -> V_36 -> V_89 ) ) {
F_11 ( & V_2 -> V_50 ) ;
if ( V_2 -> V_3 != V_86 ) {
F_13 ( & V_2 -> V_50 ) ;
return 0 ;
}
V_2 -> V_3 = V_51 ;
F_13 ( & V_2 -> V_50 ) ;
V_28 = F_50 ( V_36 , V_2 ) ;
F_11 ( & V_2 -> V_50 ) ;
if ( V_28 == 1 ) {
V_2 -> V_3 = V_4 ;
V_2 -> V_90 = ( T_2 ) - 1 ;
} else {
V_2 -> V_3 = V_86 ;
}
F_13 ( & V_2 -> V_50 ) ;
if ( V_28 == 1 ) {
F_19 ( V_36 -> V_61 , V_2 ) ;
return 0 ;
}
}
if ( V_85 )
return 0 ;
V_52 = F_51 ( sizeof( * V_52 ) , V_39 ) ;
F_22 ( ! V_52 ) ;
F_52 ( & V_52 -> V_91 ) ;
F_53 ( & V_52 -> V_76 ) ;
F_54 ( & V_52 -> V_82 ) ;
V_52 -> V_14 = V_2 ;
V_52 -> V_81 = V_2 -> V_21 . V_22 ;
F_55 ( & V_52 -> V_7 , 2 ) ;
V_52 -> V_60 . V_92 = F_30 ;
F_11 ( & V_2 -> V_50 ) ;
if ( V_2 -> V_3 != V_86 ) {
F_13 ( & V_2 -> V_50 ) ;
F_9 ( V_52 ) ;
return 0 ;
}
V_2 -> V_52 = V_52 ;
V_2 -> V_3 = V_51 ;
F_13 ( & V_2 -> V_50 ) ;
F_56 ( & V_36 -> V_77 ) ;
F_57 ( & V_52 -> V_91 , & V_36 -> V_93 ) ;
F_58 ( & V_36 -> V_77 ) ;
F_4 ( V_2 ) ;
F_59 ( & V_36 -> V_94 , & V_52 -> V_60 ) ;
return V_28 ;
}
static struct V_1 *
F_60 ( struct V_12 * V_13 , T_2 V_26 )
{
struct V_1 * V_2 ;
V_2 = F_16 ( V_13 , V_26 , 0 ) ;
return V_2 ;
}
struct V_1 * F_61 (
struct V_12 * V_13 ,
T_2 V_26 )
{
struct V_1 * V_2 ;
V_2 = F_16 ( V_13 , V_26 , 1 ) ;
return V_2 ;
}
static struct V_95 * F_62 ( struct V_12 * V_13 ,
T_2 V_6 )
{
struct V_96 * V_97 = & V_13 -> V_98 ;
struct V_95 * V_99 ;
V_6 &= V_100 | V_101 |
V_102 ;
F_63 () ;
F_64 (found, head, list) {
if ( V_99 -> V_6 & V_6 ) {
F_65 () ;
return V_99 ;
}
}
F_65 () ;
return NULL ;
}
void F_66 ( struct V_12 * V_13 )
{
struct V_96 * V_97 = & V_13 -> V_98 ;
struct V_95 * V_99 ;
F_63 () ;
F_64 (found, head, list)
V_99 -> V_103 = 0 ;
F_65 () ;
}
static T_2 F_67 ( T_2 V_104 , int V_105 )
{
if ( V_105 == 10 )
return V_104 ;
V_104 *= V_105 ;
F_68 ( V_104 , 10 ) ;
return V_104 ;
}
static T_2 F_69 ( T_2 V_104 , int V_105 )
{
if ( V_105 == 100 )
return V_104 ;
V_104 *= V_105 ;
F_68 ( V_104 , 100 ) ;
return V_104 ;
}
T_2 F_70 ( struct V_33 * V_34 ,
T_2 V_106 , T_2 V_107 , int V_108 )
{
struct V_1 * V_2 ;
T_2 V_109 ;
T_2 V_68 = F_71 ( V_107 , V_106 ) ;
T_2 V_110 = 0 ;
int V_111 = 0 ;
int V_105 = 9 ;
int V_112 = 0 ;
V_75:
while ( 1 ) {
V_2 = F_60 ( V_34 -> V_36 , V_68 ) ;
if ( ! V_2 )
break;
F_11 ( & V_2 -> V_50 ) ;
V_68 = V_2 -> V_21 . V_22 + V_2 -> V_21 . V_32 ;
V_109 = F_72 ( & V_2 -> V_113 ) ;
if ( ( V_111 || ! V_2 -> V_114 ) &&
F_3 ( V_2 , V_102 ) ) {
if ( V_109 + V_2 -> V_8 + V_2 -> V_9 <
F_67 ( V_2 -> V_21 . V_32 , V_105 ) ) {
V_110 = V_2 -> V_21 . V_22 ;
F_13 ( & V_2 -> V_50 ) ;
F_6 ( V_2 ) ;
goto V_99;
}
}
F_13 ( & V_2 -> V_50 ) ;
F_6 ( V_2 ) ;
F_46 () ;
}
if ( ! V_112 ) {
V_68 = V_106 ;
V_112 = 1 ;
goto V_75;
}
if ( ! V_111 && V_105 < 10 ) {
V_68 = V_106 ;
V_111 = 1 ;
V_105 = 10 ;
goto V_75;
}
V_99:
return V_110 ;
}
int F_73 ( struct V_33 * V_34 , T_2 V_31 , T_2 V_115 )
{
int V_28 ;
struct V_66 V_21 ;
struct V_62 * V_63 ;
V_63 = F_32 () ;
if ( ! V_63 )
return - V_116 ;
V_21 . V_22 = V_31 ;
V_21 . V_32 = V_115 ;
F_74 ( & V_21 , V_74 ) ;
V_28 = F_36 ( NULL , V_34 -> V_36 -> V_61 , & V_21 , V_63 ,
0 , 0 ) ;
F_48 ( V_63 ) ;
return V_28 ;
}
int F_75 ( struct V_83 * V_84 ,
struct V_33 * V_34 , T_2 V_26 ,
T_2 V_35 , T_2 * V_117 , T_2 * V_6 )
{
struct V_118 * V_97 ;
struct V_119 * V_120 ;
struct V_62 * V_63 ;
struct V_121 * V_122 ;
struct V_64 * V_65 ;
struct V_66 V_21 ;
T_3 V_123 ;
T_2 V_124 ;
T_2 V_125 ;
int V_28 ;
V_63 = F_32 () ;
if ( ! V_63 )
return - V_116 ;
V_21 . V_22 = V_26 ;
V_21 . type = V_74 ;
V_21 . V_32 = V_35 ;
if ( ! V_84 ) {
V_63 -> V_71 = 1 ;
V_63 -> V_72 = 1 ;
}
V_75:
V_28 = F_36 ( V_84 , V_34 -> V_36 -> V_61 ,
& V_21 , V_63 , 0 , 0 ) ;
if ( V_28 < 0 )
goto V_126;
if ( V_28 == 0 ) {
V_65 = V_63 -> V_79 [ 0 ] ;
V_123 = F_76 ( V_65 , V_63 -> V_80 [ 0 ] ) ;
if ( V_123 >= sizeof( * V_122 ) ) {
V_122 = F_77 ( V_65 , V_63 -> V_80 [ 0 ] ,
struct V_121 ) ;
V_124 = F_78 ( V_65 , V_122 ) ;
V_125 = F_79 ( V_65 , V_122 ) ;
} else {
#ifdef F_80
struct V_127 * V_128 ;
F_22 ( V_123 != sizeof( * V_128 ) ) ;
V_128 = F_77 ( V_65 , V_63 -> V_80 [ 0 ] ,
struct V_127 ) ;
V_124 = F_81 ( V_65 , V_128 ) ;
V_125 = V_129 ;
#else
F_82 () ;
#endif
}
F_22 ( V_124 == 0 ) ;
} else {
V_124 = 0 ;
V_125 = 0 ;
V_28 = 0 ;
}
if ( ! V_84 )
goto V_70;
V_120 = & V_84 -> V_87 -> V_120 ;
F_11 ( & V_120 -> V_50 ) ;
V_97 = F_83 ( V_84 , V_26 ) ;
if ( V_97 ) {
if ( ! F_84 ( & V_97 -> V_76 ) ) {
F_5 ( & V_97 -> V_130 . V_117 ) ;
F_13 ( & V_120 -> V_50 ) ;
F_43 ( V_63 ) ;
F_34 ( & V_97 -> V_76 ) ;
F_45 ( & V_97 -> V_76 ) ;
F_85 ( & V_97 -> V_130 ) ;
goto V_75;
}
if ( V_97 -> V_131 && V_97 -> V_131 -> V_132 )
V_125 |= V_97 -> V_131 -> V_133 ;
else
F_22 ( V_124 == 0 ) ;
V_124 += V_97 -> V_130 . V_134 ;
F_45 ( & V_97 -> V_76 ) ;
}
F_13 ( & V_120 -> V_50 ) ;
V_70:
F_8 ( V_124 == 0 ) ;
if ( V_117 )
* V_117 = V_124 ;
if ( V_6 )
* V_6 = V_125 ;
V_126:
F_48 ( V_63 ) ;
return V_28 ;
}
static int F_86 ( struct V_83 * V_84 ,
struct V_33 * V_34 ,
struct V_62 * V_63 ,
T_2 V_108 , T_3 V_135 )
{
struct V_121 * V_113 ;
struct V_127 * V_128 ;
struct V_136 * V_137 ;
struct V_138 * V_139 ;
struct V_64 * V_65 ;
struct V_66 V_21 ;
struct V_66 V_140 ;
T_3 V_141 = sizeof( * V_113 ) ;
T_2 V_117 ;
int V_28 ;
V_65 = V_63 -> V_79 [ 0 ] ;
F_22 ( F_76 ( V_65 , V_63 -> V_80 [ 0 ] ) != sizeof( * V_128 ) ) ;
F_39 ( V_65 , & V_21 , V_63 -> V_80 [ 0 ] ) ;
V_128 = F_77 ( V_65 , V_63 -> V_80 [ 0 ] ,
struct V_127 ) ;
V_117 = F_81 ( V_65 , V_128 ) ;
if ( V_108 == ( T_2 ) - 1 ) {
while ( 1 ) {
if ( V_63 -> V_80 [ 0 ] >= F_37 ( V_65 ) ) {
V_28 = F_42 ( V_34 , V_63 ) ;
if ( V_28 < 0 )
return V_28 ;
F_22 ( V_28 > 0 ) ;
V_65 = V_63 -> V_79 [ 0 ] ;
}
F_39 ( V_65 , & V_140 ,
V_63 -> V_80 [ 0 ] ) ;
F_22 ( V_21 . V_22 != V_140 . V_22 ) ;
if ( V_140 . type != V_142 ) {
V_63 -> V_80 [ 0 ] ++ ;
continue;
}
V_137 = F_77 ( V_65 , V_63 -> V_80 [ 0 ] ,
struct V_136 ) ;
V_108 = F_87 ( V_65 , V_137 ) ;
break;
}
}
F_43 ( V_63 ) ;
if ( V_108 < V_143 )
V_141 += sizeof( * V_139 ) ;
V_141 -= sizeof( * V_128 ) ;
V_28 = F_36 ( V_84 , V_34 , & V_21 , V_63 ,
V_141 + V_135 , 1 ) ;
if ( V_28 < 0 )
return V_28 ;
F_22 ( V_28 ) ;
V_28 = F_88 ( V_84 , V_34 , V_63 , V_141 ) ;
V_65 = V_63 -> V_79 [ 0 ] ;
V_113 = F_77 ( V_65 , V_63 -> V_80 [ 0 ] , struct V_121 ) ;
F_89 ( V_65 , V_113 , V_117 ) ;
F_90 ( V_65 , V_113 , 0 ) ;
if ( V_108 < V_143 ) {
F_91 ( V_65 , V_113 ,
V_144 |
V_129 ) ;
V_139 = (struct V_138 * ) ( V_113 + 1 ) ;
F_92 ( V_65 , 0 , ( unsigned long ) V_139 , sizeof( * V_139 ) ) ;
F_93 ( V_65 , V_139 , ( int ) V_108 ) ;
} else {
F_91 ( V_65 , V_113 , V_145 ) ;
}
F_94 ( V_65 ) ;
return 0 ;
}
static T_2 F_95 ( T_2 V_146 , T_2 V_108 , T_2 V_32 )
{
T_3 V_147 = ~ ( T_3 ) 0 ;
T_3 V_148 = ~ ( T_3 ) 0 ;
T_4 V_149 ;
V_149 = F_96 ( V_146 ) ;
V_147 = F_97 ( V_147 , & V_149 , sizeof( V_149 ) ) ;
V_149 = F_96 ( V_108 ) ;
V_148 = F_97 ( V_148 , & V_149 , sizeof( V_149 ) ) ;
V_149 = F_96 ( V_32 ) ;
V_148 = F_97 ( V_148 , & V_149 , sizeof( V_149 ) ) ;
return ( ( T_2 ) V_147 << 31 ) ^ ( T_2 ) V_148 ;
}
static T_2 F_98 ( struct V_64 * V_65 ,
struct V_150 * V_151 )
{
return F_95 ( F_99 ( V_65 , V_151 ) ,
F_100 ( V_65 , V_151 ) ,
F_101 ( V_65 , V_151 ) ) ;
}
static int F_102 ( struct V_64 * V_65 ,
struct V_150 * V_151 ,
T_2 V_146 , T_2 V_108 , T_2 V_32 )
{
if ( F_99 ( V_65 , V_151 ) != V_146 ||
F_100 ( V_65 , V_151 ) != V_108 ||
F_101 ( V_65 , V_151 ) != V_32 )
return 0 ;
return 1 ;
}
static T_1 int F_103 ( struct V_83 * V_84 ,
struct V_33 * V_34 ,
struct V_62 * V_63 ,
T_2 V_26 , T_2 V_17 ,
T_2 V_146 ,
T_2 V_108 , T_2 V_32 )
{
struct V_66 V_21 ;
struct V_150 * V_151 ;
struct V_64 * V_65 ;
T_3 V_69 ;
int V_28 ;
int V_152 ;
int V_78 = - V_153 ;
V_21 . V_22 = V_26 ;
if ( V_17 ) {
V_21 . type = V_154 ;
V_21 . V_32 = V_17 ;
} else {
V_21 . type = V_155 ;
V_21 . V_32 = F_95 ( V_146 ,
V_108 , V_32 ) ;
}
V_75:
V_152 = 0 ;
V_28 = F_36 ( V_84 , V_34 , & V_21 , V_63 , - 1 , 1 ) ;
if ( V_28 < 0 ) {
V_78 = V_28 ;
goto V_156;
}
if ( V_17 ) {
if ( ! V_28 )
return 0 ;
#ifdef F_80
V_21 . type = V_142 ;
F_43 ( V_63 ) ;
V_28 = F_36 ( V_84 , V_34 , & V_21 , V_63 , - 1 , 1 ) ;
if ( V_28 < 0 ) {
V_78 = V_28 ;
goto V_156;
}
if ( ! V_28 )
return 0 ;
#endif
goto V_156;
}
V_65 = V_63 -> V_79 [ 0 ] ;
V_69 = F_37 ( V_65 ) ;
while ( 1 ) {
if ( V_63 -> V_80 [ 0 ] >= V_69 ) {
V_28 = F_42 ( V_34 , V_63 ) ;
if ( V_28 < 0 )
V_78 = V_28 ;
if ( V_28 )
goto V_156;
V_65 = V_63 -> V_79 [ 0 ] ;
V_69 = F_37 ( V_65 ) ;
V_152 = 1 ;
}
F_39 ( V_65 , & V_21 , V_63 -> V_80 [ 0 ] ) ;
if ( V_21 . V_22 != V_26 ||
V_21 . type != V_155 )
goto V_156;
V_151 = F_77 ( V_65 , V_63 -> V_80 [ 0 ] ,
struct V_150 ) ;
if ( F_102 ( V_65 , V_151 , V_146 ,
V_108 , V_32 ) ) {
if ( V_152 ) {
F_43 ( V_63 ) ;
goto V_75;
}
V_78 = 0 ;
break;
}
V_63 -> V_80 [ 0 ] ++ ;
}
V_156:
return V_78 ;
}
static T_1 int F_104 ( struct V_83 * V_84 ,
struct V_33 * V_34 ,
struct V_62 * V_63 ,
T_2 V_26 , T_2 V_17 ,
T_2 V_146 , T_2 V_108 ,
T_2 V_32 , int V_157 )
{
struct V_66 V_21 ;
struct V_64 * V_65 ;
T_3 V_55 ;
T_3 V_124 ;
int V_28 ;
V_21 . V_22 = V_26 ;
if ( V_17 ) {
V_21 . type = V_154 ;
V_21 . V_32 = V_17 ;
V_55 = sizeof( struct V_158 ) ;
} else {
V_21 . type = V_155 ;
V_21 . V_32 = F_95 ( V_146 ,
V_108 , V_32 ) ;
V_55 = sizeof( struct V_150 ) ;
}
V_28 = F_105 ( V_84 , V_34 , V_63 , & V_21 , V_55 ) ;
if ( V_28 && V_28 != - V_25 )
goto V_156;
V_65 = V_63 -> V_79 [ 0 ] ;
if ( V_17 ) {
struct V_158 * V_151 ;
V_151 = F_77 ( V_65 , V_63 -> V_80 [ 0 ] ,
struct V_158 ) ;
if ( V_28 == 0 ) {
F_106 ( V_65 , V_151 , V_157 ) ;
} else {
V_124 = F_107 ( V_65 , V_151 ) ;
V_124 += V_157 ;
F_106 ( V_65 , V_151 , V_124 ) ;
}
} else {
struct V_150 * V_151 ;
while ( V_28 == - V_25 ) {
V_151 = F_77 ( V_65 , V_63 -> V_80 [ 0 ] ,
struct V_150 ) ;
if ( F_102 ( V_65 , V_151 , V_146 ,
V_108 , V_32 ) )
break;
F_43 ( V_63 ) ;
V_21 . V_32 ++ ;
V_28 = F_105 ( V_84 , V_34 , V_63 , & V_21 ,
V_55 ) ;
if ( V_28 && V_28 != - V_25 )
goto V_156;
V_65 = V_63 -> V_79 [ 0 ] ;
}
V_151 = F_77 ( V_65 , V_63 -> V_80 [ 0 ] ,
struct V_150 ) ;
if ( V_28 == 0 ) {
F_108 ( V_65 , V_151 ,
V_146 ) ;
F_109 ( V_65 , V_151 , V_108 ) ;
F_110 ( V_65 , V_151 , V_32 ) ;
F_111 ( V_65 , V_151 , V_157 ) ;
} else {
V_124 = F_112 ( V_65 , V_151 ) ;
V_124 += V_157 ;
F_111 ( V_65 , V_151 , V_124 ) ;
}
}
F_94 ( V_65 ) ;
V_28 = 0 ;
V_156:
F_43 ( V_63 ) ;
return V_28 ;
}
static T_1 int F_113 ( struct V_83 * V_84 ,
struct V_33 * V_34 ,
struct V_62 * V_63 ,
int V_159 )
{
struct V_66 V_21 ;
struct V_150 * V_160 = NULL ;
struct V_158 * V_161 = NULL ;
struct V_64 * V_65 ;
T_3 V_124 = 0 ;
int V_28 = 0 ;
V_65 = V_63 -> V_79 [ 0 ] ;
F_39 ( V_65 , & V_21 , V_63 -> V_80 [ 0 ] ) ;
if ( V_21 . type == V_155 ) {
V_160 = F_77 ( V_65 , V_63 -> V_80 [ 0 ] ,
struct V_150 ) ;
V_124 = F_112 ( V_65 , V_160 ) ;
} else if ( V_21 . type == V_154 ) {
V_161 = F_77 ( V_65 , V_63 -> V_80 [ 0 ] ,
struct V_158 ) ;
V_124 = F_107 ( V_65 , V_161 ) ;
#ifdef F_80
} else if ( V_21 . type == V_142 ) {
struct V_136 * V_137 ;
V_137 = F_77 ( V_65 , V_63 -> V_80 [ 0 ] ,
struct V_136 ) ;
V_124 = F_114 ( V_65 , V_137 ) ;
#endif
} else {
F_82 () ;
}
F_22 ( V_124 < V_159 ) ;
V_124 -= V_159 ;
if ( V_124 == 0 ) {
V_28 = F_115 ( V_84 , V_34 , V_63 ) ;
} else {
if ( V_21 . type == V_155 )
F_111 ( V_65 , V_160 , V_124 ) ;
else if ( V_21 . type == V_154 )
F_106 ( V_65 , V_161 , V_124 ) ;
#ifdef F_80
else {
struct V_136 * V_137 ;
V_137 = F_77 ( V_65 , V_63 -> V_80 [ 0 ] ,
struct V_136 ) ;
F_116 ( V_65 , V_137 , V_124 ) ;
}
#endif
F_94 ( V_65 ) ;
}
return V_28 ;
}
static T_1 T_3 F_117 ( struct V_33 * V_34 ,
struct V_62 * V_63 ,
struct V_162 * V_163 )
{
struct V_66 V_21 ;
struct V_64 * V_65 ;
struct V_150 * V_160 ;
struct V_158 * V_161 ;
T_3 V_124 = 0 ;
V_65 = V_63 -> V_79 [ 0 ] ;
F_39 ( V_65 , & V_21 , V_63 -> V_80 [ 0 ] ) ;
if ( V_163 ) {
if ( F_118 ( V_65 , V_163 ) ==
V_155 ) {
V_160 = (struct V_150 * ) ( & V_163 -> V_32 ) ;
V_124 = F_112 ( V_65 , V_160 ) ;
} else {
V_161 = (struct V_158 * ) ( V_163 + 1 ) ;
V_124 = F_107 ( V_65 , V_161 ) ;
}
} else if ( V_21 . type == V_155 ) {
V_160 = F_77 ( V_65 , V_63 -> V_80 [ 0 ] ,
struct V_150 ) ;
V_124 = F_112 ( V_65 , V_160 ) ;
} else if ( V_21 . type == V_154 ) {
V_161 = F_77 ( V_65 , V_63 -> V_80 [ 0 ] ,
struct V_158 ) ;
V_124 = F_107 ( V_65 , V_161 ) ;
#ifdef F_80
} else if ( V_21 . type == V_142 ) {
struct V_136 * V_137 ;
V_137 = F_77 ( V_65 , V_63 -> V_80 [ 0 ] ,
struct V_136 ) ;
V_124 = F_114 ( V_65 , V_137 ) ;
#endif
} else {
F_8 ( 1 ) ;
}
return V_124 ;
}
static T_1 int F_119 ( struct V_83 * V_84 ,
struct V_33 * V_34 ,
struct V_62 * V_63 ,
T_2 V_26 , T_2 V_17 ,
T_2 V_146 )
{
struct V_66 V_21 ;
int V_28 ;
V_21 . V_22 = V_26 ;
if ( V_17 ) {
V_21 . type = V_164 ;
V_21 . V_32 = V_17 ;
} else {
V_21 . type = V_165 ;
V_21 . V_32 = V_146 ;
}
V_28 = F_36 ( V_84 , V_34 , & V_21 , V_63 , - 1 , 1 ) ;
if ( V_28 > 0 )
V_28 = - V_153 ;
#ifdef F_80
if ( V_28 == - V_153 && V_17 ) {
F_43 ( V_63 ) ;
V_21 . type = V_142 ;
V_28 = F_36 ( V_84 , V_34 , & V_21 , V_63 , - 1 , 1 ) ;
if ( V_28 > 0 )
V_28 = - V_153 ;
}
#endif
return V_28 ;
}
static T_1 int F_120 ( struct V_83 * V_84 ,
struct V_33 * V_34 ,
struct V_62 * V_63 ,
T_2 V_26 , T_2 V_17 ,
T_2 V_146 )
{
struct V_66 V_21 ;
int V_28 ;
V_21 . V_22 = V_26 ;
if ( V_17 ) {
V_21 . type = V_164 ;
V_21 . V_32 = V_17 ;
} else {
V_21 . type = V_165 ;
V_21 . V_32 = V_146 ;
}
V_28 = F_105 ( V_84 , V_34 , V_63 , & V_21 , 0 ) ;
F_43 ( V_63 ) ;
return V_28 ;
}
static inline int F_121 ( T_2 V_17 , T_2 V_108 )
{
int type ;
if ( V_108 < V_143 ) {
if ( V_17 > 0 )
type = V_164 ;
else
type = V_165 ;
} else {
if ( V_17 > 0 )
type = V_154 ;
else
type = V_155 ;
}
return type ;
}
static int F_40 ( struct V_62 * V_63 , int V_166 ,
struct V_66 * V_21 )
{
for (; V_166 < V_167 ; V_166 ++ ) {
if ( ! V_63 -> V_79 [ V_166 ] )
break;
if ( V_63 -> V_80 [ V_166 ] + 1 >=
F_37 ( V_63 -> V_79 [ V_166 ] ) )
continue;
if ( V_166 == 0 )
F_39 ( V_63 -> V_79 [ V_166 ] , V_21 ,
V_63 -> V_80 [ V_166 ] + 1 ) ;
else
F_122 ( V_63 -> V_79 [ V_166 ] , V_21 ,
V_63 -> V_80 [ V_166 ] + 1 ) ;
return 0 ;
}
return 1 ;
}
static T_5
int F_123 ( struct V_83 * V_84 ,
struct V_33 * V_34 ,
struct V_62 * V_63 ,
struct V_162 * * V_168 ,
T_2 V_26 , T_2 V_35 ,
T_2 V_17 , T_2 V_146 ,
T_2 V_108 , T_2 V_32 , int V_169 )
{
struct V_66 V_21 ;
struct V_64 * V_65 ;
struct V_121 * V_122 ;
struct V_162 * V_163 ;
T_2 V_6 ;
T_2 V_123 ;
unsigned long V_170 ;
unsigned long V_30 ;
int V_135 ;
int type ;
int V_171 ;
int V_28 ;
int V_78 = 0 ;
V_21 . V_22 = V_26 ;
V_21 . type = V_74 ;
V_21 . V_32 = V_35 ;
V_171 = F_121 ( V_17 , V_108 ) ;
if ( V_169 ) {
V_135 = F_124 ( V_171 ) ;
V_63 -> V_172 = 1 ;
} else
V_135 = - 1 ;
V_28 = F_36 ( V_84 , V_34 , & V_21 , V_63 , V_135 , 1 ) ;
if ( V_28 < 0 ) {
V_78 = V_28 ;
goto V_70;
}
F_22 ( V_28 ) ;
V_65 = V_63 -> V_79 [ 0 ] ;
V_123 = F_76 ( V_65 , V_63 -> V_80 [ 0 ] ) ;
#ifdef F_80
if ( V_123 < sizeof( * V_122 ) ) {
if ( ! V_169 ) {
V_78 = - V_153 ;
goto V_70;
}
V_28 = F_86 ( V_84 , V_34 , V_63 , V_108 ,
V_135 ) ;
if ( V_28 < 0 ) {
V_78 = V_28 ;
goto V_70;
}
V_65 = V_63 -> V_79 [ 0 ] ;
V_123 = F_76 ( V_65 , V_63 -> V_80 [ 0 ] ) ;
}
#endif
F_22 ( V_123 < sizeof( * V_122 ) ) ;
V_122 = F_77 ( V_65 , V_63 -> V_80 [ 0 ] , struct V_121 ) ;
V_6 = F_79 ( V_65 , V_122 ) ;
V_170 = ( unsigned long ) ( V_122 + 1 ) ;
V_30 = ( unsigned long ) V_122 + V_123 ;
if ( V_6 & V_144 ) {
V_170 += sizeof( struct V_138 ) ;
F_22 ( V_170 > V_30 ) ;
} else {
F_22 ( ! ( V_6 & V_145 ) ) ;
}
V_78 = - V_153 ;
while ( 1 ) {
if ( V_170 >= V_30 ) {
F_8 ( V_170 > V_30 ) ;
break;
}
V_163 = (struct V_162 * ) V_170 ;
type = F_118 ( V_65 , V_163 ) ;
if ( V_171 < type )
break;
if ( V_171 > type ) {
V_170 += F_124 ( type ) ;
continue;
}
if ( type == V_155 ) {
struct V_150 * V_173 ;
V_173 = (struct V_150 * ) ( & V_163 -> V_32 ) ;
if ( F_102 ( V_65 , V_173 , V_146 ,
V_108 , V_32 ) ) {
V_78 = 0 ;
break;
}
if ( F_98 ( V_65 , V_173 ) <
F_95 ( V_146 , V_108 , V_32 ) )
break;
} else {
T_2 V_174 ;
V_174 = F_125 ( V_65 , V_163 ) ;
if ( V_17 > 0 ) {
if ( V_17 == V_174 ) {
V_78 = 0 ;
break;
}
if ( V_174 < V_17 )
break;
} else {
if ( V_146 == V_174 ) {
V_78 = 0 ;
break;
}
if ( V_174 < V_146 )
break;
}
}
V_170 += F_124 ( type ) ;
}
if ( V_78 == - V_153 && V_169 ) {
if ( V_123 + V_135 >=
F_126 ( V_34 ) ) {
V_78 = - V_175 ;
goto V_70;
}
if ( F_40 ( V_63 , 0 , & V_21 ) == 0 &&
V_21 . V_22 == V_26 &&
V_21 . type < V_176 ) {
V_78 = - V_175 ;
goto V_70;
}
}
* V_168 = (struct V_162 * ) V_170 ;
V_70:
if ( V_169 ) {
V_63 -> V_172 = 0 ;
F_127 ( V_63 , 1 ) ;
}
return V_78 ;
}
static T_5
int F_128 ( struct V_83 * V_84 ,
struct V_33 * V_34 ,
struct V_62 * V_63 ,
struct V_162 * V_163 ,
T_2 V_17 , T_2 V_146 ,
T_2 V_108 , T_2 V_32 , int V_157 ,
struct V_177 * V_131 )
{
struct V_64 * V_65 ;
struct V_121 * V_122 ;
unsigned long V_170 ;
unsigned long V_30 ;
unsigned long V_178 ;
T_2 V_117 ;
int V_55 ;
int type ;
int V_28 ;
V_65 = V_63 -> V_79 [ 0 ] ;
V_122 = F_77 ( V_65 , V_63 -> V_80 [ 0 ] , struct V_121 ) ;
V_178 = ( unsigned long ) V_163 - ( unsigned long ) V_122 ;
type = F_121 ( V_17 , V_108 ) ;
V_55 = F_124 ( type ) ;
V_28 = F_88 ( V_84 , V_34 , V_63 , V_55 ) ;
V_122 = F_77 ( V_65 , V_63 -> V_80 [ 0 ] , struct V_121 ) ;
V_117 = F_78 ( V_65 , V_122 ) ;
V_117 += V_157 ;
F_89 ( V_65 , V_122 , V_117 ) ;
if ( V_131 )
F_129 ( V_131 , V_65 , V_122 ) ;
V_170 = ( unsigned long ) V_122 + V_178 ;
V_30 = ( unsigned long ) V_122 + F_76 ( V_65 , V_63 -> V_80 [ 0 ] ) ;
if ( V_170 < V_30 - V_55 )
F_130 ( V_65 , V_170 + V_55 , V_170 ,
V_30 - V_55 - V_170 ) ;
V_163 = (struct V_162 * ) V_170 ;
F_131 ( V_65 , V_163 , type ) ;
if ( type == V_155 ) {
struct V_150 * V_173 ;
V_173 = (struct V_150 * ) ( & V_163 -> V_32 ) ;
F_108 ( V_65 , V_173 , V_146 ) ;
F_109 ( V_65 , V_173 , V_108 ) ;
F_110 ( V_65 , V_173 , V_32 ) ;
F_111 ( V_65 , V_173 , V_157 ) ;
} else if ( type == V_154 ) {
struct V_158 * V_179 ;
V_179 = (struct V_158 * ) ( V_163 + 1 ) ;
F_106 ( V_65 , V_179 , V_157 ) ;
F_132 ( V_65 , V_163 , V_17 ) ;
} else if ( type == V_164 ) {
F_132 ( V_65 , V_163 , V_17 ) ;
} else {
F_132 ( V_65 , V_163 , V_146 ) ;
}
F_94 ( V_65 ) ;
return 0 ;
}
static int F_133 ( struct V_83 * V_84 ,
struct V_33 * V_34 ,
struct V_62 * V_63 ,
struct V_162 * * V_168 ,
T_2 V_26 , T_2 V_35 , T_2 V_17 ,
T_2 V_146 , T_2 V_108 , T_2 V_32 )
{
int V_28 ;
V_28 = F_123 ( V_84 , V_34 , V_63 , V_168 ,
V_26 , V_35 , V_17 ,
V_146 , V_108 , V_32 , 0 ) ;
if ( V_28 != - V_153 )
return V_28 ;
F_43 ( V_63 ) ;
* V_168 = NULL ;
if ( V_108 < V_143 ) {
V_28 = F_119 ( V_84 , V_34 , V_63 , V_26 , V_17 ,
V_146 ) ;
} else {
V_28 = F_103 ( V_84 , V_34 , V_63 , V_26 , V_17 ,
V_146 , V_108 , V_32 ) ;
}
return V_28 ;
}
static T_5
int F_134 ( struct V_83 * V_84 ,
struct V_33 * V_34 ,
struct V_62 * V_63 ,
struct V_162 * V_163 ,
int V_180 ,
struct V_177 * V_131 )
{
struct V_64 * V_65 ;
struct V_121 * V_122 ;
struct V_150 * V_173 = NULL ;
struct V_158 * V_179 = NULL ;
unsigned long V_170 ;
unsigned long V_30 ;
T_3 V_123 ;
int V_55 ;
int type ;
int V_28 ;
T_2 V_117 ;
V_65 = V_63 -> V_79 [ 0 ] ;
V_122 = F_77 ( V_65 , V_63 -> V_80 [ 0 ] , struct V_121 ) ;
V_117 = F_78 ( V_65 , V_122 ) ;
F_8 ( V_180 < 0 && V_117 + V_180 <= 0 ) ;
V_117 += V_180 ;
F_89 ( V_65 , V_122 , V_117 ) ;
if ( V_131 )
F_129 ( V_131 , V_65 , V_122 ) ;
type = F_118 ( V_65 , V_163 ) ;
if ( type == V_155 ) {
V_173 = (struct V_150 * ) ( & V_163 -> V_32 ) ;
V_117 = F_112 ( V_65 , V_173 ) ;
} else if ( type == V_154 ) {
V_179 = (struct V_158 * ) ( V_163 + 1 ) ;
V_117 = F_107 ( V_65 , V_179 ) ;
} else {
V_117 = 1 ;
F_22 ( V_180 != - 1 ) ;
}
F_22 ( V_180 < 0 && V_117 < - V_180 ) ;
V_117 += V_180 ;
if ( V_117 > 0 ) {
if ( type == V_155 )
F_111 ( V_65 , V_173 , V_117 ) ;
else
F_106 ( V_65 , V_179 , V_117 ) ;
} else {
V_55 = F_124 ( type ) ;
V_123 = F_76 ( V_65 , V_63 -> V_80 [ 0 ] ) ;
V_170 = ( unsigned long ) V_163 ;
V_30 = ( unsigned long ) V_122 + V_123 ;
if ( V_170 + V_55 < V_30 )
F_130 ( V_65 , V_170 , V_170 + V_55 ,
V_30 - V_170 - V_55 ) ;
V_123 -= V_55 ;
V_28 = F_135 ( V_84 , V_34 , V_63 , V_123 , 1 ) ;
}
F_94 ( V_65 ) ;
return 0 ;
}
static T_5
int F_136 ( struct V_83 * V_84 ,
struct V_33 * V_34 ,
struct V_62 * V_63 ,
T_2 V_26 , T_2 V_35 , T_2 V_17 ,
T_2 V_146 , T_2 V_108 ,
T_2 V_32 , int V_157 ,
struct V_177 * V_131 )
{
struct V_162 * V_163 ;
int V_28 ;
V_28 = F_123 ( V_84 , V_34 , V_63 , & V_163 ,
V_26 , V_35 , V_17 ,
V_146 , V_108 , V_32 , 1 ) ;
if ( V_28 == 0 ) {
F_22 ( V_108 < V_143 ) ;
V_28 = F_134 ( V_84 , V_34 , V_63 , V_163 ,
V_157 , V_131 ) ;
} else if ( V_28 == - V_153 ) {
V_28 = F_128 ( V_84 , V_34 , V_63 , V_163 ,
V_17 , V_146 ,
V_108 , V_32 , V_157 ,
V_131 ) ;
}
return V_28 ;
}
static int F_137 ( struct V_83 * V_84 ,
struct V_33 * V_34 ,
struct V_62 * V_63 ,
T_2 V_26 , T_2 V_17 , T_2 V_146 ,
T_2 V_108 , T_2 V_32 , int V_157 )
{
int V_28 ;
if ( V_108 < V_143 ) {
F_22 ( V_157 != 1 ) ;
V_28 = F_120 ( V_84 , V_34 , V_63 , V_26 ,
V_17 , V_146 ) ;
} else {
V_28 = F_104 ( V_84 , V_34 , V_63 , V_26 ,
V_17 , V_146 ,
V_108 , V_32 , V_157 ) ;
}
return V_28 ;
}
static int F_138 ( struct V_83 * V_84 ,
struct V_33 * V_34 ,
struct V_62 * V_63 ,
struct V_162 * V_163 ,
int V_159 , int V_181 )
{
int V_28 ;
F_22 ( ! V_181 && V_159 != 1 ) ;
if ( V_163 ) {
V_28 = F_134 ( V_84 , V_34 , V_63 , V_163 ,
- V_159 , NULL ) ;
} else if ( V_181 ) {
V_28 = F_113 ( V_84 , V_34 , V_63 , V_159 ) ;
} else {
V_28 = F_115 ( V_84 , V_34 , V_63 ) ;
}
return V_28 ;
}
static int F_139 ( struct V_182 * V_183 ,
T_2 V_31 , T_2 V_115 )
{
return F_140 ( V_183 , V_31 >> 9 , V_115 >> 9 , V_39 , 0 ) ;
}
static int F_141 ( struct V_33 * V_34 , T_2 V_26 ,
T_2 V_35 , T_2 * V_184 )
{
int V_28 ;
T_2 V_185 = 0 ;
struct V_186 * V_187 = NULL ;
V_28 = F_142 ( & V_34 -> V_36 -> V_47 , V_188 ,
V_26 , & V_35 , & V_187 , 0 ) ;
if ( ! V_28 ) {
struct V_189 * V_190 = V_187 -> V_191 ;
int V_42 ;
for ( V_42 = 0 ; V_42 < V_187 -> V_192 ; V_42 ++ , V_190 ++ ) {
if ( ! V_190 -> V_193 -> V_194 )
continue;
V_28 = F_139 ( V_190 -> V_193 -> V_183 ,
V_190 -> V_195 ,
V_190 -> V_196 ) ;
if ( ! V_28 )
V_185 += V_190 -> V_196 ;
else if ( V_28 != - V_197 )
break;
V_28 = 0 ;
}
F_9 ( V_187 ) ;
}
if ( V_184 )
* V_184 = V_185 ;
return V_28 ;
}
int F_143 ( struct V_83 * V_84 ,
struct V_33 * V_34 ,
T_2 V_26 , T_2 V_35 , T_2 V_17 ,
T_2 V_146 , T_2 V_108 , T_2 V_32 )
{
int V_28 ;
F_22 ( V_108 < V_143 &&
V_146 == V_198 ) ;
if ( V_108 < V_143 ) {
V_28 = F_144 ( V_84 , V_26 , V_35 ,
V_17 , V_146 , ( int ) V_108 ,
V_199 , NULL ) ;
} else {
V_28 = F_145 ( V_84 , V_26 , V_35 ,
V_17 , V_146 , V_108 , V_32 ,
V_199 , NULL ) ;
}
return V_28 ;
}
static int F_146 ( struct V_83 * V_84 ,
struct V_33 * V_34 ,
T_2 V_26 , T_2 V_35 ,
T_2 V_17 , T_2 V_146 ,
T_2 V_108 , T_2 V_32 , int V_157 ,
struct V_177 * V_131 )
{
struct V_62 * V_63 ;
struct V_64 * V_65 ;
struct V_121 * V_113 ;
T_2 V_117 ;
int V_28 ;
int V_78 = 0 ;
V_63 = F_32 () ;
if ( ! V_63 )
return - V_116 ;
V_63 -> V_73 = 1 ;
V_63 -> V_200 = 1 ;
V_28 = F_136 ( V_84 , V_34 -> V_36 -> V_61 ,
V_63 , V_26 , V_35 , V_17 ,
V_146 , V_108 , V_32 ,
V_157 , V_131 ) ;
if ( V_28 == 0 )
goto V_70;
if ( V_28 != - V_175 ) {
V_78 = V_28 ;
goto V_70;
}
V_65 = V_63 -> V_79 [ 0 ] ;
V_113 = F_77 ( V_65 , V_63 -> V_80 [ 0 ] , struct V_121 ) ;
V_117 = F_78 ( V_65 , V_113 ) ;
F_89 ( V_65 , V_113 , V_117 + V_157 ) ;
if ( V_131 )
F_129 ( V_131 , V_65 , V_113 ) ;
F_94 ( V_65 ) ;
F_43 ( V_63 ) ;
V_63 -> V_73 = 1 ;
V_63 -> V_200 = 1 ;
V_28 = F_137 ( V_84 , V_34 -> V_36 -> V_61 ,
V_63 , V_26 , V_17 , V_146 ,
V_108 , V_32 , V_157 ) ;
F_22 ( V_28 ) ;
V_70:
F_48 ( V_63 ) ;
return V_78 ;
}
static int F_147 ( struct V_83 * V_84 ,
struct V_33 * V_34 ,
struct V_201 * V_130 ,
struct V_177 * V_131 ,
int V_202 )
{
int V_28 = 0 ;
struct V_203 * V_151 ;
struct V_66 V_204 ;
T_2 V_17 = 0 ;
T_2 V_205 = 0 ;
T_2 V_6 = 0 ;
V_204 . V_22 = V_130 -> V_26 ;
V_204 . V_32 = V_130 -> V_35 ;
V_204 . type = V_74 ;
V_151 = F_148 ( V_130 ) ;
if ( V_130 -> type == V_154 )
V_17 = V_151 -> V_17 ;
else
V_205 = V_151 -> V_34 ;
if ( V_130 -> V_206 == V_199 && V_202 ) {
if ( V_131 ) {
F_22 ( V_131 -> V_207 ) ;
V_6 |= V_131 -> V_133 ;
}
V_28 = F_149 ( V_84 , V_34 ,
V_17 , V_205 , V_6 ,
V_151 -> V_22 , V_151 -> V_32 ,
& V_204 , V_130 -> V_134 ) ;
} else if ( V_130 -> V_206 == V_199 ) {
V_28 = F_146 ( V_84 , V_34 , V_130 -> V_26 ,
V_130 -> V_35 , V_17 ,
V_205 , V_151 -> V_22 ,
V_151 -> V_32 , V_130 -> V_134 ,
V_131 ) ;
} else if ( V_130 -> V_206 == V_208 ) {
V_28 = F_150 ( V_84 , V_34 , V_130 -> V_26 ,
V_130 -> V_35 , V_17 ,
V_205 , V_151 -> V_22 ,
V_151 -> V_32 , V_130 -> V_134 ,
V_131 ) ;
} else {
F_82 () ;
}
return V_28 ;
}
static void F_129 ( struct V_177 * V_131 ,
struct V_64 * V_65 ,
struct V_121 * V_122 )
{
T_2 V_6 = F_79 ( V_65 , V_122 ) ;
if ( V_131 -> V_132 ) {
V_6 |= V_131 -> V_133 ;
F_91 ( V_65 , V_122 , V_6 ) ;
}
if ( V_131 -> V_207 ) {
struct V_138 * V_139 ;
F_22 ( ! ( V_6 & V_144 ) ) ;
V_139 = (struct V_138 * ) ( V_122 + 1 ) ;
F_151 ( V_65 , V_139 , & V_131 -> V_21 ) ;
}
}
static int F_152 ( struct V_83 * V_84 ,
struct V_33 * V_34 ,
struct V_201 * V_130 ,
struct V_177 * V_131 )
{
struct V_66 V_21 ;
struct V_62 * V_63 ;
struct V_121 * V_122 ;
struct V_64 * V_65 ;
T_3 V_123 ;
int V_28 ;
int V_78 = 0 ;
V_63 = F_32 () ;
if ( ! V_63 )
return - V_116 ;
V_21 . V_22 = V_130 -> V_26 ;
V_21 . type = V_74 ;
V_21 . V_32 = V_130 -> V_35 ;
V_63 -> V_73 = 1 ;
V_63 -> V_200 = 1 ;
V_28 = F_36 ( V_84 , V_34 -> V_36 -> V_61 , & V_21 ,
V_63 , 0 , 1 ) ;
if ( V_28 < 0 ) {
V_78 = V_28 ;
goto V_70;
}
if ( V_28 > 0 ) {
V_78 = - V_209 ;
goto V_70;
}
V_65 = V_63 -> V_79 [ 0 ] ;
V_123 = F_76 ( V_65 , V_63 -> V_80 [ 0 ] ) ;
#ifdef F_80
if ( V_123 < sizeof( * V_122 ) ) {
V_28 = F_86 ( V_84 , V_34 -> V_36 -> V_61 ,
V_63 , ( T_2 ) - 1 , 0 ) ;
if ( V_28 < 0 ) {
V_78 = V_28 ;
goto V_70;
}
V_65 = V_63 -> V_79 [ 0 ] ;
V_123 = F_76 ( V_65 , V_63 -> V_80 [ 0 ] ) ;
}
#endif
F_22 ( V_123 < sizeof( * V_122 ) ) ;
V_122 = F_77 ( V_65 , V_63 -> V_80 [ 0 ] , struct V_121 ) ;
F_129 ( V_131 , V_65 , V_122 ) ;
F_94 ( V_65 ) ;
V_70:
F_48 ( V_63 ) ;
return V_78 ;
}
static int F_153 ( struct V_83 * V_84 ,
struct V_33 * V_34 ,
struct V_201 * V_130 ,
struct V_177 * V_131 ,
int V_202 )
{
int V_28 = 0 ;
struct V_210 * V_151 ;
struct V_66 V_204 ;
T_2 V_17 = 0 ;
T_2 V_205 = 0 ;
V_204 . V_22 = V_130 -> V_26 ;
V_204 . V_32 = V_130 -> V_35 ;
V_204 . type = V_74 ;
V_151 = F_154 ( V_130 ) ;
if ( V_130 -> type == V_164 )
V_17 = V_151 -> V_17 ;
else
V_205 = V_151 -> V_34 ;
F_22 ( V_130 -> V_134 != 1 ) ;
if ( V_130 -> V_206 == V_199 && V_202 ) {
F_22 ( ! V_131 || ! V_131 -> V_132 ||
! V_131 -> V_207 ) ;
V_28 = F_155 ( V_84 , V_34 ,
V_17 , V_205 ,
V_131 -> V_133 ,
& V_131 -> V_21 ,
V_151 -> V_166 , & V_204 ) ;
} else if ( V_130 -> V_206 == V_199 ) {
V_28 = F_146 ( V_84 , V_34 , V_130 -> V_26 ,
V_130 -> V_35 , V_17 , V_205 ,
V_151 -> V_166 , 0 , 1 , V_131 ) ;
} else if ( V_130 -> V_206 == V_208 ) {
V_28 = F_150 ( V_84 , V_34 , V_130 -> V_26 ,
V_130 -> V_35 , V_17 , V_205 ,
V_151 -> V_166 , 0 , 1 , V_131 ) ;
} else {
F_82 () ;
}
return V_28 ;
}
static int F_156 ( struct V_83 * V_84 ,
struct V_33 * V_34 ,
struct V_201 * V_130 ,
struct V_177 * V_131 ,
int V_202 )
{
int V_28 ;
if ( F_157 ( V_130 ) ) {
struct V_118 * V_97 ;
F_22 ( V_131 ) ;
V_97 = F_158 ( V_130 ) ;
if ( V_202 ) {
F_159 ( V_34 , V_130 -> V_26 ,
V_130 -> V_35 , 1 ) ;
if ( V_97 -> V_181 ) {
V_28 = F_160 ( V_84 , V_34 ,
V_130 -> V_26 ,
V_130 -> V_35 ) ;
F_22 ( V_28 ) ;
}
}
F_45 ( & V_97 -> V_76 ) ;
return 0 ;
}
if ( V_130 -> type == V_165 ||
V_130 -> type == V_164 )
V_28 = F_153 ( V_84 , V_34 , V_130 , V_131 ,
V_202 ) ;
else if ( V_130 -> type == V_155 ||
V_130 -> type == V_154 )
V_28 = F_147 ( V_84 , V_34 , V_130 , V_131 ,
V_202 ) ;
else
F_82 () ;
return V_28 ;
}
T_1 int F_161 ( struct V_83 * V_84 ,
struct V_33 * V_34 ,
struct V_96 * V_211 )
{
struct V_119 * V_120 ;
struct V_201 * V_151 ;
struct V_118 * V_212 = NULL ;
struct V_177 * V_131 ;
int V_28 ;
int V_7 = 0 ;
int V_213 = 0 ;
V_120 = & V_84 -> V_87 -> V_120 ;
while ( 1 ) {
if ( ! V_212 ) {
if ( F_162 ( V_211 ) )
break;
V_212 = F_163 ( V_211 -> V_214 ,
struct V_118 , V_211 ) ;
V_28 = F_164 ( V_84 , V_212 ) ;
if ( V_28 == - V_175 ) {
V_212 = NULL ;
V_7 ++ ;
continue;
}
}
V_213 = V_212 -> V_213 ;
V_212 -> V_213 = 0 ;
V_131 = V_212 -> V_131 ;
V_212 -> V_131 = NULL ;
V_151 = F_165 ( V_212 ) ;
if ( ! V_151 ) {
V_151 = & V_212 -> V_130 ;
if ( V_131 && V_213 ) {
F_9 ( V_131 ) ;
V_131 = NULL ;
}
if ( V_131 ) {
F_13 ( & V_120 -> V_50 ) ;
V_28 = F_152 ( V_84 , V_34 ,
V_151 , V_131 ) ;
F_22 ( V_28 ) ;
F_9 ( V_131 ) ;
F_46 () ;
F_11 ( & V_120 -> V_50 ) ;
continue;
}
F_166 ( & V_212 -> V_211 ) ;
V_212 = NULL ;
}
V_151 -> V_215 = 0 ;
F_167 ( & V_151 -> V_15 , & V_120 -> V_34 ) ;
V_120 -> V_216 -- ;
F_13 ( & V_120 -> V_50 ) ;
V_28 = F_156 ( V_84 , V_34 , V_151 , V_131 ,
V_213 ) ;
F_22 ( V_28 ) ;
F_85 ( V_151 ) ;
F_9 ( V_131 ) ;
V_7 ++ ;
F_46 () ;
F_11 ( & V_120 -> V_50 ) ;
}
return V_7 ;
}
int F_168 ( struct V_83 * V_84 ,
struct V_33 * V_34 , unsigned long V_7 )
{
struct V_15 * V_130 ;
struct V_119 * V_120 ;
struct V_201 * V_151 ;
struct V_96 V_211 ;
int V_28 ;
int V_217 = V_7 == ( unsigned long ) - 1 ;
int V_218 = 0 ;
if ( V_34 == V_34 -> V_36 -> V_61 )
V_34 = V_34 -> V_36 -> V_89 ;
V_120 = & V_84 -> V_87 -> V_120 ;
F_52 ( & V_211 ) ;
V_75:
F_11 ( & V_120 -> V_50 ) ;
if ( V_7 == 0 ) {
V_7 = V_120 -> V_216 * 2 ;
V_218 = 1 ;
}
while ( 1 ) {
if ( ! ( V_217 || V_218 ) &&
V_120 -> V_219 < 64 )
break;
V_28 = F_169 ( V_84 , & V_211 ,
V_120 -> V_220 ) ;
if ( V_28 )
break;
V_28 = F_161 ( V_84 , V_34 , & V_211 ) ;
F_22 ( V_28 < 0 ) ;
V_7 -= F_170 (unsigned long, ret, count) ;
if ( V_7 == 0 )
break;
}
if ( V_217 ) {
V_130 = F_171 ( & V_120 -> V_34 ) ;
if ( ! V_130 )
goto V_70;
V_7 = ( unsigned long ) - 1 ;
while ( V_130 ) {
V_151 = F_12 ( V_130 , struct V_201 ,
V_15 ) ;
if ( F_157 ( V_151 ) ) {
struct V_118 * V_97 ;
V_97 = F_158 ( V_151 ) ;
F_5 ( & V_151 -> V_117 ) ;
F_13 ( & V_120 -> V_50 ) ;
F_34 ( & V_97 -> V_76 ) ;
F_45 ( & V_97 -> V_76 ) ;
F_85 ( V_151 ) ;
F_46 () ;
goto V_75;
}
V_130 = F_172 ( V_130 ) ;
}
F_13 ( & V_120 -> V_50 ) ;
F_173 ( 1 ) ;
goto V_75;
}
V_70:
F_13 ( & V_120 -> V_50 ) ;
return 0 ;
}
int F_174 ( struct V_83 * V_84 ,
struct V_33 * V_34 ,
T_2 V_26 , T_2 V_35 , T_2 V_6 ,
int V_181 )
{
struct V_177 * V_131 ;
int V_28 ;
V_131 = F_175 ( sizeof( * V_131 ) , V_39 ) ;
if ( ! V_131 )
return - V_116 ;
V_131 -> V_133 = V_6 ;
V_131 -> V_132 = 1 ;
V_131 -> V_207 = 0 ;
V_131 -> V_181 = V_181 ? 1 : 0 ;
V_28 = F_176 ( V_84 , V_26 , V_35 , V_131 ) ;
if ( V_28 )
F_9 ( V_131 ) ;
return V_28 ;
}
static T_1 int F_177 ( struct V_83 * V_84 ,
struct V_33 * V_34 ,
struct V_62 * V_63 ,
T_2 V_22 , T_2 V_32 , T_2 V_26 )
{
struct V_118 * V_97 ;
struct V_201 * V_151 ;
struct V_203 * V_221 ;
struct V_119 * V_120 ;
struct V_15 * V_130 ;
int V_28 = 0 ;
V_28 = - V_153 ;
V_120 = & V_84 -> V_87 -> V_120 ;
F_11 ( & V_120 -> V_50 ) ;
V_97 = F_83 ( V_84 , V_26 ) ;
if ( ! V_97 )
goto V_70;
if ( ! F_84 ( & V_97 -> V_76 ) ) {
F_5 ( & V_97 -> V_130 . V_117 ) ;
F_13 ( & V_120 -> V_50 ) ;
F_43 ( V_63 ) ;
F_34 ( & V_97 -> V_76 ) ;
F_45 ( & V_97 -> V_76 ) ;
F_85 ( & V_97 -> V_130 ) ;
return - V_175 ;
}
V_130 = F_178 ( & V_97 -> V_130 . V_15 ) ;
if ( ! V_130 )
goto V_222;
V_151 = F_12 ( V_130 , struct V_201 , V_15 ) ;
if ( V_151 -> V_26 != V_26 )
goto V_222;
V_28 = 1 ;
if ( V_151 -> type != V_155 )
goto V_222;
V_221 = F_148 ( V_151 ) ;
V_130 = F_178 ( V_130 ) ;
if ( V_130 ) {
V_151 = F_12 ( V_130 , struct V_201 , V_15 ) ;
if ( V_151 -> V_26 == V_26 )
goto V_222;
}
if ( V_221 -> V_34 != V_34 -> V_223 . V_22 ||
V_221 -> V_22 != V_22 || V_221 -> V_32 != V_32 )
goto V_222;
V_28 = 0 ;
V_222:
F_45 ( & V_97 -> V_76 ) ;
V_70:
F_13 ( & V_120 -> V_50 ) ;
return V_28 ;
}
static T_1 int F_179 ( struct V_83 * V_84 ,
struct V_33 * V_34 ,
struct V_62 * V_63 ,
T_2 V_22 , T_2 V_32 , T_2 V_26 )
{
struct V_33 * V_61 = V_34 -> V_36 -> V_61 ;
struct V_64 * V_65 ;
struct V_150 * V_151 ;
struct V_162 * V_163 ;
struct V_121 * V_122 ;
struct V_66 V_21 ;
T_3 V_123 ;
int V_28 ;
V_21 . V_22 = V_26 ;
V_21 . V_32 = ( T_2 ) - 1 ;
V_21 . type = V_74 ;
V_28 = F_36 ( NULL , V_61 , & V_21 , V_63 , 0 , 0 ) ;
if ( V_28 < 0 )
goto V_70;
F_22 ( V_28 == 0 ) ;
V_28 = - V_153 ;
if ( V_63 -> V_80 [ 0 ] == 0 )
goto V_70;
V_63 -> V_80 [ 0 ] -- ;
V_65 = V_63 -> V_79 [ 0 ] ;
F_39 ( V_65 , & V_21 , V_63 -> V_80 [ 0 ] ) ;
if ( V_21 . V_22 != V_26 || V_21 . type != V_74 )
goto V_70;
V_28 = 1 ;
V_123 = F_76 ( V_65 , V_63 -> V_80 [ 0 ] ) ;
#ifdef F_80
if ( V_123 < sizeof( * V_122 ) ) {
F_8 ( V_123 != sizeof( struct V_127 ) ) ;
goto V_70;
}
#endif
V_122 = F_77 ( V_65 , V_63 -> V_80 [ 0 ] , struct V_121 ) ;
if ( V_123 != sizeof( * V_122 ) +
F_124 ( V_155 ) )
goto V_70;
if ( F_180 ( V_65 , V_122 ) <=
F_181 ( & V_34 -> V_224 ) )
goto V_70;
V_163 = (struct V_162 * ) ( V_122 + 1 ) ;
if ( F_118 ( V_65 , V_163 ) !=
V_155 )
goto V_70;
V_151 = (struct V_150 * ) ( & V_163 -> V_32 ) ;
if ( F_78 ( V_65 , V_122 ) !=
F_112 ( V_65 , V_151 ) ||
F_99 ( V_65 , V_151 ) !=
V_34 -> V_223 . V_22 ||
F_100 ( V_65 , V_151 ) != V_22 ||
F_101 ( V_65 , V_151 ) != V_32 )
goto V_70;
V_28 = 0 ;
V_70:
return V_28 ;
}
int F_182 ( struct V_83 * V_84 ,
struct V_33 * V_34 ,
T_2 V_22 , T_2 V_32 , T_2 V_26 )
{
struct V_62 * V_63 ;
int V_28 ;
int V_225 ;
V_63 = F_32 () ;
if ( ! V_63 )
return - V_153 ;
do {
V_28 = F_179 ( V_84 , V_34 , V_63 , V_22 ,
V_32 , V_26 ) ;
if ( V_28 && V_28 != - V_153 )
goto V_70;
V_225 = F_177 ( V_84 , V_34 , V_63 , V_22 ,
V_32 , V_26 ) ;
} while ( V_225 == - V_175 );
if ( V_225 && V_225 != - V_153 ) {
V_28 = V_225 ;
goto V_70;
}
if ( V_28 != - V_153 || V_225 != - V_153 )
V_28 = 0 ;
V_70:
F_48 ( V_63 ) ;
if ( V_34 -> V_223 . V_22 == V_226 )
F_8 ( V_28 > 0 ) ;
return V_28 ;
}
static int F_183 ( struct V_83 * V_84 ,
struct V_33 * V_34 ,
struct V_64 * V_227 ,
int V_228 , int V_229 )
{
T_2 V_26 ;
T_2 V_35 ;
T_2 V_17 ;
T_2 V_205 ;
T_3 V_69 ;
struct V_66 V_21 ;
struct V_230 * V_231 ;
int V_42 ;
int V_166 ;
int V_28 = 0 ;
int (* F_184)( struct V_83 * , struct V_33 * ,
T_2 , T_2 , T_2 , T_2 , T_2 , T_2 );
V_205 = F_185 ( V_227 ) ;
V_69 = F_37 ( V_227 ) ;
V_166 = F_186 ( V_227 ) ;
if ( ! V_34 -> V_232 && V_166 == 0 )
return 0 ;
if ( V_229 )
F_184 = F_143 ;
else
F_184 = V_233 ;
if ( V_228 )
V_17 = V_227 -> V_31 ;
else
V_17 = 0 ;
for ( V_42 = 0 ; V_42 < V_69 ; V_42 ++ ) {
if ( V_166 == 0 ) {
F_39 ( V_227 , & V_21 , V_42 ) ;
if ( F_187 ( & V_21 ) != V_234 )
continue;
V_231 = F_77 ( V_227 , V_42 ,
struct V_230 ) ;
if ( F_188 ( V_227 , V_231 ) ==
V_235 )
continue;
V_26 = F_189 ( V_227 , V_231 ) ;
if ( V_26 == 0 )
continue;
V_35 = F_190 ( V_227 , V_231 ) ;
V_21 . V_32 -= F_191 ( V_227 , V_231 ) ;
V_28 = F_184 ( V_84 , V_34 , V_26 , V_35 ,
V_17 , V_205 , V_21 . V_22 ,
V_21 . V_32 ) ;
if ( V_28 )
goto V_156;
} else {
V_26 = F_192 ( V_227 , V_42 ) ;
V_35 = F_193 ( V_34 , V_166 - 1 ) ;
V_28 = F_184 ( V_84 , V_34 , V_26 , V_35 ,
V_17 , V_205 , V_166 - 1 , 0 ) ;
if ( V_28 )
goto V_156;
}
}
return 0 ;
V_156:
F_82 () ;
return V_28 ;
}
int F_194 ( struct V_83 * V_84 , struct V_33 * V_34 ,
struct V_64 * V_227 , int V_228 )
{
return F_183 ( V_84 , V_34 , V_227 , V_228 , 1 ) ;
}
int F_195 ( struct V_83 * V_84 , struct V_33 * V_34 ,
struct V_64 * V_227 , int V_228 )
{
return F_183 ( V_84 , V_34 , V_227 , V_228 , 0 ) ;
}
static int F_196 ( struct V_83 * V_84 ,
struct V_33 * V_34 ,
struct V_62 * V_63 ,
struct V_1 * V_2 )
{
int V_28 ;
struct V_33 * V_61 = V_34 -> V_36 -> V_61 ;
unsigned long V_139 ;
struct V_64 * V_65 ;
V_28 = F_36 ( V_84 , V_61 , & V_2 -> V_21 , V_63 , 0 , 1 ) ;
if ( V_28 < 0 )
goto V_156;
F_22 ( V_28 ) ;
V_65 = V_63 -> V_79 [ 0 ] ;
V_139 = F_197 ( V_65 , V_63 -> V_80 [ 0 ] ) ;
F_198 ( V_65 , & V_2 -> V_113 , V_139 , sizeof( V_2 -> V_113 ) ) ;
F_94 ( V_65 ) ;
F_43 ( V_63 ) ;
V_156:
if ( V_28 )
return V_28 ;
return 0 ;
}
static struct V_1 *
F_199 ( struct V_33 * V_34 ,
struct V_1 * V_2 )
{
struct V_15 * V_130 ;
F_11 ( & V_34 -> V_36 -> V_18 ) ;
V_130 = F_172 ( & V_2 -> V_20 ) ;
F_6 ( V_2 ) ;
if ( V_130 ) {
V_2 = F_12 ( V_130 , struct V_1 ,
V_20 ) ;
F_4 ( V_2 ) ;
} else
V_2 = NULL ;
F_13 ( & V_34 -> V_36 -> V_18 ) ;
return V_2 ;
}
static int F_200 ( struct V_1 * V_14 ,
struct V_83 * V_84 ,
struct V_62 * V_63 )
{
struct V_33 * V_34 = V_14 -> V_36 -> V_89 ;
struct V_236 * V_236 = NULL ;
T_2 V_237 = 0 ;
int V_238 = V_239 ;
int V_240 = 0 ;
int V_241 = 0 ;
int V_28 = 0 ;
if ( V_14 -> V_21 . V_32 < ( 100 * 1024 * 1024 ) ) {
F_11 ( & V_14 -> V_50 ) ;
V_14 -> V_242 = V_243 ;
F_13 ( & V_14 -> V_50 ) ;
return 0 ;
}
V_75:
V_236 = F_201 ( V_34 , V_14 , V_63 ) ;
if ( F_202 ( V_236 ) && F_203 ( V_236 ) != - V_153 ) {
V_28 = F_203 ( V_236 ) ;
F_43 ( V_63 ) ;
goto V_70;
}
if ( F_202 ( V_236 ) ) {
F_22 ( V_241 ) ;
V_241 ++ ;
if ( V_14 -> V_114 )
goto V_126;
V_28 = F_204 ( V_34 , V_84 , V_14 , V_63 ) ;
if ( V_28 )
goto V_126;
goto V_75;
}
F_205 ( V_236 ) -> V_244 = 0 ;
V_28 = F_206 ( V_84 , V_34 , V_236 ) ;
F_8 ( V_28 ) ;
if ( F_207 ( V_236 ) > 0 ) {
V_28 = F_208 ( V_34 , V_84 , V_63 ,
V_236 ) ;
if ( V_28 )
goto V_245;
}
F_11 ( & V_14 -> V_50 ) ;
if ( V_14 -> V_3 != V_4 ) {
V_238 = V_243 ;
F_13 ( & V_14 -> V_50 ) ;
goto V_245;
}
F_13 ( & V_14 -> V_50 ) ;
V_240 = ( int ) F_209 ( V_14 -> V_21 . V_32 , 1024 * 1024 * 1024 ) ;
if ( ! V_240 )
V_240 = 1 ;
V_240 *= 16 ;
V_240 *= V_246 ;
V_28 = F_210 ( V_236 , V_240 ) ;
if ( V_28 )
goto V_245;
V_28 = F_211 ( V_236 , V_84 , 0 , 0 , V_240 ,
V_240 , V_240 ,
& V_237 ) ;
if ( ! V_28 )
V_238 = V_247 ;
F_212 ( V_236 , V_240 ) ;
V_245:
F_213 ( V_236 ) ;
V_126:
F_43 ( V_63 ) ;
V_70:
F_11 ( & V_14 -> V_50 ) ;
V_14 -> V_242 = V_238 ;
F_13 ( & V_14 -> V_50 ) ;
return V_28 ;
}
int F_214 ( struct V_83 * V_84 ,
struct V_33 * V_34 )
{
struct V_1 * V_2 ;
int V_78 = 0 ;
struct V_62 * V_63 ;
T_2 V_68 = 0 ;
V_63 = F_32 () ;
if ( ! V_63 )
return - V_116 ;
V_75:
while ( 1 ) {
V_2 = F_60 ( V_34 -> V_36 , V_68 ) ;
while ( V_2 ) {
if ( V_2 -> V_242 == V_248 )
break;
V_2 = F_199 ( V_34 , V_2 ) ;
}
if ( ! V_2 ) {
if ( V_68 == 0 )
break;
V_68 = 0 ;
continue;
}
V_78 = F_200 ( V_2 , V_84 , V_63 ) ;
V_68 = V_2 -> V_21 . V_22 + V_2 -> V_21 . V_32 ;
F_6 ( V_2 ) ;
}
while ( 1 ) {
if ( V_68 == 0 ) {
V_78 = F_168 ( V_84 , V_34 ,
( unsigned long ) - 1 ) ;
F_22 ( V_78 ) ;
}
V_2 = F_60 ( V_34 -> V_36 , V_68 ) ;
while ( V_2 ) {
if ( V_2 -> V_242 == V_248 ) {
F_6 ( V_2 ) ;
goto V_75;
}
if ( V_2 -> V_249 )
break;
V_2 = F_199 ( V_34 , V_2 ) ;
}
if ( ! V_2 ) {
if ( V_68 == 0 )
break;
V_68 = 0 ;
continue;
}
if ( V_2 -> V_242 == V_247 )
V_2 -> V_242 = V_250 ;
V_2 -> V_249 = 0 ;
V_68 = V_2 -> V_21 . V_22 + V_2 -> V_21 . V_32 ;
V_78 = F_196 ( V_84 , V_34 , V_63 , V_2 ) ;
F_22 ( V_78 ) ;
F_6 ( V_2 ) ;
}
while ( 1 ) {
if ( V_68 == 0 ) {
V_78 = F_168 ( V_84 , V_34 ,
( unsigned long ) - 1 ) ;
F_22 ( V_78 ) ;
}
V_2 = F_60 ( V_34 -> V_36 , V_68 ) ;
while ( V_2 ) {
if ( V_2 -> V_249 ) {
F_6 ( V_2 ) ;
goto V_75;
}
if ( V_2 -> V_242 == V_250 )
break;
V_2 = F_199 ( V_34 , V_2 ) ;
}
if ( ! V_2 ) {
if ( V_68 == 0 )
break;
V_68 = 0 ;
continue;
}
F_215 ( V_34 , V_84 , V_2 , V_63 ) ;
if ( V_2 -> V_242 == V_250 )
V_2 -> V_242 = V_243 ;
V_68 = V_2 -> V_21 . V_22 + V_2 -> V_21 . V_32 ;
F_6 ( V_2 ) ;
}
F_48 ( V_63 ) ;
return 0 ;
}
int F_216 ( struct V_33 * V_34 , T_2 V_26 )
{
struct V_1 * V_14 ;
int V_251 = 0 ;
V_14 = F_61 ( V_34 -> V_36 , V_26 ) ;
if ( ! V_14 || V_14 -> V_114 )
V_251 = 1 ;
if ( V_14 )
F_6 ( V_14 ) ;
return V_251 ;
}
static int F_217 ( struct V_12 * V_13 , T_2 V_6 ,
T_2 V_252 , T_2 V_253 ,
struct V_95 * * V_98 )
{
struct V_95 * V_99 ;
int V_42 ;
int V_105 ;
if ( V_6 & ( V_254 | V_255 |
V_256 ) )
V_105 = 2 ;
else
V_105 = 1 ;
V_99 = F_62 ( V_13 , V_6 ) ;
if ( V_99 ) {
F_11 ( & V_99 -> V_50 ) ;
V_99 -> V_252 += V_252 ;
V_99 -> V_257 += V_252 * V_105 ;
V_99 -> V_253 += V_253 ;
V_99 -> V_258 += V_253 * V_105 ;
V_99 -> V_103 = 0 ;
F_13 ( & V_99 -> V_50 ) ;
* V_98 = V_99 ;
return 0 ;
}
V_99 = F_51 ( sizeof( * V_99 ) , V_39 ) ;
if ( ! V_99 )
return - V_116 ;
for ( V_42 = 0 ; V_42 < V_259 ; V_42 ++ )
F_52 ( & V_99 -> V_260 [ V_42 ] ) ;
F_218 ( & V_99 -> V_261 ) ;
F_219 ( & V_99 -> V_50 ) ;
V_99 -> V_6 = V_6 & ( V_100 |
V_101 |
V_102 ) ;
V_99 -> V_252 = V_252 ;
V_99 -> V_257 = V_252 * V_105 ;
V_99 -> V_253 = V_253 ;
V_99 -> V_258 = V_253 * V_105 ;
V_99 -> V_262 = 0 ;
V_99 -> V_263 = 0 ;
V_99 -> V_264 = 0 ;
V_99 -> V_265 = 0 ;
V_99 -> V_103 = 0 ;
V_99 -> V_266 = V_267 ;
V_99 -> V_268 = 0 ;
V_99 -> V_269 = 0 ;
F_54 ( & V_99 -> V_82 ) ;
* V_98 = V_99 ;
F_220 ( & V_99 -> V_91 , & V_13 -> V_98 ) ;
return 0 ;
}
static void F_221 ( struct V_12 * V_36 , T_2 V_6 )
{
T_2 V_270 = V_6 & ( V_271 |
V_255 |
V_256 |
V_254 ) ;
if ( V_270 ) {
if ( V_6 & V_100 )
V_36 -> V_272 |= V_270 ;
if ( V_6 & V_102 )
V_36 -> V_273 |= V_270 ;
if ( V_6 & V_101 )
V_36 -> V_274 |= V_270 ;
}
}
T_2 F_222 ( struct V_33 * V_34 , T_2 V_6 )
{
T_2 V_275 = V_34 -> V_36 -> V_276 -> V_277 +
V_34 -> V_36 -> V_276 -> V_278 ;
if ( V_275 == 1 )
V_6 &= ~ ( V_255 | V_271 ) ;
if ( V_275 < 4 )
V_6 &= ~ V_256 ;
if ( ( V_6 & V_254 ) &&
( V_6 & ( V_255 |
V_256 ) ) ) {
V_6 &= ~ V_254 ;
}
if ( ( V_6 & V_255 ) &&
( V_6 & V_256 ) ) {
V_6 &= ~ V_255 ;
}
if ( ( V_6 & V_271 ) &&
( ( V_6 & V_255 ) |
( V_6 & V_256 ) |
( V_6 & V_254 ) ) )
V_6 &= ~ V_271 ;
return V_6 ;
}
static T_2 F_223 ( struct V_33 * V_34 , T_2 V_6 )
{
if ( V_6 & V_100 )
V_6 |= V_34 -> V_36 -> V_272 &
V_34 -> V_36 -> V_279 ;
else if ( V_6 & V_101 )
V_6 |= V_34 -> V_36 -> V_274 &
V_34 -> V_36 -> V_280 ;
else if ( V_6 & V_102 )
V_6 |= V_34 -> V_36 -> V_273 &
V_34 -> V_36 -> V_281 ;
return F_222 ( V_34 , V_6 ) ;
}
T_2 F_224 ( struct V_33 * V_34 , int V_282 )
{
T_2 V_6 ;
if ( V_282 )
V_6 = V_100 ;
else if ( V_34 == V_34 -> V_36 -> V_283 )
V_6 = V_101 ;
else
V_6 = V_102 ;
return F_223 ( V_34 , V_6 ) ;
}
void F_225 ( struct V_33 * V_34 , struct V_236 * V_236 )
{
F_205 ( V_236 ) -> V_98 = F_62 ( V_34 -> V_36 ,
V_100 ) ;
}
int F_210 ( struct V_236 * V_236 , T_2 V_284 )
{
struct V_95 * V_285 ;
struct V_33 * V_34 = F_205 ( V_236 ) -> V_34 ;
T_2 V_109 ;
int V_28 = 0 , V_286 = 0 , V_287 = 1 ;
V_284 = ( V_284 + V_34 -> V_288 - 1 ) & ~ ( ( T_2 ) V_34 -> V_288 - 1 ) ;
if ( V_34 == V_34 -> V_36 -> V_89 ||
F_205 ( V_236 ) -> V_289 . V_22 == V_290 ) {
V_287 = 0 ;
V_286 = 1 ;
}
V_285 = F_205 ( V_236 ) -> V_98 ;
if ( ! V_285 )
goto V_291;
V_75:
F_11 ( & V_285 -> V_50 ) ;
V_109 = V_285 -> V_253 + V_285 -> V_263 +
V_285 -> V_262 + V_285 -> V_264 +
V_285 -> V_265 ;
if ( V_109 + V_284 > V_285 -> V_252 ) {
struct V_83 * V_84 ;
if ( ! V_285 -> V_103 && V_287 ) {
T_2 V_292 ;
V_285 -> V_266 = V_293 ;
F_13 ( & V_285 -> V_50 ) ;
V_291:
V_292 = F_224 ( V_34 , 1 ) ;
V_84 = F_226 ( V_34 ) ;
if ( F_202 ( V_84 ) )
return F_203 ( V_84 ) ;
V_28 = F_227 ( V_84 , V_34 -> V_36 -> V_61 ,
V_284 + 2 * 1024 * 1024 ,
V_292 ,
V_267 ) ;
F_228 ( V_84 , V_34 ) ;
if ( V_28 < 0 ) {
if ( V_28 != - V_294 )
return V_28 ;
else
goto V_295;
}
if ( ! V_285 ) {
F_225 ( V_34 , V_236 ) ;
V_285 = F_205 ( V_236 ) -> V_98 ;
}
goto V_75;
}
if ( V_285 -> V_262 < V_284 )
V_286 = 1 ;
F_13 ( & V_285 -> V_50 ) ;
V_295:
if ( ! V_286 &&
! F_229 ( & V_34 -> V_36 -> V_296 ) ) {
V_286 = 1 ;
V_84 = F_226 ( V_34 ) ;
if ( F_202 ( V_84 ) )
return F_203 ( V_84 ) ;
V_28 = F_230 ( V_84 , V_34 ) ;
if ( V_28 )
return V_28 ;
goto V_75;
}
return - V_294 ;
}
V_285 -> V_265 += V_284 ;
F_205 ( V_236 ) -> V_297 += V_284 ;
F_13 ( & V_285 -> V_50 ) ;
return 0 ;
}
void F_212 ( struct V_236 * V_236 , T_2 V_284 )
{
struct V_33 * V_34 = F_205 ( V_236 ) -> V_34 ;
struct V_95 * V_285 ;
V_284 = ( V_284 + V_34 -> V_288 - 1 ) & ~ ( ( T_2 ) V_34 -> V_288 - 1 ) ;
V_285 = F_205 ( V_236 ) -> V_98 ;
F_11 ( & V_285 -> V_50 ) ;
V_285 -> V_265 -= V_284 ;
F_205 ( V_236 ) -> V_297 -= V_284 ;
F_13 ( & V_285 -> V_50 ) ;
}
static void F_231 ( struct V_12 * V_13 )
{
struct V_96 * V_97 = & V_13 -> V_98 ;
struct V_95 * V_99 ;
F_63 () ;
F_64 (found, head, list) {
if ( V_99 -> V_6 & V_102 )
V_99 -> V_266 = V_293 ;
}
F_65 () ;
}
static int F_232 ( struct V_33 * V_34 ,
struct V_95 * V_298 , T_2 V_299 ,
int V_300 )
{
T_2 V_35 = V_298 -> V_252 - V_298 -> V_264 ;
T_2 V_301 = V_298 -> V_253 + V_298 -> V_263 ;
T_2 V_302 ;
if ( V_300 == V_293 )
return 1 ;
if ( V_300 == V_303 ) {
V_302 = F_233 ( & V_34 -> V_36 -> V_304 ) ;
V_302 = F_33 ( T_2 , 64 * 1024 * 1024 ,
F_69 ( V_302 , 1 ) ) ;
if ( V_35 - V_301 < V_302 )
return 1 ;
}
if ( V_301 + V_299 + 256 * 1024 * 1024 < V_35 )
return 0 ;
if ( V_301 + V_299 < F_67 ( V_35 , 8 ) )
return 0 ;
V_302 = F_233 ( & V_34 -> V_36 -> V_304 ) ;
V_302 = F_33 ( T_2 , 256 * 1024 * 1024 , F_69 ( V_302 , 5 ) ) ;
if ( V_35 > V_302 && V_298 -> V_253 < F_67 ( V_35 , 3 ) )
return 0 ;
return 1 ;
}
static int F_227 ( struct V_83 * V_84 ,
struct V_33 * V_61 , T_2 V_299 ,
T_2 V_6 , int V_300 )
{
struct V_95 * V_98 ;
struct V_12 * V_36 = V_61 -> V_36 ;
int V_305 = 0 ;
int V_28 = 0 ;
V_6 = F_222 ( V_61 , V_6 ) ;
V_98 = F_62 ( V_61 -> V_36 , V_6 ) ;
if ( ! V_98 ) {
V_28 = F_217 ( V_61 -> V_36 , V_6 ,
0 , 0 , & V_98 ) ;
F_22 ( V_28 ) ;
}
F_22 ( ! V_98 ) ;
V_75:
F_11 ( & V_98 -> V_50 ) ;
if ( V_98 -> V_266 )
V_300 = V_98 -> V_266 ;
if ( V_98 -> V_103 ) {
F_13 ( & V_98 -> V_50 ) ;
return 0 ;
}
if ( ! F_232 ( V_61 , V_98 , V_299 , V_300 ) ) {
F_13 ( & V_98 -> V_50 ) ;
return 0 ;
} else if ( V_98 -> V_268 ) {
V_305 = 1 ;
} else {
V_98 -> V_268 = 1 ;
}
F_13 ( & V_98 -> V_50 ) ;
F_34 ( & V_36 -> V_306 ) ;
if ( V_305 ) {
F_45 ( & V_36 -> V_306 ) ;
V_305 = 0 ;
goto V_75;
}
if ( F_234 ( V_98 ) )
V_6 |= ( V_100 | V_102 ) ;
if ( V_6 & V_100 && V_36 -> V_307 ) {
V_36 -> V_308 ++ ;
if ( ! ( V_36 -> V_308 %
V_36 -> V_307 ) )
F_231 ( V_36 ) ;
}
V_28 = F_235 ( V_84 , V_61 , V_6 ) ;
if ( V_28 < 0 && V_28 != - V_294 )
goto V_70;
F_11 ( & V_98 -> V_50 ) ;
if ( V_28 )
V_98 -> V_103 = 1 ;
else
V_28 = 1 ;
V_98 -> V_266 = V_267 ;
V_98 -> V_268 = 0 ;
F_13 ( & V_98 -> V_50 ) ;
V_70:
F_45 ( & V_61 -> V_36 -> V_306 ) ;
return V_28 ;
}
static int F_236 ( struct V_83 * V_84 ,
struct V_33 * V_34 , T_2 V_309 , int V_310 )
{
struct V_311 * V_312 ;
struct V_95 * V_98 ;
T_2 V_9 ;
T_2 V_313 ;
T_2 V_314 = 0 ;
long V_315 ;
int V_316 = ( 2 * 1024 * 1024 ) >> V_317 ;
int V_318 = 0 ;
unsigned long V_81 ;
V_312 = & V_34 -> V_36 -> V_319 ;
V_98 = V_312 -> V_98 ;
F_2 () ;
V_9 = V_98 -> V_263 ;
V_81 = V_98 -> V_320 ;
if ( V_9 == 0 )
return 0 ;
F_2 () ;
if ( V_34 -> V_36 -> V_321 == 0 ) {
if ( V_84 )
return 0 ;
F_237 ( V_34 , 0 , 0 ) ;
return 0 ;
}
V_313 = F_238 ( V_9 , V_309 ) ;
while ( V_318 < 1024 ) {
F_2 () ;
V_316 = F_170 (unsigned long, nr_pages,
root->fs_info->delalloc_bytes >> PAGE_CACHE_SHIFT) ;
F_239 ( V_34 -> V_36 -> V_322 , V_316 ) ;
F_11 ( & V_98 -> V_50 ) ;
if ( V_9 > V_98 -> V_263 )
V_314 += V_9 - V_98 -> V_263 ;
V_9 = V_98 -> V_263 ;
F_13 ( & V_98 -> V_50 ) ;
V_318 ++ ;
if ( V_9 == 0 || V_314 >= V_313 )
break;
if ( V_84 && V_84 -> V_87 -> V_323 )
return - V_175 ;
V_315 = F_240 ( 1 ) ;
if ( V_315 )
break;
if ( V_318 > 3 ) {
F_2 () ;
if ( V_81 != V_98 -> V_320 )
break;
}
}
if ( V_314 >= V_309 && ! V_84 )
F_237 ( V_34 , 0 , 0 ) ;
return V_314 >= V_309 ;
}
static int F_241 ( struct V_83 * V_84 ,
struct V_33 * V_34 ,
struct V_311 * V_312 ,
T_2 V_324 , int V_269 )
{
struct V_95 * V_98 = V_312 -> V_98 ;
T_2 V_325 ;
T_2 V_35 = V_324 ;
int V_241 = 0 ;
int V_28 = 0 ;
bool V_286 = false ;
bool V_326 = false ;
V_75:
V_28 = 0 ;
F_11 ( & V_98 -> V_50 ) ;
while ( V_269 && ! V_326 && V_98 -> V_269 ) {
F_13 ( & V_98 -> V_50 ) ;
if ( V_84 )
return - V_175 ;
V_28 = F_242 ( V_98 -> V_82 ,
! V_98 -> V_269 ) ;
if ( V_28 )
return - V_327 ;
F_11 ( & V_98 -> V_50 ) ;
}
V_28 = - V_294 ;
V_325 = V_98 -> V_253 + V_98 -> V_263 +
V_98 -> V_262 + V_98 -> V_264 +
V_98 -> V_265 ;
if ( V_325 <= V_98 -> V_252 ) {
V_325 = V_98 -> V_252 - V_325 ;
if ( V_325 >= V_35 ) {
V_98 -> V_263 += V_324 ;
V_28 = 0 ;
} else {
V_35 = V_324 ;
}
} else {
V_35 = V_325 - V_98 -> V_252 +
( V_324 * ( V_241 + 1 ) ) ;
}
if ( V_28 && V_269 ) {
V_326 = true ;
V_98 -> V_269 = 1 ;
}
F_13 ( & V_98 -> V_50 ) ;
if ( ! V_28 || ! V_269 )
goto V_70;
V_28 = F_236 ( V_84 , V_34 , V_35 , 1 ) ;
if ( V_28 < 0 )
goto V_70;
V_28 = 0 ;
if ( V_241 < 2 ) {
V_241 ++ ;
goto V_75;
}
F_11 ( & V_98 -> V_50 ) ;
if ( V_98 -> V_262 < V_324 )
V_28 = - V_294 ;
F_13 ( & V_98 -> V_50 ) ;
if ( V_28 )
goto V_70;
V_28 = - V_175 ;
if ( V_84 )
goto V_70;
V_28 = - V_294 ;
if ( V_286 )
goto V_70;
V_84 = F_226 ( V_34 ) ;
if ( F_202 ( V_84 ) )
goto V_70;
V_28 = F_230 ( V_84 , V_34 ) ;
if ( ! V_28 ) {
V_84 = NULL ;
V_286 = true ;
goto V_75;
}
V_70:
if ( V_326 ) {
F_11 ( & V_98 -> V_50 ) ;
V_98 -> V_269 = 0 ;
F_243 ( & V_98 -> V_82 ) ;
F_13 ( & V_98 -> V_50 ) ;
}
return V_28 ;
}
static struct V_311 * F_244 ( struct V_83 * V_84 ,
struct V_33 * V_34 )
{
struct V_311 * V_312 ;
if ( V_34 -> V_232 )
V_312 = V_84 -> V_312 ;
else
V_312 = V_34 -> V_312 ;
if ( ! V_312 )
V_312 = & V_34 -> V_36 -> V_328 ;
return V_312 ;
}
static int F_245 ( struct V_311 * V_312 ,
T_2 V_35 )
{
int V_28 = - V_294 ;
F_11 ( & V_312 -> V_50 ) ;
if ( V_312 -> V_9 >= V_35 ) {
V_312 -> V_9 -= V_35 ;
if ( V_312 -> V_9 < V_312 -> V_55 )
V_312 -> V_103 = 0 ;
V_28 = 0 ;
}
F_13 ( & V_312 -> V_50 ) ;
return V_28 ;
}
static void F_246 ( struct V_311 * V_312 ,
T_2 V_35 , int V_329 )
{
F_11 ( & V_312 -> V_50 ) ;
V_312 -> V_9 += V_35 ;
if ( V_329 )
V_312 -> V_55 += V_35 ;
else if ( V_312 -> V_9 >= V_312 -> V_55 )
V_312 -> V_103 = 1 ;
F_13 ( & V_312 -> V_50 ) ;
}
static void F_247 ( struct V_311 * V_312 ,
struct V_311 * V_330 , T_2 V_35 )
{
struct V_95 * V_98 = V_312 -> V_98 ;
F_11 ( & V_312 -> V_50 ) ;
if ( V_35 == ( T_2 ) - 1 )
V_35 = V_312 -> V_55 ;
V_312 -> V_55 -= V_35 ;
if ( V_312 -> V_9 >= V_312 -> V_55 ) {
V_35 = V_312 -> V_9 - V_312 -> V_55 ;
V_312 -> V_9 = V_312 -> V_55 ;
V_312 -> V_103 = 1 ;
} else {
V_35 = 0 ;
}
F_13 ( & V_312 -> V_50 ) ;
if ( V_35 > 0 ) {
if ( V_330 ) {
F_11 ( & V_330 -> V_50 ) ;
if ( ! V_330 -> V_103 ) {
T_2 V_331 ;
V_331 = V_330 -> V_55 - V_330 -> V_9 ;
V_331 = F_238 ( V_35 , V_331 ) ;
V_330 -> V_9 += V_331 ;
if ( V_330 -> V_9 >= V_330 -> V_55 )
V_330 -> V_103 = 1 ;
V_35 -= V_331 ;
}
F_13 ( & V_330 -> V_50 ) ;
}
if ( V_35 ) {
F_11 ( & V_98 -> V_50 ) ;
V_98 -> V_263 -= V_35 ;
V_98 -> V_320 ++ ;
F_13 ( & V_98 -> V_50 ) ;
}
}
}
static int F_248 ( struct V_311 * V_332 ,
struct V_311 * V_333 , T_2 V_35 )
{
int V_28 ;
V_28 = F_245 ( V_332 , V_35 ) ;
if ( V_28 )
return V_28 ;
F_246 ( V_333 , V_35 , 1 ) ;
return 0 ;
}
void F_249 ( struct V_311 * V_334 )
{
memset ( V_334 , 0 , sizeof( * V_334 ) ) ;
F_219 ( & V_334 -> V_50 ) ;
F_55 ( & V_334 -> V_335 , 1 ) ;
V_334 -> V_336 = 6 ;
F_52 ( & V_334 -> V_91 ) ;
}
struct V_311 * F_250 ( struct V_33 * V_34 )
{
struct V_311 * V_312 ;
struct V_12 * V_36 = V_34 -> V_36 ;
V_312 = F_175 ( sizeof( * V_312 ) , V_39 ) ;
if ( ! V_312 )
return NULL ;
F_249 ( V_312 ) ;
V_312 -> V_98 = F_62 ( V_36 ,
V_102 ) ;
return V_312 ;
}
void F_251 ( struct V_33 * V_34 ,
struct V_311 * V_334 )
{
if ( V_334 && F_7 ( & V_334 -> V_335 ) ) {
F_252 ( V_34 , V_334 , ( T_2 ) - 1 ) ;
if ( ! V_334 -> V_337 )
F_9 ( V_334 ) ;
}
}
void F_253 ( struct V_12 * V_36 ,
struct V_311 * V_312 )
{
V_312 -> V_337 = 1 ;
F_34 ( & V_36 -> V_338 ) ;
F_57 ( & V_312 -> V_91 , & V_36 -> V_339 ) ;
F_45 ( & V_36 -> V_338 ) ;
}
int F_254 ( struct V_83 * V_84 ,
struct V_33 * V_34 ,
struct V_311 * V_312 ,
T_2 V_35 )
{
int V_28 ;
if ( V_35 == 0 )
return 0 ;
V_28 = F_241 ( V_84 , V_34 , V_312 , V_35 , 1 ) ;
if ( ! V_28 ) {
F_246 ( V_312 , V_35 , 1 ) ;
return 0 ;
}
return V_28 ;
}
int F_255 ( struct V_83 * V_84 ,
struct V_33 * V_34 ,
struct V_311 * V_312 ,
T_2 V_340 , int V_341 )
{
T_2 V_35 = 0 ;
int V_295 = 0 ;
int V_28 = - V_294 ;
if ( ! V_312 )
return 0 ;
F_11 ( & V_312 -> V_50 ) ;
if ( V_341 > 0 )
V_35 = F_67 ( V_312 -> V_55 , V_341 ) ;
if ( V_340 > V_35 )
V_35 = V_340 ;
if ( V_312 -> V_9 >= V_35 ) {
V_28 = 0 ;
} else {
V_35 -= V_312 -> V_9 ;
if ( V_312 -> V_337 &&
V_312 -> V_342 [ 0 ] + V_312 -> V_342 [ 1 ] >= V_35 )
V_295 = 1 ;
}
F_13 ( & V_312 -> V_50 ) ;
if ( ! V_28 )
return 0 ;
if ( V_312 -> V_343 ) {
V_28 = F_241 ( V_84 , V_34 , V_312 ,
V_35 , 0 ) ;
if ( ! V_28 ) {
F_246 ( V_312 , V_35 , 0 ) ;
return 0 ;
}
}
if ( V_295 ) {
if ( V_84 )
return - V_175 ;
V_84 = F_226 ( V_34 ) ;
F_22 ( F_202 ( V_84 ) ) ;
V_28 = F_230 ( V_84 , V_34 ) ;
return 0 ;
}
return - V_294 ;
}
int F_256 ( struct V_311 * V_344 ,
struct V_311 * V_345 ,
T_2 V_35 )
{
return F_248 ( V_344 , V_345 , V_35 ) ;
}
void F_252 ( struct V_33 * V_34 ,
struct V_311 * V_312 ,
T_2 V_35 )
{
struct V_311 * V_346 = & V_34 -> V_36 -> V_347 ;
if ( V_346 -> V_103 || V_346 == V_312 ||
V_312 -> V_98 != V_346 -> V_98 )
V_346 = NULL ;
F_247 ( V_312 , V_346 , V_35 ) ;
}
static T_2 F_257 ( struct V_12 * V_36 )
{
struct V_95 * V_298 ;
T_2 V_35 ;
T_2 V_348 ;
T_2 V_349 ;
int V_350 = F_258 ( & V_36 -> V_304 ) ;
V_298 = F_62 ( V_36 , V_100 ) ;
F_11 ( & V_298 -> V_50 ) ;
V_349 = V_298 -> V_253 ;
F_13 ( & V_298 -> V_50 ) ;
V_298 = F_62 ( V_36 , V_102 ) ;
F_11 ( & V_298 -> V_50 ) ;
if ( V_298 -> V_6 & V_100 )
V_349 = 0 ;
V_348 = V_298 -> V_253 ;
F_13 ( & V_298 -> V_50 ) ;
V_35 = ( V_349 >> V_36 -> V_322 -> V_351 ) *
V_350 * 2 ;
V_35 += F_209 ( V_349 + V_348 , 50 ) ;
if ( V_35 * 3 > V_348 )
V_35 = F_209 ( V_348 , 3 ) ;
return F_259 ( V_35 , V_36 -> V_61 -> V_352 << 10 ) ;
}
static void F_260 ( struct V_12 * V_36 )
{
struct V_311 * V_312 = & V_36 -> V_347 ;
struct V_95 * V_298 = V_312 -> V_98 ;
T_2 V_35 ;
V_35 = F_257 ( V_36 ) ;
F_11 ( & V_312 -> V_50 ) ;
F_11 ( & V_298 -> V_50 ) ;
V_312 -> V_55 = V_35 ;
V_35 = V_298 -> V_253 + V_298 -> V_262 +
V_298 -> V_263 + V_298 -> V_264 +
V_298 -> V_265 ;
if ( V_298 -> V_252 > V_35 ) {
V_35 = V_298 -> V_252 - V_35 ;
V_312 -> V_9 += V_35 ;
V_298 -> V_263 += V_35 ;
}
if ( V_312 -> V_9 >= V_312 -> V_55 ) {
V_35 = V_312 -> V_9 - V_312 -> V_55 ;
V_298 -> V_263 -= V_35 ;
V_298 -> V_320 ++ ;
V_312 -> V_9 = V_312 -> V_55 ;
V_312 -> V_103 = 1 ;
}
F_13 ( & V_298 -> V_50 ) ;
F_13 ( & V_312 -> V_50 ) ;
}
static void F_261 ( struct V_12 * V_36 )
{
struct V_95 * V_98 ;
V_98 = F_62 ( V_36 , V_101 ) ;
V_36 -> V_353 . V_98 = V_98 ;
V_36 -> V_353 . V_336 = 10 ;
V_98 = F_62 ( V_36 , V_102 ) ;
V_36 -> V_347 . V_98 = V_98 ;
V_36 -> V_347 . V_336 = 10 ;
V_36 -> V_347 . V_343 = 1 ;
V_36 -> V_319 . V_98 = V_98 ;
V_36 -> V_354 . V_98 = V_98 ;
V_36 -> V_328 . V_98 = V_98 ;
V_36 -> V_328 . V_336 = 10 ;
V_36 -> V_61 -> V_312 = & V_36 -> V_347 ;
V_36 -> V_355 -> V_312 = & V_36 -> V_347 ;
V_36 -> V_356 -> V_312 = & V_36 -> V_347 ;
V_36 -> V_89 -> V_312 = & V_36 -> V_347 ;
V_36 -> V_283 -> V_312 = & V_36 -> V_353 ;
F_253 ( V_36 , & V_36 -> V_347 ) ;
F_253 ( V_36 , & V_36 -> V_319 ) ;
F_260 ( V_36 ) ;
}
static void F_262 ( struct V_12 * V_36 )
{
F_247 ( & V_36 -> V_347 , NULL , ( T_2 ) - 1 ) ;
F_8 ( V_36 -> V_319 . V_55 > 0 ) ;
F_8 ( V_36 -> V_319 . V_9 > 0 ) ;
F_8 ( V_36 -> V_354 . V_55 > 0 ) ;
F_8 ( V_36 -> V_354 . V_9 > 0 ) ;
F_8 ( V_36 -> V_353 . V_55 > 0 ) ;
F_8 ( V_36 -> V_353 . V_9 > 0 ) ;
}
int F_263 ( struct V_83 * V_84 ,
struct V_33 * V_34 ,
struct V_311 * V_334 )
{
struct V_311 * V_357 = & V_34 -> V_36 -> V_354 ;
T_2 V_35 ;
int V_28 ;
V_35 = F_264 ( V_34 , 2 ) ;
if ( V_334 -> V_9 >= V_35 )
return 0 ;
V_35 -= V_334 -> V_9 ;
V_28 = F_248 ( V_357 , V_334 , V_35 ) ;
F_22 ( V_28 ) ;
return 0 ;
}
void F_265 ( struct V_83 * V_84 ,
struct V_33 * V_34 )
{
if ( ! V_84 -> V_263 )
return;
F_22 ( V_84 -> V_312 != & V_34 -> V_36 -> V_354 ) ;
F_252 ( V_34 , V_84 -> V_312 ,
V_84 -> V_263 ) ;
V_84 -> V_263 = 0 ;
}
int F_266 ( struct V_83 * V_84 ,
struct V_236 * V_236 )
{
struct V_33 * V_34 = F_205 ( V_236 ) -> V_34 ;
struct V_311 * V_344 = F_244 ( V_84 , V_34 ) ;
struct V_311 * V_345 = V_34 -> V_358 ;
T_2 V_35 = F_264 ( V_34 , 1 ) ;
return F_248 ( V_344 , V_345 , V_35 ) ;
}
void F_267 ( struct V_236 * V_236 )
{
struct V_33 * V_34 = F_205 ( V_236 ) -> V_34 ;
T_2 V_35 = F_264 ( V_34 , 1 ) ;
F_252 ( V_34 , V_34 -> V_358 , V_35 ) ;
}
int F_268 ( struct V_83 * V_84 ,
struct V_359 * V_360 )
{
struct V_33 * V_34 = V_360 -> V_34 ;
struct V_311 * V_344 = F_244 ( V_84 , V_34 ) ;
struct V_311 * V_345 = & V_360 -> V_312 ;
T_2 V_35 = F_264 ( V_34 , 5 ) ;
V_345 -> V_98 = V_344 -> V_98 ;
return F_248 ( V_344 , V_345 , V_35 ) ;
}
static unsigned F_269 ( struct V_236 * V_236 )
{
unsigned V_361 = 0 ;
F_11 ( & F_205 ( V_236 ) -> V_50 ) ;
F_22 ( ! F_205 ( V_236 ) -> V_362 ) ;
F_205 ( V_236 ) -> V_362 -- ;
if ( F_205 ( V_236 ) -> V_362 >=
F_205 ( V_236 ) -> V_363 )
goto V_70;
V_361 = F_205 ( V_236 ) -> V_363 -
F_205 ( V_236 ) -> V_362 ;
F_205 ( V_236 ) -> V_363 -= V_361 ;
V_70:
F_13 ( & F_205 ( V_236 ) -> V_50 ) ;
return V_361 ;
}
static T_2 F_270 ( struct V_236 * V_236 , T_2 V_35 )
{
return V_35 >>= 3 ;
}
int F_271 ( struct V_236 * V_236 , T_2 V_35 )
{
struct V_33 * V_34 = F_205 ( V_236 ) -> V_34 ;
struct V_311 * V_312 = & V_34 -> V_36 -> V_319 ;
T_2 V_364 = 0 ;
unsigned V_365 = 0 ;
int V_28 ;
if ( F_272 ( V_34 -> V_36 ) )
F_173 ( 1 ) ;
V_35 = F_259 ( V_35 , V_34 -> V_288 ) ;
F_11 ( & F_205 ( V_236 ) -> V_50 ) ;
F_205 ( V_236 ) -> V_362 ++ ;
if ( F_205 ( V_236 ) -> V_362 >
F_205 ( V_236 ) -> V_363 ) {
V_365 = F_205 ( V_236 ) -> V_362 -
F_205 ( V_236 ) -> V_363 ;
F_205 ( V_236 ) -> V_363 += V_365 ;
V_364 = F_264 ( V_34 , V_365 ) ;
}
F_13 ( & F_205 ( V_236 ) -> V_50 ) ;
V_364 += F_270 ( V_236 , V_35 ) ;
V_28 = F_241 ( NULL , V_34 , V_312 , V_364 , 1 ) ;
if ( V_28 ) {
unsigned V_366 ;
V_366 = F_269 ( V_236 ) ;
F_8 ( V_366 > 1 ) ;
return V_28 ;
}
F_246 ( V_312 , V_364 , 1 ) ;
return 0 ;
}
void F_273 ( struct V_236 * V_236 , T_2 V_35 )
{
struct V_33 * V_34 = F_205 ( V_236 ) -> V_34 ;
T_2 V_367 = 0 ;
unsigned V_366 ;
V_35 = F_259 ( V_35 , V_34 -> V_288 ) ;
V_366 = F_269 ( V_236 ) ;
V_367 = F_270 ( V_236 , V_35 ) ;
if ( V_366 > 0 )
V_367 += F_264 ( V_34 , V_366 ) ;
F_252 ( V_34 , & V_34 -> V_36 -> V_319 ,
V_367 ) ;
}
int F_274 ( struct V_236 * V_236 , T_2 V_35 )
{
int V_28 ;
V_28 = F_210 ( V_236 , V_35 ) ;
if ( V_28 )
return V_28 ;
V_28 = F_271 ( V_236 , V_35 ) ;
if ( V_28 ) {
F_212 ( V_236 , V_35 ) ;
return V_28 ;
}
return 0 ;
}
void F_275 ( struct V_236 * V_236 , T_2 V_35 )
{
F_273 ( V_236 , V_35 ) ;
F_212 ( V_236 , V_35 ) ;
}
static int F_276 ( struct V_83 * V_84 ,
struct V_33 * V_34 ,
T_2 V_26 , T_2 V_35 , int V_291 )
{
struct V_1 * V_2 = NULL ;
struct V_12 * V_13 = V_34 -> V_36 ;
T_2 V_368 = V_35 ;
T_2 V_369 ;
T_2 V_370 ;
int V_105 ;
F_11 ( & V_13 -> V_371 ) ;
V_369 = F_277 ( & V_13 -> V_304 ) ;
if ( V_291 )
V_369 += V_35 ;
else
V_369 -= V_35 ;
F_278 ( & V_13 -> V_304 , V_369 ) ;
F_13 ( & V_13 -> V_371 ) ;
while ( V_368 ) {
V_2 = F_61 ( V_13 , V_26 ) ;
if ( ! V_2 )
return - 1 ;
if ( V_2 -> V_6 & ( V_254 |
V_255 |
V_256 ) )
V_105 = 2 ;
else
V_105 = 1 ;
if ( ! V_291 && V_2 -> V_3 == V_86 )
F_49 ( V_2 , V_84 , NULL , 1 ) ;
V_370 = V_26 - V_2 -> V_21 . V_22 ;
F_8 ( V_370 > V_2 -> V_21 . V_32 ) ;
F_11 ( & V_2 -> V_98 -> V_50 ) ;
F_11 ( & V_2 -> V_50 ) ;
if ( F_279 ( & V_13 -> V_304 ) != 0 &&
V_2 -> V_242 < V_248 )
V_2 -> V_242 = V_248 ;
V_2 -> V_249 = 1 ;
V_369 = F_72 ( & V_2 -> V_113 ) ;
V_35 = F_238 ( V_368 , V_2 -> V_21 . V_32 - V_370 ) ;
if ( V_291 ) {
V_369 += V_35 ;
F_280 ( & V_2 -> V_113 , V_369 ) ;
V_2 -> V_9 -= V_35 ;
V_2 -> V_98 -> V_263 -= V_35 ;
V_2 -> V_98 -> V_320 ++ ;
V_2 -> V_98 -> V_253 += V_35 ;
V_2 -> V_98 -> V_258 += V_35 * V_105 ;
F_13 ( & V_2 -> V_50 ) ;
F_13 ( & V_2 -> V_98 -> V_50 ) ;
} else {
V_369 -= V_35 ;
F_280 ( & V_2 -> V_113 , V_369 ) ;
V_2 -> V_8 += V_35 ;
V_2 -> V_98 -> V_262 += V_35 ;
V_2 -> V_98 -> V_253 -= V_35 ;
V_2 -> V_98 -> V_258 -= V_35 * V_105 ;
F_13 ( & V_2 -> V_50 ) ;
F_13 ( & V_2 -> V_98 -> V_50 ) ;
F_281 ( V_13 -> V_57 ,
V_26 , V_26 + V_35 - 1 ,
V_39 | V_372 ) ;
}
F_6 ( V_2 ) ;
V_368 -= V_35 ;
V_26 += V_35 ;
}
return 0 ;
}
static T_2 F_282 ( struct V_33 * V_34 , T_2 V_106 )
{
struct V_1 * V_2 ;
T_2 V_26 ;
V_2 = F_60 ( V_34 -> V_36 , V_106 ) ;
if ( ! V_2 )
return 0 ;
V_26 = V_2 -> V_21 . V_22 ;
F_6 ( V_2 ) ;
return V_26 ;
}
static int F_283 ( struct V_33 * V_34 ,
struct V_1 * V_2 ,
T_2 V_26 , T_2 V_35 , int V_9 )
{
F_11 ( & V_2 -> V_98 -> V_50 ) ;
F_11 ( & V_2 -> V_50 ) ;
V_2 -> V_8 += V_35 ;
V_2 -> V_98 -> V_262 += V_35 ;
if ( V_9 ) {
V_2 -> V_9 -= V_35 ;
V_2 -> V_98 -> V_263 -= V_35 ;
V_2 -> V_98 -> V_320 ++ ;
}
F_13 ( & V_2 -> V_50 ) ;
F_13 ( & V_2 -> V_98 -> V_50 ) ;
F_281 ( V_34 -> V_36 -> V_57 , V_26 ,
V_26 + V_35 - 1 , V_39 | V_372 ) ;
return 0 ;
}
int F_159 ( struct V_33 * V_34 ,
T_2 V_26 , T_2 V_35 , int V_9 )
{
struct V_1 * V_2 ;
V_2 = F_61 ( V_34 -> V_36 , V_26 ) ;
F_22 ( ! V_2 ) ;
F_283 ( V_34 , V_2 , V_26 , V_35 , V_9 ) ;
F_6 ( V_2 ) ;
return 0 ;
}
int F_284 ( struct V_1 * V_2 ,
T_2 V_35 , int V_373 , int V_298 )
{
int V_28 = 0 ;
if ( V_298 ) {
struct V_95 * V_98 = V_2 -> V_98 ;
F_11 ( & V_98 -> V_50 ) ;
F_11 ( & V_2 -> V_50 ) ;
if ( V_373 ) {
if ( V_2 -> V_114 ) {
V_28 = - V_175 ;
} else {
V_2 -> V_9 += V_35 ;
V_98 -> V_263 += V_35 ;
}
} else {
if ( V_2 -> V_114 )
V_98 -> V_264 += V_35 ;
V_2 -> V_9 -= V_35 ;
V_98 -> V_263 -= V_35 ;
V_98 -> V_320 ++ ;
}
F_13 ( & V_2 -> V_50 ) ;
F_13 ( & V_98 -> V_50 ) ;
} else {
F_11 ( & V_2 -> V_50 ) ;
if ( V_2 -> V_114 ) {
V_28 = - V_175 ;
} else {
if ( V_373 )
V_2 -> V_9 += V_35 ;
else
V_2 -> V_9 -= V_35 ;
}
F_13 ( & V_2 -> V_50 ) ;
}
return V_28 ;
}
int F_285 ( struct V_83 * V_84 ,
struct V_33 * V_34 )
{
struct V_12 * V_36 = V_34 -> V_36 ;
struct V_48 * V_214 ;
struct V_48 * V_52 ;
struct V_1 * V_2 ;
F_56 ( & V_36 -> V_77 ) ;
F_286 (caching_ctl, next,
&fs_info->caching_block_groups, list) {
V_2 = V_52 -> V_14 ;
if ( F_1 ( V_2 ) ) {
V_2 -> V_90 = ( T_2 ) - 1 ;
F_166 ( & V_52 -> V_91 ) ;
F_26 ( V_52 ) ;
} else {
V_2 -> V_90 = V_52 -> V_81 ;
}
}
if ( V_36 -> V_57 == & V_36 -> V_37 [ 0 ] )
V_36 -> V_57 = & V_36 -> V_37 [ 1 ] ;
else
V_36 -> V_57 = & V_36 -> V_37 [ 0 ] ;
F_58 ( & V_36 -> V_77 ) ;
F_260 ( V_36 ) ;
return 0 ;
}
static int F_287 ( struct V_33 * V_34 , T_2 V_31 , T_2 V_30 )
{
struct V_12 * V_36 = V_34 -> V_36 ;
struct V_1 * V_2 = NULL ;
T_2 V_115 ;
while ( V_31 <= V_30 ) {
if ( ! V_2 ||
V_31 >= V_2 -> V_21 . V_22 + V_2 -> V_21 . V_32 ) {
if ( V_2 )
F_6 ( V_2 ) ;
V_2 = F_61 ( V_36 , V_31 ) ;
F_22 ( ! V_2 ) ;
}
V_115 = V_2 -> V_21 . V_22 + V_2 -> V_21 . V_32 - V_31 ;
V_115 = F_238 ( V_115 , V_30 + 1 - V_31 ) ;
if ( V_31 < V_2 -> V_90 ) {
V_115 = F_238 ( V_115 , V_2 -> V_90 - V_31 ) ;
F_29 ( V_2 , V_31 , V_115 ) ;
}
V_31 += V_115 ;
F_11 ( & V_2 -> V_98 -> V_50 ) ;
F_11 ( & V_2 -> V_50 ) ;
V_2 -> V_8 -= V_115 ;
V_2 -> V_98 -> V_262 -= V_115 ;
if ( V_2 -> V_114 ) {
V_2 -> V_98 -> V_264 += V_115 ;
} else if ( V_2 -> V_10 > 0 ) {
V_115 = F_238 ( V_115 , V_2 -> V_10 ) ;
V_2 -> V_10 -= V_115 ;
V_2 -> V_98 -> V_263 += V_115 ;
}
F_13 ( & V_2 -> V_50 ) ;
F_13 ( & V_2 -> V_98 -> V_50 ) ;
}
if ( V_2 )
F_6 ( V_2 ) ;
return 0 ;
}
int F_288 ( struct V_83 * V_84 ,
struct V_33 * V_34 )
{
struct V_12 * V_36 = V_34 -> V_36 ;
struct V_374 * V_375 ;
struct V_311 * V_312 ;
struct V_311 * V_376 ;
T_2 V_31 ;
T_2 V_30 ;
int V_377 ;
int V_28 ;
if ( V_36 -> V_57 == & V_36 -> V_37 [ 0 ] )
V_375 = & V_36 -> V_37 [ 1 ] ;
else
V_375 = & V_36 -> V_37 [ 0 ] ;
while ( 1 ) {
V_28 = F_28 ( V_375 , 0 , & V_31 , & V_30 ,
V_58 ) ;
if ( V_28 )
break;
if ( F_289 ( V_34 , V_378 ) )
V_28 = F_141 ( V_34 , V_31 ,
V_30 + 1 - V_31 , NULL ) ;
F_290 ( V_375 , V_31 , V_30 , V_39 ) ;
F_287 ( V_34 , V_31 , V_30 ) ;
F_46 () ;
}
F_34 ( & V_36 -> V_338 ) ;
F_286 (block_rsv, next_rsv,
&fs_info->durable_block_rsv_list, list) {
V_377 = V_84 -> V_379 & 0x1 ;
if ( V_312 -> V_342 [ V_377 ] > 0 ) {
F_246 ( V_312 ,
V_312 -> V_342 [ V_377 ] , 0 ) ;
V_312 -> V_342 [ V_377 ] = 0 ;
}
if ( F_229 ( & V_312 -> V_335 ) == 0 ) {
F_252 ( V_34 , V_312 , ( T_2 ) - 1 ) ;
if ( V_312 -> V_342 [ 0 ] == 0 &&
V_312 -> V_342 [ 1 ] == 0 ) {
F_166 ( & V_312 -> V_91 ) ;
F_9 ( V_312 ) ;
}
} else {
F_252 ( V_34 , V_312 , 0 ) ;
}
}
F_45 ( & V_36 -> V_338 ) ;
return 0 ;
}
static int F_150 ( struct V_83 * V_84 ,
struct V_33 * V_34 ,
T_2 V_26 , T_2 V_35 , T_2 V_17 ,
T_2 V_146 , T_2 V_380 ,
T_2 V_381 , int V_159 ,
struct V_177 * V_131 )
{
struct V_66 V_21 ;
struct V_62 * V_63 ;
struct V_12 * V_13 = V_34 -> V_36 ;
struct V_33 * V_61 = V_13 -> V_61 ;
struct V_64 * V_65 ;
struct V_121 * V_122 ;
struct V_162 * V_163 ;
int V_28 ;
int V_181 ;
int V_382 = 0 ;
int V_383 = 0 ;
int V_384 = 1 ;
T_3 V_123 ;
T_2 V_117 ;
V_63 = F_32 () ;
if ( ! V_63 )
return - V_116 ;
V_63 -> V_73 = 1 ;
V_63 -> V_200 = 1 ;
V_181 = V_380 >= V_143 ;
F_22 ( ! V_181 && V_159 != 1 ) ;
V_28 = F_133 ( V_84 , V_61 , V_63 , & V_163 ,
V_26 , V_35 , V_17 ,
V_146 , V_380 ,
V_381 ) ;
if ( V_28 == 0 ) {
V_382 = V_63 -> V_80 [ 0 ] ;
while ( V_382 >= 0 ) {
F_39 ( V_63 -> V_79 [ 0 ] , & V_21 ,
V_382 ) ;
if ( V_21 . V_22 != V_26 )
break;
if ( V_21 . type == V_74 &&
V_21 . V_32 == V_35 ) {
V_383 = 1 ;
break;
}
if ( V_63 -> V_80 [ 0 ] - V_382 > 5 )
break;
V_382 -- ;
}
#ifdef F_80
V_123 = F_76 ( V_63 -> V_79 [ 0 ] , V_382 ) ;
if ( V_383 && V_123 < sizeof( * V_122 ) )
V_383 = 0 ;
#endif
if ( ! V_383 ) {
F_22 ( V_163 ) ;
V_28 = F_138 ( V_84 , V_61 , V_63 ,
NULL , V_159 ,
V_181 ) ;
F_22 ( V_28 ) ;
F_43 ( V_63 ) ;
V_63 -> V_200 = 1 ;
V_21 . V_22 = V_26 ;
V_21 . type = V_74 ;
V_21 . V_32 = V_35 ;
V_28 = F_36 ( V_84 , V_61 ,
& V_21 , V_63 , - 1 , 1 ) ;
if ( V_28 ) {
F_291 ( V_385 L_1
L_2 , V_28 ,
( unsigned long long ) V_26 ) ;
if ( V_28 > 0 )
F_292 ( V_61 ,
V_63 -> V_79 [ 0 ] ) ;
}
F_22 ( V_28 ) ;
V_382 = V_63 -> V_80 [ 0 ] ;
}
} else {
F_292 ( V_61 , V_63 -> V_79 [ 0 ] ) ;
F_8 ( 1 ) ;
F_291 ( V_385 L_3
L_4 ,
( unsigned long long ) V_26 ,
( unsigned long long ) V_17 ,
( unsigned long long ) V_146 ,
( unsigned long long ) V_380 ,
( unsigned long long ) V_381 ) ;
}
V_65 = V_63 -> V_79 [ 0 ] ;
V_123 = F_76 ( V_65 , V_382 ) ;
#ifdef F_80
if ( V_123 < sizeof( * V_122 ) ) {
F_22 ( V_383 || V_382 != V_63 -> V_80 [ 0 ] ) ;
V_28 = F_86 ( V_84 , V_61 , V_63 ,
V_380 , 0 ) ;
F_22 ( V_28 < 0 ) ;
F_43 ( V_63 ) ;
V_63 -> V_200 = 1 ;
V_21 . V_22 = V_26 ;
V_21 . type = V_74 ;
V_21 . V_32 = V_35 ;
V_28 = F_36 ( V_84 , V_61 , & V_21 , V_63 ,
- 1 , 1 ) ;
if ( V_28 ) {
F_291 ( V_385 L_1
L_2 , V_28 ,
( unsigned long long ) V_26 ) ;
F_292 ( V_61 , V_63 -> V_79 [ 0 ] ) ;
}
F_22 ( V_28 ) ;
V_382 = V_63 -> V_80 [ 0 ] ;
V_65 = V_63 -> V_79 [ 0 ] ;
V_123 = F_76 ( V_65 , V_382 ) ;
}
#endif
F_22 ( V_123 < sizeof( * V_122 ) ) ;
V_122 = F_77 ( V_65 , V_382 ,
struct V_121 ) ;
if ( V_380 < V_143 ) {
struct V_138 * V_139 ;
F_22 ( V_123 < sizeof( * V_122 ) + sizeof( * V_139 ) ) ;
V_139 = (struct V_138 * ) ( V_122 + 1 ) ;
F_8 ( V_380 != F_293 ( V_65 , V_139 ) ) ;
}
V_117 = F_78 ( V_65 , V_122 ) ;
F_22 ( V_117 < V_159 ) ;
V_117 -= V_159 ;
if ( V_117 > 0 ) {
if ( V_131 )
F_129 ( V_131 , V_65 , V_122 ) ;
if ( V_163 ) {
F_22 ( ! V_383 ) ;
} else {
F_89 ( V_65 , V_122 , V_117 ) ;
F_94 ( V_65 ) ;
}
if ( V_383 ) {
V_28 = F_138 ( V_84 , V_61 , V_63 ,
V_163 , V_159 ,
V_181 ) ;
F_22 ( V_28 ) ;
}
} else {
if ( V_383 ) {
F_22 ( V_181 && V_159 !=
F_117 ( V_34 , V_63 , V_163 ) ) ;
if ( V_163 ) {
F_22 ( V_63 -> V_80 [ 0 ] != V_382 ) ;
} else {
F_22 ( V_63 -> V_80 [ 0 ] != V_382 + 1 ) ;
V_63 -> V_80 [ 0 ] = V_382 ;
V_384 = 2 ;
}
}
V_28 = F_294 ( V_84 , V_61 , V_63 , V_63 -> V_80 [ 0 ] ,
V_384 ) ;
F_22 ( V_28 ) ;
F_43 ( V_63 ) ;
if ( V_181 ) {
V_28 = F_160 ( V_84 , V_34 , V_26 , V_35 ) ;
F_22 ( V_28 ) ;
} else {
F_295 ( V_13 -> V_386 -> V_387 ,
V_26 >> V_317 ,
( V_26 + V_35 - 1 ) >> V_317 ) ;
}
V_28 = F_276 ( V_84 , V_34 , V_26 , V_35 , 0 ) ;
F_22 ( V_28 ) ;
}
F_48 ( V_63 ) ;
return V_28 ;
}
static T_1 int F_296 ( struct V_83 * V_84 ,
struct V_33 * V_34 , T_2 V_26 )
{
struct V_118 * V_97 ;
struct V_119 * V_120 ;
struct V_201 * V_151 ;
struct V_15 * V_130 ;
int V_28 = 0 ;
V_120 = & V_84 -> V_87 -> V_120 ;
F_11 ( & V_120 -> V_50 ) ;
V_97 = F_83 ( V_84 , V_26 ) ;
if ( ! V_97 )
goto V_70;
V_130 = F_178 ( & V_97 -> V_130 . V_15 ) ;
if ( ! V_130 )
goto V_70;
V_151 = F_12 ( V_130 , struct V_201 , V_15 ) ;
if ( V_151 -> V_26 == V_26 )
goto V_70;
if ( V_97 -> V_131 ) {
if ( ! V_97 -> V_213 )
goto V_70;
F_9 ( V_97 -> V_131 ) ;
V_97 -> V_131 = NULL ;
}
if ( ! F_84 ( & V_97 -> V_76 ) )
goto V_70;
V_97 -> V_130 . V_215 = 0 ;
F_167 ( & V_97 -> V_130 . V_15 , & V_120 -> V_34 ) ;
V_120 -> V_216 -- ;
V_120 -> V_388 -- ;
if ( F_162 ( & V_97 -> V_211 ) )
V_120 -> V_219 -- ;
F_166 ( & V_97 -> V_211 ) ;
F_13 ( & V_120 -> V_50 ) ;
F_22 ( V_97 -> V_131 ) ;
if ( V_97 -> V_213 )
V_28 = 1 ;
F_45 ( & V_97 -> V_76 ) ;
F_85 ( & V_97 -> V_130 ) ;
return V_28 ;
V_70:
F_13 ( & V_120 -> V_50 ) ;
return 0 ;
}
void F_297 ( struct V_83 * V_84 ,
struct V_33 * V_34 ,
struct V_64 * V_227 ,
T_2 V_17 , int V_389 )
{
struct V_311 * V_312 ;
struct V_1 * V_2 = NULL ;
int V_28 ;
if ( V_34 -> V_223 . V_22 != V_198 ) {
V_28 = F_144 ( V_84 , V_227 -> V_31 , V_227 -> V_115 ,
V_17 , V_34 -> V_223 . V_22 ,
F_186 ( V_227 ) ,
V_208 , NULL ) ;
F_22 ( V_28 ) ;
}
if ( ! V_389 )
return;
V_312 = F_244 ( V_84 , V_34 ) ;
V_2 = F_61 ( V_34 -> V_36 , V_227 -> V_31 ) ;
if ( V_312 -> V_98 != V_2 -> V_98 )
goto V_70;
if ( F_298 ( V_227 ) == V_84 -> V_379 ) {
if ( V_34 -> V_223 . V_22 != V_198 ) {
V_28 = F_296 ( V_84 , V_34 , V_227 -> V_31 ) ;
if ( ! V_28 )
goto V_390;
}
if ( F_299 ( V_227 , V_391 ) ) {
F_283 ( V_34 , V_2 , V_227 -> V_31 , V_227 -> V_115 , 1 ) ;
goto V_390;
}
F_8 ( F_300 ( V_392 , & V_227 -> V_393 ) ) ;
F_29 ( V_2 , V_227 -> V_31 , V_227 -> V_115 ) ;
V_28 = F_284 ( V_2 , V_227 -> V_115 , 0 , 0 ) ;
if ( V_28 == - V_175 ) {
F_284 ( V_2 , V_227 -> V_115 , 0 , 1 ) ;
goto V_70;
}
V_28 = 1 ;
F_11 ( & V_312 -> V_50 ) ;
if ( V_312 -> V_9 < V_312 -> V_55 ) {
V_312 -> V_9 += V_227 -> V_115 ;
V_28 = 0 ;
}
F_13 ( & V_312 -> V_50 ) ;
if ( V_28 ) {
F_11 ( & V_2 -> V_98 -> V_50 ) ;
V_2 -> V_98 -> V_263 -= V_227 -> V_115 ;
V_2 -> V_98 -> V_320 ++ ;
F_13 ( & V_2 -> V_98 -> V_50 ) ;
}
goto V_70;
}
V_390:
if ( V_312 -> V_337 && ! V_2 -> V_114 ) {
V_28 = 0 ;
F_11 ( & V_2 -> V_50 ) ;
if ( ! V_2 -> V_114 ) {
V_2 -> V_10 += V_227 -> V_115 ;
V_28 = 1 ;
}
F_13 ( & V_2 -> V_50 ) ;
if ( V_28 ) {
F_11 ( & V_312 -> V_50 ) ;
V_312 -> V_342 [ V_84 -> V_379 & 0x1 ] += V_227 -> V_115 ;
F_13 ( & V_312 -> V_50 ) ;
}
}
V_70:
F_301 ( V_394 , & V_227 -> V_393 ) ;
F_6 ( V_2 ) ;
}
int V_233 ( struct V_83 * V_84 ,
struct V_33 * V_34 ,
T_2 V_26 , T_2 V_35 , T_2 V_17 ,
T_2 V_146 , T_2 V_108 , T_2 V_32 )
{
int V_28 ;
if ( V_146 == V_198 ) {
F_8 ( V_108 >= V_143 ) ;
F_159 ( V_34 , V_26 , V_35 , 1 ) ;
V_28 = 0 ;
} else if ( V_108 < V_143 ) {
V_28 = F_144 ( V_84 , V_26 , V_35 ,
V_17 , V_146 , ( int ) V_108 ,
V_208 , NULL ) ;
F_22 ( V_28 ) ;
} else {
V_28 = F_145 ( V_84 , V_26 , V_35 ,
V_17 , V_146 , V_108 ,
V_32 , V_208 , NULL ) ;
F_22 ( V_28 ) ;
}
return V_28 ;
}
static T_2 F_302 ( struct V_33 * V_34 , T_2 V_395 )
{
T_2 V_396 = ( ( T_2 ) V_34 -> V_397 - 1 ) ;
T_2 V_28 = ( V_395 + V_396 ) & ~ V_396 ;
return V_28 ;
}
static T_1 int
F_303 ( struct V_1 * V_2 ,
T_2 V_35 )
{
struct V_48 * V_52 ;
F_304 ( V_82 ) ;
V_52 = F_25 ( V_2 ) ;
if ( ! V_52 )
return 0 ;
F_305 ( V_52 -> V_82 , F_1 ( V_2 ) ||
( V_2 -> V_11 -> V_398 >= V_35 ) ) ;
F_26 ( V_52 ) ;
return 0 ;
}
static T_1 int
F_306 ( struct V_1 * V_2 )
{
struct V_48 * V_52 ;
F_304 ( V_82 ) ;
V_52 = F_25 ( V_2 ) ;
if ( ! V_52 )
return 0 ;
F_305 ( V_52 -> V_82 , F_1 ( V_2 ) ) ;
F_26 ( V_52 ) ;
return 0 ;
}
static int F_307 ( struct V_1 * V_2 )
{
int V_399 ;
if ( V_2 -> V_6 & V_256 )
V_399 = 0 ;
else if ( V_2 -> V_6 & V_255 )
V_399 = 1 ;
else if ( V_2 -> V_6 & V_254 )
V_399 = 2 ;
else if ( V_2 -> V_6 & V_271 )
V_399 = 3 ;
else
V_399 = 4 ;
return V_399 ;
}
static T_1 int F_308 ( struct V_83 * V_84 ,
struct V_33 * V_400 ,
T_2 V_35 , T_2 V_401 ,
T_2 V_106 , T_2 V_402 ,
T_2 V_403 , struct V_66 * V_204 ,
T_2 V_282 )
{
int V_28 = 0 ;
struct V_33 * V_34 = V_400 -> V_36 -> V_61 ;
struct V_404 * V_405 = NULL ;
struct V_1 * V_14 = NULL ;
int V_406 = 2 * 1024 * 1024 ;
int V_407 = 0 ;
int V_408 = 0 ;
struct V_95 * V_98 ;
int V_409 = 0 ;
int V_410 = 0 ;
int V_399 = 0 ;
bool V_411 = false ;
bool V_412 = false ;
bool V_413 = false ;
bool V_414 = true ;
T_2 V_415 = 0 ;
T_2 V_416 = 0 ;
F_8 ( V_35 < V_34 -> V_288 ) ;
F_74 ( V_204 , V_74 ) ;
V_204 -> V_22 = 0 ;
V_204 -> V_32 = 0 ;
V_98 = F_62 ( V_34 -> V_36 , V_282 ) ;
if ( ! V_98 ) {
F_291 ( V_385 L_5 , V_282 ) ;
return - V_294 ;
}
if ( F_234 ( V_98 ) )
V_414 = false ;
if ( V_400 -> V_232 || V_401 )
V_407 = 1 ;
if ( V_282 & V_102 && V_414 ) {
V_405 = & V_34 -> V_36 -> V_417 ;
if ( ! F_289 ( V_34 , V_418 ) )
V_406 = 64 * 1024 ;
}
if ( ( V_282 & V_100 ) && V_414 &&
F_289 ( V_34 , V_418 ) ) {
V_405 = & V_34 -> V_36 -> V_419 ;
}
if ( V_405 ) {
F_11 ( & V_405 -> V_50 ) ;
if ( V_405 -> V_14 )
V_403 = V_405 -> V_420 ;
F_13 ( & V_405 -> V_50 ) ;
}
V_106 = F_71 ( V_106 , F_282 ( V_34 , 0 ) ) ;
V_106 = F_71 ( V_106 , V_403 ) ;
if ( ! V_405 )
V_406 = 0 ;
if ( V_106 == V_403 ) {
V_421:
V_14 = F_61 ( V_34 -> V_36 ,
V_106 ) ;
if ( V_14 && F_3 ( V_14 , V_282 ) &&
( V_14 -> V_3 != V_86 ||
V_106 == V_416 ) ) {
F_35 ( & V_98 -> V_261 ) ;
if ( F_162 ( & V_14 -> V_91 ) ||
V_14 -> V_114 ) {
F_6 ( V_14 ) ;
F_44 ( & V_98 -> V_261 ) ;
} else {
V_399 = F_307 ( V_14 ) ;
goto V_422;
}
} else if ( V_14 ) {
F_6 ( V_14 ) ;
}
}
V_423:
F_35 ( & V_98 -> V_261 ) ;
F_309 (block_group, &space_info->block_groups[index],
list) {
T_2 V_32 ;
int V_3 ;
F_4 ( V_14 ) ;
V_106 = V_14 -> V_21 . V_22 ;
if ( ! F_3 ( V_14 , V_282 ) ) {
T_2 V_424 = V_254 |
V_255 |
V_256 ;
if ( ( V_282 & V_424 ) && ! ( V_14 -> V_6 & V_424 ) )
goto V_410;
}
V_422:
if ( F_310 ( V_14 -> V_3 == V_86 ) ) {
T_2 V_425 ;
V_28 = F_49 ( V_14 , V_84 ,
V_400 , 1 ) ;
if ( V_14 -> V_3 == V_4 )
goto V_422;
V_425 = F_72 ( & V_14 -> V_113 ) ;
V_425 *= 100 ;
V_425 = F_209 ( V_425 ,
V_14 -> V_21 . V_32 ) ;
V_425 = 100 - V_425 ;
if ( V_425 > V_415 &&
F_311 ( ! V_14 -> V_114 ) ) {
V_416 = V_14 -> V_21 . V_22 ;
V_415 = V_425 ;
}
if ( V_410 > V_426 ) {
V_28 = F_49 ( V_14 , V_84 ,
V_400 , 0 ) ;
F_22 ( V_28 ) ;
}
V_411 = true ;
if ( V_410 == V_426 )
goto V_410;
}
V_3 = F_1 ( V_14 ) ;
if ( F_310 ( ! V_3 ) )
V_411 = true ;
if ( F_310 ( V_14 -> V_114 ) )
goto V_410;
F_11 ( & V_14 -> V_11 -> V_427 ) ;
if ( V_3 &&
V_14 -> V_11 -> V_398 <
V_35 + V_401 ) {
F_13 ( & V_14 -> V_11 -> V_427 ) ;
goto V_410;
}
F_13 ( & V_14 -> V_11 -> V_427 ) ;
if ( V_405 && V_410 < V_428 ) {
F_11 ( & V_405 -> V_429 ) ;
if ( V_405 -> V_14 &&
( V_405 -> V_14 -> V_114 ||
! F_3 ( V_405 -> V_14 , V_282 ) ) ) {
V_32 = 0 ;
goto V_430;
}
V_32 = F_312 ( V_14 , V_405 ,
V_35 , V_106 ) ;
if ( V_32 ) {
F_13 ( & V_405 -> V_429 ) ;
goto V_431;
}
F_11 ( & V_405 -> V_50 ) ;
if ( ! V_409 && V_405 -> V_14 &&
V_405 -> V_14 != V_14 &&
V_399 <=
F_307 ( V_405 -> V_14 ) ) {
F_6 ( V_14 ) ;
V_14 = V_405 -> V_14 ;
F_4 ( V_14 ) ;
F_13 ( & V_405 -> V_50 ) ;
F_13 ( & V_405 -> V_429 ) ;
V_409 = 1 ;
V_106 = V_14 -> V_21 . V_22 ;
goto V_422;
}
F_13 ( & V_405 -> V_50 ) ;
V_430:
F_313 ( NULL , V_405 ) ;
V_409 = 0 ;
V_28 = F_314 ( V_84 , V_34 ,
V_14 , V_405 ,
V_32 , V_35 ,
V_406 + V_401 ) ;
if ( V_28 == 0 ) {
V_32 = F_312 ( V_14 ,
V_405 , V_35 ,
V_106 ) ;
if ( V_32 ) {
F_13 ( & V_405 -> V_429 ) ;
goto V_431;
}
} else if ( ! V_3 && V_410 > V_432
&& ! V_412 ) {
F_13 ( & V_405 -> V_429 ) ;
V_412 = true ;
F_303 ( V_14 ,
V_35 + V_406 + V_401 ) ;
goto V_422;
}
F_313 ( NULL , V_405 ) ;
F_13 ( & V_405 -> V_429 ) ;
goto V_410;
}
V_32 = F_315 ( V_14 , V_106 ,
V_35 , V_401 ) ;
if ( ! V_32 && ! V_413 && ! V_3 &&
V_410 > V_432 ) {
F_303 ( V_14 ,
V_35 + V_401 ) ;
V_413 = true ;
goto V_422;
} else if ( ! V_32 ) {
goto V_410;
}
V_431:
V_106 = F_302 ( V_34 , V_32 ) ;
if ( V_106 + V_35 >= V_402 ) {
F_29 ( V_14 , V_32 , V_35 ) ;
goto V_410;
}
if ( V_106 + V_35 >
V_14 -> V_21 . V_22 + V_14 -> V_21 . V_32 ) {
F_29 ( V_14 , V_32 , V_35 ) ;
goto V_410;
}
V_204 -> V_22 = V_106 ;
V_204 -> V_32 = V_35 ;
if ( V_32 < V_106 )
F_29 ( V_14 , V_32 ,
V_106 - V_32 ) ;
F_22 ( V_32 > V_106 ) ;
V_28 = F_284 ( V_14 , V_35 , 1 ,
( V_282 & V_100 ) ) ;
if ( V_28 == - V_175 ) {
F_29 ( V_14 , V_32 , V_35 ) ;
goto V_410;
}
V_204 -> V_22 = V_106 ;
V_204 -> V_32 = V_35 ;
if ( V_32 < V_106 )
F_29 ( V_14 , V_32 ,
V_106 - V_32 ) ;
F_22 ( V_32 > V_106 ) ;
F_6 ( V_14 ) ;
break;
V_410:
V_412 = false ;
V_413 = false ;
F_22 ( V_399 != F_307 ( V_14 ) ) ;
F_6 ( V_14 ) ;
}
F_44 ( & V_98 -> V_261 ) ;
if ( ! V_204 -> V_22 && ++ V_399 < V_259 )
goto V_423;
if ( ! V_204 -> V_22 && V_410 < V_428 ) {
V_399 = 0 ;
if ( V_410 == V_426 && V_411 ) {
V_411 = false ;
V_410 ++ ;
if ( ! V_415 )
goto V_423;
V_410 = V_433 ;
V_106 = V_416 ;
V_415 = 0 ;
goto V_421;
} else if ( V_410 == V_426 ) {
V_410 = V_433 ;
goto V_423;
}
V_410 ++ ;
if ( V_410 == V_434 ) {
if ( V_407 ) {
V_28 = F_227 ( V_84 , V_34 , V_35 +
2 * 1024 * 1024 , V_282 ,
V_303 ) ;
V_407 = 0 ;
if ( V_28 == 1 )
V_408 = 1 ;
} else if ( ! V_408 &&
V_98 -> V_266 ==
V_267 ) {
V_98 -> V_266 = V_303 ;
}
if ( ! V_408 )
V_410 = V_428 ;
}
if ( V_410 == V_428 ) {
V_401 = 0 ;
V_406 = 0 ;
}
goto V_423;
} else if ( ! V_204 -> V_22 ) {
V_28 = - V_294 ;
} else if ( V_204 -> V_22 ) {
V_28 = 0 ;
}
return V_28 ;
}
static void F_316 ( struct V_95 * V_13 , T_2 V_284 ,
int V_435 )
{
struct V_1 * V_2 ;
int V_399 = 0 ;
F_11 ( & V_13 -> V_50 ) ;
F_291 ( V_436 L_6 ,
( unsigned long long ) ( V_13 -> V_252 - V_13 -> V_253 -
V_13 -> V_262 - V_13 -> V_263 -
V_13 -> V_264 ) ,
( V_13 -> V_103 ) ? L_7 : L_8 ) ;
F_291 ( V_436 L_9
L_10 ,
( unsigned long long ) V_13 -> V_252 ,
( unsigned long long ) V_13 -> V_253 ,
( unsigned long long ) V_13 -> V_262 ,
( unsigned long long ) V_13 -> V_263 ,
( unsigned long long ) V_13 -> V_265 ,
( unsigned long long ) V_13 -> V_264 ) ;
F_13 ( & V_13 -> V_50 ) ;
if ( ! V_435 )
return;
F_35 ( & V_13 -> V_261 ) ;
V_75:
F_309 (cache, &info->block_groups[index], list) {
F_11 ( & V_2 -> V_50 ) ;
F_291 ( V_436 L_11
L_12 ,
( unsigned long long ) V_2 -> V_21 . V_22 ,
( unsigned long long ) V_2 -> V_21 . V_32 ,
( unsigned long long ) F_72 ( & V_2 -> V_113 ) ,
( unsigned long long ) V_2 -> V_8 ,
( unsigned long long ) V_2 -> V_9 ) ;
F_317 ( V_2 , V_284 ) ;
F_13 ( & V_2 -> V_50 ) ;
}
if ( ++ V_399 < V_259 )
goto V_75;
F_44 ( & V_13 -> V_261 ) ;
}
int F_318 ( struct V_83 * V_84 ,
struct V_33 * V_34 ,
T_2 V_35 , T_2 V_437 ,
T_2 V_401 , T_2 V_403 ,
T_2 V_402 , struct V_66 * V_204 ,
T_2 V_282 )
{
int V_28 ;
T_2 V_106 = 0 ;
V_282 = F_224 ( V_34 , V_282 ) ;
V_75:
if ( V_401 || V_34 -> V_232 )
V_28 = F_227 ( V_84 , V_34 -> V_36 -> V_61 ,
V_35 + 2 * 1024 * 1024 , V_282 ,
V_267 ) ;
F_8 ( V_35 < V_34 -> V_288 ) ;
V_28 = F_308 ( V_84 , V_34 , V_35 , V_401 ,
V_106 , V_402 , V_403 ,
V_204 , V_282 ) ;
if ( V_28 == - V_294 && V_35 > V_437 ) {
V_35 = V_35 >> 1 ;
V_35 = V_35 & ~ ( V_34 -> V_288 - 1 ) ;
V_35 = F_71 ( V_35 , V_437 ) ;
F_227 ( V_84 , V_34 -> V_36 -> V_61 ,
V_35 , V_282 , V_293 ) ;
goto V_75;
}
if ( V_28 == - V_294 && F_289 ( V_34 , V_438 ) ) {
struct V_95 * V_298 ;
V_298 = F_62 ( V_34 -> V_36 , V_282 ) ;
F_291 ( V_385 L_13
L_14 , ( unsigned long long ) V_282 ,
( unsigned long long ) V_35 ) ;
F_316 ( V_298 , V_35 , 1 ) ;
}
F_319 ( V_34 , V_204 -> V_22 , V_204 -> V_32 ) ;
return V_28 ;
}
int F_320 ( struct V_33 * V_34 , T_2 V_31 , T_2 V_115 )
{
struct V_1 * V_2 ;
int V_28 = 0 ;
V_2 = F_61 ( V_34 -> V_36 , V_31 ) ;
if ( ! V_2 ) {
F_291 ( V_385 L_15 ,
( unsigned long long ) V_31 ) ;
return - V_294 ;
}
if ( F_289 ( V_34 , V_378 ) )
V_28 = F_141 ( V_34 , V_31 , V_115 , NULL ) ;
F_29 ( V_2 , V_31 , V_115 ) ;
F_284 ( V_2 , V_115 , 0 , 1 ) ;
F_6 ( V_2 ) ;
F_321 ( V_34 , V_31 , V_115 ) ;
return V_28 ;
}
static int F_149 ( struct V_83 * V_84 ,
struct V_33 * V_34 ,
T_2 V_17 , T_2 V_146 ,
T_2 V_6 , T_2 V_108 , T_2 V_32 ,
struct V_66 * V_204 , int V_134 )
{
int V_28 ;
struct V_12 * V_36 = V_34 -> V_36 ;
struct V_121 * V_439 ;
struct V_162 * V_163 ;
struct V_62 * V_63 ;
struct V_64 * V_65 ;
int type ;
T_3 V_55 ;
if ( V_17 > 0 )
type = V_154 ;
else
type = V_155 ;
V_55 = sizeof( * V_439 ) + F_124 ( type ) ;
V_63 = F_32 () ;
if ( ! V_63 )
return - V_116 ;
V_63 -> V_200 = 1 ;
V_28 = F_105 ( V_84 , V_36 -> V_61 , V_63 ,
V_204 , V_55 ) ;
F_22 ( V_28 ) ;
V_65 = V_63 -> V_79 [ 0 ] ;
V_439 = F_77 ( V_65 , V_63 -> V_80 [ 0 ] ,
struct V_121 ) ;
F_89 ( V_65 , V_439 , V_134 ) ;
F_90 ( V_65 , V_439 , V_84 -> V_379 ) ;
F_91 ( V_65 , V_439 ,
V_6 | V_145 ) ;
V_163 = (struct V_162 * ) ( V_439 + 1 ) ;
F_131 ( V_65 , V_163 , type ) ;
if ( V_17 > 0 ) {
struct V_158 * V_151 ;
V_151 = (struct V_158 * ) ( V_163 + 1 ) ;
F_132 ( V_65 , V_163 , V_17 ) ;
F_106 ( V_65 , V_151 , V_134 ) ;
} else {
struct V_150 * V_151 ;
V_151 = (struct V_150 * ) ( & V_163 -> V_32 ) ;
F_108 ( V_65 , V_151 , V_146 ) ;
F_109 ( V_65 , V_151 , V_108 ) ;
F_110 ( V_65 , V_151 , V_32 ) ;
F_111 ( V_65 , V_151 , V_134 ) ;
}
F_94 ( V_63 -> V_79 [ 0 ] ) ;
F_48 ( V_63 ) ;
V_28 = F_276 ( V_84 , V_34 , V_204 -> V_22 , V_204 -> V_32 , 1 ) ;
if ( V_28 ) {
F_291 ( V_385 L_16
L_17 , ( unsigned long long ) V_204 -> V_22 ,
( unsigned long long ) V_204 -> V_32 ) ;
F_82 () ;
}
return V_28 ;
}
static int F_155 ( struct V_83 * V_84 ,
struct V_33 * V_34 ,
T_2 V_17 , T_2 V_146 ,
T_2 V_6 , struct V_440 * V_21 ,
int V_166 , struct V_66 * V_204 )
{
int V_28 ;
struct V_12 * V_36 = V_34 -> V_36 ;
struct V_121 * V_439 ;
struct V_138 * V_441 ;
struct V_162 * V_163 ;
struct V_62 * V_63 ;
struct V_64 * V_65 ;
T_3 V_55 = sizeof( * V_439 ) + sizeof( * V_441 ) + sizeof( * V_163 ) ;
V_63 = F_32 () ;
if ( ! V_63 )
return - V_116 ;
V_63 -> V_200 = 1 ;
V_28 = F_105 ( V_84 , V_36 -> V_61 , V_63 ,
V_204 , V_55 ) ;
F_22 ( V_28 ) ;
V_65 = V_63 -> V_79 [ 0 ] ;
V_439 = F_77 ( V_65 , V_63 -> V_80 [ 0 ] ,
struct V_121 ) ;
F_89 ( V_65 , V_439 , 1 ) ;
F_90 ( V_65 , V_439 , V_84 -> V_379 ) ;
F_91 ( V_65 , V_439 ,
V_6 | V_144 ) ;
V_441 = (struct V_138 * ) ( V_439 + 1 ) ;
F_151 ( V_65 , V_441 , V_21 ) ;
F_93 ( V_65 , V_441 , V_166 ) ;
V_163 = (struct V_162 * ) ( V_441 + 1 ) ;
if ( V_17 > 0 ) {
F_22 ( ! ( V_6 & V_129 ) ) ;
F_131 ( V_65 , V_163 ,
V_164 ) ;
F_132 ( V_65 , V_163 , V_17 ) ;
} else {
F_131 ( V_65 , V_163 ,
V_165 ) ;
F_132 ( V_65 , V_163 , V_146 ) ;
}
F_94 ( V_65 ) ;
F_48 ( V_63 ) ;
V_28 = F_276 ( V_84 , V_34 , V_204 -> V_22 , V_204 -> V_32 , 1 ) ;
if ( V_28 ) {
F_291 ( V_385 L_16
L_17 , ( unsigned long long ) V_204 -> V_22 ,
( unsigned long long ) V_204 -> V_32 ) ;
F_82 () ;
}
return V_28 ;
}
int F_322 ( struct V_83 * V_84 ,
struct V_33 * V_34 ,
T_2 V_146 , T_2 V_108 ,
T_2 V_32 , struct V_66 * V_204 )
{
int V_28 ;
F_22 ( V_146 == V_198 ) ;
V_28 = F_145 ( V_84 , V_204 -> V_22 , V_204 -> V_32 ,
0 , V_146 , V_108 , V_32 ,
V_442 , NULL ) ;
return V_28 ;
}
int F_323 ( struct V_83 * V_84 ,
struct V_33 * V_34 ,
T_2 V_146 , T_2 V_108 , T_2 V_32 ,
struct V_66 * V_204 )
{
int V_28 ;
struct V_1 * V_14 ;
struct V_48 * V_52 ;
T_2 V_31 = V_204 -> V_22 ;
T_2 V_35 = V_204 -> V_32 ;
V_14 = F_61 ( V_34 -> V_36 , V_204 -> V_22 ) ;
F_49 ( V_14 , V_84 , NULL , 0 ) ;
V_52 = F_25 ( V_14 ) ;
if ( ! V_52 ) {
F_22 ( ! F_1 ( V_14 ) ) ;
V_28 = F_324 ( V_14 , V_31 , V_35 ) ;
F_22 ( V_28 ) ;
} else {
F_34 ( & V_52 -> V_76 ) ;
if ( V_31 >= V_52 -> V_81 ) {
V_28 = F_17 ( V_34 , V_31 , V_35 ) ;
F_22 ( V_28 ) ;
} else if ( V_31 + V_35 <= V_52 -> V_81 ) {
V_28 = F_324 ( V_14 ,
V_31 , V_35 ) ;
F_22 ( V_28 ) ;
} else {
V_35 = V_52 -> V_81 - V_31 ;
V_28 = F_324 ( V_14 ,
V_31 , V_35 ) ;
F_22 ( V_28 ) ;
V_31 = V_52 -> V_81 ;
V_35 = V_204 -> V_22 + V_204 -> V_32 -
V_52 -> V_81 ;
V_28 = F_17 ( V_34 , V_31 , V_35 ) ;
F_22 ( V_28 ) ;
}
F_45 ( & V_52 -> V_76 ) ;
F_26 ( V_52 ) ;
}
V_28 = F_284 ( V_14 , V_204 -> V_32 , 1 , 1 ) ;
F_22 ( V_28 ) ;
F_6 ( V_14 ) ;
V_28 = F_149 ( V_84 , V_34 , 0 , V_146 ,
0 , V_108 , V_32 , V_204 , 1 ) ;
return V_28 ;
}
struct V_64 * F_325 ( struct V_83 * V_84 ,
struct V_33 * V_34 ,
T_2 V_26 , T_3 V_443 ,
int V_166 )
{
struct V_64 * V_227 ;
V_227 = F_326 ( V_34 , V_26 , V_443 ) ;
if ( ! V_227 )
return F_327 ( - V_116 ) ;
F_328 ( V_227 , V_84 -> V_379 ) ;
F_329 ( V_34 -> V_223 . V_22 , V_227 , V_166 ) ;
F_330 ( V_227 ) ;
F_331 ( V_84 , V_34 , V_227 ) ;
F_332 ( V_227 ) ;
F_333 ( V_227 ) ;
if ( V_34 -> V_223 . V_22 == V_198 ) {
if ( V_34 -> V_444 % 2 == 0 )
F_281 ( & V_34 -> V_445 , V_227 -> V_31 ,
V_227 -> V_31 + V_227 -> V_115 - 1 , V_39 ) ;
else
F_334 ( & V_34 -> V_445 , V_227 -> V_31 ,
V_227 -> V_31 + V_227 -> V_115 - 1 , V_39 ) ;
} else {
F_281 ( & V_84 -> V_87 -> V_446 , V_227 -> V_31 ,
V_227 -> V_31 + V_227 -> V_115 - 1 , V_39 ) ;
}
V_84 -> V_447 ++ ;
return V_227 ;
}
static struct V_311 *
F_335 ( struct V_83 * V_84 ,
struct V_33 * V_34 , T_3 V_443 )
{
struct V_311 * V_312 ;
struct V_311 * V_346 = & V_34 -> V_36 -> V_347 ;
int V_28 ;
V_312 = F_244 ( V_84 , V_34 ) ;
if ( V_312 -> V_55 == 0 ) {
V_28 = F_241 ( V_84 , V_34 , V_312 ,
V_443 , 0 ) ;
if ( V_28 && V_312 != V_346 ) {
V_28 = F_245 ( V_346 , V_443 ) ;
if ( ! V_28 )
return V_346 ;
return F_327 ( V_28 ) ;
} else if ( V_28 ) {
return F_327 ( V_28 ) ;
}
return V_312 ;
}
V_28 = F_245 ( V_312 , V_443 ) ;
if ( ! V_28 )
return V_312 ;
if ( V_28 ) {
F_8 ( 1 ) ;
V_28 = F_241 ( V_84 , V_34 , V_312 , V_443 ,
0 ) ;
if ( ! V_28 ) {
F_11 ( & V_312 -> V_50 ) ;
V_312 -> V_55 += V_443 ;
F_13 ( & V_312 -> V_50 ) ;
return V_312 ;
} else if ( V_28 && V_312 != V_346 ) {
V_28 = F_245 ( V_346 , V_443 ) ;
if ( ! V_28 )
return V_346 ;
}
}
return F_327 ( - V_294 ) ;
}
static void F_336 ( struct V_311 * V_312 , T_3 V_443 )
{
F_246 ( V_312 , V_443 , 0 ) ;
F_247 ( V_312 , NULL , 0 ) ;
}
struct V_64 * F_337 ( struct V_83 * V_84 ,
struct V_33 * V_34 , T_3 V_443 ,
T_2 V_17 , T_2 V_146 ,
struct V_440 * V_21 , int V_166 ,
T_2 V_448 , T_2 V_401 )
{
struct V_66 V_204 ;
struct V_311 * V_312 ;
struct V_64 * V_227 ;
T_2 V_6 = 0 ;
int V_28 ;
V_312 = F_335 ( V_84 , V_34 , V_443 ) ;
if ( F_202 ( V_312 ) )
return F_338 ( V_312 ) ;
V_28 = F_318 ( V_84 , V_34 , V_443 , V_443 ,
V_401 , V_448 , ( T_2 ) - 1 , & V_204 , 0 ) ;
if ( V_28 ) {
F_336 ( V_312 , V_443 ) ;
return F_327 ( V_28 ) ;
}
V_227 = F_325 ( V_84 , V_34 , V_204 . V_22 ,
V_443 , V_166 ) ;
F_22 ( F_202 ( V_227 ) ) ;
if ( V_146 == V_449 ) {
if ( V_17 == 0 )
V_17 = V_204 . V_22 ;
V_6 |= V_129 ;
} else
F_22 ( V_17 > 0 ) ;
if ( V_146 != V_198 ) {
struct V_177 * V_131 ;
V_131 = F_175 ( sizeof( * V_131 ) , V_39 ) ;
F_22 ( ! V_131 ) ;
if ( V_21 )
memcpy ( & V_131 -> V_21 , V_21 , sizeof( V_131 -> V_21 ) ) ;
else
memset ( & V_131 -> V_21 , 0 , sizeof( V_131 -> V_21 ) ) ;
V_131 -> V_133 = V_6 ;
V_131 -> V_207 = 1 ;
V_131 -> V_132 = 1 ;
V_131 -> V_181 = 0 ;
V_28 = F_144 ( V_84 , V_204 . V_22 ,
V_204 . V_32 , V_17 , V_146 ,
V_166 , V_442 ,
V_131 ) ;
F_22 ( V_28 ) ;
}
return V_227 ;
}
static T_1 void F_339 ( struct V_83 * V_84 ,
struct V_33 * V_34 ,
struct V_450 * V_451 ,
struct V_62 * V_63 )
{
T_2 V_26 ;
T_2 V_244 ;
T_2 V_117 ;
T_2 V_6 ;
T_3 V_69 ;
T_3 V_443 ;
struct V_66 V_21 ;
struct V_64 * V_452 ;
int V_28 ;
int V_453 ;
int V_454 = 0 ;
if ( V_63 -> V_80 [ V_451 -> V_166 ] < V_451 -> V_455 ) {
V_451 -> V_456 = V_451 -> V_456 * 2 / 3 ;
V_451 -> V_456 = F_71 ( V_451 -> V_456 , 2 ) ;
} else {
V_451 -> V_456 = V_451 -> V_456 * 3 / 2 ;
V_451 -> V_456 = F_170 ( int , V_451 -> V_456 ,
F_340 ( V_34 ) ) ;
}
V_452 = V_63 -> V_79 [ V_451 -> V_166 ] ;
V_69 = F_37 ( V_452 ) ;
V_443 = F_193 ( V_34 , V_451 -> V_166 - 1 ) ;
for ( V_453 = V_63 -> V_80 [ V_451 -> V_166 ] ; V_453 < V_69 ; V_453 ++ ) {
if ( V_454 >= V_451 -> V_456 )
break;
F_46 () ;
V_26 = F_192 ( V_452 , V_453 ) ;
V_244 = F_341 ( V_452 , V_453 ) ;
if ( V_453 == V_63 -> V_80 [ V_451 -> V_166 ] )
goto V_73;
if ( V_451 -> V_457 == V_458 &&
V_244 <= V_34 -> V_223 . V_32 )
continue;
V_28 = F_75 ( V_84 , V_34 , V_26 , V_443 ,
& V_117 , & V_6 ) ;
F_22 ( V_28 ) ;
F_22 ( V_117 == 0 ) ;
if ( V_451 -> V_457 == V_459 ) {
if ( V_117 == 1 )
goto V_73;
if ( V_451 -> V_166 == 1 &&
( V_6 & V_129 ) )
continue;
if ( ! V_451 -> V_460 ||
V_244 <= V_34 -> V_223 . V_32 )
continue;
F_122 ( V_452 , & V_21 , V_453 ) ;
V_28 = F_342 ( & V_21 ,
& V_451 -> V_461 ) ;
if ( V_28 < 0 )
continue;
} else {
if ( V_451 -> V_166 == 1 &&
( V_6 & V_129 ) )
continue;
}
V_73:
V_28 = F_343 ( V_34 , V_26 , V_443 ,
V_244 ) ;
if ( V_28 )
break;
V_454 ++ ;
}
V_451 -> V_455 = V_453 ;
}
static T_1 int F_344 ( struct V_83 * V_84 ,
struct V_33 * V_34 ,
struct V_62 * V_63 ,
struct V_450 * V_451 , int V_462 )
{
int V_166 = V_451 -> V_166 ;
struct V_64 * V_452 = V_63 -> V_79 [ V_166 ] ;
T_2 V_463 = V_129 ;
int V_28 ;
if ( V_451 -> V_457 == V_458 &&
F_185 ( V_452 ) != V_34 -> V_223 . V_22 )
return 1 ;
if ( V_462 &&
( ( V_451 -> V_457 == V_459 && V_451 -> V_117 [ V_166 ] != 1 ) ||
( V_451 -> V_457 == V_458 && ! ( V_451 -> V_6 [ V_166 ] & V_463 ) ) ) ) {
F_22 ( ! V_63 -> V_464 [ V_166 ] ) ;
V_28 = F_75 ( V_84 , V_34 ,
V_452 -> V_31 , V_452 -> V_115 ,
& V_451 -> V_117 [ V_166 ] ,
& V_451 -> V_6 [ V_166 ] ) ;
F_22 ( V_28 ) ;
F_22 ( V_451 -> V_117 [ V_166 ] == 0 ) ;
}
if ( V_451 -> V_457 == V_459 ) {
if ( V_451 -> V_117 [ V_166 ] > 1 )
return 1 ;
if ( V_63 -> V_464 [ V_166 ] && ! V_451 -> V_172 ) {
F_345 ( V_452 , V_63 -> V_464 [ V_166 ] ) ;
V_63 -> V_464 [ V_166 ] = 0 ;
}
return 0 ;
}
if ( ! ( V_451 -> V_6 [ V_166 ] & V_463 ) ) {
F_22 ( ! V_63 -> V_464 [ V_166 ] ) ;
V_28 = F_194 ( V_84 , V_34 , V_452 , 1 ) ;
F_22 ( V_28 ) ;
V_28 = F_195 ( V_84 , V_34 , V_452 , 0 ) ;
F_22 ( V_28 ) ;
V_28 = F_174 ( V_84 , V_34 , V_452 -> V_31 ,
V_452 -> V_115 , V_463 , 0 ) ;
F_22 ( V_28 ) ;
V_451 -> V_6 [ V_166 ] |= V_463 ;
}
if ( V_63 -> V_464 [ V_166 ] && V_166 > 0 ) {
F_345 ( V_452 , V_63 -> V_464 [ V_166 ] ) ;
V_63 -> V_464 [ V_166 ] = 0 ;
}
return 0 ;
}
static T_1 int F_346 ( struct V_83 * V_84 ,
struct V_33 * V_34 ,
struct V_62 * V_63 ,
struct V_450 * V_451 , int * V_462 )
{
T_2 V_26 ;
T_2 V_244 ;
T_2 V_17 ;
T_3 V_443 ;
struct V_66 V_21 ;
struct V_64 * V_214 ;
int V_166 = V_451 -> V_166 ;
int V_73 = 0 ;
int V_28 = 0 ;
V_244 = F_341 ( V_63 -> V_79 [ V_166 ] ,
V_63 -> V_80 [ V_166 ] ) ;
if ( V_451 -> V_457 == V_458 &&
V_244 <= V_34 -> V_223 . V_32 ) {
* V_462 = 1 ;
return 1 ;
}
V_26 = F_192 ( V_63 -> V_79 [ V_166 ] , V_63 -> V_80 [ V_166 ] ) ;
V_443 = F_193 ( V_34 , V_166 - 1 ) ;
V_214 = F_347 ( V_34 , V_26 , V_443 ) ;
if ( ! V_214 ) {
V_214 = F_326 ( V_34 , V_26 , V_443 ) ;
if ( ! V_214 )
return - V_116 ;
V_73 = 1 ;
}
F_330 ( V_214 ) ;
F_332 ( V_214 ) ;
V_28 = F_75 ( V_84 , V_34 , V_26 , V_443 ,
& V_451 -> V_117 [ V_166 - 1 ] ,
& V_451 -> V_6 [ V_166 - 1 ] ) ;
F_22 ( V_28 ) ;
F_22 ( V_451 -> V_117 [ V_166 - 1 ] == 0 ) ;
* V_462 = 0 ;
if ( V_451 -> V_457 == V_459 ) {
if ( V_451 -> V_117 [ V_166 - 1 ] > 1 ) {
if ( V_166 == 1 &&
( V_451 -> V_6 [ 0 ] & V_129 ) )
goto V_465;
if ( ! V_451 -> V_460 ||
V_244 <= V_34 -> V_223 . V_32 )
goto V_465;
F_122 ( V_63 -> V_79 [ V_166 ] , & V_21 ,
V_63 -> V_80 [ V_166 ] ) ;
V_28 = F_342 ( & V_21 , & V_451 -> V_461 ) ;
if ( V_28 < 0 )
goto V_465;
V_451 -> V_457 = V_458 ;
V_451 -> V_466 = V_166 - 1 ;
}
} else {
if ( V_166 == 1 &&
( V_451 -> V_6 [ 0 ] & V_129 ) )
goto V_465;
}
if ( ! F_348 ( V_214 , V_244 ) ) {
F_349 ( V_214 ) ;
F_350 ( V_214 ) ;
V_214 = NULL ;
* V_462 = 1 ;
}
if ( ! V_214 ) {
if ( V_73 && V_166 == 1 )
F_339 ( V_84 , V_34 , V_451 , V_63 ) ;
V_214 = F_351 ( V_34 , V_26 , V_443 , V_244 ) ;
if ( ! V_214 )
return - V_209 ;
F_330 ( V_214 ) ;
F_332 ( V_214 ) ;
}
V_166 -- ;
F_22 ( V_166 != F_186 ( V_214 ) ) ;
V_63 -> V_79 [ V_166 ] = V_214 ;
V_63 -> V_80 [ V_166 ] = 0 ;
V_63 -> V_464 [ V_166 ] = V_467 ;
V_451 -> V_166 = V_166 ;
if ( V_451 -> V_166 == 1 )
V_451 -> V_455 = 0 ;
return 0 ;
V_465:
V_451 -> V_117 [ V_166 - 1 ] = 0 ;
V_451 -> V_6 [ V_166 - 1 ] = 0 ;
if ( V_451 -> V_457 == V_459 ) {
if ( V_451 -> V_6 [ V_166 ] & V_129 ) {
V_17 = V_63 -> V_79 [ V_166 ] -> V_31 ;
} else {
F_22 ( V_34 -> V_223 . V_22 !=
F_185 ( V_63 -> V_79 [ V_166 ] ) ) ;
V_17 = 0 ;
}
V_28 = V_233 ( V_84 , V_34 , V_26 , V_443 , V_17 ,
V_34 -> V_223 . V_22 , V_166 - 1 , 0 ) ;
F_22 ( V_28 ) ;
}
F_349 ( V_214 ) ;
F_350 ( V_214 ) ;
* V_462 = 1 ;
return 1 ;
}
static T_1 int F_352 ( struct V_83 * V_84 ,
struct V_33 * V_34 ,
struct V_62 * V_63 ,
struct V_450 * V_451 )
{
int V_28 ;
int V_166 = V_451 -> V_166 ;
struct V_64 * V_452 = V_63 -> V_79 [ V_166 ] ;
T_2 V_17 = 0 ;
if ( V_451 -> V_457 == V_458 ) {
F_22 ( V_451 -> V_466 < V_166 ) ;
if ( V_166 < V_451 -> V_466 )
goto V_70;
V_28 = F_40 ( V_63 , V_166 + 1 , & V_451 -> V_461 ) ;
if ( V_28 > 0 )
V_451 -> V_460 = 0 ;
V_451 -> V_457 = V_459 ;
V_451 -> V_466 = - 1 ;
V_63 -> V_80 [ V_166 ] = 0 ;
if ( ! V_63 -> V_464 [ V_166 ] ) {
F_22 ( V_166 == 0 ) ;
F_330 ( V_452 ) ;
F_332 ( V_452 ) ;
V_63 -> V_464 [ V_166 ] = V_467 ;
V_28 = F_75 ( V_84 , V_34 ,
V_452 -> V_31 , V_452 -> V_115 ,
& V_451 -> V_117 [ V_166 ] ,
& V_451 -> V_6 [ V_166 ] ) ;
F_22 ( V_28 ) ;
F_22 ( V_451 -> V_117 [ V_166 ] == 0 ) ;
if ( V_451 -> V_117 [ V_166 ] == 1 ) {
F_345 ( V_452 , V_63 -> V_464 [ V_166 ] ) ;
return 1 ;
}
}
}
F_22 ( V_451 -> V_117 [ V_166 ] > 1 && ! V_63 -> V_464 [ V_166 ] ) ;
if ( V_451 -> V_117 [ V_166 ] == 1 ) {
if ( V_166 == 0 ) {
if ( V_451 -> V_6 [ V_166 ] & V_129 )
V_28 = F_195 ( V_84 , V_34 , V_452 , 1 ) ;
else
V_28 = F_195 ( V_84 , V_34 , V_452 , 0 ) ;
F_22 ( V_28 ) ;
}
if ( ! V_63 -> V_464 [ V_166 ] &&
F_298 ( V_452 ) == V_84 -> V_379 ) {
F_330 ( V_452 ) ;
F_332 ( V_452 ) ;
V_63 -> V_464 [ V_166 ] = V_467 ;
}
F_331 ( V_84 , V_34 , V_452 ) ;
}
if ( V_452 == V_34 -> V_130 ) {
if ( V_451 -> V_6 [ V_166 ] & V_129 )
V_17 = V_452 -> V_31 ;
else
F_22 ( V_34 -> V_223 . V_22 !=
F_185 ( V_452 ) ) ;
} else {
if ( V_451 -> V_6 [ V_166 + 1 ] & V_129 )
V_17 = V_63 -> V_79 [ V_166 + 1 ] -> V_31 ;
else
F_22 ( V_34 -> V_223 . V_22 !=
F_185 ( V_63 -> V_79 [ V_166 + 1 ] ) ) ;
}
F_297 ( V_84 , V_34 , V_452 , V_17 , V_451 -> V_117 [ V_166 ] == 1 ) ;
V_70:
V_451 -> V_117 [ V_166 ] = 0 ;
V_451 -> V_6 [ V_166 ] = 0 ;
return 0 ;
}
static T_1 int F_353 ( struct V_83 * V_84 ,
struct V_33 * V_34 ,
struct V_62 * V_63 ,
struct V_450 * V_451 )
{
int V_166 = V_451 -> V_166 ;
int V_462 = 1 ;
int V_28 ;
while ( V_166 >= 0 ) {
V_28 = F_344 ( V_84 , V_34 , V_63 , V_451 , V_462 ) ;
if ( V_28 > 0 )
break;
if ( V_166 == 0 )
break;
if ( V_63 -> V_80 [ V_166 ] >=
F_37 ( V_63 -> V_79 [ V_166 ] ) )
break;
V_28 = F_346 ( V_84 , V_34 , V_63 , V_451 , & V_462 ) ;
if ( V_28 > 0 ) {
V_63 -> V_80 [ V_166 ] ++ ;
continue;
} else if ( V_28 < 0 )
return V_28 ;
V_166 = V_451 -> V_166 ;
}
return 0 ;
}
static T_1 int F_354 ( struct V_83 * V_84 ,
struct V_33 * V_34 ,
struct V_62 * V_63 ,
struct V_450 * V_451 , int V_468 )
{
int V_166 = V_451 -> V_166 ;
int V_28 ;
V_63 -> V_80 [ V_166 ] = F_37 ( V_63 -> V_79 [ V_166 ] ) ;
while ( V_166 < V_468 && V_63 -> V_79 [ V_166 ] ) {
V_451 -> V_166 = V_166 ;
if ( V_63 -> V_80 [ V_166 ] + 1 <
F_37 ( V_63 -> V_79 [ V_166 ] ) ) {
V_63 -> V_80 [ V_166 ] ++ ;
return 0 ;
} else {
V_28 = F_352 ( V_84 , V_34 , V_63 , V_451 ) ;
if ( V_28 > 0 )
return 0 ;
if ( V_63 -> V_464 [ V_166 ] ) {
F_345 ( V_63 -> V_79 [ V_166 ] ,
V_63 -> V_464 [ V_166 ] ) ;
V_63 -> V_464 [ V_166 ] = 0 ;
}
F_350 ( V_63 -> V_79 [ V_166 ] ) ;
V_63 -> V_79 [ V_166 ] = NULL ;
V_166 ++ ;
}
}
return 1 ;
}
void F_355 ( struct V_33 * V_34 ,
struct V_311 * V_312 , int V_460 )
{
struct V_62 * V_63 ;
struct V_83 * V_84 ;
struct V_33 * V_89 = V_34 -> V_36 -> V_89 ;
struct V_469 * V_224 = & V_34 -> V_224 ;
struct V_450 * V_451 ;
struct V_66 V_21 ;
int V_78 = 0 ;
int V_28 ;
int V_166 ;
V_63 = F_32 () ;
if ( ! V_63 ) {
V_78 = - V_116 ;
goto V_70;
}
V_451 = F_51 ( sizeof( * V_451 ) , V_39 ) ;
if ( ! V_451 ) {
F_48 ( V_63 ) ;
V_78 = - V_116 ;
goto V_70;
}
V_84 = F_356 ( V_89 , 0 ) ;
F_22 ( F_202 ( V_84 ) ) ;
if ( V_312 )
V_84 -> V_312 = V_312 ;
if ( F_357 ( & V_224 -> V_470 ) == 0 ) {
V_166 = F_186 ( V_34 -> V_130 ) ;
V_63 -> V_79 [ V_166 ] = F_358 ( V_34 ) ;
F_332 ( V_63 -> V_79 [ V_166 ] ) ;
V_63 -> V_80 [ V_166 ] = 0 ;
V_63 -> V_464 [ V_166 ] = V_467 ;
memset ( & V_451 -> V_461 , 0 ,
sizeof( V_451 -> V_461 ) ) ;
} else {
F_359 ( & V_21 , & V_224 -> V_470 ) ;
memcpy ( & V_451 -> V_461 , & V_21 ,
sizeof( V_451 -> V_461 ) ) ;
V_166 = V_224 -> V_471 ;
F_22 ( V_166 == 0 ) ;
V_63 -> V_472 = V_166 ;
V_28 = F_36 ( NULL , V_34 , & V_21 , V_63 , 0 , 0 ) ;
V_63 -> V_472 = 0 ;
if ( V_28 < 0 ) {
V_78 = V_28 ;
goto V_126;
}
F_8 ( V_28 > 0 ) ;
F_127 ( V_63 , 0 ) ;
V_166 = F_186 ( V_34 -> V_130 ) ;
while ( 1 ) {
F_330 ( V_63 -> V_79 [ V_166 ] ) ;
F_332 ( V_63 -> V_79 [ V_166 ] ) ;
V_28 = F_75 ( V_84 , V_34 ,
V_63 -> V_79 [ V_166 ] -> V_31 ,
V_63 -> V_79 [ V_166 ] -> V_115 ,
& V_451 -> V_117 [ V_166 ] ,
& V_451 -> V_6 [ V_166 ] ) ;
F_22 ( V_28 ) ;
F_22 ( V_451 -> V_117 [ V_166 ] == 0 ) ;
if ( V_166 == V_224 -> V_471 )
break;
F_349 ( V_63 -> V_79 [ V_166 ] ) ;
F_8 ( V_451 -> V_117 [ V_166 ] != 1 ) ;
V_166 -- ;
}
}
V_451 -> V_166 = V_166 ;
V_451 -> V_466 = - 1 ;
V_451 -> V_457 = V_459 ;
V_451 -> V_460 = V_460 ;
V_451 -> V_172 = 0 ;
V_451 -> V_456 = F_340 ( V_34 ) ;
while ( 1 ) {
V_28 = F_353 ( V_84 , V_34 , V_63 , V_451 ) ;
if ( V_28 < 0 ) {
V_78 = V_28 ;
break;
}
V_28 = F_354 ( V_84 , V_34 , V_63 , V_451 , V_167 ) ;
if ( V_28 < 0 ) {
V_78 = V_28 ;
break;
}
if ( V_28 > 0 ) {
F_22 ( V_451 -> V_457 != V_459 ) ;
break;
}
if ( V_451 -> V_457 == V_459 ) {
V_166 = V_451 -> V_166 ;
F_360 ( V_63 -> V_79 [ V_166 ] ,
& V_224 -> V_470 ,
V_63 -> V_80 [ V_166 ] ) ;
V_224 -> V_471 = V_166 ;
}
F_22 ( V_451 -> V_166 == 0 ) ;
if ( F_361 ( V_84 , V_89 ) ) {
V_28 = F_362 ( V_84 , V_89 ,
& V_34 -> V_223 ,
V_224 ) ;
F_22 ( V_28 ) ;
F_363 ( V_84 , V_89 ) ;
V_84 = F_356 ( V_89 , 0 ) ;
F_22 ( F_202 ( V_84 ) ) ;
if ( V_312 )
V_84 -> V_312 = V_312 ;
}
}
F_43 ( V_63 ) ;
F_22 ( V_78 ) ;
V_28 = F_364 ( V_84 , V_89 , & V_34 -> V_223 ) ;
F_22 ( V_28 ) ;
if ( V_34 -> V_223 . V_22 != V_449 ) {
V_28 = F_365 ( V_89 , V_34 -> V_223 . V_22 ,
NULL , NULL ) ;
F_22 ( V_28 < 0 ) ;
if ( V_28 > 0 ) {
F_366 ( V_84 , V_89 ,
V_34 -> V_223 . V_22 ) ;
}
}
if ( V_34 -> V_473 ) {
F_367 ( V_89 -> V_36 , V_34 ) ;
} else {
F_350 ( V_34 -> V_130 ) ;
F_350 ( V_34 -> V_474 ) ;
F_9 ( V_34 ) ;
}
V_126:
F_363 ( V_84 , V_89 ) ;
F_9 ( V_451 ) ;
F_48 ( V_63 ) ;
V_70:
if ( V_78 )
F_368 ( V_34 -> V_36 , V_78 ) ;
return;
}
int F_369 ( struct V_83 * V_84 ,
struct V_33 * V_34 ,
struct V_64 * V_130 ,
struct V_64 * V_17 )
{
struct V_62 * V_63 ;
struct V_450 * V_451 ;
int V_166 ;
int V_475 ;
int V_28 = 0 ;
int V_476 ;
F_22 ( V_34 -> V_223 . V_22 != V_449 ) ;
V_63 = F_32 () ;
if ( ! V_63 )
return - V_116 ;
V_451 = F_51 ( sizeof( * V_451 ) , V_39 ) ;
if ( ! V_451 ) {
F_48 ( V_63 ) ;
return - V_116 ;
}
F_370 ( V_17 ) ;
V_475 = F_186 ( V_17 ) ;
F_371 ( V_17 ) ;
V_63 -> V_79 [ V_475 ] = V_17 ;
V_63 -> V_80 [ V_475 ] = F_37 ( V_17 ) ;
F_370 ( V_130 ) ;
V_166 = F_186 ( V_130 ) ;
V_63 -> V_79 [ V_166 ] = V_130 ;
V_63 -> V_80 [ V_166 ] = 0 ;
V_63 -> V_464 [ V_166 ] = V_467 ;
V_451 -> V_117 [ V_475 ] = 1 ;
V_451 -> V_6 [ V_475 ] = V_129 ;
V_451 -> V_166 = V_166 ;
V_451 -> V_466 = - 1 ;
V_451 -> V_457 = V_459 ;
V_451 -> V_460 = 0 ;
V_451 -> V_172 = 1 ;
V_451 -> V_456 = F_340 ( V_34 ) ;
while ( 1 ) {
V_476 = F_353 ( V_84 , V_34 , V_63 , V_451 ) ;
if ( V_476 < 0 ) {
V_28 = V_476 ;
break;
}
V_476 = F_354 ( V_84 , V_34 , V_63 , V_451 , V_475 ) ;
if ( V_476 < 0 )
V_28 = V_476 ;
if ( V_476 != 0 )
break;
}
F_9 ( V_451 ) ;
F_48 ( V_63 ) ;
return V_28 ;
}
static T_2 F_372 ( struct V_33 * V_34 , T_2 V_6 )
{
T_2 V_275 ;
T_2 V_477 = V_271 |
V_255 | V_256 ;
V_275 = V_34 -> V_36 -> V_276 -> V_277 +
V_34 -> V_36 -> V_276 -> V_278 ;
if ( V_275 == 1 ) {
V_477 |= V_254 ;
V_477 = V_6 & ~ V_477 ;
if ( V_6 & V_271 )
return V_477 ;
if ( V_6 & ( V_255 |
V_256 ) )
return V_477 | V_254 ;
return V_6 ;
} else {
if ( V_6 & V_477 )
return V_6 ;
V_477 |= V_254 ;
V_477 = V_6 & ~ V_477 ;
if ( V_6 & V_254 )
return V_477 | V_255 ;
return V_477 | V_271 ;
}
return V_6 ;
}
static int F_373 ( struct V_1 * V_2 , int V_300 )
{
struct V_95 * V_298 = V_2 -> V_98 ;
T_2 V_35 ;
T_2 V_478 ;
int V_28 = - V_294 ;
if ( ( V_298 -> V_6 &
( V_101 | V_102 ) ) &&
! V_300 )
V_478 = 1 * 1024 * 1024 ;
else
V_478 = 0 ;
F_11 ( & V_298 -> V_50 ) ;
F_11 ( & V_2 -> V_50 ) ;
if ( V_2 -> V_114 ) {
V_28 = 0 ;
goto V_70;
}
V_35 = V_2 -> V_21 . V_32 - V_2 -> V_9 - V_2 -> V_8 -
V_2 -> V_45 - F_72 ( & V_2 -> V_113 ) ;
if ( V_298 -> V_253 + V_298 -> V_263 + V_298 -> V_262 +
V_298 -> V_265 + V_298 -> V_264 +
V_2 -> V_10 + V_35 + V_478 <=
V_298 -> V_252 ) {
V_298 -> V_264 += V_35 ;
V_298 -> V_263 += V_2 -> V_10 ;
V_2 -> V_10 = 0 ;
V_2 -> V_114 = 1 ;
V_28 = 0 ;
}
V_70:
F_13 ( & V_2 -> V_50 ) ;
F_13 ( & V_298 -> V_50 ) ;
return V_28 ;
}
int F_374 ( struct V_33 * V_34 ,
struct V_1 * V_2 )
{
struct V_83 * V_84 ;
T_2 V_479 ;
int V_28 ;
F_22 ( V_2 -> V_114 ) ;
V_84 = F_226 ( V_34 ) ;
F_22 ( F_202 ( V_84 ) ) ;
V_479 = F_372 ( V_34 , V_2 -> V_6 ) ;
if ( V_479 != V_2 -> V_6 )
F_227 ( V_84 , V_34 , 2 * 1024 * 1024 , V_479 ,
V_293 ) ;
V_28 = F_373 ( V_2 , 0 ) ;
if ( ! V_28 )
goto V_70;
V_479 = F_223 ( V_34 , V_2 -> V_98 -> V_6 ) ;
V_28 = F_227 ( V_84 , V_34 , 2 * 1024 * 1024 , V_479 ,
V_293 ) ;
if ( V_28 < 0 )
goto V_70;
V_28 = F_373 ( V_2 , 0 ) ;
V_70:
F_228 ( V_84 , V_34 ) ;
return V_28 ;
}
int F_375 ( struct V_83 * V_84 ,
struct V_33 * V_34 , T_2 type )
{
T_2 V_479 = F_223 ( V_34 , type ) ;
return F_227 ( V_84 , V_34 , 2 * 1024 * 1024 , V_479 ,
V_293 ) ;
}
static T_2 F_376 ( struct V_96 * V_480 )
{
struct V_1 * V_14 ;
T_2 V_481 = 0 ;
int V_105 ;
F_309 (block_group, groups_list, list) {
F_11 ( & V_14 -> V_50 ) ;
if ( ! V_14 -> V_114 ) {
F_13 ( & V_14 -> V_50 ) ;
continue;
}
if ( V_14 -> V_6 & ( V_255 |
V_256 |
V_254 ) )
V_105 = 2 ;
else
V_105 = 1 ;
V_481 += ( V_14 -> V_21 . V_32 -
F_72 ( & V_14 -> V_113 ) ) *
V_105 ;
F_13 ( & V_14 -> V_50 ) ;
}
return V_481 ;
}
T_2 F_377 ( struct V_95 * V_298 )
{
int V_42 ;
T_2 V_481 = 0 ;
F_11 ( & V_298 -> V_50 ) ;
for( V_42 = 0 ; V_42 < V_259 ; V_42 ++ )
if ( ! F_162 ( & V_298 -> V_260 [ V_42 ] ) )
V_481 += F_376 (
& V_298 -> V_260 [ V_42 ] ) ;
F_13 ( & V_298 -> V_50 ) ;
return V_481 ;
}
int F_378 ( struct V_33 * V_34 ,
struct V_1 * V_2 )
{
struct V_95 * V_298 = V_2 -> V_98 ;
T_2 V_35 ;
F_22 ( ! V_2 -> V_114 ) ;
F_11 ( & V_298 -> V_50 ) ;
F_11 ( & V_2 -> V_50 ) ;
V_35 = V_2 -> V_21 . V_32 - V_2 -> V_9 - V_2 -> V_8 -
V_2 -> V_45 - F_72 ( & V_2 -> V_113 ) ;
V_298 -> V_264 -= V_35 ;
V_2 -> V_114 = 0 ;
F_13 ( & V_2 -> V_50 ) ;
F_13 ( & V_298 -> V_50 ) ;
return 0 ;
}
int F_379 ( struct V_33 * V_34 , T_2 V_26 )
{
struct V_1 * V_14 ;
struct V_95 * V_98 ;
struct V_482 * V_276 = V_34 -> V_36 -> V_276 ;
struct V_483 * V_484 ;
T_2 V_485 ;
T_2 V_486 = 1 ;
T_2 V_487 = 0 ;
int V_399 ;
int V_103 = 0 ;
int V_28 = 0 ;
V_14 = F_61 ( V_34 -> V_36 , V_26 ) ;
if ( ! V_14 )
return - 1 ;
V_485 = F_72 ( & V_14 -> V_113 ) ;
if ( ! V_485 )
goto V_70;
V_98 = V_14 -> V_98 ;
F_11 ( & V_98 -> V_50 ) ;
V_103 = V_98 -> V_103 ;
if ( ( V_98 -> V_252 != V_14 -> V_21 . V_32 ) &&
( V_98 -> V_253 + V_98 -> V_263 +
V_98 -> V_262 + V_98 -> V_264 +
V_485 < V_98 -> V_252 ) ) {
F_13 ( & V_98 -> V_50 ) ;
goto V_70;
}
F_13 ( & V_98 -> V_50 ) ;
V_28 = - 1 ;
if ( V_103 )
goto V_70;
V_399 = F_307 ( V_14 ) ;
if ( V_399 == 0 ) {
V_486 = 4 ;
V_485 >>= 1 ;
} else if ( V_399 == 1 ) {
V_486 = 2 ;
} else if ( V_399 == 2 ) {
V_485 <<= 1 ;
} else if ( V_399 == 3 ) {
V_486 = V_276 -> V_277 ;
F_68 ( V_485 , V_486 ) ;
}
F_34 ( & V_34 -> V_36 -> V_306 ) ;
F_309 (device, &fs_devices->alloc_list, dev_alloc_list) {
T_2 V_488 ;
if ( V_484 -> V_252 > V_484 -> V_253 + V_485 ) {
V_28 = F_380 ( NULL , V_484 , V_485 ,
& V_488 , NULL ) ;
if ( ! V_28 )
V_487 ++ ;
if ( V_487 >= V_486 )
break;
V_28 = - 1 ;
}
}
F_45 ( & V_34 -> V_36 -> V_306 ) ;
V_70:
F_6 ( V_14 ) ;
return V_28 ;
}
static int F_381 ( struct V_33 * V_34 ,
struct V_62 * V_63 , struct V_66 * V_21 )
{
int V_28 = 0 ;
struct V_66 V_140 ;
struct V_64 * V_65 ;
int V_453 ;
V_28 = F_36 ( NULL , V_34 , V_21 , V_63 , 0 , 0 ) ;
if ( V_28 < 0 )
goto V_70;
while ( 1 ) {
V_453 = V_63 -> V_80 [ 0 ] ;
V_65 = V_63 -> V_79 [ 0 ] ;
if ( V_453 >= F_37 ( V_65 ) ) {
V_28 = F_42 ( V_34 , V_63 ) ;
if ( V_28 == 0 )
continue;
if ( V_28 < 0 )
goto V_70;
break;
}
F_39 ( V_65 , & V_140 , V_453 ) ;
if ( V_140 . V_22 >= V_21 -> V_22 &&
V_140 . type == V_176 ) {
V_28 = 0 ;
goto V_70;
}
V_63 -> V_80 [ 0 ] ++ ;
}
V_70:
return V_28 ;
}
void F_382 ( struct V_12 * V_13 )
{
struct V_1 * V_14 ;
T_2 V_68 = 0 ;
while ( 1 ) {
struct V_236 * V_236 ;
V_14 = F_60 ( V_13 , V_68 ) ;
while ( V_14 ) {
F_11 ( & V_14 -> V_50 ) ;
if ( V_14 -> V_163 )
break;
F_13 ( & V_14 -> V_50 ) ;
V_14 = F_199 ( V_13 -> V_89 ,
V_14 ) ;
}
if ( ! V_14 ) {
if ( V_68 == 0 )
break;
V_68 = 0 ;
continue;
}
V_236 = V_14 -> V_236 ;
V_14 -> V_163 = 0 ;
V_14 -> V_236 = NULL ;
F_13 ( & V_14 -> V_50 ) ;
F_213 ( V_236 ) ;
V_68 = V_14 -> V_21 . V_22 + V_14 -> V_21 . V_32 ;
F_6 ( V_14 ) ;
}
}
int F_383 ( struct V_12 * V_13 )
{
struct V_1 * V_14 ;
struct V_95 * V_98 ;
struct V_48 * V_52 ;
struct V_15 * V_29 ;
F_56 ( & V_13 -> V_77 ) ;
while ( ! F_162 ( & V_13 -> V_93 ) ) {
V_52 = F_163 ( V_13 -> V_93 . V_214 ,
struct V_48 , V_91 ) ;
F_384 ( & V_52 -> V_91 ) ;
F_26 ( V_52 ) ;
}
F_58 ( & V_13 -> V_77 ) ;
F_11 ( & V_13 -> V_18 ) ;
while ( ( V_29 = F_385 ( & V_13 -> V_19 ) ) != NULL ) {
V_14 = F_12 ( V_29 , struct V_1 ,
V_20 ) ;
F_167 ( & V_14 -> V_20 ,
& V_13 -> V_19 ) ;
F_13 ( & V_13 -> V_18 ) ;
F_56 ( & V_14 -> V_98 -> V_261 ) ;
F_384 ( & V_14 -> V_91 ) ;
F_58 ( & V_14 -> V_98 -> V_261 ) ;
if ( V_14 -> V_3 == V_51 )
F_306 ( V_14 ) ;
if ( V_14 -> V_3 == V_86 )
F_19 ( V_13 -> V_61 , V_14 ) ;
F_386 ( V_14 ) ;
F_6 ( V_14 ) ;
F_11 ( & V_13 -> V_18 ) ;
}
F_13 ( & V_13 -> V_18 ) ;
F_387 () ;
F_262 ( V_13 ) ;
while( ! F_162 ( & V_13 -> V_98 ) ) {
V_98 = F_163 ( V_13 -> V_98 . V_214 ,
struct V_95 ,
V_91 ) ;
if ( V_98 -> V_262 > 0 ||
V_98 -> V_263 > 0 ) {
F_8 ( 1 ) ;
F_316 ( V_98 , 0 , 0 ) ;
}
F_384 ( & V_98 -> V_91 ) ;
F_9 ( V_98 ) ;
}
return 0 ;
}
static void F_388 ( struct V_95 * V_98 ,
struct V_1 * V_2 )
{
int V_399 = F_307 ( V_2 ) ;
F_56 ( & V_98 -> V_261 ) ;
F_57 ( & V_2 -> V_91 , & V_98 -> V_260 [ V_399 ] ) ;
F_58 ( & V_98 -> V_261 ) ;
}
int F_389 ( struct V_33 * V_34 )
{
struct V_62 * V_63 ;
int V_28 ;
struct V_1 * V_2 ;
struct V_12 * V_13 = V_34 -> V_36 ;
struct V_95 * V_98 ;
struct V_66 V_21 ;
struct V_66 V_140 ;
struct V_64 * V_65 ;
int V_489 = 0 ;
T_2 V_490 ;
V_34 = V_13 -> V_61 ;
V_21 . V_22 = 0 ;
V_21 . V_32 = 0 ;
F_74 ( & V_21 , V_176 ) ;
V_63 = F_32 () ;
if ( ! V_63 )
return - V_116 ;
V_63 -> V_73 = 1 ;
V_490 = F_279 ( & V_34 -> V_36 -> V_304 ) ;
if ( V_490 != 0 &&
F_390 ( & V_34 -> V_36 -> V_304 ) != V_490 )
V_489 = 1 ;
if ( F_289 ( V_34 , V_491 ) )
V_489 = 1 ;
if ( ! F_289 ( V_34 , V_492 ) && V_490 )
F_291 ( V_436 L_18 ) ;
while ( 1 ) {
V_28 = F_381 ( V_34 , V_63 , & V_21 ) ;
if ( V_28 > 0 )
break;
if ( V_28 != 0 )
goto error;
V_65 = V_63 -> V_79 [ 0 ] ;
F_39 ( V_65 , & V_140 , V_63 -> V_80 [ 0 ] ) ;
V_2 = F_51 ( sizeof( * V_2 ) , V_39 ) ;
if ( ! V_2 ) {
V_28 = - V_116 ;
goto error;
}
V_2 -> V_11 = F_51 ( sizeof( * V_2 -> V_11 ) ,
V_39 ) ;
if ( ! V_2 -> V_11 ) {
F_9 ( V_2 ) ;
V_28 = - V_116 ;
goto error;
}
F_55 ( & V_2 -> V_7 , 1 ) ;
F_219 ( & V_2 -> V_50 ) ;
V_2 -> V_36 = V_13 ;
F_52 ( & V_2 -> V_91 ) ;
F_52 ( & V_2 -> V_493 ) ;
if ( V_489 )
V_2 -> V_242 = V_248 ;
F_391 ( V_65 , & V_2 -> V_113 ,
F_197 ( V_65 , V_63 -> V_80 [ 0 ] ) ,
sizeof( V_2 -> V_113 ) ) ;
memcpy ( & V_2 -> V_21 , & V_140 , sizeof( V_140 ) ) ;
V_21 . V_22 = V_140 . V_22 + V_140 . V_32 ;
F_43 ( V_63 ) ;
V_2 -> V_6 = F_392 ( & V_2 -> V_113 ) ;
V_2 -> V_288 = V_34 -> V_288 ;
F_393 ( V_2 ) ;
F_21 ( V_34 , V_2 ) ;
if ( V_140 . V_32 == F_72 ( & V_2 -> V_113 ) ) {
V_2 -> V_90 = ( T_2 ) - 1 ;
V_2 -> V_3 = V_4 ;
F_19 ( V_34 , V_2 ) ;
} else if ( F_72 ( & V_2 -> V_113 ) == 0 ) {
V_2 -> V_90 = ( T_2 ) - 1 ;
V_2 -> V_3 = V_4 ;
F_27 ( V_2 , V_34 -> V_36 ,
V_140 . V_22 ,
V_140 . V_22 +
V_140 . V_32 ) ;
F_19 ( V_34 , V_2 ) ;
}
V_28 = F_217 ( V_13 , V_2 -> V_6 , V_140 . V_32 ,
F_72 ( & V_2 -> V_113 ) ,
& V_98 ) ;
F_22 ( V_28 ) ;
V_2 -> V_98 = V_98 ;
F_11 ( & V_2 -> V_98 -> V_50 ) ;
V_2 -> V_98 -> V_264 += V_2 -> V_45 ;
F_13 ( & V_2 -> V_98 -> V_50 ) ;
F_388 ( V_98 , V_2 ) ;
V_28 = F_10 ( V_34 -> V_36 , V_2 ) ;
F_22 ( V_28 ) ;
F_221 ( V_34 -> V_36 , V_2 -> V_6 ) ;
if ( F_394 ( V_34 , V_2 -> V_21 . V_22 ) )
F_373 ( V_2 , 1 ) ;
}
F_64 (space_info, &root->fs_info->space_info, list) {
if ( ! ( F_223 ( V_34 , V_98 -> V_6 ) &
( V_256 |
V_255 |
V_254 ) ) )
continue;
F_309 (cache, &space_info->block_groups[3], list)
F_373 ( V_2 , 1 ) ;
F_309 (cache, &space_info->block_groups[4], list)
F_373 ( V_2 , 1 ) ;
}
F_261 ( V_13 ) ;
V_28 = 0 ;
error:
F_48 ( V_63 ) ;
return V_28 ;
}
int F_395 ( struct V_83 * V_84 ,
struct V_33 * V_34 , T_2 V_253 ,
T_2 type , T_2 V_494 , T_2 V_495 ,
T_2 V_55 )
{
int V_28 ;
struct V_33 * V_61 ;
struct V_1 * V_2 ;
V_61 = V_34 -> V_36 -> V_61 ;
V_34 -> V_36 -> V_496 = V_84 -> V_379 ;
V_2 = F_51 ( sizeof( * V_2 ) , V_39 ) ;
if ( ! V_2 )
return - V_116 ;
V_2 -> V_11 = F_51 ( sizeof( * V_2 -> V_11 ) ,
V_39 ) ;
if ( ! V_2 -> V_11 ) {
F_9 ( V_2 ) ;
return - V_116 ;
}
V_2 -> V_21 . V_22 = V_495 ;
V_2 -> V_21 . V_32 = V_55 ;
V_2 -> V_21 . type = V_176 ;
V_2 -> V_288 = V_34 -> V_288 ;
V_2 -> V_36 = V_34 -> V_36 ;
F_55 ( & V_2 -> V_7 , 1 ) ;
F_219 ( & V_2 -> V_50 ) ;
F_52 ( & V_2 -> V_91 ) ;
F_52 ( & V_2 -> V_493 ) ;
F_393 ( V_2 ) ;
F_280 ( & V_2 -> V_113 , V_253 ) ;
F_396 ( & V_2 -> V_113 , V_494 ) ;
V_2 -> V_6 = type ;
F_397 ( & V_2 -> V_113 , type ) ;
V_2 -> V_90 = ( T_2 ) - 1 ;
V_2 -> V_3 = V_4 ;
F_21 ( V_34 , V_2 ) ;
F_27 ( V_2 , V_34 -> V_36 , V_495 ,
V_495 + V_55 ) ;
F_19 ( V_34 , V_2 ) ;
V_28 = F_217 ( V_34 -> V_36 , V_2 -> V_6 , V_55 , V_253 ,
& V_2 -> V_98 ) ;
F_22 ( V_28 ) ;
F_11 ( & V_2 -> V_98 -> V_50 ) ;
V_2 -> V_98 -> V_264 += V_2 -> V_45 ;
F_13 ( & V_2 -> V_98 -> V_50 ) ;
F_388 ( V_2 -> V_98 , V_2 ) ;
V_28 = F_10 ( V_34 -> V_36 , V_2 ) ;
F_22 ( V_28 ) ;
V_28 = F_398 ( V_84 , V_61 , & V_2 -> V_21 , & V_2 -> V_113 ,
sizeof( V_2 -> V_113 ) ) ;
F_22 ( V_28 ) ;
F_221 ( V_61 -> V_36 , type ) ;
return 0 ;
}
int F_399 ( struct V_83 * V_84 ,
struct V_33 * V_34 , T_2 V_110 )
{
struct V_62 * V_63 ;
struct V_1 * V_14 ;
struct V_404 * V_211 ;
struct V_33 * V_89 = V_34 -> V_36 -> V_89 ;
struct V_66 V_21 ;
struct V_236 * V_236 ;
int V_28 ;
int V_105 ;
V_34 = V_34 -> V_36 -> V_61 ;
V_14 = F_61 ( V_34 -> V_36 , V_110 ) ;
F_22 ( ! V_14 ) ;
F_22 ( ! V_14 -> V_114 ) ;
F_19 ( V_34 , V_14 ) ;
memcpy ( & V_21 , & V_14 -> V_21 , sizeof( V_21 ) ) ;
if ( V_14 -> V_6 & ( V_254 |
V_255 |
V_256 ) )
V_105 = 2 ;
else
V_105 = 1 ;
V_211 = & V_34 -> V_36 -> V_419 ;
F_11 ( & V_211 -> V_429 ) ;
F_313 ( V_14 , V_211 ) ;
F_13 ( & V_211 -> V_429 ) ;
V_211 = & V_34 -> V_36 -> V_417 ;
F_11 ( & V_211 -> V_429 ) ;
F_313 ( V_14 , V_211 ) ;
F_13 ( & V_211 -> V_429 ) ;
V_63 = F_32 () ;
if ( ! V_63 ) {
V_28 = - V_116 ;
goto V_70;
}
V_236 = F_201 ( V_34 , V_14 , V_63 ) ;
if ( ! F_202 ( V_236 ) ) {
V_28 = F_400 ( V_84 , V_236 ) ;
F_22 ( V_28 ) ;
F_401 ( V_236 ) ;
F_11 ( & V_14 -> V_50 ) ;
if ( V_14 -> V_163 ) {
V_14 -> V_163 = 0 ;
V_14 -> V_236 = NULL ;
F_13 ( & V_14 -> V_50 ) ;
F_213 ( V_236 ) ;
} else {
F_13 ( & V_14 -> V_50 ) ;
}
F_213 ( V_236 ) ;
}
V_21 . V_22 = V_497 ;
V_21 . V_32 = V_14 -> V_21 . V_22 ;
V_21 . type = 0 ;
V_28 = F_36 ( V_84 , V_89 , & V_21 , V_63 , - 1 , 1 ) ;
if ( V_28 < 0 )
goto V_70;
if ( V_28 > 0 )
F_43 ( V_63 ) ;
if ( V_28 == 0 ) {
V_28 = F_115 ( V_84 , V_89 , V_63 ) ;
if ( V_28 )
goto V_70;
F_43 ( V_63 ) ;
}
F_11 ( & V_34 -> V_36 -> V_18 ) ;
F_167 ( & V_14 -> V_20 ,
& V_34 -> V_36 -> V_19 ) ;
F_13 ( & V_34 -> V_36 -> V_18 ) ;
F_56 ( & V_14 -> V_98 -> V_261 ) ;
F_166 ( & V_14 -> V_91 ) ;
F_58 ( & V_14 -> V_98 -> V_261 ) ;
if ( V_14 -> V_3 == V_51 )
F_306 ( V_14 ) ;
F_386 ( V_14 ) ;
F_11 ( & V_14 -> V_98 -> V_50 ) ;
V_14 -> V_98 -> V_252 -= V_14 -> V_21 . V_32 ;
V_14 -> V_98 -> V_264 -= V_14 -> V_21 . V_32 ;
V_14 -> V_98 -> V_257 -= V_14 -> V_21 . V_32 * V_105 ;
F_13 ( & V_14 -> V_98 -> V_50 ) ;
memcpy ( & V_21 , & V_14 -> V_21 , sizeof( V_21 ) ) ;
F_66 ( V_34 -> V_36 ) ;
F_6 ( V_14 ) ;
F_6 ( V_14 ) ;
V_28 = F_36 ( V_84 , V_34 , & V_21 , V_63 , - 1 , 1 ) ;
if ( V_28 > 0 )
V_28 = - V_209 ;
if ( V_28 < 0 )
goto V_70;
V_28 = F_115 ( V_84 , V_34 , V_63 ) ;
V_70:
F_48 ( V_63 ) ;
return V_28 ;
}
int F_402 ( struct V_12 * V_36 )
{
struct V_95 * V_98 ;
struct V_498 * V_499 ;
T_2 V_500 ;
T_2 V_6 ;
int V_501 = 0 ;
int V_28 ;
V_499 = & V_36 -> V_304 ;
if ( ! F_403 ( V_499 ) )
return 1 ;
V_500 = F_404 ( V_499 ) ;
if ( V_500 & V_502 )
V_501 = 1 ;
V_6 = V_101 ;
V_28 = F_217 ( V_36 , V_6 , 0 , 0 , & V_98 ) ;
if ( V_28 )
goto V_70;
if ( V_501 ) {
V_6 = V_102 | V_100 ;
V_28 = F_217 ( V_36 , V_6 , 0 , 0 , & V_98 ) ;
} else {
V_6 = V_102 ;
V_28 = F_217 ( V_36 , V_6 , 0 , 0 , & V_98 ) ;
if ( V_28 )
goto V_70;
V_6 = V_100 ;
V_28 = F_217 ( V_36 , V_6 , 0 , 0 , & V_98 ) ;
}
V_70:
return V_28 ;
}
int F_405 ( struct V_33 * V_34 , T_2 V_31 , T_2 V_30 )
{
return F_287 ( V_34 , V_31 , V_30 ) ;
}
int F_406 ( struct V_33 * V_34 , T_2 V_26 ,
T_2 V_35 , T_2 * V_184 )
{
return F_141 ( V_34 , V_26 , V_35 , V_184 ) ;
}
int F_407 ( struct V_33 * V_34 , struct V_503 * V_504 )
{
struct V_12 * V_36 = V_34 -> V_36 ;
struct V_1 * V_2 = NULL ;
T_2 V_505 ;
T_2 V_31 ;
T_2 V_30 ;
T_2 V_506 = 0 ;
int V_28 = 0 ;
V_2 = F_61 ( V_36 , V_504 -> V_31 ) ;
while ( V_2 ) {
if ( V_2 -> V_21 . V_22 >= ( V_504 -> V_31 + V_504 -> V_115 ) ) {
F_6 ( V_2 ) ;
break;
}
V_31 = F_71 ( V_504 -> V_31 , V_2 -> V_21 . V_22 ) ;
V_30 = F_238 ( V_504 -> V_31 + V_504 -> V_115 ,
V_2 -> V_21 . V_22 + V_2 -> V_21 . V_32 ) ;
if ( V_30 - V_31 >= V_504 -> V_507 ) {
if ( ! F_1 ( V_2 ) ) {
V_28 = F_49 ( V_2 , NULL , V_34 , 0 ) ;
if ( ! V_28 )
F_306 ( V_2 ) ;
}
V_28 = F_408 ( V_2 ,
& V_505 ,
V_31 ,
V_30 ,
V_504 -> V_507 ) ;
V_506 += V_505 ;
if ( V_28 ) {
F_6 ( V_2 ) ;
break;
}
}
V_2 = F_199 ( V_36 -> V_89 , V_2 ) ;
}
V_504 -> V_115 = V_506 ;
return V_28 ;
}
