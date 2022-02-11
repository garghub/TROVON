static int
F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , void * T_4 V_4 )
{
T_5 * V_5 ;
T_5 * V_6 ;
T_3 * V_7 ;
T_3 * V_8 ;
T_3 * V_9 ;
T_6 V_10 ;
T_6 V_11 ;
const char * V_12 ;
T_6 V_13 ;
T_6 V_14 ;
T_6 V_15 ;
T_7 V_16 ;
T_7 V_17 ;
T_8 * V_18 ;
T_9 * V_19 ;
T_10 * V_20 ;
T_11 V_21 [ 2 ] ;
T_12 V_22 [ 4 ] ;
V_16 = F_2 ( V_1 ) ;
if ( V_16 < V_23 )
return 0 ;
V_10 = F_3 ( V_1 , 0 ) ;
if ( V_10 & 0xC000 || F_4 ( V_1 , 4 ) == 0x2112a442
|| F_4 ( V_1 , 4 ) == 0x7f5a9bc7 )
return 0 ;
V_12 = F_5 ( V_10 , V_24 ) ;
if ( V_12 == NULL )
return 0 ;
V_11 = F_3 ( V_1 , 2 ) ;
if ( V_16 != V_23 + V_11 )
return 0 ;
V_22 [ 0 ] = F_4 ( V_1 , 4 ) ;
V_22 [ 1 ] = F_4 ( V_1 , 8 ) ;
V_22 [ 2 ] = F_4 ( V_1 , 12 ) ;
V_22 [ 3 ] = F_4 ( V_1 , 16 ) ;
V_21 [ 0 ] . V_25 = 4 ;
V_21 [ 0 ] . V_26 = V_22 ;
V_21 [ 1 ] . V_25 = 0 ;
V_21 [ 1 ] . V_26 = NULL ;
V_18 = F_6 ( V_2 ) ;
V_19 = ( T_9 * ) F_7 ( V_18 , V_27 ) ;
if ( ! V_19 ) {
V_19 = F_8 ( F_9 () , T_9 ) ;
V_19 -> V_28 = F_10 ( F_9 () ) ;
F_11 ( V_18 , V_27 , V_19 ) ;
}
if( ! V_2 -> V_29 -> V_30 . V_31 ) {
if ( ( ( V_10 & V_32 ) >> 4 ) == V_33 ) {
V_20 = F_8 ( F_9 () , T_10 ) ;
V_20 -> V_34 = V_2 -> V_29 -> V_35 ;
V_20 -> V_36 = 0 ;
V_20 -> V_37 = V_2 -> V_29 -> V_38 ;
F_12 ( V_19 -> V_28 , V_21 ,
( void * ) V_20 ) ;
} else {
V_20 = ( T_10 * ) F_13 ( V_19 -> V_28 ,
V_21 ) ;
if( V_20 ) {
V_20 -> V_36 = V_2 -> V_29 -> V_35 ;
}
}
} else {
V_20 = ( T_10 * ) F_13 ( V_19 -> V_28 , V_21 ) ;
}
if( ! V_20 ) {
V_20 = F_8 ( F_14 () , T_10 ) ;
V_20 -> V_34 = 0 ;
V_20 -> V_36 = 0 ;
V_20 -> V_37 = V_2 -> V_29 -> V_38 ;
}
F_15 ( V_2 -> V_39 , V_40 , L_1 ) ;
F_16 ( V_2 -> V_39 , V_41 , L_2 ,
V_12 ) ;
if ( V_3 ) {
T_7 V_42 ;
V_5 = F_17 ( V_3 , V_27 , V_1 , 0 , - 1 , V_43 ) ;
V_7 = F_18 ( V_5 , V_44 ) ;
if ( ( ( V_10 & V_32 ) >> 4 ) == V_33 ) {
if ( V_20 -> V_36 ) {
T_5 * V_45 ;
V_45 = F_19 ( V_7 , V_46 ,
V_1 , 0 , 0 ,
V_20 -> V_36 ) ;
F_20 ( V_45 ) ;
}
}
else if ( ( ( ( V_10 & V_32 ) >> 4 ) == V_47 ) ||
( ( ( V_10 & V_32 ) >> 4 ) == V_48 ) ) {
if( V_20 -> V_34 ) {
T_5 * V_45 ;
T_13 V_49 ;
V_45 = F_19 ( V_7 , V_50 , V_1 , 0 , 0 , V_20 -> V_34 ) ;
F_20 ( V_45 ) ;
F_21 ( & V_49 , & V_2 -> V_29 -> V_38 , & V_20 -> V_37 ) ;
V_45 = F_22 ( V_7 , V_51 , V_1 , 0 , 0 , & V_49 ) ;
F_20 ( V_45 ) ;
}
}
F_19 ( V_7 , V_52 , V_1 , 0 , 2 , V_10 ) ;
F_19 ( V_7 , V_53 , V_1 , 2 , 2 , V_11 ) ;
F_17 ( V_7 , V_54 , V_1 , 4 , 16 , V_43 ) ;
V_42 = F_4 ( V_1 , 4 ) ;
if ( V_11 > 0 ) {
V_6 = F_17 ( V_7 , V_55 , V_1 , V_23 , V_11 , V_43 ) ;
V_8 = F_18 ( V_6 , V_56 ) ;
V_15 = V_23 ;
while( V_11 > 0 ) {
V_13 = F_3 ( V_1 , V_15 ) ;
V_14 = F_3 ( V_1 , V_15 + 2 ) ;
V_9 = F_23 ( V_8 , V_1 , V_15 ,
V_57 + V_14 , V_58 , NULL ,
L_3 ,
F_24 ( V_13 , V_59 , L_4 ) ) ;
F_19 ( V_9 , V_60 , V_1 ,
V_15 , 2 , V_13 ) ;
V_15 += 2 ;
if ( V_57 + V_14 > V_11 ) {
F_25 ( V_9 ,
V_61 , V_1 , V_15 , 2 ,
V_14 ,
L_5 ,
V_14 ) ;
break;
}
F_19 ( V_9 , V_61 , V_1 ,
V_15 , 2 , V_14 ) ;
V_15 += 2 ;
switch( V_13 ) {
case V_62 :
case V_63 :
case V_64 :
case V_65 :
case V_66 :
case V_67 :
case V_68 :
case V_69 :
if ( V_14 < 2 )
break;
F_17 ( V_9 , V_70 , V_1 , V_15 + 1 , 1 , V_71 ) ;
if ( V_14 < 4 )
break;
F_17 ( V_9 , V_72 , V_1 , V_15 + 2 , 2 , V_71 ) ;
switch( F_26 ( V_1 , V_15 + 1 ) ) {
case 1 :
if ( V_14 < 8 )
break;
F_17 ( V_9 , V_73 , V_1 , V_15 + 4 , 4 , V_71 ) ;
break;
case 2 :
if ( V_14 < 20 )
break;
F_17 ( V_9 , V_74 , V_1 , V_15 + 4 , 16 , V_43 ) ;
break;
}
break;
case V_75 :
if ( V_14 < 4 )
break;
F_17 ( V_9 , V_76 , V_1 , V_15 , 4 , V_71 ) ;
F_17 ( V_9 , V_77 , V_1 , V_15 , 4 , V_71 ) ;
break;
case V_78 :
case V_79 :
case V_80 :
case V_81 :
case V_82 :
if ( V_14 < 1 )
break;
F_17 ( V_9 , V_83 , V_1 , V_15 , V_14 , V_43 ) ;
break;
case V_84 :
if ( V_14 < 3 )
break;
F_17 ( V_9 , V_85 , V_1 , V_15 + 2 , 1 , V_71 ) ;
if ( V_14 < 4 )
break;
F_17 ( V_9 , V_86 , V_1 , V_15 + 3 , 1 , V_71 ) ;
if ( V_14 < 5 )
break;
F_17 ( V_9 , V_87 , V_1 , V_15 + 4 , ( V_14 - 4 ) , V_88 | V_43 ) ;
break;
case V_89 :
if ( V_14 < 4 )
break;
F_17 ( V_9 , V_90 , V_1 , V_15 , 4 , V_71 ) ;
break;
case V_91 :
if ( V_14 < 4 )
break;
F_17 ( V_9 , V_92 , V_1 , V_15 , 4 , V_71 ) ;
break;
case V_93 :
if ( V_14 < 4 )
break;
F_17 ( V_9 , V_94 , V_1 , V_15 , 4 , V_71 ) ;
break;
case V_95 :
F_17 ( V_9 , V_96 , V_1 , V_15 , V_14 , V_43 ) ;
break;
case V_97 :
for ( V_17 = 0 ; V_17 < V_14 ; V_17 += 4 ) {
F_17 ( V_9 , V_98 , V_1 , V_15 + V_17 , 2 , V_71 ) ;
F_17 ( V_9 , V_98 , V_1 , V_15 + V_17 + 2 , 2 , V_71 ) ;
}
break;
case V_99 :
F_17 ( V_9 , V_100 , V_1 , V_15 , V_14 , V_88 | V_43 ) ;
break;
case V_101 :
if ( V_14 < 2 )
break;
F_17 ( V_9 , V_70 , V_1 , V_15 + 1 , 1 , V_71 ) ;
if ( V_14 < 4 )
break;
F_17 ( V_9 , V_102 , V_1 , V_15 + 2 , 2 , V_71 ) ;
V_5 = F_19 ( V_9 , V_72 , V_1 , V_15 + 2 , 2 ,
F_3 ( V_1 , V_15 + 2 ) ^
( V_42 >> 16 ) ) ;
F_20 ( V_5 ) ;
if ( V_14 < 8 )
break;
switch( F_26 ( V_1 , V_15 + 1 ) ) {
case 1 :
if ( V_14 < 8 )
break;
F_17 ( V_9 , V_103 , V_1 , V_15 + 4 , 4 , V_71 ) ;
V_5 = F_27 ( V_9 , V_73 , V_1 , V_15 + 4 , 4 ,
F_28 ( V_1 , V_15 + 4 ) ^ F_29 ( V_42 ) ) ;
F_20 ( V_5 ) ;
break;
case 2 :
if ( V_14 < 20 )
break;
F_17 ( V_9 , V_104 , V_1 , V_15 + 4 , 16 , V_43 ) ;
break;
}
break;
case V_105 :
if ( V_14 < 2 )
break;
F_17 ( V_9 , V_70 , V_1 , V_15 + 1 , 1 , V_71 ) ;
break;
case V_106 :
F_17 ( V_9 , V_107 , V_1 , V_15 , V_14 , V_88 | V_43 ) ;
break;
default:
break;
}
V_15 += V_14 ;
V_11 -= V_57 + V_14 ;
}
}
}
return F_30 ( V_1 ) ;
}
static T_14
F_31 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , void * T_4 V_4 )
{
if ( F_1 ( V_1 , V_2 , V_3 , NULL ) == 0 )
return FALSE ;
return TRUE ;
}
void
F_32 ( void )
{
static T_15 V_108 [] = {
{ & V_52 ,
{ L_6 , L_7 , V_109 ,
V_110 , F_33 ( V_24 ) , 0x0 , NULL , V_111 }
} ,
{ & V_53 ,
{ L_8 , L_9 , V_109 ,
V_110 , NULL , 0x0 , NULL , V_111 }
} ,
{ & V_54 ,
{ L_10 , L_11 , V_112 ,
V_113 , NULL , 0x0 , NULL , V_111 }
} ,
{ & V_55 ,
{ L_12 , L_13 , V_114 ,
V_113 , NULL , 0x0 , NULL , V_111 }
} ,
{ & V_46 ,
{ L_14 , L_15 ,
V_115 , V_113 , NULL , 0x0 ,
L_16 , V_111 } } ,
{ & V_50 ,
{ L_17 , L_18 ,
V_115 , V_113 , NULL , 0x0 ,
L_19 , V_111 } } ,
{ & V_51 ,
{ L_20 , L_21 ,
V_116 , V_113 , NULL , 0x0 ,
L_22 , V_111 } } ,
{ & V_60 ,
{ L_23 , L_24 , V_109 ,
V_110 , F_33 ( V_59 ) , 0x0 , NULL , V_111 }
} ,
{ & V_61 ,
{ L_25 , L_26 , V_109 ,
V_117 , NULL , 0x0 , NULL , V_111 }
} ,
{ & V_83 ,
{ L_27 , L_28 , V_112 ,
V_113 , NULL , 0x0 , NULL , V_111 }
} ,
{ & V_70 ,
{ L_29 , L_30 , V_109 ,
V_110 , F_33 ( V_118 ) , 0x0 , NULL , V_111 }
} ,
{ & V_73 ,
{ L_31 , L_32 , V_119 ,
V_113 , NULL , 0x0 , NULL , V_111 }
} ,
{ & V_74 ,
{ L_31 , L_33 , V_120 ,
V_113 , NULL , 0x0 , NULL , V_111 }
} ,
{ & V_72 ,
{ L_34 , L_35 , V_109 ,
V_117 , NULL , 0x0 , NULL , V_111 }
} ,
{ & V_76 ,
{ L_36 , L_37 , V_121 ,
16 , F_34 ( & V_122 ) , 0x0004 , NULL , V_111 }
} ,
{ & V_77 ,
{ L_38 , L_39 , V_121 ,
16 , F_34 ( & V_122 ) , 0x0002 , NULL , V_111 }
} ,
{ & V_98 ,
{ L_40 , L_41 , V_109 ,
V_110 , NULL , 0x0 , NULL , V_111 }
} ,
{ & V_85 ,
{ L_42 , L_43 , V_123 ,
V_117 , NULL , 0x07 , NULL , V_111 }
} ,
{ & V_86 ,
{ L_44 , L_45 , V_123 ,
V_117 , NULL , 0x0 , NULL , V_111 }
} ,
{ & V_87 ,
{ L_46 , L_47 , V_124 ,
V_113 , NULL , 0x0 , NULL , V_111 }
} ,
{ & V_103 ,
{ L_48 , L_49 , V_119 ,
V_113 , NULL , 0x0 , NULL , V_111 }
} ,
{ & V_104 ,
{ L_48 , L_50 , V_120 ,
V_113 , NULL , 0x0 , NULL , V_111 }
} ,
{ & V_102 ,
{ L_51 , L_52 , V_109 ,
V_117 , NULL , 0x0 , NULL , V_111 }
} ,
{ & V_100 ,
{ L_53 , L_54 , V_124 ,
V_113 , NULL , 0x0 , NULL , V_111 }
} ,
{ & V_90 ,
{ L_55 , L_56 , V_125 ,
V_117 , NULL , 0x0 , NULL , V_111 }
} ,
{ & V_92 ,
{ L_57 , L_58 , V_125 ,
V_110 , NULL , 0x0 , NULL , V_111 }
} ,
{ & V_94 ,
{ L_59 , L_60 , V_125 ,
V_117 , NULL , 0x0 , NULL , V_111 }
} ,
{ & V_96 ,
{ L_61 , L_62 , V_112 ,
V_113 , NULL , 0x0 , NULL , V_111 }
} ,
{ & V_107 ,
{ L_63 , L_64 , V_124 ,
V_113 , NULL , 0x0 , NULL , V_111 }
} ,
} ;
static T_16 * V_126 [] = {
& V_44 ,
& V_56 ,
& V_58 ,
} ;
V_27 = F_35 ( L_65 ,
L_66 , L_67 ) ;
F_36 ( V_27 , V_108 , F_37 ( V_108 ) ) ;
F_38 ( V_126 , F_37 ( V_126 ) ) ;
F_39 ( L_67 , F_1 , V_27 ) ;
F_39 ( L_68 , F_31 , V_27 ) ;
}
void
F_40 ( void )
{
#if 0
dissector_handle_t classicstun_handle;
classicstun_handle = find_dissector("classicstun");
dissector_add_uint("tcp.port", TCP_PORT_STUN, classicstun_handle);
dissector_add_uint("udp.port", UDP_PORT_STUN, classicstun_handle);
#endif
F_41 ( L_69 , F_31 , L_70 , L_71 , V_27 , V_127 ) ;
F_41 ( L_72 , F_31 , L_73 , L_74 , V_27 , V_127 ) ;
}
