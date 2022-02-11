void F_1 ( void )
{
}
void T_1 F_2 ( void )
{
T_2 * V_1 ;
T_3 * V_2 ;
unsigned long V_3 , V_4 ;
unsigned long V_5 , V_6 ;
unsigned long V_7 [ V_8 ] ;
enum V_9 V_10 ;
int V_11 ;
V_12 = ( void * ) F_3 ( V_13 ) ;
memset ( ( void * ) V_12 , 0 , V_13 ) ;
V_1 = V_14 ;
memset ( V_14 , 0 , sizeof( V_14 ) ) ;
V_4 = V_15 * sizeof( T_3 ) ;
V_4 = ( V_4 + V_13 ) & ~ ( V_13 - 1 ) ;
V_5 = ( unsigned long ) F_3 ( V_4 ) ;
V_6 = ( V_5 + V_4 + V_13 ) & V_16 ;
V_1 += V_17 >> V_18 ;
V_3 = V_17 ;
while ( V_3 < ( unsigned long ) V_19 ) {
V_2 = ( T_3 * ) V_5 ;
V_5 += V_20 * sizeof( T_3 ) ;
F_4 ( * V_1 ) = ( unsigned long ) V_2 ;
V_1 ++ ;
for ( V_11 = 0 ; V_11 < V_20 ; ++ V_11 , ++ V_2 ) {
T_3 V_21 = F_5 ( F_6 ( V_3 ) , V_22 ) ;
if ( V_3 >= ( unsigned long ) V_19 )
F_7 ( V_21 ) = 0 ;
F_8 ( V_2 , V_21 ) ;
V_3 += V_13 ;
}
}
V_23 -> V_24 = NULL ;
for ( V_10 = 0 ; V_10 < V_8 ; V_10 ++ )
V_7 [ V_10 ] = 0x0 ;
V_7 [ V_25 ] = V_15 ;
F_9 ( V_7 ) ;
}
int F_10 ( struct V_26 * V_27 , int V_28 , int V_29 , int V_30 )
{
unsigned long V_31 , V_32 , V_33 ;
struct V_34 * V_24 ;
T_2 * V_35 ;
T_4 * V_36 ;
T_3 * V_21 ;
int V_37 ;
F_11 ( V_31 ) ;
V_32 = ( V_29 ) ? F_12 ( V_38 ) :
V_27 -> V_39 + ( V_30 * sizeof( long ) ) ;
V_24 = ( ! F_13 ( V_27 ) && F_14 ( V_32 ) ) ? & V_40 : V_23 -> V_24 ;
if ( ! V_24 ) {
F_15 ( V_31 ) ;
return - 1 ;
}
V_35 = F_16 ( V_24 , V_32 ) ;
if ( F_17 ( * V_35 ) ) {
F_15 ( V_31 ) ;
return - 1 ;
}
V_36 = F_18 ( V_35 , V_32 ) ;
if ( F_19 ( * V_36 ) ) {
F_15 ( V_31 ) ;
return - 1 ;
}
V_21 = ( F_14 ( V_32 ) ) ? F_20 ( V_36 , V_32 )
: F_21 ( V_36 , V_32 ) ;
if ( F_22 ( * V_21 ) || ! F_23 ( * V_21 ) ) {
F_15 ( V_31 ) ;
return - 1 ;
}
if ( V_28 ) {
if ( ! F_24 ( * V_21 ) ) {
F_15 ( V_31 ) ;
return - 1 ;
}
F_8 ( V_21 , F_25 ( * V_21 ) ) ;
}
F_8 ( V_21 , F_26 ( * V_21 ) ) ;
V_37 = V_24 -> V_41 & 0xff ;
if ( ! F_27 ( * V_21 ) && ! F_14 ( V_32 ) )
F_8 ( V_21 , F_28 ( * V_21 ) ) ;
V_33 = ( V_32 & V_16 ) | ( V_37 << V_42 ) | V_43 ;
if ( ( V_32 < V_44 ) || ( V_32 >= V_45 ) )
V_33 |= ( V_21 -> V_21 & V_46 ) >> V_47 ;
F_29 ( V_48 , V_33 ) ;
F_29 ( V_49 , ( F_7 ( * V_21 ) & V_16 ) |
( ( V_21 -> V_21 ) & V_50 ) | V_51 | V_52 ) ;
if ( V_29 )
F_29 ( V_53 , V_54 | V_55 ) ;
else
F_29 ( V_53 , V_56 | V_54 | V_55 ) ;
F_15 ( V_31 ) ;
return 0 ;
}
void T_1 F_30 ( void )
{
V_57 [ 0 ] = ( 1 << V_58 ) - 1 ;
V_59 = V_58 ;
F_31 ( & V_60 , V_61 - V_58 + 1 ) ;
}
void F_32 ( void )
{
struct V_34 * V_24 ;
if ( V_59 < V_58 )
V_59 = V_58 ;
V_24 = V_62 [ V_59 ] ;
F_33 ( V_24 ) ;
F_34 ( V_24 ) ;
}
