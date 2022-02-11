static T_1 * F_1 ( struct V_1 * V_2 )
{
T_1 * V_3 ;
char * V_4 ;
int V_5 , V_6 ;
V_3 = F_2 ( V_7 , V_8 ) ;
if ( V_3 == NULL )
return NULL ;
V_4 = F_2 ( 2 , V_8 ) ;
if ( V_4 == NULL )
goto error;
for ( V_6 = 0 ; V_6 < V_7 ; V_6 ++ ) {
V_5 = F_3 ( V_2 -> V_9 -> V_10 ,
F_4 ( V_2 -> V_9 -> V_10 , 0 ) , ( 0x02 ) ,
( 0x80 | ( 0x02 << 5 ) ) , V_6 << 8 , 0xA1 , V_4 , 2 ,
V_11 ) ;
if ( V_5 < 1 ) {
F_5 ( L_1 , V_6 , V_5 ) ;
goto error;
}
V_3 [ V_6 ] = V_4 [ 1 ] ;
}
F_6 ( V_4 ) ;
return V_3 ;
error:
F_6 ( V_3 ) ;
F_6 ( V_4 ) ;
return NULL ;
}
static int F_7 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = V_13 -> V_14 -> V_15 ;
struct V_16 * V_16 ;
int V_5 ;
V_16 = (struct V_16 * ) F_1 ( V_2 ) ;
if ( ! V_16 ) {
F_8 ( V_13 , NULL ) ;
return 0 ;
}
V_16 -> V_17 += V_16 -> V_18 ;
V_16 -> V_18 = 0 ;
F_8 ( V_13 , V_16 ) ;
V_5 = F_9 ( V_13 , V_16 ) ;
F_6 ( V_16 ) ;
return V_5 ;
}
static int F_10 ( struct V_12 * V_13 ,
struct V_19 * V_20 )
{
struct V_1 * V_2 = V_13 -> V_14 -> V_15 ;
if ( ! V_2 -> V_21 )
return 0 ;
if ( V_20 -> V_22 * V_20 -> V_23 > V_2 -> V_21 )
return V_24 ;
return 0 ;
}
static enum V_25
F_11 ( struct V_12 * V_13 , bool V_26 )
{
if ( F_12 ( V_13 -> V_14 ) )
return V_27 ;
return V_28 ;
}
static struct V_29 *
F_13 ( struct V_12 * V_13 )
{
int V_30 = V_13 -> V_31 [ 0 ] ;
return F_14 ( V_13 -> V_14 , V_30 ) ;
}
static int F_15 ( struct V_12 * V_13 ,
struct V_32 * V_33 ,
T_2 V_34 )
{
return 0 ;
}
static void F_16 ( struct V_12 * V_13 )
{
F_17 ( V_13 ) ;
F_18 ( V_13 ) ;
F_6 ( V_13 ) ;
}
int F_19 ( struct V_35 * V_14 , struct V_29 * V_36 )
{
struct V_12 * V_13 ;
V_13 = F_20 ( sizeof( struct V_12 ) , V_8 ) ;
if ( ! V_13 )
return - V_37 ;
F_21 ( V_14 , V_13 , & V_38 , V_39 ) ;
F_22 ( V_13 , & V_40 ) ;
F_23 ( V_13 ) ;
F_24 ( V_13 , V_36 ) ;
F_25 ( & V_13 -> V_41 ,
V_14 -> V_42 . V_43 ,
1 ) ;
return 0 ;
}
