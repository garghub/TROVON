static inline void F_1 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_4 )
{
F_2 ( V_4 , V_2 -> V_5 + V_3 ) ;
}
static inline T_1 F_3 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_4 ( V_2 -> V_5 + V_3 ) ;
}
static int F_5 ( struct V_6 * V_7 , unsigned int V_8 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
T_2 V_9 , V_10 , V_11 ;
V_9 = V_7 -> V_12 ;
F_7 ( V_2 ) ;
V_10 = F_3 ( V_2 , V_13 ) | V_9 ;
V_11 = F_3 ( V_2 , V_14 ) | V_9 ;
switch ( V_8 & V_15 ) {
case V_16 :
V_11 ^= V_9 ;
break;
case V_17 :
V_10 ^= V_9 ;
break;
case V_18 :
V_8 = V_19 ;
case V_19 :
V_10 ^= V_9 ;
V_11 ^= V_9 ;
break;
case V_20 :
break;
default:
F_8 ( V_2 ) ;
F_9 ( L_1 ,
V_21 , V_7 -> V_22 ) ;
return - V_23 ;
}
F_10 ( V_7 , V_8 ) ;
F_11 ( V_7 , V_8 ) ;
F_1 ( V_2 , V_13 , V_10 ) ;
F_1 ( V_2 , V_14 , V_11 ) ;
F_1 ( V_2 , V_24 , V_9 ) ;
F_8 ( V_2 ) ;
return V_25 ;
}
static void F_12 ( unsigned int V_22 , struct V_26 * V_27 )
{
struct V_28 * V_29 = F_13 ( V_27 ) ;
F_14 ( F_15 ( V_29 , V_22 ) ) ;
}
static int T_3 F_16 ( struct V_30 * V_31 ,
struct V_30 * V_32 )
{
int V_33 , V_34 , V_35 = F_17 ( V_31 ) ;
struct V_36 V_37 ;
struct V_1 * V_2 ;
struct V_28 * V_29 ;
void T_4 * V_5 ;
if ( F_18 ( V_31 , 0 , & V_37 ) ) {
F_9 ( L_2 ,
V_31 -> V_38 ) ;
return - V_39 ;
}
if ( ! F_19 ( V_37 . V_40 , F_20 ( & V_37 ) ,
V_31 -> V_38 ) ) {
F_9 ( L_3 , V_31 -> V_38 ) ;
return - V_41 ;
}
V_5 = F_21 ( V_37 . V_40 , F_20 ( & V_37 ) ) ;
if ( ! V_5 ) {
V_34 = - V_41 ;
F_9 ( L_4 , V_31 -> V_38 ) ;
goto V_42;
}
V_29 = F_22 ( V_31 , V_43 ,
& V_44 , NULL ) ;
if ( ! V_29 ) {
V_34 = - V_45 ;
F_9 ( L_5 ,
V_31 -> V_38 ) ;
goto V_46;
}
V_34 = F_23 ( V_29 , V_43 ,
2 , V_31 -> V_38 , V_47 ,
V_48 , V_49 ,
V_50 ) ;
if ( V_34 ) {
F_9 ( L_6 ,
V_31 -> V_38 ) ;
goto V_51;
}
V_2 = V_29 -> V_2 -> V_2 [ 0 ] ;
V_2 -> V_5 = V_5 ;
V_2 -> V_52 [ 0 ] . type = V_53 ;
V_2 -> V_52 [ 0 ] . V_54 . V_55 = V_56 ;
V_2 -> V_52 [ 0 ] . V_54 . V_57 = V_58 ;
V_2 -> V_52 [ 0 ] . V_54 . V_59 = F_5 ;
V_2 -> V_52 [ 0 ] . V_60 . V_12 = V_61 ;
V_2 -> V_52 [ 1 ] . type = V_62 ;
V_2 -> V_52 [ 1 ] . V_54 . V_38 = V_2 -> V_52 [ 0 ] . V_54 . V_38 ;
V_2 -> V_52 [ 1 ] . V_54 . V_63 = V_64 ;
V_2 -> V_52 [ 1 ] . V_54 . V_55 = V_56 ;
V_2 -> V_52 [ 1 ] . V_54 . V_57 = V_58 ;
V_2 -> V_52 [ 1 ] . V_54 . V_59 = F_5 ;
V_2 -> V_52 [ 1 ] . V_60 . V_65 = V_24 ;
V_2 -> V_52 [ 1 ] . V_60 . V_12 = V_61 ;
V_2 -> V_52 [ 1 ] . V_66 = V_67 ;
for ( V_33 = 0 ; V_33 < V_35 ; V_33 ++ ) {
unsigned int V_22 = F_24 ( V_31 , V_33 ) ;
F_25 ( V_22 , V_29 ) ;
F_26 ( V_22 , F_12 ) ;
}
F_1 ( V_2 , V_61 , 0 ) ;
F_1 ( V_2 , V_68 , 0 ) ;
F_1 ( V_2 , V_69 , 0 ) ;
F_1 ( V_2 , V_24 , ~ 0UL ) ;
return 0 ;
V_51:
F_27 ( V_29 ) ;
V_46:
F_28 ( V_5 ) ;
V_42:
F_29 ( V_37 . V_40 , F_20 ( & V_37 ) ) ;
return V_34 ;
}
