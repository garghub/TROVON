static inline void F_1 ( T_1 * V_1 , struct V_2 * V_3 , T_2 * V_4 )
{
V_1 -> V_5 = * ( V_1 -> V_1 = V_4 ) ;
V_1 -> V_3 = V_3 ;
}
static int F_2 ( struct V_6 * V_6 ,
T_3 V_7 ,
T_3 V_8 [ 4 ] , int * V_9 )
{
int V_10 = F_3 ( V_6 -> V_11 ) ;
int V_12 = F_4 ( V_6 -> V_11 ) ;
const long V_13 = V_14 ,
V_15 = V_10 ,
V_16 = ( 1 << ( V_12 * 2 ) ) ;
int V_17 = 0 ;
int V_18 = 0 ;
if ( V_7 < V_13 ) {
V_8 [ V_17 ++ ] = V_7 ;
V_18 = V_13 ;
} else if ( ( V_7 -= V_13 ) < V_15 ) {
V_8 [ V_17 ++ ] = V_19 ;
V_8 [ V_17 ++ ] = V_7 ;
V_18 = V_10 ;
} else if ( ( V_7 -= V_15 ) < V_16 ) {
V_8 [ V_17 ++ ] = V_20 ;
V_8 [ V_17 ++ ] = V_7 >> V_12 ;
V_8 [ V_17 ++ ] = V_7 & ( V_10 - 1 ) ;
V_18 = V_10 ;
} else if ( ( ( V_7 -= V_16 ) >> ( V_12 * 2 ) ) < V_10 ) {
V_8 [ V_17 ++ ] = V_21 ;
V_8 [ V_17 ++ ] = V_7 >> ( V_12 * 2 ) ;
V_8 [ V_17 ++ ] = ( V_7 >> V_12 ) & ( V_10 - 1 ) ;
V_8 [ V_17 ++ ] = V_7 & ( V_10 - 1 ) ;
V_18 = V_10 ;
} else {
F_5 ( V_6 -> V_11 , L_1 ,
V_7 + V_13 +
V_15 + V_16 , V_6 -> V_22 ) ;
}
if ( V_9 )
* V_9 = V_18 - 1 - ( V_7 & ( V_10 - 1 ) ) ;
return V_17 ;
}
static T_1 * F_6 ( struct V_6 * V_6 , int V_23 ,
T_3 * V_8 ,
T_1 V_24 [ 4 ] , int * V_25 )
{
struct V_26 * V_27 = V_6 -> V_11 ;
T_1 * V_1 = V_24 ;
struct V_2 * V_3 ;
* V_25 = 0 ;
F_1 ( V_24 , NULL , F_7 ( V_6 ) -> V_28 + * V_8 ) ;
if ( ! V_1 -> V_5 )
goto V_29;
while ( -- V_23 ) {
V_3 = F_8 ( V_27 , F_9 ( V_1 -> V_5 ) ) ;
if ( F_10 ( ! V_3 ) )
goto V_30;
if ( ! F_11 ( V_3 ) ) {
if ( F_12 ( V_3 ) < 0 ) {
F_13 ( V_3 ) ;
goto V_30;
}
if ( F_14 ( V_6 , V_3 ) ) {
F_13 ( V_3 ) ;
goto V_30;
}
}
F_1 ( ++ V_1 , V_3 , ( T_2 * ) V_3 -> V_31 + * ++ V_8 ) ;
if ( ! V_1 -> V_5 )
goto V_29;
}
return NULL ;
V_30:
* V_25 = - V_32 ;
V_29:
return V_1 ;
}
static T_4 F_15 ( struct V_6 * V_6 , T_1 * V_33 )
{
struct V_34 * V_35 = F_7 ( V_6 ) ;
T_2 * V_36 = V_33 -> V_3 ? ( T_2 * ) V_33 -> V_3 -> V_31 : V_35 -> V_28 ;
T_2 * V_1 ;
for ( V_1 = V_33 -> V_1 - 1 ; V_1 >= V_36 ; V_1 -- ) {
if ( * V_1 )
return F_9 ( * V_1 ) ;
}
if ( V_33 -> V_3 )
return V_33 -> V_3 -> V_37 ;
return F_16 ( V_6 ) ;
}
static T_4 F_17 ( struct V_6 * V_6 , T_3 V_38 ,
T_1 * V_39 )
{
T_4 V_40 ;
V_40 = F_15 ( V_6 , V_39 ) ;
V_40 = V_40 & V_41 ;
return V_40 ;
}
static int F_18 ( T_1 * V_42 , int V_43 , unsigned int V_44 ,
int V_45 )
{
unsigned int V_46 = 0 ;
if ( V_43 > 0 ) {
if ( V_44 < V_45 + 1 )
V_46 += V_44 ;
else
V_46 += V_45 + 1 ;
return V_46 ;
}
V_46 ++ ;
while ( V_46 < V_44 && V_46 <= V_45 &&
F_9 ( * ( V_42 [ 0 ] . V_1 + V_46 ) ) == 0 ) {
V_46 ++ ;
}
return V_46 ;
}
static int F_19 ( T_5 * V_47 , struct V_6 * V_6 ,
T_3 V_48 , T_4 V_40 ,
int V_49 , int V_44 ,
T_4 V_50 [ 4 ] , int * V_25 )
{
struct V_51 V_52 ;
int V_53 , V_54 ;
unsigned long V_46 = 0 , V_55 = 0 ;
int V_56 = 0 ;
T_4 V_57 = 0 ;
int V_58 = 0 ;
V_53 = V_49 ;
while ( V_53 > 0 ) {
V_46 = V_53 ;
V_57 = F_20 ( V_47 , V_6 , V_40 ,
0 , & V_46 , V_25 ) ;
if ( * V_25 )
goto V_59;
if ( F_10 ( V_57 + V_46 > V_41 ) ) {
F_21 ( V_6 ,
L_2 ,
V_57 , V_46 ,
V_41 ) ;
* V_25 = - V_32 ;
goto V_59;
}
V_53 -= V_46 ;
while ( V_56 < V_49 && V_46 ) {
V_50 [ V_56 ++ ] = V_57 ++ ;
V_46 -- ;
}
if ( V_46 > 0 ) {
V_50 [ V_56 ] = V_57 ;
F_22 ( V_60 L_3
L_4 , V_61 ) ;
F_23 ( 1 ) ;
break;
}
}
V_53 = V_44 - V_46 ;
V_55 = V_46 ;
if ( ! V_53 )
goto V_62;
memset ( & V_52 , 0 , sizeof( V_52 ) ) ;
V_52 . V_6 = V_6 ;
V_52 . V_40 = V_40 ;
V_52 . V_63 = V_53 ;
V_52 . V_64 = V_48 ;
if ( F_24 ( V_6 -> V_65 ) )
V_52 . V_66 = V_67 ;
V_57 = F_25 ( V_47 , & V_52 , V_25 ) ;
if ( F_10 ( V_57 + V_52 . V_63 > V_41 ) ) {
F_21 ( V_6 ,
L_5 ,
V_57 , V_52 . V_63 ,
V_41 ) ;
* V_25 = - V_32 ;
goto V_59;
}
if ( * V_25 && ( V_53 == V_44 ) ) {
goto V_59;
}
if ( ! * V_25 ) {
if ( V_53 == V_44 ) {
V_50 [ V_56 ] = V_57 ;
}
V_55 += V_52 . V_63 ;
}
V_62:
V_58 = V_55 ;
* V_25 = 0 ;
return V_58 ;
V_59:
for ( V_54 = 0 ; V_54 < V_56 ; V_54 ++ )
F_26 ( V_47 , V_6 , NULL , V_50 [ V_54 ] , 1 , 0 ) ;
return V_58 ;
}
static int F_27 ( T_5 * V_47 , struct V_6 * V_6 ,
T_3 V_48 , int V_49 ,
int * V_44 , T_4 V_40 ,
T_3 * V_8 , T_1 * V_42 )
{
int V_68 = V_6 -> V_11 -> V_69 ;
int V_54 , V_17 = 0 ;
int V_25 = 0 ;
struct V_2 * V_3 ;
int V_70 ;
T_4 V_50 [ 4 ] ;
T_4 V_57 ;
V_70 = F_19 ( V_47 , V_6 , V_48 , V_40 , V_49 ,
* V_44 , V_50 , & V_25 ) ;
if ( V_25 )
return V_25 ;
V_42 [ 0 ] . V_5 = F_28 ( V_50 [ 0 ] ) ;
for ( V_17 = 1 ; V_17 <= V_49 ; V_17 ++ ) {
V_3 = F_8 ( V_6 -> V_11 , V_50 [ V_17 - 1 ] ) ;
if ( F_10 ( ! V_3 ) ) {
V_25 = - V_32 ;
goto V_71;
}
V_42 [ V_17 ] . V_3 = V_3 ;
F_29 ( V_3 ) ;
F_30 ( V_3 , L_6 ) ;
V_25 = F_31 ( V_47 , V_3 ) ;
if ( V_25 ) {
F_32 ( V_3 ) ;
goto V_71;
}
memset ( V_3 -> V_31 , 0 , V_68 ) ;
V_42 [ V_17 ] . V_1 = ( T_2 * ) V_3 -> V_31 + V_8 [ V_17 ] ;
V_42 [ V_17 ] . V_5 = F_28 ( V_50 [ V_17 ] ) ;
* V_42 [ V_17 ] . V_1 = V_42 [ V_17 ] . V_5 ;
if ( V_17 == V_49 ) {
V_57 = V_50 [ V_17 ] ;
for ( V_54 = 1 ; V_54 < V_70 ; V_54 ++ )
* ( V_42 [ V_17 ] . V_1 + V_54 ) = F_28 ( ++ V_57 ) ;
}
F_30 ( V_3 , L_7 ) ;
F_33 ( V_3 ) ;
F_32 ( V_3 ) ;
F_30 ( V_3 , L_8 ) ;
V_25 = F_34 ( V_47 , V_6 , V_3 ) ;
if ( V_25 )
goto V_71;
}
* V_44 = V_70 ;
return V_25 ;
V_71:
F_26 ( V_47 , V_6 , NULL , V_50 [ 0 ] , 1 , 0 ) ;
for ( V_54 = 1 ; V_54 <= V_17 ; V_54 ++ ) {
F_26 ( V_47 , V_6 , NULL , V_50 [ V_54 ] , 1 ,
V_72 ) ;
}
for ( V_54 = V_17 + 1 ; V_54 < V_49 ; V_54 ++ )
F_26 ( V_47 , V_6 , NULL , V_50 [ V_54 ] , 1 , 0 ) ;
F_26 ( V_47 , V_6 , NULL , V_50 [ V_54 ] , V_70 , 0 ) ;
return V_25 ;
}
static int F_35 ( T_5 * V_47 , struct V_6 * V_6 ,
T_3 V_38 , T_1 * V_73 , int V_70 ,
int V_44 )
{
int V_54 ;
int V_25 = 0 ;
T_4 V_57 ;
if ( V_73 -> V_3 ) {
F_30 ( V_73 -> V_3 , L_9 ) ;
V_25 = F_36 ( V_47 , V_73 -> V_3 ) ;
if ( V_25 )
goto V_74;
}
* V_73 -> V_1 = V_73 -> V_5 ;
if ( V_70 == 0 && V_44 > 1 ) {
V_57 = F_9 ( V_73 -> V_5 ) + 1 ;
for ( V_54 = 1 ; V_54 < V_44 ; V_54 ++ )
* ( V_73 -> V_1 + V_54 ) = F_28 ( V_57 ++ ) ;
}
if ( V_73 -> V_3 ) {
F_37 ( 5 , L_10 ) ;
F_30 ( V_73 -> V_3 , L_8 ) ;
V_25 = F_34 ( V_47 , V_6 , V_73 -> V_3 ) ;
if ( V_25 )
goto V_74;
} else {
F_38 ( V_47 , V_6 ) ;
F_37 ( 5 , L_11 ) ;
}
return V_25 ;
V_74:
for ( V_54 = 1 ; V_54 <= V_70 ; V_54 ++ ) {
F_26 ( V_47 , V_6 , V_73 [ V_54 ] . V_3 , 0 , 1 ,
V_72 ) ;
}
F_26 ( V_47 , V_6 , NULL , F_9 ( V_73 [ V_70 ] . V_5 ) ,
V_44 , 0 ) ;
return V_25 ;
}
int F_39 ( T_5 * V_47 , struct V_6 * V_6 ,
struct V_75 * V_76 ,
int V_66 )
{
int V_25 = - V_32 ;
T_3 V_8 [ 4 ] ;
T_1 V_24 [ 4 ] ;
T_1 * V_39 ;
T_4 V_40 ;
int V_49 ;
int V_45 = 0 ;
int V_23 ;
int V_46 = 0 ;
T_4 V_77 = 0 ;
F_40 ( V_6 , V_76 -> V_78 , V_76 -> V_79 , V_66 ) ;
F_41 ( ! ( F_42 ( V_6 , V_80 ) ) ) ;
F_41 ( V_47 != NULL || ( V_66 & V_81 ) == 0 ) ;
V_23 = F_2 ( V_6 , V_76 -> V_78 , V_8 ,
& V_45 ) ;
if ( V_23 == 0 )
goto V_82;
V_39 = F_6 ( V_6 , V_23 , V_8 , V_24 , & V_25 ) ;
if ( ! V_39 ) {
V_77 = F_9 ( V_24 [ V_23 - 1 ] . V_5 ) ;
V_46 ++ ;
while ( V_46 < V_76 -> V_79 && V_46 <= V_45 ) {
T_4 V_83 ;
V_83 = F_9 ( * ( V_24 [ V_23 - 1 ] . V_1 + V_46 ) ) ;
if ( V_83 == V_77 + V_46 )
V_46 ++ ;
else
break;
}
goto V_84;
}
if ( ( V_66 & V_81 ) == 0 || V_25 == - V_32 )
goto V_85;
V_40 = F_17 ( V_6 , V_76 -> V_78 , V_39 ) ;
V_49 = ( V_24 + V_23 ) - V_39 - 1 ;
V_46 = F_18 ( V_39 , V_49 ,
V_76 -> V_79 , V_45 ) ;
V_25 = F_27 ( V_47 , V_6 , V_76 -> V_78 , V_49 ,
& V_46 , V_40 ,
V_8 + ( V_39 - V_24 ) , V_39 ) ;
if ( ! V_25 )
V_25 = F_35 ( V_47 , V_6 , V_76 -> V_78 ,
V_39 , V_49 , V_46 ) ;
if ( V_25 )
goto V_85;
V_76 -> V_86 |= V_87 ;
F_43 ( V_47 , V_6 , 1 ) ;
V_84:
V_76 -> V_86 |= V_88 ;
V_76 -> V_89 = F_9 ( V_24 [ V_23 - 1 ] . V_5 ) ;
V_76 -> V_79 = V_46 ;
if ( V_46 > V_45 )
V_76 -> V_86 |= V_90 ;
V_25 = V_46 ;
V_39 = V_24 + V_23 - 1 ;
V_85:
while ( V_39 > V_24 ) {
F_30 ( V_39 -> V_3 , L_12 ) ;
F_44 ( V_39 -> V_3 ) ;
V_39 -- ;
}
V_82:
F_45 ( V_6 , V_76 -> V_78 ,
V_76 -> V_89 , V_76 -> V_79 , V_25 ) ;
return V_25 ;
}
T_6 F_46 ( int V_91 , struct V_92 * V_93 ,
const struct V_94 * V_95 , T_7 V_96 ,
unsigned long V_97 )
{
struct V_98 * V_98 = V_93 -> V_99 ;
struct V_6 * V_6 = V_98 -> V_100 -> V_101 ;
struct V_34 * V_35 = F_7 ( V_6 ) ;
T_5 * V_47 ;
T_6 V_58 ;
int V_102 = 0 ;
T_8 V_46 = F_47 ( V_95 , V_97 ) ;
int V_103 = 0 ;
if ( V_91 == V_104 ) {
T_7 V_105 = V_96 + V_46 ;
if ( V_105 > V_6 -> V_106 ) {
V_47 = F_48 ( V_6 , 2 ) ;
if ( F_49 ( V_47 ) ) {
V_58 = F_50 ( V_47 ) ;
goto V_82;
}
V_58 = F_51 ( V_47 , V_6 ) ;
if ( V_58 ) {
F_52 ( V_47 ) ;
goto V_82;
}
V_102 = 1 ;
V_35 -> V_107 = V_6 -> V_106 ;
F_52 ( V_47 ) ;
}
}
V_108:
if ( V_91 == V_109 && F_53 ( V_6 ) ) {
if ( F_10 ( ! F_54 ( & V_35 -> V_110 ) ) ) {
F_55 ( & V_6 -> V_111 ) ;
F_56 ( V_6 ) ;
F_57 ( & V_6 -> V_111 ) ;
}
V_58 = F_58 ( V_91 , V_93 , V_6 ,
V_6 -> V_11 -> V_112 , V_95 ,
V_96 , V_97 ,
V_113 , NULL , NULL , 0 ) ;
} else {
V_58 = F_59 ( V_91 , V_93 , V_6 , V_95 ,
V_96 , V_97 , V_113 ) ;
if ( F_10 ( ( V_91 & V_104 ) && V_58 < 0 ) ) {
T_7 V_114 = F_60 ( V_6 ) ;
T_7 V_115 = V_96 + F_47 ( V_95 , V_97 ) ;
if ( V_115 > V_114 )
F_61 ( V_6 ) ;
}
}
if ( V_58 == - V_116 && F_62 ( V_6 -> V_11 , & V_103 ) )
goto V_108;
if ( V_102 ) {
int V_25 ;
V_47 = F_48 ( V_6 , 2 ) ;
if ( F_49 ( V_47 ) ) {
V_58 = F_50 ( V_47 ) ;
if ( V_6 -> V_117 )
F_63 ( NULL , V_6 ) ;
goto V_82;
}
if ( V_6 -> V_117 )
F_63 ( V_47 , V_6 ) ;
if ( V_58 > 0 ) {
T_7 V_115 = V_96 + V_58 ;
if ( V_115 > V_6 -> V_106 ) {
V_35 -> V_107 = V_115 ;
F_64 ( V_6 , V_115 ) ;
F_38 ( V_47 , V_6 ) ;
}
}
V_25 = F_52 ( V_47 ) ;
if ( V_58 == 0 )
V_58 = V_25 ;
}
V_82:
return V_58 ;
}
int F_65 ( struct V_6 * V_6 , T_9 V_118 )
{
struct V_34 * V_35 = F_7 ( V_6 ) ;
T_9 V_119 = ~ ( ( T_9 ) F_3 ( V_6 -> V_11 ) - 1 ) ;
int V_120 ;
if ( V_118 < V_14 )
return 0 ;
V_118 -= V_14 ;
if ( V_35 -> V_121 &&
( V_118 & V_119 ) == V_35 -> V_122 ) {
V_35 -> V_121 ++ ;
return 0 ;
}
V_35 -> V_122 = V_118 & V_119 ;
V_35 -> V_121 = 1 ;
V_120 = F_66 ( V_118 ) ;
return ( V_120 / F_4 ( V_6 -> V_11 ) ) + 1 ;
}
int F_67 ( struct V_6 * V_6 , int V_123 , int V_124 )
{
int V_125 ;
if ( V_124 ) {
return F_68 ( V_123 ,
F_3 ( V_6 -> V_11 ) ) + 4 ;
}
V_125 = V_123 * 2 + 1 ;
return V_125 ;
}
static T_5 * F_69 ( struct V_6 * V_6 )
{
T_5 * V_126 ;
V_126 = F_48 ( V_6 , F_70 ( V_6 ) ) ;
if ( ! F_49 ( V_126 ) )
return V_126 ;
F_71 ( V_6 -> V_11 , F_50 ( V_126 ) ) ;
return V_126 ;
}
static int F_72 ( T_5 * V_47 , struct V_6 * V_6 )
{
if ( ! F_73 ( V_47 ) )
return 0 ;
if ( F_74 ( V_47 , V_127 + 1 ) )
return 0 ;
if ( ! F_75 ( V_47 , F_70 ( V_6 ) ) )
return 0 ;
return 1 ;
}
static inline int F_76 ( T_2 * V_1 , T_2 * V_128 )
{
while ( V_1 < V_128 )
if ( * V_1 ++ )
return 0 ;
return 1 ;
}
static T_1 * F_77 ( struct V_6 * V_6 , int V_23 ,
T_3 V_8 [ 4 ] , T_1 V_24 [ 4 ] ,
T_2 * V_129 )
{
T_1 * V_39 , * V_1 ;
int V_43 , V_25 ;
* V_129 = 0 ;
for ( V_43 = V_23 ; V_43 > 1 && ! V_8 [ V_43 - 1 ] ; V_43 -- )
;
V_39 = F_6 ( V_6 , V_43 , V_8 , V_24 , & V_25 ) ;
if ( ! V_39 )
V_39 = V_24 + V_43 - 1 ;
if ( ! V_39 -> V_5 && * V_39 -> V_1 )
goto V_130;
for ( V_1 = V_39 ; ( V_1 > V_24 ) && F_76 ( ( T_2 * ) V_1 -> V_3 -> V_31 , V_1 -> V_1 ) ; V_1 -- )
;
if ( V_1 == V_24 + V_43 - 1 && V_1 > V_24 ) {
V_1 -> V_1 -- ;
} else {
* V_129 = * V_1 -> V_1 ;
#if 0
*p->p = 0;
#endif
}
while ( V_39 > V_1 ) {
F_44 ( V_39 -> V_3 ) ;
V_39 -- ;
}
V_130:
return V_39 ;
}
static int F_78 ( T_5 * V_47 , struct V_6 * V_6 ,
struct V_2 * V_3 ,
T_4 V_131 ,
unsigned long V_46 , T_2 * V_132 ,
T_2 * V_133 )
{
T_2 * V_1 ;
int V_66 = V_72 | V_134 ;
int V_25 ;
if ( F_79 ( V_6 -> V_65 ) || F_80 ( V_6 -> V_65 ) )
V_66 |= V_135 ;
if ( ! F_81 ( F_82 ( V_6 -> V_11 ) , V_131 ,
V_46 ) ) {
F_21 ( V_6 , L_13
L_14 ,
( unsigned long long ) V_131 , V_46 ) ;
return 1 ;
}
if ( F_72 ( V_47 , V_6 ) ) {
if ( V_3 ) {
F_30 ( V_3 , L_8 ) ;
V_25 = F_34 ( V_47 , V_6 , V_3 ) ;
if ( F_10 ( V_25 ) )
goto V_136;
}
V_25 = F_38 ( V_47 , V_6 ) ;
if ( F_10 ( V_25 ) )
goto V_136;
V_25 = F_83 ( V_47 , V_6 ,
F_70 ( V_6 ) ) ;
if ( F_10 ( V_25 ) )
goto V_136;
if ( V_3 ) {
F_30 ( V_3 , L_15 ) ;
V_25 = F_36 ( V_47 , V_3 ) ;
if ( F_10 ( V_25 ) )
goto V_136;
}
}
for ( V_1 = V_132 ; V_1 < V_133 ; V_1 ++ )
* V_1 = 0 ;
F_26 ( V_47 , V_6 , NULL , V_131 , V_46 , V_66 ) ;
return 0 ;
V_136:
F_71 ( V_6 -> V_11 , V_25 ) ;
return V_25 ;
}
static void F_84 ( T_5 * V_47 , struct V_6 * V_6 ,
struct V_2 * V_137 ,
T_2 * V_132 , T_2 * V_133 )
{
T_4 V_131 = 0 ;
unsigned long V_46 = 0 ;
T_2 * V_138 = NULL ;
T_4 V_139 ;
T_2 * V_1 ;
int V_25 = 0 ;
if ( V_137 ) {
F_30 ( V_137 , L_9 ) ;
V_25 = F_36 ( V_47 , V_137 ) ;
if ( V_25 )
return;
}
for ( V_1 = V_132 ; V_1 < V_133 ; V_1 ++ ) {
V_139 = F_9 ( * V_1 ) ;
if ( V_139 ) {
if ( V_46 == 0 ) {
V_131 = V_139 ;
V_138 = V_1 ;
V_46 = 1 ;
} else if ( V_139 == V_131 + V_46 ) {
V_46 ++ ;
} else {
V_25 = F_78 ( V_47 , V_6 , V_137 ,
V_131 , V_46 ,
V_138 , V_1 ) ;
if ( V_25 )
break;
V_131 = V_139 ;
V_138 = V_1 ;
V_46 = 1 ;
}
}
}
if ( ! V_25 && V_46 > 0 )
V_25 = F_78 ( V_47 , V_6 , V_137 , V_131 ,
V_46 , V_138 , V_1 ) ;
if ( V_25 < 0 )
return;
if ( V_137 ) {
F_30 ( V_137 , L_8 ) ;
if ( ( F_85 ( V_6 ) == NULL ) || F_86 ( V_137 ) )
F_34 ( V_47 , V_6 , V_137 ) ;
else
F_21 ( V_6 ,
L_16
L_17 ,
( unsigned long long ) V_137 -> V_37 ) ;
}
}
static void F_87 ( T_5 * V_47 , struct V_6 * V_6 ,
struct V_2 * V_140 ,
T_2 * V_132 , T_2 * V_133 , int V_23 )
{
T_4 V_139 ;
T_2 * V_1 ;
if ( F_88 ( V_47 ) )
return;
if ( V_23 -- ) {
struct V_2 * V_3 ;
int V_141 = F_3 ( V_6 -> V_11 ) ;
V_1 = V_133 ;
while ( -- V_1 >= V_132 ) {
V_139 = F_9 ( * V_1 ) ;
if ( ! V_139 )
continue;
if ( ! F_81 ( F_82 ( V_6 -> V_11 ) ,
V_139 , 1 ) ) {
F_21 ( V_6 ,
L_18
L_19 ,
( unsigned long ) V_139 , V_23 ) ;
break;
}
V_3 = F_89 ( V_6 -> V_11 , V_139 ) ;
if ( ! V_3 ) {
F_90 ( V_6 , V_139 ,
L_20 ) ;
continue;
}
F_30 ( V_3 , L_21 ) ;
F_87 ( V_47 , V_6 , V_3 ,
( T_2 * ) V_3 -> V_31 ,
( T_2 * ) V_3 -> V_31 + V_141 ,
V_23 ) ;
F_44 ( V_3 ) ;
if ( F_88 ( V_47 ) )
return;
if ( F_72 ( V_47 , V_6 ) ) {
F_38 ( V_47 , V_6 ) ;
F_83 ( V_47 , V_6 ,
F_70 ( V_6 ) ) ;
}
F_26 ( V_47 , V_6 , NULL , V_139 , 1 ,
V_135 |
V_72 ) ;
if ( V_140 ) {
F_30 ( V_140 , L_9 ) ;
if ( ! F_36 ( V_47 ,
V_140 ) ) {
* V_1 = 0 ;
F_30 ( V_140 ,
L_8 ) ;
F_34 ( V_47 ,
V_6 ,
V_140 ) ;
}
}
}
} else {
F_30 ( V_140 , L_22 ) ;
F_84 ( V_47 , V_6 , V_140 , V_132 , V_133 ) ;
}
}
void F_91 ( struct V_6 * V_6 )
{
T_5 * V_47 ;
struct V_34 * V_35 = F_7 ( V_6 ) ;
T_2 * V_28 = V_35 -> V_28 ;
int V_141 = F_3 ( V_6 -> V_11 ) ;
struct V_142 * V_143 = V_6 -> V_144 ;
T_3 V_8 [ 4 ] ;
T_1 V_24 [ 4 ] ;
T_1 * V_39 ;
T_2 V_139 = 0 ;
int V_17 = 0 ;
T_3 V_145 , V_146 ;
unsigned V_68 = V_6 -> V_11 -> V_69 ;
V_47 = F_69 ( V_6 ) ;
if ( F_49 ( V_47 ) )
return;
V_145 = ( V_6 -> V_106 + V_68 - 1 )
>> F_92 ( V_6 -> V_11 ) ;
V_146 = ( F_82 ( V_6 -> V_11 ) -> V_147 + V_68 - 1 )
>> F_92 ( V_6 -> V_11 ) ;
if ( V_6 -> V_106 & ( V_68 - 1 ) )
if ( F_93 ( V_47 , V_143 , V_6 -> V_106 ) )
goto V_148;
if ( V_145 != V_146 ) {
V_17 = F_2 ( V_6 , V_145 , V_8 , NULL ) ;
if ( V_17 == 0 )
goto V_148;
}
if ( F_51 ( V_47 , V_6 ) )
goto V_148;
F_94 ( & V_35 -> V_149 ) ;
F_95 ( V_6 ) ;
V_35 -> V_107 = V_6 -> V_106 ;
if ( V_145 == V_146 ) {
goto V_150;
} else if ( V_17 == 1 ) {
F_84 ( V_47 , V_6 , NULL , V_28 + V_8 [ 0 ] ,
V_28 + V_14 ) ;
goto V_151;
}
V_39 = F_77 ( V_6 , V_17 , V_8 , V_24 , & V_139 ) ;
if ( V_139 ) {
if ( V_39 == V_24 ) {
F_87 ( V_47 , V_6 , NULL ,
& V_139 , & V_139 + 1 , ( V_24 + V_17 - 1 ) - V_39 ) ;
* V_39 -> V_1 = 0 ;
} else {
F_30 ( V_39 -> V_3 , L_9 ) ;
F_87 ( V_47 , V_6 , V_39 -> V_3 ,
V_39 -> V_1 ,
V_39 -> V_1 + 1 , ( V_24 + V_17 - 1 ) - V_39 ) ;
}
}
while ( V_39 > V_24 ) {
F_87 ( V_47 , V_6 , V_39 -> V_3 , V_39 -> V_1 + 1 ,
( T_2 * ) V_39 -> V_3 -> V_31 + V_141 ,
( V_24 + V_17 - 1 ) - V_39 ) ;
F_30 ( V_39 -> V_3 , L_12 ) ;
F_44 ( V_39 -> V_3 ) ;
V_39 -- ;
}
V_151:
switch ( V_8 [ 0 ] ) {
default:
V_139 = V_28 [ V_19 ] ;
if ( V_139 ) {
F_87 ( V_47 , V_6 , NULL , & V_139 , & V_139 + 1 , 1 ) ;
V_28 [ V_19 ] = 0 ;
}
case V_19 :
V_139 = V_28 [ V_20 ] ;
if ( V_139 ) {
F_87 ( V_47 , V_6 , NULL , & V_139 , & V_139 + 1 , 2 ) ;
V_28 [ V_20 ] = 0 ;
}
case V_20 :
V_139 = V_28 [ V_21 ] ;
if ( V_139 ) {
F_87 ( V_47 , V_6 , NULL , & V_139 , & V_139 + 1 , 3 ) ;
V_28 [ V_21 ] = 0 ;
}
case V_21 :
;
}
V_150:
F_96 ( & V_35 -> V_149 ) ;
V_6 -> V_152 = V_6 -> V_153 = F_97 ( V_6 ) ;
F_38 ( V_47 , V_6 ) ;
if ( F_98 ( V_6 ) )
F_99 ( V_47 ) ;
V_148:
if ( V_6 -> V_117 )
F_63 ( V_47 , V_6 ) ;
F_52 ( V_47 ) ;
F_100 ( V_6 ) ;
}
