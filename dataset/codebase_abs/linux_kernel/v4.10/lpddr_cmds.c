struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
struct V_7 * V_8 ;
struct V_9 * V_10 ;
struct V_1 * V_11 ;
int V_12 ;
int V_13 , V_14 ;
V_11 = F_2 ( sizeof( * V_11 ) , V_15 ) ;
if ( ! V_11 )
return NULL ;
V_11 -> V_16 = V_3 ;
V_11 -> type = V_17 ;
V_11 -> V_18 = V_19 ;
V_11 -> type = V_17 ;
V_11 -> V_20 = V_21 ;
V_11 -> V_20 &= ~ V_22 ;
V_11 -> V_23 = V_24 ;
V_11 -> V_25 = V_26 ;
V_11 -> V_27 = V_28 ;
V_11 -> V_29 = V_30 ;
V_11 -> V_31 = V_32 ;
if ( F_3 ( V_3 ) ) {
V_11 -> V_33 = V_34 ;
V_11 -> V_35 = V_36 ;
}
V_11 -> V_37 = 1 << V_5 -> V_38 -> V_39 ;
V_11 -> V_40 = 1 << V_5 -> V_38 -> V_41 ;
V_11 -> V_42 = 1 << V_5 -> V_38 -> V_43 ;
V_8 = F_4 ( sizeof( struct V_7 ) * V_5 -> V_12 ,
V_15 ) ;
if ( ! V_8 ) {
F_5 ( V_5 ) ;
F_5 ( V_11 ) ;
return NULL ;
}
V_10 = & V_5 -> V_44 [ 0 ] ;
V_12 = V_5 -> V_12 / V_5 -> V_38 -> V_45 ;
for ( V_13 = 0 ; V_13 < V_12 ; V_13 ++ ) {
V_8 [ V_13 ] . V_46 = V_8 [ V_13 ] . V_47 = NULL ;
F_6 ( & V_8 [ V_13 ] . V_48 ) ;
for ( V_14 = 0 ; V_14 < V_5 -> V_38 -> V_45 ; V_14 ++ ) {
* V_10 = V_5 -> V_44 [ V_13 ] ;
V_10 -> V_49 += V_14 << V_5 -> V_50 ;
V_10 -> V_51 = V_10 -> V_52 = V_53 ;
V_10 -> V_16 = & V_8 [ V_13 ] ;
F_7 ( & V_10 -> V_54 ) ;
F_6 ( & V_10 -> V_55 ) ;
V_10 ++ ;
}
}
return V_11 ;
}
static int F_8 ( struct V_2 * V_3 , struct V_9 * V_10 ,
unsigned int V_56 )
{
unsigned int V_57 , V_58 , V_59 ;
unsigned int V_60 ;
T_1 V_61 = V_10 -> V_52 ;
int V_62 = 0 ;
V_57 = V_56 * 8 ;
if ( ! V_57 )
V_57 = 500000 ;
V_58 = V_57 ;
V_59 = V_56 / 2 ;
for (; ; ) {
V_60 = F_9 ( F_10 ( V_3 , V_3 -> V_63 + V_64 ) ) ;
if ( V_60 & V_65 )
break;
if ( ! V_57 ) {
F_11 ( V_66 L_1 ,
V_3 -> V_67 , V_61 ) ;
V_62 = - V_68 ;
break;
}
F_12 ( & V_10 -> V_55 ) ;
if ( V_59 >= 1000000 / V_69 ) {
F_13 ( V_59 / 1000 ) ;
V_57 -= V_59 ;
V_59 = 1000000 / V_69 ;
} else {
F_14 ( 1 ) ;
F_15 () ;
V_57 -- ;
}
F_16 ( & V_10 -> V_55 ) ;
while ( V_10 -> V_52 != V_61 ) {
F_17 ( V_70 , V_71 ) ;
F_18 ( V_72 ) ;
F_19 ( & V_10 -> V_54 , & V_70 ) ;
F_12 ( & V_10 -> V_55 ) ;
F_20 () ;
F_21 ( & V_10 -> V_54 , & V_70 ) ;
F_16 ( & V_10 -> V_55 ) ;
}
if ( V_10 -> V_73 || V_10 -> V_74 ) {
V_57 = V_58 ;
V_10 -> V_73 = V_10 -> V_74 = 0 ;
}
}
if ( V_60 & V_75 ) {
F_22 ( V_3 , F_23 ( ~ ( V_75 ) ) , V_3 -> V_63 + V_64 ) ;
F_11 ( V_76 L_2 ,
V_3 -> V_67 , V_60 ) ;
F_24 ( V_60 ) ;
V_62 = - V_77 ;
}
V_10 -> V_52 = V_53 ;
return V_62 ;
}
static int F_25 ( struct V_2 * V_3 , struct V_9 * V_10 , int V_78 )
{
int V_62 ;
F_17 ( V_70 , V_71 ) ;
V_79:
if ( V_10 -> V_16 && ( V_78 == V_80 || V_78 == V_81 )
&& V_10 -> V_52 != V_82 ) {
struct V_7 * V_8 = V_10 -> V_16 ;
struct V_9 * V_83 ;
F_16 ( & V_8 -> V_48 ) ;
V_83 = V_8 -> V_46 ;
if ( V_83 && V_83 != V_10 ) {
V_62 = F_26 ( & V_83 -> V_55 ) ;
F_12 ( & V_8 -> V_48 ) ;
if ( ! V_62 )
goto V_79;
F_12 ( & V_10 -> V_55 ) ;
V_62 = F_27 ( V_3 , V_83 , V_78 ) ;
F_16 ( & V_10 -> V_55 ) ;
if ( V_62 == - V_84 ) {
F_12 ( & V_83 -> V_55 ) ;
goto V_79;
}
if ( V_62 ) {
F_12 ( & V_83 -> V_55 ) ;
return V_62 ;
}
F_16 ( & V_8 -> V_48 ) ;
if ( V_10 -> V_52 == V_82 ) {
F_28 ( V_3 , V_83 ) ;
F_12 ( & V_83 -> V_55 ) ;
goto V_79;
}
F_12 ( & V_83 -> V_55 ) ;
}
if ( V_78 == V_81 && V_8 -> V_47
&& V_8 -> V_47 -> V_51 == V_81 ) {
F_12 ( & V_8 -> V_48 ) ;
F_18 ( V_72 ) ;
F_19 ( & V_10 -> V_54 , & V_70 ) ;
F_12 ( & V_10 -> V_55 ) ;
F_20 () ;
F_21 ( & V_10 -> V_54 , & V_70 ) ;
F_16 ( & V_10 -> V_55 ) ;
goto V_79;
}
V_8 -> V_46 = V_10 ;
if ( V_78 == V_81 )
V_8 -> V_47 = V_10 ;
F_12 ( & V_8 -> V_48 ) ;
}
V_62 = F_27 ( V_3 , V_10 , V_78 ) ;
if ( V_62 == - V_84 )
goto V_79;
return V_62 ;
}
static int F_27 ( struct V_2 * V_3 , struct V_9 * V_10 , int V_78 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
int V_62 = 0 ;
F_17 ( V_70 , V_71 ) ;
if ( V_82 == V_78 && V_53 != V_10 -> V_51 )
goto V_85;
switch ( V_10 -> V_52 ) {
case V_53 :
case V_86 :
return 0 ;
case V_81 :
if ( ! V_5 -> V_38 -> V_87 ||
! ( V_78 == V_53 || V_78 == V_88 ) )
goto V_85;
F_22 ( V_3 , F_23 ( V_89 ) ,
V_3 -> V_63 + V_90 ) ;
V_10 -> V_51 = V_81 ;
V_10 -> V_52 = V_91 ;
V_62 = F_8 ( V_3 , V_10 , 0 ) ;
if ( V_62 ) {
F_28 ( V_3 , V_10 ) ;
F_11 ( V_66 L_3
L_4 , V_3 -> V_67 ) ;
return - V_77 ;
}
V_10 -> V_73 = 1 ;
V_10 -> V_52 = V_53 ;
return 0 ;
case V_88 :
if ( V_78 == V_53 && V_10 -> V_51 == V_53 )
return 0 ;
default:
V_85:
F_18 ( V_72 ) ;
F_19 ( & V_10 -> V_54 , & V_70 ) ;
F_12 ( & V_10 -> V_55 ) ;
F_20 () ;
F_21 ( & V_10 -> V_54 , & V_70 ) ;
F_16 ( & V_10 -> V_55 ) ;
return - V_84 ;
}
}
static void F_28 ( struct V_2 * V_3 , struct V_9 * V_10 )
{
if ( V_10 -> V_16 ) {
struct V_7 * V_8 = V_10 -> V_16 ;
F_16 ( & V_8 -> V_48 ) ;
if ( V_8 -> V_46 == V_10 && V_10 -> V_51 == V_53 ) {
V_8 -> V_46 = V_8 -> V_47 ;
if ( V_8 -> V_46 && V_8 -> V_46 != V_10 ) {
struct V_9 * V_92 = V_8 -> V_46 ;
F_16 ( & V_92 -> V_55 ) ;
F_12 ( & V_8 -> V_48 ) ;
F_12 ( & V_10 -> V_55 ) ;
F_28 ( V_3 , V_92 ) ;
F_16 ( & V_10 -> V_55 ) ;
F_12 ( & V_92 -> V_55 ) ;
F_29 ( & V_10 -> V_54 ) ;
return;
}
V_8 -> V_47 = NULL ;
V_8 -> V_46 = NULL ;
} else if ( V_8 -> V_47 == V_10 && V_8 -> V_46 != V_10 ) {
F_12 ( & V_8 -> V_48 ) ;
F_29 ( & V_10 -> V_54 ) ;
return;
}
F_12 ( & V_8 -> V_48 ) ;
}
switch ( V_10 -> V_51 ) {
case V_81 :
F_22 ( V_3 , F_23 ( V_93 ) ,
V_3 -> V_63 + V_94 ) ;
F_22 ( V_3 , F_23 ( V_95 ) ,
V_3 -> V_63 + V_96 ) ;
V_10 -> V_51 = V_53 ;
V_10 -> V_52 = V_81 ;
break;
case V_53 :
break;
default:
F_11 ( V_66 L_5 ,
V_3 -> V_67 , V_10 -> V_51 ) ;
}
F_29 ( & V_10 -> V_54 ) ;
}
static int F_30 ( struct V_2 * V_3 , struct V_9 * V_10 ,
unsigned long V_97 , const struct V_98 * * V_99 ,
unsigned long * V_100 , int V_101 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
T_2 V_102 ;
int V_62 , V_103 , V_104 , V_105 ;
const struct V_98 * V_106 ;
unsigned long V_107 ;
unsigned long V_108 ;
V_103 = 1 << V_5 -> V_38 -> V_43 ;
F_16 ( & V_10 -> V_55 ) ;
V_62 = F_25 ( V_3 , V_10 , V_80 ) ;
if ( V_62 ) {
F_12 ( & V_10 -> V_55 ) ;
return V_62 ;
}
V_104 = ( - V_97 & ( F_31 ( V_3 ) - 1 ) ) ;
V_105 = ( V_101 - V_104 + F_31 ( V_3 ) - 1 ) / F_31 ( V_3 ) ;
if ( ! V_104 ) {
V_105 -- ;
} else {
V_104 = F_31 ( V_3 ) - V_104 ;
V_97 -= V_104 ;
V_102 = F_32 ( V_3 ) ;
}
V_108 = V_3 -> V_63 + F_9 ( F_10 ( V_3 ,
V_3 -> V_63 + V_109 ) ) ;
V_106 = * V_99 ;
V_107 = * V_100 ;
do {
int V_110 = F_31 ( V_3 ) - V_104 ;
if ( V_110 > V_106 -> V_111 - V_107 )
V_110 = V_106 -> V_111 - V_107 ;
if ( V_110 > V_101 )
V_110 = V_101 ;
if ( ! V_104 && ( V_101 < F_31 ( V_3 ) ) )
V_102 = F_32 ( V_3 ) ;
V_102 = F_33 ( V_3 , V_102 ,
V_106 -> V_112 + V_107 , V_104 , V_110 ) ;
V_101 -= V_110 ;
V_104 += V_110 ;
if ( ! V_101 || V_104 == F_31 ( V_3 ) ) {
F_22 ( V_3 , V_102 , V_108 ) ;
V_108 += F_31 ( V_3 ) ;
V_104 = 0 ;
}
V_107 += V_110 ;
if ( V_107 == V_106 -> V_111 ) {
V_106 ++ ;
V_107 = 0 ;
}
} while ( V_101 );
* V_99 = V_106 ;
* V_100 = V_107 ;
F_34 ( V_3 , V_113 , V_97 , V_103 , NULL ) ;
V_10 -> V_52 = V_80 ;
V_62 = F_8 ( V_3 , V_10 , ( 1 << V_5 -> V_38 -> V_114 ) ) ;
if ( V_62 ) {
F_11 ( V_76 L_6 ,
V_3 -> V_67 , V_62 , V_97 ) ;
goto V_115;
}
V_115: F_28 ( V_3 , V_10 ) ;
F_12 ( & V_10 -> V_55 ) ;
return V_62 ;
}
static int F_35 ( struct V_1 * V_11 , T_3 V_97 )
{
struct V_2 * V_3 = V_11 -> V_16 ;
struct V_4 * V_5 = V_3 -> V_6 ;
int V_116 = V_97 >> V_5 -> V_50 ;
struct V_9 * V_10 = & V_5 -> V_44 [ V_116 ] ;
int V_62 ;
F_16 ( & V_10 -> V_55 ) ;
V_62 = F_25 ( V_3 , V_10 , V_81 ) ;
if ( V_62 ) {
F_12 ( & V_10 -> V_55 ) ;
return V_62 ;
}
F_34 ( V_3 , V_117 , V_97 , 0 , NULL ) ;
V_10 -> V_52 = V_81 ;
V_62 = F_8 ( V_3 , V_10 , ( 1 << V_5 -> V_38 -> V_118 ) * 1000 ) ;
if ( V_62 ) {
F_11 ( V_76 L_7 ,
V_3 -> V_67 , V_62 , V_97 ) ;
goto V_115;
}
V_115: F_28 ( V_3 , V_10 ) ;
F_12 ( & V_10 -> V_55 ) ;
return V_62 ;
}
static int V_19 ( struct V_1 * V_11 , T_3 V_97 , T_4 V_101 ,
T_4 * V_119 , T_5 * V_120 )
{
struct V_2 * V_3 = V_11 -> V_16 ;
struct V_4 * V_5 = V_3 -> V_6 ;
int V_116 = V_97 >> V_5 -> V_50 ;
struct V_9 * V_10 = & V_5 -> V_44 [ V_116 ] ;
int V_62 = 0 ;
F_16 ( & V_10 -> V_55 ) ;
V_62 = F_25 ( V_3 , V_10 , V_53 ) ;
if ( V_62 ) {
F_12 ( & V_10 -> V_55 ) ;
return V_62 ;
}
F_36 ( V_3 , V_120 , V_97 , V_101 ) ;
* V_119 = V_101 ;
F_28 ( V_3 , V_10 ) ;
F_12 ( & V_10 -> V_55 ) ;
return V_62 ;
}
static int V_34 ( struct V_1 * V_11 , T_3 V_97 , T_4 V_101 ,
T_4 * V_119 , void * * V_121 , T_6 * V_122 )
{
struct V_2 * V_3 = V_11 -> V_16 ;
struct V_4 * V_5 = V_3 -> V_6 ;
int V_116 = V_97 >> V_5 -> V_50 ;
unsigned long V_123 , V_124 = 0 ;
struct V_9 * V_10 = & V_5 -> V_44 [ V_116 ] ;
int V_62 = 0 ;
if ( ! V_3 -> V_125 )
return - V_126 ;
V_123 = V_97 - ( V_116 << V_5 -> V_50 ) ;
* V_121 = ( void * ) V_3 -> V_125 + V_10 -> V_49 + V_123 ;
while ( V_101 ) {
unsigned long V_127 ;
if ( V_116 >= V_5 -> V_12 )
break;
if ( ! V_124 )
V_124 = V_10 -> V_49 ;
else if ( V_10 -> V_49 != V_124 )
break;
if ( ( V_101 + V_123 - 1 ) >> V_5 -> V_50 )
V_127 = ( 1 << V_5 -> V_50 ) - V_123 ;
else
V_127 = V_101 ;
F_16 ( & V_10 -> V_55 ) ;
V_62 = F_25 ( V_3 , V_10 , V_88 ) ;
F_12 ( & V_10 -> V_55 ) ;
if ( V_62 )
break;
V_10 -> V_52 = V_88 ;
V_10 -> V_128 ++ ;
* V_119 += V_127 ;
V_101 -= V_127 ;
V_123 = 0 ;
V_124 += 1 << V_5 -> V_50 ;
V_116 ++ ;
V_10 = & V_5 -> V_44 [ V_116 ] ;
}
return 0 ;
}
static int V_36 ( struct V_1 * V_11 , T_3 V_97 , T_4 V_101 )
{
struct V_2 * V_3 = V_11 -> V_16 ;
struct V_4 * V_5 = V_3 -> V_6 ;
int V_116 = V_97 >> V_5 -> V_50 , V_129 = 0 ;
unsigned long V_123 ;
V_123 = V_97 - ( V_116 << V_5 -> V_50 ) ;
while ( V_101 ) {
unsigned long V_127 ;
struct V_9 * V_10 ;
V_10 = & V_5 -> V_44 [ V_116 ] ;
if ( V_116 >= V_5 -> V_12 )
break;
if ( ( V_101 + V_123 - 1 ) >> V_5 -> V_50 )
V_127 = ( 1 << V_5 -> V_50 ) - V_123 ;
else
V_127 = V_101 ;
F_16 ( & V_10 -> V_55 ) ;
if ( V_10 -> V_52 == V_88 ) {
V_10 -> V_128 -- ;
if ( V_10 -> V_128 == 0 )
V_10 -> V_52 = V_53 ;
} else {
F_11 ( V_76 L_8
L_9 , V_3 -> V_67 ) ;
V_129 = - V_126 ;
}
F_28 ( V_3 , V_10 ) ;
F_12 ( & V_10 -> V_55 ) ;
V_101 -= V_127 ;
V_123 = 0 ;
V_116 ++ ;
}
return V_129 ;
}
static int V_26 ( struct V_1 * V_11 , T_3 V_130 , T_4 V_101 ,
T_4 * V_119 , const T_5 * V_120 )
{
struct V_98 V_106 ;
V_106 . V_112 = ( void * ) V_120 ;
V_106 . V_111 = V_101 ;
return V_28 ( V_11 , & V_106 , 1 , V_130 , V_119 ) ;
}
static int V_28 ( struct V_1 * V_11 , const struct V_98 * V_131 ,
unsigned long V_132 , T_3 V_130 , T_4 * V_119 )
{
struct V_2 * V_3 = V_11 -> V_16 ;
struct V_4 * V_5 = V_3 -> V_6 ;
int V_62 = 0 ;
int V_116 ;
unsigned long V_123 , V_107 , V_13 ;
int V_103 = 1 << V_5 -> V_38 -> V_43 ;
T_4 V_101 = 0 ;
for ( V_13 = 0 ; V_13 < V_132 ; V_13 ++ )
V_101 += V_131 [ V_13 ] . V_111 ;
if ( ! V_101 )
return 0 ;
V_116 = V_130 >> V_5 -> V_50 ;
V_123 = V_130 ;
V_107 = 0 ;
do {
int V_37 = V_103 - ( V_123 & ( V_103 - 1 ) ) ;
if ( V_37 > V_101 )
V_37 = V_101 ;
V_62 = F_30 ( V_3 , & V_5 -> V_44 [ V_116 ] ,
V_123 , & V_131 , & V_107 , V_37 ) ;
if ( V_62 )
return V_62 ;
V_123 += V_37 ;
( * V_119 ) += V_37 ;
V_101 -= V_37 ;
F_15 () ;
} while ( V_101 );
return 0 ;
}
static int V_24 ( struct V_1 * V_11 , struct V_133 * V_134 )
{
unsigned long V_123 , V_101 ;
int V_62 ;
struct V_2 * V_3 = V_11 -> V_16 ;
struct V_4 * V_5 = V_3 -> V_6 ;
int V_37 = 1 << V_5 -> V_38 -> V_41 ;
V_123 = V_134 -> V_135 ;
V_101 = V_134 -> V_101 ;
while ( V_101 > 0 ) {
V_62 = F_35 ( V_11 , V_123 ) ;
if ( V_62 )
return V_62 ;
V_123 += V_37 ;
V_101 -= V_37 ;
}
V_134 -> V_52 = V_136 ;
F_37 ( V_134 ) ;
return 0 ;
}
static int F_38 ( struct V_1 * V_11 , T_3 V_97 , T_7 V_101 , int V_137 )
{
int V_62 = 0 ;
struct V_2 * V_3 = V_11 -> V_16 ;
struct V_4 * V_5 = V_3 -> V_6 ;
int V_116 = V_97 >> V_5 -> V_50 ;
struct V_9 * V_10 = & V_5 -> V_44 [ V_116 ] ;
F_16 ( & V_10 -> V_55 ) ;
V_62 = F_25 ( V_3 , V_10 , V_138 ) ;
if ( V_62 ) {
F_12 ( & V_10 -> V_55 ) ;
return V_62 ;
}
if ( V_137 == V_139 ) {
F_34 ( V_3 , V_140 , V_97 , V_97 + V_101 , NULL ) ;
V_10 -> V_52 = V_138 ;
} else if ( V_137 == V_141 ) {
F_34 ( V_3 , V_142 , V_97 , V_97 + V_101 , NULL ) ;
V_10 -> V_52 = V_143 ;
} else
F_39 () ;
V_62 = F_8 ( V_3 , V_10 , 1 ) ;
if ( V_62 ) {
F_11 ( V_66 L_10 ,
V_3 -> V_67 , V_62 ) ;
goto V_115;
}
V_115: F_28 ( V_3 , V_10 ) ;
F_12 ( & V_10 -> V_55 ) ;
return V_62 ;
}
static int V_30 ( struct V_1 * V_11 , T_3 V_123 , T_8 V_101 )
{
return F_38 ( V_11 , V_123 , V_101 , V_139 ) ;
}
static int V_32 ( struct V_1 * V_11 , T_3 V_123 , T_8 V_101 )
{
return F_38 ( V_11 , V_123 , V_101 , V_141 ) ;
}
