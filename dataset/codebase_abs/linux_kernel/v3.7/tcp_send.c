static void F_1 ( struct V_1 * V_2 , int V_3 )
{
T_1 V_4 ;
V_4 = F_2 () ;
F_3 ( V_5 ) ;
V_2 -> V_6 -> V_7 ( V_2 , V_8 , V_9 , ( char V_10 * ) & V_3 ,
sizeof( V_3 ) ) ;
F_3 ( V_4 ) ;
}
void F_4 ( struct V_11 * V_12 )
{
struct V_13 * V_14 = V_12 -> V_15 ;
F_1 ( V_14 -> V_16 , 1 ) ;
}
void F_5 ( struct V_11 * V_12 )
{
struct V_13 * V_14 = V_12 -> V_15 ;
F_1 ( V_14 -> V_16 , 0 ) ;
}
static int F_6 ( struct V_1 * V_2 , void * V_17 , unsigned int V_18 )
{
struct V_19 V_20 = {
. V_21 = V_17 ,
. V_22 = V_18 ,
} ;
struct V_23 V_24 = {
. V_25 = V_26 | V_27 ,
} ;
return F_7 ( V_2 , & V_24 , & V_20 , 1 , V_20 . V_22 ) ;
}
int F_8 ( struct V_11 * V_12 , struct V_28 * V_29 ,
unsigned int V_30 , unsigned int V_31 , unsigned int V_32 )
{
struct V_13 * V_14 = V_12 -> V_15 ;
int V_33 = 0 ;
int V_34 = 0 ;
if ( V_30 == 0 ) {
V_14 -> V_35 = F_9 ( V_14 ) ;
V_29 -> V_36 = V_14 -> V_35 +
sizeof( struct V_37 ) +
F_10 ( V_29 -> V_38 . V_39 . V_40 ) - 1 ;
F_11 () ;
F_12 ( V_41 , & V_29 -> V_42 ) ;
V_14 -> V_43 = V_29 -> V_36 + 1 ;
F_13 ( L_1 ,
V_29 , F_9 ( V_14 ) ,
( unsigned long long ) V_29 -> V_36 ) ;
}
if ( V_30 < sizeof( struct V_37 ) ) {
F_12 ( V_44 , & V_14 -> V_16 -> V_45 -> V_46 -> V_47 ) ;
V_34 = F_6 ( V_14 -> V_16 ,
( void * ) & V_29 -> V_38 . V_39 + V_30 ,
sizeof( V_29 -> V_38 . V_39 ) - V_30 ) ;
if ( V_34 < 0 )
goto V_48;
V_33 += V_34 ;
if ( V_30 + V_33 != sizeof( struct V_37 ) )
goto V_48;
}
while ( V_31 < V_29 -> V_17 . V_49 ) {
V_34 = V_14 -> V_16 -> V_6 -> V_50 ( V_14 -> V_16 ,
F_14 ( & V_29 -> V_17 . V_51 [ V_31 ] ) ,
V_29 -> V_17 . V_51 [ V_31 ] . V_52 + V_32 ,
V_29 -> V_17 . V_51 [ V_31 ] . V_53 - V_32 ,
V_26 | V_27 ) ;
F_13 ( L_2 , ( void * ) F_14 ( & V_29 -> V_17 . V_51 [ V_31 ] ) ,
V_29 -> V_17 . V_51 [ V_31 ] . V_52 + V_32 , V_29 -> V_17 . V_51 [ V_31 ] . V_53 - V_32 ,
V_34 ) ;
if ( V_34 <= 0 )
break;
V_32 += V_34 ;
V_33 += V_34 ;
if ( V_32 == V_29 -> V_17 . V_51 [ V_31 ] . V_53 ) {
V_32 = 0 ;
V_31 ++ ;
}
}
V_48:
if ( V_34 <= 0 ) {
if ( V_34 == - V_54 ) {
F_15 ( V_55 ) ;
V_34 = 0 ;
} else {
F_16 ( V_56 L_3
L_4 ,
& V_12 -> V_57 , V_34 ) ;
F_17 ( V_12 ) ;
}
}
if ( V_33 == 0 )
V_33 = V_34 ;
return V_33 ;
}
static int F_18 ( struct V_28 * V_29 , T_2 V_58 )
{
if ( ! F_19 ( V_41 , & V_29 -> V_42 ) )
return 0 ;
return ( V_59 ) ( ( V_60 ) V_29 -> V_36 - ( V_60 ) V_58 ) < 0 ;
}
void F_20 ( struct V_2 * V_45 )
{
void (* F_21)( struct V_2 * V_45 );
struct V_11 * V_12 ;
struct V_13 * V_14 ;
F_22 ( & V_45 -> V_61 ) ;
V_12 = V_45 -> V_62 ;
if ( ! V_12 ) {
F_21 = V_45 -> V_63 ;
goto V_48;
}
V_14 = V_12 -> V_15 ;
F_13 ( L_5 , V_14 ) ;
F_21 = V_14 -> V_64 ;
F_15 ( V_65 ) ;
F_13 ( L_6 , F_23 ( V_14 ) ) ;
V_14 -> V_66 = F_23 ( V_14 ) ;
F_24 ( V_12 , F_23 ( V_14 ) , F_18 ) ;
if ( ( F_25 ( & V_45 -> V_67 ) << 1 ) <= V_45 -> V_68 )
F_26 ( V_69 , & V_12 -> V_70 , 0 ) ;
V_48:
F_27 ( & V_45 -> V_61 ) ;
F_21 ( V_45 ) ;
if ( V_45 -> V_46 )
F_12 ( V_44 , & V_45 -> V_46 -> V_47 ) ;
}
