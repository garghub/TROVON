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
case V_25 :
* V_11 = ' ' ;
break;
case V_26 :
* V_11 = '.' ;
break;
default:
return false ;
}
return true ;
}
static int
F_4 ( char * V_11 , const T_1 * V_27 , const struct V_28 * V_29 ,
int V_30 )
{
int V_31 = 1 ;
T_1 V_10 ;
V_10 = * V_27 ;
if ( ( V_30 == V_6 ) && F_3 ( V_10 , V_11 ) )
return V_31 ;
else if ( ( V_30 == V_8 ) &&
F_2 ( V_10 , V_11 ) )
return V_31 ;
V_31 = V_29 -> V_32 ( V_10 , V_11 , V_33 ) ;
if ( V_31 <= 0 )
goto V_34;
return V_31 ;
V_34:
if ( strcmp ( V_29 -> V_35 , L_1 ) )
goto V_36;
V_31 = F_5 ( V_27 , 3 , V_37 , V_11 , 6 ) ;
if ( V_31 <= 0 )
goto V_36;
return V_31 ;
V_36:
* V_11 = '?' ;
V_31 = 1 ;
return V_31 ;
}
int
F_6 ( char * V_38 , const T_2 * V_27 , int V_39 , int V_40 ,
const struct V_28 * V_41 , int V_3 )
{
int V_42 , V_43 , V_44 ;
int V_45 = 0 ;
int V_46 = F_7 ( V_41 ) ;
int V_47 = V_40 / 2 ;
char V_48 [ V_33 ] ;
T_1 V_49 [ 3 ] ;
V_44 = V_39 - ( V_33 + V_46 ) ;
for ( V_42 = 0 ; V_42 < V_47 ; V_42 ++ ) {
V_49 [ 0 ] = F_8 ( & V_27 [ V_42 ] ) ;
if ( V_49 [ 0 ] == 0 )
break;
if ( V_42 + 1 < V_47 )
V_49 [ 1 ] = F_8 ( & V_27 [ V_42 + 1 ] ) ;
else
V_49 [ 1 ] = 0 ;
if ( V_42 + 2 < V_47 )
V_49 [ 2 ] = F_8 ( & V_27 [ V_42 + 2 ] ) ;
else
V_49 [ 2 ] = 0 ;
if ( V_45 >= V_44 ) {
V_43 = F_4 ( V_48 , V_49 , V_41 , V_3 ) ;
if ( ( V_45 + V_43 ) > ( V_39 - V_46 ) )
break;
}
V_43 = F_4 ( & V_38 [ V_45 ] , V_49 , V_41 , V_3 ) ;
V_45 += V_43 ;
if ( V_43 == 4 )
V_42 ++ ;
else if ( V_43 >= 5 )
V_42 += 2 ;
}
for ( V_42 = 0 ; V_42 < V_46 ; V_42 ++ )
V_38 [ V_45 ++ ] = 0 ;
return V_45 ;
}
int
F_9 ( T_2 * V_38 , const char * V_27 , int V_31 ,
const struct V_28 * V_41 )
{
int V_43 ;
int V_42 ;
T_3 V_50 ;
if ( ! strcmp ( V_41 -> V_35 , L_1 ) ) {
V_42 = F_10 ( V_27 , V_31 , V_37 ,
( T_3 * ) V_38 , V_31 ) ;
if ( V_42 >= 0 )
goto V_51;
}
for ( V_42 = 0 ; V_31 && * V_27 ; V_42 ++ , V_27 += V_43 , V_31 -= V_43 ) {
V_43 = V_41 -> V_52 ( V_27 , V_31 , & V_50 ) ;
if ( V_43 < 1 ) {
F_11 ( V_53 , L_2 ,
* V_27 , V_43 ) ;
V_50 = 0x003f ;
V_43 = 1 ;
}
F_12 ( V_50 , & V_38 [ V_42 ] ) ;
}
V_51:
F_12 ( 0 , & V_38 [ V_42 ] ) ;
return V_42 ;
}
int
F_13 ( const T_2 * V_27 , int V_54 ,
const struct V_28 * V_41 )
{
int V_42 ;
int V_43 , V_45 = 0 ;
int V_55 = V_54 / 2 ;
char V_48 [ V_33 ] ;
T_1 V_49 [ 3 ] ;
for ( V_42 = 0 ; V_42 < V_55 ; V_42 ++ ) {
V_49 [ 0 ] = F_8 ( & V_27 [ V_42 ] ) ;
if ( V_49 [ 0 ] == 0 )
break;
if ( V_42 + 1 < V_55 )
V_49 [ 1 ] = F_8 ( & V_27 [ V_42 + 1 ] ) ;
else
V_49 [ 1 ] = 0 ;
if ( V_42 + 2 < V_55 )
V_49 [ 2 ] = F_8 ( & V_27 [ V_42 + 2 ] ) ;
else
V_49 [ 2 ] = 0 ;
V_43 = F_4 ( V_48 , V_49 , V_41 , V_9 ) ;
V_45 += V_43 ;
}
return V_45 ;
}
char *
F_14 ( const char * V_56 , const int V_57 ,
const bool V_58 , const struct V_28 * V_41 )
{
int V_31 ;
char * V_59 ;
if ( V_58 ) {
V_31 = F_13 ( ( T_2 * ) V_56 , V_57 , V_41 ) ;
V_31 += F_7 ( V_41 ) ;
V_59 = F_15 ( V_31 , V_60 ) ;
if ( ! V_59 )
return NULL ;
F_6 ( V_59 , ( T_2 * ) V_56 , V_31 , V_57 , V_41 ,
V_9 ) ;
} else {
V_31 = F_16 ( V_56 , V_57 ) ;
V_31 ++ ;
V_59 = F_15 ( V_31 , V_60 ) ;
if ( ! V_59 )
return NULL ;
F_17 ( V_59 , V_56 , V_31 ) ;
}
return V_59 ;
}
static T_2 F_18 ( char V_10 )
{
T_2 V_61 ;
switch ( V_10 ) {
case ':' :
V_61 = F_19 ( V_12 ) ;
break;
case '*' :
V_61 = F_19 ( V_13 ) ;
break;
case '?' :
V_61 = F_19 ( V_14 ) ;
break;
case '<' :
V_61 = F_19 ( V_17 ) ;
break;
case '>' :
V_61 = F_19 ( V_16 ) ;
break;
case '|' :
V_61 = F_19 ( V_15 ) ;
break;
default:
V_61 = 0 ;
}
return V_61 ;
}
static T_2 F_20 ( char V_10 , bool V_62 )
{
T_2 V_61 ;
switch ( V_10 ) {
case ':' :
V_61 = F_19 ( V_18 ) ;
break;
case '*' :
V_61 = F_19 ( V_19 ) ;
break;
case '?' :
V_61 = F_19 ( V_20 ) ;
break;
case '<' :
V_61 = F_19 ( V_23 ) ;
break;
case '>' :
V_61 = F_19 ( V_22 ) ;
break;
case '|' :
V_61 = F_19 ( V_21 ) ;
break;
case '.' :
if ( V_62 )
V_61 = F_19 ( V_26 ) ;
else
V_61 = 0 ;
break;
case ' ' :
if ( V_62 )
V_61 = F_19 ( V_25 ) ;
else
V_61 = 0 ;
break;
default:
V_61 = 0 ;
}
return V_61 ;
}
int
F_21 ( T_2 * V_11 , const char * V_63 , int V_64 ,
const struct V_28 * V_29 , int V_65 )
{
int V_42 , V_43 ;
int V_66 = 0 ;
char V_10 ;
T_2 V_67 ;
T_3 V_48 ;
T_3 * V_50 ;
int V_68 ;
T_4 V_69 ;
if ( V_65 == V_9 )
return F_9 ( V_11 , V_63 , V_70 , V_29 ) ;
V_50 = F_22 ( 6 , V_60 ) ;
for ( V_42 = 0 ; V_42 < V_64 ; V_66 ++ ) {
V_10 = V_63 [ V_42 ] ;
V_43 = 1 ;
if ( V_10 == 0 )
goto V_71;
if ( V_65 == V_8 )
V_67 = F_18 ( V_10 ) ;
else if ( V_65 == V_6 ) {
bool V_62 ;
if ( V_42 == V_64 - 1 )
V_62 = true ;
else
V_62 = false ;
V_67 = F_20 ( V_10 , V_62 ) ;
} else
V_67 = 0 ;
if ( V_67 == 0 ) {
V_43 = V_29 -> V_52 ( V_63 + V_42 , V_64 - V_42 , & V_48 ) ;
V_67 = F_19 ( V_48 ) ;
if ( V_43 > 0 )
goto V_72;
if ( strcmp ( V_29 -> V_35 , L_1 ) || ! V_50 )
goto V_36;
if ( * ( V_63 + V_42 ) & 0x80 ) {
V_43 = F_23 ( V_63 + V_42 , 6 , & V_69 ) ;
if ( V_43 < 0 )
goto V_36;
} else
goto V_36;
V_68 = F_10 ( V_63 + V_42 , V_43 ,
V_37 ,
V_50 , 6 ) ;
if ( V_68 < 0 )
goto V_36;
V_42 += V_43 ;
V_67 = F_19 ( * V_50 ) ;
if ( V_43 <= 3 )
F_24 ( V_67 , & V_11 [ V_66 ] ) ;
else if ( V_43 == 4 ) {
F_24 ( V_67 , & V_11 [ V_66 ] ) ;
V_67 = F_19 ( * ( V_50 + 1 ) ) ;
V_66 ++ ;
F_24 ( V_67 , & V_11 [ V_66 ] ) ;
} else if ( V_43 >= 5 ) {
F_24 ( V_67 , & V_11 [ V_66 ] ) ;
V_67 = F_19 ( * ( V_50 + 1 ) ) ;
V_66 ++ ;
F_24 ( V_67 , & V_11 [ V_66 ] ) ;
V_67 = F_19 ( * ( V_50 + 2 ) ) ;
V_66 ++ ;
F_24 ( V_67 , & V_11 [ V_66 ] ) ;
}
continue;
V_36:
V_67 = F_19 ( 0x003f ) ;
V_43 = 1 ;
}
V_72:
V_42 += V_43 ;
F_24 ( V_67 , & V_11 [ V_66 ] ) ;
}
V_71:
F_24 ( 0 , & V_11 [ V_66 ] ) ;
F_25 ( V_50 ) ;
return V_66 ;
}
static int
F_26 ( const char * V_27 , int V_31 ,
const struct V_28 * V_41 )
{
int V_43 ;
int V_42 ;
T_3 V_50 ;
for ( V_42 = 0 ; V_31 && * V_27 ; V_42 ++ , V_27 += V_43 , V_31 -= V_43 ) {
V_43 = V_41 -> V_52 ( V_27 , V_31 , & V_50 ) ;
if ( V_43 < 1 )
V_43 = 1 ;
}
return 2 * V_42 ;
}
T_2 *
F_27 ( const char * V_56 , const int V_57 , int * V_73 ,
const struct V_28 * V_29 , int V_74 )
{
int V_31 ;
T_2 * V_59 ;
V_31 = F_26 ( V_56 , V_57 , V_29 ) ;
V_31 += 2 ;
V_59 = F_15 ( V_31 , V_60 ) ;
if ( ! V_59 ) {
* V_73 = 0 ;
return NULL ;
}
F_21 ( V_59 , V_56 , strlen ( V_56 ) , V_29 , V_74 ) ;
* V_73 = V_31 ;
return V_59 ;
}
