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
return 1 ;
case V_9 :
return V_10 ;
default:
return - V_11 ;
}
}
static void F_5 ( struct V_1 * V_2 , T_1 V_12 , T_2 * V_6 )
{
unsigned int V_13 ;
switch ( V_12 ) {
case V_8 :
strcpy ( V_6 , L_1 ) ;
break;
case V_9 :
for ( V_13 = 0 ; V_13 < V_10 ; V_13 ++ ) {
F_6 ( V_6 , V_14 [ V_13 ] ,
V_15 ) ;
V_6 += V_15 ;
}
break;
}
}
static void F_7 ( struct V_1 * V_2 ,
struct V_16 * V_17 ,
T_3 * V_6 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_8 ( & V_4 -> V_17 . V_18 ) ;
F_9 ( V_4 ) ;
memcpy ( V_6 , & V_4 -> V_17 , V_10 * sizeof( T_3 ) ) ;
F_10 ( & V_4 -> V_17 . V_18 ) ;
}
static int F_11 ( struct V_1 * V_2 )
{
struct V_19 * V_20 = V_2 -> V_20 ;
if ( ! V_20 )
return - V_21 ;
return F_12 ( V_20 ) ;
}
static void F_13 ( struct V_1 * V_2 ,
struct V_22 * V_23 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_23 -> V_24 = V_25 ;
V_23 -> V_26 = V_27 ;
V_23 -> V_28 = V_4 -> V_29 ;
V_23 -> V_30 = V_4 -> V_31 ;
}
static int F_14 ( struct V_1 * V_2 ,
struct V_22 * V_23 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_23 -> V_32 || V_23 -> V_33 )
return - V_34 ;
V_4 -> V_31 =
F_15 ( V_23 -> V_30 , V_35 , V_27 ) ;
V_4 -> V_29 =
F_15 ( V_23 -> V_28 , V_36 , V_25 ) ;
if ( F_16 ( V_2 ) )
return F_17 ( V_4 ) ;
return 0 ;
}
static void F_18 ( struct V_1 * V_2 ,
struct V_37 * V_38 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_38 -> V_39 = V_4 -> V_40 ? V_41 : V_42 ;
V_38 -> V_43 = V_4 -> V_44 ? 1 : 0 ;
V_38 -> V_45 = V_4 -> V_46 ? 1 : 0 ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_37 * V_38 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_4 -> V_40 = V_38 -> V_39 == V_41 ;
V_4 -> V_44 = V_38 -> V_43 != 0 ;
V_4 -> V_46 = V_38 -> V_45 != 0 ;
if ( F_16 ( V_2 ) )
return F_17 ( V_4 ) ;
return 0 ;
}
static void F_20 ( struct V_1 * V_2 ,
struct V_47 * V_48 , void * V_49 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 * V_50 = V_49 ;
unsigned int V_13 ;
V_48 -> V_51 = V_52 ;
V_48 -> V_53 = V_54 * sizeof( T_1 ) ;
for ( V_13 = 0 ; V_13 < V_54 ; V_13 ++ )
V_50 [ V_13 ] = F_21 ( V_4 -> V_55 + V_56 [ V_13 ] ) ;
}
static int F_22 ( struct V_1 * V_2 )
{
return V_54 * sizeof( T_1 ) ;
}
static int F_23 ( struct V_1 * V_2 , T_1 V_57 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_4 -> V_58 = ! ! ( V_57 & V_59 ) ;
if ( F_16 ( V_2 ) )
return F_17 ( V_4 ) ;
return 0 ;
}
static T_1 F_24 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_58 ? V_59 : 0 ;
}
void F_25 ( struct V_1 * V_2 )
{
V_2 -> V_60 = & V_61 ;
}
