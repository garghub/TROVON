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
int V_39 = F_27 ( V_38 ) -> V_40 ;
struct V_21 * V_22 = F_9 ( V_3 ) ;
struct V_19 * V_20 = V_22 -> V_29 ;
int V_41 = V_22 -> V_42 ;
int V_43 = F_13 ( V_3 ) ;
unsigned int V_44 , V_45 ;
T_2 V_46 , V_47 ;
T_2 V_48 ;
unsigned int V_49 ;
int V_50 , V_51 , V_52 ;
T_3 V_53 ;
int V_54 = - 1 , V_55 ;
struct V_5 * V_6 ;
V_44 = F_28 ( & V_22 -> V_36 ) ;
V_45 = V_44 / V_41 ;
V_46 = F_28 ( & V_22 -> V_56 ) ;
V_47 = V_46 / V_41 ;
V_49 = F_28 ( & V_22 -> V_37 ) ;
if ( ( V_38 == V_3 -> V_57 -> V_58 ) ||
( F_27 ( V_38 ) -> V_59 & V_60 ) ) {
int V_61 = V_43 ;
int V_62 = - 1 ;
F_29 ( & V_54 , sizeof( V_54 ) ) ;
V_39 = ( unsigned ) V_54 % V_41 ;
for ( V_55 = 0 ; V_55 < V_41 ; V_55 ++ ) {
V_54 = ( V_39 + V_55 ) % V_41 ;
V_6 = F_2 ( V_3 , V_54 , NULL ) ;
if ( ! V_6 || ! V_6 -> V_34 )
continue;
if ( F_30 ( V_6 -> V_35 ) >= V_61 )
continue;
if ( F_30 ( V_6 -> V_34 ) < V_45 )
continue;
if ( F_30 ( V_6 -> V_63 ) < V_47 )
continue;
V_62 = V_54 ;
V_61 = F_30 ( V_6 -> V_35 ) ;
}
if ( V_62 >= 0 )
return V_62 ;
goto V_64;
}
V_48 = ( F_4 ( V_20 -> V_65 ) - V_46 ) / V_49 ;
V_51 = V_49 / V_41 + V_43 / 16 ;
V_52 = V_45 - V_43 / 4 ;
V_53 = V_47 - F_31 ( V_3 ) / 4 ;
V_50 = F_31 ( V_3 ) / F_32 ( V_48 , ( T_2 ) V_66 ) ;
if ( V_50 * V_67 > V_43 )
V_50 = V_43 / V_67 ;
if ( V_50 > 255 )
V_50 = 255 ;
if ( V_50 == 0 )
V_50 = 1 ;
for ( V_55 = 0 ; V_55 < V_41 ; V_55 ++ ) {
V_54 = ( V_39 + V_55 ) % V_41 ;
V_6 = F_2 ( V_3 , V_54 , NULL ) ;
if ( ! V_6 || ! V_6 -> V_34 )
continue;
if ( F_30 ( V_6 -> V_35 ) >= V_51 )
continue;
if ( F_30 ( V_6 -> V_34 ) < V_52 )
continue;
if ( F_30 ( V_6 -> V_63 ) < V_53 )
continue;
return V_54 ;
}
V_64:
for ( V_55 = 0 ; V_55 < V_41 ; V_55 ++ ) {
V_54 = ( V_39 + V_55 ) % V_41 ;
V_6 = F_2 ( V_3 , V_54 , NULL ) ;
if ( ! V_6 || ! V_6 -> V_34 )
continue;
if ( F_30 ( V_6 -> V_34 ) >= V_45 )
return V_54 ;
}
if ( V_45 ) {
V_45 = 0 ;
goto V_64;
}
return - 1 ;
}
static int F_33 ( struct V_2 * V_3 , struct V_11 * V_38 )
{
int V_39 = F_27 ( V_38 ) -> V_40 ;
int V_41 = F_9 ( V_3 ) -> V_42 ;
struct V_5 * V_6 ;
int V_54 , V_55 ;
V_54 = V_39 ;
V_6 = F_2 ( V_3 , V_54 , NULL ) ;
if ( V_6 && F_30 ( V_6 -> V_34 ) &&
F_30 ( V_6 -> V_63 ) )
return V_54 ;
V_54 = ( V_54 + V_38 -> V_27 ) % V_41 ;
for ( V_55 = 1 ; V_55 < V_41 ; V_55 <<= 1 ) {
V_54 += V_55 ;
if ( V_54 >= V_41 )
V_54 -= V_41 ;
V_6 = F_2 ( V_3 , V_54 , NULL ) ;
if ( V_6 && F_30 ( V_6 -> V_34 ) &&
F_30 ( V_6 -> V_63 ) )
return V_54 ;
}
V_54 = V_39 ;
for ( V_55 = 0 ; V_55 < V_41 ; V_55 ++ ) {
if ( ++ V_54 >= V_41 )
V_54 = 0 ;
V_6 = F_2 ( V_3 , V_54 , NULL ) ;
if ( V_6 && F_30 ( V_6 -> V_34 ) )
return V_54 ;
}
return - 1 ;
}
struct V_11 * F_34 ( T_1 * V_10 , struct V_11 * V_68 ,
const struct V_69 * V_69 , T_4 V_70 )
{
struct V_2 * V_3 ;
struct V_1 * V_15 = NULL ;
struct V_1 * V_16 ;
int V_54 ;
unsigned long V_14 = 0 ;
struct V_11 * V_11 ;
struct V_5 * V_18 = NULL ;
struct V_19 * V_20 ;
struct V_71 * V_72 ;
struct V_21 * V_22 ;
int V_24 = 0 ;
struct V_11 * V_73 ;
int V_55 ;
if ( ! V_68 || ! V_68 -> V_26 )
return F_35 ( - V_74 ) ;
V_3 = V_68 -> V_12 ;
F_36 ( V_68 , V_70 ) ;
V_11 = F_37 ( V_3 ) ;
if ( ! V_11 )
return F_35 ( - V_75 ) ;
V_72 = F_27 ( V_11 ) ;
V_22 = F_9 ( V_3 ) ;
V_20 = V_22 -> V_29 ;
if ( F_12 ( V_70 ) )
V_54 = F_26 ( V_3 , V_68 ) ;
else
V_54 = F_33 ( V_3 , V_68 ) ;
V_24 = - V_76 ;
if ( V_54 == - 1 )
goto V_77;
for ( V_55 = 0 ; V_55 < V_22 -> V_42 ; V_55 ++ ) {
V_24 = - V_78 ;
V_18 = F_2 ( V_3 , V_54 , & V_16 ) ;
if ( ! V_18 )
goto V_79;
F_24 ( V_15 ) ;
V_15 = F_1 ( V_3 , V_54 ) ;
if ( ! V_15 )
goto V_79;
V_14 = 0 ;
V_80:
V_14 = F_38 ( ( unsigned long * )
V_15 -> V_33 , F_13 ( V_3 ) , V_14 ) ;
if ( V_14 < F_13 ( V_3 ) ) {
F_14 ( V_15 , L_10 ) ;
V_24 = F_15 ( V_10 , V_15 ) ;
if ( V_24 )
goto V_79;
if ( ! F_39 ( F_17 ( V_22 , V_54 ) ,
V_14 , V_15 -> V_33 ) ) {
F_14 ( V_15 ,
L_12 ) ;
V_24 = F_23 ( V_10 ,
V_15 ) ;
if ( V_24 )
goto V_79;
goto V_81;
}
F_40 ( V_10 , V_15 ) ;
if ( ++ V_14 < F_13 ( V_3 ) )
goto V_80;
}
if ( ++ V_54 == V_22 -> V_42 )
V_54 = 0 ;
}
V_24 = - V_76 ;
goto V_77;
V_81:
V_14 += V_54 * F_13 ( V_3 ) + 1 ;
if ( V_14 < V_30 ( V_3 ) || V_14 > F_4 ( V_20 -> V_31 ) ) {
F_5 ( V_3 , L_13 ,
L_14
L_15 , V_54 , V_14 ) ;
V_24 = - V_78 ;
goto V_79;
}
F_14 ( V_16 , L_10 ) ;
V_24 = F_15 ( V_10 , V_16 ) ;
if ( V_24 ) goto V_79;
F_18 ( F_17 ( V_22 , V_54 ) ) ;
F_19 ( & V_18 -> V_34 , - 1 ) ;
if ( F_12 ( V_70 ) ) {
F_19 ( & V_18 -> V_35 , 1 ) ;
}
F_20 ( F_17 ( V_22 , V_54 ) ) ;
F_14 ( V_16 , L_12 ) ;
V_24 = F_23 ( V_10 , V_16 ) ;
if ( V_24 ) goto V_79;
F_22 ( & V_22 -> V_36 ) ;
if ( F_12 ( V_70 ) )
F_21 ( & V_22 -> V_37 ) ;
if ( F_41 ( V_3 , V_82 ) ) {
V_11 -> V_28 = V_70 ;
V_11 -> V_83 = F_42 () ;
V_11 -> V_84 = V_68 -> V_84 ;
} else
F_43 ( V_11 , V_68 , V_70 ) ;
V_11 -> V_27 = V_14 ;
V_11 -> V_85 = 0 ;
V_11 -> V_86 = V_11 -> V_87 = V_11 -> V_88 = V_89 ;
memset ( V_72 -> V_90 , 0 , sizeof( V_72 -> V_90 ) ) ;
V_72 -> V_91 = 0 ;
V_72 -> V_92 = 0 ;
V_72 -> V_59 =
F_44 ( V_70 , F_27 ( V_68 ) -> V_59 & V_93 ) ;
#ifdef F_45
V_72 -> V_94 = 0 ;
V_72 -> V_95 = 0 ;
V_72 -> V_96 = 0 ;
#endif
V_72 -> V_97 = 0 ;
V_72 -> V_98 = 0 ;
V_72 -> V_99 = 0 ;
V_72 -> V_100 = NULL ;
V_72 -> V_40 = V_54 ;
F_46 ( V_11 ) ;
if ( F_47 ( V_11 ) )
V_10 -> V_101 = 1 ;
if ( F_48 ( V_11 ) < 0 ) {
V_24 = - V_78 ;
goto V_79;
}
F_18 ( & V_22 -> V_102 ) ;
V_11 -> V_103 = V_22 -> V_104 ++ ;
F_20 ( & V_22 -> V_102 ) ;
V_72 -> V_105 = 0 ;
F_49 ( V_11 , V_106 ) ;
if ( V_14 >= V_30 ( V_3 ) + 1 &&
F_50 ( V_3 ) > V_107 ) {
V_72 -> V_108 =
sizeof( struct V_109 ) - V_107 ;
} else {
V_72 -> V_108 = 0 ;
}
V_73 = V_11 ;
F_51 ( V_11 ) ;
V_24 = F_52 ( V_11 ) ;
if ( V_24 )
goto V_110;
V_24 = F_53 ( V_10 , V_11 , V_68 ) ;
if ( V_24 )
goto V_111;
V_24 = F_54 ( V_10 , V_11 , V_68 , V_69 ) ;
if ( V_24 )
goto V_111;
V_24 = F_55 ( V_10 , V_11 ) ;
if ( V_24 ) {
F_25 ( V_3 , V_24 ) ;
goto V_111;
}
F_10 ( L_16 , V_11 -> V_27 ) ;
F_56 ( V_11 , V_68 , V_70 ) ;
goto V_112;
V_79:
F_25 ( V_3 , V_24 ) ;
V_77:
F_57 ( V_11 ) ;
V_73 = F_35 ( V_24 ) ;
V_112:
F_24 ( V_15 ) ;
return V_73 ;
V_111:
F_58 ( V_11 ) ;
V_110:
F_59 ( V_11 ) ;
V_11 -> V_59 |= V_113 ;
F_60 ( V_11 ) ;
F_61 ( V_11 ) ;
F_57 ( V_11 ) ;
F_24 ( V_15 ) ;
return F_35 ( V_24 ) ;
}
struct V_11 * F_62 ( struct V_2 * V_3 , unsigned long V_14 )
{
unsigned long V_114 = F_4 ( F_9 ( V_3 ) -> V_29 -> V_31 ) ;
unsigned long V_4 ;
int V_17 ;
struct V_1 * V_15 ;
struct V_11 * V_11 = NULL ;
long V_24 = - V_78 ;
if ( V_14 > V_114 ) {
F_63 ( V_3 , V_115 ,
L_17 , V_14 ) ;
goto error;
}
V_4 = ( V_14 - 1 ) / F_13 ( V_3 ) ;
V_17 = ( V_14 - 1 ) % F_13 ( V_3 ) ;
V_15 = F_1 ( V_3 , V_4 ) ;
if ( ! V_15 ) {
F_63 ( V_3 , V_115 ,
L_18 , V_14 ) ;
goto error;
}
if ( ! F_64 ( V_17 , V_15 -> V_33 ) )
goto V_116;
V_11 = F_65 ( V_3 , V_14 ) ;
if ( F_66 ( V_11 ) )
goto V_117;
if ( V_11 -> V_26 && ! F_67 ( V_11 ) )
goto V_116;
if ( F_68 ( V_11 ) > V_114 )
goto V_116;
F_24 ( V_15 ) ;
return V_11 ;
V_117:
V_24 = F_69 ( V_11 ) ;
V_11 = NULL ;
V_116:
F_63 ( V_3 , V_115 ,
L_19 , V_14 ) ;
F_8 ( V_118 L_20 ,
V_17 , ( unsigned long long ) V_15 -> V_119 ,
F_64 ( V_17 , V_15 -> V_33 ) ) ;
F_8 ( V_118 L_21 , V_11 ) ;
if ( V_11 ) {
F_8 ( V_118 L_22 ,
F_70 ( V_11 ) ) ;
F_8 ( V_118 L_23 ,
F_68 ( V_11 ) ) ;
F_8 ( V_118 L_24 , V_114 ) ;
F_8 ( V_118 L_25 , V_11 -> V_26 ) ;
if ( V_11 -> V_26 == 0 )
V_11 -> V_85 = 0 ;
F_57 ( V_11 ) ;
}
F_24 ( V_15 ) ;
error:
return F_35 ( V_24 ) ;
}
unsigned long F_71 ( struct V_2 * V_3 )
{
unsigned long V_120 ;
struct V_5 * V_18 ;
int V_55 ;
#ifdef F_72
struct V_19 * V_20 ;
unsigned long V_121 , V_122 ;
struct V_1 * V_15 = NULL ;
V_20 = F_9 ( V_3 ) -> V_29 ;
V_120 = 0 ;
V_121 = 0 ;
V_18 = NULL ;
for ( V_55 = 0 ; V_55 < F_9 ( V_3 ) -> V_42 ; V_55 ++ ) {
V_18 = F_2 ( V_3 , V_55 , NULL ) ;
if ( ! V_18 )
continue;
V_120 += F_30 ( V_18 -> V_34 ) ;
F_24 ( V_15 ) ;
V_15 = F_1 ( V_3 , V_55 ) ;
if ( ! V_15 )
continue;
V_122 = F_73 ( V_15 , F_13 ( V_3 ) / 8 ) ;
F_8 ( L_26 ,
V_55 , F_30 ( V_18 -> V_34 ) , V_122 ) ;
V_121 += V_122 ;
}
F_24 ( V_15 ) ;
F_8 ( L_27 ,
F_4 ( V_20 -> V_123 ) , V_120 , V_121 ) ;
return V_120 ;
#else
V_120 = 0 ;
for ( V_55 = 0 ; V_55 < F_9 ( V_3 ) -> V_42 ; V_55 ++ ) {
V_18 = F_2 ( V_3 , V_55 , NULL ) ;
if ( ! V_18 )
continue;
V_120 += F_30 ( V_18 -> V_34 ) ;
F_74 () ;
}
return V_120 ;
#endif
}
unsigned long F_75 ( struct V_2 * V_3 )
{
unsigned long V_124 = 0 ;
int V_55 ;
for ( V_55 = 0 ; V_55 < F_9 ( V_3 ) -> V_42 ; V_55 ++ ) {
struct V_5 * V_18 = F_2 ( V_3 , V_55 , NULL ) ;
if ( ! V_18 )
continue;
V_124 += F_30 ( V_18 -> V_35 ) ;
}
return V_124 ;
}
