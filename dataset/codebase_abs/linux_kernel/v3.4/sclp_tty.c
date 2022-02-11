static int
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
V_5 = V_2 ;
V_2 -> V_6 = NULL ;
V_2 -> V_7 = 0 ;
return 0 ;
}
static void
F_2 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( V_2 -> V_8 > 1 )
return;
V_5 = NULL ;
}
static int
F_3 ( struct V_1 * V_2 )
{
unsigned long V_9 ;
struct V_10 * V_11 ;
int V_8 ;
F_4 ( & V_12 , V_9 ) ;
V_8 = 0 ;
if ( V_13 != NULL )
V_8 = F_5 ( V_13 ) / sizeof( struct V_14 ) ;
F_6 (l, &sclp_tty_pages)
V_8 += V_15 ;
F_7 ( & V_12 , V_9 ) ;
return V_8 ;
}
static void
F_8 ( struct V_16 * V_17 , int V_18 )
{
unsigned long V_9 ;
void * V_19 ;
do {
V_19 = F_9 ( V_17 ) ;
F_4 ( & V_12 , V_9 ) ;
F_10 ( & V_17 -> V_20 ) ;
V_21 -- ;
F_11 ( (struct V_10 * ) V_19 , & V_22 ) ;
V_17 = NULL ;
if ( ! F_12 ( & V_23 ) )
V_17 = F_13 ( V_23 . V_24 ,
struct V_16 , V_20 ) ;
F_7 ( & V_12 , V_9 ) ;
} while ( V_17 && F_14 ( V_17 , F_8 ) );
if ( V_5 != NULL ) {
F_15 ( V_5 ) ;
}
}
static inline void
F_16 ( struct V_16 * V_17 )
{
unsigned long V_9 ;
int V_8 ;
int V_18 ;
F_4 ( & V_12 , V_9 ) ;
F_11 ( & V_17 -> V_20 , & V_23 ) ;
V_8 = V_21 ++ ;
F_7 ( & V_12 , V_9 ) ;
if ( V_8 )
return;
V_18 = F_14 ( V_17 , F_8 ) ;
if ( V_18 )
F_8 ( V_17 , V_18 ) ;
}
static void
F_17 ( unsigned long V_25 )
{
unsigned long V_9 ;
struct V_16 * V_26 ;
F_4 ( & V_12 , V_9 ) ;
V_26 = V_13 ;
V_13 = NULL ;
F_7 ( & V_12 , V_9 ) ;
if ( V_26 != NULL ) {
F_16 ( V_26 ) ;
}
}
static int F_18 ( const unsigned char * V_27 , int V_8 , int V_28 )
{
unsigned long V_9 ;
void * V_19 ;
int V_29 ;
int V_30 ;
struct V_16 * V_26 ;
if ( V_8 <= 0 )
return 0 ;
V_30 = 0 ;
F_4 ( & V_12 , V_9 ) ;
do {
if ( V_13 == NULL ) {
while ( F_12 ( & V_22 ) ) {
F_7 ( & V_12 , V_9 ) ;
if ( V_28 )
goto V_31;
else
F_19 () ;
F_4 ( & V_12 , V_9 ) ;
}
V_19 = V_22 . V_24 ;
F_10 ( (struct V_10 * ) V_19 ) ;
V_13 = F_20 ( V_19 , V_32 ,
V_33 ) ;
}
V_29 = F_21 ( V_13 , V_27 , V_8 ) ;
V_30 += V_29 ;
if ( V_29 == V_8 )
break;
V_26 = V_13 ;
V_13 = NULL ;
F_7 ( & V_12 , V_9 ) ;
F_16 ( V_26 ) ;
F_4 ( & V_12 , V_9 ) ;
V_27 += V_29 ;
V_8 -= V_29 ;
} while ( V_8 > 0 );
if ( V_13 && F_22 ( V_13 ) &&
! F_23 ( & V_34 ) ) {
F_24 ( & V_34 ) ;
V_34 . V_35 = F_17 ;
V_34 . V_25 = 0UL ;
V_34 . V_36 = V_37 + V_38 / 10 ;
F_25 ( & V_34 ) ;
}
F_7 ( & V_12 , V_9 ) ;
V_31:
return V_30 ;
}
static int
F_26 ( struct V_1 * V_2 , const unsigned char * V_26 , int V_8 )
{
if ( V_39 > 0 ) {
F_18 ( V_40 , V_39 , 0 ) ;
V_39 = 0 ;
}
return F_18 ( V_26 , V_8 , 1 ) ;
}
static int
F_27 ( struct V_1 * V_2 , unsigned char V_41 )
{
V_40 [ V_39 ++ ] = V_41 ;
if ( V_41 == '\n' || V_39 >= V_42 ) {
F_18 ( V_40 , V_39 , 0 ) ;
V_39 = 0 ;
}
return 1 ;
}
static void
F_28 ( struct V_1 * V_2 )
{
if ( V_39 > 0 ) {
F_18 ( V_40 , V_39 , 0 ) ;
V_39 = 0 ;
}
}
static int
F_29 ( struct V_1 * V_2 )
{
unsigned long V_9 ;
struct V_10 * V_11 ;
struct V_16 * V_43 ;
int V_8 ;
F_4 ( & V_12 , V_9 ) ;
V_8 = 0 ;
if ( V_13 != NULL )
V_8 = F_22 ( V_13 ) ;
F_6 (l, &sclp_tty_outqueue) {
V_43 = F_13 ( V_11 , struct V_16 , V_20 ) ;
V_8 += F_22 ( V_43 ) ;
}
F_7 ( & V_12 , V_9 ) ;
return V_8 ;
}
static void
F_30 ( struct V_1 * V_2 )
{
if ( V_39 > 0 ) {
F_18 ( V_40 , V_39 , 0 ) ;
V_39 = 0 ;
}
}
static void
F_31 ( unsigned char * V_26 , unsigned int V_8 )
{
unsigned int V_44 ;
if ( V_5 == NULL )
return;
V_44 = F_32 ( V_26 , V_8 , V_5 ) ;
switch ( V_44 & V_45 ) {
case V_46 :
break;
case V_47 :
F_33 ( V_5 , V_44 , V_48 ) ;
F_34 ( V_5 ) ;
break;
case V_49 :
if ( V_8 < 2 ||
( strncmp ( ( const char * ) V_26 + V_8 - 2 , L_1 , 2 ) &&
strncmp ( ( const char * ) V_26 + V_8 - 2 , L_2 , 2 ) ) ) {
F_35 ( V_5 , V_26 , V_8 ) ;
F_33 ( V_5 , '\n' , V_48 ) ;
} else
F_35 ( V_5 , V_26 , V_8 - 2 ) ;
F_34 ( V_5 ) ;
break;
}
}
static int F_36 ( unsigned char * V_26 , int V_8 )
{
unsigned char * V_50 , * V_51 ;
int V_52 ;
V_52 = 0 ;
V_50 = V_51 = V_26 ;
while ( V_8 -- > 0 ) {
if ( * V_50 == V_53 ) {
if ( V_8 && V_50 [ 1 ] == V_53 ) {
* V_51 ++ = * V_50 ++ ;
V_8 -- ;
} else
V_52 = ~ V_52 ;
V_50 ++ ;
} else
if ( V_52 )
if ( V_54 )
* V_51 ++ = V_55 [ ( int ) * V_50 ++ ] ;
else
* V_51 ++ = V_56 [ ( int ) * V_50 ++ ] ;
else
* V_51 ++ = * V_50 ++ ;
}
return V_51 - V_26 ;
}
static void F_37 ( struct V_57 * V_58 )
{
unsigned char * V_27 ;
int V_8 ;
V_27 = ( unsigned char * ) ( V_58 + 1 ) ;
V_8 = V_58 -> V_59 - sizeof( * V_58 ) ;
if ( V_54 )
F_38 ( V_27 , V_8 ) ;
V_8 = F_36 ( V_27 , V_8 ) ;
F_39 ( V_27 , V_8 ) ;
F_31 ( V_27 , V_8 ) ;
}
static inline void F_40 ( struct V_57 * V_58 )
{
void * V_60 ;
V_60 = ( void * ) V_58 + V_58 -> V_59 ;
for ( V_58 = V_58 + 1 ; ( void * ) V_58 < V_60 ; V_58 = ( void * ) V_58 + V_58 -> V_59 )
if ( V_58 -> V_61 == 0x30 )
F_37 ( V_58 ) ;
}
static inline void F_41 ( struct V_62 * V_63 )
{
struct V_57 * V_58 ;
void * V_60 ;
V_60 = ( void * ) V_63 + V_63 -> V_59 ;
for ( V_58 = (struct V_57 * ) ( V_63 + 1 ) ;
( void * ) V_58 < V_60 ; V_58 = ( void * ) V_58 + V_58 -> V_59 )
if ( V_58 -> V_61 == V_64 )
F_40 ( V_58 ) ;
}
static inline void F_42 ( struct V_62 * V_63 )
{
void * V_60 ;
V_60 = ( void * ) V_63 + V_63 -> V_59 ;
for ( V_63 = V_63 + 1 ; ( void * ) V_63 < V_60 ; V_63 = ( void * ) V_63 + V_63 -> V_59 )
if ( V_63 -> V_65 == V_66 )
F_41 ( V_63 ) ;
}
static inline void F_43 ( struct V_62 * V_63 )
{
V_63 = F_44 ( V_63 + 1 , ( void * ) V_63 + V_63 -> V_59 , V_67 ) ;
if ( V_63 )
F_42 ( V_63 ) ;
}
static void F_45 ( struct V_68 * V_69 )
{
struct V_62 * V_63 ;
V_63 = F_44 ( V_69 + 1 , ( void * ) V_69 + V_69 -> V_59 ,
V_70 ) ;
if ( V_63 )
F_43 ( V_63 ) ;
}
static void
F_46 ( struct V_71 * V_72 )
{
}
static int T_1
F_47 ( void )
{
struct V_73 * V_74 ;
void * V_19 ;
int V_75 ;
int V_18 ;
if ( ! V_76 )
return 0 ;
V_74 = F_48 ( 1 ) ;
if ( ! V_74 )
return - V_77 ;
V_18 = F_49 () ;
if ( V_18 ) {
F_50 ( V_74 ) ;
return V_18 ;
}
F_51 ( & V_22 ) ;
for ( V_75 = 0 ; V_75 < V_78 ; V_75 ++ ) {
V_19 = ( void * ) F_52 ( V_79 | V_80 ) ;
if ( V_19 == NULL ) {
F_50 ( V_74 ) ;
return - V_77 ;
}
F_11 ( (struct V_10 * ) V_19 , & V_22 ) ;
}
F_51 ( & V_23 ) ;
F_53 ( & V_12 ) ;
F_24 ( & V_34 ) ;
V_13 = NULL ;
V_21 = 0 ;
if ( V_81 ) {
V_32 = 76 ;
V_54 = 1 ;
}
V_39 = 0 ;
V_5 = NULL ;
V_18 = V_71 ( & V_82 ) ;
if ( V_18 ) {
F_50 ( V_74 ) ;
return V_18 ;
}
V_74 -> V_83 = L_3 ;
V_74 -> V_84 = L_3 ;
V_74 -> V_85 = V_86 ;
V_74 -> V_87 = 64 ;
V_74 -> type = V_88 ;
V_74 -> V_89 = V_90 ;
V_74 -> V_91 = V_92 ;
V_74 -> V_91 . V_93 = V_94 | V_95 ;
V_74 -> V_91 . V_96 = V_97 | V_98 ;
V_74 -> V_91 . V_99 = V_100 | V_101 ;
V_74 -> V_9 = V_102 ;
F_54 ( V_74 , & V_103 ) ;
V_18 = F_55 ( V_74 ) ;
if ( V_18 ) {
F_50 ( V_74 ) ;
return V_18 ;
}
V_104 = V_74 ;
return 0 ;
}
