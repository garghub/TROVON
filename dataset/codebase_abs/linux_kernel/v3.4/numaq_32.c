static inline void F_1 ( int V_1 , struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_5 + V_1 ;
T_1 V_6 = ( T_1 ) ( V_5 -> V_7 - V_5 -> V_8 ) << 20 ;
T_1 V_9 = ( T_1 ) ( V_5 -> V_7 + V_5 -> V_10 ) << 20 ;
int V_11 ;
F_2 ( V_1 , V_12 ) ;
V_11 = F_3 ( V_1 , V_6 , V_9 ) ;
F_4 ( V_11 < 0 ) ;
}
static void T_2 F_5 ( void )
{
struct V_2 * V_3 ;
int V_1 ;
V_3 = ( void * ) F_6 ( V_13 ) ;
F_7 (node) {
if ( V_3 -> V_14 & ( 1 << V_1 ) )
F_1 ( V_1 , V_3 ) ;
}
}
void T_3 F_8 ( void )
{
if ( ! V_15 )
return;
if ( F_9 () > 1 ) {
F_10 ( V_16 L_1 ) ;
F_11 ( V_17 ) ;
}
}
static void T_2 F_12 ( void )
{
F_8 () ;
}
static inline int F_13 ( int V_18 , int V_19 )
{
return ( V_18 << 4 ) + ( V_19 ? V_19 << 1 : 1 ) ;
}
static int F_14 ( struct V_20 * V_21 )
{
int V_18 = V_22 [ V_23 ] -> V_24 ;
int V_25 = F_13 ( V_18 , V_21 -> V_26 ) ;
F_10 ( V_16
L_2 ,
V_21 -> V_26 , ( V_21 -> V_27 & V_28 ) >> 8 ,
( V_21 -> V_27 & V_29 ) >> 4 ,
V_21 -> V_30 , V_18 , V_25 ) ;
return V_25 ;
}
static void F_15 ( struct V_31 * V_21 , char * V_32 )
{
int V_18 = V_22 [ V_23 ] -> V_24 ;
int V_33 = V_22 [ V_23 ] -> V_34 ;
V_35 [ V_21 -> V_36 ] = V_18 ;
V_37 [ V_21 -> V_36 ] = V_33 ;
F_10 ( V_38 L_3 , V_21 -> V_36 , V_32 , V_18 ) ;
}
static void F_16 ( struct V_31 * V_21 )
{
int V_18 = V_22 [ V_23 ] -> V_24 ;
int V_33 = V_22 [ V_23 ] -> V_34 ;
V_39 [ V_18 ] [ V_33 ] = V_21 -> V_36 ;
}
static void F_17 ( unsigned int V_40 )
{
if ( ! V_40 )
V_23 = 0 ;
else
V_23 ++ ;
}
static void T_2 F_18 ( struct V_41 * V_21 )
{
F_10 ( V_38
L_4 ,
V_23 , V_21 -> V_42 , V_21 -> V_24 , V_21 -> V_43 ,
V_21 -> V_34 ) ;
if ( V_23 >= V_44 )
F_10 ( V_45 L_5 ) ;
else
V_22 [ V_23 ] = V_21 ;
if ( V_21 -> V_24 < V_46 && ! F_19 ( V_21 -> V_24 ) )
F_20 ( V_21 -> V_24 ) ;
}
static int T_2 F_21 ( unsigned char * V_47 , int V_48 )
{
int V_49 = 0 ;
while ( V_48 -- )
V_49 += * V_47 ++ ;
return V_49 & 0xFF ;
}
static void T_2 F_22 ( struct V_50 * V_51 )
{
struct V_52 * V_53 = ( void * ) ( long ) V_51 -> V_54 ;
int V_55 = sizeof( * V_53 ) ;
unsigned char * V_54 = ( ( unsigned char * ) V_53 ) + V_55 ;
V_23 = 0 ;
F_10 ( V_38
L_6 , V_53 ) ;
if ( memcmp ( V_53 -> V_56 , V_57 , 4 ) ) {
F_10 ( V_58
L_7 ,
V_53 -> V_56 [ 0 ] , V_53 -> V_56 [ 1 ] ,
V_53 -> V_56 [ 2 ] , V_53 -> V_56 [ 3 ] ) ;
return;
}
if ( F_21 ( ( unsigned char * ) V_53 , V_53 -> V_59 ) ) {
F_10 ( V_58 L_8 ) ;
return;
}
while ( V_55 < V_53 -> V_59 ) {
switch ( * V_54 ) {
case V_60 :
{
struct V_41 * V_21 = ( void * ) V_54 ;
F_18 ( V_21 ) ;
V_54 += sizeof( * V_21 ) ;
V_55 += sizeof( * V_21 ) ;
++ V_23 ;
break;
}
default:
F_10 ( V_58
L_9 ,
( int ) * V_54 ) ;
return;
}
}
}
static T_2 void F_23 ( void )
{
if ( V_61 )
F_24 () ;
if ( V_15 ) {
V_62 . V_63 . V_23 = F_17 ;
V_62 . V_63 . V_64 = V_65 ;
V_62 . V_63 . F_14 = F_14 ;
V_62 . V_63 . F_22 = F_22 ;
V_62 . V_63 . F_16 = F_16 ;
V_62 . V_63 . F_15 = F_15 ;
V_62 . V_66 . V_67 = F_12 ;
V_62 . V_68 . V_69 = V_70 ;
}
}
int T_2 F_25 ( void )
{
F_23 () ;
if ( ! V_15 )
return - V_71 ;
F_5 () ;
return 0 ;
}
static inline unsigned int F_26 ( unsigned long V_72 )
{
return ( V_72 >> 24 ) & 0x0F ;
}
static inline void F_27 ( const struct V_73 * V_74 , int V_75 )
{
F_28 ( V_74 , V_75 ) ;
}
static inline void F_29 ( int V_75 )
{
F_30 ( V_76 , V_75 ) ;
}
static inline void F_31 ( int V_75 )
{
F_27 ( V_76 , V_75 ) ;
}
static inline void F_32 ( void )
{
F_33 () ;
}
static inline const struct V_73 * F_34 ( void )
{
return V_77 ;
}
static unsigned long F_35 ( T_4 * V_78 , int V_26 )
{
return F_36 ( V_26 , * V_78 ) ;
}
static inline unsigned long F_37 ( int V_79 )
{
return F_36 ( V_79 , V_80 ) ;
}
static inline int F_38 ( void )
{
return 1 ;
}
static inline void F_39 ( void )
{
}
static inline void F_40 ( void )
{
F_10 ( V_38
L_10 ,
V_81 ) ;
}
static inline int F_41 ( int V_82 , int V_83 )
{
return V_82 != 0 && V_83 == 0 ;
}
static inline void F_42 ( T_4 * V_84 , T_4 * V_85 )
{
return F_43 ( 0xFUL , V_85 ) ;
}
static inline int F_44 ( int V_86 )
{
if ( V_86 < 60 )
return ( ( V_86 >> 2 ) << 4 ) | ( 1 << ( V_86 & 0x3 ) ) ;
else
return V_87 ;
}
static inline int F_45 ( int V_25 )
{
return V_25 >> 4 ;
}
static int F_46 ( int V_88 )
{
int V_25 = F_47 ( V_89 , V_88 ) ;
if ( V_25 != V_87 )
return F_45 ( V_25 ) ;
return V_90 ;
}
static void F_48 ( int V_25 , T_4 * V_85 )
{
int V_1 = F_45 ( V_25 ) ;
int V_88 = F_49 ( V_25 & 0xf ) ;
F_50 ( V_88 + 4 * V_1 , V_85 ) ;
}
static inline int F_51 ( int V_19 )
{
return 1 ;
}
static unsigned int F_52 ( const struct V_73 * V_73 )
{
return 0x0F ;
}
static inline unsigned int
F_53 ( const struct V_73 * V_73 ,
const struct V_73 * V_91 )
{
return 0x0F ;
}
static inline int F_54 ( int V_92 , int V_93 )
{
return V_92 >> V_93 ;
}
static int
F_55 ( struct V_50 * V_51 , char * V_94 , char * V_95 )
{
if ( strncmp ( V_94 , L_11 , 8 ) )
F_10 ( V_45 L_12 ) ;
else
V_15 = 1 ;
return V_15 ;
}
static int F_56 ( void )
{
return V_15 ;
}
static void F_57 ( int V_88 , struct V_73 * V_96 )
{
F_58 ( V_96 ) ;
F_59 ( V_96 ) [ 0 ] = V_97 ;
}
static void F_60 ( void )
{
int V_98 = F_9 () ;
if ( V_98 <= 1 )
return;
F_10 ( V_38
L_13 , V_98 ) ;
V_99 = F_61 ( V_100 , V_98 * V_101 ) ;
F_10 ( V_38
L_14 ,
( V_102 ) V_99 , ( V_102 ) V_98 * V_101 ) ;
}
