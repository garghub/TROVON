static void F_1 ( T_1 * V_1 , T_1 * V_2 , int V_3 , int V_4 ,
int V_5 , int V_6 )
{
F_2 ( V_2 , V_3 , V_4 ) ;
F_3 ( V_1 ) ;
F_4 ( V_1 , V_5 , V_6 ) ;
F_5 ( V_1 ) ;
}
int F_6 ( const char * V_7 , const char * V_8 ,
int V_9 , int V_10 )
{
int V_11 , V_12 , V_13 , V_6 , V_5 , V_14 = 0 ;
int V_15 , V_16 , V_3 , V_4 ;
int V_17 ;
T_1 * V_1 , * V_2 ;
V_18 = 1 ;
V_19 = 0 ;
V_20 = 0 ;
V_21 = 0 ;
V_22 = V_8 ;
V_23 = V_22 ;
V_24:
F_7 ( V_25 , V_15 , V_16 ) ;
if ( V_15 < 8 || V_16 < 8 )
return - V_26 ;
if ( V_9 != 0 )
V_15 = V_9 ;
else
if ( V_15 > 4 )
V_15 -= 4 ;
else
V_15 = 0 ;
if ( V_10 != 0 )
V_16 = V_10 ;
else
if ( V_16 > 5 )
V_16 -= 5 ;
else
V_16 = 0 ;
V_12 = ( V_27 - V_16 ) / 2 ;
V_13 = ( V_28 - V_15 ) / 2 ;
F_8 ( V_25 , V_13 , V_12 , V_15 , V_16 ) ;
V_1 = F_9 ( V_15 , V_16 , V_13 , V_12 ) ;
F_10 ( V_1 , TRUE ) ;
V_3 = V_15 - 4 ;
V_4 = V_16 - 2 ;
V_2 = F_11 ( V_1 , V_3 , V_4 , V_13 + 1 , V_12 + 1 ) ;
F_12 ( V_2 , V_29 . V_1 . V_30 ) ;
F_13 ( V_2 , V_29 . V_1 . V_30 & V_31 ) ;
F_10 ( V_2 , TRUE ) ;
F_14 ( V_1 , 0 , 0 , V_15 , V_16 ,
V_29 . V_1 . V_30 , V_29 . V_32 . V_30 ) ;
F_12 ( V_1 , V_29 . V_32 . V_30 ) ;
F_15 ( V_1 , V_15 - 3 , 0 , V_33 ) ;
for ( V_11 = 0 ; V_11 < V_16 - 2 ; V_11 ++ )
F_16 ( V_1 , V_34 ) ;
F_12 ( V_1 , V_29 . V_1 . V_30 ) ;
F_13 ( V_1 , V_29 . V_1 . V_30 & V_31 ) ;
F_16 ( V_1 , V_35 ) ;
F_17 ( V_1 , V_7 , V_16 ) ;
F_18 ( V_1 , F_19 ( L_1 ) , V_15 - 2 , V_16 / 2 - 4 , TRUE ) ;
F_20 ( V_1 ) ;
F_21 ( V_1 , V_5 , V_6 ) ;
F_22 ( V_2 , V_3 , V_4 , V_29 . V_1 . V_30 ) ;
F_1 ( V_1 , V_2 , V_3 , V_4 , V_5 , V_6 ) ;
while ( ( V_14 != V_36 ) && ( V_14 != '\n' ) ) {
V_14 = F_23 ( V_1 ) ;
switch ( V_14 ) {
case 'E' :
case 'e' :
case 'X' :
case 'x' :
F_24 ( V_2 ) ;
F_24 ( V_1 ) ;
return 0 ;
case 'g' :
case V_37 :
if ( ! V_18 ) {
V_18 = 1 ;
V_23 = V_22 ;
F_1 ( V_1 , V_2 , V_3 , V_4 ,
V_5 , V_6 ) ;
}
break;
case 'G' :
case V_38 :
V_19 = 1 ;
V_23 = V_22 + strlen ( V_22 ) ;
F_25 ( V_3 ) ;
F_1 ( V_1 , V_2 , V_3 , V_4 ,
V_5 , V_6 ) ;
break;
case 'K' :
case 'k' :
case V_39 :
if ( ! V_18 ) {
F_25 ( V_20 + 1 ) ;
F_26 ( V_2 , TRUE ) ;
F_27 ( V_2 , - 1 ) ;
F_26 ( V_2 , FALSE ) ;
V_20 = 0 ;
V_17 = 0 ;
for ( V_11 = 0 ; V_11 < V_3 ; V_11 ++ ) {
if ( ! V_11 ) {
F_28 ( V_2 , 0 , V_4 ) ;
F_20 ( V_2 ) ;
} else
F_29 () ;
if ( ! V_17 )
V_20 ++ ;
if ( V_19 && ! V_17 )
V_17 = 1 ;
}
F_3 ( V_1 ) ;
F_4 ( V_1 , V_5 , V_6 ) ;
F_5 ( V_1 ) ;
}
break;
case 'B' :
case 'b' :
case V_40 :
if ( V_18 )
break;
F_25 ( V_20 + V_3 ) ;
F_1 ( V_1 , V_2 , V_3 , V_4 ,
V_5 , V_6 ) ;
break;
case 'J' :
case 'j' :
case V_41 :
if ( ! V_19 ) {
V_18 = 0 ;
F_26 ( V_2 , TRUE ) ;
F_30 ( V_2 ) ;
F_26 ( V_2 , FALSE ) ;
F_28 ( V_2 , V_3 - 1 , V_4 ) ;
F_20 ( V_2 ) ;
F_3 ( V_1 ) ;
F_4 ( V_1 , V_5 , V_6 ) ;
F_5 ( V_1 ) ;
}
break;
case V_42 :
case ' ' :
if ( V_19 )
break;
V_18 = 0 ;
F_1 ( V_1 , V_2 , V_3 , V_4 ,
V_5 , V_6 ) ;
break;
case '0' :
case 'H' :
case 'h' :
case V_43 :
if ( V_21 <= 0 )
break;
if ( V_14 == '0' )
V_21 = 0 ;
else
V_21 -- ;
F_25 ( V_20 ) ;
F_1 ( V_1 , V_2 , V_3 , V_4 ,
V_5 , V_6 ) ;
break;
case 'L' :
case 'l' :
case V_44 :
if ( V_21 >= V_45 )
break;
V_21 ++ ;
F_25 ( V_20 ) ;
F_1 ( V_1 , V_2 , V_3 , V_4 ,
V_5 , V_6 ) ;
break;
case V_36 :
V_14 = F_31 ( V_1 ) ;
break;
case V_46 :
F_25 ( V_15 ) ;
F_24 ( V_2 ) ;
F_24 ( V_1 ) ;
F_32 () ;
goto V_24;
}
}
F_24 ( V_2 ) ;
F_24 ( V_1 ) ;
return V_14 ;
}
static void F_25 ( int V_47 )
{
int V_11 ;
V_18 = 0 ;
for ( V_11 = 0 ; V_11 < V_47 ; V_11 ++ ) {
if ( * V_23 == '\0' ) {
if ( V_19 ) {
V_19 = 0 ;
continue;
}
}
if ( V_23 == V_22 ) {
V_18 = 1 ;
return;
}
V_23 -- ;
do {
if ( V_23 == V_22 ) {
V_18 = 1 ;
return;
}
V_23 -- ;
} while ( * V_23 != '\n' );
V_23 ++ ;
}
}
static void F_2 ( T_1 * V_48 , int V_15 , int V_16 )
{
int V_11 , V_17 = 0 ;
V_20 = 0 ;
for ( V_11 = 0 ; V_11 < V_15 ; V_11 ++ ) {
F_28 ( V_48 , V_11 , V_16 ) ;
if ( ! V_17 )
V_20 ++ ;
if ( V_19 && ! V_17 )
V_17 = 1 ;
}
F_20 ( V_48 ) ;
}
static void F_28 ( T_1 * V_48 , int V_49 , int V_16 )
{
char * line ;
line = F_29 () ;
line += F_33 ( strlen ( line ) , V_21 ) ;
F_4 ( V_48 , V_49 , 0 ) ;
F_16 ( V_48 , ' ' ) ;
F_34 ( V_48 , line , F_33 ( strlen ( line ) , V_16 - 2 ) ) ;
#if V_50
{
int V_12 = F_35 ( V_48 ) ;
int V_11 ;
for ( V_11 = 0 ; V_11 < V_16 - V_12 ; V_11 ++ )
F_16 ( V_48 , ' ' ) ;
}
#else
F_36 ( V_48 ) ;
#endif
}
static char * F_29 ( void )
{
int V_11 = 0 ;
static char line [ V_45 + 1 ] ;
V_19 = 0 ;
while ( * V_23 != '\n' ) {
if ( * V_23 == '\0' ) {
if ( ! V_19 ) {
V_19 = 1 ;
break;
}
} else if ( V_11 < V_45 )
line [ V_11 ++ ] = * ( V_23 ++ ) ;
else {
if ( V_11 == V_45 )
line [ V_11 ++ ] = '\0' ;
V_23 ++ ;
}
}
if ( V_11 <= V_45 )
line [ V_11 ] = '\0' ;
if ( ! V_19 )
V_23 ++ ;
return line ;
}
static void F_3 ( T_1 * V_48 )
{
int V_51 ;
F_12 ( V_48 , V_29 . V_52 . V_30 ) ;
F_13 ( V_48 , V_29 . V_52 . V_30 & V_31 ) ;
V_51 = ( V_23 - V_22 ) * 100 / strlen ( V_22 ) ;
F_4 ( V_48 , F_37 ( V_48 ) - 3 , F_38 ( V_48 ) - 9 ) ;
F_39 ( V_48 , L_2 , V_51 ) ;
}
