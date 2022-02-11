static int T_1
F_1 ( T_2 V_1 , T_2 V_2 , void * V_3 )
{
T_2 V_4 = * ( unsigned long * ) V_3 ;
T_2 V_5 , V_6 , V_7 ;
int V_8 ;
#if V_9
if ( V_1 == V_10 ) {
V_1 += V_11 ;
if ( V_1 >= V_2 )
return 0 ;
}
#endif
V_7 = V_10 ;
for ( V_8 = 0 ; V_8 < V_12 ; V_8 ++ ) {
V_5 = F_2 ( V_1 , V_7 ) ;
V_6 = F_3 ( V_2 , V_13 [ V_8 ] . V_1 & V_14 ) ;
V_7 = F_4 ( V_13 [ V_8 ] . V_2 ) ;
if ( V_6 <= V_5 )
continue;
if ( V_6 - V_5 >= V_4 ) {
V_15 = F_5 ( V_5 ) ;
return - 1 ;
}
if ( V_6 == V_2 )
return 0 ;
}
return 0 ;
}
void * F_6 ( void )
{
static bool V_16 = true ;
void * V_17 = V_18 ;
unsigned int V_19 ;
if ( ! V_16 )
goto V_20;
V_16 = false ;
F_7 (cpu) {
void * V_21 = V_19 == 0 ? V_17 : V_22 ;
memcpy ( V_23 , V_21 , V_24 - V_25 ) ;
V_26 [ V_19 ] = ( char * ) V_23 - V_25 ;
F_8 ( V_27 , V_19 ) = V_26 [ V_19 ] ;
if ( V_19 == 0 )
F_9 ( V_28 , F_5 ( V_23 ) -
( unsigned long ) V_25 ) ;
V_23 += V_29 ;
}
V_20:
return V_25 + V_26 [ F_10 () ] ;
}
static inline void
F_11 ( void )
{
V_23 = F_12 ( V_29 * F_13 () ,
V_29 , F_5 ( V_30 ) ) ;
}
void T_1
F_14 ( void )
{
struct V_31 * V_32 ;
struct V_33 * V_34 ;
unsigned int V_19 ;
T_3 V_35 , V_36 , V_37 ;
int V_38 ;
V_32 = F_15 ( 1 , F_13 () ) ;
if ( ! V_32 )
F_16 ( L_1 ) ;
V_34 = & V_32 -> V_39 [ 0 ] ;
F_7 (cpu)
V_34 -> V_40 [ V_34 -> V_41 ++ ] = V_19 ;
V_35 = V_24 - V_25 ;
V_36 = V_42 ;
V_37 = V_29 - V_35 - V_36 ;
if ( V_37 < 0 )
F_16 ( L_2 ,
V_35 , V_36 ) ;
V_32 -> V_35 = V_35 ;
V_32 -> V_36 = V_36 ;
V_32 -> V_37 = V_37 ;
V_32 -> V_43 = V_29 ;
V_32 -> V_44 = V_11 ;
V_32 -> V_45 = V_29 ;
V_38 = F_17 ( V_32 , V_25 + V_26 [ 0 ] ) ;
if ( V_38 )
F_16 ( L_3 , V_38 ) ;
F_18 ( V_32 ) ;
}
void T_1
F_19 ( void )
{
unsigned long V_46 ;
F_20 () ;
V_47 = ~ 0UL ;
V_48 = 0 ;
F_21 ( V_49 , NULL ) ;
V_50 = V_48 ;
V_46 = F_22 ( V_50 ) << V_51 ;
V_15 = ~ 0UL ;
F_21 ( F_1 , & V_46 ) ;
if ( V_15 == ~ 0UL )
F_16 ( L_4 , V_46 ) ;
V_46 = F_23 ( F_24 ( 0 ) ,
( V_15 >> V_51 ) , 0 , V_50 ) ;
F_21 ( V_52 , V_53 ) ;
F_25 ( V_15 , V_46 , V_54 ) ;
F_26 () ;
F_11 () ;
}
void T_1
F_27 ( void )
{
unsigned long V_55 ;
unsigned long V_56 [ V_57 ] ;
memset ( V_56 , 0 , sizeof( V_56 ) ) ;
#ifdef F_28
V_55 = F_29 ( ( void * ) V_30 ) >> V_51 ;
V_56 [ V_58 ] = V_55 ;
#endif
V_56 [ V_59 ] = V_48 ;
#ifdef F_30
F_21 ( V_60 , V_61 ) ;
F_21 ( V_62 , ( T_2 * ) & V_63 ) ;
if ( V_63 < V_64 ) {
V_65 = (struct V_66 * ) 0 ;
F_31 ( V_56 ) ;
} else {
unsigned long V_67 ;
V_67 = F_4 ( F_32 ( V_48 , V_68 ) *
sizeof( struct V_66 ) ) ;
V_69 -= V_67 ;
V_65 = (struct V_66 * ) V_69 ;
F_21 ( V_70 , NULL ) ;
F_24 ( 0 ) -> V_71 = V_65 +
F_33 () ;
F_31 ( V_56 ) ;
F_34 ( L_5 , V_72 ) ;
}
#else
F_35 ( 0 , F_36 ( V_48 ) , 0 ) ;
F_31 ( V_56 ) ;
#endif
V_73 = F_37 ( F_38 ( V_74 ) ) ;
}
