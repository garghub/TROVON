static int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 ,
unsigned int V_4 )
{
struct V_5 * V_6 ;
struct V_7 V_8 ;
int V_9 = 0 ;
V_6 = V_10 [ V_2 -> V_6 ] ;
V_6 -> V_11 . V_12 = V_3 ;
V_8 . V_13 = V_2 -> V_14 ;
V_8 . V_15 = V_3 ;
F_2 ( V_2 , & V_8 ) ;
V_9 = F_3 ( V_6 -> V_6 , & V_6 -> V_11 ) ;
F_4 ( V_2 , & V_8 , V_9 != 0 ) ;
if ( V_9 )
F_5 ( L_1 ,
V_6 -> V_6 , V_9 ) ;
return V_9 ;
}
static int F_6 ( struct V_1 * V_2 )
{
F_7 ( V_2 ) ;
return 0 ;
}
static void F_8 ( struct V_1 * V_2 )
{
int V_16 = V_2 -> V_6 ;
struct V_5 * V_6 = V_10 [ V_16 ] ;
int V_9 ;
V_6 -> V_11 . V_12 = V_6 -> V_17 . V_18 ;
V_9 = F_3 ( V_16 , & V_6 -> V_11 ) ;
if ( V_9 )
F_5 ( L_2 ,
V_6 -> V_17 . V_18 , V_16 , V_9 ) ;
}
static int F_9 ( struct V_1 * V_2 )
{
struct V_5 * V_6 ;
unsigned int V_16 = V_2 -> V_6 ;
int V_9 = 0 ;
V_6 = V_10 [ V_2 -> V_6 ] ;
V_6 -> V_6 = V_16 ;
V_9 = F_10 ( V_2 -> V_6 , & V_6 -> V_17 ) ;
if ( V_9 ) {
F_5 ( L_3 ,
V_16 , V_9 ) ;
return V_9 ;
}
V_2 -> V_19 = V_6 -> V_17 . V_18 ;
V_2 -> V_20 = V_6 -> V_17 . V_21 ;
V_2 -> V_22 . V_23 = V_2 -> V_19 ;
V_2 -> V_22 . V_24 = V_2 -> V_20 ;
V_2 -> V_25 = V_6 -> V_25 ;
if ( V_2 -> V_25 == V_26 )
F_11 ( V_2 -> V_27 , V_6 -> V_28 ) ;
else if ( V_2 -> V_25 == V_29 ) {
F_5 ( L_4 ) ;
return - V_30 ;
}
F_12 ( V_2 -> V_6 , V_2 -> V_27 ) ;
V_6 -> V_31 = V_2 ;
V_2 -> V_14 = V_6 -> V_11 . V_12 = V_6 -> V_17 . V_21 ;
V_9 = F_3 ( V_16 , & V_6 -> V_11 ) ;
if ( V_9 )
F_5 ( L_2 ,
V_6 -> V_17 . V_21 , V_16 , V_9 ) ;
return V_9 ;
}
static int T_1 F_13 ( void )
{
int V_32 , V_9 = 0 ;
struct V_5 * V_6 ;
if ( V_33 )
return - V_34 ;
V_10 = F_14 ( sizeof( void * ) * F_15 () , V_35 ) ;
if ( ! V_10 )
return - V_36 ;
F_16 (i) {
V_10 [ V_32 ] = F_14 ( sizeof( struct V_5 ) , V_35 ) ;
if ( ! V_10 [ V_32 ] )
goto V_37;
V_6 = V_10 [ V_32 ] ;
if ( ! F_17 ( & V_6 -> V_28 , V_35 ) )
goto V_37;
}
V_9 = F_18 ( V_10 ) ;
if ( V_9 ) {
F_5 ( L_5 ) ;
goto V_37;
}
V_9 = F_19 ( & V_38 ) ;
if ( V_9 )
goto V_37;
return V_9 ;
V_37:
F_16 (i)
F_20 ( V_10 [ V_32 ] ) ;
F_20 ( V_10 ) ;
return - V_34 ;
}
