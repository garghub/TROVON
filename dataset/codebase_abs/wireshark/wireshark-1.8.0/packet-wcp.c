static void
F_1 ( T_1 * V_1 , int V_2 , T_2 * V_3 ) {
T_3 V_4 = F_2 ( V_1 , 5 ) ;
F_3 ( V_3 , V_5 , V_1 , V_2 , 2 , F_4 ( V_1 , V_2 ) ) ;
F_3 ( V_3 , V_6 , V_1 , V_2 + 2 , 1 , F_2 ( V_1 , V_2 + 2 ) ) ;
F_3 ( V_3 , V_7 , V_1 , V_2 + 3 , 1 , F_2 ( V_1 , V_2 + 3 ) ) ;
F_3 ( V_3 , V_8 , V_1 , V_2 + 4 , 1 , F_2 ( V_1 , V_2 + 4 ) ) ;
F_3 ( V_3 , V_9 , V_1 , V_2 + 5 , 1 , V_4 ) ;
F_3 ( V_3 , V_10 , V_1 , V_2 + 6 , 1 , F_2 ( V_1 , V_2 + 6 ) ) ;
if ( V_4 > 1 )
F_3 ( V_3 , V_11 , V_1 , V_2 + 7 , 1 , F_2 ( V_1 , V_2 + 7 ) ) ;
if ( V_4 > 2 )
F_3 ( V_3 , V_12 , V_1 , V_2 + 8 , 1 , F_2 ( V_1 , V_2 + 8 ) ) ;
if ( V_4 > 3 )
F_3 ( V_3 , V_13 , V_1 , V_2 + 9 , 1 , F_2 ( V_1 , V_2 + 9 ) ) ;
}
static void
F_5 ( T_1 * V_1 , int V_2 , T_2 * V_3 ) {
F_3 ( V_3 , V_5 , V_1 , V_2 , 2 , F_4 ( V_1 , V_2 ) ) ;
F_3 ( V_3 , V_6 , V_1 , V_2 + 2 , 1 , F_2 ( V_1 , V_2 + 2 ) ) ;
F_3 ( V_3 , V_8 , V_1 , V_2 + 3 , 1 , F_2 ( V_1 , V_2 + 3 ) ) ;
F_3 ( V_3 , V_14 , V_1 , V_2 + 4 , 1 , F_2 ( V_1 , V_2 + 4 ) ) ;
}
static void
F_6 ( T_1 * V_1 , int V_2 , T_2 * V_3 ) {
F_3 ( V_3 , V_5 , V_1 , V_2 , 2 , F_4 ( V_1 , V_2 ) ) ;
F_3 ( V_3 , V_6 , V_1 , V_2 + 2 , 1 , F_2 ( V_1 , V_2 + 2 ) ) ;
F_3 ( V_3 , V_15 , V_1 , V_2 + 3 , 1 , F_2 ( V_1 , V_2 + 3 ) ) ;
F_3 ( V_3 , V_16 , V_1 , V_2 + 4 , 1 , F_2 ( V_1 , V_2 + 4 ) ) ;
F_3 ( V_3 , V_17 , V_1 , V_2 + 5 , 1 , F_2 ( V_1 , V_2 + 5 ) ) ;
}
static void
F_7 ( T_1 * V_1 , int V_2 , T_2 * V_3 ) {
F_3 ( V_3 , V_5 , V_1 , V_2 , 2 , F_4 ( V_1 , V_2 ) ) ;
}
static void F_8 ( T_1 * V_1 , T_4 * V_18 ) {
T_5 * V_19 = 0 ;
T_6 V_20 ;
V_20 = F_9 ( V_1 ) - 3 ;
V_19 = F_10 ( V_18 ) ;
if ( ( V_19 -> V_21 + V_20 ) <= ( V_19 -> V_22 + V_23 ) ) {
F_11 ( V_1 , V_19 -> V_21 , 2 , V_20 ) ;
V_19 -> V_21 = V_19 -> V_21 + V_20 ;
} else {
T_7 * V_24 = V_19 -> V_22 + V_23 ;
F_11 ( V_1 , V_19 -> V_21 , 2 , V_24 - V_19 -> V_21 ) ;
F_11 ( V_1 , V_19 -> V_22 , ( V_25 ) ( V_24 - V_19 -> V_21 - 2 ) ,
V_20 - ( V_24 - V_19 -> V_21 ) ) ;
V_19 -> V_21 = V_19 -> V_21 + V_20 - V_23 ;
}
}
static void F_12 ( T_1 * V_1 , T_4 * V_18 , T_2 * V_3 ) {
T_2 * V_26 ;
T_8 * V_27 ;
int V_28 ;
T_9 V_29 , V_30 , V_31 , V_32 ;
T_1 * V_33 ;
F_13 ( V_18 -> V_34 , V_35 , L_1 ) ;
F_14 ( V_18 -> V_34 , V_36 ) ;
V_29 = F_4 ( V_1 , 0 ) ;
V_30 = ( V_29 & 0xf000 ) >> 12 ;
V_31 = ( V_29 & 0x0f00 ) >> 8 ;
if ( V_30 == 0xf )
V_28 = 1 ;
else
V_28 = 2 ;
V_32 = V_29 & 0x0fff ;
if ( F_15 ( V_18 -> V_34 , V_36 ) ) {
F_16 ( V_18 -> V_34 , V_36 , F_17 ( V_30 , V_37 , L_2 ) ) ;
if ( V_30 == 0xf )
F_18 ( V_18 -> V_34 , V_36 , L_3 ,
F_17 ( V_31 , V_38 , L_2 ) ) ;
}
if ( V_3 ) {
V_27 = F_19 ( V_3 , V_39 , V_1 , 0 , V_28 , V_40 ) ;
V_26 = F_20 ( V_27 , V_41 ) ;
F_3 ( V_26 , V_42 , V_1 , 0 , 1 , F_2 ( V_1 , 0 ) ) ;
if ( V_30 == 0xf ) {
F_3 ( V_26 , V_43 , V_1 , 1 , 1 ,
F_2 ( V_1 , 0 ) ) ;
switch ( V_31 ) {
case V_44 :
F_1 ( V_1 , 1 , V_26 ) ;
break;
case V_45 :
F_5 ( V_1 , 1 , V_26 ) ;
break;
case V_46 :
case V_47 :
F_6 ( V_1 , 1 , V_26 ) ;
break;
case V_48 :
case V_49 :
F_7 ( V_1 , 1 , V_26 ) ;
break;
default:
break;
}
} else {
F_3 ( V_26 , V_50 , V_1 , 0 , 2 , V_32 ) ;
}
}
else {
V_26 = NULL ;
}
if ( V_30 != 1 && V_30 != 0 && ! ( V_30 == 0xf && V_31 == 0 ) )
return;
if ( V_30 == 1 ) {
if ( ! V_18 -> V_51 -> V_52 . V_53 ) {
F_8 ( V_1 , V_18 ) ;
}
V_33 = F_21 ( V_1 , V_28 ) ;
}
else {
V_33 = F_22 ( V_1 , V_28 , V_18 , V_26 ) ;
if ( ! V_33 ) {
F_23 ( V_3 , V_54 , V_1 , 0 , 0 ,
L_4 ) ;
return;
}
}
if ( V_3 )
F_3 ( V_26 , V_55 , V_1 ,
F_9 ( V_1 ) - 1 , 1 ,
F_2 ( V_1 , F_9 ( V_1 ) - 1 ) ) ;
F_24 ( V_56 , V_33 , V_18 , V_3 ) ;
return;
}
static T_7 * F_25 ( T_7 * V_57 , T_7 * V_58 , int * V_20 , T_7 * V_59 , T_7 * V_24 ) {
T_9 V_60 , V_61 ;
T_7 V_62 = * V_57 ;
V_60 = ( * ( V_57 ++ ) & 0xf ) << 8 ;
V_60 += * ( V_57 ++ ) ;
if ( ( V_62 & 0xf0 ) == 0x10 ) {
V_61 = * V_57 ;
V_61 ++ ;
} else {
V_61 = V_62 >> 4 ;
V_61 ++ ;
}
V_57 = ( V_58 - 1 - V_60 ) ;
if ( V_57 < V_59 )
V_57 += V_23 ;
while( V_61 -- ) {
* V_58 = * V_57 ;
if ( ++ ( * V_20 ) > V_63 ) {
printf ( L_5 , * V_20 ) ;
return NULL ;
}
if ( V_58 ++ == V_24 )
V_58 = V_59 ;
if ( V_57 ++ == V_24 )
V_57 = V_59 ;
}
return V_58 ;
}
static
T_5 * F_10 ( T_4 * V_18 ) {
T_10 * V_64 ;
T_11 * V_65 ;
V_64 = F_26 ( V_18 -> V_66 , V_18 -> V_67 ,
V_18 -> V_51 -> V_68 ) ;
if ( ! V_64 ) {
V_64 = F_27 ( V_18 -> V_66 , V_18 -> V_67 ,
V_18 -> V_51 -> V_68 ) ;
}
V_65 = F_28 ( V_64 , V_39 ) ;
if ( ! V_65 ) {
V_65 = F_29 ( sizeof( T_11 ) ) ;
V_65 -> V_69 . V_21 = V_65 -> V_69 . V_22 ;
V_65 -> V_70 . V_21 = V_65 -> V_70 . V_22 ;
F_30 ( V_64 , V_39 , V_65 ) ;
}
if ( V_18 -> V_71 -> V_72 . V_52 & V_73 )
return & V_65 -> V_69 ;
else
return & V_65 -> V_70 ;
}
static T_1 * F_22 ( T_1 * V_74 , int V_2 , T_4 * V_18 , T_2 * V_3 ) {
T_2 * V_75 ;
T_8 * V_27 ;
int V_20 = 0 , V_76 = - 1 ;
int V_77 = F_9 ( V_74 ) - 1 ;
T_7 * V_58 , * V_57 , * V_59 , * V_24 , V_78 = 0 ;
T_7 V_79 [ V_63 ] ;
T_1 * volatile V_1 = 0 ;
T_5 * V_19 = 0 ;
T_12 * volatile V_80 ;
volatile T_13 V_81 = FALSE ;
V_19 = F_10 ( V_18 ) ;
V_59 = V_19 -> V_22 ;
V_24 = V_59 + V_23 ;
if ( V_77 - V_2 > V_63 ) {
if ( V_3 )
F_31 ( V_3 , V_74 , V_2 , - 1 ,
L_6 ,
V_77 - V_2 , V_63 ) ;
return NULL ;
}
V_57 = F_11 ( V_74 , V_79 , V_2 , V_77 - V_2 ) ;
V_58 = V_19 -> V_21 ;
while( V_2 ++ < V_77 ) {
if ( -- V_76 >= 0 ) {
if ( V_78 & 0x80 ) {
if ( ! V_18 -> V_51 -> V_52 . V_53 ) {
V_58 = F_25 ( V_57 , V_58 , & V_20 , V_59 , V_24 ) ;
}
if ( ( * V_57 & 0xf0 ) == 0x10 ) {
if ( V_3 ) {
V_27 = F_19 ( V_3 , V_82 , V_74 ,
V_2 - 1 , 3 , V_40 ) ;
V_75 = F_20 ( V_27 , V_83 ) ;
F_3 ( V_75 , V_84 , V_74 ,
V_2 - 1 , 2 , F_32 ( V_57 ) ) ;
F_19 ( V_75 , V_85 , V_74 ,
V_2 + 1 , 1 , V_86 ) ;
}
V_57 += 3 ;
V_2 += 2 ;
} else{
if ( V_3 ) {
V_27 = F_19 ( V_3 , V_87 , V_74 ,
V_2 - 1 , 2 , V_40 ) ;
V_75 = F_20 ( V_27 , V_83 ) ;
F_3 ( V_75 , V_88 , V_74 ,
V_2 - 1 , 1 , * V_57 ) ;
F_3 ( V_75 , V_84 , V_74 ,
V_2 - 1 , 2 , F_32 ( V_57 ) ) ;
}
V_57 += 2 ;
V_2 += 1 ;
}
} else {
if ( ! V_18 -> V_51 -> V_52 . V_53 ) {
* V_58 = * V_57 ;
if ( V_58 ++ == V_24 )
V_58 = V_59 ;
}
++ V_57 ;
++ V_20 ;
}
if ( V_20 > V_63 ) {
return NULL ;
}
V_78 <<= 1 ;
} else {
V_78 = * V_57 ++ ;
if ( V_3 )
F_3 ( V_3 , V_89 , V_74 , V_2 - 1 , 1 ,
V_78 ) ;
V_76 = 8 ;
}
}
if ( V_18 -> V_51 -> V_52 . V_53 ) {
V_80 = F_33 ( V_18 -> V_51 , V_39 ) ;
if ( ! V_80 )
return NULL ;
V_20 = V_80 -> V_20 ;
} else {
V_80 = F_29 ( sizeof( T_12 ) ) ;
memcpy ( & V_80 -> V_22 , V_19 -> V_21 , V_20 ) ;
V_80 -> V_20 = V_20 ;
F_34 ( V_18 -> V_51 , V_39 , ( void * ) V_80 ) ;
V_19 -> V_21 = V_58 ;
}
F_35 {
V_1 = F_36 ( V_74 , V_80 -> V_22 , V_80 -> V_20 , V_80 -> V_20 ) ;
}
F_37 (BoundsError) {
F_38 () ;
}
F_37 (ReportedBoundsError) {
V_81 = TRUE ;
}
V_90 ;
if ( V_81 ) return NULL ;
F_39 ( V_18 , V_1 , L_7 ) ;
return V_1 ;
}
void
F_40 ( void )
{
static T_14 V_91 [] = {
{ & V_42 ,
{ L_8 , L_9 , V_92 , V_93 , F_41 ( V_37 ) , V_94 ,
L_10 , V_95 } } ,
{ & V_43 ,
{ L_11 , L_12 , V_92 , V_93 , F_41 ( V_38 ) , V_96 ,
L_13 , V_95 } } ,
{ & V_50 ,
{ L_14 , L_15 , V_97 , V_93 , NULL , V_98 ,
L_16 , V_95 } } ,
{ & V_55 ,
{ L_17 , L_18 , V_92 , V_99 , NULL , 0 ,
L_19 , V_95 } } ,
{ & V_5 ,
{ L_20 , L_21 , V_97 , V_99 , NULL , 0 ,
NULL , V_95 } } ,
{ & V_6 ,
{ L_22 , L_23 , V_92 , V_99 , NULL , 0 ,
NULL , V_95 } } ,
{ & V_7 ,
{ L_24 , L_25 , V_92 , V_99 , NULL , 0 ,
NULL , V_95 } } ,
{ & V_8 ,
{ L_26 , L_27 , V_92 , V_99 , NULL , 0 ,
L_28 , V_95 } } ,
{ & V_9 ,
{ L_29 , L_30 , V_92 , V_99 , NULL , 0 ,
L_31 , V_95 } } ,
{ & V_10 ,
{ L_32 , L_33 , V_92 , V_99 , NULL , 0 ,
L_34 , V_95 } } ,
{ & V_11 ,
{ L_35 , L_36 , V_92 , V_99 , NULL , 0 ,
L_37 , V_95 } } ,
{ & V_12 ,
{ L_38 , L_39 , V_92 , V_99 , NULL , 0 ,
L_40 , V_95 } } ,
{ & V_13 ,
{ L_41 , L_42 , V_92 , V_99 , NULL , 0 ,
L_43 , V_95 } } ,
{ & V_14 ,
{ L_44 , L_45 , V_92 , V_99 , NULL , 0 ,
L_46 , V_95 } } ,
{ & V_100 ,
{ L_47 , L_48 , V_92 , V_99 , NULL , 0 ,
L_49 , V_95 } } ,
{ & V_15 ,
{ L_50 , L_51 , V_92 , V_99 , NULL , 0 ,
L_52 , V_95 } } ,
{ & V_16 ,
{ L_53 , L_54 , V_92 , V_99 , NULL , 0 ,
L_55 , V_95 } } ,
{ & V_17 ,
{ L_56 , L_57 , V_92 , V_99 , NULL , 0 ,
NULL , V_95 } } ,
{ & V_89 ,
{ L_58 , L_59 , V_92 , V_93 , NULL , 0 ,
L_60 , V_95 } } ,
{ & V_101 ,
{ L_61 , L_62 , V_92 , V_99 , NULL , 0 ,
L_63 , V_95 } } ,
{ & V_84 ,
{ L_64 , L_65 , V_97 , V_93 , NULL , V_102 ,
L_66 , V_95 } } ,
{ & V_88 ,
{ L_67 , L_68 , V_92 , V_93 , NULL , 0xf0 ,
L_69 , V_95 } } ,
{ & V_85 ,
{ L_67 , L_70 , V_92 , V_93 , NULL , 0 ,
L_69 , V_95 } } ,
{ & V_82 ,
{ L_71 , L_72 , V_103 , V_104 , NULL , 0 ,
L_73 , V_95 } } ,
{ & V_87 ,
{ L_74 , L_75 , V_103 , V_104 , NULL , 0 ,
L_76 , V_95 } } ,
} ;
static V_25 * V_105 [] = {
& V_41 ,
& V_83 ,
} ;
V_39 = F_42 ( L_77 , L_1 , L_78 ) ;
F_43 ( V_39 , V_91 , F_44 ( V_91 ) ) ;
F_45 ( V_105 , F_44 ( V_105 ) ) ;
}
void
F_46 ( void ) {
T_15 V_106 ;
V_56 = F_47 ( L_79 ) ;
V_106 = F_48 ( F_12 , V_39 ) ;
F_49 ( L_80 , V_107 , V_106 ) ;
F_49 ( L_81 , V_108 , V_106 ) ;
}
