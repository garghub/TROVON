static inline T_1 F_1 ( struct V_1 * V_2 , int V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static inline void F_3 ( struct V_1 * V_2 , int V_3 , T_1 V_5 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static void F_5 ( struct V_6 * V_7 , unsigned int V_8 ,
int V_4 )
{
unsigned int V_9 ;
unsigned int V_10 ;
while ( V_8 ) {
V_9 = F_6 ( V_8 ) ;
V_10 = F_7 ( V_7 , V_4 + V_9 ) ;
if ( V_10 )
F_8 ( V_10 ) ;
V_8 &= ~ F_9 ( V_9 ) ;
}
}
static void F_10 ( struct V_11 * V_12 )
{
struct V_6 * V_7 = F_11 ( V_12 ) ;
struct V_13 * V_14 = F_12 ( V_12 ) ;
struct V_1 * V_2 = V_7 -> V_15 ;
unsigned int V_16 , V_17 ;
F_13 ( V_14 , V_12 ) ;
V_16 = F_1 ( V_2 , V_2 -> V_18 + V_19 ) ;
V_17 = F_1 ( V_2 , V_2 -> V_18 + V_20 + V_19 ) ;
F_5 ( V_7 , V_16 , 0 ) ;
F_5 ( V_7 , V_17 , 32 ) ;
F_14 ( V_14 , V_12 ) ;
}
static int F_15 ( struct V_21 * V_22 , unsigned int V_23 )
{
struct V_24 * V_25 = F_16 ( V_22 ) ;
struct V_1 * V_2 = V_25 -> V_26 -> V_15 ;
struct V_27 * V_28 = & V_25 -> V_29 [ 0 ] . V_28 ;
switch ( V_23 & V_30 ) {
case V_31 :
F_3 ( V_2 , V_28 -> type + V_32 , V_22 -> V_33 ) ;
F_3 ( V_2 , V_28 -> type + V_34 , V_22 -> V_33 ) ;
break;
case V_35 :
F_3 ( V_2 , V_28 -> type + V_36 , V_22 -> V_33 ) ;
F_3 ( V_2 , V_28 -> type + V_37 , V_22 -> V_33 ) ;
break;
case V_38 :
F_3 ( V_2 , V_28 -> type + V_36 , V_22 -> V_33 ) ;
F_3 ( V_2 , V_28 -> type + V_34 , V_22 -> V_33 ) ;
break;
case V_39 :
F_3 ( V_2 , V_28 -> type + V_32 , V_22 -> V_33 ) ;
F_3 ( V_2 , V_28 -> type + V_37 , V_22 -> V_33 ) ;
break;
default:
F_17 ( L_1 ,
V_23 , V_22 -> V_40 ) ;
return - V_41 ;
}
return F_18 ( V_22 , V_23 ) ;
}
static void T_2 F_19 ( struct V_24 * V_25 ,
unsigned long V_42 ,
unsigned long V_43 )
{
struct V_1 * V_2 = V_25 -> V_26 -> V_15 ;
struct V_44 * V_45 = V_25 -> V_29 ;
unsigned long V_46 = V_2 -> V_18 + V_42 ;
unsigned long V_47 = V_48 + V_43 ;
int V_49 ;
V_25 -> V_50 = V_2 -> V_4 ;
V_25 -> V_51 = 0 ;
for ( V_49 = 0 ; V_49 < 2 ; V_49 ++ ) {
V_45 [ V_49 ] . V_2 . V_52 = V_53 ;
V_45 [ V_49 ] . V_2 . V_54 = V_55 ;
V_45 [ V_49 ] . V_2 . V_56 = V_57 ;
V_45 [ V_49 ] . V_2 . V_58 = V_59 ;
V_45 [ V_49 ] . V_2 . V_60 = F_15 ;
V_45 [ V_49 ] . V_2 . V_61 = V_25 -> V_26 -> V_61 ;
V_45 [ V_49 ] . V_28 . V_62 = V_46 + V_63 ;
V_45 [ V_49 ] . V_28 . V_64 = V_46 + V_65 ;
V_45 [ V_49 ] . V_28 . V_66 = V_47 + V_67 ;
V_45 [ V_49 ] . V_28 . type = V_47 ;
}
V_45 [ 0 ] . type = V_68 ;
V_45 [ 0 ] . V_69 = V_70 ;
V_45 [ 1 ] . type = V_71 ;
V_45 [ 1 ] . V_69 = V_72 ;
F_3 ( V_2 , V_45 -> V_28 . V_64 , 0xffffffff ) ;
F_3 ( V_2 , V_45 -> V_28 . V_66 , 0xffffffff ) ;
}
static void T_2 F_20 ( struct V_6 * V_7 )
{
struct V_24 * V_25 ;
int V_49 ;
for ( V_49 = 0 ; V_49 < 2 ; V_49 ++ ) {
V_25 = F_21 ( V_7 , V_49 * 32 ) ;
F_19 ( V_25 , V_49 * V_20 , V_49 * V_73 ) ;
}
}
static int T_2 F_22 ( void T_3 * V_4 , struct V_74 * V_75 ,
struct V_76 * V_77 )
{
struct V_1 * V_2 ;
struct V_6 * V_7 ;
struct V_74 V_78 ;
int V_40 ;
int V_79 ;
V_40 = F_23 ( V_77 , 0 ) ;
if ( ! V_40 )
F_24 ( L_2 , V_77 -> V_61 ) ;
V_79 = F_25 ( V_77 , 0 , & V_78 ) ;
if ( V_79 )
F_24 ( L_3 , V_77 -> V_61 ) ;
V_2 = F_26 ( sizeof( * V_2 ) , V_80 ) ;
V_2 -> V_18 = V_78 . V_81 - V_75 -> V_81 ;
V_2 -> V_4 = V_4 ;
V_7 = F_27 ( V_77 , 64 , & V_82 , V_2 ) ;
if ( ! V_7 )
F_24 ( L_4 , V_77 -> V_61 ) ;
V_79 = F_28 ( V_7 , 32 , 2 , V_77 -> V_61 ,
V_70 , 0 , 0 , 0 ) ;
if ( V_79 )
F_24 ( L_5 , V_77 -> V_61 ) ;
F_20 ( V_7 ) ;
F_29 ( V_40 , F_10 ) ;
F_30 ( V_40 , V_7 ) ;
return 0 ;
}
static int T_2 F_31 ( struct V_76 * V_77 ,
struct V_76 * V_83 )
{
struct V_76 * V_84 ;
struct V_74 V_78 ;
void T_3 * V_4 ;
V_4 = F_32 ( V_77 , 0 ) ;
if ( ! V_4 )
F_24 ( L_6 , V_77 -> V_61 ) ;
F_25 ( V_77 , 0 , & V_78 ) ;
F_33 (node, c)
F_22 ( V_4 , & V_78 , V_84 ) ;
return 0 ;
}
