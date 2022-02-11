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
struct V_11 * V_35 = V_33 -> V_35 ;
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
F_170 ( V_83 , V_35 , V_119 ,
V_214 ) ;
V_151 = F_171 ( V_214 ) ;
if ( V_151 && V_151 -> V_217 &&
F_172 ( V_35 , V_119 , V_151 -> V_217 ) ) {
F_173 ( & V_214 -> V_213 ) ;
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
F_174 ( V_219 L_1 , V_27 ) ;
F_11 ( & V_119 -> V_49 ) ;
return V_27 ;
}
goto V_216;
}
F_173 ( & V_214 -> V_213 ) ;
V_214 = NULL ;
}
V_151 -> V_220 = 0 ;
F_175 ( & V_151 -> V_14 , & V_119 -> V_33 ) ;
V_119 -> V_221 -- ;
if ( V_214 ) {
switch ( V_151 -> V_207 ) {
case V_200 :
case V_222 :
V_214 -> V_130 . V_134 -= V_151 -> V_134 ;
break;
case V_209 :
V_214 -> V_130 . V_134 += V_151 -> V_134 ;
break;
default:
F_8 ( 1 ) ;
}
}
F_13 ( & V_119 -> V_49 ) ;
V_27 = F_161 ( V_83 , V_33 , V_151 , V_131 ,
V_215 ) ;
F_89 ( V_151 ) ;
F_9 ( V_131 ) ;
V_7 ++ ;
if ( V_27 ) {
F_174 ( V_219 L_2 , V_27 ) ;
F_11 ( & V_119 -> V_49 ) ;
return V_27 ;
}
V_216:
F_176 ( V_83 , V_35 -> V_60 ,
2 * 1024 * 1024 ,
F_177 ( V_33 , 0 ) ,
V_223 ) ;
F_46 () ;
F_11 ( & V_119 -> V_49 ) ;
}
return V_7 ;
}
static T_2 F_178 ( struct V_224 * V_33 )
{
struct V_14 * V_28 = V_33 -> V_14 ;
struct V_202 * V_225 ;
int V_226 = 1 ;
T_2 V_227 ;
T_2 V_228 = 0 , V_67 = 0 ;
V_28 = F_179 ( V_33 ) ;
if ( V_28 ) {
V_225 = F_12 ( V_28 , struct V_202 , V_14 ) ;
V_228 = V_225 -> V_25 ;
}
V_28 = F_180 ( V_33 ) ;
if ( V_28 ) {
V_225 = F_12 ( V_28 , struct V_202 , V_14 ) ;
V_67 = V_225 -> V_25 ;
}
V_28 = V_33 -> V_14 ;
while ( V_28 ) {
V_225 = F_12 ( V_28 , struct V_202 , V_14 ) ;
F_8 ( ! V_225 -> V_220 ) ;
V_227 = V_225 -> V_25 ;
if ( V_226 )
V_28 = V_28 -> V_22 ;
else
V_28 = V_28 -> V_23 ;
V_226 = 1 - V_226 ;
}
return V_227 ;
}
int F_181 ( struct V_82 * V_83 ,
struct V_11 * V_35 )
{
struct V_229 * V_229 ;
int V_27 = 0 ;
if ( F_167 ( & V_83 -> V_230 ) !=
! V_83 -> V_231 . V_217 ) {
F_174 ( V_232 L_3 ,
F_167 ( & V_83 -> V_230 ) ? L_4 : L_5 ,
V_83 -> V_231 . V_217 ) ;
F_86 () ;
}
if ( ! V_83 -> V_231 . V_217 )
return 0 ;
while ( ! F_167 ( & V_83 -> V_230 ) ) {
V_229 = F_182 ( & V_83 -> V_230 ,
struct V_229 , V_86 ) ;
F_183 ( & V_229 -> V_86 ) ;
if ( ! V_27 )
V_27 = F_184 (
V_83 , V_35 , V_229 -> V_130 ,
V_229 -> V_131 ) ;
F_9 ( V_229 ) ;
}
F_185 ( V_35 , & V_83 -> V_231 ) ;
return V_27 ;
}
int F_186 ( struct V_82 * V_83 ,
struct V_32 * V_33 , unsigned long V_7 )
{
struct V_14 * V_130 ;
struct V_118 * V_119 ;
struct V_202 * V_151 ;
struct V_97 V_213 ;
int V_27 ;
T_2 V_233 ;
int V_234 = V_7 == ( unsigned long ) - 1 ;
int V_235 = 0 ;
int V_236 ;
if ( V_83 -> V_210 )
return 0 ;
if ( V_33 == V_33 -> V_35 -> V_60 )
V_33 = V_33 -> V_35 -> V_237 ;
F_176 ( V_83 , V_33 -> V_35 -> V_60 ,
2 * 1024 * 1024 , F_177 ( V_33 , 0 ) ,
V_223 ) ;
F_181 ( V_83 , V_33 -> V_35 ) ;
V_119 = & V_83 -> V_129 -> V_119 ;
F_52 ( & V_213 ) ;
V_74:
V_236 = 0 ;
F_11 ( & V_119 -> V_49 ) ;
#ifdef F_187
V_119 -> V_238 = F_178 ( & V_119 -> V_33 ) ;
#endif
if ( V_7 == 0 ) {
V_7 = V_119 -> V_221 * 2 ;
V_235 = 1 ;
}
while ( 1 ) {
if ( ! ( V_234 || V_235 ) &&
V_119 -> V_218 < 64 )
break;
V_233 = V_119 -> V_238 ;
V_27 = F_188 ( V_83 , & V_213 ,
V_119 -> V_238 ) ;
if ( V_27 )
break;
V_27 = F_166 ( V_83 , V_33 , & V_213 ) ;
if ( V_27 < 0 ) {
F_13 ( & V_119 -> V_49 ) ;
F_151 ( V_83 , V_33 , V_27 ) ;
return V_27 ;
}
V_7 -= F_189 (unsigned long, ret, count) ;
if ( V_7 == 0 )
break;
if ( V_233 >= V_119 -> V_238 ) {
if ( V_236 == 0 ) {
V_236 = 1 ;
} else {
F_22 ( V_234 ) ;
break;
}
}
if ( V_27 ) {
V_236 = 0 ;
}
}
if ( V_234 ) {
V_130 = F_179 ( & V_119 -> V_33 ) ;
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
V_130 = F_190 ( V_130 ) ;
}
F_13 ( & V_119 -> V_49 ) ;
F_191 ( 1 ) ;
goto V_74;
}
V_69:
F_13 ( & V_119 -> V_49 ) ;
F_192 ( V_83 ) ;
return 0 ;
}
int F_193 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
T_2 V_25 , T_2 V_34 , T_2 V_6 ,
int V_181 )
{
struct V_177 * V_131 ;
int V_27 ;
V_131 = F_194 ( sizeof( * V_131 ) , V_38 ) ;
if ( ! V_131 )
return - V_85 ;
V_131 -> V_133 = V_6 ;
V_131 -> V_132 = 1 ;
V_131 -> V_208 = 0 ;
V_131 -> V_181 = V_181 ? 1 : 0 ;
V_27 = F_195 ( V_33 -> V_35 , V_83 , V_25 ,
V_34 , V_131 ) ;
if ( V_27 )
F_9 ( V_131 ) ;
return V_27 ;
}
static T_1 int F_196 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_61 * V_62 ,
T_2 V_21 , T_2 V_31 , T_2 V_25 )
{
struct V_117 * V_98 ;
struct V_202 * V_151 ;
struct V_204 * V_239 ;
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
V_130 = F_197 ( & V_98 -> V_130 . V_14 ) ;
if ( ! V_130 )
goto V_240;
V_151 = F_12 ( V_130 , struct V_202 , V_14 ) ;
if ( V_151 -> V_25 != V_25 )
goto V_240;
V_27 = 1 ;
if ( V_151 -> type != V_155 )
goto V_240;
V_239 = F_153 ( V_151 ) ;
V_130 = F_197 ( V_130 ) ;
if ( V_130 ) {
int V_217 = V_151 -> V_217 ;
V_151 = F_12 ( V_130 , struct V_202 , V_14 ) ;
if ( V_151 -> V_25 == V_25 && V_151 -> V_217 == V_217 )
goto V_240;
}
if ( V_239 -> V_33 != V_33 -> V_241 . V_21 ||
V_239 -> V_21 != V_21 || V_239 -> V_31 != V_31 )
goto V_240;
V_27 = 0 ;
V_240:
F_45 ( & V_98 -> V_75 ) ;
V_69:
F_13 ( & V_119 -> V_49 ) ;
return V_27 ;
}
static T_1 int F_198 ( struct V_82 * V_83 ,
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
if ( F_199 ( V_64 , V_121 ) <=
F_200 ( & V_33 -> V_242 ) )
goto V_69;
V_163 = (struct V_162 * ) ( V_121 + 1 ) ;
if ( F_122 ( V_64 , V_163 ) !=
V_155 )
goto V_69;
V_151 = (struct V_150 * ) ( & V_163 -> V_31 ) ;
if ( F_82 ( V_64 , V_121 ) !=
F_116 ( V_64 , V_151 ) ||
F_103 ( V_64 , V_151 ) !=
V_33 -> V_241 . V_21 ||
F_104 ( V_64 , V_151 ) != V_21 ||
F_105 ( V_64 , V_151 ) != V_31 )
goto V_69;
V_27 = 0 ;
V_69:
return V_27 ;
}
int F_201 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
T_2 V_21 , T_2 V_31 , T_2 V_25 )
{
struct V_61 * V_62 ;
int V_27 ;
int V_243 ;
V_62 = F_32 () ;
if ( ! V_62 )
return - V_153 ;
do {
V_27 = F_198 ( V_83 , V_33 , V_62 , V_21 ,
V_31 , V_25 ) ;
if ( V_27 && V_27 != - V_153 )
goto V_69;
V_243 = F_196 ( V_83 , V_33 , V_62 , V_21 ,
V_31 , V_25 ) ;
} while ( V_243 == - V_175 );
if ( V_243 && V_243 != - V_153 ) {
V_27 = V_243 ;
goto V_69;
}
if ( V_27 != - V_153 || V_243 != - V_153 )
V_27 = 0 ;
V_69:
F_48 ( V_62 ) ;
if ( V_33 -> V_241 . V_21 == V_244 )
F_8 ( V_27 > 0 ) ;
return V_27 ;
}
static int F_202 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_63 * V_245 ,
int V_246 , int V_247 , int V_198 )
{
T_2 V_25 ;
T_2 V_34 ;
T_2 V_16 ;
T_2 V_206 ;
T_3 V_68 ;
struct V_65 V_20 ;
struct V_248 * V_249 ;
int V_41 ;
int V_166 ;
int V_27 = 0 ;
int (* F_203)( struct V_82 * , struct V_32 * ,
T_2 , T_2 , T_2 , T_2 , T_2 , T_2 , int );
V_206 = F_204 ( V_245 ) ;
V_68 = F_37 ( V_245 ) ;
V_166 = F_205 ( V_245 ) ;
if ( ! V_33 -> V_250 && V_166 == 0 )
return 0 ;
if ( V_247 )
F_203 = F_147 ;
else
F_203 = V_251 ;
if ( V_246 )
V_16 = V_245 -> V_30 ;
else
V_16 = 0 ;
for ( V_41 = 0 ; V_41 < V_68 ; V_41 ++ ) {
if ( V_166 == 0 ) {
F_39 ( V_245 , & V_20 , V_41 ) ;
if ( F_206 ( & V_20 ) != V_252 )
continue;
V_249 = F_81 ( V_245 , V_41 ,
struct V_248 ) ;
if ( F_207 ( V_245 , V_249 ) ==
V_253 )
continue;
V_25 = F_208 ( V_245 , V_249 ) ;
if ( V_25 == 0 )
continue;
V_34 = F_209 ( V_245 , V_249 ) ;
V_20 . V_31 -= F_210 ( V_245 , V_249 ) ;
V_27 = F_203 ( V_83 , V_33 , V_25 , V_34 ,
V_16 , V_206 , V_20 . V_21 ,
V_20 . V_31 , V_198 ) ;
if ( V_27 )
goto V_156;
} else {
V_25 = F_211 ( V_245 , V_41 ) ;
V_34 = F_212 ( V_33 , V_166 - 1 ) ;
V_27 = F_203 ( V_83 , V_33 , V_25 , V_34 ,
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
int F_213 ( struct V_82 * V_83 , struct V_32 * V_33 ,
struct V_63 * V_245 , int V_246 , int V_198 )
{
return F_202 ( V_83 , V_33 , V_245 , V_246 , 1 , V_198 ) ;
}
int F_214 ( struct V_82 * V_83 , struct V_32 * V_33 ,
struct V_63 * V_245 , int V_246 , int V_198 )
{
return F_202 ( V_83 , V_33 , V_245 , V_246 , 0 , V_198 ) ;
}
static int F_215 ( struct V_82 * V_83 ,
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
V_139 = F_216 ( V_64 , V_62 -> V_79 [ 0 ] ) ;
F_217 ( V_64 , & V_2 -> V_112 , V_139 , sizeof( V_2 -> V_112 ) ) ;
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
F_218 ( struct V_32 * V_33 ,
struct V_1 * V_2 )
{
struct V_14 * V_130 ;
F_11 ( & V_33 -> V_35 -> V_17 ) ;
V_130 = F_190 ( & V_2 -> V_19 ) ;
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
static int F_219 ( struct V_1 * V_13 ,
struct V_82 * V_83 ,
struct V_61 * V_62 )
{
struct V_32 * V_33 = V_13 -> V_35 -> V_237 ;
struct V_254 * V_254 = NULL ;
T_2 V_255 = 0 ;
int V_256 = V_257 ;
int V_258 = 0 ;
int V_259 = 0 ;
int V_27 = 0 ;
if ( V_13 -> V_20 . V_31 < ( 100 * 1024 * 1024 ) ) {
F_11 ( & V_13 -> V_49 ) ;
V_13 -> V_260 = V_261 ;
F_13 ( & V_13 -> V_49 ) ;
return 0 ;
}
V_74:
V_254 = F_220 ( V_33 , V_13 , V_62 ) ;
if ( F_221 ( V_254 ) && F_222 ( V_254 ) != - V_153 ) {
V_27 = F_222 ( V_254 ) ;
F_43 ( V_62 ) ;
goto V_69;
}
if ( F_221 ( V_254 ) ) {
F_22 ( V_259 ) ;
V_259 ++ ;
if ( V_13 -> V_113 )
goto V_125;
V_27 = F_223 ( V_33 , V_83 , V_13 , V_62 ) ;
if ( V_27 )
goto V_125;
goto V_74;
}
if ( V_13 -> V_262 == V_83 -> V_263 &&
F_224 ( V_254 ) ) {
V_256 = V_264 ;
goto V_265;
}
F_225 ( V_254 ) -> V_266 = 0 ;
V_27 = F_226 ( V_83 , V_33 , V_254 ) ;
F_8 ( V_27 ) ;
if ( F_224 ( V_254 ) > 0 ) {
V_27 = F_227 ( V_33 , V_83 , V_62 ,
V_254 ) ;
if ( V_27 )
goto V_265;
}
F_11 ( & V_13 -> V_49 ) ;
if ( V_13 -> V_3 != V_4 ||
! F_228 ( V_33 , V_267 ) ) {
V_256 = V_261 ;
F_13 ( & V_13 -> V_49 ) ;
goto V_265;
}
F_13 ( & V_13 -> V_49 ) ;
V_258 = ( int ) F_229 ( V_13 -> V_20 . V_31 , 256 * 1024 * 1024 ) ;
if ( ! V_258 )
V_258 = 1 ;
V_258 *= 16 ;
V_258 *= V_268 ;
V_27 = F_230 ( V_254 , V_258 ) ;
if ( V_27 )
goto V_265;
V_27 = F_231 ( V_254 , V_83 , 0 , 0 , V_258 ,
V_258 , V_258 ,
& V_255 ) ;
if ( ! V_27 )
V_256 = V_264 ;
F_232 ( V_254 , V_258 ) ;
V_265:
F_233 ( V_254 ) ;
V_125:
F_43 ( V_62 ) ;
V_69:
F_11 ( & V_13 -> V_49 ) ;
if ( ! V_27 && V_256 == V_264 )
V_13 -> V_262 = V_83 -> V_263 ;
V_13 -> V_260 = V_256 ;
F_13 ( & V_13 -> V_49 ) ;
return V_27 ;
}
int F_234 ( struct V_82 * V_83 ,
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
if ( V_2 -> V_260 == V_269 )
break;
V_2 = F_218 ( V_33 , V_2 ) ;
}
if ( ! V_2 ) {
if ( V_67 == 0 )
break;
V_67 = 0 ;
continue;
}
V_77 = F_219 ( V_2 , V_83 , V_62 ) ;
V_67 = V_2 -> V_20 . V_21 + V_2 -> V_20 . V_31 ;
F_6 ( V_2 ) ;
}
while ( 1 ) {
if ( V_67 == 0 ) {
V_77 = F_186 ( V_83 , V_33 ,
( unsigned long ) - 1 ) ;
if ( V_77 )
goto V_69;
}
V_2 = F_64 ( V_33 -> V_35 , V_67 ) ;
while ( V_2 ) {
if ( V_2 -> V_260 == V_269 ) {
F_6 ( V_2 ) ;
goto V_74;
}
if ( V_2 -> V_270 )
break;
V_2 = F_218 ( V_33 , V_2 ) ;
}
if ( ! V_2 ) {
if ( V_67 == 0 )
break;
V_67 = 0 ;
continue;
}
if ( V_2 -> V_260 == V_264 )
V_2 -> V_260 = V_271 ;
V_2 -> V_270 = 0 ;
V_67 = V_2 -> V_20 . V_21 + V_2 -> V_20 . V_31 ;
V_77 = F_215 ( V_83 , V_33 , V_62 , V_2 ) ;
if ( V_77 )
goto V_69;
F_6 ( V_2 ) ;
}
while ( 1 ) {
if ( V_67 == 0 ) {
V_77 = F_186 ( V_83 , V_33 ,
( unsigned long ) - 1 ) ;
if ( V_77 )
goto V_69;
}
V_2 = F_64 ( V_33 -> V_35 , V_67 ) ;
while ( V_2 ) {
if ( V_2 -> V_270 ) {
F_6 ( V_2 ) ;
goto V_74;
}
if ( V_2 -> V_260 == V_271 )
break;
V_2 = F_218 ( V_33 , V_2 ) ;
}
if ( ! V_2 ) {
if ( V_67 == 0 )
break;
V_67 = 0 ;
continue;
}
V_77 = F_235 ( V_33 , V_83 , V_2 , V_62 ) ;
if ( ! V_77 && V_2 -> V_260 == V_271 )
V_2 -> V_260 = V_261 ;
V_67 = V_2 -> V_20 . V_21 + V_2 -> V_20 . V_31 ;
F_6 ( V_2 ) ;
}
V_69:
F_48 ( V_62 ) ;
return V_77 ;
}
int F_236 ( struct V_32 * V_33 , T_2 V_25 )
{
struct V_1 * V_13 ;
int V_272 = 0 ;
V_13 = F_65 ( V_33 -> V_35 , V_25 ) ;
if ( ! V_13 || V_13 -> V_113 )
V_272 = 1 ;
if ( V_13 )
F_6 ( V_13 ) ;
return V_272 ;
}
static int F_237 ( struct V_11 * V_12 , T_2 V_6 ,
T_2 V_273 , T_2 V_274 ,
struct V_96 * * V_99 )
{
struct V_96 * V_100 ;
int V_41 ;
int V_104 ;
if ( V_6 & ( V_275 | V_276 |
V_277 ) )
V_104 = 2 ;
else
V_104 = 1 ;
V_100 = F_66 ( V_12 , V_6 ) ;
if ( V_100 ) {
F_11 ( & V_100 -> V_49 ) ;
V_100 -> V_273 += V_273 ;
V_100 -> V_278 += V_273 * V_104 ;
V_100 -> V_274 += V_274 ;
V_100 -> V_279 += V_274 * V_104 ;
V_100 -> V_102 = 0 ;
F_13 ( & V_100 -> V_49 ) ;
* V_99 = V_100 ;
return 0 ;
}
V_100 = F_51 ( sizeof( * V_100 ) , V_38 ) ;
if ( ! V_100 )
return - V_85 ;
for ( V_41 = 0 ; V_41 < V_280 ; V_41 ++ )
F_52 ( & V_100 -> V_281 [ V_41 ] ) ;
F_238 ( & V_100 -> V_282 ) ;
F_239 ( & V_100 -> V_49 ) ;
V_100 -> V_6 = V_6 & V_101 ;
V_100 -> V_273 = V_273 ;
V_100 -> V_278 = V_273 * V_104 ;
V_100 -> V_274 = V_274 ;
V_100 -> V_279 = V_274 * V_104 ;
V_100 -> V_283 = 0 ;
V_100 -> V_284 = 0 ;
V_100 -> V_285 = 0 ;
V_100 -> V_286 = 0 ;
V_100 -> V_102 = 0 ;
V_100 -> V_287 = V_223 ;
V_100 -> V_288 = 0 ;
V_100 -> V_289 = 0 ;
F_54 ( & V_100 -> V_81 ) ;
* V_99 = V_100 ;
F_240 ( & V_100 -> V_86 , & V_12 -> V_99 ) ;
if ( V_6 & V_290 )
V_12 -> V_291 = V_100 ;
return 0 ;
}
static void F_241 ( struct V_11 * V_35 , T_2 V_6 )
{
T_2 V_292 = F_242 ( V_6 ) &
V_293 ;
if ( V_6 & V_290 )
V_35 -> V_294 |= V_292 ;
if ( V_6 & V_114 )
V_35 -> V_295 |= V_292 ;
if ( V_6 & V_296 )
V_35 -> V_297 |= V_292 ;
}
static T_2 F_243 ( struct V_11 * V_35 , T_2 V_6 )
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
} else if ( V_6 & V_114 &&
V_299 -> V_305 . V_6 & V_303 ) {
V_301 = V_114 | V_299 -> V_305 . V_301 ;
}
return V_301 ;
}
T_2 F_244 ( struct V_32 * V_33 , T_2 V_6 )
{
T_2 V_306 = V_33 -> V_35 -> V_307 -> V_308 +
V_33 -> V_35 -> V_307 -> V_309 ;
T_2 V_301 ;
F_11 ( & V_33 -> V_35 -> V_310 ) ;
V_301 = F_243 ( V_33 -> V_35 , V_6 ) ;
if ( V_301 ) {
if ( ( V_6 & V_301 ) & V_293 ) {
F_13 ( & V_33 -> V_35 -> V_310 ) ;
return F_245 ( V_301 ) ;
}
}
F_13 ( & V_33 -> V_35 -> V_310 ) ;
if ( V_306 == 1 )
V_6 &= ~ ( V_276 | V_311 ) ;
if ( V_306 < 4 )
V_6 &= ~ V_277 ;
if ( ( V_6 & V_275 ) &&
( V_6 & ( V_276 |
V_277 ) ) ) {
V_6 &= ~ V_275 ;
}
if ( ( V_6 & V_276 ) &&
( V_6 & V_277 ) ) {
V_6 &= ~ V_276 ;
}
if ( ( V_6 & V_311 ) &&
( ( V_6 & V_276 ) |
( V_6 & V_277 ) |
( V_6 & V_275 ) ) ) {
V_6 &= ~ V_311 ;
}
return F_245 ( V_6 ) ;
}
static T_2 F_246 ( struct V_32 * V_33 , T_2 V_6 )
{
if ( V_6 & V_290 )
V_6 |= V_33 -> V_35 -> V_294 ;
else if ( V_6 & V_296 )
V_6 |= V_33 -> V_35 -> V_297 ;
else if ( V_6 & V_114 )
V_6 |= V_33 -> V_35 -> V_295 ;
return F_244 ( V_33 , V_6 ) ;
}
T_2 F_177 ( struct V_32 * V_33 , int V_302 )
{
T_2 V_6 ;
if ( V_302 )
V_6 = V_290 ;
else if ( V_33 == V_33 -> V_35 -> V_312 )
V_6 = V_296 ;
else
V_6 = V_114 ;
return F_246 ( V_33 , V_6 ) ;
}
int F_230 ( struct V_254 * V_254 , T_2 V_313 )
{
struct V_96 * V_291 ;
struct V_32 * V_33 = F_225 ( V_254 ) -> V_33 ;
struct V_11 * V_35 = V_33 -> V_35 ;
T_2 V_108 ;
int V_27 = 0 , V_314 = 0 , V_315 = 1 ;
V_313 = ( V_313 + V_33 -> V_316 - 1 ) & ~ ( ( T_2 ) V_33 -> V_316 - 1 ) ;
if ( V_33 == V_33 -> V_35 -> V_237 ||
F_225 ( V_254 ) -> V_317 . V_21 == V_318 ) {
V_315 = 0 ;
V_314 = 1 ;
}
V_291 = V_35 -> V_291 ;
if ( ! V_291 )
goto V_319;
V_74:
F_11 ( & V_291 -> V_49 ) ;
V_108 = V_291 -> V_274 + V_291 -> V_284 +
V_291 -> V_283 + V_291 -> V_285 +
V_291 -> V_286 ;
if ( V_108 + V_313 > V_291 -> V_273 ) {
struct V_82 * V_83 ;
if ( ! V_291 -> V_102 && V_315 ) {
T_2 V_320 ;
V_291 -> V_287 = V_321 ;
F_13 ( & V_291 -> V_49 ) ;
V_319:
V_320 = F_177 ( V_33 , 1 ) ;
V_83 = F_247 ( V_33 ) ;
if ( F_221 ( V_83 ) )
return F_222 ( V_83 ) ;
V_27 = F_176 ( V_83 , V_33 -> V_35 -> V_60 ,
V_313 + 2 * 1024 * 1024 ,
V_320 ,
V_223 ) ;
F_248 ( V_83 , V_33 ) ;
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
if ( V_291 -> V_283 < V_313 )
V_314 = 1 ;
F_13 ( & V_291 -> V_49 ) ;
V_323:
if ( ! V_314 &&
! F_249 ( & V_33 -> V_35 -> V_324 ) ) {
V_314 = 1 ;
V_83 = F_247 ( V_33 ) ;
if ( F_221 ( V_83 ) )
return F_222 ( V_83 ) ;
V_27 = F_250 ( V_83 , V_33 ) ;
if ( V_27 )
return V_27 ;
goto V_74;
}
return - V_322 ;
}
V_291 -> V_286 += V_313 ;
F_251 ( V_33 -> V_35 , L_6 ,
V_291 -> V_6 , V_313 , 1 ) ;
F_13 ( & V_291 -> V_49 ) ;
return 0 ;
}
void F_232 ( struct V_254 * V_254 , T_2 V_313 )
{
struct V_32 * V_33 = F_225 ( V_254 ) -> V_33 ;
struct V_96 * V_291 ;
V_313 = ( V_313 + V_33 -> V_316 - 1 ) & ~ ( ( T_2 ) V_33 -> V_316 - 1 ) ;
V_291 = V_33 -> V_35 -> V_291 ;
F_11 ( & V_291 -> V_49 ) ;
V_291 -> V_286 -= V_313 ;
F_251 ( V_33 -> V_35 , L_6 ,
V_291 -> V_6 , V_313 , 0 ) ;
F_13 ( & V_291 -> V_49 ) ;
}
static void F_252 ( struct V_11 * V_12 )
{
struct V_97 * V_98 = & V_12 -> V_99 ;
struct V_96 * V_100 ;
F_67 () ;
F_68 (found, head, list) {
if ( V_100 -> V_6 & V_114 )
V_100 -> V_287 = V_321 ;
}
F_69 () ;
}
static int F_253 ( struct V_32 * V_33 ,
struct V_96 * V_325 , T_2 V_326 ,
int V_327 )
{
struct V_328 * V_329 = & V_33 -> V_35 -> V_330 ;
T_2 V_34 = V_325 -> V_273 - V_325 -> V_285 ;
T_2 V_331 = V_325 -> V_274 + V_325 -> V_284 ;
T_2 V_332 ;
if ( V_327 == V_321 )
return 1 ;
V_331 += V_329 -> V_54 ;
if ( V_327 == V_333 ) {
V_332 = F_254 ( V_33 -> V_35 -> V_334 ) ;
V_332 = F_33 ( T_2 , 64 * 1024 * 1024 ,
F_73 ( V_332 , 1 ) ) ;
if ( V_34 - V_331 < V_332 )
return 1 ;
}
V_332 = F_254 ( V_33 -> V_35 -> V_334 ) ;
V_332 = F_33 ( T_2 , 256 * 1024 * 1024 , F_73 ( V_332 , 2 ) ) ;
if ( V_325 -> V_6 & V_296 )
V_332 = 32 * 1024 * 1024 ;
if ( V_34 > V_332 && V_325 -> V_274 < F_71 ( V_34 , 8 ) )
return 0 ;
return 1 ;
}
static T_2 F_255 ( struct V_32 * V_33 , T_2 type )
{
T_2 V_335 ;
if ( type & V_277 ||
type & V_311 )
V_335 = V_33 -> V_35 -> V_307 -> V_308 ;
else if ( type & V_276 )
V_335 = 2 ;
else
V_335 = 1 ;
return F_256 ( V_33 , V_335 + 1 ) ;
}
static void F_257 ( struct V_82 * V_83 ,
struct V_32 * V_33 , T_2 type )
{
struct V_96 * V_12 ;
T_2 V_336 ;
T_2 V_332 ;
V_12 = F_66 ( V_33 -> V_35 , V_296 ) ;
F_11 ( & V_12 -> V_49 ) ;
V_336 = V_12 -> V_273 - V_12 -> V_274 - V_12 -> V_283 -
V_12 -> V_284 - V_12 -> V_285 ;
F_13 ( & V_12 -> V_49 ) ;
V_332 = F_255 ( V_33 , type ) ;
if ( V_336 < V_332 && F_228 ( V_33 , V_337 ) ) {
F_174 ( V_338 L_7 ,
V_336 , V_332 , type ) ;
F_258 ( V_12 , 0 , 0 ) ;
}
if ( V_336 < V_332 ) {
T_2 V_6 ;
V_6 = F_177 ( V_33 -> V_35 -> V_312 , 0 ) ;
F_259 ( V_83 , V_33 , V_6 ) ;
}
}
static int F_176 ( struct V_82 * V_83 ,
struct V_32 * V_60 , T_2 V_326 ,
T_2 V_6 , int V_327 )
{
struct V_96 * V_99 ;
struct V_11 * V_35 = V_60 -> V_35 ;
int V_339 = 0 ;
int V_27 = 0 ;
V_99 = F_66 ( V_60 -> V_35 , V_6 ) ;
if ( ! V_99 ) {
V_27 = F_237 ( V_60 -> V_35 , V_6 ,
0 , 0 , & V_99 ) ;
F_22 ( V_27 ) ;
}
F_22 ( ! V_99 ) ;
V_74:
F_11 ( & V_99 -> V_49 ) ;
if ( V_327 < V_99 -> V_287 )
V_327 = V_99 -> V_287 ;
if ( V_99 -> V_102 ) {
F_13 ( & V_99 -> V_49 ) ;
return 0 ;
}
if ( ! F_253 ( V_60 , V_99 , V_326 , V_327 ) ) {
F_13 ( & V_99 -> V_49 ) ;
return 0 ;
} else if ( V_99 -> V_288 ) {
V_339 = 1 ;
} else {
V_99 -> V_288 = 1 ;
}
F_13 ( & V_99 -> V_49 ) ;
F_34 ( & V_35 -> V_340 ) ;
if ( V_339 ) {
F_45 ( & V_35 -> V_340 ) ;
V_339 = 0 ;
goto V_74;
}
if ( F_260 ( V_99 ) )
V_6 |= ( V_290 | V_114 ) ;
if ( V_6 & V_290 && V_35 -> V_341 ) {
V_35 -> V_342 ++ ;
if ( ! ( V_35 -> V_342 %
V_35 -> V_341 ) )
F_252 ( V_35 ) ;
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
V_99 -> V_287 = V_223 ;
V_99 -> V_288 = 0 ;
F_13 ( & V_99 -> V_49 ) ;
V_69:
F_45 ( & V_35 -> V_340 ) ;
return V_27 ;
}
static void F_261 ( struct V_32 * V_33 , T_2 V_343 , T_2 V_344 ,
bool V_345 )
{
struct V_328 * V_346 ;
struct V_96 * V_99 ;
struct V_82 * V_83 ;
T_2 V_347 ;
T_2 V_348 ;
long V_349 ;
unsigned long V_350 = ( 2 * 1024 * 1024 ) >> V_351 ;
int V_236 = 0 ;
V_83 = (struct V_82 * ) V_352 -> V_353 ;
V_346 = & V_33 -> V_35 -> V_354 ;
V_99 = V_346 -> V_99 ;
F_2 () ;
V_347 = V_33 -> V_35 -> V_347 ;
if ( V_347 == 0 ) {
if ( V_83 )
return;
F_262 ( V_33 , 0 , 0 ) ;
return;
}
while ( V_347 && V_236 < 3 ) {
V_348 = F_263 ( V_347 , V_343 ) ;
V_350 = V_348 >> V_351 ;
F_264 ( V_33 -> V_35 -> V_355 , V_350 ,
V_356 ) ;
F_11 ( & V_99 -> V_49 ) ;
if ( V_99 -> V_274 + V_99 -> V_284 +
V_99 -> V_283 + V_99 -> V_285 +
V_99 -> V_286 + V_344 <=
V_99 -> V_273 ) {
F_13 ( & V_99 -> V_49 ) ;
break;
}
F_13 ( & V_99 -> V_49 ) ;
V_236 ++ ;
if ( V_345 && ! V_83 ) {
F_262 ( V_33 , 0 , 0 ) ;
} else {
V_349 = F_265 ( 1 ) ;
if ( V_349 )
break;
}
F_2 () ;
V_347 = V_33 -> V_35 -> V_347 ;
}
}
static int F_266 ( struct V_32 * V_33 ,
struct V_96 * V_99 ,
T_2 V_313 , int V_327 )
{
struct V_328 * V_357 = & V_33 -> V_35 -> V_358 ;
struct V_82 * V_83 ;
V_83 = (struct V_82 * ) V_352 -> V_353 ;
if ( V_83 )
return - V_175 ;
if ( V_327 )
goto V_359;
F_11 ( & V_99 -> V_49 ) ;
if ( V_99 -> V_283 >= V_313 ) {
F_13 ( & V_99 -> V_49 ) ;
goto V_359;
}
F_13 ( & V_99 -> V_49 ) ;
if ( V_99 != V_357 -> V_99 )
return - V_322 ;
F_11 ( & V_99 -> V_49 ) ;
F_11 ( & V_357 -> V_49 ) ;
if ( V_99 -> V_283 + V_357 -> V_54 < V_313 ) {
F_13 ( & V_357 -> V_49 ) ;
F_13 ( & V_99 -> V_49 ) ;
return - V_322 ;
}
F_13 ( & V_357 -> V_49 ) ;
F_13 ( & V_99 -> V_49 ) ;
V_359:
V_83 = F_247 ( V_33 ) ;
if ( F_221 ( V_83 ) )
return - V_322 ;
return F_250 ( V_83 , V_33 ) ;
}
static int F_267 ( struct V_32 * V_33 ,
struct V_96 * V_99 , T_2 V_34 ,
T_2 V_360 , int V_361 )
{
struct V_82 * V_83 ;
int V_42 ;
int V_27 = 0 ;
switch ( V_361 ) {
case V_362 :
case V_363 :
F_261 ( V_33 , V_34 , V_360 ,
V_361 == V_363 ) ;
break;
case V_364 :
case V_365 :
if ( V_361 == V_364 ) {
T_2 V_313 = F_256 ( V_33 , 1 ) ;
V_42 = ( int ) F_229 ( V_34 , V_313 ) ;
if ( ! V_42 )
V_42 = 1 ;
V_42 *= 2 ;
} else {
V_42 = - 1 ;
}
V_83 = F_247 ( V_33 ) ;
if ( F_221 ( V_83 ) ) {
V_27 = F_222 ( V_83 ) ;
break;
}
V_27 = F_268 ( V_83 , V_33 , V_42 ) ;
F_248 ( V_83 , V_33 ) ;
break;
case V_366 :
V_27 = F_266 ( V_33 , V_99 , V_360 , 0 ) ;
break;
default:
V_27 = - V_322 ;
break;
}
return V_27 ;
}
static int F_269 ( struct V_32 * V_33 ,
struct V_328 * V_346 ,
T_2 V_360 , int V_289 )
{
struct V_96 * V_99 = V_346 -> V_99 ;
T_2 V_108 ;
T_2 V_34 = V_360 ;
int V_367 = V_362 ;
int V_27 = 0 ;
bool V_368 = false ;
bool V_314 = false ;
V_74:
V_27 = 0 ;
F_11 ( & V_99 -> V_49 ) ;
while ( V_289 && ! V_368 && V_99 -> V_289 ) {
F_13 ( & V_99 -> V_49 ) ;
if ( V_352 -> V_353 )
return - V_175 ;
V_27 = F_270 ( V_99 -> V_81 , ! V_99 -> V_289 ) ;
if ( V_27 )
return - V_369 ;
F_11 ( & V_99 -> V_49 ) ;
}
V_27 = - V_322 ;
V_108 = V_99 -> V_274 + V_99 -> V_284 +
V_99 -> V_283 + V_99 -> V_285 +
V_99 -> V_286 ;
if ( V_108 <= V_99 -> V_273 ) {
if ( V_108 + V_360 <= V_99 -> V_273 ) {
V_99 -> V_286 += V_360 ;
F_251 ( V_33 -> V_35 ,
L_6 , V_99 -> V_6 , V_360 , 1 ) ;
V_27 = 0 ;
} else {
V_34 = V_360 ;
}
} else {
V_34 = V_108 - V_99 -> V_273 +
( V_360 * 2 ) ;
}
if ( V_27 ) {
T_2 V_370 = F_177 ( V_33 , 0 ) ;
T_2 V_371 ;
V_371 = ( V_99 -> V_273 - V_99 -> V_274 ) * 8 ;
F_72 ( V_371 , 10 ) ;
if ( V_99 -> V_283 >= V_371 && V_289 && ! V_314 ) {
V_99 -> V_289 = 1 ;
V_368 = true ;
F_13 ( & V_99 -> V_49 ) ;
V_27 = F_266 ( V_33 , V_99 ,
V_360 , 1 ) ;
if ( V_27 )
goto V_69;
V_314 = true ;
goto V_74;
}
F_11 ( & V_33 -> V_35 -> V_372 ) ;
V_371 = V_33 -> V_35 -> V_373 ;
if ( V_370 & ( V_275 |
V_276 |
V_277 ) )
V_371 >>= 1 ;
if ( V_289 )
V_371 >>= 3 ;
else
V_371 >>= 1 ;
F_13 ( & V_33 -> V_35 -> V_372 ) ;
if ( V_108 + V_34 < V_99 -> V_273 + V_371 ) {
V_99 -> V_286 += V_360 ;
F_251 ( V_33 -> V_35 ,
L_6 , V_99 -> V_6 , V_360 , 1 ) ;
V_27 = 0 ;
}
}
if ( V_27 && V_289 ) {
V_368 = true ;
V_99 -> V_289 = 1 ;
}
F_13 ( & V_99 -> V_49 ) ;
if ( ! V_27 || ! V_289 )
goto V_69;
V_27 = F_267 ( V_33 , V_99 , V_34 , V_360 ,
V_367 ) ;
V_367 ++ ;
if ( ! V_27 )
goto V_74;
else if ( V_367 <= V_366 )
goto V_74;
V_69:
if ( V_368 ) {
F_11 ( & V_99 -> V_49 ) ;
V_99 -> V_289 = 0 ;
F_271 ( & V_99 -> V_81 ) ;
F_13 ( & V_99 -> V_49 ) ;
}
return V_27 ;
}
static struct V_328 * F_272 (
const struct V_82 * V_83 ,
const struct V_32 * V_33 )
{
struct V_328 * V_346 = NULL ;
if ( V_33 -> V_250 )
V_346 = V_83 -> V_346 ;
if ( V_33 == V_33 -> V_35 -> V_374 && V_83 -> V_375 )
V_346 = V_83 -> V_346 ;
if ( ! V_346 )
V_346 = V_33 -> V_346 ;
if ( ! V_346 )
V_346 = & V_33 -> V_35 -> V_376 ;
return V_346 ;
}
static int F_273 ( struct V_328 * V_346 ,
T_2 V_34 )
{
int V_27 = - V_322 ;
F_11 ( & V_346 -> V_49 ) ;
if ( V_346 -> V_9 >= V_34 ) {
V_346 -> V_9 -= V_34 ;
if ( V_346 -> V_9 < V_346 -> V_54 )
V_346 -> V_102 = 0 ;
V_27 = 0 ;
}
F_13 ( & V_346 -> V_49 ) ;
return V_27 ;
}
static void F_274 ( struct V_328 * V_346 ,
T_2 V_34 , int V_377 )
{
F_11 ( & V_346 -> V_49 ) ;
V_346 -> V_9 += V_34 ;
if ( V_377 )
V_346 -> V_54 += V_34 ;
else if ( V_346 -> V_9 >= V_346 -> V_54 )
V_346 -> V_102 = 1 ;
F_13 ( & V_346 -> V_49 ) ;
}
static void F_275 ( struct V_11 * V_35 ,
struct V_328 * V_346 ,
struct V_328 * V_378 , T_2 V_34 )
{
struct V_96 * V_99 = V_346 -> V_99 ;
F_11 ( & V_346 -> V_49 ) ;
if ( V_34 == ( T_2 ) - 1 )
V_34 = V_346 -> V_54 ;
V_346 -> V_54 -= V_34 ;
if ( V_346 -> V_9 >= V_346 -> V_54 ) {
V_34 = V_346 -> V_9 - V_346 -> V_54 ;
V_346 -> V_9 = V_346 -> V_54 ;
V_346 -> V_102 = 1 ;
} else {
V_34 = 0 ;
}
F_13 ( & V_346 -> V_49 ) ;
if ( V_34 > 0 ) {
if ( V_378 ) {
F_11 ( & V_378 -> V_49 ) ;
if ( ! V_378 -> V_102 ) {
T_2 V_379 ;
V_379 = V_378 -> V_54 - V_378 -> V_9 ;
V_379 = F_263 ( V_34 , V_379 ) ;
V_378 -> V_9 += V_379 ;
if ( V_378 -> V_9 >= V_378 -> V_54 )
V_378 -> V_102 = 1 ;
V_34 -= V_379 ;
}
F_13 ( & V_378 -> V_49 ) ;
}
if ( V_34 ) {
F_11 ( & V_99 -> V_49 ) ;
V_99 -> V_286 -= V_34 ;
F_251 ( V_35 , L_6 ,
V_99 -> V_6 , V_34 , 0 ) ;
V_99 -> V_380 ++ ;
F_13 ( & V_99 -> V_49 ) ;
}
}
}
static int F_276 ( struct V_328 * V_381 ,
struct V_328 * V_382 , T_2 V_34 )
{
int V_27 ;
V_27 = F_273 ( V_381 , V_34 ) ;
if ( V_27 )
return V_27 ;
F_274 ( V_382 , V_34 , 1 ) ;
return 0 ;
}
void F_277 ( struct V_328 * V_383 )
{
memset ( V_383 , 0 , sizeof( * V_383 ) ) ;
F_239 ( & V_383 -> V_49 ) ;
}
struct V_328 * F_278 ( struct V_32 * V_33 )
{
struct V_328 * V_346 ;
struct V_11 * V_35 = V_33 -> V_35 ;
V_346 = F_194 ( sizeof( * V_346 ) , V_38 ) ;
if ( ! V_346 )
return NULL ;
F_277 ( V_346 ) ;
V_346 -> V_99 = F_66 ( V_35 ,
V_114 ) ;
return V_346 ;
}
void F_279 ( struct V_32 * V_33 ,
struct V_328 * V_383 )
{
F_280 ( V_33 , V_383 , ( T_2 ) - 1 ) ;
F_9 ( V_383 ) ;
}
static inline int F_281 ( struct V_32 * V_33 ,
struct V_328 * V_346 ,
T_2 V_34 , int V_289 )
{
int V_27 ;
if ( V_34 == 0 )
return 0 ;
V_27 = F_269 ( V_33 , V_346 , V_34 , V_289 ) ;
if ( ! V_27 ) {
F_274 ( V_346 , V_34 , 1 ) ;
return 0 ;
}
return V_27 ;
}
int F_282 ( struct V_32 * V_33 ,
struct V_328 * V_346 ,
T_2 V_34 )
{
return F_281 ( V_33 , V_346 , V_34 , 1 ) ;
}
int F_283 ( struct V_32 * V_33 ,
struct V_328 * V_346 ,
T_2 V_34 )
{
return F_281 ( V_33 , V_346 , V_34 , 0 ) ;
}
int F_284 ( struct V_32 * V_33 ,
struct V_328 * V_346 , int V_384 )
{
T_2 V_34 = 0 ;
int V_27 = - V_322 ;
if ( ! V_346 )
return 0 ;
F_11 ( & V_346 -> V_49 ) ;
V_34 = F_71 ( V_346 -> V_54 , V_384 ) ;
if ( V_346 -> V_9 >= V_34 )
V_27 = 0 ;
F_13 ( & V_346 -> V_49 ) ;
return V_27 ;
}
static inline int F_285 ( struct V_32 * V_33 ,
struct V_328 * V_346 ,
T_2 V_385 , int V_289 )
{
T_2 V_34 = 0 ;
int V_27 = - V_322 ;
if ( ! V_346 )
return 0 ;
F_11 ( & V_346 -> V_49 ) ;
V_34 = V_385 ;
if ( V_346 -> V_9 >= V_34 )
V_27 = 0 ;
else
V_34 -= V_346 -> V_9 ;
F_13 ( & V_346 -> V_49 ) ;
if ( ! V_27 )
return 0 ;
V_27 = F_269 ( V_33 , V_346 , V_34 , V_289 ) ;
if ( ! V_27 ) {
F_274 ( V_346 , V_34 , 0 ) ;
return 0 ;
}
return V_27 ;
}
int F_286 ( struct V_32 * V_33 ,
struct V_328 * V_346 ,
T_2 V_385 )
{
return F_285 ( V_33 , V_346 , V_385 , 1 ) ;
}
int F_287 ( struct V_32 * V_33 ,
struct V_328 * V_346 ,
T_2 V_385 )
{
return F_285 ( V_33 , V_346 , V_385 , 0 ) ;
}
int F_288 ( struct V_328 * V_386 ,
struct V_328 * V_387 ,
T_2 V_34 )
{
return F_276 ( V_386 , V_387 , V_34 ) ;
}
void F_280 ( struct V_32 * V_33 ,
struct V_328 * V_346 ,
T_2 V_34 )
{
struct V_328 * V_329 = & V_33 -> V_35 -> V_330 ;
if ( V_329 -> V_102 || V_329 == V_346 ||
V_346 -> V_99 != V_329 -> V_99 )
V_329 = NULL ;
F_275 ( V_33 -> V_35 , V_346 , V_329 ,
V_34 ) ;
}
static T_2 F_289 ( struct V_11 * V_35 )
{
struct V_96 * V_325 ;
T_2 V_34 ;
T_2 V_388 ;
T_2 V_389 ;
int V_390 = F_290 ( V_35 -> V_334 ) ;
V_325 = F_66 ( V_35 , V_290 ) ;
F_11 ( & V_325 -> V_49 ) ;
V_389 = V_325 -> V_274 ;
F_13 ( & V_325 -> V_49 ) ;
V_325 = F_66 ( V_35 , V_114 ) ;
F_11 ( & V_325 -> V_49 ) ;
if ( V_325 -> V_6 & V_290 )
V_389 = 0 ;
V_388 = V_325 -> V_274 ;
F_13 ( & V_325 -> V_49 ) ;
V_34 = ( V_389 >> V_35 -> V_355 -> V_391 ) *
V_390 * 2 ;
V_34 += F_229 ( V_389 + V_388 , 50 ) ;
if ( V_34 * 3 > V_388 )
V_34 = F_229 ( V_388 , 3 ) ;
return F_291 ( V_34 , V_35 -> V_60 -> V_392 << 10 ) ;
}
static void F_292 ( struct V_11 * V_35 )
{
struct V_328 * V_346 = & V_35 -> V_330 ;
struct V_96 * V_325 = V_346 -> V_99 ;
T_2 V_34 ;
V_34 = F_289 ( V_35 ) ;
F_11 ( & V_325 -> V_49 ) ;
F_11 ( & V_346 -> V_49 ) ;
V_346 -> V_54 = V_34 ;
V_34 = V_325 -> V_274 + V_325 -> V_283 +
V_325 -> V_284 + V_325 -> V_285 +
V_325 -> V_286 ;
if ( V_325 -> V_273 > V_34 ) {
V_34 = V_325 -> V_273 - V_34 ;
V_346 -> V_9 += V_34 ;
V_325 -> V_286 += V_34 ;
F_251 ( V_35 , L_6 ,
V_325 -> V_6 , V_34 , 1 ) ;
}
if ( V_346 -> V_9 >= V_346 -> V_54 ) {
V_34 = V_346 -> V_9 - V_346 -> V_54 ;
V_325 -> V_286 -= V_34 ;
F_251 ( V_35 , L_6 ,
V_325 -> V_6 , V_34 , 0 ) ;
V_325 -> V_380 ++ ;
V_346 -> V_9 = V_346 -> V_54 ;
V_346 -> V_102 = 1 ;
}
F_13 ( & V_346 -> V_49 ) ;
F_13 ( & V_325 -> V_49 ) ;
}
static void F_293 ( struct V_11 * V_35 )
{
struct V_96 * V_99 ;
V_99 = F_66 ( V_35 , V_296 ) ;
V_35 -> V_393 . V_99 = V_99 ;
V_99 = F_66 ( V_35 , V_114 ) ;
V_35 -> V_330 . V_99 = V_99 ;
V_35 -> V_354 . V_99 = V_99 ;
V_35 -> V_394 . V_99 = V_99 ;
V_35 -> V_376 . V_99 = V_99 ;
V_35 -> V_358 . V_99 = V_99 ;
V_35 -> V_60 -> V_346 = & V_35 -> V_330 ;
V_35 -> V_374 -> V_346 = & V_35 -> V_330 ;
V_35 -> V_395 -> V_346 = & V_35 -> V_330 ;
V_35 -> V_237 -> V_346 = & V_35 -> V_330 ;
V_35 -> V_312 -> V_346 = & V_35 -> V_393 ;
F_292 ( V_35 ) ;
}
static void F_294 ( struct V_11 * V_35 )
{
F_275 ( V_35 , & V_35 -> V_330 , NULL ,
( T_2 ) - 1 ) ;
F_8 ( V_35 -> V_354 . V_54 > 0 ) ;
F_8 ( V_35 -> V_354 . V_9 > 0 ) ;
F_8 ( V_35 -> V_394 . V_54 > 0 ) ;
F_8 ( V_35 -> V_394 . V_9 > 0 ) ;
F_8 ( V_35 -> V_393 . V_54 > 0 ) ;
F_8 ( V_35 -> V_393 . V_9 > 0 ) ;
F_8 ( V_35 -> V_358 . V_54 > 0 ) ;
F_8 ( V_35 -> V_358 . V_9 > 0 ) ;
}
void F_295 ( struct V_82 * V_83 ,
struct V_32 * V_33 )
{
if ( ! V_83 -> V_346 )
return;
if ( ! V_83 -> V_284 )
return;
F_251 ( V_33 -> V_35 , L_8 ,
V_83 -> V_263 , V_83 -> V_284 , 0 ) ;
F_280 ( V_33 , V_83 -> V_346 , V_83 -> V_284 ) ;
V_83 -> V_284 = 0 ;
}
int F_296 ( struct V_82 * V_83 ,
struct V_254 * V_254 )
{
struct V_32 * V_33 = F_225 ( V_254 ) -> V_33 ;
struct V_328 * V_386 = F_272 ( V_83 , V_33 ) ;
struct V_328 * V_387 = V_33 -> V_396 ;
T_2 V_34 = F_256 ( V_33 , 1 ) ;
F_251 ( V_33 -> V_35 , L_9 ,
F_297 ( V_254 ) , V_34 , 1 ) ;
return F_276 ( V_386 , V_387 , V_34 ) ;
}
void F_298 ( struct V_254 * V_254 )
{
struct V_32 * V_33 = F_225 ( V_254 ) -> V_33 ;
T_2 V_34 = F_256 ( V_33 , 1 ) ;
F_251 ( V_33 -> V_35 , L_9 ,
F_297 ( V_254 ) , V_34 , 0 ) ;
F_280 ( V_33 , V_33 -> V_396 , V_34 ) ;
}
int F_299 ( struct V_82 * V_83 ,
struct V_397 * V_398 )
{
struct V_32 * V_33 = V_398 -> V_33 ;
struct V_328 * V_386 = F_272 ( V_83 , V_33 ) ;
struct V_328 * V_387 = & V_398 -> V_346 ;
T_2 V_34 = F_256 ( V_33 , 5 ) ;
V_387 -> V_99 = V_386 -> V_99 ;
return F_276 ( V_386 , V_387 , V_34 ) ;
}
static unsigned F_300 ( struct V_254 * V_254 )
{
unsigned V_399 = 0 ;
unsigned V_400 = 0 ;
F_22 ( ! F_225 ( V_254 ) -> V_401 ) ;
F_225 ( V_254 ) -> V_401 -- ;
if ( F_225 ( V_254 ) -> V_401 == 0 &&
F_301 ( V_402 ,
& F_225 ( V_254 ) -> V_403 ) )
V_399 = 1 ;
if ( F_225 ( V_254 ) -> V_401 >=
F_225 ( V_254 ) -> V_404 )
return V_399 ;
V_400 = F_225 ( V_254 ) -> V_404 -
F_225 ( V_254 ) -> V_401 ;
F_225 ( V_254 ) -> V_404 -= V_400 ;
return V_400 + V_399 ;
}
static T_2 F_302 ( struct V_254 * V_254 , T_2 V_34 ,
int V_405 )
{
struct V_32 * V_33 = F_225 ( V_254 ) -> V_33 ;
T_2 V_390 ;
int V_406 ;
int V_407 ;
int V_408 ;
if ( F_225 ( V_254 ) -> V_6 & V_409 &&
F_225 ( V_254 ) -> V_410 == 0 )
return 0 ;
V_408 = ( int ) F_229 ( F_225 ( V_254 ) -> V_410 , V_33 -> V_316 ) ;
if ( V_405 )
F_225 ( V_254 ) -> V_410 += V_34 ;
else
F_225 ( V_254 ) -> V_410 -= V_34 ;
V_390 = F_303 ( V_33 ) - sizeof( struct V_411 ) ;
V_406 = ( int ) F_229 ( V_390 ,
sizeof( struct V_412 ) +
sizeof( struct V_413 ) ) ;
V_407 = ( int ) F_229 ( F_225 ( V_254 ) -> V_410 , V_33 -> V_316 ) ;
V_407 = V_407 + V_406 - 1 ;
V_407 = V_407 / V_406 ;
V_408 = V_408 + V_406 - 1 ;
V_408 = V_408 / V_406 ;
if ( V_408 == V_407 )
return 0 ;
if ( V_405 )
return F_256 ( V_33 ,
V_407 - V_408 ) ;
return F_256 ( V_33 , V_408 - V_407 ) ;
}
int F_304 ( struct V_254 * V_254 , T_2 V_34 )
{
struct V_32 * V_33 = F_225 ( V_254 ) -> V_33 ;
struct V_328 * V_346 = & V_33 -> V_35 -> V_354 ;
T_2 V_414 = 0 ;
T_2 V_410 ;
unsigned V_415 = 0 ;
int V_416 = 0 ;
int V_289 = 1 ;
int V_27 ;
if ( F_305 ( V_254 ) )
V_289 = 0 ;
if ( V_289 && F_306 ( V_33 -> V_35 ) )
F_191 ( 1 ) ;
F_34 ( & F_225 ( V_254 ) -> V_417 ) ;
V_34 = F_291 ( V_34 , V_33 -> V_316 ) ;
F_11 ( & F_225 ( V_254 ) -> V_49 ) ;
F_225 ( V_254 ) -> V_401 ++ ;
if ( F_225 ( V_254 ) -> V_401 >
F_225 ( V_254 ) -> V_404 )
V_415 = F_225 ( V_254 ) -> V_401 -
F_225 ( V_254 ) -> V_404 ;
if ( ! F_307 ( V_402 ,
& F_225 ( V_254 ) -> V_403 ) ) {
V_415 ++ ;
V_416 = 1 ;
}
V_414 = F_256 ( V_33 , V_415 ) ;
V_414 += F_302 ( V_254 , V_34 , 1 ) ;
V_410 = F_225 ( V_254 ) -> V_410 ;
F_13 ( & F_225 ( V_254 ) -> V_49 ) ;
if ( V_33 -> V_35 -> V_418 ) {
V_27 = F_308 ( V_33 , V_34 +
V_415 * V_33 -> V_392 ) ;
if ( V_27 ) {
F_45 ( & F_225 ( V_254 ) -> V_417 ) ;
return V_27 ;
}
}
V_27 = F_269 ( V_33 , V_346 , V_414 , V_289 ) ;
if ( V_27 ) {
T_2 V_419 = 0 ;
unsigned V_420 ;
F_11 ( & F_225 ( V_254 ) -> V_49 ) ;
V_420 = F_300 ( V_254 ) ;
if ( F_225 ( V_254 ) -> V_410 == V_410 )
F_302 ( V_254 , V_34 , 0 ) ;
else
V_419 = F_302 ( V_254 , V_34 , 0 ) ;
F_13 ( & F_225 ( V_254 ) -> V_49 ) ;
if ( V_420 )
V_419 += F_256 ( V_33 , V_420 ) ;
if ( V_419 ) {
F_280 ( V_33 , V_346 , V_419 ) ;
F_251 ( V_33 -> V_35 ,
L_10 ,
F_297 ( V_254 ) ,
V_419 , 0 ) ;
}
F_45 ( & F_225 ( V_254 ) -> V_417 ) ;
return V_27 ;
}
F_11 ( & F_225 ( V_254 ) -> V_49 ) ;
if ( V_416 ) {
F_309 ( V_402 ,
& F_225 ( V_254 ) -> V_403 ) ;
V_415 -- ;
}
F_225 ( V_254 ) -> V_404 += V_415 ;
F_13 ( & F_225 ( V_254 ) -> V_49 ) ;
F_45 ( & F_225 ( V_254 ) -> V_417 ) ;
if ( V_414 )
F_251 ( V_33 -> V_35 , L_10 ,
F_297 ( V_254 ) , V_414 , 1 ) ;
F_274 ( V_346 , V_414 , 1 ) ;
return 0 ;
}
void F_310 ( struct V_254 * V_254 , T_2 V_34 )
{
struct V_32 * V_33 = F_225 ( V_254 ) -> V_33 ;
T_2 V_419 = 0 ;
unsigned V_420 ;
V_34 = F_291 ( V_34 , V_33 -> V_316 ) ;
F_11 ( & F_225 ( V_254 ) -> V_49 ) ;
V_420 = F_300 ( V_254 ) ;
V_419 = F_302 ( V_254 , V_34 , 0 ) ;
F_13 ( & F_225 ( V_254 ) -> V_49 ) ;
if ( V_420 > 0 )
V_419 += F_256 ( V_33 , V_420 ) ;
F_251 ( V_33 -> V_35 , L_10 ,
F_297 ( V_254 ) , V_419 , 0 ) ;
if ( V_33 -> V_35 -> V_418 ) {
F_311 ( V_33 , V_34 +
V_420 * V_33 -> V_392 ) ;
}
F_280 ( V_33 , & V_33 -> V_35 -> V_354 ,
V_419 ) ;
}
int F_312 ( struct V_254 * V_254 , T_2 V_34 )
{
int V_27 ;
V_27 = F_230 ( V_254 , V_34 ) ;
if ( V_27 )
return V_27 ;
V_27 = F_304 ( V_254 , V_34 ) ;
if ( V_27 ) {
F_232 ( V_254 , V_34 ) ;
return V_27 ;
}
return 0 ;
}
void F_313 ( struct V_254 * V_254 , T_2 V_34 )
{
F_310 ( V_254 , V_34 ) ;
F_232 ( V_254 , V_34 ) ;
}
static int F_314 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
T_2 V_25 , T_2 V_34 , int V_319 )
{
struct V_1 * V_2 = NULL ;
struct V_11 * V_12 = V_33 -> V_35 ;
T_2 V_421 = V_34 ;
T_2 V_422 ;
T_2 V_423 ;
int V_104 ;
F_11 ( & V_12 -> V_424 ) ;
V_422 = F_315 ( V_12 -> V_334 ) ;
if ( V_319 )
V_422 += V_34 ;
else
V_422 -= V_34 ;
F_316 ( V_12 -> V_334 , V_422 ) ;
F_13 ( & V_12 -> V_424 ) ;
while ( V_421 ) {
V_2 = F_65 ( V_12 , V_25 ) ;
if ( ! V_2 )
return - V_153 ;
if ( V_2 -> V_6 & ( V_275 |
V_276 |
V_277 ) )
V_104 = 2 ;
else
V_104 = 1 ;
if ( ! V_319 && V_2 -> V_3 == V_90 )
F_49 ( V_2 , V_83 , NULL , 1 ) ;
V_423 = V_25 - V_2 -> V_20 . V_21 ;
F_8 ( V_423 > V_2 -> V_20 . V_31 ) ;
F_11 ( & V_2 -> V_99 -> V_49 ) ;
F_11 ( & V_2 -> V_49 ) ;
if ( F_228 ( V_33 , V_267 ) &&
V_2 -> V_260 < V_269 )
V_2 -> V_260 = V_269 ;
V_2 -> V_270 = 1 ;
V_422 = F_76 ( & V_2 -> V_112 ) ;
V_34 = F_263 ( V_421 , V_2 -> V_20 . V_31 - V_423 ) ;
if ( V_319 ) {
V_422 += V_34 ;
F_317 ( & V_2 -> V_112 , V_422 ) ;
V_2 -> V_9 -= V_34 ;
V_2 -> V_99 -> V_284 -= V_34 ;
V_2 -> V_99 -> V_274 += V_34 ;
V_2 -> V_99 -> V_279 += V_34 * V_104 ;
F_13 ( & V_2 -> V_49 ) ;
F_13 ( & V_2 -> V_99 -> V_49 ) ;
} else {
V_422 -= V_34 ;
F_317 ( & V_2 -> V_112 , V_422 ) ;
V_2 -> V_8 += V_34 ;
V_2 -> V_99 -> V_283 += V_34 ;
V_2 -> V_99 -> V_274 -= V_34 ;
V_2 -> V_99 -> V_279 -= V_34 * V_104 ;
F_13 ( & V_2 -> V_49 ) ;
F_13 ( & V_2 -> V_99 -> V_49 ) ;
F_318 ( V_12 -> V_56 ,
V_25 , V_25 + V_34 - 1 ,
V_38 | V_425 ) ;
}
F_6 ( V_2 ) ;
V_421 -= V_34 ;
V_25 += V_34 ;
}
return 0 ;
}
static T_2 F_319 ( struct V_32 * V_33 , T_2 V_105 )
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
static int F_320 ( struct V_32 * V_33 ,
struct V_1 * V_2 ,
T_2 V_25 , T_2 V_34 , int V_9 )
{
F_11 ( & V_2 -> V_99 -> V_49 ) ;
F_11 ( & V_2 -> V_49 ) ;
V_2 -> V_8 += V_34 ;
V_2 -> V_99 -> V_283 += V_34 ;
if ( V_9 ) {
V_2 -> V_9 -= V_34 ;
V_2 -> V_99 -> V_284 -= V_34 ;
}
F_13 ( & V_2 -> V_49 ) ;
F_13 ( & V_2 -> V_99 -> V_49 ) ;
F_318 ( V_33 -> V_35 -> V_56 , V_25 ,
V_25 + V_34 - 1 , V_38 | V_425 ) ;
return 0 ;
}
int F_164 ( struct V_32 * V_33 ,
T_2 V_25 , T_2 V_34 , int V_9 )
{
struct V_1 * V_2 ;
V_2 = F_65 ( V_33 -> V_35 , V_25 ) ;
F_22 ( ! V_2 ) ;
F_320 ( V_33 , V_2 , V_25 , V_34 , V_9 ) ;
F_6 ( V_2 ) ;
return 0 ;
}
int F_321 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
T_2 V_25 , T_2 V_34 )
{
struct V_1 * V_2 ;
V_2 = F_65 ( V_33 -> V_35 , V_25 ) ;
F_22 ( ! V_2 ) ;
F_49 ( V_2 , V_83 , V_33 , 1 ) ;
F_320 ( V_33 , V_2 , V_25 , V_34 , 0 ) ;
F_322 ( V_2 , V_25 , V_34 ) ;
F_6 ( V_2 ) ;
return 0 ;
}
static int F_323 ( struct V_1 * V_2 ,
T_2 V_34 , int V_405 )
{
struct V_96 * V_99 = V_2 -> V_99 ;
int V_27 = 0 ;
F_11 ( & V_99 -> V_49 ) ;
F_11 ( & V_2 -> V_49 ) ;
if ( V_405 != V_426 ) {
if ( V_2 -> V_113 ) {
V_27 = - V_175 ;
} else {
V_2 -> V_9 += V_34 ;
V_99 -> V_284 += V_34 ;
if ( V_405 == V_427 ) {
F_251 ( V_2 -> V_35 ,
L_6 , V_99 -> V_6 ,
V_34 , 0 ) ;
V_99 -> V_286 -= V_34 ;
}
}
} else {
if ( V_2 -> V_113 )
V_99 -> V_285 += V_34 ;
V_2 -> V_9 -= V_34 ;
V_99 -> V_284 -= V_34 ;
V_99 -> V_380 ++ ;
}
F_13 ( & V_2 -> V_49 ) ;
F_13 ( & V_99 -> V_49 ) ;
return V_27 ;
}
void F_324 ( struct V_82 * V_83 ,
struct V_32 * V_33 )
{
struct V_11 * V_35 = V_33 -> V_35 ;
struct V_47 * V_216 ;
struct V_47 * V_51 ;
struct V_1 * V_2 ;
F_60 ( & V_35 -> V_76 ) ;
F_325 (caching_ctl, next,
&fs_info->caching_block_groups, list) {
V_2 = V_51 -> V_13 ;
if ( F_1 ( V_2 ) ) {
V_2 -> V_93 = ( T_2 ) - 1 ;
F_173 ( & V_51 -> V_86 ) ;
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
F_292 ( V_35 ) ;
}
static int F_326 ( struct V_32 * V_33 , T_2 V_30 , T_2 V_29 )
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
V_115 = F_263 ( V_115 , V_29 + 1 - V_30 ) ;
if ( V_30 < V_2 -> V_93 ) {
V_115 = F_263 ( V_115 , V_2 -> V_93 - V_30 ) ;
F_29 ( V_2 , V_30 , V_115 ) ;
}
V_30 += V_115 ;
F_11 ( & V_2 -> V_99 -> V_49 ) ;
F_11 ( & V_2 -> V_49 ) ;
V_2 -> V_8 -= V_115 ;
V_2 -> V_99 -> V_283 -= V_115 ;
if ( V_2 -> V_113 )
V_2 -> V_99 -> V_285 += V_115 ;
F_13 ( & V_2 -> V_49 ) ;
F_13 ( & V_2 -> V_99 -> V_49 ) ;
}
if ( V_2 )
F_6 ( V_2 ) ;
return 0 ;
}
int F_327 ( struct V_82 * V_83 ,
struct V_32 * V_33 )
{
struct V_11 * V_35 = V_33 -> V_35 ;
struct V_428 * V_429 ;
T_2 V_30 ;
T_2 V_29 ;
int V_27 ;
if ( V_83 -> V_210 )
return 0 ;
if ( V_35 -> V_56 == & V_35 -> V_36 [ 0 ] )
V_429 = & V_35 -> V_36 [ 1 ] ;
else
V_429 = & V_35 -> V_36 [ 0 ] ;
while ( 1 ) {
V_27 = F_28 ( V_429 , 0 , & V_30 , & V_29 ,
V_57 ) ;
if ( V_27 )
break;
if ( F_228 ( V_33 , V_430 ) )
V_27 = F_145 ( V_33 , V_30 ,
V_29 + 1 - V_30 , NULL ) ;
F_328 ( V_429 , V_30 , V_29 , V_38 ) ;
F_326 ( V_33 , V_30 , V_29 ) ;
F_46 () ;
}
return 0 ;
}
static int F_155 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
T_2 V_25 , T_2 V_34 , T_2 V_16 ,
T_2 V_146 , T_2 V_431 ,
T_2 V_432 , int V_159 ,
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
int V_433 = 0 ;
int V_434 = 0 ;
int V_435 = 1 ;
T_3 V_122 ;
T_2 V_116 ;
V_62 = F_32 () ;
if ( ! V_62 )
return - V_85 ;
V_62 -> V_72 = 1 ;
V_62 -> V_201 = 1 ;
V_181 = V_431 >= V_143 ;
F_22 ( ! V_181 && V_159 != 1 ) ;
V_27 = F_137 ( V_83 , V_60 , V_62 , & V_163 ,
V_25 , V_34 , V_16 ,
V_146 , V_431 ,
V_432 ) ;
if ( V_27 == 0 ) {
V_433 = V_62 -> V_79 [ 0 ] ;
while ( V_433 >= 0 ) {
F_39 ( V_62 -> V_78 [ 0 ] , & V_20 ,
V_433 ) ;
if ( V_20 . V_21 != V_25 )
break;
if ( V_20 . type == V_73 &&
V_20 . V_31 == V_34 ) {
V_434 = 1 ;
break;
}
if ( V_62 -> V_79 [ 0 ] - V_433 > 5 )
break;
V_433 -- ;
}
#ifdef F_84
V_122 = F_80 ( V_62 -> V_78 [ 0 ] , V_433 ) ;
if ( V_434 && V_122 < sizeof( * V_121 ) )
V_434 = 0 ;
#endif
if ( ! V_434 ) {
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
F_174 ( V_232 L_11
L_12 , V_27 ,
( unsigned long long ) V_25 ) ;
if ( V_27 > 0 )
F_329 ( V_60 ,
V_62 -> V_78 [ 0 ] ) ;
}
if ( V_27 < 0 )
goto abort;
V_433 = V_62 -> V_79 [ 0 ] ;
}
} else if ( V_27 == - V_153 ) {
F_329 ( V_60 , V_62 -> V_78 [ 0 ] ) ;
F_8 ( 1 ) ;
F_174 ( V_232 L_13
L_14 ,
( unsigned long long ) V_25 ,
( unsigned long long ) V_16 ,
( unsigned long long ) V_146 ,
( unsigned long long ) V_431 ,
( unsigned long long ) V_432 ) ;
} else {
goto abort;
}
V_64 = V_62 -> V_78 [ 0 ] ;
V_122 = F_80 ( V_64 , V_433 ) ;
#ifdef F_84
if ( V_122 < sizeof( * V_121 ) ) {
F_22 ( V_434 || V_433 != V_62 -> V_79 [ 0 ] ) ;
V_27 = F_90 ( V_83 , V_60 , V_62 ,
V_431 , 0 ) ;
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
F_174 ( V_232 L_11
L_12 , V_27 ,
( unsigned long long ) V_25 ) ;
F_329 ( V_60 , V_62 -> V_78 [ 0 ] ) ;
}
if ( V_27 < 0 )
goto abort;
V_433 = V_62 -> V_79 [ 0 ] ;
V_64 = V_62 -> V_78 [ 0 ] ;
V_122 = F_80 ( V_64 , V_433 ) ;
}
#endif
F_22 ( V_122 < sizeof( * V_121 ) ) ;
V_121 = F_81 ( V_64 , V_433 ,
struct V_120 ) ;
if ( V_431 < V_143 ) {
struct V_138 * V_139 ;
F_22 ( V_122 < sizeof( * V_121 ) + sizeof( * V_139 ) ) ;
V_139 = (struct V_138 * ) ( V_121 + 1 ) ;
F_8 ( V_431 != F_330 ( V_64 , V_139 ) ) ;
}
V_116 = F_82 ( V_64 , V_121 ) ;
F_22 ( V_116 < V_159 ) ;
V_116 -= V_159 ;
if ( V_116 > 0 ) {
if ( V_131 )
F_133 ( V_131 , V_64 , V_121 ) ;
if ( V_163 ) {
F_22 ( ! V_434 ) ;
} else {
F_93 ( V_64 , V_121 , V_116 ) ;
F_98 ( V_64 ) ;
}
if ( V_434 ) {
V_27 = F_142 ( V_83 , V_60 , V_62 ,
V_163 , V_159 ,
V_181 ) ;
if ( V_27 )
goto abort;
}
} else {
if ( V_434 ) {
F_22 ( V_181 && V_159 !=
F_121 ( V_33 , V_62 , V_163 ) ) ;
if ( V_163 ) {
F_22 ( V_62 -> V_79 [ 0 ] != V_433 ) ;
} else {
F_22 ( V_62 -> V_79 [ 0 ] != V_433 + 1 ) ;
V_62 -> V_79 [ 0 ] = V_433 ;
V_435 = 2 ;
}
}
V_27 = F_331 ( V_83 , V_60 , V_62 , V_62 -> V_79 [ 0 ] ,
V_435 ) ;
if ( V_27 )
goto abort;
F_43 ( V_62 ) ;
if ( V_181 ) {
V_27 = F_165 ( V_83 , V_33 , V_25 , V_34 ) ;
if ( V_27 )
goto abort;
}
V_27 = F_314 ( V_83 , V_33 , V_25 , V_34 , 0 ) ;
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
static T_1 int F_332 ( struct V_82 * V_83 ,
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
V_130 = F_197 ( & V_98 -> V_130 . V_14 ) ;
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
F_175 ( & V_98 -> V_130 . V_14 , & V_119 -> V_33 ) ;
V_119 -> V_221 -- ;
V_119 -> V_436 -- ;
if ( F_167 ( & V_98 -> V_213 ) )
V_119 -> V_218 -- ;
F_173 ( & V_98 -> V_213 ) ;
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
void F_333 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_63 * V_245 ,
T_2 V_16 , int V_437 )
{
struct V_1 * V_2 = NULL ;
int V_27 ;
if ( V_33 -> V_241 . V_21 != V_199 ) {
V_27 = F_148 ( V_33 -> V_35 , V_83 ,
V_245 -> V_30 , V_245 -> V_115 ,
V_16 , V_33 -> V_241 . V_21 ,
F_205 ( V_245 ) ,
V_209 , NULL , 0 ) ;
F_22 ( V_27 ) ;
}
if ( ! V_437 )
return;
V_2 = F_65 ( V_33 -> V_35 , V_245 -> V_30 ) ;
if ( F_334 ( V_245 ) == V_83 -> V_263 ) {
if ( V_33 -> V_241 . V_21 != V_199 ) {
V_27 = F_332 ( V_83 , V_33 , V_245 -> V_30 ) ;
if ( ! V_27 )
goto V_69;
}
if ( F_335 ( V_245 , V_438 ) ) {
F_320 ( V_33 , V_2 , V_245 -> V_30 , V_245 -> V_115 , 1 ) ;
goto V_69;
}
F_8 ( F_307 ( V_439 , & V_245 -> V_440 ) ) ;
F_29 ( V_2 , V_245 -> V_30 , V_245 -> V_115 ) ;
F_323 ( V_2 , V_245 -> V_115 , V_426 ) ;
}
V_69:
F_336 ( V_441 , & V_245 -> V_440 ) ;
F_6 ( V_2 ) ;
}
int V_251 ( struct V_82 * V_83 , struct V_32 * V_33 ,
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
static T_2 F_337 ( struct V_32 * V_33 , T_2 V_442 )
{
T_2 V_443 = ( ( T_2 ) V_33 -> V_444 - 1 ) ;
T_2 V_27 = ( V_442 + V_443 ) & ~ V_443 ;
return V_27 ;
}
static T_1 int
F_338 ( struct V_1 * V_2 ,
T_2 V_34 )
{
struct V_47 * V_51 ;
F_50 ( V_81 ) ;
V_51 = F_25 ( V_2 ) ;
if ( ! V_51 )
return 0 ;
F_339 ( V_51 -> V_81 , F_1 ( V_2 ) ||
( V_2 -> V_10 -> V_445 >= V_34 ) ) ;
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
F_339 ( V_51 -> V_81 , F_1 ( V_2 ) ) ;
F_26 ( V_51 ) ;
return 0 ;
}
static int F_341 ( T_2 V_6 )
{
int V_446 ;
if ( V_6 & V_277 )
V_446 = 0 ;
else if ( V_6 & V_276 )
V_446 = 1 ;
else if ( V_6 & V_275 )
V_446 = 2 ;
else if ( V_6 & V_311 )
V_446 = 3 ;
else
V_446 = 4 ;
return V_446 ;
}
static int F_342 ( struct V_1 * V_2 )
{
return F_341 ( V_2 -> V_6 ) ;
}
static T_1 int F_343 ( struct V_82 * V_83 ,
struct V_32 * V_447 ,
T_2 V_34 , T_2 V_448 ,
T_2 V_449 , struct V_65 * V_205 ,
T_2 V_302 )
{
int V_27 = 0 ;
struct V_32 * V_33 = V_447 -> V_35 -> V_60 ;
struct V_450 * V_451 = NULL ;
struct V_1 * V_13 = NULL ;
struct V_1 * V_452 ;
T_2 V_105 = 0 ;
int V_453 = 2 * 1024 * 1024 ;
int V_454 = 0 ;
int V_455 = 0 ;
struct V_96 * V_99 ;
int V_456 = 0 ;
int V_446 = 0 ;
int V_457 = ( V_302 & V_290 ) ?
V_458 : V_427 ;
bool V_459 = false ;
bool V_460 = false ;
bool V_461 = false ;
bool V_462 = true ;
bool V_463 = false ;
F_8 ( V_34 < V_33 -> V_316 ) ;
F_78 ( V_205 , V_73 ) ;
V_205 -> V_21 = 0 ;
V_205 -> V_31 = 0 ;
F_344 ( V_447 , V_34 , V_448 , V_302 ) ;
V_99 = F_66 ( V_33 -> V_35 , V_302 ) ;
if ( ! V_99 ) {
F_174 ( V_232 L_15 , V_302 ) ;
return - V_322 ;
}
if ( F_260 ( V_99 ) )
V_462 = false ;
if ( V_447 -> V_250 || V_448 )
V_454 = 1 ;
if ( V_302 & V_114 && V_462 ) {
V_451 = & V_33 -> V_35 -> V_464 ;
if ( ! F_228 ( V_33 , V_465 ) )
V_453 = 64 * 1024 ;
}
if ( ( V_302 & V_290 ) && V_462 &&
F_228 ( V_33 , V_465 ) ) {
V_451 = & V_33 -> V_35 -> V_466 ;
}
if ( V_451 ) {
F_11 ( & V_451 -> V_49 ) ;
if ( V_451 -> V_13 )
V_449 = V_451 -> V_467 ;
F_13 ( & V_451 -> V_49 ) ;
}
V_105 = F_75 ( V_105 , F_319 ( V_33 , 0 ) ) ;
V_105 = F_75 ( V_105 , V_449 ) ;
if ( ! V_451 )
V_453 = 0 ;
if ( V_105 == V_449 ) {
V_13 = F_65 ( V_33 -> V_35 ,
V_105 ) ;
V_452 = V_13 ;
if ( V_13 && F_3 ( V_13 , V_302 ) &&
V_13 -> V_3 != V_90 ) {
F_35 ( & V_99 -> V_282 ) ;
if ( F_167 ( & V_13 -> V_86 ) ||
V_13 -> V_113 ) {
F_6 ( V_13 ) ;
F_44 ( & V_99 -> V_282 ) ;
} else {
V_446 = F_342 ( V_13 ) ;
goto V_468;
}
} else if ( V_13 ) {
F_6 ( V_13 ) ;
}
}
V_469:
V_463 = false ;
F_35 ( & V_99 -> V_282 ) ;
F_345 (block_group, &space_info->block_groups[index],
list) {
T_2 V_31 ;
int V_3 ;
V_452 = V_13 ;
F_4 ( V_13 ) ;
V_105 = V_13 -> V_20 . V_21 ;
if ( ! F_3 ( V_13 , V_302 ) ) {
T_2 V_470 = V_275 |
V_276 |
V_277 ;
if ( ( V_302 & V_470 ) && ! ( V_13 -> V_6 & V_470 ) )
goto V_456;
}
V_468:
V_3 = F_1 ( V_13 ) ;
if ( F_346 ( ! V_3 ) ) {
V_459 = true ;
V_27 = F_49 ( V_13 , V_83 ,
V_447 , 0 ) ;
F_22 ( V_27 < 0 ) ;
V_27 = 0 ;
}
if ( F_346 ( V_13 -> V_113 ) )
goto V_456;
if ( V_451 ) {
F_11 ( & V_451 -> V_471 ) ;
V_452 = V_451 -> V_13 ;
if ( V_452 != V_13 &&
( ! V_452 ||
V_452 -> V_113 ||
! F_3 ( V_452 , V_302 ) ) ) {
V_452 = V_13 ;
goto V_472;
}
if ( V_452 != V_13 )
F_4 ( V_452 ) ;
V_31 = F_347 ( V_452 ,
V_451 , V_34 , V_452 -> V_20 . V_21 ) ;
if ( V_31 ) {
F_13 ( & V_451 -> V_471 ) ;
F_348 ( V_33 ,
V_13 , V_105 , V_34 ) ;
goto V_473;
}
F_8 ( V_451 -> V_13 != V_452 ) ;
if ( V_452 != V_13 ) {
F_6 ( V_452 ) ;
V_452 = V_13 ;
}
V_472:
F_22 ( V_452 != V_13 ) ;
if ( V_456 >= V_474 &&
V_451 -> V_13 != V_13 ) {
F_13 ( & V_451 -> V_471 ) ;
goto V_475;
}
F_349 ( NULL , V_451 ) ;
if ( V_456 >= V_474 ) {
F_13 ( & V_451 -> V_471 ) ;
goto V_475;
}
V_27 = F_350 ( V_83 , V_33 ,
V_13 , V_451 ,
V_105 , V_34 ,
V_453 + V_448 ) ;
if ( V_27 == 0 ) {
V_31 = F_347 ( V_13 ,
V_451 , V_34 ,
V_105 ) ;
if ( V_31 ) {
F_13 ( & V_451 -> V_471 ) ;
F_348 ( V_33 ,
V_13 , V_105 ,
V_34 ) ;
goto V_473;
}
} else if ( ! V_3 && V_456 > V_476
&& ! V_460 ) {
F_13 ( & V_451 -> V_471 ) ;
V_460 = true ;
F_338 ( V_13 ,
V_34 + V_453 + V_448 ) ;
goto V_468;
}
F_349 ( NULL , V_451 ) ;
F_13 ( & V_451 -> V_471 ) ;
goto V_456;
}
V_475:
F_11 ( & V_13 -> V_10 -> V_477 ) ;
if ( V_3 &&
V_13 -> V_10 -> V_445 <
V_34 + V_453 + V_448 ) {
F_13 ( & V_13 -> V_10 -> V_477 ) ;
goto V_456;
}
F_13 ( & V_13 -> V_10 -> V_477 ) ;
V_31 = F_351 ( V_13 , V_105 ,
V_34 , V_448 ) ;
if ( ! V_31 && ! V_461 && ! V_3 &&
V_456 > V_476 ) {
F_338 ( V_13 ,
V_34 + V_448 ) ;
V_461 = true ;
goto V_468;
} else if ( ! V_31 ) {
if ( ! V_3 )
V_463 = true ;
goto V_456;
}
V_473:
V_105 = F_337 ( V_33 , V_31 ) ;
if ( V_105 + V_34 >
V_452 -> V_20 . V_21 + V_452 -> V_20 . V_31 ) {
F_29 ( V_452 , V_31 , V_34 ) ;
goto V_456;
}
if ( V_31 < V_105 )
F_29 ( V_452 , V_31 ,
V_105 - V_31 ) ;
F_22 ( V_31 > V_105 ) ;
V_27 = F_323 ( V_452 , V_34 ,
V_457 ) ;
if ( V_27 == - V_175 ) {
F_29 ( V_452 , V_31 , V_34 ) ;
goto V_456;
}
V_205 -> V_21 = V_105 ;
V_205 -> V_31 = V_34 ;
F_352 ( V_447 , V_13 ,
V_105 , V_34 ) ;
if ( V_31 < V_105 )
F_29 ( V_452 , V_31 ,
V_105 - V_31 ) ;
F_22 ( V_31 > V_105 ) ;
if ( V_452 != V_13 )
F_6 ( V_452 ) ;
F_6 ( V_13 ) ;
break;
V_456:
V_460 = false ;
V_461 = false ;
F_22 ( V_446 != F_342 ( V_13 ) ) ;
if ( V_452 != V_13 )
F_6 ( V_452 ) ;
F_6 ( V_13 ) ;
}
F_44 ( & V_99 -> V_282 ) ;
if ( ! V_205 -> V_21 && V_456 >= V_478 && V_463 )
goto V_469;
if ( ! V_205 -> V_21 && ++ V_446 < V_280 )
goto V_469;
if ( ! V_205 -> V_21 && V_456 < V_474 ) {
V_446 = 0 ;
V_456 ++ ;
if ( V_456 == V_479 ) {
if ( V_454 ) {
V_27 = F_176 ( V_83 , V_33 , V_34 +
2 * 1024 * 1024 , V_302 ,
V_333 ) ;
if ( V_27 < 0 && V_27 != - V_322 ) {
F_151 ( V_83 ,
V_33 , V_27 ) ;
goto V_69;
}
V_454 = 0 ;
if ( V_27 == 1 )
V_455 = 1 ;
} else if ( ! V_455 &&
V_99 -> V_287 ==
V_223 ) {
V_99 -> V_287 = V_333 ;
}
if ( ! V_455 )
V_456 = V_474 ;
}
if ( V_456 == V_474 ) {
V_448 = 0 ;
V_453 = 0 ;
}
goto V_469;
} else if ( ! V_205 -> V_21 ) {
V_27 = - V_322 ;
} else if ( V_205 -> V_21 ) {
V_27 = 0 ;
}
V_69:
return V_27 ;
}
static void F_258 ( struct V_96 * V_12 , T_2 V_313 ,
int V_480 )
{
struct V_1 * V_2 ;
int V_446 = 0 ;
F_11 ( & V_12 -> V_49 ) ;
F_174 ( V_338 L_16 ,
( unsigned long long ) V_12 -> V_6 ,
( unsigned long long ) ( V_12 -> V_273 - V_12 -> V_274 -
V_12 -> V_283 - V_12 -> V_284 -
V_12 -> V_285 ) ,
( V_12 -> V_102 ) ? L_4 : L_17 ) ;
F_174 ( V_338 L_18
L_19 ,
( unsigned long long ) V_12 -> V_273 ,
( unsigned long long ) V_12 -> V_274 ,
( unsigned long long ) V_12 -> V_283 ,
( unsigned long long ) V_12 -> V_284 ,
( unsigned long long ) V_12 -> V_286 ,
( unsigned long long ) V_12 -> V_285 ) ;
F_13 ( & V_12 -> V_49 ) ;
if ( ! V_480 )
return;
F_35 ( & V_12 -> V_282 ) ;
V_74:
F_345 (cache, &info->block_groups[index], list) {
F_11 ( & V_2 -> V_49 ) ;
F_174 ( V_338 L_20 ,
( unsigned long long ) V_2 -> V_20 . V_21 ,
( unsigned long long ) V_2 -> V_20 . V_31 ,
( unsigned long long ) F_76 ( & V_2 -> V_112 ) ,
( unsigned long long ) V_2 -> V_8 ,
( unsigned long long ) V_2 -> V_9 ,
V_2 -> V_113 ? L_21 : L_4 ) ;
F_353 ( V_2 , V_313 ) ;
F_13 ( & V_2 -> V_49 ) ;
}
if ( ++ V_446 < V_280 )
goto V_74;
F_44 ( & V_12 -> V_282 ) ;
}
int F_354 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
T_2 V_34 , T_2 V_481 ,
T_2 V_448 , T_2 V_449 ,
struct V_65 * V_205 , T_2 V_302 )
{
bool V_482 = false ;
int V_27 ;
V_302 = F_177 ( V_33 , V_302 ) ;
V_74:
if ( V_448 || V_33 -> V_250 ) {
V_27 = F_176 ( V_83 , V_33 -> V_35 -> V_60 ,
V_34 + 2 * 1024 * 1024 , V_302 ,
V_223 ) ;
if ( V_27 < 0 && V_27 != - V_322 ) {
F_151 ( V_83 , V_33 , V_27 ) ;
return V_27 ;
}
}
F_8 ( V_34 < V_33 -> V_316 ) ;
V_27 = F_343 ( V_83 , V_33 , V_34 , V_448 ,
V_449 , V_205 , V_302 ) ;
if ( V_27 == - V_322 ) {
if ( ! V_482 ) {
V_34 = V_34 >> 1 ;
V_34 = V_34 & ~ ( V_33 -> V_316 - 1 ) ;
V_34 = F_75 ( V_34 , V_481 ) ;
V_27 = F_176 ( V_83 , V_33 -> V_35 -> V_60 ,
V_34 , V_302 , V_321 ) ;
if ( V_27 < 0 && V_27 != - V_322 ) {
F_151 ( V_83 , V_33 , V_27 ) ;
return V_27 ;
}
if ( V_34 == V_481 )
V_482 = true ;
goto V_74;
} else if ( F_228 ( V_33 , V_337 ) ) {
struct V_96 * V_325 ;
V_325 = F_66 ( V_33 -> V_35 , V_302 ) ;
F_174 ( V_232 L_22
L_23 , ( unsigned long long ) V_302 ,
( unsigned long long ) V_34 ) ;
if ( V_325 )
F_258 ( V_325 , V_34 , 1 ) ;
}
}
F_355 ( V_33 , V_205 -> V_21 , V_205 -> V_31 ) ;
return V_27 ;
}
static int F_356 ( struct V_32 * V_33 ,
T_2 V_30 , T_2 V_115 , int V_483 )
{
struct V_1 * V_2 ;
int V_27 = 0 ;
V_2 = F_65 ( V_33 -> V_35 , V_30 ) ;
if ( ! V_2 ) {
F_174 ( V_232 L_24 ,
( unsigned long long ) V_30 ) ;
return - V_322 ;
}
if ( F_228 ( V_33 , V_430 ) )
V_27 = F_145 ( V_33 , V_30 , V_115 , NULL ) ;
if ( V_483 )
F_320 ( V_33 , V_2 , V_30 , V_115 , 1 ) ;
else {
F_29 ( V_2 , V_30 , V_115 ) ;
F_323 ( V_2 , V_115 , V_426 ) ;
}
F_6 ( V_2 ) ;
F_357 ( V_33 , V_30 , V_115 ) ;
return V_27 ;
}
int F_358 ( struct V_32 * V_33 ,
T_2 V_30 , T_2 V_115 )
{
return F_356 ( V_33 , V_30 , V_115 , 0 ) ;
}
int F_359 ( struct V_32 * V_33 ,
T_2 V_30 , T_2 V_115 )
{
return F_356 ( V_33 , V_30 , V_115 , 1 ) ;
}
static int F_154 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
T_2 V_16 , T_2 V_146 ,
T_2 V_6 , T_2 V_107 , T_2 V_31 ,
struct V_65 * V_205 , int V_134 )
{
int V_27 ;
struct V_11 * V_35 = V_33 -> V_35 ;
struct V_120 * V_484 ;
struct V_162 * V_163 ;
struct V_61 * V_62 ;
struct V_63 * V_64 ;
int type ;
T_3 V_54 ;
if ( V_16 > 0 )
type = V_154 ;
else
type = V_155 ;
V_54 = sizeof( * V_484 ) + F_128 ( type ) ;
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
V_484 = F_81 ( V_64 , V_62 -> V_79 [ 0 ] ,
struct V_120 ) ;
F_93 ( V_64 , V_484 , V_134 ) ;
F_94 ( V_64 , V_484 , V_83 -> V_263 ) ;
F_95 ( V_64 , V_484 ,
V_6 | V_145 ) ;
V_163 = (struct V_162 * ) ( V_484 + 1 ) ;
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
V_27 = F_314 ( V_83 , V_33 , V_205 -> V_21 , V_205 -> V_31 , 1 ) ;
if ( V_27 ) {
F_174 ( V_232 L_25
L_26 , ( unsigned long long ) V_205 -> V_21 ,
( unsigned long long ) V_205 -> V_31 ) ;
F_86 () ;
}
return V_27 ;
}
static int F_160 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
T_2 V_16 , T_2 V_146 ,
T_2 V_6 , struct V_413 * V_20 ,
int V_166 , struct V_65 * V_205 )
{
int V_27 ;
struct V_11 * V_35 = V_33 -> V_35 ;
struct V_120 * V_484 ;
struct V_138 * V_485 ;
struct V_162 * V_163 ;
struct V_61 * V_62 ;
struct V_63 * V_64 ;
T_3 V_54 = sizeof( * V_484 ) + sizeof( * V_485 ) + sizeof( * V_163 ) ;
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
V_484 = F_81 ( V_64 , V_62 -> V_79 [ 0 ] ,
struct V_120 ) ;
F_93 ( V_64 , V_484 , 1 ) ;
F_94 ( V_64 , V_484 , V_83 -> V_263 ) ;
F_95 ( V_64 , V_484 ,
V_6 | V_144 ) ;
V_485 = (struct V_138 * ) ( V_484 + 1 ) ;
F_156 ( V_64 , V_485 , V_20 ) ;
F_97 ( V_64 , V_485 , V_166 ) ;
V_163 = (struct V_162 * ) ( V_485 + 1 ) ;
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
V_27 = F_314 ( V_83 , V_33 , V_205 -> V_21 , V_205 -> V_31 , 1 ) ;
if ( V_27 ) {
F_174 ( V_232 L_25
L_26 , ( unsigned long long ) V_205 -> V_21 ,
( unsigned long long ) V_205 -> V_31 ) ;
F_86 () ;
}
return V_27 ;
}
int F_360 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
T_2 V_146 , T_2 V_107 ,
T_2 V_31 , struct V_65 * V_205 )
{
int V_27 ;
F_22 ( V_146 == V_199 ) ;
V_27 = F_149 ( V_33 -> V_35 , V_83 , V_205 -> V_21 ,
V_205 -> V_31 , 0 ,
V_146 , V_107 , V_31 ,
V_222 , NULL , 0 ) ;
return V_27 ;
}
int F_361 ( struct V_82 * V_83 ,
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
V_27 = F_322 ( V_13 , V_30 , V_34 ) ;
F_22 ( V_27 ) ;
} else {
F_34 ( & V_51 -> V_75 ) ;
if ( V_30 >= V_51 -> V_80 ) {
V_27 = F_17 ( V_33 , V_30 , V_34 ) ;
F_22 ( V_27 ) ;
} else if ( V_30 + V_34 <= V_51 -> V_80 ) {
V_27 = F_322 ( V_13 ,
V_30 , V_34 ) ;
F_22 ( V_27 ) ;
} else {
V_34 = V_51 -> V_80 - V_30 ;
V_27 = F_322 ( V_13 ,
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
V_27 = F_323 ( V_13 , V_205 -> V_31 ,
V_458 ) ;
F_22 ( V_27 ) ;
F_6 ( V_13 ) ;
V_27 = F_154 ( V_83 , V_33 , 0 , V_146 ,
0 , V_107 , V_31 , V_205 , 1 ) ;
return V_27 ;
}
struct V_63 * F_362 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
T_2 V_25 , T_3 V_486 ,
int V_166 )
{
struct V_63 * V_245 ;
V_245 = F_363 ( V_33 , V_25 , V_486 ) ;
if ( ! V_245 )
return F_364 ( - V_85 ) ;
F_365 ( V_245 , V_83 -> V_263 ) ;
F_366 ( V_33 -> V_241 . V_21 , V_245 , V_166 ) ;
F_367 ( V_245 ) ;
F_368 ( V_83 , V_33 , V_245 ) ;
F_336 ( V_487 , & V_245 -> V_440 ) ;
F_369 ( V_245 ) ;
F_370 ( V_245 ) ;
if ( V_33 -> V_241 . V_21 == V_199 ) {
if ( V_33 -> V_488 % 2 == 0 )
F_318 ( & V_33 -> V_489 , V_245 -> V_30 ,
V_245 -> V_30 + V_245 -> V_115 - 1 , V_38 ) ;
else
F_371 ( & V_33 -> V_489 , V_245 -> V_30 ,
V_245 -> V_30 + V_245 -> V_115 - 1 , V_38 ) ;
} else {
F_318 ( & V_83 -> V_129 -> V_490 , V_245 -> V_30 ,
V_245 -> V_30 + V_245 -> V_115 - 1 , V_38 ) ;
}
V_83 -> V_491 ++ ;
return V_245 ;
}
static struct V_328 *
F_372 ( struct V_82 * V_83 ,
struct V_32 * V_33 , T_3 V_486 )
{
struct V_328 * V_346 ;
struct V_328 * V_329 = & V_33 -> V_35 -> V_330 ;
int V_27 ;
V_346 = F_272 ( V_83 , V_33 ) ;
if ( V_346 -> V_54 == 0 ) {
V_27 = F_269 ( V_33 , V_346 , V_486 , 0 ) ;
if ( V_27 && V_346 != V_329 ) {
V_27 = F_273 ( V_329 , V_486 ) ;
if ( ! V_27 )
return V_329 ;
return F_364 ( V_27 ) ;
} else if ( V_27 ) {
return F_364 ( V_27 ) ;
}
return V_346 ;
}
V_27 = F_273 ( V_346 , V_486 ) ;
if ( ! V_27 )
return V_346 ;
if ( V_27 ) {
static F_373 ( V_492 ,
V_493 ,
2 ) ;
if ( F_374 ( & V_492 ) ) {
F_174 ( V_219 L_27 , V_27 ) ;
F_8 ( 1 ) ;
}
V_27 = F_269 ( V_33 , V_346 , V_486 , 0 ) ;
if ( ! V_27 ) {
return V_346 ;
} else if ( V_27 && V_346 != V_329 ) {
V_27 = F_273 ( V_329 , V_486 ) ;
if ( ! V_27 )
return V_329 ;
}
}
return F_364 ( - V_322 ) ;
}
static void F_375 ( struct V_11 * V_35 ,
struct V_328 * V_346 , T_3 V_486 )
{
F_274 ( V_346 , V_486 , 0 ) ;
F_275 ( V_35 , V_346 , NULL , 0 ) ;
}
struct V_63 * F_376 ( struct V_82 * V_83 ,
struct V_32 * V_33 , T_3 V_486 ,
T_2 V_16 , T_2 V_146 ,
struct V_413 * V_20 , int V_166 ,
T_2 V_494 , T_2 V_448 )
{
struct V_65 V_205 ;
struct V_328 * V_346 ;
struct V_63 * V_245 ;
T_2 V_6 = 0 ;
int V_27 ;
V_346 = F_372 ( V_83 , V_33 , V_486 ) ;
if ( F_221 ( V_346 ) )
return F_377 ( V_346 ) ;
V_27 = F_354 ( V_83 , V_33 , V_486 , V_486 ,
V_448 , V_494 , & V_205 , 0 ) ;
if ( V_27 ) {
F_375 ( V_33 -> V_35 , V_346 , V_486 ) ;
return F_364 ( V_27 ) ;
}
V_245 = F_362 ( V_83 , V_33 , V_205 . V_21 ,
V_486 , V_166 ) ;
F_22 ( F_221 ( V_245 ) ) ;
if ( V_146 == V_495 ) {
if ( V_16 == 0 )
V_16 = V_205 . V_21 ;
V_6 |= V_128 ;
} else
F_22 ( V_16 > 0 ) ;
if ( V_146 != V_199 ) {
struct V_177 * V_131 ;
V_131 = F_194 ( sizeof( * V_131 ) , V_38 ) ;
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
V_166 , V_222 ,
V_131 , 0 ) ;
F_22 ( V_27 ) ;
}
return V_245 ;
}
static T_1 void F_378 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_496 * V_497 ,
struct V_61 * V_62 )
{
T_2 V_25 ;
T_2 V_266 ;
T_2 V_116 ;
T_2 V_6 ;
T_3 V_68 ;
T_3 V_486 ;
struct V_65 V_20 ;
struct V_63 * V_498 ;
int V_27 ;
int V_499 ;
int V_500 = 0 ;
if ( V_62 -> V_79 [ V_497 -> V_166 ] < V_497 -> V_501 ) {
V_497 -> V_502 = V_497 -> V_502 * 2 / 3 ;
V_497 -> V_502 = F_75 ( V_497 -> V_502 , 2 ) ;
} else {
V_497 -> V_502 = V_497 -> V_502 * 3 / 2 ;
V_497 -> V_502 = F_189 ( int , V_497 -> V_502 ,
F_379 ( V_33 ) ) ;
}
V_498 = V_62 -> V_78 [ V_497 -> V_166 ] ;
V_68 = F_37 ( V_498 ) ;
V_486 = F_212 ( V_33 , V_497 -> V_166 - 1 ) ;
for ( V_499 = V_62 -> V_79 [ V_497 -> V_166 ] ; V_499 < V_68 ; V_499 ++ ) {
if ( V_500 >= V_497 -> V_502 )
break;
F_46 () ;
V_25 = F_211 ( V_498 , V_499 ) ;
V_266 = F_380 ( V_498 , V_499 ) ;
if ( V_499 == V_62 -> V_79 [ V_497 -> V_166 ] )
goto V_72;
if ( V_497 -> V_503 == V_504 &&
V_266 <= V_33 -> V_241 . V_31 )
continue;
V_27 = F_79 ( V_83 , V_33 , V_25 , V_486 ,
& V_116 , & V_6 ) ;
if ( V_27 < 0 )
continue;
F_22 ( V_116 == 0 ) ;
if ( V_497 -> V_503 == V_505 ) {
if ( V_116 == 1 )
goto V_72;
if ( V_497 -> V_166 == 1 &&
( V_6 & V_128 ) )
continue;
if ( ! V_497 -> V_506 ||
V_266 <= V_33 -> V_241 . V_31 )
continue;
F_126 ( V_498 , & V_20 , V_499 ) ;
V_27 = F_381 ( & V_20 ,
& V_497 -> V_507 ) ;
if ( V_27 < 0 )
continue;
} else {
if ( V_497 -> V_166 == 1 &&
( V_6 & V_128 ) )
continue;
}
V_72:
V_27 = F_382 ( V_33 , V_25 , V_486 ,
V_266 ) ;
if ( V_27 )
break;
V_500 ++ ;
}
V_497 -> V_501 = V_499 ;
}
static T_1 int F_383 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_61 * V_62 ,
struct V_496 * V_497 , int V_508 )
{
int V_166 = V_497 -> V_166 ;
struct V_63 * V_498 = V_62 -> V_78 [ V_166 ] ;
T_2 V_509 = V_128 ;
int V_27 ;
if ( V_497 -> V_503 == V_504 &&
F_204 ( V_498 ) != V_33 -> V_241 . V_21 )
return 1 ;
if ( V_508 &&
( ( V_497 -> V_503 == V_505 && V_497 -> V_116 [ V_166 ] != 1 ) ||
( V_497 -> V_503 == V_504 && ! ( V_497 -> V_6 [ V_166 ] & V_509 ) ) ) ) {
F_22 ( ! V_62 -> V_510 [ V_166 ] ) ;
V_27 = F_79 ( V_83 , V_33 ,
V_498 -> V_30 , V_498 -> V_115 ,
& V_497 -> V_116 [ V_166 ] ,
& V_497 -> V_6 [ V_166 ] ) ;
F_22 ( V_27 == - V_85 ) ;
if ( V_27 )
return V_27 ;
F_22 ( V_497 -> V_116 [ V_166 ] == 0 ) ;
}
if ( V_497 -> V_503 == V_505 ) {
if ( V_497 -> V_116 [ V_166 ] > 1 )
return 1 ;
if ( V_62 -> V_510 [ V_166 ] && ! V_497 -> V_172 ) {
F_384 ( V_498 , V_62 -> V_510 [ V_166 ] ) ;
V_62 -> V_510 [ V_166 ] = 0 ;
}
return 0 ;
}
if ( ! ( V_497 -> V_6 [ V_166 ] & V_509 ) ) {
F_22 ( ! V_62 -> V_510 [ V_166 ] ) ;
V_27 = F_213 ( V_83 , V_33 , V_498 , 1 , V_497 -> V_511 ) ;
F_22 ( V_27 ) ;
V_27 = F_214 ( V_83 , V_33 , V_498 , 0 , V_497 -> V_511 ) ;
F_22 ( V_27 ) ;
V_27 = F_193 ( V_83 , V_33 , V_498 -> V_30 ,
V_498 -> V_115 , V_509 , 0 ) ;
F_22 ( V_27 ) ;
V_497 -> V_6 [ V_166 ] |= V_509 ;
}
if ( V_62 -> V_510 [ V_166 ] && V_166 > 0 ) {
F_384 ( V_498 , V_62 -> V_510 [ V_166 ] ) ;
V_62 -> V_510 [ V_166 ] = 0 ;
}
return 0 ;
}
static T_1 int F_385 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_61 * V_62 ,
struct V_496 * V_497 , int * V_508 )
{
T_2 V_25 ;
T_2 V_266 ;
T_2 V_16 ;
T_3 V_486 ;
struct V_65 V_20 ;
struct V_63 * V_216 ;
int V_166 = V_497 -> V_166 ;
int V_72 = 0 ;
int V_27 = 0 ;
V_266 = F_380 ( V_62 -> V_78 [ V_166 ] ,
V_62 -> V_79 [ V_166 ] ) ;
if ( V_497 -> V_503 == V_504 &&
V_266 <= V_33 -> V_241 . V_31 ) {
* V_508 = 1 ;
return 1 ;
}
V_25 = F_211 ( V_62 -> V_78 [ V_166 ] , V_62 -> V_79 [ V_166 ] ) ;
V_486 = F_212 ( V_33 , V_166 - 1 ) ;
V_216 = F_386 ( V_33 , V_25 , V_486 ) ;
if ( ! V_216 ) {
V_216 = F_363 ( V_33 , V_25 , V_486 ) ;
if ( ! V_216 )
return - V_85 ;
V_72 = 1 ;
}
F_367 ( V_216 ) ;
F_369 ( V_216 ) ;
V_27 = F_79 ( V_83 , V_33 , V_25 , V_486 ,
& V_497 -> V_116 [ V_166 - 1 ] ,
& V_497 -> V_6 [ V_166 - 1 ] ) ;
if ( V_27 < 0 ) {
F_387 ( V_216 ) ;
return V_27 ;
}
F_22 ( V_497 -> V_116 [ V_166 - 1 ] == 0 ) ;
* V_508 = 0 ;
if ( V_497 -> V_503 == V_505 ) {
if ( V_497 -> V_116 [ V_166 - 1 ] > 1 ) {
if ( V_166 == 1 &&
( V_497 -> V_6 [ 0 ] & V_128 ) )
goto V_512;
if ( ! V_497 -> V_506 ||
V_266 <= V_33 -> V_241 . V_31 )
goto V_512;
F_126 ( V_62 -> V_78 [ V_166 ] , & V_20 ,
V_62 -> V_79 [ V_166 ] ) ;
V_27 = F_381 ( & V_20 , & V_497 -> V_507 ) ;
if ( V_27 < 0 )
goto V_512;
V_497 -> V_503 = V_504 ;
V_497 -> V_513 = V_166 - 1 ;
}
} else {
if ( V_166 == 1 &&
( V_497 -> V_6 [ 0 ] & V_128 ) )
goto V_512;
}
if ( ! F_388 ( V_216 , V_266 , 0 ) ) {
F_387 ( V_216 ) ;
F_389 ( V_216 ) ;
V_216 = NULL ;
* V_508 = 1 ;
}
if ( ! V_216 ) {
if ( V_72 && V_166 == 1 )
F_378 ( V_83 , V_33 , V_497 , V_62 ) ;
V_216 = F_390 ( V_33 , V_25 , V_486 , V_266 ) ;
if ( ! V_216 )
return - V_211 ;
F_367 ( V_216 ) ;
F_369 ( V_216 ) ;
}
V_166 -- ;
F_22 ( V_166 != F_205 ( V_216 ) ) ;
V_62 -> V_78 [ V_166 ] = V_216 ;
V_62 -> V_79 [ V_166 ] = 0 ;
V_62 -> V_510 [ V_166 ] = V_514 ;
V_497 -> V_166 = V_166 ;
if ( V_497 -> V_166 == 1 )
V_497 -> V_501 = 0 ;
return 0 ;
V_512:
V_497 -> V_116 [ V_166 - 1 ] = 0 ;
V_497 -> V_6 [ V_166 - 1 ] = 0 ;
if ( V_497 -> V_503 == V_505 ) {
if ( V_497 -> V_6 [ V_166 ] & V_128 ) {
V_16 = V_62 -> V_78 [ V_166 ] -> V_30 ;
} else {
F_22 ( V_33 -> V_241 . V_21 !=
F_204 ( V_62 -> V_78 [ V_166 ] ) ) ;
V_16 = 0 ;
}
V_27 = V_251 ( V_83 , V_33 , V_25 , V_486 , V_16 ,
V_33 -> V_241 . V_21 , V_166 - 1 , 0 , 0 ) ;
F_22 ( V_27 ) ;
}
F_387 ( V_216 ) ;
F_389 ( V_216 ) ;
* V_508 = 1 ;
return 1 ;
}
static T_1 int F_391 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_61 * V_62 ,
struct V_496 * V_497 )
{
int V_27 ;
int V_166 = V_497 -> V_166 ;
struct V_63 * V_498 = V_62 -> V_78 [ V_166 ] ;
T_2 V_16 = 0 ;
if ( V_497 -> V_503 == V_504 ) {
F_22 ( V_497 -> V_513 < V_166 ) ;
if ( V_166 < V_497 -> V_513 )
goto V_69;
V_27 = F_40 ( V_62 , V_166 + 1 , & V_497 -> V_507 ) ;
if ( V_27 > 0 )
V_497 -> V_506 = 0 ;
V_497 -> V_503 = V_505 ;
V_497 -> V_513 = - 1 ;
V_62 -> V_79 [ V_166 ] = 0 ;
if ( ! V_62 -> V_510 [ V_166 ] ) {
F_22 ( V_166 == 0 ) ;
F_367 ( V_498 ) ;
F_369 ( V_498 ) ;
V_62 -> V_510 [ V_166 ] = V_514 ;
V_27 = F_79 ( V_83 , V_33 ,
V_498 -> V_30 , V_498 -> V_115 ,
& V_497 -> V_116 [ V_166 ] ,
& V_497 -> V_6 [ V_166 ] ) ;
if ( V_27 < 0 ) {
F_384 ( V_498 , V_62 -> V_510 [ V_166 ] ) ;
return V_27 ;
}
F_22 ( V_497 -> V_116 [ V_166 ] == 0 ) ;
if ( V_497 -> V_116 [ V_166 ] == 1 ) {
F_384 ( V_498 , V_62 -> V_510 [ V_166 ] ) ;
return 1 ;
}
}
}
F_22 ( V_497 -> V_116 [ V_166 ] > 1 && ! V_62 -> V_510 [ V_166 ] ) ;
if ( V_497 -> V_116 [ V_166 ] == 1 ) {
if ( V_166 == 0 ) {
if ( V_497 -> V_6 [ V_166 ] & V_128 )
V_27 = F_214 ( V_83 , V_33 , V_498 , 1 ,
V_497 -> V_511 ) ;
else
V_27 = F_214 ( V_83 , V_33 , V_498 , 0 ,
V_497 -> V_511 ) ;
F_22 ( V_27 ) ;
}
if ( ! V_62 -> V_510 [ V_166 ] &&
F_334 ( V_498 ) == V_83 -> V_263 ) {
F_367 ( V_498 ) ;
F_369 ( V_498 ) ;
V_62 -> V_510 [ V_166 ] = V_514 ;
}
F_368 ( V_83 , V_33 , V_498 ) ;
}
if ( V_498 == V_33 -> V_130 ) {
if ( V_497 -> V_6 [ V_166 ] & V_128 )
V_16 = V_498 -> V_30 ;
else
F_22 ( V_33 -> V_241 . V_21 !=
F_204 ( V_498 ) ) ;
} else {
if ( V_497 -> V_6 [ V_166 + 1 ] & V_128 )
V_16 = V_62 -> V_78 [ V_166 + 1 ] -> V_30 ;
else
F_22 ( V_33 -> V_241 . V_21 !=
F_204 ( V_62 -> V_78 [ V_166 + 1 ] ) ) ;
}
F_333 ( V_83 , V_33 , V_498 , V_16 , V_497 -> V_116 [ V_166 ] == 1 ) ;
V_69:
V_497 -> V_116 [ V_166 ] = 0 ;
V_497 -> V_6 [ V_166 ] = 0 ;
return 0 ;
}
static T_1 int F_392 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_61 * V_62 ,
struct V_496 * V_497 )
{
int V_166 = V_497 -> V_166 ;
int V_508 = 1 ;
int V_27 ;
while ( V_166 >= 0 ) {
V_27 = F_383 ( V_83 , V_33 , V_62 , V_497 , V_508 ) ;
if ( V_27 > 0 )
break;
if ( V_166 == 0 )
break;
if ( V_62 -> V_79 [ V_166 ] >=
F_37 ( V_62 -> V_78 [ V_166 ] ) )
break;
V_27 = F_385 ( V_83 , V_33 , V_62 , V_497 , & V_508 ) ;
if ( V_27 > 0 ) {
V_62 -> V_79 [ V_166 ] ++ ;
continue;
} else if ( V_27 < 0 )
return V_27 ;
V_166 = V_497 -> V_166 ;
}
return 0 ;
}
static T_1 int F_393 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_61 * V_62 ,
struct V_496 * V_497 , int V_515 )
{
int V_166 = V_497 -> V_166 ;
int V_27 ;
V_62 -> V_79 [ V_166 ] = F_37 ( V_62 -> V_78 [ V_166 ] ) ;
while ( V_166 < V_515 && V_62 -> V_78 [ V_166 ] ) {
V_497 -> V_166 = V_166 ;
if ( V_62 -> V_79 [ V_166 ] + 1 <
F_37 ( V_62 -> V_78 [ V_166 ] ) ) {
V_62 -> V_79 [ V_166 ] ++ ;
return 0 ;
} else {
V_27 = F_391 ( V_83 , V_33 , V_62 , V_497 ) ;
if ( V_27 > 0 )
return 0 ;
if ( V_62 -> V_510 [ V_166 ] ) {
F_384 ( V_62 -> V_78 [ V_166 ] ,
V_62 -> V_510 [ V_166 ] ) ;
V_62 -> V_510 [ V_166 ] = 0 ;
}
F_389 ( V_62 -> V_78 [ V_166 ] ) ;
V_62 -> V_78 [ V_166 ] = NULL ;
V_166 ++ ;
}
}
return 1 ;
}
int F_394 ( struct V_32 * V_33 ,
struct V_328 * V_346 , int V_506 ,
int V_511 )
{
struct V_61 * V_62 ;
struct V_82 * V_83 ;
struct V_32 * V_237 = V_33 -> V_35 -> V_237 ;
struct V_516 * V_242 = & V_33 -> V_242 ;
struct V_496 * V_497 ;
struct V_65 V_20 ;
int V_77 = 0 ;
int V_27 ;
int V_166 ;
V_62 = F_32 () ;
if ( ! V_62 ) {
V_77 = - V_85 ;
goto V_69;
}
V_497 = F_51 ( sizeof( * V_497 ) , V_38 ) ;
if ( ! V_497 ) {
F_48 ( V_62 ) ;
V_77 = - V_85 ;
goto V_69;
}
V_83 = F_395 ( V_237 , 0 ) ;
if ( F_221 ( V_83 ) ) {
V_77 = F_222 ( V_83 ) ;
goto V_125;
}
if ( V_346 )
V_83 -> V_346 = V_346 ;
if ( F_396 ( & V_242 -> V_517 ) == 0 ) {
V_166 = F_205 ( V_33 -> V_130 ) ;
V_62 -> V_78 [ V_166 ] = F_397 ( V_33 ) ;
F_369 ( V_62 -> V_78 [ V_166 ] ) ;
V_62 -> V_79 [ V_166 ] = 0 ;
V_62 -> V_510 [ V_166 ] = V_514 ;
memset ( & V_497 -> V_507 , 0 ,
sizeof( V_497 -> V_507 ) ) ;
} else {
F_398 ( & V_20 , & V_242 -> V_517 ) ;
memcpy ( & V_497 -> V_507 , & V_20 ,
sizeof( V_497 -> V_507 ) ) ;
V_166 = V_242 -> V_518 ;
F_22 ( V_166 == 0 ) ;
V_62 -> V_519 = V_166 ;
V_27 = F_36 ( NULL , V_33 , & V_20 , V_62 , 0 , 0 ) ;
V_62 -> V_519 = 0 ;
if ( V_27 < 0 ) {
V_77 = V_27 ;
goto V_520;
}
F_8 ( V_27 > 0 ) ;
F_131 ( V_62 , 0 ) ;
V_166 = F_205 ( V_33 -> V_130 ) ;
while ( 1 ) {
F_367 ( V_62 -> V_78 [ V_166 ] ) ;
F_369 ( V_62 -> V_78 [ V_166 ] ) ;
V_27 = F_79 ( V_83 , V_33 ,
V_62 -> V_78 [ V_166 ] -> V_30 ,
V_62 -> V_78 [ V_166 ] -> V_115 ,
& V_497 -> V_116 [ V_166 ] ,
& V_497 -> V_6 [ V_166 ] ) ;
if ( V_27 < 0 ) {
V_77 = V_27 ;
goto V_520;
}
F_22 ( V_497 -> V_116 [ V_166 ] == 0 ) ;
if ( V_166 == V_242 -> V_518 )
break;
F_387 ( V_62 -> V_78 [ V_166 ] ) ;
F_8 ( V_497 -> V_116 [ V_166 ] != 1 ) ;
V_166 -- ;
}
}
V_497 -> V_166 = V_166 ;
V_497 -> V_513 = - 1 ;
V_497 -> V_503 = V_505 ;
V_497 -> V_506 = V_506 ;
V_497 -> V_172 = 0 ;
V_497 -> V_511 = V_511 ;
V_497 -> V_502 = F_379 ( V_33 ) ;
while ( 1 ) {
V_27 = F_392 ( V_83 , V_33 , V_62 , V_497 ) ;
if ( V_27 < 0 ) {
V_77 = V_27 ;
break;
}
V_27 = F_393 ( V_83 , V_33 , V_62 , V_497 , V_167 ) ;
if ( V_27 < 0 ) {
V_77 = V_27 ;
break;
}
if ( V_27 > 0 ) {
F_22 ( V_497 -> V_503 != V_505 ) ;
break;
}
if ( V_497 -> V_503 == V_505 ) {
V_166 = V_497 -> V_166 ;
F_399 ( V_62 -> V_78 [ V_166 ] ,
& V_242 -> V_517 ,
V_62 -> V_79 [ V_166 ] ) ;
V_242 -> V_518 = V_166 ;
}
F_22 ( V_497 -> V_166 == 0 ) ;
if ( F_400 ( V_83 , V_237 ) ) {
V_27 = F_401 ( V_83 , V_237 ,
& V_33 -> V_241 ,
V_242 ) ;
if ( V_27 ) {
F_151 ( V_83 , V_237 , V_27 ) ;
V_77 = V_27 ;
goto V_520;
}
F_402 ( V_83 , V_237 ) ;
V_83 = F_395 ( V_237 , 0 ) ;
if ( F_221 ( V_83 ) ) {
V_77 = F_222 ( V_83 ) ;
goto V_125;
}
if ( V_346 )
V_83 -> V_346 = V_346 ;
}
}
F_43 ( V_62 ) ;
if ( V_77 )
goto V_520;
V_27 = F_403 ( V_83 , V_237 , & V_33 -> V_241 ) ;
if ( V_27 ) {
F_151 ( V_83 , V_237 , V_27 ) ;
goto V_520;
}
if ( V_33 -> V_241 . V_21 != V_495 ) {
V_27 = F_404 ( V_237 , V_33 -> V_241 . V_21 ,
NULL , NULL ) ;
if ( V_27 < 0 ) {
F_151 ( V_83 , V_237 , V_27 ) ;
V_77 = V_27 ;
goto V_520;
} else if ( V_27 > 0 ) {
F_405 ( V_83 , V_237 ,
V_33 -> V_241 . V_21 ) ;
}
}
if ( V_33 -> V_521 ) {
F_406 ( V_237 -> V_35 , V_33 ) ;
} else {
F_389 ( V_33 -> V_130 ) ;
F_389 ( V_33 -> V_522 ) ;
F_9 ( V_33 ) ;
}
V_520:
F_402 ( V_83 , V_237 ) ;
V_125:
F_9 ( V_497 ) ;
F_48 ( V_62 ) ;
V_69:
if ( V_77 )
F_407 ( V_33 -> V_35 , V_77 ) ;
return V_77 ;
}
int F_408 ( struct V_82 * V_83 ,
struct V_32 * V_33 ,
struct V_63 * V_130 ,
struct V_63 * V_16 )
{
struct V_61 * V_62 ;
struct V_496 * V_497 ;
int V_166 ;
int V_523 ;
int V_27 = 0 ;
int V_524 ;
F_22 ( V_33 -> V_241 . V_21 != V_495 ) ;
V_62 = F_32 () ;
if ( ! V_62 )
return - V_85 ;
V_497 = F_51 ( sizeof( * V_497 ) , V_38 ) ;
if ( ! V_497 ) {
F_48 ( V_62 ) ;
return - V_85 ;
}
F_409 ( V_16 ) ;
V_523 = F_205 ( V_16 ) ;
F_410 ( V_16 ) ;
V_62 -> V_78 [ V_523 ] = V_16 ;
V_62 -> V_79 [ V_523 ] = F_37 ( V_16 ) ;
F_409 ( V_130 ) ;
V_166 = F_205 ( V_130 ) ;
V_62 -> V_78 [ V_166 ] = V_130 ;
V_62 -> V_79 [ V_166 ] = 0 ;
V_62 -> V_510 [ V_166 ] = V_514 ;
V_497 -> V_116 [ V_523 ] = 1 ;
V_497 -> V_6 [ V_523 ] = V_128 ;
V_497 -> V_166 = V_166 ;
V_497 -> V_513 = - 1 ;
V_497 -> V_503 = V_505 ;
V_497 -> V_506 = 0 ;
V_497 -> V_172 = 1 ;
V_497 -> V_511 = 1 ;
V_497 -> V_502 = F_379 ( V_33 ) ;
while ( 1 ) {
V_524 = F_392 ( V_83 , V_33 , V_62 , V_497 ) ;
if ( V_524 < 0 ) {
V_27 = V_524 ;
break;
}
V_524 = F_393 ( V_83 , V_33 , V_62 , V_497 , V_523 ) ;
if ( V_524 < 0 )
V_27 = V_524 ;
if ( V_524 != 0 )
break;
}
F_9 ( V_497 ) ;
F_48 ( V_62 ) ;
return V_27 ;
}
static T_2 F_411 ( struct V_32 * V_33 , T_2 V_6 )
{
T_2 V_306 ;
T_2 V_525 ;
V_525 = F_243 ( V_33 -> V_35 , V_6 ) ;
if ( V_525 )
return F_245 ( V_525 ) ;
V_306 = V_33 -> V_35 -> V_307 -> V_308 +
V_33 -> V_35 -> V_307 -> V_309 ;
V_525 = V_311 |
V_276 | V_277 ;
if ( V_306 == 1 ) {
V_525 |= V_275 ;
V_525 = V_6 & ~ V_525 ;
if ( V_6 & V_311 )
return V_525 ;
if ( V_6 & ( V_276 |
V_277 ) )
return V_525 | V_275 ;
} else {
if ( V_6 & V_525 )
return V_6 ;
V_525 |= V_275 ;
V_525 = V_6 & ~ V_525 ;
if ( V_6 & V_275 )
return V_525 | V_276 ;
}
return V_6 ;
}
static int F_412 ( struct V_1 * V_2 , int V_327 )
{
struct V_96 * V_325 = V_2 -> V_99 ;
T_2 V_34 ;
T_2 V_526 ;
int V_27 = - V_322 ;
if ( ( V_325 -> V_6 &
( V_296 | V_114 ) ) &&
! V_327 )
V_526 = 1 * 1024 * 1024 ;
else
V_526 = 0 ;
F_11 ( & V_325 -> V_49 ) ;
F_11 ( & V_2 -> V_49 ) ;
if ( V_2 -> V_113 ) {
V_27 = 0 ;
goto V_69;
}
V_34 = V_2 -> V_20 . V_31 - V_2 -> V_9 - V_2 -> V_8 -
V_2 -> V_44 - F_76 ( & V_2 -> V_112 ) ;
if ( V_325 -> V_274 + V_325 -> V_284 + V_325 -> V_283 +
V_325 -> V_286 + V_325 -> V_285 + V_34 +
V_526 <= V_325 -> V_273 ) {
V_325 -> V_285 += V_34 ;
V_2 -> V_113 = 1 ;
V_27 = 0 ;
}
V_69:
F_13 ( & V_2 -> V_49 ) ;
F_13 ( & V_325 -> V_49 ) ;
return V_27 ;
}
int F_413 ( struct V_32 * V_33 ,
struct V_1 * V_2 )
{
struct V_82 * V_83 ;
T_2 V_527 ;
int V_27 ;
F_22 ( V_2 -> V_113 ) ;
V_83 = F_247 ( V_33 ) ;
if ( F_221 ( V_83 ) )
return F_222 ( V_83 ) ;
V_527 = F_411 ( V_33 , V_2 -> V_6 ) ;
if ( V_527 != V_2 -> V_6 ) {
V_27 = F_176 ( V_83 , V_33 , 2 * 1024 * 1024 , V_527 ,
V_321 ) ;
if ( V_27 < 0 )
goto V_69;
}
V_27 = F_412 ( V_2 , 0 ) ;
if ( ! V_27 )
goto V_69;
V_527 = F_246 ( V_33 , V_2 -> V_99 -> V_6 ) ;
V_27 = F_176 ( V_83 , V_33 , 2 * 1024 * 1024 , V_527 ,
V_321 ) ;
if ( V_27 < 0 )
goto V_69;
V_27 = F_412 ( V_2 , 0 ) ;
V_69:
F_248 ( V_83 , V_33 ) ;
return V_27 ;
}
int F_414 ( struct V_82 * V_83 ,
struct V_32 * V_33 , T_2 type )
{
T_2 V_527 = F_246 ( V_33 , type ) ;
return F_176 ( V_83 , V_33 , 2 * 1024 * 1024 , V_527 ,
V_321 ) ;
}
static T_2 F_415 ( struct V_97 * V_528 )
{
struct V_1 * V_13 ;
T_2 V_529 = 0 ;
int V_104 ;
F_345 (block_group, groups_list, list) {
F_11 ( & V_13 -> V_49 ) ;
if ( ! V_13 -> V_113 ) {
F_13 ( & V_13 -> V_49 ) ;
continue;
}
if ( V_13 -> V_6 & ( V_276 |
V_277 |
V_275 ) )
V_104 = 2 ;
else
V_104 = 1 ;
V_529 += ( V_13 -> V_20 . V_31 -
F_76 ( & V_13 -> V_112 ) ) *
V_104 ;
F_13 ( & V_13 -> V_49 ) ;
}
return V_529 ;
}
T_2 F_416 ( struct V_96 * V_325 )
{
int V_41 ;
T_2 V_529 = 0 ;
F_11 ( & V_325 -> V_49 ) ;
for( V_41 = 0 ; V_41 < V_280 ; V_41 ++ )
if ( ! F_167 ( & V_325 -> V_281 [ V_41 ] ) )
V_529 += F_415 (
& V_325 -> V_281 [ V_41 ] ) ;
F_13 ( & V_325 -> V_49 ) ;
return V_529 ;
}
void F_417 ( struct V_32 * V_33 ,
struct V_1 * V_2 )
{
struct V_96 * V_325 = V_2 -> V_99 ;
T_2 V_34 ;
F_22 ( ! V_2 -> V_113 ) ;
F_11 ( & V_325 -> V_49 ) ;
F_11 ( & V_2 -> V_49 ) ;
V_34 = V_2 -> V_20 . V_31 - V_2 -> V_9 - V_2 -> V_8 -
V_2 -> V_44 - F_76 ( & V_2 -> V_112 ) ;
V_325 -> V_285 -= V_34 ;
V_2 -> V_113 = 0 ;
F_13 ( & V_2 -> V_49 ) ;
F_13 ( & V_325 -> V_49 ) ;
}
int F_418 ( struct V_32 * V_33 , T_2 V_25 )
{
struct V_1 * V_13 ;
struct V_96 * V_99 ;
struct V_530 * V_307 = V_33 -> V_35 -> V_307 ;
struct V_531 * V_532 ;
T_2 V_533 ;
T_2 V_534 = 1 ;
T_2 V_535 = 0 ;
T_2 V_301 ;
int V_446 ;
int V_102 = 0 ;
int V_27 = 0 ;
V_13 = F_65 ( V_33 -> V_35 , V_25 ) ;
if ( ! V_13 )
return - 1 ;
V_533 = F_76 ( & V_13 -> V_112 ) ;
if ( ! V_533 )
goto V_69;
V_99 = V_13 -> V_99 ;
F_11 ( & V_99 -> V_49 ) ;
V_102 = V_99 -> V_102 ;
if ( ( V_99 -> V_273 != V_13 -> V_20 . V_31 ) &&
( V_99 -> V_274 + V_99 -> V_284 +
V_99 -> V_283 + V_99 -> V_285 +
V_533 < V_99 -> V_273 ) ) {
F_13 ( & V_99 -> V_49 ) ;
goto V_69;
}
F_13 ( & V_99 -> V_49 ) ;
V_27 = - 1 ;
V_301 = F_243 ( V_33 -> V_35 , V_13 -> V_6 ) ;
if ( V_301 ) {
V_446 = F_341 ( F_245 ( V_301 ) ) ;
} else {
if ( V_102 )
goto V_69;
V_446 = F_342 ( V_13 ) ;
}
if ( V_446 == 0 ) {
V_534 = 4 ;
V_533 >>= 1 ;
} else if ( V_446 == 1 ) {
V_534 = 2 ;
} else if ( V_446 == 2 ) {
V_533 <<= 1 ;
} else if ( V_446 == 3 ) {
V_534 = V_307 -> V_308 ;
F_72 ( V_533 , V_534 ) ;
}
F_34 ( & V_33 -> V_35 -> V_340 ) ;
F_345 (device, &fs_devices->alloc_list, dev_alloc_list) {
T_2 V_536 ;
if ( V_532 -> V_273 > V_532 -> V_274 + V_533 ) {
V_27 = F_419 ( V_532 , V_533 ,
& V_536 , NULL ) ;
if ( ! V_27 )
V_535 ++ ;
if ( V_535 >= V_534 )
break;
V_27 = - 1 ;
}
}
F_45 ( & V_33 -> V_35 -> V_340 ) ;
V_69:
F_6 ( V_13 ) ;
return V_27 ;
}
static int F_420 ( struct V_32 * V_33 ,
struct V_61 * V_62 , struct V_65 * V_20 )
{
int V_27 = 0 ;
struct V_65 V_140 ;
struct V_63 * V_64 ;
int V_499 ;
V_27 = F_36 ( NULL , V_33 , V_20 , V_62 , 0 , 0 ) ;
if ( V_27 < 0 )
goto V_69;
while ( 1 ) {
V_499 = V_62 -> V_79 [ 0 ] ;
V_64 = V_62 -> V_78 [ 0 ] ;
if ( V_499 >= F_37 ( V_64 ) ) {
V_27 = F_42 ( V_33 , V_62 ) ;
if ( V_27 == 0 )
continue;
if ( V_27 < 0 )
goto V_69;
break;
}
F_39 ( V_64 , & V_140 , V_499 ) ;
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
void F_421 ( struct V_11 * V_12 )
{
struct V_1 * V_13 ;
T_2 V_67 = 0 ;
while ( 1 ) {
struct V_254 * V_254 ;
V_13 = F_64 ( V_12 , V_67 ) ;
while ( V_13 ) {
F_11 ( & V_13 -> V_49 ) ;
if ( V_13 -> V_163 )
break;
F_13 ( & V_13 -> V_49 ) ;
V_13 = F_218 ( V_12 -> V_237 ,
V_13 ) ;
}
if ( ! V_13 ) {
if ( V_67 == 0 )
break;
V_67 = 0 ;
continue;
}
V_254 = V_13 -> V_254 ;
V_13 -> V_163 = 0 ;
V_13 -> V_254 = NULL ;
F_13 ( & V_13 -> V_49 ) ;
F_233 ( V_254 ) ;
V_67 = V_13 -> V_20 . V_21 + V_13 -> V_20 . V_31 ;
F_6 ( V_13 ) ;
}
}
int F_422 ( struct V_11 * V_12 )
{
struct V_1 * V_13 ;
struct V_96 * V_99 ;
struct V_47 * V_51 ;
struct V_14 * V_28 ;
F_60 ( & V_12 -> V_76 ) ;
while ( ! F_167 ( & V_12 -> V_94 ) ) {
V_51 = F_168 ( V_12 -> V_94 . V_216 ,
struct V_47 , V_86 ) ;
F_183 ( & V_51 -> V_86 ) ;
F_26 ( V_51 ) ;
}
F_62 ( & V_12 -> V_76 ) ;
F_11 ( & V_12 -> V_17 ) ;
while ( ( V_28 = F_180 ( & V_12 -> V_18 ) ) != NULL ) {
V_13 = F_12 ( V_28 , struct V_1 ,
V_19 ) ;
F_175 ( & V_13 -> V_19 ,
& V_12 -> V_18 ) ;
F_13 ( & V_12 -> V_17 ) ;
F_60 ( & V_13 -> V_99 -> V_282 ) ;
F_183 ( & V_13 -> V_86 ) ;
F_62 ( & V_13 -> V_99 -> V_282 ) ;
if ( V_13 -> V_3 == V_50 )
F_340 ( V_13 ) ;
if ( V_13 -> V_3 == V_90 )
F_19 ( V_12 -> V_60 , V_13 ) ;
F_423 ( V_13 ) ;
F_6 ( V_13 ) ;
F_11 ( & V_12 -> V_17 ) ;
}
F_13 ( & V_12 -> V_17 ) ;
F_424 () ;
F_294 ( V_12 ) ;
while( ! F_167 ( & V_12 -> V_99 ) ) {
V_99 = F_168 ( V_12 -> V_99 . V_216 ,
struct V_96 ,
V_86 ) ;
if ( V_99 -> V_283 > 0 ||
V_99 -> V_284 > 0 ||
V_99 -> V_286 > 0 ) {
F_8 ( 1 ) ;
F_258 ( V_99 , 0 , 0 ) ;
}
F_183 ( & V_99 -> V_86 ) ;
F_9 ( V_99 ) ;
}
return 0 ;
}
static void F_425 ( struct V_96 * V_99 ,
struct V_1 * V_2 )
{
int V_446 = F_342 ( V_2 ) ;
F_60 ( & V_99 -> V_282 ) ;
F_61 ( & V_2 -> V_86 , & V_99 -> V_281 [ V_446 ] ) ;
F_62 ( & V_99 -> V_282 ) ;
}
int F_426 ( struct V_32 * V_33 )
{
struct V_61 * V_62 ;
int V_27 ;
struct V_1 * V_2 ;
struct V_11 * V_12 = V_33 -> V_35 ;
struct V_96 * V_99 ;
struct V_65 V_20 ;
struct V_65 V_140 ;
struct V_63 * V_64 ;
int V_537 = 0 ;
T_2 V_538 ;
V_33 = V_12 -> V_60 ;
V_20 . V_21 = 0 ;
V_20 . V_31 = 0 ;
F_78 ( & V_20 , V_176 ) ;
V_62 = F_32 () ;
if ( ! V_62 )
return - V_85 ;
V_62 -> V_72 = 1 ;
V_538 = F_427 ( V_33 -> V_35 -> V_334 ) ;
if ( F_228 ( V_33 , V_267 ) &&
F_428 ( V_33 -> V_35 -> V_334 ) != V_538 )
V_537 = 1 ;
if ( F_228 ( V_33 , V_539 ) )
V_537 = 1 ;
while ( 1 ) {
V_27 = F_420 ( V_33 , V_62 , & V_20 ) ;
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
F_239 ( & V_2 -> V_49 ) ;
V_2 -> V_35 = V_12 ;
F_52 ( & V_2 -> V_86 ) ;
F_52 ( & V_2 -> V_540 ) ;
if ( V_537 ) {
V_2 -> V_260 = V_269 ;
if ( F_228 ( V_33 , V_267 ) )
V_2 -> V_270 = 1 ;
}
F_429 ( V_64 , & V_2 -> V_112 ,
F_216 ( V_64 , V_62 -> V_79 [ 0 ] ) ,
sizeof( V_2 -> V_112 ) ) ;
memcpy ( & V_2 -> V_20 , & V_140 , sizeof( V_140 ) ) ;
V_20 . V_21 = V_140 . V_21 + V_140 . V_31 ;
F_43 ( V_62 ) ;
V_2 -> V_6 = F_430 ( & V_2 -> V_112 ) ;
V_2 -> V_316 = V_33 -> V_316 ;
F_431 ( V_2 ) ;
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
V_27 = F_237 ( V_12 , V_2 -> V_6 , V_140 . V_31 ,
F_76 ( & V_2 -> V_112 ) ,
& V_99 ) ;
F_22 ( V_27 ) ;
V_2 -> V_99 = V_99 ;
F_11 ( & V_2 -> V_99 -> V_49 ) ;
V_2 -> V_99 -> V_285 += V_2 -> V_44 ;
F_13 ( & V_2 -> V_99 -> V_49 ) ;
F_425 ( V_99 , V_2 ) ;
V_27 = F_10 ( V_33 -> V_35 , V_2 ) ;
F_22 ( V_27 ) ;
F_241 ( V_33 -> V_35 , V_2 -> V_6 ) ;
if ( F_432 ( V_33 , V_2 -> V_20 . V_21 ) )
F_412 ( V_2 , 1 ) ;
}
F_68 (space_info, &root->fs_info->space_info, list) {
if ( ! ( F_246 ( V_33 , V_99 -> V_6 ) &
( V_277 |
V_276 |
V_275 ) ) )
continue;
F_345 (cache, &space_info->block_groups[3], list)
F_412 ( V_2 , 1 ) ;
F_345 (cache, &space_info->block_groups[4], list)
F_412 ( V_2 , 1 ) ;
}
F_293 ( V_12 ) ;
V_27 = 0 ;
error:
F_48 ( V_62 ) ;
return V_27 ;
}
int F_433 ( struct V_82 * V_83 ,
struct V_32 * V_33 , T_2 V_274 ,
T_2 type , T_2 V_541 , T_2 V_542 ,
T_2 V_54 )
{
int V_27 ;
struct V_32 * V_60 ;
struct V_1 * V_2 ;
V_60 = V_33 -> V_35 -> V_60 ;
V_33 -> V_35 -> V_543 = V_83 -> V_263 ;
V_2 = F_51 ( sizeof( * V_2 ) , V_38 ) ;
if ( ! V_2 )
return - V_85 ;
V_2 -> V_10 = F_51 ( sizeof( * V_2 -> V_10 ) ,
V_38 ) ;
if ( ! V_2 -> V_10 ) {
F_9 ( V_2 ) ;
return - V_85 ;
}
V_2 -> V_20 . V_21 = V_542 ;
V_2 -> V_20 . V_31 = V_54 ;
V_2 -> V_20 . type = V_176 ;
V_2 -> V_316 = V_33 -> V_316 ;
V_2 -> V_35 = V_33 -> V_35 ;
F_55 ( & V_2 -> V_7 , 1 ) ;
F_239 ( & V_2 -> V_49 ) ;
F_52 ( & V_2 -> V_86 ) ;
F_52 ( & V_2 -> V_540 ) ;
F_431 ( V_2 ) ;
F_317 ( & V_2 -> V_112 , V_274 ) ;
F_434 ( & V_2 -> V_112 , V_541 ) ;
V_2 -> V_6 = type ;
F_435 ( & V_2 -> V_112 , type ) ;
V_2 -> V_93 = ( T_2 ) - 1 ;
V_2 -> V_3 = V_4 ;
F_21 ( V_33 , V_2 ) ;
F_27 ( V_2 , V_33 -> V_35 , V_542 ,
V_542 + V_54 ) ;
F_19 ( V_33 , V_2 ) ;
V_27 = F_237 ( V_33 -> V_35 , V_2 -> V_6 , V_54 , V_274 ,
& V_2 -> V_99 ) ;
F_22 ( V_27 ) ;
F_292 ( V_33 -> V_35 ) ;
F_11 ( & V_2 -> V_99 -> V_49 ) ;
V_2 -> V_99 -> V_285 += V_2 -> V_44 ;
F_13 ( & V_2 -> V_99 -> V_49 ) ;
F_425 ( V_2 -> V_99 , V_2 ) ;
V_27 = F_10 ( V_33 -> V_35 , V_2 ) ;
F_22 ( V_27 ) ;
V_27 = F_436 ( V_83 , V_60 , & V_2 -> V_20 , & V_2 -> V_112 ,
sizeof( V_2 -> V_112 ) ) ;
if ( V_27 ) {
F_151 ( V_83 , V_60 , V_27 ) ;
return V_27 ;
}
F_241 ( V_60 -> V_35 , type ) ;
return 0 ;
}
static void F_437 ( struct V_11 * V_35 , T_2 V_6 )
{
T_2 V_292 = F_242 ( V_6 ) &
V_293 ;
if ( V_6 & V_290 )
V_35 -> V_294 &= ~ V_292 ;
if ( V_6 & V_114 )
V_35 -> V_295 &= ~ V_292 ;
if ( V_6 & V_296 )
V_35 -> V_297 &= ~ V_292 ;
}
int F_438 ( struct V_82 * V_83 ,
struct V_32 * V_33 , T_2 V_109 )
{
struct V_61 * V_62 ;
struct V_1 * V_13 ;
struct V_450 * V_213 ;
struct V_32 * V_237 = V_33 -> V_35 -> V_237 ;
struct V_65 V_20 ;
struct V_254 * V_254 ;
int V_27 ;
int V_446 ;
int V_104 ;
V_33 = V_33 -> V_35 -> V_60 ;
V_13 = F_65 ( V_33 -> V_35 , V_109 ) ;
F_22 ( ! V_13 ) ;
F_22 ( ! V_13 -> V_113 ) ;
F_19 ( V_33 , V_13 ) ;
memcpy ( & V_20 , & V_13 -> V_20 , sizeof( V_20 ) ) ;
V_446 = F_342 ( V_13 ) ;
if ( V_13 -> V_6 & ( V_275 |
V_276 |
V_277 ) )
V_104 = 2 ;
else
V_104 = 1 ;
V_213 = & V_33 -> V_35 -> V_466 ;
F_11 ( & V_213 -> V_471 ) ;
F_349 ( V_13 , V_213 ) ;
F_13 ( & V_213 -> V_471 ) ;
V_213 = & V_33 -> V_35 -> V_464 ;
F_11 ( & V_213 -> V_471 ) ;
F_349 ( V_13 , V_213 ) ;
F_13 ( & V_213 -> V_471 ) ;
V_62 = F_32 () ;
if ( ! V_62 ) {
V_27 = - V_85 ;
goto V_69;
}
V_254 = F_220 ( V_237 , V_13 , V_62 ) ;
if ( ! F_221 ( V_254 ) ) {
V_27 = F_439 ( V_83 , V_254 ) ;
if ( V_27 ) {
F_440 ( V_254 ) ;
goto V_69;
}
F_441 ( V_254 ) ;
F_11 ( & V_13 -> V_49 ) ;
if ( V_13 -> V_163 ) {
V_13 -> V_163 = 0 ;
V_13 -> V_254 = NULL ;
F_13 ( & V_13 -> V_49 ) ;
F_233 ( V_254 ) ;
} else {
F_13 ( & V_13 -> V_49 ) ;
}
F_440 ( V_254 ) ;
}
V_20 . V_21 = V_544 ;
V_20 . V_31 = V_13 -> V_20 . V_21 ;
V_20 . type = 0 ;
V_27 = F_36 ( V_83 , V_237 , & V_20 , V_62 , - 1 , 1 ) ;
if ( V_27 < 0 )
goto V_69;
if ( V_27 > 0 )
F_43 ( V_62 ) ;
if ( V_27 == 0 ) {
V_27 = F_119 ( V_83 , V_237 , V_62 ) ;
if ( V_27 )
goto V_69;
F_43 ( V_62 ) ;
}
F_11 ( & V_33 -> V_35 -> V_17 ) ;
F_175 ( & V_13 -> V_19 ,
& V_33 -> V_35 -> V_18 ) ;
F_13 ( & V_33 -> V_35 -> V_17 ) ;
F_60 ( & V_13 -> V_99 -> V_282 ) ;
F_173 ( & V_13 -> V_86 ) ;
if ( F_167 ( & V_13 -> V_99 -> V_281 [ V_446 ] ) )
F_437 ( V_33 -> V_35 , V_13 -> V_6 ) ;
F_62 ( & V_13 -> V_99 -> V_282 ) ;
if ( V_13 -> V_3 == V_50 )
F_340 ( V_13 ) ;
F_423 ( V_13 ) ;
F_11 ( & V_13 -> V_99 -> V_49 ) ;
V_13 -> V_99 -> V_273 -= V_13 -> V_20 . V_31 ;
V_13 -> V_99 -> V_285 -= V_13 -> V_20 . V_31 ;
V_13 -> V_99 -> V_278 -= V_13 -> V_20 . V_31 * V_104 ;
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
int F_442 ( struct V_11 * V_35 )
{
struct V_96 * V_99 ;
struct V_545 * V_546 ;
T_2 V_547 ;
T_2 V_6 ;
int V_548 = 0 ;
int V_27 ;
V_546 = V_35 -> V_334 ;
if ( ! F_443 ( V_546 ) )
return 1 ;
V_547 = F_444 ( V_546 ) ;
if ( V_547 & V_549 )
V_548 = 1 ;
V_6 = V_296 ;
V_27 = F_237 ( V_35 , V_6 , 0 , 0 , & V_99 ) ;
if ( V_27 )
goto V_69;
if ( V_548 ) {
V_6 = V_114 | V_290 ;
V_27 = F_237 ( V_35 , V_6 , 0 , 0 , & V_99 ) ;
} else {
V_6 = V_114 ;
V_27 = F_237 ( V_35 , V_6 , 0 , 0 , & V_99 ) ;
if ( V_27 )
goto V_69;
V_6 = V_290 ;
V_27 = F_237 ( V_35 , V_6 , 0 , 0 , & V_99 ) ;
}
V_69:
return V_27 ;
}
int F_445 ( struct V_32 * V_33 , T_2 V_30 , T_2 V_29 )
{
return F_326 ( V_33 , V_30 , V_29 ) ;
}
int F_446 ( struct V_32 * V_33 , T_2 V_25 ,
T_2 V_34 , T_2 * V_184 )
{
return F_145 ( V_33 , V_25 , V_34 , V_184 ) ;
}
int F_447 ( struct V_32 * V_33 , struct V_550 * V_551 )
{
struct V_11 * V_35 = V_33 -> V_35 ;
struct V_1 * V_2 = NULL ;
T_2 V_552 ;
T_2 V_30 ;
T_2 V_29 ;
T_2 V_553 = 0 ;
T_2 V_273 = F_254 ( V_35 -> V_334 ) ;
int V_27 = 0 ;
if ( V_551 -> V_115 == V_273 )
V_2 = F_64 ( V_35 , V_551 -> V_30 ) ;
else
V_2 = F_65 ( V_35 , V_551 -> V_30 ) ;
while ( V_2 ) {
if ( V_2 -> V_20 . V_21 >= ( V_551 -> V_30 + V_551 -> V_115 ) ) {
F_6 ( V_2 ) ;
break;
}
V_30 = F_75 ( V_551 -> V_30 , V_2 -> V_20 . V_21 ) ;
V_29 = F_263 ( V_551 -> V_30 + V_551 -> V_115 ,
V_2 -> V_20 . V_21 + V_2 -> V_20 . V_31 ) ;
if ( V_29 - V_30 >= V_551 -> V_554 ) {
if ( ! F_1 ( V_2 ) ) {
V_27 = F_49 ( V_2 , NULL , V_33 , 0 ) ;
if ( ! V_27 )
F_340 ( V_2 ) ;
}
V_27 = F_448 ( V_2 ,
& V_552 ,
V_30 ,
V_29 ,
V_551 -> V_554 ) ;
V_553 += V_552 ;
if ( V_27 ) {
F_6 ( V_2 ) ;
break;
}
}
V_2 = F_218 ( V_35 -> V_237 , V_2 ) ;
}
V_551 -> V_115 = V_553 ;
return V_27 ;
}
