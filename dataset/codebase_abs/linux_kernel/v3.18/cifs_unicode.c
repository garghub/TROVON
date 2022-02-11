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
int F_3 ( struct V_13 * V_14 )
{
int V_15 ;
if ( V_14 -> V_16 & V_17 )
V_15 = V_18 ;
else if ( V_14 -> V_16 & V_19 )
V_15 = V_20 ;
else
V_15 = V_21 ;
return V_15 ;
}
static bool
F_4 ( const T_2 V_22 , char * V_23 )
{
switch ( V_22 ) {
case V_24 :
* V_23 = ':' ;
break;
case V_25 :
* V_23 = '*' ;
break;
case V_26 :
* V_23 = '?' ;
break;
case V_27 :
* V_23 = '|' ;
break;
case V_28 :
* V_23 = '>' ;
break;
case V_29 :
* V_23 = '<' ;
break;
default:
return false ;
}
return true ;
}
static bool
F_5 ( const T_2 V_22 , char * V_23 )
{
switch ( V_22 ) {
case V_30 :
* V_23 = ':' ;
break;
case V_31 :
* V_23 = '*' ;
break;
case V_32 :
* V_23 = '?' ;
break;
case V_33 :
* V_23 = '|' ;
break;
case V_34 :
* V_23 = '>' ;
break;
case V_35 :
* V_23 = '<' ;
break;
case V_36 :
* V_23 = '\\' ;
break;
default:
return false ;
}
return true ;
}
static int
F_6 ( char * V_23 , const T_2 V_22 , const struct V_3 * V_37 ,
int V_38 )
{
int V_39 = 1 ;
if ( ( V_38 == V_18 ) && F_5 ( V_22 , V_23 ) )
return V_39 ;
else if ( ( V_38 == V_20 ) &&
F_4 ( V_22 , V_23 ) )
return V_39 ;
V_39 = V_37 -> V_12 ( V_22 , V_23 , V_10 ) ;
if ( V_39 <= 0 ) {
* V_23 = '?' ;
V_39 = 1 ;
}
return V_39 ;
}
int
F_7 ( char * V_40 , const T_1 * V_1 , int V_41 , int V_42 ,
const struct V_3 * V_4 , int V_15 )
{
int V_5 , V_6 , V_43 ;
int V_7 = 0 ;
int V_44 = F_8 ( V_4 ) ;
int V_45 = V_42 / 2 ;
char V_9 [ V_10 ] ;
T_2 V_11 ;
V_43 = V_41 - ( V_10 + V_44 ) ;
for ( V_5 = 0 ; V_5 < V_45 ; V_5 ++ ) {
V_11 = F_2 ( & V_1 [ V_5 ] ) ;
if ( V_11 == 0 )
break;
if ( V_7 >= V_43 ) {
V_6 = F_6 ( V_9 , V_11 , V_4 , V_15 ) ;
if ( ( V_7 + V_6 ) > ( V_41 - V_44 ) )
break;
}
V_6 = F_6 ( & V_40 [ V_7 ] , V_11 , V_4 , V_15 ) ;
V_7 += V_6 ;
}
for ( V_5 = 0 ; V_5 < V_44 ; V_5 ++ )
V_40 [ V_7 ++ ] = 0 ;
return V_7 ;
}
int
F_9 ( T_1 * V_40 , const char * V_1 , int V_39 ,
const struct V_3 * V_4 )
{
int V_6 ;
int V_5 ;
T_3 V_46 ;
if ( ! strcmp ( V_4 -> V_47 , L_1 ) ) {
V_5 = F_10 ( V_1 , V_39 , V_48 ,
( T_3 * ) V_40 , V_39 ) ;
if ( V_5 >= 0 )
goto V_49;
}
for ( V_5 = 0 ; V_39 && * V_1 ; V_5 ++ , V_1 += V_6 , V_39 -= V_6 ) {
V_6 = V_4 -> V_50 ( V_1 , V_39 , & V_46 ) ;
if ( V_6 < 1 ) {
F_11 ( V_51 , L_2 ,
* V_1 , V_6 ) ;
V_46 = 0x003f ;
V_6 = 1 ;
}
F_12 ( V_46 , & V_40 [ V_5 ] ) ;
}
V_49:
F_12 ( 0 , & V_40 [ V_5 ] ) ;
return V_5 ;
}
char *
F_13 ( const char * V_52 , const int V_53 ,
const bool V_54 , const struct V_3 * V_4 )
{
int V_39 ;
char * V_55 ;
if ( V_54 ) {
V_39 = F_1 ( ( T_1 * ) V_52 , V_53 , V_4 ) ;
V_39 += F_8 ( V_4 ) ;
V_55 = F_14 ( V_39 , V_56 ) ;
if ( ! V_55 )
return NULL ;
F_7 ( V_55 , ( T_1 * ) V_52 , V_39 , V_53 , V_4 ,
V_21 ) ;
} else {
V_39 = F_15 ( V_52 , V_53 ) ;
V_39 ++ ;
V_55 = F_14 ( V_39 , V_56 ) ;
if ( ! V_55 )
return NULL ;
F_16 ( V_55 , V_52 , V_39 ) ;
}
return V_55 ;
}
static T_1 F_17 ( char V_22 )
{
T_1 V_57 ;
switch ( V_22 ) {
case ':' :
V_57 = F_18 ( V_24 ) ;
break;
case '*' :
V_57 = F_18 ( V_25 ) ;
break;
case '?' :
V_57 = F_18 ( V_26 ) ;
break;
case '<' :
V_57 = F_18 ( V_29 ) ;
break;
case '>' :
V_57 = F_18 ( V_28 ) ;
break;
case '|' :
V_57 = F_18 ( V_27 ) ;
break;
default:
V_57 = 0 ;
}
return V_57 ;
}
static T_1 F_19 ( char V_22 )
{
T_1 V_57 ;
switch ( V_22 ) {
case ':' :
V_57 = F_18 ( V_30 ) ;
break;
case '*' :
V_57 = F_18 ( V_31 ) ;
break;
case '?' :
V_57 = F_18 ( V_32 ) ;
break;
case '<' :
V_57 = F_18 ( V_35 ) ;
break;
case '>' :
V_57 = F_18 ( V_34 ) ;
break;
case '|' :
V_57 = F_18 ( V_33 ) ;
break;
default:
V_57 = 0 ;
}
return V_57 ;
}
int
F_20 ( T_1 * V_23 , const char * V_58 , int V_59 ,
const struct V_3 * V_37 , int V_60 )
{
int V_5 , V_6 ;
int V_61 = 0 ;
char V_22 ;
T_1 V_62 ;
T_3 V_9 ;
if ( V_60 == V_21 )
return F_9 ( V_23 , V_58 , V_63 , V_37 ) ;
for ( V_5 = 0 ; V_5 < V_59 ; V_61 ++ ) {
V_22 = V_58 [ V_5 ] ;
V_6 = 1 ;
if ( V_22 == 0 )
goto V_64;
if ( V_60 == V_20 )
V_62 = F_17 ( V_22 ) ;
else if ( V_60 == V_18 )
V_62 = F_19 ( V_22 ) ;
else
V_62 = 0 ;
if ( V_62 == 0 ) {
V_6 = V_37 -> V_50 ( V_58 + V_5 , V_59 - V_5 , & V_9 ) ;
V_62 = F_18 ( V_9 ) ;
if ( V_6 < 1 ) {
V_62 = F_18 ( 0x003f ) ;
V_6 = 1 ;
}
}
V_5 += V_6 ;
F_21 ( V_62 , & V_23 [ V_61 ] ) ;
}
V_64:
F_21 ( 0 , & V_23 [ V_61 ] ) ;
return V_61 ;
}
static int
F_22 ( const char * V_1 , int V_39 ,
const struct V_3 * V_4 )
{
int V_6 ;
int V_5 ;
T_3 V_46 ;
for ( V_5 = 0 ; V_39 && * V_1 ; V_5 ++ , V_1 += V_6 , V_39 -= V_6 ) {
V_6 = V_4 -> V_50 ( V_1 , V_39 , & V_46 ) ;
if ( V_6 < 1 )
V_6 = 1 ;
}
return 2 * V_5 ;
}
T_1 *
F_23 ( const char * V_52 , const int V_53 , int * V_65 ,
const struct V_3 * V_37 , int V_66 )
{
int V_39 ;
T_1 * V_55 ;
V_39 = F_22 ( V_52 , V_53 , V_37 ) ;
V_39 += 2 ;
V_55 = F_14 ( V_39 , V_56 ) ;
if ( ! V_55 ) {
* V_65 = 0 ;
return NULL ;
}
F_20 ( V_55 , V_52 , strlen ( V_52 ) , V_37 , V_66 ) ;
* V_65 = V_39 ;
return V_55 ;
}
