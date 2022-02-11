static void F_1 ( void T_1 * V_1 , T_2 V_2 , T_2 V_3 , T_2 V_4 )
{
T_2 V_5 ;
V_5 = F_2 ( V_1 + V_6 ) | V_7 ;
F_3 ( V_5 , V_1 + V_6 ) ;
V_5 = ( F_2 ( V_1 + V_8 ) & ~ ( V_3 | V_4 ) ) | V_2 ;
F_3 ( V_5 , V_1 + V_8 ) ;
F_3 ( V_5 | V_4 , V_1 + V_8 ) ;
F_4 ( 250 ) ;
F_3 ( V_5 , V_1 + V_8 ) ;
}
static unsigned int F_5 ( struct V_9 * V_10 )
{
unsigned int V_11 ;
T_2 V_2 ;
V_2 = F_2 ( V_10 -> V_1 + V_8 ) ;
V_2 >>= V_10 -> V_12 ;
V_11 = V_2 & ~ ( ~ 0 << V_10 -> V_13 ) ;
if ( V_10 -> V_14 )
V_11 = V_10 -> V_14 [ V_11 ] ;
return V_11 ;
}
static int F_6 ( const struct V_9 * V_10 , unsigned long V_15 ,
unsigned long V_16 , bool V_17 )
{
unsigned int V_11 , V_18 ;
V_11 = F_7 ( V_16 , V_15 ) ;
if ( V_10 -> V_14 ) {
unsigned int V_19 ;
for ( V_19 = 0 ; V_10 -> V_14 [ V_19 ] ; V_19 ++ )
if ( V_11 == V_10 -> V_14 [ V_19 ] ) {
V_11 = V_19 ;
break;
}
if ( ! V_10 -> V_14 [ V_19 ] )
return - V_20 ;
} else {
V_18 = 1 << V_10 -> V_13 ;
if ( V_17 && ( V_11 == 0 || V_11 >= V_18 ) )
return - V_20 ;
if ( V_11 >= V_18 )
V_11 = V_18 - 1 ;
else if ( V_11 == 0 )
V_11 = 1 ;
}
return V_11 ;
}
static unsigned long F_8 ( struct V_21 * V_22 , unsigned long V_23 )
{
struct V_9 * V_10 = F_9 ( V_22 ) ;
unsigned int V_11 = F_5 ( V_10 ) ;
unsigned long V_15 = F_7 ( V_23 , V_11 ) ;
F_10 ( L_1 ,
V_24 , V_10 -> V_25 , V_11 , V_23 , V_15 ) ;
return V_15 ;
}
static long F_11 ( struct V_21 * V_22 , unsigned long V_15 ,
unsigned long * V_23 )
{
struct V_9 * V_10 = F_9 ( V_22 ) ;
unsigned long V_16 = * V_23 ;
int V_11 ;
V_11 = F_6 ( V_10 , V_15 , V_16 , false ) ;
if ( V_11 < 0 )
return V_11 ;
V_15 = F_7 ( V_16 , V_11 ) ;
F_10 ( L_1 ,
V_24 , V_10 -> V_25 , V_11 , V_16 , V_15 ) ;
return V_15 ;
}
static int F_12 ( struct V_21 * V_22 , unsigned long V_15 ,
unsigned long V_16 )
{
struct V_9 * V_10 = F_9 ( V_22 ) ;
T_2 V_3 , V_4 , div ;
int V_11 ;
V_11 = F_6 ( V_10 , V_15 , V_16 , true ) ;
if ( V_11 < 0 )
return V_11 ;
F_10 ( L_1 ,
V_24 , V_10 -> V_25 , V_11 , V_16 , V_15 ) ;
div = ( T_2 ) V_11 << V_10 -> V_12 ;
V_3 = ~ ( ~ 0 << V_10 -> V_13 ) << V_10 -> V_12 ;
V_4 = F_13 ( V_10 -> V_26 ) ;
F_14 ( V_10 -> V_27 ) ;
F_1 ( V_10 -> V_1 , div , V_3 , V_4 ) ;
F_15 ( V_10 -> V_27 ) ;
return 0 ;
}
static struct V_28 * F_16 ( struct V_29 * V_30 ,
struct V_9 * V_10 , const char * * V_31 , T_3 V_32 ,
void T_1 * V_1 )
{
char V_25 [ 32 ] ;
struct V_33 V_34 = {
. V_25 = V_25 ,
. V_35 = & V_36 ,
. V_31 = V_31 ,
. V_32 = V_32 ,
} ;
F_17 ( V_25 , V_10 -> V_25 , sizeof( V_25 ) ) ;
V_10 -> V_22 . V_34 = & V_34 ;
V_10 -> V_1 = V_1 ;
V_10 -> V_13 = V_10 -> V_37 - V_10 -> V_12 + 1 ;
return F_18 ( V_30 , & V_10 -> V_22 ) ;
}
static int F_19 ( struct V_29 * V_30 , void T_1 * V_1 ,
struct V_28 * * V_38 )
{
struct V_28 * V_28 ;
int V_19 ;
V_28 = F_20 ( V_30 , V_39 [ 0 ] , NULL , 0 , 2000000000UL ) ;
if ( F_21 ( V_28 ) )
return F_22 ( V_28 ) ;
for ( V_19 = 0 ; V_19 < F_23 ( V_40 ) ; V_19 ++ )
V_38 [ V_19 ] = F_16 ( V_30 , & V_40 [ V_19 ] ,
V_39 ,
F_23 ( V_39 ) , V_1 ) ;
return 0 ;
}
void T_4 F_24 ( struct V_41 * V_42 )
{
void T_1 * V_1 ;
V_1 = F_25 ( V_42 , 0 ) ;
if ( F_26 ( ! V_1 ) )
return;
if ( F_26 ( F_19 ( NULL , V_1 , V_43 ) ) ) {
F_27 ( V_1 ) ;
return;
}
F_28 ( V_42 , V_44 , & V_45 ) ;
}
