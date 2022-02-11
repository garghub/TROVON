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
static void F_4 ( struct V_5 * V_9 ,
int * V_10 , int * V_11 )
{
struct V_5 * V_12 = NULL ;
int V_13 = 0 , V_14 = 0 ;
do {
V_12 = F_5 ( V_9 , V_12 ) ;
if ( ! V_12 )
break;
if ( F_6 ( V_12 , L_1 ) )
V_13 ++ ;
else
V_14 ++ ;
} while ( V_12 );
* V_10 = V_13 ;
* V_11 = V_14 ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_15 * V_16 )
{
V_16 -> V_17 = F_8 ( V_2 , V_16 -> V_11 *
sizeof( * V_16 -> V_17 ) ,
V_18 ) ;
if ( ! V_16 -> V_17 )
return - V_19 ;
V_16 -> V_20 = F_8 ( V_2 , V_16 -> V_11 *
sizeof( * V_16 -> V_20 ) ,
V_18 ) ;
if ( ! V_16 -> V_20 )
return - V_19 ;
V_16 -> V_21 = F_8 ( V_2 , V_16 -> V_11 *
sizeof( * V_16 -> V_21 ) ,
V_18 ) ;
if ( ! V_16 -> V_21 )
return - V_19 ;
return 0 ;
}
struct V_15 * F_9 (
struct V_1 * V_2 , struct V_5 * V_9 )
{
int V_22 = 0 , V_23 = 0 , V_24 ;
struct V_15 * V_16 ;
struct V_25 V_6 , V_26 ;
struct V_1 * V_27 ;
struct V_5 * V_28 ;
struct V_5 * V_12 = NULL ;
struct V_5 * V_29 = NULL ;
struct V_5 * V_30 = NULL ;
V_16 = F_8 ( V_2 , sizeof( * V_16 ) , V_18 ) ;
if ( ! V_16 )
return F_10 ( - V_19 ) ;
V_16 -> V_31 = F_11 ( V_2 ) ;
F_4 ( V_9 , & V_16 -> V_10 , & V_16 -> V_11 ) ;
if ( V_16 -> V_11 ) {
V_23 = F_7 ( V_2 , V_16 ) ;
if ( V_23 )
return F_10 ( V_23 ) ;
do {
V_12 = F_5 ( V_9 , V_12 ) ;
if ( ! V_12 )
break;
if ( F_12 ( V_12 , L_1 , NULL ) )
continue;
V_23 = F_13 ( V_12 , & V_6 ) ;
if ( V_23 )
continue;
V_16 -> V_17 [ V_22 ] = V_6 . V_32 ;
V_29 = F_14 ( V_12 ) ;
V_30 = F_15 ( V_12 ) ;
if ( ! V_29 || ! V_30 )
continue;
if ( F_13 ( V_30 , & V_26 ) )
continue;
V_27 = F_2 ( V_29 ) ;
if ( ! V_27 )
continue;
V_16 -> V_20 [ V_22 ] = F_11 ( V_27 ) ;
V_16 -> V_21 [ V_22 ] = V_26 . V_32 ;
V_22 ++ ;
} while ( V_12 );
}
V_16 -> V_24 = 0 ;
V_28 = F_16 ( V_9 , L_2 , 0 ) ;
for ( V_24 = 0 ; V_28 && V_24 < V_33 ; V_24 ++ ) {
if ( V_28 == F_17 ( V_24 , NULL ) ) {
V_16 -> V_24 = V_24 ;
break;
}
}
return V_16 ;
}
