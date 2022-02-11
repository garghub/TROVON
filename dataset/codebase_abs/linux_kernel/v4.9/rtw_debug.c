int F_1 ( char * V_1 , char * * V_2 ,
T_1 V_3 , int V_4 ,
int * V_5 , void * V_6 )
{
int V_7 = 0 ;
V_7 += snprintf ( V_1 + V_7 , V_4 - V_7 , L_1 , V_8 ) ;
* V_5 = 1 ;
return V_7 ;
}
int F_2 ( char * V_1 , char * * V_2 ,
T_1 V_3 , int V_4 ,
int * V_5 , void * V_6 )
{
* V_5 = 1 ;
return 0 ;
}
int F_3 ( struct V_9 * V_9 , const char T_2 * V_10 ,
unsigned long V_4 , void * V_6 )
{
struct V_11 * V_12 = V_6 ;
struct V_13 * V_14 = (struct V_13 * ) F_4 ( V_12 ) ;
char V_15 [ 32 ] ;
T_3 V_16 , V_17 , V_7 ;
if ( V_4 < 3 ) {
F_5 ( L_2 ) ;
return - V_18 ;
}
if ( V_10 && ! F_6 ( V_15 , V_10 , sizeof( V_15 ) ) ) {
int V_19 = sscanf ( V_15 , L_3 , & V_16 , & V_17 , & V_7 ) ;
if ( V_19 != 3 ) {
F_5 ( L_4 ) ;
return V_4 ;
}
switch ( V_7 ) {
case 1 :
F_7 ( V_14 , V_16 , ( V_20 ) V_17 ) ;
break;
case 2 :
F_8 ( V_14 , V_16 , ( V_21 ) V_17 ) ;
break;
case 4 :
F_9 ( V_14 , V_16 , V_17 ) ;
break;
default:
F_5 ( L_5 , V_7 ) ;
break;
}
}
return V_4 ;
}
int F_10 ( char * V_1 , char * * V_2 ,
T_1 V_3 , int V_4 ,
int * V_5 , void * V_6 )
{
struct V_11 * V_12 = V_6 ;
struct V_13 * V_14 = (struct V_13 * ) F_4 ( V_12 ) ;
int V_7 = 0 ;
if ( V_22 == 0xeeeeeeee ) {
* V_5 = 1 ;
return V_7 ;
}
switch ( V_23 ) {
case 1 :
V_7 += snprintf ( V_1 + V_7 , V_4 - V_7 , L_6 , V_22 , F_11 ( V_14 , V_22 ) ) ;
break;
case 2 :
V_7 += snprintf ( V_1 + V_7 , V_4 - V_7 , L_7 , V_22 , F_12 ( V_14 , V_22 ) ) ;
break;
case 4 :
V_7 += snprintf ( V_1 + V_7 , V_4 - V_7 , L_8 , V_22 , F_13 ( V_14 , V_22 ) ) ;
break;
default:
V_7 += snprintf ( V_1 + V_7 , V_4 - V_7 , L_9 , V_23 ) ;
break;
}
* V_5 = 1 ;
return V_7 ;
}
int F_14 ( struct V_9 * V_9 , const char T_2 * V_10 ,
unsigned long V_4 , void * V_6 )
{
char V_15 [ 16 ] ;
T_3 V_16 , V_7 ;
if ( V_4 < 2 ) {
F_5 ( L_10 ) ;
return - V_18 ;
}
if ( V_10 && ! F_6 ( V_15 , V_10 , sizeof( V_15 ) ) ) {
int V_19 = sscanf ( V_15 , L_11 , & V_16 , & V_7 ) ;
if ( V_19 != 2 ) {
F_5 ( L_12 ) ;
return V_4 ;
}
V_22 = V_16 ;
V_23 = V_7 ;
}
return V_4 ;
}
int F_15 ( char * V_1 , char * * V_2 ,
T_1 V_3 , int V_4 ,
int * V_5 , void * V_6 )
{
struct V_11 * V_12 = V_6 ;
struct V_13 * V_14 = (struct V_13 * ) F_4 ( V_12 ) ;
int V_7 = 0 ;
V_7 += snprintf ( V_1 + V_7 , V_4 - V_7 , L_13 ,
V_14 -> V_24 , V_14 -> V_25 ) ;
* V_5 = 1 ;
return V_7 ;
}
int F_16 ( char * V_1 , char * * V_2 ,
T_1 V_3 , int V_4 ,
int * V_5 , void * V_6 )
{
struct V_11 * V_12 = V_6 ;
struct V_13 * V_14 = (struct V_13 * ) F_4 ( V_12 ) ;
struct V_26 * V_27 = & V_14 -> V_28 ;
int V_7 = 0 ;
T_3 V_29 , V_30 = 1 , V_31 = 36 , V_32 = 0 , V_33 = 0 ;
for ( V_29 = 0 ; V_27 -> V_34 [ V_29 ] . V_35 != 0 ; V_29 ++ ) {
if ( V_27 -> V_34 [ V_29 ] . V_35 == 1 )
V_32 = V_29 ;
if ( V_27 -> V_34 [ V_29 ] . V_35 == 36 )
V_33 = V_29 ;
}
for ( V_29 = 0 ; V_27 -> V_34 [ V_29 ] . V_35 != 0 ; V_29 ++ ) {
if ( V_27 -> V_34 [ V_29 ] . V_35 == 6 ) {
if ( V_27 -> V_34 [ V_29 ] . V_36 < V_27 -> V_34 [ V_32 ] . V_36 ) {
V_32 = V_29 ;
V_30 = V_27 -> V_34 [ V_29 ] . V_35 ;
}
}
if ( V_27 -> V_34 [ V_29 ] . V_35 >= 36 &&
V_27 -> V_34 [ V_29 ] . V_35 < 140 ) {
if ( ( ( V_27 -> V_34 [ V_29 ] . V_35 - 36 ) % 8 == 0 ) &&
( V_27 -> V_34 [ V_29 ] . V_36 < V_27 -> V_34 [ V_33 ] . V_36 ) ) {
V_33 = V_29 ;
V_31 = V_27 -> V_34 [ V_29 ] . V_35 ;
}
}
if ( V_27 -> V_34 [ V_29 ] . V_35 >= 149 &&
V_27 -> V_34 [ V_29 ] . V_35 < 165 ) {
if ( ( ( V_27 -> V_34 [ V_29 ] . V_35 - 149 ) % 8 == 0 ) &&
( V_27 -> V_34 [ V_29 ] . V_36 < V_27 -> V_34 [ V_33 ] . V_36 ) ) {
V_33 = V_29 ;
V_31 = V_27 -> V_34 [ V_29 ] . V_35 ;
}
}
V_7 += snprintf ( V_1 + V_7 , V_4 - V_7 , L_14 ,
V_27 -> V_34 [ V_29 ] . V_35 , V_27 -> V_34 [ V_29 ] . V_36 ) ;
}
V_7 += snprintf ( V_1 + V_7 , V_4 - V_7 , L_15 , V_31 ) ;
V_7 += snprintf ( V_1 + V_7 , V_4 - V_7 , L_16 , V_30 ) ;
* V_5 = 1 ;
return V_7 ;
}
