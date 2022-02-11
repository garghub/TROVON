static void F_1 ( struct V_1 * V_2 )
{
memset ( V_2 , 0 , sizeof( struct V_1 ) ) ;
V_2 -> V_3 = V_4 . V_5 ;
}
static void F_2 ( struct V_1 * V_2 )
{
struct V_1 * V_6 = & F_3 ( V_7 , V_2 -> V_8 ) ;
V_6 -> V_9 = 0 ;
F_4 () ;
V_2 -> V_9 = 0 ;
V_6 -> V_8 = V_2 -> V_8 ;
F_4 () ;
memcpy ( V_6 , V_2 , sizeof( struct V_1 ) ) ;
F_4 () ;
V_6 -> V_9 = 1 ;
}
static void F_5 ( struct V_1 * V_2 )
{
unsigned long V_10 ;
T_1 V_11 ;
memset ( & V_11 , 0xff , sizeof( T_1 ) ) ;
F_6 ( V_10 ) ;
F_7 ( 0 , & V_11 ) ;
F_8 ( V_10 ) ;
V_2 -> V_9 = 0 ;
}
static void F_9 ( struct V_1 * V_2 , struct V_12 * V_13 )
{
struct V_12 V_14 ;
unsigned long V_10 ;
if ( ! V_13 ) {
memset ( & V_14 , 0 , sizeof( struct V_12 ) ) ;
V_14 . V_15 = V_2 -> V_15 ;
V_14 . V_16 = V_2 -> V_16 ;
V_13 = & V_14 ;
}
F_6 ( V_10 ) ;
F_10 ( V_13 , 0 ) ;
F_8 ( V_10 ) ;
V_2 -> V_9 = 0 ;
}
static int F_11 ( unsigned int V_17 , struct V_12 * V_14 )
{
int V_18 = F_12 () ;
struct V_1 * V_2 = F_13 ( & V_7 ) ;
if ( ! F_14 ( V_18 , V_19 ) )
return V_20 ;
F_15 ( V_18 , V_19 ) ;
if ( V_2 -> V_21 & V_22 )
F_9 ( V_2 , V_14 ) ;
else if ( V_2 -> V_23 )
F_5 ( V_2 ) ;
return V_24 ;
}
static void F_16 ( void * V_25 )
{
int V_18 = F_12 () ;
struct V_1 * V_2 = F_13 ( & V_7 ) ;
if ( F_14 ( V_18 , V_19 ) &&
V_2 -> V_21 & V_22 ) {
F_15 ( V_18 , V_19 ) ;
F_9 ( V_2 , NULL ) ;
}
}
static int F_17 ( void )
{
struct V_1 * V_2 = F_13 ( & V_7 ) ;
int V_26 = F_18 ( V_2 -> V_21 ) ;
int V_27 = 0 ;
int V_18 = V_2 -> V_8 ;
if ( V_2 -> V_21 & V_22 ) {
F_19 ( L_1 , V_18 ) ;
switch ( V_26 ) {
case V_28 :
case V_29 :
F_9 ( V_2 , NULL ) ;
break;
default:
F_19 ( L_2 ) ;
V_27 = - V_30 ;
}
F_19 ( L_3 , V_18 ) ;
} else if ( V_2 -> V_23 ) {
F_19 ( L_4 , V_18 ) ;
F_5 ( V_2 ) ;
F_20 () ;
F_19 ( L_5 , V_18 ) ;
} else
V_2 -> V_9 = 0 ;
return V_27 ;
}
static void T_2 F_21 ( struct V_1 * V_2 )
{
int V_26 = F_18 ( V_2 -> V_21 ) ;
F_2 ( V_2 ) ;
if ( V_26 == V_31 )
return;
if ( V_2 -> V_21 & ( V_32 | V_33 ) ) {
unsigned long V_34 ;
int V_18 ;
F_22 () ;
F_23 ( V_19 , V_35 ) ;
F_15 ( F_24 () , V_19 ) ;
F_25 (cpu) {
struct V_1 * V_36 = & F_3 ( V_7 , V_18 ) ;
if ( ! V_36 -> V_9 ||
F_18 ( V_36 -> V_21 ) != V_31 )
F_15 ( V_18 , V_19 ) ;
}
if ( ! F_26 ( V_19 ) ) {
if ( V_2 -> V_21 & V_32 ) {
F_27 () ;
F_28 ( V_19 ,
F_16 , NULL , 0 ) ;
F_29 () ;
} else if ( V_2 -> V_21 & V_33 )
V_37 -> V_38 ( V_19 ,
V_39 ) ;
}
V_34 = V_40 ;
while ( ! F_26 ( V_19 ) ) {
if ( ! F_30 ( V_40 , V_34 + 2 * V_41 ) ) {
F_31 ( L_6 ,
* F_32 ( V_19 ) ) ;
break;
}
F_33 () ;
}
F_17 () ;
F_34 () ;
F_35 () ;
} else {
F_27 () ;
F_17 () ;
F_29 () ;
}
}
static int F_36 ( struct V_42 * V_43 , unsigned long V_44 ,
void * V_45 )
{
struct V_1 * V_2 = (struct V_1 * ) V_45 ;
if ( ! V_2 )
return V_46 ;
F_37 ( & V_47 ) ;
F_21 ( V_2 ) ;
F_38 ( & V_47 ) ;
return V_46 ;
}
static int F_39 ( unsigned int V_18 , bool V_48 )
{
T_3 V_49 , V_50 ;
int V_51 ;
V_51 = F_40 ( V_18 , V_52 , & V_49 , & V_50 ) ;
if ( V_51 ) {
F_31 ( L_7 , V_53 ) ;
return V_51 ;
}
V_48 ? ( V_49 |= F_41 ( 18 ) ) : ( V_49 &= ~ F_41 ( 18 ) ) ;
V_51 = F_42 ( V_18 , V_52 , V_49 , V_50 ) ;
if ( V_51 )
F_31 ( L_8 , V_53 ) ;
return V_51 ;
}
static int F_43 ( const char * V_54 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < V_55 ; V_6 ++ ) {
if ( ! strncmp ( V_56 [ V_6 ] , V_54 , strlen ( V_56 [ V_6 ] ) ) ) {
V_57 = V_6 ;
return 0 ;
}
}
return - V_30 ;
}
static T_4 F_44 ( struct V_58 * V_59 , char T_5 * V_60 ,
T_6 V_61 , T_7 * V_62 )
{
char V_54 [ V_63 ] ;
int V_64 ;
V_64 = sprintf ( V_54 , L_9 , V_56 [ V_57 ] ) ;
return F_45 ( V_60 , V_61 , V_62 , V_54 , V_64 ) ;
}
static T_4 F_46 ( struct V_58 * V_59 , const char T_5 * V_60 ,
T_6 V_61 , T_7 * V_62 )
{
char V_54 [ V_63 ] , * V_65 ;
int V_51 ;
if ( V_61 > V_63 )
return - V_30 ;
if ( F_47 ( & V_54 , V_60 , V_61 ) )
return - V_66 ;
V_54 [ V_61 - 1 ] = 0 ;
V_65 = F_48 ( V_54 ) ;
V_51 = F_43 ( V_65 ) ;
if ( V_51 ) {
F_31 ( L_10 , V_53 , V_65 ) ;
return V_51 ;
}
* V_62 += V_61 ;
return V_61 ;
}
static int F_49 ( void * V_45 , T_8 V_44 )
{
struct V_1 * V_2 = (struct V_1 * ) V_45 ;
if ( V_44 >= V_67 || ! F_50 ( V_44 ) ) {
F_31 ( L_11 , V_53 , V_44 ) ;
return - V_30 ;
}
V_2 -> V_8 = V_44 ;
return 0 ;
}
static void F_51 ( void * V_25 )
{
asm volatile("int $18");
}
static void F_52 ( void * V_25 )
{
asm volatile("int %0" :: "i" (DEFERRED_ERROR_VECTOR));
}
static void F_53 ( void * V_25 )
{
asm volatile("int %0" :: "i" (THRESHOLD_APIC_VECTOR));
}
static T_3 F_54 ( int V_68 )
{
struct V_69 * V_70 = & V_4 ;
T_3 V_71 ;
V_71 = ( V_70 -> V_72 * V_73 ) / F_55 () ;
return V_71 * V_68 ;
}
static void F_56 ( T_9 V_74 )
{
struct V_75 * V_43 ;
struct V_76 * V_77 ;
T_3 V_44 ;
int V_51 ;
V_43 = F_57 ( V_74 ) ;
if ( ! V_43 )
return;
V_77 = V_43 -> V_78 ;
if ( ! V_77 )
return;
V_51 = F_58 ( V_77 , V_79 , & V_44 ) ;
if ( V_51 ) {
F_31 ( L_12 ,
V_53 , F_59 ( V_77 -> V_80 ) , V_79 ) ;
return;
}
if ( V_44 & F_41 ( 27 ) )
return;
F_31 ( L_13 ,
V_53 ) ;
V_44 |= F_41 ( 27 ) ;
V_51 = F_60 ( V_77 , V_79 , V_44 ) ;
if ( V_51 )
F_31 ( L_14 ,
V_53 , F_59 ( V_77 -> V_80 ) , V_79 ) ;
}
static void F_61 ( void * V_25 )
{
struct V_1 V_2 = * (struct V_1 * ) V_25 ;
T_10 V_11 = V_2 . V_81 ;
F_62 ( V_82 , V_2 . V_83 ) ;
if ( F_63 ( V_84 ) ) {
if ( V_2 . V_21 == V_85 ) {
F_62 ( F_64 ( V_11 ) , V_2 . V_23 ) ;
F_62 ( F_65 ( V_11 ) , V_2 . V_86 ) ;
} else {
F_62 ( F_66 ( V_11 ) , V_2 . V_23 ) ;
F_62 ( F_67 ( V_11 ) , V_2 . V_86 ) ;
}
F_62 ( F_68 ( V_11 ) , V_2 . V_78 ) ;
F_62 ( F_69 ( V_11 ) , V_2 . V_87 ) ;
} else {
F_62 ( F_70 ( V_11 ) , V_2 . V_23 ) ;
F_62 ( F_71 ( V_11 ) , V_2 . V_86 ) ;
F_62 ( F_72 ( V_11 ) , V_2 . V_78 ) ;
}
}
static void F_73 ( void )
{
T_8 V_88 = 0 ;
unsigned int V_18 = V_89 . V_8 ;
T_10 V_11 = V_89 . V_81 ;
F_74 ( V_89 . V_90 ) ;
if ( V_89 . V_78 )
V_89 . V_23 |= V_91 ;
if ( V_89 . V_87 )
V_89 . V_23 |= V_92 ;
if ( V_57 == V_93 ) {
F_75 ( & V_89 ) ;
return;
}
V_88 = V_94 | V_95 ;
if ( ! ( V_89 . V_23 & V_96 ) )
V_88 |= V_97 ;
if ( V_57 == V_85 ) {
V_89 . V_23 |= V_98 ;
V_89 . V_23 |= ( V_89 . V_23 & ~ V_99 ) ;
}
if ( F_76 ( V_100 ) &&
V_11 == 4 &&
V_4 . V_101 < 0x17 ) {
F_56 ( F_77 ( V_18 ) ) ;
V_18 = F_54 ( F_77 ( V_18 ) ) ;
}
F_22 () ;
if ( ! F_50 ( V_18 ) )
goto V_51;
F_39 ( V_18 , true ) ;
V_89 . V_83 = V_88 ;
V_89 . V_21 = V_57 ;
F_78 ( V_18 , F_61 , & V_89 , 0 ) ;
F_39 ( V_18 , false ) ;
switch ( V_57 ) {
case V_85 :
F_78 ( V_18 , F_52 , NULL , 0 ) ;
break;
case V_102 :
F_78 ( V_18 , F_53 , NULL , 0 ) ;
break;
default:
F_78 ( V_18 , F_51 , NULL , 0 ) ;
}
V_51:
F_35 () ;
}
static int F_79 ( void * V_45 , T_8 V_44 )
{
struct V_1 * V_2 = (struct V_1 * ) V_45 ;
if ( V_44 >= V_103 ) {
F_31 ( L_15 , V_44 ) ;
return - V_30 ;
}
V_2 -> V_81 = V_44 ;
F_73 () ;
return 0 ;
}
static T_4
F_80 ( struct V_58 * V_59 , char T_5 * V_60 ,
T_6 V_61 , T_7 * V_62 )
{
return F_45 ( V_60 , V_61 , V_62 ,
V_104 , strlen ( V_104 ) ) ;
}
static int T_11 F_81 ( void )
{
unsigned int V_6 ;
T_8 V_105 ;
F_82 ( V_106 , V_105 ) ;
V_103 = V_105 & V_107 ;
V_108 = F_83 ( L_16 , NULL ) ;
if ( ! V_108 )
return - V_30 ;
for ( V_6 = 0 ; V_6 < F_84 ( V_109 ) ; V_6 ++ ) {
V_109 [ V_6 ] . V_110 = F_85 ( V_109 [ V_6 ] . V_111 ,
V_109 [ V_6 ] . V_112 ,
V_108 ,
& V_89 ,
V_109 [ V_6 ] . V_113 ) ;
if ( ! V_109 [ V_6 ] . V_110 )
goto V_114;
}
return 0 ;
V_114:
while ( V_6 -- > 0 )
F_86 ( V_109 [ V_6 ] . V_110 ) ;
F_86 ( V_108 ) ;
V_108 = NULL ;
return - V_115 ;
}
static int T_11 F_87 ( void )
{
int V_51 ;
if ( ! F_88 ( & V_19 , V_116 ) )
return - V_117 ;
V_51 = F_81 () ;
if ( V_51 ) {
F_89 ( V_19 ) ;
return V_51 ;
}
F_90 ( V_118 , F_11 , 0 , L_17 ) ;
F_91 ( & V_119 ) ;
F_1 ( & V_89 ) ;
F_19 ( L_18 ) ;
return 0 ;
}
static void T_12 F_92 ( void )
{
F_93 ( & V_119 ) ;
F_94 ( V_118 , L_17 ) ;
F_95 ( V_108 ) ;
V_108 = NULL ;
memset ( & V_109 , 0 , sizeof( V_109 ) ) ;
F_89 ( V_19 ) ;
}
