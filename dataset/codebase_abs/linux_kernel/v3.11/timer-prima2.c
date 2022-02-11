static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
F_2 ( ! ( F_3 ( V_5 + V_6 ) & F_4 ( 0 ) ) ) ;
F_5 ( F_4 ( 0 ) , V_5 + V_6 ) ;
V_4 -> V_7 ( V_4 ) ;
return V_8 ;
}
static T_2 F_6 ( struct V_9 * V_10 )
{
T_3 V_11 ;
F_5 ( V_12 , V_5 + V_13 ) ;
V_11 = F_3 ( V_5 + V_14 ) ;
V_11 = ( V_11 << 32 ) | F_3 ( V_5 + V_15 ) ;
return V_11 ;
}
static int F_7 ( unsigned long V_16 ,
struct V_3 * V_4 )
{
unsigned long V_17 , V_18 ;
F_5 ( V_12 , V_5 + V_13 ) ;
V_17 = F_3 ( V_5 + V_15 ) ;
V_18 = V_17 + V_16 ;
F_5 ( V_18 , V_5 + V_19 ) ;
F_5 ( V_12 , V_5 + V_13 ) ;
V_17 = F_3 ( V_5 + V_15 ) ;
return V_18 - V_17 > V_16 ? - V_20 : 0 ;
}
static void F_8 ( enum V_21 V_22 ,
struct V_3 * V_4 )
{
T_4 V_23 = F_3 ( V_5 + V_24 ) ;
switch ( V_22 ) {
case V_25 :
F_2 ( 1 ) ;
break;
case V_26 :
F_5 ( V_23 | F_4 ( 0 ) , V_5 + V_24 ) ;
break;
case V_27 :
F_5 ( V_23 & ~ F_4 ( 0 ) , V_5 + V_24 ) ;
break;
case V_28 :
case V_29 :
break;
}
}
static void F_9 ( struct V_9 * V_10 )
{
int V_30 ;
F_5 ( V_12 , V_5 + V_13 ) ;
for ( V_30 = 0 ; V_30 < V_31 ; V_30 ++ )
V_32 [ V_30 ] = F_3 ( V_5 + V_33 [ V_30 ] ) ;
}
static void F_10 ( struct V_9 * V_10 )
{
int V_30 ;
for ( V_30 = 0 ; V_30 < V_31 - 2 ; V_30 ++ )
F_5 ( V_32 [ V_30 ] , V_5 + V_33 [ V_30 ] ) ;
F_5 ( V_32 [ V_31 - 2 ] , V_5 + V_34 ) ;
F_5 ( V_32 [ V_31 - 1 ] , V_5 + V_35 ) ;
}
static T_4 T_5 F_11 ( void )
{
return ( T_4 ) ( F_6 ( NULL ) & 0xffffffff ) ;
}
static void T_6 F_12 ( void )
{
V_36 . V_37 = F_13 ( 0 ) ;
F_14 ( & V_36 , V_38 ,
2 , - 2 ) ;
}
static void T_6 F_15 ( struct V_39 * V_40 )
{
unsigned long V_41 ;
struct V_42 * V_42 ;
V_42 = F_16 ( L_1 , NULL ) ;
F_17 ( F_18 ( V_42 ) ) ;
V_41 = F_19 ( V_42 ) ;
F_17 ( V_41 < V_38 ) ;
F_17 ( V_41 % V_38 ) ;
V_5 = F_20 ( V_40 , 0 ) ;
if ( ! V_5 )
F_21 ( L_2 ) ;
V_43 . V_1 = F_22 ( V_40 , 0 ) ;
F_5 ( V_41 / V_38 / 2 - 1 , V_5 + V_44 ) ;
F_5 ( 0 , V_5 + V_34 ) ;
F_5 ( 0 , V_5 + V_35 ) ;
F_5 ( F_4 ( 0 ) , V_5 + V_6 ) ;
F_17 ( F_23 ( & V_45 , V_38 ) ) ;
F_24 ( F_11 , 32 , V_38 ) ;
F_17 ( F_25 ( V_43 . V_1 , & V_43 ) ) ;
F_12 () ;
}
