static inline unsigned int F_1 ( void )
{
return F_2 ( V_1 ) & 1 ;
}
static inline void F_3 ( void )
{
do { } while ( ! F_1 () );
}
static inline void F_4 ( void )
{
do { } while ( F_1 () );
}
static inline void F_5 ( void )
{
if ( F_1 () ) {
do {
( void ) F_2 ( V_2 ) ;
F_6 () ;
} while ( F_1 () );
}
}
static T_1 F_7 ( T_1 V_3 )
{
unsigned long V_4 ;
T_1 V_5 , V_6 ;
F_8 ( & V_7 , V_4 ) ;
F_5 () ;
F_9 ( ( 0x01 << 24 ) | ( V_3 & 0x00ffffff ) , V_2 ) ;
F_6 () ;
F_3 () ;
V_5 = F_2 ( V_2 ) ;
F_6 () ;
V_6 = F_2 ( V_2 ) ;
F_4 () ;
F_10 ( & V_7 , V_4 ) ;
return V_6 ;
}
static void F_11 ( T_1 V_6 , T_1 V_3 )
{
unsigned long V_4 ;
T_1 V_5 ;
F_8 ( & V_7 , V_4 ) ;
F_5 () ;
F_9 ( ( 0x10 << 24 ) | ( V_3 & 0x00ffffff ) , V_2 ) ;
F_6 () ;
F_9 ( V_6 , V_2 ) ;
F_6 () ;
F_3 () ;
V_5 = F_2 ( V_2 ) ;
F_4 () ;
F_10 ( & V_7 , V_4 ) ;
}
static inline void F_12 ( struct V_8 * V_9 )
{
F_11 ( V_10 , V_9 -> V_11 + V_12 ) ;
}
static inline void F_13 ( struct V_8 * V_9 )
{
F_11 ( V_13 , V_9 -> V_11 + V_12 ) ;
}
static inline void F_14 ( struct V_8 * V_9 )
{
F_11 ( V_14 , V_9 -> V_11 + V_15 ) ;
F_11 ( V_16 , V_9 -> V_11 + V_12 ) ;
}
static inline void F_15 ( struct V_8 * V_9 )
{
F_11 ( V_14 , V_9 -> V_11 + V_12 ) ;
F_11 ( V_16 , V_9 -> V_11 + V_12 ) ;
}
static inline int F_16 ( struct V_8 * V_9 )
{
int V_17 ;
for ( V_17 = 0 ; V_17 < V_9 -> V_18 ; V_17 ++ ) {
if ( ( ( F_7 ( V_9 -> V_11 + V_19 ) &
( V_16 | V_20 |
V_13 | V_21 |
V_10 ) ) == 0 ) &&
( ( F_7 ( V_9 -> V_11 + V_22 ) &
( V_23 ) ) == 0 ) )
return 0 ;
F_17 ( 1 ) ;
}
return - V_24 ;
}
static inline T_1 F_18 ( struct V_8 * V_9 ,
T_1 V_25 )
{
F_11 ( V_25 , V_9 -> V_11 + V_26 ) ;
return F_7 ( V_9 -> V_11 + V_22 ) &
V_27 ;
}
static inline T_1 F_19 ( struct V_8 * V_9 )
{
F_11 ( V_20 , V_9 -> V_11 + V_12 ) ;
while ( F_7 ( V_9 -> V_11 + V_19 ) & V_20 )
;
F_11 ( V_28 , V_9 -> V_11 + V_29 ) ;
return F_7 ( V_9 -> V_11 + V_30 ) ;
}
static int F_20 ( struct V_8 * V_9 ,
unsigned int V_31 , int V_32 )
{
F_16 ( V_9 ) ;
F_12 ( V_9 ) ;
F_16 ( V_9 ) ;
V_31 <<= 1 ;
if ( V_32 )
V_31 |= 1 ;
if ( F_18 ( V_9 , V_31 ) )
return - V_33 ;
F_16 ( V_9 ) ;
if ( F_7 ( V_9 -> V_11 + V_22 ) &
V_34 )
return - V_33 ;
return 0 ;
}
static int F_21 ( struct V_8 * V_9 ,
unsigned char * V_35 , unsigned int V_36 )
{
T_1 V_37 ;
int V_17 ;
V_17 = 0 ;
while ( V_17 < V_36 ) {
V_37 = F_19 ( V_9 ) ;
V_35 [ V_17 ++ ] = V_37 ;
if ( V_17 < V_36 )
F_14 ( V_9 ) ;
else
F_15 ( V_9 ) ;
}
F_13 ( V_9 ) ;
F_16 ( V_9 ) ;
return 0 ;
}
static int F_22 ( struct V_8 * V_9 ,
unsigned char * V_35 , unsigned int V_36 )
{
int V_17 ;
T_1 V_37 ;
V_17 = 0 ;
while ( V_17 < V_36 ) {
V_37 = V_35 [ V_17 ] ;
if ( F_18 ( V_9 , V_37 ) )
return - V_33 ;
F_16 ( V_9 ) ;
if ( F_7 ( V_9 -> V_11 + V_22 ) &
V_34 )
return - V_33 ;
V_17 ++ ;
}
F_13 ( V_9 ) ;
F_16 ( V_9 ) ;
return 0 ;
}
static int F_23 ( struct V_38 * V_39 ,
struct V_40 * V_41 , int V_42 )
{
struct V_8 * V_9 = V_39 -> V_43 ;
struct V_40 * V_44 ;
int V_17 , V_45 = 0 ;
for ( V_17 = 0 ; V_17 < V_42 ; V_17 ++ ) {
#define F_24 80
int V_46 ;
static char V_35 [ F_24 ] ;
char * V_47 = V_35 ;
V_44 = & V_41 [ V_17 ] ;
V_47 += sprintf ( V_35 , L_1 , V_44 -> V_36 ) ;
if ( ( V_44 -> V_4 & V_48 ) == 0 ) {
for ( V_46 = 0 ; V_46 < V_44 -> V_36 ; V_46 ++ ) {
if ( V_47 < & V_35 [ F_24 - 4 ] ) {
V_47 += sprintf ( V_47 , L_2 , V_44 -> V_35 [ V_46 ] ) ;
} else {
strcat ( V_47 , L_3 ) ;
break;
}
}
}
}
for ( V_17 = 0 ; ! V_45 && V_17 < V_42 ; V_17 ++ ) {
V_44 = & V_41 [ V_17 ] ;
V_45 = F_20 ( V_9 , V_44 -> V_31 , V_44 -> V_4 & V_48 ) ;
if ( V_45 || ! V_44 -> V_36 )
continue;
if ( V_44 -> V_4 & V_48 )
V_45 = F_21 ( V_9 , V_44 -> V_35 , V_44 -> V_36 ) ;
else
V_45 = F_22 ( V_9 , V_44 -> V_35 , V_44 -> V_36 ) ;
}
if ( V_45 == 0 )
V_45 = V_42 ;
return V_45 ;
}
static T_1 F_25 ( struct V_38 * V_9 )
{
return V_49 | V_50 ;
}
static void F_26 ( struct V_8 * V_51 )
{
F_11 ( 500 , V_51 -> V_11 + V_52 ) ;
F_11 ( V_53 , V_51 -> V_11 + V_15 ) ;
F_11 ( V_53 , V_51 -> V_11 + V_12 ) ;
F_11 ( V_54 | V_27 ,
V_51 -> V_11 + V_29 ) ;
}
static int F_27 ( struct V_55 * V_56 )
{
struct V_8 * V_51 ;
struct V_57 * V_58 ;
int V_59 ;
V_58 = F_28 ( V_56 , V_60 , 0 ) ;
if ( ! V_58 ) {
V_59 = - V_61 ;
goto V_62;
}
V_51 = F_29 ( sizeof( struct V_8 ) , V_63 ) ;
if ( ! V_51 ) {
V_59 = - V_64 ;
goto V_62;
}
V_51 -> V_11 = V_58 -> V_65 ;
if ( ! V_51 -> V_11 ) {
V_59 = - V_66 ;
goto V_67;
}
V_51 -> V_68 = 200 ;
V_51 -> V_69 = 200 ;
V_51 -> V_18 = 200 ;
V_51 -> V_9 . V_70 = V_56 -> V_71 ;
V_51 -> V_9 . V_72 = & V_73 ;
V_51 -> V_9 . V_43 = V_51 ;
V_51 -> V_9 . V_74 . V_75 = & V_56 -> V_74 ;
F_30 ( V_51 -> V_9 . V_76 , L_4 , sizeof( V_51 -> V_9 . V_76 ) ) ;
F_26 ( V_51 ) ;
V_59 = F_31 ( & V_51 -> V_9 ) ;
if ( V_59 == 0 ) {
F_32 ( V_56 , V_51 ) ;
return 0 ;
}
V_67:
F_33 ( V_51 ) ;
V_62:
return V_59 ;
}
static int F_34 ( struct V_55 * V_56 )
{
struct V_8 * V_51 = F_35 ( V_56 ) ;
F_32 ( V_56 , NULL ) ;
F_36 ( & V_51 -> V_9 ) ;
F_33 ( V_51 ) ;
return 0 ;
}
static int F_37 ( struct V_55 * V_56 ,
T_2 V_77 )
{
F_38 ( & V_56 -> V_74 , L_5 ) ;
return 0 ;
}
static int F_39 ( struct V_55 * V_56 )
{
struct V_8 * V_51 = F_35 ( V_56 ) ;
F_38 ( & V_56 -> V_74 , L_6 ) ;
F_26 ( V_51 ) ;
return 0 ;
}
static int T_3 F_40 ( void )
{
return F_41 ( & V_78 ) ;
}
static void T_4 F_42 ( void )
{
F_43 ( & V_78 ) ;
}
