static void F_1 ( void )
{
F_2 ( L_1 , V_1 ) ;
}
static inline bool F_3 ( int V_2 )
{
return ( V_2 == 4 ) ;
}
static const char * F_4 ( const struct V_3 * V_4 )
{
switch ( V_4 -> V_5 ) {
case 0x00000413 :
return L_2 ;
case 0xc0000408 :
return L_3 ;
case 0xc0000409 :
return L_4 ;
default:
F_5 ( 1 , L_5 , V_4 -> V_5 ) ;
return L_6 ;
}
}
static bool F_6 ( unsigned int V_2 , T_1 V_6 )
{
if ( V_2 == 4 )
return true ;
return V_6 & F_7 ( 28 ) ;
}
static int F_8 ( struct V_3 * V_4 , int V_7 , T_1 V_8 , T_1 V_9 )
{
int V_10 = ( V_9 & V_11 ) >> 20 ;
if ( V_7 < 0 ) {
F_2 ( V_12 L_7
L_8 , V_4 -> V_13 ,
V_4 -> V_2 , V_4 -> V_14 , V_4 -> V_5 , V_9 , V_8 ) ;
return 0 ;
}
if ( V_7 != V_10 ) {
F_2 ( V_12 L_9
L_8 ,
V_4 -> V_13 , V_7 , V_4 -> V_2 , V_4 -> V_14 , V_4 -> V_5 , V_9 , V_8 ) ;
return 0 ;
}
return 1 ;
}
static void F_9 ( void * V_15 )
{
struct V_16 * V_17 = V_15 ;
T_1 V_9 , V_8 ;
F_10 ( V_17 -> V_4 -> V_5 , V_8 , V_9 ) ;
if ( V_17 -> V_4 -> V_18 < ( V_9 & V_19 ) )
V_17 -> V_20 = 1 ;
if ( V_17 -> V_20 ) {
V_9 =
( V_9 & ~ ( V_21 | V_22 ) ) |
( V_19 - V_17 -> V_4 -> V_18 ) ;
} else if ( V_17 -> V_23 ) {
int V_24 = ( V_9 & V_19 ) +
( V_17 -> V_23 - V_17 -> V_4 -> V_18 ) ;
V_9 = ( V_9 & ~ V_21 ) |
( V_24 & V_19 ) ;
}
V_9 &= ~ V_25 ;
if ( ! V_17 -> V_4 -> V_26 )
goto V_27;
if ( V_17 -> V_28 ) {
if ( F_8 ( V_17 -> V_4 , V_17 -> V_29 , V_8 , V_9 ) ) {
V_9 &= ~ V_11 ;
V_9 |= V_17 -> V_29 << 20 ;
}
}
if ( V_17 -> V_4 -> V_30 )
V_9 |= V_31 ;
V_27:
V_9 |= V_32 ;
F_11 ( V_17 -> V_4 -> V_5 , V_8 , V_9 ) ;
}
static void F_12 ( struct V_3 * V_4 , int V_33 )
{
struct V_16 V_17 = {
. V_4 = V_4 ,
. V_28 = 1 ,
. V_29 = V_33 ,
} ;
V_4 -> V_18 = V_19 ;
F_9 ( & V_17 ) ;
}
static int F_13 ( int V_34 , int V_35 )
{
if ( V_34 < 0 && ! F_14 ( V_35 , V_36 ,
V_37 , 0 ) )
return V_35 ;
return V_34 ;
}
static int F_15 ( int V_34 , int V_35 )
{
if ( V_34 < 0 && ! F_14 ( V_35 , V_1 ,
V_37 , 0 ) )
return V_35 ;
return V_34 ;
}
static void F_16 ( struct V_38 * V_39 )
{
T_1 V_40 = 0 , V_41 = 0 ;
int V_42 = - 1 , V_43 ;
if ( F_17 ( V_44 , & V_40 , & V_41 ) )
return;
V_43 = ( V_40 & V_45 ) >> 4 ;
if ( ! ( V_40 & V_45 ) ) {
F_2 ( V_12 L_10 ) ;
V_43 = V_46 ;
V_40 = ( V_40 & ~ V_45 ) | ( V_46 << 4 ) ;
}
V_42 = F_15 ( V_42 , V_43 ) ;
if ( ( V_42 == V_43 ) &&
( V_47 != V_48 ) )
V_47 = V_48 ;
V_40 = ( V_40 & ~ V_49 ) | V_50 ;
F_11 ( V_44 , V_40 , V_41 ) ;
}
void F_18 ( struct V_38 * V_39 )
{
struct V_3 V_4 ;
unsigned int V_13 = F_19 () ;
T_1 V_40 = 0 , V_41 = 0 , V_5 = 0 ;
unsigned int V_2 , V_14 ;
int V_33 = - 1 , V_35 ;
for ( V_2 = 0 ; V_2 < V_51 . V_52 ; ++ V_2 ) {
for ( V_14 = 0 ; V_14 < V_53 ; ++ V_14 ) {
if ( V_14 == 0 )
V_5 = F_20 ( V_2 ) ;
else if ( V_14 == 1 ) {
V_5 = ( V_40 & V_54 ) >> 21 ;
if ( ! V_5 )
break;
V_5 += V_55 ;
} else
++ V_5 ;
if ( F_17 ( V_5 , & V_40 , & V_41 ) )
break;
if ( ! ( V_41 & V_56 ) )
continue;
if ( ! ( V_41 & V_57 ) ||
( V_41 & V_58 ) )
continue;
if ( ! V_14 )
F_21 ( V_59 , V_13 ) |= ( 1 << V_2 ) ;
memset ( & V_4 , 0 , sizeof( V_4 ) ) ;
V_4 . V_13 = V_13 ;
V_4 . V_2 = V_2 ;
V_4 . V_14 = V_14 ;
V_4 . V_5 = V_5 ;
V_4 . V_26 = F_6 ( V_2 , V_41 ) ;
if ( ! V_4 . V_26 )
goto V_60;
V_4 . V_30 = 1 ;
V_35 = ( V_41 & V_11 ) >> 20 ;
V_33 = F_13 ( V_33 , V_35 ) ;
if ( ( V_33 == V_35 ) &&
( V_61 != V_62 ) )
V_61 = V_62 ;
V_60:
F_12 ( & V_4 , V_33 ) ;
}
}
if ( V_63 . V_64 )
F_16 ( V_39 ) ;
}
static void F_22 ( unsigned int V_2 , bool V_65 , T_2 V_66 )
{
struct V_67 V_68 ;
T_2 V_69 ;
F_23 ( F_24 ( V_2 ) , V_69 ) ;
if ( ! ( V_69 & V_70 ) )
return;
F_25 ( & V_68 ) ;
V_68 . V_69 = V_69 ;
V_68 . V_2 = V_2 ;
if ( V_65 )
V_68 . V_66 = V_66 ;
if ( V_68 . V_69 & V_71 )
F_23 ( F_26 ( V_2 ) , V_68 . V_72 ) ;
F_27 ( & V_68 ) ;
F_28 ( F_24 ( V_2 ) , 0 ) ;
}
static inline void F_29 ( void )
{
F_30 ( V_73 ) ;
V_47 () ;
}
T_3 T_4 void F_31 ( void )
{
F_32 () ;
F_29 () ;
F_33 () ;
}
T_3 T_4 void F_34 ( void )
{
F_32 () ;
F_35 ( V_1 ) ;
F_29 () ;
F_36 ( V_1 ) ;
F_33 () ;
}
static void V_48 ( void )
{
T_2 V_69 ;
unsigned int V_2 ;
for ( V_2 = 0 ; V_2 < V_51 . V_52 ; ++ V_2 ) {
F_23 ( F_24 ( V_2 ) , V_69 ) ;
if ( ! ( V_69 & V_70 ) ||
! ( V_69 & V_74 ) )
continue;
F_22 ( V_2 , false , 0 ) ;
break;
}
}
static void V_62 ( void )
{
T_1 V_40 = 0 , V_41 = 0 , V_5 = 0 ;
int V_13 = F_19 () ;
unsigned int V_2 , V_14 ;
for ( V_2 = 0 ; V_2 < V_51 . V_52 ; ++ V_2 ) {
if ( ! ( F_21 ( V_59 , V_13 ) & ( 1 << V_2 ) ) )
continue;
for ( V_14 = 0 ; V_14 < V_53 ; ++ V_14 ) {
if ( V_14 == 0 ) {
V_5 = F_20 ( V_2 ) ;
} else if ( V_14 == 1 ) {
V_5 = ( V_40 & V_54 ) >> 21 ;
if ( ! V_5 )
break;
V_5 += V_55 ;
} else {
++ V_5 ;
}
if ( F_17 ( V_5 , & V_40 , & V_41 ) )
break;
if ( ! ( V_41 & V_56 ) ) {
if ( V_14 )
continue;
else
break;
}
if ( ! ( V_41 & V_57 ) ||
( V_41 & V_58 ) )
continue;
if ( V_41 & V_22 )
goto log;
}
}
return;
log:
F_22 ( V_2 , true , ( ( T_2 ) V_41 << 32 ) | V_40 ) ;
}
static T_5
F_37 ( struct V_3 * V_4 , const char * V_75 , T_6 V_76 )
{
struct V_16 V_17 ;
unsigned long V_35 ;
if ( ! V_4 -> V_26 )
return - V_77 ;
if ( F_38 ( V_75 , 0 , & V_35 ) < 0 )
return - V_77 ;
V_4 -> V_30 = ! ! V_35 ;
memset ( & V_17 , 0 , sizeof( V_17 ) ) ;
V_17 . V_4 = V_4 ;
F_39 ( V_4 -> V_13 , F_9 , & V_17 , 1 ) ;
return V_76 ;
}
static T_5
F_40 ( struct V_3 * V_4 , const char * V_75 , T_6 V_76 )
{
struct V_16 V_17 ;
unsigned long V_35 ;
if ( F_38 ( V_75 , 0 , & V_35 ) < 0 )
return - V_77 ;
if ( V_35 > V_19 )
V_35 = V_19 ;
if ( V_35 < 1 )
V_35 = 1 ;
memset ( & V_17 , 0 , sizeof( V_17 ) ) ;
V_17 . V_23 = V_4 -> V_18 ;
V_4 -> V_18 = V_35 ;
V_17 . V_4 = V_4 ;
F_39 ( V_4 -> V_13 , F_9 , & V_17 , 1 ) ;
return V_76 ;
}
static T_5 F_41 ( struct V_3 * V_4 , char * V_75 )
{
T_1 V_8 , V_9 ;
F_42 ( V_4 -> V_13 , V_4 -> V_5 , & V_8 , & V_9 ) ;
return sprintf ( V_75 , L_11 , ( ( V_9 & V_19 ) -
( V_19 - V_4 -> V_18 ) ) ) ;
}
static T_5 F_43 ( struct V_78 * V_79 , struct V_80 * V_81 , char * V_75 )
{
struct V_3 * V_4 = F_44 ( V_79 ) ;
struct V_82 * V_83 = F_45 ( V_81 ) ;
T_5 V_84 ;
V_84 = V_83 -> F_43 ? V_83 -> F_43 ( V_4 , V_75 ) : - V_85 ;
return V_84 ;
}
static T_5 F_46 ( struct V_78 * V_79 , struct V_80 * V_81 ,
const char * V_75 , T_6 V_86 )
{
struct V_3 * V_4 = F_44 ( V_79 ) ;
struct V_82 * V_83 = F_45 ( V_81 ) ;
T_5 V_84 ;
V_84 = V_83 -> F_46 ? V_83 -> F_46 ( V_4 , V_75 , V_86 ) : - V_85 ;
return V_84 ;
}
static int F_47 ( unsigned int V_13 , unsigned int V_2 ,
unsigned int V_14 , T_1 V_5 )
{
struct V_3 * V_4 = NULL ;
T_1 V_40 , V_41 ;
int V_87 ;
if ( ( V_2 >= V_51 . V_52 ) || ( V_14 >= V_53 ) )
return 0 ;
if ( F_48 ( V_13 , V_5 , & V_40 , & V_41 ) )
return 0 ;
if ( ! ( V_41 & V_56 ) ) {
if ( V_14 )
goto V_88;
else
return 0 ;
}
if ( ! ( V_41 & V_57 ) ||
( V_41 & V_58 ) )
goto V_88;
V_4 = F_49 ( sizeof( struct V_3 ) , V_89 ) ;
if ( ! V_4 )
return - V_90 ;
V_4 -> V_14 = V_14 ;
V_4 -> V_2 = V_2 ;
V_4 -> V_13 = V_13 ;
V_4 -> V_5 = V_5 ;
V_4 -> V_30 = 0 ;
V_4 -> V_26 = F_6 ( V_2 , V_41 ) ;
V_4 -> V_18 = V_19 ;
if ( V_4 -> V_26 ) {
V_91 . V_92 [ 2 ] = & V_30 . V_81 ;
V_4 -> V_30 = 1 ;
} else {
V_91 . V_92 [ 2 ] = NULL ;
}
F_50 ( & V_4 -> V_93 ) ;
if ( F_21 ( V_94 , V_13 ) [ V_2 ] -> V_95 ) {
F_51 ( & V_4 -> V_93 ,
& F_21 ( V_94 , V_13 ) [ V_2 ] -> V_95 -> V_93 ) ;
} else {
F_21 ( V_94 , V_13 ) [ V_2 ] -> V_95 = V_4 ;
}
V_87 = F_52 ( & V_4 -> V_79 , & V_91 ,
F_21 ( V_94 , V_13 ) [ V_2 ] -> V_79 ,
( V_2 == 4 ? F_4 ( V_4 ) : V_96 [ V_2 ] ) ) ;
if ( V_87 )
goto V_97;
V_88:
if ( ! V_14 ) {
V_5 = ( V_40 & V_54 ) >> 21 ;
if ( ! V_5 )
return 0 ;
V_5 += V_55 ;
} else {
++ V_5 ;
}
V_87 = F_47 ( V_13 , V_2 , ++ V_14 , V_5 ) ;
if ( V_87 )
goto V_97;
if ( V_4 )
F_53 ( & V_4 -> V_79 , V_98 ) ;
return V_87 ;
V_97:
if ( V_4 ) {
F_54 ( & V_4 -> V_79 ) ;
F_55 ( & V_4 -> V_93 ) ;
F_56 ( V_4 ) ;
}
return V_87 ;
}
static int F_57 ( struct V_99 * V_4 )
{
struct V_100 * V_101 = & V_4 -> V_95 -> V_93 ;
struct V_3 * V_102 = NULL ;
struct V_3 * V_103 = NULL ;
int V_87 = 0 ;
V_87 = F_58 ( & V_4 -> V_95 -> V_79 , V_4 -> V_79 , V_4 -> V_95 -> V_79 . V_104 ) ;
if ( V_87 )
return V_87 ;
F_59 (pos, tmp, head, miscj) {
V_87 = F_58 ( & V_102 -> V_79 , V_4 -> V_79 , V_102 -> V_79 . V_104 ) ;
if ( V_87 ) {
F_60 (pos, tmp, head, miscj)
F_61 ( & V_102 -> V_79 ) ;
return V_87 ;
}
}
return V_87 ;
}
static int F_62 ( unsigned int V_13 , unsigned int V_2 )
{
struct V_105 * V_106 = F_21 ( V_107 , V_13 ) ;
struct V_108 * V_109 = NULL ;
struct V_99 * V_4 = NULL ;
const char * V_104 = V_96 [ V_2 ] ;
int V_87 = 0 ;
if ( F_3 ( V_2 ) ) {
V_109 = F_63 ( F_64 ( V_13 ) ) ;
if ( V_109 && V_109 -> V_110 ) {
V_4 = V_109 -> V_110 ;
V_87 = F_58 ( V_4 -> V_79 , & V_106 -> V_79 , V_104 ) ;
if ( V_87 )
goto V_111;
F_21 ( V_94 , V_13 ) [ V_2 ] = V_4 ;
F_65 ( & V_4 -> V_112 ) ;
V_87 = F_57 ( V_4 ) ;
goto V_111;
}
}
V_4 = F_49 ( sizeof( struct V_99 ) , V_89 ) ;
if ( ! V_4 ) {
V_87 = - V_90 ;
goto V_111;
}
V_4 -> V_79 = F_66 ( V_104 , & V_106 -> V_79 ) ;
if ( ! V_4 -> V_79 ) {
V_87 = - V_77 ;
goto V_97;
}
F_21 ( V_94 , V_13 ) [ V_2 ] = V_4 ;
if ( F_3 ( V_2 ) ) {
F_67 ( & V_4 -> V_112 , 1 ) ;
if ( V_109 ) {
F_68 ( V_109 -> V_110 ) ;
V_109 -> V_110 = V_4 ;
}
}
V_87 = F_47 ( V_13 , V_2 , 0 , F_20 ( V_2 ) ) ;
if ( ! V_87 )
goto V_111;
V_97:
F_56 ( V_4 ) ;
V_111:
return V_87 ;
}
static int F_69 ( unsigned int V_13 )
{
unsigned int V_2 ;
struct V_99 * * V_113 ;
int V_87 = 0 ;
V_113 = F_49 ( sizeof( struct V_99 * ) * V_51 . V_52 ,
V_89 ) ;
if ( ! V_113 )
return - V_90 ;
F_21 ( V_94 , V_13 ) = V_113 ;
for ( V_2 = 0 ; V_2 < V_51 . V_52 ; ++ V_2 ) {
if ( ! ( F_21 ( V_59 , V_13 ) & ( 1 << V_2 ) ) )
continue;
V_87 = F_62 ( V_13 , V_2 ) ;
if ( V_87 )
return V_87 ;
}
return V_87 ;
}
static void F_70 ( unsigned int V_13 ,
unsigned int V_2 )
{
struct V_3 * V_102 = NULL ;
struct V_3 * V_103 = NULL ;
struct V_99 * V_101 = F_21 ( V_94 , V_13 ) [ V_2 ] ;
if ( ! V_101 )
return;
F_59 (pos, tmp, &head->blocks->miscj, miscj) {
F_54 ( & V_102 -> V_79 ) ;
F_55 ( & V_102 -> V_93 ) ;
F_56 ( V_102 ) ;
}
F_56 ( F_21 ( V_94 , V_13 ) [ V_2 ] -> V_95 ) ;
F_21 ( V_94 , V_13 ) [ V_2 ] -> V_95 = NULL ;
}
static void F_71 ( struct V_99 * V_4 )
{
struct V_3 * V_102 = NULL ;
struct V_3 * V_103 = NULL ;
F_61 ( V_4 -> V_79 ) ;
F_59 (pos, tmp, &b->blocks->miscj, miscj)
F_61 ( & V_102 -> V_79 ) ;
}
static void F_72 ( unsigned int V_13 , int V_2 )
{
struct V_108 * V_109 ;
struct V_99 * V_4 ;
V_4 = F_21 ( V_94 , V_13 ) [ V_2 ] ;
if ( ! V_4 )
return;
if ( ! V_4 -> V_95 )
goto V_114;
if ( F_3 ( V_2 ) ) {
if ( ! F_73 ( & V_4 -> V_112 ) ) {
F_71 ( V_4 ) ;
F_21 ( V_94 , V_13 ) [ V_2 ] = NULL ;
return;
} else {
V_109 = F_63 ( F_64 ( V_13 ) ) ;
V_109 -> V_110 = NULL ;
}
}
F_70 ( V_13 , V_2 ) ;
V_114:
F_61 ( V_4 -> V_79 ) ;
F_54 ( V_4 -> V_79 ) ;
F_56 ( V_4 ) ;
F_21 ( V_94 , V_13 ) [ V_2 ] = NULL ;
}
static void F_74 ( unsigned int V_13 )
{
unsigned int V_2 ;
for ( V_2 = 0 ; V_2 < V_51 . V_52 ; ++ V_2 ) {
if ( ! ( F_21 ( V_59 , V_13 ) & ( 1 << V_2 ) ) )
continue;
F_72 ( V_13 , V_2 ) ;
}
F_56 ( F_21 ( V_94 , V_13 ) ) ;
}
static void
F_75 ( unsigned long V_115 , unsigned int V_13 )
{
switch ( V_115 ) {
case V_116 :
case V_117 :
F_69 ( V_13 ) ;
break;
case V_118 :
case V_119 :
F_74 ( V_13 ) ;
break;
default:
break;
}
}
static T_7 int F_76 ( void )
{
unsigned V_120 = 0 ;
F_77 (lcpu) {
int V_87 = F_69 ( V_120 ) ;
if ( V_87 )
return V_87 ;
}
V_121 = F_75 ;
return 0 ;
}
