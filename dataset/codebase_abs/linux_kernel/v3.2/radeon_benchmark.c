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
V_13 = F_2 ( V_2 , & V_11 ) ;
if ( V_13 )
return V_13 ;
switch ( V_6 ) {
case V_15 :
V_13 = F_3 ( V_2 , V_4 , V_5 ,
V_3 / V_16 ,
V_11 ) ;
break;
case V_17 :
V_13 = F_4 ( V_2 , V_4 , V_5 ,
V_3 / V_16 ,
V_11 ) ;
break;
default:
F_5 ( L_1 ) ;
V_13 = - V_18 ;
}
if ( V_13 )
goto V_19;
V_13 = F_6 ( V_11 , false ) ;
if ( V_13 )
goto V_19;
F_7 ( & V_11 ) ;
}
V_9 = V_14 ;
V_13 = F_8 ( V_9 - V_8 ) ;
V_19:
if ( V_11 )
F_7 ( & V_11 ) ;
return V_13 ;
}
static void F_9 ( int V_7 , unsigned V_3 ,
unsigned int time ,
unsigned V_20 , unsigned V_21 ,
char * V_22 )
{
unsigned int V_23 = ( V_7 * ( V_3 >> 10 ) ) / time ;
F_10 ( L_2
L_3 ,
V_22 , V_7 , V_3 >> 10 , V_20 , V_21 , time ,
V_23 * 8 , V_23 ) ;
}
static void F_11 ( struct V_1 * V_2 , unsigned V_3 ,
unsigned V_20 , unsigned V_21 )
{
struct V_24 * V_25 = NULL ;
struct V_24 * V_26 = NULL ;
T_1 V_4 , V_5 ;
int V_13 , V_7 ;
int time ;
V_7 = V_27 ;
V_13 = F_12 ( V_2 , V_3 , V_28 , true , V_20 , & V_26 ) ;
if ( V_13 ) {
goto V_29;
}
V_13 = F_13 ( V_26 , false ) ;
if ( F_14 ( V_13 != 0 ) )
goto V_29;
V_13 = F_15 ( V_26 , V_20 , & V_4 ) ;
F_16 ( V_26 ) ;
if ( V_13 ) {
goto V_29;
}
V_13 = F_12 ( V_2 , V_3 , V_28 , true , V_21 , & V_25 ) ;
if ( V_13 ) {
goto V_29;
}
V_13 = F_13 ( V_25 , false ) ;
if ( F_14 ( V_13 != 0 ) )
goto V_29;
V_13 = F_15 ( V_25 , V_21 , & V_5 ) ;
F_16 ( V_25 ) ;
if ( V_13 ) {
goto V_29;
}
if ( ( V_2 -> V_30 -> V_31 ) && ( V_20 != V_21 ) ) {
time = F_1 ( V_2 , V_3 , V_4 , V_5 ,
V_15 , V_7 ) ;
if ( time < 0 )
goto V_29;
if ( time > 0 )
F_9 ( V_7 , V_3 , time ,
V_20 , V_21 , L_4 ) ;
}
time = F_1 ( V_2 , V_3 , V_4 , V_5 ,
V_17 , V_7 ) ;
if ( time < 0 )
goto V_29;
if ( time > 0 )
F_9 ( V_7 , V_3 , time ,
V_20 , V_21 , L_5 ) ;
V_29:
if ( V_26 ) {
V_13 = F_13 ( V_26 , false ) ;
if ( F_17 ( V_13 == 0 ) ) {
F_18 ( V_26 ) ;
F_16 ( V_26 ) ;
}
F_19 ( & V_26 ) ;
}
if ( V_25 ) {
V_13 = F_13 ( V_25 , false ) ;
if ( F_17 ( V_13 == 0 ) ) {
F_18 ( V_25 ) ;
F_16 ( V_25 ) ;
}
F_19 ( & V_25 ) ;
}
if ( V_13 ) {
F_5 ( L_6 ) ;
}
}
void F_20 ( struct V_1 * V_2 , int V_32 )
{
int V_12 ;
int V_33 [ V_34 ] = {
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
switch ( V_32 ) {
case 1 :
F_11 ( V_2 , 1024 * 1024 , V_35 ,
V_36 ) ;
F_11 ( V_2 , 1024 * 1024 , V_36 ,
V_35 ) ;
break;
case 2 :
F_11 ( V_2 , 1024 * 1024 , V_36 ,
V_36 ) ;
break;
case 3 :
for ( V_12 = 1 ; V_12 <= 65536 ; V_12 <<= 1 )
F_11 ( V_2 , V_12 * 1024 ,
V_35 ,
V_36 ) ;
break;
case 4 :
for ( V_12 = 1 ; V_12 <= 65536 ; V_12 <<= 1 )
F_11 ( V_2 , V_12 * 1024 ,
V_36 ,
V_35 ) ;
break;
case 5 :
for ( V_12 = 1 ; V_12 <= 65536 ; V_12 <<= 1 )
F_11 ( V_2 , V_12 * 1024 ,
V_36 ,
V_36 ) ;
break;
case 6 :
for ( V_12 = 1 ; V_12 < V_34 ; V_12 ++ )
F_11 ( V_2 , V_33 [ V_12 ] ,
V_35 ,
V_36 ) ;
break;
case 7 :
for ( V_12 = 1 ; V_12 < V_34 ; V_12 ++ )
F_11 ( V_2 , V_33 [ V_12 ] ,
V_36 ,
V_35 ) ;
break;
case 8 :
for ( V_12 = 1 ; V_12 < V_34 ; V_12 ++ )
F_11 ( V_2 , V_33 [ V_12 ] ,
V_36 ,
V_36 ) ;
break;
default:
F_5 ( L_7 ) ;
}
}
