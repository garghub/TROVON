static void F_1 ( struct V_1 * V_2 )
{
unsigned int V_3 ;
T_1 V_4 ;
V_3 = V_2 -> V_5 -> V_6 + V_7 ;
V_4 = F_2 ( V_2 -> V_8 + V_3 ) ;
F_3 ( V_4 | V_9 , V_2 -> V_8 + V_3 ) ;
V_4 = F_2 ( V_2 -> V_8 + V_10 ) ;
if ( ! ( V_4 & V_11 ) ) {
V_3 = V_2 -> V_5 -> V_6 + V_12 ;
V_4 = F_2 ( V_2 -> V_8 + V_3 ) ;
V_4 |= V_13 ;
F_3 ( V_4 , V_2 -> V_8 + V_3 ) ;
}
}
static void F_4 ( struct V_1 * V_2 )
{
unsigned int V_3 ;
T_1 V_4 ;
V_3 = V_2 -> V_5 -> V_6 + V_14 ;
V_4 = F_2 ( V_2 -> V_8 + V_3 ) ;
V_4 |= V_15 | V_16 ;
F_3 ( V_4 , V_2 -> V_8 + V_3 ) ;
if ( F_2 ( V_2 -> V_8 + V_2 -> V_5 -> V_6 ) )
V_2 -> V_17 = 133000000 ;
}
static int F_5 ( struct V_18 * V_19 , void * V_20 )
{
struct V_21 V_22 ;
return ! F_6 ( V_19 , & V_22 ) ;
}
static inline void F_7 ( void )
{
V_23 = F_8 ( L_1 , - 1 , NULL , 0 ) ;
}
static int F_9 ( struct V_24 * V_25 ,
struct V_1 * V_2 )
{
const struct V_26 * V_5 = V_2 -> V_5 ;
const char * V_27 = F_10 ( & V_25 -> V_28 ) ;
struct V_29 * V_29 = F_11 ( - V_30 ) ;
struct V_31 * V_32 ;
const char * V_33 , * V_34 ;
void T_2 * V_35 ;
if ( ! V_23 )
F_7 () ;
V_32 = F_12 ( V_23 ) ;
if ( ! V_32 )
return - V_30 ;
V_29 = V_32 -> V_29 ;
if ( ! V_2 -> V_8
|| V_2 -> V_36 < V_5 -> V_6 + V_37 )
return - V_38 ;
V_33 = V_32 -> V_39 ;
V_35 = V_2 -> V_8 + V_5 -> V_6 ;
if ( V_2 -> V_17 ) {
V_29 = F_13 ( NULL , V_27 , V_33 , 0 ,
V_2 -> V_17 ) ;
goto V_40;
}
if ( V_5 -> V_41 & V_42 ) {
V_29 = F_14 ( NULL , V_27 , V_33 , 0 ,
V_35 , 0 , 0 , NULL ) ;
V_33 = V_27 ;
}
if ( V_5 -> V_41 & V_43 ) {
if ( ! F_2 ( V_35 ) )
F_3 ( V_44 , V_35 ) ;
V_34 = F_15 ( V_45 , L_2 , V_27 ) ;
if ( ! V_34 )
return - V_46 ;
V_29 = F_16 ( NULL , V_34 , V_33 ,
0 , V_35 ,
1 , 15 , 16 , 15 , 0 , NULL ) ;
V_33 = V_34 ;
V_34 = F_15 ( V_45 , L_3 , V_27 ) ;
if ( ! V_34 ) {
F_17 ( V_33 ) ;
return - V_46 ;
}
V_29 = F_14 ( NULL , V_34 , V_33 ,
V_47 | V_48 ,
V_35 , 31 , 0 , NULL ) ;
F_17 ( V_33 ) ;
F_17 ( V_34 ) ;
}
V_40:
if ( F_18 ( V_29 ) )
return F_19 ( V_29 ) ;
V_2 -> V_29 = V_29 ;
F_20 ( V_29 , NULL , V_27 ) ;
return 0 ;
}
static int F_21 ( struct V_24 * V_25 ,
const struct V_49 * V_50 )
{
struct V_26 * V_5 ;
struct V_1 * V_2 ;
struct V_51 * V_52 ;
struct V_53 V_54 ;
struct V_55 * V_56 ;
int V_57 ;
V_5 = (struct V_26 * ) V_50 -> V_58 ;
if ( ! V_5 ) {
V_56 = F_22 ( V_25 ) ;
return F_23 ( V_56 ) ? F_19 ( V_56 ) : 1 ;
}
V_2 = F_24 ( sizeof( * V_2 ) , V_45 ) ;
if ( ! V_2 )
return - V_46 ;
F_25 ( & V_54 ) ;
V_57 = F_26 ( V_25 , & V_54 , F_5 , NULL ) ;
if ( V_57 < 0 )
goto V_59;
F_27 (rentry, &resource_list, node)
if ( F_28 ( & V_52 -> V_19 ) == V_60 ) {
if ( V_5 -> V_61 )
V_2 -> V_36 = V_5 -> V_61 ;
else
V_2 -> V_36 = F_29 ( & V_52 -> V_19 ) ;
V_2 -> V_8 = F_30 ( V_52 -> V_19 . V_62 ,
V_2 -> V_36 ) ;
break;
}
F_31 ( & V_54 ) ;
V_2 -> V_5 = V_5 ;
if ( V_5 -> V_63 )
V_5 -> V_63 ( V_2 ) ;
if ( V_5 -> V_41 & V_64 ) {
V_57 = F_9 ( V_25 , V_2 ) ;
if ( V_57 ) {
V_57 = 0 ;
goto V_59;
}
}
V_57 = F_32 ( V_25 ) ;
if ( V_57 ) {
V_57 = 0 ;
goto V_59;
}
V_25 -> V_58 = V_2 ;
V_56 = F_22 ( V_25 ) ;
if ( ! F_23 ( V_56 ) ) {
return 1 ;
}
V_57 = F_19 ( V_56 ) ;
V_25 -> V_58 = NULL ;
V_59:
F_17 ( V_2 ) ;
return V_57 ;
}
static T_1 F_33 ( struct V_1 * V_2 , unsigned int V_65 )
{
return F_2 ( V_2 -> V_8 + V_2 -> V_5 -> V_6 + V_65 ) ;
}
static void F_34 ( T_1 V_4 , struct V_1 * V_2 ,
unsigned int V_65 )
{
F_3 ( V_4 , V_2 -> V_8 + V_2 -> V_5 -> V_6 + V_65 ) ;
}
static int F_35 ( struct V_66 * V_28 , unsigned int V_65 , T_1 * V_4 )
{
struct V_24 * V_25 ;
struct V_1 * V_2 ;
unsigned long V_41 ;
int V_57 ;
V_57 = F_36 ( F_37 ( V_28 ) , & V_25 ) ;
if ( F_38 ( V_57 ) )
return V_57 ;
F_39 ( & V_28 -> V_67 . V_68 , V_41 ) ;
if ( F_40 ( V_28 ) ) {
V_57 = - V_69 ;
goto V_40;
}
V_2 = F_41 ( V_25 ) ;
if ( F_38 ( ! V_2 || ! V_2 -> V_8 ) ) {
V_57 = - V_30 ;
goto V_40;
}
* V_4 = F_33 ( V_2 , V_65 ) ;
V_40:
F_42 ( & V_28 -> V_67 . V_68 , V_41 ) ;
return V_57 ;
}
static T_3 F_43 ( struct V_66 * V_28 , struct V_70 * V_71 ,
char * V_72 )
{
T_1 V_73 = 0 ;
unsigned int V_65 ;
int V_57 ;
V_65 = strcmp ( V_71 -> V_71 . V_39 , L_4 ) ? V_74 : V_75 ;
V_57 = F_35 ( V_28 , V_65 , & V_73 ) ;
if ( V_57 )
return V_57 ;
return snprintf ( V_72 , V_76 , L_5 , V_73 ) ;
}
static T_3 F_44 ( struct V_66 * V_28 ,
struct V_70 * V_71 , char * V_72 )
{
T_1 V_77 = 0 ;
char * V_78 ;
int V_57 ;
V_57 = F_35 ( V_28 , V_12 , & V_77 ) ;
if ( V_57 )
return V_57 ;
V_78 = ( V_77 & V_79 ) ? L_6 : L_7 ;
return sprintf ( V_72 , L_8 , V_78 ) ;
}
static void F_45 ( struct V_66 * V_28 , T_4 V_4 )
{
struct V_1 * V_2 = F_41 ( F_46 ( V_28 ) ) ;
T_1 V_77 , V_80 ;
V_77 = F_33 ( V_2 , V_12 ) ;
if ( V_4 < 0 ) {
if ( V_77 & V_79 ) {
V_77 &= ~ V_79 ;
F_34 ( V_77 , V_2 , V_12 ) ;
}
return;
}
V_80 = F_33 ( V_2 , V_74 ) & ~ V_81 ;
if ( V_4 >= V_82 ) {
V_80 |= V_83 ;
V_4 = V_84 ;
} else if ( V_4 > V_84 ) {
V_80 |= V_83 | V_85 ;
V_4 >>= V_86 ;
} else {
V_80 |= V_87 | V_85 ;
}
V_80 |= V_4 ;
F_34 ( V_80 , V_2 , V_74 ) ;
if ( ! ( V_77 & V_79 ) ) {
V_77 |= V_79 ;
F_34 ( V_77 , V_2 , V_12 ) ;
}
}
static void F_47 ( struct V_66 * V_28 ,
struct V_1 * V_2 )
{
unsigned int V_88 ;
for ( V_88 = 0 ; V_88 < V_89 ; V_88 ++ ) {
unsigned long V_3 = V_88 * sizeof( T_1 ) ;
V_2 -> V_90 [ V_88 ] = F_33 ( V_2 , V_3 ) ;
F_48 ( V_28 , L_9 ,
V_2 -> V_90 [ V_88 ] , V_3 ) ;
}
}
static void F_49 ( struct V_66 * V_28 ,
struct V_1 * V_2 )
{
unsigned int V_88 ;
F_50 ( 10 ) ;
for ( V_88 = 0 ; V_88 < V_89 ; V_88 ++ ) {
unsigned long V_3 = V_88 * sizeof( T_1 ) ;
F_34 ( V_2 -> V_90 [ V_88 ] , V_2 , V_3 ) ;
F_48 ( V_28 , L_10 ,
V_2 -> V_90 [ V_88 ] , V_3 ) ;
}
}
static int F_51 ( struct V_66 * V_28 )
{
struct V_1 * V_2 = F_41 ( F_46 ( V_28 ) ) ;
int V_57 ;
V_57 = F_52 ( V_28 ) ;
if ( V_57 )
return V_57 ;
if ( V_2 -> V_5 -> V_41 & V_91 )
F_47 ( V_28 , V_2 ) ;
return F_53 ( V_28 ) ;
}
static int F_54 ( struct V_66 * V_28 )
{
struct V_1 * V_2 = F_41 ( F_46 ( V_28 ) ) ;
int V_57 ;
V_57 = F_55 ( V_28 ) ;
if ( V_57 )
return V_57 ;
if ( V_2 -> V_5 -> V_41 & V_91 )
F_49 ( V_28 , V_2 ) ;
return F_56 ( V_28 ) ;
}
static int F_57 ( struct V_66 * V_28 )
{
struct V_1 * V_2 = F_41 ( F_46 ( V_28 ) ) ;
int V_57 ;
V_57 = F_58 ( V_28 ) ;
if ( V_57 )
return V_57 ;
if ( V_2 -> V_5 -> V_41 & V_91 )
F_47 ( V_28 , V_2 ) ;
return F_59 ( V_28 ) ;
}
static int F_60 ( struct V_66 * V_28 )
{
struct V_1 * V_2 = F_41 ( F_46 ( V_28 ) ) ;
int V_57 ;
V_57 = F_61 ( V_28 ) ;
if ( V_57 )
return V_57 ;
if ( V_2 -> V_5 -> V_41 & V_91 )
F_49 ( V_28 , V_2 ) ;
return F_62 ( V_28 ) ;
}
static int F_63 ( struct V_92 * V_93 ,
unsigned long V_94 , void * V_95 )
{
struct V_55 * V_56 = F_64 ( V_95 ) ;
struct V_1 * V_2 ;
struct V_24 * V_25 ;
const struct V_49 * V_50 ;
V_50 = F_65 ( V_96 , & V_56 -> V_28 ) ;
if ( ! V_50 || ! V_50 -> V_58 )
return 0 ;
if ( F_36 ( F_37 ( & V_56 -> V_28 ) , & V_25 ) )
return 0 ;
V_2 = F_41 ( V_25 ) ;
if ( ! V_2 )
return 0 ;
if ( V_2 -> V_8 &&
V_2 -> V_36 < V_2 -> V_5 -> V_6 + V_97 ) {
F_66 ( & V_56 -> V_28 , L_11 ) ;
return 0 ;
}
switch ( V_94 ) {
case V_98 :
V_56 -> V_28 . V_99 = & V_100 ;
if ( V_2 -> V_5 -> V_41 & V_101 )
return F_67 ( & V_56 -> V_28 . V_102 ,
& V_103 ) ;
break;
case V_104 :
if ( V_2 -> V_5 -> V_41 & V_101 )
F_68 ( & V_56 -> V_28 . V_102 , & V_103 ) ;
V_56 -> V_28 . V_99 = NULL ;
break;
default:
break;
}
return 0 ;
}
static void F_69 ( struct V_66 * V_28 )
{
struct V_1 * V_2 = F_41 ( F_46 ( V_28 ) ) ;
if ( ! V_2 || ! V_2 -> V_8 || ! ( V_2 -> V_5 -> V_41 & V_101 ) )
return;
if ( V_2 -> V_36 >= V_2 -> V_5 -> V_6 + V_97 )
V_28 -> V_67 . V_105 = F_45 ;
else
F_66 ( V_28 , L_11 ) ;
}
static void F_70 ( struct V_66 * V_28 )
{
V_28 -> V_67 . V_105 = NULL ;
}
void T_5 F_71 ( void )
{
if ( ! F_72 () ) {
F_73 ( & V_106 , & V_107 ) ;
F_74 ( & V_108 ) ;
}
}
void T_5 F_71 ( void )
{
F_74 ( & V_108 ) ;
}
