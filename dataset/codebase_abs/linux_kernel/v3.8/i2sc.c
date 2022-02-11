static inline unsigned long F_1 ( struct V_1 * V_2 , int V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static inline void F_3 ( struct V_1 * V_2 , int V_3 , unsigned long V_5 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
F_5 () ;
}
static int F_6 ( struct V_6 * V_7 , unsigned int V_8 )
{
struct V_1 * V_2 = F_7 ( V_7 ) ;
unsigned long V_9 ;
int V_10 ;
V_10 = - V_11 ;
V_9 = V_2 -> V_12 ;
V_9 &= ~ V_13 ;
switch ( V_8 & V_14 ) {
case V_15 :
V_9 |= V_16 ;
break;
case V_17 :
V_9 |= V_18 ;
break;
case V_19 :
V_9 |= V_20 ;
break;
default:
goto V_21;
}
V_9 &= ~ ( V_22 | V_23 ) ;
switch ( V_8 & V_24 ) {
case V_25 :
V_9 |= V_22 | V_23 ;
break;
case V_26 :
V_9 |= V_22 ;
break;
case V_27 :
V_9 |= V_23 ;
break;
case V_28 :
break;
default:
goto V_21;
}
switch ( V_8 & V_29 ) {
case V_30 :
break;
default:
goto V_21;
}
V_10 = 0 ;
V_2 -> V_12 = V_9 ;
V_21:
return V_10 ;
}
static int F_8 ( struct V_31 * V_32 ,
int V_33 , struct V_6 * V_34 )
{
struct V_1 * V_2 = F_7 ( V_34 ) ;
int V_35 = F_9 ( V_32 ) ;
switch ( V_33 ) {
case V_36 :
case V_37 :
F_3 ( V_2 , V_38 , V_39 | V_40 ) ;
F_3 ( V_2 , V_38 , V_40 ) ;
V_2 -> V_12 |= ( V_35 == V_41 ) ? V_42 : V_43 ;
F_3 ( V_2 , V_44 , V_2 -> V_12 ) ;
break;
case V_45 :
case V_46 :
V_2 -> V_12 &= ~ ( ( V_35 == V_41 ) ? V_42 : V_43 ) ;
F_3 ( V_2 , V_44 , V_2 -> V_12 ) ;
F_3 ( V_2 , V_38 , V_39 ) ;
break;
default:
return - V_11 ;
}
return 0 ;
}
static unsigned long F_10 ( int V_47 )
{
switch ( V_47 ) {
case 8 :
return V_48 ;
case 16 :
return V_49 ;
case 18 :
return V_50 ;
case 20 :
return V_51 ;
case 24 :
return V_52 ;
}
return 0 ;
}
static int F_11 ( struct V_31 * V_32 ,
struct V_53 * V_54 ,
struct V_6 * V_34 )
{
struct V_1 * V_2 = F_7 ( V_34 ) ;
unsigned long V_5 ;
V_5 = F_10 ( V_54 -> V_47 ) ;
if ( ! V_5 )
return - V_11 ;
V_2 -> V_12 &= ~ V_55 ;
V_2 -> V_12 |= V_5 ;
return 0 ;
}
static int F_12 ( struct V_31 * V_32 ,
struct V_6 * V_34 )
{
struct V_1 * V_2 = F_7 ( V_34 ) ;
F_13 ( V_34 , V_32 , & V_2 -> V_56 [ 0 ] ) ;
return 0 ;
}
static int F_14 ( struct V_57 * V_58 )
{
struct V_59 * V_60 , * V_61 ;
struct V_1 * V_2 ;
V_2 = F_15 ( & V_58 -> V_62 , sizeof( * V_2 ) , V_63 ) ;
if ( ! V_2 )
return - V_64 ;
V_60 = F_16 ( V_58 , V_65 , 0 ) ;
if ( ! V_60 )
return - V_66 ;
if ( ! F_17 ( & V_58 -> V_62 , V_60 -> V_67 ,
F_18 ( V_60 ) ,
V_58 -> V_68 ) )
return - V_69 ;
V_2 -> V_4 = F_19 ( & V_58 -> V_62 , V_60 -> V_67 ,
F_18 ( V_60 ) ) ;
if ( ! V_2 -> V_4 )
return - V_69 ;
V_61 = F_16 ( V_58 , V_70 , 0 ) ;
if ( ! V_61 )
return - V_69 ;
V_2 -> V_56 [ V_71 ] = V_61 -> V_67 ;
V_61 = F_16 ( V_58 , V_70 , 1 ) ;
if ( ! V_61 )
return - V_69 ;
V_2 -> V_56 [ V_72 ] = V_61 -> V_67 ;
F_20 ( V_58 , V_2 ) ;
return F_21 ( & V_58 -> V_62 , & V_73 ) ;
}
static int F_22 ( struct V_57 * V_58 )
{
struct V_1 * V_2 = F_23 ( V_58 ) ;
F_24 ( & V_58 -> V_62 ) ;
F_3 ( V_2 , V_38 , V_39 ) ;
return 0 ;
}
static int F_25 ( struct V_74 * V_62 )
{
struct V_1 * V_2 = F_26 ( V_62 ) ;
F_3 ( V_2 , V_38 , V_39 ) ;
return 0 ;
}
static int F_27 ( struct V_74 * V_62 )
{
return 0 ;
}
