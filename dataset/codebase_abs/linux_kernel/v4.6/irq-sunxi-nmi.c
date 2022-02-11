static inline void F_1 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_4 )
{
F_2 ( V_2 , V_4 , V_3 ) ;
}
static inline T_1 F_3 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_4 ( V_2 , V_3 ) ;
}
static void F_5 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_6 ( V_6 ) ;
struct V_9 * V_10 = F_7 ( V_6 ) ;
unsigned int V_11 = F_8 ( V_8 , 0 ) ;
F_9 ( V_10 , V_6 ) ;
F_10 ( V_11 ) ;
F_11 ( V_10 , V_6 ) ;
}
static int F_12 ( struct V_12 * V_13 , unsigned int V_14 )
{
struct V_1 * V_2 = F_13 ( V_13 ) ;
struct V_15 * V_16 = V_2 -> V_17 ;
T_1 V_18 ;
T_1 V_19 = V_16 -> V_20 . type ;
unsigned int V_21 ;
unsigned int V_22 ;
F_14 ( V_2 ) ;
switch ( V_14 & V_23 ) {
case V_24 :
V_21 = V_25 ;
break;
case V_26 :
V_21 = V_27 ;
break;
case V_28 :
V_21 = V_29 ;
break;
case V_30 :
case V_31 :
V_21 = V_32 ;
break;
default:
F_15 ( V_2 ) ;
F_16 ( L_1 ,
V_13 -> V_33 ) ;
return - V_34 ;
}
F_17 ( V_13 , V_14 ) ;
F_18 ( V_13 , V_14 ) ;
for ( V_22 = 0 ; V_22 < V_2 -> V_35 ; V_22 ++ , V_16 ++ )
if ( V_16 -> type & V_14 )
V_19 = V_16 -> V_20 . type ;
V_18 = F_3 ( V_2 , V_19 ) ;
V_18 &= ~ V_36 ;
V_18 |= V_21 ;
F_1 ( V_2 , V_19 , V_18 ) ;
F_15 ( V_2 ) ;
return V_37 ;
}
static int T_2 F_19 ( struct V_38 * V_39 ,
struct V_40 * V_41 )
{
struct V_7 * V_8 ;
struct V_1 * V_2 ;
unsigned int V_33 ;
unsigned int V_42 = V_43 | V_44 | V_45 ;
int V_46 ;
V_8 = F_20 ( V_39 , 1 , & V_47 , NULL ) ;
if ( ! V_8 ) {
F_16 ( L_2 ) ;
return - V_48 ;
}
V_46 = F_21 ( V_8 , 1 , 2 , V_49 ,
V_50 , V_42 , 0 ,
V_51 ) ;
if ( V_46 ) {
F_16 ( L_3 ) ;
goto V_52;
}
V_33 = F_22 ( V_39 , 0 ) ;
if ( V_33 <= 0 ) {
F_16 ( L_4 ) ;
V_46 = - V_53 ;
goto V_52;
}
V_2 = F_23 ( V_8 , 0 ) ;
V_2 -> V_54 = F_24 ( V_39 , 0 , F_25 ( V_39 ) ) ;
if ( F_26 ( V_2 -> V_54 ) ) {
F_16 ( L_5 ) ;
V_46 = F_27 ( V_2 -> V_54 ) ;
goto V_52;
}
V_2 -> V_17 [ 0 ] . type = V_55 ;
V_2 -> V_17 [ 0 ] . V_10 . V_56 = V_57 ;
V_2 -> V_17 [ 0 ] . V_10 . V_58 = V_59 ;
V_2 -> V_17 [ 0 ] . V_10 . V_60 = V_61 ;
V_2 -> V_17 [ 0 ] . V_10 . V_62 = F_12 ;
V_2 -> V_17 [ 0 ] . V_10 . V_63 = V_64 | V_65 ;
V_2 -> V_17 [ 0 ] . V_20 . V_66 = V_41 -> V_67 ;
V_2 -> V_17 [ 0 ] . V_20 . V_68 = V_41 -> V_69 ;
V_2 -> V_17 [ 0 ] . V_20 . type = V_41 -> V_70 ;
V_2 -> V_17 [ 1 ] . type = V_71 ;
V_2 -> V_17 [ 1 ] . V_10 . V_72 = V_2 -> V_17 [ 0 ] . V_10 . V_72 ;
V_2 -> V_17 [ 1 ] . V_10 . V_73 = V_61 ;
V_2 -> V_17 [ 1 ] . V_10 . V_56 = V_57 ;
V_2 -> V_17 [ 1 ] . V_10 . V_58 = V_59 ;
V_2 -> V_17 [ 1 ] . V_10 . V_62 = F_12 ;
V_2 -> V_17 [ 1 ] . V_20 . V_66 = V_41 -> V_67 ;
V_2 -> V_17 [ 1 ] . V_20 . V_68 = V_41 -> V_69 ;
V_2 -> V_17 [ 1 ] . V_20 . type = V_41 -> V_70 ;
V_2 -> V_17 [ 1 ] . V_74 = V_75 ;
F_1 ( V_2 , V_41 -> V_69 , 0 ) ;
F_1 ( V_2 , V_41 -> V_67 , 0x1 ) ;
F_28 ( V_33 , F_5 , V_8 ) ;
return 0 ;
V_52:
F_29 ( V_8 ) ;
return V_46 ;
}
static int T_2 F_30 ( struct V_38 * V_39 ,
struct V_38 * V_76 )
{
return F_19 ( V_39 , & V_77 ) ;
}
static int T_2 F_31 ( struct V_38 * V_39 ,
struct V_38 * V_76 )
{
return F_19 ( V_39 , & V_78 ) ;
}
static int T_2 F_32 ( struct V_38 * V_39 ,
struct V_38 * V_76 )
{
return F_19 ( V_39 , & V_79 ) ;
}
