void
F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 ,
T_4 * V_4 , int V_5 , int V_6 , int V_7 )
{
int V_8 , V_9 ;
while ( V_7 > 0 ) {
V_8 = F_2 ( V_3 , V_6 ) ;
V_7 -- ;
if ( V_7 <= 0 ) {
F_3 ( V_1 , V_2 , V_4 , V_3 , V_6 , - 1 ,
L_1 ) ;
return;
}
if ( V_8 > V_7 ) {
F_3 ( V_1 , V_2 , V_4 , V_3 , V_6 , - 1 ,
L_2 ,
V_8 , V_7 ) ;
return;
}
if ( V_1 ) {
T_5 * V_10 ;
V_10 = F_4 ( V_1 , V_5 , V_3 , V_6 , V_8 + 1 ,
NULL , L_3 , V_8 ) ;
for ( V_9 = 0 ; V_9 < V_8 ; V_9 ++ ) {
F_5 ( V_10 , L_4 ,
F_2 ( V_3 , V_6 + V_9 + 1 ) ) ;
if ( ( ( V_9 & 1 ) == 0 ) &&
( V_9 + 1 < V_8 ) ) {
F_5 ( V_10 , L_5 ) ;
}
}
}
V_6 += V_8 + 1 ;
V_7 -= V_8 ;
}
}
void
F_6 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 ,
T_4 * V_4 , int V_11 , int V_12 , int V_6 , int V_7 )
{
V_7 -- ;
if ( V_7 <= 0 ) {
F_3 ( V_1 , V_2 , V_4 , V_3 , V_6 , - 1 ,
L_1 ) ;
return;
}
F_7 ( V_1 , V_11 , V_3 , V_6 , 2 , V_13 ) ;
V_6 += 2 ;
V_7 -= 2 ;
while ( V_7 > 0 ) {
F_7 ( V_1 , V_12 , V_3 , V_6 , 2 , V_13 ) ;
V_6 += 2 ;
V_7 -= 2 ;
}
}
void
F_8 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 ,
int V_14 , int V_15 , T_4 * V_16 , int V_6 , int V_7 )
{
T_6 V_17 ;
int V_18 ;
const T_7 * V_19 = NULL ;
if ( V_7 <= 0 ) {
return;
}
V_17 = F_2 ( V_3 , V_6 ) ;
V_6 += 1 ;
V_7 -- ;
V_18 = FALSE ;
switch ( V_17 ) {
case 1 :
if ( V_7 > 0 ) {
F_4 ( V_1 , V_14 , V_3 , V_6 , V_7 ,
NULL , L_6 , V_7 , F_9 ( V_3 , V_6 , V_7 ) ) ;
} else {
F_4 ( V_1 , V_14 , V_3 , V_6 , V_7 ,
NULL , L_7 ) ;
}
break;
case 54 :
if ( V_7 == 16 ) {
F_4 ( V_1 , V_14 , V_3 , V_6 , V_7 ,
NULL , L_8 , V_7 , F_10 ( F_11 () , V_3 , V_6 , V_7 ) ) ;
} else {
F_4 ( V_1 , V_14 , V_3 , V_6 , V_7 ,
NULL , L_9 ) ;
}
break;
case 3 :
F_7 ( V_1 , V_15 , V_3 , V_6 , 2 , V_13 ) ;
V_6 += 2 ;
V_7 -= 2 ;
V_19 = F_12 ( V_7 , V_20 ) ;
if ( V_19 ) {
F_4 ( V_1 , V_14 , V_3 , V_6 , V_7 ,
NULL , L_10 , V_19 ,
V_7 , F_10 ( F_11 () , V_3 , V_6 , V_7 ) ) ;
} else {
F_4 ( V_1 , V_14 , V_3 , V_6 , V_7 ,
NULL , L_11 ) ;
}
break;
default:
F_4 ( V_1 , V_14 , V_3 , V_6 , V_7 ,
NULL , L_12 , V_17 , V_7 ) ;
V_18 = TRUE ;
break;
}
if ( V_18 ) {
F_13 ( V_1 , V_2 , V_16 , V_3 , V_6 , - 1 ) ;
}
}
void
F_14 ( T_3 * V_3 , T_1 * V_1 , int V_6 ,
int V_7 , int V_21 )
{
T_5 * V_10 = F_7 ( V_1 , V_21 , V_3 , V_6 , V_7 , V_22 | V_23 ) ;
if ( V_7 == 0 ) {
F_5 ( V_10 , L_13 ) ;
}
}
void
F_15 ( T_3 * V_3 , T_2 * V_2 , T_1 * V_1 , int V_6 , int V_7 ,
int V_21 , T_4 * V_24 )
{
T_8 V_25 ;
const char * V_26 ;
while ( V_7 > 0 ) {
if ( V_7 != 1 ) {
V_25 = F_16 ( V_3 , V_6 ) ;
switch( V_25 & 0x0fff ) {
case 0 :
V_26 = L_14 ;
break;
case 1 :
V_26 = L_15 ;
break;
case 2 :
V_26 = L_16 ;
break;
case 3 :
V_26 = L_17 ;
break;
case 4095 :
V_26 = L_18 ;
break;
default:
V_26 = L_19 ;
break;
}
F_17 ( V_1 , V_21 , V_3 , V_6 , 2 ,
V_25 ,
L_20 ,
V_26 ,
V_25 & 0xfff ,
( V_25 & 0x8000 ) ? L_21 : L_22 ,
( V_25 & 0x4000 ) ? L_23 : L_21 ) ;
} else {
F_13 ( V_1 , V_2 , V_24 , V_3 , V_6 , 1 ) ;
break;
}
V_7 -= 2 ;
V_6 += 2 ;
}
}
void
F_18 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , T_4 * V_4 ,
int V_6 , int V_7 , int V_21 )
{
if ( V_7 <= 0 ) {
return;
}
while ( V_7 > 0 ) {
if ( V_7 < 4 ) {
F_3 ( V_1 , V_2 , V_4 , V_3 , V_6 , - 1 ,
L_24 , V_7 ) ;
return;
}
if ( V_1 ) {
F_7 ( V_1 , V_21 , V_3 , V_6 , 4 , V_13 ) ;
}
V_6 += 4 ;
V_7 -= 4 ;
}
}
void
F_19 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , T_4 * V_4 ,
int V_6 , int V_7 , int V_21 )
{
struct V_27 V_28 ;
if ( V_7 <= 0 ) {
return;
}
while ( V_7 > 0 ) {
if ( V_7 < 16 ) {
F_3 ( V_1 , V_2 , V_4 , V_3 , V_6 , - 1 ,
L_25 , V_7 ) ;
return;
}
F_20 ( V_3 , V_6 , & V_28 ) ;
if ( V_1 ) {
F_21 ( V_1 , V_21 , V_3 , V_6 , 16 , & V_28 ) ;
}
V_6 += 16 ;
V_7 -= 16 ;
}
}
void
F_22 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , T_4 * V_4 ,
int V_6 , int V_7 , int V_21 )
{
if ( V_7 <= 0 ) {
return;
}
if ( V_7 != 4 ) {
F_3 ( V_1 , V_2 , V_4 , V_3 , V_6 , - 1 ,
L_26 , V_7 ) ;
return;
}
F_7 ( V_1 , V_21 , V_3 , V_6 , 4 , V_13 ) ;
}
void
F_23 ( T_3 * V_3 , T_1 * V_1 , int V_29 , int V_6 , int V_7 )
{
T_9 V_30 ;
T_5 * V_10 ;
if ( ! V_1 ) return;
if ( V_7 <= 0 ) {
F_7 ( V_1 , V_29 , V_3 , V_6 , V_7 , V_23 ) ;
} else {
V_30 = TRUE ;
V_10 = F_4 ( V_1 , V_29 , V_3 , V_6 , V_7 , NULL , L_27 ) ;
while ( V_7 -- > 0 ) {
if ( ! V_30 ) {
F_5 ( V_10 , L_28 ) ;
}
F_5 ( V_10 , L_29 ,
( F_2 ( V_3 , V_6 ) == V_31
? L_30
: F_24 ( F_2 ( V_3 , V_6 ) , V_32 , L_31 ) ) ,
F_2 ( V_3 , V_6 ) ) ;
V_6 ++ ;
V_30 = FALSE ;
}
}
}
void
F_25 ( T_3 * V_3 , T_2 * V_2 , T_1 * V_1 , int V_6 ,
const T_10 * V_33 , T_4 * V_34 , int V_35 , int V_36 ,
int T_11 V_37 , int V_38 , int V_39 , T_4 V_40 )
{
T_12 V_41 ;
T_12 V_7 ;
int V_42 ;
T_1 * V_43 ;
while ( V_35 > 0 ) {
V_41 = F_2 ( V_3 , V_6 ) ;
V_6 += 1 ;
V_35 -= 1 ;
if ( V_35 == 0 )
break;
V_7 = F_2 ( V_3 , V_6 ) ;
V_6 += 1 ;
V_35 -= 1 ;
if ( V_35 == 0 )
break;
if ( V_35 < V_7 ) {
F_3 ( V_1 , V_2 , V_34 , V_3 , V_6 , - 1 ,
L_32 ,
V_7 , V_35 ) ;
return;
}
V_42 = 0 ;
while ( ( V_33 [ V_42 ] . V_44 != NULL ) && ( V_33 [ V_42 ] . V_45 != V_41 ) ) {
V_42 ++ ;
}
if ( V_33 [ V_42 ] . V_44 ) {
V_43 = F_26 ( V_1 , V_3 , V_6 - 2 ,
V_7 + 2 , * V_33 [ V_42 ] . V_21 , NULL , L_33 ,
V_33 [ V_42 ] . V_46 , V_33 [ V_42 ] . V_45 , V_7 ) ;
F_7 ( V_43 , V_38 , V_3 , V_6 - 2 , 1 , V_13 ) ;
F_7 ( V_43 , V_39 , V_3 , V_6 - 1 , 1 , V_13 ) ;
V_33 [ V_42 ] . V_44 ( V_3 , V_2 , V_43 , V_6 ,
V_36 , V_7 ) ;
} else {
V_43 = F_26 ( V_1 , V_3 , V_6 - 2 ,
V_7 + 2 , T_11 , NULL , L_34 ,
V_41 , V_7 ) ;
F_7 ( V_43 , V_38 , V_3 , V_6 - 2 , 1 , V_13 ) ;
F_7 ( V_43 , V_39 , V_3 , V_6 - 1 , 1 , V_13 ) ;
F_3 ( V_43 , V_2 , & V_40 , V_3 , V_6 , V_7 - 2 , L_35
L_36 , V_41 ) ;
}
V_6 += V_7 ;
V_35 -= V_7 ;
}
}
