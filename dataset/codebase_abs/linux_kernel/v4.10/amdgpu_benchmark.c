static int F_1 ( struct V_1 * V_2 , unsigned V_3 ,
T_1 V_4 , T_1 V_5 , int V_6 )
{
unsigned long V_7 ;
unsigned long V_8 ;
struct V_9 * V_10 = NULL ;
int V_11 , V_12 ;
V_7 = V_13 ;
for ( V_11 = 0 ; V_11 < V_6 ; V_11 ++ ) {
struct V_14 * V_15 = V_2 -> V_16 . V_17 ;
V_12 = F_2 ( V_15 , V_4 , V_5 , V_3 , NULL , & V_10 ,
false ) ;
if ( V_12 )
goto V_18;
V_12 = F_3 ( V_10 , false ) ;
if ( V_12 )
goto V_18;
F_4 ( V_10 ) ;
}
V_8 = V_13 ;
V_12 = F_5 ( V_8 - V_7 ) ;
V_18:
if ( V_10 )
F_4 ( V_10 ) ;
return V_12 ;
}
static void F_6 ( int V_6 , unsigned V_3 ,
unsigned int time ,
unsigned V_19 , unsigned V_20 ,
char * V_21 )
{
unsigned int V_22 = ( V_6 * ( V_3 >> 10 ) ) / time ;
F_7 ( L_1
L_2 ,
V_21 , V_6 , V_3 >> 10 , V_19 , V_20 , time ,
V_22 * 8 , V_22 ) ;
}
static void F_8 ( struct V_1 * V_2 , unsigned V_3 ,
unsigned V_19 , unsigned V_20 )
{
struct V_23 * V_24 = NULL ;
struct V_23 * V_25 = NULL ;
T_1 V_4 , V_5 ;
int V_12 , V_6 ;
int time ;
V_6 = V_26 ;
V_12 = F_9 ( V_2 , V_3 , V_27 , true , V_19 , 0 , NULL ,
NULL , & V_25 ) ;
if ( V_12 ) {
goto V_28;
}
V_12 = F_10 ( V_25 , false ) ;
if ( F_11 ( V_12 != 0 ) )
goto V_28;
V_12 = F_12 ( V_25 , V_19 , & V_4 ) ;
F_13 ( V_25 ) ;
if ( V_12 ) {
goto V_28;
}
V_12 = F_9 ( V_2 , V_3 , V_27 , true , V_20 , 0 , NULL ,
NULL , & V_24 ) ;
if ( V_12 ) {
goto V_28;
}
V_12 = F_10 ( V_24 , false ) ;
if ( F_11 ( V_12 != 0 ) )
goto V_28;
V_12 = F_12 ( V_24 , V_20 , & V_5 ) ;
F_13 ( V_24 ) ;
if ( V_12 ) {
goto V_28;
}
if ( V_2 -> V_16 . V_29 ) {
time = F_1 ( V_2 , V_3 , V_4 , V_5 , V_6 ) ;
if ( time < 0 )
goto V_28;
if ( time > 0 )
F_6 ( V_6 , V_3 , time ,
V_19 , V_20 , L_3 ) ;
}
V_28:
if ( V_25 ) {
V_12 = F_10 ( V_25 , false ) ;
if ( F_14 ( V_12 == 0 ) ) {
F_15 ( V_25 ) ;
F_13 ( V_25 ) ;
}
F_16 ( & V_25 ) ;
}
if ( V_24 ) {
V_12 = F_10 ( V_24 , false ) ;
if ( F_14 ( V_12 == 0 ) ) {
F_15 ( V_24 ) ;
F_13 ( V_24 ) ;
}
F_16 ( & V_24 ) ;
}
if ( V_12 ) {
F_17 ( L_4 ) ;
}
}
void F_18 ( struct V_1 * V_2 , int V_30 )
{
int V_11 ;
static const int V_31 [ V_32 ] = {
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
switch ( V_30 ) {
case 1 :
F_8 ( V_2 , 1024 * 1024 , V_33 ,
V_34 ) ;
F_8 ( V_2 , 1024 * 1024 , V_34 ,
V_33 ) ;
break;
case 2 :
F_8 ( V_2 , 1024 * 1024 , V_34 ,
V_34 ) ;
break;
case 3 :
for ( V_11 = 1 ; V_11 <= 16384 ; V_11 <<= 1 )
F_8 ( V_2 , V_11 * V_35 ,
V_33 ,
V_34 ) ;
break;
case 4 :
for ( V_11 = 1 ; V_11 <= 16384 ; V_11 <<= 1 )
F_8 ( V_2 , V_11 * V_35 ,
V_34 ,
V_33 ) ;
break;
case 5 :
for ( V_11 = 1 ; V_11 <= 16384 ; V_11 <<= 1 )
F_8 ( V_2 , V_11 * V_35 ,
V_34 ,
V_34 ) ;
break;
case 6 :
for ( V_11 = 0 ; V_11 < V_32 ; V_11 ++ )
F_8 ( V_2 , V_31 [ V_11 ] ,
V_33 ,
V_34 ) ;
break;
case 7 :
for ( V_11 = 0 ; V_11 < V_32 ; V_11 ++ )
F_8 ( V_2 , V_31 [ V_11 ] ,
V_34 ,
V_33 ) ;
break;
case 8 :
for ( V_11 = 0 ; V_11 < V_32 ; V_11 ++ )
F_8 ( V_2 , V_31 [ V_11 ] ,
V_34 ,
V_34 ) ;
break;
default:
F_17 ( L_5 ) ;
}
}
