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
const T_3 * V_38 = F_23 ( F_8 () , V_13 , V_16 , V_25 ) ;
F_24 (
V_14 , V_10 -> V_17 ,
V_13 , V_16 , V_25 , V_38 ,
L_3 , V_38 ) ;
F_10 (
V_15 , L_4 , V_38 ) ;
}
return;
}
case V_43 :
{
if ( V_25 != 0 )
{
break;
}
return;
}
case V_44 :
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
T_6 * V_45 ;
T_7 * V_46 ;
T_9 V_37 ;
T_8 V_47 ;
V_37 = F_19 ( V_13 , V_16 ) ;
V_46 = F_25 (
V_14 , V_10 -> V_17 ,
V_13 , V_16 , 1 , V_48 ) ;
F_10 ( V_15 , L_8 , V_37 ) ;
if ( V_37 != 0 )
{
V_45 = F_26 (
V_46 , V_49 ) ;
for ( V_47 = 0 ; V_47 < 8 ; ++ V_47 )
{
T_9 V_50 ;
V_50 = 1U << ( 7 - V_47 ) ;
if ( V_37 & V_50 )
{
const T_3 * V_38 ;
V_38 = F_3 ( V_10 , V_37 & V_50 ) ;
F_20 (
V_45 , V_51 ,
V_13 , V_16 , V_25 , V_37 ,
L_9 , V_47 , V_38 ) ;
}
}
}
}
return;
}
case V_52 :
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
T_6 * V_45 ;
T_7 * V_46 ;
T_2 V_37 ;
T_8 V_47 ;
V_37 = F_21 ( V_13 , V_16 ) ;
V_46 = F_25 (
V_14 , V_10 -> V_17 ,
V_13 , V_16 , 2 , V_53 ) ;
F_10 ( V_15 , L_10 , V_37 ) ;
if ( V_37 != 0 )
{
V_45 = F_26 (
V_46 , V_54 ) ;
for ( V_47 = 0 ; V_47 < 16 ; ++ V_47 )
{
T_2 V_50 ;
V_50 = 1U << ( 15 - V_47 ) ;
if ( V_37 & V_50 )
{
const T_3 * V_38 ;
V_38 = F_3 ( V_10 , V_37 & V_50 ) ;
F_20 (
V_45 , V_55 ,
V_13 , V_16 , V_25 , V_37 ,
L_9 , V_47 , V_38 ) ;
}
}
}
}
return;
}
case V_56 :
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
T_6 * V_45 ;
T_7 * V_46 ;
T_4 V_37 ;
T_8 V_47 ;
V_37 = F_22 ( V_13 , V_16 ) ;
V_46 = F_25 (
V_14 , V_10 -> V_17 ,
V_13 , V_16 , 4 , V_53 ) ;
F_10 ( V_15 , L_11 , V_37 ) ;
if ( V_37 != 0 )
{
V_45 = F_26 (
V_46 , V_57 ) ;
for ( V_47 = 0 ; V_47 < 32 ; ++ V_47 )
{
T_4 V_50 ;
V_50 = 1U << ( 31 - V_47 ) ;
if ( V_37 & V_50 )
{
const T_3 * V_38 ;
V_38 = F_3 ( V_10 , V_37 & V_50 ) ;
F_20 (
V_45 , V_58 ,
V_13 , V_16 , V_25 , V_37 ,
L_9 , V_47 , V_38 ) ;
}
}
}
}
return;
}
case V_59 :
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
case V_60 :
{
if ( V_14 )
{
const T_3 * V_61 ;
const T_3 * V_62 ;
const T_9 * V_26 = F_15 ( V_13 , V_16 , V_25 ) ;
const T_3 * V_38 = F_27 ( F_8 () , V_26 , F_28 ( V_25 , V_31 ) , 0 ) ;
if ( V_25 <= V_31 )
{
V_61 = L_3 ;
V_62 = L_4 ;
}
else
{
V_61 = L_12 ;
V_62 = L_13 ;
}
F_29 (
V_14 , V_10 -> V_17 ,
V_13 , V_16 , V_25 , V_26 ,
V_61 , V_38 ) ;
F_10 (
V_15 , V_62 , V_38 ) ;
}
return;
}
case V_63 :
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
case V_64 :
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
case V_65 :
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
case V_66 :
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
case V_67 :
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
case V_68 :
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
case V_69 :
{
if ( V_8 )
{
F_2 (
L_19 , V_10 -> V_36 , V_10 -> type ) ;
}
if ( V_14 )
{
const T_3 * V_70 ;
const T_9 * V_26 = F_15 ( V_13 , V_16 , V_25 ) ;
const T_3 * V_38 = F_27 ( F_8 () , V_26 , F_28 ( V_25 , V_31 ) , 0 ) ;
if ( V_25 <= V_31 )
{
V_70 = L_20 ;
}
else
{
V_70 = L_21 ;
}
F_29 (
V_14 , V_10 -> V_17 ,
V_13 , V_16 , V_25 , V_26 ,
V_70 , V_32 , V_38 ) ;
F_10 ( V_15 , L_22 ) ;
}
return;
}
case V_71 :
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
case V_72 :
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
case V_73 :
{
if ( V_25 % 2 != 0 )
{
break;
}
if ( V_14 && V_25 > 0 )
{
T_6 * V_74 ;
T_7 * V_46 ;
const T_8 V_75 = 8 ;
V_74 = F_30 (
V_14 , V_13 , V_16 , V_25 ,
V_76 , NULL , L_23 ) ;
V_46 = F_25 (
V_74 , V_10 -> V_17 ,
V_13 , V_16 , V_25 , V_48 ) ;
F_31 ( V_46 ) ;
while ( V_16 < F_18 ( V_13 ) )
{
T_2 V_77 ;
const T_3 * V_78 ;
V_77 = F_21 ( V_13 , V_16 ) ;
V_78 = F_32 ( V_77 ) ;
F_20 (
V_74 , V_10 -> V_79 ,
V_13 , V_16 , 2 , V_77 ,
L_24 , V_78 , V_77 ) ;
if ( V_16 == 0 )
{
F_10 ( V_15 , L_4 , V_78 ) ;
}
else if ( V_16 < 2 * V_75 )
{
F_10 ( V_15 , L_25 , V_78 ) ;
}
else if ( V_16 == 2 * V_75 )
{
F_10 ( V_15 , L_26 ) ;
}
V_16 += 2 ;
}
}
return;
}
case V_80 :
{
if ( V_25 % 4 != 0 )
{
break;
}
if ( V_14 && V_25 > 0 )
{
T_6 * V_81 ;
T_7 * V_46 ;
const T_8 V_82 = 3 ;
V_81 = F_30 (
V_14 , V_13 , V_16 , V_25 ,
V_83 , NULL , L_23 ) ;
V_46 = F_25 (
V_81 , V_10 -> V_17 ,
V_13 , V_16 , V_25 , V_48 ) ;
F_31 ( V_46 ) ;
while ( V_16 < F_18 ( V_13 ) )
{
T_2 V_84 ;
T_2 V_85 ;
T_6 * V_86 ;
V_84 = F_21 ( V_13 , V_16 ) ;
V_85 = F_21 ( V_13 , V_16 + 2 ) ;
V_86 = F_33 (
V_81 , V_13 , V_16 , 4 ,
V_87 , NULL , L_27 , V_84 , V_85 ) ;
V_46 = F_25 (
V_86 , V_10 -> V_88 ,
V_13 , V_16 , 2 , V_53 ) ;
F_31 ( V_46 ) ;
V_46 = F_25 (
V_86 , V_10 -> V_89 ,
V_13 , V_16 + 2 , 2 , V_53 ) ;
F_31 ( V_46 ) ;
if ( V_16 == 0 )
{
F_10 (
V_15 , L_28 , V_84 , V_85 ) ;
}
else if ( V_16 < 4 * V_82 )
{
F_10 (
V_15 , L_29 , V_84 , V_85 ) ;
}
else if ( V_16 == 4 * V_82 )
{
F_10 ( V_15 , L_26 ) ;
}
V_16 += 4 ;
}
}
return;
}
case V_90 :
{
if ( V_25 % 8 != 0 )
{
break;
}
if ( V_14 && V_25 > 0 )
{
T_6 * V_91 ;
T_7 * V_46 ;
V_91 = F_30 (
V_14 , V_13 , V_16 , V_25 ,
V_92 , NULL , L_23 ) ;
V_46 = F_25 (
V_91 , V_10 -> V_17 ,
V_13 , V_16 , V_25 , V_48 ) ;
F_31 ( V_46 ) ;
if ( V_25 % 32 == 0 )
{
while ( V_16 < F_18 ( V_13 ) )
{
T_6 * V_93 ;
V_93 = F_30 (
V_91 , V_13 , V_16 , 32 ,
V_94 , NULL , L_30 ) ;
F_25 (
V_93 ,
V_10 -> V_23 ,
V_13 , V_16 , 16 , V_48 ) ;
V_16 += 16 ;
F_25 (
V_93 ,
V_10 -> V_95 ,
V_13 , V_16 , 16 , V_48 ) ;
V_16 += 16 ;
}
}
else
{
while ( V_16 < F_18 ( V_13 ) )
{
T_6 * V_93 ;
T_4 V_18 ;
const T_3 * V_38 ;
V_93 = F_30 (
V_91 , V_13 , V_16 , 8 ,
V_94 , NULL , L_31 ) ;
V_18 = F_6 ( V_13 , V_16 ) ;
F_25 (
V_93 ,
V_10 -> V_20 ,
V_13 , V_16 , 4 , V_53 ) ;
F_10 (
V_46 , L_32 ,
F_34 ( V_18 ) , F_35 ( V_13 , V_16 ) ) ;
V_16 += 4 ;
V_38 = F_35 ( V_13 , V_16 ) ;
F_25 (
V_93 ,
V_10 -> V_96 ,
V_13 , V_16 , 4 , V_53 ) ;
F_10 (
V_46 , L_33 , V_38 ) ;
V_16 += 4 ;
}
}
}
return;
}
case V_97 :
{
T_9 V_98 ;
T_9 V_99 = 0 ;
V_98 = F_19 ( V_13 , V_16 ) ;
if ( V_98 == V_100 || V_98 == V_101 )
{
V_99 = F_19 ( V_13 , V_16 + 4 ) ;
}
F_36 ( T_11 -> V_102 , V_103 , L_34 ) ;
F_36 ( T_11 -> V_102 , V_103 ,
F_4 ( V_98 , V_104 , L_35 ) ) ;
if ( V_98 == V_100 || V_98 == V_101 )
{
F_36 ( T_11 -> V_102 , V_103 , L_36 ) ;
F_36 ( T_11 -> V_102 , V_103 ,
F_37 ( V_99 , & V_105 , L_37 ) ) ;
}
F_36 ( T_11 -> V_102 , V_103 , L_38 ) ;
{
T_6 * V_106 ;
T_7 * V_46 ;
T_12 V_107 ;
T_5 * V_108 ;
V_46 = F_25 ( V_14 , V_10 -> V_17 , V_13 ,
V_16 , V_25 , V_48 ) ;
F_38 ( V_46 , L_23 ) ;
V_106 = F_26 ( V_46 , V_109 ) ;
F_10 ( V_46 , L_39 ,
F_4 ( V_98 , V_104 ,
L_35 ) ) ;
if ( V_98 == V_100 || V_98 == V_101 )
{
F_10 ( V_46 , L_25 ,
F_37 ( V_99 , & V_105 ,
L_37 ) ) ;
}
F_10 ( V_46 , L_40 ) ;
V_108 = F_39 ( V_13 , V_16 ) ;
V_107 = F_40 ( T_11 -> V_102 ) ;
F_41 ( T_11 -> V_102 , FALSE ) ;
F_42 ( V_110 , V_108 , T_11 , V_106 ) ;
F_41 ( T_11 -> V_102 , V_107 ) ;
}
return;
}
case V_111 :
{
if ( V_25 < 3 )
{
break;
}
if ( V_14 )
{
T_6 * V_112 ;
T_7 * V_46 ;
T_4 V_113 ;
const T_3 * V_114 ;
V_112 = F_30 (
V_14 , V_13 , V_16 , V_25 ,
V_115 , NULL , L_23 ) ;
V_46 = F_25 (
V_112 , V_10 -> V_17 ,
V_13 , V_16 , V_25 , V_48 ) ;
F_31 ( V_46 ) ;
V_113 = F_43 ( V_13 , V_16 ) ;
V_114 = F_44 ( V_113 , & V_116 , L_2 ) ;
F_20 (
V_112 , V_10 -> V_117 ,
V_13 , V_16 , 3 , V_113 ,
L_41 , V_114 , V_113 ) ;
F_10 ( V_15 , L_4 , V_114 ) ;
V_16 += 3 ;
if ( V_16 < F_18 ( V_13 ) )
{
F_25 (
V_112 , V_10 -> V_118 ,
V_13 , V_16 , V_25 - V_16 , V_48 ) ;
}
}
return;
}
case V_119 :
{
if ( V_14 )
{
const T_3 * V_61 ;
const T_3 * V_62 ;
const T_9 * V_26 = F_15 ( V_13 , V_16 , V_25 ) ;
const T_3 * V_38 =
F_27 ( F_8 () , V_26 , F_28 ( V_25 , V_31 ) , 0 ) ;
if ( V_25 <= V_31 )
{
V_61 = L_20 ;
V_62 = L_42 ;
}
else
{
V_61 = L_21 ;
V_62 = L_43 ;
}
F_29 (
V_14 , V_10 -> V_17 ,
V_13 , V_16 , V_25 , V_26 ,
V_61 , V_32 , V_38 ) ;
F_10 (
V_15 , V_62 , V_32 , V_38 ) ;
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
const T_3 * V_70 ;
const T_9 * V_26 = F_15 ( V_13 , V_16 , V_25 ) ;
const T_3 * V_38 = F_27 ( F_8 () , V_26 , F_28 ( V_25 , V_31 ) , 0 ) ;
if ( V_25 <= V_31 )
{
V_70 = L_20 ;
}
else
{
V_70 = L_21 ;
}
F_29 (
V_14 , V_120 ,
V_13 , V_16 , V_25 , V_26 ,
V_70 , V_32 , V_38 ) ;
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
T_6 * V_121 ;
T_7 * V_15 ;
T_2 type ;
T_2 V_25 ;
T_8 V_122 ;
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
V_122 = 0 ;
{
T_7 * V_123 ;
T_13 V_124 = F_28 (
( T_13 ) ( 4 + V_25 + V_122 ) , F_46 ( V_13 , V_16 ) ) ;
V_15 = F_25 (
V_14 , V_10 -> V_125 ,
V_13 , V_16 , V_124 , V_48 ) ;
F_38 ( V_15 , L_45 , V_10 -> V_36 ) ;
if ( V_10 -> V_33 == V_119 )
{
F_10 ( V_15 , L_46 , type ) ;
}
if ( V_10 -> V_33 == V_126 )
{
F_10 ( V_15 , L_47 ) ;
}
V_121 = F_26 (
V_15 , V_127 ) ;
V_123 = F_20 (
V_121 , V_128 ,
V_13 , V_16 , 2 , type ,
L_48 , V_10 -> V_36 , type ) ;
if ( V_10 -> V_33 == V_119 )
{
F_47 ( T_11 , V_123 , & V_129 ,
L_49 ,
type ) ;
}
F_48 (
V_121 , V_130 ,
V_13 , V_16 + 2 , 2 , V_25 ) ;
}
V_16 += 4 ;
if ( V_10 -> V_33 == V_126 )
{
if ( V_25 == 0 )
{
}
else if ( F_49 ( V_13 , V_16 ) > 0 )
{
T_5 * V_131 ;
V_131 = F_50 (
V_13 , V_16 ,
F_28 ( V_25 , F_46 ( V_13 , V_16 ) ) ,
V_25 ) ;
F_45 ( V_131 , T_11 , V_121 ) ;
}
else
{
F_51 ( V_13 , V_16 , V_25 + V_122 ) ;
}
}
else
{
T_5 * V_131 ;
F_51 ( V_13 , V_16 , V_25 + V_122 ) ;
V_131 = F_50 (
V_13 , V_16 ,
F_28 ( V_25 , F_46 ( V_13 , V_16 ) ) ,
V_25 ) ;
F_17 (
V_131 , T_11 , V_121 , V_15 , V_10 ) ;
}
V_16 += V_25 + V_122 ;
}
return V_16 ;
}
static T_8 F_52 (
T_5 * V_13 ,
T_10 * T_11 ,
T_6 * V_14 )
{
T_8 V_16 = 0 ;
T_2 V_132 ;
T_4 V_133 ;
const T_9 * V_134 ;
T_2 V_135 = 0 ;
T_12 V_136 ;
if ( V_14 )
{
F_25 (
V_14 , V_137 ,
V_13 , V_16 , 6 , V_48 ) ;
}
V_134 = F_53 ( V_13 , V_16 ) ;
V_16 += 6 ;
V_133 = F_22 ( V_13 , V_16 ) ;
if ( V_14 )
{
F_48 (
V_14 , V_138 ,
V_13 , V_16 , 4 , V_133 ) ;
}
V_16 += 4 ;
V_136 = FALSE ;
V_132 = F_21 ( V_13 , V_16 ) ;
if ( V_139 )
{
const T_2 V_50 = 0x7fff ;
if ( V_132 & 0x8000 )
{
F_20 (
V_14 , V_140 ,
V_13 , V_16 , 2 , V_132 ,
L_50 , V_50 & V_132 , V_132 ) ;
V_135 = V_132 & V_50 ;
V_136 = TRUE ;
}
else
{
F_20 (
V_14 , V_140 ,
V_13 , V_16 , 2 , V_132 ,
L_51 , V_132 ) ;
V_135 = V_132 ;
}
}
else
{
F_48 (
V_14 , V_140 ,
V_13 , V_16 , 2 , V_132 ) ;
V_135 = V_132 ;
}
V_16 += 2 ;
V_132 = F_21 ( V_13 , V_16 ) ;
if ( V_14 )
{
F_48 (
V_14 , V_141 ,
V_13 , V_16 , 2 , V_132 ) ;
}
V_16 += 2 ;
if ( F_49 ( V_13 , V_16 ) > 0 )
{
T_5 * V_131 ;
V_131 = F_39 ( V_13 , V_16 ) ;
V_16 += F_45 ( V_131 , T_11 , V_14 ) ;
}
F_54 ( T_11 -> V_102 , V_103 , L_52 , V_134 ) ;
if ( V_136 )
{
F_54 ( T_11 -> V_102 , V_103 , L_53 , V_135 ) ;
}
else
{
F_54 ( T_11 -> V_102 , V_103 , L_54 , V_135 ) ;
}
return V_16 ;
}
static const T_3 *
F_55 (
const T_4 V_142 ,
const T_14 * const V_143 ,
const T_4 V_144 )
{
const T_14 * V_145 ;
const T_14 * V_1 = NULL ;
for( V_145 = V_143 ; V_145 -> V_146 . V_147 ; V_145 ++ )
{
if ( ( V_145 -> V_146 . V_37 == V_142 ) && ( V_145 -> V_6 <= V_144 ) )
{
if ( ! V_1 || ( V_145 -> V_6 > V_1 -> V_6 ) )
{
V_1 = V_145 ;
}
}
}
return V_1 ? V_1 -> V_146 . V_147 : NULL ;
}
static int
F_56 (
T_5 * V_13 ,
T_10 * T_11 ,
T_6 * V_14 ,
void * T_15 V_30 )
{
static const T_3 V_148 [] = L_2 ;
T_7 * V_149 = NULL ;
T_7 * V_46 = NULL ;
T_6 * V_150 = NULL ;
T_5 * V_151 ;
T_8 V_16 ;
T_9 V_152 ;
T_9 V_153 ;
const T_3 * V_154 ;
T_7 * V_155 ;
T_2 V_25 ;
const T_16 * V_26 = NULL ;
const T_3 * V_156 ;
T_17 V_47 ;
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
F_58 ( T_11 -> V_102 , V_157 , L_55 ) ;
F_59 ( T_11 -> V_102 , V_103 ) ;
V_16 = 0 ;
if ( V_2 == NULL )
{
F_60 ( NULL ) ;
}
if ( V_14 )
{
V_149 = F_25 (
V_14 , V_158 ,
V_13 , 0 , F_28 ( V_159 , F_61 ( V_13 ) ) , V_48 ) ;
V_150 = F_26 (
V_149 , V_160 ) ;
}
if ( V_14 )
{
F_25 (
V_150 , V_161 ,
V_13 , V_16 , 1 , V_53 ) ;
}
V_16 += 1 ;
V_152 = F_19 ( V_13 , V_16 ) ;
if ( V_14 )
{
T_6 * V_45 ;
if ( V_152 == 0 )
{
F_20 (
V_150 , V_162 ,
V_13 , V_16 , 1 , V_152 ,
L_56 , V_152 ) ;
}
else
{
T_8 V_163 ;
V_46 = F_20 (
V_150 , V_162 ,
V_13 , V_16 , 1 , V_152 ,
L_57 ) ;
if ( V_152 & ( V_164 | V_165 ) )
{
if ( V_152 & V_164 )
{
F_10 ( V_46 , L_58 ) ;
}
if ( V_152 & V_165 )
{
F_10 ( V_46 , L_59 ) ;
}
F_10 ( V_46 , L_60 ) ;
}
F_10 ( V_46 , L_61 , V_152 ) ;
V_45 = F_26 (
V_46 , V_166 ) ;
for ( V_163 = 0 ; V_163 < 8 ; ++ V_163 )
{
T_9 V_50 ;
V_50 = 1U << ( 7 - V_163 ) ;
if ( V_152 & V_50 )
{
F_20 (
V_45 , V_162 ,
V_13 , V_16 , 1 , V_152 ,
L_9 ,
V_163 ,
F_4 (
V_152 & V_50 , V_167 , L_2 ) ) ;
}
}
}
}
V_16 += 1 ;
V_153 = F_19 ( V_13 , V_16 ) ;
V_154 = F_55 ( V_153 ,
V_168 ,
V_7 ) ;
if ( V_154 )
{
F_20 (
V_150 , V_169 ,
V_13 , V_16 , 1 , V_153 ,
L_62 , V_154 , V_153 ) ;
}
else
{
V_155 = F_20 (
V_150 , V_169 ,
V_13 , V_16 , 1 , V_153 ,
L_63 , V_153 ) ;
F_47 ( T_11 , V_155 ,
& V_170 ,
L_64 ,
V_153 ) ;
}
V_16 += 1 ;
V_152 = F_19 ( V_13 , V_16 ) ;
V_46 = F_20 (
V_150 , V_171 ,
V_13 , V_16 , 1 , V_152 ,
L_65 , F_4 ( V_152 >> 5 , V_172 , V_148 ) ) ;
F_10 ( V_46 , L_46 , ( ( V_152 >> 5 ) & 7 ) ) ;
for ( V_47 = 0 ; V_47 < F_62 ( V_173 ) ; ++ V_47 )
{
V_26 = & V_173 [ V_47 ] ;
if ( V_153 == V_26 -> V_153 )
{
break;
}
}
V_156 = V_26 ? F_55 ( 0x1f & V_152 , V_26 -> V_174 , V_7 ) : V_148 ;
if ( V_156 == NULL )
{
V_156 = V_148 ;
}
V_46 = F_20 (
V_150 , V_171 ,
V_13 , V_16 , 1 , V_152 ,
L_66 , V_156 ) ;
F_10 ( V_46 , L_46 , V_152 & 0x1F ) ;
if ( strcmp ( V_156 , V_148 ) == 0 )
{
F_47 ( T_11 , V_46 , & V_175 ,
L_67 ,
0x1f & V_152 ) ;
}
F_63 ( T_11 -> V_102 , V_103 , V_156 ) ;
V_16 += 1 ;
V_25 = F_21 ( V_13 , V_16 ) ;
if ( V_14 )
{
F_64 (
V_149 , F_65 ( V_159 , V_25 ) ) ;
V_46 = F_48 (
V_150 , V_176 ,
V_13 , V_16 , 2 , V_25 ) ;
}
V_16 += 2 ;
if ( V_25 < V_177 )
{
F_66 ( T_11 , V_46 , & V_178 ) ;
if ( V_14 )
{
F_10 (
V_46 , L_68 ) ;
}
if ( V_25 <= V_159 )
{
return V_16 ;
}
}
V_151 = F_50 (
V_13 , V_16 ,
F_28 ( V_25 , F_46 ( V_13 , V_16 ) ) ,
V_25 - V_159 ) ;
V_16 += F_52 (
V_151 , T_11 , V_150 ) ;
return V_16 ;
}
static char * F_67 (
char * V_36 )
{
char * V_179 = V_36 ;
char * V_180 = V_36 ;
char V_181 ;
for ( ; ( V_181 = * V_179 ) ; ++ V_179 )
{
if ( F_68 ( V_181 ) || V_181 == '_' || V_181 == '.' )
{
* ( V_180 ++ ) = V_181 ;
}
else if ( V_181 == ' ' || V_181 == '-' || V_181 == '/' )
{
if ( V_180 == V_36 )
{
continue;
}
if ( * ( V_180 - 1 ) == '_' )
{
continue;
}
* ( V_180 ++ ) = '_' ;
}
}
* V_180 = '\0' ;
return V_36 ;
}
static void F_69 (
int * V_182 ,
const char * V_36 ,
const char * V_183 ,
enum V_184 type ,
int V_185 ,
const char * V_186 )
{
T_18 V_187 = {
V_182 , { V_36 , V_183 , type , V_185 , NULL , 0x0 , V_186 , V_188 } } ;
F_70 ( V_189 . V_187 , V_187 ) ;
}
static void F_71 (
T_1 * V_3 )
{
char * V_36 ;
char * V_183 ;
const char * V_190 ;
char * V_186 ;
V_36 = F_72 ( V_3 -> V_36 ) ;
V_183 = F_67 ( F_73 ( L_69 , V_3 -> V_36 ) ) ;
switch ( V_3 -> V_33 )
{
case V_119 :
V_190 = L_70 ;
break;
case V_69 :
V_190 = F_73 ( L_71 , V_3 -> type ) ;
break;
case V_126 :
V_190 = F_73 ( L_72 , V_3 -> type ) ;
break;
case V_43 :
V_190 = F_73 ( L_73 , V_3 -> type ) ;
break;
default:
V_190 = F_73 ( L_74 , V_3 -> type ) ;
break;
}
F_69 (
& V_3 -> V_125 , V_36 , V_183 , V_191 , V_192 , V_190 ) ;
V_36 = F_72 ( L_23 ) ;
V_183 = F_67 ( F_73 ( L_75 , V_3 -> V_36 ) ) ;
V_186 = F_73 ( L_76 , V_3 -> type ) ;
switch ( V_3 -> V_33 )
{
case V_119 :
F_74 ( V_186 ) ;
F_69 (
& V_3 -> V_17 , V_36 , V_183 , V_191 , V_192 ,
L_77 ) ;
break;
case V_69 :
F_69 (
& V_3 -> V_17 , V_36 , V_183 , V_191 , V_192 , V_186 ) ;
break;
case V_126 :
case V_43 :
F_74 ( V_36 ) ;
F_74 ( V_183 ) ;
F_74 ( V_186 ) ;
break;
case V_60 :
F_69 (
& V_3 -> V_17 , V_36 , V_183 , V_191 , V_192 , V_186 ) ;
break;
case V_34 :
F_69 (
& V_3 -> V_17 , V_36 , V_183 , V_193 , V_194 , V_186 ) ;
break;
case V_39 :
F_69 (
& V_3 -> V_17 , V_36 , V_183 , V_195 , V_194 , V_186 ) ;
break;
case V_40 :
F_69 (
& V_3 -> V_17 , V_36 , V_183 , V_196 , V_194 , V_186 ) ;
break;
case V_41 :
F_69 (
& V_3 -> V_17 , V_36 , V_183 , V_197 , V_192 , V_186 ) ;
break;
case V_42 :
F_69 (
& V_3 -> V_17 , V_36 , V_183 , V_198 , V_192 , V_186 ) ;
break;
case V_44 :
F_69 (
& V_3 -> V_17 , V_36 , V_183 , V_193 , V_199 , V_186 ) ;
break;
case V_52 :
F_69 (
& V_3 -> V_17 , V_36 , V_183 , V_195 , V_199 , V_186 ) ;
break;
case V_56 :
F_69 (
& V_3 -> V_17 , V_36 , V_183 , V_196 , V_199 , V_186 ) ;
break;
case V_59 :
F_74 ( V_183 ) ;
V_183 = F_67 (
F_73 ( L_78 , V_3 -> V_36 ) ) ;
F_69 (
& V_3 -> V_20 , L_79 , V_183 , V_200 , V_192 , V_186 ) ;
V_183 = F_67 (
F_73 ( L_80 , V_3 -> V_36 ) ) ;
F_69 (
& V_3 -> V_23 , L_81 , V_183 , V_201 , V_192 , V_186 ) ;
V_183 = F_67 (
F_73 ( L_82 , V_3 -> V_36 ) ) ;
F_69 (
& V_3 -> V_28 , L_83 , V_183 , V_197 , V_192 , V_186 ) ;
break;
case V_63 :
F_69 (
& V_3 -> V_17 , V_36 , V_183 , V_193 , V_199 , V_186 ) ;
break;
case V_64 :
F_69 (
& V_3 -> V_17 , V_36 , V_183 , V_195 , V_199 , V_186 ) ;
break;
case V_65 :
F_69 (
& V_3 -> V_17 , V_36 , V_183 , V_196 , V_199 , V_186 ) ;
break;
case V_66 :
F_69 (
& V_3 -> V_17 , V_36 , V_183 , V_193 , V_194 , V_186 ) ;
break;
case V_67 :
F_69 (
& V_3 -> V_17 , V_36 , V_183 , V_195 , V_194 , V_186 ) ;
break;
case V_68 :
F_69 (
& V_3 -> V_17 , V_36 , V_183 , V_196 , V_194 , V_186 ) ;
break;
case V_71 :
F_74 ( V_183 ) ;
V_183 = F_67 (
F_73 ( L_78 , V_3 -> V_36 ) ) ;
F_69 (
& V_3 -> V_20 , L_79 , V_183 , V_200 , V_192 , V_186 ) ;
V_183 = F_67 (
F_73 ( L_80 , V_3 -> V_36 ) ) ;
F_69 (
& V_3 -> V_23 , L_81 , V_183 , V_201 , V_192 , V_186 ) ;
break;
case V_72 :
F_69 (
& V_3 -> V_17 , V_36 , V_183 , V_200 , V_192 , V_186 ) ;
break;
case V_73 :
F_69 (
& V_3 -> V_17 , V_36 , V_183 , V_191 , V_192 , V_186 ) ;
V_186 = F_73 ( L_84 , V_3 -> type ) ;
V_183 = F_67 (
F_73 ( L_85 , V_3 -> V_36 ) ) ;
F_69 (
& V_3 -> V_79 , L_86 , V_183 , V_195 , V_194 , V_186 ) ;
break;
case V_80 :
F_69 (
& V_3 -> V_17 , V_36 , V_183 , V_191 , V_192 , V_186 ) ;
V_186 = F_73 ( L_84 , V_3 -> type ) ;
V_183 = F_67 (
F_73 ( L_87 , V_3 -> V_36 ) ) ;
F_69 (
& V_3 -> V_88 , L_88 , V_183 , V_195 , V_194 , V_186 ) ;
V_183 = F_67 (
F_73 ( L_89 , V_3 -> V_36 ) ) ;
F_69 (
& V_3 -> V_89 , L_90 , V_183 , V_195 , V_194 , V_186 ) ;
break;
case V_90 :
F_69 (
& V_3 -> V_17 , V_36 , V_183 , V_191 , V_192 , V_186 ) ;
V_186 = F_73 ( L_84 , V_3 -> type ) ;
V_183 = F_67 (
F_73 ( L_91 , V_3 -> V_36 ) ) ;
F_69 (
& V_3 -> V_20 , L_79 , V_183 , V_200 , V_192 , V_186 ) ;
V_183 = F_67 (
F_73 ( L_92 , V_3 -> V_36 ) ) ;
F_69 (
& V_3 -> V_96 , L_93 , V_183 , V_200 , V_192 , V_186 ) ;
V_183 = F_67 (
F_73 ( L_94 , V_3 -> V_36 ) ) ;
F_69 (
& V_3 -> V_23 , L_81 , V_183 , V_201 , V_192 , V_186 ) ;
V_183 = F_67 (
F_73 ( L_95 , V_3 -> V_36 ) ) ;
F_69 (
& V_3 -> V_95 , L_96 , V_183 , V_201 , V_192 , V_186 ) ;
break;
case V_111 :
F_69 (
& V_3 -> V_17 , V_36 , V_183 , V_191 , V_192 , V_186 ) ;
V_186 = F_73 ( L_84 , V_3 -> type ) ;
V_183 = F_67 (
F_73 ( L_97 , V_3 -> V_36 ) ) ;
F_69 (
& V_3 -> V_117 , L_98 , V_183 , V_202 , V_194 , V_186 ) ;
V_183 = F_67 (
F_73 (
L_99 , V_3 -> V_36 ) ) ;
F_69 (
& V_3 -> V_118 , L_100 , V_183 , V_191 , V_192 ,
V_186 ) ;
break;
case V_97 :
V_186 = F_73 ( L_101 , V_36 ) ;
F_69 (
& V_3 -> V_17 , V_36 , V_183 , V_191 , V_192 , V_186 ) ;
break;
default:
F_69 (
& V_3 -> V_17 , V_36 , V_183 , V_191 , V_192 , V_186 ) ;
if ( V_8 )
{
F_2 (
L_44 , V_3 -> V_33 ) ;
}
break;
}
}
static void
F_60 ( const char * T_19 V_30 )
{
T_12 V_203 ;
T_12 V_204 ;
T_3 * V_205 ;
T_3 * V_206 ;
static T_18 V_207 [] = {
{
& V_161 ,
{
L_102 ,
L_103 ,
V_193 ,
V_194 ,
NULL ,
0x0 ,
NULL ,
V_188
}
} ,
{
& V_162 ,
{
L_104 ,
L_105 ,
V_193 ,
V_199 ,
NULL ,
0xff ,
NULL ,
V_188
}
} ,
{
& V_169 ,
{
L_106 ,
L_107 ,
V_193 ,
V_194 ,
NULL ,
0x0 ,
NULL ,
V_188
}
} ,
{
& V_171 ,
{
L_108 ,
L_109 ,
V_193 ,
V_199 ,
F_75 ( V_172 ) ,
0xE0 ,
NULL ,
V_188
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
& V_176 ,
{
L_110 ,
L_111 ,
V_195 ,
V_194 ,
NULL ,
0x0 ,
NULL ,
V_188
}
} ,
{
& V_137 ,
{
L_112 ,
L_113 ,
V_197 ,
V_192 ,
NULL ,
0x0 ,
NULL ,
V_188
}
} ,
{
& V_138 ,
{
L_114 ,
L_115 ,
V_196 ,
V_199 ,
NULL ,
0x0 ,
NULL ,
V_188
}
} ,
{
& V_140 ,
{
L_116 ,
L_117 ,
V_195 ,
V_199 ,
NULL ,
0x0 ,
NULL ,
V_188
}
} ,
{
& V_141 ,
{
L_114 ,
L_118 ,
V_195 ,
V_199 ,
NULL ,
0x0 ,
NULL ,
V_188
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
& V_128 ,
{
L_119 ,
L_120 ,
V_195 ,
V_194 ,
NULL ,
0x0 ,
NULL ,
V_188
}
} ,
{
& V_130 ,
{
L_110 ,
L_121 ,
V_195 ,
V_194 ,
NULL ,
0x0 ,
NULL ,
V_188
}
} ,
{
& V_120 ,
{
L_23 ,
L_122 ,
V_191 ,
V_192 ,
NULL ,
0x0 ,
NULL ,
V_188
}
} ,
{
& V_51 ,
{
L_23 ,
L_123 ,
V_193 ,
V_199 ,
NULL ,
0xff ,
NULL ,
V_188
}
} ,
{
& V_55 ,
{
L_23 ,
L_124 ,
V_195 ,
V_199 ,
NULL ,
0xffff ,
NULL ,
V_188
}
} ,
{
& V_58 ,
{
L_23 ,
L_125 ,
V_196 ,
V_199 ,
NULL ,
0xffffffff ,
NULL ,
V_188
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
static T_13 * V_208 [] = {
& V_160 ,
& V_166 ,
& V_127 ,
& V_49 ,
& V_54 ,
& V_57 ,
& V_76 ,
& V_83 ,
& V_92 ,
& V_94 ,
& V_109 ,
& V_115 ,
& V_87
} ;
static T_20 V_209 [] = {
{ & V_129 , { L_126 , V_210 , V_211 , L_127 , V_212 } } ,
{ & V_170 , { L_128 , V_210 , V_211 , L_129 , V_212 } } ,
{ & V_175 , { L_130 , V_210 , V_211 , L_131 , V_212 } } ,
{ & V_178 , { L_132 , V_213 , V_214 , L_133 , V_212 } } ,
} ;
T_21 * V_215 ;
V_203 = getenv ( L_134 ) != NULL ;
V_204 = getenv ( L_135 ) != NULL ;
V_205 = F_73 (
L_136 V_216 L_137 ,
F_76 () ) ;
V_2 =
F_77 ( V_205 , L_138 , V_203 , & V_206 ) ;
F_74 ( V_205 ) ;
if ( V_206 )
{
F_78 ( L_139 , V_206 ) ;
F_74 ( V_206 ) ;
}
if ( V_2 && V_204 )
{
F_79 ( stdout , V_2 ) ;
}
V_189 . V_187 =
F_80 ( FALSE , TRUE , sizeof( T_18 ) ) ;
F_81 (
V_189 . V_187 , V_207 , F_62 ( V_207 ) ) ;
V_189 . V_217 =
F_80 ( FALSE , TRUE , sizeof( T_13 * ) ) ;
F_81 (
V_189 . V_217 , V_208 , F_62 ( V_208 ) ) ;
if ( V_2 )
{
T_1 * V_3 ;
for ( V_3 = V_2 -> V_4 ; V_3 ; V_3 = V_3 -> V_5 )
{
if ( V_3 -> V_35 )
{
T_22 * V_218 ;
T_23 * V_219 = F_80 ( TRUE , TRUE , sizeof( V_220 ) ) ;
for ( V_218 = V_3 -> V_35 ; V_218 ; V_218 = V_218 -> V_5 )
{
V_220 V_46 = { V_218 -> V_11 , V_218 -> V_36 } ;
F_70 ( V_219 , V_46 ) ;
}
V_3 -> V_12 = ( V_220 * ) ( void * ) V_219 -> T_15 ;
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
printf (
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
V_3 -> V_221 ,
F_4 (
V_3 -> V_33 , V_222 , L_2 ) ,
V_3 -> V_125 ,
V_3 -> V_17 ,
V_3 -> V_20 ,
V_3 -> V_23 ,
V_3 -> V_28 ,
V_3 -> V_79 ,
V_3 -> V_88 ,
V_3 -> V_89 ,
V_3 -> V_96 ,
V_3 -> V_95 ,
V_3 -> V_117 ,
V_3 -> V_118 ) ;
}
}
}
F_82 (
V_158 ,
( T_18 * ) ( void * ) V_189 . V_187 -> T_15 ,
V_189 . V_187 -> V_223 ) ;
F_83 (
( T_13 * * ) ( void * ) V_189 . V_217 -> T_15 ,
V_189 . V_217 -> V_223 ) ;
V_215 = F_84 ( V_158 ) ;
F_85 ( V_215 , V_209 , F_62 ( V_209 ) ) ;
}
void
F_86 ( void )
{
T_24 * V_224 ;
V_158 = F_87 (
L_156 ,
L_157 ,
L_137 ) ;
F_88 ( L_137 , F_56 , V_158 ) ;
V_224 = F_89 (
V_158 ,
V_225 ) ;
F_90 (
V_224 ,
L_158 ,
L_159 ,
L_160
L_161 ,
& V_139 ) ;
F_90 (
V_224 ,
L_162 ,
L_163 ,
L_164 ,
& V_8 ) ;
F_91 (
V_224 ,
L_165 ,
L_166 ,
L_167 ,
10 , & V_226 ) ;
F_92 (
V_224 ,
L_168 ,
L_169 ,
L_170 ,
& V_7 ,
V_227 ,
FALSE ) ;
F_93 ( L_137 , F_60 ) ;
}
void
V_225 ( void )
{
static T_12 V_228 = FALSE ;
static T_25 V_229 ;
static int V_230 = - 1 ;
if ( ! V_228 )
{
V_229 = F_94 (
F_56 ,
V_158 ) ;
V_110 = F_95 ( L_171 ) ;
V_228 = TRUE ;
}
if ( V_230 != - 1 )
{
F_96 ( L_172 , V_230 , V_229 ) ;
}
V_230 = V_226 ;
F_97 ( L_172 , V_230 , V_229 ) ;
}
