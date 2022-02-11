static inline T_1 F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static inline void F_3 ( struct V_1 * V_2 , T_1 V_5 ,
unsigned int V_3 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
void F_5 ( struct V_1 * V_2 , T_2 V_6 , T_1 V_7 )
{
bool V_8 = false ;
unsigned long V_9 ;
T_1 V_10 ;
switch ( V_7 ) {
case V_11 :
case V_12 :
case V_13 :
V_8 = true ;
break;
case V_14 :
case V_15 :
case V_16 :
V_8 = false ;
break;
default:
V_8 = ( V_6 & V_17 ) ? true : false ;
break;
}
F_6 ( & V_2 -> V_18 , V_9 ) ;
V_10 = F_1 ( V_2 , V_19 ) ;
if ( V_8 )
V_10 &= ~ ( V_20 | V_21 ) ;
else
V_10 |= V_20 | V_21 ;
F_3 ( V_2 , V_10 , V_19 ) ;
F_7 ( & V_2 -> V_18 , V_9 ) ;
}
void F_8 ( struct V_1 * V_2 , enum V_22 V_23 )
{
unsigned long V_9 ;
T_1 V_10 ;
F_6 ( & V_2 -> V_18 , V_9 ) ;
V_10 = F_1 ( V_2 , V_19 ) ;
V_10 &= ~ V_24 ;
switch ( V_23 ) {
case V_25 :
V_10 |= V_26 ;
break;
case V_27 :
V_10 |= V_28 ;
break;
default:
V_10 |= V_29 ;
break;
}
F_3 ( V_2 , V_10 , V_19 ) ;
F_7 ( & V_2 -> V_18 , V_9 ) ;
}
void F_9 ( struct V_1 * V_2 , T_1 V_30 , int V_31 , int V_32 )
{
unsigned long V_9 ;
T_1 V_33 , V_10 ;
F_6 ( & V_2 -> V_18 , V_9 ) ;
V_10 = ( ( V_32 - 1 ) << 16 ) | ( V_31 - 1 ) ;
F_3 ( V_2 , V_10 , V_34 ) ;
if ( V_30 == V_35 ||
V_30 == V_36 ||
V_30 == V_37 ||
V_30 == V_38 )
V_33 = V_39 ;
else
V_33 = V_40 ;
V_10 = F_1 ( V_2 , V_19 ) ;
V_10 |= V_33 ;
V_10 |= V_41 ;
V_10 |= V_42 | V_43 ;
V_10 |= V_44 | V_45 ;
F_3 ( V_2 , V_10 , V_19 ) ;
F_7 ( & V_2 -> V_18 , V_9 ) ;
}
void F_10 ( struct V_1 * V_2 )
{
unsigned long V_9 ;
F_6 ( & V_2 -> V_18 , V_9 ) ;
F_3 ( V_2 , 0 , V_34 ) ;
F_3 ( V_2 , 0 , V_19 ) ;
F_7 ( & V_2 -> V_18 , V_9 ) ;
}
int F_11 ( struct V_1 * V_2 )
{
unsigned long V_9 ;
F_6 ( & V_2 -> V_18 , V_9 ) ;
if ( ! V_2 -> V_46 )
F_12 ( V_2 -> V_47 , V_2 -> V_48 ) ;
V_2 -> V_46 ++ ;
F_7 ( & V_2 -> V_18 , V_9 ) ;
return 0 ;
}
int F_13 ( struct V_1 * V_2 )
{
unsigned long V_9 ;
F_6 ( & V_2 -> V_18 , V_9 ) ;
if ( V_2 -> V_46 ) {
if ( ! -- V_2 -> V_46 )
F_14 ( V_2 -> V_47 , V_2 -> V_48 ) ;
}
F_7 ( & V_2 -> V_18 , V_9 ) ;
return 0 ;
}
struct V_1 * F_15 ( struct V_49 * V_47 )
{
return V_47 -> V_50 ;
}
void F_16 ( struct V_1 * V_2 )
{
}
int F_17 ( struct V_49 * V_47 , struct V_51 * V_52 ,
unsigned long V_4 , T_1 V_48 )
{
struct V_1 * V_2 ;
V_2 = F_18 ( V_52 , sizeof( * V_2 ) , V_53 ) ;
if ( ! V_2 )
return - V_54 ;
V_47 -> V_50 = V_2 ;
F_19 ( & V_2 -> V_18 ) ;
V_2 -> V_48 = V_48 ;
V_2 -> V_4 = F_20 ( V_52 , V_4 , V_55 ) ;
if ( ! V_2 -> V_4 )
return - V_54 ;
F_21 ( V_52 , L_1 , V_4 , V_2 -> V_4 ) ;
V_2 -> V_47 = V_47 ;
return 0 ;
}
void F_22 ( struct V_49 * V_47 )
{
}
