static int F_1 ( struct V_1 * V_2 )
{
return 6 + V_2 -> V_3 / 4 ;
}
static int F_2 ( struct V_4 * V_5 , const T_1 * V_6 ,
unsigned int V_7 )
{
struct V_1 * V_2 = F_3 ( V_5 ) ;
int V_8 ;
V_8 = F_4 ( V_2 , V_6 , V_7 ) ;
if ( ! V_8 )
return 0 ;
V_5 -> V_9 . V_10 |= V_11 ;
return - V_12 ;
}
static int F_5 ( struct V_4 * V_5 , unsigned int V_13 )
{
if ( ( V_13 & 1 ) || V_13 < 4 )
return - V_12 ;
return 0 ;
}
static int F_6 ( struct V_14 * V_15 , T_1 V_16 [] , T_2 V_17 )
{
struct V_4 * V_18 = F_7 ( V_15 ) ;
T_3 * V_19 = ( T_3 * ) & V_16 [ V_20 - 8 ] ;
T_2 V_21 = V_15 -> V_22 [ 0 ] + 1 ;
if ( V_21 < 2 || V_21 > 8 )
return - V_12 ;
if ( V_21 < 4 && V_17 > > ( 8 * V_21 ) )
return - V_23 ;
V_19 [ 0 ] = 0 ;
V_19 [ 1 ] = F_8 ( V_17 ) ;
memcpy ( V_16 , V_15 -> V_22 , V_20 - V_21 ) ;
V_16 [ 0 ] |= ( F_9 ( V_18 ) - 2 ) << 2 ;
if ( V_15 -> V_24 )
V_16 [ 0 ] |= 0x40 ;
memset ( & V_15 -> V_22 [ V_20 - V_21 ] , 0 , V_21 ) ;
return 0 ;
}
static void F_10 ( struct V_14 * V_15 , T_1 V_25 [] )
{
struct V_4 * V_18 = F_7 ( V_15 ) ;
struct V_1 * V_2 = F_3 ( V_18 ) ;
struct V_26 { T_4 V_21 ; T_3 V_27 ; T_5 V_28 ; } V_29 ;
struct V_30 V_31 ;
T_2 V_28 = V_15 -> V_24 ;
T_2 V_32 = 0 ;
if ( V_28 < 0xff00 ) {
V_29 . V_21 = F_11 ( V_28 ) ;
V_29 . V_28 = 2 ;
} else {
V_29 . V_21 = F_11 ( 0xfffe ) ;
F_12 ( V_28 , & V_29 . V_27 ) ;
V_29 . V_28 = 6 ;
}
F_13 ( V_25 , ( T_1 * ) & V_29 , V_29 . V_28 , & V_32 , V_2 -> V_33 ,
F_1 ( V_2 ) ) ;
F_14 ( & V_31 , V_15 -> V_34 ) ;
do {
T_2 V_19 = F_15 ( & V_31 , V_28 ) ;
T_1 * V_35 ;
if ( ! V_19 ) {
F_14 ( & V_31 , F_16 ( V_31 . V_36 ) ) ;
V_19 = F_15 ( & V_31 , V_28 ) ;
}
V_35 = F_17 ( & V_31 ) ;
F_13 ( V_25 , V_35 , V_19 , & V_32 , V_2 -> V_33 ,
F_1 ( V_2 ) ) ;
V_28 -= V_19 ;
F_18 ( V_35 ) ;
F_19 ( & V_31 , V_19 ) ;
F_20 ( & V_31 , 0 , V_28 ) ;
} while ( V_28 );
}
static int F_21 ( struct V_14 * V_15 )
{
struct V_4 * V_18 = F_7 ( V_15 ) ;
struct V_1 * V_2 = F_3 ( V_18 ) ;
struct V_37 V_31 ;
T_1 V_38 ( 8 ) V_25 [ V_20 ] ;
T_1 V_39 [ V_20 ] ;
T_2 V_28 = V_15 -> V_40 ;
int V_41 ;
V_41 = F_6 ( V_15 , V_25 , V_28 ) ;
if ( V_41 )
return V_41 ;
F_22 ( 6 ) ;
if ( V_15 -> V_24 )
F_10 ( V_15 , V_25 ) ;
memcpy ( V_39 , V_15 -> V_22 , V_20 ) ;
V_41 = F_23 ( & V_31 , V_15 , true ) ;
while ( V_31 . V_42 ) {
T_2 V_43 = V_31 . V_42 % V_20 ;
if ( V_31 . V_42 == V_31 . V_44 )
V_43 = 0 ;
F_24 ( V_31 . V_45 . V_46 . V_47 , V_31 . V_34 . V_46 . V_47 ,
V_31 . V_42 - V_43 , V_2 -> V_33 ,
F_1 ( V_2 ) , V_25 , V_31 . V_22 ) ;
V_41 = F_25 ( & V_31 , V_43 ) ;
}
if ( ! V_41 )
F_26 ( V_25 , V_39 , V_2 -> V_33 , F_1 ( V_2 ) ) ;
F_27 () ;
if ( V_41 )
return V_41 ;
F_28 ( V_25 , V_15 -> V_45 , V_15 -> V_24 + V_15 -> V_40 ,
F_9 ( V_18 ) , 1 ) ;
return 0 ;
}
static int F_29 ( struct V_14 * V_15 )
{
struct V_4 * V_18 = F_7 ( V_15 ) ;
struct V_1 * V_2 = F_3 ( V_18 ) ;
unsigned int V_13 = F_9 ( V_18 ) ;
struct V_37 V_31 ;
T_1 V_38 ( 8 ) V_25 [ V_20 ] ;
T_1 V_39 [ V_20 ] ;
T_2 V_28 = V_15 -> V_40 - V_13 ;
int V_41 ;
V_41 = F_6 ( V_15 , V_25 , V_28 ) ;
if ( V_41 )
return V_41 ;
F_22 ( 6 ) ;
if ( V_15 -> V_24 )
F_10 ( V_15 , V_25 ) ;
memcpy ( V_39 , V_15 -> V_22 , V_20 ) ;
V_41 = F_30 ( & V_31 , V_15 , true ) ;
while ( V_31 . V_42 ) {
T_2 V_43 = V_31 . V_42 % V_20 ;
if ( V_31 . V_42 == V_31 . V_44 )
V_43 = 0 ;
F_31 ( V_31 . V_45 . V_46 . V_47 , V_31 . V_34 . V_46 . V_47 ,
V_31 . V_42 - V_43 , V_2 -> V_33 ,
F_1 ( V_2 ) , V_25 , V_31 . V_22 ) ;
V_41 = F_25 ( & V_31 , V_43 ) ;
}
if ( ! V_41 )
F_26 ( V_25 , V_39 , V_2 -> V_33 , F_1 ( V_2 ) ) ;
F_27 () ;
if ( V_41 )
return V_41 ;
F_28 ( V_39 , V_15 -> V_34 ,
V_15 -> V_24 + V_15 -> V_40 - V_13 ,
V_13 , 0 ) ;
if ( F_32 ( V_25 , V_39 , V_13 ) )
return - V_48 ;
return 0 ;
}
static int T_6 F_33 ( void )
{
if ( ! ( V_49 & V_50 ) )
return - V_51 ;
return F_34 ( & V_52 ) ;
}
static void T_7 F_35 ( void )
{
F_36 ( & V_52 ) ;
}
