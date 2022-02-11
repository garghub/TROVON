static int T_1
F_1 ( char * V_1 )
{
V_2 = V_1 ;
return 1 ;
}
int T_1
F_2 ( void )
{
int V_3 ;
F_3 ( V_4 L_1 , V_5 ) ;
V_3 = F_4 () ;
if ( V_3 == 0 ) F_5 ( & V_6 ) ;
return V_3 ;
}
static inline int
F_6 ( char * V_7 , unsigned char * V_8 )
{
return F_7 ( F_8 ( V_7 ) , F_8 ( V_8 ) , 0 , 0 , V_9 ) ;
}
static inline int
F_9 ( int V_10 )
{
F_10 ( V_11 , V_10 ) ;
return 0 ;
}
static inline int
F_11 ( int V_12 , int V_10 , unsigned int V_13 )
{
return F_7 ( V_12 , V_13 , 0 , 0 , V_14 ) ;
}
static inline int
F_12 ( int V_12 )
{
return F_7 ( V_12 , 0 , 0 , 0 , V_15 ) ;
}
static inline int
F_13 ( int V_12 , unsigned char * V_16 , unsigned int V_17 )
{
return F_7 ( V_12 , F_8 ( V_16 ) , V_17 , 0 , V_18 ) ;
}
static inline int
F_14 ( int V_12 , unsigned char * V_16 , unsigned int V_17 )
{
return F_7 ( V_12 , F_8 ( V_16 ) , V_17 , 0 , V_19 ) ;
}
static int
F_4 ( void )
{
unsigned char V_20 [ V_21 ] ;
struct V_22 * V_23 ;
struct V_24 * V_25 ;
int V_12 , V_26 , V_27 , V_28 ;
if ( F_15 ( 0 , & V_29 ) )
return - V_30 ;
V_12 = F_6 ( V_2 , V_20 ) ;
if ( V_12 == - 1 )
return - V_30 ;
V_25 = F_16 ( sizeof( struct V_22 ) ) ;
if ( ! V_25 )
return - V_31 ;
memcpy ( V_25 -> V_32 , V_20 , sizeof( V_20 ) ) ;
V_23 = F_17 ( V_25 ) ;
V_23 -> V_33 = V_12 ;
V_25 -> V_34 = & V_35 ;
V_27 = F_18 ( V_25 ) ;
if ( V_27 ) {
F_19 ( V_25 ) ;
return V_27 ;
}
if ( ( V_28 = F_20 ( V_36 ) ) < 0 )
F_21 ( L_2 , V_37 ) ;
V_25 -> V_10 = V_28 ;
F_9 ( V_25 -> V_10 ) ;
F_3 ( V_4 L_3 ,
V_25 -> V_7 , V_2 , V_23 -> V_33 ) ;
for( V_26 = 0 ; V_26 < V_21 ; V_26 ++ ) {
F_3 ( L_4 , V_25 -> V_32 [ V_26 ] ) ;
}
F_3 ( L_5 , V_25 -> V_10 ) ;
return 0 ;
}
static int
F_22 ( struct V_24 * V_25 )
{
if ( F_23 ( V_25 -> V_10 , V_38 , 0 , L_6 , V_25 ) ) {
F_3 ( V_39 L_7 , V_25 -> V_10 ) ;
return - V_40 ;
}
F_24 ( V_25 ) ;
return 0 ;
}
static T_2 int F_25 ( struct V_24 * V_25 )
{
return ( V_25 -> type == V_41 && strncmp ( V_25 -> V_7 , L_8 , 5 ) ) ;
}
static int
F_26 ( struct V_42 * V_43 , unsigned long V_44 , void * V_45 )
{
struct V_24 * V_25 = V_45 ;
struct V_22 * V_23 ;
struct V_46 * V_47 ;
struct V_48 * * V_49 = NULL ;
struct V_48 * V_50 = NULL ;
int V_3 ;
if ( ! V_25 ) {
F_3 ( V_39 L_9 ) ;
return V_51 ;
}
if ( F_27 ( V_25 ) != & V_52 )
return V_51 ;
if ( V_44 != V_53 && V_44 != V_54 ) return V_51 ;
if ( ! F_25 ( V_25 ) ) return V_51 ;
if ( ( V_47 = V_25 -> V_55 ) != NULL ) {
for ( V_49 = & V_47 -> V_56 ; ( V_50 = * V_49 ) != NULL ; V_49 = & V_50 -> V_57 )
if ( strcmp ( V_25 -> V_7 , V_50 -> V_58 ) == 0 ) break;
}
if ( V_50 == NULL ) {
F_3 ( V_59 L_10 , V_25 -> V_7 ) ;
return V_51 ;
}
F_3 ( V_4 L_11 ,
V_25 -> V_7 , F_28 ( V_50 -> V_60 ) ) ;
V_23 = F_17 ( V_25 ) ;
V_3 = V_44 == V_53 ?
F_11 ( V_23 -> V_33 , V_25 -> V_10 , F_28 ( V_50 -> V_60 ) ) :
F_12 ( V_23 -> V_33 ) ;
F_3 ( V_4 L_12 ,
V_44 == V_53 ? L_13 : L_14 , V_3 ) ;
return V_51 ;
}
static int
F_29 ( struct V_24 * V_25 )
{
F_30 ( V_25 ) ;
F_31 ( V_25 -> V_10 , V_25 ) ;
return 0 ;
}
static void
F_32 ( unsigned char * V_61 , unsigned char * V_62 , int V_17 )
{
int V_26 ;
F_3 ( L_15 , V_61 , V_17 , V_62 [ 0 ] & 0xff ) ;
for( V_26 = 1 ; V_26 < 6 ; V_26 ++ ) {
F_3 ( L_16 , V_62 [ V_26 ] & 0xff ) ;
}
F_3 ( L_17 , V_62 [ 6 ] & 0xff ) ;
for( V_26 = 7 ; V_26 < 12 ; V_26 ++ ) {
F_3 ( L_16 , V_62 [ V_26 ] & 0xff ) ;
}
F_3 ( L_18 , V_62 [ 12 ] , V_62 [ 13 ] ) ;
for( V_26 = 14 ; V_26 < V_17 ; V_26 ++ ) {
F_3 ( L_19 , V_62 [ V_26 ] & 0xff ) ;
if ( ( V_26 % 10 ) == 0 ) F_3 ( L_20 ) ;
}
F_3 ( L_20 ) ;
}
static int
F_33 ( struct V_63 * V_64 , struct V_24 * V_25 )
{
struct V_22 * V_23 = F_17 ( V_25 ) ;
#if 0
unsigned int length = ETH_ZLEN < skb->len ? skb->len : ETH_ZLEN;
#else
unsigned int V_65 = V_64 -> V_17 ;
#endif
V_23 -> V_66 . V_67 += V_64 -> V_17 ;
V_23 -> V_66 . V_68 ++ ;
if ( V_69 > 5 ) F_32 ( L_21 , V_64 -> V_70 , V_65 ) ;
F_13 ( V_23 -> V_33 , V_64 -> V_70 , V_65 ) ;
F_34 ( V_64 ) ;
return V_71 ;
}
static inline struct V_63 *
F_35 ( struct V_24 * V_25 )
{
struct V_63 * V_72 ;
V_72 = F_36 ( V_73 + 2 ) ;
if ( V_72 == NULL ) {
F_3 ( V_74 L_22 , V_25 -> V_7 ) ;
return NULL ;
}
F_37 ( V_72 , 2 ) ;
F_38 ( V_72 , V_73 ) ;
return V_72 ;
}
static int
F_39 ( struct V_24 * V_25 )
{
struct V_22 * V_23 ;
struct V_63 * V_64 ;
int V_17 ;
int V_75 = V_76 ;
V_23 = F_17 ( V_25 ) ;
do {
if ( ( V_64 = F_35 ( V_25 ) ) == NULL ) {
F_3 ( V_74 L_22 , V_25 -> V_7 ) ;
V_23 -> V_66 . V_77 ++ ;
return 0 ;
}
V_17 = F_14 ( V_23 -> V_33 , V_64 -> V_70 , V_73 ) ;
if ( V_17 == 0 ) {
if ( V_69 > 0 ) F_3 ( V_39 L_23 ,
V_25 -> V_7 , V_76 - V_75 ) ;
break;
}
#if 0
skb_copy_to_linear_data(skb, frame, len);
#endif
V_64 -> V_78 = F_40 ( V_64 , V_25 ) ;
if ( V_69 > 6 ) F_32 ( L_24 , V_64 -> V_70 , V_17 ) ;
F_41 ( V_64 ) ;
V_23 -> V_66 . V_79 ++ ;
V_23 -> V_66 . V_80 += V_17 ;
} while ( -- V_75 );
return V_17 ;
}
static T_3
V_38 ( int V_10 , void * V_81 )
{
struct V_24 * V_25 = V_81 ;
while ( F_39 ( V_25 ) ) ;
return V_82 ;
}
static struct V_83 *
F_42 ( struct V_24 * V_25 )
{
struct V_22 * V_23 = F_17 ( V_25 ) ;
return & V_23 -> V_66 ;
}
static void
F_43 ( struct V_24 * V_25 )
{
F_3 ( V_39 L_25 , V_25 -> V_7 ) ;
}
