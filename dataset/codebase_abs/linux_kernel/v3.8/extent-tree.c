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
V_57 | V_37 ,
NULL ) ;
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
if ( ! V_51 )
return - V_85 ;
F_52 ( & V_51 -> V_86 ) ;
F_53 ( & V_51 -> V_75 ) ;
F_54 ( & V_51 -> V_81 ) ;
V_51 -> V_13 = V_2 ;
V_51 -> V_80 = V_2 -> V_20 . V_21 ;
F_55 ( & V_51 -> V_7 , 1 ) ;
V_51 -> V_59 . V_87 = F_30 ;
F_11 ( & V_2 -> V_49 ) ;
while ( V_2 -> V_3 == V_88 ) {
struct V_47 * V_48 ;
V_48 = V_2 -> V_51 ;
F_5 ( & V_48 -> V_7 ) ;
F_56 ( & V_48 -> V_81 , & V_81 , V_89 ) ;
F_13 ( & V_2 -> V_49 ) ;
F_57 () ;
F_58 ( & V_48 -> V_81 , & V_81 ) ;
F_26 ( V_48 ) ;
F_11 ( & V_2 -> V_49 ) ;
}
if ( V_2 -> V_3 != V_90 ) {
F_13 ( & V_2 -> V_49 ) ;
F_9 ( V_51 ) ;
return 0 ;
}
F_8 ( V_2 -> V_51 ) ;
V_2 -> V_51 = V_51 ;
V_2 -> V_3 = V_88 ;
F_13 ( & V_2 -> V_49 ) ;
if ( V_35 -> V_91 & V_92 ) {
V_27 = F_59 ( V_35 , V_2 ) ;
F_11 ( & V_2 -> V_49 ) ;
if ( V_27 == 1 ) {
V_2 -> V_51 = NULL ;
V_2 -> V_3 = V_4 ;
V_2 -> V_93 = ( T_2 ) - 1 ;
} else {
if ( V_84 ) {
V_2 -> V_51 = NULL ;
V_2 -> V_3 = V_90 ;
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
V_2 -> V_3 = V_90 ;
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
F_60 ( & V_35 -> V_76 ) ;
F_5 ( & V_51 -> V_7 ) ;
F_61 ( & V_51 -> V_86 , & V_35 -> V_94 ) ;
F_62 ( & V_35 -> V_76 ) ;
F_4 ( V_2 ) ;
F_63 ( & V_35 -> V_95 , & V_51 -> V_59 ) ;
return V_27 ;
}
static struct V_1 *
F_64 ( struct V_11 * V_12 , T_2 V_25 )
{
struct V_1 * V_2 ;
V_2 = F_16 ( V_12 , V_25 , 0 ) ;
return V_2 ;
}
struct V_1 * F_65 (
struct V_11 * V_12 ,
T_2 V_25 )
{
struct V_1 * V_2 ;
V_2 = F_16 ( V_12 , V_25 , 1 ) ;
return V_2 ;
}
static struct V_96 * F_66 ( struct V_11 * V_12 ,
T_2 V_6 )
{
struct V_97 * V_98 = & V_12 -> V_99 ;
struct V_96 * V_100 ;
V_6 &= V_101 ;
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
void F_70 ( struct V_11 * V_12 )
{
struct V_97 * V_98 = & V_12 -> V_99 ;
struct V_96 * V_100 ;
F_67 () ;
F_68 (found, head, list)
V_100 -> V_102 = 0 ;
F_69 () ;
}
T_2 F_71 ( struct V_32 * V_33 ,
T_2 V_103 , T_2 V_104 , int V_105 )
{
struct V_1 * V_2 ;
T_2 V_106 ;
T_2 V_67 = F_72 ( V_104 , V_103 ) ;
T_2 V_107 = 0 ;
int V_108 = 0 ;
int V_109 = 9 ;
int V_110 = 0 ;
V_74:
while ( 1 ) {
V_2 = F_64 ( V_33 -> V_35 , V_67 ) ;
if ( ! V_2 )
break;
F_11 ( & V_2 -> V_49 ) ;
V_67 = V_2 -> V_20 . V_21 + V_2 -> V_20 . V_31 ;
V_106 = F_73 ( & V_2 -> V_111 ) ;
if ( ( V_108 || ! V_2 -> V_112 ) &&
F_3 ( V_2 , V_113 ) ) {
if ( V_106 + V_2 -> V_8 + V_2 -> V_9 <
F_74 ( V_2 -> V_20 . V_31 , V_109 ) ) {
V_107 = V_2 -> V_20 . V_21 ;
F_13 ( & V_2 -> V_49 ) ;
F_6 ( V_2 ) ;
goto V_100;
}
}
F_13 ( & V_2 -> V_49 ) ;
F_6 ( V_2 ) ;
F_46 () ;
}
if ( ! V_110 ) {
V_67 = V_103 ;
V_110 = 1 ;
goto V_74;
}
if ( ! V_108 && V_109 < 10 ) {
V_67 = V_103 ;
V_108 = 1 ;
V_109 = 10 ;
goto V_74;
}
V_100:
return V_107 ;
}
int F_75 ( struct V_32 * V_33 , T_2 V_30 , T_2 V_114 )
{
int V_27 ;
struct V_65 V_20 ;
struct V_61 * V_62 ;
V_62 = F_32 () ;
if ( ! V_62 )
return - V_85 ;
V_20 . V_21 = V_30 ;
V_20 . V_31 = V_114 ;
F_76 ( & V_20 , V_73 ) ;
V_27 = F_36 ( NULL , V_33 -> V_35 -> V_60 , & V_20 , V_62 ,
0 , 0 ) ;
F_48 ( V_62 ) ;
return V_27 ;
}
int F_77 ( struct V_82 * V_83 ,
struct V_32 * V_33 , T_2 V_25 ,
T_2 V_34 , T_2 * V_115 , T_2 * V_6 )
{
struct V_116 * V_98 ;
struct V_117 * V_118 ;
struct V_61 * V_62 ;
struct V_119 * V_120 ;
struct V_63 * V_64 ;
struct V_65 V_20 ;
T_3 V_121 ;
T_2 V_122 ;
T_2 V_123 ;
int V_27 ;
V_62 = F_32 () ;
if ( ! V_62 )
return - V_85 ;
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
goto V_124;
if ( V_27 == 0 ) {
V_64 = V_62 -> V_78 [ 0 ] ;
V_121 = F_78 ( V_64 , V_62 -> V_79 [ 0 ] ) ;
if ( V_121 >= sizeof( * V_120 ) ) {
V_120 = F_79 ( V_64 , V_62 -> V_79 [ 0 ] ,
struct V_119 ) ;
V_122 = F_80 ( V_64 , V_120 ) ;
V_123 = F_81 ( V_64 , V_120 ) ;
} else {
#ifdef F_82
struct V_125 * V_126 ;
F_22 ( V_121 != sizeof( * V_126 ) ) ;
V_126 = F_79 ( V_64 , V_62 -> V_79 [ 0 ] ,
struct V_125 ) ;
V_122 = F_83 ( V_64 , V_126 ) ;
V_123 = V_127 ;
#else
F_84 () ;
#endif
}
F_22 ( V_122 == 0 ) ;
} else {
V_122 = 0 ;
V_123 = 0 ;
V_27 = 0 ;
}
if ( ! V_83 )
goto V_69;
V_118 = & V_83 -> V_128 -> V_118 ;
F_11 ( & V_118 -> V_49 ) ;
V_98 = F_85 ( V_83 , V_25 ) ;
if ( V_98 ) {
if ( ! F_86 ( & V_98 -> V_75 ) ) {
F_5 ( & V_98 -> V_129 . V_115 ) ;
F_13 ( & V_118 -> V_49 ) ;
F_43 ( V_62 ) ;
F_34 ( & V_98 -> V_75 ) ;
F_45 ( & V_98 -> V_75 ) ;
F_87 ( & V_98 -> V_129 ) ;
goto V_74;
}
if ( V_98 -> V_130 && V_98 -> V_130 -> V_131 )
V_123 |= V_98 -> V_130 -> V_132 ;
else
F_22 ( V_122 == 0 ) ;
V_122 += V_98 -> V_129 . V_133 ;
F_45 ( & V_98 -> V_75 ) ;
}
F_13 ( & V_118 -> V_49 ) ;
V_69:
F_8 ( V_122 == 0 ) ;
if ( V_115 )
* V_115 = V_122 ;
if ( V_6 )
* V_6 = V_123 ;
V_124:
F_48 ( V_62 ) ;
return V_27 ;
}
static int F_88 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_61 * V_62 ,
T_2 V_105 , T_3 V_134 )
{
struct V_119 * V_111 ;
struct V_125 * V_126 ;
struct V_135 * V_136 ;
struct V_137 * V_138 ;
struct V_63 * V_64 ;
struct V_65 V_20 ;
struct V_65 V_139 ;
T_3 V_140 = sizeof( * V_111 ) ;
T_2 V_115 ;
int V_27 ;
V_64 = V_62 -> V_78 [ 0 ] ;
F_22 ( F_78 ( V_64 , V_62 -> V_79 [ 0 ] ) != sizeof( * V_126 ) ) ;
F_39 ( V_64 , & V_20 , V_62 -> V_79 [ 0 ] ) ;
V_126 = F_79 ( V_64 , V_62 -> V_79 [ 0 ] ,
struct V_125 ) ;
V_115 = F_83 ( V_64 , V_126 ) ;
if ( V_105 == ( T_2 ) - 1 ) {
while ( 1 ) {
if ( V_62 -> V_79 [ 0 ] >= F_37 ( V_64 ) ) {
V_27 = F_42 ( V_33 , V_62 ) ;
if ( V_27 < 0 )
return V_27 ;
F_22 ( V_27 > 0 ) ;
V_64 = V_62 -> V_78 [ 0 ] ;
}
F_39 ( V_64 , & V_139 ,
V_62 -> V_79 [ 0 ] ) ;
F_22 ( V_20 . V_21 != V_139 . V_21 ) ;
if ( V_139 . type != V_141 ) {
V_62 -> V_79 [ 0 ] ++ ;
continue;
}
V_136 = F_79 ( V_64 , V_62 -> V_79 [ 0 ] ,
struct V_135 ) ;
V_105 = F_89 ( V_64 , V_136 ) ;
break;
}
}
F_43 ( V_62 ) ;
if ( V_105 < V_142 )
V_140 += sizeof( * V_138 ) ;
V_140 -= sizeof( * V_126 ) ;
V_27 = F_36 ( V_83 , V_33 , & V_20 , V_62 ,
V_140 + V_134 , 1 ) ;
if ( V_27 < 0 )
return V_27 ;
F_22 ( V_27 ) ;
F_90 ( V_83 , V_33 , V_62 , V_140 ) ;
V_64 = V_62 -> V_78 [ 0 ] ;
V_111 = F_79 ( V_64 , V_62 -> V_79 [ 0 ] , struct V_119 ) ;
F_91 ( V_64 , V_111 , V_115 ) ;
F_92 ( V_64 , V_111 , 0 ) ;
if ( V_105 < V_142 ) {
F_93 ( V_64 , V_111 ,
V_143 |
V_127 ) ;
V_138 = (struct V_137 * ) ( V_111 + 1 ) ;
F_94 ( V_64 , 0 , ( unsigned long ) V_138 , sizeof( * V_138 ) ) ;
F_95 ( V_64 , V_138 , ( int ) V_105 ) ;
} else {
F_93 ( V_64 , V_111 , V_144 ) ;
}
F_96 ( V_64 ) ;
return 0 ;
}
static T_2 F_97 ( T_2 V_145 , T_2 V_105 , T_2 V_31 )
{
T_3 V_146 = ~ ( T_3 ) 0 ;
T_3 V_147 = ~ ( T_3 ) 0 ;
T_4 V_148 ;
V_148 = F_98 ( V_145 ) ;
V_146 = F_99 ( V_146 , & V_148 , sizeof( V_148 ) ) ;
V_148 = F_98 ( V_105 ) ;
V_147 = F_99 ( V_147 , & V_148 , sizeof( V_148 ) ) ;
V_148 = F_98 ( V_31 ) ;
V_147 = F_99 ( V_147 , & V_148 , sizeof( V_148 ) ) ;
return ( ( T_2 ) V_146 << 31 ) ^ ( T_2 ) V_147 ;
}
static T_2 F_100 ( struct V_63 * V_64 ,
struct V_149 * V_150 )
{
return F_97 ( F_101 ( V_64 , V_150 ) ,
F_102 ( V_64 , V_150 ) ,
F_103 ( V_64 , V_150 ) ) ;
}
static int F_104 ( struct V_63 * V_64 ,
struct V_149 * V_150 ,
T_2 V_145 , T_2 V_105 , T_2 V_31 )
{
if ( F_101 ( V_64 , V_150 ) != V_145 ||
F_102 ( V_64 , V_150 ) != V_105 ||
F_103 ( V_64 , V_150 ) != V_31 )
return 0 ;
return 1 ;
}
static T_1 int F_105 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_61 * V_62 ,
T_2 V_25 , T_2 V_16 ,
T_2 V_145 ,
T_2 V_105 , T_2 V_31 )
{
struct V_65 V_20 ;
struct V_149 * V_150 ;
struct V_63 * V_64 ;
T_3 V_68 ;
int V_27 ;
int V_151 ;
int V_77 = - V_152 ;
V_20 . V_21 = V_25 ;
if ( V_16 ) {
V_20 . type = V_153 ;
V_20 . V_31 = V_16 ;
} else {
V_20 . type = V_154 ;
V_20 . V_31 = F_97 ( V_145 ,
V_105 , V_31 ) ;
}
V_74:
V_151 = 0 ;
V_27 = F_36 ( V_83 , V_33 , & V_20 , V_62 , - 1 , 1 ) ;
if ( V_27 < 0 ) {
V_77 = V_27 ;
goto V_155;
}
if ( V_16 ) {
if ( ! V_27 )
return 0 ;
#ifdef F_82
V_20 . type = V_141 ;
F_43 ( V_62 ) ;
V_27 = F_36 ( V_83 , V_33 , & V_20 , V_62 , - 1 , 1 ) ;
if ( V_27 < 0 ) {
V_77 = V_27 ;
goto V_155;
}
if ( ! V_27 )
return 0 ;
#endif
goto V_155;
}
V_64 = V_62 -> V_78 [ 0 ] ;
V_68 = F_37 ( V_64 ) ;
while ( 1 ) {
if ( V_62 -> V_79 [ 0 ] >= V_68 ) {
V_27 = F_42 ( V_33 , V_62 ) ;
if ( V_27 < 0 )
V_77 = V_27 ;
if ( V_27 )
goto V_155;
V_64 = V_62 -> V_78 [ 0 ] ;
V_68 = F_37 ( V_64 ) ;
V_151 = 1 ;
}
F_39 ( V_64 , & V_20 , V_62 -> V_79 [ 0 ] ) ;
if ( V_20 . V_21 != V_25 ||
V_20 . type != V_154 )
goto V_155;
V_150 = F_79 ( V_64 , V_62 -> V_79 [ 0 ] ,
struct V_149 ) ;
if ( F_104 ( V_64 , V_150 , V_145 ,
V_105 , V_31 ) ) {
if ( V_151 ) {
F_43 ( V_62 ) ;
goto V_74;
}
V_77 = 0 ;
break;
}
V_62 -> V_79 [ 0 ] ++ ;
}
V_155:
return V_77 ;
}
static T_1 int F_106 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_61 * V_62 ,
T_2 V_25 , T_2 V_16 ,
T_2 V_145 , T_2 V_105 ,
T_2 V_31 , int V_156 )
{
struct V_65 V_20 ;
struct V_63 * V_64 ;
T_3 V_54 ;
T_3 V_122 ;
int V_27 ;
V_20 . V_21 = V_25 ;
if ( V_16 ) {
V_20 . type = V_153 ;
V_20 . V_31 = V_16 ;
V_54 = sizeof( struct V_157 ) ;
} else {
V_20 . type = V_154 ;
V_20 . V_31 = F_97 ( V_145 ,
V_105 , V_31 ) ;
V_54 = sizeof( struct V_149 ) ;
}
V_27 = F_107 ( V_83 , V_33 , V_62 , & V_20 , V_54 ) ;
if ( V_27 && V_27 != - V_24 )
goto V_155;
V_64 = V_62 -> V_78 [ 0 ] ;
if ( V_16 ) {
struct V_157 * V_150 ;
V_150 = F_79 ( V_64 , V_62 -> V_79 [ 0 ] ,
struct V_157 ) ;
if ( V_27 == 0 ) {
F_108 ( V_64 , V_150 , V_156 ) ;
} else {
V_122 = F_109 ( V_64 , V_150 ) ;
V_122 += V_156 ;
F_108 ( V_64 , V_150 , V_122 ) ;
}
} else {
struct V_149 * V_150 ;
while ( V_27 == - V_24 ) {
V_150 = F_79 ( V_64 , V_62 -> V_79 [ 0 ] ,
struct V_149 ) ;
if ( F_104 ( V_64 , V_150 , V_145 ,
V_105 , V_31 ) )
break;
F_43 ( V_62 ) ;
V_20 . V_31 ++ ;
V_27 = F_107 ( V_83 , V_33 , V_62 , & V_20 ,
V_54 ) ;
if ( V_27 && V_27 != - V_24 )
goto V_155;
V_64 = V_62 -> V_78 [ 0 ] ;
}
V_150 = F_79 ( V_64 , V_62 -> V_79 [ 0 ] ,
struct V_149 ) ;
if ( V_27 == 0 ) {
F_110 ( V_64 , V_150 ,
V_145 ) ;
F_111 ( V_64 , V_150 , V_105 ) ;
F_112 ( V_64 , V_150 , V_31 ) ;
F_113 ( V_64 , V_150 , V_156 ) ;
} else {
V_122 = F_114 ( V_64 , V_150 ) ;
V_122 += V_156 ;
F_113 ( V_64 , V_150 , V_122 ) ;
}
}
F_96 ( V_64 ) ;
V_27 = 0 ;
V_155:
F_43 ( V_62 ) ;
return V_27 ;
}
static T_1 int F_115 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_61 * V_62 ,
int V_158 )
{
struct V_65 V_20 ;
struct V_149 * V_159 = NULL ;
struct V_157 * V_160 = NULL ;
struct V_63 * V_64 ;
T_3 V_122 = 0 ;
int V_27 = 0 ;
V_64 = V_62 -> V_78 [ 0 ] ;
F_39 ( V_64 , & V_20 , V_62 -> V_79 [ 0 ] ) ;
if ( V_20 . type == V_154 ) {
V_159 = F_79 ( V_64 , V_62 -> V_79 [ 0 ] ,
struct V_149 ) ;
V_122 = F_114 ( V_64 , V_159 ) ;
} else if ( V_20 . type == V_153 ) {
V_160 = F_79 ( V_64 , V_62 -> V_79 [ 0 ] ,
struct V_157 ) ;
V_122 = F_109 ( V_64 , V_160 ) ;
#ifdef F_82
} else if ( V_20 . type == V_141 ) {
struct V_135 * V_136 ;
V_136 = F_79 ( V_64 , V_62 -> V_79 [ 0 ] ,
struct V_135 ) ;
V_122 = F_116 ( V_64 , V_136 ) ;
#endif
} else {
F_84 () ;
}
F_22 ( V_122 < V_158 ) ;
V_122 -= V_158 ;
if ( V_122 == 0 ) {
V_27 = F_117 ( V_83 , V_33 , V_62 ) ;
} else {
if ( V_20 . type == V_154 )
F_113 ( V_64 , V_159 , V_122 ) ;
else if ( V_20 . type == V_153 )
F_108 ( V_64 , V_160 , V_122 ) ;
#ifdef F_82
else {
struct V_135 * V_136 ;
V_136 = F_79 ( V_64 , V_62 -> V_79 [ 0 ] ,
struct V_135 ) ;
F_118 ( V_64 , V_136 , V_122 ) ;
}
#endif
F_96 ( V_64 ) ;
}
return V_27 ;
}
static T_1 T_3 F_119 ( struct V_32 * V_33 ,
struct V_61 * V_62 ,
struct V_161 * V_162 )
{
struct V_65 V_20 ;
struct V_63 * V_64 ;
struct V_149 * V_159 ;
struct V_157 * V_160 ;
T_3 V_122 = 0 ;
V_64 = V_62 -> V_78 [ 0 ] ;
F_39 ( V_64 , & V_20 , V_62 -> V_79 [ 0 ] ) ;
if ( V_162 ) {
if ( F_120 ( V_64 , V_162 ) ==
V_154 ) {
V_159 = (struct V_149 * ) ( & V_162 -> V_31 ) ;
V_122 = F_114 ( V_64 , V_159 ) ;
} else {
V_160 = (struct V_157 * ) ( V_162 + 1 ) ;
V_122 = F_109 ( V_64 , V_160 ) ;
}
} else if ( V_20 . type == V_154 ) {
V_159 = F_79 ( V_64 , V_62 -> V_79 [ 0 ] ,
struct V_149 ) ;
V_122 = F_114 ( V_64 , V_159 ) ;
} else if ( V_20 . type == V_153 ) {
V_160 = F_79 ( V_64 , V_62 -> V_79 [ 0 ] ,
struct V_157 ) ;
V_122 = F_109 ( V_64 , V_160 ) ;
#ifdef F_82
} else if ( V_20 . type == V_141 ) {
struct V_135 * V_136 ;
V_136 = F_79 ( V_64 , V_62 -> V_79 [ 0 ] ,
struct V_135 ) ;
V_122 = F_116 ( V_64 , V_136 ) ;
#endif
} else {
F_8 ( 1 ) ;
}
return V_122 ;
}
static T_1 int F_121 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_61 * V_62 ,
T_2 V_25 , T_2 V_16 ,
T_2 V_145 )
{
struct V_65 V_20 ;
int V_27 ;
V_20 . V_21 = V_25 ;
if ( V_16 ) {
V_20 . type = V_163 ;
V_20 . V_31 = V_16 ;
} else {
V_20 . type = V_164 ;
V_20 . V_31 = V_145 ;
}
V_27 = F_36 ( V_83 , V_33 , & V_20 , V_62 , - 1 , 1 ) ;
if ( V_27 > 0 )
V_27 = - V_152 ;
#ifdef F_82
if ( V_27 == - V_152 && V_16 ) {
F_43 ( V_62 ) ;
V_20 . type = V_141 ;
V_27 = F_36 ( V_83 , V_33 , & V_20 , V_62 , - 1 , 1 ) ;
if ( V_27 > 0 )
V_27 = - V_152 ;
}
#endif
return V_27 ;
}
static T_1 int F_122 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_61 * V_62 ,
T_2 V_25 , T_2 V_16 ,
T_2 V_145 )
{
struct V_65 V_20 ;
int V_27 ;
V_20 . V_21 = V_25 ;
if ( V_16 ) {
V_20 . type = V_163 ;
V_20 . V_31 = V_16 ;
} else {
V_20 . type = V_164 ;
V_20 . V_31 = V_145 ;
}
V_27 = F_107 ( V_83 , V_33 , V_62 , & V_20 , 0 ) ;
F_43 ( V_62 ) ;
return V_27 ;
}
static inline int F_123 ( T_2 V_16 , T_2 V_105 )
{
int type ;
if ( V_105 < V_142 ) {
if ( V_16 > 0 )
type = V_163 ;
else
type = V_164 ;
} else {
if ( V_16 > 0 )
type = V_153 ;
else
type = V_154 ;
}
return type ;
}
static int F_40 ( struct V_61 * V_62 , int V_165 ,
struct V_65 * V_20 )
{
for (; V_165 < V_166 ; V_165 ++ ) {
if ( ! V_62 -> V_78 [ V_165 ] )
break;
if ( V_62 -> V_79 [ V_165 ] + 1 >=
F_37 ( V_62 -> V_78 [ V_165 ] ) )
continue;
if ( V_165 == 0 )
F_39 ( V_62 -> V_78 [ V_165 ] , V_20 ,
V_62 -> V_79 [ V_165 ] + 1 ) ;
else
F_124 ( V_62 -> V_78 [ V_165 ] , V_20 ,
V_62 -> V_79 [ V_165 ] + 1 ) ;
return 0 ;
}
return 1 ;
}
static T_5
int F_125 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_61 * V_62 ,
struct V_161 * * V_167 ,
T_2 V_25 , T_2 V_34 ,
T_2 V_16 , T_2 V_145 ,
T_2 V_105 , T_2 V_31 , int V_168 )
{
struct V_65 V_20 ;
struct V_63 * V_64 ;
struct V_119 * V_120 ;
struct V_161 * V_162 ;
T_2 V_6 ;
T_2 V_121 ;
unsigned long V_169 ;
unsigned long V_29 ;
int V_134 ;
int type ;
int V_170 ;
int V_27 ;
int V_77 = 0 ;
V_20 . V_21 = V_25 ;
V_20 . type = V_73 ;
V_20 . V_31 = V_34 ;
V_170 = F_123 ( V_16 , V_105 ) ;
if ( V_168 ) {
V_134 = F_126 ( V_170 ) ;
V_62 -> V_171 = 1 ;
} else
V_134 = - 1 ;
V_27 = F_36 ( V_83 , V_33 , & V_20 , V_62 , V_134 , 1 ) ;
if ( V_27 < 0 ) {
V_77 = V_27 ;
goto V_69;
}
if ( V_27 && ! V_168 ) {
V_77 = - V_152 ;
goto V_69;
}
F_22 ( V_27 ) ;
V_64 = V_62 -> V_78 [ 0 ] ;
V_121 = F_78 ( V_64 , V_62 -> V_79 [ 0 ] ) ;
#ifdef F_82
if ( V_121 < sizeof( * V_120 ) ) {
if ( ! V_168 ) {
V_77 = - V_152 ;
goto V_69;
}
V_27 = F_88 ( V_83 , V_33 , V_62 , V_105 ,
V_134 ) ;
if ( V_27 < 0 ) {
V_77 = V_27 ;
goto V_69;
}
V_64 = V_62 -> V_78 [ 0 ] ;
V_121 = F_78 ( V_64 , V_62 -> V_79 [ 0 ] ) ;
}
#endif
F_22 ( V_121 < sizeof( * V_120 ) ) ;
V_120 = F_79 ( V_64 , V_62 -> V_79 [ 0 ] , struct V_119 ) ;
V_6 = F_81 ( V_64 , V_120 ) ;
V_169 = ( unsigned long ) ( V_120 + 1 ) ;
V_29 = ( unsigned long ) V_120 + V_121 ;
if ( V_6 & V_143 ) {
V_169 += sizeof( struct V_137 ) ;
F_22 ( V_169 > V_29 ) ;
} else {
F_22 ( ! ( V_6 & V_144 ) ) ;
}
V_77 = - V_152 ;
while ( 1 ) {
if ( V_169 >= V_29 ) {
F_8 ( V_169 > V_29 ) ;
break;
}
V_162 = (struct V_161 * ) V_169 ;
type = F_120 ( V_64 , V_162 ) ;
if ( V_170 < type )
break;
if ( V_170 > type ) {
V_169 += F_126 ( type ) ;
continue;
}
if ( type == V_154 ) {
struct V_149 * V_172 ;
V_172 = (struct V_149 * ) ( & V_162 -> V_31 ) ;
if ( F_104 ( V_64 , V_172 , V_145 ,
V_105 , V_31 ) ) {
V_77 = 0 ;
break;
}
if ( F_100 ( V_64 , V_172 ) <
F_97 ( V_145 , V_105 , V_31 ) )
break;
} else {
T_2 V_173 ;
V_173 = F_127 ( V_64 , V_162 ) ;
if ( V_16 > 0 ) {
if ( V_16 == V_173 ) {
V_77 = 0 ;
break;
}
if ( V_173 < V_16 )
break;
} else {
if ( V_145 == V_173 ) {
V_77 = 0 ;
break;
}
if ( V_173 < V_145 )
break;
}
}
V_169 += F_126 ( type ) ;
}
if ( V_77 == - V_152 && V_168 ) {
if ( V_121 + V_134 >=
F_128 ( V_33 ) ) {
V_77 = - V_174 ;
goto V_69;
}
if ( F_40 ( V_62 , 0 , & V_20 ) == 0 &&
V_20 . V_21 == V_25 &&
V_20 . type < V_175 ) {
V_77 = - V_174 ;
goto V_69;
}
}
* V_167 = (struct V_161 * ) V_169 ;
V_69:
if ( V_168 ) {
V_62 -> V_171 = 0 ;
F_129 ( V_62 , 1 ) ;
}
return V_77 ;
}
static T_5
void F_130 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_61 * V_62 ,
struct V_161 * V_162 ,
T_2 V_16 , T_2 V_145 ,
T_2 V_105 , T_2 V_31 , int V_156 ,
struct V_176 * V_130 )
{
struct V_63 * V_64 ;
struct V_119 * V_120 ;
unsigned long V_169 ;
unsigned long V_29 ;
unsigned long V_177 ;
T_2 V_115 ;
int V_54 ;
int type ;
V_64 = V_62 -> V_78 [ 0 ] ;
V_120 = F_79 ( V_64 , V_62 -> V_79 [ 0 ] , struct V_119 ) ;
V_177 = ( unsigned long ) V_162 - ( unsigned long ) V_120 ;
type = F_123 ( V_16 , V_105 ) ;
V_54 = F_126 ( type ) ;
F_90 ( V_83 , V_33 , V_62 , V_54 ) ;
V_120 = F_79 ( V_64 , V_62 -> V_79 [ 0 ] , struct V_119 ) ;
V_115 = F_80 ( V_64 , V_120 ) ;
V_115 += V_156 ;
F_91 ( V_64 , V_120 , V_115 ) ;
if ( V_130 )
F_131 ( V_130 , V_64 , V_120 ) ;
V_169 = ( unsigned long ) V_120 + V_177 ;
V_29 = ( unsigned long ) V_120 + F_78 ( V_64 , V_62 -> V_79 [ 0 ] ) ;
if ( V_169 < V_29 - V_54 )
F_132 ( V_64 , V_169 + V_54 , V_169 ,
V_29 - V_54 - V_169 ) ;
V_162 = (struct V_161 * ) V_169 ;
F_133 ( V_64 , V_162 , type ) ;
if ( type == V_154 ) {
struct V_149 * V_172 ;
V_172 = (struct V_149 * ) ( & V_162 -> V_31 ) ;
F_110 ( V_64 , V_172 , V_145 ) ;
F_111 ( V_64 , V_172 , V_105 ) ;
F_112 ( V_64 , V_172 , V_31 ) ;
F_113 ( V_64 , V_172 , V_156 ) ;
} else if ( type == V_153 ) {
struct V_157 * V_178 ;
V_178 = (struct V_157 * ) ( V_162 + 1 ) ;
F_108 ( V_64 , V_178 , V_156 ) ;
F_134 ( V_64 , V_162 , V_16 ) ;
} else if ( type == V_163 ) {
F_134 ( V_64 , V_162 , V_16 ) ;
} else {
F_134 ( V_64 , V_162 , V_145 ) ;
}
F_96 ( V_64 ) ;
}
static int F_135 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_61 * V_62 ,
struct V_161 * * V_167 ,
T_2 V_25 , T_2 V_34 , T_2 V_16 ,
T_2 V_145 , T_2 V_105 , T_2 V_31 )
{
int V_27 ;
V_27 = F_125 ( V_83 , V_33 , V_62 , V_167 ,
V_25 , V_34 , V_16 ,
V_145 , V_105 , V_31 , 0 ) ;
if ( V_27 != - V_152 )
return V_27 ;
F_43 ( V_62 ) ;
* V_167 = NULL ;
if ( V_105 < V_142 ) {
V_27 = F_121 ( V_83 , V_33 , V_62 , V_25 , V_16 ,
V_145 ) ;
} else {
V_27 = F_105 ( V_83 , V_33 , V_62 , V_25 , V_16 ,
V_145 , V_105 , V_31 ) ;
}
return V_27 ;
}
static T_5
void F_136 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_61 * V_62 ,
struct V_161 * V_162 ,
int V_179 ,
struct V_176 * V_130 )
{
struct V_63 * V_64 ;
struct V_119 * V_120 ;
struct V_149 * V_172 = NULL ;
struct V_157 * V_178 = NULL ;
unsigned long V_169 ;
unsigned long V_29 ;
T_3 V_121 ;
int V_54 ;
int type ;
T_2 V_115 ;
V_64 = V_62 -> V_78 [ 0 ] ;
V_120 = F_79 ( V_64 , V_62 -> V_79 [ 0 ] , struct V_119 ) ;
V_115 = F_80 ( V_64 , V_120 ) ;
F_8 ( V_179 < 0 && V_115 + V_179 <= 0 ) ;
V_115 += V_179 ;
F_91 ( V_64 , V_120 , V_115 ) ;
if ( V_130 )
F_131 ( V_130 , V_64 , V_120 ) ;
type = F_120 ( V_64 , V_162 ) ;
if ( type == V_154 ) {
V_172 = (struct V_149 * ) ( & V_162 -> V_31 ) ;
V_115 = F_114 ( V_64 , V_172 ) ;
} else if ( type == V_153 ) {
V_178 = (struct V_157 * ) ( V_162 + 1 ) ;
V_115 = F_109 ( V_64 , V_178 ) ;
} else {
V_115 = 1 ;
F_22 ( V_179 != - 1 ) ;
}
F_22 ( V_179 < 0 && V_115 < - V_179 ) ;
V_115 += V_179 ;
if ( V_115 > 0 ) {
if ( type == V_154 )
F_113 ( V_64 , V_172 , V_115 ) ;
else
F_108 ( V_64 , V_178 , V_115 ) ;
} else {
V_54 = F_126 ( type ) ;
V_121 = F_78 ( V_64 , V_62 -> V_79 [ 0 ] ) ;
V_169 = ( unsigned long ) V_162 ;
V_29 = ( unsigned long ) V_120 + V_121 ;
if ( V_169 + V_54 < V_29 )
F_132 ( V_64 , V_169 , V_169 + V_54 ,
V_29 - V_169 - V_54 ) ;
V_121 -= V_54 ;
F_137 ( V_83 , V_33 , V_62 , V_121 , 1 ) ;
}
F_96 ( V_64 ) ;
}
static T_5
int F_138 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_61 * V_62 ,
T_2 V_25 , T_2 V_34 , T_2 V_16 ,
T_2 V_145 , T_2 V_105 ,
T_2 V_31 , int V_156 ,
struct V_176 * V_130 )
{
struct V_161 * V_162 ;
int V_27 ;
V_27 = F_125 ( V_83 , V_33 , V_62 , & V_162 ,
V_25 , V_34 , V_16 ,
V_145 , V_105 , V_31 , 1 ) ;
if ( V_27 == 0 ) {
F_22 ( V_105 < V_142 ) ;
F_136 ( V_83 , V_33 , V_62 , V_162 ,
V_156 , V_130 ) ;
} else if ( V_27 == - V_152 ) {
F_130 ( V_83 , V_33 , V_62 , V_162 , V_16 ,
V_145 , V_105 , V_31 ,
V_156 , V_130 ) ;
V_27 = 0 ;
}
return V_27 ;
}
static int F_139 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_61 * V_62 ,
T_2 V_25 , T_2 V_16 , T_2 V_145 ,
T_2 V_105 , T_2 V_31 , int V_156 )
{
int V_27 ;
if ( V_105 < V_142 ) {
F_22 ( V_156 != 1 ) ;
V_27 = F_122 ( V_83 , V_33 , V_62 , V_25 ,
V_16 , V_145 ) ;
} else {
V_27 = F_106 ( V_83 , V_33 , V_62 , V_25 ,
V_16 , V_145 ,
V_105 , V_31 , V_156 ) ;
}
return V_27 ;
}
static int F_140 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_61 * V_62 ,
struct V_161 * V_162 ,
int V_158 , int V_180 )
{
int V_27 = 0 ;
F_22 ( ! V_180 && V_158 != 1 ) ;
if ( V_162 ) {
F_136 ( V_83 , V_33 , V_62 , V_162 ,
- V_158 , NULL ) ;
} else if ( V_180 ) {
V_27 = F_115 ( V_83 , V_33 , V_62 , V_158 ) ;
} else {
V_27 = F_117 ( V_83 , V_33 , V_62 ) ;
}
return V_27 ;
}
static int F_141 ( struct V_181 * V_182 ,
T_2 V_30 , T_2 V_114 )
{
return F_142 ( V_182 , V_30 >> 9 , V_114 >> 9 , V_38 , 0 ) ;
}
static int F_143 ( struct V_32 * V_33 , T_2 V_25 ,
T_2 V_34 , T_2 * V_183 )
{
int V_27 ;
T_2 V_184 = 0 ;
struct V_185 * V_186 = NULL ;
V_27 = F_144 ( V_33 -> V_35 , V_187 ,
V_25 , & V_34 , & V_186 , 0 ) ;
if ( ! V_27 ) {
struct V_188 * V_189 = V_186 -> V_190 ;
int V_41 ;
for ( V_41 = 0 ; V_41 < V_186 -> V_191 ; V_41 ++ , V_189 ++ ) {
if ( ! V_189 -> V_192 -> V_193 )
continue;
V_27 = F_141 ( V_189 -> V_192 -> V_182 ,
V_189 -> V_194 ,
V_189 -> V_195 ) ;
if ( ! V_27 )
V_184 += V_189 -> V_195 ;
else if ( V_27 != - V_196 )
break;
V_27 = 0 ;
}
F_9 ( V_186 ) ;
}
if ( V_183 )
* V_183 = V_184 ;
return V_27 ;
}
int F_145 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
T_2 V_25 , T_2 V_34 , T_2 V_16 ,
T_2 V_145 , T_2 V_105 , T_2 V_31 , int V_197 )
{
int V_27 ;
struct V_11 * V_35 = V_33 -> V_35 ;
F_22 ( V_105 < V_142 &&
V_145 == V_198 ) ;
if ( V_105 < V_142 ) {
V_27 = F_146 ( V_35 , V_83 , V_25 ,
V_34 ,
V_16 , V_145 , ( int ) V_105 ,
V_199 , NULL , V_197 ) ;
} else {
V_27 = F_147 ( V_35 , V_83 , V_25 ,
V_34 ,
V_16 , V_145 , V_105 , V_31 ,
V_199 , NULL , V_197 ) ;
}
return V_27 ;
}
static int F_148 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
T_2 V_25 , T_2 V_34 ,
T_2 V_16 , T_2 V_145 ,
T_2 V_105 , T_2 V_31 , int V_156 ,
struct V_176 * V_130 )
{
struct V_61 * V_62 ;
struct V_63 * V_64 ;
struct V_119 * V_111 ;
T_2 V_115 ;
int V_27 ;
int V_77 = 0 ;
V_62 = F_32 () ;
if ( ! V_62 )
return - V_85 ;
V_62 -> V_72 = 1 ;
V_62 -> V_200 = 1 ;
V_27 = F_138 ( V_83 , V_33 -> V_35 -> V_60 ,
V_62 , V_25 , V_34 , V_16 ,
V_145 , V_105 , V_31 ,
V_156 , V_130 ) ;
if ( V_27 == 0 )
goto V_69;
if ( V_27 != - V_174 ) {
V_77 = V_27 ;
goto V_69;
}
V_64 = V_62 -> V_78 [ 0 ] ;
V_111 = F_79 ( V_64 , V_62 -> V_79 [ 0 ] , struct V_119 ) ;
V_115 = F_80 ( V_64 , V_111 ) ;
F_91 ( V_64 , V_111 , V_115 + V_156 ) ;
if ( V_130 )
F_131 ( V_130 , V_64 , V_111 ) ;
F_96 ( V_64 ) ;
F_43 ( V_62 ) ;
V_62 -> V_72 = 1 ;
V_62 -> V_200 = 1 ;
V_27 = F_139 ( V_83 , V_33 -> V_35 -> V_60 ,
V_62 , V_25 , V_16 , V_145 ,
V_105 , V_31 , V_156 ) ;
if ( V_27 )
F_149 ( V_83 , V_33 , V_27 ) ;
V_69:
F_48 ( V_62 ) ;
return V_77 ;
}
static int F_150 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_201 * V_129 ,
struct V_176 * V_130 ,
int V_202 )
{
int V_27 = 0 ;
struct V_203 * V_150 ;
struct V_65 V_204 ;
T_2 V_16 = 0 ;
T_2 V_205 = 0 ;
T_2 V_6 = 0 ;
V_204 . V_21 = V_129 -> V_25 ;
V_204 . V_31 = V_129 -> V_34 ;
V_204 . type = V_73 ;
V_150 = F_151 ( V_129 ) ;
if ( V_129 -> type == V_153 )
V_16 = V_150 -> V_16 ;
else
V_205 = V_150 -> V_33 ;
if ( V_129 -> V_206 == V_199 && V_202 ) {
if ( V_130 ) {
F_22 ( V_130 -> V_207 ) ;
V_6 |= V_130 -> V_132 ;
}
V_27 = F_152 ( V_83 , V_33 ,
V_16 , V_205 , V_6 ,
V_150 -> V_21 , V_150 -> V_31 ,
& V_204 , V_129 -> V_133 ) ;
} else if ( V_129 -> V_206 == V_199 ) {
V_27 = F_148 ( V_83 , V_33 , V_129 -> V_25 ,
V_129 -> V_34 , V_16 ,
V_205 , V_150 -> V_21 ,
V_150 -> V_31 , V_129 -> V_133 ,
V_130 ) ;
} else if ( V_129 -> V_206 == V_208 ) {
V_27 = F_153 ( V_83 , V_33 , V_129 -> V_25 ,
V_129 -> V_34 , V_16 ,
V_205 , V_150 -> V_21 ,
V_150 -> V_31 , V_129 -> V_133 ,
V_130 ) ;
} else {
F_84 () ;
}
return V_27 ;
}
static void F_131 ( struct V_176 * V_130 ,
struct V_63 * V_64 ,
struct V_119 * V_120 )
{
T_2 V_6 = F_81 ( V_64 , V_120 ) ;
if ( V_130 -> V_131 ) {
V_6 |= V_130 -> V_132 ;
F_93 ( V_64 , V_120 , V_6 ) ;
}
if ( V_130 -> V_207 ) {
struct V_137 * V_138 ;
F_22 ( ! ( V_6 & V_143 ) ) ;
V_138 = (struct V_137 * ) ( V_120 + 1 ) ;
F_154 ( V_64 , V_138 , & V_130 -> V_20 ) ;
}
}
static int F_155 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_201 * V_129 ,
struct V_176 * V_130 )
{
struct V_65 V_20 ;
struct V_61 * V_62 ;
struct V_119 * V_120 ;
struct V_63 * V_64 ;
T_3 V_121 ;
int V_27 ;
int V_77 = 0 ;
if ( V_83 -> V_209 )
return 0 ;
V_62 = F_32 () ;
if ( ! V_62 )
return - V_85 ;
V_20 . V_21 = V_129 -> V_25 ;
V_20 . type = V_73 ;
V_20 . V_31 = V_129 -> V_34 ;
V_62 -> V_72 = 1 ;
V_62 -> V_200 = 1 ;
V_27 = F_36 ( V_83 , V_33 -> V_35 -> V_60 , & V_20 ,
V_62 , 0 , 1 ) ;
if ( V_27 < 0 ) {
V_77 = V_27 ;
goto V_69;
}
if ( V_27 > 0 ) {
V_77 = - V_210 ;
goto V_69;
}
V_64 = V_62 -> V_78 [ 0 ] ;
V_121 = F_78 ( V_64 , V_62 -> V_79 [ 0 ] ) ;
#ifdef F_82
if ( V_121 < sizeof( * V_120 ) ) {
V_27 = F_88 ( V_83 , V_33 -> V_35 -> V_60 ,
V_62 , ( T_2 ) - 1 , 0 ) ;
if ( V_27 < 0 ) {
V_77 = V_27 ;
goto V_69;
}
V_64 = V_62 -> V_78 [ 0 ] ;
V_121 = F_78 ( V_64 , V_62 -> V_79 [ 0 ] ) ;
}
#endif
F_22 ( V_121 < sizeof( * V_120 ) ) ;
V_120 = F_79 ( V_64 , V_62 -> V_79 [ 0 ] , struct V_119 ) ;
F_131 ( V_130 , V_64 , V_120 ) ;
F_96 ( V_64 ) ;
V_69:
F_48 ( V_62 ) ;
return V_77 ;
}
static int F_156 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_201 * V_129 ,
struct V_176 * V_130 ,
int V_202 )
{
int V_27 = 0 ;
struct V_211 * V_150 ;
struct V_65 V_204 ;
T_2 V_16 = 0 ;
T_2 V_205 = 0 ;
V_204 . V_21 = V_129 -> V_25 ;
V_204 . V_31 = V_129 -> V_34 ;
V_204 . type = V_73 ;
V_150 = F_157 ( V_129 ) ;
if ( V_129 -> type == V_163 )
V_16 = V_150 -> V_16 ;
else
V_205 = V_150 -> V_33 ;
F_22 ( V_129 -> V_133 != 1 ) ;
if ( V_129 -> V_206 == V_199 && V_202 ) {
F_22 ( ! V_130 || ! V_130 -> V_131 ||
! V_130 -> V_207 ) ;
V_27 = F_158 ( V_83 , V_33 ,
V_16 , V_205 ,
V_130 -> V_132 ,
& V_130 -> V_20 ,
V_150 -> V_165 , & V_204 ) ;
} else if ( V_129 -> V_206 == V_199 ) {
V_27 = F_148 ( V_83 , V_33 , V_129 -> V_25 ,
V_129 -> V_34 , V_16 , V_205 ,
V_150 -> V_165 , 0 , 1 , V_130 ) ;
} else if ( V_129 -> V_206 == V_208 ) {
V_27 = F_153 ( V_83 , V_33 , V_129 -> V_25 ,
V_129 -> V_34 , V_16 , V_205 ,
V_150 -> V_165 , 0 , 1 , V_130 ) ;
} else {
F_84 () ;
}
return V_27 ;
}
static int F_159 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_201 * V_129 ,
struct V_176 * V_130 ,
int V_202 )
{
int V_27 = 0 ;
if ( V_83 -> V_209 )
return 0 ;
if ( F_160 ( V_129 ) ) {
struct V_116 * V_98 ;
F_22 ( V_130 ) ;
V_98 = F_161 ( V_129 ) ;
if ( V_202 ) {
F_162 ( V_33 , V_129 -> V_25 ,
V_129 -> V_34 , 1 ) ;
if ( V_98 -> V_180 ) {
V_27 = F_163 ( V_83 , V_33 ,
V_129 -> V_25 ,
V_129 -> V_34 ) ;
}
}
F_45 ( & V_98 -> V_75 ) ;
return V_27 ;
}
if ( V_129 -> type == V_164 ||
V_129 -> type == V_163 )
V_27 = F_156 ( V_83 , V_33 , V_129 , V_130 ,
V_202 ) ;
else if ( V_129 -> type == V_154 ||
V_129 -> type == V_153 )
V_27 = F_150 ( V_83 , V_33 , V_129 , V_130 ,
V_202 ) ;
else
F_84 () ;
return V_27 ;
}
T_1 int F_164 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_97 * V_212 )
{
struct V_117 * V_118 ;
struct V_201 * V_150 ;
struct V_116 * V_213 = NULL ;
struct V_176 * V_130 ;
struct V_11 * V_35 = V_33 -> V_35 ;
int V_27 ;
int V_7 = 0 ;
int V_214 = 0 ;
V_118 = & V_83 -> V_128 -> V_118 ;
while ( 1 ) {
if ( ! V_213 ) {
if ( F_165 ( V_212 ) )
break;
V_213 = F_166 ( V_212 -> V_215 ,
struct V_116 , V_212 ) ;
V_27 = F_167 ( V_83 , V_213 ) ;
if ( V_27 == - V_174 ) {
V_213 = NULL ;
V_7 ++ ;
continue;
}
}
F_168 ( V_83 , V_35 , V_118 ,
V_213 ) ;
V_150 = F_169 ( V_213 ) ;
if ( V_150 && V_150 -> V_216 &&
F_170 ( V_35 , V_118 , V_150 -> V_216 ) ) {
F_171 ( & V_213 -> V_212 ) ;
F_45 ( & V_213 -> V_75 ) ;
V_213 = NULL ;
V_118 -> V_217 ++ ;
F_13 ( & V_118 -> V_49 ) ;
F_46 () ;
F_11 ( & V_118 -> V_49 ) ;
continue;
}
V_214 = V_213 -> V_214 ;
V_213 -> V_214 = 0 ;
V_130 = V_213 -> V_130 ;
V_213 -> V_130 = NULL ;
if ( ! V_150 ) {
V_150 = & V_213 -> V_129 ;
if ( V_130 && V_214 ) {
F_9 ( V_130 ) ;
V_130 = NULL ;
}
if ( V_130 ) {
F_13 ( & V_118 -> V_49 ) ;
V_27 = F_155 ( V_83 , V_33 ,
V_150 , V_130 ) ;
F_9 ( V_130 ) ;
if ( V_27 ) {
F_171 ( & V_213 -> V_212 ) ;
F_45 ( & V_213 -> V_75 ) ;
F_172 ( V_218 L_1 , V_27 ) ;
F_11 ( & V_118 -> V_49 ) ;
return V_27 ;
}
goto V_215;
}
F_171 ( & V_213 -> V_212 ) ;
V_213 = NULL ;
}
V_150 -> V_219 = 0 ;
F_173 ( & V_150 -> V_14 , & V_118 -> V_33 ) ;
V_118 -> V_220 -- ;
if ( V_213 ) {
switch ( V_150 -> V_206 ) {
case V_199 :
case V_221 :
V_213 -> V_129 . V_133 -= V_150 -> V_133 ;
break;
case V_208 :
V_213 -> V_129 . V_133 += V_150 -> V_133 ;
break;
default:
F_8 ( 1 ) ;
}
}
F_13 ( & V_118 -> V_49 ) ;
V_27 = F_159 ( V_83 , V_33 , V_150 , V_130 ,
V_214 ) ;
F_87 ( V_150 ) ;
F_9 ( V_130 ) ;
V_7 ++ ;
if ( V_27 ) {
if ( V_213 ) {
F_171 ( & V_213 -> V_212 ) ;
F_45 ( & V_213 -> V_75 ) ;
}
F_172 ( V_218 L_2 , V_27 ) ;
F_11 ( & V_118 -> V_49 ) ;
return V_27 ;
}
V_215:
F_46 () ;
F_11 ( & V_118 -> V_49 ) ;
}
return V_7 ;
}
static T_2 F_174 ( struct V_222 * V_33 )
{
struct V_14 * V_28 = V_33 -> V_14 ;
struct V_201 * V_223 ;
int V_224 = 1 ;
T_2 V_225 ;
T_2 V_226 = 0 , V_67 = 0 ;
V_28 = F_175 ( V_33 ) ;
if ( V_28 ) {
V_223 = F_12 ( V_28 , struct V_201 , V_14 ) ;
V_226 = V_223 -> V_25 ;
}
V_28 = F_176 ( V_33 ) ;
if ( V_28 ) {
V_223 = F_12 ( V_28 , struct V_201 , V_14 ) ;
V_67 = V_223 -> V_25 ;
}
V_28 = V_33 -> V_14 ;
while ( V_28 ) {
V_223 = F_12 ( V_28 , struct V_201 , V_14 ) ;
F_8 ( ! V_223 -> V_219 ) ;
V_225 = V_223 -> V_25 ;
if ( V_224 )
V_28 = V_28 -> V_22 ;
else
V_28 = V_28 -> V_23 ;
V_224 = 1 - V_224 ;
}
return V_225 ;
}
int F_177 ( struct V_82 * V_83 ,
struct V_11 * V_35 )
{
struct V_227 * V_227 ;
int V_27 = 0 ;
if ( F_165 ( & V_83 -> V_228 ) !=
! V_83 -> V_229 . V_216 ) {
F_172 ( V_230 L_3 ,
F_165 ( & V_83 -> V_228 ) ? L_4 : L_5 ,
V_83 -> V_229 . V_216 ) ;
F_84 () ;
}
if ( ! V_83 -> V_229 . V_216 )
return 0 ;
while ( ! F_165 ( & V_83 -> V_228 ) ) {
V_227 = F_178 ( & V_83 -> V_228 ,
struct V_227 , V_86 ) ;
F_179 ( & V_227 -> V_86 ) ;
if ( ! V_27 )
V_27 = F_180 (
V_83 , V_35 , V_227 -> V_129 ,
V_227 -> V_130 ) ;
F_9 ( V_227 ) ;
}
F_181 ( V_35 , & V_83 -> V_229 ) ;
return V_27 ;
}
int F_182 ( struct V_82 * V_83 ,
struct V_32 * V_33 , unsigned long V_7 )
{
struct V_14 * V_129 ;
struct V_117 * V_118 ;
struct V_201 * V_150 ;
struct V_97 V_212 ;
int V_27 ;
T_2 V_231 ;
int V_232 = V_7 == ( unsigned long ) - 1 ;
int V_233 = 0 ;
int V_234 ;
if ( V_83 -> V_209 )
return 0 ;
if ( V_33 == V_33 -> V_35 -> V_60 )
V_33 = V_33 -> V_35 -> V_235 ;
F_177 ( V_83 , V_33 -> V_35 ) ;
V_118 = & V_83 -> V_128 -> V_118 ;
F_52 ( & V_212 ) ;
V_74:
V_234 = 0 ;
F_11 ( & V_118 -> V_49 ) ;
#ifdef F_183
V_118 -> V_236 = F_174 ( & V_118 -> V_33 ) ;
#endif
if ( V_7 == 0 ) {
V_7 = V_118 -> V_220 * 2 ;
V_233 = 1 ;
}
while ( 1 ) {
if ( ! ( V_232 || V_233 ) &&
V_118 -> V_217 < 64 )
break;
V_231 = V_118 -> V_236 ;
V_27 = F_184 ( V_83 , & V_212 ,
V_118 -> V_236 ) ;
if ( V_27 )
break;
V_27 = F_164 ( V_83 , V_33 , & V_212 ) ;
if ( V_27 < 0 ) {
F_13 ( & V_118 -> V_49 ) ;
F_149 ( V_83 , V_33 , V_27 ) ;
return V_27 ;
}
V_7 -= F_185 (unsigned long, ret, count) ;
if ( V_7 == 0 )
break;
if ( V_231 >= V_118 -> V_236 ) {
if ( V_234 == 0 ) {
V_234 = 1 ;
} else {
F_22 ( V_232 ) ;
break;
}
}
if ( V_27 ) {
V_234 = 0 ;
}
}
if ( V_232 ) {
if ( ! F_165 ( & V_83 -> V_237 ) ) {
F_13 ( & V_118 -> V_49 ) ;
F_186 ( V_83 , V_33 ) ;
F_11 ( & V_118 -> V_49 ) ;
}
V_129 = F_175 ( & V_118 -> V_33 ) ;
if ( ! V_129 )
goto V_69;
V_7 = ( unsigned long ) - 1 ;
while ( V_129 ) {
V_150 = F_12 ( V_129 , struct V_201 ,
V_14 ) ;
if ( F_160 ( V_150 ) ) {
struct V_116 * V_98 ;
V_98 = F_161 ( V_150 ) ;
F_5 ( & V_150 -> V_115 ) ;
F_13 ( & V_118 -> V_49 ) ;
F_34 ( & V_98 -> V_75 ) ;
F_45 ( & V_98 -> V_75 ) ;
F_87 ( V_150 ) ;
F_46 () ;
goto V_74;
}
V_129 = F_187 ( V_129 ) ;
}
F_13 ( & V_118 -> V_49 ) ;
F_188 ( 1 ) ;
goto V_74;
}
V_69:
F_13 ( & V_118 -> V_49 ) ;
F_189 ( V_83 ) ;
return 0 ;
}
int F_190 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
T_2 V_25 , T_2 V_34 , T_2 V_6 ,
int V_180 )
{
struct V_176 * V_130 ;
int V_27 ;
V_130 = F_191 ( sizeof( * V_130 ) , V_38 ) ;
if ( ! V_130 )
return - V_85 ;
V_130 -> V_132 = V_6 ;
V_130 -> V_131 = 1 ;
V_130 -> V_207 = 0 ;
V_130 -> V_180 = V_180 ? 1 : 0 ;
V_27 = F_192 ( V_33 -> V_35 , V_83 , V_25 ,
V_34 , V_130 ) ;
if ( V_27 )
F_9 ( V_130 ) ;
return V_27 ;
}
static T_1 int F_193 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_61 * V_62 ,
T_2 V_21 , T_2 V_31 , T_2 V_25 )
{
struct V_116 * V_98 ;
struct V_201 * V_150 ;
struct V_203 * V_238 ;
struct V_117 * V_118 ;
struct V_14 * V_129 ;
int V_27 = 0 ;
V_27 = - V_152 ;
V_118 = & V_83 -> V_128 -> V_118 ;
F_11 ( & V_118 -> V_49 ) ;
V_98 = F_85 ( V_83 , V_25 ) ;
if ( ! V_98 )
goto V_69;
if ( ! F_86 ( & V_98 -> V_75 ) ) {
F_5 ( & V_98 -> V_129 . V_115 ) ;
F_13 ( & V_118 -> V_49 ) ;
F_43 ( V_62 ) ;
F_34 ( & V_98 -> V_75 ) ;
F_45 ( & V_98 -> V_75 ) ;
F_87 ( & V_98 -> V_129 ) ;
return - V_174 ;
}
V_129 = F_194 ( & V_98 -> V_129 . V_14 ) ;
if ( ! V_129 )
goto V_239;
V_150 = F_12 ( V_129 , struct V_201 , V_14 ) ;
if ( V_150 -> V_25 != V_25 )
goto V_239;
V_27 = 1 ;
if ( V_150 -> type != V_154 )
goto V_239;
V_238 = F_151 ( V_150 ) ;
V_129 = F_194 ( V_129 ) ;
if ( V_129 ) {
int V_216 = V_150 -> V_216 ;
V_150 = F_12 ( V_129 , struct V_201 , V_14 ) ;
if ( V_150 -> V_25 == V_25 && V_150 -> V_216 == V_216 )
goto V_239;
}
if ( V_238 -> V_33 != V_33 -> V_240 . V_21 ||
V_238 -> V_21 != V_21 || V_238 -> V_31 != V_31 )
goto V_239;
V_27 = 0 ;
V_239:
F_45 ( & V_98 -> V_75 ) ;
V_69:
F_13 ( & V_118 -> V_49 ) ;
return V_27 ;
}
static T_1 int F_195 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_61 * V_62 ,
T_2 V_21 , T_2 V_31 , T_2 V_25 )
{
struct V_32 * V_60 = V_33 -> V_35 -> V_60 ;
struct V_63 * V_64 ;
struct V_149 * V_150 ;
struct V_161 * V_162 ;
struct V_119 * V_120 ;
struct V_65 V_20 ;
T_3 V_121 ;
int V_27 ;
V_20 . V_21 = V_25 ;
V_20 . V_31 = ( T_2 ) - 1 ;
V_20 . type = V_73 ;
V_27 = F_36 ( NULL , V_60 , & V_20 , V_62 , 0 , 0 ) ;
if ( V_27 < 0 )
goto V_69;
F_22 ( V_27 == 0 ) ;
V_27 = - V_152 ;
if ( V_62 -> V_79 [ 0 ] == 0 )
goto V_69;
V_62 -> V_79 [ 0 ] -- ;
V_64 = V_62 -> V_78 [ 0 ] ;
F_39 ( V_64 , & V_20 , V_62 -> V_79 [ 0 ] ) ;
if ( V_20 . V_21 != V_25 || V_20 . type != V_73 )
goto V_69;
V_27 = 1 ;
V_121 = F_78 ( V_64 , V_62 -> V_79 [ 0 ] ) ;
#ifdef F_82
if ( V_121 < sizeof( * V_120 ) ) {
F_8 ( V_121 != sizeof( struct V_125 ) ) ;
goto V_69;
}
#endif
V_120 = F_79 ( V_64 , V_62 -> V_79 [ 0 ] , struct V_119 ) ;
if ( V_121 != sizeof( * V_120 ) +
F_126 ( V_154 ) )
goto V_69;
if ( F_196 ( V_64 , V_120 ) <=
F_197 ( & V_33 -> V_241 ) )
goto V_69;
V_162 = (struct V_161 * ) ( V_120 + 1 ) ;
if ( F_120 ( V_64 , V_162 ) !=
V_154 )
goto V_69;
V_150 = (struct V_149 * ) ( & V_162 -> V_31 ) ;
if ( F_80 ( V_64 , V_120 ) !=
F_114 ( V_64 , V_150 ) ||
F_101 ( V_64 , V_150 ) !=
V_33 -> V_240 . V_21 ||
F_102 ( V_64 , V_150 ) != V_21 ||
F_103 ( V_64 , V_150 ) != V_31 )
goto V_69;
V_27 = 0 ;
V_69:
return V_27 ;
}
int F_198 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
T_2 V_21 , T_2 V_31 , T_2 V_25 )
{
struct V_61 * V_62 ;
int V_27 ;
int V_242 ;
V_62 = F_32 () ;
if ( ! V_62 )
return - V_152 ;
do {
V_27 = F_195 ( V_83 , V_33 , V_62 , V_21 ,
V_31 , V_25 ) ;
if ( V_27 && V_27 != - V_152 )
goto V_69;
V_242 = F_193 ( V_83 , V_33 , V_62 , V_21 ,
V_31 , V_25 ) ;
} while ( V_242 == - V_174 );
if ( V_242 && V_242 != - V_152 ) {
V_27 = V_242 ;
goto V_69;
}
if ( V_27 != - V_152 || V_242 != - V_152 )
V_27 = 0 ;
V_69:
F_48 ( V_62 ) ;
if ( V_33 -> V_240 . V_21 == V_243 )
F_8 ( V_27 > 0 ) ;
return V_27 ;
}
static int F_199 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_63 * V_244 ,
int V_245 , int V_246 , int V_197 )
{
T_2 V_25 ;
T_2 V_34 ;
T_2 V_16 ;
T_2 V_205 ;
T_3 V_68 ;
struct V_65 V_20 ;
struct V_247 * V_248 ;
int V_41 ;
int V_165 ;
int V_27 = 0 ;
int (* F_200)( struct V_82 * , struct V_32 * ,
T_2 , T_2 , T_2 , T_2 , T_2 , T_2 , int );
V_205 = F_201 ( V_244 ) ;
V_68 = F_37 ( V_244 ) ;
V_165 = F_202 ( V_244 ) ;
if ( ! V_33 -> V_249 && V_165 == 0 )
return 0 ;
if ( V_246 )
F_200 = F_145 ;
else
F_200 = V_250 ;
if ( V_245 )
V_16 = V_244 -> V_30 ;
else
V_16 = 0 ;
for ( V_41 = 0 ; V_41 < V_68 ; V_41 ++ ) {
if ( V_165 == 0 ) {
F_39 ( V_244 , & V_20 , V_41 ) ;
if ( F_203 ( & V_20 ) != V_251 )
continue;
V_248 = F_79 ( V_244 , V_41 ,
struct V_247 ) ;
if ( F_204 ( V_244 , V_248 ) ==
V_252 )
continue;
V_25 = F_205 ( V_244 , V_248 ) ;
if ( V_25 == 0 )
continue;
V_34 = F_206 ( V_244 , V_248 ) ;
V_20 . V_31 -= F_207 ( V_244 , V_248 ) ;
V_27 = F_200 ( V_83 , V_33 , V_25 , V_34 ,
V_16 , V_205 , V_20 . V_21 ,
V_20 . V_31 , V_197 ) ;
if ( V_27 )
goto V_155;
} else {
V_25 = F_208 ( V_244 , V_41 ) ;
V_34 = F_209 ( V_33 , V_165 - 1 ) ;
V_27 = F_200 ( V_83 , V_33 , V_25 , V_34 ,
V_16 , V_205 , V_165 - 1 , 0 ,
V_197 ) ;
if ( V_27 )
goto V_155;
}
}
return 0 ;
V_155:
return V_27 ;
}
int F_210 ( struct V_82 * V_83 , struct V_32 * V_33 ,
struct V_63 * V_244 , int V_245 , int V_197 )
{
return F_199 ( V_83 , V_33 , V_244 , V_245 , 1 , V_197 ) ;
}
int F_211 ( struct V_82 * V_83 , struct V_32 * V_33 ,
struct V_63 * V_244 , int V_245 , int V_197 )
{
return F_199 ( V_83 , V_33 , V_244 , V_245 , 0 , V_197 ) ;
}
static int F_212 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_61 * V_62 ,
struct V_1 * V_2 )
{
int V_27 ;
struct V_32 * V_60 = V_33 -> V_35 -> V_60 ;
unsigned long V_138 ;
struct V_63 * V_64 ;
V_27 = F_36 ( V_83 , V_60 , & V_2 -> V_20 , V_62 , 0 , 1 ) ;
if ( V_27 < 0 )
goto V_155;
F_22 ( V_27 ) ;
V_64 = V_62 -> V_78 [ 0 ] ;
V_138 = F_213 ( V_64 , V_62 -> V_79 [ 0 ] ) ;
F_214 ( V_64 , & V_2 -> V_111 , V_138 , sizeof( V_2 -> V_111 ) ) ;
F_96 ( V_64 ) ;
F_43 ( V_62 ) ;
V_155:
if ( V_27 ) {
F_149 ( V_83 , V_33 , V_27 ) ;
return V_27 ;
}
return 0 ;
}
static struct V_1 *
F_215 ( struct V_32 * V_33 ,
struct V_1 * V_2 )
{
struct V_14 * V_129 ;
F_11 ( & V_33 -> V_35 -> V_17 ) ;
V_129 = F_187 ( & V_2 -> V_19 ) ;
F_6 ( V_2 ) ;
if ( V_129 ) {
V_2 = F_12 ( V_129 , struct V_1 ,
V_19 ) ;
F_4 ( V_2 ) ;
} else
V_2 = NULL ;
F_13 ( & V_33 -> V_35 -> V_17 ) ;
return V_2 ;
}
static int F_216 ( struct V_1 * V_13 ,
struct V_82 * V_83 ,
struct V_61 * V_62 )
{
struct V_32 * V_33 = V_13 -> V_35 -> V_235 ;
struct V_253 * V_253 = NULL ;
T_2 V_254 = 0 ;
int V_255 = V_256 ;
int V_257 = 0 ;
int V_258 = 0 ;
int V_27 = 0 ;
if ( V_13 -> V_20 . V_31 < ( 100 * 1024 * 1024 ) ) {
F_11 ( & V_13 -> V_49 ) ;
V_13 -> V_259 = V_260 ;
F_13 ( & V_13 -> V_49 ) ;
return 0 ;
}
V_74:
V_253 = F_217 ( V_33 , V_13 , V_62 ) ;
if ( F_218 ( V_253 ) && F_219 ( V_253 ) != - V_152 ) {
V_27 = F_219 ( V_253 ) ;
F_43 ( V_62 ) ;
goto V_69;
}
if ( F_218 ( V_253 ) ) {
F_22 ( V_258 ) ;
V_258 ++ ;
if ( V_13 -> V_112 )
goto V_124;
V_27 = F_220 ( V_33 , V_83 , V_13 , V_62 ) ;
if ( V_27 )
goto V_124;
goto V_74;
}
if ( V_13 -> V_261 == V_83 -> V_262 &&
F_221 ( V_253 ) ) {
V_255 = V_263 ;
goto V_264;
}
F_222 ( V_253 ) -> V_265 = 0 ;
V_27 = F_223 ( V_83 , V_33 , V_253 ) ;
F_8 ( V_27 ) ;
if ( F_221 ( V_253 ) > 0 ) {
V_27 = F_224 ( V_33 , V_83 , V_62 ,
V_253 ) ;
if ( V_27 )
goto V_264;
}
F_11 ( & V_13 -> V_49 ) ;
if ( V_13 -> V_3 != V_4 ||
! F_225 ( V_33 , V_266 ) ) {
V_255 = V_260 ;
F_13 ( & V_13 -> V_49 ) ;
goto V_264;
}
F_13 ( & V_13 -> V_49 ) ;
V_257 = ( int ) F_226 ( V_13 -> V_20 . V_31 , 256 * 1024 * 1024 ) ;
if ( ! V_257 )
V_257 = 1 ;
V_257 *= 16 ;
V_257 *= V_267 ;
V_27 = F_227 ( V_253 , V_257 ) ;
if ( V_27 )
goto V_264;
V_27 = F_228 ( V_253 , V_83 , 0 , 0 , V_257 ,
V_257 , V_257 ,
& V_254 ) ;
if ( ! V_27 )
V_255 = V_263 ;
F_229 ( V_253 , V_257 ) ;
V_264:
F_230 ( V_253 ) ;
V_124:
F_43 ( V_62 ) ;
V_69:
F_11 ( & V_13 -> V_49 ) ;
if ( ! V_27 && V_255 == V_263 )
V_13 -> V_261 = V_83 -> V_262 ;
V_13 -> V_259 = V_255 ;
F_13 ( & V_13 -> V_49 ) ;
return V_27 ;
}
int F_231 ( struct V_82 * V_83 ,
struct V_32 * V_33 )
{
struct V_1 * V_2 ;
int V_77 = 0 ;
struct V_61 * V_62 ;
T_2 V_67 = 0 ;
V_62 = F_32 () ;
if ( ! V_62 )
return - V_85 ;
V_74:
while ( 1 ) {
V_2 = F_64 ( V_33 -> V_35 , V_67 ) ;
while ( V_2 ) {
if ( V_2 -> V_259 == V_268 )
break;
V_2 = F_215 ( V_33 , V_2 ) ;
}
if ( ! V_2 ) {
if ( V_67 == 0 )
break;
V_67 = 0 ;
continue;
}
V_77 = F_216 ( V_2 , V_83 , V_62 ) ;
V_67 = V_2 -> V_20 . V_21 + V_2 -> V_20 . V_31 ;
F_6 ( V_2 ) ;
}
while ( 1 ) {
if ( V_67 == 0 ) {
V_77 = F_182 ( V_83 , V_33 ,
( unsigned long ) - 1 ) ;
if ( V_77 )
goto V_69;
}
V_2 = F_64 ( V_33 -> V_35 , V_67 ) ;
while ( V_2 ) {
if ( V_2 -> V_259 == V_268 ) {
F_6 ( V_2 ) ;
goto V_74;
}
if ( V_2 -> V_269 )
break;
V_2 = F_215 ( V_33 , V_2 ) ;
}
if ( ! V_2 ) {
if ( V_67 == 0 )
break;
V_67 = 0 ;
continue;
}
if ( V_2 -> V_259 == V_263 )
V_2 -> V_259 = V_270 ;
V_2 -> V_269 = 0 ;
V_67 = V_2 -> V_20 . V_21 + V_2 -> V_20 . V_31 ;
V_77 = F_212 ( V_83 , V_33 , V_62 , V_2 ) ;
if ( V_77 )
goto V_69;
F_6 ( V_2 ) ;
}
while ( 1 ) {
if ( V_67 == 0 ) {
V_77 = F_182 ( V_83 , V_33 ,
( unsigned long ) - 1 ) ;
if ( V_77 )
goto V_69;
}
V_2 = F_64 ( V_33 -> V_35 , V_67 ) ;
while ( V_2 ) {
if ( V_2 -> V_269 ) {
F_6 ( V_2 ) ;
goto V_74;
}
if ( V_2 -> V_259 == V_270 )
break;
V_2 = F_215 ( V_33 , V_2 ) ;
}
if ( ! V_2 ) {
if ( V_67 == 0 )
break;
V_67 = 0 ;
continue;
}
V_77 = F_232 ( V_33 , V_83 , V_2 , V_62 ) ;
if ( ! V_77 && V_2 -> V_259 == V_270 )
V_2 -> V_259 = V_260 ;
V_67 = V_2 -> V_20 . V_21 + V_2 -> V_20 . V_31 ;
F_6 ( V_2 ) ;
}
V_69:
F_48 ( V_62 ) ;
return V_77 ;
}
int F_233 ( struct V_32 * V_33 , T_2 V_25 )
{
struct V_1 * V_13 ;
int V_271 = 0 ;
V_13 = F_65 ( V_33 -> V_35 , V_25 ) ;
if ( ! V_13 || V_13 -> V_112 )
V_271 = 1 ;
if ( V_13 )
F_6 ( V_13 ) ;
return V_271 ;
}
static int F_234 ( struct V_11 * V_12 , T_2 V_6 ,
T_2 V_272 , T_2 V_273 ,
struct V_96 * * V_99 )
{
struct V_96 * V_100 ;
int V_41 ;
int V_109 ;
if ( V_6 & ( V_274 | V_275 |
V_276 ) )
V_109 = 2 ;
else
V_109 = 1 ;
V_100 = F_66 ( V_12 , V_6 ) ;
if ( V_100 ) {
F_11 ( & V_100 -> V_49 ) ;
V_100 -> V_272 += V_272 ;
V_100 -> V_277 += V_272 * V_109 ;
V_100 -> V_273 += V_273 ;
V_100 -> V_278 += V_273 * V_109 ;
V_100 -> V_102 = 0 ;
F_13 ( & V_100 -> V_49 ) ;
* V_99 = V_100 ;
return 0 ;
}
V_100 = F_51 ( sizeof( * V_100 ) , V_38 ) ;
if ( ! V_100 )
return - V_85 ;
for ( V_41 = 0 ; V_41 < V_279 ; V_41 ++ )
F_52 ( & V_100 -> V_280 [ V_41 ] ) ;
F_235 ( & V_100 -> V_281 ) ;
F_236 ( & V_100 -> V_49 ) ;
V_100 -> V_6 = V_6 & V_101 ;
V_100 -> V_272 = V_272 ;
V_100 -> V_277 = V_272 * V_109 ;
V_100 -> V_273 = V_273 ;
V_100 -> V_278 = V_273 * V_109 ;
V_100 -> V_282 = 0 ;
V_100 -> V_283 = 0 ;
V_100 -> V_284 = 0 ;
V_100 -> V_285 = 0 ;
V_100 -> V_102 = 0 ;
V_100 -> V_286 = V_287 ;
V_100 -> V_288 = 0 ;
V_100 -> V_289 = 0 ;
F_54 ( & V_100 -> V_81 ) ;
* V_99 = V_100 ;
F_237 ( & V_100 -> V_86 , & V_12 -> V_99 ) ;
if ( V_6 & V_290 )
V_12 -> V_291 = V_100 ;
return 0 ;
}
static void F_238 ( struct V_11 * V_35 , T_2 V_6 )
{
T_2 V_292 = F_239 ( V_6 ) &
V_293 ;
if ( V_6 & V_290 )
V_35 -> V_294 |= V_292 ;
if ( V_6 & V_113 )
V_35 -> V_295 |= V_292 ;
if ( V_6 & V_296 )
V_35 -> V_297 |= V_292 ;
}
static T_2 F_240 ( struct V_11 * V_35 , T_2 V_6 )
{
struct V_298 * V_299 = V_35 -> V_300 ;
T_2 V_301 = 0 ;
if ( ! V_299 )
return 0 ;
if ( V_6 & V_290 &&
V_299 -> V_302 . V_6 & V_303 ) {
V_301 = V_290 | V_299 -> V_302 . V_301 ;
} else if ( V_6 & V_296 &&
V_299 -> V_304 . V_6 & V_303 ) {
V_301 = V_296 | V_299 -> V_304 . V_301 ;
} else if ( V_6 & V_113 &&
V_299 -> V_305 . V_6 & V_303 ) {
V_301 = V_113 | V_299 -> V_305 . V_301 ;
}
return V_301 ;
}
T_2 F_241 ( struct V_32 * V_33 , T_2 V_6 )
{
T_2 V_306 = V_33 -> V_35 -> V_307 -> V_308 +
V_33 -> V_35 -> V_307 -> V_309 ;
T_2 V_301 ;
F_11 ( & V_33 -> V_35 -> V_310 ) ;
V_301 = F_240 ( V_33 -> V_35 , V_6 ) ;
if ( V_301 ) {
if ( ( V_6 & V_301 ) & V_293 ) {
F_13 ( & V_33 -> V_35 -> V_310 ) ;
return F_242 ( V_301 ) ;
}
}
F_13 ( & V_33 -> V_35 -> V_310 ) ;
if ( V_306 == 1 )
V_6 &= ~ ( V_275 | V_311 ) ;
if ( V_306 < 4 )
V_6 &= ~ V_276 ;
if ( ( V_6 & V_274 ) &&
( V_6 & ( V_275 |
V_276 ) ) ) {
V_6 &= ~ V_274 ;
}
if ( ( V_6 & V_275 ) &&
( V_6 & V_276 ) ) {
V_6 &= ~ V_275 ;
}
if ( ( V_6 & V_311 ) &&
( ( V_6 & V_275 ) |
( V_6 & V_276 ) |
( V_6 & V_274 ) ) ) {
V_6 &= ~ V_311 ;
}
return F_242 ( V_6 ) ;
}
static T_2 F_243 ( struct V_32 * V_33 , T_2 V_6 )
{
if ( V_6 & V_290 )
V_6 |= V_33 -> V_35 -> V_294 ;
else if ( V_6 & V_296 )
V_6 |= V_33 -> V_35 -> V_297 ;
else if ( V_6 & V_113 )
V_6 |= V_33 -> V_35 -> V_295 ;
return F_241 ( V_33 , V_6 ) ;
}
T_2 F_244 ( struct V_32 * V_33 , int V_302 )
{
T_2 V_6 ;
if ( V_302 )
V_6 = V_290 ;
else if ( V_33 == V_33 -> V_35 -> V_312 )
V_6 = V_296 ;
else
V_6 = V_113 ;
return F_243 ( V_33 , V_6 ) ;
}
int F_227 ( struct V_253 * V_253 , T_2 V_313 )
{
struct V_96 * V_291 ;
struct V_32 * V_33 = F_222 ( V_253 ) -> V_33 ;
struct V_11 * V_35 = V_33 -> V_35 ;
T_2 V_106 ;
int V_27 = 0 , V_314 = 0 , V_315 = 1 ;
V_313 = ( V_313 + V_33 -> V_316 - 1 ) & ~ ( ( T_2 ) V_33 -> V_316 - 1 ) ;
if ( V_33 == V_33 -> V_35 -> V_235 ||
F_222 ( V_253 ) -> V_317 . V_21 == V_318 ) {
V_315 = 0 ;
V_314 = 1 ;
}
V_291 = V_35 -> V_291 ;
if ( ! V_291 )
goto V_319;
V_74:
F_11 ( & V_291 -> V_49 ) ;
V_106 = V_291 -> V_273 + V_291 -> V_283 +
V_291 -> V_282 + V_291 -> V_284 +
V_291 -> V_285 ;
if ( V_106 + V_313 > V_291 -> V_272 ) {
struct V_82 * V_83 ;
if ( ! V_291 -> V_102 && V_315 ) {
T_2 V_320 ;
V_291 -> V_286 = V_321 ;
F_13 ( & V_291 -> V_49 ) ;
V_319:
V_320 = F_244 ( V_33 , 1 ) ;
V_83 = F_245 ( V_33 ) ;
if ( F_218 ( V_83 ) )
return F_219 ( V_83 ) ;
V_27 = F_246 ( V_83 , V_33 -> V_35 -> V_60 ,
V_320 ,
V_287 ) ;
F_247 ( V_83 , V_33 ) ;
if ( V_27 < 0 ) {
if ( V_27 != - V_322 )
return V_27 ;
else
goto V_323;
}
if ( ! V_291 )
V_291 = V_35 -> V_291 ;
goto V_74;
}
if ( V_291 -> V_282 < V_313 )
V_314 = 1 ;
F_13 ( & V_291 -> V_49 ) ;
V_323:
if ( ! V_314 &&
! F_248 ( & V_33 -> V_35 -> V_324 ) ) {
V_314 = 1 ;
V_83 = F_245 ( V_33 ) ;
if ( F_218 ( V_83 ) )
return F_219 ( V_83 ) ;
V_27 = F_249 ( V_83 , V_33 ) ;
if ( V_27 )
return V_27 ;
goto V_74;
}
return - V_322 ;
}
V_291 -> V_285 += V_313 ;
F_250 ( V_33 -> V_35 , L_6 ,
V_291 -> V_6 , V_313 , 1 ) ;
F_13 ( & V_291 -> V_49 ) ;
return 0 ;
}
void F_229 ( struct V_253 * V_253 , T_2 V_313 )
{
struct V_32 * V_33 = F_222 ( V_253 ) -> V_33 ;
struct V_96 * V_291 ;
V_313 = ( V_313 + V_33 -> V_316 - 1 ) & ~ ( ( T_2 ) V_33 -> V_316 - 1 ) ;
V_291 = V_33 -> V_35 -> V_291 ;
F_11 ( & V_291 -> V_49 ) ;
V_291 -> V_285 -= V_313 ;
F_250 ( V_33 -> V_35 , L_6 ,
V_291 -> V_6 , V_313 , 0 ) ;
F_13 ( & V_291 -> V_49 ) ;
}
static void F_251 ( struct V_11 * V_12 )
{
struct V_97 * V_98 = & V_12 -> V_99 ;
struct V_96 * V_100 ;
F_67 () ;
F_68 (found, head, list) {
if ( V_100 -> V_6 & V_113 )
V_100 -> V_286 = V_321 ;
}
F_69 () ;
}
static int F_252 ( struct V_32 * V_33 ,
struct V_96 * V_325 , int V_326 )
{
struct V_327 * V_328 = & V_33 -> V_35 -> V_329 ;
T_2 V_34 = V_325 -> V_272 - V_325 -> V_284 ;
T_2 V_330 = V_325 -> V_273 + V_325 -> V_283 ;
T_2 V_331 ;
if ( V_326 == V_321 )
return 1 ;
if ( V_325 -> V_6 & V_113 )
V_330 += V_328 -> V_54 ;
if ( V_326 == V_332 ) {
V_331 = F_253 ( V_33 -> V_35 -> V_333 ) ;
V_331 = F_33 ( T_2 , 64 * 1024 * 1024 ,
F_254 ( V_331 , 1 ) ) ;
if ( V_34 - V_330 < V_331 )
return 1 ;
}
if ( V_330 + 2 * 1024 * 1024 < F_74 ( V_34 , 8 ) )
return 0 ;
return 1 ;
}
static T_2 F_255 ( struct V_32 * V_33 , T_2 type )
{
T_2 V_334 ;
if ( type & V_276 ||
type & V_311 )
V_334 = V_33 -> V_35 -> V_307 -> V_308 ;
else if ( type & V_275 )
V_334 = 2 ;
else
V_334 = 1 ;
return F_256 ( V_33 , V_334 + 1 ) ;
}
static void F_257 ( struct V_82 * V_83 ,
struct V_32 * V_33 , T_2 type )
{
struct V_96 * V_12 ;
T_2 V_335 ;
T_2 V_331 ;
V_12 = F_66 ( V_33 -> V_35 , V_296 ) ;
F_11 ( & V_12 -> V_49 ) ;
V_335 = V_12 -> V_272 - V_12 -> V_273 - V_12 -> V_282 -
V_12 -> V_283 - V_12 -> V_284 ;
F_13 ( & V_12 -> V_49 ) ;
V_331 = F_255 ( V_33 , type ) ;
if ( V_335 < V_331 && F_225 ( V_33 , V_336 ) ) {
F_172 ( V_337 L_7 ,
V_335 , V_331 , type ) ;
F_258 ( V_12 , 0 , 0 ) ;
}
if ( V_335 < V_331 ) {
T_2 V_6 ;
V_6 = F_244 ( V_33 -> V_35 -> V_312 , 0 ) ;
F_259 ( V_83 , V_33 , V_6 ) ;
}
}
static int F_246 ( struct V_82 * V_83 ,
struct V_32 * V_60 , T_2 V_6 , int V_326 )
{
struct V_96 * V_99 ;
struct V_11 * V_35 = V_60 -> V_35 ;
int V_338 = 0 ;
int V_27 = 0 ;
V_99 = F_66 ( V_60 -> V_35 , V_6 ) ;
if ( ! V_99 ) {
V_27 = F_234 ( V_60 -> V_35 , V_6 ,
0 , 0 , & V_99 ) ;
F_22 ( V_27 ) ;
}
F_22 ( ! V_99 ) ;
V_74:
F_11 ( & V_99 -> V_49 ) ;
if ( V_326 < V_99 -> V_286 )
V_326 = V_99 -> V_286 ;
if ( V_99 -> V_102 ) {
F_13 ( & V_99 -> V_49 ) ;
return 0 ;
}
if ( ! F_252 ( V_60 , V_99 , V_326 ) ) {
F_13 ( & V_99 -> V_49 ) ;
return 0 ;
} else if ( V_99 -> V_288 ) {
V_338 = 1 ;
} else {
V_99 -> V_288 = 1 ;
}
F_13 ( & V_99 -> V_49 ) ;
F_34 ( & V_35 -> V_339 ) ;
if ( V_338 ) {
F_45 ( & V_35 -> V_339 ) ;
V_338 = 0 ;
goto V_74;
}
if ( F_260 ( V_99 ) )
V_6 |= ( V_290 | V_113 ) ;
if ( V_6 & V_290 && V_35 -> V_340 ) {
V_35 -> V_341 ++ ;
if ( ! ( V_35 -> V_341 %
V_35 -> V_340 ) )
F_251 ( V_35 ) ;
}
F_257 ( V_83 , V_60 , V_6 ) ;
V_27 = F_259 ( V_83 , V_60 , V_6 ) ;
if ( V_27 < 0 && V_27 != - V_322 )
goto V_69;
F_11 ( & V_99 -> V_49 ) ;
if ( V_27 )
V_99 -> V_102 = 1 ;
else
V_27 = 1 ;
V_99 -> V_286 = V_287 ;
V_99 -> V_288 = 0 ;
F_13 ( & V_99 -> V_49 ) ;
V_69:
F_45 ( & V_35 -> V_339 ) ;
return V_27 ;
}
static int F_261 ( struct V_32 * V_33 ,
struct V_96 * V_99 , T_2 V_313 ,
enum V_342 V_289 )
{
T_2 V_343 = F_244 ( V_33 , 0 ) ;
T_2 V_344 ;
T_2 V_106 ;
V_106 = V_99 -> V_273 + V_99 -> V_283 +
V_99 -> V_282 + V_99 -> V_284 +
V_99 -> V_285 ;
F_11 ( & V_33 -> V_35 -> V_345 ) ;
V_344 = V_33 -> V_35 -> V_346 ;
F_13 ( & V_33 -> V_35 -> V_345 ) ;
if ( V_343 & ( V_274 |
V_275 |
V_276 ) )
V_344 >>= 1 ;
if ( V_289 == V_347 )
V_344 >>= 3 ;
else
V_344 >>= 1 ;
if ( V_106 + V_313 < V_99 -> V_272 + V_344 )
return 1 ;
return 0 ;
}
static int F_262 ( struct V_348 * V_349 ,
unsigned long V_350 ,
enum V_351 V_352 )
{
if ( ! F_263 ( V_349 -> V_353 ) &&
F_264 ( & V_349 -> V_354 ) ) {
F_265 ( V_349 , V_350 , V_352 ) ;
F_44 ( & V_349 -> V_354 ) ;
return 1 ;
}
return 0 ;
}
static void F_266 ( struct V_32 * V_33 , T_2 V_355 , T_2 V_356 ,
bool V_357 )
{
struct V_327 * V_358 ;
struct V_96 * V_99 ;
struct V_82 * V_83 ;
T_2 V_359 ;
T_2 V_360 ;
long V_361 ;
unsigned long V_350 = ( 2 * 1024 * 1024 ) >> V_362 ;
int V_234 = 0 ;
enum V_342 V_289 ;
V_83 = (struct V_82 * ) V_363 -> V_364 ;
V_358 = & V_33 -> V_35 -> V_365 ;
V_99 = V_358 -> V_99 ;
F_2 () ;
V_359 = V_33 -> V_35 -> V_359 ;
if ( V_359 == 0 ) {
if ( V_83 )
return;
F_267 ( V_33 , 0 ) ;
return;
}
while ( V_359 && V_234 < 3 ) {
V_360 = F_268 ( V_359 , V_355 ) ;
V_350 = V_360 >> V_362 ;
F_262 ( V_33 -> V_35 -> V_349 ,
V_350 ,
V_366 ) ;
F_269 ( V_33 -> V_35 -> V_367 ,
! F_248 ( & V_33 -> V_35 -> V_368 ) ) ;
if ( ! V_83 )
V_289 = V_347 ;
else
V_289 = V_369 ;
F_11 ( & V_99 -> V_49 ) ;
if ( F_261 ( V_33 , V_99 , V_356 , V_289 ) ) {
F_13 ( & V_99 -> V_49 ) ;
break;
}
F_13 ( & V_99 -> V_49 ) ;
V_234 ++ ;
if ( V_357 && ! V_83 ) {
F_267 ( V_33 , 0 ) ;
} else {
V_361 = F_270 ( 1 ) ;
if ( V_361 )
break;
}
F_2 () ;
V_359 = V_33 -> V_35 -> V_359 ;
}
}
static int F_271 ( struct V_32 * V_33 ,
struct V_96 * V_99 ,
T_2 V_313 , int V_326 )
{
struct V_327 * V_370 = & V_33 -> V_35 -> V_371 ;
struct V_82 * V_83 ;
V_83 = (struct V_82 * ) V_363 -> V_364 ;
if ( V_83 )
return - V_174 ;
if ( V_326 )
goto V_372;
F_11 ( & V_99 -> V_49 ) ;
if ( V_99 -> V_282 >= V_313 ) {
F_13 ( & V_99 -> V_49 ) ;
goto V_372;
}
F_13 ( & V_99 -> V_49 ) ;
if ( V_99 != V_370 -> V_99 )
return - V_322 ;
F_11 ( & V_99 -> V_49 ) ;
F_11 ( & V_370 -> V_49 ) ;
if ( V_99 -> V_282 + V_370 -> V_54 < V_313 ) {
F_13 ( & V_370 -> V_49 ) ;
F_13 ( & V_99 -> V_49 ) ;
return - V_322 ;
}
F_13 ( & V_370 -> V_49 ) ;
F_13 ( & V_99 -> V_49 ) ;
V_372:
V_83 = F_245 ( V_33 ) ;
if ( F_218 ( V_83 ) )
return - V_322 ;
return F_249 ( V_83 , V_33 ) ;
}
static int F_272 ( struct V_32 * V_33 ,
struct V_96 * V_99 , T_2 V_34 ,
T_2 V_373 , int V_374 )
{
struct V_82 * V_83 ;
int V_42 ;
int V_27 = 0 ;
switch ( V_374 ) {
case V_375 :
case V_376 :
if ( V_374 == V_375 ) {
T_2 V_313 = F_256 ( V_33 , 1 ) ;
V_42 = ( int ) F_226 ( V_34 , V_313 ) ;
if ( ! V_42 )
V_42 = 1 ;
V_42 *= 2 ;
} else {
V_42 = - 1 ;
}
V_83 = F_245 ( V_33 ) ;
if ( F_218 ( V_83 ) ) {
V_27 = F_219 ( V_83 ) ;
break;
}
V_27 = F_273 ( V_83 , V_33 , V_42 ) ;
F_247 ( V_83 , V_33 ) ;
break;
case V_377 :
case V_378 :
F_266 ( V_33 , V_34 , V_373 ,
V_374 == V_378 ) ;
break;
case V_379 :
V_83 = F_245 ( V_33 ) ;
if ( F_218 ( V_83 ) ) {
V_27 = F_219 ( V_83 ) ;
break;
}
V_27 = F_246 ( V_83 , V_33 -> V_35 -> V_60 ,
F_244 ( V_33 , 0 ) ,
V_287 ) ;
F_247 ( V_83 , V_33 ) ;
if ( V_27 == - V_322 )
V_27 = 0 ;
break;
case V_380 :
V_27 = F_271 ( V_33 , V_99 , V_373 , 0 ) ;
break;
default:
V_27 = - V_322 ;
break;
}
return V_27 ;
}
static int F_274 ( struct V_32 * V_33 ,
struct V_327 * V_358 ,
T_2 V_373 ,
enum V_342 V_289 )
{
struct V_96 * V_99 = V_358 -> V_99 ;
T_2 V_106 ;
T_2 V_34 = V_373 ;
int V_381 = V_375 ;
int V_27 = 0 ;
bool V_382 = false ;
V_74:
V_27 = 0 ;
F_11 ( & V_99 -> V_49 ) ;
while ( V_289 == V_347 && ! V_382 &&
V_99 -> V_289 ) {
F_13 ( & V_99 -> V_49 ) ;
if ( V_363 -> V_364 )
return - V_174 ;
V_27 = F_275 ( V_99 -> V_81 , ! V_99 -> V_289 ) ;
if ( V_27 )
return - V_383 ;
F_11 ( & V_99 -> V_49 ) ;
}
V_27 = - V_322 ;
V_106 = V_99 -> V_273 + V_99 -> V_283 +
V_99 -> V_282 + V_99 -> V_284 +
V_99 -> V_285 ;
if ( V_106 <= V_99 -> V_272 ) {
if ( V_106 + V_373 <= V_99 -> V_272 ) {
V_99 -> V_285 += V_373 ;
F_250 ( V_33 -> V_35 ,
L_6 , V_99 -> V_6 , V_373 , 1 ) ;
V_27 = 0 ;
} else {
V_34 = V_373 ;
}
} else {
V_34 = V_106 - V_99 -> V_272 +
( V_373 * 2 ) ;
}
if ( V_27 && F_261 ( V_33 , V_99 , V_373 , V_289 ) ) {
V_99 -> V_285 += V_373 ;
F_250 ( V_33 -> V_35 , L_6 ,
V_99 -> V_6 , V_373 ,
1 ) ;
V_27 = 0 ;
}
if ( V_27 && V_289 != V_369 ) {
V_382 = true ;
V_99 -> V_289 = 1 ;
}
F_13 ( & V_99 -> V_49 ) ;
if ( ! V_27 || V_289 == V_369 )
goto V_69;
V_27 = F_272 ( V_33 , V_99 , V_34 , V_373 ,
V_381 ) ;
V_381 ++ ;
if ( V_289 == V_384 &&
( V_381 == V_377 ||
V_381 == V_378 ) )
V_381 = V_379 ;
if ( ! V_27 )
goto V_74;
else if ( V_289 == V_384 &&
V_381 < V_380 )
goto V_74;
else if ( V_289 == V_347 &&
V_381 <= V_380 )
goto V_74;
V_69:
if ( V_382 ) {
F_11 ( & V_99 -> V_49 ) ;
V_99 -> V_289 = 0 ;
F_276 ( & V_99 -> V_81 ) ;
F_13 ( & V_99 -> V_49 ) ;
}
return V_27 ;
}
static struct V_327 * F_277 (
const struct V_82 * V_83 ,
const struct V_32 * V_33 )
{
struct V_327 * V_358 = NULL ;
if ( V_33 -> V_249 )
V_358 = V_83 -> V_358 ;
if ( V_33 == V_33 -> V_35 -> V_385 && V_83 -> V_386 )
V_358 = V_83 -> V_358 ;
if ( ! V_358 )
V_358 = V_33 -> V_358 ;
if ( ! V_358 )
V_358 = & V_33 -> V_35 -> V_387 ;
return V_358 ;
}
static int F_278 ( struct V_327 * V_358 ,
T_2 V_34 )
{
int V_27 = - V_322 ;
F_11 ( & V_358 -> V_49 ) ;
if ( V_358 -> V_9 >= V_34 ) {
V_358 -> V_9 -= V_34 ;
if ( V_358 -> V_9 < V_358 -> V_54 )
V_358 -> V_102 = 0 ;
V_27 = 0 ;
}
F_13 ( & V_358 -> V_49 ) ;
return V_27 ;
}
static void F_279 ( struct V_327 * V_358 ,
T_2 V_34 , int V_388 )
{
F_11 ( & V_358 -> V_49 ) ;
V_358 -> V_9 += V_34 ;
if ( V_388 )
V_358 -> V_54 += V_34 ;
else if ( V_358 -> V_9 >= V_358 -> V_54 )
V_358 -> V_102 = 1 ;
F_13 ( & V_358 -> V_49 ) ;
}
static void F_280 ( struct V_11 * V_35 ,
struct V_327 * V_358 ,
struct V_327 * V_389 , T_2 V_34 )
{
struct V_96 * V_99 = V_358 -> V_99 ;
F_11 ( & V_358 -> V_49 ) ;
if ( V_34 == ( T_2 ) - 1 )
V_34 = V_358 -> V_54 ;
V_358 -> V_54 -= V_34 ;
if ( V_358 -> V_9 >= V_358 -> V_54 ) {
V_34 = V_358 -> V_9 - V_358 -> V_54 ;
V_358 -> V_9 = V_358 -> V_54 ;
V_358 -> V_102 = 1 ;
} else {
V_34 = 0 ;
}
F_13 ( & V_358 -> V_49 ) ;
if ( V_34 > 0 ) {
if ( V_389 ) {
F_11 ( & V_389 -> V_49 ) ;
if ( ! V_389 -> V_102 ) {
T_2 V_390 ;
V_390 = V_389 -> V_54 - V_389 -> V_9 ;
V_390 = F_268 ( V_34 , V_390 ) ;
V_389 -> V_9 += V_390 ;
if ( V_389 -> V_9 >= V_389 -> V_54 )
V_389 -> V_102 = 1 ;
V_34 -= V_390 ;
}
F_13 ( & V_389 -> V_49 ) ;
}
if ( V_34 ) {
F_11 ( & V_99 -> V_49 ) ;
V_99 -> V_285 -= V_34 ;
F_250 ( V_35 , L_6 ,
V_99 -> V_6 , V_34 , 0 ) ;
V_99 -> V_391 ++ ;
F_13 ( & V_99 -> V_49 ) ;
}
}
}
static int F_281 ( struct V_327 * V_392 ,
struct V_327 * V_393 , T_2 V_34 )
{
int V_27 ;
V_27 = F_278 ( V_392 , V_34 ) ;
if ( V_27 )
return V_27 ;
F_279 ( V_393 , V_34 , 1 ) ;
return 0 ;
}
void F_282 ( struct V_327 * V_394 , unsigned short type )
{
memset ( V_394 , 0 , sizeof( * V_394 ) ) ;
F_236 ( & V_394 -> V_49 ) ;
V_394 -> type = type ;
}
struct V_327 * F_283 ( struct V_32 * V_33 ,
unsigned short type )
{
struct V_327 * V_358 ;
struct V_11 * V_35 = V_33 -> V_35 ;
V_358 = F_191 ( sizeof( * V_358 ) , V_38 ) ;
if ( ! V_358 )
return NULL ;
F_282 ( V_358 , type ) ;
V_358 -> V_99 = F_66 ( V_35 ,
V_113 ) ;
return V_358 ;
}
void F_284 ( struct V_32 * V_33 ,
struct V_327 * V_394 )
{
if ( ! V_394 )
return;
F_285 ( V_33 , V_394 , ( T_2 ) - 1 ) ;
F_9 ( V_394 ) ;
}
int F_286 ( struct V_32 * V_33 ,
struct V_327 * V_358 , T_2 V_34 ,
enum V_342 V_289 )
{
int V_27 ;
if ( V_34 == 0 )
return 0 ;
V_27 = F_274 ( V_33 , V_358 , V_34 , V_289 ) ;
if ( ! V_27 ) {
F_279 ( V_358 , V_34 , 1 ) ;
return 0 ;
}
return V_27 ;
}
int F_287 ( struct V_32 * V_33 ,
struct V_327 * V_358 , int V_395 )
{
T_2 V_34 = 0 ;
int V_27 = - V_322 ;
if ( ! V_358 )
return 0 ;
F_11 ( & V_358 -> V_49 ) ;
V_34 = F_74 ( V_358 -> V_54 , V_395 ) ;
if ( V_358 -> V_9 >= V_34 )
V_27 = 0 ;
F_13 ( & V_358 -> V_49 ) ;
return V_27 ;
}
int F_288 ( struct V_32 * V_33 ,
struct V_327 * V_358 , T_2 V_396 ,
enum V_342 V_289 )
{
T_2 V_34 = 0 ;
int V_27 = - V_322 ;
if ( ! V_358 )
return 0 ;
F_11 ( & V_358 -> V_49 ) ;
V_34 = V_396 ;
if ( V_358 -> V_9 >= V_34 )
V_27 = 0 ;
else
V_34 -= V_358 -> V_9 ;
F_13 ( & V_358 -> V_49 ) ;
if ( ! V_27 )
return 0 ;
V_27 = F_274 ( V_33 , V_358 , V_34 , V_289 ) ;
if ( ! V_27 ) {
F_279 ( V_358 , V_34 , 0 ) ;
return 0 ;
}
return V_27 ;
}
int F_289 ( struct V_327 * V_397 ,
struct V_327 * V_398 ,
T_2 V_34 )
{
return F_281 ( V_397 , V_398 , V_34 ) ;
}
void F_285 ( struct V_32 * V_33 ,
struct V_327 * V_358 ,
T_2 V_34 )
{
struct V_327 * V_328 = & V_33 -> V_35 -> V_329 ;
if ( V_328 -> V_102 || V_328 == V_358 ||
V_358 -> V_99 != V_328 -> V_99 )
V_328 = NULL ;
F_280 ( V_33 -> V_35 , V_358 , V_328 ,
V_34 ) ;
}
static T_2 F_290 ( struct V_11 * V_35 )
{
struct V_96 * V_325 ;
T_2 V_34 ;
T_2 V_399 ;
T_2 V_400 ;
int V_401 = F_291 ( V_35 -> V_333 ) ;
V_325 = F_66 ( V_35 , V_290 ) ;
F_11 ( & V_325 -> V_49 ) ;
V_400 = V_325 -> V_273 ;
F_13 ( & V_325 -> V_49 ) ;
V_325 = F_66 ( V_35 , V_113 ) ;
F_11 ( & V_325 -> V_49 ) ;
if ( V_325 -> V_6 & V_290 )
V_400 = 0 ;
V_399 = V_325 -> V_273 ;
F_13 ( & V_325 -> V_49 ) ;
V_34 = ( V_400 >> V_35 -> V_349 -> V_402 ) *
V_401 * 2 ;
V_34 += F_226 ( V_400 + V_399 , 50 ) ;
if ( V_34 * 3 > V_399 )
V_34 = F_226 ( V_399 , 3 ) ;
return F_292 ( V_34 , V_35 -> V_60 -> V_403 << 10 ) ;
}
static void F_293 ( struct V_11 * V_35 )
{
struct V_327 * V_358 = & V_35 -> V_329 ;
struct V_96 * V_325 = V_358 -> V_99 ;
T_2 V_34 ;
V_34 = F_290 ( V_35 ) ;
F_11 ( & V_325 -> V_49 ) ;
F_11 ( & V_358 -> V_49 ) ;
V_358 -> V_54 = V_34 ;
V_34 = V_325 -> V_273 + V_325 -> V_282 +
V_325 -> V_283 + V_325 -> V_284 +
V_325 -> V_285 ;
if ( V_325 -> V_272 > V_34 ) {
V_34 = V_325 -> V_272 - V_34 ;
V_358 -> V_9 += V_34 ;
V_325 -> V_285 += V_34 ;
F_250 ( V_35 , L_6 ,
V_325 -> V_6 , V_34 , 1 ) ;
}
if ( V_358 -> V_9 >= V_358 -> V_54 ) {
V_34 = V_358 -> V_9 - V_358 -> V_54 ;
V_325 -> V_285 -= V_34 ;
F_250 ( V_35 , L_6 ,
V_325 -> V_6 , V_34 , 0 ) ;
V_325 -> V_391 ++ ;
V_358 -> V_9 = V_358 -> V_54 ;
V_358 -> V_102 = 1 ;
}
F_13 ( & V_358 -> V_49 ) ;
F_13 ( & V_325 -> V_49 ) ;
}
static void F_294 ( struct V_11 * V_35 )
{
struct V_96 * V_99 ;
V_99 = F_66 ( V_35 , V_296 ) ;
V_35 -> V_404 . V_99 = V_99 ;
V_99 = F_66 ( V_35 , V_113 ) ;
V_35 -> V_329 . V_99 = V_99 ;
V_35 -> V_365 . V_99 = V_99 ;
V_35 -> V_405 . V_99 = V_99 ;
V_35 -> V_387 . V_99 = V_99 ;
V_35 -> V_371 . V_99 = V_99 ;
V_35 -> V_60 -> V_358 = & V_35 -> V_329 ;
V_35 -> V_385 -> V_358 = & V_35 -> V_329 ;
V_35 -> V_406 -> V_358 = & V_35 -> V_329 ;
V_35 -> V_235 -> V_358 = & V_35 -> V_329 ;
V_35 -> V_312 -> V_358 = & V_35 -> V_404 ;
F_293 ( V_35 ) ;
}
static void F_295 ( struct V_11 * V_35 )
{
F_280 ( V_35 , & V_35 -> V_329 , NULL ,
( T_2 ) - 1 ) ;
F_8 ( V_35 -> V_365 . V_54 > 0 ) ;
F_8 ( V_35 -> V_365 . V_9 > 0 ) ;
F_8 ( V_35 -> V_405 . V_54 > 0 ) ;
F_8 ( V_35 -> V_405 . V_9 > 0 ) ;
F_8 ( V_35 -> V_404 . V_54 > 0 ) ;
F_8 ( V_35 -> V_404 . V_9 > 0 ) ;
F_8 ( V_35 -> V_371 . V_54 > 0 ) ;
F_8 ( V_35 -> V_371 . V_9 > 0 ) ;
}
void F_296 ( struct V_82 * V_83 ,
struct V_32 * V_33 )
{
if ( ! V_83 -> V_358 )
return;
if ( ! V_83 -> V_283 )
return;
F_250 ( V_33 -> V_35 , L_8 ,
V_83 -> V_262 , V_83 -> V_283 , 0 ) ;
F_285 ( V_33 , V_83 -> V_358 , V_83 -> V_283 ) ;
V_83 -> V_283 = 0 ;
}
int F_297 ( struct V_82 * V_83 ,
struct V_253 * V_253 )
{
struct V_32 * V_33 = F_222 ( V_253 ) -> V_33 ;
struct V_327 * V_397 = F_277 ( V_83 , V_33 ) ;
struct V_327 * V_398 = V_33 -> V_407 ;
T_2 V_34 = F_256 ( V_33 , 1 ) ;
F_250 ( V_33 -> V_35 , L_9 ,
F_298 ( V_253 ) , V_34 , 1 ) ;
return F_281 ( V_397 , V_398 , V_34 ) ;
}
void F_299 ( struct V_253 * V_253 )
{
struct V_32 * V_33 = F_222 ( V_253 ) -> V_33 ;
T_2 V_34 = F_256 ( V_33 , 1 ) ;
F_250 ( V_33 -> V_35 , L_9 ,
F_298 ( V_253 ) , V_34 , 0 ) ;
F_285 ( V_33 , V_33 -> V_407 , V_34 ) ;
}
int F_300 ( struct V_82 * V_83 ,
struct V_408 * V_409 )
{
struct V_32 * V_33 = V_409 -> V_33 ;
struct V_327 * V_397 = F_277 ( V_83 , V_33 ) ;
struct V_327 * V_398 = & V_409 -> V_358 ;
T_2 V_34 = F_256 ( V_33 , 6 ) ;
V_398 -> V_99 = V_397 -> V_99 ;
return F_281 ( V_397 , V_398 , V_34 ) ;
}
static unsigned F_301 ( struct V_253 * V_253 )
{
unsigned V_410 = 0 ;
unsigned V_411 = 0 ;
F_22 ( ! F_222 ( V_253 ) -> V_412 ) ;
F_222 ( V_253 ) -> V_412 -- ;
if ( F_222 ( V_253 ) -> V_412 == 0 &&
F_302 ( V_413 ,
& F_222 ( V_253 ) -> V_414 ) )
V_410 = 1 ;
if ( F_222 ( V_253 ) -> V_412 >=
F_222 ( V_253 ) -> V_415 )
return V_410 ;
V_411 = F_222 ( V_253 ) -> V_415 -
F_222 ( V_253 ) -> V_412 ;
F_222 ( V_253 ) -> V_415 -= V_411 ;
return V_411 + V_410 ;
}
static T_2 F_303 ( struct V_253 * V_253 , T_2 V_34 ,
int V_416 )
{
struct V_32 * V_33 = F_222 ( V_253 ) -> V_33 ;
T_2 V_401 ;
int V_417 ;
int V_418 ;
int V_419 ;
if ( F_222 ( V_253 ) -> V_6 & V_420 &&
F_222 ( V_253 ) -> V_421 == 0 )
return 0 ;
V_419 = ( int ) F_226 ( F_222 ( V_253 ) -> V_421 , V_33 -> V_316 ) ;
if ( V_416 )
F_222 ( V_253 ) -> V_421 += V_34 ;
else
F_222 ( V_253 ) -> V_421 -= V_34 ;
V_401 = F_304 ( V_33 ) - sizeof( struct V_422 ) ;
V_417 = ( int ) F_226 ( V_401 ,
sizeof( struct V_423 ) +
sizeof( struct V_424 ) ) ;
V_418 = ( int ) F_226 ( F_222 ( V_253 ) -> V_421 , V_33 -> V_316 ) ;
V_418 = V_418 + V_417 - 1 ;
V_418 = V_418 / V_417 ;
V_419 = V_419 + V_417 - 1 ;
V_419 = V_419 / V_417 ;
if ( V_419 == V_418 )
return 0 ;
if ( V_416 )
return F_256 ( V_33 ,
V_418 - V_419 ) ;
return F_256 ( V_33 , V_419 - V_418 ) ;
}
int F_305 ( struct V_253 * V_253 , T_2 V_34 )
{
struct V_32 * V_33 = F_222 ( V_253 ) -> V_33 ;
struct V_327 * V_358 = & V_33 -> V_35 -> V_365 ;
T_2 V_425 = 0 ;
T_2 V_421 ;
unsigned V_426 = 0 ;
int V_427 = 0 ;
enum V_342 V_289 = V_347 ;
int V_27 = 0 ;
bool V_428 = true ;
if ( F_306 ( V_253 ) ) {
V_289 = V_369 ;
V_428 = false ;
}
if ( V_289 != V_369 &&
F_307 ( V_33 -> V_35 ) )
F_188 ( 1 ) ;
if ( V_428 )
F_34 ( & F_222 ( V_253 ) -> V_429 ) ;
V_34 = F_292 ( V_34 , V_33 -> V_316 ) ;
F_11 ( & F_222 ( V_253 ) -> V_49 ) ;
F_222 ( V_253 ) -> V_412 ++ ;
if ( F_222 ( V_253 ) -> V_412 >
F_222 ( V_253 ) -> V_415 )
V_426 = F_222 ( V_253 ) -> V_412 -
F_222 ( V_253 ) -> V_415 ;
if ( ! F_308 ( V_413 ,
& F_222 ( V_253 ) -> V_414 ) ) {
V_426 ++ ;
V_427 = 1 ;
}
V_425 = F_256 ( V_33 , V_426 ) ;
V_425 += F_303 ( V_253 , V_34 , 1 ) ;
V_421 = F_222 ( V_253 ) -> V_421 ;
F_13 ( & F_222 ( V_253 ) -> V_49 ) ;
if ( V_33 -> V_35 -> V_430 )
V_27 = F_309 ( V_33 , V_34 +
V_426 * V_33 -> V_403 ) ;
if ( V_27 == 0 )
V_27 = F_274 ( V_33 , V_358 ,
V_425 , V_289 ) ;
if ( V_27 ) {
T_2 V_431 = 0 ;
unsigned V_432 ;
F_11 ( & F_222 ( V_253 ) -> V_49 ) ;
V_432 = F_301 ( V_253 ) ;
if ( F_222 ( V_253 ) -> V_421 == V_421 )
F_303 ( V_253 , V_34 , 0 ) ;
else
V_431 = F_303 ( V_253 , V_34 , 0 ) ;
F_13 ( & F_222 ( V_253 ) -> V_49 ) ;
if ( V_432 )
V_431 += F_256 ( V_33 , V_432 ) ;
if ( V_431 ) {
F_285 ( V_33 , V_358 , V_431 ) ;
F_250 ( V_33 -> V_35 ,
L_10 ,
F_298 ( V_253 ) ,
V_431 , 0 ) ;
}
if ( V_33 -> V_35 -> V_430 ) {
F_310 ( V_33 , V_34 +
V_426 * V_33 -> V_403 ) ;
}
if ( V_428 )
F_45 ( & F_222 ( V_253 ) -> V_429 ) ;
return V_27 ;
}
F_11 ( & F_222 ( V_253 ) -> V_49 ) ;
if ( V_427 ) {
F_311 ( V_413 ,
& F_222 ( V_253 ) -> V_414 ) ;
V_426 -- ;
}
F_222 ( V_253 ) -> V_415 += V_426 ;
F_13 ( & F_222 ( V_253 ) -> V_49 ) ;
if ( V_428 )
F_45 ( & F_222 ( V_253 ) -> V_429 ) ;
if ( V_425 )
F_250 ( V_33 -> V_35 , L_10 ,
F_298 ( V_253 ) , V_425 , 1 ) ;
F_279 ( V_358 , V_425 , 1 ) ;
return 0 ;
}
void F_312 ( struct V_253 * V_253 , T_2 V_34 )
{
struct V_32 * V_33 = F_222 ( V_253 ) -> V_33 ;
T_2 V_431 = 0 ;
unsigned V_432 ;
V_34 = F_292 ( V_34 , V_33 -> V_316 ) ;
F_11 ( & F_222 ( V_253 ) -> V_49 ) ;
V_432 = F_301 ( V_253 ) ;
V_431 = F_303 ( V_253 , V_34 , 0 ) ;
F_13 ( & F_222 ( V_253 ) -> V_49 ) ;
if ( V_432 > 0 )
V_431 += F_256 ( V_33 , V_432 ) ;
F_250 ( V_33 -> V_35 , L_10 ,
F_298 ( V_253 ) , V_431 , 0 ) ;
if ( V_33 -> V_35 -> V_430 ) {
F_310 ( V_33 , V_34 +
V_432 * V_33 -> V_403 ) ;
}
F_285 ( V_33 , & V_33 -> V_35 -> V_365 ,
V_431 ) ;
}
int F_313 ( struct V_253 * V_253 , T_2 V_34 )
{
int V_27 ;
V_27 = F_227 ( V_253 , V_34 ) ;
if ( V_27 )
return V_27 ;
V_27 = F_305 ( V_253 , V_34 ) ;
if ( V_27 ) {
F_229 ( V_253 , V_34 ) ;
return V_27 ;
}
return 0 ;
}
void F_314 ( struct V_253 * V_253 , T_2 V_34 )
{
F_312 ( V_253 , V_34 ) ;
F_229 ( V_253 , V_34 ) ;
}
static int F_315 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
T_2 V_25 , T_2 V_34 , int V_319 )
{
struct V_1 * V_2 = NULL ;
struct V_11 * V_12 = V_33 -> V_35 ;
T_2 V_433 = V_34 ;
T_2 V_434 ;
T_2 V_435 ;
int V_109 ;
F_11 ( & V_12 -> V_428 ) ;
V_434 = F_316 ( V_12 -> V_333 ) ;
if ( V_319 )
V_434 += V_34 ;
else
V_434 -= V_34 ;
F_317 ( V_12 -> V_333 , V_434 ) ;
F_13 ( & V_12 -> V_428 ) ;
while ( V_433 ) {
V_2 = F_65 ( V_12 , V_25 ) ;
if ( ! V_2 )
return - V_152 ;
if ( V_2 -> V_6 & ( V_274 |
V_275 |
V_276 ) )
V_109 = 2 ;
else
V_109 = 1 ;
if ( ! V_319 && V_2 -> V_3 == V_90 )
F_49 ( V_2 , V_83 , NULL , 1 ) ;
V_435 = V_25 - V_2 -> V_20 . V_21 ;
F_8 ( V_435 > V_2 -> V_20 . V_31 ) ;
F_11 ( & V_2 -> V_99 -> V_49 ) ;
F_11 ( & V_2 -> V_49 ) ;
if ( F_225 ( V_33 , V_266 ) &&
V_2 -> V_259 < V_268 )
V_2 -> V_259 = V_268 ;
V_2 -> V_269 = 1 ;
V_434 = F_73 ( & V_2 -> V_111 ) ;
V_34 = F_268 ( V_433 , V_2 -> V_20 . V_31 - V_435 ) ;
if ( V_319 ) {
V_434 += V_34 ;
F_318 ( & V_2 -> V_111 , V_434 ) ;
V_2 -> V_9 -= V_34 ;
V_2 -> V_99 -> V_283 -= V_34 ;
V_2 -> V_99 -> V_273 += V_34 ;
V_2 -> V_99 -> V_278 += V_34 * V_109 ;
F_13 ( & V_2 -> V_49 ) ;
F_13 ( & V_2 -> V_99 -> V_49 ) ;
} else {
V_434 -= V_34 ;
F_318 ( & V_2 -> V_111 , V_434 ) ;
V_2 -> V_8 += V_34 ;
V_2 -> V_99 -> V_282 += V_34 ;
V_2 -> V_99 -> V_273 -= V_34 ;
V_2 -> V_99 -> V_278 -= V_34 * V_109 ;
F_13 ( & V_2 -> V_49 ) ;
F_13 ( & V_2 -> V_99 -> V_49 ) ;
F_319 ( V_12 -> V_56 ,
V_25 , V_25 + V_34 - 1 ,
V_38 | V_436 ) ;
}
F_6 ( V_2 ) ;
V_433 -= V_34 ;
V_25 += V_34 ;
}
return 0 ;
}
static T_2 F_320 ( struct V_32 * V_33 , T_2 V_103 )
{
struct V_1 * V_2 ;
T_2 V_25 ;
V_2 = F_64 ( V_33 -> V_35 , V_103 ) ;
if ( ! V_2 )
return 0 ;
V_25 = V_2 -> V_20 . V_21 ;
F_6 ( V_2 ) ;
return V_25 ;
}
static int F_321 ( struct V_32 * V_33 ,
struct V_1 * V_2 ,
T_2 V_25 , T_2 V_34 , int V_9 )
{
F_11 ( & V_2 -> V_99 -> V_49 ) ;
F_11 ( & V_2 -> V_49 ) ;
V_2 -> V_8 += V_34 ;
V_2 -> V_99 -> V_282 += V_34 ;
if ( V_9 ) {
V_2 -> V_9 -= V_34 ;
V_2 -> V_99 -> V_283 -= V_34 ;
}
F_13 ( & V_2 -> V_49 ) ;
F_13 ( & V_2 -> V_99 -> V_49 ) ;
F_319 ( V_33 -> V_35 -> V_56 , V_25 ,
V_25 + V_34 - 1 , V_38 | V_436 ) ;
return 0 ;
}
int F_162 ( struct V_32 * V_33 ,
T_2 V_25 , T_2 V_34 , int V_9 )
{
struct V_1 * V_2 ;
V_2 = F_65 ( V_33 -> V_35 , V_25 ) ;
F_22 ( ! V_2 ) ;
F_321 ( V_33 , V_2 , V_25 , V_34 , V_9 ) ;
F_6 ( V_2 ) ;
return 0 ;
}
int F_322 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
T_2 V_25 , T_2 V_34 )
{
struct V_1 * V_2 ;
V_2 = F_65 ( V_33 -> V_35 , V_25 ) ;
F_22 ( ! V_2 ) ;
F_49 ( V_2 , V_83 , V_33 , 1 ) ;
F_321 ( V_33 , V_2 , V_25 , V_34 , 0 ) ;
F_323 ( V_2 , V_25 , V_34 ) ;
F_6 ( V_2 ) ;
return 0 ;
}
static int F_324 ( struct V_1 * V_2 ,
T_2 V_34 , int V_416 )
{
struct V_96 * V_99 = V_2 -> V_99 ;
int V_27 = 0 ;
F_11 ( & V_99 -> V_49 ) ;
F_11 ( & V_2 -> V_49 ) ;
if ( V_416 != V_437 ) {
if ( V_2 -> V_112 ) {
V_27 = - V_174 ;
} else {
V_2 -> V_9 += V_34 ;
V_99 -> V_283 += V_34 ;
if ( V_416 == V_438 ) {
F_250 ( V_2 -> V_35 ,
L_6 , V_99 -> V_6 ,
V_34 , 0 ) ;
V_99 -> V_285 -= V_34 ;
}
}
} else {
if ( V_2 -> V_112 )
V_99 -> V_284 += V_34 ;
V_2 -> V_9 -= V_34 ;
V_99 -> V_283 -= V_34 ;
V_99 -> V_391 ++ ;
}
F_13 ( & V_2 -> V_49 ) ;
F_13 ( & V_99 -> V_49 ) ;
return V_27 ;
}
void F_325 ( struct V_82 * V_83 ,
struct V_32 * V_33 )
{
struct V_11 * V_35 = V_33 -> V_35 ;
struct V_47 * V_215 ;
struct V_47 * V_51 ;
struct V_1 * V_2 ;
F_60 ( & V_35 -> V_76 ) ;
F_326 (caching_ctl, next,
&fs_info->caching_block_groups, list) {
V_2 = V_51 -> V_13 ;
if ( F_1 ( V_2 ) ) {
V_2 -> V_93 = ( T_2 ) - 1 ;
F_171 ( & V_51 -> V_86 ) ;
F_26 ( V_51 ) ;
} else {
V_2 -> V_93 = V_51 -> V_80 ;
}
}
if ( V_35 -> V_56 == & V_35 -> V_36 [ 0 ] )
V_35 -> V_56 = & V_35 -> V_36 [ 1 ] ;
else
V_35 -> V_56 = & V_35 -> V_36 [ 0 ] ;
F_62 ( & V_35 -> V_76 ) ;
F_293 ( V_35 ) ;
}
static int F_327 ( struct V_32 * V_33 , T_2 V_30 , T_2 V_29 )
{
struct V_11 * V_35 = V_33 -> V_35 ;
struct V_1 * V_2 = NULL ;
struct V_96 * V_99 ;
struct V_327 * V_328 = & V_35 -> V_329 ;
T_2 V_114 ;
bool V_271 ;
while ( V_30 <= V_29 ) {
V_271 = false ;
if ( ! V_2 ||
V_30 >= V_2 -> V_20 . V_21 + V_2 -> V_20 . V_31 ) {
if ( V_2 )
F_6 ( V_2 ) ;
V_2 = F_65 ( V_35 , V_30 ) ;
F_22 ( ! V_2 ) ;
}
V_114 = V_2 -> V_20 . V_21 + V_2 -> V_20 . V_31 - V_30 ;
V_114 = F_268 ( V_114 , V_29 + 1 - V_30 ) ;
if ( V_30 < V_2 -> V_93 ) {
V_114 = F_268 ( V_114 , V_2 -> V_93 - V_30 ) ;
F_29 ( V_2 , V_30 , V_114 ) ;
}
V_30 += V_114 ;
V_99 = V_2 -> V_99 ;
F_11 ( & V_99 -> V_49 ) ;
F_11 ( & V_2 -> V_49 ) ;
V_2 -> V_8 -= V_114 ;
V_99 -> V_282 -= V_114 ;
if ( V_2 -> V_112 ) {
V_99 -> V_284 += V_114 ;
V_271 = true ;
}
F_13 ( & V_2 -> V_49 ) ;
if ( ! V_271 && V_328 -> V_99 == V_99 ) {
F_11 ( & V_328 -> V_49 ) ;
if ( ! V_328 -> V_102 ) {
V_114 = F_268 ( V_114 , V_328 -> V_54 -
V_328 -> V_9 ) ;
V_328 -> V_9 += V_114 ;
V_99 -> V_285 += V_114 ;
if ( V_328 -> V_9 >= V_328 -> V_54 )
V_328 -> V_102 = 1 ;
}
F_13 ( & V_328 -> V_49 ) ;
}
F_13 ( & V_99 -> V_49 ) ;
}
if ( V_2 )
F_6 ( V_2 ) ;
return 0 ;
}
int F_328 ( struct V_82 * V_83 ,
struct V_32 * V_33 )
{
struct V_11 * V_35 = V_33 -> V_35 ;
struct V_439 * V_440 ;
T_2 V_30 ;
T_2 V_29 ;
int V_27 ;
if ( V_83 -> V_209 )
return 0 ;
if ( V_35 -> V_56 == & V_35 -> V_36 [ 0 ] )
V_440 = & V_35 -> V_36 [ 1 ] ;
else
V_440 = & V_35 -> V_36 [ 0 ] ;
while ( 1 ) {
V_27 = F_28 ( V_440 , 0 , & V_30 , & V_29 ,
V_57 , NULL ) ;
if ( V_27 )
break;
if ( F_225 ( V_33 , V_441 ) )
V_27 = F_143 ( V_33 , V_30 ,
V_29 + 1 - V_30 , NULL ) ;
F_329 ( V_440 , V_30 , V_29 , V_38 ) ;
F_327 ( V_33 , V_30 , V_29 ) ;
F_46 () ;
}
return 0 ;
}
static int F_153 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
T_2 V_25 , T_2 V_34 , T_2 V_16 ,
T_2 V_145 , T_2 V_442 ,
T_2 V_443 , int V_158 ,
struct V_176 * V_130 )
{
struct V_65 V_20 ;
struct V_61 * V_62 ;
struct V_11 * V_12 = V_33 -> V_35 ;
struct V_32 * V_60 = V_12 -> V_60 ;
struct V_63 * V_64 ;
struct V_119 * V_120 ;
struct V_161 * V_162 ;
int V_27 ;
int V_180 ;
int V_444 = 0 ;
int V_445 = 0 ;
int V_446 = 1 ;
T_3 V_121 ;
T_2 V_115 ;
V_62 = F_32 () ;
if ( ! V_62 )
return - V_85 ;
V_62 -> V_72 = 1 ;
V_62 -> V_200 = 1 ;
V_180 = V_442 >= V_142 ;
F_22 ( ! V_180 && V_158 != 1 ) ;
V_27 = F_135 ( V_83 , V_60 , V_62 , & V_162 ,
V_25 , V_34 , V_16 ,
V_145 , V_442 ,
V_443 ) ;
if ( V_27 == 0 ) {
V_444 = V_62 -> V_79 [ 0 ] ;
while ( V_444 >= 0 ) {
F_39 ( V_62 -> V_78 [ 0 ] , & V_20 ,
V_444 ) ;
if ( V_20 . V_21 != V_25 )
break;
if ( V_20 . type == V_73 &&
V_20 . V_31 == V_34 ) {
V_445 = 1 ;
break;
}
if ( V_62 -> V_79 [ 0 ] - V_444 > 5 )
break;
V_444 -- ;
}
#ifdef F_82
V_121 = F_78 ( V_62 -> V_78 [ 0 ] , V_444 ) ;
if ( V_445 && V_121 < sizeof( * V_120 ) )
V_445 = 0 ;
#endif
if ( ! V_445 ) {
F_22 ( V_162 ) ;
V_27 = F_140 ( V_83 , V_60 , V_62 ,
NULL , V_158 ,
V_180 ) ;
if ( V_27 ) {
F_149 ( V_83 , V_60 , V_27 ) ;
goto V_69;
}
F_43 ( V_62 ) ;
V_62 -> V_200 = 1 ;
V_20 . V_21 = V_25 ;
V_20 . type = V_73 ;
V_20 . V_31 = V_34 ;
V_27 = F_36 ( V_83 , V_60 ,
& V_20 , V_62 , - 1 , 1 ) ;
if ( V_27 ) {
F_172 ( V_230 L_11
L_12 , V_27 ,
( unsigned long long ) V_25 ) ;
if ( V_27 > 0 )
F_330 ( V_60 ,
V_62 -> V_78 [ 0 ] ) ;
}
if ( V_27 < 0 ) {
F_149 ( V_83 , V_60 , V_27 ) ;
goto V_69;
}
V_444 = V_62 -> V_79 [ 0 ] ;
}
} else if ( V_27 == - V_152 ) {
F_330 ( V_60 , V_62 -> V_78 [ 0 ] ) ;
F_8 ( 1 ) ;
F_172 ( V_230 L_13
L_14 ,
( unsigned long long ) V_25 ,
( unsigned long long ) V_16 ,
( unsigned long long ) V_145 ,
( unsigned long long ) V_442 ,
( unsigned long long ) V_443 ) ;
} else {
F_149 ( V_83 , V_60 , V_27 ) ;
goto V_69;
}
V_64 = V_62 -> V_78 [ 0 ] ;
V_121 = F_78 ( V_64 , V_444 ) ;
#ifdef F_82
if ( V_121 < sizeof( * V_120 ) ) {
F_22 ( V_445 || V_444 != V_62 -> V_79 [ 0 ] ) ;
V_27 = F_88 ( V_83 , V_60 , V_62 ,
V_442 , 0 ) ;
if ( V_27 < 0 ) {
F_149 ( V_83 , V_60 , V_27 ) ;
goto V_69;
}
F_43 ( V_62 ) ;
V_62 -> V_200 = 1 ;
V_20 . V_21 = V_25 ;
V_20 . type = V_73 ;
V_20 . V_31 = V_34 ;
V_27 = F_36 ( V_83 , V_60 , & V_20 , V_62 ,
- 1 , 1 ) ;
if ( V_27 ) {
F_172 ( V_230 L_11
L_12 , V_27 ,
( unsigned long long ) V_25 ) ;
F_330 ( V_60 , V_62 -> V_78 [ 0 ] ) ;
}
if ( V_27 < 0 ) {
F_149 ( V_83 , V_60 , V_27 ) ;
goto V_69;
}
V_444 = V_62 -> V_79 [ 0 ] ;
V_64 = V_62 -> V_78 [ 0 ] ;
V_121 = F_78 ( V_64 , V_444 ) ;
}
#endif
F_22 ( V_121 < sizeof( * V_120 ) ) ;
V_120 = F_79 ( V_64 , V_444 ,
struct V_119 ) ;
if ( V_442 < V_142 ) {
struct V_137 * V_138 ;
F_22 ( V_121 < sizeof( * V_120 ) + sizeof( * V_138 ) ) ;
V_138 = (struct V_137 * ) ( V_120 + 1 ) ;
F_8 ( V_442 != F_331 ( V_64 , V_138 ) ) ;
}
V_115 = F_80 ( V_64 , V_120 ) ;
F_22 ( V_115 < V_158 ) ;
V_115 -= V_158 ;
if ( V_115 > 0 ) {
if ( V_130 )
F_131 ( V_130 , V_64 , V_120 ) ;
if ( V_162 ) {
F_22 ( ! V_445 ) ;
} else {
F_91 ( V_64 , V_120 , V_115 ) ;
F_96 ( V_64 ) ;
}
if ( V_445 ) {
V_27 = F_140 ( V_83 , V_60 , V_62 ,
V_162 , V_158 ,
V_180 ) ;
if ( V_27 ) {
F_149 ( V_83 , V_60 , V_27 ) ;
goto V_69;
}
}
} else {
if ( V_445 ) {
F_22 ( V_180 && V_158 !=
F_119 ( V_33 , V_62 , V_162 ) ) ;
if ( V_162 ) {
F_22 ( V_62 -> V_79 [ 0 ] != V_444 ) ;
} else {
F_22 ( V_62 -> V_79 [ 0 ] != V_444 + 1 ) ;
V_62 -> V_79 [ 0 ] = V_444 ;
V_446 = 2 ;
}
}
V_27 = F_332 ( V_83 , V_60 , V_62 , V_62 -> V_79 [ 0 ] ,
V_446 ) ;
if ( V_27 ) {
F_149 ( V_83 , V_60 , V_27 ) ;
goto V_69;
}
F_43 ( V_62 ) ;
if ( V_180 ) {
V_27 = F_163 ( V_83 , V_33 , V_25 , V_34 ) ;
if ( V_27 ) {
F_149 ( V_83 , V_60 , V_27 ) ;
goto V_69;
}
}
V_27 = F_315 ( V_83 , V_33 , V_25 , V_34 , 0 ) ;
if ( V_27 ) {
F_149 ( V_83 , V_60 , V_27 ) ;
goto V_69;
}
}
V_69:
F_48 ( V_62 ) ;
return V_27 ;
}
static T_1 int F_333 ( struct V_82 * V_83 ,
struct V_32 * V_33 , T_2 V_25 )
{
struct V_116 * V_98 ;
struct V_117 * V_118 ;
struct V_201 * V_150 ;
struct V_14 * V_129 ;
int V_27 = 0 ;
V_118 = & V_83 -> V_128 -> V_118 ;
F_11 ( & V_118 -> V_49 ) ;
V_98 = F_85 ( V_83 , V_25 ) ;
if ( ! V_98 )
goto V_69;
V_129 = F_194 ( & V_98 -> V_129 . V_14 ) ;
if ( ! V_129 )
goto V_69;
V_150 = F_12 ( V_129 , struct V_201 , V_14 ) ;
if ( V_150 -> V_25 == V_25 )
goto V_69;
if ( V_98 -> V_130 ) {
if ( ! V_98 -> V_214 )
goto V_69;
F_9 ( V_98 -> V_130 ) ;
V_98 -> V_130 = NULL ;
}
if ( ! F_86 ( & V_98 -> V_75 ) )
goto V_69;
V_98 -> V_129 . V_219 = 0 ;
F_173 ( & V_98 -> V_129 . V_14 , & V_118 -> V_33 ) ;
V_118 -> V_220 -- ;
V_118 -> V_447 -- ;
if ( F_165 ( & V_98 -> V_212 ) )
V_118 -> V_217 -- ;
F_171 ( & V_98 -> V_212 ) ;
F_13 ( & V_118 -> V_49 ) ;
F_22 ( V_98 -> V_130 ) ;
if ( V_98 -> V_214 )
V_27 = 1 ;
F_45 ( & V_98 -> V_75 ) ;
F_87 ( & V_98 -> V_129 ) ;
return V_27 ;
V_69:
F_13 ( & V_118 -> V_49 ) ;
return 0 ;
}
void F_334 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_63 * V_244 ,
T_2 V_16 , int V_448 )
{
struct V_1 * V_2 = NULL ;
int V_27 ;
if ( V_33 -> V_240 . V_21 != V_198 ) {
V_27 = F_146 ( V_33 -> V_35 , V_83 ,
V_244 -> V_30 , V_244 -> V_114 ,
V_16 , V_33 -> V_240 . V_21 ,
F_202 ( V_244 ) ,
V_208 , NULL , 0 ) ;
F_22 ( V_27 ) ;
}
if ( ! V_448 )
return;
V_2 = F_65 ( V_33 -> V_35 , V_244 -> V_30 ) ;
if ( F_335 ( V_244 ) == V_83 -> V_262 ) {
if ( V_33 -> V_240 . V_21 != V_198 ) {
V_27 = F_333 ( V_83 , V_33 , V_244 -> V_30 ) ;
if ( ! V_27 )
goto V_69;
}
if ( F_336 ( V_244 , V_449 ) ) {
F_321 ( V_33 , V_2 , V_244 -> V_30 , V_244 -> V_114 , 1 ) ;
goto V_69;
}
F_8 ( F_308 ( V_450 , & V_244 -> V_451 ) ) ;
F_29 ( V_2 , V_244 -> V_30 , V_244 -> V_114 ) ;
F_324 ( V_2 , V_244 -> V_114 , V_437 ) ;
}
V_69:
F_337 ( V_452 , & V_244 -> V_451 ) ;
F_6 ( V_2 ) ;
}
int V_250 ( struct V_82 * V_83 , struct V_32 * V_33 ,
T_2 V_25 , T_2 V_34 , T_2 V_16 , T_2 V_145 ,
T_2 V_105 , T_2 V_31 , int V_197 )
{
int V_27 ;
struct V_11 * V_35 = V_33 -> V_35 ;
if ( V_145 == V_198 ) {
F_8 ( V_105 >= V_142 ) ;
F_162 ( V_33 , V_25 , V_34 , 1 ) ;
V_27 = 0 ;
} else if ( V_105 < V_142 ) {
V_27 = F_146 ( V_35 , V_83 , V_25 ,
V_34 ,
V_16 , V_145 , ( int ) V_105 ,
V_208 , NULL , V_197 ) ;
} else {
V_27 = F_147 ( V_35 , V_83 , V_25 ,
V_34 ,
V_16 , V_145 , V_105 ,
V_31 , V_208 ,
NULL , V_197 ) ;
}
return V_27 ;
}
static T_2 F_338 ( struct V_32 * V_33 , T_2 V_453 )
{
T_2 V_454 = ( ( T_2 ) V_33 -> V_455 - 1 ) ;
T_2 V_27 = ( V_453 + V_454 ) & ~ V_454 ;
return V_27 ;
}
static T_1 int
F_339 ( struct V_1 * V_2 ,
T_2 V_34 )
{
struct V_47 * V_51 ;
F_50 ( V_81 ) ;
V_51 = F_25 ( V_2 ) ;
if ( ! V_51 )
return 0 ;
F_269 ( V_51 -> V_81 , F_1 ( V_2 ) ||
( V_2 -> V_10 -> V_456 >= V_34 ) ) ;
F_26 ( V_51 ) ;
return 0 ;
}
static T_1 int
F_340 ( struct V_1 * V_2 )
{
struct V_47 * V_51 ;
F_50 ( V_81 ) ;
V_51 = F_25 ( V_2 ) ;
if ( ! V_51 )
return 0 ;
F_269 ( V_51 -> V_81 , F_1 ( V_2 ) ) ;
F_26 ( V_51 ) ;
return 0 ;
}
int F_341 ( T_2 V_6 )
{
int V_457 ;
if ( V_6 & V_276 )
V_457 = 0 ;
else if ( V_6 & V_275 )
V_457 = 1 ;
else if ( V_6 & V_274 )
V_457 = 2 ;
else if ( V_6 & V_311 )
V_457 = 3 ;
else
V_457 = 4 ;
return V_457 ;
}
static int F_342 ( struct V_1 * V_2 )
{
return F_341 ( V_2 -> V_6 ) ;
}
static T_1 int F_343 ( struct V_82 * V_83 ,
struct V_32 * V_458 ,
T_2 V_34 , T_2 V_459 ,
T_2 V_460 , struct V_65 * V_204 ,
T_2 V_302 )
{
int V_27 = 0 ;
struct V_32 * V_33 = V_458 -> V_35 -> V_60 ;
struct V_461 * V_462 = NULL ;
struct V_1 * V_13 = NULL ;
struct V_1 * V_463 ;
T_2 V_103 = 0 ;
int V_464 = 2 * 1024 * 1024 ;
struct V_96 * V_99 ;
int V_465 = 0 ;
int V_457 = F_341 ( V_302 ) ;
int V_466 = ( V_302 & V_290 ) ?
V_467 : V_438 ;
bool V_468 = false ;
bool V_469 = false ;
bool V_470 = false ;
bool V_471 = true ;
bool V_472 = false ;
F_8 ( V_34 < V_33 -> V_316 ) ;
F_76 ( V_204 , V_73 ) ;
V_204 -> V_21 = 0 ;
V_204 -> V_31 = 0 ;
F_344 ( V_458 , V_34 , V_459 , V_302 ) ;
V_99 = F_66 ( V_33 -> V_35 , V_302 ) ;
if ( ! V_99 ) {
F_172 ( V_230 L_15 , V_302 ) ;
return - V_322 ;
}
if ( F_260 ( V_99 ) )
V_471 = false ;
if ( V_302 & V_113 && V_471 ) {
V_462 = & V_33 -> V_35 -> V_473 ;
if ( ! F_225 ( V_33 , V_474 ) )
V_464 = 64 * 1024 ;
}
if ( ( V_302 & V_290 ) && V_471 &&
F_225 ( V_33 , V_474 ) ) {
V_462 = & V_33 -> V_35 -> V_475 ;
}
if ( V_462 ) {
F_11 ( & V_462 -> V_49 ) ;
if ( V_462 -> V_13 )
V_460 = V_462 -> V_476 ;
F_13 ( & V_462 -> V_49 ) ;
}
V_103 = F_72 ( V_103 , F_320 ( V_33 , 0 ) ) ;
V_103 = F_72 ( V_103 , V_460 ) ;
if ( ! V_462 )
V_464 = 0 ;
if ( V_103 == V_460 ) {
V_13 = F_65 ( V_33 -> V_35 ,
V_103 ) ;
V_463 = V_13 ;
if ( V_13 && F_3 ( V_13 , V_302 ) &&
V_13 -> V_3 != V_90 ) {
F_35 ( & V_99 -> V_281 ) ;
if ( F_165 ( & V_13 -> V_86 ) ||
V_13 -> V_112 ) {
F_6 ( V_13 ) ;
F_44 ( & V_99 -> V_281 ) ;
} else {
V_457 = F_342 ( V_13 ) ;
goto V_477;
}
} else if ( V_13 ) {
F_6 ( V_13 ) ;
}
}
V_478:
V_472 = false ;
F_35 ( & V_99 -> V_281 ) ;
F_345 (block_group, &space_info->block_groups[index],
list) {
T_2 V_31 ;
int V_3 ;
V_463 = V_13 ;
F_4 ( V_13 ) ;
V_103 = V_13 -> V_20 . V_21 ;
if ( ! F_3 ( V_13 , V_302 ) ) {
T_2 V_479 = V_274 |
V_275 |
V_276 ;
if ( ( V_302 & V_479 ) && ! ( V_13 -> V_6 & V_479 ) )
goto V_465;
}
V_477:
V_3 = F_1 ( V_13 ) ;
if ( F_346 ( ! V_3 ) ) {
V_468 = true ;
V_27 = F_49 ( V_13 , V_83 ,
V_458 , 0 ) ;
F_22 ( V_27 < 0 ) ;
V_27 = 0 ;
}
if ( F_346 ( V_13 -> V_112 ) )
goto V_465;
if ( V_462 ) {
F_11 ( & V_462 -> V_480 ) ;
V_463 = V_462 -> V_13 ;
if ( V_463 != V_13 &&
( ! V_463 ||
V_463 -> V_112 ||
! F_3 ( V_463 , V_302 ) ) ) {
V_463 = V_13 ;
goto V_481;
}
if ( V_463 != V_13 )
F_4 ( V_463 ) ;
V_31 = F_347 ( V_463 ,
V_462 , V_34 , V_463 -> V_20 . V_21 ) ;
if ( V_31 ) {
F_13 ( & V_462 -> V_480 ) ;
F_348 ( V_33 ,
V_13 , V_103 , V_34 ) ;
goto V_482;
}
F_8 ( V_462 -> V_13 != V_463 ) ;
if ( V_463 != V_13 ) {
F_6 ( V_463 ) ;
V_463 = V_13 ;
}
V_481:
F_22 ( V_463 != V_13 ) ;
if ( V_465 >= V_483 &&
V_462 -> V_13 != V_13 ) {
F_13 ( & V_462 -> V_480 ) ;
goto V_484;
}
F_349 ( NULL , V_462 ) ;
if ( V_465 >= V_483 ) {
F_13 ( & V_462 -> V_480 ) ;
goto V_484;
}
V_27 = F_350 ( V_83 , V_33 ,
V_13 , V_462 ,
V_103 , V_34 ,
V_464 + V_459 ) ;
if ( V_27 == 0 ) {
V_31 = F_347 ( V_13 ,
V_462 , V_34 ,
V_103 ) ;
if ( V_31 ) {
F_13 ( & V_462 -> V_480 ) ;
F_348 ( V_33 ,
V_13 , V_103 ,
V_34 ) ;
goto V_482;
}
} else if ( ! V_3 && V_465 > V_485
&& ! V_469 ) {
F_13 ( & V_462 -> V_480 ) ;
V_469 = true ;
F_339 ( V_13 ,
V_34 + V_464 + V_459 ) ;
goto V_477;
}
F_349 ( NULL , V_462 ) ;
F_13 ( & V_462 -> V_480 ) ;
goto V_465;
}
V_484:
F_11 ( & V_13 -> V_10 -> V_486 ) ;
if ( V_3 &&
V_13 -> V_10 -> V_456 <
V_34 + V_464 + V_459 ) {
F_13 ( & V_13 -> V_10 -> V_486 ) ;
goto V_465;
}
F_13 ( & V_13 -> V_10 -> V_486 ) ;
V_31 = F_351 ( V_13 , V_103 ,
V_34 , V_459 ) ;
if ( ! V_31 && ! V_470 && ! V_3 &&
V_465 > V_485 ) {
F_339 ( V_13 ,
V_34 + V_459 ) ;
V_470 = true ;
goto V_477;
} else if ( ! V_31 ) {
if ( ! V_3 )
V_472 = true ;
goto V_465;
}
V_482:
V_103 = F_338 ( V_33 , V_31 ) ;
if ( V_103 + V_34 >
V_463 -> V_20 . V_21 + V_463 -> V_20 . V_31 ) {
F_29 ( V_463 , V_31 , V_34 ) ;
goto V_465;
}
if ( V_31 < V_103 )
F_29 ( V_463 , V_31 ,
V_103 - V_31 ) ;
F_22 ( V_31 > V_103 ) ;
V_27 = F_324 ( V_463 , V_34 ,
V_466 ) ;
if ( V_27 == - V_174 ) {
F_29 ( V_463 , V_31 , V_34 ) ;
goto V_465;
}
V_204 -> V_21 = V_103 ;
V_204 -> V_31 = V_34 ;
F_352 ( V_458 , V_13 ,
V_103 , V_34 ) ;
if ( V_463 != V_13 )
F_6 ( V_463 ) ;
F_6 ( V_13 ) ;
break;
V_465:
V_469 = false ;
V_470 = false ;
F_22 ( V_457 != F_342 ( V_13 ) ) ;
if ( V_463 != V_13 )
F_6 ( V_463 ) ;
F_6 ( V_13 ) ;
}
F_44 ( & V_99 -> V_281 ) ;
if ( ! V_204 -> V_21 && V_465 >= V_487 && V_472 )
goto V_478;
if ( ! V_204 -> V_21 && ++ V_457 < V_279 )
goto V_478;
if ( ! V_204 -> V_21 && V_465 < V_483 ) {
V_457 = 0 ;
V_465 ++ ;
if ( V_465 == V_488 ) {
V_27 = F_246 ( V_83 , V_33 , V_302 ,
V_321 ) ;
if ( V_27 < 0 && V_27 != - V_322 ) {
F_149 ( V_83 ,
V_33 , V_27 ) ;
goto V_69;
}
}
if ( V_465 == V_483 ) {
V_459 = 0 ;
V_464 = 0 ;
}
goto V_478;
} else if ( ! V_204 -> V_21 ) {
V_27 = - V_322 ;
} else if ( V_204 -> V_21 ) {
V_27 = 0 ;
}
V_69:
return V_27 ;
}
static void F_258 ( struct V_96 * V_12 , T_2 V_313 ,
int V_489 )
{
struct V_1 * V_2 ;
int V_457 = 0 ;
F_11 ( & V_12 -> V_49 ) ;
F_172 ( V_337 L_16 ,
( unsigned long long ) V_12 -> V_6 ,
( unsigned long long ) ( V_12 -> V_272 - V_12 -> V_273 -
V_12 -> V_282 - V_12 -> V_283 -
V_12 -> V_284 ) ,
( V_12 -> V_102 ) ? L_4 : L_17 ) ;
F_172 ( V_337 L_18
L_19 ,
( unsigned long long ) V_12 -> V_272 ,
( unsigned long long ) V_12 -> V_273 ,
( unsigned long long ) V_12 -> V_282 ,
( unsigned long long ) V_12 -> V_283 ,
( unsigned long long ) V_12 -> V_285 ,
( unsigned long long ) V_12 -> V_284 ) ;
F_13 ( & V_12 -> V_49 ) ;
if ( ! V_489 )
return;
F_35 ( & V_12 -> V_281 ) ;
V_74:
F_345 (cache, &info->block_groups[index], list) {
F_11 ( & V_2 -> V_49 ) ;
F_172 ( V_337 L_20 ,
( unsigned long long ) V_2 -> V_20 . V_21 ,
( unsigned long long ) V_2 -> V_20 . V_31 ,
( unsigned long long ) F_73 ( & V_2 -> V_111 ) ,
( unsigned long long ) V_2 -> V_8 ,
( unsigned long long ) V_2 -> V_9 ,
V_2 -> V_112 ? L_21 : L_4 ) ;
F_353 ( V_2 , V_313 ) ;
F_13 ( & V_2 -> V_49 ) ;
}
if ( ++ V_457 < V_279 )
goto V_74;
F_44 ( & V_12 -> V_281 ) ;
}
int F_354 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
T_2 V_34 , T_2 V_490 ,
T_2 V_459 , T_2 V_460 ,
struct V_65 * V_204 , T_2 V_302 )
{
bool V_491 = false ;
int V_27 ;
V_302 = F_244 ( V_33 , V_302 ) ;
V_74:
F_8 ( V_34 < V_33 -> V_316 ) ;
V_27 = F_343 ( V_83 , V_33 , V_34 , V_459 ,
V_460 , V_204 , V_302 ) ;
if ( V_27 == - V_322 ) {
if ( ! V_491 ) {
V_34 = V_34 >> 1 ;
V_34 = V_34 & ~ ( V_33 -> V_316 - 1 ) ;
V_34 = F_72 ( V_34 , V_490 ) ;
if ( V_34 == V_490 )
V_491 = true ;
goto V_74;
} else if ( F_225 ( V_33 , V_336 ) ) {
struct V_96 * V_325 ;
V_325 = F_66 ( V_33 -> V_35 , V_302 ) ;
F_172 ( V_230 L_22
L_23 , ( unsigned long long ) V_302 ,
( unsigned long long ) V_34 ) ;
if ( V_325 )
F_258 ( V_325 , V_34 , 1 ) ;
}
}
F_355 ( V_33 , V_204 -> V_21 , V_204 -> V_31 ) ;
return V_27 ;
}
static int F_356 ( struct V_32 * V_33 ,
T_2 V_30 , T_2 V_114 , int V_492 )
{
struct V_1 * V_2 ;
int V_27 = 0 ;
V_2 = F_65 ( V_33 -> V_35 , V_30 ) ;
if ( ! V_2 ) {
F_172 ( V_230 L_24 ,
( unsigned long long ) V_30 ) ;
return - V_322 ;
}
if ( F_225 ( V_33 , V_441 ) )
V_27 = F_143 ( V_33 , V_30 , V_114 , NULL ) ;
if ( V_492 )
F_321 ( V_33 , V_2 , V_30 , V_114 , 1 ) ;
else {
F_29 ( V_2 , V_30 , V_114 ) ;
F_324 ( V_2 , V_114 , V_437 ) ;
}
F_6 ( V_2 ) ;
F_357 ( V_33 , V_30 , V_114 ) ;
return V_27 ;
}
int F_358 ( struct V_32 * V_33 ,
T_2 V_30 , T_2 V_114 )
{
return F_356 ( V_33 , V_30 , V_114 , 0 ) ;
}
int F_359 ( struct V_32 * V_33 ,
T_2 V_30 , T_2 V_114 )
{
return F_356 ( V_33 , V_30 , V_114 , 1 ) ;
}
static int F_152 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
T_2 V_16 , T_2 V_145 ,
T_2 V_6 , T_2 V_105 , T_2 V_31 ,
struct V_65 * V_204 , int V_133 )
{
int V_27 ;
struct V_11 * V_35 = V_33 -> V_35 ;
struct V_119 * V_493 ;
struct V_161 * V_162 ;
struct V_61 * V_62 ;
struct V_63 * V_64 ;
int type ;
T_3 V_54 ;
if ( V_16 > 0 )
type = V_153 ;
else
type = V_154 ;
V_54 = sizeof( * V_493 ) + F_126 ( type ) ;
V_62 = F_32 () ;
if ( ! V_62 )
return - V_85 ;
V_62 -> V_200 = 1 ;
V_27 = F_107 ( V_83 , V_35 -> V_60 , V_62 ,
V_204 , V_54 ) ;
if ( V_27 ) {
F_48 ( V_62 ) ;
return V_27 ;
}
V_64 = V_62 -> V_78 [ 0 ] ;
V_493 = F_79 ( V_64 , V_62 -> V_79 [ 0 ] ,
struct V_119 ) ;
F_91 ( V_64 , V_493 , V_133 ) ;
F_92 ( V_64 , V_493 , V_83 -> V_262 ) ;
F_93 ( V_64 , V_493 ,
V_6 | V_144 ) ;
V_162 = (struct V_161 * ) ( V_493 + 1 ) ;
F_133 ( V_64 , V_162 , type ) ;
if ( V_16 > 0 ) {
struct V_157 * V_150 ;
V_150 = (struct V_157 * ) ( V_162 + 1 ) ;
F_134 ( V_64 , V_162 , V_16 ) ;
F_108 ( V_64 , V_150 , V_133 ) ;
} else {
struct V_149 * V_150 ;
V_150 = (struct V_149 * ) ( & V_162 -> V_31 ) ;
F_110 ( V_64 , V_150 , V_145 ) ;
F_111 ( V_64 , V_150 , V_105 ) ;
F_112 ( V_64 , V_150 , V_31 ) ;
F_113 ( V_64 , V_150 , V_133 ) ;
}
F_96 ( V_62 -> V_78 [ 0 ] ) ;
F_48 ( V_62 ) ;
V_27 = F_315 ( V_83 , V_33 , V_204 -> V_21 , V_204 -> V_31 , 1 ) ;
if ( V_27 ) {
F_172 ( V_230 L_25
L_26 , ( unsigned long long ) V_204 -> V_21 ,
( unsigned long long ) V_204 -> V_31 ) ;
F_84 () ;
}
return V_27 ;
}
static int F_158 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
T_2 V_16 , T_2 V_145 ,
T_2 V_6 , struct V_424 * V_20 ,
int V_165 , struct V_65 * V_204 )
{
int V_27 ;
struct V_11 * V_35 = V_33 -> V_35 ;
struct V_119 * V_493 ;
struct V_137 * V_494 ;
struct V_161 * V_162 ;
struct V_61 * V_62 ;
struct V_63 * V_64 ;
T_3 V_54 = sizeof( * V_493 ) + sizeof( * V_494 ) + sizeof( * V_162 ) ;
V_62 = F_32 () ;
if ( ! V_62 )
return - V_85 ;
V_62 -> V_200 = 1 ;
V_27 = F_107 ( V_83 , V_35 -> V_60 , V_62 ,
V_204 , V_54 ) ;
if ( V_27 ) {
F_48 ( V_62 ) ;
return V_27 ;
}
V_64 = V_62 -> V_78 [ 0 ] ;
V_493 = F_79 ( V_64 , V_62 -> V_79 [ 0 ] ,
struct V_119 ) ;
F_91 ( V_64 , V_493 , 1 ) ;
F_92 ( V_64 , V_493 , V_83 -> V_262 ) ;
F_93 ( V_64 , V_493 ,
V_6 | V_143 ) ;
V_494 = (struct V_137 * ) ( V_493 + 1 ) ;
F_154 ( V_64 , V_494 , V_20 ) ;
F_95 ( V_64 , V_494 , V_165 ) ;
V_162 = (struct V_161 * ) ( V_494 + 1 ) ;
if ( V_16 > 0 ) {
F_22 ( ! ( V_6 & V_127 ) ) ;
F_133 ( V_64 , V_162 ,
V_163 ) ;
F_134 ( V_64 , V_162 , V_16 ) ;
} else {
F_133 ( V_64 , V_162 ,
V_164 ) ;
F_134 ( V_64 , V_162 , V_145 ) ;
}
F_96 ( V_64 ) ;
F_48 ( V_62 ) ;
V_27 = F_315 ( V_83 , V_33 , V_204 -> V_21 , V_204 -> V_31 , 1 ) ;
if ( V_27 ) {
F_172 ( V_230 L_25
L_26 , ( unsigned long long ) V_204 -> V_21 ,
( unsigned long long ) V_204 -> V_31 ) ;
F_84 () ;
}
return V_27 ;
}
int F_360 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
T_2 V_145 , T_2 V_105 ,
T_2 V_31 , struct V_65 * V_204 )
{
int V_27 ;
F_22 ( V_145 == V_198 ) ;
V_27 = F_147 ( V_33 -> V_35 , V_83 , V_204 -> V_21 ,
V_204 -> V_31 , 0 ,
V_145 , V_105 , V_31 ,
V_221 , NULL , 0 ) ;
return V_27 ;
}
int F_361 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
T_2 V_145 , T_2 V_105 , T_2 V_31 ,
struct V_65 * V_204 )
{
int V_27 ;
struct V_1 * V_13 ;
struct V_47 * V_51 ;
T_2 V_30 = V_204 -> V_21 ;
T_2 V_34 = V_204 -> V_31 ;
V_13 = F_65 ( V_33 -> V_35 , V_204 -> V_21 ) ;
F_49 ( V_13 , V_83 , NULL , 0 ) ;
V_51 = F_25 ( V_13 ) ;
if ( ! V_51 ) {
F_22 ( ! F_1 ( V_13 ) ) ;
V_27 = F_323 ( V_13 , V_30 , V_34 ) ;
F_22 ( V_27 ) ;
} else {
F_34 ( & V_51 -> V_75 ) ;
if ( V_30 >= V_51 -> V_80 ) {
V_27 = F_17 ( V_33 , V_30 , V_34 ) ;
F_22 ( V_27 ) ;
} else if ( V_30 + V_34 <= V_51 -> V_80 ) {
V_27 = F_323 ( V_13 ,
V_30 , V_34 ) ;
F_22 ( V_27 ) ;
} else {
V_34 = V_51 -> V_80 - V_30 ;
V_27 = F_323 ( V_13 ,
V_30 , V_34 ) ;
F_22 ( V_27 ) ;
V_30 = V_51 -> V_80 ;
V_34 = V_204 -> V_21 + V_204 -> V_31 -
V_51 -> V_80 ;
V_27 = F_17 ( V_33 , V_30 , V_34 ) ;
F_22 ( V_27 ) ;
}
F_45 ( & V_51 -> V_75 ) ;
F_26 ( V_51 ) ;
}
V_27 = F_324 ( V_13 , V_204 -> V_31 ,
V_467 ) ;
F_22 ( V_27 ) ;
F_6 ( V_13 ) ;
V_27 = F_152 ( V_83 , V_33 , 0 , V_145 ,
0 , V_105 , V_31 , V_204 , 1 ) ;
return V_27 ;
}
struct V_63 * F_362 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
T_2 V_25 , T_3 V_495 ,
int V_165 )
{
struct V_63 * V_244 ;
V_244 = F_363 ( V_33 , V_25 , V_495 ) ;
if ( ! V_244 )
return F_364 ( - V_85 ) ;
F_365 ( V_244 , V_83 -> V_262 ) ;
F_366 ( V_33 -> V_240 . V_21 , V_244 , V_165 ) ;
F_367 ( V_244 ) ;
F_368 ( V_83 , V_33 , V_244 ) ;
F_337 ( V_496 , & V_244 -> V_451 ) ;
F_369 ( V_244 ) ;
F_370 ( V_244 ) ;
if ( V_33 -> V_240 . V_21 == V_198 ) {
if ( V_33 -> V_497 % 2 == 0 )
F_319 ( & V_33 -> V_498 , V_244 -> V_30 ,
V_244 -> V_30 + V_244 -> V_114 - 1 , V_38 ) ;
else
F_371 ( & V_33 -> V_498 , V_244 -> V_30 ,
V_244 -> V_30 + V_244 -> V_114 - 1 , V_38 ) ;
} else {
F_319 ( & V_83 -> V_128 -> V_499 , V_244 -> V_30 ,
V_244 -> V_30 + V_244 -> V_114 - 1 , V_38 ) ;
}
V_83 -> V_500 ++ ;
return V_244 ;
}
static struct V_327 *
F_372 ( struct V_82 * V_83 ,
struct V_32 * V_33 , T_3 V_495 )
{
struct V_327 * V_358 ;
struct V_327 * V_328 = & V_33 -> V_35 -> V_329 ;
int V_27 ;
V_358 = F_277 ( V_83 , V_33 ) ;
if ( V_358 -> V_54 == 0 ) {
V_27 = F_274 ( V_33 , V_358 , V_495 ,
V_369 ) ;
if ( V_27 && V_358 != V_328 ) {
V_27 = F_278 ( V_328 , V_495 ) ;
if ( ! V_27 )
return V_328 ;
return F_364 ( V_27 ) ;
} else if ( V_27 ) {
return F_364 ( V_27 ) ;
}
return V_358 ;
}
V_27 = F_278 ( V_358 , V_495 ) ;
if ( ! V_27 )
return V_358 ;
if ( V_27 && ! V_358 -> V_501 ) {
static F_373 ( V_502 ,
V_503 ,
2 ) ;
if ( F_374 ( & V_502 ) )
F_375 ( 1 , V_218 L_27 ,
V_27 ) ;
V_27 = F_274 ( V_33 , V_358 , V_495 ,
V_369 ) ;
if ( ! V_27 ) {
return V_358 ;
} else if ( V_27 && V_358 != V_328 ) {
V_27 = F_278 ( V_328 , V_495 ) ;
if ( ! V_27 )
return V_328 ;
}
}
return F_364 ( - V_322 ) ;
}
static void F_376 ( struct V_11 * V_35 ,
struct V_327 * V_358 , T_3 V_495 )
{
F_279 ( V_358 , V_495 , 0 ) ;
F_280 ( V_35 , V_358 , NULL , 0 ) ;
}
struct V_63 * F_377 ( struct V_82 * V_83 ,
struct V_32 * V_33 , T_3 V_495 ,
T_2 V_16 , T_2 V_145 ,
struct V_424 * V_20 , int V_165 ,
T_2 V_504 , T_2 V_459 )
{
struct V_65 V_204 ;
struct V_327 * V_358 ;
struct V_63 * V_244 ;
T_2 V_6 = 0 ;
int V_27 ;
V_358 = F_372 ( V_83 , V_33 , V_495 ) ;
if ( F_218 ( V_358 ) )
return F_378 ( V_358 ) ;
V_27 = F_354 ( V_83 , V_33 , V_495 , V_495 ,
V_459 , V_504 , & V_204 , 0 ) ;
if ( V_27 ) {
F_376 ( V_33 -> V_35 , V_358 , V_495 ) ;
return F_364 ( V_27 ) ;
}
V_244 = F_362 ( V_83 , V_33 , V_204 . V_21 ,
V_495 , V_165 ) ;
F_22 ( F_218 ( V_244 ) ) ;
if ( V_145 == V_505 ) {
if ( V_16 == 0 )
V_16 = V_204 . V_21 ;
V_6 |= V_127 ;
} else
F_22 ( V_16 > 0 ) ;
if ( V_145 != V_198 ) {
struct V_176 * V_130 ;
V_130 = F_191 ( sizeof( * V_130 ) , V_38 ) ;
F_22 ( ! V_130 ) ;
if ( V_20 )
memcpy ( & V_130 -> V_20 , V_20 , sizeof( V_130 -> V_20 ) ) ;
else
memset ( & V_130 -> V_20 , 0 , sizeof( V_130 -> V_20 ) ) ;
V_130 -> V_132 = V_6 ;
V_130 -> V_207 = 1 ;
V_130 -> V_131 = 1 ;
V_130 -> V_180 = 0 ;
V_27 = F_146 ( V_33 -> V_35 , V_83 ,
V_204 . V_21 ,
V_204 . V_31 , V_16 , V_145 ,
V_165 , V_221 ,
V_130 , 0 ) ;
F_22 ( V_27 ) ;
}
return V_244 ;
}
static T_1 void F_379 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_506 * V_507 ,
struct V_61 * V_62 )
{
T_2 V_25 ;
T_2 V_265 ;
T_2 V_115 ;
T_2 V_6 ;
T_3 V_68 ;
T_3 V_495 ;
struct V_65 V_20 ;
struct V_63 * V_508 ;
int V_27 ;
int V_509 ;
int V_510 = 0 ;
if ( V_62 -> V_79 [ V_507 -> V_165 ] < V_507 -> V_511 ) {
V_507 -> V_512 = V_507 -> V_512 * 2 / 3 ;
V_507 -> V_512 = F_72 ( V_507 -> V_512 , 2 ) ;
} else {
V_507 -> V_512 = V_507 -> V_512 * 3 / 2 ;
V_507 -> V_512 = F_185 ( int , V_507 -> V_512 ,
F_380 ( V_33 ) ) ;
}
V_508 = V_62 -> V_78 [ V_507 -> V_165 ] ;
V_68 = F_37 ( V_508 ) ;
V_495 = F_209 ( V_33 , V_507 -> V_165 - 1 ) ;
for ( V_509 = V_62 -> V_79 [ V_507 -> V_165 ] ; V_509 < V_68 ; V_509 ++ ) {
if ( V_510 >= V_507 -> V_512 )
break;
F_46 () ;
V_25 = F_208 ( V_508 , V_509 ) ;
V_265 = F_381 ( V_508 , V_509 ) ;
if ( V_509 == V_62 -> V_79 [ V_507 -> V_165 ] )
goto V_72;
if ( V_507 -> V_513 == V_514 &&
V_265 <= V_33 -> V_240 . V_31 )
continue;
V_27 = F_77 ( V_83 , V_33 , V_25 , V_495 ,
& V_115 , & V_6 ) ;
if ( V_27 < 0 )
continue;
F_22 ( V_115 == 0 ) ;
if ( V_507 -> V_513 == V_515 ) {
if ( V_115 == 1 )
goto V_72;
if ( V_507 -> V_165 == 1 &&
( V_6 & V_127 ) )
continue;
if ( ! V_507 -> V_516 ||
V_265 <= V_33 -> V_240 . V_31 )
continue;
F_124 ( V_508 , & V_20 , V_509 ) ;
V_27 = F_382 ( & V_20 ,
& V_507 -> V_517 ) ;
if ( V_27 < 0 )
continue;
} else {
if ( V_507 -> V_165 == 1 &&
( V_6 & V_127 ) )
continue;
}
V_72:
V_27 = F_383 ( V_33 , V_25 , V_495 ,
V_265 ) ;
if ( V_27 )
break;
V_510 ++ ;
}
V_507 -> V_511 = V_509 ;
}
static T_1 int F_384 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_61 * V_62 ,
struct V_506 * V_507 , int V_518 )
{
int V_165 = V_507 -> V_165 ;
struct V_63 * V_508 = V_62 -> V_78 [ V_165 ] ;
T_2 V_519 = V_127 ;
int V_27 ;
if ( V_507 -> V_513 == V_514 &&
F_201 ( V_508 ) != V_33 -> V_240 . V_21 )
return 1 ;
if ( V_518 &&
( ( V_507 -> V_513 == V_515 && V_507 -> V_115 [ V_165 ] != 1 ) ||
( V_507 -> V_513 == V_514 && ! ( V_507 -> V_6 [ V_165 ] & V_519 ) ) ) ) {
F_22 ( ! V_62 -> V_520 [ V_165 ] ) ;
V_27 = F_77 ( V_83 , V_33 ,
V_508 -> V_30 , V_508 -> V_114 ,
& V_507 -> V_115 [ V_165 ] ,
& V_507 -> V_6 [ V_165 ] ) ;
F_22 ( V_27 == - V_85 ) ;
if ( V_27 )
return V_27 ;
F_22 ( V_507 -> V_115 [ V_165 ] == 0 ) ;
}
if ( V_507 -> V_513 == V_515 ) {
if ( V_507 -> V_115 [ V_165 ] > 1 )
return 1 ;
if ( V_62 -> V_520 [ V_165 ] && ! V_507 -> V_171 ) {
F_385 ( V_508 , V_62 -> V_520 [ V_165 ] ) ;
V_62 -> V_520 [ V_165 ] = 0 ;
}
return 0 ;
}
if ( ! ( V_507 -> V_6 [ V_165 ] & V_519 ) ) {
F_22 ( ! V_62 -> V_520 [ V_165 ] ) ;
V_27 = F_210 ( V_83 , V_33 , V_508 , 1 , V_507 -> V_521 ) ;
F_22 ( V_27 ) ;
V_27 = F_211 ( V_83 , V_33 , V_508 , 0 , V_507 -> V_521 ) ;
F_22 ( V_27 ) ;
V_27 = F_190 ( V_83 , V_33 , V_508 -> V_30 ,
V_508 -> V_114 , V_519 , 0 ) ;
F_22 ( V_27 ) ;
V_507 -> V_6 [ V_165 ] |= V_519 ;
}
if ( V_62 -> V_520 [ V_165 ] && V_165 > 0 ) {
F_385 ( V_508 , V_62 -> V_520 [ V_165 ] ) ;
V_62 -> V_520 [ V_165 ] = 0 ;
}
return 0 ;
}
static T_1 int F_386 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_61 * V_62 ,
struct V_506 * V_507 , int * V_518 )
{
T_2 V_25 ;
T_2 V_265 ;
T_2 V_16 ;
T_3 V_495 ;
struct V_65 V_20 ;
struct V_63 * V_215 ;
int V_165 = V_507 -> V_165 ;
int V_72 = 0 ;
int V_27 = 0 ;
V_265 = F_381 ( V_62 -> V_78 [ V_165 ] ,
V_62 -> V_79 [ V_165 ] ) ;
if ( V_507 -> V_513 == V_514 &&
V_265 <= V_33 -> V_240 . V_31 ) {
* V_518 = 1 ;
return 1 ;
}
V_25 = F_208 ( V_62 -> V_78 [ V_165 ] , V_62 -> V_79 [ V_165 ] ) ;
V_495 = F_209 ( V_33 , V_165 - 1 ) ;
V_215 = F_387 ( V_33 , V_25 , V_495 ) ;
if ( ! V_215 ) {
V_215 = F_363 ( V_33 , V_25 , V_495 ) ;
if ( ! V_215 )
return - V_85 ;
V_72 = 1 ;
}
F_367 ( V_215 ) ;
F_369 ( V_215 ) ;
V_27 = F_77 ( V_83 , V_33 , V_25 , V_495 ,
& V_507 -> V_115 [ V_165 - 1 ] ,
& V_507 -> V_6 [ V_165 - 1 ] ) ;
if ( V_27 < 0 ) {
F_388 ( V_215 ) ;
return V_27 ;
}
F_22 ( V_507 -> V_115 [ V_165 - 1 ] == 0 ) ;
* V_518 = 0 ;
if ( V_507 -> V_513 == V_515 ) {
if ( V_507 -> V_115 [ V_165 - 1 ] > 1 ) {
if ( V_165 == 1 &&
( V_507 -> V_6 [ 0 ] & V_127 ) )
goto V_522;
if ( ! V_507 -> V_516 ||
V_265 <= V_33 -> V_240 . V_31 )
goto V_522;
F_124 ( V_62 -> V_78 [ V_165 ] , & V_20 ,
V_62 -> V_79 [ V_165 ] ) ;
V_27 = F_382 ( & V_20 , & V_507 -> V_517 ) ;
if ( V_27 < 0 )
goto V_522;
V_507 -> V_513 = V_514 ;
V_507 -> V_523 = V_165 - 1 ;
}
} else {
if ( V_165 == 1 &&
( V_507 -> V_6 [ 0 ] & V_127 ) )
goto V_522;
}
if ( ! F_389 ( V_215 , V_265 , 0 ) ) {
F_388 ( V_215 ) ;
F_390 ( V_215 ) ;
V_215 = NULL ;
* V_518 = 1 ;
}
if ( ! V_215 ) {
if ( V_72 && V_165 == 1 )
F_379 ( V_83 , V_33 , V_507 , V_62 ) ;
V_215 = F_391 ( V_33 , V_25 , V_495 , V_265 ) ;
if ( ! V_215 )
return - V_210 ;
F_367 ( V_215 ) ;
F_369 ( V_215 ) ;
}
V_165 -- ;
F_22 ( V_165 != F_202 ( V_215 ) ) ;
V_62 -> V_78 [ V_165 ] = V_215 ;
V_62 -> V_79 [ V_165 ] = 0 ;
V_62 -> V_520 [ V_165 ] = V_524 ;
V_507 -> V_165 = V_165 ;
if ( V_507 -> V_165 == 1 )
V_507 -> V_511 = 0 ;
return 0 ;
V_522:
V_507 -> V_115 [ V_165 - 1 ] = 0 ;
V_507 -> V_6 [ V_165 - 1 ] = 0 ;
if ( V_507 -> V_513 == V_515 ) {
if ( V_507 -> V_6 [ V_165 ] & V_127 ) {
V_16 = V_62 -> V_78 [ V_165 ] -> V_30 ;
} else {
F_22 ( V_33 -> V_240 . V_21 !=
F_201 ( V_62 -> V_78 [ V_165 ] ) ) ;
V_16 = 0 ;
}
V_27 = V_250 ( V_83 , V_33 , V_25 , V_495 , V_16 ,
V_33 -> V_240 . V_21 , V_165 - 1 , 0 , 0 ) ;
F_22 ( V_27 ) ;
}
F_388 ( V_215 ) ;
F_390 ( V_215 ) ;
* V_518 = 1 ;
return 1 ;
}
static T_1 int F_392 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_61 * V_62 ,
struct V_506 * V_507 )
{
int V_27 ;
int V_165 = V_507 -> V_165 ;
struct V_63 * V_508 = V_62 -> V_78 [ V_165 ] ;
T_2 V_16 = 0 ;
if ( V_507 -> V_513 == V_514 ) {
F_22 ( V_507 -> V_523 < V_165 ) ;
if ( V_165 < V_507 -> V_523 )
goto V_69;
V_27 = F_40 ( V_62 , V_165 + 1 , & V_507 -> V_517 ) ;
if ( V_27 > 0 )
V_507 -> V_516 = 0 ;
V_507 -> V_513 = V_515 ;
V_507 -> V_523 = - 1 ;
V_62 -> V_79 [ V_165 ] = 0 ;
if ( ! V_62 -> V_520 [ V_165 ] ) {
F_22 ( V_165 == 0 ) ;
F_367 ( V_508 ) ;
F_369 ( V_508 ) ;
V_62 -> V_520 [ V_165 ] = V_524 ;
V_27 = F_77 ( V_83 , V_33 ,
V_508 -> V_30 , V_508 -> V_114 ,
& V_507 -> V_115 [ V_165 ] ,
& V_507 -> V_6 [ V_165 ] ) ;
if ( V_27 < 0 ) {
F_385 ( V_508 , V_62 -> V_520 [ V_165 ] ) ;
V_62 -> V_520 [ V_165 ] = 0 ;
return V_27 ;
}
F_22 ( V_507 -> V_115 [ V_165 ] == 0 ) ;
if ( V_507 -> V_115 [ V_165 ] == 1 ) {
F_385 ( V_508 , V_62 -> V_520 [ V_165 ] ) ;
V_62 -> V_520 [ V_165 ] = 0 ;
return 1 ;
}
}
}
F_22 ( V_507 -> V_115 [ V_165 ] > 1 && ! V_62 -> V_520 [ V_165 ] ) ;
if ( V_507 -> V_115 [ V_165 ] == 1 ) {
if ( V_165 == 0 ) {
if ( V_507 -> V_6 [ V_165 ] & V_127 )
V_27 = F_211 ( V_83 , V_33 , V_508 , 1 ,
V_507 -> V_521 ) ;
else
V_27 = F_211 ( V_83 , V_33 , V_508 , 0 ,
V_507 -> V_521 ) ;
F_22 ( V_27 ) ;
}
if ( ! V_62 -> V_520 [ V_165 ] &&
F_335 ( V_508 ) == V_83 -> V_262 ) {
F_367 ( V_508 ) ;
F_369 ( V_508 ) ;
V_62 -> V_520 [ V_165 ] = V_524 ;
}
F_368 ( V_83 , V_33 , V_508 ) ;
}
if ( V_508 == V_33 -> V_129 ) {
if ( V_507 -> V_6 [ V_165 ] & V_127 )
V_16 = V_508 -> V_30 ;
else
F_22 ( V_33 -> V_240 . V_21 !=
F_201 ( V_508 ) ) ;
} else {
if ( V_507 -> V_6 [ V_165 + 1 ] & V_127 )
V_16 = V_62 -> V_78 [ V_165 + 1 ] -> V_30 ;
else
F_22 ( V_33 -> V_240 . V_21 !=
F_201 ( V_62 -> V_78 [ V_165 + 1 ] ) ) ;
}
F_334 ( V_83 , V_33 , V_508 , V_16 , V_507 -> V_115 [ V_165 ] == 1 ) ;
V_69:
V_507 -> V_115 [ V_165 ] = 0 ;
V_507 -> V_6 [ V_165 ] = 0 ;
return 0 ;
}
static T_1 int F_393 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_61 * V_62 ,
struct V_506 * V_507 )
{
int V_165 = V_507 -> V_165 ;
int V_518 = 1 ;
int V_27 ;
while ( V_165 >= 0 ) {
V_27 = F_384 ( V_83 , V_33 , V_62 , V_507 , V_518 ) ;
if ( V_27 > 0 )
break;
if ( V_165 == 0 )
break;
if ( V_62 -> V_79 [ V_165 ] >=
F_37 ( V_62 -> V_78 [ V_165 ] ) )
break;
V_27 = F_386 ( V_83 , V_33 , V_62 , V_507 , & V_518 ) ;
if ( V_27 > 0 ) {
V_62 -> V_79 [ V_165 ] ++ ;
continue;
} else if ( V_27 < 0 )
return V_27 ;
V_165 = V_507 -> V_165 ;
}
return 0 ;
}
static T_1 int F_394 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_61 * V_62 ,
struct V_506 * V_507 , int V_525 )
{
int V_165 = V_507 -> V_165 ;
int V_27 ;
V_62 -> V_79 [ V_165 ] = F_37 ( V_62 -> V_78 [ V_165 ] ) ;
while ( V_165 < V_525 && V_62 -> V_78 [ V_165 ] ) {
V_507 -> V_165 = V_165 ;
if ( V_62 -> V_79 [ V_165 ] + 1 <
F_37 ( V_62 -> V_78 [ V_165 ] ) ) {
V_62 -> V_79 [ V_165 ] ++ ;
return 0 ;
} else {
V_27 = F_392 ( V_83 , V_33 , V_62 , V_507 ) ;
if ( V_27 > 0 )
return 0 ;
if ( V_62 -> V_520 [ V_165 ] ) {
F_385 ( V_62 -> V_78 [ V_165 ] ,
V_62 -> V_520 [ V_165 ] ) ;
V_62 -> V_520 [ V_165 ] = 0 ;
}
F_390 ( V_62 -> V_78 [ V_165 ] ) ;
V_62 -> V_78 [ V_165 ] = NULL ;
V_165 ++ ;
}
}
return 1 ;
}
int F_395 ( struct V_32 * V_33 ,
struct V_327 * V_358 , int V_516 ,
int V_521 )
{
struct V_61 * V_62 ;
struct V_82 * V_83 ;
struct V_32 * V_235 = V_33 -> V_35 -> V_235 ;
struct V_526 * V_241 = & V_33 -> V_241 ;
struct V_506 * V_507 ;
struct V_65 V_20 ;
int V_77 = 0 ;
int V_27 ;
int V_165 ;
V_62 = F_32 () ;
if ( ! V_62 ) {
V_77 = - V_85 ;
goto V_69;
}
V_507 = F_51 ( sizeof( * V_507 ) , V_38 ) ;
if ( ! V_507 ) {
F_48 ( V_62 ) ;
V_77 = - V_85 ;
goto V_69;
}
V_83 = F_396 ( V_235 , 0 ) ;
if ( F_218 ( V_83 ) ) {
V_77 = F_219 ( V_83 ) ;
goto V_124;
}
if ( V_358 )
V_83 -> V_358 = V_358 ;
if ( F_397 ( & V_241 -> V_527 ) == 0 ) {
V_165 = F_202 ( V_33 -> V_129 ) ;
V_62 -> V_78 [ V_165 ] = F_398 ( V_33 ) ;
F_369 ( V_62 -> V_78 [ V_165 ] ) ;
V_62 -> V_79 [ V_165 ] = 0 ;
V_62 -> V_520 [ V_165 ] = V_524 ;
memset ( & V_507 -> V_517 , 0 ,
sizeof( V_507 -> V_517 ) ) ;
} else {
F_399 ( & V_20 , & V_241 -> V_527 ) ;
memcpy ( & V_507 -> V_517 , & V_20 ,
sizeof( V_507 -> V_517 ) ) ;
V_165 = V_241 -> V_528 ;
F_22 ( V_165 == 0 ) ;
V_62 -> V_529 = V_165 ;
V_27 = F_36 ( NULL , V_33 , & V_20 , V_62 , 0 , 0 ) ;
V_62 -> V_529 = 0 ;
if ( V_27 < 0 ) {
V_77 = V_27 ;
goto V_530;
}
F_8 ( V_27 > 0 ) ;
F_129 ( V_62 , 0 ) ;
V_165 = F_202 ( V_33 -> V_129 ) ;
while ( 1 ) {
F_367 ( V_62 -> V_78 [ V_165 ] ) ;
F_369 ( V_62 -> V_78 [ V_165 ] ) ;
V_27 = F_77 ( V_83 , V_33 ,
V_62 -> V_78 [ V_165 ] -> V_30 ,
V_62 -> V_78 [ V_165 ] -> V_114 ,
& V_507 -> V_115 [ V_165 ] ,
& V_507 -> V_6 [ V_165 ] ) ;
if ( V_27 < 0 ) {
V_77 = V_27 ;
goto V_530;
}
F_22 ( V_507 -> V_115 [ V_165 ] == 0 ) ;
if ( V_165 == V_241 -> V_528 )
break;
F_388 ( V_62 -> V_78 [ V_165 ] ) ;
F_8 ( V_507 -> V_115 [ V_165 ] != 1 ) ;
V_165 -- ;
}
}
V_507 -> V_165 = V_165 ;
V_507 -> V_523 = - 1 ;
V_507 -> V_513 = V_515 ;
V_507 -> V_516 = V_516 ;
V_507 -> V_171 = 0 ;
V_507 -> V_521 = V_521 ;
V_507 -> V_512 = F_380 ( V_33 ) ;
while ( 1 ) {
V_27 = F_393 ( V_83 , V_33 , V_62 , V_507 ) ;
if ( V_27 < 0 ) {
V_77 = V_27 ;
break;
}
V_27 = F_394 ( V_83 , V_33 , V_62 , V_507 , V_166 ) ;
if ( V_27 < 0 ) {
V_77 = V_27 ;
break;
}
if ( V_27 > 0 ) {
F_22 ( V_507 -> V_513 != V_515 ) ;
break;
}
if ( V_507 -> V_513 == V_515 ) {
V_165 = V_507 -> V_165 ;
F_400 ( V_62 -> V_78 [ V_165 ] ,
& V_241 -> V_527 ,
V_62 -> V_79 [ V_165 ] ) ;
V_241 -> V_528 = V_165 ;
}
F_22 ( V_507 -> V_165 == 0 ) ;
if ( F_401 ( V_83 , V_235 ) ) {
V_27 = F_402 ( V_83 , V_235 ,
& V_33 -> V_240 ,
V_241 ) ;
if ( V_27 ) {
F_149 ( V_83 , V_235 , V_27 ) ;
V_77 = V_27 ;
goto V_530;
}
F_403 ( V_83 , V_235 ) ;
V_83 = F_396 ( V_235 , 0 ) ;
if ( F_218 ( V_83 ) ) {
V_77 = F_219 ( V_83 ) ;
goto V_124;
}
if ( V_358 )
V_83 -> V_358 = V_358 ;
}
}
F_43 ( V_62 ) ;
if ( V_77 )
goto V_530;
V_27 = F_404 ( V_83 , V_235 , & V_33 -> V_240 ) ;
if ( V_27 ) {
F_149 ( V_83 , V_235 , V_27 ) ;
goto V_530;
}
if ( V_33 -> V_240 . V_21 != V_505 ) {
V_27 = F_405 ( V_235 , V_33 -> V_240 . V_21 ,
NULL , NULL ) ;
if ( V_27 < 0 ) {
F_149 ( V_83 , V_235 , V_27 ) ;
V_77 = V_27 ;
goto V_530;
} else if ( V_27 > 0 ) {
F_406 ( V_83 , V_235 ,
V_33 -> V_240 . V_21 ) ;
}
}
if ( V_33 -> V_531 ) {
F_407 ( V_235 -> V_35 , V_33 ) ;
} else {
F_390 ( V_33 -> V_129 ) ;
F_390 ( V_33 -> V_532 ) ;
F_9 ( V_33 ) ;
}
V_530:
F_403 ( V_83 , V_235 ) ;
V_124:
F_9 ( V_507 ) ;
F_48 ( V_62 ) ;
V_69:
if ( V_77 )
F_408 ( V_33 -> V_35 , V_77 ) ;
return V_77 ;
}
int F_409 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_63 * V_129 ,
struct V_63 * V_16 )
{
struct V_61 * V_62 ;
struct V_506 * V_507 ;
int V_165 ;
int V_533 ;
int V_27 = 0 ;
int V_534 ;
F_22 ( V_33 -> V_240 . V_21 != V_505 ) ;
V_62 = F_32 () ;
if ( ! V_62 )
return - V_85 ;
V_507 = F_51 ( sizeof( * V_507 ) , V_38 ) ;
if ( ! V_507 ) {
F_48 ( V_62 ) ;
return - V_85 ;
}
F_410 ( V_16 ) ;
V_533 = F_202 ( V_16 ) ;
F_411 ( V_16 ) ;
V_62 -> V_78 [ V_533 ] = V_16 ;
V_62 -> V_79 [ V_533 ] = F_37 ( V_16 ) ;
F_410 ( V_129 ) ;
V_165 = F_202 ( V_129 ) ;
V_62 -> V_78 [ V_165 ] = V_129 ;
V_62 -> V_79 [ V_165 ] = 0 ;
V_62 -> V_520 [ V_165 ] = V_524 ;
V_507 -> V_115 [ V_533 ] = 1 ;
V_507 -> V_6 [ V_533 ] = V_127 ;
V_507 -> V_165 = V_165 ;
V_507 -> V_523 = - 1 ;
V_507 -> V_513 = V_515 ;
V_507 -> V_516 = 0 ;
V_507 -> V_171 = 1 ;
V_507 -> V_521 = 1 ;
V_507 -> V_512 = F_380 ( V_33 ) ;
while ( 1 ) {
V_534 = F_393 ( V_83 , V_33 , V_62 , V_507 ) ;
if ( V_534 < 0 ) {
V_27 = V_534 ;
break;
}
V_534 = F_394 ( V_83 , V_33 , V_62 , V_507 , V_533 ) ;
if ( V_534 < 0 )
V_27 = V_534 ;
if ( V_534 != 0 )
break;
}
F_9 ( V_507 ) ;
F_48 ( V_62 ) ;
return V_27 ;
}
static T_2 F_412 ( struct V_32 * V_33 , T_2 V_6 )
{
T_2 V_306 ;
T_2 V_535 ;
V_535 = F_240 ( V_33 -> V_35 , V_6 ) ;
if ( V_535 )
return F_242 ( V_535 ) ;
V_306 = V_33 -> V_35 -> V_307 -> V_308 +
V_33 -> V_35 -> V_307 -> V_309 ;
V_535 = V_311 |
V_275 | V_276 ;
if ( V_306 == 1 ) {
V_535 |= V_274 ;
V_535 = V_6 & ~ V_535 ;
if ( V_6 & V_311 )
return V_535 ;
if ( V_6 & ( V_275 |
V_276 ) )
return V_535 | V_274 ;
} else {
if ( V_6 & V_535 )
return V_6 ;
V_535 |= V_274 ;
V_535 = V_6 & ~ V_535 ;
if ( V_6 & V_274 )
return V_535 | V_275 ;
}
return V_6 ;
}
static int F_413 ( struct V_1 * V_2 , int V_326 )
{
struct V_96 * V_325 = V_2 -> V_99 ;
T_2 V_34 ;
T_2 V_536 ;
int V_27 = - V_322 ;
if ( ( V_325 -> V_6 &
( V_296 | V_113 ) ) &&
! V_326 )
V_536 = 1 * 1024 * 1024 ;
else
V_536 = 0 ;
F_11 ( & V_325 -> V_49 ) ;
F_11 ( & V_2 -> V_49 ) ;
if ( V_2 -> V_112 ) {
V_27 = 0 ;
goto V_69;
}
V_34 = V_2 -> V_20 . V_31 - V_2 -> V_9 - V_2 -> V_8 -
V_2 -> V_44 - F_73 ( & V_2 -> V_111 ) ;
if ( V_325 -> V_273 + V_325 -> V_283 + V_325 -> V_282 +
V_325 -> V_285 + V_325 -> V_284 + V_34 +
V_536 <= V_325 -> V_272 ) {
V_325 -> V_284 += V_34 ;
V_2 -> V_112 = 1 ;
V_27 = 0 ;
}
V_69:
F_13 ( & V_2 -> V_49 ) ;
F_13 ( & V_325 -> V_49 ) ;
return V_27 ;
}
int F_414 ( struct V_32 * V_33 ,
struct V_1 * V_2 )
{
struct V_82 * V_83 ;
T_2 V_537 ;
int V_27 ;
F_22 ( V_2 -> V_112 ) ;
V_83 = F_245 ( V_33 ) ;
if ( F_218 ( V_83 ) )
return F_219 ( V_83 ) ;
V_537 = F_412 ( V_33 , V_2 -> V_6 ) ;
if ( V_537 != V_2 -> V_6 ) {
V_27 = F_246 ( V_83 , V_33 , V_537 ,
V_321 ) ;
if ( V_27 < 0 )
goto V_69;
}
V_27 = F_413 ( V_2 , 0 ) ;
if ( ! V_27 )
goto V_69;
V_537 = F_243 ( V_33 , V_2 -> V_99 -> V_6 ) ;
V_27 = F_246 ( V_83 , V_33 , V_537 ,
V_321 ) ;
if ( V_27 < 0 )
goto V_69;
V_27 = F_413 ( V_2 , 0 ) ;
V_69:
F_247 ( V_83 , V_33 ) ;
return V_27 ;
}
int F_415 ( struct V_82 * V_83 ,
struct V_32 * V_33 , T_2 type )
{
T_2 V_537 = F_243 ( V_33 , type ) ;
return F_246 ( V_83 , V_33 , V_537 ,
V_321 ) ;
}
static T_2 F_416 ( struct V_97 * V_538 )
{
struct V_1 * V_13 ;
T_2 V_539 = 0 ;
int V_109 ;
F_345 (block_group, groups_list, list) {
F_11 ( & V_13 -> V_49 ) ;
if ( ! V_13 -> V_112 ) {
F_13 ( & V_13 -> V_49 ) ;
continue;
}
if ( V_13 -> V_6 & ( V_275 |
V_276 |
V_274 ) )
V_109 = 2 ;
else
V_109 = 1 ;
V_539 += ( V_13 -> V_20 . V_31 -
F_73 ( & V_13 -> V_111 ) ) *
V_109 ;
F_13 ( & V_13 -> V_49 ) ;
}
return V_539 ;
}
T_2 F_417 ( struct V_96 * V_325 )
{
int V_41 ;
T_2 V_539 = 0 ;
F_11 ( & V_325 -> V_49 ) ;
for( V_41 = 0 ; V_41 < V_279 ; V_41 ++ )
if ( ! F_165 ( & V_325 -> V_280 [ V_41 ] ) )
V_539 += F_416 (
& V_325 -> V_280 [ V_41 ] ) ;
F_13 ( & V_325 -> V_49 ) ;
return V_539 ;
}
void F_418 ( struct V_32 * V_33 ,
struct V_1 * V_2 )
{
struct V_96 * V_325 = V_2 -> V_99 ;
T_2 V_34 ;
F_22 ( ! V_2 -> V_112 ) ;
F_11 ( & V_325 -> V_49 ) ;
F_11 ( & V_2 -> V_49 ) ;
V_34 = V_2 -> V_20 . V_31 - V_2 -> V_9 - V_2 -> V_8 -
V_2 -> V_44 - F_73 ( & V_2 -> V_111 ) ;
V_325 -> V_284 -= V_34 ;
V_2 -> V_112 = 0 ;
F_13 ( & V_2 -> V_49 ) ;
F_13 ( & V_325 -> V_49 ) ;
}
int F_419 ( struct V_32 * V_33 , T_2 V_25 )
{
struct V_1 * V_13 ;
struct V_96 * V_99 ;
struct V_540 * V_307 = V_33 -> V_35 -> V_307 ;
struct V_541 * V_542 ;
T_2 V_543 ;
T_2 V_544 = 1 ;
T_2 V_545 = 0 ;
T_2 V_301 ;
int V_457 ;
int V_102 = 0 ;
int V_27 = 0 ;
V_13 = F_65 ( V_33 -> V_35 , V_25 ) ;
if ( ! V_13 )
return - 1 ;
V_543 = F_73 ( & V_13 -> V_111 ) ;
if ( ! V_543 )
goto V_69;
V_99 = V_13 -> V_99 ;
F_11 ( & V_99 -> V_49 ) ;
V_102 = V_99 -> V_102 ;
if ( ( V_99 -> V_272 != V_13 -> V_20 . V_31 ) &&
( V_99 -> V_273 + V_99 -> V_283 +
V_99 -> V_282 + V_99 -> V_284 +
V_543 < V_99 -> V_272 ) ) {
F_13 ( & V_99 -> V_49 ) ;
goto V_69;
}
F_13 ( & V_99 -> V_49 ) ;
V_27 = - 1 ;
V_301 = F_240 ( V_33 -> V_35 , V_13 -> V_6 ) ;
if ( V_301 ) {
V_457 = F_341 ( F_242 ( V_301 ) ) ;
} else {
if ( V_102 )
goto V_69;
V_457 = F_342 ( V_13 ) ;
}
if ( V_457 == 0 ) {
V_544 = 4 ;
V_543 >>= 1 ;
} else if ( V_457 == 1 ) {
V_544 = 2 ;
} else if ( V_457 == 2 ) {
V_543 <<= 1 ;
} else if ( V_457 == 3 ) {
V_544 = V_307 -> V_308 ;
F_420 ( V_543 , V_544 ) ;
}
F_34 ( & V_33 -> V_35 -> V_339 ) ;
F_345 (device, &fs_devices->alloc_list, dev_alloc_list) {
T_2 V_546 ;
if ( V_542 -> V_272 > V_542 -> V_273 + V_543 &&
! V_542 -> V_547 ) {
V_27 = F_421 ( V_542 , V_543 ,
& V_546 , NULL ) ;
if ( ! V_27 )
V_545 ++ ;
if ( V_545 >= V_544 )
break;
V_27 = - 1 ;
}
}
F_45 ( & V_33 -> V_35 -> V_339 ) ;
V_69:
F_6 ( V_13 ) ;
return V_27 ;
}
static int F_422 ( struct V_32 * V_33 ,
struct V_61 * V_62 , struct V_65 * V_20 )
{
int V_27 = 0 ;
struct V_65 V_139 ;
struct V_63 * V_64 ;
int V_509 ;
V_27 = F_36 ( NULL , V_33 , V_20 , V_62 , 0 , 0 ) ;
if ( V_27 < 0 )
goto V_69;
while ( 1 ) {
V_509 = V_62 -> V_79 [ 0 ] ;
V_64 = V_62 -> V_78 [ 0 ] ;
if ( V_509 >= F_37 ( V_64 ) ) {
V_27 = F_42 ( V_33 , V_62 ) ;
if ( V_27 == 0 )
continue;
if ( V_27 < 0 )
goto V_69;
break;
}
F_39 ( V_64 , & V_139 , V_509 ) ;
if ( V_139 . V_21 >= V_20 -> V_21 &&
V_139 . type == V_175 ) {
V_27 = 0 ;
goto V_69;
}
V_62 -> V_79 [ 0 ] ++ ;
}
V_69:
return V_27 ;
}
void F_423 ( struct V_11 * V_12 )
{
struct V_1 * V_13 ;
T_2 V_67 = 0 ;
while ( 1 ) {
struct V_253 * V_253 ;
V_13 = F_64 ( V_12 , V_67 ) ;
while ( V_13 ) {
F_11 ( & V_13 -> V_49 ) ;
if ( V_13 -> V_162 )
break;
F_13 ( & V_13 -> V_49 ) ;
V_13 = F_215 ( V_12 -> V_235 ,
V_13 ) ;
}
if ( ! V_13 ) {
if ( V_67 == 0 )
break;
V_67 = 0 ;
continue;
}
V_253 = V_13 -> V_253 ;
V_13 -> V_162 = 0 ;
V_13 -> V_253 = NULL ;
F_13 ( & V_13 -> V_49 ) ;
F_230 ( V_253 ) ;
V_67 = V_13 -> V_20 . V_21 + V_13 -> V_20 . V_31 ;
F_6 ( V_13 ) ;
}
}
int F_424 ( struct V_11 * V_12 )
{
struct V_1 * V_13 ;
struct V_96 * V_99 ;
struct V_47 * V_51 ;
struct V_14 * V_28 ;
F_60 ( & V_12 -> V_76 ) ;
while ( ! F_165 ( & V_12 -> V_94 ) ) {
V_51 = F_166 ( V_12 -> V_94 . V_215 ,
struct V_47 , V_86 ) ;
F_179 ( & V_51 -> V_86 ) ;
F_26 ( V_51 ) ;
}
F_62 ( & V_12 -> V_76 ) ;
F_11 ( & V_12 -> V_17 ) ;
while ( ( V_28 = F_176 ( & V_12 -> V_18 ) ) != NULL ) {
V_13 = F_12 ( V_28 , struct V_1 ,
V_19 ) ;
F_173 ( & V_13 -> V_19 ,
& V_12 -> V_18 ) ;
F_13 ( & V_12 -> V_17 ) ;
F_60 ( & V_13 -> V_99 -> V_281 ) ;
F_179 ( & V_13 -> V_86 ) ;
F_62 ( & V_13 -> V_99 -> V_281 ) ;
if ( V_13 -> V_3 == V_50 )
F_340 ( V_13 ) ;
if ( V_13 -> V_3 == V_90 )
F_19 ( V_12 -> V_60 , V_13 ) ;
F_425 ( V_13 ) ;
F_6 ( V_13 ) ;
F_11 ( & V_12 -> V_17 ) ;
}
F_13 ( & V_12 -> V_17 ) ;
F_426 () ;
F_295 ( V_12 ) ;
while( ! F_165 ( & V_12 -> V_99 ) ) {
V_99 = F_166 ( V_12 -> V_99 . V_215 ,
struct V_96 ,
V_86 ) ;
if ( V_99 -> V_282 > 0 ||
V_99 -> V_283 > 0 ||
V_99 -> V_285 > 0 ) {
F_8 ( 1 ) ;
F_258 ( V_99 , 0 , 0 ) ;
}
F_179 ( & V_99 -> V_86 ) ;
F_9 ( V_99 ) ;
}
return 0 ;
}
static void F_427 ( struct V_96 * V_99 ,
struct V_1 * V_2 )
{
int V_457 = F_342 ( V_2 ) ;
F_60 ( & V_99 -> V_281 ) ;
F_61 ( & V_2 -> V_86 , & V_99 -> V_280 [ V_457 ] ) ;
F_62 ( & V_99 -> V_281 ) ;
}
int F_428 ( struct V_32 * V_33 )
{
struct V_61 * V_62 ;
int V_27 ;
struct V_1 * V_2 ;
struct V_11 * V_12 = V_33 -> V_35 ;
struct V_96 * V_99 ;
struct V_65 V_20 ;
struct V_65 V_139 ;
struct V_63 * V_64 ;
int V_548 = 0 ;
T_2 V_549 ;
V_33 = V_12 -> V_60 ;
V_20 . V_21 = 0 ;
V_20 . V_31 = 0 ;
F_76 ( & V_20 , V_175 ) ;
V_62 = F_32 () ;
if ( ! V_62 )
return - V_85 ;
V_62 -> V_72 = 1 ;
V_549 = F_429 ( V_33 -> V_35 -> V_333 ) ;
if ( F_225 ( V_33 , V_266 ) &&
F_430 ( V_33 -> V_35 -> V_333 ) != V_549 )
V_548 = 1 ;
if ( F_225 ( V_33 , V_550 ) )
V_548 = 1 ;
while ( 1 ) {
V_27 = F_422 ( V_33 , V_62 , & V_20 ) ;
if ( V_27 > 0 )
break;
if ( V_27 != 0 )
goto error;
V_64 = V_62 -> V_78 [ 0 ] ;
F_39 ( V_64 , & V_139 , V_62 -> V_79 [ 0 ] ) ;
V_2 = F_51 ( sizeof( * V_2 ) , V_38 ) ;
if ( ! V_2 ) {
V_27 = - V_85 ;
goto error;
}
V_2 -> V_10 = F_51 ( sizeof( * V_2 -> V_10 ) ,
V_38 ) ;
if ( ! V_2 -> V_10 ) {
F_9 ( V_2 ) ;
V_27 = - V_85 ;
goto error;
}
F_55 ( & V_2 -> V_7 , 1 ) ;
F_236 ( & V_2 -> V_49 ) ;
V_2 -> V_35 = V_12 ;
F_52 ( & V_2 -> V_86 ) ;
F_52 ( & V_2 -> V_551 ) ;
if ( V_548 ) {
V_2 -> V_259 = V_268 ;
if ( F_225 ( V_33 , V_266 ) )
V_2 -> V_269 = 1 ;
}
F_431 ( V_64 , & V_2 -> V_111 ,
F_213 ( V_64 , V_62 -> V_79 [ 0 ] ) ,
sizeof( V_2 -> V_111 ) ) ;
memcpy ( & V_2 -> V_20 , & V_139 , sizeof( V_139 ) ) ;
V_20 . V_21 = V_139 . V_21 + V_139 . V_31 ;
F_43 ( V_62 ) ;
V_2 -> V_6 = F_432 ( & V_2 -> V_111 ) ;
V_2 -> V_316 = V_33 -> V_316 ;
F_433 ( V_2 ) ;
F_21 ( V_33 , V_2 ) ;
if ( V_139 . V_31 == F_73 ( & V_2 -> V_111 ) ) {
V_2 -> V_93 = ( T_2 ) - 1 ;
V_2 -> V_3 = V_4 ;
F_19 ( V_33 , V_2 ) ;
} else if ( F_73 ( & V_2 -> V_111 ) == 0 ) {
V_2 -> V_93 = ( T_2 ) - 1 ;
V_2 -> V_3 = V_4 ;
F_27 ( V_2 , V_33 -> V_35 ,
V_139 . V_21 ,
V_139 . V_21 +
V_139 . V_31 ) ;
F_19 ( V_33 , V_2 ) ;
}
V_27 = F_234 ( V_12 , V_2 -> V_6 , V_139 . V_31 ,
F_73 ( & V_2 -> V_111 ) ,
& V_99 ) ;
F_22 ( V_27 ) ;
V_2 -> V_99 = V_99 ;
F_11 ( & V_2 -> V_99 -> V_49 ) ;
V_2 -> V_99 -> V_284 += V_2 -> V_44 ;
F_13 ( & V_2 -> V_99 -> V_49 ) ;
F_427 ( V_99 , V_2 ) ;
V_27 = F_10 ( V_33 -> V_35 , V_2 ) ;
F_22 ( V_27 ) ;
F_238 ( V_33 -> V_35 , V_2 -> V_6 ) ;
if ( F_434 ( V_33 , V_2 -> V_20 . V_21 ) )
F_413 ( V_2 , 1 ) ;
}
F_68 (space_info, &root->fs_info->space_info, list) {
if ( ! ( F_243 ( V_33 , V_99 -> V_6 ) &
( V_276 |
V_275 |
V_274 ) ) )
continue;
F_345 (cache, &space_info->block_groups[3], list)
F_413 ( V_2 , 1 ) ;
F_345 (cache, &space_info->block_groups[4], list)
F_413 ( V_2 , 1 ) ;
}
F_294 ( V_12 ) ;
V_27 = 0 ;
error:
F_48 ( V_62 ) ;
return V_27 ;
}
void F_186 ( struct V_82 * V_83 ,
struct V_32 * V_33 )
{
struct V_1 * V_13 , * V_552 ;
struct V_32 * V_60 = V_33 -> V_35 -> V_60 ;
struct V_553 V_111 ;
struct V_65 V_20 ;
int V_27 = 0 ;
F_326 (block_group, tmp, &trans->new_bgs,
new_bg_list) {
F_171 ( & V_13 -> V_554 ) ;
if ( V_27 )
continue;
F_11 ( & V_13 -> V_49 ) ;
memcpy ( & V_111 , & V_13 -> V_111 , sizeof( V_111 ) ) ;
memcpy ( & V_20 , & V_13 -> V_20 , sizeof( V_20 ) ) ;
F_13 ( & V_13 -> V_49 ) ;
V_27 = F_435 ( V_83 , V_60 , & V_20 , & V_111 ,
sizeof( V_111 ) ) ;
if ( V_27 )
F_149 ( V_83 , V_60 , V_27 ) ;
}
}
int F_436 ( struct V_82 * V_83 ,
struct V_32 * V_33 , T_2 V_273 ,
T_2 type , T_2 V_555 , T_2 V_556 ,
T_2 V_54 )
{
int V_27 ;
struct V_32 * V_60 ;
struct V_1 * V_2 ;
V_60 = V_33 -> V_35 -> V_60 ;
V_33 -> V_35 -> V_557 = V_83 -> V_262 ;
V_2 = F_51 ( sizeof( * V_2 ) , V_38 ) ;
if ( ! V_2 )
return - V_85 ;
V_2 -> V_10 = F_51 ( sizeof( * V_2 -> V_10 ) ,
V_38 ) ;
if ( ! V_2 -> V_10 ) {
F_9 ( V_2 ) ;
return - V_85 ;
}
V_2 -> V_20 . V_21 = V_556 ;
V_2 -> V_20 . V_31 = V_54 ;
V_2 -> V_20 . type = V_175 ;
V_2 -> V_316 = V_33 -> V_316 ;
V_2 -> V_35 = V_33 -> V_35 ;
F_55 ( & V_2 -> V_7 , 1 ) ;
F_236 ( & V_2 -> V_49 ) ;
F_52 ( & V_2 -> V_86 ) ;
F_52 ( & V_2 -> V_551 ) ;
F_52 ( & V_2 -> V_554 ) ;
F_433 ( V_2 ) ;
F_318 ( & V_2 -> V_111 , V_273 ) ;
F_437 ( & V_2 -> V_111 , V_555 ) ;
V_2 -> V_6 = type ;
F_438 ( & V_2 -> V_111 , type ) ;
V_2 -> V_93 = ( T_2 ) - 1 ;
V_2 -> V_3 = V_4 ;
F_21 ( V_33 , V_2 ) ;
F_27 ( V_2 , V_33 -> V_35 , V_556 ,
V_556 + V_54 ) ;
F_19 ( V_33 , V_2 ) ;
V_27 = F_234 ( V_33 -> V_35 , V_2 -> V_6 , V_54 , V_273 ,
& V_2 -> V_99 ) ;
F_22 ( V_27 ) ;
F_293 ( V_33 -> V_35 ) ;
F_11 ( & V_2 -> V_99 -> V_49 ) ;
V_2 -> V_99 -> V_284 += V_2 -> V_44 ;
F_13 ( & V_2 -> V_99 -> V_49 ) ;
F_427 ( V_2 -> V_99 , V_2 ) ;
V_27 = F_10 ( V_33 -> V_35 , V_2 ) ;
F_22 ( V_27 ) ;
F_61 ( & V_2 -> V_554 , & V_83 -> V_237 ) ;
F_238 ( V_60 -> V_35 , type ) ;
return 0 ;
}
static void F_439 ( struct V_11 * V_35 , T_2 V_6 )
{
T_2 V_292 = F_239 ( V_6 ) &
V_293 ;
if ( V_6 & V_290 )
V_35 -> V_294 &= ~ V_292 ;
if ( V_6 & V_113 )
V_35 -> V_295 &= ~ V_292 ;
if ( V_6 & V_296 )
V_35 -> V_297 &= ~ V_292 ;
}
int F_440 ( struct V_82 * V_83 ,
struct V_32 * V_33 , T_2 V_107 )
{
struct V_61 * V_62 ;
struct V_1 * V_13 ;
struct V_461 * V_212 ;
struct V_32 * V_235 = V_33 -> V_35 -> V_235 ;
struct V_65 V_20 ;
struct V_253 * V_253 ;
int V_27 ;
int V_457 ;
int V_109 ;
V_33 = V_33 -> V_35 -> V_60 ;
V_13 = F_65 ( V_33 -> V_35 , V_107 ) ;
F_22 ( ! V_13 ) ;
F_22 ( ! V_13 -> V_112 ) ;
F_19 ( V_33 , V_13 ) ;
memcpy ( & V_20 , & V_13 -> V_20 , sizeof( V_20 ) ) ;
V_457 = F_342 ( V_13 ) ;
if ( V_13 -> V_6 & ( V_274 |
V_275 |
V_276 ) )
V_109 = 2 ;
else
V_109 = 1 ;
V_212 = & V_33 -> V_35 -> V_475 ;
F_11 ( & V_212 -> V_480 ) ;
F_349 ( V_13 , V_212 ) ;
F_13 ( & V_212 -> V_480 ) ;
V_212 = & V_33 -> V_35 -> V_473 ;
F_11 ( & V_212 -> V_480 ) ;
F_349 ( V_13 , V_212 ) ;
F_13 ( & V_212 -> V_480 ) ;
V_62 = F_32 () ;
if ( ! V_62 ) {
V_27 = - V_85 ;
goto V_69;
}
V_253 = F_217 ( V_235 , V_13 , V_62 ) ;
if ( ! F_218 ( V_253 ) ) {
V_27 = F_441 ( V_83 , V_253 ) ;
if ( V_27 ) {
F_442 ( V_253 ) ;
goto V_69;
}
F_443 ( V_253 ) ;
F_11 ( & V_13 -> V_49 ) ;
if ( V_13 -> V_162 ) {
V_13 -> V_162 = 0 ;
V_13 -> V_253 = NULL ;
F_13 ( & V_13 -> V_49 ) ;
F_230 ( V_253 ) ;
} else {
F_13 ( & V_13 -> V_49 ) ;
}
F_442 ( V_253 ) ;
}
V_20 . V_21 = V_558 ;
V_20 . V_31 = V_13 -> V_20 . V_21 ;
V_20 . type = 0 ;
V_27 = F_36 ( V_83 , V_235 , & V_20 , V_62 , - 1 , 1 ) ;
if ( V_27 < 0 )
goto V_69;
if ( V_27 > 0 )
F_43 ( V_62 ) ;
if ( V_27 == 0 ) {
V_27 = F_117 ( V_83 , V_235 , V_62 ) ;
if ( V_27 )
goto V_69;
F_43 ( V_62 ) ;
}
F_11 ( & V_33 -> V_35 -> V_17 ) ;
F_173 ( & V_13 -> V_19 ,
& V_33 -> V_35 -> V_18 ) ;
F_13 ( & V_33 -> V_35 -> V_17 ) ;
F_60 ( & V_13 -> V_99 -> V_281 ) ;
F_171 ( & V_13 -> V_86 ) ;
if ( F_165 ( & V_13 -> V_99 -> V_280 [ V_457 ] ) )
F_439 ( V_33 -> V_35 , V_13 -> V_6 ) ;
F_62 ( & V_13 -> V_99 -> V_281 ) ;
if ( V_13 -> V_3 == V_50 )
F_340 ( V_13 ) ;
F_425 ( V_13 ) ;
F_11 ( & V_13 -> V_99 -> V_49 ) ;
V_13 -> V_99 -> V_272 -= V_13 -> V_20 . V_31 ;
V_13 -> V_99 -> V_284 -= V_13 -> V_20 . V_31 ;
V_13 -> V_99 -> V_277 -= V_13 -> V_20 . V_31 * V_109 ;
F_13 ( & V_13 -> V_99 -> V_49 ) ;
memcpy ( & V_20 , & V_13 -> V_20 , sizeof( V_20 ) ) ;
F_70 ( V_33 -> V_35 ) ;
F_6 ( V_13 ) ;
F_6 ( V_13 ) ;
V_27 = F_36 ( V_83 , V_33 , & V_20 , V_62 , - 1 , 1 ) ;
if ( V_27 > 0 )
V_27 = - V_210 ;
if ( V_27 < 0 )
goto V_69;
V_27 = F_117 ( V_83 , V_33 , V_62 ) ;
V_69:
F_48 ( V_62 ) ;
return V_27 ;
}
int F_444 ( struct V_11 * V_35 )
{
struct V_96 * V_99 ;
struct V_559 * V_560 ;
T_2 V_561 ;
T_2 V_6 ;
int V_562 = 0 ;
int V_27 ;
V_560 = V_35 -> V_333 ;
if ( ! F_445 ( V_560 ) )
return 1 ;
V_561 = F_446 ( V_560 ) ;
if ( V_561 & V_563 )
V_562 = 1 ;
V_6 = V_296 ;
V_27 = F_234 ( V_35 , V_6 , 0 , 0 , & V_99 ) ;
if ( V_27 )
goto V_69;
if ( V_562 ) {
V_6 = V_113 | V_290 ;
V_27 = F_234 ( V_35 , V_6 , 0 , 0 , & V_99 ) ;
} else {
V_6 = V_113 ;
V_27 = F_234 ( V_35 , V_6 , 0 , 0 , & V_99 ) ;
if ( V_27 )
goto V_69;
V_6 = V_290 ;
V_27 = F_234 ( V_35 , V_6 , 0 , 0 , & V_99 ) ;
}
V_69:
return V_27 ;
}
int F_447 ( struct V_32 * V_33 , T_2 V_30 , T_2 V_29 )
{
return F_327 ( V_33 , V_30 , V_29 ) ;
}
int F_448 ( struct V_32 * V_33 , T_2 V_25 ,
T_2 V_34 , T_2 * V_183 )
{
return F_143 ( V_33 , V_25 , V_34 , V_183 ) ;
}
int F_449 ( struct V_32 * V_33 , struct V_564 * V_565 )
{
struct V_11 * V_35 = V_33 -> V_35 ;
struct V_1 * V_2 = NULL ;
T_2 V_566 ;
T_2 V_30 ;
T_2 V_29 ;
T_2 V_567 = 0 ;
T_2 V_272 = F_253 ( V_35 -> V_333 ) ;
int V_27 = 0 ;
if ( V_565 -> V_114 == V_272 )
V_2 = F_64 ( V_35 , V_565 -> V_30 ) ;
else
V_2 = F_65 ( V_35 , V_565 -> V_30 ) ;
while ( V_2 ) {
if ( V_2 -> V_20 . V_21 >= ( V_565 -> V_30 + V_565 -> V_114 ) ) {
F_6 ( V_2 ) ;
break;
}
V_30 = F_72 ( V_565 -> V_30 , V_2 -> V_20 . V_21 ) ;
V_29 = F_268 ( V_565 -> V_30 + V_565 -> V_114 ,
V_2 -> V_20 . V_21 + V_2 -> V_20 . V_31 ) ;
if ( V_29 - V_30 >= V_565 -> V_568 ) {
if ( ! F_1 ( V_2 ) ) {
V_27 = F_49 ( V_2 , NULL , V_33 , 0 ) ;
if ( ! V_27 )
F_340 ( V_2 ) ;
}
V_27 = F_450 ( V_2 ,
& V_566 ,
V_30 ,
V_29 ,
V_565 -> V_568 ) ;
V_567 += V_566 ;
if ( V_27 ) {
F_6 ( V_2 ) ;
break;
}
}
V_2 = F_215 ( V_35 -> V_235 , V_2 ) ;
}
V_565 -> V_114 = V_567 ;
return V_27 ;
}
