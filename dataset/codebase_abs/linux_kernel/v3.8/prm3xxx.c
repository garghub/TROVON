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
if ( F_20 () )
F_10 ( V_27 , V_22 ,
V_23 ) ;
}
static T_1 F_21 ( void )
{
struct V_28 * V_29 ;
T_1 V_30 = 0 ;
T_1 V_31 ;
V_31 = F_2 ( V_22 , V_32 ) ;
V_29 = V_33 ;
while ( V_29 -> V_34 >= 0 && V_29 -> V_35 >= 0 ) {
if ( V_31 & ( 1 << V_29 -> V_34 ) )
V_30 |= 1 << V_29 -> V_35 ;
V_29 ++ ;
}
return V_30 ;
}
static int F_22 ( struct V_36 * V_37 , T_2 V_38 )
{
F_8 ( V_39 ,
( V_38 << V_40 ) ,
V_37 -> V_41 , V_42 ) ;
return 0 ;
}
static int F_23 ( struct V_36 * V_37 )
{
return F_24 ( V_37 -> V_41 ,
V_42 ,
V_39 ) ;
}
static int F_25 ( struct V_36 * V_37 )
{
return F_24 ( V_37 -> V_41 ,
V_43 ,
V_44 ) ;
}
static int F_26 ( struct V_36 * V_37 )
{
return F_24 ( V_37 -> V_41 ,
V_45 ,
V_46 ) ;
}
static int F_27 ( struct V_36 * V_37 )
{
return F_24 ( V_37 -> V_41 ,
V_43 ,
V_47 ) ;
}
static int F_28 ( struct V_36 * V_37 )
{
return F_24 ( V_37 -> V_41 ,
V_42 ,
V_47 ) ;
}
static int F_29 ( struct V_36 * V_37 )
{
return F_24 ( V_37 -> V_41 ,
V_45 ,
V_48 ) ;
}
static int F_30 ( T_2 V_49 )
{
switch ( V_49 ) {
case 0 :
return V_50 ;
case 1 :
return V_51 ;
case 2 :
return V_52 ;
case 3 :
return V_53 ;
default:
F_31 ( 1 ) ;
return - V_54 ;
}
return 0 ;
}
static int F_32 ( struct V_36 * V_37 , T_2 V_49 )
{
T_1 V_55 ;
V_55 = F_30 ( V_49 ) ;
return F_24 ( V_37 -> V_41 ,
V_45 , V_55 ) ;
}
static int F_33 ( struct V_36 * V_37 )
{
F_4 ( 0 , V_37 -> V_41 , V_45 ) ;
return 0 ;
}
static int F_34 ( struct V_36 * V_37 )
{
return F_8 ( 0 ,
1 << V_56 ,
V_37 -> V_41 , V_42 ) ;
}
static int F_35 ( struct V_36 * V_37 )
{
return F_8 ( 1 << V_56 ,
0 , V_37 -> V_41 ,
V_42 ) ;
}
int T_3 F_36 ( void )
{
if ( ! F_37 () )
return 0 ;
return F_38 ( & V_57 ) ;
}
static int T_3 F_39 ( void )
{
int V_58 ;
if ( ! F_37 () )
return 0 ;
F_19 () ;
V_58 = F_40 ( & V_59 ) ;
if ( ! V_58 )
F_41 ( F_42 ( L_2 ) ,
V_60 ) ;
return V_58 ;
}
static void T_4 F_43 ( void )
{
if ( ! F_37 () )
return;
F_44 ( F_45 ( & V_57 ) ,
L_3 , V_61 ) ;
}
