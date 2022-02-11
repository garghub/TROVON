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
F_9 ( V_8 -> V_12 , & V_8 -> V_2 -> V_13 ) ;
F_10 ( V_8 -> V_12 ) ;
F_11 ( V_8 ) ;
}
static void F_12 ( struct V_7 * V_8 )
{
if ( F_13 ( & V_8 -> V_11 ) )
F_14 ( & V_8 -> V_14 ) ;
}
static struct V_15 * * F_15 ( struct V_7 * V_8 ,
int V_16 , bool V_17 )
{
struct V_15 * * V_18 , * * V_19 ;
int V_20 , V_21 ;
V_20 = V_8 -> V_22 ;
V_18 = V_8 -> V_23 ;
while ( true ) {
V_21 = ( V_16 >> ( 9 * V_20 ) ) & 0x1ff ;
V_19 = & V_18 [ V_21 ] ;
if ( V_20 == 0 )
break;
if ( * V_19 == NULL ) {
if ( ! V_17 )
return NULL ;
* V_19 = ( void * ) F_16 ( V_24 ) ;
if ( * V_19 == NULL )
return NULL ;
}
V_18 = (struct V_15 * * ) * V_19 ;
V_20 -= 1 ;
}
return V_19 ;
}
static int F_17 ( struct V_7 * V_8 ,
struct V_15 * V_15 ,
int V_16 )
{
struct V_15 * * V_19 ;
unsigned long V_9 ;
int V_25 ;
F_5 ( & V_8 -> V_26 , V_9 ) ;
V_19 = F_15 ( V_8 , V_16 , true ) ;
V_25 = - V_27 ;
if ( V_19 == NULL )
goto V_28;
V_25 = - V_27 ;
if ( * V_19 != NULL )
goto V_28;
* V_19 = V_15 ;
V_25 = 0 ;
V_28:
F_7 ( & V_8 -> V_26 , V_9 ) ;
return V_25 ;
}
static void F_18 ( struct V_7 * V_8 , int V_16 )
{
struct V_15 * * V_19 ;
unsigned long V_9 ;
F_5 ( & V_8 -> V_26 , V_9 ) ;
V_19 = F_15 ( V_8 , V_16 , true ) ;
if ( V_19 == NULL )
goto V_28;
* V_19 = NULL ;
V_28:
F_7 ( & V_8 -> V_26 , V_9 ) ;
}
static struct V_15 * F_19 ( struct V_7 * V_8 ,
int V_16 )
{
struct V_15 * * V_19 , * V_25 = NULL ;
unsigned long V_9 ;
F_5 ( & V_8 -> V_26 , V_9 ) ;
V_19 = F_15 ( V_8 , V_16 , false ) ;
if ( V_19 == NULL )
goto V_28;
V_25 = * V_19 ;
if ( V_25 )
F_6 ( & V_25 -> V_11 ) ;
V_28:
F_7 ( & V_8 -> V_26 , V_9 ) ;
return V_25 ;
}
static void F_20 ( struct V_15 * V_15 )
{
F_11 ( V_15 ) ;
}
static void F_21 ( struct V_15 * V_15 )
{
if ( F_13 ( & V_15 -> V_11 ) )
F_14 ( & V_15 -> V_14 ) ;
}
static void F_22 ( struct V_15 * V_15 )
{
F_23 ( V_15 -> V_14 , ! F_24 ( & V_15 -> V_11 ) ) ;
F_20 ( V_15 ) ;
}
static void F_25 ( struct V_15 * V_15 )
{
struct V_29 * V_12 ;
V_12 = V_15 -> V_7 -> V_12 ;
V_15 -> V_30 = true ;
F_26 () ;
F_27 ( V_12 , V_15 -> V_16 ) ;
F_28 ( V_31 ) ;
}
static void F_29 ( struct V_15 * * V_32 )
{
int V_33 ;
for ( V_33 = 0 ; V_33 < 512 ; ++ V_33 ) {
if ( V_32 [ V_33 ] == NULL )
continue;
F_30 ( ( unsigned long ) V_32 [ V_33 ] ) ;
}
}
static void F_31 ( struct V_15 * * V_32 )
{
struct V_15 * * V_19 ;
int V_33 ;
for ( V_33 = 0 ; V_33 < 512 ; ++ V_33 ) {
if ( V_32 [ V_33 ] == NULL )
continue;
V_19 = (struct V_15 * * ) V_32 [ V_33 ] ;
F_29 ( V_19 ) ;
}
}
static void F_32 ( struct V_7 * V_8 )
{
struct V_15 * V_15 ;
int V_33 ;
for ( V_33 = 0 ; V_33 < V_8 -> V_34 ; ++ V_33 ) {
V_15 = F_19 ( V_8 , V_33 ) ;
if ( V_15 == NULL )
continue;
F_21 ( V_15 ) ;
F_33 ( & V_15 -> V_35 , V_15 -> V_36 ) ;
F_22 ( V_15 ) ;
F_12 ( V_8 ) ;
}
if ( V_8 -> V_22 == 2 )
F_31 ( V_8 -> V_23 ) ;
else if ( V_8 -> V_22 == 1 )
F_29 ( V_8 -> V_23 ) ;
else if ( V_8 -> V_22 != 0 )
F_34 () ;
F_30 ( ( unsigned long ) V_8 -> V_23 ) ;
}
static struct V_15 * F_35 ( struct V_37 * V_35 )
{
return F_36 ( V_35 , struct V_15 , V_35 ) ;
}
static void F_37 ( struct V_37 * V_35 ,
unsigned long V_38 )
{
struct V_15 * V_15 ;
struct V_7 * V_8 ;
V_15 = F_35 ( V_35 ) ;
V_8 = V_15 -> V_7 ;
F_38 ( V_8 -> V_12 , V_15 -> V_16 , V_38 ) ;
}
static int F_39 ( struct V_37 * V_35 ,
struct V_39 * V_36 ,
unsigned long V_40 ,
unsigned long V_41 )
{
for (; V_40 < V_41 ; V_40 += V_42 )
F_37 ( V_35 , V_40 ) ;
return 0 ;
}
static void F_40 ( struct V_37 * V_35 ,
struct V_39 * V_36 ,
unsigned long V_38 )
{
F_37 ( V_35 , V_38 ) ;
}
static void F_41 ( struct V_37 * V_35 ,
struct V_39 * V_36 ,
unsigned long V_40 , unsigned long V_41 )
{
struct V_15 * V_15 ;
struct V_7 * V_8 ;
V_15 = F_35 ( V_35 ) ;
V_8 = V_15 -> V_7 ;
if ( ( V_40 ^ ( V_41 - 1 ) ) < V_42 )
F_38 ( V_8 -> V_12 , V_15 -> V_16 ,
V_40 ) ;
else
F_42 ( V_8 -> V_12 , V_15 -> V_16 ) ;
}
static void F_43 ( struct V_37 * V_35 , struct V_39 * V_36 )
{
struct V_15 * V_15 ;
struct V_7 * V_8 ;
bool V_43 ;
F_44 () ;
V_15 = F_35 ( V_35 ) ;
V_8 = V_15 -> V_7 ;
V_43 = ! V_15 -> V_30 ;
if ( V_43 && V_15 -> V_7 -> V_44 )
V_8 -> V_44 ( V_8 -> V_2 , V_15 -> V_16 ) ;
F_25 ( V_15 ) ;
}
static void F_45 ( struct V_15 * V_15 ,
T_1 V_45 , int V_46 )
{
unsigned long V_9 ;
F_5 ( & V_15 -> V_26 , V_9 ) ;
V_15 -> V_47 [ V_45 ] . V_46 = V_46 ;
F_7 ( & V_15 -> V_26 , V_9 ) ;
}
static void F_46 ( struct V_7 * V_8 ,
struct V_15 * V_15 ,
T_1 V_45 )
{
unsigned long V_9 ;
F_5 ( & V_15 -> V_26 , V_9 ) ;
if ( F_13 ( & V_15 -> V_47 [ V_45 ] . V_48 ) &&
V_15 -> V_47 [ V_45 ] . V_49 ) {
F_47 ( V_8 -> V_2 , V_15 -> V_16 ,
V_15 -> V_47 [ V_45 ] . V_46 , V_45 ) ;
V_15 -> V_47 [ V_45 ] . V_49 = false ;
V_15 -> V_47 [ V_45 ] . V_46 = V_50 ;
}
F_7 ( & V_15 -> V_26 , V_9 ) ;
}
static void F_48 ( struct V_51 * V_51 )
{
int V_46 ;
if ( ! V_51 -> V_8 -> V_52 ) {
F_45 ( V_51 -> V_53 , V_51 -> V_45 , V_54 ) ;
return;
}
V_46 = V_51 -> V_8 -> V_52 ( V_51 -> V_8 -> V_2 ,
V_51 -> V_16 ,
V_51 -> V_38 ,
V_51 -> V_9 ) ;
switch ( V_46 ) {
case V_55 :
F_45 ( V_51 -> V_53 , V_51 -> V_45 , V_50 ) ;
break;
case V_56 :
F_45 ( V_51 -> V_53 , V_51 -> V_45 , V_54 ) ;
break;
case V_57 :
F_45 ( V_51 -> V_53 , V_51 -> V_45 , V_58 ) ;
break;
default:
F_34 () ;
}
}
static void F_49 ( struct V_59 * V_60 )
{
struct V_51 * V_51 = F_36 ( V_60 , struct V_51 , V_60 ) ;
struct V_39 * V_36 ;
struct V_61 * V_62 ;
T_2 V_38 ;
int V_25 , V_63 ;
V_63 = ! ! ( V_51 -> V_9 & V_64 ) ;
V_36 = V_51 -> V_53 -> V_36 ;
V_38 = V_51 -> V_38 ;
F_50 ( & V_36 -> V_65 ) ;
V_62 = F_51 ( V_36 , V_38 ) ;
if ( ! V_62 || V_38 < V_62 -> V_66 ) {
F_52 ( & V_36 -> V_65 ) ;
F_48 ( V_51 ) ;
goto V_67;
}
V_25 = F_53 ( V_36 , V_62 , V_38 , V_63 ) ;
if ( V_25 & V_68 ) {
F_52 ( & V_36 -> V_65 ) ;
F_48 ( V_51 ) ;
goto V_67;
}
F_52 ( & V_36 -> V_65 ) ;
V_67:
F_46 ( V_51 -> V_8 , V_51 -> V_53 , V_51 -> V_45 ) ;
F_21 ( V_51 -> V_53 ) ;
F_11 ( V_51 ) ;
}
static int F_54 ( struct V_69 * V_70 , unsigned long V_71 , void * V_72 )
{
struct V_73 * V_74 ;
struct V_15 * V_15 ;
struct V_7 * V_8 ;
unsigned long V_9 ;
struct V_51 * V_51 ;
bool V_49 ;
T_1 V_45 ;
int V_25 ;
V_74 = V_72 ;
V_45 = V_74 -> V_45 & 0x1ff ;
V_49 = ( V_74 -> V_45 >> 9 ) & 1 ;
V_25 = V_75 ;
V_8 = F_4 ( V_74 -> F_1 ) ;
if ( V_8 == NULL )
goto V_67;
V_15 = F_19 ( V_8 , V_74 -> V_16 ) ;
if ( V_15 == NULL || V_15 -> V_30 ) {
F_47 ( V_8 -> V_2 , V_74 -> V_16 ,
V_54 , V_45 ) ;
goto V_76;
}
F_5 ( & V_15 -> V_26 , V_9 ) ;
F_6 ( & V_15 -> V_47 [ V_45 ] . V_48 ) ;
if ( V_49 )
V_15 -> V_47 [ V_45 ] . V_49 = true ;
F_7 ( & V_15 -> V_26 , V_9 ) ;
V_51 = F_55 ( sizeof( * V_51 ) , V_24 ) ;
if ( V_51 == NULL ) {
F_46 ( V_8 , V_15 , V_45 ) ;
goto V_76;
}
V_51 -> V_8 = V_8 ;
V_51 -> V_38 = V_74 -> V_38 ;
V_51 -> V_53 = V_15 ;
V_51 -> V_45 = V_45 ;
V_51 -> V_49 = V_49 ;
V_51 -> V_16 = V_74 -> V_16 ;
V_51 -> V_9 = V_74 -> V_9 ;
F_56 ( & V_51 -> V_60 , F_49 ) ;
F_57 ( V_31 , & V_51 -> V_60 ) ;
V_25 = V_77 ;
V_76:
if ( V_25 != V_77 && V_15 )
F_21 ( V_15 ) ;
F_12 ( V_8 ) ;
V_67:
return V_25 ;
}
int F_58 ( struct V_1 * V_2 , int V_16 ,
struct V_78 * V_79 )
{
struct V_15 * V_15 ;
struct V_7 * V_8 ;
struct V_39 * V_36 ;
T_1 V_3 ;
int V_25 ;
F_44 () ;
if ( ! F_59 () )
return - V_80 ;
V_3 = F_1 ( V_2 ) ;
V_8 = F_4 ( V_3 ) ;
if ( V_8 == NULL )
return - V_81 ;
V_25 = - V_81 ;
if ( V_16 < 0 || V_16 >= V_8 -> V_34 )
goto V_67;
V_25 = - V_27 ;
V_15 = F_55 ( sizeof( * V_15 ) , V_82 ) ;
if ( V_15 == NULL )
goto V_67;
F_60 ( & V_15 -> V_11 , 1 ) ;
F_61 ( & V_15 -> V_14 ) ;
F_62 ( & V_15 -> V_26 ) ;
V_36 = F_63 ( V_79 ) ;
V_15 -> V_36 = V_36 ;
V_15 -> V_7 = V_8 ;
V_15 -> V_16 = V_16 ;
V_15 -> V_30 = true ;
V_15 -> V_35 . V_83 = & V_84 ;
if ( V_15 -> V_36 == NULL )
goto V_85;
F_64 ( & V_15 -> V_35 , V_36 ) ;
V_25 = F_17 ( V_8 , V_15 , V_16 ) ;
if ( V_25 )
goto V_86;
V_25 = F_65 ( V_8 -> V_12 , V_16 ,
F_66 ( V_15 -> V_36 -> V_87 ) ) ;
if ( V_25 )
goto V_88;
V_15 -> V_30 = false ;
F_67 ( V_36 ) ;
return 0 ;
V_88:
F_18 ( V_8 , V_16 ) ;
V_86:
F_33 ( & V_15 -> V_35 , V_36 ) ;
V_85:
F_67 ( V_36 ) ;
F_20 ( V_15 ) ;
V_67:
F_12 ( V_8 ) ;
return V_25 ;
}
void F_68 ( struct V_1 * V_2 , int V_16 )
{
struct V_15 * V_15 ;
struct V_7 * V_8 ;
T_1 V_3 ;
F_44 () ;
if ( ! F_59 () )
return;
V_3 = F_1 ( V_2 ) ;
V_8 = F_4 ( V_3 ) ;
if ( V_8 == NULL )
return;
if ( V_16 < 0 || V_16 >= V_8 -> V_34 )
goto V_67;
V_15 = F_19 ( V_8 , V_16 ) ;
if ( V_15 == NULL )
goto V_67;
F_21 ( V_15 ) ;
F_18 ( V_8 , V_15 -> V_16 ) ;
F_33 ( & V_15 -> V_35 , V_15 -> V_36 ) ;
F_22 ( V_15 ) ;
V_67:
F_12 ( V_8 ) ;
F_12 ( V_8 ) ;
}
int F_69 ( struct V_1 * V_2 , int V_89 )
{
struct V_7 * V_8 ;
unsigned long V_9 ;
int V_25 , V_90 ;
T_1 V_3 ;
F_44 () ;
if ( ! F_59 () )
return - V_80 ;
if ( V_89 <= 0 || V_89 > ( V_91 + 1 ) )
return - V_81 ;
V_3 = F_1 ( V_2 ) ;
V_8 = F_55 ( sizeof( * V_8 ) , V_82 ) ;
if ( V_8 == NULL )
return - V_27 ;
F_62 ( & V_8 -> V_26 ) ;
F_61 ( & V_8 -> V_14 ) ;
V_8 -> V_2 = V_2 ;
V_8 -> V_3 = V_3 ;
V_90 = V_89 ;
for ( V_8 -> V_22 = 0 ; ( V_90 - 1 ) & ~ 0x1ff ; V_90 >>= 9 )
V_8 -> V_22 += 1 ;
F_60 ( & V_8 -> V_11 , 1 ) ;
V_8 -> V_34 = V_89 ;
V_25 = - V_27 ;
V_8 -> V_23 = ( void * ) F_16 ( V_82 ) ;
if ( V_8 -> V_23 == NULL )
goto V_92;
V_8 -> V_12 = F_70 ( & V_93 ) ;
if ( V_8 -> V_12 == NULL )
goto V_94;
F_71 ( V_8 -> V_12 ) ;
V_25 = F_72 ( V_8 -> V_12 , V_89 ) ;
if ( V_25 )
goto V_95;
V_25 = F_73 ( V_8 -> V_12 , & V_2 -> V_13 ) ;
if ( V_25 != 0 )
goto V_95;
F_5 ( & V_10 , V_9 ) ;
if ( F_2 ( V_3 ) != NULL ) {
F_7 ( & V_10 , V_9 ) ;
V_25 = - V_96 ;
goto V_95;
}
F_74 ( & V_8 -> V_97 , & V_98 ) ;
F_7 ( & V_10 , V_9 ) ;
return 0 ;
V_95:
F_10 ( V_8 -> V_12 ) ;
V_94:
F_30 ( ( unsigned long ) V_8 -> V_23 ) ;
V_92:
F_11 ( V_8 ) ;
return V_25 ;
}
void F_75 ( struct V_1 * V_2 )
{
struct V_7 * V_8 ;
unsigned long V_9 ;
T_1 V_3 ;
if ( ! F_59 () )
return;
V_3 = F_1 ( V_2 ) ;
F_5 ( & V_10 , V_9 ) ;
V_8 = F_2 ( V_3 ) ;
if ( V_8 == NULL ) {
F_7 ( & V_10 , V_9 ) ;
return;
}
F_76 ( & V_8 -> V_97 ) ;
F_7 ( & V_10 , V_9 ) ;
F_32 ( V_8 ) ;
F_12 ( V_8 ) ;
F_23 ( V_8 -> V_14 , ! F_24 ( & V_8 -> V_11 ) ) ;
F_8 ( V_8 ) ;
}
int F_77 ( struct V_1 * V_2 ,
T_3 V_99 )
{
struct V_7 * V_8 ;
unsigned long V_9 ;
T_1 V_3 ;
int V_25 ;
if ( ! F_59 () )
return - V_80 ;
V_3 = F_1 ( V_2 ) ;
F_5 ( & V_10 , V_9 ) ;
V_25 = - V_81 ;
V_8 = F_2 ( V_3 ) ;
if ( V_8 == NULL )
goto V_28;
V_8 -> V_52 = V_99 ;
V_25 = 0 ;
V_28:
F_7 ( & V_10 , V_9 ) ;
return V_25 ;
}
int F_78 ( struct V_1 * V_2 ,
T_4 V_99 )
{
struct V_7 * V_8 ;
unsigned long V_9 ;
T_1 V_3 ;
int V_25 ;
if ( ! F_59 () )
return - V_80 ;
V_3 = F_1 ( V_2 ) ;
F_5 ( & V_10 , V_9 ) ;
V_25 = - V_81 ;
V_8 = F_2 ( V_3 ) ;
if ( V_8 == NULL )
goto V_28;
V_8 -> V_44 = V_99 ;
V_25 = 0 ;
V_28:
F_7 ( & V_10 , V_9 ) ;
return V_25 ;
}
static int T_5 F_79 ( void )
{
int V_25 ;
F_80 ( L_1 ) ;
if ( ! F_59 () ) {
F_80 ( L_2 ) ;
return 0 ;
}
F_62 ( & V_10 ) ;
V_25 = - V_27 ;
V_31 = F_81 ( L_3 ) ;
if ( V_31 == NULL )
goto V_67;
F_82 ( & V_100 ) ;
return 0 ;
V_67:
return V_25 ;
}
static void T_6 F_83 ( void )
{
struct V_7 * V_8 ;
int V_33 ;
if ( ! F_59 () )
return;
F_84 ( & V_100 ) ;
F_28 ( V_31 ) ;
for ( V_33 = 0 ; V_33 < V_101 ; ++ V_33 ) {
V_8 = F_4 ( V_33 ) ;
if ( V_8 == NULL )
continue;
F_85 ( 1 ) ;
F_12 ( V_8 ) ;
F_75 ( V_8 -> V_2 ) ;
}
F_86 ( V_31 ) ;
}
