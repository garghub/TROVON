static int
F_1 ( T_1 * V_1 , int V_2 , int * V_3 )
{
int V_4 = 0 ;
T_2 V_5 = F_2 ( V_1 , V_2 ) ;
V_2 += 1 ;
switch ( V_5 & 0x07 ) {
case 0 :
V_4 = ( V_5 >> 3 ) == 0 ? 0 : 1 ;
break;
case 1 :
V_4 = 2 ;
break;
case 2 :
V_4 = 4 ;
break;
case 3 :
V_4 = 8 ;
break;
case 4 :
V_4 = 16 ;
break;
case 5 :
V_4 = F_2 ( V_1 , V_2 ) ;
V_2 += 1 ;
break;
case 6 :
V_4 = F_3 ( V_1 , V_2 ) ;
V_2 += 2 ;
break;
case 7 :
V_4 = F_4 ( V_1 , V_2 ) ;
V_2 += 4 ;
break;
}
* V_3 = V_4 ;
return V_2 ;
}
static T_3
F_5 ( T_1 * V_1 , int V_6 , int V_4 )
{
switch ( V_4 ) {
case 0 :
return F_2 ( V_1 , V_6 ) ;
case 1 :
return F_3 ( V_1 , V_6 ) ;
case 2 :
return F_4 ( V_1 , V_6 ) ;
default:
return 0xffffffff ;
}
}
static T_4
F_6 ( T_1 * V_1 , int V_6 , int V_4 )
{
switch ( V_4 ) {
case 0 :
return F_2 ( V_1 , V_6 ) ;
case 1 :
return F_3 ( V_1 , V_6 ) ;
case 2 :
return F_4 ( V_1 , V_6 ) ;
default:
return - 1 ;
}
}
static int
F_7 ( T_5 * V_7 , T_1 * V_1 , int V_2 , T_6 * V_8 )
{
T_7 * V_9 ;
T_5 * V_10 ;
int V_11 , V_12 ;
T_8 V_13 ;
const char * V_14 ;
V_11 = V_2 ;
V_9 = F_8 ( V_7 , V_1 , V_2 , 2 , L_1 ) ;
V_10 = F_9 ( V_9 , V_15 ) ;
V_2 = F_1 ( V_1 , V_2 , & V_12 ) ;
F_10 ( V_9 , V_2 - V_11 + V_12 ) ;
while ( V_12 > 0 ) {
T_2 V_5 = F_2 ( V_1 , V_2 ) ;
if ( V_5 == 0x09 ) {
V_13 = F_3 ( V_1 , V_2 + 1 ) ;
V_14 = F_11 ( V_13 , V_16 , L_2 ) ;
F_8 ( V_10 , V_1 , V_2 , 3 , L_3 , V_14 , V_13 ) ;
V_2 += 3 ;
V_12 -= 3 ;
F_12 ( V_8 -> V_17 , V_18 , L_4 , V_14 ) ;
} else if ( V_5 == 0x0a ) {
F_12 ( V_8 -> V_17 , V_18 , L_5 ,
F_3 ( V_1 , V_2 + 1 ) , F_3 ( V_1 , V_2 + 3 ) ) ;
F_8 ( V_10 , V_1 , V_2 , 5 , L_6 ,
F_3 ( V_1 , V_2 + 1 ) ,
F_3 ( V_1 , V_2 + 3 ) ) ;
V_2 += 5 ;
V_12 -= 5 ;
} else {
break;
}
}
return V_2 - V_11 ;
}
static int
F_13 ( T_5 * V_7 , T_1 * V_1 , int V_2 ) {
F_14 ( V_7 , V_19 , V_1 , V_2 , 2 , V_20 ) ;
V_2 += 2 ;
return V_2 ;
}
static int
F_15 ( T_1 * V_1 , int V_2 , T_8 V_13 , T_2 * type , void * * V_21 , T_3 * V_22 , T_3 * V_23 )
{
int V_4 , V_11 , V_24 ;
T_2 V_5 ;
V_5 = F_2 ( V_1 , V_2 ) ;
* type = ( V_5 >> 3 ) & 0x1f ;
* V_21 = NULL ;
* V_22 = 0 ;
* V_23 = 0 ;
V_11 = V_2 ;
V_2 = F_1 ( V_1 , V_2 , & V_4 ) ;
V_24 = V_2 - V_11 + V_4 ;
switch ( * type ) {
case 0 : {
* V_21 = NULL ;
break;
}
case 1 :
case 2 :
case 3 : {
* V_21 = F_16 ( V_4 ) ;
if ( V_4 == 1 ) {
* ( ( T_2 * ) * V_21 ) = F_2 ( V_1 , V_2 ) ;
}
else if ( V_4 == 2 ) {
* ( ( T_8 * ) * V_21 ) = F_3 ( V_1 , V_2 ) ;
}
else if ( V_4 == 4 ) {
* ( ( T_3 * ) * V_21 ) = F_4 ( V_1 , V_2 ) ;
}
else if ( V_4 == 8 ) {
* ( ( V_25 * ) * V_21 ) = F_17 ( V_1 , V_2 ) ;
}
else if ( V_4 == 16 ) {
* ( ( T_3 * ) * V_21 ) = F_4 ( V_1 , V_2 ) ;
}
break;
}
case 8 :
case 4 : {
* V_21 = F_18 ( V_1 , V_2 , V_4 ) ;
break;
}
case 5 : {
* V_21 = F_16 ( sizeof( V_24 ) ) ;
* ( ( T_2 * ) * V_21 ) = F_2 ( V_1 , V_2 ) ;
break;
}
case 6 :
case 7 : {
T_9 V_26 = FALSE ;
int V_12 = V_4 ;
int V_27 ;
T_3 V_28 = 0 ;
while ( V_12 > 0 ) {
V_4 = F_15 ( V_1 , V_2 , V_13 , type , V_21 , V_22 , V_23 ) ;
if ( V_4 < 1 || * V_21 == NULL ) {
break;
}
F_1 ( V_1 , V_2 , & V_27 ) ;
V_2 += V_4 ;
V_12 -= V_4 ;
if ( V_27 == 1 ) {
V_28 = * ( ( T_2 * ) * V_21 ) ;
}
else if ( V_27 == 2 ) {
V_28 = * ( ( T_8 * ) * V_21 ) ;
}
else if ( V_27 == 4 ) {
V_28 = * ( ( T_3 * ) * V_21 ) ;
}
else if ( V_27 == 16 ) {
V_28 = * ( ( T_3 * ) * V_21 ) ;
}
if ( ( ( V_13 == 4 ) || ( V_13 == 0xd ) ) && ( * type == 3 ) && ( ( V_28 == 0x100 ) || ( V_28 == 0x0003 ) ) ) {
* V_22 = V_28 ;
V_26 = TRUE ;
}
else if ( ( V_13 == 9 ) && ( * type == 3 ) ) {
* V_22 = V_28 ;
V_26 = TRUE ;
}
else if ( ( V_13 == 1 ) && ( * type == 3 ) ) {
* V_22 = V_28 ;
V_26 = TRUE ;
}
else if ( ( V_26 == TRUE ) && * type == 1 ) {
* V_23 = V_28 ;
V_26 = FALSE ;
}
else {
V_26 = FALSE ;
}
}
break;
}
}
return V_24 ;
}
static int
F_19 ( T_5 * V_7 , T_1 * V_1 , int V_2 , char * * V_29 )
{
#define F_20 1024
int V_30 = 0 , V_4 , V_11 , V_24 ;
char * V_31 ;
T_2 V_5 ;
T_2 type ;
T_2 V_32 ;
V_31 = F_16 ( F_20 + 1 ) ;
* V_29 = V_31 ;
V_31 [ 0 ] = 0 ;
V_5 = F_2 ( V_1 , V_2 ) ;
type = ( V_5 >> 3 ) & 0x1f ;
V_32 = V_5 & 0x07 ;
V_11 = V_2 ;
V_2 = F_1 ( V_1 , V_2 , & V_4 ) ;
V_24 = V_2 - V_11 + V_4 ;
switch ( type ) {
case 0 :
F_8 ( V_7 , V_1 , V_11 , V_24 , L_7 ) ;
if ( V_30 < F_20 ) {
F_21 ( V_31 + V_30 , F_20 - V_30 , L_7 ) ;
}
break;
case 1 : {
T_3 V_21 = F_5 ( V_1 , V_2 , V_32 ) ;
F_8 ( V_7 , V_1 , V_11 , V_24 ,
L_8 , V_21 ) ;
if ( V_30 < F_20 ) {
F_21 ( V_31 + V_30 , F_20 - V_30 , L_9 , V_21 ) ;
}
break;
}
case 2 : {
T_3 V_21 = F_6 ( V_1 , V_2 , V_32 ) ;
F_8 ( V_7 , V_1 , V_11 , V_24 ,
L_10 , V_21 ) ;
if ( V_30 < F_20 ) {
F_21 ( V_31 + V_30 , F_20 - V_30 , L_11 , V_21 ) ;
}
break;
}
case 3 : {
T_3 V_13 ;
const char * V_33 ;
char * V_34 = F_18 ( V_1 , V_2 , V_4 ) ;
if ( V_4 == 2 ) {
V_13 = F_3 ( V_1 , V_2 ) ;
} else {
V_13 = F_4 ( V_1 , V_2 ) ;
}
V_33 = F_22 ( V_13 , & V_35 , L_12 ) ;
F_8 ( V_7 , V_1 , V_11 , V_24 , L_13 , V_33 , V_34 ) ;
if ( V_30 < F_20 ) {
F_21 ( V_31 + V_30 , F_20 - V_30 , L_14 , V_33 ) ;
}
break;
}
case 8 :
case 4 : {
char * V_34 = ( V_36 * ) F_23 ( V_1 , V_2 , V_4 ) ;
F_8 ( V_7 , V_1 , V_11 , V_24 , L_15 ,
type == 8 ? L_16 : L_17 , V_34 ) ;
if ( V_30 < F_20 ) {
F_21 ( V_31 + V_30 , F_20 - V_30 , L_18 , V_34 ) ;
}
break;
}
case 5 : {
T_2 V_37 = F_2 ( V_1 , V_2 ) ;
F_8 ( V_7 , V_1 , V_11 , V_24 , L_19 ,
V_37 ? L_20 : L_21 ) ;
if ( V_30 < F_20 ) {
F_21 ( V_31 + V_30 , F_20 - V_30 , L_18 , V_37 ? L_20 : L_21 ) ;
}
break;
}
case 6 :
case 7 : {
T_5 * V_10 ;
T_7 * V_9 ;
int V_12 = V_4 ;
int V_38 = 1 ;
char * V_39 ;
V_9 = F_8 ( V_7 , V_1 , V_11 , V_24 , L_19 ,
type == 6 ? L_22 :
L_23 ) ;
V_10 = F_9 ( V_9 , V_40 ) ;
if ( V_30 < F_20 ) {
V_30 += F_21 ( V_31 + V_30 , F_20 - V_30 , L_24 ) ;
}
while ( V_12 > 0 ) {
if ( ! V_38 ) {
if ( V_30 < F_20 ) {
V_30 += F_21 ( V_31 + V_30 , F_20 - V_30 , L_25 ) ;
}
} else {
V_38 = 0 ;
}
V_4 = F_19 ( V_10 , V_1 , V_2 , & V_39 ) ;
if ( V_4 < 1 ) {
break;
}
if ( V_30 < F_20 ) {
V_30 += F_21 ( V_31 + V_30 , F_20 - V_30 , L_18 , V_39 ) ;
}
V_2 += V_4 ;
V_12 -= V_4 ;
}
if ( V_30 < F_20 ) {
F_21 ( V_31 + V_30 , F_20 - V_30 , L_26 ) ;
}
break;
}
}
V_31 [ F_20 ] = '\0' ;
return V_24 ;
}
static int
F_24 ( T_5 * V_41 , T_1 * V_1 , int V_2 , T_6 * V_8 , T_3 V_42 )
{
T_5 * V_10 , * V_43 , * V_44 ;
int V_4 ;
const char * V_14 ;
T_8 V_13 ;
char * V_29 ;
V_13 = F_3 ( V_1 , V_2 + 1 ) ;
V_14 = F_11 ( V_13 , V_16 , L_2 ) ;
V_43 = F_8 ( V_41 , V_1 , V_2 , - 1 ,
L_27 , V_14 , V_13 ) ;
V_10 = F_9 ( V_43 , V_45 ) ;
F_8 ( V_10 , V_1 , V_2 , 3 , L_28 , V_14 , V_13 ) ;
V_44 = F_8 ( V_10 , V_1 , V_2 + 3 , - 1 , L_29 ) ;
V_10 = F_9 ( V_44 , V_45 ) ;
V_4 = F_19 ( V_10 , V_1 , V_2 + 3 , & V_29 ) ;
F_25 ( V_43 , L_30 , V_29 ) ;
if ( ! V_8 -> V_46 -> V_47 . V_48 ) {
void * V_21 ;
T_2 type ;
T_3 V_22 , V_23 ;
T_10 * V_49 ;
V_49 = F_26 ( V_50 , V_42 ) ;
if ( V_49 != NULL ) {
switch ( V_13 ) {
case V_51 :
case V_52 :
case V_53 :
F_15 ( V_1 , V_2 + 3 , V_13 , & type , & V_21 , & V_22 , & V_23 ) ;
if ( ( V_22 == V_54 )
|| ( V_22 == V_55 ) ) {
V_49 -> V_56 = V_23 ;
V_49 -> V_57 = ( T_8 ) V_22 ;
}
else {
V_49 -> V_22 = V_22 ;
}
V_49 -> V_47 = 0 ;
if ( V_13 == V_53 ) {
V_49 -> V_47 = V_58 ;
}
break;
case V_59 :
F_15 ( V_1 , V_2 + 3 , V_13 , & type , & V_21 , & V_22 , & V_23 ) ;
V_49 -> V_22 = V_22 ;
break;
case V_60 :
{
void * V_61 ;
T_2 * V_62 ;
F_15 ( V_1 , V_2 + 3 , V_13 , & type , & V_61 , & V_22 , & V_23 ) ;
V_62 = V_61 ;
if ( ( type == 1 ) && ( * V_62 & 0x1 ) ) {
V_49 -> V_56 = * V_62 ;
V_49 -> V_57 = V_54 ;
V_49 -> V_47 = 0 ;
}
}
break;
}
if ( V_49 -> V_22 != 0 && V_49 -> V_56 != 0 ) {
V_49 -> V_47 |= V_42 >> 15 ;
F_27 ( V_63 , NULL , ( void * ) V_49 ) ;
}
}
}
F_10 ( V_43 , V_4 + 3 ) ;
F_10 ( V_44 , V_4 ) ;
return V_2 + V_4 + 3 ;
}
static int
F_28 ( T_5 * V_41 , T_1 * V_1 , int V_2 , T_6 * V_8 , T_3 V_42 )
{
T_7 * V_9 ;
T_5 * V_10 ;
int V_11 = V_2 , V_27 ;
V_2 = F_1 ( V_1 , V_2 , & V_27 ) ;
V_9 = F_8 ( V_41 , V_1 , V_11 , - 1 , L_31 ) ;
V_10 = F_9 ( V_9 , V_45 ) ;
if ( ! V_27 ) {
return V_2 ;
}
while ( ( V_2 - V_11 ) < V_27 ) {
V_2 = F_24 ( V_10 , V_1 , V_2 , V_8 , V_42 ) ;
}
F_10 ( V_9 , V_2 - V_11 ) ;
return V_2 ;
}
static int
F_29 ( T_5 * V_41 , T_1 * V_1 , int V_2 , T_6 * V_8 , T_3 V_42 )
{
T_7 * V_9 ;
T_5 * V_10 ;
int V_11 , V_27 ;
V_11 = V_2 ;
V_2 = F_1 ( V_1 , V_2 , & V_27 ) ;
V_9 = F_8 ( V_41 , V_1 , V_11 , V_2 - V_11 + V_27 , L_32 ) ;
V_10 = F_9 ( V_9 , V_45 ) ;
V_11 = V_2 ;
while ( V_2 - V_11 < V_27 ) {
V_2 = F_28 ( V_10 , V_1 , V_2 , V_8 , V_42 ) ;
}
return V_2 ;
}
static int
F_30 ( T_5 * V_41 , T_1 * V_1 , int V_2 , T_6 * V_8 , T_3 V_42 )
{
F_14 ( V_41 , V_64 , V_1 , V_2 , 2 , V_20 ) ;
V_2 += 2 ;
V_2 += F_29 ( V_41 , V_1 , V_2 , V_8 , V_42 ) ;
return V_2 ;
}
static int
F_31 ( T_5 * V_7 , T_1 * V_1 , int V_2 , T_6 * V_8 , T_3 V_42 )
{
T_5 * V_10 ;
T_7 * V_9 ;
int V_11 ;
int V_4 , V_12 ;
char * V_31 ;
V_11 = V_2 ;
V_9 = F_8 ( V_7 , V_1 , V_2 , 2 , L_33 ) ;
V_10 = F_9 ( V_9 , V_45 ) ;
V_2 = F_1 ( V_1 , V_2 , & V_12 ) ;
F_10 ( V_9 , V_2 - V_11 + V_12 ) ;
while ( V_12 > 0 ) {
T_10 * V_49 ;
if ( ! V_8 -> V_46 -> V_47 . V_48 ) {
V_49 = F_26 ( V_50 , V_42 ) ;
if ( V_49 == NULL ) {
V_49 = F_32 ( sizeof( T_10 ) ) ;
F_33 ( V_50 , V_42 , V_49 ) ;
}
V_49 -> V_56 = 0 ;
V_49 -> V_22 = 0 ;
}
V_4 = F_19 ( V_10 , V_1 , V_2 , & V_31 ) ;
F_25 ( V_10 , L_34 , V_31 ) ;
F_12 ( V_8 -> V_17 , V_18 , L_19 , V_31 ) ;
if ( V_4 < 1 ) {
break;
}
V_2 += V_4 ;
V_12 -= V_4 ;
}
F_8 ( V_7 , V_1 , V_2 , 2 , L_35 , F_3 ( V_1 , V_2 ) ) ;
V_2 += 2 ;
V_2 += F_7 ( V_7 , V_1 , V_2 , V_8 ) ;
F_8 ( V_7 , V_1 , V_2 , - 1 , L_36 ) ;
return V_2 ;
}
static int
F_34 ( T_5 * V_7 , T_1 * V_1 , int V_2 , T_6 * V_8 , T_3 V_42 )
{
F_8 ( V_7 , V_1 , V_2 , 2 , L_37 ,
F_3 ( V_1 , V_2 ) ) ;
V_2 += 2 ;
V_2 = F_28 ( V_7 , V_1 , V_2 , V_8 , V_42 ) ;
F_8 ( V_7 , V_1 , V_2 , - 1 , L_36 ) ;
V_2 += F_35 ( V_1 , V_2 ) ;
return V_2 ;
}
static int
F_36 ( T_5 * V_7 , T_1 * V_1 , int V_2 , T_6 * V_8 )
{
F_8 ( V_7 , V_1 , V_2 , 4 , L_38 ,
F_4 ( V_1 , V_2 ) ) ;
V_2 += 4 ;
F_8 ( V_7 , V_1 , V_2 , 2 , L_35 ,
F_3 ( V_1 , V_2 ) ) ;
V_2 += 2 ;
V_2 += F_7 ( V_7 , V_1 , V_2 , V_8 ) ;
F_8 ( V_7 , V_1 , V_2 , - 1 , L_36 ) ;
V_2 += F_35 ( V_1 , V_2 ) ;
return V_2 ;
}
static int
F_37 ( T_5 * V_7 , T_1 * V_1 , int V_2 , T_6 * V_8 , T_3 V_42 )
{
int V_11 , V_12 , V_4 ;
T_7 * V_9 ;
T_5 * V_10 ;
V_11 = V_2 ;
V_9 = F_8 ( V_7 , V_1 , V_2 , - 1 , L_33 ) ;
V_10 = F_9 ( V_9 , V_65 ) ;
V_2 = F_1 ( V_1 , V_2 , & V_12 ) ;
F_10 ( V_9 , V_2 - V_11 + V_12 ) ;
while ( V_12 > 0 ) {
char * V_31 ;
if ( ! V_8 -> V_46 -> V_47 . V_48 ) {
T_10 * V_49 ;
T_3 V_22 , V_23 ;
T_2 type ;
void * V_21 = NULL ;
V_49 = F_26 ( V_50 , V_42 ) ;
if ( V_49 == NULL ) {
V_49 = F_32 ( sizeof( T_10 ) ) ;
F_33 ( V_50 , V_42 , V_49 ) ;
}
F_15 ( V_1 , V_2 , 4 , & type , & V_21 , & V_22 , & V_23 ) ;
if ( ( type == 3 ) && ( V_21 != NULL ) )
V_49 -> V_22 = * ( ( T_3 * ) V_21 ) ;
}
V_4 = F_19 ( V_10 , V_1 , V_2 , & V_31 ) ;
F_25 ( V_10 , L_34 , V_31 ) ;
F_12 ( V_8 -> V_17 , V_18 , L_19 , V_31 ) ;
if ( V_4 < 1 ) {
break;
}
V_2 += V_4 ;
V_12 -= V_4 ;
}
F_8 ( V_7 , V_1 , V_2 , 2 , L_39 ,
F_3 ( V_1 , V_2 ) ) ;
V_2 += 2 ;
F_8 ( V_7 , V_1 , V_2 , - 1 , L_36 ) ;
V_2 += F_35 ( V_1 , V_2 ) ;
return V_2 ;
}
static int
F_38 ( T_5 * V_7 , T_1 * V_1 , int V_2 )
{
T_5 * V_10 ;
T_7 * V_9 ;
T_11 V_66 ;
F_14 ( V_7 , V_67 , V_1 , V_2 , 2 , V_20 ) ;
V_2 += 2 ;
V_66 = F_3 ( V_1 , V_2 ) ;
F_14 ( V_7 , V_68 , V_1 , V_2 , 2 , V_20 ) ;
V_2 += 2 ;
V_9 = F_8 ( V_7 , V_1 , V_2 ,
V_66 * 4 , L_40 ) ;
V_10 = F_9 ( V_9 , V_69 ) ;
while ( V_66 > 0 ) {
F_8 ( V_10 , V_1 , V_2 , 4 , L_41 , F_4 ( V_1 , V_2 ) ) ;
V_2 += 4 ;
V_66 -= 1 ;
}
F_8 ( V_7 , V_1 , V_2 , - 1 , L_36 ) ;
V_2 += F_35 ( V_1 , V_2 ) ;
return V_2 ;
}
static int
F_39 ( T_1 * V_1 , T_6 * V_8 , T_5 * V_41 )
{
T_7 * V_9 ;
T_5 * V_10 ;
T_2 V_70 ;
T_8 V_71 ;
T_3 V_42 ;
const char * V_72 ;
int V_2 = 0 ;
F_40 ( V_8 -> V_17 , V_73 , L_42 ) ;
V_9 = F_14 ( V_41 , V_74 , V_1 , 0 , - 1 , V_75 ) ;
V_10 = F_9 ( V_9 , V_76 ) ;
V_70 = F_2 ( V_1 , V_2 ) ;
F_14 ( V_10 , V_77 , V_1 , V_2 , 1 , V_20 ) ;
V_72 = F_11 ( V_70 , V_78 , L_2 ) ;
switch ( V_8 -> V_79 ) {
case V_80 :
F_41 ( V_8 -> V_17 , V_18 , L_43 ) ;
break;
case V_81 :
F_41 ( V_8 -> V_17 , V_18 , L_44 ) ;
break;
case V_82 :
F_42 ( V_8 -> V_17 , V_18 ) ;
break;
default:
F_43 ( V_8 -> V_17 , V_18 , L_45 ,
V_8 -> V_79 ) ;
break;
}
F_12 ( V_8 -> V_17 , V_18 , L_18 , V_72 ) ;
F_25 ( V_9 , L_46 , V_72 , V_70 ) ;
V_2 += 1 ;
F_14 ( V_10 , V_83 , V_1 , V_2 , 2 , V_20 ) ;
V_2 += 2 ;
F_14 ( V_10 , V_84 , V_1 , V_2 , 2 , V_20 ) ;
V_2 += 2 ;
V_71 = ( ( V_85 * ) V_8 -> V_86 ) -> V_87 ;
if ( V_70 & 0x01 )
V_42 = V_71 | ( ( V_8 -> V_79 != V_81 ) ? 0x8000 : 0x0000 ) ;
else
V_42 = V_71 | ( ( V_8 -> V_79 == V_81 ) ? 0x8000 : 0x0000 ) ;
switch ( V_70 ) {
case 0x1 :
V_2 = F_13 ( V_10 , V_1 , V_2 ) ;
break;
case 0x2 :
V_2 = F_37 ( V_10 , V_1 , V_2 , V_8 , V_42 ) ;
break;
case 0x3 :
V_2 = F_38 ( V_10 , V_1 , V_2 ) ;
break;
case 0x4 :
V_2 = F_36 ( V_10 , V_1 , V_2 , V_8 ) ;
break;
case 0x5 :
V_2 = F_34 ( V_10 , V_1 , V_2 , V_8 , V_42 ) ;
break;
case 0x6 :
V_2 = F_31 ( V_10 , V_1 , V_2 , V_8 , V_42 ) ;
break;
case 07 :
V_2 = F_30 ( V_10 , V_1 , V_2 , V_8 , V_42 ) ;
break;
}
return V_2 ;
}
void
F_44 ( void )
{
static T_12 V_88 [] = {
{ & V_77 ,
{ L_47 , L_48 ,
V_89 , V_90 , F_45 ( V_78 ) , 0 ,
L_49 , V_91 }
} ,
{ & V_83 ,
{ L_50 , L_51 ,
V_92 , V_90 , NULL , 0 ,
NULL , V_91 }
} ,
{ & V_84 ,
{ L_52 , L_53 ,
V_92 , V_93 , NULL , 0 ,
NULL , V_91 }
} ,
{ & V_19 ,
{ L_54 , L_55 ,
V_92 , V_90 , NULL , 0 ,
NULL , V_91 }
} ,
{ & V_67 ,
{ L_56 , L_57 ,
V_92 , V_93 , NULL , 0 ,
L_58 , V_91 }
} ,
{ & V_68 ,
{ L_59 , L_60 ,
V_92 , V_93 , NULL , 0 ,
L_61 , V_91 }
} ,
{ & V_64 ,
{ L_62 , L_63 ,
V_92 , V_93 , NULL , 0 ,
L_64 , V_91 }
}
} ;
static T_11 * V_94 [] = {
& V_76 ,
& V_69 ,
& V_40 ,
& V_45 ,
& V_65 ,
& V_15
} ;
V_74 = F_46 ( L_65 , L_66 , L_67 ) ;
F_47 ( L_67 , F_39 , V_74 ) ;
V_63 = F_48 ( L_67 ) ;
F_49 ( V_74 , V_88 , F_50 ( V_88 ) ) ;
F_51 ( V_94 , F_50 ( V_94 ) ) ;
V_50 = F_52 ( V_95 , L_68 ) ;
}
void
F_53 ( void )
{
T_13 V_96 ;
V_96 = F_54 ( L_67 ) ;
F_55 ( L_69 , V_97 , V_96 ) ;
}
