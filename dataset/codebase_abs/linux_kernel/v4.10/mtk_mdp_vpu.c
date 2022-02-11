static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static void F_3 ( struct V_4 * V_5 )
{
struct V_2 * V_3 = (struct V_2 * )
( unsigned long ) V_5 -> V_6 ;
V_3 -> V_7 = (struct V_8 * )
F_4 ( V_3 -> V_9 , V_5 -> V_10 ) ;
V_3 -> V_11 = V_5 -> V_10 ;
}
static void F_5 ( void * V_12 , unsigned int V_13 , void * V_14 )
{
unsigned int V_15 = * ( unsigned int * ) V_12 ;
struct V_4 * V_5 = (struct V_4 * ) V_12 ;
struct V_2 * V_3 = (struct V_2 * )
( unsigned long ) V_5 -> V_6 ;
struct V_1 * V_16 ;
V_3 -> V_17 = V_5 -> V_18 ;
if ( ! V_3 -> V_17 ) {
switch ( V_15 ) {
case V_19 :
F_3 ( V_12 ) ;
break;
case V_20 :
case V_21 :
break;
default:
V_16 = F_1 ( V_3 ) ;
F_6 ( & V_16 -> V_22 -> V_9 -> V_23 ,
L_1 ,
V_15 ) ;
break;
}
} else {
V_16 = F_1 ( V_3 ) ;
F_7 ( 0 , L_2 , V_16 -> V_24 ,
V_15 , V_3 -> V_17 ) ;
}
}
int F_8 ( struct V_25 * V_9 )
{
struct V_26 * V_27 = F_9 ( V_9 ) ;
int V_28 ;
V_28 = F_10 ( V_27 -> V_29 , V_30 ,
F_5 , L_3 , NULL ) ;
if ( V_28 )
F_6 ( & V_27 -> V_9 -> V_23 ,
L_4 , V_28 ) ;
return V_28 ;
}
static int F_11 ( void * V_5 , int V_13 , struct V_2 * V_3 ,
int V_24 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
int V_28 ;
if ( ! V_3 -> V_9 ) {
F_7 ( 1 , L_5 , V_16 -> V_24 ) ;
return - V_31 ;
}
F_12 ( & V_16 -> V_22 -> V_32 ) ;
V_28 = F_13 ( V_3 -> V_9 , (enum V_33 ) V_24 , V_5 , V_13 ) ;
if ( V_28 )
F_6 ( & V_16 -> V_22 -> V_9 -> V_23 ,
L_6 , V_28 ) ;
F_14 ( & V_16 -> V_22 -> V_32 ) ;
return V_28 ;
}
static int F_15 ( struct V_2 * V_3 , T_1 V_15 )
{
int V_28 ;
struct V_34 V_5 ;
V_5 . V_15 = V_15 ;
V_5 . V_33 = V_30 ;
V_5 . V_10 = V_3 -> V_11 ;
V_5 . V_6 = ( unsigned long ) V_3 ;
V_28 = F_11 ( ( void * ) & V_5 , sizeof( V_5 ) , V_3 , V_30 ) ;
if ( ! V_28 && V_3 -> V_17 )
V_28 = - V_31 ;
return V_28 ;
}
int F_16 ( struct V_2 * V_3 )
{
int V_28 ;
struct V_35 V_5 ;
struct V_1 * V_16 = F_1 ( V_3 ) ;
V_3 -> V_9 = V_16 -> V_22 -> V_29 ;
V_5 . V_15 = V_36 ;
V_5 . V_33 = V_30 ;
V_5 . V_6 = ( unsigned long ) V_3 ;
V_28 = F_11 ( ( void * ) & V_5 , sizeof( V_5 ) , V_3 , V_30 ) ;
if ( ! V_28 && V_3 -> V_17 )
V_28 = - V_31 ;
return V_28 ;
}
int F_17 ( struct V_2 * V_3 )
{
return F_15 ( V_3 , V_37 ) ;
}
int F_18 ( struct V_2 * V_3 )
{
return F_15 ( V_3 , V_38 ) ;
}
