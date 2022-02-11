static inline void F_1 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_4 )
{
F_2 ( V_2 , V_4 , V_3 ) ;
}
static inline T_1 F_3 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_4 ( V_2 , V_3 ) ;
}
static void F_5 ( unsigned int V_5 , struct V_6 * V_7 )
{
struct V_8 * V_9 = F_6 ( V_7 ) ;
struct V_10 * V_11 = F_7 ( V_5 ) ;
unsigned int V_12 = F_8 ( V_9 , 0 ) ;
F_9 ( V_11 , V_7 ) ;
F_10 ( V_12 ) ;
F_11 ( V_11 , V_7 ) ;
}
static int F_12 ( struct V_13 * V_14 , unsigned int V_15 )
{
struct V_1 * V_2 = F_13 ( V_14 ) ;
struct V_16 * V_17 = V_2 -> V_18 ;
T_1 V_19 ;
T_1 V_20 = V_17 -> V_21 . type ;
unsigned int V_22 ;
unsigned int V_23 ;
F_14 ( V_2 ) ;
switch ( V_15 & V_24 ) {
case V_25 :
V_22 = V_26 ;
break;
case V_27 :
V_22 = V_28 ;
break;
case V_29 :
V_22 = V_30 ;
break;
case V_31 :
case V_32 :
V_22 = V_33 ;
break;
default:
F_15 ( V_2 ) ;
F_16 ( L_1 ,
V_34 , V_14 -> V_5 ) ;
return - V_35 ;
}
F_17 ( V_14 , V_15 ) ;
F_18 ( V_14 , V_15 ) ;
for ( V_23 = 0 ; V_23 < V_2 -> V_36 ; V_23 ++ , V_17 ++ )
if ( V_17 -> type & V_15 )
V_20 = V_17 -> V_21 . type ;
V_19 = F_3 ( V_2 , V_20 ) ;
V_19 &= ~ V_37 ;
V_19 |= V_22 ;
F_1 ( V_2 , V_20 , V_19 ) ;
F_15 ( V_2 ) ;
return V_38 ;
}
static int T_2 F_19 ( struct V_39 * V_40 ,
struct V_41 * V_42 )
{
struct V_8 * V_9 ;
struct V_1 * V_2 ;
unsigned int V_5 ;
unsigned int V_43 = V_44 | V_45 | V_46 ;
int V_47 ;
V_9 = F_20 ( V_40 , 1 , & V_48 , NULL ) ;
if ( ! V_9 ) {
F_16 ( L_2 , V_40 -> V_49 ) ;
return - V_50 ;
}
V_47 = F_21 ( V_9 , 1 , 2 , V_40 -> V_49 ,
V_51 , V_43 , 0 ,
V_52 ) ;
if ( V_47 ) {
F_16 ( L_3 ,
V_40 -> V_49 ) ;
goto V_53;
}
V_5 = F_22 ( V_40 , 0 ) ;
if ( V_5 <= 0 ) {
F_16 ( L_4 , V_40 -> V_49 ) ;
V_47 = - V_54 ;
goto V_53;
}
V_2 = F_23 ( V_9 , 0 ) ;
V_2 -> V_55 = F_24 ( V_40 , 0 ) ;
if ( ! V_2 -> V_55 ) {
F_16 ( L_5 , V_40 -> V_49 ) ;
V_47 = - V_50 ;
goto V_53;
}
V_2 -> V_18 [ 0 ] . type = V_56 ;
V_2 -> V_18 [ 0 ] . V_11 . V_57 = V_58 ;
V_2 -> V_18 [ 0 ] . V_11 . V_59 = V_60 ;
V_2 -> V_18 [ 0 ] . V_11 . V_61 = V_62 ;
V_2 -> V_18 [ 0 ] . V_11 . V_63 = F_12 ;
V_2 -> V_18 [ 0 ] . V_11 . V_64 = V_65 | V_66 ;
V_2 -> V_18 [ 0 ] . V_21 . V_67 = V_42 -> V_68 ;
V_2 -> V_18 [ 0 ] . V_21 . V_69 = V_42 -> V_70 ;
V_2 -> V_18 [ 0 ] . V_21 . type = V_42 -> V_71 ;
V_2 -> V_18 [ 1 ] . type = V_72 ;
V_2 -> V_18 [ 1 ] . V_11 . V_49 = V_2 -> V_18 [ 0 ] . V_11 . V_49 ;
V_2 -> V_18 [ 1 ] . V_11 . V_73 = V_62 ;
V_2 -> V_18 [ 1 ] . V_11 . V_57 = V_58 ;
V_2 -> V_18 [ 1 ] . V_11 . V_59 = V_60 ;
V_2 -> V_18 [ 1 ] . V_11 . V_63 = F_12 ;
V_2 -> V_18 [ 1 ] . V_21 . V_67 = V_42 -> V_68 ;
V_2 -> V_18 [ 1 ] . V_21 . V_69 = V_42 -> V_70 ;
V_2 -> V_18 [ 1 ] . V_21 . type = V_42 -> V_71 ;
V_2 -> V_18 [ 1 ] . V_74 = V_75 ;
F_1 ( V_2 , V_42 -> V_70 , 0 ) ;
F_1 ( V_2 , V_42 -> V_68 , 0x1 ) ;
F_25 ( V_5 , V_9 ) ;
F_26 ( V_5 , F_5 ) ;
return 0 ;
V_53:
F_27 ( V_9 ) ;
return V_47 ;
}
static int T_2 F_28 ( struct V_39 * V_40 ,
struct V_39 * V_76 )
{
return F_19 ( V_40 , & V_77 ) ;
}
static int T_2 F_29 ( struct V_39 * V_40 ,
struct V_39 * V_76 )
{
return F_19 ( V_40 , & V_78 ) ;
}
