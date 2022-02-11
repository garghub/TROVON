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
static int F_30 ( void * V_59 )
{
struct V_1 * V_14 = V_59 ;
struct V_12 * V_36 = V_14 -> V_36 ;
struct V_48 * V_52 = V_14 -> V_52 ;
struct V_33 * V_60 = V_36 -> V_60 ;
struct V_61 * V_62 ;
struct V_63 * V_64 ;
struct V_65 V_21 ;
T_2 V_66 = 0 ;
T_2 V_67 = 0 ;
T_3 V_68 ;
int V_28 = 0 ;
V_62 = F_31 () ;
if ( ! V_62 )
return - V_69 ;
V_67 = F_32 ( T_2 , V_14 -> V_21 . V_22 , V_44 ) ;
V_62 -> V_70 = 1 ;
V_62 -> V_71 = 1 ;
V_62 -> V_72 = 1 ;
V_21 . V_22 = V_67 ;
V_21 . V_32 = 0 ;
V_21 . type = V_73 ;
V_74:
F_33 ( & V_52 -> V_75 ) ;
F_34 ( & V_36 -> V_76 ) ;
V_28 = F_35 ( NULL , V_60 , & V_21 , V_62 , 0 , 0 ) ;
if ( V_28 < 0 )
goto V_77;
V_64 = V_62 -> V_78 [ 0 ] ;
V_68 = F_36 ( V_64 ) ;
while ( 1 ) {
if ( F_37 ( V_36 ) > 1 ) {
V_67 = ( T_2 ) - 1 ;
break;
}
if ( V_62 -> V_79 [ 0 ] < V_68 ) {
F_38 ( V_64 , & V_21 , V_62 -> V_79 [ 0 ] ) ;
} else {
V_28 = F_39 ( V_62 , 0 , & V_21 ) ;
if ( V_28 )
break;
if ( F_40 () ||
F_41 ( V_60 , V_62 ) ) {
V_52 -> V_80 = V_67 ;
F_42 ( V_62 ) ;
F_43 ( & V_36 -> V_76 ) ;
F_44 ( & V_52 -> V_75 ) ;
F_45 () ;
goto V_74;
}
V_64 = V_62 -> V_78 [ 0 ] ;
V_68 = F_36 ( V_64 ) ;
continue;
}
if ( V_21 . V_22 < V_14 -> V_21 . V_22 ) {
V_62 -> V_79 [ 0 ] ++ ;
continue;
}
if ( V_21 . V_22 >= V_14 -> V_21 . V_22 +
V_14 -> V_21 . V_32 )
break;
if ( V_21 . type == V_73 ) {
V_66 += F_27 ( V_14 ,
V_36 , V_67 ,
V_21 . V_22 ) ;
V_67 = V_21 . V_22 + V_21 . V_32 ;
if ( V_66 > ( 1024 * 1024 * 2 ) ) {
V_66 = 0 ;
F_46 ( & V_52 -> V_81 ) ;
}
}
V_62 -> V_79 [ 0 ] ++ ;
}
V_28 = 0 ;
V_66 += F_27 ( V_14 , V_36 , V_67 ,
V_14 -> V_21 . V_22 +
V_14 -> V_21 . V_32 ) ;
V_52 -> V_80 = ( T_2 ) - 1 ;
F_11 ( & V_14 -> V_50 ) ;
V_14 -> V_52 = NULL ;
V_14 -> V_3 = V_4 ;
F_13 ( & V_14 -> V_50 ) ;
V_77:
F_47 ( V_62 ) ;
F_43 ( & V_36 -> V_76 ) ;
F_19 ( V_60 , V_14 ) ;
F_44 ( & V_52 -> V_75 ) ;
F_46 ( & V_52 -> V_81 ) ;
F_26 ( V_52 ) ;
F_48 ( & V_14 -> V_82 -> V_83 ) ;
F_6 ( V_14 ) ;
return 0 ;
}
static int F_49 ( struct V_1 * V_2 ,
struct V_84 * V_85 ,
struct V_33 * V_34 ,
int V_86 )
{
struct V_12 * V_36 = V_2 -> V_36 ;
struct V_48 * V_52 ;
struct V_87 * V_88 ;
int V_28 = 0 ;
F_2 () ;
if ( V_2 -> V_3 != V_89 )
return 0 ;
if ( V_85 && ( ! V_85 -> V_90 -> V_91 ) &&
( V_34 && V_34 != V_34 -> V_36 -> V_92 ) ) {
F_11 ( & V_2 -> V_50 ) ;
if ( V_2 -> V_3 != V_89 ) {
F_13 ( & V_2 -> V_50 ) ;
return 0 ;
}
V_2 -> V_3 = V_51 ;
F_13 ( & V_2 -> V_50 ) ;
V_28 = F_50 ( V_36 , V_2 ) ;
F_11 ( & V_2 -> V_50 ) ;
if ( V_28 == 1 ) {
V_2 -> V_3 = V_4 ;
V_2 -> V_93 = ( T_2 ) - 1 ;
} else {
V_2 -> V_3 = V_89 ;
}
F_13 ( & V_2 -> V_50 ) ;
if ( V_28 == 1 ) {
F_19 ( V_36 -> V_60 , V_2 ) ;
return 0 ;
}
}
if ( V_86 )
return 0 ;
V_52 = F_51 ( sizeof( * V_52 ) , V_39 ) ;
F_22 ( ! V_52 ) ;
F_52 ( & V_52 -> V_94 ) ;
F_53 ( & V_52 -> V_75 ) ;
F_54 ( & V_52 -> V_81 ) ;
V_52 -> V_14 = V_2 ;
V_52 -> V_80 = V_2 -> V_21 . V_22 ;
F_55 ( & V_52 -> V_7 , 2 ) ;
F_11 ( & V_2 -> V_50 ) ;
if ( V_2 -> V_3 != V_89 ) {
F_13 ( & V_2 -> V_50 ) ;
F_9 ( V_52 ) ;
return 0 ;
}
V_2 -> V_52 = V_52 ;
V_2 -> V_3 = V_51 ;
F_13 ( & V_2 -> V_50 ) ;
F_56 ( & V_36 -> V_76 ) ;
F_57 ( & V_52 -> V_94 , & V_36 -> V_95 ) ;
F_58 ( & V_36 -> V_76 ) ;
F_5 ( & V_2 -> V_82 -> V_83 ) ;
F_4 ( V_2 ) ;
V_88 = F_59 ( F_30 , V_2 , L_1 ,
V_2 -> V_21 . V_22 ) ;
if ( F_60 ( V_88 ) ) {
V_28 = F_61 ( V_88 ) ;
F_62 ( V_96 L_2 , V_28 ) ;
F_63 () ;
}
return V_28 ;
}
static struct V_1 *
F_64 ( struct V_12 * V_13 , T_2 V_26 )
{
struct V_1 * V_2 ;
V_2 = F_16 ( V_13 , V_26 , 0 ) ;
return V_2 ;
}
struct V_1 * F_65 (
struct V_12 * V_13 ,
T_2 V_26 )
{
struct V_1 * V_2 ;
V_2 = F_16 ( V_13 , V_26 , 1 ) ;
return V_2 ;
}
static struct V_97 * F_66 ( struct V_12 * V_13 ,
T_2 V_6 )
{
struct V_98 * V_99 = & V_13 -> V_82 ;
struct V_97 * V_100 ;
V_6 &= V_101 | V_102 |
V_103 ;
F_67 () ;
F_68 (found, head, list) {
if ( V_100 -> V_6 & V_6 ) {
F_69 () ;
return V_100 ;
}
}
F_69 () ;
return NULL ;
}
void F_70 ( struct V_12 * V_13 )
{
struct V_98 * V_99 = & V_13 -> V_82 ;
struct V_97 * V_100 ;
F_67 () ;
F_68 (found, head, list)
V_100 -> V_104 = 0 ;
F_69 () ;
}
static T_2 F_71 ( T_2 V_105 , int V_106 )
{
if ( V_106 == 10 )
return V_105 ;
V_105 *= V_106 ;
F_72 ( V_105 , 10 ) ;
return V_105 ;
}
static T_2 F_73 ( T_2 V_105 , int V_106 )
{
if ( V_106 == 100 )
return V_105 ;
V_105 *= V_106 ;
F_72 ( V_105 , 100 ) ;
return V_105 ;
}
T_2 F_74 ( struct V_33 * V_34 ,
T_2 V_107 , T_2 V_108 , int V_109 )
{
struct V_1 * V_2 ;
T_2 V_110 ;
T_2 V_67 = F_75 ( V_108 , V_107 ) ;
T_2 V_111 = 0 ;
int V_112 = 0 ;
int V_106 = 9 ;
int V_113 = 0 ;
V_74:
while ( 1 ) {
V_2 = F_64 ( V_34 -> V_36 , V_67 ) ;
if ( ! V_2 )
break;
F_11 ( & V_2 -> V_50 ) ;
V_67 = V_2 -> V_21 . V_22 + V_2 -> V_21 . V_32 ;
V_110 = F_76 ( & V_2 -> V_114 ) ;
if ( ( V_112 || ! V_2 -> V_115 ) &&
F_3 ( V_2 , V_103 ) ) {
if ( V_110 + V_2 -> V_8 + V_2 -> V_9 <
F_71 ( V_2 -> V_21 . V_32 , V_106 ) ) {
V_111 = V_2 -> V_21 . V_22 ;
F_13 ( & V_2 -> V_50 ) ;
F_6 ( V_2 ) ;
goto V_100;
}
}
F_13 ( & V_2 -> V_50 ) ;
F_6 ( V_2 ) ;
F_45 () ;
}
if ( ! V_113 ) {
V_67 = V_107 ;
V_113 = 1 ;
goto V_74;
}
if ( ! V_112 && V_106 < 10 ) {
V_67 = V_107 ;
V_112 = 1 ;
V_106 = 10 ;
goto V_74;
}
V_100:
return V_111 ;
}
int F_77 ( struct V_33 * V_34 , T_2 V_31 , T_2 V_116 )
{
int V_28 ;
struct V_65 V_21 ;
struct V_61 * V_62 ;
V_62 = F_31 () ;
F_22 ( ! V_62 ) ;
V_21 . V_22 = V_31 ;
V_21 . V_32 = V_116 ;
F_78 ( & V_21 , V_73 ) ;
V_28 = F_35 ( NULL , V_34 -> V_36 -> V_60 , & V_21 , V_62 ,
0 , 0 ) ;
F_47 ( V_62 ) ;
return V_28 ;
}
int F_79 ( struct V_84 * V_85 ,
struct V_33 * V_34 , T_2 V_26 ,
T_2 V_35 , T_2 * V_117 , T_2 * V_6 )
{
struct V_118 * V_99 ;
struct V_119 * V_120 ;
struct V_61 * V_62 ;
struct V_121 * V_122 ;
struct V_63 * V_64 ;
struct V_65 V_21 ;
T_3 V_123 ;
T_2 V_124 ;
T_2 V_125 ;
int V_28 ;
V_62 = F_31 () ;
if ( ! V_62 )
return - V_69 ;
V_21 . V_22 = V_26 ;
V_21 . type = V_73 ;
V_21 . V_32 = V_35 ;
if ( ! V_85 ) {
V_62 -> V_70 = 1 ;
V_62 -> V_71 = 1 ;
}
V_74:
V_28 = F_35 ( V_85 , V_34 -> V_36 -> V_60 ,
& V_21 , V_62 , 0 , 0 ) ;
if ( V_28 < 0 )
goto V_126;
if ( V_28 == 0 ) {
V_64 = V_62 -> V_78 [ 0 ] ;
V_123 = F_80 ( V_64 , V_62 -> V_79 [ 0 ] ) ;
if ( V_123 >= sizeof( * V_122 ) ) {
V_122 = F_81 ( V_64 , V_62 -> V_79 [ 0 ] ,
struct V_121 ) ;
V_124 = F_82 ( V_64 , V_122 ) ;
V_125 = F_83 ( V_64 , V_122 ) ;
} else {
#ifdef F_84
struct V_127 * V_128 ;
F_22 ( V_123 != sizeof( * V_128 ) ) ;
V_128 = F_81 ( V_64 , V_62 -> V_79 [ 0 ] ,
struct V_127 ) ;
V_124 = F_85 ( V_64 , V_128 ) ;
V_125 = V_129 ;
#else
F_63 () ;
#endif
}
F_22 ( V_124 == 0 ) ;
} else {
V_124 = 0 ;
V_125 = 0 ;
V_28 = 0 ;
}
if ( ! V_85 )
goto V_130;
V_120 = & V_85 -> V_90 -> V_120 ;
F_11 ( & V_120 -> V_50 ) ;
V_99 = F_86 ( V_85 , V_26 ) ;
if ( V_99 ) {
if ( ! F_87 ( & V_99 -> V_75 ) ) {
F_5 ( & V_99 -> V_131 . V_117 ) ;
F_13 ( & V_120 -> V_50 ) ;
F_42 ( V_62 ) ;
F_33 ( & V_99 -> V_75 ) ;
F_44 ( & V_99 -> V_75 ) ;
F_88 ( & V_99 -> V_131 ) ;
goto V_74;
}
if ( V_99 -> V_132 && V_99 -> V_132 -> V_133 )
V_125 |= V_99 -> V_132 -> V_134 ;
else
F_22 ( V_124 == 0 ) ;
V_124 += V_99 -> V_131 . V_135 ;
F_44 ( & V_99 -> V_75 ) ;
}
F_13 ( & V_120 -> V_50 ) ;
V_130:
F_8 ( V_124 == 0 ) ;
if ( V_117 )
* V_117 = V_124 ;
if ( V_6 )
* V_6 = V_125 ;
V_126:
F_47 ( V_62 ) ;
return V_28 ;
}
static int F_89 ( struct V_84 * V_85 ,
struct V_33 * V_34 ,
struct V_61 * V_62 ,
T_2 V_109 , T_3 V_136 )
{
struct V_121 * V_114 ;
struct V_127 * V_128 ;
struct V_137 * V_138 ;
struct V_139 * V_140 ;
struct V_63 * V_64 ;
struct V_65 V_21 ;
struct V_65 V_141 ;
T_3 V_142 = sizeof( * V_114 ) ;
T_2 V_117 ;
int V_28 ;
V_64 = V_62 -> V_78 [ 0 ] ;
F_22 ( F_80 ( V_64 , V_62 -> V_79 [ 0 ] ) != sizeof( * V_128 ) ) ;
F_38 ( V_64 , & V_21 , V_62 -> V_79 [ 0 ] ) ;
V_128 = F_81 ( V_64 , V_62 -> V_79 [ 0 ] ,
struct V_127 ) ;
V_117 = F_85 ( V_64 , V_128 ) ;
if ( V_109 == ( T_2 ) - 1 ) {
while ( 1 ) {
if ( V_62 -> V_79 [ 0 ] >= F_36 ( V_64 ) ) {
V_28 = F_41 ( V_34 , V_62 ) ;
if ( V_28 < 0 )
return V_28 ;
F_22 ( V_28 > 0 ) ;
V_64 = V_62 -> V_78 [ 0 ] ;
}
F_38 ( V_64 , & V_141 ,
V_62 -> V_79 [ 0 ] ) ;
F_22 ( V_21 . V_22 != V_141 . V_22 ) ;
if ( V_141 . type != V_143 ) {
V_62 -> V_79 [ 0 ] ++ ;
continue;
}
V_138 = F_81 ( V_64 , V_62 -> V_79 [ 0 ] ,
struct V_137 ) ;
V_109 = F_90 ( V_64 , V_138 ) ;
break;
}
}
F_42 ( V_62 ) ;
if ( V_109 < V_144 )
V_142 += sizeof( * V_140 ) ;
V_142 -= sizeof( * V_128 ) ;
V_28 = F_35 ( V_85 , V_34 , & V_21 , V_62 ,
V_142 + V_136 , 1 ) ;
if ( V_28 < 0 )
return V_28 ;
F_22 ( V_28 ) ;
V_28 = F_91 ( V_85 , V_34 , V_62 , V_142 ) ;
V_64 = V_62 -> V_78 [ 0 ] ;
V_114 = F_81 ( V_64 , V_62 -> V_79 [ 0 ] , struct V_121 ) ;
F_92 ( V_64 , V_114 , V_117 ) ;
F_93 ( V_64 , V_114 , 0 ) ;
if ( V_109 < V_144 ) {
F_94 ( V_64 , V_114 ,
V_145 |
V_129 ) ;
V_140 = (struct V_139 * ) ( V_114 + 1 ) ;
F_95 ( V_64 , 0 , ( unsigned long ) V_140 , sizeof( * V_140 ) ) ;
F_96 ( V_64 , V_140 , ( int ) V_109 ) ;
} else {
F_94 ( V_64 , V_114 , V_146 ) ;
}
F_97 ( V_64 ) ;
return 0 ;
}
static T_2 F_98 ( T_2 V_147 , T_2 V_109 , T_2 V_32 )
{
T_3 V_148 = ~ ( T_3 ) 0 ;
T_3 V_149 = ~ ( T_3 ) 0 ;
T_4 V_150 ;
V_150 = F_99 ( V_147 ) ;
V_148 = F_100 ( V_148 , & V_150 , sizeof( V_150 ) ) ;
V_150 = F_99 ( V_109 ) ;
V_149 = F_100 ( V_149 , & V_150 , sizeof( V_150 ) ) ;
V_150 = F_99 ( V_32 ) ;
V_149 = F_100 ( V_149 , & V_150 , sizeof( V_150 ) ) ;
return ( ( T_2 ) V_148 << 31 ) ^ ( T_2 ) V_149 ;
}
static T_2 F_101 ( struct V_63 * V_64 ,
struct V_151 * V_152 )
{
return F_98 ( F_102 ( V_64 , V_152 ) ,
F_103 ( V_64 , V_152 ) ,
F_104 ( V_64 , V_152 ) ) ;
}
static int F_105 ( struct V_63 * V_64 ,
struct V_151 * V_152 ,
T_2 V_147 , T_2 V_109 , T_2 V_32 )
{
if ( F_102 ( V_64 , V_152 ) != V_147 ||
F_103 ( V_64 , V_152 ) != V_109 ||
F_104 ( V_64 , V_152 ) != V_32 )
return 0 ;
return 1 ;
}
static T_1 int F_106 ( struct V_84 * V_85 ,
struct V_33 * V_34 ,
struct V_61 * V_62 ,
T_2 V_26 , T_2 V_17 ,
T_2 V_147 ,
T_2 V_109 , T_2 V_32 )
{
struct V_65 V_21 ;
struct V_151 * V_152 ;
struct V_63 * V_64 ;
T_3 V_68 ;
int V_28 ;
int V_153 ;
int V_77 = - V_154 ;
V_21 . V_22 = V_26 ;
if ( V_17 ) {
V_21 . type = V_155 ;
V_21 . V_32 = V_17 ;
} else {
V_21 . type = V_156 ;
V_21 . V_32 = F_98 ( V_147 ,
V_109 , V_32 ) ;
}
V_74:
V_153 = 0 ;
V_28 = F_35 ( V_85 , V_34 , & V_21 , V_62 , - 1 , 1 ) ;
if ( V_28 < 0 ) {
V_77 = V_28 ;
goto V_157;
}
if ( V_17 ) {
if ( ! V_28 )
return 0 ;
#ifdef F_84
V_21 . type = V_143 ;
F_42 ( V_62 ) ;
V_28 = F_35 ( V_85 , V_34 , & V_21 , V_62 , - 1 , 1 ) ;
if ( V_28 < 0 ) {
V_77 = V_28 ;
goto V_157;
}
if ( ! V_28 )
return 0 ;
#endif
goto V_157;
}
V_64 = V_62 -> V_78 [ 0 ] ;
V_68 = F_36 ( V_64 ) ;
while ( 1 ) {
if ( V_62 -> V_79 [ 0 ] >= V_68 ) {
V_28 = F_41 ( V_34 , V_62 ) ;
if ( V_28 < 0 )
V_77 = V_28 ;
if ( V_28 )
goto V_157;
V_64 = V_62 -> V_78 [ 0 ] ;
V_68 = F_36 ( V_64 ) ;
V_153 = 1 ;
}
F_38 ( V_64 , & V_21 , V_62 -> V_79 [ 0 ] ) ;
if ( V_21 . V_22 != V_26 ||
V_21 . type != V_156 )
goto V_157;
V_152 = F_81 ( V_64 , V_62 -> V_79 [ 0 ] ,
struct V_151 ) ;
if ( F_105 ( V_64 , V_152 , V_147 ,
V_109 , V_32 ) ) {
if ( V_153 ) {
F_42 ( V_62 ) ;
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
static T_1 int F_107 ( struct V_84 * V_85 ,
struct V_33 * V_34 ,
struct V_61 * V_62 ,
T_2 V_26 , T_2 V_17 ,
T_2 V_147 , T_2 V_109 ,
T_2 V_32 , int V_158 )
{
struct V_65 V_21 ;
struct V_63 * V_64 ;
T_3 V_55 ;
T_3 V_124 ;
int V_28 ;
V_21 . V_22 = V_26 ;
if ( V_17 ) {
V_21 . type = V_155 ;
V_21 . V_32 = V_17 ;
V_55 = sizeof( struct V_159 ) ;
} else {
V_21 . type = V_156 ;
V_21 . V_32 = F_98 ( V_147 ,
V_109 , V_32 ) ;
V_55 = sizeof( struct V_151 ) ;
}
V_28 = F_108 ( V_85 , V_34 , V_62 , & V_21 , V_55 ) ;
if ( V_28 && V_28 != - V_25 )
goto V_157;
V_64 = V_62 -> V_78 [ 0 ] ;
if ( V_17 ) {
struct V_159 * V_152 ;
V_152 = F_81 ( V_64 , V_62 -> V_79 [ 0 ] ,
struct V_159 ) ;
if ( V_28 == 0 ) {
F_109 ( V_64 , V_152 , V_158 ) ;
} else {
V_124 = F_110 ( V_64 , V_152 ) ;
V_124 += V_158 ;
F_109 ( V_64 , V_152 , V_124 ) ;
}
} else {
struct V_151 * V_152 ;
while ( V_28 == - V_25 ) {
V_152 = F_81 ( V_64 , V_62 -> V_79 [ 0 ] ,
struct V_151 ) ;
if ( F_105 ( V_64 , V_152 , V_147 ,
V_109 , V_32 ) )
break;
F_42 ( V_62 ) ;
V_21 . V_32 ++ ;
V_28 = F_108 ( V_85 , V_34 , V_62 , & V_21 ,
V_55 ) ;
if ( V_28 && V_28 != - V_25 )
goto V_157;
V_64 = V_62 -> V_78 [ 0 ] ;
}
V_152 = F_81 ( V_64 , V_62 -> V_79 [ 0 ] ,
struct V_151 ) ;
if ( V_28 == 0 ) {
F_111 ( V_64 , V_152 ,
V_147 ) ;
F_112 ( V_64 , V_152 , V_109 ) ;
F_113 ( V_64 , V_152 , V_32 ) ;
F_114 ( V_64 , V_152 , V_158 ) ;
} else {
V_124 = F_115 ( V_64 , V_152 ) ;
V_124 += V_158 ;
F_114 ( V_64 , V_152 , V_124 ) ;
}
}
F_97 ( V_64 ) ;
V_28 = 0 ;
V_157:
F_42 ( V_62 ) ;
return V_28 ;
}
static T_1 int F_116 ( struct V_84 * V_85 ,
struct V_33 * V_34 ,
struct V_61 * V_62 ,
int V_160 )
{
struct V_65 V_21 ;
struct V_151 * V_161 = NULL ;
struct V_159 * V_162 = NULL ;
struct V_63 * V_64 ;
T_3 V_124 = 0 ;
int V_28 = 0 ;
V_64 = V_62 -> V_78 [ 0 ] ;
F_38 ( V_64 , & V_21 , V_62 -> V_79 [ 0 ] ) ;
if ( V_21 . type == V_156 ) {
V_161 = F_81 ( V_64 , V_62 -> V_79 [ 0 ] ,
struct V_151 ) ;
V_124 = F_115 ( V_64 , V_161 ) ;
} else if ( V_21 . type == V_155 ) {
V_162 = F_81 ( V_64 , V_62 -> V_79 [ 0 ] ,
struct V_159 ) ;
V_124 = F_110 ( V_64 , V_162 ) ;
#ifdef F_84
} else if ( V_21 . type == V_143 ) {
struct V_137 * V_138 ;
V_138 = F_81 ( V_64 , V_62 -> V_79 [ 0 ] ,
struct V_137 ) ;
V_124 = F_117 ( V_64 , V_138 ) ;
#endif
} else {
F_63 () ;
}
F_22 ( V_124 < V_160 ) ;
V_124 -= V_160 ;
if ( V_124 == 0 ) {
V_28 = F_118 ( V_85 , V_34 , V_62 ) ;
} else {
if ( V_21 . type == V_156 )
F_114 ( V_64 , V_161 , V_124 ) ;
else if ( V_21 . type == V_155 )
F_109 ( V_64 , V_162 , V_124 ) ;
#ifdef F_84
else {
struct V_137 * V_138 ;
V_138 = F_81 ( V_64 , V_62 -> V_79 [ 0 ] ,
struct V_137 ) ;
F_119 ( V_64 , V_138 , V_124 ) ;
}
#endif
F_97 ( V_64 ) ;
}
return V_28 ;
}
static T_1 T_3 F_120 ( struct V_33 * V_34 ,
struct V_61 * V_62 ,
struct V_163 * V_164 )
{
struct V_65 V_21 ;
struct V_63 * V_64 ;
struct V_151 * V_161 ;
struct V_159 * V_162 ;
T_3 V_124 = 0 ;
V_64 = V_62 -> V_78 [ 0 ] ;
F_38 ( V_64 , & V_21 , V_62 -> V_79 [ 0 ] ) ;
if ( V_164 ) {
if ( F_121 ( V_64 , V_164 ) ==
V_156 ) {
V_161 = (struct V_151 * ) ( & V_164 -> V_32 ) ;
V_124 = F_115 ( V_64 , V_161 ) ;
} else {
V_162 = (struct V_159 * ) ( V_164 + 1 ) ;
V_124 = F_110 ( V_64 , V_162 ) ;
}
} else if ( V_21 . type == V_156 ) {
V_161 = F_81 ( V_64 , V_62 -> V_79 [ 0 ] ,
struct V_151 ) ;
V_124 = F_115 ( V_64 , V_161 ) ;
} else if ( V_21 . type == V_155 ) {
V_162 = F_81 ( V_64 , V_62 -> V_79 [ 0 ] ,
struct V_159 ) ;
V_124 = F_110 ( V_64 , V_162 ) ;
#ifdef F_84
} else if ( V_21 . type == V_143 ) {
struct V_137 * V_138 ;
V_138 = F_81 ( V_64 , V_62 -> V_79 [ 0 ] ,
struct V_137 ) ;
V_124 = F_117 ( V_64 , V_138 ) ;
#endif
} else {
F_8 ( 1 ) ;
}
return V_124 ;
}
static T_1 int F_122 ( struct V_84 * V_85 ,
struct V_33 * V_34 ,
struct V_61 * V_62 ,
T_2 V_26 , T_2 V_17 ,
T_2 V_147 )
{
struct V_65 V_21 ;
int V_28 ;
V_21 . V_22 = V_26 ;
if ( V_17 ) {
V_21 . type = V_165 ;
V_21 . V_32 = V_17 ;
} else {
V_21 . type = V_166 ;
V_21 . V_32 = V_147 ;
}
V_28 = F_35 ( V_85 , V_34 , & V_21 , V_62 , - 1 , 1 ) ;
if ( V_28 > 0 )
V_28 = - V_154 ;
#ifdef F_84
if ( V_28 == - V_154 && V_17 ) {
F_42 ( V_62 ) ;
V_21 . type = V_143 ;
V_28 = F_35 ( V_85 , V_34 , & V_21 , V_62 , - 1 , 1 ) ;
if ( V_28 > 0 )
V_28 = - V_154 ;
}
#endif
return V_28 ;
}
static T_1 int F_123 ( struct V_84 * V_85 ,
struct V_33 * V_34 ,
struct V_61 * V_62 ,
T_2 V_26 , T_2 V_17 ,
T_2 V_147 )
{
struct V_65 V_21 ;
int V_28 ;
V_21 . V_22 = V_26 ;
if ( V_17 ) {
V_21 . type = V_165 ;
V_21 . V_32 = V_17 ;
} else {
V_21 . type = V_166 ;
V_21 . V_32 = V_147 ;
}
V_28 = F_108 ( V_85 , V_34 , V_62 , & V_21 , 0 ) ;
F_42 ( V_62 ) ;
return V_28 ;
}
static inline int F_124 ( T_2 V_17 , T_2 V_109 )
{
int type ;
if ( V_109 < V_144 ) {
if ( V_17 > 0 )
type = V_165 ;
else
type = V_166 ;
} else {
if ( V_17 > 0 )
type = V_155 ;
else
type = V_156 ;
}
return type ;
}
static int F_39 ( struct V_61 * V_62 , int V_167 ,
struct V_65 * V_21 )
{
for (; V_167 < V_168 ; V_167 ++ ) {
if ( ! V_62 -> V_78 [ V_167 ] )
break;
if ( V_62 -> V_79 [ V_167 ] + 1 >=
F_36 ( V_62 -> V_78 [ V_167 ] ) )
continue;
if ( V_167 == 0 )
F_38 ( V_62 -> V_78 [ V_167 ] , V_21 ,
V_62 -> V_79 [ V_167 ] + 1 ) ;
else
F_125 ( V_62 -> V_78 [ V_167 ] , V_21 ,
V_62 -> V_79 [ V_167 ] + 1 ) ;
return 0 ;
}
return 1 ;
}
static T_5
int F_126 ( struct V_84 * V_85 ,
struct V_33 * V_34 ,
struct V_61 * V_62 ,
struct V_163 * * V_169 ,
T_2 V_26 , T_2 V_35 ,
T_2 V_17 , T_2 V_147 ,
T_2 V_109 , T_2 V_32 , int V_170 )
{
struct V_65 V_21 ;
struct V_63 * V_64 ;
struct V_121 * V_122 ;
struct V_163 * V_164 ;
T_2 V_6 ;
T_2 V_123 ;
unsigned long V_171 ;
unsigned long V_30 ;
int V_136 ;
int type ;
int V_172 ;
int V_28 ;
int V_77 = 0 ;
V_21 . V_22 = V_26 ;
V_21 . type = V_73 ;
V_21 . V_32 = V_35 ;
V_172 = F_124 ( V_17 , V_109 ) ;
if ( V_170 ) {
V_136 = F_127 ( V_172 ) ;
V_62 -> V_173 = 1 ;
} else
V_136 = - 1 ;
V_28 = F_35 ( V_85 , V_34 , & V_21 , V_62 , V_136 , 1 ) ;
if ( V_28 < 0 ) {
V_77 = V_28 ;
goto V_130;
}
F_22 ( V_28 ) ;
V_64 = V_62 -> V_78 [ 0 ] ;
V_123 = F_80 ( V_64 , V_62 -> V_79 [ 0 ] ) ;
#ifdef F_84
if ( V_123 < sizeof( * V_122 ) ) {
if ( ! V_170 ) {
V_77 = - V_154 ;
goto V_130;
}
V_28 = F_89 ( V_85 , V_34 , V_62 , V_109 ,
V_136 ) ;
if ( V_28 < 0 ) {
V_77 = V_28 ;
goto V_130;
}
V_64 = V_62 -> V_78 [ 0 ] ;
V_123 = F_80 ( V_64 , V_62 -> V_79 [ 0 ] ) ;
}
#endif
F_22 ( V_123 < sizeof( * V_122 ) ) ;
V_122 = F_81 ( V_64 , V_62 -> V_79 [ 0 ] , struct V_121 ) ;
V_6 = F_83 ( V_64 , V_122 ) ;
V_171 = ( unsigned long ) ( V_122 + 1 ) ;
V_30 = ( unsigned long ) V_122 + V_123 ;
if ( V_6 & V_145 ) {
V_171 += sizeof( struct V_139 ) ;
F_22 ( V_171 > V_30 ) ;
} else {
F_22 ( ! ( V_6 & V_146 ) ) ;
}
V_77 = - V_154 ;
while ( 1 ) {
if ( V_171 >= V_30 ) {
F_8 ( V_171 > V_30 ) ;
break;
}
V_164 = (struct V_163 * ) V_171 ;
type = F_121 ( V_64 , V_164 ) ;
if ( V_172 < type )
break;
if ( V_172 > type ) {
V_171 += F_127 ( type ) ;
continue;
}
if ( type == V_156 ) {
struct V_151 * V_174 ;
V_174 = (struct V_151 * ) ( & V_164 -> V_32 ) ;
if ( F_105 ( V_64 , V_174 , V_147 ,
V_109 , V_32 ) ) {
V_77 = 0 ;
break;
}
if ( F_101 ( V_64 , V_174 ) <
F_98 ( V_147 , V_109 , V_32 ) )
break;
} else {
T_2 V_175 ;
V_175 = F_128 ( V_64 , V_164 ) ;
if ( V_17 > 0 ) {
if ( V_17 == V_175 ) {
V_77 = 0 ;
break;
}
if ( V_175 < V_17 )
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
V_171 += F_127 ( type ) ;
}
if ( V_77 == - V_154 && V_170 ) {
if ( V_123 + V_136 >=
F_129 ( V_34 ) ) {
V_77 = - V_176 ;
goto V_130;
}
if ( F_39 ( V_62 , 0 , & V_21 ) == 0 &&
V_21 . V_22 == V_26 &&
V_21 . type < V_177 ) {
V_77 = - V_176 ;
goto V_130;
}
}
* V_169 = (struct V_163 * ) V_171 ;
V_130:
if ( V_170 ) {
V_62 -> V_173 = 0 ;
F_130 ( V_62 , 1 ) ;
}
return V_77 ;
}
static T_5
int F_131 ( struct V_84 * V_85 ,
struct V_33 * V_34 ,
struct V_61 * V_62 ,
struct V_163 * V_164 ,
T_2 V_17 , T_2 V_147 ,
T_2 V_109 , T_2 V_32 , int V_158 ,
struct V_178 * V_132 )
{
struct V_63 * V_64 ;
struct V_121 * V_122 ;
unsigned long V_171 ;
unsigned long V_30 ;
unsigned long V_179 ;
T_2 V_117 ;
int V_55 ;
int type ;
int V_28 ;
V_64 = V_62 -> V_78 [ 0 ] ;
V_122 = F_81 ( V_64 , V_62 -> V_79 [ 0 ] , struct V_121 ) ;
V_179 = ( unsigned long ) V_164 - ( unsigned long ) V_122 ;
type = F_124 ( V_17 , V_109 ) ;
V_55 = F_127 ( type ) ;
V_28 = F_91 ( V_85 , V_34 , V_62 , V_55 ) ;
V_122 = F_81 ( V_64 , V_62 -> V_79 [ 0 ] , struct V_121 ) ;
V_117 = F_82 ( V_64 , V_122 ) ;
V_117 += V_158 ;
F_92 ( V_64 , V_122 , V_117 ) ;
if ( V_132 )
F_132 ( V_132 , V_64 , V_122 ) ;
V_171 = ( unsigned long ) V_122 + V_179 ;
V_30 = ( unsigned long ) V_122 + F_80 ( V_64 , V_62 -> V_79 [ 0 ] ) ;
if ( V_171 < V_30 - V_55 )
F_133 ( V_64 , V_171 + V_55 , V_171 ,
V_30 - V_55 - V_171 ) ;
V_164 = (struct V_163 * ) V_171 ;
F_134 ( V_64 , V_164 , type ) ;
if ( type == V_156 ) {
struct V_151 * V_174 ;
V_174 = (struct V_151 * ) ( & V_164 -> V_32 ) ;
F_111 ( V_64 , V_174 , V_147 ) ;
F_112 ( V_64 , V_174 , V_109 ) ;
F_113 ( V_64 , V_174 , V_32 ) ;
F_114 ( V_64 , V_174 , V_158 ) ;
} else if ( type == V_155 ) {
struct V_159 * V_180 ;
V_180 = (struct V_159 * ) ( V_164 + 1 ) ;
F_109 ( V_64 , V_180 , V_158 ) ;
F_135 ( V_64 , V_164 , V_17 ) ;
} else if ( type == V_165 ) {
F_135 ( V_64 , V_164 , V_17 ) ;
} else {
F_135 ( V_64 , V_164 , V_147 ) ;
}
F_97 ( V_64 ) ;
return 0 ;
}
static int F_136 ( struct V_84 * V_85 ,
struct V_33 * V_34 ,
struct V_61 * V_62 ,
struct V_163 * * V_169 ,
T_2 V_26 , T_2 V_35 , T_2 V_17 ,
T_2 V_147 , T_2 V_109 , T_2 V_32 )
{
int V_28 ;
V_28 = F_126 ( V_85 , V_34 , V_62 , V_169 ,
V_26 , V_35 , V_17 ,
V_147 , V_109 , V_32 , 0 ) ;
if ( V_28 != - V_154 )
return V_28 ;
F_42 ( V_62 ) ;
* V_169 = NULL ;
if ( V_109 < V_144 ) {
V_28 = F_122 ( V_85 , V_34 , V_62 , V_26 , V_17 ,
V_147 ) ;
} else {
V_28 = F_106 ( V_85 , V_34 , V_62 , V_26 , V_17 ,
V_147 , V_109 , V_32 ) ;
}
return V_28 ;
}
static T_5
int F_137 ( struct V_84 * V_85 ,
struct V_33 * V_34 ,
struct V_61 * V_62 ,
struct V_163 * V_164 ,
int V_181 ,
struct V_178 * V_132 )
{
struct V_63 * V_64 ;
struct V_121 * V_122 ;
struct V_151 * V_174 = NULL ;
struct V_159 * V_180 = NULL ;
unsigned long V_171 ;
unsigned long V_30 ;
T_3 V_123 ;
int V_55 ;
int type ;
int V_28 ;
T_2 V_117 ;
V_64 = V_62 -> V_78 [ 0 ] ;
V_122 = F_81 ( V_64 , V_62 -> V_79 [ 0 ] , struct V_121 ) ;
V_117 = F_82 ( V_64 , V_122 ) ;
F_8 ( V_181 < 0 && V_117 + V_181 <= 0 ) ;
V_117 += V_181 ;
F_92 ( V_64 , V_122 , V_117 ) ;
if ( V_132 )
F_132 ( V_132 , V_64 , V_122 ) ;
type = F_121 ( V_64 , V_164 ) ;
if ( type == V_156 ) {
V_174 = (struct V_151 * ) ( & V_164 -> V_32 ) ;
V_117 = F_115 ( V_64 , V_174 ) ;
} else if ( type == V_155 ) {
V_180 = (struct V_159 * ) ( V_164 + 1 ) ;
V_117 = F_110 ( V_64 , V_180 ) ;
} else {
V_117 = 1 ;
F_22 ( V_181 != - 1 ) ;
}
F_22 ( V_181 < 0 && V_117 < - V_181 ) ;
V_117 += V_181 ;
if ( V_117 > 0 ) {
if ( type == V_156 )
F_114 ( V_64 , V_174 , V_117 ) ;
else
F_109 ( V_64 , V_180 , V_117 ) ;
} else {
V_55 = F_127 ( type ) ;
V_123 = F_80 ( V_64 , V_62 -> V_79 [ 0 ] ) ;
V_171 = ( unsigned long ) V_164 ;
V_30 = ( unsigned long ) V_122 + V_123 ;
if ( V_171 + V_55 < V_30 )
F_133 ( V_64 , V_171 , V_171 + V_55 ,
V_30 - V_171 - V_55 ) ;
V_123 -= V_55 ;
V_28 = F_138 ( V_85 , V_34 , V_62 , V_123 , 1 ) ;
}
F_97 ( V_64 ) ;
return 0 ;
}
static T_5
int F_139 ( struct V_84 * V_85 ,
struct V_33 * V_34 ,
struct V_61 * V_62 ,
T_2 V_26 , T_2 V_35 , T_2 V_17 ,
T_2 V_147 , T_2 V_109 ,
T_2 V_32 , int V_158 ,
struct V_178 * V_132 )
{
struct V_163 * V_164 ;
int V_28 ;
V_28 = F_126 ( V_85 , V_34 , V_62 , & V_164 ,
V_26 , V_35 , V_17 ,
V_147 , V_109 , V_32 , 1 ) ;
if ( V_28 == 0 ) {
F_22 ( V_109 < V_144 ) ;
V_28 = F_137 ( V_85 , V_34 , V_62 , V_164 ,
V_158 , V_132 ) ;
} else if ( V_28 == - V_154 ) {
V_28 = F_131 ( V_85 , V_34 , V_62 , V_164 ,
V_17 , V_147 ,
V_109 , V_32 , V_158 ,
V_132 ) ;
}
return V_28 ;
}
static int F_140 ( struct V_84 * V_85 ,
struct V_33 * V_34 ,
struct V_61 * V_62 ,
T_2 V_26 , T_2 V_17 , T_2 V_147 ,
T_2 V_109 , T_2 V_32 , int V_158 )
{
int V_28 ;
if ( V_109 < V_144 ) {
F_22 ( V_158 != 1 ) ;
V_28 = F_123 ( V_85 , V_34 , V_62 , V_26 ,
V_17 , V_147 ) ;
} else {
V_28 = F_107 ( V_85 , V_34 , V_62 , V_26 ,
V_17 , V_147 ,
V_109 , V_32 , V_158 ) ;
}
return V_28 ;
}
static int F_141 ( struct V_84 * V_85 ,
struct V_33 * V_34 ,
struct V_61 * V_62 ,
struct V_163 * V_164 ,
int V_160 , int V_182 )
{
int V_28 ;
F_22 ( ! V_182 && V_160 != 1 ) ;
if ( V_164 ) {
V_28 = F_137 ( V_85 , V_34 , V_62 , V_164 ,
- V_160 , NULL ) ;
} else if ( V_182 ) {
V_28 = F_116 ( V_85 , V_34 , V_62 , V_160 ) ;
} else {
V_28 = F_118 ( V_85 , V_34 , V_62 ) ;
}
return V_28 ;
}
static int F_142 ( struct V_183 * V_184 ,
T_2 V_31 , T_2 V_116 )
{
return F_143 ( V_184 , V_31 >> 9 , V_116 >> 9 , V_39 , 0 ) ;
}
static int F_144 ( struct V_33 * V_34 , T_2 V_26 ,
T_2 V_35 , T_2 * V_185 )
{
int V_28 ;
T_2 V_186 = 0 ;
struct V_187 * V_188 = NULL ;
V_28 = F_145 ( & V_34 -> V_36 -> V_47 , V_189 ,
V_26 , & V_35 , & V_188 , 0 ) ;
if ( ! V_28 ) {
struct V_190 * V_191 = V_188 -> V_192 ;
int V_42 ;
for ( V_42 = 0 ; V_42 < V_188 -> V_193 ; V_42 ++ , V_191 ++ ) {
V_28 = F_142 ( V_191 -> V_194 -> V_184 ,
V_191 -> V_195 ,
V_191 -> V_196 ) ;
if ( ! V_28 )
V_186 += V_191 -> V_196 ;
else if ( V_28 != - V_197 )
break;
}
F_9 ( V_188 ) ;
}
if ( V_186 && V_28 == - V_197 )
V_28 = 0 ;
if ( V_185 )
* V_185 = V_186 ;
return V_28 ;
}
int F_146 ( struct V_84 * V_85 ,
struct V_33 * V_34 ,
T_2 V_26 , T_2 V_35 , T_2 V_17 ,
T_2 V_147 , T_2 V_109 , T_2 V_32 )
{
int V_28 ;
F_22 ( V_109 < V_144 &&
V_147 == V_198 ) ;
if ( V_109 < V_144 ) {
V_28 = F_147 ( V_85 , V_26 , V_35 ,
V_17 , V_147 , ( int ) V_109 ,
V_199 , NULL ) ;
} else {
V_28 = F_148 ( V_85 , V_26 , V_35 ,
V_17 , V_147 , V_109 , V_32 ,
V_199 , NULL ) ;
}
return V_28 ;
}
static int F_149 ( struct V_84 * V_85 ,
struct V_33 * V_34 ,
T_2 V_26 , T_2 V_35 ,
T_2 V_17 , T_2 V_147 ,
T_2 V_109 , T_2 V_32 , int V_158 ,
struct V_178 * V_132 )
{
struct V_61 * V_62 ;
struct V_63 * V_64 ;
struct V_121 * V_114 ;
T_2 V_117 ;
int V_28 ;
int V_77 = 0 ;
V_62 = F_31 () ;
if ( ! V_62 )
return - V_69 ;
V_62 -> V_72 = 1 ;
V_62 -> V_200 = 1 ;
V_28 = F_139 ( V_85 , V_34 -> V_36 -> V_60 ,
V_62 , V_26 , V_35 , V_17 ,
V_147 , V_109 , V_32 ,
V_158 , V_132 ) ;
if ( V_28 == 0 )
goto V_130;
if ( V_28 != - V_176 ) {
V_77 = V_28 ;
goto V_130;
}
V_64 = V_62 -> V_78 [ 0 ] ;
V_114 = F_81 ( V_64 , V_62 -> V_79 [ 0 ] , struct V_121 ) ;
V_117 = F_82 ( V_64 , V_114 ) ;
F_92 ( V_64 , V_114 , V_117 + V_158 ) ;
if ( V_132 )
F_132 ( V_132 , V_64 , V_114 ) ;
F_97 ( V_64 ) ;
F_42 ( V_62 ) ;
V_62 -> V_72 = 1 ;
V_62 -> V_200 = 1 ;
V_28 = F_140 ( V_85 , V_34 -> V_36 -> V_60 ,
V_62 , V_26 , V_17 , V_147 ,
V_109 , V_32 , V_158 ) ;
F_22 ( V_28 ) ;
V_130:
F_47 ( V_62 ) ;
return V_77 ;
}
static int F_150 ( struct V_84 * V_85 ,
struct V_33 * V_34 ,
struct V_201 * V_131 ,
struct V_178 * V_132 ,
int V_202 )
{
int V_28 = 0 ;
struct V_203 * V_152 ;
struct V_65 V_204 ;
T_2 V_17 = 0 ;
T_2 V_205 = 0 ;
T_2 V_6 = 0 ;
V_204 . V_22 = V_131 -> V_26 ;
V_204 . V_32 = V_131 -> V_35 ;
V_204 . type = V_73 ;
V_152 = F_151 ( V_131 ) ;
if ( V_131 -> type == V_155 )
V_17 = V_152 -> V_17 ;
else
V_205 = V_152 -> V_34 ;
if ( V_131 -> V_206 == V_199 && V_202 ) {
if ( V_132 ) {
F_22 ( V_132 -> V_207 ) ;
V_6 |= V_132 -> V_134 ;
}
V_28 = F_152 ( V_85 , V_34 ,
V_17 , V_205 , V_6 ,
V_152 -> V_22 , V_152 -> V_32 ,
& V_204 , V_131 -> V_135 ) ;
} else if ( V_131 -> V_206 == V_199 ) {
V_28 = F_149 ( V_85 , V_34 , V_131 -> V_26 ,
V_131 -> V_35 , V_17 ,
V_205 , V_152 -> V_22 ,
V_152 -> V_32 , V_131 -> V_135 ,
V_132 ) ;
} else if ( V_131 -> V_206 == V_208 ) {
V_28 = F_153 ( V_85 , V_34 , V_131 -> V_26 ,
V_131 -> V_35 , V_17 ,
V_205 , V_152 -> V_22 ,
V_152 -> V_32 , V_131 -> V_135 ,
V_132 ) ;
} else {
F_63 () ;
}
return V_28 ;
}
static void F_132 ( struct V_178 * V_132 ,
struct V_63 * V_64 ,
struct V_121 * V_122 )
{
T_2 V_6 = F_83 ( V_64 , V_122 ) ;
if ( V_132 -> V_133 ) {
V_6 |= V_132 -> V_134 ;
F_94 ( V_64 , V_122 , V_6 ) ;
}
if ( V_132 -> V_207 ) {
struct V_139 * V_140 ;
F_22 ( ! ( V_6 & V_145 ) ) ;
V_140 = (struct V_139 * ) ( V_122 + 1 ) ;
F_154 ( V_64 , V_140 , & V_132 -> V_21 ) ;
}
}
static int F_155 ( struct V_84 * V_85 ,
struct V_33 * V_34 ,
struct V_201 * V_131 ,
struct V_178 * V_132 )
{
struct V_65 V_21 ;
struct V_61 * V_62 ;
struct V_121 * V_122 ;
struct V_63 * V_64 ;
T_3 V_123 ;
int V_28 ;
int V_77 = 0 ;
V_62 = F_31 () ;
if ( ! V_62 )
return - V_69 ;
V_21 . V_22 = V_131 -> V_26 ;
V_21 . type = V_73 ;
V_21 . V_32 = V_131 -> V_35 ;
V_62 -> V_72 = 1 ;
V_62 -> V_200 = 1 ;
V_28 = F_35 ( V_85 , V_34 -> V_36 -> V_60 , & V_21 ,
V_62 , 0 , 1 ) ;
if ( V_28 < 0 ) {
V_77 = V_28 ;
goto V_130;
}
if ( V_28 > 0 ) {
V_77 = - V_209 ;
goto V_130;
}
V_64 = V_62 -> V_78 [ 0 ] ;
V_123 = F_80 ( V_64 , V_62 -> V_79 [ 0 ] ) ;
#ifdef F_84
if ( V_123 < sizeof( * V_122 ) ) {
V_28 = F_89 ( V_85 , V_34 -> V_36 -> V_60 ,
V_62 , ( T_2 ) - 1 , 0 ) ;
if ( V_28 < 0 ) {
V_77 = V_28 ;
goto V_130;
}
V_64 = V_62 -> V_78 [ 0 ] ;
V_123 = F_80 ( V_64 , V_62 -> V_79 [ 0 ] ) ;
}
#endif
F_22 ( V_123 < sizeof( * V_122 ) ) ;
V_122 = F_81 ( V_64 , V_62 -> V_79 [ 0 ] , struct V_121 ) ;
F_132 ( V_132 , V_64 , V_122 ) ;
F_97 ( V_64 ) ;
V_130:
F_47 ( V_62 ) ;
return V_77 ;
}
static int F_156 ( struct V_84 * V_85 ,
struct V_33 * V_34 ,
struct V_201 * V_131 ,
struct V_178 * V_132 ,
int V_202 )
{
int V_28 = 0 ;
struct V_210 * V_152 ;
struct V_65 V_204 ;
T_2 V_17 = 0 ;
T_2 V_205 = 0 ;
V_204 . V_22 = V_131 -> V_26 ;
V_204 . V_32 = V_131 -> V_35 ;
V_204 . type = V_73 ;
V_152 = F_157 ( V_131 ) ;
if ( V_131 -> type == V_165 )
V_17 = V_152 -> V_17 ;
else
V_205 = V_152 -> V_34 ;
F_22 ( V_131 -> V_135 != 1 ) ;
if ( V_131 -> V_206 == V_199 && V_202 ) {
F_22 ( ! V_132 || ! V_132 -> V_133 ||
! V_132 -> V_207 ) ;
V_28 = F_158 ( V_85 , V_34 ,
V_17 , V_205 ,
V_132 -> V_134 ,
& V_132 -> V_21 ,
V_152 -> V_167 , & V_204 ) ;
} else if ( V_131 -> V_206 == V_199 ) {
V_28 = F_149 ( V_85 , V_34 , V_131 -> V_26 ,
V_131 -> V_35 , V_17 , V_205 ,
V_152 -> V_167 , 0 , 1 , V_132 ) ;
} else if ( V_131 -> V_206 == V_208 ) {
V_28 = F_153 ( V_85 , V_34 , V_131 -> V_26 ,
V_131 -> V_35 , V_17 , V_205 ,
V_152 -> V_167 , 0 , 1 , V_132 ) ;
} else {
F_63 () ;
}
return V_28 ;
}
static int F_159 ( struct V_84 * V_85 ,
struct V_33 * V_34 ,
struct V_201 * V_131 ,
struct V_178 * V_132 ,
int V_202 )
{
int V_28 ;
if ( F_160 ( V_131 ) ) {
struct V_118 * V_99 ;
F_22 ( V_132 ) ;
V_99 = F_161 ( V_131 ) ;
if ( V_202 ) {
F_162 ( V_34 , V_131 -> V_26 ,
V_131 -> V_35 , 1 ) ;
if ( V_99 -> V_182 ) {
V_28 = F_163 ( V_85 , V_34 ,
V_131 -> V_26 ,
V_131 -> V_35 ) ;
F_22 ( V_28 ) ;
}
}
F_44 ( & V_99 -> V_75 ) ;
return 0 ;
}
if ( V_131 -> type == V_166 ||
V_131 -> type == V_165 )
V_28 = F_156 ( V_85 , V_34 , V_131 , V_132 ,
V_202 ) ;
else if ( V_131 -> type == V_156 ||
V_131 -> type == V_155 )
V_28 = F_150 ( V_85 , V_34 , V_131 , V_132 ,
V_202 ) ;
else
F_63 () ;
return V_28 ;
}
T_1 int F_164 ( struct V_84 * V_85 ,
struct V_33 * V_34 ,
struct V_98 * V_211 )
{
struct V_119 * V_120 ;
struct V_201 * V_152 ;
struct V_118 * V_212 = NULL ;
struct V_178 * V_132 ;
int V_28 ;
int V_7 = 0 ;
int V_213 = 0 ;
V_120 = & V_85 -> V_90 -> V_120 ;
while ( 1 ) {
if ( ! V_212 ) {
if ( F_165 ( V_211 ) )
break;
V_212 = F_166 ( V_211 -> V_214 ,
struct V_118 , V_211 ) ;
V_28 = F_167 ( V_85 , V_212 ) ;
if ( V_28 == - V_176 ) {
V_212 = NULL ;
V_7 ++ ;
continue;
}
}
V_213 = V_212 -> V_213 ;
V_212 -> V_213 = 0 ;
V_132 = V_212 -> V_132 ;
V_212 -> V_132 = NULL ;
V_152 = F_168 ( V_212 ) ;
if ( ! V_152 ) {
V_152 = & V_212 -> V_131 ;
if ( V_132 && V_213 ) {
F_9 ( V_132 ) ;
V_132 = NULL ;
}
if ( V_132 ) {
F_13 ( & V_120 -> V_50 ) ;
V_28 = F_155 ( V_85 , V_34 ,
V_152 , V_132 ) ;
F_22 ( V_28 ) ;
F_9 ( V_132 ) ;
F_45 () ;
F_11 ( & V_120 -> V_50 ) ;
continue;
}
F_169 ( & V_212 -> V_211 ) ;
V_212 = NULL ;
}
V_152 -> V_215 = 0 ;
F_170 ( & V_152 -> V_15 , & V_120 -> V_34 ) ;
V_120 -> V_216 -- ;
F_13 ( & V_120 -> V_50 ) ;
V_28 = F_159 ( V_85 , V_34 , V_152 , V_132 ,
V_213 ) ;
F_22 ( V_28 ) ;
F_88 ( V_152 ) ;
F_9 ( V_132 ) ;
V_7 ++ ;
F_45 () ;
F_11 ( & V_120 -> V_50 ) ;
}
return V_7 ;
}
int F_171 ( struct V_84 * V_85 ,
struct V_33 * V_34 , unsigned long V_7 )
{
struct V_15 * V_131 ;
struct V_119 * V_120 ;
struct V_201 * V_152 ;
struct V_98 V_211 ;
int V_28 ;
int V_217 = V_7 == ( unsigned long ) - 1 ;
int V_218 = 0 ;
if ( V_34 == V_34 -> V_36 -> V_60 )
V_34 = V_34 -> V_36 -> V_92 ;
V_120 = & V_85 -> V_90 -> V_120 ;
F_52 ( & V_211 ) ;
V_74:
F_11 ( & V_120 -> V_50 ) ;
if ( V_7 == 0 ) {
V_7 = V_120 -> V_216 * 2 ;
V_218 = 1 ;
}
while ( 1 ) {
if ( ! ( V_217 || V_218 ) &&
V_120 -> V_219 < 64 )
break;
V_28 = F_172 ( V_85 , & V_211 ,
V_120 -> V_220 ) ;
if ( V_28 )
break;
V_28 = F_164 ( V_85 , V_34 , & V_211 ) ;
F_22 ( V_28 < 0 ) ;
V_7 -= F_173 (unsigned long, ret, count) ;
if ( V_7 == 0 )
break;
}
if ( V_217 ) {
V_131 = F_174 ( & V_120 -> V_34 ) ;
if ( ! V_131 )
goto V_130;
V_7 = ( unsigned long ) - 1 ;
while ( V_131 ) {
V_152 = F_12 ( V_131 , struct V_201 ,
V_15 ) ;
if ( F_160 ( V_152 ) ) {
struct V_118 * V_99 ;
V_99 = F_161 ( V_152 ) ;
F_5 ( & V_152 -> V_117 ) ;
F_13 ( & V_120 -> V_50 ) ;
F_33 ( & V_99 -> V_75 ) ;
F_44 ( & V_99 -> V_75 ) ;
F_88 ( V_152 ) ;
F_45 () ;
goto V_74;
}
V_131 = F_175 ( V_131 ) ;
}
F_13 ( & V_120 -> V_50 ) ;
F_176 ( 1 ) ;
goto V_74;
}
V_130:
F_13 ( & V_120 -> V_50 ) ;
return 0 ;
}
int F_177 ( struct V_84 * V_85 ,
struct V_33 * V_34 ,
T_2 V_26 , T_2 V_35 , T_2 V_6 ,
int V_182 )
{
struct V_178 * V_132 ;
int V_28 ;
V_132 = F_178 ( sizeof( * V_132 ) , V_39 ) ;
if ( ! V_132 )
return - V_69 ;
V_132 -> V_134 = V_6 ;
V_132 -> V_133 = 1 ;
V_132 -> V_207 = 0 ;
V_132 -> V_182 = V_182 ? 1 : 0 ;
V_28 = F_179 ( V_85 , V_26 , V_35 , V_132 ) ;
if ( V_28 )
F_9 ( V_132 ) ;
return V_28 ;
}
static T_1 int F_180 ( struct V_84 * V_85 ,
struct V_33 * V_34 ,
struct V_61 * V_62 ,
T_2 V_22 , T_2 V_32 , T_2 V_26 )
{
struct V_118 * V_99 ;
struct V_201 * V_152 ;
struct V_203 * V_221 ;
struct V_119 * V_120 ;
struct V_15 * V_131 ;
int V_28 = 0 ;
V_28 = - V_154 ;
V_120 = & V_85 -> V_90 -> V_120 ;
F_11 ( & V_120 -> V_50 ) ;
V_99 = F_86 ( V_85 , V_26 ) ;
if ( ! V_99 )
goto V_130;
if ( ! F_87 ( & V_99 -> V_75 ) ) {
F_5 ( & V_99 -> V_131 . V_117 ) ;
F_13 ( & V_120 -> V_50 ) ;
F_42 ( V_62 ) ;
F_33 ( & V_99 -> V_75 ) ;
F_44 ( & V_99 -> V_75 ) ;
F_88 ( & V_99 -> V_131 ) ;
return - V_176 ;
}
V_131 = F_181 ( & V_99 -> V_131 . V_15 ) ;
if ( ! V_131 )
goto V_222;
V_152 = F_12 ( V_131 , struct V_201 , V_15 ) ;
if ( V_152 -> V_26 != V_26 )
goto V_222;
V_28 = 1 ;
if ( V_152 -> type != V_156 )
goto V_222;
V_221 = F_151 ( V_152 ) ;
V_131 = F_181 ( V_131 ) ;
if ( V_131 ) {
V_152 = F_12 ( V_131 , struct V_201 , V_15 ) ;
if ( V_152 -> V_26 == V_26 )
goto V_222;
}
if ( V_221 -> V_34 != V_34 -> V_223 . V_22 ||
V_221 -> V_22 != V_22 || V_221 -> V_32 != V_32 )
goto V_222;
V_28 = 0 ;
V_222:
F_44 ( & V_99 -> V_75 ) ;
V_130:
F_13 ( & V_120 -> V_50 ) ;
return V_28 ;
}
static T_1 int F_182 ( struct V_84 * V_85 ,
struct V_33 * V_34 ,
struct V_61 * V_62 ,
T_2 V_22 , T_2 V_32 , T_2 V_26 )
{
struct V_33 * V_60 = V_34 -> V_36 -> V_60 ;
struct V_63 * V_64 ;
struct V_151 * V_152 ;
struct V_163 * V_164 ;
struct V_121 * V_122 ;
struct V_65 V_21 ;
T_3 V_123 ;
int V_28 ;
V_21 . V_22 = V_26 ;
V_21 . V_32 = ( T_2 ) - 1 ;
V_21 . type = V_73 ;
V_28 = F_35 ( NULL , V_60 , & V_21 , V_62 , 0 , 0 ) ;
if ( V_28 < 0 )
goto V_130;
F_22 ( V_28 == 0 ) ;
V_28 = - V_154 ;
if ( V_62 -> V_79 [ 0 ] == 0 )
goto V_130;
V_62 -> V_79 [ 0 ] -- ;
V_64 = V_62 -> V_78 [ 0 ] ;
F_38 ( V_64 , & V_21 , V_62 -> V_79 [ 0 ] ) ;
if ( V_21 . V_22 != V_26 || V_21 . type != V_73 )
goto V_130;
V_28 = 1 ;
V_123 = F_80 ( V_64 , V_62 -> V_79 [ 0 ] ) ;
#ifdef F_84
if ( V_123 < sizeof( * V_122 ) ) {
F_8 ( V_123 != sizeof( struct V_127 ) ) ;
goto V_130;
}
#endif
V_122 = F_81 ( V_64 , V_62 -> V_79 [ 0 ] , struct V_121 ) ;
if ( V_123 != sizeof( * V_122 ) +
F_127 ( V_156 ) )
goto V_130;
if ( F_183 ( V_64 , V_122 ) <=
F_184 ( & V_34 -> V_224 ) )
goto V_130;
V_164 = (struct V_163 * ) ( V_122 + 1 ) ;
if ( F_121 ( V_64 , V_164 ) !=
V_156 )
goto V_130;
V_152 = (struct V_151 * ) ( & V_164 -> V_32 ) ;
if ( F_82 ( V_64 , V_122 ) !=
F_115 ( V_64 , V_152 ) ||
F_102 ( V_64 , V_152 ) !=
V_34 -> V_223 . V_22 ||
F_103 ( V_64 , V_152 ) != V_22 ||
F_104 ( V_64 , V_152 ) != V_32 )
goto V_130;
V_28 = 0 ;
V_130:
return V_28 ;
}
int F_185 ( struct V_84 * V_85 ,
struct V_33 * V_34 ,
T_2 V_22 , T_2 V_32 , T_2 V_26 )
{
struct V_61 * V_62 ;
int V_28 ;
int V_225 ;
V_62 = F_31 () ;
if ( ! V_62 )
return - V_154 ;
do {
V_28 = F_182 ( V_85 , V_34 , V_62 , V_22 ,
V_32 , V_26 ) ;
if ( V_28 && V_28 != - V_154 )
goto V_130;
V_225 = F_180 ( V_85 , V_34 , V_62 , V_22 ,
V_32 , V_26 ) ;
} while ( V_225 == - V_176 );
if ( V_225 && V_225 != - V_154 ) {
V_28 = V_225 ;
goto V_130;
}
if ( V_28 != - V_154 || V_225 != - V_154 )
V_28 = 0 ;
V_130:
F_47 ( V_62 ) ;
if ( V_34 -> V_223 . V_22 == V_226 )
F_8 ( V_28 > 0 ) ;
return V_28 ;
}
static int F_186 ( struct V_84 * V_85 ,
struct V_33 * V_34 ,
struct V_63 * V_227 ,
int V_228 , int V_229 )
{
T_2 V_26 ;
T_2 V_35 ;
T_2 V_17 ;
T_2 V_205 ;
T_3 V_68 ;
struct V_65 V_21 ;
struct V_230 * V_231 ;
int V_42 ;
int V_167 ;
int V_28 = 0 ;
int (* F_187)( struct V_84 * , struct V_33 * ,
T_2 , T_2 , T_2 , T_2 , T_2 , T_2 );
V_205 = F_188 ( V_227 ) ;
V_68 = F_36 ( V_227 ) ;
V_167 = F_189 ( V_227 ) ;
if ( ! V_34 -> V_232 && V_167 == 0 )
return 0 ;
if ( V_229 )
F_187 = F_146 ;
else
F_187 = V_233 ;
if ( V_228 )
V_17 = V_227 -> V_31 ;
else
V_17 = 0 ;
for ( V_42 = 0 ; V_42 < V_68 ; V_42 ++ ) {
if ( V_167 == 0 ) {
F_38 ( V_227 , & V_21 , V_42 ) ;
if ( F_190 ( & V_21 ) != V_234 )
continue;
V_231 = F_81 ( V_227 , V_42 ,
struct V_230 ) ;
if ( F_191 ( V_227 , V_231 ) ==
V_235 )
continue;
V_26 = F_192 ( V_227 , V_231 ) ;
if ( V_26 == 0 )
continue;
V_35 = F_193 ( V_227 , V_231 ) ;
V_21 . V_32 -= F_194 ( V_227 , V_231 ) ;
V_28 = F_187 ( V_85 , V_34 , V_26 , V_35 ,
V_17 , V_205 , V_21 . V_22 ,
V_21 . V_32 ) ;
if ( V_28 )
goto V_157;
} else {
V_26 = F_195 ( V_227 , V_42 ) ;
V_35 = F_196 ( V_34 , V_167 - 1 ) ;
V_28 = F_187 ( V_85 , V_34 , V_26 , V_35 ,
V_17 , V_205 , V_167 - 1 , 0 ) ;
if ( V_28 )
goto V_157;
}
}
return 0 ;
V_157:
F_63 () ;
return V_28 ;
}
int F_197 ( struct V_84 * V_85 , struct V_33 * V_34 ,
struct V_63 * V_227 , int V_228 )
{
return F_186 ( V_85 , V_34 , V_227 , V_228 , 1 ) ;
}
int F_198 ( struct V_84 * V_85 , struct V_33 * V_34 ,
struct V_63 * V_227 , int V_228 )
{
return F_186 ( V_85 , V_34 , V_227 , V_228 , 0 ) ;
}
static int F_199 ( struct V_84 * V_85 ,
struct V_33 * V_34 ,
struct V_61 * V_62 ,
struct V_1 * V_2 )
{
int V_28 ;
struct V_33 * V_60 = V_34 -> V_36 -> V_60 ;
unsigned long V_140 ;
struct V_63 * V_64 ;
V_28 = F_35 ( V_85 , V_60 , & V_2 -> V_21 , V_62 , 0 , 1 ) ;
if ( V_28 < 0 )
goto V_157;
F_22 ( V_28 ) ;
V_64 = V_62 -> V_78 [ 0 ] ;
V_140 = F_200 ( V_64 , V_62 -> V_79 [ 0 ] ) ;
F_201 ( V_64 , & V_2 -> V_114 , V_140 , sizeof( V_2 -> V_114 ) ) ;
F_97 ( V_64 ) ;
F_42 ( V_62 ) ;
V_157:
if ( V_28 )
return V_28 ;
return 0 ;
}
static struct V_1 *
F_202 ( struct V_33 * V_34 ,
struct V_1 * V_2 )
{
struct V_15 * V_131 ;
F_11 ( & V_34 -> V_36 -> V_18 ) ;
V_131 = F_175 ( & V_2 -> V_20 ) ;
F_6 ( V_2 ) ;
if ( V_131 ) {
V_2 = F_12 ( V_131 , struct V_1 ,
V_20 ) ;
F_4 ( V_2 ) ;
} else
V_2 = NULL ;
F_13 ( & V_34 -> V_36 -> V_18 ) ;
return V_2 ;
}
static int F_203 ( struct V_1 * V_14 ,
struct V_84 * V_85 ,
struct V_61 * V_62 )
{
struct V_33 * V_34 = V_14 -> V_36 -> V_92 ;
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
V_74:
V_236 = F_204 ( V_34 , V_14 , V_62 ) ;
if ( F_60 ( V_236 ) && F_61 ( V_236 ) != - V_154 ) {
V_28 = F_61 ( V_236 ) ;
F_42 ( V_62 ) ;
goto V_130;
}
if ( F_60 ( V_236 ) ) {
F_22 ( V_241 ) ;
V_241 ++ ;
if ( V_14 -> V_115 )
goto V_126;
V_28 = F_205 ( V_34 , V_85 , V_14 , V_62 ) ;
if ( V_28 )
goto V_126;
goto V_74;
}
F_206 ( V_236 ) -> V_244 = 0 ;
V_28 = F_207 ( V_85 , V_34 , V_236 ) ;
F_8 ( V_28 ) ;
if ( F_208 ( V_236 ) > 0 ) {
V_28 = F_209 ( V_34 , V_85 , V_62 ,
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
V_240 = ( int ) F_210 ( V_14 -> V_21 . V_32 , 1024 * 1024 * 1024 ) ;
if ( ! V_240 )
V_240 = 1 ;
V_240 *= 16 ;
V_240 *= V_246 ;
V_28 = F_211 ( V_236 , V_240 ) ;
if ( V_28 )
goto V_245;
V_28 = F_212 ( V_236 , V_85 , 0 , 0 , V_240 ,
V_240 , V_240 ,
& V_237 ) ;
if ( ! V_28 )
V_238 = V_247 ;
F_213 ( V_236 , V_240 ) ;
V_245:
F_214 ( V_236 ) ;
V_126:
F_42 ( V_62 ) ;
V_130:
F_11 ( & V_14 -> V_50 ) ;
V_14 -> V_242 = V_238 ;
F_13 ( & V_14 -> V_50 ) ;
return V_28 ;
}
int F_215 ( struct V_84 * V_85 ,
struct V_33 * V_34 )
{
struct V_1 * V_2 ;
int V_77 = 0 ;
struct V_61 * V_62 ;
T_2 V_67 = 0 ;
V_62 = F_31 () ;
if ( ! V_62 )
return - V_69 ;
V_74:
while ( 1 ) {
V_2 = F_64 ( V_34 -> V_36 , V_67 ) ;
while ( V_2 ) {
if ( V_2 -> V_242 == V_248 )
break;
V_2 = F_202 ( V_34 , V_2 ) ;
}
if ( ! V_2 ) {
if ( V_67 == 0 )
break;
V_67 = 0 ;
continue;
}
V_77 = F_203 ( V_2 , V_85 , V_62 ) ;
V_67 = V_2 -> V_21 . V_22 + V_2 -> V_21 . V_32 ;
F_6 ( V_2 ) ;
}
while ( 1 ) {
if ( V_67 == 0 ) {
V_77 = F_171 ( V_85 , V_34 ,
( unsigned long ) - 1 ) ;
F_22 ( V_77 ) ;
}
V_2 = F_64 ( V_34 -> V_36 , V_67 ) ;
while ( V_2 ) {
if ( V_2 -> V_242 == V_248 ) {
F_6 ( V_2 ) ;
goto V_74;
}
if ( V_2 -> V_249 )
break;
V_2 = F_202 ( V_34 , V_2 ) ;
}
if ( ! V_2 ) {
if ( V_67 == 0 )
break;
V_67 = 0 ;
continue;
}
if ( V_2 -> V_242 == V_247 )
V_2 -> V_242 = V_250 ;
V_2 -> V_249 = 0 ;
V_67 = V_2 -> V_21 . V_22 + V_2 -> V_21 . V_32 ;
V_77 = F_199 ( V_85 , V_34 , V_62 , V_2 ) ;
F_22 ( V_77 ) ;
F_6 ( V_2 ) ;
}
while ( 1 ) {
if ( V_67 == 0 ) {
V_77 = F_171 ( V_85 , V_34 ,
( unsigned long ) - 1 ) ;
F_22 ( V_77 ) ;
}
V_2 = F_64 ( V_34 -> V_36 , V_67 ) ;
while ( V_2 ) {
if ( V_2 -> V_249 ) {
F_6 ( V_2 ) ;
goto V_74;
}
if ( V_2 -> V_242 == V_250 )
break;
V_2 = F_202 ( V_34 , V_2 ) ;
}
if ( ! V_2 ) {
if ( V_67 == 0 )
break;
V_67 = 0 ;
continue;
}
F_216 ( V_34 , V_85 , V_2 , V_62 ) ;
if ( V_2 -> V_242 == V_250 )
V_2 -> V_242 = V_243 ;
V_67 = V_2 -> V_21 . V_22 + V_2 -> V_21 . V_32 ;
F_6 ( V_2 ) ;
}
F_47 ( V_62 ) ;
return 0 ;
}
int F_217 ( struct V_33 * V_34 , T_2 V_26 )
{
struct V_1 * V_14 ;
int V_251 = 0 ;
V_14 = F_65 ( V_34 -> V_36 , V_26 ) ;
if ( ! V_14 || V_14 -> V_115 )
V_251 = 1 ;
if ( V_14 )
F_6 ( V_14 ) ;
return V_251 ;
}
static int F_218 ( struct V_12 * V_13 , T_2 V_6 ,
T_2 V_252 , T_2 V_253 ,
struct V_97 * * V_82 )
{
struct V_97 * V_100 ;
int V_42 ;
int V_106 ;
if ( V_6 & ( V_254 | V_255 |
V_256 ) )
V_106 = 2 ;
else
V_106 = 1 ;
V_100 = F_66 ( V_13 , V_6 ) ;
if ( V_100 ) {
F_11 ( & V_100 -> V_50 ) ;
V_100 -> V_252 += V_252 ;
V_100 -> V_257 += V_252 * V_106 ;
V_100 -> V_253 += V_253 ;
V_100 -> V_258 += V_253 * V_106 ;
V_100 -> V_104 = 0 ;
F_13 ( & V_100 -> V_50 ) ;
* V_82 = V_100 ;
return 0 ;
}
V_100 = F_51 ( sizeof( * V_100 ) , V_39 ) ;
if ( ! V_100 )
return - V_69 ;
for ( V_42 = 0 ; V_42 < V_259 ; V_42 ++ )
F_52 ( & V_100 -> V_260 [ V_42 ] ) ;
F_219 ( & V_100 -> V_261 ) ;
F_220 ( & V_100 -> V_50 ) ;
V_100 -> V_6 = V_6 & ( V_101 |
V_102 |
V_103 ) ;
V_100 -> V_252 = V_252 ;
V_100 -> V_257 = V_252 * V_106 ;
V_100 -> V_253 = V_253 ;
V_100 -> V_258 = V_253 * V_106 ;
V_100 -> V_262 = 0 ;
V_100 -> V_263 = 0 ;
V_100 -> V_264 = 0 ;
V_100 -> V_265 = 0 ;
V_100 -> V_104 = 0 ;
V_100 -> V_266 = V_267 ;
V_100 -> V_268 = 0 ;
* V_82 = V_100 ;
F_221 ( & V_100 -> V_94 , & V_13 -> V_82 ) ;
F_55 ( & V_100 -> V_83 , 0 ) ;
return 0 ;
}
static void F_222 ( struct V_12 * V_36 , T_2 V_6 )
{
T_2 V_269 = V_6 & ( V_270 |
V_255 |
V_256 |
V_254 ) ;
if ( V_269 ) {
if ( V_6 & V_101 )
V_36 -> V_271 |= V_269 ;
if ( V_6 & V_103 )
V_36 -> V_272 |= V_269 ;
if ( V_6 & V_102 )
V_36 -> V_273 |= V_269 ;
}
}
T_2 F_223 ( struct V_33 * V_34 , T_2 V_6 )
{
T_2 V_274 = V_34 -> V_36 -> V_275 -> V_276 +
V_34 -> V_36 -> V_275 -> V_277 ;
if ( V_274 == 1 )
V_6 &= ~ ( V_255 | V_270 ) ;
if ( V_274 < 4 )
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
if ( ( V_6 & V_270 ) &&
( ( V_6 & V_255 ) |
( V_6 & V_256 ) |
( V_6 & V_254 ) ) )
V_6 &= ~ V_270 ;
return V_6 ;
}
static T_2 F_224 ( struct V_33 * V_34 , T_2 V_6 )
{
if ( V_6 & V_101 )
V_6 |= V_34 -> V_36 -> V_271 &
V_34 -> V_36 -> V_278 ;
else if ( V_6 & V_102 )
V_6 |= V_34 -> V_36 -> V_273 &
V_34 -> V_36 -> V_279 ;
else if ( V_6 & V_103 )
V_6 |= V_34 -> V_36 -> V_272 &
V_34 -> V_36 -> V_280 ;
return F_223 ( V_34 , V_6 ) ;
}
T_2 F_225 ( struct V_33 * V_34 , int V_59 )
{
T_2 V_6 ;
if ( V_59 )
V_6 = V_101 ;
else if ( V_34 == V_34 -> V_36 -> V_281 )
V_6 = V_102 ;
else
V_6 = V_103 ;
return F_224 ( V_34 , V_6 ) ;
}
void F_226 ( struct V_33 * V_34 , struct V_236 * V_236 )
{
F_206 ( V_236 ) -> V_82 = F_66 ( V_34 -> V_36 ,
V_101 ) ;
}
int F_211 ( struct V_236 * V_236 , T_2 V_282 )
{
struct V_97 * V_283 ;
struct V_33 * V_34 = F_206 ( V_236 ) -> V_34 ;
T_2 V_110 ;
int V_28 = 0 , V_284 = 0 , V_285 = 1 ;
V_282 = ( V_282 + V_34 -> V_286 - 1 ) & ~ ( ( T_2 ) V_34 -> V_286 - 1 ) ;
if ( V_34 == V_34 -> V_36 -> V_92 ||
F_206 ( V_236 ) -> V_287 . V_22 == V_288 ) {
V_285 = 0 ;
V_284 = 1 ;
}
V_283 = F_206 ( V_236 ) -> V_82 ;
if ( ! V_283 )
goto V_289;
V_74:
F_11 ( & V_283 -> V_50 ) ;
V_110 = V_283 -> V_253 + V_283 -> V_263 +
V_283 -> V_262 + V_283 -> V_264 +
V_283 -> V_265 ;
if ( V_110 + V_282 > V_283 -> V_252 ) {
struct V_84 * V_85 ;
if ( ! V_283 -> V_104 && V_285 ) {
T_2 V_290 ;
V_283 -> V_266 = V_291 ;
F_13 ( & V_283 -> V_50 ) ;
V_289:
V_290 = F_225 ( V_34 , 1 ) ;
V_85 = F_227 ( V_34 ) ;
if ( F_60 ( V_85 ) )
return F_61 ( V_85 ) ;
V_28 = F_228 ( V_85 , V_34 -> V_36 -> V_60 ,
V_282 + 2 * 1024 * 1024 ,
V_290 ,
V_267 ) ;
F_229 ( V_85 , V_34 ) ;
if ( V_28 < 0 ) {
if ( V_28 != - V_292 )
return V_28 ;
else
goto V_293;
}
if ( ! V_283 ) {
F_226 ( V_34 , V_236 ) ;
V_283 = F_206 ( V_236 ) -> V_82 ;
}
goto V_74;
}
if ( V_283 -> V_262 < V_282 )
V_284 = 1 ;
F_13 ( & V_283 -> V_50 ) ;
V_293:
if ( ! V_284 &&
! F_230 ( & V_34 -> V_36 -> V_294 ) ) {
V_284 = 1 ;
V_85 = F_227 ( V_34 ) ;
if ( F_60 ( V_85 ) )
return F_61 ( V_85 ) ;
V_28 = F_231 ( V_85 , V_34 ) ;
if ( V_28 )
return V_28 ;
goto V_74;
}
return - V_292 ;
}
V_283 -> V_265 += V_282 ;
F_206 ( V_236 ) -> V_295 += V_282 ;
F_13 ( & V_283 -> V_50 ) ;
return 0 ;
}
void F_213 ( struct V_236 * V_236 , T_2 V_282 )
{
struct V_33 * V_34 = F_206 ( V_236 ) -> V_34 ;
struct V_97 * V_283 ;
V_282 = ( V_282 + V_34 -> V_286 - 1 ) & ~ ( ( T_2 ) V_34 -> V_286 - 1 ) ;
V_283 = F_206 ( V_236 ) -> V_82 ;
F_11 ( & V_283 -> V_50 ) ;
V_283 -> V_265 -= V_282 ;
F_206 ( V_236 ) -> V_295 -= V_282 ;
F_13 ( & V_283 -> V_50 ) ;
}
static void F_232 ( struct V_12 * V_13 )
{
struct V_98 * V_99 = & V_13 -> V_82 ;
struct V_97 * V_100 ;
F_67 () ;
F_68 (found, head, list) {
if ( V_100 -> V_6 & V_103 )
V_100 -> V_266 = V_291 ;
}
F_69 () ;
}
static int F_233 ( struct V_33 * V_34 ,
struct V_97 * V_296 , T_2 V_297 ,
int V_298 )
{
T_2 V_35 = V_296 -> V_252 - V_296 -> V_264 ;
T_2 V_299 = V_296 -> V_253 + V_296 -> V_263 ;
T_2 V_300 ;
if ( V_298 == V_291 )
return 1 ;
if ( V_298 == V_301 ) {
V_300 = F_234 ( & V_34 -> V_36 -> V_302 ) ;
V_300 = F_32 ( T_2 , 64 * 1024 * 1024 ,
F_73 ( V_300 , 1 ) ) ;
if ( V_35 - V_299 < V_300 )
return 1 ;
}
if ( V_299 + V_297 + 256 * 1024 * 1024 < V_35 )
return 0 ;
if ( V_299 + V_297 < F_71 ( V_35 , 8 ) )
return 0 ;
V_300 = F_234 ( & V_34 -> V_36 -> V_302 ) ;
V_300 = F_32 ( T_2 , 256 * 1024 * 1024 , F_73 ( V_300 , 5 ) ) ;
if ( V_35 > V_300 && V_296 -> V_253 < F_71 ( V_35 , 3 ) )
return 0 ;
return 1 ;
}
static int F_228 ( struct V_84 * V_85 ,
struct V_33 * V_60 , T_2 V_297 ,
T_2 V_6 , int V_298 )
{
struct V_97 * V_82 ;
struct V_12 * V_36 = V_60 -> V_36 ;
int V_303 = 0 ;
int V_28 = 0 ;
V_6 = F_223 ( V_60 , V_6 ) ;
V_82 = F_66 ( V_60 -> V_36 , V_6 ) ;
if ( ! V_82 ) {
V_28 = F_218 ( V_60 -> V_36 , V_6 ,
0 , 0 , & V_82 ) ;
F_22 ( V_28 ) ;
}
F_22 ( ! V_82 ) ;
V_74:
F_11 ( & V_82 -> V_50 ) ;
if ( V_82 -> V_266 )
V_298 = V_82 -> V_266 ;
if ( V_82 -> V_104 ) {
F_13 ( & V_82 -> V_50 ) ;
return 0 ;
}
if ( ! F_233 ( V_60 , V_82 , V_297 , V_298 ) ) {
F_13 ( & V_82 -> V_50 ) ;
return 0 ;
} else if ( V_82 -> V_268 ) {
V_303 = 1 ;
} else {
V_82 -> V_268 = 1 ;
}
F_13 ( & V_82 -> V_50 ) ;
F_33 ( & V_36 -> V_304 ) ;
if ( V_303 ) {
F_44 ( & V_36 -> V_304 ) ;
V_303 = 0 ;
goto V_74;
}
if ( F_235 ( V_82 ) )
V_6 |= ( V_101 | V_103 ) ;
if ( V_6 & V_101 && V_36 -> V_305 ) {
V_36 -> V_306 ++ ;
if ( ! ( V_36 -> V_306 %
V_36 -> V_305 ) )
F_232 ( V_36 ) ;
}
V_28 = F_236 ( V_85 , V_60 , V_6 ) ;
F_11 ( & V_82 -> V_50 ) ;
if ( V_28 )
V_82 -> V_104 = 1 ;
else
V_28 = 1 ;
V_82 -> V_266 = V_267 ;
V_82 -> V_268 = 0 ;
F_13 ( & V_82 -> V_50 ) ;
F_44 ( & V_60 -> V_36 -> V_304 ) ;
return V_28 ;
}
static int F_237 ( struct V_84 * V_85 ,
struct V_33 * V_34 , T_2 V_307 , int V_308 )
{
struct V_309 * V_310 ;
struct V_97 * V_82 ;
T_2 V_9 ;
T_2 V_311 ;
T_2 V_312 = 0 ;
long V_313 ;
int V_314 = ( 2 * 1024 * 1024 ) >> V_315 ;
int V_316 = 0 ;
unsigned long V_80 ;
V_310 = & V_34 -> V_36 -> V_317 ;
V_82 = V_310 -> V_82 ;
F_2 () ;
V_9 = V_82 -> V_263 ;
V_80 = V_82 -> V_318 ;
if ( V_9 == 0 )
return 0 ;
V_311 = F_238 ( V_9 , V_307 ) ;
while ( V_316 < 1024 ) {
F_2 () ;
V_314 = F_173 (unsigned long, nr_pages,
root->fs_info->delalloc_bytes >> PAGE_CACHE_SHIFT) ;
F_239 ( V_34 -> V_36 -> V_319 , V_314 ) ;
F_11 ( & V_82 -> V_50 ) ;
if ( V_9 > V_82 -> V_263 )
V_312 += V_9 - V_82 -> V_263 ;
V_9 = V_82 -> V_263 ;
F_13 ( & V_82 -> V_50 ) ;
V_316 ++ ;
if ( V_9 == 0 || V_312 >= V_311 )
break;
if ( V_85 && V_85 -> V_90 -> V_320 )
return - V_176 ;
V_313 = F_240 ( 1 ) ;
if ( V_313 )
break;
if ( V_316 > 3 ) {
F_2 () ;
if ( V_80 != V_82 -> V_318 )
break;
}
}
return V_312 >= V_307 ;
}
static int F_241 ( struct V_84 * V_85 ,
struct V_33 * V_34 ,
struct V_309 * V_310 ,
T_2 V_321 , int V_322 )
{
struct V_97 * V_82 = V_310 -> V_82 ;
T_2 V_323 ;
T_2 V_35 = V_321 ;
int V_241 = 0 ;
int V_28 = 0 ;
bool V_9 = false ;
bool V_284 = false ;
V_74:
V_28 = - V_292 ;
if ( V_9 )
V_35 = 0 ;
F_11 ( & V_82 -> V_50 ) ;
V_323 = V_82 -> V_253 + V_82 -> V_263 +
V_82 -> V_262 + V_82 -> V_264 +
V_82 -> V_265 ;
if ( V_323 <= V_82 -> V_252 ) {
V_323 = V_82 -> V_252 - V_323 ;
if ( V_323 >= V_35 ) {
if ( ! V_9 )
V_82 -> V_263 += V_321 ;
V_28 = 0 ;
} else {
V_35 = V_321 ;
}
} else {
V_35 = V_323 - V_82 -> V_252 +
( V_321 * ( V_241 + 1 ) ) ;
}
if ( V_28 && ! V_9 ) {
V_82 -> V_263 += V_321 ;
V_9 = true ;
}
F_13 ( & V_82 -> V_50 ) ;
if ( ! V_28 )
return 0 ;
if ( ! V_322 )
goto V_130;
V_28 = F_237 ( V_85 , V_34 , V_35 , 1 ) ;
if ( V_28 > 0 )
return 0 ;
else if ( V_28 < 0 )
goto V_130;
if ( V_241 < 2 ) {
V_241 ++ ;
goto V_74;
}
F_11 ( & V_82 -> V_50 ) ;
if ( V_82 -> V_262 < V_321 )
V_28 = - V_292 ;
F_13 ( & V_82 -> V_50 ) ;
if ( V_28 )
goto V_130;
V_28 = - V_176 ;
if ( V_85 || V_284 )
goto V_130;
V_28 = - V_292 ;
V_85 = F_227 ( V_34 ) ;
if ( F_60 ( V_85 ) )
goto V_130;
V_28 = F_231 ( V_85 , V_34 ) ;
if ( ! V_28 ) {
V_85 = NULL ;
V_284 = true ;
goto V_74;
}
V_130:
if ( V_9 ) {
F_11 ( & V_82 -> V_50 ) ;
V_82 -> V_263 -= V_321 ;
F_13 ( & V_82 -> V_50 ) ;
}
return V_28 ;
}
static struct V_309 * F_242 ( struct V_84 * V_85 ,
struct V_33 * V_34 )
{
struct V_309 * V_310 ;
if ( V_34 -> V_232 )
V_310 = V_85 -> V_310 ;
else
V_310 = V_34 -> V_310 ;
if ( ! V_310 )
V_310 = & V_34 -> V_36 -> V_324 ;
return V_310 ;
}
static int F_243 ( struct V_309 * V_310 ,
T_2 V_35 )
{
int V_28 = - V_292 ;
F_11 ( & V_310 -> V_50 ) ;
if ( V_310 -> V_9 >= V_35 ) {
V_310 -> V_9 -= V_35 ;
if ( V_310 -> V_9 < V_310 -> V_55 )
V_310 -> V_104 = 0 ;
V_28 = 0 ;
}
F_13 ( & V_310 -> V_50 ) ;
return V_28 ;
}
static void F_244 ( struct V_309 * V_310 ,
T_2 V_35 , int V_325 )
{
F_11 ( & V_310 -> V_50 ) ;
V_310 -> V_9 += V_35 ;
if ( V_325 )
V_310 -> V_55 += V_35 ;
else if ( V_310 -> V_9 >= V_310 -> V_55 )
V_310 -> V_104 = 1 ;
F_13 ( & V_310 -> V_50 ) ;
}
static void F_245 ( struct V_309 * V_310 ,
struct V_309 * V_326 , T_2 V_35 )
{
struct V_97 * V_82 = V_310 -> V_82 ;
F_11 ( & V_310 -> V_50 ) ;
if ( V_35 == ( T_2 ) - 1 )
V_35 = V_310 -> V_55 ;
V_310 -> V_55 -= V_35 ;
if ( V_310 -> V_9 >= V_310 -> V_55 ) {
V_35 = V_310 -> V_9 - V_310 -> V_55 ;
V_310 -> V_9 = V_310 -> V_55 ;
V_310 -> V_104 = 1 ;
} else {
V_35 = 0 ;
}
F_13 ( & V_310 -> V_50 ) ;
if ( V_35 > 0 ) {
if ( V_326 ) {
F_11 ( & V_326 -> V_50 ) ;
if ( ! V_326 -> V_104 ) {
T_2 V_327 ;
V_327 = V_326 -> V_55 - V_326 -> V_9 ;
V_327 = F_238 ( V_35 , V_327 ) ;
V_326 -> V_9 += V_327 ;
if ( V_326 -> V_9 >= V_326 -> V_55 )
V_326 -> V_104 = 1 ;
V_35 -= V_327 ;
}
F_13 ( & V_326 -> V_50 ) ;
}
if ( V_35 ) {
F_11 ( & V_82 -> V_50 ) ;
V_82 -> V_263 -= V_35 ;
V_82 -> V_318 ++ ;
F_13 ( & V_82 -> V_50 ) ;
}
}
}
static int F_246 ( struct V_309 * V_328 ,
struct V_309 * V_329 , T_2 V_35 )
{
int V_28 ;
V_28 = F_243 ( V_328 , V_35 ) ;
if ( V_28 )
return V_28 ;
F_244 ( V_329 , V_35 , 1 ) ;
return 0 ;
}
void F_247 ( struct V_309 * V_330 )
{
memset ( V_330 , 0 , sizeof( * V_330 ) ) ;
F_220 ( & V_330 -> V_50 ) ;
F_55 ( & V_330 -> V_331 , 1 ) ;
V_330 -> V_332 = 6 ;
F_52 ( & V_330 -> V_94 ) ;
}
struct V_309 * F_248 ( struct V_33 * V_34 )
{
struct V_309 * V_310 ;
struct V_12 * V_36 = V_34 -> V_36 ;
V_310 = F_178 ( sizeof( * V_310 ) , V_39 ) ;
if ( ! V_310 )
return NULL ;
F_247 ( V_310 ) ;
V_310 -> V_82 = F_66 ( V_36 ,
V_103 ) ;
return V_310 ;
}
void F_249 ( struct V_33 * V_34 ,
struct V_309 * V_330 )
{
if ( V_330 && F_7 ( & V_330 -> V_331 ) ) {
F_250 ( V_34 , V_330 , ( T_2 ) - 1 ) ;
if ( ! V_330 -> V_333 )
F_9 ( V_330 ) ;
}
}
void F_251 ( struct V_12 * V_36 ,
struct V_309 * V_310 )
{
V_310 -> V_333 = 1 ;
F_33 ( & V_36 -> V_334 ) ;
F_57 ( & V_310 -> V_94 , & V_36 -> V_335 ) ;
F_44 ( & V_36 -> V_334 ) ;
}
int F_252 ( struct V_84 * V_85 ,
struct V_33 * V_34 ,
struct V_309 * V_310 ,
T_2 V_35 )
{
int V_28 ;
if ( V_35 == 0 )
return 0 ;
V_28 = F_241 ( V_85 , V_34 , V_310 , V_35 , 1 ) ;
if ( ! V_28 ) {
F_244 ( V_310 , V_35 , 1 ) ;
return 0 ;
}
return V_28 ;
}
int F_253 ( struct V_84 * V_85 ,
struct V_33 * V_34 ,
struct V_309 * V_310 ,
T_2 V_336 , int V_337 )
{
T_2 V_35 = 0 ;
int V_293 = 0 ;
int V_28 = - V_292 ;
if ( ! V_310 )
return 0 ;
F_11 ( & V_310 -> V_50 ) ;
if ( V_337 > 0 )
V_35 = F_71 ( V_310 -> V_55 , V_337 ) ;
if ( V_336 > V_35 )
V_35 = V_336 ;
if ( V_310 -> V_9 >= V_35 ) {
V_28 = 0 ;
} else {
V_35 -= V_310 -> V_9 ;
if ( V_310 -> V_333 &&
V_310 -> V_338 [ 0 ] + V_310 -> V_338 [ 1 ] >= V_35 )
V_293 = 1 ;
}
F_13 ( & V_310 -> V_50 ) ;
if ( ! V_28 )
return 0 ;
if ( V_310 -> V_339 ) {
V_28 = F_241 ( V_85 , V_34 , V_310 ,
V_35 , 0 ) ;
if ( ! V_28 ) {
F_244 ( V_310 , V_35 , 0 ) ;
return 0 ;
}
}
if ( V_293 ) {
if ( V_85 )
return - V_176 ;
V_85 = F_227 ( V_34 ) ;
F_22 ( F_60 ( V_85 ) ) ;
V_28 = F_231 ( V_85 , V_34 ) ;
return 0 ;
}
return - V_292 ;
}
int F_254 ( struct V_309 * V_340 ,
struct V_309 * V_341 ,
T_2 V_35 )
{
return F_246 ( V_340 , V_341 , V_35 ) ;
}
void F_250 ( struct V_33 * V_34 ,
struct V_309 * V_310 ,
T_2 V_35 )
{
struct V_309 * V_342 = & V_34 -> V_36 -> V_343 ;
if ( V_342 -> V_104 || V_342 == V_310 ||
V_310 -> V_82 != V_342 -> V_82 )
V_342 = NULL ;
F_245 ( V_310 , V_342 , V_35 ) ;
}
static T_2 F_255 ( struct V_12 * V_36 )
{
struct V_97 * V_296 ;
T_2 V_35 ;
T_2 V_344 ;
T_2 V_345 ;
int V_346 = F_256 ( & V_36 -> V_302 ) ;
V_296 = F_66 ( V_36 , V_101 ) ;
F_11 ( & V_296 -> V_50 ) ;
V_345 = V_296 -> V_253 ;
F_13 ( & V_296 -> V_50 ) ;
V_296 = F_66 ( V_36 , V_103 ) ;
F_11 ( & V_296 -> V_50 ) ;
if ( V_296 -> V_6 & V_101 )
V_345 = 0 ;
V_344 = V_296 -> V_253 ;
F_13 ( & V_296 -> V_50 ) ;
V_35 = ( V_345 >> V_36 -> V_319 -> V_347 ) *
V_346 * 2 ;
V_35 += F_210 ( V_345 + V_344 , 50 ) ;
if ( V_35 * 3 > V_344 )
V_35 = F_210 ( V_344 , 3 ) ;
return F_257 ( V_35 , V_36 -> V_60 -> V_348 << 10 ) ;
}
static void F_258 ( struct V_12 * V_36 )
{
struct V_309 * V_310 = & V_36 -> V_343 ;
struct V_97 * V_296 = V_310 -> V_82 ;
T_2 V_35 ;
V_35 = F_255 ( V_36 ) ;
F_11 ( & V_310 -> V_50 ) ;
F_11 ( & V_296 -> V_50 ) ;
V_310 -> V_55 = V_35 ;
V_35 = V_296 -> V_253 + V_296 -> V_262 +
V_296 -> V_263 + V_296 -> V_264 +
V_296 -> V_265 ;
if ( V_296 -> V_252 > V_35 ) {
V_35 = V_296 -> V_252 - V_35 ;
V_310 -> V_9 += V_35 ;
V_296 -> V_263 += V_35 ;
}
if ( V_310 -> V_9 >= V_310 -> V_55 ) {
V_35 = V_310 -> V_9 - V_310 -> V_55 ;
V_296 -> V_263 -= V_35 ;
V_296 -> V_318 ++ ;
V_310 -> V_9 = V_310 -> V_55 ;
V_310 -> V_104 = 1 ;
}
F_13 ( & V_296 -> V_50 ) ;
F_13 ( & V_310 -> V_50 ) ;
}
static void F_259 ( struct V_12 * V_36 )
{
struct V_97 * V_82 ;
V_82 = F_66 ( V_36 , V_102 ) ;
V_36 -> V_349 . V_82 = V_82 ;
V_36 -> V_349 . V_332 = 10 ;
V_82 = F_66 ( V_36 , V_103 ) ;
V_36 -> V_343 . V_82 = V_82 ;
V_36 -> V_343 . V_332 = 10 ;
V_36 -> V_343 . V_339 = 1 ;
V_36 -> V_317 . V_82 = V_82 ;
V_36 -> V_350 . V_82 = V_82 ;
V_36 -> V_324 . V_82 = V_82 ;
V_36 -> V_324 . V_332 = 10 ;
V_36 -> V_60 -> V_310 = & V_36 -> V_343 ;
V_36 -> V_351 -> V_310 = & V_36 -> V_343 ;
V_36 -> V_352 -> V_310 = & V_36 -> V_343 ;
V_36 -> V_92 -> V_310 = & V_36 -> V_343 ;
V_36 -> V_281 -> V_310 = & V_36 -> V_349 ;
F_251 ( V_36 , & V_36 -> V_343 ) ;
F_251 ( V_36 , & V_36 -> V_317 ) ;
F_258 ( V_36 ) ;
}
static void F_260 ( struct V_12 * V_36 )
{
F_245 ( & V_36 -> V_343 , NULL , ( T_2 ) - 1 ) ;
F_8 ( V_36 -> V_317 . V_55 > 0 ) ;
F_8 ( V_36 -> V_317 . V_9 > 0 ) ;
F_8 ( V_36 -> V_350 . V_55 > 0 ) ;
F_8 ( V_36 -> V_350 . V_9 > 0 ) ;
F_8 ( V_36 -> V_349 . V_55 > 0 ) ;
F_8 ( V_36 -> V_349 . V_9 > 0 ) ;
}
int F_261 ( struct V_84 * V_85 ,
struct V_33 * V_34 ,
struct V_309 * V_330 )
{
struct V_309 * V_353 = & V_34 -> V_36 -> V_350 ;
T_2 V_35 ;
int V_28 ;
V_35 = F_262 ( V_34 , 2 ) ;
if ( V_330 -> V_9 >= V_35 )
return 0 ;
V_35 -= V_330 -> V_9 ;
V_28 = F_246 ( V_353 , V_330 , V_35 ) ;
F_22 ( V_28 ) ;
return 0 ;
}
int F_263 ( struct V_84 * V_85 ,
struct V_33 * V_34 ,
int V_354 )
{
T_2 V_35 ;
int V_28 ;
if ( V_354 == 0 || V_34 -> V_36 -> V_281 == V_34 )
return 0 ;
V_35 = F_262 ( V_34 , V_354 ) ;
V_28 = F_252 ( V_85 , V_34 , & V_34 -> V_36 -> V_350 ,
V_35 ) ;
if ( ! V_28 ) {
V_85 -> V_263 += V_35 ;
V_85 -> V_310 = & V_34 -> V_36 -> V_350 ;
}
return V_28 ;
}
void F_264 ( struct V_84 * V_85 ,
struct V_33 * V_34 )
{
if ( ! V_85 -> V_263 )
return;
F_22 ( V_85 -> V_310 != & V_34 -> V_36 -> V_350 ) ;
F_250 ( V_34 , V_85 -> V_310 ,
V_85 -> V_263 ) ;
V_85 -> V_263 = 0 ;
}
int F_265 ( struct V_84 * V_85 ,
struct V_236 * V_236 )
{
struct V_33 * V_34 = F_206 ( V_236 ) -> V_34 ;
struct V_309 * V_340 = F_242 ( V_85 , V_34 ) ;
struct V_309 * V_341 = V_34 -> V_355 ;
T_2 V_35 = F_262 ( V_34 , 1 ) ;
return F_246 ( V_340 , V_341 , V_35 ) ;
}
void F_266 ( struct V_236 * V_236 )
{
struct V_33 * V_34 = F_206 ( V_236 ) -> V_34 ;
T_2 V_35 = F_262 ( V_34 , 1 ) ;
F_250 ( V_34 , V_34 -> V_355 , V_35 ) ;
}
int F_267 ( struct V_84 * V_85 ,
struct V_356 * V_357 )
{
struct V_33 * V_34 = V_357 -> V_34 ;
struct V_309 * V_340 = F_242 ( V_85 , V_34 ) ;
struct V_309 * V_341 = & V_357 -> V_310 ;
T_2 V_35 = F_262 ( V_34 , 5 ) ;
V_341 -> V_82 = V_340 -> V_82 ;
return F_246 ( V_340 , V_341 , V_35 ) ;
}
static T_2 F_268 ( struct V_236 * V_236 , T_2 V_35 )
{
return V_35 >>= 3 ;
}
int F_269 ( struct V_236 * V_236 , T_2 V_35 )
{
struct V_33 * V_34 = F_206 ( V_236 ) -> V_34 ;
struct V_309 * V_310 = & V_34 -> V_36 -> V_317 ;
T_2 V_358 ;
int V_359 ;
int V_360 ;
int V_28 ;
if ( F_270 ( V_34 -> V_36 ) )
F_176 ( 1 ) ;
V_35 = F_257 ( V_35 , V_34 -> V_286 ) ;
V_359 = F_230 ( & F_206 ( V_236 ) -> V_361 ) + 1 ;
V_360 = F_230 ( & F_206 ( V_236 ) -> V_360 ) ;
if ( V_359 > V_360 ) {
V_359 -= V_360 ;
V_358 = F_262 ( V_34 , V_359 ) ;
} else {
V_359 = 0 ;
V_358 = 0 ;
}
V_358 += F_268 ( V_236 , V_35 ) ;
V_28 = F_241 ( NULL , V_34 , V_310 , V_358 , 1 ) ;
if ( V_28 )
return V_28 ;
F_271 ( V_359 , & F_206 ( V_236 ) -> V_360 ) ;
F_5 ( & F_206 ( V_236 ) -> V_361 ) ;
F_244 ( V_310 , V_358 , 1 ) ;
if ( V_310 -> V_55 > 512 * 1024 * 1024 )
F_237 ( NULL , V_34 , V_358 , 0 ) ;
return 0 ;
}
void F_272 ( struct V_236 * V_236 , T_2 V_35 )
{
struct V_33 * V_34 = F_206 ( V_236 ) -> V_34 ;
T_2 V_362 ;
int V_359 ;
int V_360 ;
V_35 = F_257 ( V_35 , V_34 -> V_286 ) ;
F_48 ( & F_206 ( V_236 ) -> V_361 ) ;
F_8 ( F_230 ( & F_206 ( V_236 ) -> V_361 ) < 0 ) ;
V_360 = F_230 ( & F_206 ( V_236 ) -> V_360 ) ;
do {
int V_363 , V_364 ;
V_359 = F_230 ( & F_206 ( V_236 ) -> V_361 ) ;
if ( V_359 >= V_360 ) {
V_359 = 0 ;
break;
}
V_363 = V_360 ;
V_359 = V_360 - V_359 ;
V_364 = V_360 - V_359 ;
V_363 = F_273 ( & F_206 ( V_236 ) -> V_360 ,
V_360 , V_364 ) ;
if ( F_274 ( V_363 == V_360 ) )
break;
V_360 = V_363 ;
} while ( 1 );
V_362 = F_268 ( V_236 , V_35 ) ;
if ( V_359 > 0 )
V_362 += F_262 ( V_34 , V_359 ) ;
F_250 ( V_34 , & V_34 -> V_36 -> V_317 ,
V_362 ) ;
}
int F_275 ( struct V_236 * V_236 , T_2 V_35 )
{
int V_28 ;
V_28 = F_211 ( V_236 , V_35 ) ;
if ( V_28 )
return V_28 ;
V_28 = F_269 ( V_236 , V_35 ) ;
if ( V_28 ) {
F_213 ( V_236 , V_35 ) ;
return V_28 ;
}
return 0 ;
}
void F_276 ( struct V_236 * V_236 , T_2 V_35 )
{
F_272 ( V_236 , V_35 ) ;
F_213 ( V_236 , V_35 ) ;
}
static int F_277 ( struct V_84 * V_85 ,
struct V_33 * V_34 ,
T_2 V_26 , T_2 V_35 , int V_289 )
{
struct V_1 * V_2 = NULL ;
struct V_12 * V_13 = V_34 -> V_36 ;
T_2 V_365 = V_35 ;
T_2 V_366 ;
T_2 V_367 ;
int V_106 ;
F_11 ( & V_13 -> V_368 ) ;
V_366 = F_278 ( & V_13 -> V_302 ) ;
if ( V_289 )
V_366 += V_35 ;
else
V_366 -= V_35 ;
F_279 ( & V_13 -> V_302 , V_366 ) ;
F_13 ( & V_13 -> V_368 ) ;
while ( V_365 ) {
V_2 = F_65 ( V_13 , V_26 ) ;
if ( ! V_2 )
return - 1 ;
if ( V_2 -> V_6 & ( V_254 |
V_255 |
V_256 ) )
V_106 = 2 ;
else
V_106 = 1 ;
if ( ! V_289 && V_2 -> V_3 == V_89 )
F_49 ( V_2 , V_85 , NULL , 1 ) ;
V_367 = V_26 - V_2 -> V_21 . V_22 ;
F_8 ( V_367 > V_2 -> V_21 . V_32 ) ;
F_11 ( & V_2 -> V_82 -> V_50 ) ;
F_11 ( & V_2 -> V_50 ) ;
if ( F_280 ( & V_13 -> V_302 ) != 0 &&
V_2 -> V_242 < V_248 )
V_2 -> V_242 = V_248 ;
V_2 -> V_249 = 1 ;
V_366 = F_76 ( & V_2 -> V_114 ) ;
V_35 = F_238 ( V_365 , V_2 -> V_21 . V_32 - V_367 ) ;
if ( V_289 ) {
V_366 += V_35 ;
F_281 ( & V_2 -> V_114 , V_366 ) ;
V_2 -> V_9 -= V_35 ;
V_2 -> V_82 -> V_263 -= V_35 ;
V_2 -> V_82 -> V_318 ++ ;
V_2 -> V_82 -> V_253 += V_35 ;
V_2 -> V_82 -> V_258 += V_35 * V_106 ;
F_13 ( & V_2 -> V_50 ) ;
F_13 ( & V_2 -> V_82 -> V_50 ) ;
} else {
V_366 -= V_35 ;
F_281 ( & V_2 -> V_114 , V_366 ) ;
V_2 -> V_8 += V_35 ;
V_2 -> V_82 -> V_262 += V_35 ;
V_2 -> V_82 -> V_253 -= V_35 ;
V_2 -> V_82 -> V_258 -= V_35 * V_106 ;
F_13 ( & V_2 -> V_50 ) ;
F_13 ( & V_2 -> V_82 -> V_50 ) ;
F_282 ( V_13 -> V_57 ,
V_26 , V_26 + V_35 - 1 ,
V_39 | V_369 ) ;
}
F_6 ( V_2 ) ;
V_365 -= V_35 ;
V_26 += V_35 ;
}
return 0 ;
}
static T_2 F_283 ( struct V_33 * V_34 , T_2 V_107 )
{
struct V_1 * V_2 ;
T_2 V_26 ;
V_2 = F_64 ( V_34 -> V_36 , V_107 ) ;
if ( ! V_2 )
return 0 ;
V_26 = V_2 -> V_21 . V_22 ;
F_6 ( V_2 ) ;
return V_26 ;
}
static int F_284 ( struct V_33 * V_34 ,
struct V_1 * V_2 ,
T_2 V_26 , T_2 V_35 , int V_9 )
{
F_11 ( & V_2 -> V_82 -> V_50 ) ;
F_11 ( & V_2 -> V_50 ) ;
V_2 -> V_8 += V_35 ;
V_2 -> V_82 -> V_262 += V_35 ;
if ( V_9 ) {
V_2 -> V_9 -= V_35 ;
V_2 -> V_82 -> V_263 -= V_35 ;
V_2 -> V_82 -> V_318 ++ ;
}
F_13 ( & V_2 -> V_50 ) ;
F_13 ( & V_2 -> V_82 -> V_50 ) ;
F_282 ( V_34 -> V_36 -> V_57 , V_26 ,
V_26 + V_35 - 1 , V_39 | V_369 ) ;
return 0 ;
}
int F_162 ( struct V_33 * V_34 ,
T_2 V_26 , T_2 V_35 , int V_9 )
{
struct V_1 * V_2 ;
V_2 = F_65 ( V_34 -> V_36 , V_26 ) ;
F_22 ( ! V_2 ) ;
F_284 ( V_34 , V_2 , V_26 , V_35 , V_9 ) ;
F_6 ( V_2 ) ;
return 0 ;
}
int F_285 ( struct V_1 * V_2 ,
T_2 V_35 , int V_370 , int V_296 )
{
int V_28 = 0 ;
if ( V_296 ) {
struct V_97 * V_82 = V_2 -> V_82 ;
F_11 ( & V_82 -> V_50 ) ;
F_11 ( & V_2 -> V_50 ) ;
if ( V_370 ) {
if ( V_2 -> V_115 ) {
V_28 = - V_176 ;
} else {
V_2 -> V_9 += V_35 ;
V_82 -> V_263 += V_35 ;
}
} else {
if ( V_2 -> V_115 )
V_82 -> V_264 += V_35 ;
V_2 -> V_9 -= V_35 ;
V_82 -> V_263 -= V_35 ;
V_82 -> V_318 ++ ;
}
F_13 ( & V_2 -> V_50 ) ;
F_13 ( & V_82 -> V_50 ) ;
} else {
F_11 ( & V_2 -> V_50 ) ;
if ( V_2 -> V_115 ) {
V_28 = - V_176 ;
} else {
if ( V_370 )
V_2 -> V_9 += V_35 ;
else
V_2 -> V_9 -= V_35 ;
}
F_13 ( & V_2 -> V_50 ) ;
}
return V_28 ;
}
int F_286 ( struct V_84 * V_85 ,
struct V_33 * V_34 )
{
struct V_12 * V_36 = V_34 -> V_36 ;
struct V_48 * V_214 ;
struct V_48 * V_52 ;
struct V_1 * V_2 ;
F_56 ( & V_36 -> V_76 ) ;
F_287 (caching_ctl, next,
&fs_info->caching_block_groups, list) {
V_2 = V_52 -> V_14 ;
if ( F_1 ( V_2 ) ) {
V_2 -> V_93 = ( T_2 ) - 1 ;
F_169 ( & V_52 -> V_94 ) ;
F_26 ( V_52 ) ;
} else {
V_2 -> V_93 = V_52 -> V_80 ;
}
}
if ( V_36 -> V_57 == & V_36 -> V_37 [ 0 ] )
V_36 -> V_57 = & V_36 -> V_37 [ 1 ] ;
else
V_36 -> V_57 = & V_36 -> V_37 [ 0 ] ;
F_58 ( & V_36 -> V_76 ) ;
F_258 ( V_36 ) ;
return 0 ;
}
static int F_288 ( struct V_33 * V_34 , T_2 V_31 , T_2 V_30 )
{
struct V_12 * V_36 = V_34 -> V_36 ;
struct V_1 * V_2 = NULL ;
T_2 V_116 ;
while ( V_31 <= V_30 ) {
if ( ! V_2 ||
V_31 >= V_2 -> V_21 . V_22 + V_2 -> V_21 . V_32 ) {
if ( V_2 )
F_6 ( V_2 ) ;
V_2 = F_65 ( V_36 , V_31 ) ;
F_22 ( ! V_2 ) ;
}
V_116 = V_2 -> V_21 . V_22 + V_2 -> V_21 . V_32 - V_31 ;
V_116 = F_238 ( V_116 , V_30 + 1 - V_31 ) ;
if ( V_31 < V_2 -> V_93 ) {
V_116 = F_238 ( V_116 , V_2 -> V_93 - V_31 ) ;
F_29 ( V_2 , V_31 , V_116 ) ;
}
V_31 += V_116 ;
F_11 ( & V_2 -> V_82 -> V_50 ) ;
F_11 ( & V_2 -> V_50 ) ;
V_2 -> V_8 -= V_116 ;
V_2 -> V_82 -> V_262 -= V_116 ;
if ( V_2 -> V_115 ) {
V_2 -> V_82 -> V_264 += V_116 ;
} else if ( V_2 -> V_10 > 0 ) {
V_116 = F_238 ( V_116 , V_2 -> V_10 ) ;
V_2 -> V_10 -= V_116 ;
V_2 -> V_82 -> V_263 += V_116 ;
}
F_13 ( & V_2 -> V_50 ) ;
F_13 ( & V_2 -> V_82 -> V_50 ) ;
}
if ( V_2 )
F_6 ( V_2 ) ;
return 0 ;
}
int F_289 ( struct V_84 * V_85 ,
struct V_33 * V_34 )
{
struct V_12 * V_36 = V_34 -> V_36 ;
struct V_371 * V_372 ;
struct V_309 * V_310 ;
struct V_309 * V_373 ;
T_2 V_31 ;
T_2 V_30 ;
int V_374 ;
int V_28 ;
if ( V_36 -> V_57 == & V_36 -> V_37 [ 0 ] )
V_372 = & V_36 -> V_37 [ 1 ] ;
else
V_372 = & V_36 -> V_37 [ 0 ] ;
while ( 1 ) {
V_28 = F_28 ( V_372 , 0 , & V_31 , & V_30 ,
V_58 ) ;
if ( V_28 )
break;
if ( F_290 ( V_34 , V_375 ) )
V_28 = F_144 ( V_34 , V_31 ,
V_30 + 1 - V_31 , NULL ) ;
F_291 ( V_372 , V_31 , V_30 , V_39 ) ;
F_288 ( V_34 , V_31 , V_30 ) ;
F_45 () ;
}
F_33 ( & V_36 -> V_334 ) ;
F_287 (block_rsv, next_rsv,
&fs_info->durable_block_rsv_list, list) {
V_374 = V_85 -> V_376 & 0x1 ;
if ( V_310 -> V_338 [ V_374 ] > 0 ) {
F_244 ( V_310 ,
V_310 -> V_338 [ V_374 ] , 0 ) ;
V_310 -> V_338 [ V_374 ] = 0 ;
}
if ( F_230 ( & V_310 -> V_331 ) == 0 ) {
F_250 ( V_34 , V_310 , ( T_2 ) - 1 ) ;
if ( V_310 -> V_338 [ 0 ] == 0 &&
V_310 -> V_338 [ 1 ] == 0 ) {
F_169 ( & V_310 -> V_94 ) ;
F_9 ( V_310 ) ;
}
} else {
F_250 ( V_34 , V_310 , 0 ) ;
}
}
F_44 ( & V_36 -> V_334 ) ;
return 0 ;
}
static int F_153 ( struct V_84 * V_85 ,
struct V_33 * V_34 ,
T_2 V_26 , T_2 V_35 , T_2 V_17 ,
T_2 V_147 , T_2 V_377 ,
T_2 V_378 , int V_160 ,
struct V_178 * V_132 )
{
struct V_65 V_21 ;
struct V_61 * V_62 ;
struct V_12 * V_13 = V_34 -> V_36 ;
struct V_33 * V_60 = V_13 -> V_60 ;
struct V_63 * V_64 ;
struct V_121 * V_122 ;
struct V_163 * V_164 ;
int V_28 ;
int V_182 ;
int V_379 = 0 ;
int V_380 = 0 ;
int V_381 = 1 ;
T_3 V_123 ;
T_2 V_117 ;
V_62 = F_31 () ;
if ( ! V_62 )
return - V_69 ;
V_62 -> V_72 = 1 ;
V_62 -> V_200 = 1 ;
V_182 = V_377 >= V_144 ;
F_22 ( ! V_182 && V_160 != 1 ) ;
V_28 = F_136 ( V_85 , V_60 , V_62 , & V_164 ,
V_26 , V_35 , V_17 ,
V_147 , V_377 ,
V_378 ) ;
if ( V_28 == 0 ) {
V_379 = V_62 -> V_79 [ 0 ] ;
while ( V_379 >= 0 ) {
F_38 ( V_62 -> V_78 [ 0 ] , & V_21 ,
V_379 ) ;
if ( V_21 . V_22 != V_26 )
break;
if ( V_21 . type == V_73 &&
V_21 . V_32 == V_35 ) {
V_380 = 1 ;
break;
}
if ( V_62 -> V_79 [ 0 ] - V_379 > 5 )
break;
V_379 -- ;
}
#ifdef F_84
V_123 = F_80 ( V_62 -> V_78 [ 0 ] , V_379 ) ;
if ( V_380 && V_123 < sizeof( * V_122 ) )
V_380 = 0 ;
#endif
if ( ! V_380 ) {
F_22 ( V_164 ) ;
V_28 = F_141 ( V_85 , V_60 , V_62 ,
NULL , V_160 ,
V_182 ) ;
F_22 ( V_28 ) ;
F_42 ( V_62 ) ;
V_62 -> V_200 = 1 ;
V_21 . V_22 = V_26 ;
V_21 . type = V_73 ;
V_21 . V_32 = V_35 ;
V_28 = F_35 ( V_85 , V_60 ,
& V_21 , V_62 , - 1 , 1 ) ;
if ( V_28 ) {
F_62 ( V_96 L_3
L_4 , V_28 ,
( unsigned long long ) V_26 ) ;
F_292 ( V_60 , V_62 -> V_78 [ 0 ] ) ;
}
F_22 ( V_28 ) ;
V_379 = V_62 -> V_79 [ 0 ] ;
}
} else {
F_292 ( V_60 , V_62 -> V_78 [ 0 ] ) ;
F_8 ( 1 ) ;
F_62 ( V_96 L_5
L_6 ,
( unsigned long long ) V_26 ,
( unsigned long long ) V_17 ,
( unsigned long long ) V_147 ,
( unsigned long long ) V_377 ,
( unsigned long long ) V_378 ) ;
}
V_64 = V_62 -> V_78 [ 0 ] ;
V_123 = F_80 ( V_64 , V_379 ) ;
#ifdef F_84
if ( V_123 < sizeof( * V_122 ) ) {
F_22 ( V_380 || V_379 != V_62 -> V_79 [ 0 ] ) ;
V_28 = F_89 ( V_85 , V_60 , V_62 ,
V_377 , 0 ) ;
F_22 ( V_28 < 0 ) ;
F_42 ( V_62 ) ;
V_62 -> V_200 = 1 ;
V_21 . V_22 = V_26 ;
V_21 . type = V_73 ;
V_21 . V_32 = V_35 ;
V_28 = F_35 ( V_85 , V_60 , & V_21 , V_62 ,
- 1 , 1 ) ;
if ( V_28 ) {
F_62 ( V_96 L_3
L_4 , V_28 ,
( unsigned long long ) V_26 ) ;
F_292 ( V_60 , V_62 -> V_78 [ 0 ] ) ;
}
F_22 ( V_28 ) ;
V_379 = V_62 -> V_79 [ 0 ] ;
V_64 = V_62 -> V_78 [ 0 ] ;
V_123 = F_80 ( V_64 , V_379 ) ;
}
#endif
F_22 ( V_123 < sizeof( * V_122 ) ) ;
V_122 = F_81 ( V_64 , V_379 ,
struct V_121 ) ;
if ( V_377 < V_144 ) {
struct V_139 * V_140 ;
F_22 ( V_123 < sizeof( * V_122 ) + sizeof( * V_140 ) ) ;
V_140 = (struct V_139 * ) ( V_122 + 1 ) ;
F_8 ( V_377 != F_293 ( V_64 , V_140 ) ) ;
}
V_117 = F_82 ( V_64 , V_122 ) ;
F_22 ( V_117 < V_160 ) ;
V_117 -= V_160 ;
if ( V_117 > 0 ) {
if ( V_132 )
F_132 ( V_132 , V_64 , V_122 ) ;
if ( V_164 ) {
F_22 ( ! V_380 ) ;
} else {
F_92 ( V_64 , V_122 , V_117 ) ;
F_97 ( V_64 ) ;
}
if ( V_380 ) {
V_28 = F_141 ( V_85 , V_60 , V_62 ,
V_164 , V_160 ,
V_182 ) ;
F_22 ( V_28 ) ;
}
} else {
if ( V_380 ) {
F_22 ( V_182 && V_160 !=
F_120 ( V_34 , V_62 , V_164 ) ) ;
if ( V_164 ) {
F_22 ( V_62 -> V_79 [ 0 ] != V_379 ) ;
} else {
F_22 ( V_62 -> V_79 [ 0 ] != V_379 + 1 ) ;
V_62 -> V_79 [ 0 ] = V_379 ;
V_381 = 2 ;
}
}
V_28 = F_294 ( V_85 , V_60 , V_62 , V_62 -> V_79 [ 0 ] ,
V_381 ) ;
F_22 ( V_28 ) ;
F_42 ( V_62 ) ;
if ( V_182 ) {
V_28 = F_163 ( V_85 , V_34 , V_26 , V_35 ) ;
F_22 ( V_28 ) ;
} else {
F_295 ( V_13 -> V_382 -> V_383 ,
V_26 >> V_315 ,
( V_26 + V_35 - 1 ) >> V_315 ) ;
}
V_28 = F_277 ( V_85 , V_34 , V_26 , V_35 , 0 ) ;
F_22 ( V_28 ) ;
}
F_47 ( V_62 ) ;
return V_28 ;
}
static T_1 int F_296 ( struct V_84 * V_85 ,
struct V_33 * V_34 , T_2 V_26 )
{
struct V_118 * V_99 ;
struct V_119 * V_120 ;
struct V_201 * V_152 ;
struct V_15 * V_131 ;
int V_28 = 0 ;
V_120 = & V_85 -> V_90 -> V_120 ;
F_11 ( & V_120 -> V_50 ) ;
V_99 = F_86 ( V_85 , V_26 ) ;
if ( ! V_99 )
goto V_130;
V_131 = F_181 ( & V_99 -> V_131 . V_15 ) ;
if ( ! V_131 )
goto V_130;
V_152 = F_12 ( V_131 , struct V_201 , V_15 ) ;
if ( V_152 -> V_26 == V_26 )
goto V_130;
if ( V_99 -> V_132 ) {
if ( ! V_99 -> V_213 )
goto V_130;
F_9 ( V_99 -> V_132 ) ;
V_99 -> V_132 = NULL ;
}
if ( ! F_87 ( & V_99 -> V_75 ) )
goto V_130;
V_99 -> V_131 . V_215 = 0 ;
F_170 ( & V_99 -> V_131 . V_15 , & V_120 -> V_34 ) ;
V_120 -> V_216 -- ;
V_120 -> V_384 -- ;
if ( F_165 ( & V_99 -> V_211 ) )
V_120 -> V_219 -- ;
F_169 ( & V_99 -> V_211 ) ;
F_13 ( & V_120 -> V_50 ) ;
F_22 ( V_99 -> V_132 ) ;
if ( V_99 -> V_213 )
V_28 = 1 ;
F_44 ( & V_99 -> V_75 ) ;
F_88 ( & V_99 -> V_131 ) ;
return V_28 ;
V_130:
F_13 ( & V_120 -> V_50 ) ;
return 0 ;
}
void F_297 ( struct V_84 * V_85 ,
struct V_33 * V_34 ,
struct V_63 * V_227 ,
T_2 V_17 , int V_385 )
{
struct V_309 * V_310 ;
struct V_1 * V_2 = NULL ;
int V_28 ;
if ( V_34 -> V_223 . V_22 != V_198 ) {
V_28 = F_147 ( V_85 , V_227 -> V_31 , V_227 -> V_116 ,
V_17 , V_34 -> V_223 . V_22 ,
F_189 ( V_227 ) ,
V_208 , NULL ) ;
F_22 ( V_28 ) ;
}
if ( ! V_385 )
return;
V_310 = F_242 ( V_85 , V_34 ) ;
V_2 = F_65 ( V_34 -> V_36 , V_227 -> V_31 ) ;
if ( V_310 -> V_82 != V_2 -> V_82 )
goto V_130;
if ( F_298 ( V_227 ) == V_85 -> V_376 ) {
if ( V_34 -> V_223 . V_22 != V_198 ) {
V_28 = F_296 ( V_85 , V_34 , V_227 -> V_31 ) ;
if ( ! V_28 )
goto V_386;
}
if ( F_299 ( V_227 , V_387 ) ) {
F_284 ( V_34 , V_2 , V_227 -> V_31 , V_227 -> V_116 , 1 ) ;
goto V_386;
}
F_8 ( F_300 ( V_388 , & V_227 -> V_389 ) ) ;
F_29 ( V_2 , V_227 -> V_31 , V_227 -> V_116 ) ;
V_28 = F_285 ( V_2 , V_227 -> V_116 , 0 , 0 ) ;
if ( V_28 == - V_176 ) {
F_285 ( V_2 , V_227 -> V_116 , 0 , 1 ) ;
goto V_130;
}
V_28 = 1 ;
F_11 ( & V_310 -> V_50 ) ;
if ( V_310 -> V_9 < V_310 -> V_55 ) {
V_310 -> V_9 += V_227 -> V_116 ;
V_28 = 0 ;
}
F_13 ( & V_310 -> V_50 ) ;
if ( V_28 ) {
F_11 ( & V_2 -> V_82 -> V_50 ) ;
V_2 -> V_82 -> V_263 -= V_227 -> V_116 ;
V_2 -> V_82 -> V_318 ++ ;
F_13 ( & V_2 -> V_82 -> V_50 ) ;
}
goto V_130;
}
V_386:
if ( V_310 -> V_333 && ! V_2 -> V_115 ) {
V_28 = 0 ;
F_11 ( & V_2 -> V_50 ) ;
if ( ! V_2 -> V_115 ) {
V_2 -> V_10 += V_227 -> V_116 ;
V_28 = 1 ;
}
F_13 ( & V_2 -> V_50 ) ;
if ( V_28 ) {
F_11 ( & V_310 -> V_50 ) ;
V_310 -> V_338 [ V_85 -> V_376 & 0x1 ] += V_227 -> V_116 ;
F_13 ( & V_310 -> V_50 ) ;
}
}
V_130:
F_301 ( V_390 , & V_227 -> V_389 ) ;
F_6 ( V_2 ) ;
}
int V_233 ( struct V_84 * V_85 ,
struct V_33 * V_34 ,
T_2 V_26 , T_2 V_35 , T_2 V_17 ,
T_2 V_147 , T_2 V_109 , T_2 V_32 )
{
int V_28 ;
if ( V_147 == V_198 ) {
F_8 ( V_109 >= V_144 ) ;
F_162 ( V_34 , V_26 , V_35 , 1 ) ;
V_28 = 0 ;
} else if ( V_109 < V_144 ) {
V_28 = F_147 ( V_85 , V_26 , V_35 ,
V_17 , V_147 , ( int ) V_109 ,
V_208 , NULL ) ;
F_22 ( V_28 ) ;
} else {
V_28 = F_148 ( V_85 , V_26 , V_35 ,
V_17 , V_147 , V_109 ,
V_32 , V_208 , NULL ) ;
F_22 ( V_28 ) ;
}
return V_28 ;
}
static T_2 F_302 ( struct V_33 * V_34 , T_2 V_391 )
{
T_2 V_392 = ( ( T_2 ) V_34 -> V_393 - 1 ) ;
T_2 V_28 = ( V_391 + V_392 ) & ~ V_392 ;
return V_28 ;
}
static T_1 int
F_303 ( struct V_1 * V_2 ,
T_2 V_35 )
{
struct V_48 * V_52 ;
F_304 ( V_81 ) ;
V_52 = F_25 ( V_2 ) ;
if ( ! V_52 )
return 0 ;
F_305 ( V_52 -> V_81 , F_1 ( V_2 ) ||
( V_2 -> V_11 -> V_394 >= V_35 ) ) ;
F_26 ( V_52 ) ;
return 0 ;
}
static T_1 int
F_306 ( struct V_1 * V_2 )
{
struct V_48 * V_52 ;
F_304 ( V_81 ) ;
V_52 = F_25 ( V_2 ) ;
if ( ! V_52 )
return 0 ;
F_305 ( V_52 -> V_81 , F_1 ( V_2 ) ) ;
F_26 ( V_52 ) ;
return 0 ;
}
static int F_307 ( struct V_1 * V_2 )
{
int V_395 ;
if ( V_2 -> V_6 & V_256 )
V_395 = 0 ;
else if ( V_2 -> V_6 & V_255 )
V_395 = 1 ;
else if ( V_2 -> V_6 & V_254 )
V_395 = 2 ;
else if ( V_2 -> V_6 & V_270 )
V_395 = 3 ;
else
V_395 = 4 ;
return V_395 ;
}
static T_1 int F_308 ( struct V_84 * V_85 ,
struct V_33 * V_396 ,
T_2 V_35 , T_2 V_397 ,
T_2 V_107 , T_2 V_398 ,
T_2 V_399 , struct V_65 * V_204 ,
T_2 V_59 )
{
int V_28 = 0 ;
struct V_33 * V_34 = V_396 -> V_36 -> V_60 ;
struct V_400 * V_401 = NULL ;
struct V_1 * V_14 = NULL ;
int V_402 = 2 * 1024 * 1024 ;
int V_403 = 0 ;
int V_404 = 0 ;
struct V_97 * V_82 ;
int V_405 = 0 ;
int V_406 = 0 ;
int V_395 = 0 ;
bool V_407 = false ;
bool V_408 = false ;
bool V_409 = false ;
bool V_410 = true ;
T_2 V_411 = 0 ;
T_2 V_412 = 0 ;
F_8 ( V_35 < V_34 -> V_286 ) ;
F_78 ( V_204 , V_73 ) ;
V_204 -> V_22 = 0 ;
V_204 -> V_32 = 0 ;
V_82 = F_66 ( V_34 -> V_36 , V_59 ) ;
if ( ! V_82 ) {
F_62 ( V_96 L_7 , V_59 ) ;
return - V_292 ;
}
if ( F_235 ( V_82 ) )
V_410 = false ;
if ( V_396 -> V_232 || V_397 )
V_403 = 1 ;
if ( V_59 & V_103 && V_410 ) {
V_401 = & V_34 -> V_36 -> V_413 ;
if ( ! F_290 ( V_34 , V_414 ) )
V_402 = 64 * 1024 ;
}
if ( ( V_59 & V_101 ) && V_410 &&
F_290 ( V_34 , V_414 ) ) {
V_401 = & V_34 -> V_36 -> V_415 ;
}
if ( V_401 ) {
F_11 ( & V_401 -> V_50 ) ;
if ( V_401 -> V_14 )
V_399 = V_401 -> V_416 ;
F_13 ( & V_401 -> V_50 ) ;
}
V_107 = F_75 ( V_107 , F_283 ( V_34 , 0 ) ) ;
V_107 = F_75 ( V_107 , V_399 ) ;
if ( ! V_401 )
V_402 = 0 ;
if ( V_107 == V_399 ) {
V_417:
V_14 = F_65 ( V_34 -> V_36 ,
V_107 ) ;
if ( V_14 && F_3 ( V_14 , V_59 ) &&
( V_14 -> V_3 != V_89 ||
V_107 == V_412 ) ) {
F_34 ( & V_82 -> V_261 ) ;
if ( F_165 ( & V_14 -> V_94 ) ||
V_14 -> V_115 ) {
F_6 ( V_14 ) ;
F_43 ( & V_82 -> V_261 ) ;
} else {
V_395 = F_307 ( V_14 ) ;
goto V_418;
}
} else if ( V_14 ) {
F_6 ( V_14 ) ;
}
}
V_419:
F_34 ( & V_82 -> V_261 ) ;
F_309 (block_group, &space_info->block_groups[index],
list) {
T_2 V_32 ;
int V_3 ;
F_4 ( V_14 ) ;
V_107 = V_14 -> V_21 . V_22 ;
if ( ! F_3 ( V_14 , V_59 ) ) {
T_2 V_420 = V_254 |
V_255 |
V_256 ;
if ( ( V_59 & V_420 ) && ! ( V_14 -> V_6 & V_420 ) )
goto V_406;
}
V_418:
if ( F_310 ( V_14 -> V_3 == V_89 ) ) {
T_2 V_421 ;
V_28 = F_49 ( V_14 , V_85 ,
V_396 , 1 ) ;
if ( V_14 -> V_3 == V_4 )
goto V_418;
V_421 = F_76 ( & V_14 -> V_114 ) ;
V_421 *= 100 ;
V_421 = F_210 ( V_421 ,
V_14 -> V_21 . V_32 ) ;
V_421 = 100 - V_421 ;
if ( V_421 > V_411 &&
F_274 ( ! V_14 -> V_115 ) ) {
V_412 = V_14 -> V_21 . V_22 ;
V_411 = V_421 ;
}
if ( V_406 > V_422 ||
( V_406 > V_423 &&
F_230 ( & V_82 -> V_83 ) < 2 ) ) {
V_28 = F_49 ( V_14 , V_85 ,
V_396 , 0 ) ;
F_22 ( V_28 ) ;
}
V_407 = true ;
if ( V_406 == V_423 )
goto V_406;
}
V_3 = F_1 ( V_14 ) ;
if ( F_310 ( ! V_3 ) )
V_407 = true ;
if ( F_310 ( V_14 -> V_115 ) )
goto V_406;
F_11 ( & V_14 -> V_11 -> V_424 ) ;
if ( V_3 &&
V_14 -> V_11 -> V_394 <
V_35 + V_397 ) {
F_13 ( & V_14 -> V_11 -> V_424 ) ;
goto V_406;
}
F_13 ( & V_14 -> V_11 -> V_424 ) ;
if ( V_401 && V_406 < V_425 ) {
F_11 ( & V_401 -> V_426 ) ;
if ( V_401 -> V_14 &&
( V_401 -> V_14 -> V_115 ||
! F_3 ( V_401 -> V_14 , V_59 ) ) ) {
V_32 = 0 ;
goto V_427;
}
V_32 = F_311 ( V_14 , V_401 ,
V_35 , V_107 ) ;
if ( V_32 ) {
F_13 ( & V_401 -> V_426 ) ;
goto V_428;
}
F_11 ( & V_401 -> V_50 ) ;
if ( ! V_405 && V_401 -> V_14 &&
V_401 -> V_14 != V_14 ) {
F_6 ( V_14 ) ;
V_14 = V_401 -> V_14 ;
F_4 ( V_14 ) ;
F_13 ( & V_401 -> V_50 ) ;
F_13 ( & V_401 -> V_426 ) ;
V_405 = 1 ;
V_107 = V_14 -> V_21 . V_22 ;
goto V_418;
}
F_13 ( & V_401 -> V_50 ) ;
V_427:
F_312 ( NULL , V_401 ) ;
V_405 = 0 ;
V_28 = F_313 ( V_85 , V_34 ,
V_14 , V_401 ,
V_32 , V_35 ,
V_402 + V_397 ) ;
if ( V_28 == 0 ) {
V_32 = F_311 ( V_14 ,
V_401 , V_35 ,
V_107 ) ;
if ( V_32 ) {
F_13 ( & V_401 -> V_426 ) ;
goto V_428;
}
} else if ( ! V_3 && V_406 > V_422
&& ! V_408 ) {
F_13 ( & V_401 -> V_426 ) ;
V_408 = true ;
F_303 ( V_14 ,
V_35 + V_402 + V_397 ) ;
goto V_418;
}
F_312 ( NULL , V_401 ) ;
F_13 ( & V_401 -> V_426 ) ;
goto V_406;
}
V_32 = F_314 ( V_14 , V_107 ,
V_35 , V_397 ) ;
if ( ! V_32 && ! V_409 && ! V_3 &&
V_406 > V_422 ) {
F_303 ( V_14 ,
V_35 + V_397 ) ;
V_409 = true ;
goto V_418;
} else if ( ! V_32 ) {
goto V_406;
}
V_428:
V_107 = F_302 ( V_34 , V_32 ) ;
if ( V_107 + V_35 >= V_398 ) {
F_29 ( V_14 , V_32 , V_35 ) ;
goto V_406;
}
if ( V_107 + V_35 >
V_14 -> V_21 . V_22 + V_14 -> V_21 . V_32 ) {
F_29 ( V_14 , V_32 , V_35 ) ;
goto V_406;
}
V_204 -> V_22 = V_107 ;
V_204 -> V_32 = V_35 ;
if ( V_32 < V_107 )
F_29 ( V_14 , V_32 ,
V_107 - V_32 ) ;
F_22 ( V_32 > V_107 ) ;
V_28 = F_285 ( V_14 , V_35 , 1 ,
( V_59 & V_101 ) ) ;
if ( V_28 == - V_176 ) {
F_29 ( V_14 , V_32 , V_35 ) ;
goto V_406;
}
V_204 -> V_22 = V_107 ;
V_204 -> V_32 = V_35 ;
if ( V_32 < V_107 )
F_29 ( V_14 , V_32 ,
V_107 - V_32 ) ;
F_22 ( V_32 > V_107 ) ;
F_6 ( V_14 ) ;
break;
V_406:
V_408 = false ;
V_409 = false ;
F_22 ( V_395 != F_307 ( V_14 ) ) ;
F_6 ( V_14 ) ;
}
F_43 ( & V_82 -> V_261 ) ;
if ( ! V_204 -> V_22 && ++ V_395 < V_259 )
goto V_419;
if ( ! V_204 -> V_22 && V_406 < V_425 ) {
V_395 = 0 ;
if ( V_406 == V_423 && V_407 ) {
V_407 = false ;
V_406 ++ ;
if ( ! V_411 &&
F_230 ( & V_82 -> V_83 ) )
goto V_419;
V_406 = V_429 ;
V_107 = V_412 ;
V_411 = 0 ;
goto V_417;
} else if ( V_406 == V_423 ) {
V_406 = V_429 ;
goto V_419;
}
V_406 ++ ;
if ( V_406 == V_430 ) {
if ( V_403 ) {
V_28 = F_228 ( V_85 , V_34 , V_35 +
2 * 1024 * 1024 , V_59 ,
V_301 ) ;
V_403 = 0 ;
if ( V_28 == 1 )
V_404 = 1 ;
} else if ( ! V_404 &&
V_82 -> V_266 ==
V_267 ) {
V_82 -> V_266 = V_301 ;
}
if ( ! V_404 )
V_406 = V_425 ;
}
if ( V_406 == V_425 ) {
V_397 = 0 ;
V_402 = 0 ;
}
goto V_419;
} else if ( ! V_204 -> V_22 ) {
V_28 = - V_292 ;
} else if ( V_204 -> V_22 ) {
V_28 = 0 ;
}
return V_28 ;
}
static void F_315 ( struct V_97 * V_13 , T_2 V_282 ,
int V_431 )
{
struct V_1 * V_2 ;
int V_395 = 0 ;
F_11 ( & V_13 -> V_50 ) ;
F_62 ( V_432 L_8 ,
( unsigned long long ) ( V_13 -> V_252 - V_13 -> V_253 -
V_13 -> V_262 - V_13 -> V_263 -
V_13 -> V_264 ) ,
( V_13 -> V_104 ) ? L_9 : L_10 ) ;
F_62 ( V_432 L_11
L_12 ,
( unsigned long long ) V_13 -> V_252 ,
( unsigned long long ) V_13 -> V_253 ,
( unsigned long long ) V_13 -> V_262 ,
( unsigned long long ) V_13 -> V_263 ,
( unsigned long long ) V_13 -> V_265 ,
( unsigned long long ) V_13 -> V_264 ) ;
F_13 ( & V_13 -> V_50 ) ;
if ( ! V_431 )
return;
F_34 ( & V_13 -> V_261 ) ;
V_74:
F_309 (cache, &info->block_groups[index], list) {
F_11 ( & V_2 -> V_50 ) ;
F_62 ( V_432 L_13
L_14 ,
( unsigned long long ) V_2 -> V_21 . V_22 ,
( unsigned long long ) V_2 -> V_21 . V_32 ,
( unsigned long long ) F_76 ( & V_2 -> V_114 ) ,
( unsigned long long ) V_2 -> V_8 ,
( unsigned long long ) V_2 -> V_9 ) ;
F_316 ( V_2 , V_282 ) ;
F_13 ( & V_2 -> V_50 ) ;
}
if ( ++ V_395 < V_259 )
goto V_74;
F_43 ( & V_13 -> V_261 ) ;
}
int F_317 ( struct V_84 * V_85 ,
struct V_33 * V_34 ,
T_2 V_35 , T_2 V_433 ,
T_2 V_397 , T_2 V_399 ,
T_2 V_398 , struct V_65 * V_204 ,
T_2 V_59 )
{
int V_28 ;
T_2 V_107 = 0 ;
V_59 = F_225 ( V_34 , V_59 ) ;
V_74:
if ( V_397 || V_34 -> V_232 )
V_28 = F_228 ( V_85 , V_34 -> V_36 -> V_60 ,
V_35 + 2 * 1024 * 1024 , V_59 ,
V_267 ) ;
F_8 ( V_35 < V_34 -> V_286 ) ;
V_28 = F_308 ( V_85 , V_34 , V_35 , V_397 ,
V_107 , V_398 , V_399 ,
V_204 , V_59 ) ;
if ( V_28 == - V_292 && V_35 > V_433 ) {
V_35 = V_35 >> 1 ;
V_35 = V_35 & ~ ( V_34 -> V_286 - 1 ) ;
V_35 = F_75 ( V_35 , V_433 ) ;
F_228 ( V_85 , V_34 -> V_36 -> V_60 ,
V_35 , V_59 , V_291 ) ;
goto V_74;
}
if ( V_28 == - V_292 && F_290 ( V_34 , V_434 ) ) {
struct V_97 * V_296 ;
V_296 = F_66 ( V_34 -> V_36 , V_59 ) ;
F_62 ( V_96 L_15
L_16 , ( unsigned long long ) V_59 ,
( unsigned long long ) V_35 ) ;
F_315 ( V_296 , V_35 , 1 ) ;
}
F_318 ( V_34 , V_204 -> V_22 , V_204 -> V_32 ) ;
return V_28 ;
}
int F_319 ( struct V_33 * V_34 , T_2 V_31 , T_2 V_116 )
{
struct V_1 * V_2 ;
int V_28 = 0 ;
V_2 = F_65 ( V_34 -> V_36 , V_31 ) ;
if ( ! V_2 ) {
F_62 ( V_96 L_17 ,
( unsigned long long ) V_31 ) ;
return - V_292 ;
}
if ( F_290 ( V_34 , V_375 ) )
V_28 = F_144 ( V_34 , V_31 , V_116 , NULL ) ;
F_29 ( V_2 , V_31 , V_116 ) ;
F_285 ( V_2 , V_116 , 0 , 1 ) ;
F_6 ( V_2 ) ;
F_320 ( V_34 , V_31 , V_116 ) ;
return V_28 ;
}
static int F_152 ( struct V_84 * V_85 ,
struct V_33 * V_34 ,
T_2 V_17 , T_2 V_147 ,
T_2 V_6 , T_2 V_109 , T_2 V_32 ,
struct V_65 * V_204 , int V_135 )
{
int V_28 ;
struct V_12 * V_36 = V_34 -> V_36 ;
struct V_121 * V_435 ;
struct V_163 * V_164 ;
struct V_61 * V_62 ;
struct V_63 * V_64 ;
int type ;
T_3 V_55 ;
if ( V_17 > 0 )
type = V_155 ;
else
type = V_156 ;
V_55 = sizeof( * V_435 ) + F_127 ( type ) ;
V_62 = F_31 () ;
if ( ! V_62 )
return - V_69 ;
V_62 -> V_200 = 1 ;
V_28 = F_108 ( V_85 , V_36 -> V_60 , V_62 ,
V_204 , V_55 ) ;
F_22 ( V_28 ) ;
V_64 = V_62 -> V_78 [ 0 ] ;
V_435 = F_81 ( V_64 , V_62 -> V_79 [ 0 ] ,
struct V_121 ) ;
F_92 ( V_64 , V_435 , V_135 ) ;
F_93 ( V_64 , V_435 , V_85 -> V_376 ) ;
F_94 ( V_64 , V_435 ,
V_6 | V_146 ) ;
V_164 = (struct V_163 * ) ( V_435 + 1 ) ;
F_134 ( V_64 , V_164 , type ) ;
if ( V_17 > 0 ) {
struct V_159 * V_152 ;
V_152 = (struct V_159 * ) ( V_164 + 1 ) ;
F_135 ( V_64 , V_164 , V_17 ) ;
F_109 ( V_64 , V_152 , V_135 ) ;
} else {
struct V_151 * V_152 ;
V_152 = (struct V_151 * ) ( & V_164 -> V_32 ) ;
F_111 ( V_64 , V_152 , V_147 ) ;
F_112 ( V_64 , V_152 , V_109 ) ;
F_113 ( V_64 , V_152 , V_32 ) ;
F_114 ( V_64 , V_152 , V_135 ) ;
}
F_97 ( V_62 -> V_78 [ 0 ] ) ;
F_47 ( V_62 ) ;
V_28 = F_277 ( V_85 , V_34 , V_204 -> V_22 , V_204 -> V_32 , 1 ) ;
if ( V_28 ) {
F_62 ( V_96 L_18
L_19 , ( unsigned long long ) V_204 -> V_22 ,
( unsigned long long ) V_204 -> V_32 ) ;
F_63 () ;
}
return V_28 ;
}
static int F_158 ( struct V_84 * V_85 ,
struct V_33 * V_34 ,
T_2 V_17 , T_2 V_147 ,
T_2 V_6 , struct V_436 * V_21 ,
int V_167 , struct V_65 * V_204 )
{
int V_28 ;
struct V_12 * V_36 = V_34 -> V_36 ;
struct V_121 * V_435 ;
struct V_139 * V_437 ;
struct V_163 * V_164 ;
struct V_61 * V_62 ;
struct V_63 * V_64 ;
T_3 V_55 = sizeof( * V_435 ) + sizeof( * V_437 ) + sizeof( * V_164 ) ;
V_62 = F_31 () ;
F_22 ( ! V_62 ) ;
V_62 -> V_200 = 1 ;
V_28 = F_108 ( V_85 , V_36 -> V_60 , V_62 ,
V_204 , V_55 ) ;
F_22 ( V_28 ) ;
V_64 = V_62 -> V_78 [ 0 ] ;
V_435 = F_81 ( V_64 , V_62 -> V_79 [ 0 ] ,
struct V_121 ) ;
F_92 ( V_64 , V_435 , 1 ) ;
F_93 ( V_64 , V_435 , V_85 -> V_376 ) ;
F_94 ( V_64 , V_435 ,
V_6 | V_145 ) ;
V_437 = (struct V_139 * ) ( V_435 + 1 ) ;
F_154 ( V_64 , V_437 , V_21 ) ;
F_96 ( V_64 , V_437 , V_167 ) ;
V_164 = (struct V_163 * ) ( V_437 + 1 ) ;
if ( V_17 > 0 ) {
F_22 ( ! ( V_6 & V_129 ) ) ;
F_134 ( V_64 , V_164 ,
V_165 ) ;
F_135 ( V_64 , V_164 , V_17 ) ;
} else {
F_134 ( V_64 , V_164 ,
V_166 ) ;
F_135 ( V_64 , V_164 , V_147 ) ;
}
F_97 ( V_64 ) ;
F_47 ( V_62 ) ;
V_28 = F_277 ( V_85 , V_34 , V_204 -> V_22 , V_204 -> V_32 , 1 ) ;
if ( V_28 ) {
F_62 ( V_96 L_18
L_19 , ( unsigned long long ) V_204 -> V_22 ,
( unsigned long long ) V_204 -> V_32 ) ;
F_63 () ;
}
return V_28 ;
}
int F_321 ( struct V_84 * V_85 ,
struct V_33 * V_34 ,
T_2 V_147 , T_2 V_109 ,
T_2 V_32 , struct V_65 * V_204 )
{
int V_28 ;
F_22 ( V_147 == V_198 ) ;
V_28 = F_148 ( V_85 , V_204 -> V_22 , V_204 -> V_32 ,
0 , V_147 , V_109 , V_32 ,
V_438 , NULL ) ;
return V_28 ;
}
int F_322 ( struct V_84 * V_85 ,
struct V_33 * V_34 ,
T_2 V_147 , T_2 V_109 , T_2 V_32 ,
struct V_65 * V_204 )
{
int V_28 ;
struct V_1 * V_14 ;
struct V_48 * V_52 ;
T_2 V_31 = V_204 -> V_22 ;
T_2 V_35 = V_204 -> V_32 ;
V_14 = F_65 ( V_34 -> V_36 , V_204 -> V_22 ) ;
F_49 ( V_14 , V_85 , NULL , 0 ) ;
V_52 = F_25 ( V_14 ) ;
if ( ! V_52 ) {
F_22 ( ! F_1 ( V_14 ) ) ;
V_28 = F_323 ( V_14 , V_31 , V_35 ) ;
F_22 ( V_28 ) ;
} else {
F_33 ( & V_52 -> V_75 ) ;
if ( V_31 >= V_52 -> V_80 ) {
V_28 = F_17 ( V_34 , V_31 , V_35 ) ;
F_22 ( V_28 ) ;
} else if ( V_31 + V_35 <= V_52 -> V_80 ) {
V_28 = F_323 ( V_14 ,
V_31 , V_35 ) ;
F_22 ( V_28 ) ;
} else {
V_35 = V_52 -> V_80 - V_31 ;
V_28 = F_323 ( V_14 ,
V_31 , V_35 ) ;
F_22 ( V_28 ) ;
V_31 = V_52 -> V_80 ;
V_35 = V_204 -> V_22 + V_204 -> V_32 -
V_52 -> V_80 ;
V_28 = F_17 ( V_34 , V_31 , V_35 ) ;
F_22 ( V_28 ) ;
}
F_44 ( & V_52 -> V_75 ) ;
F_26 ( V_52 ) ;
}
V_28 = F_285 ( V_14 , V_204 -> V_32 , 1 , 1 ) ;
F_22 ( V_28 ) ;
F_6 ( V_14 ) ;
V_28 = F_152 ( V_85 , V_34 , 0 , V_147 ,
0 , V_109 , V_32 , V_204 , 1 ) ;
return V_28 ;
}
struct V_63 * F_324 ( struct V_84 * V_85 ,
struct V_33 * V_34 ,
T_2 V_26 , T_3 V_439 ,
int V_167 )
{
struct V_63 * V_227 ;
V_227 = F_325 ( V_34 , V_26 , V_439 ) ;
if ( ! V_227 )
return F_326 ( - V_69 ) ;
F_327 ( V_227 , V_85 -> V_376 ) ;
F_328 ( V_227 , V_167 ) ;
F_329 ( V_227 ) ;
F_330 ( V_85 , V_34 , V_227 ) ;
F_331 ( V_227 ) ;
F_332 ( V_227 ) ;
if ( V_34 -> V_223 . V_22 == V_198 ) {
if ( V_34 -> V_440 % 2 == 0 )
F_282 ( & V_34 -> V_441 , V_227 -> V_31 ,
V_227 -> V_31 + V_227 -> V_116 - 1 , V_39 ) ;
else
F_333 ( & V_34 -> V_441 , V_227 -> V_31 ,
V_227 -> V_31 + V_227 -> V_116 - 1 , V_39 ) ;
} else {
F_282 ( & V_85 -> V_90 -> V_442 , V_227 -> V_31 ,
V_227 -> V_31 + V_227 -> V_116 - 1 , V_39 ) ;
}
V_85 -> V_443 ++ ;
return V_227 ;
}
static struct V_309 *
F_334 ( struct V_84 * V_85 ,
struct V_33 * V_34 , T_3 V_439 )
{
struct V_309 * V_310 ;
struct V_309 * V_342 = & V_34 -> V_36 -> V_343 ;
int V_28 ;
V_310 = F_242 ( V_85 , V_34 ) ;
if ( V_310 -> V_55 == 0 ) {
V_28 = F_241 ( V_85 , V_34 , V_310 ,
V_439 , 0 ) ;
if ( V_28 && V_310 != V_342 ) {
V_28 = F_243 ( V_342 , V_439 ) ;
if ( ! V_28 )
return V_342 ;
return F_326 ( V_28 ) ;
} else if ( V_28 ) {
return F_326 ( V_28 ) ;
}
return V_310 ;
}
V_28 = F_243 ( V_310 , V_439 ) ;
if ( ! V_28 )
return V_310 ;
if ( V_28 ) {
F_8 ( 1 ) ;
V_28 = F_241 ( V_85 , V_34 , V_310 , V_439 ,
0 ) ;
if ( ! V_28 ) {
F_11 ( & V_310 -> V_50 ) ;
V_310 -> V_55 += V_439 ;
F_13 ( & V_310 -> V_50 ) ;
return V_310 ;
} else if ( V_28 && V_310 != V_342 ) {
V_28 = F_243 ( V_342 , V_439 ) ;
if ( ! V_28 )
return V_342 ;
}
}
return F_326 ( - V_292 ) ;
}
static void F_335 ( struct V_309 * V_310 , T_3 V_439 )
{
F_244 ( V_310 , V_439 , 0 ) ;
F_245 ( V_310 , NULL , 0 ) ;
}
struct V_63 * F_336 ( struct V_84 * V_85 ,
struct V_33 * V_34 , T_3 V_439 ,
T_2 V_17 , T_2 V_147 ,
struct V_436 * V_21 , int V_167 ,
T_2 V_444 , T_2 V_397 )
{
struct V_65 V_204 ;
struct V_309 * V_310 ;
struct V_63 * V_227 ;
T_2 V_6 = 0 ;
int V_28 ;
V_310 = F_334 ( V_85 , V_34 , V_439 ) ;
if ( F_60 ( V_310 ) )
return F_337 ( V_310 ) ;
V_28 = F_317 ( V_85 , V_34 , V_439 , V_439 ,
V_397 , V_444 , ( T_2 ) - 1 , & V_204 , 0 ) ;
if ( V_28 ) {
F_335 ( V_310 , V_439 ) ;
return F_326 ( V_28 ) ;
}
V_227 = F_324 ( V_85 , V_34 , V_204 . V_22 ,
V_439 , V_167 ) ;
F_22 ( F_60 ( V_227 ) ) ;
if ( V_147 == V_445 ) {
if ( V_17 == 0 )
V_17 = V_204 . V_22 ;
V_6 |= V_129 ;
} else
F_22 ( V_17 > 0 ) ;
if ( V_147 != V_198 ) {
struct V_178 * V_132 ;
V_132 = F_178 ( sizeof( * V_132 ) , V_39 ) ;
F_22 ( ! V_132 ) ;
if ( V_21 )
memcpy ( & V_132 -> V_21 , V_21 , sizeof( V_132 -> V_21 ) ) ;
else
memset ( & V_132 -> V_21 , 0 , sizeof( V_132 -> V_21 ) ) ;
V_132 -> V_134 = V_6 ;
V_132 -> V_207 = 1 ;
V_132 -> V_133 = 1 ;
V_132 -> V_182 = 0 ;
V_28 = F_147 ( V_85 , V_204 . V_22 ,
V_204 . V_32 , V_17 , V_147 ,
V_167 , V_438 ,
V_132 ) ;
F_22 ( V_28 ) ;
}
return V_227 ;
}
static T_1 void F_338 ( struct V_84 * V_85 ,
struct V_33 * V_34 ,
struct V_446 * V_447 ,
struct V_61 * V_62 )
{
T_2 V_26 ;
T_2 V_244 ;
T_2 V_117 ;
T_2 V_6 ;
T_3 V_68 ;
T_3 V_439 ;
struct V_65 V_21 ;
struct V_63 * V_448 ;
int V_28 ;
int V_449 ;
int V_450 = 0 ;
if ( V_62 -> V_79 [ V_447 -> V_167 ] < V_447 -> V_451 ) {
V_447 -> V_452 = V_447 -> V_452 * 2 / 3 ;
V_447 -> V_452 = F_75 ( V_447 -> V_452 , 2 ) ;
} else {
V_447 -> V_452 = V_447 -> V_452 * 3 / 2 ;
V_447 -> V_452 = F_173 ( int , V_447 -> V_452 ,
F_339 ( V_34 ) ) ;
}
V_448 = V_62 -> V_78 [ V_447 -> V_167 ] ;
V_68 = F_36 ( V_448 ) ;
V_439 = F_196 ( V_34 , V_447 -> V_167 - 1 ) ;
for ( V_449 = V_62 -> V_79 [ V_447 -> V_167 ] ; V_449 < V_68 ; V_449 ++ ) {
if ( V_450 >= V_447 -> V_452 )
break;
F_45 () ;
V_26 = F_195 ( V_448 , V_449 ) ;
V_244 = F_340 ( V_448 , V_449 ) ;
if ( V_449 == V_62 -> V_79 [ V_447 -> V_167 ] )
goto V_72;
if ( V_447 -> V_453 == V_454 &&
V_244 <= V_34 -> V_223 . V_32 )
continue;
V_28 = F_79 ( V_85 , V_34 , V_26 , V_439 ,
& V_117 , & V_6 ) ;
F_22 ( V_28 ) ;
F_22 ( V_117 == 0 ) ;
if ( V_447 -> V_453 == V_455 ) {
if ( V_117 == 1 )
goto V_72;
if ( V_447 -> V_167 == 1 &&
( V_6 & V_129 ) )
continue;
if ( ! V_447 -> V_456 ||
V_244 <= V_34 -> V_223 . V_32 )
continue;
F_125 ( V_448 , & V_21 , V_449 ) ;
V_28 = F_341 ( & V_21 ,
& V_447 -> V_457 ) ;
if ( V_28 < 0 )
continue;
} else {
if ( V_447 -> V_167 == 1 &&
( V_6 & V_129 ) )
continue;
}
V_72:
V_28 = F_342 ( V_34 , V_26 , V_439 ,
V_244 ) ;
if ( V_28 )
break;
V_450 ++ ;
}
V_447 -> V_451 = V_449 ;
}
static T_1 int F_343 ( struct V_84 * V_85 ,
struct V_33 * V_34 ,
struct V_61 * V_62 ,
struct V_446 * V_447 , int V_458 )
{
int V_167 = V_447 -> V_167 ;
struct V_63 * V_448 = V_62 -> V_78 [ V_167 ] ;
T_2 V_459 = V_129 ;
int V_28 ;
if ( V_447 -> V_453 == V_454 &&
F_188 ( V_448 ) != V_34 -> V_223 . V_22 )
return 1 ;
if ( V_458 &&
( ( V_447 -> V_453 == V_455 && V_447 -> V_117 [ V_167 ] != 1 ) ||
( V_447 -> V_453 == V_454 && ! ( V_447 -> V_6 [ V_167 ] & V_459 ) ) ) ) {
F_22 ( ! V_62 -> V_460 [ V_167 ] ) ;
V_28 = F_79 ( V_85 , V_34 ,
V_448 -> V_31 , V_448 -> V_116 ,
& V_447 -> V_117 [ V_167 ] ,
& V_447 -> V_6 [ V_167 ] ) ;
F_22 ( V_28 ) ;
F_22 ( V_447 -> V_117 [ V_167 ] == 0 ) ;
}
if ( V_447 -> V_453 == V_455 ) {
if ( V_447 -> V_117 [ V_167 ] > 1 )
return 1 ;
if ( V_62 -> V_460 [ V_167 ] && ! V_447 -> V_173 ) {
F_344 ( V_448 ) ;
V_62 -> V_460 [ V_167 ] = 0 ;
}
return 0 ;
}
if ( ! ( V_447 -> V_6 [ V_167 ] & V_459 ) ) {
F_22 ( ! V_62 -> V_460 [ V_167 ] ) ;
V_28 = F_197 ( V_85 , V_34 , V_448 , 1 ) ;
F_22 ( V_28 ) ;
V_28 = F_198 ( V_85 , V_34 , V_448 , 0 ) ;
F_22 ( V_28 ) ;
V_28 = F_177 ( V_85 , V_34 , V_448 -> V_31 ,
V_448 -> V_116 , V_459 , 0 ) ;
F_22 ( V_28 ) ;
V_447 -> V_6 [ V_167 ] |= V_459 ;
}
if ( V_62 -> V_460 [ V_167 ] && V_167 > 0 ) {
F_344 ( V_448 ) ;
V_62 -> V_460 [ V_167 ] = 0 ;
}
return 0 ;
}
static T_1 int F_345 ( struct V_84 * V_85 ,
struct V_33 * V_34 ,
struct V_61 * V_62 ,
struct V_446 * V_447 , int * V_458 )
{
T_2 V_26 ;
T_2 V_244 ;
T_2 V_17 ;
T_3 V_439 ;
struct V_65 V_21 ;
struct V_63 * V_214 ;
int V_167 = V_447 -> V_167 ;
int V_72 = 0 ;
int V_28 = 0 ;
V_244 = F_340 ( V_62 -> V_78 [ V_167 ] ,
V_62 -> V_79 [ V_167 ] ) ;
if ( V_447 -> V_453 == V_454 &&
V_244 <= V_34 -> V_223 . V_32 ) {
* V_458 = 1 ;
return 1 ;
}
V_26 = F_195 ( V_62 -> V_78 [ V_167 ] , V_62 -> V_79 [ V_167 ] ) ;
V_439 = F_196 ( V_34 , V_167 - 1 ) ;
V_214 = F_346 ( V_34 , V_26 , V_439 ) ;
if ( ! V_214 ) {
V_214 = F_325 ( V_34 , V_26 , V_439 ) ;
if ( ! V_214 )
return - V_69 ;
V_72 = 1 ;
}
F_329 ( V_214 ) ;
F_331 ( V_214 ) ;
V_28 = F_79 ( V_85 , V_34 , V_26 , V_439 ,
& V_447 -> V_117 [ V_167 - 1 ] ,
& V_447 -> V_6 [ V_167 - 1 ] ) ;
F_22 ( V_28 ) ;
F_22 ( V_447 -> V_117 [ V_167 - 1 ] == 0 ) ;
* V_458 = 0 ;
if ( V_447 -> V_453 == V_455 ) {
if ( V_447 -> V_117 [ V_167 - 1 ] > 1 ) {
if ( V_167 == 1 &&
( V_447 -> V_6 [ 0 ] & V_129 ) )
goto V_461;
if ( ! V_447 -> V_456 ||
V_244 <= V_34 -> V_223 . V_32 )
goto V_461;
F_125 ( V_62 -> V_78 [ V_167 ] , & V_21 ,
V_62 -> V_79 [ V_167 ] ) ;
V_28 = F_341 ( & V_21 , & V_447 -> V_457 ) ;
if ( V_28 < 0 )
goto V_461;
V_447 -> V_453 = V_454 ;
V_447 -> V_462 = V_167 - 1 ;
}
} else {
if ( V_167 == 1 &&
( V_447 -> V_6 [ 0 ] & V_129 ) )
goto V_461;
}
if ( ! F_347 ( V_214 , V_244 ) ) {
F_344 ( V_214 ) ;
F_348 ( V_214 ) ;
V_214 = NULL ;
* V_458 = 1 ;
}
if ( ! V_214 ) {
if ( V_72 && V_167 == 1 )
F_338 ( V_85 , V_34 , V_447 , V_62 ) ;
V_214 = F_349 ( V_34 , V_26 , V_439 , V_244 ) ;
if ( ! V_214 )
return - V_209 ;
F_329 ( V_214 ) ;
F_331 ( V_214 ) ;
}
V_167 -- ;
F_22 ( V_167 != F_189 ( V_214 ) ) ;
V_62 -> V_78 [ V_167 ] = V_214 ;
V_62 -> V_79 [ V_167 ] = 0 ;
V_62 -> V_460 [ V_167 ] = 1 ;
V_447 -> V_167 = V_167 ;
if ( V_447 -> V_167 == 1 )
V_447 -> V_451 = 0 ;
return 0 ;
V_461:
V_447 -> V_117 [ V_167 - 1 ] = 0 ;
V_447 -> V_6 [ V_167 - 1 ] = 0 ;
if ( V_447 -> V_453 == V_455 ) {
if ( V_447 -> V_6 [ V_167 ] & V_129 ) {
V_17 = V_62 -> V_78 [ V_167 ] -> V_31 ;
} else {
F_22 ( V_34 -> V_223 . V_22 !=
F_188 ( V_62 -> V_78 [ V_167 ] ) ) ;
V_17 = 0 ;
}
V_28 = V_233 ( V_85 , V_34 , V_26 , V_439 , V_17 ,
V_34 -> V_223 . V_22 , V_167 - 1 , 0 ) ;
F_22 ( V_28 ) ;
}
F_344 ( V_214 ) ;
F_348 ( V_214 ) ;
* V_458 = 1 ;
return 1 ;
}
static T_1 int F_350 ( struct V_84 * V_85 ,
struct V_33 * V_34 ,
struct V_61 * V_62 ,
struct V_446 * V_447 )
{
int V_28 ;
int V_167 = V_447 -> V_167 ;
struct V_63 * V_448 = V_62 -> V_78 [ V_167 ] ;
T_2 V_17 = 0 ;
if ( V_447 -> V_453 == V_454 ) {
F_22 ( V_447 -> V_462 < V_167 ) ;
if ( V_167 < V_447 -> V_462 )
goto V_130;
V_28 = F_39 ( V_62 , V_167 + 1 , & V_447 -> V_457 ) ;
if ( V_28 > 0 )
V_447 -> V_456 = 0 ;
V_447 -> V_453 = V_455 ;
V_447 -> V_462 = - 1 ;
V_62 -> V_79 [ V_167 ] = 0 ;
if ( ! V_62 -> V_460 [ V_167 ] ) {
F_22 ( V_167 == 0 ) ;
F_329 ( V_448 ) ;
F_331 ( V_448 ) ;
V_62 -> V_460 [ V_167 ] = 1 ;
V_28 = F_79 ( V_85 , V_34 ,
V_448 -> V_31 , V_448 -> V_116 ,
& V_447 -> V_117 [ V_167 ] ,
& V_447 -> V_6 [ V_167 ] ) ;
F_22 ( V_28 ) ;
F_22 ( V_447 -> V_117 [ V_167 ] == 0 ) ;
if ( V_447 -> V_117 [ V_167 ] == 1 ) {
F_344 ( V_448 ) ;
V_62 -> V_460 [ V_167 ] = 0 ;
return 1 ;
}
}
}
F_22 ( V_447 -> V_117 [ V_167 ] > 1 && ! V_62 -> V_460 [ V_167 ] ) ;
if ( V_447 -> V_117 [ V_167 ] == 1 ) {
if ( V_167 == 0 ) {
if ( V_447 -> V_6 [ V_167 ] & V_129 )
V_28 = F_198 ( V_85 , V_34 , V_448 , 1 ) ;
else
V_28 = F_198 ( V_85 , V_34 , V_448 , 0 ) ;
F_22 ( V_28 ) ;
}
if ( ! V_62 -> V_460 [ V_167 ] &&
F_298 ( V_448 ) == V_85 -> V_376 ) {
F_329 ( V_448 ) ;
F_331 ( V_448 ) ;
V_62 -> V_460 [ V_167 ] = 1 ;
}
F_330 ( V_85 , V_34 , V_448 ) ;
}
if ( V_448 == V_34 -> V_131 ) {
if ( V_447 -> V_6 [ V_167 ] & V_129 )
V_17 = V_448 -> V_31 ;
else
F_22 ( V_34 -> V_223 . V_22 !=
F_188 ( V_448 ) ) ;
} else {
if ( V_447 -> V_6 [ V_167 + 1 ] & V_129 )
V_17 = V_62 -> V_78 [ V_167 + 1 ] -> V_31 ;
else
F_22 ( V_34 -> V_223 . V_22 !=
F_188 ( V_62 -> V_78 [ V_167 + 1 ] ) ) ;
}
F_297 ( V_85 , V_34 , V_448 , V_17 , V_447 -> V_117 [ V_167 ] == 1 ) ;
V_130:
V_447 -> V_117 [ V_167 ] = 0 ;
V_447 -> V_6 [ V_167 ] = 0 ;
return 0 ;
}
static T_1 int F_351 ( struct V_84 * V_85 ,
struct V_33 * V_34 ,
struct V_61 * V_62 ,
struct V_446 * V_447 )
{
int V_167 = V_447 -> V_167 ;
int V_458 = 1 ;
int V_28 ;
while ( V_167 >= 0 ) {
V_28 = F_343 ( V_85 , V_34 , V_62 , V_447 , V_458 ) ;
if ( V_28 > 0 )
break;
if ( V_167 == 0 )
break;
if ( V_62 -> V_79 [ V_167 ] >=
F_36 ( V_62 -> V_78 [ V_167 ] ) )
break;
V_28 = F_345 ( V_85 , V_34 , V_62 , V_447 , & V_458 ) ;
if ( V_28 > 0 ) {
V_62 -> V_79 [ V_167 ] ++ ;
continue;
} else if ( V_28 < 0 )
return V_28 ;
V_167 = V_447 -> V_167 ;
}
return 0 ;
}
static T_1 int F_352 ( struct V_84 * V_85 ,
struct V_33 * V_34 ,
struct V_61 * V_62 ,
struct V_446 * V_447 , int V_463 )
{
int V_167 = V_447 -> V_167 ;
int V_28 ;
V_62 -> V_79 [ V_167 ] = F_36 ( V_62 -> V_78 [ V_167 ] ) ;
while ( V_167 < V_463 && V_62 -> V_78 [ V_167 ] ) {
V_447 -> V_167 = V_167 ;
if ( V_62 -> V_79 [ V_167 ] + 1 <
F_36 ( V_62 -> V_78 [ V_167 ] ) ) {
V_62 -> V_79 [ V_167 ] ++ ;
return 0 ;
} else {
V_28 = F_350 ( V_85 , V_34 , V_62 , V_447 ) ;
if ( V_28 > 0 )
return 0 ;
if ( V_62 -> V_460 [ V_167 ] ) {
F_344 ( V_62 -> V_78 [ V_167 ] ) ;
V_62 -> V_460 [ V_167 ] = 0 ;
}
F_348 ( V_62 -> V_78 [ V_167 ] ) ;
V_62 -> V_78 [ V_167 ] = NULL ;
V_167 ++ ;
}
}
return 1 ;
}
int F_353 ( struct V_33 * V_34 ,
struct V_309 * V_310 , int V_456 )
{
struct V_61 * V_62 ;
struct V_84 * V_85 ;
struct V_33 * V_92 = V_34 -> V_36 -> V_92 ;
struct V_464 * V_224 = & V_34 -> V_224 ;
struct V_446 * V_447 ;
struct V_65 V_21 ;
int V_77 = 0 ;
int V_28 ;
int V_167 ;
V_62 = F_31 () ;
F_22 ( ! V_62 ) ;
V_447 = F_51 ( sizeof( * V_447 ) , V_39 ) ;
F_22 ( ! V_447 ) ;
V_85 = F_354 ( V_92 , 0 ) ;
F_22 ( F_60 ( V_85 ) ) ;
if ( V_310 )
V_85 -> V_310 = V_310 ;
if ( F_355 ( & V_224 -> V_465 ) == 0 ) {
V_167 = F_189 ( V_34 -> V_131 ) ;
V_62 -> V_78 [ V_167 ] = F_356 ( V_34 ) ;
F_331 ( V_62 -> V_78 [ V_167 ] ) ;
V_62 -> V_79 [ V_167 ] = 0 ;
V_62 -> V_460 [ V_167 ] = 1 ;
memset ( & V_447 -> V_457 , 0 ,
sizeof( V_447 -> V_457 ) ) ;
} else {
F_357 ( & V_21 , & V_224 -> V_465 ) ;
memcpy ( & V_447 -> V_457 , & V_21 ,
sizeof( V_447 -> V_457 ) ) ;
V_167 = V_224 -> V_466 ;
F_22 ( V_167 == 0 ) ;
V_62 -> V_467 = V_167 ;
V_28 = F_35 ( NULL , V_34 , & V_21 , V_62 , 0 , 0 ) ;
V_62 -> V_467 = 0 ;
if ( V_28 < 0 ) {
V_77 = V_28 ;
goto V_130;
}
F_8 ( V_28 > 0 ) ;
F_130 ( V_62 , 0 ) ;
V_167 = F_189 ( V_34 -> V_131 ) ;
while ( 1 ) {
F_329 ( V_62 -> V_78 [ V_167 ] ) ;
F_331 ( V_62 -> V_78 [ V_167 ] ) ;
V_28 = F_79 ( V_85 , V_34 ,
V_62 -> V_78 [ V_167 ] -> V_31 ,
V_62 -> V_78 [ V_167 ] -> V_116 ,
& V_447 -> V_117 [ V_167 ] ,
& V_447 -> V_6 [ V_167 ] ) ;
F_22 ( V_28 ) ;
F_22 ( V_447 -> V_117 [ V_167 ] == 0 ) ;
if ( V_167 == V_224 -> V_466 )
break;
F_344 ( V_62 -> V_78 [ V_167 ] ) ;
F_8 ( V_447 -> V_117 [ V_167 ] != 1 ) ;
V_167 -- ;
}
}
V_447 -> V_167 = V_167 ;
V_447 -> V_462 = - 1 ;
V_447 -> V_453 = V_455 ;
V_447 -> V_456 = V_456 ;
V_447 -> V_173 = 0 ;
V_447 -> V_452 = F_339 ( V_34 ) ;
while ( 1 ) {
V_28 = F_351 ( V_85 , V_34 , V_62 , V_447 ) ;
if ( V_28 < 0 ) {
V_77 = V_28 ;
break;
}
V_28 = F_352 ( V_85 , V_34 , V_62 , V_447 , V_168 ) ;
if ( V_28 < 0 ) {
V_77 = V_28 ;
break;
}
if ( V_28 > 0 ) {
F_22 ( V_447 -> V_453 != V_455 ) ;
break;
}
if ( V_447 -> V_453 == V_455 ) {
V_167 = V_447 -> V_167 ;
F_358 ( V_62 -> V_78 [ V_167 ] ,
& V_224 -> V_465 ,
V_62 -> V_79 [ V_167 ] ) ;
V_224 -> V_466 = V_167 ;
}
F_22 ( V_447 -> V_167 == 0 ) ;
if ( F_359 ( V_85 , V_92 ) ) {
V_28 = F_360 ( V_85 , V_92 ,
& V_34 -> V_223 ,
V_224 ) ;
F_22 ( V_28 ) ;
F_361 ( V_85 , V_92 ) ;
V_85 = F_354 ( V_92 , 0 ) ;
F_22 ( F_60 ( V_85 ) ) ;
if ( V_310 )
V_85 -> V_310 = V_310 ;
}
}
F_42 ( V_62 ) ;
F_22 ( V_77 ) ;
V_28 = F_362 ( V_85 , V_92 , & V_34 -> V_223 ) ;
F_22 ( V_28 ) ;
if ( V_34 -> V_223 . V_22 != V_445 ) {
V_28 = F_363 ( V_92 , V_34 -> V_223 . V_22 ,
NULL , NULL ) ;
F_22 ( V_28 < 0 ) ;
if ( V_28 > 0 ) {
F_364 ( V_85 , V_92 ,
V_34 -> V_223 . V_22 ) ;
}
}
if ( V_34 -> V_468 ) {
F_365 ( V_92 -> V_36 , V_34 ) ;
} else {
F_348 ( V_34 -> V_131 ) ;
F_348 ( V_34 -> V_469 ) ;
F_9 ( V_34 ) ;
}
V_130:
F_361 ( V_85 , V_92 ) ;
F_9 ( V_447 ) ;
F_47 ( V_62 ) ;
return V_77 ;
}
int F_366 ( struct V_84 * V_85 ,
struct V_33 * V_34 ,
struct V_63 * V_131 ,
struct V_63 * V_17 )
{
struct V_61 * V_62 ;
struct V_446 * V_447 ;
int V_167 ;
int V_470 ;
int V_28 = 0 ;
int V_471 ;
F_22 ( V_34 -> V_223 . V_22 != V_445 ) ;
V_62 = F_31 () ;
if ( ! V_62 )
return - V_69 ;
V_447 = F_51 ( sizeof( * V_447 ) , V_39 ) ;
if ( ! V_447 ) {
F_47 ( V_62 ) ;
return - V_69 ;
}
F_367 ( V_17 ) ;
V_470 = F_189 ( V_17 ) ;
F_368 ( V_17 ) ;
V_62 -> V_78 [ V_470 ] = V_17 ;
V_62 -> V_79 [ V_470 ] = F_36 ( V_17 ) ;
F_367 ( V_131 ) ;
V_167 = F_189 ( V_131 ) ;
V_62 -> V_78 [ V_167 ] = V_131 ;
V_62 -> V_79 [ V_167 ] = 0 ;
V_62 -> V_460 [ V_167 ] = 1 ;
V_447 -> V_117 [ V_470 ] = 1 ;
V_447 -> V_6 [ V_470 ] = V_129 ;
V_447 -> V_167 = V_167 ;
V_447 -> V_462 = - 1 ;
V_447 -> V_453 = V_455 ;
V_447 -> V_456 = 0 ;
V_447 -> V_173 = 1 ;
V_447 -> V_452 = F_339 ( V_34 ) ;
while ( 1 ) {
V_471 = F_351 ( V_85 , V_34 , V_62 , V_447 ) ;
if ( V_471 < 0 ) {
V_28 = V_471 ;
break;
}
V_471 = F_352 ( V_85 , V_34 , V_62 , V_447 , V_470 ) ;
if ( V_471 < 0 )
V_28 = V_471 ;
if ( V_471 != 0 )
break;
}
F_9 ( V_447 ) ;
F_47 ( V_62 ) ;
return V_28 ;
}
static T_2 F_369 ( struct V_33 * V_34 , T_2 V_6 )
{
T_2 V_274 ;
T_2 V_472 = V_270 |
V_255 | V_256 ;
V_274 = V_34 -> V_36 -> V_275 -> V_276 +
V_34 -> V_36 -> V_275 -> V_277 ;
if ( V_274 == 1 ) {
V_472 |= V_254 ;
V_472 = V_6 & ~ V_472 ;
if ( V_6 & V_270 )
return V_472 ;
if ( V_6 & ( V_255 |
V_256 ) )
return V_472 | V_254 ;
return V_6 ;
} else {
if ( V_6 & V_472 )
return V_6 ;
V_472 |= V_254 ;
V_472 = V_6 & ~ V_472 ;
if ( V_6 & V_254 )
return V_472 | V_255 ;
return V_472 | V_270 ;
}
return V_6 ;
}
static int F_370 ( struct V_1 * V_2 )
{
struct V_97 * V_296 = V_2 -> V_82 ;
T_2 V_35 ;
int V_28 = - V_292 ;
if ( V_2 -> V_115 )
return 0 ;
F_11 ( & V_296 -> V_50 ) ;
F_11 ( & V_2 -> V_50 ) ;
V_35 = V_2 -> V_21 . V_32 - V_2 -> V_9 - V_2 -> V_8 -
V_2 -> V_45 - F_76 ( & V_2 -> V_114 ) ;
if ( V_296 -> V_253 + V_296 -> V_263 + V_296 -> V_262 +
V_296 -> V_265 + V_296 -> V_264 +
V_2 -> V_10 + V_35 <= V_296 -> V_252 ) {
V_296 -> V_264 += V_35 ;
V_296 -> V_263 += V_2 -> V_10 ;
V_2 -> V_10 = 0 ;
V_2 -> V_115 = 1 ;
V_28 = 0 ;
}
F_13 ( & V_2 -> V_50 ) ;
F_13 ( & V_296 -> V_50 ) ;
return V_28 ;
}
int F_371 ( struct V_33 * V_34 ,
struct V_1 * V_2 )
{
struct V_84 * V_85 ;
T_2 V_473 ;
int V_28 ;
F_22 ( V_2 -> V_115 ) ;
V_85 = F_227 ( V_34 ) ;
F_22 ( F_60 ( V_85 ) ) ;
V_473 = F_369 ( V_34 , V_2 -> V_6 ) ;
if ( V_473 != V_2 -> V_6 )
F_228 ( V_85 , V_34 , 2 * 1024 * 1024 , V_473 ,
V_291 ) ;
V_28 = F_370 ( V_2 ) ;
if ( ! V_28 )
goto V_130;
V_473 = F_224 ( V_34 , V_2 -> V_82 -> V_6 ) ;
V_28 = F_228 ( V_85 , V_34 , 2 * 1024 * 1024 , V_473 ,
V_291 ) ;
if ( V_28 < 0 )
goto V_130;
V_28 = F_370 ( V_2 ) ;
V_130:
F_229 ( V_85 , V_34 ) ;
return V_28 ;
}
int F_372 ( struct V_84 * V_85 ,
struct V_33 * V_34 , T_2 type )
{
T_2 V_473 = F_224 ( V_34 , type ) ;
return F_228 ( V_85 , V_34 , 2 * 1024 * 1024 , V_473 ,
V_291 ) ;
}
static T_2 F_373 ( struct V_98 * V_474 )
{
struct V_1 * V_14 ;
T_2 V_475 = 0 ;
int V_106 ;
F_309 (block_group, groups_list, list) {
F_11 ( & V_14 -> V_50 ) ;
if ( ! V_14 -> V_115 ) {
F_13 ( & V_14 -> V_50 ) ;
continue;
}
if ( V_14 -> V_6 & ( V_255 |
V_256 |
V_254 ) )
V_106 = 2 ;
else
V_106 = 1 ;
V_475 += ( V_14 -> V_21 . V_32 -
F_76 ( & V_14 -> V_114 ) ) *
V_106 ;
F_13 ( & V_14 -> V_50 ) ;
}
return V_475 ;
}
T_2 F_374 ( struct V_97 * V_296 )
{
int V_42 ;
T_2 V_475 = 0 ;
F_11 ( & V_296 -> V_50 ) ;
for( V_42 = 0 ; V_42 < V_259 ; V_42 ++ )
if ( ! F_165 ( & V_296 -> V_260 [ V_42 ] ) )
V_475 += F_373 (
& V_296 -> V_260 [ V_42 ] ) ;
F_13 ( & V_296 -> V_50 ) ;
return V_475 ;
}
int F_375 ( struct V_33 * V_34 ,
struct V_1 * V_2 )
{
struct V_97 * V_296 = V_2 -> V_82 ;
T_2 V_35 ;
F_22 ( ! V_2 -> V_115 ) ;
F_11 ( & V_296 -> V_50 ) ;
F_11 ( & V_2 -> V_50 ) ;
V_35 = V_2 -> V_21 . V_32 - V_2 -> V_9 - V_2 -> V_8 -
V_2 -> V_45 - F_76 ( & V_2 -> V_114 ) ;
V_296 -> V_264 -= V_35 ;
V_2 -> V_115 = 0 ;
F_13 ( & V_2 -> V_50 ) ;
F_13 ( & V_296 -> V_50 ) ;
return 0 ;
}
int F_376 ( struct V_33 * V_34 , T_2 V_26 )
{
struct V_1 * V_14 ;
struct V_97 * V_82 ;
struct V_476 * V_275 = V_34 -> V_36 -> V_275 ;
struct V_477 * V_478 ;
int V_104 = 0 ;
int V_28 = 0 ;
V_14 = F_65 ( V_34 -> V_36 , V_26 ) ;
if ( ! V_14 )
return - 1 ;
if ( ! F_76 ( & V_14 -> V_114 ) )
goto V_130;
V_82 = V_14 -> V_82 ;
F_11 ( & V_82 -> V_50 ) ;
V_104 = V_82 -> V_104 ;
if ( ( V_82 -> V_252 != V_14 -> V_21 . V_32 ) &&
( V_82 -> V_253 + V_82 -> V_263 +
V_82 -> V_262 + V_82 -> V_264 +
F_76 ( & V_14 -> V_114 ) <
V_82 -> V_252 ) ) {
F_13 ( & V_82 -> V_50 ) ;
goto V_130;
}
F_13 ( & V_82 -> V_50 ) ;
V_28 = - 1 ;
if ( V_104 )
goto V_130;
F_33 ( & V_34 -> V_36 -> V_304 ) ;
F_309 (device, &fs_devices->alloc_list, dev_alloc_list) {
T_2 V_479 = F_76 ( & V_14 -> V_114 ) ;
T_2 V_480 ;
if ( V_478 -> V_252 > V_478 -> V_253 + V_479 ) {
V_28 = F_377 ( NULL , V_478 , V_479 ,
& V_480 , NULL ) ;
if ( ! V_28 )
break;
V_28 = - 1 ;
}
}
F_44 ( & V_34 -> V_36 -> V_304 ) ;
V_130:
F_6 ( V_14 ) ;
return V_28 ;
}
static int F_378 ( struct V_33 * V_34 ,
struct V_61 * V_62 , struct V_65 * V_21 )
{
int V_28 = 0 ;
struct V_65 V_141 ;
struct V_63 * V_64 ;
int V_449 ;
V_28 = F_35 ( NULL , V_34 , V_21 , V_62 , 0 , 0 ) ;
if ( V_28 < 0 )
goto V_130;
while ( 1 ) {
V_449 = V_62 -> V_79 [ 0 ] ;
V_64 = V_62 -> V_78 [ 0 ] ;
if ( V_449 >= F_36 ( V_64 ) ) {
V_28 = F_41 ( V_34 , V_62 ) ;
if ( V_28 == 0 )
continue;
if ( V_28 < 0 )
goto V_130;
break;
}
F_38 ( V_64 , & V_141 , V_449 ) ;
if ( V_141 . V_22 >= V_21 -> V_22 &&
V_141 . type == V_177 ) {
V_28 = 0 ;
goto V_130;
}
V_62 -> V_79 [ 0 ] ++ ;
}
V_130:
return V_28 ;
}
void F_379 ( struct V_12 * V_13 )
{
struct V_1 * V_14 ;
T_2 V_67 = 0 ;
while ( 1 ) {
struct V_236 * V_236 ;
V_14 = F_64 ( V_13 , V_67 ) ;
while ( V_14 ) {
F_11 ( & V_14 -> V_50 ) ;
if ( V_14 -> V_164 )
break;
F_13 ( & V_14 -> V_50 ) ;
V_14 = F_202 ( V_13 -> V_92 ,
V_14 ) ;
}
if ( ! V_14 ) {
if ( V_67 == 0 )
break;
V_67 = 0 ;
continue;
}
V_236 = V_14 -> V_236 ;
V_14 -> V_164 = 0 ;
V_14 -> V_236 = NULL ;
F_13 ( & V_14 -> V_50 ) ;
F_214 ( V_236 ) ;
V_67 = V_14 -> V_21 . V_22 + V_14 -> V_21 . V_32 ;
F_6 ( V_14 ) ;
}
}
int F_380 ( struct V_12 * V_13 )
{
struct V_1 * V_14 ;
struct V_97 * V_82 ;
struct V_48 * V_52 ;
struct V_15 * V_29 ;
F_56 ( & V_13 -> V_76 ) ;
while ( ! F_165 ( & V_13 -> V_95 ) ) {
V_52 = F_166 ( V_13 -> V_95 . V_214 ,
struct V_48 , V_94 ) ;
F_381 ( & V_52 -> V_94 ) ;
F_26 ( V_52 ) ;
}
F_58 ( & V_13 -> V_76 ) ;
F_11 ( & V_13 -> V_18 ) ;
while ( ( V_29 = F_382 ( & V_13 -> V_19 ) ) != NULL ) {
V_14 = F_12 ( V_29 , struct V_1 ,
V_20 ) ;
F_170 ( & V_14 -> V_20 ,
& V_13 -> V_19 ) ;
F_13 ( & V_13 -> V_18 ) ;
F_56 ( & V_14 -> V_82 -> V_261 ) ;
F_381 ( & V_14 -> V_94 ) ;
F_58 ( & V_14 -> V_82 -> V_261 ) ;
if ( V_14 -> V_3 == V_51 )
F_306 ( V_14 ) ;
if ( V_14 -> V_3 == V_89 )
F_19 ( V_13 -> V_60 , V_14 ) ;
F_383 ( V_14 ) ;
F_6 ( V_14 ) ;
F_11 ( & V_13 -> V_18 ) ;
}
F_13 ( & V_13 -> V_18 ) ;
F_384 () ;
F_260 ( V_13 ) ;
while( ! F_165 ( & V_13 -> V_82 ) ) {
V_82 = F_166 ( V_13 -> V_82 . V_214 ,
struct V_97 ,
V_94 ) ;
if ( V_82 -> V_262 > 0 ||
V_82 -> V_263 > 0 ) {
F_8 ( 1 ) ;
F_315 ( V_82 , 0 , 0 ) ;
}
F_381 ( & V_82 -> V_94 ) ;
F_9 ( V_82 ) ;
}
return 0 ;
}
static void F_385 ( struct V_97 * V_82 ,
struct V_1 * V_2 )
{
int V_395 = F_307 ( V_2 ) ;
F_56 ( & V_82 -> V_261 ) ;
F_57 ( & V_2 -> V_94 , & V_82 -> V_260 [ V_395 ] ) ;
F_58 ( & V_82 -> V_261 ) ;
}
int F_386 ( struct V_33 * V_34 )
{
struct V_61 * V_62 ;
int V_28 ;
struct V_1 * V_2 ;
struct V_12 * V_13 = V_34 -> V_36 ;
struct V_97 * V_82 ;
struct V_65 V_21 ;
struct V_65 V_141 ;
struct V_63 * V_64 ;
int V_481 = 0 ;
T_2 V_482 ;
V_34 = V_13 -> V_60 ;
V_21 . V_22 = 0 ;
V_21 . V_32 = 0 ;
F_78 ( & V_21 , V_177 ) ;
V_62 = F_31 () ;
if ( ! V_62 )
return - V_69 ;
V_62 -> V_72 = 1 ;
V_482 = F_280 ( & V_34 -> V_36 -> V_302 ) ;
if ( V_482 != 0 &&
F_387 ( & V_34 -> V_36 -> V_302 ) != V_482 )
V_481 = 1 ;
if ( F_290 ( V_34 , V_483 ) )
V_481 = 1 ;
if ( ! F_290 ( V_34 , V_484 ) && V_482 )
F_62 ( V_432 L_20 ) ;
while ( 1 ) {
V_28 = F_378 ( V_34 , V_62 , & V_21 ) ;
if ( V_28 > 0 )
break;
if ( V_28 != 0 )
goto error;
V_64 = V_62 -> V_78 [ 0 ] ;
F_38 ( V_64 , & V_141 , V_62 -> V_79 [ 0 ] ) ;
V_2 = F_51 ( sizeof( * V_2 ) , V_39 ) ;
if ( ! V_2 ) {
V_28 = - V_69 ;
goto error;
}
V_2 -> V_11 = F_51 ( sizeof( * V_2 -> V_11 ) ,
V_39 ) ;
if ( ! V_2 -> V_11 ) {
F_9 ( V_2 ) ;
V_28 = - V_69 ;
goto error;
}
F_55 ( & V_2 -> V_7 , 1 ) ;
F_220 ( & V_2 -> V_50 ) ;
V_2 -> V_36 = V_13 ;
F_52 ( & V_2 -> V_94 ) ;
F_52 ( & V_2 -> V_485 ) ;
if ( V_481 )
V_2 -> V_242 = V_248 ;
F_388 ( V_64 , & V_2 -> V_114 ,
F_200 ( V_64 , V_62 -> V_79 [ 0 ] ) ,
sizeof( V_2 -> V_114 ) ) ;
memcpy ( & V_2 -> V_21 , & V_141 , sizeof( V_141 ) ) ;
V_21 . V_22 = V_141 . V_22 + V_141 . V_32 ;
F_42 ( V_62 ) ;
V_2 -> V_6 = F_389 ( & V_2 -> V_114 ) ;
V_2 -> V_286 = V_34 -> V_286 ;
F_390 ( V_2 ) ;
F_21 ( V_34 , V_2 ) ;
if ( V_141 . V_32 == F_76 ( & V_2 -> V_114 ) ) {
V_2 -> V_93 = ( T_2 ) - 1 ;
V_2 -> V_3 = V_4 ;
F_19 ( V_34 , V_2 ) ;
} else if ( F_76 ( & V_2 -> V_114 ) == 0 ) {
V_2 -> V_93 = ( T_2 ) - 1 ;
V_2 -> V_3 = V_4 ;
F_27 ( V_2 , V_34 -> V_36 ,
V_141 . V_22 ,
V_141 . V_22 +
V_141 . V_32 ) ;
F_19 ( V_34 , V_2 ) ;
}
V_28 = F_218 ( V_13 , V_2 -> V_6 , V_141 . V_32 ,
F_76 ( & V_2 -> V_114 ) ,
& V_82 ) ;
F_22 ( V_28 ) ;
V_2 -> V_82 = V_82 ;
F_11 ( & V_2 -> V_82 -> V_50 ) ;
V_2 -> V_82 -> V_264 += V_2 -> V_45 ;
F_13 ( & V_2 -> V_82 -> V_50 ) ;
F_385 ( V_82 , V_2 ) ;
V_28 = F_10 ( V_34 -> V_36 , V_2 ) ;
F_22 ( V_28 ) ;
F_222 ( V_34 -> V_36 , V_2 -> V_6 ) ;
if ( F_391 ( V_34 , V_2 -> V_21 . V_22 ) )
F_370 ( V_2 ) ;
}
F_68 (space_info, &root->fs_info->space_info, list) {
if ( ! ( F_224 ( V_34 , V_82 -> V_6 ) &
( V_256 |
V_255 |
V_254 ) ) )
continue;
F_309 (cache, &space_info->block_groups[3], list)
F_370 ( V_2 ) ;
F_309 (cache, &space_info->block_groups[4], list)
F_370 ( V_2 ) ;
}
F_259 ( V_13 ) ;
V_28 = 0 ;
error:
F_47 ( V_62 ) ;
return V_28 ;
}
int F_392 ( struct V_84 * V_85 ,
struct V_33 * V_34 , T_2 V_253 ,
T_2 type , T_2 V_486 , T_2 V_487 ,
T_2 V_55 )
{
int V_28 ;
struct V_33 * V_60 ;
struct V_1 * V_2 ;
V_60 = V_34 -> V_36 -> V_60 ;
V_34 -> V_36 -> V_488 = V_85 -> V_376 ;
V_2 = F_51 ( sizeof( * V_2 ) , V_39 ) ;
if ( ! V_2 )
return - V_69 ;
V_2 -> V_11 = F_51 ( sizeof( * V_2 -> V_11 ) ,
V_39 ) ;
if ( ! V_2 -> V_11 ) {
F_9 ( V_2 ) ;
return - V_69 ;
}
V_2 -> V_21 . V_22 = V_487 ;
V_2 -> V_21 . V_32 = V_55 ;
V_2 -> V_21 . type = V_177 ;
V_2 -> V_286 = V_34 -> V_286 ;
V_2 -> V_36 = V_34 -> V_36 ;
F_55 ( & V_2 -> V_7 , 1 ) ;
F_220 ( & V_2 -> V_50 ) ;
F_52 ( & V_2 -> V_94 ) ;
F_52 ( & V_2 -> V_485 ) ;
F_390 ( V_2 ) ;
F_281 ( & V_2 -> V_114 , V_253 ) ;
F_393 ( & V_2 -> V_114 , V_486 ) ;
V_2 -> V_6 = type ;
F_394 ( & V_2 -> V_114 , type ) ;
V_2 -> V_93 = ( T_2 ) - 1 ;
V_2 -> V_3 = V_4 ;
F_21 ( V_34 , V_2 ) ;
F_27 ( V_2 , V_34 -> V_36 , V_487 ,
V_487 + V_55 ) ;
F_19 ( V_34 , V_2 ) ;
V_28 = F_218 ( V_34 -> V_36 , V_2 -> V_6 , V_55 , V_253 ,
& V_2 -> V_82 ) ;
F_22 ( V_28 ) ;
F_11 ( & V_2 -> V_82 -> V_50 ) ;
V_2 -> V_82 -> V_264 += V_2 -> V_45 ;
F_13 ( & V_2 -> V_82 -> V_50 ) ;
F_385 ( V_2 -> V_82 , V_2 ) ;
V_28 = F_10 ( V_34 -> V_36 , V_2 ) ;
F_22 ( V_28 ) ;
V_28 = F_395 ( V_85 , V_60 , & V_2 -> V_21 , & V_2 -> V_114 ,
sizeof( V_2 -> V_114 ) ) ;
F_22 ( V_28 ) ;
F_222 ( V_60 -> V_36 , type ) ;
return 0 ;
}
int F_396 ( struct V_84 * V_85 ,
struct V_33 * V_34 , T_2 V_111 )
{
struct V_61 * V_62 ;
struct V_1 * V_14 ;
struct V_400 * V_211 ;
struct V_33 * V_92 = V_34 -> V_36 -> V_92 ;
struct V_65 V_21 ;
struct V_236 * V_236 ;
int V_28 ;
int V_106 ;
V_34 = V_34 -> V_36 -> V_60 ;
V_14 = F_65 ( V_34 -> V_36 , V_111 ) ;
F_22 ( ! V_14 ) ;
F_22 ( ! V_14 -> V_115 ) ;
F_19 ( V_34 , V_14 ) ;
memcpy ( & V_21 , & V_14 -> V_21 , sizeof( V_21 ) ) ;
if ( V_14 -> V_6 & ( V_254 |
V_255 |
V_256 ) )
V_106 = 2 ;
else
V_106 = 1 ;
V_211 = & V_34 -> V_36 -> V_415 ;
F_11 ( & V_211 -> V_426 ) ;
F_312 ( V_14 , V_211 ) ;
F_13 ( & V_211 -> V_426 ) ;
V_211 = & V_34 -> V_36 -> V_413 ;
F_11 ( & V_211 -> V_426 ) ;
F_312 ( V_14 , V_211 ) ;
F_13 ( & V_211 -> V_426 ) ;
V_62 = F_31 () ;
F_22 ( ! V_62 ) ;
V_236 = F_204 ( V_34 , V_14 , V_62 ) ;
if ( ! F_60 ( V_236 ) ) {
F_397 ( V_85 , V_236 ) ;
F_398 ( V_236 ) ;
F_11 ( & V_14 -> V_50 ) ;
if ( V_14 -> V_164 ) {
V_14 -> V_164 = 0 ;
V_14 -> V_236 = NULL ;
F_13 ( & V_14 -> V_50 ) ;
F_214 ( V_236 ) ;
} else {
F_13 ( & V_14 -> V_50 ) ;
}
F_214 ( V_236 ) ;
}
V_21 . V_22 = V_489 ;
V_21 . V_32 = V_14 -> V_21 . V_22 ;
V_21 . type = 0 ;
V_28 = F_35 ( V_85 , V_92 , & V_21 , V_62 , - 1 , 1 ) ;
if ( V_28 < 0 )
goto V_130;
if ( V_28 > 0 )
F_42 ( V_62 ) ;
if ( V_28 == 0 ) {
V_28 = F_118 ( V_85 , V_92 , V_62 ) ;
if ( V_28 )
goto V_130;
F_42 ( V_62 ) ;
}
F_11 ( & V_34 -> V_36 -> V_18 ) ;
F_170 ( & V_14 -> V_20 ,
& V_34 -> V_36 -> V_19 ) ;
F_13 ( & V_34 -> V_36 -> V_18 ) ;
F_56 ( & V_14 -> V_82 -> V_261 ) ;
F_169 ( & V_14 -> V_94 ) ;
F_58 ( & V_14 -> V_82 -> V_261 ) ;
if ( V_14 -> V_3 == V_51 )
F_306 ( V_14 ) ;
F_383 ( V_14 ) ;
F_11 ( & V_14 -> V_82 -> V_50 ) ;
V_14 -> V_82 -> V_252 -= V_14 -> V_21 . V_32 ;
V_14 -> V_82 -> V_264 -= V_14 -> V_21 . V_32 ;
V_14 -> V_82 -> V_257 -= V_14 -> V_21 . V_32 * V_106 ;
F_13 ( & V_14 -> V_82 -> V_50 ) ;
memcpy ( & V_21 , & V_14 -> V_21 , sizeof( V_21 ) ) ;
F_70 ( V_34 -> V_36 ) ;
F_6 ( V_14 ) ;
F_6 ( V_14 ) ;
V_28 = F_35 ( V_85 , V_34 , & V_21 , V_62 , - 1 , 1 ) ;
if ( V_28 > 0 )
V_28 = - V_209 ;
if ( V_28 < 0 )
goto V_130;
V_28 = F_118 ( V_85 , V_34 , V_62 ) ;
V_130:
F_47 ( V_62 ) ;
return V_28 ;
}
int F_399 ( struct V_12 * V_36 )
{
struct V_97 * V_82 ;
struct V_490 * V_491 ;
T_2 V_492 ;
T_2 V_6 ;
int V_493 = 0 ;
int V_28 ;
V_491 = & V_36 -> V_302 ;
if ( ! F_400 ( V_491 ) )
return 1 ;
V_492 = F_401 ( V_491 ) ;
if ( V_492 & V_494 )
V_493 = 1 ;
V_6 = V_102 ;
V_28 = F_218 ( V_36 , V_6 , 0 , 0 , & V_82 ) ;
if ( V_28 )
goto V_130;
if ( V_493 ) {
V_6 = V_103 | V_101 ;
V_28 = F_218 ( V_36 , V_6 , 0 , 0 , & V_82 ) ;
} else {
V_6 = V_103 ;
V_28 = F_218 ( V_36 , V_6 , 0 , 0 , & V_82 ) ;
if ( V_28 )
goto V_130;
V_6 = V_101 ;
V_28 = F_218 ( V_36 , V_6 , 0 , 0 , & V_82 ) ;
}
V_130:
return V_28 ;
}
int F_402 ( struct V_33 * V_34 , T_2 V_31 , T_2 V_30 )
{
return F_288 ( V_34 , V_31 , V_30 ) ;
}
int F_403 ( struct V_33 * V_34 , T_2 V_26 ,
T_2 V_35 , T_2 * V_185 )
{
return F_144 ( V_34 , V_26 , V_35 , V_185 ) ;
}
int F_404 ( struct V_33 * V_34 , struct V_495 * V_496 )
{
struct V_12 * V_36 = V_34 -> V_36 ;
struct V_1 * V_2 = NULL ;
T_2 V_497 ;
T_2 V_31 ;
T_2 V_30 ;
T_2 V_498 = 0 ;
int V_28 = 0 ;
V_2 = F_65 ( V_36 , V_496 -> V_31 ) ;
while ( V_2 ) {
if ( V_2 -> V_21 . V_22 >= ( V_496 -> V_31 + V_496 -> V_116 ) ) {
F_6 ( V_2 ) ;
break;
}
V_31 = F_75 ( V_496 -> V_31 , V_2 -> V_21 . V_22 ) ;
V_30 = F_238 ( V_496 -> V_31 + V_496 -> V_116 ,
V_2 -> V_21 . V_22 + V_2 -> V_21 . V_32 ) ;
if ( V_30 - V_31 >= V_496 -> V_499 ) {
if ( ! F_1 ( V_2 ) ) {
V_28 = F_49 ( V_2 , NULL , V_34 , 0 ) ;
if ( ! V_28 )
F_306 ( V_2 ) ;
}
V_28 = F_405 ( V_2 ,
& V_497 ,
V_31 ,
V_30 ,
V_496 -> V_499 ) ;
V_498 += V_497 ;
if ( V_28 ) {
F_6 ( V_2 ) ;
break;
}
}
V_2 = F_202 ( V_36 -> V_92 , V_2 ) ;
}
V_496 -> V_116 = V_498 ;
return V_28 ;
}
