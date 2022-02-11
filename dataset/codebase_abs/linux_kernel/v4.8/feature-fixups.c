static unsigned int * F_1 ( struct V_1 * V_2 , long V_3 )
{
return ( unsigned int * ) ( ( unsigned long ) V_2 + V_3 ) ;
}
static int F_2 ( unsigned int * V_4 , unsigned int * V_5 ,
unsigned int * V_6 , unsigned int * V_7 )
{
unsigned int V_8 ;
V_8 = * V_4 ;
if ( F_3 ( * V_4 ) ) {
unsigned int * V_9 = ( unsigned int * ) F_4 ( V_4 ) ;
if ( V_9 < V_6 || V_9 >= V_7 ) {
V_8 = F_5 ( V_5 , V_4 ) ;
if ( ! V_8 )
return 1 ;
}
}
F_6 ( V_5 , V_8 ) ;
return 0 ;
}
static int F_7 ( unsigned long V_10 , struct V_1 * V_2 )
{
unsigned int * V_11 , * V_12 , * V_6 , * V_7 , * V_4 , * V_5 ;
V_11 = F_1 ( V_2 , V_2 -> V_13 ) ;
V_12 = F_1 ( V_2 , V_2 -> V_14 ) ;
V_6 = F_1 ( V_2 , V_2 -> V_15 ) ;
V_7 = F_1 ( V_2 , V_2 -> V_16 ) ;
if ( ( V_7 - V_6 ) > ( V_12 - V_11 ) )
return 1 ;
if ( ( V_10 & V_2 -> V_17 ) == V_2 -> V_10 )
return 0 ;
V_4 = V_6 ;
V_5 = V_11 ;
for (; V_4 < V_7 ; V_4 ++ , V_5 ++ ) {
if ( F_2 ( V_4 , V_5 , V_6 , V_7 ) )
return 1 ;
}
for (; V_5 < V_12 ; V_5 ++ )
F_6 ( V_5 , V_18 ) ;
return 0 ;
}
void F_8 ( unsigned long V_10 , void * V_19 , void * V_20 )
{
struct V_1 * V_2 , * V_21 ;
V_2 = V_19 ;
V_21 = V_20 ;
for (; V_2 < V_21 ; V_2 ++ ) {
if ( F_7 ( V_10 , V_2 ) ) {
F_9 ( 1 ) ;
F_10 ( L_1 \
L_2 ,
F_1 ( V_2 , V_2 -> V_13 ) ,
F_1 ( V_2 , V_2 -> V_14 ) ,
F_1 ( V_2 , V_2 -> V_15 ) ,
F_1 ( V_2 , V_2 -> V_16 ) ) ;
}
}
}
void F_11 ( unsigned long V_10 , void * V_19 , void * V_20 )
{
long * V_11 , * V_12 ;
unsigned int * V_5 ;
if ( ! ( V_10 & V_22 ) )
return ;
V_11 = V_19 ;
V_12 = V_20 ;
for (; V_11 < V_12 ; V_11 ++ ) {
V_5 = ( void * ) V_11 + * V_11 ;
F_6 ( V_5 , V_23 ) ;
}
}
static void F_12 ( void )
{
#if F_13 ( V_24 ) && F_13 ( V_25 )
int * V_4 , * V_5 ;
unsigned long V_26 ;
if ( V_27 == 0 )
return;
V_4 = ( int * ) ( V_28 + V_27 ) ;
V_5 = ( int * ) V_28 ;
V_26 = ( V_29 - V_30 ) / sizeof( int ) ;
while ( V_26 -- ) {
F_6 ( V_5 , * V_4 ) ;
V_4 ++ ;
V_5 ++ ;
}
#endif
}
void T_1 F_14 ( void )
{
struct V_31 * V_32 = F_15 ( * F_15 ( & V_33 ) ) ;
* F_15 ( & V_34 ) = V_32 -> V_35 ;
* F_15 ( & V_36 ) = V_32 -> V_37 ;
F_8 ( V_32 -> V_35 ,
F_15 ( & V_38 ) ,
F_15 ( & V_39 ) ) ;
F_8 ( V_32 -> V_37 ,
F_15 ( & V_40 ) ,
F_15 ( & V_41 ) ) ;
F_11 ( V_32 -> V_35 ,
F_15 ( & V_42 ) ,
F_15 ( & V_43 ) ) ;
#ifdef V_24
V_44 = V_45 ;
F_8 ( V_45 ,
& V_46 , & V_47 ) ;
#endif
F_12 () ;
}
void T_1 F_16 ( void )
{
F_17 () ;
F_18 () ;
F_19 () ;
}
static int T_1 F_20 ( void )
{
F_21 ( V_34 != V_33 -> V_35 ,
L_3 ) ;
F_21 ( V_36 != V_33 -> V_37 ,
L_4 ) ;
#ifdef V_24
F_21 ( V_44 != V_45 ,
L_5 ) ;
#endif
return 0 ;
}
static long F_22 ( struct V_1 * V_48 , unsigned int * V_49 )
{
return ( unsigned long ) V_49 - ( unsigned long ) V_48 ;
}
static void F_23 ( void )
{
extern unsigned int V_50 ;
extern unsigned int V_51 ;
extern unsigned int V_52 ;
extern unsigned int V_53 ;
int V_54 = & V_51 - & V_50 ;
V_55 . V_10 = V_55 . V_17 = 8 ;
V_55 . V_13 = F_22 ( & V_55 , & V_50 + 1 ) ;
V_55 . V_14 = F_22 ( & V_55 , & V_50 + 2 ) ;
V_55 . V_15 = V_55 . V_16 = 0 ;
F_24 ( memcmp ( & V_50 , & V_52 , V_54 ) == 0 ) ;
F_7 ( 8 , & V_55 ) ;
F_24 ( memcmp ( & V_50 , & V_52 , V_54 ) == 0 ) ;
F_7 ( 0 , & V_55 ) ;
F_24 ( memcmp ( & V_50 , & V_53 , V_54 ) == 0 ) ;
memcpy ( & V_50 , & V_52 , V_54 ) ;
F_24 ( memcmp ( & V_50 , & V_52 , V_54 ) == 0 ) ;
F_7 ( ~ 8 , & V_55 ) ;
F_24 ( memcmp ( & V_50 , & V_53 , V_54 ) == 0 ) ;
}
static void F_25 ( void )
{
extern unsigned int V_56 ;
extern unsigned int V_57 ;
extern unsigned int V_58 ;
extern unsigned int V_59 ;
extern unsigned int V_60 ;
int V_54 = & V_57 - & V_56 ;
V_55 . V_10 = V_55 . V_17 = 0xF ;
V_55 . V_13 = F_22 ( & V_55 , & V_56 + 1 ) ;
V_55 . V_14 = F_22 ( & V_55 , & V_56 + 2 ) ;
V_55 . V_15 = F_22 ( & V_55 , & V_59 ) ;
V_55 . V_16 = F_22 ( & V_55 , & V_59 + 1 ) ;
F_24 ( memcmp ( & V_56 , & V_58 , V_54 ) == 0 ) ;
F_7 ( 0xF , & V_55 ) ;
F_24 ( memcmp ( & V_56 , & V_58 , V_54 ) == 0 ) ;
F_7 ( 0 , & V_55 ) ;
F_24 ( memcmp ( & V_56 , & V_60 , V_54 ) == 0 ) ;
memcpy ( & V_56 , & V_58 , V_54 ) ;
F_24 ( memcmp ( & V_56 , & V_58 , V_54 ) == 0 ) ;
F_7 ( ~ 0xF , & V_55 ) ;
F_24 ( memcmp ( & V_56 , & V_60 , V_54 ) == 0 ) ;
}
static void F_26 ( void )
{
extern unsigned int V_61 ;
extern unsigned int V_62 ;
extern unsigned int V_63 ;
extern unsigned int V_64 ;
int V_54 = & V_62 - & V_61 ;
V_55 . V_10 = V_55 . V_17 = 0xC ;
V_55 . V_13 = F_22 ( & V_55 , & V_61 + 1 ) ;
V_55 . V_14 = F_22 ( & V_55 , & V_61 + 2 ) ;
V_55 . V_15 = F_22 ( & V_55 , & V_64 ) ;
V_55 . V_16 = F_22 ( & V_55 , & V_64 + 2 ) ;
F_24 ( memcmp ( & V_61 , & V_63 , V_54 ) == 0 ) ;
F_24 ( F_7 ( 0xF , & V_55 ) == 1 ) ;
F_24 ( memcmp ( & V_61 , & V_63 , V_54 ) == 0 ) ;
F_24 ( F_7 ( 0 , & V_55 ) == 1 ) ;
F_24 ( memcmp ( & V_61 , & V_63 , V_54 ) == 0 ) ;
F_24 ( F_7 ( ~ 0xF , & V_55 ) == 1 ) ;
F_24 ( memcmp ( & V_61 , & V_63 , V_54 ) == 0 ) ;
}
static void F_27 ( void )
{
extern unsigned int V_65 ;
extern unsigned int V_66 ;
extern unsigned int V_67 ;
extern unsigned int V_68 ;
extern unsigned int V_69 ;
int V_54 = & V_66 - & V_65 ;
unsigned long V_70 ;
V_70 = 1UL << ( (sizeof( unsigned long ) - 1 ) * 8 ) ;
V_55 . V_10 = V_55 . V_17 = V_70 ;
V_55 . V_13 = F_22 ( & V_55 , & V_65 + 1 ) ;
V_55 . V_14 = F_22 ( & V_55 , & V_65 + 5 ) ;
V_55 . V_15 = F_22 ( & V_55 , & V_68 ) ;
V_55 . V_16 = F_22 ( & V_55 , & V_68 + 2 ) ;
F_24 ( memcmp ( & V_65 , & V_67 , V_54 ) == 0 ) ;
F_7 ( V_70 , & V_55 ) ;
F_24 ( memcmp ( & V_65 , & V_67 , V_54 ) == 0 ) ;
F_7 ( 0 , & V_55 ) ;
F_24 ( memcmp ( & V_65 , & V_69 , V_54 ) == 0 ) ;
memcpy ( & V_65 , & V_67 , V_54 ) ;
F_24 ( memcmp ( & V_65 , & V_67 , V_54 ) == 0 ) ;
F_7 ( ~ V_70 , & V_55 ) ;
F_24 ( memcmp ( & V_65 , & V_69 , V_54 ) == 0 ) ;
}
static void F_28 ( void )
{
extern unsigned int V_71 ;
extern unsigned int V_72 ;
extern unsigned int V_73 ;
int V_54 = & V_72 - & V_71 ;
F_24 ( memcmp ( & V_71 , & V_73 , V_54 ) == 0 ) ;
}
static void F_29 ( void )
{
extern unsigned int V_74 ;
extern unsigned int V_75 ;
extern unsigned int V_76 ;
int V_54 = & V_75 - & V_74 ;
F_24 ( memcmp ( & V_74 , & V_76 , V_54 ) == 0 ) ;
}
static void F_30 ( void )
{
extern T_2 V_77 ;
extern T_2 V_78 ;
unsigned long V_54 = & V_78 -
& V_77 ;
F_24 ( memcmp ( & V_77 ,
& V_78 , V_54 ) == 0 ) ;
}
static void F_31 ( void )
{
#ifdef V_24
extern T_2 V_79 ;
extern T_2 V_80 ;
unsigned long V_54 = & V_80 -
& V_79 ;
F_24 ( memcmp ( & V_79 ,
& V_80 , V_54 ) == 0 ) ;
#endif
}
static void F_32 ( void )
{
extern T_2 V_81 ;
extern T_2 V_82 ;
extern T_2 V_83 ;
extern T_2 V_84 ;
unsigned long V_54 = & V_82 -
& V_81 ;
if ( V_33 -> V_35 & V_22 ) {
F_24 ( memcmp ( & V_81 ,
& V_83 , V_54 ) == 0 ) ;
} else {
F_24 ( memcmp ( & V_81 ,
& V_84 , V_54 ) == 0 ) ;
}
}
static int T_1 F_33 ( void )
{
F_10 ( V_85 L_6 ) ;
F_23 () ;
F_25 () ;
F_26 () ;
F_27 () ;
F_28 () ;
F_29 () ;
F_30 () ;
F_31 () ;
F_32 () ;
return 0 ;
}
