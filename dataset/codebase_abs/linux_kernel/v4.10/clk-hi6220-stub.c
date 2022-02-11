static unsigned int F_1 ( struct V_1 * V_2 )
{
unsigned int V_3 ;
F_2 ( V_2 -> V_4 , V_5 , & V_3 ) ;
return V_3 ;
}
static int F_3 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
union V_6 V_7 ;
F_4 ( V_2 -> V_4 , V_8 , V_3 ) ;
V_7 . V_9 . type = V_10 ;
V_7 . V_9 . V_11 = V_12 ;
V_7 . V_9 . V_13 = V_14 ;
V_7 . V_9 . V_15 = V_14 ;
F_5 ( V_2 -> V_16 , & V_7 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
unsigned int V_17 , V_18 = V_19 ;
unsigned int V_20 ;
F_2 ( V_2 -> V_4 , V_21 , & V_17 ) ;
if ( V_17 == V_22 )
F_2 ( V_2 -> V_4 , V_23 , & V_18 ) ;
F_2 ( V_2 -> V_4 , V_24 , & V_20 ) ;
V_20 = F_7 ( V_20 , V_18 ) ;
if ( F_8 ( V_3 > V_20 ) )
V_3 = V_20 ;
return V_3 ;
}
static unsigned long F_9 ( struct V_25 * V_26 ,
unsigned long V_27 )
{
T_1 V_28 = 0 ;
struct V_1 * V_2 = F_10 ( V_26 ) ;
switch ( V_2 -> V_29 ) {
case V_30 :
V_28 = F_1 ( V_2 ) ;
V_28 *= 1000 ;
break;
default:
F_11 ( V_2 -> V_31 , L_1 ,
V_32 , V_2 -> V_29 ) ;
break;
}
return V_28 ;
}
static int F_12 ( struct V_25 * V_26 , unsigned long V_28 ,
unsigned long V_27 )
{
struct V_1 * V_2 = F_10 ( V_26 ) ;
unsigned long V_33 = V_28 / 1000 ;
int V_34 = 0 ;
switch ( V_2 -> V_29 ) {
case V_30 :
V_34 = F_3 ( V_2 , V_33 ) ;
if ( V_34 < 0 )
return V_34 ;
break;
default:
F_11 ( V_2 -> V_31 , L_1 ,
V_32 , V_2 -> V_29 ) ;
break;
}
F_13 ( L_2 , V_32 , V_33 ) ;
return V_34 ;
}
static long F_14 ( struct V_25 * V_26 , unsigned long V_28 ,
unsigned long * V_27 )
{
struct V_1 * V_2 = F_10 ( V_26 ) ;
unsigned long V_33 = V_28 / 1000 ;
switch ( V_2 -> V_29 ) {
case V_30 :
V_33 = F_6 ( V_2 , V_33 ) ;
V_33 *= 1000 ;
break;
default:
F_11 ( V_2 -> V_31 , L_1 ,
V_32 , V_2 -> V_29 ) ;
break;
}
return V_33 ;
}
static int F_15 ( struct V_35 * V_36 )
{
struct V_37 * V_31 = & V_36 -> V_31 ;
struct V_38 V_39 ;
struct V_1 * V_2 ;
struct V_40 * V_40 ;
struct V_41 * V_42 = V_36 -> V_31 . V_43 ;
int V_34 ;
V_2 = F_16 ( V_31 , sizeof( * V_2 ) , V_44 ) ;
if ( ! V_2 )
return - V_45 ;
V_2 -> V_4 = F_17 ( V_42 ,
L_3 ) ;
if ( F_18 ( V_2 -> V_4 ) ) {
F_11 ( V_31 , L_4 ) ;
return F_19 ( V_2 -> V_4 ) ;
}
V_2 -> V_26 . V_39 = & V_39 ;
V_2 -> V_31 = V_31 ;
V_2 -> V_29 = V_30 ;
V_2 -> V_46 . V_31 = V_31 ;
V_2 -> V_46 . V_47 = NULL ;
V_2 -> V_46 . V_48 = true ;
V_2 -> V_46 . V_49 = 500 ;
V_2 -> V_46 . V_50 = false ;
V_2 -> V_16 = F_20 ( & V_2 -> V_46 , 0 ) ;
if ( F_18 ( V_2 -> V_16 ) ) {
F_11 ( V_31 , L_5 ) ;
return F_19 ( V_2 -> V_16 ) ;
}
V_39 . V_51 = L_6 ;
V_39 . V_52 = & V_53 ;
V_39 . V_54 = 0 ;
V_39 . V_55 = 0 ;
V_40 = F_21 ( V_31 , & V_2 -> V_26 ) ;
if ( F_18 ( V_40 ) )
return F_19 ( V_40 ) ;
V_34 = F_22 ( V_42 , V_56 , V_40 ) ;
if ( V_34 ) {
F_11 ( V_31 , L_7 ) ;
return V_34 ;
}
F_4 ( V_2 -> V_4 , V_21 , 0x0 ) ;
F_4 ( V_2 -> V_4 , V_8 , 0x0 ) ;
F_4 ( V_2 -> V_4 , V_23 , 0x0 ) ;
F_23 ( V_31 , L_8 , V_39 . V_51 ) ;
return 0 ;
}
static int T_2 F_24 ( void )
{
return F_25 ( & V_57 ) ;
}
