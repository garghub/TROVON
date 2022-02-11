static int F_1 ( struct V_1 * V_2 )
{
struct V_3 V_3 ;
int V_4 = V_2 -> V_5 -> V_6 -> V_7 ( V_2 ) ;
if ( V_4 & V_8 )
return V_4 ;
memcpy ( & V_3 , V_2 -> V_9 , sizeof( V_3 ) ) ;
V_3 . V_10 &= ~ V_11 ;
F_2 ( V_2 , & V_3 ) ;
V_4 = V_2 -> V_5 -> V_6 -> V_7 ( V_2 ) ;
V_2 -> V_5 -> V_6 -> V_12 ( V_2 , 0x00 , V_13 ) ;
F_3 ( 20 ) ;
V_4 = V_2 -> V_5 -> V_6 -> V_7 ( V_2 ) ;
V_2 -> V_5 -> V_6 -> V_12 ( V_2 , V_13 , 0x00 ) ;
F_3 ( 20 ) ;
V_4 = V_2 -> V_5 -> V_6 -> V_7 ( V_2 ) ;
V_3 . V_10 |= V_11 ;
V_4 = F_2 ( V_2 , & V_3 ) ;
return V_4 ;
}
static void F_4 ( struct V_14 * V_15 )
{
int V_4 ;
struct V_16 * V_17 ;
struct V_18 * V_19 ;
struct V_1 * V_2 ;
V_17 = F_5 ( V_15 , struct V_16 , V_20 ) ;
V_19 = V_17 -> V_19 ;
V_2 = V_19 -> V_2 ;
if ( V_17 -> V_21 ) {
V_4 = F_1 ( V_2 ) ;
if ( ! ( V_4 & V_8 ) )
return;
}
F_6 ( V_22 , & V_19 -> V_23 ) ;
F_7 ( V_19 ) ;
}
static int F_8 ( struct V_18 * V_19 )
{
struct V_16 * V_17 ;
F_9 ( L_1 , V_19 ) ;
V_17 = F_10 ( sizeof( * V_17 ) , V_24 ) ;
if ( ! V_17 )
return - V_25 ;
F_11 ( & V_17 -> V_26 ) ;
V_19 -> V_27 = V_17 ;
V_17 -> V_19 = V_19 ;
F_12 ( & V_17 -> V_20 , F_4 ) ;
return 0 ;
}
static int F_13 ( struct V_18 * V_19 )
{
struct V_16 * V_17 = V_19 -> V_27 ;
F_9 ( L_1 , V_19 ) ;
F_14 ( & V_17 -> V_26 ) ;
return 0 ;
}
static int F_15 ( struct V_18 * V_19 )
{
struct V_16 * V_17 = V_19 -> V_27 ;
F_9 ( L_1 , V_19 ) ;
F_14 ( & V_17 -> V_26 ) ;
F_16 ( & V_17 -> V_20 ) ;
V_19 -> V_27 = NULL ;
F_17 ( V_17 ) ;
return 0 ;
}
static int F_18 ( struct V_18 * V_19 , struct V_28 * V_29 )
{
struct V_16 * V_17 = V_19 -> V_27 ;
if ( F_19 ( V_29 ) -> V_30 == V_31 ) {
F_20 ( V_29 ) ;
return 0 ;
}
if ( F_19 ( V_29 ) -> V_30 == V_32 ) {
struct V_33 * V_34 = ( void * ) V_29 -> V_35 ;
if ( F_21 ( V_34 -> V_36 ) == V_37 )
V_17 -> V_21 = V_29 -> V_35 [ V_38 ] ;
}
F_9 ( L_2 , V_19 , V_29 ) ;
memcpy ( F_22 ( V_29 , 1 ) , & F_19 ( V_29 ) -> V_30 , 1 ) ;
F_23 ( & V_17 -> V_26 , V_29 ) ;
F_24 ( V_22 , & V_19 -> V_23 ) ;
F_25 ( & V_17 -> V_20 ) ;
return 0 ;
}
static struct V_28 * F_26 ( struct V_18 * V_19 )
{
struct V_16 * V_17 = V_19 -> V_27 ;
return F_27 ( & V_17 -> V_26 ) ;
}
static int F_28 ( struct V_18 * V_19 , void * V_35 , int V_39 )
{
int V_40 ;
V_40 = F_29 ( V_19 -> V_41 , V_35 , V_39 ) ;
if ( V_40 < 0 ) {
F_30 ( L_3 ) ;
return V_40 ;
}
return V_39 ;
}
int T_1 F_31 ( void )
{
int V_42 = F_32 ( & V_43 ) ;
if ( ! V_42 )
F_33 ( L_4 ) ;
else
F_30 ( L_5 ) ;
return V_42 ;
}
int T_2 F_34 ( void )
{
return F_35 ( & V_43 ) ;
}
