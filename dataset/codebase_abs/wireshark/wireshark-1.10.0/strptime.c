static struct V_1 *
localtime_r ( T_1 , T_2 )
const T_3 * T_1 ;
struct V_1 * T_2 ;
{
struct V_1 * V_2 = localtime ( T_1 ) ;
if ( ! V_2 )
return 0 ;
* T_2 = * V_2 ;
return T_2 ;
}
static void
F_1 ( struct V_1 * V_1 )
{
int V_3 = 1900 + V_1 -> V_4 - ( V_1 -> V_5 < 2 ) ;
int V_6 = ( - 473
+ ( 365 * ( V_1 -> V_4 - 70 ) )
+ ( V_3 / 4 )
- ( ( V_3 / 4 ) / 25 ) + ( ( V_3 / 4 ) % 25 < 0 )
+ ( ( ( V_3 / 4 ) / 25 ) / 4 )
+ V_7 [ 0 ] [ V_1 -> V_5 ]
+ V_1 -> V_8 - 1 ) ;
V_1 -> V_9 = ( ( V_6 % 7 ) + 7 ) % 7 ;
}
static void
F_2 ( struct V_1 * V_1 )
{
V_1 -> V_10 = ( V_7 [ F_3 ( 1900 + V_1 -> V_4 ) ] [ V_1 -> V_5 ]
+ ( V_1 -> V_8 - 1 ) ) ;
}
static char *
#ifdef F_4
T_4
#endif
F_5 ( T_5 , T_6 , V_1 , T_7 , T_8 )
const char * T_5 ;
const char * T_6 ;
struct V_1 * V_1 ;
enum V_11 * T_7 ;
int T_8 ;
{
const char * V_12 ;
int V_13 ;
int V_14 ;
int V_15 , V_16 ;
int V_17 , V_18 ;
int V_19 ;
int V_20 , V_21 ;
int V_22 ;
int V_23 , V_24 ;
#ifdef F_6
T_9 V_25 ;
#endif
struct V_26 * V_27 ;
V_15 = V_16 = 0 ;
V_17 = - 1 ;
V_18 = 0 ;
V_19 = 0 ;
V_27 = NULL ;
V_20 = V_21 = V_22 = V_23 = V_24 = 0 ;
while ( * T_6 != '\0' )
{
if ( isspace ( * T_6 ) )
{
while ( isspace ( * T_5 ) )
++ T_5 ;
++ T_6 ;
continue;
}
if ( * T_6 != '%' )
{
F_7 ( * T_6 ++ , * T_5 ++ ) ;
continue;
}
++ T_6 ;
#ifndef F_6
V_28:
#endif
V_12 = T_5 ;
switch ( * T_6 ++ )
{
case '%' :
F_7 ( '%' , * T_5 ++ ) ;
break;
case 'a' :
case 'A' :
for ( V_13 = 0 ; V_13 < 7 ; ++ V_13 )
{
#ifdef F_6
if ( * T_7 != V_29 )
{
if ( F_8 ( F_6 ( V_30 , V_31 + V_13 ) , T_5 ) )
{
if ( * T_7 == V_32
&& strcmp ( F_6 ( V_30 , V_31 + V_13 ) ,
V_33 [ V_13 ] ) )
* T_7 = V_34 ;
break;
}
if ( F_8 ( F_6 ( V_30 , V_35 + V_13 ) , T_5 ) )
{
if ( * T_7 == V_32
&& strcmp ( F_6 ( V_30 , V_35 + V_13 ) ,
V_36 [ V_13 ] ) )
* T_7 = V_34 ;
break;
}
}
#endif
if ( * T_7 != V_34
&& ( F_8 ( V_33 [ V_13 ] , T_5 )
|| F_8 ( V_36 [ V_13 ] , T_5 ) ) )
{
* T_7 = V_29 ;
break;
}
}
if ( V_13 == 7 )
return NULL ;
V_1 -> V_9 = V_13 ;
V_20 = 1 ;
break;
case 'b' :
case 'B' :
case 'h' :
for ( V_13 = 0 ; V_13 < 12 ; ++ V_13 )
{
#ifdef F_6
if ( * T_7 != V_29 )
{
if ( F_8 ( F_6 ( V_30 , V_37 + V_13 ) , T_5 ) )
{
if ( * T_7 == V_32
&& strcmp ( F_6 ( V_30 , V_37 + V_13 ) ,
V_38 [ V_13 ] ) )
* T_7 = V_34 ;
break;
}
if ( F_8 ( F_6 ( V_30 , V_39 + V_13 ) , T_5 ) )
{
if ( * T_7 == V_32
&& strcmp ( F_6 ( V_30 , V_39 + V_13 ) ,
V_40 [ V_13 ] ) )
* T_7 = V_34 ;
break;
}
}
#endif
if ( F_8 ( V_38 [ V_13 ] , T_5 )
|| F_8 ( V_40 [ V_13 ] , T_5 ) )
{
* T_7 = V_29 ;
break;
}
}
if ( V_13 == 12 )
return NULL ;
V_1 -> V_5 = V_13 ;
V_21 = 1 ;
break;
case 'c' :
#ifdef F_6
if ( * T_7 != V_29 )
{
if ( ! F_9 ( F_6 ( V_30 , V_41 ) ) )
{
if ( * T_7 == V_34 )
return NULL ;
else
T_5 = V_12 ;
}
else
{
if ( * T_7 == V_32 &&
strcmp ( F_6 ( V_30 , V_41 ) , V_42 ) )
* T_7 = V_34 ;
V_21 = 1 ;
break;
}
* T_7 = V_29 ;
}
#endif
if ( ! F_9 ( V_42 ) )
return NULL ;
V_21 = 1 ;
break;
case 'C' :
#ifdef F_6
V_43:
#endif
F_10 ( 0 , 99 , 2 ) ;
V_17 = V_14 ;
V_21 = 1 ;
break;
case 'd' :
case 'e' :
F_10 ( 1 , 31 , 2 ) ;
V_1 -> V_8 = V_14 ;
V_24 = 1 ;
V_21 = 1 ;
break;
case 'F' :
if ( ! F_9 ( L_1 ) )
return NULL ;
V_21 = 1 ;
break;
case 'x' :
#ifdef F_6
if ( * T_7 != V_29 )
{
if ( ! F_9 ( F_6 ( V_30 , V_44 ) ) )
{
if ( * T_7 == V_34 )
return NULL ;
else
T_5 = V_12 ;
}
else
{
if ( * T_7 == V_32
&& strcmp ( F_6 ( V_30 , V_44 ) , V_45 ) )
* T_7 = V_34 ;
V_21 = 1 ;
break;
}
* T_7 = V_29 ;
}
#endif
case 'D' :
if ( ! F_9 ( V_45 ) )
return NULL ;
V_21 = 1 ;
break;
case 'k' :
case 'H' :
F_10 ( 0 , 23 , 2 ) ;
V_1 -> V_46 = V_14 ;
V_15 = 0 ;
break;
case 'I' :
F_10 ( 1 , 12 , 2 ) ;
V_1 -> V_46 = V_14 % 12 ;
V_15 = 1 ;
break;
case 'j' :
F_10 ( 1 , 366 , 3 ) ;
V_1 -> V_10 = V_14 - 1 ;
V_22 = 1 ;
break;
case 'm' :
F_10 ( 1 , 12 , 2 ) ;
V_1 -> V_5 = V_14 - 1 ;
V_23 = 1 ;
V_21 = 1 ;
break;
case 'M' :
F_10 ( 0 , 59 , 2 ) ;
V_1 -> V_47 = V_14 ;
break;
case 'n' :
case 't' :
while ( isspace ( * T_5 ) )
++ T_5 ;
break;
case 'p' :
#ifdef F_6
if ( * T_7 != V_29 )
{
if ( F_8 ( F_6 ( V_30 , V_48 ) , T_5 ) )
{
if ( strcmp ( F_6 ( V_30 , V_48 ) , V_49 ) )
* T_7 = V_34 ;
break;
}
if ( F_8 ( F_6 ( V_30 , V_50 ) , T_5 ) )
{
if ( strcmp ( F_6 ( V_30 , V_50 ) , V_51 ) )
* T_7 = V_34 ;
V_16 = 1 ;
break;
}
* T_7 = V_29 ;
}
#endif
if ( ! F_8 ( V_49 , T_5 ) ) {
if ( F_8 ( V_51 , T_5 ) )
V_16 = 1 ;
else
return NULL ;
}
break;
case 'r' :
#ifdef F_6
if ( * T_7 != V_29 )
{
if ( ! F_9 ( F_6 ( V_30 , V_52 ) ) )
{
if ( * T_7 == V_34 )
return NULL ;
else
T_5 = V_12 ;
}
else
{
if ( * T_7 == V_32 &&
strcmp ( F_6 ( V_30 , V_52 ) ,
V_53 ) )
* T_7 = V_34 ;
break;
}
* T_7 = V_29 ;
}
#endif
if ( ! F_9 ( V_53 ) )
return NULL ;
break;
case 'R' :
if ( ! F_9 ( L_2 ) )
return NULL ;
break;
case 's' :
{
T_3 V_54 = 0 ;
if ( * T_5 < '0' || * T_5 > '9' )
return NULL ;
do
{
V_54 *= 10 ;
V_54 += * T_5 ++ - '0' ;
}
while ( * T_5 >= '0' && * T_5 <= '9' );
if ( localtime_r ( & V_54 , V_1 ) == NULL )
return NULL ;
}
break;
case 'S' :
F_10 ( 0 , 61 , 2 ) ;
V_1 -> V_55 = V_14 ;
break;
case 'X' :
#ifdef F_6
if ( * T_7 != V_29 )
{
if ( ! F_9 ( F_6 ( V_30 , V_56 ) ) )
{
if ( * T_7 == V_34 )
return NULL ;
else
T_5 = V_12 ;
}
else
{
if ( strcmp ( F_6 ( V_30 , V_56 ) , V_57 ) )
* T_7 = V_34 ;
break;
}
* T_7 = V_29 ;
}
#endif
case 'T' :
if ( ! F_9 ( V_57 ) )
return NULL ;
break;
case 'u' :
F_10 ( 1 , 7 , 1 ) ;
V_1 -> V_9 = V_14 % 7 ;
V_20 = 1 ;
break;
case 'g' :
F_10 ( 0 , 99 , 2 ) ;
break;
case 'G' :
if ( * T_5 < '0' || * T_5 > '9' )
return NULL ;
do
++ T_5 ;
while ( * T_5 >= '0' && * T_5 <= '9' );
break;
case 'U' :
case 'V' :
case 'W' :
F_10 ( 0 , 53 , 2 ) ;
break;
case 'w' :
F_10 ( 0 , 6 , 1 ) ;
V_1 -> V_9 = V_14 ;
V_20 = 1 ;
break;
case 'y' :
#ifdef F_6
V_58:
#endif
F_10 ( 0 , 99 , 2 ) ;
V_1 -> V_4 = V_14 >= 69 ? V_14 : V_14 + 100 ;
V_18 = 1 ;
V_21 = 1 ;
break;
case 'Y' :
F_10 ( 0 , 9999 , 4 ) ;
V_1 -> V_4 = V_14 - 1900 ;
V_18 = 0 ;
V_21 = 1 ;
break;
case 'Z' :
break;
case 'E' :
#ifdef F_6
switch ( * T_6 ++ )
{
case 'c' :
if ( * T_7 != V_29 )
{
const char * T_6 = F_6 ( V_30 , V_59 ) ;
if ( * T_6 == '\0' )
T_6 = F_6 ( V_30 , V_41 ) ;
if ( ! F_9 ( T_6 ) )
{
if ( * T_7 == V_34 )
return NULL ;
else
T_5 = V_12 ;
}
else
{
if ( strcmp ( T_6 , V_42 ) )
* T_7 = V_34 ;
V_21 = 1 ;
break;
}
* T_7 = V_29 ;
}
if ( ! F_9 ( V_42 ) )
return NULL ;
V_21 = 1 ;
break;
case 'C' :
if ( * T_7 != V_29 )
{
if ( T_8 >= 0 )
{
V_27 = F_11 ( T_8 ) ;
if ( F_8 ( V_27 -> V_60 , T_5 ) )
{
* T_7 = V_34 ;
break;
}
else
return NULL ;
}
else
{
V_25 = F_12 ( V_30 ,
V_61 ) ;
for ( T_8 = 0 ; T_8 < ( int ) V_25 ;
++ T_8 , T_5 = V_12 )
{
V_27 = F_11 ( T_8 ) ;
if ( F_8 ( V_27 -> V_60 , T_5 ) )
{
* T_7 = V_34 ;
break;
}
}
if ( T_8 == ( int ) V_25 )
{
T_8 = - 1 ;
if ( * T_7 == V_34 )
return NULL ;
}
else
break;
}
* T_7 = V_29 ;
}
goto V_43;
case 'y' :
if ( * T_7 == V_29 )
goto V_58;
F_10 ( 0 , 9999 , 4 ) ;
V_1 -> V_4 = V_14 ;
V_19 = 1 ;
V_21 = 1 ;
break;
case 'Y' :
if ( * T_7 != V_29 )
{
V_25 = F_12 ( V_30 ,
V_61 ) ;
for ( T_8 = 0 ; T_8 < ( int ) V_25 ;
++ T_8 , T_5 = V_12 )
{
V_27 = F_11 ( T_8 ) ;
if ( F_9 ( V_27 -> V_62 ) )
break;
}
if ( T_8 == ( int ) V_25 )
{
T_8 = - 1 ;
if ( * T_7 == V_34 )
return NULL ;
else
T_5 = V_12 ;
}
else
{
* T_7 = V_34 ;
T_8 = - 1 ;
break;
}
* T_7 = V_29 ;
}
F_10 ( 0 , 9999 , 4 ) ;
V_1 -> V_4 = V_14 - 1900 ;
V_18 = 0 ;
V_21 = 1 ;
break;
case 'x' :
if ( * T_7 != V_29 )
{
const char * T_6 = F_6 ( V_30 , V_63 ) ;
if ( * T_6 == '\0' )
T_6 = F_6 ( V_30 , V_44 ) ;
if ( ! F_9 ( T_6 ) )
{
if ( * T_7 == V_34 )
return NULL ;
else
T_5 = V_12 ;
}
else
{
if ( strcmp ( T_6 , V_45 ) )
* T_7 = V_34 ;
break;
}
* T_7 = V_29 ;
}
if ( ! F_9 ( V_45 ) )
return NULL ;
break;
case 'X' :
if ( * T_7 != V_29 )
{
const char * T_6 = F_6 ( V_30 , V_64 ) ;
if ( * T_6 == '\0' )
T_6 = F_6 ( V_30 , V_56 ) ;
if ( ! F_9 ( T_6 ) )
{
if ( * T_7 == V_34 )
return NULL ;
else
T_5 = V_12 ;
}
else
{
if ( strcmp ( T_6 , V_57 ) )
* T_7 = V_34 ;
break;
}
* T_7 = V_29 ;
}
if ( ! F_9 ( V_57 ) )
return NULL ;
break;
default:
return NULL ;
}
break;
#else
if ( * T_6 != 'c' && * T_6 != 'C' && * T_6 != 'y' && * T_6 != 'Y'
&& * T_6 != 'x' && * T_6 != 'X' )
return NULL ;
goto V_28;
#endif
case 'O' :
switch ( * T_6 ++ )
{
case 'd' :
case 'e' :
F_13 ( 1 , 31 , 2 ) ;
V_1 -> V_8 = V_14 ;
V_24 = 1 ;
V_21 = 1 ;
break;
case 'H' :
F_13 ( 0 , 23 , 2 ) ;
V_1 -> V_46 = V_14 ;
V_15 = 0 ;
break;
case 'I' :
F_13 ( 1 , 12 , 2 ) ;
V_1 -> V_46 = V_14 - 1 ;
V_15 = 1 ;
break;
case 'm' :
F_13 ( 1 , 12 , 2 ) ;
V_1 -> V_5 = V_14 - 1 ;
V_23 = 1 ;
V_21 = 1 ;
break;
case 'M' :
F_13 ( 0 , 59 , 2 ) ;
V_1 -> V_47 = V_14 ;
break;
case 'S' :
F_13 ( 0 , 61 , 2 ) ;
V_1 -> V_55 = V_14 ;
break;
case 'U' :
case 'V' :
case 'W' :
F_13 ( 0 , 53 , 2 ) ;
break;
case 'w' :
F_13 ( 0 , 6 , 1 ) ;
V_1 -> V_9 = V_14 ;
V_20 = 1 ;
break;
case 'y' :
F_13 ( 0 , 99 , 2 ) ;
V_1 -> V_4 = V_14 >= 69 ? V_14 : V_14 + 100 ;
V_21 = 1 ;
break;
default:
return NULL ;
}
break;
default:
return NULL ;
}
}
if ( V_15 && V_16 )
V_1 -> V_46 += 12 ;
if ( V_17 != - 1 )
{
if ( V_18 )
V_1 -> V_4 = V_1 -> V_4 % 100 + ( V_17 - 19 ) * 100 ;
else
V_1 -> V_4 = ( V_17 - 19 ) * 100 ;
}
#ifdef F_6
if ( T_8 != - 1 )
{
V_27 = F_11 ( T_8 ) ;
if ( V_19 )
V_1 -> V_4 = ( V_27 -> V_65 [ 0 ]
+ ( ( V_1 -> V_4 - V_27 -> V_66 )
* V_27 -> V_67 ) ) ;
else
V_1 -> V_4 = V_27 -> V_65 [ 0 ] ;
}
else
#endif
if ( V_19 )
return NULL ;
if ( V_21 && ! V_20 )
{
if ( ! ( V_23 && V_24 ) && V_22 )
{
int V_68 = 0 ;
while ( V_7 [ F_3 ( 1900 + V_1 -> V_4 ) ] [ V_68 ] <= V_1 -> V_10 )
V_68 ++ ;
if ( ! V_23 )
V_1 -> V_5 = V_68 - 1 ;
if ( ! V_24 )
V_1 -> V_8 =
( V_1 -> V_10
- V_7 [ F_3 ( 1900 + V_1 -> V_4 ) ] [ V_68 - 1 ] + 1 ) ;
}
F_1 ( V_1 ) ;
}
if ( V_21 && ! V_22 )
F_2 ( V_1 ) ;
return ( char * ) T_5 ;
}
char *
strptime ( T_10 , T_11 , V_1 )
const char * T_10 ;
const char * T_11 ;
struct V_1 * V_1 ;
{
enum V_11 T_7 ;
#ifdef F_6
T_7 = V_32 ;
#else
T_7 = V_29 ;
#endif
return F_5 ( T_10 , T_11 , V_1 , & T_7 , - 1 ) ;
}
