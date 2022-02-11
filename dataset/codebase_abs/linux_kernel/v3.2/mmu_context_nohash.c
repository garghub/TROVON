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
#ifdef F_28
if ( F_29 ( V_3 ) )
F_30 ( V_3 , V_30 ) ;
#endif
return 0 ;
}
void F_31 ( struct V_2 * V_3 )
{
unsigned long V_31 ;
unsigned int V_1 ;
if ( V_3 -> V_10 . V_1 == V_12 )
return;
F_21 ( V_3 -> V_10 . V_11 != 0 ) ;
F_32 ( & V_14 , V_31 ) ;
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
F_33 ( & V_14 , V_31 ) ;
}
static int T_1 F_34 ( struct V_32 * V_33 ,
unsigned long V_34 , void * V_35 )
{
unsigned int V_4 = ( unsigned int ) ( long ) V_35 ;
#ifdef F_35
struct V_28 * V_36 ;
#endif
if ( V_4 == V_37 )
return V_38 ;
switch ( V_34 ) {
case V_39 :
case V_40 :
F_36 ( L_15 , V_4 ) ;
V_13 [ V_4 ] = F_37 ( V_41 , V_42 ) ;
break;
#ifdef F_35
case V_43 :
case V_44 :
case V_45 :
case V_46 :
F_36 ( L_16 , V_4 ) ;
F_38 ( V_13 [ V_4 ] ) ;
V_13 [ V_4 ] = NULL ;
F_39 ( & V_47 ) ;
F_40 (p) {
if ( V_36 -> V_3 )
F_41 ( V_4 , F_42 ( V_36 -> V_3 ) ) ;
}
F_43 ( & V_47 ) ;
break;
#endif
}
return V_38 ;
}
void T_2 F_44 ( void )
{
V_48 . V_10 . V_11 = V_49 ;
if ( F_45 ( V_50 ) ) {
V_8 = 0 ;
V_7 = 15 ;
} else if ( F_45 ( V_51 ) ) {
V_8 = 1 ;
V_7 = 65535 ;
} else
#ifdef F_46
if ( F_45 ( V_52 ) ) {
T_3 V_53 = F_47 ( V_54 ) ;
T_3 V_55 = ( V_53 & V_56 )
>> V_57 ;
V_8 = 1 ;
V_7 = ( 1UL << ( V_55 + 1 ) ) - 1 ;
} else
#endif
{
V_8 = 1 ;
V_7 = 255 ;
}
#ifdef F_48
V_7 = F_48 ;
#endif
V_18 = F_49 ( V_41 ) ;
V_9 = F_49 ( sizeof( void * ) * ( V_7 + 1 ) ) ;
#ifndef F_20
V_13 [ 0 ] = F_49 ( V_41 ) ;
#else
V_13 [ V_37 ] = F_49 ( V_41 ) ;
F_50 ( & V_58 ) ;
#endif
F_51 ( V_59
L_17 ,
2 * V_41 + ( sizeof( void * ) * ( V_7 + 1 ) ) ,
V_7 - V_8 + 1 ) ;
V_18 [ 0 ] = ( 1 << V_8 ) - 1 ;
V_25 = V_8 ;
V_19 = V_7 - V_8 + 1 ;
}
