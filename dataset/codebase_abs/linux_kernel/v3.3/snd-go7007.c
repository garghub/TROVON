static void F_1 ( struct V_1 * V_2 , T_1 * V_3 , int V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
int V_11 = F_2 ( V_9 , V_4 ) ;
F_3 ( & V_6 -> V_12 ) ;
V_6 -> V_13 += V_11 ;
if ( V_6 -> V_13 >= V_9 -> V_14 )
V_6 -> V_13 -= V_9 -> V_14 ;
V_6 -> V_15 += V_11 ;
F_4 ( & V_6 -> V_12 ) ;
if ( V_6 -> V_16 + V_4 > V_9 -> V_17 ) {
int V_18 = V_9 -> V_17 - V_6 -> V_16 ;
memcpy ( V_9 -> V_19 + V_6 -> V_16 , V_3 , V_18 ) ;
V_4 -= V_18 ;
V_3 += V_18 ;
V_6 -> V_16 = 0 ;
}
memcpy ( V_9 -> V_19 + V_6 -> V_16 , V_3 , V_4 ) ;
V_6 -> V_16 += V_4 ;
F_3 ( & V_6 -> V_12 ) ;
if ( V_6 -> V_15 < V_9 -> V_20 ) {
F_4 ( & V_6 -> V_12 ) ;
return;
}
V_6 -> V_15 -= V_9 -> V_20 ;
F_4 ( & V_6 -> V_12 ) ;
if ( V_6 -> V_21 )
F_5 ( V_6 -> V_10 ) ;
}
static int F_6 ( struct V_22 * V_10 ,
struct V_23 * V_24 )
{
struct V_1 * V_2 = F_7 ( V_10 ) ;
unsigned int V_25 ;
V_25 = F_8 ( V_24 ) ;
if ( V_10 -> V_9 -> V_17 > 0 )
F_9 ( V_10 -> V_9 -> V_19 ) ;
V_10 -> V_9 -> V_17 = 0 ;
V_10 -> V_9 -> V_19 = F_10 ( V_25 ) ;
if ( V_10 -> V_9 -> V_19 == NULL )
return - V_26 ;
V_10 -> V_9 -> V_17 = V_25 ;
V_2 -> V_27 = F_1 ;
return 0 ;
}
static int F_11 ( struct V_22 * V_10 )
{
struct V_1 * V_2 = F_7 ( V_10 ) ;
V_2 -> V_27 = NULL ;
if ( V_10 -> V_9 -> V_17 > 0 )
F_9 ( V_10 -> V_9 -> V_19 ) ;
V_10 -> V_9 -> V_17 = 0 ;
return 0 ;
}
static int F_12 ( struct V_22 * V_10 )
{
struct V_1 * V_2 = F_7 ( V_10 ) ;
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned long V_28 ;
int V_29 ;
F_13 ( & V_6 -> V_12 , V_28 ) ;
if ( V_6 -> V_10 == NULL ) {
V_6 -> V_10 = V_10 ;
V_10 -> V_9 -> V_30 = V_31 ;
V_29 = 0 ;
} else
V_29 = - V_32 ;
F_14 ( & V_6 -> V_12 , V_28 ) ;
return V_29 ;
}
static int F_15 ( struct V_22 * V_10 )
{
struct V_1 * V_2 = F_7 ( V_10 ) ;
struct V_5 * V_6 = V_2 -> V_7 ;
V_6 -> V_10 = NULL ;
return 0 ;
}
static int F_16 ( struct V_22 * V_10 )
{
return 0 ;
}
static int F_17 ( struct V_22 * V_10 , int V_33 )
{
struct V_1 * V_2 = F_7 ( V_10 ) ;
struct V_5 * V_6 = V_2 -> V_7 ;
switch ( V_33 ) {
case V_34 :
V_6 -> V_21 = 1 ;
return 0 ;
case V_35 :
V_6 -> V_13 = V_6 -> V_16 = V_6 -> V_15 = 0 ;
V_6 -> V_21 = 0 ;
return 0 ;
default:
return - V_36 ;
}
}
static T_2 F_18 ( struct V_22 * V_10 )
{
struct V_1 * V_2 = F_7 ( V_10 ) ;
struct V_5 * V_6 = V_2 -> V_7 ;
return V_6 -> V_13 ;
}
static struct V_37 * F_19 ( struct V_22 * V_10 ,
unsigned long V_38 )
{
return F_20 ( V_10 -> V_9 -> V_19 + V_38 ) ;
}
static int F_21 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = V_40 -> V_41 ;
F_22 ( V_2 -> V_7 ) ;
V_2 -> V_7 = NULL ;
if ( -- V_2 -> V_42 == 0 )
F_22 ( V_2 ) ;
return 0 ;
}
int F_23 ( struct V_1 * V_2 )
{
static int V_43 ;
struct V_5 * V_6 ;
int V_44 = 0 ;
if ( V_43 >= V_45 )
return - V_46 ;
if ( ! V_47 [ V_43 ] ) {
V_43 ++ ;
return - V_48 ;
}
V_6 = F_24 ( sizeof( struct V_5 ) , V_49 ) ;
if ( V_6 == NULL )
return - V_26 ;
F_25 ( & V_6 -> V_12 ) ;
V_6 -> V_13 = V_6 -> V_16 = V_6 -> V_15 = 0 ;
V_6 -> V_21 = 0 ;
V_44 = F_26 ( V_50 [ V_43 ] , V_51 [ V_43 ] , V_52 , 0 ,
& V_6 -> V_53 ) ;
if ( V_44 < 0 ) {
F_22 ( V_6 ) ;
return V_44 ;
}
V_44 = F_27 ( V_6 -> V_53 , V_54 , V_2 ,
& V_55 ) ;
if ( V_44 < 0 ) {
F_22 ( V_6 ) ;
return V_44 ;
}
F_28 ( V_6 -> V_53 , V_2 -> V_43 ) ;
V_44 = F_29 ( V_6 -> V_53 , L_1 , 0 , 0 , 1 , & V_6 -> V_56 ) ;
if ( V_44 < 0 ) {
F_30 ( V_6 -> V_53 ) ;
F_22 ( V_6 ) ;
return V_44 ;
}
strncpy ( V_6 -> V_53 -> V_57 , L_1 , sizeof( V_6 -> V_53 -> V_57 ) ) ;
strncpy ( V_6 -> V_53 -> V_58 , V_2 -> V_59 , sizeof( V_6 -> V_53 -> V_57 ) ) ;
strncpy ( V_6 -> V_53 -> V_60 , V_6 -> V_53 -> V_58 ,
sizeof( V_6 -> V_53 -> V_60 ) ) ;
V_6 -> V_56 -> V_61 = V_2 ;
F_31 ( V_6 -> V_56 , V_62 ,
& V_63 ) ;
V_44 = F_32 ( V_6 -> V_53 ) ;
if ( V_44 < 0 ) {
F_30 ( V_6 -> V_53 ) ;
F_22 ( V_6 ) ;
return V_44 ;
}
V_6 -> V_10 = NULL ;
V_2 -> V_7 = V_6 ;
++ V_43 ;
++ V_2 -> V_42 ;
return 0 ;
}
int F_33 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
F_34 ( V_6 -> V_53 ) ;
F_35 ( V_6 -> V_53 ) ;
return 0 ;
}
