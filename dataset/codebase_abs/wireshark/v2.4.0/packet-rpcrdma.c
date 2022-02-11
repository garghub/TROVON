static T_1 F_1 ( T_2 * V_1 , T_1 V_2 , T_1 V_3 )
{
T_3 V_4 ;
T_1 V_5 = V_3 ;
while ( 1 ) {
V_4 = F_2 ( V_1 , V_3 ) ;
V_3 += 4 ;
if ( V_3 > V_2 )
return 0 ;
if ( ! V_4 )
break;
V_3 += 20 ;
if ( V_3 > V_2 )
return 0 ;
}
return V_3 - V_5 ;
}
static T_1 F_3 ( T_2 * V_1 , T_1 V_3 )
{
T_3 V_4 ;
T_1 V_6 ;
V_6 = 0 ;
while ( 1 ) {
V_4 = F_2 ( V_1 , V_3 ) ;
V_3 += 4 ;
if ( ! V_4 )
break;
V_6 ++ ;
V_3 += 20 ;
}
return V_6 ;
}
static T_1 F_4 ( T_2 * V_1 , T_1 V_3 )
{
T_1 V_7 ;
V_7 = F_2 ( V_1 , V_3 ) ;
return 4 + ( V_7 * 16 ) ;
}
static T_1 F_5 ( T_2 * V_1 , T_1 V_2 , T_1 V_3 )
{
T_3 V_4 ;
T_1 V_8 , V_5 = V_3 ;
while ( 1 ) {
V_4 = F_2 ( V_1 , V_3 ) ;
V_3 += 4 ;
if ( V_3 > V_2 )
return 0 ;
if ( ! V_4 )
break;
V_8 = F_4 ( V_1 , V_3 ) ;
if ( ( V_3 + V_8 ) < V_3 ||
( V_3 + V_8 ) > V_2 )
return 0 ;
V_3 += V_8 ;
}
return V_3 - V_5 ;
}
static T_1 F_6 ( T_2 * V_1 , T_1 V_3 )
{
T_3 V_4 ;
T_1 V_6 , V_8 ;
V_6 = 0 ;
while ( 1 ) {
V_4 = F_2 ( V_1 , V_3 ) ;
V_3 += 4 ;
if ( ! V_4 )
break;
V_6 ++ ;
V_8 = F_4 ( V_1 , V_3 ) ;
if ( ( V_3 + V_8 ) < V_3 )
break;
}
return V_6 ;
}
static T_1 F_7 ( T_2 * V_1 , T_1 V_2 , T_1 V_3 )
{
T_3 V_4 ;
T_1 V_5 = V_3 ;
V_4 = F_2 ( V_1 , V_3 ) ;
V_3 += 4 ;
if ( V_3 > V_2 )
return 0 ;
if ( V_4 ) {
V_3 += F_4 ( V_1 , V_3 ) ;
if ( V_3 > V_2 )
return 0 ;
}
return V_3 - V_5 ;
}
static T_1 F_8 ( T_2 * V_1 , T_1 V_3 )
{
T_3 V_4 ;
V_4 = F_2 ( V_1 , V_3 ) ;
return V_4 ? 1 : 0 ;
}
static T_1 F_9 ( T_4 * V_9 ,
T_2 * V_1 , T_1 V_3 )
{
T_4 * V_10 ;
T_3 V_11 ;
V_11 = F_2 ( V_1 , V_3 ) ;
V_10 = F_10 ( V_9 , V_1 ,
V_3 , 20 , V_12 , NULL ,
L_1 , V_11 ) ;
F_11 ( V_10 , V_13 , V_1 ,
V_3 , 4 , V_14 ) ;
V_3 += 4 ;
F_11 ( V_10 , V_15 , V_1 ,
V_3 , 4 , V_14 ) ;
V_3 += 4 ;
F_11 ( V_10 , V_16 , V_1 ,
V_3 , 4 , V_14 ) ;
V_3 += 4 ;
F_11 ( V_10 , V_17 , V_1 ,
V_3 , 8 , V_14 ) ;
return V_3 + 8 ;
}
static T_1 F_12 ( T_2 * V_1 , T_1 V_3 ,
T_4 * V_18 )
{
T_1 V_19 , V_5 = V_3 ;
T_4 * V_9 ;
T_3 V_4 ;
T_5 * V_20 ;
V_19 = F_3 ( V_1 , V_3 ) ;
V_20 = F_13 ( V_18 , V_21 ,
V_1 , V_3 , 0 , V_19 ,
L_2 , V_19 ) ;
V_9 = F_14 ( V_20 , V_22 ) ;
while ( 1 ) {
V_4 = F_2 ( V_1 , V_3 ) ;
V_3 += 4 ;
if ( ! V_4 )
break;
V_3 = F_9 ( V_9 , V_1 , V_3 ) ;
}
F_15 ( V_20 , V_3 - V_5 ) ;
return V_3 ;
}
static T_1 F_16 ( T_4 * V_23 , T_2 * V_1 ,
T_1 V_3 , T_3 V_24 )
{
T_4 * V_25 ;
V_25 = F_10 ( V_23 , V_1 ,
V_3 , 16 , V_26 , NULL ,
L_3 , V_24 ) ;
F_11 ( V_25 , V_15 , V_1 ,
V_3 , 4 , V_14 ) ;
V_3 += 4 ;
F_11 ( V_25 , V_16 , V_1 ,
V_3 , 4 , V_14 ) ;
V_3 += 4 ;
F_11 ( V_25 , V_17 , V_1 ,
V_3 , 8 , V_14 ) ;
return V_3 + 8 ;
}
static T_1 F_17 ( T_4 * V_27 ,
T_2 * V_1 , T_1 V_3 )
{
T_3 V_24 , V_7 ;
T_4 * V_23 ;
T_1 V_28 ;
V_28 = F_4 ( V_1 , V_3 ) ;
V_7 = F_2 ( V_1 , V_3 ) ;
V_23 = F_10 ( V_27 , V_1 ,
V_3 , V_28 ,
V_29 , NULL ,
L_4 , V_7 ,
V_7 == 1 ? L_5 : L_6 ) ;
F_11 ( V_23 , V_30 ,
V_1 , V_3 , 4 , V_14 ) ;
V_3 += 4 ;
for ( V_24 = 0 ; V_24 < V_7 ; ++ V_24 )
V_3 = F_16 ( V_23 , V_1 , V_3 , V_24 ) ;
return V_3 ;
}
static T_1 F_18 ( T_2 * V_1 , T_1 V_3 ,
T_4 * V_18 )
{
T_1 V_19 , V_5 = V_3 ;
T_4 * V_27 ;
T_3 V_4 ;
T_5 * V_20 ;
V_19 = F_6 ( V_1 , V_3 ) ;
V_20 = F_13 ( V_18 , V_31 ,
V_1 , V_3 , 0 , V_19 ,
L_7 , V_19 ) ;
V_27 = F_14 ( V_20 , V_32 ) ;
while ( 1 ) {
V_4 = F_2 ( V_1 , V_3 ) ;
V_3 += 4 ;
if ( ! V_4 )
break;
V_3 = F_17 ( V_27 , V_1 , V_3 ) ;
}
F_15 ( V_20 , V_3 - V_5 ) ;
return V_3 ;
}
static T_1 F_19 ( T_2 * V_1 , T_1 V_3 ,
T_4 * V_18 )
{
T_3 V_19 , V_5 = V_3 ;
T_4 * V_33 ;
T_3 V_4 ;
T_5 * V_20 ;
V_19 = F_8 ( V_1 , V_3 ) ;
V_20 = F_13 ( V_18 , V_34 ,
V_1 , V_3 , 4 , V_19 ,
L_8 , V_19 ) ;
V_33 = F_14 ( V_20 , V_35 ) ;
V_4 = F_2 ( V_1 , V_3 ) ;
V_3 += 4 ;
if ( ! V_4 )
return V_3 ;
V_3 = F_17 ( V_33 , V_1 , V_3 ) ;
F_15 ( V_20 , V_3 - V_5 ) ;
return V_3 ;
}
static T_1 F_20 ( T_2 * V_1 , T_1 V_3 , T_4 * V_18 )
{
V_3 = F_12 ( V_1 , V_3 , V_18 ) ;
V_3 = F_18 ( V_1 , V_3 , V_18 ) ;
return F_19 ( V_1 , V_3 , V_18 ) ;
}
static T_1 F_21 ( T_2 * V_1 , T_1 V_2 , T_1 V_3 )
{
T_1 V_36 , V_5 = V_3 ;
V_36 = F_1 ( V_1 , V_2 , V_3 ) ;
if ( ! V_36 )
return 0 ;
V_3 += V_36 ;
V_36 = F_5 ( V_1 , V_2 , V_3 ) ;
if ( ! V_36 )
return 0 ;
V_3 += V_36 ;
V_36 = F_7 ( V_1 , V_2 , V_3 ) ;
if ( ! V_36 )
return 0 ;
V_3 += V_36 ;
return V_3 - V_5 ;
}
static T_6
F_22 ( T_2 * V_1 )
{
T_1 V_36 , V_37 = F_23 ( V_1 ) ;
T_3 V_38 ;
T_3 V_39 = F_2 ( V_1 , 0 ) ;
T_3 V_40 = F_2 ( V_1 , 12 ) ;
T_1 V_3 ;
if ( V_37 < V_41 )
return 0 ;
switch ( V_40 ) {
case V_42 :
if ( V_37 < V_43 )
return FALSE ;
V_3 = V_41 ;
V_36 = F_21 ( V_1 , V_37 , V_3 ) ;
if ( ! V_36 )
return FALSE ;
V_3 += V_36 ;
if ( V_3 + 4 > V_37 )
return FALSE ;
V_38 = F_2 ( V_1 , V_3 ) ;
if ( V_39 != V_38 )
return FALSE ;
break;
case V_44 :
if ( V_37 < V_45 )
return FALSE ;
V_3 = V_41 + 8 ;
V_36 = F_21 ( V_1 , V_37 , V_3 ) ;
if ( ! V_36 )
return FALSE ;
V_3 += V_36 ;
if ( V_3 + 4 > V_37 )
return FALSE ;
V_38 = F_2 ( V_1 , V_3 ) ;
if ( V_39 != V_38 )
return FALSE ;
break;
case V_46 :
case V_47 :
case V_48 :
break;
default:
return FALSE ;
}
return TRUE ;
}
static int
F_24 ( T_2 * V_1 , T_7 * V_49 , T_4 * V_18 , void * T_8 V_50 )
{
T_2 * V_51 ;
T_5 * V_52 ;
T_4 * V_53 ;
T_1 V_3 = 0 ;
T_3 V_40 = F_2 ( V_1 , 12 ) ;
T_3 V_39 ;
T_3 V_54 ;
if ( F_2 ( V_1 , 4 ) != 1 )
return 0 ;
V_39 = F_2 ( V_1 , 0 ) ;
F_25 ( V_49 -> V_55 , V_56 , L_9 ) ;
F_26 ( V_49 -> V_55 , V_57 , L_10 ,
F_27 ( V_40 , V_58 , L_11 ) , V_39 ) ;
V_52 = F_11 ( V_18 , V_59 , V_1 , 0 , V_41 , V_60 ) ;
V_53 = F_14 ( V_52 , V_61 ) ;
F_11 ( V_53 , V_62 , V_1 ,
V_3 , 4 , V_14 ) ;
V_3 += 4 ;
F_11 ( V_53 , V_63 , V_1 ,
V_3 , 4 , V_14 ) ;
V_3 += 4 ;
F_11 ( V_53 , V_64 , V_1 ,
V_3 , 4 , V_14 ) ;
V_3 += 4 ;
F_11 ( V_53 , V_65 , V_1 ,
V_3 , 4 , V_14 ) ;
V_3 += 4 ;
switch ( V_40 ) {
case V_42 :
V_3 = F_20 ( V_1 , V_3 , V_53 ) ;
F_15 ( V_52 , V_3 ) ;
V_51 = F_28 ( V_1 , V_3 ) ;
return F_29 ( V_66 , V_51 , V_49 , V_18 ) ;
case V_46 :
V_3 = F_20 ( V_1 , V_3 , V_53 ) ;
break;
case V_44 :
F_11 ( V_53 , V_67 , V_1 ,
V_3 , 4 , V_14 ) ;
V_3 += 4 ;
F_11 ( V_53 , V_68 , V_1 ,
V_3 , 4 , V_14 ) ;
V_3 += 4 ;
V_3 = F_20 ( V_1 , V_3 , V_53 ) ;
F_15 ( V_52 , V_3 ) ;
V_51 = F_28 ( V_1 , V_3 ) ;
return F_29 ( V_66 , V_51 , V_49 , V_18 ) ;
case V_47 :
break;
case V_48 :
V_54 = F_2 ( V_1 , V_3 ) ;
F_11 ( V_53 , V_69 , V_1 ,
V_3 , 4 , V_14 ) ;
V_3 += 4 ;
switch ( V_54 ) {
case V_70 :
F_11 ( V_53 , V_71 , V_1 ,
V_3 , 4 , V_14 ) ;
V_3 += 4 ;
F_11 ( V_53 , V_72 , V_1 ,
V_3 , 4 , V_14 ) ;
V_3 += 4 ;
break;
case V_73 :
break;
default:
F_15 ( V_52 , V_3 ) ;
V_51 = F_28 ( V_1 , V_3 ) ;
return F_30 ( V_51 , V_49 , V_18 ) ;
}
break;
}
F_15 ( V_52 , V_3 ) ;
return V_3 ;
}
static T_6
F_31 ( T_2 * V_1 , T_7 * V_49 ,
T_4 * V_18 , void * T_8 )
{
struct V_74 * V_75 = (struct V_74 * ) T_8 ;
if ( ! V_75 )
return FALSE ;
switch ( V_75 -> V_76 ) {
case V_77 :
case V_78 :
case V_79 :
case V_80 :
case V_81 :
case V_82 :
break;
default:
return FALSE ;
}
if ( ! F_22 ( V_1 ) )
return FALSE ;
F_24 ( V_1 , V_49 , V_18 , NULL ) ;
return TRUE ;
}
static T_6
F_32 ( T_2 * V_1 , T_7 * V_49 ,
T_4 * V_18 , void * T_8 )
{
struct V_83 * V_75 = (struct V_83 * ) T_8 ;
if ( ! V_75 )
return FALSE ;
switch ( V_75 -> V_84 ) {
case V_85 :
case V_86 :
break;
default:
return FALSE ;
}
if ( ! F_22 ( V_1 ) )
return FALSE ;
F_24 ( V_1 , V_49 , V_18 , NULL ) ;
return TRUE ;
}
void
F_33 ( void )
{
T_9 * V_87 ;
static T_10 V_88 [] = {
{ & V_62 ,
{ L_12 , L_13 ,
V_89 , V_90 ,
NULL , 0x0 , NULL , V_91 }
} ,
{ & V_63 ,
{ L_14 , L_15 ,
V_89 , V_92 ,
NULL , 0x0 , NULL , V_91 }
} ,
{ & V_64 ,
{ L_16 , L_17 ,
V_89 , V_92 ,
NULL , 0x0 , NULL , V_91 }
} ,
{ & V_65 ,
{ L_18 , L_19 ,
V_89 , V_92 ,
F_34 ( V_58 ) , 0x0 , NULL , V_91 }
} ,
{ & V_21 ,
{ L_20 , L_21 ,
V_89 , V_92 ,
NULL , 0 , NULL , V_91 }
} ,
{ & V_31 ,
{ L_22 , L_23 ,
V_89 , V_92 ,
NULL , 0 , NULL , V_91 }
} ,
{ & V_34 ,
{ L_24 , L_25 ,
V_89 , V_92 ,
NULL , 0 , NULL , V_91 }
} ,
{ & V_15 ,
{ L_26 , L_27 ,
V_89 , V_90 ,
NULL , 0 , NULL , V_91 }
} ,
{ & V_16 ,
{ L_28 , L_29 ,
V_89 , V_92 ,
NULL , 0 , NULL , V_91 }
} ,
{ & V_17 ,
{ L_30 , L_31 ,
V_93 , V_90 ,
NULL , 0 , NULL , V_91 }
} ,
{ & V_13 ,
{ L_32 , L_33 ,
V_89 , V_92 ,
NULL , 0 , NULL , V_91 }
} ,
{ & V_30 ,
{ L_34 , L_35 ,
V_89 , V_92 ,
NULL , 0 , NULL , V_91 }
} ,
{ & V_67 ,
{ L_36 , L_37 ,
V_89 , V_92 ,
NULL , 0 , NULL , V_91 }
} ,
{ & V_68 ,
{ L_38 , L_39 ,
V_89 , V_92 ,
NULL , 0 , NULL , V_91 }
} ,
{ & V_69 ,
{ L_40 , L_41 ,
V_89 , V_92 ,
F_34 ( V_94 ) , 0 , NULL , V_91 }
} ,
{ & V_71 ,
{ L_42 , L_43 ,
V_89 , V_92 ,
NULL , 0 , NULL , V_91 }
} ,
{ & V_72 ,
{ L_44 , L_45 ,
V_89 , V_92 ,
NULL , 0 , NULL , V_91 }
} ,
} ;
static T_11 * V_95 [] = {
& V_61 ,
& V_96 ,
& V_22 ,
& V_12 ,
& V_32 ,
& V_29 ,
& V_35 ,
& V_26 ,
} ;
V_59 = F_35 (
L_46 ,
L_9 ,
L_47
) ;
F_36 ( V_59 , V_88 , F_37 ( V_88 ) ) ;
F_38 ( V_95 , F_37 ( V_95 ) ) ;
V_87 = F_39 ( V_59 , V_97 ) ;
F_40 ( V_87 , L_48 ) ;
F_40 ( V_87 , L_49 ) ;
F_40 ( V_87 , L_50 ) ;
F_40 ( V_87 , L_51 ) ;
F_40 ( V_87 , L_52 ) ;
F_40 ( V_87 , L_53 ) ;
F_40 ( V_87 , L_54 ) ;
F_40 ( V_87 , L_55 ) ;
F_40 ( V_87 , L_56 ) ;
F_40 ( V_87 , L_57 ) ;
}
void
V_97 ( void )
{
F_41 ( L_58 , F_31 , L_59 ,
L_60 , V_59 , V_98 ) ;
F_42 ( L_61 , F_43 ( F_24 , V_59 ) ) ;
F_41 ( L_62 , F_32 , L_63 ,
L_64 , V_59 , V_98 ) ;
V_66 = F_44 ( L_65 , V_59 ) ;
}
