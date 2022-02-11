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
return 0 ;
}
static int F_14 ( struct V_14 * V_15 )
{
struct V_12 * V_13 = V_15 -> V_23 ;
F_8 ( L_1 , V_15 ) ;
F_13 ( & V_13 -> V_22 ) ;
F_15 ( & V_13 -> V_16 ) ;
V_15 -> V_23 = NULL ;
F_16 ( V_13 ) ;
return 0 ;
}
static int F_17 ( struct V_14 * V_15 , struct V_24 * V_25 )
{
struct V_12 * V_13 = V_15 -> V_23 ;
if ( F_18 ( V_25 ) -> V_26 == V_27 ) {
F_19 ( V_25 ) ;
return 0 ;
}
if ( F_18 ( V_25 ) -> V_26 == V_28 ) {
struct V_29 * V_30 = ( void * ) V_25 -> V_31 ;
if ( F_20 ( V_30 -> V_32 ) == V_33 )
V_13 -> V_17 = V_25 -> V_31 [ V_34 ] ;
}
F_8 ( L_2 , V_15 , V_25 ) ;
memcpy ( F_21 ( V_25 , 1 ) , & F_18 ( V_25 ) -> V_26 , 1 ) ;
F_22 ( & V_13 -> V_22 , V_25 ) ;
F_23 ( V_18 , & V_15 -> V_19 ) ;
F_24 ( & V_13 -> V_16 ) ;
return 0 ;
}
static struct V_24 * F_25 ( struct V_14 * V_15 )
{
struct V_12 * V_13 = V_15 -> V_23 ;
return F_26 ( & V_13 -> V_22 ) ;
}
static int F_27 ( struct V_14 * V_15 , void * V_31 , int V_35 )
{
int V_36 ;
V_36 = F_28 ( V_15 -> V_37 , V_31 , V_35 ) ;
if ( V_36 < 0 ) {
F_29 ( L_3 ) ;
return V_36 ;
}
return V_35 ;
}
int T_1 F_30 ( void )
{
int V_38 = F_31 ( & V_39 ) ;
if ( ! V_38 )
F_32 ( L_4 ) ;
else
F_29 ( L_5 ) ;
return V_38 ;
}
int T_2 F_33 ( void )
{
return F_34 ( & V_39 ) ;
}
