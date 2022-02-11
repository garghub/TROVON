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
if ( V_2 -> V_29 || V_2 -> V_19 ) {
F_1 ( V_2 , V_46 , V_52 , V_32 ) ;
F_2 ( V_53 , V_2 -> V_6 + V_17 ) ;
} else {
F_1 ( V_2 , V_46 , 0 , V_32 ) ;
F_12 ( & V_2 -> V_22 ) ;
}
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
if ( V_2 -> V_29 ) {
F_1 ( V_2 , 0 , V_52 , V_32 ) ;
F_2 ( V_53 , V_2 -> V_6 + V_17 ) ;
}
F_1 ( V_2 , 0 , V_54 , V_55 ) ;
} else {
F_1 ( V_2 , V_54 , 0 , V_55 ) ;
}
* V_2 -> V_27 = F_3 ( V_2 -> V_6 + V_50 ) ;
V_2 -> V_27 ++ ;
V_2 -> V_25 -- ;
return V_48 ;
}
static T_2 F_14 ( int V_37 , void * V_38 )
{
struct V_1 * V_2 = V_38 ;
F_2 ( 0 , V_2 -> V_6 + V_23 ) ;
F_3 ( V_2 -> V_6 + V_23 ) ;
F_2 ( 0 , V_2 -> V_6 + V_32 ) ;
F_3 ( V_2 -> V_6 + V_32 ) ;
F_12 ( & V_2 -> V_22 ) ;
return V_48 ;
}
static T_3 F_15 ( struct V_7 * V_8 )
{
return V_56 | V_57 ;
}
static int F_16 ( struct V_1 * V_2 , T_3 V_58 )
{
int V_14 ;
unsigned long V_59 ;
V_14 = F_6 ( V_2 -> V_16 ) ;
if ( V_14 )
return V_14 ;
V_59 = F_17 ( V_2 -> V_16 ) ;
if ( V_59 != 33325000 ) {
F_18 ( & V_2 -> V_33 . V_60 ,
L_1 , V_59 ) ;
F_9 ( V_2 -> V_16 ) ;
return - V_61 ;
}
F_2 ( V_62 | V_63 , V_2 -> V_6 + V_64 ) ;
F_1 ( V_2 , 0 , V_65 , V_64 ) ;
switch ( V_58 ) {
case 100000 :
F_2 ( F_19 ( 3 ) , V_2 -> V_6 + V_66 ) ;
F_2 ( V_67 , V_2 -> V_6 + V_68 ) ;
F_2 ( V_69 , V_2 -> V_6 + V_70 ) ;
break;
case 400000 :
F_2 ( F_19 ( 1 ) , V_2 -> V_6 + V_66 ) ;
F_2 ( V_71 , V_2 -> V_6 + V_68 ) ;
F_2 ( V_72 , V_2 -> V_6 + V_70 ) ;
break;
default:
F_18 ( & V_2 -> V_33 . V_60 ,
L_2 , V_58 ) ;
F_9 ( V_2 -> V_16 ) ;
return - V_61 ;
}
F_2 ( 0 , V_2 -> V_6 + V_73 ) ;
F_2 ( V_74 | V_75 , V_2 -> V_6 + V_55 ) ;
F_1 ( V_2 , V_62 , 0 , V_64 ) ;
F_9 ( V_2 -> V_16 ) ;
return 0 ;
}
static int F_20 ( struct V_76 * V_77 )
{
struct V_78 * V_79 = V_77 -> V_60 . V_80 ;
struct V_1 * V_2 ;
struct V_7 * V_8 ;
struct V_81 * V_82 ;
T_3 V_83 = 0 ;
int V_13 , V_14 ;
V_2 = F_21 ( & V_77 -> V_60 , sizeof( * V_2 ) , V_84 ) ;
if ( ! V_2 )
return - V_85 ;
V_82 = F_22 ( V_77 , V_86 , 0 ) ;
V_2 -> V_6 = F_23 ( & V_77 -> V_60 , V_82 ) ;
if ( F_24 ( V_2 -> V_6 ) )
return F_25 ( V_2 -> V_6 ) ;
V_2 -> V_16 = F_26 ( & V_77 -> V_60 , NULL ) ;
if ( F_24 ( V_2 -> V_16 ) ) {
F_18 ( & V_77 -> V_60 , L_3 ) ;
return F_25 ( V_2 -> V_16 ) ;
}
for ( V_13 = 0 ; V_13 < F_27 ( V_87 ) ; V_13 ++ ) {
V_82 = F_22 ( V_77 , V_88 , V_87 [ V_13 ] . V_89 ) ;
if ( ! V_82 )
return - V_90 ;
V_14 = F_28 ( & V_77 -> V_60 , V_82 -> V_91 , V_87 [ V_13 ] . V_92 ,
0 , V_87 [ V_13 ] . V_93 , V_2 ) ;
if ( V_14 ) {
F_18 ( & V_77 -> V_60 , L_4 , V_87 [ V_13 ] . V_93 ) ;
return V_14 ;
}
}
V_8 = & V_2 -> V_33 ;
F_29 ( V_8 , V_2 ) ;
F_30 ( V_8 -> V_93 , L_5 , sizeof( V_8 -> V_93 ) ) ;
V_8 -> V_94 = V_95 ;
V_8 -> V_96 = & V_97 ;
V_8 -> V_60 . V_98 = & V_77 -> V_60 ;
V_8 -> V_60 . V_80 = V_77 -> V_60 . V_80 ;
F_31 ( & V_2 -> V_22 ) ;
F_32 ( V_79 , L_6 , & V_83 ) ;
V_14 = F_16 ( V_2 , V_83 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_33 ( V_8 ) ;
if ( V_14 )
return V_14 ;
F_34 ( V_77 , V_2 ) ;
F_35 ( & V_77 -> V_60 , L_7 , V_83 ) ;
return 0 ;
}
static int F_36 ( struct V_76 * V_77 )
{
struct V_1 * V_2 = F_37 ( V_77 ) ;
F_2 ( 0 , V_2 -> V_6 + V_32 ) ;
F_38 ( & V_2 -> V_33 ) ;
return 0 ;
}
