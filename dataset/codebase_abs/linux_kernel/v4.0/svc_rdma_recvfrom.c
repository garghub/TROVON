static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 )
{
struct V_6 * V_7 ;
struct V_8 * V_8 ;
T_1 V_9 ;
int V_10 ;
V_8 = V_4 -> V_11 [ 0 ] ;
F_2 ( V_2 -> V_12 [ 0 ] ) ;
V_2 -> V_12 [ 0 ] = V_8 ;
V_2 -> V_13 . V_14 [ 0 ] . V_15 = F_3 ( V_8 ) ;
V_2 -> V_13 . V_14 [ 0 ] . V_16 =
F_4 ( V_17 , V_5 , V_4 -> V_18 [ 0 ] . V_19 ) ;
V_2 -> V_13 . V_20 = V_5 ;
V_2 -> V_13 . V_21 = V_5 ;
V_9 = V_5 - V_2 -> V_13 . V_14 [ 0 ] . V_16 ;
V_2 -> V_13 . V_22 = V_9 ;
V_2 -> V_13 . V_23 = 0 ;
V_7 = (struct V_6 * ) V_2 -> V_13 . V_14 [ 0 ] . V_15 ;
if ( F_5 ( V_7 -> V_24 ) == V_25 )
V_2 -> V_13 . V_11 = & V_2 -> V_12 [ 0 ] ;
else
V_2 -> V_13 . V_11 = & V_2 -> V_12 [ 1 ] ;
V_10 = 1 ;
while ( V_9 && V_10 < V_4 -> V_26 ) {
V_8 = V_4 -> V_11 [ V_10 ] ;
F_2 ( V_2 -> V_12 [ V_10 ] ) ;
V_2 -> V_12 [ V_10 ] = V_8 ;
V_9 -= F_4 ( T_1 , V_9 , V_4 -> V_18 [ V_10 ] . V_19 ) ;
V_2 -> V_13 . V_21 += V_4 -> V_18 [ V_10 ] . V_19 ;
V_10 ++ ;
}
V_2 -> V_27 = & V_2 -> V_12 [ V_10 ] ;
V_2 -> V_28 = V_2 -> V_27 + 1 ;
V_9 = V_10 ;
while ( V_10 < V_4 -> V_26 ) {
V_8 = V_4 -> V_11 [ V_10 ++ ] ;
F_2 ( V_8 ) ;
}
V_4 -> V_26 = V_9 ;
V_2 -> V_13 . V_29 [ 0 ] . V_15 = NULL ;
V_2 -> V_13 . V_29 [ 0 ] . V_16 = 0 ;
}
static int F_6 ( struct V_30 * V_31 , int V_32 )
{
if ( F_7 ( V_31 -> V_33 -> V_34 -> V_35 ) ==
V_36 )
return 1 ;
else
return F_4 ( int , V_32 , V_31 -> V_37 ) ;
}
int F_8 ( struct V_30 * V_31 ,
struct V_1 * V_2 ,
struct V_3 * V_14 ,
int * V_38 ,
T_1 * V_39 ,
T_1 V_40 ,
T_1 V_41 ,
T_2 V_42 ,
bool V_43 )
{
struct V_44 V_45 ;
int V_46 = F_9 ( * V_39 + V_41 ) >> V_47 ;
struct V_3 * V_4 = F_10 ( V_31 ) ;
int V_48 , V_49 , V_50 ;
T_1 V_51 = * V_39 ;
T_1 V_52 = * V_38 ;
V_4 -> V_53 = V_54 ;
V_4 -> V_55 = V_14 ;
V_46 =
F_4 ( int , V_46 , F_6 ( V_31 , V_46 ) ) ;
V_49 = F_4 ( int , V_46 << V_47 , V_41 ) ;
for ( V_50 = 0 ; V_50 < V_46 ; V_50 ++ ) {
int V_20 = F_4 ( int , V_41 , V_56 - V_51 ) ;
V_14 -> V_57 . V_11 [ V_52 ] = V_2 -> V_13 . V_11 [ V_52 ] ;
V_14 -> V_57 . V_22 += V_20 ;
V_14 -> V_57 . V_20 += V_20 ;
if ( ! V_51 )
V_14 -> V_26 ++ ;
V_2 -> V_27 = & V_2 -> V_13 . V_11 [ V_52 + 1 ] ;
V_2 -> V_28 = V_2 -> V_27 + 1 ;
V_4 -> V_18 [ V_50 ] . V_58 =
F_11 ( V_31 -> V_33 -> V_34 ,
V_14 -> V_57 . V_11 [ V_52 ] , V_51 ,
V_56 - V_51 ,
V_54 ) ;
V_48 = F_12 ( V_31 -> V_33 -> V_34 ,
V_4 -> V_18 [ V_50 ] . V_58 ) ;
if ( V_48 )
goto V_59;
F_13 ( & V_31 -> V_60 ) ;
V_4 -> V_18 [ V_50 ] . V_61 = V_31 -> V_62 ;
V_4 -> V_18 [ V_50 ] . V_19 = V_20 ;
V_4 -> V_26 ++ ;
V_51 += V_20 ;
if ( V_51 == V_56 ) {
V_51 = 0 ;
V_52 ++ ;
}
V_41 -= V_20 ;
}
if ( V_43 && V_41 == 0 )
F_14 ( V_63 , & V_4 -> V_64 ) ;
else
F_15 ( V_63 , & V_4 -> V_64 ) ;
memset ( & V_45 , 0 , sizeof( V_45 ) ) ;
V_45 . V_65 = ( unsigned long ) V_4 ;
V_45 . V_66 = V_67 ;
V_4 -> V_68 = V_45 . V_66 ;
V_45 . V_69 = V_70 ;
V_45 . V_71 . V_72 . V_73 = V_40 ;
V_45 . V_71 . V_72 . V_74 = V_42 ;
V_45 . V_75 = V_4 -> V_18 ;
V_45 . V_76 = V_46 ;
V_48 = F_16 ( V_31 , & V_45 ) ;
if ( V_48 ) {
F_17 ( L_1 , V_48 ) ;
F_14 ( V_77 , & V_31 -> V_78 . V_79 ) ;
goto V_59;
}
* V_38 = V_52 ;
* V_39 = V_51 ;
V_48 = V_49 ;
F_13 ( & V_80 ) ;
return V_48 ;
V_59:
F_18 ( V_4 ) ;
F_19 ( V_4 , 0 ) ;
return V_48 ;
}
int F_20 ( struct V_30 * V_31 ,
struct V_1 * V_2 ,
struct V_3 * V_14 ,
int * V_38 ,
T_1 * V_39 ,
T_1 V_40 ,
T_1 V_41 ,
T_2 V_42 ,
bool V_43 )
{
struct V_44 V_45 ;
struct V_44 V_81 ;
struct V_44 V_82 ;
T_3 V_83 ;
int V_46 = F_9 ( * V_39 + V_41 ) >> V_47 ;
struct V_3 * V_4 = F_10 ( V_31 ) ;
struct V_84 * V_85 = F_21 ( V_31 ) ;
int V_48 , V_49 , V_50 ;
T_1 V_51 = * V_39 ;
T_1 V_52 = * V_38 ;
if ( F_22 ( V_85 ) )
return - V_86 ;
V_4 -> V_53 = V_54 ;
V_4 -> V_85 = V_85 ;
V_46 = F_4 ( int , V_46 , V_31 -> V_87 ) ;
V_49 = F_4 ( int , V_46 << V_47 , V_41 ) ;
V_85 -> V_88 = F_3 ( V_2 -> V_13 . V_11 [ V_52 ] ) ;
V_85 -> V_53 = V_54 ;
V_85 -> V_89 = ( V_90 | V_91 ) ;
V_85 -> V_92 = V_46 << V_47 ;
V_85 -> V_93 = V_46 ;
for ( V_50 = 0 ; V_50 < V_46 ; V_50 ++ ) {
int V_20 = F_4 ( int , V_41 , V_56 - V_51 ) ;
V_14 -> V_57 . V_11 [ V_52 ] = V_2 -> V_13 . V_11 [ V_52 ] ;
V_14 -> V_57 . V_22 += V_20 ;
V_14 -> V_57 . V_20 += V_20 ;
if ( ! V_51 )
V_14 -> V_26 ++ ;
V_2 -> V_27 = & V_2 -> V_13 . V_11 [ V_52 + 1 ] ;
V_2 -> V_28 = V_2 -> V_27 + 1 ;
V_85 -> V_94 -> V_94 [ V_50 ] =
F_11 ( V_31 -> V_33 -> V_34 ,
V_14 -> V_57 . V_11 [ V_52 ] , 0 ,
V_56 , V_54 ) ;
V_48 = F_12 ( V_31 -> V_33 -> V_34 ,
V_85 -> V_94 -> V_94 [ V_50 ] ) ;
if ( V_48 )
goto V_59;
F_13 ( & V_31 -> V_60 ) ;
V_51 += V_20 ;
if ( V_51 == V_56 ) {
V_51 = 0 ;
V_52 ++ ;
}
V_41 -= V_20 ;
}
if ( V_43 && V_41 == 0 )
F_14 ( V_63 , & V_4 -> V_64 ) ;
else
F_15 ( V_63 , & V_4 -> V_64 ) ;
V_83 = ( T_3 ) ( V_85 -> V_95 -> V_61 & 0x000000FF ) ;
F_23 ( V_85 -> V_95 , ++ V_83 ) ;
V_4 -> V_18 [ 0 ] . V_58 = ( unsigned long ) V_85 -> V_88 + * V_39 ;
V_4 -> V_18 [ 0 ] . V_61 = V_85 -> V_95 -> V_61 ;
V_4 -> V_18 [ 0 ] . V_19 = V_49 ;
V_4 -> V_26 = 1 ;
V_4 -> V_55 = V_14 ;
memset ( & V_82 , 0 , sizeof( V_82 ) ) ;
V_82 . V_66 = V_96 ;
V_82 . V_69 = V_70 ;
V_82 . V_71 . V_97 . V_98 = ( unsigned long ) V_85 -> V_88 ;
V_82 . V_71 . V_97 . V_94 = V_85 -> V_94 ;
V_82 . V_71 . V_97 . V_93 = V_85 -> V_93 ;
V_82 . V_71 . V_97 . V_99 = V_47 ;
V_82 . V_71 . V_97 . V_19 = V_85 -> V_92 ;
V_82 . V_71 . V_97 . V_89 = V_85 -> V_89 ;
V_82 . V_71 . V_97 . V_73 = V_85 -> V_95 -> V_61 ;
V_82 . V_100 = & V_45 ;
memset ( & V_45 , 0 , sizeof( V_45 ) ) ;
V_45 . V_69 = V_70 ;
V_45 . V_71 . V_72 . V_73 = V_40 ;
V_45 . V_71 . V_72 . V_74 = V_42 ;
V_45 . V_75 = V_4 -> V_18 ;
V_45 . V_76 = 1 ;
if ( V_31 -> V_101 & V_102 ) {
V_45 . V_66 = V_103 ;
V_45 . V_65 = ( unsigned long ) V_4 ;
V_45 . V_104 . V_105 = V_4 -> V_85 -> V_95 -> V_61 ;
} else {
V_45 . V_66 = V_67 ;
V_45 . V_100 = & V_81 ;
memset ( & V_81 , 0 , sizeof( V_81 ) ) ;
V_81 . V_65 = ( unsigned long ) V_4 ;
V_81 . V_66 = V_106 ;
V_81 . V_69 = V_70 | V_107 ;
V_81 . V_104 . V_105 = V_85 -> V_95 -> V_61 ;
}
V_4 -> V_68 = V_45 . V_66 ;
V_48 = F_16 ( V_31 , & V_82 ) ;
if ( V_48 ) {
F_17 ( L_1 , V_48 ) ;
F_14 ( V_77 , & V_31 -> V_78 . V_79 ) ;
goto V_59;
}
* V_38 = V_52 ;
* V_39 = V_51 ;
V_48 = V_49 ;
F_13 ( & V_80 ) ;
return V_48 ;
V_59:
F_18 ( V_4 ) ;
F_19 ( V_4 , 0 ) ;
F_24 ( V_31 , V_85 ) ;
return V_48 ;
}
static unsigned int
F_25 ( struct V_108 * V_109 )
{
unsigned int V_26 ;
for ( V_26 = 0 ; V_109 -> V_110 != V_111 ; V_109 ++ )
V_26 ++ ;
return V_26 ;
}
static int
F_26 ( struct V_1 * V_2 , struct V_3 * V_14 ,
T_1 V_112 , T_1 V_5 , T_1 V_39 , int V_38 )
{
char * V_113 , * V_114 ;
int V_48 ;
V_48 = 0 ;
V_113 = V_14 -> V_57 . V_14 [ 0 ] . V_15 + V_112 ;
V_5 = V_14 -> V_57 . V_14 [ 0 ] . V_16 - V_112 ;
if ( V_5 > V_56 ) {
F_27 ( L_2 ) ;
return 0 ;
}
if ( V_39 != V_56 ) {
V_114 = F_3 ( V_2 -> V_13 . V_11 [ V_38 ] ) ;
V_114 += V_39 ;
while ( V_5 -- ) {
* V_114 ++ = * V_113 ++ ;
V_39 ++ ;
if ( V_39 == V_56 && V_5 )
goto V_115;
}
goto V_116;
}
V_115:
V_38 ++ ;
V_114 = F_3 ( V_2 -> V_13 . V_11 [ V_38 ] ) ;
while ( V_5 -- )
* V_114 ++ = * V_113 ++ ;
V_2 -> V_27 = & V_2 -> V_13 . V_11 [ V_38 + 1 ] ;
V_2 -> V_28 = V_2 -> V_27 + 1 ;
V_116:
V_5 = V_14 -> V_57 . V_14 [ 0 ] . V_16 - V_112 ;
V_14 -> V_57 . V_22 += V_5 ;
V_14 -> V_57 . V_20 += V_5 ;
V_14 -> V_57 . V_21 += V_5 ;
return 1 ;
}
static int F_28 ( struct V_30 * V_31 ,
struct V_6 * V_7 ,
struct V_1 * V_2 ,
struct V_3 * V_14 )
{
int V_38 , V_48 ;
struct V_108 * V_109 ;
T_1 V_117 , V_39 , V_5 ;
T_1 V_112 ;
T_2 V_42 ;
bool V_43 ;
V_109 = F_29 ( V_7 ) ;
if ( ! V_109 )
return 0 ;
if ( F_25 ( V_109 ) > V_118 )
return - V_119 ;
V_14 -> V_57 . V_14 [ 0 ] = V_2 -> V_13 . V_14 [ 0 ] ;
V_14 -> V_57 . V_29 [ 0 ] = V_2 -> V_13 . V_29 [ 0 ] ;
V_14 -> V_120 = V_14 -> V_26 ;
V_14 -> V_57 . V_23 = 0 ;
V_14 -> V_57 . V_22 = 0 ;
V_14 -> V_57 . V_20 = V_2 -> V_13 . V_20 ;
V_14 -> V_57 . V_21 = V_2 -> V_13 . V_21 ;
V_109 = (struct V_108 * ) & V_7 -> V_121 . V_122 [ 0 ] ;
V_112 = F_5 ( V_109 -> V_123 ) ;
if ( V_112 == 0 ) {
V_14 -> V_57 . V_11 = & V_14 -> V_11 [ 0 ] ;
V_39 = V_14 -> V_124 ;
} else {
V_14 -> V_57 . V_11 = & V_14 -> V_11 [ V_14 -> V_26 ] ;
V_39 = 0 ;
}
V_48 = 0 ;
V_38 = 0 ;
for (; V_109 -> V_110 != V_111 ; V_109 ++ ) {
if ( F_5 ( V_109 -> V_123 ) != V_112 )
goto V_59;
V_117 = F_5 ( V_109 -> V_125 . V_40 ) ,
V_5 = F_5 ( V_109 -> V_125 . V_41 ) ;
F_30 ( ( V_126 * ) & V_109 -> V_125 . V_42 ,
& V_42 ) ;
while ( V_5 > 0 ) {
V_43 = ( V_109 + 1 ) -> V_110 == V_111 ;
V_48 = V_31 -> V_127 ( V_31 , V_2 , V_14 ,
& V_38 , & V_39 ,
V_117 , V_5 ,
V_42 , V_43 ) ;
if ( V_48 < 0 )
goto V_59;
V_5 -= V_48 ;
V_42 += V_48 ;
V_14 -> V_57 . V_21 += V_48 ;
}
}
if ( V_39 & 3 ) {
T_1 V_128 = 4 - ( V_39 & 3 ) ;
V_14 -> V_57 . V_22 += V_128 ;
V_14 -> V_57 . V_20 += V_128 ;
V_14 -> V_57 . V_21 += V_128 ;
V_39 += V_128 ;
}
V_48 = 1 ;
if ( V_112 && V_112 < V_14 -> V_57 . V_14 [ 0 ] . V_16 )
V_48 = F_26 ( V_2 , V_14 , V_112 ,
V_5 , V_39 , V_38 ) ;
V_14 -> V_57 . V_14 [ 0 ] . V_16 = V_112 ;
V_14 -> V_112 = V_112 ;
V_59:
for ( V_38 = 0 ;
& V_2 -> V_12 [ V_38 ] < V_2 -> V_27 ; V_38 ++ )
V_2 -> V_12 [ V_38 ] = NULL ;
return V_48 ;
}
static int F_31 ( struct V_1 * V_2 ,
struct V_3 * V_14 )
{
int V_38 ;
int V_48 ;
for ( V_38 = 0 ; V_38 < V_14 -> V_26 ; V_38 ++ ) {
F_2 ( V_2 -> V_12 [ V_38 ] ) ;
V_2 -> V_12 [ V_38 ] = V_14 -> V_11 [ V_38 ] ;
}
if ( V_14 -> V_112 == 0 ) {
if ( V_14 -> V_57 . V_20 <= V_14 -> V_18 [ 0 ] . V_19 ) {
V_14 -> V_57 . V_14 [ 0 ] . V_16 = V_14 -> V_57 . V_20 -
V_14 -> V_124 ;
V_14 -> V_57 . V_22 = 0 ;
} else {
V_14 -> V_57 . V_14 [ 0 ] . V_16 = V_14 -> V_18 [ 0 ] . V_19 -
V_14 -> V_124 ;
V_14 -> V_57 . V_22 = V_14 -> V_57 . V_20 -
V_14 -> V_18 [ 0 ] . V_19 ;
}
}
V_2 -> V_13 . V_11 = & V_2 -> V_12 [ V_14 -> V_120 ] ;
V_2 -> V_13 . V_22 = V_14 -> V_57 . V_22 ;
V_2 -> V_13 . V_23 = V_14 -> V_57 . V_23 ;
V_2 -> V_27 = & V_2 -> V_13 . V_11 [ V_38 ] ;
V_2 -> V_28 = V_2 -> V_27 + 1 ;
V_2 -> V_13 . V_14 [ 0 ] = V_14 -> V_57 . V_14 [ 0 ] ;
V_2 -> V_13 . V_29 [ 0 ] = V_14 -> V_57 . V_29 [ 0 ] ;
V_2 -> V_13 . V_20 = V_14 -> V_57 . V_20 ;
V_2 -> V_13 . V_21 = V_14 -> V_57 . V_21 ;
F_19 ( V_14 , 0 ) ;
V_2 -> V_129 = V_130 ;
F_32 ( V_2 , V_2 -> V_131 ) ;
V_48 = V_2 -> V_13 . V_14 [ 0 ] . V_16
+ V_2 -> V_13 . V_22
+ V_2 -> V_13 . V_29 [ 0 ] . V_16 ;
F_27 ( L_3
L_4 ,
V_48 , V_2 -> V_13 . V_20 , V_2 -> V_13 . V_14 [ 0 ] . V_15 ,
V_2 -> V_13 . V_14 [ 0 ] . V_16 ) ;
return V_48 ;
}
int F_33 ( struct V_1 * V_2 )
{
struct V_132 * V_31 = V_2 -> V_131 ;
struct V_30 * V_133 =
F_34 ( V_31 , struct V_30 , V_78 ) ;
struct V_3 * V_4 = NULL ;
struct V_6 * V_7 ;
int V_48 = 0 ;
int V_20 ;
F_27 ( L_5 , V_2 ) ;
F_35 ( & V_133 -> V_134 ) ;
if ( ! F_36 ( & V_133 -> V_135 ) ) {
V_4 = F_37 ( V_133 -> V_135 . V_100 ,
struct V_3 ,
V_136 ) ;
F_38 ( & V_4 -> V_136 ) ;
F_39 ( & V_133 -> V_134 ) ;
return F_31 ( V_2 , V_4 ) ;
} else if ( ! F_36 ( & V_133 -> V_137 ) ) {
V_4 = F_37 ( V_133 -> V_137 . V_100 ,
struct V_3 ,
V_136 ) ;
F_38 ( & V_4 -> V_136 ) ;
} else {
F_13 ( & V_138 ) ;
F_15 ( V_139 , & V_31 -> V_79 ) ;
V_4 = NULL ;
}
F_39 ( & V_133 -> V_134 ) ;
if ( ! V_4 ) {
if ( F_40 ( V_77 , & V_31 -> V_79 ) )
goto V_140;
goto V_141;
}
F_27 ( L_6 ,
V_4 , V_133 , V_2 , V_4 -> V_142 ) ;
F_13 ( & V_143 ) ;
F_1 ( V_2 , V_4 , V_4 -> V_124 ) ;
V_20 = F_41 ( & V_7 , V_2 ) ;
V_2 -> V_144 = V_20 ;
if ( V_20 < 0 ) {
if ( V_20 == - V_145 )
F_42 ( V_133 , V_7 , V_146 ) ;
goto V_140;
}
V_48 = F_28 ( V_133 , V_7 , V_2 , V_4 ) ;
if ( V_48 > 0 ) {
goto V_147;
} else if ( V_48 < 0 ) {
F_19 ( V_4 , 1 ) ;
return 0 ;
}
V_48 = V_2 -> V_13 . V_14 [ 0 ] . V_16
+ V_2 -> V_13 . V_22
+ V_2 -> V_13 . V_29 [ 0 ] . V_16 ;
F_19 ( V_4 , 0 ) ;
V_141:
F_27 ( L_7
L_8 ,
V_48 , V_2 -> V_13 . V_20 ,
V_2 -> V_13 . V_14 [ 0 ] . V_15 ,
V_2 -> V_13 . V_14 [ 0 ] . V_16 ) ;
V_2 -> V_129 = V_130 ;
F_32 ( V_2 , V_31 ) ;
return V_48 ;
V_140:
if ( V_4 )
F_19 ( V_4 , 1 ) ;
F_27 ( L_9 , V_31 ) ;
F_14 ( V_77 , & V_31 -> V_79 ) ;
V_147:
return 0 ;
}
