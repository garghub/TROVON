static void
F_1 ( struct V_1 * V_2 , const char * V_3 )
{
T_1 V_4 ;
F_2 ( L_1 , V_3 ) ;
for ( V_4 = 0 ; V_4 < V_2 -> V_5 ; V_4 ++ )
F_2 ( L_2 , V_4 , ( ( ( char * ) V_2 -> V_6 ) [ V_4 ] ) & 0xff ) ;
}
static inline int
F_3 ( struct V_1 * V_2 , void * V_7 , T_1 V_8 )
{
void * V_9 ;
T_1 V_10 = V_2 -> V_11 ;
V_12:
if ( ( V_2 -> V_5 + V_8 ) < V_10 ) {
memcpy ( V_2 -> V_6 + V_2 -> V_5 , V_7 , V_8 ) ;
V_2 -> V_5 += V_8 ;
return 0 ;
}
if ( ! V_10 )
V_10 = V_13 ;
else
V_10 <<= 1 ;
V_9 = realloc ( V_2 -> V_6 , V_10 ) ;
if ( ! V_9 )
return - 1 ;
V_2 -> V_6 = V_9 ;
V_2 -> V_11 = V_10 ;
goto V_12;
}
static void
F_4 ( struct V_1 * V_2 )
{
V_2 -> V_6 = NULL ;
V_2 -> V_5 = 0 ;
V_2 -> V_11 = 0 ;
}
static inline T_1
F_5 ( struct V_1 * V_2 )
{
return V_2 -> V_5 ;
}
static inline void *
F_6 ( struct V_1 * V_2 )
{
return V_2 -> V_6 ;
}
static void F_7 ( struct V_1 * V_2 , T_2 V_6 )
{
F_3 ( V_2 , & V_6 , sizeof( T_2 ) ) ;
}
static void F_8 ( struct V_1 * V_2 , const char * V_14 )
{
F_3 ( V_2 , ( void * ) V_14 , strlen ( V_14 ) + 1 ) ;
}
static void F_9 ( struct V_1 * V_2 ,
unsigned long V_6 )
{
do {
T_3 V_15 = V_6 & 0x7F ;
V_6 >>= 7 ;
if ( V_6 )
V_15 |= 0x80 ;
F_3 ( V_2 , & V_15 , 1 ) ;
} while ( V_6 );
}
static void F_10 ( struct V_1 * V_2 , long V_6 )
{
int V_16 = 1 ;
int V_17 = V_6 < 0 ;
int V_18 = sizeof( long ) * V_19 ;
while ( V_16 ) {
T_3 V_15 = V_6 & 0x7F ;
V_6 >>= 7 ;
if ( V_17 )
V_6 |= - ( 1 << ( V_18 - 7 ) ) ;
if ( ( V_6 == 0 && ! ( V_15 & 0x40 ) ) ||
( V_6 == - 1l && ( V_15 & 0x40 ) ) )
V_16 = 0 ;
else
V_15 |= 0x80 ;
F_3 ( V_2 , & V_15 , 1 ) ;
}
}
static void F_11 ( struct V_1 * V_2 , T_3 V_20 ,
void * V_6 , T_1 V_21 )
{
F_3 ( V_2 , ( char * ) L_3 , 1 ) ;
F_9 ( V_2 , V_21 + 1 ) ;
F_3 ( V_2 , & V_20 , 1 ) ;
F_3 ( V_2 , V_6 , V_21 ) ;
}
static void F_12 ( struct V_1 * V_2 , T_3 V_20 )
{
F_3 ( V_2 , & V_20 , 1 ) ;
}
static void F_13 ( struct V_1 * V_2 ,
T_3 V_20 , long V_6 )
{
F_3 ( V_2 , & V_20 , 1 ) ;
F_10 ( V_2 , V_6 ) ;
}
static void F_14 ( struct V_1 * V_2 , T_3 V_20 ,
unsigned long V_6 )
{
F_3 ( V_2 , & V_20 , 1 ) ;
F_9 ( V_2 , V_6 ) ;
}
static void F_15 ( struct V_1 * V_2 , unsigned long V_22 )
{
F_14 ( V_2 , V_23 , V_22 ) ;
}
static void F_16 ( struct V_1 * V_2 , long V_24 )
{
F_13 ( V_2 , V_25 , V_24 ) ;
}
static void F_17 ( struct V_1 * V_2 )
{
F_11 ( V_2 , V_26 , NULL , 0 ) ;
}
static void F_18 ( struct V_1 * V_2 , unsigned long V_27 )
{
F_14 ( V_2 , V_28 , V_27 ) ;
}
static void F_19 ( struct V_1 * V_2 ,
const char * V_29 )
{
F_3 ( V_2 , ( void * ) L_3 , 1 ) ;
F_9 ( V_2 , strlen ( V_29 ) + 5 ) ;
F_12 ( V_2 , V_30 ) ;
F_8 ( V_2 , V_29 ) ;
F_9 ( V_2 , 0 ) ;
F_9 ( V_2 , 0 ) ;
F_9 ( V_2 , 0 ) ;
}
static void F_20 ( struct V_1 * V_2 ,
void * V_31 )
{
F_11 ( V_2 , V_32 , & V_31 , sizeof( unsigned long ) ) ;
}
static T_3 F_21 ( struct V_33 * V_34 ,
unsigned int V_35 ,
unsigned long V_36 )
{
unsigned int V_37 ;
unsigned long V_38 ;
V_37 = ( V_34 -> V_39 - V_35 ) - V_40 . V_41 ;
if ( V_37 >= V_40 . V_42 )
return 0 ;
V_38 = ( V_34 -> V_7 - V_36 ) / V_40 . V_43 ;
if ( V_38 <= 256 / V_40 . V_42 ) {
unsigned long V_20 = V_37 +
( V_38 * V_40 . V_42 ) +
V_40 . V_44 ;
return V_20 <= 255 ? V_20 : 0 ;
}
return 0 ;
}
static void F_22 ( struct V_1 * V_2 ,
struct V_33 * V_34 , T_1 V_45 ,
unsigned long V_46 )
{
T_1 V_4 ;
unsigned long V_36 = V_46 ;
char const * V_47 = NULL ;
unsigned long V_48 = 0 ;
int V_35 = 1 ;
F_20 ( V_2 , ( void * ) V_46 ) ;
for ( V_4 = 0 ; V_4 < V_45 ; V_4 ++ , V_34 = F_23 ( V_34 ) ) {
int V_49 = 0 ;
T_3 V_50 ;
if ( ! V_47 || strcmp ( V_47 , V_34 -> V_51 ) ) {
F_19 ( V_2 , V_34 -> V_51 ) ;
V_47 = V_34 -> V_51 ;
F_18 ( V_2 , ++ V_48 ) ;
V_49 = 1 ;
}
V_50 = F_21 ( V_34 , V_35 , V_36 ) ;
if ( V_50 != 0 ) {
V_35 = V_34 -> V_39 ;
V_36 = V_34 -> V_7 ;
F_12 ( V_2 , V_50 ) ;
} else {
if ( V_35 != V_34 -> V_39 ) {
F_16 ( V_2 , V_34 -> V_39 - V_35 ) ;
V_35 = V_34 -> V_39 ;
V_49 = 1 ;
}
if ( V_36 != V_34 -> V_7 ) {
F_15 ( V_2 , V_34 -> V_7 - V_36 ) ;
V_36 = V_34 -> V_7 ;
V_49 = 1 ;
}
if ( V_49 )
F_12 ( V_2 , V_52 ) ;
}
}
}
static void F_24 ( struct V_1 * V_2 ,
struct V_33 * V_34 , T_1 V_45 ,
unsigned long V_46 )
{
struct V_53 * V_54 ;
T_1 V_55 ;
V_55 = F_5 ( V_2 ) ;
F_3 ( V_2 , ( void * ) & V_40 ,
sizeof( V_40 ) ) ;
F_3 ( V_2 , & V_56 , sizeof( V_56 ) ) ;
F_3 ( V_2 , ( void * ) L_3 , 1 ) ;
F_3 ( V_2 , ( void * ) L_3 , 1 ) ;
V_54 = F_6 ( V_2 ) + V_55 ;
V_54 -> V_57 = ( F_5 ( V_2 ) - V_55 ) -
F_25 ( struct V_53 , V_43 ) ;
F_22 ( V_2 , V_34 , V_45 , V_46 ) ;
F_17 ( V_2 ) ;
V_54 = F_6 ( V_2 ) + V_55 ;
V_54 -> V_58 = ( F_5 ( V_2 ) - V_55 ) -
F_25 ( struct V_53 , V_59 ) ;
}
static void
F_26 ( struct V_1 * V_2 )
{
F_9 ( V_2 , 1 ) ;
F_9 ( V_2 , V_60 ) ;
F_9 ( V_2 , V_61 ) ;
F_9 ( V_2 , V_62 ) ;
F_9 ( V_2 , V_63 ) ;
F_9 ( V_2 , 0 ) ;
F_9 ( V_2 , 0 ) ;
F_9 ( V_2 , 0 ) ;
}
static void
F_27 ( struct V_1 * V_2 ,
T_1 V_64 )
{
struct V_65 * V_66 ;
T_1 V_55 = F_5 ( V_2 ) ;
F_3 ( V_2 , & V_67 ,
sizeof( V_67 ) ) ;
F_9 ( V_2 , 1 ) ;
F_7 ( V_2 , V_64 ) ;
V_66 = F_6 ( V_2 ) + V_55 ;
V_66 -> V_58 = ( F_5 ( V_2 ) - V_55 ) -
F_25 ( struct V_65 , V_59 ) ;
}
static int
F_28 ( T_4 V_46 ,
void * V_68 , int V_69 ,
struct V_1 * V_70 ,
struct V_1 * V_71 ,
struct V_1 * V_72 )
{
struct V_33 * V_34 = V_68 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_69 ; V_4 ++ ) {
V_34 -> V_7 = V_34 -> V_7 - V_46 ;
V_34 = F_23 ( V_34 ) ;
}
F_27 ( V_72 , F_5 ( V_70 ) ) ;
F_24 ( V_70 , V_68 , V_69 , 0 ) ;
F_26 ( V_71 ) ;
if ( 0 ) F_1 ( V_71 , L_4 ) ;
return 0 ;
}
int
F_29 ( T_5 * V_73 , T_4 V_46 , void * V_68 , int V_69 )
{
T_6 * V_74 ;
T_7 * V_75 ;
T_8 * V_76 ;
struct V_1 V_70 , V_72 , V_71 ;
int V_77 ;
F_4 ( & V_70 ) ;
F_4 ( & V_72 ) ;
F_4 ( & V_71 ) ;
V_77 = F_28 ( V_46 , V_68 , V_69 , & V_70 , & V_71 , & V_72 ) ;
if ( V_77 )
return - 1 ;
V_75 = F_30 ( V_73 ) ;
if ( ! V_75 ) {
F_2 ( L_5 ) ;
return - 1 ;
}
V_74 = F_31 ( V_75 ) ;
if ( ! V_74 ) {
F_2 ( L_6 ) ;
return - 1 ;
}
V_74 -> V_78 = 1 ;
V_74 -> V_79 = 0LL ;
V_74 -> V_80 = F_6 ( & V_70 ) ;
V_74 -> V_81 = V_82 ;
V_74 -> V_83 = F_5 ( & V_70 ) ;
V_74 -> V_84 = V_85 ;
V_76 = F_32 ( V_75 ) ;
if ( ! V_76 ) {
F_2 ( L_7 ) ;
return - 1 ;
}
V_76 -> V_86 = 52 ;
V_76 -> V_87 = V_88 ;
V_76 -> V_89 = 0 ;
V_76 -> V_90 = 0 ;
V_76 -> V_91 = 0 ;
V_75 = F_30 ( V_73 ) ;
if ( ! V_75 ) {
F_2 ( L_5 ) ;
return - 1 ;
}
V_74 = F_31 ( V_75 ) ;
if ( ! V_74 ) {
F_2 ( L_6 ) ;
return - 1 ;
}
V_74 -> V_78 = 1 ;
V_74 -> V_79 = 0LL ;
V_74 -> V_80 = F_6 ( & V_72 ) ;
V_74 -> V_81 = V_82 ;
V_74 -> V_83 = F_5 ( & V_72 ) ;
V_74 -> V_84 = V_85 ;
V_76 = F_32 ( V_75 ) ;
if ( ! V_76 ) {
F_2 ( L_7 ) ;
return - 1 ;
}
V_76 -> V_86 = 64 ;
V_76 -> V_87 = V_88 ;
V_76 -> V_89 = 0 ;
V_76 -> V_90 = 0 ;
V_76 -> V_91 = 0 ;
V_75 = F_30 ( V_73 ) ;
if ( ! V_75 ) {
F_2 ( L_5 ) ;
return - 1 ;
}
V_74 = F_31 ( V_75 ) ;
if ( ! V_74 ) {
F_2 ( L_6 ) ;
return - 1 ;
}
V_74 -> V_78 = 1 ;
V_74 -> V_79 = 0LL ;
V_74 -> V_80 = F_6 ( & V_71 ) ;
V_74 -> V_81 = V_82 ;
V_74 -> V_83 = F_5 ( & V_71 ) ;
V_74 -> V_84 = V_85 ;
V_76 = F_32 ( V_75 ) ;
if ( ! V_76 ) {
F_2 ( L_7 ) ;
return - 1 ;
}
V_76 -> V_86 = 76 ;
V_76 -> V_87 = V_88 ;
V_76 -> V_89 = 0 ;
V_76 -> V_90 = 0 ;
V_76 -> V_91 = 0 ;
if ( F_33 ( V_73 , V_92 ) < 0 ) {
F_2 ( L_8 ) ;
return - 1 ;
}
return 0 ;
}
