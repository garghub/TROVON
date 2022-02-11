static T_1
F_1 ( const T_2 * V_1 , const T_1 V_2 )
{
const struct V_3 * V_4 = ( const struct V_3 * ) V_1 ;
const T_2 * V_5 = V_4 -> V_6 . V_1 ;
return F_2 ( V_5 , V_2 + V_4 -> V_6 . V_7 ) ;
}
static void *
F_3 ( T_2 * V_1 , void * V_8 , T_1 V_9 , T_1 V_10 )
{
struct V_3 * V_4 = (struct V_3 * ) V_1 ;
return F_4 ( V_4 -> V_6 . V_1 , V_8 , V_4 -> V_6 . V_7 + V_9 , V_10 ) ;
}
static const T_3 *
F_5 ( T_2 * V_1 , T_1 V_9 , T_1 V_10 )
{
struct V_3 * V_4 = (struct V_3 * ) V_1 ;
return F_6 ( V_4 -> V_6 . V_1 , V_4 -> V_6 . V_7 + V_9 , V_10 ) ;
}
static T_4
F_7 ( T_2 * V_1 , T_1 V_9 , T_1 V_11 , T_3 V_12 )
{
struct V_3 * V_4 = (struct V_3 * ) V_1 ;
return F_8 ( V_4 -> V_6 . V_1 , V_4 -> V_6 . V_7 + V_9 , V_11 , V_12 ) ;
}
static T_4
F_9 ( T_2 * V_1 , T_1 V_9 , T_1 V_11 , const T_5 * V_13 , T_6 * V_14 )
{
struct V_3 * V_4 = (struct V_3 * ) V_1 ;
return F_10 ( V_4 -> V_6 . V_1 , V_4 -> V_6 . V_7 + V_9 , V_11 , V_13 , V_14 ) ;
}
static T_2 *
F_11 ( T_2 * V_1 , T_1 V_9 , T_1 V_10 )
{
struct V_3 * V_4 = (struct V_3 * ) V_1 ;
return F_12 ( V_4 -> V_6 . V_1 , V_4 -> V_6 . V_7 + V_9 , V_10 ) ;
}
static T_2 *
F_13 ( T_2 * V_15 , const T_4 V_16 ,
const T_1 V_17 , const T_1 V_18 )
{
T_2 * V_1 = F_14 ( & V_19 ) ;
struct V_3 * V_4 = (struct V_3 * ) V_1 ;
V_4 -> V_6 . V_7 = V_17 ;
V_4 -> V_6 . V_20 = V_18 ;
V_4 -> V_6 . V_1 = V_15 ;
V_1 -> V_20 = V_18 ;
V_1 -> V_21 = V_15 -> V_21 ;
if ( V_16 == - 1 ) {
V_1 -> V_16 = V_15 -> V_16 - V_17 ;
}
else {
V_1 -> V_16 = V_16 ;
}
V_1 -> V_22 = TRUE ;
if ( V_15 -> V_23 != NULL ) {
V_1 -> V_23 = V_15 -> V_23 + V_17 ;
}
V_1 -> V_24 = V_15 -> V_24 ;
return V_1 ;
}
T_2 *
F_15 ( T_2 * V_15 , const T_4 V_25 , const T_4 V_26 , const T_4 V_16 )
{
T_2 * V_1 ;
T_1 V_17 ;
T_1 V_18 ;
F_16 ( V_15 && V_15 -> V_22 ) ;
F_17 ( V_16 < - 1 , V_27 ) ;
F_18 ( V_15 , V_25 , V_26 ,
& V_17 ,
& V_18 ) ;
V_1 = F_13 ( V_15 , V_16 ,
V_17 , V_18 ) ;
F_19 ( V_15 , V_1 ) ;
return V_1 ;
}
T_2 *
F_20 ( T_2 * V_15 , const T_4 V_25 , const T_4 V_26 )
{
T_4 V_28 ;
T_2 * V_1 ;
T_1 V_17 ;
T_1 V_18 ;
F_16 ( V_15 && V_15 -> V_22 ) ;
F_17 ( V_26 < 0 , V_27 ) ;
V_28 = F_21 ( V_15 , V_25 ) ;
F_17 ( V_28 < 0 , V_29 ) ;
if ( V_28 > V_26 )
V_28 = V_26 ;
F_18 ( V_15 , V_25 , V_28 ,
& V_17 ,
& V_18 ) ;
V_1 = F_13 ( V_15 , V_26 ,
V_17 , V_18 ) ;
F_19 ( V_15 , V_1 ) ;
return V_1 ;
}
T_2 *
F_22 ( T_2 * V_15 , const T_4 V_25 )
{
T_2 * V_1 ;
T_1 V_17 ;
T_1 V_18 ;
F_18 ( V_15 , V_25 , - 1 ,
& V_17 ,
& V_18 ) ;
V_1 = F_13 ( V_15 , - 1 ,
V_17 , V_18 ) ;
F_19 ( V_15 , V_1 ) ;
return V_1 ;
}
T_2 *
F_23 ( T_2 * V_15 )
{
T_2 * V_1 ;
if ( V_15 )
V_1 = F_13 ( V_15 , V_15 -> V_16 , 0 , V_15 -> V_20 ) ;
else
V_1 = F_24 ( NULL , 0 , 0 ) ;
V_1 -> V_24 = V_1 ;
return V_1 ;
}
