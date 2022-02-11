static inline void F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_2 = (struct V_2 * ) V_1 ;
while ( F_2 ( F_3 ( V_3 , & V_2 -> V_4 ) ) ) {
do {
F_4 () ;
} while ( F_5 ( V_3 , & V_2 -> V_4 ) );
}
}
static inline void F_6 ( struct V_1 * V_1 )
{
struct V_2 * V_2 = (struct V_2 * ) V_1 ;
F_7 ( V_3 , & V_2 -> V_4 ) ;
}
static inline int F_8 ( struct V_1 * V_1 )
{
return F_9 ( (struct V_2 * ) V_1 ) ;
}
static inline int F_10 ( struct V_1 * V_1 )
{
return F_11 ( (struct V_2 * ) V_1 ) ;
}
static inline void * F_12 ( struct V_1 * V_1 )
{
return F_13 ( (struct V_2 * ) V_1 ) ;
}
static inline int F_14 ( struct V_1 * V_1 )
{
struct V_2 * V_2 = (struct V_2 * ) V_1 ;
return F_5 ( V_5 , & V_2 -> V_4 ) ;
}
static inline void F_15 ( struct V_1 * V_1 )
{
struct V_2 * V_2 = (struct V_2 * ) V_1 ;
F_16 ( V_5 , & V_2 -> V_4 ) ;
}
static inline void F_17 ( struct V_1 * V_1 )
{
struct V_2 * V_2 = (struct V_2 * ) V_1 ;
F_7 ( V_5 , & V_2 -> V_4 ) ;
}
static inline int F_18 ( struct V_1 * V_1 )
{
struct V_2 * V_2 = (struct V_2 * ) V_1 ;
return F_5 ( V_6 , & V_2 -> V_4 ) ;
}
static inline void F_19 ( struct V_1 * V_1 )
{
struct V_2 * V_2 = (struct V_2 * ) V_1 ;
F_16 ( V_6 , & V_2 -> V_4 ) ;
}
static inline void F_20 ( struct V_1 * V_1 )
{
struct V_2 * V_2 = (struct V_2 * ) V_1 ;
F_7 ( V_6 , & V_2 -> V_4 ) ;
}
static inline void F_21 ( void * V_7 )
{
F_22 ( V_7 ) ;
}
static inline struct V_1 * F_23 ( struct V_8 * V_9 )
{
unsigned long V_10 = ( unsigned long ) V_9 ;
V_10 &= ~ 1UL ;
return (struct V_1 * ) V_10 ;
}
static inline struct V_8 * F_24 ( struct V_1 * V_1 ,
unsigned V_11 )
{
unsigned long V_10 = ( unsigned long ) V_1 ;
F_25 ( V_11 > 1 ) ;
V_10 |= V_11 ;
return (struct V_8 * ) V_10 ;
}
static inline int F_26 ( struct V_8 * V_8 )
{
unsigned long V_10 = ( unsigned long ) V_8 ;
return V_10 & 1UL ;
}
static inline unsigned F_27 ( void )
{
return V_12 << V_13 ;
}
static inline unsigned F_28 ( unsigned V_14 )
{
F_25 ( V_14 == 0 || V_14 > F_27 () ) ;
return ( V_14 + V_15 - 1 ) >> V_13 ;
}
static inline char * F_29 ( void * V_7 ,
unsigned V_11 , unsigned V_14 )
{
char * V_16 ;
F_25 ( V_14 == 0 || V_14 > F_27 () ) ;
V_16 = ( char * ) V_7 ;
if ( V_11 == 1 )
V_16 += V_17 - ( ( V_14 + V_15 - 1 ) & V_18 ) ;
return V_16 ;
}
static int F_30 ( void )
{
struct V_19 * V_20 = F_31 ( L_1 , NULL ) ;
if ( V_20 == NULL )
return - V_21 ;
F_32 ( L_2 , V_22 , V_20 , & V_23 ) ;
F_32 ( L_3 , V_22 , V_20 , & V_24 ) ;
F_32 ( L_4 , V_22 , V_20 , & V_25 ) ;
F_32 ( L_5 , V_22 , V_20 , & V_26 ) ;
F_33 ( L_6 , V_22 , V_20 , & V_27 ) ;
F_33 ( L_7 , V_22 , V_20 ,
& V_28 ) ;
F_33 ( L_8 , V_22 , V_20 , & V_29 ) ;
F_33 ( L_9 , V_22 , V_20 , & V_30 ) ;
F_33 ( L_10 , V_22 , V_20 , & V_31 ) ;
F_33 ( L_11 , V_22 , V_20 , & V_32 ) ;
F_33 ( L_12 , V_22 , V_20 , & V_33 ) ;
F_33 ( L_13 , V_22 , V_20 ,
& V_34 ) ;
F_33 ( L_14 , V_22 , V_20 , & V_35 ) ;
F_33 ( L_15 , V_22 , V_20 , & V_36 ) ;
F_33 ( L_16 , V_22 , V_20 , & V_37 ) ;
F_33 ( L_17 , V_22 , V_20 , & V_38 ) ;
F_33 ( L_18 , V_22 , V_20 , & V_39 ) ;
return 0 ;
}
static inline struct V_1 * F_34 ( struct V_2 * V_2 , bool V_40 )
{
struct V_1 * V_1 = (struct V_1 * ) V_2 ;
F_25 ( V_2 == NULL ) ;
F_35 ( & V_1 -> V_41 ) ;
F_35 ( & V_1 -> V_42 ) ;
V_1 -> V_43 = 0 ;
V_1 -> V_44 = 0 ;
V_1 -> V_45 = 0 ;
if ( V_40 )
V_30 ++ ;
else
V_36 ++ ;
return V_1 ;
}
static inline struct V_2 * F_36 ( struct V_1 * V_1 ,
bool V_40 )
{
struct V_2 * V_2 = (struct V_2 * ) V_1 ;
F_25 ( ! F_37 ( & V_1 -> V_41 ) ) ;
F_25 ( ! F_37 ( & V_1 -> V_42 ) ) ;
F_25 ( V_1 -> V_43 != 0 ) ;
F_25 ( V_1 -> V_44 != 0 ) ;
F_25 ( ! F_11 ( V_2 ) ) ;
F_25 ( V_1 -> V_45 != 0 ) ;
F_25 ( F_14 ( V_1 ) ) ;
F_25 ( F_18 ( V_1 ) ) ;
if ( V_40 )
V_30 -- ;
else
V_36 -- ;
F_6 ( V_1 ) ;
F_38 ( V_2 ) ;
F_39 ( V_2 ) ;
V_2 -> V_46 = 0 ;
return V_2 ;
}
static inline void F_40 ( struct V_1 * V_1 ,
int V_11 , bool V_40 )
{
unsigned V_14 ;
F_25 ( ! F_10 ( V_1 ) ) ;
if ( V_11 == 0 ) {
V_14 = V_1 -> V_43 ;
V_1 -> V_43 = 0 ;
} else {
V_14 = V_1 -> V_44 ;
V_1 -> V_44 = 0 ;
}
if ( V_40 ) {
V_23 -= V_14 ;
V_29 -- ;
} else {
V_25 -= V_14 ;
V_35 -- ;
}
}
static void F_41 ( struct V_1 * V_1 , struct V_47 * V_48 ,
bool V_40 , void * V_49 ,
unsigned V_11 , unsigned V_14 )
{
char * V_50 ;
void * V_7 ;
struct V_47 * V_51 ;
unsigned V_52 = F_28 ( V_14 ) ;
F_25 ( ! F_10 ( V_1 ) ) ;
V_7 = F_12 ( V_1 ) ;
V_50 = F_29 ( V_7 , V_11 , V_14 ) ;
V_51 = (struct V_47 * ) V_50 ;
V_51 -> V_46 = V_48 -> V_46 ;
V_51 -> V_53 = V_48 -> V_53 ;
V_51 -> V_54 = V_48 -> V_54 ;
V_51 -> V_55 = V_48 -> V_55 ;
V_50 += sizeof( struct V_47 ) ;
if ( V_49 != NULL )
memcpy ( V_50 , V_49 , V_14 - sizeof( struct V_47 ) ) ;
F_21 ( V_7 ) ;
if ( V_11 == 0 )
V_1 -> V_43 = V_14 ;
else
V_1 -> V_44 = V_14 ;
if ( V_40 ) {
V_56 [ V_52 ] ++ ;
V_29 ++ ;
V_27 ++ ;
V_23 += V_14 ;
V_24 += V_14 ;
} else {
V_57 [ V_52 ] ++ ;
V_35 ++ ;
V_33 ++ ;
V_25 += V_14 ;
V_26 += V_14 ;
}
}
static void F_42 ( struct V_1 * V_1 )
{
int V_58 , V_59 ;
T_1 V_54 [ 2 ] , V_55 [ 2 ] ;
T_1 V_46 [ 2 ] ;
struct V_60 V_53 [ 2 ] ;
struct V_61 * V_62 ;
void * V_7 ;
struct V_47 * V_48 ;
unsigned V_14 ;
V_7 = F_12 ( V_1 ) ;
for ( V_58 = 0 , V_59 = 0 ; V_58 < 2 ; V_58 ++ ) {
V_14 = ( V_58 == 0 ) ? V_1 -> V_43 : V_1 -> V_44 ;
if ( V_14 ) {
V_48 = (struct V_47 * ) F_29 ( V_7 , V_58 , V_14 ) ;
V_55 [ V_59 ] = V_48 -> V_55 ;
V_54 [ V_59 ] = V_48 -> V_54 ;
V_53 [ V_59 ] = V_48 -> V_53 ;
V_46 [ V_59 ] = V_48 -> V_46 ;
V_59 ++ ;
F_40 ( V_1 , V_58 , true ) ;
}
}
F_21 ( V_7 ) ;
F_6 ( V_1 ) ;
for ( V_58 = 0 ; V_58 < V_59 ; V_58 ++ ) {
V_62 = F_43 ( V_55 [ V_58 ] , V_54 [ V_58 ] ) ;
if ( V_62 != NULL ) {
F_44 ( V_62 , & V_53 [ V_58 ] , V_46 [ V_58 ] ) ;
F_45 ( V_62 ) ;
}
}
}
unsigned int F_46 ( void )
{
return F_27 () - sizeof( struct V_47 ) ;
}
struct V_2 * F_47 ( struct V_8 * V_9 , bool V_40 ,
unsigned int * V_63 , unsigned int * V_64 )
{
unsigned long V_11 = F_26 ( V_9 ) ;
struct V_1 * V_1 = F_23 ( V_9 ) ;
struct V_2 * V_2 = NULL ;
unsigned V_65 , V_66 , V_67 ;
T_2 * V_68 =
V_40 ? & V_69 : & V_70 ;
struct V_71 * V_72 =
V_40 ? V_73 : V_74 ;
F_48 ( V_68 ) ;
F_1 ( V_1 ) ;
if ( F_14 ( V_1 ) ) {
F_6 ( V_1 ) ;
F_49 ( V_68 ) ;
* V_64 = 0 ;
* V_63 = 0 ;
goto V_75;
}
if ( V_11 == 0 ) {
V_66 = V_1 -> V_43 ;
V_67 = V_1 -> V_44 ;
} else {
V_66 = V_1 -> V_44 ;
V_67 = V_1 -> V_43 ;
}
* V_63 = V_66 - sizeof( struct V_47 ) ;
* V_64 = 1 ;
F_40 ( V_1 , V_11 , V_40 ) ;
if ( V_67 == 0 ) {
V_65 = F_28 ( V_66 ) ;
if ( F_18 ( V_1 ) ) {
if ( V_40 )
V_39 =
F_50 ( & V_76 ) ;
else
V_39 =
F_50 ( & V_77 ) ;
F_20 ( V_1 ) ;
} else {
F_25 ( F_37 ( & V_72 [ V_65 ] . V_78 ) ) ;
F_51 ( & V_1 -> V_41 ) ;
V_72 [ V_65 ] . V_79 -- ;
}
F_51 ( & V_1 -> V_42 ) ;
F_49 ( V_68 ) ;
if ( V_40 )
V_32 -- ;
else
V_38 -- ;
V_2 = F_36 ( V_1 , V_40 ) ;
} else {
V_65 = F_28 ( V_67 ) ;
if ( ! F_18 ( V_1 ) ) {
F_51 ( & V_1 -> V_41 ) ;
F_52 ( & V_1 -> V_41 , & V_72 [ V_65 ] . V_78 ) ;
V_72 [ V_65 ] . V_79 ++ ;
}
if ( V_40 ) {
V_31 -- ;
V_32 ++ ;
} else {
V_38 ++ ;
V_37 -- ;
}
F_6 ( V_1 ) ;
F_49 ( V_68 ) ;
}
V_75:
return V_2 ;
}
struct V_8 * F_53 ( struct V_47 * V_48 , bool V_40 ,
void * V_49 , unsigned V_14 )
{
struct V_1 * V_1 = NULL , * V_80 ;
unsigned long V_11 = 0UL ;
unsigned V_52 ;
int V_58 , V_81 = 0 ;
T_2 * V_68 =
V_40 ? & V_69 : & V_70 ;
struct V_71 * V_72 =
V_40 ? V_73 : V_74 ;
V_14 += sizeof( struct V_47 ) ;
V_52 = F_28 ( V_14 ) ;
for ( V_58 = V_12 - V_52 + 1 ; V_58 > 0 ; V_58 -- ) {
F_48 ( V_68 ) ;
if ( ! F_37 ( & V_72 [ V_58 ] . V_78 ) ) {
F_54 (zbudpage, zbudpage2,
&unbud[i].list, budlist) {
if ( F_8 ( V_1 ) ) {
V_81 = V_58 ;
goto V_82;
}
}
}
F_49 ( V_68 ) ;
}
V_1 = NULL ;
goto V_75;
V_82:
F_25 ( ! F_10 ( V_1 ) ) ;
F_25 ( ! ( ( V_1 -> V_43 == 0 ) ^ ( V_1 -> V_44 == 0 ) ) ) ;
if ( V_1 -> V_43 == 0 )
V_11 = 0UL ;
else if ( V_1 -> V_44 == 0 )
V_11 = 1UL ;
F_51 ( & V_1 -> V_41 ) ;
if ( V_40 ) {
F_52 ( & V_1 -> V_41 , & V_83 ) ;
V_72 [ V_81 ] . V_79 -- ;
V_32 -- ;
V_31 ++ ;
F_51 ( & V_1 -> V_42 ) ;
F_52 ( & V_1 -> V_42 , & V_84 ) ;
} else {
F_52 ( & V_1 -> V_41 , & V_85 ) ;
V_72 [ V_81 ] . V_79 -- ;
V_38 -- ;
V_37 ++ ;
F_51 ( & V_1 -> V_42 ) ;
F_52 ( & V_1 -> V_42 , & V_86 ) ;
}
F_41 ( V_1 , V_48 , V_40 , V_49 , V_11 , V_14 ) ;
V_1 -> V_45 ++ ;
F_25 ( V_1 -> V_45 == 3 ) ;
F_6 ( V_1 ) ;
F_49 ( V_68 ) ;
V_75:
return F_24 ( V_1 , V_11 ) ;
}
struct V_8 * F_55 ( struct V_47 * V_48 , bool V_40 ,
void * V_49 , unsigned V_14 ,
struct V_2 * V_87 )
{
struct V_1 * V_1 ;
unsigned long V_11 = 0 ;
unsigned V_52 ;
T_2 * V_68 =
V_40 ? & V_69 : & V_70 ;
struct V_71 * V_72 =
V_40 ? V_73 : V_74 ;
#if 0
static unsigned long counter;
budnum = counter++ & 1;
#endif
if ( V_14 > F_46 () )
return NULL ;
if ( V_87 == NULL )
return NULL ;
V_14 += sizeof( struct V_47 ) ;
V_52 = F_28 ( V_14 ) ;
F_48 ( V_68 ) ;
V_1 = F_34 ( V_87 , V_40 ) ;
F_1 ( V_1 ) ;
F_52 ( & V_1 -> V_41 , & V_72 [ V_52 ] . V_78 ) ;
if ( V_40 ) {
F_52 ( & V_1 -> V_42 , & V_84 ) ;
V_32 ++ ;
} else {
F_52 ( & V_1 -> V_42 , & V_86 ) ;
V_38 ++ ;
}
V_72 [ V_52 ] . V_79 ++ ;
F_41 ( V_1 , V_48 , V_40 , V_49 , V_11 , V_14 ) ;
V_1 -> V_45 ++ ;
F_25 ( V_1 -> V_45 == 3 ) ;
F_6 ( V_1 ) ;
F_49 ( V_68 ) ;
return F_24 ( V_1 , V_11 ) ;
}
void F_56 ( struct V_8 * V_9 , bool V_40 )
{
struct V_1 * V_1 = F_23 ( V_9 ) ;
T_2 * V_68 =
V_40 ? & V_69 : & V_70 ;
F_48 ( V_68 ) ;
F_1 ( V_1 ) ;
F_25 ( F_14 ( V_1 ) ) ;
V_1 -> V_45 -- ;
F_25 ( ( int ) V_1 -> V_45 < 0 ) ;
F_6 ( V_1 ) ;
F_49 ( V_68 ) ;
}
int F_57 ( struct V_2 * V_88 , struct V_8 * V_9 , bool V_40 ,
void (* F_58)( char * , unsigned int , char * ) )
{
struct V_1 * V_1 = F_23 ( V_9 ) ;
unsigned long V_11 = F_26 ( V_9 ) ;
void * V_7 ;
char * V_89 , * V_90 ;
unsigned V_14 ;
int V_91 = - 1 ;
T_2 * V_68 =
V_40 ? & V_69 : & V_70 ;
F_48 ( V_68 ) ;
F_1 ( V_1 ) ;
if ( F_14 ( V_1 ) ) {
goto V_75;
}
V_7 = F_12 ( V_1 ) ;
V_89 = F_13 ( V_88 ) ;
if ( V_11 == 0 )
V_14 = V_1 -> V_43 ;
else
V_14 = V_1 -> V_44 ;
F_25 ( V_14 == 0 || V_14 > F_27 () ) ;
V_90 = F_29 ( V_7 , V_11 , V_14 ) ;
V_90 += sizeof( struct V_47 ) ;
V_14 -= sizeof( struct V_47 ) ;
F_58 ( V_90 , V_14 , V_89 ) ;
F_22 ( V_89 ) ;
F_21 ( V_7 ) ;
V_91 = 0 ;
V_75:
F_6 ( V_1 ) ;
F_49 ( V_68 ) ;
return V_91 ;
}
int F_59 ( char * V_89 , struct V_8 * V_9 ,
T_3 * V_92 , bool V_40 )
{
struct V_1 * V_1 = F_23 ( V_9 ) ;
unsigned long V_11 = F_26 ( V_9 ) ;
void * V_7 ;
char * V_90 ;
unsigned V_14 ;
int V_91 = - 1 ;
T_2 * V_68 =
V_40 ? & V_69 : & V_70 ;
F_48 ( V_68 ) ;
F_1 ( V_1 ) ;
if ( F_14 ( V_1 ) ) {
goto V_75;
}
V_7 = F_12 ( V_1 ) ;
if ( V_11 == 0 )
V_14 = V_1 -> V_43 ;
else
V_14 = V_1 -> V_44 ;
F_25 ( V_14 == 0 || V_14 > F_27 () ) ;
V_90 = F_29 ( V_7 , V_11 , V_14 ) ;
V_90 += sizeof( struct V_47 ) ;
V_14 -= sizeof( struct V_47 ) ;
* V_92 = V_14 ;
memcpy ( V_89 , V_90 , V_14 ) ;
F_21 ( V_7 ) ;
V_91 = 0 ;
V_75:
F_6 ( V_1 ) ;
F_49 ( V_68 ) ;
return V_91 ;
}
int F_60 ( struct V_8 * V_9 , char * V_90 , bool V_40 )
{
struct V_1 * V_1 = F_23 ( V_9 ) ;
unsigned long V_11 = F_26 ( V_9 ) ;
void * V_7 ;
char * V_89 ;
unsigned V_14 ;
int V_91 = - 1 ;
T_2 * V_68 =
V_40 ? & V_69 : & V_70 ;
F_48 ( V_68 ) ;
F_1 ( V_1 ) ;
if ( F_14 ( V_1 ) ) {
goto V_75;
}
V_7 = F_12 ( V_1 ) ;
if ( V_11 == 0 )
V_14 = V_1 -> V_43 ;
else
V_14 = V_1 -> V_44 ;
F_25 ( V_14 == 0 || V_14 > F_27 () ) ;
V_89 = F_29 ( V_7 , V_11 , V_14 ) ;
V_89 += sizeof( struct V_47 ) ;
V_14 -= sizeof( struct V_47 ) ;
memcpy ( V_89 , V_90 , V_14 ) ;
F_21 ( V_7 ) ;
V_91 = 0 ;
V_75:
F_6 ( V_1 ) ;
F_49 ( V_68 ) ;
return V_91 ;
}
struct V_2 * F_61 ( unsigned int * V_63 , unsigned int * V_64 )
{
struct V_1 * V_1 = NULL , * V_80 ;
struct V_71 * V_72 = V_73 ;
struct V_2 * V_2 = NULL ;
bool V_93 = V_93 () ;
if ( V_93 )
F_48 ( & V_69 ) ;
else
F_62 ( & V_69 ) ;
* V_63 = 0 ;
if ( F_37 ( & V_84 ) )
goto V_94;
F_54 (zbudpage, zbudpage2, &zbud_eph_lru_list, lru) {
if ( F_2 ( ! F_8 ( V_1 ) ) )
continue;
if ( F_2 ( V_1 -> V_45 != 0 ) ) {
F_6 ( V_1 ) ;
continue;
}
goto V_95;
}
V_94:
if ( V_93 )
F_49 ( & V_69 ) ;
else
F_63 ( & V_69 ) ;
goto V_75;
V_95:
F_51 ( & V_1 -> V_41 ) ;
F_51 ( & V_1 -> V_42 ) ;
F_15 ( V_1 ) ;
if ( V_1 -> V_43 != 0 && V_1 -> V_44 != 0 ) {
* V_63 = V_1 -> V_43 + V_1 -> V_44 -
( 2 * sizeof( struct V_47 ) ) ;
* V_64 = 2 ;
} else if ( V_1 -> V_43 != 0 ) {
V_72 [ F_28 ( V_1 -> V_43 ) ] . V_79 -- ;
* V_63 = V_1 -> V_43 - sizeof( struct V_47 ) ;
* V_64 = 1 ;
} else if ( V_1 -> V_44 != 0 ) {
V_72 [ F_28 ( V_1 -> V_44 ) ] . V_79 -- ;
* V_63 = V_1 -> V_44 - sizeof( struct V_47 ) ;
* V_64 = 1 ;
} else {
F_64 () ;
}
F_49 ( & V_69 ) ;
V_28 ++ ;
if ( * V_64 == 1 )
V_32 -- ;
else
V_31 -- ;
F_42 ( V_1 ) ;
F_1 ( V_1 ) ;
F_17 ( V_1 ) ;
V_2 = F_36 ( V_1 , true ) ;
if ( ! V_93 )
F_65 () ;
V_75:
return V_2 ;
}
unsigned int F_66 ( struct V_47 * V_48 , unsigned char * * V_96 ,
unsigned int * V_63 , bool V_40 )
{
struct V_1 * V_1 = NULL , * V_97 ;
struct V_47 * V_98 ;
char * V_90 ;
void * V_7 ;
unsigned V_14 ;
int V_91 = 0 , V_58 ;
T_2 * V_68 =
V_40 ? & V_69 : & V_70 ;
struct V_99 * V_100 =
V_40 ? & V_84 : & V_86 ;
F_62 ( V_68 ) ;
if ( F_37 ( V_100 ) )
goto V_75;
F_54 (zbudpage, zbudpag2, lru_list, lru) {
if ( F_2 ( ! F_8 ( V_1 ) ) )
continue;
if ( F_2 ( V_1 -> V_45 != 0 ) ) {
F_6 ( V_1 ) ;
continue;
}
goto V_101;
}
goto V_75;
V_101:
F_51 ( & V_1 -> V_41 ) ;
F_19 ( V_1 ) ;
F_51 ( & V_1 -> V_42 ) ;
if ( V_40 ) {
F_52 ( & V_1 -> V_42 , & V_102 ) ;
V_103 =
F_67 ( & V_76 ) ;
} else {
F_52 ( & V_1 -> V_42 , & V_104 ) ;
V_39 =
F_67 ( & V_77 ) ;
}
V_7 = F_12 ( V_1 ) ;
for ( V_58 = 0 ; V_58 < 2 ; V_58 ++ ) {
V_14 = ( V_58 == 0 ) ? V_1 -> V_43 : V_1 -> V_44 ;
if ( V_14 ) {
V_90 = F_29 ( V_7 , V_58 , V_14 ) ;
V_98 = (struct V_47 * ) V_90 ;
V_90 += sizeof( struct V_47 ) ;
V_14 -= sizeof( struct V_47 ) ;
if ( V_48 != NULL )
V_48 [ V_91 ] = * V_98 ;
if ( V_96 != NULL )
memcpy ( V_96 [ V_91 ] , V_90 , V_14 ) ;
if ( V_63 != NULL )
* V_63 ++ = V_14 ;
V_91 ++ ;
}
}
F_21 ( V_7 ) ;
F_6 ( V_1 ) ;
V_75:
F_63 ( V_68 ) ;
return V_91 ;
}
void T_4 F_68 ( void )
{
int V_58 ;
#ifdef F_69
F_30 () ;
#endif
F_25 ( ( sizeof( struct V_47 ) * 2 > V_15 ) ) ;
F_25 ( sizeof( struct V_1 ) > sizeof( struct V_2 ) ) ;
for ( V_58 = 0 ; V_58 < V_105 ; V_58 ++ ) {
F_35 ( & V_73 [ V_58 ] . V_78 ) ;
F_35 ( & V_74 [ V_58 ] . V_78 ) ;
}
}
