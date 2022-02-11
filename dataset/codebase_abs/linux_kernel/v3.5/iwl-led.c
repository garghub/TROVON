void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 , V_4 , V_5 ) ;
}
static inline T_1 F_3 ( struct V_1 * V_2 ,
T_1 time , T_2 V_6 )
{
if ( ! V_6 ) {
F_4 ( V_2 , L_1
L_2 ) ;
return time ;
}
return ( T_1 ) ( ( time * V_6 ) >> 6 ) ;
}
static int F_5 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
struct V_9 V_10 = {
. V_11 = V_12 ,
. V_13 = { sizeof( struct V_7 ) , } ,
. V_14 = { V_8 , } ,
. V_15 = V_16 ,
} ;
T_3 V_17 ;
V_17 = F_6 ( V_2 -> V_3 , V_4 ) ;
if ( V_17 != ( V_17 & V_18 ) )
F_2 ( V_2 -> V_3 , V_4 ,
V_17 & V_18 ) ;
return F_7 ( V_2 , & V_10 ) ;
}
static int V_7 ( struct V_1 * V_2 ,
unsigned long V_19 ,
unsigned long V_20 )
{
struct V_7 V_8 = {
. V_11 = V_21 ,
. V_22 = V_23
} ;
int V_24 ;
if ( ! F_8 ( V_25 , & V_2 -> V_26 ) )
return - V_27 ;
if ( V_2 -> V_28 == V_19 && V_2 -> V_29 == V_20 )
return 0 ;
if ( V_20 == 0 ) {
V_19 = V_30 ;
}
F_9 ( V_2 , L_3 ,
V_2 -> V_31 -> V_32 -> V_33 ) ;
V_8 . V_19 = F_3 ( V_2 , V_19 ,
V_2 -> V_31 -> V_32 -> V_33 ) ;
V_8 . V_20 = F_3 ( V_2 , V_20 ,
V_2 -> V_31 -> V_32 -> V_33 ) ;
V_24 = F_5 ( V_2 , & V_8 ) ;
if ( ! V_24 ) {
V_2 -> V_28 = V_19 ;
V_2 -> V_29 = V_20 ;
}
return V_24 ;
}
static void F_10 ( struct V_34 * V_35 ,
enum V_36 V_37 )
{
struct V_1 * V_2 = F_11 ( V_35 , struct V_1 , V_38 ) ;
unsigned long V_19 = 0 ;
if ( V_37 > 0 )
V_19 = V_30 ;
V_7 ( V_2 , V_19 , 0 ) ;
}
static int F_12 ( struct V_34 * V_35 ,
unsigned long * V_39 ,
unsigned long * V_40 )
{
struct V_1 * V_2 = F_11 ( V_35 , struct V_1 , V_38 ) ;
return V_7 ( V_2 , * V_39 , * V_40 ) ;
}
void F_13 ( struct V_1 * V_2 )
{
int V_41 = V_42 . V_43 ;
int V_24 ;
if ( V_41 == V_44 ) {
F_14 ( V_2 , L_4 ) ;
return;
}
if ( V_41 == V_45 )
V_41 = V_2 -> V_31 -> V_43 ;
V_2 -> V_38 . V_46 = F_15 ( V_47 , L_5 ,
F_16 ( V_2 -> V_48 -> V_49 ) ) ;
V_2 -> V_38 . V_50 = F_10 ;
V_2 -> V_38 . V_51 = F_12 ;
V_2 -> V_38 . V_52 = 1 ;
switch ( V_41 ) {
case V_45 :
F_17 ( 1 ) ;
break;
case V_53 :
V_2 -> V_38 . V_54 =
F_18 ( V_2 -> V_48 ,
V_55 ,
V_56 , F_19 ( V_56 ) ) ;
break;
case V_57 :
V_2 -> V_38 . V_54 =
F_20 ( V_2 -> V_48 ) ;
break;
}
V_24 = F_21 ( V_2 -> V_3 -> V_58 , & V_2 -> V_38 ) ;
if ( V_24 ) {
F_22 ( V_2 -> V_38 . V_46 ) ;
return;
}
V_2 -> V_59 = true ;
}
void F_23 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_59 )
return;
F_24 ( & V_2 -> V_38 ) ;
F_22 ( V_2 -> V_38 . V_46 ) ;
}
