static const T_1 * F_1 (
T_2 type )
{
T_1 * V_1 = NULL ;
if ( V_2 )
{
T_1 * V_3 ;
for ( V_3 = V_2 -> V_4 ; V_3 ; V_3 = V_3 -> V_5 )
{
if ( V_3 -> type == type )
{
if ( V_3 -> V_6 <= V_7 )
{
if ( ! V_1 || ( V_3 -> V_6 > V_1 -> V_6 ) )
{
V_1 = V_3 ;
}
}
}
}
}
if ( V_8 && ! V_1 )
{
F_2 ( L_1 , type ) ;
}
return V_1 ? V_1 : & V_9 ;
}
static const T_3 * F_3 (
const T_1 * V_10 ,
T_4 V_11 )
{
if ( V_10 -> V_12 )
{
return F_4 ( V_11 , V_10 -> V_12 , L_2 ) ;
}
else
{
return L_2 ;
}
}
static void F_5 (
T_5 * V_13 ,
T_6 * V_14 ,
T_7 * V_15 ,
T_8 V_16 ,
const T_1 * V_10 )
{
int V_17 ;
T_4 V_18 ;
const T_3 * V_19 ;
if ( V_10 -> V_20 != - 1 )
{
V_17 = V_10 -> V_20 ;
}
else
{
V_17 = V_10 -> V_17 ;
}
V_18 = F_6 ( V_13 , V_16 ) ;
V_19 = F_7 ( F_8 () , V_13 , V_21 , V_16 ) ;
F_9 (
V_14 , V_17 ,
V_13 , V_16 , 4 , V_18 ,
L_3 , V_19 ) ;
F_10 (
V_15 , L_4 , V_19 ) ;
}
static void F_11 (
T_5 * V_13 ,
T_6 * V_14 ,
T_7 * V_15 ,
T_8 V_16 ,
const T_1 * V_10 )
{
int V_17 ;
struct V_22 V_18 ;
const T_3 * V_19 ;
if ( V_10 -> V_20 != - 1 )
{
V_17 = V_10 -> V_23 ;
}
else
{
V_17 = V_10 -> V_17 ;
}
F_12 ( V_13 , V_16 , & V_18 ) ;
V_19 = F_7 ( F_8 () , V_13 , V_24 , V_16 ) ;
F_13 (
V_14 , V_17 ,
V_13 , V_16 , 16 , & V_18 ,
L_3 , V_19 ) ;
F_10 (
V_15 , L_4 , V_19 ) ;
}
static void F_14 (
T_5 * V_13 ,
T_6 * V_14 ,
T_7 * V_15 ,
T_8 V_16 ,
T_8 V_25 ,
const T_1 * V_10 )
{
int V_17 ;
const T_9 * V_26 ;
const T_3 * V_27 ;
if ( V_10 -> V_28 != - 1 )
{
V_17 = V_10 -> V_28 ;
}
else
{
V_17 = V_10 -> V_17 ;
}
V_26 = F_15 ( V_13 , V_16 , V_25 ) ;
V_27 = F_7 ( F_8 () , V_13 , V_29 , V_16 ) ;
F_16 (
V_14 , V_17 ,
V_13 , V_16 , V_25 , V_26 ,
L_3 ,
V_27 ) ;
F_10 (
V_15 , L_4 ,
V_27 ) ;
}
static void F_17 (
T_5 * V_13 ,
T_10 * T_11 V_30 ,
T_6 * V_14 ,
T_7 * V_15 ,
const T_1 * V_10 )
{
T_8 V_16 = 0 ;
T_8 V_25 ;
const T_8 V_31 = 24 ;
static const T_3 * V_32 = L_5 ;
V_25 = F_18 ( V_13 ) ;
switch ( V_10 -> V_33 )
{
case V_34 :
{
if ( V_25 != 1 )
{
break;
}
if ( V_10 -> V_35 == NULL )
{
if ( V_8 )
{
F_2 ( L_6 ,
V_10 -> V_36 , V_10 -> type ) ;
}
}
if ( V_14 )
{
T_9 V_37 ;
const T_3 * V_38 ;
V_37 = F_19 ( V_13 , V_16 ) ;
V_38 = F_3 ( V_10 , V_37 ) ;
F_20 (
V_14 , V_10 -> V_17 ,
V_13 , V_16 , V_25 , V_37 ,
L_7 , V_38 , V_37 ) ;
F_10 ( V_15 , L_4 , V_38 ) ;
}
return;
}
case V_39 :
{
if ( V_25 != 2 )
{
break;
}
if ( V_10 -> V_35 == NULL )
{
if ( V_8 )
{
F_2 ( L_6 ,
V_10 -> V_36 , V_10 -> type ) ;
}
}
if ( V_14 )
{
T_2 V_37 ;
const T_3 * V_38 ;
V_37 = F_21 ( V_13 , V_16 ) ;
V_38 = F_3 ( V_10 , V_37 ) ;
F_20 (
V_14 , V_10 -> V_17 ,
V_13 , V_16 , V_25 , V_37 ,
L_7 , V_38 , V_37 ) ;
F_10 ( V_15 , L_4 , V_38 ) ;
}
return;
}
case V_40 :
{
if ( V_25 != 4 )
{
break;
}
if ( V_10 -> V_35 == NULL )
{
if ( V_8 )
{
F_2 ( L_6 ,
V_10 -> V_36 , V_10 -> type ) ;
}
}
if ( V_14 )
{
T_4 V_37 ;
const T_3 * V_38 ;
V_37 = F_22 ( V_13 , V_16 ) ;
V_38 = F_3 ( V_10 , V_37 ) ;
F_20 (
V_14 , V_10 -> V_17 ,
V_13 , V_16 , V_25 , V_37 ,
L_7 , V_38 , V_37 ) ;
F_10 ( V_15 , L_4 , V_38 ) ;
}
return;
}
case V_41 :
{
if ( V_25 != 6 )
{
break;
}
if ( V_14 )
{
F_14 (
V_13 , V_14 , V_15 , V_16 , V_25 , V_10 ) ;
}
return;
}
case V_42 :
{
if ( V_14 )
{
const T_3 * V_38 = F_23 ( F_8 () , V_13 , V_16 , V_25 , V_43 ) ;
F_24 (
V_14 , V_10 -> V_17 ,
V_13 , V_16 , V_25 , V_38 ,
L_3 , V_38 ) ;
F_10 (
V_15 , L_4 , V_38 ) ;
}
return;
}
case V_44 :
{
if ( V_25 != 0 )
{
break;
}
return;
}
case V_45 :
{
if ( V_25 != 1 )
{
break;
}
if ( V_10 -> V_35 == NULL )
{
}
if ( V_14 )
{
T_6 * V_46 ;
T_7 * V_47 ;
T_9 V_37 ;
T_8 V_48 ;
V_37 = F_19 ( V_13 , V_16 ) ;
V_47 = F_25 (
V_14 , V_10 -> V_17 ,
V_13 , V_16 , 1 , V_49 ) ;
F_10 ( V_15 , L_8 , V_37 ) ;
if ( V_37 != 0 )
{
V_46 = F_26 (
V_47 , V_50 ) ;
for ( V_48 = 0 ; V_48 < 8 ; ++ V_48 )
{
T_9 V_51 ;
V_51 = 1U << ( 7 - V_48 ) ;
if ( V_37 & V_51 )
{
const T_3 * V_38 ;
V_38 = F_3 ( V_10 , V_37 & V_51 ) ;
F_20 (
V_46 , V_52 ,
V_13 , V_16 , V_25 , V_37 ,
L_9 , V_48 , V_38 ) ;
}
}
}
}
return;
}
case V_53 :
{
if ( V_25 != 2 )
{
break;
}
if ( V_10 -> V_35 == NULL )
{
}
if ( V_14 )
{
T_6 * V_46 ;
T_7 * V_47 ;
T_2 V_37 ;
T_8 V_48 ;
V_37 = F_21 ( V_13 , V_16 ) ;
V_47 = F_25 (
V_14 , V_10 -> V_17 ,
V_13 , V_16 , 2 , V_54 ) ;
F_10 ( V_15 , L_10 , V_37 ) ;
if ( V_37 != 0 )
{
V_46 = F_26 (
V_47 , V_55 ) ;
for ( V_48 = 0 ; V_48 < 16 ; ++ V_48 )
{
T_2 V_51 ;
V_51 = 1U << ( 15 - V_48 ) ;
if ( V_37 & V_51 )
{
const T_3 * V_38 ;
V_38 = F_3 ( V_10 , V_37 & V_51 ) ;
F_20 (
V_46 , V_56 ,
V_13 , V_16 , V_25 , V_37 ,
L_9 , V_48 , V_38 ) ;
}
}
}
}
return;
}
case V_57 :
{
if ( V_25 != 4 )
{
break;
}
if ( V_10 -> V_35 == NULL )
{
}
if ( V_14 )
{
T_6 * V_46 ;
T_7 * V_47 ;
T_4 V_37 ;
T_8 V_48 ;
V_37 = F_22 ( V_13 , V_16 ) ;
V_47 = F_25 (
V_14 , V_10 -> V_17 ,
V_13 , V_16 , 4 , V_54 ) ;
F_10 ( V_15 , L_11 , V_37 ) ;
if ( V_37 != 0 )
{
V_46 = F_26 (
V_47 , V_58 ) ;
for ( V_48 = 0 ; V_48 < 32 ; ++ V_48 )
{
T_4 V_51 ;
V_51 = 1U << ( 31 - V_48 ) ;
if ( V_37 & V_51 )
{
const T_3 * V_38 ;
V_38 = F_3 ( V_10 , V_37 & V_51 ) ;
F_20 (
V_46 , V_59 ,
V_13 , V_16 , V_25 , V_37 ,
L_9 , V_48 , V_38 ) ;
}
}
}
}
return;
}
case V_60 :
{
if ( V_25 == 4 )
{
if ( V_14 )
{
F_5 (
V_13 , V_14 , V_15 , V_16 , V_10 ) ;
}
return;
}
else if ( V_25 == 6 )
{
if ( V_14 )
{
F_14 (
V_13 , V_14 , V_15 , V_16 , V_25 , V_10 ) ;
}
return;
}
else if ( V_25 == 16 )
{
if ( V_14 )
{
F_11 (
V_13 , V_14 , V_15 , V_16 , V_10 ) ;
}
return;
}
else
{
break;
}
}
case V_61 :
{
if ( V_14 )
{
const T_3 * V_62 ;
const T_3 * V_63 ;
const T_9 * V_26 = F_15 ( V_13 , V_16 , V_25 ) ;
const T_3 * V_38 = F_27 ( F_8 () , V_26 , F_28 ( V_25 , V_31 ) , 0 ) ;
if ( V_25 <= V_31 )
{
V_62 = L_3 ;
V_63 = L_4 ;
}
else
{
V_62 = L_12 ;
V_63 = L_13 ;
}
F_29 (
V_14 , V_10 -> V_17 ,
V_13 , V_16 , V_25 , V_26 ,
V_62 , V_38 ) ;
F_10 (
V_15 , V_63 , V_38 ) ;
}
return;
}
case V_64 :
{
if ( V_25 != 1 )
{
break;
}
if ( V_14 )
{
T_9 V_37 ;
V_37 = F_19 ( V_13 , V_16 ) ;
F_20 (
V_14 , V_10 -> V_17 ,
V_13 , V_16 , V_25 , V_37 ,
L_14 , V_37 ) ;
F_10 ( V_15 , L_8 , V_37 ) ;
}
return;
}
case V_65 :
{
if ( V_25 != 2 )
{
break;
}
if ( V_14 )
{
T_2 V_37 ;
V_37 = F_21 ( V_13 , V_16 ) ;
F_20 (
V_14 , V_10 -> V_17 ,
V_13 , V_16 , V_25 , V_37 ,
L_15 , V_37 ) ;
F_10 ( V_15 , L_10 , V_37 ) ;
}
return;
}
case V_66 :
{
if ( V_25 != 4 )
{
break;
}
if ( V_14 )
{
T_4 V_37 ;
V_37 = F_22 ( V_13 , V_16 ) ;
F_20 (
V_14 , V_10 -> V_17 ,
V_13 , V_16 , V_25 , V_37 ,
L_16 , V_37 ) ;
F_10 ( V_15 , L_11 , V_37 ) ;
}
return;
}
case V_67 :
{
if ( V_25 != 1 )
{
break;
}
if ( V_14 )
{
T_9 V_37 ;
V_37 = F_19 ( V_13 , V_16 ) ;
F_20 (
V_14 , V_10 -> V_17 ,
V_13 , V_16 , V_25 , V_37 ,
L_17 , V_37 ) ;
F_10 ( V_15 , L_18 , V_37 ) ;
}
return;
}
case V_68 :
{
if ( V_25 != 2 )
{
break;
}
if ( V_14 )
{
T_2 V_37 ;
V_37 = F_21 ( V_13 , V_16 ) ;
F_20 (
V_14 , V_10 -> V_17 ,
V_13 , V_16 , V_25 , V_37 ,
L_17 , V_37 ) ;
F_10 ( V_15 , L_18 , V_37 ) ;
}
return;
}
case V_69 :
{
if ( V_25 != 4 )
{
break;
}
if ( V_14 )
{
T_4 V_37 ;
V_37 = F_22 ( V_13 , V_16 ) ;
F_20 (
V_14 , V_10 -> V_17 ,
V_13 , V_16 , V_25 , V_37 ,
L_17 , V_37 ) ;
F_10 ( V_15 , L_18 , V_37 ) ;
}
return;
}
case V_70 :
{
if ( V_8 )
{
F_2 (
L_19 , V_10 -> V_36 , V_10 -> type ) ;
}
if ( V_14 )
{
const T_3 * V_71 ;
const T_9 * V_26 = F_15 ( V_13 , V_16 , V_25 ) ;
const T_3 * V_38 = F_27 ( F_8 () , V_26 , F_28 ( V_25 , V_31 ) , 0 ) ;
if ( V_25 <= V_31 )
{
V_71 = L_20 ;
}
else
{
V_71 = L_21 ;
}
F_29 (
V_14 , V_10 -> V_17 ,
V_13 , V_16 , V_25 , V_26 ,
V_71 , V_32 , V_38 ) ;
F_10 ( V_15 , L_22 ) ;
}
return;
}
case V_72 :
{
if ( V_25 == 4 )
{
if ( V_14 )
{
F_5 (
V_13 , V_14 , V_15 , V_16 , V_10 ) ;
}
return;
}
else if ( V_25 == 16 )
{
if ( V_14 )
{
F_11 (
V_13 , V_14 , V_15 , V_16 , V_10 ) ;
}
return;
}
else
{
break;
}
}
case V_73 :
{
if ( V_25 != 4 )
{
break;
}
if ( V_14 )
{
F_5 (
V_13 , V_14 , V_15 , V_16 , V_10 ) ;
}
return;
}
case V_74 :
{
if ( V_25 % 2 != 0 )
{
break;
}
if ( V_14 && V_25 > 0 )
{
T_6 * V_75 ;
T_7 * V_47 ;
const T_8 V_76 = 8 ;
V_75 = F_30 (
V_14 , V_13 , V_16 , V_25 ,
V_77 , NULL , L_23 ) ;
V_47 = F_25 (
V_75 , V_10 -> V_17 ,
V_13 , V_16 , V_25 , V_49 ) ;
F_31 ( V_47 ) ;
while ( V_16 < F_18 ( V_13 ) )
{
T_2 V_78 ;
const T_3 * V_79 ;
V_78 = F_21 ( V_13 , V_16 ) ;
V_79 = F_32 ( V_78 ) ;
F_20 (
V_75 , V_10 -> V_80 ,
V_13 , V_16 , 2 , V_78 ,
L_24 , V_79 , V_78 ) ;
if ( V_16 == 0 )
{
F_10 ( V_15 , L_4 , V_79 ) ;
}
else if ( V_16 < 2 * V_76 )
{
F_10 ( V_15 , L_25 , V_79 ) ;
}
else if ( V_16 == 2 * V_76 )
{
F_10 ( V_15 , L_26 ) ;
}
V_16 += 2 ;
}
}
return;
}
case V_81 :
{
if ( V_25 % 4 != 0 )
{
break;
}
if ( V_14 && V_25 > 0 )
{
T_6 * V_82 ;
T_7 * V_47 ;
const T_8 V_83 = 3 ;
V_82 = F_30 (
V_14 , V_13 , V_16 , V_25 ,
V_84 , NULL , L_23 ) ;
V_47 = F_25 (
V_82 , V_10 -> V_17 ,
V_13 , V_16 , V_25 , V_49 ) ;
F_31 ( V_47 ) ;
while ( V_16 < F_18 ( V_13 ) )
{
T_2 V_85 ;
T_2 V_86 ;
T_6 * V_87 ;
V_85 = F_21 ( V_13 , V_16 ) ;
V_86 = F_21 ( V_13 , V_16 + 2 ) ;
V_87 = F_33 (
V_82 , V_13 , V_16 , 4 ,
V_88 , NULL , L_27 , V_85 , V_86 ) ;
V_47 = F_25 (
V_87 , V_10 -> V_89 ,
V_13 , V_16 , 2 , V_54 ) ;
F_31 ( V_47 ) ;
V_47 = F_25 (
V_87 , V_10 -> V_90 ,
V_13 , V_16 + 2 , 2 , V_54 ) ;
F_31 ( V_47 ) ;
if ( V_16 == 0 )
{
F_10 (
V_15 , L_28 , V_85 , V_86 ) ;
}
else if ( V_16 < 4 * V_83 )
{
F_10 (
V_15 , L_29 , V_85 , V_86 ) ;
}
else if ( V_16 == 4 * V_83 )
{
F_10 ( V_15 , L_26 ) ;
}
V_16 += 4 ;
}
}
return;
}
case V_91 :
{
if ( V_25 % 8 != 0 )
{
break;
}
if ( V_14 && V_25 > 0 )
{
T_6 * V_92 ;
T_7 * V_47 ;
V_92 = F_30 (
V_14 , V_13 , V_16 , V_25 ,
V_93 , NULL , L_23 ) ;
V_47 = F_25 (
V_92 , V_10 -> V_17 ,
V_13 , V_16 , V_25 , V_49 ) ;
F_31 ( V_47 ) ;
if ( V_25 % 32 == 0 )
{
while ( V_16 < F_18 ( V_13 ) )
{
T_6 * V_94 ;
V_94 = F_30 (
V_92 , V_13 , V_16 , 32 ,
V_95 , NULL , L_30 ) ;
F_25 (
V_94 ,
V_10 -> V_23 ,
V_13 , V_16 , 16 , V_49 ) ;
V_16 += 16 ;
F_25 (
V_94 ,
V_10 -> V_96 ,
V_13 , V_16 , 16 , V_49 ) ;
V_16 += 16 ;
}
}
else
{
while ( V_16 < F_18 ( V_13 ) )
{
T_6 * V_94 ;
T_4 V_18 ;
const T_3 * V_38 ;
V_94 = F_30 (
V_92 , V_13 , V_16 , 8 ,
V_95 , NULL , L_31 ) ;
V_18 = F_6 ( V_13 , V_16 ) ;
F_25 (
V_94 ,
V_10 -> V_20 ,
V_13 , V_16 , 4 , V_54 ) ;
F_10 (
V_47 , L_32 ,
F_34 ( V_18 ) , F_35 ( V_13 , V_16 ) ) ;
V_16 += 4 ;
V_38 = F_35 ( V_13 , V_16 ) ;
F_25 (
V_94 ,
V_10 -> V_97 ,
V_13 , V_16 , 4 , V_54 ) ;
F_10 (
V_47 , L_33 , V_38 ) ;
V_16 += 4 ;
}
}
}
return;
}
case V_98 :
{
T_9 V_99 ;
T_9 V_100 = 0 ;
V_99 = F_19 ( V_13 , V_16 ) ;
if ( V_99 == V_101 || V_99 == V_102 )
{
V_100 = F_19 ( V_13 , V_16 + 4 ) ;
}
F_36 ( T_11 -> V_103 , V_104 , L_34 ) ;
F_36 ( T_11 -> V_103 , V_104 ,
F_4 ( V_99 , V_105 , L_35 ) ) ;
if ( V_99 == V_101 || V_99 == V_102 )
{
F_36 ( T_11 -> V_103 , V_104 , L_36 ) ;
F_36 ( T_11 -> V_103 , V_104 ,
F_37 ( V_100 , & V_106 , L_37 ) ) ;
}
F_36 ( T_11 -> V_103 , V_104 , L_38 ) ;
{
T_6 * V_107 ;
T_7 * V_47 ;
T_12 V_108 ;
T_5 * V_109 ;
V_47 = F_25 ( V_14 , V_10 -> V_17 , V_13 ,
V_16 , V_25 , V_49 ) ;
F_38 ( V_47 , L_23 ) ;
V_107 = F_26 ( V_47 , V_110 ) ;
F_10 ( V_47 , L_39 ,
F_4 ( V_99 , V_105 ,
L_35 ) ) ;
if ( V_99 == V_101 || V_99 == V_102 )
{
F_10 ( V_47 , L_25 ,
F_37 ( V_100 , & V_106 ,
L_37 ) ) ;
}
F_10 ( V_47 , L_40 ) ;
V_109 = F_39 ( V_13 , V_16 ) ;
V_108 = F_40 ( T_11 -> V_103 , - 1 ) ;
F_41 ( T_11 -> V_103 , - 1 , FALSE ) ;
F_42 ( V_111 , V_109 , T_11 , V_107 ) ;
F_41 ( T_11 -> V_103 , - 1 , V_108 ) ;
}
return;
}
case V_112 :
{
if ( V_25 < 3 )
{
break;
}
if ( V_14 )
{
T_6 * V_113 ;
T_7 * V_47 ;
T_4 V_114 ;
const T_3 * V_115 ;
V_113 = F_30 (
V_14 , V_13 , V_16 , V_25 ,
V_116 , NULL , L_23 ) ;
V_47 = F_25 (
V_113 , V_10 -> V_17 ,
V_13 , V_16 , V_25 , V_49 ) ;
F_31 ( V_47 ) ;
V_114 = F_43 ( V_13 , V_16 ) ;
V_115 = F_44 ( V_114 , & V_117 , L_2 ) ;
F_20 (
V_113 , V_10 -> V_118 ,
V_13 , V_16 , 3 , V_114 ,
L_41 , V_115 , V_114 ) ;
F_10 ( V_15 , L_4 , V_115 ) ;
V_16 += 3 ;
if ( V_16 < F_18 ( V_13 ) )
{
F_25 (
V_113 , V_10 -> V_119 ,
V_13 , V_16 , V_25 - V_16 , V_49 ) ;
}
}
return;
}
case V_120 :
{
if ( V_14 )
{
const T_3 * V_62 ;
const T_3 * V_63 ;
const T_9 * V_26 = F_15 ( V_13 , V_16 , V_25 ) ;
const T_3 * V_38 =
F_27 ( F_8 () , V_26 , F_28 ( V_25 , V_31 ) , 0 ) ;
if ( V_25 <= V_31 )
{
V_62 = L_20 ;
V_63 = L_42 ;
}
else
{
V_62 = L_21 ;
V_63 = L_43 ;
}
F_29 (
V_14 , V_10 -> V_17 ,
V_13 , V_16 , V_25 , V_26 ,
V_62 , V_32 , V_38 ) ;
F_10 (
V_15 , V_63 , V_32 , V_38 ) ;
}
return;
}
default:
if ( V_8 )
{
F_2 (
L_44 , V_10 -> V_33 ) ;
}
break;
}
if ( V_14 )
{
const T_3 * V_71 ;
const T_9 * V_26 = F_15 ( V_13 , V_16 , V_25 ) ;
const T_3 * V_38 = F_27 ( F_8 () , V_26 , F_28 ( V_25 , V_31 ) , 0 ) ;
if ( V_25 <= V_31 )
{
V_71 = L_20 ;
}
else
{
V_71 = L_21 ;
}
F_29 (
V_14 , V_121 ,
V_13 , V_16 , V_25 , V_26 ,
V_71 , V_32 , V_38 ) ;
}
}
static T_8 F_45 (
T_5 * V_13 ,
T_10 * T_11 ,
T_6 * V_14 )
{
T_8 V_16 ;
V_16 = 0 ;
while ( V_16 < F_18 ( V_13 ) )
{
const T_1 * V_10 ;
T_6 * V_122 ;
T_7 * V_15 ;
T_2 type ;
T_2 V_25 ;
T_8 V_123 ;
type = F_21 ( V_13 , V_16 ) ;
V_10 = F_1 ( type ) ;
V_25 = F_21 ( V_13 , V_16 + 2 ) ;
#if 0
pad = 4 - (length % 4);
if (pad == 4)
{
pad = 0;
}
#endif
V_123 = 0 ;
{
T_7 * V_124 ;
T_13 V_125 = F_28 (
( T_13 ) ( 4 + V_25 + V_123 ) , F_46 ( V_13 , V_16 ) ) ;
V_15 = F_25 (
V_14 , V_10 -> V_126 ,
V_13 , V_16 , V_125 , V_49 ) ;
F_38 ( V_15 , L_45 , V_10 -> V_36 ) ;
if ( V_10 -> V_33 == V_120 )
{
F_10 ( V_15 , L_46 , type ) ;
}
if ( V_10 -> V_33 == V_127 )
{
F_10 ( V_15 , L_47 ) ;
}
V_122 = F_26 (
V_15 , V_128 ) ;
V_124 = F_20 (
V_122 , V_129 ,
V_13 , V_16 , 2 , type ,
L_48 , V_10 -> V_36 , type ) ;
if ( V_10 -> V_33 == V_120 )
{
F_47 ( T_11 , V_124 , & V_130 ,
L_49 ,
type ) ;
}
F_48 (
V_122 , V_131 ,
V_13 , V_16 + 2 , 2 , V_25 ) ;
}
V_16 += 4 ;
if ( V_10 -> V_33 == V_127 )
{
if ( V_25 == 0 )
{
}
else if ( F_49 ( V_13 , V_16 ) > 0 )
{
T_5 * V_132 ;
V_132 = F_50 (
V_13 , V_16 ,
F_28 ( V_25 , F_46 ( V_13 , V_16 ) ) ,
V_25 ) ;
F_45 ( V_132 , T_11 , V_122 ) ;
}
else
{
F_51 ( V_13 , V_16 , V_25 + V_123 ) ;
}
}
else
{
T_5 * V_132 ;
F_51 ( V_13 , V_16 , V_25 + V_123 ) ;
V_132 = F_50 (
V_13 , V_16 ,
F_28 ( V_25 , F_46 ( V_13 , V_16 ) ) ,
V_25 ) ;
F_17 (
V_132 , T_11 , V_122 , V_15 , V_10 ) ;
}
V_16 += V_25 + V_123 ;
}
return V_16 ;
}
static T_8 F_52 (
T_5 * V_13 ,
T_10 * T_11 ,
T_6 * V_14 )
{
T_8 V_16 = 0 ;
T_2 V_133 ;
T_4 V_134 ;
const T_9 * V_135 ;
T_2 V_136 = 0 ;
T_12 V_137 ;
if ( V_14 )
{
F_25 (
V_14 , V_138 ,
V_13 , V_16 , 6 , V_49 ) ;
}
V_135 = F_53 ( V_13 , V_16 ) ;
V_16 += 6 ;
V_134 = F_22 ( V_13 , V_16 ) ;
if ( V_14 )
{
F_48 (
V_14 , V_139 ,
V_13 , V_16 , 4 , V_134 ) ;
}
V_16 += 4 ;
V_137 = FALSE ;
V_133 = F_21 ( V_13 , V_16 ) ;
if ( V_140 )
{
const T_2 V_51 = 0x7fff ;
if ( V_133 & 0x8000 )
{
F_20 (
V_14 , V_141 ,
V_13 , V_16 , 2 , V_133 ,
L_50 , V_51 & V_133 , V_133 ) ;
V_136 = V_133 & V_51 ;
V_137 = TRUE ;
}
else
{
F_20 (
V_14 , V_141 ,
V_13 , V_16 , 2 , V_133 ,
L_51 , V_133 ) ;
V_136 = V_133 ;
}
}
else
{
F_48 (
V_14 , V_141 ,
V_13 , V_16 , 2 , V_133 ) ;
V_136 = V_133 ;
}
V_16 += 2 ;
V_133 = F_21 ( V_13 , V_16 ) ;
if ( V_14 )
{
F_48 (
V_14 , V_142 ,
V_13 , V_16 , 2 , V_133 ) ;
}
V_16 += 2 ;
if ( F_49 ( V_13 , V_16 ) > 0 )
{
T_5 * V_132 ;
V_132 = F_39 ( V_13 , V_16 ) ;
V_16 += F_45 ( V_132 , T_11 , V_14 ) ;
}
F_54 ( T_11 -> V_103 , V_104 , L_52 , V_135 ) ;
if ( V_137 )
{
F_54 ( T_11 -> V_103 , V_104 , L_53 , V_136 ) ;
}
else
{
F_54 ( T_11 -> V_103 , V_104 , L_54 , V_136 ) ;
}
return V_16 ;
}
static const T_3 *
F_55 (
const T_4 V_143 ,
const T_14 * const V_144 ,
const T_4 V_145 )
{
const T_14 * V_146 ;
const T_14 * V_1 = NULL ;
for( V_146 = V_144 ; V_146 -> V_147 . V_148 ; V_146 ++ )
{
if ( ( V_146 -> V_147 . V_37 == V_143 ) && ( V_146 -> V_6 <= V_145 ) )
{
if ( ! V_1 || ( V_146 -> V_6 > V_1 -> V_6 ) )
{
V_1 = V_146 ;
}
}
}
return V_1 ? V_1 -> V_147 . V_148 : NULL ;
}
static int
F_56 (
T_5 * V_13 ,
T_10 * T_11 ,
T_6 * V_14 ,
void * T_15 V_30 )
{
static const T_3 V_149 [] = L_2 ;
T_7 * V_150 = NULL ;
T_7 * V_47 = NULL ;
T_6 * V_151 = NULL ;
T_5 * V_152 ;
T_8 V_16 ;
T_9 V_153 ;
T_9 V_154 ;
const T_3 * V_155 ;
T_7 * V_156 ;
T_2 V_25 ;
const T_16 * V_26 = NULL ;
const T_3 * V_157 ;
T_17 V_48 ;
#if 0
if (tvb_reported_length(tvb) < WIMAXASNCP_HEADER_SIZE)
{
return 0;
}
#endif
if ( F_57 ( V_13 , 0 , 1 ) && F_19 ( V_13 , 0 ) != 1 )
{
return 0 ;
}
F_58 ( T_11 -> V_103 , V_158 , L_55 ) ;
F_59 ( T_11 -> V_103 , V_104 ) ;
V_16 = 0 ;
if ( V_159 == - 1 )
{
F_60 ( L_56 ) ;
}
if ( V_14 )
{
V_150 = F_25 (
V_14 , V_160 ,
V_13 , 0 , F_28 ( V_161 , F_61 ( V_13 ) ) , V_49 ) ;
V_151 = F_26 (
V_150 , V_162 ) ;
}
if ( V_14 )
{
F_25 (
V_151 , V_159 ,
V_13 , V_16 , 1 , V_54 ) ;
}
V_16 += 1 ;
V_153 = F_19 ( V_13 , V_16 ) ;
if ( V_14 )
{
T_6 * V_46 ;
if ( V_153 == 0 )
{
F_20 (
V_151 , V_163 ,
V_13 , V_16 , 1 , V_153 ,
L_57 , V_153 ) ;
}
else
{
T_8 V_164 ;
V_47 = F_20 (
V_151 , V_163 ,
V_13 , V_16 , 1 , V_153 ,
L_58 ) ;
if ( V_153 & ( V_165 | V_166 ) )
{
if ( V_153 & V_165 )
{
F_10 ( V_47 , L_59 ) ;
}
if ( V_153 & V_166 )
{
F_10 ( V_47 , L_60 ) ;
}
F_10 ( V_47 , L_61 ) ;
}
F_10 ( V_47 , L_62 , V_153 ) ;
V_46 = F_26 (
V_47 , V_167 ) ;
for ( V_164 = 0 ; V_164 < 8 ; ++ V_164 )
{
T_9 V_51 ;
V_51 = 1U << ( 7 - V_164 ) ;
if ( V_153 & V_51 )
{
F_20 (
V_46 , V_163 ,
V_13 , V_16 , 1 , V_153 ,
L_9 ,
V_164 ,
F_4 (
V_153 & V_51 , V_168 , L_2 ) ) ;
}
}
}
}
V_16 += 1 ;
V_154 = F_19 ( V_13 , V_16 ) ;
V_155 = F_55 ( V_154 ,
V_169 ,
V_7 ) ;
if ( V_155 )
{
F_20 (
V_151 , V_170 ,
V_13 , V_16 , 1 , V_154 ,
L_63 , V_155 , V_154 ) ;
}
else
{
V_156 = F_20 (
V_151 , V_170 ,
V_13 , V_16 , 1 , V_154 ,
L_64 , V_154 ) ;
F_47 ( T_11 , V_156 ,
& V_171 ,
L_65 ,
V_154 ) ;
}
V_16 += 1 ;
V_153 = F_19 ( V_13 , V_16 ) ;
V_47 = F_20 (
V_151 , V_172 ,
V_13 , V_16 , 1 , V_153 ,
L_66 , F_4 ( V_153 >> 5 , V_173 , V_149 ) ) ;
F_10 ( V_47 , L_46 , ( ( V_153 >> 5 ) & 7 ) ) ;
for ( V_48 = 0 ; V_48 < F_62 ( V_174 ) ; ++ V_48 )
{
V_26 = & V_174 [ V_48 ] ;
if ( V_154 == V_26 -> V_154 )
{
break;
}
}
V_157 = V_26 ? F_55 ( 0x1f & V_153 , V_26 -> V_175 , V_7 ) : V_149 ;
if ( V_157 == NULL )
{
V_157 = V_149 ;
}
V_47 = F_20 (
V_151 , V_172 ,
V_13 , V_16 , 1 , V_153 ,
L_67 , V_157 ) ;
F_10 ( V_47 , L_46 , V_153 & 0x1F ) ;
if ( strcmp ( V_157 , V_149 ) == 0 )
{
F_47 ( T_11 , V_47 , & V_176 ,
L_68 ,
0x1f & V_153 ) ;
}
F_63 ( T_11 -> V_103 , V_104 , V_157 ) ;
V_16 += 1 ;
V_25 = F_21 ( V_13 , V_16 ) ;
if ( V_14 )
{
F_64 (
V_150 , F_65 ( V_161 , V_25 ) ) ;
V_47 = F_48 (
V_151 , V_177 ,
V_13 , V_16 , 2 , V_25 ) ;
}
V_16 += 2 ;
if ( V_25 < V_178 )
{
F_66 ( T_11 , V_47 , & V_179 ) ;
if ( V_14 )
{
F_10 (
V_47 , L_69 ) ;
}
if ( V_25 <= V_161 )
{
return V_16 ;
}
}
V_152 = F_50 (
V_13 , V_16 ,
F_28 ( V_25 , F_46 ( V_13 , V_16 ) ) ,
V_25 - V_161 ) ;
V_16 += F_52 (
V_152 , T_11 , V_151 ) ;
return V_16 ;
}
static char * F_67 (
char * V_36 )
{
char * V_180 = V_36 ;
char * V_181 = V_36 ;
char V_182 ;
for ( ; ( V_182 = * V_180 ) ; ++ V_180 )
{
if ( F_68 ( V_182 ) || V_182 == '_' || V_182 == '.' )
{
* ( V_181 ++ ) = V_182 ;
}
else if ( V_182 == ' ' || V_182 == '-' || V_182 == '/' )
{
if ( V_181 == V_36 )
{
continue;
}
if ( * ( V_181 - 1 ) == '_' )
{
continue;
}
* ( V_181 ++ ) = '_' ;
}
}
* V_181 = '\0' ;
return V_36 ;
}
static void F_69 (
int * V_183 ,
const char * V_36 ,
const char * V_184 ,
enum V_185 type ,
int V_186 ,
const char * V_187 )
{
T_18 V_188 = {
V_183 , { V_36 , V_184 , type , V_186 , NULL , 0x0 , V_187 , V_189 } } ;
F_70 ( V_190 . V_188 , V_188 ) ;
}
static void F_71 (
T_1 * V_3 )
{
char * V_36 ;
char * V_184 ;
const char * V_191 ;
char * V_187 ;
V_36 = F_72 ( V_3 -> V_36 ) ;
V_184 = F_67 ( F_73 ( L_70 , V_3 -> V_36 ) ) ;
switch ( V_3 -> V_33 )
{
case V_120 :
V_191 = L_71 ;
break;
case V_70 :
V_191 = F_73 ( L_72 , V_3 -> type ) ;
break;
case V_127 :
V_191 = F_73 ( L_73 , V_3 -> type ) ;
break;
case V_44 :
V_191 = F_73 ( L_74 , V_3 -> type ) ;
break;
default:
V_191 = F_73 ( L_75 , V_3 -> type ) ;
break;
}
F_69 (
& V_3 -> V_126 , V_36 , V_184 , V_192 , V_193 , V_191 ) ;
V_36 = F_72 ( L_23 ) ;
V_184 = F_67 ( F_73 ( L_76 , V_3 -> V_36 ) ) ;
V_187 = F_73 ( L_77 , V_3 -> type ) ;
switch ( V_3 -> V_33 )
{
case V_120 :
F_74 ( V_187 ) ;
F_69 (
& V_3 -> V_17 , V_36 , V_184 , V_192 , V_193 ,
L_78 ) ;
break;
case V_70 :
F_69 (
& V_3 -> V_17 , V_36 , V_184 , V_192 , V_193 , V_187 ) ;
break;
case V_127 :
case V_44 :
F_74 ( V_36 ) ;
F_74 ( V_184 ) ;
F_74 ( V_187 ) ;
break;
case V_61 :
F_69 (
& V_3 -> V_17 , V_36 , V_184 , V_192 , V_193 , V_187 ) ;
break;
case V_34 :
F_69 (
& V_3 -> V_17 , V_36 , V_184 , V_194 , V_195 , V_187 ) ;
break;
case V_39 :
F_69 (
& V_3 -> V_17 , V_36 , V_184 , V_196 , V_195 , V_187 ) ;
break;
case V_40 :
F_69 (
& V_3 -> V_17 , V_36 , V_184 , V_197 , V_195 , V_187 ) ;
break;
case V_41 :
F_69 (
& V_3 -> V_17 , V_36 , V_184 , V_198 , V_193 , V_187 ) ;
break;
case V_42 :
F_69 (
& V_3 -> V_17 , V_36 , V_184 , V_199 , V_193 , V_187 ) ;
break;
case V_45 :
F_69 (
& V_3 -> V_17 , V_36 , V_184 , V_194 , V_200 , V_187 ) ;
break;
case V_53 :
F_69 (
& V_3 -> V_17 , V_36 , V_184 , V_196 , V_200 , V_187 ) ;
break;
case V_57 :
F_69 (
& V_3 -> V_17 , V_36 , V_184 , V_197 , V_200 , V_187 ) ;
break;
case V_60 :
F_74 ( V_184 ) ;
V_184 = F_67 (
F_73 ( L_79 , V_3 -> V_36 ) ) ;
F_69 (
& V_3 -> V_20 , L_80 , V_184 , V_201 , V_193 , V_187 ) ;
V_184 = F_67 (
F_73 ( L_81 , V_3 -> V_36 ) ) ;
F_69 (
& V_3 -> V_23 , L_82 , V_184 , V_202 , V_193 , V_187 ) ;
V_184 = F_67 (
F_73 ( L_83 , V_3 -> V_36 ) ) ;
F_69 (
& V_3 -> V_28 , L_84 , V_184 , V_198 , V_193 , V_187 ) ;
break;
case V_64 :
F_69 (
& V_3 -> V_17 , V_36 , V_184 , V_194 , V_200 , V_187 ) ;
break;
case V_65 :
F_69 (
& V_3 -> V_17 , V_36 , V_184 , V_196 , V_200 , V_187 ) ;
break;
case V_66 :
F_69 (
& V_3 -> V_17 , V_36 , V_184 , V_197 , V_200 , V_187 ) ;
break;
case V_67 :
F_69 (
& V_3 -> V_17 , V_36 , V_184 , V_194 , V_195 , V_187 ) ;
break;
case V_68 :
F_69 (
& V_3 -> V_17 , V_36 , V_184 , V_196 , V_195 , V_187 ) ;
break;
case V_69 :
F_69 (
& V_3 -> V_17 , V_36 , V_184 , V_197 , V_195 , V_187 ) ;
break;
case V_72 :
F_74 ( V_184 ) ;
V_184 = F_67 (
F_73 ( L_79 , V_3 -> V_36 ) ) ;
F_69 (
& V_3 -> V_20 , L_80 , V_184 , V_201 , V_193 , V_187 ) ;
V_184 = F_67 (
F_73 ( L_81 , V_3 -> V_36 ) ) ;
F_69 (
& V_3 -> V_23 , L_82 , V_184 , V_202 , V_193 , V_187 ) ;
break;
case V_73 :
F_69 (
& V_3 -> V_17 , V_36 , V_184 , V_201 , V_193 , V_187 ) ;
break;
case V_74 :
F_69 (
& V_3 -> V_17 , V_36 , V_184 , V_192 , V_193 , V_187 ) ;
V_187 = F_73 ( L_85 , V_3 -> type ) ;
V_184 = F_67 (
F_73 ( L_86 , V_3 -> V_36 ) ) ;
F_69 (
& V_3 -> V_80 , L_87 , V_184 , V_196 , V_195 , V_187 ) ;
break;
case V_81 :
F_69 (
& V_3 -> V_17 , V_36 , V_184 , V_192 , V_193 , V_187 ) ;
V_187 = F_73 ( L_85 , V_3 -> type ) ;
V_184 = F_67 (
F_73 ( L_88 , V_3 -> V_36 ) ) ;
F_69 (
& V_3 -> V_89 , L_89 , V_184 , V_196 , V_195 , V_187 ) ;
V_184 = F_67 (
F_73 ( L_90 , V_3 -> V_36 ) ) ;
F_69 (
& V_3 -> V_90 , L_91 , V_184 , V_196 , V_195 , V_187 ) ;
break;
case V_91 :
F_69 (
& V_3 -> V_17 , V_36 , V_184 , V_192 , V_193 , V_187 ) ;
V_187 = F_73 ( L_85 , V_3 -> type ) ;
V_184 = F_67 (
F_73 ( L_92 , V_3 -> V_36 ) ) ;
F_69 (
& V_3 -> V_20 , L_80 , V_184 , V_201 , V_193 , V_187 ) ;
V_184 = F_67 (
F_73 ( L_93 , V_3 -> V_36 ) ) ;
F_69 (
& V_3 -> V_97 , L_94 , V_184 , V_201 , V_193 , V_187 ) ;
V_184 = F_67 (
F_73 ( L_95 , V_3 -> V_36 ) ) ;
F_69 (
& V_3 -> V_23 , L_82 , V_184 , V_202 , V_193 , V_187 ) ;
V_184 = F_67 (
F_73 ( L_96 , V_3 -> V_36 ) ) ;
F_69 (
& V_3 -> V_96 , L_97 , V_184 , V_202 , V_193 , V_187 ) ;
break;
case V_112 :
F_69 (
& V_3 -> V_17 , V_36 , V_184 , V_192 , V_193 , V_187 ) ;
V_187 = F_73 ( L_85 , V_3 -> type ) ;
V_184 = F_67 (
F_73 ( L_98 , V_3 -> V_36 ) ) ;
F_69 (
& V_3 -> V_118 , L_99 , V_184 , V_203 , V_195 , V_187 ) ;
V_184 = F_67 (
F_73 (
L_100 , V_3 -> V_36 ) ) ;
F_69 (
& V_3 -> V_119 , L_101 , V_184 , V_192 , V_193 ,
V_187 ) ;
break;
case V_98 :
V_187 = F_73 ( L_102 , V_36 ) ;
F_69 (
& V_3 -> V_17 , V_36 , V_184 , V_192 , V_193 , V_187 ) ;
break;
default:
F_69 (
& V_3 -> V_17 , V_36 , V_184 , V_192 , V_193 , V_187 ) ;
if ( V_8 )
{
F_2 (
L_44 , V_3 -> V_33 ) ;
}
break;
}
}
static void
F_75 ( const char * T_19 V_30 )
{
T_12 V_204 ;
T_12 V_205 ;
T_3 * V_206 ;
T_3 * V_207 ;
static T_18 V_208 [] = {
{
& V_159 ,
{
L_103 ,
L_56 ,
V_194 ,
V_195 ,
NULL ,
0x0 ,
NULL ,
V_189
}
} ,
{
& V_163 ,
{
L_104 ,
L_105 ,
V_194 ,
V_200 ,
NULL ,
0xff ,
NULL ,
V_189
}
} ,
{
& V_170 ,
{
L_106 ,
L_107 ,
V_194 ,
V_195 ,
NULL ,
0x0 ,
NULL ,
V_189
}
} ,
{
& V_172 ,
{
L_108 ,
L_109 ,
V_194 ,
V_200 ,
F_76 ( V_173 ) ,
0xE0 ,
NULL ,
V_189
}
} ,
#if 0
{
&hf_wimaxasncp_message_type,
{
"Message Type",
"wimaxasncp.message_type",
FT_UINT8,
BASE_HEX,
NULL,
0x1F,
NULL,
HFILL
}
},
#endif
#if 0
{
&hf_wimaxasncp_qos_msg,
{
"Message Type",
"wimaxasncp.qos_msg",
FT_UINT8,
BASE_HEX,
NULL,
0x1F,
NULL,
HFILL
}
},
#endif
#if 0
{
&hf_wimaxasncp_ho_control_msg,
{
"Message Type",
"wimaxasncp.ho_control_msg",
FT_UINT8,
BASE_HEX,
NULL,
0x1F,
NULL,
HFILL
}
},
#endif
#if 0
{
&hf_wimaxasncp_data_path_control_msg,
{
"Message Type",
"wimaxasncp.data_path_control_msg",
FT_UINT8,
BASE_HEX,
NULL,
0x1F,
NULL,
HFILL
}
},
#endif
#if 0
{
&hf_wimaxasncp_context_delivery_msg,
{
"Message Type",
"wimaxasncp.context_delivery_msg",
FT_UINT8,
BASE_HEX,
NULL,
0x1F,
NULL,
HFILL
}
},
#endif
#if 0
{
&hf_wimaxasncp_r3_mobility_msg,
{
"Message Type",
"wimaxasncp.r3_mobility_msg",
FT_UINT8,
BASE_HEX,
NULL,
0x1F,
NULL,
HFILL
}
},
#endif
#if 0
{
&hf_wimaxasncp_paging_msg,
{
"Message Type",
"wimaxasncp.paging_msg",
FT_UINT8,
BASE_HEX,
NULL,
0x1F,
NULL,
HFILL
}
},
#endif
#if 0
{
&hf_wimaxasncp_rrm_msg,
{
"Message Type",
"wimaxasncp.rrm_msg",
FT_UINT8,
BASE_HEX,
NULL,
0x1F,
NULL,
HFILL
}
},
#endif
#if 0
{
&hf_wimaxasncp_authentication_msg,
{
"Message Type",
"wimaxasncp.authentication_msg",
FT_UINT8,
BASE_HEX,
NULL,
0x1F,
NULL,
HFILL
}
},
#endif
#if 0
{
&hf_wimaxasncp_ms_state_msg,
{
"Message Type",
"wimaxasncp.ms_state_msg",
FT_UINT8,
BASE_HEX,
NULL,
0x1F,
NULL,
HFILL
}
},
#endif
#if 0
{
&hf_wimaxasncp_reauthentication_msg,
{
"Message Type",
"wimaxasncp.reauthentication_msg",
FT_UINT8,
BASE_HEX,
NULL,
0x1F,
NULL,
HFILL
}
},
#endif
#if 0
{
&hf_wimaxasncp_session_msg,
{
"Message Type",
"wimaxasncp.session_msg",
FT_UINT8,
BASE_HEX,
NULL,
0x1F,
NULL,
HFILL
}
},
#endif
{
& V_177 ,
{
L_110 ,
L_111 ,
V_196 ,
V_195 ,
NULL ,
0x0 ,
NULL ,
V_189
}
} ,
{
& V_138 ,
{
L_112 ,
L_113 ,
V_198 ,
V_193 ,
NULL ,
0x0 ,
NULL ,
V_189
}
} ,
{
& V_139 ,
{
L_114 ,
L_115 ,
V_197 ,
V_200 ,
NULL ,
0x0 ,
NULL ,
V_189
}
} ,
{
& V_141 ,
{
L_116 ,
L_117 ,
V_196 ,
V_200 ,
NULL ,
0x0 ,
NULL ,
V_189
}
} ,
{
& V_142 ,
{
L_114 ,
L_118 ,
V_196 ,
V_200 ,
NULL ,
0x0 ,
NULL ,
V_189
}
} ,
#if 0
{
&hf_wimaxasncp_tlv,
{
"TLV",
"wimaxasncp.tlv",
FT_BYTES,
BASE_NONE,
NULL,
0x0,
NULL,
HFILL
}
},
#endif
{
& V_129 ,
{
L_119 ,
L_120 ,
V_196 ,
V_195 ,
NULL ,
0x0 ,
NULL ,
V_189
}
} ,
{
& V_131 ,
{
L_110 ,
L_121 ,
V_196 ,
V_195 ,
NULL ,
0x0 ,
NULL ,
V_189
}
} ,
{
& V_121 ,
{
L_23 ,
L_122 ,
V_192 ,
V_193 ,
NULL ,
0x0 ,
NULL ,
V_189
}
} ,
{
& V_52 ,
{
L_23 ,
L_123 ,
V_194 ,
V_200 ,
NULL ,
0xff ,
NULL ,
V_189
}
} ,
{
& V_56 ,
{
L_23 ,
L_124 ,
V_196 ,
V_200 ,
NULL ,
0xffff ,
NULL ,
V_189
}
} ,
{
& V_59 ,
{
L_23 ,
L_125 ,
V_197 ,
V_200 ,
NULL ,
0xffffffff ,
NULL ,
V_189
}
} ,
#if 0
{
&hf_wimaxasncp_tlv_value_protocol,
{
"Value",
"wimaxasncp.tlv_value_protocol",
FT_UINT16,
BASE_DEC,
NULL,
0x0,
NULL,
HFILL
}
},
#endif
#if 0
{
&hf_wimaxasncp_tlv_value_vendor_id,
{
"Vendor ID",
"wimaxasncp.tlv_value_vendor_id",
FT_UINT24,
BASE_DEC,
NULL,
0x0,
NULL,
HFILL
}
}
#endif
} ;
static T_13 * V_209 [] = {
& V_162 ,
& V_167 ,
& V_128 ,
& V_50 ,
& V_55 ,
& V_58 ,
& V_77 ,
& V_84 ,
& V_93 ,
& V_95 ,
& V_110 ,
& V_116 ,
& V_88
} ;
static T_20 V_210 [] = {
{ & V_130 , { L_126 , V_211 , V_212 , L_127 , V_213 } } ,
{ & V_171 , { L_128 , V_211 , V_212 , L_129 , V_213 } } ,
{ & V_176 , { L_130 , V_211 , V_212 , L_131 , V_213 } } ,
{ & V_179 , { L_132 , V_214 , V_215 , L_133 , V_213 } } ,
} ;
T_21 * V_216 ;
V_204 = getenv ( L_134 ) != NULL ;
V_205 = getenv ( L_135 ) != NULL ;
V_206 = F_73 (
L_136 V_217 L_137 ,
F_77 () ) ;
V_2 =
F_78 ( V_206 , L_138 , V_204 , & V_207 ) ;
F_74 ( V_206 ) ;
if ( V_207 )
{
F_79 ( L_139 , V_207 ) ;
F_74 ( V_207 ) ;
}
if ( V_2 && V_205 )
{
F_80 ( stdout , V_2 ) ;
}
V_190 . V_188 =
F_81 ( FALSE , TRUE , sizeof( T_18 ) ) ;
F_82 (
V_190 . V_188 , V_208 , F_62 ( V_208 ) ) ;
V_190 . V_218 =
F_81 ( FALSE , TRUE , sizeof( T_13 * ) ) ;
F_82 (
V_190 . V_218 , V_209 , F_62 ( V_209 ) ) ;
if ( V_2 )
{
T_1 * V_3 ;
for ( V_3 = V_2 -> V_4 ; V_3 ; V_3 = V_3 -> V_5 )
{
if ( V_3 -> V_35 )
{
T_22 * V_219 ;
T_23 * V_220 = F_81 ( TRUE , TRUE , sizeof( V_221 ) ) ;
for ( V_219 = V_3 -> V_35 ; V_219 ; V_219 = V_219 -> V_5 )
{
V_221 V_47 = { V_219 -> V_11 , V_219 -> V_36 } ;
F_70 ( V_220 , V_47 ) ;
}
V_3 -> V_12 = ( V_221 * ) ( void * ) V_220 -> T_15 ;
}
F_71 ( V_3 ) ;
}
}
F_71 ( & V_9 ) ;
if ( V_8 )
{
if ( V_2 )
{
T_1 * V_3 ;
for ( V_3 = V_2 -> V_4 ; V_3 ; V_3 = V_3 -> V_5 )
{
F_83 (
L_140
L_141
L_142
L_143
L_144
L_145
L_146
L_147
L_148
L_149
L_150
L_151
L_152
L_153
L_154
L_155 ,
V_3 -> V_36 ,
V_3 -> type ,
V_3 -> V_222 ,
F_4 (
V_3 -> V_33 , V_223 , L_2 ) ,
V_3 -> V_126 ,
V_3 -> V_17 ,
V_3 -> V_20 ,
V_3 -> V_23 ,
V_3 -> V_28 ,
V_3 -> V_80 ,
V_3 -> V_89 ,
V_3 -> V_90 ,
V_3 -> V_97 ,
V_3 -> V_96 ,
V_3 -> V_118 ,
V_3 -> V_119 ) ;
}
}
}
F_84 (
V_160 ,
( T_18 * ) ( void * ) V_190 . V_188 -> T_15 ,
V_190 . V_188 -> V_224 ) ;
F_85 (
( T_13 * * ) ( void * ) V_190 . V_218 -> T_15 ,
V_190 . V_218 -> V_224 ) ;
V_216 = F_86 ( V_160 ) ;
F_87 ( V_216 , V_210 , F_62 ( V_210 ) ) ;
}
void
F_88 ( void )
{
T_24 * V_225 ;
V_160 = F_89 ( L_156 , L_157 , L_137 ) ;
V_226 = F_90 ( L_137 , F_56 , V_160 ) ;
V_225 = F_91 ( V_160 , NULL ) ;
F_92 (
V_225 ,
L_158 ,
L_159 ,
L_160
L_161 ,
& V_140 ) ;
F_92 (
V_225 ,
L_162 ,
L_163 ,
L_164 ,
& V_8 ) ;
F_93 (
V_225 ,
L_165 ,
L_166 ,
L_167 ,
& V_7 ,
V_227 ,
FALSE ) ;
F_94 ( L_137 , F_75 ) ;
}
void
F_95 ( void )
{
V_111 = F_96 ( L_168 , V_160 ) ;
F_97 ( L_169 , V_228 , V_226 ) ;
}
