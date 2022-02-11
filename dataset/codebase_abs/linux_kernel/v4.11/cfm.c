void F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 . V_4 = F_2 ( V_5 ) ;
V_2 -> V_6 . V_7 = 0 ;
V_2 -> V_6 . V_8 = 0 ;
V_2 -> V_9 [ V_10 ] . V_11 = 0 ;
V_2 -> V_9 [ V_12 ] . V_11 = 0 ;
V_2 -> V_9 [ V_10 ] . V_13 = V_14 ;
V_2 -> V_9 [ V_12 ] . V_13 = V_14 ;
}
static void F_3 ( struct V_1 * V_2 , struct V_15 * V_16 )
{
switch ( V_16 -> V_3 -> V_17 ) {
case V_18 :
if ( ! F_4 ( V_2 ) && V_2 -> V_9 [ V_12 ] . V_19 ) {
V_16 -> V_20 = TRUE ;
} else {
V_16 -> V_20 = FALSE ;
}
break;
case V_21 :
V_16 -> V_20 = FALSE ;
break;
case V_22 :
V_16 -> V_20 = FALSE ;
break;
case V_23 :
V_16 -> V_20 = FALSE ;
break;
}
}
void F_5 ( struct V_1 * V_2 )
{
struct V_15 * V_16 ;
int V_24 ;
for ( V_24 = 0 , V_16 = V_2 -> V_9 ; V_24 < V_25 ; V_24 ++ , V_16 ++ ) {
F_3 ( V_2 , V_16 ) ;
}
}
static void F_6 ( struct V_1 * V_2 , int V_26 )
{
int V_27 ;
int V_28 ;
if ( V_2 -> V_29 . V_30 != V_31 )
return ;
V_27 = V_26 - V_32 ;
if ( V_27 != V_10 && V_27 != V_12 ) {
return ;
}
if ( V_2 -> V_9 [ V_27 ] . V_19 ) {
V_2 -> V_9 [ V_27 ] . V_13 = V_33 ;
} else if ( ! V_2 -> V_9 [ V_27 ] . V_20 ) {
V_2 -> V_9 [ V_27 ] . V_13 = V_14 ;
}
for ( V_28 = 0 ; V_28 < 2 ; V_28 ++ ) {
if ( V_2 -> V_9 [ V_28 ] . V_13 == V_34 && ! V_2 -> V_9 [ V_28 ] . V_20 ) {
V_2 -> V_9 [ V_28 ] . V_13 = V_14 ;
F_7 ( V_2 , ( int ) ( V_35 + V_28 ) , V_36 ) ;
}
if ( V_2 -> V_9 [ V_28 ] . V_13 == V_33 && V_2 -> V_9 [ V_28 ] . V_20 ) {
V_2 -> V_9 [ V_28 ] . V_13 = V_34 ;
F_7 ( V_2 , ( int ) ( V_35 + V_28 ) , V_36 ) ;
}
if ( V_2 -> V_9 [ V_28 ] . V_13 == V_14 && V_2 -> V_9 [ V_28 ] . V_20 ) {
V_2 -> V_9 [ V_28 ] . V_13 = V_34 ;
}
}
return ;
}
void F_8 ( struct V_1 * V_2 , int V_26 )
{
int V_37 ;
int V_38 ;
int V_39 ;
F_5 ( V_2 ) ;
F_6 ( V_2 , V_26 ) ;
V_39 = V_2 -> V_3 . V_4 ;
do {
F_9 ( L_1 ,
V_2 -> V_3 . V_4 & V_40 ? L_2 : L_3 ,
V_41 [ V_2 -> V_3 . V_4 & ~ V_40 ] ,
V_42 [ V_26 ] ) ;
V_37 = V_2 -> V_3 . V_4 ;
F_10 ( V_2 , V_26 ) ;
V_26 = 0 ;
} while ( V_37 != V_2 -> V_3 . V_4 ) ;
#ifndef F_11
V_38 = FALSE ;
if ( ( V_2 -> V_3 . V_4 == V_43 &&
V_2 -> V_9 [ V_10 ] . V_44 == V_45 ) ||
( V_2 -> V_3 . V_4 == V_46 &&
V_2 -> V_9 [ V_12 ] . V_44 == V_45 ) ||
( V_2 -> V_3 . V_4 == V_47 &&
V_2 -> V_9 [ V_48 ] . V_44 == V_45 &&
V_2 -> V_9 [ V_48 ] . V_3 -> V_49 != V_22 ) ) {
V_38 = TRUE ;
}
if ( V_38 != V_2 -> V_3 . V_50 )
F_12 ( V_2 , V_51 , 0 , V_38 ) ;
#if 0
if (smc->mib.fddiSMTCF_State != oldstate) {
smt_srf_event(smc,SMT_EVENT_MAC_PATH_CHANGE,INDEX_MAC,0) ;
}
#endif
#endif
V_2 -> V_3 . V_52 [ V_53 ] . V_54 =
V_55 [ V_2 -> V_3 . V_4 ] ;
F_13 ( V_2 , ( int ) V_2 -> V_3 . V_4 ) ;
}
static void F_10 ( struct V_1 * V_2 , int V_56 )
{
switch( V_2 -> V_3 . V_4 ) {
case F_2 ( V_5 ) :
V_2 -> V_3 . V_24 [ V_10 ] . V_57 = V_58 ;
V_2 -> V_3 . V_24 [ V_12 ] . V_57 = V_58 ;
V_2 -> V_3 . V_24 [ V_10 ] . V_59 = 0 ;
V_2 -> V_3 . V_24 [ V_12 ] . V_59 = 0 ;
V_2 -> V_3 . V_60 = V_61 ;
F_14 ( V_2 , V_62 ) ;
V_2 -> V_6 . V_8 = FALSE ;
V_2 -> V_6 . V_7 = FALSE ;
F_7 ( V_2 , V_63 , V_64 ) ;
F_15 () ;
F_16 ( 1 , L_4 , V_41 [ V_2 -> V_3 . V_4 ] ) ;
break;
case V_5 :
if ( V_2 -> V_29 . V_30 && ( V_2 -> V_9 [ V_10 ] . V_19 || V_2 -> V_9 [ V_10 ] . V_65 ||
V_2 -> V_9 [ V_12 ] . V_19 || V_2 -> V_9 [ V_12 ] . V_65 ) ) {
F_17 ( V_47 ) ;
break ;
}
if ( ( V_2 -> V_9 [ V_10 ] . V_13 == V_33 && V_2 -> V_9 [ V_10 ] . V_19 &&
! V_2 -> V_9 [ V_10 ] . V_20 ) || V_2 -> V_9 [ V_10 ] . V_65 ) {
F_17 ( V_43 ) ;
break ;
}
if ( ( V_2 -> V_9 [ V_12 ] . V_13 == V_33 && V_2 -> V_9 [ V_12 ] . V_19 &&
! V_2 -> V_9 [ V_12 ] . V_20 ) || V_2 -> V_9 [ V_12 ] . V_65 ) {
F_17 ( V_46 ) ;
break ;
}
break ;
case F_2 ( V_43 ) :
V_2 -> V_3 . V_24 [ V_10 ] . V_57 = V_66 ;
V_2 -> V_3 . V_24 [ V_12 ] . V_57 = V_58 ;
V_2 -> V_3 . V_24 [ V_10 ] . V_59 = V_67 ;
V_2 -> V_3 . V_24 [ V_12 ] . V_59 = 0 ;
V_2 -> V_3 . V_60 = V_68 ;
F_14 ( V_2 , V_69 ) ;
if ( V_2 -> V_9 [ V_10 ] . V_65 ) {
V_2 -> V_6 . V_7 = FALSE ;
V_2 -> V_6 . V_8 = TRUE ;
F_7 ( V_2 , V_63 , V_70 ) ;
}
if ( V_2 -> V_9 [ V_10 ] . V_19 ) {
V_2 -> V_6 . V_8 = FALSE ;
V_2 -> V_6 . V_7 = TRUE ;
F_7 ( V_2 , V_63 , V_64 ) ;
}
F_15 () ;
F_16 ( 1 , L_4 , V_41 [ V_2 -> V_3 . V_4 ] ) ;
break ;
case V_43 :
if ( ( V_2 -> V_9 [ V_10 ] . V_20 || ! V_2 -> V_9 [ V_10 ] . V_19 ) &&
! V_2 -> V_9 [ V_10 ] . V_65 ) {
F_17 ( V_5 ) ;
break ;
}
else if ( ( V_2 -> V_9 [ V_12 ] . V_65 && V_2 -> V_9 [ V_10 ] . V_19 &&
V_2 -> V_9 [ V_10 ] . V_13 == V_33 ) ||
( ( V_2 -> V_9 [ V_12 ] . V_65 ||
( V_2 -> V_9 [ V_12 ] . V_19 &&
V_2 -> V_9 [ V_12 ] . V_13 == V_33 ) ) &&
( V_2 -> V_9 [ V_10 ] . V_44 == V_71 ||
V_2 -> V_9 [ V_12 ] . V_44 == V_71 ) ) ) {
V_2 -> V_9 [ V_10 ] . V_11 = TRUE ;
F_17 ( V_46 ) ;
break ;
}
else if ( ! V_2 -> V_29 . V_72 &&
V_2 -> V_9 [ V_10 ] . V_19 &&
V_2 -> V_9 [ V_10 ] . V_13 == V_33 &&
V_2 -> V_9 [ V_10 ] . V_44 == V_45 && V_2 -> V_9 [ V_12 ] . V_19 &&
V_2 -> V_9 [ V_12 ] . V_13 == V_33 &&
V_2 -> V_9 [ V_12 ] . V_44 == V_45 ) {
V_2 -> V_9 [ V_10 ] . V_11 = TRUE ;
V_2 -> V_9 [ V_12 ] . V_11 = TRUE ;
F_17 ( V_73 ) ;
break ;
}
else if ( V_2 -> V_29 . V_72 &&
V_2 -> V_9 [ V_10 ] . V_19 &&
V_2 -> V_9 [ V_10 ] . V_13 == V_33 &&
V_2 -> V_9 [ V_10 ] . V_44 == V_45 &&
V_2 -> V_9 [ V_12 ] . V_19 &&
V_2 -> V_9 [ V_12 ] . V_13 == V_33 &&
V_2 -> V_9 [ V_12 ] . V_44 == V_45 ) {
V_2 -> V_9 [ V_10 ] . V_11 = TRUE ;
V_2 -> V_9 [ V_12 ] . V_11 = TRUE ;
F_17 ( V_74 ) ;
break ;
}
break ;
case F_2 ( V_46 ) :
V_2 -> V_3 . V_24 [ V_10 ] . V_57 = V_58 ;
V_2 -> V_3 . V_24 [ V_12 ] . V_57 = V_66 ;
V_2 -> V_3 . V_24 [ V_10 ] . V_59 = 0 ;
V_2 -> V_3 . V_24 [ V_12 ] . V_59 = V_67 ;
V_2 -> V_3 . V_60 = V_68 ;
F_14 ( V_2 , V_75 ) ;
if ( V_2 -> V_9 [ V_12 ] . V_65 ) {
V_2 -> V_6 . V_7 = FALSE ;
V_2 -> V_6 . V_8 = TRUE ;
F_7 ( V_2 , V_63 , V_70 ) ;
}
if ( V_2 -> V_9 [ V_12 ] . V_19 ) {
V_2 -> V_6 . V_8 = FALSE ;
V_2 -> V_6 . V_7 = TRUE ;
F_7 ( V_2 , V_63 , V_64 ) ;
}
F_15 () ;
F_16 ( 1 , L_4 , V_41 [ V_2 -> V_3 . V_4 ] ) ;
break ;
case V_46 :
if ( ! V_2 -> V_9 [ V_12 ] . V_19 && ! V_2 -> V_9 [ V_12 ] . V_65 ) {
F_17 ( V_5 ) ;
break ;
}
else if ( V_2 -> V_9 [ V_10 ] . V_65 && V_2 -> V_9 [ V_10 ] . V_44 == V_45 &&
V_2 -> V_9 [ V_12 ] . V_19 && V_2 -> V_9 [ V_12 ] . V_44 == V_45 ) {
V_2 -> V_9 [ V_12 ] . V_11 = TRUE ;
F_17 ( V_43 ) ;
break ;
}
else if ( ! V_2 -> V_29 . V_72 &&
V_2 -> V_9 [ V_10 ] . V_19 && V_2 -> V_9 [ V_10 ] . V_44 == V_45 &&
V_2 -> V_9 [ V_12 ] . V_19 && V_2 -> V_9 [ V_12 ] . V_44 == V_45 ) {
V_2 -> V_9 [ V_10 ] . V_11 = TRUE ;
V_2 -> V_9 [ V_12 ] . V_11 = TRUE ;
F_17 ( V_73 ) ;
break ;
}
else if ( V_2 -> V_29 . V_72 &&
V_2 -> V_9 [ V_10 ] . V_19 && V_2 -> V_9 [ V_10 ] . V_44 == V_45 &&
V_2 -> V_9 [ V_12 ] . V_19 && V_2 -> V_9 [ V_12 ] . V_44 == V_45 ) {
V_2 -> V_9 [ V_10 ] . V_11 = TRUE ;
V_2 -> V_9 [ V_12 ] . V_11 = TRUE ;
F_17 ( V_74 ) ;
break ;
}
break ;
case F_2 ( V_73 ) :
V_2 -> V_3 . V_24 [ V_10 ] . V_57 = V_76 ;
V_2 -> V_3 . V_24 [ V_12 ] . V_57 = V_76 ;
V_2 -> V_3 . V_24 [ V_10 ] . V_59 = 0 ;
V_2 -> V_3 . V_24 [ V_12 ] . V_59 = V_67 ;
V_2 -> V_3 . V_60 = V_77 ;
F_14 ( V_2 , V_78 ) ;
V_2 -> V_6 . V_8 = FALSE ;
V_2 -> V_6 . V_7 = TRUE ;
F_7 ( V_2 , V_63 , V_64 ) ;
F_15 () ;
F_16 ( 1 , L_4 , V_41 [ V_2 -> V_3 . V_4 ] ) ;
break ;
case V_73 :
if ( V_2 -> V_9 [ V_12 ] . V_20 || ! V_2 -> V_9 [ V_12 ] . V_19 ) {
V_2 -> V_9 [ V_10 ] . V_11 = TRUE ;
F_17 ( V_43 ) ;
break ;
}
else if ( ! V_2 -> V_9 [ V_10 ] . V_19 || V_2 -> V_9 [ V_10 ] . V_20 ) {
V_2 -> V_9 [ V_12 ] . V_11 = TRUE ;
F_17 ( V_46 ) ;
break ;
}
else if ( V_2 -> V_29 . V_72 ) {
V_2 -> V_9 [ V_12 ] . V_11 = TRUE ;
F_17 ( V_74 ) ;
break ;
}
break ;
case F_2 ( V_74 ) :
V_2 -> V_3 . V_24 [ V_10 ] . V_57 = V_76 ;
V_2 -> V_3 . V_24 [ V_12 ] . V_57 = V_76 ;
V_2 -> V_3 . V_24 [ V_10 ] . V_59 = V_67 ;
V_2 -> V_3 . V_24 [ V_12 ] . V_59 = 0 ;
V_2 -> V_3 . V_60 = V_77 ;
F_14 ( V_2 , V_79 ) ;
V_2 -> V_6 . V_8 = FALSE ;
V_2 -> V_6 . V_7 = TRUE ;
F_7 ( V_2 , V_63 , V_64 ) ;
F_15 () ;
F_16 ( 1 , L_4 , V_41 [ V_2 -> V_3 . V_4 ] ) ;
break ;
case V_74 :
if ( ! V_2 -> V_9 [ V_12 ] . V_19 || V_2 -> V_9 [ V_12 ] . V_20 ) {
V_2 -> V_9 [ V_10 ] . V_11 = TRUE ;
F_17 ( V_43 ) ;
break ;
}
else if ( ! V_2 -> V_9 [ V_10 ] . V_19 || V_2 -> V_9 [ V_10 ] . V_20 ) {
V_2 -> V_9 [ V_12 ] . V_11 = TRUE ;
F_17 ( V_46 ) ;
break ;
}
else if ( ! V_2 -> V_29 . V_72 ) {
V_2 -> V_9 [ V_10 ] . V_11 = TRUE ;
F_17 ( V_73 ) ;
break ;
}
break ;
case F_2 ( V_47 ) :
V_2 -> V_3 . V_24 [ V_48 ] . V_57 = V_66 ;
V_2 -> V_3 . V_24 [ V_48 ] . V_59 = V_67 ;
V_2 -> V_3 . V_60 = V_68 ;
F_14 ( V_2 , V_80 ) ;
if ( V_2 -> V_9 [ V_10 ] . V_65 || V_2 -> V_9 [ V_12 ] . V_65 ) {
V_2 -> V_6 . V_7 = FALSE ;
V_2 -> V_6 . V_8 = TRUE ;
F_7 ( V_2 , V_63 , V_70 ) ;
}
if ( V_2 -> V_9 [ V_10 ] . V_19 || V_2 -> V_9 [ V_12 ] . V_19 ) {
V_2 -> V_6 . V_8 = FALSE ;
V_2 -> V_6 . V_7 = TRUE ;
F_7 ( V_2 , V_63 , V_64 ) ;
}
F_15 () ;
F_16 ( 1 , L_4 , V_41 [ V_2 -> V_3 . V_4 ] ) ;
break ;
case V_47 :
if ( ! V_2 -> V_9 [ V_10 ] . V_19 && ! V_2 -> V_9 [ V_10 ] . V_65 &&
! V_2 -> V_9 [ V_12 ] . V_19 && ! V_2 -> V_9 [ V_12 ] . V_65 ) {
F_17 ( V_5 ) ;
break ;
}
break ;
default:
F_18 ( V_2 , V_81 , V_82 ) ;
break;
}
}
int F_19 ( struct V_1 * V_2 )
{
return ( V_2 -> V_3 . V_4 == V_46 ||
V_2 -> V_3 . V_4 == V_74 ) ? V_12 : V_10 ;
}
int F_20 ( struct V_1 * V_2 )
{
return ( V_2 -> V_3 . V_4 == V_46 ||
V_2 -> V_3 . V_4 == V_73 ) ? V_12 : V_10 ;
}
int F_21 ( struct V_1 * V_2 , char * V_83 , int V_84 )
{
char * V_85 ;
int V_86 ;
switch ( V_2 -> V_3 . V_4 ) {
default :
case V_5 :
V_85 = V_2 -> V_29 . V_30 ? V_87 : V_88 ;
V_86 = V_2 -> V_29 . V_30 ? sizeof( V_87 ) : sizeof( V_88 ) ;
break ;
case V_43 :
V_85 = V_89 ;
V_86 = sizeof( V_89 ) ;
break ;
case V_46 :
V_85 = V_90 ;
V_86 = sizeof( V_90 ) ;
break ;
case V_73 :
V_85 = V_91 ;
V_86 = sizeof( V_91 ) ;
break ;
case V_47 :
V_85 = V_92 ;
V_86 = sizeof( V_92 ) ;
break ;
}
memcpy ( V_83 , V_85 , V_86 ) ;
F_22 ( V_84 ) ;
return V_86 ;
}
