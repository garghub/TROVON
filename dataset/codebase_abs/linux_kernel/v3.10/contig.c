void F_1 ( unsigned int V_1 )
{
int V_2 , V_3 = 0 ;
int V_4 = 0 , V_5 = 0 ;
unsigned long V_6 = 0 ;
T_1 * V_7 ;
F_2 ( V_8 L_1 ) ;
F_3 ( V_1 ) ;
F_2 ( V_8 L_2 ) ;
if ( V_1 & V_9 )
return;
F_4 (pgdat) {
unsigned long V_10 ;
unsigned long V_11 ;
int V_12 = 0 , V_13 = 0 , V_14 = 0 ;
int V_15 = V_7 -> V_16 ;
if ( F_5 ( V_1 , V_15 ) )
continue;
F_6 ( V_7 , & V_11 ) ;
V_10 = V_7 -> V_17 ;
for( V_2 = 0 ; V_2 < V_7 -> V_18 ; V_2 ++ ) {
struct V_19 * V_19 ;
if ( F_7 ( V_2 % V_20 == 0 ) )
F_8 () ;
if ( F_9 ( V_7 -> V_21 + V_2 ) )
V_19 = F_10 ( V_7 -> V_21 + V_2 ) ;
else {
#ifdef F_11
if ( V_22 < V_23 )
continue;
#endif
V_2 = F_12 ( V_15 , V_2 ) - 1 ;
continue;
}
if ( F_13 ( V_19 ) )
V_14 ++ ;
else if ( F_14 ( V_19 ) )
V_13 ++ ;
else if ( F_15 ( V_19 ) )
V_12 += F_15 ( V_19 ) - 1 ;
}
F_16 ( V_7 , & V_11 ) ;
V_6 += V_10 ;
V_3 += V_14 ;
V_5 += V_13 ;
V_4 += V_12 ;
F_2 ( V_8 L_3
L_4 , V_15 ,
V_10 , V_14 , V_12 , V_13 ) ;
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
F_19 ( T_3 V_24 , T_3 V_25 , void * V_26 )
{
T_3 V_27 = * ( unsigned long * ) V_26 ;
T_3 V_28 , V_29 , V_30 ;
int V_2 ;
#if V_31
if ( V_24 == V_32 ) {
V_24 += V_33 ;
if ( V_24 >= V_25 )
return 0 ;
}
#endif
V_30 = V_32 ;
for ( V_2 = 0 ; V_2 < V_34 ; V_2 ++ ) {
V_28 = F_20 ( V_24 , V_30 ) ;
V_29 = F_21 ( V_25 , V_35 [ V_2 ] . V_24 & V_36 ) ;
V_30 = F_22 ( V_35 [ V_2 ] . V_25 ) ;
if ( V_29 <= V_28 )
continue;
if ( V_29 - V_28 >= V_27 ) {
V_37 = F_23 ( V_28 ) ;
return - 1 ;
}
if ( V_29 == V_25 )
return 0 ;
}
return 0 ;
}
void * T_4
F_24 ( void )
{
static bool V_38 = true ;
void * V_39 = V_40 ;
unsigned int V_41 ;
if ( ! V_38 )
goto V_42;
V_38 = false ;
F_25 (cpu) {
void * V_43 = V_41 == 0 ? V_39 : V_44 ;
memcpy ( V_45 , V_43 , V_46 - V_47 ) ;
V_48 [ V_41 ] = ( char * ) V_45 - V_47 ;
F_26 ( V_49 , V_41 ) = V_48 [ V_41 ] ;
if ( V_41 == 0 )
F_27 ( V_50 , F_23 ( V_45 ) -
( unsigned long ) V_47 ) ;
V_45 += V_51 ;
}
V_42:
return V_47 + V_48 [ F_28 () ] ;
}
static inline void
F_29 ( void )
{
V_45 = F_30 ( V_51 * F_31 () ,
V_51 , F_23 ( V_52 ) ) ;
}
void T_2
F_32 ( void )
{
struct V_53 * V_54 ;
struct V_55 * V_56 ;
unsigned int V_41 ;
T_5 V_57 , V_58 , V_59 ;
int V_60 ;
V_54 = F_33 ( 1 , F_31 () ) ;
if ( ! V_54 )
F_34 ( L_11 ) ;
V_56 = & V_54 -> V_61 [ 0 ] ;
F_25 (cpu)
V_56 -> V_62 [ V_56 -> V_63 ++ ] = V_41 ;
V_57 = V_46 - V_47 ;
V_58 = V_64 ;
V_59 = V_51 - V_57 - V_58 ;
if ( V_59 < 0 )
F_34 ( L_12 ,
V_57 , V_58 ) ;
V_54 -> V_57 = V_57 ;
V_54 -> V_58 = V_58 ;
V_54 -> V_59 = V_59 ;
V_54 -> V_65 = V_51 ;
V_54 -> V_66 = V_33 ;
V_54 -> V_67 = V_51 ;
V_60 = F_35 ( V_54 , V_47 + V_48 [ 0 ] ) ;
if ( V_60 )
F_34 ( L_13 , V_60 ) ;
F_36 ( V_54 ) ;
}
void T_2
F_37 ( void )
{
unsigned long V_68 ;
F_38 () ;
V_69 = ~ 0UL ;
V_70 = 0 ;
F_39 ( V_71 , NULL ) ;
V_72 = V_70 ;
V_68 = F_40 ( V_72 ) << V_73 ;
V_37 = ~ 0UL ;
F_39 ( F_19 , & V_68 ) ;
if ( V_37 == ~ 0UL )
F_34 ( L_14 , V_68 ) ;
V_68 = F_41 ( F_42 ( 0 ) ,
( V_37 >> V_73 ) , 0 , V_72 ) ;
F_39 ( V_74 , V_75 ) ;
F_43 ( V_37 , V_68 , V_76 ) ;
F_44 () ;
F_29 () ;
}
static int F_45 ( T_3 V_24 , T_3 V_25 , void * V_26 )
{
unsigned long * V_77 = V_26 ;
* V_77 += ( V_25 - V_24 ) >> V_73 ;
return 0 ;
}
void T_2
F_46 ( void )
{
unsigned long V_78 ;
unsigned long V_79 [ V_80 ] ;
V_81 = 0 ;
F_39 ( F_45 , & V_81 ) ;
memset ( V_79 , 0 , sizeof( V_79 ) ) ;
#ifdef F_47
V_78 = F_48 ( ( void * ) V_52 ) >> V_73 ;
V_79 [ V_82 ] = V_78 ;
#endif
V_79 [ V_83 ] = V_70 ;
#ifdef F_11
F_39 ( V_84 , V_85 ) ;
F_39 ( V_86 , ( T_3 * ) & V_22 ) ;
if ( V_22 < V_23 ) {
V_87 = (struct V_19 * ) 0 ;
F_49 ( V_79 ) ;
} else {
unsigned long V_88 ;
V_88 = F_22 ( F_50 ( V_70 , V_20 ) *
sizeof( struct V_19 ) ) ;
V_89 -= V_88 ;
V_87 = (struct V_19 * ) V_89 ;
F_39 ( V_90 , NULL ) ;
F_42 ( 0 ) -> V_91 = V_87 +
F_51 () ;
F_49 ( V_79 ) ;
F_2 ( L_15 , V_92 ) ;
}
#else
F_52 ( 0 , F_53 ( V_70 ) , 0 ) ;
F_49 ( V_79 ) ;
#endif
V_93 = F_54 ( F_55 ( V_94 ) ) ;
}
