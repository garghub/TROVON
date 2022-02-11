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
F_9 ( int V_10 , int V_11 , unsigned int V_12 )
{
return F_7 ( V_10 , V_12 , 0 , 0 , V_13 ) ;
}
static inline int
F_10 ( int V_10 )
{
return F_7 ( V_10 , 0 , 0 , 0 , V_14 ) ;
}
static inline int
F_11 ( int V_10 , unsigned char * V_15 , unsigned int V_16 )
{
return F_7 ( V_10 , F_8 ( V_15 ) , V_16 , 0 , V_17 ) ;
}
static inline int
F_12 ( int V_10 , unsigned char * V_15 , unsigned int V_16 )
{
return F_7 ( V_10 , F_8 ( V_15 ) , V_16 , 0 , V_18 ) ;
}
static int
F_4 ( void )
{
unsigned char V_19 [ V_20 ] ;
struct V_21 * V_22 ;
struct V_23 * V_24 ;
int V_10 , V_25 , V_26 ;
if ( F_13 ( 0 , & V_27 ) )
return - V_28 ;
V_10 = F_6 ( V_2 , V_19 ) ;
if ( V_10 == - 1 )
return - V_28 ;
V_24 = F_14 ( sizeof( struct V_21 ) ) ;
if ( ! V_24 )
return - V_29 ;
memcpy ( V_24 -> V_30 , V_19 , sizeof( V_19 ) ) ;
V_22 = F_15 ( V_24 ) ;
V_22 -> V_31 = V_10 ;
V_24 -> V_32 = & V_33 ;
V_25 = F_16 ( V_24 ) ;
if ( V_25 ) {
F_17 ( V_24 ) ;
return V_25 ;
}
if ( ( V_26 = F_18 ( V_34 ) ) < 0 )
F_19 ( L_2 , V_35 ) ;
V_24 -> V_11 = V_26 ;
F_3 ( V_4 L_3 ,
V_24 -> V_7 , V_2 , V_22 -> V_31 , V_24 -> V_30 , V_24 -> V_11 ) ;
return 0 ;
}
static int
F_20 ( struct V_23 * V_24 )
{
if ( F_21 ( V_24 -> V_11 , V_36 , 0 , L_4 , V_24 ) ) {
F_3 ( V_37 L_5 , V_24 -> V_11 ) ;
return - V_38 ;
}
F_22 ( V_24 ) ;
return 0 ;
}
static T_2 int F_23 ( struct V_23 * V_24 )
{
return ( V_24 -> type == V_39 && strncmp ( V_24 -> V_7 , L_6 , 5 ) ) ;
}
static int
F_24 ( struct V_40 * V_41 , unsigned long V_42 , void * V_43 )
{
struct V_23 * V_24 = F_25 ( V_43 ) ;
struct V_21 * V_22 ;
struct V_44 * V_45 ;
struct V_46 * * V_47 = NULL ;
struct V_46 * V_48 = NULL ;
int V_3 ;
if ( ! V_24 ) {
F_3 ( V_37 L_7 ) ;
return V_49 ;
}
if ( F_26 ( V_24 ) != & V_50 )
return V_49 ;
if ( V_42 != V_51 && V_42 != V_52 ) return V_49 ;
if ( ! F_23 ( V_24 ) ) return V_49 ;
if ( ( V_45 = V_24 -> V_53 ) != NULL ) {
for ( V_47 = & V_45 -> V_54 ; ( V_48 = * V_47 ) != NULL ; V_47 = & V_48 -> V_55 )
if ( strcmp ( V_24 -> V_7 , V_48 -> V_56 ) == 0 ) break;
}
if ( V_48 == NULL ) {
F_3 ( V_57 L_8 , V_24 -> V_7 ) ;
return V_49 ;
}
F_3 ( V_4 L_9 ,
V_24 -> V_7 , F_27 ( V_48 -> V_58 ) ) ;
V_22 = F_15 ( V_24 ) ;
V_3 = V_42 == V_51 ?
F_9 ( V_22 -> V_31 , V_24 -> V_11 , F_27 ( V_48 -> V_58 ) ) :
F_10 ( V_22 -> V_31 ) ;
F_3 ( V_4 L_10 ,
V_42 == V_51 ? L_11 : L_12 , V_3 ) ;
return V_49 ;
}
static int
F_28 ( struct V_23 * V_24 )
{
F_29 ( V_24 ) ;
F_30 ( V_24 -> V_11 , V_24 ) ;
return 0 ;
}
static void
F_31 ( unsigned char * V_59 , unsigned char * V_60 , int V_16 )
{
int V_61 ;
F_3 ( L_13 , V_59 , V_16 , V_60 [ 0 ] & 0xff ) ;
for( V_61 = 1 ; V_61 < 6 ; V_61 ++ ) {
F_3 ( L_14 , V_60 [ V_61 ] & 0xff ) ;
}
F_3 ( L_15 , V_60 [ 6 ] & 0xff ) ;
for( V_61 = 7 ; V_61 < 12 ; V_61 ++ ) {
F_3 ( L_14 , V_60 [ V_61 ] & 0xff ) ;
}
F_3 ( L_16 , V_60 [ 12 ] , V_60 [ 13 ] ) ;
for( V_61 = 14 ; V_61 < V_16 ; V_61 ++ ) {
F_3 ( L_17 , V_60 [ V_61 ] & 0xff ) ;
if ( ( V_61 % 10 ) == 0 ) F_3 ( L_18 ) ;
}
F_3 ( L_18 ) ;
}
static int
F_32 ( struct V_62 * V_63 , struct V_23 * V_24 )
{
struct V_21 * V_22 = F_15 ( V_24 ) ;
#if 0
unsigned int length = ETH_ZLEN < skb->len ? skb->len : ETH_ZLEN;
#else
unsigned int V_64 = V_63 -> V_16 ;
#endif
V_22 -> V_65 . V_66 += V_63 -> V_16 ;
V_22 -> V_65 . V_67 ++ ;
if ( V_68 > 5 ) F_31 ( L_19 , V_63 -> V_69 , V_64 ) ;
F_11 ( V_22 -> V_31 , V_63 -> V_69 , V_64 ) ;
F_33 ( V_63 ) ;
return V_70 ;
}
static inline struct V_62 *
F_34 ( struct V_23 * V_24 )
{
struct V_62 * V_71 ;
V_71 = F_35 ( V_72 + 2 ) ;
if ( V_71 == NULL ) {
F_3 ( V_73 L_20 , V_24 -> V_7 ) ;
return NULL ;
}
F_36 ( V_71 , 2 ) ;
F_37 ( V_71 , V_72 ) ;
return V_71 ;
}
static int
F_38 ( struct V_23 * V_24 )
{
struct V_21 * V_22 ;
struct V_62 * V_63 ;
int V_16 ;
int V_74 = V_75 ;
V_22 = F_15 ( V_24 ) ;
do {
if ( ( V_63 = F_34 ( V_24 ) ) == NULL ) {
F_3 ( V_73 L_20 , V_24 -> V_7 ) ;
V_22 -> V_65 . V_76 ++ ;
return 0 ;
}
V_16 = F_12 ( V_22 -> V_31 , V_63 -> V_69 , V_72 ) ;
if ( V_16 == 0 ) {
if ( V_68 > 0 ) F_3 ( V_37 L_21 ,
V_24 -> V_7 , V_75 - V_74 ) ;
break;
}
#if 0
skb_copy_to_linear_data(skb, frame, len);
#endif
V_63 -> V_77 = F_39 ( V_63 , V_24 ) ;
if ( V_68 > 6 ) F_31 ( L_22 , V_63 -> V_69 , V_16 ) ;
F_40 ( V_63 ) ;
V_22 -> V_65 . V_78 ++ ;
V_22 -> V_65 . V_79 += V_16 ;
} while ( -- V_74 );
return V_16 ;
}
static T_3
V_36 ( int V_11 , void * V_80 )
{
struct V_23 * V_24 = V_80 ;
while ( F_38 ( V_24 ) ) ;
return V_81 ;
}
static struct V_82 *
F_41 ( struct V_23 * V_24 )
{
struct V_21 * V_22 = F_15 ( V_24 ) ;
return & V_22 -> V_65 ;
}
static void
F_42 ( struct V_23 * V_24 )
{
F_3 ( V_37 L_23 , V_24 -> V_7 ) ;
}
