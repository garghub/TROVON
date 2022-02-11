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
if ( V_8 -> V_9 )
V_7 = F_3 ( ( V_10 ) V_7 ) ;
else
V_7 = F_4 ( ( V_10 ) V_7 ) ;
V_7 = V_7 >> V_8 -> V_11 ;
if ( V_8 -> V_12 ) {
T_1 V_13 = V_7 ;
V_13 &= ( 1 << V_8 -> V_14 ) - 1 ;
V_13 = ( T_1 ) ( V_13 << ( 16 - V_8 -> V_14 ) ) >>
( 16 - V_8 -> V_14 ) ;
printf ( L_1 , ( ( float ) V_13 + V_8 -> V_15 ) * V_8 -> V_16 ) ;
} else {
V_10 V_13 = V_7 ;
V_13 &= ( 1 << V_8 -> V_14 ) - 1 ;
printf ( L_1 , ( ( float ) V_13 + V_8 -> V_15 ) * V_8 -> V_16 ) ;
}
}
void F_5 ( char * V_17 ,
struct V_1 * V_2 ,
int V_3 )
{
int V_18 ;
for ( V_18 = 0 ; V_18 < V_3 ; V_18 ++ )
switch ( V_2 [ V_18 ] . V_4 ) {
case 2 :
F_2 ( * ( V_10 * ) ( V_17 + V_2 [ V_18 ] . V_6 ) ,
& V_2 [ V_18 ] ) ;
break;
case 8 :
if ( V_2 [ V_18 ] . V_12 ) {
T_2 V_13 = * ( T_2 * )
( V_17 +
V_2 [ V_18 ] . V_6 ) ;
if ( ( V_13 >> V_2 [ V_18 ] . V_14 ) & 1 )
V_13 = ( V_13 & V_2 [ V_18 ] . V_19 ) |
~ V_2 [ V_18 ] . V_19 ;
if ( V_2 [ V_18 ] . V_16 == 1.0f &&
V_2 [ V_18 ] . V_15 == 0.0f )
printf ( L_2 V_20 L_3 , V_13 ) ;
else
printf ( L_1 , ( ( float ) V_13 +
V_2 [ V_18 ] . V_15 ) *
V_2 [ V_18 ] . V_16 ) ;
}
break;
default:
break;
}
printf ( L_4 ) ;
}
int main ( int V_21 , char * * V_22 )
{
unsigned long V_23 = 2 ;
unsigned long V_24 = 1000000 ;
unsigned long V_25 = 128 ;
int V_26 , V_27 , V_5 , V_28 , V_29 ;
int V_30 ;
int V_3 ;
char * V_31 = NULL , * V_32 = NULL ;
char * V_33 , * V_34 ;
int V_35 = 1 ;
char * V_17 ;
T_3 V_36 ;
int V_37 , V_38 ;
char * V_39 ;
int V_40 ;
int V_41 = 0 ;
char * V_42 ;
struct V_1 * V_2 ;
while ( ( V_27 = F_6 ( V_21 , V_22 , L_5 ) ) != - 1 ) {
switch ( V_27 ) {
case 'n' :
V_32 = V_43 ;
break;
case 't' :
V_31 = V_43 ;
V_35 = 0 ;
break;
case 'e' :
V_41 = 1 ;
break;
case 'c' :
V_23 = strtoul ( V_43 , & V_42 , 10 ) ;
break;
case 'w' :
V_24 = strtoul ( V_43 , & V_42 , 10 ) ;
break;
case 'l' :
V_25 = strtoul ( V_43 , & V_42 , 10 ) ;
break;
case '?' :
return - 1 ;
}
}
if ( V_32 == NULL )
return - 1 ;
V_37 = F_7 ( V_32 , L_6 ) ;
if ( V_37 < 0 ) {
printf ( L_7 , V_32 ) ;
V_26 = - V_44 ;
goto V_45;
}
printf ( L_8 , V_37 ) ;
F_8 ( & V_33 , L_9 , V_46 , V_37 ) ;
if ( V_31 == NULL ) {
V_26 = F_8 ( & V_31 ,
L_10 , V_32 , V_37 ) ;
if ( V_26 < 0 ) {
V_26 = - V_47 ;
goto V_45;
}
}
V_38 = F_7 ( V_31 , L_11 ) ;
if ( V_38 < 0 ) {
printf ( L_12 , V_31 ) ;
V_26 = - V_44 ;
goto V_48;
}
printf ( L_13 , V_38 ) ;
V_26 = F_9 ( V_33 , & V_2 , & V_3 ) ;
if ( V_26 ) {
printf ( L_14 ) ;
printf ( L_15 , V_33 ) ;
goto V_48;
}
V_26 = F_8 ( & V_34 ,
L_16 , V_46 , V_37 ) ;
if ( V_26 < 0 ) {
V_26 = - V_47 ;
goto V_48;
}
printf ( L_17 , V_33 , V_31 ) ;
V_26 = F_10 ( L_18 ,
V_33 ,
V_31 ) ;
if ( V_26 < 0 ) {
printf ( L_19 ) ;
goto V_49;
}
V_26 = F_11 ( L_20 , V_34 , V_25 ) ;
if ( V_26 < 0 )
goto V_49;
V_26 = F_11 ( L_21 , V_34 , 1 ) ;
if ( V_26 < 0 )
goto V_49;
V_40 = F_1 ( V_2 , V_3 ) ;
V_17 = malloc ( V_40 * V_25 ) ;
if ( ! V_17 ) {
V_26 = - V_47 ;
goto V_49;
}
V_26 = F_8 ( & V_39 , L_22 , V_37 ) ;
if ( V_26 < 0 ) {
V_26 = - V_47 ;
goto V_50;
}
V_30 = F_12 ( V_39 , V_51 | V_52 ) ;
if ( V_30 == - 1 ) {
printf ( L_23 , V_39 ) ;
V_26 = - V_53 ;
goto V_54;
}
for ( V_28 = 0 ; V_28 < V_23 ; V_28 ++ ) {
if ( ! V_41 ) {
struct V_55 V_56 = {
. V_57 = V_30 ,
. V_58 = V_59 ,
} ;
F_13 ( & V_56 , 1 , - 1 ) ;
V_29 = V_25 ;
} else {
F_14 ( V_24 ) ;
V_29 = 64 ;
}
V_36 = F_15 ( V_30 ,
V_17 ,
V_29 * V_40 ) ;
if ( V_36 == - V_60 ) {
printf ( L_24 ) ;
continue;
}
for ( V_5 = 0 ; V_5 < V_36 / V_40 ; V_5 ++ )
F_5 ( V_17 + V_40 * V_5 ,
V_2 ,
V_3 ) ;
}
V_26 = F_11 ( L_21 , V_34 , 0 ) ;
if ( V_26 < 0 )
goto V_61;
F_16 ( L_18 ,
V_33 , L_25 ) ;
V_61:
F_17 ( V_30 ) ;
V_50:
free ( V_17 ) ;
V_54:
free ( V_39 ) ;
V_49:
free ( V_34 ) ;
V_48:
if ( V_35 )
free ( V_31 ) ;
V_45:
return V_26 ;
}
