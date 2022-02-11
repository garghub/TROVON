static enum V_1 F_1 ( int V_2 )
{
struct V_3 * V_4 ;
int * V_5 ;
T_1 V_6 ;
V_4 = F_2 ( V_7 , V_2 , & V_6 , NULL ) ;
if ( ! V_4 )
return V_8 ;
V_5 = F_3 ( V_4 ) ;
if ( * V_5 != V_2 ) {
F_4 () ;
return V_8 ;
}
V_9 ++ ;
return V_10 ;
}
static enum V_1 F_5 ( int V_2 )
{
struct V_3 * V_4 ;
struct V_11 * V_12 ;
unsigned long V_13 ;
void * V_14 ;
int * V_5 ;
int V_15 ;
int V_16 ;
int V_17 ;
V_14 = F_6 ( V_7 , V_2 ) ;
if ( ! V_14 )
return V_8 ;
V_15 = F_7 ( V_7 , & V_14 , V_18 , V_2 , 1 ) ;
if ( V_15 >= 0 ) {
V_12 = V_14 ;
V_13 = F_8 ( & V_12 -> V_13 ) & 0xfffff ;
for ( V_17 = 0 ; V_17 < V_13 && ! V_19 ; V_17 += V_16 ) {
if ( V_17 >= ( V_18 - F_9 ( struct V_11 , V_20 ) ) ) {
F_4 () ;
break;
}
V_16 = - 1 ;
V_4 = ( void * ) & V_12 -> V_20 [ V_17 ] ;
switch ( V_4 -> V_21 ) {
case V_22 :
if ( ! V_4 -> V_23 )
F_4 () ;
V_16 = V_4 -> V_24 [ 0 ] + 4 ;
break;
case V_25 :
V_16 = 8 ;
break;
case 0 :
V_5 = F_3 ( V_4 ) ;
if ( * V_5 != V_2 ) {
F_4 () ;
break;
}
V_9 ++ ;
if ( ! V_4 -> V_24 [ 0 ] ) {
F_4 () ;
break;
}
V_16 = V_4 -> V_24 [ 0 ] + 4 ;
break;
default:
V_5 = F_3 ( V_4 ) ;
if ( * V_5 != V_2 ) {
F_4 () ;
break;
}
V_9 ++ ;
V_16 = ( ( V_4 -> V_21 + 1 ) * 4 ) ;
}
if ( V_19 )
break;
if ( V_16 <= 0 ) {
F_4 () ;
break;
}
}
}
F_10 ( V_7 , V_14 ) ;
if ( V_15 < 0 )
return V_8 ;
return V_10 ;
}
static void F_11 ( void )
{
V_26 ^= 1 ;
V_9 = 0 ;
while ( ! V_27 && ! V_19 ) {
int V_28 ;
do {
int V_2 ;
V_28 = 0 ;
F_12 (cpu) {
enum V_1 V_29 ;
if ( V_26 )
V_29 = F_1 ( V_2 ) ;
else
V_29 = F_5 ( V_2 ) ;
if ( V_19 )
break;
if ( V_29 == V_10 )
V_28 = 1 ;
}
} while ( V_28 && ! V_19 );
F_13 ( V_30 ) ;
if ( V_27 )
break;
F_14 () ;
}
V_27 = 0 ;
F_15 ( & V_31 ) ;
}
static void F_16 ( void )
{
T_2 V_32 , V_33 , V_34 ;
unsigned long long time ;
unsigned long long V_35 ;
unsigned long long V_36 ;
unsigned long V_37 = 0 ;
unsigned long V_38 = 0 ;
unsigned long V_39 ;
int V_40 = 0 ;
F_17 ( L_1 ) ;
V_32 = F_18 () ;
V_34 = F_19 ( V_32 , V_41 * V_42 ) ;
do {
struct V_3 * V_4 ;
int * V_5 ;
int V_17 ;
for ( V_17 = 0 ; V_17 < V_43 ; V_17 ++ ) {
V_4 = F_20 ( V_7 , 10 ) ;
if ( ! V_4 ) {
V_37 ++ ;
} else {
V_38 ++ ;
V_5 = F_3 ( V_4 ) ;
* V_5 = F_21 () ;
F_22 ( V_7 , V_4 ) ;
}
}
V_33 = F_18 () ;
V_40 ++ ;
if ( V_44 && ! ( V_40 % V_45 ) )
F_23 ( V_44 ) ;
#ifndef F_24
if ( V_40 % V_45 )
F_25 () ;
#endif
} while ( F_26 ( V_33 , V_34 ) && ! V_19 );
F_17 ( L_2 ) ;
if ( V_44 ) {
F_27 ( & V_46 ) ;
F_27 ( & V_31 ) ;
F_28 () ;
V_27 = 1 ;
F_28 () ;
F_23 ( V_44 ) ;
F_29 ( & V_31 ) ;
}
time = F_30 ( V_33 , V_32 ) ;
V_35 = F_31 ( V_7 ) ;
V_36 = F_32 ( V_7 ) ;
if ( V_19 )
F_17 ( L_3 ) ;
if ( ! V_47 ) {
if ( V_48 < 0 )
F_17 ( L_4 ,
V_49 ) ;
else
F_17 ( L_5 ,
V_48 ) ;
}
if ( V_50 < 0 )
F_17 ( L_6 ,
V_51 ) ;
else
F_17 ( L_7 ,
V_50 ) ;
if ( V_50 < 0 && V_48 < 0 &&
V_51 == V_52 && V_49 == V_52 )
F_17 ( L_8 ) ;
F_17 ( L_9 , time ) ;
F_17 ( L_10 , V_36 ) ;
if ( V_47 )
F_17 ( L_11 ) ;
else
F_17 ( L_12 , V_9 ,
V_26 ? L_13 : L_14 ) ;
F_17 ( L_15 , V_35 ) ;
F_17 ( L_16 , V_35 + V_36 + V_9 ) ;
F_17 ( L_17 , V_37 ) ;
F_17 ( L_18 , V_38 ) ;
F_33 ( time , V_53 ) ;
if ( time )
V_38 /= ( long ) time ;
else
F_17 ( L_19 ) ;
F_17 ( L_20 , V_38 ) ;
if ( V_38 ) {
V_39 = V_54 / V_38 ;
F_17 ( L_21 , V_39 ) ;
}
if ( V_37 ) {
if ( time )
V_37 /= ( long ) time ;
F_17 ( L_22 ,
V_38 + V_37 ) ;
if ( ! ( V_38 + V_37 ) ) {
F_17 ( L_23 ) ;
V_38 -- ;
}
V_39 = V_54 / ( V_38 + V_37 ) ;
F_17 ( L_21 , V_39 ) ;
}
}
static void F_34 ( void )
{
F_13 ( V_30 ) ;
while ( ! F_35 () ) {
F_14 () ;
F_13 ( V_30 ) ;
}
F_36 ( V_55 ) ;
}
static int F_37 ( void * V_56 )
{
while ( ! F_35 () && ! V_19 ) {
F_15 ( & V_46 ) ;
F_11 () ;
F_13 ( V_30 ) ;
if ( F_35 () || V_19 )
break;
F_14 () ;
}
F_36 ( V_55 ) ;
if ( V_19 )
F_34 () ;
return 0 ;
}
static int F_38 ( void * V_56 )
{
F_27 ( & V_46 ) ;
while ( ! F_35 () && ! V_19 ) {
F_39 ( V_7 ) ;
if ( V_44 ) {
F_28 () ;
F_23 ( V_44 ) ;
F_29 ( & V_46 ) ;
}
F_16 () ;
F_17 ( L_24 ) ;
F_13 ( V_30 ) ;
F_40 ( V_57 * V_58 ) ;
}
if ( V_19 )
F_34 () ;
return 0 ;
}
static int T_3 F_41 ( void )
{
int V_15 ;
V_7 = F_42 ( 1000000 , V_59 ) ;
if ( ! V_7 )
return - V_60 ;
if ( ! V_47 ) {
V_44 = F_43 ( F_37 ,
NULL , L_25 ) ;
V_15 = F_44 ( V_44 ) ;
if ( F_45 ( V_44 ) )
goto V_61;
}
V_62 = F_46 ( F_38 ,
NULL , L_26 ) ;
V_15 = F_44 ( V_62 ) ;
if ( F_45 ( V_62 ) )
goto V_63;
if ( ! V_47 ) {
if ( V_48 >= 0 ) {
struct V_64 V_65 = {
. V_66 = V_48
} ;
F_47 ( V_44 , V_67 , & V_65 ) ;
} else
F_48 ( V_44 , V_49 ) ;
}
if ( V_50 >= 0 ) {
struct V_64 V_65 = {
. V_66 = V_50
} ;
F_47 ( V_62 , V_67 , & V_65 ) ;
} else
F_48 ( V_62 , V_51 ) ;
return 0 ;
V_63:
if ( V_44 )
F_49 ( V_44 ) ;
V_61:
F_50 ( V_7 ) ;
return V_15 ;
}
static void T_4 F_51 ( void )
{
F_49 ( V_62 ) ;
if ( V_44 )
F_49 ( V_44 ) ;
F_50 ( V_7 ) ;
}
