T_1 T_2 * F_1 ( struct V_1 * V_2 , unsigned long V_3 )
{
T_2 * V_4 ;
if ( F_2 () ) {
V_4 = ( T_2 * ) F_3 ( V_5 | V_6 ) ;
} else {
V_4 = F_4 ( F_5 ( V_7 , V_7 ) ) ;
if ( V_4 )
F_6 ( V_4 ) ;
}
return V_4 ;
}
T_3 F_7 ( struct V_1 * V_2 , unsigned long V_3 )
{
struct V_8 * V_9 ;
T_4 V_10 = V_5 | V_6 | V_11 ;
V_9 = F_8 ( V_10 , 0 ) ;
if ( ! V_9 )
return NULL ;
if ( ! F_9 ( V_9 ) ) {
F_10 ( V_9 ) ;
return NULL ;
}
return V_9 ;
}
void T_5 *
F_11 ( T_6 V_12 , unsigned long V_13 )
{
return F_12 ( V_12 , V_13 , V_14 | V_15 ,
F_13 ( 0 ) ) ;
}
void T_5 *
F_14 ( T_6 V_12 , unsigned long V_13 )
{
return F_12 ( V_12 , V_13 , V_14 ,
F_13 ( 0 ) ) ;
}
void T_5 *
F_15 ( T_6 V_12 , unsigned long V_13 , unsigned long V_10 )
{
if ( ( V_10 & ( V_16 | V_17 ) ) != V_17 )
V_10 |= V_18 | V_19 ;
V_10 &= ~ ( V_20 | V_21 ) ;
#ifdef F_16
V_10 |= F_16 ;
#endif
return F_12 ( V_12 , V_13 , V_10 , F_13 ( 0 ) ) ;
}
void T_5 *
F_17 ( T_6 V_12 , unsigned long V_13 , unsigned long V_10 )
{
return F_12 ( V_12 , V_13 , V_10 , F_13 ( 0 ) ) ;
}
void T_5 *
F_12 ( T_6 V_12 , unsigned long V_13 , unsigned long V_10 ,
void * V_22 )
{
unsigned long V_23 , V_24 ;
T_6 V_25 ;
int V_26 ;
if ( ( V_10 & V_27 ) == 0 )
V_10 |= F_18 ( V_28 ) ;
if ( V_10 & V_14 )
V_10 &= ~ V_29 ;
V_25 = V_12 & V_30 ;
V_13 = F_19 ( V_12 + V_13 ) - V_25 ;
if ( V_25 < 16 * 1024 * 1024 )
V_25 += V_31 ;
#ifndef F_20
if ( F_2 () && ( V_25 < F_21 ( V_32 ) ) &&
! ( V_33 && F_22 ( V_25 , V_13 ) ) ) {
F_23 ( L_1 ,
( unsigned long long ) V_25 , F_13 ( 0 ) ) ;
return NULL ;
}
#endif
if ( V_13 == 0 )
return NULL ;
V_23 = F_24 ( V_25 ) ;
if ( V_23 )
goto V_34;
if ( F_2 () ) {
struct V_35 * V_36 ;
V_36 = F_25 ( V_13 , V_37 , V_22 ) ;
if ( V_36 == 0 )
return NULL ;
V_36 -> V_38 = V_25 ;
V_23 = ( unsigned long ) V_36 -> V_12 ;
} else {
V_23 = ( V_39 -= V_13 ) ;
}
V_26 = 0 ;
for ( V_24 = 0 ; V_24 < V_13 && V_26 == 0 ; V_24 += V_7 )
V_26 = F_26 ( V_23 + V_24 , V_25 + V_24 , V_10 ) ;
if ( V_26 ) {
if ( F_2 () )
F_27 ( ( void * ) V_23 ) ;
return NULL ;
}
V_34:
return ( void T_5 * ) ( V_23 + ( ( unsigned long ) V_12 & ~ V_30 ) ) ;
}
void F_28 ( volatile void T_5 * V_12 )
{
if ( F_29 ( ( unsigned long ) V_12 ) )
return;
if ( V_12 > V_32 && ( unsigned long ) V_12 < V_39 )
F_27 ( ( void * ) ( V_30 & ( unsigned long ) V_12 ) ) ;
}
int F_26 ( unsigned long V_40 , T_6 V_41 , int V_10 )
{
T_7 * V_42 ;
T_2 * V_43 ;
int V_26 = - V_44 ;
V_42 = F_30 ( F_31 ( F_32 ( V_40 ) , V_40 ) , V_40 ) ;
V_43 = F_33 ( V_42 , V_40 ) ;
if ( V_43 != 0 ) {
V_26 = 0 ;
F_34 ( ( F_35 ( * V_43 ) & ( V_27 | V_45 ) ) &&
V_10 ) ;
F_36 ( & V_46 , V_40 , V_43 , F_37 ( V_41 >> V_47 ,
F_38 ( V_10 ) ) ) ;
}
F_39 () ;
return V_26 ;
}
void T_8 F_40 ( unsigned long V_48 , unsigned long V_49 )
{
unsigned long V_23 , V_50 , V_51 ;
T_6 V_25 ;
int V_52 ;
V_50 = V_48 ;
V_23 = V_53 + V_50 ;
V_25 = V_54 + V_50 ;
for (; V_50 < V_49 ; V_50 += V_7 ) {
V_52 = ( ( char * ) V_23 >= V_55 && ( char * ) V_23 < V_56 ) ||
( ( char * ) V_23 >= V_57 && ( char * ) V_23 < V_58 ) ;
V_51 = V_52 ? F_18 ( V_59 ) : F_18 ( V_28 ) ;
F_26 ( V_23 , V_25 , V_51 ) ;
#ifdef F_41
if ( V_52 )
F_42 ( & V_46 , V_23 , 0 , 0x300 ) ;
#endif
V_23 += V_7 ;
V_25 += V_7 ;
}
}
void T_8 F_43 ( void )
{
unsigned long V_50 , V_49 ;
#ifndef F_44
V_49 = V_60 ;
V_50 = F_45 ( V_49 ) ;
F_40 ( V_50 , V_49 ) ;
#else
if ( ! V_61 ) {
V_50 = F_45 ( V_60 ) ;
F_40 ( V_50 , V_60 ) ;
} else {
V_49 = V_62 ;
V_50 = F_45 ( V_49 ) ;
F_40 ( V_50 , V_49 ) ;
V_49 = F_46 () ;
V_50 = F_47 ( V_49 ) ;
F_40 ( V_50 , V_49 ) ;
}
#endif
}
int
F_48 ( struct V_1 * V_2 , unsigned long V_12 , T_2 * * V_63 , T_7 * * V_64 )
{
T_9 * V_65 ;
T_10 * V_66 ;
T_7 * V_67 ;
T_2 * V_4 ;
int V_68 = 0 ;
V_65 = F_49 ( V_2 , V_12 & V_30 ) ;
if ( V_65 ) {
V_66 = F_31 ( V_65 , V_12 & V_30 ) ;
if ( V_66 && F_50 ( * V_66 ) ) {
V_67 = F_30 ( V_66 , V_12 & V_30 ) ;
if ( F_51 ( * V_67 ) ) {
V_4 = F_52 ( V_67 , V_12 & V_30 ) ;
if ( V_4 ) {
V_68 = 1 ;
* V_63 = V_4 ;
if ( V_64 )
* V_64 = V_67 ;
}
}
}
}
return ( V_68 ) ;
}
static int F_53 ( struct V_8 * V_8 , T_11 V_69 )
{
T_2 * V_70 ;
T_7 * V_71 ;
unsigned long V_3 ;
F_34 ( F_54 ( V_8 ) ) ;
V_3 = ( unsigned long ) F_55 ( V_8 ) ;
if ( F_29 ( V_3 ) )
return 0 ;
if ( ! F_48 ( & V_46 , V_3 , & V_70 , & V_71 ) )
return - V_72 ;
F_56 ( & V_46 , V_3 , V_70 , F_57 ( V_8 , V_69 ) , 0 ) ;
F_58 () ;
F_59 ( NULL , V_3 ) ;
F_60 ( V_70 ) ;
return 0 ;
}
static int F_61 ( struct V_8 * V_8 , int V_73 , T_11 V_69 )
{
int V_24 , V_26 = 0 ;
unsigned long V_10 ;
F_62 ( V_10 ) ;
for ( V_24 = 0 ; V_24 < V_73 ; V_24 ++ , V_8 ++ ) {
V_26 = F_53 ( V_8 , V_69 ) ;
if ( V_26 )
break;
}
F_63 ( V_10 ) ;
return V_26 ;
}
void F_64 ( struct V_8 * V_8 , int V_73 , int V_74 )
{
if ( F_54 ( V_8 ) )
return;
F_61 ( V_8 , V_73 , V_74 ? V_28 : F_38 ( 0 ) ) ;
}
void F_65 ( enum V_75 V_76 , T_6 V_77 , T_11 V_10 )
{
unsigned long V_3 = F_66 ( V_76 ) ;
if ( V_76 >= V_78 ) {
F_67 () ;
return;
}
F_26 ( V_3 , V_77 , F_18 ( V_10 ) ) ;
V_79 ++ ;
}
