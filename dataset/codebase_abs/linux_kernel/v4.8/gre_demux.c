int F_1 ( const struct V_1 * V_2 , T_1 V_3 )
{
if ( V_3 >= V_4 )
return - V_5 ;
return ( F_2 ( ( const struct V_1 * * ) & V_6 [ V_3 ] , NULL , V_2 ) == NULL ) ?
0 : - V_7 ;
}
int F_3 ( const struct V_1 * V_2 , T_1 V_3 )
{
int V_8 ;
if ( V_3 >= V_4 )
return - V_5 ;
V_8 = ( F_2 ( ( const struct V_1 * * ) & V_6 [ V_3 ] , V_2 , NULL ) == V_2 ) ?
0 : - V_7 ;
if ( V_8 )
return V_8 ;
F_4 () ;
return 0 ;
}
int F_5 ( struct V_9 * V_10 , struct V_11 * V_12 ,
bool * V_13 , T_2 V_2 , int V_14 )
{
const struct V_15 * V_16 ;
T_3 * V_17 ;
int V_18 ;
if ( F_6 ( ! F_7 ( V_10 , V_14 + sizeof( struct V_15 ) ) ) )
return - V_5 ;
V_16 = (struct V_15 * ) ( V_10 -> V_19 + V_14 ) ;
if ( F_6 ( V_16 -> V_20 & ( V_21 | V_22 ) ) )
return - V_5 ;
V_12 -> V_20 = F_8 ( V_16 -> V_20 ) ;
V_18 = F_9 ( V_12 -> V_20 ) ;
if ( ! F_7 ( V_10 , V_14 + V_18 ) )
return - V_5 ;
V_16 = (struct V_15 * ) ( V_10 -> V_19 + V_14 ) ;
V_12 -> V_2 = V_16 -> V_23 ;
V_17 = ( T_3 * ) ( V_16 + 1 ) ;
if ( V_16 -> V_20 & V_24 ) {
if ( F_10 ( V_10 ) ) {
* V_13 = true ;
return - V_5 ;
}
F_11 ( V_10 , V_25 , 0 ,
V_26 ) ;
V_17 ++ ;
}
if ( V_16 -> V_20 & V_27 ) {
V_12 -> V_28 = * V_17 ;
V_17 ++ ;
} else {
V_12 -> V_28 = 0 ;
}
if ( F_6 ( V_16 -> V_20 & V_29 ) ) {
V_12 -> V_30 = * V_17 ;
V_17 ++ ;
} else {
V_12 -> V_30 = 0 ;
}
if ( V_16 -> V_20 == 0 && V_12 -> V_2 == F_12 ( V_31 ) ) {
V_12 -> V_2 = V_2 ;
if ( ( * ( T_1 * ) V_17 & 0xF0 ) != 0x40 )
V_18 += 4 ;
}
V_12 -> V_18 = V_18 ;
return V_18 ;
}
static int F_13 ( struct V_9 * V_10 )
{
const struct V_1 * V_2 ;
T_1 V_32 ;
int V_8 ;
if ( ! F_7 ( V_10 , 12 ) )
goto V_33;
V_32 = V_10 -> V_19 [ 1 ] & 0x7f ;
if ( V_32 >= V_4 )
goto V_33;
F_14 () ;
V_2 = F_15 ( V_6 [ V_32 ] ) ;
if ( ! V_2 || ! V_2 -> V_34 )
goto V_35;
V_8 = V_2 -> V_34 ( V_10 ) ;
F_16 () ;
return V_8 ;
V_35:
F_16 () ;
V_33:
F_17 ( V_10 ) ;
return V_36 ;
}
static void F_18 ( struct V_9 * V_10 , T_4 V_37 )
{
const struct V_1 * V_2 ;
const struct V_38 * V_39 = ( const struct V_38 * ) V_10 -> V_19 ;
T_1 V_32 = V_10 -> V_19 [ ( V_39 -> V_40 << 2 ) + 1 ] & 0x7f ;
if ( V_32 >= V_4 )
return;
F_14 () ;
V_2 = F_15 ( V_6 [ V_32 ] ) ;
if ( V_2 && V_2 -> V_41 )
V_2 -> V_41 ( V_10 , V_37 ) ;
F_16 () ;
}
static int T_5 F_19 ( void )
{
F_20 ( L_1 ) ;
if ( F_21 ( & V_42 , V_25 ) < 0 ) {
F_22 ( L_2 ) ;
return - V_43 ;
}
return 0 ;
}
static void T_6 F_23 ( void )
{
F_24 ( & V_42 , V_25 ) ;
}
