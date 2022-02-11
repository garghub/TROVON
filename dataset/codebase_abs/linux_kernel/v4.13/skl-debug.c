static T_1 F_1 ( struct V_1 * V_2 , char * V_3 ,
int V_4 , T_1 V_5 , bool V_6 )
{
int V_7 ;
T_1 V_8 = 0 ;
for ( V_7 = 0 ; V_7 < V_4 ; V_7 ++ )
V_8 += snprintf ( V_3 + V_5 , V_9 - V_5 ,
L_1
L_2
L_3 ,
V_6 ? L_4 : L_5 ,
V_7 , V_2 [ V_7 ] . V_10 . V_11 ,
V_2 [ V_7 ] . V_10 . V_12 ,
V_2 [ V_7 ] . V_13 ? L_6 : L_7 ,
V_2 [ V_7 ] . V_14 ? L_8 : L_9 ,
V_2 [ V_7 ] . V_15 , V_7 ) ;
return V_8 ;
}
static T_1 F_2 ( struct V_16 * V_17 , char * V_3 ,
T_1 V_5 , bool V_6 )
{
return snprintf ( V_3 + V_5 , V_9 - V_5 ,
L_10
L_11
L_12 ,
V_6 ? L_13 : L_14 ,
V_17 -> V_18 , V_17 -> V_19 , V_17 -> V_20 ,
V_17 -> V_21 , V_17 -> V_22 ,
V_17 -> V_23 , V_17 -> V_24 ,
V_17 -> V_25 ) ;
}
static T_1 F_3 ( struct V_26 * V_26 , char T_2 * V_27 ,
T_3 V_28 , T_4 * V_29 )
{
struct V_30 * V_31 = V_26 -> V_32 ;
char * V_3 ;
T_1 V_8 ;
V_3 = F_4 ( V_9 , V_33 ) ;
if ( ! V_3 )
return - V_34 ;
V_8 = snprintf ( V_3 , V_9 , L_15
L_16 , V_31 -> V_35 ,
V_31 -> V_10 . V_11 , V_31 -> V_10 . V_12 ,
V_31 -> V_10 . V_36 ) ;
V_8 += snprintf ( V_3 + V_8 , V_9 - V_8 ,
L_17 ,
V_31 -> V_37 , V_31 -> V_38 , V_31 -> V_39 ) ;
V_8 += snprintf ( V_3 + V_8 , V_9 - V_8 ,
L_18
L_19 ,
V_31 -> V_40 , V_31 -> V_41 ,
V_31 -> V_42 ,
V_31 -> V_43 ? L_20 : L_21 ) ;
V_8 += F_2 ( V_31 -> V_44 , V_3 , V_8 , true ) ;
V_8 += F_2 ( V_31 -> V_45 , V_3 , V_8 , false ) ;
V_8 += snprintf ( V_3 + V_8 , V_9 - V_8 ,
L_22 ,
V_31 -> V_46 , V_31 -> V_47 ) ;
V_8 += snprintf ( V_3 + V_8 , V_9 - V_8 ,
L_23 ,
V_31 -> V_48 , V_31 -> V_49 ,
V_31 -> V_50 , V_31 -> V_51 ) ;
V_8 += snprintf ( V_3 + V_8 , V_9 - V_8 ,
L_24
L_25 , V_31 -> V_52 -> V_53 ,
V_31 -> V_52 -> V_54 , V_31 -> V_52 -> V_55 ,
V_31 -> V_52 -> V_56 ) ;
V_8 += snprintf ( V_3 + V_8 , V_9 - V_8 ,
L_26 ,
V_31 -> V_52 -> V_57 -> V_58 ,
V_31 -> V_52 -> V_57 -> V_59 ) ;
V_8 += snprintf ( V_3 + V_8 , V_9 - V_8 ,
L_27 ,
V_31 -> V_52 -> V_57 -> V_60 ,
V_31 -> V_52 -> V_57 -> V_19 ,
V_31 -> V_52 -> V_57 -> V_61 ) ;
V_8 += snprintf ( V_3 + V_8 , V_9 - V_8 ,
L_28 ,
V_31 -> V_52 -> V_57 -> V_62 ,
V_31 -> V_52 -> V_57 -> V_63 ) ;
V_8 += snprintf ( V_3 + V_8 , V_9 - V_8 ,
L_29 ,
V_31 -> V_52 -> V_64 ,
V_31 -> V_52 -> V_65 ? L_30 : L_31 ) ;
V_8 += F_1 ( V_31 -> V_66 , V_3 ,
V_31 -> V_41 , V_8 , true ) ;
V_8 += F_1 ( V_31 -> V_67 , V_3 ,
V_31 -> V_42 , V_8 , false ) ;
V_8 += snprintf ( V_3 + V_8 , V_9 - V_8 ,
L_32
L_33
L_34
L_35 ,
V_31 -> V_68 ,
V_31 -> V_69 ? L_30 : L_31 ,
V_31 -> V_70 ? L_30 : L_31 ,
V_31 -> V_71 , V_31 -> V_72 ,
V_31 -> V_73 , V_31 -> V_74 , V_31 -> V_75 ,
V_31 -> V_76 ) ;
V_8 = F_5 ( V_27 , V_28 , V_29 , V_3 , V_8 ) ;
F_6 ( V_3 ) ;
return V_8 ;
}
void F_7 ( struct V_77 * V_78 ,
struct V_79 * V_80 ,
struct V_30 * V_31 )
{
if ( ! F_8 ( V_80 -> V_81 , 0444 ,
V_78 -> V_82 , V_31 ,
& V_83 ) )
F_9 ( V_78 -> V_84 , L_36 , V_80 -> V_81 ) ;
}
static T_1 F_10 ( struct V_26 * V_26 , char T_2 * V_27 ,
T_3 V_28 , T_4 * V_29 )
{
struct V_77 * V_78 = V_26 -> V_32 ;
struct V_85 * V_86 = V_78 -> V_87 -> V_88 -> V_89 ;
T_3 V_90 = V_86 -> V_91 . V_90 ;
void T_5 * V_92 = V_86 -> V_93 . V_92 ;
void T_5 * V_94 ;
unsigned int V_95 ;
char * V_96 ;
T_1 V_8 = 0 ;
V_96 = F_4 ( V_97 , V_33 ) ;
if ( ! V_96 )
return - V_34 ;
V_94 = V_92 - V_90 ;
memset ( V_78 -> V_98 , 0 , V_97 ) ;
if ( V_90 > 0 )
F_11 ( V_78 -> V_98 , V_94 , V_90 >> 2 ) ;
for ( V_95 = 0 ; V_95 < V_99 ; V_95 += 16 ) {
V_8 += snprintf ( V_96 + V_8 , V_97 - V_8 , L_37 , V_95 ) ;
F_12 ( V_78 -> V_98 + V_95 , 16 , 16 , 4 ,
V_96 + V_8 , V_97 - V_8 , 0 ) ;
V_8 += strlen ( V_96 + V_8 ) ;
if ( V_97 - V_8 > 0 )
V_96 [ V_8 ++ ] = '\n' ;
}
V_8 = F_5 ( V_27 , V_28 , V_29 , V_96 , V_8 ) ;
F_6 ( V_96 ) ;
return V_8 ;
}
struct V_77 * F_13 ( struct V_87 * V_87 )
{
struct V_77 * V_78 ;
V_78 = F_14 ( & V_87 -> V_100 -> V_84 , sizeof( * V_78 ) , V_33 ) ;
if ( ! V_78 )
return NULL ;
V_78 -> V_101 = F_15 ( L_38 ,
V_87 -> V_102 -> V_103 . V_104 ) ;
if ( F_16 ( V_78 -> V_101 ) || ! V_78 -> V_101 ) {
F_9 ( & V_87 -> V_100 -> V_84 , L_39 ) ;
return NULL ;
}
V_78 -> V_87 = V_87 ;
V_78 -> V_84 = & V_87 -> V_100 -> V_84 ;
V_78 -> V_82 = F_15 ( L_40 , V_78 -> V_101 ) ;
if ( F_16 ( V_78 -> V_82 ) || ! V_78 -> V_82 ) {
F_9 ( & V_87 -> V_100 -> V_84 , L_41 ) ;
goto V_105;
}
if ( ! F_8 ( L_42 , 0444 , V_78 -> V_101 , V_78 ,
& V_106 ) ) {
F_9 ( V_78 -> V_84 , L_43 ) ;
goto V_105;
}
return V_78 ;
V_105:
F_17 ( V_78 -> V_101 ) ;
return NULL ;
}
