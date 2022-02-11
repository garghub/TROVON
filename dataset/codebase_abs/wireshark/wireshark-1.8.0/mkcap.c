void
F_1 ( char * V_1 , char * V_2 , char * V_3 , char * V_4 , char * V_5 , char * V_6 , int * V_7 , int * V_8 , char * V_9 , int V_10 )
{
int V_11 ;
printf ( L_1 , V_12 / 1000000 , V_12 % 1000000 ) ;
printf ( L_2 , V_1 , V_2 ) ;
printf ( L_3 , ( V_10 + 40 ) >> 8 , ( V_10 + 40 ) & 0xff , V_3 , V_4 ) ;
printf ( L_4 , V_5 , V_6 ,
( ( * V_7 ) >> 24 ) & 0xff ,
( ( * V_7 ) >> 16 ) & 0xff ,
( ( * V_7 ) >> 8 ) & 0xff ,
( ( * V_7 ) ) & 0xff ,
( ( * V_8 ) >> 24 ) & 0xff ,
( ( * V_8 ) >> 16 ) & 0xff ,
( ( * V_8 ) >> 8 ) & 0xff ,
( ( * V_8 ) ) & 0xff ,
V_9 ) ;
for( V_11 = 0 ; V_11 < ( V_10 < ( V_13 - 40 ) ? V_10 : V_13 - 40 ) ; V_11 ++ ) printf ( L_5 ) ;
printf ( L_6 ) ;
printf ( L_6 ) ;
( * V_7 ) += V_10 ;
}
int F_2 ()
{
int V_14 = V_15 ;
int V_16 = 0 , V_17 = 0 ;
if ( V_15 == V_18 )
return ( ( ( unsigned int ) ( 1 << 31 ) ) - 1 ) ;
while ( V_19 [ V_14 ] . V_9 & ( V_20 || V_21 ) ) {
if ( V_19 [ V_14 ] . V_9 & V_20 )
V_16 ++ ;
if ( V_19 [ V_14 ] . V_9 & V_21 )
V_17 ++ ;
V_14 = ( V_14 + 1 ) % V_22 ;
}
if ( V_14 == V_15 )
return ( ( ( unsigned int ) ( 1 << 31 ) ) - 1 ) ;
if ( V_14 == V_18 && V_15 == ( ( V_18 + 1 ) % V_22 ) )
return ( V_19 [ V_18 ] . V_12 + V_23 + V_24 ) ;
if ( V_17 )
return ( V_19 [ V_14 ] . V_12 + V_23 + V_24 ) ;
if ( V_16 ) {
if ( V_25 ) {
if ( ( ( V_18 + 1 + 2 * V_16 ) % V_22 ) >= V_15 )
return ( ( ( unsigned int ) ( 1 << 31 ) ) - 1 ) ;
else
return V_19 [ ( V_18 + 1 + 2 * V_16 ) % V_22 ] . V_12 +
V_23 + V_24 ;
}
else
return V_19 [ V_14 ] . V_12 + V_23 + V_24 ;
}
else {
if ( V_25 )
return ( V_19 [ ( V_18 + 1 ) % V_22 ] . V_12 + V_23 + V_24 ) ;
else
return ( V_19 [ V_18 ] . V_12 + V_23 + V_24 ) ;
}
}
int
F_3 ( int V_26 , int V_27 )
{
int V_28 , V_29 , V_30 ;
V_28 = V_19 [ V_18 ] . V_31 + V_19 [ V_18 ] . V_10 ;
V_32 = V_32 - V_19 [ V_18 ] . V_10 ;
V_30 = V_19 [ V_18 ] . V_10 ;
V_29 = V_19 [ V_18 ] . V_12 + V_23 ;
V_18 = ( V_18 + 1 ) % V_22 ;
if ( V_25 && ( V_18 != V_15 ) ) {
V_28 += V_19 [ V_18 ] . V_10 ;
V_32 = V_32 - V_19 [ V_18 ] . V_10 ;
V_30 += V_19 [ V_18 ] . V_10 ;
V_29 = V_19 [ V_18 ] . V_12 + V_23 ;
V_18 = ( V_18 + 1 ) % V_22 ;
}
if ( V_29 + V_24 <= V_12 )
V_12 ++ ;
else
V_12 = V_29 + V_24 ;
V_24 = ( rand () % 10 - 5 ) ;
F_1 ( V_33 , V_34 , V_35 , V_36 , V_37 , V_38 , & V_39 , & V_28 , L_7 , 0 ) ;
if ( V_40 >= V_41 )
V_40 += ( 1460 * V_30 ) / V_40 ;
else
V_40 = V_40 + V_30 ;
if ( V_42 ) fprintf ( V_43 , L_8 ,
V_12 , V_30 , V_40 , V_44 ) ;
if ( V_40 > V_44 ) V_40 = V_44 ;
}
void
F_4 ( int V_10 , int V_27 , int V_45 )
{
int V_46 , V_47 = 0 ;
if ( V_42 ) fprintf ( V_43 , L_9 ,
V_10 , V_27 , V_45 ) ;
V_46 = V_48 ;
while( V_10 > 0 ) {
int V_49 , V_50 ;
V_49 = ( V_10 > 1460 ) ? 1460 : V_10 ;
if ( V_49 > ( V_40 - V_32 ) ) V_49 = V_40 - V_32 ;
V_10 -= V_49 ;
V_50 = V_48 ;
if ( V_42 ) fprintf ( V_43 , L_10 , V_12 , V_24 ) ;
if( V_10 ) {
F_1 ( V_34 , V_33 , V_36 , V_35 , V_38 , V_37 , & V_48 , & V_39 , L_7 , V_49 ) ;
} else {
F_1 ( V_34 , V_33 , V_36 , V_35 , V_38 , V_37 , & V_48 , & V_39 , L_11 , V_49 ) ;
}
F_5 ( V_50 , V_49 ) ;
V_24 = ( rand () % 10 ) - 5 ;
if ( V_42 ) fprintf ( V_43 , L_12 , V_32 , V_40 ) ;
if ( ( V_47 = F_2 () ) < V_12 + V_27 + V_24 ) {
int V_51 = V_12 ;
if ( V_42 ) fprintf ( V_43 , L_13 , V_12 + V_27 + V_24 , V_24 ) ;
F_3 ( V_52 , V_27 ) ;
if ( V_51 + V_27 + V_24 <= V_12 )
V_12 ++ ;
else
V_12 = V_51 + V_27 + V_24 ;
} else if ( V_32 == V_40 ) {
if ( V_42 ) fprintf ( V_43 , L_14 ) ;
F_3 ( V_53 , V_27 ) ;
V_12 += ( V_27 + V_24 ) ;
}
else {
V_12 += ( V_27 + V_24 ) ;
}
if ( V_42 ) fprintf ( V_43 , L_15 , V_47 ) ;
}
}
void
F_6 ( int V_10 , int V_27 , int V_45 )
{
int V_46 ;
int V_54 ;
int V_11 ;
int V_55 ;
if ( V_42 ) fprintf ( V_43 , L_16 ,
V_10 , V_27 , V_45 ) ;
V_46 = V_48 ;
while( V_10 > 0 ) {
int V_49 ;
V_49 = ( V_10 > 1460 ) ? 1460 : V_10 ;
V_10 -= V_49 ;
if( V_49 == 1460 ) {
F_1 ( V_34 , V_33 , V_36 , V_35 , V_38 , V_37 , & V_48 , & V_39 , L_7 , V_49 ) ;
} else {
F_1 ( V_34 , V_33 , V_36 , V_35 , V_38 , V_37 , & V_48 , & V_39 , L_11 , V_49 ) ;
}
V_12 += V_27 ;
}
V_12 += V_45 ;
V_11 = 0 ;
V_55 = - 1 ;
V_54 = 0 ;
while( V_46 != V_48 ) {
int V_56 ;
V_56 = ( ( V_48 - V_46 ) > 2920 ) ? 2920 : ( V_48 - V_46 ) ;
V_11 ++ ;
if( V_11 == 6 ) {
V_54 = V_46 ;
}
V_46 += V_56 ;
if( V_11 < 6 ) {
F_1 ( V_33 , V_34 , V_35 , V_36 , V_37 , V_38 , & V_39 , & V_46 , L_7 , 0 ) ;
} else if ( V_11 == 6 ) {
F_1 ( V_33 , V_34 , V_35 , V_36 , V_37 , V_38 , & V_39 , & V_54 , L_7 , 0 ) ;
V_55 += 2 ;
} else {
F_1 ( V_33 , V_34 , V_35 , V_36 , V_37 , V_38 , & V_39 , & V_54 , L_7 , 0 ) ;
F_1 ( V_33 , V_34 , V_35 , V_36 , V_37 , V_38 , & V_39 , & V_54 , L_7 , 0 ) ;
V_55 += 2 ;
}
V_12 += V_27 / 2 ;
}
if( ! V_54 ) {
return;
}
if( V_55 < 3 ) {
int V_49 ;
int V_57 ;
V_12 += 1000000 ;
V_49 = ( ( V_48 - V_54 ) > 1460 ) ? 1460 : ( V_48 - V_54 ) ;
if( V_49 == 1460 ) {
F_1 ( V_34 , V_33 , V_36 , V_35 , V_38 , V_37 , & V_54 , & V_39 , L_7 , V_49 ) ;
} else {
F_1 ( V_34 , V_33 , V_36 , V_35 , V_38 , V_37 , & V_54 , & V_39 , L_11 , V_49 ) ;
}
V_12 += V_45 ;
V_57 = V_49 + V_48 ;
F_1 ( V_33 , V_34 , V_35 , V_36 , V_37 , V_38 , & V_39 , & V_48 , L_7 , 0 ) ;
V_12 += V_27 ;
return;
}
while( V_54 != V_48 ) {
int V_49 ;
int V_58 ;
V_49 = ( ( V_48 - V_54 ) > 1460 ) ? 1460 : ( V_48 - V_54 ) ;
if( V_49 == 1460 ) {
F_1 ( V_34 , V_33 , V_36 , V_35 , V_38 , V_37 , & V_54 , & V_39 , L_7 , V_49 ) ;
} else {
F_1 ( V_34 , V_33 , V_36 , V_35 , V_38 , V_37 , & V_54 , & V_39 , L_11 , V_49 ) ;
}
V_12 += V_45 ;
V_58 = V_54 ;
F_1 ( V_33 , V_34 , V_35 , V_36 , V_37 , V_38 , & V_39 , & V_58 , L_7 , 0 ) ;
V_12 += V_27 ;
}
}
void F_7 ()
{
fprintf ( V_43 , L_17 ) ;
fprintf ( V_43 , L_18 ) ;
fprintf ( V_43 , L_19 ) ;
fprintf ( V_43 , L_20 ) ;
fprintf ( V_43 , L_21 ) ;
fprintf ( V_43 , L_22 ) ;
fprintf ( V_43 , L_23 ) ;
fprintf ( V_43 , L_24 ) ;
fprintf ( V_43 , L_25 ) ;
fprintf ( V_43 , L_26 ) ;
fprintf ( V_43 , L_27 ) ;
}
int
F_8 ( char * V_59 )
{
int V_11 ;
if ( ! V_59 || ! ( * V_59 ) ) {
return 0 ;
}
for ( V_11 = 0 ; V_59 [ V_11 ] ; V_11 ++ ) {
if ( ! isdigit ( V_59 [ V_11 ] ) )
return 0 ;
}
return 1 ;
}
void
F_9 ( char * V_60 )
{
int V_61 = 0 , V_11 ;
char * V_62 , * V_63 ;
if ( ! V_60 || ! ( * V_60 ) ) {
fprintf ( V_43 , L_28 ) ;
return;
}
V_63 = ( char * ) F_10 ( V_60 ) ;
for ( V_62 = ( char * ) strtok ( V_60 , L_29 ) ; V_62 ; V_62 = ( char * ) strtok ( NULL , L_29 ) ) {
V_61 ++ ;
}
V_64 = ( V_61 + 1 ) / 2 ;
V_65 = ( V_66 * ) F_11 ( sizeof( V_66 ) * V_64 ) ;
if ( ! V_65 ) {
fprintf ( V_43 , L_30 ) ;
V_64 = 0 ;
F_12 ( V_63 ) ;
return;
}
V_61 = 0 ;
for ( V_62 = ( char * ) strtok ( V_63 , L_29 ) ; V_62 ; V_62 = ( char * ) strtok ( NULL , L_29 ) ) {
int V_67 = atoi ( V_62 ) ;
if ( ! F_8 ( V_62 ) ) {
fprintf ( V_43 , L_31 ,
V_62 ) ;
fprintf ( V_43 , L_32 ) ;
F_12 ( V_63 ) ;
F_12 ( V_65 ) ;
V_64 = 0 ; V_65 = NULL ;
return;
}
if ( V_67 == 0 ) V_67 = 1 ;
if ( V_61 % 2 )
V_65 [ V_61 / 2 ] . V_68 = V_67 ;
else
V_65 [ V_61 / 2 ] . V_69 = V_67 ;
}
}
int
main ( int V_70 , char * V_71 [] )
{
int V_11 ;
int V_10 ;
int type ;
int V_72 ;
extern char * V_73 ;
extern int V_74 ;
int V_75 ;
while ( ( V_75 = F_13 ( V_70 , V_71 , L_33 ) ) != V_76 ) {
switch ( V_75 ) {
case 'a' :
V_23 = atoi ( V_73 ) ;
break;
case 'b' :
V_77 = atoi ( V_73 ) ;
break;
case 'd' :
F_9 ( V_73 ) ;
break;
case 'D' :
V_78 = ( V_78 + 1 ) % 1 ;
break;
case 'i' :
V_36 = V_73 ;
break;
case 'I' :
V_35 = V_73 ;
break;
case 'l' :
V_13 = atoi ( V_73 ) ;
break;
case 'n' :
V_48 = atoi ( V_73 ) ;
break;
case 'N' :
V_39 = atoi ( V_73 ) ;
break;
case 'p' :
V_38 = V_73 ;
break;
case 'P' :
V_37 = V_73 ;
break;
case 'r' :
V_79 = atoi ( V_73 ) ;
break;
case 's' :
V_80 = atoi ( V_73 ) ;
break;
case 'v' :
V_42 ++ ;
break;
case 'w' :
V_44 = atoi ( V_73 ) ;
V_41 = V_44 / 2 ;
break;
default:
F_7 () ;
break;
}
}
if ( V_42 ) fprintf ( V_43 , L_34 ,
V_36 , V_35 , V_38 , V_37 , V_23 , V_80 ) ;
if ( V_79 == 0 ) {
F_4 ( V_77 , V_80 , V_23 ) ;
}
else {
for( V_72 = 0 ; V_72 < 200 ; V_72 ++ ) {
type = rand () % 150 ;
if( type < 75 ) {
int V_81 ;
V_81 = 5 + rand () % 10 ;
for( V_11 = 0 ; V_11 < V_81 ; V_11 ++ ) {
F_4 ( 32768 , V_80 , V_23 ) ;
}
} else if( type < 90 ) {
int V_81 ;
V_81 = 4 + rand () % 4 ;
for( V_11 = 0 ; V_11 < V_81 ; V_11 ++ ) {
V_10 = 100 + rand () & 0xfff ;
F_4 ( V_10 , V_80 , V_23 ) ;
}
} else {
for( V_11 = 0 ; V_11 < 5 ; V_11 ++ ) {
V_10 = 100 + rand () & 0x3fff + 0x1fff ;
F_4 ( V_10 , V_80 , V_23 ) ;
}
}
}
}
return 0 ;
}
