void F_1 ( void )
{
if ( V_1 )
(* V_1)() ;
F_2 () ;
}
void F_3 ( void )
{
F_2 () ;
F_4 ( 8 ) ;
F_5 () ;
F_6 () ;
F_7 ( L_1 ) ;
}
void F_8 ( char * V_2 )
{
char * V_3 ;
F_2 () ;
F_4 ( 8 ) ;
F_5 () ;
V_3 = strchr ( V_4 , '\n' ) ;
if ( V_3 ) * V_3 = 0 ;
if ( V_2 )
F_9 ( V_2 ) ;
if ( * V_4 )
F_9 ( V_4 ) ;
F_10 ( L_2 ) ;
F_7 ( L_3 ) ;
}
void F_11 ( void )
{
if ( V_5 &&
( strcmp ( V_6 -> type , L_4 ) || V_7 ) ) {
T_1 V_8 = F_12 ( V_5 ) ;
V_8 |= V_9 ;
F_13 ( V_8 , V_5 ) ;
}
F_3 () ;
}
void F_14 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = (struct V_12 * ) V_11 -> V_14 [ 14 ] ;
F_15 ( V_15 ) ;
F_16 ( L_5 ,
V_11 -> V_16 , V_11 -> V_17 , V_11 -> V_18 , V_11 -> V_19 , F_17 () ) ;
F_16 ( L_6 , ( void * ) V_11 -> V_17 ) ;
F_16 ( L_7 ,
V_11 -> V_14 [ 0 ] , V_11 -> V_14 [ 1 ] , V_11 -> V_14 [ 2 ] , V_11 -> V_14 [ 3 ] ,
V_11 -> V_14 [ 4 ] , V_11 -> V_14 [ 5 ] , V_11 -> V_14 [ 6 ] , V_11 -> V_14 [ 7 ] ) ;
F_16 ( L_8 ,
V_11 -> V_14 [ 8 ] , V_11 -> V_14 [ 9 ] , V_11 -> V_14 [ 10 ] , V_11 -> V_14 [ 11 ] ,
V_11 -> V_14 [ 12 ] , V_11 -> V_14 [ 13 ] , V_11 -> V_14 [ 14 ] , V_11 -> V_14 [ 15 ] ) ;
F_16 ( L_9 , ( void * ) V_11 -> V_14 [ 15 ] ) ;
F_16 ( L_10 ,
V_13 -> V_20 [ 0 ] , V_13 -> V_20 [ 1 ] , V_13 -> V_20 [ 2 ] , V_13 -> V_20 [ 3 ] ,
V_13 -> V_20 [ 4 ] , V_13 -> V_20 [ 5 ] , V_13 -> V_20 [ 6 ] , V_13 -> V_20 [ 7 ] ) ;
F_16 ( L_11 ,
V_13 -> V_21 [ 0 ] , V_13 -> V_21 [ 1 ] , V_13 -> V_21 [ 2 ] , V_13 -> V_21 [ 3 ] ,
V_13 -> V_21 [ 4 ] , V_13 -> V_21 [ 5 ] , V_13 -> V_21 [ 6 ] , V_13 -> V_21 [ 7 ] ) ;
}
void F_18 ( struct V_22 * V_23 , unsigned long * V_24 )
{
unsigned long V_17 , V_25 ;
unsigned long V_26 ;
struct V_12 * V_13 ;
int V_27 = 0 ;
if ( ! V_23 )
V_23 = V_28 ;
if ( V_23 == V_28 && ! V_24 )
__asm__ __volatile__("mov %%fp, %0" : "=r" (_ksp));
V_26 = ( unsigned long ) F_19 ( V_23 ) ;
V_25 = ( unsigned long ) V_24 ;
do {
if ( V_25 < ( V_26 + sizeof( struct V_29 ) ) ||
V_25 >= ( V_26 + ( V_30 << 1 ) ) )
break;
V_13 = (struct V_12 * ) V_25 ;
V_17 = V_13 -> V_21 [ 7 ] ;
F_16 ( L_12 , V_17 ) ;
F_16 ( L_13 , ( void * ) V_17 ) ;
V_25 = V_13 -> V_21 [ 6 ] ;
} while ( ++ V_27 < 16 );
F_16 ( L_14 ) ;
}
unsigned long F_20 ( struct V_22 * V_23 )
{
return F_21 ( V_23 ) -> V_31 ;
}
static inline struct V_32 T_2 *
F_22 ( struct V_32 T_2 * V_33 ,
struct V_32 T_2 * V_34 )
{
unsigned long V_35 , V_25 ;
struct V_32 * V_36 ;
struct V_32 T_2 * V_37 ;
if ( F_23 ( V_36 , & V_34 -> V_25 ) )
return NULL ;
V_25 = ( unsigned long ) V_36 ;
V_35 = ( V_25 - ( ( unsigned long ) V_34 ) ) ;
V_25 = ( unsigned long ) V_33 ;
V_37 = (struct V_32 T_2 * ) ( V_25 - V_35 ) ;
if ( F_24 ( V_37 , V_34 , V_35 ) )
V_37 = NULL ;
else if ( F_25 ( V_25 , & V_37 -> V_25 ) )
V_37 = NULL ;
return V_37 ;
}
T_3 int F_26 ( unsigned long V_38 ,
unsigned long V_39 ,
struct V_10 * V_40 ,
unsigned long V_41 )
{
unsigned long V_42 , V_43 ;
unsigned long V_44 = V_40 -> V_14 [ V_45 ] ;
long V_46 ;
V_42 = V_40 -> V_14 [ V_47 ] ;
V_43 = V_40 -> V_14 [ V_48 ] ;
V_46 = F_27 ( V_38 , V_39 , V_41 ,
( int T_2 * ) V_42 ,
( int T_2 * ) V_43 ) ;
if ( ( unsigned long ) V_46 >= - V_49 )
V_40 -> V_14 [ V_45 ] = V_44 ;
return V_46 ;
}
int F_28 ( struct V_10 * V_40 , T_4 * V_50 )
{
if ( F_29 () ) {
memset ( V_50 , 0 , sizeof( * V_50 ) ) ;
V_50 -> V_51 = 8 ;
return 1 ;
}
#ifdef F_30
if ( F_31 ( V_52 ) ) {
F_32 ( F_33 () | V_53 ) ;
F_34 ( & V_28 -> V_54 . V_55 [ 0 ] , & V_28 -> V_54 . V_56 ,
& V_28 -> V_54 . V_57 [ 0 ] , & V_28 -> V_54 . V_58 ) ;
if ( V_40 != NULL ) {
V_40 -> V_16 &= ~ ( V_53 ) ;
F_35 ( V_52 ) ;
}
}
#else
if ( V_28 == V_59 ) {
F_32 ( F_33 () | V_53 ) ;
F_34 ( & V_28 -> V_54 . V_55 [ 0 ] , & V_28 -> V_54 . V_56 ,
& V_28 -> V_54 . V_57 [ 0 ] , & V_28 -> V_54 . V_58 ) ;
if ( V_40 != NULL ) {
V_40 -> V_16 &= ~ ( V_53 ) ;
V_59 = NULL ;
}
}
#endif
memcpy ( & V_50 -> V_60 . V_61 [ 0 ] ,
& V_28 -> V_54 . V_55 [ 0 ] ,
(sizeof( unsigned long ) * 32 ) ) ;
V_50 -> V_62 = V_28 -> V_54 . V_56 ;
V_50 -> V_63 = V_28 -> V_54 . V_58 ;
V_50 -> V_51 = 8 ;
V_50 -> V_64 = 1 ;
if( V_50 -> V_63 != 0 ) {
memcpy ( & V_50 -> V_65 [ 0 ] ,
& V_28 -> V_54 . V_57 [ 0 ] ,
sizeof( struct V_66 ) * V_50 -> V_63 ) ;
}
memset ( & V_50 -> V_65 [ V_50 -> V_63 ] , 0 ,
sizeof( struct V_66 ) * ( 32 - V_50 -> V_63 ) ) ;
return 1 ;
}
unsigned long F_36 ( struct V_22 * V_67 )
{
unsigned long V_17 , V_25 , V_68 = 0 ;
unsigned long V_26 = ( unsigned long ) V_67 ;
unsigned long V_46 = 0 ;
struct V_12 * V_13 ;
int V_27 = 0 ;
if ( ! V_67 || V_67 == V_28 ||
V_67 -> V_69 == V_70 )
goto V_71;
V_25 = F_21 ( V_67 ) -> V_72 + V_68 ;
do {
if ( V_25 < ( V_26 + sizeof( struct V_29 ) ) ||
V_25 >= ( V_26 + ( 2 * V_30 ) ) )
break;
V_13 = (struct V_12 * ) V_25 ;
V_17 = V_13 -> V_21 [ 7 ] ;
if ( ! F_37 ( V_17 ) ) {
V_46 = V_17 ;
goto V_71;
}
V_25 = V_13 -> V_21 [ 6 ] + V_68 ;
} while ( ++ V_27 < 16 );
V_71:
return V_46 ;
}
