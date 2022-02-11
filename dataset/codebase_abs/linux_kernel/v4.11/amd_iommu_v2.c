static T_1 F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
V_3 = V_2 -> V_4 -> V_5 ;
V_3 = ( V_3 << 8 ) | V_2 -> V_6 ;
return V_3 ;
}
static struct V_7 * F_2 ( T_1 V_3 )
{
struct V_7 * V_8 ;
F_3 (dev_state, &state_list, list) {
if ( V_8 -> V_3 == V_3 )
return V_8 ;
}
return NULL ;
}
static struct V_7 * F_4 ( T_1 V_3 )
{
struct V_7 * V_8 ;
unsigned long V_9 ;
F_5 ( & V_10 , V_9 ) ;
V_8 = F_2 ( V_3 ) ;
if ( V_8 != NULL )
F_6 ( & V_8 -> V_11 ) ;
F_7 ( & V_10 , V_9 ) ;
return V_8 ;
}
static void F_8 ( struct V_7 * V_8 )
{
struct V_12 * V_13 ;
V_13 = F_9 ( & V_8 -> V_2 -> V_14 ) ;
if ( F_10 ( ! V_13 ) )
return;
F_11 ( V_8 -> V_15 , V_13 ) ;
F_12 ( V_13 ) ;
F_13 ( V_8 -> V_15 ) ;
F_14 ( V_8 ) ;
}
static void F_15 ( struct V_7 * V_8 )
{
if ( F_16 ( & V_8 -> V_11 ) )
F_17 ( & V_8 -> V_16 ) ;
}
static struct V_17 * * F_18 ( struct V_7 * V_8 ,
int V_18 , bool V_19 )
{
struct V_17 * * V_20 , * * V_21 ;
int V_22 , V_23 ;
V_22 = V_8 -> V_24 ;
V_20 = V_8 -> V_25 ;
while ( true ) {
V_23 = ( V_18 >> ( 9 * V_22 ) ) & 0x1ff ;
V_21 = & V_20 [ V_23 ] ;
if ( V_22 == 0 )
break;
if ( * V_21 == NULL ) {
if ( ! V_19 )
return NULL ;
* V_21 = ( void * ) F_19 ( V_26 ) ;
if ( * V_21 == NULL )
return NULL ;
}
V_20 = (struct V_17 * * ) * V_21 ;
V_22 -= 1 ;
}
return V_21 ;
}
static int F_20 ( struct V_7 * V_8 ,
struct V_17 * V_17 ,
int V_18 )
{
struct V_17 * * V_21 ;
unsigned long V_9 ;
int V_27 ;
F_5 ( & V_8 -> V_28 , V_9 ) ;
V_21 = F_18 ( V_8 , V_18 , true ) ;
V_27 = - V_29 ;
if ( V_21 == NULL )
goto V_30;
V_27 = - V_29 ;
if ( * V_21 != NULL )
goto V_30;
* V_21 = V_17 ;
V_27 = 0 ;
V_30:
F_7 ( & V_8 -> V_28 , V_9 ) ;
return V_27 ;
}
static void F_21 ( struct V_7 * V_8 , int V_18 )
{
struct V_17 * * V_21 ;
unsigned long V_9 ;
F_5 ( & V_8 -> V_28 , V_9 ) ;
V_21 = F_18 ( V_8 , V_18 , true ) ;
if ( V_21 == NULL )
goto V_30;
* V_21 = NULL ;
V_30:
F_7 ( & V_8 -> V_28 , V_9 ) ;
}
static struct V_17 * F_22 ( struct V_7 * V_8 ,
int V_18 )
{
struct V_17 * * V_21 , * V_27 = NULL ;
unsigned long V_9 ;
F_5 ( & V_8 -> V_28 , V_9 ) ;
V_21 = F_18 ( V_8 , V_18 , false ) ;
if ( V_21 == NULL )
goto V_30;
V_27 = * V_21 ;
if ( V_27 )
F_6 ( & V_27 -> V_11 ) ;
V_30:
F_7 ( & V_8 -> V_28 , V_9 ) ;
return V_27 ;
}
static void F_23 ( struct V_17 * V_17 )
{
F_14 ( V_17 ) ;
}
static void F_24 ( struct V_17 * V_17 )
{
if ( F_16 ( & V_17 -> V_11 ) )
F_17 ( & V_17 -> V_16 ) ;
}
static void F_25 ( struct V_17 * V_17 )
{
F_26 ( & V_17 -> V_11 ) ;
F_27 ( V_17 -> V_16 , ! F_28 ( & V_17 -> V_11 ) ) ;
F_23 ( V_17 ) ;
}
static void F_29 ( struct V_17 * V_17 )
{
struct V_31 * V_15 ;
V_15 = V_17 -> V_7 -> V_15 ;
V_17 -> V_32 = true ;
F_30 () ;
F_31 ( V_15 , V_17 -> V_18 ) ;
F_32 ( V_33 ) ;
}
static void F_33 ( struct V_17 * * V_34 )
{
int V_35 ;
for ( V_35 = 0 ; V_35 < 512 ; ++ V_35 ) {
if ( V_34 [ V_35 ] == NULL )
continue;
F_34 ( ( unsigned long ) V_34 [ V_35 ] ) ;
}
}
static void F_35 ( struct V_17 * * V_34 )
{
struct V_17 * * V_21 ;
int V_35 ;
for ( V_35 = 0 ; V_35 < 512 ; ++ V_35 ) {
if ( V_34 [ V_35 ] == NULL )
continue;
V_21 = (struct V_17 * * ) V_34 [ V_35 ] ;
F_33 ( V_21 ) ;
}
}
static void F_36 ( struct V_7 * V_8 )
{
struct V_17 * V_17 ;
int V_35 ;
for ( V_35 = 0 ; V_35 < V_8 -> V_36 ; ++ V_35 ) {
V_17 = F_22 ( V_8 , V_35 ) ;
if ( V_17 == NULL )
continue;
F_24 ( V_17 ) ;
F_37 ( & V_17 -> V_37 , V_17 -> V_38 ) ;
F_25 ( V_17 ) ;
F_15 ( V_8 ) ;
}
if ( V_8 -> V_24 == 2 )
F_35 ( V_8 -> V_25 ) ;
else if ( V_8 -> V_24 == 1 )
F_33 ( V_8 -> V_25 ) ;
else
F_38 ( V_8 -> V_24 != 0 ) ;
F_34 ( ( unsigned long ) V_8 -> V_25 ) ;
}
static struct V_17 * F_39 ( struct V_39 * V_37 )
{
return F_40 ( V_37 , struct V_17 , V_37 ) ;
}
static void F_41 ( struct V_39 * V_37 ,
unsigned long V_40 )
{
struct V_17 * V_17 ;
struct V_7 * V_8 ;
V_17 = F_39 ( V_37 ) ;
V_8 = V_17 -> V_7 ;
F_42 ( V_8 -> V_15 , V_17 -> V_18 , V_40 ) ;
}
static int F_43 ( struct V_39 * V_37 ,
struct V_41 * V_38 ,
unsigned long V_42 ,
unsigned long V_43 )
{
for (; V_42 < V_43 ; V_42 += V_44 )
F_41 ( V_37 , V_42 ) ;
return 0 ;
}
static void F_44 ( struct V_39 * V_37 ,
struct V_41 * V_38 ,
unsigned long V_40 )
{
F_41 ( V_37 , V_40 ) ;
}
static void F_45 ( struct V_39 * V_37 ,
struct V_41 * V_38 ,
unsigned long V_42 , unsigned long V_43 )
{
struct V_17 * V_17 ;
struct V_7 * V_8 ;
V_17 = F_39 ( V_37 ) ;
V_8 = V_17 -> V_7 ;
if ( ( V_42 ^ ( V_43 - 1 ) ) < V_44 )
F_42 ( V_8 -> V_15 , V_17 -> V_18 ,
V_42 ) ;
else
F_46 ( V_8 -> V_15 , V_17 -> V_18 ) ;
}
static void F_47 ( struct V_39 * V_37 , struct V_41 * V_38 )
{
struct V_17 * V_17 ;
struct V_7 * V_8 ;
bool V_45 ;
F_48 () ;
V_17 = F_39 ( V_37 ) ;
V_8 = V_17 -> V_7 ;
V_45 = ! V_17 -> V_32 ;
if ( V_45 && V_8 -> V_46 )
V_8 -> V_46 ( V_8 -> V_2 , V_17 -> V_18 ) ;
F_29 ( V_17 ) ;
}
static void F_49 ( struct V_17 * V_17 ,
T_1 V_47 , int V_48 )
{
unsigned long V_9 ;
F_5 ( & V_17 -> V_28 , V_9 ) ;
V_17 -> V_49 [ V_47 ] . V_48 = V_48 ;
F_7 ( & V_17 -> V_28 , V_9 ) ;
}
static void F_50 ( struct V_7 * V_8 ,
struct V_17 * V_17 ,
T_1 V_47 )
{
unsigned long V_9 ;
F_5 ( & V_17 -> V_28 , V_9 ) ;
if ( F_16 ( & V_17 -> V_49 [ V_47 ] . V_50 ) &&
V_17 -> V_49 [ V_47 ] . V_51 ) {
F_51 ( V_8 -> V_2 , V_17 -> V_18 ,
V_17 -> V_49 [ V_47 ] . V_48 , V_47 ) ;
V_17 -> V_49 [ V_47 ] . V_51 = false ;
V_17 -> V_49 [ V_47 ] . V_48 = V_52 ;
}
F_7 ( & V_17 -> V_28 , V_9 ) ;
}
static void F_52 ( struct V_53 * V_53 )
{
int V_48 ;
if ( ! V_53 -> V_8 -> V_54 ) {
F_49 ( V_53 -> V_55 , V_53 -> V_47 , V_56 ) ;
return;
}
V_48 = V_53 -> V_8 -> V_54 ( V_53 -> V_8 -> V_2 ,
V_53 -> V_18 ,
V_53 -> V_40 ,
V_53 -> V_9 ) ;
switch ( V_48 ) {
case V_57 :
F_49 ( V_53 -> V_55 , V_53 -> V_47 , V_52 ) ;
break;
case V_58 :
F_49 ( V_53 -> V_55 , V_53 -> V_47 , V_56 ) ;
break;
case V_59 :
F_49 ( V_53 -> V_55 , V_53 -> V_47 , V_60 ) ;
break;
default:
F_53 () ;
}
}
static bool F_54 ( struct V_61 * V_62 , struct V_53 * V_53 )
{
unsigned long V_63 = 0 ;
if ( V_53 -> V_9 & V_64 )
V_63 |= V_65 ;
if ( V_53 -> V_9 & V_66 )
V_63 |= V_67 ;
if ( V_53 -> V_9 & V_68 )
V_63 |= V_69 ;
return ( V_63 & ~ V_62 -> V_70 ) != 0 ;
}
static void F_55 ( struct V_71 * V_72 )
{
struct V_53 * V_53 = F_40 ( V_72 , struct V_53 , V_72 ) ;
struct V_61 * V_62 ;
int V_27 = V_73 ;
unsigned int V_9 = 0 ;
struct V_41 * V_38 ;
T_2 V_40 ;
V_38 = V_53 -> V_55 -> V_38 ;
V_40 = V_53 -> V_40 ;
if ( V_53 -> V_9 & V_74 )
V_9 |= V_75 ;
if ( V_53 -> V_9 & V_68 )
V_9 |= V_76 ;
V_9 |= V_77 ;
F_56 ( & V_38 -> V_78 ) ;
V_62 = F_57 ( V_38 , V_40 ) ;
if ( ! V_62 || V_40 < V_62 -> V_79 )
goto V_80;
if ( F_54 ( V_62 , V_53 ) )
goto V_80;
V_27 = F_58 ( V_62 , V_40 , V_9 ) ;
V_80:
F_59 ( & V_38 -> V_78 ) ;
if ( V_27 & V_73 )
F_52 ( V_53 ) ;
F_50 ( V_53 -> V_8 , V_53 -> V_55 , V_53 -> V_47 ) ;
F_24 ( V_53 -> V_55 ) ;
F_14 ( V_53 ) ;
}
static int F_60 ( struct V_81 * V_82 , unsigned long V_83 , void * V_84 )
{
struct V_85 * V_86 ;
struct V_17 * V_17 ;
struct V_7 * V_8 ;
unsigned long V_9 ;
struct V_53 * V_53 ;
bool V_51 ;
T_1 V_47 ;
int V_27 ;
V_86 = V_84 ;
V_47 = V_86 -> V_47 & 0x1ff ;
V_51 = ( V_86 -> V_47 >> 9 ) & 1 ;
V_27 = V_87 ;
V_8 = F_4 ( V_86 -> F_1 ) ;
if ( V_8 == NULL )
goto V_80;
V_17 = F_22 ( V_8 , V_86 -> V_18 ) ;
if ( V_17 == NULL || V_17 -> V_32 ) {
F_51 ( V_8 -> V_2 , V_86 -> V_18 ,
V_56 , V_47 ) ;
goto V_88;
}
F_5 ( & V_17 -> V_28 , V_9 ) ;
F_6 ( & V_17 -> V_49 [ V_47 ] . V_50 ) ;
if ( V_51 )
V_17 -> V_49 [ V_47 ] . V_51 = true ;
F_7 ( & V_17 -> V_28 , V_9 ) ;
V_53 = F_61 ( sizeof( * V_53 ) , V_26 ) ;
if ( V_53 == NULL ) {
F_50 ( V_8 , V_17 , V_47 ) ;
goto V_88;
}
V_53 -> V_8 = V_8 ;
V_53 -> V_40 = V_86 -> V_40 ;
V_53 -> V_55 = V_17 ;
V_53 -> V_47 = V_47 ;
V_53 -> V_51 = V_51 ;
V_53 -> V_18 = V_86 -> V_18 ;
V_53 -> V_9 = V_86 -> V_9 ;
F_62 ( & V_53 -> V_72 , F_55 ) ;
F_63 ( V_33 , & V_53 -> V_72 ) ;
V_27 = V_89 ;
V_88:
if ( V_27 != V_89 && V_17 )
F_24 ( V_17 ) ;
F_15 ( V_8 ) ;
V_80:
return V_27 ;
}
int F_64 ( struct V_1 * V_2 , int V_18 ,
struct V_90 * V_91 )
{
struct V_17 * V_17 ;
struct V_7 * V_8 ;
struct V_41 * V_38 ;
T_1 V_3 ;
int V_27 ;
F_48 () ;
if ( ! F_65 () )
return - V_92 ;
V_3 = F_1 ( V_2 ) ;
V_8 = F_4 ( V_3 ) ;
if ( V_8 == NULL )
return - V_93 ;
V_27 = - V_93 ;
if ( V_18 < 0 || V_18 >= V_8 -> V_36 )
goto V_80;
V_27 = - V_29 ;
V_17 = F_61 ( sizeof( * V_17 ) , V_94 ) ;
if ( V_17 == NULL )
goto V_80;
F_66 ( & V_17 -> V_11 , 1 ) ;
F_67 ( & V_17 -> V_16 ) ;
F_68 ( & V_17 -> V_28 ) ;
V_38 = F_69 ( V_91 ) ;
V_17 -> V_38 = V_38 ;
V_17 -> V_7 = V_8 ;
V_17 -> V_18 = V_18 ;
V_17 -> V_32 = true ;
V_17 -> V_37 . V_95 = & V_96 ;
if ( V_17 -> V_38 == NULL )
goto V_97;
F_70 ( & V_17 -> V_37 , V_38 ) ;
V_27 = F_20 ( V_8 , V_17 , V_18 ) ;
if ( V_27 )
goto V_98;
V_27 = F_71 ( V_8 -> V_15 , V_18 ,
F_72 ( V_17 -> V_38 -> V_99 ) ) ;
if ( V_27 )
goto V_100;
V_17 -> V_32 = false ;
F_73 ( V_38 ) ;
return 0 ;
V_100:
F_21 ( V_8 , V_18 ) ;
V_98:
F_37 ( & V_17 -> V_37 , V_38 ) ;
V_97:
F_73 ( V_38 ) ;
F_23 ( V_17 ) ;
V_80:
F_15 ( V_8 ) ;
return V_27 ;
}
void F_74 ( struct V_1 * V_2 , int V_18 )
{
struct V_17 * V_17 ;
struct V_7 * V_8 ;
T_1 V_3 ;
F_48 () ;
if ( ! F_65 () )
return;
V_3 = F_1 ( V_2 ) ;
V_8 = F_4 ( V_3 ) ;
if ( V_8 == NULL )
return;
if ( V_18 < 0 || V_18 >= V_8 -> V_36 )
goto V_80;
V_17 = F_22 ( V_8 , V_18 ) ;
if ( V_17 == NULL )
goto V_80;
F_24 ( V_17 ) ;
F_21 ( V_8 , V_17 -> V_18 ) ;
F_37 ( & V_17 -> V_37 , V_17 -> V_38 ) ;
F_25 ( V_17 ) ;
V_80:
F_15 ( V_8 ) ;
F_15 ( V_8 ) ;
}
int F_75 ( struct V_1 * V_2 , int V_101 )
{
struct V_7 * V_8 ;
struct V_12 * V_13 ;
unsigned long V_9 ;
int V_27 , V_102 ;
T_1 V_3 ;
F_48 () ;
if ( ! F_65 () )
return - V_92 ;
if ( V_101 <= 0 || V_101 > ( V_103 + 1 ) )
return - V_93 ;
V_3 = F_1 ( V_2 ) ;
V_8 = F_61 ( sizeof( * V_8 ) , V_94 ) ;
if ( V_8 == NULL )
return - V_29 ;
F_68 ( & V_8 -> V_28 ) ;
F_67 ( & V_8 -> V_16 ) ;
V_8 -> V_2 = V_2 ;
V_8 -> V_3 = V_3 ;
V_102 = V_101 ;
for ( V_8 -> V_24 = 0 ; ( V_102 - 1 ) & ~ 0x1ff ; V_102 >>= 9 )
V_8 -> V_24 += 1 ;
F_66 ( & V_8 -> V_11 , 1 ) ;
V_8 -> V_36 = V_101 ;
V_27 = - V_29 ;
V_8 -> V_25 = ( void * ) F_19 ( V_94 ) ;
if ( V_8 -> V_25 == NULL )
goto V_104;
V_8 -> V_15 = F_76 ( & V_105 ) ;
if ( V_8 -> V_15 == NULL )
goto V_106;
F_77 ( V_8 -> V_15 ) ;
V_27 = F_78 ( V_8 -> V_15 , V_101 ) ;
if ( V_27 )
goto V_107;
V_13 = F_9 ( & V_2 -> V_14 ) ;
if ( ! V_13 ) {
V_27 = - V_93 ;
goto V_107;
}
V_27 = F_79 ( V_8 -> V_15 , V_13 ) ;
if ( V_27 != 0 )
goto V_108;
F_12 ( V_13 ) ;
F_5 ( & V_10 , V_9 ) ;
if ( F_2 ( V_3 ) != NULL ) {
F_7 ( & V_10 , V_9 ) ;
V_27 = - V_109 ;
goto V_107;
}
F_80 ( & V_8 -> V_110 , & V_111 ) ;
F_7 ( & V_10 , V_9 ) ;
return 0 ;
V_108:
F_12 ( V_13 ) ;
V_107:
F_13 ( V_8 -> V_15 ) ;
V_106:
F_34 ( ( unsigned long ) V_8 -> V_25 ) ;
V_104:
F_14 ( V_8 ) ;
return V_27 ;
}
void F_81 ( struct V_1 * V_2 )
{
struct V_7 * V_8 ;
unsigned long V_9 ;
T_1 V_3 ;
if ( ! F_65 () )
return;
V_3 = F_1 ( V_2 ) ;
F_5 ( & V_10 , V_9 ) ;
V_8 = F_2 ( V_3 ) ;
if ( V_8 == NULL ) {
F_7 ( & V_10 , V_9 ) ;
return;
}
F_82 ( & V_8 -> V_110 ) ;
F_7 ( & V_10 , V_9 ) ;
F_36 ( V_8 ) ;
F_15 ( V_8 ) ;
F_27 ( V_8 -> V_16 , ! F_28 ( & V_8 -> V_11 ) ) ;
F_8 ( V_8 ) ;
}
int F_83 ( struct V_1 * V_2 ,
T_3 V_112 )
{
struct V_7 * V_8 ;
unsigned long V_9 ;
T_1 V_3 ;
int V_27 ;
if ( ! F_65 () )
return - V_92 ;
V_3 = F_1 ( V_2 ) ;
F_5 ( & V_10 , V_9 ) ;
V_27 = - V_93 ;
V_8 = F_2 ( V_3 ) ;
if ( V_8 == NULL )
goto V_30;
V_8 -> V_54 = V_112 ;
V_27 = 0 ;
V_30:
F_7 ( & V_10 , V_9 ) ;
return V_27 ;
}
int F_84 ( struct V_1 * V_2 ,
T_4 V_112 )
{
struct V_7 * V_8 ;
unsigned long V_9 ;
T_1 V_3 ;
int V_27 ;
if ( ! F_65 () )
return - V_92 ;
V_3 = F_1 ( V_2 ) ;
F_5 ( & V_10 , V_9 ) ;
V_27 = - V_93 ;
V_8 = F_2 ( V_3 ) ;
if ( V_8 == NULL )
goto V_30;
V_8 -> V_46 = V_112 ;
V_27 = 0 ;
V_30:
F_7 ( & V_10 , V_9 ) ;
return V_27 ;
}
static int T_5 F_85 ( void )
{
int V_27 ;
F_86 ( L_1 ) ;
if ( ! F_65 () ) {
F_86 ( L_2 ) ;
return 0 ;
}
F_68 ( & V_10 ) ;
V_27 = - V_29 ;
V_33 = F_87 ( L_3 , V_113 , 0 ) ;
if ( V_33 == NULL )
goto V_80;
F_88 ( & V_114 ) ;
return 0 ;
V_80:
return V_27 ;
}
static void T_6 F_89 ( void )
{
struct V_7 * V_8 ;
int V_35 ;
if ( ! F_65 () )
return;
F_90 ( & V_114 ) ;
F_32 ( V_33 ) ;
for ( V_35 = 0 ; V_35 < V_115 ; ++ V_35 ) {
V_8 = F_4 ( V_35 ) ;
if ( V_8 == NULL )
continue;
F_91 ( 1 ) ;
F_15 ( V_8 ) ;
F_81 ( V_8 -> V_2 ) ;
}
F_92 ( V_33 ) ;
}
