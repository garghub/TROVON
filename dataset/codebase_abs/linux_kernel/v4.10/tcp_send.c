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
int F_8 ( struct V_28 * V_29 , struct V_30 * V_31 ,
unsigned int V_32 , unsigned int V_33 , unsigned int V_34 )
{
struct V_11 * V_12 = V_31 -> V_35 . V_36 ;
struct V_13 * V_14 = V_12 -> V_15 ;
int V_37 = 0 ;
int V_38 = 0 ;
int V_39 ;
if ( V_32 == 0 ) {
V_14 -> V_40 = F_9 ( V_14 ) ;
V_31 -> V_41 = V_14 -> V_40 +
sizeof( struct V_42 ) +
F_10 ( V_31 -> V_35 . V_43 . V_44 ) - 1 ;
F_11 () ;
F_12 ( V_45 , & V_31 -> V_46 ) ;
V_14 -> V_47 = V_31 -> V_41 + 1 ;
if ( F_13 ( V_48 , & V_31 -> V_46 ) )
V_31 -> V_35 . V_43 . V_49 |= V_50 ;
F_14 ( L_1 ,
V_31 , F_9 ( V_14 ) ,
( unsigned long long ) V_31 -> V_41 ) ;
}
if ( V_32 < sizeof( struct V_42 ) ) {
F_12 ( V_51 , & V_14 -> V_16 -> V_52 -> V_53 -> V_54 ) ;
V_38 = F_6 ( V_14 -> V_16 ,
( void * ) & V_31 -> V_35 . V_43 + V_32 ,
sizeof( V_31 -> V_35 . V_43 ) - V_32 ) ;
if ( V_38 < 0 )
goto V_55;
V_37 += V_38 ;
if ( V_32 + V_37 != sizeof( struct V_42 ) )
goto V_55;
}
V_39 = V_31 -> V_17 . V_56 > 1 ? ( V_57 | V_58 ) : 0 ;
while ( V_33 < V_31 -> V_17 . V_56 ) {
int V_54 = V_26 | V_27 | V_39 ;
V_38 = V_14 -> V_16 -> V_6 -> V_59 ( V_14 -> V_16 ,
F_15 ( & V_31 -> V_17 . V_60 [ V_33 ] ) ,
V_31 -> V_17 . V_60 [ V_33 ] . V_61 + V_34 ,
V_31 -> V_17 . V_60 [ V_33 ] . V_62 - V_34 ,
V_54 ) ;
F_14 ( L_2 , ( void * ) F_15 ( & V_31 -> V_17 . V_60 [ V_33 ] ) ,
V_31 -> V_17 . V_60 [ V_33 ] . V_61 + V_34 , V_31 -> V_17 . V_60 [ V_33 ] . V_62 - V_34 ,
V_38 ) ;
if ( V_38 <= 0 )
break;
V_34 += V_38 ;
V_37 += V_38 ;
if ( V_34 == V_31 -> V_17 . V_60 [ V_33 ] . V_62 ) {
V_34 = 0 ;
V_33 ++ ;
}
if ( V_33 == V_31 -> V_17 . V_56 - 1 )
V_39 = 0 ;
}
V_55:
if ( V_38 <= 0 ) {
if ( V_38 == - V_63 ) {
F_16 ( V_64 ) ;
V_38 = 0 ;
} else {
if ( F_17 ( V_12 ) ) {
F_18 ( L_3
L_4
L_5 ,
& V_29 -> V_65 , V_12 -> V_66 , V_38 ) ;
F_19 ( V_12 ) ;
}
}
}
if ( V_37 == 0 )
V_37 = V_38 ;
return V_37 ;
}
static int F_20 ( struct V_30 * V_31 , T_2 V_67 )
{
if ( ! F_13 ( V_45 , & V_31 -> V_46 ) )
return 0 ;
return ( V_68 ) ( ( V_69 ) V_31 -> V_41 - ( V_69 ) V_67 ) < 0 ;
}
void F_21 ( struct V_2 * V_52 )
{
void (* F_22)( struct V_2 * V_52 );
struct V_11 * V_12 ;
struct V_13 * V_14 ;
F_23 ( & V_52 -> V_70 ) ;
V_12 = V_52 -> V_71 ;
if ( ! V_12 ) {
F_22 = V_52 -> V_72 ;
goto V_55;
}
V_14 = V_12 -> V_15 ;
F_14 ( L_6 , V_14 ) ;
F_22 = V_14 -> V_73 ;
F_16 ( V_74 ) ;
F_14 ( L_7 , F_24 ( V_14 ) ) ;
V_14 -> V_75 = F_24 ( V_14 ) ;
F_25 ( V_12 , F_24 ( V_14 ) , F_20 ) ;
if ( ( F_26 ( & V_52 -> V_76 ) << 1 ) <= V_52 -> V_77 )
F_27 ( V_78 , & V_12 -> V_79 , 0 ) ;
V_55:
F_28 ( & V_52 -> V_70 ) ;
F_22 ( V_52 ) ;
if ( V_52 -> V_53 )
F_12 ( V_51 , & V_52 -> V_53 -> V_54 ) ;
}
