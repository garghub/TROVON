static void F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 V_3 ) {
T_4 V_4 , V_5 ;
if ( ( V_4 = ( F_2 ( V_2 ) ) / 4 - V_3 ) ) {
V_1 = F_3 ( V_1 , V_2 , 0 , V_4 * 4 , V_6 , NULL , L_1 ) ;
for ( V_5 = 0 ; V_5 < V_4 ; V_5 ++ ) {
F_4 ( V_1 , V_7 , V_2 , V_5 * 4 + 1 , 3 , V_8 ) ;
}
}
}
extern void
F_5 ( T_2 * V_2 , T_5 * V_9 , T_1 * V_1 , T_6 V_10 )
{
T_3 V_11 ;
T_7 * V_12 ;
T_1 * V_13 = NULL ;
T_8 V_14 ;
int V_15 ;
int V_16 ;
T_2 * V_17 ;
V_11 = F_2 ( V_2 ) ;
V_14 = F_6 ( V_2 , V_18 ) ;
V_19 . type = V_14 & V_20 ;
F_7 ( V_9 -> V_21 , V_22 , L_2 ) ;
F_8 ( V_9 -> V_21 , V_23 , F_9 ( V_19 . type , & V_24 ,
L_3 ) ) ;
switch ( V_19 . type ) {
case V_25 :
V_16 = ( V_14 >> 6 ) & 0x03 ;
V_15 = 4 ;
break;
case V_26 :
case V_27 :
case V_28 :
case V_29 :
case V_30 :
#if 0
case SSCOP_SDP:
#endif
V_16 = ( V_14 >> 6 ) & 0x03 ;
V_19 . V_31 = V_15 = 8 ;
break;
case V_32 :
V_16 = ( V_14 >> 6 ) & 0x03 ;
V_19 . V_31 = V_15 = 4 ;
break;
default:
V_16 = 0 ;
V_15 = V_11 ;
V_19 . V_31 = 0 ;
break;
}
if ( V_1 ) {
V_12 = F_10 ( V_1 , V_33 , V_2 ,
V_11 - V_15 ,
V_15 , L_2 ) ;
V_13 = F_11 ( V_12 , V_34 ) ;
F_4 ( V_13 , V_35 , V_2 , V_18 , 1 , V_8 ) ;
switch ( V_19 . type ) {
case V_26 :
case V_30 :
case V_36 :
F_4 ( V_13 , V_37 , V_2 , V_38 , 1 , V_8 ) ;
F_4 ( V_13 , V_39 , V_2 , V_40 + 1 , 3 , V_8 ) ;
break;
case V_29 :
F_12 ( V_13 , V_41 , V_2 , V_18 , 1 ,
( V_14 & V_42 ) ? L_2 : L_4 ) ;
break;
case V_27 :
case V_43 :
F_4 ( V_13 , V_39 , V_2 , V_40 + 1 , 3 , V_8 ) ;
break;
case V_44 :
F_4 ( V_13 , V_39 , V_2 , V_40 + 1 , 3 , V_8 ) ;
break;
case V_25 :
F_4 ( V_13 , V_45 , V_2 , V_46 + 1 , 3 , V_8 ) ;
break;
#if 0
case SSCOP_SDP:
#endif
case V_47 :
F_4 ( V_13 , V_48 , V_2 , V_49 + 1 , 3 , V_8 ) ;
F_4 ( V_13 , V_45 , V_2 , V_46 + 1 , 3 , V_8 ) ;
break;
case V_50 :
F_4 ( V_13 , V_48 , V_2 , V_51 + 1 , 3 , V_8 ) ;
F_4 ( V_13 , V_39 , V_2 , V_52 + 1 , 3 , V_8 ) ;
F_4 ( V_13 , V_53 , V_2 , V_54 + 1 , 3 , V_8 ) ;
F_1 ( V_13 , V_2 , 3 ) ;
break;
case V_55 :
F_4 ( V_13 , V_39 , V_2 , V_52 + 1 , 3 , V_8 ) ;
F_4 ( V_13 , V_53 , V_2 , V_54 + 1 , 3 , V_8 ) ;
F_1 ( V_13 , V_2 , 2 ) ;
break;
}
}
switch ( V_19 . type ) {
case V_25 :
case V_32 :
case V_26 :
case V_27 :
case V_28 :
case V_29 :
case V_30 :
#if 0
case SSCOP_SDP:
#endif
if ( V_1 ) {
F_13 ( V_13 , V_56 , V_2 , V_18 , 1 , V_16 ) ;
}
V_11 -= ( V_15 + V_16 ) ;
if ( V_11 != 0 ) {
V_17 = F_14 ( V_2 , 0 , V_11 ) ;
if ( V_19 . type == V_25 )
{
F_15 ( V_10 , V_17 , V_9 , V_1 ) ;
}
break;
}
}
}
static void F_16 ( T_2 * V_2 , T_5 * V_9 , T_1 * V_1 )
{
struct V_57 * V_58 ;
T_6 V_59 ;
V_58 = (struct V_57 * ) F_17 ( F_18 () , V_9 , V_33 , 0 ) ;
if ( V_58
&& ( V_59 = V_58 -> V_59 )
&& ( V_59 == V_60
|| V_59 == V_61
|| V_59 == V_62
|| V_59 == V_63
|| V_59 == V_64 ) )
F_5 ( V_2 , V_9 , V_1 , V_59 ) ;
else
F_5 ( V_2 , V_9 , V_1 , V_65 ) ;
}
static void F_19 ( void ) {
static T_9 V_66 = FALSE ;
if ( ! V_66 ) {
V_61 = F_20 ( L_5 ) ;
V_60 = F_20 ( L_6 ) ;
V_62 = F_20 ( L_7 ) ;
V_63 = F_20 ( L_8 ) ;
V_64 = F_20 ( L_9 ) ;
V_66 = TRUE ;
}
}
T_9 F_21 ( T_6 V_67 )
{
F_19 () ;
if ( V_67 == V_61 || V_67 == V_60
|| V_67 == V_62 || V_67 == V_63
|| V_67 == V_64 )
return TRUE ;
return FALSE ;
}
void
F_22 ( void )
{
static T_9 V_68 = FALSE ;
static T_10 * V_69 ;
if ( ! V_68 ) {
F_19 () ;
V_68 = TRUE ;
} else {
F_23 ( L_10 , V_69 , V_70 ) ;
F_24 ( V_69 ) ;
}
V_69 = F_25 ( V_71 ) ;
F_26 ( L_10 , V_69 , V_70 ) ;
switch( V_72 ) {
case V_73 : V_65 = V_60 ; break;
case V_74 : V_65 = V_61 ; break;
case V_75 : V_65 = V_62 ; break;
case V_76 : V_65 = V_63 ; break;
case V_77 : V_65 = V_64 ; break;
}
}
void
F_27 ( void )
{
static T_11 V_78 [] = {
{ & V_35 , { L_11 , L_12 , V_79 , V_80 | V_81 , & V_24 , V_20 , NULL , V_82 } } ,
{ & V_37 , { L_13 , L_14 , V_79 , V_83 , NULL , 0x0 , NULL , V_82 } } ,
{ & V_39 , { L_15 , L_16 , V_84 , V_83 , NULL , 0x0 , NULL , V_82 } } ,
{ & V_45 , { L_17 , L_18 , V_84 , V_83 , NULL , 0x0 , NULL , V_82 } } ,
{ & V_48 , { L_19 , L_20 , V_84 , V_83 , NULL , 0x0 , NULL , V_82 } } ,
{ & V_53 , { L_21 , L_22 , V_84 , V_83 , NULL , 0x0 , NULL , V_82 } } ,
{ & V_7 , { L_17 , L_23 , V_84 , V_83 , NULL , 0x0 , NULL , V_82 } } ,
{ & V_56 , { L_24 , L_25 , V_79 , V_83 , NULL , 0x0 , NULL , V_82 } } ,
{ & V_41 , { L_26 , L_27 , V_85 , V_86 , NULL , 0x0 , NULL , V_82 } } ,
#if 0
{ &hf_sscop_stat_count, { "Number of NACKed pdus", "sscop.stat.count", FT_UINT32, BASE_DEC, NULL, 0x0,NULL, HFILL }}
#endif
} ;
static T_4 * V_87 [] = {
& V_34 ,
& V_6
} ;
V_33 = F_28 ( L_2 , L_2 , L_28 ) ;
F_29 ( V_33 , V_78 , F_30 ( V_78 ) ) ;
F_31 ( V_87 , F_30 ( V_87 ) ) ;
V_70 = F_32 ( L_28 , F_16 , V_33 ) ;
V_88 = F_33 ( V_33 , F_22 ) ;
V_71 = F_34 () ;
F_35 ( V_88 , L_29 ,
L_30 ,
L_31 ,
& V_71 , V_89 ) ;
F_36 ( V_88 , L_32 ,
L_33 ,
L_34 ,
( T_4 * ) & V_72 ,
V_90 , FALSE ) ;
}
