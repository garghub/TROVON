static int T_1 F_1 ( char * V_1 )
{
int V_2 , V_3 , V_4 , V_5 , V_6 = 0 ;
char * V_7 = L_1 ;
char * V_8 ;
int V_9 ;
if ( * V_1 == 'd' ) {
V_6 = 1 ;
V_1 ++ ;
}
if ( F_2 ( & V_1 , & V_2 ) != 2 ) {
F_3 ( V_10 L_2 ) ;
return 0 ;
}
V_8 = V_1 ;
for ( V_9 = 0 ; V_9 < V_11 ; V_9 ++ )
if ( V_12 [ V_9 ] . V_2 == V_2 &&
V_12 [ V_9 ] . V_6 == V_6 ) {
F_3 ( V_10 L_3
L_4 , V_6 ? L_5 : L_1 , V_2 ) ;
break;
}
if ( V_9 >= F_4 ( V_12 ) ) {
F_3 ( V_10 L_6 , V_6 ? L_5 : L_1 , V_2 ) ;
return 0 ;
}
if ( V_9 >= V_11 )
V_11 ++ ;
switch ( F_2 ( & V_1 , & V_3 ) ) {
case 2 :
if ( V_3 == 0 || V_3 == V_13 ) {
if ( F_2 ( & V_1 , & V_4 ) != 2 ||
F_2 ( & V_1 , & V_5 ) != 2 ) {
F_3 ( V_10 L_2 ) ;
return 0 ;
}
V_12 [ V_9 ] . V_3 = V_3 ;
V_12 [ V_9 ] . V_14 = 1 << ( V_4 + 12 ) ;
if ( V_3 == V_13 )
V_7 = L_7 ;
else
V_7 = L_8 ;
break;
}
case 1 :
V_1 = V_8 ;
case 0 :
V_12 [ V_9 ] . V_3 = V_15 ;
V_7 = L_9 ;
}
F_3 ( V_16 L_10 ,
V_2 , V_7 , V_1 ) ;
V_12 [ V_9 ] . V_17 = V_1 ;
V_12 [ V_9 ] . V_6 = V_6 ;
V_12 [ V_9 ] . V_2 = V_2 ;
return 1 ;
}
static void T_1 F_5 ( void )
{
int V_2 , V_18 , V_9 , V_6 ;
T_2 V_19 ;
T_2 V_20 [ V_21 + 1 ] ;
for ( V_9 = 0 ; V_9 < V_11 ; V_9 ++ ) {
int V_22 ;
int V_23 = 0 ;
char * V_24 ;
T_3 V_25 ;
char V_26 [ 16 ] ;
V_2 = V_12 [ V_9 ] . V_2 ;
V_6 = V_12 [ V_9 ] . V_6 ;
V_24 = V_12 [ V_9 ] . V_17 ;
sprintf ( V_26 , L_11 , V_6 ? L_12 : L_1 , V_2 ) ;
if ( V_6 )
V_19 = F_6 ( V_27 , V_2 << V_28 ) ;
else
V_19 = F_6 ( V_29 , V_2 ) ;
F_7 ( V_26 , V_19 ) ;
for ( V_18 = 0 ; V_18 < V_21 && V_24 != NULL ; V_18 ++ ) {
char * V_30 ;
char V_31 [ 64 ] ;
T_4 V_32 ;
V_30 = strchr ( V_24 , ',' ) ;
if ( V_30 )
* V_30 ++ = 0 ;
V_19 = F_8 ( V_24 ) ;
if ( strncmp ( V_24 , L_13 , 5 ) == 0 )
V_24 += 5 ;
snprintf ( V_31 , 63 , L_14 , V_24 ) ;
V_32 = F_9 ( V_31 ) ;
if ( V_32 )
V_19 = F_10 ( V_32 ) ;
if ( ! V_19 ) {
F_3 ( V_10 L_15 , V_24 ) ;
break;
}
V_20 [ V_18 ] = V_19 ;
V_24 = V_30 ;
}
V_20 [ V_18 ] = 0 ;
if ( ! V_18 )
continue;
F_3 ( V_16 L_16 ,
V_6 ? L_12 : L_1 , V_2 ,
V_12 [ V_9 ] . V_17 ) ;
V_22 = F_11 ( V_26 , 0 , 0 ) ;
if ( V_22 < 0 ) {
F_3 ( V_33 L_17
L_18 , V_26 ) ;
continue;
}
if ( F_12 ( V_22 , V_34 , 0 ) == - V_35 ) {
F_3 ( V_10
L_19 ,
V_2 ) ;
F_13 ( V_22 ) ;
continue;
}
if ( V_12 [ V_9 ] . V_3 != V_15 ) {
T_5 V_36 ;
V_36 . V_3 = V_12 [ V_9 ] . V_3 ;
V_36 . V_37 = 0 ;
V_36 . V_38 = 0 ;
V_36 . V_39 = 0 ;
while ( V_20 [ V_36 . V_39 ] )
V_36 . V_39 ++ ;
V_36 . V_40 = V_2 ;
V_36 . V_41 = 1 ;
V_36 . V_42 = ( 1 << V_43 ) ;
V_36 . V_44 = 0 ;
V_36 . V_45 = V_12 [ V_9 ] . V_14 ;
V_23 = F_12 ( V_22 , V_34 , ( long ) & V_36 ) ;
for ( V_18 = 0 ; ! V_23 && V_18 <= V_21 ; V_18 ++ ) {
V_19 = V_20 [ V_18 ] ;
if ( ! V_19 )
break;
V_25 . V_46 = V_18 ;
V_25 . V_47 = V_18 ;
V_25 . V_42 = ( 1 << V_48 ) | ( 1 << V_49 ) ;
V_25 . V_50 = F_14 ( V_19 ) ;
V_25 . V_2 = F_15 ( V_19 ) ;
V_23 = F_12 ( V_22 , V_51 , ( long ) & V_25 ) ;
}
} else {
for ( V_18 = 0 ; V_18 <= V_21 ; V_18 ++ ) {
V_19 = V_20 [ V_18 ] ;
if ( ! V_19 )
break;
V_25 . V_50 = F_14 ( V_19 ) ;
V_25 . V_2 = F_15 ( V_19 ) ;
F_12 ( V_22 , V_51 , ( long ) & V_25 ) ;
}
}
if ( ! V_23 )
V_23 = F_12 ( V_22 , V_52 , 0 ) ;
if ( V_23 )
F_3 ( V_10 L_20 , V_2 ) ;
else {
F_13 ( V_22 ) ;
V_22 = F_11 ( V_26 , 0 , 0 ) ;
F_12 ( V_22 , V_53 , 0 ) ;
}
F_13 ( V_22 ) ;
}
}
static int T_1 F_16 ( char * V_1 )
{
int V_54 , V_55 ;
V_54 = strlen ( V_1 ) + 1 ;
V_55 = 0 ;
while ( V_55 < V_54 ) {
char * V_56 = strchr ( V_1 + V_55 , ',' ) ;
int V_57 ;
if ( V_56 )
V_57 = ( V_56 - V_1 ) - V_55 ;
else V_57 = ( V_54 - 1 ) - V_55 ;
if ( ! strncmp ( V_1 , L_21 , V_57 ) )
V_58 = 1 ;
if ( ! strncmp ( V_1 , L_22 , V_57 ) )
V_58 = 0 ;
if ( strncmp ( V_1 , L_23 , V_57 ) == 0 )
V_59 = 1 ;
if ( strncmp ( V_1 , L_24 , V_57 ) == 0 )
V_59 = 1 ;
V_55 += V_57 + 1 ;
}
return 1 ;
}
static void T_1 F_17 ( void )
{
int V_22 ;
F_3 ( V_16 L_25 ) ;
F_3 ( V_16 L_26 ) ;
F_18 () ;
V_22 = F_11 ( ( const char V_60 V_61 * ) L_27 , 0 , 0 ) ;
if ( V_22 >= 0 ) {
F_12 ( V_22 , V_62 , V_59 ) ;
F_13 ( V_22 ) ;
}
}
void T_1 F_19 ( void )
{
F_7 ( L_27 , F_6 ( V_29 , 0 ) ) ;
if ( V_58 )
F_3 ( V_16 L_28 ) ;
else
F_17 () ;
F_5 () ;
}
