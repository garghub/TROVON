static void
F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 )
{
T_4 * V_4 = NULL ;
T_3 * V_5 = NULL ;
T_5 V_6 ;
T_5 V_7 ;
T_6 V_8 ;
int V_9 = 0 ;
T_5 V_10 , V_11 = 0 ;
T_1 * V_12 ;
T_7 * V_13 ;
T_8 * V_14 ;
void * V_15 ;
T_9 * V_16 ;
T_10 V_17 [ 5 ] ;
T_11 V_18 ;
T_11 V_19 ;
T_11 V_20 ;
T_11 V_21 ;
T_12 * V_22 ;
const T_13 * V_23 ;
T_14 V_24 [ 6 ] ;
const T_13 * V_25 ;
T_13 * V_26 ;
T_15 V_27 ;
T_16 * V_28 ;
T_17 * V_29 ;
switch ( V_2 -> V_30 ) {
case V_31 :
F_2 ( V_2 -> V_32 , V_33 , L_1 ) ;
break;
case V_34 :
F_2 ( V_2 -> V_32 , V_33 , L_2 ) ;
break;
default:
F_3 ( V_2 -> V_32 , V_33 , L_3 ,
V_2 -> V_30 ) ;
break;
}
F_4 ( V_2 -> V_32 , V_35 , L_4 ) ;
if ( V_3 ) {
V_4 = F_5 ( V_3 , V_36 , V_1 , V_9 , - 1 , V_37 ) ;
V_5 = F_6 ( V_4 , V_38 ) ;
}
V_6 = F_7 ( V_1 , V_9 ) ;
V_10 = ( V_6 & 0x3000 ) >> 12 ;
F_5 ( V_5 , V_39 , V_1 , V_9 , 2 , V_40 ) ;
F_5 ( V_5 , V_41 , V_1 , V_9 , 2 , V_40 ) ;
F_5 ( V_5 , V_42 , V_1 , V_9 , 2 , V_40 ) ;
V_9 += 2 ;
V_16 = ( T_9 * ) V_2 -> V_43 ;
V_13 = F_8 ( F_9 () , T_7 ) ;
V_13 -> V_44 = V_16 -> V_44 ;
V_13 -> V_45 = V_16 -> V_45 ;
V_13 -> V_46 = V_6 & 0x0fff ;
V_13 -> V_47 = 0 ;
V_13 -> V_48 = 0 ;
V_15 = V_2 -> V_43 ;
V_2 -> V_43 = V_13 ;
V_20 = V_16 -> V_44 ;
V_21 = V_16 -> V_45 ;
V_18 = V_6 & 0x0fff ;
V_19 = V_2 -> V_49 -> V_50 ;
V_17 [ 0 ] . V_7 = 1 ;
V_17 [ 0 ] . V_17 = & V_20 ;
V_17 [ 1 ] . V_7 = 1 ;
V_17 [ 1 ] . V_17 = & V_21 ;
V_17 [ 2 ] . V_7 = 1 ;
V_17 [ 2 ] . V_17 = & V_18 ;
V_17 [ 3 ] . V_7 = 1 ;
V_17 [ 3 ] . V_17 = & V_19 ;
V_17 [ 4 ] . V_7 = 0 ;
V_17 [ 4 ] . V_17 = NULL ;
V_22 = ( T_12 * ) F_10 ( V_16 -> V_51 , V_17 ) ;
if ( V_22 && V_22 -> V_44 == V_16 -> V_44 &&
V_22 -> V_45 == V_16 -> V_45 &&
V_22 -> V_46 == ( V_6 & 0x0fff ) ) {
T_11 V_52 ;
T_11 V_53 ;
T_11 V_54 ;
T_11 V_55 ;
T_18 * V_56 ;
const T_13 * V_57 ;
const T_13 * V_58 ;
T_13 * V_59 ;
T_15 V_60 ;
V_54 = V_22 -> V_61 [ 0 ] << 16 | V_22 -> V_61 [ 1 ] << 8 | V_22 -> V_61 [ 2 ] ;
V_55 = V_22 -> V_61 [ 3 ] << 16 | V_22 -> V_61 [ 4 ] << 8 | V_22 -> V_61 [ 5 ] ;
V_13 -> V_47 = V_54 ;
V_13 -> V_48 = V_55 ;
V_52 = V_54 ;
V_53 = V_55 ;
V_19 = V_2 -> V_49 -> V_50 ;
V_17 [ 0 ] . V_7 = 1 ;
V_17 [ 0 ] . V_17 = & V_53 ;
V_17 [ 1 ] . V_7 = 1 ;
V_17 [ 1 ] . V_17 = & V_52 ;
V_17 [ 2 ] . V_7 = 1 ;
V_17 [ 2 ] . V_17 = & V_19 ;
V_17 [ 3 ] . V_7 = 0 ;
V_17 [ 3 ] . V_17 = NULL ;
V_56 = ( T_18 * ) F_10 ( V_16 -> V_62 , V_17 ) ;
if ( V_56 && V_56 -> V_54 == V_54 && V_56 -> V_55 == V_55 )
V_57 = V_56 -> V_63 ;
else
V_57 = L_5 ;
V_58 = F_11 ( V_22 -> V_61 ) ;
V_60 = ( T_15 ) ( strlen ( V_58 ) + 3 + strlen ( V_57 ) + 1 ) ;
V_59 = ( T_13 * ) F_12 ( V_2 -> V_64 , V_60 ) ;
F_13 ( V_59 , V_60 , L_6 , V_58 , V_57 ) ;
if ( V_2 -> V_30 == V_34 ) {
F_14 ( & V_2 -> V_65 , V_66 , ( int ) strlen ( V_57 ) + 1 , V_57 ) ;
F_14 ( & V_2 -> V_67 , V_68 , 6 , V_22 -> V_61 ) ;
F_14 ( & V_2 -> V_69 , V_66 , ( int ) strlen ( V_59 ) + 1 , V_59 ) ;
} else if ( V_2 -> V_30 == V_31 ) {
F_14 ( & V_2 -> V_70 , V_66 , ( int ) strlen ( V_57 ) + 1 , V_57 ) ;
F_14 ( & V_2 -> V_71 , V_68 , 6 , V_22 -> V_61 ) ;
F_14 ( & V_2 -> V_72 , V_66 , ( int ) strlen ( V_59 ) + 1 , V_59 ) ;
}
} else {
if ( V_2 -> V_30 == V_34 ) {
F_14 ( & V_2 -> V_65 , V_66 , 1 , L_5 ) ;
F_14 ( & V_2 -> V_67 , V_66 , 1 , L_5 ) ;
F_14 ( & V_2 -> V_69 , V_66 , 10 , L_7 ) ;
} else if ( V_2 -> V_30 == V_31 ) {
F_14 ( & V_2 -> V_70 , V_66 , 1 , L_5 ) ;
F_14 ( & V_2 -> V_71 , V_66 , 1 , L_5 ) ;
F_14 ( & V_2 -> V_72 , V_66 , 10 , L_7 ) ;
}
}
V_20 = V_16 -> V_44 ;
V_21 = V_16 -> V_45 ;
V_19 = V_2 -> V_49 -> V_50 ;
V_17 [ 0 ] . V_7 = 1 ;
V_17 [ 0 ] . V_17 = & V_20 ;
V_17 [ 1 ] . V_7 = 1 ;
V_17 [ 1 ] . V_17 = & V_21 ;
V_17 [ 2 ] . V_7 = 1 ;
V_17 [ 2 ] . V_17 = & V_19 ;
V_17 [ 3 ] . V_7 = 0 ;
V_17 [ 3 ] . V_17 = NULL ;
V_28 = ( T_16 * ) F_10 ( V_16 -> V_24 , V_17 ) ;
if ( V_28 && V_28 -> V_44 == V_16 -> V_44 &&
V_28 -> V_45 == V_16 -> V_45 )
V_25 = F_11 ( V_28 -> V_61 ) ;
else
V_25 = L_8 ;
V_29 = ( T_17 * ) F_10 ( V_16 -> V_23 , V_17 ) ;
if ( V_29 && V_29 -> V_44 == V_16 -> V_44 &&
V_29 -> V_45 == V_16 -> V_45 )
V_23 = V_29 -> V_63 ;
else
V_23 = L_5 ;
V_27 = ( T_15 ) ( strlen ( V_25 ) + 3 + strlen ( V_23 ) + 1 ) ;
V_26 = ( T_13 * ) F_12 ( V_2 -> V_64 , V_27 ) ;
F_13 ( V_26 , V_27 , L_6 , V_25 , V_23 ) ;
if ( V_2 -> V_30 == V_34 ) {
F_14 ( & V_2 -> V_70 , V_66 , ( int ) strlen ( V_23 ) + 1 , V_23 ) ;
F_14 ( & V_2 -> V_71 , V_68 , 6 , V_24 ) ;
F_14 ( & V_2 -> V_72 , V_66 , ( int ) strlen ( V_26 ) + 1 , V_26 ) ;
} else if ( V_2 -> V_30 == V_31 ) {
F_14 ( & V_2 -> V_65 , V_66 , ( int ) strlen ( V_23 ) + 1 , V_23 ) ;
F_14 ( & V_2 -> V_67 , V_68 , 6 , V_24 ) ;
F_14 ( & V_2 -> V_69 , V_66 , ( int ) strlen ( V_26 ) + 1 , V_26 ) ;
}
V_20 = V_16 -> V_44 ;
V_21 = V_16 -> V_45 ;
V_18 = V_6 & 0x0fff ;
V_19 = V_2 -> V_49 -> V_50 ;
V_17 [ 0 ] . V_7 = 1 ;
V_17 [ 0 ] . V_17 = & V_20 ;
V_17 [ 1 ] . V_7 = 1 ;
V_17 [ 1 ] . V_17 = & V_21 ;
V_17 [ 2 ] . V_7 = 1 ;
V_17 [ 2 ] . V_17 = & V_18 ;
V_17 [ 3 ] . V_7 = 1 ;
V_17 [ 3 ] . V_17 = & V_19 ;
V_17 [ 4 ] . V_7 = 0 ;
V_17 [ 4 ] . V_17 = NULL ;
V_14 = ( T_8 * ) F_10 ( V_73 , V_17 ) ;
if ( ! ( V_14 && V_14 -> V_44 == V_16 -> V_44 &&
V_14 -> V_45 == V_16 -> V_45 &&
V_14 -> V_46 == ( V_6 & 0x0fff ) ) ) {
V_20 = V_16 -> V_44 ;
V_21 = V_16 -> V_45 ;
V_18 = V_6 & 0x0fff ;
V_19 = V_2 -> V_49 -> V_50 ;
V_17 [ 0 ] . V_7 = 1 ;
V_17 [ 0 ] . V_17 = & V_20 ;
V_17 [ 1 ] . V_7 = 1 ;
V_17 [ 1 ] . V_17 = & V_21 ;
V_17 [ 2 ] . V_7 = 1 ;
V_17 [ 2 ] . V_17 = & V_18 ;
V_17 [ 3 ] . V_7 = 1 ;
V_17 [ 3 ] . V_17 = & V_19 ;
V_17 [ 4 ] . V_7 = 0 ;
V_17 [ 4 ] . V_17 = NULL ;
V_14 = ( T_8 * ) F_15 ( sizeof( T_8 ) ) ;
V_14 -> V_74 = F_16 ( V_75 , L_9 ) ;
V_14 -> V_44 = V_16 -> V_44 ;
V_14 -> V_45 = V_16 -> V_45 ;
V_14 -> V_46 = V_6 & 0x0fff ;
F_17 ( V_73 , V_17 , V_14 ) ;
}
V_7 = F_7 ( V_1 , V_9 ) ;
F_5 ( V_5 , V_76 , V_1 , V_9 , 2 , V_40 ) ;
V_9 += 2 ;
switch( V_10 ) {
case 0x01 :
V_8 = TRUE ;
break;
case 0x00 :
case 0x02 :
V_11 = F_7 ( V_1 , V_9 ) ;
V_8 = ( V_11 + 4 != V_7 ) ;
break;
default:
V_8 = FALSE ;
}
if ( ! V_8 || ( ! V_77 && ! ( V_10 & 0x01 ) ) ) {
V_12 = F_18 ( V_1 , V_9 , F_19 ( V_1 , V_9 ) , V_7 ) ;
if ( V_78 ) {
F_20 ( V_78 , V_12 , V_2 , V_3 ) ;
}
V_2 -> V_43 = V_15 ;
return;
}
if ( V_8 && V_77 ) {
T_19 * V_79 = NULL ;
T_15 V_80 ;
if ( ! ( V_10 & 0x01 ) ) {
if ( ! V_2 -> V_49 -> V_6 . V_81 ) {
V_79 = ( T_19 * ) F_8 ( F_21 () , T_19 ) ;
V_79 -> V_82 = V_2 -> V_49 -> V_50 ;
V_79 -> V_83 = 0 ;
V_79 -> V_84 = V_11 + 4 ;
V_79 -> V_85 = ( char * ) F_12 ( F_21 () , V_79 -> V_84 ) ;
V_80 = F_19 ( V_1 , V_9 ) ;
if ( V_80 <= V_79 -> V_84 ) {
F_22 ( V_1 , ( T_14 * ) V_79 -> V_85 , V_9 , V_80 ) ;
V_79 -> V_86 = V_80 ;
F_23 ( V_14 -> V_74 , V_2 -> V_49 -> V_50 , V_79 ) ;
}
} else {
V_79 = ( T_19 * ) F_24 ( V_14 -> V_74 , V_2 -> V_49 -> V_50 ) ;
}
if ( V_79 != NULL && V_79 -> V_83 ) {
T_4 * V_87 ;
V_87 = F_25 ( V_5 , V_88 , V_1 , 0 , 0 , V_79 -> V_83 ) ;
F_26 ( V_87 ) ;
F_27 ( V_2 -> V_32 , V_33 , L_10 , V_79 -> V_83 ) ;
}
}
if ( V_10 == 0x01 ) {
V_79 = ( T_19 * ) F_28 ( V_14 -> V_74 , V_2 -> V_49 -> V_50 ) ;
if ( ! V_2 -> V_49 -> V_6 . V_81 ) {
V_80 = F_19 ( V_1 , V_9 ) ;
if ( V_79 != NULL && ! V_79 -> V_83 && ( V_79 -> V_84 >= V_79 -> V_86 + V_80 ) ) {
F_22 ( V_1 , ( T_14 * ) V_79 -> V_85 + V_79 -> V_86 , V_9 , V_80 ) ;
V_79 -> V_86 += V_80 ;
if ( V_79 -> V_86 == V_79 -> V_84 ) {
V_79 -> V_83 = V_2 -> V_49 -> V_50 ;
}
}
}
if ( V_79 ) {
T_4 * V_87 ;
V_87 = F_25 ( V_5 , V_89 , V_1 , 0 , 0 , V_79 -> V_82 ) ;
F_26 ( V_87 ) ;
F_27 ( V_2 -> V_32 , V_33 , L_11 , V_79 -> V_82 ) ;
}
if ( V_79 != NULL && V_79 -> V_83 == V_2 -> V_49 -> V_50 ) {
V_12 = F_29 ( V_1 , ( T_14 * ) V_79 -> V_85 , V_79 -> V_84 , V_79 -> V_84 ) ;
F_30 ( V_2 , V_12 , L_12 ) ;
if ( V_78 ) {
F_20 ( V_78 , V_12 , V_2 , V_3 ) ;
}
}
}
}
V_2 -> V_43 = V_15 ;
}
void
F_31 ( void )
{
static T_20 V_90 [] = {
{ & V_39 ,
{ L_13 , L_14 ,
V_91 , V_92 , NULL , 0x0FFF ,
NULL , V_93 }
} ,
{ & V_41 ,
{ L_15 , L_16 ,
V_91 , V_94 , F_32 ( V_95 ) , 0x3000 ,
L_17 , V_93 }
} ,
{ & V_42 ,
{ L_18 , L_19 ,
V_91 , V_94 , F_32 ( V_96 ) , 0xC000 ,
L_20 , V_93 }
} ,
{ & V_76 ,
{ L_21 , L_22 ,
V_91 , V_94 , NULL , 0x0 ,
NULL , V_93 }
} ,
#if 0
{ &hf_bthci_acl_data,
{ "Data", "bthci_acl.data",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
#endif
{ & V_89 ,
{ L_23 , L_24 ,
V_97 , V_98 , NULL , 0x0 ,
L_25 , V_93 }
} ,
{ & V_88 ,
{ L_26 , L_27 ,
V_97 , V_98 , NULL , 0x0 ,
L_28 , V_93 }
} ,
} ;
static T_15 * V_99 [] = {
& V_38 ,
} ;
T_21 * V_100 ;
V_36 = F_33 ( L_29 , L_4 , L_30 ) ;
F_34 ( L_30 , F_1 , V_36 ) ;
F_35 ( V_36 , V_90 , F_36 ( V_90 ) ) ;
F_37 ( V_99 , F_36 ( V_99 ) ) ;
V_100 = F_38 ( V_36 , NULL ) ;
F_39 ( V_100 , L_31 ,
L_32 ,
L_33 ,
& V_77 ) ;
V_73 = F_40 ( V_75 , L_34 ) ;
}
void
F_41 ( void )
{
T_22 V_101 ;
V_101 = F_42 ( L_30 ) ;
F_43 ( L_35 , V_102 , V_101 ) ;
F_43 ( L_36 , V_103 , V_101 ) ;
V_78 = F_42 ( L_37 ) ;
}
