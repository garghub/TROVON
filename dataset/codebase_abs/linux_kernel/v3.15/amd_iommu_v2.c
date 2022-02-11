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
unsigned long V_9 ;
F_3 ( & V_10 , V_9 ) ;
V_8 = V_11 [ V_3 ] ;
if ( V_8 != NULL )
F_4 ( & V_8 -> V_12 ) ;
F_5 ( & V_10 , V_9 ) ;
return V_8 ;
}
static void F_6 ( struct V_7 * V_8 )
{
F_7 ( V_8 -> V_13 , & V_8 -> V_2 -> V_14 ) ;
F_8 ( V_8 -> V_13 ) ;
F_9 ( V_8 ) ;
}
static void F_10 ( struct V_7 * V_8 )
{
if ( F_11 ( & V_8 -> V_12 ) )
F_12 ( & V_8 -> V_15 ) ;
}
static void F_13 ( struct V_7 * V_8 )
{
F_14 ( V_16 ) ;
F_15 ( & V_8 -> V_15 , & V_16 , V_17 ) ;
if ( ! F_11 ( & V_8 -> V_12 ) )
F_16 () ;
F_17 ( & V_8 -> V_15 , & V_16 ) ;
F_6 ( V_8 ) ;
}
static void F_18 ( struct V_18 * V_18 )
{
F_19 ( & V_19 ) ;
F_20 ( & V_18 -> V_20 , & V_21 ) ;
F_21 ( & V_19 ) ;
}
static void F_22 ( struct V_18 * V_18 )
{
F_23 ( & V_18 -> V_20 ) ;
}
static void F_24 ( struct V_18 * V_18 )
{
F_19 ( & V_19 ) ;
F_22 ( V_18 ) ;
F_21 ( & V_19 ) ;
}
static struct V_18 * * F_25 ( struct V_7 * V_8 ,
int V_22 , bool V_23 )
{
struct V_18 * * V_24 , * * V_25 ;
int V_26 , V_27 ;
V_26 = V_8 -> V_28 ;
V_24 = V_8 -> V_29 ;
while ( true ) {
V_27 = ( V_22 >> ( 9 * V_26 ) ) & 0x1ff ;
V_25 = & V_24 [ V_27 ] ;
if ( V_26 == 0 )
break;
if ( * V_25 == NULL ) {
if ( ! V_23 )
return NULL ;
* V_25 = ( void * ) F_26 ( V_30 ) ;
if ( * V_25 == NULL )
return NULL ;
}
V_24 = (struct V_18 * * ) * V_25 ;
V_26 -= 1 ;
}
return V_25 ;
}
static int F_27 ( struct V_7 * V_8 ,
struct V_18 * V_18 ,
int V_22 )
{
struct V_18 * * V_25 ;
unsigned long V_9 ;
int V_31 ;
F_3 ( & V_8 -> V_32 , V_9 ) ;
V_25 = F_25 ( V_8 , V_22 , true ) ;
V_31 = - V_33 ;
if ( V_25 == NULL )
goto V_34;
V_31 = - V_33 ;
if ( * V_25 != NULL )
goto V_34;
* V_25 = V_18 ;
V_31 = 0 ;
V_34:
F_5 ( & V_8 -> V_32 , V_9 ) ;
return V_31 ;
}
static void F_28 ( struct V_7 * V_8 , int V_22 )
{
struct V_18 * * V_25 ;
unsigned long V_9 ;
F_3 ( & V_8 -> V_32 , V_9 ) ;
V_25 = F_25 ( V_8 , V_22 , true ) ;
if ( V_25 == NULL )
goto V_34;
* V_25 = NULL ;
V_34:
F_5 ( & V_8 -> V_32 , V_9 ) ;
}
static struct V_18 * F_29 ( struct V_7 * V_8 ,
int V_22 )
{
struct V_18 * * V_25 , * V_31 = NULL ;
unsigned long V_9 ;
F_3 ( & V_8 -> V_32 , V_9 ) ;
V_25 = F_25 ( V_8 , V_22 , false ) ;
if ( V_25 == NULL )
goto V_34;
V_31 = * V_25 ;
if ( V_31 )
F_4 ( & V_31 -> V_12 ) ;
V_34:
F_5 ( & V_8 -> V_32 , V_9 ) ;
return V_31 ;
}
static void F_30 ( struct V_18 * V_18 )
{
F_9 ( V_18 ) ;
}
static void F_31 ( struct V_18 * V_18 )
{
if ( F_11 ( & V_18 -> V_12 ) ) {
F_10 ( V_18 -> V_7 ) ;
F_12 ( & V_18 -> V_15 ) ;
}
}
static void F_32 ( struct V_18 * V_18 )
{
F_14 ( V_16 ) ;
F_15 ( & V_18 -> V_15 , & V_16 , V_17 ) ;
if ( F_11 ( & V_18 -> V_12 ) )
F_10 ( V_18 -> V_7 ) ;
else
F_16 () ;
F_17 ( & V_18 -> V_15 , & V_16 ) ;
F_33 ( V_18 -> V_35 ) ;
F_30 ( V_18 ) ;
}
static void F_34 ( struct V_18 * V_18 )
{
struct V_36 * V_13 ;
V_13 = V_18 -> V_7 -> V_13 ;
F_35 ( V_13 , V_18 -> V_22 ) ;
F_28 ( V_18 -> V_7 , V_18 -> V_22 ) ;
F_36 ( V_37 ) ;
F_37 ( & V_18 -> V_38 , V_18 -> V_35 ) ;
F_31 ( V_18 ) ;
}
static void F_38 ( struct V_7 * V_8 , int V_22 )
{
struct V_18 * V_18 ;
V_18 = F_29 ( V_8 , V_22 ) ;
if ( V_18 == NULL )
return;
F_24 ( V_18 ) ;
F_34 ( V_18 ) ;
F_32 ( V_18 ) ;
}
static void F_39 ( struct V_18 * * V_39 )
{
int V_40 ;
for ( V_40 = 0 ; V_40 < 512 ; ++ V_40 ) {
if ( V_39 [ V_40 ] == NULL )
continue;
F_40 ( ( unsigned long ) V_39 [ V_40 ] ) ;
}
}
static void F_41 ( struct V_18 * * V_39 )
{
struct V_18 * * V_25 ;
int V_40 ;
for ( V_40 = 0 ; V_40 < 512 ; ++ V_40 ) {
if ( V_39 [ V_40 ] == NULL )
continue;
V_25 = (struct V_18 * * ) V_39 [ V_40 ] ;
F_39 ( V_25 ) ;
}
}
static void F_42 ( struct V_7 * V_8 )
{
struct V_18 * V_18 ;
int V_40 ;
for ( V_40 = 0 ; V_40 < V_8 -> V_41 ; ++ V_40 ) {
V_18 = F_29 ( V_8 , V_40 ) ;
if ( V_18 == NULL )
continue;
F_31 ( V_18 ) ;
F_38 ( V_8 , V_40 ) ;
}
if ( V_8 -> V_28 == 2 )
F_41 ( V_8 -> V_29 ) ;
else if ( V_8 -> V_28 == 1 )
F_39 ( V_8 -> V_29 ) ;
else if ( V_8 -> V_28 != 0 )
F_43 () ;
F_40 ( ( unsigned long ) V_8 -> V_29 ) ;
}
static struct V_18 * F_44 ( struct V_42 * V_38 )
{
return F_45 ( V_38 , struct V_18 , V_38 ) ;
}
static void F_46 ( struct V_42 * V_38 ,
unsigned long V_43 )
{
struct V_18 * V_18 ;
struct V_7 * V_8 ;
V_18 = F_44 ( V_38 ) ;
V_8 = V_18 -> V_7 ;
F_47 ( V_8 -> V_13 , V_18 -> V_22 , V_43 ) ;
}
static int F_48 ( struct V_42 * V_38 ,
struct V_44 * V_35 ,
unsigned long V_43 )
{
F_46 ( V_38 , V_43 ) ;
return 0 ;
}
static void F_49 ( struct V_42 * V_38 ,
struct V_44 * V_35 ,
unsigned long V_43 ,
T_2 V_45 )
{
F_46 ( V_38 , V_43 ) ;
}
static void F_50 ( struct V_42 * V_38 ,
struct V_44 * V_35 ,
unsigned long V_43 )
{
F_46 ( V_38 , V_43 ) ;
}
static void F_51 ( struct V_42 * V_38 ,
struct V_44 * V_35 ,
unsigned long V_46 , unsigned long V_47 )
{
struct V_18 * V_18 ;
struct V_7 * V_8 ;
V_18 = F_44 ( V_38 ) ;
V_8 = V_18 -> V_7 ;
F_52 ( V_8 -> V_13 , V_18 -> V_22 ,
F_53 ( V_48 ) ) ;
}
static void F_54 ( struct V_42 * V_38 ,
struct V_44 * V_35 ,
unsigned long V_46 , unsigned long V_47 )
{
struct V_18 * V_18 ;
struct V_7 * V_8 ;
V_18 = F_44 ( V_38 ) ;
V_8 = V_18 -> V_7 ;
F_52 ( V_8 -> V_13 , V_18 -> V_22 ,
F_53 ( V_18 -> V_35 -> V_49 ) ) ;
}
static void F_55 ( struct V_18 * V_18 ,
T_1 V_50 , int V_51 )
{
unsigned long V_9 ;
F_3 ( & V_18 -> V_32 , V_9 ) ;
V_18 -> V_52 [ V_50 ] . V_51 = V_51 ;
F_5 ( & V_18 -> V_32 , V_9 ) ;
}
static void F_56 ( struct V_7 * V_8 ,
struct V_18 * V_18 ,
T_1 V_50 )
{
unsigned long V_9 ;
F_3 ( & V_18 -> V_32 , V_9 ) ;
if ( F_11 ( & V_18 -> V_52 [ V_50 ] . V_53 ) &&
V_18 -> V_52 [ V_50 ] . V_54 ) {
F_57 ( V_8 -> V_2 , V_18 -> V_22 ,
V_18 -> V_52 [ V_50 ] . V_51 , V_50 ) ;
V_18 -> V_52 [ V_50 ] . V_54 = false ;
V_18 -> V_52 [ V_50 ] . V_51 = V_55 ;
}
F_5 ( & V_18 -> V_32 , V_9 ) ;
}
static void F_58 ( struct V_56 * V_57 )
{
struct V_58 * V_58 = F_45 ( V_57 , struct V_58 , V_57 ) ;
int V_59 , V_60 ;
struct V_61 * V_61 ;
V_60 = ! ! ( V_58 -> V_9 & V_62 ) ;
F_59 ( & V_58 -> V_63 -> V_35 -> V_64 ) ;
V_59 = F_60 ( V_58 -> V_63 -> V_65 , V_58 -> V_63 -> V_35 ,
V_58 -> V_43 , 1 , V_60 , 0 , & V_61 , NULL ) ;
F_61 ( & V_58 -> V_63 -> V_35 -> V_64 ) ;
if ( V_59 == 1 ) {
F_62 ( V_61 ) ;
} else if ( V_58 -> V_8 -> V_66 ) {
int V_51 ;
V_51 = V_58 -> V_8 -> V_66 ( V_58 -> V_8 -> V_2 ,
V_58 -> V_22 ,
V_58 -> V_43 ,
V_58 -> V_9 ) ;
switch ( V_51 ) {
case V_67 :
F_55 ( V_58 -> V_63 , V_58 -> V_50 , V_55 ) ;
break;
case V_68 :
F_55 ( V_58 -> V_63 , V_58 -> V_50 , V_69 ) ;
break;
case V_70 :
F_55 ( V_58 -> V_63 , V_58 -> V_50 , V_71 ) ;
break;
default:
F_43 () ;
}
} else {
F_55 ( V_58 -> V_63 , V_58 -> V_50 , V_69 ) ;
}
F_56 ( V_58 -> V_8 , V_58 -> V_63 , V_58 -> V_50 ) ;
F_31 ( V_58 -> V_63 ) ;
F_9 ( V_58 ) ;
}
static int F_63 ( struct V_72 * V_73 , unsigned long V_74 , void * V_75 )
{
struct V_76 * V_77 ;
struct V_18 * V_18 ;
struct V_7 * V_8 ;
unsigned long V_9 ;
struct V_58 * V_58 ;
bool V_54 ;
T_1 V_50 ;
int V_31 ;
V_77 = V_75 ;
V_50 = V_77 -> V_50 & 0x1ff ;
V_54 = ( V_77 -> V_50 >> 9 ) & 1 ;
V_31 = V_78 ;
V_8 = F_2 ( V_77 -> F_1 ) ;
if ( V_8 == NULL )
goto V_79;
V_18 = F_29 ( V_8 , V_77 -> V_22 ) ;
if ( V_18 == NULL ) {
F_57 ( V_8 -> V_2 , V_77 -> V_22 ,
V_69 , V_50 ) ;
goto V_80;
}
F_3 ( & V_18 -> V_32 , V_9 ) ;
F_4 ( & V_18 -> V_52 [ V_50 ] . V_53 ) ;
if ( V_54 )
V_18 -> V_52 [ V_50 ] . V_54 = true ;
F_5 ( & V_18 -> V_32 , V_9 ) ;
V_58 = F_64 ( sizeof( * V_58 ) , V_30 ) ;
if ( V_58 == NULL ) {
F_56 ( V_8 , V_18 , V_50 ) ;
goto V_80;
}
V_58 -> V_8 = V_8 ;
V_58 -> V_43 = V_77 -> V_43 ;
V_58 -> V_63 = V_18 ;
V_58 -> V_50 = V_50 ;
V_58 -> V_54 = V_54 ;
V_58 -> V_9 = V_77 -> V_9 ;
F_65 ( & V_58 -> V_57 , F_58 ) ;
F_66 ( V_37 , & V_58 -> V_57 ) ;
V_31 = V_81 ;
V_80:
F_10 ( V_8 ) ;
V_79:
return V_31 ;
}
static int F_67 ( struct V_72 * V_73 , unsigned long V_74 , void * V_75 )
{
struct V_18 * V_18 ;
struct V_82 * V_65 ;
V_65 = V_75 ;
V_83:
F_19 ( & V_19 ) ;
F_68 (pasid_state, &pasid_state_list, list) {
struct V_7 * V_8 ;
int V_22 ;
if ( V_18 -> V_65 != V_65 )
continue;
F_21 ( & V_19 ) ;
V_8 = V_18 -> V_7 ;
V_22 = V_18 -> V_22 ;
if ( V_18 -> V_7 -> V_84 )
V_8 -> V_84 ( V_8 -> V_2 , V_22 ) ;
F_38 ( V_8 , V_22 ) ;
goto V_83;
}
F_21 ( & V_19 ) ;
return V_81 ;
}
int F_69 ( struct V_1 * V_2 , int V_22 ,
struct V_82 * V_65 )
{
struct V_18 * V_18 ;
struct V_7 * V_8 ;
T_1 V_3 ;
int V_31 ;
F_70 () ;
if ( ! F_71 () )
return - V_85 ;
V_3 = F_1 ( V_2 ) ;
V_8 = F_2 ( V_3 ) ;
if ( V_8 == NULL )
return - V_86 ;
V_31 = - V_86 ;
if ( V_22 < 0 || V_22 >= V_8 -> V_41 )
goto V_79;
V_31 = - V_33 ;
V_18 = F_64 ( sizeof( * V_18 ) , V_87 ) ;
if ( V_18 == NULL )
goto V_79;
F_72 ( & V_18 -> V_12 , 1 ) ;
F_73 ( & V_18 -> V_15 ) ;
F_74 ( & V_18 -> V_32 ) ;
V_18 -> V_65 = V_65 ;
V_18 -> V_35 = F_75 ( V_65 ) ;
V_18 -> V_7 = V_8 ;
V_18 -> V_22 = V_22 ;
V_18 -> V_38 . V_88 = & V_89 ;
if ( V_18 -> V_35 == NULL )
goto V_90;
F_76 ( & V_18 -> V_38 , V_18 -> V_35 ) ;
V_31 = F_27 ( V_8 , V_18 , V_22 ) ;
if ( V_31 )
goto V_91;
V_31 = F_52 ( V_8 -> V_13 , V_22 ,
F_53 ( V_18 -> V_35 -> V_49 ) ) ;
if ( V_31 )
goto V_92;
F_18 ( V_18 ) ;
return 0 ;
V_92:
F_28 ( V_8 , V_22 ) ;
V_91:
F_37 ( & V_18 -> V_38 , V_18 -> V_35 ) ;
V_90:
F_30 ( V_18 ) ;
V_79:
F_10 ( V_8 ) ;
return V_31 ;
}
void F_77 ( struct V_1 * V_2 , int V_22 )
{
struct V_7 * V_8 ;
T_1 V_3 ;
F_70 () ;
if ( ! F_71 () )
return;
V_3 = F_1 ( V_2 ) ;
V_8 = F_2 ( V_3 ) ;
if ( V_8 == NULL )
return;
if ( V_22 < 0 || V_22 >= V_8 -> V_41 )
goto V_79;
F_38 ( V_8 , V_22 ) ;
V_79:
F_10 ( V_8 ) ;
}
int F_78 ( struct V_1 * V_2 , int V_93 )
{
struct V_7 * V_8 ;
unsigned long V_9 ;
int V_31 , V_94 ;
T_1 V_3 ;
F_70 () ;
if ( ! F_71 () )
return - V_85 ;
if ( V_93 <= 0 || V_93 > ( V_95 + 1 ) )
return - V_86 ;
V_3 = F_1 ( V_2 ) ;
V_8 = F_64 ( sizeof( * V_8 ) , V_87 ) ;
if ( V_8 == NULL )
return - V_33 ;
F_74 ( & V_8 -> V_32 ) ;
F_73 ( & V_8 -> V_15 ) ;
V_8 -> V_2 = V_2 ;
V_94 = V_93 ;
for ( V_8 -> V_28 = 0 ; ( V_94 - 1 ) & ~ 0x1ff ; V_94 >>= 9 )
V_8 -> V_28 += 1 ;
F_72 ( & V_8 -> V_12 , 1 ) ;
V_8 -> V_41 = V_93 ;
V_31 = - V_33 ;
V_8 -> V_29 = ( void * ) F_26 ( V_87 ) ;
if ( V_8 -> V_29 == NULL )
goto V_96;
V_8 -> V_13 = F_79 ( & V_97 ) ;
if ( V_8 -> V_13 == NULL )
goto V_98;
F_80 ( V_8 -> V_13 ) ;
V_31 = F_81 ( V_8 -> V_13 , V_93 ) ;
if ( V_31 )
goto V_99;
V_31 = F_82 ( V_8 -> V_13 , & V_2 -> V_14 ) ;
if ( V_31 != 0 )
goto V_99;
F_3 ( & V_10 , V_9 ) ;
if ( V_11 [ V_3 ] != NULL ) {
F_5 ( & V_10 , V_9 ) ;
V_31 = - V_100 ;
goto V_99;
}
V_11 [ V_3 ] = V_8 ;
F_5 ( & V_10 , V_9 ) ;
return 0 ;
V_99:
F_8 ( V_8 -> V_13 ) ;
V_98:
F_40 ( ( unsigned long ) V_8 -> V_29 ) ;
V_96:
F_9 ( V_8 ) ;
return V_31 ;
}
void F_83 ( struct V_1 * V_2 )
{
struct V_7 * V_8 ;
unsigned long V_9 ;
T_1 V_3 ;
if ( ! F_71 () )
return;
V_3 = F_1 ( V_2 ) ;
F_3 ( & V_10 , V_9 ) ;
V_8 = V_11 [ V_3 ] ;
if ( V_8 == NULL ) {
F_5 ( & V_10 , V_9 ) ;
return;
}
V_11 [ V_3 ] = NULL ;
F_5 ( & V_10 , V_9 ) ;
F_42 ( V_8 ) ;
F_13 ( V_8 ) ;
}
int F_84 ( struct V_1 * V_2 ,
T_3 V_101 )
{
struct V_7 * V_8 ;
unsigned long V_9 ;
T_1 V_3 ;
int V_31 ;
if ( ! F_71 () )
return - V_85 ;
V_3 = F_1 ( V_2 ) ;
F_3 ( & V_10 , V_9 ) ;
V_31 = - V_86 ;
V_8 = V_11 [ V_3 ] ;
if ( V_8 == NULL )
goto V_34;
V_8 -> V_66 = V_101 ;
V_31 = 0 ;
V_34:
F_5 ( & V_10 , V_9 ) ;
return V_31 ;
}
int F_85 ( struct V_1 * V_2 ,
T_4 V_101 )
{
struct V_7 * V_8 ;
unsigned long V_9 ;
T_1 V_3 ;
int V_31 ;
if ( ! F_71 () )
return - V_85 ;
V_3 = F_1 ( V_2 ) ;
F_3 ( & V_10 , V_9 ) ;
V_31 = - V_86 ;
V_8 = V_11 [ V_3 ] ;
if ( V_8 == NULL )
goto V_34;
V_8 -> V_84 = V_101 ;
V_31 = 0 ;
V_34:
F_5 ( & V_10 , V_9 ) ;
return V_31 ;
}
static int T_5 F_86 ( void )
{
T_6 V_102 ;
int V_31 ;
F_87 ( L_1 ) ;
if ( ! F_71 () ) {
F_87 ( L_2 ) ;
return 0 ;
}
F_74 ( & V_10 ) ;
V_102 = V_103 * sizeof( struct V_7 * ) ;
V_11 = ( void * ) F_88 ( V_87 | V_104 ,
F_89 ( V_102 ) ) ;
if ( V_11 == NULL )
return - V_33 ;
V_31 = - V_33 ;
V_37 = F_90 ( L_3 ) ;
if ( V_37 == NULL )
goto V_90;
V_31 = - V_33 ;
V_48 = ( V_105 * ) F_26 ( V_87 ) ;
if ( V_48 == NULL )
goto V_106;
F_91 ( & V_107 ) ;
F_92 ( V_108 , & V_109 ) ;
return 0 ;
V_106:
F_93 ( V_37 ) ;
V_90:
F_94 ( ( unsigned long ) V_11 , F_89 ( V_102 ) ) ;
return V_31 ;
}
static void T_7 F_95 ( void )
{
struct V_7 * V_8 ;
T_6 V_102 ;
int V_40 ;
if ( ! F_71 () )
return;
F_96 ( V_108 , & V_109 ) ;
F_97 ( & V_107 ) ;
F_36 ( V_37 ) ;
for ( V_40 = 0 ; V_40 < V_103 ; ++ V_40 ) {
V_8 = F_2 ( V_40 ) ;
if ( V_8 == NULL )
continue;
F_98 ( 1 ) ;
F_10 ( V_8 ) ;
F_83 ( V_8 -> V_2 ) ;
}
F_93 ( V_37 ) ;
V_102 = V_103 * sizeof( struct V_7 * ) ;
F_94 ( ( unsigned long ) V_11 , F_89 ( V_102 ) ) ;
F_40 ( ( unsigned long ) V_48 ) ;
}
