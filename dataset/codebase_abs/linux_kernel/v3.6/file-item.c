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
F_3 ( & V_19 , V_25 ) ;
V_21 -> V_26 = 1 ;
V_15 = F_4 ( V_2 , V_4 , V_21 , & V_19 ,
sizeof( * V_17 ) ) ;
if ( V_15 < 0 )
goto V_27;
F_5 ( V_15 ) ;
V_23 = V_21 -> V_28 [ 0 ] ;
V_17 = F_6 ( V_23 , V_21 -> V_29 [ 0 ] ,
struct V_16 ) ;
F_7 ( V_23 , V_17 , V_7 ) ;
F_8 ( V_23 , V_17 , V_8 ) ;
F_9 ( V_23 , V_17 , V_10 ) ;
F_10 ( V_23 , V_17 , V_9 ) ;
F_11 ( V_23 , V_17 , V_11 ) ;
F_12 ( V_23 , V_17 , V_2 -> V_30 ) ;
F_13 ( V_23 , V_17 , V_31 ) ;
F_14 ( V_23 , V_17 , V_12 ) ;
F_15 ( V_23 , V_17 , V_13 ) ;
F_16 ( V_23 , V_17 , V_14 ) ;
F_17 ( V_23 ) ;
V_27:
F_18 ( V_21 ) ;
return V_15 ;
}
struct V_32 * F_19 ( struct V_1 * V_2 ,
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
T_3 V_37 = F_20 ( V_4 -> V_38 -> V_39 ) ;
int V_40 ;
V_19 . V_5 = V_41 ;
V_19 . V_10 = V_33 ;
F_3 ( & V_19 , V_42 ) ;
V_15 = F_21 ( V_2 , V_4 , & V_19 , V_21 , 0 , V_34 ) ;
if ( V_15 < 0 )
goto V_43;
V_23 = V_21 -> V_28 [ 0 ] ;
if ( V_15 > 0 ) {
V_15 = 1 ;
if ( V_21 -> V_29 [ 0 ] == 0 )
goto V_43;
V_21 -> V_29 [ 0 ] -- ;
F_22 ( V_23 , & V_35 , V_21 -> V_29 [ 0 ] ) ;
if ( F_23 ( & V_35 ) != V_42 )
goto V_43;
V_36 = ( V_33 - V_35 . V_10 ) >>
V_4 -> V_38 -> V_44 -> V_45 ;
V_40 = F_24 ( V_23 , V_21 -> V_29 [ 0 ] ) ;
V_40 /= V_37 ;
if ( V_36 >= V_40 ) {
V_15 = - V_46 ;
goto V_43;
}
}
V_17 = F_6 ( V_23 , V_21 -> V_29 [ 0 ] , struct V_32 ) ;
V_17 = (struct V_32 * ) ( ( unsigned char * ) V_17 +
V_36 * V_37 ) ;
return V_17 ;
V_43:
if ( V_15 > 0 )
V_15 = - V_47 ;
return F_25 ( V_15 ) ;
}
int F_26 ( struct V_1 * V_2 ,
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
F_3 ( & V_19 , V_25 ) ;
V_15 = F_21 ( V_2 , V_4 , & V_19 , V_21 , V_49 , V_34 ) ;
return V_15 ;
}
static int F_27 ( struct V_3 * V_4 ,
struct V_50 * V_50 , struct V_51 * V_51 ,
T_1 V_52 , T_4 * V_53 , int V_54 )
{
T_4 V_55 ;
struct V_56 * V_57 = V_51 -> V_58 ;
int V_59 = 0 ;
T_1 V_10 = 0 ;
T_1 V_60 = 0 ;
T_1 V_61 = 0 ;
T_1 V_62 ;
T_4 V_63 ;
T_3 V_37 = F_20 ( V_4 -> V_38 -> V_39 ) ;
int V_15 ;
struct V_20 * V_21 ;
struct V_32 * V_17 = NULL ;
struct V_64 * V_65 = & F_28 ( V_50 ) -> V_65 ;
V_21 = F_2 () ;
if ( ! V_21 )
return - V_24 ;
if ( V_51 -> V_66 > V_67 * 8 )
V_21 -> V_68 = 2 ;
F_29 ( V_51 -> V_69 <= 0 ) ;
if ( F_30 ( V_50 ) ) {
V_21 -> V_70 = 1 ;
V_21 -> V_71 = 1 ;
}
V_62 = ( T_1 ) V_51 -> V_72 << 9 ;
if ( V_54 )
V_10 = V_52 ;
while ( V_59 < V_51 -> V_69 ) {
if ( ! V_54 )
V_10 = F_31 ( V_57 -> V_73 ) + V_57 -> V_74 ;
V_15 = F_32 ( V_50 , V_10 , V_62 , & V_55 ) ;
if ( V_15 == 0 )
goto V_75;
if ( ! V_17 || V_62 < V_60 ||
V_62 >= V_61 ) {
struct V_18 V_35 ;
T_4 V_76 ;
if ( V_17 )
F_33 ( V_21 ) ;
V_17 = F_19 ( NULL , V_4 -> V_38 -> V_77 ,
V_21 , V_62 , 0 ) ;
if ( F_34 ( V_17 ) ) {
V_15 = F_35 ( V_17 ) ;
if ( V_15 == - V_47 || V_15 == - V_46 )
V_15 = 0 ;
V_55 = 0 ;
if ( F_28 ( V_50 ) -> V_4 -> V_78 . V_5 ==
V_79 ) {
F_36 ( V_65 , V_10 ,
V_10 + V_57 -> V_80 - 1 ,
V_81 , V_82 ) ;
} else {
F_37 ( V_83 L_1
L_2 ,
( unsigned long long )
F_38 ( V_50 ) ,
( unsigned long long ) V_10 ) ;
}
V_17 = NULL ;
F_33 ( V_21 ) ;
goto V_75;
}
F_22 ( V_21 -> V_28 [ 0 ] , & V_35 ,
V_21 -> V_29 [ 0 ] ) ;
V_60 = V_35 . V_10 ;
V_76 = F_24 ( V_21 -> V_28 [ 0 ] ,
V_21 -> V_29 [ 0 ] ) ;
V_61 = V_60 +
( V_76 / V_37 ) *
V_4 -> V_84 ;
V_17 = F_6 ( V_21 -> V_28 [ 0 ] , V_21 -> V_29 [ 0 ] ,
struct V_32 ) ;
}
V_63 = V_62 - V_60 ;
V_63 = V_63 / V_4 -> V_84 ;
V_63 = V_63 * V_37 ;
F_39 ( V_21 -> V_28 [ 0 ] , & V_55 ,
( ( unsigned long ) V_17 ) + V_63 ,
V_37 ) ;
V_75:
if ( V_53 )
* V_53 ++ = V_55 ;
else
F_40 ( V_65 , V_10 , V_55 ) ;
V_62 += V_57 -> V_80 ;
V_10 += V_57 -> V_80 ;
V_59 ++ ;
V_57 ++ ;
}
F_18 ( V_21 ) ;
return 0 ;
}
int F_41 ( struct V_3 * V_4 , struct V_50 * V_50 ,
struct V_51 * V_51 , T_4 * V_53 )
{
return F_27 ( V_4 , V_50 , V_51 , 0 , V_53 , 0 ) ;
}
int F_42 ( struct V_3 * V_4 , struct V_50 * V_50 ,
struct V_51 * V_51 , T_1 V_10 )
{
return F_27 ( V_4 , V_50 , V_51 , V_10 , NULL , 1 ) ;
}
int F_43 ( struct V_3 * V_4 , T_1 V_85 , T_1 V_86 ,
struct V_87 * V_88 , int V_89 )
{
struct V_18 V_90 ;
struct V_20 * V_21 ;
struct V_22 * V_23 ;
struct V_91 * V_92 ;
struct V_93 * V_94 ;
struct V_32 * V_17 ;
F_44 ( V_95 ) ;
unsigned long V_10 ;
int V_15 ;
T_5 V_96 ;
T_1 V_97 ;
T_3 V_37 = F_20 ( V_4 -> V_38 -> V_39 ) ;
V_21 = F_2 () ;
if ( ! V_21 )
return - V_24 ;
if ( V_89 ) {
V_21 -> V_71 = 1 ;
V_21 -> V_68 = 2 ;
V_21 -> V_70 = 1 ;
}
V_90 . V_5 = V_41 ;
V_90 . V_10 = V_85 ;
V_90 . type = V_42 ;
V_15 = F_21 ( NULL , V_4 , & V_90 , V_21 , 0 , 0 ) ;
if ( V_15 < 0 )
goto V_43;
if ( V_15 > 0 && V_21 -> V_29 [ 0 ] > 0 ) {
V_23 = V_21 -> V_28 [ 0 ] ;
F_22 ( V_23 , & V_90 , V_21 -> V_29 [ 0 ] - 1 ) ;
if ( V_90 . V_5 == V_41 &&
V_90 . type == V_42 ) {
V_10 = ( V_85 - V_90 . V_10 ) >>
V_4 -> V_38 -> V_44 -> V_45 ;
if ( V_10 * V_37 <
F_24 ( V_23 , V_21 -> V_29 [ 0 ] - 1 ) )
V_21 -> V_29 [ 0 ] -- ;
}
}
while ( V_85 <= V_86 ) {
V_23 = V_21 -> V_28 [ 0 ] ;
if ( V_21 -> V_29 [ 0 ] >= F_45 ( V_23 ) ) {
V_15 = F_46 ( V_4 , V_21 ) ;
if ( V_15 < 0 )
goto V_43;
if ( V_15 > 0 )
break;
V_23 = V_21 -> V_28 [ 0 ] ;
}
F_22 ( V_23 , & V_90 , V_21 -> V_29 [ 0 ] ) ;
if ( V_90 . V_5 != V_41 ||
V_90 . type != V_42 )
break;
F_22 ( V_23 , & V_90 , V_21 -> V_29 [ 0 ] ) ;
if ( V_90 . V_10 > V_86 )
break;
if ( V_90 . V_10 > V_85 )
V_85 = V_90 . V_10 ;
V_96 = F_24 ( V_23 , V_21 -> V_29 [ 0 ] ) ;
V_97 = V_90 . V_10 + ( V_96 / V_37 ) * V_4 -> V_84 ;
if ( V_97 <= V_85 ) {
V_21 -> V_29 [ 0 ] ++ ;
continue;
}
V_97 = F_47 ( V_97 , V_86 + 1 ) ;
V_17 = F_6 ( V_21 -> V_28 [ 0 ] , V_21 -> V_29 [ 0 ] ,
struct V_32 ) ;
while ( V_85 < V_97 ) {
V_96 = F_48 ( T_5 , V_97 - V_85 ,
F_49 ( V_4 ) ) ;
V_92 = F_50 ( F_51 ( V_4 , V_96 ) ,
V_82 ) ;
if ( ! V_92 ) {
V_15 = - V_24 ;
goto V_43;
}
V_94 = V_92 -> V_92 ;
V_92 -> V_33 = V_85 ;
V_92 -> V_98 = V_96 ;
V_10 = ( V_85 - V_90 . V_10 ) >>
V_4 -> V_38 -> V_44 -> V_45 ;
V_10 *= V_37 ;
while ( V_96 > 0 ) {
F_39 ( V_21 -> V_28 [ 0 ] ,
& V_94 -> V_55 ,
( ( unsigned long ) V_17 ) +
V_10 , V_37 ) ;
V_94 -> V_33 = V_85 ;
V_96 -= V_4 -> V_84 ;
V_85 += V_4 -> V_84 ;
V_10 += V_37 ;
V_94 ++ ;
}
F_52 ( & V_92 -> V_88 , & V_95 ) ;
}
V_21 -> V_29 [ 0 ] ++ ;
}
V_15 = 0 ;
V_43:
while ( V_15 < 0 && ! F_53 ( & V_95 ) ) {
V_92 = F_54 ( & V_95 , struct V_91 , V_88 ) ;
F_55 ( & V_92 -> V_88 ) ;
F_56 ( V_92 ) ;
}
F_57 ( & V_95 , V_88 ) ;
F_18 ( V_21 ) ;
return V_15 ;
}
int F_58 ( struct V_3 * V_4 , struct V_50 * V_50 ,
struct V_51 * V_51 , T_1 V_99 , int V_100 )
{
struct V_91 * V_92 ;
struct V_93 * V_94 ;
struct V_101 * V_102 ;
char * V_103 ;
struct V_56 * V_57 = V_51 -> V_58 ;
int V_59 = 0 ;
unsigned long V_104 = 0 ;
unsigned long V_105 = 0 ;
T_1 V_10 ;
T_1 V_62 ;
F_29 ( V_51 -> V_69 <= 0 ) ;
V_92 = F_50 ( F_51 ( V_4 , V_51 -> V_66 ) , V_82 ) ;
if ( ! V_92 )
return - V_24 ;
V_94 = V_92 -> V_92 ;
V_62 = ( T_1 ) V_51 -> V_72 << 9 ;
V_92 -> V_98 = V_51 -> V_66 ;
F_59 ( & V_92 -> V_88 ) ;
if ( V_100 )
V_10 = V_99 ;
else
V_10 = F_31 ( V_57 -> V_73 ) + V_57 -> V_74 ;
V_102 = F_60 ( V_50 , V_10 ) ;
F_5 ( ! V_102 ) ;
V_92 -> V_33 = V_102 -> V_85 ;
while ( V_59 < V_51 -> V_69 ) {
if ( ! V_100 )
V_10 = F_31 ( V_57 -> V_73 ) + V_57 -> V_74 ;
if ( ! V_100 && ( V_10 >= V_102 -> V_106 + V_102 -> V_98 ||
V_10 < V_102 -> V_106 ) ) {
unsigned long V_107 ;
V_92 -> V_98 = V_105 ;
V_105 = 0 ;
F_61 ( V_50 , V_102 , V_92 ) ;
F_62 ( V_102 ) ;
V_107 = V_51 -> V_66 - V_104 ;
V_92 = F_50 ( F_51 ( V_4 , V_107 ) ,
V_82 ) ;
F_5 ( ! V_92 ) ;
V_94 = V_92 -> V_92 ;
V_92 -> V_98 = V_107 ;
V_102 = F_60 ( V_50 , V_10 ) ;
F_5 ( ! V_102 ) ;
V_92 -> V_33 = V_102 -> V_85 ;
}
V_103 = F_63 ( V_57 -> V_73 ) ;
V_94 -> V_55 = ~ ( T_4 ) 0 ;
V_94 -> V_55 = F_64 ( V_4 ,
V_103 + V_57 -> V_74 ,
V_94 -> V_55 ,
V_57 -> V_80 ) ;
F_65 ( V_103 ) ;
F_66 ( V_94 -> V_55 ,
( char * ) & V_94 -> V_55 ) ;
V_94 -> V_33 = V_62 ;
V_94 ++ ;
V_59 ++ ;
V_104 += V_57 -> V_80 ;
V_105 += V_57 -> V_80 ;
V_62 += V_57 -> V_80 ;
V_10 += V_57 -> V_80 ;
V_57 ++ ;
}
V_105 = 0 ;
F_61 ( V_50 , V_102 , V_92 ) ;
F_62 ( V_102 ) ;
return 0 ;
}
static T_6 void F_67 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_20 * V_21 ,
struct V_18 * V_90 ,
T_1 V_33 , T_1 V_98 )
{
struct V_22 * V_23 ;
T_3 V_37 = F_20 ( V_4 -> V_38 -> V_39 ) ;
T_1 V_97 ;
T_1 V_108 = V_33 + V_98 ;
T_4 V_109 = V_4 -> V_38 -> V_44 -> V_45 ;
V_23 = V_21 -> V_28 [ 0 ] ;
V_97 = F_24 ( V_23 , V_21 -> V_29 [ 0 ] ) / V_37 ;
V_97 <<= V_4 -> V_38 -> V_44 -> V_45 ;
V_97 += V_90 -> V_10 ;
if ( V_90 -> V_10 < V_33 && V_97 <= V_108 ) {
T_4 V_110 = ( V_33 - V_90 -> V_10 ) >> V_109 ;
V_110 *= V_37 ;
F_68 ( V_2 , V_4 , V_21 , V_110 , 1 ) ;
} else if ( V_90 -> V_10 >= V_33 && V_97 > V_108 &&
V_108 > V_90 -> V_10 ) {
T_4 V_110 = ( V_97 - V_108 ) >> V_109 ;
V_110 *= V_37 ;
F_68 ( V_2 , V_4 , V_21 , V_110 , 0 ) ;
V_90 -> V_10 = V_108 ;
F_69 ( V_2 , V_4 , V_21 , V_90 ) ;
} else {
F_70 () ;
}
}
int F_71 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_1 V_33 , T_1 V_98 )
{
struct V_20 * V_21 ;
struct V_18 V_90 ;
T_1 V_108 = V_33 + V_98 ;
T_1 V_97 ;
struct V_22 * V_23 ;
int V_15 ;
T_3 V_37 = F_20 ( V_4 -> V_38 -> V_39 ) ;
int V_109 = V_4 -> V_38 -> V_44 -> V_45 ;
V_4 = V_4 -> V_38 -> V_77 ;
V_21 = F_2 () ;
if ( ! V_21 )
return - V_24 ;
while ( 1 ) {
V_90 . V_5 = V_41 ;
V_90 . V_10 = V_108 - 1 ;
V_90 . type = V_42 ;
V_21 -> V_26 = 1 ;
V_15 = F_21 ( V_2 , V_4 , & V_90 , V_21 , - 1 , 1 ) ;
if ( V_15 > 0 ) {
if ( V_21 -> V_29 [ 0 ] == 0 )
break;
V_21 -> V_29 [ 0 ] -- ;
} else if ( V_15 < 0 ) {
break;
}
V_23 = V_21 -> V_28 [ 0 ] ;
F_22 ( V_23 , & V_90 , V_21 -> V_29 [ 0 ] ) ;
if ( V_90 . V_5 != V_41 ||
V_90 . type != V_42 ) {
break;
}
if ( V_90 . V_10 >= V_108 )
break;
V_97 = F_24 ( V_23 , V_21 -> V_29 [ 0 ] ) / V_37 ;
V_97 <<= V_109 ;
V_97 += V_90 . V_10 ;
if ( V_97 <= V_33 )
break;
if ( V_90 . V_10 >= V_33 && V_97 <= V_108 ) {
V_15 = F_72 ( V_2 , V_4 , V_21 ) ;
if ( V_15 )
goto V_27;
if ( V_90 . V_10 == V_33 )
break;
} else if ( V_90 . V_10 < V_33 && V_97 > V_108 ) {
unsigned long V_10 ;
unsigned long V_111 ;
unsigned long V_112 ;
V_10 = ( V_33 - V_90 . V_10 ) >> V_109 ;
V_10 *= V_37 ;
V_111 = ( V_98 >> V_109 ) * V_37 ;
V_112 = F_73 ( V_23 ,
V_21 -> V_29 [ 0 ] ) ;
F_74 ( V_23 , 0 , V_112 + V_10 ,
V_111 ) ;
V_90 . V_10 = V_33 ;
V_15 = F_75 ( V_2 , V_4 , V_21 , & V_90 , V_10 ) ;
if ( V_15 && V_15 != - V_113 ) {
F_76 ( V_2 , V_4 , V_15 ) ;
goto V_27;
}
V_90 . V_10 = V_108 - 1 ;
} else {
F_67 ( V_2 , V_4 , V_21 , & V_90 , V_33 , V_98 ) ;
if ( V_90 . V_10 < V_33 )
break;
}
F_33 ( V_21 ) ;
}
V_15 = 0 ;
V_27:
F_18 ( V_21 ) ;
return V_15 ;
}
int F_77 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_91 * V_92 )
{
T_1 V_33 ;
int V_15 ;
struct V_18 V_19 ;
struct V_18 V_35 ;
T_1 V_114 ;
T_1 V_104 = 0 ;
int V_115 ;
struct V_20 * V_21 ;
struct V_32 * V_17 ;
struct V_32 * V_116 ;
struct V_22 * V_23 = NULL ;
T_1 V_36 ;
struct V_93 * V_94 ;
T_4 V_117 ;
T_4 V_118 ;
T_3 V_37 = F_20 ( V_4 -> V_38 -> V_39 ) ;
V_21 = F_2 () ;
if ( ! V_21 )
return - V_24 ;
V_94 = V_92 -> V_92 ;
V_2 -> V_119 = 1 ;
V_120:
V_114 = ( T_1 ) - 1 ;
V_115 = 0 ;
V_19 . V_5 = V_41 ;
V_19 . V_10 = V_94 -> V_33 ;
V_33 = V_94 -> V_33 ;
F_3 ( & V_19 , V_42 ) ;
V_17 = F_19 ( V_2 , V_4 , V_21 , V_94 -> V_33 , 1 ) ;
if ( ! F_34 ( V_17 ) ) {
V_23 = V_21 -> V_28 [ 0 ] ;
V_15 = 0 ;
goto V_75;
}
V_15 = F_35 ( V_17 ) ;
if ( V_15 != - V_46 && V_15 != - V_47 )
goto V_121;
if ( V_15 == - V_46 ) {
T_4 V_76 ;
V_23 = V_21 -> V_28 [ 0 ] ;
V_76 = F_24 ( V_23 , V_21 -> V_29 [ 0 ] ) ;
if ( ( V_76 / V_37 ) >=
F_78 ( V_4 , V_37 ) ) {
goto V_122;
}
} else {
int V_123 = V_21 -> V_29 [ 0 ] + 1 ;
V_117 = F_45 ( V_21 -> V_28 [ 0 ] ) ;
if ( V_21 -> V_29 [ 0 ] >= V_117 - 1 ) {
V_15 = F_46 ( V_4 , V_21 ) ;
if ( V_15 == 1 )
V_115 = 1 ;
if ( V_15 != 0 )
goto V_122;
V_123 = 0 ;
}
F_22 ( V_21 -> V_28 [ 0 ] , & V_35 , V_123 ) ;
if ( V_35 . V_5 != V_41 ||
V_35 . type != V_42 ) {
V_115 = 1 ;
goto V_122;
}
V_114 = V_35 . V_10 ;
V_115 = 1 ;
goto V_122;
}
F_33 ( V_21 ) ;
V_15 = F_21 ( V_2 , V_4 , & V_19 , V_21 ,
V_37 , 1 ) ;
if ( V_15 < 0 )
goto V_121;
if ( V_15 > 0 ) {
if ( V_21 -> V_29 [ 0 ] == 0 )
goto V_122;
V_21 -> V_29 [ 0 ] -- ;
}
V_23 = V_21 -> V_28 [ 0 ] ;
F_22 ( V_23 , & V_35 , V_21 -> V_29 [ 0 ] ) ;
V_36 = ( V_33 - V_35 . V_10 ) >>
V_4 -> V_38 -> V_44 -> V_45 ;
if ( F_23 ( & V_35 ) != V_42 ||
V_35 . V_5 != V_41 ||
V_36 >= F_78 ( V_4 , V_37 ) ) {
goto V_122;
}
if ( V_36 >= F_24 ( V_23 , V_21 -> V_29 [ 0 ] ) /
V_37 ) {
T_4 V_63 = ( V_36 + 1 ) * V_37 ;
if ( V_63 < F_24 ( V_23 , V_21 -> V_29 [ 0 ] ) )
goto V_124;
V_63 = V_63 - F_24 ( V_23 , V_21 -> V_29 [ 0 ] ) ;
if ( V_63 != V_37 )
goto V_122;
F_79 ( V_2 , V_4 , V_21 , V_63 ) ;
goto V_124;
}
V_122:
F_33 ( V_21 ) ;
V_36 = 0 ;
if ( V_115 ) {
T_1 V_125 = V_104 + V_4 -> V_84 ;
T_1 V_126 = V_94 -> V_33 ;
struct V_93 * V_127 = V_94 + 1 ;
while ( V_125 < V_92 -> V_98 ) {
if ( V_126 + V_4 -> V_84 != V_127 -> V_33 )
break;
V_125 += V_4 -> V_84 ;
V_126 = V_127 -> V_33 ;
V_127 ++ ;
}
V_125 = F_47 ( V_125 , V_114 - V_19 . V_10 ) ;
V_125 >>= V_4 -> V_38 -> V_44 -> V_45 ;
V_125 = F_80 ( ( T_1 ) 1 , V_125 ) ;
V_125 = F_47 ( V_125 , ( T_1 ) F_78 ( V_4 , V_37 ) ) ;
V_118 = V_37 * V_125 ;
} else {
V_118 = V_37 ;
}
V_21 -> V_26 = 1 ;
V_15 = F_4 ( V_2 , V_4 , V_21 , & V_19 ,
V_118 ) ;
V_21 -> V_26 = 0 ;
if ( V_15 < 0 )
goto V_121;
if ( V_15 != 0 ) {
F_29 ( 1 ) ;
goto V_121;
}
V_124:
V_23 = V_21 -> V_28 [ 0 ] ;
V_17 = F_6 ( V_23 , V_21 -> V_29 [ 0 ] , struct V_32 ) ;
V_15 = 0 ;
V_17 = (struct V_32 * ) ( ( unsigned char * ) V_17 +
V_36 * V_37 ) ;
V_75:
V_116 = F_6 ( V_23 , V_21 -> V_29 [ 0 ] , struct V_32 ) ;
V_116 = (struct V_32 * ) ( ( unsigned char * ) V_116 +
F_24 ( V_23 , V_21 -> V_29 [ 0 ] ) ) ;
V_126:
F_81 ( V_23 , & V_94 -> V_55 , ( unsigned long ) V_17 , V_37 ) ;
V_104 += V_4 -> V_84 ;
V_94 ++ ;
if ( V_104 < V_92 -> V_98 ) {
V_17 = (struct V_32 * ) ( ( char * ) V_17 +
V_37 ) ;
if ( V_17 < V_116 && V_33 + V_67 ==
V_94 -> V_33 ) {
V_33 = V_94 -> V_33 ;
goto V_126;
}
}
F_17 ( V_21 -> V_28 [ 0 ] ) ;
if ( V_104 < V_92 -> V_98 ) {
F_33 ( V_21 ) ;
F_82 () ;
goto V_120;
}
V_27:
V_2 -> V_119 = 0 ;
F_18 ( V_21 ) ;
return V_15 ;
V_121:
goto V_27;
}
