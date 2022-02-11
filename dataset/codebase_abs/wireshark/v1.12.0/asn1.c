void
F_1 ( T_1 * V_1 , T_2 * V_2 , int V_3 )
{
V_1 -> V_2 = V_2 ;
V_1 -> V_3 = V_3 ;
}
void
F_2 ( T_1 * V_1 , int * V_3 )
{
* V_3 = V_1 -> V_3 ;
}
int
F_3 ( T_1 * V_1 , T_3 * V_4 )
{
* V_4 = F_4 ( V_1 -> V_2 , V_1 -> V_3 ) ;
V_1 -> V_3 ++ ;
return V_5 ;
}
static int
F_5 ( T_1 * V_1 , T_4 * V_6 )
{
int V_7 ;
T_3 V_4 ;
do {
V_7 = F_3 ( V_1 , & V_4 ) ;
if ( V_7 != V_5 )
return V_7 ;
* V_6 <<= 7 ;
* V_6 |= V_4 & 0x7F ;
} while ( ( V_4 & 0x80 ) == 0x80 );
return V_5 ;
}
int
F_6 ( T_1 * V_1 , T_4 * V_6 )
{
* V_6 = 0 ;
return F_5 ( V_1 , V_6 ) ;
}
int
F_7 ( T_1 * V_1 , T_4 * V_8 , T_4 * V_9 , T_4 * V_6 )
{
int V_7 ;
T_3 V_4 ;
* V_6 = 0 ;
V_7 = F_3 ( V_1 , & V_4 ) ;
if ( V_7 != V_5 )
return V_7 ;
* V_8 = ( V_4 & 0xC0 ) >> 6 ;
* V_9 = ( V_4 & 0x20 ) >> 5 ;
* V_6 = ( V_4 & 0x1F ) ;
if ( * V_6 == 0x1F ) {
V_7 = F_6 ( V_1 , V_6 ) ;
if ( V_7 != V_5 )
return V_7 ;
}
return V_5 ;
}
int
F_8 ( T_1 * V_1 , T_4 * V_6 )
{
int V_7 ;
T_3 V_4 ;
* V_6 = 0 ;
V_7 = F_3 ( V_1 , & V_4 ) ;
if ( V_7 != V_5 )
return V_7 ;
* V_6 = V_4 ;
if ( ( * V_6 & 0x1F ) == 0x1F ) {
* V_6 = V_4 >> 5 ;
V_7 = F_5 ( V_1 , V_6 ) ;
if ( V_7 != V_5 )
return V_7 ;
}
return V_5 ;
}
int
F_9 ( T_1 * V_1 , T_5 * V_10 , T_4 * V_11 )
{
int V_7 ;
T_3 V_4 , V_12 ;
V_7 = F_3 ( V_1 , & V_4 ) ;
if ( V_7 != V_5 )
return V_7 ;
if ( V_4 == 0x80 )
* V_10 = FALSE ;
else {
* V_10 = TRUE ;
if ( V_4 < 0x80 )
* V_11 = V_4 ;
else {
V_12 = ( T_3 ) ( V_4 & 0x7F ) ;
* V_11 = 0 ;
while ( V_12 > 0 ) {
V_7 = F_3 ( V_1 , & V_4 ) ;
if ( V_7 != V_5 )
return V_7 ;
* V_11 <<= 8 ;
* V_11 |= V_4 ;
V_12 -- ;
}
}
}
return V_5 ;
}
int
F_10 ( T_1 * V_1 , T_4 * V_8 , T_4 * V_9 , T_4 * V_6 ,
T_5 * V_13 , T_4 * V_14 )
{
int V_7 ;
T_4 V_11 = 0 ;
T_5 V_10 ;
V_7 = F_7 ( V_1 , V_8 , V_9 , V_6 ) ;
if ( V_7 != V_5 )
return V_7 ;
V_7 = F_9 ( V_1 , & V_10 , & V_11 ) ;
if ( V_7 != V_5 )
return V_7 ;
* V_13 = V_10 ;
* V_14 = V_11 ;
return V_5 ;
}
T_5
F_11 ( T_1 * V_1 , int V_15 )
{
if ( V_15 == - 1 )
return ( F_4 ( V_1 -> V_2 , V_1 -> V_3 ) == 0x00
&& F_4 ( V_1 -> V_2 , V_1 -> V_3 + 1 ) == 0x00 ) ;
else
return ( V_1 -> V_3 >= V_15 ) ;
}
int
F_12 ( T_1 * V_1 , int V_15 )
{
int V_7 ;
T_3 V_4 ;
if ( V_15 == - 1 ) {
V_7 = F_3 ( V_1 , & V_4 ) ;
if ( V_7 != V_5 )
return V_7 ;
if ( V_4 != 0x00 )
return V_16 ;
V_7 = F_3 ( V_1 , & V_4 ) ;
if ( V_7 != V_5 )
return V_7 ;
if ( V_4 != 0x00 )
return V_16 ;
return V_5 ;
} else {
if ( V_1 -> V_3 != V_15 )
return V_17 ;
return V_5 ;
}
}
int
F_13 ( T_1 * V_1 , int V_18 )
{
int V_19 = V_1 -> V_3 ;
V_1 -> V_3 += V_18 ;
if ( V_1 -> V_3 < 0 || V_1 -> V_3 < V_19 )
return V_17 ;
return V_5 ;
}
int
F_14 ( T_1 * V_1 , int V_18 , T_5 * boolean )
{
int V_7 ;
T_3 V_4 ;
if ( V_18 != 1 )
return V_17 ;
V_7 = F_3 ( V_1 , & V_4 ) ;
if ( V_7 != V_5 )
return V_7 ;
* boolean = V_4 ? TRUE : FALSE ;
return V_5 ;
}
int
F_15 ( T_1 * V_1 , int V_18 , T_6 * integer )
{
int V_7 ;
int V_15 ;
T_3 V_4 ;
T_4 V_11 ;
V_15 = V_1 -> V_3 + V_18 ;
V_7 = F_3 ( V_1 , & V_4 ) ;
if ( V_7 != V_5 )
return V_7 ;
* integer = ( V_20 ) V_4 ;
V_11 = 1 ;
while ( V_1 -> V_3 < V_15 ) {
if ( ++ V_11 > sizeof ( T_6 ) )
return V_21 ;
V_7 = F_3 ( V_1 , & V_4 ) ;
if ( V_7 != V_5 )
return V_7 ;
* integer <<= 8 ;
* integer |= V_4 ;
}
return V_5 ;
}
int
F_16 ( T_1 * V_1 , T_6 * integer , T_4 * V_22 )
{
int V_7 ;
int V_23 ;
T_4 V_8 ;
T_4 V_9 ;
T_4 V_6 ;
T_5 V_10 ;
T_4 V_18 ;
V_23 = V_1 -> V_3 ;
V_7 = F_10 ( V_1 , & V_8 , & V_9 , & V_6 , & V_10 , & V_18 ) ;
if ( V_7 != V_5 )
goto V_24;
if ( V_8 != V_25 || V_9 != V_26 || V_6 != V_27 ) {
V_7 = V_28 ;
goto V_24;
}
if ( ! V_10 ) {
V_7 = V_29 ;
goto V_24;
}
V_7 = F_15 ( V_1 , V_18 , integer ) ;
V_24:
* V_22 = V_1 -> V_3 - V_23 ;
return V_7 ;
}
int
F_17 ( T_1 * V_1 , int V_18 , T_7 * integer )
{
int V_7 ;
int V_15 ;
T_3 V_4 ;
T_4 V_11 ;
V_15 = V_1 -> V_3 + V_18 ;
V_7 = F_3 ( V_1 , & V_4 ) ;
if ( V_7 != V_5 )
return V_7 ;
* integer = V_4 ;
if ( V_4 == 0 )
V_11 = 0 ;
else
V_11 = 1 ;
while ( V_1 -> V_3 < V_15 ) {
if ( ++ V_11 > sizeof ( T_7 ) )
return V_21 ;
V_7 = F_3 ( V_1 , & V_4 ) ;
if ( V_7 != V_5 )
return V_7 ;
* integer <<= 8 ;
* integer |= V_4 ;
}
return V_5 ;
}
int
F_18 ( T_1 * V_1 , T_7 * integer , T_4 * V_22 )
{
int V_7 ;
int V_23 ;
T_4 V_8 ;
T_4 V_9 ;
T_4 V_6 ;
T_5 V_10 ;
T_4 V_18 ;
V_23 = V_1 -> V_3 ;
V_7 = F_10 ( V_1 , & V_8 , & V_9 , & V_6 , & V_10 , & V_18 ) ;
if ( V_7 != V_5 )
goto V_24;
if ( V_8 != V_25 || V_9 != V_26 || V_6 != V_27 ) {
V_7 = V_28 ;
goto V_24;
}
if ( ! V_10 ) {
V_7 = V_29 ;
goto V_24;
}
V_7 = F_17 ( V_1 , V_18 , integer ) ;
V_24:
* V_22 = V_1 -> V_3 - V_23 ;
return V_7 ;
}
int
F_19 ( T_1 * V_1 , int V_18 , T_3 * * V_30 ,
T_4 * V_11 , T_3 * V_31 )
{
int V_7 ;
int V_15 ;
T_3 * V_32 ;
V_15 = V_1 -> V_3 + V_18 ;
* V_30 = NULL ;
V_7 = F_3 ( V_1 , V_31 ) ;
if ( V_7 != V_5 )
return V_7 ;
* V_11 = 0 ;
if ( V_18 != 0 ) {
F_20 ( V_1 -> V_2 , V_1 -> V_3 , V_18 ) ;
* V_30 = ( T_3 * ) F_21 ( V_18 ) ;
} else {
* V_30 = ( T_3 * ) F_21 ( 1 ) ;
}
V_32 = * V_30 ;
while ( V_1 -> V_3 < V_15 ) {
V_7 = F_3 ( V_1 , ( T_3 * ) V_32 ++ ) ;
if ( V_7 != V_5 ) {
F_22 ( * V_30 ) ;
* V_30 = NULL ;
return V_7 ;
}
}
* V_11 = ( T_4 ) ( V_32 - * V_30 ) ;
return V_5 ;
}
int
F_23 ( T_1 * V_1 , int V_18 , T_3 * * V_33 )
{
int V_7 ;
int V_15 ;
T_3 * V_32 ;
if ( V_18 != 0 )
F_20 ( V_1 -> V_2 , V_1 -> V_3 , V_18 ) ;
* V_33 = ( T_3 * ) F_21 ( V_18 + 1 ) ;
V_15 = V_1 -> V_3 + V_18 ;
V_32 = * V_33 ;
while ( V_1 -> V_3 < V_15 ) {
V_7 = F_3 ( V_1 , ( T_3 * ) V_32 ++ ) ;
if ( V_7 != V_5 ) {
F_22 ( * V_33 ) ;
* V_33 = NULL ;
return V_7 ;
}
}
* ( T_3 * ) V_32 = '\0' ;
return V_5 ;
}
int
F_24 ( T_1 * V_1 , T_3 * * V_33 , T_4 * V_34 ,
T_4 * V_22 , T_4 V_35 )
{
int V_7 ;
int V_23 ;
T_4 V_18 ;
T_4 V_8 ;
T_4 V_9 ;
T_4 V_6 ;
T_5 V_10 ;
V_23 = V_1 -> V_3 ;
V_7 = F_10 ( V_1 , & V_8 , & V_9 , & V_6 , & V_10 , & V_18 ) ;
if ( V_7 != V_5 )
goto V_24;
if ( V_8 != V_25 || V_9 != V_26 || V_6 != V_35 ) {
V_7 = V_28 ;
goto V_24;
}
if ( ! V_10 ) {
V_7 = V_29 ;
goto V_24;
}
V_7 = F_23 ( V_1 , V_18 , V_33 ) ;
* V_34 = V_18 ;
V_24:
* V_22 = V_1 -> V_3 - V_23 ;
return V_7 ;
}
int
F_25 ( T_1 * V_1 , T_3 * * V_33 , T_4 * V_34 ,
T_4 * V_22 )
{
return F_24 ( V_1 , V_33 , V_34 , V_22 , V_36 ) ;
}
int
F_26 ( T_1 * V_1 , T_8 * V_37 )
{
int V_7 ;
T_3 V_4 ;
* V_37 = 0 ;
do {
V_7 = F_3 ( V_1 , & V_4 ) ;
if ( V_7 != V_5 )
return V_7 ;
* V_37 <<= 7 ;
* V_37 |= V_4 & 0x7F ;
} while ( ( V_4 & 0x80 ) == 0x80 );
return V_5 ;
}
int
F_27 ( T_1 * V_1 , int V_18 , T_8 * * V_38 , T_4 * V_11 )
{
int V_7 ;
int V_15 ;
T_8 V_37 ;
T_4 V_39 ;
T_8 * V_40 ;
if ( V_18 < 1 ) {
* V_38 = NULL ;
return V_17 ;
}
F_20 ( V_1 -> V_2 , V_1 -> V_3 , V_18 ) ;
V_15 = V_1 -> V_3 + V_18 ;
V_39 = V_18 + 1 ;
* V_38 = ( T_7 * ) F_21 ( V_39 * sizeof( V_41 ) ) ;
V_40 = * V_38 ;
V_7 = F_26 ( V_1 , & V_37 ) ;
if ( V_7 != V_5 ) {
F_22 ( * V_38 ) ;
* V_38 = NULL ;
return V_7 ;
}
if ( V_37 < 40 ) {
V_40 [ 0 ] = 0 ;
V_40 [ 1 ] = V_37 ;
} else if ( V_37 < 80 ) {
V_40 [ 0 ] = 1 ;
V_40 [ 1 ] = V_37 - 40 ;
} else {
V_40 [ 0 ] = 2 ;
V_40 [ 1 ] = V_37 - 80 ;
}
* V_11 = 2 ;
V_40 += 2 ;
while ( V_1 -> V_3 < V_15 ) {
if ( ++ ( * V_11 ) > V_39 ) {
F_22 ( * V_38 ) ;
* V_38 = NULL ;
return V_21 ;
}
V_7 = F_26 ( V_1 , V_40 ++ ) ;
if ( V_7 != V_5 ) {
F_22 ( * V_38 ) ;
* V_38 = NULL ;
return V_7 ;
}
}
return V_5 ;
}
int
F_28 ( T_1 * V_1 , T_8 * * V_38 , T_4 * V_11 , T_4 * V_22 )
{
int V_7 ;
int V_23 ;
T_4 V_8 ;
T_4 V_9 ;
T_4 V_6 ;
T_5 V_10 ;
T_4 V_18 ;
V_23 = V_1 -> V_3 ;
V_7 = F_10 ( V_1 , & V_8 , & V_9 , & V_6 , & V_10 , & V_18 ) ;
if ( V_7 != V_5 )
goto V_24;
if ( V_8 != V_25 || V_9 != V_26 || V_6 != V_42 ) {
V_7 = V_28 ;
goto V_24;
}
if ( ! V_10 ) {
V_7 = V_29 ;
goto V_24;
}
V_7 = F_27 ( V_1 , V_18 , V_38 , V_11 ) ;
V_24:
* V_22 = V_1 -> V_3 - V_23 ;
return V_7 ;
}
int
F_29 ( T_1 * V_1 , T_4 * V_43 , T_4 * V_22 )
{
int V_7 ;
int V_23 ;
T_4 V_8 ;
T_4 V_9 ;
T_4 V_6 ;
T_5 V_10 ;
V_23 = V_1 -> V_3 ;
V_7 = F_10 ( V_1 , & V_8 , & V_9 , & V_6 ,
& V_10 , V_43 ) ;
if ( V_7 != V_5 )
goto V_24;
if ( V_8 != V_25 || V_9 != V_44 || V_6 != V_45 ) {
V_7 = V_28 ;
goto V_24;
}
if ( ! V_10 ) {
V_7 = V_29 ;
goto V_24;
}
V_7 = V_5 ;
V_24:
* V_22 = V_1 -> V_3 - V_23 ;
return V_7 ;
}
const char *
F_30 ( int V_46 )
{
const char * V_47 ;
char V_48 [ 14 + 1 + 1 + 11 + 1 + 1 ] ;
switch ( V_46 ) {
case V_16 :
V_47 = L_1 ;
break;
case V_28 :
V_47 = L_2 ;
break;
case V_29 :
V_47 = L_3 ;
break;
case V_17 :
V_47 = L_4 ;
break;
case V_21 :
V_47 = L_5 ;
break;
default:
F_31 ( V_48 , sizeof V_48 , L_6 , V_46 ) ;
V_47 = F_32 ( V_48 ) ;
break;
}
return V_47 ;
}
