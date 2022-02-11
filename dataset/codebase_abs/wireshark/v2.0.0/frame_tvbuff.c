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
F_5 ( & V_4 ) ;
if ( V_2 -> V_5 == NULL ) {
V_2 -> V_5 = (struct T_2 * ) F_6 ( sizeof( struct T_2 ) ) ;
F_7 ( V_2 -> V_5 , V_2 -> V_12 . V_13 + V_2 -> V_14 ) ;
if ( ! F_1 ( V_2 , & V_4 , V_2 -> V_5 ) )
{ }
}
V_2 -> V_12 . V_15 = F_8 ( V_2 -> V_5 ) + V_2 -> V_14 ;
F_9 ( & V_4 ) ;
}
static void
F_10 ( T_4 * V_12 )
{
struct V_1 * V_2 = (struct V_1 * ) V_12 ;
if ( V_2 -> V_5 ) {
F_11 ( V_2 -> V_5 ) ;
F_3 ( V_2 -> V_5 ) ;
}
}
static const T_5 *
F_12 ( T_4 * V_12 , T_6 V_16 , T_6 T_7 V_17 )
{
struct V_1 * V_2 = (struct V_1 * ) V_12 ;
F_4 ( V_2 ) ;
return V_12 -> V_15 + V_16 ;
}
static void *
F_13 ( T_4 * V_12 , void * V_18 , T_6 V_16 , T_6 T_7 )
{
struct V_1 * V_2 = (struct V_1 * ) V_12 ;
F_4 ( V_2 ) ;
return memcpy ( V_18 , V_12 -> V_15 + V_16 , T_7 ) ;
}
static T_8
F_14 ( T_4 * V_12 , T_6 V_16 , T_6 V_19 , T_5 V_20 )
{
struct V_1 * V_2 = (struct V_1 * ) V_12 ;
const T_5 * V_21 ;
F_4 ( V_2 ) ;
V_21 = ( const T_5 * ) memchr ( V_12 -> V_15 + V_16 , V_20 , V_19 ) ;
if ( V_21 )
return ( T_8 ) ( V_21 - V_12 -> V_15 ) ;
else
return - 1 ;
}
static T_8
F_15 ( T_4 * V_12 , T_6 V_16 , T_6 V_19 , const T_9 * V_22 , T_10 * V_23 )
{
struct V_1 * V_2 = (struct V_1 * ) V_12 ;
F_4 ( V_2 ) ;
return F_16 ( V_12 , V_16 , V_19 , V_22 , V_23 ) ;
}
static T_6
F_17 ( const T_4 * V_12 V_17 , const T_6 V_24 )
{
return V_24 ;
}
T_4 *
F_18 ( const T_11 * V_25 , const T_5 * V_5 )
{
struct V_1 * V_2 ;
T_4 * V_12 ;
V_12 = F_19 ( & V_26 ) ;
V_12 -> V_15 = V_5 ;
V_12 -> V_13 = V_25 -> V_27 ;
V_12 -> V_28 = V_25 -> V_29 > V_30 ? V_30 : V_25 -> V_29 ;
V_12 -> V_31 = TRUE ;
V_12 -> V_32 = V_12 ;
V_2 = (struct V_1 * ) V_12 ;
if ( V_8 . V_9 && V_8 . V_9 -> V_33
#ifdef F_20
&& V_25 -> V_10 != - 1
#endif
) {
V_2 -> V_9 = V_8 . V_9 ;
V_2 -> V_10 = V_25 -> V_10 ;
V_2 -> V_14 = 0 ;
} else
V_2 -> V_9 = NULL ;
V_2 -> V_5 = NULL ;
return V_12 ;
}
T_4 *
F_21 ( const T_11 * V_25 , T_2 * V_5 )
{
return F_18 ( V_25 , F_8 ( V_5 ) ) ;
}
static T_4 *
F_22 ( T_4 * V_12 , T_6 V_16 , T_6 T_7 )
{
struct V_1 * V_2 = (struct V_1 * ) V_12 ;
T_4 * V_34 ;
struct V_1 * V_35 ;
if ( ! V_2 -> V_9 )
return NULL ;
V_16 += V_2 -> V_14 ;
V_34 = F_19 ( & V_26 ) ;
V_34 -> V_15 = NULL ;
V_34 -> V_13 = T_7 ;
V_34 -> V_28 = T_7 ;
V_34 -> V_31 = TRUE ;
V_34 -> V_32 = V_34 ;
V_35 = (struct V_1 * ) V_34 ;
V_35 -> V_9 = V_2 -> V_9 ;
V_35 -> V_10 = V_2 -> V_10 ;
V_35 -> V_14 = V_16 ;
V_35 -> V_5 = NULL ;
return V_34 ;
}
T_4 *
F_23 ( const T_11 * V_25 , const T_5 * V_5 )
{
struct V_1 * V_2 ;
T_4 * V_12 ;
V_12 = F_19 ( & V_26 ) ;
V_12 -> V_15 = V_5 ;
V_12 -> V_13 = V_25 -> V_27 ;
V_12 -> V_28 = V_25 -> V_29 > V_30 ? V_30 : V_25 -> V_29 ;
V_12 -> V_31 = TRUE ;
V_12 -> V_32 = V_12 ;
V_2 = (struct V_1 * ) V_12 ;
if ( V_8 . V_9 && V_8 . V_9 -> V_33
#ifdef F_20
&& V_25 -> V_10 != - 1
#endif
) {
V_2 -> V_9 = V_8 . V_9 ;
V_2 -> V_10 = V_25 -> V_10 ;
V_2 -> V_14 = 0 ;
} else
V_2 -> V_9 = NULL ;
V_2 -> V_5 = NULL ;
return V_12 ;
}
T_4 *
F_24 ( const T_11 * V_25 , T_2 * V_5 )
{
return F_18 ( V_25 , F_8 ( V_5 ) ) ;
}
