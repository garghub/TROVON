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
if ( V_9 == NULL && F_6 ( & V_10 ) ) {
F_7 ( L_1 ) ;
F_8 ( V_11 ) ;
F_9 () ;
F_8 ( V_12 ) ;
}
if ( ! ( F_10 () & V_13 ) && F_6 ( & V_10 ) ) {
F_7 ( L_2 ,
V_7 , V_10 . V_14 , V_10 . V_15 ) ;
if ( V_7 )
F_9 () ;
else
F_11 ( V_16 ) ;
continue;
}
if ( F_10 () & V_13 ) {
struct V_17 * V_18 ;
F_12 ( & V_19 ) ;
V_18 = (struct V_17 * ) V_9 ;
if ( V_18 != NULL ) {
T_1 V_1 = F_2 () ;
if ( V_7 == 0 ) {
F_7 ( L_3 , V_1 ) ;
V_7 = V_1 ;
} else {
T_2 V_20 = ( 4 <= V_7 ? 4 : V_7 ) ;
F_7 ( L_4 , V_1 , V_20 ) ;
V_7 -= V_20 ;
F_13 ( V_18 , ( unsigned char * ) & V_1 , V_20 ) ;
F_14 ( V_18 ) ;
}
}
F_15 ( & V_19 ) ;
}
if ( ! ( F_10 () & V_21 ) && ! F_6 ( & V_10 ) ) {
if ( V_8 == 0 ) {
V_8 = F_16 ( & V_10 ) ;
F_1 ( V_8 ) ;
F_7 ( L_5 , V_8 ) ;
} else {
struct V_17 * V_18 ;
int V_14 = V_10 . V_14 ;
T_2 V_22 = ( 4 <= V_8 ? 4 : V_8 ) ;
T_1 V_1 =
F_3 (
F_17 ( & V_10 , V_14 + 0 ) ,
F_17 ( & V_10 , V_14 + 1 ) ,
F_17 ( & V_10 , V_14 + 2 ) ,
F_17 ( & V_10 , V_14 + 3 )
) ;
V_10 . V_14 += V_22 ;
V_8 -= V_22 ;
F_12 ( & V_19 ) ;
V_18 = (struct V_17 * ) V_9 ;
if ( V_18 )
F_18 ( V_18 ) ;
F_15 ( & V_19 ) ;
F_7 ( L_6 , V_1 , V_22 ) ;
}
}
}
F_8 ( V_12 ) ;
return 0 ;
}
static int
F_19 ( struct V_17 * V_18 , struct V_23 * V_24 )
{
F_12 ( & V_19 ) ;
F_7 ( L_7 , V_25 ) ;
++ V_25 ;
V_9 = V_18 ;
F_20 ( V_26 ) ;
F_15 ( & V_19 ) ;
return 0 ;
}
static void
F_21 ( struct V_17 * V_18 , struct V_23 * V_24 )
{
F_12 ( & V_19 ) ;
F_7 ( L_8 , V_25 ) ;
if ( -- V_25 == 0 )
V_9 = NULL ;
F_20 ( V_26 ) ;
F_15 ( & V_19 ) ;
}
static int
F_22 ( const unsigned char * V_27 , int V_28 )
{
int V_29 ;
V_28 = F_23 ( V_28 , F_24 ( & V_10 ) ) ;
F_7 ( L_9 , V_28 ) ;
for ( V_29 = 0 ; V_29 < V_28 ; ++ V_29 )
F_17 ( & V_10 , V_10 . V_15 + V_29 ) = V_27 [ V_29 ] ;
V_10 . V_15 += V_29 ;
return V_29 ;
}
static int
F_25 ( struct V_17 * V_18 , const unsigned char * V_27 , int V_28 )
{
int V_29 ;
F_26 () ;
V_29 = F_22 ( V_27 , V_28 ) ;
F_27 () ;
F_20 ( V_26 ) ;
return V_29 ;
}
static void
F_28 ( struct V_17 * V_18 )
{
F_20 ( V_26 ) ;
}
static int
F_29 ( struct V_17 * V_18 )
{
return F_24 ( & V_10 ) ;
}
static int
F_30 ( struct V_17 * V_18 )
{
return F_16 ( & V_10 ) ;
}
static void
F_31 ( struct V_17 * V_18 , int V_30 )
{
unsigned long V_31 = V_32 + V_30 ;
while ( ! F_6 ( & V_10 ) ) {
if ( F_32 ( V_33 ) )
break;
if ( F_33 ( V_32 , V_31 ) )
break;
}
}
static int T_3 F_34 ( void )
{
int V_34 ;
V_26 = F_35 ( F_4 , NULL , V_35 ) ;
if ( F_36 ( V_26 ) )
return F_37 ( V_26 ) ;
V_34 = - V_36 ;
V_10 . V_15 = V_10 . V_14 = 0 ;
V_10 . V_27 = F_38 ( V_37 , V_38 ) ;
if ( ! V_10 . V_27 )
goto V_39;
V_40 = F_39 ( 1 ) ;
if ( ! V_40 )
goto V_41;
V_40 -> V_42 = V_35 ;
V_40 -> V_43 = V_44 ;
V_40 -> type = V_45 ;
V_40 -> V_46 = V_47 ;
V_40 -> V_48 = V_49 ;
F_40 ( V_40 , & V_50 ) ;
V_34 = F_41 ( V_40 ) ;
if ( V_34 )
goto V_51;
F_42 (KERN_INFO DRV_NAME L_10 ) ;
return 0 ;
V_51:
F_43 ( V_40 ) ;
V_41:
F_44 ( V_10 . V_27 ) ;
V_39:
F_45 ( V_26 ) ;
return V_34 ;
}
static void T_4 F_46 ( void )
{
F_45 ( V_26 ) ;
F_44 ( V_10 . V_27 ) ;
F_47 ( V_40 ) ;
F_43 ( V_40 ) ;
}
static void
F_48 ( const char * V_27 , unsigned V_28 )
{
unsigned V_22 = 0 ;
while ( F_10 () & V_21 )
continue;
F_1 ( V_28 ) ;
while ( V_22 < V_28 ) {
while ( F_10 () & V_21 )
continue;
F_3 ( V_27 [ V_22 ] , V_27 [ V_22 + 1 ] , V_27 [ V_22 + 2 ] , V_27 [ V_22 + 3 ] ) ;
V_22 += 4 ;
}
}
static void
F_49 ( struct V_52 * V_53 , const char * V_27 , unsigned V_28 )
{
if ( V_26 == NULL )
F_48 ( V_27 , V_28 ) ;
else
F_22 ( V_27 , V_28 ) ;
}
static struct V_54 *
F_50 ( struct V_52 * V_53 , int * V_55 )
{
* V_55 = V_53 -> V_55 ;
return V_40 ;
}
static int T_3 F_51 ( void )
{
F_52 ( & V_56 ) ;
return 0 ;
}
static void T_3
F_53 ( struct V_52 * V_53 , const char * V_27 , unsigned int V_28 )
{
F_48 ( V_27 , V_28 ) ;
}
struct V_52 * T_3
F_54 ( unsigned int V_57 , unsigned int V_58 )
{
return & V_59 ;
}
