void F_1 ( unsigned long V_1 , int V_2 )
{
F_2 ( L_1 , ( void * ) V_1 ,
V_2 ? L_2 : L_3 , ( void * ) V_1 ) ;
}
static void
F_3 ( unsigned long V_3 , void * V_4 ,
const struct V_5 * V_6 ,
struct V_7 * V_8 , int * V_9 )
{
struct V_10 * V_11 ;
unsigned long V_12 ;
int V_13 ;
if ( V_3 != ( unsigned long ) V_14 )
return;
V_11 = V_8 -> V_11 ;
V_13 = V_11 -> V_15 ;
if ( ! V_11 -> V_16 || V_13 < * V_9 )
return;
V_13 -= * V_9 ;
V_12 = V_11 -> V_16 [ V_13 ] . V_17 ;
V_6 -> V_1 ( V_4 , V_12 , 1 ) ;
( * V_9 ) ++ ;
}
static inline void
F_3 ( unsigned long V_3 , void * V_4 ,
const struct V_5 * V_6 ,
struct V_7 * V_8 , int * V_9 )
{ }
static inline int F_4 ( struct V_7 * V_8 ,
void * V_18 , unsigned int V_19 , void * V_20 )
{
void * V_21 = V_8 ;
if ( V_20 ) {
if ( V_18 < V_20 && V_18 >= ( V_20 - V_22 ) )
return 1 ;
else
return 0 ;
}
return V_18 > V_21 && V_18 < V_21 + V_22 - V_19 ;
}
unsigned long
F_5 ( struct V_7 * V_8 ,
unsigned long * V_23 , unsigned long V_24 ,
const struct V_5 * V_6 , void * V_4 ,
unsigned long * V_20 , int * V_9 )
{
struct V_25 * V_26 = (struct V_25 * ) V_24 ;
while ( F_4 ( V_8 , V_23 , sizeof( * V_23 ) , V_20 ) ) {
unsigned long V_3 ;
V_3 = * V_23 ;
if ( F_6 ( V_3 ) ) {
if ( ( unsigned long ) V_23 == V_24 + sizeof( long ) ) {
V_6 -> V_1 ( V_4 , V_3 , 1 ) ;
V_26 = V_26 -> V_27 ;
V_24 = ( unsigned long ) V_26 ;
} else {
V_6 -> V_1 ( V_4 , V_3 , 0 ) ;
}
F_3 ( V_3 , V_4 , V_6 , V_8 , V_9 ) ;
}
V_23 ++ ;
}
return V_24 ;
}
unsigned long
F_7 ( struct V_7 * V_8 ,
unsigned long * V_23 , unsigned long V_24 ,
const struct V_5 * V_6 , void * V_4 ,
unsigned long * V_20 , int * V_9 )
{
struct V_25 * V_26 = (struct V_25 * ) V_24 ;
unsigned long * V_12 = & V_26 -> V_28 ;
while ( F_4 ( V_8 , V_12 , sizeof( * V_12 ) , V_20 ) ) {
unsigned long V_3 = * V_12 ;
if ( ! F_6 ( V_3 ) )
break;
V_6 -> V_1 ( V_4 , V_3 , 1 ) ;
V_26 = V_26 -> V_27 ;
V_12 = & V_26 -> V_28 ;
F_3 ( V_3 , V_4 , V_6 , V_8 , V_9 ) ;
}
return ( unsigned long ) V_26 ;
}
static int F_8 ( void * V_4 , char * V_29 )
{
F_2 ( L_4 , ( char * ) V_4 , V_29 ) ;
return 0 ;
}
static void F_9 ( void * V_4 , unsigned long V_3 , int V_2 )
{
F_10 () ;
F_2 ( V_4 ) ;
F_1 ( V_3 , V_2 ) ;
}
void
F_11 ( struct V_10 * V_11 , struct V_30 * V_31 ,
unsigned long * V_23 , unsigned long V_24 , char * V_32 )
{
F_2 ( L_5 , V_32 ) ;
F_12 ( V_11 , V_31 , V_23 , V_24 , & V_33 , V_32 ) ;
}
void F_13 ( struct V_10 * V_11 , struct V_30 * V_31 ,
unsigned long * V_23 , unsigned long V_24 )
{
F_11 ( V_11 , V_31 , V_23 , V_24 , L_2 ) ;
}
void F_14 ( struct V_10 * V_11 , unsigned long * V_34 )
{
F_15 ( V_11 , NULL , V_34 , 0 , L_2 ) ;
}
void F_16 ( void )
{
unsigned long V_24 ;
unsigned long V_23 ;
V_24 = V_25 ( V_35 , NULL ) ;
F_2 ( L_6 ,
V_35 -> V_36 , V_35 -> V_37 , F_17 () ,
F_18 () -> V_38 ,
( int ) strcspn ( F_18 () -> V_39 , L_7 ) ,
F_18 () -> V_39 ) ;
F_13 ( NULL , NULL , & V_23 , V_24 ) ;
}
unsigned T_1 long F_19 ( void )
{
int V_40 ;
unsigned long V_41 ;
F_20 () ;
F_21 ( V_41 ) ;
V_40 = F_22 () ;
if ( ! F_23 ( & V_42 ) ) {
if ( V_40 == V_43 )
;
else
F_24 ( & V_42 ) ;
}
V_44 ++ ;
V_43 = V_40 ;
F_25 () ;
F_26 ( 1 ) ;
return V_41 ;
}
void T_1 F_27 ( unsigned long V_41 , struct V_30 * V_31 , int V_45 )
{
if ( V_31 && F_28 ( V_35 ) )
F_29 ( V_31 ) ;
F_26 ( 0 ) ;
V_43 = - 1 ;
F_30 ( V_46 ) ;
V_44 -- ;
if ( ! V_44 )
F_31 ( & V_42 ) ;
F_32 ( V_41 ) ;
F_33 () ;
if ( ! V_45 )
return;
if ( F_34 () )
F_35 ( L_8 ) ;
if ( V_47 )
F_35 ( L_9 ) ;
F_36 ( V_45 ) ;
}
int T_1 F_37 ( const char * V_48 , struct V_30 * V_31 , long V_49 )
{
#ifdef F_38
unsigned short V_50 ;
unsigned long V_34 ;
#endif
F_2 ( V_51
L_10 , V_48 , V_49 & 0xffff , ++ V_52 ) ;
#ifdef F_39
F_2 ( L_11 ) ;
#endif
#ifdef F_40
F_2 ( L_12 ) ;
#endif
#ifdef F_41
F_2 ( L_13 ) ;
#endif
F_2 ( L_14 ) ;
if ( F_42 ( V_53 , V_48 , V_31 , V_49 ,
V_35 -> V_54 . V_55 , V_56 ) == V_57 )
return 1 ;
F_43 ( V_31 ) ;
#ifdef F_38
if ( F_44 ( V_31 ) ) {
V_34 = V_31 -> V_34 ;
V_50 = V_31 -> V_50 & 0xffff ;
} else {
V_34 = F_45 ( V_31 ) ;
F_46 ( V_50 , V_50 ) ;
}
F_2 ( V_58 L_15 , V_31 -> V_59 ) ;
F_47 ( L_16 , V_31 -> V_59 ) ;
F_2 ( L_17 , V_50 , V_34 ) ;
#else
F_2 ( V_60 L_18 ) ;
F_1 ( V_31 -> V_59 , 1 ) ;
F_2 ( L_19 , V_31 -> V_34 ) ;
#endif
return 0 ;
}
void F_48 ( const char * V_48 , struct V_30 * V_31 , long V_49 )
{
unsigned long V_41 = F_19 () ;
int V_61 = V_56 ;
if ( ! F_44 ( V_31 ) )
F_49 ( V_31 -> V_59 , V_31 ) ;
if ( F_37 ( V_48 , V_31 , V_49 ) )
V_61 = 0 ;
F_27 ( V_41 , V_31 , V_61 ) ;
}
static int T_2 F_50 ( char * V_62 )
{
T_3 V_17 ;
unsigned long V_63 ;
if ( ! V_62 )
return - V_64 ;
V_17 = F_51 ( V_62 , 0 , & V_63 ) ;
if ( V_17 )
return V_17 ;
V_65 = V_63 ;
return 0 ;
}
static int T_2 F_52 ( char * V_62 )
{
T_3 V_17 ;
unsigned long V_63 ;
if ( ! V_62 )
return - V_64 ;
V_17 = F_51 ( V_62 , 0 , & V_63 ) ;
if ( V_17 )
return V_17 ;
V_66 = V_63 ;
if ( V_66 > 8192 )
V_66 = 8192 ;
return 1 ;
}
