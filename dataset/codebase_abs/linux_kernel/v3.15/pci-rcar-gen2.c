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
static int F_5 ( struct V_1 * V_2 , unsigned int V_3 ,
int V_4 , int V_20 , T_2 * V_12 )
{
void T_1 * V_18 = F_1 ( V_2 , V_3 , V_4 ) ;
if ( ! V_18 )
return V_21 ;
switch ( V_20 ) {
case 1 :
* V_12 = F_6 ( V_18 ) ;
break;
case 2 :
* V_12 = F_7 ( V_18 ) ;
break;
default:
* V_12 = F_8 ( V_18 ) ;
break;
}
return V_22 ;
}
static int F_9 ( struct V_1 * V_2 , unsigned int V_3 ,
int V_4 , int V_20 , T_2 V_12 )
{
void T_1 * V_18 = F_1 ( V_2 , V_3 , V_4 ) ;
if ( ! V_18 )
return V_21 ;
switch ( V_20 ) {
case 1 :
F_10 ( V_12 , V_18 ) ;
break;
case 2 :
F_11 ( V_12 , V_18 ) ;
break;
default:
F_4 ( V_12 , V_18 ) ;
break;
}
return V_22 ;
}
static int F_12 ( const struct V_23 * V_24 , T_3 V_11 , T_3 V_25 )
{
struct V_5 * V_6 = V_24 -> V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 ;
int V_26 ;
V_26 = F_13 ( V_24 , V_11 , V_25 ) ;
if ( ! V_26 )
V_26 = V_9 -> V_26 ;
return V_26 ;
}
static T_4 F_14 ( int V_26 , void * V_27 )
{
struct V_8 * V_9 = V_27 ;
T_2 V_28 = F_8 ( V_9 -> V_18 + V_29 ) ;
if ( V_28 & V_30 ) {
F_15 ( V_9 -> V_24 , L_1 , V_28 ) ;
F_4 ( V_28 & V_30 ,
V_9 -> V_18 + V_29 ) ;
return V_31 ;
}
return V_32 ;
}
static void F_16 ( struct V_8 * V_9 )
{
int V_33 ;
T_2 V_12 ;
V_33 = F_17 ( V_9 -> V_24 , V_9 -> V_26 , F_14 ,
V_34 , L_2 , V_9 ) ;
if ( V_33 ) {
F_15 ( V_9 -> V_24 , L_3 ) ;
return;
}
V_12 = F_8 ( V_9 -> V_18 + V_35 ) ;
V_12 |= V_30 ;
F_4 ( V_12 , V_9 -> V_18 + V_35 ) ;
}
static inline void F_16 ( struct V_8 * V_9 ) { }
static int F_18 ( int V_36 , struct V_5 * V_6 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
void T_1 * V_18 = V_9 -> V_18 ;
T_2 V_12 ;
F_19 ( V_9 -> V_24 ) ;
F_20 ( V_9 -> V_24 ) ;
V_12 = F_8 ( V_18 + V_37 ) ;
F_21 ( V_9 -> V_24 , L_4 , V_6 -> V_13 , V_12 ) ;
V_12 = F_8 ( V_18 + V_38 ) & ~ V_39 ;
V_12 |= V_40 | V_41 ;
F_4 ( V_12 , V_18 + V_38 ) ;
F_22 ( 4 ) ;
V_12 &= ~ ( V_42 | V_43 |
V_40 | V_41 ) ;
switch ( V_9 -> V_44 ) {
case V_45 :
V_12 |= V_46 ;
break;
case V_47 :
V_12 |= V_48 ;
break;
case V_49 :
V_12 |= V_50 ;
break;
default:
F_23 ( L_5 ,
V_9 -> V_44 ) ;
V_9 -> V_44 = V_51 ;
case V_51 :
V_12 |= V_52 ;
break;
}
F_4 ( V_12 , V_18 + V_38 ) ;
F_4 ( V_53 , V_18 + V_54 ) ;
V_12 = F_8 ( V_18 + V_55 ) ;
V_12 |= V_56 | V_57 |
V_58 ;
F_4 ( V_12 , V_18 + V_55 ) ;
F_4 ( 0x40000000 | V_59 ,
V_18 + V_60 ) ;
V_12 = V_9 -> V_61 . V_62 | V_63 ;
F_4 ( V_12 , V_18 + V_64 ) ;
F_4 ( V_17 | V_16 ,
V_18 + V_19 ) ;
F_4 ( 0x40000000 | V_65 ,
V_18 + V_66 ) ;
V_12 = V_9 -> V_67 -> V_62 + V_68 ;
F_4 ( V_12 , V_18 + V_69 ) ;
V_12 = F_8 ( V_18 + V_70 ) ;
V_12 |= V_71 | V_72 |
V_73 | V_74 ;
F_4 ( V_12 , V_18 + V_70 ) ;
F_4 ( V_75 | V_76 | V_77 ,
V_18 + V_35 ) ;
if ( V_9 -> V_26 > 0 )
F_16 ( V_9 ) ;
F_24 ( & V_6 -> V_78 , & V_9 -> V_79 ) ;
F_24 ( & V_6 -> V_78 , & V_9 -> V_61 ) ;
V_6 -> V_13 = F_25 ( V_9 -> V_24 ) -> V_80 ;
return 1 ;
}
static int F_26 ( struct V_81 * V_82 )
{
struct V_83 * V_67 , * V_61 ;
struct V_8 * V_9 ;
void T_1 * V_18 ;
struct V_84 V_85 ;
void * V_86 [ 1 ] ;
V_67 = F_27 ( V_82 , V_87 , 0 ) ;
V_18 = F_28 ( & V_82 -> V_24 , V_67 ) ;
if ( F_29 ( V_18 ) )
return F_30 ( V_18 ) ;
V_61 = F_27 ( V_82 , V_87 , 1 ) ;
if ( ! V_61 || ! V_61 -> V_62 )
return - V_88 ;
V_9 = F_31 ( & V_82 -> V_24 ,
sizeof( struct V_8 ) , V_89 ) ;
if ( ! V_9 )
return - V_90 ;
V_9 -> V_61 = * V_61 ;
V_9 -> V_79 . V_62 = V_9 -> V_61 . V_62 ;
V_9 -> V_79 . V_91 = V_9 -> V_61 . V_91 ;
V_9 -> V_79 . V_92 = V_93 ;
V_9 -> V_67 = V_67 ;
V_9 -> V_26 = F_32 ( V_82 , 0 ) ;
V_9 -> V_18 = V_18 ;
V_9 -> V_24 = & V_82 -> V_24 ;
if ( V_9 -> V_26 < 0 ) {
F_15 ( & V_82 -> V_24 , L_6 ) ;
return V_9 -> V_26 ;
}
V_9 -> V_44 = V_47 ;
V_86 [ 0 ] = V_9 ;
memset ( & V_85 , 0 , sizeof( V_85 ) ) ;
V_85 . V_94 = F_33 ( V_86 ) ;
V_85 . V_10 = V_86 ;
V_85 . V_95 = F_12 ;
V_85 . V_96 = & V_97 ;
V_85 . V_98 = F_18 ;
F_34 ( & V_82 -> V_24 , & V_85 ) ;
return 0 ;
}
