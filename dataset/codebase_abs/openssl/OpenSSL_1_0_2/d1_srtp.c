static int F_1 ( char * V_1 ,
T_1 * * V_2 , unsigned V_3 )
{
T_1 * V_4 ;
V_4 = V_5 ;
while ( V_4 -> V_6 ) {
if ( ( V_3 == strlen ( V_4 -> V_6 ) ) && ! strncmp ( V_4 -> V_6 , V_1 , V_3 ) ) {
* V_2 = V_4 ;
return 0 ;
}
V_4 ++ ;
}
return 1 ;
}
int F_2 ( T_2 * V_7 , const char * V_8 )
{
return F_3 ( V_8 , & V_7 -> V_9 ) ;
}
int F_4 ( T_3 * V_10 , const char * V_8 )
{
return F_3 ( V_8 , & V_10 -> V_9 ) ;
}
int F_5 ( T_3 * V_10 , unsigned char * V_4 , int * V_3 ,
int V_11 )
{
int V_12 = 0 ;
int V_13 ;
F_6 ( T_1 ) * V_14 = 0 ;
T_1 * V_15 ;
V_14 = F_7 ( V_10 ) ;
V_12 = F_8 ( V_14 ) ;
if ( V_4 ) {
if ( V_12 == 0 ) {
F_9 ( V_16 ,
V_17 ) ;
return 1 ;
}
if ( ( 2 + V_12 * 2 + 1 ) > V_11 ) {
F_9 ( V_16 ,
V_18 ) ;
return 1 ;
}
F_10 ( V_12 * 2 , V_4 ) ;
for ( V_13 = 0 ; V_13 < V_12 ; V_13 ++ ) {
V_15 = F_11 ( V_14 , V_13 ) ;
F_10 ( V_15 -> V_19 , V_4 ) ;
}
* V_4 ++ = 0 ;
}
* V_3 = 2 + V_12 * 2 + 1 ;
return 0 ;
}
int F_12 ( T_3 * V_10 , unsigned char * V_20 , int V_3 ,
int * V_21 )
{
T_1 * V_22 ;
F_6 ( T_1 ) * V_23 ;
int V_12 ;
int V_24 ;
int V_13 , V_25 ;
unsigned int V_19 ;
if ( V_3 < 3 ) {
F_9 ( V_26 ,
V_27 ) ;
* V_21 = V_28 ;
return 1 ;
}
F_13 ( V_20 , V_12 ) ;
V_3 -= 2 ;
if ( V_12 % 2 ) {
F_9 ( V_26 ,
V_27 ) ;
* V_21 = V_28 ;
return 1 ;
}
if ( V_3 < ( V_12 + 1 ) ) {
F_9 ( V_26 ,
V_27 ) ;
* V_21 = V_28 ;
return 1 ;
}
V_23 = F_7 ( V_10 ) ;
V_10 -> V_29 = NULL ;
V_25 = F_8 ( V_23 ) ;
while ( V_12 ) {
F_13 ( V_20 , V_19 ) ;
V_12 -= 2 ;
V_3 -= 2 ;
for ( V_13 = 0 ; V_13 < V_25 ; V_13 ++ ) {
V_22 = F_11 ( V_23 , V_13 ) ;
if ( V_22 -> V_19 == V_19 ) {
V_10 -> V_29 = V_22 ;
V_25 = V_13 ;
break;
}
}
}
V_24 = * V_20 ;
V_20 ++ ;
V_3 -- ;
if ( V_24 != V_3 ) {
F_9 ( V_26 ,
V_30 ) ;
* V_21 = V_28 ;
return 1 ;
}
return 0 ;
}
int F_14 ( T_3 * V_10 , unsigned char * V_4 , int * V_3 ,
int V_11 )
{
if ( V_4 ) {
if ( V_11 < 5 ) {
F_9 ( V_31 ,
V_18 ) ;
return 1 ;
}
if ( V_10 -> V_29 == 0 ) {
F_9 ( V_31 ,
V_32 ) ;
return 1 ;
}
F_10 ( 2 , V_4 ) ;
F_10 ( V_10 -> V_29 -> V_19 , V_4 ) ;
* V_4 ++ = 0 ;
}
* V_3 = 5 ;
return 0 ;
}
int F_15 ( T_3 * V_10 , unsigned char * V_20 , int V_3 ,
int * V_21 )
{
unsigned V_19 ;
int V_13 ;
int V_12 ;
F_6 ( T_1 ) * V_14 ;
T_1 * V_15 ;
if ( V_3 != 5 ) {
F_9 ( V_33 ,
V_27 ) ;
* V_21 = V_28 ;
return 1 ;
}
F_13 ( V_20 , V_12 ) ;
if ( V_12 != 2 ) {
F_9 ( V_33 ,
V_27 ) ;
* V_21 = V_28 ;
return 1 ;
}
F_13 ( V_20 , V_19 ) ;
if ( * V_20 ) {
F_9 ( V_33 ,
V_30 ) ;
* V_21 = V_34 ;
return 1 ;
}
V_14 = F_7 ( V_10 ) ;
if ( V_14 == NULL ) {
F_9 ( V_33 ,
V_35 ) ;
* V_21 = V_28 ;
return 1 ;
}
for ( V_13 = 0 ; V_13 < F_8 ( V_14 ) ; V_13 ++ ) {
V_15 = F_11 ( V_14 , V_13 ) ;
if ( V_15 -> V_19 == V_19 ) {
V_10 -> V_29 = V_15 ;
* V_21 = 0 ;
return 0 ;
}
}
F_9 ( V_33 ,
V_27 ) ;
* V_21 = V_28 ;
return 1 ;
}
