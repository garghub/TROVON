static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
return V_2 -> V_4 == V_3 ;
}
static struct V_1 *
F_2 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = NULL ;
V_2 = F_3 ( & V_7 , NULL ,
V_6 , F_1 ) ;
if ( V_2 )
return V_2 ;
return F_3 ( & V_8 , NULL ,
V_6 , F_1 ) ;
}
static struct V_5 * F_4 (
const struct V_5 * V_9 , struct V_5 * V_10 )
{
struct V_5 * V_11 = F_5 ( V_9 , V_10 ) ;
F_6 ( V_10 ) ;
return V_11 ;
}
static void F_7 ( struct V_5 * V_11 ,
int * V_12 , int * V_13 )
{
struct V_5 * V_14 = NULL ;
int V_15 = 0 , V_16 = 0 ;
do {
V_14 = F_4 ( V_11 , V_14 ) ;
if ( ! V_14 )
break;
if ( F_8 ( V_14 , L_1 ) )
V_15 ++ ;
else
V_16 ++ ;
} while ( V_14 );
* V_12 = V_15 ;
* V_13 = V_16 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_17 * V_18 )
{
V_18 -> V_19 = F_10 ( V_2 , V_18 -> V_13 *
sizeof( * V_18 -> V_19 ) ,
V_20 ) ;
if ( ! V_18 -> V_19 )
return - V_21 ;
V_18 -> V_22 = F_10 ( V_2 , V_18 -> V_13 *
sizeof( * V_18 -> V_22 ) ,
V_20 ) ;
if ( ! V_18 -> V_22 )
return - V_21 ;
V_18 -> V_23 = F_10 ( V_2 , V_18 -> V_13 *
sizeof( * V_18 -> V_23 ) ,
V_20 ) ;
if ( ! V_18 -> V_23 )
return - V_21 ;
return 0 ;
}
struct V_17 * F_11 (
struct V_1 * V_2 , struct V_5 * V_11 )
{
int V_24 = 0 , V_25 = 0 ;
struct V_17 * V_18 ;
struct V_26 V_6 , V_27 ;
struct V_1 * V_28 ;
struct V_5 * V_29 ;
struct V_5 * V_14 = NULL ;
struct V_5 * V_30 = NULL ;
struct V_5 * V_31 = NULL ;
V_18 = F_10 ( V_2 , sizeof( * V_18 ) , V_20 ) ;
if ( ! V_18 )
return F_12 ( - V_21 ) ;
V_18 -> V_32 = F_13 ( V_2 ) ;
F_7 ( V_11 , & V_18 -> V_12 , & V_18 -> V_13 ) ;
if ( V_18 -> V_13 ) {
V_25 = F_9 ( V_2 , V_18 ) ;
if ( V_25 )
return F_12 ( V_25 ) ;
do {
V_14 = F_4 ( V_11 , V_14 ) ;
if ( ! V_14 )
break;
if ( F_14 ( V_14 , L_1 , NULL ) )
continue;
V_25 = F_15 ( V_14 , & V_6 ) ;
if ( V_25 )
continue;
V_18 -> V_19 [ V_24 ] = V_6 . V_33 ;
V_30 = F_16 ( V_14 ) ;
V_31 = F_17 ( V_14 ) ;
if ( ! V_30 || ! V_31 )
continue;
if ( F_15 ( V_31 , & V_27 ) )
continue;
V_28 = F_2 ( V_30 ) ;
if ( ! V_28 )
continue;
V_18 -> V_22 [ V_24 ] = F_13 ( V_28 ) ;
V_18 -> V_23 [ V_24 ] = V_27 . V_33 ;
V_24 ++ ;
} while ( V_14 );
}
V_18 -> V_34 = 0 ;
V_29 = F_18 ( V_11 , L_2 , 0 ) ;
if ( V_29 ) {
const T_1 * V_35 ;
int V_36 , V_37 ;
T_2 V_38 ;
V_35 = F_19 ( V_29 , L_3 , & V_36 ) ;
if ( V_35 ) {
V_38 = F_20 ( V_35 , F_21 ( V_29 ) ) ;
V_37 = F_22 ( V_38 ) ;
if ( V_37 != - V_39 )
V_18 -> V_34 = V_37 ;
}
}
return V_18 ;
}
