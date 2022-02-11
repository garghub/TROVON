static int F_1 ( struct V_1 * V_2 , void * V_3 , T_1 V_4 , bool V_5 )
{
struct V_6 * V_7 =
F_2 ( V_2 , struct V_6 , V_2 ) ;
T_2 V_8 ;
int V_9 = 0 ;
F_3 ( (struct V_10 * ) V_7 -> V_2 . V_7 ) ;
while ( V_4 > sizeof( T_2 ) ) {
V_8 = F_4 ( V_7 -> V_11 + V_12 ) ;
if ( ! V_8 && V_5 ) {
unsigned int V_13 = V_14 ;
do {
F_5 () ;
V_8 = F_4 ( V_7 -> V_11 + V_12 ) ;
} while ( ! V_8 && -- V_13 );
}
if ( V_8 != V_15 ) {
if ( F_6 ( V_8 & ( V_16 | V_17 ) ,
L_1 , V_8 ) )
F_7 ( 0 , V_7 -> V_11 + V_12 ) ;
break;
}
* ( T_2 * ) V_3 = F_4 ( V_7 -> V_11 + V_18 ) ;
V_9 += sizeof( T_2 ) ;
V_3 += sizeof( T_2 ) ;
V_4 -= sizeof( T_2 ) ;
}
F_8 ( (struct V_10 * ) V_7 -> V_2 . V_7 ) ;
F_9 ( (struct V_10 * ) V_7 -> V_2 . V_7 ) ;
return V_9 || ! V_5 ? V_9 : - V_19 ;
}
static int F_10 ( struct V_1 * V_2 )
{
struct V_6 * V_7 =
F_2 ( V_2 , struct V_6 , V_2 ) ;
int V_20 ;
V_20 = F_11 ( V_7 -> V_21 ) ;
if ( V_20 )
return V_20 ;
F_7 ( V_22 , V_7 -> V_11 + V_23 ) ;
F_7 ( 0 , V_7 -> V_11 + V_12 ) ;
return 0 ;
}
static void F_12 ( struct V_1 * V_2 )
{
struct V_6 * V_7 =
F_2 ( V_2 , struct V_6 , V_2 ) ;
F_7 ( 0 , V_7 -> V_11 + V_23 ) ;
F_13 ( V_7 -> V_21 ) ;
}
static int F_14 ( struct V_24 * V_25 )
{
struct V_10 * V_26 = & V_25 -> V_26 ;
struct V_27 * V_28 = V_25 -> V_26 . V_29 ;
struct V_6 * V_7 ;
struct V_30 V_31 ;
int V_20 ;
V_7 = F_15 ( V_26 , sizeof( struct V_6 ) , V_32 ) ;
if ( ! V_7 )
return - V_33 ;
V_20 = F_16 ( V_28 , 0 , & V_31 ) ;
if ( V_20 )
return V_20 ;
V_7 -> V_11 = F_17 ( V_26 , & V_31 ) ;
if ( F_18 ( V_7 -> V_11 ) )
return F_19 ( V_7 -> V_11 ) ;
V_7 -> V_21 = F_20 ( & V_25 -> V_26 , NULL ) ;
if ( F_18 ( V_7 -> V_21 ) )
return F_19 ( V_7 -> V_21 ) ;
F_21 ( V_26 , V_7 ) ;
V_7 -> V_2 . V_34 = F_22 ( V_26 ) ,
#ifndef F_23
V_7 -> V_2 . V_35 = F_10 ,
V_7 -> V_2 . V_36 = F_12 ,
#endif
V_7 -> V_2 . V_37 = F_1 ,
V_7 -> V_2 . V_7 = ( unsigned long ) V_26 ;
F_24 ( V_26 , 100 ) ;
F_25 ( V_26 ) ;
F_26 ( V_26 ) ;
return F_27 ( V_26 , & V_7 -> V_2 ) ;
}
static int F_28 ( struct V_10 * V_26 )
{
struct V_6 * V_7 = F_29 ( V_26 ) ;
F_12 ( & V_7 -> V_2 ) ;
return 0 ;
}
static int F_30 ( struct V_10 * V_26 )
{
struct V_6 * V_7 = F_29 ( V_26 ) ;
return F_10 ( & V_7 -> V_2 ) ;
}
