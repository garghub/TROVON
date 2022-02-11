static T_1 T_2 F_1 ( void )
{
return F_2 ( V_1 ) ;
}
static T_3
F_3 ( int V_2 , void * V_3 )
{
struct V_4 * V_5 = V_3 ;
F_4 ( F_2 ( V_6 ) & ~ V_7 , V_6 ) ;
F_4 ( V_8 , V_9 ) ;
V_5 -> V_10 ( V_5 ) ;
return V_11 ;
}
static int
F_5 ( unsigned long V_12 , struct V_4 * V_13 )
{
unsigned long V_14 , V_15 ;
F_4 ( F_2 ( V_6 ) | V_7 , V_6 ) ;
V_14 = F_2 ( V_1 ) + V_12 ;
F_4 ( V_14 , V_16 ) ;
V_15 = F_2 ( V_1 ) ;
return ( signed ) ( V_14 - V_15 ) <= V_17 ? - V_18 : 0 ;
}
static void
F_6 ( enum V_19 V_20 , struct V_4 * V_13 )
{
switch ( V_20 ) {
case V_21 :
F_4 ( F_2 ( V_6 ) & ~ V_7 , V_6 ) ;
F_4 ( V_8 , V_9 ) ;
break;
case V_22 :
case V_23 :
F_4 ( F_2 ( V_6 ) & ~ V_7 , V_6 ) ;
F_4 ( V_8 , V_9 ) ;
break;
case V_24 :
case V_25 :
break;
}
}
static void F_7 ( struct V_4 * V_26 )
{
V_27 [ 0 ] = F_2 ( V_16 ) ;
V_27 [ 1 ] = F_2 ( V_28 ) ;
V_27 [ 2 ] = F_2 ( V_29 ) ;
V_27 [ 3 ] = F_2 ( V_30 ) ;
V_31 = F_2 ( V_6 ) ;
V_15 = F_2 ( V_1 ) ;
}
static void F_8 ( struct V_4 * V_26 )
{
if ( V_27 [ 0 ] - V_15 < V_17 )
V_27 [ 0 ] += V_17 ;
F_4 ( V_27 [ 0 ] , V_16 ) ;
F_4 ( V_27 [ 1 ] , V_28 ) ;
F_4 ( V_27 [ 2 ] , V_29 ) ;
F_4 ( V_27 [ 3 ] , V_30 ) ;
F_4 ( V_31 , V_6 ) ;
F_4 ( V_15 , V_1 ) ;
}
static void F_9 ( int V_2 , unsigned long V_32 )
{
F_4 ( 0 , V_6 ) ;
F_4 ( V_8 | V_33 | V_34 | V_35 , V_9 ) ;
F_10 ( F_1 , 32 , V_32 ) ;
V_36 . V_37 = F_11 ( 0 ) ;
F_12 ( V_2 , & V_38 ) ;
F_13 ( V_39 + V_1 , L_1 , V_32 , 200 ,
32 , V_40 ) ;
F_14 ( & V_36 , V_32 ,
V_17 * 2 , 0x7fffffff ) ;
}
static void T_4 F_15 ( struct V_41 * V_42 )
{
struct V_43 * V_43 ;
int V_2 ;
V_39 = F_16 ( V_42 , 0 ) ;
if ( ! V_39 )
F_17 ( L_2 , V_42 -> V_44 ) ;
V_43 = F_18 ( V_42 , 0 ) ;
if ( F_19 ( V_43 ) ) {
F_20 ( L_3 , V_42 -> V_44 ) ;
return;
}
F_21 ( V_43 ) ;
V_2 = F_22 ( V_42 , 0 ) ;
if ( V_2 <= 0 ) {
F_20 ( L_4 , V_42 -> V_44 ) ;
return;
}
F_9 ( V_2 , F_23 ( V_43 ) ) ;
}
void T_4 F_24 ( int V_2 , void T_5 * V_45 ,
unsigned long V_32 )
{
struct V_43 * V_43 ;
V_39 = V_45 ;
V_43 = F_25 ( NULL , L_5 ) ;
if ( V_43 && ! F_19 ( V_43 ) )
F_21 ( V_43 ) ;
else
F_20 ( L_3 , V_46 ) ;
F_9 ( V_2 , V_32 ) ;
}
