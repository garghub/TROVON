static int F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_6 , V_7 ;
F_3 ( & V_5 -> V_8 ) ;
F_4 ( V_5 -> V_9 , V_10 ,
V_11 | V_12
| V_13 ,
F_5 ( V_3 ) | V_13 ) ;
V_7 = F_6 ( V_5 -> V_14 , V_5 -> V_15 ,
F_7 ( 1000 ) ) ;
F_4 ( V_5 -> V_9 , V_16 ,
F_8 ( V_3 ) , 0 ) ;
if ( V_7 == 0 )
V_7 = - V_17 ;
if ( V_7 < 0 ) {
F_9 ( & V_5 -> V_8 ) ;
return V_7 ;
}
F_4 ( V_5 -> V_9 , V_10 ,
V_13 , 0 ) ;
V_6 = V_5 -> V_6 ;
V_5 -> V_15 = false ;
F_9 ( & V_5 -> V_8 ) ;
return V_6 ;
}
static int F_10 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_6 , V_7 ;
F_3 ( & V_5 -> V_8 ) ;
F_4 ( V_5 -> V_9 , V_10 ,
V_18 | V_19 ,
V_19 ) ;
F_4 ( V_5 -> V_9 , V_20 ,
V_21 | V_22
| V_23 ,
F_11 ( 3 ) | V_24
| V_23 ) ;
V_7 = F_6 ( V_5 -> V_14 , V_5 -> V_15 ,
F_7 ( 1000 ) ) ;
F_4 ( V_5 -> V_9 , V_25 ,
V_26 , 0 ) ;
if ( V_7 == 0 )
V_7 = - V_17 ;
if ( V_7 < 0 ) {
F_9 ( & V_5 -> V_8 ) ;
return V_7 ;
}
F_4 ( V_5 -> V_9 , V_20 ,
V_23 , 0 ) ;
V_6 = V_5 -> V_6 ;
V_5 -> V_15 = false ;
F_9 ( & V_5 -> V_8 ) ;
return V_6 ;
}
static int F_12 ( struct V_1 * V_2 ,
struct V_27 const * V_28 , int * V_29 , int * V_30 ,
long V_31 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_32 ;
switch ( V_31 ) {
case V_33 :
if ( V_28 -> type != V_34 )
return - V_35 ;
F_13 ( V_5 -> V_9 , V_16 ,
F_8 ( V_28 -> V_3 ) ) ;
* V_29 = F_1 ( V_2 , V_28 -> V_3 ) ;
if ( * V_29 < 0 )
return * V_29 ;
return V_36 ;
case V_37 :
if ( V_28 -> type != V_38 )
return - V_35 ;
F_13 ( V_5 -> V_9 , V_25 ,
V_26 ) ;
V_32 = F_10 ( V_2 ) ;
if ( V_32 < 0 )
return V_32 ;
if ( V_32 > 2047 )
V_32 -= 4096 ;
* V_29 = ( ( V_32 * 100000 ) / 264 - 270000 ) ;
return V_36 ;
default:
break;
}
return - V_35 ;
}
static T_1 F_14 ( int V_39 , void * V_40 )
{
struct V_4 * V_5 = F_2 ( V_40 ) ;
unsigned V_29 ;
F_15 ( V_5 -> V_9 , V_16 , & V_29 ) ;
if ( V_29 & V_41 ) {
F_15 ( V_5 -> V_9 , V_42 , & V_5 -> V_6 ) ;
V_5 -> V_6 &= V_43 ;
V_29 &= ~ V_41 ;
F_13 ( V_5 -> V_9 , V_16 , V_29 ) ;
V_5 -> V_15 = true ;
F_16 ( & V_5 -> V_14 ) ;
}
return V_44 ;
}
static T_1 F_17 ( int V_39 , void * V_40 )
{
struct V_4 * V_5 = F_2 ( V_40 ) ;
unsigned V_29 ;
F_15 ( V_5 -> V_9 , V_25 , & V_29 ) ;
if ( V_29 & V_45 ) {
F_15 ( V_5 -> V_9 , V_46 , & V_5 -> V_6 ) ;
V_5 -> V_6 &= V_47 ;
V_29 &= ~ V_45 ;
F_13 ( V_5 -> V_9 , V_25 , V_29 ) ;
V_5 -> V_15 = true ;
F_16 ( & V_5 -> V_14 ) ;
}
return V_44 ;
}
static int F_18 ( struct V_48 * V_49 )
{
struct V_1 * V_2 ;
struct V_4 * V_5 ;
struct V_50 * V_51 = F_19 ( V_49 -> V_52 . V_53 ) ;
int V_39 , V_54 ;
int V_7 ;
V_2 = F_20 ( & V_49 -> V_52 , sizeof( * V_5 ) ) ;
if ( ! V_2 )
return - V_55 ;
V_5 = F_2 ( V_2 ) ;
F_21 ( V_49 , V_2 ) ;
V_5 -> V_9 = F_22 ( V_51 ) ;
F_23 ( V_51 ) ;
if ( F_24 ( V_5 -> V_9 ) )
return F_25 ( V_5 -> V_9 ) ;
V_39 = F_26 ( V_49 , L_1 ) ;
if ( V_39 < 0 )
return V_39 ;
V_54 = F_26 ( V_49 , L_2 ) ;
if ( V_54 < 0 )
return V_54 ;
V_7 = F_27 ( & V_49 -> V_52 , V_39 , F_14 , 0 ,
V_49 -> V_52 . V_56 -> V_57 , V_2 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_27 ( & V_49 -> V_52 , V_54 , F_17 ,
0 , V_49 -> V_52 . V_56 -> V_57 , V_2 ) ;
if ( V_7 )
return V_7 ;
F_28 ( & V_5 -> V_14 ) ;
F_29 ( & V_5 -> V_8 ) ;
V_2 -> V_52 . V_58 = & V_49 -> V_52 ;
V_2 -> V_57 = F_30 ( & V_49 -> V_52 ) ;
V_2 -> V_59 = V_60 ;
V_2 -> V_61 = & V_62 ;
V_2 -> V_63 = V_64 ;
V_2 -> V_65 = F_31 ( V_64 ) ;
F_4 ( V_5 -> V_9 , V_10 ,
V_66 , V_66 ) ;
V_7 = F_32 ( V_2 ) ;
if ( V_7 ) {
F_4 ( V_5 -> V_9 , V_10 ,
V_66 , 0 ) ;
return V_7 ;
}
return 0 ;
}
static int F_33 ( struct V_48 * V_49 )
{
struct V_1 * V_2 = F_34 ( V_49 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_35 ( V_2 ) ;
F_4 ( V_5 -> V_9 , V_10 ,
V_66 , 0 ) ;
return 0 ;
}
