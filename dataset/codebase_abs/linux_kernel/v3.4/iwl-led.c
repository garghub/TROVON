void F_1 ( struct V_1 * V_2 )
{
F_2 ( F_3 ( V_2 ) , V_3 , V_4 ) ;
}
static inline T_1 F_4 ( struct V_1 * V_2 ,
T_1 time , T_2 V_5 )
{
if ( ! V_5 ) {
F_5 ( V_2 , L_1
L_2 ) ;
return time ;
}
return ( T_1 ) ( ( time * V_5 ) >> 6 ) ;
}
static int F_6 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
struct V_8 V_9 = {
. V_10 = V_11 ,
. V_12 = { sizeof( struct V_6 ) , } ,
. V_13 = { V_7 , } ,
. V_14 = V_15 ,
} ;
T_3 V_16 ;
V_16 = F_7 ( F_3 ( V_2 ) , V_3 ) ;
if ( V_16 != ( V_16 & V_17 ) )
F_2 ( F_3 ( V_2 ) , V_3 ,
V_16 & V_17 ) ;
return F_8 ( V_2 , & V_9 ) ;
}
static int V_6 ( struct V_1 * V_2 ,
unsigned long V_18 ,
unsigned long V_19 )
{
struct V_6 V_7 = {
. V_10 = V_20 ,
. V_21 = V_22
} ;
int V_23 ;
if ( ! F_9 ( V_24 , & V_2 -> V_25 ) )
return - V_26 ;
if ( V_2 -> V_27 == V_18 && V_2 -> V_28 == V_19 )
return 0 ;
if ( V_19 == 0 ) {
V_18 = V_29 ;
}
F_10 ( V_2 , L_3 ,
F_11 ( V_2 ) -> V_30 -> V_31 ) ;
V_7 . V_18 = F_4 ( V_2 , V_18 ,
F_11 ( V_2 ) -> V_30 -> V_31 ) ;
V_7 . V_19 = F_4 ( V_2 , V_19 ,
F_11 ( V_2 ) -> V_30 -> V_31 ) ;
V_23 = F_6 ( V_2 , & V_7 ) ;
if ( ! V_23 ) {
V_2 -> V_27 = V_18 ;
V_2 -> V_28 = V_19 ;
}
return V_23 ;
}
static void F_12 ( struct V_32 * V_33 ,
enum V_34 V_35 )
{
struct V_1 * V_2 = F_13 ( V_33 , struct V_1 , V_36 ) ;
unsigned long V_18 = 0 ;
if ( V_35 > 0 )
V_18 = V_29 ;
V_6 ( V_2 , V_18 , 0 ) ;
}
static int F_14 ( struct V_32 * V_33 ,
unsigned long * V_37 ,
unsigned long * V_38 )
{
struct V_1 * V_2 = F_13 ( V_33 , struct V_1 , V_36 ) ;
return V_6 ( V_2 , * V_37 , * V_38 ) ;
}
void F_15 ( struct V_1 * V_2 )
{
int V_39 = V_40 . V_41 ;
int V_23 ;
if ( V_39 == V_42 ) {
F_16 ( V_2 , L_4 ) ;
return;
}
if ( V_39 == V_43 )
V_39 = F_11 ( V_2 ) -> V_41 ;
V_2 -> V_36 . V_44 = F_17 ( V_45 , L_5 ,
F_18 ( V_2 -> V_46 -> V_47 ) ) ;
V_2 -> V_36 . V_48 = F_12 ;
V_2 -> V_36 . V_49 = F_14 ;
V_2 -> V_36 . V_50 = 1 ;
switch ( V_39 ) {
case V_43 :
F_19 ( 1 ) ;
break;
case V_51 :
V_2 -> V_36 . V_52 =
F_20 ( V_2 -> V_46 ,
V_53 ,
V_54 , F_21 ( V_54 ) ) ;
break;
case V_55 :
V_2 -> V_36 . V_52 =
F_22 ( V_2 -> V_46 ) ;
break;
}
V_23 = F_23 ( F_3 ( V_2 ) -> V_56 , & V_2 -> V_36 ) ;
if ( V_23 ) {
F_24 ( V_2 -> V_36 . V_44 ) ;
return;
}
V_2 -> V_57 = true ;
}
void F_25 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_57 )
return;
F_26 ( & V_2 -> V_36 ) ;
F_24 ( V_2 -> V_36 . V_44 ) ;
}
