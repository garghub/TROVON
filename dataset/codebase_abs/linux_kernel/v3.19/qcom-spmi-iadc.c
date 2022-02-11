static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 * V_4 )
{
unsigned int V_5 ;
int V_6 ;
V_6 = F_2 ( V_2 -> V_7 , V_2 -> V_8 + V_3 , & V_5 ) ;
if ( V_6 < 0 )
return V_6 ;
* V_4 = V_5 ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 )
{
return F_4 ( V_2 -> V_7 , V_2 -> V_8 + V_3 , V_4 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
T_2 V_4 ;
int V_6 ;
V_6 = F_3 ( V_2 , V_9 , V_10 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_1 ( V_2 , V_11 , & V_4 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_3 ( V_2 , V_9 , V_10 ) ;
if ( V_6 < 0 )
return V_6 ;
V_4 |= V_12 ;
return F_3 ( V_2 , V_11 , V_4 ) ;
}
static int F_6 ( struct V_1 * V_2 , bool V_13 )
{
return F_3 ( V_2 , V_14 , V_13 ? V_15 : 0 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
T_2 V_16 , V_17 , V_18 , V_19 , V_20 , V_21 ;
int V_6 ;
V_6 = F_1 ( V_2 , V_22 , & V_16 ) ;
if ( V_6 < 0 )
return;
V_6 = F_1 ( V_2 , V_23 , & V_19 ) ;
if ( V_6 < 0 )
return;
V_6 = F_1 ( V_2 , V_24 , & V_18 ) ;
if ( V_6 < 0 )
return;
V_6 = F_1 ( V_2 , V_25 , & V_21 ) ;
if ( V_6 < 0 )
return;
V_6 = F_1 ( V_2 , V_26 , & V_17 ) ;
if ( V_6 < 0 )
return;
V_6 = F_1 ( V_2 , V_14 , & V_20 ) ;
if ( V_6 < 0 )
return;
F_8 ( V_2 -> V_27 ,
L_1 ,
V_16 , V_20 , V_18 , V_19 , V_21 , V_17 ) ;
}
static int F_9 ( struct V_1 * V_2 , int V_28 )
{
T_2 V_29 , V_16 ;
int V_6 ;
V_16 = ( V_30 << V_31 ) | V_32 ;
V_6 = F_3 ( V_2 , V_22 , V_16 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_3 ( V_2 , V_24 , V_28 ) ;
if ( V_6 < 0 )
return V_6 ;
V_29 = V_33 << V_34 ;
V_6 = F_3 ( V_2 , V_23 , V_29 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_3 ( V_2 , V_35 , V_36 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_3 ( V_2 , V_37 , V_38 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( V_38 )
V_6 = F_3 ( V_2 , V_39 , V_40 ) ;
else
V_6 = F_3 ( V_2 , V_39 , 0 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( ! V_2 -> V_41 )
F_10 ( & V_2 -> V_42 ) ;
V_6 = F_6 ( V_2 , true ) ;
if ( V_6 < 0 )
return V_6 ;
return F_3 ( V_2 , V_25 , V_43 ) ;
}
static int F_11 ( struct V_1 * V_2 , unsigned int V_44 )
{
unsigned int V_45 , V_46 ;
int V_6 ;
T_2 V_17 ;
V_46 = V_44 / V_47 ;
for ( V_45 = 0 ; V_45 < V_46 ; V_45 ++ ) {
V_6 = F_1 ( V_2 , V_26 , & V_17 ) ;
if ( V_6 < 0 )
return V_6 ;
V_17 &= V_48 ;
if ( V_17 == V_49 )
return 0 ;
F_12 ( V_47 , V_50 ) ;
}
F_7 ( V_2 ) ;
return - V_51 ;
}
static int F_13 ( struct V_1 * V_2 , T_1 * V_4 )
{
return F_14 ( V_2 -> V_7 , V_2 -> V_8 + V_52 , V_4 , 2 ) ;
}
static int F_15 ( struct V_1 * V_2 , int V_18 , T_1 * V_4 )
{
unsigned int V_53 ;
int V_6 ;
V_6 = F_9 ( V_2 , V_18 ) ;
if ( V_6 < 0 )
goto exit;
V_53 = F_16 ( V_38 ) * V_47 * 2 ;
if ( V_2 -> V_41 ) {
V_6 = F_11 ( V_2 , V_53 ) ;
} else {
V_6 = F_17 ( & V_2 -> V_42 , V_53 ) ;
if ( ! V_6 )
V_6 = - V_51 ;
else
V_6 = F_11 ( V_2 , V_47 ) ;
}
if ( ! V_6 )
V_6 = F_13 ( V_2 , V_4 ) ;
exit:
F_6 ( V_2 , false ) ;
if ( V_6 < 0 )
F_8 ( V_2 -> V_27 , L_2 ) ;
return V_6 ;
}
static int F_18 ( struct V_54 * V_55 ,
struct V_56 const * V_18 ,
int * V_5 , int * V_57 , long V_58 )
{
struct V_1 * V_2 = F_19 ( V_55 ) ;
T_3 V_59 , V_60 ;
T_1 V_61 , V_62 ;
int V_6 ;
switch ( V_58 ) {
case V_63 :
F_20 ( & V_2 -> V_64 ) ;
V_6 = F_15 ( V_2 , V_18 -> V_28 , & V_61 ) ;
F_21 ( & V_2 -> V_64 ) ;
if ( V_6 < 0 )
return V_6 ;
V_62 = V_61 - V_2 -> V_3 [ V_18 -> V_28 ] ;
V_60 = V_62 * V_65 ;
V_60 /= ( T_3 ) V_2 -> V_66 - V_2 -> V_3 [ V_18 -> V_28 ] ;
V_59 = V_60 / V_2 -> V_67 [ V_18 -> V_28 ] ;
F_22 ( V_2 -> V_27 , L_3 ,
V_2 -> V_3 [ V_18 -> V_28 ] , V_2 -> V_66 ,
V_61 , V_60 , V_59 ) ;
* V_5 = V_59 ;
return V_68 ;
case V_69 :
* V_5 = 0 ;
* V_57 = 1000 ;
return V_70 ;
}
return - V_71 ;
}
static T_4 F_23 ( int V_72 , void * V_73 )
{
struct V_1 * V_2 = V_73 ;
V_42 ( & V_2 -> V_42 ) ;
return V_74 ;
}
static int F_24 ( struct V_1 * V_2 )
{
int V_6 ;
V_6 = F_15 ( V_2 , V_75 , & V_2 -> V_66 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_15 ( V_2 , V_76 ,
& V_2 -> V_3 [ V_77 ] ) ;
if ( V_6 < 0 )
return V_6 ;
if ( V_2 -> V_66 == V_2 -> V_3 [ V_77 ] ) {
F_8 ( V_2 -> V_27 , L_4 ,
V_2 -> V_66 ) ;
return - V_71 ;
}
V_6 = F_15 ( V_2 , V_78 ,
& V_2 -> V_3 [ V_79 ] ) ;
if ( V_6 < 0 )
return V_6 ;
if ( V_2 -> V_66 == V_2 -> V_3 [ V_79 ] ) {
F_8 ( V_2 -> V_27 , L_5 ,
V_2 -> V_66 ) ;
return - V_71 ;
}
return 0 ;
}
static int F_25 ( struct V_1 * V_2 )
{
T_2 V_5 ;
int V_6 ;
V_6 = F_1 ( V_2 , V_80 , & V_5 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( V_5 < V_81 ) {
F_8 ( V_2 -> V_27 , L_6 , V_5 ) ;
return - V_71 ;
}
V_6 = F_1 ( V_2 , V_82 , & V_5 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( V_5 < V_83 ) {
F_8 ( V_2 -> V_27 , L_7 , V_5 ) ;
return - V_71 ;
}
V_6 = F_1 ( V_2 , V_84 , & V_5 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( V_5 < V_85 ) {
F_8 ( V_2 -> V_27 , L_8 , V_5 ) ;
return - V_71 ;
}
return 0 ;
}
static int F_26 ( struct V_1 * V_2 , struct V_86 * V_87 )
{
int V_6 , V_88 , V_89 ;
T_2 V_90 ;
V_6 = F_27 ( V_87 , L_9 ,
& V_2 -> V_67 [ V_79 ] ) ;
if ( V_6 < 0 )
V_2 -> V_67 [ V_79 ] = V_91 ;
if ( ! V_2 -> V_67 [ V_79 ] ) {
F_8 ( V_2 -> V_27 , L_10 ) ;
return - V_71 ;
}
V_6 = F_1 ( V_2 , V_92 , & V_90 ) ;
if ( V_6 < 0 )
return V_6 ;
V_88 = ( V_90 & V_93 ) ? - 1 : 1 ;
V_90 &= ~ V_93 ;
V_89 = V_91 * 1000 ;
V_89 += V_88 * V_90 * V_94 ;
V_89 /= 1000 ;
V_2 -> V_67 [ V_77 ] = V_89 ;
return 0 ;
}
static int F_28 ( struct V_95 * V_96 )
{
struct V_86 * V_87 = V_96 -> V_27 . V_97 ;
struct V_98 * V_27 = & V_96 -> V_27 ;
struct V_54 * V_55 ;
struct V_1 * V_2 ;
int V_6 , V_99 ;
T_5 V_100 ;
V_55 = F_29 ( V_27 , sizeof( * V_2 ) ) ;
if ( ! V_55 )
return - V_101 ;
V_2 = F_19 ( V_55 ) ;
V_2 -> V_27 = V_27 ;
V_2 -> V_7 = F_30 ( V_27 -> V_102 , NULL ) ;
if ( ! V_2 -> V_7 )
return - V_103 ;
F_31 ( & V_2 -> V_42 ) ;
F_32 ( & V_2 -> V_64 ) ;
V_6 = F_27 ( V_87 , L_11 , & V_100 ) ;
if ( V_6 < 0 )
return - V_103 ;
V_2 -> V_8 = V_100 ;
V_6 = F_25 ( V_2 ) ;
if ( V_6 < 0 )
return - V_103 ;
V_6 = F_26 ( V_2 , V_87 ) ;
if ( V_6 < 0 )
return - V_103 ;
F_22 ( V_2 -> V_27 , L_12 ,
V_2 -> V_67 [ V_77 ] ,
V_2 -> V_67 [ V_79 ] ) ;
V_99 = F_33 ( V_96 , 0 ) ;
if ( V_99 == - V_104 )
return V_99 ;
if ( V_99 < 0 )
V_2 -> V_41 = true ;
V_6 = F_5 ( V_2 ) ;
if ( V_6 < 0 ) {
F_8 ( V_27 , L_13 ) ;
return V_6 ;
}
if ( ! V_2 -> V_41 ) {
V_6 = F_34 ( V_27 , V_99 , F_23 , 0 ,
L_14 , V_2 ) ;
if ( ! V_6 )
F_35 ( V_99 ) ;
else
return V_6 ;
} else {
F_36 ( V_2 -> V_27 , 1 ) ;
}
V_6 = F_24 ( V_2 ) ;
if ( V_6 < 0 ) {
F_8 ( V_27 , L_15 ) ;
return V_6 ;
}
V_55 -> V_27 . V_102 = V_27 ;
V_55 -> V_27 . V_97 = V_87 ;
V_55 -> V_105 = V_96 -> V_105 ;
V_55 -> V_106 = V_107 ;
V_55 -> V_108 = & V_109 ;
V_55 -> V_110 = V_111 ;
V_55 -> V_112 = F_37 ( V_111 ) ;
return F_38 ( V_27 , V_55 ) ;
}
