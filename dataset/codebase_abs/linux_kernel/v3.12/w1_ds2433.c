static inline T_1 F_1 ( T_2 V_1 , T_1 V_2 , T_1 V_3 )
{
if ( V_1 > V_3 )
return 0 ;
if ( ( V_1 + V_2 ) > V_3 )
return ( V_3 - V_1 ) ;
return V_2 ;
}
static int F_2 ( struct V_4 * V_5 , struct V_6 * V_7 ,
int V_8 )
{
T_3 V_9 [ 3 ] ;
int V_1 = V_8 * V_10 ;
if ( V_7 -> V_11 & ( 1 << V_8 ) )
return 0 ;
if ( F_3 ( V_5 ) ) {
V_7 -> V_11 = 0 ;
return - V_12 ;
}
V_9 [ 0 ] = V_13 ;
V_9 [ 1 ] = V_1 & 0xff ;
V_9 [ 2 ] = V_1 >> 8 ;
F_4 ( V_5 -> V_14 , V_9 , 3 ) ;
F_5 ( V_5 -> V_14 , & V_7 -> V_15 [ V_1 ] , V_10 ) ;
if ( F_6 ( V_16 , & V_7 -> V_15 [ V_1 ] , V_10 ) == V_17 )
V_7 -> V_11 |= ( 1 << V_8 ) ;
return 0 ;
}
static T_4 F_7 ( struct V_18 * V_19 , struct V_20 * V_21 ,
struct V_22 * V_23 , char * V_24 ,
T_2 V_1 , T_1 V_2 )
{
struct V_4 * V_5 = F_8 ( V_21 ) ;
#ifdef F_9
struct V_6 * V_7 = V_5 -> V_25 ;
int V_26 , V_27 , V_28 ;
#else
T_3 V_9 [ 3 ] ;
#endif
if ( ( V_2 = F_1 ( V_1 , V_2 , V_29 ) ) == 0 )
return 0 ;
F_10 ( & V_5 -> V_14 -> V_30 ) ;
#ifdef F_9
V_27 = ( V_1 >> V_31 ) ;
V_28 = ( V_1 + V_2 - 1 ) >> V_31 ;
for ( V_26 = V_27 ; V_26 <= V_28 ; V_26 ++ ) {
if ( F_2 ( V_5 , V_7 , V_26 ) ) {
V_2 = - V_12 ;
goto V_32;
}
}
memcpy ( V_24 , & V_7 -> V_15 [ V_1 ] , V_2 ) ;
#else
if ( F_3 ( V_5 ) ) {
V_2 = - V_12 ;
goto V_32;
}
V_9 [ 0 ] = V_13 ;
V_9 [ 1 ] = V_1 & 0xff ;
V_9 [ 2 ] = V_1 >> 8 ;
F_4 ( V_5 -> V_14 , V_9 , 3 ) ;
F_5 ( V_5 -> V_14 , V_24 , V_2 ) ;
#endif
V_32:
F_11 ( & V_5 -> V_14 -> V_30 ) ;
return V_2 ;
}
static int F_12 ( struct V_4 * V_5 , int V_33 , int V_34 , const T_3 * V_7 )
{
#ifdef F_9
struct V_6 * V_35 = V_5 -> V_25 ;
#endif
T_3 V_9 [ 4 ] ;
T_3 V_36 [ V_10 + 3 ] ;
T_3 V_37 = ( V_33 + V_34 - 1 ) & 0x1f ;
if ( F_3 ( V_5 ) )
return - 1 ;
V_9 [ 0 ] = V_38 ;
V_9 [ 1 ] = V_33 & 0xff ;
V_9 [ 2 ] = V_33 >> 8 ;
F_4 ( V_5 -> V_14 , V_9 , 3 ) ;
F_4 ( V_5 -> V_14 , V_7 , V_34 ) ;
if ( F_3 ( V_5 ) )
return - 1 ;
F_13 ( V_5 -> V_14 , V_39 ) ;
F_5 ( V_5 -> V_14 , V_36 , V_34 + 3 ) ;
if ( ( V_36 [ 0 ] != V_9 [ 1 ] ) || ( V_36 [ 1 ] != V_9 [ 2 ] ) ||
( V_36 [ 2 ] != V_37 ) || ( memcmp ( V_7 , & V_36 [ 3 ] , V_34 ) != 0 ) )
return - 1 ;
if ( F_3 ( V_5 ) )
return - 1 ;
V_9 [ 0 ] = V_40 ;
V_9 [ 3 ] = V_37 ;
F_4 ( V_5 -> V_14 , V_9 , 4 ) ;
F_14 ( 5 ) ;
F_15 ( V_5 -> V_14 ) ;
#ifdef F_9
V_35 -> V_11 &= ~ ( 1 << ( V_33 >> V_31 ) ) ;
#endif
return 0 ;
}
static T_4 F_16 ( struct V_18 * V_19 , struct V_20 * V_21 ,
struct V_22 * V_23 , char * V_24 ,
T_2 V_1 , T_1 V_2 )
{
struct V_4 * V_5 = F_8 ( V_21 ) ;
int V_33 , V_34 , V_41 ;
if ( ( V_2 = F_1 ( V_1 , V_2 , V_29 ) ) == 0 )
return 0 ;
#ifdef F_9
if ( ( V_1 & V_42 ) || ( V_2 & V_42 ) ) {
F_17 ( & V_5 -> V_43 , L_1 ,
( int ) V_1 , V_2 ) ;
return - V_44 ;
}
for ( V_41 = 0 ; V_41 < V_2 ; V_41 += V_10 ) {
if ( F_6 ( V_16 , & V_24 [ V_41 ] , V_10 ) != V_17 ) {
F_17 ( & V_5 -> V_43 , L_2 , ( int ) V_1 ) ;
return - V_44 ;
}
}
#endif
F_10 ( & V_5 -> V_14 -> V_30 ) ;
V_41 = 0 ;
while ( V_41 < V_2 ) {
V_33 = V_1 + V_41 ;
V_34 = V_10 - ( V_33 & V_42 ) ;
if ( V_34 > ( V_2 - V_41 ) )
V_34 = V_2 - V_41 ;
if ( F_12 ( V_5 , V_33 , V_34 , & V_24 [ V_41 ] ) < 0 ) {
V_2 = - V_12 ;
goto V_32;
}
V_41 += V_34 ;
}
V_32:
F_11 ( & V_5 -> V_14 -> V_30 ) ;
return V_2 ;
}
static int F_18 ( struct V_4 * V_5 )
{
#ifdef F_9
struct V_6 * V_7 ;
V_7 = F_19 ( sizeof( struct V_6 ) , V_45 ) ;
if ( ! V_7 )
return - V_46 ;
V_5 -> V_25 = V_7 ;
#endif
return 0 ;
}
static void F_20 ( struct V_4 * V_5 )
{
#ifdef F_9
F_21 ( V_5 -> V_25 ) ;
V_5 -> V_25 = NULL ;
#endif
}
static int T_5 F_22 ( void )
{
return F_23 ( & V_47 ) ;
}
static void T_6 F_24 ( void )
{
F_25 ( & V_47 ) ;
}
