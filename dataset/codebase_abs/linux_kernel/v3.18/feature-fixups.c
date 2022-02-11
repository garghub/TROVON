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
void F_12 ( void )
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
static long F_14 ( struct V_1 * V_31 , unsigned int * V_32 )
{
return ( unsigned long ) V_32 - ( unsigned long ) V_31 ;
}
static void F_15 ( void )
{
extern unsigned int V_33 ;
extern unsigned int V_34 ;
extern unsigned int V_35 ;
extern unsigned int V_36 ;
int V_37 = & V_34 - & V_33 ;
V_38 . V_10 = V_38 . V_17 = 8 ;
V_38 . V_13 = F_14 ( & V_38 , & V_33 + 1 ) ;
V_38 . V_14 = F_14 ( & V_38 , & V_33 + 2 ) ;
V_38 . V_15 = V_38 . V_16 = 0 ;
F_16 ( memcmp ( & V_33 , & V_35 , V_37 ) == 0 ) ;
F_7 ( 8 , & V_38 ) ;
F_16 ( memcmp ( & V_33 , & V_35 , V_37 ) == 0 ) ;
F_7 ( 0 , & V_38 ) ;
F_16 ( memcmp ( & V_33 , & V_36 , V_37 ) == 0 ) ;
memcpy ( & V_33 , & V_35 , V_37 ) ;
F_16 ( memcmp ( & V_33 , & V_35 , V_37 ) == 0 ) ;
F_7 ( ~ 8 , & V_38 ) ;
F_16 ( memcmp ( & V_33 , & V_36 , V_37 ) == 0 ) ;
}
static void F_17 ( void )
{
extern unsigned int V_39 ;
extern unsigned int V_40 ;
extern unsigned int V_41 ;
extern unsigned int V_42 ;
extern unsigned int V_43 ;
int V_37 = & V_40 - & V_39 ;
V_38 . V_10 = V_38 . V_17 = 0xF ;
V_38 . V_13 = F_14 ( & V_38 , & V_39 + 1 ) ;
V_38 . V_14 = F_14 ( & V_38 , & V_39 + 2 ) ;
V_38 . V_15 = F_14 ( & V_38 , & V_42 ) ;
V_38 . V_16 = F_14 ( & V_38 , & V_42 + 1 ) ;
F_16 ( memcmp ( & V_39 , & V_41 , V_37 ) == 0 ) ;
F_7 ( 0xF , & V_38 ) ;
F_16 ( memcmp ( & V_39 , & V_41 , V_37 ) == 0 ) ;
F_7 ( 0 , & V_38 ) ;
F_16 ( memcmp ( & V_39 , & V_43 , V_37 ) == 0 ) ;
memcpy ( & V_39 , & V_41 , V_37 ) ;
F_16 ( memcmp ( & V_39 , & V_41 , V_37 ) == 0 ) ;
F_7 ( ~ 0xF , & V_38 ) ;
F_16 ( memcmp ( & V_39 , & V_43 , V_37 ) == 0 ) ;
}
static void F_18 ( void )
{
extern unsigned int V_44 ;
extern unsigned int V_45 ;
extern unsigned int V_46 ;
extern unsigned int V_47 ;
int V_37 = & V_45 - & V_44 ;
V_38 . V_10 = V_38 . V_17 = 0xC ;
V_38 . V_13 = F_14 ( & V_38 , & V_44 + 1 ) ;
V_38 . V_14 = F_14 ( & V_38 , & V_44 + 2 ) ;
V_38 . V_15 = F_14 ( & V_38 , & V_47 ) ;
V_38 . V_16 = F_14 ( & V_38 , & V_47 + 2 ) ;
F_16 ( memcmp ( & V_44 , & V_46 , V_37 ) == 0 ) ;
F_16 ( F_7 ( 0xF , & V_38 ) == 1 ) ;
F_16 ( memcmp ( & V_44 , & V_46 , V_37 ) == 0 ) ;
F_16 ( F_7 ( 0 , & V_38 ) == 1 ) ;
F_16 ( memcmp ( & V_44 , & V_46 , V_37 ) == 0 ) ;
F_16 ( F_7 ( ~ 0xF , & V_38 ) == 1 ) ;
F_16 ( memcmp ( & V_44 , & V_46 , V_37 ) == 0 ) ;
}
static void F_19 ( void )
{
extern unsigned int V_48 ;
extern unsigned int V_49 ;
extern unsigned int V_50 ;
extern unsigned int V_51 ;
extern unsigned int V_52 ;
int V_37 = & V_49 - & V_48 ;
unsigned long V_53 ;
V_53 = 1UL << ( (sizeof( unsigned long ) - 1 ) * 8 ) ;
V_38 . V_10 = V_38 . V_17 = V_53 ;
V_38 . V_13 = F_14 ( & V_38 , & V_48 + 1 ) ;
V_38 . V_14 = F_14 ( & V_38 , & V_48 + 5 ) ;
V_38 . V_15 = F_14 ( & V_38 , & V_51 ) ;
V_38 . V_16 = F_14 ( & V_38 , & V_51 + 2 ) ;
F_16 ( memcmp ( & V_48 , & V_50 , V_37 ) == 0 ) ;
F_7 ( V_53 , & V_38 ) ;
F_16 ( memcmp ( & V_48 , & V_50 , V_37 ) == 0 ) ;
F_7 ( 0 , & V_38 ) ;
F_16 ( memcmp ( & V_48 , & V_52 , V_37 ) == 0 ) ;
memcpy ( & V_48 , & V_50 , V_37 ) ;
F_16 ( memcmp ( & V_48 , & V_50 , V_37 ) == 0 ) ;
F_7 ( ~ V_53 , & V_38 ) ;
F_16 ( memcmp ( & V_48 , & V_52 , V_37 ) == 0 ) ;
}
static void F_20 ( void )
{
extern unsigned int V_54 ;
extern unsigned int V_55 ;
extern unsigned int V_56 ;
int V_37 = & V_55 - & V_54 ;
F_16 ( memcmp ( & V_54 , & V_56 , V_37 ) == 0 ) ;
}
static void F_21 ( void )
{
extern unsigned int V_57 ;
extern unsigned int V_58 ;
extern unsigned int V_59 ;
int V_37 = & V_58 - & V_57 ;
F_16 ( memcmp ( & V_57 , & V_59 , V_37 ) == 0 ) ;
}
static void F_22 ( void )
{
extern T_1 V_60 ;
extern T_1 V_61 ;
unsigned long V_37 = & V_61 -
& V_60 ;
F_16 ( memcmp ( & V_60 ,
& V_61 , V_37 ) == 0 ) ;
}
static void F_23 ( void )
{
#ifdef V_24
extern T_1 V_62 ;
extern T_1 V_63 ;
unsigned long V_37 = & V_63 -
& V_62 ;
F_16 ( memcmp ( & V_62 ,
& V_63 , V_37 ) == 0 ) ;
#endif
}
static void F_24 ( void )
{
extern T_1 V_64 ;
extern T_1 V_65 ;
extern T_1 V_66 ;
extern T_1 V_67 ;
unsigned long V_37 = & V_65 -
& V_64 ;
if ( V_68 -> V_69 & V_22 ) {
F_16 ( memcmp ( & V_64 ,
& V_66 , V_37 ) == 0 ) ;
} else {
F_16 ( memcmp ( & V_64 ,
& V_67 , V_37 ) == 0 ) ;
}
}
static int T_2 F_25 ( void )
{
F_10 ( V_70 L_3 ) ;
F_15 () ;
F_17 () ;
F_18 () ;
F_19 () ;
F_20 () ;
F_21 () ;
F_22 () ;
F_23 () ;
F_24 () ;
return 0 ;
}
