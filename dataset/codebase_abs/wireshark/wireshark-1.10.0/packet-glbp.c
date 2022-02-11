static int
F_1 ( T_1 * V_1 , int V_2 ,
T_2 * V_3 , T_3 * V_4 )
{
T_4 V_5 ;
T_4 V_6 ;
F_2 ( V_4 , V_7 , V_1 , V_2 , 1 , V_8 ) ;
V_2 ++ ;
F_2 ( V_4 , V_9 , V_1 , V_2 , 1 , V_10 ) ;
V_2 ++ ;
F_2 ( V_4 , V_11 , V_1 , V_2 , 1 , V_8 ) ;
V_2 ++ ;
F_2 ( V_4 , V_12 , V_1 , V_2 , 1 , V_10 ) ;
V_2 ++ ;
F_2 ( V_4 , V_13 , V_1 , V_2 , 2 , V_8 ) ;
V_2 += 2 ;
F_2 ( V_4 , V_14 , V_1 , V_2 , 4 , V_10 ) ;
V_2 += 4 ;
F_2 ( V_4 , V_15 , V_1 , V_2 , 4 , V_10 ) ;
V_2 += 4 ;
F_2 ( V_4 , V_16 , V_1 , V_2 , 2 , V_10 ) ;
V_2 += 2 ;
F_2 ( V_4 , V_17 , V_1 , V_2 , 2 , V_10 ) ;
V_2 += 2 ;
F_2 ( V_4 , V_18 , V_1 , V_2 , 2 , V_8 ) ;
V_2 += 2 ;
F_2 ( V_4 , V_19 , V_1 , V_2 , 1 , V_10 ) ;
V_5 = F_3 ( V_1 , V_2 ) ;
V_2 ++ ;
F_2 ( V_4 , V_20 , V_1 , V_2 , 1 , V_10 ) ;
V_6 = F_3 ( V_1 , V_2 ) ;
V_2 ++ ;
switch ( V_5 ) {
case 1 :
if ( V_6 != 4 ) {
F_4 ( V_3 , NULL , V_21 , V_22 , L_1 , V_6 ) ;
return V_2 + V_6 ;
}
F_2 ( V_4 , V_23 , V_1 , V_2 , V_6 , V_10 ) ;
break;
case 2 :
if ( V_6 != 16 ) {
F_4 ( V_3 , NULL , V_21 , V_22 , L_2 , V_6 ) ;
return V_2 + V_6 ;
}
F_2 ( V_4 , V_24 , V_1 , V_2 , V_6 , V_8 ) ;
break;
default:
F_2 ( V_4 , V_25 , V_1 , V_2 , V_6 , V_8 ) ;
break;
}
V_2 += V_6 ;
F_5 ( V_3 -> V_26 , V_27 , L_3 ,
F_6 ( V_5 , V_28 , L_4 ) ) ;
return V_2 ;
}
static int
F_7 ( T_1 * V_1 , int V_2 ,
T_2 * V_3 V_29 , T_3 * V_4 )
{
F_2 ( V_4 , V_30 , V_1 , V_2 , 1 , V_10 ) ;
V_2 ++ ;
F_2 ( V_4 , V_31 , V_1 , V_2 , 1 , V_10 ) ;
V_2 ++ ;
F_2 ( V_4 , V_32 , V_1 , V_2 , 1 , V_8 ) ;
V_2 += 1 ;
F_2 ( V_4 , V_33 , V_1 , V_2 , 1 , V_10 ) ;
V_2 ++ ;
F_2 ( V_4 , V_34 , V_1 , V_2 , 1 , V_10 ) ;
V_2 ++ ;
F_2 ( V_4 , V_35 , V_1 , V_2 , 7 , V_8 ) ;
V_2 += 7 ;
F_2 ( V_4 , V_36 , V_1 , V_2 , 6 , V_8 ) ;
V_2 += 6 ;
return V_2 ;
}
static int
F_8 ( T_1 * V_1 , int V_2 ,
T_2 * V_3 V_29 , T_3 * V_4 )
{
T_4 V_37 ;
T_4 V_38 ;
F_2 ( V_4 , V_39 , V_1 , V_2 , 1 , V_10 ) ;
V_37 = F_3 ( V_1 , V_2 ) ;
V_2 ++ ;
F_2 ( V_4 , V_40 , V_1 , V_2 , 1 , V_10 ) ;
V_38 = F_3 ( V_1 , V_2 ) ;
V_2 ++ ;
switch( V_37 ) {
case 1 :
F_2 ( V_4 , V_41 , V_1 , V_2 , V_38 , V_42 | V_8 ) ;
V_2 += V_38 ;
break;
case 2 :
F_2 ( V_4 , V_43 , V_1 , V_2 , V_38 , V_8 ) ;
V_2 += V_38 ;
break;
case 3 :
F_2 ( V_4 , V_44 , V_1 , V_2 , 4 , V_10 ) ;
F_2 ( V_4 , V_45 , V_1 , V_2 + 4 , V_38 - 4 , V_8 ) ;
V_2 += V_38 ;
break;
default:
F_2 ( V_4 , V_46 , V_1 , V_2 , V_38 , V_8 ) ;
V_2 += V_38 ;
break;
}
return V_2 ;
}
static int
F_9 ( T_1 * V_1 , int V_2 , T_5 V_47 ,
T_2 * V_3 V_29 , T_3 * V_4 )
{
F_2 ( V_4 , V_48 , V_1 , V_2 , V_47 , V_8 ) ;
V_2 += V_47 ;
return V_2 ;
}
static int
F_10 ( T_1 * V_1 , T_2 * V_3 , T_3 * V_49 )
{
T_3 * V_50 ;
T_3 * V_4 ;
T_6 * V_51 ;
T_4 type ;
int V_2 = 0 ;
int V_52 ;
T_4 V_47 ;
T_7 V_53 ;
V_53 = F_11 ( V_1 , 2 ) ;
F_12 ( V_3 -> V_26 , V_54 , L_5 ) ;
F_13 ( V_3 -> V_26 , V_27 , L_6 , V_53 ) ;
V_51 = F_2 ( V_49 , V_55 , V_1 , 0 , - 1 , V_8 ) ;
V_50 = F_14 ( V_51 , V_56 ) ;
F_2 ( V_50 , V_57 , V_1 , V_2 , 1 , V_10 ) ;
V_2 ++ ;
F_2 ( V_50 , V_58 , V_1 , V_2 , 1 , V_10 ) ;
V_2 ++ ;
F_2 ( V_50 , V_59 , V_1 , V_2 , 2 , V_10 ) ;
V_2 += 2 ;
F_2 ( V_50 , V_60 , V_1 , V_2 , 2 , V_8 ) ;
V_2 += 2 ;
F_2 ( V_50 , V_61 , V_1 , V_2 , 6 , V_8 ) ;
V_2 += 6 ;
while ( F_15 ( V_1 , V_2 ) > 0 ) {
type = F_3 ( V_1 , V_2 ) ;
V_47 = F_3 ( V_1 , V_2 + 1 ) ;
if ( V_47 < 2 ) {
F_4 ( V_3 , NULL , V_21 , V_22 , L_7 , V_47 ) ;
return V_2 ;
}
V_47 -= 2 ;
V_51 = F_2 ( V_50 , V_62 , V_1 , V_2 , V_47 + 2 , V_10 ) ;
V_4 = F_14 ( V_51 , V_63 ) ;
F_16 ( V_51 , L_8 , V_47 + 2 ,
F_6 ( type , V_64 , L_4 ) ) ;
F_2 ( V_4 , V_65 , V_1 , V_2 , 1 , V_10 ) ;
V_2 ++ ;
F_2 ( V_4 , V_66 , V_1 , V_2 , 1 , V_10 ) ;
V_2 ++ ;
F_5 ( V_3 -> V_26 , V_27 , L_3 ,
F_6 ( type , V_64 , L_4 ) ) ;
V_52 = V_2 ;
switch( type ) {
case 1 :
V_2 = F_1 ( V_1 , V_2 , V_3 , V_4 ) ;
break;
case 2 :
V_2 = F_7 ( V_1 , V_2 , V_3 , V_4 ) ;
break;
case 3 :
V_2 = F_8 ( V_1 , V_2 , V_3 , V_4 ) ;
break;
default:
V_2 = F_9 ( V_1 , V_2 , V_47 , V_3 , V_4 ) ;
break;
}
if ( V_52 >= V_2 ) {
F_4 ( V_3 , NULL , V_21 , V_22 , L_9 ) ;
return V_52 ;
}
if ( V_52 + V_47 > V_2 )
V_2 = V_52 + V_47 ;
}
return V_2 ;
}
static T_8
F_17 ( T_1 * V_1 , T_2 * V_3 )
{
T_5 V_67 ;
if ( F_18 ( V_1 ) < 2 )
return FALSE ;
V_67 = F_3 ( V_1 , 1 ) ;
if ( F_3 ( V_1 , 0 ) != 1
|| V_67 > 4
|| V_3 -> V_68 != V_3 -> V_69
#if 0
|| unknown1 == 0 && pinfo->net_dst != ipv4:224.0.0.102
&& pinfo->net_dst != ipv6:...
|| unknown1 == 0 && pinfo->dl_src != ether:c2-00-7c-b8-00-00
#endif
) {
return FALSE ;
}
return TRUE ;
}
static int
F_19 ( T_1 * V_1 , T_2 * V_3 , T_3 * V_49 , void * T_9 V_29 )
{
if ( ! F_17 ( V_1 , V_3 ) ) {
return 0 ;
}
return F_10 ( V_1 , V_3 , V_49 ) ;
}
void
F_20 ( void )
{
static T_10 V_70 [] = {
{ & V_57 ,
{ L_10 , L_11 , V_71 , V_72 , NULL ,
0x0 , NULL , V_73 } } ,
{ & V_58 ,
{ L_12 , L_13 , V_71 , V_72 , NULL ,
0x0 , NULL , V_73 } } ,
{ & V_59 ,
{ L_14 , L_15 , V_74 , V_72 , NULL ,
0x0 , NULL , V_73 } } ,
{ & V_60 ,
{ L_16 , L_17 , V_75 , V_76 , NULL ,
0x0 , NULL , V_73 } } ,
{ & V_61 ,
{ L_18 , L_19 , V_77 , V_76 , NULL ,
0x0 , NULL , V_73 } } ,
{ & V_62 ,
{ L_20 , L_21 , V_78 , V_76 , NULL ,
0x0 , NULL , V_73 } } ,
{ & V_65 ,
{ L_22 , L_23 , V_71 , V_72 , F_21 ( V_64 ) ,
0x0 , NULL , V_73 } } ,
{ & V_66 ,
{ L_24 , L_25 , V_71 , V_72 , NULL ,
0x0 , NULL , V_73 } } ,
{ & V_7 ,
{ L_26 , L_27 , V_75 , V_76 , NULL ,
0x0 , NULL , V_73 } } ,
{ & V_9 ,
{ L_28 , L_29 , V_71 , V_72 , F_21 ( V_79 ) ,
0x0 , NULL , V_73 } } ,
{ & V_11 ,
{ L_30 , L_31 , V_75 , V_76 , NULL ,
0x0 , NULL , V_73 } } ,
{ & V_12 ,
{ L_32 , L_33 , V_71 , V_72 , NULL ,
0x0 , NULL , V_73 } } ,
{ & V_13 ,
{ L_34 , L_35 , V_75 , V_76 , NULL ,
0x0 , NULL , V_73 } } ,
{ & V_14 ,
{ L_36 , L_37 , V_80 , V_72 , NULL ,
0x0 , L_38 , V_73 } } ,
{ & V_15 ,
{ L_39 , L_40 , V_80 , V_72 , NULL ,
0x0 , L_41 , V_73 } } ,
{ & V_16 ,
{ L_42 , L_43 , V_74 , V_72 , NULL ,
0x0 , L_44 , V_73 } } ,
{ & V_17 ,
{ L_45 , L_46 , V_74 , V_72 , NULL ,
0x0 , L_47 , V_73 } } ,
{ & V_18 ,
{ L_48 , L_49 , V_75 , V_76 , NULL ,
0x0 , NULL , V_73 } } ,
{ & V_19 ,
{ L_50 , L_51 , V_71 , V_72 , F_21 ( V_28 ) ,
0x0 , NULL , V_73 } } ,
{ & V_20 ,
{ L_52 , L_53 , V_71 , V_72 , NULL ,
0x0 , NULL , V_73 } } ,
{ & V_23 ,
{ L_54 , L_55 , V_81 , V_76 , NULL ,
0x0 , NULL , V_73 } } ,
{ & V_24 ,
{ L_56 , L_57 , V_82 , V_76 , NULL ,
0x0 , NULL , V_73 } } ,
{ & V_25 ,
{ L_58 , L_59 , V_75 , V_76 , NULL ,
0x0 , NULL , V_73 } } ,
{ & V_30 ,
{ L_60 , L_61 , V_71 , V_72 , NULL ,
0x0 , NULL , V_73 } } ,
{ & V_31 ,
{ L_62 , L_63 , V_71 , V_72 , F_21 ( V_83 ) ,
0x0 , NULL , V_73 } } ,
{ & V_32 ,
{ L_64 , L_65 , V_75 , V_76 , NULL ,
0x0 , NULL , V_73 } } ,
{ & V_33 ,
{ L_32 , L_66 , V_71 , V_72 , NULL ,
0x0 , NULL , V_73 } } ,
{ & V_34 ,
{ L_67 , L_68 , V_71 , V_72 , NULL ,
0x0 , NULL , V_73 } } ,
{ & V_35 ,
{ L_69 , L_70 , V_75 , V_76 , NULL ,
0x0 , NULL , V_73 } } ,
{ & V_36 ,
{ L_71 , L_72 , V_77 , V_76 , NULL ,
0x0 , NULL , V_73 } } ,
{ & V_39 ,
{ L_73 , L_74 , V_71 , V_72 , F_21 ( V_84 ) ,
0x0 , NULL , V_73 } } ,
{ & V_40 ,
{ L_75 , L_76 , V_71 , V_72 , NULL ,
0x0 , NULL , V_73 } } ,
{ & V_41 ,
{ L_77 , L_78 , V_85 , V_76 , NULL ,
0x0 , NULL , V_73 } } ,
{ & V_43 ,
{ L_79 , L_80 , V_75 , V_76 , NULL ,
0x0 , NULL , V_73 } } ,
{ & V_44 ,
{ L_81 , L_82 , V_80 , V_72 , NULL ,
0x0 , NULL , V_73 } } ,
{ & V_45 ,
{ L_83 , L_84 , V_75 , V_76 , NULL ,
0x0 , NULL , V_73 } } ,
{ & V_46 ,
{ L_85 , L_86 , V_75 , V_76 , NULL ,
0x0 , NULL , V_73 } } ,
{ & V_48 ,
{ L_87 , L_88 , V_75 , V_76 , NULL ,
0x0 , NULL , V_73 } } ,
} ;
static T_11 * V_86 [] = {
& V_56 ,
& V_63 ,
} ;
V_55 = F_22 (
L_89 , L_5 , L_90 ) ;
F_23 ( V_55 , V_70 , F_24 ( V_70 ) ) ;
F_25 ( V_86 , F_24 ( V_86 ) ) ;
}
void
F_26 ( void )
{
T_12 V_87 ;
V_87 = F_27 ( F_19 , V_55 ) ;
F_28 ( L_91 , 3222 , V_87 ) ;
}
