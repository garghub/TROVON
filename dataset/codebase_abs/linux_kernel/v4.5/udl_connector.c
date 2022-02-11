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
V_5 = F_3 ( V_2 -> V_9 ,
F_4 ( V_2 -> V_9 , 0 ) , ( 0x02 ) ,
( 0x80 | ( 0x02 << 5 ) ) , V_6 << 8 , 0xA1 , V_4 , 2 ,
V_10 ) ;
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
static int F_7 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = V_12 -> V_13 -> V_14 ;
struct V_15 * V_15 ;
int V_5 ;
V_15 = (struct V_15 * ) F_1 ( V_2 ) ;
if ( ! V_15 ) {
F_8 ( V_12 , NULL ) ;
return 0 ;
}
V_15 -> V_16 += V_15 -> V_17 ;
V_15 -> V_17 = 0 ;
F_8 ( V_12 , V_15 ) ;
V_5 = F_9 ( V_12 , V_15 ) ;
F_6 ( V_15 ) ;
return V_5 ;
}
static int F_10 ( struct V_11 * V_12 ,
struct V_18 * V_19 )
{
struct V_1 * V_2 = V_12 -> V_13 -> V_14 ;
if ( ! V_2 -> V_20 )
return 0 ;
if ( V_19 -> V_21 * V_19 -> V_22 > V_2 -> V_20 )
return V_23 ;
return 0 ;
}
static enum V_24
F_11 ( struct V_11 * V_12 , bool V_25 )
{
if ( F_12 ( V_12 -> V_13 ) )
return V_26 ;
return V_27 ;
}
static struct V_28 *
F_13 ( struct V_11 * V_12 )
{
int V_29 = V_12 -> V_30 [ 0 ] ;
return F_14 ( V_12 -> V_13 , V_29 ) ;
}
static int F_15 ( struct V_11 * V_12 ,
struct V_31 * V_32 ,
T_2 V_33 )
{
return 0 ;
}
static void F_16 ( struct V_11 * V_12 )
{
F_17 ( V_12 ) ;
F_18 ( V_12 ) ;
F_6 ( V_12 ) ;
}
int F_19 ( struct V_34 * V_13 , struct V_28 * V_35 )
{
struct V_11 * V_12 ;
V_12 = F_20 ( sizeof( struct V_11 ) , V_8 ) ;
if ( ! V_12 )
return - V_36 ;
F_21 ( V_13 , V_12 , & V_37 , V_38 ) ;
F_22 ( V_12 , & V_39 ) ;
F_23 ( V_12 ) ;
F_24 ( V_12 , V_35 ) ;
F_25 ( & V_12 -> V_40 ,
V_13 -> V_41 . V_42 ,
1 ) ;
return 0 ;
}
