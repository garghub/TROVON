static void
F_1 ( void )
{
F_2 () ;
}
static int
F_3 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 )
{
T_4 * V_4 ;
T_3 * V_5 ;
T_1 * V_6 ;
T_5 * V_7 ;
int V_8 = 0 ;
int V_9 ;
T_5 V_10 ;
T_6 V_11 ;
int V_12 ;
int V_13 ;
T_7 V_14 ;
V_15 = V_3 ;
V_11 = F_4 ( V_1 , V_8 ) ;
if( V_11 == 0xffff ) {
V_8 = V_8 + 2 ;
V_10 = F_5 ( V_1 , V_8 ) ;
} else{
V_10 = F_5 ( V_1 , V_8 ) ;
}
if ( ( V_10 & 0xf8 ) != 0xf8 )
return V_8 ;
V_9 = F_6 ( V_1 , V_8 ) ;
for( V_12 = 0 ; V_12 < ( V_9 - 1 ) ; ++ V_12 ) {
V_11 = F_4 ( V_1 , V_8 + V_12 ) ;
if ( 0xffff == V_11 ) break;
}
if ( V_12 >= ( V_9 - 1 ) ) {
if ( V_2 -> V_16 || V_2 -> V_17 ) {
V_2 -> V_18 = V_8 ;
V_2 -> V_19 = V_20 ;
return - 1 ;
}
}
F_7 ( V_2 -> V_21 , V_22 , L_1 ) ;
F_8 ( V_2 -> V_21 , V_23 ) ;
V_9 = F_9 ( V_1 , V_8 ) ;
V_24:
V_4 = F_10 ( V_3 , V_25 , V_1 , 0 , - 1 , V_26 ) ;
V_5 = F_11 ( V_4 , V_27 ) ;
V_12 = 0 ;
V_14 = FALSE ;
V_7 = F_12 ( V_9 - V_8 ) ;
if ( V_28 > 2 )
F_13 ( V_5 , V_1 , V_8 , - 1 , L_2 ) ;
while ( ( V_8 < V_9 ) && ( V_14 == FALSE ) ) {
V_10 = F_5 ( V_1 , V_8 ) ;
if ( V_10 == 0xff ) {
if ( V_8 + 1 >= V_9 ) {
V_8 ++ ;
continue;
}
if ( V_28 > 2 )
F_13 ( V_5 , V_1 , V_8 , 2 ,
L_3 ) ;
V_10 = F_5 ( V_1 , V_8 + 1 ) ;
if ( V_10 == 0 ) {
V_7 [ V_12 ] = 0xff ;
V_8 = V_8 + 2 ;
V_12 ++ ;
continue;
}
if ( ( V_10 > 0x7f ) && ( V_10 < 0xff ) ) {
if ( V_28 > 2 )
F_13 ( V_5 , V_1 , V_8 , 2 ,
L_4 ) ;
V_8 = V_8 + F_9 ( V_1 , V_8 ) ;
return V_8 ;
}
if ( V_10 == 0xff ) {
if ( V_28 > 2 )
F_13 ( V_5 , V_1 , V_8 , 2 ,
L_5 ) ;
V_14 = TRUE ;
V_8 = V_8 + 2 ;
continue;
}
V_7 [ V_12 ] = 0xff ;
if ( V_28 > 2 )
F_13 ( V_5 , V_1 , V_8 , 1 ,
L_6 , V_12 , V_7 [ V_12 ] ) ;
V_12 ++ ;
V_8 = V_8 + 2 ;
if ( V_28 > 2 )
F_13 ( V_5 , V_1 , V_8 , V_10 ,
L_7 , V_10 ) ;
if( V_8 + V_10 >= V_9 )
V_10 = V_9 - V_8 ;
for ( V_13 = 0 ; V_13 < V_10 ; V_13 ++ ) {
V_7 [ V_12 ] = F_5 ( V_1 , V_8 ) ;
if ( V_28 > 2 )
F_13 ( V_5 , V_1 , V_8 , 1 ,
L_8 , V_12 , V_7 [ V_12 ] ) ;
V_12 ++ ;
V_8 ++ ;
}
continue;
}
V_7 [ V_12 ] = V_10 ;
if ( V_28 > 2 )
F_13 ( V_5 , V_1 , V_8 , 1 ,
L_6 , V_12 , V_7 [ V_12 ] ) ;
V_12 ++ ;
V_8 ++ ;
}
V_6 = F_14 ( V_1 , V_7 , V_12 , V_12 ) ;
F_15 ( V_6 , V_29 ) ;
F_16 ( V_2 , V_6 , L_9 ) ;
F_13 ( V_5 , V_6 , 0 , - 1 , L_10 ) ;
if ( V_14 == TRUE ) {
F_17 ( V_6 , V_2 , V_5 ) ;
} else{
F_13 ( V_5 , V_6 , 0 , - 1 , L_11 ) ;
}
if ( V_8 < V_9 ) {
goto V_24;
}
return V_8 ;
}
static int
F_18 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 )
{
T_4 * V_4 ;
T_3 * V_5 ;
T_8 V_8 = 0 ;
T_9 V_10 ;
if ( V_2 -> V_30 == V_31 )
return F_3 ( V_1 , V_2 , V_3 ) ;
V_10 = F_5 ( V_1 , V_8 ) ;
if ( ( V_10 & 0xf8 ) != 0xf8 )
return 0 ;
F_7 ( V_2 -> V_21 , V_22 , L_1 ) ;
F_8 ( V_2 -> V_21 , V_23 ) ;
V_15 = V_3 ;
V_4 = F_10 ( V_3 , V_25 , V_1 , 0 , - 1 , V_26 ) ;
V_5 = F_11 ( V_4 , V_27 ) ;
return F_17 ( V_1 , V_2 , V_5 ) ;
}
static int
F_17 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_5 )
{
T_1 * V_32 , * V_33 , * V_34 ;
T_1 * V_35 = NULL ;
T_4 * V_36 , * V_37 ;
T_3 * V_38 , * V_39 ;
T_8 V_8 = 0 ;
T_8 V_40 ;
T_6 V_41 ;
T_10 V_10 ;
T_5 V_42 [ 128 ] ;
T_5 V_43 [ 12 ] ;
T_10 V_44 ;
T_6 V_45 = 0 ;
T_6 V_46 = 0 ;
T_10 V_47 ;
T_8 V_48 = 0 ;
T_5 * V_7 ;
T_6 V_49 ;
T_5 V_12 ;
T_6 V_50 ;
T_6 V_51 ;
T_6 V_52 ;
T_6 V_53 ;
T_6 V_54 ;
T_11 * V_55 ;
T_5 V_56 ;
V_10 = F_5 ( V_1 , V_8 ) ;
F_10 ( V_5 , V_57 , V_1 , V_8 , 1 , V_58 ) ;
F_10 ( V_5 , V_59 , V_1 , V_8 , 1 , V_58 ) ;
V_44 = ( V_10 & 0x04 ) >> 2 ;
V_41 = V_10 & 0x03 ;
V_8 ++ ;
if ( V_41 != 0 ) {
V_41 = V_41 * 3 + 3 ;
F_7 ( V_2 -> V_21 , V_23 , L_12 ) ;
if ( V_44 == 1 ) {
V_45 = 1 ;
V_10 = F_5 ( V_1 , V_8 ) ;
if ( ( V_10 & 0x80 ) != 0 ) {
V_45 = V_10 & 0x7f ;
F_10 ( V_5 , V_60 ,
V_1 , V_8 , 1 , V_58 ) ;
V_8 ++ ;
F_19 ( V_1 , V_42 , V_8 , V_45 ) ;
} else {
V_42 [ 0 ] = F_5 ( V_1 , V_8 ) & 0x7f ;
}
F_20 ( V_5 , V_61 ,
V_1 , V_8 , V_45 , V_42 ) ;
V_8 = V_8 + V_45 ;
}
F_19 ( V_1 , V_43 , V_8 , V_41 ) ;
V_55 = F_21 ( V_43 , V_41 ) ;
F_22 ( V_5 , V_62 ,
V_1 , V_8 , V_41 , V_55 ) ;
V_8 = V_8 + V_41 ;
V_48 = F_23 ( V_1 , V_8 ) ;
if( V_48 > 0 ) {
T_4 * V_4 ;
V_4 = F_24 ( V_5 , V_63 , V_1 ,
V_8 , 0 , V_48 ) ;
F_25 ( V_4 ) ;
}
if ( V_64 ) {
V_33 = F_26 ( V_1 , V_8 , V_48 , V_48 ) ;
V_7 = F_27 ( V_65 ) ;
V_49 = 0 ;
V_50 = 0 ;
V_51 = 0 ;
V_52 = 0 ;
V_53 = 0 ;
V_12 = 0 ;
while ( V_12 < V_41 ) {
V_7 [ V_12 ] = V_43 [ V_12 ] ;
V_12 ++ ;
}
#if 0
result_code = udvm_state_access(tvb, sigcomp_tree, buff, p_id_start, partial_state_len, state_begin, &state_length,
&state_address, &state_instruction, hf_sigcomp_partial_state);
#endif
V_54 = F_28 ( V_1 , V_5 , V_7 , V_49 , V_66 , V_50 , & V_51 ,
& V_52 , & V_53 , V_62 ) ;
if ( V_54 != 0 ) {
T_4 * V_4 ;
V_4 = F_13 ( V_5 , V_1 , 0 , - 1 , L_13 ,
F_29 ( V_54 , V_67 , L_14 ) ) ;
F_25 ( V_4 ) ;
V_29 ( V_7 ) ;
return F_30 ( V_1 ) ;
}
V_32 = F_14 ( V_1 , V_7 , V_51 + V_52 , V_51 + V_52 ) ;
F_16 ( V_2 , V_32 , L_15 ) ;
F_15 ( V_32 , V_29 ) ;
V_34 = F_26 ( V_32 , V_52 , V_51 , V_51 ) ;
V_37 = F_10 ( V_5 , V_68 ,
V_34 , 0 , V_51 ,
V_26 ) ;
V_39 = F_11 ( V_37 , V_69 ) ;
V_35 = F_31 ( V_34 , V_33 , V_2 ,
V_39 , V_52 ,
V_28 , V_62 ,
V_8 , V_51 , V_41 , V_53 ) ;
if ( V_35 ) {
T_4 * V_4 ;
T_12 V_70 =
( T_12 ) ( ( ( float ) F_30 ( V_35 ) / ( float ) F_30 ( V_1 ) ) * 100 ) ;
F_13 ( V_5 , V_35 , 0 , - 1 , L_16 ) ;
V_4 = F_24 ( V_5 , V_71 , V_35 ,
0 , 0 , V_70 ) ;
F_25 ( V_4 ) ;
if ( V_72 )
F_32 ( V_35 , V_15 ) ;
F_33 ( V_2 -> V_21 , V_22 , L_17 ) ;
F_34 ( V_2 -> V_21 , V_22 ) ;
F_35 ( V_73 , V_35 , V_2 , V_15 ) ;
}
}
}
else{
F_7 ( V_2 -> V_21 , V_23 , L_18 ) ;
if ( V_44 == 1 ) {
V_45 = 1 ;
V_10 = F_5 ( V_1 , V_8 ) ;
if ( ( V_10 & 0x80 ) != 0 ) {
V_45 = V_10 & 0x7f ;
F_10 ( V_5 , V_60 ,
V_1 , V_8 , 1 , V_58 ) ;
V_8 ++ ;
}
F_19 ( V_1 , V_42 , V_8 , V_45 ) ;
F_20 ( V_5 , V_61 ,
V_1 , V_8 , V_45 , V_42 ) ;
V_8 = V_8 + V_45 ;
}
V_45 = F_4 ( V_1 , V_8 ) >> 4 ;
V_56 = F_5 ( V_1 , V_8 + 1 ) & 0x0f ;
if ( ( V_45 == 0 ) && ( V_56 == 1 ) ) {
T_4 * V_74 ;
T_5 V_75 ;
V_8 ++ ;
F_10 ( V_5 , V_76 , V_1 , V_8 , 1 , V_58 ) ;
V_8 ++ ;
V_10 = F_5 ( V_1 , V_8 ) ;
V_74 = F_10 ( V_5 , V_77 , V_1 , V_8 , 1 , V_58 ) ;
V_8 ++ ;
V_75 = F_5 ( V_1 , V_8 ) ;
F_10 ( V_5 , V_78 , V_1 , V_8 , 1 , V_58 ) ;
V_8 ++ ;
F_36 ( V_2 , V_74 , V_79 , V_80 ,
L_19 ,
F_29 ( V_10 , V_81 , L_20 ) ,
F_29 ( V_75 , V_82 , L_20 ) ) ;
F_10 ( V_5 , V_83 , V_1 , V_8 , 2 , V_58 ) ;
V_8 = V_8 + 2 ;
F_10 ( V_5 , V_84 , V_1 , V_8 , 20 , V_26 ) ;
V_8 = V_8 + 20 ;
F_37 ( V_2 -> V_21 , V_23 , L_21 ,
F_29 ( V_10 , V_81 , L_20 ) ,
F_29 ( V_75 , V_82 , L_20 ) ) ;
switch ( V_10 ) {
case V_85 :
case V_86 :
case V_87 :
F_10 ( V_5 , V_88 , V_1 , V_8 , - 1 , V_26 ) ;
break;
case V_89 :
F_10 ( V_5 , V_90 , V_1 , V_8 , 1 , V_58 ) ;
break;
case V_91 :
F_10 ( V_5 , V_92 , V_1 , V_8 , 2 , V_58 ) ;
break;
default:
break;
}
} else{
V_10 = F_5 ( V_1 , ( V_8 + 1 ) ) ;
V_47 = ( V_10 & 0x0f ) ;
if ( V_47 != 0 )
V_47 = 64 + ( V_47 * 64 ) ;
F_10 ( V_5 , V_93 , V_1 , V_8 , 2 , V_58 ) ;
F_10 ( V_5 , V_94 , V_1 , ( V_8 + 1 ) , 1 , V_58 ) ;
V_8 = V_8 + 2 ;
V_46 = V_45 ;
V_40 = V_8 ;
V_36 = F_10 ( V_5 , V_95 , V_1 ,
V_40 , V_46 , V_26 ) ;
F_38 ( V_36 ,
L_22 , V_46 , V_46 ) ;
V_38 = F_11 ( V_36 , V_96 ) ;
V_32 = F_26 ( V_1 , V_8 , V_45 , V_45 ) ;
if ( V_97 )
F_39 ( V_32 , V_38 , V_47 ) ;
V_8 = V_8 + V_45 ;
V_48 = F_23 ( V_1 , V_8 ) ;
if ( V_48 > 0 ) {
T_4 * V_4 = F_13 ( V_5 , V_1 , V_8 , - 1 ,
L_23 ,
F_23 ( V_1 , V_8 ) ) ;
F_25 ( V_4 ) ;
}
if ( V_64 ) {
V_33 = F_26 ( V_1 , V_8 , V_48 , V_48 ) ;
V_37 = F_10 ( V_5 , V_68 ,
V_1 , V_40 , V_46 ,
V_26 ) ;
V_39 = F_11 ( V_37 , V_69 ) ;
V_35 = F_31 ( V_32 , V_33 , V_2 ,
V_39 , V_47 ,
V_28 , V_62 ,
V_8 , 0 , 0 , V_47 ) ;
if ( V_35 ) {
T_4 * V_4 ;
T_12 V_70 =
( T_12 ) ( ( ( float ) F_30 ( V_35 ) / ( float ) F_30 ( V_1 ) ) * 100 ) ;
F_13 ( V_5 , V_35 , 0 , - 1 , L_16 ) ;
V_4 = F_24 ( V_5 , V_71 , V_35 ,
0 , 0 , V_70 ) ;
F_25 ( V_4 ) ;
if ( V_72 )
F_32 ( V_35 , V_15 ) ;
F_33 ( V_2 -> V_21 , V_22 , L_17 ) ;
F_34 ( V_2 -> V_21 , V_22 ) ;
F_35 ( V_73 , V_35 , V_2 , V_15 ) ;
}
}
}
}
return F_30 ( V_1 ) ;
}
static void
F_39 ( T_1 * V_32 , T_3 * V_38 , T_10 V_98 )
{
T_10 V_99 ;
T_8 V_8 = 0 ;
T_8 V_100 = 0 ;
T_8 V_45 ;
T_8 V_13 ;
T_10 V_101 = 0 ;
T_6 V_102 = 0 ;
T_4 * V_103 , * V_104 ;
T_10 V_105 = V_98 ;
T_7 V_106 ;
T_6 V_107 = F_23 ( V_32 , V_8 ) ;
while ( V_107 > V_8 ) {
V_99 = F_5 ( V_32 , V_8 ) ;
V_101 ++ ;
V_105 = V_98 + V_8 ;
;
V_103 = F_13 ( V_38 , V_32 , V_8 , 1 ,
L_24 ,
V_101 , V_105 , V_105 ) ;
F_25 ( V_103 ) ;
F_10 ( V_38 , V_108 , V_32 , V_8 , 1 , V_58 ) ;
V_8 ++ ;
switch ( V_99 ) {
case V_109 :
V_8 = F_40 ( V_32 , V_38 , V_8 , & V_100 , & V_102 ) ;
V_45 = V_8 - V_100 ;
F_24 ( V_38 , V_110 ,
V_32 , V_100 , V_45 , V_102 ) ;
V_8 = F_41 ( V_32 , V_38 , V_8 , FALSE , & V_100 , & V_102 , & V_106 ) ;
V_45 = V_8 - V_100 ;
if ( V_106 ) {
F_24 ( V_38 , V_111 ,
V_32 , V_100 , V_45 , V_102 ) ;
} else{
F_24 ( V_38 , V_112 ,
V_32 , V_100 , V_45 , V_102 ) ;
}
break;
case V_113 :
V_8 = F_40 ( V_32 , V_38 , V_8 , & V_100 , & V_102 ) ;
V_45 = V_8 - V_100 ;
F_24 ( V_38 , V_110 ,
V_32 , V_100 , V_45 , V_102 ) ;
V_8 = F_41 ( V_32 , V_38 , V_8 , FALSE , & V_100 , & V_102 , & V_106 ) ;
V_45 = V_8 - V_100 ;
if ( V_106 ) {
F_24 ( V_38 , V_111 ,
V_32 , V_100 , V_45 , V_102 ) ;
} else{
F_24 ( V_38 , V_112 ,
V_32 , V_100 , V_45 , V_102 ) ;
}
break;
case V_114 :
V_8 = F_40 ( V_32 , V_38 , V_8 , & V_100 , & V_102 ) ;
V_45 = V_8 - V_100 ;
F_24 ( V_38 , V_110 ,
V_32 , V_100 , V_45 , V_102 ) ;
break;
case V_115 :
V_8 = F_40 ( V_32 , V_38 , V_8 , & V_100 , & V_102 ) ;
V_45 = V_8 - V_100 ;
F_24 ( V_38 , V_110 ,
V_32 , V_100 , V_45 , V_102 ) ;
V_8 = F_41 ( V_32 , V_38 , V_8 , FALSE , & V_100 , & V_102 , & V_106 ) ;
V_45 = V_8 - V_100 ;
if ( V_106 ) {
F_24 ( V_38 , V_111 ,
V_32 , V_100 , V_45 , V_102 ) ;
} else{
F_24 ( V_38 , V_112 ,
V_32 , V_100 , V_45 , V_102 ) ;
}
break;
case V_116 :
V_8 = F_40 ( V_32 , V_38 , V_8 , & V_100 , & V_102 ) ;
V_45 = V_8 - V_100 ;
F_24 ( V_38 , V_110 ,
V_32 , V_100 , V_45 , V_102 ) ;
V_8 = F_41 ( V_32 , V_38 , V_8 , FALSE , & V_100 , & V_102 , & V_106 ) ;
V_45 = V_8 - V_100 ;
if ( V_106 ) {
F_24 ( V_38 , V_111 ,
V_32 , V_100 , V_45 , V_102 ) ;
} else{
F_24 ( V_38 , V_112 ,
V_32 , V_100 , V_45 , V_102 ) ;
}
break;
case V_117 :
V_8 = F_40 ( V_32 , V_38 , V_8 , & V_100 , & V_102 ) ;
V_45 = V_8 - V_100 ;
F_24 ( V_38 , V_110 ,
V_32 , V_100 , V_45 , V_102 ) ;
V_8 = F_41 ( V_32 , V_38 , V_8 , FALSE , & V_100 , & V_102 , & V_106 ) ;
V_45 = V_8 - V_100 ;
if ( V_106 ) {
F_24 ( V_38 , V_111 ,
V_32 , V_100 , V_45 , V_102 ) ;
} else{
F_24 ( V_38 , V_112 ,
V_32 , V_100 , V_45 , V_102 ) ;
}
break;
case V_118 :
V_8 = F_40 ( V_32 , V_38 , V_8 , & V_100 , & V_102 ) ;
V_45 = V_8 - V_100 ;
F_24 ( V_38 , V_110 ,
V_32 , V_100 , V_45 , V_102 ) ;
V_8 = F_41 ( V_32 , V_38 , V_8 , FALSE , & V_100 , & V_102 , & V_106 ) ;
V_45 = V_8 - V_100 ;
if ( V_106 ) {
F_24 ( V_38 , V_111 ,
V_32 , V_100 , V_45 , V_102 ) ;
} else{
F_24 ( V_38 , V_112 ,
V_32 , V_100 , V_45 , V_102 ) ;
}
break;
case V_119 :
V_8 = F_40 ( V_32 , V_38 , V_8 , & V_100 , & V_102 ) ;
V_45 = V_8 - V_100 ;
F_24 ( V_38 , V_110 ,
V_32 , V_100 , V_45 , V_102 ) ;
V_8 = F_41 ( V_32 , V_38 , V_8 , FALSE , & V_100 , & V_102 , & V_106 ) ;
V_45 = V_8 - V_100 ;
if ( V_106 ) {
F_24 ( V_38 , V_111 ,
V_32 , V_100 , V_45 , V_102 ) ;
} else{
F_24 ( V_38 , V_112 ,
V_32 , V_100 , V_45 , V_102 ) ;
}
break;
case V_120 :
V_8 = F_40 ( V_32 , V_38 , V_8 , & V_100 , & V_102 ) ;
V_45 = V_8 - V_100 ;
F_24 ( V_38 , V_110 ,
V_32 , V_100 , V_45 , V_102 ) ;
V_8 = F_41 ( V_32 , V_38 , V_8 , FALSE , & V_100 , & V_102 , & V_106 ) ;
V_45 = V_8 - V_100 ;
if ( V_106 ) {
F_24 ( V_38 , V_111 ,
V_32 , V_100 , V_45 , V_102 ) ;
} else{
F_24 ( V_38 , V_112 ,
V_32 , V_100 , V_45 , V_102 ) ;
}
break;
case V_121 :
V_8 = F_40 ( V_32 , V_38 , V_8 , & V_100 , & V_102 ) ;
V_45 = V_8 - V_100 ;
F_24 ( V_38 , V_110 ,
V_32 , V_100 , V_45 , V_102 ) ;
V_8 = F_41 ( V_32 , V_38 , V_8 , FALSE , & V_100 , & V_102 , & V_106 ) ;
V_45 = V_8 - V_100 ;
if ( V_106 ) {
F_24 ( V_38 , V_111 ,
V_32 , V_100 , V_45 , V_102 ) ;
} else{
F_24 ( V_38 , V_112 ,
V_32 , V_100 , V_45 , V_102 ) ;
}
break;
case V_122 :
V_8 = V_8 + F_23 ( V_32 , V_8 ) ;
break;
case V_123 :
V_8 = V_8 + F_23 ( V_32 , V_8 ) ;
break;
case V_124 :
V_8 = F_41 ( V_32 , V_38 , V_8 , FALSE , & V_100 , & V_102 , & V_106 ) ;
V_45 = V_8 - V_100 ;
F_24 ( V_38 , V_125 ,
V_32 , V_100 , V_45 , V_102 ) ;
V_8 = F_41 ( V_32 , V_38 , V_8 , FALSE , & V_100 , & V_102 , & V_106 ) ;
V_45 = V_8 - V_100 ;
if ( V_106 ) {
F_24 ( V_38 , V_126 ,
V_32 , V_100 , V_45 , V_102 ) ;
} else{
F_24 ( V_38 , V_127 ,
V_32 , V_100 , V_45 , V_102 ) ;
}
V_8 = F_40 ( V_32 , V_38 , V_8 , & V_100 , & V_102 ) ;
V_45 = V_8 - V_100 ;
F_24 ( V_38 , V_128 ,
V_32 , V_100 , V_45 , V_102 ) ;
break;
case V_129 :
V_8 = F_41 ( V_32 , V_38 , V_8 , TRUE , & V_100 , & V_102 , & V_106 ) ;
V_45 = V_8 - V_100 ;
F_24 ( V_38 , V_130 ,
V_32 , V_100 , V_45 , V_102 ) ;
V_8 = F_41 ( V_32 , V_38 , V_8 , FALSE , & V_100 , & V_102 , & V_106 ) ;
V_45 = V_8 - V_100 ;
if ( V_106 ) {
F_24 ( V_38 , V_131 ,
V_32 , V_100 , V_45 , V_102 ) ;
} else{
F_24 ( V_38 , V_132 ,
V_32 , V_100 , V_45 , V_102 ) ;
}
break;
case V_133 :
V_8 = F_41 ( V_32 , V_38 , V_8 , TRUE , & V_100 , & V_102 , & V_106 ) ;
V_45 = V_8 - V_100 ;
F_24 ( V_38 , V_130 ,
V_32 , V_100 , V_45 , V_102 ) ;
V_8 = F_42 ( V_32 , V_38 , V_8 , & V_100 , & V_102 ) ;
V_45 = V_8 - V_100 ;
F_24 ( V_38 , V_134 ,
V_32 , V_100 , V_45 , V_102 ) ;
V_13 = V_102 ;
while ( V_13 > 0 ) {
V_13 = V_13 - 1 ;
V_8 = F_41 ( V_32 , V_38 , V_8 , FALSE , & V_100 , & V_102 , & V_106 ) ;
V_45 = V_8 - V_100 ;
if ( V_106 ) {
F_24 ( V_38 , V_131 ,
V_32 , V_100 , V_45 , V_102 ) ;
} else{
F_24 ( V_38 , V_132 ,
V_32 , V_100 , V_45 , V_102 ) ;
}
}
break;
case V_135 :
V_8 = F_41 ( V_32 , V_38 , V_8 , FALSE , & V_100 , & V_102 , & V_106 ) ;
V_45 = V_8 - V_100 ;
if ( V_106 ) {
F_24 ( V_38 , V_131 ,
V_32 , V_100 , V_45 , V_102 ) ;
} else{
F_24 ( V_38 , V_132 ,
V_32 , V_100 , V_45 , V_102 ) ;
}
break;
case V_136 :
V_8 = F_41 ( V_32 , V_38 , V_8 , TRUE , & V_100 , & V_102 , & V_106 ) ;
V_45 = V_8 - V_100 ;
F_24 ( V_38 , V_130 ,
V_32 , V_100 , V_45 , V_102 ) ;
break;
case V_137 :
V_8 = F_41 ( V_32 , V_38 , V_8 , FALSE , & V_100 , & V_102 , & V_106 ) ;
V_45 = V_8 - V_100 ;
F_24 ( V_38 , V_125 ,
V_32 , V_100 , V_45 , V_102 ) ;
V_8 = F_41 ( V_32 , V_38 , V_8 , FALSE , & V_100 , & V_102 , & V_106 ) ;
V_45 = V_8 - V_100 ;
if ( V_106 ) {
F_24 ( V_38 , V_126 ,
V_32 , V_100 , V_45 , V_102 ) ;
} else{
F_24 ( V_38 , V_127 ,
V_32 , V_100 , V_45 , V_102 ) ;
}
V_8 = F_40 ( V_32 , V_38 , V_8 , & V_100 , & V_102 ) ;
V_45 = V_8 - V_100 ;
F_24 ( V_38 , V_128 ,
V_32 , V_100 , V_45 , V_102 ) ;
break;
case V_138 :
V_8 = F_41 ( V_32 , V_38 , V_8 , FALSE , & V_100 , & V_102 , & V_106 ) ;
V_45 = V_8 - V_100 ;
F_24 ( V_38 , V_125 ,
V_32 , V_100 , V_45 , V_102 ) ;
V_8 = F_41 ( V_32 , V_38 , V_8 , FALSE , & V_100 , & V_102 , & V_106 ) ;
V_45 = V_8 - V_100 ;
if ( V_106 ) {
F_24 ( V_38 , V_126 ,
V_32 , V_100 , V_45 , V_102 ) ;
} else{
F_24 ( V_38 , V_127 ,
V_32 , V_100 , V_45 , V_102 ) ;
}
V_8 = F_40 ( V_32 , V_38 , V_8 , & V_100 , & V_102 ) ;
V_45 = V_8 - V_100 ;
F_24 ( V_38 , V_128 ,
V_32 , V_100 , V_45 , V_102 ) ;
break;
case V_139 :
V_8 = F_41 ( V_32 , V_38 , V_8 , FALSE , & V_100 , & V_102 , & V_106 ) ;
V_45 = V_8 - V_100 ;
if ( V_106 ) {
F_24 ( V_38 , V_140 ,
V_32 , V_100 , V_45 , V_102 ) ;
} else{
F_24 ( V_38 , V_141 ,
V_32 , V_100 , V_45 , V_102 ) ;
}
V_8 = F_41 ( V_32 , V_38 , V_8 , FALSE , & V_100 , & V_102 , & V_106 ) ;
V_45 = V_8 - V_100 ;
if ( V_106 ) {
F_24 ( V_38 , V_126 ,
V_32 , V_100 , V_45 , V_102 ) ;
} else{
F_24 ( V_38 , V_127 ,
V_32 , V_100 , V_45 , V_102 ) ;
}
V_8 = F_40 ( V_32 , V_38 , V_8 , & V_100 , & V_102 ) ;
V_45 = V_8 - V_100 ;
F_24 ( V_38 , V_128 ,
V_32 , V_100 , V_45 , V_102 ) ;
break;
case V_142 :
V_8 = F_41 ( V_32 , V_38 , V_8 , TRUE , & V_100 , & V_102 , & V_106 ) ;
V_45 = V_8 - V_100 ;
F_24 ( V_38 , V_130 ,
V_32 , V_100 , V_45 , V_102 ) ;
V_8 = F_41 ( V_32 , V_38 , V_8 , FALSE , & V_100 , & V_102 , & V_106 ) ;
V_45 = V_8 - V_100 ;
if ( V_106 ) {
F_24 ( V_38 , V_126 ,
V_32 , V_100 , V_45 , V_102 ) ;
} else{
F_24 ( V_38 , V_127 ,
V_32 , V_100 , V_45 , V_102 ) ;
}
V_8 = F_41 ( V_32 , V_38 , V_8 , FALSE , & V_100 , & V_102 , & V_106 ) ;
V_45 = V_8 - V_100 ;
F_24 ( V_38 , V_143 ,
V_32 , V_100 , V_45 , V_102 ) ;
V_8 = F_41 ( V_32 , V_38 , V_8 , FALSE , & V_100 , & V_102 , & V_106 ) ;
V_45 = V_8 - V_100 ;
F_24 ( V_38 , V_141 ,
V_32 , V_100 , V_45 , V_102 ) ;
break;
case V_144 :
V_8 = F_41 ( V_32 , V_38 , V_8 , TRUE , & V_100 , & V_102 , & V_106 ) ;
V_45 = V_8 - V_100 ;
V_102 = ( V_102 + V_105 ) & 0xffff ;
F_24 ( V_38 , V_145 ,
V_32 , V_100 , V_45 , V_102 ) ;
break;
case V_146 :
V_8 = F_41 ( V_32 , V_38 , V_8 , FALSE , & V_100 , & V_102 , & V_106 ) ;
V_45 = V_8 - V_100 ;
if ( V_106 ) {
F_24 ( V_38 , V_131 ,
V_32 , V_100 , V_45 , V_102 ) ;
} else{
F_24 ( V_38 , V_132 ,
V_32 , V_100 , V_45 , V_102 ) ;
}
V_8 = F_41 ( V_32 , V_38 , V_8 , FALSE , & V_100 , & V_102 , & V_106 ) ;
V_45 = V_8 - V_100 ;
if ( V_106 ) {
F_24 ( V_38 , V_131 ,
V_32 , V_100 , V_45 , V_102 ) ;
} else{
F_24 ( V_38 , V_132 ,
V_32 , V_100 , V_45 , V_102 ) ;
}
V_8 = F_41 ( V_32 , V_38 , V_8 , TRUE , & V_100 , & V_102 , & V_106 ) ;
V_45 = V_8 - V_100 ;
V_102 = ( V_102 + V_105 ) & 0xffff ;
F_24 ( V_38 , V_145 ,
V_32 , V_100 , V_45 , V_102 ) ;
V_8 = F_41 ( V_32 , V_38 , V_8 , TRUE , & V_100 , & V_102 , & V_106 ) ;
V_45 = V_8 - V_100 ;
V_102 = ( V_102 + V_105 ) & 0xffff ;
F_24 ( V_38 , V_145 ,
V_32 , V_100 , V_45 , V_102 ) ;
V_8 = F_41 ( V_32 , V_38 , V_8 , TRUE , & V_100 , & V_102 , & V_106 ) ;
V_45 = V_8 - V_100 ;
V_102 = ( V_102 + V_105 ) & 0xffff ;
F_24 ( V_38 , V_145 ,
V_32 , V_100 , V_45 , V_102 ) ;
break;
case V_147 :
V_8 = F_41 ( V_32 , V_38 , V_8 , TRUE , & V_100 , & V_102 , & V_106 ) ;
V_45 = V_8 - V_100 ;
V_102 = ( V_102 + V_105 ) & 0xffff ;
F_24 ( V_38 , V_145 ,
V_32 , V_100 , V_45 , V_102 ) ;
break;
case V_148 :
break;
case V_149 :
V_8 = F_42 ( V_32 , V_38 , V_8 , & V_100 , & V_102 ) ;
V_45 = V_8 - V_100 ;
F_24 ( V_38 , V_134 ,
V_32 , V_100 , V_45 , V_102 ) ;
V_13 = V_102 ;
V_8 = F_41 ( V_32 , V_38 , V_8 , FALSE , & V_100 , & V_102 , & V_106 ) ;
V_45 = V_8 - V_100 ;
if ( V_106 ) {
F_24 ( V_38 , V_150 ,
V_32 , V_100 , V_45 , V_102 ) ;
} else{
F_24 ( V_38 , V_151 ,
V_32 , V_100 , V_45 , V_102 ) ;
}
while ( V_13 > 0 ) {
V_13 = V_13 - 1 ;
V_8 = F_41 ( V_32 , V_38 , V_8 , TRUE , & V_100 , & V_102 , & V_106 ) ;
V_45 = V_8 - V_100 ;
V_102 = ( V_102 + V_105 ) & 0xffff ;
F_24 ( V_38 , V_145 ,
V_32 , V_100 , V_45 , V_102 ) ;
}
break;
case V_152 :
V_8 = F_41 ( V_32 , V_38 , V_8 , FALSE , & V_100 , & V_102 , & V_106 ) ;
V_45 = V_8 - V_100 ;
if ( V_106 ) {
F_24 ( V_38 , V_131 ,
V_32 , V_100 , V_45 , V_102 ) ;
} else{
F_24 ( V_38 , V_132 ,
V_32 , V_100 , V_45 , V_102 ) ;
}
V_8 = F_41 ( V_32 , V_38 , V_8 , FALSE , & V_100 , & V_102 , & V_106 ) ;
V_45 = V_8 - V_100 ;
F_24 ( V_38 , V_125 ,
V_32 , V_100 , V_45 , V_102 ) ;
V_8 = F_41 ( V_32 , V_38 , V_8 , FALSE , & V_100 , & V_102 , & V_106 ) ;
V_45 = V_8 - V_100 ;
if ( V_106 ) {
F_24 ( V_38 , V_126 ,
V_32 , V_100 , V_45 , V_102 ) ;
} else{
F_24 ( V_38 , V_127 ,
V_32 , V_100 , V_45 , V_102 ) ;
}
V_8 = F_41 ( V_32 , V_38 , V_8 , TRUE , & V_100 , & V_102 , & V_106 ) ;
V_45 = V_8 - V_100 ;
V_102 = ( V_102 + V_105 ) & 0xffff ;
F_24 ( V_38 , V_145 ,
V_32 , V_100 , V_45 , V_102 ) ;
break;
case V_153 :
V_8 = F_41 ( V_32 , V_38 , V_8 , FALSE , & V_100 , & V_102 , & V_106 ) ;
V_45 = V_8 - V_100 ;
if ( V_106 ) {
F_24 ( V_38 , V_126 ,
V_32 , V_100 , V_45 , V_102 ) ;
} else{
F_24 ( V_38 , V_127 ,
V_32 , V_100 , V_45 , V_102 ) ;
}
V_8 = F_41 ( V_32 , V_38 , V_8 , FALSE , & V_100 , & V_102 , & V_106 ) ;
V_45 = V_8 - V_100 ;
if ( V_106 ) {
F_24 ( V_38 , V_154 ,
V_32 , V_100 , V_45 , V_102 ) ;
} else{
F_24 ( V_38 , V_155 ,
V_32 , V_100 , V_45 , V_102 ) ;
}
V_8 = F_41 ( V_32 , V_38 , V_8 , TRUE , & V_100 , & V_102 , & V_106 ) ;
V_45 = V_8 - V_100 ;
V_102 = ( V_102 + V_105 ) & 0xffff ;
F_24 ( V_38 , V_145 ,
V_32 , V_100 , V_45 , V_102 ) ;
break;
case V_156 :
V_8 = F_41 ( V_32 , V_38 , V_8 , FALSE , & V_100 , & V_102 , & V_106 ) ;
V_45 = V_8 - V_100 ;
if ( V_106 ) {
F_24 ( V_38 , V_126 ,
V_32 , V_100 , V_45 , V_102 ) ;
} else{
F_24 ( V_38 , V_127 ,
V_32 , V_100 , V_45 , V_102 ) ;
}
V_8 = F_41 ( V_32 , V_38 , V_8 , FALSE , & V_100 , & V_102 , & V_106 ) ;
V_45 = V_8 - V_100 ;
if ( V_106 ) {
F_24 ( V_38 , V_154 ,
V_32 , V_100 , V_45 , V_102 ) ;
} else{
F_24 ( V_38 , V_155 ,
V_32 , V_100 , V_45 , V_102 ) ;
}
V_8 = F_41 ( V_32 , V_38 , V_8 , TRUE , & V_100 , & V_102 , & V_106 ) ;
V_45 = V_8 - V_100 ;
V_102 = ( V_102 + V_105 ) & 0xffff ;
F_24 ( V_38 , V_145 ,
V_32 , V_100 , V_45 , V_102 ) ;
break;
case V_157 :
V_8 = F_41 ( V_32 , V_38 , V_8 , FALSE , & V_100 , & V_102 , & V_106 ) ;
V_45 = V_8 - V_100 ;
if ( V_106 ) {
F_24 ( V_38 , V_154 ,
V_32 , V_100 , V_45 , V_102 ) ;
} else{
F_24 ( V_38 , V_155 ,
V_32 , V_100 , V_45 , V_102 ) ;
}
V_8 = F_41 ( V_32 , V_38 , V_8 , TRUE , & V_100 , & V_102 , & V_106 ) ;
V_45 = V_8 - V_100 ;
V_102 = ( V_102 + V_105 ) & 0xffff ;
F_24 ( V_38 , V_145 ,
V_32 , V_100 , V_45 , V_102 ) ;
V_8 = F_42 ( V_32 , V_38 , V_8 , & V_100 , & V_102 ) ;
V_45 = V_8 - V_100 ;
F_24 ( V_38 , V_134 ,
V_32 , V_100 , V_45 , V_102 ) ;
V_13 = V_102 ;
while ( V_13 > 0 ) {
V_13 = V_13 - 1 ;
V_8 = F_41 ( V_32 , V_38 , V_8 , FALSE , & V_100 , & V_102 , & V_106 ) ;
V_45 = V_8 - V_100 ;
F_24 ( V_38 , V_158 ,
V_32 , V_100 , V_45 , V_102 ) ;
V_8 = F_41 ( V_32 , V_38 , V_8 , FALSE , & V_100 , & V_102 , & V_106 ) ;
V_45 = V_8 - V_100 ;
F_24 ( V_38 , V_159 ,
V_32 , V_100 , V_45 , V_102 ) ;
V_8 = F_41 ( V_32 , V_38 , V_8 , FALSE , & V_100 , & V_102 , & V_106 ) ;
V_45 = V_8 - V_100 ;
F_24 ( V_38 , V_160 ,
V_32 , V_100 , V_45 , V_102 ) ;
V_8 = F_41 ( V_32 , V_38 , V_8 , FALSE , & V_100 , & V_102 , & V_106 ) ;
V_45 = V_8 - V_100 ;
F_24 ( V_38 , V_161 ,
V_32 , V_100 , V_45 , V_102 ) ;
}
break;
case V_162 :
V_8 = F_41 ( V_32 , V_38 , V_8 , TRUE , & V_100 , & V_102 , & V_106 ) ;
V_45 = V_8 - V_100 ;
F_24 ( V_38 , V_163 ,
V_32 , V_100 , V_45 , V_102 ) ;
V_8 = F_41 ( V_32 , V_38 , V_8 , TRUE , & V_100 , & V_102 , & V_106 ) ;
V_45 = V_8 - V_100 ;
F_24 ( V_38 , V_164 ,
V_32 , V_100 , V_45 , V_102 ) ;
V_8 = F_41 ( V_32 , V_38 , V_8 , TRUE , & V_100 , & V_102 , & V_106 ) ;
V_45 = V_8 - V_100 ;
F_24 ( V_38 , V_165 ,
V_32 , V_100 , V_45 , V_102 ) ;
V_8 = F_41 ( V_32 , V_38 , V_8 , TRUE , & V_100 , & V_102 , & V_106 ) ;
V_45 = V_8 - V_100 ;
if ( V_106 ) {
F_24 ( V_38 , V_166 ,
V_32 , V_100 , V_45 , V_102 ) ;
} else{
F_24 ( V_38 , V_167 ,
V_32 , V_100 , V_45 , V_102 ) ;
}
V_8 = F_41 ( V_32 , V_38 , V_8 , TRUE , & V_100 , & V_102 , & V_106 ) ;
V_45 = V_8 - V_100 ;
if ( V_106 ) {
F_24 ( V_38 , V_168 ,
V_32 , V_100 , V_45 , V_102 ) ;
} else{
F_24 ( V_38 , V_169 ,
V_32 , V_100 , V_45 , V_102 ) ;
}
V_8 = F_41 ( V_32 , V_38 , V_8 , TRUE , & V_100 , & V_102 , & V_106 ) ;
V_45 = V_8 - V_100 ;
F_24 ( V_38 , V_170 ,
V_32 , V_100 , V_45 , V_102 ) ;
break;
case V_171 :
V_8 = F_41 ( V_32 , V_38 , V_8 , TRUE , & V_100 , & V_102 , & V_106 ) ;
V_45 = V_8 - V_100 ;
if ( V_106 ) {
F_24 ( V_38 , V_166 ,
V_32 , V_100 , V_45 , V_102 ) ;
} else{
F_24 ( V_38 , V_167 ,
V_32 , V_100 , V_45 , V_102 ) ;
}
V_8 = F_41 ( V_32 , V_38 , V_8 , TRUE , & V_100 , & V_102 , & V_106 ) ;
V_45 = V_8 - V_100 ;
if ( V_106 ) {
F_24 ( V_38 , V_168 ,
V_32 , V_100 , V_45 , V_102 ) ;
} else{
F_24 ( V_38 , V_169 ,
V_32 , V_100 , V_45 , V_102 ) ;
}
V_8 = F_41 ( V_32 , V_38 , V_8 , TRUE , & V_100 , & V_102 , & V_106 ) ;
V_45 = V_8 - V_100 ;
F_24 ( V_38 , V_170 ,
V_32 , V_100 , V_45 , V_102 ) ;
V_8 = F_41 ( V_32 , V_38 , V_8 , TRUE , & V_100 , & V_102 , & V_106 ) ;
V_45 = V_8 - V_100 ;
F_24 ( V_38 , V_172 ,
V_32 , V_100 , V_45 , V_102 ) ;
V_8 = F_41 ( V_32 , V_38 , V_8 , TRUE , & V_100 , & V_102 , & V_106 ) ;
V_45 = V_8 - V_100 ;
F_24 ( V_38 , V_173 ,
V_32 , V_100 , V_45 , V_102 ) ;
break;
case V_174 :
V_8 = F_41 ( V_32 , V_38 , V_8 , TRUE , & V_100 , & V_102 , & V_106 ) ;
V_45 = V_8 - V_100 ;
F_24 ( V_38 , V_163 ,
V_32 , V_100 , V_45 , V_102 ) ;
V_8 = F_41 ( V_32 , V_38 , V_8 , TRUE , & V_100 , & V_102 , & V_106 ) ;
V_45 = V_8 - V_100 ;
F_24 ( V_38 , V_164 ,
V_32 , V_100 , V_45 , V_102 ) ;
break;
case V_175 :
V_8 = F_41 ( V_32 , V_38 , V_8 , TRUE , & V_100 , & V_102 , & V_106 ) ;
V_45 = V_8 - V_100 ;
if ( V_106 ) {
F_24 ( V_38 , V_176 ,
V_32 , V_100 , V_45 , V_102 ) ;
} else{
F_24 ( V_38 , V_177 ,
V_32 , V_100 , V_45 , V_102 ) ;
}
V_8 = F_41 ( V_32 , V_38 , V_8 , TRUE , & V_100 , & V_102 , & V_106 ) ;
V_45 = V_8 - V_100 ;
if ( V_106 ) {
F_24 ( V_38 , V_178 ,
V_32 , V_100 , V_45 , V_102 ) ;
} else{
F_24 ( V_38 , V_179 ,
V_32 , V_100 , V_45 , V_102 ) ;
}
break;
case V_180 :
if ( ( V_107 - 1 ) < V_8 ) {
V_104 = F_13 ( V_38 , V_32 , 0 , - 1 ,
L_25 ) ;
F_25 ( V_104 ) ;
return;
}
V_8 = F_41 ( V_32 , V_38 , V_8 , TRUE , & V_100 , & V_102 , & V_106 ) ;
V_45 = V_8 - V_100 ;
F_24 ( V_38 , V_181 ,
V_32 , V_100 , V_45 , V_102 ) ;
if ( ( V_107 - 1 ) < V_8 ) {
V_104 = F_13 ( V_38 , V_32 , V_8 - 1 , - 1 ,
L_25 ) ;
F_25 ( V_104 ) ;
return;
}
V_8 = F_41 ( V_32 , V_38 , V_8 , TRUE , & V_100 , & V_102 , & V_106 ) ;
V_45 = V_8 - V_100 ;
F_24 ( V_38 , V_182 ,
V_32 , V_100 , V_45 , V_102 ) ;
V_8 = F_41 ( V_32 , V_38 , V_8 , TRUE , & V_100 , & V_102 , & V_106 ) ;
V_45 = V_8 - V_100 ;
if ( V_106 ) {
F_24 ( V_38 , V_166 ,
V_32 , V_100 , V_45 , V_102 ) ;
} else{
F_24 ( V_38 , V_167 ,
V_32 , V_100 , V_45 , V_102 ) ;
}
V_8 = F_41 ( V_32 , V_38 , V_8 , TRUE , & V_100 , & V_102 , & V_106 ) ;
V_45 = V_8 - V_100 ;
if ( V_106 ) {
F_24 ( V_38 , V_168 ,
V_32 , V_100 , V_45 , V_102 ) ;
} else{
F_24 ( V_38 , V_169 ,
V_32 , V_100 , V_45 , V_102 ) ;
}
V_8 = F_41 ( V_32 , V_38 , V_8 , TRUE , & V_100 , & V_102 , & V_106 ) ;
V_45 = V_8 - V_100 ;
F_24 ( V_38 , V_170 ,
V_32 , V_100 , V_45 , V_102 ) ;
V_8 = F_41 ( V_32 , V_38 , V_8 , TRUE , & V_100 , & V_102 , & V_106 ) ;
V_45 = V_8 - V_100 ;
F_24 ( V_38 , V_172 ,
V_32 , V_100 , V_45 , V_102 ) ;
if ( F_23 ( V_32 , V_8 ) != 0 ) {
V_8 = F_41 ( V_32 , V_38 , V_8 , TRUE , & V_100 , & V_102 , & V_106 ) ;
V_45 = V_8 - V_100 ;
F_24 ( V_38 , V_173 ,
V_32 , V_100 , V_45 , V_102 ) ;
} else{
V_104 = F_13 ( V_38 , V_32 , V_8 , 1 ,
L_26 ) ;
F_25 ( V_104 ) ;
}
if ( F_23 ( V_32 , V_8 ) != 0 ) {
V_45 = F_23 ( V_32 , V_8 ) ;
V_105 = V_98 + V_8 ;
F_13 ( V_38 , V_32 , V_8 , V_45 ,
L_27 , V_45 , V_105 , V_105 ) ;
}
V_8 = V_8 + F_23 ( V_32 , V_8 ) ;
break;
default:
V_8 = V_8 + F_23 ( V_32 , V_8 ) ;
break;
}
}
return;
}
static int
F_42 ( T_1 * V_32 , T_3 * V_38 ,
T_8 V_8 , T_8 * V_100 , T_6 * V_102 )
{
T_10 V_183 ;
T_6 V_184 ;
T_10 V_185 ;
T_10 V_186 ;
V_183 = F_5 ( V_32 , V_8 ) ;
V_185 = V_183 >> 7 ;
if ( V_185 == 1 ) {
V_185 = V_183 >> 6 ;
if ( V_185 == 2 ) {
V_186 = V_183 & 0xc0 ;
if ( V_187 )
F_24 ( V_38 , V_188 ,
V_32 , V_8 , 1 , V_186 ) ;
V_184 = F_4 ( V_32 , V_8 ) & 0x3fff ;
* V_102 = V_184 ;
* V_100 = V_8 ;
V_8 = V_8 + 2 ;
} else{
V_186 = V_183 & 0xc0 ;
if ( V_187 )
F_24 ( V_38 , V_188 ,
V_32 , V_8 , 1 , V_186 ) ;
V_8 ++ ;
V_184 = F_4 ( V_32 , V_8 ) ;
* V_102 = V_184 ;
* V_100 = V_8 ;
V_8 = V_8 + 2 ;
}
} else{
V_186 = V_183 & 0xc0 ;
if ( V_187 )
F_24 ( V_38 , V_188 ,
V_32 , V_8 , 1 , V_186 ) ;
V_184 = ( V_183 & 0x7f ) ;
* V_102 = V_184 ;
* V_100 = V_8 ;
V_8 ++ ;
}
return V_8 ;
}
static int
F_40 ( T_1 * V_32 , T_3 * V_38 ,
T_8 V_8 , T_8 * V_100 , T_6 * V_102 )
{
T_10 V_183 ;
T_6 V_184 ;
T_10 V_185 ;
T_10 V_186 ;
V_183 = F_5 ( V_32 , V_8 ) ;
V_185 = V_183 >> 7 ;
if ( V_185 == 1 ) {
V_185 = V_183 >> 6 ;
if ( V_185 == 2 ) {
V_186 = V_183 & 0xc0 ;
if ( V_187 )
F_24 ( V_38 , V_189 ,
V_32 , V_8 , 1 , V_186 ) ;
V_184 = F_4 ( V_32 , V_8 ) & 0x3fff ;
* V_102 = ( V_184 * 2 ) ;
* V_100 = V_8 ;
V_8 = V_8 + 2 ;
} else{
V_186 = V_183 & 0xc0 ;
if ( V_187 )
F_24 ( V_38 , V_189 ,
V_32 , V_8 , 1 , V_186 ) ;
V_8 ++ ;
V_184 = F_4 ( V_32 , V_8 ) ;
* V_102 = V_184 ;
* V_100 = V_8 ;
V_8 = V_8 + 2 ;
}
} else{
V_186 = V_183 & 0xc0 ;
if ( V_187 )
F_24 ( V_38 , V_189 ,
V_32 , V_8 , 1 , V_186 ) ;
V_184 = ( V_183 & 0x7f ) ;
* V_102 = ( V_184 * 2 ) ;
* V_100 = V_8 ;
V_8 ++ ;
}
return V_8 ;
}
static int
F_41 ( T_1 * V_32 , T_3 * V_38 ,
T_8 V_8 , T_7 T_13 V_190 , T_8 * V_100 , T_6 * V_102 , T_7 * V_106 )
{
T_10 V_183 ;
T_10 V_186 ;
T_6 V_184 ;
T_12 V_191 ;
T_10 V_185 ;
* V_106 = FALSE ;
V_183 = F_5 ( V_32 , V_8 ) ;
V_185 = ( V_183 & 0xc0 ) >> 6 ;
switch ( V_185 ) {
case 0 :
V_186 = V_183 & 0xc0 ;
if ( V_187 )
F_24 ( V_38 , V_192 ,
V_32 , V_8 , 1 , V_186 ) ;
V_184 = ( V_183 & 0x3f ) ;
* V_102 = V_184 ;
* V_100 = V_8 ;
V_8 ++ ;
break;
case 1 :
V_186 = V_183 & 0xc0 ;
if ( V_187 )
F_24 ( V_38 , V_192 ,
V_32 , V_8 , 1 , V_186 ) ;
V_184 = ( V_183 & 0x3f ) * 2 ;
* V_106 = TRUE ;
* V_102 = V_184 ;
* V_100 = V_8 ;
V_8 ++ ;
break;
case 2 :
V_185 = ( V_183 & 0xe0 ) >> 5 ;
if ( V_185 == 5 ) {
V_186 = V_183 & 0xe0 ;
if ( V_187 )
F_24 ( V_38 , V_192 ,
V_32 , V_8 , 1 , V_186 ) ;
V_184 = F_4 ( V_32 , V_8 ) & 0x1fff ;
* V_102 = V_184 ;
* V_100 = V_8 ;
V_8 = V_8 + 2 ;
} else{
V_185 = ( V_183 & 0xf0 ) >> 4 ;
if ( V_185 == 9 ) {
V_186 = V_183 & 0xf0 ;
if ( V_187 )
F_24 ( V_38 , V_192 ,
V_32 , V_8 , 1 , V_186 ) ;
V_184 = ( F_4 ( V_32 , V_8 ) & 0x0fff ) + 61440 ;
* V_100 = V_8 ;
* V_102 = V_184 ;
V_8 = V_8 + 2 ;
} else{
V_185 = ( V_183 & 0x08 ) >> 3 ;
if ( V_185 == 1 ) {
V_186 = V_183 & 0xf8 ;
if ( V_187 )
F_24 ( V_38 , V_192 ,
V_32 , V_8 , 1 , V_186 ) ;
V_191 = ( T_12 ) pow ( 2 , ( V_183 & 0x07 ) + 8 ) ;
V_184 = V_191 & 0xffff ;
* V_100 = V_8 ;
* V_102 = V_184 ;
V_8 ++ ;
} else{
V_185 = ( V_183 & 0x0e ) >> 1 ;
if ( V_185 == 3 ) {
V_186 = V_183 & 0xfe ;
if ( V_187 )
F_24 ( V_38 , V_192 ,
V_32 , V_8 , 1 , V_186 ) ;
V_191 = ( T_12 ) pow ( 2 , ( V_183 & 0x01 ) + 6 ) ;
V_184 = V_191 & 0xffff ;
* V_100 = V_8 ;
* V_102 = V_184 ;
V_8 ++ ;
} else{
V_186 = V_183 ;
if ( V_187 )
F_24 ( V_38 , V_192 ,
V_32 , V_8 , 1 , V_186 ) ;
if ( ( V_183 & 0x01 ) == 1 )
* V_106 = TRUE ;
V_8 ++ ;
V_184 = F_4 ( V_32 , V_8 ) ;
* V_102 = V_184 ;
* V_100 = V_8 ;
V_8 = V_8 + 2 ;
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
F_24 ( V_38 , V_192 ,
V_32 , V_8 , 1 , V_186 ) ;
V_184 = ( V_183 & 0x1f ) + 65504 ;
* V_100 = V_8 ;
* V_102 = V_184 ;
V_8 ++ ;
} else{
V_186 = V_183 & 0xe0 ;
if ( V_187 )
F_24 ( V_38 , V_192 ,
V_32 , V_8 , 1 , V_186 ) ;
V_184 = ( F_4 ( V_32 , V_8 ) & 0x1fff ) ;
* V_106 = TRUE ;
* V_100 = V_8 ;
* V_102 = V_184 ;
V_8 = V_8 + 2 ;
}
default :
break;
}
return V_8 ;
}
static void
F_32 ( T_1 * V_1 , T_3 * V_3 )
{
T_3 * V_193 = NULL ;
T_4 * V_4 = NULL ;
int V_8 , V_194 , V_195 ;
if( V_3 ) {
V_4 = F_10 ( V_3 , V_196 , V_1 , 0 , - 1 , V_26 ) ;
V_193 = F_11 ( V_4 , V_197 ) ;
}
V_8 = 0 ;
while ( F_43 ( V_1 , V_8 ) ) {
F_44 ( V_1 , V_8 , - 1 , & V_194 , FALSE ) ;
V_195 = V_194 - V_8 ;
if( V_193 ) {
F_13 ( V_193 , V_1 , V_8 , V_195 ,
L_28 , F_45 ( V_1 , V_8 , V_195 ) ) ;
}
V_8 = V_194 ;
}
}
void
F_46 ( void )
{
void V_198 ( void ) ;
static T_14 V_199 [] = {
{ & V_57 ,
{ L_29 , L_30 ,
V_200 , V_201 , NULL , 0x04 ,
L_31 , V_202 }
} ,
{ & V_59 ,
{ L_32 , L_33 ,
V_200 , V_203 , F_47 ( V_204 ) , 0x03 ,
L_34 , V_202 }
} ,
{ & V_61 ,
{ L_35 , L_36 ,
V_205 , V_206 , NULL , 0x0 ,
L_37 , V_202 }
} ,
{ & V_62 ,
{ L_38 , L_39 ,
V_207 , V_206 , NULL , 0x0 ,
NULL , V_202 }
} ,
{ & V_63 ,
{ L_40 , L_41 ,
V_208 , V_201 , NULL , 0x0 ,
L_42 , V_202 }
} ,
{ & V_71 ,
{ L_43 , L_44 ,
V_208 , V_201 , NULL , 0x0 ,
L_45 , V_202 }
} ,
{ & V_60 ,
{ L_46 , L_47 ,
V_200 , V_201 , NULL , 0x7f ,
NULL , V_202 }
} ,
{ & V_93 ,
{ L_48 , L_49 ,
V_209 , V_203 , NULL , 0xfff0 ,
NULL , V_202 }
} ,
{ & V_94 ,
{ L_50 , L_51 ,
V_200 , V_203 , F_47 ( V_210 ) , 0xf ,
NULL , V_202 }
} ,
{ & V_95 ,
{ L_52 , L_53 ,
V_211 , V_206 , NULL , 0x0 ,
NULL , V_202 }
} ,
{ & V_108 ,
{ L_54 , L_55 ,
V_200 , V_201 , F_47 ( V_82 ) , 0x0 ,
NULL , V_202 }
} ,
{ & V_68 ,
{ L_56 , L_57 ,
V_211 , V_206 , NULL , 0x0 ,
NULL , V_202 }
} ,
{ & V_192 ,
{ L_58 , L_59 ,
V_200 , V_203 , F_47 ( V_212 ) , 0x0 ,
NULL , V_202 }
} ,
{ & V_189 ,
{ L_58 , L_60 ,
V_200 , V_203 , F_47 ( V_213 ) , 0x0 ,
NULL , V_202 }
} ,
{ & V_188 ,
{ L_58 , L_61 ,
V_200 , V_203 , F_47 ( V_214 ) , 0x0 ,
NULL , V_202 }
} ,
{ & V_215 ,
{ L_62 , L_63 ,
V_209 , V_201 , NULL , 0x0 ,
NULL , V_202 }
} ,
{ & V_127 ,
{ L_64 , L_65 ,
V_209 , V_201 , NULL , 0x0 ,
L_66 , V_202 }
} ,
{ & V_126 ,
{ L_67 , L_68 ,
V_209 , V_201 , NULL , 0x0 ,
L_66 , V_202 }
} ,
{ & V_155 ,
{ L_69 , L_70 ,
V_209 , V_201 , NULL , 0x0 ,
L_50 , V_202 }
} ,
{ & V_154 ,
{ L_71 , L_72 ,
V_209 , V_201 , NULL , 0x0 ,
L_50 , V_202 }
} ,
{ & V_145 ,
{ L_73 , L_74 ,
V_209 , V_201 , NULL , 0x0 ,
L_75 , V_202 }
} ,
{ & V_130 ,
{ L_76 , L_65 ,
V_209 , V_201 , NULL , 0x0 ,
L_75 , V_202 }
} ,
{ & V_134 ,
{ L_77 , L_78 ,
V_209 , V_201 , NULL , 0x0 ,
L_79 , V_202 }
} ,
{ & V_132 ,
{ L_80 , L_81 ,
V_209 , V_201 , NULL , 0x0 ,
L_82 , V_202 }
} ,
{ & V_131 ,
{ L_83 , L_81 ,
V_209 , V_201 , NULL , 0x0 ,
L_82 , V_202 }
} ,
{ & V_163 ,
{ L_84 , L_85 ,
V_209 , V_201 , NULL , 0x0 ,
L_86 , V_202 }
} ,
{ & V_164 ,
{ L_87 , L_88 ,
V_209 , V_201 , NULL , 0x0 ,
L_89 , V_202 }
} ,
{ & V_165 ,
{ L_90 , L_91 ,
V_209 , V_201 , NULL , 0x0 ,
L_92 , V_202 }
} ,
{ & V_167 ,
{ L_93 , L_94 ,
V_209 , V_201 , NULL , 0x0 ,
L_95 , V_202 }
} ,
{ & V_166 ,
{ L_96 , L_97 ,
V_209 , V_201 , NULL , 0x0 ,
L_95 , V_202 }
} ,
{ & V_169 ,
{ L_98 , L_99 ,
V_209 , V_201 , NULL , 0x0 ,
L_100 , V_202 }
} ,
{ & V_168 ,
{ L_101 , L_102 ,
V_209 , V_201 , NULL , 0x0 ,
L_100 , V_202 }
} ,
{ & V_170 ,
{ L_103 , L_104 ,
V_209 , V_201 , NULL , 0x0 ,
L_105 , V_202 }
} ,
{ & V_110 ,
{ L_106 , L_107 ,
V_209 , V_201 , NULL , 0x0 ,
L_108 , V_202 }
} ,
{ & V_112 ,
{ L_109 , L_110 ,
V_209 , V_201 , NULL , 0x0 ,
L_111 , V_202 }
} ,
{ & V_111 ,
{ L_112 , L_113 ,
V_209 , V_201 , NULL , 0x0 ,
L_111 , V_202 }
} ,
{ & V_151 ,
{ L_114 , L_115 ,
V_209 , V_201 , NULL , 0x0 ,
L_116 , V_202 }
} ,
{ & V_150 ,
{ L_117 , L_118 ,
V_209 , V_201 , NULL , 0x0 ,
L_116 , V_202 }
} ,
{ & V_177 ,
{ L_119 , L_120 ,
V_209 , V_201 , NULL , 0x0 ,
L_121 , V_202 }
} ,
{ & V_176 ,
{ L_122 , L_123 ,
V_209 , V_201 , NULL , 0x0 ,
L_121 , V_202 }
} ,
{ & V_179 ,
{ L_124 , L_125 ,
V_209 , V_201 , NULL , 0x0 ,
L_126 , V_202 }
} ,
{ & V_178 ,
{ L_127 , L_128 ,
V_209 , V_201 , NULL , 0x0 ,
L_126 , V_202 }
} ,
{ & V_181 ,
{ L_129 , L_130 ,
V_209 , V_201 , NULL , 0x0 ,
L_131 , V_202 }
} ,
{ & V_172 ,
{ L_132 , L_133 ,
V_209 , V_201 , NULL , 0x0 ,
L_134 , V_202 }
} ,
{ & V_173 ,
{ L_135 , L_136 ,
V_209 , V_201 , NULL , 0x0 ,
L_137 , V_202 }
} ,
{ & V_182 ,
{ L_138 , L_139 ,
V_209 , V_201 , NULL , 0x0 ,
L_140 , V_202 }
} ,
{ & V_125 ,
{ L_141 , L_142 ,
V_209 , V_201 , NULL , 0x0 ,
L_143 , V_202 }
} ,
{ & V_128 ,
{ L_144 , L_145 ,
V_209 , V_201 , NULL , 0x0 ,
L_146 , V_202 }
} ,
{ & V_158 ,
{ L_147 , L_148 ,
V_209 , V_201 , NULL , 0x0 ,
L_149 , V_202 }
} ,
{ & V_159 ,
{ L_150 , L_151 ,
V_209 , V_201 , NULL , 0x0 ,
L_152 , V_202 }
} ,
{ & V_160 ,
{ L_153 , L_154 ,
V_209 , V_201 , NULL , 0x0 ,
L_155 , V_202 }
} ,
{ & V_161 ,
{ L_156 , L_157 ,
V_209 , V_201 , NULL , 0x0 ,
L_158 , V_202 }
} ,
{ & V_143 ,
{ L_159 , L_160 ,
V_209 , V_201 , NULL , 0x0 ,
L_161 , V_202 }
} ,
{ & V_141 ,
{ L_162 , L_163 ,
V_209 , V_201 , NULL , 0x0 ,
L_164 , V_202 }
} ,
{ & V_140 ,
{ L_165 , L_166 ,
V_209 , V_201 , NULL , 0x0 ,
L_164 , V_202 }
} ,
{ & V_76 ,
{ L_167 , L_168 ,
V_200 , V_201 , NULL , 0x0f ,
NULL , V_202 }
} ,
{ & V_77 ,
{ L_169 , L_170 ,
V_200 , V_201 , F_47 ( V_81 ) , 0x0 ,
L_171 , V_202 }
} ,
{ & V_78 ,
{ L_172 , L_173 ,
V_200 , V_201 , F_47 ( V_82 ) , 0x0 ,
L_174 , V_202 }
} ,
{ & V_83 ,
{ L_175 , L_176 ,
V_209 , V_201 , NULL , 0x0 ,
L_177 , V_202 }
} ,
{ & V_84 ,
{ L_178 , L_179 ,
V_205 , V_206 , NULL , 0x0 ,
L_180 , V_202 }
} ,
{ & V_88 ,
{ L_181 , L_182 ,
V_205 , V_206 , NULL , 0x0 ,
L_183 , V_202 }
} ,
{ & V_90 ,
{ L_184 , L_185 ,
V_200 , V_201 , NULL , 0x0 ,
L_186 , V_202 }
} ,
{ & V_92 ,
{ L_187 , L_188 ,
V_209 , V_201 , NULL , 0x0 ,
NULL , V_202 }
} ,
} ;
static T_8 * V_216 [] = {
& V_27 ,
& V_96 ,
& V_69 ,
} ;
static T_8 * V_217 [] = {
& V_197 ,
} ;
T_15 * V_218 ;
static T_16 V_219 [] = {
{ L_189 , L_190 , 0 } ,
{ L_191 , L_192 , 1 } ,
{ L_193 , L_194 , 2 } ,
{ L_195 , L_196 , 3 } ,
{ NULL , NULL , - 1 }
} ;
V_25 = F_48 ( L_197 ,
L_1 , L_198 ) ;
V_196 = F_48 ( L_199 ,
L_200 , L_201 ) ;
F_49 ( L_198 , F_18 , V_25 ) ;
F_50 ( V_25 , V_199 , F_51 ( V_199 ) ) ;
F_52 ( V_216 , F_51 ( V_216 ) ) ;
F_52 ( V_217 , F_51 ( V_217 ) ) ;
V_218 = F_53 ( V_25 ,
V_198 ) ;
F_54 ( V_218 , L_202 ,
L_203 ,
L_204 ,
10 ,
& V_220 ) ;
F_54 ( V_218 , L_205 ,
L_206 ,
L_207 ,
10 ,
& V_221 ) ;
F_54 ( V_218 , L_208 ,
L_209 ,
L_210 ,
10 ,
& V_222 ) ;
F_54 ( V_218 , L_211 ,
L_212 ,
L_213 ,
10 ,
& V_223 ) ;
F_55 ( V_218 , L_214 ,
L_215 ,
L_216 ,
& V_97 ) ;
F_55 ( V_218 , L_217 ,
L_218 ,
L_219
L_220 ,
& V_187 ) ;
F_55 ( V_218 , L_221 ,
L_222 ,
L_223 ,
& V_64 ) ;
F_55 ( V_218 , L_224 ,
L_225 ,
L_226
L_227 ,
& V_72 ) ;
F_56 ( V_218 , L_228 ,
L_229 ,
L_230
L_231
L_232 ,
& V_28 , V_219 , FALSE ) ;
F_57 ( & F_1 ) ;
}
void
V_198 ( void )
{
static T_17 V_224 ;
static T_17 V_225 ;
static T_7 V_226 = FALSE ;
static T_10 V_227 ;
static T_10 V_228 ;
static T_10 V_229 ;
static T_10 V_230 ;
if ( ! V_226 ) {
V_224 = F_58 ( L_198 ) ;
V_225 = F_59 ( F_3 , V_25 ) ;
V_73 = F_58 ( L_233 ) ;
V_226 = TRUE ;
} else{
F_60 ( L_202 , V_227 , V_224 ) ;
F_60 ( L_202 , V_228 , V_224 ) ;
F_60 ( L_208 , V_229 , V_225 ) ;
F_60 ( L_208 , V_230 , V_225 ) ;
}
V_227 = V_220 ;
V_228 = V_221 ;
V_229 = V_222 ;
V_230 = V_223 ;
F_61 ( L_202 , V_220 , V_224 ) ;
F_61 ( L_202 , V_221 , V_224 ) ;
F_61 ( L_208 , V_222 , V_225 ) ;
F_61 ( L_208 , V_223 , V_225 ) ;
}
