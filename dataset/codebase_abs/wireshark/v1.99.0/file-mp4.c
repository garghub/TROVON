static inline double
F_1 ( T_1 V_1 )
{
if ( V_1 == 0 )
return 0.0 ;
return ( double ) ( V_1 / exp ( log ( 10.0 ) * ( 1 + floor ( log ( ( double ) V_1 ) / log ( 10.0 ) ) ) ) ) ;
}
static T_2
F_2 ( T_3 * V_2 , T_2 V_3 , T_2 T_4 V_4 ,
T_5 * T_6 V_4 , T_7 * V_5 )
{
T_2 V_6 ;
V_6 = V_3 ;
F_3 ( V_5 , V_7 ,
V_2 , V_3 , 1 , V_8 ) ;
V_3 += 1 ;
F_3 ( V_5 , V_9 ,
V_2 , V_3 , 3 , V_8 ) ;
V_3 += 3 ;
return V_3 - V_6 ;
}
static T_2
F_4 ( T_3 * V_2 , T_2 V_3 , T_2 T_4 V_4 ,
T_5 * T_6 V_4 , T_7 * V_5 )
{
T_2 V_6 ;
V_6 = V_3 ;
F_3 ( V_5 , V_7 ,
V_2 , V_3 , 1 , V_8 ) ;
V_3 += 1 ;
F_3 ( V_5 , V_9 ,
V_2 , V_3 , 3 , V_8 ) ;
V_3 += 3 ;
F_3 ( V_5 , V_10 ,
V_2 , V_3 , 4 , V_8 ) ;
V_3 += 4 ;
return V_3 - V_6 ;
}
static T_2
F_5 ( T_3 * V_2 , T_2 V_3 , T_2 T_4 V_4 ,
T_5 * T_6 V_4 , T_7 * V_5 )
{
T_2 V_6 ;
T_8 V_11 ;
T_8 V_12 ;
double V_13 , V_14 ;
T_9 V_15 ;
V_6 = V_3 ;
V_11 = F_6 ( V_2 , V_3 ) ;
F_3 ( V_5 , V_7 ,
V_2 , V_3 , 1 , V_8 ) ;
V_3 += 1 ;
F_3 ( V_5 , V_9 ,
V_2 , V_3 , 3 , V_8 ) ;
V_3 += 3 ;
V_12 = ( V_11 == 0 ) ? 4 : 8 ;
F_3 ( V_5 , V_16 ,
V_2 , V_3 , V_12 , V_8 ) ;
V_3 += V_12 ;
F_3 ( V_5 , V_17 ,
V_2 , V_3 , V_12 , V_8 ) ;
V_3 += V_12 ;
F_3 ( V_5 , V_18 ,
V_2 , V_3 , 4 , V_8 ) ;
V_3 += 4 ;
V_3 += 4 ;
F_3 ( V_5 , V_19 ,
V_2 , V_3 , V_12 , V_8 ) ;
V_3 += V_12 ;
V_3 += 2 * 4 ;
V_3 += 2 ;
V_3 += 2 ;
V_3 += 2 ;
V_3 += 2 ;
V_3 += 9 * 4 ;
V_13 = F_7 ( V_2 , V_3 ) ;
V_15 = F_7 ( V_2 , V_3 + 2 ) ;
V_13 += F_1 ( V_15 ) ;
F_8 ( V_5 , V_20 ,
V_2 , V_3 , 4 , V_13 , L_1 , V_13 ) ;
V_3 += 4 ;
V_14 = F_7 ( V_2 , V_3 ) ;
V_15 = F_7 ( V_2 , V_3 + 2 ) ;
V_14 += F_1 ( V_15 ) ;
F_8 ( V_5 , V_21 ,
V_2 , V_3 , 4 , V_14 , L_1 , V_14 ) ;
V_3 += 4 ;
return V_3 - V_6 ;
}
static T_2
F_9 ( T_3 * V_2 , T_2 V_3 , T_2 T_4 ,
T_5 * T_6 V_4 , T_7 * V_5 )
{
T_2 V_6 ;
V_6 = V_3 ;
F_3 ( V_5 , V_22 ,
V_2 , V_3 , 4 , V_23 | V_24 ) ;
V_3 += 4 ;
F_3 ( V_5 , V_25 ,
V_2 , V_3 , 4 , V_8 ) ;
V_3 += 4 ;
while ( ( V_3 - V_6 ) < T_4 ) {
F_3 ( V_5 , V_26 ,
V_2 , V_3 , 4 , V_23 | V_24 ) ;
V_3 += 4 ;
}
return V_3 - V_6 ;
}
static T_2
F_10 ( T_3 * V_2 , T_2 V_3 , T_2 T_4 V_4 ,
T_5 * T_6 V_4 , T_7 * V_5 )
{
T_2 V_6 ;
T_1 V_27 ;
V_6 = V_3 ;
F_3 ( V_5 , V_7 ,
V_2 , V_3 , 1 , V_8 ) ;
V_3 += 1 ;
F_3 ( V_5 , V_9 ,
V_2 , V_3 , 3 , V_8 ) ;
V_3 += 3 ;
V_3 += 4 ;
F_3 ( V_5 , V_28 ,
V_2 , V_3 , 4 , V_23 | V_24 ) ;
V_3 += 4 ;
V_3 += 12 ;
V_27 = F_11 ( V_2 , V_3 ) ;
F_3 ( V_5 , V_29 ,
V_2 , V_3 , V_27 , V_30 | V_24 ) ;
V_3 += V_27 ;
return V_3 - V_6 ;
}
static T_2
F_12 ( T_3 * V_2 , T_2 V_3 , T_2 T_4 V_4 ,
T_5 * T_6 , T_7 * V_5 )
{
T_2 V_6 ;
T_10 V_31 , V_32 ;
T_2 V_33 ;
V_6 = V_3 ;
F_3 ( V_5 , V_7 ,
V_2 , V_3 , 1 , V_8 ) ;
V_3 += 1 ;
F_3 ( V_5 , V_9 ,
V_2 , V_3 , 3 , V_8 ) ;
V_3 += 3 ;
V_31 = F_13 ( V_2 , V_3 ) ;
F_3 ( V_5 , V_34 ,
V_2 , V_3 , 4 , V_8 ) ;
V_3 += 4 ;
for( V_32 = 0 ; V_32 < V_31 ; V_32 ++ ) {
V_33 = F_14 ( V_35 , V_2 , V_3 , T_6 , V_5 ) ;
if ( V_33 <= 0 )
break;
V_3 += V_33 ;
}
return V_3 - V_6 ;
}
static T_2
F_15 ( T_3 * V_2 , T_2 V_3 , T_2 T_4 ,
T_5 * T_6 V_4 , T_7 * V_5 )
{
#if 0
guint32 flags;
#endif
F_3 ( V_5 , V_7 ,
V_2 , V_3 , 1 , V_8 ) ;
V_3 += 1 ;
#if 0
flags = tvb_get_ntoh24(tvb, offset);
#endif
F_3 ( V_5 , V_9 ,
V_2 , V_3 , 3 , V_8 ) ;
F_3 ( V_5 , V_36 , V_2 , V_3 , 3 , V_8 ) ;
#if 0
if (flags&ENTRY_FLAG_MOVIE) {
}
else {
}
#endif
return T_4 ;
}
static T_2
F_16 ( T_3 * V_2 , T_2 V_3 , T_2 T_4 ,
T_5 * T_6 V_4 , T_7 * V_5 )
{
T_10 V_31 , V_32 ;
T_2 V_33 ;
F_3 ( V_5 , V_7 ,
V_2 , V_3 , 1 , V_8 ) ;
V_3 += 1 ;
F_3 ( V_5 , V_9 ,
V_2 , V_3 , 3 , V_8 ) ;
V_3 += 3 ;
V_31 = F_13 ( V_2 , V_3 ) ;
F_3 ( V_5 , V_34 ,
V_2 , V_3 , 4 , V_8 ) ;
V_3 += 4 ;
for( V_32 = 0 ; V_32 < V_31 ; V_32 ++ ) {
V_33 = F_14 ( V_37 , V_2 , V_3 , T_6 , V_5 ) ;
if ( V_33 <= 0 )
break;
V_3 += V_33 ;
}
return T_4 ;
}
static T_2
F_14 ( T_10 T_11 V_4 ,
T_3 * V_2 , T_2 V_3 , T_5 * T_6 , T_7 * V_5 )
{
T_2 V_6 ;
T_12 V_38 ;
T_10 V_39 ;
T_8 * V_40 ;
T_13 * V_41 , * V_42 , * V_43 = NULL ;
T_7 * V_44 ;
T_2 V_33 ;
T_2 V_45 ;
V_6 = V_3 ;
V_38 = ( T_12 ) F_13 ( V_2 , V_3 ) ;
if ( ( V_38 != V_46 ) && ( V_38 < V_47 ) )
return - 1 ;
V_39 = F_13 ( V_2 , V_3 + 4 ) ;
V_40 = F_17 ( F_18 () , V_2 ,
V_3 + 4 , 4 , V_23 | V_24 ) ;
V_44 = F_19 ( V_5 , V_2 , V_3 , - 1 , V_48 , & V_41 , L_2 ,
F_20 ( V_39 , V_49 , L_3 ) , V_40 ) ;
V_42 = F_3 ( V_44 , V_50 ,
V_2 , V_3 , 4 , V_8 ) ;
if ( V_38 == V_46 )
F_21 ( V_42 , L_4 ) ;
V_3 += 4 ;
F_3 ( V_44 , V_51 ,
V_2 , V_3 , 4 , V_23 | V_24 ) ;
V_3 += 4 ;
if ( V_38 == V_46 ) {
V_38 = F_22 ( V_2 , V_3 ) ;
V_43 = F_3 ( V_44 , V_52 ,
V_2 , V_3 , 8 , V_8 ) ;
V_3 += 8 ;
}
if ( V_38 > V_53 ) {
F_23 ( T_6 , V_43 , & V_54 ) ;
return - 1 ;
}
F_24 ( V_41 , ( T_2 ) V_38 ) ;
V_45 = ( T_2 ) V_38 - ( V_3 - V_6 ) ;
switch ( V_39 ) {
case V_55 :
F_9 ( V_2 , V_3 , V_45 , T_6 , V_44 ) ;
break;
case V_56 :
F_2 ( V_2 , V_3 , V_45 , T_6 , V_44 ) ;
break;
case V_57 :
F_4 ( V_2 , V_3 , V_45 , T_6 , V_44 ) ;
break;
case V_58 :
F_5 ( V_2 , V_3 , V_45 , T_6 , V_44 ) ;
break;
case V_59 :
F_10 ( V_2 , V_3 , V_45 , T_6 , V_44 ) ;
break;
case V_35 :
F_12 ( V_2 , V_3 , V_45 , T_6 , V_44 ) ;
break;
case V_60 :
F_15 ( V_2 , V_3 , V_45 , T_6 , V_44 ) ;
break;
case V_37 :
F_16 ( V_2 , V_3 , V_45 , T_6 , V_44 ) ;
break;
case V_61 :
case V_62 :
case V_63 :
case V_64 :
case V_65 :
case V_66 :
case V_67 :
case V_68 :
case V_69 :
case V_70 :
while ( V_3 - V_6 < ( T_2 ) V_38 ) {
V_33 = F_14 ( V_39 , V_2 , V_3 , T_6 , V_44 ) ;
if ( V_33 <= 0 )
break;
V_3 += V_33 ;
}
break;
default:
break;
}
return ( T_2 ) V_38 ;
}
static int
F_25 ( T_3 * V_2 , T_5 * T_6 , T_7 * V_5 , void * T_14 V_4 )
{
T_2 V_3 = 0 ;
T_10 V_39 ;
T_13 * V_71 ;
T_7 * V_72 ;
T_2 V_33 ;
if ( F_26 ( V_2 ) < V_47 )
return 0 ;
V_39 = F_13 ( V_2 , 4 ) ;
if ( F_27 ( V_39 , V_49 ) == NULL )
return 0 ;
F_28 ( T_6 -> V_73 , V_74 , L_5 ) ;
F_29 ( T_6 -> V_73 , V_75 ) ;
V_71 = F_30 ( V_5 , V_76 ,
V_2 , 0 , ( T_2 ) F_26 ( V_2 ) , L_5 ) ;
V_72 = F_31 ( V_71 , V_77 ) ;
while ( F_32 ( V_2 , V_3 ) > 0 ) {
V_33 = F_14 ( V_78 , V_2 , V_3 , T_6 , V_72 ) ;
if ( V_33 <= 0 )
break;
V_3 += V_33 ;
}
return V_3 ;
}
void
F_33 ( void )
{
static T_15 V_79 [] = {
{ & V_50 ,
{ L_6 , L_7 , V_80 , V_81 ,
NULL , 0 , NULL , V_82 } } ,
{ & V_51 ,
{ L_8 , L_9 , V_83 , V_84 ,
NULL , 0 , NULL , V_82 } } ,
{ & V_52 ,
{ L_10 , L_11 , V_85 , V_81 ,
NULL , 0 , NULL , V_82 } } ,
{ & V_7 ,
{ L_12 , L_13 , V_86 , V_81 ,
NULL , 0 , NULL , V_82 } } ,
{ & V_9 ,
{ L_14 , L_15 , V_87 , V_88 ,
NULL , 0 , NULL , V_82 } } ,
{ & V_36 ,
{ L_16 , L_17 , V_89 , 24 ,
NULL , V_90 , NULL , V_82 } } ,
{ & V_22 ,
{ L_18 , L_19 , V_83 , V_84 ,
NULL , 0 , NULL , V_82 } } ,
{ & V_25 ,
{ L_20 , L_21 , V_80 , V_81 ,
NULL , 0 , NULL , V_82 } } ,
{ & V_26 ,
{ L_22 , L_23 , V_83 ,
V_84 , NULL , 0 , NULL , V_82 } } ,
{ & V_10 ,
{ L_24 , L_25 , V_80 ,
V_81 , NULL , 0 , NULL , V_82 } } ,
{ & V_16 ,
{ L_26 , L_27 , V_85 ,
V_81 , NULL , 0 , NULL , V_82 } } ,
{ & V_17 ,
{ L_28 , L_29 , V_85 ,
V_81 , NULL , 0 , NULL , V_82 } } ,
{ & V_18 ,
{ L_30 , L_31 , V_80 ,
V_81 , NULL , 0 , NULL , V_82 } } ,
{ & V_19 ,
{ L_32 , L_33 , V_85 ,
V_81 , NULL , 0 , NULL , V_82 } } ,
{ & V_20 ,
{ L_34 , L_35 , V_91 ,
V_84 , NULL , 0 , NULL , V_82 } } ,
{ & V_21 ,
{ L_36 , L_37 , V_91 ,
V_84 , NULL , 0 , NULL , V_82 } } ,
{ & V_28 ,
{ L_38 , L_39 , V_83 ,
V_84 , NULL , 0 , NULL , V_82 } } ,
{ & V_29 ,
{ L_40 , L_41 , V_92 ,
V_84 , NULL , 0 , NULL , V_82 } } ,
{ & V_34 ,
{ L_42 , L_43 , V_80 ,
V_81 , NULL , 0 , NULL , V_82 } } ,
{ & V_93 ,
{ L_42 , L_44 , V_80 ,
V_81 , NULL , 0 , NULL , V_82 } }
} ;
static T_2 * V_94 [] = {
& V_77 ,
& V_48
} ;
static T_16 V_95 [] = {
{ & V_54 ,
{ L_45 , V_96 , V_97 ,
L_46 , V_98 } }
} ;
T_17 * V_99 ;
V_76 = F_34 ( L_47 , L_48 , L_48 ) ;
F_35 ( V_76 , V_79 , F_36 ( V_79 ) ) ;
F_37 ( V_94 , F_36 ( V_94 ) ) ;
V_99 = F_38 ( V_76 ) ;
F_39 ( V_99 , V_95 , F_36 ( V_95 ) ) ;
}
void
F_40 ( void )
{
T_18 V_100 = F_41 ( F_25 , V_76 ) ;
F_42 ( L_49 , L_50 , V_100 ) ;
}
