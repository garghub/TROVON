void F_1 ( unsigned int V_1 )
{
int V_2 , V_3 = 0 ;
int V_4 = 0 , V_5 = 0 ;
unsigned long V_6 = 0 ;
T_1 * V_7 ;
F_2 ( V_8 L_1 ) ;
F_3 ( V_1 ) ;
F_2 ( V_8 L_2 ) ;
F_4 (pgdat) {
unsigned long V_9 ;
unsigned long V_10 ;
int V_11 = 0 , V_12 = 0 , V_13 = 0 ;
int V_14 = V_7 -> V_15 ;
if ( F_5 ( V_1 , V_14 ) )
continue;
F_6 ( V_7 , & V_10 ) ;
V_9 = V_7 -> V_16 ;
for( V_2 = 0 ; V_2 < V_7 -> V_17 ; V_2 ++ ) {
struct V_18 * V_18 ;
if ( F_7 ( V_2 % V_19 == 0 ) )
F_8 () ;
if ( F_9 ( V_7 -> V_20 + V_2 ) )
V_18 = F_10 ( V_7 -> V_20 + V_2 ) ;
else {
#ifdef F_11
if ( V_21 < V_22 )
continue;
#endif
V_2 = F_12 ( V_14 , V_2 ) - 1 ;
continue;
}
if ( F_13 ( V_18 ) )
V_13 ++ ;
else if ( F_14 ( V_18 ) )
V_12 ++ ;
else if ( F_15 ( V_18 ) )
V_11 += F_15 ( V_18 ) - 1 ;
}
F_16 ( V_7 , & V_10 ) ;
V_6 += V_9 ;
V_3 += V_13 ;
V_5 += V_12 ;
V_4 += V_11 ;
F_2 ( V_8 L_3
L_4 , V_14 ,
V_9 , V_13 , V_11 , V_12 ) ;
}
F_2 ( V_8 L_5 , V_6 ) ;
F_2 ( V_8 L_6 , V_3 ) ;
F_2 ( V_8 L_7 , V_4 ) ;
F_2 ( V_8 L_8 , V_5 ) ;
F_2 ( V_8 L_9 ,
F_17 () ) ;
F_2 ( V_8 L_10 , F_18 () ) ;
}
static int T_2
F_19 ( T_3 V_23 , T_3 V_24 , void * V_25 )
{
T_3 V_26 = * ( unsigned long * ) V_25 ;
T_3 V_27 , V_28 , V_29 ;
int V_2 ;
#if V_30
if ( V_23 == V_31 ) {
V_23 += V_32 ;
if ( V_23 >= V_24 )
return 0 ;
}
#endif
V_29 = V_31 ;
for ( V_2 = 0 ; V_2 < V_33 ; V_2 ++ ) {
V_27 = F_20 ( V_23 , V_29 ) ;
V_28 = F_21 ( V_24 , V_34 [ V_2 ] . V_23 & V_35 ) ;
V_29 = F_22 ( V_34 [ V_2 ] . V_24 ) ;
if ( V_28 <= V_27 )
continue;
if ( V_28 - V_27 >= V_26 ) {
V_36 = F_23 ( V_27 ) ;
return - 1 ;
}
if ( V_28 == V_24 )
return 0 ;
}
return 0 ;
}
void * T_4
F_24 ( void )
{
static bool V_37 = true ;
void * V_38 = V_39 ;
unsigned int V_40 ;
if ( ! V_37 )
goto V_41;
V_37 = false ;
F_25 (cpu) {
void * V_42 = V_40 == 0 ? V_38 : V_43 ;
memcpy ( V_44 , V_42 , V_45 - V_46 ) ;
V_47 [ V_40 ] = ( char * ) V_44 - V_46 ;
F_26 ( V_48 , V_40 ) = V_47 [ V_40 ] ;
if ( V_40 == 0 )
F_27 ( V_49 , F_23 ( V_44 ) -
( unsigned long ) V_46 ) ;
V_44 += V_50 ;
}
V_41:
return V_46 + V_47 [ F_28 () ] ;
}
static inline void
F_29 ( void )
{
V_44 = F_30 ( V_50 * F_31 () ,
V_50 , F_23 ( V_51 ) ) ;
}
void T_2
F_32 ( void )
{
struct V_52 * V_53 ;
struct V_54 * V_55 ;
unsigned int V_40 ;
T_5 V_56 , V_57 , V_58 ;
int V_59 ;
V_53 = F_33 ( 1 , F_31 () ) ;
if ( ! V_53 )
F_34 ( L_11 ) ;
V_55 = & V_53 -> V_60 [ 0 ] ;
F_25 (cpu)
V_55 -> V_61 [ V_55 -> V_62 ++ ] = V_40 ;
V_56 = V_45 - V_46 ;
V_57 = V_63 ;
V_58 = V_50 - V_56 - V_57 ;
if ( V_58 < 0 )
F_34 ( L_12 ,
V_56 , V_57 ) ;
V_53 -> V_56 = V_56 ;
V_53 -> V_57 = V_57 ;
V_53 -> V_58 = V_58 ;
V_53 -> V_64 = V_50 ;
V_53 -> V_65 = V_32 ;
V_53 -> V_66 = V_50 ;
V_59 = F_35 ( V_53 , V_46 + V_47 [ 0 ] ) ;
if ( V_59 )
F_34 ( L_13 , V_59 ) ;
F_36 ( V_53 ) ;
}
void T_2
F_37 ( void )
{
unsigned long V_67 ;
F_38 () ;
V_68 = ~ 0UL ;
V_69 = 0 ;
F_39 ( V_70 , NULL ) ;
V_71 = V_69 ;
V_67 = F_40 ( V_71 ) << V_72 ;
V_36 = ~ 0UL ;
F_39 ( F_19 , & V_67 ) ;
if ( V_36 == ~ 0UL )
F_34 ( L_14 , V_67 ) ;
V_67 = F_41 ( F_42 ( 0 ) ,
( V_36 >> V_72 ) , 0 , V_71 ) ;
F_39 ( V_73 , V_74 ) ;
F_43 ( V_36 , V_67 , V_75 ) ;
F_44 () ;
F_29 () ;
}
static int F_45 ( T_3 V_23 , T_3 V_24 , void * V_25 )
{
unsigned long * V_76 = V_25 ;
* V_76 += ( V_24 - V_23 ) >> V_72 ;
return 0 ;
}
void T_2
F_46 ( void )
{
unsigned long V_77 ;
unsigned long V_78 [ V_79 ] ;
V_80 = 0 ;
F_39 ( F_45 , & V_80 ) ;
memset ( V_78 , 0 , sizeof( V_78 ) ) ;
#ifdef F_47
V_77 = F_48 ( ( void * ) V_51 ) >> V_72 ;
V_78 [ V_81 ] = V_77 ;
#endif
V_78 [ V_82 ] = V_69 ;
#ifdef F_11
F_39 ( V_83 , V_84 ) ;
F_39 ( V_85 , ( T_3 * ) & V_21 ) ;
if ( V_21 < V_22 ) {
V_86 = (struct V_18 * ) 0 ;
F_49 ( V_78 ) ;
} else {
unsigned long V_87 ;
V_87 = F_22 ( F_50 ( V_69 , V_19 ) *
sizeof( struct V_18 ) ) ;
V_88 -= V_87 ;
V_86 = (struct V_18 * ) V_88 ;
F_39 ( V_89 , NULL ) ;
F_42 ( 0 ) -> V_90 = V_86 +
F_51 () ;
F_49 ( V_78 ) ;
F_2 ( L_15 , V_91 ) ;
}
#else
F_52 ( 0 , 0 , V_69 ) ;
F_49 ( V_78 ) ;
#endif
V_92 = F_53 ( F_54 ( V_93 ) ) ;
}
