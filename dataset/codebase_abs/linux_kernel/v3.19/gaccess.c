int F_1 ( struct V_1 * V_2 )
{
union V_3 * V_4 = & V_2 -> V_5 -> V_6 . V_7 -> V_3 ;
if ( V_2 -> V_6 . V_8 -> V_9 & 1 )
return V_4 -> V_10 != 0 ;
return V_2 -> V_5 -> V_6 . V_11 != 0 ;
}
static void F_2 ( struct V_1 * V_2 )
{
union V_3 V_12 , V_13 , * V_4 ;
F_3 ( & V_2 -> V_5 -> V_6 . V_14 ) ;
V_2 -> V_5 -> V_6 . V_11 ++ ;
if ( V_2 -> V_5 -> V_6 . V_11 > 1 )
goto V_15;
V_4 = & V_2 -> V_5 -> V_6 . V_7 -> V_3 ;
do {
V_12 = F_4 ( * V_4 ) ;
while ( V_12 . V_16 ) {
F_5 () ;
V_12 = F_4 ( * V_4 ) ;
}
V_13 = V_12 ;
V_13 . V_16 = 1 ;
} while ( F_6 ( & V_4 -> V_17 , V_12 . V_17 , V_13 . V_17 ) != V_12 . V_17 );
V_15:
F_7 ( & V_2 -> V_5 -> V_6 . V_14 ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
union V_3 V_12 , V_13 , * V_4 ;
F_3 ( & V_2 -> V_5 -> V_6 . V_14 ) ;
V_2 -> V_5 -> V_6 . V_11 -- ;
if ( V_2 -> V_5 -> V_6 . V_11 )
goto V_15;
V_4 = & V_2 -> V_5 -> V_6 . V_7 -> V_3 ;
do {
V_12 = F_4 ( * V_4 ) ;
V_13 = V_12 ;
V_13 . V_16 = 0 ;
} while ( F_6 ( & V_4 -> V_17 , V_12 . V_17 , V_13 . V_17 ) != V_12 . V_17 );
F_9 ( & V_2 -> V_5 -> V_6 . V_18 ) ;
V_15:
F_7 ( & V_2 -> V_5 -> V_6 . V_14 ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
union V_3 V_12 , V_13 , * V_4 ;
V_4 = & V_2 -> V_5 -> V_6 . V_7 -> V_3 ;
do {
V_12 = F_4 ( * V_4 ) ;
while ( V_12 . V_19 ) {
F_5 () ;
V_12 = F_4 ( * V_4 ) ;
}
V_13 = V_12 ;
V_13 . V_16 = 1 ;
V_13 . V_10 ++ ;
} while ( F_6 ( & V_4 -> V_17 , V_12 . V_17 , V_13 . V_17 ) != V_12 . V_17 );
}
static void F_11 ( struct V_1 * V_2 )
{
union V_3 V_12 , V_13 , * V_4 ;
V_4 = & V_2 -> V_5 -> V_6 . V_7 -> V_3 ;
do {
V_12 = F_4 ( * V_4 ) ;
V_13 = V_12 ;
V_13 . V_10 -- ;
if ( ! V_13 . V_10 )
V_13 . V_16 = 0 ;
} while ( F_6 ( & V_4 -> V_17 , V_12 . V_17 , V_13 . V_17 ) != V_12 . V_17 );
if ( ! V_13 . V_10 )
F_9 ( & V_2 -> V_5 -> V_6 . V_18 ) ;
}
void F_12 ( struct V_1 * V_2 )
{
if ( V_2 -> V_6 . V_8 -> V_9 & 1 )
F_10 ( V_2 ) ;
else
F_2 ( V_2 ) ;
}
void F_13 ( struct V_1 * V_2 )
{
if ( V_2 -> V_6 . V_8 -> V_9 & 1 )
F_11 ( V_2 ) ;
else
F_8 ( V_2 ) ;
}
static unsigned long F_14 ( struct V_1 * V_2 )
{
switch ( F_15 ( V_2 -> V_6 . V_8 -> V_20 ) . V_21 ) {
case V_22 :
return V_2 -> V_6 . V_8 -> V_23 [ 1 ] ;
case V_24 :
return V_2 -> V_6 . V_8 -> V_23 [ 7 ] ;
case V_25 :
return V_2 -> V_6 . V_8 -> V_23 [ 13 ] ;
}
return 0 ;
}
static int F_16 ( struct V_5 * V_5 , unsigned long V_26 , unsigned long * V_17 )
{
return F_17 ( V_5 , V_26 , V_17 , sizeof( * V_17 ) ) ;
}
static unsigned long F_18 ( struct V_1 * V_2 , unsigned long V_27 ,
unsigned long * V_26 , int V_28 )
{
union V_29 V_30 = { . V_31 = V_27 } ;
union V_32 V_33 = { . V_31 = V_27 } ;
union V_34 V_35 ;
int V_36 = 0 ;
union V_37 V_37 ;
unsigned long V_38 ;
int V_39 , V_40 ;
union V_41 V_41 ;
V_37 . V_17 = V_2 -> V_6 . V_8 -> V_23 [ 0 ] ;
V_39 = V_37 . V_42 && F_19 ( 8 ) ;
V_40 = V_39 && F_19 ( 78 ) ;
V_41 . V_17 = F_14 ( V_2 ) ;
if ( V_41 . V_43 )
goto V_44;
V_38 = V_41 . V_45 * 4096 ;
switch ( V_41 . V_46 ) {
case V_47 :
if ( V_30 . V_48 > V_41 . V_49 )
return V_50 ;
V_38 += V_30 . V_51 * 8 ;
break;
case V_52 :
if ( V_30 . V_51 )
return V_53 ;
if ( V_30 . V_54 > V_41 . V_49 )
return V_55 ;
V_38 += V_30 . V_56 * 8 ;
break;
case V_57 :
if ( V_30 . V_51 || V_30 . V_56 )
return V_53 ;
if ( V_30 . V_58 > V_41 . V_49 )
return V_59 ;
V_38 += V_30 . V_60 * 8 ;
break;
case V_61 :
if ( V_30 . V_51 || V_30 . V_56 || V_30 . V_60 )
return V_53 ;
if ( V_30 . V_62 > V_41 . V_49 )
return V_63 ;
V_38 += V_30 . V_64 * 8 ;
break;
}
switch ( V_41 . V_46 ) {
case V_47 : {
union V_65 V_66 ;
if ( F_20 ( V_2 -> V_5 , V_38 ) )
return V_67 ;
if ( F_16 ( V_2 -> V_5 , V_38 , & V_66 . V_17 ) )
return - V_68 ;
if ( V_66 . V_69 )
return V_50 ;
if ( V_66 . V_70 != V_71 )
return V_72 ;
if ( V_30 . V_54 < V_66 . V_73 || V_30 . V_54 > V_66 . V_49 )
return V_55 ;
if ( V_39 )
V_36 |= V_66 . V_74 ;
V_38 = V_66 . V_75 * 4096 + V_30 . V_56 * 8 ;
}
case V_52 : {
union V_76 V_77 ;
if ( F_20 ( V_2 -> V_5 , V_38 ) )
return V_67 ;
if ( F_16 ( V_2 -> V_5 , V_38 , & V_77 . V_17 ) )
return - V_68 ;
if ( V_77 . V_69 )
return V_55 ;
if ( V_77 . V_70 != V_78 )
return V_72 ;
if ( V_30 . V_58 < V_77 . V_73 || V_30 . V_58 > V_77 . V_49 )
return V_59 ;
if ( V_39 )
V_36 |= V_77 . V_74 ;
V_38 = V_77 . V_75 * 4096 + V_30 . V_60 * 8 ;
}
case V_57 : {
union V_79 V_80 ;
if ( F_20 ( V_2 -> V_5 , V_38 ) )
return V_67 ;
if ( F_16 ( V_2 -> V_5 , V_38 , & V_80 . V_17 ) )
return - V_68 ;
if ( V_80 . V_69 )
return V_59 ;
if ( V_80 . V_70 != V_81 )
return V_72 ;
if ( V_80 . V_82 && V_41 . V_74 && V_40 )
return V_72 ;
if ( V_80 . V_83 && V_40 ) {
V_36 |= V_80 . V_84 . V_74 ;
V_33 . V_85 = V_80 . V_84 . V_85 ;
goto V_86;
}
if ( V_30 . V_62 < V_80 . V_87 . V_73 )
return V_63 ;
if ( V_30 . V_62 > V_80 . V_87 . V_49 )
return V_63 ;
if ( V_39 )
V_36 |= V_80 . V_87 . V_74 ;
V_38 = V_80 . V_87 . V_88 * 4096 + V_30 . V_64 * 8 ;
}
case V_61 : {
union V_89 V_90 ;
if ( F_20 ( V_2 -> V_5 , V_38 ) )
return V_67 ;
if ( F_16 ( V_2 -> V_5 , V_38 , & V_90 . V_17 ) )
return - V_68 ;
if ( V_90 . V_69 )
return V_63 ;
if ( V_90 . V_70 != V_91 )
return V_72 ;
if ( V_90 . V_92 && V_41 . V_74 )
return V_72 ;
if ( V_90 . V_83 && V_39 ) {
V_36 |= V_90 . V_84 . V_74 ;
V_33 . V_93 = V_90 . V_84 . V_93 ;
goto V_86;
}
V_36 |= V_90 . V_87 . V_74 ;
V_38 = V_90 . V_87 . V_94 * 2048 + V_30 . V_95 * 8 ;
}
}
if ( F_20 ( V_2 -> V_5 , V_38 ) )
return V_67 ;
if ( F_16 ( V_2 -> V_5 , V_38 , & V_35 . V_17 ) )
return - V_68 ;
if ( V_35 . V_69 )
return V_96 ;
if ( V_35 . V_97 )
return V_72 ;
if ( V_35 . V_98 && ! V_39 )
return V_72 ;
V_36 |= V_35 . V_74 ;
V_33 . V_99 = V_35 . V_99 ;
V_44:
V_33 . V_31 = F_21 ( V_2 , V_33 . V_31 ) ;
V_86:
if ( V_28 && V_36 )
return V_100 ;
if ( F_20 ( V_2 -> V_5 , V_33 . V_31 ) )
return V_67 ;
* V_26 = V_33 . V_31 ;
return 0 ;
}
static inline int F_22 ( unsigned long V_101 )
{
return ( V_101 & ~ 0x11fful ) == 0 ;
}
static int F_23 ( struct V_1 * V_2 )
{
union V_37 V_37 = { . V_17 = V_2 -> V_6 . V_8 -> V_23 [ 0 ] } ;
T_1 * V_102 = & V_2 -> V_6 . V_8 -> V_20 ;
union V_41 V_41 ;
if ( ! V_37 . V_103 )
return 0 ;
V_41 . V_17 = F_14 ( V_2 ) ;
if ( F_15 ( * V_102 ) . V_104 && V_41 . V_74 )
return 0 ;
return 1 ;
}
static int F_24 ( struct V_1 * V_2 , unsigned long V_101 ,
unsigned long * V_105 , unsigned long V_106 ,
int V_28 )
{
struct V_107 * V_108 = & V_2 -> V_6 . V_108 ;
T_1 * V_102 = & V_2 -> V_6 . V_8 -> V_20 ;
struct V_109 * V_110 ;
int V_111 , V_112 ;
memset ( V_108 , 0 , sizeof( * V_108 ) ) ;
V_110 = (struct V_109 * ) & V_108 -> V_113 ;
V_110 -> V_114 = V_28 ? V_115 : V_116 ;
V_110 -> V_21 = F_15 ( * V_102 ) . V_21 ;
V_111 = F_23 ( V_2 ) ;
while ( V_106 ) {
V_101 = F_25 ( V_2 , V_101 ) ;
V_110 -> V_31 = V_101 >> V_117 ;
if ( V_28 && V_111 && F_22 ( V_101 ) ) {
V_108 -> V_118 = V_100 ;
return V_108 -> V_118 ;
}
V_101 &= V_119 ;
if ( F_15 ( * V_102 ) . V_104 ) {
V_112 = F_18 ( V_2 , V_101 , V_105 , V_28 ) ;
if ( V_112 < 0 )
return V_112 ;
if ( V_112 == V_100 )
V_110 -> V_120 = 1 ;
if ( V_112 )
V_108 -> V_118 = V_112 ;
} else {
* V_105 = F_21 ( V_2 , V_101 ) ;
if ( F_20 ( V_2 -> V_5 , * V_105 ) )
V_108 -> V_118 = V_67 ;
}
if ( V_108 -> V_118 )
return V_108 -> V_118 ;
V_101 += V_121 ;
V_105 ++ ;
V_106 -- ;
}
return 0 ;
}
int F_26 ( struct V_1 * V_2 , unsigned long V_101 , void * V_122 ,
unsigned long V_123 , int V_28 )
{
T_1 * V_102 = & V_2 -> V_6 . V_8 -> V_20 ;
unsigned long V_124 , V_106 , V_26 , V_125 ;
unsigned long V_126 [ 2 ] ;
unsigned long * V_105 ;
int V_127 ;
union V_41 V_41 ;
int V_112 ;
if ( ! V_123 )
return 0 ;
if ( F_15 ( * V_102 ) . V_104 && F_15 ( * V_102 ) . V_21 == V_128 )
return - V_129 ;
V_106 = ( ( ( V_101 & ~ V_119 ) + V_123 - 1 ) >> V_117 ) + 1 ;
V_105 = V_126 ;
if ( V_106 > F_27 ( V_126 ) )
V_105 = F_28 ( V_106 * sizeof( unsigned long ) ) ;
if ( ! V_105 )
return - V_130 ;
V_41 . V_17 = F_14 ( V_2 ) ;
V_127 = F_15 ( * V_102 ) . V_104 && ! V_41 . V_43 ;
if ( V_127 )
F_12 ( V_2 ) ;
V_112 = F_24 ( V_2 , V_101 , V_105 , V_106 , V_28 ) ;
for ( V_125 = 0 ; V_125 < V_106 && ! V_112 ; V_125 ++ ) {
V_26 = * ( V_105 + V_125 ) + ( V_101 & ~ V_119 ) ;
V_124 = F_29 ( V_121 - ( V_26 & ~ V_119 ) , V_123 ) ;
if ( V_28 )
V_112 = F_30 ( V_2 -> V_5 , V_26 , V_122 , V_124 ) ;
else
V_112 = F_17 ( V_2 -> V_5 , V_26 , V_122 , V_124 ) ;
V_123 -= V_124 ;
V_101 += V_124 ;
V_122 += V_124 ;
}
if ( V_127 )
F_13 ( V_2 ) ;
if ( V_106 > F_27 ( V_126 ) )
F_31 ( V_105 ) ;
return V_112 ;
}
int F_32 ( struct V_1 * V_2 , unsigned long V_131 ,
void * V_122 , unsigned long V_123 , int V_28 )
{
unsigned long V_124 , V_26 ;
int V_112 = 0 ;
while ( V_123 && ! V_112 ) {
V_26 = F_21 ( V_2 , V_131 ) ;
V_124 = F_29 ( V_121 - ( V_26 & ~ V_119 ) , V_123 ) ;
if ( V_28 )
V_112 = F_33 ( V_2 , V_26 , V_122 , V_124 ) ;
else
V_112 = F_34 ( V_2 , V_26 , V_122 , V_124 ) ;
V_123 -= V_124 ;
V_131 += V_124 ;
V_122 += V_124 ;
}
return V_112 ;
}
int F_35 ( struct V_1 * V_2 , unsigned long V_27 ,
unsigned long * V_26 , int V_28 )
{
struct V_107 * V_108 = & V_2 -> V_6 . V_108 ;
T_1 * V_102 = & V_2 -> V_6 . V_8 -> V_20 ;
struct V_109 * V_132 ;
union V_41 V_41 ;
int V_112 ;
if ( F_15 ( * V_102 ) . V_104 && F_15 ( * V_102 ) . V_21 == V_128 )
return - V_129 ;
V_27 = F_25 ( V_2 , V_27 ) ;
memset ( V_108 , 0 , sizeof( * V_108 ) ) ;
V_132 = (struct V_109 * ) & V_108 -> V_113 ;
V_132 -> V_21 = F_15 ( * V_102 ) . V_21 ;
V_132 -> V_114 = V_28 ? V_115 : V_116 ;
V_132 -> V_31 = V_27 >> V_117 ;
if ( F_22 ( V_27 ) && F_23 ( V_2 ) ) {
if ( V_28 ) {
V_112 = V_108 -> V_118 = V_100 ;
return V_112 ;
}
}
V_41 . V_17 = F_14 ( V_2 ) ;
if ( F_15 ( * V_102 ) . V_104 && ! V_41 . V_43 ) {
V_112 = F_18 ( V_2 , V_27 , V_26 , V_28 ) ;
if ( V_112 > 0 ) {
if ( V_112 == V_100 )
V_132 -> V_120 = 1 ;
V_108 -> V_118 = V_112 ;
}
} else {
V_112 = 0 ;
* V_26 = F_21 ( V_2 , V_27 ) ;
if ( F_20 ( V_2 -> V_5 , * V_26 ) )
V_112 = V_108 -> V_118 = V_67 ;
}
return V_112 ;
}
int F_36 ( struct V_1 * V_2 , unsigned long V_101 )
{
struct V_107 * V_108 = & V_2 -> V_6 . V_108 ;
T_1 * V_102 = & V_2 -> V_6 . V_8 -> V_20 ;
struct V_109 * V_110 ;
if ( ! F_22 ( V_101 ) || ! F_23 ( V_2 ) )
return 0 ;
memset ( V_108 , 0 , sizeof( * V_108 ) ) ;
V_110 = (struct V_109 * ) & V_108 -> V_113 ;
V_110 -> V_114 = V_115 ;
V_110 -> V_21 = F_15 ( * V_102 ) . V_21 ;
V_110 -> V_31 = V_101 >> V_117 ;
V_108 -> V_118 = V_100 ;
return V_108 -> V_118 ;
}
