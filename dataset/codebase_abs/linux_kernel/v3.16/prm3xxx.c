T_1 F_1 ( T_2 V_1 )
{
struct V_2 * V_3 = & V_2 [ V_1 ] ;
T_1 V_4 ;
V_4 = F_2 ( V_5 ,
V_6 ) ;
return V_4 & V_3 -> V_7 ;
}
void F_3 ( T_2 V_1 )
{
struct V_2 * V_3 = & V_2 [ V_1 ] ;
F_4 ( V_3 -> V_7 ,
V_5 , V_6 ) ;
}
T_1 F_5 ( T_2 V_8 )
{
return F_2 ( V_9 , V_8 ) ;
}
void F_6 ( T_1 V_10 , T_2 V_8 )
{
F_4 ( V_10 , V_9 , V_8 ) ;
}
T_1 F_7 ( T_1 V_11 , T_1 V_12 , T_2 V_8 )
{
return F_8 ( V_11 , V_12 , V_9 , V_8 ) ;
}
void F_9 ( void )
{
F_10 ( V_13 , V_9 ,
V_14 ) ;
F_2 ( V_9 , V_14 ) ;
}
void F_11 ( unsigned long * V_15 )
{
T_1 V_11 , V_16 ;
V_11 = F_2 ( V_5 , V_17 ) ;
V_16 = F_2 ( V_5 , V_6 ) ;
V_15 [ 0 ] = V_11 & V_16 ;
}
void F_12 ( void )
{
F_2 ( V_5 , V_18 ) ;
}
void F_13 ( T_1 * V_19 )
{
V_19 [ 0 ] = F_2 ( V_5 ,
V_17 ) ;
F_4 ( 0 , V_5 , V_17 ) ;
F_2 ( V_5 , V_18 ) ;
}
void F_14 ( T_1 * V_19 )
{
F_4 ( V_19 [ 0 ] , V_5 ,
V_17 ) ;
}
void F_15 ( void )
{
int V_20 = 0 ;
F_10 ( V_21 , V_22 ,
V_23 ) ;
F_16 ( F_2 ( V_22 , V_24 ) &
V_25 ,
V_26 , V_20 ) ;
if ( V_20 == V_26 )
F_17 ( L_1 ) ;
F_18 ( V_21 , V_22 ,
V_23 ) ;
F_10 ( V_25 , V_22 ,
V_24 ) ;
F_2 ( V_22 , V_24 ) ;
}
static void T_3 F_19 ( void )
{
if ( V_27 & V_28 )
F_10 ( V_29 , V_22 ,
V_23 ) ;
}
static T_1 F_20 ( void )
{
struct V_30 * V_31 ;
T_1 V_32 = 0 ;
T_1 V_33 ;
V_33 = F_2 ( V_22 , V_34 ) ;
V_31 = V_35 ;
while ( V_31 -> V_36 >= 0 && V_31 -> V_37 >= 0 ) {
if ( V_33 & ( 1 << V_31 -> V_36 ) )
V_32 |= 1 << V_31 -> V_37 ;
V_31 ++ ;
}
return V_32 ;
}
static int F_21 ( struct V_38 * V_39 , T_2 V_40 )
{
F_8 ( V_41 ,
( V_40 << V_42 ) ,
V_39 -> V_43 , V_44 ) ;
return 0 ;
}
static int F_22 ( struct V_38 * V_39 )
{
return F_23 ( V_39 -> V_43 ,
V_44 ,
V_41 ) ;
}
static int F_24 ( struct V_38 * V_39 )
{
return F_23 ( V_39 -> V_43 ,
V_45 ,
V_46 ) ;
}
static int F_25 ( struct V_38 * V_39 )
{
return F_23 ( V_39 -> V_43 ,
V_47 ,
V_48 ) ;
}
static int F_26 ( struct V_38 * V_39 )
{
return F_23 ( V_39 -> V_43 ,
V_45 ,
V_49 ) ;
}
static int F_27 ( struct V_38 * V_39 )
{
return F_23 ( V_39 -> V_43 ,
V_44 ,
V_49 ) ;
}
static int F_28 ( struct V_38 * V_39 )
{
return F_23 ( V_39 -> V_43 ,
V_47 ,
V_50 ) ;
}
static int F_29 ( T_2 V_51 )
{
switch ( V_51 ) {
case 0 :
return V_52 ;
case 1 :
return V_53 ;
case 2 :
return V_54 ;
case 3 :
return V_55 ;
default:
F_30 ( 1 ) ;
return - V_56 ;
}
return 0 ;
}
static int F_31 ( struct V_38 * V_39 , T_2 V_51 )
{
T_1 V_57 ;
V_57 = F_29 ( V_51 ) ;
return F_23 ( V_39 -> V_43 ,
V_47 , V_57 ) ;
}
static int F_32 ( struct V_38 * V_39 )
{
F_4 ( 0 , V_39 -> V_43 , V_47 ) ;
return 0 ;
}
static int F_33 ( struct V_38 * V_39 )
{
return F_8 ( 0 ,
1 << V_58 ,
V_39 -> V_43 , V_44 ) ;
}
static int F_34 ( struct V_38 * V_39 )
{
return F_8 ( 1 << V_58 ,
0 , V_39 -> V_43 ,
V_44 ) ;
}
int T_3 F_35 ( void )
{
if ( F_36 () )
V_27 |= V_28 ;
return F_37 ( & V_59 ) ;
}
static int F_38 ( void )
{
int V_60 ;
if ( ! ( V_27 & V_28 ) )
return 0 ;
F_19 () ;
V_60 = F_39 ( & V_61 ) ;
if ( ! V_60 )
F_40 ( F_41 ( L_2 ) ,
V_62 ) ;
return V_60 ;
}
static void T_4 F_42 ( void )
{
F_43 ( & V_59 ) ;
}
