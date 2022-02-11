static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_5 ;
if ( ! ( F_2 ( V_4 , V_6 ) ) ) {
F_3 ( V_2 -> V_7 , L_1 ) ;
return 0 ;
}
V_5 = F_4 ( * ( V_8 * ) & V_4 -> V_9 [ V_4 -> V_5 - 2 ] ) ;
F_5 ( V_4 , V_5 ) ;
return 1 ;
}
static struct V_3 * F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_1 V_10 )
{
int V_11 = V_4 -> V_5 ;
int V_12 = V_11 + V_6 ;
int V_13 = F_7 ( V_4 ) ;
int V_14 = F_8 ( V_4 ) ;
int V_15 = 0 ;
V_8 * V_5 ;
if ( ( V_12 ) < V_2 -> V_16 )
V_15 = V_2 -> V_16 - V_12 + 1 ;
else if ( ! ( V_12 % V_2 -> V_16 ) )
V_15 = 1 ;
if ( ! F_9 ( V_4 ) &&
( V_13 + V_14 >= V_15 + V_6 ) ) {
if ( V_13 < V_6 || V_14 < V_15 ) {
V_4 -> V_9 = memmove ( V_4 -> V_17 + V_6 ,
V_4 -> V_9 , V_4 -> V_5 ) ;
F_10 ( V_4 , V_4 -> V_5 ) ;
}
} else {
struct V_3 * V_18 ;
V_18 = F_11 ( V_4 ,
V_6 ,
V_15 ,
V_10 ) ;
F_12 ( V_4 ) ;
if ( ! V_18 )
return NULL ;
V_4 = V_18 ;
}
V_11 += V_15 ;
V_11 &= 0x07ff ;
V_5 = ( V_8 * ) F_13 ( V_4 , V_6 ) ;
* V_5 = F_14 ( V_11 ) ;
if( V_15 )
memset ( F_15 ( V_4 , V_15 ) , 0 , V_15 ) ;
return V_4 ;
}
static void F_16 ( struct V_19 * V_19 )
{
struct V_20 * V_21 = (struct V_20 * ) V_19 -> V_22 ;
int V_23 = V_19 -> V_23 ;
if ( V_23 < 0 )
F_17 ( & V_19 -> V_2 -> V_2 , L_2 , V_23 ) ;
F_18 ( V_21 ) ;
F_19 ( V_19 ) ;
}
static void F_20 ( struct V_24 * V_25 )
{
struct V_20 * V_21 ;
int V_23 ;
struct V_19 * V_19 ;
struct V_1 * V_2 = F_21 ( V_25 ) ;
T_2 V_26 = V_27 | V_28 ;
if ( V_25 -> V_10 & V_29 ) {
V_26 |= V_30 ;
F_22 ( V_2 -> V_7 , L_3 ) ;
} else if ( ! F_23 ( V_25 ) ||
( V_25 -> V_10 & V_31 ) ) {
V_26 |= V_32 ;
F_24 ( V_2 -> V_7 , L_4 ) ;
} else {
F_24 ( V_2 -> V_7 , L_5 ) ;
}
V_19 = F_25 ( 0 , V_33 ) ;
if ( ! V_19 ) {
F_26 ( V_2 -> V_7 , L_6 ) ;
return;
}
V_21 = F_27 ( sizeof( * V_21 ) , V_33 ) ;
if ( ! V_21 ) {
F_26 ( V_2 -> V_7 , L_7 ) ;
goto V_34;
}
V_21 -> V_35 = V_36 | V_37 | V_38 ;
V_21 -> V_39 = V_40 ;
V_21 -> V_41 = F_14 ( V_26 ) ;
V_21 -> V_42 = 0 ;
V_21 -> V_43 = 0 ;
F_28 ( V_19 , V_2 -> V_44 , F_29 ( V_2 -> V_44 , 0 ) ,
( void * ) V_21 , NULL , 0 ,
F_16 ,
( void * ) V_21 ) ;
V_23 = F_30 ( V_19 , V_33 ) ;
if ( V_23 < 0 ) {
F_26 ( V_2 -> V_7 , L_8 ,
V_23 ) ;
goto V_45;
}
return;
V_45:
F_18 ( V_21 ) ;
V_34:
F_19 ( V_19 ) ;
}
static int F_31 ( struct V_1 * V_2 , struct V_46 * V_47 )
{
int V_23 = F_32 ( V_2 , 3 ) ;
if ( V_23 )
return V_23 ;
V_2 -> V_7 -> V_48 += V_6 ;
V_2 -> V_49 = V_2 -> V_7 -> V_50 + V_2 -> V_7 -> V_48 ;
V_2 -> V_7 -> V_51 = & V_52 ;
return F_33 ( V_2 , V_47 ) ;
}
