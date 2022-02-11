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
F_8 ( V_13 , V_16 ) ;
V_5 = F_9 ( V_13 , V_16 ) ;
F_6 ( V_16 ) ;
return V_5 ;
}
static int F_10 ( struct V_12 * V_13 ,
struct V_17 * V_18 )
{
struct V_1 * V_2 = V_13 -> V_14 -> V_15 ;
if ( ! V_2 -> V_19 )
return 0 ;
if ( V_18 -> V_20 * V_18 -> V_21 > V_2 -> V_19 )
return V_22 ;
return 0 ;
}
static enum V_23
F_11 ( struct V_12 * V_13 , bool V_24 )
{
if ( F_12 ( V_13 -> V_14 ) )
return V_25 ;
return V_26 ;
}
struct V_27 * F_13 ( struct V_12 * V_13 )
{
int V_28 = V_13 -> V_29 [ 0 ] ;
struct V_30 * V_31 ;
struct V_27 * V_32 ;
V_31 = F_14 ( V_13 -> V_14 , V_28 , V_33 ) ;
if ( ! V_31 )
return NULL ;
V_32 = F_15 ( V_31 ) ;
return V_32 ;
}
int F_16 ( struct V_12 * V_13 , struct V_34 * V_35 ,
T_2 V_36 )
{
return 0 ;
}
static void F_17 ( struct V_12 * V_13 )
{
F_18 ( V_13 ) ;
F_19 ( V_13 ) ;
F_6 ( V_13 ) ;
}
int F_20 ( struct V_37 * V_14 , struct V_27 * V_32 )
{
struct V_12 * V_13 ;
V_13 = F_21 ( sizeof( struct V_12 ) , V_8 ) ;
if ( ! V_13 )
return - V_38 ;
F_22 ( V_14 , V_13 , & V_39 , V_40 ) ;
F_23 ( V_13 , & V_41 ) ;
F_24 ( V_13 ) ;
F_25 ( V_13 , V_32 ) ;
F_26 ( V_13 ,
V_14 -> V_42 . V_43 ,
1 ) ;
return 0 ;
}
