static inline unsigned int F_1 ( T_1 V_1 )
{
unsigned int V_2 , V_3 ;
V_1 -= V_4 ;
V_2 = V_1 / V_5 + 1 ;
V_3 = V_1 % V_5 ;
return V_3 * 4 + V_2 * V_6
+ V_7 ;
}
static inline void F_2 ( T_1 V_1 ,
T_2 * V_8 , T_2 * V_9 )
{
unsigned int V_2 , V_10 , V_11 ;
V_1 -= V_4 ;
V_2 = V_1 / V_5 + 1 ;
V_10 = V_1 % V_5 ;
* V_8 = 1 << ( V_10 % 32 ) ;
V_11 = V_10 / 32 * 4 ;
* V_9 = V_11 + V_2 * V_6
+ V_12 ;
}
static inline void F_3 ( T_1 V_1 ,
T_2 * V_8 , T_2 * V_9 )
{
unsigned int V_11 ;
V_1 -= V_4 ;
V_11 = V_1 / 32 * 4 ;
* V_8 = 1 << ( V_1 % 32 ) ;
* V_9 = V_11 + V_13 ;
}
static void F_4 ( struct V_14 * V_15 )
{
void T_3 * V_16 = V_15 -> V_17 ;
T_2 V_8 , V_9 ;
F_3 ( V_15 -> V_1 , & V_8 , & V_9 ) ;
F_5 ( V_8 , V_16 + V_9 ) ;
F_6 ( V_15 ) ;
}
static int F_7 ( struct V_14 * V_15 , unsigned int type )
{
void T_3 * V_16 = V_15 -> V_17 ;
T_2 V_8 , V_9 , V_18 ;
if ( type != V_19 && type != V_20 )
return - V_21 ;
F_2 ( V_15 -> V_1 , & V_8 , & V_9 ) ;
V_18 = F_8 ( V_16 + V_9 ) ;
if ( type == V_19 )
V_18 |= V_8 ;
else
V_18 &= ~ V_8 ;
F_5 ( V_18 , V_16 + V_9 ) ;
return 0 ;
}
static void F_9 ( struct V_22 * V_23 , struct V_24 * V_25 )
{
struct V_14 * V_26 = F_10 ( V_23 -> V_27 ) ;
void T_3 * V_16 = V_26 -> V_17 ;
T_2 V_18 ;
V_16 += F_1 ( V_26 -> V_1 ) ;
V_18 = F_8 ( V_16 ) ;
V_18 &= ~ ( V_28 << V_29 ) ;
V_18 |= ( V_25 -> V_15 << V_29 ) ;
F_5 ( V_18 , V_16 ) ;
}
static int F_11 ( struct V_30 * V_26 ,
struct V_31 * V_32 ,
unsigned long * V_1 ,
unsigned int * type )
{
if ( F_12 ( V_32 -> V_33 ) ) {
if ( V_32 -> V_34 != 2 )
return - V_21 ;
if ( ( V_32 -> V_35 [ 0 ] > V_36 ) ||
( V_32 -> V_35 [ 0 ] < V_4 ) )
return - V_21 ;
else
* V_1 = V_32 -> V_35 [ 0 ] ;
if ( ( V_32 -> V_35 [ 1 ] == V_20 ) ||
( V_32 -> V_35 [ 1 ] == V_19 ) )
* type = V_32 -> V_35 [ 1 ] ;
else
return - V_21 ;
return 0 ;
}
return - V_21 ;
}
static int F_13 ( struct V_30 * V_37 ,
unsigned int V_38 ,
unsigned int V_39 ,
void * args )
{
struct V_31 * V_32 = args ;
T_1 V_1 ;
unsigned int type ;
struct V_40 * V_41 ;
int V_42 , V_43 ;
V_43 = F_11 ( V_37 , V_32 , & V_1 , & type ) ;
if ( V_43 )
return V_43 ;
V_43 = F_14 ( V_37 , V_38 , V_39 ) ;
if ( V_43 )
return V_43 ;
V_41 = F_15 ( V_37 ) ;
for ( V_42 = 0 ; V_42 < V_39 ; V_42 ++ )
F_16 ( V_37 , V_38 + V_42 , V_1 + V_42 ,
& V_44 , V_41 -> V_16 ) ;
return 0 ;
}
static int F_17 ( struct V_45 * V_46 )
{
struct V_40 * V_41 ;
struct V_47 * V_48 ;
struct V_30 * V_37 ;
T_2 V_49 ;
V_41 = F_18 ( & V_46 -> V_50 , sizeof( * V_41 ) , V_51 ) ;
if ( ! V_41 )
return - V_52 ;
V_41 -> V_46 = V_46 ;
V_48 = F_19 ( V_46 , V_53 , 0 ) ;
V_41 -> V_16 = F_20 ( & V_46 -> V_50 , V_48 ) ;
if ( F_21 ( V_41 -> V_16 ) )
return F_22 ( V_41 -> V_16 ) ;
if ( F_23 ( V_46 -> V_50 . V_54 , L_1 , & V_49 ) < 0 ) {
F_24 ( & V_46 -> V_50 , L_2 ) ;
return - V_21 ;
}
V_37 = F_25 ( & V_46 -> V_50 , V_49 ,
F_9 ,
& V_55 ,
V_41 ) ;
if ( ! V_37 )
return - V_52 ;
F_26 ( V_46 , V_41 ) ;
F_27 ( & V_46 -> V_50 , L_3 , V_49 ) ;
return 0 ;
}
