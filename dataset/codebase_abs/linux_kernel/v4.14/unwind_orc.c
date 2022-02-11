static inline unsigned long F_1 ( const int * V_1 )
{
return ( unsigned long ) V_1 + * V_1 ;
}
static struct V_2 * F_2 ( int * V_3 , struct V_2 * V_4 ,
unsigned int V_5 , unsigned long V_1 )
{
int * V_6 = V_3 ;
int * V_7 = V_3 + V_5 - 1 ;
int * V_8 = V_6 , * V_9 = V_6 ;
if ( ! V_5 )
return NULL ;
while ( V_6 <= V_7 ) {
V_8 = V_6 + ( ( V_7 - V_6 ) / 2 ) ;
if ( F_1 ( V_8 ) <= V_1 ) {
V_9 = V_8 ;
V_6 = V_8 + 1 ;
} else
V_7 = V_8 - 1 ;
}
return V_4 + ( V_9 - V_3 ) ;
}
static struct V_2 * F_3 ( unsigned long V_1 )
{
struct V_10 * V_11 ;
V_11 = F_4 ( V_1 ) ;
if ( ! V_11 || ! V_11 -> V_12 . V_13 || ! V_11 -> V_12 . V_14 )
return NULL ;
return F_2 ( V_11 -> V_12 . V_14 , V_11 -> V_12 . V_13 ,
V_11 -> V_12 . V_15 , V_1 ) ;
}
static struct V_2 * F_3 ( unsigned long V_1 )
{
return NULL ;
}
static struct V_2 * F_5 ( unsigned long V_1 )
{
if ( ! V_16 )
return NULL ;
if ( V_1 >= V_17 && V_1 < V_18 ) {
unsigned int V_19 , V_20 , V_21 ;
V_19 = ( V_1 - V_17 ) / V_22 ;
if ( F_6 ( ( V_19 >= V_23 - 1 ) ) ) {
F_7 ( L_1 ,
V_19 , V_23 , ( void * ) V_1 ) ;
return NULL ;
}
V_20 = V_24 [ V_19 ] ;
V_21 = V_24 [ V_19 + 1 ] + 1 ;
if ( F_6 ( ( V_25 + V_20 >= V_26 ) ||
( V_25 + V_21 > V_26 ) ) ) {
F_7 ( L_2 ,
V_19 , V_23 , V_20 , V_21 , ( void * ) V_1 ) ;
return NULL ;
}
return F_2 ( V_27 + V_20 ,
V_25 + V_20 , V_21 - V_20 , V_1 ) ;
}
if ( V_1 >= ( unsigned long ) V_28 && V_1 < ( unsigned long ) V_29 )
return F_2 ( V_27 , V_25 ,
V_30 - V_27 , V_1 ) ;
return F_3 ( V_1 ) ;
}
static void F_8 ( void * V_31 , void * V_32 , int V_33 )
{
struct V_2 * V_34 , * V_35 ;
struct V_2 V_36 ;
int * V_37 = V_31 , * V_38 = V_32 , V_39 ;
int V_40 = V_32 - V_31 ;
V_39 = * V_37 ;
* V_37 = * V_38 + V_40 ;
* V_38 = V_39 - V_40 ;
V_34 = V_41 + ( V_37 - V_42 ) ;
V_35 = V_41 + ( V_38 - V_42 ) ;
V_36 = * V_34 ;
* V_34 = * V_35 ;
* V_35 = V_36 ;
}
static int F_9 ( const void * V_31 , const void * V_32 )
{
struct V_2 * V_34 ;
const int * V_37 = V_31 , * V_38 = V_32 ;
unsigned long V_43 = F_1 ( V_37 ) ;
unsigned long V_44 = F_1 ( V_38 ) ;
if ( V_43 > V_44 )
return 1 ;
if ( V_43 < V_44 )
return - 1 ;
V_34 = V_41 + ( V_37 - V_42 ) ;
return V_34 -> V_45 == V_46 ? - 1 : 1 ;
}
void F_10 ( struct V_10 * V_11 , void * V_47 , T_1 V_48 ,
void * V_49 , T_1 V_50 )
{
int * F_1 = V_47 ;
struct V_2 * V_51 = V_49 ;
unsigned int V_5 = V_48 / sizeof( int ) ;
F_11 ( V_48 % sizeof( int ) != 0 ||
V_50 % sizeof( * V_51 ) != 0 ||
V_5 != V_50 / sizeof( * V_51 ) ) ;
F_12 ( & V_52 ) ;
V_42 = F_1 ;
V_41 = V_51 ;
F_13 ( F_1 , V_5 , sizeof( int ) , F_9 , F_8 ) ;
F_14 ( & V_52 ) ;
V_11 -> V_12 . V_14 = F_1 ;
V_11 -> V_12 . V_13 = V_51 ;
V_11 -> V_12 . V_15 = V_5 ;
}
void T_2 F_15 ( void )
{
T_1 V_48 = ( void * ) V_30 - ( void * ) V_27 ;
T_1 V_50 = ( void * ) V_26 - ( void * ) V_25 ;
T_1 V_5 = V_48 / sizeof( int ) ;
struct V_2 * V_51 ;
int V_53 ;
if ( ! V_5 || V_48 % sizeof( int ) != 0 ||
V_50 % sizeof( struct V_2 ) != 0 ||
V_5 != V_50 / sizeof( struct V_2 ) ) {
F_7 ( L_3 ) ;
return;
}
F_13 ( V_27 , V_5 , sizeof( int ) , F_9 ,
F_8 ) ;
V_23 = V_54 - V_24 ;
for ( V_53 = 0 ; V_53 < V_23 - 1 ; V_53 ++ ) {
V_51 = F_2 ( V_27 , V_25 ,
V_5 ,
V_17 + ( V_22 * V_53 ) ) ;
if ( ! V_51 ) {
F_7 ( L_4 ) ;
return;
}
V_24 [ V_53 ] = V_51 - V_25 ;
}
V_51 = F_2 ( V_27 , V_25 , V_5 ,
V_18 ) ;
if ( ! V_51 ) {
F_7 ( L_4 ) ;
return;
}
V_24 [ V_23 - 1 ] = V_51 - V_25 ;
V_16 = true ;
}
unsigned long F_16 ( struct V_55 * V_56 )
{
if ( F_17 ( V_56 ) )
return 0 ;
return F_18 ( V_56 -> V_1 ) ? V_56 -> V_1 : 0 ;
}
unsigned long * F_19 ( struct V_55 * V_56 )
{
if ( F_17 ( V_56 ) )
return NULL ;
if ( V_56 -> V_57 )
return & V_56 -> V_57 -> V_1 ;
if ( V_56 -> V_58 )
return ( unsigned long * ) V_56 -> V_58 - 1 ;
return NULL ;
}
static bool F_20 ( struct V_55 * V_56 , unsigned long V_59 ,
T_1 V_60 )
{
struct V_61 * V_62 = & V_56 -> V_61 ;
while ( ! F_21 ( V_62 , ( void * ) V_59 , V_60 ) )
if ( F_22 ( V_62 -> V_63 , V_56 -> V_64 , V_62 ,
& V_56 -> V_65 ) )
return false ;
return true ;
}
static bool F_23 ( struct V_55 * V_56 , unsigned long V_59 ,
unsigned long * V_66 )
{
if ( ! F_20 ( V_56 , V_59 , sizeof( long ) ) )
return false ;
* V_66 = F_24 ( * ( unsigned long * ) V_59 ) ;
return true ;
}
static bool F_25 ( struct V_55 * V_56 , unsigned long V_59 ,
unsigned long * V_1 , unsigned long * V_58 , bool V_67 )
{
T_1 V_68 = V_67 ? V_69 : V_70 ;
T_1 V_71 = V_67 ? V_72 : V_73 ;
struct V_74 * V_57 = (struct V_74 * ) ( V_59 + V_68 - V_69 ) ;
if ( F_26 ( V_75 ) ) {
if ( ! F_20 ( V_56 , V_59 , V_68 ) )
return false ;
* V_1 = V_57 -> V_1 ;
* V_58 = V_57 -> V_58 ;
return true ;
}
if ( ! F_20 ( V_56 , V_59 , V_71 ) )
return false ;
* V_1 = V_57 -> V_1 ;
if ( F_27 ( V_57 ) ) {
if ( ! F_20 ( V_56 , V_59 + V_71 ,
V_69 - V_72 ) )
return false ;
* V_58 = V_57 -> V_58 ;
} else
* V_58 = ( unsigned long ) & V_57 -> V_58 ;
return true ;
}
bool F_28 ( struct V_55 * V_56 )
{
unsigned long V_76 , V_58 , V_77 , V_78 = V_56 -> V_58 ;
enum V_79 V_80 = V_56 -> V_61 . type ;
struct V_2 * V_51 ;
struct V_74 * V_81 ;
bool V_82 = false ;
if ( F_17 ( V_56 ) )
return false ;
F_29 () ;
if ( V_56 -> V_57 && F_27 ( V_56 -> V_57 ) )
goto V_83;
V_51 = F_5 ( V_56 -> signal ? V_56 -> V_1 : V_56 -> V_1 - 1 ) ;
if ( ! V_51 || V_51 -> V_45 == V_46 )
goto V_83;
V_77 = V_56 -> V_1 ;
switch ( V_51 -> V_45 ) {
case V_84 :
V_58 = V_56 -> V_58 + V_51 -> V_71 ;
break;
case V_85 :
V_58 = V_56 -> V_86 + V_51 -> V_71 ;
break;
case V_87 :
V_58 = V_56 -> V_58 + V_51 -> V_71 ;
V_82 = true ;
break;
case V_88 :
V_58 = V_56 -> V_86 + V_51 -> V_71 ;
V_82 = true ;
break;
case V_89 :
if ( ! V_56 -> V_57 || ! V_56 -> V_90 ) {
F_7 ( L_5 ,
( void * ) V_56 -> V_1 ) ;
goto V_83;
}
V_58 = V_56 -> V_57 -> V_91 ;
break;
case V_92 :
if ( ! V_56 -> V_57 || ! V_56 -> V_90 ) {
F_7 ( L_6 ,
( void * ) V_56 -> V_1 ) ;
goto V_83;
}
V_58 = V_56 -> V_57 -> V_93 ;
break;
case V_94 :
if ( ! V_56 -> V_57 || ! V_56 -> V_90 ) {
F_7 ( L_7 ,
( void * ) V_56 -> V_1 ) ;
goto V_83;
}
V_58 = V_56 -> V_57 -> V_95 ;
break;
case V_96 :
if ( ! V_56 -> V_57 || ! V_56 -> V_90 ) {
F_7 ( L_8 ,
( void * ) V_56 -> V_1 ) ;
goto V_83;
}
V_58 = V_56 -> V_57 -> V_97 ;
break;
default:
F_7 ( L_9 ,
V_51 -> V_45 , ( void * ) V_56 -> V_1 ) ;
goto V_83;
}
if ( V_82 ) {
if ( ! F_23 ( V_56 , V_58 , & V_58 ) )
goto V_83;
}
switch ( V_51 -> type ) {
case V_98 :
V_76 = V_58 - sizeof( long ) ;
if ( ! F_23 ( V_56 , V_76 , & V_56 -> V_1 ) )
goto V_83;
V_56 -> V_1 = F_30 ( V_56 -> V_64 , & V_56 -> V_99 ,
V_56 -> V_1 , ( void * ) V_76 ) ;
V_56 -> V_58 = V_58 ;
V_56 -> V_57 = NULL ;
V_56 -> signal = false ;
break;
case V_100 :
if ( ! F_25 ( V_56 , V_58 , & V_56 -> V_1 , & V_56 -> V_58 , true ) ) {
F_7 ( L_10 ,
( void * ) V_58 , ( void * ) V_77 ) ;
goto V_83;
}
V_56 -> V_57 = (struct V_74 * ) V_58 ;
V_56 -> V_90 = true ;
V_56 -> signal = true ;
break;
case V_101 :
if ( ! F_25 ( V_56 , V_58 , & V_56 -> V_1 , & V_56 -> V_58 , false ) ) {
F_7 ( L_11 ,
( void * ) V_58 , ( void * ) V_77 ) ;
goto V_83;
}
V_81 = F_31 ( ( void * ) V_58 , struct V_74 , V_1 ) ;
if ( ( unsigned long ) V_81 >= V_78 &&
F_21 ( & V_56 -> V_61 , V_81 , V_69 ) ) {
V_56 -> V_57 = V_81 ;
V_56 -> V_90 = false ;
} else
V_56 -> V_57 = NULL ;
V_56 -> signal = true ;
break;
default:
F_7 ( L_12 ,
V_51 -> type , ( void * ) V_77 ) ;
break;
}
switch ( V_51 -> V_102 ) {
case V_46 :
if ( V_56 -> V_57 && V_56 -> V_90 )
V_56 -> V_86 = V_56 -> V_57 -> V_86 ;
break;
case V_103 :
if ( ! F_23 ( V_56 , V_58 + V_51 -> V_104 , & V_56 -> V_86 ) )
goto V_83;
break;
case V_85 :
if ( ! F_23 ( V_56 , V_56 -> V_86 + V_51 -> V_104 , & V_56 -> V_86 ) )
goto V_83;
break;
default:
F_7 ( L_13 ,
V_51 -> V_102 , ( void * ) V_77 ) ;
goto V_83;
}
if ( V_56 -> V_61 . type == V_80 &&
F_21 ( & V_56 -> V_61 , ( void * ) V_56 -> V_58 , sizeof( long ) ) &&
V_56 -> V_58 <= V_78 ) {
F_7 ( L_14 ,
( void * ) V_77 ) ;
goto V_83;
}
F_32 () ;
return true ;
V_83:
F_32 () ;
V_56 -> V_61 . type = V_105 ;
return false ;
}
void F_33 ( struct V_55 * V_56 , struct V_106 * V_64 ,
struct V_74 * V_57 , unsigned long * V_107 )
{
memset ( V_56 , 0 , sizeof( * V_56 ) ) ;
V_56 -> V_64 = V_64 ;
if ( F_34 ( V_64 ) )
goto V_83;
if ( V_57 ) {
if ( F_27 ( V_57 ) )
goto V_83;
V_56 -> V_1 = V_57 -> V_1 ;
V_56 -> V_58 = F_35 ( V_57 ) ;
V_56 -> V_86 = V_57 -> V_86 ;
V_56 -> V_57 = V_57 ;
V_56 -> V_90 = true ;
V_56 -> signal = true ;
} else if ( V_64 == V_108 ) {
asm volatile("lea (%%rip), %0\n\t"
"mov %%rsp, %1\n\t"
"mov %%rbp, %2\n\t"
: "=r" (state->ip), "=r" (state->sp),
"=r" (state->bp));
} else {
struct V_109 * V_110 = ( void * ) V_64 -> V_111 . V_58 ;
V_56 -> V_58 = V_64 -> V_111 . V_58 ;
V_56 -> V_86 = F_24 ( V_110 -> V_86 ) ;
V_56 -> V_1 = F_24 ( V_110 -> V_112 ) ;
}
if ( F_22 ( ( unsigned long * ) V_56 -> V_58 , V_56 -> V_64 ,
& V_56 -> V_61 , & V_56 -> V_65 ) )
return;
if ( V_57 ) {
F_28 ( V_56 ) ;
return;
}
while ( ! F_17 ( V_56 ) &&
( ! F_21 ( & V_56 -> V_61 , V_107 , sizeof( long ) ) ||
V_56 -> V_58 <= ( unsigned long ) V_107 ) )
F_28 ( V_56 ) ;
return;
V_83:
V_56 -> V_61 . type = V_105 ;
return;
}
