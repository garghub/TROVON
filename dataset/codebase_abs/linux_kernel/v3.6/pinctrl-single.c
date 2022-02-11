static unsigned T_1 F_1 ( void T_2 * V_1 )
{
return F_2 ( V_1 ) ;
}
static unsigned T_1 F_3 ( void T_2 * V_1 )
{
return F_4 ( V_1 ) ;
}
static unsigned T_1 F_5 ( void T_2 * V_1 )
{
return F_6 ( V_1 ) ;
}
static void T_1 F_7 ( unsigned V_2 , void T_2 * V_1 )
{
F_8 ( V_2 , V_1 ) ;
}
static void T_1 F_9 ( unsigned V_2 , void T_2 * V_1 )
{
F_10 ( V_2 , V_1 ) ;
}
static void T_1 F_11 ( unsigned V_2 , void T_2 * V_1 )
{
F_12 ( V_2 , V_1 ) ;
}
static int F_13 ( struct V_3 * V_4 )
{
struct V_5 * V_6 ;
V_6 = F_14 ( V_4 ) ;
return V_6 -> V_7 ;
}
static const char * F_15 ( struct V_3 * V_4 ,
unsigned V_8 )
{
struct V_5 * V_6 ;
struct V_9 * V_10 ;
V_6 = F_14 ( V_4 ) ;
V_10 = F_16 ( & V_6 -> V_11 , V_8 ) ;
if ( ! V_10 ) {
F_17 ( V_6 -> V_12 , L_1 ,
V_13 , V_8 ) ;
return NULL ;
}
return V_10 -> V_14 ;
}
static int F_18 ( struct V_3 * V_4 ,
unsigned V_8 ,
const unsigned * * V_15 ,
unsigned * V_16 )
{
struct V_5 * V_6 ;
struct V_9 * V_10 ;
V_6 = F_14 ( V_4 ) ;
V_10 = F_16 ( & V_6 -> V_11 , V_8 ) ;
if ( ! V_10 ) {
F_17 ( V_6 -> V_12 , L_1 ,
V_13 , V_8 ) ;
return - V_17 ;
}
* V_15 = V_10 -> V_18 ;
* V_16 = V_10 -> V_19 ;
return 0 ;
}
static void F_19 ( struct V_3 * V_4 ,
struct V_20 * V_21 ,
unsigned V_22 )
{
F_20 ( V_21 , L_2 V_23 ) ;
}
static void F_21 ( struct V_3 * V_4 ,
struct V_24 * V_25 , unsigned V_26 )
{
struct V_5 * V_6 ;
V_6 = F_14 ( V_4 ) ;
F_22 ( V_6 -> V_12 , V_25 ) ;
}
static int F_23 ( struct V_3 * V_4 )
{
struct V_5 * V_6 ;
V_6 = F_14 ( V_4 ) ;
return V_6 -> V_27 ;
}
static const char * F_24 ( struct V_3 * V_4 ,
unsigned V_28 )
{
struct V_5 * V_6 ;
struct V_29 * V_30 ;
V_6 = F_14 ( V_4 ) ;
V_30 = F_16 ( & V_6 -> V_31 , V_28 ) ;
if ( ! V_30 ) {
F_17 ( V_6 -> V_12 , L_3 ,
V_13 , V_28 ) ;
return NULL ;
}
return V_30 -> V_14 ;
}
static int F_25 ( struct V_3 * V_4 ,
unsigned V_28 ,
const char * const * * V_32 ,
unsigned * const V_7 )
{
struct V_5 * V_6 ;
struct V_29 * V_30 ;
V_6 = F_14 ( V_4 ) ;
V_30 = F_16 ( & V_6 -> V_31 , V_28 ) ;
if ( ! V_30 ) {
F_17 ( V_6 -> V_12 , L_3 ,
V_13 , V_28 ) ;
return - V_17 ;
}
* V_32 = V_30 -> V_33 ;
* V_7 = V_30 -> V_34 ;
return 0 ;
}
static int F_26 ( struct V_3 * V_4 , unsigned V_28 ,
unsigned V_10 )
{
struct V_5 * V_6 ;
struct V_29 * V_30 ;
int V_35 ;
V_6 = F_14 ( V_4 ) ;
V_30 = F_16 ( & V_6 -> V_31 , V_28 ) ;
if ( ! V_30 )
return - V_17 ;
F_27 ( V_6 -> V_12 , L_4 ,
V_30 -> V_14 , V_28 ) ;
for ( V_35 = 0 ; V_35 < V_30 -> V_36 ; V_35 ++ ) {
struct V_37 * V_38 ;
unsigned V_2 ;
V_38 = & V_30 -> V_38 [ V_35 ] ;
V_2 = V_6 -> V_39 ( V_38 -> V_1 ) ;
V_2 &= ~ V_6 -> V_40 ;
V_2 |= V_38 -> V_2 ;
V_6 -> V_41 ( V_2 , V_38 -> V_1 ) ;
}
return 0 ;
}
static void F_28 ( struct V_3 * V_4 , unsigned V_28 ,
unsigned V_10 )
{
struct V_5 * V_6 ;
struct V_29 * V_30 ;
int V_35 ;
V_6 = F_14 ( V_4 ) ;
V_30 = F_16 ( & V_6 -> V_31 , V_28 ) ;
if ( ! V_30 ) {
F_17 ( V_6 -> V_12 , L_3 ,
V_13 , V_28 ) ;
return;
}
if ( V_6 -> V_42 == V_43 ) {
F_27 ( V_6 -> V_12 , L_5 ,
V_30 -> V_14 , V_28 ) ;
return;
}
F_27 ( V_6 -> V_12 , L_6 ,
V_28 , V_30 -> V_14 ) ;
for ( V_35 = 0 ; V_35 < V_30 -> V_36 ; V_35 ++ ) {
struct V_37 * V_38 ;
unsigned V_2 ;
V_38 = & V_30 -> V_38 [ V_35 ] ;
V_2 = V_6 -> V_39 ( V_38 -> V_1 ) ;
V_2 &= ~ V_6 -> V_40 ;
V_2 |= V_6 -> V_42 << V_6 -> V_44 ;
V_6 -> V_41 ( V_2 , V_38 -> V_1 ) ;
}
}
static int F_29 ( struct V_3 * V_4 ,
struct V_45 * V_46 , unsigned V_22 )
{
return - V_47 ;
}
static int F_30 ( struct V_3 * V_4 ,
unsigned V_48 , unsigned long * V_49 )
{
return - V_47 ;
}
static int F_31 ( struct V_3 * V_4 ,
unsigned V_48 , unsigned long V_49 )
{
return - V_47 ;
}
static int F_32 ( struct V_3 * V_4 ,
unsigned V_10 , unsigned long * V_49 )
{
return - V_47 ;
}
static int F_33 ( struct V_3 * V_4 ,
unsigned V_10 , unsigned long V_49 )
{
return - V_47 ;
}
static void F_34 ( struct V_3 * V_4 ,
struct V_20 * V_21 , unsigned V_22 )
{
}
static void F_35 ( struct V_3 * V_4 ,
struct V_20 * V_21 , unsigned V_50 )
{
}
static int T_3 F_36 ( struct V_5 * V_6 , unsigned V_22 )
{
struct V_51 * V_48 ;
struct V_52 * V_53 ;
int V_35 ;
V_35 = V_6 -> V_15 . V_54 ;
if ( V_35 >= V_6 -> V_55 . V_16 ) {
F_17 ( V_6 -> V_12 , L_7 ,
V_6 -> V_55 . V_16 ) ;
return - V_56 ;
}
V_48 = & V_6 -> V_15 . V_57 [ V_35 ] ;
V_53 = & V_6 -> V_58 [ V_35 ] ;
sprintf ( V_53 -> V_14 , L_8 ,
( unsigned long ) V_6 -> V_59 -> V_60 + V_22 ) ;
V_48 -> V_14 = V_53 -> V_14 ;
V_48 -> V_61 = V_35 ;
V_6 -> V_15 . V_54 ++ ;
return V_35 ;
}
static int T_3 F_37 ( struct V_5 * V_6 )
{
int V_62 , V_63 , V_35 ;
V_62 = V_6 -> V_64 / V_65 ;
V_63 = V_6 -> V_66 / V_62 ;
F_27 ( V_6 -> V_12 , L_9 , V_63 ) ;
V_6 -> V_15 . V_57 = F_38 ( V_6 -> V_12 ,
sizeof( * V_6 -> V_15 . V_57 ) * V_63 ,
V_67 ) ;
if ( ! V_6 -> V_15 . V_57 )
return - V_56 ;
V_6 -> V_58 = F_38 ( V_6 -> V_12 ,
sizeof( struct V_52 ) * V_63 ,
V_67 ) ;
if ( ! V_6 -> V_58 )
return - V_56 ;
V_6 -> V_55 . V_15 = V_6 -> V_15 . V_57 ;
V_6 -> V_55 . V_16 = V_63 ;
for ( V_35 = 0 ; V_35 < V_6 -> V_55 . V_16 ; V_35 ++ ) {
unsigned V_22 ;
int V_59 ;
V_22 = V_35 * V_62 ;
V_59 = F_36 ( V_6 , V_22 ) ;
if ( V_59 < 0 ) {
F_17 ( V_6 -> V_12 , L_10 , V_59 ) ;
return V_59 ;
}
}
return 0 ;
}
static struct V_29 * F_39 ( struct V_5 * V_6 ,
struct V_68 * V_69 ,
const char * V_14 ,
struct V_37 * V_38 ,
unsigned V_36 ,
const char * * V_33 ,
unsigned V_34 )
{
struct V_29 * V_70 ;
V_70 = F_38 ( V_6 -> V_12 , sizeof( * V_70 ) , V_67 ) ;
if ( ! V_70 )
return NULL ;
V_70 -> V_14 = V_14 ;
V_70 -> V_38 = V_38 ;
V_70 -> V_36 = V_36 ;
V_70 -> V_33 = V_33 ;
V_70 -> V_34 = V_34 ;
F_40 ( & V_6 -> V_71 ) ;
F_41 ( & V_70 -> V_72 , & V_6 -> V_73 ) ;
F_42 ( & V_6 -> V_31 , V_6 -> V_27 , V_70 ) ;
V_6 -> V_27 ++ ;
F_43 ( & V_6 -> V_71 ) ;
return V_70 ;
}
static void F_44 ( struct V_5 * V_6 ,
struct V_29 * V_70 )
{
int V_35 ;
F_40 ( & V_6 -> V_71 ) ;
for ( V_35 = 0 ; V_35 < V_6 -> V_27 ; V_35 ++ ) {
struct V_29 * V_74 ;
V_74 = F_16 ( & V_6 -> V_31 , V_35 ) ;
if ( V_74 == V_70 )
F_45 ( & V_6 -> V_31 , V_35 ) ;
}
F_46 ( & V_70 -> V_72 ) ;
F_43 ( & V_6 -> V_71 ) ;
}
static int F_47 ( struct V_5 * V_6 ,
struct V_68 * V_69 ,
const char * V_14 ,
int * V_18 ,
int V_19 )
{
struct V_9 * V_75 ;
V_75 = F_38 ( V_6 -> V_12 , sizeof( * V_75 ) , V_67 ) ;
if ( ! V_75 )
return - V_56 ;
V_75 -> V_14 = V_14 ;
V_75 -> V_69 = V_69 ;
V_75 -> V_18 = V_18 ;
V_75 -> V_19 = V_19 ;
F_40 ( & V_6 -> V_71 ) ;
F_41 ( & V_75 -> V_72 , & V_6 -> V_76 ) ;
F_42 ( & V_6 -> V_11 , V_6 -> V_7 , V_75 ) ;
V_6 -> V_7 ++ ;
F_43 ( & V_6 -> V_71 ) ;
return 0 ;
}
static int F_48 ( struct V_5 * V_6 , unsigned V_22 )
{
unsigned V_77 ;
if ( V_22 >= V_6 -> V_66 ) {
F_17 ( V_6 -> V_12 , L_11 ,
V_22 , V_6 -> V_66 ) ;
return - V_17 ;
}
V_77 = V_22 / ( V_6 -> V_64 / V_65 ) ;
return V_77 ;
}
static int F_49 ( struct V_5 * V_6 ,
struct V_68 * V_69 ,
struct V_24 * * V_25 ,
const char * * V_33 )
{
struct V_37 * V_38 ;
const T_4 * V_78 ;
int V_66 , V_79 , * V_15 , V_77 = 0 , V_74 = 0 , V_59 = - V_56 ;
struct V_29 * V_70 ;
V_78 = F_50 ( V_69 , V_80 , & V_66 ) ;
if ( ( ! V_78 ) || ( V_66 < sizeof( * V_78 ) * 2 ) ) {
F_17 ( V_6 -> V_12 , L_12 ,
V_69 -> V_14 ) ;
return - V_17 ;
}
V_66 /= sizeof( * V_78 ) ;
V_79 = V_66 / 2 ;
V_38 = F_38 ( V_6 -> V_12 , sizeof( * V_38 ) * V_79 , V_67 ) ;
if ( ! V_38 )
return - V_56 ;
V_15 = F_38 ( V_6 -> V_12 , sizeof( * V_15 ) * V_79 , V_67 ) ;
if ( ! V_15 )
goto V_81;
while ( V_77 < V_66 ) {
unsigned V_22 , V_2 ;
int V_48 ;
V_22 = F_51 ( V_78 + V_77 ++ ) ;
V_2 = F_51 ( V_78 + V_77 ++ ) ;
V_38 [ V_74 ] . V_1 = V_6 -> V_82 + V_22 ;
V_38 [ V_74 ] . V_2 = V_2 ;
V_48 = F_48 ( V_6 , V_22 ) ;
if ( V_48 < 0 ) {
F_17 ( V_6 -> V_12 ,
L_13 ,
V_69 -> V_14 , V_22 ) ;
break;
}
V_15 [ V_74 ++ ] = V_48 ;
}
V_33 [ 0 ] = V_69 -> V_14 ;
V_70 = F_39 ( V_6 , V_69 , V_69 -> V_14 , V_38 , V_74 , V_33 , 1 ) ;
if ( ! V_70 )
goto V_83;
V_59 = F_47 ( V_6 , V_69 , V_69 -> V_14 , V_15 , V_74 ) ;
if ( V_59 < 0 )
goto V_84;
( * V_25 ) -> type = V_85 ;
( * V_25 ) -> V_86 . V_78 . V_10 = V_69 -> V_14 ;
( * V_25 ) -> V_86 . V_78 . V_70 = V_69 -> V_14 ;
return 0 ;
V_84:
F_44 ( V_6 , V_70 ) ;
V_83:
F_22 ( V_6 -> V_12 , V_15 ) ;
V_81:
F_22 ( V_6 -> V_12 , V_38 ) ;
return V_59 ;
}
static int F_52 ( struct V_3 * V_4 ,
struct V_68 * V_87 ,
struct V_24 * * V_25 , unsigned * V_26 )
{
struct V_5 * V_6 ;
const char * * V_33 ;
int V_88 ;
V_6 = F_14 ( V_4 ) ;
* V_25 = F_38 ( V_6 -> V_12 , sizeof( * * V_25 ) , V_67 ) ;
if ( ! V_25 )
return - V_56 ;
* V_26 = 0 ;
V_33 = F_38 ( V_6 -> V_12 , sizeof( * V_33 ) , V_67 ) ;
if ( ! V_33 ) {
V_88 = - V_56 ;
goto V_89;
}
V_88 = F_49 ( V_6 , V_87 , V_25 , V_33 ) ;
if ( V_88 < 0 ) {
F_17 ( V_6 -> V_12 , L_14 ,
V_87 -> V_14 ) ;
goto V_90;
}
* V_26 = 1 ;
return 0 ;
V_90:
F_22 ( V_6 -> V_12 , V_33 ) ;
V_89:
F_22 ( V_6 -> V_12 , * V_25 ) ;
return V_88 ;
}
static void F_53 ( struct V_5 * V_6 )
{
struct V_91 * V_92 , * V_93 ;
int V_35 ;
F_40 ( & V_6 -> V_71 ) ;
for ( V_35 = 0 ; V_35 < V_6 -> V_27 ; V_35 ++ ) {
struct V_29 * V_30 ;
V_30 = F_16 ( & V_6 -> V_31 , V_35 ) ;
if ( ! V_30 )
continue;
F_45 ( & V_6 -> V_31 , V_35 ) ;
}
F_54 (pos, tmp, &pcs->functions) {
struct V_29 * V_70 ;
V_70 = F_55 ( V_92 , struct V_29 , V_72 ) ;
F_46 ( & V_70 -> V_72 ) ;
}
F_43 ( & V_6 -> V_71 ) ;
}
static void F_56 ( struct V_5 * V_6 )
{
struct V_91 * V_92 , * V_93 ;
int V_35 ;
F_40 ( & V_6 -> V_71 ) ;
for ( V_35 = 0 ; V_35 < V_6 -> V_7 ; V_35 ++ ) {
struct V_9 * V_75 ;
V_75 = F_16 ( & V_6 -> V_11 , V_35 ) ;
if ( ! V_75 )
continue;
F_45 ( & V_6 -> V_11 , V_35 ) ;
}
F_54 (pos, tmp, &pcs->pingroups) {
struct V_9 * V_75 ;
V_75 = F_55 ( V_92 , struct V_9 , V_72 ) ;
F_46 ( & V_75 -> V_72 ) ;
}
F_43 ( & V_6 -> V_71 ) ;
}
static void F_57 ( struct V_5 * V_6 )
{
if ( V_6 -> V_94 )
F_58 ( V_6 -> V_94 ) ;
F_53 ( V_6 ) ;
F_56 ( V_6 ) ;
}
static int T_3 F_59 ( struct V_95 * V_96 )
{
struct V_68 * V_69 = V_96 -> V_12 . V_97 ;
const struct V_98 * V_99 ;
struct V_100 * V_59 ;
struct V_5 * V_6 ;
int V_88 ;
V_99 = F_60 ( V_101 , & V_96 -> V_12 ) ;
if ( ! V_99 )
return - V_17 ;
V_6 = F_38 ( & V_96 -> V_12 , sizeof( * V_6 ) , V_67 ) ;
if ( ! V_6 ) {
F_17 ( & V_96 -> V_12 , L_15 ) ;
return - V_56 ;
}
V_6 -> V_12 = & V_96 -> V_12 ;
F_61 ( & V_6 -> V_71 ) ;
F_62 ( & V_6 -> V_76 ) ;
F_62 ( & V_6 -> V_73 ) ;
F_63 ( L_16 , & V_6 -> V_64 ,
L_17 ) ;
F_63 ( L_18 , & V_6 -> V_40 ,
L_19 ) ;
V_6 -> V_44 = F_64 ( V_6 -> V_40 ) - 1 ;
V_6 -> V_102 = V_6 -> V_40 >> V_6 -> V_44 ;
V_88 = F_65 ( V_69 , L_20 ,
& V_6 -> V_42 ) ;
if ( V_88 )
V_6 -> V_42 = V_43 ;
V_59 = F_66 ( V_96 , V_103 , 0 ) ;
if ( ! V_59 ) {
F_17 ( V_6 -> V_12 , L_21 ) ;
return - V_104 ;
}
V_6 -> V_59 = F_67 ( V_6 -> V_12 , V_59 -> V_60 ,
F_68 ( V_59 ) , V_23 ) ;
if ( ! V_6 -> V_59 ) {
F_17 ( V_6 -> V_12 , L_22 ) ;
return - V_105 ;
}
V_6 -> V_66 = F_68 ( V_6 -> V_59 ) ;
V_6 -> V_82 = F_69 ( V_6 -> V_12 , V_6 -> V_59 -> V_60 , V_6 -> V_66 ) ;
if ( ! V_6 -> V_82 ) {
F_17 ( V_6 -> V_12 , L_23 ) ;
return - V_104 ;
}
F_70 ( & V_6 -> V_11 , V_67 ) ;
F_70 ( & V_6 -> V_31 , V_67 ) ;
F_71 ( V_96 , V_6 ) ;
switch ( V_6 -> V_64 ) {
case 8 :
V_6 -> V_39 = F_1 ;
V_6 -> V_41 = F_7 ;
break;
case 16 :
V_6 -> V_39 = F_3 ;
V_6 -> V_41 = F_9 ;
break;
case 32 :
V_6 -> V_39 = F_5 ;
V_6 -> V_41 = F_11 ;
break;
default:
break;
}
V_6 -> V_55 . V_14 = V_23 ;
V_6 -> V_55 . V_106 = & V_107 ;
V_6 -> V_55 . V_108 = & V_109 ;
V_6 -> V_55 . V_110 = & V_111 ;
V_6 -> V_55 . V_112 = V_113 ;
V_88 = F_37 ( V_6 ) ;
if ( V_88 < 0 )
goto free;
V_6 -> V_94 = F_72 ( & V_6 -> V_55 , V_6 -> V_12 , V_6 ) ;
if ( ! V_6 -> V_94 ) {
F_17 ( V_6 -> V_12 , L_24 ) ;
V_88 = - V_17 ;
goto free;
}
F_73 ( V_6 -> V_12 , L_25 ,
V_6 -> V_55 . V_16 , V_6 -> V_82 , V_6 -> V_66 ) ;
return 0 ;
free:
F_57 ( V_6 ) ;
return V_88 ;
}
static int T_5 F_74 ( struct V_95 * V_96 )
{
struct V_5 * V_6 = F_75 ( V_96 ) ;
if ( ! V_6 )
return 0 ;
F_57 ( V_6 ) ;
return 0 ;
}
