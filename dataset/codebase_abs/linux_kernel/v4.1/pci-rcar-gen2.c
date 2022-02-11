static void T_1 * F_1 ( struct V_1 * V_2 , unsigned int V_3 ,
int V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 ;
int V_11 , V_12 ;
if ( V_6 -> V_13 != V_2 -> V_14 || F_2 ( V_3 ) )
return NULL ;
V_11 = F_3 ( V_3 ) ;
if ( V_11 > 2 )
return NULL ;
if ( V_11 == 0x0 && V_4 >= 0x40 )
return NULL ;
V_12 = V_11 ? V_15 | V_16 :
V_17 | V_16 ;
F_4 ( V_12 , V_9 -> V_18 + V_19 ) ;
return V_9 -> V_18 + ( V_11 >> 1 ) * 0x100 + V_4 ;
}
static int F_5 ( const struct V_20 * V_21 , T_2 V_11 , T_2 V_22 )
{
struct V_5 * V_6 = V_21 -> V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 ;
int V_23 ;
V_23 = F_6 ( V_21 , V_11 , V_22 ) ;
if ( ! V_23 )
V_23 = V_9 -> V_23 ;
return V_23 ;
}
static T_3 F_7 ( int V_23 , void * V_24 )
{
struct V_8 * V_9 = V_24 ;
T_4 V_25 = F_8 ( V_9 -> V_18 + V_26 ) ;
if ( V_25 & V_27 ) {
F_9 ( V_9 -> V_21 , L_1 , V_25 ) ;
F_4 ( V_25 & V_27 ,
V_9 -> V_18 + V_26 ) ;
return V_28 ;
}
return V_29 ;
}
static void F_10 ( struct V_8 * V_9 )
{
int V_30 ;
T_4 V_12 ;
V_30 = F_11 ( V_9 -> V_21 , V_9 -> V_23 , F_7 ,
V_31 , L_2 , V_9 ) ;
if ( V_30 ) {
F_9 ( V_9 -> V_21 , L_3 ) ;
return;
}
V_12 = F_8 ( V_9 -> V_18 + V_32 ) ;
V_12 |= V_27 ;
F_4 ( V_12 , V_9 -> V_18 + V_32 ) ;
}
static inline void F_10 ( struct V_8 * V_9 ) { }
static int F_12 ( int V_33 , struct V_5 * V_6 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
void T_1 * V_18 = V_9 -> V_18 ;
T_4 V_12 ;
F_13 ( V_9 -> V_21 ) ;
F_14 ( V_9 -> V_21 ) ;
V_12 = F_8 ( V_18 + V_34 ) ;
F_15 ( V_9 -> V_21 , L_4 , V_6 -> V_13 , V_12 ) ;
V_12 = F_8 ( V_18 + V_35 ) & ~ V_36 ;
V_12 |= V_37 | V_38 ;
F_4 ( V_12 , V_18 + V_35 ) ;
F_16 ( 4 ) ;
V_12 &= ~ ( V_39 | V_40 |
V_37 | V_38 ) ;
switch ( V_9 -> V_41 ) {
case V_42 :
V_12 |= V_43 ;
break;
case V_44 :
V_12 |= V_45 ;
break;
case V_46 :
V_12 |= V_47 ;
break;
default:
F_17 ( L_5 ,
V_9 -> V_41 ) ;
V_9 -> V_41 = V_48 ;
case V_48 :
V_12 |= V_49 ;
break;
}
F_4 ( V_12 , V_18 + V_35 ) ;
F_4 ( V_50 , V_18 + V_51 ) ;
V_12 = F_8 ( V_18 + V_52 ) ;
V_12 |= V_53 | V_54 |
V_55 ;
F_4 ( V_12 , V_18 + V_52 ) ;
F_4 ( 0x40000000 | V_56 ,
V_18 + V_57 ) ;
V_12 = V_9 -> V_58 . V_59 | V_60 ;
F_4 ( V_12 , V_18 + V_61 ) ;
F_4 ( V_17 | V_16 ,
V_18 + V_19 ) ;
F_4 ( 0x40000000 | V_62 ,
V_18 + V_63 ) ;
V_12 = V_9 -> V_64 -> V_59 + V_65 ;
F_4 ( V_12 , V_18 + V_66 ) ;
V_12 = F_8 ( V_18 + V_67 ) ;
V_12 |= V_68 | V_69 |
V_70 | V_71 ;
F_4 ( V_12 , V_18 + V_67 ) ;
F_4 ( V_72 | V_73 | V_74 ,
V_18 + V_32 ) ;
if ( V_9 -> V_23 > 0 )
F_10 ( V_9 ) ;
F_18 ( & V_6 -> V_75 , & V_9 -> V_76 ) ;
F_18 ( & V_6 -> V_75 , & V_9 -> V_58 ) ;
V_6 -> V_13 = V_9 -> V_13 ;
return 1 ;
}
static int F_19 ( struct V_77 * V_78 )
{
struct V_79 * V_64 , * V_58 ;
struct V_8 * V_9 ;
void T_1 * V_18 ;
struct V_80 V_81 ;
void * V_82 [ 1 ] ;
V_64 = F_20 ( V_78 , V_83 , 0 ) ;
V_18 = F_21 ( & V_78 -> V_21 , V_64 ) ;
if ( F_22 ( V_18 ) )
return F_23 ( V_18 ) ;
V_58 = F_20 ( V_78 , V_83 , 1 ) ;
if ( ! V_58 || ! V_58 -> V_59 )
return - V_84 ;
if ( V_58 -> V_59 & 0xFFFF )
return - V_85 ;
V_9 = F_24 ( & V_78 -> V_21 ,
sizeof( struct V_8 ) , V_86 ) ;
if ( ! V_9 )
return - V_87 ;
V_9 -> V_58 = * V_58 ;
V_9 -> V_76 . V_59 = V_9 -> V_58 . V_59 ;
V_9 -> V_76 . V_88 = V_9 -> V_58 . V_88 ;
V_9 -> V_76 . V_89 = V_90 ;
V_9 -> V_64 = V_64 ;
V_9 -> V_23 = F_25 ( V_78 , 0 ) ;
V_9 -> V_18 = V_18 ;
V_9 -> V_21 = & V_78 -> V_21 ;
if ( V_9 -> V_23 < 0 ) {
F_9 ( & V_78 -> V_21 , L_6 ) ;
return V_9 -> V_23 ;
}
V_9 -> V_41 = V_44 ;
if ( V_78 -> V_21 . V_91 ) {
struct V_79 V_13 ;
int V_30 ;
V_30 = F_26 ( V_78 -> V_21 . V_91 , & V_13 ) ;
if ( V_30 < 0 ) {
F_9 ( & V_78 -> V_21 , L_7 ) ;
return V_30 ;
}
V_9 -> V_13 = V_13 . V_59 ;
if ( V_13 . V_88 != V_13 . V_59 )
F_27 ( & V_78 -> V_21 , L_8 ) ;
} else {
V_9 -> V_13 = V_78 -> V_92 ;
}
V_82 [ 0 ] = V_9 ;
memset ( & V_81 , 0 , sizeof( V_81 ) ) ;
V_81 . V_93 = F_28 ( V_82 ) ;
V_81 . V_10 = V_82 ;
V_81 . V_94 = F_5 ;
V_81 . V_95 = & V_96 ;
V_81 . V_97 = F_12 ;
F_29 ( & V_78 -> V_21 , & V_81 ) ;
return 0 ;
}
