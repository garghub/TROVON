static void F_1 ( struct V_1 * V_2 , int V_3 )
{
F_2 ( V_2 , V_4 , V_5 , ( void * ) & V_3 , sizeof( V_3 ) ) ;
}
void F_3 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = V_7 -> V_10 ;
F_1 ( V_9 -> V_11 , 1 ) ;
}
void F_4 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = V_7 -> V_10 ;
F_1 ( V_9 -> V_11 , 0 ) ;
}
static int F_5 ( struct V_1 * V_2 , void * V_12 , unsigned int V_13 )
{
struct V_14 V_15 = {
. V_16 = V_12 ,
. V_17 = V_13 ,
} ;
struct V_18 V_19 = {
. V_20 = V_21 | V_22 ,
} ;
return F_6 ( V_2 , & V_19 , & V_15 , 1 , V_15 . V_17 ) ;
}
int F_7 ( struct V_23 * V_24 , struct V_25 * V_26 ,
unsigned int V_27 , unsigned int V_28 , unsigned int V_29 )
{
struct V_6 * V_7 = V_26 -> V_30 . V_31 ;
struct V_8 * V_9 = V_7 -> V_10 ;
int V_32 = 0 ;
int V_33 = 0 ;
int V_34 ;
if ( V_27 == 0 ) {
V_9 -> V_35 = F_8 ( V_9 ) ;
V_26 -> V_36 = V_9 -> V_35 +
sizeof( struct V_37 ) +
F_9 ( V_26 -> V_30 . V_38 . V_39 ) - 1 ;
F_10 () ;
F_11 ( V_40 , & V_26 -> V_41 ) ;
V_9 -> V_42 = V_26 -> V_36 + 1 ;
if ( F_12 ( V_43 , & V_26 -> V_41 ) )
V_26 -> V_30 . V_38 . V_44 |= V_45 ;
F_13 ( L_1 ,
V_26 , F_8 ( V_9 ) ,
( unsigned long long ) V_26 -> V_36 ) ;
}
if ( V_27 < sizeof( struct V_37 ) ) {
F_11 ( V_46 , & V_9 -> V_11 -> V_47 -> V_48 -> V_49 ) ;
V_33 = F_5 ( V_9 -> V_11 ,
( void * ) & V_26 -> V_30 . V_38 + V_27 ,
sizeof( V_26 -> V_30 . V_38 ) - V_27 ) ;
if ( V_33 < 0 )
goto V_50;
V_32 += V_33 ;
if ( V_27 + V_32 != sizeof( struct V_37 ) )
goto V_50;
}
V_34 = V_26 -> V_12 . V_51 > 1 ? ( V_52 | V_53 ) : 0 ;
while ( V_28 < V_26 -> V_12 . V_51 ) {
int V_49 = V_21 | V_22 | V_34 ;
V_33 = V_9 -> V_11 -> V_54 -> V_55 ( V_9 -> V_11 ,
F_14 ( & V_26 -> V_12 . V_56 [ V_28 ] ) ,
V_26 -> V_12 . V_56 [ V_28 ] . V_57 + V_29 ,
V_26 -> V_12 . V_56 [ V_28 ] . V_58 - V_29 ,
V_49 ) ;
F_13 ( L_2 , ( void * ) F_14 ( & V_26 -> V_12 . V_56 [ V_28 ] ) ,
V_26 -> V_12 . V_56 [ V_28 ] . V_57 + V_29 , V_26 -> V_12 . V_56 [ V_28 ] . V_58 - V_29 ,
V_33 ) ;
if ( V_33 <= 0 )
break;
V_29 += V_33 ;
V_32 += V_33 ;
if ( V_29 == V_26 -> V_12 . V_56 [ V_28 ] . V_58 ) {
V_29 = 0 ;
V_28 ++ ;
}
if ( V_28 == V_26 -> V_12 . V_51 - 1 )
V_34 = 0 ;
}
V_50:
if ( V_33 <= 0 ) {
if ( V_33 == - V_59 ) {
F_15 ( V_60 ) ;
V_33 = 0 ;
} else {
if ( F_16 ( V_7 ) ) {
F_17 ( L_3
L_4
L_5 ,
& V_24 -> V_61 , V_7 -> V_62 , V_33 ) ;
F_18 ( V_7 , false ) ;
}
}
}
if ( V_32 == 0 )
V_32 = V_33 ;
return V_32 ;
}
static int F_19 ( struct V_25 * V_26 , T_1 V_63 )
{
if ( ! F_12 ( V_40 , & V_26 -> V_41 ) )
return 0 ;
return ( V_64 ) ( ( V_65 ) V_26 -> V_36 - ( V_65 ) V_63 ) < 0 ;
}
void F_20 ( struct V_2 * V_47 )
{
void (* F_21)( struct V_2 * V_47 );
struct V_6 * V_7 ;
struct V_8 * V_9 ;
F_22 ( & V_47 -> V_66 ) ;
V_7 = V_47 -> V_67 ;
if ( ! V_7 ) {
F_21 = V_47 -> V_68 ;
goto V_50;
}
V_9 = V_7 -> V_10 ;
F_13 ( L_6 , V_9 ) ;
F_21 = V_9 -> V_69 ;
F_15 ( V_70 ) ;
F_13 ( L_7 , F_23 ( V_9 ) ) ;
V_9 -> V_71 = F_23 ( V_9 ) ;
F_24 ( V_7 , F_23 ( V_9 ) , F_19 ) ;
if ( ( F_25 ( & V_47 -> V_72 ) << 1 ) <= V_47 -> V_73 )
F_26 ( V_74 , & V_7 -> V_75 , 0 ) ;
V_50:
F_27 ( & V_47 -> V_66 ) ;
F_21 ( V_47 ) ;
if ( V_47 -> V_48 )
F_11 ( V_46 , & V_47 -> V_48 -> V_49 ) ;
}
