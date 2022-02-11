static T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_5 ;
}
static void F_3 ( struct V_1 * V_2 , T_1 V_6 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_4 -> V_5 = V_6 ;
}
static int F_4 ( struct V_1 * V_2 , int V_7 )
{
switch ( V_7 ) {
case V_8 :
return V_9 ;
default:
return - V_10 ;
}
}
static void F_5 ( struct V_1 * V_2 , T_1 V_11 , T_2 * V_6 )
{
unsigned int V_12 ;
switch ( V_11 ) {
case V_8 :
for ( V_12 = 0 ; V_12 < V_9 ; V_12 ++ ) {
F_6 ( V_6 , V_13 [ V_12 ] ,
V_14 ) ;
V_6 += V_14 ;
}
break;
}
}
static void F_7 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
T_3 * V_6 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_8 ( & V_4 -> V_16 . V_17 ) ;
F_9 ( V_4 ) ;
memcpy ( V_6 , & V_4 -> V_16 , V_9 * sizeof( T_3 ) ) ;
F_10 ( & V_4 -> V_16 . V_17 ) ;
}
static int F_11 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = V_2 -> V_19 ;
if ( ! V_19 )
return - V_20 ;
return F_12 ( V_19 ) ;
}
static void F_13 ( struct V_1 * V_2 ,
struct V_21 * V_22 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_22 -> V_23 = V_24 ;
V_22 -> V_25 = V_26 ;
V_22 -> V_27 = V_4 -> V_28 ;
V_22 -> V_29 = V_4 -> V_30 ;
}
static int F_14 ( struct V_1 * V_2 ,
struct V_21 * V_22 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_22 -> V_31 || V_22 -> V_32 )
return - V_33 ;
V_4 -> V_30 =
F_15 ( V_22 -> V_29 , V_34 , V_26 ) ;
V_4 -> V_28 =
F_15 ( V_22 -> V_27 , V_35 , V_24 ) ;
if ( F_16 ( V_2 ) )
return F_17 ( V_4 ) ;
return 0 ;
}
static void F_18 ( struct V_1 * V_2 ,
struct V_36 * V_37 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_37 -> V_38 = V_4 -> V_39 ? V_40 : V_41 ;
V_37 -> V_42 = V_4 -> V_43 ? 1 : 0 ;
V_37 -> V_44 = V_4 -> V_45 ? 1 : 0 ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_36 * V_37 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_4 -> V_39 = V_37 -> V_38 == V_40 ;
V_4 -> V_43 = V_37 -> V_42 != 0 ;
V_4 -> V_45 = V_37 -> V_44 != 0 ;
if ( F_16 ( V_2 ) )
return F_17 ( V_4 ) ;
return 0 ;
}
static void F_20 ( struct V_1 * V_2 ,
struct V_46 * V_47 , void * V_48 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 * V_49 = V_48 ;
unsigned int V_12 ;
V_47 -> V_50 = V_51 ;
V_47 -> V_52 = V_53 * sizeof( T_1 ) ;
for ( V_12 = 0 ; V_12 < V_53 ; V_12 ++ )
V_49 [ V_12 ] = F_21 ( V_4 -> V_54 + V_55 [ V_12 ] ) ;
}
static int F_22 ( struct V_1 * V_2 )
{
return V_53 * sizeof( T_1 ) ;
}
void F_23 ( struct V_1 * V_2 )
{
V_2 -> V_56 = & V_57 ;
}
