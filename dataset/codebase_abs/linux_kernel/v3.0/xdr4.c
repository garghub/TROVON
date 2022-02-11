static inline T_1
F_1 ( T_2 V_1 )
{
return ( T_1 ) V_1 ;
}
static inline T_3
F_2 ( T_1 V_1 )
{
T_3 V_2 ;
if ( V_1 > V_3 )
V_2 = V_3 ;
else if ( V_1 < - V_3 )
V_2 = - V_3 ;
else
V_2 = V_1 ;
return V_2 ;
}
static T_4 *
F_3 ( T_4 * V_4 , struct V_5 * V_6 )
{
unsigned int V_7 ;
V_7 = F_4 ( * V_4 ++ ) ;
if( V_7 == 0 )
{
V_6 -> V_7 = 4 ;
memset ( V_6 -> V_8 , 0 , 4 ) ;
}
else if( V_7 <= V_9 )
{
V_6 -> V_7 = V_7 ;
memcpy ( V_6 -> V_8 , V_4 , V_7 ) ;
V_4 += F_5 ( V_7 ) ;
}
else
{
F_6 ( L_1
L_2 ,
V_7 , V_9 ) ;
return NULL ;
}
return V_4 ;
}
static T_4 *
F_7 ( T_4 * V_4 , struct V_5 * V_6 )
{
* V_4 ++ = F_8 ( V_6 -> V_7 ) ;
memcpy ( V_4 , V_6 -> V_8 , V_6 -> V_7 ) ;
V_4 += F_5 ( V_6 -> V_7 ) ;
return V_4 ;
}
static T_4 *
F_9 ( T_4 * V_4 , struct V_10 * V_11 )
{
memset ( V_11 -> V_8 , 0 , sizeof( V_11 -> V_8 ) ) ;
V_11 -> V_12 = F_4 ( * V_4 ++ ) ;
if ( V_11 -> V_12 > V_13 ) {
F_6 ( L_3 ,
V_11 -> V_12 , V_13 ) ;
return NULL ;
}
memcpy ( V_11 -> V_8 , V_4 , V_11 -> V_12 ) ;
return V_4 + F_5 ( V_11 -> V_12 ) ;
}
static T_4 *
F_10 ( T_4 * V_4 , struct V_14 * V_15 )
{
return F_11 ( V_4 , V_15 ) ;
}
static T_4 *
F_12 ( T_4 * V_4 , struct V_16 * V_17 )
{
struct V_18 * V_19 = & V_17 -> V_19 ;
T_5 V_7 , V_20 ;
T_2 V_21 ;
if ( ! ( V_4 = F_13 ( V_4 , & V_17 -> V_22 ,
& V_17 -> V_7 , V_23 ) )
|| ! ( V_4 = F_9 ( V_4 , & V_17 -> V_24 ) )
|| ! ( V_4 = F_10 ( V_4 , & V_17 -> V_15 ) ) )
return NULL ;
V_17 -> V_25 = F_4 ( * V_4 ++ ) ;
F_14 ( V_19 ) ;
V_19 -> V_26 = V_27 -> V_28 ;
V_19 -> V_29 = ( V_30 ) V_17 -> V_25 ;
V_19 -> V_31 = V_32 ;
V_19 -> V_33 = V_34 ;
V_4 = F_15 ( V_4 , & V_20 ) ;
V_4 = F_15 ( V_4 , & V_7 ) ;
V_21 = V_20 + V_7 - 1 ;
V_19 -> V_35 = F_1 ( V_20 ) ;
if ( V_7 == 0 || V_21 < 0 )
V_19 -> V_36 = V_37 ;
else
V_19 -> V_36 = F_1 ( V_21 ) ;
return V_4 ;
}
static T_4 *
F_16 ( T_4 * V_4 , struct V_38 * V_39 )
{
T_3 V_20 , V_7 ;
F_6 ( L_4 , V_4 , V_39 ) ;
if ( ! ( V_4 = F_7 ( V_4 , & V_39 -> V_40 ) ) )
return NULL ;
* V_4 ++ = V_39 -> V_41 ;
if ( V_39 -> V_41 == V_42 ) {
struct V_18 * V_19 = & V_39 -> V_17 . V_19 ;
* V_4 ++ = ( V_19 -> V_33 == V_34 ) ? V_43 : V_44 ;
* V_4 ++ = F_8 ( V_39 -> V_17 . V_25 ) ;
if ( ! ( V_4 = F_17 ( V_4 , & V_39 -> V_17 . V_15 ) ) )
return NULL ;
V_20 = F_2 ( V_19 -> V_35 ) ;
if ( V_19 -> V_36 == V_37 )
V_7 = 0 ;
else
V_7 = F_2 ( V_19 -> V_36 - V_19 -> V_35 + 1 ) ;
V_4 = F_18 ( V_4 , V_20 ) ;
V_4 = F_18 ( V_4 , V_7 ) ;
F_6 ( L_5 ,
V_39 -> V_41 , ( int ) V_39 -> V_17 . V_25 , V_19 -> V_33 ,
( long long ) V_19 -> V_35 , ( long long ) V_19 -> V_36 ) ;
}
F_6 ( L_6 , V_4 , V_39 ) ;
return V_4 ;
}
int
F_19 ( struct V_45 * V_46 , T_4 * V_4 , T_6 * V_47 )
{
T_7 V_48 ;
if ( ! ( V_4 = F_3 ( V_4 , & V_47 -> V_40 ) ) )
return 0 ;
V_48 = F_4 ( * V_4 ++ ) ;
if ( ! ( V_4 = F_12 ( V_4 , & V_47 -> V_17 ) ) )
return 0 ;
if ( V_48 )
V_47 -> V_17 . V_19 . V_33 = V_49 ;
return F_20 ( V_46 , V_4 ) ;
}
int
F_21 ( struct V_45 * V_46 , T_4 * V_4 , struct V_38 * V_39 )
{
if ( ! ( V_4 = F_16 ( V_4 , V_39 ) ) )
return 0 ;
return F_22 ( V_46 , V_4 ) ;
}
int
F_23 ( struct V_45 * V_46 , T_4 * V_4 , T_6 * V_47 )
{
T_7 V_48 ;
if ( ! ( V_4 = F_3 ( V_4 , & V_47 -> V_40 ) ) )
return 0 ;
V_47 -> V_50 = F_4 ( * V_4 ++ ) ;
V_48 = F_4 ( * V_4 ++ ) ;
if ( ! ( V_4 = F_12 ( V_4 , & V_47 -> V_17 ) ) )
return 0 ;
if ( V_48 )
V_47 -> V_17 . V_19 . V_33 = V_49 ;
V_47 -> V_51 = F_4 ( * V_4 ++ ) ;
V_47 -> V_52 = F_4 ( * V_4 ++ ) ;
V_47 -> V_53 = 1 ;
return F_20 ( V_46 , V_4 ) ;
}
int
F_24 ( struct V_45 * V_46 , T_4 * V_4 , T_6 * V_47 )
{
T_7 V_48 ;
if ( ! ( V_4 = F_3 ( V_4 , & V_47 -> V_40 ) ) )
return 0 ;
V_47 -> V_50 = F_4 ( * V_4 ++ ) ;
V_48 = F_4 ( * V_4 ++ ) ;
if ( ! ( V_4 = F_12 ( V_4 , & V_47 -> V_17 ) ) )
return 0 ;
if ( V_48 )
V_47 -> V_17 . V_19 . V_33 = V_49 ;
return F_20 ( V_46 , V_4 ) ;
}
int
F_25 ( struct V_45 * V_46 , T_4 * V_4 , T_6 * V_47 )
{
if ( ! ( V_4 = F_3 ( V_4 , & V_47 -> V_40 ) )
|| ! ( V_4 = F_12 ( V_4 , & V_47 -> V_17 ) ) )
return 0 ;
V_47 -> V_17 . V_19 . V_33 = V_54 ;
return F_20 ( V_46 , V_4 ) ;
}
int
F_26 ( struct V_45 * V_46 , T_4 * V_4 , T_6 * V_47 )
{
struct V_16 * V_17 = & V_47 -> V_17 ;
memset ( V_17 , 0 , sizeof( * V_17 ) ) ;
F_14 ( & V_17 -> V_19 ) ;
V_17 -> V_25 = ~ ( T_7 ) 0 ;
V_17 -> V_19 . V_29 = ( V_30 ) V_17 -> V_25 ;
if ( ! ( V_4 = F_3 ( V_4 , & V_47 -> V_40 ) )
|| ! ( V_4 = F_13 ( V_4 , & V_17 -> V_22 ,
& V_17 -> V_7 , V_23 ) )
|| ! ( V_4 = F_9 ( V_4 , & V_17 -> V_24 ) )
|| ! ( V_4 = F_10 ( V_4 , & V_17 -> V_15 ) ) )
return 0 ;
V_47 -> V_55 = F_4 ( * V_4 ++ ) ;
V_47 -> V_56 = F_4 ( * V_4 ++ ) ;
return F_20 ( V_46 , V_4 ) ;
}
int
F_27 ( struct V_45 * V_46 , T_4 * V_4 , struct V_38 * V_39 )
{
if ( ! ( V_4 = F_7 ( V_4 , & V_39 -> V_40 ) ) )
return 0 ;
* V_4 ++ = V_39 -> V_41 ;
* V_4 ++ = V_43 ;
return F_22 ( V_46 , V_4 ) ;
}
int
F_28 ( struct V_45 * V_46 , T_4 * V_4 , struct V_38 * V_39 )
{
if ( ! ( V_4 = F_7 ( V_4 , & V_39 -> V_40 ) ) )
return 0 ;
* V_4 ++ = V_39 -> V_41 ;
return F_22 ( V_46 , V_4 ) ;
}
int
F_29 ( struct V_45 * V_46 , T_4 * V_4 , struct T_6 * V_47 )
{
struct V_16 * V_17 = & V_47 -> V_17 ;
if ( ! ( V_4 = F_13 ( V_4 , & V_17 -> V_22 ,
& V_17 -> V_7 , V_23 ) ) )
return 0 ;
V_47 -> V_52 = F_4 ( * V_4 ++ ) ;
return F_20 ( V_46 , V_4 ) ;
}
int
F_30 ( struct V_45 * V_46 , T_4 * V_4 , struct V_57 * V_47 )
{
if ( ! ( V_4 = F_13 ( V_4 , & V_47 -> V_58 , & V_47 -> V_7 , V_59 ) ) )
return 0 ;
V_47 -> V_52 = F_4 ( * V_4 ++ ) ;
memcpy ( & V_47 -> V_60 . V_8 , V_4 , sizeof( V_47 -> V_60 . V_8 ) ) ;
V_4 += F_5 ( V_61 ) ;
return F_20 ( V_46 , V_4 ) ;
}
int
F_31 ( struct V_45 * V_46 , T_4 * V_4 , struct V_38 * V_39 )
{
if ( ! ( V_4 = F_3 ( V_4 , & V_39 -> V_40 ) ) )
return 0 ;
V_39 -> V_41 = * V_4 ++ ;
return F_20 ( V_46 , V_4 ) ;
}
int
F_32 ( struct V_45 * V_46 , T_4 * V_4 , void * V_62 )
{
return F_20 ( V_46 , V_4 ) ;
}
int
F_33 ( struct V_45 * V_46 , T_4 * V_4 , void * V_62 )
{
return F_22 ( V_46 , V_4 ) ;
}
