static void
F_1 ( void )
{
F_2 () ;
}
static int
F_3 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , void * T_4 V_4 )
{
T_5 * V_5 ;
T_3 * V_6 ;
T_1 * V_7 ;
T_6 * V_8 ;
int V_9 = 0 ;
int V_10 ;
T_6 V_11 ;
T_7 V_12 ;
int V_13 ;
int V_14 ;
T_8 V_15 ;
V_16 = V_3 ;
V_12 = F_4 ( V_1 , V_9 ) ;
if( V_12 == 0xffff ) {
V_9 = V_9 + 2 ;
V_11 = F_5 ( V_1 , V_9 ) ;
} else{
V_11 = F_5 ( V_1 , V_9 ) ;
}
if ( ( V_11 & 0xf8 ) != 0xf8 )
return V_9 ;
V_10 = F_6 ( V_1 , V_9 ) ;
for( V_13 = 0 ; V_13 < ( V_10 - 1 ) ; ++ V_13 ) {
V_12 = F_4 ( V_1 , V_9 + V_13 ) ;
if ( 0xffff == V_12 ) break;
}
if ( V_13 >= ( V_10 - 1 ) ) {
if ( V_2 -> V_17 || V_2 -> V_18 ) {
V_2 -> V_19 = V_9 ;
V_2 -> V_20 = V_21 ;
return - 1 ;
}
}
F_7 ( V_2 -> V_22 , V_23 , L_1 ) ;
F_8 ( V_2 -> V_22 , V_24 ) ;
V_10 = F_9 ( V_1 , V_9 ) ;
V_25:
V_5 = F_10 ( V_3 , V_26 , V_1 , 0 , - 1 , V_27 ) ;
V_6 = F_11 ( V_5 , V_28 ) ;
V_13 = 0 ;
V_15 = FALSE ;
V_8 = ( T_6 * ) F_12 ( V_2 -> V_29 , V_10 - V_9 ) ;
if ( V_30 > 2 )
F_13 ( V_6 , V_1 , V_9 , - 1 , L_2 ) ;
while ( ( V_9 < V_10 ) && ( V_15 == FALSE ) ) {
V_11 = F_5 ( V_1 , V_9 ) ;
if ( V_11 == 0xff ) {
if ( V_9 + 1 >= V_10 ) {
V_9 ++ ;
continue;
}
if ( V_30 > 2 )
F_13 ( V_6 , V_1 , V_9 , 2 ,
L_3 ) ;
V_11 = F_5 ( V_1 , V_9 + 1 ) ;
if ( V_11 == 0 ) {
V_8 [ V_13 ] = 0xff ;
V_9 = V_9 + 2 ;
V_13 ++ ;
continue;
}
if ( ( V_11 > 0x7f ) && ( V_11 < 0xff ) ) {
if ( V_30 > 2 )
F_13 ( V_6 , V_1 , V_9 , 2 ,
L_4 ) ;
V_9 = V_9 + F_9 ( V_1 , V_9 ) ;
return V_9 ;
}
if ( V_11 == 0xff ) {
if ( V_30 > 2 )
F_13 ( V_6 , V_1 , V_9 , 2 ,
L_5 ) ;
V_15 = TRUE ;
V_9 = V_9 + 2 ;
continue;
}
V_8 [ V_13 ] = 0xff ;
if ( V_30 > 2 )
F_13 ( V_6 , V_1 , V_9 , 1 ,
L_6 , V_13 , V_8 [ V_13 ] ) ;
V_13 ++ ;
V_9 = V_9 + 2 ;
if ( V_30 > 2 )
F_13 ( V_6 , V_1 , V_9 , V_11 ,
L_7 , V_11 ) ;
if( V_9 + V_11 >= V_10 )
V_11 = V_10 - V_9 ;
for ( V_14 = 0 ; V_14 < V_11 ; V_14 ++ ) {
V_8 [ V_13 ] = F_5 ( V_1 , V_9 ) ;
if ( V_30 > 2 )
F_13 ( V_6 , V_1 , V_9 , 1 ,
L_8 , V_13 , V_8 [ V_13 ] ) ;
V_13 ++ ;
V_9 ++ ;
}
continue;
}
V_8 [ V_13 ] = V_11 ;
if ( V_30 > 2 )
F_13 ( V_6 , V_1 , V_9 , 1 ,
L_6 , V_13 , V_8 [ V_13 ] ) ;
V_13 ++ ;
V_9 ++ ;
}
V_7 = F_14 ( V_1 , V_8 , V_13 , V_13 ) ;
F_15 ( V_2 , V_7 , L_9 ) ;
F_13 ( V_6 , V_7 , 0 , - 1 , L_10 ) ;
if ( V_15 == TRUE ) {
F_16 ( V_7 , V_2 , V_6 ) ;
} else{
F_13 ( V_6 , V_7 , 0 , - 1 , L_11 ) ;
}
if ( V_9 < V_10 ) {
goto V_25;
}
return V_9 ;
}
static int
F_17 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , void * V_12 V_4 )
{
T_5 * V_5 ;
T_3 * V_6 ;
T_9 V_9 = 0 ;
T_10 V_11 ;
if ( V_2 -> V_31 == V_32 )
return F_3 ( V_1 , V_2 , V_3 , NULL ) ;
V_11 = F_5 ( V_1 , V_9 ) ;
if ( ( V_11 & 0xf8 ) != 0xf8 )
return 0 ;
F_7 ( V_2 -> V_22 , V_23 , L_1 ) ;
F_8 ( V_2 -> V_22 , V_24 ) ;
V_16 = V_3 ;
V_5 = F_10 ( V_3 , V_26 , V_1 , 0 , - 1 , V_27 ) ;
V_6 = F_11 ( V_5 , V_28 ) ;
return F_16 ( V_1 , V_2 , V_6 ) ;
}
static int
F_16 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_6 )
{
T_1 * V_33 , * V_34 , * V_35 ;
T_1 * V_36 = NULL ;
T_5 * V_37 , * V_38 ;
T_3 * V_39 , * V_40 ;
T_9 V_9 = 0 ;
T_9 V_41 ;
T_7 V_42 ;
T_11 V_11 ;
T_6 V_43 [ 128 ] ;
T_6 V_44 [ 12 ] ;
T_11 V_45 ;
T_7 V_46 = 0 ;
T_7 V_47 = 0 ;
T_11 V_48 ;
T_9 V_49 = 0 ;
T_6 * V_8 ;
T_7 V_50 ;
T_6 V_13 ;
T_7 V_51 ;
T_7 V_52 ;
T_7 V_53 ;
T_7 V_54 ;
T_7 V_55 ;
T_12 * V_56 ;
T_6 V_57 ;
V_11 = F_5 ( V_1 , V_9 ) ;
F_10 ( V_6 , V_58 , V_1 , V_9 , 1 , V_59 ) ;
F_10 ( V_6 , V_60 , V_1 , V_9 , 1 , V_59 ) ;
V_45 = ( V_11 & 0x04 ) >> 2 ;
V_42 = V_11 & 0x03 ;
V_9 ++ ;
if ( V_42 != 0 ) {
V_42 = V_42 * 3 + 3 ;
F_7 ( V_2 -> V_22 , V_24 , L_12 ) ;
if ( V_45 == 1 ) {
V_46 = 1 ;
V_11 = F_5 ( V_1 , V_9 ) ;
if ( ( V_11 & 0x80 ) != 0 ) {
V_46 = V_11 & 0x7f ;
F_10 ( V_6 , V_61 ,
V_1 , V_9 , 1 , V_59 ) ;
V_9 ++ ;
F_18 ( V_1 , V_43 , V_9 , V_46 ) ;
} else {
V_43 [ 0 ] = F_5 ( V_1 , V_9 ) & 0x7f ;
}
F_19 ( V_6 , V_62 ,
V_1 , V_9 , V_46 , V_43 ) ;
V_9 = V_9 + V_46 ;
}
F_18 ( V_1 , V_44 , V_9 , V_42 ) ;
V_56 = F_20 ( V_44 , V_42 ) ;
F_21 ( V_6 , V_63 ,
V_1 , V_9 , V_42 , V_56 ) ;
V_9 = V_9 + V_42 ;
V_49 = F_22 ( V_1 , V_9 ) ;
if( V_49 > 0 ) {
T_5 * V_5 ;
V_5 = F_23 ( V_6 , V_64 , V_1 ,
V_9 , 0 , V_49 ) ;
F_24 ( V_5 ) ;
}
if ( V_65 ) {
V_34 = F_25 ( V_1 , V_9 , V_49 , V_49 ) ;
V_8 = ( T_6 * ) F_26 ( V_2 -> V_29 , V_66 ) ;
V_50 = 0 ;
V_51 = 0 ;
V_52 = 0 ;
V_53 = 0 ;
V_54 = 0 ;
V_13 = 0 ;
while ( V_13 < V_42 ) {
V_8 [ V_13 ] = V_44 [ V_13 ] ;
V_13 ++ ;
}
#if 0
result_code = udvm_state_access(tvb, sigcomp_tree, buff, p_id_start, partial_state_len, state_begin, &state_length,
&state_address, &state_instruction, hf_sigcomp_partial_state);
#endif
V_55 = F_27 ( V_1 , V_6 , V_8 , V_50 , V_67 , V_51 , & V_52 ,
& V_53 , & V_54 , V_63 ) ;
if ( V_55 != 0 ) {
T_5 * V_5 ;
V_5 = F_13 ( V_6 , V_1 , 0 , - 1 , L_13 ,
F_28 ( V_55 , V_68 , L_14 ) ) ;
F_24 ( V_5 ) ;
return F_29 ( V_1 ) ;
}
V_33 = F_14 ( V_1 , V_8 , V_52 + V_53 , V_52 + V_53 ) ;
F_15 ( V_2 , V_33 , L_15 ) ;
V_35 = F_25 ( V_33 , V_53 , V_52 , V_52 ) ;
V_38 = F_10 ( V_6 , V_69 ,
V_35 , 0 , V_52 ,
V_27 ) ;
V_40 = F_11 ( V_38 , V_70 ) ;
V_36 = F_30 ( V_35 , V_34 , V_2 ,
V_40 , V_53 ,
V_30 , V_63 ,
V_9 , V_52 , V_42 , V_54 ) ;
if ( V_36 ) {
T_5 * V_5 ;
T_13 V_71 =
( T_13 ) ( ( ( float ) F_29 ( V_36 ) / ( float ) F_29 ( V_1 ) ) * 100 ) ;
F_13 ( V_6 , V_36 , 0 , - 1 , L_16 ) ;
V_5 = F_23 ( V_6 , V_72 , V_36 ,
0 , 0 , V_71 ) ;
F_24 ( V_5 ) ;
if ( V_73 )
F_31 ( V_36 , V_16 ) ;
F_32 ( V_2 -> V_22 , V_23 , L_17 ) ;
F_33 ( V_2 -> V_22 , V_23 ) ;
F_34 ( V_74 , V_36 , V_2 , V_16 ) ;
}
}
}
else{
F_7 ( V_2 -> V_22 , V_24 , L_18 ) ;
if ( V_45 == 1 ) {
V_46 = 1 ;
V_11 = F_5 ( V_1 , V_9 ) ;
if ( ( V_11 & 0x80 ) != 0 ) {
V_46 = V_11 & 0x7f ;
F_10 ( V_6 , V_61 ,
V_1 , V_9 , 1 , V_59 ) ;
V_9 ++ ;
}
F_18 ( V_1 , V_43 , V_9 , V_46 ) ;
F_19 ( V_6 , V_62 ,
V_1 , V_9 , V_46 , V_43 ) ;
V_9 = V_9 + V_46 ;
}
V_46 = F_4 ( V_1 , V_9 ) >> 4 ;
V_57 = F_5 ( V_1 , V_9 + 1 ) & 0x0f ;
if ( ( V_46 == 0 ) && ( V_57 == 1 ) ) {
T_5 * V_75 ;
T_6 V_76 ;
V_9 ++ ;
F_10 ( V_6 , V_77 , V_1 , V_9 , 1 , V_59 ) ;
V_9 ++ ;
V_11 = F_5 ( V_1 , V_9 ) ;
V_75 = F_10 ( V_6 , V_78 , V_1 , V_9 , 1 , V_59 ) ;
V_9 ++ ;
V_76 = F_5 ( V_1 , V_9 ) ;
F_10 ( V_6 , V_79 , V_1 , V_9 , 1 , V_59 ) ;
V_9 ++ ;
F_35 ( V_2 , V_75 , & V_80 ,
L_19 ,
F_36 ( V_11 , & V_81 , L_20 ) ,
F_36 ( V_76 , & V_82 , L_20 ) ) ;
F_10 ( V_6 , V_83 , V_1 , V_9 , 2 , V_59 ) ;
V_9 = V_9 + 2 ;
F_10 ( V_6 , V_84 , V_1 , V_9 , 20 , V_27 ) ;
V_9 = V_9 + 20 ;
F_37 ( V_2 -> V_22 , V_24 , L_21 ,
F_36 ( V_11 , & V_81 , L_20 ) ,
F_36 ( V_76 , & V_82 , L_20 ) ) ;
switch ( V_11 ) {
case V_85 :
case V_86 :
case V_87 :
F_10 ( V_6 , V_88 , V_1 , V_9 , - 1 , V_27 ) ;
break;
case V_89 :
F_10 ( V_6 , V_90 , V_1 , V_9 , 1 , V_59 ) ;
break;
case V_91 :
F_10 ( V_6 , V_92 , V_1 , V_9 , 2 , V_59 ) ;
break;
default:
break;
}
} else{
V_11 = F_5 ( V_1 , ( V_9 + 1 ) ) ;
V_48 = ( V_11 & 0x0f ) ;
if ( V_48 != 0 )
V_48 = 64 + ( V_48 * 64 ) ;
F_10 ( V_6 , V_93 , V_1 , V_9 , 2 , V_59 ) ;
F_10 ( V_6 , V_94 , V_1 , ( V_9 + 1 ) , 1 , V_59 ) ;
V_9 = V_9 + 2 ;
V_47 = V_46 ;
V_41 = V_9 ;
V_37 = F_10 ( V_6 , V_95 , V_1 ,
V_41 , V_47 , V_27 ) ;
F_38 ( V_37 ,
L_22 , V_47 , V_47 ) ;
V_39 = F_11 ( V_37 , V_96 ) ;
V_33 = F_25 ( V_1 , V_9 , V_46 , V_46 ) ;
if ( V_97 )
F_39 ( V_33 , V_39 , V_48 ) ;
V_9 = V_9 + V_46 ;
V_49 = F_22 ( V_1 , V_9 ) ;
if ( V_49 > 0 ) {
T_5 * V_5 = F_13 ( V_6 , V_1 , V_9 , - 1 ,
L_23 ,
F_22 ( V_1 , V_9 ) ) ;
F_24 ( V_5 ) ;
}
if ( V_65 ) {
V_34 = F_25 ( V_1 , V_9 , V_49 , V_49 ) ;
V_38 = F_10 ( V_6 , V_69 ,
V_1 , V_41 , V_47 ,
V_27 ) ;
V_40 = F_11 ( V_38 , V_70 ) ;
V_36 = F_30 ( V_33 , V_34 , V_2 ,
V_40 , V_48 ,
V_30 , V_63 ,
V_9 , 0 , 0 , V_48 ) ;
if ( V_36 ) {
T_5 * V_5 ;
T_13 V_71 =
( T_13 ) ( ( ( float ) F_29 ( V_36 ) / ( float ) F_29 ( V_1 ) ) * 100 ) ;
F_13 ( V_6 , V_36 , 0 , - 1 , L_16 ) ;
V_5 = F_23 ( V_6 , V_72 , V_36 ,
0 , 0 , V_71 ) ;
F_24 ( V_5 ) ;
if ( V_73 )
F_31 ( V_36 , V_16 ) ;
F_32 ( V_2 -> V_22 , V_23 , L_17 ) ;
F_33 ( V_2 -> V_22 , V_23 ) ;
F_34 ( V_74 , V_36 , V_2 , V_16 ) ;
}
}
}
}
return F_29 ( V_1 ) ;
}
static void
F_39 ( T_1 * V_33 , T_3 * V_39 , T_11 V_98 )
{
T_11 V_99 ;
T_9 V_9 = 0 ;
T_9 V_100 = 0 ;
T_9 V_46 ;
T_9 V_14 ;
T_11 V_101 = 0 ;
T_7 V_102 = 0 ;
T_5 * V_103 , * V_104 ;
T_11 V_105 = V_98 ;
T_8 V_106 ;
T_7 V_107 = F_22 ( V_33 , V_9 ) ;
while ( V_107 > V_9 ) {
V_99 = F_5 ( V_33 , V_9 ) ;
V_101 ++ ;
V_105 = V_98 + V_9 ;
;
V_103 = F_13 ( V_39 , V_33 , V_9 , 1 ,
L_24 ,
V_101 , V_105 , V_105 ) ;
F_24 ( V_103 ) ;
F_10 ( V_39 , V_108 , V_33 , V_9 , 1 , V_59 ) ;
V_9 ++ ;
switch ( V_99 ) {
case V_109 :
V_9 = F_40 ( V_33 , V_39 , V_9 , & V_100 , & V_102 ) ;
V_46 = V_9 - V_100 ;
F_23 ( V_39 , V_110 ,
V_33 , V_100 , V_46 , V_102 ) ;
V_9 = F_41 ( V_33 , V_39 , V_9 , FALSE , & V_100 , & V_102 , & V_106 ) ;
V_46 = V_9 - V_100 ;
if ( V_106 ) {
F_23 ( V_39 , V_111 ,
V_33 , V_100 , V_46 , V_102 ) ;
} else{
F_23 ( V_39 , V_112 ,
V_33 , V_100 , V_46 , V_102 ) ;
}
break;
case V_113 :
V_9 = F_40 ( V_33 , V_39 , V_9 , & V_100 , & V_102 ) ;
V_46 = V_9 - V_100 ;
F_23 ( V_39 , V_110 ,
V_33 , V_100 , V_46 , V_102 ) ;
V_9 = F_41 ( V_33 , V_39 , V_9 , FALSE , & V_100 , & V_102 , & V_106 ) ;
V_46 = V_9 - V_100 ;
if ( V_106 ) {
F_23 ( V_39 , V_111 ,
V_33 , V_100 , V_46 , V_102 ) ;
} else{
F_23 ( V_39 , V_112 ,
V_33 , V_100 , V_46 , V_102 ) ;
}
break;
case V_114 :
V_9 = F_40 ( V_33 , V_39 , V_9 , & V_100 , & V_102 ) ;
V_46 = V_9 - V_100 ;
F_23 ( V_39 , V_110 ,
V_33 , V_100 , V_46 , V_102 ) ;
break;
case V_115 :
V_9 = F_40 ( V_33 , V_39 , V_9 , & V_100 , & V_102 ) ;
V_46 = V_9 - V_100 ;
F_23 ( V_39 , V_110 ,
V_33 , V_100 , V_46 , V_102 ) ;
V_9 = F_41 ( V_33 , V_39 , V_9 , FALSE , & V_100 , & V_102 , & V_106 ) ;
V_46 = V_9 - V_100 ;
if ( V_106 ) {
F_23 ( V_39 , V_111 ,
V_33 , V_100 , V_46 , V_102 ) ;
} else{
F_23 ( V_39 , V_112 ,
V_33 , V_100 , V_46 , V_102 ) ;
}
break;
case V_116 :
V_9 = F_40 ( V_33 , V_39 , V_9 , & V_100 , & V_102 ) ;
V_46 = V_9 - V_100 ;
F_23 ( V_39 , V_110 ,
V_33 , V_100 , V_46 , V_102 ) ;
V_9 = F_41 ( V_33 , V_39 , V_9 , FALSE , & V_100 , & V_102 , & V_106 ) ;
V_46 = V_9 - V_100 ;
if ( V_106 ) {
F_23 ( V_39 , V_111 ,
V_33 , V_100 , V_46 , V_102 ) ;
} else{
F_23 ( V_39 , V_112 ,
V_33 , V_100 , V_46 , V_102 ) ;
}
break;
case V_117 :
V_9 = F_40 ( V_33 , V_39 , V_9 , & V_100 , & V_102 ) ;
V_46 = V_9 - V_100 ;
F_23 ( V_39 , V_110 ,
V_33 , V_100 , V_46 , V_102 ) ;
V_9 = F_41 ( V_33 , V_39 , V_9 , FALSE , & V_100 , & V_102 , & V_106 ) ;
V_46 = V_9 - V_100 ;
if ( V_106 ) {
F_23 ( V_39 , V_111 ,
V_33 , V_100 , V_46 , V_102 ) ;
} else{
F_23 ( V_39 , V_112 ,
V_33 , V_100 , V_46 , V_102 ) ;
}
break;
case V_118 :
V_9 = F_40 ( V_33 , V_39 , V_9 , & V_100 , & V_102 ) ;
V_46 = V_9 - V_100 ;
F_23 ( V_39 , V_110 ,
V_33 , V_100 , V_46 , V_102 ) ;
V_9 = F_41 ( V_33 , V_39 , V_9 , FALSE , & V_100 , & V_102 , & V_106 ) ;
V_46 = V_9 - V_100 ;
if ( V_106 ) {
F_23 ( V_39 , V_111 ,
V_33 , V_100 , V_46 , V_102 ) ;
} else{
F_23 ( V_39 , V_112 ,
V_33 , V_100 , V_46 , V_102 ) ;
}
break;
case V_119 :
V_9 = F_40 ( V_33 , V_39 , V_9 , & V_100 , & V_102 ) ;
V_46 = V_9 - V_100 ;
F_23 ( V_39 , V_110 ,
V_33 , V_100 , V_46 , V_102 ) ;
V_9 = F_41 ( V_33 , V_39 , V_9 , FALSE , & V_100 , & V_102 , & V_106 ) ;
V_46 = V_9 - V_100 ;
if ( V_106 ) {
F_23 ( V_39 , V_111 ,
V_33 , V_100 , V_46 , V_102 ) ;
} else{
F_23 ( V_39 , V_112 ,
V_33 , V_100 , V_46 , V_102 ) ;
}
break;
case V_120 :
V_9 = F_40 ( V_33 , V_39 , V_9 , & V_100 , & V_102 ) ;
V_46 = V_9 - V_100 ;
F_23 ( V_39 , V_110 ,
V_33 , V_100 , V_46 , V_102 ) ;
V_9 = F_41 ( V_33 , V_39 , V_9 , FALSE , & V_100 , & V_102 , & V_106 ) ;
V_46 = V_9 - V_100 ;
if ( V_106 ) {
F_23 ( V_39 , V_111 ,
V_33 , V_100 , V_46 , V_102 ) ;
} else{
F_23 ( V_39 , V_112 ,
V_33 , V_100 , V_46 , V_102 ) ;
}
break;
case V_121 :
V_9 = F_40 ( V_33 , V_39 , V_9 , & V_100 , & V_102 ) ;
V_46 = V_9 - V_100 ;
F_23 ( V_39 , V_110 ,
V_33 , V_100 , V_46 , V_102 ) ;
V_9 = F_41 ( V_33 , V_39 , V_9 , FALSE , & V_100 , & V_102 , & V_106 ) ;
V_46 = V_9 - V_100 ;
if ( V_106 ) {
F_23 ( V_39 , V_111 ,
V_33 , V_100 , V_46 , V_102 ) ;
} else{
F_23 ( V_39 , V_112 ,
V_33 , V_100 , V_46 , V_102 ) ;
}
break;
case V_122 :
V_9 = V_9 + F_22 ( V_33 , V_9 ) ;
break;
case V_123 :
V_9 = V_9 + F_22 ( V_33 , V_9 ) ;
break;
case V_124 :
V_9 = F_41 ( V_33 , V_39 , V_9 , FALSE , & V_100 , & V_102 , & V_106 ) ;
V_46 = V_9 - V_100 ;
F_23 ( V_39 , V_125 ,
V_33 , V_100 , V_46 , V_102 ) ;
V_9 = F_41 ( V_33 , V_39 , V_9 , FALSE , & V_100 , & V_102 , & V_106 ) ;
V_46 = V_9 - V_100 ;
if ( V_106 ) {
F_23 ( V_39 , V_126 ,
V_33 , V_100 , V_46 , V_102 ) ;
} else{
F_23 ( V_39 , V_127 ,
V_33 , V_100 , V_46 , V_102 ) ;
}
V_9 = F_40 ( V_33 , V_39 , V_9 , & V_100 , & V_102 ) ;
V_46 = V_9 - V_100 ;
F_23 ( V_39 , V_128 ,
V_33 , V_100 , V_46 , V_102 ) ;
break;
case V_129 :
V_9 = F_41 ( V_33 , V_39 , V_9 , TRUE , & V_100 , & V_102 , & V_106 ) ;
V_46 = V_9 - V_100 ;
F_23 ( V_39 , V_130 ,
V_33 , V_100 , V_46 , V_102 ) ;
V_9 = F_41 ( V_33 , V_39 , V_9 , FALSE , & V_100 , & V_102 , & V_106 ) ;
V_46 = V_9 - V_100 ;
if ( V_106 ) {
F_23 ( V_39 , V_131 ,
V_33 , V_100 , V_46 , V_102 ) ;
} else{
F_23 ( V_39 , V_132 ,
V_33 , V_100 , V_46 , V_102 ) ;
}
break;
case V_133 :
V_9 = F_41 ( V_33 , V_39 , V_9 , TRUE , & V_100 , & V_102 , & V_106 ) ;
V_46 = V_9 - V_100 ;
F_23 ( V_39 , V_130 ,
V_33 , V_100 , V_46 , V_102 ) ;
V_9 = F_42 ( V_33 , V_39 , V_9 , & V_100 , & V_102 ) ;
V_46 = V_9 - V_100 ;
F_23 ( V_39 , V_134 ,
V_33 , V_100 , V_46 , V_102 ) ;
V_14 = V_102 ;
while ( V_14 > 0 ) {
V_14 = V_14 - 1 ;
V_9 = F_41 ( V_33 , V_39 , V_9 , FALSE , & V_100 , & V_102 , & V_106 ) ;
V_46 = V_9 - V_100 ;
if ( V_106 ) {
F_23 ( V_39 , V_131 ,
V_33 , V_100 , V_46 , V_102 ) ;
} else{
F_23 ( V_39 , V_132 ,
V_33 , V_100 , V_46 , V_102 ) ;
}
}
break;
case V_135 :
V_9 = F_41 ( V_33 , V_39 , V_9 , FALSE , & V_100 , & V_102 , & V_106 ) ;
V_46 = V_9 - V_100 ;
if ( V_106 ) {
F_23 ( V_39 , V_131 ,
V_33 , V_100 , V_46 , V_102 ) ;
} else{
F_23 ( V_39 , V_132 ,
V_33 , V_100 , V_46 , V_102 ) ;
}
break;
case V_136 :
V_9 = F_41 ( V_33 , V_39 , V_9 , TRUE , & V_100 , & V_102 , & V_106 ) ;
V_46 = V_9 - V_100 ;
F_23 ( V_39 , V_130 ,
V_33 , V_100 , V_46 , V_102 ) ;
break;
case V_137 :
V_9 = F_41 ( V_33 , V_39 , V_9 , FALSE , & V_100 , & V_102 , & V_106 ) ;
V_46 = V_9 - V_100 ;
F_23 ( V_39 , V_125 ,
V_33 , V_100 , V_46 , V_102 ) ;
V_9 = F_41 ( V_33 , V_39 , V_9 , FALSE , & V_100 , & V_102 , & V_106 ) ;
V_46 = V_9 - V_100 ;
if ( V_106 ) {
F_23 ( V_39 , V_126 ,
V_33 , V_100 , V_46 , V_102 ) ;
} else{
F_23 ( V_39 , V_127 ,
V_33 , V_100 , V_46 , V_102 ) ;
}
V_9 = F_40 ( V_33 , V_39 , V_9 , & V_100 , & V_102 ) ;
V_46 = V_9 - V_100 ;
F_23 ( V_39 , V_128 ,
V_33 , V_100 , V_46 , V_102 ) ;
break;
case V_138 :
V_9 = F_41 ( V_33 , V_39 , V_9 , FALSE , & V_100 , & V_102 , & V_106 ) ;
V_46 = V_9 - V_100 ;
F_23 ( V_39 , V_125 ,
V_33 , V_100 , V_46 , V_102 ) ;
V_9 = F_41 ( V_33 , V_39 , V_9 , FALSE , & V_100 , & V_102 , & V_106 ) ;
V_46 = V_9 - V_100 ;
if ( V_106 ) {
F_23 ( V_39 , V_126 ,
V_33 , V_100 , V_46 , V_102 ) ;
} else{
F_23 ( V_39 , V_127 ,
V_33 , V_100 , V_46 , V_102 ) ;
}
V_9 = F_40 ( V_33 , V_39 , V_9 , & V_100 , & V_102 ) ;
V_46 = V_9 - V_100 ;
F_23 ( V_39 , V_128 ,
V_33 , V_100 , V_46 , V_102 ) ;
break;
case V_139 :
V_9 = F_41 ( V_33 , V_39 , V_9 , FALSE , & V_100 , & V_102 , & V_106 ) ;
V_46 = V_9 - V_100 ;
if ( V_106 ) {
F_23 ( V_39 , V_140 ,
V_33 , V_100 , V_46 , V_102 ) ;
} else{
F_23 ( V_39 , V_141 ,
V_33 , V_100 , V_46 , V_102 ) ;
}
V_9 = F_41 ( V_33 , V_39 , V_9 , FALSE , & V_100 , & V_102 , & V_106 ) ;
V_46 = V_9 - V_100 ;
if ( V_106 ) {
F_23 ( V_39 , V_126 ,
V_33 , V_100 , V_46 , V_102 ) ;
} else{
F_23 ( V_39 , V_127 ,
V_33 , V_100 , V_46 , V_102 ) ;
}
V_9 = F_40 ( V_33 , V_39 , V_9 , & V_100 , & V_102 ) ;
V_46 = V_9 - V_100 ;
F_23 ( V_39 , V_128 ,
V_33 , V_100 , V_46 , V_102 ) ;
break;
case V_142 :
V_9 = F_41 ( V_33 , V_39 , V_9 , TRUE , & V_100 , & V_102 , & V_106 ) ;
V_46 = V_9 - V_100 ;
F_23 ( V_39 , V_130 ,
V_33 , V_100 , V_46 , V_102 ) ;
V_9 = F_41 ( V_33 , V_39 , V_9 , FALSE , & V_100 , & V_102 , & V_106 ) ;
V_46 = V_9 - V_100 ;
if ( V_106 ) {
F_23 ( V_39 , V_126 ,
V_33 , V_100 , V_46 , V_102 ) ;
} else{
F_23 ( V_39 , V_127 ,
V_33 , V_100 , V_46 , V_102 ) ;
}
V_9 = F_41 ( V_33 , V_39 , V_9 , FALSE , & V_100 , & V_102 , & V_106 ) ;
V_46 = V_9 - V_100 ;
F_23 ( V_39 , V_143 ,
V_33 , V_100 , V_46 , V_102 ) ;
V_9 = F_41 ( V_33 , V_39 , V_9 , FALSE , & V_100 , & V_102 , & V_106 ) ;
V_46 = V_9 - V_100 ;
F_23 ( V_39 , V_141 ,
V_33 , V_100 , V_46 , V_102 ) ;
break;
case V_144 :
V_9 = F_41 ( V_33 , V_39 , V_9 , TRUE , & V_100 , & V_102 , & V_106 ) ;
V_46 = V_9 - V_100 ;
V_102 = ( V_102 + V_105 ) & 0xffff ;
F_23 ( V_39 , V_145 ,
V_33 , V_100 , V_46 , V_102 ) ;
break;
case V_146 :
V_9 = F_41 ( V_33 , V_39 , V_9 , FALSE , & V_100 , & V_102 , & V_106 ) ;
V_46 = V_9 - V_100 ;
if ( V_106 ) {
F_23 ( V_39 , V_131 ,
V_33 , V_100 , V_46 , V_102 ) ;
} else{
F_23 ( V_39 , V_132 ,
V_33 , V_100 , V_46 , V_102 ) ;
}
V_9 = F_41 ( V_33 , V_39 , V_9 , FALSE , & V_100 , & V_102 , & V_106 ) ;
V_46 = V_9 - V_100 ;
if ( V_106 ) {
F_23 ( V_39 , V_131 ,
V_33 , V_100 , V_46 , V_102 ) ;
} else{
F_23 ( V_39 , V_132 ,
V_33 , V_100 , V_46 , V_102 ) ;
}
V_9 = F_41 ( V_33 , V_39 , V_9 , TRUE , & V_100 , & V_102 , & V_106 ) ;
V_46 = V_9 - V_100 ;
V_102 = ( V_102 + V_105 ) & 0xffff ;
F_23 ( V_39 , V_145 ,
V_33 , V_100 , V_46 , V_102 ) ;
V_9 = F_41 ( V_33 , V_39 , V_9 , TRUE , & V_100 , & V_102 , & V_106 ) ;
V_46 = V_9 - V_100 ;
V_102 = ( V_102 + V_105 ) & 0xffff ;
F_23 ( V_39 , V_145 ,
V_33 , V_100 , V_46 , V_102 ) ;
V_9 = F_41 ( V_33 , V_39 , V_9 , TRUE , & V_100 , & V_102 , & V_106 ) ;
V_46 = V_9 - V_100 ;
V_102 = ( V_102 + V_105 ) & 0xffff ;
F_23 ( V_39 , V_145 ,
V_33 , V_100 , V_46 , V_102 ) ;
break;
case V_147 :
V_9 = F_41 ( V_33 , V_39 , V_9 , TRUE , & V_100 , & V_102 , & V_106 ) ;
V_46 = V_9 - V_100 ;
V_102 = ( V_102 + V_105 ) & 0xffff ;
F_23 ( V_39 , V_145 ,
V_33 , V_100 , V_46 , V_102 ) ;
break;
case V_148 :
break;
case V_149 :
V_9 = F_42 ( V_33 , V_39 , V_9 , & V_100 , & V_102 ) ;
V_46 = V_9 - V_100 ;
F_23 ( V_39 , V_134 ,
V_33 , V_100 , V_46 , V_102 ) ;
V_14 = V_102 ;
V_9 = F_41 ( V_33 , V_39 , V_9 , FALSE , & V_100 , & V_102 , & V_106 ) ;
V_46 = V_9 - V_100 ;
if ( V_106 ) {
F_23 ( V_39 , V_150 ,
V_33 , V_100 , V_46 , V_102 ) ;
} else{
F_23 ( V_39 , V_151 ,
V_33 , V_100 , V_46 , V_102 ) ;
}
while ( V_14 > 0 ) {
V_14 = V_14 - 1 ;
V_9 = F_41 ( V_33 , V_39 , V_9 , TRUE , & V_100 , & V_102 , & V_106 ) ;
V_46 = V_9 - V_100 ;
V_102 = ( V_102 + V_105 ) & 0xffff ;
F_23 ( V_39 , V_145 ,
V_33 , V_100 , V_46 , V_102 ) ;
}
break;
case V_152 :
V_9 = F_41 ( V_33 , V_39 , V_9 , FALSE , & V_100 , & V_102 , & V_106 ) ;
V_46 = V_9 - V_100 ;
if ( V_106 ) {
F_23 ( V_39 , V_131 ,
V_33 , V_100 , V_46 , V_102 ) ;
} else{
F_23 ( V_39 , V_132 ,
V_33 , V_100 , V_46 , V_102 ) ;
}
V_9 = F_41 ( V_33 , V_39 , V_9 , FALSE , & V_100 , & V_102 , & V_106 ) ;
V_46 = V_9 - V_100 ;
F_23 ( V_39 , V_125 ,
V_33 , V_100 , V_46 , V_102 ) ;
V_9 = F_41 ( V_33 , V_39 , V_9 , FALSE , & V_100 , & V_102 , & V_106 ) ;
V_46 = V_9 - V_100 ;
if ( V_106 ) {
F_23 ( V_39 , V_126 ,
V_33 , V_100 , V_46 , V_102 ) ;
} else{
F_23 ( V_39 , V_127 ,
V_33 , V_100 , V_46 , V_102 ) ;
}
V_9 = F_41 ( V_33 , V_39 , V_9 , TRUE , & V_100 , & V_102 , & V_106 ) ;
V_46 = V_9 - V_100 ;
V_102 = ( V_102 + V_105 ) & 0xffff ;
F_23 ( V_39 , V_145 ,
V_33 , V_100 , V_46 , V_102 ) ;
break;
case V_153 :
V_9 = F_41 ( V_33 , V_39 , V_9 , FALSE , & V_100 , & V_102 , & V_106 ) ;
V_46 = V_9 - V_100 ;
if ( V_106 ) {
F_23 ( V_39 , V_126 ,
V_33 , V_100 , V_46 , V_102 ) ;
} else{
F_23 ( V_39 , V_127 ,
V_33 , V_100 , V_46 , V_102 ) ;
}
V_9 = F_41 ( V_33 , V_39 , V_9 , FALSE , & V_100 , & V_102 , & V_106 ) ;
V_46 = V_9 - V_100 ;
if ( V_106 ) {
F_23 ( V_39 , V_154 ,
V_33 , V_100 , V_46 , V_102 ) ;
} else{
F_23 ( V_39 , V_155 ,
V_33 , V_100 , V_46 , V_102 ) ;
}
V_9 = F_41 ( V_33 , V_39 , V_9 , TRUE , & V_100 , & V_102 , & V_106 ) ;
V_46 = V_9 - V_100 ;
V_102 = ( V_102 + V_105 ) & 0xffff ;
F_23 ( V_39 , V_145 ,
V_33 , V_100 , V_46 , V_102 ) ;
break;
case V_156 :
V_9 = F_41 ( V_33 , V_39 , V_9 , FALSE , & V_100 , & V_102 , & V_106 ) ;
V_46 = V_9 - V_100 ;
if ( V_106 ) {
F_23 ( V_39 , V_126 ,
V_33 , V_100 , V_46 , V_102 ) ;
} else{
F_23 ( V_39 , V_127 ,
V_33 , V_100 , V_46 , V_102 ) ;
}
V_9 = F_41 ( V_33 , V_39 , V_9 , FALSE , & V_100 , & V_102 , & V_106 ) ;
V_46 = V_9 - V_100 ;
if ( V_106 ) {
F_23 ( V_39 , V_154 ,
V_33 , V_100 , V_46 , V_102 ) ;
} else{
F_23 ( V_39 , V_155 ,
V_33 , V_100 , V_46 , V_102 ) ;
}
V_9 = F_41 ( V_33 , V_39 , V_9 , TRUE , & V_100 , & V_102 , & V_106 ) ;
V_46 = V_9 - V_100 ;
V_102 = ( V_102 + V_105 ) & 0xffff ;
F_23 ( V_39 , V_145 ,
V_33 , V_100 , V_46 , V_102 ) ;
break;
case V_157 :
V_9 = F_41 ( V_33 , V_39 , V_9 , FALSE , & V_100 , & V_102 , & V_106 ) ;
V_46 = V_9 - V_100 ;
if ( V_106 ) {
F_23 ( V_39 , V_154 ,
V_33 , V_100 , V_46 , V_102 ) ;
} else{
F_23 ( V_39 , V_155 ,
V_33 , V_100 , V_46 , V_102 ) ;
}
V_9 = F_41 ( V_33 , V_39 , V_9 , TRUE , & V_100 , & V_102 , & V_106 ) ;
V_46 = V_9 - V_100 ;
V_102 = ( V_102 + V_105 ) & 0xffff ;
F_23 ( V_39 , V_145 ,
V_33 , V_100 , V_46 , V_102 ) ;
V_9 = F_42 ( V_33 , V_39 , V_9 , & V_100 , & V_102 ) ;
V_46 = V_9 - V_100 ;
F_23 ( V_39 , V_134 ,
V_33 , V_100 , V_46 , V_102 ) ;
V_14 = V_102 ;
while ( V_14 > 0 ) {
V_14 = V_14 - 1 ;
V_9 = F_41 ( V_33 , V_39 , V_9 , FALSE , & V_100 , & V_102 , & V_106 ) ;
V_46 = V_9 - V_100 ;
F_23 ( V_39 , V_158 ,
V_33 , V_100 , V_46 , V_102 ) ;
V_9 = F_41 ( V_33 , V_39 , V_9 , FALSE , & V_100 , & V_102 , & V_106 ) ;
V_46 = V_9 - V_100 ;
F_23 ( V_39 , V_159 ,
V_33 , V_100 , V_46 , V_102 ) ;
V_9 = F_41 ( V_33 , V_39 , V_9 , FALSE , & V_100 , & V_102 , & V_106 ) ;
V_46 = V_9 - V_100 ;
F_23 ( V_39 , V_160 ,
V_33 , V_100 , V_46 , V_102 ) ;
V_9 = F_41 ( V_33 , V_39 , V_9 , FALSE , & V_100 , & V_102 , & V_106 ) ;
V_46 = V_9 - V_100 ;
F_23 ( V_39 , V_161 ,
V_33 , V_100 , V_46 , V_102 ) ;
}
break;
case V_162 :
V_9 = F_41 ( V_33 , V_39 , V_9 , TRUE , & V_100 , & V_102 , & V_106 ) ;
V_46 = V_9 - V_100 ;
F_23 ( V_39 , V_163 ,
V_33 , V_100 , V_46 , V_102 ) ;
V_9 = F_41 ( V_33 , V_39 , V_9 , TRUE , & V_100 , & V_102 , & V_106 ) ;
V_46 = V_9 - V_100 ;
F_23 ( V_39 , V_164 ,
V_33 , V_100 , V_46 , V_102 ) ;
V_9 = F_41 ( V_33 , V_39 , V_9 , TRUE , & V_100 , & V_102 , & V_106 ) ;
V_46 = V_9 - V_100 ;
F_23 ( V_39 , V_165 ,
V_33 , V_100 , V_46 , V_102 ) ;
V_9 = F_41 ( V_33 , V_39 , V_9 , TRUE , & V_100 , & V_102 , & V_106 ) ;
V_46 = V_9 - V_100 ;
if ( V_106 ) {
F_23 ( V_39 , V_166 ,
V_33 , V_100 , V_46 , V_102 ) ;
} else{
F_23 ( V_39 , V_167 ,
V_33 , V_100 , V_46 , V_102 ) ;
}
V_9 = F_41 ( V_33 , V_39 , V_9 , TRUE , & V_100 , & V_102 , & V_106 ) ;
V_46 = V_9 - V_100 ;
if ( V_106 ) {
F_23 ( V_39 , V_168 ,
V_33 , V_100 , V_46 , V_102 ) ;
} else{
F_23 ( V_39 , V_169 ,
V_33 , V_100 , V_46 , V_102 ) ;
}
V_9 = F_41 ( V_33 , V_39 , V_9 , TRUE , & V_100 , & V_102 , & V_106 ) ;
V_46 = V_9 - V_100 ;
F_23 ( V_39 , V_170 ,
V_33 , V_100 , V_46 , V_102 ) ;
break;
case V_171 :
V_9 = F_41 ( V_33 , V_39 , V_9 , TRUE , & V_100 , & V_102 , & V_106 ) ;
V_46 = V_9 - V_100 ;
if ( V_106 ) {
F_23 ( V_39 , V_166 ,
V_33 , V_100 , V_46 , V_102 ) ;
} else{
F_23 ( V_39 , V_167 ,
V_33 , V_100 , V_46 , V_102 ) ;
}
V_9 = F_41 ( V_33 , V_39 , V_9 , TRUE , & V_100 , & V_102 , & V_106 ) ;
V_46 = V_9 - V_100 ;
if ( V_106 ) {
F_23 ( V_39 , V_168 ,
V_33 , V_100 , V_46 , V_102 ) ;
} else{
F_23 ( V_39 , V_169 ,
V_33 , V_100 , V_46 , V_102 ) ;
}
V_9 = F_41 ( V_33 , V_39 , V_9 , TRUE , & V_100 , & V_102 , & V_106 ) ;
V_46 = V_9 - V_100 ;
F_23 ( V_39 , V_170 ,
V_33 , V_100 , V_46 , V_102 ) ;
V_9 = F_41 ( V_33 , V_39 , V_9 , TRUE , & V_100 , & V_102 , & V_106 ) ;
V_46 = V_9 - V_100 ;
F_23 ( V_39 , V_172 ,
V_33 , V_100 , V_46 , V_102 ) ;
V_9 = F_41 ( V_33 , V_39 , V_9 , TRUE , & V_100 , & V_102 , & V_106 ) ;
V_46 = V_9 - V_100 ;
F_23 ( V_39 , V_173 ,
V_33 , V_100 , V_46 , V_102 ) ;
break;
case V_174 :
V_9 = F_41 ( V_33 , V_39 , V_9 , TRUE , & V_100 , & V_102 , & V_106 ) ;
V_46 = V_9 - V_100 ;
F_23 ( V_39 , V_163 ,
V_33 , V_100 , V_46 , V_102 ) ;
V_9 = F_41 ( V_33 , V_39 , V_9 , TRUE , & V_100 , & V_102 , & V_106 ) ;
V_46 = V_9 - V_100 ;
F_23 ( V_39 , V_164 ,
V_33 , V_100 , V_46 , V_102 ) ;
break;
case V_175 :
V_9 = F_41 ( V_33 , V_39 , V_9 , TRUE , & V_100 , & V_102 , & V_106 ) ;
V_46 = V_9 - V_100 ;
if ( V_106 ) {
F_23 ( V_39 , V_176 ,
V_33 , V_100 , V_46 , V_102 ) ;
} else{
F_23 ( V_39 , V_177 ,
V_33 , V_100 , V_46 , V_102 ) ;
}
V_9 = F_41 ( V_33 , V_39 , V_9 , TRUE , & V_100 , & V_102 , & V_106 ) ;
V_46 = V_9 - V_100 ;
if ( V_106 ) {
F_23 ( V_39 , V_178 ,
V_33 , V_100 , V_46 , V_102 ) ;
} else{
F_23 ( V_39 , V_179 ,
V_33 , V_100 , V_46 , V_102 ) ;
}
break;
case V_180 :
if ( ( V_107 - 1 ) < V_9 ) {
V_104 = F_13 ( V_39 , V_33 , 0 , - 1 ,
L_25 ) ;
F_24 ( V_104 ) ;
return;
}
V_9 = F_41 ( V_33 , V_39 , V_9 , TRUE , & V_100 , & V_102 , & V_106 ) ;
V_46 = V_9 - V_100 ;
F_23 ( V_39 , V_181 ,
V_33 , V_100 , V_46 , V_102 ) ;
if ( ( V_107 - 1 ) < V_9 ) {
V_104 = F_13 ( V_39 , V_33 , V_9 - 1 , - 1 ,
L_25 ) ;
F_24 ( V_104 ) ;
return;
}
V_9 = F_41 ( V_33 , V_39 , V_9 , TRUE , & V_100 , & V_102 , & V_106 ) ;
V_46 = V_9 - V_100 ;
F_23 ( V_39 , V_182 ,
V_33 , V_100 , V_46 , V_102 ) ;
V_9 = F_41 ( V_33 , V_39 , V_9 , TRUE , & V_100 , & V_102 , & V_106 ) ;
V_46 = V_9 - V_100 ;
if ( V_106 ) {
F_23 ( V_39 , V_166 ,
V_33 , V_100 , V_46 , V_102 ) ;
} else{
F_23 ( V_39 , V_167 ,
V_33 , V_100 , V_46 , V_102 ) ;
}
V_9 = F_41 ( V_33 , V_39 , V_9 , TRUE , & V_100 , & V_102 , & V_106 ) ;
V_46 = V_9 - V_100 ;
if ( V_106 ) {
F_23 ( V_39 , V_168 ,
V_33 , V_100 , V_46 , V_102 ) ;
} else{
F_23 ( V_39 , V_169 ,
V_33 , V_100 , V_46 , V_102 ) ;
}
V_9 = F_41 ( V_33 , V_39 , V_9 , TRUE , & V_100 , & V_102 , & V_106 ) ;
V_46 = V_9 - V_100 ;
F_23 ( V_39 , V_170 ,
V_33 , V_100 , V_46 , V_102 ) ;
V_9 = F_41 ( V_33 , V_39 , V_9 , TRUE , & V_100 , & V_102 , & V_106 ) ;
V_46 = V_9 - V_100 ;
F_23 ( V_39 , V_172 ,
V_33 , V_100 , V_46 , V_102 ) ;
if ( F_22 ( V_33 , V_9 ) != 0 ) {
V_9 = F_41 ( V_33 , V_39 , V_9 , TRUE , & V_100 , & V_102 , & V_106 ) ;
V_46 = V_9 - V_100 ;
F_23 ( V_39 , V_173 ,
V_33 , V_100 , V_46 , V_102 ) ;
} else{
V_104 = F_13 ( V_39 , V_33 , V_9 , 1 ,
L_26 ) ;
F_24 ( V_104 ) ;
}
if ( F_22 ( V_33 , V_9 ) != 0 ) {
V_46 = F_22 ( V_33 , V_9 ) ;
V_105 = V_98 + V_9 ;
F_13 ( V_39 , V_33 , V_9 , V_46 ,
L_27 , V_46 , V_105 , V_105 ) ;
}
V_9 = V_9 + F_22 ( V_33 , V_9 ) ;
break;
default:
V_9 = V_9 + F_22 ( V_33 , V_9 ) ;
break;
}
}
return;
}
static int
F_42 ( T_1 * V_33 , T_3 * V_39 ,
T_9 V_9 , T_9 * V_100 , T_7 * V_102 )
{
T_11 V_183 ;
T_7 V_184 ;
T_11 V_185 ;
T_11 V_186 ;
V_183 = F_5 ( V_33 , V_9 ) ;
V_185 = V_183 >> 7 ;
if ( V_185 == 1 ) {
V_185 = V_183 >> 6 ;
if ( V_185 == 2 ) {
V_186 = V_183 & 0xc0 ;
if ( V_187 )
F_23 ( V_39 , V_188 ,
V_33 , V_9 , 1 , V_186 ) ;
V_184 = F_4 ( V_33 , V_9 ) & 0x3fff ;
* V_102 = V_184 ;
* V_100 = V_9 ;
V_9 = V_9 + 2 ;
} else{
V_186 = V_183 & 0xc0 ;
if ( V_187 )
F_23 ( V_39 , V_188 ,
V_33 , V_9 , 1 , V_186 ) ;
V_9 ++ ;
V_184 = F_4 ( V_33 , V_9 ) ;
* V_102 = V_184 ;
* V_100 = V_9 ;
V_9 = V_9 + 2 ;
}
} else{
V_186 = V_183 & 0xc0 ;
if ( V_187 )
F_23 ( V_39 , V_188 ,
V_33 , V_9 , 1 , V_186 ) ;
V_184 = ( V_183 & 0x7f ) ;
* V_102 = V_184 ;
* V_100 = V_9 ;
V_9 ++ ;
}
return V_9 ;
}
static int
F_40 ( T_1 * V_33 , T_3 * V_39 ,
T_9 V_9 , T_9 * V_100 , T_7 * V_102 )
{
T_11 V_183 ;
T_7 V_184 ;
T_11 V_185 ;
T_11 V_186 ;
V_183 = F_5 ( V_33 , V_9 ) ;
V_185 = V_183 >> 7 ;
if ( V_185 == 1 ) {
V_185 = V_183 >> 6 ;
if ( V_185 == 2 ) {
V_186 = V_183 & 0xc0 ;
if ( V_187 )
F_23 ( V_39 , V_189 ,
V_33 , V_9 , 1 , V_186 ) ;
V_184 = F_4 ( V_33 , V_9 ) & 0x3fff ;
* V_102 = ( V_184 * 2 ) ;
* V_100 = V_9 ;
V_9 = V_9 + 2 ;
} else{
V_186 = V_183 & 0xc0 ;
if ( V_187 )
F_23 ( V_39 , V_189 ,
V_33 , V_9 , 1 , V_186 ) ;
V_9 ++ ;
V_184 = F_4 ( V_33 , V_9 ) ;
* V_102 = V_184 ;
* V_100 = V_9 ;
V_9 = V_9 + 2 ;
}
} else{
V_186 = V_183 & 0xc0 ;
if ( V_187 )
F_23 ( V_39 , V_189 ,
V_33 , V_9 , 1 , V_186 ) ;
V_184 = ( V_183 & 0x7f ) ;
* V_102 = ( V_184 * 2 ) ;
* V_100 = V_9 ;
V_9 ++ ;
}
return V_9 ;
}
static int
F_41 ( T_1 * V_33 , T_3 * V_39 ,
T_9 V_9 , T_8 T_14 V_4 , T_9 * V_100 , T_7 * V_102 , T_8 * V_106 )
{
T_11 V_183 ;
T_11 V_186 ;
T_7 V_184 ;
T_13 V_190 ;
T_11 V_185 ;
* V_106 = FALSE ;
V_183 = F_5 ( V_33 , V_9 ) ;
V_185 = ( V_183 & 0xc0 ) >> 6 ;
switch ( V_185 ) {
case 0 :
V_186 = V_183 & 0xc0 ;
if ( V_187 )
F_23 ( V_39 , V_191 ,
V_33 , V_9 , 1 , V_186 ) ;
V_184 = ( V_183 & 0x3f ) ;
* V_102 = V_184 ;
* V_100 = V_9 ;
V_9 ++ ;
break;
case 1 :
V_186 = V_183 & 0xc0 ;
if ( V_187 )
F_23 ( V_39 , V_191 ,
V_33 , V_9 , 1 , V_186 ) ;
V_184 = ( V_183 & 0x3f ) * 2 ;
* V_106 = TRUE ;
* V_102 = V_184 ;
* V_100 = V_9 ;
V_9 ++ ;
break;
case 2 :
V_185 = ( V_183 & 0xe0 ) >> 5 ;
if ( V_185 == 5 ) {
V_186 = V_183 & 0xe0 ;
if ( V_187 )
F_23 ( V_39 , V_191 ,
V_33 , V_9 , 1 , V_186 ) ;
V_184 = F_4 ( V_33 , V_9 ) & 0x1fff ;
* V_102 = V_184 ;
* V_100 = V_9 ;
V_9 = V_9 + 2 ;
} else{
V_185 = ( V_183 & 0xf0 ) >> 4 ;
if ( V_185 == 9 ) {
V_186 = V_183 & 0xf0 ;
if ( V_187 )
F_23 ( V_39 , V_191 ,
V_33 , V_9 , 1 , V_186 ) ;
V_184 = ( F_4 ( V_33 , V_9 ) & 0x0fff ) + 61440 ;
* V_100 = V_9 ;
* V_102 = V_184 ;
V_9 = V_9 + 2 ;
} else{
V_185 = ( V_183 & 0x08 ) >> 3 ;
if ( V_185 == 1 ) {
V_186 = V_183 & 0xf8 ;
if ( V_187 )
F_23 ( V_39 , V_191 ,
V_33 , V_9 , 1 , V_186 ) ;
V_190 = ( T_13 ) pow ( 2 , ( V_183 & 0x07 ) + 8 ) ;
V_184 = V_190 & 0xffff ;
* V_100 = V_9 ;
* V_102 = V_184 ;
V_9 ++ ;
} else{
V_185 = ( V_183 & 0x0e ) >> 1 ;
if ( V_185 == 3 ) {
V_186 = V_183 & 0xfe ;
if ( V_187 )
F_23 ( V_39 , V_191 ,
V_33 , V_9 , 1 , V_186 ) ;
V_190 = ( T_13 ) pow ( 2 , ( V_183 & 0x01 ) + 6 ) ;
V_184 = V_190 & 0xffff ;
* V_100 = V_9 ;
* V_102 = V_184 ;
V_9 ++ ;
} else{
V_186 = V_183 ;
if ( V_187 )
F_23 ( V_39 , V_191 ,
V_33 , V_9 , 1 , V_186 ) ;
if ( ( V_183 & 0x01 ) == 1 )
* V_106 = TRUE ;
V_9 ++ ;
V_184 = F_4 ( V_33 , V_9 ) ;
* V_102 = V_184 ;
* V_100 = V_9 ;
V_9 = V_9 + 2 ;
}
}
}
}
break;
case 3 :
V_185 = ( V_183 & 0x20 ) >> 5 ;
if ( V_185 == 1 ) {
V_186 = V_183 & 0xe0 ;
if ( V_187 )
F_23 ( V_39 , V_191 ,
V_33 , V_9 , 1 , V_186 ) ;
V_184 = ( V_183 & 0x1f ) + 65504 ;
* V_100 = V_9 ;
* V_102 = V_184 ;
V_9 ++ ;
} else{
V_186 = V_183 & 0xe0 ;
if ( V_187 )
F_23 ( V_39 , V_191 ,
V_33 , V_9 , 1 , V_186 ) ;
V_184 = ( F_4 ( V_33 , V_9 ) & 0x1fff ) ;
* V_106 = TRUE ;
* V_100 = V_9 ;
* V_102 = V_184 ;
V_9 = V_9 + 2 ;
}
default :
break;
}
return V_9 ;
}
static void
F_31 ( T_1 * V_1 , T_3 * V_3 )
{
T_3 * V_192 = NULL ;
T_5 * V_5 = NULL ;
int V_9 , V_193 , V_194 ;
if( V_3 ) {
V_5 = F_10 ( V_3 , V_195 , V_1 , 0 , - 1 , V_27 ) ;
V_192 = F_11 ( V_5 , V_196 ) ;
}
V_9 = 0 ;
while ( F_43 ( V_1 , V_9 ) ) {
F_44 ( V_1 , V_9 , - 1 , & V_193 , FALSE ) ;
V_194 = V_193 - V_9 ;
F_45 ( V_192 , V_1 , V_9 , V_194 ) ;
V_9 = V_193 ;
}
}
void
F_46 ( void )
{
static T_15 V_197 [] = {
{ & V_58 ,
{ L_28 , L_29 ,
V_198 , V_199 , NULL , 0x04 ,
L_30 , V_200 }
} ,
{ & V_60 ,
{ L_31 , L_32 ,
V_198 , V_201 , F_47 ( V_202 ) , 0x03 ,
L_33 , V_200 }
} ,
{ & V_62 ,
{ L_34 , L_35 ,
V_203 , V_204 , NULL , 0x0 ,
L_36 , V_200 }
} ,
{ & V_63 ,
{ L_37 , L_38 ,
V_205 , V_204 , NULL , 0x0 ,
NULL , V_200 }
} ,
{ & V_64 ,
{ L_39 , L_40 ,
V_206 , V_199 , NULL , 0x0 ,
L_41 , V_200 }
} ,
{ & V_72 ,
{ L_42 , L_43 ,
V_206 , V_199 , NULL , 0x0 ,
L_44 , V_200 }
} ,
{ & V_61 ,
{ L_45 , L_46 ,
V_198 , V_199 , NULL , 0x7f ,
NULL , V_200 }
} ,
{ & V_93 ,
{ L_47 , L_48 ,
V_207 , V_201 , NULL , 0xfff0 ,
NULL , V_200 }
} ,
{ & V_94 ,
{ L_49 , L_50 ,
V_198 , V_201 | V_208 , & V_209 , 0xf ,
NULL , V_200 }
} ,
{ & V_95 ,
{ L_51 , L_52 ,
V_210 , V_204 , NULL , 0x0 ,
NULL , V_200 }
} ,
{ & V_108 ,
{ L_53 , L_54 ,
V_198 , V_199 | V_208 , & V_82 , 0x0 ,
NULL , V_200 }
} ,
{ & V_69 ,
{ L_55 , L_56 ,
V_210 , V_204 , NULL , 0x0 ,
NULL , V_200 }
} ,
{ & V_191 ,
{ L_57 , L_58 ,
V_198 , V_201 , F_47 ( V_211 ) , 0x0 ,
NULL , V_200 }
} ,
{ & V_189 ,
{ L_57 , L_59 ,
V_198 , V_201 , F_47 ( V_212 ) , 0x0 ,
NULL , V_200 }
} ,
{ & V_188 ,
{ L_57 , L_60 ,
V_198 , V_201 , F_47 ( V_213 ) , 0x0 ,
NULL , V_200 }
} ,
#if 0
{ &hf_udvm_operand,
{ "UDVM operand", "sigcomp.udvm.operand",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
#endif
{ & V_127 ,
{ L_61 , L_62 ,
V_207 , V_199 , NULL , 0x0 ,
L_63 , V_200 }
} ,
{ & V_126 ,
{ L_64 , L_65 ,
V_207 , V_199 , NULL , 0x0 ,
L_63 , V_200 }
} ,
{ & V_155 ,
{ L_66 , L_67 ,
V_207 , V_199 , NULL , 0x0 ,
L_49 , V_200 }
} ,
{ & V_154 ,
{ L_68 , L_69 ,
V_207 , V_199 , NULL , 0x0 ,
L_49 , V_200 }
} ,
{ & V_145 ,
{ L_70 , L_71 ,
V_207 , V_199 , NULL , 0x0 ,
L_72 , V_200 }
} ,
{ & V_130 ,
{ L_73 , L_62 ,
V_207 , V_199 , NULL , 0x0 ,
L_72 , V_200 }
} ,
{ & V_134 ,
{ L_74 , L_75 ,
V_207 , V_199 , NULL , 0x0 ,
L_76 , V_200 }
} ,
{ & V_132 ,
{ L_77 , L_78 ,
V_207 , V_199 , NULL , 0x0 ,
L_79 , V_200 }
} ,
{ & V_131 ,
{ L_80 , L_78 ,
V_207 , V_199 , NULL , 0x0 ,
L_79 , V_200 }
} ,
{ & V_163 ,
{ L_81 , L_82 ,
V_207 , V_199 , NULL , 0x0 ,
L_83 , V_200 }
} ,
{ & V_164 ,
{ L_84 , L_85 ,
V_207 , V_199 , NULL , 0x0 ,
L_86 , V_200 }
} ,
{ & V_165 ,
{ L_87 , L_88 ,
V_207 , V_199 , NULL , 0x0 ,
L_89 , V_200 }
} ,
{ & V_167 ,
{ L_90 , L_91 ,
V_207 , V_199 , NULL , 0x0 ,
L_92 , V_200 }
} ,
{ & V_166 ,
{ L_93 , L_94 ,
V_207 , V_199 , NULL , 0x0 ,
L_92 , V_200 }
} ,
{ & V_169 ,
{ L_95 , L_96 ,
V_207 , V_199 , NULL , 0x0 ,
L_97 , V_200 }
} ,
{ & V_168 ,
{ L_98 , L_99 ,
V_207 , V_199 , NULL , 0x0 ,
L_97 , V_200 }
} ,
{ & V_170 ,
{ L_100 , L_101 ,
V_207 , V_199 , NULL , 0x0 ,
L_102 , V_200 }
} ,
{ & V_110 ,
{ L_103 , L_104 ,
V_207 , V_199 , NULL , 0x0 ,
L_105 , V_200 }
} ,
{ & V_112 ,
{ L_106 , L_107 ,
V_207 , V_199 , NULL , 0x0 ,
L_108 , V_200 }
} ,
{ & V_111 ,
{ L_109 , L_110 ,
V_207 , V_199 , NULL , 0x0 ,
L_108 , V_200 }
} ,
{ & V_151 ,
{ L_111 , L_112 ,
V_207 , V_199 , NULL , 0x0 ,
L_113 , V_200 }
} ,
{ & V_150 ,
{ L_114 , L_115 ,
V_207 , V_199 , NULL , 0x0 ,
L_113 , V_200 }
} ,
{ & V_177 ,
{ L_116 , L_117 ,
V_207 , V_199 , NULL , 0x0 ,
L_118 , V_200 }
} ,
{ & V_176 ,
{ L_119 , L_120 ,
V_207 , V_199 , NULL , 0x0 ,
L_118 , V_200 }
} ,
{ & V_179 ,
{ L_121 , L_122 ,
V_207 , V_199 , NULL , 0x0 ,
L_123 , V_200 }
} ,
{ & V_178 ,
{ L_124 , L_125 ,
V_207 , V_199 , NULL , 0x0 ,
L_123 , V_200 }
} ,
{ & V_181 ,
{ L_126 , L_127 ,
V_207 , V_199 , NULL , 0x0 ,
L_128 , V_200 }
} ,
{ & V_172 ,
{ L_129 , L_130 ,
V_207 , V_199 , NULL , 0x0 ,
L_131 , V_200 }
} ,
{ & V_173 ,
{ L_132 , L_133 ,
V_207 , V_199 , NULL , 0x0 ,
L_134 , V_200 }
} ,
{ & V_182 ,
{ L_135 , L_136 ,
V_207 , V_199 , NULL , 0x0 ,
L_137 , V_200 }
} ,
{ & V_125 ,
{ L_138 , L_139 ,
V_207 , V_199 , NULL , 0x0 ,
L_140 , V_200 }
} ,
{ & V_128 ,
{ L_141 , L_142 ,
V_207 , V_199 , NULL , 0x0 ,
L_143 , V_200 }
} ,
{ & V_158 ,
{ L_144 , L_145 ,
V_207 , V_199 , NULL , 0x0 ,
L_146 , V_200 }
} ,
{ & V_159 ,
{ L_147 , L_148 ,
V_207 , V_199 , NULL , 0x0 ,
L_149 , V_200 }
} ,
{ & V_160 ,
{ L_150 , L_151 ,
V_207 , V_199 , NULL , 0x0 ,
L_152 , V_200 }
} ,
{ & V_161 ,
{ L_153 , L_154 ,
V_207 , V_199 , NULL , 0x0 ,
L_155 , V_200 }
} ,
{ & V_143 ,
{ L_156 , L_157 ,
V_207 , V_199 , NULL , 0x0 ,
L_158 , V_200 }
} ,
{ & V_141 ,
{ L_159 , L_160 ,
V_207 , V_199 , NULL , 0x0 ,
L_161 , V_200 }
} ,
{ & V_140 ,
{ L_162 , L_163 ,
V_207 , V_199 , NULL , 0x0 ,
L_161 , V_200 }
} ,
{ & V_77 ,
{ L_164 , L_165 ,
V_198 , V_199 , NULL , 0x0f ,
NULL , V_200 }
} ,
{ & V_78 ,
{ L_166 , L_167 ,
V_198 , V_199 | V_208 , & V_81 , 0x0 ,
L_168 , V_200 }
} ,
{ & V_79 ,
{ L_169 , L_170 ,
V_198 , V_199 | V_208 , & V_82 , 0x0 ,
L_171 , V_200 }
} ,
{ & V_83 ,
{ L_172 , L_173 ,
V_207 , V_199 , NULL , 0x0 ,
L_174 , V_200 }
} ,
{ & V_84 ,
{ L_175 , L_176 ,
V_203 , V_204 , NULL , 0x0 ,
L_177 , V_200 }
} ,
{ & V_88 ,
{ L_178 , L_179 ,
V_203 , V_204 , NULL , 0x0 ,
L_180 , V_200 }
} ,
{ & V_90 ,
{ L_181 , L_182 ,
V_198 , V_199 , NULL , 0x0 ,
L_183 , V_200 }
} ,
{ & V_92 ,
{ L_184 , L_185 ,
V_207 , V_199 , NULL , 0x0 ,
NULL , V_200 }
} ,
} ;
static T_9 * V_214 [] = {
& V_28 ,
& V_96 ,
& V_70 ,
} ;
static T_9 * V_215 [] = {
& V_196 ,
} ;
static T_16 V_216 [] = {
{ & V_80 , { L_186 , V_217 , V_218 , L_187 , V_219 } } ,
} ;
T_17 * V_220 ;
T_18 * V_221 ;
static const T_19 V_222 [] = {
{ L_188 , L_189 , 0 } ,
{ L_190 , L_191 , 1 } ,
{ L_192 , L_193 , 2 } ,
{ L_194 , L_195 , 3 } ,
{ NULL , NULL , - 1 }
} ;
V_26 = F_48 ( L_196 ,
L_1 , L_197 ) ;
V_195 = F_48 ( L_198 ,
L_199 , L_200 ) ;
F_49 ( L_197 , F_17 , V_26 ) ;
F_50 ( V_26 , V_197 , F_51 ( V_197 ) ) ;
F_52 ( V_214 , F_51 ( V_214 ) ) ;
F_52 ( V_215 , F_51 ( V_215 ) ) ;
V_221 = F_53 ( V_26 ) ;
F_54 ( V_221 , V_216 , F_51 ( V_216 ) ) ;
V_220 = F_55 ( V_26 ,
V_223 ) ;
F_56 ( V_220 , L_201 ,
L_202 ,
L_203 ,
10 ,
& V_224 ) ;
F_56 ( V_220 , L_204 ,
L_205 ,
L_206 ,
10 ,
& V_225 ) ;
F_56 ( V_220 , L_207 ,
L_208 ,
L_209 ,
10 ,
& V_226 ) ;
F_56 ( V_220 , L_210 ,
L_211 ,
L_212 ,
10 ,
& V_227 ) ;
F_57 ( V_220 , L_213 ,
L_214 ,
L_215 ,
& V_97 ) ;
F_57 ( V_220 , L_216 ,
L_217 ,
L_218
L_219 ,
& V_187 ) ;
F_57 ( V_220 , L_220 ,
L_221 ,
L_222 ,
& V_65 ) ;
F_57 ( V_220 , L_223 ,
L_224 ,
L_225
L_226 ,
& V_73 ) ;
F_58 ( V_220 , L_227 ,
L_228 ,
L_229
L_230
L_231 ,
& V_30 , V_222 , FALSE ) ;
F_59 ( & F_1 ) ;
}
void
V_223 ( void )
{
static T_20 V_228 ;
static T_20 V_229 ;
static T_8 V_230 = FALSE ;
static T_11 V_231 ;
static T_11 V_232 ;
static T_11 V_233 ;
static T_11 V_234 ;
if ( ! V_230 ) {
V_228 = F_60 ( L_197 ) ;
V_229 = F_61 ( F_3 , V_26 ) ;
V_74 = F_60 ( L_232 ) ;
V_230 = TRUE ;
} else{
F_62 ( L_201 , V_231 , V_228 ) ;
F_62 ( L_201 , V_232 , V_228 ) ;
F_62 ( L_207 , V_233 , V_229 ) ;
F_62 ( L_207 , V_234 , V_229 ) ;
}
V_231 = V_224 ;
V_232 = V_225 ;
V_233 = V_226 ;
V_234 = V_227 ;
F_63 ( L_201 , V_224 , V_228 ) ;
F_63 ( L_201 , V_225 , V_228 ) ;
F_63 ( L_207 , V_226 , V_229 ) ;
F_63 ( L_207 , V_227 , V_229 ) ;
}
