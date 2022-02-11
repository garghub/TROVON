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
if G_UNLIKELY( ! V_12 ) V_12 = F_6 ( 1024 ) ;
if ( V_12 -> V_13 > 0 ) {
V_2 -> V_5 = (struct T_2 * ) F_7 ( V_12 , V_12 -> V_13 - 1 ) ;
} else {
V_2 -> V_5 = (struct T_2 * ) F_8 ( sizeof( struct T_2 ) ) ;
}
F_9 ( V_2 -> V_5 , V_2 -> V_14 . V_15 + V_2 -> V_16 ) ;
if ( ! F_1 ( V_2 , & V_4 , V_2 -> V_5 ) )
{ }
}
V_2 -> V_14 . V_17 = F_10 ( V_2 -> V_5 ) + V_2 -> V_16 ;
F_11 ( & V_4 ) ;
}
static void
F_12 ( T_4 * V_14 )
{
struct V_1 * V_2 = (struct V_1 * ) V_14 ;
if ( V_2 -> V_5 ) {
F_13 ( V_2 -> V_5 ) ;
F_14 ( V_12 , V_2 -> V_5 ) ;
}
}
static const T_5 *
F_15 ( T_4 * V_14 , T_6 V_18 , T_6 T_7 V_19 )
{
struct V_1 * V_2 = (struct V_1 * ) V_14 ;
F_4 ( V_2 ) ;
return V_14 -> V_17 + V_18 ;
}
static void *
F_16 ( T_4 * V_14 , void * V_20 , T_6 V_18 , T_6 T_7 )
{
struct V_1 * V_2 = (struct V_1 * ) V_14 ;
F_4 ( V_2 ) ;
return memcpy ( V_20 , V_14 -> V_17 + V_18 , T_7 ) ;
}
static T_8
F_17 ( T_4 * V_14 , T_6 V_18 , T_6 V_21 , T_5 V_22 )
{
struct V_1 * V_2 = (struct V_1 * ) V_14 ;
const T_5 * V_23 ;
F_4 ( V_2 ) ;
V_23 = ( const T_5 * ) memchr ( V_14 -> V_17 + V_18 , V_22 , V_21 ) ;
if ( V_23 )
return ( T_8 ) ( V_23 - V_14 -> V_17 ) ;
else
return - 1 ;
}
static T_8
F_18 ( T_4 * V_14 , T_6 V_18 , T_6 V_21 , const T_9 * V_24 , T_10 * V_25 )
{
struct V_1 * V_2 = (struct V_1 * ) V_14 ;
F_4 ( V_2 ) ;
return F_19 ( V_14 , V_18 , V_21 , V_24 , V_25 ) ;
}
static T_6
F_20 ( const T_4 * V_14 V_19 , const T_6 V_26 )
{
return V_26 ;
}
T_4 *
F_21 ( const T_11 * V_27 , const T_5 * V_5 )
{
struct V_1 * V_2 ;
T_4 * V_14 ;
V_14 = F_22 ( & V_28 ) ;
V_14 -> V_17 = V_5 ;
V_14 -> V_15 = V_27 -> V_29 ;
V_14 -> V_30 = V_27 -> V_31 > V_32 ? V_32 : V_27 -> V_31 ;
V_14 -> V_33 = TRUE ;
V_14 -> V_34 = V_14 ;
V_2 = (struct V_1 * ) V_14 ;
if ( V_8 . V_9 && V_8 . V_9 -> V_35
#ifdef F_23
&& V_27 -> V_10 != - 1
#endif
) {
V_2 -> V_9 = V_8 . V_9 ;
V_2 -> V_10 = V_27 -> V_10 ;
V_2 -> V_16 = 0 ;
} else
V_2 -> V_9 = NULL ;
V_2 -> V_5 = NULL ;
return V_14 ;
}
T_4 *
F_24 ( const T_11 * V_27 , T_2 * V_5 )
{
return F_21 ( V_27 , F_10 ( V_5 ) ) ;
}
static T_4 *
F_25 ( T_4 * V_14 , T_6 V_18 , T_6 T_7 )
{
struct V_1 * V_2 = (struct V_1 * ) V_14 ;
T_4 * V_36 ;
struct V_1 * V_37 ;
if ( ! V_2 -> V_9 )
return NULL ;
V_18 += V_2 -> V_16 ;
V_36 = F_22 ( & V_28 ) ;
V_36 -> V_17 = NULL ;
V_36 -> V_15 = T_7 ;
V_36 -> V_30 = T_7 ;
V_36 -> V_33 = TRUE ;
V_36 -> V_34 = V_36 ;
V_37 = (struct V_1 * ) V_36 ;
V_37 -> V_9 = V_2 -> V_9 ;
V_37 -> V_10 = V_2 -> V_10 ;
V_37 -> V_16 = V_18 ;
V_37 -> V_5 = NULL ;
return V_36 ;
}
T_4 *
F_26 ( const T_11 * V_27 , const T_5 * V_5 )
{
struct V_1 * V_2 ;
T_4 * V_14 ;
V_14 = F_22 ( & V_28 ) ;
V_14 -> V_17 = V_5 ;
V_14 -> V_15 = V_27 -> V_29 ;
V_14 -> V_30 = V_27 -> V_31 > V_32 ? V_32 : V_27 -> V_31 ;
V_14 -> V_33 = TRUE ;
V_14 -> V_34 = V_14 ;
V_2 = (struct V_1 * ) V_14 ;
if ( V_8 . V_9 && V_8 . V_9 -> V_35
#ifdef F_23
&& V_27 -> V_10 != - 1
#endif
) {
V_2 -> V_9 = V_8 . V_9 ;
V_2 -> V_10 = V_27 -> V_10 ;
V_2 -> V_16 = 0 ;
} else
V_2 -> V_9 = NULL ;
V_2 -> V_5 = NULL ;
return V_14 ;
}
T_4 *
F_27 ( const T_11 * V_27 , T_2 * V_5 )
{
return F_21 ( V_27 , F_10 ( V_5 ) ) ;
}
