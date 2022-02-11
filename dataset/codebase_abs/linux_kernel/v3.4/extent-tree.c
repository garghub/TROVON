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
static T_2 F_71 ( T_2 V_103 , int V_104 )
{
if ( V_104 == 10 )
return V_103 ;
V_103 *= V_104 ;
F_72 ( V_103 , 10 ) ;
return V_103 ;
}
static T_2 F_73 ( T_2 V_103 , int V_104 )
{
if ( V_104 == 100 )
return V_103 ;
V_103 *= V_104 ;
F_72 ( V_103 , 100 ) ;
return V_103 ;
}
T_2 F_74 ( struct V_32 * V_33 ,
T_2 V_105 , T_2 V_106 , int V_107 )
{
struct V_1 * V_2 ;
T_2 V_108 ;
T_2 V_67 = F_75 ( V_106 , V_105 ) ;
T_2 V_109 = 0 ;
int V_110 = 0 ;
int V_104 = 9 ;
int V_111 = 0 ;
V_74:
while ( 1 ) {
V_2 = F_64 ( V_33 -> V_35 , V_67 ) ;
if ( ! V_2 )
break;
F_11 ( & V_2 -> V_49 ) ;
V_67 = V_2 -> V_20 . V_21 + V_2 -> V_20 . V_31 ;
V_108 = F_76 ( & V_2 -> V_112 ) ;
if ( ( V_110 || ! V_2 -> V_113 ) &&
F_3 ( V_2 , V_114 ) ) {
if ( V_108 + V_2 -> V_8 + V_2 -> V_9 <
F_71 ( V_2 -> V_20 . V_31 , V_104 ) ) {
V_109 = V_2 -> V_20 . V_21 ;
F_13 ( & V_2 -> V_49 ) ;
F_6 ( V_2 ) ;
goto V_100;
}
}
F_13 ( & V_2 -> V_49 ) ;
F_6 ( V_2 ) ;
F_46 () ;
}
if ( ! V_111 ) {
V_67 = V_105 ;
V_111 = 1 ;
goto V_74;
}
if ( ! V_110 && V_104 < 10 ) {
V_67 = V_105 ;
V_110 = 1 ;
V_104 = 10 ;
goto V_74;
}
V_100:
return V_109 ;
}
int F_77 ( struct V_32 * V_33 , T_2 V_30 , T_2 V_115 )
{
int V_27 ;
struct V_65 V_20 ;
struct V_61 * V_62 ;
V_62 = F_32 () ;
if ( ! V_62 )
return - V_85 ;
V_20 . V_21 = V_30 ;
V_20 . V_31 = V_115 ;
F_78 ( & V_20 , V_73 ) ;
V_27 = F_36 ( NULL , V_33 -> V_35 -> V_60 , & V_20 , V_62 ,
0 , 0 ) ;
F_48 ( V_62 ) ;
return V_27 ;
}
int F_79 ( struct V_82 * V_83 ,
struct V_32 * V_33 , T_2 V_25 ,
T_2 V_34 , T_2 * V_116 , T_2 * V_6 )
{
struct V_117 * V_98 ;
struct V_118 * V_119 ;
struct V_61 * V_62 ;
struct V_120 * V_121 ;
struct V_63 * V_64 ;
struct V_65 V_20 ;
T_3 V_122 ;
T_2 V_123 ;
T_2 V_124 ;
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
goto V_125;
if ( V_27 == 0 ) {
V_64 = V_62 -> V_78 [ 0 ] ;
V_122 = F_80 ( V_64 , V_62 -> V_79 [ 0 ] ) ;
if ( V_122 >= sizeof( * V_121 ) ) {
V_121 = F_81 ( V_64 , V_62 -> V_79 [ 0 ] ,
struct V_120 ) ;
V_123 = F_82 ( V_64 , V_121 ) ;
V_124 = F_83 ( V_64 , V_121 ) ;
} else {
#ifdef F_84
struct V_126 * V_127 ;
F_22 ( V_122 != sizeof( * V_127 ) ) ;
V_127 = F_81 ( V_64 , V_62 -> V_79 [ 0 ] ,
struct V_126 ) ;
V_123 = F_85 ( V_64 , V_127 ) ;
V_124 = V_128 ;
#else
F_86 () ;
#endif
}
F_22 ( V_123 == 0 ) ;
} else {
V_123 = 0 ;
V_124 = 0 ;
V_27 = 0 ;
}
if ( ! V_83 )
goto V_69;
V_119 = & V_83 -> V_129 -> V_119 ;
F_11 ( & V_119 -> V_49 ) ;
V_98 = F_87 ( V_83 , V_25 ) ;
if ( V_98 ) {
if ( ! F_88 ( & V_98 -> V_75 ) ) {
F_5 ( & V_98 -> V_130 . V_116 ) ;
F_13 ( & V_119 -> V_49 ) ;
F_43 ( V_62 ) ;
F_34 ( & V_98 -> V_75 ) ;
F_45 ( & V_98 -> V_75 ) ;
F_89 ( & V_98 -> V_130 ) ;
goto V_74;
}
if ( V_98 -> V_131 && V_98 -> V_131 -> V_132 )
V_124 |= V_98 -> V_131 -> V_133 ;
else
F_22 ( V_123 == 0 ) ;
V_123 += V_98 -> V_130 . V_134 ;
F_45 ( & V_98 -> V_75 ) ;
}
F_13 ( & V_119 -> V_49 ) ;
V_69:
F_8 ( V_123 == 0 ) ;
if ( V_116 )
* V_116 = V_123 ;
if ( V_6 )
* V_6 = V_124 ;
V_125:
F_48 ( V_62 ) ;
return V_27 ;
}
static int F_90 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_61 * V_62 ,
T_2 V_107 , T_3 V_135 )
{
struct V_120 * V_112 ;
struct V_126 * V_127 ;
struct V_136 * V_137 ;
struct V_138 * V_139 ;
struct V_63 * V_64 ;
struct V_65 V_20 ;
struct V_65 V_140 ;
T_3 V_141 = sizeof( * V_112 ) ;
T_2 V_116 ;
int V_27 ;
V_64 = V_62 -> V_78 [ 0 ] ;
F_22 ( F_80 ( V_64 , V_62 -> V_79 [ 0 ] ) != sizeof( * V_127 ) ) ;
F_39 ( V_64 , & V_20 , V_62 -> V_79 [ 0 ] ) ;
V_127 = F_81 ( V_64 , V_62 -> V_79 [ 0 ] ,
struct V_126 ) ;
V_116 = F_85 ( V_64 , V_127 ) ;
if ( V_107 == ( T_2 ) - 1 ) {
while ( 1 ) {
if ( V_62 -> V_79 [ 0 ] >= F_37 ( V_64 ) ) {
V_27 = F_42 ( V_33 , V_62 ) ;
if ( V_27 < 0 )
return V_27 ;
F_22 ( V_27 > 0 ) ;
V_64 = V_62 -> V_78 [ 0 ] ;
}
F_39 ( V_64 , & V_140 ,
V_62 -> V_79 [ 0 ] ) ;
F_22 ( V_20 . V_21 != V_140 . V_21 ) ;
if ( V_140 . type != V_142 ) {
V_62 -> V_79 [ 0 ] ++ ;
continue;
}
V_137 = F_81 ( V_64 , V_62 -> V_79 [ 0 ] ,
struct V_136 ) ;
V_107 = F_91 ( V_64 , V_137 ) ;
break;
}
}
F_43 ( V_62 ) ;
if ( V_107 < V_143 )
V_141 += sizeof( * V_139 ) ;
V_141 -= sizeof( * V_127 ) ;
V_27 = F_36 ( V_83 , V_33 , & V_20 , V_62 ,
V_141 + V_135 , 1 ) ;
if ( V_27 < 0 )
return V_27 ;
F_22 ( V_27 ) ;
F_92 ( V_83 , V_33 , V_62 , V_141 ) ;
V_64 = V_62 -> V_78 [ 0 ] ;
V_112 = F_81 ( V_64 , V_62 -> V_79 [ 0 ] , struct V_120 ) ;
F_93 ( V_64 , V_112 , V_116 ) ;
F_94 ( V_64 , V_112 , 0 ) ;
if ( V_107 < V_143 ) {
F_95 ( V_64 , V_112 ,
V_144 |
V_128 ) ;
V_139 = (struct V_138 * ) ( V_112 + 1 ) ;
F_96 ( V_64 , 0 , ( unsigned long ) V_139 , sizeof( * V_139 ) ) ;
F_97 ( V_64 , V_139 , ( int ) V_107 ) ;
} else {
F_95 ( V_64 , V_112 , V_145 ) ;
}
F_98 ( V_64 ) ;
return 0 ;
}
static T_2 F_99 ( T_2 V_146 , T_2 V_107 , T_2 V_31 )
{
T_3 V_147 = ~ ( T_3 ) 0 ;
T_3 V_148 = ~ ( T_3 ) 0 ;
T_4 V_149 ;
V_149 = F_100 ( V_146 ) ;
V_147 = F_101 ( V_147 , & V_149 , sizeof( V_149 ) ) ;
V_149 = F_100 ( V_107 ) ;
V_148 = F_101 ( V_148 , & V_149 , sizeof( V_149 ) ) ;
V_149 = F_100 ( V_31 ) ;
V_148 = F_101 ( V_148 , & V_149 , sizeof( V_149 ) ) ;
return ( ( T_2 ) V_147 << 31 ) ^ ( T_2 ) V_148 ;
}
static T_2 F_102 ( struct V_63 * V_64 ,
struct V_150 * V_151 )
{
return F_99 ( F_103 ( V_64 , V_151 ) ,
F_104 ( V_64 , V_151 ) ,
F_105 ( V_64 , V_151 ) ) ;
}
static int F_106 ( struct V_63 * V_64 ,
struct V_150 * V_151 ,
T_2 V_146 , T_2 V_107 , T_2 V_31 )
{
if ( F_103 ( V_64 , V_151 ) != V_146 ||
F_104 ( V_64 , V_151 ) != V_107 ||
F_105 ( V_64 , V_151 ) != V_31 )
return 0 ;
return 1 ;
}
static T_1 int F_107 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_61 * V_62 ,
T_2 V_25 , T_2 V_16 ,
T_2 V_146 ,
T_2 V_107 , T_2 V_31 )
{
struct V_65 V_20 ;
struct V_150 * V_151 ;
struct V_63 * V_64 ;
T_3 V_68 ;
int V_27 ;
int V_152 ;
int V_77 = - V_153 ;
V_20 . V_21 = V_25 ;
if ( V_16 ) {
V_20 . type = V_154 ;
V_20 . V_31 = V_16 ;
} else {
V_20 . type = V_155 ;
V_20 . V_31 = F_99 ( V_146 ,
V_107 , V_31 ) ;
}
V_74:
V_152 = 0 ;
V_27 = F_36 ( V_83 , V_33 , & V_20 , V_62 , - 1 , 1 ) ;
if ( V_27 < 0 ) {
V_77 = V_27 ;
goto V_156;
}
if ( V_16 ) {
if ( ! V_27 )
return 0 ;
#ifdef F_84
V_20 . type = V_142 ;
F_43 ( V_62 ) ;
V_27 = F_36 ( V_83 , V_33 , & V_20 , V_62 , - 1 , 1 ) ;
if ( V_27 < 0 ) {
V_77 = V_27 ;
goto V_156;
}
if ( ! V_27 )
return 0 ;
#endif
goto V_156;
}
V_64 = V_62 -> V_78 [ 0 ] ;
V_68 = F_37 ( V_64 ) ;
while ( 1 ) {
if ( V_62 -> V_79 [ 0 ] >= V_68 ) {
V_27 = F_42 ( V_33 , V_62 ) ;
if ( V_27 < 0 )
V_77 = V_27 ;
if ( V_27 )
goto V_156;
V_64 = V_62 -> V_78 [ 0 ] ;
V_68 = F_37 ( V_64 ) ;
V_152 = 1 ;
}
F_39 ( V_64 , & V_20 , V_62 -> V_79 [ 0 ] ) ;
if ( V_20 . V_21 != V_25 ||
V_20 . type != V_155 )
goto V_156;
V_151 = F_81 ( V_64 , V_62 -> V_79 [ 0 ] ,
struct V_150 ) ;
if ( F_106 ( V_64 , V_151 , V_146 ,
V_107 , V_31 ) ) {
if ( V_152 ) {
F_43 ( V_62 ) ;
goto V_74;
}
V_77 = 0 ;
break;
}
V_62 -> V_79 [ 0 ] ++ ;
}
V_156:
return V_77 ;
}
static T_1 int F_108 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_61 * V_62 ,
T_2 V_25 , T_2 V_16 ,
T_2 V_146 , T_2 V_107 ,
T_2 V_31 , int V_157 )
{
struct V_65 V_20 ;
struct V_63 * V_64 ;
T_3 V_54 ;
T_3 V_123 ;
int V_27 ;
V_20 . V_21 = V_25 ;
if ( V_16 ) {
V_20 . type = V_154 ;
V_20 . V_31 = V_16 ;
V_54 = sizeof( struct V_158 ) ;
} else {
V_20 . type = V_155 ;
V_20 . V_31 = F_99 ( V_146 ,
V_107 , V_31 ) ;
V_54 = sizeof( struct V_150 ) ;
}
V_27 = F_109 ( V_83 , V_33 , V_62 , & V_20 , V_54 ) ;
if ( V_27 && V_27 != - V_24 )
goto V_156;
V_64 = V_62 -> V_78 [ 0 ] ;
if ( V_16 ) {
struct V_158 * V_151 ;
V_151 = F_81 ( V_64 , V_62 -> V_79 [ 0 ] ,
struct V_158 ) ;
if ( V_27 == 0 ) {
F_110 ( V_64 , V_151 , V_157 ) ;
} else {
V_123 = F_111 ( V_64 , V_151 ) ;
V_123 += V_157 ;
F_110 ( V_64 , V_151 , V_123 ) ;
}
} else {
struct V_150 * V_151 ;
while ( V_27 == - V_24 ) {
V_151 = F_81 ( V_64 , V_62 -> V_79 [ 0 ] ,
struct V_150 ) ;
if ( F_106 ( V_64 , V_151 , V_146 ,
V_107 , V_31 ) )
break;
F_43 ( V_62 ) ;
V_20 . V_31 ++ ;
V_27 = F_109 ( V_83 , V_33 , V_62 , & V_20 ,
V_54 ) ;
if ( V_27 && V_27 != - V_24 )
goto V_156;
V_64 = V_62 -> V_78 [ 0 ] ;
}
V_151 = F_81 ( V_64 , V_62 -> V_79 [ 0 ] ,
struct V_150 ) ;
if ( V_27 == 0 ) {
F_112 ( V_64 , V_151 ,
V_146 ) ;
F_113 ( V_64 , V_151 , V_107 ) ;
F_114 ( V_64 , V_151 , V_31 ) ;
F_115 ( V_64 , V_151 , V_157 ) ;
} else {
V_123 = F_116 ( V_64 , V_151 ) ;
V_123 += V_157 ;
F_115 ( V_64 , V_151 , V_123 ) ;
}
}
F_98 ( V_64 ) ;
V_27 = 0 ;
V_156:
F_43 ( V_62 ) ;
return V_27 ;
}
static T_1 int F_117 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_61 * V_62 ,
int V_159 )
{
struct V_65 V_20 ;
struct V_150 * V_160 = NULL ;
struct V_158 * V_161 = NULL ;
struct V_63 * V_64 ;
T_3 V_123 = 0 ;
int V_27 = 0 ;
V_64 = V_62 -> V_78 [ 0 ] ;
F_39 ( V_64 , & V_20 , V_62 -> V_79 [ 0 ] ) ;
if ( V_20 . type == V_155 ) {
V_160 = F_81 ( V_64 , V_62 -> V_79 [ 0 ] ,
struct V_150 ) ;
V_123 = F_116 ( V_64 , V_160 ) ;
} else if ( V_20 . type == V_154 ) {
V_161 = F_81 ( V_64 , V_62 -> V_79 [ 0 ] ,
struct V_158 ) ;
V_123 = F_111 ( V_64 , V_161 ) ;
#ifdef F_84
} else if ( V_20 . type == V_142 ) {
struct V_136 * V_137 ;
V_137 = F_81 ( V_64 , V_62 -> V_79 [ 0 ] ,
struct V_136 ) ;
V_123 = F_118 ( V_64 , V_137 ) ;
#endif
} else {
F_86 () ;
}
F_22 ( V_123 < V_159 ) ;
V_123 -= V_159 ;
if ( V_123 == 0 ) {
V_27 = F_119 ( V_83 , V_33 , V_62 ) ;
} else {
if ( V_20 . type == V_155 )
F_115 ( V_64 , V_160 , V_123 ) ;
else if ( V_20 . type == V_154 )
F_110 ( V_64 , V_161 , V_123 ) ;
#ifdef F_84
else {
struct V_136 * V_137 ;
V_137 = F_81 ( V_64 , V_62 -> V_79 [ 0 ] ,
struct V_136 ) ;
F_120 ( V_64 , V_137 , V_123 ) ;
}
#endif
F_98 ( V_64 ) ;
}
return V_27 ;
}
static T_1 T_3 F_121 ( struct V_32 * V_33 ,
struct V_61 * V_62 ,
struct V_162 * V_163 )
{
struct V_65 V_20 ;
struct V_63 * V_64 ;
struct V_150 * V_160 ;
struct V_158 * V_161 ;
T_3 V_123 = 0 ;
V_64 = V_62 -> V_78 [ 0 ] ;
F_39 ( V_64 , & V_20 , V_62 -> V_79 [ 0 ] ) ;
if ( V_163 ) {
if ( F_122 ( V_64 , V_163 ) ==
V_155 ) {
V_160 = (struct V_150 * ) ( & V_163 -> V_31 ) ;
V_123 = F_116 ( V_64 , V_160 ) ;
} else {
V_161 = (struct V_158 * ) ( V_163 + 1 ) ;
V_123 = F_111 ( V_64 , V_161 ) ;
}
} else if ( V_20 . type == V_155 ) {
V_160 = F_81 ( V_64 , V_62 -> V_79 [ 0 ] ,
struct V_150 ) ;
V_123 = F_116 ( V_64 , V_160 ) ;
} else if ( V_20 . type == V_154 ) {
V_161 = F_81 ( V_64 , V_62 -> V_79 [ 0 ] ,
struct V_158 ) ;
V_123 = F_111 ( V_64 , V_161 ) ;
#ifdef F_84
} else if ( V_20 . type == V_142 ) {
struct V_136 * V_137 ;
V_137 = F_81 ( V_64 , V_62 -> V_79 [ 0 ] ,
struct V_136 ) ;
V_123 = F_118 ( V_64 , V_137 ) ;
#endif
} else {
F_8 ( 1 ) ;
}
return V_123 ;
}
static T_1 int F_123 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_61 * V_62 ,
T_2 V_25 , T_2 V_16 ,
T_2 V_146 )
{
struct V_65 V_20 ;
int V_27 ;
V_20 . V_21 = V_25 ;
if ( V_16 ) {
V_20 . type = V_164 ;
V_20 . V_31 = V_16 ;
} else {
V_20 . type = V_165 ;
V_20 . V_31 = V_146 ;
}
V_27 = F_36 ( V_83 , V_33 , & V_20 , V_62 , - 1 , 1 ) ;
if ( V_27 > 0 )
V_27 = - V_153 ;
#ifdef F_84
if ( V_27 == - V_153 && V_16 ) {
F_43 ( V_62 ) ;
V_20 . type = V_142 ;
V_27 = F_36 ( V_83 , V_33 , & V_20 , V_62 , - 1 , 1 ) ;
if ( V_27 > 0 )
V_27 = - V_153 ;
}
#endif
return V_27 ;
}
static T_1 int F_124 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_61 * V_62 ,
T_2 V_25 , T_2 V_16 ,
T_2 V_146 )
{
struct V_65 V_20 ;
int V_27 ;
V_20 . V_21 = V_25 ;
if ( V_16 ) {
V_20 . type = V_164 ;
V_20 . V_31 = V_16 ;
} else {
V_20 . type = V_165 ;
V_20 . V_31 = V_146 ;
}
V_27 = F_109 ( V_83 , V_33 , V_62 , & V_20 , 0 ) ;
F_43 ( V_62 ) ;
return V_27 ;
}
static inline int F_125 ( T_2 V_16 , T_2 V_107 )
{
int type ;
if ( V_107 < V_143 ) {
if ( V_16 > 0 )
type = V_164 ;
else
type = V_165 ;
} else {
if ( V_16 > 0 )
type = V_154 ;
else
type = V_155 ;
}
return type ;
}
static int F_40 ( struct V_61 * V_62 , int V_166 ,
struct V_65 * V_20 )
{
for (; V_166 < V_167 ; V_166 ++ ) {
if ( ! V_62 -> V_78 [ V_166 ] )
break;
if ( V_62 -> V_79 [ V_166 ] + 1 >=
F_37 ( V_62 -> V_78 [ V_166 ] ) )
continue;
if ( V_166 == 0 )
F_39 ( V_62 -> V_78 [ V_166 ] , V_20 ,
V_62 -> V_79 [ V_166 ] + 1 ) ;
else
F_126 ( V_62 -> V_78 [ V_166 ] , V_20 ,
V_62 -> V_79 [ V_166 ] + 1 ) ;
return 0 ;
}
return 1 ;
}
static T_5
int F_127 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_61 * V_62 ,
struct V_162 * * V_168 ,
T_2 V_25 , T_2 V_34 ,
T_2 V_16 , T_2 V_146 ,
T_2 V_107 , T_2 V_31 , int V_169 )
{
struct V_65 V_20 ;
struct V_63 * V_64 ;
struct V_120 * V_121 ;
struct V_162 * V_163 ;
T_2 V_6 ;
T_2 V_122 ;
unsigned long V_170 ;
unsigned long V_29 ;
int V_135 ;
int type ;
int V_171 ;
int V_27 ;
int V_77 = 0 ;
V_20 . V_21 = V_25 ;
V_20 . type = V_73 ;
V_20 . V_31 = V_34 ;
V_171 = F_125 ( V_16 , V_107 ) ;
if ( V_169 ) {
V_135 = F_128 ( V_171 ) ;
V_62 -> V_172 = 1 ;
} else
V_135 = - 1 ;
V_27 = F_36 ( V_83 , V_33 , & V_20 , V_62 , V_135 , 1 ) ;
if ( V_27 < 0 ) {
V_77 = V_27 ;
goto V_69;
}
if ( V_27 && ! V_169 ) {
V_77 = - V_153 ;
goto V_69;
}
F_22 ( V_27 ) ;
V_64 = V_62 -> V_78 [ 0 ] ;
V_122 = F_80 ( V_64 , V_62 -> V_79 [ 0 ] ) ;
#ifdef F_84
if ( V_122 < sizeof( * V_121 ) ) {
if ( ! V_169 ) {
V_77 = - V_153 ;
goto V_69;
}
V_27 = F_90 ( V_83 , V_33 , V_62 , V_107 ,
V_135 ) ;
if ( V_27 < 0 ) {
V_77 = V_27 ;
goto V_69;
}
V_64 = V_62 -> V_78 [ 0 ] ;
V_122 = F_80 ( V_64 , V_62 -> V_79 [ 0 ] ) ;
}
#endif
F_22 ( V_122 < sizeof( * V_121 ) ) ;
V_121 = F_81 ( V_64 , V_62 -> V_79 [ 0 ] , struct V_120 ) ;
V_6 = F_83 ( V_64 , V_121 ) ;
V_170 = ( unsigned long ) ( V_121 + 1 ) ;
V_29 = ( unsigned long ) V_121 + V_122 ;
if ( V_6 & V_144 ) {
V_170 += sizeof( struct V_138 ) ;
F_22 ( V_170 > V_29 ) ;
} else {
F_22 ( ! ( V_6 & V_145 ) ) ;
}
V_77 = - V_153 ;
while ( 1 ) {
if ( V_170 >= V_29 ) {
F_8 ( V_170 > V_29 ) ;
break;
}
V_163 = (struct V_162 * ) V_170 ;
type = F_122 ( V_64 , V_163 ) ;
if ( V_171 < type )
break;
if ( V_171 > type ) {
V_170 += F_128 ( type ) ;
continue;
}
if ( type == V_155 ) {
struct V_150 * V_173 ;
V_173 = (struct V_150 * ) ( & V_163 -> V_31 ) ;
if ( F_106 ( V_64 , V_173 , V_146 ,
V_107 , V_31 ) ) {
V_77 = 0 ;
break;
}
if ( F_102 ( V_64 , V_173 ) <
F_99 ( V_146 , V_107 , V_31 ) )
break;
} else {
T_2 V_174 ;
V_174 = F_129 ( V_64 , V_163 ) ;
if ( V_16 > 0 ) {
if ( V_16 == V_174 ) {
V_77 = 0 ;
break;
}
if ( V_174 < V_16 )
break;
} else {
if ( V_146 == V_174 ) {
V_77 = 0 ;
break;
}
if ( V_174 < V_146 )
break;
}
}
V_170 += F_128 ( type ) ;
}
if ( V_77 == - V_153 && V_169 ) {
if ( V_122 + V_135 >=
F_130 ( V_33 ) ) {
V_77 = - V_175 ;
goto V_69;
}
if ( F_40 ( V_62 , 0 , & V_20 ) == 0 &&
V_20 . V_21 == V_25 &&
V_20 . type < V_176 ) {
V_77 = - V_175 ;
goto V_69;
}
}
* V_168 = (struct V_162 * ) V_170 ;
V_69:
if ( V_169 ) {
V_62 -> V_172 = 0 ;
F_131 ( V_62 , 1 ) ;
}
return V_77 ;
}
static T_5
void F_132 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_61 * V_62 ,
struct V_162 * V_163 ,
T_2 V_16 , T_2 V_146 ,
T_2 V_107 , T_2 V_31 , int V_157 ,
struct V_177 * V_131 )
{
struct V_63 * V_64 ;
struct V_120 * V_121 ;
unsigned long V_170 ;
unsigned long V_29 ;
unsigned long V_178 ;
T_2 V_116 ;
int V_54 ;
int type ;
V_64 = V_62 -> V_78 [ 0 ] ;
V_121 = F_81 ( V_64 , V_62 -> V_79 [ 0 ] , struct V_120 ) ;
V_178 = ( unsigned long ) V_163 - ( unsigned long ) V_121 ;
type = F_125 ( V_16 , V_107 ) ;
V_54 = F_128 ( type ) ;
F_92 ( V_83 , V_33 , V_62 , V_54 ) ;
V_121 = F_81 ( V_64 , V_62 -> V_79 [ 0 ] , struct V_120 ) ;
V_116 = F_82 ( V_64 , V_121 ) ;
V_116 += V_157 ;
F_93 ( V_64 , V_121 , V_116 ) ;
if ( V_131 )
F_133 ( V_131 , V_64 , V_121 ) ;
V_170 = ( unsigned long ) V_121 + V_178 ;
V_29 = ( unsigned long ) V_121 + F_80 ( V_64 , V_62 -> V_79 [ 0 ] ) ;
if ( V_170 < V_29 - V_54 )
F_134 ( V_64 , V_170 + V_54 , V_170 ,
V_29 - V_54 - V_170 ) ;
V_163 = (struct V_162 * ) V_170 ;
F_135 ( V_64 , V_163 , type ) ;
if ( type == V_155 ) {
struct V_150 * V_173 ;
V_173 = (struct V_150 * ) ( & V_163 -> V_31 ) ;
F_112 ( V_64 , V_173 , V_146 ) ;
F_113 ( V_64 , V_173 , V_107 ) ;
F_114 ( V_64 , V_173 , V_31 ) ;
F_115 ( V_64 , V_173 , V_157 ) ;
} else if ( type == V_154 ) {
struct V_158 * V_179 ;
V_179 = (struct V_158 * ) ( V_163 + 1 ) ;
F_110 ( V_64 , V_179 , V_157 ) ;
F_136 ( V_64 , V_163 , V_16 ) ;
} else if ( type == V_164 ) {
F_136 ( V_64 , V_163 , V_16 ) ;
} else {
F_136 ( V_64 , V_163 , V_146 ) ;
}
F_98 ( V_64 ) ;
}
static int F_137 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_61 * V_62 ,
struct V_162 * * V_168 ,
T_2 V_25 , T_2 V_34 , T_2 V_16 ,
T_2 V_146 , T_2 V_107 , T_2 V_31 )
{
int V_27 ;
V_27 = F_127 ( V_83 , V_33 , V_62 , V_168 ,
V_25 , V_34 , V_16 ,
V_146 , V_107 , V_31 , 0 ) ;
if ( V_27 != - V_153 )
return V_27 ;
F_43 ( V_62 ) ;
* V_168 = NULL ;
if ( V_107 < V_143 ) {
V_27 = F_123 ( V_83 , V_33 , V_62 , V_25 , V_16 ,
V_146 ) ;
} else {
V_27 = F_107 ( V_83 , V_33 , V_62 , V_25 , V_16 ,
V_146 , V_107 , V_31 ) ;
}
return V_27 ;
}
static T_5
void F_138 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_61 * V_62 ,
struct V_162 * V_163 ,
int V_180 ,
struct V_177 * V_131 )
{
struct V_63 * V_64 ;
struct V_120 * V_121 ;
struct V_150 * V_173 = NULL ;
struct V_158 * V_179 = NULL ;
unsigned long V_170 ;
unsigned long V_29 ;
T_3 V_122 ;
int V_54 ;
int type ;
T_2 V_116 ;
V_64 = V_62 -> V_78 [ 0 ] ;
V_121 = F_81 ( V_64 , V_62 -> V_79 [ 0 ] , struct V_120 ) ;
V_116 = F_82 ( V_64 , V_121 ) ;
F_8 ( V_180 < 0 && V_116 + V_180 <= 0 ) ;
V_116 += V_180 ;
F_93 ( V_64 , V_121 , V_116 ) ;
if ( V_131 )
F_133 ( V_131 , V_64 , V_121 ) ;
type = F_122 ( V_64 , V_163 ) ;
if ( type == V_155 ) {
V_173 = (struct V_150 * ) ( & V_163 -> V_31 ) ;
V_116 = F_116 ( V_64 , V_173 ) ;
} else if ( type == V_154 ) {
V_179 = (struct V_158 * ) ( V_163 + 1 ) ;
V_116 = F_111 ( V_64 , V_179 ) ;
} else {
V_116 = 1 ;
F_22 ( V_180 != - 1 ) ;
}
F_22 ( V_180 < 0 && V_116 < - V_180 ) ;
V_116 += V_180 ;
if ( V_116 > 0 ) {
if ( type == V_155 )
F_115 ( V_64 , V_173 , V_116 ) ;
else
F_110 ( V_64 , V_179 , V_116 ) ;
} else {
V_54 = F_128 ( type ) ;
V_122 = F_80 ( V_64 , V_62 -> V_79 [ 0 ] ) ;
V_170 = ( unsigned long ) V_163 ;
V_29 = ( unsigned long ) V_121 + V_122 ;
if ( V_170 + V_54 < V_29 )
F_134 ( V_64 , V_170 , V_170 + V_54 ,
V_29 - V_170 - V_54 ) ;
V_122 -= V_54 ;
F_139 ( V_83 , V_33 , V_62 , V_122 , 1 ) ;
}
F_98 ( V_64 ) ;
}
static T_5
int F_140 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_61 * V_62 ,
T_2 V_25 , T_2 V_34 , T_2 V_16 ,
T_2 V_146 , T_2 V_107 ,
T_2 V_31 , int V_157 ,
struct V_177 * V_131 )
{
struct V_162 * V_163 ;
int V_27 ;
V_27 = F_127 ( V_83 , V_33 , V_62 , & V_163 ,
V_25 , V_34 , V_16 ,
V_146 , V_107 , V_31 , 1 ) ;
if ( V_27 == 0 ) {
F_22 ( V_107 < V_143 ) ;
F_138 ( V_83 , V_33 , V_62 , V_163 ,
V_157 , V_131 ) ;
} else if ( V_27 == - V_153 ) {
F_132 ( V_83 , V_33 , V_62 , V_163 , V_16 ,
V_146 , V_107 , V_31 ,
V_157 , V_131 ) ;
V_27 = 0 ;
}
return V_27 ;
}
static int F_141 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_61 * V_62 ,
T_2 V_25 , T_2 V_16 , T_2 V_146 ,
T_2 V_107 , T_2 V_31 , int V_157 )
{
int V_27 ;
if ( V_107 < V_143 ) {
F_22 ( V_157 != 1 ) ;
V_27 = F_124 ( V_83 , V_33 , V_62 , V_25 ,
V_16 , V_146 ) ;
} else {
V_27 = F_108 ( V_83 , V_33 , V_62 , V_25 ,
V_16 , V_146 ,
V_107 , V_31 , V_157 ) ;
}
return V_27 ;
}
static int F_142 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_61 * V_62 ,
struct V_162 * V_163 ,
int V_159 , int V_181 )
{
int V_27 = 0 ;
F_22 ( ! V_181 && V_159 != 1 ) ;
if ( V_163 ) {
F_138 ( V_83 , V_33 , V_62 , V_163 ,
- V_159 , NULL ) ;
} else if ( V_181 ) {
V_27 = F_117 ( V_83 , V_33 , V_62 , V_159 ) ;
} else {
V_27 = F_119 ( V_83 , V_33 , V_62 ) ;
}
return V_27 ;
}
static int F_143 ( struct V_182 * V_183 ,
T_2 V_30 , T_2 V_115 )
{
return F_144 ( V_183 , V_30 >> 9 , V_115 >> 9 , V_38 , 0 ) ;
}
static int F_145 ( struct V_32 * V_33 , T_2 V_25 ,
T_2 V_34 , T_2 * V_184 )
{
int V_27 ;
T_2 V_185 = 0 ;
struct V_186 * V_187 = NULL ;
V_27 = F_146 ( & V_33 -> V_35 -> V_46 , V_188 ,
V_25 , & V_34 , & V_187 , 0 ) ;
if ( ! V_27 ) {
struct V_189 * V_190 = V_187 -> V_191 ;
int V_41 ;
for ( V_41 = 0 ; V_41 < V_187 -> V_192 ; V_41 ++ , V_190 ++ ) {
if ( ! V_190 -> V_193 -> V_194 )
continue;
V_27 = F_143 ( V_190 -> V_193 -> V_183 ,
V_190 -> V_195 ,
V_190 -> V_196 ) ;
if ( ! V_27 )
V_185 += V_190 -> V_196 ;
else if ( V_27 != - V_197 )
break;
V_27 = 0 ;
}
F_9 ( V_187 ) ;
}
if ( V_184 )
* V_184 = V_185 ;
return V_27 ;
}
int F_147 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
T_2 V_25 , T_2 V_34 , T_2 V_16 ,
T_2 V_146 , T_2 V_107 , T_2 V_31 , int V_198 )
{
int V_27 ;
struct V_11 * V_35 = V_33 -> V_35 ;
F_22 ( V_107 < V_143 &&
V_146 == V_199 ) ;
if ( V_107 < V_143 ) {
V_27 = F_148 ( V_35 , V_83 , V_25 ,
V_34 ,
V_16 , V_146 , ( int ) V_107 ,
V_200 , NULL , V_198 ) ;
} else {
V_27 = F_149 ( V_35 , V_83 , V_25 ,
V_34 ,
V_16 , V_146 , V_107 , V_31 ,
V_200 , NULL , V_198 ) ;
}
return V_27 ;
}
static int F_150 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
T_2 V_25 , T_2 V_34 ,
T_2 V_16 , T_2 V_146 ,
T_2 V_107 , T_2 V_31 , int V_157 ,
struct V_177 * V_131 )
{
struct V_61 * V_62 ;
struct V_63 * V_64 ;
struct V_120 * V_112 ;
T_2 V_116 ;
int V_27 ;
int V_77 = 0 ;
V_62 = F_32 () ;
if ( ! V_62 )
return - V_85 ;
V_62 -> V_72 = 1 ;
V_62 -> V_201 = 1 ;
V_27 = F_140 ( V_83 , V_33 -> V_35 -> V_60 ,
V_62 , V_25 , V_34 , V_16 ,
V_146 , V_107 , V_31 ,
V_157 , V_131 ) ;
if ( V_27 == 0 )
goto V_69;
if ( V_27 != - V_175 ) {
V_77 = V_27 ;
goto V_69;
}
V_64 = V_62 -> V_78 [ 0 ] ;
V_112 = F_81 ( V_64 , V_62 -> V_79 [ 0 ] , struct V_120 ) ;
V_116 = F_82 ( V_64 , V_112 ) ;
F_93 ( V_64 , V_112 , V_116 + V_157 ) ;
if ( V_131 )
F_133 ( V_131 , V_64 , V_112 ) ;
F_98 ( V_64 ) ;
F_43 ( V_62 ) ;
V_62 -> V_72 = 1 ;
V_62 -> V_201 = 1 ;
V_27 = F_141 ( V_83 , V_33 -> V_35 -> V_60 ,
V_62 , V_25 , V_16 , V_146 ,
V_107 , V_31 , V_157 ) ;
if ( V_27 )
F_151 ( V_83 , V_33 , V_27 ) ;
V_69:
F_48 ( V_62 ) ;
return V_77 ;
}
static int F_152 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_202 * V_130 ,
struct V_177 * V_131 ,
int V_203 )
{
int V_27 = 0 ;
struct V_204 * V_151 ;
struct V_65 V_205 ;
T_2 V_16 = 0 ;
T_2 V_206 = 0 ;
T_2 V_6 = 0 ;
V_205 . V_21 = V_130 -> V_25 ;
V_205 . V_31 = V_130 -> V_34 ;
V_205 . type = V_73 ;
V_151 = F_153 ( V_130 ) ;
if ( V_130 -> type == V_154 )
V_16 = V_151 -> V_16 ;
else
V_206 = V_151 -> V_33 ;
if ( V_130 -> V_207 == V_200 && V_203 ) {
if ( V_131 ) {
F_22 ( V_131 -> V_208 ) ;
V_6 |= V_131 -> V_133 ;
}
V_27 = F_154 ( V_83 , V_33 ,
V_16 , V_206 , V_6 ,
V_151 -> V_21 , V_151 -> V_31 ,
& V_205 , V_130 -> V_134 ) ;
} else if ( V_130 -> V_207 == V_200 ) {
V_27 = F_150 ( V_83 , V_33 , V_130 -> V_25 ,
V_130 -> V_34 , V_16 ,
V_206 , V_151 -> V_21 ,
V_151 -> V_31 , V_130 -> V_134 ,
V_131 ) ;
} else if ( V_130 -> V_207 == V_209 ) {
V_27 = F_155 ( V_83 , V_33 , V_130 -> V_25 ,
V_130 -> V_34 , V_16 ,
V_206 , V_151 -> V_21 ,
V_151 -> V_31 , V_130 -> V_134 ,
V_131 ) ;
} else {
F_86 () ;
}
return V_27 ;
}
static void F_133 ( struct V_177 * V_131 ,
struct V_63 * V_64 ,
struct V_120 * V_121 )
{
T_2 V_6 = F_83 ( V_64 , V_121 ) ;
if ( V_131 -> V_132 ) {
V_6 |= V_131 -> V_133 ;
F_95 ( V_64 , V_121 , V_6 ) ;
}
if ( V_131 -> V_208 ) {
struct V_138 * V_139 ;
F_22 ( ! ( V_6 & V_144 ) ) ;
V_139 = (struct V_138 * ) ( V_121 + 1 ) ;
F_156 ( V_64 , V_139 , & V_131 -> V_20 ) ;
}
}
static int F_157 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_202 * V_130 ,
struct V_177 * V_131 )
{
struct V_65 V_20 ;
struct V_61 * V_62 ;
struct V_120 * V_121 ;
struct V_63 * V_64 ;
T_3 V_122 ;
int V_27 ;
int V_77 = 0 ;
if ( V_83 -> V_210 )
return 0 ;
V_62 = F_32 () ;
if ( ! V_62 )
return - V_85 ;
V_20 . V_21 = V_130 -> V_25 ;
V_20 . type = V_73 ;
V_20 . V_31 = V_130 -> V_34 ;
V_62 -> V_72 = 1 ;
V_62 -> V_201 = 1 ;
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
V_122 = F_80 ( V_64 , V_62 -> V_79 [ 0 ] ) ;
#ifdef F_84
if ( V_122 < sizeof( * V_121 ) ) {
V_27 = F_90 ( V_83 , V_33 -> V_35 -> V_60 ,
V_62 , ( T_2 ) - 1 , 0 ) ;
if ( V_27 < 0 ) {
V_77 = V_27 ;
goto V_69;
}
V_64 = V_62 -> V_78 [ 0 ] ;
V_122 = F_80 ( V_64 , V_62 -> V_79 [ 0 ] ) ;
}
#endif
F_22 ( V_122 < sizeof( * V_121 ) ) ;
V_121 = F_81 ( V_64 , V_62 -> V_79 [ 0 ] , struct V_120 ) ;
F_133 ( V_131 , V_64 , V_121 ) ;
F_98 ( V_64 ) ;
V_69:
F_48 ( V_62 ) ;
return V_77 ;
}
static int F_158 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_202 * V_130 ,
struct V_177 * V_131 ,
int V_203 )
{
int V_27 = 0 ;
struct V_212 * V_151 ;
struct V_65 V_205 ;
T_2 V_16 = 0 ;
T_2 V_206 = 0 ;
V_205 . V_21 = V_130 -> V_25 ;
V_205 . V_31 = V_130 -> V_34 ;
V_205 . type = V_73 ;
V_151 = F_159 ( V_130 ) ;
if ( V_130 -> type == V_164 )
V_16 = V_151 -> V_16 ;
else
V_206 = V_151 -> V_33 ;
F_22 ( V_130 -> V_134 != 1 ) ;
if ( V_130 -> V_207 == V_200 && V_203 ) {
F_22 ( ! V_131 || ! V_131 -> V_132 ||
! V_131 -> V_208 ) ;
V_27 = F_160 ( V_83 , V_33 ,
V_16 , V_206 ,
V_131 -> V_133 ,
& V_131 -> V_20 ,
V_151 -> V_166 , & V_205 ) ;
} else if ( V_130 -> V_207 == V_200 ) {
V_27 = F_150 ( V_83 , V_33 , V_130 -> V_25 ,
V_130 -> V_34 , V_16 , V_206 ,
V_151 -> V_166 , 0 , 1 , V_131 ) ;
} else if ( V_130 -> V_207 == V_209 ) {
V_27 = F_155 ( V_83 , V_33 , V_130 -> V_25 ,
V_130 -> V_34 , V_16 , V_206 ,
V_151 -> V_166 , 0 , 1 , V_131 ) ;
} else {
F_86 () ;
}
return V_27 ;
}
static int F_161 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_202 * V_130 ,
struct V_177 * V_131 ,
int V_203 )
{
int V_27 = 0 ;
if ( V_83 -> V_210 )
return 0 ;
if ( F_162 ( V_130 ) ) {
struct V_117 * V_98 ;
F_22 ( V_131 ) ;
V_98 = F_163 ( V_130 ) ;
if ( V_203 ) {
F_164 ( V_33 , V_130 -> V_25 ,
V_130 -> V_34 , 1 ) ;
if ( V_98 -> V_181 ) {
V_27 = F_165 ( V_83 , V_33 ,
V_130 -> V_25 ,
V_130 -> V_34 ) ;
}
}
F_45 ( & V_98 -> V_75 ) ;
return V_27 ;
}
if ( V_130 -> type == V_165 ||
V_130 -> type == V_164 )
V_27 = F_158 ( V_83 , V_33 , V_130 , V_131 ,
V_203 ) ;
else if ( V_130 -> type == V_155 ||
V_130 -> type == V_154 )
V_27 = F_152 ( V_83 , V_33 , V_130 , V_131 ,
V_203 ) ;
else
F_86 () ;
return V_27 ;
}
T_1 int F_166 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_97 * V_213 )
{
struct V_118 * V_119 ;
struct V_202 * V_151 ;
struct V_117 * V_214 = NULL ;
struct V_177 * V_131 ;
int V_27 ;
int V_7 = 0 ;
int V_215 = 0 ;
V_119 = & V_83 -> V_129 -> V_119 ;
while ( 1 ) {
if ( ! V_214 ) {
if ( F_167 ( V_213 ) )
break;
V_214 = F_168 ( V_213 -> V_216 ,
struct V_117 , V_213 ) ;
V_27 = F_169 ( V_83 , V_214 ) ;
if ( V_27 == - V_175 ) {
V_214 = NULL ;
V_7 ++ ;
continue;
}
}
V_151 = F_170 ( V_214 ) ;
if ( V_151 && V_151 -> V_217 &&
F_171 ( V_119 , V_151 -> V_217 ) ) {
F_172 ( & V_214 -> V_213 ) ;
F_45 ( & V_214 -> V_75 ) ;
V_214 = NULL ;
V_119 -> V_218 ++ ;
F_13 ( & V_119 -> V_49 ) ;
F_46 () ;
F_11 ( & V_119 -> V_49 ) ;
continue;
}
V_215 = V_214 -> V_215 ;
V_214 -> V_215 = 0 ;
V_131 = V_214 -> V_131 ;
V_214 -> V_131 = NULL ;
if ( ! V_151 ) {
V_151 = & V_214 -> V_130 ;
if ( V_131 && V_215 ) {
F_9 ( V_131 ) ;
V_131 = NULL ;
}
if ( V_131 ) {
F_13 ( & V_119 -> V_49 ) ;
V_27 = F_157 ( V_83 , V_33 ,
V_151 , V_131 ) ;
F_9 ( V_131 ) ;
if ( V_27 ) {
F_173 ( V_219 L_1 , V_27 ) ;
F_11 ( & V_119 -> V_49 ) ;
return V_27 ;
}
goto V_216;
}
F_172 ( & V_214 -> V_213 ) ;
V_214 = NULL ;
}
V_151 -> V_220 = 0 ;
F_174 ( & V_151 -> V_14 , & V_119 -> V_33 ) ;
V_119 -> V_221 -- ;
F_13 ( & V_119 -> V_49 ) ;
V_27 = F_161 ( V_83 , V_33 , V_151 , V_131 ,
V_215 ) ;
F_89 ( V_151 ) ;
F_9 ( V_131 ) ;
V_7 ++ ;
if ( V_27 ) {
F_173 ( V_219 L_2 , V_27 ) ;
F_11 ( & V_119 -> V_49 ) ;
return V_27 ;
}
V_216:
F_175 ( V_83 , V_33 -> V_35 -> V_60 ,
2 * 1024 * 1024 ,
F_176 ( V_33 , 0 ) ,
V_222 ) ;
F_46 () ;
F_11 ( & V_119 -> V_49 ) ;
}
return V_7 ;
}
static void F_177 ( struct V_118 * V_119 ,
unsigned long V_123 )
{
struct V_97 * V_223 = V_119 -> V_224 . V_216 ;
F_13 ( & V_119 -> V_49 ) ;
F_178 ( L_3 ,
V_123 , V_223 ) ;
F_179 ( V_119 -> V_225 ,
V_123 != V_119 -> V_221 ||
V_119 -> V_224 . V_216 != V_223 ) ;
F_178 ( L_4 ,
V_119 -> V_221 , V_119 -> V_224 . V_216 ) ;
F_11 ( & V_119 -> V_49 ) ;
}
int F_180 ( struct V_82 * V_83 ,
struct V_32 * V_33 , unsigned long V_7 )
{
struct V_14 * V_130 ;
struct V_118 * V_119 ;
struct V_202 * V_151 ;
struct V_97 V_213 ;
int V_27 ;
T_2 V_226 ;
int V_227 = V_7 == ( unsigned long ) - 1 ;
int V_228 = 0 ;
unsigned long V_123 = 0 ;
int V_229 ;
if ( V_83 -> V_210 )
return 0 ;
if ( V_33 == V_33 -> V_35 -> V_60 )
V_33 = V_33 -> V_35 -> V_230 ;
F_175 ( V_83 , V_33 -> V_35 -> V_60 ,
2 * 1024 * 1024 , F_176 ( V_33 , 0 ) ,
V_222 ) ;
V_119 = & V_83 -> V_129 -> V_119 ;
F_52 ( & V_213 ) ;
V_74:
V_229 = 0 ;
F_11 ( & V_119 -> V_49 ) ;
if ( V_7 == 0 ) {
V_7 = V_119 -> V_221 * 2 ;
V_228 = 1 ;
}
while ( 1 ) {
if ( ! ( V_227 || V_228 ) &&
V_119 -> V_218 < 64 )
break;
V_226 = V_119 -> V_231 ;
V_27 = F_181 ( V_83 , & V_213 ,
V_119 -> V_231 ) ;
if ( V_27 )
break;
if ( V_226 >= V_119 -> V_231 ) {
if ( V_229 == 0 ) {
V_229 = 1 ;
V_123 = V_119 -> V_221 ;
} else {
F_177 ( V_119 , V_123 ) ;
V_229 = 0 ;
}
}
V_27 = F_166 ( V_83 , V_33 , & V_213 ) ;
if ( V_27 < 0 ) {
F_13 ( & V_119 -> V_49 ) ;
F_151 ( V_83 , V_33 , V_27 ) ;
return V_27 ;
}
V_7 -= F_182 (unsigned long, ret, count) ;
if ( V_7 == 0 )
break;
if ( V_27 || V_119 -> V_231 == 0 ) {
V_229 = 0 ;
}
}
if ( V_227 ) {
V_130 = F_183 ( & V_119 -> V_33 ) ;
if ( ! V_130 )
goto V_69;
V_7 = ( unsigned long ) - 1 ;
while ( V_130 ) {
V_151 = F_12 ( V_130 , struct V_202 ,
V_14 ) ;
if ( F_162 ( V_151 ) ) {
struct V_117 * V_98 ;
V_98 = F_163 ( V_151 ) ;
F_5 ( & V_151 -> V_116 ) ;
F_13 ( & V_119 -> V_49 ) ;
F_34 ( & V_98 -> V_75 ) ;
F_45 ( & V_98 -> V_75 ) ;
F_89 ( V_151 ) ;
F_46 () ;
goto V_74;
}
V_130 = F_184 ( V_130 ) ;
}
F_13 ( & V_119 -> V_49 ) ;
F_185 ( 1 ) ;
goto V_74;
}
V_69:
F_13 ( & V_119 -> V_49 ) ;
return 0 ;
}
int F_186 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
T_2 V_25 , T_2 V_34 , T_2 V_6 ,
int V_181 )
{
struct V_177 * V_131 ;
int V_27 ;
V_131 = F_187 ( sizeof( * V_131 ) , V_38 ) ;
if ( ! V_131 )
return - V_85 ;
V_131 -> V_133 = V_6 ;
V_131 -> V_132 = 1 ;
V_131 -> V_208 = 0 ;
V_131 -> V_181 = V_181 ? 1 : 0 ;
V_27 = F_188 ( V_33 -> V_35 , V_83 , V_25 ,
V_34 , V_131 ) ;
if ( V_27 )
F_9 ( V_131 ) ;
return V_27 ;
}
static T_1 int F_189 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_61 * V_62 ,
T_2 V_21 , T_2 V_31 , T_2 V_25 )
{
struct V_117 * V_98 ;
struct V_202 * V_151 ;
struct V_204 * V_232 ;
struct V_118 * V_119 ;
struct V_14 * V_130 ;
int V_27 = 0 ;
V_27 = - V_153 ;
V_119 = & V_83 -> V_129 -> V_119 ;
F_11 ( & V_119 -> V_49 ) ;
V_98 = F_87 ( V_83 , V_25 ) ;
if ( ! V_98 )
goto V_69;
if ( ! F_88 ( & V_98 -> V_75 ) ) {
F_5 ( & V_98 -> V_130 . V_116 ) ;
F_13 ( & V_119 -> V_49 ) ;
F_43 ( V_62 ) ;
F_34 ( & V_98 -> V_75 ) ;
F_45 ( & V_98 -> V_75 ) ;
F_89 ( & V_98 -> V_130 ) ;
return - V_175 ;
}
V_130 = F_190 ( & V_98 -> V_130 . V_14 ) ;
if ( ! V_130 )
goto V_233;
V_151 = F_12 ( V_130 , struct V_202 , V_14 ) ;
if ( V_151 -> V_25 != V_25 )
goto V_233;
V_27 = 1 ;
if ( V_151 -> type != V_155 )
goto V_233;
V_232 = F_153 ( V_151 ) ;
V_130 = F_190 ( V_130 ) ;
if ( V_130 ) {
V_151 = F_12 ( V_130 , struct V_202 , V_14 ) ;
if ( V_151 -> V_25 == V_25 )
goto V_233;
}
if ( V_232 -> V_33 != V_33 -> V_234 . V_21 ||
V_232 -> V_21 != V_21 || V_232 -> V_31 != V_31 )
goto V_233;
V_27 = 0 ;
V_233:
F_45 ( & V_98 -> V_75 ) ;
V_69:
F_13 ( & V_119 -> V_49 ) ;
return V_27 ;
}
static T_1 int F_191 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_61 * V_62 ,
T_2 V_21 , T_2 V_31 , T_2 V_25 )
{
struct V_32 * V_60 = V_33 -> V_35 -> V_60 ;
struct V_63 * V_64 ;
struct V_150 * V_151 ;
struct V_162 * V_163 ;
struct V_120 * V_121 ;
struct V_65 V_20 ;
T_3 V_122 ;
int V_27 ;
V_20 . V_21 = V_25 ;
V_20 . V_31 = ( T_2 ) - 1 ;
V_20 . type = V_73 ;
V_27 = F_36 ( NULL , V_60 , & V_20 , V_62 , 0 , 0 ) ;
if ( V_27 < 0 )
goto V_69;
F_22 ( V_27 == 0 ) ;
V_27 = - V_153 ;
if ( V_62 -> V_79 [ 0 ] == 0 )
goto V_69;
V_62 -> V_79 [ 0 ] -- ;
V_64 = V_62 -> V_78 [ 0 ] ;
F_39 ( V_64 , & V_20 , V_62 -> V_79 [ 0 ] ) ;
if ( V_20 . V_21 != V_25 || V_20 . type != V_73 )
goto V_69;
V_27 = 1 ;
V_122 = F_80 ( V_64 , V_62 -> V_79 [ 0 ] ) ;
#ifdef F_84
if ( V_122 < sizeof( * V_121 ) ) {
F_8 ( V_122 != sizeof( struct V_126 ) ) ;
goto V_69;
}
#endif
V_121 = F_81 ( V_64 , V_62 -> V_79 [ 0 ] , struct V_120 ) ;
if ( V_122 != sizeof( * V_121 ) +
F_128 ( V_155 ) )
goto V_69;
if ( F_192 ( V_64 , V_121 ) <=
F_193 ( & V_33 -> V_235 ) )
goto V_69;
V_163 = (struct V_162 * ) ( V_121 + 1 ) ;
if ( F_122 ( V_64 , V_163 ) !=
V_155 )
goto V_69;
V_151 = (struct V_150 * ) ( & V_163 -> V_31 ) ;
if ( F_82 ( V_64 , V_121 ) !=
F_116 ( V_64 , V_151 ) ||
F_103 ( V_64 , V_151 ) !=
V_33 -> V_234 . V_21 ||
F_104 ( V_64 , V_151 ) != V_21 ||
F_105 ( V_64 , V_151 ) != V_31 )
goto V_69;
V_27 = 0 ;
V_69:
return V_27 ;
}
int F_194 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
T_2 V_21 , T_2 V_31 , T_2 V_25 )
{
struct V_61 * V_62 ;
int V_27 ;
int V_236 ;
V_62 = F_32 () ;
if ( ! V_62 )
return - V_153 ;
do {
V_27 = F_191 ( V_83 , V_33 , V_62 , V_21 ,
V_31 , V_25 ) ;
if ( V_27 && V_27 != - V_153 )
goto V_69;
V_236 = F_189 ( V_83 , V_33 , V_62 , V_21 ,
V_31 , V_25 ) ;
} while ( V_236 == - V_175 );
if ( V_236 && V_236 != - V_153 ) {
V_27 = V_236 ;
goto V_69;
}
if ( V_27 != - V_153 || V_236 != - V_153 )
V_27 = 0 ;
V_69:
F_48 ( V_62 ) ;
if ( V_33 -> V_234 . V_21 == V_237 )
F_8 ( V_27 > 0 ) ;
return V_27 ;
}
static int F_195 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_63 * V_238 ,
int V_239 , int V_240 , int V_198 )
{
T_2 V_25 ;
T_2 V_34 ;
T_2 V_16 ;
T_2 V_206 ;
T_3 V_68 ;
struct V_65 V_20 ;
struct V_241 * V_242 ;
int V_41 ;
int V_166 ;
int V_27 = 0 ;
int (* F_196)( struct V_82 * , struct V_32 * ,
T_2 , T_2 , T_2 , T_2 , T_2 , T_2 , int );
V_206 = F_197 ( V_238 ) ;
V_68 = F_37 ( V_238 ) ;
V_166 = F_198 ( V_238 ) ;
if ( ! V_33 -> V_243 && V_166 == 0 )
return 0 ;
if ( V_240 )
F_196 = F_147 ;
else
F_196 = V_244 ;
if ( V_239 )
V_16 = V_238 -> V_30 ;
else
V_16 = 0 ;
for ( V_41 = 0 ; V_41 < V_68 ; V_41 ++ ) {
if ( V_166 == 0 ) {
F_39 ( V_238 , & V_20 , V_41 ) ;
if ( F_199 ( & V_20 ) != V_245 )
continue;
V_242 = F_81 ( V_238 , V_41 ,
struct V_241 ) ;
if ( F_200 ( V_238 , V_242 ) ==
V_246 )
continue;
V_25 = F_201 ( V_238 , V_242 ) ;
if ( V_25 == 0 )
continue;
V_34 = F_202 ( V_238 , V_242 ) ;
V_20 . V_31 -= F_203 ( V_238 , V_242 ) ;
V_27 = F_196 ( V_83 , V_33 , V_25 , V_34 ,
V_16 , V_206 , V_20 . V_21 ,
V_20 . V_31 , V_198 ) ;
if ( V_27 )
goto V_156;
} else {
V_25 = F_204 ( V_238 , V_41 ) ;
V_34 = F_205 ( V_33 , V_166 - 1 ) ;
V_27 = F_196 ( V_83 , V_33 , V_25 , V_34 ,
V_16 , V_206 , V_166 - 1 , 0 ,
V_198 ) ;
if ( V_27 )
goto V_156;
}
}
return 0 ;
V_156:
return V_27 ;
}
int F_206 ( struct V_82 * V_83 , struct V_32 * V_33 ,
struct V_63 * V_238 , int V_239 , int V_198 )
{
return F_195 ( V_83 , V_33 , V_238 , V_239 , 1 , V_198 ) ;
}
int F_207 ( struct V_82 * V_83 , struct V_32 * V_33 ,
struct V_63 * V_238 , int V_239 , int V_198 )
{
return F_195 ( V_83 , V_33 , V_238 , V_239 , 0 , V_198 ) ;
}
static int F_208 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_61 * V_62 ,
struct V_1 * V_2 )
{
int V_27 ;
struct V_32 * V_60 = V_33 -> V_35 -> V_60 ;
unsigned long V_139 ;
struct V_63 * V_64 ;
V_27 = F_36 ( V_83 , V_60 , & V_2 -> V_20 , V_62 , 0 , 1 ) ;
if ( V_27 < 0 )
goto V_156;
F_22 ( V_27 ) ;
V_64 = V_62 -> V_78 [ 0 ] ;
V_139 = F_209 ( V_64 , V_62 -> V_79 [ 0 ] ) ;
F_210 ( V_64 , & V_2 -> V_112 , V_139 , sizeof( V_2 -> V_112 ) ) ;
F_98 ( V_64 ) ;
F_43 ( V_62 ) ;
V_156:
if ( V_27 ) {
F_151 ( V_83 , V_33 , V_27 ) ;
return V_27 ;
}
return 0 ;
}
static struct V_1 *
F_211 ( struct V_32 * V_33 ,
struct V_1 * V_2 )
{
struct V_14 * V_130 ;
F_11 ( & V_33 -> V_35 -> V_17 ) ;
V_130 = F_184 ( & V_2 -> V_19 ) ;
F_6 ( V_2 ) ;
if ( V_130 ) {
V_2 = F_12 ( V_130 , struct V_1 ,
V_19 ) ;
F_4 ( V_2 ) ;
} else
V_2 = NULL ;
F_13 ( & V_33 -> V_35 -> V_17 ) ;
return V_2 ;
}
static int F_212 ( struct V_1 * V_13 ,
struct V_82 * V_83 ,
struct V_61 * V_62 )
{
struct V_32 * V_33 = V_13 -> V_35 -> V_230 ;
struct V_247 * V_247 = NULL ;
T_2 V_248 = 0 ;
int V_249 = V_250 ;
int V_251 = 0 ;
int V_252 = 0 ;
int V_27 = 0 ;
if ( V_13 -> V_20 . V_31 < ( 100 * 1024 * 1024 ) ) {
F_11 ( & V_13 -> V_49 ) ;
V_13 -> V_253 = V_254 ;
F_13 ( & V_13 -> V_49 ) ;
return 0 ;
}
V_74:
V_247 = F_213 ( V_33 , V_13 , V_62 ) ;
if ( F_214 ( V_247 ) && F_215 ( V_247 ) != - V_153 ) {
V_27 = F_215 ( V_247 ) ;
F_43 ( V_62 ) ;
goto V_69;
}
if ( F_214 ( V_247 ) ) {
F_22 ( V_252 ) ;
V_252 ++ ;
if ( V_13 -> V_113 )
goto V_125;
V_27 = F_216 ( V_33 , V_83 , V_13 , V_62 ) ;
if ( V_27 )
goto V_125;
goto V_74;
}
if ( V_13 -> V_255 == V_83 -> V_256 &&
F_217 ( V_247 ) ) {
V_249 = V_257 ;
goto V_258;
}
F_218 ( V_247 ) -> V_259 = 0 ;
V_27 = F_219 ( V_83 , V_33 , V_247 ) ;
F_8 ( V_27 ) ;
if ( F_217 ( V_247 ) > 0 ) {
V_27 = F_220 ( V_33 , V_83 , V_62 ,
V_247 ) ;
if ( V_27 )
goto V_258;
}
F_11 ( & V_13 -> V_49 ) ;
if ( V_13 -> V_3 != V_4 ) {
V_249 = V_254 ;
F_13 ( & V_13 -> V_49 ) ;
goto V_258;
}
F_13 ( & V_13 -> V_49 ) ;
V_251 = ( int ) F_221 ( V_13 -> V_20 . V_31 , 1024 * 1024 * 1024 ) ;
if ( ! V_251 )
V_251 = 1 ;
V_251 *= 16 ;
V_251 *= V_260 ;
V_27 = F_222 ( V_247 , V_251 ) ;
if ( V_27 )
goto V_258;
V_27 = F_223 ( V_247 , V_83 , 0 , 0 , V_251 ,
V_251 , V_251 ,
& V_248 ) ;
if ( ! V_27 )
V_249 = V_257 ;
F_224 ( V_247 , V_251 ) ;
V_258:
F_225 ( V_247 ) ;
V_125:
F_43 ( V_62 ) ;
V_69:
F_11 ( & V_13 -> V_49 ) ;
if ( ! V_27 && V_249 == V_257 )
V_13 -> V_255 = V_83 -> V_256 ;
V_13 -> V_253 = V_249 ;
F_13 ( & V_13 -> V_49 ) ;
return V_27 ;
}
int F_226 ( struct V_82 * V_83 ,
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
if ( V_2 -> V_253 == V_261 )
break;
V_2 = F_211 ( V_33 , V_2 ) ;
}
if ( ! V_2 ) {
if ( V_67 == 0 )
break;
V_67 = 0 ;
continue;
}
V_77 = F_212 ( V_2 , V_83 , V_62 ) ;
V_67 = V_2 -> V_20 . V_21 + V_2 -> V_20 . V_31 ;
F_6 ( V_2 ) ;
}
while ( 1 ) {
if ( V_67 == 0 ) {
V_77 = F_180 ( V_83 , V_33 ,
( unsigned long ) - 1 ) ;
if ( V_77 )
goto V_69;
}
V_2 = F_64 ( V_33 -> V_35 , V_67 ) ;
while ( V_2 ) {
if ( V_2 -> V_253 == V_261 ) {
F_6 ( V_2 ) ;
goto V_74;
}
if ( V_2 -> V_262 )
break;
V_2 = F_211 ( V_33 , V_2 ) ;
}
if ( ! V_2 ) {
if ( V_67 == 0 )
break;
V_67 = 0 ;
continue;
}
if ( V_2 -> V_253 == V_257 )
V_2 -> V_253 = V_263 ;
V_2 -> V_262 = 0 ;
V_67 = V_2 -> V_20 . V_21 + V_2 -> V_20 . V_31 ;
V_77 = F_208 ( V_83 , V_33 , V_62 , V_2 ) ;
if ( V_77 )
goto V_69;
F_6 ( V_2 ) ;
}
while ( 1 ) {
if ( V_67 == 0 ) {
V_77 = F_180 ( V_83 , V_33 ,
( unsigned long ) - 1 ) ;
if ( V_77 )
goto V_69;
}
V_2 = F_64 ( V_33 -> V_35 , V_67 ) ;
while ( V_2 ) {
if ( V_2 -> V_262 ) {
F_6 ( V_2 ) ;
goto V_74;
}
if ( V_2 -> V_253 == V_263 )
break;
V_2 = F_211 ( V_33 , V_2 ) ;
}
if ( ! V_2 ) {
if ( V_67 == 0 )
break;
V_67 = 0 ;
continue;
}
V_77 = F_227 ( V_33 , V_83 , V_2 , V_62 ) ;
if ( ! V_77 && V_2 -> V_253 == V_263 )
V_2 -> V_253 = V_254 ;
V_67 = V_2 -> V_20 . V_21 + V_2 -> V_20 . V_31 ;
F_6 ( V_2 ) ;
}
V_69:
F_48 ( V_62 ) ;
return V_77 ;
}
int F_228 ( struct V_32 * V_33 , T_2 V_25 )
{
struct V_1 * V_13 ;
int V_264 = 0 ;
V_13 = F_65 ( V_33 -> V_35 , V_25 ) ;
if ( ! V_13 || V_13 -> V_113 )
V_264 = 1 ;
if ( V_13 )
F_6 ( V_13 ) ;
return V_264 ;
}
static int F_229 ( struct V_11 * V_12 , T_2 V_6 ,
T_2 V_265 , T_2 V_266 ,
struct V_96 * * V_99 )
{
struct V_96 * V_100 ;
int V_41 ;
int V_104 ;
if ( V_6 & ( V_267 | V_268 |
V_269 ) )
V_104 = 2 ;
else
V_104 = 1 ;
V_100 = F_66 ( V_12 , V_6 ) ;
if ( V_100 ) {
F_11 ( & V_100 -> V_49 ) ;
V_100 -> V_265 += V_265 ;
V_100 -> V_270 += V_265 * V_104 ;
V_100 -> V_266 += V_266 ;
V_100 -> V_271 += V_266 * V_104 ;
V_100 -> V_102 = 0 ;
F_13 ( & V_100 -> V_49 ) ;
* V_99 = V_100 ;
return 0 ;
}
V_100 = F_51 ( sizeof( * V_100 ) , V_38 ) ;
if ( ! V_100 )
return - V_85 ;
for ( V_41 = 0 ; V_41 < V_272 ; V_41 ++ )
F_52 ( & V_100 -> V_273 [ V_41 ] ) ;
F_230 ( & V_100 -> V_274 ) ;
F_231 ( & V_100 -> V_49 ) ;
V_100 -> V_6 = V_6 & V_101 ;
V_100 -> V_265 = V_265 ;
V_100 -> V_270 = V_265 * V_104 ;
V_100 -> V_266 = V_266 ;
V_100 -> V_271 = V_266 * V_104 ;
V_100 -> V_275 = 0 ;
V_100 -> V_276 = 0 ;
V_100 -> V_277 = 0 ;
V_100 -> V_278 = 0 ;
V_100 -> V_102 = 0 ;
V_100 -> V_279 = V_222 ;
V_100 -> V_280 = 0 ;
V_100 -> V_281 = 0 ;
F_54 ( & V_100 -> V_81 ) ;
* V_99 = V_100 ;
F_232 ( & V_100 -> V_86 , & V_12 -> V_99 ) ;
return 0 ;
}
static void F_233 ( struct V_11 * V_35 , T_2 V_6 )
{
T_2 V_282 = F_234 ( V_6 ) &
V_283 ;
if ( V_6 & V_284 )
V_35 -> V_285 |= V_282 ;
if ( V_6 & V_114 )
V_35 -> V_286 |= V_282 ;
if ( V_6 & V_287 )
V_35 -> V_288 |= V_282 ;
}
static T_2 F_235 ( struct V_11 * V_35 , T_2 V_6 )
{
struct V_289 * V_290 = V_35 -> V_291 ;
T_2 V_292 = 0 ;
if ( ! V_290 )
return 0 ;
if ( V_6 & V_284 &&
V_290 -> V_293 . V_6 & V_294 ) {
V_292 = V_284 | V_290 -> V_293 . V_292 ;
} else if ( V_6 & V_287 &&
V_290 -> V_295 . V_6 & V_294 ) {
V_292 = V_287 | V_290 -> V_295 . V_292 ;
} else if ( V_6 & V_114 &&
V_290 -> V_296 . V_6 & V_294 ) {
V_292 = V_114 | V_290 -> V_296 . V_292 ;
}
return V_292 ;
}
T_2 F_236 ( struct V_32 * V_33 , T_2 V_6 )
{
T_2 V_297 = V_33 -> V_35 -> V_298 -> V_299 +
V_33 -> V_35 -> V_298 -> V_300 ;
T_2 V_292 ;
F_11 ( & V_33 -> V_35 -> V_301 ) ;
V_292 = F_235 ( V_33 -> V_35 , V_6 ) ;
if ( V_292 ) {
if ( ( V_6 & V_292 ) & V_283 ) {
F_13 ( & V_33 -> V_35 -> V_301 ) ;
return F_237 ( V_292 ) ;
}
}
F_13 ( & V_33 -> V_35 -> V_301 ) ;
if ( V_297 == 1 )
V_6 &= ~ ( V_268 | V_302 ) ;
if ( V_297 < 4 )
V_6 &= ~ V_269 ;
if ( ( V_6 & V_267 ) &&
( V_6 & ( V_268 |
V_269 ) ) ) {
V_6 &= ~ V_267 ;
}
if ( ( V_6 & V_268 ) &&
( V_6 & V_269 ) ) {
V_6 &= ~ V_268 ;
}
if ( ( V_6 & V_302 ) &&
( ( V_6 & V_268 ) |
( V_6 & V_269 ) |
( V_6 & V_267 ) ) ) {
V_6 &= ~ V_302 ;
}
return F_237 ( V_6 ) ;
}
static T_2 F_238 ( struct V_32 * V_33 , T_2 V_6 )
{
if ( V_6 & V_284 )
V_6 |= V_33 -> V_35 -> V_285 ;
else if ( V_6 & V_287 )
V_6 |= V_33 -> V_35 -> V_288 ;
else if ( V_6 & V_114 )
V_6 |= V_33 -> V_35 -> V_286 ;
return F_236 ( V_33 , V_6 ) ;
}
T_2 F_176 ( struct V_32 * V_33 , int V_293 )
{
T_2 V_6 ;
if ( V_293 )
V_6 = V_284 ;
else if ( V_33 == V_33 -> V_35 -> V_303 )
V_6 = V_287 ;
else
V_6 = V_114 ;
return F_238 ( V_33 , V_6 ) ;
}
void F_239 ( struct V_32 * V_33 , struct V_247 * V_247 )
{
F_218 ( V_247 ) -> V_99 = F_66 ( V_33 -> V_35 ,
V_284 ) ;
}
int F_222 ( struct V_247 * V_247 , T_2 V_304 )
{
struct V_96 * V_305 ;
struct V_32 * V_33 = F_218 ( V_247 ) -> V_33 ;
T_2 V_108 ;
int V_27 = 0 , V_306 = 0 , V_307 = 1 ;
V_304 = ( V_304 + V_33 -> V_308 - 1 ) & ~ ( ( T_2 ) V_33 -> V_308 - 1 ) ;
if ( V_33 == V_33 -> V_35 -> V_230 ||
F_218 ( V_247 ) -> V_309 . V_21 == V_310 ) {
V_307 = 0 ;
V_306 = 1 ;
}
V_305 = F_218 ( V_247 ) -> V_99 ;
if ( ! V_305 )
goto V_311;
V_74:
F_11 ( & V_305 -> V_49 ) ;
V_108 = V_305 -> V_266 + V_305 -> V_276 +
V_305 -> V_275 + V_305 -> V_277 +
V_305 -> V_278 ;
if ( V_108 + V_304 > V_305 -> V_265 ) {
struct V_82 * V_83 ;
if ( ! V_305 -> V_102 && V_307 ) {
T_2 V_312 ;
V_305 -> V_279 = V_313 ;
F_13 ( & V_305 -> V_49 ) ;
V_311:
V_312 = F_176 ( V_33 , 1 ) ;
V_83 = F_240 ( V_33 ) ;
if ( F_214 ( V_83 ) )
return F_215 ( V_83 ) ;
V_27 = F_175 ( V_83 , V_33 -> V_35 -> V_60 ,
V_304 + 2 * 1024 * 1024 ,
V_312 ,
V_222 ) ;
F_241 ( V_83 , V_33 ) ;
if ( V_27 < 0 ) {
if ( V_27 != - V_314 )
return V_27 ;
else
goto V_315;
}
if ( ! V_305 ) {
F_239 ( V_33 , V_247 ) ;
V_305 = F_218 ( V_247 ) -> V_99 ;
}
goto V_74;
}
if ( V_305 -> V_275 < V_304 )
V_306 = 1 ;
F_13 ( & V_305 -> V_49 ) ;
V_315:
if ( ! V_306 &&
! F_242 ( & V_33 -> V_35 -> V_316 ) ) {
V_306 = 1 ;
V_83 = F_240 ( V_33 ) ;
if ( F_214 ( V_83 ) )
return F_215 ( V_83 ) ;
V_27 = F_243 ( V_83 , V_33 ) ;
if ( V_27 )
return V_27 ;
goto V_74;
}
return - V_314 ;
}
V_305 -> V_278 += V_304 ;
F_244 ( V_33 -> V_35 , L_5 ,
V_305 -> V_6 , V_304 , 1 ) ;
F_13 ( & V_305 -> V_49 ) ;
return 0 ;
}
void F_224 ( struct V_247 * V_247 , T_2 V_304 )
{
struct V_32 * V_33 = F_218 ( V_247 ) -> V_33 ;
struct V_96 * V_305 ;
V_304 = ( V_304 + V_33 -> V_308 - 1 ) & ~ ( ( T_2 ) V_33 -> V_308 - 1 ) ;
V_305 = F_218 ( V_247 ) -> V_99 ;
F_11 ( & V_305 -> V_49 ) ;
V_305 -> V_278 -= V_304 ;
F_244 ( V_33 -> V_35 , L_5 ,
V_305 -> V_6 , V_304 , 0 ) ;
F_13 ( & V_305 -> V_49 ) ;
}
static void F_245 ( struct V_11 * V_12 )
{
struct V_97 * V_98 = & V_12 -> V_99 ;
struct V_96 * V_100 ;
F_67 () ;
F_68 (found, head, list) {
if ( V_100 -> V_6 & V_114 )
V_100 -> V_279 = V_313 ;
}
F_69 () ;
}
static int F_246 ( struct V_32 * V_33 ,
struct V_96 * V_317 , T_2 V_318 ,
int V_319 )
{
struct V_320 * V_321 = & V_33 -> V_35 -> V_322 ;
T_2 V_34 = V_317 -> V_265 - V_317 -> V_277 ;
T_2 V_323 = V_317 -> V_266 + V_317 -> V_276 ;
T_2 V_324 ;
if ( V_319 == V_313 )
return 1 ;
V_323 += V_321 -> V_54 ;
if ( V_319 == V_325 ) {
V_324 = F_247 ( V_33 -> V_35 -> V_326 ) ;
V_324 = F_33 ( T_2 , 64 * 1024 * 1024 ,
F_73 ( V_324 , 1 ) ) ;
if ( V_34 - V_323 < V_324 )
return 1 ;
}
V_324 = F_247 ( V_33 -> V_35 -> V_326 ) ;
V_324 = F_33 ( T_2 , 256 * 1024 * 1024 , F_73 ( V_324 , 2 ) ) ;
if ( V_317 -> V_6 & V_287 )
V_324 = 32 * 1024 * 1024 ;
if ( V_34 > V_324 && V_317 -> V_266 < F_71 ( V_34 , 8 ) )
return 0 ;
return 1 ;
}
static T_2 F_248 ( struct V_32 * V_33 , T_2 type )
{
T_2 V_327 ;
if ( type & V_269 ||
type & V_302 )
V_327 = V_33 -> V_35 -> V_298 -> V_299 ;
else if ( type & V_268 )
V_327 = 2 ;
else
V_327 = 1 ;
return F_249 ( V_33 , V_327 + 1 ) ;
}
static void F_250 ( struct V_82 * V_83 ,
struct V_32 * V_33 , T_2 type )
{
struct V_96 * V_12 ;
T_2 V_328 ;
T_2 V_324 ;
V_12 = F_66 ( V_33 -> V_35 , V_287 ) ;
F_11 ( & V_12 -> V_49 ) ;
V_328 = V_12 -> V_265 - V_12 -> V_266 - V_12 -> V_275 -
V_12 -> V_276 - V_12 -> V_277 ;
F_13 ( & V_12 -> V_49 ) ;
V_324 = F_248 ( V_33 , type ) ;
if ( V_328 < V_324 && F_251 ( V_33 , V_329 ) ) {
F_173 ( V_330 L_6 ,
V_328 , V_324 , type ) ;
F_252 ( V_12 , 0 , 0 ) ;
}
if ( V_328 < V_324 ) {
T_2 V_6 ;
V_6 = F_176 ( V_33 -> V_35 -> V_303 , 0 ) ;
F_253 ( V_83 , V_33 , V_6 ) ;
}
}
static int F_175 ( struct V_82 * V_83 ,
struct V_32 * V_60 , T_2 V_318 ,
T_2 V_6 , int V_319 )
{
struct V_96 * V_99 ;
struct V_11 * V_35 = V_60 -> V_35 ;
int V_331 = 0 ;
int V_27 = 0 ;
V_99 = F_66 ( V_60 -> V_35 , V_6 ) ;
if ( ! V_99 ) {
V_27 = F_229 ( V_60 -> V_35 , V_6 ,
0 , 0 , & V_99 ) ;
F_22 ( V_27 ) ;
}
F_22 ( ! V_99 ) ;
V_74:
F_11 ( & V_99 -> V_49 ) ;
if ( V_319 < V_99 -> V_279 )
V_319 = V_99 -> V_279 ;
if ( V_99 -> V_102 ) {
F_13 ( & V_99 -> V_49 ) ;
return 0 ;
}
if ( ! F_246 ( V_60 , V_99 , V_318 , V_319 ) ) {
F_13 ( & V_99 -> V_49 ) ;
return 0 ;
} else if ( V_99 -> V_280 ) {
V_331 = 1 ;
} else {
V_99 -> V_280 = 1 ;
}
F_13 ( & V_99 -> V_49 ) ;
F_34 ( & V_35 -> V_332 ) ;
if ( V_331 ) {
F_45 ( & V_35 -> V_332 ) ;
V_331 = 0 ;
goto V_74;
}
if ( F_254 ( V_99 ) )
V_6 |= ( V_284 | V_114 ) ;
if ( V_6 & V_284 && V_35 -> V_333 ) {
V_35 -> V_334 ++ ;
if ( ! ( V_35 -> V_334 %
V_35 -> V_333 ) )
F_245 ( V_35 ) ;
}
F_250 ( V_83 , V_60 , V_6 ) ;
V_27 = F_253 ( V_83 , V_60 , V_6 ) ;
if ( V_27 < 0 && V_27 != - V_314 )
goto V_69;
F_11 ( & V_99 -> V_49 ) ;
if ( V_27 )
V_99 -> V_102 = 1 ;
else
V_27 = 1 ;
V_99 -> V_279 = V_222 ;
V_99 -> V_280 = 0 ;
F_13 ( & V_99 -> V_49 ) ;
V_69:
F_45 ( & V_60 -> V_35 -> V_332 ) ;
return V_27 ;
}
static int F_255 ( struct V_32 * V_33 , T_2 V_335 ,
bool V_336 )
{
struct V_320 * V_337 ;
struct V_96 * V_99 ;
struct V_82 * V_83 ;
T_2 V_9 ;
T_2 V_338 ;
T_2 V_339 = 0 ;
long V_340 ;
unsigned long V_341 = ( 2 * 1024 * 1024 ) >> V_342 ;
int V_343 = 0 ;
unsigned long V_80 ;
V_83 = (struct V_82 * ) V_344 -> V_345 ;
V_337 = & V_33 -> V_35 -> V_346 ;
V_99 = V_337 -> V_99 ;
F_2 () ;
V_9 = V_99 -> V_278 ;
V_80 = V_99 -> V_347 ;
if ( V_9 == 0 )
return 0 ;
F_2 () ;
if ( V_33 -> V_35 -> V_348 == 0 ) {
if ( V_83 )
return 0 ;
F_256 ( V_33 , 0 , 0 ) ;
return 0 ;
}
V_338 = F_257 ( V_9 , V_335 ) ;
V_341 = F_33 (unsigned long, nr_pages,
max_reclaim >> PAGE_CACHE_SHIFT) ;
while ( V_343 < 1024 ) {
F_2 () ;
V_341 = F_182 (unsigned long, nr_pages,
root->fs_info->delalloc_bytes >> PAGE_CACHE_SHIFT) ;
F_258 ( V_33 -> V_35 -> V_349 , V_341 ,
V_350 ) ;
F_11 ( & V_99 -> V_49 ) ;
if ( V_9 > V_99 -> V_278 )
V_339 += V_9 - V_99 -> V_278 ;
V_9 = V_99 -> V_278 ;
F_13 ( & V_99 -> V_49 ) ;
V_343 ++ ;
if ( V_9 == 0 || V_339 >= V_338 )
break;
if ( V_83 && V_83 -> V_129 -> V_351 )
return - V_175 ;
if ( V_336 && ! V_83 ) {
F_256 ( V_33 , 0 , 0 ) ;
} else {
V_340 = F_259 ( 1 ) ;
if ( V_340 )
break;
}
if ( V_343 > 3 ) {
F_2 () ;
if ( V_80 != V_99 -> V_347 )
break;
}
}
return V_339 >= V_335 ;
}
static int F_260 ( struct V_32 * V_33 ,
struct V_96 * V_99 ,
T_2 V_304 , int V_319 )
{
struct V_320 * V_352 = & V_33 -> V_35 -> V_353 ;
struct V_82 * V_83 ;
V_83 = (struct V_82 * ) V_344 -> V_345 ;
if ( V_83 )
return - V_175 ;
if ( V_319 )
goto V_354;
F_11 ( & V_99 -> V_49 ) ;
if ( V_99 -> V_275 >= V_304 ) {
F_13 ( & V_99 -> V_49 ) ;
goto V_354;
}
F_13 ( & V_99 -> V_49 ) ;
if ( V_99 != V_352 -> V_99 )
return - V_314 ;
F_11 ( & V_99 -> V_49 ) ;
F_11 ( & V_352 -> V_49 ) ;
if ( V_99 -> V_275 + V_352 -> V_54 < V_304 ) {
F_13 ( & V_352 -> V_49 ) ;
F_13 ( & V_99 -> V_49 ) ;
return - V_314 ;
}
F_13 ( & V_352 -> V_49 ) ;
F_13 ( & V_99 -> V_49 ) ;
V_354:
V_83 = F_240 ( V_33 ) ;
if ( F_214 ( V_83 ) )
return - V_314 ;
return F_243 ( V_83 , V_33 ) ;
}
static int F_261 ( struct V_32 * V_33 ,
struct V_320 * V_337 ,
T_2 V_355 , int V_281 )
{
struct V_96 * V_99 = V_337 -> V_99 ;
T_2 V_108 ;
T_2 V_34 = V_355 ;
int V_252 = 0 ;
int V_27 = 0 ;
bool V_306 = false ;
bool V_356 = false ;
bool V_336 = false ;
V_74:
V_27 = 0 ;
F_11 ( & V_99 -> V_49 ) ;
while ( V_281 && ! V_356 && V_99 -> V_281 ) {
F_13 ( & V_99 -> V_49 ) ;
if ( V_344 -> V_345 )
return - V_175 ;
V_27 = F_262 ( V_99 -> V_81 , ! V_99 -> V_281 ) ;
if ( V_27 )
return - V_357 ;
F_11 ( & V_99 -> V_49 ) ;
}
V_27 = - V_314 ;
V_108 = V_99 -> V_266 + V_99 -> V_276 +
V_99 -> V_275 + V_99 -> V_277 +
V_99 -> V_278 ;
if ( V_108 <= V_99 -> V_265 ) {
if ( V_108 + V_355 <= V_99 -> V_265 ) {
V_99 -> V_278 += V_355 ;
F_244 ( V_33 -> V_35 ,
L_5 , V_99 -> V_6 , V_355 , 1 ) ;
V_27 = 0 ;
} else {
V_34 = V_355 ;
}
} else {
V_336 = true ;
V_34 = V_108 - V_99 -> V_265 +
( V_355 * ( V_252 + 1 ) ) ;
}
if ( V_27 ) {
T_2 V_358 = F_176 ( V_33 , 0 ) ;
T_2 V_359 ;
V_359 = ( V_99 -> V_265 - V_99 -> V_266 ) * 8 ;
F_72 ( V_359 , 10 ) ;
if ( V_99 -> V_275 >= V_359 && V_281 && ! V_306 ) {
V_99 -> V_281 = 1 ;
V_356 = true ;
F_13 ( & V_99 -> V_49 ) ;
V_27 = F_260 ( V_33 , V_99 ,
V_355 , 1 ) ;
if ( V_27 )
goto V_69;
V_306 = true ;
goto V_74;
}
F_11 ( & V_33 -> V_35 -> V_360 ) ;
V_359 = V_33 -> V_35 -> V_361 ;
if ( V_358 & ( V_267 |
V_268 |
V_269 ) )
V_359 >>= 1 ;
if ( V_281 )
V_359 >>= 3 ;
else
V_359 >>= 1 ;
F_13 ( & V_33 -> V_35 -> V_360 ) ;
if ( V_108 + V_34 < V_99 -> V_265 + V_359 ) {
V_99 -> V_278 += V_355 ;
F_244 ( V_33 -> V_35 ,
L_5 , V_99 -> V_6 , V_355 , 1 ) ;
V_27 = 0 ;
} else {
V_336 = true ;
}
}
if ( V_27 && V_281 ) {
V_356 = true ;
V_99 -> V_281 = 1 ;
}
F_13 ( & V_99 -> V_49 ) ;
if ( ! V_27 || ! V_281 )
goto V_69;
V_27 = F_255 ( V_33 , V_34 , V_336 ) ;
if ( V_27 < 0 )
goto V_69;
V_27 = 0 ;
if ( V_252 < 2 ) {
V_336 = true ;
V_252 ++ ;
goto V_74;
}
V_27 = - V_314 ;
if ( V_306 )
goto V_69;
V_27 = F_260 ( V_33 , V_99 , V_355 , 0 ) ;
if ( ! V_27 ) {
V_306 = true ;
goto V_74;
}
V_69:
if ( V_356 ) {
F_11 ( & V_99 -> V_49 ) ;
V_99 -> V_281 = 0 ;
F_263 ( & V_99 -> V_81 ) ;
F_13 ( & V_99 -> V_49 ) ;
}
return V_27 ;
}
static struct V_320 * F_264 (
const struct V_82 * V_83 ,
const struct V_32 * V_33 )
{
struct V_320 * V_337 = NULL ;
if ( V_33 -> V_243 || V_33 == V_33 -> V_35 -> V_362 )
V_337 = V_83 -> V_337 ;
if ( ! V_337 )
V_337 = V_33 -> V_337 ;
if ( ! V_337 )
V_337 = & V_33 -> V_35 -> V_363 ;
return V_337 ;
}
static int F_265 ( struct V_320 * V_337 ,
T_2 V_34 )
{
int V_27 = - V_314 ;
F_11 ( & V_337 -> V_49 ) ;
if ( V_337 -> V_9 >= V_34 ) {
V_337 -> V_9 -= V_34 ;
if ( V_337 -> V_9 < V_337 -> V_54 )
V_337 -> V_102 = 0 ;
V_27 = 0 ;
}
F_13 ( & V_337 -> V_49 ) ;
return V_27 ;
}
static void F_266 ( struct V_320 * V_337 ,
T_2 V_34 , int V_364 )
{
F_11 ( & V_337 -> V_49 ) ;
V_337 -> V_9 += V_34 ;
if ( V_364 )
V_337 -> V_54 += V_34 ;
else if ( V_337 -> V_9 >= V_337 -> V_54 )
V_337 -> V_102 = 1 ;
F_13 ( & V_337 -> V_49 ) ;
}
static void F_267 ( struct V_11 * V_35 ,
struct V_320 * V_337 ,
struct V_320 * V_365 , T_2 V_34 )
{
struct V_96 * V_99 = V_337 -> V_99 ;
F_11 ( & V_337 -> V_49 ) ;
if ( V_34 == ( T_2 ) - 1 )
V_34 = V_337 -> V_54 ;
V_337 -> V_54 -= V_34 ;
if ( V_337 -> V_9 >= V_337 -> V_54 ) {
V_34 = V_337 -> V_9 - V_337 -> V_54 ;
V_337 -> V_9 = V_337 -> V_54 ;
V_337 -> V_102 = 1 ;
} else {
V_34 = 0 ;
}
F_13 ( & V_337 -> V_49 ) ;
if ( V_34 > 0 ) {
if ( V_365 ) {
F_11 ( & V_365 -> V_49 ) ;
if ( ! V_365 -> V_102 ) {
T_2 V_366 ;
V_366 = V_365 -> V_54 - V_365 -> V_9 ;
V_366 = F_257 ( V_34 , V_366 ) ;
V_365 -> V_9 += V_366 ;
if ( V_365 -> V_9 >= V_365 -> V_54 )
V_365 -> V_102 = 1 ;
V_34 -= V_366 ;
}
F_13 ( & V_365 -> V_49 ) ;
}
if ( V_34 ) {
F_11 ( & V_99 -> V_49 ) ;
V_99 -> V_278 -= V_34 ;
F_244 ( V_35 , L_5 ,
V_99 -> V_6 , V_34 , 0 ) ;
V_99 -> V_347 ++ ;
F_13 ( & V_99 -> V_49 ) ;
}
}
}
static int F_268 ( struct V_320 * V_367 ,
struct V_320 * V_368 , T_2 V_34 )
{
int V_27 ;
V_27 = F_265 ( V_367 , V_34 ) ;
if ( V_27 )
return V_27 ;
F_266 ( V_368 , V_34 , 1 ) ;
return 0 ;
}
void F_269 ( struct V_320 * V_369 )
{
memset ( V_369 , 0 , sizeof( * V_369 ) ) ;
F_231 ( & V_369 -> V_49 ) ;
}
struct V_320 * F_270 ( struct V_32 * V_33 )
{
struct V_320 * V_337 ;
struct V_11 * V_35 = V_33 -> V_35 ;
V_337 = F_187 ( sizeof( * V_337 ) , V_38 ) ;
if ( ! V_337 )
return NULL ;
F_269 ( V_337 ) ;
V_337 -> V_99 = F_66 ( V_35 ,
V_114 ) ;
return V_337 ;
}
void F_271 ( struct V_32 * V_33 ,
struct V_320 * V_369 )
{
F_272 ( V_33 , V_369 , ( T_2 ) - 1 ) ;
F_9 ( V_369 ) ;
}
static inline int F_273 ( struct V_32 * V_33 ,
struct V_320 * V_337 ,
T_2 V_34 , int V_281 )
{
int V_27 ;
if ( V_34 == 0 )
return 0 ;
V_27 = F_261 ( V_33 , V_337 , V_34 , V_281 ) ;
if ( ! V_27 ) {
F_266 ( V_337 , V_34 , 1 ) ;
return 0 ;
}
return V_27 ;
}
int F_274 ( struct V_32 * V_33 ,
struct V_320 * V_337 ,
T_2 V_34 )
{
return F_273 ( V_33 , V_337 , V_34 , 1 ) ;
}
int F_275 ( struct V_32 * V_33 ,
struct V_320 * V_337 ,
T_2 V_34 )
{
return F_273 ( V_33 , V_337 , V_34 , 0 ) ;
}
int F_276 ( struct V_32 * V_33 ,
struct V_320 * V_337 , int V_370 )
{
T_2 V_34 = 0 ;
int V_27 = - V_314 ;
if ( ! V_337 )
return 0 ;
F_11 ( & V_337 -> V_49 ) ;
V_34 = F_71 ( V_337 -> V_54 , V_370 ) ;
if ( V_337 -> V_9 >= V_34 )
V_27 = 0 ;
F_13 ( & V_337 -> V_49 ) ;
return V_27 ;
}
static inline int F_277 ( struct V_32 * V_33 ,
struct V_320 * V_337 ,
T_2 V_371 , int V_281 )
{
T_2 V_34 = 0 ;
int V_27 = - V_314 ;
if ( ! V_337 )
return 0 ;
F_11 ( & V_337 -> V_49 ) ;
V_34 = V_371 ;
if ( V_337 -> V_9 >= V_34 )
V_27 = 0 ;
else
V_34 -= V_337 -> V_9 ;
F_13 ( & V_337 -> V_49 ) ;
if ( ! V_27 )
return 0 ;
V_27 = F_261 ( V_33 , V_337 , V_34 , V_281 ) ;
if ( ! V_27 ) {
F_266 ( V_337 , V_34 , 0 ) ;
return 0 ;
}
return V_27 ;
}
int F_278 ( struct V_32 * V_33 ,
struct V_320 * V_337 ,
T_2 V_371 )
{
return F_277 ( V_33 , V_337 , V_371 , 1 ) ;
}
int F_279 ( struct V_32 * V_33 ,
struct V_320 * V_337 ,
T_2 V_371 )
{
return F_277 ( V_33 , V_337 , V_371 , 0 ) ;
}
int F_280 ( struct V_320 * V_372 ,
struct V_320 * V_373 ,
T_2 V_34 )
{
return F_268 ( V_372 , V_373 , V_34 ) ;
}
void F_272 ( struct V_32 * V_33 ,
struct V_320 * V_337 ,
T_2 V_34 )
{
struct V_320 * V_321 = & V_33 -> V_35 -> V_322 ;
if ( V_321 -> V_102 || V_321 == V_337 ||
V_337 -> V_99 != V_321 -> V_99 )
V_321 = NULL ;
F_267 ( V_33 -> V_35 , V_337 , V_321 ,
V_34 ) ;
}
static T_2 F_281 ( struct V_11 * V_35 )
{
struct V_96 * V_317 ;
T_2 V_34 ;
T_2 V_374 ;
T_2 V_375 ;
int V_376 = F_282 ( V_35 -> V_326 ) ;
V_317 = F_66 ( V_35 , V_284 ) ;
F_11 ( & V_317 -> V_49 ) ;
V_375 = V_317 -> V_266 ;
F_13 ( & V_317 -> V_49 ) ;
V_317 = F_66 ( V_35 , V_114 ) ;
F_11 ( & V_317 -> V_49 ) ;
if ( V_317 -> V_6 & V_284 )
V_375 = 0 ;
V_374 = V_317 -> V_266 ;
F_13 ( & V_317 -> V_49 ) ;
V_34 = ( V_375 >> V_35 -> V_349 -> V_377 ) *
V_376 * 2 ;
V_34 += F_221 ( V_375 + V_374 , 50 ) ;
if ( V_34 * 3 > V_374 )
V_34 = F_221 ( V_374 , 3 ) ;
return F_283 ( V_34 , V_35 -> V_60 -> V_378 << 10 ) ;
}
static void F_284 ( struct V_11 * V_35 )
{
struct V_320 * V_337 = & V_35 -> V_322 ;
struct V_96 * V_317 = V_337 -> V_99 ;
T_2 V_34 ;
V_34 = F_281 ( V_35 ) ;
F_11 ( & V_317 -> V_49 ) ;
F_11 ( & V_337 -> V_49 ) ;
V_337 -> V_54 = V_34 ;
V_34 = V_317 -> V_266 + V_317 -> V_275 +
V_317 -> V_276 + V_317 -> V_277 +
V_317 -> V_278 ;
if ( V_317 -> V_265 > V_34 ) {
V_34 = V_317 -> V_265 - V_34 ;
V_337 -> V_9 += V_34 ;
V_317 -> V_278 += V_34 ;
F_244 ( V_35 , L_5 ,
V_317 -> V_6 , V_34 , 1 ) ;
}
if ( V_337 -> V_9 >= V_337 -> V_54 ) {
V_34 = V_337 -> V_9 - V_337 -> V_54 ;
V_317 -> V_278 -= V_34 ;
F_244 ( V_35 , L_5 ,
V_317 -> V_6 , V_34 , 0 ) ;
V_317 -> V_347 ++ ;
V_337 -> V_9 = V_337 -> V_54 ;
V_337 -> V_102 = 1 ;
}
F_13 ( & V_337 -> V_49 ) ;
F_13 ( & V_317 -> V_49 ) ;
}
static void F_285 ( struct V_11 * V_35 )
{
struct V_96 * V_99 ;
V_99 = F_66 ( V_35 , V_287 ) ;
V_35 -> V_379 . V_99 = V_99 ;
V_99 = F_66 ( V_35 , V_114 ) ;
V_35 -> V_322 . V_99 = V_99 ;
V_35 -> V_346 . V_99 = V_99 ;
V_35 -> V_380 . V_99 = V_99 ;
V_35 -> V_363 . V_99 = V_99 ;
V_35 -> V_353 . V_99 = V_99 ;
V_35 -> V_60 -> V_337 = & V_35 -> V_322 ;
V_35 -> V_362 -> V_337 = & V_35 -> V_322 ;
V_35 -> V_381 -> V_337 = & V_35 -> V_322 ;
V_35 -> V_230 -> V_337 = & V_35 -> V_322 ;
V_35 -> V_303 -> V_337 = & V_35 -> V_379 ;
F_284 ( V_35 ) ;
}
static void F_286 ( struct V_11 * V_35 )
{
F_267 ( V_35 , & V_35 -> V_322 , NULL ,
( T_2 ) - 1 ) ;
F_8 ( V_35 -> V_346 . V_54 > 0 ) ;
F_8 ( V_35 -> V_346 . V_9 > 0 ) ;
F_8 ( V_35 -> V_380 . V_54 > 0 ) ;
F_8 ( V_35 -> V_380 . V_9 > 0 ) ;
F_8 ( V_35 -> V_379 . V_54 > 0 ) ;
F_8 ( V_35 -> V_379 . V_9 > 0 ) ;
F_8 ( V_35 -> V_353 . V_54 > 0 ) ;
F_8 ( V_35 -> V_353 . V_9 > 0 ) ;
}
void F_287 ( struct V_82 * V_83 ,
struct V_32 * V_33 )
{
if ( ! V_83 -> V_276 )
return;
F_244 ( V_33 -> V_35 , L_7 ,
V_83 -> V_256 , V_83 -> V_276 , 0 ) ;
F_272 ( V_33 , V_83 -> V_337 , V_83 -> V_276 ) ;
V_83 -> V_276 = 0 ;
}
int F_288 ( struct V_82 * V_83 ,
struct V_247 * V_247 )
{
struct V_32 * V_33 = F_218 ( V_247 ) -> V_33 ;
struct V_320 * V_372 = F_264 ( V_83 , V_33 ) ;
struct V_320 * V_373 = V_33 -> V_382 ;
T_2 V_34 = F_249 ( V_33 , 1 ) ;
F_244 ( V_33 -> V_35 , L_8 ,
F_289 ( V_247 ) , V_34 , 1 ) ;
return F_268 ( V_372 , V_373 , V_34 ) ;
}
void F_290 ( struct V_247 * V_247 )
{
struct V_32 * V_33 = F_218 ( V_247 ) -> V_33 ;
T_2 V_34 = F_249 ( V_33 , 1 ) ;
F_244 ( V_33 -> V_35 , L_8 ,
F_289 ( V_247 ) , V_34 , 0 ) ;
F_272 ( V_33 , V_33 -> V_382 , V_34 ) ;
}
int F_291 ( struct V_82 * V_83 ,
struct V_383 * V_384 )
{
struct V_32 * V_33 = V_384 -> V_33 ;
struct V_320 * V_372 = F_264 ( V_83 , V_33 ) ;
struct V_320 * V_373 = & V_384 -> V_337 ;
T_2 V_34 = F_249 ( V_33 , 5 ) ;
V_373 -> V_99 = V_372 -> V_99 ;
return F_268 ( V_372 , V_373 , V_34 ) ;
}
static unsigned F_292 ( struct V_247 * V_247 )
{
unsigned V_385 = 0 ;
unsigned V_386 = 0 ;
F_22 ( ! F_218 ( V_247 ) -> V_387 ) ;
F_218 ( V_247 ) -> V_387 -- ;
if ( F_218 ( V_247 ) -> V_387 == 0 &&
F_218 ( V_247 ) -> V_388 ) {
V_385 = 1 ;
F_218 ( V_247 ) -> V_388 = 0 ;
}
if ( F_218 ( V_247 ) -> V_387 >=
F_218 ( V_247 ) -> V_389 )
return V_385 ;
V_386 = F_218 ( V_247 ) -> V_389 -
F_218 ( V_247 ) -> V_387 ;
F_218 ( V_247 ) -> V_389 -= V_386 ;
return V_386 + V_385 ;
}
static T_2 F_293 ( struct V_247 * V_247 , T_2 V_34 ,
int V_390 )
{
struct V_32 * V_33 = F_218 ( V_247 ) -> V_33 ;
T_2 V_376 ;
int V_391 ;
int V_392 ;
int V_393 ;
if ( F_218 ( V_247 ) -> V_6 & V_394 &&
F_218 ( V_247 ) -> V_395 == 0 )
return 0 ;
V_393 = ( int ) F_221 ( F_218 ( V_247 ) -> V_395 , V_33 -> V_308 ) ;
if ( V_390 )
F_218 ( V_247 ) -> V_395 += V_34 ;
else
F_218 ( V_247 ) -> V_395 -= V_34 ;
V_376 = F_294 ( V_33 ) - sizeof( struct V_396 ) ;
V_391 = ( int ) F_221 ( V_376 ,
sizeof( struct V_397 ) +
sizeof( struct V_398 ) ) ;
V_392 = ( int ) F_221 ( F_218 ( V_247 ) -> V_395 , V_33 -> V_308 ) ;
V_392 = V_392 + V_391 - 1 ;
V_392 = V_392 / V_391 ;
V_393 = V_393 + V_391 - 1 ;
V_393 = V_393 / V_391 ;
if ( V_393 == V_392 )
return 0 ;
if ( V_390 )
return F_249 ( V_33 ,
V_392 - V_393 ) ;
return F_249 ( V_33 , V_393 - V_392 ) ;
}
int F_295 ( struct V_247 * V_247 , T_2 V_34 )
{
struct V_32 * V_33 = F_218 ( V_247 ) -> V_33 ;
struct V_320 * V_337 = & V_33 -> V_35 -> V_346 ;
T_2 V_399 = 0 ;
T_2 V_395 ;
unsigned V_400 = 0 ;
int V_401 = 0 ;
int V_281 = 1 ;
int V_27 ;
if ( F_296 ( V_33 , V_247 ) )
V_281 = 0 ;
if ( V_281 && F_297 ( V_33 -> V_35 ) )
F_185 ( 1 ) ;
F_34 ( & F_218 ( V_247 ) -> V_402 ) ;
V_34 = F_283 ( V_34 , V_33 -> V_308 ) ;
F_11 ( & F_218 ( V_247 ) -> V_49 ) ;
F_218 ( V_247 ) -> V_387 ++ ;
if ( F_218 ( V_247 ) -> V_387 >
F_218 ( V_247 ) -> V_389 )
V_400 = F_218 ( V_247 ) -> V_387 -
F_218 ( V_247 ) -> V_389 ;
if ( ! F_218 ( V_247 ) -> V_388 ) {
V_400 ++ ;
V_401 = 1 ;
}
V_399 = F_249 ( V_33 , V_400 ) ;
V_399 += F_293 ( V_247 , V_34 , 1 ) ;
V_395 = F_218 ( V_247 ) -> V_395 ;
F_13 ( & F_218 ( V_247 ) -> V_49 ) ;
V_27 = F_261 ( V_33 , V_337 , V_399 , V_281 ) ;
if ( V_27 ) {
T_2 V_403 = 0 ;
unsigned V_404 ;
F_11 ( & F_218 ( V_247 ) -> V_49 ) ;
V_404 = F_292 ( V_247 ) ;
if ( F_218 ( V_247 ) -> V_395 == V_395 )
F_293 ( V_247 , V_34 , 0 ) ;
else
V_403 = F_293 ( V_247 , V_34 , 0 ) ;
F_13 ( & F_218 ( V_247 ) -> V_49 ) ;
if ( V_404 )
V_403 += F_249 ( V_33 , V_404 ) ;
if ( V_403 ) {
F_272 ( V_33 , V_337 , V_403 ) ;
F_244 ( V_33 -> V_35 ,
L_9 ,
F_289 ( V_247 ) ,
V_403 , 0 ) ;
}
F_45 ( & F_218 ( V_247 ) -> V_402 ) ;
return V_27 ;
}
F_11 ( & F_218 ( V_247 ) -> V_49 ) ;
if ( V_401 ) {
F_218 ( V_247 ) -> V_388 = 1 ;
V_400 -- ;
}
F_218 ( V_247 ) -> V_389 += V_400 ;
F_13 ( & F_218 ( V_247 ) -> V_49 ) ;
F_45 ( & F_218 ( V_247 ) -> V_402 ) ;
if ( V_399 )
F_244 ( V_33 -> V_35 , L_9 ,
F_289 ( V_247 ) , V_399 , 1 ) ;
F_266 ( V_337 , V_399 , 1 ) ;
return 0 ;
}
void F_298 ( struct V_247 * V_247 , T_2 V_34 )
{
struct V_32 * V_33 = F_218 ( V_247 ) -> V_33 ;
T_2 V_403 = 0 ;
unsigned V_404 ;
V_34 = F_283 ( V_34 , V_33 -> V_308 ) ;
F_11 ( & F_218 ( V_247 ) -> V_49 ) ;
V_404 = F_292 ( V_247 ) ;
V_403 = F_293 ( V_247 , V_34 , 0 ) ;
F_13 ( & F_218 ( V_247 ) -> V_49 ) ;
if ( V_404 > 0 )
V_403 += F_249 ( V_33 , V_404 ) ;
F_244 ( V_33 -> V_35 , L_9 ,
F_289 ( V_247 ) , V_403 , 0 ) ;
F_272 ( V_33 , & V_33 -> V_35 -> V_346 ,
V_403 ) ;
}
int F_299 ( struct V_247 * V_247 , T_2 V_34 )
{
int V_27 ;
V_27 = F_222 ( V_247 , V_34 ) ;
if ( V_27 )
return V_27 ;
V_27 = F_295 ( V_247 , V_34 ) ;
if ( V_27 ) {
F_224 ( V_247 , V_34 ) ;
return V_27 ;
}
return 0 ;
}
void F_300 ( struct V_247 * V_247 , T_2 V_34 )
{
F_298 ( V_247 , V_34 ) ;
F_224 ( V_247 , V_34 ) ;
}
static int F_301 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
T_2 V_25 , T_2 V_34 , int V_311 )
{
struct V_1 * V_2 = NULL ;
struct V_11 * V_12 = V_33 -> V_35 ;
T_2 V_405 = V_34 ;
T_2 V_406 ;
T_2 V_407 ;
int V_104 ;
F_11 ( & V_12 -> V_408 ) ;
V_406 = F_302 ( V_12 -> V_326 ) ;
if ( V_311 )
V_406 += V_34 ;
else
V_406 -= V_34 ;
F_303 ( V_12 -> V_326 , V_406 ) ;
F_13 ( & V_12 -> V_408 ) ;
while ( V_405 ) {
V_2 = F_65 ( V_12 , V_25 ) ;
if ( ! V_2 )
return - V_153 ;
if ( V_2 -> V_6 & ( V_267 |
V_268 |
V_269 ) )
V_104 = 2 ;
else
V_104 = 1 ;
if ( ! V_311 && V_2 -> V_3 == V_90 )
F_49 ( V_2 , V_83 , NULL , 1 ) ;
V_407 = V_25 - V_2 -> V_20 . V_21 ;
F_8 ( V_407 > V_2 -> V_20 . V_31 ) ;
F_11 ( & V_2 -> V_99 -> V_49 ) ;
F_11 ( & V_2 -> V_49 ) ;
if ( F_251 ( V_33 , V_409 ) &&
V_2 -> V_253 < V_261 )
V_2 -> V_253 = V_261 ;
V_2 -> V_262 = 1 ;
V_406 = F_76 ( & V_2 -> V_112 ) ;
V_34 = F_257 ( V_405 , V_2 -> V_20 . V_31 - V_407 ) ;
if ( V_311 ) {
V_406 += V_34 ;
F_304 ( & V_2 -> V_112 , V_406 ) ;
V_2 -> V_9 -= V_34 ;
V_2 -> V_99 -> V_276 -= V_34 ;
V_2 -> V_99 -> V_266 += V_34 ;
V_2 -> V_99 -> V_271 += V_34 * V_104 ;
F_13 ( & V_2 -> V_49 ) ;
F_13 ( & V_2 -> V_99 -> V_49 ) ;
} else {
V_406 -= V_34 ;
F_304 ( & V_2 -> V_112 , V_406 ) ;
V_2 -> V_8 += V_34 ;
V_2 -> V_99 -> V_275 += V_34 ;
V_2 -> V_99 -> V_266 -= V_34 ;
V_2 -> V_99 -> V_271 -= V_34 * V_104 ;
F_13 ( & V_2 -> V_49 ) ;
F_13 ( & V_2 -> V_99 -> V_49 ) ;
F_305 ( V_12 -> V_56 ,
V_25 , V_25 + V_34 - 1 ,
V_38 | V_410 ) ;
}
F_6 ( V_2 ) ;
V_405 -= V_34 ;
V_25 += V_34 ;
}
return 0 ;
}
static T_2 F_306 ( struct V_32 * V_33 , T_2 V_105 )
{
struct V_1 * V_2 ;
T_2 V_25 ;
V_2 = F_64 ( V_33 -> V_35 , V_105 ) ;
if ( ! V_2 )
return 0 ;
V_25 = V_2 -> V_20 . V_21 ;
F_6 ( V_2 ) ;
return V_25 ;
}
static int F_307 ( struct V_32 * V_33 ,
struct V_1 * V_2 ,
T_2 V_25 , T_2 V_34 , int V_9 )
{
F_11 ( & V_2 -> V_99 -> V_49 ) ;
F_11 ( & V_2 -> V_49 ) ;
V_2 -> V_8 += V_34 ;
V_2 -> V_99 -> V_275 += V_34 ;
if ( V_9 ) {
V_2 -> V_9 -= V_34 ;
V_2 -> V_99 -> V_276 -= V_34 ;
}
F_13 ( & V_2 -> V_49 ) ;
F_13 ( & V_2 -> V_99 -> V_49 ) ;
F_305 ( V_33 -> V_35 -> V_56 , V_25 ,
V_25 + V_34 - 1 , V_38 | V_410 ) ;
return 0 ;
}
int F_164 ( struct V_32 * V_33 ,
T_2 V_25 , T_2 V_34 , int V_9 )
{
struct V_1 * V_2 ;
V_2 = F_65 ( V_33 -> V_35 , V_25 ) ;
F_22 ( ! V_2 ) ;
F_307 ( V_33 , V_2 , V_25 , V_34 , V_9 ) ;
F_6 ( V_2 ) ;
return 0 ;
}
int F_308 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
T_2 V_25 , T_2 V_34 )
{
struct V_1 * V_2 ;
V_2 = F_65 ( V_33 -> V_35 , V_25 ) ;
F_22 ( ! V_2 ) ;
F_49 ( V_2 , V_83 , V_33 , 1 ) ;
F_307 ( V_33 , V_2 , V_25 , V_34 , 0 ) ;
F_309 ( V_2 , V_25 , V_34 ) ;
F_6 ( V_2 ) ;
return 0 ;
}
static int F_310 ( struct V_1 * V_2 ,
T_2 V_34 , int V_390 )
{
struct V_96 * V_99 = V_2 -> V_99 ;
int V_27 = 0 ;
F_11 ( & V_99 -> V_49 ) ;
F_11 ( & V_2 -> V_49 ) ;
if ( V_390 != V_411 ) {
if ( V_2 -> V_113 ) {
V_27 = - V_175 ;
} else {
V_2 -> V_9 += V_34 ;
V_99 -> V_276 += V_34 ;
if ( V_390 == V_412 ) {
F_244 ( V_2 -> V_35 ,
L_5 , V_99 -> V_6 ,
V_34 , 0 ) ;
V_99 -> V_278 -= V_34 ;
}
}
} else {
if ( V_2 -> V_113 )
V_99 -> V_277 += V_34 ;
V_2 -> V_9 -= V_34 ;
V_99 -> V_276 -= V_34 ;
V_99 -> V_347 ++ ;
}
F_13 ( & V_2 -> V_49 ) ;
F_13 ( & V_99 -> V_49 ) ;
return V_27 ;
}
void F_311 ( struct V_82 * V_83 ,
struct V_32 * V_33 )
{
struct V_11 * V_35 = V_33 -> V_35 ;
struct V_47 * V_216 ;
struct V_47 * V_51 ;
struct V_1 * V_2 ;
F_60 ( & V_35 -> V_76 ) ;
F_312 (caching_ctl, next,
&fs_info->caching_block_groups, list) {
V_2 = V_51 -> V_13 ;
if ( F_1 ( V_2 ) ) {
V_2 -> V_93 = ( T_2 ) - 1 ;
F_172 ( & V_51 -> V_86 ) ;
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
F_284 ( V_35 ) ;
}
static int F_313 ( struct V_32 * V_33 , T_2 V_30 , T_2 V_29 )
{
struct V_11 * V_35 = V_33 -> V_35 ;
struct V_1 * V_2 = NULL ;
T_2 V_115 ;
while ( V_30 <= V_29 ) {
if ( ! V_2 ||
V_30 >= V_2 -> V_20 . V_21 + V_2 -> V_20 . V_31 ) {
if ( V_2 )
F_6 ( V_2 ) ;
V_2 = F_65 ( V_35 , V_30 ) ;
F_22 ( ! V_2 ) ;
}
V_115 = V_2 -> V_20 . V_21 + V_2 -> V_20 . V_31 - V_30 ;
V_115 = F_257 ( V_115 , V_29 + 1 - V_30 ) ;
if ( V_30 < V_2 -> V_93 ) {
V_115 = F_257 ( V_115 , V_2 -> V_93 - V_30 ) ;
F_29 ( V_2 , V_30 , V_115 ) ;
}
V_30 += V_115 ;
F_11 ( & V_2 -> V_99 -> V_49 ) ;
F_11 ( & V_2 -> V_49 ) ;
V_2 -> V_8 -= V_115 ;
V_2 -> V_99 -> V_275 -= V_115 ;
if ( V_2 -> V_113 )
V_2 -> V_99 -> V_277 += V_115 ;
F_13 ( & V_2 -> V_49 ) ;
F_13 ( & V_2 -> V_99 -> V_49 ) ;
}
if ( V_2 )
F_6 ( V_2 ) ;
return 0 ;
}
int F_314 ( struct V_82 * V_83 ,
struct V_32 * V_33 )
{
struct V_11 * V_35 = V_33 -> V_35 ;
struct V_413 * V_414 ;
T_2 V_30 ;
T_2 V_29 ;
int V_27 ;
if ( V_83 -> V_210 )
return 0 ;
if ( V_35 -> V_56 == & V_35 -> V_36 [ 0 ] )
V_414 = & V_35 -> V_36 [ 1 ] ;
else
V_414 = & V_35 -> V_36 [ 0 ] ;
while ( 1 ) {
V_27 = F_28 ( V_414 , 0 , & V_30 , & V_29 ,
V_57 ) ;
if ( V_27 )
break;
if ( F_251 ( V_33 , V_415 ) )
V_27 = F_145 ( V_33 , V_30 ,
V_29 + 1 - V_30 , NULL ) ;
F_315 ( V_414 , V_30 , V_29 , V_38 ) ;
F_313 ( V_33 , V_30 , V_29 ) ;
F_46 () ;
}
return 0 ;
}
static int F_155 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
T_2 V_25 , T_2 V_34 , T_2 V_16 ,
T_2 V_146 , T_2 V_416 ,
T_2 V_417 , int V_159 ,
struct V_177 * V_131 )
{
struct V_65 V_20 ;
struct V_61 * V_62 ;
struct V_11 * V_12 = V_33 -> V_35 ;
struct V_32 * V_60 = V_12 -> V_60 ;
struct V_63 * V_64 ;
struct V_120 * V_121 ;
struct V_162 * V_163 ;
int V_27 ;
int V_181 ;
int V_418 = 0 ;
int V_419 = 0 ;
int V_420 = 1 ;
T_3 V_122 ;
T_2 V_116 ;
V_62 = F_32 () ;
if ( ! V_62 )
return - V_85 ;
V_62 -> V_72 = 1 ;
V_62 -> V_201 = 1 ;
V_181 = V_416 >= V_143 ;
F_22 ( ! V_181 && V_159 != 1 ) ;
V_27 = F_137 ( V_83 , V_60 , V_62 , & V_163 ,
V_25 , V_34 , V_16 ,
V_146 , V_416 ,
V_417 ) ;
if ( V_27 == 0 ) {
V_418 = V_62 -> V_79 [ 0 ] ;
while ( V_418 >= 0 ) {
F_39 ( V_62 -> V_78 [ 0 ] , & V_20 ,
V_418 ) ;
if ( V_20 . V_21 != V_25 )
break;
if ( V_20 . type == V_73 &&
V_20 . V_31 == V_34 ) {
V_419 = 1 ;
break;
}
if ( V_62 -> V_79 [ 0 ] - V_418 > 5 )
break;
V_418 -- ;
}
#ifdef F_84
V_122 = F_80 ( V_62 -> V_78 [ 0 ] , V_418 ) ;
if ( V_419 && V_122 < sizeof( * V_121 ) )
V_419 = 0 ;
#endif
if ( ! V_419 ) {
F_22 ( V_163 ) ;
V_27 = F_142 ( V_83 , V_60 , V_62 ,
NULL , V_159 ,
V_181 ) ;
if ( V_27 )
goto abort;
F_43 ( V_62 ) ;
V_62 -> V_201 = 1 ;
V_20 . V_21 = V_25 ;
V_20 . type = V_73 ;
V_20 . V_31 = V_34 ;
V_27 = F_36 ( V_83 , V_60 ,
& V_20 , V_62 , - 1 , 1 ) ;
if ( V_27 ) {
F_173 ( V_421 L_10
L_11 , V_27 ,
( unsigned long long ) V_25 ) ;
if ( V_27 > 0 )
F_316 ( V_60 ,
V_62 -> V_78 [ 0 ] ) ;
}
if ( V_27 < 0 )
goto abort;
V_418 = V_62 -> V_79 [ 0 ] ;
}
} else if ( V_27 == - V_153 ) {
F_316 ( V_60 , V_62 -> V_78 [ 0 ] ) ;
F_8 ( 1 ) ;
F_173 ( V_421 L_12
L_13 ,
( unsigned long long ) V_25 ,
( unsigned long long ) V_16 ,
( unsigned long long ) V_146 ,
( unsigned long long ) V_416 ,
( unsigned long long ) V_417 ) ;
} else {
goto abort;
}
V_64 = V_62 -> V_78 [ 0 ] ;
V_122 = F_80 ( V_64 , V_418 ) ;
#ifdef F_84
if ( V_122 < sizeof( * V_121 ) ) {
F_22 ( V_419 || V_418 != V_62 -> V_79 [ 0 ] ) ;
V_27 = F_90 ( V_83 , V_60 , V_62 ,
V_416 , 0 ) ;
if ( V_27 < 0 )
goto abort;
F_43 ( V_62 ) ;
V_62 -> V_201 = 1 ;
V_20 . V_21 = V_25 ;
V_20 . type = V_73 ;
V_20 . V_31 = V_34 ;
V_27 = F_36 ( V_83 , V_60 , & V_20 , V_62 ,
- 1 , 1 ) ;
if ( V_27 ) {
F_173 ( V_421 L_10
L_11 , V_27 ,
( unsigned long long ) V_25 ) ;
F_316 ( V_60 , V_62 -> V_78 [ 0 ] ) ;
}
if ( V_27 < 0 )
goto abort;
V_418 = V_62 -> V_79 [ 0 ] ;
V_64 = V_62 -> V_78 [ 0 ] ;
V_122 = F_80 ( V_64 , V_418 ) ;
}
#endif
F_22 ( V_122 < sizeof( * V_121 ) ) ;
V_121 = F_81 ( V_64 , V_418 ,
struct V_120 ) ;
if ( V_416 < V_143 ) {
struct V_138 * V_139 ;
F_22 ( V_122 < sizeof( * V_121 ) + sizeof( * V_139 ) ) ;
V_139 = (struct V_138 * ) ( V_121 + 1 ) ;
F_8 ( V_416 != F_317 ( V_64 , V_139 ) ) ;
}
V_116 = F_82 ( V_64 , V_121 ) ;
F_22 ( V_116 < V_159 ) ;
V_116 -= V_159 ;
if ( V_116 > 0 ) {
if ( V_131 )
F_133 ( V_131 , V_64 , V_121 ) ;
if ( V_163 ) {
F_22 ( ! V_419 ) ;
} else {
F_93 ( V_64 , V_121 , V_116 ) ;
F_98 ( V_64 ) ;
}
if ( V_419 ) {
V_27 = F_142 ( V_83 , V_60 , V_62 ,
V_163 , V_159 ,
V_181 ) ;
if ( V_27 )
goto abort;
}
} else {
if ( V_419 ) {
F_22 ( V_181 && V_159 !=
F_121 ( V_33 , V_62 , V_163 ) ) ;
if ( V_163 ) {
F_22 ( V_62 -> V_79 [ 0 ] != V_418 ) ;
} else {
F_22 ( V_62 -> V_79 [ 0 ] != V_418 + 1 ) ;
V_62 -> V_79 [ 0 ] = V_418 ;
V_420 = 2 ;
}
}
V_27 = F_318 ( V_83 , V_60 , V_62 , V_62 -> V_79 [ 0 ] ,
V_420 ) ;
if ( V_27 )
goto abort;
F_43 ( V_62 ) ;
if ( V_181 ) {
V_27 = F_165 ( V_83 , V_33 , V_25 , V_34 ) ;
if ( V_27 )
goto abort;
}
V_27 = F_301 ( V_83 , V_33 , V_25 , V_34 , 0 ) ;
if ( V_27 )
goto abort;
}
V_69:
F_48 ( V_62 ) ;
return V_27 ;
abort:
F_151 ( V_83 , V_60 , V_27 ) ;
goto V_69;
}
static T_1 int F_319 ( struct V_82 * V_83 ,
struct V_32 * V_33 , T_2 V_25 )
{
struct V_117 * V_98 ;
struct V_118 * V_119 ;
struct V_202 * V_151 ;
struct V_14 * V_130 ;
int V_27 = 0 ;
V_119 = & V_83 -> V_129 -> V_119 ;
F_11 ( & V_119 -> V_49 ) ;
V_98 = F_87 ( V_83 , V_25 ) ;
if ( ! V_98 )
goto V_69;
V_130 = F_190 ( & V_98 -> V_130 . V_14 ) ;
if ( ! V_130 )
goto V_69;
V_151 = F_12 ( V_130 , struct V_202 , V_14 ) ;
if ( V_151 -> V_25 == V_25 )
goto V_69;
if ( V_98 -> V_131 ) {
if ( ! V_98 -> V_215 )
goto V_69;
F_9 ( V_98 -> V_131 ) ;
V_98 -> V_131 = NULL ;
}
if ( ! F_88 ( & V_98 -> V_75 ) )
goto V_69;
V_98 -> V_130 . V_220 = 0 ;
F_174 ( & V_98 -> V_130 . V_14 , & V_119 -> V_33 ) ;
V_119 -> V_221 -- ;
if ( F_320 ( & V_119 -> V_225 ) )
F_47 ( & V_119 -> V_225 ) ;
V_119 -> V_422 -- ;
if ( F_167 ( & V_98 -> V_213 ) )
V_119 -> V_218 -- ;
F_172 ( & V_98 -> V_213 ) ;
F_13 ( & V_119 -> V_49 ) ;
F_22 ( V_98 -> V_131 ) ;
if ( V_98 -> V_215 )
V_27 = 1 ;
F_45 ( & V_98 -> V_75 ) ;
F_89 ( & V_98 -> V_130 ) ;
return V_27 ;
V_69:
F_13 ( & V_119 -> V_49 ) ;
return 0 ;
}
void F_321 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_63 * V_238 ,
T_2 V_16 , int V_423 , int V_198 )
{
struct V_1 * V_2 = NULL ;
int V_27 ;
if ( V_33 -> V_234 . V_21 != V_199 ) {
V_27 = F_148 ( V_33 -> V_35 , V_83 ,
V_238 -> V_30 , V_238 -> V_115 ,
V_16 , V_33 -> V_234 . V_21 ,
F_198 ( V_238 ) ,
V_209 , NULL , V_198 ) ;
F_22 ( V_27 ) ;
}
if ( ! V_423 )
return;
V_2 = F_65 ( V_33 -> V_35 , V_238 -> V_30 ) ;
if ( F_322 ( V_238 ) == V_83 -> V_256 ) {
if ( V_33 -> V_234 . V_21 != V_199 ) {
V_27 = F_319 ( V_83 , V_33 , V_238 -> V_30 ) ;
if ( ! V_27 )
goto V_69;
}
if ( F_323 ( V_238 , V_424 ) ) {
F_307 ( V_33 , V_2 , V_238 -> V_30 , V_238 -> V_115 , 1 ) ;
goto V_69;
}
F_8 ( F_324 ( V_425 , & V_238 -> V_426 ) ) ;
F_29 ( V_2 , V_238 -> V_30 , V_238 -> V_115 ) ;
F_310 ( V_2 , V_238 -> V_115 , V_411 ) ;
}
V_69:
F_325 ( V_427 , & V_238 -> V_426 ) ;
F_6 ( V_2 ) ;
}
int V_244 ( struct V_82 * V_83 , struct V_32 * V_33 ,
T_2 V_25 , T_2 V_34 , T_2 V_16 , T_2 V_146 ,
T_2 V_107 , T_2 V_31 , int V_198 )
{
int V_27 ;
struct V_11 * V_35 = V_33 -> V_35 ;
if ( V_146 == V_199 ) {
F_8 ( V_107 >= V_143 ) ;
F_164 ( V_33 , V_25 , V_34 , 1 ) ;
V_27 = 0 ;
} else if ( V_107 < V_143 ) {
V_27 = F_148 ( V_35 , V_83 , V_25 ,
V_34 ,
V_16 , V_146 , ( int ) V_107 ,
V_209 , NULL , V_198 ) ;
} else {
V_27 = F_149 ( V_35 , V_83 , V_25 ,
V_34 ,
V_16 , V_146 , V_107 ,
V_31 , V_209 ,
NULL , V_198 ) ;
}
return V_27 ;
}
static T_2 F_326 ( struct V_32 * V_33 , T_2 V_428 )
{
T_2 V_429 = ( ( T_2 ) V_33 -> V_430 - 1 ) ;
T_2 V_27 = ( V_428 + V_429 ) & ~ V_429 ;
return V_27 ;
}
static T_1 int
F_327 ( struct V_1 * V_2 ,
T_2 V_34 )
{
struct V_47 * V_51 ;
F_50 ( V_81 ) ;
V_51 = F_25 ( V_2 ) ;
if ( ! V_51 )
return 0 ;
F_179 ( V_51 -> V_81 , F_1 ( V_2 ) ||
( V_2 -> V_10 -> V_431 >= V_34 ) ) ;
F_26 ( V_51 ) ;
return 0 ;
}
static T_1 int
F_328 ( struct V_1 * V_2 )
{
struct V_47 * V_51 ;
F_50 ( V_81 ) ;
V_51 = F_25 ( V_2 ) ;
if ( ! V_51 )
return 0 ;
F_179 ( V_51 -> V_81 , F_1 ( V_2 ) ) ;
F_26 ( V_51 ) ;
return 0 ;
}
static int F_329 ( T_2 V_6 )
{
int V_432 ;
if ( V_6 & V_269 )
V_432 = 0 ;
else if ( V_6 & V_268 )
V_432 = 1 ;
else if ( V_6 & V_267 )
V_432 = 2 ;
else if ( V_6 & V_302 )
V_432 = 3 ;
else
V_432 = 4 ;
return V_432 ;
}
static int F_330 ( struct V_1 * V_2 )
{
return F_329 ( V_2 -> V_6 ) ;
}
static T_1 int F_331 ( struct V_82 * V_83 ,
struct V_32 * V_433 ,
T_2 V_34 , T_2 V_434 ,
T_2 V_435 , struct V_65 * V_205 ,
T_2 V_293 )
{
int V_27 = 0 ;
struct V_32 * V_33 = V_433 -> V_35 -> V_60 ;
struct V_436 * V_437 = NULL ;
struct V_1 * V_13 = NULL ;
struct V_1 * V_438 ;
T_2 V_105 = 0 ;
int V_439 = 2 * 1024 * 1024 ;
int V_440 = 0 ;
int V_441 = 0 ;
struct V_96 * V_99 ;
int V_442 = 0 ;
int V_432 = 0 ;
int V_443 = ( V_293 & V_284 ) ?
V_444 : V_412 ;
bool V_445 = false ;
bool V_446 = false ;
bool V_447 = false ;
bool V_448 = true ;
bool V_449 = false ;
F_8 ( V_34 < V_33 -> V_308 ) ;
F_78 ( V_205 , V_73 ) ;
V_205 -> V_21 = 0 ;
V_205 -> V_31 = 0 ;
F_332 ( V_433 , V_34 , V_434 , V_293 ) ;
V_99 = F_66 ( V_33 -> V_35 , V_293 ) ;
if ( ! V_99 ) {
F_173 ( V_421 L_14 , V_293 ) ;
return - V_314 ;
}
if ( F_254 ( V_99 ) )
V_448 = false ;
if ( V_433 -> V_243 || V_434 )
V_440 = 1 ;
if ( V_293 & V_114 && V_448 ) {
V_437 = & V_33 -> V_35 -> V_450 ;
if ( ! F_251 ( V_33 , V_451 ) )
V_439 = 64 * 1024 ;
}
if ( ( V_293 & V_284 ) && V_448 &&
F_251 ( V_33 , V_451 ) ) {
V_437 = & V_33 -> V_35 -> V_452 ;
}
if ( V_437 ) {
F_11 ( & V_437 -> V_49 ) ;
if ( V_437 -> V_13 )
V_435 = V_437 -> V_453 ;
F_13 ( & V_437 -> V_49 ) ;
}
V_105 = F_75 ( V_105 , F_306 ( V_33 , 0 ) ) ;
V_105 = F_75 ( V_105 , V_435 ) ;
if ( ! V_437 )
V_439 = 0 ;
if ( V_105 == V_435 ) {
V_13 = F_65 ( V_33 -> V_35 ,
V_105 ) ;
V_438 = V_13 ;
if ( V_13 && F_3 ( V_13 , V_293 ) &&
V_13 -> V_3 != V_90 ) {
F_35 ( & V_99 -> V_274 ) ;
if ( F_167 ( & V_13 -> V_86 ) ||
V_13 -> V_113 ) {
F_6 ( V_13 ) ;
F_44 ( & V_99 -> V_274 ) ;
} else {
V_432 = F_330 ( V_13 ) ;
goto V_454;
}
} else if ( V_13 ) {
F_6 ( V_13 ) ;
}
}
V_455:
V_449 = false ;
F_35 ( & V_99 -> V_274 ) ;
F_333 (block_group, &space_info->block_groups[index],
list) {
T_2 V_31 ;
int V_3 ;
V_438 = V_13 ;
F_4 ( V_13 ) ;
V_105 = V_13 -> V_20 . V_21 ;
if ( ! F_3 ( V_13 , V_293 ) ) {
T_2 V_456 = V_267 |
V_268 |
V_269 ;
if ( ( V_293 & V_456 ) && ! ( V_13 -> V_6 & V_456 ) )
goto V_442;
}
V_454:
V_3 = F_1 ( V_13 ) ;
if ( F_334 ( ! V_3 ) ) {
V_445 = true ;
V_27 = F_49 ( V_13 , V_83 ,
V_433 , 0 ) ;
F_22 ( V_27 < 0 ) ;
V_27 = 0 ;
}
if ( F_334 ( V_13 -> V_113 ) )
goto V_442;
if ( V_437 ) {
F_11 ( & V_437 -> V_457 ) ;
V_438 = V_437 -> V_13 ;
if ( V_438 != V_13 &&
( ! V_438 ||
V_438 -> V_113 ||
! F_3 ( V_438 , V_293 ) ) ) {
V_438 = V_13 ;
goto V_458;
}
if ( V_438 != V_13 )
F_4 ( V_438 ) ;
V_31 = F_335 ( V_438 ,
V_437 , V_34 , V_438 -> V_20 . V_21 ) ;
if ( V_31 ) {
F_13 ( & V_437 -> V_457 ) ;
F_336 ( V_33 ,
V_13 , V_105 , V_34 ) ;
goto V_459;
}
F_8 ( V_437 -> V_13 != V_438 ) ;
if ( V_438 != V_13 ) {
F_6 ( V_438 ) ;
V_438 = V_13 ;
}
V_458:
F_22 ( V_438 != V_13 ) ;
if ( V_442 >= V_460 &&
V_437 -> V_13 != V_13 ) {
F_13 ( & V_437 -> V_457 ) ;
goto V_461;
}
F_337 ( NULL , V_437 ) ;
if ( V_442 >= V_460 ) {
F_13 ( & V_437 -> V_457 ) ;
goto V_461;
}
V_27 = F_338 ( V_83 , V_33 ,
V_13 , V_437 ,
V_105 , V_34 ,
V_439 + V_434 ) ;
if ( V_27 == 0 ) {
V_31 = F_335 ( V_13 ,
V_437 , V_34 ,
V_105 ) ;
if ( V_31 ) {
F_13 ( & V_437 -> V_457 ) ;
F_336 ( V_33 ,
V_13 , V_105 ,
V_34 ) ;
goto V_459;
}
} else if ( ! V_3 && V_442 > V_462
&& ! V_446 ) {
F_13 ( & V_437 -> V_457 ) ;
V_446 = true ;
F_327 ( V_13 ,
V_34 + V_439 + V_434 ) ;
goto V_454;
}
F_337 ( NULL , V_437 ) ;
F_13 ( & V_437 -> V_457 ) ;
goto V_442;
}
V_461:
F_11 ( & V_13 -> V_10 -> V_463 ) ;
if ( V_3 &&
V_13 -> V_10 -> V_431 <
V_34 + V_439 + V_434 ) {
F_13 ( & V_13 -> V_10 -> V_463 ) ;
goto V_442;
}
F_13 ( & V_13 -> V_10 -> V_463 ) ;
V_31 = F_339 ( V_13 , V_105 ,
V_34 , V_434 ) ;
if ( ! V_31 && ! V_447 && ! V_3 &&
V_442 > V_462 ) {
F_327 ( V_13 ,
V_34 + V_434 ) ;
V_447 = true ;
goto V_454;
} else if ( ! V_31 ) {
if ( ! V_3 )
V_449 = true ;
goto V_442;
}
V_459:
V_105 = F_326 ( V_33 , V_31 ) ;
if ( V_105 + V_34 >
V_438 -> V_20 . V_21 + V_438 -> V_20 . V_31 ) {
F_29 ( V_438 , V_31 , V_34 ) ;
goto V_442;
}
if ( V_31 < V_105 )
F_29 ( V_438 , V_31 ,
V_105 - V_31 ) ;
F_22 ( V_31 > V_105 ) ;
V_27 = F_310 ( V_438 , V_34 ,
V_443 ) ;
if ( V_27 == - V_175 ) {
F_29 ( V_438 , V_31 , V_34 ) ;
goto V_442;
}
V_205 -> V_21 = V_105 ;
V_205 -> V_31 = V_34 ;
F_340 ( V_433 , V_13 ,
V_105 , V_34 ) ;
if ( V_31 < V_105 )
F_29 ( V_438 , V_31 ,
V_105 - V_31 ) ;
F_22 ( V_31 > V_105 ) ;
if ( V_438 != V_13 )
F_6 ( V_438 ) ;
F_6 ( V_13 ) ;
break;
V_442:
V_446 = false ;
V_447 = false ;
F_22 ( V_432 != F_330 ( V_13 ) ) ;
if ( V_438 != V_13 )
F_6 ( V_438 ) ;
F_6 ( V_13 ) ;
}
F_44 ( & V_99 -> V_274 ) ;
if ( ! V_205 -> V_21 && V_442 >= V_464 && V_449 )
goto V_455;
if ( ! V_205 -> V_21 && ++ V_432 < V_272 )
goto V_455;
if ( ! V_205 -> V_21 && V_442 < V_460 ) {
V_432 = 0 ;
V_442 ++ ;
if ( V_442 == V_465 ) {
if ( V_440 ) {
V_27 = F_175 ( V_83 , V_33 , V_34 +
2 * 1024 * 1024 , V_293 ,
V_325 ) ;
if ( V_27 < 0 ) {
F_151 ( V_83 ,
V_33 , V_27 ) ;
goto V_69;
}
V_440 = 0 ;
if ( V_27 == 1 )
V_441 = 1 ;
} else if ( ! V_441 &&
V_99 -> V_279 ==
V_222 ) {
V_99 -> V_279 = V_325 ;
}
if ( ! V_441 )
V_442 = V_460 ;
}
if ( V_442 == V_460 ) {
V_434 = 0 ;
V_439 = 0 ;
}
goto V_455;
} else if ( ! V_205 -> V_21 ) {
V_27 = - V_314 ;
} else if ( V_205 -> V_21 ) {
V_27 = 0 ;
}
V_69:
return V_27 ;
}
static void F_252 ( struct V_96 * V_12 , T_2 V_304 ,
int V_466 )
{
struct V_1 * V_2 ;
int V_432 = 0 ;
F_11 ( & V_12 -> V_49 ) ;
F_173 ( V_330 L_15 ,
( unsigned long long ) V_12 -> V_6 ,
( unsigned long long ) ( V_12 -> V_265 - V_12 -> V_266 -
V_12 -> V_275 - V_12 -> V_276 -
V_12 -> V_277 ) ,
( V_12 -> V_102 ) ? L_16 : L_17 ) ;
F_173 ( V_330 L_18
L_19 ,
( unsigned long long ) V_12 -> V_265 ,
( unsigned long long ) V_12 -> V_266 ,
( unsigned long long ) V_12 -> V_275 ,
( unsigned long long ) V_12 -> V_276 ,
( unsigned long long ) V_12 -> V_278 ,
( unsigned long long ) V_12 -> V_277 ) ;
F_13 ( & V_12 -> V_49 ) ;
if ( ! V_466 )
return;
F_35 ( & V_12 -> V_274 ) ;
V_74:
F_333 (cache, &info->block_groups[index], list) {
F_11 ( & V_2 -> V_49 ) ;
F_173 ( V_330 L_20
L_21 ,
( unsigned long long ) V_2 -> V_20 . V_21 ,
( unsigned long long ) V_2 -> V_20 . V_31 ,
( unsigned long long ) F_76 ( & V_2 -> V_112 ) ,
( unsigned long long ) V_2 -> V_8 ,
( unsigned long long ) V_2 -> V_9 ) ;
F_341 ( V_2 , V_304 ) ;
F_13 ( & V_2 -> V_49 ) ;
}
if ( ++ V_432 < V_272 )
goto V_74;
F_44 ( & V_12 -> V_274 ) ;
}
int F_342 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
T_2 V_34 , T_2 V_467 ,
T_2 V_434 , T_2 V_435 ,
struct V_65 * V_205 , T_2 V_293 )
{
bool V_468 = false ;
int V_27 ;
V_293 = F_176 ( V_33 , V_293 ) ;
V_74:
if ( V_434 || V_33 -> V_243 ) {
V_27 = F_175 ( V_83 , V_33 -> V_35 -> V_60 ,
V_34 + 2 * 1024 * 1024 , V_293 ,
V_222 ) ;
if ( V_27 < 0 && V_27 != - V_314 ) {
F_151 ( V_83 , V_33 , V_27 ) ;
return V_27 ;
}
}
F_8 ( V_34 < V_33 -> V_308 ) ;
V_27 = F_331 ( V_83 , V_33 , V_34 , V_434 ,
V_435 , V_205 , V_293 ) ;
if ( V_27 == - V_314 ) {
if ( ! V_468 ) {
V_34 = V_34 >> 1 ;
V_34 = V_34 & ~ ( V_33 -> V_308 - 1 ) ;
V_34 = F_75 ( V_34 , V_467 ) ;
V_27 = F_175 ( V_83 , V_33 -> V_35 -> V_60 ,
V_34 , V_293 , V_313 ) ;
if ( V_27 < 0 && V_27 != - V_314 ) {
F_151 ( V_83 , V_33 , V_27 ) ;
return V_27 ;
}
if ( V_34 == V_467 )
V_468 = true ;
goto V_74;
} else if ( F_251 ( V_33 , V_329 ) ) {
struct V_96 * V_317 ;
V_317 = F_66 ( V_33 -> V_35 , V_293 ) ;
F_173 ( V_421 L_22
L_23 , ( unsigned long long ) V_293 ,
( unsigned long long ) V_34 ) ;
if ( V_317 )
F_252 ( V_317 , V_34 , 1 ) ;
}
}
F_343 ( V_33 , V_205 -> V_21 , V_205 -> V_31 ) ;
return V_27 ;
}
static int F_344 ( struct V_32 * V_33 ,
T_2 V_30 , T_2 V_115 , int V_469 )
{
struct V_1 * V_2 ;
int V_27 = 0 ;
V_2 = F_65 ( V_33 -> V_35 , V_30 ) ;
if ( ! V_2 ) {
F_173 ( V_421 L_24 ,
( unsigned long long ) V_30 ) ;
return - V_314 ;
}
if ( F_251 ( V_33 , V_415 ) )
V_27 = F_145 ( V_33 , V_30 , V_115 , NULL ) ;
if ( V_469 )
F_307 ( V_33 , V_2 , V_30 , V_115 , 1 ) ;
else {
F_29 ( V_2 , V_30 , V_115 ) ;
F_310 ( V_2 , V_115 , V_411 ) ;
}
F_6 ( V_2 ) ;
F_345 ( V_33 , V_30 , V_115 ) ;
return V_27 ;
}
int F_346 ( struct V_32 * V_33 ,
T_2 V_30 , T_2 V_115 )
{
return F_344 ( V_33 , V_30 , V_115 , 0 ) ;
}
int F_347 ( struct V_32 * V_33 ,
T_2 V_30 , T_2 V_115 )
{
return F_344 ( V_33 , V_30 , V_115 , 1 ) ;
}
static int F_154 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
T_2 V_16 , T_2 V_146 ,
T_2 V_6 , T_2 V_107 , T_2 V_31 ,
struct V_65 * V_205 , int V_134 )
{
int V_27 ;
struct V_11 * V_35 = V_33 -> V_35 ;
struct V_120 * V_470 ;
struct V_162 * V_163 ;
struct V_61 * V_62 ;
struct V_63 * V_64 ;
int type ;
T_3 V_54 ;
if ( V_16 > 0 )
type = V_154 ;
else
type = V_155 ;
V_54 = sizeof( * V_470 ) + F_128 ( type ) ;
V_62 = F_32 () ;
if ( ! V_62 )
return - V_85 ;
V_62 -> V_201 = 1 ;
V_27 = F_109 ( V_83 , V_35 -> V_60 , V_62 ,
V_205 , V_54 ) ;
if ( V_27 ) {
F_48 ( V_62 ) ;
return V_27 ;
}
V_64 = V_62 -> V_78 [ 0 ] ;
V_470 = F_81 ( V_64 , V_62 -> V_79 [ 0 ] ,
struct V_120 ) ;
F_93 ( V_64 , V_470 , V_134 ) ;
F_94 ( V_64 , V_470 , V_83 -> V_256 ) ;
F_95 ( V_64 , V_470 ,
V_6 | V_145 ) ;
V_163 = (struct V_162 * ) ( V_470 + 1 ) ;
F_135 ( V_64 , V_163 , type ) ;
if ( V_16 > 0 ) {
struct V_158 * V_151 ;
V_151 = (struct V_158 * ) ( V_163 + 1 ) ;
F_136 ( V_64 , V_163 , V_16 ) ;
F_110 ( V_64 , V_151 , V_134 ) ;
} else {
struct V_150 * V_151 ;
V_151 = (struct V_150 * ) ( & V_163 -> V_31 ) ;
F_112 ( V_64 , V_151 , V_146 ) ;
F_113 ( V_64 , V_151 , V_107 ) ;
F_114 ( V_64 , V_151 , V_31 ) ;
F_115 ( V_64 , V_151 , V_134 ) ;
}
F_98 ( V_62 -> V_78 [ 0 ] ) ;
F_48 ( V_62 ) ;
V_27 = F_301 ( V_83 , V_33 , V_205 -> V_21 , V_205 -> V_31 , 1 ) ;
if ( V_27 ) {
F_173 ( V_421 L_25
L_26 , ( unsigned long long ) V_205 -> V_21 ,
( unsigned long long ) V_205 -> V_31 ) ;
F_86 () ;
}
return V_27 ;
}
static int F_160 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
T_2 V_16 , T_2 V_146 ,
T_2 V_6 , struct V_398 * V_20 ,
int V_166 , struct V_65 * V_205 )
{
int V_27 ;
struct V_11 * V_35 = V_33 -> V_35 ;
struct V_120 * V_470 ;
struct V_138 * V_471 ;
struct V_162 * V_163 ;
struct V_61 * V_62 ;
struct V_63 * V_64 ;
T_3 V_54 = sizeof( * V_470 ) + sizeof( * V_471 ) + sizeof( * V_163 ) ;
V_62 = F_32 () ;
if ( ! V_62 )
return - V_85 ;
V_62 -> V_201 = 1 ;
V_27 = F_109 ( V_83 , V_35 -> V_60 , V_62 ,
V_205 , V_54 ) ;
if ( V_27 ) {
F_48 ( V_62 ) ;
return V_27 ;
}
V_64 = V_62 -> V_78 [ 0 ] ;
V_470 = F_81 ( V_64 , V_62 -> V_79 [ 0 ] ,
struct V_120 ) ;
F_93 ( V_64 , V_470 , 1 ) ;
F_94 ( V_64 , V_470 , V_83 -> V_256 ) ;
F_95 ( V_64 , V_470 ,
V_6 | V_144 ) ;
V_471 = (struct V_138 * ) ( V_470 + 1 ) ;
F_156 ( V_64 , V_471 , V_20 ) ;
F_97 ( V_64 , V_471 , V_166 ) ;
V_163 = (struct V_162 * ) ( V_471 + 1 ) ;
if ( V_16 > 0 ) {
F_22 ( ! ( V_6 & V_128 ) ) ;
F_135 ( V_64 , V_163 ,
V_164 ) ;
F_136 ( V_64 , V_163 , V_16 ) ;
} else {
F_135 ( V_64 , V_163 ,
V_165 ) ;
F_136 ( V_64 , V_163 , V_146 ) ;
}
F_98 ( V_64 ) ;
F_48 ( V_62 ) ;
V_27 = F_301 ( V_83 , V_33 , V_205 -> V_21 , V_205 -> V_31 , 1 ) ;
if ( V_27 ) {
F_173 ( V_421 L_25
L_26 , ( unsigned long long ) V_205 -> V_21 ,
( unsigned long long ) V_205 -> V_31 ) ;
F_86 () ;
}
return V_27 ;
}
int F_348 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
T_2 V_146 , T_2 V_107 ,
T_2 V_31 , struct V_65 * V_205 )
{
int V_27 ;
F_22 ( V_146 == V_199 ) ;
V_27 = F_149 ( V_33 -> V_35 , V_83 , V_205 -> V_21 ,
V_205 -> V_31 , 0 ,
V_146 , V_107 , V_31 ,
V_472 , NULL , 0 ) ;
return V_27 ;
}
int F_349 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
T_2 V_146 , T_2 V_107 , T_2 V_31 ,
struct V_65 * V_205 )
{
int V_27 ;
struct V_1 * V_13 ;
struct V_47 * V_51 ;
T_2 V_30 = V_205 -> V_21 ;
T_2 V_34 = V_205 -> V_31 ;
V_13 = F_65 ( V_33 -> V_35 , V_205 -> V_21 ) ;
F_49 ( V_13 , V_83 , NULL , 0 ) ;
V_51 = F_25 ( V_13 ) ;
if ( ! V_51 ) {
F_22 ( ! F_1 ( V_13 ) ) ;
V_27 = F_309 ( V_13 , V_30 , V_34 ) ;
F_22 ( V_27 ) ;
} else {
F_34 ( & V_51 -> V_75 ) ;
if ( V_30 >= V_51 -> V_80 ) {
V_27 = F_17 ( V_33 , V_30 , V_34 ) ;
F_22 ( V_27 ) ;
} else if ( V_30 + V_34 <= V_51 -> V_80 ) {
V_27 = F_309 ( V_13 ,
V_30 , V_34 ) ;
F_22 ( V_27 ) ;
} else {
V_34 = V_51 -> V_80 - V_30 ;
V_27 = F_309 ( V_13 ,
V_30 , V_34 ) ;
F_22 ( V_27 ) ;
V_30 = V_51 -> V_80 ;
V_34 = V_205 -> V_21 + V_205 -> V_31 -
V_51 -> V_80 ;
V_27 = F_17 ( V_33 , V_30 , V_34 ) ;
F_22 ( V_27 ) ;
}
F_45 ( & V_51 -> V_75 ) ;
F_26 ( V_51 ) ;
}
V_27 = F_310 ( V_13 , V_205 -> V_31 ,
V_444 ) ;
F_22 ( V_27 ) ;
F_6 ( V_13 ) ;
V_27 = F_154 ( V_83 , V_33 , 0 , V_146 ,
0 , V_107 , V_31 , V_205 , 1 ) ;
return V_27 ;
}
struct V_63 * F_350 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
T_2 V_25 , T_3 V_473 ,
int V_166 )
{
struct V_63 * V_238 ;
V_238 = F_351 ( V_33 , V_25 , V_473 ) ;
if ( ! V_238 )
return F_352 ( - V_85 ) ;
F_353 ( V_238 , V_83 -> V_256 ) ;
F_354 ( V_33 -> V_234 . V_21 , V_238 , V_166 ) ;
F_355 ( V_238 ) ;
F_356 ( V_83 , V_33 , V_238 ) ;
F_325 ( V_474 , & V_238 -> V_426 ) ;
F_357 ( V_238 ) ;
F_358 ( V_238 ) ;
if ( V_33 -> V_234 . V_21 == V_199 ) {
if ( V_33 -> V_475 % 2 == 0 )
F_305 ( & V_33 -> V_476 , V_238 -> V_30 ,
V_238 -> V_30 + V_238 -> V_115 - 1 , V_38 ) ;
else
F_359 ( & V_33 -> V_476 , V_238 -> V_30 ,
V_238 -> V_30 + V_238 -> V_115 - 1 , V_38 ) ;
} else {
F_305 ( & V_83 -> V_129 -> V_477 , V_238 -> V_30 ,
V_238 -> V_30 + V_238 -> V_115 - 1 , V_38 ) ;
}
V_83 -> V_478 ++ ;
return V_238 ;
}
static struct V_320 *
F_360 ( struct V_82 * V_83 ,
struct V_32 * V_33 , T_3 V_473 )
{
struct V_320 * V_337 ;
struct V_320 * V_321 = & V_33 -> V_35 -> V_322 ;
int V_27 ;
V_337 = F_264 ( V_83 , V_33 ) ;
if ( V_337 -> V_54 == 0 ) {
V_27 = F_261 ( V_33 , V_337 , V_473 , 0 ) ;
if ( V_27 && V_337 != V_321 ) {
V_27 = F_265 ( V_321 , V_473 ) ;
if ( ! V_27 )
return V_321 ;
return F_352 ( V_27 ) ;
} else if ( V_27 ) {
return F_352 ( V_27 ) ;
}
return V_337 ;
}
V_27 = F_265 ( V_337 , V_473 ) ;
if ( ! V_27 )
return V_337 ;
if ( V_27 ) {
static F_361 ( V_479 ,
V_480 ,
2 ) ;
if ( F_362 ( & V_479 ) ) {
F_173 ( V_219 L_27 , V_27 ) ;
F_8 ( 1 ) ;
}
V_27 = F_261 ( V_33 , V_337 , V_473 , 0 ) ;
if ( ! V_27 ) {
return V_337 ;
} else if ( V_27 && V_337 != V_321 ) {
V_27 = F_265 ( V_321 , V_473 ) ;
if ( ! V_27 )
return V_321 ;
}
}
return F_352 ( - V_314 ) ;
}
static void F_363 ( struct V_11 * V_35 ,
struct V_320 * V_337 , T_3 V_473 )
{
F_266 ( V_337 , V_473 , 0 ) ;
F_267 ( V_35 , V_337 , NULL , 0 ) ;
}
struct V_63 * F_364 ( struct V_82 * V_83 ,
struct V_32 * V_33 , T_3 V_473 ,
T_2 V_16 , T_2 V_146 ,
struct V_398 * V_20 , int V_166 ,
T_2 V_481 , T_2 V_434 , int V_198 )
{
struct V_65 V_205 ;
struct V_320 * V_337 ;
struct V_63 * V_238 ;
T_2 V_6 = 0 ;
int V_27 ;
V_337 = F_360 ( V_83 , V_33 , V_473 ) ;
if ( F_214 ( V_337 ) )
return F_365 ( V_337 ) ;
V_27 = F_342 ( V_83 , V_33 , V_473 , V_473 ,
V_434 , V_481 , & V_205 , 0 ) ;
if ( V_27 ) {
F_363 ( V_33 -> V_35 , V_337 , V_473 ) ;
return F_352 ( V_27 ) ;
}
V_238 = F_350 ( V_83 , V_33 , V_205 . V_21 ,
V_473 , V_166 ) ;
F_22 ( F_214 ( V_238 ) ) ;
if ( V_146 == V_482 ) {
if ( V_16 == 0 )
V_16 = V_205 . V_21 ;
V_6 |= V_128 ;
} else
F_22 ( V_16 > 0 ) ;
if ( V_146 != V_199 ) {
struct V_177 * V_131 ;
V_131 = F_187 ( sizeof( * V_131 ) , V_38 ) ;
F_22 ( ! V_131 ) ;
if ( V_20 )
memcpy ( & V_131 -> V_20 , V_20 , sizeof( V_131 -> V_20 ) ) ;
else
memset ( & V_131 -> V_20 , 0 , sizeof( V_131 -> V_20 ) ) ;
V_131 -> V_133 = V_6 ;
V_131 -> V_208 = 1 ;
V_131 -> V_132 = 1 ;
V_131 -> V_181 = 0 ;
V_27 = F_148 ( V_33 -> V_35 , V_83 ,
V_205 . V_21 ,
V_205 . V_31 , V_16 , V_146 ,
V_166 , V_472 ,
V_131 , V_198 ) ;
F_22 ( V_27 ) ;
}
return V_238 ;
}
static T_1 void F_366 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_483 * V_484 ,
struct V_61 * V_62 )
{
T_2 V_25 ;
T_2 V_259 ;
T_2 V_116 ;
T_2 V_6 ;
T_3 V_68 ;
T_3 V_473 ;
struct V_65 V_20 ;
struct V_63 * V_485 ;
int V_27 ;
int V_486 ;
int V_487 = 0 ;
if ( V_62 -> V_79 [ V_484 -> V_166 ] < V_484 -> V_488 ) {
V_484 -> V_489 = V_484 -> V_489 * 2 / 3 ;
V_484 -> V_489 = F_75 ( V_484 -> V_489 , 2 ) ;
} else {
V_484 -> V_489 = V_484 -> V_489 * 3 / 2 ;
V_484 -> V_489 = F_182 ( int , V_484 -> V_489 ,
F_367 ( V_33 ) ) ;
}
V_485 = V_62 -> V_78 [ V_484 -> V_166 ] ;
V_68 = F_37 ( V_485 ) ;
V_473 = F_205 ( V_33 , V_484 -> V_166 - 1 ) ;
for ( V_486 = V_62 -> V_79 [ V_484 -> V_166 ] ; V_486 < V_68 ; V_486 ++ ) {
if ( V_487 >= V_484 -> V_489 )
break;
F_46 () ;
V_25 = F_204 ( V_485 , V_486 ) ;
V_259 = F_368 ( V_485 , V_486 ) ;
if ( V_486 == V_62 -> V_79 [ V_484 -> V_166 ] )
goto V_72;
if ( V_484 -> V_490 == V_491 &&
V_259 <= V_33 -> V_234 . V_31 )
continue;
V_27 = F_79 ( V_83 , V_33 , V_25 , V_473 ,
& V_116 , & V_6 ) ;
if ( V_27 < 0 )
continue;
F_22 ( V_116 == 0 ) ;
if ( V_484 -> V_490 == V_492 ) {
if ( V_116 == 1 )
goto V_72;
if ( V_484 -> V_166 == 1 &&
( V_6 & V_128 ) )
continue;
if ( ! V_484 -> V_493 ||
V_259 <= V_33 -> V_234 . V_31 )
continue;
F_126 ( V_485 , & V_20 , V_486 ) ;
V_27 = F_369 ( & V_20 ,
& V_484 -> V_494 ) ;
if ( V_27 < 0 )
continue;
} else {
if ( V_484 -> V_166 == 1 &&
( V_6 & V_128 ) )
continue;
}
V_72:
V_27 = F_370 ( V_33 , V_25 , V_473 ,
V_259 ) ;
if ( V_27 )
break;
V_487 ++ ;
}
V_484 -> V_488 = V_486 ;
}
static T_1 int F_371 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_61 * V_62 ,
struct V_483 * V_484 , int V_495 )
{
int V_166 = V_484 -> V_166 ;
struct V_63 * V_485 = V_62 -> V_78 [ V_166 ] ;
T_2 V_496 = V_128 ;
int V_27 ;
if ( V_484 -> V_490 == V_491 &&
F_197 ( V_485 ) != V_33 -> V_234 . V_21 )
return 1 ;
if ( V_495 &&
( ( V_484 -> V_490 == V_492 && V_484 -> V_116 [ V_166 ] != 1 ) ||
( V_484 -> V_490 == V_491 && ! ( V_484 -> V_6 [ V_166 ] & V_496 ) ) ) ) {
F_22 ( ! V_62 -> V_497 [ V_166 ] ) ;
V_27 = F_79 ( V_83 , V_33 ,
V_485 -> V_30 , V_485 -> V_115 ,
& V_484 -> V_116 [ V_166 ] ,
& V_484 -> V_6 [ V_166 ] ) ;
F_22 ( V_27 == - V_85 ) ;
if ( V_27 )
return V_27 ;
F_22 ( V_484 -> V_116 [ V_166 ] == 0 ) ;
}
if ( V_484 -> V_490 == V_492 ) {
if ( V_484 -> V_116 [ V_166 ] > 1 )
return 1 ;
if ( V_62 -> V_497 [ V_166 ] && ! V_484 -> V_172 ) {
F_372 ( V_485 , V_62 -> V_497 [ V_166 ] ) ;
V_62 -> V_497 [ V_166 ] = 0 ;
}
return 0 ;
}
if ( ! ( V_484 -> V_6 [ V_166 ] & V_496 ) ) {
F_22 ( ! V_62 -> V_497 [ V_166 ] ) ;
V_27 = F_206 ( V_83 , V_33 , V_485 , 1 , V_484 -> V_498 ) ;
F_22 ( V_27 ) ;
V_27 = F_207 ( V_83 , V_33 , V_485 , 0 , V_484 -> V_498 ) ;
F_22 ( V_27 ) ;
V_27 = F_186 ( V_83 , V_33 , V_485 -> V_30 ,
V_485 -> V_115 , V_496 , 0 ) ;
F_22 ( V_27 ) ;
V_484 -> V_6 [ V_166 ] |= V_496 ;
}
if ( V_62 -> V_497 [ V_166 ] && V_166 > 0 ) {
F_372 ( V_485 , V_62 -> V_497 [ V_166 ] ) ;
V_62 -> V_497 [ V_166 ] = 0 ;
}
return 0 ;
}
static T_1 int F_373 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_61 * V_62 ,
struct V_483 * V_484 , int * V_495 )
{
T_2 V_25 ;
T_2 V_259 ;
T_2 V_16 ;
T_3 V_473 ;
struct V_65 V_20 ;
struct V_63 * V_216 ;
int V_166 = V_484 -> V_166 ;
int V_72 = 0 ;
int V_27 = 0 ;
V_259 = F_368 ( V_62 -> V_78 [ V_166 ] ,
V_62 -> V_79 [ V_166 ] ) ;
if ( V_484 -> V_490 == V_491 &&
V_259 <= V_33 -> V_234 . V_31 ) {
* V_495 = 1 ;
return 1 ;
}
V_25 = F_204 ( V_62 -> V_78 [ V_166 ] , V_62 -> V_79 [ V_166 ] ) ;
V_473 = F_205 ( V_33 , V_166 - 1 ) ;
V_216 = F_374 ( V_33 , V_25 , V_473 ) ;
if ( ! V_216 ) {
V_216 = F_351 ( V_33 , V_25 , V_473 ) ;
if ( ! V_216 )
return - V_85 ;
V_72 = 1 ;
}
F_355 ( V_216 ) ;
F_357 ( V_216 ) ;
V_27 = F_79 ( V_83 , V_33 , V_25 , V_473 ,
& V_484 -> V_116 [ V_166 - 1 ] ,
& V_484 -> V_6 [ V_166 - 1 ] ) ;
if ( V_27 < 0 ) {
F_375 ( V_216 ) ;
return V_27 ;
}
F_22 ( V_484 -> V_116 [ V_166 - 1 ] == 0 ) ;
* V_495 = 0 ;
if ( V_484 -> V_490 == V_492 ) {
if ( V_484 -> V_116 [ V_166 - 1 ] > 1 ) {
if ( V_166 == 1 &&
( V_484 -> V_6 [ 0 ] & V_128 ) )
goto V_499;
if ( ! V_484 -> V_493 ||
V_259 <= V_33 -> V_234 . V_31 )
goto V_499;
F_126 ( V_62 -> V_78 [ V_166 ] , & V_20 ,
V_62 -> V_79 [ V_166 ] ) ;
V_27 = F_369 ( & V_20 , & V_484 -> V_494 ) ;
if ( V_27 < 0 )
goto V_499;
V_484 -> V_490 = V_491 ;
V_484 -> V_500 = V_166 - 1 ;
}
} else {
if ( V_166 == 1 &&
( V_484 -> V_6 [ 0 ] & V_128 ) )
goto V_499;
}
if ( ! F_376 ( V_216 , V_259 , 0 ) ) {
F_375 ( V_216 ) ;
F_377 ( V_216 ) ;
V_216 = NULL ;
* V_495 = 1 ;
}
if ( ! V_216 ) {
if ( V_72 && V_166 == 1 )
F_366 ( V_83 , V_33 , V_484 , V_62 ) ;
V_216 = F_378 ( V_33 , V_25 , V_473 , V_259 ) ;
if ( ! V_216 )
return - V_211 ;
F_355 ( V_216 ) ;
F_357 ( V_216 ) ;
}
V_166 -- ;
F_22 ( V_166 != F_198 ( V_216 ) ) ;
V_62 -> V_78 [ V_166 ] = V_216 ;
V_62 -> V_79 [ V_166 ] = 0 ;
V_62 -> V_497 [ V_166 ] = V_501 ;
V_484 -> V_166 = V_166 ;
if ( V_484 -> V_166 == 1 )
V_484 -> V_488 = 0 ;
return 0 ;
V_499:
V_484 -> V_116 [ V_166 - 1 ] = 0 ;
V_484 -> V_6 [ V_166 - 1 ] = 0 ;
if ( V_484 -> V_490 == V_492 ) {
if ( V_484 -> V_6 [ V_166 ] & V_128 ) {
V_16 = V_62 -> V_78 [ V_166 ] -> V_30 ;
} else {
F_22 ( V_33 -> V_234 . V_21 !=
F_197 ( V_62 -> V_78 [ V_166 ] ) ) ;
V_16 = 0 ;
}
V_27 = V_244 ( V_83 , V_33 , V_25 , V_473 , V_16 ,
V_33 -> V_234 . V_21 , V_166 - 1 , 0 , 0 ) ;
F_22 ( V_27 ) ;
}
F_375 ( V_216 ) ;
F_377 ( V_216 ) ;
* V_495 = 1 ;
return 1 ;
}
static T_1 int F_379 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_61 * V_62 ,
struct V_483 * V_484 )
{
int V_27 ;
int V_166 = V_484 -> V_166 ;
struct V_63 * V_485 = V_62 -> V_78 [ V_166 ] ;
T_2 V_16 = 0 ;
if ( V_484 -> V_490 == V_491 ) {
F_22 ( V_484 -> V_500 < V_166 ) ;
if ( V_166 < V_484 -> V_500 )
goto V_69;
V_27 = F_40 ( V_62 , V_166 + 1 , & V_484 -> V_494 ) ;
if ( V_27 > 0 )
V_484 -> V_493 = 0 ;
V_484 -> V_490 = V_492 ;
V_484 -> V_500 = - 1 ;
V_62 -> V_79 [ V_166 ] = 0 ;
if ( ! V_62 -> V_497 [ V_166 ] ) {
F_22 ( V_166 == 0 ) ;
F_355 ( V_485 ) ;
F_357 ( V_485 ) ;
V_62 -> V_497 [ V_166 ] = V_501 ;
V_27 = F_79 ( V_83 , V_33 ,
V_485 -> V_30 , V_485 -> V_115 ,
& V_484 -> V_116 [ V_166 ] ,
& V_484 -> V_6 [ V_166 ] ) ;
if ( V_27 < 0 ) {
F_372 ( V_485 , V_62 -> V_497 [ V_166 ] ) ;
return V_27 ;
}
F_22 ( V_484 -> V_116 [ V_166 ] == 0 ) ;
if ( V_484 -> V_116 [ V_166 ] == 1 ) {
F_372 ( V_485 , V_62 -> V_497 [ V_166 ] ) ;
return 1 ;
}
}
}
F_22 ( V_484 -> V_116 [ V_166 ] > 1 && ! V_62 -> V_497 [ V_166 ] ) ;
if ( V_484 -> V_116 [ V_166 ] == 1 ) {
if ( V_166 == 0 ) {
if ( V_484 -> V_6 [ V_166 ] & V_128 )
V_27 = F_207 ( V_83 , V_33 , V_485 , 1 ,
V_484 -> V_498 ) ;
else
V_27 = F_207 ( V_83 , V_33 , V_485 , 0 ,
V_484 -> V_498 ) ;
F_22 ( V_27 ) ;
}
if ( ! V_62 -> V_497 [ V_166 ] &&
F_322 ( V_485 ) == V_83 -> V_256 ) {
F_355 ( V_485 ) ;
F_357 ( V_485 ) ;
V_62 -> V_497 [ V_166 ] = V_501 ;
}
F_356 ( V_83 , V_33 , V_485 ) ;
}
if ( V_485 == V_33 -> V_130 ) {
if ( V_484 -> V_6 [ V_166 ] & V_128 )
V_16 = V_485 -> V_30 ;
else
F_22 ( V_33 -> V_234 . V_21 !=
F_197 ( V_485 ) ) ;
} else {
if ( V_484 -> V_6 [ V_166 + 1 ] & V_128 )
V_16 = V_62 -> V_78 [ V_166 + 1 ] -> V_30 ;
else
F_22 ( V_33 -> V_234 . V_21 !=
F_197 ( V_62 -> V_78 [ V_166 + 1 ] ) ) ;
}
F_321 ( V_83 , V_33 , V_485 , V_16 , V_484 -> V_116 [ V_166 ] == 1 , 0 ) ;
V_69:
V_484 -> V_116 [ V_166 ] = 0 ;
V_484 -> V_6 [ V_166 ] = 0 ;
return 0 ;
}
static T_1 int F_380 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_61 * V_62 ,
struct V_483 * V_484 )
{
int V_166 = V_484 -> V_166 ;
int V_495 = 1 ;
int V_27 ;
while ( V_166 >= 0 ) {
V_27 = F_371 ( V_83 , V_33 , V_62 , V_484 , V_495 ) ;
if ( V_27 > 0 )
break;
if ( V_166 == 0 )
break;
if ( V_62 -> V_79 [ V_166 ] >=
F_37 ( V_62 -> V_78 [ V_166 ] ) )
break;
V_27 = F_373 ( V_83 , V_33 , V_62 , V_484 , & V_495 ) ;
if ( V_27 > 0 ) {
V_62 -> V_79 [ V_166 ] ++ ;
continue;
} else if ( V_27 < 0 )
return V_27 ;
V_166 = V_484 -> V_166 ;
}
return 0 ;
}
static T_1 int F_381 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_61 * V_62 ,
struct V_483 * V_484 , int V_502 )
{
int V_166 = V_484 -> V_166 ;
int V_27 ;
V_62 -> V_79 [ V_166 ] = F_37 ( V_62 -> V_78 [ V_166 ] ) ;
while ( V_166 < V_502 && V_62 -> V_78 [ V_166 ] ) {
V_484 -> V_166 = V_166 ;
if ( V_62 -> V_79 [ V_166 ] + 1 <
F_37 ( V_62 -> V_78 [ V_166 ] ) ) {
V_62 -> V_79 [ V_166 ] ++ ;
return 0 ;
} else {
V_27 = F_379 ( V_83 , V_33 , V_62 , V_484 ) ;
if ( V_27 > 0 )
return 0 ;
if ( V_62 -> V_497 [ V_166 ] ) {
F_372 ( V_62 -> V_78 [ V_166 ] ,
V_62 -> V_497 [ V_166 ] ) ;
V_62 -> V_497 [ V_166 ] = 0 ;
}
F_377 ( V_62 -> V_78 [ V_166 ] ) ;
V_62 -> V_78 [ V_166 ] = NULL ;
V_166 ++ ;
}
}
return 1 ;
}
int F_382 ( struct V_32 * V_33 ,
struct V_320 * V_337 , int V_493 ,
int V_498 )
{
struct V_61 * V_62 ;
struct V_82 * V_83 ;
struct V_32 * V_230 = V_33 -> V_35 -> V_230 ;
struct V_503 * V_235 = & V_33 -> V_235 ;
struct V_483 * V_484 ;
struct V_65 V_20 ;
int V_77 = 0 ;
int V_27 ;
int V_166 ;
V_62 = F_32 () ;
if ( ! V_62 ) {
V_77 = - V_85 ;
goto V_69;
}
V_484 = F_51 ( sizeof( * V_484 ) , V_38 ) ;
if ( ! V_484 ) {
F_48 ( V_62 ) ;
V_77 = - V_85 ;
goto V_69;
}
V_83 = F_383 ( V_230 , 0 ) ;
if ( F_214 ( V_83 ) ) {
V_77 = F_215 ( V_83 ) ;
goto V_125;
}
if ( V_337 )
V_83 -> V_337 = V_337 ;
if ( F_384 ( & V_235 -> V_504 ) == 0 ) {
V_166 = F_198 ( V_33 -> V_130 ) ;
V_62 -> V_78 [ V_166 ] = F_385 ( V_33 ) ;
F_357 ( V_62 -> V_78 [ V_166 ] ) ;
V_62 -> V_79 [ V_166 ] = 0 ;
V_62 -> V_497 [ V_166 ] = V_501 ;
memset ( & V_484 -> V_494 , 0 ,
sizeof( V_484 -> V_494 ) ) ;
} else {
F_386 ( & V_20 , & V_235 -> V_504 ) ;
memcpy ( & V_484 -> V_494 , & V_20 ,
sizeof( V_484 -> V_494 ) ) ;
V_166 = V_235 -> V_505 ;
F_22 ( V_166 == 0 ) ;
V_62 -> V_506 = V_166 ;
V_27 = F_36 ( NULL , V_33 , & V_20 , V_62 , 0 , 0 ) ;
V_62 -> V_506 = 0 ;
if ( V_27 < 0 ) {
V_77 = V_27 ;
goto V_507;
}
F_8 ( V_27 > 0 ) ;
F_131 ( V_62 , 0 ) ;
V_166 = F_198 ( V_33 -> V_130 ) ;
while ( 1 ) {
F_355 ( V_62 -> V_78 [ V_166 ] ) ;
F_357 ( V_62 -> V_78 [ V_166 ] ) ;
V_27 = F_79 ( V_83 , V_33 ,
V_62 -> V_78 [ V_166 ] -> V_30 ,
V_62 -> V_78 [ V_166 ] -> V_115 ,
& V_484 -> V_116 [ V_166 ] ,
& V_484 -> V_6 [ V_166 ] ) ;
if ( V_27 < 0 ) {
V_77 = V_27 ;
goto V_507;
}
F_22 ( V_484 -> V_116 [ V_166 ] == 0 ) ;
if ( V_166 == V_235 -> V_505 )
break;
F_375 ( V_62 -> V_78 [ V_166 ] ) ;
F_8 ( V_484 -> V_116 [ V_166 ] != 1 ) ;
V_166 -- ;
}
}
V_484 -> V_166 = V_166 ;
V_484 -> V_500 = - 1 ;
V_484 -> V_490 = V_492 ;
V_484 -> V_493 = V_493 ;
V_484 -> V_172 = 0 ;
V_484 -> V_498 = V_498 ;
V_484 -> V_489 = F_367 ( V_33 ) ;
while ( 1 ) {
V_27 = F_380 ( V_83 , V_33 , V_62 , V_484 ) ;
if ( V_27 < 0 ) {
V_77 = V_27 ;
break;
}
V_27 = F_381 ( V_83 , V_33 , V_62 , V_484 , V_167 ) ;
if ( V_27 < 0 ) {
V_77 = V_27 ;
break;
}
if ( V_27 > 0 ) {
F_22 ( V_484 -> V_490 != V_492 ) ;
break;
}
if ( V_484 -> V_490 == V_492 ) {
V_166 = V_484 -> V_166 ;
F_387 ( V_62 -> V_78 [ V_166 ] ,
& V_235 -> V_504 ,
V_62 -> V_79 [ V_166 ] ) ;
V_235 -> V_505 = V_166 ;
}
F_22 ( V_484 -> V_166 == 0 ) ;
if ( F_388 ( V_83 , V_230 ) ) {
V_27 = F_389 ( V_83 , V_230 ,
& V_33 -> V_234 ,
V_235 ) ;
if ( V_27 ) {
F_151 ( V_83 , V_230 , V_27 ) ;
V_77 = V_27 ;
goto V_507;
}
F_390 ( V_83 , V_230 ) ;
V_83 = F_383 ( V_230 , 0 ) ;
if ( F_214 ( V_83 ) ) {
V_77 = F_215 ( V_83 ) ;
goto V_125;
}
if ( V_337 )
V_83 -> V_337 = V_337 ;
}
}
F_43 ( V_62 ) ;
if ( V_77 )
goto V_507;
V_27 = F_391 ( V_83 , V_230 , & V_33 -> V_234 ) ;
if ( V_27 ) {
F_151 ( V_83 , V_230 , V_27 ) ;
goto V_507;
}
if ( V_33 -> V_234 . V_21 != V_482 ) {
V_27 = F_392 ( V_230 , V_33 -> V_234 . V_21 ,
NULL , NULL ) ;
if ( V_27 < 0 ) {
F_151 ( V_83 , V_230 , V_27 ) ;
V_77 = V_27 ;
goto V_507;
} else if ( V_27 > 0 ) {
F_393 ( V_83 , V_230 ,
V_33 -> V_234 . V_21 ) ;
}
}
if ( V_33 -> V_508 ) {
F_394 ( V_230 -> V_35 , V_33 ) ;
} else {
F_377 ( V_33 -> V_130 ) ;
F_377 ( V_33 -> V_509 ) ;
F_9 ( V_33 ) ;
}
V_507:
F_390 ( V_83 , V_230 ) ;
V_125:
F_9 ( V_484 ) ;
F_48 ( V_62 ) ;
V_69:
if ( V_77 )
F_395 ( V_33 -> V_35 , V_77 ) ;
return V_77 ;
}
int F_396 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_63 * V_130 ,
struct V_63 * V_16 )
{
struct V_61 * V_62 ;
struct V_483 * V_484 ;
int V_166 ;
int V_510 ;
int V_27 = 0 ;
int V_511 ;
F_22 ( V_33 -> V_234 . V_21 != V_482 ) ;
V_62 = F_32 () ;
if ( ! V_62 )
return - V_85 ;
V_484 = F_51 ( sizeof( * V_484 ) , V_38 ) ;
if ( ! V_484 ) {
F_48 ( V_62 ) ;
return - V_85 ;
}
F_397 ( V_16 ) ;
V_510 = F_198 ( V_16 ) ;
F_398 ( V_16 ) ;
V_62 -> V_78 [ V_510 ] = V_16 ;
V_62 -> V_79 [ V_510 ] = F_37 ( V_16 ) ;
F_397 ( V_130 ) ;
V_166 = F_198 ( V_130 ) ;
V_62 -> V_78 [ V_166 ] = V_130 ;
V_62 -> V_79 [ V_166 ] = 0 ;
V_62 -> V_497 [ V_166 ] = V_501 ;
V_484 -> V_116 [ V_510 ] = 1 ;
V_484 -> V_6 [ V_510 ] = V_128 ;
V_484 -> V_166 = V_166 ;
V_484 -> V_500 = - 1 ;
V_484 -> V_490 = V_492 ;
V_484 -> V_493 = 0 ;
V_484 -> V_172 = 1 ;
V_484 -> V_498 = 1 ;
V_484 -> V_489 = F_367 ( V_33 ) ;
while ( 1 ) {
V_511 = F_380 ( V_83 , V_33 , V_62 , V_484 ) ;
if ( V_511 < 0 ) {
V_27 = V_511 ;
break;
}
V_511 = F_381 ( V_83 , V_33 , V_62 , V_484 , V_510 ) ;
if ( V_511 < 0 )
V_27 = V_511 ;
if ( V_511 != 0 )
break;
}
F_9 ( V_484 ) ;
F_48 ( V_62 ) ;
return V_27 ;
}
static T_2 F_399 ( struct V_32 * V_33 , T_2 V_6 )
{
T_2 V_297 ;
T_2 V_512 ;
V_512 = F_235 ( V_33 -> V_35 , V_6 ) ;
if ( V_512 )
return F_237 ( V_512 ) ;
V_297 = V_33 -> V_35 -> V_298 -> V_299 +
V_33 -> V_35 -> V_298 -> V_300 ;
V_512 = V_302 |
V_268 | V_269 ;
if ( V_297 == 1 ) {
V_512 |= V_267 ;
V_512 = V_6 & ~ V_512 ;
if ( V_6 & V_302 )
return V_512 ;
if ( V_6 & ( V_268 |
V_269 ) )
return V_512 | V_267 ;
} else {
if ( V_6 & V_512 )
return V_6 ;
V_512 |= V_267 ;
V_512 = V_6 & ~ V_512 ;
if ( V_6 & V_267 )
return V_512 | V_268 ;
}
return V_6 ;
}
static int F_400 ( struct V_1 * V_2 , int V_319 )
{
struct V_96 * V_317 = V_2 -> V_99 ;
T_2 V_34 ;
T_2 V_513 ;
int V_27 = - V_314 ;
if ( ( V_317 -> V_6 &
( V_287 | V_114 ) ) &&
! V_319 )
V_513 = 1 * 1024 * 1024 ;
else
V_513 = 0 ;
F_11 ( & V_317 -> V_49 ) ;
F_11 ( & V_2 -> V_49 ) ;
if ( V_2 -> V_113 ) {
V_27 = 0 ;
goto V_69;
}
V_34 = V_2 -> V_20 . V_31 - V_2 -> V_9 - V_2 -> V_8 -
V_2 -> V_44 - F_76 ( & V_2 -> V_112 ) ;
if ( V_317 -> V_266 + V_317 -> V_276 + V_317 -> V_275 +
V_317 -> V_278 + V_317 -> V_277 + V_34 +
V_513 <= V_317 -> V_265 ) {
V_317 -> V_277 += V_34 ;
V_2 -> V_113 = 1 ;
V_27 = 0 ;
}
V_69:
F_13 ( & V_2 -> V_49 ) ;
F_13 ( & V_317 -> V_49 ) ;
return V_27 ;
}
int F_401 ( struct V_32 * V_33 ,
struct V_1 * V_2 )
{
struct V_82 * V_83 ;
T_2 V_514 ;
int V_27 ;
F_22 ( V_2 -> V_113 ) ;
V_83 = F_240 ( V_33 ) ;
if ( F_214 ( V_83 ) )
return F_215 ( V_83 ) ;
V_514 = F_399 ( V_33 , V_2 -> V_6 ) ;
if ( V_514 != V_2 -> V_6 ) {
V_27 = F_175 ( V_83 , V_33 , 2 * 1024 * 1024 , V_514 ,
V_313 ) ;
if ( V_27 < 0 )
goto V_69;
}
V_27 = F_400 ( V_2 , 0 ) ;
if ( ! V_27 )
goto V_69;
V_514 = F_238 ( V_33 , V_2 -> V_99 -> V_6 ) ;
V_27 = F_175 ( V_83 , V_33 , 2 * 1024 * 1024 , V_514 ,
V_313 ) ;
if ( V_27 < 0 )
goto V_69;
V_27 = F_400 ( V_2 , 0 ) ;
V_69:
F_241 ( V_83 , V_33 ) ;
return V_27 ;
}
int F_402 ( struct V_82 * V_83 ,
struct V_32 * V_33 , T_2 type )
{
T_2 V_514 = F_238 ( V_33 , type ) ;
return F_175 ( V_83 , V_33 , 2 * 1024 * 1024 , V_514 ,
V_313 ) ;
}
static T_2 F_403 ( struct V_97 * V_515 )
{
struct V_1 * V_13 ;
T_2 V_516 = 0 ;
int V_104 ;
F_333 (block_group, groups_list, list) {
F_11 ( & V_13 -> V_49 ) ;
if ( ! V_13 -> V_113 ) {
F_13 ( & V_13 -> V_49 ) ;
continue;
}
if ( V_13 -> V_6 & ( V_268 |
V_269 |
V_267 ) )
V_104 = 2 ;
else
V_104 = 1 ;
V_516 += ( V_13 -> V_20 . V_31 -
F_76 ( & V_13 -> V_112 ) ) *
V_104 ;
F_13 ( & V_13 -> V_49 ) ;
}
return V_516 ;
}
T_2 F_404 ( struct V_96 * V_317 )
{
int V_41 ;
T_2 V_516 = 0 ;
F_11 ( & V_317 -> V_49 ) ;
for( V_41 = 0 ; V_41 < V_272 ; V_41 ++ )
if ( ! F_167 ( & V_317 -> V_273 [ V_41 ] ) )
V_516 += F_403 (
& V_317 -> V_273 [ V_41 ] ) ;
F_13 ( & V_317 -> V_49 ) ;
return V_516 ;
}
void F_405 ( struct V_32 * V_33 ,
struct V_1 * V_2 )
{
struct V_96 * V_317 = V_2 -> V_99 ;
T_2 V_34 ;
F_22 ( ! V_2 -> V_113 ) ;
F_11 ( & V_317 -> V_49 ) ;
F_11 ( & V_2 -> V_49 ) ;
V_34 = V_2 -> V_20 . V_31 - V_2 -> V_9 - V_2 -> V_8 -
V_2 -> V_44 - F_76 ( & V_2 -> V_112 ) ;
V_317 -> V_277 -= V_34 ;
V_2 -> V_113 = 0 ;
F_13 ( & V_2 -> V_49 ) ;
F_13 ( & V_317 -> V_49 ) ;
}
int F_406 ( struct V_32 * V_33 , T_2 V_25 )
{
struct V_1 * V_13 ;
struct V_96 * V_99 ;
struct V_517 * V_298 = V_33 -> V_35 -> V_298 ;
struct V_518 * V_519 ;
T_2 V_520 ;
T_2 V_521 = 1 ;
T_2 V_522 = 0 ;
T_2 V_292 ;
int V_432 ;
int V_102 = 0 ;
int V_27 = 0 ;
V_13 = F_65 ( V_33 -> V_35 , V_25 ) ;
if ( ! V_13 )
return - 1 ;
V_520 = F_76 ( & V_13 -> V_112 ) ;
if ( ! V_520 )
goto V_69;
V_99 = V_13 -> V_99 ;
F_11 ( & V_99 -> V_49 ) ;
V_102 = V_99 -> V_102 ;
if ( ( V_99 -> V_265 != V_13 -> V_20 . V_31 ) &&
( V_99 -> V_266 + V_99 -> V_276 +
V_99 -> V_275 + V_99 -> V_277 +
V_520 < V_99 -> V_265 ) ) {
F_13 ( & V_99 -> V_49 ) ;
goto V_69;
}
F_13 ( & V_99 -> V_49 ) ;
V_27 = - 1 ;
V_292 = F_235 ( V_33 -> V_35 , V_13 -> V_6 ) ;
if ( V_292 ) {
V_432 = F_329 ( F_237 ( V_292 ) ) ;
} else {
if ( V_102 )
goto V_69;
V_432 = F_330 ( V_13 ) ;
}
if ( V_432 == 0 ) {
V_521 = 4 ;
V_520 >>= 1 ;
} else if ( V_432 == 1 ) {
V_521 = 2 ;
} else if ( V_432 == 2 ) {
V_520 <<= 1 ;
} else if ( V_432 == 3 ) {
V_521 = V_298 -> V_299 ;
F_72 ( V_520 , V_521 ) ;
}
F_34 ( & V_33 -> V_35 -> V_332 ) ;
F_333 (device, &fs_devices->alloc_list, dev_alloc_list) {
T_2 V_523 ;
if ( V_519 -> V_265 > V_519 -> V_266 + V_520 ) {
V_27 = F_407 ( V_519 , V_520 ,
& V_523 , NULL ) ;
if ( ! V_27 )
V_522 ++ ;
if ( V_522 >= V_521 )
break;
V_27 = - 1 ;
}
}
F_45 ( & V_33 -> V_35 -> V_332 ) ;
V_69:
F_6 ( V_13 ) ;
return V_27 ;
}
static int F_408 ( struct V_32 * V_33 ,
struct V_61 * V_62 , struct V_65 * V_20 )
{
int V_27 = 0 ;
struct V_65 V_140 ;
struct V_63 * V_64 ;
int V_486 ;
V_27 = F_36 ( NULL , V_33 , V_20 , V_62 , 0 , 0 ) ;
if ( V_27 < 0 )
goto V_69;
while ( 1 ) {
V_486 = V_62 -> V_79 [ 0 ] ;
V_64 = V_62 -> V_78 [ 0 ] ;
if ( V_486 >= F_37 ( V_64 ) ) {
V_27 = F_42 ( V_33 , V_62 ) ;
if ( V_27 == 0 )
continue;
if ( V_27 < 0 )
goto V_69;
break;
}
F_39 ( V_64 , & V_140 , V_486 ) ;
if ( V_140 . V_21 >= V_20 -> V_21 &&
V_140 . type == V_176 ) {
V_27 = 0 ;
goto V_69;
}
V_62 -> V_79 [ 0 ] ++ ;
}
V_69:
return V_27 ;
}
void F_409 ( struct V_11 * V_12 )
{
struct V_1 * V_13 ;
T_2 V_67 = 0 ;
while ( 1 ) {
struct V_247 * V_247 ;
V_13 = F_64 ( V_12 , V_67 ) ;
while ( V_13 ) {
F_11 ( & V_13 -> V_49 ) ;
if ( V_13 -> V_163 )
break;
F_13 ( & V_13 -> V_49 ) ;
V_13 = F_211 ( V_12 -> V_230 ,
V_13 ) ;
}
if ( ! V_13 ) {
if ( V_67 == 0 )
break;
V_67 = 0 ;
continue;
}
V_247 = V_13 -> V_247 ;
V_13 -> V_163 = 0 ;
V_13 -> V_247 = NULL ;
F_13 ( & V_13 -> V_49 ) ;
F_225 ( V_247 ) ;
V_67 = V_13 -> V_20 . V_21 + V_13 -> V_20 . V_31 ;
F_6 ( V_13 ) ;
}
}
int F_410 ( struct V_11 * V_12 )
{
struct V_1 * V_13 ;
struct V_96 * V_99 ;
struct V_47 * V_51 ;
struct V_14 * V_28 ;
F_60 ( & V_12 -> V_76 ) ;
while ( ! F_167 ( & V_12 -> V_94 ) ) {
V_51 = F_168 ( V_12 -> V_94 . V_216 ,
struct V_47 , V_86 ) ;
F_411 ( & V_51 -> V_86 ) ;
F_26 ( V_51 ) ;
}
F_62 ( & V_12 -> V_76 ) ;
F_11 ( & V_12 -> V_17 ) ;
while ( ( V_28 = F_412 ( & V_12 -> V_18 ) ) != NULL ) {
V_13 = F_12 ( V_28 , struct V_1 ,
V_19 ) ;
F_174 ( & V_13 -> V_19 ,
& V_12 -> V_18 ) ;
F_13 ( & V_12 -> V_17 ) ;
F_60 ( & V_13 -> V_99 -> V_274 ) ;
F_411 ( & V_13 -> V_86 ) ;
F_62 ( & V_13 -> V_99 -> V_274 ) ;
if ( V_13 -> V_3 == V_50 )
F_328 ( V_13 ) ;
if ( V_13 -> V_3 == V_90 )
F_19 ( V_12 -> V_60 , V_13 ) ;
F_413 ( V_13 ) ;
F_6 ( V_13 ) ;
F_11 ( & V_12 -> V_17 ) ;
}
F_13 ( & V_12 -> V_17 ) ;
F_414 () ;
F_286 ( V_12 ) ;
while( ! F_167 ( & V_12 -> V_99 ) ) {
V_99 = F_168 ( V_12 -> V_99 . V_216 ,
struct V_96 ,
V_86 ) ;
if ( V_99 -> V_275 > 0 ||
V_99 -> V_276 > 0 ||
V_99 -> V_278 > 0 ) {
F_8 ( 1 ) ;
F_252 ( V_99 , 0 , 0 ) ;
}
F_411 ( & V_99 -> V_86 ) ;
F_9 ( V_99 ) ;
}
return 0 ;
}
static void F_415 ( struct V_96 * V_99 ,
struct V_1 * V_2 )
{
int V_432 = F_330 ( V_2 ) ;
F_60 ( & V_99 -> V_274 ) ;
F_61 ( & V_2 -> V_86 , & V_99 -> V_273 [ V_432 ] ) ;
F_62 ( & V_99 -> V_274 ) ;
}
int F_416 ( struct V_32 * V_33 )
{
struct V_61 * V_62 ;
int V_27 ;
struct V_1 * V_2 ;
struct V_11 * V_12 = V_33 -> V_35 ;
struct V_96 * V_99 ;
struct V_65 V_20 ;
struct V_65 V_140 ;
struct V_63 * V_64 ;
int V_524 = 0 ;
T_2 V_525 ;
V_33 = V_12 -> V_60 ;
V_20 . V_21 = 0 ;
V_20 . V_31 = 0 ;
F_78 ( & V_20 , V_176 ) ;
V_62 = F_32 () ;
if ( ! V_62 )
return - V_85 ;
V_62 -> V_72 = 1 ;
V_525 = F_417 ( V_33 -> V_35 -> V_326 ) ;
if ( F_251 ( V_33 , V_409 ) &&
F_418 ( V_33 -> V_35 -> V_326 ) != V_525 )
V_524 = 1 ;
if ( F_251 ( V_33 , V_526 ) )
V_524 = 1 ;
while ( 1 ) {
V_27 = F_408 ( V_33 , V_62 , & V_20 ) ;
if ( V_27 > 0 )
break;
if ( V_27 != 0 )
goto error;
V_64 = V_62 -> V_78 [ 0 ] ;
F_39 ( V_64 , & V_140 , V_62 -> V_79 [ 0 ] ) ;
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
F_231 ( & V_2 -> V_49 ) ;
V_2 -> V_35 = V_12 ;
F_52 ( & V_2 -> V_86 ) ;
F_52 ( & V_2 -> V_527 ) ;
if ( V_524 )
V_2 -> V_253 = V_261 ;
F_419 ( V_64 , & V_2 -> V_112 ,
F_209 ( V_64 , V_62 -> V_79 [ 0 ] ) ,
sizeof( V_2 -> V_112 ) ) ;
memcpy ( & V_2 -> V_20 , & V_140 , sizeof( V_140 ) ) ;
V_20 . V_21 = V_140 . V_21 + V_140 . V_31 ;
F_43 ( V_62 ) ;
V_2 -> V_6 = F_420 ( & V_2 -> V_112 ) ;
V_2 -> V_308 = V_33 -> V_308 ;
F_421 ( V_2 ) ;
F_21 ( V_33 , V_2 ) ;
if ( V_140 . V_31 == F_76 ( & V_2 -> V_112 ) ) {
V_2 -> V_93 = ( T_2 ) - 1 ;
V_2 -> V_3 = V_4 ;
F_19 ( V_33 , V_2 ) ;
} else if ( F_76 ( & V_2 -> V_112 ) == 0 ) {
V_2 -> V_93 = ( T_2 ) - 1 ;
V_2 -> V_3 = V_4 ;
F_27 ( V_2 , V_33 -> V_35 ,
V_140 . V_21 ,
V_140 . V_21 +
V_140 . V_31 ) ;
F_19 ( V_33 , V_2 ) ;
}
V_27 = F_229 ( V_12 , V_2 -> V_6 , V_140 . V_31 ,
F_76 ( & V_2 -> V_112 ) ,
& V_99 ) ;
F_22 ( V_27 ) ;
V_2 -> V_99 = V_99 ;
F_11 ( & V_2 -> V_99 -> V_49 ) ;
V_2 -> V_99 -> V_277 += V_2 -> V_44 ;
F_13 ( & V_2 -> V_99 -> V_49 ) ;
F_415 ( V_99 , V_2 ) ;
V_27 = F_10 ( V_33 -> V_35 , V_2 ) ;
F_22 ( V_27 ) ;
F_233 ( V_33 -> V_35 , V_2 -> V_6 ) ;
if ( F_422 ( V_33 , V_2 -> V_20 . V_21 ) )
F_400 ( V_2 , 1 ) ;
}
F_68 (space_info, &root->fs_info->space_info, list) {
if ( ! ( F_238 ( V_33 , V_99 -> V_6 ) &
( V_269 |
V_268 |
V_267 ) ) )
continue;
F_333 (cache, &space_info->block_groups[3], list)
F_400 ( V_2 , 1 ) ;
F_333 (cache, &space_info->block_groups[4], list)
F_400 ( V_2 , 1 ) ;
}
F_285 ( V_12 ) ;
V_27 = 0 ;
error:
F_48 ( V_62 ) ;
return V_27 ;
}
int F_423 ( struct V_82 * V_83 ,
struct V_32 * V_33 , T_2 V_266 ,
T_2 type , T_2 V_528 , T_2 V_529 ,
T_2 V_54 )
{
int V_27 ;
struct V_32 * V_60 ;
struct V_1 * V_2 ;
V_60 = V_33 -> V_35 -> V_60 ;
V_33 -> V_35 -> V_530 = V_83 -> V_256 ;
V_2 = F_51 ( sizeof( * V_2 ) , V_38 ) ;
if ( ! V_2 )
return - V_85 ;
V_2 -> V_10 = F_51 ( sizeof( * V_2 -> V_10 ) ,
V_38 ) ;
if ( ! V_2 -> V_10 ) {
F_9 ( V_2 ) ;
return - V_85 ;
}
V_2 -> V_20 . V_21 = V_529 ;
V_2 -> V_20 . V_31 = V_54 ;
V_2 -> V_20 . type = V_176 ;
V_2 -> V_308 = V_33 -> V_308 ;
V_2 -> V_35 = V_33 -> V_35 ;
F_55 ( & V_2 -> V_7 , 1 ) ;
F_231 ( & V_2 -> V_49 ) ;
F_52 ( & V_2 -> V_86 ) ;
F_52 ( & V_2 -> V_527 ) ;
F_421 ( V_2 ) ;
F_304 ( & V_2 -> V_112 , V_266 ) ;
F_424 ( & V_2 -> V_112 , V_528 ) ;
V_2 -> V_6 = type ;
F_425 ( & V_2 -> V_112 , type ) ;
V_2 -> V_93 = ( T_2 ) - 1 ;
V_2 -> V_3 = V_4 ;
F_21 ( V_33 , V_2 ) ;
F_27 ( V_2 , V_33 -> V_35 , V_529 ,
V_529 + V_54 ) ;
F_19 ( V_33 , V_2 ) ;
V_27 = F_229 ( V_33 -> V_35 , V_2 -> V_6 , V_54 , V_266 ,
& V_2 -> V_99 ) ;
F_22 ( V_27 ) ;
F_284 ( V_33 -> V_35 ) ;
F_11 ( & V_2 -> V_99 -> V_49 ) ;
V_2 -> V_99 -> V_277 += V_2 -> V_44 ;
F_13 ( & V_2 -> V_99 -> V_49 ) ;
F_415 ( V_2 -> V_99 , V_2 ) ;
V_27 = F_10 ( V_33 -> V_35 , V_2 ) ;
F_22 ( V_27 ) ;
V_27 = F_426 ( V_83 , V_60 , & V_2 -> V_20 , & V_2 -> V_112 ,
sizeof( V_2 -> V_112 ) ) ;
if ( V_27 ) {
F_151 ( V_83 , V_60 , V_27 ) ;
return V_27 ;
}
F_233 ( V_60 -> V_35 , type ) ;
return 0 ;
}
static void F_427 ( struct V_11 * V_35 , T_2 V_6 )
{
T_2 V_282 = F_234 ( V_6 ) &
V_283 ;
if ( V_6 & V_284 )
V_35 -> V_285 &= ~ V_282 ;
if ( V_6 & V_114 )
V_35 -> V_286 &= ~ V_282 ;
if ( V_6 & V_287 )
V_35 -> V_288 &= ~ V_282 ;
}
int F_428 ( struct V_82 * V_83 ,
struct V_32 * V_33 , T_2 V_109 )
{
struct V_61 * V_62 ;
struct V_1 * V_13 ;
struct V_436 * V_213 ;
struct V_32 * V_230 = V_33 -> V_35 -> V_230 ;
struct V_65 V_20 ;
struct V_247 * V_247 ;
int V_27 ;
int V_432 ;
int V_104 ;
V_33 = V_33 -> V_35 -> V_60 ;
V_13 = F_65 ( V_33 -> V_35 , V_109 ) ;
F_22 ( ! V_13 ) ;
F_22 ( ! V_13 -> V_113 ) ;
F_19 ( V_33 , V_13 ) ;
memcpy ( & V_20 , & V_13 -> V_20 , sizeof( V_20 ) ) ;
V_432 = F_330 ( V_13 ) ;
if ( V_13 -> V_6 & ( V_267 |
V_268 |
V_269 ) )
V_104 = 2 ;
else
V_104 = 1 ;
V_213 = & V_33 -> V_35 -> V_452 ;
F_11 ( & V_213 -> V_457 ) ;
F_337 ( V_13 , V_213 ) ;
F_13 ( & V_213 -> V_457 ) ;
V_213 = & V_33 -> V_35 -> V_450 ;
F_11 ( & V_213 -> V_457 ) ;
F_337 ( V_13 , V_213 ) ;
F_13 ( & V_213 -> V_457 ) ;
V_62 = F_32 () ;
if ( ! V_62 ) {
V_27 = - V_85 ;
goto V_69;
}
V_247 = F_213 ( V_230 , V_13 , V_62 ) ;
if ( ! F_214 ( V_247 ) ) {
V_27 = F_429 ( V_83 , V_247 ) ;
if ( V_27 ) {
F_430 ( V_247 ) ;
goto V_69;
}
F_431 ( V_247 ) ;
F_11 ( & V_13 -> V_49 ) ;
if ( V_13 -> V_163 ) {
V_13 -> V_163 = 0 ;
V_13 -> V_247 = NULL ;
F_13 ( & V_13 -> V_49 ) ;
F_225 ( V_247 ) ;
} else {
F_13 ( & V_13 -> V_49 ) ;
}
F_430 ( V_247 ) ;
}
V_20 . V_21 = V_531 ;
V_20 . V_31 = V_13 -> V_20 . V_21 ;
V_20 . type = 0 ;
V_27 = F_36 ( V_83 , V_230 , & V_20 , V_62 , - 1 , 1 ) ;
if ( V_27 < 0 )
goto V_69;
if ( V_27 > 0 )
F_43 ( V_62 ) ;
if ( V_27 == 0 ) {
V_27 = F_119 ( V_83 , V_230 , V_62 ) ;
if ( V_27 )
goto V_69;
F_43 ( V_62 ) ;
}
F_11 ( & V_33 -> V_35 -> V_17 ) ;
F_174 ( & V_13 -> V_19 ,
& V_33 -> V_35 -> V_18 ) ;
F_13 ( & V_33 -> V_35 -> V_17 ) ;
F_60 ( & V_13 -> V_99 -> V_274 ) ;
F_172 ( & V_13 -> V_86 ) ;
if ( F_167 ( & V_13 -> V_99 -> V_273 [ V_432 ] ) )
F_427 ( V_33 -> V_35 , V_13 -> V_6 ) ;
F_62 ( & V_13 -> V_99 -> V_274 ) ;
if ( V_13 -> V_3 == V_50 )
F_328 ( V_13 ) ;
F_413 ( V_13 ) ;
F_11 ( & V_13 -> V_99 -> V_49 ) ;
V_13 -> V_99 -> V_265 -= V_13 -> V_20 . V_31 ;
V_13 -> V_99 -> V_277 -= V_13 -> V_20 . V_31 ;
V_13 -> V_99 -> V_270 -= V_13 -> V_20 . V_31 * V_104 ;
F_13 ( & V_13 -> V_99 -> V_49 ) ;
memcpy ( & V_20 , & V_13 -> V_20 , sizeof( V_20 ) ) ;
F_70 ( V_33 -> V_35 ) ;
F_6 ( V_13 ) ;
F_6 ( V_13 ) ;
V_27 = F_36 ( V_83 , V_33 , & V_20 , V_62 , - 1 , 1 ) ;
if ( V_27 > 0 )
V_27 = - V_211 ;
if ( V_27 < 0 )
goto V_69;
V_27 = F_119 ( V_83 , V_33 , V_62 ) ;
V_69:
F_48 ( V_62 ) ;
return V_27 ;
}
int F_432 ( struct V_11 * V_35 )
{
struct V_96 * V_99 ;
struct V_532 * V_533 ;
T_2 V_534 ;
T_2 V_6 ;
int V_535 = 0 ;
int V_27 ;
V_533 = V_35 -> V_326 ;
if ( ! F_433 ( V_533 ) )
return 1 ;
V_534 = F_434 ( V_533 ) ;
if ( V_534 & V_536 )
V_535 = 1 ;
V_6 = V_287 ;
V_27 = F_229 ( V_35 , V_6 , 0 , 0 , & V_99 ) ;
if ( V_27 )
goto V_69;
if ( V_535 ) {
V_6 = V_114 | V_284 ;
V_27 = F_229 ( V_35 , V_6 , 0 , 0 , & V_99 ) ;
} else {
V_6 = V_114 ;
V_27 = F_229 ( V_35 , V_6 , 0 , 0 , & V_99 ) ;
if ( V_27 )
goto V_69;
V_6 = V_284 ;
V_27 = F_229 ( V_35 , V_6 , 0 , 0 , & V_99 ) ;
}
V_69:
return V_27 ;
}
int F_435 ( struct V_32 * V_33 , T_2 V_30 , T_2 V_29 )
{
return F_313 ( V_33 , V_30 , V_29 ) ;
}
int F_436 ( struct V_32 * V_33 , T_2 V_25 ,
T_2 V_34 , T_2 * V_184 )
{
return F_145 ( V_33 , V_25 , V_34 , V_184 ) ;
}
int F_437 ( struct V_32 * V_33 , struct V_537 * V_538 )
{
struct V_11 * V_35 = V_33 -> V_35 ;
struct V_1 * V_2 = NULL ;
T_2 V_539 ;
T_2 V_30 ;
T_2 V_29 ;
T_2 V_540 = 0 ;
T_2 V_265 = F_247 ( V_35 -> V_326 ) ;
int V_27 = 0 ;
if ( V_538 -> V_115 == V_265 )
V_2 = F_64 ( V_35 , V_538 -> V_30 ) ;
else
V_2 = F_65 ( V_35 , V_538 -> V_30 ) ;
while ( V_2 ) {
if ( V_2 -> V_20 . V_21 >= ( V_538 -> V_30 + V_538 -> V_115 ) ) {
F_6 ( V_2 ) ;
break;
}
V_30 = F_75 ( V_538 -> V_30 , V_2 -> V_20 . V_21 ) ;
V_29 = F_257 ( V_538 -> V_30 + V_538 -> V_115 ,
V_2 -> V_20 . V_21 + V_2 -> V_20 . V_31 ) ;
if ( V_29 - V_30 >= V_538 -> V_541 ) {
if ( ! F_1 ( V_2 ) ) {
V_27 = F_49 ( V_2 , NULL , V_33 , 0 ) ;
if ( ! V_27 )
F_328 ( V_2 ) ;
}
V_27 = F_438 ( V_2 ,
& V_539 ,
V_30 ,
V_29 ,
V_538 -> V_541 ) ;
V_540 += V_539 ;
if ( V_27 ) {
F_6 ( V_2 ) ;
break;
}
}
V_2 = F_211 ( V_35 -> V_230 , V_2 ) ;
}
V_538 -> V_115 = V_540 ;
return V_27 ;
}
