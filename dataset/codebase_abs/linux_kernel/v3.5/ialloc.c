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
int V_41 = V_22 -> V_42 ;
int V_43 = F_13 ( V_3 ) ;
unsigned int V_44 , V_45 ;
T_2 V_46 , V_47 ;
unsigned int V_48 ;
int V_49 , V_50 ;
T_3 V_51 ;
int V_52 = - 1 , V_53 ;
struct V_5 * V_6 ;
V_44 = F_28 ( & V_22 -> V_36 ) ;
V_45 = V_44 / V_41 ;
V_46 = F_28 ( & V_22 -> V_54 ) ;
V_47 = V_46 / V_41 ;
V_48 = F_28 ( & V_22 -> V_37 ) ;
if ( ( V_38 == V_3 -> V_55 -> V_56 ) ||
( F_27 ( V_38 ) -> V_57 & V_58 ) ) {
int V_59 = V_43 ;
int V_60 = - 1 ;
F_29 ( & V_52 , sizeof( V_52 ) ) ;
V_39 = ( unsigned ) V_52 % V_41 ;
for ( V_53 = 0 ; V_53 < V_41 ; V_53 ++ ) {
V_52 = ( V_39 + V_53 ) % V_41 ;
V_6 = F_2 ( V_3 , V_52 , NULL ) ;
if ( ! V_6 || ! V_6 -> V_34 )
continue;
if ( F_30 ( V_6 -> V_35 ) >= V_59 )
continue;
if ( F_30 ( V_6 -> V_34 ) < V_45 )
continue;
if ( F_30 ( V_6 -> V_61 ) < V_47 )
continue;
V_60 = V_52 ;
V_59 = F_30 ( V_6 -> V_35 ) ;
}
if ( V_60 >= 0 )
return V_60 ;
goto V_62;
}
V_49 = V_48 / V_41 + V_43 / 16 ;
V_50 = V_45 - V_43 / 4 ;
V_51 = V_47 - F_31 ( V_3 ) / 4 ;
for ( V_53 = 0 ; V_53 < V_41 ; V_53 ++ ) {
V_52 = ( V_39 + V_53 ) % V_41 ;
V_6 = F_2 ( V_3 , V_52 , NULL ) ;
if ( ! V_6 || ! V_6 -> V_34 )
continue;
if ( F_30 ( V_6 -> V_35 ) >= V_49 )
continue;
if ( F_30 ( V_6 -> V_34 ) < V_50 )
continue;
if ( F_30 ( V_6 -> V_61 ) < V_51 )
continue;
return V_52 ;
}
V_62:
for ( V_53 = 0 ; V_53 < V_41 ; V_53 ++ ) {
V_52 = ( V_39 + V_53 ) % V_41 ;
V_6 = F_2 ( V_3 , V_52 , NULL ) ;
if ( ! V_6 || ! V_6 -> V_34 )
continue;
if ( F_30 ( V_6 -> V_34 ) >= V_45 )
return V_52 ;
}
if ( V_45 ) {
V_45 = 0 ;
goto V_62;
}
return - 1 ;
}
static int F_32 ( struct V_2 * V_3 , struct V_11 * V_38 )
{
int V_39 = F_27 ( V_38 ) -> V_40 ;
int V_41 = F_9 ( V_3 ) -> V_42 ;
struct V_5 * V_6 ;
int V_52 , V_53 ;
V_52 = V_39 ;
V_6 = F_2 ( V_3 , V_52 , NULL ) ;
if ( V_6 && F_30 ( V_6 -> V_34 ) &&
F_30 ( V_6 -> V_61 ) )
return V_52 ;
V_52 = ( V_52 + V_38 -> V_27 ) % V_41 ;
for ( V_53 = 1 ; V_53 < V_41 ; V_53 <<= 1 ) {
V_52 += V_53 ;
if ( V_52 >= V_41 )
V_52 -= V_41 ;
V_6 = F_2 ( V_3 , V_52 , NULL ) ;
if ( V_6 && F_30 ( V_6 -> V_34 ) &&
F_30 ( V_6 -> V_61 ) )
return V_52 ;
}
V_52 = V_39 ;
for ( V_53 = 0 ; V_53 < V_41 ; V_53 ++ ) {
if ( ++ V_52 >= V_41 )
V_52 = 0 ;
V_6 = F_2 ( V_3 , V_52 , NULL ) ;
if ( V_6 && F_30 ( V_6 -> V_34 ) )
return V_52 ;
}
return - 1 ;
}
struct V_11 * F_33 ( T_1 * V_10 , struct V_11 * V_63 ,
const struct V_64 * V_64 , T_4 V_65 )
{
struct V_2 * V_3 ;
struct V_1 * V_15 = NULL ;
struct V_1 * V_16 ;
int V_52 ;
unsigned long V_14 = 0 ;
struct V_11 * V_11 ;
struct V_5 * V_18 = NULL ;
struct V_19 * V_20 ;
struct V_66 * V_67 ;
struct V_21 * V_22 ;
int V_24 = 0 ;
struct V_11 * V_68 ;
int V_53 ;
if ( ! V_63 || ! V_63 -> V_26 )
return F_34 ( - V_69 ) ;
V_3 = V_63 -> V_12 ;
F_35 ( V_63 , V_65 ) ;
V_11 = F_36 ( V_3 ) ;
if ( ! V_11 )
return F_34 ( - V_70 ) ;
V_67 = F_27 ( V_11 ) ;
V_22 = F_9 ( V_3 ) ;
V_20 = V_22 -> V_29 ;
if ( F_12 ( V_65 ) )
V_52 = F_26 ( V_3 , V_63 ) ;
else
V_52 = F_32 ( V_3 , V_63 ) ;
V_24 = - V_71 ;
if ( V_52 == - 1 )
goto V_72;
for ( V_53 = 0 ; V_53 < V_22 -> V_42 ; V_53 ++ ) {
V_24 = - V_73 ;
V_18 = F_2 ( V_3 , V_52 , & V_16 ) ;
if ( ! V_18 )
goto V_74;
F_24 ( V_15 ) ;
V_15 = F_1 ( V_3 , V_52 ) ;
if ( ! V_15 )
goto V_74;
V_14 = 0 ;
V_75:
V_14 = F_37 ( ( unsigned long * )
V_15 -> V_33 , F_13 ( V_3 ) , V_14 ) ;
if ( V_14 < F_13 ( V_3 ) ) {
F_14 ( V_15 , L_10 ) ;
V_24 = F_15 ( V_10 , V_15 ) ;
if ( V_24 )
goto V_74;
if ( ! F_38 ( F_17 ( V_22 , V_52 ) ,
V_14 , V_15 -> V_33 ) ) {
F_14 ( V_15 ,
L_12 ) ;
V_24 = F_23 ( V_10 ,
V_15 ) ;
if ( V_24 )
goto V_74;
goto V_76;
}
F_39 ( V_10 , V_15 ) ;
if ( ++ V_14 < F_13 ( V_3 ) )
goto V_75;
}
if ( ++ V_52 == V_22 -> V_42 )
V_52 = 0 ;
}
V_24 = - V_71 ;
goto V_72;
V_76:
V_14 += V_52 * F_13 ( V_3 ) + 1 ;
if ( V_14 < V_30 ( V_3 ) || V_14 > F_4 ( V_20 -> V_31 ) ) {
F_5 ( V_3 , L_13 ,
L_14
L_15 , V_52 , V_14 ) ;
V_24 = - V_73 ;
goto V_74;
}
F_14 ( V_16 , L_10 ) ;
V_24 = F_15 ( V_10 , V_16 ) ;
if ( V_24 ) goto V_74;
F_18 ( F_17 ( V_22 , V_52 ) ) ;
F_19 ( & V_18 -> V_34 , - 1 ) ;
if ( F_12 ( V_65 ) ) {
F_19 ( & V_18 -> V_35 , 1 ) ;
}
F_20 ( F_17 ( V_22 , V_52 ) ) ;
F_14 ( V_16 , L_12 ) ;
V_24 = F_23 ( V_10 , V_16 ) ;
if ( V_24 ) goto V_74;
F_22 ( & V_22 -> V_36 ) ;
if ( F_12 ( V_65 ) )
F_21 ( & V_22 -> V_37 ) ;
if ( F_40 ( V_3 , V_77 ) ) {
V_11 -> V_28 = V_65 ;
V_11 -> V_78 = F_41 () ;
V_11 -> V_79 = V_63 -> V_79 ;
} else
F_42 ( V_11 , V_63 , V_65 ) ;
V_11 -> V_27 = V_14 ;
V_11 -> V_80 = 0 ;
V_11 -> V_81 = V_11 -> V_82 = V_11 -> V_83 = V_84 ;
memset ( V_67 -> V_85 , 0 , sizeof( V_67 -> V_85 ) ) ;
V_67 -> V_86 = 0 ;
V_67 -> V_87 = 0 ;
V_67 -> V_57 =
F_43 ( V_65 , F_27 ( V_63 ) -> V_57 & V_88 ) ;
#ifdef F_44
V_67 -> V_89 = 0 ;
V_67 -> V_90 = 0 ;
V_67 -> V_91 = 0 ;
#endif
V_67 -> V_92 = 0 ;
V_67 -> V_93 = 0 ;
V_67 -> V_94 = 0 ;
V_67 -> V_95 = NULL ;
V_67 -> V_40 = V_52 ;
F_45 ( V_11 ) ;
if ( F_46 ( V_11 ) )
V_10 -> V_96 = 1 ;
if ( F_47 ( V_11 ) < 0 ) {
V_24 = - V_73 ;
goto V_74;
}
F_18 ( & V_22 -> V_97 ) ;
V_11 -> V_98 = V_22 -> V_99 ++ ;
F_20 ( & V_22 -> V_97 ) ;
V_67 -> V_100 = 0 ;
F_48 ( V_11 , V_101 ) ;
if ( V_14 >= V_30 ( V_3 ) + 1 &&
F_49 ( V_3 ) > V_102 ) {
V_67 -> V_103 =
sizeof( struct V_104 ) - V_102 ;
} else {
V_67 -> V_103 = 0 ;
}
V_68 = V_11 ;
F_50 ( V_11 ) ;
V_24 = F_51 ( V_11 ) ;
if ( V_24 )
goto V_105;
V_24 = F_52 ( V_10 , V_11 , V_63 ) ;
if ( V_24 )
goto V_106;
V_24 = F_53 ( V_10 , V_11 , V_63 , V_64 ) ;
if ( V_24 )
goto V_106;
V_24 = F_54 ( V_10 , V_11 ) ;
if ( V_24 ) {
F_25 ( V_3 , V_24 ) ;
goto V_106;
}
F_10 ( L_16 , V_11 -> V_27 ) ;
F_55 ( V_11 , V_63 , V_65 ) ;
goto V_107;
V_74:
F_25 ( V_3 , V_24 ) ;
V_72:
F_56 ( V_11 ) ;
V_68 = F_34 ( V_24 ) ;
V_107:
F_24 ( V_15 ) ;
return V_68 ;
V_106:
F_57 ( V_11 ) ;
V_105:
F_58 ( V_11 ) ;
V_11 -> V_57 |= V_108 ;
F_59 ( V_11 ) ;
F_60 ( V_11 ) ;
F_56 ( V_11 ) ;
F_24 ( V_15 ) ;
return F_34 ( V_24 ) ;
}
struct V_11 * F_61 ( struct V_2 * V_3 , unsigned long V_14 )
{
unsigned long V_109 = F_4 ( F_9 ( V_3 ) -> V_29 -> V_31 ) ;
unsigned long V_4 ;
int V_17 ;
struct V_1 * V_15 ;
struct V_11 * V_11 = NULL ;
long V_24 = - V_73 ;
if ( V_14 > V_109 ) {
F_62 ( V_3 , V_110 ,
L_17 , V_14 ) ;
goto error;
}
V_4 = ( V_14 - 1 ) / F_13 ( V_3 ) ;
V_17 = ( V_14 - 1 ) % F_13 ( V_3 ) ;
V_15 = F_1 ( V_3 , V_4 ) ;
if ( ! V_15 ) {
F_62 ( V_3 , V_110 ,
L_18 , V_14 ) ;
goto error;
}
if ( ! F_63 ( V_17 , V_15 -> V_33 ) )
goto V_111;
V_11 = F_64 ( V_3 , V_14 ) ;
if ( F_65 ( V_11 ) )
goto V_112;
if ( V_11 -> V_26 && ! F_66 ( V_11 ) )
goto V_111;
if ( F_67 ( V_11 ) > V_109 )
goto V_111;
F_24 ( V_15 ) ;
return V_11 ;
V_112:
V_24 = F_68 ( V_11 ) ;
V_11 = NULL ;
V_111:
F_62 ( V_3 , V_110 ,
L_19 , V_14 ) ;
F_8 ( V_113 L_20 ,
V_17 , ( unsigned long long ) V_15 -> V_114 ,
F_63 ( V_17 , V_15 -> V_33 ) ) ;
F_8 ( V_113 L_21 , V_11 ) ;
if ( V_11 ) {
F_8 ( V_113 L_22 ,
F_69 ( V_11 ) ) ;
F_8 ( V_113 L_23 ,
F_67 ( V_11 ) ) ;
F_8 ( V_113 L_24 , V_109 ) ;
F_8 ( V_113 L_25 , V_11 -> V_26 ) ;
if ( V_11 -> V_26 == 0 )
V_11 -> V_80 = 0 ;
F_56 ( V_11 ) ;
}
F_24 ( V_15 ) ;
error:
return F_34 ( V_24 ) ;
}
unsigned long F_70 ( struct V_2 * V_3 )
{
unsigned long V_115 ;
struct V_5 * V_18 ;
int V_53 ;
#ifdef F_71
struct V_19 * V_20 ;
unsigned long V_116 , V_117 ;
struct V_1 * V_15 = NULL ;
V_20 = F_9 ( V_3 ) -> V_29 ;
V_115 = 0 ;
V_116 = 0 ;
V_18 = NULL ;
for ( V_53 = 0 ; V_53 < F_9 ( V_3 ) -> V_42 ; V_53 ++ ) {
V_18 = F_2 ( V_3 , V_53 , NULL ) ;
if ( ! V_18 )
continue;
V_115 += F_30 ( V_18 -> V_34 ) ;
F_24 ( V_15 ) ;
V_15 = F_1 ( V_3 , V_53 ) ;
if ( ! V_15 )
continue;
V_117 = F_72 ( V_15 , F_13 ( V_3 ) / 8 ) ;
F_8 ( L_26 ,
V_53 , F_30 ( V_18 -> V_34 ) , V_117 ) ;
V_116 += V_117 ;
}
F_24 ( V_15 ) ;
F_8 ( L_27 ,
F_4 ( V_20 -> V_118 ) , V_115 , V_116 ) ;
return V_115 ;
#else
V_115 = 0 ;
for ( V_53 = 0 ; V_53 < F_9 ( V_3 ) -> V_42 ; V_53 ++ ) {
V_18 = F_2 ( V_3 , V_53 , NULL ) ;
if ( ! V_18 )
continue;
V_115 += F_30 ( V_18 -> V_34 ) ;
F_73 () ;
}
return V_115 ;
#endif
}
unsigned long F_74 ( struct V_2 * V_3 )
{
unsigned long V_119 = 0 ;
int V_53 ;
for ( V_53 = 0 ; V_53 < F_9 ( V_3 ) -> V_42 ; V_53 ++ ) {
struct V_5 * V_18 = F_2 ( V_3 , V_53 , NULL ) ;
if ( ! V_18 )
continue;
V_119 += F_30 ( V_18 -> V_35 ) ;
}
return V_119 ;
}
