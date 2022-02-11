int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_3 * V_5 )
{
V_4 -> V_6 = sizeof( V_7 ) * V_2 -> V_8 . V_9 ;
V_4 -> V_10 = F_2 ( V_2 -> V_11 ,
V_4 -> V_6 * V_12 ,
& V_4 -> V_13 , V_14 ) ;
if ( ! V_4 -> V_10 )
return - V_15 ;
V_4 -> V_16 = V_4 -> V_10 ;
V_4 -> V_17 = V_4 -> V_10 + V_4 -> V_6 * V_12 ;
V_4 -> V_18 = V_4 -> V_10 ;
V_5 -> V_6 = sizeof( V_7 ) * V_2 -> V_8 . V_19 ;
V_5 -> V_10 = F_2 ( V_2 -> V_11 ,
V_5 -> V_6 * V_12 ,
& V_5 -> V_13 , V_14 ) ;
if ( ! V_5 -> V_10 )
return - V_15 ;
V_5 -> V_16 = V_5 -> V_10 ;
V_5 -> V_17 = V_5 -> V_10 + V_5 -> V_6 * V_12 ;
V_5 -> V_18 = V_5 -> V_10 ;
return 0 ;
}
inline int F_3 ( struct V_1 * V_2 )
{
return ( F_4 ( & V_2 -> V_20 ) % V_2 -> V_8 . V_21 ) ;
}
static void * F_5 ( struct V_1 * V_2 ,
struct V_3 * V_22 )
{
void * V_23 = V_22 -> V_16 ;
if ( V_22 -> V_24 == V_12 - 1 )
return F_6 ( - V_15 ) ;
V_22 -> V_16 += V_22 -> V_6 ;
if ( V_22 -> V_16 == V_22 -> V_17 )
V_22 -> V_16 = V_22 -> V_10 ;
V_22 -> V_24 ++ ;
return V_23 ;
}
void * F_7 ( struct V_1 * V_2 ,
struct V_3 * V_22 )
{
void * V_23 = V_22 -> V_18 ;
if ( ! V_22 -> V_24 )
return F_6 ( - V_25 ) ;
V_22 -> V_18 += V_22 -> V_6 ;
if ( V_22 -> V_18 == V_22 -> V_17 )
V_22 -> V_18 = V_22 -> V_10 ;
V_22 -> V_24 -- ;
return V_23 ;
}
void F_8 ( struct V_1 * V_2 ,
struct V_3 * V_22 )
{
if ( ! V_22 -> V_24 )
return;
if ( V_22 -> V_16 == V_22 -> V_10 )
V_22 -> V_16 = V_22 -> V_17 - V_22 -> V_6 ;
else
V_22 -> V_16 -= V_22 -> V_6 ;
V_22 -> V_24 -- ;
}
struct V_26 * F_9 ( struct V_1 * V_2 ,
int V_27 ,
bool V_28 , bool V_29 ,
T_1 V_30 , V_7 V_31 ,
V_7 V_32 ,
T_1 V_33 ) {
struct V_26 * V_34 ;
int V_35 ;
V_34 = F_5 ( V_2 , & V_2 -> V_22 [ V_27 ] . V_4 ) ;
if ( F_10 ( V_34 ) )
return V_34 ;
memset ( V_34 , 0 , sizeof( struct V_26 ) ) ;
V_34 -> V_36 = V_28 ;
V_34 -> V_37 = V_29 ;
V_34 -> V_38 = V_31 ;
V_34 -> V_39 = F_11 ( V_30 ) ;
V_34 -> V_40 = F_12 ( V_30 ) ;
if ( V_28 && V_33 ) {
struct V_41 * V_42 =
(struct V_41 * ) V_34 -> V_43 . V_42 ;
V_34 -> V_43 . V_44 = V_32 ;
V_34 -> V_43 . V_45 = V_46 |
V_47 |
V_48 ;
V_34 -> V_43 . V_49 =
( F_11 ( V_33 ) & F_13 ( 31 , 2 ) ) >> 2 ;
V_34 -> V_43 . V_50 = F_12 ( V_33 ) ;
V_34 -> V_43 . V_51 = 2 ;
for ( V_35 = 0 ; V_35 < V_52 ; V_35 ++ )
F_14 ( & V_42 [ V_35 ] ) ;
}
return V_34 ;
}
struct V_53 * F_15 ( struct V_1 * V_2 ,
int V_27 ,
bool V_28 , bool V_29 ,
T_1 V_30 , V_7 V_54 )
{
struct V_53 * V_55 ;
V_55 = F_5 ( V_2 , & V_2 -> V_22 [ V_27 ] . V_5 ) ;
if ( F_10 ( V_55 ) )
return V_55 ;
memset ( V_55 , 0 , sizeof( struct V_53 ) ) ;
V_55 -> V_36 = V_28 ;
V_55 -> V_37 = V_29 ;
V_55 -> V_38 = V_54 ;
V_55 -> V_39 = F_11 ( V_30 ) ;
V_55 -> V_40 = F_12 ( V_30 ) ;
return V_55 ;
}
