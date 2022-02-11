int
F_1 ( const T_1 * V_1 , int V_2 ,
const struct V_3 * V_4 )
{
int V_5 ;
int V_6 , V_7 = 0 ;
int V_8 = V_2 / 2 ;
char V_9 [ V_10 ] ;
T_2 V_11 ;
for ( V_5 = 0 ; V_5 < V_8 ; V_5 ++ ) {
V_11 = F_2 ( & V_1 [ V_5 ] ) ;
if ( V_11 == 0 )
break;
V_6 = V_4 -> V_12 ( V_11 , V_9 , V_10 ) ;
if ( V_6 > 0 )
V_7 += V_6 ;
else
V_7 ++ ;
}
return V_7 ;
}
static int
F_3 ( char * V_13 , const T_2 V_14 , const struct V_3 * V_15 ,
bool V_16 )
{
int V_17 = 1 ;
if ( ! V_16 )
goto V_18;
switch ( V_14 ) {
case V_19 :
* V_13 = ':' ;
break;
case V_20 :
* V_13 = '*' ;
break;
case V_21 :
* V_13 = '?' ;
break;
case V_22 :
* V_13 = '|' ;
break;
case V_23 :
* V_13 = '>' ;
break;
case V_24 :
* V_13 = '<' ;
break;
default:
goto V_18;
}
V_25:
return V_17 ;
V_18:
V_17 = V_15 -> V_12 ( V_14 , V_13 , V_10 ) ;
if ( V_17 <= 0 ) {
* V_13 = '?' ;
V_17 = 1 ;
}
goto V_25;
}
int
F_4 ( char * V_26 , const T_1 * V_1 , int V_27 , int V_28 ,
const struct V_3 * V_4 , bool V_16 )
{
int V_5 , V_6 , V_29 ;
int V_7 = 0 ;
int V_30 = F_5 ( V_4 ) ;
int V_31 = V_28 / 2 ;
char V_9 [ V_10 ] ;
T_2 V_11 ;
V_29 = V_27 - ( V_10 + V_30 ) ;
for ( V_5 = 0 ; V_5 < V_31 ; V_5 ++ ) {
V_11 = F_2 ( & V_1 [ V_5 ] ) ;
if ( V_11 == 0 )
break;
if ( V_7 >= V_29 ) {
V_6 = F_3 ( V_9 , V_11 , V_4 , V_16 ) ;
if ( ( V_7 + V_6 ) > ( V_27 - V_30 ) )
break;
}
V_6 = F_3 ( & V_26 [ V_7 ] , V_11 , V_4 , V_16 ) ;
V_7 += V_6 ;
}
for ( V_5 = 0 ; V_5 < V_30 ; V_5 ++ )
V_26 [ V_7 ++ ] = 0 ;
return V_7 ;
}
int
F_6 ( T_1 * V_26 , const char * V_1 , int V_17 ,
const struct V_3 * V_4 )
{
int V_6 ;
int V_5 ;
T_3 V_32 ;
for ( V_5 = 0 ; V_17 && * V_1 ; V_5 ++ , V_1 += V_6 , V_17 -= V_6 ) {
V_6 = V_4 -> V_33 ( V_1 , V_17 , & V_32 ) ;
if ( V_6 < 1 ) {
F_7 ( 1 , L_1 ,
* V_1 , V_6 ) ;
V_32 = 0x003f ;
V_6 = 1 ;
}
F_8 ( V_32 , & V_26 [ V_5 ] ) ;
}
F_8 ( 0 , & V_26 [ V_5 ] ) ;
return V_5 ;
}
char *
F_9 ( const char * V_34 , const int V_35 ,
const bool V_36 , const struct V_3 * V_4 )
{
int V_17 ;
char * V_37 ;
if ( V_36 ) {
V_17 = F_1 ( ( T_1 * ) V_34 , V_35 , V_4 ) ;
V_17 += F_5 ( V_4 ) ;
V_37 = F_10 ( V_17 , V_38 ) ;
if ( ! V_37 )
return NULL ;
F_4 ( V_37 , ( T_1 * ) V_34 , V_17 , V_35 , V_4 ,
false ) ;
} else {
V_17 = F_11 ( V_34 , V_35 ) ;
V_17 ++ ;
V_37 = F_10 ( V_17 , V_38 ) ;
if ( ! V_37 )
return NULL ;
F_12 ( V_37 , V_34 , V_17 ) ;
}
return V_37 ;
}
int
F_13 ( T_1 * V_13 , const char * V_39 , int V_40 ,
const struct V_3 * V_15 , int V_41 )
{
int V_5 , V_42 , V_6 ;
char V_14 ;
T_1 V_43 ;
T_3 V_9 ;
if ( ! V_41 )
return F_6 ( V_13 , V_39 , V_44 , V_15 ) ;
for ( V_5 = 0 , V_42 = 0 ; V_5 < V_40 ; V_42 ++ ) {
V_14 = V_39 [ V_5 ] ;
V_6 = 1 ;
switch ( V_14 ) {
case 0 :
F_14 ( 0 , & V_13 [ V_42 ] ) ;
goto V_45;
case ':' :
V_43 = F_15 ( V_19 ) ;
break;
case '*' :
V_43 = F_15 ( V_20 ) ;
break;
case '?' :
V_43 = F_15 ( V_21 ) ;
break;
case '<' :
V_43 = F_15 ( V_24 ) ;
break;
case '>' :
V_43 = F_15 ( V_23 ) ;
break;
case '|' :
V_43 = F_15 ( V_22 ) ;
break;
default:
V_6 = V_15 -> V_33 ( V_39 + V_5 , V_40 - V_5 , & V_9 ) ;
V_43 = F_15 ( V_9 ) ;
if ( V_6 < 1 ) {
V_43 = F_15 ( 0x003f ) ;
V_6 = 1 ;
}
}
V_5 += V_6 ;
F_14 ( V_43 , & V_13 [ V_42 ] ) ;
}
V_45:
return V_5 ;
}
