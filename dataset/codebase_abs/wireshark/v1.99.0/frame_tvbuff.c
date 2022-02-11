static T_1
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 , T_2 * V_5 )
{
int V_6 ;
T_3 * V_7 ;
if ( V_8 . V_9 != V_2 -> V_9 )
return FALSE ;
if ( ! F_2 ( V_2 -> V_9 , V_2 -> V_10 , V_4 , V_5 , & V_6 , & V_7 ) ) {
switch ( V_6 ) {
case V_11 :
case V_12 :
F_3 ( V_7 ) ;
break;
}
return FALSE ;
}
return TRUE ;
}
static void
F_4 ( struct V_1 * V_2 )
{
struct V_3 V_4 ;
memset ( & V_4 , 0 , sizeof( struct V_3 ) ) ;
if ( V_2 -> V_5 == NULL ) {
V_2 -> V_5 = (struct T_2 * ) F_5 ( sizeof( struct T_2 ) ) ;
F_6 ( V_2 -> V_5 , V_2 -> V_13 . V_14 + V_2 -> V_15 ) ;
if ( ! F_1 ( V_2 , & V_4 , V_2 -> V_5 ) )
{ }
}
V_2 -> V_13 . V_16 = F_7 ( V_2 -> V_5 ) + V_2 -> V_15 ;
}
static void
F_8 ( T_4 * V_13 )
{
struct V_1 * V_2 = (struct V_1 * ) V_13 ;
if ( V_2 -> V_5 ) {
F_9 ( V_2 -> V_5 ) ;
F_3 ( V_2 -> V_5 ) ;
}
}
static const T_5 *
F_10 ( T_4 * V_13 , T_6 V_17 , T_6 T_7 V_18 )
{
struct V_1 * V_2 = (struct V_1 * ) V_13 ;
F_4 ( V_2 ) ;
return V_13 -> V_16 + V_17 ;
}
static void *
F_11 ( T_4 * V_13 , void * V_19 , T_6 V_17 , T_6 T_7 )
{
struct V_1 * V_2 = (struct V_1 * ) V_13 ;
F_4 ( V_2 ) ;
return memcpy ( V_19 , V_13 -> V_16 + V_17 , T_7 ) ;
}
static T_8
F_12 ( T_4 * V_13 , T_6 V_17 , T_6 V_20 , T_5 V_21 )
{
struct V_1 * V_2 = (struct V_1 * ) V_13 ;
const T_5 * V_22 ;
F_4 ( V_2 ) ;
V_22 = ( const T_5 * ) memchr ( V_13 -> V_16 + V_17 , V_21 , V_20 ) ;
if ( V_22 )
return ( T_8 ) ( V_22 - V_13 -> V_16 ) ;
else
return - 1 ;
}
static T_8
F_13 ( T_4 * V_13 , T_6 V_17 , T_6 V_20 , const T_5 * V_23 , T_9 * V_24 )
{
struct V_1 * V_2 = (struct V_1 * ) V_13 ;
F_4 ( V_2 ) ;
return F_14 ( V_13 , V_17 , V_20 , V_23 , V_24 ) ;
}
static T_6
F_15 ( const T_4 * V_13 V_18 , const T_6 V_25 )
{
return V_25 ;
}
T_4 *
F_16 ( const T_10 * V_26 , const T_5 * V_5 )
{
struct V_1 * V_2 ;
T_4 * V_13 ;
V_13 = F_17 ( & V_27 ) ;
V_13 -> V_16 = V_5 ;
V_13 -> V_14 = V_26 -> V_28 ;
V_13 -> V_29 = V_26 -> V_30 > V_31 ? V_31 : V_26 -> V_30 ;
V_13 -> V_32 = TRUE ;
V_13 -> V_33 = V_13 ;
V_2 = (struct V_1 * ) V_13 ;
if ( V_8 . V_9 && V_8 . V_9 -> V_34
#ifdef F_18
&& V_26 -> V_10 != - 1
#endif
) {
V_2 -> V_9 = V_8 . V_9 ;
V_2 -> V_10 = V_26 -> V_10 ;
V_2 -> V_15 = 0 ;
} else
V_2 -> V_9 = NULL ;
V_2 -> V_5 = NULL ;
return V_13 ;
}
T_4 *
F_19 ( const T_10 * V_26 , T_2 * V_5 )
{
return F_16 ( V_26 , F_7 ( V_5 ) ) ;
}
static T_4 *
F_20 ( T_4 * V_13 , T_6 V_17 , T_6 T_7 )
{
struct V_1 * V_2 = (struct V_1 * ) V_13 ;
T_4 * V_35 ;
struct V_1 * V_36 ;
if ( ! V_2 -> V_9 )
return NULL ;
V_17 += V_2 -> V_15 ;
V_35 = F_17 ( & V_27 ) ;
V_35 -> V_16 = NULL ;
V_35 -> V_14 = T_7 ;
V_35 -> V_29 = T_7 ;
V_35 -> V_32 = TRUE ;
V_35 -> V_33 = V_35 ;
V_36 = (struct V_1 * ) V_35 ;
V_36 -> V_9 = V_2 -> V_9 ;
V_36 -> V_10 = V_2 -> V_10 ;
V_36 -> V_15 = V_17 ;
V_36 -> V_5 = NULL ;
return V_35 ;
}
T_4 *
F_21 ( const T_10 * V_26 , const T_5 * V_5 )
{
struct V_1 * V_2 ;
T_4 * V_13 ;
V_13 = F_17 ( & V_27 ) ;
V_13 -> V_16 = V_5 ;
V_13 -> V_14 = V_26 -> V_28 ;
V_13 -> V_29 = V_26 -> V_30 > V_31 ? V_31 : V_26 -> V_30 ;
V_13 -> V_32 = TRUE ;
V_13 -> V_33 = V_13 ;
V_2 = (struct V_1 * ) V_13 ;
if ( V_8 . V_9 && V_8 . V_9 -> V_34
#ifdef F_18
&& V_26 -> V_10 != - 1
#endif
) {
V_2 -> V_9 = V_8 . V_9 ;
V_2 -> V_10 = V_26 -> V_10 ;
V_2 -> V_15 = 0 ;
} else
V_2 -> V_9 = NULL ;
V_2 -> V_5 = NULL ;
return V_13 ;
}
T_4 *
F_22 ( const T_10 * V_26 , T_2 * V_5 )
{
return F_16 ( V_26 , F_7 ( V_5 ) ) ;
}
