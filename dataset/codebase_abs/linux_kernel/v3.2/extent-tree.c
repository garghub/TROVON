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
V_6 &= V_102 | V_103 |
V_104 ;
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
V_101 -> V_105 = 0 ;
F_70 () ;
}
static T_2 F_72 ( T_2 V_106 , int V_107 )
{
if ( V_107 == 10 )
return V_106 ;
V_106 *= V_107 ;
F_73 ( V_106 , 10 ) ;
return V_106 ;
}
static T_2 F_74 ( T_2 V_106 , int V_107 )
{
if ( V_107 == 100 )
return V_106 ;
V_106 *= V_107 ;
F_73 ( V_106 , 100 ) ;
return V_106 ;
}
T_2 F_75 ( struct V_32 * V_33 ,
T_2 V_108 , T_2 V_109 , int V_110 )
{
struct V_1 * V_2 ;
T_2 V_111 ;
T_2 V_67 = F_76 ( V_109 , V_108 ) ;
T_2 V_112 = 0 ;
int V_113 = 0 ;
int V_107 = 9 ;
int V_114 = 0 ;
V_74:
while ( 1 ) {
V_2 = F_65 ( V_33 -> V_35 , V_67 ) ;
if ( ! V_2 )
break;
F_11 ( & V_2 -> V_49 ) ;
V_67 = V_2 -> V_20 . V_21 + V_2 -> V_20 . V_31 ;
V_111 = F_77 ( & V_2 -> V_115 ) ;
if ( ( V_113 || ! V_2 -> V_116 ) &&
F_3 ( V_2 , V_104 ) ) {
if ( V_111 + V_2 -> V_8 + V_2 -> V_9 <
F_72 ( V_2 -> V_20 . V_31 , V_107 ) ) {
V_112 = V_2 -> V_20 . V_21 ;
F_13 ( & V_2 -> V_49 ) ;
F_6 ( V_2 ) ;
goto V_101;
}
}
F_13 ( & V_2 -> V_49 ) ;
F_6 ( V_2 ) ;
F_46 () ;
}
if ( ! V_114 ) {
V_67 = V_108 ;
V_114 = 1 ;
goto V_74;
}
if ( ! V_113 && V_107 < 10 ) {
V_67 = V_108 ;
V_113 = 1 ;
V_107 = 10 ;
goto V_74;
}
V_101:
return V_112 ;
}
int F_78 ( struct V_32 * V_33 , T_2 V_30 , T_2 V_117 )
{
int V_27 ;
struct V_65 V_20 ;
struct V_61 * V_62 ;
V_62 = F_32 () ;
if ( ! V_62 )
return - V_118 ;
V_20 . V_21 = V_30 ;
V_20 . V_31 = V_117 ;
F_79 ( & V_20 , V_73 ) ;
V_27 = F_36 ( NULL , V_33 -> V_35 -> V_60 , & V_20 , V_62 ,
0 , 0 ) ;
F_48 ( V_62 ) ;
return V_27 ;
}
int F_80 ( struct V_82 * V_83 ,
struct V_32 * V_33 , T_2 V_25 ,
T_2 V_34 , T_2 * V_119 , T_2 * V_6 )
{
struct V_120 * V_99 ;
struct V_121 * V_122 ;
struct V_61 * V_62 ;
struct V_123 * V_124 ;
struct V_63 * V_64 ;
struct V_65 V_20 ;
T_3 V_125 ;
T_2 V_126 ;
T_2 V_127 ;
int V_27 ;
V_62 = F_32 () ;
if ( ! V_62 )
return - V_118 ;
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
goto V_128;
if ( V_27 == 0 ) {
V_64 = V_62 -> V_78 [ 0 ] ;
V_125 = F_81 ( V_64 , V_62 -> V_79 [ 0 ] ) ;
if ( V_125 >= sizeof( * V_124 ) ) {
V_124 = F_82 ( V_64 , V_62 -> V_79 [ 0 ] ,
struct V_123 ) ;
V_126 = F_83 ( V_64 , V_124 ) ;
V_127 = F_84 ( V_64 , V_124 ) ;
} else {
#ifdef F_85
struct V_129 * V_130 ;
F_22 ( V_125 != sizeof( * V_130 ) ) ;
V_130 = F_82 ( V_64 , V_62 -> V_79 [ 0 ] ,
struct V_129 ) ;
V_126 = F_86 ( V_64 , V_130 ) ;
V_127 = V_131 ;
#else
F_87 () ;
#endif
}
F_22 ( V_126 == 0 ) ;
} else {
V_126 = 0 ;
V_127 = 0 ;
V_27 = 0 ;
}
if ( ! V_83 )
goto V_69;
V_122 = & V_83 -> V_90 -> V_122 ;
F_11 ( & V_122 -> V_49 ) ;
V_99 = F_88 ( V_83 , V_25 ) ;
if ( V_99 ) {
if ( ! F_89 ( & V_99 -> V_75 ) ) {
F_5 ( & V_99 -> V_132 . V_119 ) ;
F_13 ( & V_122 -> V_49 ) ;
F_43 ( V_62 ) ;
F_34 ( & V_99 -> V_75 ) ;
F_45 ( & V_99 -> V_75 ) ;
F_90 ( & V_99 -> V_132 ) ;
goto V_74;
}
if ( V_99 -> V_133 && V_99 -> V_133 -> V_134 )
V_127 |= V_99 -> V_133 -> V_135 ;
else
F_22 ( V_126 == 0 ) ;
V_126 += V_99 -> V_132 . V_136 ;
F_45 ( & V_99 -> V_75 ) ;
}
F_13 ( & V_122 -> V_49 ) ;
V_69:
F_8 ( V_126 == 0 ) ;
if ( V_119 )
* V_119 = V_126 ;
if ( V_6 )
* V_6 = V_127 ;
V_128:
F_48 ( V_62 ) ;
return V_27 ;
}
static int F_91 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_61 * V_62 ,
T_2 V_110 , T_3 V_137 )
{
struct V_123 * V_115 ;
struct V_129 * V_130 ;
struct V_138 * V_139 ;
struct V_140 * V_141 ;
struct V_63 * V_64 ;
struct V_65 V_20 ;
struct V_65 V_142 ;
T_3 V_143 = sizeof( * V_115 ) ;
T_2 V_119 ;
int V_27 ;
V_64 = V_62 -> V_78 [ 0 ] ;
F_22 ( F_81 ( V_64 , V_62 -> V_79 [ 0 ] ) != sizeof( * V_130 ) ) ;
F_39 ( V_64 , & V_20 , V_62 -> V_79 [ 0 ] ) ;
V_130 = F_82 ( V_64 , V_62 -> V_79 [ 0 ] ,
struct V_129 ) ;
V_119 = F_86 ( V_64 , V_130 ) ;
if ( V_110 == ( T_2 ) - 1 ) {
while ( 1 ) {
if ( V_62 -> V_79 [ 0 ] >= F_37 ( V_64 ) ) {
V_27 = F_42 ( V_33 , V_62 ) ;
if ( V_27 < 0 )
return V_27 ;
F_22 ( V_27 > 0 ) ;
V_64 = V_62 -> V_78 [ 0 ] ;
}
F_39 ( V_64 , & V_142 ,
V_62 -> V_79 [ 0 ] ) ;
F_22 ( V_20 . V_21 != V_142 . V_21 ) ;
if ( V_142 . type != V_144 ) {
V_62 -> V_79 [ 0 ] ++ ;
continue;
}
V_139 = F_82 ( V_64 , V_62 -> V_79 [ 0 ] ,
struct V_138 ) ;
V_110 = F_92 ( V_64 , V_139 ) ;
break;
}
}
F_43 ( V_62 ) ;
if ( V_110 < V_145 )
V_143 += sizeof( * V_141 ) ;
V_143 -= sizeof( * V_130 ) ;
V_27 = F_36 ( V_83 , V_33 , & V_20 , V_62 ,
V_143 + V_137 , 1 ) ;
if ( V_27 < 0 )
return V_27 ;
F_22 ( V_27 ) ;
V_27 = F_93 ( V_83 , V_33 , V_62 , V_143 ) ;
V_64 = V_62 -> V_78 [ 0 ] ;
V_115 = F_82 ( V_64 , V_62 -> V_79 [ 0 ] , struct V_123 ) ;
F_94 ( V_64 , V_115 , V_119 ) ;
F_95 ( V_64 , V_115 , 0 ) ;
if ( V_110 < V_145 ) {
F_96 ( V_64 , V_115 ,
V_146 |
V_131 ) ;
V_141 = (struct V_140 * ) ( V_115 + 1 ) ;
F_97 ( V_64 , 0 , ( unsigned long ) V_141 , sizeof( * V_141 ) ) ;
F_98 ( V_64 , V_141 , ( int ) V_110 ) ;
} else {
F_96 ( V_64 , V_115 , V_147 ) ;
}
F_99 ( V_64 ) ;
return 0 ;
}
static T_2 F_100 ( T_2 V_148 , T_2 V_110 , T_2 V_31 )
{
T_3 V_149 = ~ ( T_3 ) 0 ;
T_3 V_150 = ~ ( T_3 ) 0 ;
T_4 V_151 ;
V_151 = F_101 ( V_148 ) ;
V_149 = F_102 ( V_149 , & V_151 , sizeof( V_151 ) ) ;
V_151 = F_101 ( V_110 ) ;
V_150 = F_102 ( V_150 , & V_151 , sizeof( V_151 ) ) ;
V_151 = F_101 ( V_31 ) ;
V_150 = F_102 ( V_150 , & V_151 , sizeof( V_151 ) ) ;
return ( ( T_2 ) V_149 << 31 ) ^ ( T_2 ) V_150 ;
}
static T_2 F_103 ( struct V_63 * V_64 ,
struct V_152 * V_153 )
{
return F_100 ( F_104 ( V_64 , V_153 ) ,
F_105 ( V_64 , V_153 ) ,
F_106 ( V_64 , V_153 ) ) ;
}
static int F_107 ( struct V_63 * V_64 ,
struct V_152 * V_153 ,
T_2 V_148 , T_2 V_110 , T_2 V_31 )
{
if ( F_104 ( V_64 , V_153 ) != V_148 ||
F_105 ( V_64 , V_153 ) != V_110 ||
F_106 ( V_64 , V_153 ) != V_31 )
return 0 ;
return 1 ;
}
static T_1 int F_108 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_61 * V_62 ,
T_2 V_25 , T_2 V_16 ,
T_2 V_148 ,
T_2 V_110 , T_2 V_31 )
{
struct V_65 V_20 ;
struct V_152 * V_153 ;
struct V_63 * V_64 ;
T_3 V_68 ;
int V_27 ;
int V_154 ;
int V_77 = - V_155 ;
V_20 . V_21 = V_25 ;
if ( V_16 ) {
V_20 . type = V_156 ;
V_20 . V_31 = V_16 ;
} else {
V_20 . type = V_157 ;
V_20 . V_31 = F_100 ( V_148 ,
V_110 , V_31 ) ;
}
V_74:
V_154 = 0 ;
V_27 = F_36 ( V_83 , V_33 , & V_20 , V_62 , - 1 , 1 ) ;
if ( V_27 < 0 ) {
V_77 = V_27 ;
goto V_158;
}
if ( V_16 ) {
if ( ! V_27 )
return 0 ;
#ifdef F_85
V_20 . type = V_144 ;
F_43 ( V_62 ) ;
V_27 = F_36 ( V_83 , V_33 , & V_20 , V_62 , - 1 , 1 ) ;
if ( V_27 < 0 ) {
V_77 = V_27 ;
goto V_158;
}
if ( ! V_27 )
return 0 ;
#endif
goto V_158;
}
V_64 = V_62 -> V_78 [ 0 ] ;
V_68 = F_37 ( V_64 ) ;
while ( 1 ) {
if ( V_62 -> V_79 [ 0 ] >= V_68 ) {
V_27 = F_42 ( V_33 , V_62 ) ;
if ( V_27 < 0 )
V_77 = V_27 ;
if ( V_27 )
goto V_158;
V_64 = V_62 -> V_78 [ 0 ] ;
V_68 = F_37 ( V_64 ) ;
V_154 = 1 ;
}
F_39 ( V_64 , & V_20 , V_62 -> V_79 [ 0 ] ) ;
if ( V_20 . V_21 != V_25 ||
V_20 . type != V_157 )
goto V_158;
V_153 = F_82 ( V_64 , V_62 -> V_79 [ 0 ] ,
struct V_152 ) ;
if ( F_107 ( V_64 , V_153 , V_148 ,
V_110 , V_31 ) ) {
if ( V_154 ) {
F_43 ( V_62 ) ;
goto V_74;
}
V_77 = 0 ;
break;
}
V_62 -> V_79 [ 0 ] ++ ;
}
V_158:
return V_77 ;
}
static T_1 int F_109 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_61 * V_62 ,
T_2 V_25 , T_2 V_16 ,
T_2 V_148 , T_2 V_110 ,
T_2 V_31 , int V_159 )
{
struct V_65 V_20 ;
struct V_63 * V_64 ;
T_3 V_54 ;
T_3 V_126 ;
int V_27 ;
V_20 . V_21 = V_25 ;
if ( V_16 ) {
V_20 . type = V_156 ;
V_20 . V_31 = V_16 ;
V_54 = sizeof( struct V_160 ) ;
} else {
V_20 . type = V_157 ;
V_20 . V_31 = F_100 ( V_148 ,
V_110 , V_31 ) ;
V_54 = sizeof( struct V_152 ) ;
}
V_27 = F_110 ( V_83 , V_33 , V_62 , & V_20 , V_54 ) ;
if ( V_27 && V_27 != - V_24 )
goto V_158;
V_64 = V_62 -> V_78 [ 0 ] ;
if ( V_16 ) {
struct V_160 * V_153 ;
V_153 = F_82 ( V_64 , V_62 -> V_79 [ 0 ] ,
struct V_160 ) ;
if ( V_27 == 0 ) {
F_111 ( V_64 , V_153 , V_159 ) ;
} else {
V_126 = F_112 ( V_64 , V_153 ) ;
V_126 += V_159 ;
F_111 ( V_64 , V_153 , V_126 ) ;
}
} else {
struct V_152 * V_153 ;
while ( V_27 == - V_24 ) {
V_153 = F_82 ( V_64 , V_62 -> V_79 [ 0 ] ,
struct V_152 ) ;
if ( F_107 ( V_64 , V_153 , V_148 ,
V_110 , V_31 ) )
break;
F_43 ( V_62 ) ;
V_20 . V_31 ++ ;
V_27 = F_110 ( V_83 , V_33 , V_62 , & V_20 ,
V_54 ) ;
if ( V_27 && V_27 != - V_24 )
goto V_158;
V_64 = V_62 -> V_78 [ 0 ] ;
}
V_153 = F_82 ( V_64 , V_62 -> V_79 [ 0 ] ,
struct V_152 ) ;
if ( V_27 == 0 ) {
F_113 ( V_64 , V_153 ,
V_148 ) ;
F_114 ( V_64 , V_153 , V_110 ) ;
F_115 ( V_64 , V_153 , V_31 ) ;
F_116 ( V_64 , V_153 , V_159 ) ;
} else {
V_126 = F_117 ( V_64 , V_153 ) ;
V_126 += V_159 ;
F_116 ( V_64 , V_153 , V_126 ) ;
}
}
F_99 ( V_64 ) ;
V_27 = 0 ;
V_158:
F_43 ( V_62 ) ;
return V_27 ;
}
static T_1 int F_118 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_61 * V_62 ,
int V_161 )
{
struct V_65 V_20 ;
struct V_152 * V_162 = NULL ;
struct V_160 * V_163 = NULL ;
struct V_63 * V_64 ;
T_3 V_126 = 0 ;
int V_27 = 0 ;
V_64 = V_62 -> V_78 [ 0 ] ;
F_39 ( V_64 , & V_20 , V_62 -> V_79 [ 0 ] ) ;
if ( V_20 . type == V_157 ) {
V_162 = F_82 ( V_64 , V_62 -> V_79 [ 0 ] ,
struct V_152 ) ;
V_126 = F_117 ( V_64 , V_162 ) ;
} else if ( V_20 . type == V_156 ) {
V_163 = F_82 ( V_64 , V_62 -> V_79 [ 0 ] ,
struct V_160 ) ;
V_126 = F_112 ( V_64 , V_163 ) ;
#ifdef F_85
} else if ( V_20 . type == V_144 ) {
struct V_138 * V_139 ;
V_139 = F_82 ( V_64 , V_62 -> V_79 [ 0 ] ,
struct V_138 ) ;
V_126 = F_119 ( V_64 , V_139 ) ;
#endif
} else {
F_87 () ;
}
F_22 ( V_126 < V_161 ) ;
V_126 -= V_161 ;
if ( V_126 == 0 ) {
V_27 = F_120 ( V_83 , V_33 , V_62 ) ;
} else {
if ( V_20 . type == V_157 )
F_116 ( V_64 , V_162 , V_126 ) ;
else if ( V_20 . type == V_156 )
F_111 ( V_64 , V_163 , V_126 ) ;
#ifdef F_85
else {
struct V_138 * V_139 ;
V_139 = F_82 ( V_64 , V_62 -> V_79 [ 0 ] ,
struct V_138 ) ;
F_121 ( V_64 , V_139 , V_126 ) ;
}
#endif
F_99 ( V_64 ) ;
}
return V_27 ;
}
static T_1 T_3 F_122 ( struct V_32 * V_33 ,
struct V_61 * V_62 ,
struct V_164 * V_165 )
{
struct V_65 V_20 ;
struct V_63 * V_64 ;
struct V_152 * V_162 ;
struct V_160 * V_163 ;
T_3 V_126 = 0 ;
V_64 = V_62 -> V_78 [ 0 ] ;
F_39 ( V_64 , & V_20 , V_62 -> V_79 [ 0 ] ) ;
if ( V_165 ) {
if ( F_123 ( V_64 , V_165 ) ==
V_157 ) {
V_162 = (struct V_152 * ) ( & V_165 -> V_31 ) ;
V_126 = F_117 ( V_64 , V_162 ) ;
} else {
V_163 = (struct V_160 * ) ( V_165 + 1 ) ;
V_126 = F_112 ( V_64 , V_163 ) ;
}
} else if ( V_20 . type == V_157 ) {
V_162 = F_82 ( V_64 , V_62 -> V_79 [ 0 ] ,
struct V_152 ) ;
V_126 = F_117 ( V_64 , V_162 ) ;
} else if ( V_20 . type == V_156 ) {
V_163 = F_82 ( V_64 , V_62 -> V_79 [ 0 ] ,
struct V_160 ) ;
V_126 = F_112 ( V_64 , V_163 ) ;
#ifdef F_85
} else if ( V_20 . type == V_144 ) {
struct V_138 * V_139 ;
V_139 = F_82 ( V_64 , V_62 -> V_79 [ 0 ] ,
struct V_138 ) ;
V_126 = F_119 ( V_64 , V_139 ) ;
#endif
} else {
F_8 ( 1 ) ;
}
return V_126 ;
}
static T_1 int F_124 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_61 * V_62 ,
T_2 V_25 , T_2 V_16 ,
T_2 V_148 )
{
struct V_65 V_20 ;
int V_27 ;
V_20 . V_21 = V_25 ;
if ( V_16 ) {
V_20 . type = V_166 ;
V_20 . V_31 = V_16 ;
} else {
V_20 . type = V_167 ;
V_20 . V_31 = V_148 ;
}
V_27 = F_36 ( V_83 , V_33 , & V_20 , V_62 , - 1 , 1 ) ;
if ( V_27 > 0 )
V_27 = - V_155 ;
#ifdef F_85
if ( V_27 == - V_155 && V_16 ) {
F_43 ( V_62 ) ;
V_20 . type = V_144 ;
V_27 = F_36 ( V_83 , V_33 , & V_20 , V_62 , - 1 , 1 ) ;
if ( V_27 > 0 )
V_27 = - V_155 ;
}
#endif
return V_27 ;
}
static T_1 int F_125 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_61 * V_62 ,
T_2 V_25 , T_2 V_16 ,
T_2 V_148 )
{
struct V_65 V_20 ;
int V_27 ;
V_20 . V_21 = V_25 ;
if ( V_16 ) {
V_20 . type = V_166 ;
V_20 . V_31 = V_16 ;
} else {
V_20 . type = V_167 ;
V_20 . V_31 = V_148 ;
}
V_27 = F_110 ( V_83 , V_33 , V_62 , & V_20 , 0 ) ;
F_43 ( V_62 ) ;
return V_27 ;
}
static inline int F_126 ( T_2 V_16 , T_2 V_110 )
{
int type ;
if ( V_110 < V_145 ) {
if ( V_16 > 0 )
type = V_166 ;
else
type = V_167 ;
} else {
if ( V_16 > 0 )
type = V_156 ;
else
type = V_157 ;
}
return type ;
}
static int F_40 ( struct V_61 * V_62 , int V_168 ,
struct V_65 * V_20 )
{
for (; V_168 < V_169 ; V_168 ++ ) {
if ( ! V_62 -> V_78 [ V_168 ] )
break;
if ( V_62 -> V_79 [ V_168 ] + 1 >=
F_37 ( V_62 -> V_78 [ V_168 ] ) )
continue;
if ( V_168 == 0 )
F_39 ( V_62 -> V_78 [ V_168 ] , V_20 ,
V_62 -> V_79 [ V_168 ] + 1 ) ;
else
F_127 ( V_62 -> V_78 [ V_168 ] , V_20 ,
V_62 -> V_79 [ V_168 ] + 1 ) ;
return 0 ;
}
return 1 ;
}
static T_5
int F_128 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_61 * V_62 ,
struct V_164 * * V_170 ,
T_2 V_25 , T_2 V_34 ,
T_2 V_16 , T_2 V_148 ,
T_2 V_110 , T_2 V_31 , int V_171 )
{
struct V_65 V_20 ;
struct V_63 * V_64 ;
struct V_123 * V_124 ;
struct V_164 * V_165 ;
T_2 V_6 ;
T_2 V_125 ;
unsigned long V_172 ;
unsigned long V_29 ;
int V_137 ;
int type ;
int V_173 ;
int V_27 ;
int V_77 = 0 ;
V_20 . V_21 = V_25 ;
V_20 . type = V_73 ;
V_20 . V_31 = V_34 ;
V_173 = F_126 ( V_16 , V_110 ) ;
if ( V_171 ) {
V_137 = F_129 ( V_173 ) ;
V_62 -> V_174 = 1 ;
} else
V_137 = - 1 ;
V_27 = F_36 ( V_83 , V_33 , & V_20 , V_62 , V_137 , 1 ) ;
if ( V_27 < 0 ) {
V_77 = V_27 ;
goto V_69;
}
F_22 ( V_27 ) ;
V_64 = V_62 -> V_78 [ 0 ] ;
V_125 = F_81 ( V_64 , V_62 -> V_79 [ 0 ] ) ;
#ifdef F_85
if ( V_125 < sizeof( * V_124 ) ) {
if ( ! V_171 ) {
V_77 = - V_155 ;
goto V_69;
}
V_27 = F_91 ( V_83 , V_33 , V_62 , V_110 ,
V_137 ) ;
if ( V_27 < 0 ) {
V_77 = V_27 ;
goto V_69;
}
V_64 = V_62 -> V_78 [ 0 ] ;
V_125 = F_81 ( V_64 , V_62 -> V_79 [ 0 ] ) ;
}
#endif
F_22 ( V_125 < sizeof( * V_124 ) ) ;
V_124 = F_82 ( V_64 , V_62 -> V_79 [ 0 ] , struct V_123 ) ;
V_6 = F_84 ( V_64 , V_124 ) ;
V_172 = ( unsigned long ) ( V_124 + 1 ) ;
V_29 = ( unsigned long ) V_124 + V_125 ;
if ( V_6 & V_146 ) {
V_172 += sizeof( struct V_140 ) ;
F_22 ( V_172 > V_29 ) ;
} else {
F_22 ( ! ( V_6 & V_147 ) ) ;
}
V_77 = - V_155 ;
while ( 1 ) {
if ( V_172 >= V_29 ) {
F_8 ( V_172 > V_29 ) ;
break;
}
V_165 = (struct V_164 * ) V_172 ;
type = F_123 ( V_64 , V_165 ) ;
if ( V_173 < type )
break;
if ( V_173 > type ) {
V_172 += F_129 ( type ) ;
continue;
}
if ( type == V_157 ) {
struct V_152 * V_175 ;
V_175 = (struct V_152 * ) ( & V_165 -> V_31 ) ;
if ( F_107 ( V_64 , V_175 , V_148 ,
V_110 , V_31 ) ) {
V_77 = 0 ;
break;
}
if ( F_103 ( V_64 , V_175 ) <
F_100 ( V_148 , V_110 , V_31 ) )
break;
} else {
T_2 V_176 ;
V_176 = F_130 ( V_64 , V_165 ) ;
if ( V_16 > 0 ) {
if ( V_16 == V_176 ) {
V_77 = 0 ;
break;
}
if ( V_176 < V_16 )
break;
} else {
if ( V_148 == V_176 ) {
V_77 = 0 ;
break;
}
if ( V_176 < V_148 )
break;
}
}
V_172 += F_129 ( type ) ;
}
if ( V_77 == - V_155 && V_171 ) {
if ( V_125 + V_137 >=
F_131 ( V_33 ) ) {
V_77 = - V_177 ;
goto V_69;
}
if ( F_40 ( V_62 , 0 , & V_20 ) == 0 &&
V_20 . V_21 == V_25 &&
V_20 . type < V_178 ) {
V_77 = - V_177 ;
goto V_69;
}
}
* V_170 = (struct V_164 * ) V_172 ;
V_69:
if ( V_171 ) {
V_62 -> V_174 = 0 ;
F_132 ( V_62 , 1 ) ;
}
return V_77 ;
}
static T_5
int F_133 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_61 * V_62 ,
struct V_164 * V_165 ,
T_2 V_16 , T_2 V_148 ,
T_2 V_110 , T_2 V_31 , int V_159 ,
struct V_179 * V_133 )
{
struct V_63 * V_64 ;
struct V_123 * V_124 ;
unsigned long V_172 ;
unsigned long V_29 ;
unsigned long V_180 ;
T_2 V_119 ;
int V_54 ;
int type ;
int V_27 ;
V_64 = V_62 -> V_78 [ 0 ] ;
V_124 = F_82 ( V_64 , V_62 -> V_79 [ 0 ] , struct V_123 ) ;
V_180 = ( unsigned long ) V_165 - ( unsigned long ) V_124 ;
type = F_126 ( V_16 , V_110 ) ;
V_54 = F_129 ( type ) ;
V_27 = F_93 ( V_83 , V_33 , V_62 , V_54 ) ;
V_124 = F_82 ( V_64 , V_62 -> V_79 [ 0 ] , struct V_123 ) ;
V_119 = F_83 ( V_64 , V_124 ) ;
V_119 += V_159 ;
F_94 ( V_64 , V_124 , V_119 ) ;
if ( V_133 )
F_134 ( V_133 , V_64 , V_124 ) ;
V_172 = ( unsigned long ) V_124 + V_180 ;
V_29 = ( unsigned long ) V_124 + F_81 ( V_64 , V_62 -> V_79 [ 0 ] ) ;
if ( V_172 < V_29 - V_54 )
F_135 ( V_64 , V_172 + V_54 , V_172 ,
V_29 - V_54 - V_172 ) ;
V_165 = (struct V_164 * ) V_172 ;
F_136 ( V_64 , V_165 , type ) ;
if ( type == V_157 ) {
struct V_152 * V_175 ;
V_175 = (struct V_152 * ) ( & V_165 -> V_31 ) ;
F_113 ( V_64 , V_175 , V_148 ) ;
F_114 ( V_64 , V_175 , V_110 ) ;
F_115 ( V_64 , V_175 , V_31 ) ;
F_116 ( V_64 , V_175 , V_159 ) ;
} else if ( type == V_156 ) {
struct V_160 * V_181 ;
V_181 = (struct V_160 * ) ( V_165 + 1 ) ;
F_111 ( V_64 , V_181 , V_159 ) ;
F_137 ( V_64 , V_165 , V_16 ) ;
} else if ( type == V_166 ) {
F_137 ( V_64 , V_165 , V_16 ) ;
} else {
F_137 ( V_64 , V_165 , V_148 ) ;
}
F_99 ( V_64 ) ;
return 0 ;
}
static int F_138 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_61 * V_62 ,
struct V_164 * * V_170 ,
T_2 V_25 , T_2 V_34 , T_2 V_16 ,
T_2 V_148 , T_2 V_110 , T_2 V_31 )
{
int V_27 ;
V_27 = F_128 ( V_83 , V_33 , V_62 , V_170 ,
V_25 , V_34 , V_16 ,
V_148 , V_110 , V_31 , 0 ) ;
if ( V_27 != - V_155 )
return V_27 ;
F_43 ( V_62 ) ;
* V_170 = NULL ;
if ( V_110 < V_145 ) {
V_27 = F_124 ( V_83 , V_33 , V_62 , V_25 , V_16 ,
V_148 ) ;
} else {
V_27 = F_108 ( V_83 , V_33 , V_62 , V_25 , V_16 ,
V_148 , V_110 , V_31 ) ;
}
return V_27 ;
}
static T_5
int F_139 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_61 * V_62 ,
struct V_164 * V_165 ,
int V_182 ,
struct V_179 * V_133 )
{
struct V_63 * V_64 ;
struct V_123 * V_124 ;
struct V_152 * V_175 = NULL ;
struct V_160 * V_181 = NULL ;
unsigned long V_172 ;
unsigned long V_29 ;
T_3 V_125 ;
int V_54 ;
int type ;
int V_27 ;
T_2 V_119 ;
V_64 = V_62 -> V_78 [ 0 ] ;
V_124 = F_82 ( V_64 , V_62 -> V_79 [ 0 ] , struct V_123 ) ;
V_119 = F_83 ( V_64 , V_124 ) ;
F_8 ( V_182 < 0 && V_119 + V_182 <= 0 ) ;
V_119 += V_182 ;
F_94 ( V_64 , V_124 , V_119 ) ;
if ( V_133 )
F_134 ( V_133 , V_64 , V_124 ) ;
type = F_123 ( V_64 , V_165 ) ;
if ( type == V_157 ) {
V_175 = (struct V_152 * ) ( & V_165 -> V_31 ) ;
V_119 = F_117 ( V_64 , V_175 ) ;
} else if ( type == V_156 ) {
V_181 = (struct V_160 * ) ( V_165 + 1 ) ;
V_119 = F_112 ( V_64 , V_181 ) ;
} else {
V_119 = 1 ;
F_22 ( V_182 != - 1 ) ;
}
F_22 ( V_182 < 0 && V_119 < - V_182 ) ;
V_119 += V_182 ;
if ( V_119 > 0 ) {
if ( type == V_157 )
F_116 ( V_64 , V_175 , V_119 ) ;
else
F_111 ( V_64 , V_181 , V_119 ) ;
} else {
V_54 = F_129 ( type ) ;
V_125 = F_81 ( V_64 , V_62 -> V_79 [ 0 ] ) ;
V_172 = ( unsigned long ) V_165 ;
V_29 = ( unsigned long ) V_124 + V_125 ;
if ( V_172 + V_54 < V_29 )
F_135 ( V_64 , V_172 , V_172 + V_54 ,
V_29 - V_172 - V_54 ) ;
V_125 -= V_54 ;
V_27 = F_140 ( V_83 , V_33 , V_62 , V_125 , 1 ) ;
}
F_99 ( V_64 ) ;
return 0 ;
}
static T_5
int F_141 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_61 * V_62 ,
T_2 V_25 , T_2 V_34 , T_2 V_16 ,
T_2 V_148 , T_2 V_110 ,
T_2 V_31 , int V_159 ,
struct V_179 * V_133 )
{
struct V_164 * V_165 ;
int V_27 ;
V_27 = F_128 ( V_83 , V_33 , V_62 , & V_165 ,
V_25 , V_34 , V_16 ,
V_148 , V_110 , V_31 , 1 ) ;
if ( V_27 == 0 ) {
F_22 ( V_110 < V_145 ) ;
V_27 = F_139 ( V_83 , V_33 , V_62 , V_165 ,
V_159 , V_133 ) ;
} else if ( V_27 == - V_155 ) {
V_27 = F_133 ( V_83 , V_33 , V_62 , V_165 ,
V_16 , V_148 ,
V_110 , V_31 , V_159 ,
V_133 ) ;
}
return V_27 ;
}
static int F_142 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_61 * V_62 ,
T_2 V_25 , T_2 V_16 , T_2 V_148 ,
T_2 V_110 , T_2 V_31 , int V_159 )
{
int V_27 ;
if ( V_110 < V_145 ) {
F_22 ( V_159 != 1 ) ;
V_27 = F_125 ( V_83 , V_33 , V_62 , V_25 ,
V_16 , V_148 ) ;
} else {
V_27 = F_109 ( V_83 , V_33 , V_62 , V_25 ,
V_16 , V_148 ,
V_110 , V_31 , V_159 ) ;
}
return V_27 ;
}
static int F_143 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_61 * V_62 ,
struct V_164 * V_165 ,
int V_161 , int V_183 )
{
int V_27 ;
F_22 ( ! V_183 && V_161 != 1 ) ;
if ( V_165 ) {
V_27 = F_139 ( V_83 , V_33 , V_62 , V_165 ,
- V_161 , NULL ) ;
} else if ( V_183 ) {
V_27 = F_118 ( V_83 , V_33 , V_62 , V_161 ) ;
} else {
V_27 = F_120 ( V_83 , V_33 , V_62 ) ;
}
return V_27 ;
}
static int F_144 ( struct V_184 * V_185 ,
T_2 V_30 , T_2 V_117 )
{
return F_145 ( V_185 , V_30 >> 9 , V_117 >> 9 , V_38 , 0 ) ;
}
static int F_146 ( struct V_32 * V_33 , T_2 V_25 ,
T_2 V_34 , T_2 * V_186 )
{
int V_27 ;
T_2 V_187 = 0 ;
struct V_188 * V_189 = NULL ;
V_27 = F_147 ( & V_33 -> V_35 -> V_46 , V_190 ,
V_25 , & V_34 , & V_189 , 0 ) ;
if ( ! V_27 ) {
struct V_191 * V_192 = V_189 -> V_193 ;
int V_41 ;
for ( V_41 = 0 ; V_41 < V_189 -> V_194 ; V_41 ++ , V_192 ++ ) {
if ( ! V_192 -> V_195 -> V_196 )
continue;
V_27 = F_144 ( V_192 -> V_195 -> V_185 ,
V_192 -> V_197 ,
V_192 -> V_198 ) ;
if ( ! V_27 )
V_187 += V_192 -> V_198 ;
else if ( V_27 != - V_199 )
break;
V_27 = 0 ;
}
F_9 ( V_189 ) ;
}
if ( V_186 )
* V_186 = V_187 ;
return V_27 ;
}
int F_148 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
T_2 V_25 , T_2 V_34 , T_2 V_16 ,
T_2 V_148 , T_2 V_110 , T_2 V_31 )
{
int V_27 ;
F_22 ( V_110 < V_145 &&
V_148 == V_200 ) ;
if ( V_110 < V_145 ) {
V_27 = F_149 ( V_83 , V_25 , V_34 ,
V_16 , V_148 , ( int ) V_110 ,
V_201 , NULL ) ;
} else {
V_27 = F_150 ( V_83 , V_25 , V_34 ,
V_16 , V_148 , V_110 , V_31 ,
V_201 , NULL ) ;
}
return V_27 ;
}
static int F_151 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
T_2 V_25 , T_2 V_34 ,
T_2 V_16 , T_2 V_148 ,
T_2 V_110 , T_2 V_31 , int V_159 ,
struct V_179 * V_133 )
{
struct V_61 * V_62 ;
struct V_63 * V_64 ;
struct V_123 * V_115 ;
T_2 V_119 ;
int V_27 ;
int V_77 = 0 ;
V_62 = F_32 () ;
if ( ! V_62 )
return - V_118 ;
V_62 -> V_72 = 1 ;
V_62 -> V_202 = 1 ;
V_27 = F_141 ( V_83 , V_33 -> V_35 -> V_60 ,
V_62 , V_25 , V_34 , V_16 ,
V_148 , V_110 , V_31 ,
V_159 , V_133 ) ;
if ( V_27 == 0 )
goto V_69;
if ( V_27 != - V_177 ) {
V_77 = V_27 ;
goto V_69;
}
V_64 = V_62 -> V_78 [ 0 ] ;
V_115 = F_82 ( V_64 , V_62 -> V_79 [ 0 ] , struct V_123 ) ;
V_119 = F_83 ( V_64 , V_115 ) ;
F_94 ( V_64 , V_115 , V_119 + V_159 ) ;
if ( V_133 )
F_134 ( V_133 , V_64 , V_115 ) ;
F_99 ( V_64 ) ;
F_43 ( V_62 ) ;
V_62 -> V_72 = 1 ;
V_62 -> V_202 = 1 ;
V_27 = F_142 ( V_83 , V_33 -> V_35 -> V_60 ,
V_62 , V_25 , V_16 , V_148 ,
V_110 , V_31 , V_159 ) ;
F_22 ( V_27 ) ;
V_69:
F_48 ( V_62 ) ;
return V_77 ;
}
static int F_152 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_203 * V_132 ,
struct V_179 * V_133 ,
int V_204 )
{
int V_27 = 0 ;
struct V_205 * V_153 ;
struct V_65 V_206 ;
T_2 V_16 = 0 ;
T_2 V_207 = 0 ;
T_2 V_6 = 0 ;
V_206 . V_21 = V_132 -> V_25 ;
V_206 . V_31 = V_132 -> V_34 ;
V_206 . type = V_73 ;
V_153 = F_153 ( V_132 ) ;
if ( V_132 -> type == V_156 )
V_16 = V_153 -> V_16 ;
else
V_207 = V_153 -> V_33 ;
if ( V_132 -> V_208 == V_201 && V_204 ) {
if ( V_133 ) {
F_22 ( V_133 -> V_209 ) ;
V_6 |= V_133 -> V_135 ;
}
V_27 = F_154 ( V_83 , V_33 ,
V_16 , V_207 , V_6 ,
V_153 -> V_21 , V_153 -> V_31 ,
& V_206 , V_132 -> V_136 ) ;
} else if ( V_132 -> V_208 == V_201 ) {
V_27 = F_151 ( V_83 , V_33 , V_132 -> V_25 ,
V_132 -> V_34 , V_16 ,
V_207 , V_153 -> V_21 ,
V_153 -> V_31 , V_132 -> V_136 ,
V_133 ) ;
} else if ( V_132 -> V_208 == V_210 ) {
V_27 = F_155 ( V_83 , V_33 , V_132 -> V_25 ,
V_132 -> V_34 , V_16 ,
V_207 , V_153 -> V_21 ,
V_153 -> V_31 , V_132 -> V_136 ,
V_133 ) ;
} else {
F_87 () ;
}
return V_27 ;
}
static void F_134 ( struct V_179 * V_133 ,
struct V_63 * V_64 ,
struct V_123 * V_124 )
{
T_2 V_6 = F_84 ( V_64 , V_124 ) ;
if ( V_133 -> V_134 ) {
V_6 |= V_133 -> V_135 ;
F_96 ( V_64 , V_124 , V_6 ) ;
}
if ( V_133 -> V_209 ) {
struct V_140 * V_141 ;
F_22 ( ! ( V_6 & V_146 ) ) ;
V_141 = (struct V_140 * ) ( V_124 + 1 ) ;
F_156 ( V_64 , V_141 , & V_133 -> V_20 ) ;
}
}
static int F_157 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_203 * V_132 ,
struct V_179 * V_133 )
{
struct V_65 V_20 ;
struct V_61 * V_62 ;
struct V_123 * V_124 ;
struct V_63 * V_64 ;
T_3 V_125 ;
int V_27 ;
int V_77 = 0 ;
V_62 = F_32 () ;
if ( ! V_62 )
return - V_118 ;
V_20 . V_21 = V_132 -> V_25 ;
V_20 . type = V_73 ;
V_20 . V_31 = V_132 -> V_34 ;
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
V_125 = F_81 ( V_64 , V_62 -> V_79 [ 0 ] ) ;
#ifdef F_85
if ( V_125 < sizeof( * V_124 ) ) {
V_27 = F_91 ( V_83 , V_33 -> V_35 -> V_60 ,
V_62 , ( T_2 ) - 1 , 0 ) ;
if ( V_27 < 0 ) {
V_77 = V_27 ;
goto V_69;
}
V_64 = V_62 -> V_78 [ 0 ] ;
V_125 = F_81 ( V_64 , V_62 -> V_79 [ 0 ] ) ;
}
#endif
F_22 ( V_125 < sizeof( * V_124 ) ) ;
V_124 = F_82 ( V_64 , V_62 -> V_79 [ 0 ] , struct V_123 ) ;
F_134 ( V_133 , V_64 , V_124 ) ;
F_99 ( V_64 ) ;
V_69:
F_48 ( V_62 ) ;
return V_77 ;
}
static int F_158 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_203 * V_132 ,
struct V_179 * V_133 ,
int V_204 )
{
int V_27 = 0 ;
struct V_212 * V_153 ;
struct V_65 V_206 ;
T_2 V_16 = 0 ;
T_2 V_207 = 0 ;
V_206 . V_21 = V_132 -> V_25 ;
V_206 . V_31 = V_132 -> V_34 ;
V_206 . type = V_73 ;
V_153 = F_159 ( V_132 ) ;
if ( V_132 -> type == V_166 )
V_16 = V_153 -> V_16 ;
else
V_207 = V_153 -> V_33 ;
F_22 ( V_132 -> V_136 != 1 ) ;
if ( V_132 -> V_208 == V_201 && V_204 ) {
F_22 ( ! V_133 || ! V_133 -> V_134 ||
! V_133 -> V_209 ) ;
V_27 = F_160 ( V_83 , V_33 ,
V_16 , V_207 ,
V_133 -> V_135 ,
& V_133 -> V_20 ,
V_153 -> V_168 , & V_206 ) ;
} else if ( V_132 -> V_208 == V_201 ) {
V_27 = F_151 ( V_83 , V_33 , V_132 -> V_25 ,
V_132 -> V_34 , V_16 , V_207 ,
V_153 -> V_168 , 0 , 1 , V_133 ) ;
} else if ( V_132 -> V_208 == V_210 ) {
V_27 = F_155 ( V_83 , V_33 , V_132 -> V_25 ,
V_132 -> V_34 , V_16 , V_207 ,
V_153 -> V_168 , 0 , 1 , V_133 ) ;
} else {
F_87 () ;
}
return V_27 ;
}
static int F_161 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_203 * V_132 ,
struct V_179 * V_133 ,
int V_204 )
{
int V_27 ;
if ( F_162 ( V_132 ) ) {
struct V_120 * V_99 ;
F_22 ( V_133 ) ;
V_99 = F_163 ( V_132 ) ;
if ( V_204 ) {
F_164 ( V_33 , V_132 -> V_25 ,
V_132 -> V_34 , 1 ) ;
if ( V_99 -> V_183 ) {
V_27 = F_165 ( V_83 , V_33 ,
V_132 -> V_25 ,
V_132 -> V_34 ) ;
F_22 ( V_27 ) ;
}
}
F_45 ( & V_99 -> V_75 ) ;
return 0 ;
}
if ( V_132 -> type == V_167 ||
V_132 -> type == V_166 )
V_27 = F_158 ( V_83 , V_33 , V_132 , V_133 ,
V_204 ) ;
else if ( V_132 -> type == V_157 ||
V_132 -> type == V_156 )
V_27 = F_152 ( V_83 , V_33 , V_132 , V_133 ,
V_204 ) ;
else
F_87 () ;
return V_27 ;
}
T_1 int F_166 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_98 * V_213 )
{
struct V_121 * V_122 ;
struct V_203 * V_153 ;
struct V_120 * V_214 = NULL ;
struct V_179 * V_133 ;
int V_27 ;
int V_7 = 0 ;
int V_215 = 0 ;
V_122 = & V_83 -> V_90 -> V_122 ;
while ( 1 ) {
if ( ! V_214 ) {
if ( F_167 ( V_213 ) )
break;
V_214 = F_168 ( V_213 -> V_216 ,
struct V_120 , V_213 ) ;
V_27 = F_169 ( V_83 , V_214 ) ;
if ( V_27 == - V_177 ) {
V_214 = NULL ;
V_7 ++ ;
continue;
}
}
V_215 = V_214 -> V_215 ;
V_214 -> V_215 = 0 ;
V_133 = V_214 -> V_133 ;
V_214 -> V_133 = NULL ;
V_153 = F_170 ( V_214 ) ;
if ( ! V_153 ) {
V_153 = & V_214 -> V_132 ;
if ( V_133 && V_215 ) {
F_9 ( V_133 ) ;
V_133 = NULL ;
}
if ( V_133 ) {
F_13 ( & V_122 -> V_49 ) ;
V_27 = F_157 ( V_83 , V_33 ,
V_153 , V_133 ) ;
F_22 ( V_27 ) ;
F_9 ( V_133 ) ;
F_46 () ;
F_11 ( & V_122 -> V_49 ) ;
continue;
}
F_171 ( & V_214 -> V_213 ) ;
V_214 = NULL ;
}
V_153 -> V_217 = 0 ;
F_172 ( & V_153 -> V_14 , & V_122 -> V_33 ) ;
V_122 -> V_218 -- ;
F_13 ( & V_122 -> V_49 ) ;
V_27 = F_161 ( V_83 , V_33 , V_153 , V_133 ,
V_215 ) ;
F_22 ( V_27 ) ;
F_90 ( V_153 ) ;
F_9 ( V_133 ) ;
V_7 ++ ;
F_46 () ;
F_11 ( & V_122 -> V_49 ) ;
}
return V_7 ;
}
int F_173 ( struct V_82 * V_83 ,
struct V_32 * V_33 , unsigned long V_7 )
{
struct V_14 * V_132 ;
struct V_121 * V_122 ;
struct V_203 * V_153 ;
struct V_98 V_213 ;
int V_27 ;
int V_219 = V_7 == ( unsigned long ) - 1 ;
int V_220 = 0 ;
if ( V_33 == V_33 -> V_35 -> V_60 )
V_33 = V_33 -> V_35 -> V_92 ;
V_122 = & V_83 -> V_90 -> V_122 ;
F_52 ( & V_213 ) ;
V_74:
F_11 ( & V_122 -> V_49 ) ;
if ( V_7 == 0 ) {
V_7 = V_122 -> V_218 * 2 ;
V_220 = 1 ;
}
while ( 1 ) {
if ( ! ( V_219 || V_220 ) &&
V_122 -> V_221 < 64 )
break;
V_27 = F_174 ( V_83 , & V_213 ,
V_122 -> V_222 ) ;
if ( V_27 )
break;
V_27 = F_166 ( V_83 , V_33 , & V_213 ) ;
F_22 ( V_27 < 0 ) ;
V_7 -= F_175 (unsigned long, ret, count) ;
if ( V_7 == 0 )
break;
}
if ( V_219 ) {
V_132 = F_176 ( & V_122 -> V_33 ) ;
if ( ! V_132 )
goto V_69;
V_7 = ( unsigned long ) - 1 ;
while ( V_132 ) {
V_153 = F_12 ( V_132 , struct V_203 ,
V_14 ) ;
if ( F_162 ( V_153 ) ) {
struct V_120 * V_99 ;
V_99 = F_163 ( V_153 ) ;
F_5 ( & V_153 -> V_119 ) ;
F_13 ( & V_122 -> V_49 ) ;
F_34 ( & V_99 -> V_75 ) ;
F_45 ( & V_99 -> V_75 ) ;
F_90 ( V_153 ) ;
F_46 () ;
goto V_74;
}
V_132 = F_177 ( V_132 ) ;
}
F_13 ( & V_122 -> V_49 ) ;
F_178 ( 1 ) ;
goto V_74;
}
V_69:
F_13 ( & V_122 -> V_49 ) ;
return 0 ;
}
int F_179 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
T_2 V_25 , T_2 V_34 , T_2 V_6 ,
int V_183 )
{
struct V_179 * V_133 ;
int V_27 ;
V_133 = F_180 ( sizeof( * V_133 ) , V_38 ) ;
if ( ! V_133 )
return - V_118 ;
V_133 -> V_135 = V_6 ;
V_133 -> V_134 = 1 ;
V_133 -> V_209 = 0 ;
V_133 -> V_183 = V_183 ? 1 : 0 ;
V_27 = F_181 ( V_83 , V_25 , V_34 , V_133 ) ;
if ( V_27 )
F_9 ( V_133 ) ;
return V_27 ;
}
static T_1 int F_182 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_61 * V_62 ,
T_2 V_21 , T_2 V_31 , T_2 V_25 )
{
struct V_120 * V_99 ;
struct V_203 * V_153 ;
struct V_205 * V_223 ;
struct V_121 * V_122 ;
struct V_14 * V_132 ;
int V_27 = 0 ;
V_27 = - V_155 ;
V_122 = & V_83 -> V_90 -> V_122 ;
F_11 ( & V_122 -> V_49 ) ;
V_99 = F_88 ( V_83 , V_25 ) ;
if ( ! V_99 )
goto V_69;
if ( ! F_89 ( & V_99 -> V_75 ) ) {
F_5 ( & V_99 -> V_132 . V_119 ) ;
F_13 ( & V_122 -> V_49 ) ;
F_43 ( V_62 ) ;
F_34 ( & V_99 -> V_75 ) ;
F_45 ( & V_99 -> V_75 ) ;
F_90 ( & V_99 -> V_132 ) ;
return - V_177 ;
}
V_132 = F_183 ( & V_99 -> V_132 . V_14 ) ;
if ( ! V_132 )
goto V_224;
V_153 = F_12 ( V_132 , struct V_203 , V_14 ) ;
if ( V_153 -> V_25 != V_25 )
goto V_224;
V_27 = 1 ;
if ( V_153 -> type != V_157 )
goto V_224;
V_223 = F_153 ( V_153 ) ;
V_132 = F_183 ( V_132 ) ;
if ( V_132 ) {
V_153 = F_12 ( V_132 , struct V_203 , V_14 ) ;
if ( V_153 -> V_25 == V_25 )
goto V_224;
}
if ( V_223 -> V_33 != V_33 -> V_225 . V_21 ||
V_223 -> V_21 != V_21 || V_223 -> V_31 != V_31 )
goto V_224;
V_27 = 0 ;
V_224:
F_45 ( & V_99 -> V_75 ) ;
V_69:
F_13 ( & V_122 -> V_49 ) ;
return V_27 ;
}
static T_1 int F_184 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_61 * V_62 ,
T_2 V_21 , T_2 V_31 , T_2 V_25 )
{
struct V_32 * V_60 = V_33 -> V_35 -> V_60 ;
struct V_63 * V_64 ;
struct V_152 * V_153 ;
struct V_164 * V_165 ;
struct V_123 * V_124 ;
struct V_65 V_20 ;
T_3 V_125 ;
int V_27 ;
V_20 . V_21 = V_25 ;
V_20 . V_31 = ( T_2 ) - 1 ;
V_20 . type = V_73 ;
V_27 = F_36 ( NULL , V_60 , & V_20 , V_62 , 0 , 0 ) ;
if ( V_27 < 0 )
goto V_69;
F_22 ( V_27 == 0 ) ;
V_27 = - V_155 ;
if ( V_62 -> V_79 [ 0 ] == 0 )
goto V_69;
V_62 -> V_79 [ 0 ] -- ;
V_64 = V_62 -> V_78 [ 0 ] ;
F_39 ( V_64 , & V_20 , V_62 -> V_79 [ 0 ] ) ;
if ( V_20 . V_21 != V_25 || V_20 . type != V_73 )
goto V_69;
V_27 = 1 ;
V_125 = F_81 ( V_64 , V_62 -> V_79 [ 0 ] ) ;
#ifdef F_85
if ( V_125 < sizeof( * V_124 ) ) {
F_8 ( V_125 != sizeof( struct V_129 ) ) ;
goto V_69;
}
#endif
V_124 = F_82 ( V_64 , V_62 -> V_79 [ 0 ] , struct V_123 ) ;
if ( V_125 != sizeof( * V_124 ) +
F_129 ( V_157 ) )
goto V_69;
if ( F_185 ( V_64 , V_124 ) <=
F_186 ( & V_33 -> V_226 ) )
goto V_69;
V_165 = (struct V_164 * ) ( V_124 + 1 ) ;
if ( F_123 ( V_64 , V_165 ) !=
V_157 )
goto V_69;
V_153 = (struct V_152 * ) ( & V_165 -> V_31 ) ;
if ( F_83 ( V_64 , V_124 ) !=
F_117 ( V_64 , V_153 ) ||
F_104 ( V_64 , V_153 ) !=
V_33 -> V_225 . V_21 ||
F_105 ( V_64 , V_153 ) != V_21 ||
F_106 ( V_64 , V_153 ) != V_31 )
goto V_69;
V_27 = 0 ;
V_69:
return V_27 ;
}
int F_187 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
T_2 V_21 , T_2 V_31 , T_2 V_25 )
{
struct V_61 * V_62 ;
int V_27 ;
int V_227 ;
V_62 = F_32 () ;
if ( ! V_62 )
return - V_155 ;
do {
V_27 = F_184 ( V_83 , V_33 , V_62 , V_21 ,
V_31 , V_25 ) ;
if ( V_27 && V_27 != - V_155 )
goto V_69;
V_227 = F_182 ( V_83 , V_33 , V_62 , V_21 ,
V_31 , V_25 ) ;
} while ( V_227 == - V_177 );
if ( V_227 && V_227 != - V_155 ) {
V_27 = V_227 ;
goto V_69;
}
if ( V_27 != - V_155 || V_227 != - V_155 )
V_27 = 0 ;
V_69:
F_48 ( V_62 ) ;
if ( V_33 -> V_225 . V_21 == V_228 )
F_8 ( V_27 > 0 ) ;
return V_27 ;
}
static int F_188 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_63 * V_229 ,
int V_230 , int V_231 )
{
T_2 V_25 ;
T_2 V_34 ;
T_2 V_16 ;
T_2 V_207 ;
T_3 V_68 ;
struct V_65 V_20 ;
struct V_232 * V_233 ;
int V_41 ;
int V_168 ;
int V_27 = 0 ;
int (* F_189)( struct V_82 * , struct V_32 * ,
T_2 , T_2 , T_2 , T_2 , T_2 , T_2 );
V_207 = F_190 ( V_229 ) ;
V_68 = F_37 ( V_229 ) ;
V_168 = F_191 ( V_229 ) ;
if ( ! V_33 -> V_234 && V_168 == 0 )
return 0 ;
if ( V_231 )
F_189 = F_148 ;
else
F_189 = V_235 ;
if ( V_230 )
V_16 = V_229 -> V_30 ;
else
V_16 = 0 ;
for ( V_41 = 0 ; V_41 < V_68 ; V_41 ++ ) {
if ( V_168 == 0 ) {
F_39 ( V_229 , & V_20 , V_41 ) ;
if ( F_192 ( & V_20 ) != V_236 )
continue;
V_233 = F_82 ( V_229 , V_41 ,
struct V_232 ) ;
if ( F_193 ( V_229 , V_233 ) ==
V_237 )
continue;
V_25 = F_194 ( V_229 , V_233 ) ;
if ( V_25 == 0 )
continue;
V_34 = F_195 ( V_229 , V_233 ) ;
V_20 . V_31 -= F_196 ( V_229 , V_233 ) ;
V_27 = F_189 ( V_83 , V_33 , V_25 , V_34 ,
V_16 , V_207 , V_20 . V_21 ,
V_20 . V_31 ) ;
if ( V_27 )
goto V_158;
} else {
V_25 = F_197 ( V_229 , V_41 ) ;
V_34 = F_198 ( V_33 , V_168 - 1 ) ;
V_27 = F_189 ( V_83 , V_33 , V_25 , V_34 ,
V_16 , V_207 , V_168 - 1 , 0 ) ;
if ( V_27 )
goto V_158;
}
}
return 0 ;
V_158:
F_87 () ;
return V_27 ;
}
int F_199 ( struct V_82 * V_83 , struct V_32 * V_33 ,
struct V_63 * V_229 , int V_230 )
{
return F_188 ( V_83 , V_33 , V_229 , V_230 , 1 ) ;
}
int F_200 ( struct V_82 * V_83 , struct V_32 * V_33 ,
struct V_63 * V_229 , int V_230 )
{
return F_188 ( V_83 , V_33 , V_229 , V_230 , 0 ) ;
}
static int F_201 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_61 * V_62 ,
struct V_1 * V_2 )
{
int V_27 ;
struct V_32 * V_60 = V_33 -> V_35 -> V_60 ;
unsigned long V_141 ;
struct V_63 * V_64 ;
V_27 = F_36 ( V_83 , V_60 , & V_2 -> V_20 , V_62 , 0 , 1 ) ;
if ( V_27 < 0 )
goto V_158;
F_22 ( V_27 ) ;
V_64 = V_62 -> V_78 [ 0 ] ;
V_141 = F_202 ( V_64 , V_62 -> V_79 [ 0 ] ) ;
F_203 ( V_64 , & V_2 -> V_115 , V_141 , sizeof( V_2 -> V_115 ) ) ;
F_99 ( V_64 ) ;
F_43 ( V_62 ) ;
V_158:
if ( V_27 )
return V_27 ;
return 0 ;
}
static struct V_1 *
F_204 ( struct V_32 * V_33 ,
struct V_1 * V_2 )
{
struct V_14 * V_132 ;
F_11 ( & V_33 -> V_35 -> V_17 ) ;
V_132 = F_177 ( & V_2 -> V_19 ) ;
F_6 ( V_2 ) ;
if ( V_132 ) {
V_2 = F_12 ( V_132 , struct V_1 ,
V_19 ) ;
F_4 ( V_2 ) ;
} else
V_2 = NULL ;
F_13 ( & V_33 -> V_35 -> V_17 ) ;
return V_2 ;
}
static int F_205 ( struct V_1 * V_13 ,
struct V_82 * V_83 ,
struct V_61 * V_62 )
{
struct V_32 * V_33 = V_13 -> V_35 -> V_92 ;
struct V_238 * V_238 = NULL ;
T_2 V_239 = 0 ;
int V_240 = V_241 ;
int V_242 = 0 ;
int V_243 = 0 ;
int V_27 = 0 ;
if ( V_13 -> V_20 . V_31 < ( 100 * 1024 * 1024 ) ) {
F_11 ( & V_13 -> V_49 ) ;
V_13 -> V_244 = V_245 ;
F_13 ( & V_13 -> V_49 ) ;
return 0 ;
}
V_74:
V_238 = F_206 ( V_33 , V_13 , V_62 ) ;
if ( F_207 ( V_238 ) && F_208 ( V_238 ) != - V_155 ) {
V_27 = F_208 ( V_238 ) ;
F_43 ( V_62 ) ;
goto V_69;
}
if ( F_207 ( V_238 ) ) {
F_22 ( V_243 ) ;
V_243 ++ ;
if ( V_13 -> V_116 )
goto V_128;
V_27 = F_209 ( V_33 , V_83 , V_13 , V_62 ) ;
if ( V_27 )
goto V_128;
goto V_74;
}
if ( V_13 -> V_246 == V_83 -> V_247 &&
F_210 ( V_238 ) ) {
V_240 = V_248 ;
goto V_249;
}
F_211 ( V_238 ) -> V_250 = 0 ;
V_27 = F_212 ( V_83 , V_33 , V_238 ) ;
F_8 ( V_27 ) ;
if ( F_210 ( V_238 ) > 0 ) {
V_27 = F_213 ( V_33 , V_83 , V_62 ,
V_238 ) ;
if ( V_27 )
goto V_249;
}
F_11 ( & V_13 -> V_49 ) ;
if ( V_13 -> V_3 != V_4 ) {
V_240 = V_245 ;
F_13 ( & V_13 -> V_49 ) ;
goto V_249;
}
F_13 ( & V_13 -> V_49 ) ;
V_242 = ( int ) F_214 ( V_13 -> V_20 . V_31 , 1024 * 1024 * 1024 ) ;
if ( ! V_242 )
V_242 = 1 ;
V_242 *= 16 ;
V_242 *= V_251 ;
V_27 = F_215 ( V_238 , V_242 ) ;
if ( V_27 )
goto V_249;
V_27 = F_216 ( V_238 , V_83 , 0 , 0 , V_242 ,
V_242 , V_242 ,
& V_239 ) ;
if ( ! V_27 )
V_240 = V_248 ;
F_217 ( V_238 , V_242 ) ;
V_249:
F_218 ( V_238 ) ;
V_128:
F_43 ( V_62 ) ;
V_69:
F_11 ( & V_13 -> V_49 ) ;
if ( ! V_27 && V_240 == V_248 )
V_13 -> V_246 = V_83 -> V_247 ;
V_13 -> V_244 = V_240 ;
F_13 ( & V_13 -> V_49 ) ;
return V_27 ;
}
int F_219 ( struct V_82 * V_83 ,
struct V_32 * V_33 )
{
struct V_1 * V_2 ;
int V_77 = 0 ;
struct V_61 * V_62 ;
T_2 V_67 = 0 ;
V_62 = F_32 () ;
if ( ! V_62 )
return - V_118 ;
V_74:
while ( 1 ) {
V_2 = F_65 ( V_33 -> V_35 , V_67 ) ;
while ( V_2 ) {
if ( V_2 -> V_244 == V_252 )
break;
V_2 = F_204 ( V_33 , V_2 ) ;
}
if ( ! V_2 ) {
if ( V_67 == 0 )
break;
V_67 = 0 ;
continue;
}
V_77 = F_205 ( V_2 , V_83 , V_62 ) ;
V_67 = V_2 -> V_20 . V_21 + V_2 -> V_20 . V_31 ;
F_6 ( V_2 ) ;
}
while ( 1 ) {
if ( V_67 == 0 ) {
V_77 = F_173 ( V_83 , V_33 ,
( unsigned long ) - 1 ) ;
F_22 ( V_77 ) ;
}
V_2 = F_65 ( V_33 -> V_35 , V_67 ) ;
while ( V_2 ) {
if ( V_2 -> V_244 == V_252 ) {
F_6 ( V_2 ) ;
goto V_74;
}
if ( V_2 -> V_253 )
break;
V_2 = F_204 ( V_33 , V_2 ) ;
}
if ( ! V_2 ) {
if ( V_67 == 0 )
break;
V_67 = 0 ;
continue;
}
if ( V_2 -> V_244 == V_248 )
V_2 -> V_244 = V_254 ;
V_2 -> V_253 = 0 ;
V_67 = V_2 -> V_20 . V_21 + V_2 -> V_20 . V_31 ;
V_77 = F_201 ( V_83 , V_33 , V_62 , V_2 ) ;
F_22 ( V_77 ) ;
F_6 ( V_2 ) ;
}
while ( 1 ) {
if ( V_67 == 0 ) {
V_77 = F_173 ( V_83 , V_33 ,
( unsigned long ) - 1 ) ;
F_22 ( V_77 ) ;
}
V_2 = F_65 ( V_33 -> V_35 , V_67 ) ;
while ( V_2 ) {
if ( V_2 -> V_253 ) {
F_6 ( V_2 ) ;
goto V_74;
}
if ( V_2 -> V_244 == V_254 )
break;
V_2 = F_204 ( V_33 , V_2 ) ;
}
if ( ! V_2 ) {
if ( V_67 == 0 )
break;
V_67 = 0 ;
continue;
}
F_220 ( V_33 , V_83 , V_2 , V_62 ) ;
if ( V_2 -> V_244 == V_254 )
V_2 -> V_244 = V_245 ;
V_67 = V_2 -> V_20 . V_21 + V_2 -> V_20 . V_31 ;
F_6 ( V_2 ) ;
}
F_48 ( V_62 ) ;
return 0 ;
}
int F_221 ( struct V_32 * V_33 , T_2 V_25 )
{
struct V_1 * V_13 ;
int V_255 = 0 ;
V_13 = F_66 ( V_33 -> V_35 , V_25 ) ;
if ( ! V_13 || V_13 -> V_116 )
V_255 = 1 ;
if ( V_13 )
F_6 ( V_13 ) ;
return V_255 ;
}
static int F_222 ( struct V_11 * V_12 , T_2 V_6 ,
T_2 V_256 , T_2 V_257 ,
struct V_97 * * V_100 )
{
struct V_97 * V_101 ;
int V_41 ;
int V_107 ;
if ( V_6 & ( V_258 | V_259 |
V_260 ) )
V_107 = 2 ;
else
V_107 = 1 ;
V_101 = F_67 ( V_12 , V_6 ) ;
if ( V_101 ) {
F_11 ( & V_101 -> V_49 ) ;
V_101 -> V_256 += V_256 ;
V_101 -> V_261 += V_256 * V_107 ;
V_101 -> V_257 += V_257 ;
V_101 -> V_262 += V_257 * V_107 ;
V_101 -> V_105 = 0 ;
F_13 ( & V_101 -> V_49 ) ;
* V_100 = V_101 ;
return 0 ;
}
V_101 = F_51 ( sizeof( * V_101 ) , V_38 ) ;
if ( ! V_101 )
return - V_118 ;
for ( V_41 = 0 ; V_41 < V_263 ; V_41 ++ )
F_52 ( & V_101 -> V_264 [ V_41 ] ) ;
F_223 ( & V_101 -> V_265 ) ;
F_224 ( & V_101 -> V_49 ) ;
V_101 -> V_6 = V_6 & ( V_102 |
V_103 |
V_104 ) ;
V_101 -> V_256 = V_256 ;
V_101 -> V_261 = V_256 * V_107 ;
V_101 -> V_257 = V_257 ;
V_101 -> V_262 = V_257 * V_107 ;
V_101 -> V_266 = 0 ;
V_101 -> V_267 = 0 ;
V_101 -> V_268 = 0 ;
V_101 -> V_269 = 0 ;
V_101 -> V_105 = 0 ;
V_101 -> V_270 = V_271 ;
V_101 -> V_272 = 0 ;
V_101 -> V_273 = 0 ;
F_54 ( & V_101 -> V_81 ) ;
* V_100 = V_101 ;
F_225 ( & V_101 -> V_85 , & V_12 -> V_100 ) ;
return 0 ;
}
static void F_226 ( struct V_11 * V_35 , T_2 V_6 )
{
T_2 V_274 = V_6 & ( V_275 |
V_259 |
V_260 |
V_258 ) ;
if ( V_274 ) {
if ( V_6 & V_102 )
V_35 -> V_276 |= V_274 ;
if ( V_6 & V_104 )
V_35 -> V_277 |= V_274 ;
if ( V_6 & V_103 )
V_35 -> V_278 |= V_274 ;
}
}
T_2 F_227 ( struct V_32 * V_33 , T_2 V_6 )
{
T_2 V_279 = V_33 -> V_35 -> V_280 -> V_281 +
V_33 -> V_35 -> V_280 -> V_282 ;
if ( V_279 == 1 )
V_6 &= ~ ( V_259 | V_275 ) ;
if ( V_279 < 4 )
V_6 &= ~ V_260 ;
if ( ( V_6 & V_258 ) &&
( V_6 & ( V_259 |
V_260 ) ) ) {
V_6 &= ~ V_258 ;
}
if ( ( V_6 & V_259 ) &&
( V_6 & V_260 ) ) {
V_6 &= ~ V_259 ;
}
if ( ( V_6 & V_275 ) &&
( ( V_6 & V_259 ) |
( V_6 & V_260 ) |
( V_6 & V_258 ) ) )
V_6 &= ~ V_275 ;
return V_6 ;
}
static T_2 F_228 ( struct V_32 * V_33 , T_2 V_6 )
{
if ( V_6 & V_102 )
V_6 |= V_33 -> V_35 -> V_276 &
V_33 -> V_35 -> V_283 ;
else if ( V_6 & V_103 )
V_6 |= V_33 -> V_35 -> V_278 &
V_33 -> V_35 -> V_284 ;
else if ( V_6 & V_104 )
V_6 |= V_33 -> V_35 -> V_277 &
V_33 -> V_35 -> V_285 ;
return F_227 ( V_33 , V_6 ) ;
}
T_2 F_229 ( struct V_32 * V_33 , int V_286 )
{
T_2 V_6 ;
if ( V_286 )
V_6 = V_102 ;
else if ( V_33 == V_33 -> V_35 -> V_287 )
V_6 = V_103 ;
else
V_6 = V_104 ;
return F_228 ( V_33 , V_6 ) ;
}
void F_230 ( struct V_32 * V_33 , struct V_238 * V_238 )
{
F_211 ( V_238 ) -> V_100 = F_67 ( V_33 -> V_35 ,
V_102 ) ;
}
int F_215 ( struct V_238 * V_238 , T_2 V_288 )
{
struct V_97 * V_289 ;
struct V_32 * V_33 = F_211 ( V_238 ) -> V_33 ;
T_2 V_111 ;
int V_27 = 0 , V_290 = 0 , V_291 = 1 ;
V_288 = ( V_288 + V_33 -> V_292 - 1 ) & ~ ( ( T_2 ) V_33 -> V_292 - 1 ) ;
if ( V_33 == V_33 -> V_35 -> V_92 ||
F_211 ( V_238 ) -> V_293 . V_21 == V_294 ) {
V_291 = 0 ;
V_290 = 1 ;
}
V_289 = F_211 ( V_238 ) -> V_100 ;
if ( ! V_289 )
goto V_295;
V_74:
F_11 ( & V_289 -> V_49 ) ;
V_111 = V_289 -> V_257 + V_289 -> V_267 +
V_289 -> V_266 + V_289 -> V_268 +
V_289 -> V_269 ;
if ( V_111 + V_288 > V_289 -> V_256 ) {
struct V_82 * V_83 ;
if ( ! V_289 -> V_105 && V_291 ) {
T_2 V_296 ;
V_289 -> V_270 = V_297 ;
F_13 ( & V_289 -> V_49 ) ;
V_295:
V_296 = F_229 ( V_33 , 1 ) ;
V_83 = F_231 ( V_33 ) ;
if ( F_207 ( V_83 ) )
return F_208 ( V_83 ) ;
V_27 = F_232 ( V_83 , V_33 -> V_35 -> V_60 ,
V_288 + 2 * 1024 * 1024 ,
V_296 ,
V_271 ) ;
F_233 ( V_83 , V_33 ) ;
if ( V_27 < 0 ) {
if ( V_27 != - V_298 )
return V_27 ;
else
goto V_299;
}
if ( ! V_289 ) {
F_230 ( V_33 , V_238 ) ;
V_289 = F_211 ( V_238 ) -> V_100 ;
}
goto V_74;
}
if ( V_289 -> V_266 < V_288 )
V_290 = 1 ;
F_13 ( & V_289 -> V_49 ) ;
V_299:
if ( ! V_290 &&
! F_234 ( & V_33 -> V_35 -> V_300 ) ) {
V_290 = 1 ;
V_83 = F_231 ( V_33 ) ;
if ( F_207 ( V_83 ) )
return F_208 ( V_83 ) ;
V_27 = F_235 ( V_83 , V_33 ) ;
if ( V_27 )
return V_27 ;
goto V_74;
}
return - V_298 ;
}
V_289 -> V_269 += V_288 ;
F_13 ( & V_289 -> V_49 ) ;
return 0 ;
}
void F_217 ( struct V_238 * V_238 , T_2 V_288 )
{
struct V_32 * V_33 = F_211 ( V_238 ) -> V_33 ;
struct V_97 * V_289 ;
V_288 = ( V_288 + V_33 -> V_292 - 1 ) & ~ ( ( T_2 ) V_33 -> V_292 - 1 ) ;
V_289 = F_211 ( V_238 ) -> V_100 ;
F_11 ( & V_289 -> V_49 ) ;
V_289 -> V_269 -= V_288 ;
F_13 ( & V_289 -> V_49 ) ;
}
static void F_236 ( struct V_11 * V_12 )
{
struct V_98 * V_99 = & V_12 -> V_100 ;
struct V_97 * V_101 ;
F_68 () ;
F_69 (found, head, list) {
if ( V_101 -> V_6 & V_104 )
V_101 -> V_270 = V_297 ;
}
F_70 () ;
}
static int F_237 ( struct V_32 * V_33 ,
struct V_97 * V_301 , T_2 V_302 ,
int V_303 )
{
struct V_304 * V_305 = & V_33 -> V_35 -> V_306 ;
T_2 V_34 = V_301 -> V_256 - V_301 -> V_268 ;
T_2 V_307 = V_301 -> V_257 + V_301 -> V_267 ;
T_2 V_308 ;
if ( V_303 == V_297 )
return 1 ;
V_307 += V_305 -> V_54 ;
if ( V_303 == V_309 ) {
V_308 = F_238 ( V_33 -> V_35 -> V_310 ) ;
V_308 = F_33 ( T_2 , 64 * 1024 * 1024 ,
F_74 ( V_308 , 1 ) ) ;
if ( V_34 - V_307 < V_308 )
return 1 ;
}
if ( V_307 + V_302 + 256 * 1024 * 1024 < V_34 )
return 0 ;
if ( V_307 + V_302 < F_72 ( V_34 , 8 ) )
return 0 ;
V_308 = F_238 ( V_33 -> V_35 -> V_310 ) ;
V_308 = F_33 ( T_2 , 256 * 1024 * 1024 , F_74 ( V_308 , 5 ) ) ;
if ( V_34 > V_308 && V_301 -> V_257 < F_72 ( V_34 , 3 ) )
return 0 ;
return 1 ;
}
static int F_232 ( struct V_82 * V_83 ,
struct V_32 * V_60 , T_2 V_302 ,
T_2 V_6 , int V_303 )
{
struct V_97 * V_100 ;
struct V_11 * V_35 = V_60 -> V_35 ;
int V_311 = 0 ;
int V_27 = 0 ;
V_6 = F_227 ( V_60 , V_6 ) ;
V_100 = F_67 ( V_60 -> V_35 , V_6 ) ;
if ( ! V_100 ) {
V_27 = F_222 ( V_60 -> V_35 , V_6 ,
0 , 0 , & V_100 ) ;
F_22 ( V_27 ) ;
}
F_22 ( ! V_100 ) ;
V_74:
F_11 ( & V_100 -> V_49 ) ;
if ( V_100 -> V_270 )
V_303 = V_100 -> V_270 ;
if ( V_100 -> V_105 ) {
F_13 ( & V_100 -> V_49 ) ;
return 0 ;
}
if ( ! F_237 ( V_60 , V_100 , V_302 , V_303 ) ) {
F_13 ( & V_100 -> V_49 ) ;
return 0 ;
} else if ( V_100 -> V_272 ) {
V_311 = 1 ;
} else {
V_100 -> V_272 = 1 ;
}
F_13 ( & V_100 -> V_49 ) ;
F_34 ( & V_35 -> V_312 ) ;
if ( V_311 ) {
F_45 ( & V_35 -> V_312 ) ;
V_311 = 0 ;
goto V_74;
}
if ( F_239 ( V_100 ) )
V_6 |= ( V_102 | V_104 ) ;
if ( V_6 & V_102 && V_35 -> V_313 ) {
V_35 -> V_314 ++ ;
if ( ! ( V_35 -> V_314 %
V_35 -> V_313 ) )
F_236 ( V_35 ) ;
}
V_27 = F_240 ( V_83 , V_60 , V_6 ) ;
if ( V_27 < 0 && V_27 != - V_298 )
goto V_69;
F_11 ( & V_100 -> V_49 ) ;
if ( V_27 )
V_100 -> V_105 = 1 ;
else
V_27 = 1 ;
V_100 -> V_270 = V_271 ;
V_100 -> V_272 = 0 ;
F_13 ( & V_100 -> V_49 ) ;
V_69:
F_45 ( & V_60 -> V_35 -> V_312 ) ;
return V_27 ;
}
static int F_241 ( struct V_32 * V_33 , T_2 V_315 ,
bool V_316 )
{
struct V_304 * V_317 ;
struct V_97 * V_100 ;
struct V_82 * V_83 ;
T_2 V_9 ;
T_2 V_318 ;
T_2 V_319 = 0 ;
long V_320 ;
unsigned long V_321 = ( 2 * 1024 * 1024 ) >> V_322 ;
int V_323 = 0 ;
unsigned long V_80 ;
V_83 = (struct V_82 * ) V_324 -> V_325 ;
V_317 = & V_33 -> V_35 -> V_326 ;
V_100 = V_317 -> V_100 ;
F_2 () ;
V_9 = V_100 -> V_269 ;
V_80 = V_100 -> V_327 ;
if ( V_9 == 0 )
return 0 ;
F_2 () ;
if ( V_33 -> V_35 -> V_328 == 0 ) {
if ( V_83 )
return 0 ;
F_242 ( V_33 , 0 , 0 ) ;
return 0 ;
}
V_318 = F_243 ( V_9 , V_315 ) ;
V_321 = F_33 (unsigned long, nr_pages,
max_reclaim >> PAGE_CACHE_SHIFT) ;
while ( V_323 < 1024 ) {
F_2 () ;
V_321 = F_175 (unsigned long, nr_pages,
root->fs_info->delalloc_bytes >> PAGE_CACHE_SHIFT) ;
F_244 ( V_33 -> V_35 -> V_329 , V_321 ,
V_330 ) ;
F_11 ( & V_100 -> V_49 ) ;
if ( V_9 > V_100 -> V_269 )
V_319 += V_9 - V_100 -> V_269 ;
V_9 = V_100 -> V_269 ;
F_13 ( & V_100 -> V_49 ) ;
V_323 ++ ;
if ( V_9 == 0 || V_319 >= V_318 )
break;
if ( V_83 && V_83 -> V_90 -> V_331 )
return - V_177 ;
if ( V_316 && ! V_83 ) {
F_242 ( V_33 , 0 , 0 ) ;
} else {
V_320 = F_245 ( 1 ) ;
if ( V_320 )
break;
}
if ( V_323 > 3 ) {
F_2 () ;
if ( V_80 != V_100 -> V_327 )
break;
}
}
return V_319 >= V_315 ;
}
static int F_246 ( struct V_32 * V_33 ,
struct V_97 * V_100 ,
T_2 V_288 , int V_303 )
{
struct V_304 * V_332 = & V_33 -> V_35 -> V_333 ;
struct V_82 * V_83 ;
V_83 = (struct V_82 * ) V_324 -> V_325 ;
if ( V_83 )
return - V_177 ;
if ( V_303 )
goto V_334;
F_11 ( & V_100 -> V_49 ) ;
if ( V_100 -> V_266 >= V_288 ) {
F_13 ( & V_100 -> V_49 ) ;
goto V_334;
}
F_13 ( & V_100 -> V_49 ) ;
if ( V_100 != V_332 -> V_100 )
return - V_298 ;
F_11 ( & V_332 -> V_49 ) ;
if ( V_332 -> V_54 < V_288 ) {
F_13 ( & V_332 -> V_49 ) ;
return - V_298 ;
}
F_13 ( & V_332 -> V_49 ) ;
V_334:
V_83 = F_231 ( V_33 ) ;
if ( F_207 ( V_83 ) )
return - V_298 ;
return F_235 ( V_83 , V_33 ) ;
}
static int F_247 ( struct V_32 * V_33 ,
struct V_304 * V_317 ,
T_2 V_335 , int V_273 )
{
struct V_97 * V_100 = V_317 -> V_100 ;
T_2 V_111 ;
T_2 V_34 = V_335 ;
int V_243 = 0 ;
int V_27 = 0 ;
bool V_290 = false ;
bool V_336 = false ;
bool V_316 = false ;
V_74:
V_27 = 0 ;
F_11 ( & V_100 -> V_49 ) ;
while ( V_273 && ! V_336 && V_100 -> V_273 ) {
F_13 ( & V_100 -> V_49 ) ;
if ( V_324 -> V_325 )
return - V_177 ;
V_27 = F_248 ( V_100 -> V_81 ,
! V_100 -> V_273 ) ;
if ( V_27 )
return - V_337 ;
F_11 ( & V_100 -> V_49 ) ;
}
V_27 = - V_298 ;
V_111 = V_100 -> V_257 + V_100 -> V_267 +
V_100 -> V_266 + V_100 -> V_268 +
V_100 -> V_269 ;
if ( V_111 <= V_100 -> V_256 ) {
if ( V_111 + V_335 <= V_100 -> V_256 ) {
V_100 -> V_269 += V_335 ;
V_27 = 0 ;
} else {
V_34 = V_335 ;
}
} else {
V_316 = true ;
V_34 = V_111 - V_100 -> V_256 +
( V_335 * ( V_243 + 1 ) ) ;
}
if ( V_27 ) {
T_2 V_338 = F_229 ( V_33 , 0 ) ;
T_2 V_339 ;
V_339 = ( V_100 -> V_256 - V_100 -> V_257 ) * 8 ;
F_73 ( V_339 , 10 ) ;
if ( V_100 -> V_266 >= V_339 && V_273 && ! V_290 ) {
V_100 -> V_273 = 1 ;
V_336 = true ;
F_13 ( & V_100 -> V_49 ) ;
V_27 = F_246 ( V_33 , V_100 ,
V_335 , 1 ) ;
if ( V_27 )
goto V_69;
V_290 = true ;
goto V_74;
}
F_11 ( & V_33 -> V_35 -> V_340 ) ;
V_339 = V_33 -> V_35 -> V_341 ;
if ( V_338 & ( V_258 |
V_259 |
V_260 ) )
V_339 >>= 1 ;
if ( V_273 )
V_339 >>= 3 ;
else
V_339 >>= 1 ;
F_13 ( & V_33 -> V_35 -> V_340 ) ;
if ( V_111 + V_34 < V_100 -> V_256 + V_339 ) {
V_100 -> V_269 += V_335 ;
V_27 = 0 ;
} else {
V_316 = true ;
}
}
if ( V_27 && V_273 ) {
V_336 = true ;
V_100 -> V_273 = 1 ;
}
F_13 ( & V_100 -> V_49 ) ;
if ( ! V_27 || ! V_273 )
goto V_69;
V_27 = F_241 ( V_33 , V_34 , V_316 ) ;
if ( V_27 < 0 )
goto V_69;
V_27 = 0 ;
if ( V_243 < 2 ) {
V_316 = true ;
V_243 ++ ;
goto V_74;
}
V_27 = - V_298 ;
if ( V_290 )
goto V_69;
V_27 = F_246 ( V_33 , V_100 , V_335 , 0 ) ;
if ( ! V_27 ) {
V_290 = true ;
goto V_74;
}
V_69:
if ( V_336 ) {
F_11 ( & V_100 -> V_49 ) ;
V_100 -> V_273 = 0 ;
F_249 ( & V_100 -> V_81 ) ;
F_13 ( & V_100 -> V_49 ) ;
}
return V_27 ;
}
static struct V_304 * F_250 ( struct V_82 * V_83 ,
struct V_32 * V_33 )
{
struct V_304 * V_317 = NULL ;
if ( V_33 -> V_234 || V_33 == V_33 -> V_35 -> V_342 )
V_317 = V_83 -> V_317 ;
if ( ! V_317 )
V_317 = V_33 -> V_317 ;
if ( ! V_317 )
V_317 = & V_33 -> V_35 -> V_343 ;
return V_317 ;
}
static int F_251 ( struct V_304 * V_317 ,
T_2 V_34 )
{
int V_27 = - V_298 ;
F_11 ( & V_317 -> V_49 ) ;
if ( V_317 -> V_9 >= V_34 ) {
V_317 -> V_9 -= V_34 ;
if ( V_317 -> V_9 < V_317 -> V_54 )
V_317 -> V_105 = 0 ;
V_27 = 0 ;
}
F_13 ( & V_317 -> V_49 ) ;
return V_27 ;
}
static void F_252 ( struct V_304 * V_317 ,
T_2 V_34 , int V_344 )
{
F_11 ( & V_317 -> V_49 ) ;
V_317 -> V_9 += V_34 ;
if ( V_344 )
V_317 -> V_54 += V_34 ;
else if ( V_317 -> V_9 >= V_317 -> V_54 )
V_317 -> V_105 = 1 ;
F_13 ( & V_317 -> V_49 ) ;
}
static void F_253 ( struct V_304 * V_317 ,
struct V_304 * V_345 , T_2 V_34 )
{
struct V_97 * V_100 = V_317 -> V_100 ;
F_11 ( & V_317 -> V_49 ) ;
if ( V_34 == ( T_2 ) - 1 )
V_34 = V_317 -> V_54 ;
V_317 -> V_54 -= V_34 ;
if ( V_317 -> V_9 >= V_317 -> V_54 ) {
V_34 = V_317 -> V_9 - V_317 -> V_54 ;
V_317 -> V_9 = V_317 -> V_54 ;
V_317 -> V_105 = 1 ;
} else {
V_34 = 0 ;
}
F_13 ( & V_317 -> V_49 ) ;
if ( V_34 > 0 ) {
if ( V_345 ) {
F_11 ( & V_345 -> V_49 ) ;
if ( ! V_345 -> V_105 ) {
T_2 V_346 ;
V_346 = V_345 -> V_54 - V_345 -> V_9 ;
V_346 = F_243 ( V_34 , V_346 ) ;
V_345 -> V_9 += V_346 ;
if ( V_345 -> V_9 >= V_345 -> V_54 )
V_345 -> V_105 = 1 ;
V_34 -= V_346 ;
}
F_13 ( & V_345 -> V_49 ) ;
}
if ( V_34 ) {
F_11 ( & V_100 -> V_49 ) ;
V_100 -> V_269 -= V_34 ;
V_100 -> V_327 ++ ;
F_13 ( & V_100 -> V_49 ) ;
}
}
}
static int F_254 ( struct V_304 * V_347 ,
struct V_304 * V_348 , T_2 V_34 )
{
int V_27 ;
V_27 = F_251 ( V_347 , V_34 ) ;
if ( V_27 )
return V_27 ;
F_252 ( V_348 , V_34 , 1 ) ;
return 0 ;
}
void F_255 ( struct V_304 * V_349 )
{
memset ( V_349 , 0 , sizeof( * V_349 ) ) ;
F_224 ( & V_349 -> V_49 ) ;
}
struct V_304 * F_256 ( struct V_32 * V_33 )
{
struct V_304 * V_317 ;
struct V_11 * V_35 = V_33 -> V_35 ;
V_317 = F_180 ( sizeof( * V_317 ) , V_38 ) ;
if ( ! V_317 )
return NULL ;
F_255 ( V_317 ) ;
V_317 -> V_100 = F_67 ( V_35 ,
V_104 ) ;
return V_317 ;
}
void F_257 ( struct V_32 * V_33 ,
struct V_304 * V_349 )
{
F_258 ( V_33 , V_349 , ( T_2 ) - 1 ) ;
F_9 ( V_349 ) ;
}
static inline int F_259 ( struct V_32 * V_33 ,
struct V_304 * V_317 ,
T_2 V_34 , int V_273 )
{
int V_27 ;
if ( V_34 == 0 )
return 0 ;
V_27 = F_247 ( V_33 , V_317 , V_34 , V_273 ) ;
if ( ! V_27 ) {
F_252 ( V_317 , V_34 , 1 ) ;
return 0 ;
}
return V_27 ;
}
int F_260 ( struct V_32 * V_33 ,
struct V_304 * V_317 ,
T_2 V_34 )
{
return F_259 ( V_33 , V_317 , V_34 , 1 ) ;
}
int F_261 ( struct V_32 * V_33 ,
struct V_304 * V_317 ,
T_2 V_34 )
{
return F_259 ( V_33 , V_317 , V_34 , 0 ) ;
}
int F_262 ( struct V_32 * V_33 ,
struct V_304 * V_317 , int V_350 )
{
T_2 V_34 = 0 ;
int V_27 = - V_298 ;
if ( ! V_317 )
return 0 ;
F_11 ( & V_317 -> V_49 ) ;
V_34 = F_72 ( V_317 -> V_54 , V_350 ) ;
if ( V_317 -> V_9 >= V_34 )
V_27 = 0 ;
F_13 ( & V_317 -> V_49 ) ;
return V_27 ;
}
static inline int F_263 ( struct V_32 * V_33 ,
struct V_304 * V_317 ,
T_2 V_351 , int V_273 )
{
T_2 V_34 = 0 ;
int V_27 = - V_298 ;
if ( ! V_317 )
return 0 ;
F_11 ( & V_317 -> V_49 ) ;
V_34 = V_351 ;
if ( V_317 -> V_9 >= V_34 )
V_27 = 0 ;
else
V_34 -= V_317 -> V_9 ;
F_13 ( & V_317 -> V_49 ) ;
if ( ! V_27 )
return 0 ;
V_27 = F_247 ( V_33 , V_317 , V_34 , V_273 ) ;
if ( ! V_27 ) {
F_252 ( V_317 , V_34 , 0 ) ;
return 0 ;
}
return V_27 ;
}
int F_264 ( struct V_32 * V_33 ,
struct V_304 * V_317 ,
T_2 V_351 )
{
return F_263 ( V_33 , V_317 , V_351 , 1 ) ;
}
int F_265 ( struct V_32 * V_33 ,
struct V_304 * V_317 ,
T_2 V_351 )
{
return F_263 ( V_33 , V_317 , V_351 , 0 ) ;
}
int F_266 ( struct V_304 * V_352 ,
struct V_304 * V_353 ,
T_2 V_34 )
{
return F_254 ( V_352 , V_353 , V_34 ) ;
}
void F_258 ( struct V_32 * V_33 ,
struct V_304 * V_317 ,
T_2 V_34 )
{
struct V_304 * V_305 = & V_33 -> V_35 -> V_306 ;
if ( V_305 -> V_105 || V_305 == V_317 ||
V_317 -> V_100 != V_305 -> V_100 )
V_305 = NULL ;
F_253 ( V_317 , V_305 , V_34 ) ;
}
static T_2 F_267 ( struct V_11 * V_35 )
{
struct V_97 * V_301 ;
T_2 V_34 ;
T_2 V_354 ;
T_2 V_355 ;
int V_356 = F_268 ( V_35 -> V_310 ) ;
V_301 = F_67 ( V_35 , V_102 ) ;
F_11 ( & V_301 -> V_49 ) ;
V_355 = V_301 -> V_257 ;
F_13 ( & V_301 -> V_49 ) ;
V_301 = F_67 ( V_35 , V_104 ) ;
F_11 ( & V_301 -> V_49 ) ;
if ( V_301 -> V_6 & V_102 )
V_355 = 0 ;
V_354 = V_301 -> V_257 ;
F_13 ( & V_301 -> V_49 ) ;
V_34 = ( V_355 >> V_35 -> V_329 -> V_357 ) *
V_356 * 2 ;
V_34 += F_214 ( V_355 + V_354 , 50 ) ;
if ( V_34 * 3 > V_354 )
V_34 = F_214 ( V_354 , 3 ) ;
return F_269 ( V_34 , V_35 -> V_60 -> V_358 << 10 ) ;
}
static void F_270 ( struct V_11 * V_35 )
{
struct V_304 * V_317 = & V_35 -> V_306 ;
struct V_97 * V_301 = V_317 -> V_100 ;
T_2 V_34 ;
V_34 = F_267 ( V_35 ) ;
F_11 ( & V_317 -> V_49 ) ;
F_11 ( & V_301 -> V_49 ) ;
V_317 -> V_54 = V_34 ;
V_34 = V_301 -> V_257 + V_301 -> V_266 +
V_301 -> V_267 + V_301 -> V_268 +
V_301 -> V_269 ;
if ( V_301 -> V_256 > V_34 ) {
V_34 = V_301 -> V_256 - V_34 ;
V_317 -> V_9 += V_34 ;
V_301 -> V_269 += V_34 ;
}
if ( V_317 -> V_9 >= V_317 -> V_54 ) {
V_34 = V_317 -> V_9 - V_317 -> V_54 ;
V_301 -> V_269 -= V_34 ;
V_301 -> V_327 ++ ;
V_317 -> V_9 = V_317 -> V_54 ;
V_317 -> V_105 = 1 ;
}
F_13 ( & V_301 -> V_49 ) ;
F_13 ( & V_317 -> V_49 ) ;
}
static void F_271 ( struct V_11 * V_35 )
{
struct V_97 * V_100 ;
V_100 = F_67 ( V_35 , V_103 ) ;
V_35 -> V_359 . V_100 = V_100 ;
V_100 = F_67 ( V_35 , V_104 ) ;
V_35 -> V_306 . V_100 = V_100 ;
V_35 -> V_326 . V_100 = V_100 ;
V_35 -> V_360 . V_100 = V_100 ;
V_35 -> V_343 . V_100 = V_100 ;
V_35 -> V_333 . V_100 = V_100 ;
V_35 -> V_60 -> V_317 = & V_35 -> V_306 ;
V_35 -> V_342 -> V_317 = & V_35 -> V_306 ;
V_35 -> V_361 -> V_317 = & V_35 -> V_306 ;
V_35 -> V_92 -> V_317 = & V_35 -> V_306 ;
V_35 -> V_287 -> V_317 = & V_35 -> V_359 ;
F_270 ( V_35 ) ;
}
static void F_272 ( struct V_11 * V_35 )
{
F_253 ( & V_35 -> V_306 , NULL , ( T_2 ) - 1 ) ;
F_8 ( V_35 -> V_326 . V_54 > 0 ) ;
F_8 ( V_35 -> V_326 . V_9 > 0 ) ;
F_8 ( V_35 -> V_360 . V_54 > 0 ) ;
F_8 ( V_35 -> V_360 . V_9 > 0 ) ;
F_8 ( V_35 -> V_359 . V_54 > 0 ) ;
F_8 ( V_35 -> V_359 . V_9 > 0 ) ;
F_8 ( V_35 -> V_333 . V_54 > 0 ) ;
F_8 ( V_35 -> V_333 . V_9 > 0 ) ;
}
void F_273 ( struct V_82 * V_83 ,
struct V_32 * V_33 )
{
if ( ! V_83 -> V_267 )
return;
F_258 ( V_33 , V_83 -> V_317 , V_83 -> V_267 ) ;
V_83 -> V_267 = 0 ;
}
int F_274 ( struct V_82 * V_83 ,
struct V_238 * V_238 )
{
struct V_32 * V_33 = F_211 ( V_238 ) -> V_33 ;
struct V_304 * V_352 = F_250 ( V_83 , V_33 ) ;
struct V_304 * V_353 = V_33 -> V_362 ;
T_2 V_34 = F_275 ( V_33 , 1 ) ;
return F_254 ( V_352 , V_353 , V_34 ) ;
}
void F_276 ( struct V_238 * V_238 )
{
struct V_32 * V_33 = F_211 ( V_238 ) -> V_33 ;
T_2 V_34 = F_275 ( V_33 , 1 ) ;
F_258 ( V_33 , V_33 -> V_362 , V_34 ) ;
}
int F_277 ( struct V_82 * V_83 ,
struct V_363 * V_364 )
{
struct V_32 * V_33 = V_364 -> V_33 ;
struct V_304 * V_352 = F_250 ( V_83 , V_33 ) ;
struct V_304 * V_353 = & V_364 -> V_317 ;
T_2 V_34 = F_275 ( V_33 , 5 ) ;
V_353 -> V_100 = V_352 -> V_100 ;
return F_254 ( V_352 , V_353 , V_34 ) ;
}
static unsigned F_278 ( struct V_238 * V_238 )
{
unsigned V_365 = 0 ;
unsigned V_366 = 0 ;
F_22 ( ! F_211 ( V_238 ) -> V_367 ) ;
F_211 ( V_238 ) -> V_367 -- ;
if ( F_211 ( V_238 ) -> V_367 == 0 &&
F_211 ( V_238 ) -> V_368 ) {
V_365 = 1 ;
F_211 ( V_238 ) -> V_368 = 0 ;
}
if ( F_211 ( V_238 ) -> V_367 >=
F_211 ( V_238 ) -> V_369 )
return V_365 ;
V_366 = F_211 ( V_238 ) -> V_369 -
F_211 ( V_238 ) -> V_367 ;
F_211 ( V_238 ) -> V_369 -= V_366 ;
return V_366 + V_365 ;
}
static T_2 F_279 ( struct V_238 * V_238 , T_2 V_34 ,
int V_370 )
{
struct V_32 * V_33 = F_211 ( V_238 ) -> V_33 ;
T_2 V_356 ;
int V_371 ;
int V_372 ;
int V_373 ;
if ( F_211 ( V_238 ) -> V_6 & V_374 &&
F_211 ( V_238 ) -> V_375 == 0 )
return 0 ;
V_373 = ( int ) F_214 ( F_211 ( V_238 ) -> V_375 , V_33 -> V_292 ) ;
if ( V_370 )
F_211 ( V_238 ) -> V_375 += V_34 ;
else
F_211 ( V_238 ) -> V_375 -= V_34 ;
V_356 = F_280 ( V_33 ) - sizeof( struct V_376 ) ;
V_371 = ( int ) F_214 ( V_356 ,
sizeof( struct V_377 ) +
sizeof( struct V_378 ) ) ;
V_372 = ( int ) F_214 ( F_211 ( V_238 ) -> V_375 , V_33 -> V_292 ) ;
V_372 = V_372 + V_371 - 1 ;
V_372 = V_372 / V_371 ;
V_373 = V_373 + V_371 - 1 ;
V_373 = V_373 / V_371 ;
if ( V_373 == V_372 )
return 0 ;
if ( V_370 )
return F_275 ( V_33 ,
V_372 - V_373 ) ;
return F_275 ( V_33 , V_373 - V_372 ) ;
}
int F_281 ( struct V_238 * V_238 , T_2 V_34 )
{
struct V_32 * V_33 = F_211 ( V_238 ) -> V_33 ;
struct V_304 * V_317 = & V_33 -> V_35 -> V_326 ;
T_2 V_379 = 0 ;
T_2 V_375 ;
unsigned V_380 = 0 ;
int V_381 = 0 ;
int V_273 = 1 ;
int V_27 ;
if ( F_282 ( V_33 , V_238 ) )
V_273 = 0 ;
else
F_8 ( ! F_283 ( & V_238 -> V_382 ) ) ;
if ( V_273 && F_284 ( V_33 -> V_35 ) )
F_178 ( 1 ) ;
V_34 = F_269 ( V_34 , V_33 -> V_292 ) ;
F_11 ( & F_211 ( V_238 ) -> V_49 ) ;
F_211 ( V_238 ) -> V_367 ++ ;
if ( F_211 ( V_238 ) -> V_367 >
F_211 ( V_238 ) -> V_369 )
V_380 = F_211 ( V_238 ) -> V_367 -
F_211 ( V_238 ) -> V_369 ;
if ( ! F_211 ( V_238 ) -> V_368 ) {
V_380 ++ ;
V_381 = 1 ;
}
V_379 = F_275 ( V_33 , V_380 ) ;
V_379 += F_279 ( V_238 , V_34 , 1 ) ;
V_375 = F_211 ( V_238 ) -> V_375 ;
F_13 ( & F_211 ( V_238 ) -> V_49 ) ;
V_27 = F_247 ( V_33 , V_317 , V_379 , V_273 ) ;
if ( V_27 ) {
T_2 V_383 = 0 ;
unsigned V_384 ;
F_11 ( & F_211 ( V_238 ) -> V_49 ) ;
V_384 = F_278 ( V_238 ) ;
if ( F_211 ( V_238 ) -> V_375 == V_375 )
F_279 ( V_238 , V_34 , 0 ) ;
else
V_383 = F_279 ( V_238 , V_34 , 0 ) ;
F_13 ( & F_211 ( V_238 ) -> V_49 ) ;
if ( V_384 )
V_383 += F_275 ( V_33 , V_384 ) ;
if ( V_383 )
F_258 ( V_33 , V_317 , V_383 ) ;
return V_27 ;
}
F_11 ( & F_211 ( V_238 ) -> V_49 ) ;
if ( V_381 ) {
F_211 ( V_238 ) -> V_368 = 1 ;
V_380 -- ;
}
F_211 ( V_238 ) -> V_369 += V_380 ;
F_13 ( & F_211 ( V_238 ) -> V_49 ) ;
F_252 ( V_317 , V_379 , 1 ) ;
return 0 ;
}
void F_285 ( struct V_238 * V_238 , T_2 V_34 )
{
struct V_32 * V_33 = F_211 ( V_238 ) -> V_33 ;
T_2 V_383 = 0 ;
unsigned V_384 ;
V_34 = F_269 ( V_34 , V_33 -> V_292 ) ;
F_11 ( & F_211 ( V_238 ) -> V_49 ) ;
V_384 = F_278 ( V_238 ) ;
V_383 = F_279 ( V_238 , V_34 , 0 ) ;
F_13 ( & F_211 ( V_238 ) -> V_49 ) ;
if ( V_384 > 0 )
V_383 += F_275 ( V_33 , V_384 ) ;
F_258 ( V_33 , & V_33 -> V_35 -> V_326 ,
V_383 ) ;
}
int F_286 ( struct V_238 * V_238 , T_2 V_34 )
{
int V_27 ;
V_27 = F_215 ( V_238 , V_34 ) ;
if ( V_27 )
return V_27 ;
V_27 = F_281 ( V_238 , V_34 ) ;
if ( V_27 ) {
F_217 ( V_238 , V_34 ) ;
return V_27 ;
}
return 0 ;
}
void F_287 ( struct V_238 * V_238 , T_2 V_34 )
{
F_285 ( V_238 , V_34 ) ;
F_217 ( V_238 , V_34 ) ;
}
static int F_288 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
T_2 V_25 , T_2 V_34 , int V_295 )
{
struct V_1 * V_2 = NULL ;
struct V_11 * V_12 = V_33 -> V_35 ;
T_2 V_385 = V_34 ;
T_2 V_386 ;
T_2 V_387 ;
int V_107 ;
F_11 ( & V_12 -> V_388 ) ;
V_386 = F_289 ( V_12 -> V_310 ) ;
if ( V_295 )
V_386 += V_34 ;
else
V_386 -= V_34 ;
F_290 ( V_12 -> V_310 , V_386 ) ;
F_13 ( & V_12 -> V_388 ) ;
while ( V_385 ) {
V_2 = F_66 ( V_12 , V_25 ) ;
if ( ! V_2 )
return - 1 ;
if ( V_2 -> V_6 & ( V_258 |
V_259 |
V_260 ) )
V_107 = 2 ;
else
V_107 = 1 ;
if ( ! V_295 && V_2 -> V_3 == V_89 )
F_49 ( V_2 , V_83 , NULL , 1 ) ;
V_387 = V_25 - V_2 -> V_20 . V_21 ;
F_8 ( V_387 > V_2 -> V_20 . V_31 ) ;
F_11 ( & V_2 -> V_100 -> V_49 ) ;
F_11 ( & V_2 -> V_49 ) ;
if ( F_59 ( V_33 , V_93 ) &&
V_2 -> V_244 < V_252 )
V_2 -> V_244 = V_252 ;
V_2 -> V_253 = 1 ;
V_386 = F_77 ( & V_2 -> V_115 ) ;
V_34 = F_243 ( V_385 , V_2 -> V_20 . V_31 - V_387 ) ;
if ( V_295 ) {
V_386 += V_34 ;
F_291 ( & V_2 -> V_115 , V_386 ) ;
V_2 -> V_9 -= V_34 ;
V_2 -> V_100 -> V_267 -= V_34 ;
V_2 -> V_100 -> V_257 += V_34 ;
V_2 -> V_100 -> V_262 += V_34 * V_107 ;
F_13 ( & V_2 -> V_49 ) ;
F_13 ( & V_2 -> V_100 -> V_49 ) ;
} else {
V_386 -= V_34 ;
F_291 ( & V_2 -> V_115 , V_386 ) ;
V_2 -> V_8 += V_34 ;
V_2 -> V_100 -> V_266 += V_34 ;
V_2 -> V_100 -> V_257 -= V_34 ;
V_2 -> V_100 -> V_262 -= V_34 * V_107 ;
F_13 ( & V_2 -> V_49 ) ;
F_13 ( & V_2 -> V_100 -> V_49 ) ;
F_292 ( V_12 -> V_56 ,
V_25 , V_25 + V_34 - 1 ,
V_38 | V_389 ) ;
}
F_6 ( V_2 ) ;
V_385 -= V_34 ;
V_25 += V_34 ;
}
return 0 ;
}
static T_2 F_293 ( struct V_32 * V_33 , T_2 V_108 )
{
struct V_1 * V_2 ;
T_2 V_25 ;
V_2 = F_65 ( V_33 -> V_35 , V_108 ) ;
if ( ! V_2 )
return 0 ;
V_25 = V_2 -> V_20 . V_21 ;
F_6 ( V_2 ) ;
return V_25 ;
}
static int F_294 ( struct V_32 * V_33 ,
struct V_1 * V_2 ,
T_2 V_25 , T_2 V_34 , int V_9 )
{
F_11 ( & V_2 -> V_100 -> V_49 ) ;
F_11 ( & V_2 -> V_49 ) ;
V_2 -> V_8 += V_34 ;
V_2 -> V_100 -> V_266 += V_34 ;
if ( V_9 ) {
V_2 -> V_9 -= V_34 ;
V_2 -> V_100 -> V_267 -= V_34 ;
}
F_13 ( & V_2 -> V_49 ) ;
F_13 ( & V_2 -> V_100 -> V_49 ) ;
F_292 ( V_33 -> V_35 -> V_56 , V_25 ,
V_25 + V_34 - 1 , V_38 | V_389 ) ;
return 0 ;
}
int F_164 ( struct V_32 * V_33 ,
T_2 V_25 , T_2 V_34 , int V_9 )
{
struct V_1 * V_2 ;
V_2 = F_66 ( V_33 -> V_35 , V_25 ) ;
F_22 ( ! V_2 ) ;
F_294 ( V_33 , V_2 , V_25 , V_34 , V_9 ) ;
F_6 ( V_2 ) ;
return 0 ;
}
int F_295 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
T_2 V_25 , T_2 V_34 )
{
struct V_1 * V_2 ;
V_2 = F_66 ( V_33 -> V_35 , V_25 ) ;
F_22 ( ! V_2 ) ;
F_49 ( V_2 , V_83 , V_33 , 1 ) ;
F_294 ( V_33 , V_2 , V_25 , V_34 , 0 ) ;
F_296 ( V_2 , V_25 , V_34 ) ;
F_6 ( V_2 ) ;
return 0 ;
}
static int F_297 ( struct V_1 * V_2 ,
T_2 V_34 , int V_370 )
{
struct V_97 * V_100 = V_2 -> V_100 ;
int V_27 = 0 ;
F_11 ( & V_100 -> V_49 ) ;
F_11 ( & V_2 -> V_49 ) ;
if ( V_370 != V_390 ) {
if ( V_2 -> V_116 ) {
V_27 = - V_177 ;
} else {
V_2 -> V_9 += V_34 ;
V_100 -> V_267 += V_34 ;
if ( V_370 == V_391 ) {
F_22 ( V_100 -> V_269 < V_34 ) ;
V_100 -> V_269 -= V_34 ;
}
}
} else {
if ( V_2 -> V_116 )
V_100 -> V_268 += V_34 ;
V_2 -> V_9 -= V_34 ;
V_100 -> V_267 -= V_34 ;
V_100 -> V_327 ++ ;
}
F_13 ( & V_2 -> V_49 ) ;
F_13 ( & V_100 -> V_49 ) ;
return V_27 ;
}
int F_298 ( struct V_82 * V_83 ,
struct V_32 * V_33 )
{
struct V_11 * V_35 = V_33 -> V_35 ;
struct V_47 * V_216 ;
struct V_47 * V_51 ;
struct V_1 * V_2 ;
F_61 ( & V_35 -> V_76 ) ;
F_299 (caching_ctl, next,
&fs_info->caching_block_groups, list) {
V_2 = V_51 -> V_13 ;
if ( F_1 ( V_2 ) ) {
V_2 -> V_94 = ( T_2 ) - 1 ;
F_171 ( & V_51 -> V_85 ) ;
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
F_270 ( V_35 ) ;
return 0 ;
}
static int F_300 ( struct V_32 * V_33 , T_2 V_30 , T_2 V_29 )
{
struct V_11 * V_35 = V_33 -> V_35 ;
struct V_1 * V_2 = NULL ;
T_2 V_117 ;
while ( V_30 <= V_29 ) {
if ( ! V_2 ||
V_30 >= V_2 -> V_20 . V_21 + V_2 -> V_20 . V_31 ) {
if ( V_2 )
F_6 ( V_2 ) ;
V_2 = F_66 ( V_35 , V_30 ) ;
F_22 ( ! V_2 ) ;
}
V_117 = V_2 -> V_20 . V_21 + V_2 -> V_20 . V_31 - V_30 ;
V_117 = F_243 ( V_117 , V_29 + 1 - V_30 ) ;
if ( V_30 < V_2 -> V_94 ) {
V_117 = F_243 ( V_117 , V_2 -> V_94 - V_30 ) ;
F_29 ( V_2 , V_30 , V_117 ) ;
}
V_30 += V_117 ;
F_11 ( & V_2 -> V_100 -> V_49 ) ;
F_11 ( & V_2 -> V_49 ) ;
V_2 -> V_8 -= V_117 ;
V_2 -> V_100 -> V_266 -= V_117 ;
if ( V_2 -> V_116 )
V_2 -> V_100 -> V_268 += V_117 ;
F_13 ( & V_2 -> V_49 ) ;
F_13 ( & V_2 -> V_100 -> V_49 ) ;
}
if ( V_2 )
F_6 ( V_2 ) ;
return 0 ;
}
int F_301 ( struct V_82 * V_83 ,
struct V_32 * V_33 )
{
struct V_11 * V_35 = V_33 -> V_35 ;
struct V_392 * V_393 ;
T_2 V_30 ;
T_2 V_29 ;
int V_27 ;
if ( V_35 -> V_56 == & V_35 -> V_36 [ 0 ] )
V_393 = & V_35 -> V_36 [ 1 ] ;
else
V_393 = & V_35 -> V_36 [ 0 ] ;
while ( 1 ) {
V_27 = F_28 ( V_393 , 0 , & V_30 , & V_29 ,
V_57 ) ;
if ( V_27 )
break;
if ( F_59 ( V_33 , V_394 ) )
V_27 = F_146 ( V_33 , V_30 ,
V_29 + 1 - V_30 , NULL ) ;
F_302 ( V_393 , V_30 , V_29 , V_38 ) ;
F_300 ( V_33 , V_30 , V_29 ) ;
F_46 () ;
}
return 0 ;
}
static int F_155 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
T_2 V_25 , T_2 V_34 , T_2 V_16 ,
T_2 V_148 , T_2 V_395 ,
T_2 V_396 , int V_161 ,
struct V_179 * V_133 )
{
struct V_65 V_20 ;
struct V_61 * V_62 ;
struct V_11 * V_12 = V_33 -> V_35 ;
struct V_32 * V_60 = V_12 -> V_60 ;
struct V_63 * V_64 ;
struct V_123 * V_124 ;
struct V_164 * V_165 ;
int V_27 ;
int V_183 ;
int V_397 = 0 ;
int V_398 = 0 ;
int V_399 = 1 ;
T_3 V_125 ;
T_2 V_119 ;
V_62 = F_32 () ;
if ( ! V_62 )
return - V_118 ;
V_62 -> V_72 = 1 ;
V_62 -> V_202 = 1 ;
V_183 = V_395 >= V_145 ;
F_22 ( ! V_183 && V_161 != 1 ) ;
V_27 = F_138 ( V_83 , V_60 , V_62 , & V_165 ,
V_25 , V_34 , V_16 ,
V_148 , V_395 ,
V_396 ) ;
if ( V_27 == 0 ) {
V_397 = V_62 -> V_79 [ 0 ] ;
while ( V_397 >= 0 ) {
F_39 ( V_62 -> V_78 [ 0 ] , & V_20 ,
V_397 ) ;
if ( V_20 . V_21 != V_25 )
break;
if ( V_20 . type == V_73 &&
V_20 . V_31 == V_34 ) {
V_398 = 1 ;
break;
}
if ( V_62 -> V_79 [ 0 ] - V_397 > 5 )
break;
V_397 -- ;
}
#ifdef F_85
V_125 = F_81 ( V_62 -> V_78 [ 0 ] , V_397 ) ;
if ( V_398 && V_125 < sizeof( * V_124 ) )
V_398 = 0 ;
#endif
if ( ! V_398 ) {
F_22 ( V_165 ) ;
V_27 = F_143 ( V_83 , V_60 , V_62 ,
NULL , V_161 ,
V_183 ) ;
F_22 ( V_27 ) ;
F_43 ( V_62 ) ;
V_62 -> V_202 = 1 ;
V_20 . V_21 = V_25 ;
V_20 . type = V_73 ;
V_20 . V_31 = V_34 ;
V_27 = F_36 ( V_83 , V_60 ,
& V_20 , V_62 , - 1 , 1 ) ;
if ( V_27 ) {
F_303 ( V_400 L_1
L_2 , V_27 ,
( unsigned long long ) V_25 ) ;
if ( V_27 > 0 )
F_304 ( V_60 ,
V_62 -> V_78 [ 0 ] ) ;
}
F_22 ( V_27 ) ;
V_397 = V_62 -> V_79 [ 0 ] ;
}
} else {
F_304 ( V_60 , V_62 -> V_78 [ 0 ] ) ;
F_8 ( 1 ) ;
F_303 ( V_400 L_3
L_4 ,
( unsigned long long ) V_25 ,
( unsigned long long ) V_16 ,
( unsigned long long ) V_148 ,
( unsigned long long ) V_395 ,
( unsigned long long ) V_396 ) ;
}
V_64 = V_62 -> V_78 [ 0 ] ;
V_125 = F_81 ( V_64 , V_397 ) ;
#ifdef F_85
if ( V_125 < sizeof( * V_124 ) ) {
F_22 ( V_398 || V_397 != V_62 -> V_79 [ 0 ] ) ;
V_27 = F_91 ( V_83 , V_60 , V_62 ,
V_395 , 0 ) ;
F_22 ( V_27 < 0 ) ;
F_43 ( V_62 ) ;
V_62 -> V_202 = 1 ;
V_20 . V_21 = V_25 ;
V_20 . type = V_73 ;
V_20 . V_31 = V_34 ;
V_27 = F_36 ( V_83 , V_60 , & V_20 , V_62 ,
- 1 , 1 ) ;
if ( V_27 ) {
F_303 ( V_400 L_1
L_2 , V_27 ,
( unsigned long long ) V_25 ) ;
F_304 ( V_60 , V_62 -> V_78 [ 0 ] ) ;
}
F_22 ( V_27 ) ;
V_397 = V_62 -> V_79 [ 0 ] ;
V_64 = V_62 -> V_78 [ 0 ] ;
V_125 = F_81 ( V_64 , V_397 ) ;
}
#endif
F_22 ( V_125 < sizeof( * V_124 ) ) ;
V_124 = F_82 ( V_64 , V_397 ,
struct V_123 ) ;
if ( V_395 < V_145 ) {
struct V_140 * V_141 ;
F_22 ( V_125 < sizeof( * V_124 ) + sizeof( * V_141 ) ) ;
V_141 = (struct V_140 * ) ( V_124 + 1 ) ;
F_8 ( V_395 != F_305 ( V_64 , V_141 ) ) ;
}
V_119 = F_83 ( V_64 , V_124 ) ;
F_22 ( V_119 < V_161 ) ;
V_119 -= V_161 ;
if ( V_119 > 0 ) {
if ( V_133 )
F_134 ( V_133 , V_64 , V_124 ) ;
if ( V_165 ) {
F_22 ( ! V_398 ) ;
} else {
F_94 ( V_64 , V_124 , V_119 ) ;
F_99 ( V_64 ) ;
}
if ( V_398 ) {
V_27 = F_143 ( V_83 , V_60 , V_62 ,
V_165 , V_161 ,
V_183 ) ;
F_22 ( V_27 ) ;
}
} else {
if ( V_398 ) {
F_22 ( V_183 && V_161 !=
F_122 ( V_33 , V_62 , V_165 ) ) ;
if ( V_165 ) {
F_22 ( V_62 -> V_79 [ 0 ] != V_397 ) ;
} else {
F_22 ( V_62 -> V_79 [ 0 ] != V_397 + 1 ) ;
V_62 -> V_79 [ 0 ] = V_397 ;
V_399 = 2 ;
}
}
V_27 = F_306 ( V_83 , V_60 , V_62 , V_62 -> V_79 [ 0 ] ,
V_399 ) ;
F_22 ( V_27 ) ;
F_43 ( V_62 ) ;
if ( V_183 ) {
V_27 = F_165 ( V_83 , V_33 , V_25 , V_34 ) ;
F_22 ( V_27 ) ;
} else {
F_307 ( V_12 -> V_401 -> V_402 ,
V_25 >> V_322 ,
( V_25 + V_34 - 1 ) >> V_322 ) ;
}
V_27 = F_288 ( V_83 , V_33 , V_25 , V_34 , 0 ) ;
F_22 ( V_27 ) ;
}
F_48 ( V_62 ) ;
return V_27 ;
}
static T_1 int F_308 ( struct V_82 * V_83 ,
struct V_32 * V_33 , T_2 V_25 )
{
struct V_120 * V_99 ;
struct V_121 * V_122 ;
struct V_203 * V_153 ;
struct V_14 * V_132 ;
int V_27 = 0 ;
V_122 = & V_83 -> V_90 -> V_122 ;
F_11 ( & V_122 -> V_49 ) ;
V_99 = F_88 ( V_83 , V_25 ) ;
if ( ! V_99 )
goto V_69;
V_132 = F_183 ( & V_99 -> V_132 . V_14 ) ;
if ( ! V_132 )
goto V_69;
V_153 = F_12 ( V_132 , struct V_203 , V_14 ) ;
if ( V_153 -> V_25 == V_25 )
goto V_69;
if ( V_99 -> V_133 ) {
if ( ! V_99 -> V_215 )
goto V_69;
F_9 ( V_99 -> V_133 ) ;
V_99 -> V_133 = NULL ;
}
if ( ! F_89 ( & V_99 -> V_75 ) )
goto V_69;
V_99 -> V_132 . V_217 = 0 ;
F_172 ( & V_99 -> V_132 . V_14 , & V_122 -> V_33 ) ;
V_122 -> V_218 -- ;
V_122 -> V_403 -- ;
if ( F_167 ( & V_99 -> V_213 ) )
V_122 -> V_221 -- ;
F_171 ( & V_99 -> V_213 ) ;
F_13 ( & V_122 -> V_49 ) ;
F_22 ( V_99 -> V_133 ) ;
if ( V_99 -> V_215 )
V_27 = 1 ;
F_45 ( & V_99 -> V_75 ) ;
F_90 ( & V_99 -> V_132 ) ;
return V_27 ;
V_69:
F_13 ( & V_122 -> V_49 ) ;
return 0 ;
}
void F_309 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_63 * V_229 ,
T_2 V_16 , int V_404 )
{
struct V_1 * V_2 = NULL ;
int V_27 ;
if ( V_33 -> V_225 . V_21 != V_200 ) {
V_27 = F_149 ( V_83 , V_229 -> V_30 , V_229 -> V_117 ,
V_16 , V_33 -> V_225 . V_21 ,
F_191 ( V_229 ) ,
V_210 , NULL ) ;
F_22 ( V_27 ) ;
}
if ( ! V_404 )
return;
V_2 = F_66 ( V_33 -> V_35 , V_229 -> V_30 ) ;
if ( F_310 ( V_229 ) == V_83 -> V_247 ) {
if ( V_33 -> V_225 . V_21 != V_200 ) {
V_27 = F_308 ( V_83 , V_33 , V_229 -> V_30 ) ;
if ( ! V_27 )
goto V_69;
}
if ( F_311 ( V_229 , V_405 ) ) {
F_294 ( V_33 , V_2 , V_229 -> V_30 , V_229 -> V_117 , 1 ) ;
goto V_69;
}
F_8 ( F_312 ( V_406 , & V_229 -> V_407 ) ) ;
F_29 ( V_2 , V_229 -> V_30 , V_229 -> V_117 ) ;
F_297 ( V_2 , V_229 -> V_117 , V_390 ) ;
}
V_69:
F_313 ( V_408 , & V_229 -> V_407 ) ;
F_6 ( V_2 ) ;
}
int V_235 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
T_2 V_25 , T_2 V_34 , T_2 V_16 ,
T_2 V_148 , T_2 V_110 , T_2 V_31 )
{
int V_27 ;
if ( V_148 == V_200 ) {
F_8 ( V_110 >= V_145 ) ;
F_164 ( V_33 , V_25 , V_34 , 1 ) ;
V_27 = 0 ;
} else if ( V_110 < V_145 ) {
V_27 = F_149 ( V_83 , V_25 , V_34 ,
V_16 , V_148 , ( int ) V_110 ,
V_210 , NULL ) ;
F_22 ( V_27 ) ;
} else {
V_27 = F_150 ( V_83 , V_25 , V_34 ,
V_16 , V_148 , V_110 ,
V_31 , V_210 , NULL ) ;
F_22 ( V_27 ) ;
}
return V_27 ;
}
static T_2 F_314 ( struct V_32 * V_33 , T_2 V_409 )
{
T_2 V_410 = ( ( T_2 ) V_33 -> V_411 - 1 ) ;
T_2 V_27 = ( V_409 + V_410 ) & ~ V_410 ;
return V_27 ;
}
static T_1 int
F_315 ( struct V_1 * V_2 ,
T_2 V_34 )
{
struct V_47 * V_51 ;
F_50 ( V_81 ) ;
V_51 = F_25 ( V_2 ) ;
if ( ! V_51 )
return 0 ;
F_316 ( V_51 -> V_81 , F_1 ( V_2 ) ||
( V_2 -> V_10 -> V_412 >= V_34 ) ) ;
F_26 ( V_51 ) ;
return 0 ;
}
static T_1 int
F_317 ( struct V_1 * V_2 )
{
struct V_47 * V_51 ;
F_50 ( V_81 ) ;
V_51 = F_25 ( V_2 ) ;
if ( ! V_51 )
return 0 ;
F_316 ( V_51 -> V_81 , F_1 ( V_2 ) ) ;
F_26 ( V_51 ) ;
return 0 ;
}
static int F_318 ( struct V_1 * V_2 )
{
int V_413 ;
if ( V_2 -> V_6 & V_260 )
V_413 = 0 ;
else if ( V_2 -> V_6 & V_259 )
V_413 = 1 ;
else if ( V_2 -> V_6 & V_258 )
V_413 = 2 ;
else if ( V_2 -> V_6 & V_275 )
V_413 = 3 ;
else
V_413 = 4 ;
return V_413 ;
}
static T_1 int F_319 ( struct V_82 * V_83 ,
struct V_32 * V_414 ,
T_2 V_34 , T_2 V_415 ,
T_2 V_108 , T_2 V_416 ,
T_2 V_417 , struct V_65 * V_206 ,
T_2 V_286 )
{
int V_27 = 0 ;
struct V_32 * V_33 = V_414 -> V_35 -> V_60 ;
struct V_418 * V_419 = NULL ;
struct V_1 * V_13 = NULL ;
struct V_1 * V_420 ;
int V_421 = 2 * 1024 * 1024 ;
int V_422 = 0 ;
int V_423 = 0 ;
struct V_97 * V_100 ;
int V_424 = 0 ;
int V_413 = 0 ;
int V_425 = ( V_286 & V_102 ) ?
V_426 : V_391 ;
bool V_427 = false ;
bool V_428 = false ;
bool V_429 = false ;
bool V_430 = true ;
bool V_431 = false ;
T_2 V_432 = 0 ;
T_2 V_433 = 0 ;
F_8 ( V_34 < V_33 -> V_292 ) ;
F_79 ( V_206 , V_73 ) ;
V_206 -> V_21 = 0 ;
V_206 -> V_31 = 0 ;
V_100 = F_67 ( V_33 -> V_35 , V_286 ) ;
if ( ! V_100 ) {
F_303 ( V_400 L_5 , V_286 ) ;
return - V_298 ;
}
if ( F_239 ( V_100 ) )
V_430 = false ;
if ( V_414 -> V_234 || V_415 )
V_422 = 1 ;
if ( V_286 & V_104 && V_430 ) {
V_419 = & V_33 -> V_35 -> V_434 ;
if ( ! F_59 ( V_33 , V_435 ) )
V_421 = 64 * 1024 ;
}
if ( ( V_286 & V_102 ) && V_430 &&
F_59 ( V_33 , V_435 ) ) {
V_419 = & V_33 -> V_35 -> V_436 ;
}
if ( V_419 ) {
F_11 ( & V_419 -> V_49 ) ;
if ( V_419 -> V_13 )
V_417 = V_419 -> V_437 ;
F_13 ( & V_419 -> V_49 ) ;
}
V_108 = F_76 ( V_108 , F_293 ( V_33 , 0 ) ) ;
V_108 = F_76 ( V_108 , V_417 ) ;
if ( ! V_419 )
V_421 = 0 ;
if ( V_108 == V_417 ) {
V_438:
V_13 = F_66 ( V_33 -> V_35 ,
V_108 ) ;
V_420 = V_13 ;
if ( V_13 && F_3 ( V_13 , V_286 ) &&
( V_13 -> V_3 != V_89 ||
V_108 == V_433 ) ) {
F_35 ( & V_100 -> V_265 ) ;
if ( F_167 ( & V_13 -> V_85 ) ||
V_13 -> V_116 ) {
F_6 ( V_13 ) ;
F_44 ( & V_100 -> V_265 ) ;
} else {
V_413 = F_318 ( V_13 ) ;
goto V_439;
}
} else if ( V_13 ) {
F_6 ( V_13 ) ;
}
}
V_440:
V_431 = false ;
F_35 ( & V_100 -> V_265 ) ;
F_320 (block_group, &space_info->block_groups[index],
list) {
T_2 V_31 ;
int V_3 ;
V_420 = V_13 ;
F_4 ( V_13 ) ;
V_108 = V_13 -> V_20 . V_21 ;
if ( ! F_3 ( V_13 , V_286 ) ) {
T_2 V_441 = V_258 |
V_259 |
V_260 ;
if ( ( V_286 & V_441 ) && ! ( V_13 -> V_6 & V_441 ) )
goto V_424;
}
V_439:
V_3 = F_1 ( V_13 ) ;
if ( F_321 ( ! V_3 ) ) {
T_2 V_442 ;
V_427 = true ;
V_27 = F_49 ( V_13 , V_83 ,
V_414 , 1 ) ;
if ( V_13 -> V_3 == V_4 )
goto V_295;
V_442 = F_77 ( & V_13 -> V_115 ) ;
V_442 *= 100 ;
V_442 = F_214 ( V_442 ,
V_13 -> V_20 . V_31 ) ;
V_442 = 100 - V_442 ;
if ( V_442 > V_432 &&
F_322 ( ! V_13 -> V_116 ) ) {
V_433 = V_13 -> V_20 . V_21 ;
V_432 = V_442 ;
}
if ( V_424 > V_443 ) {
V_27 = F_49 ( V_13 , V_83 ,
V_414 , 0 ) ;
F_22 ( V_27 ) ;
}
if ( V_424 == V_443 )
goto V_424;
}
V_295:
if ( F_321 ( V_13 -> V_116 ) )
goto V_424;
F_11 ( & V_13 -> V_10 -> V_444 ) ;
if ( V_3 &&
V_13 -> V_10 -> V_412 <
V_34 + V_421 + V_415 ) {
F_13 ( & V_13 -> V_10 -> V_444 ) ;
goto V_424;
}
F_13 ( & V_13 -> V_10 -> V_444 ) ;
if ( V_419 ) {
F_11 ( & V_419 -> V_445 ) ;
V_420 = V_419 -> V_13 ;
if ( V_420 != V_13 &&
( ! V_420 ||
V_420 -> V_116 ||
! F_3 ( V_420 , V_286 ) ) ) {
V_420 = V_13 ;
goto V_446;
}
if ( V_420 != V_13 )
F_4 ( V_420 ) ;
V_31 = F_323 ( V_420 ,
V_419 , V_34 , V_420 -> V_20 . V_21 ) ;
if ( V_31 ) {
F_13 ( & V_419 -> V_445 ) ;
goto V_447;
}
F_8 ( V_419 -> V_13 != V_420 ) ;
if ( V_420 != V_13 ) {
F_6 ( V_420 ) ;
V_420 = V_13 ;
}
V_446:
F_22 ( V_420 != V_13 ) ;
if ( V_424 >= V_448 ) {
F_13 ( & V_419 -> V_445 ) ;
goto V_449;
}
F_324 ( NULL , V_419 ) ;
V_27 = F_325 ( V_83 , V_33 ,
V_13 , V_419 ,
V_108 , V_34 ,
V_421 + V_415 ) ;
if ( V_27 == 0 ) {
V_31 = F_323 ( V_13 ,
V_419 , V_34 ,
V_108 ) ;
if ( V_31 ) {
F_13 ( & V_419 -> V_445 ) ;
goto V_447;
}
} else if ( ! V_3 && V_424 > V_450
&& ! V_428 ) {
F_13 ( & V_419 -> V_445 ) ;
V_428 = true ;
F_315 ( V_13 ,
V_34 + V_421 + V_415 ) ;
goto V_439;
}
F_324 ( NULL , V_419 ) ;
F_13 ( & V_419 -> V_445 ) ;
goto V_424;
}
V_449:
V_31 = F_326 ( V_13 , V_108 ,
V_34 , V_415 ) ;
if ( ! V_31 && ! V_429 && ! V_3 &&
V_424 > V_450 ) {
F_315 ( V_13 ,
V_34 + V_415 ) ;
V_429 = true ;
goto V_439;
} else if ( ! V_31 ) {
if ( ! V_3 )
V_431 = true ;
goto V_424;
}
V_447:
V_108 = F_314 ( V_33 , V_31 ) ;
if ( V_108 + V_34 >= V_416 ) {
F_29 ( V_420 , V_31 , V_34 ) ;
goto V_424;
}
if ( V_108 + V_34 >
V_420 -> V_20 . V_21 + V_420 -> V_20 . V_31 ) {
F_29 ( V_420 , V_31 , V_34 ) ;
goto V_424;
}
V_206 -> V_21 = V_108 ;
V_206 -> V_31 = V_34 ;
if ( V_31 < V_108 )
F_29 ( V_420 , V_31 ,
V_108 - V_31 ) ;
F_22 ( V_31 > V_108 ) ;
V_27 = F_297 ( V_420 , V_34 ,
V_425 ) ;
if ( V_27 == - V_177 ) {
F_29 ( V_420 , V_31 , V_34 ) ;
goto V_424;
}
V_206 -> V_21 = V_108 ;
V_206 -> V_31 = V_34 ;
if ( V_31 < V_108 )
F_29 ( V_420 , V_31 ,
V_108 - V_31 ) ;
F_22 ( V_31 > V_108 ) ;
if ( V_420 != V_13 )
F_6 ( V_420 ) ;
F_6 ( V_13 ) ;
break;
V_424:
V_428 = false ;
V_429 = false ;
F_22 ( V_413 != F_318 ( V_13 ) ) ;
if ( V_420 != V_13 )
F_6 ( V_420 ) ;
F_6 ( V_13 ) ;
}
F_44 ( & V_100 -> V_265 ) ;
if ( ! V_206 -> V_21 && V_424 >= V_451 && V_431 )
goto V_440;
if ( ! V_206 -> V_21 && ++ V_413 < V_263 )
goto V_440;
if ( ! V_206 -> V_21 && V_424 < V_448 ) {
V_413 = 0 ;
if ( V_424 == V_443 && V_427 ) {
V_427 = false ;
V_424 ++ ;
if ( ! V_432 )
goto V_440;
V_424 = V_451 ;
V_108 = V_433 ;
V_432 = 0 ;
goto V_438;
} else if ( V_424 == V_443 ) {
V_424 = V_451 ;
goto V_440;
}
V_424 ++ ;
if ( V_424 == V_452 ) {
if ( V_422 ) {
V_27 = F_232 ( V_83 , V_33 , V_34 +
2 * 1024 * 1024 , V_286 ,
V_309 ) ;
V_422 = 0 ;
if ( V_27 == 1 )
V_423 = 1 ;
} else if ( ! V_423 &&
V_100 -> V_270 ==
V_271 ) {
V_100 -> V_270 = V_309 ;
}
if ( ! V_423 )
V_424 = V_448 ;
}
if ( V_424 == V_448 ) {
V_415 = 0 ;
V_421 = 0 ;
}
goto V_440;
} else if ( ! V_206 -> V_21 ) {
V_27 = - V_298 ;
} else if ( V_206 -> V_21 ) {
V_27 = 0 ;
}
return V_27 ;
}
static void F_327 ( struct V_97 * V_12 , T_2 V_288 ,
int V_453 )
{
struct V_1 * V_2 ;
int V_413 = 0 ;
F_11 ( & V_12 -> V_49 ) ;
F_303 ( V_454 L_6 ,
( unsigned long long ) V_12 -> V_6 ,
( unsigned long long ) ( V_12 -> V_256 - V_12 -> V_257 -
V_12 -> V_266 - V_12 -> V_267 -
V_12 -> V_268 ) ,
( V_12 -> V_105 ) ? L_7 : L_8 ) ;
F_303 ( V_454 L_9
L_10 ,
( unsigned long long ) V_12 -> V_256 ,
( unsigned long long ) V_12 -> V_257 ,
( unsigned long long ) V_12 -> V_266 ,
( unsigned long long ) V_12 -> V_267 ,
( unsigned long long ) V_12 -> V_269 ,
( unsigned long long ) V_12 -> V_268 ) ;
F_13 ( & V_12 -> V_49 ) ;
if ( ! V_453 )
return;
F_35 ( & V_12 -> V_265 ) ;
V_74:
F_320 (cache, &info->block_groups[index], list) {
F_11 ( & V_2 -> V_49 ) ;
F_303 ( V_454 L_11
L_12 ,
( unsigned long long ) V_2 -> V_20 . V_21 ,
( unsigned long long ) V_2 -> V_20 . V_31 ,
( unsigned long long ) F_77 ( & V_2 -> V_115 ) ,
( unsigned long long ) V_2 -> V_8 ,
( unsigned long long ) V_2 -> V_9 ) ;
F_328 ( V_2 , V_288 ) ;
F_13 ( & V_2 -> V_49 ) ;
}
if ( ++ V_413 < V_263 )
goto V_74;
F_44 ( & V_12 -> V_265 ) ;
}
int F_329 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
T_2 V_34 , T_2 V_455 ,
T_2 V_415 , T_2 V_417 ,
T_2 V_416 , struct V_65 * V_206 ,
T_2 V_286 )
{
int V_27 ;
T_2 V_108 = 0 ;
V_286 = F_229 ( V_33 , V_286 ) ;
V_74:
if ( V_415 || V_33 -> V_234 )
V_27 = F_232 ( V_83 , V_33 -> V_35 -> V_60 ,
V_34 + 2 * 1024 * 1024 , V_286 ,
V_271 ) ;
F_8 ( V_34 < V_33 -> V_292 ) ;
V_27 = F_319 ( V_83 , V_33 , V_34 , V_415 ,
V_108 , V_416 , V_417 ,
V_206 , V_286 ) ;
if ( V_27 == - V_298 && V_34 > V_455 ) {
V_34 = V_34 >> 1 ;
V_34 = V_34 & ~ ( V_33 -> V_292 - 1 ) ;
V_34 = F_76 ( V_34 , V_455 ) ;
F_232 ( V_83 , V_33 -> V_35 -> V_60 ,
V_34 , V_286 , V_297 ) ;
goto V_74;
}
if ( V_27 == - V_298 && F_59 ( V_33 , V_456 ) ) {
struct V_97 * V_301 ;
V_301 = F_67 ( V_33 -> V_35 , V_286 ) ;
F_303 ( V_400 L_13
L_14 , ( unsigned long long ) V_286 ,
( unsigned long long ) V_34 ) ;
F_327 ( V_301 , V_34 , 1 ) ;
}
F_330 ( V_33 , V_206 -> V_21 , V_206 -> V_31 ) ;
return V_27 ;
}
static int F_331 ( struct V_32 * V_33 ,
T_2 V_30 , T_2 V_117 , int V_457 )
{
struct V_1 * V_2 ;
int V_27 = 0 ;
V_2 = F_66 ( V_33 -> V_35 , V_30 ) ;
if ( ! V_2 ) {
F_303 ( V_400 L_15 ,
( unsigned long long ) V_30 ) ;
return - V_298 ;
}
if ( F_59 ( V_33 , V_394 ) )
V_27 = F_146 ( V_33 , V_30 , V_117 , NULL ) ;
if ( V_457 )
F_294 ( V_33 , V_2 , V_30 , V_117 , 1 ) ;
else {
F_29 ( V_2 , V_30 , V_117 ) ;
F_297 ( V_2 , V_117 , V_390 ) ;
}
F_6 ( V_2 ) ;
F_332 ( V_33 , V_30 , V_117 ) ;
return V_27 ;
}
int F_333 ( struct V_32 * V_33 ,
T_2 V_30 , T_2 V_117 )
{
return F_331 ( V_33 , V_30 , V_117 , 0 ) ;
}
int F_334 ( struct V_32 * V_33 ,
T_2 V_30 , T_2 V_117 )
{
return F_331 ( V_33 , V_30 , V_117 , 1 ) ;
}
static int F_154 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
T_2 V_16 , T_2 V_148 ,
T_2 V_6 , T_2 V_110 , T_2 V_31 ,
struct V_65 * V_206 , int V_136 )
{
int V_27 ;
struct V_11 * V_35 = V_33 -> V_35 ;
struct V_123 * V_458 ;
struct V_164 * V_165 ;
struct V_61 * V_62 ;
struct V_63 * V_64 ;
int type ;
T_3 V_54 ;
if ( V_16 > 0 )
type = V_156 ;
else
type = V_157 ;
V_54 = sizeof( * V_458 ) + F_129 ( type ) ;
V_62 = F_32 () ;
if ( ! V_62 )
return - V_118 ;
V_62 -> V_202 = 1 ;
V_27 = F_110 ( V_83 , V_35 -> V_60 , V_62 ,
V_206 , V_54 ) ;
F_22 ( V_27 ) ;
V_64 = V_62 -> V_78 [ 0 ] ;
V_458 = F_82 ( V_64 , V_62 -> V_79 [ 0 ] ,
struct V_123 ) ;
F_94 ( V_64 , V_458 , V_136 ) ;
F_95 ( V_64 , V_458 , V_83 -> V_247 ) ;
F_96 ( V_64 , V_458 ,
V_6 | V_147 ) ;
V_165 = (struct V_164 * ) ( V_458 + 1 ) ;
F_136 ( V_64 , V_165 , type ) ;
if ( V_16 > 0 ) {
struct V_160 * V_153 ;
V_153 = (struct V_160 * ) ( V_165 + 1 ) ;
F_137 ( V_64 , V_165 , V_16 ) ;
F_111 ( V_64 , V_153 , V_136 ) ;
} else {
struct V_152 * V_153 ;
V_153 = (struct V_152 * ) ( & V_165 -> V_31 ) ;
F_113 ( V_64 , V_153 , V_148 ) ;
F_114 ( V_64 , V_153 , V_110 ) ;
F_115 ( V_64 , V_153 , V_31 ) ;
F_116 ( V_64 , V_153 , V_136 ) ;
}
F_99 ( V_62 -> V_78 [ 0 ] ) ;
F_48 ( V_62 ) ;
V_27 = F_288 ( V_83 , V_33 , V_206 -> V_21 , V_206 -> V_31 , 1 ) ;
if ( V_27 ) {
F_303 ( V_400 L_16
L_17 , ( unsigned long long ) V_206 -> V_21 ,
( unsigned long long ) V_206 -> V_31 ) ;
F_87 () ;
}
return V_27 ;
}
static int F_160 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
T_2 V_16 , T_2 V_148 ,
T_2 V_6 , struct V_378 * V_20 ,
int V_168 , struct V_65 * V_206 )
{
int V_27 ;
struct V_11 * V_35 = V_33 -> V_35 ;
struct V_123 * V_458 ;
struct V_140 * V_459 ;
struct V_164 * V_165 ;
struct V_61 * V_62 ;
struct V_63 * V_64 ;
T_3 V_54 = sizeof( * V_458 ) + sizeof( * V_459 ) + sizeof( * V_165 ) ;
V_62 = F_32 () ;
if ( ! V_62 )
return - V_118 ;
V_62 -> V_202 = 1 ;
V_27 = F_110 ( V_83 , V_35 -> V_60 , V_62 ,
V_206 , V_54 ) ;
F_22 ( V_27 ) ;
V_64 = V_62 -> V_78 [ 0 ] ;
V_458 = F_82 ( V_64 , V_62 -> V_79 [ 0 ] ,
struct V_123 ) ;
F_94 ( V_64 , V_458 , 1 ) ;
F_95 ( V_64 , V_458 , V_83 -> V_247 ) ;
F_96 ( V_64 , V_458 ,
V_6 | V_146 ) ;
V_459 = (struct V_140 * ) ( V_458 + 1 ) ;
F_156 ( V_64 , V_459 , V_20 ) ;
F_98 ( V_64 , V_459 , V_168 ) ;
V_165 = (struct V_164 * ) ( V_459 + 1 ) ;
if ( V_16 > 0 ) {
F_22 ( ! ( V_6 & V_131 ) ) ;
F_136 ( V_64 , V_165 ,
V_166 ) ;
F_137 ( V_64 , V_165 , V_16 ) ;
} else {
F_136 ( V_64 , V_165 ,
V_167 ) ;
F_137 ( V_64 , V_165 , V_148 ) ;
}
F_99 ( V_64 ) ;
F_48 ( V_62 ) ;
V_27 = F_288 ( V_83 , V_33 , V_206 -> V_21 , V_206 -> V_31 , 1 ) ;
if ( V_27 ) {
F_303 ( V_400 L_16
L_17 , ( unsigned long long ) V_206 -> V_21 ,
( unsigned long long ) V_206 -> V_31 ) ;
F_87 () ;
}
return V_27 ;
}
int F_335 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
T_2 V_148 , T_2 V_110 ,
T_2 V_31 , struct V_65 * V_206 )
{
int V_27 ;
F_22 ( V_148 == V_200 ) ;
V_27 = F_150 ( V_83 , V_206 -> V_21 , V_206 -> V_31 ,
0 , V_148 , V_110 , V_31 ,
V_460 , NULL ) ;
return V_27 ;
}
int F_336 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
T_2 V_148 , T_2 V_110 , T_2 V_31 ,
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
V_27 = F_296 ( V_13 , V_30 , V_34 ) ;
F_22 ( V_27 ) ;
} else {
F_34 ( & V_51 -> V_75 ) ;
if ( V_30 >= V_51 -> V_80 ) {
V_27 = F_17 ( V_33 , V_30 , V_34 ) ;
F_22 ( V_27 ) ;
} else if ( V_30 + V_34 <= V_51 -> V_80 ) {
V_27 = F_296 ( V_13 ,
V_30 , V_34 ) ;
F_22 ( V_27 ) ;
} else {
V_34 = V_51 -> V_80 - V_30 ;
V_27 = F_296 ( V_13 ,
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
V_27 = F_297 ( V_13 , V_206 -> V_31 ,
V_426 ) ;
F_22 ( V_27 ) ;
F_6 ( V_13 ) ;
V_27 = F_154 ( V_83 , V_33 , 0 , V_148 ,
0 , V_110 , V_31 , V_206 , 1 ) ;
return V_27 ;
}
struct V_63 * F_337 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
T_2 V_25 , T_3 V_461 ,
int V_168 )
{
struct V_63 * V_229 ;
V_229 = F_338 ( V_33 , V_25 , V_461 ) ;
if ( ! V_229 )
return F_339 ( - V_118 ) ;
F_340 ( V_229 , V_83 -> V_247 ) ;
F_341 ( V_33 -> V_225 . V_21 , V_229 , V_168 ) ;
F_342 ( V_229 ) ;
F_343 ( V_83 , V_33 , V_229 ) ;
F_344 ( V_229 ) ;
F_345 ( V_229 ) ;
if ( V_33 -> V_225 . V_21 == V_200 ) {
if ( V_33 -> V_462 % 2 == 0 )
F_292 ( & V_33 -> V_463 , V_229 -> V_30 ,
V_229 -> V_30 + V_229 -> V_117 - 1 , V_38 ) ;
else
F_346 ( & V_33 -> V_463 , V_229 -> V_30 ,
V_229 -> V_30 + V_229 -> V_117 - 1 , V_38 ) ;
} else {
F_292 ( & V_83 -> V_90 -> V_464 , V_229 -> V_30 ,
V_229 -> V_30 + V_229 -> V_117 - 1 , V_38 ) ;
}
V_83 -> V_465 ++ ;
return V_229 ;
}
static struct V_304 *
F_347 ( struct V_82 * V_83 ,
struct V_32 * V_33 , T_3 V_461 )
{
struct V_304 * V_317 ;
struct V_304 * V_305 = & V_33 -> V_35 -> V_306 ;
int V_27 ;
V_317 = F_250 ( V_83 , V_33 ) ;
if ( V_317 -> V_54 == 0 ) {
V_27 = F_247 ( V_33 , V_317 , V_461 , 0 ) ;
if ( V_27 && V_317 != V_305 ) {
V_27 = F_251 ( V_305 , V_461 ) ;
if ( ! V_27 )
return V_305 ;
return F_339 ( V_27 ) ;
} else if ( V_27 ) {
return F_339 ( V_27 ) ;
}
return V_317 ;
}
V_27 = F_251 ( V_317 , V_461 ) ;
if ( ! V_27 )
return V_317 ;
if ( V_27 ) {
static F_348 ( V_466 ,
V_467 ,
2 ) ;
if ( F_349 ( & V_466 ) ) {
F_303 ( V_468 L_18 , V_27 ) ;
F_8 ( 1 ) ;
}
V_27 = F_247 ( V_33 , V_317 , V_461 , 0 ) ;
if ( ! V_27 ) {
return V_317 ;
} else if ( V_27 && V_317 != V_305 ) {
V_27 = F_251 ( V_305 , V_461 ) ;
if ( ! V_27 )
return V_305 ;
}
}
return F_339 ( - V_298 ) ;
}
static void F_350 ( struct V_304 * V_317 , T_3 V_461 )
{
F_252 ( V_317 , V_461 , 0 ) ;
F_253 ( V_317 , NULL , 0 ) ;
}
struct V_63 * F_351 ( struct V_82 * V_83 ,
struct V_32 * V_33 , T_3 V_461 ,
T_2 V_16 , T_2 V_148 ,
struct V_378 * V_20 , int V_168 ,
T_2 V_469 , T_2 V_415 )
{
struct V_65 V_206 ;
struct V_304 * V_317 ;
struct V_63 * V_229 ;
T_2 V_6 = 0 ;
int V_27 ;
V_317 = F_347 ( V_83 , V_33 , V_461 ) ;
if ( F_207 ( V_317 ) )
return F_352 ( V_317 ) ;
V_27 = F_329 ( V_83 , V_33 , V_461 , V_461 ,
V_415 , V_469 , ( T_2 ) - 1 , & V_206 , 0 ) ;
if ( V_27 ) {
F_350 ( V_317 , V_461 ) ;
return F_339 ( V_27 ) ;
}
V_229 = F_337 ( V_83 , V_33 , V_206 . V_21 ,
V_461 , V_168 ) ;
F_22 ( F_207 ( V_229 ) ) ;
if ( V_148 == V_470 ) {
if ( V_16 == 0 )
V_16 = V_206 . V_21 ;
V_6 |= V_131 ;
} else
F_22 ( V_16 > 0 ) ;
if ( V_148 != V_200 ) {
struct V_179 * V_133 ;
V_133 = F_180 ( sizeof( * V_133 ) , V_38 ) ;
F_22 ( ! V_133 ) ;
if ( V_20 )
memcpy ( & V_133 -> V_20 , V_20 , sizeof( V_133 -> V_20 ) ) ;
else
memset ( & V_133 -> V_20 , 0 , sizeof( V_133 -> V_20 ) ) ;
V_133 -> V_135 = V_6 ;
V_133 -> V_209 = 1 ;
V_133 -> V_134 = 1 ;
V_133 -> V_183 = 0 ;
V_27 = F_149 ( V_83 , V_206 . V_21 ,
V_206 . V_31 , V_16 , V_148 ,
V_168 , V_460 ,
V_133 ) ;
F_22 ( V_27 ) ;
}
return V_229 ;
}
static T_1 void F_353 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_471 * V_472 ,
struct V_61 * V_62 )
{
T_2 V_25 ;
T_2 V_250 ;
T_2 V_119 ;
T_2 V_6 ;
T_3 V_68 ;
T_3 V_461 ;
struct V_65 V_20 ;
struct V_63 * V_473 ;
int V_27 ;
int V_474 ;
int V_475 = 0 ;
if ( V_62 -> V_79 [ V_472 -> V_168 ] < V_472 -> V_476 ) {
V_472 -> V_477 = V_472 -> V_477 * 2 / 3 ;
V_472 -> V_477 = F_76 ( V_472 -> V_477 , 2 ) ;
} else {
V_472 -> V_477 = V_472 -> V_477 * 3 / 2 ;
V_472 -> V_477 = F_175 ( int , V_472 -> V_477 ,
F_354 ( V_33 ) ) ;
}
V_473 = V_62 -> V_78 [ V_472 -> V_168 ] ;
V_68 = F_37 ( V_473 ) ;
V_461 = F_198 ( V_33 , V_472 -> V_168 - 1 ) ;
for ( V_474 = V_62 -> V_79 [ V_472 -> V_168 ] ; V_474 < V_68 ; V_474 ++ ) {
if ( V_475 >= V_472 -> V_477 )
break;
F_46 () ;
V_25 = F_197 ( V_473 , V_474 ) ;
V_250 = F_355 ( V_473 , V_474 ) ;
if ( V_474 == V_62 -> V_79 [ V_472 -> V_168 ] )
goto V_72;
if ( V_472 -> V_478 == V_479 &&
V_250 <= V_33 -> V_225 . V_31 )
continue;
V_27 = F_80 ( V_83 , V_33 , V_25 , V_461 ,
& V_119 , & V_6 ) ;
F_22 ( V_27 ) ;
F_22 ( V_119 == 0 ) ;
if ( V_472 -> V_478 == V_480 ) {
if ( V_119 == 1 )
goto V_72;
if ( V_472 -> V_168 == 1 &&
( V_6 & V_131 ) )
continue;
if ( ! V_472 -> V_481 ||
V_250 <= V_33 -> V_225 . V_31 )
continue;
F_127 ( V_473 , & V_20 , V_474 ) ;
V_27 = F_356 ( & V_20 ,
& V_472 -> V_482 ) ;
if ( V_27 < 0 )
continue;
} else {
if ( V_472 -> V_168 == 1 &&
( V_6 & V_131 ) )
continue;
}
V_72:
V_27 = F_357 ( V_33 , V_25 , V_461 ,
V_250 ) ;
if ( V_27 )
break;
V_475 ++ ;
}
V_472 -> V_476 = V_474 ;
}
static T_1 int F_358 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_61 * V_62 ,
struct V_471 * V_472 , int V_483 )
{
int V_168 = V_472 -> V_168 ;
struct V_63 * V_473 = V_62 -> V_78 [ V_168 ] ;
T_2 V_484 = V_131 ;
int V_27 ;
if ( V_472 -> V_478 == V_479 &&
F_190 ( V_473 ) != V_33 -> V_225 . V_21 )
return 1 ;
if ( V_483 &&
( ( V_472 -> V_478 == V_480 && V_472 -> V_119 [ V_168 ] != 1 ) ||
( V_472 -> V_478 == V_479 && ! ( V_472 -> V_6 [ V_168 ] & V_484 ) ) ) ) {
F_22 ( ! V_62 -> V_485 [ V_168 ] ) ;
V_27 = F_80 ( V_83 , V_33 ,
V_473 -> V_30 , V_473 -> V_117 ,
& V_472 -> V_119 [ V_168 ] ,
& V_472 -> V_6 [ V_168 ] ) ;
F_22 ( V_27 ) ;
F_22 ( V_472 -> V_119 [ V_168 ] == 0 ) ;
}
if ( V_472 -> V_478 == V_480 ) {
if ( V_472 -> V_119 [ V_168 ] > 1 )
return 1 ;
if ( V_62 -> V_485 [ V_168 ] && ! V_472 -> V_174 ) {
F_359 ( V_473 , V_62 -> V_485 [ V_168 ] ) ;
V_62 -> V_485 [ V_168 ] = 0 ;
}
return 0 ;
}
if ( ! ( V_472 -> V_6 [ V_168 ] & V_484 ) ) {
F_22 ( ! V_62 -> V_485 [ V_168 ] ) ;
V_27 = F_199 ( V_83 , V_33 , V_473 , 1 ) ;
F_22 ( V_27 ) ;
V_27 = F_200 ( V_83 , V_33 , V_473 , 0 ) ;
F_22 ( V_27 ) ;
V_27 = F_179 ( V_83 , V_33 , V_473 -> V_30 ,
V_473 -> V_117 , V_484 , 0 ) ;
F_22 ( V_27 ) ;
V_472 -> V_6 [ V_168 ] |= V_484 ;
}
if ( V_62 -> V_485 [ V_168 ] && V_168 > 0 ) {
F_359 ( V_473 , V_62 -> V_485 [ V_168 ] ) ;
V_62 -> V_485 [ V_168 ] = 0 ;
}
return 0 ;
}
static T_1 int F_360 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_61 * V_62 ,
struct V_471 * V_472 , int * V_483 )
{
T_2 V_25 ;
T_2 V_250 ;
T_2 V_16 ;
T_3 V_461 ;
struct V_65 V_20 ;
struct V_63 * V_216 ;
int V_168 = V_472 -> V_168 ;
int V_72 = 0 ;
int V_27 = 0 ;
V_250 = F_355 ( V_62 -> V_78 [ V_168 ] ,
V_62 -> V_79 [ V_168 ] ) ;
if ( V_472 -> V_478 == V_479 &&
V_250 <= V_33 -> V_225 . V_31 ) {
* V_483 = 1 ;
return 1 ;
}
V_25 = F_197 ( V_62 -> V_78 [ V_168 ] , V_62 -> V_79 [ V_168 ] ) ;
V_461 = F_198 ( V_33 , V_168 - 1 ) ;
V_216 = F_361 ( V_33 , V_25 , V_461 ) ;
if ( ! V_216 ) {
V_216 = F_338 ( V_33 , V_25 , V_461 ) ;
if ( ! V_216 )
return - V_118 ;
V_72 = 1 ;
}
F_342 ( V_216 ) ;
F_344 ( V_216 ) ;
V_27 = F_80 ( V_83 , V_33 , V_25 , V_461 ,
& V_472 -> V_119 [ V_168 - 1 ] ,
& V_472 -> V_6 [ V_168 - 1 ] ) ;
F_22 ( V_27 ) ;
F_22 ( V_472 -> V_119 [ V_168 - 1 ] == 0 ) ;
* V_483 = 0 ;
if ( V_472 -> V_478 == V_480 ) {
if ( V_472 -> V_119 [ V_168 - 1 ] > 1 ) {
if ( V_168 == 1 &&
( V_472 -> V_6 [ 0 ] & V_131 ) )
goto V_486;
if ( ! V_472 -> V_481 ||
V_250 <= V_33 -> V_225 . V_31 )
goto V_486;
F_127 ( V_62 -> V_78 [ V_168 ] , & V_20 ,
V_62 -> V_79 [ V_168 ] ) ;
V_27 = F_356 ( & V_20 , & V_472 -> V_482 ) ;
if ( V_27 < 0 )
goto V_486;
V_472 -> V_478 = V_479 ;
V_472 -> V_487 = V_168 - 1 ;
}
} else {
if ( V_168 == 1 &&
( V_472 -> V_6 [ 0 ] & V_131 ) )
goto V_486;
}
if ( ! F_362 ( V_216 , V_250 ) ) {
F_363 ( V_216 ) ;
F_364 ( V_216 ) ;
V_216 = NULL ;
* V_483 = 1 ;
}
if ( ! V_216 ) {
if ( V_72 && V_168 == 1 )
F_353 ( V_83 , V_33 , V_472 , V_62 ) ;
V_216 = F_365 ( V_33 , V_25 , V_461 , V_250 ) ;
if ( ! V_216 )
return - V_211 ;
F_342 ( V_216 ) ;
F_344 ( V_216 ) ;
}
V_168 -- ;
F_22 ( V_168 != F_191 ( V_216 ) ) ;
V_62 -> V_78 [ V_168 ] = V_216 ;
V_62 -> V_79 [ V_168 ] = 0 ;
V_62 -> V_485 [ V_168 ] = V_488 ;
V_472 -> V_168 = V_168 ;
if ( V_472 -> V_168 == 1 )
V_472 -> V_476 = 0 ;
return 0 ;
V_486:
V_472 -> V_119 [ V_168 - 1 ] = 0 ;
V_472 -> V_6 [ V_168 - 1 ] = 0 ;
if ( V_472 -> V_478 == V_480 ) {
if ( V_472 -> V_6 [ V_168 ] & V_131 ) {
V_16 = V_62 -> V_78 [ V_168 ] -> V_30 ;
} else {
F_22 ( V_33 -> V_225 . V_21 !=
F_190 ( V_62 -> V_78 [ V_168 ] ) ) ;
V_16 = 0 ;
}
V_27 = V_235 ( V_83 , V_33 , V_25 , V_461 , V_16 ,
V_33 -> V_225 . V_21 , V_168 - 1 , 0 ) ;
F_22 ( V_27 ) ;
}
F_363 ( V_216 ) ;
F_364 ( V_216 ) ;
* V_483 = 1 ;
return 1 ;
}
static T_1 int F_366 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_61 * V_62 ,
struct V_471 * V_472 )
{
int V_27 ;
int V_168 = V_472 -> V_168 ;
struct V_63 * V_473 = V_62 -> V_78 [ V_168 ] ;
T_2 V_16 = 0 ;
if ( V_472 -> V_478 == V_479 ) {
F_22 ( V_472 -> V_487 < V_168 ) ;
if ( V_168 < V_472 -> V_487 )
goto V_69;
V_27 = F_40 ( V_62 , V_168 + 1 , & V_472 -> V_482 ) ;
if ( V_27 > 0 )
V_472 -> V_481 = 0 ;
V_472 -> V_478 = V_480 ;
V_472 -> V_487 = - 1 ;
V_62 -> V_79 [ V_168 ] = 0 ;
if ( ! V_62 -> V_485 [ V_168 ] ) {
F_22 ( V_168 == 0 ) ;
F_342 ( V_473 ) ;
F_344 ( V_473 ) ;
V_62 -> V_485 [ V_168 ] = V_488 ;
V_27 = F_80 ( V_83 , V_33 ,
V_473 -> V_30 , V_473 -> V_117 ,
& V_472 -> V_119 [ V_168 ] ,
& V_472 -> V_6 [ V_168 ] ) ;
F_22 ( V_27 ) ;
F_22 ( V_472 -> V_119 [ V_168 ] == 0 ) ;
if ( V_472 -> V_119 [ V_168 ] == 1 ) {
F_359 ( V_473 , V_62 -> V_485 [ V_168 ] ) ;
return 1 ;
}
}
}
F_22 ( V_472 -> V_119 [ V_168 ] > 1 && ! V_62 -> V_485 [ V_168 ] ) ;
if ( V_472 -> V_119 [ V_168 ] == 1 ) {
if ( V_168 == 0 ) {
if ( V_472 -> V_6 [ V_168 ] & V_131 )
V_27 = F_200 ( V_83 , V_33 , V_473 , 1 ) ;
else
V_27 = F_200 ( V_83 , V_33 , V_473 , 0 ) ;
F_22 ( V_27 ) ;
}
if ( ! V_62 -> V_485 [ V_168 ] &&
F_310 ( V_473 ) == V_83 -> V_247 ) {
F_342 ( V_473 ) ;
F_344 ( V_473 ) ;
V_62 -> V_485 [ V_168 ] = V_488 ;
}
F_343 ( V_83 , V_33 , V_473 ) ;
}
if ( V_473 == V_33 -> V_132 ) {
if ( V_472 -> V_6 [ V_168 ] & V_131 )
V_16 = V_473 -> V_30 ;
else
F_22 ( V_33 -> V_225 . V_21 !=
F_190 ( V_473 ) ) ;
} else {
if ( V_472 -> V_6 [ V_168 + 1 ] & V_131 )
V_16 = V_62 -> V_78 [ V_168 + 1 ] -> V_30 ;
else
F_22 ( V_33 -> V_225 . V_21 !=
F_190 ( V_62 -> V_78 [ V_168 + 1 ] ) ) ;
}
F_309 ( V_83 , V_33 , V_473 , V_16 , V_472 -> V_119 [ V_168 ] == 1 ) ;
V_69:
V_472 -> V_119 [ V_168 ] = 0 ;
V_472 -> V_6 [ V_168 ] = 0 ;
return 0 ;
}
static T_1 int F_367 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_61 * V_62 ,
struct V_471 * V_472 )
{
int V_168 = V_472 -> V_168 ;
int V_483 = 1 ;
int V_27 ;
while ( V_168 >= 0 ) {
V_27 = F_358 ( V_83 , V_33 , V_62 , V_472 , V_483 ) ;
if ( V_27 > 0 )
break;
if ( V_168 == 0 )
break;
if ( V_62 -> V_79 [ V_168 ] >=
F_37 ( V_62 -> V_78 [ V_168 ] ) )
break;
V_27 = F_360 ( V_83 , V_33 , V_62 , V_472 , & V_483 ) ;
if ( V_27 > 0 ) {
V_62 -> V_79 [ V_168 ] ++ ;
continue;
} else if ( V_27 < 0 )
return V_27 ;
V_168 = V_472 -> V_168 ;
}
return 0 ;
}
static T_1 int F_368 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_61 * V_62 ,
struct V_471 * V_472 , int V_489 )
{
int V_168 = V_472 -> V_168 ;
int V_27 ;
V_62 -> V_79 [ V_168 ] = F_37 ( V_62 -> V_78 [ V_168 ] ) ;
while ( V_168 < V_489 && V_62 -> V_78 [ V_168 ] ) {
V_472 -> V_168 = V_168 ;
if ( V_62 -> V_79 [ V_168 ] + 1 <
F_37 ( V_62 -> V_78 [ V_168 ] ) ) {
V_62 -> V_79 [ V_168 ] ++ ;
return 0 ;
} else {
V_27 = F_366 ( V_83 , V_33 , V_62 , V_472 ) ;
if ( V_27 > 0 )
return 0 ;
if ( V_62 -> V_485 [ V_168 ] ) {
F_359 ( V_62 -> V_78 [ V_168 ] ,
V_62 -> V_485 [ V_168 ] ) ;
V_62 -> V_485 [ V_168 ] = 0 ;
}
F_364 ( V_62 -> V_78 [ V_168 ] ) ;
V_62 -> V_78 [ V_168 ] = NULL ;
V_168 ++ ;
}
}
return 1 ;
}
void F_369 ( struct V_32 * V_33 ,
struct V_304 * V_317 , int V_481 )
{
struct V_61 * V_62 ;
struct V_82 * V_83 ;
struct V_32 * V_92 = V_33 -> V_35 -> V_92 ;
struct V_490 * V_226 = & V_33 -> V_226 ;
struct V_471 * V_472 ;
struct V_65 V_20 ;
int V_77 = 0 ;
int V_27 ;
int V_168 ;
V_62 = F_32 () ;
if ( ! V_62 ) {
V_77 = - V_118 ;
goto V_69;
}
V_472 = F_51 ( sizeof( * V_472 ) , V_38 ) ;
if ( ! V_472 ) {
F_48 ( V_62 ) ;
V_77 = - V_118 ;
goto V_69;
}
V_83 = F_370 ( V_92 , 0 ) ;
F_22 ( F_207 ( V_83 ) ) ;
if ( V_317 )
V_83 -> V_317 = V_317 ;
if ( F_371 ( & V_226 -> V_491 ) == 0 ) {
V_168 = F_191 ( V_33 -> V_132 ) ;
V_62 -> V_78 [ V_168 ] = F_372 ( V_33 ) ;
F_344 ( V_62 -> V_78 [ V_168 ] ) ;
V_62 -> V_79 [ V_168 ] = 0 ;
V_62 -> V_485 [ V_168 ] = V_488 ;
memset ( & V_472 -> V_482 , 0 ,
sizeof( V_472 -> V_482 ) ) ;
} else {
F_373 ( & V_20 , & V_226 -> V_491 ) ;
memcpy ( & V_472 -> V_482 , & V_20 ,
sizeof( V_472 -> V_482 ) ) ;
V_168 = V_226 -> V_492 ;
F_22 ( V_168 == 0 ) ;
V_62 -> V_493 = V_168 ;
V_27 = F_36 ( NULL , V_33 , & V_20 , V_62 , 0 , 0 ) ;
V_62 -> V_493 = 0 ;
if ( V_27 < 0 ) {
V_77 = V_27 ;
goto V_128;
}
F_8 ( V_27 > 0 ) ;
F_132 ( V_62 , 0 ) ;
V_168 = F_191 ( V_33 -> V_132 ) ;
while ( 1 ) {
F_342 ( V_62 -> V_78 [ V_168 ] ) ;
F_344 ( V_62 -> V_78 [ V_168 ] ) ;
V_27 = F_80 ( V_83 , V_33 ,
V_62 -> V_78 [ V_168 ] -> V_30 ,
V_62 -> V_78 [ V_168 ] -> V_117 ,
& V_472 -> V_119 [ V_168 ] ,
& V_472 -> V_6 [ V_168 ] ) ;
F_22 ( V_27 ) ;
F_22 ( V_472 -> V_119 [ V_168 ] == 0 ) ;
if ( V_168 == V_226 -> V_492 )
break;
F_363 ( V_62 -> V_78 [ V_168 ] ) ;
F_8 ( V_472 -> V_119 [ V_168 ] != 1 ) ;
V_168 -- ;
}
}
V_472 -> V_168 = V_168 ;
V_472 -> V_487 = - 1 ;
V_472 -> V_478 = V_480 ;
V_472 -> V_481 = V_481 ;
V_472 -> V_174 = 0 ;
V_472 -> V_477 = F_354 ( V_33 ) ;
while ( 1 ) {
V_27 = F_367 ( V_83 , V_33 , V_62 , V_472 ) ;
if ( V_27 < 0 ) {
V_77 = V_27 ;
break;
}
V_27 = F_368 ( V_83 , V_33 , V_62 , V_472 , V_169 ) ;
if ( V_27 < 0 ) {
V_77 = V_27 ;
break;
}
if ( V_27 > 0 ) {
F_22 ( V_472 -> V_478 != V_480 ) ;
break;
}
if ( V_472 -> V_478 == V_480 ) {
V_168 = V_472 -> V_168 ;
F_374 ( V_62 -> V_78 [ V_168 ] ,
& V_226 -> V_491 ,
V_62 -> V_79 [ V_168 ] ) ;
V_226 -> V_492 = V_168 ;
}
F_22 ( V_472 -> V_168 == 0 ) ;
if ( F_375 ( V_83 , V_92 ) ) {
V_27 = F_376 ( V_83 , V_92 ,
& V_33 -> V_225 ,
V_226 ) ;
F_22 ( V_27 ) ;
F_377 ( V_83 , V_92 ) ;
V_83 = F_370 ( V_92 , 0 ) ;
F_22 ( F_207 ( V_83 ) ) ;
if ( V_317 )
V_83 -> V_317 = V_317 ;
}
}
F_43 ( V_62 ) ;
F_22 ( V_77 ) ;
V_27 = F_378 ( V_83 , V_92 , & V_33 -> V_225 ) ;
F_22 ( V_27 ) ;
if ( V_33 -> V_225 . V_21 != V_470 ) {
V_27 = F_379 ( V_92 , V_33 -> V_225 . V_21 ,
NULL , NULL ) ;
F_22 ( V_27 < 0 ) ;
if ( V_27 > 0 ) {
F_380 ( V_83 , V_92 ,
V_33 -> V_225 . V_21 ) ;
}
}
if ( V_33 -> V_494 ) {
F_381 ( V_92 -> V_35 , V_33 ) ;
} else {
F_364 ( V_33 -> V_132 ) ;
F_364 ( V_33 -> V_495 ) ;
F_9 ( V_33 ) ;
}
V_128:
F_377 ( V_83 , V_92 ) ;
F_9 ( V_472 ) ;
F_48 ( V_62 ) ;
V_69:
if ( V_77 )
F_382 ( V_33 -> V_35 , V_77 ) ;
return;
}
int F_383 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_63 * V_132 ,
struct V_63 * V_16 )
{
struct V_61 * V_62 ;
struct V_471 * V_472 ;
int V_168 ;
int V_496 ;
int V_27 = 0 ;
int V_497 ;
F_22 ( V_33 -> V_225 . V_21 != V_470 ) ;
V_62 = F_32 () ;
if ( ! V_62 )
return - V_118 ;
V_472 = F_51 ( sizeof( * V_472 ) , V_38 ) ;
if ( ! V_472 ) {
F_48 ( V_62 ) ;
return - V_118 ;
}
F_384 ( V_16 ) ;
V_496 = F_191 ( V_16 ) ;
F_385 ( V_16 ) ;
V_62 -> V_78 [ V_496 ] = V_16 ;
V_62 -> V_79 [ V_496 ] = F_37 ( V_16 ) ;
F_384 ( V_132 ) ;
V_168 = F_191 ( V_132 ) ;
V_62 -> V_78 [ V_168 ] = V_132 ;
V_62 -> V_79 [ V_168 ] = 0 ;
V_62 -> V_485 [ V_168 ] = V_488 ;
V_472 -> V_119 [ V_496 ] = 1 ;
V_472 -> V_6 [ V_496 ] = V_131 ;
V_472 -> V_168 = V_168 ;
V_472 -> V_487 = - 1 ;
V_472 -> V_478 = V_480 ;
V_472 -> V_481 = 0 ;
V_472 -> V_174 = 1 ;
V_472 -> V_477 = F_354 ( V_33 ) ;
while ( 1 ) {
V_497 = F_367 ( V_83 , V_33 , V_62 , V_472 ) ;
if ( V_497 < 0 ) {
V_27 = V_497 ;
break;
}
V_497 = F_368 ( V_83 , V_33 , V_62 , V_472 , V_496 ) ;
if ( V_497 < 0 )
V_27 = V_497 ;
if ( V_497 != 0 )
break;
}
F_9 ( V_472 ) ;
F_48 ( V_62 ) ;
return V_27 ;
}
static T_2 F_386 ( struct V_32 * V_33 , T_2 V_6 )
{
T_2 V_279 ;
T_2 V_498 = V_275 |
V_259 | V_260 ;
V_279 = V_33 -> V_35 -> V_280 -> V_281 +
V_33 -> V_35 -> V_280 -> V_282 ;
if ( V_279 == 1 ) {
V_498 |= V_258 ;
V_498 = V_6 & ~ V_498 ;
if ( V_6 & V_275 )
return V_498 ;
if ( V_6 & ( V_259 |
V_260 ) )
return V_498 | V_258 ;
return V_6 ;
} else {
if ( V_6 & V_498 )
return V_6 ;
V_498 |= V_258 ;
V_498 = V_6 & ~ V_498 ;
if ( V_6 & V_258 )
return V_498 | V_259 ;
return V_498 | V_275 ;
}
return V_6 ;
}
static int F_387 ( struct V_1 * V_2 , int V_303 )
{
struct V_97 * V_301 = V_2 -> V_100 ;
T_2 V_34 ;
T_2 V_499 ;
int V_27 = - V_298 ;
if ( ( V_301 -> V_6 &
( V_103 | V_104 ) ) &&
! V_303 )
V_499 = 1 * 1024 * 1024 ;
else
V_499 = 0 ;
F_11 ( & V_301 -> V_49 ) ;
F_11 ( & V_2 -> V_49 ) ;
if ( V_2 -> V_116 ) {
V_27 = 0 ;
goto V_69;
}
V_34 = V_2 -> V_20 . V_31 - V_2 -> V_9 - V_2 -> V_8 -
V_2 -> V_44 - F_77 ( & V_2 -> V_115 ) ;
if ( V_301 -> V_257 + V_301 -> V_267 + V_301 -> V_266 +
V_301 -> V_269 + V_301 -> V_268 + V_34 +
V_499 <= V_301 -> V_256 ) {
V_301 -> V_268 += V_34 ;
V_2 -> V_116 = 1 ;
V_27 = 0 ;
}
V_69:
F_13 ( & V_2 -> V_49 ) ;
F_13 ( & V_301 -> V_49 ) ;
return V_27 ;
}
int F_388 ( struct V_32 * V_33 ,
struct V_1 * V_2 )
{
struct V_82 * V_83 ;
T_2 V_500 ;
int V_27 ;
F_22 ( V_2 -> V_116 ) ;
V_83 = F_231 ( V_33 ) ;
F_22 ( F_207 ( V_83 ) ) ;
V_500 = F_386 ( V_33 , V_2 -> V_6 ) ;
if ( V_500 != V_2 -> V_6 )
F_232 ( V_83 , V_33 , 2 * 1024 * 1024 , V_500 ,
V_297 ) ;
V_27 = F_387 ( V_2 , 0 ) ;
if ( ! V_27 )
goto V_69;
V_500 = F_228 ( V_33 , V_2 -> V_100 -> V_6 ) ;
V_27 = F_232 ( V_83 , V_33 , 2 * 1024 * 1024 , V_500 ,
V_297 ) ;
if ( V_27 < 0 )
goto V_69;
V_27 = F_387 ( V_2 , 0 ) ;
V_69:
F_233 ( V_83 , V_33 ) ;
return V_27 ;
}
int F_389 ( struct V_82 * V_83 ,
struct V_32 * V_33 , T_2 type )
{
T_2 V_500 = F_228 ( V_33 , type ) ;
return F_232 ( V_83 , V_33 , 2 * 1024 * 1024 , V_500 ,
V_297 ) ;
}
static T_2 F_390 ( struct V_98 * V_501 )
{
struct V_1 * V_13 ;
T_2 V_502 = 0 ;
int V_107 ;
F_320 (block_group, groups_list, list) {
F_11 ( & V_13 -> V_49 ) ;
if ( ! V_13 -> V_116 ) {
F_13 ( & V_13 -> V_49 ) ;
continue;
}
if ( V_13 -> V_6 & ( V_259 |
V_260 |
V_258 ) )
V_107 = 2 ;
else
V_107 = 1 ;
V_502 += ( V_13 -> V_20 . V_31 -
F_77 ( & V_13 -> V_115 ) ) *
V_107 ;
F_13 ( & V_13 -> V_49 ) ;
}
return V_502 ;
}
T_2 F_391 ( struct V_97 * V_301 )
{
int V_41 ;
T_2 V_502 = 0 ;
F_11 ( & V_301 -> V_49 ) ;
for( V_41 = 0 ; V_41 < V_263 ; V_41 ++ )
if ( ! F_167 ( & V_301 -> V_264 [ V_41 ] ) )
V_502 += F_390 (
& V_301 -> V_264 [ V_41 ] ) ;
F_13 ( & V_301 -> V_49 ) ;
return V_502 ;
}
int F_392 ( struct V_32 * V_33 ,
struct V_1 * V_2 )
{
struct V_97 * V_301 = V_2 -> V_100 ;
T_2 V_34 ;
F_22 ( ! V_2 -> V_116 ) ;
F_11 ( & V_301 -> V_49 ) ;
F_11 ( & V_2 -> V_49 ) ;
V_34 = V_2 -> V_20 . V_31 - V_2 -> V_9 - V_2 -> V_8 -
V_2 -> V_44 - F_77 ( & V_2 -> V_115 ) ;
V_301 -> V_268 -= V_34 ;
V_2 -> V_116 = 0 ;
F_13 ( & V_2 -> V_49 ) ;
F_13 ( & V_301 -> V_49 ) ;
return 0 ;
}
int F_393 ( struct V_32 * V_33 , T_2 V_25 )
{
struct V_1 * V_13 ;
struct V_97 * V_100 ;
struct V_503 * V_280 = V_33 -> V_35 -> V_280 ;
struct V_504 * V_505 ;
T_2 V_506 ;
T_2 V_507 = 1 ;
T_2 V_508 = 0 ;
int V_413 ;
int V_105 = 0 ;
int V_27 = 0 ;
V_13 = F_66 ( V_33 -> V_35 , V_25 ) ;
if ( ! V_13 )
return - 1 ;
V_506 = F_77 ( & V_13 -> V_115 ) ;
if ( ! V_506 )
goto V_69;
V_100 = V_13 -> V_100 ;
F_11 ( & V_100 -> V_49 ) ;
V_105 = V_100 -> V_105 ;
if ( ( V_100 -> V_256 != V_13 -> V_20 . V_31 ) &&
( V_100 -> V_257 + V_100 -> V_267 +
V_100 -> V_266 + V_100 -> V_268 +
V_506 < V_100 -> V_256 ) ) {
F_13 ( & V_100 -> V_49 ) ;
goto V_69;
}
F_13 ( & V_100 -> V_49 ) ;
V_27 = - 1 ;
if ( V_105 )
goto V_69;
V_413 = F_318 ( V_13 ) ;
if ( V_413 == 0 ) {
V_507 = 4 ;
V_506 >>= 1 ;
} else if ( V_413 == 1 ) {
V_507 = 2 ;
} else if ( V_413 == 2 ) {
V_506 <<= 1 ;
} else if ( V_413 == 3 ) {
V_507 = V_280 -> V_281 ;
F_73 ( V_506 , V_507 ) ;
}
F_34 ( & V_33 -> V_35 -> V_312 ) ;
F_320 (device, &fs_devices->alloc_list, dev_alloc_list) {
T_2 V_509 ;
if ( V_505 -> V_256 > V_505 -> V_257 + V_506 ) {
V_27 = F_394 ( NULL , V_505 , V_506 ,
& V_509 , NULL ) ;
if ( ! V_27 )
V_508 ++ ;
if ( V_508 >= V_507 )
break;
V_27 = - 1 ;
}
}
F_45 ( & V_33 -> V_35 -> V_312 ) ;
V_69:
F_6 ( V_13 ) ;
return V_27 ;
}
static int F_395 ( struct V_32 * V_33 ,
struct V_61 * V_62 , struct V_65 * V_20 )
{
int V_27 = 0 ;
struct V_65 V_142 ;
struct V_63 * V_64 ;
int V_474 ;
V_27 = F_36 ( NULL , V_33 , V_20 , V_62 , 0 , 0 ) ;
if ( V_27 < 0 )
goto V_69;
while ( 1 ) {
V_474 = V_62 -> V_79 [ 0 ] ;
V_64 = V_62 -> V_78 [ 0 ] ;
if ( V_474 >= F_37 ( V_64 ) ) {
V_27 = F_42 ( V_33 , V_62 ) ;
if ( V_27 == 0 )
continue;
if ( V_27 < 0 )
goto V_69;
break;
}
F_39 ( V_64 , & V_142 , V_474 ) ;
if ( V_142 . V_21 >= V_20 -> V_21 &&
V_142 . type == V_178 ) {
V_27 = 0 ;
goto V_69;
}
V_62 -> V_79 [ 0 ] ++ ;
}
V_69:
return V_27 ;
}
void F_396 ( struct V_11 * V_12 )
{
struct V_1 * V_13 ;
T_2 V_67 = 0 ;
while ( 1 ) {
struct V_238 * V_238 ;
V_13 = F_65 ( V_12 , V_67 ) ;
while ( V_13 ) {
F_11 ( & V_13 -> V_49 ) ;
if ( V_13 -> V_165 )
break;
F_13 ( & V_13 -> V_49 ) ;
V_13 = F_204 ( V_12 -> V_92 ,
V_13 ) ;
}
if ( ! V_13 ) {
if ( V_67 == 0 )
break;
V_67 = 0 ;
continue;
}
V_238 = V_13 -> V_238 ;
V_13 -> V_165 = 0 ;
V_13 -> V_238 = NULL ;
F_13 ( & V_13 -> V_49 ) ;
F_218 ( V_238 ) ;
V_67 = V_13 -> V_20 . V_21 + V_13 -> V_20 . V_31 ;
F_6 ( V_13 ) ;
}
}
int F_397 ( struct V_11 * V_12 )
{
struct V_1 * V_13 ;
struct V_97 * V_100 ;
struct V_47 * V_51 ;
struct V_14 * V_28 ;
F_61 ( & V_12 -> V_76 ) ;
while ( ! F_167 ( & V_12 -> V_95 ) ) {
V_51 = F_168 ( V_12 -> V_95 . V_216 ,
struct V_47 , V_85 ) ;
F_398 ( & V_51 -> V_85 ) ;
F_26 ( V_51 ) ;
}
F_63 ( & V_12 -> V_76 ) ;
F_11 ( & V_12 -> V_17 ) ;
while ( ( V_28 = F_399 ( & V_12 -> V_18 ) ) != NULL ) {
V_13 = F_12 ( V_28 , struct V_1 ,
V_19 ) ;
F_172 ( & V_13 -> V_19 ,
& V_12 -> V_18 ) ;
F_13 ( & V_12 -> V_17 ) ;
F_61 ( & V_13 -> V_100 -> V_265 ) ;
F_398 ( & V_13 -> V_85 ) ;
F_63 ( & V_13 -> V_100 -> V_265 ) ;
if ( V_13 -> V_3 == V_50 )
F_317 ( V_13 ) ;
if ( V_13 -> V_3 == V_89 )
F_19 ( V_12 -> V_60 , V_13 ) ;
F_400 ( V_13 ) ;
F_6 ( V_13 ) ;
F_11 ( & V_12 -> V_17 ) ;
}
F_13 ( & V_12 -> V_17 ) ;
F_401 () ;
F_272 ( V_12 ) ;
while( ! F_167 ( & V_12 -> V_100 ) ) {
V_100 = F_168 ( V_12 -> V_100 . V_216 ,
struct V_97 ,
V_85 ) ;
if ( V_100 -> V_266 > 0 ||
V_100 -> V_267 > 0 ||
V_100 -> V_269 > 0 ) {
F_8 ( 1 ) ;
F_327 ( V_100 , 0 , 0 ) ;
}
F_398 ( & V_100 -> V_85 ) ;
F_9 ( V_100 ) ;
}
return 0 ;
}
static void F_402 ( struct V_97 * V_100 ,
struct V_1 * V_2 )
{
int V_413 = F_318 ( V_2 ) ;
F_61 ( & V_100 -> V_265 ) ;
F_62 ( & V_2 -> V_85 , & V_100 -> V_264 [ V_413 ] ) ;
F_63 ( & V_100 -> V_265 ) ;
}
int F_403 ( struct V_32 * V_33 )
{
struct V_61 * V_62 ;
int V_27 ;
struct V_1 * V_2 ;
struct V_11 * V_12 = V_33 -> V_35 ;
struct V_97 * V_100 ;
struct V_65 V_20 ;
struct V_65 V_142 ;
struct V_63 * V_64 ;
int V_510 = 0 ;
T_2 V_511 ;
V_33 = V_12 -> V_60 ;
V_20 . V_21 = 0 ;
V_20 . V_31 = 0 ;
F_79 ( & V_20 , V_178 ) ;
V_62 = F_32 () ;
if ( ! V_62 )
return - V_118 ;
V_62 -> V_72 = 1 ;
V_511 = F_404 ( V_33 -> V_35 -> V_310 ) ;
if ( F_59 ( V_33 , V_93 ) &&
F_405 ( V_33 -> V_35 -> V_310 ) != V_511 )
V_510 = 1 ;
if ( F_59 ( V_33 , V_512 ) )
V_510 = 1 ;
while ( 1 ) {
V_27 = F_395 ( V_33 , V_62 , & V_20 ) ;
if ( V_27 > 0 )
break;
if ( V_27 != 0 )
goto error;
V_64 = V_62 -> V_78 [ 0 ] ;
F_39 ( V_64 , & V_142 , V_62 -> V_79 [ 0 ] ) ;
V_2 = F_51 ( sizeof( * V_2 ) , V_38 ) ;
if ( ! V_2 ) {
V_27 = - V_118 ;
goto error;
}
V_2 -> V_10 = F_51 ( sizeof( * V_2 -> V_10 ) ,
V_38 ) ;
if ( ! V_2 -> V_10 ) {
F_9 ( V_2 ) ;
V_27 = - V_118 ;
goto error;
}
F_55 ( & V_2 -> V_7 , 1 ) ;
F_224 ( & V_2 -> V_49 ) ;
V_2 -> V_35 = V_12 ;
F_52 ( & V_2 -> V_85 ) ;
F_52 ( & V_2 -> V_513 ) ;
if ( V_510 )
V_2 -> V_244 = V_252 ;
F_406 ( V_64 , & V_2 -> V_115 ,
F_202 ( V_64 , V_62 -> V_79 [ 0 ] ) ,
sizeof( V_2 -> V_115 ) ) ;
memcpy ( & V_2 -> V_20 , & V_142 , sizeof( V_142 ) ) ;
V_20 . V_21 = V_142 . V_21 + V_142 . V_31 ;
F_43 ( V_62 ) ;
V_2 -> V_6 = F_407 ( & V_2 -> V_115 ) ;
V_2 -> V_292 = V_33 -> V_292 ;
F_408 ( V_2 ) ;
F_21 ( V_33 , V_2 ) ;
if ( V_142 . V_31 == F_77 ( & V_2 -> V_115 ) ) {
V_2 -> V_94 = ( T_2 ) - 1 ;
V_2 -> V_3 = V_4 ;
F_19 ( V_33 , V_2 ) ;
} else if ( F_77 ( & V_2 -> V_115 ) == 0 ) {
V_2 -> V_94 = ( T_2 ) - 1 ;
V_2 -> V_3 = V_4 ;
F_27 ( V_2 , V_33 -> V_35 ,
V_142 . V_21 ,
V_142 . V_21 +
V_142 . V_31 ) ;
F_19 ( V_33 , V_2 ) ;
}
V_27 = F_222 ( V_12 , V_2 -> V_6 , V_142 . V_31 ,
F_77 ( & V_2 -> V_115 ) ,
& V_100 ) ;
F_22 ( V_27 ) ;
V_2 -> V_100 = V_100 ;
F_11 ( & V_2 -> V_100 -> V_49 ) ;
V_2 -> V_100 -> V_268 += V_2 -> V_44 ;
F_13 ( & V_2 -> V_100 -> V_49 ) ;
F_402 ( V_100 , V_2 ) ;
V_27 = F_10 ( V_33 -> V_35 , V_2 ) ;
F_22 ( V_27 ) ;
F_226 ( V_33 -> V_35 , V_2 -> V_6 ) ;
if ( F_409 ( V_33 , V_2 -> V_20 . V_21 ) )
F_387 ( V_2 , 1 ) ;
}
F_69 (space_info, &root->fs_info->space_info, list) {
if ( ! ( F_228 ( V_33 , V_100 -> V_6 ) &
( V_260 |
V_259 |
V_258 ) ) )
continue;
F_320 (cache, &space_info->block_groups[3], list)
F_387 ( V_2 , 1 ) ;
F_320 (cache, &space_info->block_groups[4], list)
F_387 ( V_2 , 1 ) ;
}
F_271 ( V_12 ) ;
V_27 = 0 ;
error:
F_48 ( V_62 ) ;
return V_27 ;
}
int F_410 ( struct V_82 * V_83 ,
struct V_32 * V_33 , T_2 V_257 ,
T_2 type , T_2 V_514 , T_2 V_515 ,
T_2 V_54 )
{
int V_27 ;
struct V_32 * V_60 ;
struct V_1 * V_2 ;
V_60 = V_33 -> V_35 -> V_60 ;
V_33 -> V_35 -> V_516 = V_83 -> V_247 ;
V_2 = F_51 ( sizeof( * V_2 ) , V_38 ) ;
if ( ! V_2 )
return - V_118 ;
V_2 -> V_10 = F_51 ( sizeof( * V_2 -> V_10 ) ,
V_38 ) ;
if ( ! V_2 -> V_10 ) {
F_9 ( V_2 ) ;
return - V_118 ;
}
V_2 -> V_20 . V_21 = V_515 ;
V_2 -> V_20 . V_31 = V_54 ;
V_2 -> V_20 . type = V_178 ;
V_2 -> V_292 = V_33 -> V_292 ;
V_2 -> V_35 = V_33 -> V_35 ;
F_55 ( & V_2 -> V_7 , 1 ) ;
F_224 ( & V_2 -> V_49 ) ;
F_52 ( & V_2 -> V_85 ) ;
F_52 ( & V_2 -> V_513 ) ;
F_408 ( V_2 ) ;
F_291 ( & V_2 -> V_115 , V_257 ) ;
F_411 ( & V_2 -> V_115 , V_514 ) ;
V_2 -> V_6 = type ;
F_412 ( & V_2 -> V_115 , type ) ;
V_2 -> V_94 = ( T_2 ) - 1 ;
V_2 -> V_3 = V_4 ;
F_21 ( V_33 , V_2 ) ;
F_27 ( V_2 , V_33 -> V_35 , V_515 ,
V_515 + V_54 ) ;
F_19 ( V_33 , V_2 ) ;
V_27 = F_222 ( V_33 -> V_35 , V_2 -> V_6 , V_54 , V_257 ,
& V_2 -> V_100 ) ;
F_22 ( V_27 ) ;
F_11 ( & V_2 -> V_100 -> V_49 ) ;
V_2 -> V_100 -> V_268 += V_2 -> V_44 ;
F_13 ( & V_2 -> V_100 -> V_49 ) ;
F_402 ( V_2 -> V_100 , V_2 ) ;
V_27 = F_10 ( V_33 -> V_35 , V_2 ) ;
F_22 ( V_27 ) ;
V_27 = F_413 ( V_83 , V_60 , & V_2 -> V_20 , & V_2 -> V_115 ,
sizeof( V_2 -> V_115 ) ) ;
F_22 ( V_27 ) ;
F_226 ( V_60 -> V_35 , type ) ;
return 0 ;
}
int F_414 ( struct V_82 * V_83 ,
struct V_32 * V_33 , T_2 V_112 )
{
struct V_61 * V_62 ;
struct V_1 * V_13 ;
struct V_418 * V_213 ;
struct V_32 * V_92 = V_33 -> V_35 -> V_92 ;
struct V_65 V_20 ;
struct V_238 * V_238 ;
int V_27 ;
int V_107 ;
V_33 = V_33 -> V_35 -> V_60 ;
V_13 = F_66 ( V_33 -> V_35 , V_112 ) ;
F_22 ( ! V_13 ) ;
F_22 ( ! V_13 -> V_116 ) ;
F_19 ( V_33 , V_13 ) ;
memcpy ( & V_20 , & V_13 -> V_20 , sizeof( V_20 ) ) ;
if ( V_13 -> V_6 & ( V_258 |
V_259 |
V_260 ) )
V_107 = 2 ;
else
V_107 = 1 ;
V_213 = & V_33 -> V_35 -> V_436 ;
F_11 ( & V_213 -> V_445 ) ;
F_324 ( V_13 , V_213 ) ;
F_13 ( & V_213 -> V_445 ) ;
V_213 = & V_33 -> V_35 -> V_434 ;
F_11 ( & V_213 -> V_445 ) ;
F_324 ( V_13 , V_213 ) ;
F_13 ( & V_213 -> V_445 ) ;
V_62 = F_32 () ;
if ( ! V_62 ) {
V_27 = - V_118 ;
goto V_69;
}
V_238 = F_206 ( V_92 , V_13 , V_62 ) ;
if ( ! F_207 ( V_238 ) ) {
V_27 = F_415 ( V_83 , V_238 ) ;
F_22 ( V_27 ) ;
F_416 ( V_238 ) ;
F_11 ( & V_13 -> V_49 ) ;
if ( V_13 -> V_165 ) {
V_13 -> V_165 = 0 ;
V_13 -> V_238 = NULL ;
F_13 ( & V_13 -> V_49 ) ;
F_218 ( V_238 ) ;
} else {
F_13 ( & V_13 -> V_49 ) ;
}
F_417 ( V_238 ) ;
}
V_20 . V_21 = V_517 ;
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
F_172 ( & V_13 -> V_19 ,
& V_33 -> V_35 -> V_18 ) ;
F_13 ( & V_33 -> V_35 -> V_17 ) ;
F_61 ( & V_13 -> V_100 -> V_265 ) ;
F_171 ( & V_13 -> V_85 ) ;
F_63 ( & V_13 -> V_100 -> V_265 ) ;
if ( V_13 -> V_3 == V_50 )
F_317 ( V_13 ) ;
F_400 ( V_13 ) ;
F_11 ( & V_13 -> V_100 -> V_49 ) ;
V_13 -> V_100 -> V_256 -= V_13 -> V_20 . V_31 ;
V_13 -> V_100 -> V_268 -= V_13 -> V_20 . V_31 ;
V_13 -> V_100 -> V_261 -= V_13 -> V_20 . V_31 * V_107 ;
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
int F_418 ( struct V_11 * V_35 )
{
struct V_97 * V_100 ;
struct V_518 * V_519 ;
T_2 V_520 ;
T_2 V_6 ;
int V_521 = 0 ;
int V_27 ;
V_519 = V_35 -> V_310 ;
if ( ! F_419 ( V_519 ) )
return 1 ;
V_520 = F_420 ( V_519 ) ;
if ( V_520 & V_522 )
V_521 = 1 ;
V_6 = V_103 ;
V_27 = F_222 ( V_35 , V_6 , 0 , 0 , & V_100 ) ;
if ( V_27 )
goto V_69;
if ( V_521 ) {
V_6 = V_104 | V_102 ;
V_27 = F_222 ( V_35 , V_6 , 0 , 0 , & V_100 ) ;
} else {
V_6 = V_104 ;
V_27 = F_222 ( V_35 , V_6 , 0 , 0 , & V_100 ) ;
if ( V_27 )
goto V_69;
V_6 = V_102 ;
V_27 = F_222 ( V_35 , V_6 , 0 , 0 , & V_100 ) ;
}
V_69:
return V_27 ;
}
int F_421 ( struct V_32 * V_33 , T_2 V_30 , T_2 V_29 )
{
return F_300 ( V_33 , V_30 , V_29 ) ;
}
int F_422 ( struct V_32 * V_33 , T_2 V_25 ,
T_2 V_34 , T_2 * V_186 )
{
return F_146 ( V_33 , V_25 , V_34 , V_186 ) ;
}
int F_423 ( struct V_32 * V_33 , struct V_523 * V_524 )
{
struct V_11 * V_35 = V_33 -> V_35 ;
struct V_1 * V_2 = NULL ;
T_2 V_525 ;
T_2 V_30 ;
T_2 V_29 ;
T_2 V_526 = 0 ;
int V_27 = 0 ;
V_2 = F_66 ( V_35 , V_524 -> V_30 ) ;
while ( V_2 ) {
if ( V_2 -> V_20 . V_21 >= ( V_524 -> V_30 + V_524 -> V_117 ) ) {
F_6 ( V_2 ) ;
break;
}
V_30 = F_76 ( V_524 -> V_30 , V_2 -> V_20 . V_21 ) ;
V_29 = F_243 ( V_524 -> V_30 + V_524 -> V_117 ,
V_2 -> V_20 . V_21 + V_2 -> V_20 . V_31 ) ;
if ( V_29 - V_30 >= V_524 -> V_527 ) {
if ( ! F_1 ( V_2 ) ) {
V_27 = F_49 ( V_2 , NULL , V_33 , 0 ) ;
if ( ! V_27 )
F_317 ( V_2 ) ;
}
V_27 = F_424 ( V_2 ,
& V_525 ,
V_30 ,
V_29 ,
V_524 -> V_527 ) ;
V_526 += V_525 ;
if ( V_27 ) {
F_6 ( V_2 ) ;
break;
}
}
V_2 = F_204 ( V_35 -> V_92 , V_2 ) ;
}
V_524 -> V_117 = V_526 ;
return V_27 ;
}
