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
static long F_12 ( struct V_1 * V_24 , unsigned int * V_25 )
{
return ( unsigned long ) V_25 - ( unsigned long ) V_24 ;
}
void F_13 ( void )
{
extern unsigned int V_26 ;
extern unsigned int V_27 ;
extern unsigned int V_28 ;
extern unsigned int V_29 ;
int V_30 = & V_27 - & V_26 ;
V_31 . V_10 = V_31 . V_17 = 8 ;
V_31 . V_13 = F_12 ( & V_31 , & V_26 + 1 ) ;
V_31 . V_14 = F_12 ( & V_31 , & V_26 + 2 ) ;
V_31 . V_15 = V_31 . V_16 = 0 ;
F_14 ( memcmp ( & V_26 , & V_28 , V_30 ) == 0 ) ;
F_7 ( 8 , & V_31 ) ;
F_14 ( memcmp ( & V_26 , & V_28 , V_30 ) == 0 ) ;
F_7 ( 0 , & V_31 ) ;
F_14 ( memcmp ( & V_26 , & V_29 , V_30 ) == 0 ) ;
memcpy ( & V_26 , & V_28 , V_30 ) ;
F_14 ( memcmp ( & V_26 , & V_28 , V_30 ) == 0 ) ;
F_7 ( ~ 8 , & V_31 ) ;
F_14 ( memcmp ( & V_26 , & V_29 , V_30 ) == 0 ) ;
}
static void F_15 ( void )
{
extern unsigned int V_32 ;
extern unsigned int V_33 ;
extern unsigned int V_34 ;
extern unsigned int V_35 ;
extern unsigned int V_36 ;
int V_30 = & V_33 - & V_32 ;
V_31 . V_10 = V_31 . V_17 = 0xF ;
V_31 . V_13 = F_12 ( & V_31 , & V_32 + 1 ) ;
V_31 . V_14 = F_12 ( & V_31 , & V_32 + 2 ) ;
V_31 . V_15 = F_12 ( & V_31 , & V_35 ) ;
V_31 . V_16 = F_12 ( & V_31 , & V_35 + 1 ) ;
F_14 ( memcmp ( & V_32 , & V_34 , V_30 ) == 0 ) ;
F_7 ( 0xF , & V_31 ) ;
F_14 ( memcmp ( & V_32 , & V_34 , V_30 ) == 0 ) ;
F_7 ( 0 , & V_31 ) ;
F_14 ( memcmp ( & V_32 , & V_36 , V_30 ) == 0 ) ;
memcpy ( & V_32 , & V_34 , V_30 ) ;
F_14 ( memcmp ( & V_32 , & V_34 , V_30 ) == 0 ) ;
F_7 ( ~ 0xF , & V_31 ) ;
F_14 ( memcmp ( & V_32 , & V_36 , V_30 ) == 0 ) ;
}
static void F_16 ( void )
{
extern unsigned int V_37 ;
extern unsigned int V_38 ;
extern unsigned int V_39 ;
extern unsigned int V_40 ;
int V_30 = & V_38 - & V_37 ;
V_31 . V_10 = V_31 . V_17 = 0xC ;
V_31 . V_13 = F_12 ( & V_31 , & V_37 + 1 ) ;
V_31 . V_14 = F_12 ( & V_31 , & V_37 + 2 ) ;
V_31 . V_15 = F_12 ( & V_31 , & V_40 ) ;
V_31 . V_16 = F_12 ( & V_31 , & V_40 + 2 ) ;
F_14 ( memcmp ( & V_37 , & V_39 , V_30 ) == 0 ) ;
F_14 ( F_7 ( 0xF , & V_31 ) == 1 ) ;
F_14 ( memcmp ( & V_37 , & V_39 , V_30 ) == 0 ) ;
F_14 ( F_7 ( 0 , & V_31 ) == 1 ) ;
F_14 ( memcmp ( & V_37 , & V_39 , V_30 ) == 0 ) ;
F_14 ( F_7 ( ~ 0xF , & V_31 ) == 1 ) ;
F_14 ( memcmp ( & V_37 , & V_39 , V_30 ) == 0 ) ;
}
static void F_17 ( void )
{
extern unsigned int V_41 ;
extern unsigned int V_42 ;
extern unsigned int V_43 ;
extern unsigned int V_44 ;
extern unsigned int V_45 ;
int V_30 = & V_42 - & V_41 ;
unsigned long V_46 ;
V_46 = 1UL << ( (sizeof( unsigned long ) - 1 ) * 8 ) ;
V_31 . V_10 = V_31 . V_17 = V_46 ;
V_31 . V_13 = F_12 ( & V_31 , & V_41 + 1 ) ;
V_31 . V_14 = F_12 ( & V_31 , & V_41 + 5 ) ;
V_31 . V_15 = F_12 ( & V_31 , & V_44 ) ;
V_31 . V_16 = F_12 ( & V_31 , & V_44 + 2 ) ;
F_14 ( memcmp ( & V_41 , & V_43 , V_30 ) == 0 ) ;
F_7 ( V_46 , & V_31 ) ;
F_14 ( memcmp ( & V_41 , & V_43 , V_30 ) == 0 ) ;
F_7 ( 0 , & V_31 ) ;
F_14 ( memcmp ( & V_41 , & V_45 , V_30 ) == 0 ) ;
memcpy ( & V_41 , & V_43 , V_30 ) ;
F_14 ( memcmp ( & V_41 , & V_43 , V_30 ) == 0 ) ;
F_7 ( ~ V_46 , & V_31 ) ;
F_14 ( memcmp ( & V_41 , & V_45 , V_30 ) == 0 ) ;
}
static void F_18 ( void )
{
extern unsigned int V_47 ;
extern unsigned int V_48 ;
extern unsigned int V_49 ;
int V_30 = & V_48 - & V_47 ;
F_14 ( memcmp ( & V_47 , & V_49 , V_30 ) == 0 ) ;
}
static void F_19 ( void )
{
extern unsigned int V_50 ;
extern unsigned int V_51 ;
extern unsigned int V_52 ;
int V_30 = & V_51 - & V_50 ;
F_14 ( memcmp ( & V_50 , & V_52 , V_30 ) == 0 ) ;
}
static void F_20 ( void )
{
extern T_1 V_53 ;
extern T_1 V_54 ;
unsigned long V_30 = & V_54 -
& V_53 ;
F_14 ( memcmp ( & V_53 ,
& V_54 , V_30 ) == 0 ) ;
}
static void F_21 ( void )
{
#ifdef F_22
extern T_1 V_55 ;
extern T_1 V_56 ;
unsigned long V_30 = & V_56 -
& V_55 ;
F_14 ( memcmp ( & V_55 ,
& V_56 , V_30 ) == 0 ) ;
#endif
}
static void F_23 ( void )
{
extern T_1 V_57 ;
extern T_1 V_58 ;
extern T_1 V_59 ;
extern T_1 V_60 ;
unsigned long V_30 = & V_58 -
& V_57 ;
if ( V_61 -> V_62 & V_22 ) {
F_14 ( memcmp ( & V_57 ,
& V_59 , V_30 ) == 0 ) ;
} else {
F_14 ( memcmp ( & V_57 ,
& V_60 , V_30 ) == 0 ) ;
}
}
static int T_2 F_24 ( void )
{
F_10 ( V_63 L_3 ) ;
F_13 () ;
F_15 () ;
F_16 () ;
F_17 () ;
F_18 () ;
F_19 () ;
F_20 () ;
F_21 () ;
F_23 () ;
return 0 ;
}
