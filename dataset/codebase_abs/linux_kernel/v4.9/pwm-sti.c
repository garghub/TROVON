static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_1 * V_4 , unsigned long V_5 ,
unsigned int * V_6 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
unsigned long V_9 ;
unsigned long V_10 ;
unsigned int V_11 ;
V_9 = F_4 ( V_4 -> V_12 ) ;
if ( ! V_9 ) {
F_5 ( V_4 -> V_13 , L_1 ) ;
return - V_14 ;
}
V_10 = V_15 / V_9 ;
V_10 *= V_8 -> V_16 + 1 ;
if ( V_5 % V_10 )
return - V_14 ;
V_11 = V_5 / V_10 - 1 ;
if ( V_11 > V_8 -> V_17 )
return - V_14 ;
* V_6 = V_11 ;
return 0 ;
}
static int F_6 ( struct V_2 * V_3 , struct V_18 * V_19 ,
int V_20 , int V_21 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
unsigned int V_22 , V_10 , V_6 = 0 ;
struct V_18 * V_23 = V_4 -> V_23 ;
struct V_24 * V_13 = V_4 -> V_13 ;
bool V_25 = false ;
int V_26 ;
V_22 = F_7 ( V_4 -> V_27 ) ;
if ( V_22 )
V_25 = ( V_21 == F_8 ( V_23 ) ) ;
if ( ! V_22 ||
( ( V_22 == 1 ) && ( V_19 -> V_28 == V_23 -> V_28 ) ) ||
( ( V_22 == 1 ) && ( V_19 -> V_28 != V_23 -> V_28 ) && V_25 ) ||
( ( V_22 > 1 ) && V_25 ) ) {
V_26 = F_9 ( V_4 -> V_12 ) ;
if ( V_26 )
return V_26 ;
V_26 = F_9 ( V_4 -> V_29 ) ;
if ( V_26 )
return V_26 ;
if ( ! V_25 ) {
V_26 = F_3 ( V_4 , V_21 , & V_6 ) ;
if ( V_26 )
goto V_30;
V_10 = V_6 & V_31 ;
V_26 = F_10 ( V_4 -> V_32 , V_10 ) ;
if ( V_26 )
goto V_30;
V_10 = ( V_6 & V_33 ) >> 4 ;
V_26 = F_10 ( V_4 -> V_34 , V_10 ) ;
if ( V_26 )
goto V_30;
}
V_10 = V_8 -> V_16 * V_20 / V_21 ;
V_26 = F_11 ( V_4 -> V_35 , F_12 ( V_19 -> V_28 ) , V_10 ) ;
if ( V_26 )
goto V_30;
V_26 = F_10 ( V_4 -> V_36 , 0 ) ;
F_13 ( V_19 -> V_28 , & V_4 -> V_27 ) ;
V_4 -> V_23 = V_19 ;
F_14 ( V_13 , L_2 ,
V_6 , V_21 , V_20 , V_10 ) ;
} else {
return - V_14 ;
}
V_30:
F_15 ( V_4 -> V_12 ) ;
F_15 ( V_4 -> V_29 ) ;
return V_26 ;
}
static int F_16 ( struct V_2 * V_3 , struct V_18 * V_19 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_24 * V_13 = V_4 -> V_13 ;
int V_26 = 0 ;
F_17 ( & V_4 -> V_37 ) ;
if ( ! V_4 -> V_38 ) {
V_26 = F_9 ( V_4 -> V_12 ) ;
if ( V_26 )
goto V_39;
V_26 = F_9 ( V_4 -> V_29 ) ;
if ( V_26 )
goto V_39;
V_26 = F_10 ( V_4 -> V_40 , 1 ) ;
if ( V_26 ) {
F_5 ( V_13 , L_3 ,
V_19 -> V_28 , V_26 ) ;
goto V_39;
}
}
V_4 -> V_38 ++ ;
V_39:
F_18 ( & V_4 -> V_37 ) ;
return V_26 ;
}
static void F_19 ( struct V_2 * V_3 , struct V_18 * V_19 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
F_17 ( & V_4 -> V_37 ) ;
if ( -- V_4 -> V_38 ) {
F_18 ( & V_4 -> V_37 ) ;
return;
}
F_10 ( V_4 -> V_40 , 0 ) ;
F_15 ( V_4 -> V_12 ) ;
F_15 ( V_4 -> V_29 ) ;
F_18 ( & V_4 -> V_37 ) ;
}
static void F_20 ( struct V_2 * V_3 , struct V_18 * V_19 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
F_21 ( V_19 -> V_28 , & V_4 -> V_27 ) ;
}
static int F_22 ( struct V_2 * V_3 , struct V_18 * V_19 ,
struct V_41 * V_42 , unsigned long V_43 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
struct V_44 * V_45 = F_23 ( V_19 ) ;
struct V_24 * V_13 = V_4 -> V_13 ;
unsigned int V_46 ;
unsigned long long V_47 , V_48 ;
int V_26 ;
if ( V_19 -> V_28 >= V_8 -> V_49 ) {
F_5 ( V_13 , L_4 , V_19 -> V_28 ) ;
return - V_14 ;
}
F_17 ( & V_45 -> V_50 ) ;
V_45 -> V_51 = 0 ;
F_11 ( V_4 -> V_35 , F_24 ( V_19 -> V_28 ) , V_52 ) ;
F_10 ( V_4 -> V_36 , F_25 ( V_19 -> V_28 ) ) ;
V_26 = F_10 ( V_4 -> V_53 , 1 ) ;
if ( V_26 ) {
F_5 ( V_13 , L_5 ,
V_19 -> V_28 , V_26 ) ;
goto V_39;
}
V_26 = F_26 ( V_45 -> V_54 , V_45 -> V_51 > 1 ,
F_27 ( V_43 ) ) ;
F_11 ( V_4 -> V_35 , F_24 ( V_19 -> V_28 ) , V_55 ) ;
if ( V_26 == - V_56 )
goto V_39;
switch ( V_45 -> V_51 ) {
case 0 :
case 1 :
V_42 -> V_5 = 0 ;
V_42 -> V_57 = 0 ;
break;
case 2 :
V_47 = V_45 -> V_58 [ 1 ] - V_45 -> V_58 [ 0 ] ;
V_48 = V_45 -> V_58 [ 2 ] - V_45 -> V_58 [ 1 ] ;
V_46 = F_4 ( V_4 -> V_29 ) ;
V_42 -> V_5 = ( V_47 + V_48 ) * V_15 ;
V_42 -> V_5 /= V_46 ;
V_42 -> V_57 = V_47 * V_15 ;
V_42 -> V_57 /= V_46 ;
break;
default:
F_5 ( V_13 , L_6 ) ;
break;
}
V_39:
F_10 ( V_4 -> V_53 , 0 ) ;
F_18 ( & V_45 -> V_50 ) ;
return V_26 ;
}
static T_1 F_28 ( int V_59 , void * V_60 )
{
struct V_1 * V_4 = V_60 ;
struct V_24 * V_13 = V_4 -> V_13 ;
struct V_44 * V_45 ;
int V_61 ;
unsigned int V_62 ;
unsigned int V_63 ;
int V_26 = V_64 ;
V_26 = F_29 ( V_4 -> V_65 , & V_62 ) ;
if ( V_26 )
return V_26 ;
while ( V_62 ) {
V_61 = F_30 ( V_62 ) - 1 ;
V_45 = F_23 ( & V_4 -> V_3 . V_66 [ V_61 ] ) ;
F_31 ( V_4 -> V_35 ,
F_32 ( V_61 ) ,
& V_45 -> V_58 [ V_45 -> V_51 ] ) ;
switch ( V_45 -> V_51 ) {
case 0 :
case 1 :
F_31 ( V_4 -> V_35 , F_24 ( V_61 ) , & V_63 ) ;
V_63 ^= V_67 ;
F_11 ( V_4 -> V_35 , F_24 ( V_61 ) , V_63 ) ;
V_45 -> V_51 ++ ;
break;
case 2 :
F_11 ( V_4 -> V_35 ,
F_24 ( V_61 ) ,
V_55 ) ;
F_33 ( & V_45 -> V_54 ) ;
break;
default:
F_5 ( V_13 , L_7 ) ;
}
V_62 &= ~ F_34 ( V_61 ) ;
V_26 = V_68 ;
}
F_11 ( V_4 -> V_35 , V_69 , V_70 ) ;
return V_26 ;
}
static int F_35 ( struct V_1 * V_4 )
{
struct V_24 * V_13 = V_4 -> V_13 ;
const struct V_71 * V_72 ;
struct V_73 * V_74 = V_13 -> V_75 ;
struct V_7 * V_8 = V_4 -> V_8 ;
T_2 V_76 ;
int V_26 ;
V_26 = F_36 ( V_74 , L_8 , & V_76 ) ;
if ( ! V_26 )
V_8 -> V_77 = V_76 ;
V_26 = F_36 ( V_74 , L_9 , & V_76 ) ;
if ( ! V_26 )
V_8 -> V_49 = V_76 ;
if ( ! V_8 -> V_77 && ! V_8 -> V_49 ) {
F_5 ( V_13 , L_10 ) ;
return - V_14 ;
}
V_72 = V_8 -> V_72 ;
V_4 -> V_32 = F_37 ( V_13 , V_4 -> V_35 ,
V_72 [ V_78 ] ) ;
if ( F_38 ( V_4 -> V_32 ) )
return F_39 ( V_4 -> V_32 ) ;
V_4 -> V_34 = F_37 ( V_13 , V_4 -> V_35 ,
V_72 [ V_79 ] ) ;
if ( F_38 ( V_4 -> V_34 ) )
return F_39 ( V_4 -> V_34 ) ;
V_4 -> V_40 = F_37 ( V_13 , V_4 -> V_35 ,
V_72 [ V_80 ] ) ;
if ( F_38 ( V_4 -> V_40 ) )
return F_39 ( V_4 -> V_40 ) ;
V_4 -> V_53 = F_37 ( V_13 , V_4 -> V_35 ,
V_72 [ V_81 ] ) ;
if ( F_38 ( V_4 -> V_53 ) )
return F_39 ( V_4 -> V_53 ) ;
V_4 -> V_36 = F_37 ( V_13 , V_4 -> V_35 ,
V_72 [ V_82 ] ) ;
if ( F_38 ( V_4 -> V_36 ) )
return F_39 ( V_4 -> V_36 ) ;
V_4 -> V_65 = F_37 ( V_13 , V_4 -> V_35 ,
V_72 [ V_83 ] ) ;
if ( F_40 ( V_4 -> V_65 ) )
return F_39 ( V_4 -> V_65 ) ;
return 0 ;
}
static int F_41 ( struct V_84 * V_85 )
{
struct V_24 * V_13 = & V_85 -> V_13 ;
struct V_7 * V_8 ;
struct V_1 * V_4 ;
struct V_86 * V_87 ;
unsigned int V_88 ;
int V_59 , V_26 ;
V_4 = F_42 ( V_13 , sizeof( * V_4 ) , V_89 ) ;
if ( ! V_4 )
return - V_90 ;
V_8 = F_42 ( V_13 , sizeof( * V_8 ) , V_89 ) ;
if ( ! V_8 )
return - V_90 ;
V_87 = F_43 ( V_85 , V_91 , 0 ) ;
V_4 -> V_92 = F_44 ( V_13 , V_87 ) ;
if ( F_38 ( V_4 -> V_92 ) )
return F_39 ( V_4 -> V_92 ) ;
V_4 -> V_35 = F_45 ( V_13 , V_4 -> V_92 ,
& V_93 ) ;
if ( F_38 ( V_4 -> V_35 ) )
return F_39 ( V_4 -> V_35 ) ;
V_59 = F_46 ( V_85 , 0 ) ;
if ( V_59 < 0 ) {
F_5 ( & V_85 -> V_13 , L_11 ) ;
return V_59 ;
}
V_26 = F_47 ( & V_85 -> V_13 , V_59 , F_28 , 0 ,
V_85 -> V_94 , V_4 ) ;
if ( V_26 < 0 ) {
F_5 ( & V_85 -> V_13 , L_12 ) ;
return V_26 ;
}
V_8 -> V_72 = V_95 ;
V_8 -> V_17 = 0xff ;
V_8 -> V_16 = 255 ;
V_8 -> V_77 = 0 ;
V_8 -> V_49 = 0 ;
V_4 -> V_8 = V_8 ;
V_4 -> V_13 = V_13 ;
V_4 -> V_38 = 0 ;
F_48 ( & V_4 -> V_37 ) ;
V_26 = F_35 ( V_4 ) ;
if ( V_26 )
return V_26 ;
if ( ! V_8 -> V_77 )
goto V_96;
V_4 -> V_12 = F_49 ( V_13 -> V_75 , L_13 ) ;
if ( F_38 ( V_4 -> V_12 ) ) {
F_5 ( V_13 , L_14 ) ;
return F_39 ( V_4 -> V_12 ) ;
}
V_26 = F_50 ( V_4 -> V_12 ) ;
if ( V_26 ) {
F_5 ( V_13 , L_15 ) ;
return V_26 ;
}
V_96:
if ( ! V_8 -> V_49 )
goto V_97;
V_4 -> V_29 = F_49 ( V_13 -> V_75 , L_16 ) ;
if ( F_38 ( V_4 -> V_29 ) ) {
F_5 ( V_13 , L_17 ) ;
return F_39 ( V_4 -> V_29 ) ;
}
V_26 = F_50 ( V_4 -> V_29 ) ;
if ( V_26 ) {
F_5 ( V_13 , L_15 ) ;
return V_26 ;
}
V_97:
V_4 -> V_3 . V_13 = V_13 ;
V_4 -> V_3 . V_98 = & V_99 ;
V_4 -> V_3 . V_100 = - 1 ;
V_4 -> V_3 . V_101 = V_4 -> V_8 -> V_77 ;
V_4 -> V_3 . V_102 = true ;
V_26 = F_51 ( & V_4 -> V_3 ) ;
if ( V_26 < 0 ) {
F_52 ( V_4 -> V_12 ) ;
F_52 ( V_4 -> V_29 ) ;
return V_26 ;
}
for ( V_88 = 0 ; V_88 < V_8 -> V_49 ; V_88 ++ ) {
struct V_44 * V_45 ;
V_45 = F_42 ( V_13 , sizeof( * V_45 ) , V_89 ) ;
if ( ! V_45 )
return - V_90 ;
F_53 ( & V_45 -> V_54 ) ;
F_48 ( & V_45 -> V_50 ) ;
F_54 ( & V_4 -> V_3 . V_66 [ V_88 ] , V_45 ) ;
}
F_55 ( V_85 , V_4 ) ;
return 0 ;
}
static int F_56 ( struct V_84 * V_85 )
{
struct V_1 * V_4 = F_57 ( V_85 ) ;
unsigned int V_88 ;
for ( V_88 = 0 ; V_88 < V_4 -> V_8 -> V_77 ; V_88 ++ )
F_58 ( & V_4 -> V_3 . V_66 [ V_88 ] ) ;
F_52 ( V_4 -> V_12 ) ;
F_52 ( V_4 -> V_29 ) ;
return F_59 ( & V_4 -> V_3 ) ;
}
