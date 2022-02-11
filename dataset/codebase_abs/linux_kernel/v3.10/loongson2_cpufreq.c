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
V_16 = V_20 -> V_16 ;
F_5 ( V_20 , F_6 ( V_9 ) ) ;
if ( F_7
( V_12 , & V_21 [ 0 ] , V_13 , V_14 ,
& V_15 ) )
return - V_22 ;
V_19 =
( ( V_23 / 1000 ) *
V_21 [ V_15 ] . V_24 ) / 8 ;
if ( V_19 < V_12 -> V_25 || V_19 > V_12 -> V_26 )
return - V_22 ;
F_8 ( L_1 , V_13 * 1000 ) ;
V_18 . V_27 = F_2 ( V_9 ) ;
V_18 . V_28 = V_19 ;
V_18 . V_29 = 0 ;
if ( V_18 . V_28 == V_18 . V_27 )
return 0 ;
F_9 ( V_12 , & V_18 , V_30 ) ;
F_5 ( V_20 , & V_16 ) ;
F_10 ( V_10 , V_19 ) ;
F_9 ( V_12 , & V_18 , V_5 ) ;
F_8 ( L_2 , V_19 ) ;
return 0 ;
}
static int F_11 ( struct V_11 * V_12 )
{
int V_31 ;
unsigned long V_32 ;
int V_33 ;
V_10 = F_12 ( NULL , L_3 ) ;
if ( F_13 ( V_10 ) ) {
F_14 ( V_34 L_4 ) ;
return F_15 ( V_10 ) ;
}
V_32 = V_23 / 1000 ;
if ( ! V_32 ) {
F_16 ( V_10 ) ;
return - V_22 ;
}
V_33 = F_10 ( V_10 , V_32 ) ;
if ( V_33 ) {
F_16 ( V_10 ) ;
return V_33 ;
}
for ( V_31 = 2 ;
( V_21 [ V_31 ] . V_35 != V_36 ) ;
V_31 ++ )
V_21 [ V_31 ] . V_35 = ( V_32 * V_31 ) / 8 ;
V_12 -> V_37 = F_2 ( V_12 -> V_9 ) ;
F_17 ( & V_21 [ 0 ] ,
V_12 -> V_9 ) ;
return F_18 ( V_12 ,
& V_21 [ 0 ] ) ;
}
static int F_19 ( struct V_11 * V_12 )
{
return F_20 ( V_12 ,
& V_21 [ 0 ] ) ;
}
static int F_21 ( struct V_11 * V_12 )
{
F_16 ( V_10 ) ;
return 0 ;
}
static void F_22 ( void )
{
unsigned long V_29 ;
T_2 V_38 ;
F_23 ( & V_39 , V_29 ) ;
V_38 = V_40 ;
V_40 &= ~ 0x7 ;
V_40 = V_38 ;
F_24 ( & V_39 , V_29 ) ;
F_25 () ;
}
static int T_3 F_26 ( void )
{
int V_33 ;
V_33 = F_27 ( & V_41 ) ;
if ( V_33 )
return V_33 ;
F_28 ( L_5 ) ;
F_29 ( & V_42 ,
V_43 ) ;
V_33 = F_30 ( & V_44 ) ;
if ( ! V_33 && ! V_45 ) {
V_46 = V_47 ;
V_47 = F_22 ;
}
return V_33 ;
}
static void T_4 F_31 ( void )
{
if ( ! V_45 && V_46 )
V_47 = V_46 ;
F_32 ( & V_44 ) ;
F_33 ( & V_42 ,
V_43 ) ;
F_34 ( & V_41 ) ;
}
