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
int V_14 , T_4 * V_15 , int V_6 , int V_7 )
{
T_6 V_16 ;
int V_17 ;
if ( V_7 <= 0 ) {
return;
}
V_16 = F_2 ( V_3 , V_6 ) ;
V_6 += 1 ;
V_7 -- ;
V_17 = FALSE ;
switch ( V_16 ) {
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
default:
F_4 ( V_1 , V_14 , V_3 , V_6 , V_7 ,
NULL , L_10 , V_16 , V_7 ) ;
V_17 = TRUE ;
break;
}
if ( V_17 ) {
F_12 ( V_1 , V_2 , V_15 , V_3 , V_6 , - 1 ) ;
}
}
void
F_13 ( T_3 * V_3 , T_1 * V_1 , int V_6 ,
int V_7 , int V_18 )
{
T_5 * V_10 = F_7 ( V_1 , V_18 , V_3 , V_6 , V_7 , V_19 | V_20 ) ;
if ( V_7 == 0 ) {
F_5 ( V_10 , L_11 ) ;
}
}
void
F_14 ( T_3 * V_3 , T_2 * V_2 , T_1 * V_1 , int V_6 , int V_7 ,
int V_18 , T_4 * V_21 )
{
T_7 V_22 ;
const char * V_23 ;
while ( V_7 > 0 ) {
if ( V_7 != 1 ) {
V_22 = F_15 ( V_3 , V_6 ) ;
switch( V_22 & 0x0fff ) {
case 0 :
V_23 = L_12 ;
break;
case 1 :
V_23 = L_13 ;
break;
case 2 :
V_23 = L_14 ;
break;
case 3 :
V_23 = L_15 ;
break;
case 4095 :
V_23 = L_16 ;
break;
default:
V_23 = L_17 ;
break;
}
F_16 ( V_1 , V_18 , V_3 , V_6 , 2 ,
V_22 ,
L_18 ,
V_23 ,
V_22 & 0xfff ,
( V_22 & 0x8000 ) ? L_19 : L_20 ,
( V_22 & 0x4000 ) ? L_21 : L_19 ) ;
} else {
F_12 ( V_1 , V_2 , V_21 , V_3 , V_6 , 1 ) ;
break;
}
V_7 -= 2 ;
V_6 += 2 ;
}
}
void
F_17 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , T_4 * V_4 ,
int V_6 , int V_7 , int V_18 )
{
if ( V_7 <= 0 ) {
return;
}
while ( V_7 > 0 ) {
if ( V_7 < 4 ) {
F_3 ( V_1 , V_2 , V_4 , V_3 , V_6 , - 1 ,
L_22 , V_7 ) ;
return;
}
if ( V_1 ) {
F_7 ( V_1 , V_18 , V_3 , V_6 , 4 , V_13 ) ;
}
V_6 += 4 ;
V_7 -= 4 ;
}
}
void
F_18 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , T_4 * V_4 ,
int V_6 , int V_7 , int V_18 )
{
struct V_24 V_25 ;
if ( V_7 <= 0 ) {
return;
}
while ( V_7 > 0 ) {
if ( V_7 < 16 ) {
F_3 ( V_1 , V_2 , V_4 , V_3 , V_6 , - 1 ,
L_23 , V_7 ) ;
return;
}
F_19 ( V_3 , V_6 , & V_25 ) ;
if ( V_1 ) {
F_20 ( V_1 , V_18 , V_3 , V_6 , 16 , & V_25 ) ;
}
V_6 += 16 ;
V_7 -= 16 ;
}
}
void
F_21 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , T_4 * V_4 ,
int V_6 , int V_7 , int V_18 )
{
if ( V_7 <= 0 ) {
return;
}
if ( V_7 != 4 ) {
F_3 ( V_1 , V_2 , V_4 , V_3 , V_6 , - 1 ,
L_24 , V_7 ) ;
return;
}
F_7 ( V_1 , V_18 , V_3 , V_6 , 4 , V_13 ) ;
}
void
F_22 ( T_3 * V_3 , T_1 * V_1 , int V_26 , int V_6 , int V_7 )
{
T_8 V_27 ;
T_5 * V_10 ;
if ( ! V_1 ) return;
if ( V_7 <= 0 ) {
F_7 ( V_1 , V_26 , V_3 , V_6 , V_7 , V_20 ) ;
} else {
V_27 = TRUE ;
V_10 = F_4 ( V_1 , V_26 , V_3 , V_6 , V_7 , NULL , L_25 ) ;
while ( V_7 -- > 0 ) {
if ( ! V_27 ) {
F_5 ( V_10 , L_26 ) ;
}
F_5 ( V_10 , L_27 ,
( F_2 ( V_3 , V_6 ) == V_28
? L_28
: F_23 ( F_2 ( V_3 , V_6 ) , V_29 , L_29 ) ) ,
F_2 ( V_3 , V_6 ) ) ;
V_6 ++ ;
V_27 = FALSE ;
}
}
}
void
F_24 ( T_3 * V_3 , T_2 * V_2 , T_1 * V_1 , int V_6 ,
const T_9 * V_30 , T_4 * V_31 , int V_32 , int V_33 ,
int T_10 V_34 , int V_35 , int V_36 , T_4 V_37 )
{
T_11 V_38 ;
T_11 V_7 ;
int V_39 ;
T_1 * V_40 ;
while ( V_32 > 0 ) {
V_38 = F_2 ( V_3 , V_6 ) ;
V_6 += 1 ;
V_32 -= 1 ;
if ( V_32 == 0 )
break;
V_7 = F_2 ( V_3 , V_6 ) ;
V_6 += 1 ;
V_32 -= 1 ;
if ( V_32 == 0 )
break;
if ( V_32 < V_7 ) {
F_3 ( V_1 , V_2 , V_31 , V_3 , V_6 , - 1 ,
L_30 ,
V_7 , V_32 ) ;
return;
}
V_39 = 0 ;
while ( ( V_30 [ V_39 ] . V_41 != NULL ) && ( V_30 [ V_39 ] . V_42 != V_38 ) ) {
V_39 ++ ;
}
if ( V_30 [ V_39 ] . V_41 ) {
V_40 = F_25 ( V_1 , V_3 , V_6 - 2 ,
V_7 + 2 , * V_30 [ V_39 ] . V_18 , NULL , L_31 ,
V_30 [ V_39 ] . V_43 , V_30 [ V_39 ] . V_42 , V_7 ) ;
F_7 ( V_40 , V_35 , V_3 , V_6 - 2 , 1 , V_13 ) ;
F_7 ( V_40 , V_36 , V_3 , V_6 - 1 , 1 , V_13 ) ;
V_30 [ V_39 ] . V_41 ( V_3 , V_2 , V_40 , V_6 ,
V_33 , V_7 ) ;
} else {
V_40 = F_25 ( V_1 , V_3 , V_6 - 2 ,
V_7 + 2 , T_10 , NULL , L_32 ,
V_38 , V_7 ) ;
F_7 ( V_40 , V_35 , V_3 , V_6 - 2 , 1 , V_13 ) ;
F_7 ( V_40 , V_36 , V_3 , V_6 - 1 , 1 , V_13 ) ;
F_3 ( V_40 , V_2 , & V_37 , V_3 , V_6 , V_7 - 2 , L_33
L_34 , V_38 ) ;
}
V_6 += V_7 ;
V_32 -= V_7 ;
}
}
