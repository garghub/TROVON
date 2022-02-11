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
V_7 >>= V_8 -> V_9 ;
V_7 &= V_8 -> V_10 ;
if ( V_8 -> V_11 ) {
T_2 V_12 = ( T_2 ) ( V_7 << ( 8 - V_8 -> V_13 ) ) >>
( 8 - V_8 -> V_13 ) ;
printf ( L_1 , ( ( float ) V_12 + V_8 -> V_14 ) * V_8 -> V_15 ) ;
} else {
printf ( L_1 , ( ( float ) V_7 + V_8 -> V_14 ) * V_8 -> V_15 ) ;
}
}
void F_3 ( T_3 V_7 , struct V_1 * V_8 )
{
if ( V_8 -> V_16 )
V_7 = F_4 ( V_7 ) ;
else
V_7 = F_5 ( V_7 ) ;
V_7 >>= V_8 -> V_9 ;
V_7 &= V_8 -> V_10 ;
if ( V_8 -> V_11 ) {
T_4 V_12 = ( T_4 ) ( V_7 << ( 16 - V_8 -> V_13 ) ) >>
( 16 - V_8 -> V_13 ) ;
printf ( L_1 , ( ( float ) V_12 + V_8 -> V_14 ) * V_8 -> V_15 ) ;
} else {
printf ( L_1 , ( ( float ) V_7 + V_8 -> V_14 ) * V_8 -> V_15 ) ;
}
}
void F_6 ( T_5 V_7 , struct V_1 * V_8 )
{
if ( V_8 -> V_16 )
V_7 = F_7 ( V_7 ) ;
else
V_7 = F_8 ( V_7 ) ;
V_7 >>= V_8 -> V_9 ;
V_7 &= V_8 -> V_10 ;
if ( V_8 -> V_11 ) {
T_6 V_12 = ( T_6 ) ( V_7 << ( 32 - V_8 -> V_13 ) ) >>
( 32 - V_8 -> V_13 ) ;
printf ( L_1 , ( ( float ) V_12 + V_8 -> V_14 ) * V_8 -> V_15 ) ;
} else {
printf ( L_1 , ( ( float ) V_7 + V_8 -> V_14 ) * V_8 -> V_15 ) ;
}
}
void F_9 ( T_7 V_7 , struct V_1 * V_8 )
{
if ( V_8 -> V_16 )
V_7 = F_10 ( V_7 ) ;
else
V_7 = F_11 ( V_7 ) ;
V_7 >>= V_8 -> V_9 ;
V_7 &= V_8 -> V_10 ;
if ( V_8 -> V_11 ) {
T_8 V_12 = ( T_8 ) ( V_7 << ( 64 - V_8 -> V_13 ) ) >>
( 64 - V_8 -> V_13 ) ;
if ( V_8 -> V_15 == 1.0f && V_8 -> V_14 == 0.0f )
printf ( L_2 V_17 L_3 , V_12 ) ;
else
printf ( L_1 ,
( ( float ) V_12 + V_8 -> V_14 ) * V_8 -> V_15 ) ;
} else {
printf ( L_1 , ( ( float ) V_7 + V_8 -> V_14 ) * V_8 -> V_15 ) ;
}
}
void F_12 ( char * V_18 ,
struct V_1 * V_2 ,
int V_3 )
{
int V_19 ;
for ( V_19 = 0 ; V_19 < V_3 ; V_19 ++ )
switch ( V_2 [ V_19 ] . V_4 ) {
case 1 :
F_2 ( * ( T_1 * ) ( V_18 + V_2 [ V_19 ] . V_6 ) ,
& V_2 [ V_19 ] ) ;
break;
case 2 :
F_3 ( * ( T_3 * ) ( V_18 + V_2 [ V_19 ] . V_6 ) ,
& V_2 [ V_19 ] ) ;
break;
case 4 :
F_6 ( * ( T_5 * ) ( V_18 + V_2 [ V_19 ] . V_6 ) ,
& V_2 [ V_19 ] ) ;
break;
case 8 :
F_9 ( * ( T_7 * ) ( V_18 + V_2 [ V_19 ] . V_6 ) ,
& V_2 [ V_19 ] ) ;
break;
default:
break;
}
printf ( L_4 ) ;
}
void F_13 ( void )
{
fprintf ( V_20 , L_5
L_6
L_7
L_8
L_9
L_10
L_11
L_12
L_13 ) ;
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
char * V_18 ;
T_9 V_36 ;
int V_37 , V_38 ;
char * V_39 ;
int V_40 ;
int V_41 = 0 ;
int V_42 = 0 ;
char * V_43 ;
struct V_1 * V_2 ;
while ( ( V_27 = F_14 ( V_21 , V_22 , L_14 ) ) != - 1 ) {
switch ( V_27 ) {
case 'c' :
V_44 = 0 ;
V_23 = strtoul ( V_45 , & V_43 , 10 ) ;
if ( V_44 )
return - V_44 ;
break;
case 'e' :
V_41 = 1 ;
break;
case 'g' :
V_42 = 1 ;
break;
case 'l' :
V_44 = 0 ;
V_25 = strtoul ( V_45 , & V_43 , 10 ) ;
if ( V_44 )
return - V_44 ;
break;
case 'n' :
V_32 = V_45 ;
break;
case 't' :
V_31 = V_45 ;
V_35 = 0 ;
break;
case 'w' :
V_44 = 0 ;
V_24 = strtoul ( V_45 , & V_43 , 10 ) ;
if ( V_44 )
return - V_44 ;
break;
case '?' :
F_13 () ;
return - 1 ;
}
}
if ( ! V_32 ) {
fprintf ( V_20 , L_15 ) ;
F_13 () ;
return - 1 ;
}
V_37 = F_15 ( V_32 , L_16 ) ;
if ( V_37 < 0 ) {
fprintf ( V_20 , L_17 , V_32 ) ;
return V_37 ;
}
printf ( L_18 , V_37 ) ;
V_26 = F_16 ( & V_33 , L_19 , V_46 , V_37 ) ;
if ( V_26 < 0 )
return - V_47 ;
if ( ! V_42 ) {
if ( ! V_31 ) {
V_26 = F_16 ( & V_31 ,
L_20 , V_32 , V_37 ) ;
if ( V_26 < 0 ) {
V_26 = - V_47 ;
goto V_48;
}
}
V_38 = F_15 ( V_31 , L_21 ) ;
if ( V_38 < 0 ) {
fprintf ( V_20 , L_22 ,
V_31 ) ;
V_26 = V_38 ;
goto V_49;
}
printf ( L_23 , V_38 ) ;
} else {
printf ( L_24 ) ;
}
V_26 = F_17 ( V_33 , & V_2 , & V_3 ) ;
if ( V_26 ) {
fprintf ( V_20 , L_25
L_26 , V_33 ) ;
goto V_49;
}
if ( ! V_3 ) {
fprintf ( V_20 ,
L_27 ) ;
fprintf ( V_20 , L_28
V_50
L_29 , V_33 ) ;
V_26 = - V_51 ;
goto V_49;
}
V_26 = F_16 ( & V_34 ,
L_30 , V_46 , V_37 ) ;
if ( V_26 < 0 ) {
V_26 = - V_47 ;
goto V_52;
}
if ( ! V_42 ) {
printf ( L_31 , V_33 , V_31 ) ;
V_26 = F_18 ( L_32 ,
V_33 ,
V_31 ) ;
if ( V_26 < 0 ) {
fprintf ( V_20 ,
L_33 ) ;
goto V_53;
}
}
V_26 = F_19 ( L_34 , V_34 , V_25 ) ;
if ( V_26 < 0 )
goto V_53;
V_26 = F_19 ( L_35 , V_34 , 1 ) ;
if ( V_26 < 0 ) {
fprintf ( V_20 ,
L_36 , strerror ( - V_26 ) ) ;
goto V_53;
}
V_40 = F_1 ( V_2 , V_3 ) ;
V_18 = malloc ( V_40 * V_25 ) ;
if ( ! V_18 ) {
V_26 = - V_47 ;
goto V_53;
}
V_26 = F_16 ( & V_39 , L_37 , V_37 ) ;
if ( V_26 < 0 ) {
V_26 = - V_47 ;
goto V_54;
}
V_30 = F_20 ( V_39 , V_55 | V_56 ) ;
if ( V_30 == - 1 ) {
V_26 = - V_44 ;
fprintf ( V_20 , L_38 , V_39 ) ;
goto V_57;
}
for ( V_28 = 0 ; V_28 < V_23 ; V_28 ++ ) {
if ( ! V_41 ) {
struct V_58 V_59 = {
. V_60 = V_30 ,
. V_61 = V_62 ,
} ;
V_26 = F_21 ( & V_59 , 1 , - 1 ) ;
if ( V_26 < 0 ) {
V_26 = - V_44 ;
goto V_63;
} else if ( V_26 == 0 ) {
continue;
}
V_29 = V_25 ;
} else {
F_22 ( V_24 ) ;
V_29 = 64 ;
}
V_36 = F_23 ( V_30 , V_18 , V_29 * V_40 ) ;
if ( V_36 < 0 ) {
if ( V_44 == V_64 ) {
fprintf ( V_20 , L_39 ) ;
continue;
} else {
break;
}
}
for ( V_5 = 0 ; V_5 < V_36 / V_40 ; V_5 ++ )
F_12 ( V_18 + V_40 * V_5 , V_2 ,
V_3 ) ;
}
V_26 = F_19 ( L_35 , V_34 , 0 ) ;
if ( V_26 < 0 )
goto V_63;
if ( ! V_42 )
V_26 = F_24 ( L_32 ,
V_33 , L_40 ) ;
if ( V_26 < 0 )
fprintf ( V_20 , L_41 ,
V_33 ) ;
V_63:
if ( F_25 ( V_30 ) == - 1 )
perror ( L_42 ) ;
V_57:
free ( V_39 ) ;
V_54:
free ( V_18 ) ;
V_53:
free ( V_34 ) ;
V_52:
for ( V_5 = V_3 - 1 ; V_5 >= 0 ; V_5 -- ) {
free ( V_2 [ V_5 ] . V_65 ) ;
free ( V_2 [ V_5 ] . V_66 ) ;
}
free ( V_2 ) ;
V_49:
if ( V_35 )
free ( V_31 ) ;
V_48:
free ( V_33 ) ;
return V_26 ;
}
