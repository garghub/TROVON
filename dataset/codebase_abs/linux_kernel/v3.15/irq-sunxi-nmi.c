static inline void F_1 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_4 )
{
F_2 ( V_4 , V_2 -> V_5 + V_3 ) ;
}
static inline T_1 F_3 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_4 ( V_2 -> V_5 + V_3 ) ;
}
static void F_5 ( unsigned int V_6 , struct V_7 * V_8 )
{
struct V_9 * V_10 = F_6 ( V_8 ) ;
struct V_11 * V_12 = F_7 ( V_6 ) ;
unsigned int V_13 = F_8 ( V_10 , 0 ) ;
F_9 ( V_12 , V_8 ) ;
F_10 ( V_13 ) ;
F_11 ( V_12 , V_8 ) ;
}
static int F_12 ( struct V_14 * V_15 , unsigned int V_16 )
{
struct V_1 * V_2 = F_13 ( V_15 ) ;
struct V_17 * V_18 = V_2 -> V_19 ;
T_1 V_20 ;
T_1 V_21 = V_18 -> V_22 . type ;
unsigned int V_23 ;
unsigned int V_24 ;
F_14 ( V_2 ) ;
switch ( V_16 & V_25 ) {
case V_26 :
V_23 = V_27 ;
break;
case V_28 :
V_23 = V_29 ;
break;
case V_30 :
V_23 = V_31 ;
break;
case V_32 :
case V_33 :
V_23 = V_34 ;
break;
default:
F_15 ( V_2 ) ;
F_16 ( L_1 ,
V_35 , V_15 -> V_6 ) ;
return - V_36 ;
}
F_17 ( V_15 , V_16 ) ;
F_18 ( V_15 , V_16 ) ;
for ( V_24 = 0 ; V_24 <= V_2 -> V_37 ; V_24 ++ , V_18 ++ )
if ( V_18 -> type & V_16 )
V_21 = V_18 -> V_22 . type ;
V_20 = F_3 ( V_2 , V_21 ) ;
V_20 &= ~ V_38 ;
V_20 |= V_23 ;
F_1 ( V_2 , V_21 , V_20 ) ;
F_15 ( V_2 ) ;
return V_39 ;
}
static int T_2 F_19 ( struct V_40 * V_41 ,
struct V_42 * V_43 )
{
struct V_9 * V_10 ;
struct V_1 * V_2 ;
unsigned int V_6 ;
unsigned int V_44 = V_45 | V_46 | V_47 ;
int V_48 ;
V_10 = F_20 ( V_41 , 1 , & V_49 , NULL ) ;
if ( ! V_10 ) {
F_16 ( L_2 , V_41 -> V_50 ) ;
return - V_51 ;
}
V_48 = F_21 ( V_10 , 1 , 2 , V_41 -> V_50 ,
V_52 , V_44 , 0 ,
V_53 ) ;
if ( V_48 ) {
F_16 ( L_3 ,
V_41 -> V_50 ) ;
goto V_54;
}
V_6 = F_22 ( V_41 , 0 ) ;
if ( V_6 <= 0 ) {
F_16 ( L_4 , V_41 -> V_50 ) ;
V_48 = - V_55 ;
goto V_54;
}
V_2 = F_23 ( V_10 , 0 ) ;
V_2 -> V_5 = F_24 ( V_41 , 0 ) ;
if ( ! V_2 -> V_5 ) {
F_16 ( L_5 , V_41 -> V_50 ) ;
V_48 = - V_51 ;
goto V_54;
}
V_2 -> V_19 [ 0 ] . type = V_56 ;
V_2 -> V_19 [ 0 ] . V_12 . V_57 = V_58 ;
V_2 -> V_19 [ 0 ] . V_12 . V_59 = V_60 ;
V_2 -> V_19 [ 0 ] . V_12 . V_61 = V_62 ;
V_2 -> V_19 [ 0 ] . V_12 . V_63 = F_12 ;
V_2 -> V_19 [ 0 ] . V_12 . V_64 = V_65 | V_66 ;
V_2 -> V_19 [ 0 ] . V_22 . V_67 = V_43 -> V_68 ;
V_2 -> V_19 [ 0 ] . V_22 . V_69 = V_43 -> V_70 ;
V_2 -> V_19 [ 0 ] . V_22 . type = V_43 -> V_71 ;
V_2 -> V_19 [ 1 ] . type = V_72 ;
V_2 -> V_19 [ 1 ] . V_12 . V_50 = V_2 -> V_19 [ 0 ] . V_12 . V_50 ;
V_2 -> V_19 [ 1 ] . V_12 . V_73 = V_62 ;
V_2 -> V_19 [ 1 ] . V_12 . V_57 = V_58 ;
V_2 -> V_19 [ 1 ] . V_12 . V_59 = V_60 ;
V_2 -> V_19 [ 1 ] . V_12 . V_63 = F_12 ;
V_2 -> V_19 [ 1 ] . V_22 . V_67 = V_43 -> V_68 ;
V_2 -> V_19 [ 1 ] . V_22 . V_69 = V_43 -> V_70 ;
V_2 -> V_19 [ 1 ] . V_22 . type = V_43 -> V_71 ;
V_2 -> V_19 [ 1 ] . V_74 = V_75 ;
F_1 ( V_2 , V_43 -> V_70 , 0 ) ;
F_1 ( V_2 , V_43 -> V_68 , 0x1 ) ;
F_25 ( V_6 , V_10 ) ;
F_26 ( V_6 , F_5 ) ;
return 0 ;
V_54:
F_27 ( V_10 ) ;
return V_48 ;
}
static int T_2 F_28 ( struct V_40 * V_41 ,
struct V_40 * V_76 )
{
return F_19 ( V_41 , & V_77 ) ;
}
static int T_2 F_29 ( struct V_40 * V_41 ,
struct V_40 * V_76 )
{
return F_19 ( V_41 , & V_78 ) ;
}
