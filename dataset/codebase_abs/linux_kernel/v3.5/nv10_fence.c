static int
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_6 = F_2 ( V_4 , 2 ) ;
if ( V_6 == 0 ) {
F_3 ( V_4 , 0 , V_7 , 1 ) ;
F_4 ( V_4 , V_2 -> V_8 ) ;
F_5 ( V_4 ) ;
}
return V_6 ;
}
static int
F_6 ( struct V_1 * V_2 ,
struct V_3 * V_9 , struct V_3 * V_4 )
{
return - V_10 ;
}
static int
F_7 ( struct V_1 * V_2 ,
struct V_3 * V_9 , struct V_3 * V_4 )
{
struct V_11 * V_12 = F_8 ( V_4 -> V_13 , V_14 ) ;
T_1 V_15 ;
int V_6 ;
if ( ! F_9 ( & V_9 -> V_16 ) )
return - V_17 ;
F_10 ( & V_12 -> V_18 ) ;
V_15 = V_12 -> V_8 ;
V_12 -> V_8 += 2 ;
F_11 ( & V_12 -> V_18 ) ;
V_6 = F_2 ( V_9 , 5 ) ;
if ( ! V_6 ) {
F_3 ( V_9 , 0 , V_19 , 4 ) ;
F_4 ( V_9 , V_20 ) ;
F_4 ( V_9 , 0 ) ;
F_4 ( V_9 , V_15 + 0 ) ;
F_4 ( V_9 , V_15 + 1 ) ;
F_5 ( V_9 ) ;
}
if ( ! V_6 && ! ( V_6 = F_2 ( V_4 , 5 ) ) ) {
F_3 ( V_4 , 0 , V_19 , 4 ) ;
F_4 ( V_4 , V_20 ) ;
F_4 ( V_4 , 0 ) ;
F_4 ( V_4 , V_15 + 1 ) ;
F_4 ( V_4 , V_15 + 2 ) ;
F_5 ( V_4 ) ;
}
F_12 ( & V_9 -> V_16 ) ;
return 0 ;
}
static T_1
F_13 ( struct V_3 * V_4 )
{
return F_14 ( V_4 , 0x0048 ) ;
}
static void
F_15 ( struct V_3 * V_4 , int V_21 )
{
struct V_22 * V_23 = V_4 -> V_24 [ V_21 ] ;
F_16 ( & V_23 -> V_25 ) ;
V_4 -> V_24 [ V_21 ] = NULL ;
F_17 ( V_23 ) ;
}
static int
F_18 ( struct V_3 * V_4 , int V_21 )
{
struct V_11 * V_12 = F_8 ( V_4 -> V_13 , V_21 ) ;
struct V_22 * V_23 ;
struct V_26 * V_27 ;
int V_6 = 0 ;
V_23 = V_4 -> V_24 [ V_21 ] = F_19 ( sizeof( * V_23 ) , V_28 ) ;
if ( ! V_23 )
return - V_29 ;
F_20 ( & V_23 -> V_25 ) ;
if ( V_12 -> V_30 ) {
struct V_31 * V_32 = & V_12 -> V_30 -> V_30 . V_32 ;
V_6 = F_21 ( V_4 , V_33 ,
V_32 -> V_34 * V_35 , V_32 -> V_36 ,
V_37 ,
V_38 , & V_27 ) ;
if ( ! V_6 ) {
V_6 = F_22 ( V_4 , V_20 , V_27 ) ;
F_23 ( NULL , & V_27 ) ;
}
}
if ( V_6 )
F_15 ( V_4 , V_21 ) ;
return V_6 ;
}
static int
F_24 ( struct V_39 * V_13 , int V_21 , bool V_40 )
{
return 0 ;
}
static int
F_25 ( struct V_39 * V_13 , int V_21 )
{
return 0 ;
}
static void
F_26 ( struct V_39 * V_13 , int V_21 )
{
struct V_41 * V_42 = V_13 -> V_43 ;
struct V_11 * V_12 = F_8 ( V_13 , V_21 ) ;
F_27 ( NULL , & V_12 -> V_30 ) ;
V_42 -> V_44 [ V_21 ] = NULL ;
F_17 ( V_12 ) ;
}
int
F_28 ( struct V_39 * V_13 )
{
struct V_41 * V_42 = V_13 -> V_43 ;
struct V_11 * V_12 ;
int V_6 = 0 ;
V_12 = F_19 ( sizeof( * V_12 ) , V_28 ) ;
if ( ! V_12 )
return - V_29 ;
V_12 -> V_25 . V_21 . V_45 = F_26 ;
V_12 -> V_25 . V_21 . V_46 = F_25 ;
V_12 -> V_25 . V_21 . V_47 = F_24 ;
V_12 -> V_25 . V_21 . V_48 = F_18 ;
V_12 -> V_25 . V_21 . V_49 = F_15 ;
V_12 -> V_25 . V_50 = F_1 ;
V_12 -> V_25 . V_51 = F_13 ;
V_12 -> V_25 . V_52 = F_6 ;
V_42 -> V_44 [ V_14 ] = & V_12 -> V_25 . V_21 ;
F_29 ( & V_12 -> V_18 ) ;
if ( V_42 -> V_53 >= 0x17 ) {
V_6 = F_30 ( V_13 , 4096 , 0x1000 , V_54 ,
0 , 0x0000 , NULL , & V_12 -> V_30 ) ;
if ( ! V_6 ) {
V_6 = F_31 ( V_12 -> V_30 , V_54 ) ;
if ( ! V_6 )
V_6 = F_32 ( V_12 -> V_30 ) ;
if ( V_6 )
F_27 ( NULL , & V_12 -> V_30 ) ;
}
if ( V_6 == 0 ) {
F_33 ( V_12 -> V_30 , 0x000 , 0x00000000 ) ;
V_12 -> V_25 . V_52 = F_7 ;
}
}
if ( V_6 )
F_26 ( V_13 , V_14 ) ;
return V_6 ;
}
