static void F_1 ( struct V_1 * V_2 )
{
unsigned int V_3 ;
T_1 V_4 ;
V_3 = V_2 -> V_5 -> V_6 + V_7 ;
V_4 = F_2 ( V_2 -> V_8 + V_3 ) ;
F_3 ( V_4 | V_9 , V_2 -> V_8 + V_3 ) ;
V_3 = V_2 -> V_5 -> V_6 + V_10 ;
V_4 = F_2 ( V_2 -> V_8 + V_3 ) ;
F_3 ( V_4 | V_11 , V_2 -> V_8 + V_3 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
unsigned int V_3 ;
T_1 V_12 ;
V_3 = V_2 -> V_5 -> V_6 + V_13 ;
V_12 = F_2 ( V_2 -> V_8 + V_3 ) ;
V_12 |= V_14 | V_15 ;
F_3 ( V_12 , V_2 -> V_8 + V_3 ) ;
}
static int F_5 ( struct V_16 * V_17 , void * V_18 )
{
struct V_19 V_20 ;
return ! F_6 ( V_17 , & V_20 ) ;
}
static inline void F_7 ( void )
{
V_21 = F_8 ( L_1 , - 1 , NULL , 0 ) ;
}
static int F_9 ( struct V_22 * V_23 ,
struct V_1 * V_2 )
{
const struct V_24 * V_5 = V_2 -> V_5 ;
struct V_25 * V_26 = V_5 -> V_26 ;
const char * V_27 = F_10 ( & V_23 -> V_28 ) ;
struct V_29 * V_29 = F_11 ( - V_30 ) ;
struct V_31 * V_32 ;
const char * V_33 , * V_34 ;
void T_2 * V_35 ;
if ( ! V_21 )
F_7 () ;
V_32 = F_12 ( V_21 ) ;
if ( ! V_32 )
return - V_30 ;
if ( V_5 -> V_36 ) {
F_13 ( V_32 -> V_29 , V_5 -> V_36 ,
V_27 ) ;
return 0 ;
}
if ( ! V_2 -> V_8
|| V_2 -> V_37 < V_5 -> V_6 + V_38 )
return - V_39 ;
V_33 = V_32 -> V_40 ;
V_35 = V_2 -> V_8 + V_5 -> V_6 ;
if ( V_26 ) {
V_29 = V_26 -> V_29 ;
if ( ! V_29 ) {
V_29 = F_14 ( NULL , V_26 -> V_40 ,
L_2 , 0 ,
V_26 -> V_41 ) ;
V_26 -> V_29 = V_29 ;
}
V_33 = V_26 -> V_40 ;
}
if ( V_5 -> V_42 ) {
V_29 = F_15 ( NULL , V_27 , V_33 , 0 ,
V_35 , 0 , 0 , NULL ) ;
V_33 = V_27 ;
}
if ( V_5 -> V_43 ) {
if ( ! F_2 ( V_35 ) )
F_3 ( V_44 , V_35 ) ;
V_34 = F_16 ( V_45 , L_3 , V_27 ) ;
if ( ! V_34 )
return - V_46 ;
V_29 = F_17 ( NULL , V_34 , V_33 ,
0 , V_35 ,
1 , 15 , 16 , 15 , 0 , NULL ) ;
V_33 = V_34 ;
V_34 = F_16 ( V_45 , L_4 , V_27 ) ;
if ( ! V_34 ) {
F_18 ( V_33 ) ;
return - V_46 ;
}
V_29 = F_15 ( NULL , V_34 , V_33 ,
V_47 | V_48 ,
V_35 , 31 , 0 , NULL ) ;
F_18 ( V_33 ) ;
F_18 ( V_34 ) ;
}
if ( F_19 ( V_29 ) )
return F_20 ( V_29 ) ;
V_2 -> V_29 = V_29 ;
F_13 ( V_29 , NULL , V_27 ) ;
return 0 ;
}
static int F_21 ( struct V_22 * V_23 ,
const struct V_49 * V_50 )
{
struct V_24 * V_5 ;
struct V_1 * V_2 ;
struct V_51 * V_52 ;
struct V_53 V_54 ;
struct V_55 * V_56 ;
int V_57 ;
V_5 = (struct V_24 * ) V_50 -> V_58 ;
if ( ! V_5 ) {
V_56 = F_22 ( V_23 ) ;
return F_23 ( V_56 ) ? F_20 ( V_56 ) : 1 ;
}
V_2 = F_24 ( sizeof( * V_2 ) , V_45 ) ;
if ( ! V_2 )
return - V_46 ;
F_25 ( & V_54 ) ;
V_57 = F_26 ( V_23 , & V_54 , F_5 , NULL ) ;
if ( V_57 < 0 )
goto V_59;
F_27 (rentry, &resource_list, node)
if ( F_28 ( & V_52 -> V_17 ) == V_60 ) {
if ( V_5 -> V_61 )
V_2 -> V_37 = V_5 -> V_61 ;
else
V_2 -> V_37 = F_29 ( & V_52 -> V_17 ) ;
V_2 -> V_8 = F_30 ( V_52 -> V_17 . V_62 ,
V_2 -> V_37 ) ;
break;
}
F_31 ( & V_54 ) ;
V_2 -> V_5 = V_5 ;
if ( V_5 -> V_63 ) {
V_57 = F_9 ( V_23 , V_2 ) ;
if ( V_57 ) {
V_57 = 0 ;
goto V_59;
}
}
V_57 = F_32 ( V_23 ) ;
if ( V_57 ) {
V_57 = 0 ;
goto V_59;
}
if ( V_5 -> V_64 )
V_5 -> V_64 ( V_2 ) ;
V_23 -> V_58 = V_2 ;
V_56 = F_22 ( V_23 ) ;
if ( ! F_23 ( V_56 ) ) {
return 1 ;
}
V_57 = F_20 ( V_56 ) ;
V_23 -> V_58 = NULL ;
V_59:
F_18 ( V_2 ) ;
return V_57 ;
}
static T_1 F_33 ( struct V_1 * V_2 , unsigned int V_4 )
{
return F_2 ( V_2 -> V_8 + V_2 -> V_5 -> V_6 + V_4 ) ;
}
static void F_34 ( T_1 V_12 , struct V_1 * V_2 ,
unsigned int V_4 )
{
F_3 ( V_12 , V_2 -> V_8 + V_2 -> V_5 -> V_6 + V_4 ) ;
}
static int F_35 ( struct V_65 * V_28 , unsigned int V_4 , T_1 * V_12 )
{
struct V_22 * V_23 ;
struct V_1 * V_2 ;
unsigned long V_66 ;
int V_57 ;
V_57 = F_36 ( F_37 ( V_28 ) , & V_23 ) ;
if ( F_38 ( V_57 ) )
return V_57 ;
F_39 ( & V_28 -> V_67 . V_68 , V_66 ) ;
if ( F_40 ( V_28 ) ) {
V_57 = - V_69 ;
goto V_70;
}
V_2 = F_41 ( V_23 ) ;
if ( F_38 ( ! V_2 || ! V_2 -> V_8 ) ) {
V_57 = - V_30 ;
goto V_70;
}
* V_12 = F_33 ( V_2 , V_4 ) ;
V_70:
F_42 ( & V_28 -> V_67 . V_68 , V_66 ) ;
return V_57 ;
}
static T_3 F_43 ( struct V_65 * V_28 , struct V_71 * V_72 ,
char * V_73 )
{
T_1 V_74 = 0 ;
unsigned int V_4 ;
int V_57 ;
V_4 = strcmp ( V_72 -> V_72 . V_40 , L_5 ) ? V_75 : V_76 ;
V_57 = F_35 ( V_28 , V_4 , & V_74 ) ;
if ( V_57 )
return V_57 ;
return snprintf ( V_73 , V_77 , L_6 , V_74 ) ;
}
static T_3 F_44 ( struct V_65 * V_28 ,
struct V_71 * V_72 , char * V_73 )
{
T_1 V_78 = 0 ;
char * V_79 ;
int V_57 ;
V_57 = F_35 ( V_28 , V_10 , & V_78 ) ;
if ( V_57 )
return V_57 ;
V_79 = ( V_78 & V_80 ) ? L_7 : L_8 ;
return sprintf ( V_73 , L_9 , V_79 ) ;
}
static void F_45 ( struct V_65 * V_28 , T_4 V_12 )
{
struct V_1 * V_2 = F_41 ( F_46 ( V_28 ) ) ;
T_1 V_78 , V_81 ;
V_78 = F_33 ( V_2 , V_10 ) ;
if ( V_12 < 0 ) {
if ( V_78 & V_80 ) {
V_78 &= ~ V_80 ;
F_34 ( V_78 , V_2 , V_10 ) ;
}
return;
}
V_81 = F_33 ( V_2 , V_75 ) & ~ V_82 ;
if ( V_12 >= V_83 ) {
V_81 |= V_84 ;
V_12 = V_85 ;
} else if ( V_12 > V_85 ) {
V_81 |= V_84 | V_86 ;
V_12 >>= V_87 ;
} else {
V_81 |= V_88 | V_86 ;
}
V_81 |= V_12 ;
F_34 ( V_81 , V_2 , V_75 ) ;
if ( ! ( V_78 & V_80 ) ) {
V_78 |= V_80 ;
F_34 ( V_78 , V_2 , V_10 ) ;
}
}
static void F_47 ( struct V_65 * V_28 )
{
struct V_1 * V_2 = F_41 ( F_46 ( V_28 ) ) ;
unsigned int V_89 ;
for ( V_89 = 0 ; V_89 < V_90 ; V_89 ++ ) {
unsigned long V_3 = V_89 * sizeof( T_1 ) ;
V_2 -> V_91 [ V_89 ] = F_33 ( V_2 , V_3 ) ;
F_48 ( V_28 , L_10 ,
V_2 -> V_91 [ V_89 ] , V_3 ) ;
}
}
static void F_49 ( struct V_65 * V_28 )
{
struct V_1 * V_2 = F_41 ( F_46 ( V_28 ) ) ;
unsigned int V_89 ;
F_50 ( 10 ) ;
for ( V_89 = 0 ; V_89 < V_90 ; V_89 ++ ) {
unsigned long V_3 = V_89 * sizeof( T_1 ) ;
F_34 ( V_2 -> V_91 [ V_89 ] , V_2 , V_3 ) ;
F_48 ( V_28 , L_11 ,
V_2 -> V_91 [ V_89 ] , V_3 ) ;
}
}
static int F_51 ( struct V_65 * V_28 )
{
int V_57 = F_52 ( V_28 ) ;
if ( V_57 )
return V_57 ;
F_47 ( V_28 ) ;
return F_53 ( V_28 ) ;
}
static int F_54 ( struct V_65 * V_28 )
{
int V_57 = F_55 ( V_28 ) ;
if ( V_57 )
return V_57 ;
F_49 ( V_28 ) ;
return F_56 ( V_28 ) ;
}
static int F_57 ( struct V_65 * V_28 )
{
int V_57 = F_58 ( V_28 ) ;
if ( V_57 )
return V_57 ;
F_47 ( V_28 ) ;
return F_59 ( V_28 ) ;
}
static int F_60 ( struct V_65 * V_28 )
{
int V_57 = F_61 ( V_28 ) ;
if ( V_57 )
return V_57 ;
F_49 ( V_28 ) ;
return F_62 ( V_28 ) ;
}
static int F_63 ( struct V_92 * V_93 ,
unsigned long V_94 , void * V_95 )
{
struct V_55 * V_56 = F_64 ( V_95 ) ;
struct V_1 * V_2 ;
struct V_22 * V_23 ;
const struct V_49 * V_50 ;
V_50 = F_65 ( V_96 , & V_56 -> V_28 ) ;
if ( ! V_50 || ! V_50 -> V_58 )
return 0 ;
if ( F_36 ( F_37 ( & V_56 -> V_28 ) , & V_23 ) )
return 0 ;
V_2 = F_41 ( V_23 ) ;
if ( ! V_2 || ! V_2 -> V_8 )
return 0 ;
if ( V_2 -> V_37 < V_2 -> V_5 -> V_6 + V_97 ) {
F_66 ( & V_56 -> V_28 , L_12 ) ;
return 0 ;
}
switch ( V_94 ) {
case V_98 :
if ( V_2 -> V_5 -> V_99 )
V_56 -> V_28 . V_100 = & V_101 ;
break;
case V_102 :
if ( V_2 -> V_5 -> V_99 )
V_56 -> V_28 . V_100 = NULL ;
break;
case V_103 :
if ( V_2 -> V_5 -> V_104 )
return F_67 ( & V_56 -> V_28 . V_105 ,
& V_106 ) ;
case V_107 :
if ( V_2 -> V_5 -> V_104 )
F_68 ( & V_56 -> V_28 . V_105 , & V_106 ) ;
default:
break;
}
return 0 ;
}
static void F_69 ( struct V_65 * V_28 )
{
struct V_1 * V_2 = F_41 ( F_46 ( V_28 ) ) ;
if ( ! V_2 || ! V_2 -> V_8 || ! V_2 -> V_5 -> V_104 )
return;
if ( V_2 -> V_37 >= V_2 -> V_5 -> V_6 + V_97 )
V_28 -> V_67 . V_108 = F_45 ;
else
F_66 ( V_28 , L_12 ) ;
}
static void F_70 ( struct V_65 * V_28 )
{
V_28 -> V_67 . V_108 = NULL ;
}
void T_5 F_71 ( void )
{
if ( ! F_72 () ) {
F_73 ( & V_109 , & V_110 ) ;
F_74 ( & V_111 ) ;
}
}
void T_5 F_71 ( void )
{
F_74 ( & V_111 ) ;
}
