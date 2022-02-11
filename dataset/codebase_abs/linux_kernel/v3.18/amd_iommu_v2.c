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
static void F_15 ( struct V_7 * V_8 )
{
F_16 ( V_15 ) ;
F_17 ( & V_8 -> V_14 , & V_15 , V_16 ) ;
if ( ! F_13 ( & V_8 -> V_11 ) )
F_18 () ;
F_19 ( & V_8 -> V_14 , & V_15 ) ;
F_8 ( V_8 ) ;
}
static struct V_17 * * F_20 ( struct V_7 * V_8 ,
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
* V_21 = ( void * ) F_21 ( V_26 ) ;
if ( * V_21 == NULL )
return NULL ;
}
V_20 = (struct V_17 * * ) * V_21 ;
V_22 -= 1 ;
}
return V_21 ;
}
static int F_22 ( struct V_7 * V_8 ,
struct V_17 * V_17 ,
int V_18 )
{
struct V_17 * * V_21 ;
unsigned long V_9 ;
int V_27 ;
F_5 ( & V_8 -> V_28 , V_9 ) ;
V_21 = F_20 ( V_8 , V_18 , true ) ;
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
static void F_23 ( struct V_7 * V_8 , int V_18 )
{
struct V_17 * * V_21 ;
unsigned long V_9 ;
F_5 ( & V_8 -> V_28 , V_9 ) ;
V_21 = F_20 ( V_8 , V_18 , true ) ;
if ( V_21 == NULL )
goto V_30;
* V_21 = NULL ;
V_30:
F_7 ( & V_8 -> V_28 , V_9 ) ;
}
static struct V_17 * F_24 ( struct V_7 * V_8 ,
int V_18 )
{
struct V_17 * * V_21 , * V_27 = NULL ;
unsigned long V_9 ;
F_5 ( & V_8 -> V_28 , V_9 ) ;
V_21 = F_20 ( V_8 , V_18 , false ) ;
if ( V_21 == NULL )
goto V_30;
V_27 = * V_21 ;
if ( V_27 )
F_6 ( & V_27 -> V_11 ) ;
V_30:
F_7 ( & V_8 -> V_28 , V_9 ) ;
return V_27 ;
}
static void F_25 ( struct V_17 * V_17 )
{
F_11 ( V_17 ) ;
}
static void F_26 ( struct V_17 * V_17 )
{
if ( F_13 ( & V_17 -> V_11 ) ) {
F_12 ( V_17 -> V_7 ) ;
F_14 ( & V_17 -> V_14 ) ;
}
}
static void F_27 ( struct V_17 * V_17 )
{
F_16 ( V_15 ) ;
F_17 ( & V_17 -> V_14 , & V_15 , V_16 ) ;
if ( F_13 ( & V_17 -> V_11 ) )
F_12 ( V_17 -> V_7 ) ;
else
F_18 () ;
F_19 ( & V_17 -> V_14 , & V_15 ) ;
F_25 ( V_17 ) ;
}
static void F_28 ( struct V_17 * V_17 )
{
struct V_31 * V_12 ;
V_12 = V_17 -> V_7 -> V_12 ;
V_17 -> V_32 = true ;
F_29 () ;
F_30 ( V_12 , V_17 -> V_18 ) ;
F_31 ( V_33 ) ;
}
static void F_32 ( struct V_17 * * V_34 )
{
int V_35 ;
for ( V_35 = 0 ; V_35 < 512 ; ++ V_35 ) {
if ( V_34 [ V_35 ] == NULL )
continue;
F_33 ( ( unsigned long ) V_34 [ V_35 ] ) ;
}
}
static void F_34 ( struct V_17 * * V_34 )
{
struct V_17 * * V_21 ;
int V_35 ;
for ( V_35 = 0 ; V_35 < 512 ; ++ V_35 ) {
if ( V_34 [ V_35 ] == NULL )
continue;
V_21 = (struct V_17 * * ) V_34 [ V_35 ] ;
F_32 ( V_21 ) ;
}
}
static void F_35 ( struct V_7 * V_8 )
{
struct V_17 * V_17 ;
int V_35 ;
for ( V_35 = 0 ; V_35 < V_8 -> V_36 ; ++ V_35 ) {
V_17 = F_24 ( V_8 , V_35 ) ;
if ( V_17 == NULL )
continue;
F_26 ( V_17 ) ;
F_36 ( & V_17 -> V_37 , V_17 -> V_38 ) ;
F_27 ( V_17 ) ;
F_12 ( V_8 ) ;
}
if ( V_8 -> V_24 == 2 )
F_34 ( V_8 -> V_25 ) ;
else if ( V_8 -> V_24 == 1 )
F_32 ( V_8 -> V_25 ) ;
else if ( V_8 -> V_24 != 0 )
F_37 () ;
F_33 ( ( unsigned long ) V_8 -> V_25 ) ;
}
static struct V_17 * F_38 ( struct V_39 * V_37 )
{
return F_39 ( V_37 , struct V_17 , V_37 ) ;
}
static void F_40 ( struct V_39 * V_37 ,
unsigned long V_40 )
{
struct V_17 * V_17 ;
struct V_7 * V_8 ;
V_17 = F_38 ( V_37 ) ;
V_8 = V_17 -> V_7 ;
F_41 ( V_8 -> V_12 , V_17 -> V_18 , V_40 ) ;
}
static int F_42 ( struct V_39 * V_37 ,
struct V_41 * V_38 ,
unsigned long V_42 ,
unsigned long V_43 )
{
for (; V_42 < V_43 ; V_42 += V_44 )
F_40 ( V_37 , V_42 ) ;
return 0 ;
}
static void F_43 ( struct V_39 * V_37 ,
struct V_41 * V_38 ,
unsigned long V_40 )
{
F_40 ( V_37 , V_40 ) ;
}
static void F_44 ( struct V_39 * V_37 ,
struct V_41 * V_38 ,
unsigned long V_42 , unsigned long V_43 )
{
struct V_17 * V_17 ;
struct V_7 * V_8 ;
unsigned long V_9 ;
V_17 = F_38 ( V_37 ) ;
V_8 = V_17 -> V_7 ;
F_5 ( & V_17 -> V_28 , V_9 ) ;
if ( V_17 -> V_45 == 0 ) {
F_45 ( V_8 -> V_12 ,
V_17 -> V_18 ,
F_46 ( V_46 ) ) ;
}
V_17 -> V_45 += 1 ;
F_7 ( & V_17 -> V_28 , V_9 ) ;
}
static void F_47 ( struct V_39 * V_37 ,
struct V_41 * V_38 ,
unsigned long V_42 , unsigned long V_43 )
{
struct V_17 * V_17 ;
struct V_7 * V_8 ;
unsigned long V_9 ;
V_17 = F_38 ( V_37 ) ;
V_8 = V_17 -> V_7 ;
F_5 ( & V_17 -> V_28 , V_9 ) ;
V_17 -> V_45 -= 1 ;
if ( V_17 -> V_45 == 0 ) {
F_45 ( V_8 -> V_12 ,
V_17 -> V_18 ,
F_46 ( V_17 -> V_38 -> V_47 ) ) ;
}
F_7 ( & V_17 -> V_28 , V_9 ) ;
}
static void F_48 ( struct V_39 * V_37 , struct V_41 * V_38 )
{
struct V_17 * V_17 ;
struct V_7 * V_8 ;
bool V_48 ;
F_49 () ;
V_17 = F_38 ( V_37 ) ;
V_8 = V_17 -> V_7 ;
V_48 = ! V_17 -> V_32 ;
if ( V_48 && V_17 -> V_7 -> V_49 )
V_8 -> V_49 ( V_8 -> V_2 , V_17 -> V_18 ) ;
F_28 ( V_17 ) ;
}
static void F_50 ( struct V_17 * V_17 ,
T_1 V_50 , int V_51 )
{
unsigned long V_9 ;
F_5 ( & V_17 -> V_28 , V_9 ) ;
V_17 -> V_52 [ V_50 ] . V_51 = V_51 ;
F_7 ( & V_17 -> V_28 , V_9 ) ;
}
static void F_51 ( struct V_7 * V_8 ,
struct V_17 * V_17 ,
T_1 V_50 )
{
unsigned long V_9 ;
F_5 ( & V_17 -> V_28 , V_9 ) ;
if ( F_13 ( & V_17 -> V_52 [ V_50 ] . V_53 ) &&
V_17 -> V_52 [ V_50 ] . V_54 ) {
F_52 ( V_8 -> V_2 , V_17 -> V_18 ,
V_17 -> V_52 [ V_50 ] . V_51 , V_50 ) ;
V_17 -> V_52 [ V_50 ] . V_54 = false ;
V_17 -> V_52 [ V_50 ] . V_51 = V_55 ;
}
F_7 ( & V_17 -> V_28 , V_9 ) ;
}
static void F_53 ( struct V_56 * V_57 )
{
struct V_58 * V_58 = F_39 ( V_57 , struct V_58 , V_57 ) ;
int V_59 , V_60 ;
struct V_61 * V_61 ;
V_60 = ! ! ( V_58 -> V_9 & V_62 ) ;
F_54 ( & V_58 -> V_63 -> V_38 -> V_64 ) ;
V_59 = F_55 ( NULL , V_58 -> V_63 -> V_38 ,
V_58 -> V_40 , 1 , V_60 , 0 , & V_61 , NULL ) ;
F_56 ( & V_58 -> V_63 -> V_38 -> V_64 ) ;
if ( V_59 == 1 ) {
F_57 ( V_61 ) ;
} else if ( V_58 -> V_8 -> V_65 ) {
int V_51 ;
V_51 = V_58 -> V_8 -> V_65 ( V_58 -> V_8 -> V_2 ,
V_58 -> V_18 ,
V_58 -> V_40 ,
V_58 -> V_9 ) ;
switch ( V_51 ) {
case V_66 :
F_50 ( V_58 -> V_63 , V_58 -> V_50 , V_55 ) ;
break;
case V_67 :
F_50 ( V_58 -> V_63 , V_58 -> V_50 , V_68 ) ;
break;
case V_69 :
F_50 ( V_58 -> V_63 , V_58 -> V_50 , V_70 ) ;
break;
default:
F_37 () ;
}
} else {
F_50 ( V_58 -> V_63 , V_58 -> V_50 , V_68 ) ;
}
F_51 ( V_58 -> V_8 , V_58 -> V_63 , V_58 -> V_50 ) ;
F_26 ( V_58 -> V_63 ) ;
F_11 ( V_58 ) ;
}
static int F_58 ( struct V_71 * V_72 , unsigned long V_73 , void * V_74 )
{
struct V_75 * V_76 ;
struct V_17 * V_17 ;
struct V_7 * V_8 ;
unsigned long V_9 ;
struct V_58 * V_58 ;
bool V_54 ;
T_1 V_50 ;
int V_27 ;
V_76 = V_74 ;
V_50 = V_76 -> V_50 & 0x1ff ;
V_54 = ( V_76 -> V_50 >> 9 ) & 1 ;
V_27 = V_77 ;
V_8 = F_4 ( V_76 -> F_1 ) ;
if ( V_8 == NULL )
goto V_78;
V_17 = F_24 ( V_8 , V_76 -> V_18 ) ;
if ( V_17 == NULL || V_17 -> V_32 ) {
F_52 ( V_8 -> V_2 , V_76 -> V_18 ,
V_68 , V_50 ) ;
goto V_79;
}
F_5 ( & V_17 -> V_28 , V_9 ) ;
F_6 ( & V_17 -> V_52 [ V_50 ] . V_53 ) ;
if ( V_54 )
V_17 -> V_52 [ V_50 ] . V_54 = true ;
F_7 ( & V_17 -> V_28 , V_9 ) ;
V_58 = F_59 ( sizeof( * V_58 ) , V_26 ) ;
if ( V_58 == NULL ) {
F_51 ( V_8 , V_17 , V_50 ) ;
goto V_79;
}
V_58 -> V_8 = V_8 ;
V_58 -> V_40 = V_76 -> V_40 ;
V_58 -> V_63 = V_17 ;
V_58 -> V_50 = V_50 ;
V_58 -> V_54 = V_54 ;
V_58 -> V_18 = V_76 -> V_18 ;
V_58 -> V_9 = V_76 -> V_9 ;
F_60 ( & V_58 -> V_57 , F_53 ) ;
F_61 ( V_33 , & V_58 -> V_57 ) ;
V_27 = V_80 ;
V_79:
if ( V_27 != V_80 && V_17 )
F_26 ( V_17 ) ;
F_12 ( V_8 ) ;
V_78:
return V_27 ;
}
int F_62 ( struct V_1 * V_2 , int V_18 ,
struct V_81 * V_82 )
{
struct V_17 * V_17 ;
struct V_7 * V_8 ;
struct V_41 * V_38 ;
T_1 V_3 ;
int V_27 ;
F_49 () ;
if ( ! F_63 () )
return - V_83 ;
V_3 = F_1 ( V_2 ) ;
V_8 = F_4 ( V_3 ) ;
if ( V_8 == NULL )
return - V_84 ;
V_27 = - V_84 ;
if ( V_18 < 0 || V_18 >= V_8 -> V_36 )
goto V_78;
V_27 = - V_29 ;
V_17 = F_59 ( sizeof( * V_17 ) , V_85 ) ;
if ( V_17 == NULL )
goto V_78;
F_64 ( & V_17 -> V_11 , 1 ) ;
F_65 ( & V_17 -> V_14 ) ;
F_66 ( & V_17 -> V_28 ) ;
V_38 = F_67 ( V_82 ) ;
V_17 -> V_38 = V_38 ;
V_17 -> V_7 = V_8 ;
V_17 -> V_18 = V_18 ;
V_17 -> V_32 = true ;
V_17 -> V_37 . V_86 = & V_87 ;
if ( V_17 -> V_38 == NULL )
goto V_88;
F_68 ( & V_17 -> V_37 , V_38 ) ;
V_27 = F_22 ( V_8 , V_17 , V_18 ) ;
if ( V_27 )
goto V_89;
V_27 = F_45 ( V_8 -> V_12 , V_18 ,
F_46 ( V_17 -> V_38 -> V_47 ) ) ;
if ( V_27 )
goto V_90;
V_17 -> V_32 = false ;
F_69 ( V_38 ) ;
return 0 ;
V_90:
F_23 ( V_8 , V_18 ) ;
V_89:
F_36 ( & V_17 -> V_37 , V_38 ) ;
V_88:
F_69 ( V_38 ) ;
F_25 ( V_17 ) ;
V_78:
F_12 ( V_8 ) ;
return V_27 ;
}
void F_70 ( struct V_1 * V_2 , int V_18 )
{
struct V_17 * V_17 ;
struct V_7 * V_8 ;
T_1 V_3 ;
F_49 () ;
if ( ! F_63 () )
return;
V_3 = F_1 ( V_2 ) ;
V_8 = F_4 ( V_3 ) ;
if ( V_8 == NULL )
return;
if ( V_18 < 0 || V_18 >= V_8 -> V_36 )
goto V_78;
V_17 = F_24 ( V_8 , V_18 ) ;
if ( V_17 == NULL )
goto V_78;
F_26 ( V_17 ) ;
F_23 ( V_8 , V_17 -> V_18 ) ;
F_36 ( & V_17 -> V_37 , V_17 -> V_38 ) ;
F_27 ( V_17 ) ;
V_78:
F_12 ( V_8 ) ;
F_12 ( V_8 ) ;
}
int F_71 ( struct V_1 * V_2 , int V_91 )
{
struct V_7 * V_8 ;
unsigned long V_9 ;
int V_27 , V_92 ;
T_1 V_3 ;
F_49 () ;
if ( ! F_63 () )
return - V_83 ;
if ( V_91 <= 0 || V_91 > ( V_93 + 1 ) )
return - V_84 ;
V_3 = F_1 ( V_2 ) ;
V_8 = F_59 ( sizeof( * V_8 ) , V_85 ) ;
if ( V_8 == NULL )
return - V_29 ;
F_66 ( & V_8 -> V_28 ) ;
F_65 ( & V_8 -> V_14 ) ;
V_8 -> V_2 = V_2 ;
V_8 -> V_3 = V_3 ;
V_92 = V_91 ;
for ( V_8 -> V_24 = 0 ; ( V_92 - 1 ) & ~ 0x1ff ; V_92 >>= 9 )
V_8 -> V_24 += 1 ;
F_64 ( & V_8 -> V_11 , 1 ) ;
V_8 -> V_36 = V_91 ;
V_27 = - V_29 ;
V_8 -> V_25 = ( void * ) F_21 ( V_85 ) ;
if ( V_8 -> V_25 == NULL )
goto V_94;
V_8 -> V_12 = F_72 ( & V_95 ) ;
if ( V_8 -> V_12 == NULL )
goto V_96;
F_73 ( V_8 -> V_12 ) ;
V_27 = F_74 ( V_8 -> V_12 , V_91 ) ;
if ( V_27 )
goto V_97;
V_27 = F_75 ( V_8 -> V_12 , & V_2 -> V_13 ) ;
if ( V_27 != 0 )
goto V_97;
F_5 ( & V_10 , V_9 ) ;
if ( F_2 ( V_3 ) != NULL ) {
F_7 ( & V_10 , V_9 ) ;
V_27 = - V_98 ;
goto V_97;
}
F_76 ( & V_8 -> V_99 , & V_100 ) ;
F_7 ( & V_10 , V_9 ) ;
return 0 ;
V_97:
F_10 ( V_8 -> V_12 ) ;
V_96:
F_33 ( ( unsigned long ) V_8 -> V_25 ) ;
V_94:
F_11 ( V_8 ) ;
return V_27 ;
}
void F_77 ( struct V_1 * V_2 )
{
struct V_7 * V_8 ;
unsigned long V_9 ;
T_1 V_3 ;
if ( ! F_63 () )
return;
V_3 = F_1 ( V_2 ) ;
F_5 ( & V_10 , V_9 ) ;
V_8 = F_2 ( V_3 ) ;
if ( V_8 == NULL ) {
F_7 ( & V_10 , V_9 ) ;
return;
}
F_78 ( & V_8 -> V_99 ) ;
F_7 ( & V_10 , V_9 ) ;
F_35 ( V_8 ) ;
F_15 ( V_8 ) ;
}
int F_79 ( struct V_1 * V_2 ,
T_2 V_101 )
{
struct V_7 * V_8 ;
unsigned long V_9 ;
T_1 V_3 ;
int V_27 ;
if ( ! F_63 () )
return - V_83 ;
V_3 = F_1 ( V_2 ) ;
F_5 ( & V_10 , V_9 ) ;
V_27 = - V_84 ;
V_8 = F_2 ( V_3 ) ;
if ( V_8 == NULL )
goto V_30;
V_8 -> V_65 = V_101 ;
V_27 = 0 ;
V_30:
F_7 ( & V_10 , V_9 ) ;
return V_27 ;
}
int F_80 ( struct V_1 * V_2 ,
T_3 V_101 )
{
struct V_7 * V_8 ;
unsigned long V_9 ;
T_1 V_3 ;
int V_27 ;
if ( ! F_63 () )
return - V_83 ;
V_3 = F_1 ( V_2 ) ;
F_5 ( & V_10 , V_9 ) ;
V_27 = - V_84 ;
V_8 = F_2 ( V_3 ) ;
if ( V_8 == NULL )
goto V_30;
V_8 -> V_49 = V_101 ;
V_27 = 0 ;
V_30:
F_7 ( & V_10 , V_9 ) ;
return V_27 ;
}
static int T_4 F_81 ( void )
{
int V_27 ;
F_82 ( L_1 ) ;
if ( ! F_63 () ) {
F_82 ( L_2 ) ;
return 0 ;
}
F_66 ( & V_10 ) ;
V_27 = - V_29 ;
V_33 = F_83 ( L_3 ) ;
if ( V_33 == NULL )
goto V_78;
V_27 = - V_29 ;
V_46 = ( V_102 * ) F_21 ( V_85 ) ;
if ( V_46 == NULL )
goto V_103;
F_84 ( & V_104 ) ;
return 0 ;
V_103:
F_85 ( V_33 ) ;
V_78:
return V_27 ;
}
static void T_5 F_86 ( void )
{
struct V_7 * V_8 ;
int V_35 ;
if ( ! F_63 () )
return;
F_87 ( & V_104 ) ;
F_31 ( V_33 ) ;
for ( V_35 = 0 ; V_35 < V_105 ; ++ V_35 ) {
V_8 = F_4 ( V_35 ) ;
if ( V_8 == NULL )
continue;
F_88 ( 1 ) ;
F_12 ( V_8 ) ;
F_77 ( V_8 -> V_2 ) ;
}
F_85 ( V_33 ) ;
F_33 ( ( unsigned long ) V_46 ) ;
}
