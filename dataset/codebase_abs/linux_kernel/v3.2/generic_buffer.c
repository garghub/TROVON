int F_1 ( struct V_1 * V_2 , int V_3 )
{
int V_4 = 0 ;
int V_5 = 0 ;
while ( V_5 < V_3 ) {
if ( V_4 % V_2 [ V_5 ] . V_4 == 0 )
V_2 [ V_5 ] . V_6 = V_4 ;
else
V_2 [ V_5 ] . V_6 = V_4 - V_4 % V_2 [ V_5 ] . V_4
+ V_2 [ V_5 ] . V_4 ;
V_4 = V_2 [ V_5 ] . V_6 + V_2 [ V_5 ] . V_4 ;
V_5 ++ ;
}
return V_4 ;
}
void F_2 ( int V_7 , struct V_1 * V_8 )
{
V_7 = V_7 >> V_8 -> V_9 ;
if ( V_8 -> V_10 ) {
T_1 V_11 = V_7 ;
V_11 &= ( 1 << V_8 -> V_12 ) - 1 ;
V_11 = ( T_1 ) ( V_11 << ( 16 - V_8 -> V_12 ) ) >>
( 16 - V_8 -> V_12 ) ;
printf ( L_1 , V_11 ,
( float ) ( V_11 + V_8 -> V_13 ) * V_8 -> V_14 ) ;
} else {
T_2 V_11 = V_7 ;
V_11 &= ( 1 << V_8 -> V_12 ) - 1 ;
printf ( L_2 , ( ( float ) V_11 + V_8 -> V_13 ) * V_8 -> V_14 ) ;
}
}
void F_3 ( char * V_15 ,
struct V_1 * V_16 ,
int V_3 )
{
int V_17 ;
for ( V_17 = 0 ; V_17 < V_3 ; V_17 ++ )
switch ( V_16 [ V_17 ] . V_4 ) {
case 2 :
F_2 ( * ( T_2 * ) ( V_15 + V_16 [ V_17 ] . V_6 ) ,
& V_16 [ V_17 ] ) ;
break;
case 8 :
if ( V_16 [ V_17 ] . V_10 ) {
T_3 V_11 = * ( T_3 * )
( V_15 +
V_16 [ V_17 ] . V_6 ) ;
if ( ( V_11 >> V_16 [ V_17 ] . V_12 ) & 1 )
V_11 = ( V_11 & V_16 [ V_17 ] . V_18 ) |
~ V_16 [ V_17 ] . V_18 ;
if ( V_16 [ V_17 ] . V_14 == 1.0f &&
V_16 [ V_17 ] . V_13 == 0.0f )
printf ( L_3 , V_11 ) ;
else
printf ( L_2 , ( ( float ) V_11 +
V_16 [ V_17 ] . V_13 ) *
V_16 [ V_17 ] . V_14 ) ;
}
break;
default:
break;
}
printf ( L_4 ) ;
}
int main ( int V_19 , char * * V_20 )
{
unsigned long V_21 = 2 ;
unsigned long V_22 = 1000000 ;
unsigned long V_23 = 128 ;
int V_24 , V_25 , V_5 , V_26 , V_27 ;
T_4 * V_28 ;
int V_29 ;
int V_3 ;
char * V_30 = NULL , * V_31 = NULL ;
char * V_32 , * V_33 ;
int V_34 = 1 ;
char * V_15 ;
T_5 V_35 ;
int V_36 , V_37 ;
char * V_38 ;
int V_39 ;
int V_40 = 0 ;
char * V_41 ;
struct V_1 * V_16 ;
while ( ( V_25 = F_4 ( V_19 , V_20 , L_5 ) ) != - 1 ) {
switch ( V_25 ) {
case 'n' :
V_31 = V_42 ;
break;
case 't' :
V_30 = V_42 ;
V_34 = 0 ;
break;
case 'e' :
V_40 = 1 ;
break;
case 'c' :
V_21 = strtoul ( V_42 , & V_41 , 10 ) ;
break;
case 'w' :
V_22 = strtoul ( V_42 , & V_41 , 10 ) ;
break;
case 'l' :
V_23 = strtoul ( V_42 , & V_41 , 10 ) ;
break;
case '?' :
return - 1 ;
}
}
if ( V_31 == NULL )
return - 1 ;
V_36 = F_5 ( V_31 , L_6 ) ;
if ( V_36 < 0 ) {
printf ( L_7 , V_31 ) ;
V_24 = - V_43 ;
goto V_44;
}
printf ( L_8 , V_36 ) ;
F_6 ( & V_32 , L_9 , V_45 , V_36 ) ;
if ( V_30 == NULL ) {
V_24 = F_6 ( & V_30 ,
L_10 , V_31 , V_36 ) ;
if ( V_24 < 0 ) {
V_24 = - V_46 ;
goto V_44;
}
}
V_37 = F_5 ( V_30 , L_11 ) ;
if ( V_37 < 0 ) {
printf ( L_12 , V_30 ) ;
V_24 = - V_43 ;
goto V_47;
}
printf ( L_13 , V_37 ) ;
V_24 = F_7 ( V_32 , & V_16 , & V_3 ) ;
if ( V_24 ) {
printf ( L_14 ) ;
printf ( L_15 , V_32 ) ;
goto V_47;
}
V_24 = F_6 ( & V_33 ,
L_16 , V_45 , V_36 ) ;
if ( V_24 < 0 ) {
V_24 = - V_46 ;
goto V_47;
}
printf ( L_17 , V_32 , V_30 ) ;
V_24 = F_8 ( L_18 ,
V_32 ,
V_30 ) ;
if ( V_24 < 0 ) {
printf ( L_19 ) ;
goto V_48;
}
V_24 = F_9 ( L_20 , V_33 , V_23 ) ;
if ( V_24 < 0 )
goto V_48;
V_24 = F_9 ( L_21 , V_33 , 1 ) ;
if ( V_24 < 0 )
goto V_48;
V_39 = F_1 ( V_16 , V_3 ) ;
V_15 = malloc ( V_39 * V_23 ) ;
if ( ! V_15 ) {
V_24 = - V_46 ;
goto V_48;
}
V_24 = F_6 ( & V_38 , L_22 , V_36 ) ;
if ( V_24 < 0 ) {
V_24 = - V_46 ;
goto V_49;
}
V_29 = F_10 ( V_38 , V_50 | V_51 ) ;
if ( V_29 == - 1 ) {
printf ( L_23 , V_38 ) ;
V_24 = - V_52 ;
goto V_53;
}
for ( V_26 = 0 ; V_26 < V_21 ; V_26 ++ ) {
if ( ! V_40 ) {
struct V_54 V_55 = {
. V_56 = V_29 ,
. V_57 = V_58 ,
} ;
F_11 ( & V_55 , 1 , - 1 ) ;
V_27 = V_23 ;
} else {
F_12 ( V_22 ) ;
V_27 = 64 ;
}
V_35 = F_13 ( V_29 ,
V_15 ,
V_27 * V_39 ) ;
if ( V_35 == - V_59 ) {
printf ( L_24 ) ;
continue;
}
for ( V_5 = 0 ; V_5 < V_35 / V_39 ; V_5 ++ )
F_3 ( V_15 + V_39 * V_5 ,
V_16 ,
V_3 ) ;
}
V_24 = F_9 ( L_21 , V_33 , 0 ) ;
if ( V_24 < 0 )
goto V_60;
F_14 ( L_18 ,
V_32 , L_25 ) ;
V_60:
F_15 ( V_29 ) ;
V_49:
free ( V_15 ) ;
V_53:
free ( V_38 ) ;
V_48:
free ( V_33 ) ;
V_47:
if ( V_34 )
free ( V_30 ) ;
V_44:
return V_24 ;
}
