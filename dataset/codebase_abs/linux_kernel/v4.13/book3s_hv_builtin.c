static int T_1 F_1 ( char * V_1 )
{
F_2 ( L_1 , V_2 , V_1 ) ;
if ( ! V_1 )
return - V_3 ;
return F_3 ( V_1 , 0 , & V_4 ) ;
}
struct V_5 * F_4 ( unsigned long V_6 )
{
F_5 ( F_6 ( V_6 ) < V_7 - V_8 ) ;
return F_7 ( V_9 , V_6 , F_6 ( V_10 ) ,
V_11 ) ;
}
void F_8 ( struct V_5 * V_5 , unsigned long V_6 )
{
F_9 ( V_9 , V_5 , V_6 ) ;
}
void T_1 F_10 ( void )
{
unsigned long V_12 ;
struct V_13 * V_14 ;
T_2 V_15 = 0 ;
if ( ! F_11 ( V_16 ) )
return;
F_12 (memory, reg)
V_15 += F_13 ( V_14 ) -
F_14 ( V_14 ) ;
V_15 = ( V_15 * V_4 / 100 ) << V_8 ;
if ( V_15 ) {
F_2 ( L_2 , V_2 ,
( unsigned long ) V_15 / V_17 ) ;
V_12 = V_10 << V_8 ;
F_15 ( 0 , V_15 , 0 , V_12 ,
V_7 - V_8 , false , L_3 ,
& V_9 ) ;
}
}
long int F_16 ( struct V_18 * V_19 , int V_20 ,
unsigned int V_21 )
{
struct V_22 * V_23 = V_24 -> V_25 . V_26 ;
int V_27 = V_24 -> V_25 . V_27 ;
int V_28 ;
int V_29 ;
int V_30 ;
T_3 V_31 = F_17 () + 10 * V_32 ;
int V_33 = V_34 ;
F_18 ( V_27 , & V_23 -> V_35 ) ;
while ( ( F_17 () < V_31 ) && ! F_19 ( V_23 ) ) {
V_28 = F_20 ( V_23 ) ;
V_29 = V_23 -> V_36 ;
V_30 = V_23 -> V_35 ;
if ( ( V_29 | V_30 ) == V_28 ) {
V_33 = V_37 ;
break;
}
}
F_21 ( V_27 , & V_23 -> V_35 ) ;
return V_33 ;
}
void F_22 ( void )
{
F_23 () ;
F_24 ( & V_38 ) ;
F_25 () ;
}
void F_26 ( void )
{
F_23 () ;
F_27 ( & V_38 ) ;
F_25 () ;
}
bool F_28 ( void )
{
return F_29 ( & V_38 ) != 0 ;
}
int F_30 ( unsigned long V_39 )
{
V_39 /= 4 ;
if ( V_39 < V_40 - V_41 &&
V_41 [ V_39 ] )
return 1 ;
return 0 ;
}
int F_31 ( void )
{
return F_32 () ;
}
long F_33 ( struct V_18 * V_19 )
{
int V_42 ;
if ( F_34 ( V_19 -> V_43 ) && ( F_35 () & V_44 ) )
V_42 = F_36 ( & V_19 -> V_45 . V_46 [ 4 ] ) ;
else
V_42 = F_37 ( & V_19 -> V_45 . V_46 [ 4 ] ) ;
if ( V_42 )
return V_34 ;
return V_47 ;
}
void F_38 ( int V_48 )
{
void T_4 * V_49 ;
unsigned long V_50 = F_39 ( V_51 ) ;
if ( F_11 ( V_52 ) ) {
V_50 |= F_40 ( V_48 ) ;
__asm__ __volatile__ (PPC_MSGSND(%0) : : "r" (msg));
return;
}
if ( F_11 ( V_53 ) &&
F_41 ( V_48 ) ==
F_41 ( F_42 () ) ) {
V_50 |= F_43 ( V_48 ) ;
__asm__ __volatile__ (PPC_MSGSND(%0) : : "r" (msg));
return;
}
if ( F_44 ( F_45 () ) )
return;
V_49 = V_54 [ V_48 ] . V_25 . V_49 ;
if ( V_49 )
F_46 ( V_55 , V_49 + V_56 ) ;
else
F_47 ( F_40 ( V_48 ) , V_55 ) ;
}
static void F_48 ( struct V_22 * V_23 , int V_57 )
{
int V_48 = V_23 -> V_58 ;
F_49 () ;
for (; V_57 ; V_57 >>= 1 , ++ V_48 )
if ( V_57 & 1 )
F_38 ( V_48 ) ;
}
void F_50 ( int V_59 )
{
struct V_22 * V_23 = V_24 -> V_25 . V_26 ;
int V_27 = V_24 -> V_25 . V_27 ;
struct V_60 * V_61 = V_24 -> V_25 . V_60 ;
int V_62 , V_63 , V_64 ;
V_62 = 0x100 << V_27 ;
do {
V_63 = V_23 -> V_65 ;
} while ( F_51 ( & V_23 -> V_65 , V_63 , V_63 | V_62 ) != V_63 );
if ( ( V_63 >> 8 ) != 0 )
return;
if ( V_59 != V_66 )
F_48 ( V_23 , V_63 & ~ ( 1 << V_27 ) ) ;
if ( ! V_61 )
return;
for ( V_64 = 0 ; V_64 < V_67 ; ++ V_64 ) {
V_23 = V_61 -> V_23 [ V_64 ] ;
if ( ! V_23 )
break;
do {
V_63 = V_23 -> V_65 ;
if ( ( V_63 >> 8 ) != 0 )
break;
} while ( F_51 ( & V_23 -> V_65 , V_63 ,
V_63 | V_68 ) != V_63 );
if ( ( V_63 >> 8 ) == 0 )
F_48 ( V_23 , V_63 ) ;
}
}
static struct V_69 * F_52 ( struct V_70 * V_71 ,
T_5 V_72 )
{
int V_64 ;
for ( V_64 = 0 ; V_64 < V_71 -> V_73 ; V_64 ++ ) {
if ( V_72 == V_71 -> V_74 [ V_64 ] . V_75 ) {
F_53 () ;
return & V_71 -> V_74 [ V_64 ] ;
}
}
return NULL ;
}
static int F_54 ( T_5 V_72 , T_6 V_76 , bool * V_77 )
{
struct V_70 * V_71 ;
struct V_69 * V_78 ;
struct V_18 * V_19 ;
V_19 = V_24 -> V_25 . V_18 ;
if ( ! V_19 )
return 1 ;
V_71 = F_55 ( V_19 -> V_43 ) ;
if ( ! V_71 )
return 1 ;
V_78 = F_52 ( V_71 , V_72 ) ;
if ( ! V_78 )
return 1 ;
V_24 -> V_25 . V_79 = 0 ;
return F_56 ( V_19 , V_76 , V_78 , V_71 , V_77 ) ;
}
static inline int F_54 ( T_5 V_72 , T_6 V_76 , bool * V_77 )
{
return 1 ;
}
long F_57 ( void )
{
long V_80 = 0 ;
long V_81 ;
bool V_77 ;
if ( F_45 () )
return 1 ;
do {
V_77 = false ;
V_81 = F_58 ( & V_77 ) ;
if ( V_81 && ( V_80 == 0 || V_81 > V_80 ) )
V_80 = V_81 ;
} while ( V_77 );
return V_80 ;
}
static long F_58 ( bool * V_77 )
{
void T_4 * V_49 ;
T_5 V_82 ;
T_6 V_76 ;
T_5 V_72 ;
T_7 V_83 ;
T_8 V_81 ;
if ( F_45 () )
return 1 ;
V_83 = V_24 -> V_25 . V_83 ;
if ( V_83 )
return 1 ;
V_49 = V_24 -> V_25 . V_49 ;
V_81 = 0 ;
if ( ! V_49 )
V_81 = F_59 ( & V_76 , false ) ;
else
V_76 = F_60 ( V_49 + V_84 ) ;
if ( V_81 < 0 )
return 1 ;
V_82 = F_61 ( V_76 ) ;
V_24 -> V_25 . V_79 = V_82 ;
V_72 = V_82 & 0xffffff ;
F_49 () ;
if ( ! V_72 )
return 0 ;
if ( V_72 == V_85 ) {
V_81 = 0 ;
if ( V_49 ) {
F_46 ( 0xff , V_49 + V_56 ) ;
F_62 ( V_76 , V_49 + V_84 ) ;
} else {
F_47 ( F_63 () , 0xff ) ;
V_81 = F_64 ( V_82 ) ;
}
* V_77 = V_81 > 0 ;
F_49 () ;
V_83 = V_24 -> V_25 . V_83 ;
if ( F_65 ( V_83 != 0 ) ) {
if ( V_49 )
F_46 ( V_55 ,
V_49 + V_56 ) ;
else
F_47 ( F_63 () ,
V_55 ) ;
F_49 () ;
return 1 ;
}
V_24 -> V_25 . V_79 = 0 ;
return - 1 ;
}
return F_54 ( V_72 , V_76 , V_77 ) ;
}
static inline bool F_66 ( void )
{
return ! ( F_35 () & V_86 ) ;
}
unsigned long F_67 ( struct V_18 * V_19 )
{
if ( F_45 () ) {
if ( F_66 () )
return F_68 ( V_19 ) ;
if ( F_65 ( ! V_87 ) )
return V_88 ;
return V_87 ( V_19 ) ;
} else
return F_69 ( V_19 ) ;
}
unsigned long F_70 ( struct V_18 * V_19 )
{
V_19 -> V_45 . V_46 [ 5 ] = F_17 () ;
if ( F_45 () ) {
if ( F_66 () )
return F_68 ( V_19 ) ;
if ( F_65 ( ! V_87 ) )
return V_88 ;
return V_87 ( V_19 ) ;
} else
return F_69 ( V_19 ) ;
}
unsigned long F_71 ( struct V_18 * V_19 , unsigned long V_89 )
{
if ( F_45 () ) {
if ( F_66 () )
return F_72 ( V_19 , V_89 ) ;
if ( F_65 ( ! V_90 ) )
return V_88 ;
return V_90 ( V_19 , V_89 ) ;
} else
return V_37 ;
}
int F_73 ( struct V_18 * V_19 , unsigned long V_89 ,
unsigned long V_91 )
{
if ( F_45 () ) {
if ( F_66 () )
return F_74 ( V_19 , V_89 , V_91 ) ;
if ( F_65 ( ! V_92 ) )
return V_88 ;
return V_92 ( V_19 , V_89 , V_91 ) ;
} else
return F_75 ( V_19 , V_89 , V_91 ) ;
}
int F_76 ( struct V_18 * V_19 , unsigned long V_93 )
{
if ( F_45 () ) {
if ( F_66 () )
return F_77 ( V_19 , V_93 ) ;
if ( F_65 ( ! V_94 ) )
return V_88 ;
return V_94 ( V_19 , V_93 ) ;
} else
return F_78 ( V_19 , V_93 ) ;
}
int F_79 ( struct V_18 * V_19 , unsigned long V_76 )
{
if ( F_45 () ) {
if ( F_66 () )
return F_80 ( V_19 , V_76 ) ;
if ( F_65 ( ! V_95 ) )
return V_88 ;
return V_95 ( V_19 , V_76 ) ;
} else
return F_81 ( V_19 , V_76 ) ;
}
