static void F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 V_3 ) {
T_4 V_4 , V_5 ;
T_5 * V_6 ;
if ( ( V_4 = ( F_2 ( V_2 ) ) / 4 - V_3 ) ) {
V_6 = F_3 ( V_1 , V_2 , 0 , V_4 * 4 , L_1 ) ;
V_1 = F_4 ( V_6 , V_7 ) ;
for ( V_5 = 0 ; V_5 < V_4 ; V_5 ++ ) {
F_5 ( V_1 , V_8 , V_2 , V_5 * 4 + 1 , 3 , V_9 ) ;
}
}
}
extern void
F_6 ( T_2 * V_2 , T_6 * V_10 , T_1 * V_1 , T_7 V_11 )
{
T_3 V_12 ;
T_5 * V_13 ;
T_1 * V_14 = NULL ;
T_8 V_15 ;
int V_16 ;
int V_17 ;
T_2 * V_18 ;
V_12 = F_2 ( V_2 ) ;
V_15 = F_7 ( V_2 , V_19 ) ;
V_20 . type = V_15 & V_21 ;
F_8 ( V_10 -> V_22 , V_23 , L_2 ) ;
F_9 ( V_10 -> V_22 , V_24 , F_10 ( V_20 . type , V_25 ,
L_3 ) ) ;
switch ( V_20 . type ) {
case V_26 :
V_17 = ( V_15 >> 6 ) & 0x03 ;
V_16 = 4 ;
break;
case V_27 :
case V_28 :
case V_29 :
case V_30 :
case V_31 :
#if 0
case SSCOP_SDP:
#endif
V_17 = ( V_15 >> 6 ) & 0x03 ;
V_20 . V_32 = V_16 = 8 ;
break;
case V_33 :
V_17 = ( V_15 >> 6 ) & 0x03 ;
V_20 . V_32 = V_16 = 4 ;
break;
default:
V_17 = 0 ;
V_16 = V_12 ;
V_20 . V_32 = 0 ;
break;
}
if ( V_1 ) {
V_13 = F_11 ( V_1 , V_34 , V_2 ,
V_12 - V_16 ,
V_16 , L_2 ) ;
V_14 = F_4 ( V_13 , V_35 ) ;
F_5 ( V_14 , V_36 , V_2 , V_19 , 1 , V_9 ) ;
switch ( V_20 . type ) {
case V_27 :
case V_31 :
case V_37 :
F_5 ( V_14 , V_38 , V_2 , V_39 , 1 , V_9 ) ;
F_5 ( V_14 , V_40 , V_2 , V_41 + 1 , 3 , V_9 ) ;
break;
case V_30 :
F_3 ( V_14 , V_2 , V_19 , 1 ,
L_4 , ( V_15 & V_42 ) ? L_2 : L_5 ) ;
break;
case V_28 :
case V_43 :
F_5 ( V_14 , V_40 , V_2 , V_41 + 1 , 3 , V_9 ) ;
break;
case V_44 :
F_5 ( V_14 , V_40 , V_2 , V_41 + 1 , 3 , V_9 ) ;
break;
case V_26 :
F_5 ( V_14 , V_45 , V_2 , V_46 + 1 , 3 , V_9 ) ;
break;
#if 0
case SSCOP_SDP:
#endif
case V_47 :
F_5 ( V_14 , V_48 , V_2 , V_49 + 1 , 3 , V_9 ) ;
F_5 ( V_14 , V_45 , V_2 , V_46 + 1 , 3 , V_9 ) ;
break;
case V_50 :
F_5 ( V_14 , V_48 , V_2 , V_51 + 1 , 3 , V_9 ) ;
F_5 ( V_14 , V_40 , V_2 , V_52 + 1 , 3 , V_9 ) ;
F_5 ( V_14 , V_53 , V_2 , V_54 + 1 , 3 , V_9 ) ;
F_1 ( V_14 , V_2 , 3 ) ;
break;
case V_55 :
F_5 ( V_14 , V_40 , V_2 , V_52 + 1 , 3 , V_9 ) ;
F_5 ( V_14 , V_53 , V_2 , V_54 + 1 , 3 , V_9 ) ;
F_1 ( V_14 , V_2 , 2 ) ;
break;
}
}
switch ( V_20 . type ) {
case V_26 :
case V_33 :
case V_27 :
case V_28 :
case V_29 :
case V_30 :
case V_31 :
#if 0
case SSCOP_SDP:
#endif
if ( V_1 ) {
F_3 ( V_14 , V_2 , V_19 , 1 ,
L_6 , V_17 ) ;
}
V_12 -= ( V_16 + V_17 ) ;
if ( V_12 != 0 ) {
V_18 = F_12 ( V_2 , 0 , V_12 , V_12 ) ;
if ( V_20 . type == V_26 )
{
F_13 ( V_11 , V_18 , V_10 , V_1 ) ;
}
break;
}
}
}
static void F_14 ( T_2 * V_2 , T_6 * V_10 , T_1 * V_1 )
{
struct V_56 * V_57 ;
T_7 V_58 ;
V_57 = (struct V_56 * ) F_15 ( F_16 () , V_10 , V_34 , 0 ) ;
if ( V_57
&& ( V_58 = V_57 -> V_58 )
&& ( V_58 == V_59
|| V_58 == V_60
|| V_58 == V_61
|| V_58 == V_62
|| V_58 == V_63 ) )
F_6 ( V_2 , V_10 , V_1 , V_58 ) ;
else
F_6 ( V_2 , V_10 , V_1 , V_64 ) ;
}
static void F_17 ( void ) {
static T_9 V_65 = FALSE ;
if ( ! V_65 ) {
V_60 = F_18 ( L_7 ) ;
V_59 = F_18 ( L_8 ) ;
V_61 = F_18 ( L_9 ) ;
V_62 = F_18 ( L_10 ) ;
V_63 = F_18 ( L_11 ) ;
V_65 = TRUE ;
}
}
T_9 F_19 ( T_7 V_66 )
{
F_17 () ;
if ( V_66 == V_60 || V_66 == V_59
|| V_66 == V_61 || V_66 == V_62
|| V_66 == V_63 )
return TRUE ;
return FALSE ;
}
void
F_20 ( void )
{
static T_9 V_67 = FALSE ;
static T_10 * V_68 ;
if ( ! V_67 ) {
F_17 () ;
V_67 = TRUE ;
} else {
F_21 ( L_12 , V_68 , V_69 ) ;
F_22 ( V_68 ) ;
}
V_68 = F_23 ( V_70 ) ;
F_24 ( L_12 , V_68 , V_69 ) ;
switch( V_71 ) {
case V_72 : V_64 = V_59 ; break;
case V_73 : V_64 = V_60 ; break;
case V_74 : V_64 = V_61 ; break;
case V_75 : V_64 = V_62 ; break;
case V_76 : V_64 = V_63 ; break;
}
}
void
F_25 ( void )
{
static T_11 V_77 [] = {
{ & V_36 , { L_13 , L_14 , V_78 , V_79 , F_26 ( V_25 ) , V_21 , NULL , V_80 } } ,
{ & V_38 , { L_15 , L_16 , V_78 , V_81 , NULL , 0x0 , NULL , V_80 } } ,
{ & V_40 , { L_17 , L_18 , V_82 , V_81 , NULL , 0x0 , NULL , V_80 } } ,
{ & V_45 , { L_19 , L_20 , V_82 , V_81 , NULL , 0x0 , NULL , V_80 } } ,
{ & V_48 , { L_21 , L_22 , V_82 , V_81 , NULL , 0x0 , NULL , V_80 } } ,
{ & V_53 , { L_23 , L_24 , V_82 , V_81 , NULL , 0x0 , NULL , V_80 } } ,
{ & V_8 , { L_19 , L_25 , V_82 , V_81 , NULL , 0x0 , NULL , V_80 } } ,
#if 0
{ &hf_sscop_stat_count, { "Number of NACKed pdus", "sscop.stat.count", FT_UINT32, BASE_DEC, NULL, 0x0,NULL, HFILL }}
#endif
} ;
static T_4 * V_83 [] = {
& V_35 ,
& V_7
} ;
V_34 = F_27 ( L_2 , L_2 , L_26 ) ;
F_28 ( V_34 , V_77 , F_29 ( V_77 ) ) ;
F_30 ( V_83 , F_29 ( V_83 ) ) ;
V_69 = F_31 ( L_26 , F_14 , V_34 ) ;
V_84 = F_32 ( V_34 , F_20 ) ;
V_70 = F_33 () ;
F_34 ( V_84 , L_27 ,
L_28 ,
L_29 ,
& V_70 , V_85 ) ;
F_35 ( V_84 , L_30 ,
L_31 ,
L_32 ,
( T_4 * ) & V_71 ,
V_86 , FALSE ) ;
}
