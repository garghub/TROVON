static int F_1 ( struct V_1 * V_2 , unsigned V_3 ,
T_1 V_4 , T_1 V_5 ,
int V_6 , int V_7 )
{
unsigned long V_8 ;
unsigned long V_9 ;
struct V_10 * V_11 = NULL ;
int V_12 , V_13 ;
V_8 = V_14 ;
for ( V_12 = 0 ; V_12 < V_7 ; V_12 ++ ) {
V_13 = F_2 ( V_2 , & V_11 , V_15 ) ;
if ( V_13 )
return V_13 ;
switch ( V_6 ) {
case V_16 :
V_13 = F_3 ( V_2 , V_4 , V_5 ,
V_3 / V_17 ,
V_11 ) ;
break;
case V_18 :
V_13 = F_4 ( V_2 , V_4 , V_5 ,
V_3 / V_17 ,
V_11 ) ;
break;
default:
F_5 ( L_1 ) ;
V_13 = - V_19 ;
}
if ( V_13 )
goto V_20;
V_13 = F_6 ( V_11 , false ) ;
if ( V_13 )
goto V_20;
F_7 ( & V_11 ) ;
}
V_9 = V_14 ;
V_13 = F_8 ( V_9 - V_8 ) ;
V_20:
if ( V_11 )
F_7 ( & V_11 ) ;
return V_13 ;
}
static void F_9 ( int V_7 , unsigned V_3 ,
unsigned int time ,
unsigned V_21 , unsigned V_22 ,
char * V_23 )
{
unsigned int V_24 = ( V_7 * ( V_3 >> 10 ) ) / time ;
F_10 ( L_2
L_3 ,
V_23 , V_7 , V_3 >> 10 , V_21 , V_22 , time ,
V_24 * 8 , V_24 ) ;
}
static void F_11 ( struct V_1 * V_2 , unsigned V_3 ,
unsigned V_21 , unsigned V_22 )
{
struct V_25 * V_26 = NULL ;
struct V_25 * V_27 = NULL ;
T_1 V_4 , V_5 ;
int V_13 , V_7 ;
int time ;
V_7 = V_28 ;
V_13 = F_12 ( V_2 , V_3 , V_29 , true , V_21 , & V_27 ) ;
if ( V_13 ) {
goto V_30;
}
V_13 = F_13 ( V_27 , false ) ;
if ( F_14 ( V_13 != 0 ) )
goto V_30;
V_13 = F_15 ( V_27 , V_21 , & V_4 ) ;
F_16 ( V_27 ) ;
if ( V_13 ) {
goto V_30;
}
V_13 = F_12 ( V_2 , V_3 , V_29 , true , V_22 , & V_26 ) ;
if ( V_13 ) {
goto V_30;
}
V_13 = F_13 ( V_26 , false ) ;
if ( F_14 ( V_13 != 0 ) )
goto V_30;
V_13 = F_15 ( V_26 , V_22 , & V_5 ) ;
F_16 ( V_26 ) ;
if ( V_13 ) {
goto V_30;
}
if ( ( V_2 -> V_31 -> V_32 ) && ( V_21 != V_22 ) ) {
time = F_1 ( V_2 , V_3 , V_4 , V_5 ,
V_16 , V_7 ) ;
if ( time < 0 )
goto V_30;
if ( time > 0 )
F_9 ( V_7 , V_3 , time ,
V_21 , V_22 , L_4 ) ;
}
time = F_1 ( V_2 , V_3 , V_4 , V_5 ,
V_18 , V_7 ) ;
if ( time < 0 )
goto V_30;
if ( time > 0 )
F_9 ( V_7 , V_3 , time ,
V_21 , V_22 , L_5 ) ;
V_30:
if ( V_27 ) {
V_13 = F_13 ( V_27 , false ) ;
if ( F_17 ( V_13 == 0 ) ) {
F_18 ( V_27 ) ;
F_16 ( V_27 ) ;
}
F_19 ( & V_27 ) ;
}
if ( V_26 ) {
V_13 = F_13 ( V_26 , false ) ;
if ( F_17 ( V_13 == 0 ) ) {
F_18 ( V_26 ) ;
F_16 ( V_26 ) ;
}
F_19 ( & V_26 ) ;
}
if ( V_13 ) {
F_5 ( L_6 ) ;
}
}
void F_20 ( struct V_1 * V_2 , int V_33 )
{
int V_12 ;
int V_34 [ V_35 ] = {
640 * 480 * 4 ,
720 * 480 * 4 ,
800 * 600 * 4 ,
848 * 480 * 4 ,
1024 * 768 * 4 ,
1152 * 768 * 4 ,
1280 * 720 * 4 ,
1280 * 800 * 4 ,
1280 * 854 * 4 ,
1280 * 960 * 4 ,
1280 * 1024 * 4 ,
1440 * 900 * 4 ,
1400 * 1050 * 4 ,
1680 * 1050 * 4 ,
1600 * 1200 * 4 ,
1920 * 1080 * 4 ,
1920 * 1200 * 4
} ;
switch ( V_33 ) {
case 1 :
F_11 ( V_2 , 1024 * 1024 , V_36 ,
V_37 ) ;
F_11 ( V_2 , 1024 * 1024 , V_37 ,
V_36 ) ;
break;
case 2 :
F_11 ( V_2 , 1024 * 1024 , V_37 ,
V_37 ) ;
break;
case 3 :
for ( V_12 = 1 ; V_12 <= 65536 ; V_12 <<= 1 )
F_11 ( V_2 , V_12 * 1024 ,
V_36 ,
V_37 ) ;
break;
case 4 :
for ( V_12 = 1 ; V_12 <= 65536 ; V_12 <<= 1 )
F_11 ( V_2 , V_12 * 1024 ,
V_37 ,
V_36 ) ;
break;
case 5 :
for ( V_12 = 1 ; V_12 <= 65536 ; V_12 <<= 1 )
F_11 ( V_2 , V_12 * 1024 ,
V_37 ,
V_37 ) ;
break;
case 6 :
for ( V_12 = 0 ; V_12 < V_35 ; V_12 ++ )
F_11 ( V_2 , V_34 [ V_12 ] ,
V_36 ,
V_37 ) ;
break;
case 7 :
for ( V_12 = 0 ; V_12 < V_35 ; V_12 ++ )
F_11 ( V_2 , V_34 [ V_12 ] ,
V_37 ,
V_36 ) ;
break;
case 8 :
for ( V_12 = 0 ; V_12 < V_35 ; V_12 ++ )
F_11 ( V_2 , V_34 [ V_12 ] ,
V_37 ,
V_37 ) ;
break;
default:
F_5 ( L_7 ) ;
}
}
