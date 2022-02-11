static struct V_1 *
F_1 ( struct V_2 * V_3 , unsigned long V_4 )
{
struct V_5 * V_6 ;
struct V_1 * V_7 = NULL ;
V_6 = F_2 ( V_3 , V_4 , NULL ) ;
if ( ! V_6 )
goto V_8;
V_7 = F_3 ( V_3 , F_4 ( V_6 -> V_9 ) ) ;
if ( ! V_7 )
F_5 ( V_3 , L_1 ,
L_2
L_3 ,
V_4 , F_4 ( V_6 -> V_9 ) ) ;
V_8:
return V_7 ;
}
void F_6 ( T_1 * V_10 , struct V_11 * V_11 )
{
struct V_2 * V_3 = V_11 -> V_12 ;
int V_13 ;
unsigned long V_14 ;
struct V_1 * V_15 = NULL ;
struct V_1 * V_16 ;
unsigned long V_4 ;
unsigned long V_17 ;
struct V_5 * V_18 ;
struct V_19 * V_20 ;
struct V_21 * V_22 ;
int V_23 = 0 , V_24 ;
if ( F_7 ( & V_11 -> V_25 ) > 1 ) {
F_8 ( L_4 ,
F_7 ( & V_11 -> V_25 ) ) ;
return;
}
if ( V_11 -> V_26 ) {
F_8 ( L_5 ,
V_11 -> V_26 ) ;
return;
}
if ( ! V_3 ) {
F_8 ( L_6 ) ;
return;
}
V_22 = F_9 ( V_3 ) ;
V_14 = V_11 -> V_27 ;
F_10 ( L_7 , V_14 ) ;
F_11 ( V_11 ) ;
V_13 = F_12 ( V_11 -> V_28 ) ;
V_20 = F_9 ( V_3 ) -> V_29 ;
if ( V_14 < V_30 ( V_3 ) || V_14 > F_4 ( V_20 -> V_31 ) ) {
F_5 ( V_3 , L_8 ,
L_9 , V_14 ) ;
goto V_32;
}
V_4 = ( V_14 - 1 ) / F_13 ( V_3 ) ;
V_17 = ( V_14 - 1 ) % F_13 ( V_3 ) ;
V_15 = F_1 ( V_3 , V_4 ) ;
if ( ! V_15 )
goto V_32;
F_14 ( V_15 , L_10 ) ;
V_23 = F_15 ( V_10 , V_15 ) ;
if ( V_23 )
goto V_32;
if ( ! F_16 ( F_17 ( V_22 , V_4 ) ,
V_17 , V_15 -> V_33 ) )
F_5 ( V_3 , L_8 ,
L_11 , V_14 ) ;
else {
V_18 = F_2 ( V_3 , V_4 , & V_16 ) ;
F_14 ( V_16 , L_10 ) ;
V_23 = F_15 ( V_10 , V_16 ) ;
if ( V_23 ) goto V_32;
if ( V_18 ) {
F_18 ( F_17 ( V_22 , V_4 ) ) ;
F_19 ( & V_18 -> V_34 , 1 ) ;
if ( V_13 )
F_19 ( & V_18 -> V_35 , - 1 ) ;
F_20 ( F_17 ( V_22 , V_4 ) ) ;
F_21 ( & V_22 -> V_36 ) ;
if ( V_13 )
F_22 ( & V_22 -> V_37 ) ;
}
F_14 ( V_16 , L_12 ) ;
V_24 = F_23 ( V_10 , V_16 ) ;
if ( ! V_23 ) V_23 = V_24 ;
}
F_14 ( V_15 , L_12 ) ;
V_24 = F_23 ( V_10 , V_15 ) ;
if ( ! V_23 )
V_23 = V_24 ;
V_32:
F_24 ( V_15 ) ;
F_25 ( V_3 , V_23 ) ;
}
static int F_26 ( struct V_2 * V_3 , struct V_11 * V_38 )
{
int V_39 = F_9 ( V_3 ) -> V_40 ;
unsigned int V_41 , V_42 ;
struct V_5 * V_6 , * V_43 = NULL ;
int V_44 , V_45 = - 1 ;
V_41 = F_27 ( & F_9 ( V_3 ) -> V_36 ) ;
V_42 = V_41 / V_39 ;
for ( V_44 = 0 ; V_44 < V_39 ; V_44 ++ ) {
V_6 = F_2 ( V_3 , V_44 , NULL ) ;
if ( ! V_6 || ! V_6 -> V_34 )
continue;
if ( F_28 ( V_6 -> V_34 ) < V_42 )
continue;
if ( ! V_43 ||
( F_28 ( V_6 -> V_46 ) >
F_28 ( V_43 -> V_46 ) ) ) {
V_45 = V_44 ;
V_43 = V_6 ;
}
}
return V_45 ;
}
static int F_29 ( struct V_2 * V_3 , struct V_11 * V_38 )
{
int V_47 = F_30 ( V_38 ) -> V_48 ;
struct V_21 * V_22 = F_9 ( V_3 ) ;
struct V_19 * V_20 = V_22 -> V_29 ;
int V_39 = V_22 -> V_40 ;
int V_49 = F_13 ( V_3 ) ;
unsigned int V_41 , V_42 ;
T_2 V_50 , V_51 ;
T_2 V_52 ;
unsigned int V_53 ;
int V_54 , V_55 , V_56 ;
T_3 V_57 ;
int V_44 = - 1 , V_58 ;
struct V_5 * V_6 ;
V_41 = F_27 ( & V_22 -> V_36 ) ;
V_42 = V_41 / V_39 ;
V_50 = F_27 ( & V_22 -> V_59 ) ;
V_51 = V_50 / V_39 ;
V_53 = F_27 ( & V_22 -> V_37 ) ;
if ( ( V_38 == V_3 -> V_60 -> V_61 ) ||
( F_30 ( V_38 ) -> V_62 & V_63 ) ) {
int V_64 = V_49 ;
int V_45 = - 1 ;
F_31 ( & V_44 , sizeof( V_44 ) ) ;
V_47 = ( unsigned ) V_44 % V_39 ;
for ( V_58 = 0 ; V_58 < V_39 ; V_58 ++ ) {
V_44 = ( V_47 + V_58 ) % V_39 ;
V_6 = F_2 ( V_3 , V_44 , NULL ) ;
if ( ! V_6 || ! V_6 -> V_34 )
continue;
if ( F_28 ( V_6 -> V_35 ) >= V_64 )
continue;
if ( F_28 ( V_6 -> V_34 ) < V_42 )
continue;
if ( F_28 ( V_6 -> V_46 ) < V_51 )
continue;
V_45 = V_44 ;
V_64 = F_28 ( V_6 -> V_35 ) ;
}
if ( V_45 >= 0 )
return V_45 ;
goto V_65;
}
V_52 = ( F_4 ( V_20 -> V_66 ) - V_50 ) / V_53 ;
V_55 = V_53 / V_39 + V_49 / 16 ;
V_56 = V_42 - V_49 / 4 ;
V_57 = V_51 - F_32 ( V_3 ) / 4 ;
V_54 = F_32 ( V_3 ) / F_33 ( V_52 , ( T_2 ) V_67 ) ;
if ( V_54 * V_68 > V_49 )
V_54 = V_49 / V_68 ;
if ( V_54 > 255 )
V_54 = 255 ;
if ( V_54 == 0 )
V_54 = 1 ;
for ( V_58 = 0 ; V_58 < V_39 ; V_58 ++ ) {
V_44 = ( V_47 + V_58 ) % V_39 ;
V_6 = F_2 ( V_3 , V_44 , NULL ) ;
if ( ! V_6 || ! V_6 -> V_34 )
continue;
if ( F_28 ( V_6 -> V_35 ) >= V_55 )
continue;
if ( F_28 ( V_6 -> V_34 ) < V_56 )
continue;
if ( F_28 ( V_6 -> V_46 ) < V_57 )
continue;
return V_44 ;
}
V_65:
for ( V_58 = 0 ; V_58 < V_39 ; V_58 ++ ) {
V_44 = ( V_47 + V_58 ) % V_39 ;
V_6 = F_2 ( V_3 , V_44 , NULL ) ;
if ( ! V_6 || ! V_6 -> V_34 )
continue;
if ( F_28 ( V_6 -> V_34 ) >= V_42 )
return V_44 ;
}
if ( V_42 ) {
V_42 = 0 ;
goto V_65;
}
return - 1 ;
}
static int F_34 ( struct V_2 * V_3 , struct V_11 * V_38 )
{
int V_47 = F_30 ( V_38 ) -> V_48 ;
int V_39 = F_9 ( V_3 ) -> V_40 ;
struct V_5 * V_6 ;
int V_44 , V_58 ;
V_44 = V_47 ;
V_6 = F_2 ( V_3 , V_44 , NULL ) ;
if ( V_6 && F_28 ( V_6 -> V_34 ) &&
F_28 ( V_6 -> V_46 ) )
return V_44 ;
V_44 = ( V_44 + V_38 -> V_27 ) % V_39 ;
for ( V_58 = 1 ; V_58 < V_39 ; V_58 <<= 1 ) {
V_44 += V_58 ;
if ( V_44 >= V_39 )
V_44 -= V_39 ;
V_6 = F_2 ( V_3 , V_44 , NULL ) ;
if ( V_6 && F_28 ( V_6 -> V_34 ) &&
F_28 ( V_6 -> V_46 ) )
return V_44 ;
}
V_44 = V_47 ;
for ( V_58 = 0 ; V_58 < V_39 ; V_58 ++ ) {
if ( ++ V_44 >= V_39 )
V_44 = 0 ;
V_6 = F_2 ( V_3 , V_44 , NULL ) ;
if ( V_6 && F_28 ( V_6 -> V_34 ) )
return V_44 ;
}
return - 1 ;
}
struct V_11 * F_35 ( T_1 * V_10 , struct V_11 * V_69 ,
const struct V_70 * V_70 , int V_71 )
{
struct V_2 * V_3 ;
struct V_1 * V_15 = NULL ;
struct V_1 * V_16 ;
int V_44 ;
unsigned long V_14 = 0 ;
struct V_11 * V_11 ;
struct V_5 * V_18 = NULL ;
struct V_19 * V_20 ;
struct V_72 * V_73 ;
struct V_21 * V_22 ;
int V_24 = 0 ;
struct V_11 * V_74 ;
int V_58 ;
if ( ! V_69 || ! V_69 -> V_26 )
return F_36 ( - V_75 ) ;
V_3 = V_69 -> V_12 ;
F_37 ( V_69 , V_71 ) ;
V_11 = F_38 ( V_3 ) ;
if ( ! V_11 )
return F_36 ( - V_76 ) ;
V_73 = F_30 ( V_11 ) ;
V_22 = F_9 ( V_3 ) ;
V_20 = V_22 -> V_29 ;
if ( F_12 ( V_71 ) ) {
if ( F_39 ( V_3 , V_77 ) )
V_44 = F_26 ( V_3 , V_69 ) ;
else
V_44 = F_29 ( V_3 , V_69 ) ;
} else
V_44 = F_34 ( V_3 , V_69 ) ;
V_24 = - V_78 ;
if ( V_44 == - 1 )
goto V_79;
for ( V_58 = 0 ; V_58 < V_22 -> V_40 ; V_58 ++ ) {
V_24 = - V_80 ;
V_18 = F_2 ( V_3 , V_44 , & V_16 ) ;
if ( ! V_18 )
goto V_81;
F_24 ( V_15 ) ;
V_15 = F_1 ( V_3 , V_44 ) ;
if ( ! V_15 )
goto V_81;
V_14 = 0 ;
V_82:
V_14 = F_40 ( ( unsigned long * )
V_15 -> V_33 , F_13 ( V_3 ) , V_14 ) ;
if ( V_14 < F_13 ( V_3 ) ) {
F_14 ( V_15 , L_10 ) ;
V_24 = F_15 ( V_10 , V_15 ) ;
if ( V_24 )
goto V_81;
if ( ! F_41 ( F_17 ( V_22 , V_44 ) ,
V_14 , V_15 -> V_33 ) ) {
F_14 ( V_15 ,
L_12 ) ;
V_24 = F_23 ( V_10 ,
V_15 ) ;
if ( V_24 )
goto V_81;
goto V_83;
}
F_42 ( V_10 , V_15 ) ;
if ( ++ V_14 < F_13 ( V_3 ) )
goto V_82;
}
if ( ++ V_44 == V_22 -> V_40 )
V_44 = 0 ;
}
V_24 = - V_78 ;
goto V_79;
V_83:
V_14 += V_44 * F_13 ( V_3 ) + 1 ;
if ( V_14 < V_30 ( V_3 ) || V_14 > F_4 ( V_20 -> V_31 ) ) {
F_5 ( V_3 , L_13 ,
L_14
L_15 , V_44 , V_14 ) ;
V_24 = - V_80 ;
goto V_81;
}
F_14 ( V_16 , L_10 ) ;
V_24 = F_15 ( V_10 , V_16 ) ;
if ( V_24 ) goto V_81;
F_18 ( F_17 ( V_22 , V_44 ) ) ;
F_19 ( & V_18 -> V_34 , - 1 ) ;
if ( F_12 ( V_71 ) ) {
F_19 ( & V_18 -> V_35 , 1 ) ;
}
F_20 ( F_17 ( V_22 , V_44 ) ) ;
F_14 ( V_16 , L_12 ) ;
V_24 = F_23 ( V_10 , V_16 ) ;
if ( V_24 ) goto V_81;
F_22 ( & V_22 -> V_36 ) ;
if ( F_12 ( V_71 ) )
F_21 ( & V_22 -> V_37 ) ;
if ( F_39 ( V_3 , V_84 ) ) {
V_11 -> V_28 = V_71 ;
V_11 -> V_85 = F_43 () ;
V_11 -> V_86 = V_69 -> V_86 ;
} else
F_44 ( V_11 , V_69 , V_71 ) ;
V_11 -> V_27 = V_14 ;
V_11 -> V_87 = 0 ;
V_11 -> V_88 = V_11 -> V_89 = V_11 -> V_90 = V_91 ;
memset ( V_73 -> V_92 , 0 , sizeof( V_73 -> V_92 ) ) ;
V_73 -> V_93 = 0 ;
V_73 -> V_94 = 0 ;
V_73 -> V_62 =
F_45 ( V_71 , F_30 ( V_69 ) -> V_62 & V_95 ) ;
#ifdef F_46
V_73 -> V_96 = 0 ;
V_73 -> V_97 = 0 ;
V_73 -> V_98 = 0 ;
#endif
V_73 -> V_99 = 0 ;
V_73 -> V_100 = 0 ;
V_73 -> V_101 = 0 ;
V_73 -> V_102 = NULL ;
V_73 -> V_48 = V_44 ;
F_47 ( V_11 ) ;
if ( F_48 ( V_11 ) )
V_10 -> V_103 = 1 ;
if ( F_49 ( V_11 ) < 0 ) {
V_24 = - V_104 ;
goto V_105;
}
F_18 ( & V_22 -> V_106 ) ;
V_11 -> V_107 = V_22 -> V_108 ++ ;
F_20 ( & V_22 -> V_106 ) ;
V_73 -> V_109 = 0 ;
F_50 ( V_11 , V_110 ) ;
if ( V_14 >= V_30 ( V_3 ) + 1 &&
F_51 ( V_3 ) > V_111 ) {
V_73 -> V_112 =
sizeof( struct V_113 ) - V_111 ;
} else {
V_73 -> V_112 = 0 ;
}
V_74 = V_11 ;
F_52 ( V_11 ) ;
V_24 = F_53 ( V_11 ) ;
if ( V_24 )
goto V_105;
V_24 = F_54 ( V_10 , V_11 , V_69 ) ;
if ( V_24 )
goto V_114;
V_24 = F_55 ( V_10 , V_11 , V_69 , V_70 ) ;
if ( V_24 )
goto V_114;
V_24 = F_56 ( V_10 , V_11 ) ;
if ( V_24 ) {
F_25 ( V_3 , V_24 ) ;
goto V_114;
}
F_10 ( L_16 , V_11 -> V_27 ) ;
F_57 ( V_11 , V_69 , V_71 ) ;
goto V_115;
V_81:
F_25 ( V_3 , V_24 ) ;
V_79:
F_58 ( V_11 ) ;
V_74 = F_36 ( V_24 ) ;
V_115:
F_24 ( V_15 ) ;
return V_74 ;
V_114:
F_59 ( V_11 ) ;
V_105:
F_60 ( V_11 ) ;
V_11 -> V_62 |= V_116 ;
V_11 -> V_26 = 0 ;
F_61 ( V_11 ) ;
F_58 ( V_11 ) ;
F_24 ( V_15 ) ;
return F_36 ( V_24 ) ;
}
struct V_11 * F_62 ( struct V_2 * V_3 , unsigned long V_14 )
{
unsigned long V_117 = F_4 ( F_9 ( V_3 ) -> V_29 -> V_31 ) ;
unsigned long V_4 ;
int V_17 ;
struct V_1 * V_15 ;
struct V_11 * V_11 = NULL ;
long V_24 = - V_80 ;
if ( V_14 > V_117 ) {
F_63 ( V_3 , V_118 ,
L_17 , V_14 ) ;
goto error;
}
V_4 = ( V_14 - 1 ) / F_13 ( V_3 ) ;
V_17 = ( V_14 - 1 ) % F_13 ( V_3 ) ;
V_15 = F_1 ( V_3 , V_4 ) ;
if ( ! V_15 ) {
F_63 ( V_3 , V_118 ,
L_18 , V_14 ) ;
goto error;
}
if ( ! F_64 ( V_17 , V_15 -> V_33 ) )
goto V_119;
V_11 = F_65 ( V_3 , V_14 ) ;
if ( F_66 ( V_11 ) )
goto V_120;
if ( V_11 -> V_26 && ! F_67 ( V_11 ) )
goto V_119;
if ( F_68 ( V_11 ) > V_117 )
goto V_119;
F_24 ( V_15 ) ;
return V_11 ;
V_120:
V_24 = F_69 ( V_11 ) ;
V_11 = NULL ;
V_119:
F_63 ( V_3 , V_118 ,
L_19 , V_14 ) ;
F_8 ( V_121 L_20 ,
V_17 , ( unsigned long long ) V_15 -> V_122 ,
F_64 ( V_17 , V_15 -> V_33 ) ) ;
F_8 ( V_121 L_21 , V_11 ) ;
if ( V_11 ) {
F_8 ( V_121 L_22 ,
F_70 ( V_11 ) ) ;
F_8 ( V_121 L_23 ,
F_68 ( V_11 ) ) ;
F_8 ( V_121 L_24 , V_117 ) ;
F_8 ( V_121 L_25 , V_11 -> V_26 ) ;
if ( V_11 -> V_26 == 0 )
V_11 -> V_87 = 0 ;
F_58 ( V_11 ) ;
}
F_24 ( V_15 ) ;
error:
return F_36 ( V_24 ) ;
}
unsigned long F_71 ( struct V_2 * V_3 )
{
unsigned long V_123 ;
struct V_5 * V_18 ;
int V_58 ;
#ifdef F_72
struct V_19 * V_20 ;
unsigned long V_124 , V_125 ;
struct V_1 * V_15 = NULL ;
V_20 = F_9 ( V_3 ) -> V_29 ;
V_123 = 0 ;
V_124 = 0 ;
V_18 = NULL ;
for ( V_58 = 0 ; V_58 < F_9 ( V_3 ) -> V_40 ; V_58 ++ ) {
V_18 = F_2 ( V_3 , V_58 , NULL ) ;
if ( ! V_18 )
continue;
V_123 += F_28 ( V_18 -> V_34 ) ;
F_24 ( V_15 ) ;
V_15 = F_1 ( V_3 , V_58 ) ;
if ( ! V_15 )
continue;
V_125 = F_73 ( V_15 , F_13 ( V_3 ) / 8 ) ;
F_8 ( L_26 ,
V_58 , F_28 ( V_18 -> V_34 ) , V_125 ) ;
V_124 += V_125 ;
}
F_24 ( V_15 ) ;
F_8 ( L_27 ,
F_4 ( V_20 -> V_126 ) , V_123 , V_124 ) ;
return V_123 ;
#else
V_123 = 0 ;
for ( V_58 = 0 ; V_58 < F_9 ( V_3 ) -> V_40 ; V_58 ++ ) {
V_18 = F_2 ( V_3 , V_58 , NULL ) ;
if ( ! V_18 )
continue;
V_123 += F_28 ( V_18 -> V_34 ) ;
F_74 () ;
}
return V_123 ;
#endif
}
unsigned long F_75 ( struct V_2 * V_3 )
{
unsigned long V_127 = 0 ;
int V_58 ;
for ( V_58 = 0 ; V_58 < F_9 ( V_3 ) -> V_40 ; V_58 ++ ) {
struct V_5 * V_18 = F_2 ( V_3 , V_58 , NULL ) ;
if ( ! V_18 )
continue;
V_127 += F_28 ( V_18 -> V_35 ) ;
}
return V_127 ;
}
