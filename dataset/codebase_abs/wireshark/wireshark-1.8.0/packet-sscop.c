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
if ( F_9 ( V_10 -> V_22 , V_24 ) )
F_10 ( V_10 -> V_22 , V_24 , F_11 ( V_20 . type , V_25 ,
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
V_13 = F_12 ( V_1 , V_34 , V_2 ,
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
V_18 = F_13 ( V_2 , 0 , V_12 , V_12 ) ;
if ( V_20 . type == V_26 )
{
F_14 ( V_11 , V_18 , V_10 , V_1 ) ;
}
break;
}
}
}
static void F_15 ( T_2 * V_2 , T_6 * V_10 , T_1 * V_1 )
{
struct V_56 * V_57 ;
T_7 V_58 ;
V_57 = F_16 ( V_10 -> V_59 , V_34 ) ;
if ( V_57
&& ( V_58 = V_57 -> V_58 )
&& ( V_58 == V_60
|| V_58 == V_61
|| V_58 == V_62
|| V_58 == V_63
|| V_58 == V_64 ) )
F_6 ( V_2 , V_10 , V_1 , V_58 ) ;
else
F_6 ( V_2 , V_10 , V_1 , V_65 ) ;
}
static void F_17 ( T_9 V_66 )
{
if ( V_66 ) {
F_18 ( L_7 , V_66 , V_67 ) ;
}
}
static void F_19 ( T_9 V_66 )
{
if ( V_66 ) {
F_20 ( L_7 , V_66 , V_67 ) ;
}
}
static void F_21 ( void ) {
static T_10 V_68 = FALSE ;
if ( ! V_68 ) {
V_67 = F_22 ( F_15 , V_34 ) ;
V_61 = F_23 ( L_8 ) ;
V_60 = F_23 ( L_9 ) ;
V_62 = F_23 ( L_10 ) ;
V_63 = F_23 ( L_11 ) ;
V_64 = F_23 ( L_12 ) ;
V_68 = TRUE ;
}
}
T_10 F_24 ( T_7 V_69 )
{
F_21 () ;
if ( V_69 == V_61 || V_69 == V_60
|| V_69 == V_62 || V_69 == V_63
|| V_69 == V_64 )
return TRUE ;
return FALSE ;
}
void
F_25 ( void )
{
static T_10 V_70 = FALSE ;
static T_11 * V_71 ;
if ( ! V_70 ) {
F_21 () ;
V_70 = TRUE ;
} else {
F_26 ( V_71 , F_17 ) ;
F_27 ( V_71 ) ;
}
V_71 = F_28 ( V_72 ) ;
F_26 ( V_71 , F_19 ) ;
switch( V_73 ) {
case V_74 : V_65 = V_60 ; break;
case V_75 : V_65 = V_61 ; break;
case V_76 : V_65 = V_62 ; break;
case V_77 : V_65 = V_63 ; break;
case V_78 : V_65 = V_64 ; break;
}
}
void
F_29 ( void )
{
static T_12 V_79 [] = {
{ & V_36 , { L_13 , L_14 , V_80 , V_81 , F_30 ( V_25 ) , V_21 , NULL , V_82 } } ,
{ & V_38 , { L_15 , L_16 , V_80 , V_83 , NULL , 0x0 , NULL , V_82 } } ,
{ & V_40 , { L_17 , L_18 , V_84 , V_83 , NULL , 0x0 , NULL , V_82 } } ,
{ & V_45 , { L_19 , L_20 , V_84 , V_83 , NULL , 0x0 , NULL , V_82 } } ,
{ & V_48 , { L_21 , L_22 , V_84 , V_83 , NULL , 0x0 , NULL , V_82 } } ,
{ & V_53 , { L_23 , L_24 , V_84 , V_83 , NULL , 0x0 , NULL , V_82 } } ,
{ & V_8 , { L_19 , L_25 , V_84 , V_83 , NULL , 0x0 , NULL , V_82 } } ,
{ & V_85 , { L_26 , L_27 , V_86 , V_83 , NULL , 0x0 , NULL , V_82 } }
} ;
static T_4 * V_87 [] = {
& V_35 ,
& V_7
} ;
V_34 = F_31 ( L_2 , L_2 , L_28 ) ;
F_32 ( V_34 , V_79 , F_33 ( V_79 ) ) ;
F_34 ( V_87 , F_33 ( V_87 ) ) ;
F_35 ( L_28 , F_15 , V_34 ) ;
V_88 = F_36 ( V_34 , F_25 ) ;
V_72 = F_37 () ;
F_38 ( V_88 , L_29 ,
L_30 ,
L_31 ,
& V_72 , V_89 ) ;
F_39 ( V_88 , L_32 ,
L_33 ,
L_34 ,
( T_4 * ) & V_73 ,
V_90 , FALSE ) ;
}
