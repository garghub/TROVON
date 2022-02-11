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
void F_2 ( T_1 V_7 , struct V_1 * V_8 )
{
if ( V_8 -> V_9 )
V_7 = F_3 ( V_7 ) ;
else
V_7 = F_4 ( V_7 ) ;
V_7 >>= V_8 -> V_10 ;
V_7 &= V_8 -> V_11 ;
if ( V_8 -> V_12 ) {
T_2 V_13 = ( T_2 ) ( V_7 << ( 16 - V_8 -> V_14 ) ) >>
( 16 - V_8 -> V_14 ) ;
printf ( L_1 , ( ( float ) V_13 + V_8 -> V_15 ) * V_8 -> V_16 ) ;
} else {
printf ( L_1 , ( ( float ) V_7 + V_8 -> V_15 ) * V_8 -> V_16 ) ;
}
}
void F_5 ( T_3 V_7 , struct V_1 * V_8 )
{
if ( V_8 -> V_9 )
V_7 = F_6 ( V_7 ) ;
else
V_7 = F_7 ( V_7 ) ;
V_7 >>= V_8 -> V_10 ;
V_7 &= V_8 -> V_11 ;
if ( V_8 -> V_12 ) {
T_4 V_13 = ( T_4 ) ( V_7 << ( 32 - V_8 -> V_14 ) ) >>
( 32 - V_8 -> V_14 ) ;
printf ( L_1 , ( ( float ) V_13 + V_8 -> V_15 ) * V_8 -> V_16 ) ;
} else {
printf ( L_1 , ( ( float ) V_7 + V_8 -> V_15 ) * V_8 -> V_16 ) ;
}
}
void F_8 ( T_5 V_7 , struct V_1 * V_8 )
{
if ( V_8 -> V_9 )
V_7 = F_9 ( V_7 ) ;
else
V_7 = F_10 ( V_7 ) ;
V_7 >>= V_8 -> V_10 ;
V_7 &= V_8 -> V_11 ;
if ( V_8 -> V_12 ) {
T_6 V_13 = ( T_6 ) ( V_7 << ( 64 - V_8 -> V_14 ) ) >>
( 64 - V_8 -> V_14 ) ;
if ( V_8 -> V_16 == 1.0f && V_8 -> V_15 == 0.0f )
printf ( L_2 V_17 L_3 , V_13 ) ;
else
printf ( L_1 ,
( ( float ) V_13 + V_8 -> V_15 ) * V_8 -> V_16 ) ;
} else {
printf ( L_1 , ( ( float ) V_7 + V_8 -> V_15 ) * V_8 -> V_16 ) ;
}
}
void F_11 ( char * V_18 ,
struct V_1 * V_2 ,
int V_3 )
{
int V_19 ;
for ( V_19 = 0 ; V_19 < V_3 ; V_19 ++ )
switch ( V_2 [ V_19 ] . V_4 ) {
case 2 :
F_2 ( * ( T_1 * ) ( V_18 + V_2 [ V_19 ] . V_6 ) ,
& V_2 [ V_19 ] ) ;
break;
case 4 :
F_5 ( * ( T_3 * ) ( V_18 + V_2 [ V_19 ] . V_6 ) ,
& V_2 [ V_19 ] ) ;
break;
case 8 :
F_8 ( * ( T_5 * ) ( V_18 + V_2 [ V_19 ] . V_6 ) ,
& V_2 [ V_19 ] ) ;
break;
default:
break;
}
printf ( L_4 ) ;
}
void F_12 ( void )
{
printf ( L_5
L_6
L_7
L_8
L_9
L_10
L_11
L_12
L_13 ) ;
}
int main ( int V_20 , char * * V_21 )
{
unsigned long V_22 = 2 ;
unsigned long V_23 = 1000000 ;
unsigned long V_24 = 128 ;
int V_25 , V_26 , V_5 , V_27 , V_28 ;
int V_29 ;
int V_3 ;
char * V_30 = NULL , * V_31 = NULL ;
char * V_32 , * V_33 ;
int V_34 = 1 ;
char * V_18 ;
T_7 V_35 ;
int V_36 , V_37 ;
char * V_38 ;
int V_39 ;
int V_40 = 0 ;
int V_41 = 0 ;
char * V_42 ;
struct V_1 * V_2 ;
while ( ( V_26 = F_13 ( V_20 , V_21 , L_14 ) ) != - 1 ) {
switch ( V_26 ) {
case 'c' :
V_43 = 0 ;
V_22 = strtoul ( V_44 , & V_42 , 10 ) ;
if ( V_43 )
return - V_43 ;
break;
case 'e' :
V_40 = 1 ;
break;
case 'g' :
V_41 = 1 ;
break;
case 'l' :
V_43 = 0 ;
V_24 = strtoul ( V_44 , & V_42 , 10 ) ;
if ( V_43 )
return - V_43 ;
break;
case 'n' :
V_31 = V_44 ;
break;
case 't' :
V_30 = V_44 ;
V_34 = 0 ;
break;
case 'w' :
V_43 = 0 ;
V_23 = strtoul ( V_44 , & V_42 , 10 ) ;
if ( V_43 )
return - V_43 ;
break;
case '?' :
F_12 () ;
return - 1 ;
}
}
if ( V_31 == NULL ) {
printf ( L_15 ) ;
F_12 () ;
return - 1 ;
}
V_36 = F_14 ( V_31 , L_16 ) ;
if ( V_36 < 0 ) {
printf ( L_17 , V_31 ) ;
return V_36 ;
}
printf ( L_18 , V_36 ) ;
V_25 = F_15 ( & V_32 , L_19 , V_45 , V_36 ) ;
if ( V_25 < 0 )
return - V_46 ;
if ( ! V_41 ) {
if ( V_30 == NULL ) {
V_25 = F_15 ( & V_30 ,
L_20 , V_31 , V_36 ) ;
if ( V_25 < 0 ) {
V_25 = - V_46 ;
goto V_47;
}
}
V_37 = F_14 ( V_30 , L_21 ) ;
if ( V_37 < 0 ) {
printf ( L_22 , V_30 ) ;
V_25 = V_37 ;
goto V_48;
}
printf ( L_23 , V_37 ) ;
} else
printf ( L_24 ) ;
V_25 = F_16 ( V_32 , & V_2 , & V_3 ) ;
if ( V_25 ) {
printf ( L_25 ) ;
printf ( L_26 , V_32 ) ;
goto V_48;
}
V_25 = F_15 ( & V_33 ,
L_27 , V_45 , V_36 ) ;
if ( V_25 < 0 ) {
V_25 = - V_46 ;
goto V_49;
}
if ( ! V_41 ) {
printf ( L_28 , V_32 , V_30 ) ;
V_25 = F_17 ( L_29 ,
V_32 ,
V_30 ) ;
if ( V_25 < 0 ) {
printf ( L_30 ) ;
goto V_50;
}
}
V_25 = F_18 ( L_31 , V_33 , V_24 ) ;
if ( V_25 < 0 )
goto V_50;
V_25 = F_18 ( L_32 , V_33 , 1 ) ;
if ( V_25 < 0 )
goto V_50;
V_39 = F_1 ( V_2 , V_3 ) ;
V_18 = malloc ( V_39 * V_24 ) ;
if ( ! V_18 ) {
V_25 = - V_46 ;
goto V_50;
}
V_25 = F_15 ( & V_38 , L_33 , V_36 ) ;
if ( V_25 < 0 ) {
V_25 = - V_46 ;
goto V_51;
}
V_29 = F_19 ( V_38 , V_52 | V_53 ) ;
if ( V_29 == - 1 ) {
V_25 = - V_43 ;
printf ( L_34 , V_38 ) ;
goto V_54;
}
for ( V_27 = 0 ; V_27 < V_22 ; V_27 ++ ) {
if ( ! V_40 ) {
struct V_55 V_56 = {
. V_57 = V_29 ,
. V_58 = V_59 ,
} ;
V_25 = F_20 ( & V_56 , 1 , - 1 ) ;
if ( V_25 < 0 ) {
V_25 = - V_43 ;
goto V_60;
} else if ( V_25 == 0 ) {
continue;
}
V_28 = V_24 ;
} else {
F_21 ( V_23 ) ;
V_28 = 64 ;
}
V_35 = F_22 ( V_29 ,
V_18 ,
V_28 * V_39 ) ;
if ( V_35 < 0 ) {
if ( V_43 == V_61 ) {
printf ( L_35 ) ;
continue;
} else
break;
}
for ( V_5 = 0 ; V_5 < V_35 / V_39 ; V_5 ++ )
F_11 ( V_18 + V_39 * V_5 ,
V_2 ,
V_3 ) ;
}
V_25 = F_18 ( L_32 , V_33 , 0 ) ;
if ( V_25 < 0 )
goto V_60;
if ( ! V_41 )
V_25 = F_23 ( L_29 ,
V_32 , L_36 ) ;
if ( V_25 < 0 )
printf ( L_37 , V_32 ) ;
V_60:
if ( F_24 ( V_29 ) == - 1 )
perror ( L_38 ) ;
V_54:
free ( V_38 ) ;
V_51:
free ( V_18 ) ;
V_50:
free ( V_33 ) ;
V_49:
for ( V_5 = V_3 - 1 ; V_5 >= 0 ; V_5 -- ) {
free ( V_2 [ V_5 ] . V_62 ) ;
free ( V_2 [ V_5 ] . V_63 ) ;
}
free ( V_2 ) ;
V_48:
if ( V_34 )
free ( V_30 ) ;
V_47:
free ( V_32 ) ;
return V_25 ;
}
