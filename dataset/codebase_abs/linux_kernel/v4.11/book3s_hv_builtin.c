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
V_7 - V_8 , false , & V_9 ) ;
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
if ( F_34 ( & V_19 -> V_42 . V_43 [ 4 ] ) )
return V_34 ;
return V_44 ;
}
static inline void F_35 ( unsigned long V_45 , T_4 V_46 )
{
__asm__ __volatile__("stbcix %0,0,%1"
: : "r" (val), "r" (paddr) : "memory");
}
void F_36 ( int V_47 )
{
unsigned long V_48 ;
unsigned long V_49 = F_37 ( V_50 ) ;
if ( F_11 ( V_51 ) ) {
V_49 |= F_38 ( V_47 ) ;
__asm__ __volatile__ (PPC_MSGSND(%0) : : "r" (msg));
return;
}
if ( F_11 ( V_52 ) &&
F_39 ( V_47 ) ==
F_39 ( F_40 () ) ) {
V_49 |= F_41 ( V_47 ) ;
__asm__ __volatile__ (PPC_MSGSND(%0) : : "r" (msg));
return;
}
V_48 = V_53 [ V_47 ] . V_25 . V_48 ;
if ( V_48 )
F_35 ( V_48 + V_54 , V_55 ) ;
else
F_42 ( F_38 ( V_47 ) , V_55 ) ;
}
static void F_43 ( struct V_22 * V_23 , int V_56 )
{
int V_47 = V_23 -> V_57 ;
F_44 () ;
for (; V_56 ; V_56 >>= 1 , ++ V_47 )
if ( V_56 & 1 )
F_36 ( V_47 ) ;
}
void F_45 ( int V_58 )
{
struct V_22 * V_23 = V_24 -> V_25 . V_26 ;
int V_27 = V_24 -> V_25 . V_27 ;
struct V_59 * V_60 = V_24 -> V_25 . V_59 ;
int V_61 , V_62 , V_63 ;
V_61 = 0x100 << V_27 ;
do {
V_62 = V_23 -> V_64 ;
} while ( F_46 ( & V_23 -> V_64 , V_62 , V_62 | V_61 ) != V_62 );
if ( ( V_62 >> 8 ) != 0 )
return;
if ( V_58 != V_65 )
F_43 ( V_23 , V_62 & ~ ( 1 << V_27 ) ) ;
if ( ! V_60 )
return;
for ( V_63 = 0 ; V_63 < V_66 ; ++ V_63 ) {
V_23 = V_60 -> V_67 [ V_63 ] ;
if ( ! V_23 )
break;
do {
V_62 = V_23 -> V_64 ;
if ( ( V_62 >> 8 ) != 0 )
break;
} while ( F_46 ( & V_23 -> V_64 , V_62 ,
V_62 | V_68 ) != V_62 );
if ( ( V_62 >> 8 ) == 0 )
F_43 ( V_23 , V_62 ) ;
}
}
static struct V_69 * F_47 ( struct V_70 * V_71 ,
T_5 V_72 )
{
int V_63 ;
for ( V_63 = 0 ; V_63 < V_71 -> V_73 ; V_63 ++ ) {
if ( V_72 == V_71 -> V_74 [ V_63 ] . V_75 ) {
F_48 () ;
return & V_71 -> V_74 [ V_63 ] ;
}
}
return NULL ;
}
static int F_49 ( T_5 V_72 , T_6 V_76 , bool * V_77 )
{
struct V_70 * V_71 ;
struct V_69 * V_78 ;
struct V_18 * V_19 ;
V_19 = V_24 -> V_25 . V_18 ;
if ( ! V_19 )
return 1 ;
V_71 = F_50 ( V_19 -> V_79 ) ;
if ( ! V_71 )
return 1 ;
V_78 = F_47 ( V_71 , V_72 ) ;
if ( ! V_78 )
return 1 ;
V_24 -> V_25 . V_80 = 0 ;
return F_51 ( V_19 , V_76 , V_78 , V_71 , V_77 ) ;
}
static inline int F_49 ( T_5 V_72 , T_6 V_76 , bool * V_77 )
{
return 1 ;
}
long F_52 ( void )
{
long V_81 = 0 ;
long V_82 ;
bool V_77 ;
do {
V_77 = false ;
V_82 = F_53 ( & V_77 ) ;
if ( V_82 && ( V_81 == 0 || V_82 > V_81 ) )
V_81 = V_82 ;
} while ( V_77 );
return V_81 ;
}
static long F_53 ( bool * V_77 )
{
unsigned long V_48 ;
T_5 V_83 ;
T_6 V_76 ;
T_5 V_72 ;
T_4 V_84 ;
T_7 V_82 ;
V_84 = V_24 -> V_25 . V_84 ;
if ( V_84 )
return 1 ;
V_48 = V_24 -> V_25 . V_48 ;
V_82 = 0 ;
if ( ! V_48 )
V_82 = F_54 ( & V_76 , false ) ;
else
V_76 = F_55 ( V_48 + V_85 ) ;
if ( V_82 < 0 )
return 1 ;
V_83 = F_56 ( V_76 ) ;
V_24 -> V_25 . V_80 = V_83 ;
V_72 = V_83 & 0xffffff ;
F_44 () ;
if ( ! V_72 )
return 0 ;
if ( V_72 == V_86 ) {
V_82 = 0 ;
if ( V_48 ) {
F_57 ( V_48 + V_54 , 0xff ) ;
F_58 ( V_48 + V_85 , V_76 ) ;
} else {
F_42 ( F_59 () , 0xff ) ;
V_82 = F_60 ( V_83 ) ;
}
* V_77 = V_82 > 0 ;
F_44 () ;
V_84 = V_24 -> V_25 . V_84 ;
if ( F_61 ( V_84 != 0 ) ) {
if ( V_48 )
F_57 ( V_48 + V_54 , V_55 ) ;
else
F_42 ( F_59 () ,
V_55 ) ;
F_44 () ;
return 1 ;
}
V_24 -> V_25 . V_80 = 0 ;
return - 1 ;
}
return F_49 ( V_72 , V_76 , V_77 ) ;
}
