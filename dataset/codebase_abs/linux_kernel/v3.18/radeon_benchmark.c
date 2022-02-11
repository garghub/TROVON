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
switch ( V_6 ) {
case V_15 :
V_11 = F_2 ( V_2 , V_4 , V_5 ,
V_3 / V_16 ,
NULL ) ;
break;
case V_17 :
V_11 = F_3 ( V_2 , V_4 , V_5 ,
V_3 / V_16 ,
NULL ) ;
break;
default:
F_4 ( L_1 ) ;
return - V_18 ;
}
if ( F_5 ( V_11 ) )
return F_6 ( V_11 ) ;
V_13 = F_7 ( V_11 , false ) ;
F_8 ( & V_11 ) ;
if ( V_13 )
return V_13 ;
}
V_9 = V_14 ;
return F_9 ( V_9 - V_8 ) ;
}
static void F_10 ( int V_7 , unsigned V_3 ,
unsigned int time ,
unsigned V_19 , unsigned V_20 ,
char * V_21 )
{
unsigned int V_22 = ( V_7 * ( V_3 >> 10 ) ) / time ;
F_11 ( L_2
L_3 ,
V_21 , V_7 , V_3 >> 10 , V_19 , V_20 , time ,
V_22 * 8 , V_22 ) ;
}
static void F_12 ( struct V_1 * V_2 , unsigned V_3 ,
unsigned V_19 , unsigned V_20 )
{
struct V_23 * V_24 = NULL ;
struct V_23 * V_25 = NULL ;
T_1 V_4 , V_5 ;
int V_13 , V_7 ;
int time ;
V_7 = V_26 ;
V_13 = F_13 ( V_2 , V_3 , V_27 , true , V_19 , 0 , NULL , NULL , & V_25 ) ;
if ( V_13 ) {
goto V_28;
}
V_13 = F_14 ( V_25 , false ) ;
if ( F_15 ( V_13 != 0 ) )
goto V_28;
V_13 = F_16 ( V_25 , V_19 , & V_4 ) ;
F_17 ( V_25 ) ;
if ( V_13 ) {
goto V_28;
}
V_13 = F_13 ( V_2 , V_3 , V_27 , true , V_20 , 0 , NULL , NULL , & V_24 ) ;
if ( V_13 ) {
goto V_28;
}
V_13 = F_14 ( V_24 , false ) ;
if ( F_15 ( V_13 != 0 ) )
goto V_28;
V_13 = F_16 ( V_24 , V_20 , & V_5 ) ;
F_17 ( V_24 ) ;
if ( V_13 ) {
goto V_28;
}
if ( V_2 -> V_29 -> V_30 . V_31 ) {
time = F_1 ( V_2 , V_3 , V_4 , V_5 ,
V_15 , V_7 ) ;
if ( time < 0 )
goto V_28;
if ( time > 0 )
F_10 ( V_7 , V_3 , time ,
V_19 , V_20 , L_4 ) ;
}
if ( V_2 -> V_29 -> V_30 . V_32 ) {
time = F_1 ( V_2 , V_3 , V_4 , V_5 ,
V_17 , V_7 ) ;
if ( time < 0 )
goto V_28;
if ( time > 0 )
F_10 ( V_7 , V_3 , time ,
V_19 , V_20 , L_5 ) ;
}
V_28:
if ( V_25 ) {
V_13 = F_14 ( V_25 , false ) ;
if ( F_18 ( V_13 == 0 ) ) {
F_19 ( V_25 ) ;
F_17 ( V_25 ) ;
}
F_20 ( & V_25 ) ;
}
if ( V_24 ) {
V_13 = F_14 ( V_24 , false ) ;
if ( F_18 ( V_13 == 0 ) ) {
F_19 ( V_24 ) ;
F_17 ( V_24 ) ;
}
F_20 ( & V_24 ) ;
}
if ( V_13 ) {
F_4 ( L_6 ) ;
}
}
void F_21 ( struct V_1 * V_2 , int V_33 )
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
F_12 ( V_2 , 1024 * 1024 , V_36 ,
V_37 ) ;
F_12 ( V_2 , 1024 * 1024 , V_37 ,
V_36 ) ;
break;
case 2 :
F_12 ( V_2 , 1024 * 1024 , V_37 ,
V_37 ) ;
break;
case 3 :
for ( V_12 = 1 ; V_12 <= 16384 ; V_12 <<= 1 )
F_12 ( V_2 , V_12 * V_16 ,
V_36 ,
V_37 ) ;
break;
case 4 :
for ( V_12 = 1 ; V_12 <= 16384 ; V_12 <<= 1 )
F_12 ( V_2 , V_12 * V_16 ,
V_37 ,
V_36 ) ;
break;
case 5 :
for ( V_12 = 1 ; V_12 <= 16384 ; V_12 <<= 1 )
F_12 ( V_2 , V_12 * V_16 ,
V_37 ,
V_37 ) ;
break;
case 6 :
for ( V_12 = 0 ; V_12 < V_35 ; V_12 ++ )
F_12 ( V_2 , V_34 [ V_12 ] ,
V_36 ,
V_37 ) ;
break;
case 7 :
for ( V_12 = 0 ; V_12 < V_35 ; V_12 ++ )
F_12 ( V_2 , V_34 [ V_12 ] ,
V_37 ,
V_36 ) ;
break;
case 8 :
for ( V_12 = 0 ; V_12 < V_35 ; V_12 ++ )
F_12 ( V_2 , V_34 [ V_12 ] ,
V_37 ,
V_37 ) ;
break;
default:
F_4 ( L_7 ) ;
}
}
