int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 , T_1 V_6 ,
T_1 V_7 , T_1 V_8 ,
T_1 V_9 , T_1 V_10 , T_1 V_11 ,
T_2 V_12 , T_2 V_13 , T_3 V_14 )
{
int V_15 = 0 ;
struct V_16 * V_17 ;
struct V_18 V_19 ;
struct V_20 * V_21 ;
struct V_22 * V_23 ;
V_21 = F_2 () ;
if ( ! V_21 )
return - V_24 ;
V_19 . V_5 = V_5 ;
V_19 . V_10 = V_6 ;
V_19 . type = V_25 ;
V_21 -> V_26 = 1 ;
V_15 = F_3 ( V_2 , V_4 , V_21 , & V_19 ,
sizeof( * V_17 ) ) ;
if ( V_15 < 0 )
goto V_27;
F_4 ( V_15 ) ;
V_23 = V_21 -> V_28 [ 0 ] ;
V_17 = F_5 ( V_23 , V_21 -> V_29 [ 0 ] ,
struct V_16 ) ;
F_6 ( V_23 , V_17 , V_7 ) ;
F_7 ( V_23 , V_17 , V_8 ) ;
F_8 ( V_23 , V_17 , V_10 ) ;
F_9 ( V_23 , V_17 , V_9 ) ;
F_10 ( V_23 , V_17 , V_11 ) ;
F_11 ( V_23 , V_17 , V_2 -> V_30 ) ;
F_12 ( V_23 , V_17 , V_31 ) ;
F_13 ( V_23 , V_17 , V_12 ) ;
F_14 ( V_23 , V_17 , V_13 ) ;
F_15 ( V_23 , V_17 , V_14 ) ;
F_16 ( V_23 ) ;
V_27:
F_17 ( V_21 ) ;
return V_15 ;
}
static struct V_32 *
F_18 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_20 * V_21 ,
T_1 V_33 , int V_34 )
{
int V_15 ;
struct V_18 V_19 ;
struct V_18 V_35 ;
struct V_32 * V_17 ;
struct V_22 * V_23 ;
T_1 V_36 = 0 ;
T_3 V_37 = F_19 ( V_4 -> V_38 -> V_39 ) ;
int V_40 ;
V_19 . V_5 = V_41 ;
V_19 . V_10 = V_33 ;
V_19 . type = V_42 ;
V_15 = F_20 ( V_2 , V_4 , & V_19 , V_21 , 0 , V_34 ) ;
if ( V_15 < 0 )
goto V_43;
V_23 = V_21 -> V_28 [ 0 ] ;
if ( V_15 > 0 ) {
V_15 = 1 ;
if ( V_21 -> V_29 [ 0 ] == 0 )
goto V_43;
V_21 -> V_29 [ 0 ] -- ;
F_21 ( V_23 , & V_35 , V_21 -> V_29 [ 0 ] ) ;
if ( V_35 . type != V_42 )
goto V_43;
V_36 = ( V_33 - V_35 . V_10 ) >>
V_4 -> V_38 -> V_44 -> V_45 ;
V_40 = F_22 ( V_23 , V_21 -> V_29 [ 0 ] ) ;
V_40 /= V_37 ;
if ( V_36 == V_40 ) {
V_15 = - V_46 ;
goto V_43;
} else if ( V_36 > V_40 ) {
goto V_43;
}
}
V_17 = F_5 ( V_23 , V_21 -> V_29 [ 0 ] , struct V_32 ) ;
V_17 = (struct V_32 * ) ( ( unsigned char * ) V_17 +
V_36 * V_37 ) ;
return V_17 ;
V_43:
if ( V_15 > 0 )
V_15 = - V_47 ;
return F_23 ( V_15 ) ;
}
int F_24 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_20 * V_21 , T_1 V_5 ,
T_1 V_10 , int V_48 )
{
int V_15 ;
struct V_18 V_19 ;
int V_49 = V_48 < 0 ? - 1 : 0 ;
int V_34 = V_48 != 0 ;
V_19 . V_5 = V_5 ;
V_19 . V_10 = V_10 ;
V_19 . type = V_25 ;
V_15 = F_20 ( V_2 , V_4 , & V_19 , V_21 , V_49 , V_34 ) ;
return V_15 ;
}
static void F_25 ( struct V_50 * V_51 , int V_52 )
{
F_26 ( V_51 -> V_53 ) ;
}
static int F_27 ( struct V_3 * V_4 ,
struct V_54 * V_54 , struct V_51 * V_51 ,
T_1 V_55 , T_4 * V_56 , int V_57 )
{
struct V_58 * V_59 = V_51 -> V_60 ;
struct V_50 * V_61 = V_50 ( V_51 ) ;
struct V_32 * V_17 = NULL ;
struct V_62 * V_63 = & F_28 ( V_54 ) -> V_63 ;
struct V_20 * V_21 ;
T_2 * V_64 ;
T_1 V_10 = 0 ;
T_1 V_65 = 0 ;
T_1 V_66 = 0 ;
T_1 V_67 ;
T_1 V_68 ;
T_4 V_69 ;
int V_70 ;
int V_71 = 0 ;
int V_72 ;
T_3 V_37 = F_19 ( V_4 -> V_38 -> V_39 ) ;
V_21 = F_2 () ;
if ( ! V_21 )
return - V_24 ;
V_70 = V_51 -> V_73 . V_74 >> V_54 -> V_75 -> V_45 ;
if ( ! V_56 ) {
if ( V_70 * V_37 > V_76 ) {
V_61 -> V_53 = F_29 ( V_70 ,
V_37 , V_77 ) ;
if ( ! V_61 -> V_53 ) {
F_17 ( V_21 ) ;
return - V_24 ;
}
V_61 -> V_64 = V_61 -> V_53 ;
V_61 -> V_78 = F_25 ;
} else {
V_61 -> V_64 = V_61 -> V_79 ;
}
V_64 = V_61 -> V_64 ;
} else {
V_64 = ( T_2 * ) V_56 ;
}
if ( V_51 -> V_73 . V_74 > V_80 * 8 )
V_21 -> V_81 = V_82 ;
F_30 ( V_51 -> V_83 <= 0 ) ;
if ( F_31 ( V_54 ) ) {
V_21 -> V_84 = 1 ;
V_21 -> V_85 = 1 ;
}
V_67 = ( T_1 ) V_51 -> V_73 . V_86 << 9 ;
if ( V_57 )
V_10 = V_55 ;
V_68 = V_59 -> V_87 ;
while ( V_71 < V_51 -> V_83 ) {
if ( ! V_57 )
V_10 = F_32 ( V_59 -> V_88 ) + V_59 -> V_89 ;
V_72 = F_33 ( V_54 , V_10 , V_67 ,
( T_4 * ) V_64 , V_70 ) ;
if ( V_72 )
goto V_90;
if ( ! V_17 || V_67 < V_65 ||
V_67 >= V_66 ) {
struct V_18 V_35 ;
T_4 V_91 ;
if ( V_17 )
F_34 ( V_21 ) ;
V_17 = F_18 ( NULL , V_4 -> V_38 -> V_92 ,
V_21 , V_67 , 0 ) ;
if ( F_35 ( V_17 ) ) {
V_72 = 1 ;
memset ( V_64 , 0 , V_37 ) ;
if ( F_28 ( V_54 ) -> V_4 -> V_93 . V_5 ==
V_94 ) {
F_36 ( V_63 , V_10 ,
V_10 + V_4 -> V_95 - 1 ,
V_96 , V_77 ) ;
} else {
F_37 ( F_28 ( V_54 ) -> V_4 -> V_38 ,
L_1 ,
F_38 ( V_54 ) , V_10 ) ;
}
V_17 = NULL ;
F_34 ( V_21 ) ;
goto V_90;
}
F_21 ( V_21 -> V_28 [ 0 ] , & V_35 ,
V_21 -> V_29 [ 0 ] ) ;
V_65 = V_35 . V_10 ;
V_91 = F_22 ( V_21 -> V_28 [ 0 ] ,
V_21 -> V_29 [ 0 ] ) ;
V_66 = V_65 +
( V_91 / V_37 ) *
V_4 -> V_95 ;
V_17 = F_5 ( V_21 -> V_28 [ 0 ] , V_21 -> V_29 [ 0 ] ,
struct V_32 ) ;
}
V_69 = V_67 - V_65 ;
V_69 = V_69 / V_4 -> V_95 ;
V_69 = V_69 * V_37 ;
V_72 = F_39 ( int , V_70 , ( V_66 - V_67 ) >>
V_54 -> V_75 -> V_45 ) ;
F_40 ( V_21 -> V_28 [ 0 ] , V_64 ,
( ( unsigned long ) V_17 ) + V_69 ,
V_37 * V_72 ) ;
V_90:
V_64 += V_72 * V_37 ;
V_70 -= V_72 ;
while ( V_72 -- ) {
V_67 += V_4 -> V_95 ;
V_10 += V_4 -> V_95 ;
V_68 -= V_4 -> V_95 ;
if ( ! V_68 ) {
V_71 ++ ;
if ( V_71 >= V_51 -> V_83 ) {
F_41 ( V_72 ) ;
goto V_97;
}
V_59 ++ ;
V_68 = V_59 -> V_87 ;
}
}
}
V_97:
F_17 ( V_21 ) ;
return 0 ;
}
int F_42 ( struct V_3 * V_4 , struct V_54 * V_54 ,
struct V_51 * V_51 , T_4 * V_56 )
{
return F_27 ( V_4 , V_54 , V_51 , 0 , V_56 , 0 ) ;
}
int F_43 ( struct V_3 * V_4 , struct V_54 * V_54 ,
struct V_51 * V_51 , T_1 V_10 )
{
return F_27 ( V_4 , V_54 , V_51 , V_10 , NULL , 1 ) ;
}
int F_44 ( struct V_3 * V_4 , T_1 V_98 , T_1 V_99 ,
struct V_100 * V_101 , int V_102 )
{
struct V_18 V_103 ;
struct V_20 * V_21 ;
struct V_22 * V_23 ;
struct V_104 * V_105 ;
struct V_32 * V_17 ;
F_45 ( V_106 ) ;
unsigned long V_10 ;
int V_15 ;
T_5 V_107 ;
T_1 V_108 ;
T_3 V_37 = F_19 ( V_4 -> V_38 -> V_39 ) ;
ASSERT ( F_46 ( V_98 , V_4 -> V_95 ) &&
F_46 ( V_99 + 1 , V_4 -> V_95 ) ) ;
V_21 = F_2 () ;
if ( ! V_21 )
return - V_24 ;
if ( V_102 ) {
V_21 -> V_85 = 1 ;
V_21 -> V_81 = V_82 ;
V_21 -> V_84 = 1 ;
}
V_103 . V_5 = V_41 ;
V_103 . V_10 = V_98 ;
V_103 . type = V_42 ;
V_15 = F_20 ( NULL , V_4 , & V_103 , V_21 , 0 , 0 ) ;
if ( V_15 < 0 )
goto V_43;
if ( V_15 > 0 && V_21 -> V_29 [ 0 ] > 0 ) {
V_23 = V_21 -> V_28 [ 0 ] ;
F_21 ( V_23 , & V_103 , V_21 -> V_29 [ 0 ] - 1 ) ;
if ( V_103 . V_5 == V_41 &&
V_103 . type == V_42 ) {
V_10 = ( V_98 - V_103 . V_10 ) >>
V_4 -> V_38 -> V_44 -> V_45 ;
if ( V_10 * V_37 <
F_22 ( V_23 , V_21 -> V_29 [ 0 ] - 1 ) )
V_21 -> V_29 [ 0 ] -- ;
}
}
while ( V_98 <= V_99 ) {
V_23 = V_21 -> V_28 [ 0 ] ;
if ( V_21 -> V_29 [ 0 ] >= F_47 ( V_23 ) ) {
V_15 = F_48 ( V_4 , V_21 ) ;
if ( V_15 < 0 )
goto V_43;
if ( V_15 > 0 )
break;
V_23 = V_21 -> V_28 [ 0 ] ;
}
F_21 ( V_23 , & V_103 , V_21 -> V_29 [ 0 ] ) ;
if ( V_103 . V_5 != V_41 ||
V_103 . type != V_42 ||
V_103 . V_10 > V_99 )
break;
if ( V_103 . V_10 > V_98 )
V_98 = V_103 . V_10 ;
V_107 = F_22 ( V_23 , V_21 -> V_29 [ 0 ] ) ;
V_108 = V_103 . V_10 + ( V_107 / V_37 ) * V_4 -> V_95 ;
if ( V_108 <= V_98 ) {
V_21 -> V_29 [ 0 ] ++ ;
continue;
}
V_108 = F_49 ( V_108 , V_99 + 1 ) ;
V_17 = F_5 ( V_21 -> V_28 [ 0 ] , V_21 -> V_29 [ 0 ] ,
struct V_32 ) ;
while ( V_98 < V_108 ) {
V_107 = F_39 ( T_5 , V_108 - V_98 ,
F_50 ( V_4 ) ) ;
V_105 = F_51 ( F_52 ( V_4 , V_107 ) ,
V_77 ) ;
if ( ! V_105 ) {
V_15 = - V_24 ;
goto V_43;
}
V_105 -> V_33 = V_98 ;
V_105 -> V_109 = ( int ) V_107 ;
V_10 = ( V_98 - V_103 . V_10 ) >>
V_4 -> V_38 -> V_44 -> V_45 ;
V_10 *= V_37 ;
V_107 >>= V_4 -> V_38 -> V_44 -> V_45 ;
F_40 ( V_21 -> V_28 [ 0 ] ,
V_105 -> V_105 ,
( ( unsigned long ) V_17 ) + V_10 ,
V_37 * V_107 ) ;
V_98 += V_4 -> V_95 * V_107 ;
F_53 ( & V_105 -> V_101 , & V_106 ) ;
}
V_21 -> V_29 [ 0 ] ++ ;
}
V_15 = 0 ;
V_43:
while ( V_15 < 0 && ! F_54 ( & V_106 ) ) {
V_105 = F_55 ( V_106 . V_110 , struct V_104 , V_101 ) ;
F_56 ( & V_105 -> V_101 ) ;
F_26 ( V_105 ) ;
}
F_57 ( & V_106 , V_101 ) ;
F_17 ( V_21 ) ;
return V_15 ;
}
int F_58 ( struct V_3 * V_4 , struct V_54 * V_54 ,
struct V_51 * V_51 , T_1 V_111 , int V_112 )
{
struct V_104 * V_105 ;
struct V_113 * V_114 ;
char * V_115 ;
struct V_58 * V_59 = V_51 -> V_60 ;
int V_71 = 0 ;
int V_116 ;
int V_117 ;
int V_118 ;
unsigned long V_119 = 0 ;
unsigned long V_120 = 0 ;
T_1 V_10 ;
F_30 ( V_51 -> V_83 <= 0 ) ;
V_105 = F_51 ( F_52 ( V_4 , V_51 -> V_73 . V_74 ) ,
V_77 ) ;
if ( ! V_105 )
return - V_24 ;
V_105 -> V_109 = V_51 -> V_73 . V_74 ;
F_59 ( & V_105 -> V_101 ) ;
if ( V_112 )
V_10 = V_111 ;
else
V_10 = F_32 ( V_59 -> V_88 ) + V_59 -> V_89 ;
V_114 = F_60 ( V_54 , V_10 ) ;
F_4 ( ! V_114 ) ;
V_105 -> V_33 = ( T_1 ) V_51 -> V_73 . V_86 << 9 ;
V_116 = 0 ;
while ( V_71 < V_51 -> V_83 ) {
if ( ! V_112 )
V_10 = F_32 ( V_59 -> V_88 ) + V_59 -> V_89 ;
V_115 = F_61 ( V_59 -> V_88 ) ;
V_117 = F_62 ( V_4 -> V_38 ,
V_59 -> V_87 + V_4 -> V_95
- 1 ) ;
for ( V_118 = 0 ; V_118 < V_117 ; V_118 ++ ) {
if ( V_10 >= V_114 -> V_121 + V_114 -> V_109 ||
V_10 < V_114 -> V_121 ) {
unsigned long V_122 ;
F_63 ( V_115 ) ;
V_105 -> V_109 = V_120 ;
V_120 = 0 ;
F_64 ( V_54 , V_114 , V_105 ) ;
F_65 ( V_114 ) ;
V_122 = V_51 -> V_73 . V_74 - V_119 ;
V_105 = F_51 ( F_52 ( V_4 , V_122 ) ,
V_77 ) ;
F_4 ( ! V_105 ) ;
V_105 -> V_109 = V_122 ;
V_114 = F_60 ( V_54 ,
V_10 ) ;
ASSERT ( V_114 ) ;
V_105 -> V_33 = ( ( T_1 ) V_51 -> V_73 . V_86 << 9 )
+ V_119 ;
V_116 = 0 ;
V_115 = F_61 ( V_59 -> V_88 ) ;
}
V_105 -> V_105 [ V_116 ] = ~ ( T_4 ) 0 ;
V_105 -> V_105 [ V_116 ]
= F_66 ( V_115 + V_59 -> V_89
+ ( V_118 * V_4 -> V_95 ) ,
V_105 -> V_105 [ V_116 ] ,
V_4 -> V_95 ) ;
F_67 ( V_105 -> V_105 [ V_116 ] ,
( char * ) ( V_105 -> V_105 + V_116 ) ) ;
V_116 ++ ;
V_10 += V_4 -> V_95 ;
V_120 += V_4 -> V_95 ;
V_119 += V_4 -> V_95 ;
}
F_63 ( V_115 ) ;
V_71 ++ ;
V_59 ++ ;
}
V_120 = 0 ;
F_64 ( V_54 , V_114 , V_105 ) ;
F_65 ( V_114 ) ;
return 0 ;
}
static T_6 void F_68 ( struct V_3 * V_4 ,
struct V_20 * V_21 ,
struct V_18 * V_103 ,
T_1 V_33 , T_1 V_109 )
{
struct V_22 * V_23 ;
T_3 V_37 = F_19 ( V_4 -> V_38 -> V_39 ) ;
T_1 V_108 ;
T_1 V_123 = V_33 + V_109 ;
T_4 V_124 = V_4 -> V_38 -> V_44 -> V_45 ;
V_23 = V_21 -> V_28 [ 0 ] ;
V_108 = F_22 ( V_23 , V_21 -> V_29 [ 0 ] ) / V_37 ;
V_108 <<= V_4 -> V_38 -> V_44 -> V_45 ;
V_108 += V_103 -> V_10 ;
if ( V_103 -> V_10 < V_33 && V_108 <= V_123 ) {
T_4 V_125 = ( V_33 - V_103 -> V_10 ) >> V_124 ;
V_125 *= V_37 ;
F_69 ( V_4 , V_21 , V_125 , 1 ) ;
} else if ( V_103 -> V_10 >= V_33 && V_108 > V_123 &&
V_123 > V_103 -> V_10 ) {
T_4 V_125 = ( V_108 - V_123 ) >> V_124 ;
V_125 *= V_37 ;
F_69 ( V_4 , V_21 , V_125 , 0 ) ;
V_103 -> V_10 = V_123 ;
F_70 ( V_4 -> V_38 , V_21 , V_103 ) ;
} else {
F_71 () ;
}
}
int F_72 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_1 V_33 , T_1 V_109 )
{
struct V_20 * V_21 ;
struct V_18 V_103 ;
T_1 V_123 = V_33 + V_109 ;
T_1 V_108 ;
struct V_22 * V_23 ;
int V_15 ;
T_3 V_37 = F_19 ( V_4 -> V_38 -> V_39 ) ;
int V_124 = V_4 -> V_38 -> V_44 -> V_45 ;
V_4 = V_4 -> V_38 -> V_92 ;
V_21 = F_2 () ;
if ( ! V_21 )
return - V_24 ;
while ( 1 ) {
V_103 . V_5 = V_41 ;
V_103 . V_10 = V_123 - 1 ;
V_103 . type = V_42 ;
V_21 -> V_26 = 1 ;
V_15 = F_20 ( V_2 , V_4 , & V_103 , V_21 , - 1 , 1 ) ;
if ( V_15 > 0 ) {
if ( V_21 -> V_29 [ 0 ] == 0 )
break;
V_21 -> V_29 [ 0 ] -- ;
} else if ( V_15 < 0 ) {
break;
}
V_23 = V_21 -> V_28 [ 0 ] ;
F_21 ( V_23 , & V_103 , V_21 -> V_29 [ 0 ] ) ;
if ( V_103 . V_5 != V_41 ||
V_103 . type != V_42 ) {
break;
}
if ( V_103 . V_10 >= V_123 )
break;
V_108 = F_22 ( V_23 , V_21 -> V_29 [ 0 ] ) / V_37 ;
V_108 <<= V_124 ;
V_108 += V_103 . V_10 ;
if ( V_108 <= V_33 )
break;
if ( V_103 . V_10 >= V_33 && V_108 <= V_123 ) {
V_15 = F_73 ( V_2 , V_4 , V_21 ) ;
if ( V_15 )
goto V_27;
if ( V_103 . V_10 == V_33 )
break;
} else if ( V_103 . V_10 < V_33 && V_108 > V_123 ) {
unsigned long V_10 ;
unsigned long V_126 ;
unsigned long V_127 ;
V_10 = ( V_33 - V_103 . V_10 ) >> V_124 ;
V_10 *= V_37 ;
V_126 = ( V_109 >> V_124 ) * V_37 ;
V_127 = F_74 ( V_23 ,
V_21 -> V_29 [ 0 ] ) ;
F_75 ( V_23 , 0 , V_127 + V_10 ,
V_126 ) ;
V_103 . V_10 = V_33 ;
V_15 = F_76 ( V_2 , V_4 , V_21 , & V_103 , V_10 ) ;
if ( V_15 && V_15 != - V_128 ) {
F_77 ( V_2 , V_4 , V_15 ) ;
goto V_27;
}
V_103 . V_10 = V_123 - 1 ;
} else {
F_68 ( V_4 , V_21 , & V_103 , V_33 , V_109 ) ;
if ( V_103 . V_10 < V_33 )
break;
}
F_34 ( V_21 ) ;
}
V_15 = 0 ;
V_27:
F_17 ( V_21 ) ;
return V_15 ;
}
int F_78 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_104 * V_105 )
{
struct V_18 V_19 ;
struct V_18 V_35 ;
struct V_20 * V_21 ;
struct V_32 * V_17 ;
struct V_32 * V_129 ;
struct V_22 * V_23 = NULL ;
T_1 V_130 ;
T_1 V_119 = 0 ;
T_1 V_36 ;
T_1 V_33 ;
T_4 V_131 ;
T_4 V_132 ;
int V_116 = 0 ;
int V_133 ;
int V_15 ;
T_3 V_37 = F_19 ( V_4 -> V_38 -> V_39 ) ;
V_21 = F_2 () ;
if ( ! V_21 )
return - V_24 ;
V_134:
V_130 = ( T_1 ) - 1 ;
V_133 = 0 ;
V_33 = V_105 -> V_33 + V_119 ;
V_19 . V_5 = V_41 ;
V_19 . V_10 = V_33 ;
V_19 . type = V_42 ;
V_17 = F_18 ( V_2 , V_4 , V_21 , V_33 , 1 ) ;
if ( ! F_35 ( V_17 ) ) {
V_15 = 0 ;
V_23 = V_21 -> V_28 [ 0 ] ;
V_129 = F_5 ( V_23 , V_21 -> V_29 [ 0 ] ,
struct V_32 ) ;
V_129 = (struct V_32 * ) ( ( char * ) V_129 +
F_22 ( V_23 , V_21 -> V_29 [ 0 ] ) ) ;
goto V_90;
}
V_15 = F_79 ( V_17 ) ;
if ( V_15 != - V_46 && V_15 != - V_47 )
goto V_135;
if ( V_15 == - V_46 ) {
T_4 V_91 ;
V_23 = V_21 -> V_28 [ 0 ] ;
V_91 = F_22 ( V_23 , V_21 -> V_29 [ 0 ] ) ;
if ( ( V_91 / V_37 ) >=
F_80 ( V_4 , V_37 ) ) {
goto V_136;
}
} else {
int V_137 = V_21 -> V_29 [ 0 ] + 1 ;
V_131 = F_47 ( V_21 -> V_28 [ 0 ] ) ;
if ( ! V_131 || ( V_21 -> V_29 [ 0 ] >= V_131 - 1 ) ) {
V_15 = F_48 ( V_4 , V_21 ) ;
if ( V_15 == 1 )
V_133 = 1 ;
if ( V_15 != 0 )
goto V_136;
V_137 = V_21 -> V_29 [ 0 ] ;
}
F_21 ( V_21 -> V_28 [ 0 ] , & V_35 , V_137 ) ;
if ( V_35 . V_5 != V_41 ||
V_35 . type != V_42 ) {
V_133 = 1 ;
goto V_136;
}
V_130 = V_35 . V_10 ;
V_133 = 1 ;
goto V_136;
}
F_34 ( V_21 ) ;
V_15 = F_20 ( V_2 , V_4 , & V_19 , V_21 ,
V_37 , 1 ) ;
if ( V_15 < 0 )
goto V_135;
if ( V_15 > 0 ) {
if ( V_21 -> V_29 [ 0 ] == 0 )
goto V_136;
V_21 -> V_29 [ 0 ] -- ;
}
V_23 = V_21 -> V_28 [ 0 ] ;
F_21 ( V_23 , & V_35 , V_21 -> V_29 [ 0 ] ) ;
V_36 = ( V_33 - V_35 . V_10 ) >>
V_4 -> V_38 -> V_44 -> V_45 ;
if ( V_35 . type != V_42 ||
V_35 . V_5 != V_41 ||
V_36 >= F_80 ( V_4 , V_37 ) ) {
goto V_136;
}
if ( V_36 == F_22 ( V_23 , V_21 -> V_29 [ 0 ] ) /
V_37 ) {
int V_138 ;
T_1 V_139 ;
T_4 V_69 ;
T_4 V_140 ;
if ( F_81 ( V_4 , V_23 ) <
sizeof( struct V_141 ) + V_37 * 2 )
goto V_136;
V_140 = F_81 ( V_4 , V_23 ) -
sizeof( struct V_141 ) - V_37 ;
V_139 = V_105 -> V_109 - V_119 ;
V_139 >>= V_4 -> V_38 -> V_44 -> V_45 ;
F_30 ( V_139 < 1 ) ;
V_138 = F_82 ( int , 1 , ( int ) V_139 ) ;
V_69 = ( V_36 + V_138 ) * V_37 ;
V_69 = F_49 ( V_69 , F_80 ( V_4 , V_37 ) * V_37 ) ;
V_69 = V_69 - F_22 ( V_23 , V_21 -> V_29 [ 0 ] ) ;
V_69 = F_49 ( V_140 , V_69 ) ;
V_69 /= V_37 ;
V_69 *= V_37 ;
F_83 ( V_4 , V_21 , V_69 ) ;
V_15 = 0 ;
goto V_64;
}
V_136:
F_34 ( V_21 ) ;
V_36 = 0 ;
if ( V_133 ) {
T_1 V_139 ;
V_139 = V_105 -> V_109 - V_119 ;
V_139 >>= V_4 -> V_38 -> V_44 -> V_45 ;
V_139 = F_49 ( V_139 , ( V_130 - V_19 . V_10 ) >>
V_4 -> V_38 -> V_44 -> V_45 ) ;
V_139 = F_84 ( ( T_1 ) 1 , V_139 ) ;
V_139 = F_49 ( V_139 , ( T_1 ) F_80 ( V_4 , V_37 ) ) ;
V_132 = V_37 * V_139 ;
} else {
V_132 = V_37 ;
}
V_21 -> V_26 = 1 ;
V_15 = F_3 ( V_2 , V_4 , V_21 , & V_19 ,
V_132 ) ;
V_21 -> V_26 = 0 ;
if ( V_15 < 0 )
goto V_135;
if ( F_30 ( V_15 != 0 ) )
goto V_135;
V_23 = V_21 -> V_28 [ 0 ] ;
V_64:
V_17 = F_5 ( V_23 , V_21 -> V_29 [ 0 ] , struct V_32 ) ;
V_129 = (struct V_32 * ) ( ( unsigned char * ) V_17 +
F_22 ( V_23 , V_21 -> V_29 [ 0 ] ) ) ;
V_17 = (struct V_32 * ) ( ( unsigned char * ) V_17 +
V_36 * V_37 ) ;
V_90:
V_132 = ( T_4 ) ( V_105 -> V_109 - V_119 ) >>
V_4 -> V_38 -> V_44 -> V_45 ;
V_132 *= V_37 ;
V_132 = F_39 ( T_4 , ( unsigned long ) V_129 - ( unsigned long ) V_17 ,
V_132 ) ;
F_85 ( V_23 , V_105 -> V_105 + V_116 , ( unsigned long ) V_17 ,
V_132 ) ;
V_132 /= V_37 ;
V_119 += V_132 * V_4 -> V_95 ;
V_116 += V_132 ;
F_16 ( V_21 -> V_28 [ 0 ] ) ;
if ( V_119 < V_105 -> V_109 ) {
F_34 ( V_21 ) ;
F_86 () ;
goto V_134;
}
V_27:
F_17 ( V_21 ) ;
return V_15 ;
V_135:
goto V_27;
}
void F_87 ( struct V_54 * V_54 ,
const struct V_20 * V_21 ,
struct V_16 * V_142 ,
const bool V_143 ,
struct V_144 * V_145 )
{
struct V_3 * V_4 = F_28 ( V_54 ) -> V_4 ;
struct V_22 * V_23 = V_21 -> V_28 [ 0 ] ;
const int V_137 = V_21 -> V_29 [ 0 ] ;
struct V_18 V_103 ;
T_1 V_146 , V_147 ;
T_1 V_33 ;
T_2 type = F_88 ( V_23 , V_142 ) ;
int V_148 = F_89 ( V_23 , V_142 ) ;
V_145 -> V_149 = V_4 -> V_38 -> V_150 -> V_151 ;
F_21 ( V_23 , & V_103 , V_137 ) ;
V_146 = V_103 . V_10 ;
if ( type == V_31 ||
type == V_152 ) {
V_147 = V_146 +
F_90 ( V_23 , V_142 ) ;
} else if ( type == V_153 ) {
T_5 V_107 ;
V_107 = F_91 ( V_23 , V_137 , V_142 ) ;
V_147 = F_92 ( V_146 + V_107 , V_4 -> V_95 ) ;
}
V_145 -> V_11 = F_93 ( V_23 , V_142 ) ;
if ( type == V_31 ||
type == V_152 ) {
V_145 -> V_98 = V_146 ;
V_145 -> V_109 = V_147 - V_146 ;
V_145 -> V_154 = V_146 -
F_94 ( V_23 , V_142 ) ;
V_145 -> V_155 = F_95 ( V_23 , V_142 ) ;
V_33 = F_96 ( V_23 , V_142 ) ;
if ( V_33 == 0 ) {
V_145 -> V_156 = V_157 ;
return;
}
if ( V_148 != V_158 ) {
F_97 ( V_159 , & V_145 -> V_160 ) ;
V_145 -> V_148 = V_148 ;
V_145 -> V_156 = V_33 ;
V_145 -> V_161 = V_145 -> V_155 ;
} else {
V_33 += F_94 ( V_23 , V_142 ) ;
V_145 -> V_156 = V_33 ;
V_145 -> V_161 = V_145 -> V_109 ;
if ( type == V_152 )
F_97 ( V_162 , & V_145 -> V_160 ) ;
}
} else if ( type == V_153 ) {
V_145 -> V_156 = V_163 ;
V_145 -> V_98 = V_146 ;
V_145 -> V_109 = V_147 - V_146 ;
V_145 -> V_154 = V_157 ;
V_145 -> V_161 = ( T_1 ) - 1 ;
if ( ! V_143 && V_148 != V_158 ) {
F_97 ( V_159 , & V_145 -> V_160 ) ;
V_145 -> V_148 = V_148 ;
}
} else {
F_98 ( V_4 -> V_38 ,
L_2 ,
type , F_38 ( V_54 ) , V_146 ,
V_4 -> V_93 . V_5 ) ;
}
}
