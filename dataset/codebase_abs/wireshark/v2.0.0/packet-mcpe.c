static void
F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 V_3 )
{
T_4 V_4 ;
T_3 V_5 ;
V_5 = 2 ;
F_2 ( V_2 , V_6 , V_1 , V_3 ,
V_5 , V_7 ) ;
V_3 += V_5 ;
V_4 = ( F_3 ( V_1 , V_3 ) != 0 ) ;
V_5 = 1 ;
F_2 ( V_2 , V_8 , V_1 , V_3 ,
V_5 , V_7 ) ;
V_3 += V_5 ;
V_5 = 3 ;
F_2 ( V_2 , V_9 , V_1 , V_3 ,
V_5 , V_7 ) ;
V_3 += V_5 ;
if ( ! V_4 ) {
V_5 = 3 ;
F_2 ( V_2 , V_9 , V_1 ,
V_3 , V_5 , V_7 ) ;
}
}
static void
F_4 ( T_1 * V_1 , T_2 * V_10 ,
T_3 * V_3 )
{
T_3 V_5 ;
V_5 = 2 ;
F_2 ( V_10 , V_11 , V_1 ,
* V_3 , V_5 , V_7 ) ;
* V_3 += V_5 ;
}
static void
F_5 ( T_1 * V_1 , T_2 * V_10 ,
T_3 * V_3 )
{
T_3 V_5 ;
V_5 = 2 ;
F_2 ( V_10 , V_11 , V_1 ,
* V_3 , V_5 , V_7 ) ;
* V_3 += V_5 ;
V_5 = 3 ;
F_2 ( V_10 , V_12 , V_1 ,
* V_3 , V_5 , V_7 ) ;
* V_3 += V_5 ;
}
static void
F_6 ( T_1 * V_1 , T_2 * V_10 , T_3 V_3 )
{
T_3 V_13 ;
T_3 V_5 ;
V_5 = 3 ;
F_2 ( V_10 , V_9 , V_1 , V_3 ,
V_5 , V_7 ) ;
V_3 += V_5 ;
V_13 = F_3 ( V_1 , V_3 ) ;
V_5 = 1 ;
F_2 ( V_10 , V_14 , V_1 , V_3 ,
V_5 , V_7 ) ;
V_3 += V_5 ;
switch ( V_13 ) {
case 0x00 :
F_4 ( V_1 , V_10 , & V_3 ) ;
break;
case 0x40 :
case 0x50 :
case 0x60 :
F_5 ( V_1 , V_10 , & V_3 ) ;
break;
default:
break;
}
V_5 = - 1 ;
F_2 ( V_10 , V_15 , V_1 , V_3 ,
V_5 , V_16 ) ;
}
static T_2 *
F_7 ( T_1 * V_1 , T_5 * V_17 , T_2 * V_18 , T_3 * V_3 )
{
const char * V_19 ;
T_6 V_20 ;
T_2 * V_21 ;
T_7 * V_22 ;
F_8 ( V_17 -> V_23 , V_24 , L_1 ) ;
F_9 ( V_17 -> V_23 , V_25 ) ;
V_22 = F_2 ( V_18 , V_26 , V_1 , 0 , - 1 , V_16 ) ;
V_21 = F_10 ( V_22 , V_27 ) ;
V_20 = F_3 ( V_1 , * V_3 ) ;
F_2 ( V_21 , V_28 , V_1 , * V_3 ,
1 , V_7 ) ;
* V_3 += 1 ;
switch ( V_20 ) {
case 0xA0 :
V_19 = L_2 ;
break;
case 0xC0 :
V_19 = L_3 ;
break;
default:
V_19 = L_4 ;
break;
}
F_11 ( V_17 -> V_23 , V_25 , L_5 , V_20 , V_19 ) ;
F_12 ( V_22 , L_6 , V_20 ) ;
return V_21 ;
}
static int
F_13 ( T_1 * V_1 , T_5 * V_17 , T_2 * V_18 ,
void * T_8 V_29 )
{
T_2 * V_21 ;
T_3 V_3 ;
V_3 = 0 ;
V_21 = F_7 ( V_1 , V_17 , V_18 , & V_3 ) ;
if ( V_21 != NULL ) {
F_6 ( V_1 , V_21 , V_3 ) ;
}
return F_14 ( V_1 ) ;
}
static int
F_15 ( T_1 * V_1 , T_5 * V_17 , T_2 * V_18 ,
void * T_8 V_29 )
{
T_2 * V_21 ;
T_3 V_3 ;
V_3 = 0 ;
V_21 = F_7 ( V_1 , V_17 , V_18 , & V_3 ) ;
if ( V_21 != NULL ) {
F_1 ( V_1 , V_21 , V_3 ) ;
}
return F_14 ( V_1 ) ;
}
static int
F_16 ( T_1 * V_1 , T_5 * V_17 , T_2 * V_18 ,
void * T_8 V_29 )
{
T_2 * V_21 ;
T_3 V_3 ;
V_3 = 0 ;
V_21 = F_7 ( V_1 , V_17 , V_18 , & V_3 ) ;
if ( V_21 != NULL ) {
F_1 ( V_1 , V_21 , V_3 ) ;
}
return F_14 ( V_1 ) ;
}
void
F_17 ( void )
{
static T_9 V_30 [] = {
{ & V_28 ,
{ L_7 , L_8 ,
V_31 , V_32 ,
NULL , 0x0 ,
NULL , V_33 }
} ,
{ & V_14 ,
{ L_9 , L_10 ,
V_31 , V_32 ,
NULL , 0x0 ,
NULL , V_33 }
} ,
{ & V_9 ,
{ L_11 , L_12 ,
V_34 , V_35 ,
NULL , 0x0 ,
NULL , V_33 }
} ,
{ & V_15 ,
{ L_13 , L_14 ,
V_36 , V_37 ,
NULL , 0x0 ,
NULL , V_33 }
} ,
{ & V_11 ,
{ L_15 , L_16 ,
V_38 , V_35 ,
NULL , 0x0 ,
NULL , V_33 }
} ,
{ & V_12 ,
{ L_17 , L_18 ,
V_34 , V_35 ,
NULL , 0x0 ,
NULL , V_33 }
} ,
{ & V_6 ,
{ L_19 , L_20 ,
V_31 , V_35 ,
NULL , 0x0 ,
NULL , V_33 }
} ,
{ & V_8 ,
{ L_21 , L_22 ,
V_31 , V_35 ,
NULL , 0x0 ,
NULL , V_33 }
}
} ;
static T_3 * V_39 [] = {
& V_27 ,
} ;
T_10 * V_40 ;
V_26 = F_18 (
L_23 ,
L_1 ,
L_24
) ;
F_19 ( V_26 , V_30 , F_20 ( V_30 ) ) ;
F_21 ( V_39 , F_20 ( V_39 ) ) ;
V_40 = F_22 ( V_26 ,
V_41 ) ;
F_23 ( V_40 , L_25 ,
L_26 ,
L_27 ,
10 , & V_42 ) ;
}
void
V_41 ( void )
{
static T_11 V_43 = NULL ;
static T_12 V_44 ;
static T_4 V_45 = FALSE ;
if ( V_45 ) {
F_24 ( L_25 , V_44 , V_43 ) ;
} else {
T_11 V_46 ;
V_45 = TRUE ;
V_43 = F_25 ( L_28 ) ;
V_46 = F_26 ( F_13 , V_26 ) ;
F_27 ( L_29 , 0x80 , V_46 ) ;
F_27 ( L_29 , 0x84 , V_46 ) ;
F_27 ( L_29 , 0x88 , V_46 ) ;
F_27 ( L_29 , 0x8C , V_46 ) ;
F_27 ( L_29 , 0xA0 ,
F_26 ( F_15 ,
V_26 ) ) ;
F_27 ( L_29 , 0xC0 ,
F_26 ( F_16 ,
V_26 ) ) ;
}
V_44 = V_42 ;
F_27 ( L_25 , V_42 , V_43 ) ;
}
