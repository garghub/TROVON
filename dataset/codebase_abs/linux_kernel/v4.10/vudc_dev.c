static void F_1 ( struct V_1 * V_1 )
{
if ( ! V_1 )
return;
F_2 ( V_1 -> V_2 ) ;
V_1 -> V_2 = NULL ;
F_2 ( V_1 -> V_3 ) ;
V_1 -> V_3 = NULL ;
F_3 ( V_1 ) ;
}
struct V_4 * F_4 ( void )
{
struct V_4 * V_5 ;
V_5 = F_5 ( sizeof( * V_5 ) , V_6 ) ;
if ( ! V_5 )
return V_5 ;
V_5 -> V_1 = NULL ;
V_5 -> V_7 = NULL ;
F_6 ( & V_5 -> V_8 ) ;
return V_5 ;
}
static void F_7 ( struct V_4 * V_5 )
{
F_2 ( V_5 ) ;
}
void F_8 ( struct V_4 * V_5 )
{
if ( ! V_5 )
return;
F_1 ( V_5 -> V_1 ) ;
F_7 ( V_5 ) ;
}
static void F_9 ( struct V_9 * V_10 , struct V_11 * V_7 )
{
struct V_12 * V_13 ;
while ( ! F_10 ( & V_7 -> V_14 ) ) {
V_13 = F_11 ( & V_7 -> V_14 , struct V_12 ,
V_15 ) ;
F_12 ( & V_13 -> V_15 ) ;
V_13 -> V_13 . V_16 = - V_17 ;
F_13 ( & V_10 -> V_18 ) ;
F_14 ( & V_7 -> V_7 , & V_13 -> V_13 ) ;
F_15 ( & V_10 -> V_18 ) ;
}
}
static void F_16 ( struct V_9 * V_10 )
{
int V_19 ;
struct V_4 * V_5 , * V_20 ;
V_10 -> V_21 = 0 ;
for ( V_19 = 0 ; V_19 < V_22 ; V_19 ++ )
F_9 ( V_10 , & V_10 -> V_7 [ V_19 ] ) ;
F_17 (urb_p, tmp, &udc->urb_queue, urb_entry) {
F_18 ( & V_5 -> V_8 ) ;
F_8 ( V_5 ) ;
}
}
struct V_11 * F_19 ( struct V_9 * V_10 , T_1 V_21 )
{
int V_19 ;
if ( ( V_21 & ~ V_23 ) == 0 )
return & V_10 -> V_7 [ 0 ] ;
for ( V_19 = 1 ; V_19 < V_22 ; V_19 ++ ) {
struct V_11 * V_7 = & V_10 -> V_7 [ V_19 ] ;
if ( ! V_7 -> V_24 )
continue;
if ( V_7 -> V_24 -> V_25 == V_21 )
return V_7 ;
}
return NULL ;
}
static int F_20 ( struct V_26 * V_27 )
{
struct V_28 V_29 ;
struct V_9 * V_10 = F_21 ( V_27 ) ;
F_22 ( & V_29 ) ;
return ( ( V_29 . V_30 - V_10 -> V_31 . V_30 ) * 1000 +
( V_29 . V_32 - V_10 -> V_31 . V_32 ) / 1000 )
% 0x7FF ;
}
static int F_23 ( struct V_26 * V_27 , int V_33 )
{
struct V_9 * V_10 = F_21 ( V_27 ) ;
if ( V_33 )
V_10 -> V_34 |= ( 1 << V_35 ) ;
else
V_10 -> V_34 &= ~ ( 1 << V_35 ) ;
return 0 ;
}
static int F_24 ( struct V_26 * V_27 , int V_33 )
{
struct V_9 * V_10 = F_21 ( V_27 ) ;
unsigned long V_36 ;
int V_37 ;
F_25 ( & V_10 -> V_18 , V_36 ) ;
V_33 = ! ! V_33 ;
if ( V_33 == V_10 -> V_38 )
goto V_39;
V_10 -> V_38 = V_33 ;
if ( V_33 ) {
V_10 -> V_40 . V_41 = F_26 ( T_1 , V_42 ,
V_10 -> V_43 -> V_44 ) ;
V_10 -> V_7 [ 0 ] . V_7 . V_45 = 64 ;
V_37 = F_27 ( V_10 ) ;
if ( V_37 ) {
F_28 ( & V_10 -> V_40 . V_46 , L_1 , V_37 ) ;
goto V_39;
}
F_29 ( & V_10 -> V_18 , V_36 ) ;
F_30 ( & V_10 -> V_47 ) ;
} else {
V_10 -> V_48 = 0 ;
F_29 ( & V_10 -> V_18 , V_36 ) ;
F_31 ( & V_10 -> V_47 , V_49 ) ;
F_32 ( & V_10 -> V_47 ) ;
}
return 0 ;
V_39:
F_29 ( & V_10 -> V_18 , V_36 ) ;
return 0 ;
}
static int F_33 ( struct V_26 * V_50 ,
struct V_51 * V_43 )
{
struct V_9 * V_10 = F_21 ( V_50 ) ;
unsigned long V_36 ;
F_25 ( & V_10 -> V_18 , V_36 ) ;
V_10 -> V_43 = V_43 ;
V_10 -> V_38 = V_10 -> V_52 = V_10 -> V_48 = 0 ;
F_29 ( & V_10 -> V_18 , V_36 ) ;
return 0 ;
}
static int F_34 ( struct V_26 * V_50 )
{
struct V_9 * V_10 = F_21 ( V_50 ) ;
unsigned long V_36 ;
F_25 ( & V_10 -> V_18 , V_36 ) ;
V_10 -> V_43 = NULL ;
F_29 ( & V_10 -> V_18 , V_36 ) ;
return 0 ;
}
static int F_35 ( struct V_53 * V_54 ,
const struct V_55 * V_24 )
{
struct V_11 * V_7 ;
struct V_9 * V_10 ;
unsigned int V_56 ;
unsigned long V_36 ;
V_7 = F_36 ( V_54 ) ;
V_10 = F_37 ( V_7 ) ;
if ( ! V_54 || ! V_24 || V_7 -> V_24 || V_54 -> V_57 . V_58
|| V_24 -> V_59 != V_60 )
return - V_61 ;
if ( ! V_10 -> V_43 )
return - V_17 ;
F_25 ( & V_10 -> V_18 , V_36 ) ;
V_56 = F_38 ( V_24 ) ;
V_54 -> V_45 = V_56 ;
V_7 -> V_24 = V_24 ;
V_7 -> type = F_39 ( V_24 ) ;
V_7 -> V_62 = V_7 -> V_63 = 0 ;
F_29 ( & V_10 -> V_18 , V_36 ) ;
return 0 ;
}
static int F_40 ( struct V_53 * V_54 )
{
struct V_11 * V_7 ;
struct V_9 * V_10 ;
unsigned long V_36 ;
V_7 = F_36 ( V_54 ) ;
V_10 = F_37 ( V_7 ) ;
if ( ! V_54 || ! V_7 -> V_24 || V_54 -> V_57 . V_58 )
return - V_61 ;
F_25 ( & V_10 -> V_18 , V_36 ) ;
V_7 -> V_24 = NULL ;
F_9 ( V_10 , V_7 ) ;
F_29 ( & V_10 -> V_18 , V_36 ) ;
return 0 ;
}
static struct V_64 * F_41 ( struct V_53 * V_54 ,
T_2 V_65 )
{
struct V_11 * V_7 ;
struct V_12 * V_13 ;
if ( ! V_54 )
return NULL ;
V_7 = F_36 ( V_54 ) ;
V_13 = F_5 ( sizeof( * V_13 ) , V_65 ) ;
if ( ! V_13 )
return NULL ;
F_6 ( & V_13 -> V_15 ) ;
return & V_13 -> V_13 ;
}
static void F_42 ( struct V_53 * V_54 , struct V_64 * V_66 )
{
struct V_12 * V_13 ;
if ( F_43 ( ! V_54 || ! V_66 ) )
return;
V_13 = F_44 ( V_66 ) ;
F_2 ( V_13 ) ;
}
static int F_45 ( struct V_53 * V_54 , struct V_64 * V_66 ,
T_2 V_65 )
{
struct V_11 * V_7 ;
struct V_12 * V_13 ;
struct V_9 * V_10 ;
unsigned long V_36 ;
if ( ! V_54 || ! V_66 )
return - V_61 ;
V_7 = F_36 ( V_54 ) ;
V_13 = F_44 ( V_66 ) ;
V_10 = F_37 ( V_7 ) ;
F_25 ( & V_10 -> V_18 , V_36 ) ;
V_66 -> V_67 = 0 ;
V_66 -> V_16 = - V_68 ;
F_46 ( & V_13 -> V_15 , & V_7 -> V_14 ) ;
F_29 ( & V_10 -> V_18 , V_36 ) ;
return 0 ;
}
static int F_47 ( struct V_53 * V_54 , struct V_64 * V_66 )
{
struct V_11 * V_7 ;
struct V_12 * V_13 ;
struct V_9 * V_10 ;
struct V_12 * V_69 ;
unsigned long V_36 ;
int V_37 = - V_61 ;
if ( ! V_54 || ! V_66 )
return V_37 ;
V_7 = F_36 ( V_54 ) ;
V_13 = F_44 ( V_66 ) ;
V_10 = V_13 -> V_10 ;
if ( ! V_10 -> V_43 )
return - V_17 ;
F_25 ( & V_10 -> V_18 , V_36 ) ;
F_48 (lst, &ep->req_queue, req_entry) {
if ( & V_69 -> V_13 == V_66 ) {
F_12 ( & V_69 -> V_15 ) ;
V_66 -> V_16 = - V_70 ;
V_37 = 0 ;
break;
}
}
F_29 ( & V_10 -> V_18 , V_36 ) ;
if ( V_37 == 0 )
F_14 ( V_54 , V_66 ) ;
return V_37 ;
}
static int
F_49 ( struct V_53 * V_54 , int V_33 , int V_63 )
{
struct V_11 * V_7 ;
struct V_9 * V_10 ;
unsigned long V_36 ;
int V_37 = 0 ;
V_7 = F_36 ( V_54 ) ;
if ( ! V_54 )
return - V_61 ;
V_10 = F_37 ( V_7 ) ;
if ( ! V_10 -> V_43 )
return - V_17 ;
F_25 ( & V_10 -> V_18 , V_36 ) ;
if ( ! V_33 )
V_7 -> V_62 = V_7 -> V_63 = 0 ;
else if ( V_7 -> V_24 && ( V_7 -> V_24 -> V_25 & V_23 ) &&
! F_10 ( & V_7 -> V_14 ) )
V_37 = - V_71 ;
else {
V_7 -> V_62 = 1 ;
if ( V_63 )
V_7 -> V_63 = 1 ;
}
F_29 ( & V_10 -> V_18 , V_36 ) ;
return V_37 ;
}
static int
F_50 ( struct V_53 * V_54 , int V_33 )
{
return F_49 ( V_54 , V_33 , 0 ) ;
}
static int F_51 ( struct V_53 * V_54 )
{
return F_49 ( V_54 , 1 , 1 ) ;
}
static void F_52 ( struct V_72 * V_47 )
{
struct V_9 * V_10 = F_53 ( V_47 , struct V_9 , V_47 ) ;
int V_73 = 0 ;
unsigned long V_36 ;
F_54 ( & V_10 -> V_74 -> V_46 , L_2 ) ;
if ( V_47 -> V_75 )
F_55 ( V_47 -> V_75 , V_76 ) ;
if ( V_47 -> V_77 ) {
F_56 ( V_47 -> V_77 ) ;
V_47 -> V_77 = NULL ;
}
if ( V_47 -> V_78 ) {
F_56 ( V_47 -> V_78 ) ;
V_47 -> V_78 = NULL ;
}
if ( V_47 -> V_75 ) {
F_57 ( V_47 -> V_75 ) ;
V_47 -> V_75 = NULL ;
}
F_25 ( & V_10 -> V_18 , V_36 ) ;
F_16 ( V_10 ) ;
if ( V_10 -> V_52 && V_10 -> V_43 -> V_79 )
V_73 = 1 ;
V_10 -> V_52 = 0 ;
F_29 ( & V_10 -> V_18 , V_36 ) ;
if ( V_73 )
V_10 -> V_43 -> V_79 ( & V_10 -> V_40 ) ;
}
static void F_58 ( struct V_72 * V_47 )
{
struct V_9 * V_10 = F_53 ( V_47 , struct V_9 , V_47 ) ;
unsigned long V_36 ;
F_54 ( & V_10 -> V_74 -> V_46 , L_3 ) ;
F_25 ( & V_10 -> V_18 , V_36 ) ;
F_16 ( V_10 ) ;
F_29 ( & V_10 -> V_18 , V_36 ) ;
if ( V_10 -> V_43 )
F_59 ( & V_10 -> V_40 , V_10 -> V_43 ) ;
F_25 ( & V_47 -> V_18 , V_36 ) ;
V_47 -> V_16 = V_80 ;
F_29 ( & V_47 -> V_18 , V_36 ) ;
}
static void F_60 ( struct V_72 * V_47 )
{
unsigned long V_36 ;
F_25 ( & V_47 -> V_18 , V_36 ) ;
V_47 -> V_16 = V_81 ;
F_29 ( & V_47 -> V_18 , V_36 ) ;
}
struct V_82 * F_61 ( int V_83 )
{
struct V_82 * V_84 = NULL ;
V_84 = F_5 ( sizeof( * V_84 ) , V_6 ) ;
if ( ! V_84 )
goto V_85;
F_6 ( & V_84 -> V_86 ) ;
V_84 -> V_74 = F_62 ( V_87 , V_83 ) ;
if ( ! V_84 -> V_74 ) {
F_2 ( V_84 ) ;
V_84 = NULL ;
}
V_85:
return V_84 ;
}
void F_63 ( struct V_82 * V_84 )
{
F_64 ( V_84 -> V_74 ) ;
F_2 ( V_84 ) ;
}
static int F_65 ( struct V_9 * V_10 )
{
int V_19 ;
struct V_72 * V_47 = & V_10 -> V_47 ;
struct V_11 * V_7 ;
V_10 -> V_7 = F_66 ( V_22 , sizeof( * V_10 -> V_7 ) , V_6 ) ;
if ( ! V_10 -> V_7 )
goto V_88;
F_6 ( & V_10 -> V_40 . V_89 ) ;
for ( V_19 = 0 ; V_19 < V_22 ; ++ V_19 ) {
int V_90 = V_19 % 2 ;
int V_91 = ( V_19 + 1 ) / 2 ;
V_7 = & V_10 -> V_7 [ V_19 ] ;
sprintf ( V_7 -> V_92 , L_4 , V_91 ,
V_19 ? ( V_90 ? L_5 : L_6 ) : L_7 ) ;
V_7 -> V_7 . V_92 = V_7 -> V_92 ;
V_7 -> V_7 . V_93 = & V_94 ;
F_67 ( & V_7 -> V_7 , ~ 0 ) ;
V_7 -> V_7 . V_95 = 16 ;
V_7 -> V_40 = & V_10 -> V_40 ;
F_6 ( & V_7 -> V_14 ) ;
if ( V_19 == 0 ) {
V_7 -> V_7 . V_57 . V_58 = true ;
V_7 -> V_7 . V_57 . V_96 = true ;
V_7 -> V_7 . V_57 . V_97 = true ;
V_10 -> V_40 . V_98 = & V_7 -> V_7 ;
} else {
V_7 -> V_7 . V_57 . V_99 = true ;
V_7 -> V_7 . V_57 . V_100 = true ;
V_7 -> V_7 . V_57 . V_101 = true ;
if ( V_90 )
V_7 -> V_7 . V_57 . V_96 = true ;
else
V_7 -> V_7 . V_57 . V_97 = true ;
F_46 ( & V_7 -> V_7 . V_89 , & V_10 -> V_40 . V_89 ) ;
}
}
F_68 ( & V_10 -> V_18 ) ;
F_68 ( & V_10 -> V_102 ) ;
F_6 ( & V_10 -> V_103 ) ;
F_6 ( & V_10 -> V_104 ) ;
F_69 ( & V_10 -> V_105 ) ;
F_68 ( & V_47 -> V_18 ) ;
V_47 -> V_16 = V_80 ;
V_47 -> V_106 = V_107 ;
V_47 -> V_108 . V_109 = F_52 ;
V_47 -> V_108 . V_110 = F_58 ;
V_47 -> V_108 . V_111 = F_60 ;
F_70 ( V_10 ) ;
return 0 ;
V_88:
return - V_112 ;
}
static void F_71 ( struct V_9 * V_10 )
{
F_2 ( V_10 -> V_7 ) ;
}
int F_72 ( struct V_113 * V_74 )
{
struct V_9 * V_10 ;
int V_37 = - V_112 ;
V_10 = F_5 ( sizeof( * V_10 ) , V_6 ) ;
if ( ! V_10 )
goto V_85;
V_10 -> V_40 . V_92 = V_87 ;
V_10 -> V_40 . V_93 = & V_114 ;
V_10 -> V_40 . V_44 = V_42 ;
V_10 -> V_40 . V_46 . V_115 = & V_74 -> V_46 ;
V_10 -> V_74 = V_74 ;
V_37 = F_65 ( V_10 ) ;
if ( V_37 )
goto V_116;
V_37 = F_73 ( & V_74 -> V_46 , & V_10 -> V_40 ) ;
if ( V_37 < 0 )
goto V_117;
V_37 = F_74 ( & V_74 -> V_46 . V_118 , & V_119 ) ;
if ( V_37 ) {
F_28 ( & V_10 -> V_74 -> V_46 , L_8 ) ;
goto V_120;
}
F_75 ( V_74 , V_10 ) ;
return V_37 ;
V_120:
F_76 ( & V_10 -> V_40 ) ;
V_117:
F_71 ( V_10 ) ;
V_116:
F_2 ( V_10 ) ;
V_85:
return V_37 ;
}
int F_77 ( struct V_113 * V_74 )
{
struct V_9 * V_10 = F_78 ( V_74 ) ;
F_79 ( & V_74 -> V_46 . V_118 , & V_119 ) ;
F_76 ( & V_10 -> V_40 ) ;
F_71 ( V_10 ) ;
F_2 ( V_10 ) ;
return 0 ;
}
