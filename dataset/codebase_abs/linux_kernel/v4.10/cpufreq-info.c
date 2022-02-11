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
static int F_13 ( unsigned int V_7 , unsigned int V_38 )
{
unsigned long V_39 = F_14 ( V_7 ) ;
printf ( _ ( L_37 ) ) ;
if ( ! V_39 ) {
printf ( _ ( L_38 ) ) ;
return - V_40 ;
}
if ( V_38 ) {
F_6 ( V_39 ) ;
} else
printf ( L_39 , V_39 ) ;
printf ( _ ( L_40 ) ) ;
return 0 ;
}
static int F_15 ( unsigned int V_7 , unsigned int V_38 )
{
unsigned long V_39 = F_16 ( V_7 ) ;
printf ( _ ( L_37 ) ) ;
if ( ! V_39 ) {
printf ( L_41 ) ;
return - V_40 ;
}
if ( V_38 ) {
F_6 ( V_39 ) ;
} else
printf ( L_39 , V_39 ) ;
printf ( _ ( L_42 ) ) ;
return 0 ;
}
static int F_17 ( unsigned int V_7 )
{
unsigned long V_13 , V_14 ;
printf ( _ ( L_43 ) ) ;
if ( F_4 ( V_7 , & V_13 , & V_14 ) ) {
printf ( _ ( L_44 ) ) ;
return - V_40 ;
}
F_6 ( V_13 ) ;
printf ( L_45 ) ;
F_6 ( V_14 ) ;
printf ( L_30 ) ;
return 0 ;
}
static int F_18 ( unsigned int V_7 )
{
char * V_41 = F_19 ( V_7 ) ;
if ( ! V_41 ) {
printf ( _ ( L_46 ) ) ;
return - V_40 ;
}
printf ( L_47 , V_41 ) ;
F_20 ( V_41 ) ;
return 0 ;
}
static int F_21 ( unsigned int V_7 )
{
struct V_9 * V_10 = F_3 ( V_7 ) ;
if ( ! V_10 ) {
printf ( _ ( L_48 ) ) ;
return - V_40 ;
}
printf ( _ ( L_49 ) ) ;
F_6 ( V_10 -> V_13 ) ;
printf ( _ ( L_50 ) ) ;
F_6 ( V_10 -> V_14 ) ;
printf ( L_51 ) ;
printf ( _ ( L_52
L_53 ) ,
V_10 -> V_15 ) ;
F_5 ( V_10 ) ;
return 0 ;
}
static int F_22 ( unsigned int V_7 )
{
struct V_42 * V_43 =
F_23 ( V_7 ) ;
printf ( _ ( L_54 ) ) ;
if ( ! V_43 ) {
printf ( _ ( L_44 ) ) ;
return - V_40 ;
}
while ( V_43 -> V_44 ) {
printf ( L_55 , V_43 -> V_15 ) ;
V_43 = V_43 -> V_44 ;
}
printf ( L_56 , V_43 -> V_15 ) ;
F_24 ( V_43 ) ;
return 0 ;
}
static int F_25 ( unsigned int V_7 )
{
struct V_45 * V_46 = F_26 ( V_7 ) ;
printf ( _ ( L_57 ) ) ;
if ( ! V_46 ) {
printf ( _ ( L_44 ) ) ;
return - V_40 ;
}
while ( V_46 -> V_44 ) {
printf ( L_58 , V_46 -> V_7 ) ;
V_46 = V_46 -> V_44 ;
}
printf ( L_59 , V_46 -> V_7 ) ;
F_27 ( V_46 ) ;
return 0 ;
}
static int F_28 ( unsigned int V_7 )
{
struct V_45 * V_46 = F_29 ( V_7 ) ;
printf ( _ ( L_60 ) ) ;
if ( ! V_46 ) {
printf ( _ ( L_44 ) ) ;
return - V_40 ;
}
while ( V_46 -> V_44 ) {
printf ( L_58 , V_46 -> V_7 ) ;
V_46 = V_46 -> V_44 ;
}
printf ( L_59 , V_46 -> V_7 ) ;
F_30 ( V_46 ) ;
return 0 ;
}
static int F_31 ( unsigned int V_7 , unsigned int V_38 )
{
unsigned long V_47 = F_32 ( V_7 ) ;
unsigned long long V_48 ;
struct V_49 * V_50 = F_33 ( V_7 , & V_48 ) ;
while ( V_50 ) {
if ( V_38 ) {
F_6 ( V_50 -> V_51 ) ;
printf ( L_61 ,
( 100.0 * V_50 -> V_52 ) / V_48 ) ;
} else
printf ( L_62 ,
V_50 -> V_51 , V_50 -> V_52 ) ;
V_50 = V_50 -> V_44 ;
if ( V_50 )
printf ( L_63 ) ;
}
F_34 ( V_50 ) ;
if ( V_47 )
printf ( L_64 , V_47 ) ;
return 0 ;
}
static int F_35 ( unsigned int V_7 , unsigned int V_38 )
{
unsigned long V_53 = F_36 ( V_7 ) ;
printf ( _ ( L_65 ) ) ;
if ( ! V_53 || V_53 == V_54 ) {
printf ( _ ( L_66 ) ) ;
return - V_40 ;
}
if ( V_38 ) {
F_7 ( V_53 ) ;
printf ( L_30 ) ;
} else
printf ( L_67 , V_53 ) ;
return 0 ;
}
static void F_37 ( unsigned int V_7 )
{
struct V_55 * V_56 ;
F_18 ( V_7 ) ;
F_28 ( V_7 ) ;
F_25 ( V_7 ) ;
F_35 ( V_7 , 1 ) ;
F_17 ( V_7 ) ;
V_56 = F_38 ( V_7 ) ;
if ( V_56 ) {
printf ( _ ( L_68 ) ) ;
while ( V_56 -> V_44 ) {
F_6 ( V_56 -> V_51 ) ;
printf ( L_63 ) ;
V_56 = V_56 -> V_44 ;
}
F_6 ( V_56 -> V_51 ) ;
printf ( L_30 ) ;
F_39 ( V_56 ) ;
}
F_22 ( V_7 ) ;
F_21 ( V_7 ) ;
if ( F_15 ( V_7 , 1 ) < 0 )
F_13 ( V_7 , 1 ) ;
F_8 ( V_7 ) ;
}
int F_40 ( int V_57 , char * * V_58 )
{
extern char * V_59 ;
extern int V_60 , V_61 , V_62 ;
int V_4 = 0 , V_63 = 1 ;
unsigned int V_7 = 0 ;
unsigned int V_38 = 0 ;
int V_64 = 0 ;
do {
V_4 = F_41 ( V_57 , V_58 , L_69 , V_65 ,
NULL ) ;
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
if ( V_38 ) {
V_64 = - 1 ;
V_63 = 0 ;
break;
}
V_38 = 1 ;
break;
case 'n' :
V_18 = 1 ;
break;
default:
fprintf ( V_66 , L_70 ) ;
return V_67 ;
}
} while ( V_63 );
switch ( V_64 ) {
case 'o' :
if ( ! F_42 ( V_68 ) ) {
printf ( _ ( L_71
L_72 ) ) ;
return - V_40 ;
}
break;
case 0 :
V_64 = 'e' ;
}
V_4 = 0 ;
if ( F_42 ( V_68 ) )
F_43 ( V_68 , 0 ) ;
switch ( V_64 ) {
case - 1 :
printf ( _ ( L_73
L_74 ) ) ;
return - V_40 ;
case '?' :
printf ( _ ( L_70 ) ) ;
return - V_40 ;
case 'o' :
F_2 () ;
return V_69 ;
}
for ( V_7 = F_44 ( V_68 ) ;
V_7 <= F_45 ( V_68 ) ; V_7 ++ ) {
if ( ! F_46 ( V_68 , V_7 ) )
continue;
printf ( _ ( L_75 ) , V_7 ) ;
if ( F_47 ( V_7 ) != 1 ) {
printf ( _ ( L_76 ) ) ;
printf ( L_30 ) ;
continue;
}
switch ( V_64 ) {
case 'b' :
F_8 ( V_7 ) ;
break;
case 'e' :
F_37 ( V_7 ) ;
break;
case 'a' :
V_4 = F_25 ( V_7 ) ;
break;
case 'r' :
V_4 = F_28 ( V_7 ) ;
break;
case 'g' :
V_4 = F_22 ( V_7 ) ;
break;
case 'p' :
V_4 = F_21 ( V_7 ) ;
break;
case 'd' :
V_4 = F_18 ( V_7 ) ;
break;
case 'l' :
V_4 = F_17 ( V_7 ) ;
break;
case 'w' :
V_4 = F_15 ( V_7 , V_38 ) ;
break;
case 'f' :
V_4 = F_13 ( V_7 , V_38 ) ;
break;
case 's' :
V_4 = F_31 ( V_7 , V_38 ) ;
break;
case 'y' :
V_4 = F_35 ( V_7 , V_38 ) ;
break;
}
if ( V_4 )
return V_4 ;
printf ( L_30 ) ;
}
return V_4 ;
}
