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
static int F_13 ( char * V_20 , int V_21 )
{
const struct V_22 * V_23 ;
char V_24 [ 256 ] ;
T_9 * V_25 ;
int V_26 ;
snprintf ( V_24 , sizeof( V_24 ) ,
V_27 , V_20 ) ;
V_24 [ sizeof( V_24 ) - 1 ] = '\0' ;
V_25 = F_14 ( V_24 ) ;
if ( ! V_25 ) {
fprintf ( V_28 , L_5 ,
V_24 ) ;
return - V_29 ;
}
V_26 = - V_30 ;
while ( V_23 = F_15 ( V_25 ) , V_23 ) {
if ( F_16 ( V_23 -> V_31 , L_6 ) ) {
printf ( L_7 ,
V_21 ? L_8 : L_9 ,
V_23 -> V_31 ) ;
V_26 = F_17 ( V_23 -> V_31 , V_24 ,
V_21 ) ;
if ( V_26 < 0 )
fprintf ( V_28 , L_10 ,
V_23 -> V_31 ) ;
}
}
if ( F_18 ( V_25 ) == - 1 ) {
perror ( L_11
L_12 ) ;
return - V_32 ;
}
return 0 ;
}
void F_19 ( void )
{
fprintf ( V_28 , L_13
L_14
L_15
L_16
L_17
L_18
L_19
L_20
L_21
L_22 ) ;
}
int main ( int V_33 , char * * V_34 )
{
unsigned long V_35 = 2 ;
unsigned long V_36 = 1000000 ;
unsigned long V_37 = 128 ;
int V_26 , V_38 , V_5 , V_39 , V_40 ;
int V_41 ;
int V_3 ;
char * V_42 = NULL , * V_43 = NULL ;
char * V_20 , * V_44 ;
int V_45 = 1 ;
char * V_18 ;
T_10 V_46 ;
int V_47 , V_48 ;
char * V_49 ;
int V_50 ;
int V_51 = 0 ;
int V_52 = 0 ;
enum V_53 V_54 = V_55 ;
char * V_56 ;
struct V_1 * V_2 ;
while ( ( V_38 = F_20 ( V_33 , V_34 , L_23 ) ) != - 1 ) {
switch ( V_38 ) {
case 'a' :
V_54 = V_57 ;
break;
case 'c' :
V_32 = 0 ;
V_35 = strtoul ( V_58 , & V_56 , 10 ) ;
if ( V_32 )
return - V_32 ;
break;
case 'e' :
V_51 = 1 ;
break;
case 'g' :
V_52 = 1 ;
break;
case 'l' :
V_32 = 0 ;
V_37 = strtoul ( V_58 , & V_56 , 10 ) ;
if ( V_32 )
return - V_32 ;
break;
case 'n' :
V_43 = V_58 ;
break;
case 't' :
V_42 = V_58 ;
V_45 = 0 ;
break;
case 'w' :
V_32 = 0 ;
V_36 = strtoul ( V_58 , & V_56 , 10 ) ;
if ( V_32 )
return - V_32 ;
break;
case '?' :
F_19 () ;
return - 1 ;
}
}
if ( ! V_43 ) {
fprintf ( V_28 , L_24 ) ;
F_19 () ;
return - 1 ;
}
V_47 = F_21 ( V_43 , L_25 ) ;
if ( V_47 < 0 ) {
fprintf ( V_28 , L_26 , V_43 ) ;
return V_47 ;
}
printf ( L_27 , V_47 ) ;
V_26 = F_22 ( & V_20 , L_28 , V_59 , V_47 ) ;
if ( V_26 < 0 )
return - V_60 ;
if ( ! V_52 ) {
if ( ! V_42 ) {
V_26 = F_22 ( & V_42 ,
L_29 , V_43 , V_47 ) ;
if ( V_26 < 0 ) {
V_26 = - V_60 ;
goto V_61;
}
}
V_48 = F_21 ( V_42 , L_30 ) ;
if ( V_48 < 0 ) {
free ( V_42 ) ;
V_26 = F_22 ( & V_42 ,
L_31 , V_43 ) ;
if ( V_26 < 0 ) {
V_26 = - V_60 ;
goto V_61;
}
}
V_48 = F_21 ( V_42 , L_30 ) ;
if ( V_48 < 0 ) {
fprintf ( V_28 , L_32 ,
V_42 ) ;
V_26 = V_48 ;
goto V_62;
}
printf ( L_33 , V_48 ) ;
} else {
printf ( L_34 ) ;
}
V_26 = F_23 ( V_20 , & V_2 , & V_3 ) ;
if ( V_26 ) {
fprintf ( V_28 , L_35
L_36 , V_20 ) ;
goto V_62;
}
if ( V_3 && V_54 == V_57 ) {
fprintf ( V_28 , L_37
L_38 ) ;
fprintf ( V_28 , L_39 ) ;
}
if ( ! V_3 && V_54 == V_57 ) {
fprintf ( V_28 ,
L_40 ) ;
V_26 = F_13 ( V_20 , 1 ) ;
if ( V_26 ) {
fprintf ( V_28 , L_41 ) ;
goto V_62;
}
V_54 = V_63 ;
V_26 = F_23 ( V_20 , & V_2 ,
& V_3 ) ;
if ( V_26 ) {
fprintf ( V_28 , L_42
L_43
L_36 , V_20 ) ;
goto V_64;
}
if ( ! V_3 ) {
fprintf ( V_28 , L_44
L_45 ) ;
goto V_64;
}
}
if ( ! V_3 && V_54 == V_55 ) {
fprintf ( V_28 ,
L_46 ) ;
fprintf ( V_28 , L_47
V_27
L_48
L_49 , V_20 ) ;
V_26 = - V_30 ;
goto V_62;
}
V_26 = F_22 ( & V_44 ,
L_50 , V_59 , V_47 ) ;
if ( V_26 < 0 ) {
V_26 = - V_60 ;
goto V_65;
}
if ( ! V_52 ) {
printf ( L_51 , V_20 , V_42 ) ;
V_26 = F_24 ( L_52 ,
V_20 ,
V_42 ) ;
if ( V_26 < 0 ) {
fprintf ( V_28 ,
L_53 ) ;
goto V_66;
}
}
V_26 = F_17 ( L_54 , V_44 , V_37 ) ;
if ( V_26 < 0 )
goto V_66;
V_26 = F_17 ( L_55 , V_44 , 1 ) ;
if ( V_26 < 0 ) {
fprintf ( V_28 ,
L_56 , strerror ( - V_26 ) ) ;
goto V_66;
}
V_50 = F_1 ( V_2 , V_3 ) ;
V_18 = malloc ( V_50 * V_37 ) ;
if ( ! V_18 ) {
V_26 = - V_60 ;
goto V_66;
}
V_26 = F_22 ( & V_49 , L_57 , V_47 ) ;
if ( V_26 < 0 ) {
V_26 = - V_60 ;
goto V_67;
}
V_41 = F_25 ( V_49 , V_68 | V_69 ) ;
if ( V_41 == - 1 ) {
V_26 = - V_32 ;
fprintf ( V_28 , L_58 , V_49 ) ;
goto V_70;
}
for ( V_39 = 0 ; V_39 < V_35 ; V_39 ++ ) {
if ( ! V_51 ) {
struct V_71 V_72 = {
. V_73 = V_41 ,
. V_74 = V_75 ,
} ;
V_26 = F_26 ( & V_72 , 1 , - 1 ) ;
if ( V_26 < 0 ) {
V_26 = - V_32 ;
goto V_76;
} else if ( V_26 == 0 ) {
continue;
}
V_40 = V_37 ;
} else {
F_27 ( V_36 ) ;
V_40 = 64 ;
}
V_46 = F_28 ( V_41 , V_18 , V_40 * V_50 ) ;
if ( V_46 < 0 ) {
if ( V_32 == V_77 ) {
fprintf ( V_28 , L_59 ) ;
continue;
} else {
break;
}
}
for ( V_5 = 0 ; V_5 < V_46 / V_50 ; V_5 ++ )
F_12 ( V_18 + V_50 * V_5 , V_2 ,
V_3 ) ;
}
V_26 = F_17 ( L_55 , V_44 , 0 ) ;
if ( V_26 < 0 )
goto V_76;
if ( ! V_52 )
V_26 = F_29 ( L_52 ,
V_20 , L_60 ) ;
if ( V_26 < 0 )
fprintf ( V_28 , L_61 ,
V_20 ) ;
V_76:
if ( F_30 ( V_41 ) == - 1 )
perror ( L_62 ) ;
V_70:
free ( V_49 ) ;
V_67:
free ( V_18 ) ;
V_66:
free ( V_44 ) ;
V_65:
for ( V_5 = V_3 - 1 ; V_5 >= 0 ; V_5 -- ) {
free ( V_2 [ V_5 ] . V_78 ) ;
free ( V_2 [ V_5 ] . V_79 ) ;
}
free ( V_2 ) ;
V_62:
if ( V_45 )
free ( V_42 ) ;
V_64:
if ( V_54 == V_63 ) {
V_26 = F_13 ( V_20 , 0 ) ;
if ( V_26 )
fprintf ( V_28 , L_63 ) ;
}
V_61:
free ( V_20 ) ;
return V_26 ;
}
