static void F_1 ( const struct V_1 * V_2 , void * V_3 )
{
const T_1 * V_4 = ( const T_1 * ) V_2 ;
T_2 * V_5 = ( T_2 * ) V_3 ;
if ( V_2 -> type == V_6 &&
V_2 -> V_7 >= V_8 ) {
T_2 V_9 = ( T_2 ) F_2 ( ( const T_2 * )
( V_4 + V_10 ) ) ;
* V_5 = V_9 > * V_5 ? V_9 : * V_5 ;
}
}
static T_3 F_3 ( void )
{
T_2 V_5 = 0 ;
F_4 ( F_1 , & V_5 ) ;
V_5 = V_5 ? V_5 : 1 ;
return ( 1000 * V_5 ) ;
}
static int F_5 ( struct V_11 * V_12 ,
unsigned int V_13 ,
unsigned int V_14 )
{
struct V_15 * V_16 ;
struct V_17 V_18 ;
T_4 V_19 ;
int V_20 = 0 ;
V_16 = V_21 [ V_12 -> V_16 ] ;
V_19 = ( T_3 ) V_13 * V_16 -> V_22 . V_23 / V_24 ;
if ( V_19 == V_16 -> V_25 . V_19 )
return V_20 ;
V_16 -> V_25 . V_19 = V_19 ;
V_18 . V_26 = V_12 -> V_27 ;
V_18 . V_28 = V_13 ;
F_6 ( V_12 , & V_18 ) ;
V_20 = F_7 ( V_16 -> V_16 , & V_16 -> V_25 ) ;
F_8 ( V_12 , & V_18 , V_20 != 0 ) ;
if ( V_20 )
F_9 ( L_1 ,
V_16 -> V_16 , V_20 ) ;
return V_20 ;
}
static int F_10 ( struct V_11 * V_12 )
{
F_11 ( V_12 ) ;
return 0 ;
}
static void F_12 ( struct V_11 * V_12 )
{
int V_29 = V_12 -> V_16 ;
struct V_15 * V_16 = V_21 [ V_29 ] ;
int V_20 ;
V_16 -> V_25 . V_19 = V_16 -> V_22 . V_30 ;
V_20 = F_7 ( V_29 , & V_16 -> V_25 ) ;
if ( V_20 )
F_9 ( L_2 ,
V_16 -> V_22 . V_30 , V_29 , V_20 ) ;
}
static int F_13 ( struct V_11 * V_12 )
{
struct V_15 * V_16 ;
unsigned int V_29 = V_12 -> V_16 ;
int V_20 = 0 ;
V_16 = V_21 [ V_12 -> V_16 ] ;
V_16 -> V_16 = V_29 ;
V_20 = F_14 ( V_12 -> V_16 , & V_16 -> V_22 ) ;
if ( V_20 ) {
F_9 ( L_3 ,
V_29 , V_20 ) ;
return V_20 ;
}
V_24 = F_3 () ;
V_12 -> V_31 = V_16 -> V_22 . V_30 * V_24 / V_16 -> V_22 . V_23 ;
V_12 -> V_32 = V_24 ;
V_12 -> V_33 . V_34 = V_12 -> V_31 ;
V_12 -> V_33 . V_35 = V_12 -> V_32 ;
V_12 -> V_33 . V_36 = F_15 ( V_29 ) ;
V_12 -> V_37 = V_16 -> V_37 ;
if ( V_12 -> V_37 == V_38 )
F_16 ( V_12 -> V_39 , V_16 -> V_40 ) ;
else if ( V_12 -> V_37 == V_41 ) {
F_9 ( L_4 ) ;
return - V_42 ;
}
F_17 ( V_12 -> V_16 , V_12 -> V_39 ) ;
V_16 -> V_43 = V_12 ;
V_12 -> V_27 = V_24 ;
V_16 -> V_25 . V_19 = V_16 -> V_22 . V_23 ;
V_20 = F_7 ( V_29 , & V_16 -> V_25 ) ;
if ( V_20 )
F_9 ( L_2 ,
V_16 -> V_22 . V_23 , V_29 , V_20 ) ;
return V_20 ;
}
static int T_5 F_18 ( void )
{
int V_44 , V_20 = 0 ;
struct V_15 * V_16 ;
if ( V_45 )
return - V_46 ;
V_21 = F_19 ( sizeof( void * ) * F_20 () , V_47 ) ;
if ( ! V_21 )
return - V_48 ;
F_21 (i) {
V_21 [ V_44 ] = F_19 ( sizeof( struct V_15 ) , V_47 ) ;
if ( ! V_21 [ V_44 ] )
goto V_49;
V_16 = V_21 [ V_44 ] ;
if ( ! F_22 ( & V_16 -> V_40 , V_47 ) )
goto V_49;
}
V_20 = F_23 ( V_21 ) ;
if ( V_20 ) {
F_9 ( L_5 ) ;
goto V_49;
}
V_20 = F_24 ( & V_50 ) ;
if ( V_20 )
goto V_49;
return V_20 ;
V_49:
F_21 (i)
F_25 ( V_21 [ V_44 ] ) ;
F_25 ( V_21 ) ;
return - V_46 ;
}
static void T_6 F_26 ( void )
{
struct V_15 * V_16 ;
int V_44 ;
F_27 ( & V_50 ) ;
F_21 (i) {
V_16 = V_21 [ V_44 ] ;
F_28 ( V_16 -> V_40 ) ;
F_25 ( V_16 ) ;
}
F_25 ( V_21 ) ;
}
