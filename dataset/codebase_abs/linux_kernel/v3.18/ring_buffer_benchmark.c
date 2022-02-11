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
struct V_32 V_33 ;
struct V_32 V_34 ;
unsigned long long time ;
unsigned long long V_35 ;
unsigned long long V_36 ;
unsigned long V_37 = 0 ;
unsigned long V_38 = 0 ;
unsigned long V_39 ;
int V_40 = 0 ;
F_17 ( L_1 ) ;
F_18 ( & V_33 ) ;
do {
struct V_3 * V_4 ;
int * V_5 ;
int V_17 ;
for ( V_17 = 0 ; V_17 < V_41 ; V_17 ++ ) {
V_4 = F_19 ( V_7 , 10 ) ;
if ( ! V_4 ) {
V_37 ++ ;
} else {
V_38 ++ ;
V_5 = F_3 ( V_4 ) ;
* V_5 = F_20 () ;
F_21 ( V_7 , V_4 ) ;
}
}
F_18 ( & V_34 ) ;
V_40 ++ ;
if ( V_42 && ! ( V_40 % V_43 ) )
F_22 ( V_42 ) ;
#ifndef F_23
if ( V_40 % V_43 )
F_24 () ;
#endif
} while ( V_34 . V_44 < ( V_33 . V_44 + V_45 ) && ! V_19 );
F_17 ( L_2 ) ;
if ( V_42 ) {
F_25 ( & V_46 ) ;
F_25 ( & V_31 ) ;
F_26 () ;
V_27 = 1 ;
F_26 () ;
F_22 ( V_42 ) ;
F_27 ( & V_31 ) ;
}
time = V_34 . V_44 - V_33 . V_44 ;
time *= V_47 ;
time += ( long long ) ( ( long ) V_34 . V_48 - ( long ) V_33 . V_48 ) ;
V_35 = F_28 ( V_7 ) ;
V_36 = F_29 ( V_7 ) ;
if ( V_19 )
F_17 ( L_3 ) ;
if ( ! V_49 ) {
if ( V_50 < 0 )
F_17 ( L_4 ,
V_51 ) ;
else
F_17 ( L_5 ,
V_50 ) ;
}
if ( V_52 < 0 )
F_17 ( L_6 ,
V_53 ) ;
else
F_17 ( L_7 ,
V_52 ) ;
if ( V_52 < 0 && V_50 < 0 &&
V_53 == V_54 && V_51 == V_54 )
F_17 ( L_8 ) ;
F_17 ( L_9 , time ) ;
F_17 ( L_10 , V_36 ) ;
if ( V_49 )
F_17 ( L_11 ) ;
else
F_17 ( L_12 , V_9 ,
V_26 ? L_13 : L_14 ) ;
F_17 ( L_15 , V_35 ) ;
F_17 ( L_16 , V_35 + V_36 + V_9 ) ;
F_17 ( L_17 , V_37 ) ;
F_17 ( L_18 , V_38 ) ;
F_30 ( time , V_55 ) ;
if ( time )
V_38 /= ( long ) time ;
else
F_17 ( L_19 ) ;
F_17 ( L_20 , V_38 ) ;
if ( V_38 ) {
V_39 = V_56 / V_38 ;
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
V_39 = V_56 / ( V_38 + V_37 ) ;
F_17 ( L_21 , V_39 ) ;
}
}
static void F_31 ( void )
{
F_13 ( V_30 ) ;
while ( ! F_32 () ) {
F_14 () ;
F_13 ( V_30 ) ;
}
F_33 ( V_57 ) ;
}
static int F_34 ( void * V_58 )
{
while ( ! F_32 () && ! V_19 ) {
F_15 ( & V_46 ) ;
F_11 () ;
F_13 ( V_30 ) ;
if ( F_32 () || V_19 )
break;
F_14 () ;
}
F_33 ( V_57 ) ;
if ( V_19 )
F_31 () ;
return 0 ;
}
static int F_35 ( void * V_58 )
{
F_25 ( & V_46 ) ;
while ( ! F_32 () && ! V_19 ) {
F_36 ( V_7 ) ;
if ( V_42 ) {
F_26 () ;
F_22 ( V_42 ) ;
F_27 ( & V_46 ) ;
}
F_16 () ;
F_17 ( L_24 ) ;
F_13 ( V_30 ) ;
F_37 ( V_59 * V_60 ) ;
}
if ( V_19 )
F_31 () ;
return 0 ;
}
static int T_2 F_38 ( void )
{
int V_15 ;
V_7 = F_39 ( 1000000 , V_61 ) ;
if ( ! V_7 )
return - V_62 ;
if ( ! V_49 ) {
V_42 = F_40 ( F_34 ,
NULL , L_25 ) ;
V_15 = F_41 ( V_42 ) ;
if ( F_42 ( V_42 ) )
goto V_63;
}
V_64 = F_43 ( F_35 ,
NULL , L_26 ) ;
V_15 = F_41 ( V_64 ) ;
if ( F_42 ( V_64 ) )
goto V_65;
if ( ! V_49 ) {
if ( V_50 >= 0 ) {
struct V_66 V_67 = {
. V_68 = V_50
} ;
F_44 ( V_42 , V_69 , & V_67 ) ;
} else
F_45 ( V_42 , V_51 ) ;
}
if ( V_52 >= 0 ) {
struct V_66 V_67 = {
. V_68 = V_50
} ;
F_44 ( V_64 , V_69 , & V_67 ) ;
} else
F_45 ( V_64 , V_53 ) ;
return 0 ;
V_65:
if ( V_42 )
F_46 ( V_42 ) ;
V_63:
F_47 ( V_7 ) ;
return V_15 ;
}
static void T_3 F_48 ( void )
{
F_46 ( V_64 ) ;
if ( V_42 )
F_46 ( V_42 ) ;
F_47 ( V_7 ) ;
}
