static bool F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
return ( V_3 == V_4 ) ? true : false ;
}
static int F_2 ( struct V_5 * V_6 , unsigned int V_7 )
{
struct V_8 * V_9 = F_3 ( V_6 ) ;
unsigned int V_10 ;
int V_11 ;
V_11 = F_4 ( V_9 -> V_12 , V_4 , & V_10 ) ;
if ( V_11 < 0 )
return V_11 ;
return ! ! ( V_10 & F_5 ( 1 - V_7 ) ) ;
}
static void F_6 ( struct V_5 * V_6 , unsigned int V_7 ,
int V_13 )
{
struct V_8 * V_9 = F_3 ( V_6 ) ;
F_7 ( V_9 -> V_12 , V_4 , F_5 ( 5 - V_7 ) ,
V_13 ? F_5 ( 5 - V_7 ) : 0 ) ;
}
static int F_8 ( struct V_5 * V_6 ,
unsigned int V_7 )
{
struct V_8 * V_9 = F_3 ( V_6 ) ;
unsigned int V_10 ;
int V_11 ;
V_11 = F_4 ( V_9 -> V_12 , V_14 , & V_10 ) ;
if ( V_11 < 0 )
return V_11 ;
return ! ! ( V_10 & F_5 ( 7 - V_7 ) ) ;
}
static int F_9 ( struct V_5 * V_6 ,
unsigned int V_7 )
{
struct V_8 * V_9 = F_3 ( V_6 ) ;
return F_7 ( V_9 -> V_12 , V_14 ,
F_5 ( 7 - V_7 ) , F_5 ( 7 - V_7 ) ) ;
}
static int F_10 ( struct V_5 * V_6 ,
unsigned int V_7 , int V_13 )
{
struct V_8 * V_9 = F_3 ( V_6 ) ;
F_6 ( V_6 , V_7 , V_13 ) ;
return F_7 ( V_9 -> V_12 , V_14 ,
F_5 ( 7 - V_7 ) , 0 ) ;
}
static int F_11 ( struct V_5 * V_6 ,
unsigned int V_7 , unsigned long V_15 )
{
struct V_8 * V_9 = F_3 ( V_6 ) ;
unsigned int V_10 ;
switch ( F_12 ( V_15 ) ) {
case V_16 :
V_10 = 0 ;
break;
case V_17 :
V_10 = F_5 ( 4 - V_7 ) ;
break;
default:
return - V_18 ;
}
return F_7 ( V_9 -> V_12 , V_14 ,
F_5 ( 4 - V_7 ) , V_10 ) ;
}
static int F_13 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_14 ( V_9 -> V_12 ) ;
if ( ! V_9 -> V_6 -> V_19 )
return 0 ;
V_9 -> V_20 . V_21 = F_15 ( V_2 ) ;
V_9 -> V_20 . V_22 = - 1 ;
V_9 -> V_20 . V_23 = V_9 -> V_6 -> V_19 ;
V_9 -> V_20 . V_24 = V_2 ;
V_9 -> V_20 . V_25 = true ;
V_9 -> V_20 . V_26 = F_8 ;
V_9 -> V_20 . V_27 = F_9 ;
V_9 -> V_20 . V_28 = F_10 ;
V_9 -> V_20 . V_29 = F_2 ;
V_9 -> V_20 . V_30 = F_6 ;
V_9 -> V_20 . V_31 = F_11 ;
V_9 -> V_20 . V_32 = V_33 ;
F_16 ( V_9 -> V_12 , V_14 , V_34 ) ;
return F_17 ( V_2 , & V_9 -> V_20 , V_9 ) ;
}
static int F_18 ( struct V_35 * V_36 , T_1 V_37 )
{
struct V_8 * V_9 = F_19 ( V_36 ) ;
return F_7 ( V_9 -> V_12 , V_38 ,
V_39 , F_5 ( 7 - V_37 ) ) ;
}
static int F_20 ( struct V_35 * V_36 , T_1 V_37 )
{
struct V_8 * V_9 = F_19 ( V_36 ) ;
return F_7 ( V_9 -> V_12 , V_38 ,
V_39 , 0 ) ;
}
static int F_21 ( struct V_40 * V_41 ,
const struct V_42 * V_43 )
{
struct V_44 * V_45 = F_22 ( V_41 -> V_2 . V_24 ) ;
const struct V_46 * V_6 ;
struct V_35 * V_36 ;
struct V_8 * V_9 ;
struct V_47 * V_48 ;
bool V_49 ;
unsigned int V_10 = 0 ;
int V_50 , V_11 ;
V_6 = F_23 ( & V_41 -> V_2 ) ;
if ( ! V_6 )
V_6 = & V_51 [ V_43 -> V_52 ] ;
V_49 = F_24 ( & V_41 -> V_2 ,
L_1 ) ;
V_36 = F_25 ( V_45 , & V_41 -> V_2 ,
V_6 -> V_53 , sizeof( * V_9 ) ,
V_54 , F_18 ,
V_49 ? F_20 : NULL ) ;
if ( ! V_36 )
return - V_55 ;
V_9 = F_19 ( V_36 ) ;
V_9 -> V_6 = V_6 ;
F_26 ( V_41 , V_36 ) ;
V_9 -> V_12 = F_27 ( V_41 , & V_56 ) ;
if ( F_28 ( V_9 -> V_12 ) ) {
V_11 = F_29 ( V_9 -> V_12 ) ;
F_30 ( & V_41 -> V_2 , L_2 ,
V_11 ) ;
return V_11 ;
}
V_48 = F_31 ( & V_41 -> V_2 , L_3 , V_57 ) ;
if ( F_28 ( V_48 ) )
return F_29 ( V_48 ) ;
if ( V_48 ) {
F_32 ( 1 ) ;
F_33 ( V_48 , 1 ) ;
}
if ( F_16 ( V_9 -> V_12 , V_38 , 0 ) < 0 ) {
F_34 ( & V_41 -> V_2 , L_4 ) ;
return - V_58 ;
}
if ( F_24 ( & V_41 -> V_2 ,
L_5 ) )
V_10 |= V_59 ;
if ( F_24 ( & V_41 -> V_2 ,
L_6 ) )
V_10 |= V_60 ;
if ( F_16 ( V_9 -> V_12 , V_4 , V_10 ) < 0 )
return - V_58 ;
V_11 = F_13 ( V_9 ) ;
if ( V_11 < 0 )
return V_11 ;
for ( V_50 = 0 ; V_50 < V_6 -> V_53 ; V_50 ++ ) {
V_11 = F_35 ( V_36 , 0 , V_50 , 0 ) ;
if ( V_11 ) {
F_36 ( V_36 ) ;
return V_11 ;
}
}
F_37 ( & V_41 -> V_2 ,
L_7 ,
V_50 , V_41 -> V_61 ) ;
return 0 ;
}
static int F_38 ( struct V_40 * V_41 )
{
struct V_35 * V_36 = F_39 ( V_41 ) ;
F_36 ( V_36 ) ;
return 0 ;
}
