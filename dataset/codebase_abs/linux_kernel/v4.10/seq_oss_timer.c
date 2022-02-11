struct V_1 *
F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
V_4 = F_2 ( sizeof( * V_4 ) , V_5 ) ;
if ( V_4 == NULL )
return NULL ;
V_4 -> V_3 = V_3 ;
V_4 -> V_6 = 0 ;
V_4 -> V_7 = 0 ;
V_4 -> V_8 = 0 ;
V_4 -> V_9 = 60 ;
V_4 -> V_10 = 100 ;
F_3 ( V_4 ) ;
return V_4 ;
}
void
F_4 ( struct V_1 * V_4 )
{
if ( V_4 ) {
F_5 ( V_4 ) ;
F_6 ( V_4 ) ;
}
}
int
F_7 ( struct V_1 * V_4 , union V_11 * V_12 )
{
T_1 V_13 = V_12 -> V_14 . time ;
if ( V_12 -> V_14 . V_15 == V_16 ) {
switch ( V_12 -> V_14 . V_17 ) {
case V_18 :
V_13 += V_4 -> V_6 ;
V_4 -> V_7 = 0 ;
case V_19 :
if ( V_13 == 0 ) {
V_4 -> V_7 = 1 ;
} else if ( V_13 >= V_4 -> V_6 ) {
V_4 -> V_7 = 0 ;
V_4 -> V_6 = V_13 ;
}
return 1 ;
case V_20 :
F_8 ( V_4 ) ;
return 1 ;
}
} else if ( V_12 -> V_21 . V_15 == V_22 ) {
V_13 = ( V_12 -> V_23 >> 8 ) & 0xffffff ;
if ( V_13 > V_4 -> V_6 ) {
V_4 -> V_6 = V_13 ;
V_4 -> V_7 = 0 ;
}
return 1 ;
}
return 0 ;
}
static void
F_3 ( struct V_1 * V_24 )
{
V_24 -> V_25 = ( 60 * 1000000 ) / V_24 -> V_9 ;
V_24 -> V_26 = V_24 -> V_10 ;
}
static int
F_9 ( struct V_2 * V_3 , int type , int V_27 )
{
struct V_28 V_12 ;
memset ( & V_12 , 0 , sizeof( V_12 ) ) ;
V_12 . type = type ;
V_12 . V_29 . V_30 = V_3 -> V_31 ;
V_12 . V_29 . V_32 = 0 ;
V_12 . V_33 . V_30 = V_34 ;
V_12 . V_33 . V_32 = V_35 ;
V_12 . V_36 = V_3 -> V_36 ;
V_12 . V_37 . V_36 . V_36 = V_3 -> V_36 ;
V_12 . V_37 . V_36 . V_38 . V_27 = V_27 ;
return F_10 ( V_3 -> V_31 , & V_12 , 1 , 0 ) ;
}
int
F_8 ( struct V_1 * V_24 )
{
struct V_2 * V_3 = V_24 -> V_3 ;
struct V_39 V_40 ;
if ( V_24 -> V_8 )
F_5 ( V_24 ) ;
memset ( & V_40 , 0 , sizeof( V_40 ) ) ;
V_40 . V_36 = V_3 -> V_36 ;
V_40 . V_26 = V_24 -> V_26 ;
V_40 . V_25 = V_24 -> V_25 ;
F_11 ( V_3 -> V_31 , & V_40 ) ;
F_9 ( V_3 , V_41 , 0 ) ;
V_24 -> V_8 = 1 ;
V_24 -> V_6 = 0 ;
return 0 ;
}
int
F_5 ( struct V_1 * V_24 )
{
if ( ! V_24 -> V_8 )
return 0 ;
F_9 ( V_24 -> V_3 , V_42 , 0 ) ;
V_24 -> V_8 = 0 ;
return 0 ;
}
int
F_12 ( struct V_1 * V_24 )
{
if ( V_24 -> V_8 )
return 0 ;
F_9 ( V_24 -> V_3 , V_43 , 0 ) ;
V_24 -> V_8 = 1 ;
return 0 ;
}
int
F_13 ( struct V_1 * V_24 , int V_27 )
{
if ( V_27 < V_44 )
V_27 = V_44 ;
else if ( V_27 > V_45 )
V_27 = V_45 ;
V_24 -> V_9 = V_27 ;
F_3 ( V_24 ) ;
if ( V_24 -> V_8 )
F_9 ( V_24 -> V_3 , V_46 , V_24 -> V_25 ) ;
return 0 ;
}
int
F_14 ( struct V_1 * V_24 , unsigned int V_17 , int T_2 * V_47 )
{
int V_27 ;
if ( V_17 == V_48 ) {
if ( F_15 ( V_27 , V_47 ) )
return - V_49 ;
if ( V_27 )
return - V_50 ;
V_27 = ( ( V_24 -> V_9 * V_24 -> V_10 ) + 30 ) / 60 ;
return F_16 ( V_27 , V_47 ) ? - V_49 : 0 ;
}
if ( V_24 -> V_3 -> V_51 == V_52 )
return 0 ;
switch ( V_17 ) {
case V_53 :
return F_8 ( V_24 ) ;
case V_54 :
return F_5 ( V_24 ) ;
case V_55 :
return F_12 ( V_24 ) ;
case V_56 :
if ( F_15 ( V_27 , V_47 ) )
return - V_49 ;
return F_13 ( V_24 , V_27 ) ;
case V_57 :
if ( F_15 ( V_27 , V_47 ) )
return - V_49 ;
if ( V_27 < V_58 )
V_27 = V_58 ;
else if ( V_27 > V_59 )
V_27 = V_59 ;
V_24 -> V_10 = V_27 ;
F_3 ( V_24 ) ;
return 0 ;
case V_60 :
case V_61 :
case V_62 :
return 0 ;
}
return 0 ;
}
