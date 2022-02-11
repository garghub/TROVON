static bool F_1 ( void )
{
return V_1 || F_2 () ;
}
static enum V_2 F_3 ( int V_3 )
{
struct V_4 * V_5 ;
int * V_6 ;
T_1 V_7 ;
V_5 = F_4 ( V_8 , V_3 , & V_7 , NULL ) ;
if ( ! V_5 )
return V_9 ;
V_6 = F_5 ( V_5 ) ;
if ( * V_6 != V_3 ) {
F_6 () ;
return V_9 ;
}
V_10 ++ ;
return V_11 ;
}
static enum V_2 F_7 ( int V_3 )
{
struct V_4 * V_5 ;
struct V_12 * V_13 ;
unsigned long V_14 ;
void * V_15 ;
int * V_6 ;
int V_16 ;
int V_17 ;
int V_18 ;
V_15 = F_8 ( V_8 , V_3 ) ;
if ( ! V_15 )
return V_9 ;
V_16 = F_9 ( V_8 , & V_15 , V_19 , V_3 , 1 ) ;
if ( V_16 >= 0 ) {
V_13 = V_15 ;
V_14 = F_10 ( & V_13 -> V_14 ) & 0xfffff ;
for ( V_18 = 0 ; V_18 < V_14 && ! V_1 ; V_18 += V_17 ) {
if ( V_18 >= ( V_19 - F_11 ( struct V_12 , V_20 ) ) ) {
F_6 () ;
break;
}
V_17 = - 1 ;
V_5 = ( void * ) & V_13 -> V_20 [ V_18 ] ;
switch ( V_5 -> V_21 ) {
case V_22 :
if ( ! V_5 -> V_23 )
F_6 () ;
V_17 = V_5 -> V_24 [ 0 ] + 4 ;
break;
case V_25 :
V_17 = 8 ;
break;
case 0 :
V_6 = F_5 ( V_5 ) ;
if ( * V_6 != V_3 ) {
F_6 () ;
break;
}
V_10 ++ ;
if ( ! V_5 -> V_24 [ 0 ] ) {
F_6 () ;
break;
}
V_17 = V_5 -> V_24 [ 0 ] + 4 ;
break;
default:
V_6 = F_5 ( V_5 ) ;
if ( * V_6 != V_3 ) {
F_6 () ;
break;
}
V_10 ++ ;
V_17 = ( ( V_5 -> V_21 + 1 ) * 4 ) ;
}
if ( V_1 )
break;
if ( V_17 <= 0 ) {
F_6 () ;
break;
}
}
}
F_12 ( V_8 , V_3 , V_15 ) ;
if ( V_16 < 0 )
return V_9 ;
return V_11 ;
}
static void F_13 ( void )
{
V_26 ^= 1 ;
V_10 = 0 ;
while ( ! F_14 ( V_27 ) ) {
int V_28 = 1 ;
while ( V_28 && ! V_1 ) {
int V_3 ;
V_28 = 0 ;
F_15 (cpu) {
enum V_2 V_29 ;
if ( V_26 )
V_29 = F_3 ( V_3 ) ;
else
V_29 = F_7 ( V_3 ) ;
if ( V_1 )
break;
if ( V_29 == V_11 )
V_28 = 1 ;
}
}
F_16 ( V_30 ) ;
if ( V_27 )
break;
F_17 () ;
}
F_18 ( V_31 ) ;
V_27 = 0 ;
F_19 ( & V_32 ) ;
}
static void F_20 ( void )
{
T_2 V_33 , V_34 , V_35 ;
unsigned long long time ;
unsigned long long V_36 ;
unsigned long long V_37 ;
unsigned long V_38 = 0 ;
unsigned long V_39 = 0 ;
unsigned long V_40 ;
int V_41 = 0 ;
F_21 ( L_1 ) ;
V_33 = F_22 () ;
V_35 = F_23 ( V_33 , V_42 * V_43 ) ;
do {
struct V_4 * V_5 ;
int * V_6 ;
int V_18 ;
for ( V_18 = 0 ; V_18 < V_44 ; V_18 ++ ) {
V_5 = F_24 ( V_8 , 10 ) ;
if ( ! V_5 ) {
V_38 ++ ;
} else {
V_39 ++ ;
V_6 = F_5 ( V_5 ) ;
* V_6 = F_25 () ;
F_26 ( V_8 , V_5 ) ;
}
}
V_34 = F_22 () ;
V_41 ++ ;
if ( V_45 && ! ( V_41 % V_46 ) )
F_27 ( V_45 ) ;
#ifndef F_28
if ( V_41 % V_46 )
F_29 () ;
#endif
} while ( F_30 ( V_34 , V_35 ) && ! F_1 () );
F_21 ( L_2 ) ;
if ( V_45 ) {
F_31 ( & V_47 ) ;
F_31 ( & V_32 ) ;
F_32 () ;
V_27 = 1 ;
F_27 ( V_45 ) ;
F_33 ( & V_32 ) ;
}
time = F_34 ( V_34 , V_33 ) ;
V_36 = F_35 ( V_8 ) ;
V_37 = F_36 ( V_8 ) ;
if ( V_1 )
F_21 ( L_3 ) ;
if ( ! V_48 ) {
if ( V_49 < 0 )
F_21 ( L_4 ,
V_50 ) ;
else
F_21 ( L_5 ,
V_49 ) ;
}
if ( V_51 < 0 )
F_21 ( L_6 ,
V_52 ) ;
else
F_21 ( L_7 ,
V_51 ) ;
if ( V_51 < 0 && V_49 < 0 &&
V_52 == V_53 && V_50 == V_53 )
F_21 ( L_8 ) ;
F_21 ( L_9 , time ) ;
F_21 ( L_10 , V_37 ) ;
if ( V_48 )
F_21 ( L_11 ) ;
else
F_21 ( L_12 , V_10 ,
V_26 ? L_13 : L_14 ) ;
F_21 ( L_15 , V_36 ) ;
F_21 ( L_16 , V_36 + V_37 + V_10 ) ;
F_21 ( L_17 , V_38 ) ;
F_21 ( L_18 , V_39 ) ;
F_37 ( time , V_54 ) ;
if ( time )
V_39 /= ( long ) time ;
else
F_21 ( L_19 ) ;
F_21 ( L_20 , V_39 ) ;
if ( V_39 ) {
V_40 = V_55 / V_39 ;
F_21 ( L_21 , V_40 ) ;
}
if ( V_38 ) {
if ( time )
V_38 /= ( long ) time ;
F_21 ( L_22 ,
V_39 + V_38 ) ;
if ( ! ( V_39 + V_38 ) ) {
F_21 ( L_23 ) ;
V_39 -- ;
}
V_40 = V_55 / ( V_39 + V_38 ) ;
F_21 ( L_21 , V_40 ) ;
}
}
static void F_38 ( void )
{
F_16 ( V_30 ) ;
while ( ! F_2 () ) {
F_17 () ;
F_16 ( V_30 ) ;
}
F_18 ( V_31 ) ;
}
static int F_39 ( void * V_56 )
{
while ( ! F_1 () ) {
F_19 ( & V_47 ) ;
F_13 () ;
F_16 ( V_30 ) ;
if ( F_1 () )
break;
F_17 () ;
}
F_18 ( V_31 ) ;
if ( ! F_2 () )
F_38 () ;
return 0 ;
}
static int F_40 ( void * V_56 )
{
while ( ! F_1 () ) {
F_41 ( V_8 ) ;
if ( V_45 ) {
F_27 ( V_45 ) ;
F_33 ( & V_47 ) ;
}
F_20 () ;
if ( F_1 () )
goto V_57;
F_21 ( L_24 ) ;
F_16 ( V_30 ) ;
if ( F_1 () )
goto V_57;
F_42 ( V_58 * V_59 ) ;
}
V_57:
F_18 ( V_31 ) ;
if ( ! F_2 () )
F_38 () ;
return 0 ;
}
static int T_3 F_43 ( void )
{
int V_16 ;
V_8 = F_44 ( 1000000 , V_60 ) ;
if ( ! V_8 )
return - V_61 ;
if ( ! V_48 ) {
V_45 = F_45 ( F_39 ,
NULL , L_25 ) ;
V_16 = F_46 ( V_45 ) ;
if ( F_47 ( V_45 ) )
goto V_62;
}
V_63 = F_48 ( F_40 ,
NULL , L_26 ) ;
V_16 = F_46 ( V_63 ) ;
if ( F_47 ( V_63 ) )
goto V_57;
if ( ! V_48 ) {
if ( V_49 >= 0 ) {
struct V_64 V_65 = {
. V_66 = V_49
} ;
F_49 ( V_45 , V_67 , & V_65 ) ;
} else
F_50 ( V_45 , V_50 ) ;
}
if ( V_51 >= 0 ) {
struct V_64 V_65 = {
. V_66 = V_51
} ;
F_49 ( V_63 , V_67 , & V_65 ) ;
} else
F_50 ( V_63 , V_52 ) ;
return 0 ;
V_57:
if ( V_45 )
F_51 ( V_45 ) ;
V_62:
F_52 ( V_8 ) ;
return V_16 ;
}
static void T_4 F_53 ( void )
{
F_51 ( V_63 ) ;
if ( V_45 )
F_51 ( V_45 ) ;
F_52 ( V_8 ) ;
}
