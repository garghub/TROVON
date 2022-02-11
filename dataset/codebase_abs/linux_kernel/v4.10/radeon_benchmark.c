static int F_1 ( struct V_1 * V_2 , unsigned V_3 ,
T_1 V_4 , T_1 V_5 ,
int V_6 , int V_7 ,
struct V_8 * V_9 )
{
unsigned long V_10 ;
unsigned long V_11 ;
struct V_12 * V_13 = NULL ;
int V_14 , V_15 ;
V_10 = V_16 ;
for ( V_14 = 0 ; V_14 < V_7 ; V_14 ++ ) {
switch ( V_6 ) {
case V_17 :
V_13 = F_2 ( V_2 , V_4 , V_5 ,
V_3 / V_18 ,
V_9 ) ;
break;
case V_19 :
V_13 = F_3 ( V_2 , V_4 , V_5 ,
V_3 / V_18 ,
V_9 ) ;
break;
default:
F_4 ( L_1 ) ;
return - V_20 ;
}
if ( F_5 ( V_13 ) )
return F_6 ( V_13 ) ;
V_15 = F_7 ( V_13 , false ) ;
F_8 ( & V_13 ) ;
if ( V_15 )
return V_15 ;
}
V_11 = V_16 ;
return F_9 ( V_11 - V_10 ) ;
}
static void F_10 ( int V_7 , unsigned V_3 ,
unsigned int time ,
unsigned V_21 , unsigned V_22 ,
char * V_23 )
{
unsigned int V_24 = ( V_7 * ( V_3 >> 10 ) ) / time ;
F_11 ( L_2
L_3 ,
V_23 , V_7 , V_3 >> 10 , V_21 , V_22 , time ,
V_24 * 8 , V_24 ) ;
}
static void F_12 ( struct V_1 * V_2 , unsigned V_3 ,
unsigned V_21 , unsigned V_22 )
{
struct V_25 * V_26 = NULL ;
struct V_25 * V_27 = NULL ;
T_1 V_4 , V_5 ;
int V_15 , V_7 ;
int time ;
V_7 = V_28 ;
V_15 = F_13 ( V_2 , V_3 , V_29 , true , V_21 , 0 , NULL , NULL , & V_27 ) ;
if ( V_15 ) {
goto V_30;
}
V_15 = F_14 ( V_27 , false ) ;
if ( F_15 ( V_15 != 0 ) )
goto V_30;
V_15 = F_16 ( V_27 , V_21 , & V_4 ) ;
F_17 ( V_27 ) ;
if ( V_15 ) {
goto V_30;
}
V_15 = F_13 ( V_2 , V_3 , V_29 , true , V_22 , 0 , NULL , NULL , & V_26 ) ;
if ( V_15 ) {
goto V_30;
}
V_15 = F_14 ( V_26 , false ) ;
if ( F_15 ( V_15 != 0 ) )
goto V_30;
V_15 = F_16 ( V_26 , V_22 , & V_5 ) ;
F_17 ( V_26 ) ;
if ( V_15 ) {
goto V_30;
}
if ( V_2 -> V_31 -> V_32 . V_33 ) {
time = F_1 ( V_2 , V_3 , V_4 , V_5 ,
V_17 , V_7 ,
V_26 -> V_34 . V_9 ) ;
if ( time < 0 )
goto V_30;
if ( time > 0 )
F_10 ( V_7 , V_3 , time ,
V_21 , V_22 , L_4 ) ;
}
if ( V_2 -> V_31 -> V_32 . V_35 ) {
time = F_1 ( V_2 , V_3 , V_4 , V_5 ,
V_19 , V_7 ,
V_26 -> V_34 . V_9 ) ;
if ( time < 0 )
goto V_30;
if ( time > 0 )
F_10 ( V_7 , V_3 , time ,
V_21 , V_22 , L_5 ) ;
}
V_30:
if ( V_27 ) {
V_15 = F_14 ( V_27 , false ) ;
if ( F_18 ( V_15 == 0 ) ) {
F_19 ( V_27 ) ;
F_17 ( V_27 ) ;
}
F_20 ( & V_27 ) ;
}
if ( V_26 ) {
V_15 = F_14 ( V_26 , false ) ;
if ( F_18 ( V_15 == 0 ) ) {
F_19 ( V_26 ) ;
F_17 ( V_26 ) ;
}
F_20 ( & V_26 ) ;
}
if ( V_15 ) {
F_4 ( L_6 ) ;
}
}
void F_21 ( struct V_1 * V_2 , int V_36 )
{
int V_14 ;
int V_37 [ V_38 ] = {
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
switch ( V_36 ) {
case 1 :
F_12 ( V_2 , 1024 * 1024 , V_39 ,
V_40 ) ;
F_12 ( V_2 , 1024 * 1024 , V_40 ,
V_39 ) ;
break;
case 2 :
F_12 ( V_2 , 1024 * 1024 , V_40 ,
V_40 ) ;
break;
case 3 :
for ( V_14 = 1 ; V_14 <= 16384 ; V_14 <<= 1 )
F_12 ( V_2 , V_14 * V_18 ,
V_39 ,
V_40 ) ;
break;
case 4 :
for ( V_14 = 1 ; V_14 <= 16384 ; V_14 <<= 1 )
F_12 ( V_2 , V_14 * V_18 ,
V_40 ,
V_39 ) ;
break;
case 5 :
for ( V_14 = 1 ; V_14 <= 16384 ; V_14 <<= 1 )
F_12 ( V_2 , V_14 * V_18 ,
V_40 ,
V_40 ) ;
break;
case 6 :
for ( V_14 = 0 ; V_14 < V_38 ; V_14 ++ )
F_12 ( V_2 , V_37 [ V_14 ] ,
V_39 ,
V_40 ) ;
break;
case 7 :
for ( V_14 = 0 ; V_14 < V_38 ; V_14 ++ )
F_12 ( V_2 , V_37 [ V_14 ] ,
V_40 ,
V_39 ) ;
break;
case 8 :
for ( V_14 = 0 ; V_14 < V_38 ; V_14 ++ )
F_12 ( V_2 , V_37 [ V_14 ] ,
V_40 ,
V_40 ) ;
break;
default:
F_4 ( L_7 ) ;
}
}
