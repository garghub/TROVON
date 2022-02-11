T_1 F_1 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_3 ) {
case V_4 :
case V_5 :
return V_6 ;
case V_7 :
return V_8 ;
case V_9 :
return V_10 ;
case V_11 :
return V_12 ;
default:
F_2 ( 1 , L_1 , V_2 -> V_3 ) ;
return V_6 ;
}
}
T_1 F_3 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_13 -> V_14 - V_2 -> V_15 ) {
case - 70 :
return V_16 ;
case - 50 :
return V_17 ;
case - 30 :
return V_18 ;
case - 10 :
return V_19 ;
case 10 :
return V_20 ;
case 30 :
return V_21 ;
case 50 :
return V_22 ;
case 70 :
return V_23 ;
default:
F_2 ( 1 , L_2 ) ;
case 0 :
return V_19 ;
}
}
static void F_4 ( struct V_24 * V_25 ,
struct V_26 * V_27 ,
T_2 V_28 , T_2 V_29 )
{
memset ( V_27 , 0 , sizeof( struct V_26 ) ) ;
V_27 -> V_30 = F_5 ( F_6 ( V_25 -> V_31 ,
V_25 -> V_32 ) ) ;
V_27 -> V_28 = F_5 ( V_28 ) ;
V_27 -> V_29 = F_5 ( V_29 ) ;
}
static void F_7 ( struct V_33 * V_34 ,
struct V_26 * V_27 ,
struct V_1 * V_2 ,
T_1 V_35 , T_1 V_36 )
{
T_1 V_37 , V_38 ;
V_27 -> V_39 . V_40 = ( V_2 -> V_13 -> V_40 == V_41 ?
V_42 : V_43 ) ;
V_27 -> V_39 . V_44 = V_2 -> V_13 -> V_45 ;
V_27 -> V_39 . V_3 = F_1 ( V_2 ) ;
V_27 -> V_39 . V_46 = F_3 ( V_2 ) ;
V_38 = V_35 ;
V_37 = V_36 ;
if ( V_37 == 1 && F_8 ( V_34 ) ) {
V_38 = 2 ;
V_37 = 2 ;
}
V_27 -> V_47 = F_5 ( F_9 ( V_34 ) <<
V_48 ) ;
V_27 -> V_47 |= F_5 ( V_38 << V_49 ) ;
V_27 -> V_47 |= F_5 ( V_37 <<
V_50 ) ;
V_27 -> V_51 = F_5 ( F_10 ( V_34 ) ) ;
}
static int F_11 ( struct V_33 * V_34 ,
struct V_24 * V_25 ,
struct V_1 * V_2 ,
T_1 V_35 , T_1 V_36 ,
T_2 V_28 , T_2 V_29 )
{
struct V_26 V_27 ;
int V_52 ;
F_4 ( V_25 , & V_27 , V_28 , V_29 ) ;
F_7 ( V_34 , & V_27 , V_2 ,
V_35 , V_36 ) ;
V_52 = F_12 ( V_34 , V_53 , 0 ,
sizeof( struct V_26 ) ,
& V_27 ) ;
if ( V_52 )
F_13 ( V_34 , L_3 , V_52 ) ;
return V_52 ;
}
int F_14 ( struct V_33 * V_34 , struct V_24 * V_25 ,
struct V_1 * V_2 ,
T_1 V_35 , T_1 V_36 )
{
F_15 ( ! F_16 ( V_54 , & V_34 -> V_55 ) &&
V_25 -> V_56 ) ;
F_17 ( & V_34 -> V_57 ) ;
V_25 -> V_44 = V_2 -> V_13 ;
return F_11 ( V_34 , V_25 , V_2 ,
V_35 , V_36 ,
V_58 , 0 ) ;
}
void F_18 ( struct V_33 * V_34 , struct V_24 * V_25 )
{
F_17 ( & V_34 -> V_57 ) ;
V_25 -> V_56 ++ ;
}
int F_19 ( struct V_33 * V_34 , struct V_24 * V_25 ,
struct V_1 * V_2 ,
T_1 V_35 , T_1 V_36 )
{
F_17 ( & V_34 -> V_57 ) ;
V_25 -> V_44 = V_2 -> V_13 ;
return F_11 ( V_34 , V_25 , V_2 ,
V_35 , V_36 ,
V_59 , 0 ) ;
}
void F_20 ( struct V_33 * V_34 , struct V_24 * V_25 )
{
F_17 ( & V_34 -> V_57 ) ;
if ( F_21 ( ! V_25 ) )
return;
V_25 -> V_56 -- ;
}
static void F_22 ( void * V_60 , T_1 * V_61 ,
struct V_62 * V_63 )
{
unsigned long * V_64 = V_60 ;
struct V_65 * V_66 = F_23 ( V_63 ) ;
if ( ! V_66 -> V_67 )
return;
if ( V_63 -> type == V_68 ||
V_63 -> type == V_69 )
F_24 ( V_66 -> V_67 -> V_31 , V_64 ) ;
}
int F_25 ( struct V_33 * V_34 )
{
unsigned long V_70 = 0 ;
F_26 ( V_34 -> V_71 ,
V_72 ,
F_22 ,
& V_70 ) ;
return F_27 ( V_70 ) ;
}
