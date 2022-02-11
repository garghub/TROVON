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
static void F_4 ( const struct V_5 * V_9 ,
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
int F_9 ( const struct V_5 * V_9 )
{
int V_22 ;
bool V_23 ;
struct V_5 * V_24 , * V_25 ;
V_24 = F_10 ( V_9 , L_2 , 0 ) ;
if ( ! V_24 )
return 0 ;
F_11 (cpu) {
V_25 = F_12 ( V_22 ) ;
V_23 = ( V_24 == V_25 ) ;
F_13 ( V_25 ) ;
if ( V_23 )
break;
}
F_13 ( V_24 ) ;
return V_23 ? V_22 : 0 ;
}
struct V_15 *
F_14 ( struct V_1 * V_2 ,
const struct V_5 * V_9 )
{
int V_26 = 0 , V_27 = 0 ;
struct V_15 * V_16 ;
struct V_28 V_6 , V_29 ;
struct V_1 * V_30 ;
struct V_5 * V_12 = NULL ;
struct V_5 * V_31 = NULL ;
struct V_5 * V_32 = NULL ;
V_16 = F_8 ( V_2 , sizeof( * V_16 ) , V_18 ) ;
if ( ! V_16 )
return F_15 ( - V_19 ) ;
V_16 -> V_33 = F_16 ( V_2 ) ;
F_4 ( V_9 , & V_16 -> V_10 , & V_16 -> V_11 ) ;
if ( V_16 -> V_11 ) {
V_27 = F_7 ( V_2 , V_16 ) ;
if ( V_27 )
return F_15 ( V_27 ) ;
do {
V_12 = F_5 ( V_9 , V_12 ) ;
if ( ! V_12 )
break;
if ( F_17 ( V_12 , L_1 , NULL ) )
continue;
V_27 = F_18 ( V_12 , & V_6 ) ;
if ( V_27 )
continue;
V_16 -> V_17 [ V_26 ] = V_6 . V_34 ;
V_31 = F_19 ( V_12 ) ;
V_32 = F_20 ( V_12 ) ;
if ( ! V_31 || ! V_32 )
continue;
if ( F_18 ( V_32 , & V_29 ) )
continue;
V_30 = F_2 ( V_31 ) ;
if ( ! V_30 )
return F_15 ( - V_35 ) ;
V_16 -> V_20 [ V_26 ] = F_16 ( V_30 ) ;
V_16 -> V_21 [ V_26 ] = V_29 . V_36 ;
V_26 ++ ;
} while ( V_12 );
}
V_16 -> V_22 = F_9 ( V_9 ) ;
return V_16 ;
}
