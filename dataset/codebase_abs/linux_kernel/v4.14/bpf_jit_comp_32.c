static inline bool F_1 ( unsigned int V_1 )
{
return V_1 + 0x1000 < 0x2000 ;
}
void F_2 ( struct V_2 * V_3 )
{
unsigned int V_4 , V_5 , V_6 = 0 ;
T_1 V_7 [ 8 ] , * V_8 , * V_9 , V_10 = 0 , V_11 ;
const struct V_12 * V_13 = V_3 -> V_14 ;
int V_15 , V_16 = V_3 -> V_17 , V_18 = - 1 ;
unsigned int * V_19 ;
void * V_20 ;
if ( ! V_21 )
return;
V_19 = F_3 ( V_16 * sizeof( * V_19 ) , V_22 ) ;
if ( V_19 == NULL )
return;
for ( V_5 = 0 , V_15 = 0 ; V_15 < V_16 ; V_15 ++ ) {
V_5 += 64 ;
V_19 [ V_15 ] = V_5 ;
}
V_4 = V_5 ;
V_20 = NULL ;
for ( V_11 = 0 ; V_11 < 10 ; V_11 ++ ) {
T_2 V_23 = ( V_11 == 0 ) ? ( V_24 | V_25 | V_26 ) : V_10 ;
V_5 = 0 ;
V_8 = V_7 ;
if ( V_23 ) {
if ( V_23 & V_26 ) {
unsigned int V_27 = V_28 ;
V_27 += V_29 * sizeof( T_1 ) ;
F_4 ( V_27 ) ;
}
if ( V_23 & V_24 )
F_5 ( V_30 ) ;
if ( V_23 & V_25 ) {
F_6 ( V_31 , struct V_32 , V_17 , V_33 ) ;
F_6 ( V_31 , struct V_32 , V_34 , V_35 ) ;
F_7 ( V_33 , V_35 , V_33 ) ;
F_8 ( V_31 , struct V_32 , V_36 , V_37 ) ;
}
}
F_9 ( V_38 , V_39 ) ;
if ( F_10 ( & V_13 [ 0 ] ) )
F_5 ( V_40 ) ;
for ( V_15 = 0 ; V_15 < V_16 ; V_15 ++ ) {
unsigned int V_41 = V_13 [ V_15 ] . V_42 ;
unsigned int V_43 ;
unsigned int V_44 ;
T_1 V_45 , V_46 ;
T_3 V_47 = F_11 ( & V_13 [ V_15 ] ) ;
int V_48 ;
switch ( V_47 ) {
case V_49 | V_50 | V_51 :
F_12 ( V_52 ) ;
break;
case V_49 | V_50 | V_53 :
F_13 ( V_52 , V_41 ) ;
break;
case V_49 | V_54 | V_51 :
F_12 ( V_55 ) ;
break;
case V_49 | V_54 | V_53 :
F_13 ( V_55 , V_41 ) ;
break;
case V_49 | V_56 | V_51 :
F_12 ( V_57 ) ;
break;
case V_49 | V_56 | V_53 :
F_13 ( V_57 , V_41 ) ;
break;
case V_49 | V_58 | V_51 :
F_12 ( V_59 ) ;
break;
case V_49 | V_58 | V_53 :
F_13 ( V_59 , V_41 ) ;
break;
case V_60 | V_61 :
case V_49 | V_62 | V_51 :
F_12 ( V_63 ) ;
break;
case V_49 | V_62 | V_53 :
F_13 ( V_63 , V_41 ) ;
break;
case V_49 | V_64 | V_51 :
F_12 ( V_65 ) ;
break;
case V_49 | V_64 | V_53 :
F_13 ( V_65 , V_41 ) ;
break;
case V_49 | V_66 | V_51 :
F_12 ( V_67 ) ;
break;
case V_49 | V_66 | V_53 :
F_13 ( V_67 , V_41 ) ;
break;
case V_49 | V_68 | V_51 :
F_12 ( V_69 ) ;
break;
case V_49 | V_68 | V_53 :
F_13 ( V_69 , V_41 ) ;
break;
case V_49 | V_70 | V_53 :
if ( V_41 == 1 )
break;
F_14 ( V_71 ) ;
F_15 () ;
F_15 () ;
F_15 () ;
F_13 ( DIV , V_41 ) ;
break;
case V_49 | V_70 | V_51 :
F_16 ( V_30 , 0 ) ;
if ( V_18 > 0 ) {
V_43 = V_19 [ V_18 - 1 ] ;
F_17 ( V_72 , V_43 + 20 ) ;
F_15 () ;
} else {
F_18 ( V_73 , 16 ) ;
F_15 () ;
F_19 ( V_4 + 20 ) ;
F_5 ( V_40 ) ;
}
F_14 ( V_71 ) ;
F_15 () ;
F_15 () ;
F_15 () ;
F_12 ( DIV ) ;
break;
case V_49 | V_74 :
F_20 () ;
break;
case V_75 | V_53 :
if ( ! V_41 ) {
if ( V_18 == - 1 )
V_18 = V_15 ;
F_5 ( V_40 ) ;
} else {
F_21 ( V_41 , V_40 ) ;
}
case V_75 | V_76 :
if ( V_23 ) {
if ( V_15 != V_16 - 1 ) {
F_19 ( V_4 ) ;
F_15 () ;
break;
}
if ( V_23 & V_26 ) {
unsigned int V_27 = V_28 ;
V_27 += V_29 * sizeof( T_1 ) ;
F_22 ( V_27 ) ;
}
}
F_23 ( V_39 , 8 , V_71 ) ;
F_9 ( V_40 , V_77 ) ;
break;
case V_78 | V_79 :
V_10 |= V_24 ;
F_9 ( V_40 , V_30 ) ;
break;
case V_78 | V_80 :
V_10 |= V_24 ;
F_9 ( V_30 , V_40 ) ;
break;
case V_60 | V_81 :
F_24 ( V_40 ) ;
break;
case V_60 | V_82 :
F_25 ( V_83 , V_40 ) ;
break;
case V_60 | V_84 :
F_26 ( V_85 , V_40 ) ;
F_27 ( V_40 , V_86 , V_40 ) ;
F_13 ( V_67 , 5 ) ;
break;
case V_60 | V_87 :
F_28 ( V_88 , V_40 ) ;
F_16 ( V_40 , 0 ) ;
F_17 ( V_89 , V_4 + 4 ) ;
F_15 () ;
F_6 ( V_40 , struct V_90 , V_91 , V_40 ) ;
break;
case V_60 | V_92 :
F_29 ( V_93 , V_40 ) ;
break;
case V_60 | V_94 :
F_25 ( V_95 , V_40 ) ;
break;
case V_60 | V_96 :
F_28 ( V_88 , V_40 ) ;
F_16 ( V_40 , 0 ) ;
F_17 ( V_89 , V_4 + 4 ) ;
F_15 () ;
F_30 ( V_40 , struct V_90 , type , V_40 ) ;
break;
case V_60 | V_97 :
F_29 ( V_98 , V_40 ) ;
break;
case V_60 | V_99 :
case V_60 | V_100 :
F_25 ( V_101 , V_40 ) ;
if ( V_47 != ( V_60 | V_99 ) ) {
F_13 ( V_67 , 12 ) ;
F_27 ( V_40 , 1 , V_40 ) ;
} else {
F_21 ( ~ V_102 , V_35 ) ;
F_31 ( V_40 , V_35 , V_40 ) ;
}
break;
case V_103 | V_104 | V_105 :
F_29 ( V_17 , V_40 ) ;
break;
case V_106 | V_104 | V_105 :
F_29 ( V_17 , V_30 ) ;
break;
case V_103 | V_107 :
F_21 ( V_41 , V_40 ) ;
break;
case V_106 | V_107 :
F_21 ( V_41 , V_30 ) ;
break;
case V_103 | V_108 :
V_10 |= V_26 ;
F_32 ( V_41 * 4 , V_40 ) ;
break;
case V_106 | V_108 :
V_10 |= V_26 | V_24 ;
F_32 ( V_41 * 4 , V_30 ) ;
break;
case V_109 :
V_10 |= V_26 ;
F_33 ( V_41 * 4 , V_40 ) ;
break;
case V_110 :
V_10 |= V_26 | V_24 ;
F_33 ( V_41 * 4 , V_30 ) ;
break;
#define F_34 ( V_41 , V_9 ) \
((int)K < 0 ? ((int)K >= SKF_LL_OFF ? func##_negative_offset : func) : func##_positive_offset)
case V_103 | V_104 | V_111 :
V_9 = F_34 ( V_41 , V_112 ) ;
V_113: V_10 |= V_25 ;
F_21 ( V_41 , V_114 ) ;
F_35 ( V_9 ) ;
break;
case V_103 | V_115 | V_111 :
V_9 = F_34 ( V_41 , V_116 ) ;
goto V_113;
case V_103 | V_117 | V_111 :
V_9 = F_34 ( V_41 , V_118 ) ;
goto V_113;
case V_106 | V_117 | V_119 :
V_9 = F_34 ( V_41 , V_120 ) ;
goto V_113;
case V_103 | V_104 | V_121 :
V_9 = V_112 ;
V_122: V_10 |= V_25 | V_24 ;
if ( V_41 ) {
if ( F_1 ( V_41 ) ) {
F_36 ( V_30 , V_41 , V_114 ) ;
} else {
F_21 ( V_41 , V_35 ) ;
F_37 ( V_30 , V_35 , V_114 ) ;
}
} else {
F_9 ( V_30 , V_114 ) ;
}
F_35 ( V_9 ) ;
break;
case V_103 | V_115 | V_121 :
V_9 = V_116 ;
goto V_122;
case V_103 | V_117 | V_121 :
V_9 = V_118 ;
goto V_122;
case V_123 | V_124 :
F_19 ( V_19 [ V_15 + V_41 ] ) ;
F_15 () ;
break;
#define F_38 ( T_4 , T_5 , T_6 ) \
case CODE: \
t_op = TOP; \
f_op = FOP; \
goto cond_branch
F_38 ( V_123 | V_125 | V_53 , V_126 , V_127 ) ;
F_38 ( V_123 | V_128 | V_53 , V_129 , V_130 ) ;
F_38 ( V_123 | V_131 | V_53 , V_72 , V_73 ) ;
F_38 ( V_123 | V_132 | V_53 , V_73 , V_72 ) ;
F_38 ( V_123 | V_125 | V_51 , V_126 , V_127 ) ;
F_38 ( V_123 | V_128 | V_51 , V_129 , V_130 ) ;
F_38 ( V_123 | V_131 | V_51 , V_72 , V_73 ) ;
F_38 ( V_123 | V_132 | V_51 , V_73 , V_72 ) ;
V_133: V_44 = V_19 [ V_15 + V_13 [ V_15 ] . V_134 ] ;
V_43 = V_19 [ V_15 + V_13 [ V_15 ] . V_135 ] ;
if ( V_13 [ V_15 ] . V_135 == V_13 [ V_15 ] . V_134 ) {
F_19 ( V_43 ) ;
F_15 () ;
break;
}
switch ( V_47 ) {
case V_123 | V_125 | V_51 :
case V_123 | V_128 | V_51 :
case V_123 | V_131 | V_51 :
V_10 |= V_24 ;
F_39 ( V_40 , V_30 ) ;
break;
case V_123 | V_132 | V_51 :
V_10 |= V_24 ;
F_40 ( V_40 , V_30 ) ;
break;
case V_123 | V_131 | V_53 :
case V_123 | V_125 | V_53 :
case V_123 | V_128 | V_53 :
if ( F_1 ( V_41 ) ) {
F_16 ( V_40 , V_41 ) ;
} else {
F_21 ( V_41 , V_35 ) ;
F_39 ( V_40 , V_35 ) ;
}
break;
case V_123 | V_132 | V_53 :
if ( F_1 ( V_41 ) ) {
F_41 ( V_40 , V_41 ) ;
} else {
F_21 ( V_41 , V_35 ) ;
F_40 ( V_40 , V_35 ) ;
}
break;
}
if ( V_13 [ V_15 ] . V_135 != 0 ) {
if ( V_13 [ V_15 ] . V_134 )
V_43 += 8 ;
F_17 ( V_45 , V_43 ) ;
F_15 () ;
if ( V_13 [ V_15 ] . V_134 ) {
F_19 ( V_44 ) ;
F_15 () ;
}
break;
}
F_17 ( V_46 , V_44 ) ;
F_15 () ;
break;
default:
goto V_136;
}
V_48 = ( void * ) V_8 - ( void * ) V_7 ;
if ( V_20 ) {
if ( F_42 ( V_5 + V_48 > V_6 ) ) {
F_43 ( L_1 ) ;
F_44 ( V_19 ) ;
F_45 ( V_20 ) ;
return;
}
memcpy ( V_20 + V_5 , V_7 , V_48 ) ;
}
V_5 += V_48 ;
V_19 [ V_15 ] = V_5 ;
V_8 = V_7 ;
}
V_4 = V_5 - 8 ;
if ( V_23 & V_26 )
V_4 -= 4 ;
if ( V_20 ) {
if ( V_5 != V_6 )
F_43 ( L_2 ,
V_5 , V_6 ) ;
break;
}
if ( V_5 == V_6 ) {
V_20 = F_46 ( V_5 ) ;
if ( ! V_20 )
goto V_136;
}
V_6 = V_5 ;
}
if ( V_21 > 1 )
F_47 ( V_16 , V_5 , V_11 + 1 , V_20 ) ;
if ( V_20 ) {
V_3 -> V_137 = ( void * ) V_20 ;
V_3 -> V_138 = 1 ;
}
V_136:
F_44 ( V_19 ) ;
return;
}
void F_48 ( struct V_2 * V_3 )
{
if ( V_3 -> V_138 )
F_45 ( V_3 -> V_137 ) ;
F_49 ( V_3 ) ;
}
