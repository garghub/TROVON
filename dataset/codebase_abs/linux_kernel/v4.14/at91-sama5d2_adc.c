static int F_1 ( struct V_1 * V_2 , bool V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = F_3 ( V_5 ) ;
T_1 V_8 = F_4 ( V_7 , V_9 ) ;
T_2 V_10 ;
V_8 &= ~ V_11 ;
if ( V_3 )
V_8 |= V_7 -> V_12 -> V_13 ;
F_5 ( V_7 , V_9 , V_8 ) ;
F_6 (bit, indio->active_scan_mask, indio->num_channels) {
struct V_14 const * V_15 = V_5 -> V_16 + V_10 ;
if ( V_3 ) {
F_5 ( V_7 , V_17 ,
F_7 ( V_15 -> V_18 ) ) ;
F_5 ( V_7 , V_19 ,
F_7 ( V_15 -> V_18 ) ) ;
} else {
F_5 ( V_7 , V_20 ,
F_7 ( V_15 -> V_18 ) ) ;
F_5 ( V_7 , V_21 ,
F_7 ( V_15 -> V_18 ) ) ;
}
}
return 0 ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = F_3 ( V_5 ) ;
F_9 ( V_7 -> V_22 ) ;
F_4 ( V_7 , V_23 ) ;
return 0 ;
}
static struct V_1 * F_10 ( struct V_4 * V_5 ,
char * V_24 )
{
struct V_1 * V_2 ;
int V_25 ;
V_2 = F_11 ( & V_5 -> V_26 , L_1 , V_5 -> V_27 ,
V_5 -> V_28 , V_24 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_26 . V_29 = V_5 -> V_26 . V_29 ;
F_12 ( V_2 , V_5 ) ;
V_2 -> V_30 = & V_31 ;
V_25 = F_13 ( & V_5 -> V_26 , V_2 ) ;
if ( V_25 )
return F_14 ( V_25 ) ;
return V_2 ;
}
static int F_15 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = F_3 ( V_5 ) ;
V_7 -> V_2 = F_10 ( V_5 , V_7 -> V_12 -> V_27 ) ;
if ( F_16 ( V_7 -> V_2 ) ) {
F_17 ( & V_5 -> V_26 ,
L_2 ) ;
return F_18 ( V_7 -> V_2 ) ;
}
return 0 ;
}
static T_3 F_19 ( int V_22 , void * V_32 )
{
struct V_33 * V_34 = V_32 ;
struct V_4 * V_5 = V_34 -> V_35 ;
struct V_6 * V_7 = F_3 ( V_5 ) ;
int V_36 = 0 ;
T_2 V_10 ;
F_6 (bit, indio->active_scan_mask, indio->num_channels) {
struct V_14 const * V_15 = V_5 -> V_16 + V_10 ;
V_7 -> V_37 [ V_36 ] = F_4 ( V_7 , V_15 -> V_38 ) ;
V_36 ++ ;
}
F_20 ( V_5 , V_7 -> V_37 , V_34 -> V_39 ) ;
F_21 ( V_5 -> V_2 ) ;
return V_40 ;
}
static int F_22 ( struct V_4 * V_5 )
{
return F_23 ( & V_5 -> V_26 , V_5 ,
& V_41 ,
& F_19 , NULL ) ;
}
static unsigned F_24 ( unsigned V_42 ,
unsigned V_43 )
{
static const unsigned int V_44 [] = {
0 , 8 , 16 , 24 ,
64 , 80 , 96 , 112 ,
512 , 576 , 640 , 704 ,
768 , 832 , 896 , 960
} ;
unsigned V_45 , V_36 ;
V_45 = V_42 * V_43 / 1000 ;
for ( V_36 = 0 ; V_36 < F_25 ( V_44 ) ; V_36 ++ )
if ( V_44 [ V_36 ] > V_45 )
break;
return V_36 ;
}
static void F_26 ( struct V_6 * V_7 , unsigned V_46 )
{
struct V_4 * V_35 = F_27 ( V_7 ) ;
unsigned V_47 , V_48 , V_49 , V_50 ;
V_47 = F_28 ( V_7 -> V_51 ) ;
V_48 = ( V_47 / ( 2 * V_46 ) ) - 1 ;
V_49 = F_24 ( V_7 -> V_52 . V_53 ,
V_46 / 1000 ) ;
V_50 = F_4 ( V_7 , V_54 ) ;
V_50 &= ~ ( V_55 | V_56 ) ;
V_50 |= F_29 ( V_49 ) ;
V_50 |= F_30 ( V_48 ) ;
F_5 ( V_7 , V_54 , V_50 ) ;
F_31 ( & V_35 -> V_26 , L_3 ,
V_46 , V_49 , V_48 ) ;
}
static unsigned F_32 ( struct V_6 * V_7 )
{
unsigned V_57 , V_47 = F_28 ( V_7 -> V_51 ) ;
unsigned V_50 , V_48 ;
V_50 = F_4 ( V_7 , V_54 ) ;
V_48 = ( V_50 >> V_58 )
& V_59 ;
V_57 = V_47 / ( 2 * ( V_48 + 1 ) ) ;
return V_57 ;
}
static T_3 F_33 ( int V_22 , void * V_60 )
{
struct V_4 * V_5 = V_60 ;
struct V_6 * V_7 = F_3 ( V_5 ) ;
T_1 V_8 = F_4 ( V_7 , V_61 ) ;
T_1 V_62 = F_4 ( V_7 , V_63 ) ;
if ( ! ( V_8 & V_62 ) )
return V_64 ;
if ( F_34 ( V_5 ) ) {
F_35 ( V_22 ) ;
F_36 ( V_5 -> V_2 ) ;
} else {
V_7 -> V_65 = F_4 ( V_7 , V_7 -> V_15 -> V_38 ) ;
V_7 -> V_66 = true ;
F_37 ( & V_7 -> V_67 ) ;
}
return V_40 ;
}
static int F_38 ( struct V_4 * V_35 ,
struct V_14 const * V_15 ,
int * V_68 , int * V_69 , long V_70 )
{
struct V_6 * V_7 = F_3 ( V_35 ) ;
T_1 V_71 = 0 ;
int V_25 ;
switch ( V_70 ) {
case V_72 :
V_25 = F_39 ( V_35 ) ;
if ( V_25 )
return V_25 ;
F_40 ( & V_7 -> V_73 ) ;
V_7 -> V_15 = V_15 ;
if ( V_15 -> V_74 )
V_71 = ( F_7 ( V_15 -> V_18 ) | F_7 ( V_15 -> V_75 ) ) <<
V_76 ;
F_5 ( V_7 , V_77 , V_71 ) ;
F_5 ( V_7 , V_17 , F_7 ( V_15 -> V_18 ) ) ;
F_5 ( V_7 , V_19 , F_7 ( V_15 -> V_18 ) ) ;
F_5 ( V_7 , V_78 , V_79 ) ;
V_25 = F_41 ( V_7 -> V_67 ,
V_7 -> V_66 ,
F_42 ( 1000 ) ) ;
if ( V_25 == 0 )
V_25 = - V_80 ;
if ( V_25 > 0 ) {
* V_68 = V_7 -> V_65 ;
if ( V_15 -> V_81 . V_82 == 's' )
* V_68 = F_43 ( * V_68 , 11 ) ;
V_25 = V_83 ;
V_7 -> V_66 = false ;
}
F_5 ( V_7 , V_20 , F_7 ( V_15 -> V_18 ) ) ;
F_5 ( V_7 , V_21 , F_7 ( V_15 -> V_18 ) ) ;
F_44 ( & V_7 -> V_73 ) ;
F_45 ( V_35 ) ;
return V_25 ;
case V_84 :
* V_68 = V_7 -> V_85 / 1000 ;
if ( V_15 -> V_74 )
* V_68 *= 2 ;
* V_69 = V_15 -> V_81 . V_86 ;
return V_87 ;
case V_88 :
* V_68 = F_32 ( V_7 ) ;
return V_83 ;
default:
return - V_89 ;
}
}
static int F_46 ( struct V_4 * V_35 ,
struct V_14 const * V_15 ,
int V_68 , int V_69 , long V_70 )
{
struct V_6 * V_7 = F_3 ( V_35 ) ;
if ( V_70 != V_88 )
return - V_89 ;
if ( V_68 < V_7 -> V_52 . V_90 ||
V_68 > V_7 -> V_52 . V_91 )
return - V_89 ;
F_26 ( V_7 , V_68 ) ;
return 0 ;
}
static void F_47 ( struct V_6 * V_7 )
{
F_5 ( V_7 , V_78 , V_92 ) ;
F_5 ( V_7 , V_20 , 0xffffffff ) ;
F_5 ( V_7 , V_54 ,
F_48 ( 2 ) | V_93 ) ;
F_26 ( V_7 , V_7 -> V_52 . V_90 ) ;
}
static int F_49 ( struct V_94 * V_95 )
{
struct V_4 * V_35 ;
struct V_6 * V_7 ;
struct V_96 * V_97 ;
int V_25 , V_36 ;
T_1 V_98 = V_99 ;
V_35 = F_50 ( & V_95 -> V_26 , sizeof( * V_7 ) ) ;
if ( ! V_35 )
return - V_100 ;
V_35 -> V_26 . V_29 = & V_95 -> V_26 ;
V_35 -> V_27 = F_51 ( & V_95 -> V_26 ) ;
V_35 -> V_101 = V_102 ;
V_35 -> V_103 = & V_104 ;
V_35 -> V_16 = V_105 ;
V_35 -> V_106 = F_25 ( V_105 ) ;
V_7 = F_3 ( V_35 ) ;
V_25 = F_52 ( V_95 -> V_26 . V_107 ,
L_4 ,
& V_7 -> V_52 . V_90 ) ;
if ( V_25 ) {
F_17 ( & V_95 -> V_26 ,
L_5 ) ;
return V_25 ;
}
V_25 = F_52 ( V_95 -> V_26 . V_107 ,
L_6 ,
& V_7 -> V_52 . V_91 ) ;
if ( V_25 ) {
F_17 ( & V_95 -> V_26 ,
L_7 ) ;
return V_25 ;
}
V_25 = F_52 ( V_95 -> V_26 . V_107 , L_8 ,
& V_7 -> V_52 . V_53 ) ;
if ( V_25 ) {
F_17 ( & V_95 -> V_26 ,
L_9 ) ;
return V_25 ;
}
V_25 = F_52 ( V_95 -> V_26 . V_107 ,
L_10 , & V_98 ) ;
if ( V_25 ) {
F_31 ( & V_95 -> V_26 ,
L_11 ) ;
}
V_7 -> V_12 = NULL ;
for ( V_36 = 0 ; V_36 < V_108 + 1 ; V_36 ++ )
if ( V_109 [ V_36 ] . V_98 == V_98 ) {
V_7 -> V_12 = & V_109 [ V_36 ] ;
break;
}
if ( ! V_7 -> V_12 ) {
F_17 ( & V_95 -> V_26 , L_12 ) ;
return - V_89 ;
}
F_53 ( & V_7 -> V_67 ) ;
F_54 ( & V_7 -> V_73 ) ;
V_97 = F_55 ( V_95 , V_110 , 0 ) ;
if ( ! V_97 )
return - V_89 ;
V_7 -> V_111 = F_56 ( & V_95 -> V_26 , V_97 ) ;
if ( F_16 ( V_7 -> V_111 ) )
return F_18 ( V_7 -> V_111 ) ;
V_7 -> V_22 = F_57 ( V_95 , 0 ) ;
if ( V_7 -> V_22 <= 0 ) {
if ( ! V_7 -> V_22 )
V_7 -> V_22 = - V_112 ;
return V_7 -> V_22 ;
}
V_7 -> V_51 = F_58 ( & V_95 -> V_26 , L_13 ) ;
if ( F_16 ( V_7 -> V_51 ) )
return F_18 ( V_7 -> V_51 ) ;
V_7 -> V_113 = F_59 ( & V_95 -> V_26 , L_14 ) ;
if ( F_16 ( V_7 -> V_113 ) )
return F_18 ( V_7 -> V_113 ) ;
V_7 -> V_114 = F_59 ( & V_95 -> V_26 , L_15 ) ;
if ( F_16 ( V_7 -> V_114 ) )
return F_18 ( V_7 -> V_114 ) ;
V_25 = F_60 ( & V_95 -> V_26 , V_7 -> V_22 , F_33 , 0 ,
V_95 -> V_26 . V_115 -> V_27 , V_35 ) ;
if ( V_25 )
return V_25 ;
V_25 = F_61 ( V_7 -> V_113 ) ;
if ( V_25 )
return V_25 ;
V_25 = F_61 ( V_7 -> V_114 ) ;
if ( V_25 )
goto V_116;
V_7 -> V_85 = F_62 ( V_7 -> V_114 ) ;
if ( V_7 -> V_85 <= 0 ) {
V_25 = - V_89 ;
goto V_117;
}
F_47 ( V_7 ) ;
V_25 = F_63 ( V_7 -> V_51 ) ;
if ( V_25 )
goto V_117;
F_64 ( V_95 , V_35 ) ;
if ( V_7 -> V_12 -> V_118 ) {
V_25 = F_22 ( V_35 ) ;
if ( V_25 < 0 ) {
F_17 ( & V_95 -> V_26 , L_16 ) ;
goto V_119;
}
V_25 = F_15 ( V_35 ) ;
if ( V_25 < 0 ) {
F_17 ( & V_95 -> V_26 , L_17 ) ;
goto V_119;
}
}
V_25 = F_65 ( V_35 ) ;
if ( V_25 < 0 )
goto V_119;
if ( V_7 -> V_12 -> V_118 )
F_66 ( & V_95 -> V_26 , L_18 ,
V_7 -> V_12 -> V_27 ) ;
F_66 ( & V_95 -> V_26 , L_19 ,
F_67 ( V_7 -> V_111 + V_120 ) ) ;
return 0 ;
V_119:
F_68 ( V_7 -> V_51 ) ;
V_117:
F_69 ( V_7 -> V_114 ) ;
V_116:
F_69 ( V_7 -> V_113 ) ;
return V_25 ;
}
static int F_70 ( struct V_94 * V_95 )
{
struct V_4 * V_35 = F_71 ( V_95 ) ;
struct V_6 * V_7 = F_3 ( V_35 ) ;
F_72 ( V_35 ) ;
F_68 ( V_7 -> V_51 ) ;
F_69 ( V_7 -> V_114 ) ;
F_69 ( V_7 -> V_113 ) ;
return 0 ;
}
static T_4 int F_73 ( struct V_121 * V_26 )
{
struct V_4 * V_35 =
F_71 ( F_74 ( V_26 ) ) ;
struct V_6 * V_7 = F_3 ( V_35 ) ;
F_5 ( V_7 , V_78 , V_92 ) ;
F_68 ( V_7 -> V_51 ) ;
F_69 ( V_7 -> V_114 ) ;
F_69 ( V_7 -> V_113 ) ;
return F_75 ( V_26 ) ;
}
static T_4 int F_76 ( struct V_121 * V_26 )
{
struct V_4 * V_35 =
F_71 ( F_74 ( V_26 ) ) ;
struct V_6 * V_7 = F_3 ( V_35 ) ;
int V_25 ;
V_25 = F_77 ( V_26 ) ;
if ( V_25 )
goto V_122;
V_25 = F_61 ( V_7 -> V_113 ) ;
if ( V_25 )
goto V_122;
V_25 = F_61 ( V_7 -> V_114 ) ;
if ( V_25 )
goto V_123;
V_25 = F_63 ( V_7 -> V_51 ) ;
if ( V_25 )
goto V_124;
F_47 ( V_7 ) ;
if ( F_34 ( V_35 ) )
F_1 ( V_7 -> V_2 , true ) ;
return 0 ;
V_124:
F_69 ( V_7 -> V_114 ) ;
V_123:
F_69 ( V_7 -> V_113 ) ;
V_122:
F_17 ( & V_35 -> V_26 , L_20 ) ;
return V_25 ;
}
