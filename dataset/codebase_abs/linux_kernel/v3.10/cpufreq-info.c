static unsigned int F_1 ( void )
{
T_1 * V_1 ;
char V_2 [ V_3 ] ;
unsigned int V_4 = 0 ;
unsigned int V_5 = 0 ;
V_1 = fopen ( L_1 , L_2 ) ;
if ( ! V_1 ) {
printf ( _ ( L_3 ) , L_1 , strerror ( V_6 ) ) ;
return 1 ;
}
while ( ! feof ( V_1 ) ) {
if ( ! fgets ( V_2 , V_3 , V_1 ) )
continue;
V_2 [ V_3 - 1 ] = '\0' ;
if ( strlen ( V_2 ) < ( V_3 - 2 ) )
continue;
if ( strstr ( V_2 , L_4 ) )
continue;
if ( sscanf ( V_2 , L_5 , & V_5 ) != 1 )
continue;
if ( V_5 > V_4 )
V_4 = V_5 ;
}
fclose ( V_1 ) ;
return V_4 + 1 ;
}
static void F_2 ( void )
{
unsigned int V_7 , V_8 ;
struct V_9 * V_10 ;
unsigned int V_11 = 0 ;
unsigned int V_12 = 0 ;
unsigned long V_13 , V_14 ;
printf ( _ ( L_6 ) ) ;
V_8 = F_1 () ;
for ( V_7 = 0 ; V_7 < V_8 ; V_7 ++ ) {
V_10 = F_3 ( V_7 ) ;
if ( ! V_10 )
continue;
if ( F_4 ( V_7 , & V_13 , & V_14 ) ) {
V_14 = 0 ;
} else {
V_11 = ( V_10 -> V_13 * 100 ) / V_14 ;
V_12 = ( V_10 -> V_14 * 100 ) / V_14 ;
}
printf ( L_7 ,
V_7 , V_10 -> V_13 , V_14 ? V_11 : 0 , V_10 -> V_14 ,
V_14 ? V_12 : 0 , V_10 -> V_15 ) ;
F_5 ( V_10 ) ;
}
}
static void F_6 ( unsigned long V_16 )
{
unsigned long V_17 ;
if ( V_16 > 1000000 ) {
V_17 = V_16 % 10000 ;
if ( V_17 >= 5000 )
V_16 += 10000 ;
printf ( L_8 , ( ( unsigned int ) V_16 / 1000000 ) ,
( ( unsigned int ) ( V_16 % 1000000 ) / 10000 ) ) ;
} else if ( V_16 > 100000 ) {
V_17 = V_16 % 1000 ;
if ( V_17 >= 500 )
V_16 += 1000 ;
printf ( L_9 , ( ( unsigned int ) V_16 / 1000 ) ) ;
} else if ( V_16 > 1000 ) {
V_17 = V_16 % 100 ;
if ( V_17 >= 50 )
V_16 += 100 ;
printf ( L_10 , ( ( unsigned int ) V_16 / 1000 ) ,
( ( unsigned int ) ( V_16 % 1000 ) / 100 ) ) ;
} else
printf ( L_11 , V_16 ) ;
return;
}
static void F_7 ( unsigned long V_18 )
{
unsigned long V_17 ;
if ( V_18 > 1000000 ) {
V_17 = V_18 % 10000 ;
if ( V_17 >= 5000 )
V_18 += 10000 ;
printf ( L_12 , ( ( unsigned int ) V_18 / 1000000 ) ,
( ( unsigned int ) ( V_18 % 1000000 ) / 10000 ) ) ;
} else if ( V_18 > 100000 ) {
V_17 = V_18 % 1000 ;
if ( V_17 >= 500 )
V_18 += 1000 ;
printf ( L_13 , ( ( unsigned int ) V_18 / 1000 ) ) ;
} else if ( V_18 > 1000 ) {
V_17 = V_18 % 100 ;
if ( V_17 >= 50 )
V_18 += 100 ;
printf ( L_14 , ( ( unsigned int ) V_18 / 1000 ) ,
( ( unsigned int ) ( V_18 % 1000 ) / 100 ) ) ;
} else
printf ( L_15 , V_18 ) ;
return;
}
static int F_8 ( unsigned int V_7 )
{
int V_19 , V_20 , V_21 = 0 , V_4 , V_22 , V_23 ;
unsigned long V_24 [ V_25 ] = { 0 ,} ;
if ( V_26 . V_27 != V_28 &&
V_26 . V_27 != V_29 )
return 0 ;
V_4 = F_9 ( V_7 , & V_19 , & V_20 , & V_21 ) ;
if ( V_4 ) {
printf ( _ ( L_16
L_17 ) , V_7 ) ;
return V_4 ;
}
printf ( _ ( L_18 ) ) ;
printf ( _ ( L_19 ) , V_19 ? _ ( L_20 ) : _ ( L_21 ) ) ;
printf ( _ ( L_22 ) , V_20 ? _ ( L_20 ) : _ ( L_21 ) ) ;
if ( V_26 . V_27 == V_28 &&
V_26 . V_30 >= 0x10 ) {
V_4 = F_10 ( V_7 , V_26 . V_30 , V_21 ,
V_24 , & V_22 ) ;
if ( V_4 )
return V_4 ;
printf ( _ ( L_23 ) , V_21 ) ;
printf ( _ ( L_24 ) , V_22 ) ;
for ( V_23 = 0 ; V_23 < V_22 ; V_23 ++ ) {
if ( V_23 < V_21 )
printf ( _ ( L_25
L_26 ) , V_23 , V_24 [ V_23 ] ) ;
else
printf ( _ ( L_27 ) ,
V_23 - V_21 , V_24 [ V_23 ] ) ;
}
} else if ( V_26 . V_31 & V_32 ) {
double V_33 ;
unsigned long long V_34 = 0 ;
unsigned int V_35 ;
if ( V_26 . V_31 & V_36 )
V_33 = 100.00 ;
else
V_33 = 133.33 ;
V_34 = F_11 ( V_7 ) ;
F_12 ( L_28 ,
V_34 , V_33 ) ;
V_35 = ( V_34 >> 24 ) & 0xFF ;
if ( V_35 )
printf ( _ ( L_29 ) ,
V_35 * V_33 ) ;
V_35 = ( V_34 >> 16 ) & 0xFF ;
if ( V_35 )
printf ( _ ( L_30 ) ,
V_35 * V_33 ) ;
V_35 = ( V_34 >> 8 ) & 0xFF ;
if ( V_35 )
printf ( _ ( L_31 ) ,
V_35 * V_33 ) ;
V_35 = ( V_34 >> 0 ) & 0xFF ;
if ( V_35 )
printf ( _ ( L_32 ) ,
V_35 * V_33 ) ;
}
return 0 ;
}
static void F_13 ( unsigned int V_7 )
{
char * V_37 ;
struct V_38 * V_39 ;
struct V_40 * V_41 ;
unsigned long V_13 , V_14 , V_42 , V_43 ;
unsigned long V_44 , V_45 ;
unsigned long long V_46 ;
struct V_9 * V_10 ;
struct V_47 * V_48 ;
struct V_49 * V_50 ;
if ( F_14 ( V_7 ) )
return;
V_42 = F_15 ( V_7 ) ;
V_43 = F_16 ( V_7 ) ;
V_37 = F_17 ( V_7 ) ;
if ( ! V_37 ) {
printf ( _ ( L_33 ) ) ;
} else {
printf ( _ ( L_34 ) , V_37 ) ;
F_18 ( V_37 ) ;
}
V_39 = F_19 ( V_7 ) ;
if ( V_39 ) {
printf ( _ ( L_35 ) ) ;
while ( V_39 -> V_51 ) {
printf ( L_36 , V_39 -> V_7 ) ;
V_39 = V_39 -> V_51 ;
}
printf ( L_37 , V_39 -> V_7 ) ;
F_20 ( V_39 ) ;
}
V_39 = F_21 ( V_7 ) ;
if ( V_39 ) {
printf ( _ ( L_38 ) ) ;
while ( V_39 -> V_51 ) {
printf ( L_36 , V_39 -> V_7 ) ;
V_39 = V_39 -> V_51 ;
}
printf ( L_37 , V_39 -> V_7 ) ;
F_22 ( V_39 ) ;
}
V_45 = F_23 ( V_7 ) ;
if ( V_45 ) {
printf ( _ ( L_39 ) ) ;
F_7 ( V_45 ) ;
printf ( L_40 ) ;
}
if ( ! ( F_4 ( V_7 , & V_13 , & V_14 ) ) ) {
printf ( _ ( L_41 ) ) ;
F_6 ( V_13 ) ;
printf ( L_42 ) ;
F_6 ( V_14 ) ;
printf ( L_26 ) ;
}
V_41 = F_24 ( V_7 ) ;
if ( V_41 ) {
printf ( _ ( L_43 ) ) ;
while ( V_41 -> V_51 ) {
F_6 ( V_41 -> V_52 ) ;
printf ( L_44 ) ;
V_41 = V_41 -> V_51 ;
}
F_6 ( V_41 -> V_52 ) ;
printf ( L_26 ) ;
F_25 ( V_41 ) ;
}
V_48 = F_26 ( V_7 ) ;
if ( V_48 ) {
printf ( _ ( L_45 ) ) ;
while ( V_48 -> V_51 ) {
printf ( L_46 , V_48 -> V_15 ) ;
V_48 = V_48 -> V_51 ;
}
printf ( L_47 , V_48 -> V_15 ) ;
F_27 ( V_48 ) ;
}
V_10 = F_3 ( V_7 ) ;
if ( V_10 ) {
printf ( _ ( L_48 ) ) ;
F_6 ( V_10 -> V_13 ) ;
printf ( _ ( L_49 ) ) ;
F_6 ( V_10 -> V_14 ) ;
printf ( L_50 ) ;
printf ( _ ( L_51
L_52 ) ,
V_10 -> V_15 ) ;
F_5 ( V_10 ) ;
}
if ( V_42 || V_43 ) {
printf ( _ ( L_53 ) ) ;
if ( V_43 ) {
F_6 ( V_43 ) ;
printf ( _ ( L_54 ) ) ;
} else
F_6 ( V_42 ) ;
printf ( L_40 ) ;
}
V_50 = F_28 ( V_7 , & V_46 ) ;
if ( V_50 ) {
printf ( _ ( L_55 ) ) ;
while ( V_50 ) {
F_6 ( V_50 -> V_52 ) ;
printf ( L_56 , ( 100.0 * V_50 -> V_53 ) / V_46 ) ;
V_50 = V_50 -> V_51 ;
if ( V_50 )
printf ( L_44 ) ;
}
F_29 ( V_50 ) ;
V_44 = F_30 ( V_7 ) ;
if ( V_44 )
printf ( L_57 , V_44 ) ;
else
printf ( L_26 ) ;
}
F_8 ( V_7 ) ;
}
static int F_31 ( unsigned int V_7 , unsigned int V_54 )
{
unsigned long V_55 = F_15 ( V_7 ) ;
if ( ! V_55 )
return - V_56 ;
if ( V_54 ) {
F_6 ( V_55 ) ;
printf ( L_26 ) ;
} else
printf ( L_58 , V_55 ) ;
return 0 ;
}
static int F_32 ( unsigned int V_7 , unsigned int V_54 )
{
unsigned long V_55 = F_16 ( V_7 ) ;
if ( ! V_55 )
return - V_56 ;
if ( V_54 ) {
F_6 ( V_55 ) ;
printf ( L_26 ) ;
} else
printf ( L_58 , V_55 ) ;
return 0 ;
}
static int F_33 ( unsigned int V_7 )
{
unsigned long V_13 , V_14 ;
if ( F_4 ( V_7 , & V_13 , & V_14 ) )
return - V_56 ;
printf ( L_59 , V_13 , V_14 ) ;
return 0 ;
}
static int F_34 ( unsigned int V_7 )
{
char * V_37 = F_17 ( V_7 ) ;
if ( ! V_37 )
return - V_56 ;
printf ( L_47 , V_37 ) ;
F_18 ( V_37 ) ;
return 0 ;
}
static int F_35 ( unsigned int V_7 )
{
struct V_9 * V_10 = F_3 ( V_7 ) ;
if ( ! V_10 )
return - V_56 ;
printf ( L_60 , V_10 -> V_13 , V_10 -> V_14 , V_10 -> V_15 ) ;
F_5 ( V_10 ) ;
return 0 ;
}
static int F_36 ( unsigned int V_7 )
{
struct V_47 * V_48 =
F_26 ( V_7 ) ;
if ( ! V_48 )
return - V_56 ;
while ( V_48 -> V_51 ) {
printf ( L_61 , V_48 -> V_15 ) ;
V_48 = V_48 -> V_51 ;
}
printf ( L_47 , V_48 -> V_15 ) ;
F_27 ( V_48 ) ;
return 0 ;
}
static int F_37 ( unsigned int V_7 )
{
struct V_38 * V_39 = F_21 ( V_7 ) ;
if ( ! V_39 )
return - V_56 ;
while ( V_39 -> V_51 ) {
printf ( L_36 , V_39 -> V_7 ) ;
V_39 = V_39 -> V_51 ;
}
printf ( L_37 , V_39 -> V_7 ) ;
F_22 ( V_39 ) ;
return 0 ;
}
static int F_38 ( unsigned int V_7 )
{
struct V_38 * V_39 = F_19 ( V_7 ) ;
if ( ! V_39 )
return - V_56 ;
while ( V_39 -> V_51 ) {
printf ( L_36 , V_39 -> V_7 ) ;
V_39 = V_39 -> V_51 ;
}
printf ( L_37 , V_39 -> V_7 ) ;
F_20 ( V_39 ) ;
return 0 ;
}
static int F_39 ( unsigned int V_7 , unsigned int V_54 )
{
unsigned long V_44 = F_30 ( V_7 ) ;
unsigned long long V_46 ;
struct V_49 * V_50 = F_28 ( V_7 , & V_46 ) ;
while ( V_50 ) {
if ( V_54 ) {
F_6 ( V_50 -> V_52 ) ;
printf ( L_56 ,
( 100.0 * V_50 -> V_53 ) / V_46 ) ;
} else
printf ( L_62 ,
V_50 -> V_52 , V_50 -> V_53 ) ;
V_50 = V_50 -> V_51 ;
if ( V_50 )
printf ( L_44 ) ;
}
F_29 ( V_50 ) ;
if ( V_44 )
printf ( L_57 , V_44 ) ;
return 0 ;
}
static int F_40 ( unsigned int V_7 , unsigned int V_54 )
{
unsigned long V_45 = F_23 ( V_7 ) ;
if ( ! V_45 )
return - V_56 ;
if ( V_54 ) {
F_7 ( V_45 ) ;
printf ( L_26 ) ;
} else
printf ( L_58 , V_45 ) ;
return 0 ;
}
int F_41 ( int V_57 , char * * V_58 )
{
extern char * V_59 ;
extern int V_60 , V_61 , V_62 ;
int V_4 = 0 , V_63 = 1 ;
unsigned int V_7 = 0 ;
unsigned int V_54 = 0 ;
int V_64 = 0 ;
do {
V_4 = F_42 ( V_57 , V_58 , L_63 , V_65 , NULL ) ;
switch ( V_4 ) {
case '?' :
V_64 = '?' ;
V_63 = 0 ;
break;
case - 1 :
V_63 = 0 ;
break;
case 'b' :
case 'o' :
case 'a' :
case 'r' :
case 'g' :
case 'p' :
case 'd' :
case 'l' :
case 'w' :
case 'f' :
case 'e' :
case 's' :
case 'y' :
if ( V_64 ) {
V_64 = - 1 ;
V_63 = 0 ;
break;
}
V_64 = V_4 ;
break;
case 'm' :
if ( V_54 ) {
V_64 = - 1 ;
V_63 = 0 ;
break;
}
V_54 = 1 ;
break;
default:
fprintf ( V_66 , L_64 ) ;
return V_67 ;
}
} while ( V_63 );
switch ( V_64 ) {
case 'o' :
if ( ! F_43 ( V_68 ) ) {
printf ( _ ( L_65
L_66 ) ) ;
return - V_56 ;
}
break;
case 0 :
V_64 = 'e' ;
}
V_4 = 0 ;
if ( F_43 ( V_68 ) )
F_44 ( V_68 , 0 ) ;
switch ( V_64 ) {
case - 1 :
printf ( _ ( L_67
L_68 ) ) ;
return - V_56 ;
case '?' :
printf ( _ ( L_64 ) ) ;
return - V_56 ;
case 'o' :
F_2 () ;
return V_69 ;
}
for ( V_7 = F_45 ( V_68 ) ;
V_7 <= F_46 ( V_68 ) ; V_7 ++ ) {
if ( ! F_47 ( V_68 , V_7 ) )
continue;
if ( F_14 ( V_7 ) ) {
printf ( _ ( L_69 ) , V_7 ) ;
continue;
}
printf ( _ ( L_70 ) , V_7 ) ;
switch ( V_64 ) {
case 'b' :
F_8 ( V_7 ) ;
break;
case 'e' :
F_13 ( V_7 ) ;
break;
case 'a' :
V_4 = F_37 ( V_7 ) ;
break;
case 'r' :
V_4 = F_38 ( V_7 ) ;
break;
case 'g' :
V_4 = F_36 ( V_7 ) ;
break;
case 'p' :
V_4 = F_35 ( V_7 ) ;
break;
case 'd' :
V_4 = F_34 ( V_7 ) ;
break;
case 'l' :
V_4 = F_33 ( V_7 ) ;
break;
case 'w' :
V_4 = F_32 ( V_7 , V_54 ) ;
break;
case 'f' :
V_4 = F_31 ( V_7 , V_54 ) ;
break;
case 's' :
V_4 = F_39 ( V_7 , V_54 ) ;
break;
case 'y' :
V_4 = F_40 ( V_7 , V_54 ) ;
break;
}
if ( V_4 )
return V_4 ;
}
return V_4 ;
}
