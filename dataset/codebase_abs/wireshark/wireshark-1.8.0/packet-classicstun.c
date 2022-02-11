static int
F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 )
{
T_4 * V_4 ;
T_4 * V_5 ;
T_3 * V_6 ;
T_3 * V_7 ;
T_3 * V_8 ;
T_5 V_9 ;
T_5 V_10 ;
const char * V_11 ;
T_5 V_12 ;
T_5 V_13 ;
T_5 V_14 ;
T_6 V_15 ;
T_6 V_16 ;
T_7 * V_17 ;
T_8 * V_18 ;
T_9 * V_19 ;
T_10 V_20 [ 2 ] ;
T_11 V_21 [ 4 ] ;
V_15 = F_2 ( V_1 ) ;
if ( V_15 < V_22 )
return 0 ;
V_9 = F_3 ( V_1 , 0 ) ;
if ( V_9 & 0xC000 || F_4 ( V_1 , 4 ) == 0x2112a442
|| F_4 ( V_1 , 4 ) == 0x7f5a9bc7 )
return 0 ;
V_11 = F_5 ( V_9 , V_23 ) ;
if ( V_11 == NULL )
return 0 ;
V_10 = F_3 ( V_1 , 2 ) ;
if ( V_15 != V_22 + V_10 )
return 0 ;
V_21 [ 0 ] = F_4 ( V_1 , 4 ) ;
V_21 [ 1 ] = F_4 ( V_1 , 8 ) ;
V_21 [ 2 ] = F_4 ( V_1 , 12 ) ;
V_21 [ 3 ] = F_4 ( V_1 , 16 ) ;
V_20 [ 0 ] . V_24 = 4 ;
V_20 [ 0 ] . V_25 = V_21 ;
V_20 [ 1 ] . V_24 = 0 ;
V_20 [ 1 ] . V_25 = NULL ;
V_17 = F_6 ( V_2 ) ;
V_18 = F_7 ( V_17 , V_26 ) ;
if ( ! V_18 ) {
V_18 = F_8 ( sizeof( T_8 ) ) ;
V_18 -> V_27 = F_9 ( V_28 , L_1 ) ;
F_10 ( V_17 , V_26 , V_18 ) ;
}
if( ! V_2 -> V_29 -> V_30 . V_31 ) {
if ( ( ( V_9 & V_32 ) >> 4 ) == V_33 ) {
V_19 = F_8 ( sizeof( T_9 ) ) ;
V_19 -> V_34 = V_2 -> V_29 -> V_35 ;
V_19 -> V_36 = 0 ;
V_19 -> V_37 = V_2 -> V_29 -> V_38 ;
F_11 ( V_18 -> V_27 , V_20 ,
( void * ) V_19 ) ;
} else {
V_19 = F_12 ( V_18 -> V_27 ,
V_20 ) ;
if( V_19 ) {
V_19 -> V_36 = V_2 -> V_29 -> V_35 ;
}
}
} else {
V_19 = F_12 ( V_18 -> V_27 , V_20 ) ;
}
if( ! V_19 ) {
V_19 = F_13 ( sizeof( T_9 ) ) ;
V_19 -> V_34 = 0 ;
V_19 -> V_36 = 0 ;
V_19 -> V_37 = V_2 -> V_29 -> V_38 ;
}
F_14 ( V_2 -> V_39 , V_40 , L_2 ) ;
F_15 ( V_2 -> V_39 , V_41 , L_3 ,
V_11 ) ;
if ( V_3 ) {
T_6 V_42 ;
V_4 = F_16 ( V_3 , V_26 , V_1 , 0 , - 1 , V_43 ) ;
V_6 = F_17 ( V_4 , V_44 ) ;
if ( ( ( V_9 & V_32 ) >> 4 ) == V_33 ) {
if ( V_19 -> V_36 ) {
T_4 * V_45 ;
V_45 = F_18 ( V_6 , V_46 ,
V_1 , 0 , 0 ,
V_19 -> V_36 ) ;
F_19 ( V_45 ) ;
}
}
else if ( ( ( ( V_9 & V_32 ) >> 4 ) == V_47 ) ||
( ( ( V_9 & V_32 ) >> 4 ) == V_48 ) ) {
if( V_19 -> V_34 ) {
T_4 * V_45 ;
T_12 V_49 ;
V_45 = F_18 ( V_6 , V_50 , V_1 , 0 , 0 , V_19 -> V_34 ) ;
F_19 ( V_45 ) ;
F_20 ( & V_49 , & V_2 -> V_29 -> V_38 , & V_19 -> V_37 ) ;
V_45 = F_21 ( V_6 , V_51 , V_1 , 0 , 0 , & V_49 ) ;
F_19 ( V_45 ) ;
}
}
F_18 ( V_6 , V_52 , V_1 , 0 , 2 , V_9 ) ;
F_18 ( V_6 , V_53 , V_1 , 2 , 2 , V_10 ) ;
F_16 ( V_6 , V_54 , V_1 , 4 , 16 , V_43 ) ;
V_42 = F_4 ( V_1 , 4 ) ;
if ( V_10 > 0 ) {
V_5 = F_16 ( V_6 , V_55 , V_1 , V_22 , V_10 , V_43 ) ;
V_7 = F_17 ( V_5 , V_56 ) ;
V_14 = V_22 ;
while( V_10 > 0 ) {
V_12 = F_3 ( V_1 , V_14 ) ;
V_13 = F_3 ( V_1 , V_14 + 2 ) ;
V_5 = F_22 ( V_7 , V_1 , V_14 ,
V_57 + V_13 ,
L_4 ,
F_23 ( V_12 , V_58 , L_5 ) ) ;
V_8 = F_17 ( V_5 , V_59 ) ;
F_18 ( V_8 , V_60 , V_1 ,
V_14 , 2 , V_12 ) ;
V_14 += 2 ;
if ( V_57 + V_13 > V_10 ) {
F_24 ( V_8 ,
V_61 , V_1 , V_14 , 2 ,
V_13 ,
L_6 ,
V_13 ) ;
break;
}
F_18 ( V_8 , V_61 , V_1 ,
V_14 , 2 , V_13 ) ;
V_14 += 2 ;
switch( V_12 ) {
case V_62 :
case V_63 :
case V_64 :
case V_65 :
case V_66 :
case V_67 :
case V_68 :
case V_69 :
if ( V_13 < 2 )
break;
F_16 ( V_8 , V_70 , V_1 , V_14 + 1 , 1 , V_71 ) ;
if ( V_13 < 4 )
break;
F_16 ( V_8 , V_72 , V_1 , V_14 + 2 , 2 , V_71 ) ;
switch( F_25 ( V_1 , V_14 + 1 ) ) {
case 1 :
if ( V_13 < 8 )
break;
F_16 ( V_8 , V_73 , V_1 , V_14 + 4 , 4 , V_71 ) ;
break;
case 2 :
if ( V_13 < 20 )
break;
F_16 ( V_8 , V_74 , V_1 , V_14 + 4 , 16 , V_43 ) ;
break;
}
break;
case V_75 :
if ( V_13 < 4 )
break;
F_16 ( V_8 , V_76 , V_1 , V_14 , 4 , V_71 ) ;
F_16 ( V_8 , V_77 , V_1 , V_14 , 4 , V_71 ) ;
break;
case V_78 :
case V_79 :
case V_80 :
case V_81 :
case V_82 :
if ( V_13 < 1 )
break;
F_16 ( V_8 , V_83 , V_1 , V_14 , V_13 , V_43 ) ;
break;
case V_84 :
if ( V_13 < 3 )
break;
F_16 ( V_8 , V_85 , V_1 , V_14 + 2 , 1 , V_71 ) ;
if ( V_13 < 4 )
break;
F_16 ( V_8 , V_86 , V_1 , V_14 + 3 , 1 , V_71 ) ;
if ( V_13 < 5 )
break;
F_16 ( V_8 , V_87 , V_1 , V_14 + 4 , ( V_13 - 4 ) , V_88 | V_43 ) ;
break;
case V_89 :
if ( V_13 < 4 )
break;
F_16 ( V_8 , V_90 , V_1 , V_14 , 4 , V_71 ) ;
break;
case V_91 :
if ( V_13 < 4 )
break;
F_16 ( V_8 , V_92 , V_1 , V_14 , 4 , V_71 ) ;
break;
case V_93 :
if ( V_13 < 4 )
break;
F_16 ( V_8 , V_94 , V_1 , V_14 , 4 , V_71 ) ;
break;
case V_95 :
F_16 ( V_8 , V_96 , V_1 , V_14 , V_13 , V_43 ) ;
break;
case V_97 :
for ( V_16 = 0 ; V_16 < V_13 ; V_16 += 4 ) {
F_16 ( V_8 , V_98 , V_1 , V_14 + V_16 , 2 , V_71 ) ;
F_16 ( V_8 , V_98 , V_1 , V_14 + V_16 + 2 , 2 , V_71 ) ;
}
break;
case V_99 :
F_16 ( V_8 , V_100 , V_1 , V_14 , V_13 , V_88 | V_43 ) ;
break;
case V_101 :
if ( V_13 < 2 )
break;
F_16 ( V_8 , V_70 , V_1 , V_14 + 1 , 1 , V_71 ) ;
if ( V_13 < 4 )
break;
F_16 ( V_8 , V_102 , V_1 , V_14 + 2 , 2 , V_71 ) ;
V_4 = F_18 ( V_8 , V_72 , V_1 , V_14 + 2 , 2 ,
F_3 ( V_1 , V_14 + 2 ) ^
( V_42 >> 16 ) ) ;
F_19 ( V_4 ) ;
if ( V_13 < 8 )
break;
switch( F_25 ( V_1 , V_14 + 1 ) ) {
case 1 :
if ( V_13 < 8 )
break;
F_16 ( V_8 , V_103 , V_1 , V_14 + 4 , 4 , V_71 ) ;
V_4 = F_26 ( V_8 , V_73 , V_1 , V_14 + 4 , 4 ,
F_27 ( V_1 , V_14 + 4 ) ^ F_28 ( V_42 ) ) ;
F_19 ( V_4 ) ;
break;
case 2 :
if ( V_13 < 20 )
break;
F_16 ( V_8 , V_104 , V_1 , V_14 + 4 , 16 , V_43 ) ;
break;
}
break;
case V_105 :
if ( V_13 < 2 )
break;
F_16 ( V_8 , V_70 , V_1 , V_14 + 1 , 1 , V_71 ) ;
break;
case V_106 :
F_16 ( V_8 , V_107 , V_1 , V_14 , V_13 , V_88 | V_43 ) ;
break;
default:
break;
}
V_14 += V_13 ;
V_10 -= V_57 + V_13 ;
}
}
}
return F_2 ( V_1 ) ;
}
static T_13
F_29 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 )
{
if ( F_1 ( V_1 , V_2 , V_3 ) == 0 )
return FALSE ;
return TRUE ;
}
void
F_30 ( void )
{
static T_14 V_108 [] = {
{ & V_52 ,
{ L_7 , L_8 , V_109 ,
V_110 , F_31 ( V_23 ) , 0x0 , NULL , V_111 }
} ,
{ & V_53 ,
{ L_9 , L_10 , V_109 ,
V_110 , NULL , 0x0 , NULL , V_111 }
} ,
{ & V_54 ,
{ L_11 , L_12 , V_112 ,
V_113 , NULL , 0x0 , NULL , V_111 }
} ,
{ & V_55 ,
{ L_13 , L_14 , V_114 ,
V_113 , NULL , 0x0 , NULL , V_111 }
} ,
{ & V_46 ,
{ L_15 , L_16 ,
V_115 , V_113 , NULL , 0x0 ,
L_17 , V_111 } } ,
{ & V_50 ,
{ L_18 , L_19 ,
V_115 , V_113 , NULL , 0x0 ,
L_20 , V_111 } } ,
{ & V_51 ,
{ L_21 , L_22 ,
V_116 , V_113 , NULL , 0x0 ,
L_23 , V_111 } } ,
{ & V_60 ,
{ L_24 , L_25 , V_109 ,
V_110 , F_31 ( V_58 ) , 0x0 , NULL , V_111 }
} ,
{ & V_61 ,
{ L_26 , L_27 , V_109 ,
V_117 , NULL , 0x0 , NULL , V_111 }
} ,
{ & V_83 ,
{ L_28 , L_29 , V_112 ,
V_113 , NULL , 0x0 , NULL , V_111 }
} ,
{ & V_70 ,
{ L_30 , L_31 , V_109 ,
V_110 , F_31 ( V_118 ) , 0x0 , NULL , V_111 }
} ,
{ & V_73 ,
{ L_32 , L_33 , V_119 ,
V_113 , NULL , 0x0 , NULL , V_111 }
} ,
{ & V_74 ,
{ L_32 , L_34 , V_120 ,
V_113 , NULL , 0x0 , NULL , V_111 }
} ,
{ & V_72 ,
{ L_35 , L_36 , V_109 ,
V_117 , NULL , 0x0 , NULL , V_111 }
} ,
{ & V_76 ,
{ L_37 , L_38 , V_121 ,
16 , F_32 ( & V_122 ) , 0x0004 , NULL , V_111 }
} ,
{ & V_77 ,
{ L_39 , L_40 , V_121 ,
16 , F_32 ( & V_122 ) , 0x0002 , NULL , V_111 }
} ,
{ & V_98 ,
{ L_41 , L_42 , V_109 ,
V_110 , NULL , 0x0 , NULL , V_111 }
} ,
{ & V_85 ,
{ L_43 , L_44 , V_123 ,
V_117 , NULL , 0x07 , NULL , V_111 }
} ,
{ & V_86 ,
{ L_45 , L_46 , V_123 ,
V_117 , NULL , 0x0 , NULL , V_111 }
} ,
{ & V_87 ,
{ L_47 , L_48 , V_124 ,
V_113 , NULL , 0x0 , NULL , V_111 }
} ,
{ & V_103 ,
{ L_49 , L_50 , V_119 ,
V_113 , NULL , 0x0 , NULL , V_111 }
} ,
{ & V_104 ,
{ L_49 , L_51 , V_120 ,
V_113 , NULL , 0x0 , NULL , V_111 }
} ,
{ & V_102 ,
{ L_52 , L_53 , V_109 ,
V_117 , NULL , 0x0 , NULL , V_111 }
} ,
{ & V_100 ,
{ L_54 , L_55 , V_124 ,
V_113 , NULL , 0x0 , NULL , V_111 }
} ,
{ & V_90 ,
{ L_56 , L_57 , V_125 ,
V_117 , NULL , 0x0 , NULL , V_111 }
} ,
{ & V_92 ,
{ L_58 , L_59 , V_125 ,
V_110 , NULL , 0x0 , NULL , V_111 }
} ,
{ & V_94 ,
{ L_60 , L_61 , V_125 ,
V_117 , NULL , 0x0 , NULL , V_111 }
} ,
{ & V_96 ,
{ L_62 , L_63 , V_112 ,
V_113 , NULL , 0x0 , NULL , V_111 }
} ,
{ & V_107 ,
{ L_64 , L_65 , V_124 ,
V_113 , NULL , 0x0 , NULL , V_111 }
} ,
} ;
static T_15 * V_126 [] = {
& V_44 ,
& V_56 ,
& V_59 ,
} ;
V_26 = F_33 ( L_66 ,
L_67 , L_68 ) ;
F_34 ( V_26 , V_108 , F_35 ( V_108 ) ) ;
F_36 ( V_126 , F_35 ( V_126 ) ) ;
F_37 ( L_68 , F_1 , V_26 ) ;
F_37 ( L_69 , F_29 , V_26 ) ;
}
void
F_38 ( void )
{
#if 0
dissector_handle_t classicstun_handle;
classicstun_handle = find_dissector("classicstun");
dissector_add_uint("tcp.port", TCP_PORT_STUN, classicstun_handle);
dissector_add_uint("udp.port", UDP_PORT_STUN, classicstun_handle);
#endif
F_39 ( L_70 , F_29 , V_26 ) ;
F_39 ( L_71 , F_29 , V_26 ) ;
}
