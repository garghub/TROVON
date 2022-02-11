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
unsigned long V_123 ,
struct V_97 * V_223 )
{
F_13 ( & V_119 -> V_49 ) ;
F_178 ( L_3 ,
V_123 , V_223 ) ;
F_179 ( V_119 -> V_224 ,
V_123 != V_119 -> V_221 ||
V_119 -> V_225 . V_216 != V_223 ) ;
F_178 ( L_4 ,
V_119 -> V_221 , V_119 -> V_225 . V_216 ) ;
F_11 ( & V_119 -> V_49 ) ;
}
int F_180 ( struct V_82 * V_83 ,
struct V_32 * V_33 , unsigned long V_7 )
{
struct V_14 * V_130 ;
struct V_118 * V_119 ;
struct V_202 * V_151 ;
struct V_97 V_213 ;
struct V_97 * V_223 = NULL ;
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
V_223 = V_33 -> V_35 -> V_232 . V_216 ;
} else {
F_177 ( V_119 ,
V_123 , V_223 ) ;
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
struct V_204 * V_233 ;
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
goto V_234;
V_151 = F_12 ( V_130 , struct V_202 , V_14 ) ;
if ( V_151 -> V_25 != V_25 )
goto V_234;
V_27 = 1 ;
if ( V_151 -> type != V_155 )
goto V_234;
V_233 = F_153 ( V_151 ) ;
V_130 = F_190 ( V_130 ) ;
if ( V_130 ) {
V_151 = F_12 ( V_130 , struct V_202 , V_14 ) ;
if ( V_151 -> V_25 == V_25 )
goto V_234;
}
if ( V_233 -> V_33 != V_33 -> V_235 . V_21 ||
V_233 -> V_21 != V_21 || V_233 -> V_31 != V_31 )
goto V_234;
V_27 = 0 ;
V_234:
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
F_193 ( & V_33 -> V_236 ) )
goto V_69;
V_163 = (struct V_162 * ) ( V_121 + 1 ) ;
if ( F_122 ( V_64 , V_163 ) !=
V_155 )
goto V_69;
V_151 = (struct V_150 * ) ( & V_163 -> V_31 ) ;
if ( F_82 ( V_64 , V_121 ) !=
F_116 ( V_64 , V_151 ) ||
F_103 ( V_64 , V_151 ) !=
V_33 -> V_235 . V_21 ||
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
int V_237 ;
V_62 = F_32 () ;
if ( ! V_62 )
return - V_153 ;
do {
V_27 = F_191 ( V_83 , V_33 , V_62 , V_21 ,
V_31 , V_25 ) ;
if ( V_27 && V_27 != - V_153 )
goto V_69;
V_237 = F_189 ( V_83 , V_33 , V_62 , V_21 ,
V_31 , V_25 ) ;
} while ( V_237 == - V_175 );
if ( V_237 && V_237 != - V_153 ) {
V_27 = V_237 ;
goto V_69;
}
if ( V_27 != - V_153 || V_237 != - V_153 )
V_27 = 0 ;
V_69:
F_48 ( V_62 ) ;
if ( V_33 -> V_235 . V_21 == V_238 )
F_8 ( V_27 > 0 ) ;
return V_27 ;
}
static int F_195 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_63 * V_239 ,
int V_240 , int V_241 , int V_198 )
{
T_2 V_25 ;
T_2 V_34 ;
T_2 V_16 ;
T_2 V_206 ;
T_3 V_68 ;
struct V_65 V_20 ;
struct V_242 * V_243 ;
int V_41 ;
int V_166 ;
int V_27 = 0 ;
int (* F_196)( struct V_82 * , struct V_32 * ,
T_2 , T_2 , T_2 , T_2 , T_2 , T_2 , int );
V_206 = F_197 ( V_239 ) ;
V_68 = F_37 ( V_239 ) ;
V_166 = F_198 ( V_239 ) ;
if ( ! V_33 -> V_244 && V_166 == 0 )
return 0 ;
if ( V_241 )
F_196 = F_147 ;
else
F_196 = V_245 ;
if ( V_240 )
V_16 = V_239 -> V_30 ;
else
V_16 = 0 ;
for ( V_41 = 0 ; V_41 < V_68 ; V_41 ++ ) {
if ( V_166 == 0 ) {
F_39 ( V_239 , & V_20 , V_41 ) ;
if ( F_199 ( & V_20 ) != V_246 )
continue;
V_243 = F_81 ( V_239 , V_41 ,
struct V_242 ) ;
if ( F_200 ( V_239 , V_243 ) ==
V_247 )
continue;
V_25 = F_201 ( V_239 , V_243 ) ;
if ( V_25 == 0 )
continue;
V_34 = F_202 ( V_239 , V_243 ) ;
V_20 . V_31 -= F_203 ( V_239 , V_243 ) ;
V_27 = F_196 ( V_83 , V_33 , V_25 , V_34 ,
V_16 , V_206 , V_20 . V_21 ,
V_20 . V_31 , V_198 ) ;
if ( V_27 )
goto V_156;
} else {
V_25 = F_204 ( V_239 , V_41 ) ;
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
struct V_63 * V_239 , int V_240 , int V_198 )
{
return F_195 ( V_83 , V_33 , V_239 , V_240 , 1 , V_198 ) ;
}
int F_207 ( struct V_82 * V_83 , struct V_32 * V_33 ,
struct V_63 * V_239 , int V_240 , int V_198 )
{
return F_195 ( V_83 , V_33 , V_239 , V_240 , 0 , V_198 ) ;
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
struct V_248 * V_248 = NULL ;
T_2 V_249 = 0 ;
int V_250 = V_251 ;
int V_252 = 0 ;
int V_253 = 0 ;
int V_27 = 0 ;
if ( V_13 -> V_20 . V_31 < ( 100 * 1024 * 1024 ) ) {
F_11 ( & V_13 -> V_49 ) ;
V_13 -> V_254 = V_255 ;
F_13 ( & V_13 -> V_49 ) ;
return 0 ;
}
V_74:
V_248 = F_213 ( V_33 , V_13 , V_62 ) ;
if ( F_214 ( V_248 ) && F_215 ( V_248 ) != - V_153 ) {
V_27 = F_215 ( V_248 ) ;
F_43 ( V_62 ) ;
goto V_69;
}
if ( F_214 ( V_248 ) ) {
F_22 ( V_253 ) ;
V_253 ++ ;
if ( V_13 -> V_113 )
goto V_125;
V_27 = F_216 ( V_33 , V_83 , V_13 , V_62 ) ;
if ( V_27 )
goto V_125;
goto V_74;
}
if ( V_13 -> V_256 == V_83 -> V_257 &&
F_217 ( V_248 ) ) {
V_250 = V_258 ;
goto V_259;
}
F_218 ( V_248 ) -> V_260 = 0 ;
V_27 = F_219 ( V_83 , V_33 , V_248 ) ;
F_8 ( V_27 ) ;
if ( F_217 ( V_248 ) > 0 ) {
V_27 = F_220 ( V_33 , V_83 , V_62 ,
V_248 ) ;
if ( V_27 )
goto V_259;
}
F_11 ( & V_13 -> V_49 ) ;
if ( V_13 -> V_3 != V_4 ) {
V_250 = V_255 ;
F_13 ( & V_13 -> V_49 ) ;
goto V_259;
}
F_13 ( & V_13 -> V_49 ) ;
V_252 = ( int ) F_221 ( V_13 -> V_20 . V_31 , 1024 * 1024 * 1024 ) ;
if ( ! V_252 )
V_252 = 1 ;
V_252 *= 16 ;
V_252 *= V_261 ;
V_27 = F_222 ( V_248 , V_252 ) ;
if ( V_27 )
goto V_259;
V_27 = F_223 ( V_248 , V_83 , 0 , 0 , V_252 ,
V_252 , V_252 ,
& V_249 ) ;
if ( ! V_27 )
V_250 = V_258 ;
F_224 ( V_248 , V_252 ) ;
V_259:
F_225 ( V_248 ) ;
V_125:
F_43 ( V_62 ) ;
V_69:
F_11 ( & V_13 -> V_49 ) ;
if ( ! V_27 && V_250 == V_258 )
V_13 -> V_256 = V_83 -> V_257 ;
V_13 -> V_254 = V_250 ;
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
if ( V_2 -> V_254 == V_262 )
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
if ( V_2 -> V_254 == V_262 ) {
F_6 ( V_2 ) ;
goto V_74;
}
if ( V_2 -> V_263 )
break;
V_2 = F_211 ( V_33 , V_2 ) ;
}
if ( ! V_2 ) {
if ( V_67 == 0 )
break;
V_67 = 0 ;
continue;
}
if ( V_2 -> V_254 == V_258 )
V_2 -> V_254 = V_264 ;
V_2 -> V_263 = 0 ;
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
if ( V_2 -> V_263 ) {
F_6 ( V_2 ) ;
goto V_74;
}
if ( V_2 -> V_254 == V_264 )
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
if ( ! V_77 && V_2 -> V_254 == V_264 )
V_2 -> V_254 = V_255 ;
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
int V_265 = 0 ;
V_13 = F_65 ( V_33 -> V_35 , V_25 ) ;
if ( ! V_13 || V_13 -> V_113 )
V_265 = 1 ;
if ( V_13 )
F_6 ( V_13 ) ;
return V_265 ;
}
static int F_229 ( struct V_11 * V_12 , T_2 V_6 ,
T_2 V_266 , T_2 V_267 ,
struct V_96 * * V_99 )
{
struct V_96 * V_100 ;
int V_41 ;
int V_104 ;
if ( V_6 & ( V_268 | V_269 |
V_270 ) )
V_104 = 2 ;
else
V_104 = 1 ;
V_100 = F_66 ( V_12 , V_6 ) ;
if ( V_100 ) {
F_11 ( & V_100 -> V_49 ) ;
V_100 -> V_266 += V_266 ;
V_100 -> V_271 += V_266 * V_104 ;
V_100 -> V_267 += V_267 ;
V_100 -> V_272 += V_267 * V_104 ;
V_100 -> V_102 = 0 ;
F_13 ( & V_100 -> V_49 ) ;
* V_99 = V_100 ;
return 0 ;
}
V_100 = F_51 ( sizeof( * V_100 ) , V_38 ) ;
if ( ! V_100 )
return - V_85 ;
for ( V_41 = 0 ; V_41 < V_273 ; V_41 ++ )
F_52 ( & V_100 -> V_274 [ V_41 ] ) ;
F_230 ( & V_100 -> V_275 ) ;
F_231 ( & V_100 -> V_49 ) ;
V_100 -> V_6 = V_6 & V_101 ;
V_100 -> V_266 = V_266 ;
V_100 -> V_271 = V_266 * V_104 ;
V_100 -> V_267 = V_267 ;
V_100 -> V_272 = V_267 * V_104 ;
V_100 -> V_276 = 0 ;
V_100 -> V_277 = 0 ;
V_100 -> V_278 = 0 ;
V_100 -> V_279 = 0 ;
V_100 -> V_102 = 0 ;
V_100 -> V_280 = V_222 ;
V_100 -> V_281 = 0 ;
V_100 -> V_282 = 0 ;
F_54 ( & V_100 -> V_81 ) ;
* V_99 = V_100 ;
F_232 ( & V_100 -> V_86 , & V_12 -> V_99 ) ;
return 0 ;
}
static void F_233 ( struct V_11 * V_35 , T_2 V_6 )
{
T_2 V_283 = F_234 ( V_6 ) &
V_284 ;
if ( V_6 & V_285 )
V_35 -> V_286 |= V_283 ;
if ( V_6 & V_114 )
V_35 -> V_287 |= V_283 ;
if ( V_6 & V_288 )
V_35 -> V_289 |= V_283 ;
}
static T_2 F_235 ( struct V_11 * V_35 , T_2 V_6 )
{
struct V_290 * V_291 = V_35 -> V_292 ;
T_2 V_293 = 0 ;
if ( ! V_291 )
return 0 ;
if ( V_6 & V_285 &&
V_291 -> V_294 . V_6 & V_295 ) {
V_293 = V_285 | V_291 -> V_294 . V_293 ;
} else if ( V_6 & V_288 &&
V_291 -> V_296 . V_6 & V_295 ) {
V_293 = V_288 | V_291 -> V_296 . V_293 ;
} else if ( V_6 & V_114 &&
V_291 -> V_297 . V_6 & V_295 ) {
V_293 = V_114 | V_291 -> V_297 . V_293 ;
}
return V_293 ;
}
T_2 F_236 ( struct V_32 * V_33 , T_2 V_6 )
{
T_2 V_298 = V_33 -> V_35 -> V_299 -> V_300 +
V_33 -> V_35 -> V_299 -> V_301 ;
T_2 V_293 ;
F_11 ( & V_33 -> V_35 -> V_302 ) ;
V_293 = F_235 ( V_33 -> V_35 , V_6 ) ;
if ( V_293 ) {
if ( ( V_6 & V_293 ) & V_284 ) {
F_13 ( & V_33 -> V_35 -> V_302 ) ;
return F_237 ( V_293 ) ;
}
}
F_13 ( & V_33 -> V_35 -> V_302 ) ;
if ( V_298 == 1 )
V_6 &= ~ ( V_269 | V_303 ) ;
if ( V_298 < 4 )
V_6 &= ~ V_270 ;
if ( ( V_6 & V_268 ) &&
( V_6 & ( V_269 |
V_270 ) ) ) {
V_6 &= ~ V_268 ;
}
if ( ( V_6 & V_269 ) &&
( V_6 & V_270 ) ) {
V_6 &= ~ V_269 ;
}
if ( ( V_6 & V_303 ) &&
( ( V_6 & V_269 ) |
( V_6 & V_270 ) |
( V_6 & V_268 ) ) ) {
V_6 &= ~ V_303 ;
}
return F_237 ( V_6 ) ;
}
static T_2 F_238 ( struct V_32 * V_33 , T_2 V_6 )
{
if ( V_6 & V_285 )
V_6 |= V_33 -> V_35 -> V_286 ;
else if ( V_6 & V_288 )
V_6 |= V_33 -> V_35 -> V_289 ;
else if ( V_6 & V_114 )
V_6 |= V_33 -> V_35 -> V_287 ;
return F_236 ( V_33 , V_6 ) ;
}
T_2 F_176 ( struct V_32 * V_33 , int V_294 )
{
T_2 V_6 ;
if ( V_294 )
V_6 = V_285 ;
else if ( V_33 == V_33 -> V_35 -> V_304 )
V_6 = V_288 ;
else
V_6 = V_114 ;
return F_238 ( V_33 , V_6 ) ;
}
void F_239 ( struct V_32 * V_33 , struct V_248 * V_248 )
{
F_218 ( V_248 ) -> V_99 = F_66 ( V_33 -> V_35 ,
V_285 ) ;
}
int F_222 ( struct V_248 * V_248 , T_2 V_305 )
{
struct V_96 * V_306 ;
struct V_32 * V_33 = F_218 ( V_248 ) -> V_33 ;
T_2 V_108 ;
int V_27 = 0 , V_307 = 0 , V_308 = 1 ;
V_305 = ( V_305 + V_33 -> V_309 - 1 ) & ~ ( ( T_2 ) V_33 -> V_309 - 1 ) ;
if ( V_33 == V_33 -> V_35 -> V_230 ||
F_218 ( V_248 ) -> V_310 . V_21 == V_311 ) {
V_308 = 0 ;
V_307 = 1 ;
}
V_306 = F_218 ( V_248 ) -> V_99 ;
if ( ! V_306 )
goto V_312;
V_74:
F_11 ( & V_306 -> V_49 ) ;
V_108 = V_306 -> V_267 + V_306 -> V_277 +
V_306 -> V_276 + V_306 -> V_278 +
V_306 -> V_279 ;
if ( V_108 + V_305 > V_306 -> V_266 ) {
struct V_82 * V_83 ;
if ( ! V_306 -> V_102 && V_308 ) {
T_2 V_313 ;
V_306 -> V_280 = V_314 ;
F_13 ( & V_306 -> V_49 ) ;
V_312:
V_313 = F_176 ( V_33 , 1 ) ;
V_83 = F_240 ( V_33 ) ;
if ( F_214 ( V_83 ) )
return F_215 ( V_83 ) ;
V_27 = F_175 ( V_83 , V_33 -> V_35 -> V_60 ,
V_305 + 2 * 1024 * 1024 ,
V_313 ,
V_222 ) ;
F_241 ( V_83 , V_33 ) ;
if ( V_27 < 0 ) {
if ( V_27 != - V_315 )
return V_27 ;
else
goto V_316;
}
if ( ! V_306 ) {
F_239 ( V_33 , V_248 ) ;
V_306 = F_218 ( V_248 ) -> V_99 ;
}
goto V_74;
}
if ( V_306 -> V_276 < V_305 )
V_307 = 1 ;
F_13 ( & V_306 -> V_49 ) ;
V_316:
if ( ! V_307 &&
! F_242 ( & V_33 -> V_35 -> V_317 ) ) {
V_307 = 1 ;
V_83 = F_240 ( V_33 ) ;
if ( F_214 ( V_83 ) )
return F_215 ( V_83 ) ;
V_27 = F_243 ( V_83 , V_33 ) ;
if ( V_27 )
return V_27 ;
goto V_74;
}
return - V_315 ;
}
V_306 -> V_279 += V_305 ;
F_244 ( V_33 -> V_35 , L_5 ,
V_306 -> V_6 , V_305 , 1 ) ;
F_13 ( & V_306 -> V_49 ) ;
return 0 ;
}
void F_224 ( struct V_248 * V_248 , T_2 V_305 )
{
struct V_32 * V_33 = F_218 ( V_248 ) -> V_33 ;
struct V_96 * V_306 ;
V_305 = ( V_305 + V_33 -> V_309 - 1 ) & ~ ( ( T_2 ) V_33 -> V_309 - 1 ) ;
V_306 = F_218 ( V_248 ) -> V_99 ;
F_11 ( & V_306 -> V_49 ) ;
V_306 -> V_279 -= V_305 ;
F_244 ( V_33 -> V_35 , L_5 ,
V_306 -> V_6 , V_305 , 0 ) ;
F_13 ( & V_306 -> V_49 ) ;
}
static void F_245 ( struct V_11 * V_12 )
{
struct V_97 * V_98 = & V_12 -> V_99 ;
struct V_96 * V_100 ;
F_67 () ;
F_68 (found, head, list) {
if ( V_100 -> V_6 & V_114 )
V_100 -> V_280 = V_314 ;
}
F_69 () ;
}
static int F_246 ( struct V_32 * V_33 ,
struct V_96 * V_318 , T_2 V_319 ,
int V_320 )
{
struct V_321 * V_322 = & V_33 -> V_35 -> V_323 ;
T_2 V_34 = V_318 -> V_266 - V_318 -> V_278 ;
T_2 V_324 = V_318 -> V_267 + V_318 -> V_277 ;
T_2 V_325 ;
if ( V_320 == V_314 )
return 1 ;
V_324 += V_322 -> V_54 ;
if ( V_320 == V_326 ) {
V_325 = F_247 ( V_33 -> V_35 -> V_327 ) ;
V_325 = F_33 ( T_2 , 64 * 1024 * 1024 ,
F_73 ( V_325 , 1 ) ) ;
if ( V_34 - V_324 < V_325 )
return 1 ;
}
V_325 = F_247 ( V_33 -> V_35 -> V_327 ) ;
V_325 = F_33 ( T_2 , 256 * 1024 * 1024 , F_73 ( V_325 , 2 ) ) ;
if ( V_318 -> V_6 & V_288 )
V_325 = 32 * 1024 * 1024 ;
if ( V_34 > V_325 && V_318 -> V_267 < F_71 ( V_34 , 8 ) )
return 0 ;
return 1 ;
}
static T_2 F_248 ( struct V_32 * V_33 , T_2 type )
{
T_2 V_328 ;
if ( type & V_270 ||
type & V_303 )
V_328 = V_33 -> V_35 -> V_299 -> V_300 ;
else if ( type & V_269 )
V_328 = 2 ;
else
V_328 = 1 ;
return F_249 ( V_33 , V_328 + 1 ) ;
}
static void F_250 ( struct V_82 * V_83 ,
struct V_32 * V_33 , T_2 type )
{
struct V_96 * V_12 ;
T_2 V_329 ;
T_2 V_325 ;
V_12 = F_66 ( V_33 -> V_35 , V_288 ) ;
F_11 ( & V_12 -> V_49 ) ;
V_329 = V_12 -> V_266 - V_12 -> V_267 - V_12 -> V_276 -
V_12 -> V_277 - V_12 -> V_278 ;
F_13 ( & V_12 -> V_49 ) ;
V_325 = F_248 ( V_33 , type ) ;
if ( V_329 < V_325 && F_251 ( V_33 , V_330 ) ) {
F_173 ( V_331 L_6 ,
V_329 , V_325 , type ) ;
F_252 ( V_12 , 0 , 0 ) ;
}
if ( V_329 < V_325 ) {
T_2 V_6 ;
V_6 = F_176 ( V_33 -> V_35 -> V_304 , 0 ) ;
F_253 ( V_83 , V_33 , V_6 ) ;
}
}
static int F_175 ( struct V_82 * V_83 ,
struct V_32 * V_60 , T_2 V_319 ,
T_2 V_6 , int V_320 )
{
struct V_96 * V_99 ;
struct V_11 * V_35 = V_60 -> V_35 ;
int V_332 = 0 ;
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
if ( V_320 < V_99 -> V_280 )
V_320 = V_99 -> V_280 ;
if ( V_99 -> V_102 ) {
F_13 ( & V_99 -> V_49 ) ;
return 0 ;
}
if ( ! F_246 ( V_60 , V_99 , V_319 , V_320 ) ) {
F_13 ( & V_99 -> V_49 ) ;
return 0 ;
} else if ( V_99 -> V_281 ) {
V_332 = 1 ;
} else {
V_99 -> V_281 = 1 ;
}
F_13 ( & V_99 -> V_49 ) ;
F_34 ( & V_35 -> V_333 ) ;
if ( V_332 ) {
F_45 ( & V_35 -> V_333 ) ;
V_332 = 0 ;
goto V_74;
}
if ( F_254 ( V_99 ) )
V_6 |= ( V_285 | V_114 ) ;
if ( V_6 & V_285 && V_35 -> V_334 ) {
V_35 -> V_335 ++ ;
if ( ! ( V_35 -> V_335 %
V_35 -> V_334 ) )
F_245 ( V_35 ) ;
}
F_250 ( V_83 , V_60 , V_6 ) ;
V_27 = F_253 ( V_83 , V_60 , V_6 ) ;
if ( V_27 < 0 && V_27 != - V_315 )
goto V_69;
F_11 ( & V_99 -> V_49 ) ;
if ( V_27 )
V_99 -> V_102 = 1 ;
else
V_27 = 1 ;
V_99 -> V_280 = V_222 ;
V_99 -> V_281 = 0 ;
F_13 ( & V_99 -> V_49 ) ;
V_69:
F_45 ( & V_35 -> V_333 ) ;
return V_27 ;
}
static int F_255 ( struct V_32 * V_33 , T_2 V_336 ,
bool V_337 )
{
struct V_321 * V_338 ;
struct V_96 * V_99 ;
struct V_82 * V_83 ;
T_2 V_9 ;
T_2 V_339 ;
T_2 V_340 = 0 ;
long V_341 ;
unsigned long V_342 = ( 2 * 1024 * 1024 ) >> V_343 ;
int V_344 = 0 ;
unsigned long V_80 ;
V_83 = (struct V_82 * ) V_345 -> V_346 ;
V_338 = & V_33 -> V_35 -> V_347 ;
V_99 = V_338 -> V_99 ;
F_2 () ;
V_9 = V_99 -> V_279 ;
V_80 = V_99 -> V_348 ;
if ( V_9 == 0 )
return 0 ;
F_2 () ;
if ( V_33 -> V_35 -> V_349 == 0 ) {
if ( V_83 )
return 0 ;
F_256 ( V_33 , 0 , 0 ) ;
return 0 ;
}
V_339 = F_257 ( V_9 , V_336 ) ;
V_342 = F_33 (unsigned long, nr_pages,
max_reclaim >> PAGE_CACHE_SHIFT) ;
while ( V_344 < 1024 ) {
F_2 () ;
V_342 = F_182 (unsigned long, nr_pages,
root->fs_info->delalloc_bytes >> PAGE_CACHE_SHIFT) ;
F_258 ( V_33 -> V_35 -> V_350 , V_342 ,
V_351 ) ;
F_11 ( & V_99 -> V_49 ) ;
if ( V_9 > V_99 -> V_279 )
V_340 += V_9 - V_99 -> V_279 ;
V_9 = V_99 -> V_279 ;
F_13 ( & V_99 -> V_49 ) ;
V_344 ++ ;
if ( V_9 == 0 || V_340 >= V_339 )
break;
if ( V_83 && V_83 -> V_129 -> V_352 )
return - V_175 ;
if ( V_337 && ! V_83 ) {
F_256 ( V_33 , 0 , 0 ) ;
} else {
V_341 = F_259 ( 1 ) ;
if ( V_341 )
break;
}
if ( V_344 > 3 ) {
F_2 () ;
if ( V_80 != V_99 -> V_348 )
break;
}
}
return V_340 >= V_336 ;
}
static int F_260 ( struct V_32 * V_33 ,
struct V_96 * V_99 ,
T_2 V_305 , int V_320 )
{
struct V_321 * V_353 = & V_33 -> V_35 -> V_354 ;
struct V_82 * V_83 ;
V_83 = (struct V_82 * ) V_345 -> V_346 ;
if ( V_83 )
return - V_175 ;
if ( V_320 )
goto V_355;
F_11 ( & V_99 -> V_49 ) ;
if ( V_99 -> V_276 >= V_305 ) {
F_13 ( & V_99 -> V_49 ) ;
goto V_355;
}
F_13 ( & V_99 -> V_49 ) ;
if ( V_99 != V_353 -> V_99 )
return - V_315 ;
F_11 ( & V_99 -> V_49 ) ;
F_11 ( & V_353 -> V_49 ) ;
if ( V_99 -> V_276 + V_353 -> V_54 < V_305 ) {
F_13 ( & V_353 -> V_49 ) ;
F_13 ( & V_99 -> V_49 ) ;
return - V_315 ;
}
F_13 ( & V_353 -> V_49 ) ;
F_13 ( & V_99 -> V_49 ) ;
V_355:
V_83 = F_240 ( V_33 ) ;
if ( F_214 ( V_83 ) )
return - V_315 ;
return F_243 ( V_83 , V_33 ) ;
}
static int F_261 ( struct V_32 * V_33 ,
struct V_321 * V_338 ,
T_2 V_356 , int V_282 )
{
struct V_96 * V_99 = V_338 -> V_99 ;
T_2 V_108 ;
T_2 V_34 = V_356 ;
int V_253 = 0 ;
int V_27 = 0 ;
bool V_307 = false ;
bool V_357 = false ;
bool V_337 = false ;
V_74:
V_27 = 0 ;
F_11 ( & V_99 -> V_49 ) ;
while ( V_282 && ! V_357 && V_99 -> V_282 ) {
F_13 ( & V_99 -> V_49 ) ;
if ( V_345 -> V_346 )
return - V_175 ;
V_27 = F_262 ( V_99 -> V_81 , ! V_99 -> V_282 ) ;
if ( V_27 )
return - V_358 ;
F_11 ( & V_99 -> V_49 ) ;
}
V_27 = - V_315 ;
V_108 = V_99 -> V_267 + V_99 -> V_277 +
V_99 -> V_276 + V_99 -> V_278 +
V_99 -> V_279 ;
if ( V_108 <= V_99 -> V_266 ) {
if ( V_108 + V_356 <= V_99 -> V_266 ) {
V_99 -> V_279 += V_356 ;
F_244 ( V_33 -> V_35 ,
L_5 , V_99 -> V_6 , V_356 , 1 ) ;
V_27 = 0 ;
} else {
V_34 = V_356 ;
}
} else {
V_337 = true ;
V_34 = V_108 - V_99 -> V_266 +
( V_356 * ( V_253 + 1 ) ) ;
}
if ( V_27 ) {
T_2 V_359 = F_176 ( V_33 , 0 ) ;
T_2 V_360 ;
V_360 = ( V_99 -> V_266 - V_99 -> V_267 ) * 8 ;
F_72 ( V_360 , 10 ) ;
if ( V_99 -> V_276 >= V_360 && V_282 && ! V_307 ) {
V_99 -> V_282 = 1 ;
V_357 = true ;
F_13 ( & V_99 -> V_49 ) ;
V_27 = F_260 ( V_33 , V_99 ,
V_356 , 1 ) ;
if ( V_27 )
goto V_69;
V_307 = true ;
goto V_74;
}
F_11 ( & V_33 -> V_35 -> V_361 ) ;
V_360 = V_33 -> V_35 -> V_362 ;
if ( V_359 & ( V_268 |
V_269 |
V_270 ) )
V_360 >>= 1 ;
if ( V_282 )
V_360 >>= 3 ;
else
V_360 >>= 1 ;
F_13 ( & V_33 -> V_35 -> V_361 ) ;
if ( V_108 + V_34 < V_99 -> V_266 + V_360 ) {
V_99 -> V_279 += V_356 ;
F_244 ( V_33 -> V_35 ,
L_5 , V_99 -> V_6 , V_356 , 1 ) ;
V_27 = 0 ;
} else {
V_337 = true ;
}
}
if ( V_27 && V_282 ) {
V_357 = true ;
V_99 -> V_282 = 1 ;
}
F_13 ( & V_99 -> V_49 ) ;
if ( ! V_27 || ! V_282 )
goto V_69;
V_27 = F_255 ( V_33 , V_34 , V_337 ) ;
if ( V_27 < 0 )
goto V_69;
V_27 = 0 ;
if ( V_253 < 2 ) {
V_337 = true ;
V_253 ++ ;
goto V_74;
}
V_27 = - V_315 ;
if ( V_307 )
goto V_69;
V_27 = F_260 ( V_33 , V_99 , V_356 , 0 ) ;
if ( ! V_27 ) {
V_307 = true ;
goto V_74;
}
V_69:
if ( V_357 ) {
F_11 ( & V_99 -> V_49 ) ;
V_99 -> V_282 = 0 ;
F_263 ( & V_99 -> V_81 ) ;
F_13 ( & V_99 -> V_49 ) ;
}
return V_27 ;
}
static struct V_321 * F_264 (
const struct V_82 * V_83 ,
const struct V_32 * V_33 )
{
struct V_321 * V_338 = NULL ;
if ( V_33 -> V_244 || V_33 == V_33 -> V_35 -> V_363 )
V_338 = V_83 -> V_338 ;
if ( ! V_338 )
V_338 = V_33 -> V_338 ;
if ( ! V_338 )
V_338 = & V_33 -> V_35 -> V_364 ;
return V_338 ;
}
static int F_265 ( struct V_321 * V_338 ,
T_2 V_34 )
{
int V_27 = - V_315 ;
F_11 ( & V_338 -> V_49 ) ;
if ( V_338 -> V_9 >= V_34 ) {
V_338 -> V_9 -= V_34 ;
if ( V_338 -> V_9 < V_338 -> V_54 )
V_338 -> V_102 = 0 ;
V_27 = 0 ;
}
F_13 ( & V_338 -> V_49 ) ;
return V_27 ;
}
static void F_266 ( struct V_321 * V_338 ,
T_2 V_34 , int V_365 )
{
F_11 ( & V_338 -> V_49 ) ;
V_338 -> V_9 += V_34 ;
if ( V_365 )
V_338 -> V_54 += V_34 ;
else if ( V_338 -> V_9 >= V_338 -> V_54 )
V_338 -> V_102 = 1 ;
F_13 ( & V_338 -> V_49 ) ;
}
static void F_267 ( struct V_11 * V_35 ,
struct V_321 * V_338 ,
struct V_321 * V_366 , T_2 V_34 )
{
struct V_96 * V_99 = V_338 -> V_99 ;
F_11 ( & V_338 -> V_49 ) ;
if ( V_34 == ( T_2 ) - 1 )
V_34 = V_338 -> V_54 ;
V_338 -> V_54 -= V_34 ;
if ( V_338 -> V_9 >= V_338 -> V_54 ) {
V_34 = V_338 -> V_9 - V_338 -> V_54 ;
V_338 -> V_9 = V_338 -> V_54 ;
V_338 -> V_102 = 1 ;
} else {
V_34 = 0 ;
}
F_13 ( & V_338 -> V_49 ) ;
if ( V_34 > 0 ) {
if ( V_366 ) {
F_11 ( & V_366 -> V_49 ) ;
if ( ! V_366 -> V_102 ) {
T_2 V_367 ;
V_367 = V_366 -> V_54 - V_366 -> V_9 ;
V_367 = F_257 ( V_34 , V_367 ) ;
V_366 -> V_9 += V_367 ;
if ( V_366 -> V_9 >= V_366 -> V_54 )
V_366 -> V_102 = 1 ;
V_34 -= V_367 ;
}
F_13 ( & V_366 -> V_49 ) ;
}
if ( V_34 ) {
F_11 ( & V_99 -> V_49 ) ;
V_99 -> V_279 -= V_34 ;
F_244 ( V_35 , L_5 ,
V_99 -> V_6 , V_34 , 0 ) ;
V_99 -> V_348 ++ ;
F_13 ( & V_99 -> V_49 ) ;
}
}
}
static int F_268 ( struct V_321 * V_368 ,
struct V_321 * V_369 , T_2 V_34 )
{
int V_27 ;
V_27 = F_265 ( V_368 , V_34 ) ;
if ( V_27 )
return V_27 ;
F_266 ( V_369 , V_34 , 1 ) ;
return 0 ;
}
void F_269 ( struct V_321 * V_370 )
{
memset ( V_370 , 0 , sizeof( * V_370 ) ) ;
F_231 ( & V_370 -> V_49 ) ;
}
struct V_321 * F_270 ( struct V_32 * V_33 )
{
struct V_321 * V_338 ;
struct V_11 * V_35 = V_33 -> V_35 ;
V_338 = F_187 ( sizeof( * V_338 ) , V_38 ) ;
if ( ! V_338 )
return NULL ;
F_269 ( V_338 ) ;
V_338 -> V_99 = F_66 ( V_35 ,
V_114 ) ;
return V_338 ;
}
void F_271 ( struct V_32 * V_33 ,
struct V_321 * V_370 )
{
F_272 ( V_33 , V_370 , ( T_2 ) - 1 ) ;
F_9 ( V_370 ) ;
}
static inline int F_273 ( struct V_32 * V_33 ,
struct V_321 * V_338 ,
T_2 V_34 , int V_282 )
{
int V_27 ;
if ( V_34 == 0 )
return 0 ;
V_27 = F_261 ( V_33 , V_338 , V_34 , V_282 ) ;
if ( ! V_27 ) {
F_266 ( V_338 , V_34 , 1 ) ;
return 0 ;
}
return V_27 ;
}
int F_274 ( struct V_32 * V_33 ,
struct V_321 * V_338 ,
T_2 V_34 )
{
return F_273 ( V_33 , V_338 , V_34 , 1 ) ;
}
int F_275 ( struct V_32 * V_33 ,
struct V_321 * V_338 ,
T_2 V_34 )
{
return F_273 ( V_33 , V_338 , V_34 , 0 ) ;
}
int F_276 ( struct V_32 * V_33 ,
struct V_321 * V_338 , int V_371 )
{
T_2 V_34 = 0 ;
int V_27 = - V_315 ;
if ( ! V_338 )
return 0 ;
F_11 ( & V_338 -> V_49 ) ;
V_34 = F_71 ( V_338 -> V_54 , V_371 ) ;
if ( V_338 -> V_9 >= V_34 )
V_27 = 0 ;
F_13 ( & V_338 -> V_49 ) ;
return V_27 ;
}
static inline int F_277 ( struct V_32 * V_33 ,
struct V_321 * V_338 ,
T_2 V_372 , int V_282 )
{
T_2 V_34 = 0 ;
int V_27 = - V_315 ;
if ( ! V_338 )
return 0 ;
F_11 ( & V_338 -> V_49 ) ;
V_34 = V_372 ;
if ( V_338 -> V_9 >= V_34 )
V_27 = 0 ;
else
V_34 -= V_338 -> V_9 ;
F_13 ( & V_338 -> V_49 ) ;
if ( ! V_27 )
return 0 ;
V_27 = F_261 ( V_33 , V_338 , V_34 , V_282 ) ;
if ( ! V_27 ) {
F_266 ( V_338 , V_34 , 0 ) ;
return 0 ;
}
return V_27 ;
}
int F_278 ( struct V_32 * V_33 ,
struct V_321 * V_338 ,
T_2 V_372 )
{
return F_277 ( V_33 , V_338 , V_372 , 1 ) ;
}
int F_279 ( struct V_32 * V_33 ,
struct V_321 * V_338 ,
T_2 V_372 )
{
return F_277 ( V_33 , V_338 , V_372 , 0 ) ;
}
int F_280 ( struct V_321 * V_373 ,
struct V_321 * V_374 ,
T_2 V_34 )
{
return F_268 ( V_373 , V_374 , V_34 ) ;
}
void F_272 ( struct V_32 * V_33 ,
struct V_321 * V_338 ,
T_2 V_34 )
{
struct V_321 * V_322 = & V_33 -> V_35 -> V_323 ;
if ( V_322 -> V_102 || V_322 == V_338 ||
V_338 -> V_99 != V_322 -> V_99 )
V_322 = NULL ;
F_267 ( V_33 -> V_35 , V_338 , V_322 ,
V_34 ) ;
}
static T_2 F_281 ( struct V_11 * V_35 )
{
struct V_96 * V_318 ;
T_2 V_34 ;
T_2 V_375 ;
T_2 V_376 ;
int V_377 = F_282 ( V_35 -> V_327 ) ;
V_318 = F_66 ( V_35 , V_285 ) ;
F_11 ( & V_318 -> V_49 ) ;
V_376 = V_318 -> V_267 ;
F_13 ( & V_318 -> V_49 ) ;
V_318 = F_66 ( V_35 , V_114 ) ;
F_11 ( & V_318 -> V_49 ) ;
if ( V_318 -> V_6 & V_285 )
V_376 = 0 ;
V_375 = V_318 -> V_267 ;
F_13 ( & V_318 -> V_49 ) ;
V_34 = ( V_376 >> V_35 -> V_350 -> V_378 ) *
V_377 * 2 ;
V_34 += F_221 ( V_376 + V_375 , 50 ) ;
if ( V_34 * 3 > V_375 )
V_34 = F_221 ( V_375 , 3 ) ;
return F_283 ( V_34 , V_35 -> V_60 -> V_379 << 10 ) ;
}
static void F_284 ( struct V_11 * V_35 )
{
struct V_321 * V_338 = & V_35 -> V_323 ;
struct V_96 * V_318 = V_338 -> V_99 ;
T_2 V_34 ;
V_34 = F_281 ( V_35 ) ;
F_11 ( & V_318 -> V_49 ) ;
F_11 ( & V_338 -> V_49 ) ;
V_338 -> V_54 = V_34 ;
V_34 = V_318 -> V_267 + V_318 -> V_276 +
V_318 -> V_277 + V_318 -> V_278 +
V_318 -> V_279 ;
if ( V_318 -> V_266 > V_34 ) {
V_34 = V_318 -> V_266 - V_34 ;
V_338 -> V_9 += V_34 ;
V_318 -> V_279 += V_34 ;
F_244 ( V_35 , L_5 ,
V_318 -> V_6 , V_34 , 1 ) ;
}
if ( V_338 -> V_9 >= V_338 -> V_54 ) {
V_34 = V_338 -> V_9 - V_338 -> V_54 ;
V_318 -> V_279 -= V_34 ;
F_244 ( V_35 , L_5 ,
V_318 -> V_6 , V_34 , 0 ) ;
V_318 -> V_348 ++ ;
V_338 -> V_9 = V_338 -> V_54 ;
V_338 -> V_102 = 1 ;
}
F_13 ( & V_338 -> V_49 ) ;
F_13 ( & V_318 -> V_49 ) ;
}
static void F_285 ( struct V_11 * V_35 )
{
struct V_96 * V_99 ;
V_99 = F_66 ( V_35 , V_288 ) ;
V_35 -> V_380 . V_99 = V_99 ;
V_99 = F_66 ( V_35 , V_114 ) ;
V_35 -> V_323 . V_99 = V_99 ;
V_35 -> V_347 . V_99 = V_99 ;
V_35 -> V_381 . V_99 = V_99 ;
V_35 -> V_364 . V_99 = V_99 ;
V_35 -> V_354 . V_99 = V_99 ;
V_35 -> V_60 -> V_338 = & V_35 -> V_323 ;
V_35 -> V_363 -> V_338 = & V_35 -> V_323 ;
V_35 -> V_382 -> V_338 = & V_35 -> V_323 ;
V_35 -> V_230 -> V_338 = & V_35 -> V_323 ;
V_35 -> V_304 -> V_338 = & V_35 -> V_380 ;
F_284 ( V_35 ) ;
}
static void F_286 ( struct V_11 * V_35 )
{
F_267 ( V_35 , & V_35 -> V_323 , NULL ,
( T_2 ) - 1 ) ;
F_8 ( V_35 -> V_347 . V_54 > 0 ) ;
F_8 ( V_35 -> V_347 . V_9 > 0 ) ;
F_8 ( V_35 -> V_381 . V_54 > 0 ) ;
F_8 ( V_35 -> V_381 . V_9 > 0 ) ;
F_8 ( V_35 -> V_380 . V_54 > 0 ) ;
F_8 ( V_35 -> V_380 . V_9 > 0 ) ;
F_8 ( V_35 -> V_354 . V_54 > 0 ) ;
F_8 ( V_35 -> V_354 . V_9 > 0 ) ;
}
void F_287 ( struct V_82 * V_83 ,
struct V_32 * V_33 )
{
if ( ! V_83 -> V_277 )
return;
F_244 ( V_33 -> V_35 , L_7 ,
V_83 -> V_257 , V_83 -> V_277 , 0 ) ;
F_272 ( V_33 , V_83 -> V_338 , V_83 -> V_277 ) ;
V_83 -> V_277 = 0 ;
}
int F_288 ( struct V_82 * V_83 ,
struct V_248 * V_248 )
{
struct V_32 * V_33 = F_218 ( V_248 ) -> V_33 ;
struct V_321 * V_373 = F_264 ( V_83 , V_33 ) ;
struct V_321 * V_374 = V_33 -> V_383 ;
T_2 V_34 = F_249 ( V_33 , 1 ) ;
F_244 ( V_33 -> V_35 , L_8 ,
F_289 ( V_248 ) , V_34 , 1 ) ;
return F_268 ( V_373 , V_374 , V_34 ) ;
}
void F_290 ( struct V_248 * V_248 )
{
struct V_32 * V_33 = F_218 ( V_248 ) -> V_33 ;
T_2 V_34 = F_249 ( V_33 , 1 ) ;
F_244 ( V_33 -> V_35 , L_8 ,
F_289 ( V_248 ) , V_34 , 0 ) ;
F_272 ( V_33 , V_33 -> V_383 , V_34 ) ;
}
int F_291 ( struct V_82 * V_83 ,
struct V_384 * V_385 )
{
struct V_32 * V_33 = V_385 -> V_33 ;
struct V_321 * V_373 = F_264 ( V_83 , V_33 ) ;
struct V_321 * V_374 = & V_385 -> V_338 ;
T_2 V_34 = F_249 ( V_33 , 5 ) ;
V_374 -> V_99 = V_373 -> V_99 ;
return F_268 ( V_373 , V_374 , V_34 ) ;
}
static unsigned F_292 ( struct V_248 * V_248 )
{
unsigned V_386 = 0 ;
unsigned V_387 = 0 ;
F_22 ( ! F_218 ( V_248 ) -> V_388 ) ;
F_218 ( V_248 ) -> V_388 -- ;
if ( F_218 ( V_248 ) -> V_388 == 0 &&
F_293 ( V_389 ,
& F_218 ( V_248 ) -> V_390 ) )
V_386 = 1 ;
if ( F_218 ( V_248 ) -> V_388 >=
F_218 ( V_248 ) -> V_391 )
return V_386 ;
V_387 = F_218 ( V_248 ) -> V_391 -
F_218 ( V_248 ) -> V_388 ;
F_218 ( V_248 ) -> V_391 -= V_387 ;
return V_387 + V_386 ;
}
static T_2 F_294 ( struct V_248 * V_248 , T_2 V_34 ,
int V_392 )
{
struct V_32 * V_33 = F_218 ( V_248 ) -> V_33 ;
T_2 V_377 ;
int V_393 ;
int V_394 ;
int V_395 ;
if ( F_218 ( V_248 ) -> V_6 & V_396 &&
F_218 ( V_248 ) -> V_397 == 0 )
return 0 ;
V_395 = ( int ) F_221 ( F_218 ( V_248 ) -> V_397 , V_33 -> V_309 ) ;
if ( V_392 )
F_218 ( V_248 ) -> V_397 += V_34 ;
else
F_218 ( V_248 ) -> V_397 -= V_34 ;
V_377 = F_295 ( V_33 ) - sizeof( struct V_398 ) ;
V_393 = ( int ) F_221 ( V_377 ,
sizeof( struct V_399 ) +
sizeof( struct V_400 ) ) ;
V_394 = ( int ) F_221 ( F_218 ( V_248 ) -> V_397 , V_33 -> V_309 ) ;
V_394 = V_394 + V_393 - 1 ;
V_394 = V_394 / V_393 ;
V_395 = V_395 + V_393 - 1 ;
V_395 = V_395 / V_393 ;
if ( V_395 == V_394 )
return 0 ;
if ( V_392 )
return F_249 ( V_33 ,
V_394 - V_395 ) ;
return F_249 ( V_33 , V_395 - V_394 ) ;
}
int F_296 ( struct V_248 * V_248 , T_2 V_34 )
{
struct V_32 * V_33 = F_218 ( V_248 ) -> V_33 ;
struct V_321 * V_338 = & V_33 -> V_35 -> V_347 ;
T_2 V_401 = 0 ;
T_2 V_397 ;
unsigned V_402 = 0 ;
int V_403 = 0 ;
int V_282 = 1 ;
int V_27 ;
if ( F_297 ( V_33 , V_248 ) )
V_282 = 0 ;
if ( V_282 && F_298 ( V_33 -> V_35 ) )
F_185 ( 1 ) ;
F_34 ( & F_218 ( V_248 ) -> V_404 ) ;
V_34 = F_283 ( V_34 , V_33 -> V_309 ) ;
F_11 ( & F_218 ( V_248 ) -> V_49 ) ;
F_218 ( V_248 ) -> V_388 ++ ;
if ( F_218 ( V_248 ) -> V_388 >
F_218 ( V_248 ) -> V_391 )
V_402 = F_218 ( V_248 ) -> V_388 -
F_218 ( V_248 ) -> V_391 ;
if ( ! F_299 ( V_389 ,
& F_218 ( V_248 ) -> V_390 ) ) {
V_402 ++ ;
V_403 = 1 ;
}
V_401 = F_249 ( V_33 , V_402 ) ;
V_401 += F_294 ( V_248 , V_34 , 1 ) ;
V_397 = F_218 ( V_248 ) -> V_397 ;
F_13 ( & F_218 ( V_248 ) -> V_49 ) ;
V_27 = F_261 ( V_33 , V_338 , V_401 , V_282 ) ;
if ( V_27 ) {
T_2 V_405 = 0 ;
unsigned V_406 ;
F_11 ( & F_218 ( V_248 ) -> V_49 ) ;
V_406 = F_292 ( V_248 ) ;
if ( F_218 ( V_248 ) -> V_397 == V_397 )
F_294 ( V_248 , V_34 , 0 ) ;
else
V_405 = F_294 ( V_248 , V_34 , 0 ) ;
F_13 ( & F_218 ( V_248 ) -> V_49 ) ;
if ( V_406 )
V_405 += F_249 ( V_33 , V_406 ) ;
if ( V_405 ) {
F_272 ( V_33 , V_338 , V_405 ) ;
F_244 ( V_33 -> V_35 ,
L_9 ,
F_289 ( V_248 ) ,
V_405 , 0 ) ;
}
F_45 ( & F_218 ( V_248 ) -> V_404 ) ;
return V_27 ;
}
F_11 ( & F_218 ( V_248 ) -> V_49 ) ;
if ( V_403 ) {
F_300 ( V_389 ,
& F_218 ( V_248 ) -> V_390 ) ;
V_402 -- ;
}
F_218 ( V_248 ) -> V_391 += V_402 ;
F_13 ( & F_218 ( V_248 ) -> V_49 ) ;
F_45 ( & F_218 ( V_248 ) -> V_404 ) ;
if ( V_401 )
F_244 ( V_33 -> V_35 , L_9 ,
F_289 ( V_248 ) , V_401 , 1 ) ;
F_266 ( V_338 , V_401 , 1 ) ;
return 0 ;
}
void F_301 ( struct V_248 * V_248 , T_2 V_34 )
{
struct V_32 * V_33 = F_218 ( V_248 ) -> V_33 ;
T_2 V_405 = 0 ;
unsigned V_406 ;
V_34 = F_283 ( V_34 , V_33 -> V_309 ) ;
F_11 ( & F_218 ( V_248 ) -> V_49 ) ;
V_406 = F_292 ( V_248 ) ;
V_405 = F_294 ( V_248 , V_34 , 0 ) ;
F_13 ( & F_218 ( V_248 ) -> V_49 ) ;
if ( V_406 > 0 )
V_405 += F_249 ( V_33 , V_406 ) ;
F_244 ( V_33 -> V_35 , L_9 ,
F_289 ( V_248 ) , V_405 , 0 ) ;
F_272 ( V_33 , & V_33 -> V_35 -> V_347 ,
V_405 ) ;
}
int F_302 ( struct V_248 * V_248 , T_2 V_34 )
{
int V_27 ;
V_27 = F_222 ( V_248 , V_34 ) ;
if ( V_27 )
return V_27 ;
V_27 = F_296 ( V_248 , V_34 ) ;
if ( V_27 ) {
F_224 ( V_248 , V_34 ) ;
return V_27 ;
}
return 0 ;
}
void F_303 ( struct V_248 * V_248 , T_2 V_34 )
{
F_301 ( V_248 , V_34 ) ;
F_224 ( V_248 , V_34 ) ;
}
static int F_304 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
T_2 V_25 , T_2 V_34 , int V_312 )
{
struct V_1 * V_2 = NULL ;
struct V_11 * V_12 = V_33 -> V_35 ;
T_2 V_407 = V_34 ;
T_2 V_408 ;
T_2 V_409 ;
int V_104 ;
F_11 ( & V_12 -> V_410 ) ;
V_408 = F_305 ( V_12 -> V_327 ) ;
if ( V_312 )
V_408 += V_34 ;
else
V_408 -= V_34 ;
F_306 ( V_12 -> V_327 , V_408 ) ;
F_13 ( & V_12 -> V_410 ) ;
while ( V_407 ) {
V_2 = F_65 ( V_12 , V_25 ) ;
if ( ! V_2 )
return - V_153 ;
if ( V_2 -> V_6 & ( V_268 |
V_269 |
V_270 ) )
V_104 = 2 ;
else
V_104 = 1 ;
if ( ! V_312 && V_2 -> V_3 == V_90 )
F_49 ( V_2 , V_83 , NULL , 1 ) ;
V_409 = V_25 - V_2 -> V_20 . V_21 ;
F_8 ( V_409 > V_2 -> V_20 . V_31 ) ;
F_11 ( & V_2 -> V_99 -> V_49 ) ;
F_11 ( & V_2 -> V_49 ) ;
if ( F_251 ( V_33 , V_411 ) &&
V_2 -> V_254 < V_262 )
V_2 -> V_254 = V_262 ;
V_2 -> V_263 = 1 ;
V_408 = F_76 ( & V_2 -> V_112 ) ;
V_34 = F_257 ( V_407 , V_2 -> V_20 . V_31 - V_409 ) ;
if ( V_312 ) {
V_408 += V_34 ;
F_307 ( & V_2 -> V_112 , V_408 ) ;
V_2 -> V_9 -= V_34 ;
V_2 -> V_99 -> V_277 -= V_34 ;
V_2 -> V_99 -> V_267 += V_34 ;
V_2 -> V_99 -> V_272 += V_34 * V_104 ;
F_13 ( & V_2 -> V_49 ) ;
F_13 ( & V_2 -> V_99 -> V_49 ) ;
} else {
V_408 -= V_34 ;
F_307 ( & V_2 -> V_112 , V_408 ) ;
V_2 -> V_8 += V_34 ;
V_2 -> V_99 -> V_276 += V_34 ;
V_2 -> V_99 -> V_267 -= V_34 ;
V_2 -> V_99 -> V_272 -= V_34 * V_104 ;
F_13 ( & V_2 -> V_49 ) ;
F_13 ( & V_2 -> V_99 -> V_49 ) ;
F_308 ( V_12 -> V_56 ,
V_25 , V_25 + V_34 - 1 ,
V_38 | V_412 ) ;
}
F_6 ( V_2 ) ;
V_407 -= V_34 ;
V_25 += V_34 ;
}
return 0 ;
}
static T_2 F_309 ( struct V_32 * V_33 , T_2 V_105 )
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
static int F_310 ( struct V_32 * V_33 ,
struct V_1 * V_2 ,
T_2 V_25 , T_2 V_34 , int V_9 )
{
F_11 ( & V_2 -> V_99 -> V_49 ) ;
F_11 ( & V_2 -> V_49 ) ;
V_2 -> V_8 += V_34 ;
V_2 -> V_99 -> V_276 += V_34 ;
if ( V_9 ) {
V_2 -> V_9 -= V_34 ;
V_2 -> V_99 -> V_277 -= V_34 ;
}
F_13 ( & V_2 -> V_49 ) ;
F_13 ( & V_2 -> V_99 -> V_49 ) ;
F_308 ( V_33 -> V_35 -> V_56 , V_25 ,
V_25 + V_34 - 1 , V_38 | V_412 ) ;
return 0 ;
}
int F_164 ( struct V_32 * V_33 ,
T_2 V_25 , T_2 V_34 , int V_9 )
{
struct V_1 * V_2 ;
V_2 = F_65 ( V_33 -> V_35 , V_25 ) ;
F_22 ( ! V_2 ) ;
F_310 ( V_33 , V_2 , V_25 , V_34 , V_9 ) ;
F_6 ( V_2 ) ;
return 0 ;
}
int F_311 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
T_2 V_25 , T_2 V_34 )
{
struct V_1 * V_2 ;
V_2 = F_65 ( V_33 -> V_35 , V_25 ) ;
F_22 ( ! V_2 ) ;
F_49 ( V_2 , V_83 , V_33 , 1 ) ;
F_310 ( V_33 , V_2 , V_25 , V_34 , 0 ) ;
F_312 ( V_2 , V_25 , V_34 ) ;
F_6 ( V_2 ) ;
return 0 ;
}
static int F_313 ( struct V_1 * V_2 ,
T_2 V_34 , int V_392 )
{
struct V_96 * V_99 = V_2 -> V_99 ;
int V_27 = 0 ;
F_11 ( & V_99 -> V_49 ) ;
F_11 ( & V_2 -> V_49 ) ;
if ( V_392 != V_413 ) {
if ( V_2 -> V_113 ) {
V_27 = - V_175 ;
} else {
V_2 -> V_9 += V_34 ;
V_99 -> V_277 += V_34 ;
if ( V_392 == V_414 ) {
F_244 ( V_2 -> V_35 ,
L_5 , V_99 -> V_6 ,
V_34 , 0 ) ;
V_99 -> V_279 -= V_34 ;
}
}
} else {
if ( V_2 -> V_113 )
V_99 -> V_278 += V_34 ;
V_2 -> V_9 -= V_34 ;
V_99 -> V_277 -= V_34 ;
V_99 -> V_348 ++ ;
}
F_13 ( & V_2 -> V_49 ) ;
F_13 ( & V_99 -> V_49 ) ;
return V_27 ;
}
void F_314 ( struct V_82 * V_83 ,
struct V_32 * V_33 )
{
struct V_11 * V_35 = V_33 -> V_35 ;
struct V_47 * V_216 ;
struct V_47 * V_51 ;
struct V_1 * V_2 ;
F_60 ( & V_35 -> V_76 ) ;
F_315 (caching_ctl, next,
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
static int F_316 ( struct V_32 * V_33 , T_2 V_30 , T_2 V_29 )
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
V_2 -> V_99 -> V_276 -= V_115 ;
if ( V_2 -> V_113 )
V_2 -> V_99 -> V_278 += V_115 ;
F_13 ( & V_2 -> V_49 ) ;
F_13 ( & V_2 -> V_99 -> V_49 ) ;
}
if ( V_2 )
F_6 ( V_2 ) ;
return 0 ;
}
int F_317 ( struct V_82 * V_83 ,
struct V_32 * V_33 )
{
struct V_11 * V_35 = V_33 -> V_35 ;
struct V_415 * V_416 ;
T_2 V_30 ;
T_2 V_29 ;
int V_27 ;
if ( V_83 -> V_210 )
return 0 ;
if ( V_35 -> V_56 == & V_35 -> V_36 [ 0 ] )
V_416 = & V_35 -> V_36 [ 1 ] ;
else
V_416 = & V_35 -> V_36 [ 0 ] ;
while ( 1 ) {
V_27 = F_28 ( V_416 , 0 , & V_30 , & V_29 ,
V_57 ) ;
if ( V_27 )
break;
if ( F_251 ( V_33 , V_417 ) )
V_27 = F_145 ( V_33 , V_30 ,
V_29 + 1 - V_30 , NULL ) ;
F_318 ( V_416 , V_30 , V_29 , V_38 ) ;
F_316 ( V_33 , V_30 , V_29 ) ;
F_46 () ;
}
return 0 ;
}
static int F_155 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
T_2 V_25 , T_2 V_34 , T_2 V_16 ,
T_2 V_146 , T_2 V_418 ,
T_2 V_419 , int V_159 ,
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
int V_420 = 0 ;
int V_421 = 0 ;
int V_422 = 1 ;
T_3 V_122 ;
T_2 V_116 ;
V_62 = F_32 () ;
if ( ! V_62 )
return - V_85 ;
V_62 -> V_72 = 1 ;
V_62 -> V_201 = 1 ;
V_181 = V_418 >= V_143 ;
F_22 ( ! V_181 && V_159 != 1 ) ;
V_27 = F_137 ( V_83 , V_60 , V_62 , & V_163 ,
V_25 , V_34 , V_16 ,
V_146 , V_418 ,
V_419 ) ;
if ( V_27 == 0 ) {
V_420 = V_62 -> V_79 [ 0 ] ;
while ( V_420 >= 0 ) {
F_39 ( V_62 -> V_78 [ 0 ] , & V_20 ,
V_420 ) ;
if ( V_20 . V_21 != V_25 )
break;
if ( V_20 . type == V_73 &&
V_20 . V_31 == V_34 ) {
V_421 = 1 ;
break;
}
if ( V_62 -> V_79 [ 0 ] - V_420 > 5 )
break;
V_420 -- ;
}
#ifdef F_84
V_122 = F_80 ( V_62 -> V_78 [ 0 ] , V_420 ) ;
if ( V_421 && V_122 < sizeof( * V_121 ) )
V_421 = 0 ;
#endif
if ( ! V_421 ) {
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
F_173 ( V_423 L_10
L_11 , V_27 ,
( unsigned long long ) V_25 ) ;
if ( V_27 > 0 )
F_319 ( V_60 ,
V_62 -> V_78 [ 0 ] ) ;
}
if ( V_27 < 0 )
goto abort;
V_420 = V_62 -> V_79 [ 0 ] ;
}
} else if ( V_27 == - V_153 ) {
F_319 ( V_60 , V_62 -> V_78 [ 0 ] ) ;
F_8 ( 1 ) ;
F_173 ( V_423 L_12
L_13 ,
( unsigned long long ) V_25 ,
( unsigned long long ) V_16 ,
( unsigned long long ) V_146 ,
( unsigned long long ) V_418 ,
( unsigned long long ) V_419 ) ;
} else {
goto abort;
}
V_64 = V_62 -> V_78 [ 0 ] ;
V_122 = F_80 ( V_64 , V_420 ) ;
#ifdef F_84
if ( V_122 < sizeof( * V_121 ) ) {
F_22 ( V_421 || V_420 != V_62 -> V_79 [ 0 ] ) ;
V_27 = F_90 ( V_83 , V_60 , V_62 ,
V_418 , 0 ) ;
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
F_173 ( V_423 L_10
L_11 , V_27 ,
( unsigned long long ) V_25 ) ;
F_319 ( V_60 , V_62 -> V_78 [ 0 ] ) ;
}
if ( V_27 < 0 )
goto abort;
V_420 = V_62 -> V_79 [ 0 ] ;
V_64 = V_62 -> V_78 [ 0 ] ;
V_122 = F_80 ( V_64 , V_420 ) ;
}
#endif
F_22 ( V_122 < sizeof( * V_121 ) ) ;
V_121 = F_81 ( V_64 , V_420 ,
struct V_120 ) ;
if ( V_418 < V_143 ) {
struct V_138 * V_139 ;
F_22 ( V_122 < sizeof( * V_121 ) + sizeof( * V_139 ) ) ;
V_139 = (struct V_138 * ) ( V_121 + 1 ) ;
F_8 ( V_418 != F_320 ( V_64 , V_139 ) ) ;
}
V_116 = F_82 ( V_64 , V_121 ) ;
F_22 ( V_116 < V_159 ) ;
V_116 -= V_159 ;
if ( V_116 > 0 ) {
if ( V_131 )
F_133 ( V_131 , V_64 , V_121 ) ;
if ( V_163 ) {
F_22 ( ! V_421 ) ;
} else {
F_93 ( V_64 , V_121 , V_116 ) ;
F_98 ( V_64 ) ;
}
if ( V_421 ) {
V_27 = F_142 ( V_83 , V_60 , V_62 ,
V_163 , V_159 ,
V_181 ) ;
if ( V_27 )
goto abort;
}
} else {
if ( V_421 ) {
F_22 ( V_181 && V_159 !=
F_121 ( V_33 , V_62 , V_163 ) ) ;
if ( V_163 ) {
F_22 ( V_62 -> V_79 [ 0 ] != V_420 ) ;
} else {
F_22 ( V_62 -> V_79 [ 0 ] != V_420 + 1 ) ;
V_62 -> V_79 [ 0 ] = V_420 ;
V_422 = 2 ;
}
}
V_27 = F_321 ( V_83 , V_60 , V_62 , V_62 -> V_79 [ 0 ] ,
V_422 ) ;
if ( V_27 )
goto abort;
F_43 ( V_62 ) ;
if ( V_181 ) {
V_27 = F_165 ( V_83 , V_33 , V_25 , V_34 ) ;
if ( V_27 )
goto abort;
}
V_27 = F_304 ( V_83 , V_33 , V_25 , V_34 , 0 ) ;
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
static T_1 int F_322 ( struct V_82 * V_83 ,
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
if ( F_323 ( & V_119 -> V_224 ) )
F_47 ( & V_119 -> V_224 ) ;
V_119 -> V_424 -- ;
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
void F_324 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_63 * V_239 ,
T_2 V_16 , int V_425 )
{
struct V_1 * V_2 = NULL ;
int V_27 ;
if ( V_33 -> V_235 . V_21 != V_199 ) {
V_27 = F_148 ( V_33 -> V_35 , V_83 ,
V_239 -> V_30 , V_239 -> V_115 ,
V_16 , V_33 -> V_235 . V_21 ,
F_198 ( V_239 ) ,
V_209 , NULL , 0 ) ;
F_22 ( V_27 ) ;
}
if ( ! V_425 )
return;
V_2 = F_65 ( V_33 -> V_35 , V_239 -> V_30 ) ;
if ( F_325 ( V_239 ) == V_83 -> V_257 ) {
if ( V_33 -> V_235 . V_21 != V_199 ) {
V_27 = F_322 ( V_83 , V_33 , V_239 -> V_30 ) ;
if ( ! V_27 )
goto V_69;
}
if ( F_326 ( V_239 , V_426 ) ) {
F_310 ( V_33 , V_2 , V_239 -> V_30 , V_239 -> V_115 , 1 ) ;
goto V_69;
}
F_8 ( F_299 ( V_427 , & V_239 -> V_428 ) ) ;
F_29 ( V_2 , V_239 -> V_30 , V_239 -> V_115 ) ;
F_313 ( V_2 , V_239 -> V_115 , V_413 ) ;
}
V_69:
F_327 ( V_429 , & V_239 -> V_428 ) ;
F_6 ( V_2 ) ;
}
int V_245 ( struct V_82 * V_83 , struct V_32 * V_33 ,
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
static T_2 F_328 ( struct V_32 * V_33 , T_2 V_430 )
{
T_2 V_431 = ( ( T_2 ) V_33 -> V_432 - 1 ) ;
T_2 V_27 = ( V_430 + V_431 ) & ~ V_431 ;
return V_27 ;
}
static T_1 int
F_329 ( struct V_1 * V_2 ,
T_2 V_34 )
{
struct V_47 * V_51 ;
F_50 ( V_81 ) ;
V_51 = F_25 ( V_2 ) ;
if ( ! V_51 )
return 0 ;
F_179 ( V_51 -> V_81 , F_1 ( V_2 ) ||
( V_2 -> V_10 -> V_433 >= V_34 ) ) ;
F_26 ( V_51 ) ;
return 0 ;
}
static T_1 int
F_330 ( struct V_1 * V_2 )
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
static int F_331 ( T_2 V_6 )
{
int V_434 ;
if ( V_6 & V_270 )
V_434 = 0 ;
else if ( V_6 & V_269 )
V_434 = 1 ;
else if ( V_6 & V_268 )
V_434 = 2 ;
else if ( V_6 & V_303 )
V_434 = 3 ;
else
V_434 = 4 ;
return V_434 ;
}
static int F_332 ( struct V_1 * V_2 )
{
return F_331 ( V_2 -> V_6 ) ;
}
static T_1 int F_333 ( struct V_82 * V_83 ,
struct V_32 * V_435 ,
T_2 V_34 , T_2 V_436 ,
T_2 V_437 , struct V_65 * V_205 ,
T_2 V_294 )
{
int V_27 = 0 ;
struct V_32 * V_33 = V_435 -> V_35 -> V_60 ;
struct V_438 * V_439 = NULL ;
struct V_1 * V_13 = NULL ;
struct V_1 * V_440 ;
T_2 V_105 = 0 ;
int V_441 = 2 * 1024 * 1024 ;
int V_442 = 0 ;
int V_443 = 0 ;
struct V_96 * V_99 ;
int V_444 = 0 ;
int V_434 = 0 ;
int V_445 = ( V_294 & V_285 ) ?
V_446 : V_414 ;
bool V_447 = false ;
bool V_448 = false ;
bool V_449 = false ;
bool V_450 = true ;
bool V_451 = false ;
F_8 ( V_34 < V_33 -> V_309 ) ;
F_78 ( V_205 , V_73 ) ;
V_205 -> V_21 = 0 ;
V_205 -> V_31 = 0 ;
F_334 ( V_435 , V_34 , V_436 , V_294 ) ;
V_99 = F_66 ( V_33 -> V_35 , V_294 ) ;
if ( ! V_99 ) {
F_173 ( V_423 L_14 , V_294 ) ;
return - V_315 ;
}
if ( F_254 ( V_99 ) )
V_450 = false ;
if ( V_435 -> V_244 || V_436 )
V_442 = 1 ;
if ( V_294 & V_114 && V_450 ) {
V_439 = & V_33 -> V_35 -> V_452 ;
if ( ! F_251 ( V_33 , V_453 ) )
V_441 = 64 * 1024 ;
}
if ( ( V_294 & V_285 ) && V_450 &&
F_251 ( V_33 , V_453 ) ) {
V_439 = & V_33 -> V_35 -> V_454 ;
}
if ( V_439 ) {
F_11 ( & V_439 -> V_49 ) ;
if ( V_439 -> V_13 )
V_437 = V_439 -> V_455 ;
F_13 ( & V_439 -> V_49 ) ;
}
V_105 = F_75 ( V_105 , F_309 ( V_33 , 0 ) ) ;
V_105 = F_75 ( V_105 , V_437 ) ;
if ( ! V_439 )
V_441 = 0 ;
if ( V_105 == V_437 ) {
V_13 = F_65 ( V_33 -> V_35 ,
V_105 ) ;
V_440 = V_13 ;
if ( V_13 && F_3 ( V_13 , V_294 ) &&
V_13 -> V_3 != V_90 ) {
F_35 ( & V_99 -> V_275 ) ;
if ( F_167 ( & V_13 -> V_86 ) ||
V_13 -> V_113 ) {
F_6 ( V_13 ) ;
F_44 ( & V_99 -> V_275 ) ;
} else {
V_434 = F_332 ( V_13 ) ;
goto V_456;
}
} else if ( V_13 ) {
F_6 ( V_13 ) ;
}
}
V_457:
V_451 = false ;
F_35 ( & V_99 -> V_275 ) ;
F_335 (block_group, &space_info->block_groups[index],
list) {
T_2 V_31 ;
int V_3 ;
V_440 = V_13 ;
F_4 ( V_13 ) ;
V_105 = V_13 -> V_20 . V_21 ;
if ( ! F_3 ( V_13 , V_294 ) ) {
T_2 V_458 = V_268 |
V_269 |
V_270 ;
if ( ( V_294 & V_458 ) && ! ( V_13 -> V_6 & V_458 ) )
goto V_444;
}
V_456:
V_3 = F_1 ( V_13 ) ;
if ( F_336 ( ! V_3 ) ) {
V_447 = true ;
V_27 = F_49 ( V_13 , V_83 ,
V_435 , 0 ) ;
F_22 ( V_27 < 0 ) ;
V_27 = 0 ;
}
if ( F_336 ( V_13 -> V_113 ) )
goto V_444;
if ( V_439 ) {
F_11 ( & V_439 -> V_459 ) ;
V_440 = V_439 -> V_13 ;
if ( V_440 != V_13 &&
( ! V_440 ||
V_440 -> V_113 ||
! F_3 ( V_440 , V_294 ) ) ) {
V_440 = V_13 ;
goto V_460;
}
if ( V_440 != V_13 )
F_4 ( V_440 ) ;
V_31 = F_337 ( V_440 ,
V_439 , V_34 , V_440 -> V_20 . V_21 ) ;
if ( V_31 ) {
F_13 ( & V_439 -> V_459 ) ;
F_338 ( V_33 ,
V_13 , V_105 , V_34 ) ;
goto V_461;
}
F_8 ( V_439 -> V_13 != V_440 ) ;
if ( V_440 != V_13 ) {
F_6 ( V_440 ) ;
V_440 = V_13 ;
}
V_460:
F_22 ( V_440 != V_13 ) ;
if ( V_444 >= V_462 &&
V_439 -> V_13 != V_13 ) {
F_13 ( & V_439 -> V_459 ) ;
goto V_463;
}
F_339 ( NULL , V_439 ) ;
if ( V_444 >= V_462 ) {
F_13 ( & V_439 -> V_459 ) ;
goto V_463;
}
V_27 = F_340 ( V_83 , V_33 ,
V_13 , V_439 ,
V_105 , V_34 ,
V_441 + V_436 ) ;
if ( V_27 == 0 ) {
V_31 = F_337 ( V_13 ,
V_439 , V_34 ,
V_105 ) ;
if ( V_31 ) {
F_13 ( & V_439 -> V_459 ) ;
F_338 ( V_33 ,
V_13 , V_105 ,
V_34 ) ;
goto V_461;
}
} else if ( ! V_3 && V_444 > V_464
&& ! V_448 ) {
F_13 ( & V_439 -> V_459 ) ;
V_448 = true ;
F_329 ( V_13 ,
V_34 + V_441 + V_436 ) ;
goto V_456;
}
F_339 ( NULL , V_439 ) ;
F_13 ( & V_439 -> V_459 ) ;
goto V_444;
}
V_463:
F_11 ( & V_13 -> V_10 -> V_465 ) ;
if ( V_3 &&
V_13 -> V_10 -> V_433 <
V_34 + V_441 + V_436 ) {
F_13 ( & V_13 -> V_10 -> V_465 ) ;
goto V_444;
}
F_13 ( & V_13 -> V_10 -> V_465 ) ;
V_31 = F_341 ( V_13 , V_105 ,
V_34 , V_436 ) ;
if ( ! V_31 && ! V_449 && ! V_3 &&
V_444 > V_464 ) {
F_329 ( V_13 ,
V_34 + V_436 ) ;
V_449 = true ;
goto V_456;
} else if ( ! V_31 ) {
if ( ! V_3 )
V_451 = true ;
goto V_444;
}
V_461:
V_105 = F_328 ( V_33 , V_31 ) ;
if ( V_105 + V_34 >
V_440 -> V_20 . V_21 + V_440 -> V_20 . V_31 ) {
F_29 ( V_440 , V_31 , V_34 ) ;
goto V_444;
}
if ( V_31 < V_105 )
F_29 ( V_440 , V_31 ,
V_105 - V_31 ) ;
F_22 ( V_31 > V_105 ) ;
V_27 = F_313 ( V_440 , V_34 ,
V_445 ) ;
if ( V_27 == - V_175 ) {
F_29 ( V_440 , V_31 , V_34 ) ;
goto V_444;
}
V_205 -> V_21 = V_105 ;
V_205 -> V_31 = V_34 ;
F_342 ( V_435 , V_13 ,
V_105 , V_34 ) ;
if ( V_31 < V_105 )
F_29 ( V_440 , V_31 ,
V_105 - V_31 ) ;
F_22 ( V_31 > V_105 ) ;
if ( V_440 != V_13 )
F_6 ( V_440 ) ;
F_6 ( V_13 ) ;
break;
V_444:
V_448 = false ;
V_449 = false ;
F_22 ( V_434 != F_332 ( V_13 ) ) ;
if ( V_440 != V_13 )
F_6 ( V_440 ) ;
F_6 ( V_13 ) ;
}
F_44 ( & V_99 -> V_275 ) ;
if ( ! V_205 -> V_21 && V_444 >= V_466 && V_451 )
goto V_457;
if ( ! V_205 -> V_21 && ++ V_434 < V_273 )
goto V_457;
if ( ! V_205 -> V_21 && V_444 < V_462 ) {
V_434 = 0 ;
V_444 ++ ;
if ( V_444 == V_467 ) {
if ( V_442 ) {
V_27 = F_175 ( V_83 , V_33 , V_34 +
2 * 1024 * 1024 , V_294 ,
V_326 ) ;
if ( V_27 < 0 ) {
F_151 ( V_83 ,
V_33 , V_27 ) ;
goto V_69;
}
V_442 = 0 ;
if ( V_27 == 1 )
V_443 = 1 ;
} else if ( ! V_443 &&
V_99 -> V_280 ==
V_222 ) {
V_99 -> V_280 = V_326 ;
}
if ( ! V_443 )
V_444 = V_462 ;
}
if ( V_444 == V_462 ) {
V_436 = 0 ;
V_441 = 0 ;
}
goto V_457;
} else if ( ! V_205 -> V_21 ) {
V_27 = - V_315 ;
} else if ( V_205 -> V_21 ) {
V_27 = 0 ;
}
V_69:
return V_27 ;
}
static void F_252 ( struct V_96 * V_12 , T_2 V_305 ,
int V_468 )
{
struct V_1 * V_2 ;
int V_434 = 0 ;
F_11 ( & V_12 -> V_49 ) ;
F_173 ( V_331 L_15 ,
( unsigned long long ) V_12 -> V_6 ,
( unsigned long long ) ( V_12 -> V_266 - V_12 -> V_267 -
V_12 -> V_276 - V_12 -> V_277 -
V_12 -> V_278 ) ,
( V_12 -> V_102 ) ? L_16 : L_17 ) ;
F_173 ( V_331 L_18
L_19 ,
( unsigned long long ) V_12 -> V_266 ,
( unsigned long long ) V_12 -> V_267 ,
( unsigned long long ) V_12 -> V_276 ,
( unsigned long long ) V_12 -> V_277 ,
( unsigned long long ) V_12 -> V_279 ,
( unsigned long long ) V_12 -> V_278 ) ;
F_13 ( & V_12 -> V_49 ) ;
if ( ! V_468 )
return;
F_35 ( & V_12 -> V_275 ) ;
V_74:
F_335 (cache, &info->block_groups[index], list) {
F_11 ( & V_2 -> V_49 ) ;
F_173 ( V_331 L_20
L_21 ,
( unsigned long long ) V_2 -> V_20 . V_21 ,
( unsigned long long ) V_2 -> V_20 . V_31 ,
( unsigned long long ) F_76 ( & V_2 -> V_112 ) ,
( unsigned long long ) V_2 -> V_8 ,
( unsigned long long ) V_2 -> V_9 ) ;
F_343 ( V_2 , V_305 ) ;
F_13 ( & V_2 -> V_49 ) ;
}
if ( ++ V_434 < V_273 )
goto V_74;
F_44 ( & V_12 -> V_275 ) ;
}
int F_344 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
T_2 V_34 , T_2 V_469 ,
T_2 V_436 , T_2 V_437 ,
struct V_65 * V_205 , T_2 V_294 )
{
bool V_470 = false ;
int V_27 ;
V_294 = F_176 ( V_33 , V_294 ) ;
V_74:
if ( V_436 || V_33 -> V_244 ) {
V_27 = F_175 ( V_83 , V_33 -> V_35 -> V_60 ,
V_34 + 2 * 1024 * 1024 , V_294 ,
V_222 ) ;
if ( V_27 < 0 && V_27 != - V_315 ) {
F_151 ( V_83 , V_33 , V_27 ) ;
return V_27 ;
}
}
F_8 ( V_34 < V_33 -> V_309 ) ;
V_27 = F_333 ( V_83 , V_33 , V_34 , V_436 ,
V_437 , V_205 , V_294 ) ;
if ( V_27 == - V_315 ) {
if ( ! V_470 ) {
V_34 = V_34 >> 1 ;
V_34 = V_34 & ~ ( V_33 -> V_309 - 1 ) ;
V_34 = F_75 ( V_34 , V_469 ) ;
V_27 = F_175 ( V_83 , V_33 -> V_35 -> V_60 ,
V_34 , V_294 , V_314 ) ;
if ( V_27 < 0 && V_27 != - V_315 ) {
F_151 ( V_83 , V_33 , V_27 ) ;
return V_27 ;
}
if ( V_34 == V_469 )
V_470 = true ;
goto V_74;
} else if ( F_251 ( V_33 , V_330 ) ) {
struct V_96 * V_318 ;
V_318 = F_66 ( V_33 -> V_35 , V_294 ) ;
F_173 ( V_423 L_22
L_23 , ( unsigned long long ) V_294 ,
( unsigned long long ) V_34 ) ;
if ( V_318 )
F_252 ( V_318 , V_34 , 1 ) ;
}
}
F_345 ( V_33 , V_205 -> V_21 , V_205 -> V_31 ) ;
return V_27 ;
}
static int F_346 ( struct V_32 * V_33 ,
T_2 V_30 , T_2 V_115 , int V_471 )
{
struct V_1 * V_2 ;
int V_27 = 0 ;
V_2 = F_65 ( V_33 -> V_35 , V_30 ) ;
if ( ! V_2 ) {
F_173 ( V_423 L_24 ,
( unsigned long long ) V_30 ) ;
return - V_315 ;
}
if ( F_251 ( V_33 , V_417 ) )
V_27 = F_145 ( V_33 , V_30 , V_115 , NULL ) ;
if ( V_471 )
F_310 ( V_33 , V_2 , V_30 , V_115 , 1 ) ;
else {
F_29 ( V_2 , V_30 , V_115 ) ;
F_313 ( V_2 , V_115 , V_413 ) ;
}
F_6 ( V_2 ) ;
F_347 ( V_33 , V_30 , V_115 ) ;
return V_27 ;
}
int F_348 ( struct V_32 * V_33 ,
T_2 V_30 , T_2 V_115 )
{
return F_346 ( V_33 , V_30 , V_115 , 0 ) ;
}
int F_349 ( struct V_32 * V_33 ,
T_2 V_30 , T_2 V_115 )
{
return F_346 ( V_33 , V_30 , V_115 , 1 ) ;
}
static int F_154 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
T_2 V_16 , T_2 V_146 ,
T_2 V_6 , T_2 V_107 , T_2 V_31 ,
struct V_65 * V_205 , int V_134 )
{
int V_27 ;
struct V_11 * V_35 = V_33 -> V_35 ;
struct V_120 * V_472 ;
struct V_162 * V_163 ;
struct V_61 * V_62 ;
struct V_63 * V_64 ;
int type ;
T_3 V_54 ;
if ( V_16 > 0 )
type = V_154 ;
else
type = V_155 ;
V_54 = sizeof( * V_472 ) + F_128 ( type ) ;
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
V_472 = F_81 ( V_64 , V_62 -> V_79 [ 0 ] ,
struct V_120 ) ;
F_93 ( V_64 , V_472 , V_134 ) ;
F_94 ( V_64 , V_472 , V_83 -> V_257 ) ;
F_95 ( V_64 , V_472 ,
V_6 | V_145 ) ;
V_163 = (struct V_162 * ) ( V_472 + 1 ) ;
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
V_27 = F_304 ( V_83 , V_33 , V_205 -> V_21 , V_205 -> V_31 , 1 ) ;
if ( V_27 ) {
F_173 ( V_423 L_25
L_26 , ( unsigned long long ) V_205 -> V_21 ,
( unsigned long long ) V_205 -> V_31 ) ;
F_86 () ;
}
return V_27 ;
}
static int F_160 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
T_2 V_16 , T_2 V_146 ,
T_2 V_6 , struct V_400 * V_20 ,
int V_166 , struct V_65 * V_205 )
{
int V_27 ;
struct V_11 * V_35 = V_33 -> V_35 ;
struct V_120 * V_472 ;
struct V_138 * V_473 ;
struct V_162 * V_163 ;
struct V_61 * V_62 ;
struct V_63 * V_64 ;
T_3 V_54 = sizeof( * V_472 ) + sizeof( * V_473 ) + sizeof( * V_163 ) ;
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
V_472 = F_81 ( V_64 , V_62 -> V_79 [ 0 ] ,
struct V_120 ) ;
F_93 ( V_64 , V_472 , 1 ) ;
F_94 ( V_64 , V_472 , V_83 -> V_257 ) ;
F_95 ( V_64 , V_472 ,
V_6 | V_144 ) ;
V_473 = (struct V_138 * ) ( V_472 + 1 ) ;
F_156 ( V_64 , V_473 , V_20 ) ;
F_97 ( V_64 , V_473 , V_166 ) ;
V_163 = (struct V_162 * ) ( V_473 + 1 ) ;
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
V_27 = F_304 ( V_83 , V_33 , V_205 -> V_21 , V_205 -> V_31 , 1 ) ;
if ( V_27 ) {
F_173 ( V_423 L_25
L_26 , ( unsigned long long ) V_205 -> V_21 ,
( unsigned long long ) V_205 -> V_31 ) ;
F_86 () ;
}
return V_27 ;
}
int F_350 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
T_2 V_146 , T_2 V_107 ,
T_2 V_31 , struct V_65 * V_205 )
{
int V_27 ;
F_22 ( V_146 == V_199 ) ;
V_27 = F_149 ( V_33 -> V_35 , V_83 , V_205 -> V_21 ,
V_205 -> V_31 , 0 ,
V_146 , V_107 , V_31 ,
V_474 , NULL , 0 ) ;
return V_27 ;
}
int F_351 ( struct V_82 * V_83 ,
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
V_27 = F_312 ( V_13 , V_30 , V_34 ) ;
F_22 ( V_27 ) ;
} else {
F_34 ( & V_51 -> V_75 ) ;
if ( V_30 >= V_51 -> V_80 ) {
V_27 = F_17 ( V_33 , V_30 , V_34 ) ;
F_22 ( V_27 ) ;
} else if ( V_30 + V_34 <= V_51 -> V_80 ) {
V_27 = F_312 ( V_13 ,
V_30 , V_34 ) ;
F_22 ( V_27 ) ;
} else {
V_34 = V_51 -> V_80 - V_30 ;
V_27 = F_312 ( V_13 ,
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
V_27 = F_313 ( V_13 , V_205 -> V_31 ,
V_446 ) ;
F_22 ( V_27 ) ;
F_6 ( V_13 ) ;
V_27 = F_154 ( V_83 , V_33 , 0 , V_146 ,
0 , V_107 , V_31 , V_205 , 1 ) ;
return V_27 ;
}
struct V_63 * F_352 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
T_2 V_25 , T_3 V_475 ,
int V_166 )
{
struct V_63 * V_239 ;
V_239 = F_353 ( V_33 , V_25 , V_475 ) ;
if ( ! V_239 )
return F_354 ( - V_85 ) ;
F_355 ( V_239 , V_83 -> V_257 ) ;
F_356 ( V_33 -> V_235 . V_21 , V_239 , V_166 ) ;
F_357 ( V_239 ) ;
F_358 ( V_83 , V_33 , V_239 ) ;
F_327 ( V_476 , & V_239 -> V_428 ) ;
F_359 ( V_239 ) ;
F_360 ( V_239 ) ;
if ( V_33 -> V_235 . V_21 == V_199 ) {
if ( V_33 -> V_477 % 2 == 0 )
F_308 ( & V_33 -> V_478 , V_239 -> V_30 ,
V_239 -> V_30 + V_239 -> V_115 - 1 , V_38 ) ;
else
F_361 ( & V_33 -> V_478 , V_239 -> V_30 ,
V_239 -> V_30 + V_239 -> V_115 - 1 , V_38 ) ;
} else {
F_308 ( & V_83 -> V_129 -> V_479 , V_239 -> V_30 ,
V_239 -> V_30 + V_239 -> V_115 - 1 , V_38 ) ;
}
V_83 -> V_480 ++ ;
return V_239 ;
}
static struct V_321 *
F_362 ( struct V_82 * V_83 ,
struct V_32 * V_33 , T_3 V_475 )
{
struct V_321 * V_338 ;
struct V_321 * V_322 = & V_33 -> V_35 -> V_323 ;
int V_27 ;
V_338 = F_264 ( V_83 , V_33 ) ;
if ( V_338 -> V_54 == 0 ) {
V_27 = F_261 ( V_33 , V_338 , V_475 , 0 ) ;
if ( V_27 && V_338 != V_322 ) {
V_27 = F_265 ( V_322 , V_475 ) ;
if ( ! V_27 )
return V_322 ;
return F_354 ( V_27 ) ;
} else if ( V_27 ) {
return F_354 ( V_27 ) ;
}
return V_338 ;
}
V_27 = F_265 ( V_338 , V_475 ) ;
if ( ! V_27 )
return V_338 ;
if ( V_27 ) {
static F_363 ( V_481 ,
V_482 ,
2 ) ;
if ( F_364 ( & V_481 ) ) {
F_173 ( V_219 L_27 , V_27 ) ;
F_8 ( 1 ) ;
}
V_27 = F_261 ( V_33 , V_338 , V_475 , 0 ) ;
if ( ! V_27 ) {
return V_338 ;
} else if ( V_27 && V_338 != V_322 ) {
V_27 = F_265 ( V_322 , V_475 ) ;
if ( ! V_27 )
return V_322 ;
}
}
return F_354 ( - V_315 ) ;
}
static void F_365 ( struct V_11 * V_35 ,
struct V_321 * V_338 , T_3 V_475 )
{
F_266 ( V_338 , V_475 , 0 ) ;
F_267 ( V_35 , V_338 , NULL , 0 ) ;
}
struct V_63 * F_366 ( struct V_82 * V_83 ,
struct V_32 * V_33 , T_3 V_475 ,
T_2 V_16 , T_2 V_146 ,
struct V_400 * V_20 , int V_166 ,
T_2 V_483 , T_2 V_436 )
{
struct V_65 V_205 ;
struct V_321 * V_338 ;
struct V_63 * V_239 ;
T_2 V_6 = 0 ;
int V_27 ;
V_338 = F_362 ( V_83 , V_33 , V_475 ) ;
if ( F_214 ( V_338 ) )
return F_367 ( V_338 ) ;
V_27 = F_344 ( V_83 , V_33 , V_475 , V_475 ,
V_436 , V_483 , & V_205 , 0 ) ;
if ( V_27 ) {
F_365 ( V_33 -> V_35 , V_338 , V_475 ) ;
return F_354 ( V_27 ) ;
}
V_239 = F_352 ( V_83 , V_33 , V_205 . V_21 ,
V_475 , V_166 ) ;
F_22 ( F_214 ( V_239 ) ) ;
if ( V_146 == V_484 ) {
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
V_166 , V_474 ,
V_131 , 0 ) ;
F_22 ( V_27 ) ;
}
return V_239 ;
}
static T_1 void F_368 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_485 * V_486 ,
struct V_61 * V_62 )
{
T_2 V_25 ;
T_2 V_260 ;
T_2 V_116 ;
T_2 V_6 ;
T_3 V_68 ;
T_3 V_475 ;
struct V_65 V_20 ;
struct V_63 * V_487 ;
int V_27 ;
int V_488 ;
int V_489 = 0 ;
if ( V_62 -> V_79 [ V_486 -> V_166 ] < V_486 -> V_490 ) {
V_486 -> V_491 = V_486 -> V_491 * 2 / 3 ;
V_486 -> V_491 = F_75 ( V_486 -> V_491 , 2 ) ;
} else {
V_486 -> V_491 = V_486 -> V_491 * 3 / 2 ;
V_486 -> V_491 = F_182 ( int , V_486 -> V_491 ,
F_369 ( V_33 ) ) ;
}
V_487 = V_62 -> V_78 [ V_486 -> V_166 ] ;
V_68 = F_37 ( V_487 ) ;
V_475 = F_205 ( V_33 , V_486 -> V_166 - 1 ) ;
for ( V_488 = V_62 -> V_79 [ V_486 -> V_166 ] ; V_488 < V_68 ; V_488 ++ ) {
if ( V_489 >= V_486 -> V_491 )
break;
F_46 () ;
V_25 = F_204 ( V_487 , V_488 ) ;
V_260 = F_370 ( V_487 , V_488 ) ;
if ( V_488 == V_62 -> V_79 [ V_486 -> V_166 ] )
goto V_72;
if ( V_486 -> V_492 == V_493 &&
V_260 <= V_33 -> V_235 . V_31 )
continue;
V_27 = F_79 ( V_83 , V_33 , V_25 , V_475 ,
& V_116 , & V_6 ) ;
if ( V_27 < 0 )
continue;
F_22 ( V_116 == 0 ) ;
if ( V_486 -> V_492 == V_494 ) {
if ( V_116 == 1 )
goto V_72;
if ( V_486 -> V_166 == 1 &&
( V_6 & V_128 ) )
continue;
if ( ! V_486 -> V_495 ||
V_260 <= V_33 -> V_235 . V_31 )
continue;
F_126 ( V_487 , & V_20 , V_488 ) ;
V_27 = F_371 ( & V_20 ,
& V_486 -> V_496 ) ;
if ( V_27 < 0 )
continue;
} else {
if ( V_486 -> V_166 == 1 &&
( V_6 & V_128 ) )
continue;
}
V_72:
V_27 = F_372 ( V_33 , V_25 , V_475 ,
V_260 ) ;
if ( V_27 )
break;
V_489 ++ ;
}
V_486 -> V_490 = V_488 ;
}
static T_1 int F_373 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_61 * V_62 ,
struct V_485 * V_486 , int V_497 )
{
int V_166 = V_486 -> V_166 ;
struct V_63 * V_487 = V_62 -> V_78 [ V_166 ] ;
T_2 V_498 = V_128 ;
int V_27 ;
if ( V_486 -> V_492 == V_493 &&
F_197 ( V_487 ) != V_33 -> V_235 . V_21 )
return 1 ;
if ( V_497 &&
( ( V_486 -> V_492 == V_494 && V_486 -> V_116 [ V_166 ] != 1 ) ||
( V_486 -> V_492 == V_493 && ! ( V_486 -> V_6 [ V_166 ] & V_498 ) ) ) ) {
F_22 ( ! V_62 -> V_499 [ V_166 ] ) ;
V_27 = F_79 ( V_83 , V_33 ,
V_487 -> V_30 , V_487 -> V_115 ,
& V_486 -> V_116 [ V_166 ] ,
& V_486 -> V_6 [ V_166 ] ) ;
F_22 ( V_27 == - V_85 ) ;
if ( V_27 )
return V_27 ;
F_22 ( V_486 -> V_116 [ V_166 ] == 0 ) ;
}
if ( V_486 -> V_492 == V_494 ) {
if ( V_486 -> V_116 [ V_166 ] > 1 )
return 1 ;
if ( V_62 -> V_499 [ V_166 ] && ! V_486 -> V_172 ) {
F_374 ( V_487 , V_62 -> V_499 [ V_166 ] ) ;
V_62 -> V_499 [ V_166 ] = 0 ;
}
return 0 ;
}
if ( ! ( V_486 -> V_6 [ V_166 ] & V_498 ) ) {
F_22 ( ! V_62 -> V_499 [ V_166 ] ) ;
V_27 = F_206 ( V_83 , V_33 , V_487 , 1 , V_486 -> V_500 ) ;
F_22 ( V_27 ) ;
V_27 = F_207 ( V_83 , V_33 , V_487 , 0 , V_486 -> V_500 ) ;
F_22 ( V_27 ) ;
V_27 = F_186 ( V_83 , V_33 , V_487 -> V_30 ,
V_487 -> V_115 , V_498 , 0 ) ;
F_22 ( V_27 ) ;
V_486 -> V_6 [ V_166 ] |= V_498 ;
}
if ( V_62 -> V_499 [ V_166 ] && V_166 > 0 ) {
F_374 ( V_487 , V_62 -> V_499 [ V_166 ] ) ;
V_62 -> V_499 [ V_166 ] = 0 ;
}
return 0 ;
}
static T_1 int F_375 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_61 * V_62 ,
struct V_485 * V_486 , int * V_497 )
{
T_2 V_25 ;
T_2 V_260 ;
T_2 V_16 ;
T_3 V_475 ;
struct V_65 V_20 ;
struct V_63 * V_216 ;
int V_166 = V_486 -> V_166 ;
int V_72 = 0 ;
int V_27 = 0 ;
V_260 = F_370 ( V_62 -> V_78 [ V_166 ] ,
V_62 -> V_79 [ V_166 ] ) ;
if ( V_486 -> V_492 == V_493 &&
V_260 <= V_33 -> V_235 . V_31 ) {
* V_497 = 1 ;
return 1 ;
}
V_25 = F_204 ( V_62 -> V_78 [ V_166 ] , V_62 -> V_79 [ V_166 ] ) ;
V_475 = F_205 ( V_33 , V_166 - 1 ) ;
V_216 = F_376 ( V_33 , V_25 , V_475 ) ;
if ( ! V_216 ) {
V_216 = F_353 ( V_33 , V_25 , V_475 ) ;
if ( ! V_216 )
return - V_85 ;
V_72 = 1 ;
}
F_357 ( V_216 ) ;
F_359 ( V_216 ) ;
V_27 = F_79 ( V_83 , V_33 , V_25 , V_475 ,
& V_486 -> V_116 [ V_166 - 1 ] ,
& V_486 -> V_6 [ V_166 - 1 ] ) ;
if ( V_27 < 0 ) {
F_377 ( V_216 ) ;
return V_27 ;
}
F_22 ( V_486 -> V_116 [ V_166 - 1 ] == 0 ) ;
* V_497 = 0 ;
if ( V_486 -> V_492 == V_494 ) {
if ( V_486 -> V_116 [ V_166 - 1 ] > 1 ) {
if ( V_166 == 1 &&
( V_486 -> V_6 [ 0 ] & V_128 ) )
goto V_501;
if ( ! V_486 -> V_495 ||
V_260 <= V_33 -> V_235 . V_31 )
goto V_501;
F_126 ( V_62 -> V_78 [ V_166 ] , & V_20 ,
V_62 -> V_79 [ V_166 ] ) ;
V_27 = F_371 ( & V_20 , & V_486 -> V_496 ) ;
if ( V_27 < 0 )
goto V_501;
V_486 -> V_492 = V_493 ;
V_486 -> V_502 = V_166 - 1 ;
}
} else {
if ( V_166 == 1 &&
( V_486 -> V_6 [ 0 ] & V_128 ) )
goto V_501;
}
if ( ! F_378 ( V_216 , V_260 , 0 ) ) {
F_377 ( V_216 ) ;
F_379 ( V_216 ) ;
V_216 = NULL ;
* V_497 = 1 ;
}
if ( ! V_216 ) {
if ( V_72 && V_166 == 1 )
F_368 ( V_83 , V_33 , V_486 , V_62 ) ;
V_216 = F_380 ( V_33 , V_25 , V_475 , V_260 ) ;
if ( ! V_216 )
return - V_211 ;
F_357 ( V_216 ) ;
F_359 ( V_216 ) ;
}
V_166 -- ;
F_22 ( V_166 != F_198 ( V_216 ) ) ;
V_62 -> V_78 [ V_166 ] = V_216 ;
V_62 -> V_79 [ V_166 ] = 0 ;
V_62 -> V_499 [ V_166 ] = V_503 ;
V_486 -> V_166 = V_166 ;
if ( V_486 -> V_166 == 1 )
V_486 -> V_490 = 0 ;
return 0 ;
V_501:
V_486 -> V_116 [ V_166 - 1 ] = 0 ;
V_486 -> V_6 [ V_166 - 1 ] = 0 ;
if ( V_486 -> V_492 == V_494 ) {
if ( V_486 -> V_6 [ V_166 ] & V_128 ) {
V_16 = V_62 -> V_78 [ V_166 ] -> V_30 ;
} else {
F_22 ( V_33 -> V_235 . V_21 !=
F_197 ( V_62 -> V_78 [ V_166 ] ) ) ;
V_16 = 0 ;
}
V_27 = V_245 ( V_83 , V_33 , V_25 , V_475 , V_16 ,
V_33 -> V_235 . V_21 , V_166 - 1 , 0 , 0 ) ;
F_22 ( V_27 ) ;
}
F_377 ( V_216 ) ;
F_379 ( V_216 ) ;
* V_497 = 1 ;
return 1 ;
}
static T_1 int F_381 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_61 * V_62 ,
struct V_485 * V_486 )
{
int V_27 ;
int V_166 = V_486 -> V_166 ;
struct V_63 * V_487 = V_62 -> V_78 [ V_166 ] ;
T_2 V_16 = 0 ;
if ( V_486 -> V_492 == V_493 ) {
F_22 ( V_486 -> V_502 < V_166 ) ;
if ( V_166 < V_486 -> V_502 )
goto V_69;
V_27 = F_40 ( V_62 , V_166 + 1 , & V_486 -> V_496 ) ;
if ( V_27 > 0 )
V_486 -> V_495 = 0 ;
V_486 -> V_492 = V_494 ;
V_486 -> V_502 = - 1 ;
V_62 -> V_79 [ V_166 ] = 0 ;
if ( ! V_62 -> V_499 [ V_166 ] ) {
F_22 ( V_166 == 0 ) ;
F_357 ( V_487 ) ;
F_359 ( V_487 ) ;
V_62 -> V_499 [ V_166 ] = V_503 ;
V_27 = F_79 ( V_83 , V_33 ,
V_487 -> V_30 , V_487 -> V_115 ,
& V_486 -> V_116 [ V_166 ] ,
& V_486 -> V_6 [ V_166 ] ) ;
if ( V_27 < 0 ) {
F_374 ( V_487 , V_62 -> V_499 [ V_166 ] ) ;
return V_27 ;
}
F_22 ( V_486 -> V_116 [ V_166 ] == 0 ) ;
if ( V_486 -> V_116 [ V_166 ] == 1 ) {
F_374 ( V_487 , V_62 -> V_499 [ V_166 ] ) ;
return 1 ;
}
}
}
F_22 ( V_486 -> V_116 [ V_166 ] > 1 && ! V_62 -> V_499 [ V_166 ] ) ;
if ( V_486 -> V_116 [ V_166 ] == 1 ) {
if ( V_166 == 0 ) {
if ( V_486 -> V_6 [ V_166 ] & V_128 )
V_27 = F_207 ( V_83 , V_33 , V_487 , 1 ,
V_486 -> V_500 ) ;
else
V_27 = F_207 ( V_83 , V_33 , V_487 , 0 ,
V_486 -> V_500 ) ;
F_22 ( V_27 ) ;
}
if ( ! V_62 -> V_499 [ V_166 ] &&
F_325 ( V_487 ) == V_83 -> V_257 ) {
F_357 ( V_487 ) ;
F_359 ( V_487 ) ;
V_62 -> V_499 [ V_166 ] = V_503 ;
}
F_358 ( V_83 , V_33 , V_487 ) ;
}
if ( V_487 == V_33 -> V_130 ) {
if ( V_486 -> V_6 [ V_166 ] & V_128 )
V_16 = V_487 -> V_30 ;
else
F_22 ( V_33 -> V_235 . V_21 !=
F_197 ( V_487 ) ) ;
} else {
if ( V_486 -> V_6 [ V_166 + 1 ] & V_128 )
V_16 = V_62 -> V_78 [ V_166 + 1 ] -> V_30 ;
else
F_22 ( V_33 -> V_235 . V_21 !=
F_197 ( V_62 -> V_78 [ V_166 + 1 ] ) ) ;
}
F_324 ( V_83 , V_33 , V_487 , V_16 , V_486 -> V_116 [ V_166 ] == 1 ) ;
V_69:
V_486 -> V_116 [ V_166 ] = 0 ;
V_486 -> V_6 [ V_166 ] = 0 ;
return 0 ;
}
static T_1 int F_382 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_61 * V_62 ,
struct V_485 * V_486 )
{
int V_166 = V_486 -> V_166 ;
int V_497 = 1 ;
int V_27 ;
while ( V_166 >= 0 ) {
V_27 = F_373 ( V_83 , V_33 , V_62 , V_486 , V_497 ) ;
if ( V_27 > 0 )
break;
if ( V_166 == 0 )
break;
if ( V_62 -> V_79 [ V_166 ] >=
F_37 ( V_62 -> V_78 [ V_166 ] ) )
break;
V_27 = F_375 ( V_83 , V_33 , V_62 , V_486 , & V_497 ) ;
if ( V_27 > 0 ) {
V_62 -> V_79 [ V_166 ] ++ ;
continue;
} else if ( V_27 < 0 )
return V_27 ;
V_166 = V_486 -> V_166 ;
}
return 0 ;
}
static T_1 int F_383 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_61 * V_62 ,
struct V_485 * V_486 , int V_504 )
{
int V_166 = V_486 -> V_166 ;
int V_27 ;
V_62 -> V_79 [ V_166 ] = F_37 ( V_62 -> V_78 [ V_166 ] ) ;
while ( V_166 < V_504 && V_62 -> V_78 [ V_166 ] ) {
V_486 -> V_166 = V_166 ;
if ( V_62 -> V_79 [ V_166 ] + 1 <
F_37 ( V_62 -> V_78 [ V_166 ] ) ) {
V_62 -> V_79 [ V_166 ] ++ ;
return 0 ;
} else {
V_27 = F_381 ( V_83 , V_33 , V_62 , V_486 ) ;
if ( V_27 > 0 )
return 0 ;
if ( V_62 -> V_499 [ V_166 ] ) {
F_374 ( V_62 -> V_78 [ V_166 ] ,
V_62 -> V_499 [ V_166 ] ) ;
V_62 -> V_499 [ V_166 ] = 0 ;
}
F_379 ( V_62 -> V_78 [ V_166 ] ) ;
V_62 -> V_78 [ V_166 ] = NULL ;
V_166 ++ ;
}
}
return 1 ;
}
int F_384 ( struct V_32 * V_33 ,
struct V_321 * V_338 , int V_495 ,
int V_500 )
{
struct V_61 * V_62 ;
struct V_82 * V_83 ;
struct V_32 * V_230 = V_33 -> V_35 -> V_230 ;
struct V_505 * V_236 = & V_33 -> V_236 ;
struct V_485 * V_486 ;
struct V_65 V_20 ;
int V_77 = 0 ;
int V_27 ;
int V_166 ;
V_62 = F_32 () ;
if ( ! V_62 ) {
V_77 = - V_85 ;
goto V_69;
}
V_486 = F_51 ( sizeof( * V_486 ) , V_38 ) ;
if ( ! V_486 ) {
F_48 ( V_62 ) ;
V_77 = - V_85 ;
goto V_69;
}
V_83 = F_385 ( V_230 , 0 ) ;
if ( F_214 ( V_83 ) ) {
V_77 = F_215 ( V_83 ) ;
goto V_125;
}
if ( V_338 )
V_83 -> V_338 = V_338 ;
if ( F_386 ( & V_236 -> V_506 ) == 0 ) {
V_166 = F_198 ( V_33 -> V_130 ) ;
V_62 -> V_78 [ V_166 ] = F_387 ( V_33 ) ;
F_359 ( V_62 -> V_78 [ V_166 ] ) ;
V_62 -> V_79 [ V_166 ] = 0 ;
V_62 -> V_499 [ V_166 ] = V_503 ;
memset ( & V_486 -> V_496 , 0 ,
sizeof( V_486 -> V_496 ) ) ;
} else {
F_388 ( & V_20 , & V_236 -> V_506 ) ;
memcpy ( & V_486 -> V_496 , & V_20 ,
sizeof( V_486 -> V_496 ) ) ;
V_166 = V_236 -> V_507 ;
F_22 ( V_166 == 0 ) ;
V_62 -> V_508 = V_166 ;
V_27 = F_36 ( NULL , V_33 , & V_20 , V_62 , 0 , 0 ) ;
V_62 -> V_508 = 0 ;
if ( V_27 < 0 ) {
V_77 = V_27 ;
goto V_509;
}
F_8 ( V_27 > 0 ) ;
F_131 ( V_62 , 0 ) ;
V_166 = F_198 ( V_33 -> V_130 ) ;
while ( 1 ) {
F_357 ( V_62 -> V_78 [ V_166 ] ) ;
F_359 ( V_62 -> V_78 [ V_166 ] ) ;
V_27 = F_79 ( V_83 , V_33 ,
V_62 -> V_78 [ V_166 ] -> V_30 ,
V_62 -> V_78 [ V_166 ] -> V_115 ,
& V_486 -> V_116 [ V_166 ] ,
& V_486 -> V_6 [ V_166 ] ) ;
if ( V_27 < 0 ) {
V_77 = V_27 ;
goto V_509;
}
F_22 ( V_486 -> V_116 [ V_166 ] == 0 ) ;
if ( V_166 == V_236 -> V_507 )
break;
F_377 ( V_62 -> V_78 [ V_166 ] ) ;
F_8 ( V_486 -> V_116 [ V_166 ] != 1 ) ;
V_166 -- ;
}
}
V_486 -> V_166 = V_166 ;
V_486 -> V_502 = - 1 ;
V_486 -> V_492 = V_494 ;
V_486 -> V_495 = V_495 ;
V_486 -> V_172 = 0 ;
V_486 -> V_500 = V_500 ;
V_486 -> V_491 = F_369 ( V_33 ) ;
while ( 1 ) {
V_27 = F_382 ( V_83 , V_33 , V_62 , V_486 ) ;
if ( V_27 < 0 ) {
V_77 = V_27 ;
break;
}
V_27 = F_383 ( V_83 , V_33 , V_62 , V_486 , V_167 ) ;
if ( V_27 < 0 ) {
V_77 = V_27 ;
break;
}
if ( V_27 > 0 ) {
F_22 ( V_486 -> V_492 != V_494 ) ;
break;
}
if ( V_486 -> V_492 == V_494 ) {
V_166 = V_486 -> V_166 ;
F_389 ( V_62 -> V_78 [ V_166 ] ,
& V_236 -> V_506 ,
V_62 -> V_79 [ V_166 ] ) ;
V_236 -> V_507 = V_166 ;
}
F_22 ( V_486 -> V_166 == 0 ) ;
if ( F_390 ( V_83 , V_230 ) ) {
V_27 = F_391 ( V_83 , V_230 ,
& V_33 -> V_235 ,
V_236 ) ;
if ( V_27 ) {
F_151 ( V_83 , V_230 , V_27 ) ;
V_77 = V_27 ;
goto V_509;
}
F_392 ( V_83 , V_230 ) ;
V_83 = F_385 ( V_230 , 0 ) ;
if ( F_214 ( V_83 ) ) {
V_77 = F_215 ( V_83 ) ;
goto V_125;
}
if ( V_338 )
V_83 -> V_338 = V_338 ;
}
}
F_43 ( V_62 ) ;
if ( V_77 )
goto V_509;
V_27 = F_393 ( V_83 , V_230 , & V_33 -> V_235 ) ;
if ( V_27 ) {
F_151 ( V_83 , V_230 , V_27 ) ;
goto V_509;
}
if ( V_33 -> V_235 . V_21 != V_484 ) {
V_27 = F_394 ( V_230 , V_33 -> V_235 . V_21 ,
NULL , NULL ) ;
if ( V_27 < 0 ) {
F_151 ( V_83 , V_230 , V_27 ) ;
V_77 = V_27 ;
goto V_509;
} else if ( V_27 > 0 ) {
F_395 ( V_83 , V_230 ,
V_33 -> V_235 . V_21 ) ;
}
}
if ( V_33 -> V_510 ) {
F_396 ( V_230 -> V_35 , V_33 ) ;
} else {
F_379 ( V_33 -> V_130 ) ;
F_379 ( V_33 -> V_511 ) ;
F_9 ( V_33 ) ;
}
V_509:
F_392 ( V_83 , V_230 ) ;
V_125:
F_9 ( V_486 ) ;
F_48 ( V_62 ) ;
V_69:
if ( V_77 )
F_397 ( V_33 -> V_35 , V_77 ) ;
return V_77 ;
}
int F_398 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_63 * V_130 ,
struct V_63 * V_16 )
{
struct V_61 * V_62 ;
struct V_485 * V_486 ;
int V_166 ;
int V_512 ;
int V_27 = 0 ;
int V_513 ;
F_22 ( V_33 -> V_235 . V_21 != V_484 ) ;
V_62 = F_32 () ;
if ( ! V_62 )
return - V_85 ;
V_486 = F_51 ( sizeof( * V_486 ) , V_38 ) ;
if ( ! V_486 ) {
F_48 ( V_62 ) ;
return - V_85 ;
}
F_399 ( V_16 ) ;
V_512 = F_198 ( V_16 ) ;
F_400 ( V_16 ) ;
V_62 -> V_78 [ V_512 ] = V_16 ;
V_62 -> V_79 [ V_512 ] = F_37 ( V_16 ) ;
F_399 ( V_130 ) ;
V_166 = F_198 ( V_130 ) ;
V_62 -> V_78 [ V_166 ] = V_130 ;
V_62 -> V_79 [ V_166 ] = 0 ;
V_62 -> V_499 [ V_166 ] = V_503 ;
V_486 -> V_116 [ V_512 ] = 1 ;
V_486 -> V_6 [ V_512 ] = V_128 ;
V_486 -> V_166 = V_166 ;
V_486 -> V_502 = - 1 ;
V_486 -> V_492 = V_494 ;
V_486 -> V_495 = 0 ;
V_486 -> V_172 = 1 ;
V_486 -> V_500 = 1 ;
V_486 -> V_491 = F_369 ( V_33 ) ;
while ( 1 ) {
V_513 = F_382 ( V_83 , V_33 , V_62 , V_486 ) ;
if ( V_513 < 0 ) {
V_27 = V_513 ;
break;
}
V_513 = F_383 ( V_83 , V_33 , V_62 , V_486 , V_512 ) ;
if ( V_513 < 0 )
V_27 = V_513 ;
if ( V_513 != 0 )
break;
}
F_9 ( V_486 ) ;
F_48 ( V_62 ) ;
return V_27 ;
}
static T_2 F_401 ( struct V_32 * V_33 , T_2 V_6 )
{
T_2 V_298 ;
T_2 V_514 ;
V_514 = F_235 ( V_33 -> V_35 , V_6 ) ;
if ( V_514 )
return F_237 ( V_514 ) ;
V_298 = V_33 -> V_35 -> V_299 -> V_300 +
V_33 -> V_35 -> V_299 -> V_301 ;
V_514 = V_303 |
V_269 | V_270 ;
if ( V_298 == 1 ) {
V_514 |= V_268 ;
V_514 = V_6 & ~ V_514 ;
if ( V_6 & V_303 )
return V_514 ;
if ( V_6 & ( V_269 |
V_270 ) )
return V_514 | V_268 ;
} else {
if ( V_6 & V_514 )
return V_6 ;
V_514 |= V_268 ;
V_514 = V_6 & ~ V_514 ;
if ( V_6 & V_268 )
return V_514 | V_269 ;
}
return V_6 ;
}
static int F_402 ( struct V_1 * V_2 , int V_320 )
{
struct V_96 * V_318 = V_2 -> V_99 ;
T_2 V_34 ;
T_2 V_515 ;
int V_27 = - V_315 ;
if ( ( V_318 -> V_6 &
( V_288 | V_114 ) ) &&
! V_320 )
V_515 = 1 * 1024 * 1024 ;
else
V_515 = 0 ;
F_11 ( & V_318 -> V_49 ) ;
F_11 ( & V_2 -> V_49 ) ;
if ( V_2 -> V_113 ) {
V_27 = 0 ;
goto V_69;
}
V_34 = V_2 -> V_20 . V_31 - V_2 -> V_9 - V_2 -> V_8 -
V_2 -> V_44 - F_76 ( & V_2 -> V_112 ) ;
if ( V_318 -> V_267 + V_318 -> V_277 + V_318 -> V_276 +
V_318 -> V_279 + V_318 -> V_278 + V_34 +
V_515 <= V_318 -> V_266 ) {
V_318 -> V_278 += V_34 ;
V_2 -> V_113 = 1 ;
V_27 = 0 ;
}
V_69:
F_13 ( & V_2 -> V_49 ) ;
F_13 ( & V_318 -> V_49 ) ;
return V_27 ;
}
int F_403 ( struct V_32 * V_33 ,
struct V_1 * V_2 )
{
struct V_82 * V_83 ;
T_2 V_516 ;
int V_27 ;
F_22 ( V_2 -> V_113 ) ;
V_83 = F_240 ( V_33 ) ;
if ( F_214 ( V_83 ) )
return F_215 ( V_83 ) ;
V_516 = F_401 ( V_33 , V_2 -> V_6 ) ;
if ( V_516 != V_2 -> V_6 ) {
V_27 = F_175 ( V_83 , V_33 , 2 * 1024 * 1024 , V_516 ,
V_314 ) ;
if ( V_27 < 0 )
goto V_69;
}
V_27 = F_402 ( V_2 , 0 ) ;
if ( ! V_27 )
goto V_69;
V_516 = F_238 ( V_33 , V_2 -> V_99 -> V_6 ) ;
V_27 = F_175 ( V_83 , V_33 , 2 * 1024 * 1024 , V_516 ,
V_314 ) ;
if ( V_27 < 0 )
goto V_69;
V_27 = F_402 ( V_2 , 0 ) ;
V_69:
F_241 ( V_83 , V_33 ) ;
return V_27 ;
}
int F_404 ( struct V_82 * V_83 ,
struct V_32 * V_33 , T_2 type )
{
T_2 V_516 = F_238 ( V_33 , type ) ;
return F_175 ( V_83 , V_33 , 2 * 1024 * 1024 , V_516 ,
V_314 ) ;
}
static T_2 F_405 ( struct V_97 * V_517 )
{
struct V_1 * V_13 ;
T_2 V_518 = 0 ;
int V_104 ;
F_335 (block_group, groups_list, list) {
F_11 ( & V_13 -> V_49 ) ;
if ( ! V_13 -> V_113 ) {
F_13 ( & V_13 -> V_49 ) ;
continue;
}
if ( V_13 -> V_6 & ( V_269 |
V_270 |
V_268 ) )
V_104 = 2 ;
else
V_104 = 1 ;
V_518 += ( V_13 -> V_20 . V_31 -
F_76 ( & V_13 -> V_112 ) ) *
V_104 ;
F_13 ( & V_13 -> V_49 ) ;
}
return V_518 ;
}
T_2 F_406 ( struct V_96 * V_318 )
{
int V_41 ;
T_2 V_518 = 0 ;
F_11 ( & V_318 -> V_49 ) ;
for( V_41 = 0 ; V_41 < V_273 ; V_41 ++ )
if ( ! F_167 ( & V_318 -> V_274 [ V_41 ] ) )
V_518 += F_405 (
& V_318 -> V_274 [ V_41 ] ) ;
F_13 ( & V_318 -> V_49 ) ;
return V_518 ;
}
void F_407 ( struct V_32 * V_33 ,
struct V_1 * V_2 )
{
struct V_96 * V_318 = V_2 -> V_99 ;
T_2 V_34 ;
F_22 ( ! V_2 -> V_113 ) ;
F_11 ( & V_318 -> V_49 ) ;
F_11 ( & V_2 -> V_49 ) ;
V_34 = V_2 -> V_20 . V_31 - V_2 -> V_9 - V_2 -> V_8 -
V_2 -> V_44 - F_76 ( & V_2 -> V_112 ) ;
V_318 -> V_278 -= V_34 ;
V_2 -> V_113 = 0 ;
F_13 ( & V_2 -> V_49 ) ;
F_13 ( & V_318 -> V_49 ) ;
}
int F_408 ( struct V_32 * V_33 , T_2 V_25 )
{
struct V_1 * V_13 ;
struct V_96 * V_99 ;
struct V_519 * V_299 = V_33 -> V_35 -> V_299 ;
struct V_520 * V_521 ;
T_2 V_522 ;
T_2 V_523 = 1 ;
T_2 V_524 = 0 ;
T_2 V_293 ;
int V_434 ;
int V_102 = 0 ;
int V_27 = 0 ;
V_13 = F_65 ( V_33 -> V_35 , V_25 ) ;
if ( ! V_13 )
return - 1 ;
V_522 = F_76 ( & V_13 -> V_112 ) ;
if ( ! V_522 )
goto V_69;
V_99 = V_13 -> V_99 ;
F_11 ( & V_99 -> V_49 ) ;
V_102 = V_99 -> V_102 ;
if ( ( V_99 -> V_266 != V_13 -> V_20 . V_31 ) &&
( V_99 -> V_267 + V_99 -> V_277 +
V_99 -> V_276 + V_99 -> V_278 +
V_522 < V_99 -> V_266 ) ) {
F_13 ( & V_99 -> V_49 ) ;
goto V_69;
}
F_13 ( & V_99 -> V_49 ) ;
V_27 = - 1 ;
V_293 = F_235 ( V_33 -> V_35 , V_13 -> V_6 ) ;
if ( V_293 ) {
V_434 = F_331 ( F_237 ( V_293 ) ) ;
} else {
if ( V_102 )
goto V_69;
V_434 = F_332 ( V_13 ) ;
}
if ( V_434 == 0 ) {
V_523 = 4 ;
V_522 >>= 1 ;
} else if ( V_434 == 1 ) {
V_523 = 2 ;
} else if ( V_434 == 2 ) {
V_522 <<= 1 ;
} else if ( V_434 == 3 ) {
V_523 = V_299 -> V_300 ;
F_72 ( V_522 , V_523 ) ;
}
F_34 ( & V_33 -> V_35 -> V_333 ) ;
F_335 (device, &fs_devices->alloc_list, dev_alloc_list) {
T_2 V_525 ;
if ( V_521 -> V_266 > V_521 -> V_267 + V_522 ) {
V_27 = F_409 ( V_521 , V_522 ,
& V_525 , NULL ) ;
if ( ! V_27 )
V_524 ++ ;
if ( V_524 >= V_523 )
break;
V_27 = - 1 ;
}
}
F_45 ( & V_33 -> V_35 -> V_333 ) ;
V_69:
F_6 ( V_13 ) ;
return V_27 ;
}
static int F_410 ( struct V_32 * V_33 ,
struct V_61 * V_62 , struct V_65 * V_20 )
{
int V_27 = 0 ;
struct V_65 V_140 ;
struct V_63 * V_64 ;
int V_488 ;
V_27 = F_36 ( NULL , V_33 , V_20 , V_62 , 0 , 0 ) ;
if ( V_27 < 0 )
goto V_69;
while ( 1 ) {
V_488 = V_62 -> V_79 [ 0 ] ;
V_64 = V_62 -> V_78 [ 0 ] ;
if ( V_488 >= F_37 ( V_64 ) ) {
V_27 = F_42 ( V_33 , V_62 ) ;
if ( V_27 == 0 )
continue;
if ( V_27 < 0 )
goto V_69;
break;
}
F_39 ( V_64 , & V_140 , V_488 ) ;
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
void F_411 ( struct V_11 * V_12 )
{
struct V_1 * V_13 ;
T_2 V_67 = 0 ;
while ( 1 ) {
struct V_248 * V_248 ;
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
V_248 = V_13 -> V_248 ;
V_13 -> V_163 = 0 ;
V_13 -> V_248 = NULL ;
F_13 ( & V_13 -> V_49 ) ;
F_225 ( V_248 ) ;
V_67 = V_13 -> V_20 . V_21 + V_13 -> V_20 . V_31 ;
F_6 ( V_13 ) ;
}
}
int F_412 ( struct V_11 * V_12 )
{
struct V_1 * V_13 ;
struct V_96 * V_99 ;
struct V_47 * V_51 ;
struct V_14 * V_28 ;
F_60 ( & V_12 -> V_76 ) ;
while ( ! F_167 ( & V_12 -> V_94 ) ) {
V_51 = F_168 ( V_12 -> V_94 . V_216 ,
struct V_47 , V_86 ) ;
F_413 ( & V_51 -> V_86 ) ;
F_26 ( V_51 ) ;
}
F_62 ( & V_12 -> V_76 ) ;
F_11 ( & V_12 -> V_17 ) ;
while ( ( V_28 = F_414 ( & V_12 -> V_18 ) ) != NULL ) {
V_13 = F_12 ( V_28 , struct V_1 ,
V_19 ) ;
F_174 ( & V_13 -> V_19 ,
& V_12 -> V_18 ) ;
F_13 ( & V_12 -> V_17 ) ;
F_60 ( & V_13 -> V_99 -> V_275 ) ;
F_413 ( & V_13 -> V_86 ) ;
F_62 ( & V_13 -> V_99 -> V_275 ) ;
if ( V_13 -> V_3 == V_50 )
F_330 ( V_13 ) ;
if ( V_13 -> V_3 == V_90 )
F_19 ( V_12 -> V_60 , V_13 ) ;
F_415 ( V_13 ) ;
F_6 ( V_13 ) ;
F_11 ( & V_12 -> V_17 ) ;
}
F_13 ( & V_12 -> V_17 ) ;
F_416 () ;
F_286 ( V_12 ) ;
while( ! F_167 ( & V_12 -> V_99 ) ) {
V_99 = F_168 ( V_12 -> V_99 . V_216 ,
struct V_96 ,
V_86 ) ;
if ( V_99 -> V_276 > 0 ||
V_99 -> V_277 > 0 ||
V_99 -> V_279 > 0 ) {
F_8 ( 1 ) ;
F_252 ( V_99 , 0 , 0 ) ;
}
F_413 ( & V_99 -> V_86 ) ;
F_9 ( V_99 ) ;
}
return 0 ;
}
static void F_417 ( struct V_96 * V_99 ,
struct V_1 * V_2 )
{
int V_434 = F_332 ( V_2 ) ;
F_60 ( & V_99 -> V_275 ) ;
F_61 ( & V_2 -> V_86 , & V_99 -> V_274 [ V_434 ] ) ;
F_62 ( & V_99 -> V_275 ) ;
}
int F_418 ( struct V_32 * V_33 )
{
struct V_61 * V_62 ;
int V_27 ;
struct V_1 * V_2 ;
struct V_11 * V_12 = V_33 -> V_35 ;
struct V_96 * V_99 ;
struct V_65 V_20 ;
struct V_65 V_140 ;
struct V_63 * V_64 ;
int V_526 = 0 ;
T_2 V_527 ;
V_33 = V_12 -> V_60 ;
V_20 . V_21 = 0 ;
V_20 . V_31 = 0 ;
F_78 ( & V_20 , V_176 ) ;
V_62 = F_32 () ;
if ( ! V_62 )
return - V_85 ;
V_62 -> V_72 = 1 ;
V_527 = F_419 ( V_33 -> V_35 -> V_327 ) ;
if ( F_251 ( V_33 , V_411 ) &&
F_420 ( V_33 -> V_35 -> V_327 ) != V_527 )
V_526 = 1 ;
if ( F_251 ( V_33 , V_528 ) )
V_526 = 1 ;
while ( 1 ) {
V_27 = F_410 ( V_33 , V_62 , & V_20 ) ;
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
F_52 ( & V_2 -> V_529 ) ;
if ( V_526 )
V_2 -> V_254 = V_262 ;
F_421 ( V_64 , & V_2 -> V_112 ,
F_209 ( V_64 , V_62 -> V_79 [ 0 ] ) ,
sizeof( V_2 -> V_112 ) ) ;
memcpy ( & V_2 -> V_20 , & V_140 , sizeof( V_140 ) ) ;
V_20 . V_21 = V_140 . V_21 + V_140 . V_31 ;
F_43 ( V_62 ) ;
V_2 -> V_6 = F_422 ( & V_2 -> V_112 ) ;
V_2 -> V_309 = V_33 -> V_309 ;
F_423 ( V_2 ) ;
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
V_2 -> V_99 -> V_278 += V_2 -> V_44 ;
F_13 ( & V_2 -> V_99 -> V_49 ) ;
F_417 ( V_99 , V_2 ) ;
V_27 = F_10 ( V_33 -> V_35 , V_2 ) ;
F_22 ( V_27 ) ;
F_233 ( V_33 -> V_35 , V_2 -> V_6 ) ;
if ( F_424 ( V_33 , V_2 -> V_20 . V_21 ) )
F_402 ( V_2 , 1 ) ;
}
F_68 (space_info, &root->fs_info->space_info, list) {
if ( ! ( F_238 ( V_33 , V_99 -> V_6 ) &
( V_270 |
V_269 |
V_268 ) ) )
continue;
F_335 (cache, &space_info->block_groups[3], list)
F_402 ( V_2 , 1 ) ;
F_335 (cache, &space_info->block_groups[4], list)
F_402 ( V_2 , 1 ) ;
}
F_285 ( V_12 ) ;
V_27 = 0 ;
error:
F_48 ( V_62 ) ;
return V_27 ;
}
int F_425 ( struct V_82 * V_83 ,
struct V_32 * V_33 , T_2 V_267 ,
T_2 type , T_2 V_530 , T_2 V_531 ,
T_2 V_54 )
{
int V_27 ;
struct V_32 * V_60 ;
struct V_1 * V_2 ;
V_60 = V_33 -> V_35 -> V_60 ;
V_33 -> V_35 -> V_532 = V_83 -> V_257 ;
V_2 = F_51 ( sizeof( * V_2 ) , V_38 ) ;
if ( ! V_2 )
return - V_85 ;
V_2 -> V_10 = F_51 ( sizeof( * V_2 -> V_10 ) ,
V_38 ) ;
if ( ! V_2 -> V_10 ) {
F_9 ( V_2 ) ;
return - V_85 ;
}
V_2 -> V_20 . V_21 = V_531 ;
V_2 -> V_20 . V_31 = V_54 ;
V_2 -> V_20 . type = V_176 ;
V_2 -> V_309 = V_33 -> V_309 ;
V_2 -> V_35 = V_33 -> V_35 ;
F_55 ( & V_2 -> V_7 , 1 ) ;
F_231 ( & V_2 -> V_49 ) ;
F_52 ( & V_2 -> V_86 ) ;
F_52 ( & V_2 -> V_529 ) ;
F_423 ( V_2 ) ;
F_307 ( & V_2 -> V_112 , V_267 ) ;
F_426 ( & V_2 -> V_112 , V_530 ) ;
V_2 -> V_6 = type ;
F_427 ( & V_2 -> V_112 , type ) ;
V_2 -> V_93 = ( T_2 ) - 1 ;
V_2 -> V_3 = V_4 ;
F_21 ( V_33 , V_2 ) ;
F_27 ( V_2 , V_33 -> V_35 , V_531 ,
V_531 + V_54 ) ;
F_19 ( V_33 , V_2 ) ;
V_27 = F_229 ( V_33 -> V_35 , V_2 -> V_6 , V_54 , V_267 ,
& V_2 -> V_99 ) ;
F_22 ( V_27 ) ;
F_284 ( V_33 -> V_35 ) ;
F_11 ( & V_2 -> V_99 -> V_49 ) ;
V_2 -> V_99 -> V_278 += V_2 -> V_44 ;
F_13 ( & V_2 -> V_99 -> V_49 ) ;
F_417 ( V_2 -> V_99 , V_2 ) ;
V_27 = F_10 ( V_33 -> V_35 , V_2 ) ;
F_22 ( V_27 ) ;
V_27 = F_428 ( V_83 , V_60 , & V_2 -> V_20 , & V_2 -> V_112 ,
sizeof( V_2 -> V_112 ) ) ;
if ( V_27 ) {
F_151 ( V_83 , V_60 , V_27 ) ;
return V_27 ;
}
F_233 ( V_60 -> V_35 , type ) ;
return 0 ;
}
static void F_429 ( struct V_11 * V_35 , T_2 V_6 )
{
T_2 V_283 = F_234 ( V_6 ) &
V_284 ;
if ( V_6 & V_285 )
V_35 -> V_286 &= ~ V_283 ;
if ( V_6 & V_114 )
V_35 -> V_287 &= ~ V_283 ;
if ( V_6 & V_288 )
V_35 -> V_289 &= ~ V_283 ;
}
int F_430 ( struct V_82 * V_83 ,
struct V_32 * V_33 , T_2 V_109 )
{
struct V_61 * V_62 ;
struct V_1 * V_13 ;
struct V_438 * V_213 ;
struct V_32 * V_230 = V_33 -> V_35 -> V_230 ;
struct V_65 V_20 ;
struct V_248 * V_248 ;
int V_27 ;
int V_434 ;
int V_104 ;
V_33 = V_33 -> V_35 -> V_60 ;
V_13 = F_65 ( V_33 -> V_35 , V_109 ) ;
F_22 ( ! V_13 ) ;
F_22 ( ! V_13 -> V_113 ) ;
F_19 ( V_33 , V_13 ) ;
memcpy ( & V_20 , & V_13 -> V_20 , sizeof( V_20 ) ) ;
V_434 = F_332 ( V_13 ) ;
if ( V_13 -> V_6 & ( V_268 |
V_269 |
V_270 ) )
V_104 = 2 ;
else
V_104 = 1 ;
V_213 = & V_33 -> V_35 -> V_454 ;
F_11 ( & V_213 -> V_459 ) ;
F_339 ( V_13 , V_213 ) ;
F_13 ( & V_213 -> V_459 ) ;
V_213 = & V_33 -> V_35 -> V_452 ;
F_11 ( & V_213 -> V_459 ) ;
F_339 ( V_13 , V_213 ) ;
F_13 ( & V_213 -> V_459 ) ;
V_62 = F_32 () ;
if ( ! V_62 ) {
V_27 = - V_85 ;
goto V_69;
}
V_248 = F_213 ( V_230 , V_13 , V_62 ) ;
if ( ! F_214 ( V_248 ) ) {
V_27 = F_431 ( V_83 , V_248 ) ;
if ( V_27 ) {
F_432 ( V_248 ) ;
goto V_69;
}
F_433 ( V_248 ) ;
F_11 ( & V_13 -> V_49 ) ;
if ( V_13 -> V_163 ) {
V_13 -> V_163 = 0 ;
V_13 -> V_248 = NULL ;
F_13 ( & V_13 -> V_49 ) ;
F_225 ( V_248 ) ;
} else {
F_13 ( & V_13 -> V_49 ) ;
}
F_432 ( V_248 ) ;
}
V_20 . V_21 = V_533 ;
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
F_60 ( & V_13 -> V_99 -> V_275 ) ;
F_172 ( & V_13 -> V_86 ) ;
if ( F_167 ( & V_13 -> V_99 -> V_274 [ V_434 ] ) )
F_429 ( V_33 -> V_35 , V_13 -> V_6 ) ;
F_62 ( & V_13 -> V_99 -> V_275 ) ;
if ( V_13 -> V_3 == V_50 )
F_330 ( V_13 ) ;
F_415 ( V_13 ) ;
F_11 ( & V_13 -> V_99 -> V_49 ) ;
V_13 -> V_99 -> V_266 -= V_13 -> V_20 . V_31 ;
V_13 -> V_99 -> V_278 -= V_13 -> V_20 . V_31 ;
V_13 -> V_99 -> V_271 -= V_13 -> V_20 . V_31 * V_104 ;
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
int F_434 ( struct V_11 * V_35 )
{
struct V_96 * V_99 ;
struct V_534 * V_535 ;
T_2 V_536 ;
T_2 V_6 ;
int V_537 = 0 ;
int V_27 ;
V_535 = V_35 -> V_327 ;
if ( ! F_435 ( V_535 ) )
return 1 ;
V_536 = F_436 ( V_535 ) ;
if ( V_536 & V_538 )
V_537 = 1 ;
V_6 = V_288 ;
V_27 = F_229 ( V_35 , V_6 , 0 , 0 , & V_99 ) ;
if ( V_27 )
goto V_69;
if ( V_537 ) {
V_6 = V_114 | V_285 ;
V_27 = F_229 ( V_35 , V_6 , 0 , 0 , & V_99 ) ;
} else {
V_6 = V_114 ;
V_27 = F_229 ( V_35 , V_6 , 0 , 0 , & V_99 ) ;
if ( V_27 )
goto V_69;
V_6 = V_285 ;
V_27 = F_229 ( V_35 , V_6 , 0 , 0 , & V_99 ) ;
}
V_69:
return V_27 ;
}
int F_437 ( struct V_32 * V_33 , T_2 V_30 , T_2 V_29 )
{
return F_316 ( V_33 , V_30 , V_29 ) ;
}
int F_438 ( struct V_32 * V_33 , T_2 V_25 ,
T_2 V_34 , T_2 * V_184 )
{
return F_145 ( V_33 , V_25 , V_34 , V_184 ) ;
}
int F_439 ( struct V_32 * V_33 , struct V_539 * V_540 )
{
struct V_11 * V_35 = V_33 -> V_35 ;
struct V_1 * V_2 = NULL ;
T_2 V_541 ;
T_2 V_30 ;
T_2 V_29 ;
T_2 V_542 = 0 ;
T_2 V_266 = F_247 ( V_35 -> V_327 ) ;
int V_27 = 0 ;
if ( V_540 -> V_115 == V_266 )
V_2 = F_64 ( V_35 , V_540 -> V_30 ) ;
else
V_2 = F_65 ( V_35 , V_540 -> V_30 ) ;
while ( V_2 ) {
if ( V_2 -> V_20 . V_21 >= ( V_540 -> V_30 + V_540 -> V_115 ) ) {
F_6 ( V_2 ) ;
break;
}
V_30 = F_75 ( V_540 -> V_30 , V_2 -> V_20 . V_21 ) ;
V_29 = F_257 ( V_540 -> V_30 + V_540 -> V_115 ,
V_2 -> V_20 . V_21 + V_2 -> V_20 . V_31 ) ;
if ( V_29 - V_30 >= V_540 -> V_543 ) {
if ( ! F_1 ( V_2 ) ) {
V_27 = F_49 ( V_2 , NULL , V_33 , 0 ) ;
if ( ! V_27 )
F_330 ( V_2 ) ;
}
V_27 = F_440 ( V_2 ,
& V_541 ,
V_30 ,
V_29 ,
V_540 -> V_543 ) ;
V_542 += V_541 ;
if ( V_27 ) {
F_6 ( V_2 ) ;
break;
}
}
V_2 = F_211 ( V_35 -> V_230 , V_2 ) ;
}
V_540 -> V_115 = V_542 ;
return V_27 ;
}
