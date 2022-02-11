static inline int F_1 ( enum V_1 type )
{
if ( type == V_2 )
return sizeof( struct V_3 ) ;
else
return sizeof( struct V_4 ) ;
}
static inline T_1 F_2 ( enum V_1 type , void * V_5 )
{
if ( type == V_2 )
return ( (struct V_3 * ) V_5 ) -> V_6 ;
else
return ( (struct V_4 * ) V_5 ) -> V_6 ;
}
static inline T_1 F_3 ( enum V_1 type , void * V_5 )
{
if ( type == V_2 )
return ( (struct V_3 * ) V_5 ) -> V_7 ;
else
return ( (struct V_4 * ) V_5 ) -> V_7 ;
}
static inline T_2 F_4 ( enum V_1 type , void * V_5 )
{
if ( type == V_2 )
return ( (struct V_3 * ) V_5 ) -> V_8 ;
else
return ( (struct V_4 * ) V_5 ) -> V_8 ;
}
static inline int F_5 ( enum V_1 type )
{
if ( type == V_2 )
return sizeof( struct V_9 ) ;
else
return sizeof( struct V_10 ) ;
}
static inline T_1 F_6 ( enum V_1 type , void * V_5 )
{
if ( type == V_2 )
return ( (struct V_9 * ) V_5 ) -> V_11 ;
else
return ( (struct V_10 * ) V_5 ) -> V_12 ;
}
static inline void F_7 ( enum V_1 type , void * V_5 ,
char * V_13 )
{
if ( type == V_2 )
memcpy ( V_13 , ( (struct V_9 * ) V_5 ) -> V_14 ,
V_15 ) ;
else
memcpy ( V_13 , ( (struct V_10 * ) V_5 ) -> V_14 ,
V_15 ) ;
F_8 ( V_13 , V_15 ) ;
V_13 [ V_15 ] = 0 ;
F_9 ( V_13 ) ;
}
static inline int F_10 ( enum V_1 type )
{
if ( type == V_2 )
return sizeof( struct V_16 ) ;
else
return sizeof( struct V_17 ) ;
}
static inline T_1 F_11 ( enum V_1 type , void * V_5 )
{
if ( type == V_2 )
return ( (struct V_16 * ) V_5 ) -> V_18 ;
else
return ( (struct V_17 * ) V_5 ) -> V_18 ;
}
static inline T_2 F_12 ( enum V_1 type , void * V_5 )
{
if ( type == V_2 )
return ( (struct V_16 * ) V_5 ) -> V_19 ;
else
return ( (struct V_17 * ) V_5 ) -> V_19 ;
}
static inline T_3 F_13 ( enum V_1 type , void * V_5 )
{
if ( type == V_2 )
return ( (struct V_16 * ) V_5 ) -> V_20 ;
else
return ( (struct V_17 * ) V_5 ) -> V_20 ;
}
static inline T_3 F_14 ( enum V_1 type , void * V_5 )
{
if ( type == V_2 )
return ( (struct V_16 * ) V_5 ) -> V_21 ;
else
return ( (struct V_17 * ) V_5 ) -> V_21 ;
}
static inline T_3 F_15 ( enum V_1 type , void * V_5 )
{
if ( type == V_2 )
return 0 ;
else
return ( (struct V_17 * ) V_5 ) -> V_22 ;
}
static inline int F_16 ( enum V_1 type )
{
if ( type == V_2 )
return sizeof( struct V_23 ) ;
else
return sizeof( struct V_24 ) ;
}
static inline T_1 F_17 ( enum V_1 type , void * V_5 )
{
if ( type == V_2 )
return ( (struct V_23 * ) V_5 ) -> V_11 ;
else
return ( (struct V_24 * ) V_5 ) -> V_11 ;
}
static inline int F_18 ( enum V_1 type )
{
if ( type == V_2 )
return sizeof( struct V_25 ) ;
else
return sizeof( struct V_26 ) ;
}
static inline T_2 F_19 ( enum V_1 type , void * V_5 )
{
if ( type == V_2 )
return ( (struct V_25 * ) V_5 ) -> V_19 ;
else
return ( (struct V_26 * ) V_5 ) -> V_19 ;
}
static inline T_3 F_20 ( enum V_1 type , void * V_5 )
{
if ( type == V_2 )
return ( (struct V_25 * ) V_5 ) -> V_27 ;
else
return ( (struct V_26 * ) V_5 ) -> V_27 ;
}
static inline T_3 F_21 ( enum V_1 type , void * V_5 )
{
if ( type == V_2 )
return ( (struct V_25 * ) V_5 ) -> V_18 ;
else
return ( (struct V_26 * ) V_5 ) -> V_18 ;
}
static inline int F_22 ( unsigned long V_28 , unsigned long V_29 , void * V_30 )
{
register unsigned long T_4 V_31 ( L_1 ) = V_28 ;
register unsigned long T_5 V_31 ( L_2 ) = V_29 ;
asm volatile(
" diag %2,%0,0x204\n"
"0:\n"
EX_TABLE(0b,0b)
: "+d" (_subcode), "+d" (_size) : "d" (addr) : "memory");
if ( T_4 )
return - 1 ;
return T_5 ;
}
static int F_23 ( unsigned long V_28 , unsigned long V_29 , void * V_30 )
{
F_24 ( V_32 ) ;
return F_22 ( V_28 , V_29 , V_30 ) ;
}
static void F_25 ( void )
{
if ( ! V_33 )
return;
if ( V_34 ) {
F_26 ( V_34 ) ;
V_34 = NULL ;
} else {
F_27 ( ( unsigned long ) V_33 , 0 ) ;
}
V_33 = NULL ;
}
static void * F_28 ( void * V_35 )
{
return ( void * ) F_29 ( ( unsigned long ) V_35 ) ;
}
static void * F_30 ( int V_36 )
{
V_34 = F_31 ( V_37 * ( V_36 + 1 ) ) ;
if ( ! V_34 )
return F_32 ( - V_38 ) ;
V_33 = F_28 ( V_34 ) ;
V_39 = V_36 ;
return V_33 ;
}
static void * F_33 ( void )
{
V_33 = ( void * ) F_34 ( V_40 , 0 ) ;
if ( ! V_33 )
return F_32 ( - V_38 ) ;
V_39 = 1 ;
return V_33 ;
}
static void * F_35 ( enum V_1 V_41 , int * V_36 )
{
if ( V_33 ) {
* V_36 = V_39 ;
return V_33 ;
}
if ( V_41 == V_2 ) {
* V_36 = 1 ;
return F_33 () ;
} else {
* V_36 = F_23 ( ( unsigned long ) V_42 |
( unsigned long ) V_43 , 0 , NULL ) ;
if ( * V_36 <= 0 )
return F_32 ( - V_44 ) ;
else
return F_30 ( * V_36 ) ;
}
}
static int F_36 ( void )
{
void * V_45 ;
int V_36 , V_46 ;
V_45 = F_35 ( V_43 , & V_36 ) ;
if ( ! F_37 ( V_45 ) ) {
if ( F_23 ( ( unsigned long ) V_47 |
( unsigned long ) V_43 , V_36 , V_45 ) >= 0 ) {
V_48 = V_47 ;
V_49 = V_43 ;
goto V_50;
}
if ( F_23 ( ( unsigned long ) V_51 |
( unsigned long ) V_43 , V_36 , V_45 ) >= 0 ) {
V_48 = V_51 ;
V_49 = V_43 ;
goto V_50;
}
F_25 () ;
}
V_45 = F_35 ( V_2 , & V_36 ) ;
if ( F_37 ( V_45 ) ) {
V_46 = F_38 ( V_45 ) ;
goto V_52;
}
if ( F_23 ( ( unsigned long ) V_53 |
( unsigned long ) V_2 , V_36 , V_45 ) >= 0 ) {
V_48 = V_53 ;
V_49 = V_2 ;
goto V_50;
} else {
V_46 = - V_44 ;
goto V_54;
}
V_50:
V_46 = 0 ;
V_54:
F_25 () ;
V_52:
return V_46 ;
}
static int F_39 ( void * V_45 , int V_36 )
{
int V_46 ;
V_46 = F_23 ( ( unsigned long ) V_48 |
( unsigned long ) V_49 , V_36 , V_45 ) ;
return V_46 < 0 ? - V_44 : 0 ;
}
static void * F_40 ( void )
{
void * V_45 ;
int V_36 , V_46 ;
V_45 = F_35 ( V_49 , & V_36 ) ;
if ( F_37 ( V_45 ) )
goto V_50;
V_46 = F_39 ( V_45 , V_36 ) ;
if ( V_46 )
return F_32 ( V_46 ) ;
V_50:
return V_45 ;
}
static int F_41 ( void * V_35 )
{
int V_46 = - V_55 ;
F_24 ( V_56 ) ;
asm volatile(
" diag %1,%2,0x224\n"
"0: lhi %0,0x0\n"
"1:\n"
EX_TABLE(0b,1b)
: "+d" (rc) :"d" (0), "d" (ptr) : "memory");
return V_46 ;
}
static int F_42 ( void )
{
V_57 = F_43 ( V_37 , V_40 | V_58 ) ;
if ( ! V_57 )
return - V_38 ;
if ( F_41 ( V_57 ) ) {
F_44 ( V_57 ) ;
return - V_55 ;
}
F_8 ( V_57 + 16 , ( * V_57 + 1 ) * 16 ) ;
return 0 ;
}
static void F_45 ( void )
{
F_44 ( V_57 ) ;
}
static int F_46 ( int V_59 , char * V_13 )
{
memcpy ( V_13 , V_57 + ( ( V_59 + 1 ) * V_60 ) ,
V_60 ) ;
V_13 [ V_60 ] = 0 ;
F_9 ( V_13 ) ;
return 0 ;
}
static int F_47 ( void * * V_61 , void * * V_62 , T_6 * V_29 )
{
struct V_63 * V_64 ;
int V_46 , V_65 ;
void * V_66 ;
V_65 = V_37 * ( V_39 + 1 ) + sizeof( V_64 -> V_5 ) ;
V_66 = F_48 ( V_65 ) ;
if ( ! V_66 )
return - V_38 ;
V_64 = F_28 ( V_66 + sizeof( V_64 -> V_5 ) ) - sizeof( V_64 -> V_5 ) ;
V_46 = F_39 ( V_64 -> V_45 , V_39 ) ;
if ( V_46 ) {
F_26 ( V_66 ) ;
return V_46 ;
}
V_64 -> V_5 . V_67 = V_68 ;
V_64 -> V_5 . V_69 = V_37 * V_39 ;
V_64 -> V_5 . V_70 = V_48 ;
* V_61 = V_64 ;
* V_62 = V_66 ;
* V_29 = V_64 -> V_5 . V_69 + sizeof( struct V_71 ) ;
return 0 ;
}
T_7 int F_49 ( void )
{
int V_46 ;
if ( F_36 () ) {
F_50 ( L_3 ) ;
return - V_72 ;
}
if ( V_49 == V_43 ) {
V_46 = F_51 ( & V_73 ) ;
if ( V_46 )
return V_46 ;
}
if ( V_74 ) {
V_46 = F_42 () ;
if ( V_46 ) {
F_50 ( L_4
L_5 ) ;
F_52 ( V_75 ) ;
return V_46 ;
}
}
return 0 ;
}
void F_53 ( void )
{
F_52 ( V_75 ) ;
F_45 () ;
F_25 () ;
F_54 ( & V_73 ) ;
}
static int F_55 ( struct V_76 * V_77 , void * V_16 )
{
struct V_76 * V_78 ;
char V_79 [ V_80 ] ;
void * V_46 ;
snprintf ( V_79 , V_80 , L_6 , F_12 ( V_49 ,
V_16 ) ) ;
V_78 = F_56 ( V_77 , V_79 ) ;
V_46 = F_57 ( V_78 , L_7 ,
F_13 ( V_49 , V_16 ) -
F_14 ( V_49 , V_16 ) ) ;
if ( F_37 ( V_46 ) )
return F_38 ( V_46 ) ;
V_46 = F_57 ( V_78 , L_8 ,
F_14 ( V_49 , V_16 ) ) ;
if ( F_37 ( V_46 ) )
return F_38 ( V_46 ) ;
if ( V_49 == V_43 ) {
V_46 = F_57 ( V_78 , L_9 ,
F_15 ( V_49 ,
V_16 ) ) ;
if ( F_37 ( V_46 ) )
return F_38 ( V_46 ) ;
}
F_46 ( F_11 ( V_49 , V_16 ) , V_79 ) ;
V_46 = F_58 ( V_78 , L_10 , V_79 ) ;
return F_59 ( V_46 ) ;
}
static void * F_60 ( struct V_76 * V_81 , void * V_9 )
{
struct V_76 * V_77 ;
struct V_76 * V_82 ;
char V_83 [ V_15 + 1 ] ;
void * V_16 ;
int V_84 ;
F_7 ( V_49 , V_9 , V_83 ) ;
V_83 [ V_15 ] = 0 ;
V_82 = F_56 ( V_81 , V_83 ) ;
if ( F_37 ( V_82 ) )
return V_82 ;
V_77 = F_56 ( V_82 , L_11 ) ;
if ( F_37 ( V_77 ) )
return V_77 ;
V_16 = V_9 + F_5 ( V_49 ) ;
for ( V_84 = 0 ; V_84 < F_6 ( V_49 , V_9 ) ; V_84 ++ ) {
int V_46 ;
V_46 = F_55 ( V_77 , V_16 ) ;
if ( V_46 )
return F_32 ( V_46 ) ;
V_16 += F_10 ( V_49 ) ;
}
return V_16 ;
}
static int F_61 ( struct V_76 * V_77 , void * V_16 )
{
struct V_76 * V_78 ;
char V_79 [ V_80 ] ;
void * V_46 ;
snprintf ( V_79 , V_80 , L_12 , F_19 ( V_49 ,
V_16 ) ) ;
V_78 = F_56 ( V_77 , V_79 ) ;
if ( F_37 ( V_78 ) )
return F_38 ( V_78 ) ;
V_46 = F_57 ( V_78 , L_7 ,
F_20 ( V_49 , V_16 ) ) ;
if ( F_37 ( V_46 ) )
return F_38 ( V_46 ) ;
F_46 ( F_21 ( V_49 , V_16 ) , V_79 ) ;
V_46 = F_58 ( V_78 , L_10 , V_79 ) ;
return F_59 ( V_46 ) ;
}
static void * F_62 ( struct V_76 * V_85 , void * V_23 )
{
int V_84 ;
void * V_16 ;
struct V_76 * V_77 ;
V_77 = F_56 ( V_85 , L_11 ) ;
if ( F_37 ( V_77 ) )
return V_77 ;
V_16 = V_23 + F_16 ( V_49 ) ;
for ( V_84 = 0 ; V_84 < F_17 ( V_49 , V_23 ) ; V_84 ++ ) {
int V_46 ;
V_46 = F_61 ( V_77 , V_16 ) ;
if ( V_46 )
return F_32 ( V_46 ) ;
V_16 += F_18 ( V_49 ) ;
}
return V_16 ;
}
int F_63 ( struct V_76 * V_86 )
{
struct V_76 * V_81 , * V_87 ;
void * V_88 , * V_9 ;
int V_84 , V_46 ;
void * V_79 , * V_35 ;
V_79 = F_40 () ;
if ( F_37 ( V_79 ) )
return F_38 ( V_79 ) ;
V_81 = F_56 ( V_86 , L_13 ) ;
if ( F_37 ( V_81 ) ) {
V_46 = F_38 ( V_81 ) ;
goto V_89;
}
V_88 = (struct V_4 * ) V_79 ;
V_9 = V_88 + F_1 ( V_49 ) ;
for ( V_84 = 0 ; V_84 < F_2 ( V_49 , V_88 ) ; V_84 ++ ) {
V_9 = F_60 ( V_81 , V_9 ) ;
if ( F_37 ( V_9 ) ) {
V_46 = F_38 ( V_9 ) ;
goto V_89;
}
}
if ( F_3 ( V_49 , V_88 ) & V_90 ) {
V_35 = F_62 ( V_86 , V_9 ) ;
if ( F_37 ( V_35 ) ) {
V_46 = F_38 ( V_35 ) ;
goto V_89;
}
}
V_87 = F_56 ( V_86 , L_14 ) ;
if ( F_37 ( V_87 ) ) {
V_46 = F_38 ( V_87 ) ;
goto V_89;
}
V_35 = F_58 ( V_87 , L_10 , L_15 ) ;
if ( F_37 ( V_35 ) ) {
V_46 = F_38 ( V_35 ) ;
goto V_89;
}
V_46 = 0 ;
V_89:
return V_46 ;
}
