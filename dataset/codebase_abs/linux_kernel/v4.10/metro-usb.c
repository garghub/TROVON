static inline int F_1 ( struct V_1 * V_2 )
{
T_1 V_3 = F_2 (
V_2 -> V_4 -> V_5 -> V_6 . V_7 ) ;
return V_3 == V_8 ;
}
static int F_3 ( T_2 V_9 , struct V_1 * V_2 )
{
int V_10 ;
int V_11 ;
T_2 * V_12 = NULL ;
if ( ! F_1 ( V_2 ) )
return 0 ;
V_12 = F_4 ( sizeof( V_9 ) , V_13 ) ;
if ( ! V_12 )
return - V_14 ;
* V_12 = V_9 ;
V_10 = F_5 ( V_2 -> V_4 -> V_5 ,
F_6 ( V_2 -> V_4 -> V_5 , V_2 -> V_15 ) ,
V_12 , sizeof( V_9 ) ,
& V_11 , V_16 ) ;
F_7 ( V_12 ) ;
if ( V_10 < 0 )
return V_10 ;
else if ( V_11 != sizeof( V_9 ) )
return - V_17 ;
return 0 ;
}
static void F_8 ( struct V_18 * V_18 )
{
struct V_1 * V_2 = V_18 -> V_19 ;
struct V_20 * V_21 = F_9 ( V_2 ) ;
unsigned char * V_22 = V_18 -> V_23 ;
int V_24 = 0 ;
int V_25 = 0 ;
unsigned long V_26 = 0 ;
F_10 ( & V_2 -> V_5 , L_1 , V_27 ) ;
switch ( V_18 -> V_28 ) {
case 0 :
break;
case - V_29 :
case - V_30 :
case - V_31 :
F_10 ( & V_2 -> V_5 ,
L_2 ,
V_27 , V_18 -> V_28 ) ;
return;
default:
F_10 ( & V_2 -> V_5 ,
L_3 ,
V_27 , V_18 -> V_28 ) ;
goto exit;
}
if ( V_18 -> V_32 ) {
F_11 ( & V_2 -> V_2 , V_22 , V_18 -> V_32 ) ;
F_12 ( & V_2 -> V_2 ) ;
}
F_13 ( & V_21 -> V_33 , V_26 ) ;
V_24 = V_21 -> V_24 ;
F_14 ( & V_21 -> V_33 , V_26 ) ;
if ( ! V_24 ) {
F_15 ( V_2 -> V_34 , V_2 -> V_4 -> V_5 ,
F_16 ( V_2 -> V_4 -> V_5 , V_2 -> V_35 ) ,
V_2 -> V_34 -> V_23 ,
V_2 -> V_34 -> V_36 ,
F_8 , V_2 , 1 ) ;
V_25 = F_17 ( V_2 -> V_34 , V_37 ) ;
if ( V_25 )
F_18 ( & V_2 -> V_5 ,
L_4 ,
V_27 , V_25 ) ;
}
return;
exit:
V_25 = F_17 ( V_18 , V_37 ) ;
if ( V_25 )
F_18 ( & V_2 -> V_5 ,
L_4 ,
V_27 , V_25 ) ;
}
static void F_19 ( struct V_18 * V_18 )
{
struct V_1 * V_2 = V_18 -> V_19 ;
F_20 ( & V_2 -> V_5 , L_5 ,
V_27 ) ;
}
static void F_21 ( struct V_1 * V_2 )
{
F_10 ( & V_2 -> V_5 , L_1 , V_27 ) ;
F_22 ( V_2 -> V_34 ) ;
F_23 ( V_2 -> V_34 ) ;
F_3 ( V_38 , V_2 ) ;
}
static int F_24 ( struct V_39 * V_40 , struct V_1 * V_2 )
{
struct V_41 * V_4 = V_2 -> V_4 ;
struct V_20 * V_21 = F_9 ( V_2 ) ;
unsigned long V_26 = 0 ;
int V_25 = 0 ;
F_10 ( & V_2 -> V_5 , L_1 , V_27 ) ;
if ( ! V_2 -> V_34 ) {
F_18 ( & V_2 -> V_5 , L_6 ,
V_27 ) ;
return - V_42 ;
}
F_13 ( & V_21 -> V_33 , V_26 ) ;
V_21 -> V_43 = 0 ;
V_21 -> V_24 = 0 ;
F_14 ( & V_21 -> V_33 , V_26 ) ;
F_25 ( V_4 -> V_5 , V_2 -> V_34 -> V_44 ) ;
F_15 ( V_2 -> V_34 , V_4 -> V_5 ,
F_16 ( V_4 -> V_5 , V_2 -> V_35 ) ,
V_2 -> V_34 -> V_23 ,
V_2 -> V_34 -> V_36 ,
F_8 , V_2 , 1 ) ;
V_25 = F_17 ( V_2 -> V_34 , V_13 ) ;
if ( V_25 ) {
F_18 ( & V_2 -> V_5 ,
L_4 ,
V_27 , V_25 ) ;
goto exit;
}
V_25 = F_3 ( V_45 , V_2 ) ;
if ( V_25 ) {
F_18 ( & V_2 -> V_5 ,
L_7 ,
V_27 , V_25 ) ;
goto exit;
}
F_10 ( & V_2 -> V_5 , L_8 , V_27 ) ;
exit:
return V_25 ;
}
static int F_26 ( struct V_41 * V_4 , unsigned int V_43 )
{
int V_46 = 0 ;
unsigned char V_47 = V_48 ;
F_10 ( & V_4 -> V_5 -> V_5 , L_9 ,
V_27 , V_43 ) ;
if ( V_43 & V_49 )
V_47 |= V_50 ;
if ( V_43 & V_51 )
V_47 |= V_52 ;
V_46 = F_27 ( V_4 -> V_5 , F_28 ( V_4 -> V_5 , 0 ) ,
V_53 , V_54 ,
V_43 , 0 , NULL , 0 , V_55 ) ;
if ( V_46 < 0 )
F_18 ( & V_4 -> V_5 -> V_5 ,
L_10 ,
V_27 , V_47 , V_46 ) ;
return V_46 ;
}
static int F_29 ( struct V_1 * V_2 )
{
struct V_20 * V_21 ;
V_21 = F_4 ( sizeof( * V_21 ) , V_13 ) ;
if ( ! V_21 )
return - V_14 ;
F_30 ( & V_21 -> V_33 ) ;
F_31 ( V_2 , V_21 ) ;
return 0 ;
}
static int F_32 ( struct V_1 * V_2 )
{
struct V_20 * V_21 ;
V_21 = F_9 ( V_2 ) ;
F_7 ( V_21 ) ;
return 0 ;
}
static void F_33 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = V_40 -> V_56 ;
struct V_20 * V_21 = F_9 ( V_2 ) ;
unsigned long V_26 = 0 ;
F_10 ( V_40 -> V_5 , L_1 , V_27 ) ;
F_13 ( & V_21 -> V_33 , V_26 ) ;
V_21 -> V_24 = 1 ;
F_14 ( & V_21 -> V_33 , V_26 ) ;
}
static int F_34 ( struct V_39 * V_40 )
{
unsigned long V_43 = 0 ;
struct V_1 * V_2 = V_40 -> V_56 ;
struct V_20 * V_21 = F_9 ( V_2 ) ;
unsigned long V_26 = 0 ;
F_10 ( V_40 -> V_5 , L_1 , V_27 ) ;
F_13 ( & V_21 -> V_33 , V_26 ) ;
V_43 = V_21 -> V_43 ;
F_14 ( & V_21 -> V_33 , V_26 ) ;
return V_43 ;
}
static int F_35 ( struct V_39 * V_40 ,
unsigned int V_57 , unsigned int V_58 )
{
struct V_1 * V_2 = V_40 -> V_56 ;
struct V_41 * V_4 = V_2 -> V_4 ;
struct V_20 * V_21 = F_9 ( V_2 ) ;
unsigned long V_26 = 0 ;
unsigned long V_43 = 0 ;
F_10 ( V_40 -> V_5 , L_11 , V_27 , V_57 , V_58 ) ;
F_13 ( & V_21 -> V_33 , V_26 ) ;
V_43 = V_21 -> V_43 ;
if ( V_57 & V_51 )
V_43 |= V_51 ;
if ( V_57 & V_49 )
V_43 |= V_49 ;
if ( V_58 & V_51 )
V_43 &= ~ V_51 ;
if ( V_58 & V_49 )
V_43 &= ~ V_49 ;
V_21 -> V_43 = V_43 ;
F_14 ( & V_21 -> V_33 , V_26 ) ;
return F_26 ( V_4 , V_43 ) ;
}
static void F_36 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = V_40 -> V_56 ;
struct V_20 * V_21 = F_9 ( V_2 ) ;
unsigned long V_26 = 0 ;
int V_25 = 0 ;
F_10 ( V_40 -> V_5 , L_1 , V_27 ) ;
F_13 ( & V_21 -> V_33 , V_26 ) ;
V_21 -> V_24 = 0 ;
F_14 ( & V_21 -> V_33 , V_26 ) ;
V_2 -> V_34 -> V_5 = V_2 -> V_4 -> V_5 ;
V_25 = F_17 ( V_2 -> V_34 , V_37 ) ;
if ( V_25 )
F_18 ( V_40 -> V_5 ,
L_12 ,
V_25 ) ;
}
