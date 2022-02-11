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
unsigned int V_53 ;
struct V_54 * V_55 ;
T_3 * V_33 ;
V_53 = ( V_56 > V_57 ) ?
( V_56 - V_57 ) : 0 ;
V_55 = F_19 ( F_20 ( V_49 ) , V_58 , V_53 ) ;
if ( ! V_55 )
return - V_23 ;
V_33 = ( T_3 * ) F_21 ( V_55 ) ;
memset ( V_33 , 0 , 1 << V_56 ) ;
return F_10 ( F_22 ( V_49 ) ,
V_32 , V_26 , V_33 , V_56 , false ) ;
}
static void F_23 ( unsigned int V_49 , struct V_50 * V_51 , T_6 V_26 )
{
struct V_31 * V_32 = & V_51 -> V_52 [ V_26 ] ;
unsigned int V_53 ;
F_16 ( F_22 ( V_49 ) , V_32 , V_26 ) ;
V_53 = ( V_56 > V_57 ) ?
( V_56 - V_57 ) : 0 ;
F_24 ( ( unsigned long ) V_32 -> V_33 , V_53 ) ;
V_32 -> V_33 = NULL ;
}
static bool F_25 ( struct V_59 * V_60 )
{
return F_26 ( V_60 , L_7 ) ;
}
static int F_27 ( unsigned int V_49 , struct V_50 * V_51 )
{
struct V_59 * V_61 ;
unsigned int V_62 ;
T_5 V_63 ;
V_61 = F_28 ( V_49 , NULL ) ;
if ( V_61 ) {
if ( F_29 ( V_61 , L_8 , & V_62 ) < 0 )
V_62 = 0 ;
}
for (; ; ) {
V_63 = F_30 ( V_62 ) ;
if ( V_63 == V_28 ) {
F_9 ( 1 ) ;
continue;
}
if ( V_63 < 0 ) {
F_3 ( L_9 , V_49 ) ;
return - V_29 ;
}
V_51 -> V_64 = V_63 ;
break;
}
return 0 ;
}
T_1 F_31 ( void )
{
T_5 V_10 ;
for (; ; ) {
V_10 = F_30 ( V_65 ) ;
if ( V_10 != V_28 )
break;
F_9 ( 1 ) ;
}
if ( V_10 < 0 )
return 0 ;
return V_10 ;
}
void F_32 ( T_1 V_63 )
{
for (; ; ) {
T_5 V_10 = F_33 ( V_63 ) ;
if ( V_10 != V_28 )
break;
F_9 ( 1 ) ;
}
}
static void F_34 ( unsigned int V_49 , struct V_50 * V_51 )
{
T_5 V_10 ;
if ( ! V_51 -> V_64 )
return;
for (; ; ) {
V_10 = F_33 ( V_51 -> V_64 ) ;
if ( V_10 == V_28 ) {
F_9 ( 1 ) ;
continue;
}
V_51 -> V_64 = 0 ;
break;
}
}
static void F_35 ( void )
{
F_36 ( V_66 ) ;
}
static void F_37 ( struct V_50 * V_51 )
{
T_6 V_67 , V_68 ;
T_7 V_69 ;
V_69 = F_38 ( F_39 ( V_70 + V_71 ) ) ;
F_40 () ;
V_68 = V_69 & 0xff ;
V_67 = F_41 ( V_72 , ( V_69 >> 8 ) ) ;
switch( V_67 ) {
case V_73 :
break;
case V_74 :
if ( V_68 == 0xff )
return;
V_51 -> V_75 |= 1 << V_68 ;
if ( V_68 >= V_51 -> V_68 )
F_3 ( L_10 ,
F_42 () , V_68 , V_51 -> V_68 ) ;
V_51 -> V_68 = V_68 ;
break;
case V_76 :
case V_77 :
F_3 ( L_11 ,
F_42 () , V_67 ) ;
return;
}
}
static void F_43 ( T_1 V_1 )
{
F_44 ( V_1 ) ;
}
static void F_45 ( unsigned int V_49 , struct V_50 * V_51 )
{
T_5 V_10 ;
T_1 V_78 ;
T_2 V_79 ;
T_4 V_80 ;
if ( V_81 == V_82 )
return;
V_78 = V_81 + V_49 ;
F_46 ( L_12 , V_49 , V_78 ) ;
for (; ; ) {
V_10 = F_47 ( V_78 , V_83 , 0 ) ;
if ( V_10 != V_28 )
break;
F_9 ( 1 ) ;
}
if ( V_10 ) {
F_3 ( L_13 , V_49 ) ;
return;
}
V_10 = F_48 ( V_78 , NULL , & V_79 , NULL , NULL ) ;
if ( V_10 ) {
F_3 ( L_14 , V_49 ) ;
return;
}
V_80 = F_4 ( V_79 ) ;
F_46 ( L_15 , V_80 ) ;
F_46 ( L_16 ,
F_49 ( V_70 + V_84 + V_85 ) ) ;
F_50 ( V_70 + V_84 + V_86 , 0xff ) ;
F_50 ( V_70 + V_84 + V_85 ,
V_87 | V_80 ) ;
F_46 ( L_17 ,
F_49 ( V_70 + V_84 + V_85 ) ) ;
}
static void F_51 ( unsigned int V_49 , struct V_50 * V_51 )
{
T_5 V_10 ;
T_1 V_78 ;
if ( V_81 == V_82 )
return;
F_52 ( V_70 + V_88 ) ;
V_78 = V_81 + V_49 ;
for (; ; ) {
V_10 = F_47 ( V_78 , 0 , 0 ) ;
if ( V_10 != V_28 )
break;
F_9 ( 1 ) ;
}
}
void F_53 ( T_1 V_1 )
{
F_54 ( V_89 , V_1 ) ;
}
static bool F_55 ( struct V_59 * V_61 )
{
int V_10 ;
if ( F_29 ( V_61 , L_18 ,
& V_90 ) < 0 )
return true ;
V_10 = F_56 ( V_61 , L_19 , 4 ) ;
if ( V_10 < 0 ) {
F_3 ( L_20 , V_10 ) ;
return false ;
}
V_91 = V_10 ;
if ( V_10 == 0 )
return true ;
V_92 = F_57 ( 4 * V_91 ,
V_58 ) ;
if ( F_11 ( ! V_92 ) )
return false ;
V_10 = F_58 ( V_61 , L_19 ,
V_92 ,
V_91 ) ;
if ( V_10 < 0 ) {
F_3 ( L_21 , V_10 ) ;
return false ;
}
V_93 = F_59 ( L_22 ,
V_90 ,
V_90 ,
0 , NULL ) ;
if ( ! V_93 ) {
F_3 ( L_23 ) ;
return false ;
}
return true ;
}
static void F_60 ( void )
{
F_46 ( L_24 , V_94 ) ;
V_81 = F_61 ( V_94 ) ;
if ( F_11 ( V_81 == V_82 ) )
F_3 ( L_25 ) ;
F_46 ( L_26 ,
V_81 , V_94 ) ;
}
T_1 F_62 ( void )
{
return V_56 ;
}
bool F_63 ( void )
{
struct V_59 * V_61 ;
struct V_95 V_96 ;
void T_8 * V_97 ;
struct V_98 * V_99 ;
T_6 V_100 = 7 ;
const T_3 * V_101 ;
T_1 V_102 , V_49 ;
T_5 V_10 ;
if ( V_103 )
return false ;
F_64 ( L_27 ) ;
V_61 = F_65 ( NULL , NULL , L_28 ) ;
if ( ! V_61 ) {
F_64 ( L_29 ) ;
return false ;
}
F_64 ( L_30 , V_61 -> V_104 ) ;
if ( F_66 ( V_61 , 1 , & V_96 ) ) {
F_3 ( L_31 ) ;
return false ;
}
V_97 = F_6 ( V_96 . V_105 , F_67 ( & V_96 ) ) ;
if ( ! V_97 ) {
F_3 ( L_32 ) ;
return false ;
}
if ( F_29 ( V_61 , L_33 , & V_102 ) == 0 )
V_100 = V_102 - 1 ;
F_68 (np, L_34 , prop, p, val) {
V_56 = V_102 ;
if ( V_102 == V_57 )
break;
}
F_69 (cpu)
F_70 ( V_49 , V_96 . V_105 , V_97 ) ;
F_55 ( V_61 ) ;
V_10 = F_36 ( V_106 ) ;
if ( V_10 ) {
F_3 ( L_35 , V_10 ) ;
return false ;
}
F_60 () ;
if ( ! F_71 ( & V_107 , V_97 , V_108 ,
V_100 ) ) {
F_36 ( V_66 ) ;
return false ;
}
F_72 ( L_36 , 1 << ( V_56 - 10 ) ) ;
return true ;
}
static bool F_73 ( void )
{
T_1 V_109 ;
void * V_101 ;
for ( V_109 = 0 ; V_109 < V_91 ; V_109 ++ ) {
T_1 V_110 = V_92 [ V_109 ] ;
V_101 = F_74 ( V_93 , V_58 ) ;
if ( ! V_101 ) {
F_3 ( L_37 ) ;
return false ;
}
F_75 ( V_110 , F_12 ( V_101 ) ) ;
}
return true ;
}
T_1 F_61 ( T_1 V_111 )
{
T_5 V_10 ;
T_1 V_34 ;
V_34 = F_76 ( V_111 ) - 1 ;
if ( V_111 > ( 1 << V_34 ) )
V_34 ++ ;
F_46 ( L_38 ,
V_111 , V_34 ) ;
for (; ; ) {
V_10 = F_77 ( V_34 ) ;
switch ( V_10 ) {
case V_28 :
F_9 ( 1 ) ;
break;
case V_112 :
if ( ! F_73 () )
return V_82 ;
break;
default:
if ( V_10 < 0 ) {
F_3 ( L_39 ,
V_34 , V_10 ) ;
return V_82 ;
}
return V_10 ;
}
}
}
void F_78 ( T_1 V_113 )
{
T_5 V_10 ;
if ( V_113 == V_82 )
return;
V_10 = F_79 ( V_113 ) ;
if ( V_10 < 0 )
F_80 ( L_40 , V_10 ) ;
}
int F_81 ( T_1 V_30 )
{
T_5 V_10 ;
for (; ; ) {
V_10 = F_47 ( V_30 , V_83 , 0 ) ;
if ( V_10 != V_28 )
break;
F_9 ( 1 ) ;
}
return V_10 ? - V_42 : 0 ;
}
int F_82 ( T_1 V_30 )
{
T_5 V_10 ;
for (; ; ) {
V_10 = F_47 ( V_30 , 0 , 0 ) ;
if ( V_10 != V_28 )
break;
F_9 ( 1 ) ;
}
return V_10 ? - V_42 : 0 ;
}
int F_83 ( T_1 V_30 , T_1 * V_114 , T_1 * V_115 )
{
T_2 V_79 ;
T_3 V_116 ;
T_5 V_10 ;
V_10 = F_48 ( V_30 , NULL , & V_79 , NULL , & V_116 ) ;
if ( V_10 )
return - V_42 ;
* V_114 = F_4 ( V_79 ) & 0xffffffffu ;
* V_115 = F_5 ( V_116 ) ;
return 0 ;
}
