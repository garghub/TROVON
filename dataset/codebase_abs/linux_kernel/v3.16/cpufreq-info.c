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
if ( V_18 ) {
if ( V_16 > 1000000 )
printf ( L_8 , ( ( unsigned int ) V_16 / 1000000 ) ,
( ( unsigned int ) V_16 % 1000000 ) ) ;
else if ( V_16 > 100000 )
printf ( L_9 , ( unsigned int ) V_16 ) ;
else if ( V_16 > 1000 )
printf ( L_10 , ( ( unsigned int ) V_16 / 1000 ) ,
( unsigned int ) ( V_16 % 1000 ) ) ;
else
printf ( L_11 , V_16 ) ;
} else {
if ( V_16 > 1000000 ) {
V_17 = V_16 % 10000 ;
if ( V_17 >= 5000 )
V_16 += 10000 ;
printf ( L_12 , ( ( unsigned int ) V_16 / 1000000 ) ,
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
printf ( L_13 , ( ( unsigned int ) V_16 / 1000 ) ,
( ( unsigned int ) ( V_16 % 1000 ) / 100 ) ) ;
}
}
return;
}
static void F_7 ( unsigned long V_19 )
{
unsigned long V_17 ;
if ( V_18 ) {
if ( V_19 > 1000000 )
printf ( L_14 , ( ( unsigned int ) V_19 / 1000000 ) ,
( ( unsigned int ) V_19 % 1000000 ) ) ;
else if ( V_19 > 100000 )
printf ( L_15 , ( ( unsigned int ) V_19 / 1000 ) ) ;
else if ( V_19 > 1000 )
printf ( L_16 , ( ( unsigned int ) V_19 / 1000 ) ,
( ( unsigned int ) V_19 % 1000 ) ) ;
else
printf ( L_17 , V_19 ) ;
} else {
if ( V_19 > 1000000 ) {
V_17 = V_19 % 10000 ;
if ( V_17 >= 5000 )
V_19 += 10000 ;
printf ( L_18 , ( ( unsigned int ) V_19 / 1000000 ) ,
( ( unsigned int ) ( V_19 % 1000000 ) / 10000 ) ) ;
} else if ( V_19 > 100000 ) {
V_17 = V_19 % 1000 ;
if ( V_17 >= 500 )
V_19 += 1000 ;
printf ( L_15 , ( ( unsigned int ) V_19 / 1000 ) ) ;
} else if ( V_19 > 1000 ) {
V_17 = V_19 % 100 ;
if ( V_17 >= 50 )
V_19 += 100 ;
printf ( L_19 , ( ( unsigned int ) V_19 / 1000 ) ,
( ( unsigned int ) ( V_19 % 1000 ) / 100 ) ) ;
} else
printf ( L_17 , V_19 ) ;
}
return;
}
static int F_8 ( unsigned int V_7 )
{
int V_20 , V_21 , V_22 = 0 , V_4 , V_23 , V_24 ;
unsigned long V_25 [ V_26 ] = { 0 ,} ;
if ( V_27 . V_28 != V_29 &&
V_27 . V_28 != V_30 )
return 0 ;
V_4 = F_9 ( V_7 , & V_20 , & V_21 , & V_22 ) ;
if ( V_4 ) {
printf ( _ ( L_20
L_21 ) , V_7 ) ;
return V_4 ;
}
printf ( _ ( L_22 ) ) ;
printf ( _ ( L_23 ) , V_20 ? _ ( L_24 ) : _ ( L_25 ) ) ;
printf ( _ ( L_26 ) , V_21 ? _ ( L_24 ) : _ ( L_25 ) ) ;
if ( V_27 . V_28 == V_29 &&
V_27 . V_31 >= 0x10 ) {
V_4 = F_10 ( V_7 , V_27 . V_31 , V_22 ,
V_25 , & V_23 ) ;
if ( V_4 )
return V_4 ;
printf ( _ ( L_27 ) , V_22 ) ;
printf ( _ ( L_28 ) , V_23 ) ;
for ( V_24 = 0 ; V_24 < V_23 ; V_24 ++ ) {
if ( V_24 < V_22 )
printf ( _ ( L_29
L_30 ) , V_24 , V_25 [ V_24 ] ) ;
else
printf ( _ ( L_31 ) ,
V_24 - V_22 , V_25 [ V_24 ] ) ;
}
} else if ( V_27 . V_32 & V_33 ) {
double V_34 ;
unsigned long long V_35 = 0 ;
unsigned int V_36 ;
if ( V_27 . V_32 & V_37 )
V_34 = 100.00 ;
else
V_34 = 133.33 ;
V_35 = F_11 ( V_7 ) ;
F_12 ( L_32 ,
V_35 , V_34 ) ;
V_36 = ( V_35 >> 24 ) & 0xFF ;
if ( V_36 )
printf ( _ ( L_33 ) ,
V_36 * V_34 ) ;
V_36 = ( V_35 >> 16 ) & 0xFF ;
if ( V_36 )
printf ( _ ( L_34 ) ,
V_36 * V_34 ) ;
V_36 = ( V_35 >> 8 ) & 0xFF ;
if ( V_36 )
printf ( _ ( L_35 ) ,
V_36 * V_34 ) ;
V_36 = ( V_35 >> 0 ) & 0xFF ;
if ( V_36 )
printf ( _ ( L_36 ) ,
V_36 * V_34 ) ;
}
return 0 ;
}
static void F_13 ( unsigned int V_7 )
{
char * V_38 ;
struct V_39 * V_40 ;
struct V_41 * V_42 ;
unsigned long V_13 , V_14 , V_43 , V_44 ;
unsigned long V_45 , V_46 ;
unsigned long long V_47 ;
struct V_9 * V_10 ;
struct V_48 * V_49 ;
struct V_50 * V_51 ;
if ( F_14 ( V_7 ) )
return;
V_43 = F_15 ( V_7 ) ;
V_44 = F_16 ( V_7 ) ;
V_38 = F_17 ( V_7 ) ;
if ( ! V_38 ) {
printf ( _ ( L_37 ) ) ;
} else {
printf ( _ ( L_38 ) , V_38 ) ;
F_18 ( V_38 ) ;
}
V_40 = F_19 ( V_7 ) ;
if ( V_40 ) {
printf ( _ ( L_39 ) ) ;
while ( V_40 -> V_52 ) {
printf ( L_40 , V_40 -> V_7 ) ;
V_40 = V_40 -> V_52 ;
}
printf ( L_41 , V_40 -> V_7 ) ;
F_20 ( V_40 ) ;
}
V_40 = F_21 ( V_7 ) ;
if ( V_40 ) {
printf ( _ ( L_42 ) ) ;
while ( V_40 -> V_52 ) {
printf ( L_40 , V_40 -> V_7 ) ;
V_40 = V_40 -> V_52 ;
}
printf ( L_41 , V_40 -> V_7 ) ;
F_22 ( V_40 ) ;
}
V_46 = F_23 ( V_7 ) ;
if ( V_46 ) {
printf ( _ ( L_43 ) ) ;
F_7 ( V_46 ) ;
printf ( L_44 ) ;
}
if ( ! ( F_4 ( V_7 , & V_13 , & V_14 ) ) ) {
printf ( _ ( L_45 ) ) ;
F_6 ( V_13 ) ;
printf ( L_46 ) ;
F_6 ( V_14 ) ;
printf ( L_30 ) ;
}
V_42 = F_24 ( V_7 ) ;
if ( V_42 ) {
printf ( _ ( L_47 ) ) ;
while ( V_42 -> V_52 ) {
F_6 ( V_42 -> V_53 ) ;
printf ( L_48 ) ;
V_42 = V_42 -> V_52 ;
}
F_6 ( V_42 -> V_53 ) ;
printf ( L_30 ) ;
F_25 ( V_42 ) ;
}
V_49 = F_26 ( V_7 ) ;
if ( V_49 ) {
printf ( _ ( L_49 ) ) ;
while ( V_49 -> V_52 ) {
printf ( L_50 , V_49 -> V_15 ) ;
V_49 = V_49 -> V_52 ;
}
printf ( L_51 , V_49 -> V_15 ) ;
F_27 ( V_49 ) ;
}
V_10 = F_3 ( V_7 ) ;
if ( V_10 ) {
printf ( _ ( L_52 ) ) ;
F_6 ( V_10 -> V_13 ) ;
printf ( _ ( L_53 ) ) ;
F_6 ( V_10 -> V_14 ) ;
printf ( L_54 ) ;
printf ( _ ( L_55
L_56 ) ,
V_10 -> V_15 ) ;
F_5 ( V_10 ) ;
}
if ( V_43 || V_44 ) {
printf ( _ ( L_57 ) ) ;
if ( V_44 ) {
F_6 ( V_44 ) ;
printf ( _ ( L_58 ) ) ;
} else
F_6 ( V_43 ) ;
printf ( L_44 ) ;
}
V_51 = F_28 ( V_7 , & V_47 ) ;
if ( V_51 ) {
printf ( _ ( L_59 ) ) ;
while ( V_51 ) {
F_6 ( V_51 -> V_53 ) ;
printf ( L_60 , ( 100.0 * V_51 -> V_54 ) / V_47 ) ;
V_51 = V_51 -> V_52 ;
if ( V_51 )
printf ( L_48 ) ;
}
F_29 ( V_51 ) ;
V_45 = F_30 ( V_7 ) ;
if ( V_45 )
printf ( L_61 , V_45 ) ;
else
printf ( L_30 ) ;
}
F_8 ( V_7 ) ;
}
static int F_31 ( unsigned int V_7 , unsigned int V_55 )
{
unsigned long V_56 = F_15 ( V_7 ) ;
if ( ! V_56 )
return - V_57 ;
if ( V_55 ) {
F_6 ( V_56 ) ;
printf ( L_30 ) ;
} else
printf ( L_62 , V_56 ) ;
return 0 ;
}
static int F_32 ( unsigned int V_7 , unsigned int V_55 )
{
unsigned long V_56 = F_16 ( V_7 ) ;
if ( ! V_56 )
return - V_57 ;
if ( V_55 ) {
F_6 ( V_56 ) ;
printf ( L_30 ) ;
} else
printf ( L_62 , V_56 ) ;
return 0 ;
}
static int F_33 ( unsigned int V_7 )
{
unsigned long V_13 , V_14 ;
if ( F_4 ( V_7 , & V_13 , & V_14 ) )
return - V_57 ;
printf ( L_63 , V_13 , V_14 ) ;
return 0 ;
}
static int F_34 ( unsigned int V_7 )
{
char * V_38 = F_17 ( V_7 ) ;
if ( ! V_38 )
return - V_57 ;
printf ( L_51 , V_38 ) ;
F_18 ( V_38 ) ;
return 0 ;
}
static int F_35 ( unsigned int V_7 )
{
struct V_9 * V_10 = F_3 ( V_7 ) ;
if ( ! V_10 )
return - V_57 ;
printf ( L_64 , V_10 -> V_13 , V_10 -> V_14 , V_10 -> V_15 ) ;
F_5 ( V_10 ) ;
return 0 ;
}
static int F_36 ( unsigned int V_7 )
{
struct V_48 * V_49 =
F_26 ( V_7 ) ;
if ( ! V_49 )
return - V_57 ;
while ( V_49 -> V_52 ) {
printf ( L_65 , V_49 -> V_15 ) ;
V_49 = V_49 -> V_52 ;
}
printf ( L_51 , V_49 -> V_15 ) ;
F_27 ( V_49 ) ;
return 0 ;
}
static int F_37 ( unsigned int V_7 )
{
struct V_39 * V_40 = F_21 ( V_7 ) ;
if ( ! V_40 )
return - V_57 ;
while ( V_40 -> V_52 ) {
printf ( L_40 , V_40 -> V_7 ) ;
V_40 = V_40 -> V_52 ;
}
printf ( L_41 , V_40 -> V_7 ) ;
F_22 ( V_40 ) ;
return 0 ;
}
static int F_38 ( unsigned int V_7 )
{
struct V_39 * V_40 = F_19 ( V_7 ) ;
if ( ! V_40 )
return - V_57 ;
while ( V_40 -> V_52 ) {
printf ( L_40 , V_40 -> V_7 ) ;
V_40 = V_40 -> V_52 ;
}
printf ( L_41 , V_40 -> V_7 ) ;
F_20 ( V_40 ) ;
return 0 ;
}
static int F_39 ( unsigned int V_7 , unsigned int V_55 )
{
unsigned long V_45 = F_30 ( V_7 ) ;
unsigned long long V_47 ;
struct V_50 * V_51 = F_28 ( V_7 , & V_47 ) ;
while ( V_51 ) {
if ( V_55 ) {
F_6 ( V_51 -> V_53 ) ;
printf ( L_60 ,
( 100.0 * V_51 -> V_54 ) / V_47 ) ;
} else
printf ( L_66 ,
V_51 -> V_53 , V_51 -> V_54 ) ;
V_51 = V_51 -> V_52 ;
if ( V_51 )
printf ( L_48 ) ;
}
F_29 ( V_51 ) ;
if ( V_45 )
printf ( L_61 , V_45 ) ;
return 0 ;
}
static int F_40 ( unsigned int V_7 , unsigned int V_55 )
{
unsigned long V_46 = F_23 ( V_7 ) ;
if ( ! V_46 )
return - V_57 ;
if ( V_55 ) {
F_7 ( V_46 ) ;
printf ( L_30 ) ;
} else
printf ( L_62 , V_46 ) ;
return 0 ;
}
int F_41 ( int V_58 , char * * V_59 )
{
extern char * V_60 ;
extern int V_61 , V_62 , V_63 ;
int V_4 = 0 , V_64 = 1 ;
unsigned int V_7 = 0 ;
unsigned int V_55 = 0 ;
int V_65 = 0 ;
do {
V_4 = F_42 ( V_58 , V_59 , L_67 , V_66 ,
NULL ) ;
switch ( V_4 ) {
case '?' :
V_65 = '?' ;
V_64 = 0 ;
break;
case - 1 :
V_64 = 0 ;
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
if ( V_65 ) {
V_65 = - 1 ;
V_64 = 0 ;
break;
}
V_65 = V_4 ;
break;
case 'm' :
if ( V_55 ) {
V_65 = - 1 ;
V_64 = 0 ;
break;
}
V_55 = 1 ;
break;
case 'n' :
V_18 = 1 ;
break;
default:
fprintf ( V_67 , L_68 ) ;
return V_68 ;
}
} while ( V_64 );
switch ( V_65 ) {
case 'o' :
if ( ! F_43 ( V_69 ) ) {
printf ( _ ( L_69
L_70 ) ) ;
return - V_57 ;
}
break;
case 0 :
V_65 = 'e' ;
}
V_4 = 0 ;
if ( F_43 ( V_69 ) )
F_44 ( V_69 , 0 ) ;
switch ( V_65 ) {
case - 1 :
printf ( _ ( L_71
L_72 ) ) ;
return - V_57 ;
case '?' :
printf ( _ ( L_68 ) ) ;
return - V_57 ;
case 'o' :
F_2 () ;
return V_70 ;
}
for ( V_7 = F_45 ( V_69 ) ;
V_7 <= F_46 ( V_69 ) ; V_7 ++ ) {
if ( ! F_47 ( V_69 , V_7 ) )
continue;
if ( F_14 ( V_7 ) ) {
printf ( _ ( L_73 ) , V_7 ) ;
continue;
}
printf ( _ ( L_74 ) , V_7 ) ;
switch ( V_65 ) {
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
V_4 = F_32 ( V_7 , V_55 ) ;
break;
case 'f' :
V_4 = F_31 ( V_7 , V_55 ) ;
break;
case 's' :
V_4 = F_39 ( V_7 , V_55 ) ;
break;
case 'y' :
V_4 = F_40 ( V_7 , V_55 ) ;
break;
}
if ( V_4 )
return V_4 ;
}
return V_4 ;
}
