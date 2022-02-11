int F_1 ( T_1 V_1 , struct V_2 * V_3 )
{
T_2 V_4 , V_5 , V_6 ;
T_3 V_7 , V_8 ;
T_4 V_9 ;
T_5 V_10 ;
memset ( V_3 , 0 , sizeof( * V_3 ) ) ;
V_10 = F_2 ( V_1 , & V_4 , & V_5 , & V_6 ,
& V_7 , & V_8 ) ;
if ( V_10 ) {
F_3 ( L_1 ,
V_1 , V_10 ) ;
return - V_11 ;
}
V_9 = F_4 ( V_4 ) ;
if ( V_9 & V_12 )
V_3 -> V_4 |= V_13 ;
if ( V_9 & V_14 )
V_3 -> V_4 |= V_15 ;
if ( V_9 & V_16 )
V_3 -> V_4 |= V_17 ;
if ( V_9 & V_18 )
V_3 -> V_4 |= V_19 ;
if ( V_9 & V_20 )
V_3 -> V_4 |= V_21 ;
V_3 -> V_5 = F_4 ( V_5 ) ;
V_3 -> V_6 = F_4 ( V_6 ) ;
V_3 -> V_7 = F_5 ( V_7 ) ;
V_3 -> V_8 = F_5 ( V_8 ) ;
V_3 -> V_22 = F_6 ( V_3 -> V_5 , 1u << V_3 -> V_7 ) ;
if ( ! V_3 -> V_22 ) {
F_3 ( L_2 , V_1 ) ;
return - V_23 ;
}
V_3 -> V_1 = V_1 ;
if ( ! V_3 -> V_6 )
return 0 ;
if ( V_3 -> V_6 == V_3 -> V_5 ) {
V_3 -> V_24 = V_3 -> V_22 ;
return 0 ;
}
V_3 -> V_24 = F_6 ( V_3 -> V_6 , 1u << V_3 -> V_7 ) ;
if ( ! V_3 -> V_24 ) {
F_3 ( L_3 , V_1 ) ;
return - V_23 ;
}
return 0 ;
}
int F_7 ( T_1 V_1 , T_1 V_25 , T_6 V_26 , T_1 V_27 )
{
T_5 V_10 ;
for (; ; ) {
V_10 = F_8 ( V_1 , V_25 , V_26 , V_27 ) ;
if ( V_10 != V_28 )
break;
F_9 ( 1 ) ;
}
return V_10 == 0 ? 0 : - V_29 ;
}
int F_10 ( T_1 V_30 , struct V_31 * V_32 , T_6 V_26 ,
T_3 * V_33 , T_1 V_34 , bool V_35 )
{
T_5 V_10 = 0 ;
T_2 V_36 ;
T_3 V_37 ;
T_4 V_4 , V_38 ;
if ( V_34 ) {
if ( F_11 ( ! V_33 ) )
return - V_11 ;
V_38 = F_12 ( V_33 ) ;
} else
V_38 = 0 ;
V_32 -> V_39 = V_34 ? ( ( 1u << ( V_34 - 2 ) ) - 1 ) : 0 ;
V_32 -> V_40 = 0 ;
V_32 -> V_41 = 0 ;
V_10 = F_13 ( V_30 , V_26 , NULL , NULL ,
& V_36 ,
& V_37 ,
NULL ) ;
if ( V_10 ) {
F_3 ( L_4 , V_10 , V_26 ) ;
V_10 = - V_42 ;
goto V_43;
}
V_32 -> V_44 = F_4 ( V_36 ) ;
V_4 = V_45 | V_46 ;
if ( V_35 ) {
V_32 -> V_47 = F_5 ( V_37 ) ;
V_4 |= V_48 ;
}
for (; ; ) {
V_10 = F_14 ( V_30 , V_26 , V_38 , V_34 , V_4 ) ;
if ( V_10 != V_28 )
break;
F_9 ( 1 ) ;
}
if ( V_10 ) {
F_3 ( L_5 , V_10 , V_26 ) ;
V_10 = - V_42 ;
} else {
F_15 () ;
V_32 -> V_33 = V_33 ;
}
V_43:
return V_10 ;
}
static void F_16 ( T_1 V_30 , struct V_31 * V_32 , T_6 V_26 )
{
T_5 V_10 ;
for (; ; ) {
V_10 = F_14 ( V_30 , V_26 , 0 , 0 , 0 ) ;
if ( V_10 != V_28 )
break;
F_9 ( 1 ) ;
}
if ( V_10 )
F_3 ( L_6 , V_10 , V_26 ) ;
}
void F_17 ( T_1 V_30 , struct V_31 * V_32 , T_6 V_26 )
{
F_16 ( V_30 , V_32 , V_26 ) ;
}
static int F_18 ( unsigned int V_49 , struct V_50 * V_51 , T_6 V_26 )
{
struct V_31 * V_32 = & V_51 -> V_52 [ V_26 ] ;
T_3 * V_33 ;
V_33 = F_19 ( V_49 , V_53 ) ;
if ( F_20 ( V_33 ) )
return F_21 ( V_33 ) ;
return F_10 ( F_22 ( V_49 ) ,
V_32 , V_26 , V_33 , V_53 , false ) ;
}
static void F_23 ( unsigned int V_49 , struct V_50 * V_51 , T_6 V_26 )
{
struct V_31 * V_32 = & V_51 -> V_52 [ V_26 ] ;
unsigned int V_54 ;
F_16 ( F_22 ( V_49 ) , V_32 , V_26 ) ;
V_54 = F_24 ( V_53 ) ;
F_25 ( ( unsigned long ) V_32 -> V_33 , V_54 ) ;
V_32 -> V_33 = NULL ;
}
static bool F_26 ( struct V_55 * V_56 )
{
return F_27 ( V_56 , L_7 ) ;
}
static int F_28 ( unsigned int V_49 , struct V_50 * V_51 )
{
struct V_55 * V_57 ;
unsigned int V_58 ;
T_5 V_59 ;
V_57 = F_29 ( V_49 , NULL ) ;
if ( V_57 ) {
if ( F_30 ( V_57 , L_8 , & V_58 ) < 0 )
V_58 = 0 ;
}
for (; ; ) {
V_59 = F_31 ( V_58 ) ;
if ( V_59 == V_28 ) {
F_9 ( 1 ) ;
continue;
}
if ( V_59 < 0 ) {
F_3 ( L_9 , V_49 ) ;
return - V_29 ;
}
V_51 -> V_60 = V_59 ;
break;
}
return 0 ;
}
T_1 F_32 ( void )
{
T_5 V_10 ;
for (; ; ) {
V_10 = F_31 ( V_61 ) ;
if ( V_10 != V_28 )
break;
F_9 ( 1 ) ;
}
if ( V_10 < 0 )
return 0 ;
return V_10 ;
}
void F_33 ( T_1 V_59 )
{
for (; ; ) {
T_5 V_10 = F_34 ( V_59 ) ;
if ( V_10 != V_28 )
break;
F_9 ( 1 ) ;
}
}
static void F_35 ( unsigned int V_49 , struct V_50 * V_51 )
{
T_5 V_10 ;
if ( ! V_51 -> V_60 )
return;
for (; ; ) {
V_10 = F_34 ( V_51 -> V_60 ) ;
if ( V_10 == V_28 ) {
F_9 ( 1 ) ;
continue;
}
V_51 -> V_60 = 0 ;
break;
}
}
static void F_36 ( void )
{
F_37 ( V_62 ) ;
}
static void F_38 ( struct V_50 * V_51 )
{
T_6 V_63 , V_64 ;
T_7 V_65 ;
V_65 = F_39 ( F_40 ( V_66 + V_67 ) ) ;
F_41 () ;
V_64 = V_65 & 0xff ;
V_63 = F_42 ( V_68 , ( V_65 >> 8 ) ) ;
switch( V_63 ) {
case V_69 :
break;
case V_70 :
if ( V_64 == 0xff )
return;
V_51 -> V_71 |= 1 << V_64 ;
if ( V_64 >= V_51 -> V_64 )
F_3 ( L_10 ,
F_43 () , V_64 , V_51 -> V_64 ) ;
V_51 -> V_64 = V_64 ;
break;
case V_72 :
case V_73 :
F_3 ( L_11 ,
F_43 () , V_63 ) ;
return;
}
}
static void F_44 ( T_1 V_1 )
{
F_45 ( V_1 ) ;
}
static void F_46 ( unsigned int V_49 , struct V_50 * V_51 )
{
T_5 V_10 ;
T_1 V_74 ;
T_2 V_75 ;
T_4 V_76 ;
if ( V_77 == V_78 )
return;
V_74 = V_77 + V_49 ;
F_47 ( L_12 , V_49 , V_74 ) ;
for (; ; ) {
V_10 = F_48 ( V_74 , V_79 , 0 ) ;
if ( V_10 != V_28 )
break;
F_9 ( 1 ) ;
}
if ( V_10 ) {
F_3 ( L_13 , V_49 ) ;
return;
}
V_10 = F_49 ( V_74 , NULL , & V_75 , NULL , NULL ) ;
if ( V_10 ) {
F_3 ( L_14 , V_49 ) ;
return;
}
V_76 = F_4 ( V_75 ) ;
F_47 ( L_15 , V_76 ) ;
F_47 ( L_16 ,
F_50 ( V_66 + V_80 + V_81 ) ) ;
F_51 ( V_66 + V_80 + V_82 , 0xff ) ;
F_51 ( V_66 + V_80 + V_81 ,
V_83 | V_76 ) ;
F_47 ( L_17 ,
F_50 ( V_66 + V_80 + V_81 ) ) ;
}
static void F_52 ( unsigned int V_49 , struct V_50 * V_51 )
{
T_5 V_10 ;
T_1 V_74 ;
if ( V_77 == V_78 )
return;
F_53 ( V_66 + V_84 ) ;
V_74 = V_77 + V_49 ;
for (; ; ) {
V_10 = F_48 ( V_74 , 0 , 0 ) ;
if ( V_10 != V_28 )
break;
F_9 ( 1 ) ;
}
}
void F_54 ( T_1 V_1 )
{
F_55 ( V_85 , V_1 ) ;
}
static bool F_56 ( struct V_55 * V_57 )
{
int V_10 ;
if ( F_30 ( V_57 , L_18 ,
& V_86 ) < 0 )
return true ;
V_10 = F_57 ( V_57 , L_19 , 4 ) ;
if ( V_10 < 0 ) {
F_3 ( L_20 , V_10 ) ;
return false ;
}
V_87 = V_10 ;
if ( V_10 == 0 )
return true ;
V_88 = F_58 ( 4 * V_87 ,
V_89 ) ;
if ( F_11 ( ! V_88 ) )
return false ;
V_10 = F_59 ( V_57 , L_19 ,
V_88 ,
V_87 ) ;
if ( V_10 < 0 ) {
F_3 ( L_21 , V_10 ) ;
return false ;
}
V_90 = F_60 ( L_22 ,
V_86 ,
V_86 ,
0 , NULL ) ;
if ( ! V_90 ) {
F_3 ( L_23 ) ;
return false ;
}
return true ;
}
static void F_61 ( void )
{
F_47 ( L_24 , V_91 ) ;
V_77 = F_62 ( V_91 ) ;
if ( F_11 ( V_77 == V_78 ) )
F_3 ( L_25 ) ;
F_47 ( L_26 ,
V_77 , V_91 ) ;
}
T_1 F_63 ( void )
{
return V_53 ;
}
bool T_8 F_64 ( void )
{
struct V_55 * V_57 ;
struct V_92 V_93 ;
void T_9 * V_94 ;
struct V_95 * V_96 ;
T_6 V_97 = 7 ;
const T_3 * V_98 ;
T_1 V_99 , V_49 ;
T_5 V_10 ;
if ( V_100 )
return false ;
F_65 ( L_27 ) ;
V_57 = F_66 ( NULL , NULL , L_28 ) ;
if ( ! V_57 ) {
F_65 ( L_29 ) ;
return false ;
}
F_65 ( L_30 , V_57 ) ;
if ( F_67 ( V_57 , 1 , & V_93 ) ) {
F_3 ( L_31 ) ;
return false ;
}
V_94 = F_6 ( V_93 . V_101 , F_68 ( & V_93 ) ) ;
if ( ! V_94 ) {
F_3 ( L_32 ) ;
return false ;
}
if ( F_30 ( V_57 , L_33 , & V_99 ) == 0 )
V_97 = V_99 - 1 ;
F_69 (np, L_34 , prop, p, val) {
V_53 = V_99 ;
if ( V_99 == V_102 )
break;
}
F_70 (cpu)
F_71 ( V_49 , V_93 . V_101 , V_94 ) ;
F_56 ( V_57 ) ;
V_10 = F_37 ( V_103 ) ;
if ( V_10 ) {
F_3 ( L_35 , V_10 ) ;
return false ;
}
F_61 () ;
if ( ! F_72 ( & V_104 , V_94 , V_105 ,
V_97 ) ) {
F_37 ( V_62 ) ;
return false ;
}
F_73 ( L_36 , 1 << ( V_53 - 10 ) ) ;
return true ;
}
static bool F_74 ( void )
{
T_1 V_106 ;
void * V_98 ;
for ( V_106 = 0 ; V_106 < V_87 ; V_106 ++ ) {
T_1 V_107 = V_88 [ V_106 ] ;
V_98 = F_75 ( V_90 , V_89 ) ;
if ( ! V_98 ) {
F_3 ( L_37 ) ;
return false ;
}
F_76 ( V_107 , F_12 ( V_98 ) ) ;
}
return true ;
}
T_1 F_62 ( T_1 V_108 )
{
T_5 V_10 ;
T_1 V_34 ;
V_34 = F_77 ( V_108 ) - 1 ;
if ( V_108 > ( 1 << V_34 ) )
V_34 ++ ;
F_47 ( L_38 ,
V_108 , V_34 ) ;
for (; ; ) {
V_10 = F_78 ( V_34 ) ;
switch ( V_10 ) {
case V_28 :
F_9 ( 1 ) ;
break;
case V_109 :
if ( ! F_74 () )
return V_78 ;
break;
default:
if ( V_10 < 0 ) {
F_3 ( L_39 ,
V_34 , V_10 ) ;
return V_78 ;
}
return V_10 ;
}
}
}
void F_79 ( T_1 V_110 )
{
T_5 V_10 ;
if ( V_110 == V_78 )
return;
V_10 = F_80 ( V_110 ) ;
if ( V_10 < 0 )
F_81 ( L_40 , V_10 ) ;
}
int F_82 ( T_1 V_30 )
{
T_5 V_10 ;
for (; ; ) {
V_10 = F_48 ( V_30 , V_79 , 0 ) ;
if ( V_10 != V_28 )
break;
F_9 ( 1 ) ;
}
return V_10 ? - V_42 : 0 ;
}
int F_83 ( T_1 V_30 )
{
T_5 V_10 ;
for (; ; ) {
V_10 = F_48 ( V_30 , 0 , 0 ) ;
if ( V_10 != V_28 )
break;
F_9 ( 1 ) ;
}
return V_10 ? - V_42 : 0 ;
}
int F_84 ( T_1 V_30 , T_1 * V_111 , T_1 * V_112 )
{
T_2 V_75 ;
T_3 V_113 ;
T_5 V_10 ;
V_10 = F_49 ( V_30 , NULL , & V_75 , NULL , & V_113 ) ;
if ( V_10 )
return - V_42 ;
* V_111 = F_4 ( V_75 ) & 0xffffffffu ;
* V_112 = F_5 ( V_113 ) ;
return 0 ;
}
