static T_1 void F_1 ( T_2 V_1 )
{
T_3 * V_2 ;
V_2 = F_2 ( & V_3 , & V_1 ) ;
if ( V_2 )
* V_2 += 1 ;
}
static T_1 int F_3 ( void * V_4 , void * V_5 ,
T_4 V_1 )
{
struct V_6 * V_7 ;
struct V_8 * V_9 ;
switch ( V_1 ) {
case V_10 :
V_7 = (struct V_6 * ) V_4 ;
if ( V_7 + 1 > V_5 )
return - 1 ;
return V_7 -> V_11 ;
case V_12 :
V_9 = (struct V_8 * ) V_4 ;
if ( V_9 + 1 > V_5 )
return - 1 ;
return V_9 -> V_11 ;
default:
return 0 ;
}
}
static T_1 void F_4 ( struct V_13 * V_14 ,
const struct V_13 * V_15 ,
const struct V_16 * V_17 ,
T_5 V_18 )
{
memcpy ( V_14 -> V_19 , V_15 -> V_20 , sizeof( V_14 -> V_19 ) ) ;
memcpy ( V_14 -> V_20 , V_17 -> V_21 , sizeof( V_14 -> V_20 ) ) ;
V_14 -> V_18 = V_18 ;
}
static T_1 int F_5 ( struct V_22 * V_23 )
{
void * V_5 = ( void * ) ( long ) V_23 -> V_5 ;
void * V_24 = ( void * ) ( long ) V_23 -> V_24 ;
struct V_16 * V_17 ;
struct V_13 * V_14 ;
struct V_13 * V_15 ;
struct V_25 * V_26 = V_24 + sizeof( struct V_13 ) ;
T_6 * V_27 ;
T_6 V_28 ;
struct V_29 V_29 = {} ;
int V_30 ;
T_2 V_31 = 0 ;
int V_32 ;
if ( V_26 + 1 > V_5 )
return V_33 ;
V_30 = F_3 ( V_26 + 1 , V_5 , V_26 -> V_1 ) ;
if ( V_30 == - 1 )
return V_33 ;
V_29 . V_1 = V_26 -> V_1 ;
V_29 . V_34 = V_35 ;
V_29 . V_36 . V_37 = V_26 -> V_36 ;
V_29 . V_30 = V_30 ;
V_28 = F_6 ( V_26 -> V_38 ) ;
V_17 = F_2 ( & V_39 , & V_29 ) ;
if ( ! V_17 || V_17 -> V_34 != V_35 )
return V_40 ;
if ( F_7 ( V_23 , 0 - ( int ) sizeof( struct V_25 ) ) )
return V_33 ;
V_24 = ( void * ) ( long ) V_23 -> V_24 ;
V_5 = ( void * ) ( long ) V_23 -> V_5 ;
V_14 = V_24 ;
V_26 = V_24 + sizeof( * V_14 ) ;
V_15 = V_24 + sizeof( * V_26 ) ;
if ( V_14 + 1 > V_5 ||
V_15 + 1 > V_5 ||
V_26 + 1 > V_5 )
return V_33 ;
F_4 ( V_14 , V_15 , V_17 , F_8 ( V_41 ) ) ;
V_26 -> V_42 = 4 ;
V_26 -> V_43 = sizeof( * V_26 ) >> 2 ;
V_26 -> V_44 = 0 ;
V_26 -> V_1 = V_45 ;
V_26 -> V_46 = 0 ;
V_26 -> V_47 = 0 ;
V_26 -> V_38 = F_8 ( V_28 + sizeof( * V_26 ) ) ;
V_26 -> V_36 = V_17 -> V_36 . V_37 ;
V_26 -> V_48 = V_17 -> V_48 . V_37 ;
V_26 -> V_49 = 8 ;
V_27 = ( T_6 * ) V_26 ;
#pragma V_50 V_51 V_52 ( V_53 )
for ( V_32 = 0 ; V_32 < sizeof( * V_26 ) >> 1 ; V_32 ++ )
V_31 += * V_27 ++ ;
V_26 -> V_46 = ~ ( ( V_31 & 0xffff ) + ( V_31 >> 16 ) ) ;
F_1 ( V_29 . V_1 ) ;
return V_54 ;
}
static T_1 int F_9 ( struct V_22 * V_23 )
{
void * V_5 = ( void * ) ( long ) V_23 -> V_5 ;
void * V_24 = ( void * ) ( long ) V_23 -> V_24 ;
struct V_16 * V_17 ;
struct V_13 * V_14 ;
struct V_13 * V_15 ;
struct V_55 * V_56 = V_24 + sizeof( struct V_13 ) ;
T_7 V_28 ;
struct V_29 V_29 = {} ;
int V_30 ;
if ( V_56 + 1 > V_5 )
return V_33 ;
V_30 = F_3 ( V_56 + 1 , V_5 , V_56 -> V_57 ) ;
if ( V_30 == - 1 )
return V_33 ;
V_29 . V_1 = V_56 -> V_57 ;
V_29 . V_34 = V_58 ;
memcpy ( V_29 . V_36 . V_59 , V_56 -> V_36 . V_60 , sizeof( V_29 . V_36 ) ) ;
V_29 . V_30 = V_30 ;
V_28 = V_56 -> V_28 ;
V_17 = F_2 ( & V_39 , & V_29 ) ;
if ( ! V_17 || V_17 -> V_34 != V_58 )
return V_40 ;
if ( F_7 ( V_23 , 0 - ( int ) sizeof( struct V_55 ) ) )
return V_33 ;
V_24 = ( void * ) ( long ) V_23 -> V_24 ;
V_5 = ( void * ) ( long ) V_23 -> V_5 ;
V_14 = V_24 ;
V_56 = V_24 + sizeof( * V_14 ) ;
V_15 = V_24 + sizeof( * V_56 ) ;
if ( V_14 + 1 > V_5 ||
V_15 + 1 > V_5 ||
V_56 + 1 > V_5 )
return V_33 ;
F_4 ( V_14 , V_15 , V_17 , F_8 ( V_61 ) ) ;
V_56 -> V_42 = 6 ;
V_56 -> V_62 = 0 ;
memset ( V_56 -> V_63 , 0 , sizeof( V_56 -> V_63 ) ) ;
V_56 -> V_28 = F_8 ( F_6 ( V_28 ) + sizeof( * V_56 ) ) ;
V_56 -> V_57 = V_64 ;
V_56 -> V_65 = 8 ;
memcpy ( V_56 -> V_48 . V_60 , V_17 -> V_48 . V_59 , sizeof( V_17 -> V_48 . V_59 ) ) ;
memcpy ( V_56 -> V_36 . V_60 , V_17 -> V_36 . V_59 , sizeof( V_17 -> V_36 . V_59 ) ) ;
F_1 ( V_29 . V_1 ) ;
return V_54 ;
}
int F_10 ( struct V_22 * V_23 )
{
void * V_5 = ( void * ) ( long ) V_23 -> V_5 ;
void * V_24 = ( void * ) ( long ) V_23 -> V_24 ;
struct V_13 * V_66 = V_24 ;
T_7 V_18 ;
if ( V_66 + 1 > V_5 )
return V_33 ;
V_18 = V_66 -> V_18 ;
if ( V_18 == F_8 ( V_41 ) )
return F_5 ( V_23 ) ;
else if ( V_18 == F_8 ( V_61 ) )
return F_9 ( V_23 ) ;
else
return V_40 ;
}
