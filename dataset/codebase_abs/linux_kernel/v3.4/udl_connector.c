static T_1 * F_1 ( struct V_1 * V_2 )
{
T_1 * V_3 ;
char V_4 [ 3 ] ;
int V_5 , V_6 ;
V_3 = F_2 ( V_7 , V_8 ) ;
if ( V_3 == NULL )
return NULL ;
for ( V_6 = 0 ; V_6 < V_7 ; V_6 ++ ) {
V_5 = F_3 ( V_2 -> V_9 -> V_10 ,
F_4 ( V_2 -> V_9 -> V_10 , 0 ) , ( 0x02 ) ,
( 0x80 | ( 0x02 << 5 ) ) , V_6 << 8 , 0xA1 , V_4 , 2 ,
V_11 ) ;
if ( V_5 < 1 ) {
F_5 ( L_1 , V_6 , V_5 ) ;
V_6 -- ;
goto error;
}
V_3 [ V_6 ] = V_4 [ 1 ] ;
}
return V_3 ;
error:
F_6 ( V_3 ) ;
return NULL ;
}
static int F_7 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = V_13 -> V_14 -> V_15 ;
struct V_16 * V_16 ;
int V_5 ;
V_16 = (struct V_16 * ) F_1 ( V_2 ) ;
V_13 -> V_17 . V_18 = ( char * ) V_16 ;
F_8 ( V_13 , V_16 ) ;
V_5 = F_9 ( V_13 , V_16 ) ;
V_13 -> V_17 . V_18 = NULL ;
F_6 ( V_16 ) ;
return V_5 ;
}
static int F_10 ( struct V_12 * V_13 ,
struct V_19 * V_20 )
{
return 0 ;
}
static enum V_21
F_11 ( struct V_12 * V_13 , bool V_22 )
{
if ( F_12 ( V_13 -> V_14 ) )
return V_23 ;
return V_24 ;
}
struct V_25 * F_13 ( struct V_12 * V_13 )
{
int V_26 = V_13 -> V_27 [ 0 ] ;
struct V_28 * V_29 ;
struct V_25 * V_30 ;
V_29 = F_14 ( V_13 -> V_14 , V_26 , V_31 ) ;
if ( ! V_29 )
return NULL ;
V_30 = F_15 ( V_29 ) ;
return V_30 ;
}
int F_16 ( struct V_12 * V_13 , struct V_32 * V_33 ,
T_2 V_34 )
{
return 0 ;
}
static void F_17 ( struct V_12 * V_13 )
{
F_18 ( V_13 ) ;
F_19 ( V_13 ) ;
F_6 ( V_13 ) ;
}
int F_20 ( struct V_35 * V_14 , struct V_25 * V_30 )
{
struct V_12 * V_13 ;
V_13 = F_21 ( sizeof( struct V_12 ) , V_8 ) ;
if ( ! V_13 )
return - V_36 ;
F_22 ( V_14 , V_13 , & V_37 , V_38 ) ;
F_23 ( V_13 , & V_39 ) ;
F_24 ( V_13 ) ;
F_25 ( V_13 , V_30 ) ;
F_26 ( V_13 ,
V_14 -> V_40 . V_41 ,
1 ) ;
return 0 ;
}
