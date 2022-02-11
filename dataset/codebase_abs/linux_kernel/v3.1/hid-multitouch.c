static int F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 . V_4 != 0 || V_2 -> V_5 == 0 )
return V_2 -> V_3 . V_4 ;
else
return - 1 ;
}
static int F_2 ( struct V_1 * V_2 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < V_2 -> V_7 ; ++ V_6 ) {
if ( V_2 -> V_8 [ V_6 ] . V_4 == V_2 -> V_3 . V_4 &&
V_2 -> V_8 [ V_6 ] . V_9 )
return V_6 ;
}
for ( V_6 = 0 ; V_6 < V_2 -> V_7 ; ++ V_6 ) {
if ( ! V_2 -> V_8 [ V_6 ] . V_10 &&
! V_2 -> V_8 [ V_6 ] . V_9 )
return V_6 ;
}
return - 1 ;
}
static void F_3 ( struct V_11 * V_12 ,
struct V_13 * V_14 , struct V_15 * V_16 )
{
struct V_1 * V_2 = F_4 ( V_12 ) ;
switch ( V_16 -> V_17 ) {
case V_18 :
V_2 -> V_19 = V_14 -> V_20 -> V_21 ;
break;
case V_22 :
V_2 -> V_7 = V_14 -> V_23 [ 0 ] ;
if ( V_2 -> V_24 -> V_7 )
V_2 -> V_7 = V_2 -> V_24 -> V_7 ;
break;
}
}
static void F_5 ( struct V_25 * V_26 , unsigned int V_27 ,
struct V_13 * V_14 , int V_28 )
{
int V_29 = V_14 -> V_30 ;
int V_31 = V_14 -> V_32 ;
int V_33 = V_28 ? ( V_31 - V_29 ) / V_28 : 0 ;
F_6 ( V_26 , V_27 , V_29 , V_31 , V_33 , 0 ) ;
}
static int F_7 ( struct V_11 * V_12 , struct V_34 * V_35 ,
struct V_13 * V_14 , struct V_15 * V_16 ,
unsigned long * * V_36 , int * V_37 )
{
struct V_1 * V_2 = F_4 ( V_12 ) ;
struct V_38 * V_39 = V_2 -> V_24 ;
T_1 V_40 = V_39 -> V_40 ;
switch ( V_16 -> V_17 & V_41 ) {
case V_42 :
switch ( V_16 -> V_17 ) {
case V_43 :
if ( V_40 & V_44 )
V_14 -> V_32 = 32760 ;
F_8 ( V_35 , V_16 , V_36 , V_37 ,
V_45 , V_46 ) ;
F_5 ( V_35 -> V_26 , V_46 , V_14 ,
V_39 -> V_47 ) ;
F_5 ( V_35 -> V_26 , V_48 , V_14 , V_39 -> V_47 ) ;
if ( V_2 -> V_49 == V_16 -> V_50 ) {
V_2 -> V_51 = V_16 -> V_17 ;
V_2 -> V_52 = V_14 -> V_53 ;
}
return 1 ;
case V_54 :
if ( V_40 & V_44 )
V_14 -> V_32 = 32760 ;
F_8 ( V_35 , V_16 , V_36 , V_37 ,
V_45 , V_55 ) ;
F_5 ( V_35 -> V_26 , V_55 , V_14 ,
V_39 -> V_47 ) ;
F_5 ( V_35 -> V_26 , V_56 , V_14 , V_39 -> V_47 ) ;
if ( V_2 -> V_49 == V_16 -> V_50 ) {
V_2 -> V_51 = V_16 -> V_17 ;
V_2 -> V_52 = V_14 -> V_53 ;
}
return 1 ;
}
return 0 ;
case V_57 :
switch ( V_16 -> V_17 ) {
case V_58 :
if ( V_2 -> V_49 == V_16 -> V_50 ) {
V_2 -> V_51 = V_16 -> V_17 ;
V_2 -> V_52 = V_14 -> V_53 ;
}
return 1 ;
case V_59 :
if ( V_2 -> V_49 == V_16 -> V_50 ) {
V_2 -> V_51 = V_16 -> V_17 ;
V_2 -> V_52 = V_14 -> V_53 ;
}
return 1 ;
case V_60 :
F_8 ( V_35 , V_16 , V_36 , V_37 , V_61 , V_62 ) ;
F_9 ( V_35 -> V_26 , V_61 , V_62 ) ;
if ( V_2 -> V_49 == V_16 -> V_50 ) {
V_2 -> V_51 = V_16 -> V_17 ;
V_2 -> V_52 = V_14 -> V_53 ;
}
return 1 ;
case V_63 :
if ( ! V_2 -> V_7 )
V_2 -> V_7 = V_64 ;
F_10 ( V_35 -> V_26 , V_2 -> V_7 ) ;
V_2 -> V_51 = V_16 -> V_17 ;
V_2 -> V_52 = V_14 -> V_53 ;
V_2 -> V_49 = V_16 -> V_50 ;
return 1 ;
case V_65 :
F_8 ( V_35 , V_16 , V_36 , V_37 ,
V_45 , V_66 ) ;
F_5 ( V_35 -> V_26 , V_66 , V_14 ,
V_39 -> V_67 ) ;
if ( V_2 -> V_49 == V_16 -> V_50 ) {
V_2 -> V_51 = V_16 -> V_17 ;
V_2 -> V_52 = V_14 -> V_53 ;
}
return 1 ;
case V_68 :
F_8 ( V_35 , V_16 , V_36 , V_37 ,
V_45 , V_69 ) ;
F_5 ( V_35 -> V_26 , V_69 , V_14 ,
V_39 -> V_70 ) ;
F_6 ( V_35 -> V_26 ,
V_71 , 0 , 1 , 0 , 0 ) ;
if ( V_2 -> V_49 == V_16 -> V_50 ) {
V_2 -> V_51 = V_16 -> V_17 ;
V_2 -> V_52 = V_14 -> V_53 ;
}
return 1 ;
case V_72 :
if ( V_40 & V_44 )
V_14 -> V_30 = 0 ;
F_8 ( V_35 , V_16 , V_36 , V_37 ,
V_45 , V_73 ) ;
F_5 ( V_35 -> V_26 , V_73 , V_14 ,
V_39 -> V_74 ) ;
F_5 ( V_35 -> V_26 , V_75 , V_14 ,
V_39 -> V_74 ) ;
if ( V_2 -> V_49 == V_16 -> V_50 ) {
V_2 -> V_51 = V_16 -> V_17 ;
V_2 -> V_52 = V_14 -> V_53 ;
}
return 1 ;
case V_76 :
if ( V_2 -> V_49 == V_16 -> V_50 )
V_2 -> V_52 = V_14 -> V_53 ;
return 1 ;
case V_22 :
if ( V_2 -> V_49 == V_16 -> V_50 )
V_2 -> V_52 = V_14 -> V_53 ;
return - 1 ;
}
return 0 ;
case 0xff000000 :
return - 1 ;
}
return 0 ;
}
static int F_11 ( struct V_11 * V_12 , struct V_34 * V_35 ,
struct V_13 * V_14 , struct V_15 * V_16 ,
unsigned long * * V_36 , int * V_37 )
{
if ( V_16 -> type == V_61 || V_16 -> type == V_45 )
F_12 ( V_16 -> type , V_35 -> V_26 -> V_77 ) ;
return - 1 ;
}
static int F_13 ( struct V_1 * V_2 )
{
T_1 V_40 = V_2 -> V_24 -> V_40 ;
if ( V_40 & V_78 )
return V_2 -> V_3 . V_4 ;
if ( V_40 & V_79 )
return F_1 ( V_2 ) ;
if ( V_40 & V_80 )
return V_2 -> V_5 ;
if ( V_40 & V_81 )
return V_2 -> V_3 . V_4 - 1 ;
return F_2 ( V_2 ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
V_2 -> V_3 . V_10 = true ;
if ( V_2 -> V_82 ) {
int V_83 = F_13 ( V_2 ) ;
if ( V_83 >= 0 && V_83 < V_2 -> V_7 )
V_2 -> V_8 [ V_83 ] = V_2 -> V_3 ;
}
V_2 -> V_5 ++ ;
}
static void F_15 ( struct V_1 * V_2 , struct V_25 * V_26 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < V_2 -> V_7 ; ++ V_6 ) {
struct V_84 * V_85 = & ( V_2 -> V_8 [ V_6 ] ) ;
if ( ( V_2 -> V_24 -> V_40 & V_86 ) &&
! V_85 -> V_10 ) {
V_85 -> V_9 = false ;
}
F_16 ( V_26 , V_6 ) ;
F_17 ( V_26 , V_87 ,
V_85 -> V_9 ) ;
if ( V_85 -> V_9 ) {
int V_88 = ( V_85 -> V_89 > V_85 -> V_90 ) ;
int V_91 = V_37 ( V_85 -> V_89 , V_85 -> V_90 ) >> 1 ;
int V_92 = F_18 ( V_85 -> V_89 , V_85 -> V_90 ) >> 1 ;
F_19 ( V_26 , V_45 , V_46 , V_85 -> V_93 ) ;
F_19 ( V_26 , V_45 , V_55 , V_85 -> V_94 ) ;
F_19 ( V_26 , V_45 , V_71 , V_88 ) ;
F_19 ( V_26 , V_45 , V_73 , V_85 -> V_95 ) ;
F_19 ( V_26 , V_45 , V_66 , V_91 ) ;
F_19 ( V_26 , V_45 , V_69 , V_92 ) ;
}
V_85 -> V_10 = false ;
}
F_20 ( V_26 , true ) ;
F_21 ( V_26 ) ;
V_2 -> V_5 = 0 ;
}
static int F_22 ( struct V_11 * V_17 , struct V_13 * V_14 ,
struct V_15 * V_16 , T_1 V_23 )
{
struct V_1 * V_2 = F_4 ( V_17 ) ;
T_1 V_40 = V_2 -> V_24 -> V_40 ;
if ( V_17 -> V_96 & V_97 && V_2 -> V_8 ) {
switch ( V_16 -> V_17 ) {
case V_58 :
if ( V_40 & V_98 )
V_2 -> V_82 = V_23 ;
break;
case V_60 :
if ( V_40 & V_86 )
V_2 -> V_82 = V_23 ;
V_2 -> V_3 . V_9 = V_23 ;
break;
case V_59 :
if ( V_40 & V_99 )
V_2 -> V_82 = V_23 ;
break;
case V_63 :
V_2 -> V_3 . V_4 = V_23 ;
break;
case V_72 :
V_2 -> V_3 . V_95 = V_23 ;
break;
case V_43 :
V_2 -> V_3 . V_93 = V_23 ;
break;
case V_54 :
V_2 -> V_3 . V_94 = V_23 ;
break;
case V_65 :
V_2 -> V_3 . V_89 = V_23 ;
break;
case V_68 :
V_2 -> V_3 . V_90 = V_23 ;
break;
case V_76 :
if ( V_23 )
V_2 -> V_100 = V_23 ;
break;
default:
return 0 ;
}
if ( V_16 -> V_17 == V_2 -> V_51 ) {
F_14 ( V_2 ) ;
}
if ( V_14 -> V_53 == V_2 -> V_52
&& V_2 -> V_5 >= V_2 -> V_100 )
F_15 ( V_2 , V_14 -> V_101 -> V_26 ) ;
}
if ( V_17 -> V_96 & V_102 && V_17 -> V_103 )
V_17 -> V_103 ( V_17 , V_14 , V_16 , V_23 ) ;
return 1 ;
}
static void F_23 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_4 ( V_12 ) ;
struct V_104 * V_105 ;
struct V_106 * V_107 ;
if ( V_2 -> V_19 < 0 )
return;
V_107 = & ( V_12 -> V_108 [ V_109 ] ) ;
V_105 = V_107 -> V_110 [ V_2 -> V_19 ] ;
if ( V_105 ) {
V_105 -> V_14 [ 0 ] -> V_23 [ 0 ] = 0x02 ;
F_24 ( V_12 , V_105 , V_111 ) ;
}
}
static int F_25 ( struct V_11 * V_12 , const struct V_112 * V_21 )
{
int V_113 , V_6 ;
struct V_1 * V_2 ;
struct V_38 * V_24 = V_114 ;
for ( V_6 = 0 ; V_114 [ V_6 ] . V_115 ; V_6 ++ ) {
if ( V_21 -> V_116 == V_114 [ V_6 ] . V_115 ) {
V_24 = & ( V_114 [ V_6 ] ) ;
break;
}
}
V_12 -> V_40 |= V_117 ;
V_2 = F_26 ( sizeof( struct V_1 ) , V_118 ) ;
if ( ! V_2 ) {
F_27 ( & V_12 -> V_119 , L_1 ) ;
return - V_120 ;
}
V_2 -> V_24 = V_24 ;
V_2 -> V_19 = - 1 ;
V_2 -> V_49 = - 1 ;
F_28 ( V_12 , V_2 ) ;
V_113 = F_29 ( V_12 ) ;
if ( V_113 != 0 )
goto V_121;
V_113 = F_30 ( V_12 , V_122 ) ;
if ( V_113 )
goto V_121;
V_2 -> V_8 = F_26 ( V_2 -> V_7 * sizeof( struct V_84 ) ,
V_118 ) ;
if ( ! V_2 -> V_8 ) {
F_27 ( & V_12 -> V_119 , L_2 ) ;
F_31 ( V_12 ) ;
V_113 = - V_120 ;
goto V_121;
}
F_23 ( V_12 ) ;
return 0 ;
V_121:
F_32 ( V_2 ) ;
return V_113 ;
}
static int F_33 ( struct V_11 * V_12 )
{
F_23 ( V_12 ) ;
return 0 ;
}
static void F_34 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_4 ( V_12 ) ;
F_31 ( V_12 ) ;
F_32 ( V_2 -> V_8 ) ;
F_32 ( V_2 ) ;
F_28 ( V_12 , NULL ) ;
}
static int T_2 F_35 ( void )
{
return F_36 ( & V_123 ) ;
}
static void T_3 F_37 ( void )
{
F_38 ( & V_123 ) ;
}
