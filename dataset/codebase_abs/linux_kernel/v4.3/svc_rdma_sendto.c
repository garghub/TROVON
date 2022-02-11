static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
int V_7 ;
T_1 V_8 ;
T_1 V_9 ;
T_1 V_10 ;
int V_11 ;
if ( V_4 -> V_12 !=
( V_4 -> V_13 [ 0 ] . V_14 + V_4 -> V_15 + V_4 -> V_16 [ 0 ] . V_14 ) ) {
F_2 ( L_1 ) ;
return - V_17 ;
}
V_7 = 1 ;
V_6 -> V_18 [ V_7 ] . V_19 = V_4 -> V_13 [ 0 ] . V_19 ;
V_6 -> V_18 [ V_7 ] . V_14 = V_4 -> V_13 [ 0 ] . V_14 ;
V_7 ++ ;
V_11 = 0 ;
V_9 = V_4 -> V_15 ;
V_10 = V_4 -> V_20 ;
while ( V_9 ) {
V_6 -> V_18 [ V_7 ] . V_19 =
F_3 ( V_4 -> V_21 [ V_11 ] ) + V_10 ;
V_8 = F_4 ( T_1 , V_9 , ( V_22 - V_10 ) ) ;
V_9 -= V_8 ;
V_6 -> V_18 [ V_7 ] . V_14 = V_8 ;
V_7 ++ ;
V_11 ++ ;
V_10 = 0 ;
}
if ( V_4 -> V_16 [ 0 ] . V_14 ) {
V_6 -> V_18 [ V_7 ] . V_19 = V_4 -> V_16 [ 0 ] . V_19 ;
V_6 -> V_18 [ V_7 ] . V_14 = V_4 -> V_16 [ 0 ] . V_14 ;
V_7 ++ ;
}
F_5 ( L_2
L_3 ,
V_7 , V_11 , V_4 -> V_20 , V_4 -> V_15 ,
V_4 -> V_13 [ 0 ] . V_14 , V_4 -> V_16 [ 0 ] . V_14 ) ;
V_6 -> V_23 = V_7 ;
return 0 ;
}
static T_2 F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_24 , T_3 V_12 , int V_25 )
{
struct V_26 * V_26 ;
T_2 V_27 ;
if ( V_24 < V_4 -> V_13 [ 0 ] . V_14 ) {
V_24 += ( unsigned long ) V_4 -> V_13 [ 0 ] . V_19 & ~ V_28 ;
V_26 = F_7 ( V_4 -> V_13 [ 0 ] . V_19 ) ;
} else {
V_24 -= V_4 -> V_13 [ 0 ] . V_14 ;
if ( V_24 < V_4 -> V_15 ) {
V_24 += V_4 -> V_20 ;
V_26 = V_4 -> V_21 [ V_24 >> V_29 ] ;
V_24 &= ~ V_28 ;
} else {
V_24 -= V_4 -> V_15 ;
V_24 += ( unsigned long )
V_4 -> V_16 [ 0 ] . V_19 & ~ V_28 ;
V_26 = F_7 ( V_4 -> V_16 [ 0 ] . V_19 ) ;
}
}
V_27 = F_8 ( V_2 -> V_30 -> V_31 , V_26 , V_24 ,
F_4 ( T_3 , V_22 , V_12 ) , V_25 ) ;
return V_27 ;
}
struct V_32 *
F_9 ( struct V_33 * V_34 )
{
struct V_32 * V_35 =
(struct V_32 * ) & V_34 -> V_36 . V_37 [ 0 ] ;
if ( V_35 -> V_38 == V_39 )
return NULL ;
return V_35 ;
}
static struct V_40 *
F_10 ( struct V_33 * V_34 )
{
if ( V_34 -> V_36 . V_37 [ 0 ] != V_39 ||
V_34 -> V_36 . V_37 [ 1 ] == V_39 )
return NULL ;
return (struct V_40 * ) & V_34 -> V_36 . V_37 [ 1 ] ;
}
static struct V_40 *
F_11 ( struct V_33 * V_34 )
{
struct V_32 * V_41 ;
struct V_40 * V_42 ;
struct V_40 * V_43 ;
if ( V_34 -> V_36 . V_37 [ 0 ] != V_39 ||
V_34 -> V_36 . V_37 [ 1 ] != V_39 )
return NULL ;
V_41 = F_9 ( V_34 ) ;
if ( V_41 ) {
while ( V_41 -> V_38 != V_39 )
V_41 ++ ;
V_43 = (struct V_40 * ) & V_41 -> V_44 ;
goto V_45;
}
V_42 = F_10 ( V_34 ) ;
if ( V_42 ) {
int V_46 = F_12 ( V_42 -> V_47 ) ;
V_43 = (struct V_40 * )
& V_42 -> V_48 [ V_46 ] . V_49 . V_50 ;
goto V_45;
}
V_43 = (struct V_40 * ) & V_34 -> V_36 . V_37 [ 2 ] ;
V_45:
if ( V_43 -> V_51 == V_39 )
return NULL ;
return V_43 ;
}
static int F_13 ( struct V_1 * V_2 , struct V_52 * V_53 ,
T_1 V_54 , T_4 V_55 ,
T_1 V_24 , int V_56 ,
struct V_5 * V_6 )
{
struct V_57 V_58 ;
struct V_59 * V_18 ;
int V_60 ;
int V_7 ;
int V_8 ;
int V_61 ;
int V_62 ;
struct V_63 * V_64 ;
if ( V_6 -> V_23 > V_65 ) {
F_2 ( L_4 , V_6 -> V_23 ) ;
return - V_17 ;
}
F_5 ( L_5
L_6 ,
V_54 , ( unsigned long long ) V_55 , V_24 ,
V_56 , V_6 -> V_18 , V_6 -> V_23 ) ;
V_64 = F_14 ( V_2 ) ;
V_64 -> V_66 = V_67 ;
V_18 = V_64 -> V_18 ;
for ( V_62 = V_24 , V_60 = 1 ; V_62 && V_60 < V_6 -> V_23 ;
V_60 ++ ) {
if ( V_6 -> V_18 [ V_60 ] . V_14 > V_62 )
break;
V_62 -= V_6 -> V_18 [ V_60 ] . V_14 ;
}
V_61 = V_62 ;
V_62 = V_56 ;
V_7 = 0 ;
while ( V_62 != 0 ) {
V_8 = F_4 ( T_3 ,
V_62 , V_6 -> V_18 [ V_60 ] . V_14 - V_61 ) ;
V_18 [ V_7 ] . V_68 = V_8 ;
V_18 [ V_7 ] . V_69 =
F_6 ( V_2 , & V_53 -> V_70 , V_24 ,
V_8 , V_67 ) ;
V_24 += V_8 ;
if ( F_15 ( V_2 -> V_30 -> V_31 ,
V_18 [ V_7 ] . V_69 ) )
goto V_71;
F_16 ( & V_2 -> V_72 ) ;
V_18 [ V_7 ] . V_73 = V_2 -> V_74 ;
V_64 -> V_23 ++ ;
V_61 = 0 ;
V_7 ++ ;
V_60 ++ ;
if ( V_60 > V_6 -> V_23 ) {
F_2 ( L_7 , V_60 ) ;
goto V_71;
}
V_62 -= V_8 ;
if ( V_7 == V_2 -> V_75 )
break;
}
memset ( & V_58 , 0 , sizeof V_58 ) ;
V_64 -> V_76 = V_77 ;
V_58 . V_78 = ( unsigned long ) V_64 ;
V_58 . V_79 = & V_18 [ 0 ] ;
V_58 . V_80 = V_7 ;
V_58 . V_81 = V_77 ;
V_58 . V_82 = V_83 ;
V_58 . V_84 . V_85 . V_86 = V_54 ;
V_58 . V_84 . V_85 . V_87 = V_55 ;
F_16 ( & V_88 ) ;
if ( F_17 ( V_2 , & V_58 ) )
goto V_71;
return V_56 - V_62 ;
V_71:
F_18 ( V_64 ) ;
F_19 ( V_64 , 0 ) ;
return - V_17 ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_33 * V_89 ,
struct V_33 * V_90 ,
struct V_52 * V_53 ,
struct V_5 * V_6 )
{
T_1 V_91 = V_53 -> V_70 . V_15 + V_53 -> V_70 . V_16 [ 0 ] . V_14 ;
int V_56 ;
T_1 V_24 ;
int V_92 ;
int V_93 ;
int V_94 ;
struct V_40 * V_95 ;
struct V_40 * V_96 ;
int V_97 ;
V_95 = F_10 ( V_89 ) ;
if ( ! V_95 )
return 0 ;
V_96 = (struct V_40 * )
& V_90 -> V_36 . V_37 [ 1 ] ;
V_94 = F_12 ( V_95 -> V_47 ) ;
for ( V_24 = V_53 -> V_70 . V_13 [ 0 ] . V_14 , V_93 = 0 ;
V_91 && V_93 < V_94 ;
V_93 ++ ) {
struct V_98 * V_99 ;
T_4 V_100 ;
V_99 = & V_95 -> V_48 [ V_93 ] . V_49 ;
V_56 = F_21 ( V_91 , F_12 ( V_99 -> V_50 ) ) ;
F_22 ( ( V_101 * ) & V_99 -> V_100 , & V_100 ) ;
F_23 ( V_96 , V_93 ,
V_99 -> V_102 ,
V_99 -> V_100 ,
V_56 ) ;
V_92 = 0 ;
while ( V_56 ) {
V_97 = F_13 ( V_2 , V_53 ,
F_12 ( V_99 -> V_102 ) ,
V_100 + V_92 ,
V_24 ,
V_56 ,
V_6 ) ;
if ( V_97 <= 0 ) {
F_5 ( L_8 ,
V_97 ) ;
return - V_17 ;
}
V_92 += V_97 ;
V_24 += V_97 ;
V_91 -= V_97 ;
V_56 -= V_97 ;
}
}
F_24 ( V_90 , V_93 ) ;
return V_53 -> V_70 . V_15 + V_53 -> V_70 . V_16 [ 0 ] . V_14 ;
}
static int F_25 ( struct V_1 * V_2 ,
struct V_33 * V_89 ,
struct V_33 * V_90 ,
struct V_52 * V_53 ,
struct V_5 * V_6 )
{
T_1 V_91 = V_53 -> V_70 . V_12 ;
int V_56 ;
T_1 V_24 ;
int V_93 ;
int V_92 ;
int V_94 ;
struct V_98 * V_35 ;
struct V_40 * V_95 ;
struct V_40 * V_96 ;
int V_97 ;
V_95 = F_11 ( V_89 ) ;
if ( ! V_95 )
return 0 ;
V_96 = (struct V_40 * )
& V_90 -> V_36 . V_37 [ 2 ] ;
V_94 = F_12 ( V_95 -> V_47 ) ;
for ( V_24 = 0 , V_93 = 0 ;
V_91 && V_93 < V_94 ;
V_93 ++ ) {
T_4 V_100 ;
V_35 = & V_95 -> V_48 [ V_93 ] . V_49 ;
V_56 = F_21 ( V_91 , F_12 ( V_35 -> V_50 ) ) ;
F_22 ( ( V_101 * ) & V_35 -> V_100 , & V_100 ) ;
F_23 ( V_96 , V_93 ,
V_35 -> V_102 , V_35 -> V_100 ,
V_56 ) ;
V_92 = 0 ;
while ( V_56 ) {
V_97 = F_13 ( V_2 , V_53 ,
F_12 ( V_35 -> V_102 ) ,
V_100 + V_92 ,
V_24 ,
V_56 ,
V_6 ) ;
if ( V_97 <= 0 ) {
F_5 ( L_8 ,
V_97 ) ;
return - V_17 ;
}
V_92 += V_97 ;
V_24 += V_97 ;
V_91 -= V_97 ;
V_56 -= V_97 ;
}
}
F_26 ( V_96 , V_93 ) ;
return V_53 -> V_70 . V_12 ;
}
static int F_27 ( struct V_1 * V_85 ,
struct V_52 * V_53 ,
struct V_26 * V_26 ,
struct V_33 * V_90 ,
struct V_63 * V_64 ,
struct V_5 * V_6 ,
int V_103 )
{
struct V_57 V_104 ;
T_1 V_24 ;
int V_7 ;
int V_8 ;
int V_11 ;
int V_21 ;
int V_97 ;
V_97 = F_28 ( V_85 ) ;
if ( V_97 ) {
F_29 ( V_105
L_9
L_10 , V_97 , V_85 ) ;
F_30 ( V_106 , & V_85 -> V_107 . V_108 ) ;
F_19 ( V_64 , 0 ) ;
return - V_109 ;
}
V_64 -> V_21 [ 0 ] = V_26 ;
V_64 -> V_23 = 1 ;
V_64 -> V_18 [ 0 ] . V_73 = V_85 -> V_74 ;
V_64 -> V_18 [ 0 ] . V_68 = F_31 ( V_90 ) ;
V_64 -> V_18 [ 0 ] . V_69 =
F_8 ( V_85 -> V_30 -> V_31 , V_26 , 0 ,
V_64 -> V_18 [ 0 ] . V_68 , V_67 ) ;
if ( F_15 ( V_85 -> V_30 -> V_31 , V_64 -> V_18 [ 0 ] . V_69 ) )
goto V_71;
F_16 ( & V_85 -> V_72 ) ;
V_64 -> V_66 = V_67 ;
V_24 = 0 ;
for ( V_7 = 1 ; V_103 && V_7 < V_6 -> V_23 ; V_7 ++ ) {
V_8 = F_4 ( T_3 , V_6 -> V_18 [ V_7 ] . V_14 , V_103 ) ;
V_103 -= V_8 ;
V_64 -> V_18 [ V_7 ] . V_69 =
F_6 ( V_85 , & V_53 -> V_70 , V_24 ,
V_8 , V_67 ) ;
V_24 += V_8 ;
if ( F_15 ( V_85 -> V_30 -> V_31 ,
V_64 -> V_18 [ V_7 ] . V_69 ) )
goto V_71;
F_16 ( & V_85 -> V_72 ) ;
V_64 -> V_18 [ V_7 ] . V_73 = V_85 -> V_74 ;
V_64 -> V_18 [ V_7 ] . V_68 = V_8 ;
}
if ( V_103 != 0 ) {
F_2 ( L_11 , V_103 ) ;
goto V_71;
}
V_21 = V_53 -> V_110 - V_53 -> V_111 ;
for ( V_11 = 0 ; V_11 < V_21 ; V_11 ++ ) {
V_64 -> V_21 [ V_11 + 1 ] = V_53 -> V_111 [ V_11 ] ;
V_64 -> V_23 ++ ;
V_53 -> V_111 [ V_11 ] = NULL ;
if ( V_11 + 1 >= V_7 )
V_64 -> V_18 [ V_11 + 1 ] . V_68 = 0 ;
}
V_53 -> V_110 = V_53 -> V_111 + 1 ;
if ( V_7 > V_64 -> V_23 )
F_32 ( & V_85 -> V_72 ) ;
if ( V_7 > V_85 -> V_75 ) {
F_2 ( L_7 , V_7 ) ;
goto V_71;
}
memset ( & V_104 , 0 , sizeof V_104 ) ;
V_64 -> V_76 = V_112 ;
V_104 . V_78 = ( unsigned long ) V_64 ;
V_104 . V_79 = V_64 -> V_18 ;
V_104 . V_80 = V_7 ;
V_104 . V_81 = V_112 ;
V_104 . V_82 = V_83 ;
V_97 = F_17 ( V_85 , & V_104 ) ;
if ( V_97 )
goto V_71;
return 0 ;
V_71:
F_18 ( V_64 ) ;
F_19 ( V_64 , 1 ) ;
return - V_17 ;
}
void F_33 ( struct V_52 * V_53 )
{
}
int F_34 ( struct V_52 * V_53 )
{
struct V_113 * V_2 = V_53 -> V_114 ;
struct V_1 * V_85 =
F_35 ( V_2 , struct V_1 , V_107 ) ;
struct V_33 * V_89 ;
struct V_33 * V_90 ;
struct V_40 * V_115 ;
enum V_116 V_117 ;
int V_97 ;
int V_118 ;
struct V_26 * V_119 ;
struct V_63 * V_64 ;
struct V_5 * V_6 ;
F_5 ( L_12 , V_53 ) ;
V_89 = F_3 ( V_53 -> V_120 [ 0 ] ) ;
V_64 = F_14 ( V_85 ) ;
V_64 -> V_66 = V_67 ;
V_6 = F_36 () ;
V_97 = F_1 ( V_85 , & V_53 -> V_70 , V_6 ) ;
if ( V_97 )
goto V_121;
V_118 = V_53 -> V_70 . V_12 ;
V_119 = F_37 ( V_122 | V_123 ) ;
V_90 = F_3 ( V_119 ) ;
V_115 = F_11 ( V_89 ) ;
if ( V_115 )
V_117 = V_124 ;
else
V_117 = V_125 ;
F_38 ( V_85 , V_89 ,
V_90 , V_117 ) ;
V_97 = F_20 ( V_85 , V_89 , V_90 ,
V_53 , V_6 ) ;
if ( V_97 < 0 ) {
F_29 ( V_126 L_13 ,
V_97 ) ;
goto V_127;
}
V_118 -= V_97 ;
V_97 = F_25 ( V_85 , V_89 , V_90 ,
V_53 , V_6 ) ;
if ( V_97 < 0 ) {
F_29 ( V_126 L_14 ,
V_97 ) ;
goto V_127;
}
V_118 -= V_97 ;
V_97 = F_27 ( V_85 , V_53 , V_119 , V_90 , V_64 , V_6 ,
V_118 ) ;
F_39 ( V_6 ) ;
F_5 ( L_15 , V_97 ) ;
return V_97 ;
V_127:
F_40 ( V_119 ) ;
V_121:
F_39 ( V_6 ) ;
F_19 ( V_64 , 0 ) ;
return V_97 ;
}
