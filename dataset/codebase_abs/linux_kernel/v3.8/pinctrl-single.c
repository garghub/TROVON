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
struct V_5 * V_6 ;
unsigned V_2 , V_23 ;
V_6 = F_14 ( V_4 ) ;
V_23 = V_6 -> V_24 / V_25 ;
V_2 = V_6 -> V_26 ( V_6 -> V_27 + V_22 * V_23 ) ;
F_20 ( V_21 , L_2 , V_2 , V_28 ) ;
}
static void F_21 ( struct V_3 * V_4 ,
struct V_29 * V_30 , unsigned V_31 )
{
struct V_5 * V_6 ;
V_6 = F_14 ( V_4 ) ;
F_22 ( V_6 -> V_12 , V_30 ) ;
}
static int F_23 ( struct V_3 * V_4 )
{
struct V_5 * V_6 ;
V_6 = F_14 ( V_4 ) ;
return V_6 -> V_32 ;
}
static const char * F_24 ( struct V_3 * V_4 ,
unsigned V_33 )
{
struct V_5 * V_6 ;
struct V_34 * V_35 ;
V_6 = F_14 ( V_4 ) ;
V_35 = F_16 ( & V_6 -> V_36 , V_33 ) ;
if ( ! V_35 ) {
F_17 ( V_6 -> V_12 , L_3 ,
V_13 , V_33 ) ;
return NULL ;
}
return V_35 -> V_14 ;
}
static int F_25 ( struct V_3 * V_4 ,
unsigned V_33 ,
const char * const * * V_37 ,
unsigned * const V_7 )
{
struct V_5 * V_6 ;
struct V_34 * V_35 ;
V_6 = F_14 ( V_4 ) ;
V_35 = F_16 ( & V_6 -> V_36 , V_33 ) ;
if ( ! V_35 ) {
F_17 ( V_6 -> V_12 , L_3 ,
V_13 , V_33 ) ;
return - V_17 ;
}
* V_37 = V_35 -> V_38 ;
* V_7 = V_35 -> V_39 ;
return 0 ;
}
static int F_26 ( struct V_3 * V_4 , unsigned V_33 ,
unsigned V_10 )
{
struct V_5 * V_6 ;
struct V_34 * V_35 ;
int V_40 ;
V_6 = F_14 ( V_4 ) ;
V_35 = F_16 ( & V_6 -> V_36 , V_33 ) ;
if ( ! V_35 )
return - V_17 ;
F_27 ( V_6 -> V_12 , L_4 ,
V_35 -> V_14 , V_33 ) ;
for ( V_40 = 0 ; V_40 < V_35 -> V_41 ; V_40 ++ ) {
struct V_42 * V_43 ;
unsigned V_2 , V_44 ;
V_43 = & V_35 -> V_43 [ V_40 ] ;
V_2 = V_6 -> V_26 ( V_43 -> V_1 ) ;
if ( ! V_43 -> V_44 )
V_44 = V_6 -> V_45 ;
else
V_44 = V_6 -> V_45 & V_43 -> V_44 ;
V_2 &= ~ V_44 ;
V_2 |= ( V_43 -> V_2 & V_44 ) ;
V_6 -> V_46 ( V_2 , V_43 -> V_1 ) ;
}
return 0 ;
}
static void F_28 ( struct V_3 * V_4 , unsigned V_33 ,
unsigned V_10 )
{
struct V_5 * V_6 ;
struct V_34 * V_35 ;
int V_40 ;
V_6 = F_14 ( V_4 ) ;
V_35 = F_16 ( & V_6 -> V_36 , V_33 ) ;
if ( ! V_35 ) {
F_17 ( V_6 -> V_12 , L_3 ,
V_13 , V_33 ) ;
return;
}
if ( V_6 -> V_47 == V_48 ) {
F_27 ( V_6 -> V_12 , L_5 ,
V_35 -> V_14 , V_33 ) ;
return;
}
F_27 ( V_6 -> V_12 , L_6 ,
V_33 , V_35 -> V_14 ) ;
for ( V_40 = 0 ; V_40 < V_35 -> V_41 ; V_40 ++ ) {
struct V_42 * V_43 ;
unsigned V_2 ;
V_43 = & V_35 -> V_43 [ V_40 ] ;
V_2 = V_6 -> V_26 ( V_43 -> V_1 ) ;
V_2 &= ~ V_6 -> V_45 ;
V_2 |= V_6 -> V_47 << V_6 -> V_49 ;
V_6 -> V_46 ( V_2 , V_43 -> V_1 ) ;
}
}
static int F_29 ( struct V_3 * V_4 ,
struct V_50 * V_51 , unsigned V_52 )
{
return - V_53 ;
}
static int F_30 ( struct V_3 * V_4 ,
unsigned V_22 , unsigned long * V_54 )
{
return - V_53 ;
}
static int F_31 ( struct V_3 * V_4 ,
unsigned V_22 , unsigned long V_54 )
{
return - V_53 ;
}
static int F_32 ( struct V_3 * V_4 ,
unsigned V_10 , unsigned long * V_54 )
{
return - V_53 ;
}
static int F_33 ( struct V_3 * V_4 ,
unsigned V_10 , unsigned long V_54 )
{
return - V_53 ;
}
static void F_34 ( struct V_3 * V_4 ,
struct V_20 * V_21 , unsigned V_52 )
{
}
static void F_35 ( struct V_3 * V_4 ,
struct V_20 * V_21 , unsigned V_55 )
{
}
static int F_36 ( struct V_5 * V_6 , unsigned V_52 )
{
struct V_56 * V_22 ;
struct V_57 * V_58 ;
int V_40 ;
V_40 = V_6 -> V_15 . V_59 ;
if ( V_40 >= V_6 -> V_60 . V_16 ) {
F_17 ( V_6 -> V_12 , L_7 ,
V_6 -> V_60 . V_16 ) ;
return - V_61 ;
}
V_22 = & V_6 -> V_15 . V_62 [ V_40 ] ;
V_58 = & V_6 -> V_63 [ V_40 ] ;
sprintf ( V_58 -> V_14 , L_8 ,
( unsigned long ) V_6 -> V_64 -> V_65 + V_52 ) ;
V_22 -> V_14 = V_58 -> V_14 ;
V_22 -> V_66 = V_40 ;
V_6 -> V_15 . V_59 ++ ;
return V_40 ;
}
static int F_37 ( struct V_5 * V_6 )
{
int V_23 , V_67 , V_40 ;
V_23 = V_6 -> V_24 / V_25 ;
V_67 = V_6 -> V_68 / V_23 ;
F_27 ( V_6 -> V_12 , L_9 , V_67 ) ;
V_6 -> V_15 . V_62 = F_38 ( V_6 -> V_12 ,
sizeof( * V_6 -> V_15 . V_62 ) * V_67 ,
V_69 ) ;
if ( ! V_6 -> V_15 . V_62 )
return - V_61 ;
V_6 -> V_63 = F_38 ( V_6 -> V_12 ,
sizeof( struct V_57 ) * V_67 ,
V_69 ) ;
if ( ! V_6 -> V_63 )
return - V_61 ;
V_6 -> V_60 . V_15 = V_6 -> V_15 . V_62 ;
V_6 -> V_60 . V_16 = V_67 ;
for ( V_40 = 0 ; V_40 < V_6 -> V_60 . V_16 ; V_40 ++ ) {
unsigned V_52 ;
int V_64 ;
V_52 = V_40 * V_23 ;
V_64 = F_36 ( V_6 , V_52 ) ;
if ( V_64 < 0 ) {
F_17 ( V_6 -> V_12 , L_10 , V_64 ) ;
return V_64 ;
}
}
return 0 ;
}
static struct V_34 * F_39 ( struct V_5 * V_6 ,
struct V_70 * V_71 ,
const char * V_14 ,
struct V_42 * V_43 ,
unsigned V_41 ,
const char * * V_38 ,
unsigned V_39 )
{
struct V_34 * V_72 ;
V_72 = F_38 ( V_6 -> V_12 , sizeof( * V_72 ) , V_69 ) ;
if ( ! V_72 )
return NULL ;
V_72 -> V_14 = V_14 ;
V_72 -> V_43 = V_43 ;
V_72 -> V_41 = V_41 ;
V_72 -> V_38 = V_38 ;
V_72 -> V_39 = V_39 ;
F_40 ( & V_6 -> V_73 ) ;
F_41 ( & V_72 -> V_74 , & V_6 -> V_75 ) ;
F_42 ( & V_6 -> V_36 , V_6 -> V_32 , V_72 ) ;
V_6 -> V_32 ++ ;
F_43 ( & V_6 -> V_73 ) ;
return V_72 ;
}
static void F_44 ( struct V_5 * V_6 ,
struct V_34 * V_72 )
{
int V_40 ;
F_40 ( & V_6 -> V_73 ) ;
for ( V_40 = 0 ; V_40 < V_6 -> V_32 ; V_40 ++ ) {
struct V_34 * V_76 ;
V_76 = F_16 ( & V_6 -> V_36 , V_40 ) ;
if ( V_76 == V_72 )
F_45 ( & V_6 -> V_36 , V_40 ) ;
}
F_46 ( & V_72 -> V_74 ) ;
F_43 ( & V_6 -> V_73 ) ;
}
static int F_47 ( struct V_5 * V_6 ,
struct V_70 * V_71 ,
const char * V_14 ,
int * V_18 ,
int V_19 )
{
struct V_9 * V_77 ;
V_77 = F_38 ( V_6 -> V_12 , sizeof( * V_77 ) , V_69 ) ;
if ( ! V_77 )
return - V_61 ;
V_77 -> V_14 = V_14 ;
V_77 -> V_71 = V_71 ;
V_77 -> V_18 = V_18 ;
V_77 -> V_19 = V_19 ;
F_40 ( & V_6 -> V_73 ) ;
F_41 ( & V_77 -> V_74 , & V_6 -> V_78 ) ;
F_42 ( & V_6 -> V_11 , V_6 -> V_7 , V_77 ) ;
V_6 -> V_7 ++ ;
F_43 ( & V_6 -> V_73 ) ;
return 0 ;
}
static int F_48 ( struct V_5 * V_6 , unsigned V_52 )
{
unsigned V_79 ;
if ( V_52 >= V_6 -> V_68 ) {
F_17 ( V_6 -> V_12 , L_11 ,
V_52 , V_6 -> V_68 ) ;
return - V_17 ;
}
V_79 = V_52 / ( V_6 -> V_24 / V_25 ) ;
return V_79 ;
}
static int F_49 ( struct V_5 * V_6 ,
struct V_70 * V_71 ,
struct V_29 * * V_30 ,
const char * * V_38 )
{
struct V_42 * V_43 ;
const T_3 * V_80 ;
int V_68 , V_81 , V_82 , * V_15 , V_79 = 0 , V_76 = 0 , V_64 = - V_61 ;
struct V_34 * V_72 ;
if ( V_6 -> V_83 ) {
V_81 = 3 ;
V_80 = F_50 ( V_71 , V_84 , & V_68 ) ;
} else {
V_81 = 2 ;
V_80 = F_50 ( V_71 , V_85 , & V_68 ) ;
}
if ( ! V_80 ) {
F_17 ( V_6 -> V_12 , L_12 , V_71 -> V_14 ) ;
return - V_17 ;
}
if ( V_68 < ( sizeof( * V_80 ) * V_81 ) ) {
F_17 ( V_6 -> V_12 , L_13 , V_71 -> V_14 ) ;
return - V_17 ;
}
V_68 /= sizeof( * V_80 ) ;
V_82 = V_68 / V_81 ;
V_43 = F_38 ( V_6 -> V_12 , sizeof( * V_43 ) * V_82 , V_69 ) ;
if ( ! V_43 )
return - V_61 ;
V_15 = F_38 ( V_6 -> V_12 , sizeof( * V_15 ) * V_82 , V_69 ) ;
if ( ! V_15 )
goto V_86;
while ( V_79 < V_68 ) {
unsigned V_52 , V_2 ;
int V_22 ;
V_52 = F_51 ( V_80 + V_79 ++ ) ;
V_2 = F_51 ( V_80 + V_79 ++ ) ;
V_43 [ V_76 ] . V_1 = V_6 -> V_27 + V_52 ;
V_43 [ V_76 ] . V_2 = V_2 ;
if ( V_81 == 3 ) {
V_2 = F_51 ( V_80 + V_79 ++ ) ;
V_43 [ V_76 ] . V_44 = V_2 ;
}
V_22 = F_48 ( V_6 , V_52 ) ;
if ( V_22 < 0 ) {
F_17 ( V_6 -> V_12 ,
L_14 ,
V_71 -> V_14 , V_52 ) ;
break;
}
V_15 [ V_76 ++ ] = V_22 ;
}
V_38 [ 0 ] = V_71 -> V_14 ;
V_72 = F_39 ( V_6 , V_71 , V_71 -> V_14 , V_43 , V_76 , V_38 , 1 ) ;
if ( ! V_72 )
goto V_87;
V_64 = F_47 ( V_6 , V_71 , V_71 -> V_14 , V_15 , V_76 ) ;
if ( V_64 < 0 )
goto V_88;
( * V_30 ) -> type = V_89 ;
( * V_30 ) -> V_90 . V_80 . V_10 = V_71 -> V_14 ;
( * V_30 ) -> V_90 . V_80 . V_72 = V_71 -> V_14 ;
return 0 ;
V_88:
F_44 ( V_6 , V_72 ) ;
V_87:
F_22 ( V_6 -> V_12 , V_15 ) ;
V_86:
F_22 ( V_6 -> V_12 , V_43 ) ;
return V_64 ;
}
static int F_52 ( struct V_3 * V_4 ,
struct V_70 * V_91 ,
struct V_29 * * V_30 , unsigned * V_31 )
{
struct V_5 * V_6 ;
const char * * V_38 ;
int V_92 ;
V_6 = F_14 ( V_4 ) ;
* V_30 = F_38 ( V_6 -> V_12 , sizeof( * * V_30 ) , V_69 ) ;
if ( ! * V_30 )
return - V_61 ;
* V_31 = 0 ;
V_38 = F_38 ( V_6 -> V_12 , sizeof( * V_38 ) , V_69 ) ;
if ( ! V_38 ) {
V_92 = - V_61 ;
goto V_93;
}
V_92 = F_49 ( V_6 , V_91 , V_30 , V_38 ) ;
if ( V_92 < 0 ) {
F_17 ( V_6 -> V_12 , L_15 ,
V_91 -> V_14 ) ;
goto V_94;
}
* V_31 = 1 ;
return 0 ;
V_94:
F_22 ( V_6 -> V_12 , V_38 ) ;
V_93:
F_22 ( V_6 -> V_12 , * V_30 ) ;
return V_92 ;
}
static void F_53 ( struct V_5 * V_6 )
{
struct V_95 * V_96 , * V_97 ;
int V_40 ;
F_40 ( & V_6 -> V_73 ) ;
for ( V_40 = 0 ; V_40 < V_6 -> V_32 ; V_40 ++ ) {
struct V_34 * V_35 ;
V_35 = F_16 ( & V_6 -> V_36 , V_40 ) ;
if ( ! V_35 )
continue;
F_45 ( & V_6 -> V_36 , V_40 ) ;
}
F_54 (pos, tmp, &pcs->functions) {
struct V_34 * V_72 ;
V_72 = F_55 ( V_96 , struct V_34 , V_74 ) ;
F_46 ( & V_72 -> V_74 ) ;
}
F_43 ( & V_6 -> V_73 ) ;
}
static void F_56 ( struct V_5 * V_6 )
{
struct V_95 * V_96 , * V_97 ;
int V_40 ;
F_40 ( & V_6 -> V_73 ) ;
for ( V_40 = 0 ; V_40 < V_6 -> V_7 ; V_40 ++ ) {
struct V_9 * V_77 ;
V_77 = F_16 ( & V_6 -> V_11 , V_40 ) ;
if ( ! V_77 )
continue;
F_45 ( & V_6 -> V_11 , V_40 ) ;
}
F_54 (pos, tmp, &pcs->pingroups) {
struct V_9 * V_77 ;
V_77 = F_55 ( V_96 , struct V_9 , V_74 ) ;
F_46 ( & V_77 -> V_74 ) ;
}
F_43 ( & V_6 -> V_73 ) ;
}
static void F_57 ( struct V_5 * V_6 )
{
if ( V_6 -> V_98 )
F_58 ( V_6 -> V_98 ) ;
F_53 ( V_6 ) ;
F_56 ( V_6 ) ;
}
static int F_59 ( struct V_99 * V_100 )
{
struct V_70 * V_71 = V_100 -> V_12 . V_101 ;
const struct V_102 * V_103 ;
struct V_104 * V_64 ;
struct V_5 * V_6 ;
int V_92 ;
V_103 = F_60 ( V_105 , & V_100 -> V_12 ) ;
if ( ! V_103 )
return - V_17 ;
V_6 = F_38 ( & V_100 -> V_12 , sizeof( * V_6 ) , V_69 ) ;
if ( ! V_6 ) {
F_17 ( & V_100 -> V_12 , L_16 ) ;
return - V_61 ;
}
V_6 -> V_12 = & V_100 -> V_12 ;
F_61 ( & V_6 -> V_73 ) ;
F_62 ( & V_6 -> V_78 ) ;
F_62 ( & V_6 -> V_75 ) ;
F_63 ( L_17 , & V_6 -> V_24 ,
L_18 ) ;
F_63 ( L_19 , & V_6 -> V_45 ,
L_20 ) ;
V_6 -> V_49 = F_64 ( V_6 -> V_45 ) - 1 ;
V_6 -> V_106 = V_6 -> V_45 >> V_6 -> V_49 ;
V_92 = F_65 ( V_71 , L_21 ,
& V_6 -> V_47 ) ;
if ( V_92 )
V_6 -> V_47 = V_48 ;
V_6 -> V_83 = F_66 ( V_71 ,
L_22 ) ;
V_64 = F_67 ( V_100 , V_107 , 0 ) ;
if ( ! V_64 ) {
F_17 ( V_6 -> V_12 , L_23 ) ;
return - V_108 ;
}
V_6 -> V_64 = F_68 ( V_6 -> V_12 , V_64 -> V_65 ,
F_69 ( V_64 ) , V_28 ) ;
if ( ! V_6 -> V_64 ) {
F_17 ( V_6 -> V_12 , L_24 ) ;
return - V_109 ;
}
V_6 -> V_68 = F_69 ( V_6 -> V_64 ) ;
V_6 -> V_27 = F_70 ( V_6 -> V_12 , V_6 -> V_64 -> V_65 , V_6 -> V_68 ) ;
if ( ! V_6 -> V_27 ) {
F_17 ( V_6 -> V_12 , L_25 ) ;
return - V_108 ;
}
F_71 ( & V_6 -> V_11 , V_69 ) ;
F_71 ( & V_6 -> V_36 , V_69 ) ;
F_72 ( V_100 , V_6 ) ;
switch ( V_6 -> V_24 ) {
case 8 :
V_6 -> V_26 = F_1 ;
V_6 -> V_46 = F_7 ;
break;
case 16 :
V_6 -> V_26 = F_3 ;
V_6 -> V_46 = F_9 ;
break;
case 32 :
V_6 -> V_26 = F_5 ;
V_6 -> V_46 = F_11 ;
break;
default:
break;
}
V_6 -> V_60 . V_14 = V_28 ;
V_6 -> V_60 . V_110 = & V_111 ;
V_6 -> V_60 . V_112 = & V_113 ;
V_6 -> V_60 . V_114 = & V_115 ;
V_6 -> V_60 . V_116 = V_117 ;
V_92 = F_37 ( V_6 ) ;
if ( V_92 < 0 )
goto free;
V_6 -> V_98 = F_73 ( & V_6 -> V_60 , V_6 -> V_12 , V_6 ) ;
if ( ! V_6 -> V_98 ) {
F_17 ( V_6 -> V_12 , L_26 ) ;
V_92 = - V_17 ;
goto free;
}
F_74 ( V_6 -> V_12 , L_27 ,
V_6 -> V_60 . V_16 , V_6 -> V_27 , V_6 -> V_68 ) ;
return 0 ;
free:
F_57 ( V_6 ) ;
return V_92 ;
}
static int F_75 ( struct V_99 * V_100 )
{
struct V_5 * V_6 = F_76 ( V_100 ) ;
if ( ! V_6 )
return 0 ;
F_57 ( V_6 ) ;
return 0 ;
}
