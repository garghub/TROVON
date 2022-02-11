static int
F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 ,
volatile T_4 V_4 , T_4 V_5 )
{
T_1 * V_6 ;
#ifdef F_2
F_3 ( V_2 -> V_7 , FALSE ) ;
#endif
V_6 = F_4 ( V_1 , V_4 , V_5 , V_5 ) ;
F_5 {
F_6 ( V_8 , V_6 , V_2 , V_3 ) ;
} F_7 {
F_8 ( V_6 , V_2 , V_3 , V_9 , V_10 ) ;
} V_11 ;
V_4 += V_5 ;
#ifdef F_2
F_3 ( V_2 -> V_7 , TRUE ) ;
#endif
return V_4 ;
}
static int
F_9 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_12 ,
T_4 V_4 , T_4 V_13 , T_5 V_14 )
{
T_6 * V_15 ;
T_3 * V_3 = NULL ;
T_3 * V_16 = NULL ;
T_3 * V_17 = NULL ;
T_3 * V_18 = NULL ;
T_7 V_19 ;
T_7 V_20 ;
T_8 type , V_5 , V_21 ;
T_4 V_22 ;
T_8 V_23 ;
static T_9 * V_24 ;
if ( ! V_12 )
return V_13 ;
V_20 = F_10 ( V_1 , V_4 + 12 ) ;
F_11 ( V_2 -> V_7 , V_25 , V_26 ) ;
F_12 ( V_2 -> V_7 , V_27 , F_13 ( V_20 ,
V_28 , L_1 ) ) ;
V_15 = F_14 ( V_12 , V_29 , V_1 ,
V_4 , V_13 , V_30 ) ;
V_3 = F_15 ( V_15 , V_31 ) ;
V_15 = F_14 ( V_3 , & V_32 , V_1 ,
V_4 , 16 , V_30 ) ;
V_16 = F_15 ( V_15 , V_33 ) ;
F_14 ( V_16 , & V_34 , V_1 ,
V_4 , 4 , V_30 ) ;
V_4 += 4 ;
F_14 ( V_16 , & V_35 , V_1 ,
V_4 , 4 , V_30 ) ;
V_4 += 4 ;
F_14 ( V_16 , & V_36 , V_1 ,
V_4 , 4 , V_30 ) ;
V_4 += 4 ;
F_14 ( V_16 , & V_37 , V_1 ,
V_4 , 2 , V_38 ) ;
V_4 += 2 ;
F_14 ( V_16 , & V_39 , V_1 ,
V_4 , 2 , V_38 ) ;
V_4 += 2 ;
switch( V_20 ) {
case V_40 :
V_15 = F_14 ( V_3 , & V_41 , V_1 ,
V_4 , V_13 - 16 , V_30 ) ;
V_17 = F_15 ( V_15 , V_42 ) ;
F_14 ( V_17 , & V_43 , V_1 ,
V_4 , 2 , V_30 ) ;
V_4 += 2 ;
if ( V_4 < V_13 )
V_4 += F_1 ( V_1 , V_2 , V_12 ,
V_4 , V_13 - V_4 ) ;
break;
case V_44 :
V_15 = F_14 ( V_3 , & V_41 , V_1 ,
V_4 , V_13 - 16 , V_30 ) ;
V_17 = F_15 ( V_15 , V_42 ) ;
F_14 ( V_17 , & V_45 , V_1 ,
V_4 , 2 , V_38 ) ;
V_4 += 2 ;
F_14 ( V_17 , & V_46 , V_1 ,
V_4 , 4 , V_30 ) ;
V_4 += 4 ;
F_14 ( V_17 , & V_43 , V_1 ,
V_4 , 4 , V_30 ) ;
V_4 += 4 ;
if ( V_4 < V_13 )
V_4 += F_1 ( V_1 , V_2 , V_12 ,
V_4 , V_13 - V_4 ) ;
break;
case V_47 :
V_15 = F_14 ( V_3 , & V_48 , V_1 ,
V_4 , V_13 - 16 , V_30 ) ;
V_18 = F_15 ( V_15 , V_49 ) ;
F_14 ( V_18 , & V_50 , V_1 ,
V_4 , 32 , V_30 ) ;
V_4 += 32 ;
F_14 ( V_18 , & V_51 , V_1 ,
V_4 , 1 , V_30 ) ;
V_4 += 1 ;
F_14 ( V_18 , & V_52 , V_1 ,
V_4 , 1 , V_30 ) ;
V_4 += 1 ;
F_14 ( V_18 , & V_53 , V_1 ,
V_4 , 1 , V_30 ) ;
V_4 += 1 ;
V_21 = F_16 ( V_1 , V_4 ) ;
F_14 ( V_18 , & V_54 , V_1 ,
V_4 , 1 , V_30 ) ;
V_4 += 1 ;
V_22 = F_17 ( V_1 , V_4 ) ;
F_14 ( V_18 , & V_55 , V_1 ,
V_4 , 4 , V_30 ) ;
V_4 += 4 ;
F_14 ( V_18 , & V_56 , V_1 ,
V_4 , 4 , V_30 ) ;
V_4 += 4 ;
switch ( V_22 ) {
case 0x43534E50 :
V_23 = 12 ;
V_24 = & V_57 ;
break;
case 0x48454C4F :
V_23 = 0 ;
V_24 = & V_58 ;
break;
case 0x4C535000 :
V_23 = 8 ;
V_24 = & V_59 ;
break;
case 0x50534E50 :
V_23 = 4 ;
V_24 = & V_60 ;
break;
default:
V_23 = 0 ;
V_24 = & V_61 ;
}
if ( V_21 > 12 ) {
F_14 ( V_18 , & V_62 , V_1 ,
V_4 , V_21 - 12 , V_30 ) ;
V_4 += V_21 - 12 ;
}
while ( V_4 < V_13 - 2 ) {
type = F_16 ( V_1 , V_4 ) ;
F_14 ( V_18 , V_24 , V_1 ,
V_4 , 1 , V_30 ) ;
V_4 += 1 ;
V_5 = F_16 ( V_1 , V_4 ) ;
if ( type == 1 && V_5 == 128 ) {
F_14 ( V_18 , & V_63 , V_1 ,
V_4 , 1 , V_30 ) ;
V_4 += 1 ;
V_5 = F_16 ( V_1 , V_4 ) ;
}
F_14 ( V_18 , & V_64 , V_1 ,
V_4 , 1 , V_30 ) ;
V_4 += 1 ;
if ( V_4 + V_5 > V_13 ) {
break;
}
if ( type == 1 && V_23 ) {
T_4 V_65 = V_4 + V_5 ;
for (; V_4 < V_65 ; V_4 += V_23 ) {
F_14 ( V_18 , & V_66 , V_1 ,
V_4 , V_23 , V_30 ) ;
}
} else {
F_14 ( V_18 , & V_67 , V_1 ,
V_4 , V_5 , V_30 ) ;
V_4 += V_5 ;
}
}
break;
case V_68 :
V_15 = F_14 ( V_3 , & V_48 , V_1 ,
V_4 , V_13 - 16 , V_30 ) ;
V_18 = F_15 ( V_15 , V_49 ) ;
F_14 ( V_18 , & V_50 , V_1 ,
V_4 , 32 , V_30 ) ;
V_4 += 32 ;
V_19 = V_13 - V_4 ;
F_14 ( V_18 , & V_69 , V_1 ,
V_4 , V_19 , V_30 ) ;
V_4 += V_19 ;
break;
case V_70 :
V_15 = F_14 ( V_3 , & V_48 , V_1 ,
V_4 , V_13 - 16 , V_30 ) ;
V_18 = F_15 ( V_15 , V_49 ) ;
F_14 ( V_18 , & V_50 , V_1 ,
V_4 , 32 , V_30 ) ;
V_4 += 32 ;
F_14 ( V_18 , & V_71 , V_1 ,
V_4 , 2 , V_38 ) ;
V_4 += 2 ;
while ( V_4 < V_13 - 2 ) {
F_14 ( V_18 , & V_72 , V_1 ,
V_4 , 1 , V_30 ) ;
V_4 += 1 ;
V_5 = F_16 ( V_1 , V_4 ) ;
F_14 ( V_18 , & V_73 , V_1 ,
V_4 , 1 , V_30 ) ;
V_4 += 1 ;
if ( V_4 + V_5 > V_13 ) {
break;
}
F_14 ( V_18 , & V_74 , V_1 ,
V_4 , V_5 , V_30 ) ;
V_4 += V_5 ;
}
break;
default:
V_19 = V_13 - V_4 ;
switch( V_14 ) {
case V_75 :
case V_76 :
F_14 ( V_3 , & V_77 , V_1 ,
V_4 , V_19 , V_30 ) ;
break;
case V_78 :
F_14 ( V_3 , & V_43 , V_1 ,
V_4 , V_19 , V_30 ) ;
break;
default:
F_18 () ;
}
V_4 += V_19 ;
break;
}
#if V_79 F_2
F_19 ( V_31 , TRUE ) ;
F_19 ( V_80 , TRUE ) ;
F_19 ( V_33 , TRUE ) ;
F_19 ( V_49 , TRUE ) ;
F_19 ( V_42 , TRUE ) ;
#endif
return V_4 ;
}
static int
F_20 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_12 )
{
T_4 V_4 = 0 ;
T_4 V_13 = F_21 ( V_1 , 0 ) ;
V_4 += F_9 ( V_1 , V_2 , V_12 , 0 , V_13 ,
V_75 ) ;
return V_4 ;
}
static int
F_22 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_12 )
{
T_4 V_4 = 0 ;
T_4 V_13 = F_21 ( V_1 , 0 ) ;
V_4 += F_9 ( V_1 , V_2 , V_12 , 0 , V_13 ,
V_78 ) ;
return V_4 ;
}
static int
F_23 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_12 )
{
T_6 * V_15 ;
T_3 * V_81 = NULL ;
T_4 V_4 = 0 ;
T_4 V_13 ;
V_15 = F_14 ( V_12 , & V_82 , V_1 ,
V_4 , 4 , V_30 ) ;
V_81 = F_15 ( V_15 , V_80 ) ;
F_14 ( V_81 , & V_83 , V_1 ,
V_4 , 2 , V_30 ) ;
V_4 += 2 ;
F_14 ( V_81 , & V_84 , V_1 ,
V_4 , 2 , V_38 ) ;
V_13 = F_10 ( V_1 , V_4 ) + 4 ;
V_4 += 2 ;
V_4 += F_9 ( V_1 , V_2 , V_12 , 4 , V_13 , V_76 ) ;
return V_4 ;
}
static T_10
F_24 ( T_1 * V_1 V_85 )
{
#if 0
if ( tvb_length(tvb) < 8
|| tvb_get_guint8(tvb, 0) != 3
) {
return FALSE;
}
#endif
return TRUE ;
}
static T_10
F_25 ( T_1 * V_1 V_85 )
{
#if 0
if ( tvb_length(tvb) < 8
|| tvb_get_guint8(tvb, 0) != 3
) {
return FALSE;
}
#endif
return TRUE ;
}
static T_10
F_26 ( T_1 * V_1 V_85 )
{
#if 0
if ( tvb_length(tvb) < 8
|| tvb_get_guint8(tvb, 0) != 3
) {
return FALSE;
}
#endif
return TRUE ;
}
static int
F_27 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_12 , void * T_11 V_85 )
{
if ( ! F_24 ( V_1 ) ) {
return 0 ;
}
return F_20 ( V_1 , V_2 , V_12 ) ;
}
static int
F_28 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_12 , void * T_11 V_85 )
{
if ( ! F_25 ( V_1 ) ) {
return 0 ;
}
return F_22 ( V_1 , V_2 , V_12 ) ;
}
static int
F_29 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_12 , void * T_11 V_85 )
{
if ( ! F_26 ( V_1 ) ) {
return 0 ;
}
return F_23 ( V_1 , V_2 , V_12 ) ;
}
void
F_30 ( void )
{
#ifndef F_31
static T_9 * V_86 [] = {
& V_82 ,
& V_83 ,
& V_84 ,
& V_32 ,
& V_34 ,
& V_36 ,
& V_35 ,
& V_39 ,
& V_37 ,
& V_41 ,
& V_45 ,
& V_46 ,
& V_43 ,
& V_48 ,
& V_50 ,
& V_77 ,
& V_55 ,
& V_56 ,
& V_51 ,
& V_52 ,
& V_53 ,
& V_54 ,
& V_62 ,
& V_61 ,
& V_57 ,
& V_58 ,
& V_59 ,
& V_60 ,
& V_64 ,
& V_63 ,
& V_66 ,
& V_67 ,
& V_69 ,
& V_71 ,
& V_72 ,
& V_73 ,
& V_74 ,
} ;
#endif
static T_12 * V_87 [] = {
& V_80 ,
& V_31 ,
& V_33 ,
& V_49 ,
& V_42 ,
} ;
int V_88 ;
V_88 = F_32 ( V_89 , V_26 , L_2 ) ;
V_29 = F_33 ( V_88 ) ;
F_34 ( V_88 , V_86 , F_35 ( V_86 ) ) ;
F_36 ( V_87 , F_35 ( V_87 ) ) ;
V_90 = F_37 ( F_27 , V_88 ) ;
V_91 = F_37 ( F_28 , V_88 ) ;
V_92 = F_37 ( F_29 , V_88 ) ;
}
void
F_38 ( void )
{
F_39 ( L_3 , V_75 , V_90 ) ;
F_39 ( L_3 , V_78 , V_91 ) ;
F_39 ( L_4 , V_76 , V_92 ) ;
V_8 = F_40 ( L_5 ) ;
}
