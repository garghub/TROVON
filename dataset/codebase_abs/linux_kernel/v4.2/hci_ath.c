static int F_1 ( struct V_1 * V_2 )
{
int V_3 = V_2 -> V_4 -> V_5 -> V_6 ( V_2 ) ;
if ( V_3 & V_7 )
return V_3 ;
V_2 -> V_4 -> V_5 -> V_6 ( V_2 ) ;
V_2 -> V_4 -> V_5 -> V_8 ( V_2 , 0x00 , V_9 ) ;
F_2 ( 20 ) ;
V_2 -> V_4 -> V_5 -> V_6 ( V_2 ) ;
V_2 -> V_4 -> V_5 -> V_8 ( V_2 , V_9 , 0x00 ) ;
F_2 ( 20 ) ;
V_3 = V_2 -> V_4 -> V_5 -> V_6 ( V_2 ) ;
return V_3 ;
}
static void F_3 ( struct V_10 * V_11 )
{
int V_3 ;
struct V_12 * V_13 ;
struct V_14 * V_15 ;
struct V_1 * V_2 ;
V_13 = F_4 ( V_11 , struct V_12 , V_16 ) ;
V_15 = V_13 -> V_15 ;
V_2 = V_15 -> V_2 ;
if ( V_13 -> V_17 ) {
V_3 = F_1 ( V_2 ) ;
if ( ! ( V_3 & V_7 ) )
return;
}
F_5 ( V_18 , & V_15 -> V_19 ) ;
F_6 ( V_15 ) ;
}
static int F_7 ( struct V_14 * V_15 )
{
struct V_12 * V_13 ;
F_8 ( L_1 , V_15 ) ;
V_13 = F_9 ( sizeof( * V_13 ) , V_20 ) ;
if ( ! V_13 )
return - V_21 ;
F_10 ( & V_13 -> V_22 ) ;
V_15 -> V_23 = V_13 ;
V_13 -> V_15 = V_15 ;
F_11 ( & V_13 -> V_16 , F_3 ) ;
return 0 ;
}
static int F_12 ( struct V_14 * V_15 )
{
struct V_12 * V_13 = V_15 -> V_23 ;
F_8 ( L_1 , V_15 ) ;
F_13 ( & V_13 -> V_22 ) ;
F_14 ( V_13 -> V_24 ) ;
F_15 ( & V_13 -> V_16 ) ;
V_15 -> V_23 = NULL ;
F_16 ( V_13 ) ;
return 0 ;
}
static int F_17 ( struct V_14 * V_15 )
{
struct V_12 * V_13 = V_15 -> V_23 ;
F_8 ( L_1 , V_15 ) ;
F_13 ( & V_13 -> V_22 ) ;
return 0 ;
}
static int F_18 ( struct V_25 * V_26 , const T_1 * V_27 )
{
struct V_28 * V_29 ;
T_2 V_30 [ 10 ] ;
int V_31 ;
V_30 [ 0 ] = 0x01 ;
V_30 [ 1 ] = 0x01 ;
V_30 [ 2 ] = 0x00 ;
V_30 [ 3 ] = sizeof( T_1 ) ;
memcpy ( V_30 + 4 , V_27 , sizeof( T_1 ) ) ;
V_29 = F_19 ( V_26 , 0xfc0b , sizeof( V_30 ) , V_30 , V_32 ) ;
if ( F_20 ( V_29 ) ) {
V_31 = F_21 ( V_29 ) ;
F_22 ( L_2 ,
V_26 -> V_33 , V_31 ) ;
return V_31 ;
}
F_14 ( V_29 ) ;
return 0 ;
}
static int F_23 ( struct V_14 * V_15 )
{
F_8 ( L_1 , V_15 ) ;
V_15 -> V_26 -> V_34 = F_18 ;
return 0 ;
}
static int F_24 ( struct V_14 * V_15 , const void * V_35 , int V_36 )
{
struct V_12 * V_13 = V_15 -> V_23 ;
V_13 -> V_24 = F_25 ( V_15 -> V_26 , V_13 -> V_24 , V_35 , V_36 ,
V_37 , F_26 ( V_37 ) ) ;
if ( F_20 ( V_13 -> V_24 ) ) {
int V_31 = F_21 ( V_13 -> V_24 ) ;
F_22 ( L_3 , V_15 -> V_26 -> V_33 , V_31 ) ;
V_13 -> V_24 = NULL ;
return V_31 ;
}
return V_36 ;
}
static int F_27 ( struct V_14 * V_15 , struct V_28 * V_29 )
{
struct V_12 * V_13 = V_15 -> V_23 ;
if ( F_28 ( V_29 ) -> V_38 == V_39 ) {
F_14 ( V_29 ) ;
return 0 ;
}
if ( F_28 ( V_29 ) -> V_38 == V_40 ) {
struct V_41 * V_42 = ( void * ) V_29 -> V_35 ;
if ( F_29 ( V_42 -> V_43 ) == V_44 )
V_13 -> V_17 = V_29 -> V_35 [ V_45 ] ;
}
F_8 ( L_4 , V_15 , V_29 ) ;
memcpy ( F_30 ( V_29 , 1 ) , & F_28 ( V_29 ) -> V_38 , 1 ) ;
F_31 ( & V_13 -> V_22 , V_29 ) ;
F_32 ( V_18 , & V_15 -> V_19 ) ;
F_33 ( & V_13 -> V_16 ) ;
return 0 ;
}
static struct V_28 * F_34 ( struct V_14 * V_15 )
{
struct V_12 * V_13 = V_15 -> V_23 ;
return F_35 ( & V_13 -> V_22 ) ;
}
int T_3 F_36 ( void )
{
return F_37 ( & V_46 ) ;
}
int T_4 F_38 ( void )
{
return F_39 ( & V_46 ) ;
}
