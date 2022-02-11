void F_1 ( struct V_1 * V_2 , T_1 V_3 , int V_4 )
{
T_2 * V_5 = V_2 -> V_6 ;
if ( V_4 )
V_5 -> V_7 |= V_3 ;
else
V_5 -> V_7 &= ~ V_3 ;
if ( V_2 -> V_8 )
F_2 ( V_9 , V_5 -> V_7 ) ;
}
static void F_3 ( struct V_1 * V_2 , T_1 V_3 , int V_4 )
{
T_2 * V_5 = V_2 -> V_6 ;
if ( V_4 )
V_5 -> V_10 |= V_3 ;
else
V_5 -> V_10 &= ~ V_3 ;
if ( V_2 -> V_8 )
F_2 ( V_11 , V_5 -> V_10 ) ;
}
int F_4 ( struct V_1 * V_2 , int V_12 )
{
T_2 * V_5 = V_2 -> V_6 ;
if ( ( V_5 -> V_13 & V_14 ) >= V_15 ) {
switch ( V_12 ) {
case 0 :
F_3 ( V_2 , V_16 , 1 ) ;
break;
case 1 :
F_3 ( V_2 , V_17 , 1 ) ;
break;
default:
F_5 ( L_1 ,
V_12 ) ;
return - V_18 ;
}
} else {
switch ( V_12 ) {
case 0 :
F_1 ( V_2 , V_19 , 1 ) ;
break;
case 1 :
F_1 ( V_2 , V_20 , 1 ) ;
break;
default:
F_5 ( L_1 ,
V_12 ) ;
return - V_18 ;
}
}
return 0 ;
}
void F_6 ( struct V_1 * V_2 , int V_12 )
{
T_2 * V_5 = V_2 -> V_6 ;
if ( ( V_5 -> V_13 & V_14 ) >= V_15 ) {
switch ( V_12 ) {
case 0 :
F_3 ( V_2 , V_16 , 0 ) ;
break;
case 1 :
F_3 ( V_2 , V_17 , 0 ) ;
break;
default:
F_5 ( L_1 ,
V_12 ) ;
break;
}
} else {
switch ( V_12 ) {
case 0 :
F_1 ( V_2 , V_19 , 0 ) ;
break;
case 1 :
F_1 ( V_2 , V_20 , 0 ) ;
break;
default:
F_5 ( L_1 ,
V_12 ) ;
break;
}
}
}
static T_1 F_7 ( T_2 * V_5 , T_1 * V_21 )
{
T_1 V_22 = F_8 ( V_23 ) ;
T_1 V_24 = V_25 ;
* V_21 = 0 ;
if ( ( V_5 -> V_13 & V_14 ) >= V_15 ) {
if ( V_22 & V_26 ) {
T_1 V_27 ;
V_27 = F_8 ( V_28 ) ;
* V_21 = V_27 ;
if ( V_27 & V_29 )
F_2 ( V_30 , V_31 ) ;
if ( V_27 & V_32 )
F_2 ( V_33 , V_31 ) ;
}
V_24 |= V_26 ;
} else
V_24 |= V_34 | V_35 ;
V_22 &= V_24 ;
if ( V_22 )
F_2 ( V_23 , V_22 ) ;
return V_22 ;
}
T_3 F_9 ( int V_36 , void * V_37 )
{
struct V_1 * V_2 = (struct V_1 * ) V_37 ;
T_2 * V_5 =
( T_2 * ) V_2 -> V_6 ;
T_1 V_38 ;
T_1 V_21 ;
if ( ( V_5 -> V_13 & V_14 ) >= V_39 )
return V_40 ;
V_38 = F_7 ( V_5 , & V_21 ) ;
if ( ! V_38 )
return V_40 ;
V_38 &= V_5 -> V_7 ;
if ( V_38 & V_25 )
F_10 ( & V_5 -> V_41 ) ;
if ( ( V_5 -> V_13 & V_14 ) >= V_15 ) {
if ( V_21 & V_29 )
F_11 ( V_2 , 0 ) ;
if ( V_21 & V_32 )
F_11 ( V_2 , 1 ) ;
} else {
if ( V_38 & V_34 )
F_11 ( V_2 , 0 ) ;
if ( V_38 & V_35 )
F_11 ( V_2 , 1 ) ;
}
return V_42 ;
}
static int F_12 ( struct V_1 * V_2 )
{
T_2 * V_5 = V_2 -> V_6 ;
unsigned int V_43 ;
V_44 ;
F_13 ( & V_5 -> V_45 ) ;
V_43 = F_14 ( & V_5 -> V_45 ) ;
F_15 ( 4 ) ;
F_16 ( V_46 , V_43 ) ;
F_16 ( V_23 , V_47 ) ;
F_17 () ;
F_18 () ;
return V_43 ;
}
static int F_19 ( struct V_1 * V_2 , int V_48 )
{
T_2 * V_5 =
( T_2 * ) V_2 -> V_6 ;
int V_43 = 0 ;
if ( F_8 ( V_46 ) >= V_48 )
return 0 ;
V_5 -> V_49 . V_50 |= V_51 ;
F_20 ( V_43 , V_5 -> V_41 , 3 * V_52 ,
F_8 ( V_46 ) >= V_48 ) ;
return V_43 ;
}
T_1 F_21 ( struct V_1 * V_2 , int V_12 )
{
T_2 * V_5 = V_2 -> V_6 ;
if ( ! V_5 ) {
F_5 ( L_2 ) ;
return - V_18 ;
}
if ( V_12 < 0 || V_12 > 1 ) {
F_5 ( L_3 , V_12 ) ;
return - V_18 ;
}
if ( ( V_5 -> V_13 & V_14 ) >= V_15 ) {
if ( V_12 == 0 )
return F_8 ( V_53 ) ;
else
return F_8 ( V_54 ) ;
} else {
if ( V_12 == 0 )
return F_8 ( V_55 ) ;
else
return F_8 ( V_56 ) ;
}
}
int F_22 ( struct V_1 * V_2 , void * V_57 , struct V_58 * V_59 )
{
T_2 * V_5 = V_2 -> V_6 ;
T_4 * V_60 = V_57 ;
int V_61 ;
if ( ! V_5 ) {
F_5 ( L_2 ) ;
return - V_18 ;
}
if ( ( V_5 -> V_13 & V_14 ) >= V_39 )
return - V_18 ;
F_23 ( V_2 , V_59 ) ;
V_61 = F_12 ( V_2 ) ;
if ( F_24 ( V_60 -> V_62 , & V_61 , sizeof( int ) ) ) {
F_5 ( L_4 ) ;
return - V_63 ;
}
return 0 ;
}
int F_25 ( struct V_1 * V_2 , void * V_57 , struct V_58 * V_59 )
{
T_2 * V_5 = V_2 -> V_6 ;
T_5 * V_64 = V_57 ;
if ( ! V_5 ) {
F_5 ( L_2 ) ;
return - V_18 ;
}
if ( ( V_5 -> V_13 & V_14 ) >= V_39 )
return - V_18 ;
return F_19 ( V_2 , V_64 -> V_62 ) ;
}
void F_26 ( struct V_1 * V_2 )
{
T_2 * V_5 =
( T_2 * ) V_2 -> V_6 ;
T_1 V_65 ;
if ( ( V_5 -> V_13 & V_14 ) >= V_39 )
return;
if ( ( V_5 -> V_13 & V_14 ) >= V_15 )
F_2 ( V_11 , 0 ) ;
F_2 ( V_9 , 0 ) ;
F_7 ( V_5 , & V_65 ) ;
}
int F_27 ( struct V_1 * V_2 )
{
T_2 * V_5 =
( T_2 * ) V_2 -> V_6 ;
F_28 ( & V_5 -> V_45 , 0 ) ;
F_29 ( & V_5 -> V_41 ) ;
V_2 -> V_66 = 0x001fffff ;
if ( ( V_5 -> V_13 & V_14 ) >= V_39 )
return 0 ;
F_1 ( V_2 , V_67 , 1 ) ;
return 0 ;
}
void F_30 ( struct V_1 * V_2 )
{
T_2 * V_5 =
( T_2 * ) V_2 -> V_6 ;
if ( ! V_5 )
return;
if ( ( V_5 -> V_13 & V_14 ) >= V_39 )
return;
if ( ( V_5 -> V_13 & V_14 ) >= V_15 )
F_2 ( V_11 , 0 ) ;
F_2 ( V_9 , 0 ) ;
}
int F_31 ( struct V_1 * V_2 )
{
T_2 * V_5 = ( T_2 * ) V_2 -> V_6 ;
return V_5 -> V_68 ;
}
int F_32 ( struct V_1 * V_2 , T_6 V_69 )
{
T_2 * V_5 = ( T_2 * ) V_2 -> V_6 ;
if ( V_69 & ~ ( V_70 | V_71 ) ) {
F_5 ( L_5 , ( unsigned int ) V_69 ) ;
return - V_18 ;
}
V_5 -> V_68 = ( unsigned int ) V_69 ;
return 0 ;
}
