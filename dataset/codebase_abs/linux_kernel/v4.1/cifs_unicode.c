int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
if ( V_2 -> V_4 & V_5 )
V_3 = V_6 ;
else if ( V_2 -> V_4 & V_7 )
V_3 = V_8 ;
else
V_3 = V_9 ;
return V_3 ;
}
static bool
F_2 ( const T_1 V_10 , char * V_11 )
{
switch ( V_10 ) {
case V_12 :
* V_11 = ':' ;
break;
case V_13 :
* V_11 = '*' ;
break;
case V_14 :
* V_11 = '?' ;
break;
case V_15 :
* V_11 = '|' ;
break;
case V_16 :
* V_11 = '>' ;
break;
case V_17 :
* V_11 = '<' ;
break;
default:
return false ;
}
return true ;
}
static bool
F_3 ( const T_1 V_10 , char * V_11 )
{
switch ( V_10 ) {
case V_18 :
* V_11 = ':' ;
break;
case V_19 :
* V_11 = '*' ;
break;
case V_20 :
* V_11 = '?' ;
break;
case V_21 :
* V_11 = '|' ;
break;
case V_22 :
* V_11 = '>' ;
break;
case V_23 :
* V_11 = '<' ;
break;
case V_24 :
* V_11 = '\\' ;
break;
default:
return false ;
}
return true ;
}
static int
F_4 ( char * V_11 , const T_1 * V_25 , const struct V_26 * V_27 ,
int V_28 )
{
int V_29 = 1 ;
T_1 V_10 ;
V_10 = * V_25 ;
if ( ( V_28 == V_6 ) && F_3 ( V_10 , V_11 ) )
return V_29 ;
else if ( ( V_28 == V_8 ) &&
F_2 ( V_10 , V_11 ) )
return V_29 ;
V_29 = V_27 -> V_30 ( V_10 , V_11 , V_31 ) ;
if ( V_29 <= 0 )
goto V_32;
return V_29 ;
V_32:
if ( strcmp ( V_27 -> V_33 , L_1 ) )
goto V_34;
V_29 = F_5 ( V_25 , 3 , V_35 , V_11 , 6 ) ;
if ( V_29 <= 0 )
goto V_34;
return V_29 ;
V_34:
* V_11 = '?' ;
V_29 = 1 ;
return V_29 ;
}
int
F_6 ( char * V_36 , const T_2 * V_25 , int V_37 , int V_38 ,
const struct V_26 * V_39 , int V_3 )
{
int V_40 , V_41 , V_42 ;
int V_43 = 0 ;
int V_44 = F_7 ( V_39 ) ;
int V_45 = V_38 / 2 ;
char V_46 [ V_31 ] ;
T_1 V_47 [ 3 ] ;
V_42 = V_37 - ( V_31 + V_44 ) ;
for ( V_40 = 0 ; V_40 < V_45 ; V_40 ++ ) {
V_47 [ 0 ] = F_8 ( & V_25 [ V_40 ] ) ;
if ( V_47 [ 0 ] == 0 )
break;
if ( V_40 + 1 < V_45 )
V_47 [ 1 ] = F_8 ( & V_25 [ V_40 + 1 ] ) ;
else
V_47 [ 1 ] = 0 ;
if ( V_40 + 2 < V_45 )
V_47 [ 2 ] = F_8 ( & V_25 [ V_40 + 2 ] ) ;
else
V_47 [ 2 ] = 0 ;
if ( V_43 >= V_42 ) {
V_41 = F_4 ( V_46 , V_47 , V_39 , V_3 ) ;
if ( ( V_43 + V_41 ) > ( V_37 - V_44 ) )
break;
}
V_41 = F_4 ( & V_36 [ V_43 ] , V_47 , V_39 , V_3 ) ;
V_43 += V_41 ;
if ( V_41 == 4 )
V_40 ++ ;
else if ( V_41 >= 5 )
V_40 += 2 ;
}
for ( V_40 = 0 ; V_40 < V_44 ; V_40 ++ )
V_36 [ V_43 ++ ] = 0 ;
return V_43 ;
}
int
F_9 ( T_2 * V_36 , const char * V_25 , int V_29 ,
const struct V_26 * V_39 )
{
int V_41 ;
int V_40 ;
T_3 V_48 ;
if ( ! strcmp ( V_39 -> V_33 , L_1 ) ) {
V_40 = F_10 ( V_25 , V_29 , V_35 ,
( T_3 * ) V_36 , V_29 ) ;
if ( V_40 >= 0 )
goto V_49;
}
for ( V_40 = 0 ; V_29 && * V_25 ; V_40 ++ , V_25 += V_41 , V_29 -= V_41 ) {
V_41 = V_39 -> V_50 ( V_25 , V_29 , & V_48 ) ;
if ( V_41 < 1 ) {
F_11 ( V_51 , L_2 ,
* V_25 , V_41 ) ;
V_48 = 0x003f ;
V_41 = 1 ;
}
F_12 ( V_48 , & V_36 [ V_40 ] ) ;
}
V_49:
F_12 ( 0 , & V_36 [ V_40 ] ) ;
return V_40 ;
}
int
F_13 ( const T_2 * V_25 , int V_52 ,
const struct V_26 * V_39 )
{
int V_40 ;
int V_41 , V_43 = 0 ;
int V_53 = V_52 / 2 ;
char V_46 [ V_31 ] ;
T_1 V_47 [ 3 ] ;
for ( V_40 = 0 ; V_40 < V_53 ; V_40 ++ ) {
V_47 [ 0 ] = F_8 ( & V_25 [ V_40 ] ) ;
if ( V_47 [ 0 ] == 0 )
break;
if ( V_40 + 1 < V_53 )
V_47 [ 1 ] = F_8 ( & V_25 [ V_40 + 1 ] ) ;
else
V_47 [ 1 ] = 0 ;
if ( V_40 + 2 < V_53 )
V_47 [ 2 ] = F_8 ( & V_25 [ V_40 + 2 ] ) ;
else
V_47 [ 2 ] = 0 ;
V_41 = F_4 ( V_46 , V_47 , V_39 , V_9 ) ;
V_43 += V_41 ;
}
return V_43 ;
}
char *
F_14 ( const char * V_54 , const int V_55 ,
const bool V_56 , const struct V_26 * V_39 )
{
int V_29 ;
char * V_57 ;
if ( V_56 ) {
V_29 = F_13 ( ( T_2 * ) V_54 , V_55 , V_39 ) ;
V_29 += F_7 ( V_39 ) ;
V_57 = F_15 ( V_29 , V_58 ) ;
if ( ! V_57 )
return NULL ;
F_6 ( V_57 , ( T_2 * ) V_54 , V_29 , V_55 , V_39 ,
V_9 ) ;
} else {
V_29 = F_16 ( V_54 , V_55 ) ;
V_29 ++ ;
V_57 = F_15 ( V_29 , V_58 ) ;
if ( ! V_57 )
return NULL ;
F_17 ( V_57 , V_54 , V_29 ) ;
}
return V_57 ;
}
static T_2 F_18 ( char V_10 )
{
T_2 V_59 ;
switch ( V_10 ) {
case ':' :
V_59 = F_19 ( V_12 ) ;
break;
case '*' :
V_59 = F_19 ( V_13 ) ;
break;
case '?' :
V_59 = F_19 ( V_14 ) ;
break;
case '<' :
V_59 = F_19 ( V_17 ) ;
break;
case '>' :
V_59 = F_19 ( V_16 ) ;
break;
case '|' :
V_59 = F_19 ( V_15 ) ;
break;
default:
V_59 = 0 ;
}
return V_59 ;
}
static T_2 F_20 ( char V_10 )
{
T_2 V_59 ;
switch ( V_10 ) {
case ':' :
V_59 = F_19 ( V_18 ) ;
break;
case '*' :
V_59 = F_19 ( V_19 ) ;
break;
case '?' :
V_59 = F_19 ( V_20 ) ;
break;
case '<' :
V_59 = F_19 ( V_23 ) ;
break;
case '>' :
V_59 = F_19 ( V_22 ) ;
break;
case '|' :
V_59 = F_19 ( V_21 ) ;
break;
default:
V_59 = 0 ;
}
return V_59 ;
}
int
F_21 ( T_2 * V_11 , const char * V_60 , int V_61 ,
const struct V_26 * V_27 , int V_62 )
{
int V_40 , V_41 ;
int V_63 = 0 ;
char V_10 ;
T_2 V_64 ;
T_3 V_46 ;
T_3 * V_48 ;
int V_65 ;
T_4 V_66 ;
if ( V_62 == V_9 )
return F_9 ( V_11 , V_60 , V_67 , V_27 ) ;
V_48 = F_22 ( 6 , V_58 ) ;
for ( V_40 = 0 ; V_40 < V_61 ; V_63 ++ ) {
V_10 = V_60 [ V_40 ] ;
V_41 = 1 ;
if ( V_10 == 0 )
goto V_68;
if ( V_62 == V_8 )
V_64 = F_18 ( V_10 ) ;
else if ( V_62 == V_6 )
V_64 = F_20 ( V_10 ) ;
else
V_64 = 0 ;
if ( V_64 == 0 ) {
V_41 = V_27 -> V_50 ( V_60 + V_40 , V_61 - V_40 , & V_46 ) ;
V_64 = F_19 ( V_46 ) ;
if ( V_41 > 0 )
goto V_69;
if ( strcmp ( V_27 -> V_33 , L_1 ) || ! V_48 )
goto V_34;
if ( * ( V_60 + V_40 ) & 0x80 ) {
V_41 = F_23 ( V_60 + V_40 , 6 , & V_66 ) ;
if ( V_41 < 0 )
goto V_34;
} else
goto V_34;
V_65 = F_10 ( V_60 + V_40 , V_41 ,
V_35 ,
V_48 , 6 ) ;
if ( V_65 < 0 )
goto V_34;
V_40 += V_41 ;
V_64 = F_19 ( * V_48 ) ;
if ( V_41 <= 3 )
F_24 ( V_64 , & V_11 [ V_63 ] ) ;
else if ( V_41 == 4 ) {
F_24 ( V_64 , & V_11 [ V_63 ] ) ;
V_64 = F_19 ( * ( V_48 + 1 ) ) ;
V_63 ++ ;
F_24 ( V_64 , & V_11 [ V_63 ] ) ;
} else if ( V_41 >= 5 ) {
F_24 ( V_64 , & V_11 [ V_63 ] ) ;
V_64 = F_19 ( * ( V_48 + 1 ) ) ;
V_63 ++ ;
F_24 ( V_64 , & V_11 [ V_63 ] ) ;
V_64 = F_19 ( * ( V_48 + 2 ) ) ;
V_63 ++ ;
F_24 ( V_64 , & V_11 [ V_63 ] ) ;
}
continue;
V_34:
V_64 = F_19 ( 0x003f ) ;
V_41 = 1 ;
}
V_69:
V_40 += V_41 ;
F_24 ( V_64 , & V_11 [ V_63 ] ) ;
}
V_68:
F_24 ( 0 , & V_11 [ V_63 ] ) ;
F_25 ( V_48 ) ;
return V_63 ;
}
static int
F_26 ( const char * V_25 , int V_29 ,
const struct V_26 * V_39 )
{
int V_41 ;
int V_40 ;
T_3 V_48 ;
for ( V_40 = 0 ; V_29 && * V_25 ; V_40 ++ , V_25 += V_41 , V_29 -= V_41 ) {
V_41 = V_39 -> V_50 ( V_25 , V_29 , & V_48 ) ;
if ( V_41 < 1 )
V_41 = 1 ;
}
return 2 * V_40 ;
}
T_2 *
F_27 ( const char * V_54 , const int V_55 , int * V_70 ,
const struct V_26 * V_27 , int V_71 )
{
int V_29 ;
T_2 * V_57 ;
V_29 = F_26 ( V_54 , V_55 , V_27 ) ;
V_29 += 2 ;
V_57 = F_15 ( V_29 , V_58 ) ;
if ( ! V_57 ) {
* V_70 = 0 ;
return NULL ;
}
F_21 ( V_57 , V_54 , strlen ( V_54 ) , V_27 , V_71 ) ;
* V_70 = V_29 ;
return V_57 ;
}
