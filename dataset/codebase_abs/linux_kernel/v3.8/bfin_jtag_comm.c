static inline T_1 F_1 ( T_1 V_1 )
{
__asm__ __volatile__("emudat = %0;" : : "d"(emudat));
return V_1 ;
}
static inline T_1 F_2 ( void )
{
T_1 V_1 ;
__asm__ __volatile__("%0 = emudat;" : "=d"(emudat));
return V_1 ;
}
static inline T_1 F_3 ( char V_2 , char V_3 , char V_4 , char V_5 )
{
return F_1 ( ( V_2 << 0 ) | ( V_3 << 8 ) | ( V_4 << 16 ) | ( V_5 << 24 ) ) ;
}
static int
F_4 ( void * V_6 )
{
T_1 V_7 = 0 , V_8 = 0 ;
while ( ! F_5 () ) {
struct V_9 * V_10 = F_6 ( & V_11 ) ;
if ( V_10 == NULL && F_7 ( & V_12 ) ) {
F_8 ( L_1 ) ;
F_9 ( V_13 ) ;
F_10 () ;
F_9 ( V_14 ) ;
continue;
}
if ( ! ( F_11 () & V_15 ) && F_7 ( & V_12 ) ) {
F_8 ( L_2 ,
V_7 , V_12 . V_16 , V_12 . V_17 ) ;
F_12 ( V_10 ) ;
if ( V_7 )
F_10 () ;
else
F_13 ( V_18 ) ;
continue;
}
if ( F_11 () & V_15 ) {
if ( V_10 != NULL ) {
T_1 V_1 = F_2 () ;
if ( V_7 == 0 ) {
F_8 ( L_3 , V_1 ) ;
V_7 = V_1 ;
} else {
T_2 V_19 = ( 4 <= V_7 ? 4 : V_7 ) ;
F_8 ( L_4 , V_1 , V_19 ) ;
V_7 -= V_19 ;
F_14 ( V_10 , ( unsigned char * ) & V_1 , V_19 ) ;
F_15 ( V_10 ) ;
}
}
}
if ( ! ( F_11 () & V_20 ) && ! F_7 ( & V_12 ) ) {
if ( V_8 == 0 ) {
V_8 = F_16 ( & V_12 ) ;
F_1 ( V_8 ) ;
F_8 ( L_5 , V_8 ) ;
} else {
int V_16 = V_12 . V_16 ;
T_2 V_21 = ( 4 <= V_8 ? 4 : V_8 ) ;
T_1 V_1 =
F_3 (
F_17 ( & V_12 , V_16 + 0 ) ,
F_17 ( & V_12 , V_16 + 1 ) ,
F_17 ( & V_12 , V_16 + 2 ) ,
F_17 ( & V_12 , V_16 + 3 )
) ;
V_12 . V_16 += V_21 ;
V_8 -= V_21 ;
if ( V_10 )
F_18 ( V_10 ) ;
F_8 ( L_6 , V_1 , V_21 ) ;
}
}
F_12 ( V_10 ) ;
}
F_9 ( V_14 ) ;
return 0 ;
}
static int
F_19 ( struct V_9 * V_10 , struct V_22 * V_23 )
{
unsigned long V_24 ;
F_20 ( & V_11 . V_25 , V_24 ) ;
V_11 . V_26 ++ ;
F_21 ( & V_11 . V_25 , V_24 ) ;
F_22 ( & V_11 , V_10 ) ;
F_23 ( V_27 ) ;
return 0 ;
}
static void
F_24 ( struct V_9 * V_10 , struct V_22 * V_23 )
{
unsigned long V_24 ;
bool V_28 ;
F_20 ( & V_11 . V_25 , V_24 ) ;
V_28 = -- V_11 . V_26 == 0 ;
F_21 ( & V_11 . V_25 , V_24 ) ;
if ( V_28 )
F_22 ( & V_11 , NULL ) ;
F_23 ( V_27 ) ;
}
static int
F_25 ( const unsigned char * V_29 , int V_26 )
{
int V_30 ;
V_26 = F_26 ( V_26 , F_27 ( & V_12 ) ) ;
F_8 ( L_7 , V_26 ) ;
for ( V_30 = 0 ; V_30 < V_26 ; ++ V_30 )
F_17 ( & V_12 , V_12 . V_17 + V_30 ) = V_29 [ V_30 ] ;
V_12 . V_17 += V_30 ;
return V_30 ;
}
static int
F_28 ( struct V_9 * V_10 , const unsigned char * V_29 , int V_26 )
{
int V_30 ;
F_29 () ;
V_30 = F_25 ( V_29 , V_26 ) ;
F_30 () ;
F_23 ( V_27 ) ;
return V_30 ;
}
static void
F_31 ( struct V_9 * V_10 )
{
F_23 ( V_27 ) ;
}
static int
F_32 ( struct V_9 * V_10 )
{
return F_27 ( & V_12 ) ;
}
static int
F_33 ( struct V_9 * V_10 )
{
return F_16 ( & V_12 ) ;
}
static void
F_34 ( struct V_9 * V_10 , int V_31 )
{
unsigned long V_32 = V_33 + V_31 ;
while ( ! F_7 ( & V_12 ) ) {
if ( F_35 ( V_34 ) )
break;
if ( F_36 ( V_33 , V_32 ) )
break;
}
}
static int T_3 F_37 ( void )
{
int V_35 ;
V_27 = F_38 ( F_4 , NULL , V_36 ) ;
if ( F_39 ( V_27 ) )
return F_40 ( V_27 ) ;
V_35 = - V_37 ;
V_12 . V_17 = V_12 . V_16 = 0 ;
V_12 . V_29 = F_41 ( V_38 , V_39 ) ;
if ( ! V_12 . V_29 )
goto V_40;
V_41 = F_42 ( 1 ) ;
if ( ! V_41 )
goto V_42;
F_43 ( & V_11 ) ;
V_41 -> V_43 = V_36 ;
V_41 -> V_44 = V_45 ;
V_41 -> type = V_46 ;
V_41 -> V_47 = V_48 ;
V_41 -> V_49 = V_50 ;
F_44 ( V_41 , & V_51 ) ;
F_45 ( & V_11 , V_41 , 0 ) ;
V_35 = F_46 ( V_41 ) ;
if ( V_35 )
goto V_52;
F_47 (KERN_INFO DRV_NAME L_8 ) ;
return 0 ;
V_52:
F_48 ( & V_11 ) ;
F_49 ( V_41 ) ;
V_42:
F_50 ( V_12 . V_29 ) ;
V_40:
F_51 ( V_27 ) ;
return V_35 ;
}
static void T_4 F_52 ( void )
{
F_51 ( V_27 ) ;
F_50 ( V_12 . V_29 ) ;
F_53 ( V_41 ) ;
F_49 ( V_41 ) ;
F_48 ( & V_11 ) ;
}
static void
F_54 ( const char * V_29 , unsigned V_26 )
{
unsigned V_21 = 0 ;
while ( F_11 () & V_20 )
continue;
F_1 ( V_26 ) ;
while ( V_21 < V_26 ) {
while ( F_11 () & V_20 )
continue;
F_3 ( V_29 [ V_21 ] , V_29 [ V_21 + 1 ] , V_29 [ V_21 + 2 ] , V_29 [ V_21 + 3 ] ) ;
V_21 += 4 ;
}
}
static void
F_55 ( struct V_53 * V_54 , const char * V_29 , unsigned V_26 )
{
if ( V_27 == NULL )
F_54 ( V_29 , V_26 ) ;
else
F_25 ( V_29 , V_26 ) ;
}
static struct V_55 *
F_56 ( struct V_53 * V_54 , int * V_56 )
{
* V_56 = V_54 -> V_56 ;
return V_41 ;
}
static int T_3 F_57 ( void )
{
F_58 ( & V_57 ) ;
return 0 ;
}
static void T_3
F_59 ( struct V_53 * V_54 , const char * V_29 , unsigned int V_26 )
{
F_54 ( V_29 , V_26 ) ;
}
struct V_53 * T_3
F_60 ( unsigned int V_11 , unsigned int V_58 )
{
return & V_59 ;
}
