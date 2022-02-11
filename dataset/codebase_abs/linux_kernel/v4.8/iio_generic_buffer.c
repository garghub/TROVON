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
L_22
L_23
L_24
L_25
L_26 ) ;
}
void F_20 ( void )
{
int V_26 ;
if ( V_20 && V_33 ) {
V_26 = F_21 ( L_27 ,
V_20 , L_28 ) ;
if ( V_26 < 0 )
fprintf ( V_28 , L_29 ,
strerror ( - V_26 ) ) ;
V_33 = false ;
}
if ( V_34 ) {
V_26 = F_17 ( L_30 , V_34 , 0 ) ;
if ( V_26 < 0 )
fprintf ( V_28 , L_31 ,
strerror ( - V_26 ) ) ;
}
if ( V_20 && V_35 == V_36 ) {
V_26 = F_13 ( V_20 , 0 ) ;
if ( V_26 )
fprintf ( V_28 , L_32 ) ;
V_35 = V_37 ;
}
}
void F_22 ( int V_38 )
{
fprintf ( V_28 , L_33 , V_38 ) ;
F_20 () ;
exit ( - V_38 ) ;
}
void F_23 ( void )
{
struct V_39 V_40 = { . V_41 = F_22 } ;
const int V_42 [] = { V_43 , V_44 , V_45 } ;
int V_26 , V_5 ;
for ( V_5 = 0 ; V_5 < F_24 ( V_42 ) ; ++ V_5 ) {
V_26 = V_39 ( V_42 [ V_5 ] , & V_40 , NULL ) ;
if ( V_26 ) {
perror ( L_34 ) ;
exit ( - 1 ) ;
}
}
}
int main ( int V_46 , char * * V_47 )
{
unsigned long V_48 = 2 ;
unsigned long V_49 = 1000000 ;
unsigned long V_50 = 128 ;
int V_26 , V_51 , V_5 , V_52 , V_53 ;
int V_54 = - 1 ;
int V_3 = 0 ;
char * V_55 = NULL , * V_56 = NULL ;
char * V_18 = NULL ;
T_10 V_57 ;
int V_58 = - 1 , V_59 = - 1 ;
char * V_60 = NULL ;
int V_61 ;
int V_62 = 0 ;
int V_63 = 0 ;
char * V_64 ;
struct V_1 * V_2 = NULL ;
F_23 () ;
while ( ( V_51 = F_25 ( V_46 , V_47 , L_35 , V_65 , NULL ) ) != - 1 ) {
switch ( V_51 ) {
case 'a' :
V_35 = V_66 ;
break;
case 'c' :
V_32 = 0 ;
V_48 = strtoul ( V_67 , & V_64 , 10 ) ;
if ( V_32 ) {
V_26 = - V_32 ;
goto error;
}
break;
case 'e' :
V_62 = 1 ;
break;
case 'g' :
V_63 = 1 ;
break;
case 'l' :
V_32 = 0 ;
V_50 = strtoul ( V_67 , & V_64 , 10 ) ;
if ( V_32 ) {
V_26 = - V_32 ;
goto error;
}
break;
case 'n' :
V_56 = F_26 ( V_67 ) ;
break;
case 'N' :
V_32 = 0 ;
V_58 = strtoul ( V_67 , & V_64 , 10 ) ;
if ( V_32 ) {
V_26 = - V_32 ;
goto error;
}
break;
case 't' :
V_55 = F_26 ( V_67 ) ;
break;
case 'T' :
V_32 = 0 ;
V_59 = strtoul ( V_67 , & V_64 , 10 ) ;
if ( V_32 )
return - V_32 ;
break;
case 'w' :
V_32 = 0 ;
V_49 = strtoul ( V_67 , & V_64 , 10 ) ;
if ( V_32 ) {
V_26 = - V_32 ;
goto error;
}
break;
case '?' :
F_19 () ;
V_26 = - 1 ;
goto error;
}
}
if ( V_58 < 0 && ! V_56 ) {
fprintf ( V_28 , L_36 ) ;
F_19 () ;
V_26 = - 1 ;
goto error;
} else if ( V_58 >= 0 && V_56 ) {
fprintf ( V_28 , L_37 ) ;
F_19 () ;
V_26 = - 1 ;
goto error;
} else if ( V_58 < 0 ) {
V_58 = F_27 ( V_56 , L_38 ) ;
if ( V_58 < 0 ) {
fprintf ( V_28 , L_39 , V_56 ) ;
V_26 = V_58 ;
goto error;
}
}
printf ( L_40 , V_58 ) ;
V_26 = F_28 ( & V_20 , L_41 , V_68 , V_58 ) ;
if ( V_26 < 0 )
return - V_69 ;
if ( ! V_56 ) {
V_56 = malloc ( V_70 ) ;
if ( ! V_56 ) {
V_26 = - V_69 ;
goto error;
}
V_26 = F_29 ( L_42 , V_20 , V_56 ) ;
if ( V_26 < 0 ) {
fprintf ( V_28 , L_43 , V_58 ) ;
goto error;
}
}
if ( V_63 ) {
printf ( L_44 ) ;
} else if ( V_59 >= 0 ) {
char * V_71 ;
V_26 = F_28 ( & V_71 , L_45 , V_68 , V_59 ) ;
if ( V_26 < 0 ) {
return - V_69 ;
}
V_55 = malloc ( V_70 ) ;
V_26 = F_29 ( L_42 , V_71 , V_55 ) ;
free ( V_71 ) ;
if ( V_26 < 0 ) {
fprintf ( V_28 , L_46 , V_59 ) ;
return V_26 ;
}
printf ( L_47 , V_59 ) ;
} else {
if ( ! V_55 ) {
V_26 = F_28 ( & V_55 ,
L_48 , V_56 , V_58 ) ;
if ( V_26 < 0 ) {
V_26 = - V_69 ;
goto error;
}
}
V_59 = F_27 ( V_55 , L_49 ) ;
if ( V_59 < 0 ) {
free ( V_55 ) ;
V_26 = F_28 ( & V_55 ,
L_50 , V_56 ) ;
if ( V_26 < 0 ) {
V_26 = - V_69 ;
goto error;
}
}
V_59 = F_27 ( V_55 , L_49 ) ;
if ( V_59 < 0 ) {
fprintf ( V_28 , L_51 ,
V_55 ) ;
V_26 = V_59 ;
goto error;
}
printf ( L_47 , V_59 ) ;
}
V_26 = F_30 ( V_20 , & V_2 , & V_3 ) ;
if ( V_26 ) {
fprintf ( V_28 , L_52
L_53 , V_20 ) ;
goto error;
}
if ( V_3 && V_35 == V_66 ) {
fprintf ( V_28 , L_54
L_55 ) ;
fprintf ( V_28 , L_56 ) ;
}
if ( ! V_3 && V_35 == V_66 ) {
fprintf ( V_28 ,
L_57 ) ;
V_26 = F_13 ( V_20 , 1 ) ;
if ( V_26 ) {
fprintf ( V_28 , L_58 ) ;
goto error;
}
V_35 = V_36 ;
V_26 = F_30 ( V_20 , & V_2 ,
& V_3 ) ;
if ( V_26 ) {
fprintf ( V_28 , L_59
L_60
L_53 , V_20 ) ;
goto error;
}
if ( ! V_3 ) {
fprintf ( V_28 , L_61
L_62 ) ;
goto error;
}
}
if ( ! V_3 && V_35 == V_37 ) {
fprintf ( V_28 ,
L_63 ) ;
fprintf ( V_28 , L_64
V_27
L_65
L_66 , V_20 ) ;
V_26 = - V_30 ;
goto error;
}
V_26 = F_28 ( & V_34 ,
L_67 , V_68 , V_58 ) ;
if ( V_26 < 0 ) {
V_26 = - V_69 ;
goto error;
}
if ( ! V_63 ) {
printf ( L_68 , V_20 , V_55 ) ;
V_26 = F_31 ( L_27 ,
V_20 ,
V_55 ) ;
if ( V_26 < 0 ) {
fprintf ( V_28 ,
L_69 ) ;
goto error;
}
}
V_26 = F_17 ( L_70 , V_34 , V_50 ) ;
if ( V_26 < 0 )
goto error;
V_26 = F_17 ( L_30 , V_34 , 1 ) ;
if ( V_26 < 0 ) {
fprintf ( V_28 ,
L_71 , strerror ( - V_26 ) ) ;
goto error;
}
V_61 = F_1 ( V_2 , V_3 ) ;
V_18 = malloc ( V_61 * V_50 ) ;
if ( ! V_18 ) {
V_26 = - V_69 ;
goto error;
}
V_26 = F_28 ( & V_60 , L_72 , V_58 ) ;
if ( V_26 < 0 ) {
V_26 = - V_69 ;
goto error;
}
V_54 = F_32 ( V_60 , V_72 | V_73 ) ;
if ( V_54 == - 1 ) {
V_26 = - V_32 ;
fprintf ( V_28 , L_73 , V_60 ) ;
goto error;
}
for ( V_52 = 0 ; V_52 < V_48 ; V_52 ++ ) {
if ( ! V_62 ) {
struct V_74 V_75 = {
. V_76 = V_54 ,
. V_77 = V_78 ,
} ;
V_26 = F_33 ( & V_75 , 1 , - 1 ) ;
if ( V_26 < 0 ) {
V_26 = - V_32 ;
goto error;
} else if ( V_26 == 0 ) {
continue;
}
V_53 = V_50 ;
} else {
F_34 ( V_49 ) ;
V_53 = 64 ;
}
V_57 = F_35 ( V_54 , V_18 , V_53 * V_61 ) ;
if ( V_57 < 0 ) {
if ( V_32 == V_79 ) {
fprintf ( V_28 , L_74 ) ;
continue;
} else {
break;
}
}
for ( V_5 = 0 ; V_5 < V_57 / V_61 ; V_5 ++ )
F_12 ( V_18 + V_61 * V_5 , V_2 ,
V_3 ) ;
}
error:
F_20 () ;
if ( V_54 >= 0 && F_36 ( V_54 ) == - 1 )
perror ( L_75 ) ;
free ( V_60 ) ;
free ( V_18 ) ;
free ( V_34 ) ;
for ( V_5 = V_3 - 1 ; V_5 >= 0 ; V_5 -- ) {
free ( V_2 [ V_5 ] . V_80 ) ;
free ( V_2 [ V_5 ] . V_81 ) ;
}
free ( V_2 ) ;
free ( V_55 ) ;
free ( V_56 ) ;
free ( V_20 ) ;
return V_26 ;
}
