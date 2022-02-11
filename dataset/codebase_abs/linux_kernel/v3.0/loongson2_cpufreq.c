static int F_1 ( struct V_1 * V_2 ,
unsigned long V_3 , void * V_4 )
{
if ( V_3 == V_5 )
V_6 . V_7 = V_8 ;
return 0 ;
}
static unsigned int F_2 ( unsigned int V_9 )
{
return F_3 ( V_10 ) ;
}
static int F_4 ( struct V_11 * V_12 ,
unsigned int V_13 ,
unsigned int V_14 )
{
unsigned int V_9 = V_12 -> V_9 ;
unsigned int V_15 = 0 ;
T_1 V_16 ;
struct V_17 V_18 ;
unsigned int V_19 ;
if ( ! F_5 ( V_9 ) )
return - V_20 ;
V_16 = V_21 -> V_16 ;
F_6 ( V_21 , F_7 ( V_9 ) ) ;
if ( F_8
( V_12 , & V_22 [ 0 ] , V_13 , V_14 ,
& V_15 ) )
return - V_23 ;
V_19 =
( ( V_24 / 1000 ) *
V_22 [ V_15 ] . V_25 ) / 8 ;
if ( V_19 < V_12 -> V_26 || V_19 > V_12 -> V_27 )
return - V_23 ;
F_9 ( L_1 , V_13 * 1000 ) ;
V_18 . V_9 = V_9 ;
V_18 . V_28 = F_2 ( V_9 ) ;
V_18 . V_29 = V_19 ;
V_18 . V_30 = 0 ;
if ( V_18 . V_29 == V_18 . V_28 )
return 0 ;
F_10 ( & V_18 , V_31 ) ;
F_6 ( V_21 , & V_16 ) ;
F_11 ( V_10 , V_19 ) ;
F_10 ( & V_18 , V_5 ) ;
F_9 ( L_2 , V_19 ) ;
return 0 ;
}
static int F_12 ( struct V_11 * V_12 )
{
int V_32 ;
if ( ! F_5 ( V_12 -> V_9 ) )
return - V_20 ;
V_10 = F_13 ( NULL , L_3 ) ;
if ( F_14 ( V_10 ) ) {
F_15 ( V_33 L_4 ) ;
return F_16 ( V_10 ) ;
}
V_10 -> V_34 = V_24 / 1000 ;
if ( ! V_10 -> V_34 )
return - V_23 ;
for ( V_32 = 2 ;
( V_22 [ V_32 ] . V_35 != V_36 ) ;
V_32 ++ )
V_22 [ V_32 ] . V_35 = ( V_10 -> V_34 * V_32 ) / 8 ;
V_12 -> V_37 = F_2 ( V_12 -> V_9 ) ;
F_17 ( & V_22 [ 0 ] ,
V_12 -> V_9 ) ;
return F_18 ( V_12 ,
& V_22 [ 0 ] ) ;
}
static int F_19 ( struct V_11 * V_12 )
{
return F_20 ( V_12 ,
& V_22 [ 0 ] ) ;
}
static int F_21 ( struct V_11 * V_12 )
{
F_22 ( V_10 ) ;
return 0 ;
}
static int T_2 F_23 ( void )
{
int V_38 ;
V_38 = F_24 ( & V_39 ) ;
if ( V_38 )
return V_38 ;
F_25 ( L_5 ) ;
F_26 ( & V_40 ,
V_41 ) ;
V_38 = F_27 ( & V_42 ) ;
if ( ! V_38 && ! V_43 ) {
V_44 = V_45 ;
V_45 = V_46 ;
}
return V_38 ;
}
static void T_3 F_28 ( void )
{
if ( ! V_43 && V_44 )
V_45 = V_44 ;
F_29 ( & V_42 ) ;
F_30 ( & V_40 ,
V_41 ) ;
F_31 ( & V_39 ) ;
}
