static void F_1 ( T_1 * V_1 , T_1 * V_2 , int V_3 , int V_4 ,
int V_5 , int V_6 , T_2 V_7 ,
void * V_8 )
{
F_2 ( V_2 , V_3 , V_4 , V_7 , V_8 ) ;
F_3 ( V_1 ) ;
F_4 ( V_1 , V_5 , V_6 ) ;
F_5 ( V_1 ) ;
}
int F_6 ( const char * V_9 , char * V_10 , int V_11 ,
int V_12 , int * V_13 , int * V_14 , int * V_15 ,
T_2 V_7 , void * V_8 )
{
int V_16 , V_17 , V_18 , V_6 , V_5 , V_19 = 0 ;
int V_20 , V_21 , V_3 , V_4 ;
T_1 * V_1 , * V_2 ;
bool V_22 = false ;
V_23 = 1 ;
V_24 = 0 ;
V_25 = 0 ;
V_26 = 0 ;
V_27 = V_10 ;
V_28 = V_27 ;
if ( V_14 && * V_14 ) {
V_23 = 0 ;
for ( V_16 = 0 ; V_16 < * V_14 ; V_16 ++ )
F_7 () ;
}
if ( V_15 )
V_26 = * V_15 ;
V_29:
F_8 ( V_30 , V_20 , V_21 ) ;
if ( V_20 < V_31 || V_21 < V_32 )
return - V_33 ;
if ( V_11 != 0 )
V_20 = V_11 ;
else
if ( V_20 > 4 )
V_20 -= 4 ;
else
V_20 = 0 ;
if ( V_12 != 0 )
V_21 = V_12 ;
else
if ( V_21 > 5 )
V_21 -= 5 ;
else
V_21 = 0 ;
V_17 = ( F_9 ( V_30 ) - V_21 ) / 2 ;
V_18 = ( F_10 ( V_30 ) - V_20 ) / 2 ;
F_11 ( V_30 , V_18 , V_17 , V_20 , V_21 ) ;
V_1 = F_12 ( V_20 , V_21 , V_18 , V_17 ) ;
F_13 ( V_1 , TRUE ) ;
V_3 = V_20 - 4 ;
V_4 = V_21 - 2 ;
V_2 = F_14 ( V_1 , V_3 , V_4 , V_18 + 1 , V_17 + 1 ) ;
F_15 ( V_2 , V_34 . V_1 . V_35 ) ;
F_16 ( V_2 , V_34 . V_1 . V_35 & V_36 ) ;
F_13 ( V_2 , TRUE ) ;
F_17 ( V_1 , 0 , 0 , V_20 , V_21 ,
V_34 . V_1 . V_35 , V_34 . V_37 . V_35 ) ;
F_15 ( V_1 , V_34 . V_37 . V_35 ) ;
F_18 ( V_1 , V_20 - 3 , 0 , V_38 ) ;
for ( V_16 = 0 ; V_16 < V_21 - 2 ; V_16 ++ )
F_19 ( V_1 , V_39 ) ;
F_15 ( V_1 , V_34 . V_1 . V_35 ) ;
F_16 ( V_1 , V_34 . V_1 . V_35 & V_36 ) ;
F_19 ( V_1 , V_40 ) ;
F_20 ( V_1 , V_9 , V_21 ) ;
F_21 ( V_1 , F_22 ( L_1 ) , V_20 - 2 , V_21 / 2 - 4 , TRUE ) ;
F_23 ( V_1 ) ;
F_24 ( V_1 , V_5 , V_6 ) ;
F_25 ( V_2 , V_3 , V_4 , V_34 . V_1 . V_35 ) ;
F_1 ( V_1 , V_2 , V_3 , V_4 , V_5 , V_6 , V_7 ,
V_8 ) ;
while ( ! V_22 ) {
V_19 = F_26 ( V_1 ) ;
switch ( V_19 ) {
case 'E' :
case 'e' :
case 'X' :
case 'x' :
case 'q' :
case '\n' :
V_22 = true ;
break;
case 'g' :
case V_41 :
if ( ! V_23 ) {
V_23 = 1 ;
V_28 = V_27 ;
F_1 ( V_1 , V_2 , V_3 , V_4 ,
V_5 , V_6 , V_7 ,
V_8 ) ;
}
break;
case 'G' :
case V_42 :
V_24 = 1 ;
V_28 = V_27 + strlen ( V_27 ) ;
F_27 ( V_3 ) ;
F_1 ( V_1 , V_2 , V_3 , V_4 , V_5 ,
V_6 , V_7 , V_8 ) ;
break;
case 'K' :
case 'k' :
case V_43 :
if ( V_23 )
break;
F_27 ( V_25 + 1 ) ;
F_1 ( V_1 , V_2 , V_3 , V_4 , V_5 ,
V_6 , V_7 , V_8 ) ;
break;
case 'B' :
case 'b' :
case 'u' :
case V_44 :
if ( V_23 )
break;
F_27 ( V_25 + V_3 ) ;
F_1 ( V_1 , V_2 , V_3 , V_4 , V_5 ,
V_6 , V_7 , V_8 ) ;
break;
case 'J' :
case 'j' :
case V_45 :
if ( V_24 )
break;
F_27 ( V_25 - 1 ) ;
F_1 ( V_1 , V_2 , V_3 , V_4 , V_5 ,
V_6 , V_7 , V_8 ) ;
break;
case V_46 :
case ' ' :
case 'd' :
if ( V_24 )
break;
V_23 = 0 ;
F_1 ( V_1 , V_2 , V_3 , V_4 , V_5 ,
V_6 , V_7 , V_8 ) ;
break;
case '0' :
case 'H' :
case 'h' :
case V_47 :
if ( V_26 <= 0 )
break;
if ( V_19 == '0' )
V_26 = 0 ;
else
V_26 -- ;
F_27 ( V_25 ) ;
F_1 ( V_1 , V_2 , V_3 , V_4 , V_5 ,
V_6 , V_7 , V_8 ) ;
break;
case 'L' :
case 'l' :
case V_48 :
if ( V_26 >= V_49 )
break;
V_26 ++ ;
F_27 ( V_25 ) ;
F_1 ( V_1 , V_2 , V_3 , V_4 , V_5 ,
V_6 , V_7 , V_8 ) ;
break;
case V_50 :
if ( F_28 ( V_1 ) == V_50 )
V_22 = true ;
break;
case V_51 :
F_27 ( V_20 ) ;
F_29 ( V_2 ) ;
F_29 ( V_1 ) ;
F_30 () ;
goto V_29;
default:
for ( V_16 = 0 ; V_13 [ V_16 ] ; V_16 ++ ) {
if ( V_19 == V_13 [ V_16 ] ) {
V_22 = true ;
break;
}
}
}
}
F_29 ( V_2 ) ;
F_29 ( V_1 ) ;
if ( V_14 ) {
const char * V_52 ;
V_52 = V_27 ;
* V_14 = 0 ;
F_27 ( V_25 ) ;
while ( V_52 < V_28 && ( V_52 = strchr ( V_52 , '\n' ) ) ) {
( * V_14 ) ++ ;
V_52 ++ ;
}
}
if ( V_15 )
* V_15 = V_26 ;
return V_19 ;
}
static void F_27 ( int V_53 )
{
int V_16 ;
V_23 = 0 ;
for ( V_16 = 0 ; V_16 < V_53 ; V_16 ++ ) {
if ( * V_28 == '\0' ) {
if ( V_24 ) {
V_24 = 0 ;
continue;
}
}
if ( V_28 == V_27 ) {
V_23 = 1 ;
return;
}
V_28 -- ;
do {
if ( V_28 == V_27 ) {
V_23 = 1 ;
return;
}
V_28 -- ;
} while ( * V_28 != '\n' );
V_28 ++ ;
}
}
static void F_2 ( T_1 * V_54 , int V_20 , int V_21 , T_2
V_7 , void * V_8 )
{
int V_16 , V_55 = 0 ;
if ( V_7 ) {
char * V_56 ;
for ( V_16 = 0 ; V_16 < V_20 ; V_16 ++ )
F_7 () ;
V_56 = V_28 ;
F_27 ( V_20 ) ;
V_7 ( V_27 , V_28 - V_27 , V_56 - V_27 , V_8 ) ;
}
V_25 = 0 ;
for ( V_16 = 0 ; V_16 < V_20 ; V_16 ++ ) {
F_31 ( V_54 , V_16 , V_21 ) ;
if ( ! V_55 )
V_25 ++ ;
if ( V_24 && ! V_55 )
V_55 = 1 ;
}
F_23 ( V_54 ) ;
}
static void F_31 ( T_1 * V_54 , int V_57 , int V_21 )
{
char * line ;
line = F_7 () ;
line += F_32 ( strlen ( line ) , V_26 ) ;
F_4 ( V_54 , V_57 , 0 ) ;
F_19 ( V_54 , ' ' ) ;
F_33 ( V_54 , line , F_32 ( strlen ( line ) , V_21 - 2 ) ) ;
#if V_58
{
int V_17 = F_34 ( V_54 ) ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_21 - V_17 ; V_16 ++ )
F_19 ( V_54 , ' ' ) ;
}
#else
F_35 ( V_54 ) ;
#endif
}
static char * F_7 ( void )
{
int V_16 = 0 ;
static char line [ V_49 + 1 ] ;
V_24 = 0 ;
while ( * V_28 != '\n' ) {
if ( * V_28 == '\0' ) {
V_24 = 1 ;
break;
} else if ( V_16 < V_49 )
line [ V_16 ++ ] = * ( V_28 ++ ) ;
else {
if ( V_16 == V_49 )
line [ V_16 ++ ] = '\0' ;
V_28 ++ ;
}
}
if ( V_16 <= V_49 )
line [ V_16 ] = '\0' ;
if ( ! V_24 )
V_28 ++ ;
return line ;
}
static void F_3 ( T_1 * V_54 )
{
int V_59 ;
F_15 ( V_54 , V_34 . V_60 . V_35 ) ;
F_16 ( V_54 , V_34 . V_60 . V_35 & V_36 ) ;
V_59 = ( V_28 - V_27 ) * 100 / strlen ( V_27 ) ;
F_4 ( V_54 , F_10 ( V_54 ) - 3 , F_9 ( V_54 ) - 9 ) ;
F_36 ( V_54 , L_2 , V_59 ) ;
}
