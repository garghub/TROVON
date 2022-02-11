int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
unsigned long long V_4 , T_1 * V_5 )
{
T_2 V_6 [ 4 ] ;
int V_7 ;
V_7 = F_2 ( V_2 , V_3 , V_4 , V_6 , sizeof( V_6 ) ) ;
* V_5 = F_3 ( V_6 ) ;
return V_7 ;
}
int F_4 ( struct V_1 * V_2 , T_1 V_3 ,
unsigned long long V_4 , T_1 V_5 )
{
T_2 V_6 [ 4 ] ;
F_5 ( V_5 , V_6 ) ;
return F_6 ( V_2 , V_3 , V_4 , V_6 , sizeof( V_6 ) ) ;
}
int F_7 ( struct V_1 * V_2 , T_1 V_3 ,
unsigned long long V_4 , T_3 * V_5 )
{
T_2 V_6 [ 8 ] ;
int V_7 ;
V_7 = F_2 ( V_2 , V_3 , V_4 , V_6 , sizeof( V_6 ) ) ;
* V_5 = F_8 ( V_6 ) ;
return V_7 ;
}
int F_9 ( struct V_1 * V_2 , T_1 V_3 ,
unsigned long long V_4 , T_3 V_5 )
{
T_2 V_6 [ 8 ] ;
F_10 ( V_5 , V_6 ) ;
return F_6 ( V_2 , V_3 , V_4 , V_6 , sizeof( V_6 ) ) ;
}
int F_11 ( struct V_1 * V_2 , T_1 * V_8 )
{
const T_1 V_9 = F_12 ( V_10 , 0 , 0 ) ;
T_1 V_11 ;
int V_7 ;
V_7 = F_1 ( V_2 , V_9 , V_12 , V_8 ) ;
if ( V_7 < 0 )
return V_7 ;
* V_8 &= ~ 0xff ;
V_7 = F_13 ( V_2 , F_14 ( 1 , 1 , 16 ) + V_13 ,
& V_11 ) ;
if ( V_7 < 0 )
return V_7 ;
* V_8 |= ( V_14 & V_11 ) - 0x10 ;
return 0 ;
}
static T_2 F_15 ( int V_15 , T_3 V_16 )
{
if ( V_15 == 8 )
return 0xff ;
else if ( V_15 == 4 )
return 0x0f << ( V_16 & 4 ) ;
else if ( V_15 == 2 )
return 0x03 << ( V_16 & 6 ) ;
else if ( V_15 == 1 )
return 0x01 << ( V_16 & 7 ) ;
else
return 0 ;
}
int F_16 ( struct V_1 * V_2 , T_1 V_3 ,
T_3 V_16 , void * V_17 , T_4 V_18 , int V_19 )
{
struct V_20 * V_21 ;
char * V_6 = V_17 ;
int V_7 , V_22 , V_23 ;
T_2 V_24 ;
if ( V_18 & ( V_19 - 1 ) )
return - V_25 ;
V_21 = F_17 ( V_2 ) ;
if ( ! V_21 )
return - V_26 ;
V_23 = F_18 ( int , 16 * V_19 , 128 ) ;
V_23 = F_18 ( int , V_23 , V_18 ) ;
if ( F_19 ( V_3 ) == V_27 )
V_3 = F_12 ( F_20 ( V_3 ) , 0 ,
F_21 ( V_3 ) ) ;
V_24 = F_15 ( V_19 , V_16 ) ;
F_22 ( V_21 , V_3 ,
V_23 / V_19 - 1 , V_24 ) ;
F_23 ( V_21 , 1 , 0 , V_28 ,
0 , V_29 ) ;
for ( V_22 = 0 ; V_22 < V_18 ; V_22 += V_23 , V_16 += V_23 , V_6 += V_23 ) {
if ( V_22 + V_23 > V_18 ) {
V_23 = V_18 - V_22 ;
F_22 ( V_21 , V_3 ,
V_23 / V_19 - 1 ,
0xff ) ;
}
V_7 = F_24 ( V_21 , V_16 ) ;
if ( V_7 < 0 )
goto V_30;
V_7 = F_25 ( V_21 , V_6 , V_23 ) ;
if ( V_7 < 0 )
goto V_30;
}
V_7 = V_18 ;
V_30:
F_26 ( V_21 ) ;
return V_7 ;
}
int F_27 ( struct V_1 * V_2 , T_1 V_3 , T_3 V_16 ,
const void * V_17 , T_4 V_18 , int V_31 )
{
struct V_20 * V_21 ;
const char * V_6 = V_17 ;
int V_7 , V_22 , V_23 ;
T_2 V_24 ;
if ( V_18 & ( V_31 - 1 ) )
return - V_25 ;
V_21 = F_17 ( V_2 ) ;
if ( ! V_21 )
return - V_26 ;
V_23 = F_18 ( int , 16 * V_31 , 128 ) ;
V_23 = F_18 ( int , V_23 , V_18 ) ;
if ( F_19 ( V_3 ) == V_27 )
V_3 = F_12 ( F_20 ( V_3 ) , 1 ,
F_21 ( V_3 ) ) ;
V_24 = F_15 ( V_31 , V_16 ) ;
F_22 ( V_21 , V_3 ,
V_23 / V_31 - 1 , V_24 ) ;
F_23 ( V_21 , 1 , 0 , V_32 ,
0 , V_29 ) ;
for ( V_22 = 0 ; V_22 < V_18 ; V_22 += V_23 , V_16 += V_23 , V_6 += V_23 ) {
if ( V_22 + V_23 > V_18 ) {
V_23 = V_18 - V_22 ;
F_22 ( V_21 , V_3 ,
V_23 / V_31 - 1 ,
0xff ) ;
}
V_7 = F_28 ( V_21 , V_6 , V_23 ) ;
if ( V_7 < 0 )
goto V_30;
V_7 = F_24 ( V_21 , V_16 ) ;
if ( V_7 < 0 )
goto V_30;
}
V_7 = V_18 ;
V_30:
F_26 ( V_21 ) ;
return V_7 ;
}
