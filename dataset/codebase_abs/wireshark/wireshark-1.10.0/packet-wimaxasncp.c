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
const T_3 * V_20 ;
if ( V_10 -> V_21 != - 1 )
{
V_17 = V_10 -> V_21 ;
}
else
{
V_17 = V_10 -> V_17 ;
}
V_18 = F_6 ( V_13 , V_16 ) ;
V_19 = F_7 ( V_18 ) ;
V_20 = F_8 ( ( V_22 * ) & V_18 ) ;
F_9 (
V_14 , V_17 ,
V_13 , V_16 , 4 , V_18 ,
L_3 , V_19 , V_20 ) ;
F_10 (
V_15 , L_4 ,
V_19 , V_20 ) ;
}
static void F_11 (
T_5 * V_13 ,
T_6 * V_14 ,
T_7 * V_15 ,
T_8 V_16 ,
const T_1 * V_10 )
{
int V_17 ;
struct V_23 V_18 ;
const T_3 * V_19 ;
const T_3 * V_20 ;
if ( V_10 -> V_21 != - 1 )
{
V_17 = V_10 -> V_24 ;
}
else
{
V_17 = V_10 -> V_17 ;
}
F_12 ( V_13 , V_16 , & V_18 ) ;
V_19 = F_13 ( & V_18 ) ;
V_20 = F_14 ( & V_18 ) ;
F_15 (
V_14 , V_17 ,
V_13 , V_16 , 16 , ( V_22 * ) & V_18 ,
L_3 , V_19 , V_20 ) ;
F_10 (
V_15 , L_4 ,
V_19 , V_20 ) ;
}
static void F_16 (
T_5 * V_13 ,
T_6 * V_14 ,
T_7 * V_15 ,
T_8 V_16 ,
T_8 V_25 ,
const T_1 * V_10 )
{
int V_17 ;
const V_22 * V_26 ;
const T_3 * V_27 ;
const T_3 * V_28 ;
if ( V_10 -> V_29 != - 1 )
{
V_17 = V_10 -> V_29 ;
}
else
{
V_17 = V_10 -> V_17 ;
}
V_26 = F_17 ( V_13 , V_16 , V_25 ) ;
V_27 = F_18 ( V_26 ) ;
V_28 = F_19 ( V_26 ) ;
F_20 (
V_14 , V_17 ,
V_13 , V_16 , V_25 , V_26 ,
L_3 ,
V_27 , V_28 ) ;
F_10 (
V_15 , L_4 ,
V_27 , V_28 ) ;
}
static void F_21 (
T_5 * V_13 ,
T_9 * T_10 V_30 ,
T_6 * V_14 ,
T_7 * V_15 ,
const T_1 * V_10 )
{
T_8 V_16 = 0 ;
T_8 V_25 ;
const T_8 V_31 = 24 ;
const T_3 * V_32 = L_5 ;
V_25 = F_22 ( V_13 ) ;
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
V_22 V_37 ;
const T_3 * V_38 ;
V_37 = F_23 ( V_13 , V_16 ) ;
V_38 = F_3 ( V_10 , V_37 ) ;
F_24 (
V_14 , V_10 -> V_17 ,
V_13 , V_16 , V_25 , V_37 ,
L_7 , V_38 , V_37 ) ;
F_10 ( V_15 , L_8 , V_38 ) ;
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
V_37 = F_25 ( V_13 , V_16 ) ;
V_38 = F_3 ( V_10 , V_37 ) ;
F_24 (
V_14 , V_10 -> V_17 ,
V_13 , V_16 , V_25 , V_37 ,
L_7 , V_38 , V_37 ) ;
F_10 ( V_15 , L_8 , V_38 ) ;
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
V_37 = F_26 ( V_13 , V_16 ) ;
V_38 = F_3 ( V_10 , V_37 ) ;
F_24 (
V_14 , V_10 -> V_17 ,
V_13 , V_16 , V_25 , V_37 ,
L_7 , V_38 , V_37 ) ;
F_10 ( V_15 , L_8 , V_38 ) ;
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
F_16 (
V_13 , V_14 , V_15 , V_16 , V_25 , V_10 ) ;
}
return;
}
case V_42 :
{
if ( V_14 )
{
const V_22 * V_26 ;
const T_3 * V_38 = F_27 ( V_13 , V_16 , V_25 ) ;
V_26 = F_17 ( V_13 , V_16 , V_25 ) ;
F_28 (
V_14 , V_10 -> V_17 ,
V_13 , V_16 , V_25 , V_26 ,
L_9 , V_38 ) ;
F_10 (
V_15 , L_8 , V_38 ) ;
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
V_22 V_37 ;
T_8 V_47 ;
V_37 = F_23 ( V_13 , V_16 ) ;
V_46 = F_29 (
V_14 , V_10 -> V_17 ,
V_13 , V_16 , 1 , V_48 ) ;
F_10 ( V_15 , L_10 , V_37 ) ;
if ( V_37 != 0 )
{
V_45 = F_30 (
V_46 , V_49 ) ;
for ( V_47 = 0 ; V_47 < 8 ; ++ V_47 )
{
V_22 V_50 ;
V_50 = 1 << ( 7 - V_47 ) ;
if ( V_37 & V_50 )
{
const T_3 * V_38 ;
V_38 = F_3 ( V_10 , V_37 & V_50 ) ;
F_24 (
V_45 , V_51 ,
V_13 , V_16 , V_25 , V_37 ,
L_11 , V_47 , V_38 ) ;
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
V_37 = F_25 ( V_13 , V_16 ) ;
V_46 = F_29 (
V_14 , V_10 -> V_17 ,
V_13 , V_16 , 2 , V_53 ) ;
F_10 ( V_15 , L_12 , V_37 ) ;
if ( V_37 != 0 )
{
V_45 = F_30 (
V_46 , V_54 ) ;
for ( V_47 = 0 ; V_47 < 16 ; ++ V_47 )
{
T_2 V_50 ;
V_50 = 1 << ( 15 - V_47 ) ;
if ( V_37 & V_50 )
{
const T_3 * V_38 ;
V_38 = F_3 ( V_10 , V_37 & V_50 ) ;
F_24 (
V_45 , V_55 ,
V_13 , V_16 , V_25 , V_37 ,
L_11 , V_47 , V_38 ) ;
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
V_37 = F_26 ( V_13 , V_16 ) ;
V_46 = F_29 (
V_14 , V_10 -> V_17 ,
V_13 , V_16 , 4 , V_53 ) ;
F_10 ( V_15 , L_13 , V_37 ) ;
if ( V_37 != 0 )
{
V_45 = F_30 (
V_46 , V_57 ) ;
for ( V_47 = 0 ; V_47 < 32 ; ++ V_47 )
{
T_4 V_50 ;
V_50 = 1 << ( 31 - V_47 ) ;
if ( V_37 & V_50 )
{
const T_3 * V_38 ;
V_38 = F_3 ( V_10 , V_37 & V_50 ) ;
F_24 (
V_45 , V_58 ,
V_13 , V_16 , V_25 , V_37 ,
L_11 , V_47 , V_38 ) ;
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
F_16 (
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
const V_22 * V_26 = F_17 ( V_13 , V_16 , V_25 ) ;
const T_3 * V_38 = F_31 ( V_26 , F_32 ( V_25 , V_31 ) , 0 ) ;
if ( V_25 <= V_31 )
{
V_61 = L_9 ;
V_62 = L_8 ;
}
else
{
V_61 = L_14 ;
V_62 = L_15 ;
}
F_33 (
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
V_22 V_37 ;
V_37 = F_23 ( V_13 , V_16 ) ;
F_24 (
V_14 , V_10 -> V_17 ,
V_13 , V_16 , V_25 , V_37 ,
L_16 , V_37 ) ;
F_10 ( V_15 , L_10 , V_37 ) ;
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
V_37 = F_25 ( V_13 , V_16 ) ;
F_24 (
V_14 , V_10 -> V_17 ,
V_13 , V_16 , V_25 , V_37 ,
L_17 , V_37 ) ;
F_10 ( V_15 , L_12 , V_37 ) ;
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
V_37 = F_26 ( V_13 , V_16 ) ;
F_24 (
V_14 , V_10 -> V_17 ,
V_13 , V_16 , V_25 , V_37 ,
L_18 , V_37 ) ;
F_10 ( V_15 , L_13 , V_37 ) ;
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
V_22 V_37 ;
V_37 = F_23 ( V_13 , V_16 ) ;
F_24 (
V_14 , V_10 -> V_17 ,
V_13 , V_16 , V_25 , V_37 ,
L_19 , V_37 ) ;
F_10 ( V_15 , L_20 , V_37 ) ;
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
V_37 = F_25 ( V_13 , V_16 ) ;
F_24 (
V_14 , V_10 -> V_17 ,
V_13 , V_16 , V_25 , V_37 ,
L_19 , V_37 ) ;
F_10 ( V_15 , L_20 , V_37 ) ;
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
V_37 = F_26 ( V_13 , V_16 ) ;
F_24 (
V_14 , V_10 -> V_17 ,
V_13 , V_16 , V_25 , V_37 ,
L_19 , V_37 ) ;
F_10 ( V_15 , L_20 , V_37 ) ;
}
return;
}
case V_69 :
{
if ( V_8 )
{
F_2 (
L_21 , V_10 -> V_36 , V_10 -> type ) ;
}
if ( V_14 )
{
const T_3 * V_70 ;
const V_22 * V_26 = F_17 ( V_13 , V_16 , V_25 ) ;
const T_3 * V_38 = F_31 ( V_26 , F_32 ( V_25 , V_31 ) , 0 ) ;
if ( V_25 <= V_31 )
{
V_70 = L_22 ;
}
else
{
V_70 = L_23 ;
}
F_33 (
V_14 , V_10 -> V_17 ,
V_13 , V_16 , V_25 , V_26 ,
V_70 , V_32 , V_38 ) ;
F_10 ( V_15 , L_24 ) ;
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
V_46 = F_34 (
V_14 , V_13 , V_16 , V_25 ,
L_25 ) ;
V_74 = F_30 (
V_46 , V_76 ) ;
V_46 = F_29 (
V_74 , V_10 -> V_17 ,
V_13 , V_16 , V_25 , V_48 ) ;
F_35 ( V_46 ) ;
while ( V_16 < F_36 ( V_13 ) )
{
T_2 V_77 ;
const T_3 * V_78 ;
V_77 = F_25 ( V_13 , V_16 ) ;
V_78 = F_37 ( V_77 ) ;
F_24 (
V_74 , V_10 -> V_79 ,
V_13 , V_16 , 2 , V_77 ,
L_26 , V_78 , V_77 ) ;
if ( V_16 == 0 )
{
F_10 ( V_15 , L_8 , V_78 ) ;
}
else if ( V_16 < 2 * V_75 )
{
F_10 ( V_15 , L_27 , V_78 ) ;
}
else if ( V_16 == 2 * V_75 )
{
F_10 ( V_15 , L_28 ) ;
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
V_46 = F_34 (
V_14 , V_13 , V_16 , V_25 ,
L_25 ) ;
V_81 = F_30 (
V_46 , V_83 ) ;
V_46 = F_29 (
V_81 , V_10 -> V_17 ,
V_13 , V_16 , V_25 , V_48 ) ;
F_35 ( V_46 ) ;
while ( V_16 < F_36 ( V_13 ) )
{
T_2 V_84 ;
T_2 V_85 ;
V_84 = F_25 ( V_13 , V_16 ) ;
V_85 = F_25 ( V_13 , V_16 + 2 ) ;
F_34 (
V_81 , V_13 , V_16 , 4 ,
L_29 , V_84 , V_85 ) ;
V_46 = F_29 (
V_81 , V_10 -> V_86 ,
V_13 , V_16 , 2 , V_53 ) ;
F_35 ( V_46 ) ;
V_46 = F_29 (
V_81 , V_10 -> V_87 ,
V_13 , V_16 + 2 , 2 , V_53 ) ;
F_35 ( V_46 ) ;
if ( V_16 == 0 )
{
F_10 (
V_15 , L_30 , V_84 , V_85 ) ;
}
else if ( V_16 < 4 * V_82 )
{
F_10 (
V_15 , L_31 , V_84 , V_85 ) ;
}
else if ( V_16 == 4 * V_82 )
{
F_10 ( V_15 , L_28 ) ;
}
V_16 += 4 ;
}
}
return;
}
case V_88 :
{
if ( V_25 % 8 != 0 )
{
break;
}
if ( V_14 && V_25 > 0 )
{
T_6 * V_89 ;
T_7 * V_46 ;
V_46 = F_34 (
V_14 , V_13 , V_16 , V_25 ,
L_25 ) ;
V_89 = F_30 (
V_46 , V_90 ) ;
V_46 = F_29 (
V_89 , V_10 -> V_17 ,
V_13 , V_16 , V_25 , V_48 ) ;
F_35 ( V_46 ) ;
if ( V_25 % 32 == 0 )
{
while ( V_16 < F_36 ( V_13 ) )
{
T_6 * V_91 ;
struct V_23 V_18 ;
const T_3 * V_38 ;
V_46 = F_34 (
V_89 , V_13 , V_16 , 32 ,
L_32 ) ;
V_91 = F_30 (
V_46 , V_92 ) ;
F_12 ( V_13 , V_16 , & V_18 ) ;
F_29 (
V_91 ,
V_10 -> V_24 ,
V_13 , V_16 , 16 , V_48 ) ;
V_16 += 16 ;
F_12 ( V_13 , V_16 , & V_18 ) ;
V_38 = F_14 ( & V_18 ) ;
F_38 (
V_91 ,
V_10 -> V_93 ,
V_13 , V_16 , 16 , ( const V_22 * ) & V_18 ,
L_33 , V_38 ) ;
V_16 += 16 ;
}
}
else
{
while ( V_16 < F_36 ( V_13 ) )
{
T_6 * V_91 ;
T_4 V_18 ;
const T_3 * V_38 ;
V_46 = F_34 (
V_89 , V_13 , V_16 , 8 ,
L_34 ) ;
V_91 = F_30 (
V_46 , V_92 ) ;
V_18 = F_6 ( V_13 , V_16 ) ;
F_29 (
V_91 ,
V_10 -> V_21 ,
V_13 , V_16 , 4 , V_53 ) ;
F_10 (
V_46 , L_4 ,
F_7 ( V_18 ) , F_8 ( ( V_22 * ) & V_18 ) ) ;
V_16 += 4 ;
V_18 = F_6 ( V_13 , V_16 ) ;
V_38 = F_8 ( ( V_22 * ) & V_18 ) ;
F_39 (
V_91 ,
V_10 -> V_94 ,
V_13 , V_16 , 4 , V_18 ,
L_33 , V_38 ) ;
F_10 (
V_46 , L_35 , V_38 ) ;
V_16 += 4 ;
}
}
}
return;
}
case V_95 :
{
V_22 V_96 ;
V_22 V_97 = 0 ;
V_96 = F_23 ( V_13 , V_16 ) ;
if ( V_96 == V_98 || V_96 == V_99 )
{
V_97 = F_23 ( V_13 , V_16 + 4 ) ;
}
F_40 ( T_10 -> V_100 , V_101 , L_36 ) ;
F_40 ( T_10 -> V_100 , V_101 ,
F_4 ( V_96 , V_102 , L_37 ) ) ;
if ( V_96 == V_98 || V_96 == V_99 )
{
F_40 ( T_10 -> V_100 , V_101 , L_38 ) ;
F_40 ( T_10 -> V_100 , V_101 ,
F_41 ( V_97 , & V_103 , L_39 ) ) ;
}
F_40 ( T_10 -> V_100 , V_101 , L_40 ) ;
{
T_6 * V_104 ;
T_7 * V_46 ;
T_11 V_105 ;
T_5 * V_106 ;
V_46 = F_29 ( V_14 , V_10 -> V_17 , V_13 ,
V_16 , V_25 , V_48 ) ;
F_42 ( V_46 , L_25 ) ;
V_104 = F_30 ( V_46 , V_107 ) ;
F_10 ( V_46 , L_41 ,
F_4 ( V_96 , V_102 ,
L_37 ) ) ;
if ( V_96 == V_98 || V_96 == V_99 )
{
F_10 ( V_46 , L_27 ,
F_41 ( V_97 , & V_103 ,
L_39 ) ) ;
}
F_10 ( V_46 , L_42 ) ;
V_106 = F_43 ( V_13 , V_16 , V_25 ,
F_44 ( V_13 , V_16 ) ) ;
V_105 = F_45 ( T_10 -> V_100 ) ;
F_46 ( T_10 -> V_100 , FALSE ) ;
F_47 ( V_108 , V_106 , T_10 , V_104 ) ;
F_46 ( T_10 -> V_100 , V_105 ) ;
}
return;
}
case V_109 :
{
if ( V_25 < 3 )
{
break;
}
if ( V_14 )
{
T_6 * V_110 ;
T_7 * V_46 ;
T_4 V_111 ;
const T_3 * V_112 ;
V_46 = F_34 (
V_14 , V_13 , V_16 , V_25 ,
L_25 ) ;
V_110 = F_30 (
V_46 , V_113 ) ;
V_46 = F_29 (
V_110 , V_10 -> V_17 ,
V_13 , V_16 , V_25 , V_48 ) ;
F_35 ( V_46 ) ;
V_111 = F_48 ( V_13 , V_16 ) ;
V_112 = F_49 ( V_111 , & V_114 , L_2 ) ;
F_24 (
V_110 , V_10 -> V_115 ,
V_13 , V_16 , 3 , V_111 ,
L_43 , V_112 , V_111 ) ;
F_10 ( V_15 , L_8 , V_112 ) ;
V_16 += 3 ;
if ( V_16 < F_36 ( V_13 ) )
{
F_29 (
V_110 , V_10 -> V_116 ,
V_13 , V_16 , V_25 - V_16 , V_48 ) ;
}
}
return;
}
case V_117 :
{
if ( V_14 )
{
const T_3 * V_61 ;
const T_3 * V_62 ;
const V_22 * V_26 = F_17 ( V_13 , V_16 , V_25 ) ;
const T_3 * V_38 =
F_31 ( V_26 , F_32 ( V_25 , V_31 ) , 0 ) ;
if ( V_25 <= V_31 )
{
V_61 = L_22 ;
V_62 = L_44 ;
}
else
{
V_61 = L_23 ;
V_62 = L_45 ;
}
F_33 (
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
L_46 , V_10 -> V_33 ) ;
}
break;
}
if ( V_14 )
{
const T_3 * V_70 ;
const V_22 * V_26 = F_17 ( V_13 , V_16 , V_25 ) ;
const T_3 * V_38 = F_31 ( V_26 , F_32 ( V_25 , V_31 ) , 0 ) ;
if ( V_25 <= V_31 )
{
V_70 = L_22 ;
}
else
{
V_70 = L_23 ;
}
F_33 (
V_14 , V_118 ,
V_13 , V_16 , V_25 , V_26 ,
V_70 , V_32 , V_38 ) ;
}
}
static T_8 F_50 (
T_5 * V_13 ,
T_9 * T_10 ,
T_6 * V_14 )
{
T_8 V_16 ;
V_16 = 0 ;
while ( V_16 < F_22 ( V_13 ) )
{
const T_1 * V_10 ;
T_6 * V_119 ;
T_7 * V_15 ;
T_2 type ;
T_2 V_25 ;
T_8 V_120 ;
type = F_25 ( V_13 , V_16 ) ;
V_10 = F_1 ( type ) ;
V_25 = F_25 ( V_13 , V_16 + 2 ) ;
#if 0
pad = 4 - (length % 4);
if (pad == 4)
{
pad = 0;
}
#endif
V_120 = 0 ;
{
T_7 * V_121 ;
T_12 V_122 = F_32 (
( T_12 ) ( 4 + V_25 + V_120 ) , F_44 ( V_13 , V_16 ) ) ;
V_15 = F_29 (
V_14 , V_10 -> V_123 ,
V_13 , V_16 , V_122 , V_48 ) ;
F_42 ( V_15 , L_47 , V_10 -> V_36 ) ;
if ( V_10 -> V_33 == V_117 )
{
F_10 ( V_15 , L_48 , type ) ;
}
if ( V_10 -> V_33 == V_124 )
{
F_10 ( V_15 , L_49 ) ;
}
V_119 = F_30 (
V_15 , V_125 ) ;
V_121 = F_24 (
V_119 , V_126 ,
V_13 , V_16 , 2 , type ,
L_50 , V_10 -> V_36 , type ) ;
if ( V_10 -> V_33 == V_117 )
{
F_51 ( T_10 , V_121 ,
V_127 , V_128 ,
L_51 ,
type ) ;
}
F_52 (
V_119 , V_129 ,
V_13 , V_16 + 2 , 2 , V_25 ) ;
}
V_16 += 4 ;
if ( V_10 -> V_33 == V_124 )
{
if ( V_25 == 0 )
{
}
else if ( F_44 ( V_13 , V_16 ) > 0 )
{
T_5 * V_130 ;
V_130 = F_43 (
V_13 , V_16 ,
F_32 ( V_25 , F_44 ( V_13 , V_16 ) ) ,
V_25 ) ;
F_50 ( V_130 , T_10 , V_119 ) ;
}
else
{
F_53 ( V_13 , V_16 , V_25 + V_120 ) ;
}
}
else
{
T_5 * V_130 ;
F_53 ( V_13 , V_16 , V_25 + V_120 ) ;
V_130 = F_43 (
V_13 , V_16 ,
F_32 ( V_25 , F_44 ( V_13 , V_16 ) ) ,
V_25 ) ;
F_21 (
V_130 , T_10 , V_119 , V_15 , V_10 ) ;
}
V_16 += V_25 + V_120 ;
}
return V_16 ;
}
static T_8 F_54 (
T_5 * V_13 ,
T_9 * T_10 ,
T_6 * V_14 )
{
T_8 V_16 = 0 ;
T_2 V_131 ;
T_4 V_132 ;
const V_22 * V_133 ;
T_2 V_134 = 0 ;
T_11 V_135 ;
if ( V_14 )
{
F_29 (
V_14 , V_136 ,
V_13 , V_16 , 6 , V_48 ) ;
}
V_133 = F_55 ( V_13 , V_16 ) ;
V_16 += 6 ;
V_132 = F_26 ( V_13 , V_16 ) ;
if ( V_14 )
{
F_52 (
V_14 , V_137 ,
V_13 , V_16 , 4 , V_132 ) ;
}
V_16 += 4 ;
V_135 = FALSE ;
V_131 = F_25 ( V_13 , V_16 ) ;
if ( V_138 )
{
const T_2 V_50 = 0x7fff ;
if ( V_131 & 0x8000 )
{
F_24 (
V_14 , V_139 ,
V_13 , V_16 , 2 , V_131 ,
L_52 , V_50 & V_131 , V_131 ) ;
V_134 = V_131 & V_50 ;
V_135 = TRUE ;
}
else
{
F_24 (
V_14 , V_139 ,
V_13 , V_16 , 2 , V_131 ,
L_53 , V_131 ) ;
V_134 = V_131 ;
}
}
else
{
F_52 (
V_14 , V_139 ,
V_13 , V_16 , 2 , V_131 ) ;
V_134 = V_131 ;
}
V_16 += 2 ;
V_131 = F_25 ( V_13 , V_16 ) ;
if ( V_14 )
{
F_52 (
V_14 , V_140 ,
V_13 , V_16 , 2 , V_131 ) ;
}
V_16 += 2 ;
if ( V_16 < F_36 ( V_13 ) )
{
T_5 * V_130 ;
V_130 = F_56 ( V_13 , V_16 ) ;
V_16 += F_50 ( V_130 , T_10 , V_14 ) ;
}
F_57 ( T_10 -> V_100 , V_101 , L_54 , V_133 ) ;
if ( V_135 )
{
F_57 ( T_10 -> V_100 , V_101 , L_55 , V_134 ) ;
}
else
{
F_57 ( T_10 -> V_100 , V_101 , L_56 , V_134 ) ;
}
return V_16 ;
}
static const T_3 *
F_58 (
const T_4 V_141 ,
const T_13 * const V_142 ,
const T_4 V_143 )
{
const T_13 * V_144 ;
const T_13 * V_1 = NULL ;
for( V_144 = V_142 ; V_144 -> V_145 . V_146 ; V_144 ++ )
{
if ( ( V_144 -> V_145 . V_37 == V_141 ) && ( V_144 -> V_6 <= V_143 ) )
{
if ( ! V_1 || ( V_144 -> V_6 > V_1 -> V_6 ) )
{
V_1 = V_144 ;
}
}
}
return V_1 ? V_1 -> V_145 . V_146 : NULL ;
}
static int
F_59 (
T_5 * V_13 ,
T_9 * T_10 ,
T_6 * V_14 ,
void * T_14 V_30 )
{
const T_3 * V_147 = L_2 ;
T_7 * V_148 = NULL ;
T_7 * V_46 = NULL ;
T_6 * V_149 = NULL ;
T_5 * V_150 ;
T_8 V_16 ;
V_22 V_151 ;
V_22 V_152 ;
const T_3 * V_153 ;
T_7 * V_154 ;
T_2 V_25 ;
const T_15 * V_26 = NULL ;
const T_3 * V_155 ;
T_16 V_47 ;
#if 0
if (tvb_reported_length(tvb) < WIMAXASNCP_HEADER_SIZE)
{
return 0;
}
#endif
if ( F_60 ( V_13 , 0 , 1 ) && F_23 ( V_13 , 0 ) != 1 )
{
return 0 ;
}
F_61 ( T_10 -> V_100 , V_156 , L_57 ) ;
F_62 ( T_10 -> V_100 , V_101 ) ;
V_16 = 0 ;
if ( V_2 == NULL )
{
F_63 ( NULL ) ;
}
if ( V_14 )
{
V_148 = F_29 (
V_14 , V_157 ,
V_13 , 0 , F_32 ( V_158 , F_36 ( V_13 ) ) , V_48 ) ;
V_149 = F_30 (
V_148 , V_159 ) ;
}
if ( V_14 )
{
F_29 (
V_149 , V_160 ,
V_13 , V_16 , 1 , V_53 ) ;
}
V_16 += 1 ;
V_151 = F_23 ( V_13 , V_16 ) ;
if ( V_14 )
{
T_6 * V_45 ;
if ( V_151 == 0 )
{
F_24 (
V_149 , V_161 ,
V_13 , V_16 , 1 , V_151 ,
L_58 , V_151 ) ;
}
else
{
T_8 V_162 ;
V_46 = F_24 (
V_149 , V_161 ,
V_13 , V_16 , 1 , V_151 ,
L_59 ) ;
if ( V_151 & ( V_163 | V_164 ) )
{
if ( V_151 & V_163 )
{
F_10 ( V_46 , L_60 ) ;
}
if ( V_151 & V_164 )
{
F_10 ( V_46 , L_61 ) ;
}
F_10 ( V_46 , L_62 ) ;
}
F_10 ( V_46 , L_63 , V_151 ) ;
V_45 = F_30 (
V_46 , V_165 ) ;
for ( V_162 = 0 ; V_162 < 8 ; ++ V_162 )
{
V_22 V_50 ;
V_50 = 1 << ( 7 - V_162 ) ;
if ( V_151 & V_50 )
{
F_24 (
V_45 , V_161 ,
V_13 , V_16 , 1 , V_151 ,
L_11 ,
V_162 ,
F_4 (
V_151 & V_50 , V_166 , L_2 ) ) ;
}
}
}
}
V_16 += 1 ;
V_152 = F_23 ( V_13 , V_16 ) ;
V_153 = F_58 ( V_152 ,
V_167 ,
V_7 ) ;
if ( V_153 )
{
F_24 (
V_149 , V_168 ,
V_13 , V_16 , 1 , V_152 ,
L_64 , V_153 , V_152 ) ;
}
else
{
V_154 = F_24 (
V_149 , V_168 ,
V_13 , V_16 , 1 , V_152 ,
L_65 , V_152 ) ;
F_51 ( T_10 , V_154 ,
V_127 , V_128 ,
L_66 ,
V_152 ) ;
}
V_16 += 1 ;
V_151 = F_23 ( V_13 , V_16 ) ;
V_46 = F_24 (
V_149 , V_169 ,
V_13 , V_16 , 1 , V_151 ,
L_67 , F_4 ( V_151 >> 5 , V_170 , V_147 ) ) ;
F_10 ( V_46 , L_48 , ( ( V_151 >> 5 ) & 7 ) ) ;
for ( V_47 = 0 ; V_47 < F_64 ( V_171 ) ; ++ V_47 )
{
V_26 = & V_171 [ V_47 ] ;
if ( V_152 == V_26 -> V_152 )
{
break;
}
}
V_155 = V_26 ? F_58 ( 0x1f & V_151 , V_26 -> V_172 , V_7 ) : V_147 ;
if ( V_155 == NULL )
{
V_155 = V_147 ;
}
V_46 = F_24 (
V_149 , V_169 ,
V_13 , V_16 , 1 , V_151 ,
L_68 , V_155 ) ;
F_10 ( V_46 , L_48 , V_151 & 0x1F ) ;
if ( strcmp ( V_155 , V_147 ) == 0 )
{
F_51 ( T_10 , V_46 ,
V_127 , V_128 ,
L_69 ,
0x1f & V_151 ) ;
}
F_65 ( T_10 -> V_100 , V_101 , V_155 ) ;
V_16 += 1 ;
V_25 = F_25 ( V_13 , V_16 ) ;
if ( V_14 )
{
F_66 (
V_148 , F_67 ( V_158 , V_25 ) ) ;
V_46 = F_52 (
V_149 , V_173 ,
V_13 , V_16 , 2 , V_25 ) ;
}
V_16 += 2 ;
if ( V_25 < V_174 )
{
F_51 (
T_10 , V_46 , V_175 , V_176 , L_70 ) ;
if ( V_14 )
{
F_10 (
V_46 , L_71 ) ;
}
if ( V_25 <= V_158 )
{
return V_16 ;
}
}
V_150 = F_43 (
V_13 , V_16 ,
F_32 ( V_25 , F_36 ( V_13 ) - V_16 ) ,
V_25 - V_158 ) ;
V_16 += F_54 (
V_150 , T_10 , V_149 ) ;
return V_16 ;
}
static char * F_68 (
char * V_36 )
{
char * V_177 = V_36 ;
char * V_178 = V_36 ;
char V_179 ;
for ( ; ( V_179 = * V_177 ) ; ++ V_177 )
{
if ( isalnum ( ( unsigned char ) V_179 ) || V_179 == '_' || V_179 == '.' )
{
* ( V_178 ++ ) = V_179 ;
}
else if ( V_179 == ' ' || V_179 == '-' || V_179 == '/' )
{
if ( V_178 == V_36 )
{
continue;
}
if ( * ( V_178 - 1 ) == '_' )
{
continue;
}
* ( V_178 ++ ) = '_' ;
}
}
* V_178 = '\0' ;
return V_36 ;
}
static void F_69 (
int * V_180 ,
const char * V_36 ,
const char * V_181 ,
enum V_182 type ,
int V_183 ,
const char * V_184 )
{
T_17 V_185 = {
V_180 , { V_36 , V_181 , type , V_183 , NULL , 0x0 , V_184 , V_186 } } ;
F_70 ( V_187 . V_185 , V_185 ) ;
}
static void F_71 (
T_1 * V_3 )
{
char * V_36 ;
char * V_181 ;
const char * V_188 ;
char * V_184 ;
V_36 = F_72 ( V_3 -> V_36 ) ;
V_181 = F_68 ( F_73 ( L_72 , V_3 -> V_36 ) ) ;
switch ( V_3 -> V_33 )
{
case V_117 :
V_188 = L_73 ;
break;
case V_69 :
V_188 = F_73 ( L_74 , V_3 -> type ) ;
break;
case V_124 :
V_188 = F_73 ( L_75 , V_3 -> type ) ;
break;
case V_43 :
V_188 = F_73 ( L_76 , V_3 -> type ) ;
break;
default:
V_188 = F_73 ( L_77 , V_3 -> type ) ;
break;
}
F_69 (
& V_3 -> V_123 , V_36 , V_181 , V_189 , V_190 , V_188 ) ;
V_36 = F_72 ( L_25 ) ;
V_181 = F_68 ( F_73 ( L_78 , V_3 -> V_36 ) ) ;
V_184 = F_73 ( L_79 , V_3 -> type ) ;
switch ( V_3 -> V_33 )
{
case V_117 :
F_74 ( V_184 ) ;
F_69 (
& V_3 -> V_17 , V_36 , V_181 , V_189 , V_190 ,
L_80 ) ;
break;
case V_69 :
F_69 (
& V_3 -> V_17 , V_36 , V_181 , V_189 , V_190 , V_184 ) ;
break;
case V_124 :
case V_43 :
F_74 ( V_36 ) ;
F_74 ( V_181 ) ;
F_74 ( V_184 ) ;
break;
case V_60 :
F_69 (
& V_3 -> V_17 , V_36 , V_181 , V_189 , V_190 , V_184 ) ;
break;
case V_34 :
F_69 (
& V_3 -> V_17 , V_36 , V_181 , V_191 , V_192 , V_184 ) ;
break;
case V_39 :
F_69 (
& V_3 -> V_17 , V_36 , V_181 , V_193 , V_192 , V_184 ) ;
break;
case V_40 :
F_69 (
& V_3 -> V_17 , V_36 , V_181 , V_194 , V_192 , V_184 ) ;
break;
case V_41 :
F_69 (
& V_3 -> V_17 , V_36 , V_181 , V_195 , V_190 , V_184 ) ;
break;
case V_42 :
F_69 (
& V_3 -> V_17 , V_36 , V_181 , V_196 , V_190 , V_184 ) ;
break;
case V_44 :
F_69 (
& V_3 -> V_17 , V_36 , V_181 , V_191 , V_197 , V_184 ) ;
break;
case V_52 :
F_69 (
& V_3 -> V_17 , V_36 , V_181 , V_193 , V_197 , V_184 ) ;
break;
case V_56 :
F_69 (
& V_3 -> V_17 , V_36 , V_181 , V_194 , V_197 , V_184 ) ;
break;
case V_59 :
F_74 ( V_181 ) ;
V_181 = F_68 (
F_73 ( L_81 , V_3 -> V_36 ) ) ;
F_69 (
& V_3 -> V_21 , L_82 , V_181 , V_198 , V_190 , V_184 ) ;
V_181 = F_68 (
F_73 ( L_83 , V_3 -> V_36 ) ) ;
F_69 (
& V_3 -> V_24 , L_84 , V_181 , V_199 , V_190 , V_184 ) ;
V_181 = F_68 (
F_73 ( L_85 , V_3 -> V_36 ) ) ;
F_69 (
& V_3 -> V_29 , L_86 , V_181 , V_195 , V_190 , V_184 ) ;
break;
case V_63 :
F_69 (
& V_3 -> V_17 , V_36 , V_181 , V_191 , V_197 , V_184 ) ;
break;
case V_64 :
F_69 (
& V_3 -> V_17 , V_36 , V_181 , V_193 , V_197 , V_184 ) ;
break;
case V_65 :
F_69 (
& V_3 -> V_17 , V_36 , V_181 , V_194 , V_197 , V_184 ) ;
break;
case V_66 :
F_69 (
& V_3 -> V_17 , V_36 , V_181 , V_191 , V_192 , V_184 ) ;
break;
case V_67 :
F_69 (
& V_3 -> V_17 , V_36 , V_181 , V_193 , V_192 , V_184 ) ;
break;
case V_68 :
F_69 (
& V_3 -> V_17 , V_36 , V_181 , V_194 , V_192 , V_184 ) ;
break;
case V_71 :
F_74 ( V_181 ) ;
V_181 = F_68 (
F_73 ( L_81 , V_3 -> V_36 ) ) ;
F_69 (
& V_3 -> V_21 , L_82 , V_181 , V_198 , V_190 , V_184 ) ;
V_181 = F_68 (
F_73 ( L_83 , V_3 -> V_36 ) ) ;
F_69 (
& V_3 -> V_24 , L_84 , V_181 , V_199 , V_190 , V_184 ) ;
break;
case V_72 :
F_69 (
& V_3 -> V_17 , V_36 , V_181 , V_198 , V_190 , V_184 ) ;
break;
case V_73 :
F_69 (
& V_3 -> V_17 , V_36 , V_181 , V_189 , V_190 , V_184 ) ;
V_184 = F_73 ( L_87 , V_3 -> type ) ;
V_181 = F_68 (
F_73 ( L_88 , V_3 -> V_36 ) ) ;
F_69 (
& V_3 -> V_79 , L_89 , V_181 , V_193 , V_192 , V_184 ) ;
break;
case V_80 :
F_69 (
& V_3 -> V_17 , V_36 , V_181 , V_189 , V_190 , V_184 ) ;
V_184 = F_73 ( L_87 , V_3 -> type ) ;
V_181 = F_68 (
F_73 ( L_90 , V_3 -> V_36 ) ) ;
F_69 (
& V_3 -> V_86 , L_91 , V_181 , V_193 , V_192 , V_184 ) ;
V_181 = F_68 (
F_73 ( L_92 , V_3 -> V_36 ) ) ;
F_69 (
& V_3 -> V_87 , L_93 , V_181 , V_193 , V_192 , V_184 ) ;
break;
case V_88 :
F_69 (
& V_3 -> V_17 , V_36 , V_181 , V_189 , V_190 , V_184 ) ;
V_184 = F_73 ( L_87 , V_3 -> type ) ;
V_181 = F_68 (
F_73 ( L_94 , V_3 -> V_36 ) ) ;
F_69 (
& V_3 -> V_21 , L_82 , V_181 , V_198 , V_190 , V_184 ) ;
V_181 = F_68 (
F_73 ( L_95 , V_3 -> V_36 ) ) ;
F_69 (
& V_3 -> V_94 , L_96 , V_181 , V_198 , V_190 , V_184 ) ;
V_181 = F_68 (
F_73 ( L_97 , V_3 -> V_36 ) ) ;
F_69 (
& V_3 -> V_24 , L_84 , V_181 , V_199 , V_190 , V_184 ) ;
V_181 = F_68 (
F_73 ( L_98 , V_3 -> V_36 ) ) ;
F_69 (
& V_3 -> V_93 , L_99 , V_181 , V_199 , V_190 , V_184 ) ;
break;
case V_109 :
F_69 (
& V_3 -> V_17 , V_36 , V_181 , V_189 , V_190 , V_184 ) ;
V_184 = F_73 ( L_87 , V_3 -> type ) ;
V_181 = F_68 (
F_73 ( L_100 , V_3 -> V_36 ) ) ;
F_69 (
& V_3 -> V_115 , L_101 , V_181 , V_200 , V_192 , V_184 ) ;
V_181 = F_68 (
F_73 (
L_102 , V_3 -> V_36 ) ) ;
F_69 (
& V_3 -> V_116 , L_103 , V_181 , V_189 , V_190 ,
V_184 ) ;
break;
case V_95 :
V_184 = F_73 ( L_104 , V_36 ) ;
F_69 (
& V_3 -> V_17 , V_36 , V_181 , V_189 , V_190 , V_184 ) ;
break;
default:
F_69 (
& V_3 -> V_17 , V_36 , V_181 , V_189 , V_190 , V_184 ) ;
if ( V_8 )
{
F_2 (
L_46 , V_3 -> V_33 ) ;
}
break;
}
}
static void
F_63 ( const char * T_18 V_30 )
{
T_11 V_201 ;
T_11 V_202 ;
T_3 * V_203 ;
T_3 * V_204 ;
static T_17 V_205 [] = {
{
& V_160 ,
{
L_105 ,
L_106 ,
V_191 ,
V_192 ,
NULL ,
0x0 ,
NULL ,
V_186
}
} ,
{
& V_161 ,
{
L_107 ,
L_108 ,
V_191 ,
V_197 ,
NULL ,
0xff ,
NULL ,
V_186
}
} ,
{
& V_168 ,
{
L_109 ,
L_110 ,
V_191 ,
V_192 ,
NULL ,
0x0 ,
NULL ,
V_186
}
} ,
{
& V_169 ,
{
L_111 ,
L_112 ,
V_191 ,
V_197 ,
F_75 ( V_170 ) ,
0xE0 ,
NULL ,
V_186
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
& V_173 ,
{
L_113 ,
L_114 ,
V_193 ,
V_192 ,
NULL ,
0x0 ,
NULL ,
V_186
}
} ,
{
& V_136 ,
{
L_115 ,
L_116 ,
V_195 ,
V_190 ,
NULL ,
0x0 ,
NULL ,
V_186
}
} ,
{
& V_137 ,
{
L_117 ,
L_118 ,
V_194 ,
V_197 ,
NULL ,
0x0 ,
NULL ,
V_186
}
} ,
{
& V_139 ,
{
L_119 ,
L_120 ,
V_193 ,
V_197 ,
NULL ,
0x0 ,
NULL ,
V_186
}
} ,
{
& V_140 ,
{
L_117 ,
L_121 ,
V_193 ,
V_197 ,
NULL ,
0x0 ,
NULL ,
V_186
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
& V_126 ,
{
L_122 ,
L_123 ,
V_193 ,
V_192 ,
NULL ,
0x0 ,
NULL ,
V_186
}
} ,
{
& V_129 ,
{
L_113 ,
L_124 ,
V_193 ,
V_192 ,
NULL ,
0x0 ,
NULL ,
V_186
}
} ,
{
& V_118 ,
{
L_25 ,
L_125 ,
V_189 ,
V_190 ,
NULL ,
0x0 ,
NULL ,
V_186
}
} ,
{
& V_51 ,
{
L_25 ,
L_126 ,
V_191 ,
V_197 ,
NULL ,
0xff ,
NULL ,
V_186
}
} ,
{
& V_55 ,
{
L_25 ,
L_127 ,
V_193 ,
V_197 ,
NULL ,
0xffff ,
NULL ,
V_186
}
} ,
{
& V_58 ,
{
L_25 ,
L_128 ,
V_194 ,
V_197 ,
NULL ,
0xffffffff ,
NULL ,
V_186
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
static T_12 * V_206 [] = {
& V_159 ,
& V_165 ,
& V_125 ,
& V_49 ,
& V_54 ,
& V_57 ,
& V_76 ,
& V_83 ,
& V_90 ,
& V_92 ,
& V_107 ,
& V_113
} ;
V_201 = getenv ( L_129 ) != NULL ;
V_202 = getenv ( L_130 ) != NULL ;
V_203 = F_76 (
L_33 V_207 L_131 ,
F_77 () ) ;
V_2 =
F_78 ( V_203 , L_132 , V_201 , & V_204 ) ;
if ( V_204 )
{
F_79 ( L_133 , V_204 ) ;
F_74 ( V_204 ) ;
}
if ( V_2 && V_202 )
{
F_80 ( stdout , V_2 ) ;
}
V_187 . V_185 =
F_81 ( FALSE , TRUE , sizeof( T_17 ) ) ;
F_82 (
V_187 . V_185 , V_205 , F_64 ( V_205 ) ) ;
V_187 . V_208 =
F_81 ( FALSE , TRUE , sizeof( T_12 * ) ) ;
F_82 (
V_187 . V_208 , V_206 , F_64 ( V_206 ) ) ;
if ( V_2 )
{
T_1 * V_3 ;
for ( V_3 = V_2 -> V_4 ; V_3 ; V_3 = V_3 -> V_5 )
{
if ( V_3 -> V_35 )
{
T_19 * V_209 ;
T_20 * V_210 = F_81 ( TRUE , TRUE , sizeof( V_211 ) ) ;
for ( V_209 = V_3 -> V_35 ; V_209 ; V_209 = V_209 -> V_5 )
{
V_211 V_46 = { V_209 -> V_11 , V_209 -> V_36 } ;
F_70 ( V_210 , V_46 ) ;
}
V_3 -> V_12 = ( V_211 * ) ( void * ) V_210 -> T_14 ;
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
L_134
L_135
L_136
L_137
L_138
L_139
L_140
L_141
L_142
L_143
L_144
L_145
L_146
L_147
L_148
L_149 ,
V_3 -> V_36 ,
V_3 -> type ,
V_3 -> V_212 ,
F_4 (
V_3 -> V_33 , V_213 , L_2 ) ,
V_3 -> V_123 ,
V_3 -> V_17 ,
V_3 -> V_21 ,
V_3 -> V_24 ,
V_3 -> V_29 ,
V_3 -> V_79 ,
V_3 -> V_86 ,
V_3 -> V_87 ,
V_3 -> V_94 ,
V_3 -> V_93 ,
V_3 -> V_115 ,
V_3 -> V_116 ) ;
}
}
}
F_83 (
V_157 ,
( T_17 * ) ( void * ) V_187 . V_185 -> T_14 ,
V_187 . V_185 -> V_214 ) ;
F_84 (
( T_12 * * ) ( void * ) V_187 . V_208 -> T_14 ,
V_187 . V_208 -> V_214 ) ;
}
void
F_85 ( void )
{
T_21 * V_215 ;
V_157 = F_86 (
L_150 ,
L_151 ,
L_131 ) ;
F_87 ( L_131 , F_59 , V_157 ) ;
V_215 = F_88 (
V_157 ,
V_216 ) ;
F_89 (
V_215 ,
L_152 ,
L_153 ,
L_154
L_155 ,
& V_138 ) ;
F_89 (
V_215 ,
L_156 ,
L_157 ,
L_158 ,
& V_8 ) ;
F_90 (
V_215 ,
L_159 ,
L_160 ,
L_161 ,
10 , & V_217 ) ;
F_91 (
V_215 ,
L_162 ,
L_163 ,
L_164 ,
& V_7 ,
V_218 ,
FALSE ) ;
F_92 ( L_131 , F_63 ) ;
}
void
V_216 ( void )
{
static T_11 V_219 = FALSE ;
static T_22 V_220 ;
static int V_221 = - 1 ;
if ( ! V_219 )
{
V_220 = F_93 (
F_59 ,
V_157 ) ;
V_108 = F_94 ( L_165 ) ;
V_219 = TRUE ;
}
if ( V_221 != - 1 )
{
F_95 ( L_166 , V_221 , V_220 ) ;
}
V_221 = V_217 ;
F_96 ( L_166 , V_221 , V_220 ) ;
}
