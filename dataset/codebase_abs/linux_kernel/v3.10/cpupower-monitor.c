static void F_1 ( void )
{
printf ( _ ( L_1 ) ) ;
exit ( V_1 ) ;
}
long long F_2 ( struct V_2 V_3 , struct V_2 V_4 )
{
struct V_2 V_5 ;
if ( ( V_4 . V_6 - V_3 . V_6 ) < 0 ) {
V_5 . V_7 = V_4 . V_7 - V_3 . V_7 - 1 ;
V_5 . V_6 = 1000000000 + V_4 . V_6 - V_3 . V_6 ;
} else {
V_5 . V_7 = V_4 . V_7 - V_3 . V_7 ;
V_5 . V_6 = V_4 . V_6 - V_3 . V_6 ;
}
return ( V_5 . V_7 * 1000000 ) + ( V_5 . V_6 / 1000 ) ;
}
void F_3 ( int V_8 )
{
int V_9 ;
for ( V_9 = 0 ; V_9 < V_8 ; V_9 ++ )
printf ( L_2 ) ;
}
int F_4 ( char * V_10 , int V_8 )
{
int V_11 = strlen ( V_10 ) ;
if ( V_11 > V_8 )
return - 1 ;
for (; V_11 < V_8 ; V_11 ++ )
V_10 [ V_11 ] = ' ' ;
V_10 [ V_11 ] = '\0' ;
return 0 ;
}
void F_5 ( int V_12 )
{
int unsigned V_13 ;
int V_14 , V_15 ;
T_1 V_10 ;
char V_16 [ 128 ] = L_3 ;
int V_17 = 4 ;
F_4 ( V_16 , V_12 * 5 - 1 ) ;
printf ( L_4 , V_16 ) ;
for ( V_13 = 0 ; V_13 < V_18 ; V_13 ++ ) {
V_15 = V_19 [ V_13 ] -> V_20 * ( V_17 + 3 )
- 1 ;
if ( V_13 != 0 ) {
printf ( L_5 ) ;
V_15 -- ;
}
sprintf ( V_16 , L_6 , V_19 [ V_13 ] -> V_21 ) ;
F_4 ( V_16 , V_15 ) ;
printf ( L_6 , V_16 ) ;
}
printf ( L_7 ) ;
if ( V_12 > 2 )
printf ( L_8 ) ;
if ( V_12 > 1 )
printf ( L_9 ) ;
if ( V_12 > 0 )
printf ( L_10 ) ;
for ( V_13 = 0 ; V_13 < V_18 ; V_13 ++ ) {
if ( V_13 != 0 )
printf ( L_5 ) ;
else
printf ( L_2 ) ;
for ( V_14 = 0 ; V_14 < V_19 [ V_13 ] -> V_20 ; V_14 ++ ) {
if ( V_14 != 0 )
printf ( L_11 ) ;
V_10 = V_19 [ V_13 ] -> V_22 [ V_14 ] ;
sprintf ( V_16 , L_6 , V_10 . V_21 ) ;
F_4 ( V_16 , V_17 ) ;
printf ( L_6 , V_16 ) ;
}
printf ( L_2 ) ;
}
printf ( L_7 ) ;
}
void F_6 ( int V_12 , int V_23 )
{
unsigned int V_13 ;
int V_14 , V_24 ;
double V_25 ;
unsigned long long V_26 ;
T_1 V_10 ;
if ( ! F_7 ( V_27 , V_28 . V_29 [ V_23 ] . V_23 ) )
return;
if ( V_12 > 2 )
printf ( L_12 , V_28 . V_29 [ V_23 ] . V_30 ) ;
if ( V_12 > 1 )
printf ( L_12 , V_28 . V_29 [ V_23 ] . V_31 ) ;
if ( V_12 > 0 )
printf ( L_12 , V_28 . V_29 [ V_23 ] . V_23 ) ;
for ( V_13 = 0 ; V_13 < V_18 ; V_13 ++ ) {
if ( V_13 != 0 )
printf ( L_13 ) ;
for ( V_14 = 0 ; V_14 < V_19 [ V_13 ] -> V_20 ; V_14 ++ ) {
if ( V_14 != 0 )
printf ( L_14 ) ;
V_10 = V_19 [ V_13 ] -> V_22 [ V_14 ] ;
if ( V_10 . V_32 ) {
V_24 = V_10 . V_32 ( V_10 . V_33 , & V_25 ,
V_28 . V_29 [ V_23 ] . V_23 ) ;
if ( V_24 )
printf ( L_15 ) ;
else if ( V_25 >= 100.0 )
printf ( L_16 , V_25 ) ;
else
printf ( L_17 , V_25 ) ;
} else if ( V_10 . V_34 ) {
V_24 = V_10 . V_34 ( V_10 . V_33 , & V_26 ,
V_28 . V_29 [ V_23 ] . V_23 ) ;
if ( V_24 )
printf ( L_15 ) ;
else
printf ( L_18 , V_26 ) ;
} else {
printf ( _ ( L_19
L_20 ) ,
V_19 [ V_13 ] -> V_21 , V_10 . V_21 ) ;
exit ( V_1 ) ;
}
}
}
if ( ! V_28 . V_29 [ V_23 ] . V_35 ) {
printf ( _ ( L_21 ) ) ;
return;
} else
printf ( L_7 ) ;
}
static void F_8 ( char * V_36 )
{
unsigned int V_37 ;
int V_13 , V_38 = 0 ;
char * V_39 = V_36 , * V_40 ;
struct V_41 * V_42 [ V_43 ] ;
for ( V_13 = 0 ; V_13 < V_43 ; V_13 ++ , V_39 = NULL ) {
V_40 = strtok ( V_39 , L_22 ) ;
if ( V_40 == NULL )
break;
if ( strlen ( V_40 ) >= V_44 ) {
printf ( _ ( L_23
L_24 ) , V_40 , V_44 ) ;
continue;
}
for ( V_37 = 0 ; V_37 < V_18 ; V_37 ++ ) {
if ( ! strcmp ( V_19 [ V_37 ] -> V_21 , V_40 ) ) {
F_9 ( L_25 , V_40 ) ;
V_42 [ V_38 ] = V_19 [ V_37 ] ;
V_38 ++ ;
}
}
}
if ( V_38 == 0 ) {
printf ( _ ( L_26
L_27 ) , V_36 ) ;
exit ( V_1 ) ;
}
memcpy ( V_19 , V_42 ,
sizeof( struct V_41 * ) * V_43 ) ;
V_18 = V_38 ;
}
void F_10 ( void )
{
unsigned int V_13 ;
int V_14 ;
T_1 V_10 ;
for ( V_13 = 0 ; V_13 < V_18 ; V_13 ++ ) {
printf ( _ ( L_28
L_29 ) ,
V_19 [ V_13 ] -> V_21 , V_19 [ V_13 ] -> V_20 ,
V_19 [ V_13 ] -> V_45 ) ;
for ( V_14 = 0 ; V_14 < V_19 [ V_13 ] -> V_20 ; V_14 ++ ) {
V_10 = V_19 [ V_13 ] -> V_22 [ V_14 ] ;
printf ( L_30 , V_10 . V_21 , V_46 [ V_10 . V_47 ] ,
F_11 ( V_10 . V_48 ) ) ;
}
}
}
int F_12 ( char * * V_49 )
{
int V_50 ;
unsigned int V_37 ;
unsigned long long V_51 ;
T_2 V_52 ;
struct V_2 V_3 , V_4 ;
V_52 = F_13 () ;
F_14 ( V_53 , & V_3 ) ;
for ( V_37 = 0 ; V_37 < V_18 ; V_37 ++ )
V_19 [ V_37 ] -> V_3 () ;
if ( ! V_52 ) {
F_15 ( V_49 [ 0 ] , V_49 ) ;
} else {
if ( V_52 == - 1 ) {
perror ( L_31 ) ;
exit ( 1 ) ;
}
signal ( V_54 , V_55 ) ;
signal ( V_56 , V_55 ) ;
if ( F_16 ( V_52 , & V_50 , 0 ) == - 1 ) {
perror ( L_32 ) ;
exit ( 1 ) ;
}
}
F_14 ( V_53 , & V_4 ) ;
for ( V_37 = 0 ; V_37 < V_18 ; V_37 ++ )
V_19 [ V_37 ] -> F_17 () ;
V_51 = F_2 ( V_3 , V_4 ) ;
if ( F_18 ( V_50 ) )
printf ( _ ( L_33 ) ,
V_49 [ 0 ] , V_51 / ( 1000.0 * 1000 ) ,
F_19 ( V_50 ) ) ;
return 0 ;
}
int F_20 ( int V_57 )
{
unsigned int V_37 ;
int V_23 ;
if ( V_58 )
for ( V_23 = 0 ; V_23 < V_59 ; V_23 ++ )
F_21 ( V_23 ) ;
for ( V_37 = 0 ; V_37 < V_18 ; V_37 ++ ) {
F_9 ( L_34 ,
V_19 [ V_37 ] -> V_21 , V_19 [ V_37 ] -> V_20 ) ;
V_19 [ V_37 ] -> V_3 () ;
}
F_22 ( V_57 ) ;
if ( V_58 )
for ( V_23 = 0 ; V_23 < V_59 ; V_23 ++ )
F_21 ( V_23 ) ;
for ( V_37 = 0 ; V_37 < V_18 ; V_37 ++ )
V_19 [ V_37 ] -> F_17 () ;
return 0 ;
}
static void F_23 ( int V_60 , char * V_49 [] )
{
int V_61 ;
V_62 = F_24 ( V_49 [ 0 ] ) ;
while ( ( V_61 = F_25 ( V_60 , V_49 , L_35 ) ) != - 1 ) {
switch ( V_61 ) {
case 'l' :
if ( V_63 )
F_1 () ;
V_63 = V_64 ;
break;
case 'i' :
if ( V_63 && V_63 != V_65 )
F_1 () ;
V_66 = atoi ( V_67 ) ;
break;
case 'm' :
if ( V_63 )
F_1 () ;
V_63 = V_65 ;
V_68 = V_67 ;
break;
case 'c' :
V_58 = 1 ;
break;
default:
F_1 () ;
}
}
if ( ! V_63 )
V_63 = V_69 ;
}
int F_26 ( int V_60 , char * * V_49 )
{
unsigned int V_37 ;
struct V_41 * V_70 ;
int V_23 ;
F_23 ( V_60 , V_49 ) ;
V_59 = F_27 ( & V_28 ) ;
if ( V_59 < 0 ) {
printf ( _ ( L_36 ) ) ;
return V_1 ;
}
if ( F_28 ( V_27 ) )
F_29 ( V_27 ) ;
F_9 ( L_37 , V_59 ) ;
for ( V_37 = 0 ; V_71 [ V_37 ] ; V_37 ++ ) {
F_9 ( L_38 , V_71 [ V_37 ] -> V_21 ) ;
V_70 = V_71 [ V_37 ] -> F_30 () ;
if ( V_70 ) {
if ( V_70 -> V_72 && ! V_73 ) {
fprintf ( V_74 , _ ( L_39
L_40 ) , V_70 -> V_21 ) ;
continue;
}
V_19 [ V_18 ] = V_70 ;
F_9 ( L_41 , V_71 [ V_37 ] -> V_21 ) ;
V_18 ++ ;
}
}
if ( V_18 == 0 ) {
printf ( _ ( L_42 ) ) ;
return 1 ;
}
if ( V_63 == V_64 ) {
F_10 () ;
exit ( V_75 ) ;
}
if ( V_63 == V_65 )
F_8 ( V_68 ) ;
F_9 ( L_43 ,
V_28 . V_76 , V_28 . V_77 , V_59 ) ;
if ( V_60 - V_78 )
F_12 ( V_49 + V_78 ) ;
else
F_20 ( V_66 ) ;
if ( V_28 . V_76 > 1 )
F_5 ( 3 ) ;
else
F_5 ( 1 ) ;
for ( V_23 = 0 ; V_23 < V_59 ; V_23 ++ ) {
if ( V_28 . V_76 > 1 )
F_6 ( 3 , V_23 ) ;
else
F_6 ( 1 , V_23 ) ;
}
for ( V_37 = 0 ; V_37 < V_18 ; V_37 ++ )
V_19 [ V_37 ] -> F_31 () ;
F_32 ( V_28 ) ;
return 0 ;
}
