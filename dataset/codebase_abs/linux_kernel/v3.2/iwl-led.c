static inline T_1 F_1 ( struct V_1 * V_2 ,
T_1 time , T_2 V_3 )
{
if ( ! V_3 ) {
F_2 ( V_2 , L_1
L_2 ) ;
return time ;
}
return ( T_1 ) ( ( time * V_3 ) >> 6 ) ;
}
static int F_3 ( struct V_1 * V_2 ,
unsigned long V_4 ,
unsigned long V_5 )
{
struct V_6 V_7 = {
. V_8 = V_9 ,
. V_10 = V_11
} ;
int V_12 ;
if ( ! F_4 ( V_13 , & V_2 -> V_14 ) )
return - V_15 ;
if ( V_2 -> V_16 == V_4 && V_2 -> V_17 == V_5 )
return 0 ;
if ( V_5 == 0 ) {
V_4 = V_18 ;
}
F_5 ( V_2 , L_3 ,
V_2 -> V_19 -> V_20 -> V_21 ) ;
V_7 . V_4 = F_1 ( V_2 , V_4 ,
V_2 -> V_19 -> V_20 -> V_21 ) ;
V_7 . V_5 = F_1 ( V_2 , V_5 ,
V_2 -> V_19 -> V_20 -> V_21 ) ;
V_12 = V_2 -> V_19 -> V_22 -> V_23 -> V_24 ( V_2 , & V_7 ) ;
if ( ! V_12 ) {
V_2 -> V_16 = V_4 ;
V_2 -> V_17 = V_5 ;
}
return V_12 ;
}
static void F_6 ( struct V_25 * V_26 ,
enum V_27 V_28 )
{
struct V_1 * V_2 = F_7 ( V_26 , struct V_1 , V_23 ) ;
unsigned long V_4 = 0 ;
if ( V_28 > 0 )
V_4 = V_18 ;
F_3 ( V_2 , V_4 , 0 ) ;
}
static int F_8 ( struct V_25 * V_26 ,
unsigned long * V_29 ,
unsigned long * V_30 )
{
struct V_1 * V_2 = F_7 ( V_26 , struct V_1 , V_23 ) ;
return F_3 ( V_2 , * V_29 , * V_30 ) ;
}
void F_9 ( struct V_1 * V_2 )
{
int V_31 = V_32 ;
int V_12 ;
if ( V_31 == V_33 )
V_31 = V_2 -> V_19 -> V_32 ;
V_2 -> V_23 . V_34 = F_10 ( V_35 , L_4 ,
F_11 ( V_2 -> V_36 -> V_37 ) ) ;
V_2 -> V_23 . V_38 = F_6 ;
V_2 -> V_23 . V_39 = F_8 ;
V_2 -> V_23 . V_40 = 1 ;
switch ( V_31 ) {
case V_33 :
F_12 ( 1 ) ;
break;
case V_41 :
V_2 -> V_23 . V_42 =
F_13 ( V_2 -> V_36 ,
V_43 ,
V_44 , F_14 ( V_44 ) ) ;
break;
case V_45 :
V_2 -> V_23 . V_42 =
F_15 ( V_2 -> V_36 ) ;
break;
}
V_12 = F_16 ( & V_2 -> V_46 -> V_47 , & V_2 -> V_23 ) ;
if ( V_12 ) {
F_17 ( V_2 -> V_23 . V_34 ) ;
return;
}
V_2 -> V_48 = true ;
}
void F_18 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_48 )
return;
F_19 ( & V_2 -> V_23 ) ;
F_17 ( V_2 -> V_23 . V_34 ) ;
}
