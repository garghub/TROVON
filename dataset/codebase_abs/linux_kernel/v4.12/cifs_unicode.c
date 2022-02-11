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
* V_11 = '"' ;
break;
case V_20 :
* V_11 = '*' ;
break;
case V_21 :
* V_11 = '?' ;
break;
case V_22 :
* V_11 = '|' ;
break;
case V_23 :
* V_11 = '>' ;
break;
case V_24 :
* V_11 = '<' ;
break;
case V_25 :
* V_11 = '\\' ;
break;
case V_26 :
* V_11 = ' ' ;
break;
case V_27 :
* V_11 = '.' ;
break;
default:
return false ;
}
return true ;
}
static int
F_4 ( char * V_11 , const T_1 * V_28 , const struct V_29 * V_30 ,
int V_31 )
{
int V_32 = 1 ;
T_1 V_10 ;
V_10 = * V_28 ;
if ( ( V_31 == V_6 ) && F_3 ( V_10 , V_11 ) )
return V_32 ;
else if ( ( V_31 == V_8 ) &&
F_2 ( V_10 , V_11 ) )
return V_32 ;
V_32 = V_30 -> V_33 ( V_10 , V_11 , V_34 ) ;
if ( V_32 <= 0 )
goto V_35;
return V_32 ;
V_35:
if ( strcmp ( V_30 -> V_36 , L_1 ) )
goto V_37;
V_32 = F_5 ( V_28 , 3 , V_38 , V_11 , 6 ) ;
if ( V_32 <= 0 )
goto V_37;
return V_32 ;
V_37:
* V_11 = '?' ;
V_32 = 1 ;
return V_32 ;
}
int
F_6 ( char * V_39 , const T_2 * V_28 , int V_40 , int V_41 ,
const struct V_29 * V_42 , int V_3 )
{
int V_43 , V_44 , V_45 ;
int V_46 = 0 ;
int V_47 = F_7 ( V_42 ) ;
int V_48 = V_41 / 2 ;
char V_49 [ V_34 ] ;
T_1 V_50 [ 3 ] ;
V_45 = V_40 - ( V_34 + V_47 ) ;
for ( V_43 = 0 ; V_43 < V_48 ; V_43 ++ ) {
V_50 [ 0 ] = F_8 ( & V_28 [ V_43 ] ) ;
if ( V_50 [ 0 ] == 0 )
break;
if ( V_43 + 1 < V_48 )
V_50 [ 1 ] = F_8 ( & V_28 [ V_43 + 1 ] ) ;
else
V_50 [ 1 ] = 0 ;
if ( V_43 + 2 < V_48 )
V_50 [ 2 ] = F_8 ( & V_28 [ V_43 + 2 ] ) ;
else
V_50 [ 2 ] = 0 ;
if ( V_46 >= V_45 ) {
V_44 = F_4 ( V_49 , V_50 , V_42 , V_3 ) ;
if ( ( V_46 + V_44 ) > ( V_40 - V_47 ) )
break;
}
V_44 = F_4 ( & V_39 [ V_46 ] , V_50 , V_42 , V_3 ) ;
V_46 += V_44 ;
if ( V_44 == 4 )
V_43 ++ ;
else if ( V_44 >= 5 )
V_43 += 2 ;
}
for ( V_43 = 0 ; V_43 < V_47 ; V_43 ++ )
V_39 [ V_46 ++ ] = 0 ;
return V_46 ;
}
int
F_9 ( T_2 * V_39 , const char * V_28 , int V_32 ,
const struct V_29 * V_42 )
{
int V_44 ;
int V_43 ;
T_3 V_51 ;
if ( ! strcmp ( V_42 -> V_36 , L_1 ) ) {
V_43 = F_10 ( V_28 , V_32 , V_38 ,
( T_3 * ) V_39 , V_32 ) ;
if ( V_43 >= 0 )
goto V_52;
}
for ( V_43 = 0 ; V_32 && * V_28 ; V_43 ++ , V_28 += V_44 , V_32 -= V_44 ) {
V_44 = V_42 -> V_53 ( V_28 , V_32 , & V_51 ) ;
if ( V_44 < 1 ) {
F_11 ( V_54 , L_2 ,
* V_28 , V_44 ) ;
V_51 = 0x003f ;
V_44 = 1 ;
}
F_12 ( V_51 , & V_39 [ V_43 ] ) ;
}
V_52:
F_12 ( 0 , & V_39 [ V_43 ] ) ;
return V_43 ;
}
int
F_13 ( const T_2 * V_28 , int V_55 ,
const struct V_29 * V_42 )
{
int V_43 ;
int V_44 , V_46 = 0 ;
int V_56 = V_55 / 2 ;
char V_49 [ V_34 ] ;
T_1 V_50 [ 3 ] ;
for ( V_43 = 0 ; V_43 < V_56 ; V_43 ++ ) {
V_50 [ 0 ] = F_8 ( & V_28 [ V_43 ] ) ;
if ( V_50 [ 0 ] == 0 )
break;
if ( V_43 + 1 < V_56 )
V_50 [ 1 ] = F_8 ( & V_28 [ V_43 + 1 ] ) ;
else
V_50 [ 1 ] = 0 ;
if ( V_43 + 2 < V_56 )
V_50 [ 2 ] = F_8 ( & V_28 [ V_43 + 2 ] ) ;
else
V_50 [ 2 ] = 0 ;
V_44 = F_4 ( V_49 , V_50 , V_42 , V_9 ) ;
V_46 += V_44 ;
}
return V_46 ;
}
char *
F_14 ( const char * V_57 , const int V_58 ,
const bool V_59 , const struct V_29 * V_42 )
{
int V_32 ;
char * V_60 ;
if ( V_59 ) {
V_32 = F_13 ( ( T_2 * ) V_57 , V_58 , V_42 ) ;
V_32 += F_7 ( V_42 ) ;
V_60 = F_15 ( V_32 , V_61 ) ;
if ( ! V_60 )
return NULL ;
F_6 ( V_60 , ( T_2 * ) V_57 , V_32 , V_58 , V_42 ,
V_9 ) ;
} else {
V_32 = F_16 ( V_57 , V_58 ) ;
V_32 ++ ;
V_60 = F_15 ( V_32 , V_61 ) ;
if ( ! V_60 )
return NULL ;
F_17 ( V_60 , V_57 , V_32 ) ;
}
return V_60 ;
}
static T_2 F_18 ( char V_10 )
{
T_2 V_62 ;
switch ( V_10 ) {
case ':' :
V_62 = F_19 ( V_12 ) ;
break;
case '*' :
V_62 = F_19 ( V_13 ) ;
break;
case '?' :
V_62 = F_19 ( V_14 ) ;
break;
case '<' :
V_62 = F_19 ( V_17 ) ;
break;
case '>' :
V_62 = F_19 ( V_16 ) ;
break;
case '|' :
V_62 = F_19 ( V_15 ) ;
break;
default:
V_62 = 0 ;
}
return V_62 ;
}
static T_2 F_20 ( char V_10 , bool V_63 )
{
T_2 V_62 ;
switch ( V_10 ) {
case ':' :
V_62 = F_19 ( V_18 ) ;
break;
case '"' :
V_62 = F_19 ( V_19 ) ;
break;
case '*' :
V_62 = F_19 ( V_20 ) ;
break;
case '?' :
V_62 = F_19 ( V_21 ) ;
break;
case '<' :
V_62 = F_19 ( V_24 ) ;
break;
case '>' :
V_62 = F_19 ( V_23 ) ;
break;
case '|' :
V_62 = F_19 ( V_22 ) ;
break;
case '.' :
if ( V_63 )
V_62 = F_19 ( V_27 ) ;
else
V_62 = 0 ;
break;
case ' ' :
if ( V_63 )
V_62 = F_19 ( V_26 ) ;
else
V_62 = 0 ;
break;
default:
V_62 = 0 ;
}
return V_62 ;
}
int
F_21 ( T_2 * V_11 , const char * V_64 , int V_65 ,
const struct V_29 * V_30 , int V_66 )
{
int V_43 , V_44 ;
int V_67 = 0 ;
char V_10 ;
T_2 V_68 ;
T_3 V_49 ;
T_3 * V_51 ;
int V_69 ;
T_4 V_70 ;
if ( V_66 == V_9 )
return F_9 ( V_11 , V_64 , V_71 , V_30 ) ;
V_51 = F_22 ( 6 , V_61 ) ;
for ( V_43 = 0 ; V_43 < V_65 ; V_67 ++ ) {
V_10 = V_64 [ V_43 ] ;
V_44 = 1 ;
if ( V_10 == 0 )
goto V_72;
if ( V_66 == V_8 )
V_68 = F_18 ( V_10 ) ;
else if ( V_66 == V_6 ) {
bool V_63 ;
if ( V_43 == V_65 - 1 )
V_63 = true ;
else
V_63 = false ;
V_68 = F_20 ( V_10 , V_63 ) ;
} else
V_68 = 0 ;
if ( V_68 == 0 ) {
V_44 = V_30 -> V_53 ( V_64 + V_43 , V_65 - V_43 , & V_49 ) ;
V_68 = F_19 ( V_49 ) ;
if ( V_44 > 0 )
goto V_73;
if ( strcmp ( V_30 -> V_36 , L_1 ) || ! V_51 )
goto V_37;
if ( * ( V_64 + V_43 ) & 0x80 ) {
V_44 = F_23 ( V_64 + V_43 , 6 , & V_70 ) ;
if ( V_44 < 0 )
goto V_37;
} else
goto V_37;
V_69 = F_10 ( V_64 + V_43 , V_44 ,
V_38 ,
V_51 , 6 ) ;
if ( V_69 < 0 )
goto V_37;
V_43 += V_44 ;
V_68 = F_19 ( * V_51 ) ;
if ( V_44 <= 3 )
F_24 ( V_68 , & V_11 [ V_67 ] ) ;
else if ( V_44 == 4 ) {
F_24 ( V_68 , & V_11 [ V_67 ] ) ;
V_68 = F_19 ( * ( V_51 + 1 ) ) ;
V_67 ++ ;
F_24 ( V_68 , & V_11 [ V_67 ] ) ;
} else if ( V_44 >= 5 ) {
F_24 ( V_68 , & V_11 [ V_67 ] ) ;
V_68 = F_19 ( * ( V_51 + 1 ) ) ;
V_67 ++ ;
F_24 ( V_68 , & V_11 [ V_67 ] ) ;
V_68 = F_19 ( * ( V_51 + 2 ) ) ;
V_67 ++ ;
F_24 ( V_68 , & V_11 [ V_67 ] ) ;
}
continue;
V_37:
V_68 = F_19 ( 0x003f ) ;
V_44 = 1 ;
}
V_73:
V_43 += V_44 ;
F_24 ( V_68 , & V_11 [ V_67 ] ) ;
}
V_72:
F_24 ( 0 , & V_11 [ V_67 ] ) ;
F_25 ( V_51 ) ;
return V_67 ;
}
static int
F_26 ( const char * V_28 , int V_32 ,
const struct V_29 * V_42 )
{
int V_44 ;
int V_43 ;
T_3 V_51 ;
for ( V_43 = 0 ; V_32 && * V_28 ; V_43 ++ , V_28 += V_44 , V_32 -= V_44 ) {
V_44 = V_42 -> V_53 ( V_28 , V_32 , & V_51 ) ;
if ( V_44 < 1 )
V_44 = 1 ;
}
return 2 * V_43 ;
}
T_2 *
F_27 ( const char * V_57 , const int V_58 , int * V_74 ,
const struct V_29 * V_30 , int V_75 )
{
int V_32 ;
T_2 * V_60 ;
V_32 = F_26 ( V_57 , V_58 , V_30 ) ;
V_32 += 2 ;
V_60 = F_15 ( V_32 , V_61 ) ;
if ( ! V_60 ) {
* V_74 = 0 ;
return NULL ;
}
F_21 ( V_60 , V_57 , strlen ( V_57 ) , V_30 , V_75 ) ;
* V_74 = V_32 ;
return V_60 ;
}
