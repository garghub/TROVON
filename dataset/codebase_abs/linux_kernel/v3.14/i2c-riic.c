static inline void F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 , T_1 V_5 )
{
F_2 ( ( F_3 ( V_2 -> V_6 + V_5 ) & ~ V_3 ) | V_4 , V_2 -> V_6 + V_5 ) ;
}
static int F_4 ( struct V_7 * V_8 , struct V_9 V_10 [] , int V_11 )
{
struct V_1 * V_2 = F_5 ( V_8 ) ;
unsigned long V_12 ;
int V_13 , V_14 ;
T_1 V_15 ;
V_14 = F_6 ( V_2 -> V_16 ) ;
if ( V_14 )
return V_14 ;
if ( F_3 ( V_2 -> V_6 + V_17 ) & V_18 ) {
V_2 -> V_19 = - V_20 ;
goto V_21;
}
F_7 ( & V_2 -> V_22 ) ;
V_2 -> V_19 = 0 ;
F_2 ( 0 , V_2 -> V_6 + V_23 ) ;
for ( V_13 = 0 , V_15 = V_24 ; V_13 < V_11 ; V_13 ++ ) {
V_2 -> V_25 = V_26 ;
V_2 -> V_27 = V_10 [ V_13 ] . V_27 ;
V_2 -> V_28 = & V_10 [ V_13 ] ;
V_2 -> V_29 = ( V_13 == V_11 - 1 ) ;
F_2 ( V_30 | V_31 , V_2 -> V_6 + V_32 ) ;
F_2 ( V_15 , V_2 -> V_6 + V_17 ) ;
V_12 = F_8 ( & V_2 -> V_22 , V_2 -> V_33 . V_34 ) ;
if ( V_12 == 0 )
V_2 -> V_19 = - V_35 ;
if ( V_2 -> V_19 )
break;
V_15 = V_36 ;
}
V_21:
F_9 ( V_2 -> V_16 ) ;
return V_2 -> V_19 ? : V_11 ;
}
static T_2 F_10 ( int V_37 , void * V_38 )
{
struct V_1 * V_2 = V_38 ;
T_1 V_39 ;
if ( ! V_2 -> V_25 )
return V_40 ;
if ( V_2 -> V_25 == V_26 ) {
V_39 = ! ! ( V_2 -> V_28 -> V_41 & V_42 ) ;
if ( V_39 )
F_1 ( V_2 , V_31 , V_43 , V_32 ) ;
else
V_2 -> V_25 = V_2 -> V_28 -> V_44 ;
V_39 |= ( V_2 -> V_28 -> V_45 << 1 ) ;
} else {
V_39 = * V_2 -> V_27 ;
V_2 -> V_27 ++ ;
V_2 -> V_25 -- ;
}
if ( V_2 -> V_25 == 0 )
F_1 ( V_2 , V_31 , V_46 , V_32 ) ;
F_2 ( V_39 , V_2 -> V_6 + V_47 ) ;
return V_48 ;
}
static T_2 F_11 ( int V_37 , void * V_38 )
{
struct V_1 * V_2 = V_38 ;
if ( F_3 ( V_2 -> V_6 + V_23 ) & V_49 ) {
F_3 ( V_2 -> V_6 + V_50 ) ;
V_2 -> V_19 = - V_51 ;
} else if ( V_2 -> V_25 ) {
return V_40 ;
}
if ( V_2 -> V_29 || V_2 -> V_19 )
F_2 ( V_52 , V_2 -> V_6 + V_17 ) ;
F_2 ( 0 , V_2 -> V_6 + V_32 ) ;
F_12 ( & V_2 -> V_22 ) ;
return V_48 ;
}
static T_2 F_13 ( int V_37 , void * V_38 )
{
struct V_1 * V_2 = V_38 ;
if ( ! V_2 -> V_25 )
return V_40 ;
if ( V_2 -> V_25 == V_26 ) {
V_2 -> V_25 = V_2 -> V_28 -> V_44 ;
F_3 ( V_2 -> V_6 + V_50 ) ;
return V_48 ;
}
if ( V_2 -> V_25 == 1 ) {
if ( V_2 -> V_29 )
F_2 ( V_52 , V_2 -> V_6 + V_17 ) ;
F_1 ( V_2 , 0 , V_53 , V_54 ) ;
F_2 ( 0 , V_2 -> V_6 + V_32 ) ;
F_12 ( & V_2 -> V_22 ) ;
} else {
F_1 ( V_2 , V_53 , 0 , V_54 ) ;
}
* V_2 -> V_27 = F_3 ( V_2 -> V_6 + V_50 ) ;
V_2 -> V_27 ++ ;
V_2 -> V_25 -- ;
return V_48 ;
}
static T_3 F_14 ( struct V_7 * V_8 )
{
return V_55 | V_56 ;
}
static int F_15 ( struct V_1 * V_2 , T_3 V_57 )
{
int V_14 ;
unsigned long V_58 ;
V_14 = F_6 ( V_2 -> V_16 ) ;
if ( V_14 )
return V_14 ;
V_58 = F_16 ( V_2 -> V_16 ) ;
if ( V_58 != 33325000 ) {
F_17 ( & V_2 -> V_33 . V_59 ,
L_1 , V_58 ) ;
F_9 ( V_2 -> V_16 ) ;
return - V_60 ;
}
F_2 ( V_61 | V_62 , V_2 -> V_6 + V_63 ) ;
F_1 ( V_2 , 0 , V_64 , V_63 ) ;
switch ( V_57 ) {
case 100000 :
F_2 ( F_18 ( 3 ) , V_2 -> V_6 + V_65 ) ;
F_2 ( V_66 , V_2 -> V_6 + V_67 ) ;
F_2 ( V_68 , V_2 -> V_6 + V_69 ) ;
break;
case 400000 :
F_2 ( F_18 ( 1 ) , V_2 -> V_6 + V_65 ) ;
F_2 ( V_70 , V_2 -> V_6 + V_67 ) ;
F_2 ( V_71 , V_2 -> V_6 + V_69 ) ;
break;
default:
F_17 ( & V_2 -> V_33 . V_59 ,
L_2 , V_57 ) ;
F_9 ( V_2 -> V_16 ) ;
return - V_60 ;
}
F_2 ( 0 , V_2 -> V_6 + V_72 ) ;
F_2 ( V_73 | V_74 , V_2 -> V_6 + V_54 ) ;
F_1 ( V_2 , V_61 , 0 , V_63 ) ;
F_9 ( V_2 -> V_16 ) ;
return 0 ;
}
static int F_19 ( struct V_75 * V_76 )
{
struct V_77 * V_78 = V_76 -> V_59 . V_79 ;
struct V_1 * V_2 ;
struct V_7 * V_8 ;
struct V_80 * V_81 ;
T_3 V_82 = 0 ;
int V_13 , V_14 ;
V_2 = F_20 ( & V_76 -> V_59 , sizeof( * V_2 ) , V_83 ) ;
if ( ! V_2 )
return - V_84 ;
V_81 = F_21 ( V_76 , V_85 , 0 ) ;
V_2 -> V_6 = F_22 ( & V_76 -> V_59 , V_81 ) ;
if ( F_23 ( V_2 -> V_6 ) )
return F_24 ( V_2 -> V_6 ) ;
V_2 -> V_16 = F_25 ( & V_76 -> V_59 , NULL ) ;
if ( F_23 ( V_2 -> V_16 ) ) {
F_17 ( & V_76 -> V_59 , L_3 ) ;
return F_24 ( V_2 -> V_16 ) ;
}
for ( V_13 = 0 ; V_13 < F_26 ( V_86 ) ; V_13 ++ ) {
V_81 = F_21 ( V_76 , V_87 , V_86 [ V_13 ] . V_88 ) ;
if ( ! V_81 )
return - V_89 ;
V_14 = F_27 ( & V_76 -> V_59 , V_81 -> V_90 , V_86 [ V_13 ] . V_91 ,
0 , V_86 [ V_13 ] . V_92 , V_2 ) ;
if ( V_14 ) {
F_17 ( & V_76 -> V_59 , L_4 , V_86 [ V_13 ] . V_92 ) ;
return V_14 ;
}
}
V_8 = & V_2 -> V_33 ;
F_28 ( V_8 , V_2 ) ;
F_29 ( V_8 -> V_92 , L_5 , sizeof( V_8 -> V_92 ) ) ;
V_8 -> V_93 = V_94 ;
V_8 -> V_95 = & V_96 ;
V_8 -> V_59 . V_97 = & V_76 -> V_59 ;
V_8 -> V_59 . V_79 = V_76 -> V_59 . V_79 ;
F_30 ( & V_2 -> V_22 ) ;
F_31 ( V_78 , L_6 , & V_82 ) ;
V_14 = F_15 ( V_2 , V_82 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_32 ( V_8 ) ;
if ( V_14 ) {
F_17 ( & V_76 -> V_59 , L_7 ) ;
return V_14 ;
}
F_33 ( V_76 , V_2 ) ;
F_34 ( & V_76 -> V_59 , L_8 , V_82 ) ;
return 0 ;
}
static int F_35 ( struct V_75 * V_76 )
{
struct V_1 * V_2 = F_36 ( V_76 ) ;
F_2 ( 0 , V_2 -> V_6 + V_32 ) ;
F_37 ( & V_2 -> V_33 ) ;
return 0 ;
}
