static int F_1 ( const T_1 * V_1 , T_2 V_2 )
{
const unsigned char * V_3 = V_1 ;
const unsigned char * V_4 = V_3 + V_2 ;
for (; V_3 != V_4 ; V_3 ++ ) {
if ( * V_3 & 0x80 )
return FALSE ;
}
return TRUE ;
}
static int F_2 ( T_3 * V_5 ) {
T_2 V_6 ;
const T_1 * V_7 ;
V_6 = F_3 ( V_5 , V_8 ) ;
V_7 = F_4 ( V_5 , V_8 , V_6 ) ;
return F_1 ( V_7 , V_6 ) && V_7 [ V_6 - 1 ] == '\n' ;
}
static int F_5 ( T_3 * V_5 , T_4 * V_9 , T_5 * V_10 ) {
int V_11 = 0 ;
T_2 V_12 ;
T_2 V_13 ;
T_6 * V_14 ;
T_6 * * V_15 ;
T_6 * V_16 ;
T_6 * V_17 ;
F_6 ( V_9 -> V_18 , V_19 , L_1 ) ;
V_13 = F_7 ( V_5 , V_11 , F_3 ( V_5 , V_11 ) , & V_12 , FALSE ) ;
if( V_13 != - 1 ) {
V_14 = ( T_6 * ) F_8 ( F_9 () , V_5 , V_11 , V_13 , V_20 ) ;
V_15 = F_10 ( F_9 () , V_14 , L_2 , - 1 ) ;
if( V_15 != NULL ) {
V_16 = V_15 [ 0 ] ;
if ( V_16 ) {
F_11 ( V_10 , V_21 , V_5 , V_11 , ( V_22 ) strlen ( V_16 ) , V_16 ) ;
V_11 += ( int ) strlen ( V_16 ) + V_23 ;
V_17 = V_15 [ 1 ] ;
if ( V_17 ) {
F_11 ( V_10 , V_24 , V_5 , V_11 , ( V_22 ) strlen ( V_17 ) , V_17 ) ;
}
} else {
V_17 = NULL ;
}
F_12 ( V_9 -> V_18 , V_19 , L_3 , V_16 ? V_16 : L_4 , V_17 ? V_17 : L_4 ) ;
}
}
return V_13 ;
}
static int F_13 ( const T_6 * type , T_3 * V_5 ) {
T_6 * V_25 ;
if( F_3 ( V_5 , V_8 ) != V_26 ) {
return 0 ;
}
V_25 = ( T_6 * ) F_8 ( F_9 () , V_5 , V_8 ,
V_26 , V_20 ) ;
return F_14 ( V_25 , F_15 ( L_5 , type ) ) == 0 ;
}
static int F_16 ( T_3 * V_5 ) {
return F_13 ( L_6 , V_5 ) ;
}
static int F_17 ( T_3 * V_5 ) {
return F_13 ( L_7 , V_5 ) ;
}
static int F_18 ( T_3 * V_5 , T_4 * V_9 , T_5 * V_27 ) {
int V_11 = V_8 ;
F_6 ( V_9 -> V_18 , V_19 , L_8 ) ;
F_19 ( V_27 , V_28 , V_5 , V_11 , V_26 , V_20 | V_29 ) ;
V_11 += V_26 ;
return V_11 ;
}
static int F_20 ( T_3 * V_5 , T_4 * V_9 , T_5 * V_27 ) {
int V_11 = V_8 ;
F_6 ( V_9 -> V_18 , V_19 , L_9 ) ;
F_19 ( V_27 , V_30 , V_5 , V_11 , V_26 , V_20 | V_29 ) ;
V_11 += V_26 ;
return V_11 ;
}
static void F_21 ( T_4 * V_9 ) {
T_7 * V_31 ;
T_8 * V_32 ;
V_31 = F_22 ( V_9 ) ;
V_32 = ( T_8 * ) F_23 ( V_31 , V_33 ) ;
if( V_32 == NULL ) {
V_32 = F_24 ( F_25 () , T_8 ) ;
}
V_32 -> V_34 = V_9 -> V_35 -> V_36 ;
F_26 ( V_31 , V_33 , V_32 ) ;
}
static int F_27 ( T_4 * V_9 ) {
T_7 * V_31 ;
T_8 * V_32 ;
V_31 = F_22 ( V_9 ) ;
V_32 = ( T_8 * ) F_23 ( V_31 , V_33 ) ;
if( V_32 == NULL ) {
return FALSE ;
}
return V_9 -> V_35 -> V_36 >= V_32 -> V_34 ;
}
static int F_28 ( T_3 * V_5 , T_4 * V_9 , T_5 * V_10 ) {
V_9 -> V_37 = V_9 -> V_38 ;
return F_29 ( V_39 , V_5 , V_9 , V_10 ) ;
}
static int F_30 ( T_3 * V_5 , T_4 * V_9 , T_5 * V_10 ) {
T_9 * V_40 ;
T_5 * V_27 ;
V_40 = F_19 ( V_10 , V_33 , V_5 , 0 , - 1 , V_29 ) ;
V_27 = F_31 ( V_40 , V_41 ) ;
if ( F_16 ( V_5 ) ) {
return F_18 ( V_5 , V_9 , V_27 ) ;
} else if ( F_17 ( V_5 ) ) {
return F_20 ( V_5 , V_9 , V_27 ) ;
} else if ( F_2 ( V_5 ) ) {
return F_5 ( V_5 , V_9 , V_27 ) ;
} else {
F_21 ( V_9 ) ;
}
return F_32 ( V_5 , 0 ) ;
}
static int F_33 ( T_3 * V_5 , T_4 * V_9 , T_5 * V_10 , void * V_1 V_42 ) {
F_6 ( V_9 -> V_18 , V_43 , L_10 ) ;
F_34 ( V_9 -> V_18 , V_19 ) ;
if( F_27 ( V_9 ) ) {
return F_28 ( V_5 , V_9 , V_10 ) ;
}
else {
return F_30 ( V_5 , V_9 , V_10 ) ;
}
}
void F_35 ( void ) {
static T_10 V_44 [] = {
{ & V_21 ,
{ L_11 , L_12 ,
V_45 , V_46 ,
NULL , 0x0 ,
NULL , V_47
}
} ,
{ & V_24 ,
{ L_13 , L_14 ,
V_45 , V_46 ,
NULL , 0x0 ,
NULL , V_47
}
} ,
{ & V_30 ,
{ L_15 , L_16 ,
V_45 , V_46 ,
NULL , 0x0 ,
NULL , V_47
}
} ,
{ & V_28 ,
{ L_17 , L_18 ,
V_45 , V_46 ,
NULL , 0x0 ,
NULL , V_47
}
} ,
} ;
static T_2 * V_48 [] = {
& V_41 ,
} ;
V_33 = F_36 ( L_19 , L_10 , L_20 ) ;
F_37 ( V_33 , V_44 , F_38 ( V_44 ) ) ;
F_39 ( V_48 , F_38 ( V_48 ) ) ;
}
void F_40 ( void ) {
V_49 = F_41 ( F_33 , V_33 ) ;
V_39 = F_42 ( L_21 ) ;
F_43 ( L_22 , V_50 , V_49 ) ;
}
