static int F_1 ( T_1 * V_1 , T_2 * T_3 V_2 ,
int V_3 , int V_4 , T_4 * V_5 , T_5 * V_6 , int V_7 )
{
T_6 V_8 ;
int V_9 = 0 , V_10 ;
int V_11 ;
int V_12 = 0 ;
if ( V_4 < 2 ) {
F_2 ( V_5 , V_1 , V_3 , V_4 , L_1 ) ;
return - 1 ;
}
V_11 = 0 ;
while ( V_4 >= 1 ) {
V_8 = F_3 ( V_1 , V_3 + V_11 ) ;
V_4 -- ;
V_11 ++ ;
if ( V_8 == ':' && V_11 > 1 ) {
if ( V_9 > V_4 || V_9 < 0 ) {
F_2 ( V_5 , V_1 , V_3 , V_4 , L_2 ) ;
return - 1 ;
}
if ( V_5 ) {
F_4 ( V_5 , V_13 , V_1 , V_3 , V_11 , V_9 ) ;
F_5 ( V_5 , V_14 , V_1 , V_3 + V_11 , V_9 , V_15 | V_16 ) ;
if ( V_7 == 1 ) {
F_6 ( V_6 , L_3 , F_7 ( ( V_17 * ) F_8 ( F_9 () , V_1 , V_3 + V_11 , V_9 ) , V_9 ) ) ;
}
if ( V_7 == 2 ) {
F_6 ( V_6 , L_4 , F_7 ( ( V_17 * ) F_8 ( F_9 () , V_1 , V_3 + V_11 , V_9 ) , V_9 ) ) ;
}
}
return V_11 + V_9 ;
}
if ( ! V_12 && V_8 >= '0' && V_8 <= '9' ) {
if ( V_8 == '0' && V_11 == 1 ) {
V_12 = 1 ;
}
V_10 = ( V_9 * 10 ) + ( V_8 - '0' ) ;
if ( V_10 >= V_9 ) {
V_9 = V_10 ;
continue;
}
}
F_2 ( V_5 , V_1 , V_3 , V_4 , L_1 ) ;
return - 1 ;
}
F_2 ( V_5 , V_1 , V_3 , V_4 , L_5 ) ;
return - 1 ;
}
static int F_10 ( T_1 * V_1 , T_2 * T_3 V_2 ,
int V_3 , int V_4 , T_4 * V_5 , T_5 * V_6 , int V_7 )
{
T_7 V_18 = 0 ;
int V_19 = 0 ;
int V_12 = 0 ;
int V_11 ;
T_6 V_8 ;
if ( V_4 < 3 ) {
F_2 ( V_5 , V_1 , V_3 , V_4 , L_6 ) ;
return - 1 ;
}
V_4 -- ;
V_11 = 1 ;
while ( V_4 >= 1 ) {
V_8 = F_3 ( V_1 , V_3 + V_11 ) ;
V_4 -- ;
V_11 ++ ;
switch ( V_8 ) {
case 'e' :
if ( V_5 ) {
if ( V_19 ) V_18 = - V_18 ;
F_11 ( V_5 , V_20 , V_1 , V_3 , V_11 , V_18 ) ;
if ( V_7 == 2 ) {
F_6 ( V_6 , L_7 , V_18 ) ;
}
}
return V_11 ;
case '-' :
if ( V_11 == 2 ) {
V_19 = 1 ;
break;
}
default:
if ( ! ( V_8 == '0' && V_11 == 3 && V_19 ) ) {
if ( V_8 == '0' && V_11 == 2 ) {
V_12 = 1 ;
break;
}
if ( ! V_12 && V_8 >= '0' && V_8 <= '9' ) {
V_18 = ( V_18 * 10 ) + ( V_8 - '0' ) ;
break;
}
}
F_2 ( V_5 , V_1 , V_3 , V_4 , L_6 ) ;
return - 1 ;
}
}
F_2 ( V_5 , V_1 , V_3 , V_4 , L_5 ) ;
return - 1 ;
}
static int F_12 ( T_1 * V_1 , T_2 * T_3 V_2 ,
int V_3 , int V_4 , T_4 * V_5 , int V_21 , T_5 * V_22 , int V_7 )
{
T_6 V_23 ;
int V_24 = 0 , V_25 , V_26 ;
int V_11 ;
T_5 * V_6 = NULL , * V_27 = NULL ;
T_4 * V_28 = NULL , * V_29 = NULL ;
if ( V_21 > 10 ) {
F_2 ( V_5 , V_1 , V_3 , - 1 , L_8 ) ;
return - 1 ;
}
if ( V_4 < 1 ) {
F_2 ( V_5 , V_1 , V_3 , - 1 , L_5 ) ;
return V_4 ;
}
V_23 = F_3 ( V_1 , V_3 ) ;
if ( V_5 ) {
V_24 = F_12 ( V_1 , T_3 , V_3 , V_4 , NULL , V_21 , NULL , 0 ) ;
if ( V_24 < 0 ) V_24 = V_4 ;
}
switch ( V_23 ) {
case 'd' :
if ( V_5 ) {
V_27 = F_5 ( V_5 , V_30 , V_1 , V_3 , V_24 , V_16 ) ;
V_29 = F_13 ( V_27 , V_31 ) ;
}
V_11 = 1 ;
V_4 -- ;
while ( V_4 >= 1 ) {
V_23 = F_3 ( V_1 , V_3 + V_11 ) ;
if ( V_23 == 'e' ) {
return V_11 + 1 ;
}
V_25 = F_1 ( V_1 , T_3 , V_3 + V_11 , V_4 , NULL , NULL , 0 ) ;
if ( V_25 < 0 ) {
if ( V_29 ) {
F_2 ( V_29 , V_1 , V_3 + V_11 , - 1 , L_9 ) ;
}
return V_25 ;
}
V_26 = - 1 ;
if ( V_4 - V_25 > 2 )
V_26 = F_12 ( V_1 , T_3 , V_3 + V_11 + V_25 , V_4 - V_25 , NULL , V_21 + 1 , NULL , 0 ) ;
if ( V_26 < 0 ) {
if ( V_29 ) {
F_2 ( V_29 , V_1 , V_3 + V_11 + V_25 , - 1 , L_10 ) ;
}
return V_26 ;
}
if ( V_29 ) {
V_6 = F_5 ( V_29 , V_32 , V_1 , V_3 + V_11 , V_25 + V_26 , V_16 ) ;
V_28 = F_13 ( V_6 , V_33 ) ;
F_1 ( V_1 , T_3 , V_3 + V_11 , V_4 , V_28 , V_6 , 1 ) ;
F_12 ( V_1 , T_3 , V_3 + V_11 + V_25 , V_4 - V_25 , V_28 , V_21 + 1 , V_6 , 2 ) ;
}
V_11 += V_25 + V_26 ;
V_4 -= V_25 + V_26 ;
}
if ( V_29 ) {
F_2 ( V_29 , V_1 , V_3 + V_11 , - 1 , L_5 ) ;
}
return - 1 ;
case 'l' :
if ( V_5 ) {
V_6 = F_5 ( V_5 , V_34 , V_1 , V_3 , V_24 , V_16 ) ;
V_28 = F_13 ( V_6 , V_35 ) ;
}
V_11 = 1 ;
V_4 -- ;
while ( V_4 >= 1 ) {
V_23 = F_3 ( V_1 , V_3 + V_11 ) ;
if ( V_23 == 'e' ) {
return V_11 + 1 ;
}
V_24 = F_12 ( V_1 , T_3 , V_3 + V_11 , V_4 , V_28 , V_21 + 1 , V_6 , 0 ) ;
if ( V_24 < 1 ) return V_24 ;
V_11 += V_24 ;
V_4 -= V_24 ;
}
if ( V_28 ) {
F_2 ( V_28 , V_1 , V_3 + V_11 , - 1 , L_5 ) ;
}
return - 1 ;
case 'i' :
return F_10 ( V_1 , T_3 , V_3 , V_4 , V_5 , V_22 , V_7 ) ;
default:
if ( V_23 >= '1' && V_23 <= '9' ) {
return F_1 ( V_1 , T_3 , V_3 , V_4 , V_5 , V_22 , V_7 ) ;
}
F_2 ( V_5 , V_1 , V_3 , - 1 , L_11 ) ;
}
return - 1 ;
}
static void F_14 ( T_1 * V_1 , T_2 * T_3 , T_4 * V_5 )
{
F_12 ( V_1 , T_3 , 0 , F_15 ( V_1 ) , V_5 , 0 , NULL , 0 ) ;
}
void
F_16 ( void )
{
static T_8 V_36 [] = {
{ & V_13 ,
{ L_12 , L_13 , V_37 , V_38 , NULL , 0x0 , NULL , V_39 }
} ,
{ & V_14 ,
{ L_14 , L_15 , V_40 , V_41 , NULL , 0x0 , NULL , V_39 }
} ,
{ & V_20 ,
{ L_16 , L_17 , V_42 , V_38 , NULL , 0x0 , NULL , V_39 }
} ,
{ & V_30 ,
{ L_18 , L_19 , V_43 , V_41 , NULL , 0x0 , NULL , V_39 }
} ,
{ & V_32 ,
{ L_20 , L_21 , V_43 , V_41 , NULL , 0x0 , NULL , V_39 }
} ,
{ & V_34 ,
{ L_22 , L_23 , V_43 , V_41 , NULL , 0x0 , NULL , V_39 }
} ,
} ;
static T_9 * V_44 [] = {
& V_31 ,
& V_33 ,
& V_35 ,
} ;
V_45 = F_17 ( L_24 , L_24 , L_25 ) ;
F_18 ( L_25 , F_14 , V_45 ) ;
F_19 ( V_45 , V_36 , F_20 ( V_36 ) ) ;
F_21 ( V_44 , F_20 ( V_44 ) ) ;
}
