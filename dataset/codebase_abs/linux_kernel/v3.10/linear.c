static inline void F_1 ( struct V_1 * V_2 ,
unsigned char * V_3 , unsigned char * V_4 )
{
unsigned int V_5 = 0 ;
unsigned char * V_6 = ( unsigned char * ) & V_5 ;
memcpy ( V_6 + V_2 -> V_7 , V_4 + V_2 -> V_8 , V_2 -> V_9 ) ;
if ( V_2 -> V_10 )
V_5 = F_2 ( V_5 ) ;
V_5 ^= V_2 -> V_11 ;
memcpy ( V_3 , V_6 + V_2 -> V_12 , V_2 -> V_13 ) ;
}
static void F_3 ( struct V_14 * V_15 ,
const struct V_16 * V_17 ,
struct V_16 * V_18 ,
T_1 V_19 )
{
struct V_1 * V_2 = (struct V_1 * ) V_15 -> V_20 ;
int V_21 ;
int V_22 = V_15 -> V_23 . V_24 ;
for ( V_21 = 0 ; V_21 < V_22 ; ++ V_21 ) {
char * V_4 ;
char * V_3 ;
int V_25 , V_26 ;
T_1 V_27 ;
if ( ! V_17 [ V_21 ] . V_28 ) {
if ( V_18 [ V_21 ] . V_29 )
F_4 ( & V_18 [ V_21 ] . V_30 , 0 , V_19 , V_15 -> V_31 . V_32 ) ;
V_18 [ V_21 ] . V_28 = 0 ;
continue;
}
V_18 [ V_21 ] . V_28 = 1 ;
V_4 = V_17 [ V_21 ] . V_30 . V_33 + V_17 [ V_21 ] . V_30 . V_34 / 8 ;
V_3 = V_18 [ V_21 ] . V_30 . V_33 + V_18 [ V_21 ] . V_30 . V_34 / 8 ;
V_25 = V_17 [ V_21 ] . V_30 . V_35 / 8 ;
V_26 = V_18 [ V_21 ] . V_30 . V_35 / 8 ;
V_27 = V_19 ;
while ( V_27 -- > 0 ) {
F_1 ( V_2 , V_3 , V_4 ) ;
V_4 += V_25 ;
V_3 += V_26 ;
}
}
}
static T_2 F_5 ( struct V_14 * V_15 ,
const struct V_16 * V_17 ,
struct V_16 * V_18 ,
T_1 V_19 )
{
if ( F_6 ( ! V_15 || ! V_17 || ! V_18 ) )
return - V_36 ;
if ( V_19 == 0 )
return 0 ;
#ifdef F_7
{
unsigned int V_21 ;
for ( V_21 = 0 ; V_21 < V_15 -> V_23 . V_24 ; V_21 ++ ) {
if ( F_6 ( V_17 [ V_21 ] . V_30 . V_34 % 8 ||
V_17 [ V_21 ] . V_30 . V_35 % 8 ) )
return - V_36 ;
if ( F_6 ( V_18 [ V_21 ] . V_30 . V_34 % 8 ||
V_18 [ V_21 ] . V_30 . V_35 % 8 ) )
return - V_36 ;
}
}
#endif
F_3 ( V_15 , V_17 , V_18 , V_19 ) ;
return V_19 ;
}
static void F_8 ( struct V_1 * V_2 ,
T_3 V_23 , T_3 V_31 )
{
int V_37 , V_38 , V_39 , V_13 ;
V_39 = F_9 ( V_23 ) / 8 ;
V_13 = F_9 ( V_31 ) / 8 ;
V_37 = F_10 ( V_23 ) > 0 ;
V_38 = F_10 ( V_31 ) > 0 ;
V_2 -> V_13 = V_13 ;
V_2 -> V_10 = V_37 != V_38 ;
V_2 -> V_9 = V_39 < V_13 ? V_39 : V_13 ;
if ( V_37 ) {
V_2 -> V_7 = 4 - V_2 -> V_9 ;
V_2 -> V_8 = V_39 - V_2 -> V_9 ;
} else
V_2 -> V_8 = F_11 ( V_23 ) / 8 -
V_39 ;
if ( V_38 )
V_2 -> V_12 = 4 - V_2 -> V_13 ;
else
V_2 -> V_12 = F_11 ( V_31 ) / 8 -
V_13 ;
if ( F_12 ( V_23 ) !=
F_12 ( V_31 ) ) {
if ( V_38 )
V_2 -> V_11 = ( V_40 V_41 ) F_13 ( 0x80000000 ) ;
else
V_2 -> V_11 = ( V_40 V_41 ) F_14 ( 0x80000000 ) ;
}
}
int F_15 ( struct V_42 * V_43 ,
struct V_44 * V_23 ,
struct V_44 * V_31 ,
struct V_14 * * V_45 )
{
int V_46 ;
struct V_1 * V_2 ;
struct V_14 * V_15 ;
if ( F_6 ( ! V_45 ) )
return - V_36 ;
* V_45 = NULL ;
if ( F_6 ( V_23 -> V_47 != V_31 -> V_47 ) )
return - V_36 ;
if ( F_6 ( V_23 -> V_24 != V_31 -> V_24 ) )
return - V_36 ;
if ( F_6 ( ! F_16 ( V_23 -> V_32 ) ||
! F_16 ( V_31 -> V_32 ) ) )
return - V_36 ;
V_46 = F_17 ( V_43 , L_1 ,
V_23 , V_31 ,
sizeof( struct V_1 ) , & V_15 ) ;
if ( V_46 < 0 )
return V_46 ;
V_2 = (struct V_1 * ) V_15 -> V_20 ;
F_8 ( V_2 , V_23 -> V_32 , V_31 -> V_32 ) ;
V_15 -> V_48 = F_5 ;
* V_45 = V_15 ;
return 0 ;
}
