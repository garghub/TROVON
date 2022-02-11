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
int V_14 , V_15 , V_16 ;
T_1 V_10 ;
char V_17 [ 128 ] = L_3 ;
int V_18 = 4 ;
F_4 ( V_17 , V_12 * 5 - 1 ) ;
printf ( L_4 , V_17 ) ;
for ( V_13 = 0 ; V_13 < V_19 ; V_13 ++ ) {
V_16 = 0 ;
V_15 = V_20 [ V_13 ] -> V_21 * ( V_18 + 3 )
- 1 ;
if ( V_13 != 0 ) {
printf ( L_5 ) ;
V_15 -- ;
}
sprintf ( V_17 , L_6 , V_20 [ V_13 ] -> V_22 ) ;
F_4 ( V_17 , V_15 ) ;
printf ( L_6 , V_17 ) ;
}
printf ( L_7 ) ;
if ( V_12 > 2 )
printf ( L_8 ) ;
if ( V_12 > 1 )
printf ( L_9 ) ;
if ( V_12 > 0 )
printf ( L_10 ) ;
for ( V_13 = 0 ; V_13 < V_19 ; V_13 ++ ) {
if ( V_13 != 0 )
printf ( L_5 ) ;
else
printf ( L_2 ) ;
for ( V_14 = 0 ; V_14 < V_20 [ V_13 ] -> V_21 ; V_14 ++ ) {
if ( V_14 != 0 )
printf ( L_11 ) ;
V_10 = V_20 [ V_13 ] -> V_23 [ V_14 ] ;
sprintf ( V_17 , L_6 , V_10 . V_22 ) ;
F_4 ( V_17 , V_18 ) ;
printf ( L_6 , V_17 ) ;
}
printf ( L_2 ) ;
}
printf ( L_7 ) ;
}
void F_6 ( int V_12 , int V_24 )
{
unsigned int V_13 ;
int V_14 , V_25 ;
double V_26 ;
unsigned long long V_27 ;
T_1 V_10 ;
if ( ! F_7 ( V_28 , V_29 . V_30 [ V_24 ] . V_24 ) )
return;
if ( V_12 > 2 )
printf ( L_12 , V_29 . V_30 [ V_24 ] . V_31 ) ;
if ( V_12 > 1 )
printf ( L_12 , V_29 . V_30 [ V_24 ] . V_32 ) ;
if ( V_12 > 0 )
printf ( L_12 , V_29 . V_30 [ V_24 ] . V_24 ) ;
for ( V_13 = 0 ; V_13 < V_19 ; V_13 ++ ) {
if ( V_13 != 0 )
printf ( L_13 ) ;
for ( V_14 = 0 ; V_14 < V_20 [ V_13 ] -> V_21 ; V_14 ++ ) {
if ( V_14 != 0 )
printf ( L_14 ) ;
V_10 = V_20 [ V_13 ] -> V_23 [ V_14 ] ;
if ( V_10 . V_33 ) {
V_25 = V_10 . V_33 ( V_10 . V_34 , & V_26 ,
V_29 . V_30 [ V_24 ] . V_24 ) ;
if ( V_25 )
printf ( L_15 ) ;
else if ( V_26 >= 100.0 )
printf ( L_16 , V_26 ) ;
else
printf ( L_17 , V_26 ) ;
} else if ( V_10 . V_35 ) {
V_25 = V_10 . V_35 ( V_10 . V_34 , & V_27 ,
V_29 . V_30 [ V_24 ] . V_24 ) ;
if ( V_25 )
printf ( L_15 ) ;
else
printf ( L_18 , V_27 ) ;
} else {
printf ( _ ( L_19
L_20 ) ,
V_20 [ V_13 ] -> V_22 , V_10 . V_22 ) ;
exit ( V_1 ) ;
}
}
}
if ( ! V_29 . V_30 [ V_24 ] . V_36 ) {
printf ( _ ( L_21 ) ) ;
return;
} else
printf ( L_7 ) ;
}
static void F_8 ( char * V_37 )
{
unsigned int V_38 ;
int V_13 , V_39 = 0 ;
char * V_40 = V_37 , * V_41 ;
struct V_42 * V_43 [ V_44 ] ;
for ( V_13 = 0 ; V_13 < V_44 ; V_13 ++ , V_40 = NULL ) {
V_41 = strtok ( V_40 , L_22 ) ;
if ( V_41 == NULL )
break;
if ( strlen ( V_41 ) >= V_45 ) {
printf ( _ ( L_23
L_24 ) , V_41 , V_45 ) ;
continue;
}
for ( V_38 = 0 ; V_38 < V_19 ; V_38 ++ ) {
if ( ! strcmp ( V_20 [ V_38 ] -> V_22 , V_41 ) ) {
F_9 ( L_25 , V_41 ) ;
V_43 [ V_39 ] = V_20 [ V_38 ] ;
V_39 ++ ;
}
}
}
if ( V_39 == 0 ) {
printf ( _ ( L_26
L_27 ) , V_37 ) ;
exit ( V_1 ) ;
}
memcpy ( V_20 , V_43 ,
sizeof( struct V_42 * ) * V_44 ) ;
V_19 = V_39 ;
}
void F_10 ( void )
{
unsigned int V_13 ;
int V_14 ;
T_1 V_10 ;
for ( V_13 = 0 ; V_13 < V_19 ; V_13 ++ ) {
printf ( _ ( L_28
L_29 ) ,
V_20 [ V_13 ] -> V_22 , V_20 [ V_13 ] -> V_21 ,
V_20 [ V_13 ] -> V_46 ) ;
for ( V_14 = 0 ; V_14 < V_20 [ V_13 ] -> V_21 ; V_14 ++ ) {
V_10 = V_20 [ V_13 ] -> V_23 [ V_14 ] ;
printf ( L_30 , V_10 . V_22 , V_47 [ V_10 . V_48 ] ,
F_11 ( V_10 . V_49 ) ) ;
}
}
}
int F_12 ( char * * V_50 )
{
int V_51 ;
unsigned int V_38 ;
unsigned long long V_52 ;
T_2 V_53 ;
struct V_2 V_3 , V_4 ;
V_53 = F_13 () ;
F_14 ( V_54 , & V_3 ) ;
for ( V_38 = 0 ; V_38 < V_19 ; V_38 ++ )
V_20 [ V_38 ] -> V_3 () ;
if ( ! V_53 ) {
F_15 ( V_50 [ 0 ] , V_50 ) ;
} else {
if ( V_53 == - 1 ) {
perror ( L_31 ) ;
exit ( 1 ) ;
}
signal ( V_55 , V_56 ) ;
signal ( V_57 , V_56 ) ;
if ( F_16 ( V_53 , & V_51 , 0 ) == - 1 ) {
perror ( L_32 ) ;
exit ( 1 ) ;
}
}
F_14 ( V_54 , & V_4 ) ;
for ( V_38 = 0 ; V_38 < V_19 ; V_38 ++ )
V_20 [ V_38 ] -> F_17 () ;
V_52 = F_2 ( V_3 , V_4 ) ;
if ( F_18 ( V_51 ) )
printf ( _ ( L_33 ) ,
V_50 [ 0 ] , V_52 / ( 1000.0 * 1000 ) ,
F_19 ( V_51 ) ) ;
return 0 ;
}
int F_20 ( int V_58 )
{
unsigned int V_38 ;
for ( V_38 = 0 ; V_38 < V_19 ; V_38 ++ ) {
F_9 ( L_34 ,
V_20 [ V_38 ] -> V_22 , V_20 [ V_38 ] -> V_21 ) ;
V_20 [ V_38 ] -> V_3 () ;
}
F_21 ( V_58 ) ;
for ( V_38 = 0 ; V_38 < V_19 ; V_38 ++ )
V_20 [ V_38 ] -> F_17 () ;
return 0 ;
}
static void F_22 ( int V_59 , char * V_50 [] )
{
int V_60 ;
V_61 = F_23 ( V_50 [ 0 ] ) ;
while ( ( V_60 = F_24 ( V_59 , V_50 , L_35 ) ) != - 1 ) {
switch ( V_60 ) {
case 'l' :
if ( V_62 )
F_1 () ;
V_62 = V_63 ;
break;
case 'i' :
if ( V_62 && V_62 != V_64 )
F_1 () ;
V_65 = atoi ( V_66 ) ;
break;
case 'm' :
if ( V_62 )
F_1 () ;
V_62 = V_64 ;
V_67 = V_66 ;
break;
default:
F_1 () ;
}
}
if ( ! V_62 )
V_62 = V_68 ;
}
int F_25 ( int V_59 , char * * V_50 )
{
unsigned int V_38 ;
struct V_42 * V_69 ;
int V_24 ;
F_22 ( V_59 , V_50 ) ;
V_70 = F_26 ( & V_29 ) ;
if ( V_70 < 0 ) {
printf ( _ ( L_36 ) ) ;
return V_1 ;
}
if ( F_27 ( V_28 ) )
F_28 ( V_28 ) ;
F_9 ( L_37 , V_70 ) ;
for ( V_38 = 0 ; V_71 [ V_38 ] ; V_38 ++ ) {
F_9 ( L_38 , V_71 [ V_38 ] -> V_22 ) ;
V_69 = V_71 [ V_38 ] -> F_29 () ;
if ( V_69 ) {
if ( V_69 -> V_72 && ! V_73 ) {
fprintf ( V_74 , _ ( L_39
L_40 ) , V_69 -> V_22 ) ;
continue;
}
V_20 [ V_19 ] = V_69 ;
F_9 ( L_41 , V_71 [ V_38 ] -> V_22 ) ;
V_19 ++ ;
}
}
if ( V_19 == 0 ) {
printf ( _ ( L_42 ) ) ;
return 1 ;
}
if ( V_62 == V_63 ) {
F_10 () ;
exit ( V_75 ) ;
}
if ( V_62 == V_64 )
F_8 ( V_67 ) ;
F_9 ( L_43 ,
V_29 . V_76 , V_29 . V_77 , V_70 ) ;
if ( V_59 - V_78 )
F_12 ( V_50 + V_78 ) ;
else
F_20 ( V_65 ) ;
if ( V_29 . V_76 > 1 )
F_5 ( 3 ) ;
else
F_5 ( 1 ) ;
for ( V_24 = 0 ; V_24 < V_70 ; V_24 ++ ) {
if ( V_29 . V_76 > 1 )
F_6 ( 3 , V_24 ) ;
else
F_6 ( 1 , V_24 ) ;
}
for ( V_38 = 0 ; V_38 < V_19 ; V_38 ++ )
V_20 [ V_38 ] -> F_30 () ;
F_31 ( V_29 ) ;
return 0 ;
}
