static inline T_1 F_1 ( struct V_1 * V_2 )
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
static inline T_1 F_3 ( struct V_1 * V_2 )
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
T_1 V_37 , V_38 , V_39 ;
V_27 -> V_40 . V_41 = ( V_2 -> V_13 -> V_41 == V_42 ?
V_43 : V_44 ) ;
V_27 -> V_40 . V_45 = V_2 -> V_13 -> V_46 ;
V_27 -> V_40 . V_3 = F_1 ( V_2 ) ;
V_27 -> V_40 . V_47 = F_3 ( V_2 ) ;
V_37 = V_34 -> V_48 -> V_49 ;
V_39 = V_35 ;
V_38 = V_36 ;
V_27 -> V_50 = F_5 ( V_37 <<
V_51 ) ;
V_27 -> V_50 |= F_5 ( V_39 << V_52 ) ;
V_27 -> V_50 |= F_5 ( V_38 <<
V_53 ) ;
V_27 -> V_54 = F_5 ( V_34 -> V_48 -> V_55 ) ;
}
static int F_8 ( struct V_33 * V_34 ,
struct V_24 * V_25 ,
struct V_1 * V_2 ,
T_1 V_35 , T_1 V_36 ,
T_2 V_28 , T_2 V_29 )
{
struct V_26 V_27 ;
int V_56 ;
F_4 ( V_25 , & V_27 , V_28 , V_29 ) ;
F_7 ( V_34 , & V_27 , V_2 ,
V_35 , V_36 ) ;
V_56 = F_9 ( V_34 , V_57 , V_58 ,
sizeof( struct V_26 ) ,
& V_27 ) ;
if ( V_56 )
F_10 ( V_34 , L_3 , V_56 ) ;
return V_56 ;
}
static void F_11 ( struct V_59 * V_60 ,
struct V_61 * V_62 ,
void * V_63 )
{
struct V_64 * V_65 = V_63 ;
struct V_24 * V_66 = ( void * ) V_62 -> V_67 ;
F_12 ( V_66 -> V_31 , V_65 -> V_68 ) ;
}
int F_13 ( struct V_33 * V_34 , struct V_24 * V_25 ,
struct V_1 * V_2 ,
T_1 V_35 , T_1 V_36 )
{
struct V_64 V_65 = {
. V_68 = { } ,
} ;
if ( V_25 != & V_34 -> V_69 )
F_12 ( V_34 -> V_69 . V_31 , V_65 . V_68 ) ;
F_14 ( & V_34 -> V_70 ) ;
V_25 -> V_32 ++ ;
if ( ! F_15 ( V_71 , & V_34 -> V_72 ) ) {
F_16 (
V_34 -> V_60 , F_11 , & V_65 ) ;
V_25 -> V_31 = F_17 ( V_65 . V_68 , V_73 ) ;
if ( F_18 ( V_25 -> V_31 == V_73 ,
L_4 ) )
return - V_74 ;
}
V_25 -> V_45 = V_2 -> V_13 ;
return F_8 ( V_34 , V_25 , V_2 ,
V_35 , V_36 ,
V_75 , 0 ) ;
}
int F_19 ( struct V_33 * V_34 , struct V_24 * V_25 ,
struct V_1 * V_2 ,
T_1 V_35 , T_1 V_36 )
{
F_14 ( & V_34 -> V_70 ) ;
V_25 -> V_45 = V_2 -> V_13 ;
return F_8 ( V_34 , V_25 , V_2 ,
V_35 , V_36 ,
V_76 , 0 ) ;
}
void F_20 ( struct V_33 * V_34 , struct V_24 * V_25 )
{
struct V_26 V_27 ;
int V_56 ;
F_14 ( & V_34 -> V_70 ) ;
F_4 ( V_25 , & V_27 , V_77 , 0 ) ;
V_56 = F_9 ( V_34 , V_57 , V_58 ,
sizeof( struct V_26 ) ,
& V_27 ) ;
if ( V_56 )
F_10 ( V_34 , L_5 ,
V_25 -> V_31 ) ;
}
