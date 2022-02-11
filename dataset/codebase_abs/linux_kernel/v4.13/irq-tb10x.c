static inline void F_1 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_4 )
{
F_2 ( V_2 , V_4 , V_3 ) ;
}
static inline T_1 F_3 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_4 ( V_2 , V_3 ) ;
}
static int F_5 ( struct V_5 * V_6 , unsigned int V_7 )
{
struct V_1 * V_2 = F_6 ( V_6 ) ;
T_2 V_8 , V_9 , V_10 ;
V_8 = V_6 -> V_11 ;
F_7 ( V_2 ) ;
V_9 = F_3 ( V_2 , V_12 ) | V_8 ;
V_10 = F_3 ( V_2 , V_13 ) | V_8 ;
switch ( V_7 & V_14 ) {
case V_15 :
V_10 ^= V_8 ;
break;
case V_16 :
V_9 ^= V_8 ;
break;
case V_17 :
V_7 = V_18 ;
case V_18 :
V_9 ^= V_8 ;
V_10 ^= V_8 ;
break;
case V_19 :
break;
default:
F_8 ( V_2 ) ;
F_9 ( L_1 ,
V_20 , V_6 -> V_21 ) ;
return - V_22 ;
}
F_10 ( V_6 , V_7 ) ;
F_11 ( V_6 , V_7 ) ;
F_1 ( V_2 , V_12 , V_9 ) ;
F_1 ( V_2 , V_13 , V_10 ) ;
F_1 ( V_2 , V_23 , V_8 ) ;
F_8 ( V_2 ) ;
return V_24 ;
}
static void F_12 ( struct V_25 * V_26 )
{
struct V_27 * V_28 = F_13 ( V_26 ) ;
unsigned int V_21 = F_14 ( V_26 ) ;
F_15 ( F_16 ( V_28 , V_21 ) ) ;
}
static int T_3 F_17 ( struct V_29 * V_30 ,
struct V_29 * V_31 )
{
int V_32 , V_33 , V_34 = F_18 ( V_30 ) ;
struct V_35 V_36 ;
struct V_1 * V_2 ;
struct V_27 * V_28 ;
void T_4 * V_37 ;
if ( F_19 ( V_30 , 0 , & V_36 ) ) {
F_9 ( L_2 ,
V_30 -> V_38 ) ;
return - V_39 ;
}
if ( ! F_20 ( V_36 . V_40 , F_21 ( & V_36 ) ,
V_30 -> V_38 ) ) {
F_9 ( L_3 , V_30 -> V_38 ) ;
return - V_41 ;
}
V_37 = F_22 ( V_36 . V_40 , F_21 ( & V_36 ) ) ;
if ( ! V_37 ) {
V_33 = - V_41 ;
F_9 ( L_4 , V_30 -> V_38 ) ;
goto V_42;
}
V_28 = F_23 ( V_30 , V_43 ,
& V_44 , NULL ) ;
if ( ! V_28 ) {
V_33 = - V_45 ;
F_9 ( L_5 ,
V_30 -> V_38 ) ;
goto V_46;
}
V_33 = F_24 ( V_28 , V_43 ,
2 , V_30 -> V_38 , V_47 ,
V_48 , V_49 ,
V_50 ) ;
if ( V_33 ) {
F_9 ( L_6 ,
V_30 -> V_38 ) ;
goto V_51;
}
V_2 = V_28 -> V_2 -> V_2 [ 0 ] ;
V_2 -> V_37 = V_37 ;
V_2 -> V_52 [ 0 ] . type = V_53 ;
V_2 -> V_52 [ 0 ] . V_54 . V_55 = V_56 ;
V_2 -> V_52 [ 0 ] . V_54 . V_57 = V_58 ;
V_2 -> V_52 [ 0 ] . V_54 . V_59 = F_5 ;
V_2 -> V_52 [ 0 ] . V_60 . V_11 = V_61 ;
V_2 -> V_52 [ 1 ] . type = V_62 ;
V_2 -> V_52 [ 1 ] . V_54 . V_38 = V_2 -> V_52 [ 0 ] . V_54 . V_38 ;
V_2 -> V_52 [ 1 ] . V_54 . V_63 = V_64 ;
V_2 -> V_52 [ 1 ] . V_54 . V_55 = V_56 ;
V_2 -> V_52 [ 1 ] . V_54 . V_57 = V_58 ;
V_2 -> V_52 [ 1 ] . V_54 . V_59 = F_5 ;
V_2 -> V_52 [ 1 ] . V_60 . V_65 = V_23 ;
V_2 -> V_52 [ 1 ] . V_60 . V_11 = V_61 ;
V_2 -> V_52 [ 1 ] . V_66 = V_67 ;
for ( V_32 = 0 ; V_32 < V_34 ; V_32 ++ ) {
unsigned int V_21 = F_25 ( V_30 , V_32 ) ;
F_26 ( V_21 , F_12 ,
V_28 ) ;
}
F_1 ( V_2 , V_61 , 0 ) ;
F_1 ( V_2 , V_68 , 0 ) ;
F_1 ( V_2 , V_69 , 0 ) ;
F_1 ( V_2 , V_23 , ~ 0UL ) ;
return 0 ;
V_51:
F_27 ( V_28 ) ;
V_46:
F_28 ( V_37 ) ;
V_42:
F_29 ( V_36 . V_40 , F_21 ( & V_36 ) ) ;
return V_33 ;
}
