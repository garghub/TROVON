static unsigned int F_1 ( unsigned int V_1 )
{
struct V_2 * V_3 ;
unsigned int V_4 , V_5 , V_6 ;
V_5 = V_7 - V_8 ;
while ( V_5 -- ) {
V_3 = V_9 [ V_1 ] ;
if ( V_3 -> V_10 . V_11 ) {
V_1 ++ ;
if ( V_1 > V_7 )
V_1 = V_8 ;
continue;
}
F_2 ( L_1 , V_1 , V_3 ) ;
V_3 -> V_10 . V_1 = V_12 ;
F_3 (cpu, mm_cpumask(mm)) {
for ( V_6 = F_4 ( V_4 ) ;
V_6 <= F_5 ( V_4 ) ; V_6 ++ )
F_6 ( V_1 , V_13 [ V_6 ] ) ;
V_4 = V_6 - 1 ;
}
return V_1 ;
}
F_7 ( & V_14 ) ;
F_8 () ;
F_9 ( & V_14 ) ;
return V_12 ;
}
static unsigned int F_10 ( unsigned int V_1 )
{
struct V_2 * V_3 ;
int V_4 = F_11 () ;
V_3 = V_9 [ V_1 ] ;
F_2 ( L_1 , V_1 , V_3 ) ;
F_12 ( V_3 ) ;
V_3 -> V_10 . V_1 = V_12 ;
F_13 ( V_1 , V_13 [ V_4 ] ) ;
return V_1 ;
}
static void F_14 ( void )
{
unsigned int V_1 , V_15 , V_16 ;
V_15 = V_16 = 0 ;
for ( V_1 = V_8 ; V_1 <= V_7 ; V_1 ++ ) {
int V_17 = F_15 ( V_1 , V_18 ) ;
if ( ! V_17 )
V_15 ++ ;
if ( V_17 != ( V_9 [ V_1 ] != NULL ) )
F_16 ( L_2 ,
V_1 , V_17 ? L_3 : L_4 , V_9 [ V_1 ] ) ;
if ( V_9 [ V_1 ] != NULL )
V_16 += V_9 [ V_1 ] -> V_10 . V_11 ;
}
if ( V_15 != V_19 ) {
F_16 ( L_5 ,
V_19 , V_15 ) ;
V_19 = V_15 ;
}
if ( V_16 > F_17 () )
F_16 ( L_6 ,
V_16 , F_17 () ) ;
if ( V_8 > 0 && ! F_15 ( 0 , V_18 ) )
F_16 ( L_7 ) ;
}
static void F_14 ( void ) { }
void F_18 ( struct V_2 * V_20 , struct V_2 * V_21 )
{
unsigned int V_6 , V_1 , V_4 = F_11 () ;
unsigned long * V_22 ;
F_9 ( & V_14 ) ;
F_19 ( L_8 ,
V_4 , V_21 , V_21 -> V_10 . V_11 , V_21 -> V_10 . V_1 ) ;
#ifdef F_20
V_21 -> V_10 . V_11 ++ ;
if ( V_20 ) {
F_2 ( L_9 , V_20 , V_20 -> V_10 . V_11 ) ;
F_21 ( V_20 -> V_10 . V_11 < 1 ) ;
V_20 -> V_10 . V_11 -- ;
}
V_23:
#endif
V_1 = V_21 -> V_10 . V_1 ;
if ( F_22 ( V_1 != V_12 ) ) {
#ifdef F_23
if ( V_9 [ V_1 ] != V_21 )
F_16 ( L_10 ,
V_21 , V_1 , V_1 , V_9 [ V_1 ] ) ;
#endif
goto V_24;
}
V_1 = V_25 ;
if ( V_1 > V_7 )
V_1 = V_8 ;
V_22 = V_18 ;
if ( V_19 == 0 ) {
#ifdef F_20
if ( F_17 () > 1 ) {
V_1 = F_1 ( V_1 ) ;
if ( V_1 == V_12 )
goto V_23;
goto V_26;
}
#endif
V_1 = F_10 ( V_1 ) ;
goto V_26;
}
V_19 -- ;
while ( F_24 ( V_1 , V_22 ) ) {
V_1 = F_25 ( V_22 , V_7 + 1 , V_1 ) ;
if ( V_1 > V_7 )
V_1 = V_8 ;
}
V_26:
V_25 = V_1 + 1 ;
V_9 [ V_1 ] = V_21 ;
V_21 -> V_10 . V_1 = V_1 ;
F_2 ( L_11 , V_1 , V_19 ) ;
F_14 () ;
V_24:
if ( F_15 ( V_1 , V_13 [ V_4 ] ) ) {
F_2 ( L_12 ,
V_1 , F_4 ( V_4 ) ,
F_5 ( V_4 ) ) ;
F_12 ( V_21 ) ;
for ( V_6 = F_4 ( V_4 ) ;
V_6 <= F_5 ( V_4 ) ; V_6 ++ ) {
F_13 ( V_1 , V_13 [ V_6 ] ) ;
}
}
F_2 ( L_13 , V_1 ) ;
F_26 ( V_1 , V_21 -> V_27 ) ;
F_7 ( & V_14 ) ;
}
int F_27 ( struct V_28 * V_29 , struct V_2 * V_3 )
{
F_19 ( L_14 , V_3 ) ;
V_3 -> V_10 . V_1 = V_12 ;
V_3 -> V_10 . V_11 = 0 ;
return 0 ;
}
void F_28 ( struct V_2 * V_3 )
{
unsigned long V_30 ;
unsigned int V_1 ;
if ( V_3 -> V_10 . V_1 == V_12 )
return;
F_21 ( V_3 -> V_10 . V_11 != 0 ) ;
F_29 ( & V_14 , V_30 ) ;
V_1 = V_3 -> V_10 . V_1 ;
if ( V_1 != V_12 ) {
F_13 ( V_1 , V_18 ) ;
V_3 -> V_10 . V_1 = V_12 ;
#ifdef F_23
V_3 -> V_10 . V_11 = 0 ;
#endif
V_9 [ V_1 ] = NULL ;
V_19 ++ ;
}
F_30 ( & V_14 , V_30 ) ;
}
static int T_1 F_31 ( struct V_31 * V_32 ,
unsigned long V_33 , void * V_34 )
{
unsigned int V_4 = ( unsigned int ) ( long ) V_34 ;
#ifdef F_32
struct V_28 * V_35 ;
#endif
if ( V_4 == V_36 )
return V_37 ;
switch ( V_33 ) {
case V_38 :
case V_39 :
F_33 ( L_15 , V_4 ) ;
V_13 [ V_4 ] = F_34 ( V_40 , V_41 ) ;
break;
#ifdef F_32
case V_42 :
case V_43 :
case V_44 :
case V_45 :
F_33 ( L_16 , V_4 ) ;
F_35 ( V_13 [ V_4 ] ) ;
V_13 [ V_4 ] = NULL ;
F_36 ( & V_46 ) ;
F_37 (p) {
if ( V_35 -> V_3 )
F_38 ( V_4 , F_39 ( V_35 -> V_3 ) ) ;
}
F_40 ( & V_46 ) ;
break;
#endif
}
return V_37 ;
}
void T_2 F_41 ( void )
{
V_47 . V_10 . V_11 = V_48 ;
if ( F_42 ( V_49 ) ) {
V_8 = 0 ;
V_7 = 15 ;
} else if ( F_42 ( V_50 ) ) {
V_8 = 1 ;
V_7 = 65535 ;
} else
#ifdef F_43
if ( F_42 ( V_51 ) ) {
T_3 V_52 = F_44 ( V_53 ) ;
T_3 V_54 = ( V_52 & V_55 )
>> V_56 ;
V_8 = 1 ;
V_7 = ( 1UL << ( V_54 + 1 ) ) - 1 ;
} else
#endif
{
V_8 = 1 ;
V_7 = 255 ;
}
#ifdef F_45
V_7 = F_45 ;
#endif
V_18 = F_46 ( V_40 ) ;
V_9 = F_46 ( sizeof( void * ) * ( V_7 + 1 ) ) ;
#ifndef F_20
V_13 [ 0 ] = F_46 ( V_40 ) ;
#else
V_13 [ V_36 ] = F_46 ( V_40 ) ;
F_47 ( & V_57 ) ;
#endif
F_48 ( V_58
L_17 ,
2 * V_40 + ( sizeof( void * ) * ( V_7 + 1 ) ) ,
V_7 - V_8 + 1 ) ;
V_18 [ 0 ] = ( 1 << V_8 ) - 1 ;
V_25 = V_8 ;
V_19 = V_7 - V_8 + 1 ;
}
