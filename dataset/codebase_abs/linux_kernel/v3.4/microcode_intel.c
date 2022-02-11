static int F_1 ( int V_1 , struct V_2 * V_3 )
{
struct V_4 * V_5 = & F_2 ( V_1 ) ;
unsigned int V_6 [ 2 ] ;
memset ( V_3 , 0 , sizeof( * V_3 ) ) ;
V_3 -> V_7 = F_3 ( 0x00000001 ) ;
if ( ( V_5 -> V_8 >= 5 ) || ( V_5 -> V_9 > 6 ) ) {
F_4 ( V_10 , V_6 [ 0 ] , V_6 [ 1 ] ) ;
V_3 -> V_11 = 1 << ( ( V_6 [ 1 ] >> 18 ) & 7 ) ;
}
V_3 -> V_12 = V_5 -> V_13 ;
F_5 ( L_1 ,
V_1 , V_3 -> V_7 , V_3 -> V_11 , V_3 -> V_12 ) ;
return 0 ;
}
static inline int F_6 ( struct V_2 * V_3 , int V_7 , int V_11 )
{
return ( ! F_7 ( V_7 , V_3 -> V_7 , V_11 , V_3 -> V_11 ) ) ? 0 : 1 ;
}
static inline int
F_8 ( struct V_14 * V_15 , int V_12 )
{
return ( V_15 -> V_12 <= V_12 ) ? 0 : 1 ;
}
static int F_9 ( void * V_16 )
{
unsigned long V_17 , V_18 , V_19 ;
struct V_14 * V_15 = V_16 ;
struct V_20 * V_21 = NULL ;
int V_22 , V_23 , V_24 = 0 , V_25 ;
struct V_26 * V_27 ;
V_17 = F_10 ( V_15 ) ;
V_18 = F_11 ( V_15 ) ;
if ( V_18 + V_28 > V_17 ) {
F_12 ( L_2 ) ;
return - V_29 ;
}
if ( V_15 -> V_30 != 1 || V_15 -> V_31 != 1 ) {
F_12 ( L_3 ) ;
return - V_29 ;
}
V_19 = V_17 - ( V_28 + V_18 ) ;
if ( V_19 ) {
if ( ( V_19 < V_32 )
|| ( ( V_19 - V_32 ) % V_33 ) ) {
F_12 ( L_4 ) ;
return - V_29 ;
}
V_21 = V_16 + V_28 + V_18 ;
if ( V_19 != F_13 ( V_21 ) ) {
F_12 ( L_5 ) ;
return - V_34 ;
}
V_24 = V_21 -> V_35 ;
}
if ( V_19 ) {
int V_36 = 0 ;
int * V_37 = ( int * ) V_21 ;
V_25 = V_19 / V_38 ;
while ( V_25 -- )
V_36 += V_37 [ V_25 ] ;
if ( V_36 ) {
F_14 ( L_6 ) ;
return - V_29 ;
}
}
V_23 = 0 ;
V_25 = ( V_28 + V_18 ) / V_38 ;
while ( V_25 -- )
V_23 += ( ( int * ) V_16 ) [ V_25 ] ;
if ( V_23 ) {
F_12 ( L_7 ) ;
return - V_29 ;
}
if ( ! V_19 )
return 0 ;
for ( V_25 = 0 ; V_25 < V_24 ; V_25 ++ ) {
V_27 = ( void * ) V_21 + V_32 +
V_33 * V_25 ;
V_22 = V_23
- ( V_15 -> V_7 + V_15 -> V_11 + V_15 -> V_39 )
+ ( V_27 -> V_7 + V_27 -> V_11 + V_27 -> V_39 ) ;
if ( V_22 ) {
F_12 ( L_7 ) ;
return - V_29 ;
}
}
return 0 ;
}
static int
F_15 ( struct V_2 * V_40 , void * V_16 , int V_12 )
{
struct V_14 * V_15 = V_16 ;
struct V_20 * V_21 ;
unsigned long V_17 = F_10 ( V_15 ) ;
int V_24 , V_25 ;
struct V_26 * V_27 ;
if ( ! F_8 ( V_15 , V_12 ) )
return 0 ;
if ( F_6 ( V_40 , V_15 -> V_7 , V_15 -> V_11 ) )
return 1 ;
if ( V_17 <= F_11 ( V_15 ) + V_28 )
return 0 ;
V_21 = V_16 + F_11 ( V_15 ) + V_28 ;
V_24 = V_21 -> V_35 ;
V_27 = ( void * ) V_21 + V_32 ;
for ( V_25 = 0 ; V_25 < V_24 ; V_25 ++ ) {
if ( F_6 ( V_40 , V_27 -> V_7 , V_27 -> V_11 ) )
return 1 ;
V_27 ++ ;
}
return 0 ;
}
static int F_16 ( int V_41 )
{
struct V_42 * V_43 ;
struct V_44 * V_45 ;
unsigned int V_6 [ 2 ] ;
int V_1 = F_17 () ;
struct V_4 * V_5 = & F_2 ( V_1 ) ;
V_45 = V_44 + V_41 ;
V_43 = V_45 -> V_16 ;
F_18 ( V_1 != V_41 ) ;
if ( V_43 == NULL )
return 0 ;
F_19 ( V_46 ,
( unsigned long ) V_43 -> V_47 ,
( unsigned long ) V_43 -> V_47 >> 16 >> 16 ) ;
F_19 ( V_48 , 0 , 0 ) ;
F_20 () ;
F_4 ( V_48 , V_6 [ 0 ] , V_6 [ 1 ] ) ;
if ( V_6 [ 1 ] != V_43 -> V_49 . V_12 ) {
F_12 ( L_8 ,
V_1 , V_43 -> V_49 . V_12 ) ;
return - 1 ;
}
F_5 ( L_9 ,
V_1 , V_6 [ 1 ] ,
V_43 -> V_49 . V_50 & 0xffff ,
V_43 -> V_49 . V_50 >> 24 ,
( V_43 -> V_49 . V_50 >> 16 ) & 0xff ) ;
V_45 -> V_40 . V_12 = V_6 [ 1 ] ;
V_5 -> V_13 = V_6 [ 1 ] ;
return 0 ;
}
static enum V_51 F_21 ( int V_41 , void * V_52 , T_1 V_53 ,
int (* F_22)( void * , const void * , T_1 ) )
{
struct V_44 * V_45 = V_44 + V_41 ;
T_2 * V_54 = V_52 , * V_55 = NULL , * V_16 = NULL ;
int V_56 = V_45 -> V_40 . V_12 ;
unsigned int V_57 = V_53 ;
enum V_51 V_58 = V_59 ;
unsigned int V_60 = 0 ;
while ( V_57 ) {
struct V_14 V_15 ;
unsigned int V_61 ;
if ( F_22 ( & V_15 , V_54 , sizeof( V_15 ) ) )
break;
V_61 = F_10 ( & V_15 ) ;
if ( ! V_61 || V_61 > V_57 ) {
F_12 ( L_10 ) ;
break;
}
if ( ! V_16 || V_61 > V_60 ) {
F_23 ( V_16 ) ;
V_16 = F_24 ( V_61 ) ;
if ( ! V_16 )
break;
V_60 = V_61 ;
}
if ( F_22 ( V_16 , V_54 , V_61 ) ||
F_9 ( V_16 ) < 0 ) {
break;
}
if ( F_15 ( & V_45 -> V_40 , V_16 , V_56 ) ) {
F_23 ( V_55 ) ;
V_56 = V_15 . V_12 ;
V_55 = V_16 ;
V_16 = NULL ;
}
V_54 += V_61 ;
V_57 -= V_61 ;
}
F_23 ( V_16 ) ;
if ( V_57 ) {
F_23 ( V_55 ) ;
V_58 = V_62 ;
goto V_63;
}
if ( ! V_55 ) {
V_58 = V_64 ;
goto V_63;
}
F_23 ( V_45 -> V_16 ) ;
V_45 -> V_16 = (struct V_42 * ) V_55 ;
F_25 ( L_11 ,
V_41 , V_56 , V_45 -> V_40 . V_12 ) ;
V_63:
return V_58 ;
}
static int F_26 ( void * V_65 , const void * V_66 , T_1 V_67 )
{
memcpy ( V_65 , V_66 , V_67 ) ;
return 0 ;
}
static enum V_51 F_27 ( int V_41 , struct V_68 * V_68 )
{
char V_69 [ 30 ] ;
struct V_4 * V_5 = & F_2 ( V_41 ) ;
const struct V_70 * V_70 ;
enum V_51 V_71 ;
sprintf ( V_69 , L_12 ,
V_5 -> V_9 , V_5 -> V_8 , V_5 -> V_72 ) ;
if ( F_28 ( & V_70 , V_69 , V_68 ) ) {
F_25 ( L_13 , V_69 ) ;
return V_64 ;
}
V_71 = F_21 ( V_41 , ( void * ) V_70 -> V_52 ,
V_70 -> V_53 , & F_26 ) ;
F_29 ( V_70 ) ;
return V_71 ;
}
static int F_30 ( void * V_65 , const void * V_66 , T_1 V_67 )
{
return F_31 ( V_65 , V_66 , V_67 ) ;
}
static enum V_51
F_32 ( int V_41 , const void T_3 * V_73 , T_1 V_53 )
{
return F_21 ( V_41 , ( void * ) V_73 , V_53 , & F_30 ) ;
}
static void F_33 ( int V_41 )
{
struct V_44 * V_45 = V_44 + V_41 ;
F_23 ( V_45 -> V_16 ) ;
V_45 -> V_16 = NULL ;
}
struct V_74 * T_4 F_34 ( void )
{
struct V_4 * V_5 = & F_2 ( 0 ) ;
if ( V_5 -> V_75 != V_76 || V_5 -> V_9 < 6 ||
F_35 ( V_5 , V_77 ) ) {
F_12 ( L_14 , V_5 -> V_9 ) ;
return NULL ;
}
return & V_78 ;
}
