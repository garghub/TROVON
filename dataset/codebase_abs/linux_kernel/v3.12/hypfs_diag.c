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
static int F_22 ( unsigned long V_28 , unsigned long V_29 , void * V_30 )
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
static void F_23 ( void )
{
if ( ! V_32 )
return;
if ( V_33 ) {
F_24 ( V_33 ) ;
V_33 = NULL ;
} else {
F_25 ( ( unsigned long ) V_32 , 0 ) ;
}
V_32 = NULL ;
}
static void * F_26 ( void * V_34 )
{
return ( void * ) F_27 ( ( unsigned long ) V_34 ) ;
}
static void * F_28 ( int V_35 )
{
V_33 = F_29 ( V_36 * ( V_35 + 1 ) ) ;
if ( ! V_33 )
return F_30 ( - V_37 ) ;
V_32 = F_26 ( V_33 ) ;
V_38 = V_35 ;
return V_32 ;
}
static void * F_31 ( void )
{
V_32 = ( void * ) F_32 ( V_39 , 0 ) ;
if ( ! V_32 )
return F_30 ( - V_37 ) ;
V_38 = 1 ;
return V_32 ;
}
static void * F_33 ( enum V_1 V_40 , int * V_35 )
{
if ( V_32 ) {
* V_35 = V_38 ;
return V_32 ;
}
if ( V_40 == V_2 ) {
* V_35 = 1 ;
return F_31 () ;
} else {
* V_35 = F_22 ( ( unsigned long ) V_41 |
( unsigned long ) V_42 , 0 , NULL ) ;
if ( * V_35 <= 0 )
return F_30 ( - V_43 ) ;
else
return F_28 ( * V_35 ) ;
}
}
static int F_34 ( void )
{
void * V_44 ;
int V_35 , V_45 ;
V_44 = F_33 ( V_42 , & V_35 ) ;
if ( ! F_35 ( V_44 ) ) {
if ( F_22 ( ( unsigned long ) V_46 |
( unsigned long ) V_42 , V_35 , V_44 ) >= 0 ) {
V_47 = V_46 ;
V_48 = V_42 ;
goto V_49;
}
if ( F_22 ( ( unsigned long ) V_50 |
( unsigned long ) V_42 , V_35 , V_44 ) >= 0 ) {
V_47 = V_50 ;
V_48 = V_42 ;
goto V_49;
}
F_23 () ;
}
V_44 = F_33 ( V_2 , & V_35 ) ;
if ( F_35 ( V_44 ) ) {
V_45 = F_36 ( V_44 ) ;
goto V_51;
}
if ( F_22 ( ( unsigned long ) V_52 |
( unsigned long ) V_2 , V_35 , V_44 ) >= 0 ) {
V_47 = V_52 ;
V_48 = V_2 ;
goto V_49;
} else {
V_45 = - V_43 ;
goto V_53;
}
V_49:
V_45 = 0 ;
V_53:
F_23 () ;
V_51:
return V_45 ;
}
static int F_37 ( void * V_44 , int V_35 )
{
int V_45 ;
V_45 = F_22 ( ( unsigned long ) V_47 |
( unsigned long ) V_48 , V_35 , V_44 ) ;
return V_45 < 0 ? - V_43 : 0 ;
}
static void * F_38 ( void )
{
void * V_44 ;
int V_35 , V_45 ;
V_44 = F_33 ( V_48 , & V_35 ) ;
if ( F_35 ( V_44 ) )
goto V_49;
V_45 = F_37 ( V_44 , V_35 ) ;
if ( V_45 )
return F_30 ( V_45 ) ;
V_49:
return V_44 ;
}
static int F_39 ( void * V_34 )
{
int V_45 = - V_54 ;
asm volatile(
" diag %1,%2,0x224\n"
"0: lhi %0,0x0\n"
"1:\n"
EX_TABLE(0b,1b)
: "+d" (rc) :"d" (0), "d" (ptr) : "memory");
return V_45 ;
}
static int F_40 ( void )
{
V_55 = F_41 ( V_36 , V_39 | V_56 ) ;
if ( ! V_55 )
return - V_37 ;
if ( F_39 ( V_55 ) ) {
F_42 ( V_55 ) ;
return - V_54 ;
}
F_8 ( V_55 + 16 , ( * V_55 + 1 ) * 16 ) ;
return 0 ;
}
static void F_43 ( void )
{
F_42 ( V_55 ) ;
}
static int F_44 ( int V_57 , char * V_13 )
{
memcpy ( V_13 , V_55 + ( ( V_57 + 1 ) * V_58 ) ,
V_58 ) ;
V_13 [ V_58 ] = 0 ;
F_9 ( V_13 ) ;
return 0 ;
}
static int F_45 ( void * * V_59 , void * * V_60 , T_6 * V_29 )
{
struct V_61 * V_62 ;
int V_45 , V_63 ;
void * V_64 ;
V_63 = V_36 * ( V_38 + 1 ) + sizeof( V_62 -> V_5 ) ;
V_64 = F_46 ( V_63 ) ;
if ( ! V_64 )
return - V_37 ;
V_62 = F_26 ( V_64 + sizeof( V_62 -> V_5 ) ) - sizeof( V_62 -> V_5 ) ;
V_45 = F_37 ( V_62 -> V_44 , V_38 ) ;
if ( V_45 ) {
F_24 ( V_64 ) ;
return V_45 ;
}
V_62 -> V_5 . V_65 = V_66 ;
V_62 -> V_5 . V_67 = V_36 * V_38 ;
V_62 -> V_5 . V_68 = V_47 ;
* V_59 = V_62 ;
* V_60 = V_64 ;
* V_29 = V_62 -> V_5 . V_67 + sizeof( struct V_69 ) ;
return 0 ;
}
T_7 int F_47 ( void )
{
int V_45 ;
if ( F_34 () ) {
F_48 ( L_3 ) ;
return - V_70 ;
}
if ( V_48 == V_42 ) {
V_45 = F_49 ( & V_71 ) ;
if ( V_45 )
return V_45 ;
}
if ( V_72 ) {
V_45 = F_40 () ;
if ( V_45 ) {
F_48 ( L_4
L_5 ) ;
F_50 ( V_73 ) ;
return V_45 ;
}
}
return 0 ;
}
void F_51 ( void )
{
F_50 ( V_73 ) ;
F_43 () ;
F_23 () ;
F_52 ( & V_71 ) ;
}
static int F_53 ( struct V_74 * V_75 , void * V_16 )
{
struct V_74 * V_76 ;
char V_77 [ V_78 ] ;
void * V_45 ;
snprintf ( V_77 , V_78 , L_6 , F_12 ( V_48 ,
V_16 ) ) ;
V_76 = F_54 ( V_75 , V_77 ) ;
V_45 = F_55 ( V_76 , L_7 ,
F_13 ( V_48 , V_16 ) -
F_14 ( V_48 , V_16 ) ) ;
if ( F_35 ( V_45 ) )
return F_36 ( V_45 ) ;
V_45 = F_55 ( V_76 , L_8 ,
F_14 ( V_48 , V_16 ) ) ;
if ( F_35 ( V_45 ) )
return F_36 ( V_45 ) ;
if ( V_48 == V_42 ) {
V_45 = F_55 ( V_76 , L_9 ,
F_15 ( V_48 ,
V_16 ) ) ;
if ( F_35 ( V_45 ) )
return F_36 ( V_45 ) ;
}
F_44 ( F_11 ( V_48 , V_16 ) , V_77 ) ;
V_45 = F_56 ( V_76 , L_10 , V_77 ) ;
return F_57 ( V_45 ) ;
}
static void * F_58 ( struct V_74 * V_79 , void * V_9 )
{
struct V_74 * V_75 ;
struct V_74 * V_80 ;
char V_81 [ V_15 + 1 ] ;
void * V_16 ;
int V_82 ;
F_7 ( V_48 , V_9 , V_81 ) ;
V_81 [ V_15 ] = 0 ;
V_80 = F_54 ( V_79 , V_81 ) ;
if ( F_35 ( V_80 ) )
return V_80 ;
V_75 = F_54 ( V_80 , L_11 ) ;
if ( F_35 ( V_75 ) )
return V_75 ;
V_16 = V_9 + F_5 ( V_48 ) ;
for ( V_82 = 0 ; V_82 < F_6 ( V_48 , V_9 ) ; V_82 ++ ) {
int V_45 ;
V_45 = F_53 ( V_75 , V_16 ) ;
if ( V_45 )
return F_30 ( V_45 ) ;
V_16 += F_10 ( V_48 ) ;
}
return V_16 ;
}
static int F_59 ( struct V_74 * V_75 , void * V_16 )
{
struct V_74 * V_76 ;
char V_77 [ V_78 ] ;
void * V_45 ;
snprintf ( V_77 , V_78 , L_12 , F_19 ( V_48 ,
V_16 ) ) ;
V_76 = F_54 ( V_75 , V_77 ) ;
if ( F_35 ( V_76 ) )
return F_36 ( V_76 ) ;
V_45 = F_55 ( V_76 , L_7 ,
F_20 ( V_48 , V_16 ) ) ;
if ( F_35 ( V_45 ) )
return F_36 ( V_45 ) ;
F_44 ( F_21 ( V_48 , V_16 ) , V_77 ) ;
V_45 = F_56 ( V_76 , L_10 , V_77 ) ;
return F_57 ( V_45 ) ;
}
static void * F_60 ( struct V_74 * V_83 , void * V_23 )
{
int V_82 ;
void * V_16 ;
struct V_74 * V_75 ;
V_75 = F_54 ( V_83 , L_11 ) ;
if ( F_35 ( V_75 ) )
return V_75 ;
V_16 = V_23 + F_16 ( V_48 ) ;
for ( V_82 = 0 ; V_82 < F_17 ( V_48 , V_23 ) ; V_82 ++ ) {
int V_45 ;
V_45 = F_59 ( V_75 , V_16 ) ;
if ( V_45 )
return F_30 ( V_45 ) ;
V_16 += F_18 ( V_48 ) ;
}
return V_16 ;
}
int F_61 ( struct V_74 * V_84 )
{
struct V_74 * V_79 , * V_85 ;
void * V_86 , * V_9 ;
int V_82 , V_45 ;
void * V_77 , * V_34 ;
V_77 = F_38 () ;
if ( F_35 ( V_77 ) )
return F_36 ( V_77 ) ;
V_79 = F_54 ( V_84 , L_13 ) ;
if ( F_35 ( V_79 ) ) {
V_45 = F_36 ( V_79 ) ;
goto V_87;
}
V_86 = (struct V_4 * ) V_77 ;
V_9 = V_86 + F_1 ( V_48 ) ;
for ( V_82 = 0 ; V_82 < F_2 ( V_48 , V_86 ) ; V_82 ++ ) {
V_9 = F_58 ( V_79 , V_9 ) ;
if ( F_35 ( V_9 ) ) {
V_45 = F_36 ( V_9 ) ;
goto V_87;
}
}
if ( F_3 ( V_48 , V_86 ) & V_88 ) {
V_34 = F_60 ( V_84 , V_9 ) ;
if ( F_35 ( V_34 ) ) {
V_45 = F_36 ( V_34 ) ;
goto V_87;
}
}
V_85 = F_54 ( V_84 , L_14 ) ;
if ( F_35 ( V_85 ) ) {
V_45 = F_36 ( V_85 ) ;
goto V_87;
}
V_34 = F_56 ( V_85 , L_10 , L_15 ) ;
if ( F_35 ( V_34 ) ) {
V_45 = F_36 ( V_34 ) ;
goto V_87;
}
V_45 = 0 ;
V_87:
return V_45 ;
}
