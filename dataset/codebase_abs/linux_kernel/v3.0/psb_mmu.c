static inline T_1 F_1 ( T_1 V_1 )
{
return ( V_1 >> V_2 ) & 0x3FF ;
}
static inline T_1 F_2 ( T_1 V_1 )
{
return V_1 >> V_3 ;
}
static inline void F_3 ( void * V_4 )
{
__asm__ __volatile__("clflush (%0)\n" : : "r"(addr) : "memory");
}
static inline void F_4 ( struct V_5 * V_6 ,
void * V_4 )
{
if ( ! V_6 -> V_7 )
return;
F_5 () ;
F_3 ( V_4 ) ;
F_5 () ;
}
static void F_6 ( struct V_5 * V_6 , struct V_8 * V_8 )
{
T_1 V_9 = V_6 -> V_9 >> V_10 ;
T_1 V_11 = V_12 / V_9 ;
int V_13 ;
T_2 * V_14 ;
V_14 = F_7 ( V_8 , V_15 ) ;
F_5 () ;
for ( V_13 = 0 ; V_13 < V_11 ; ++ V_13 ) {
F_3 ( V_14 ) ;
V_14 += V_9 ;
}
F_5 () ;
F_8 ( V_14 , V_15 ) ;
}
static void F_9 ( struct V_5 * V_6 ,
struct V_8 * V_8 [] , unsigned long V_16 )
{
int V_13 ;
if ( ! V_6 -> V_7 )
return ;
for ( V_13 = 0 ; V_13 < V_16 ; V_13 ++ )
F_6 ( V_6 , * V_8 ++ ) ;
}
static void F_10 ( struct V_5 * V_6 ,
int V_17 )
{
F_11 ( & V_6 -> V_18 , 0 ) ;
}
static void F_12 ( struct V_5 * V_6 , int V_17 )
{
F_13 ( & V_6 -> V_19 ) ;
F_10 ( V_6 , V_17 ) ;
F_14 ( & V_6 -> V_19 ) ;
}
void F_15 ( struct V_5 * V_6 , int V_20 )
{
if ( V_20 )
F_13 ( & V_6 -> V_19 ) ;
if ( V_20 )
F_14 ( & V_6 -> V_19 ) ;
}
void F_16 ( struct V_21 * V_22 , int V_23 )
{
F_9 ( V_22 -> V_6 , & V_22 -> V_24 , 1 ) ;
F_13 ( & V_22 -> V_6 -> V_19 ) ;
F_17 () ;
F_10 ( V_22 -> V_6 , 1 ) ;
V_22 -> V_23 = V_23 ;
F_14 ( & V_22 -> V_6 -> V_19 ) ;
}
static inline unsigned long F_18 ( unsigned long V_4 ,
unsigned long V_25 )
{
V_4 = ( V_4 + V_26 + 1 ) & ~ V_26 ;
return ( V_4 < V_25 ) ? V_4 : V_25 ;
}
static inline T_1 F_19 ( T_1 V_27 , int type )
{
T_1 V_28 = V_29 ;
if ( type & V_30 )
V_28 |= V_31 ;
if ( type & V_32 )
V_28 |= V_33 ;
if ( type & V_34 )
V_28 |= V_35 ;
return ( V_27 << V_10 ) | V_28 ;
}
struct V_21 * F_20 ( struct V_5 * V_6 ,
int V_36 , int V_37 )
{
struct V_21 * V_22 = F_21 ( sizeof( * V_22 ) , V_38 ) ;
T_1 * V_39 ;
int V_13 ;
if ( ! V_22 )
return NULL ;
V_22 -> V_24 = F_22 ( V_40 ) ;
if ( ! V_22 -> V_24 )
goto V_41;
V_22 -> V_42 = F_22 ( V_40 ) ;
if ( ! V_22 -> V_42 )
goto V_43;
V_22 -> V_44 = F_22 ( V_40 ) ;
if ( ! V_22 -> V_44 )
goto V_45;
if ( ! V_36 ) {
V_22 -> V_46 =
F_19 ( F_23 ( V_22 -> V_42 ) ,
V_37 ) ;
V_22 -> V_47 =
F_19 ( F_23 ( V_22 -> V_44 ) ,
V_37 ) ;
} else {
V_22 -> V_46 = 0 ;
V_22 -> V_47 = 0 ;
}
V_39 = F_24 ( V_22 -> V_42 ) ;
for ( V_13 = 0 ; V_13 < ( V_12 / sizeof( T_1 ) ) ; ++ V_13 )
V_39 [ V_13 ] = V_22 -> V_47 ;
F_25 ( V_22 -> V_42 ) ;
V_39 = F_24 ( V_22 -> V_24 ) ;
for ( V_13 = 0 ; V_13 < ( V_12 / sizeof( T_1 ) ) ; ++ V_13 )
V_39 [ V_13 ] = V_22 -> V_46 ;
F_25 ( V_22 -> V_24 ) ;
F_26 ( F_24 ( V_22 -> V_44 ) ) ;
F_25 ( V_22 -> V_44 ) ;
V_22 -> V_48 = F_27 ( sizeof( struct V_49 * ) * 1024 ) ;
if ( ! V_22 -> V_48 )
goto V_50;
V_22 -> V_23 = - 1 ;
V_22 -> V_51 = V_29 ;
V_22 -> V_6 = V_6 ;
return V_22 ;
V_50:
F_28 ( V_22 -> V_44 ) ;
V_45:
F_28 ( V_22 -> V_42 ) ;
V_43:
F_28 ( V_22 -> V_24 ) ;
V_41:
F_29 ( V_22 ) ;
return NULL ;
}
void F_30 ( struct V_49 * V_52 )
{
F_28 ( V_52 -> V_24 ) ;
F_29 ( V_52 ) ;
}
void F_31 ( struct V_21 * V_22 )
{
struct V_5 * V_6 = V_22 -> V_6 ;
struct V_49 * V_52 ;
int V_13 ;
F_13 ( & V_6 -> V_19 ) ;
if ( V_22 -> V_23 != - 1 )
F_10 ( V_6 , 1 ) ;
for ( V_13 = 0 ; V_13 < 1024 ; ++ V_13 ) {
V_52 = V_22 -> V_48 [ V_13 ] ;
if ( V_52 )
F_30 ( V_52 ) ;
}
F_32 ( V_22 -> V_48 ) ;
F_28 ( V_22 -> V_44 ) ;
F_28 ( V_22 -> V_42 ) ;
F_28 ( V_22 -> V_24 ) ;
F_29 ( V_22 ) ;
F_14 ( & V_6 -> V_19 ) ;
}
static struct V_49 * F_33 ( struct V_21 * V_22 )
{
struct V_49 * V_52 = F_21 ( sizeof( * V_52 ) , V_38 ) ;
void * V_39 ;
T_1 V_9 = V_22 -> V_6 -> V_9 >> V_10 ;
T_1 V_11 = V_12 / V_9 ;
T_3 * V_53 = & V_22 -> V_6 -> V_53 ;
T_2 * V_14 ;
T_1 * V_54 ;
int V_13 ;
if ( ! V_52 )
return NULL ;
V_52 -> V_24 = F_22 ( V_40 ) ;
if ( ! V_52 -> V_24 ) {
F_29 ( V_52 ) ;
return NULL ;
}
F_34 ( V_53 ) ;
V_39 = F_7 ( V_52 -> V_24 , V_15 ) ;
V_14 = ( T_2 * ) V_39 ;
V_54 = ( T_1 * ) V_39 ;
for ( V_13 = 0 ; V_13 < ( V_12 / sizeof( T_1 ) ) ; ++ V_13 )
* V_54 ++ = V_22 -> V_47 ;
if ( V_22 -> V_6 -> V_7 && V_22 -> V_23 != - 1 ) {
F_5 () ;
for ( V_13 = 0 ; V_13 < V_11 ; ++ V_13 ) {
F_3 ( V_14 ) ;
V_14 += V_9 ;
}
F_5 () ;
}
F_8 ( V_39 , V_15 ) ;
F_35 ( V_53 ) ;
V_52 -> V_55 = 0 ;
V_52 -> V_22 = V_22 ;
V_52 -> V_56 = 0 ;
return V_52 ;
}
struct V_49 * F_36 ( struct V_21 * V_22 ,
unsigned long V_4 )
{
T_1 V_56 = F_2 ( V_4 ) ;
struct V_49 * V_52 ;
T_1 * V_39 ;
T_3 * V_53 = & V_22 -> V_6 -> V_53 ;
F_34 ( V_53 ) ;
V_52 = V_22 -> V_48 [ V_56 ] ;
while ( ! V_52 ) {
F_35 ( V_53 ) ;
V_52 = F_33 ( V_22 ) ;
if ( ! V_52 )
return NULL ;
F_34 ( V_53 ) ;
if ( V_22 -> V_48 [ V_56 ] ) {
F_35 ( V_53 ) ;
F_30 ( V_52 ) ;
F_34 ( V_53 ) ;
V_52 = V_22 -> V_48 [ V_56 ] ;
continue;
}
V_39 = F_7 ( V_22 -> V_24 , V_15 ) ;
V_22 -> V_48 [ V_56 ] = V_52 ;
V_39 [ V_56 ] = ( F_23 ( V_52 -> V_24 ) << 12 ) | V_22 -> V_51 ;
V_52 -> V_56 = V_56 ;
F_8 ( ( void * ) V_39 , V_15 ) ;
if ( V_22 -> V_23 != - 1 ) {
F_4 ( V_22 -> V_6 , ( void * ) & V_39 [ V_56 ] ) ;
F_11 ( & V_22 -> V_6 -> V_18 , 1 ) ;
}
}
V_52 -> V_39 = F_7 ( V_52 -> V_24 , V_15 ) ;
return V_52 ;
}
static struct V_49 * F_37 ( struct V_21 * V_22 ,
unsigned long V_4 )
{
T_1 V_56 = F_2 ( V_4 ) ;
struct V_49 * V_52 ;
T_3 * V_53 = & V_22 -> V_6 -> V_53 ;
F_34 ( V_53 ) ;
V_52 = V_22 -> V_48 [ V_56 ] ;
if ( ! V_52 ) {
F_35 ( V_53 ) ;
return NULL ;
}
V_52 -> V_39 = F_7 ( V_52 -> V_24 , V_15 ) ;
return V_52 ;
}
static void F_38 ( struct V_49 * V_52 )
{
struct V_21 * V_22 = V_52 -> V_22 ;
T_1 * V_39 ;
F_8 ( V_52 -> V_39 , V_15 ) ;
if ( V_52 -> V_55 == 0 ) {
V_39 = F_7 ( V_22 -> V_24 , V_15 ) ;
V_39 [ V_52 -> V_56 ] = V_22 -> V_46 ;
V_22 -> V_48 [ V_52 -> V_56 ] = NULL ;
if ( V_22 -> V_23 != - 1 ) {
F_4 ( V_22 -> V_6 ,
( void * ) & V_39 [ V_52 -> V_56 ] ) ;
F_11 ( & V_22 -> V_6 -> V_18 , 1 ) ;
}
F_8 ( V_52 -> V_39 , V_15 ) ;
F_35 ( & V_22 -> V_6 -> V_53 ) ;
F_30 ( V_52 ) ;
return;
}
F_35 ( & V_22 -> V_6 -> V_53 ) ;
}
static inline void F_39 ( struct V_49 * V_52 ,
unsigned long V_4 , T_1 V_57 )
{
V_52 -> V_39 [ F_1 ( V_4 ) ] = V_57 ;
}
static inline void F_40 ( struct V_49 * V_52 ,
unsigned long V_4 )
{
V_52 -> V_39 [ F_1 ( V_4 ) ] = V_52 -> V_22 -> V_47 ;
}
void F_41 ( struct V_21 * V_22 ,
T_1 V_58 , T_1 V_59 ,
T_1 V_60 )
{
T_1 * V_39 ;
T_1 V_61 = F_2 ( V_58 ) ;
struct V_5 * V_6 = V_22 -> V_6 ;
int V_16 = V_60 ;
F_42 ( & V_6 -> V_19 ) ;
F_34 ( & V_6 -> V_53 ) ;
V_39 = F_7 ( V_22 -> V_24 , V_15 ) ;
V_39 += V_61 ;
while ( V_60 -- ) {
* V_39 ++ = V_59 | V_22 -> V_51 ;
V_59 += V_12 ;
}
F_9 ( V_22 -> V_6 , & V_22 -> V_24 , V_16 ) ;
F_8 ( V_39 , V_15 ) ;
F_35 ( & V_6 -> V_53 ) ;
if ( V_22 -> V_23 != - 1 )
F_11 ( & V_22 -> V_6 -> V_18 , 1 ) ;
F_43 ( & V_22 -> V_6 -> V_19 ) ;
F_12 ( V_22 -> V_6 , 0 ) ;
}
struct V_21 * F_44 ( struct V_5 * V_6 )
{
struct V_21 * V_22 ;
V_22 = V_6 -> V_62 ;
return V_22 ;
}
T_1 F_45 ( struct V_5 * V_6 )
{
struct V_21 * V_22 ;
V_22 = F_44 ( V_6 ) ;
return F_23 ( V_22 -> V_24 ) << V_10 ;
}
void F_46 ( struct V_5 * V_6 )
{
F_31 ( V_6 -> V_62 ) ;
F_29 ( V_6 ) ;
}
struct V_5 * F_47 ( T_2 T_4 * V_63 ,
int V_36 ,
int V_37 ,
struct V_64 * V_65 )
{
struct V_5 * V_6 ;
V_6 = F_21 ( sizeof( * V_6 ) , V_38 ) ;
if ( ! V_6 )
return NULL ;
V_6 -> V_65 = V_65 ;
V_6 -> V_62 = F_20 ( V_6 , V_36 ,
V_37 ) ;
if ( ! V_6 -> V_62 )
goto V_41;
F_48 ( & V_6 -> V_53 ) ;
F_49 ( & V_6 -> V_19 ) ;
F_13 ( & V_6 -> V_19 ) ;
V_6 -> V_66 = V_63 ;
F_11 ( & V_6 -> V_18 , 1 ) ;
V_6 -> V_7 = 0 ;
if ( F_50 ( V_67 ) ) {
T_1 V_68 , V_69 , V_70 , V_71 , V_72 ;
F_51 ( 0x00000001 , & V_68 , & V_69 , & V_70 , & V_71 ) ;
V_72 = ( ( V_69 >> 8 ) & 0xff ) * 8 ;
V_6 -> V_7 = 1 ;
V_6 -> V_9 =
V_12 * V_72 / sizeof( T_1 ) ;
V_6 -> V_73 = V_6 -> V_9 - 1 ;
V_6 -> V_73 = ~ V_6 -> V_73 ;
}
F_14 ( & V_6 -> V_19 ) ;
return V_6 ;
V_41:
F_29 ( V_6 ) ;
return NULL ;
}
static void F_52 ( struct V_21 * V_22 ,
unsigned long V_74 , T_1 V_16 ,
T_1 V_75 ,
T_1 V_76 )
{
struct V_49 * V_52 ;
T_1 V_77 = 1 ;
T_1 V_13 ;
unsigned long V_4 ;
unsigned long V_25 ;
unsigned long V_78 ;
unsigned long V_79 ;
unsigned long V_80 ;
unsigned long V_9 = V_22 -> V_6 -> V_9 ;
unsigned long V_73 = V_22 -> V_6 -> V_73 ;
if ( ! V_22 -> V_6 -> V_7 ) {
F_9 ( V_22 -> V_6 , & V_22 -> V_24 , V_16 ) ;
return;
}
if ( V_76 )
V_77 = V_16 / V_75 ;
else
V_75 = V_16 ;
V_79 = V_75 << V_10 ;
V_80 = V_76 << V_10 ;
F_5 () ;
for ( V_13 = 0 ; V_13 < V_77 ; ++ V_13 ) {
V_4 = V_74 ;
V_25 = V_4 + V_79 ;
do {
V_78 = F_18 ( V_4 , V_25 ) ;
V_52 = F_37 ( V_22 , V_4 ) ;
if ( ! V_52 )
continue;
do {
F_3 ( & V_52 -> V_39
[ F_1 ( V_4 ) ] ) ;
} while ( V_4 +=
V_9 ,
( V_4 & V_73 ) < V_78 );
F_38 ( V_52 ) ;
} while ( V_4 = V_78 , V_78 != V_25 );
V_74 += V_80 ;
}
F_5 () ;
}
void F_53 ( struct V_21 * V_22 ,
unsigned long V_74 , T_1 V_16 )
{
struct V_49 * V_52 ;
unsigned long V_4 ;
unsigned long V_25 ;
unsigned long V_78 ;
unsigned long V_81 = V_74 ;
F_42 ( & V_22 -> V_6 -> V_19 ) ;
V_4 = V_74 ;
V_25 = V_4 + ( V_16 << V_10 ) ;
do {
V_78 = F_18 ( V_4 , V_25 ) ;
V_52 = F_36 ( V_22 , V_4 ) ;
if ( ! V_52 )
goto V_82;
do {
F_40 ( V_52 , V_4 ) ;
-- V_52 -> V_55 ;
} while ( V_4 += V_12 , V_4 < V_78 );
F_38 ( V_52 ) ;
} while ( V_4 = V_78 , V_78 != V_25 );
V_82:
if ( V_22 -> V_23 != - 1 )
F_52 ( V_22 , V_81 , V_16 , 1 , 1 ) ;
F_43 ( & V_22 -> V_6 -> V_19 ) ;
if ( V_22 -> V_23 != - 1 )
F_15 ( V_22 -> V_6 , 0 ) ;
return;
}
void F_54 ( struct V_21 * V_22 , unsigned long V_74 ,
T_1 V_16 , T_1 V_75 ,
T_1 V_76 )
{
struct V_49 * V_52 ;
T_1 V_77 = 1 ;
T_1 V_13 ;
unsigned long V_4 ;
unsigned long V_25 ;
unsigned long V_78 ;
unsigned long V_79 ;
unsigned long V_80 ;
unsigned long V_81 = V_74 ;
if ( V_76 )
V_77 = V_16 / V_75 ;
else
V_75 = V_16 ;
V_79 = V_75 << V_10 ;
V_80 = V_76 << V_10 ;
for ( V_13 = 0 ; V_13 < V_77 ; ++ V_13 ) {
V_4 = V_74 ;
V_25 = V_4 + V_79 ;
do {
V_78 = F_18 ( V_4 , V_25 ) ;
V_52 = F_37 ( V_22 , V_4 ) ;
if ( ! V_52 )
continue;
do {
F_40 ( V_52 , V_4 ) ;
-- V_52 -> V_55 ;
} while ( V_4 += V_12 , V_4 < V_78 );
F_38 ( V_52 ) ;
} while ( V_4 = V_78 , V_78 != V_25 );
V_74 += V_80 ;
}
if ( V_22 -> V_23 != - 1 )
F_52 ( V_22 , V_81 , V_16 ,
V_75 , V_76 ) ;
if ( V_22 -> V_23 != - 1 )
F_15 ( V_22 -> V_6 , 0 ) ;
}
int F_55 ( struct V_21 * V_22 , T_1 V_83 ,
unsigned long V_74 , T_1 V_16 ,
int type )
{
struct V_49 * V_52 ;
T_1 V_57 ;
unsigned long V_4 ;
unsigned long V_25 ;
unsigned long V_78 ;
unsigned long V_81 = V_74 ;
int V_84 = 0 ;
F_42 ( & V_22 -> V_6 -> V_19 ) ;
V_4 = V_74 ;
V_25 = V_4 + ( V_16 << V_10 ) ;
do {
V_78 = F_18 ( V_4 , V_25 ) ;
V_52 = F_36 ( V_22 , V_4 ) ;
if ( ! V_52 ) {
V_84 = - V_85 ;
goto V_82;
}
do {
V_57 = F_19 ( V_83 ++ , type ) ;
F_39 ( V_52 , V_4 , V_57 ) ;
V_52 -> V_55 ++ ;
} while ( V_4 += V_12 , V_4 < V_78 );
F_38 ( V_52 ) ;
} while ( V_4 = V_78 , V_78 != V_25 );
V_82:
if ( V_22 -> V_23 != - 1 )
F_52 ( V_22 , V_81 , V_16 , 1 , 1 ) ;
F_43 ( & V_22 -> V_6 -> V_19 ) ;
if ( V_22 -> V_23 != - 1 )
F_15 ( V_22 -> V_6 , 1 ) ;
return V_84 ;
}
int F_56 ( struct V_21 * V_22 , struct V_8 * * V_86 ,
unsigned long V_74 , T_1 V_16 ,
T_1 V_75 ,
T_1 V_76 , int type )
{
struct V_49 * V_52 ;
T_1 V_77 = 1 ;
T_1 V_13 ;
T_1 V_57 ;
unsigned long V_4 ;
unsigned long V_25 ;
unsigned long V_78 ;
unsigned long V_79 ;
unsigned long V_80 ;
unsigned long V_81 = V_74 ;
int V_84 = 0 ;
if ( V_76 ) {
if ( V_16 % V_75 != 0 )
return - V_87 ;
V_77 = V_16 / V_75 ;
} else {
V_75 = V_16 ;
}
V_79 = V_75 << V_10 ;
V_80 = V_76 << V_10 ;
F_42 ( & V_22 -> V_6 -> V_19 ) ;
for ( V_13 = 0 ; V_13 < V_77 ; ++ V_13 ) {
V_4 = V_74 ;
V_25 = V_4 + V_79 ;
do {
V_78 = F_18 ( V_4 , V_25 ) ;
V_52 = F_36 ( V_22 , V_4 ) ;
if ( ! V_52 ) {
V_84 = - V_85 ;
goto V_82;
}
do {
V_57 =
F_19 ( F_23 ( * V_86 ++ ) ,
type ) ;
F_39 ( V_52 , V_4 , V_57 ) ;
V_52 -> V_55 ++ ;
} while ( V_4 += V_12 , V_4 < V_78 );
F_38 ( V_52 ) ;
} while ( V_4 = V_78 , V_78 != V_25 );
V_74 += V_80 ;
}
V_82:
if ( V_22 -> V_23 != - 1 )
F_52 ( V_22 , V_81 , V_16 ,
V_75 , V_76 ) ;
F_43 ( & V_22 -> V_6 -> V_19 ) ;
if ( V_22 -> V_23 != - 1 )
F_15 ( V_22 -> V_6 , 1 ) ;
return V_84 ;
}
int F_57 ( struct V_21 * V_22 , T_1 V_88 ,
unsigned long * V_27 )
{
int V_84 ;
struct V_49 * V_52 ;
T_1 V_89 ;
T_3 * V_53 = & V_22 -> V_6 -> V_53 ;
F_42 ( & V_22 -> V_6 -> V_19 ) ;
V_52 = F_37 ( V_22 , V_88 ) ;
if ( ! V_52 ) {
T_1 * V_39 ;
F_34 ( V_53 ) ;
V_39 = F_7 ( V_22 -> V_24 , V_15 ) ;
V_89 = V_39 [ F_2 ( V_88 ) ] ;
F_8 ( V_39 , V_15 ) ;
F_35 ( V_53 ) ;
if ( V_89 != V_22 -> V_46 || ! ( V_89 & V_29 ) ||
! ( V_22 -> V_47 & V_29 ) ) {
V_84 = - V_87 ;
goto V_82;
}
V_84 = 0 ;
* V_27 = V_22 -> V_47 >> V_10 ;
goto V_82;
}
V_89 = V_52 -> V_39 [ F_1 ( V_88 ) ] ;
if ( ! ( V_89 & V_29 ) ) {
V_84 = - V_87 ;
} else {
V_84 = 0 ;
* V_27 = V_89 >> V_10 ;
}
F_38 ( V_52 ) ;
V_82:
F_43 ( & V_22 -> V_6 -> V_19 ) ;
return V_84 ;
}
