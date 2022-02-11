static int F_1 ( int V_1 , struct V_2 * V_3 )
{
struct V_4 * V_5 = & F_2 ( V_1 ) ;
unsigned int V_6 [ 2 ] ;
memset ( V_3 , 0 , sizeof( * V_3 ) ) ;
if ( V_5 -> V_7 != V_8 || V_5 -> V_9 < 6 ||
F_3 ( V_5 , V_10 ) ) {
F_4 ( L_1 , V_1 ) ;
return - 1 ;
}
V_3 -> V_11 = F_5 ( 0x00000001 ) ;
if ( ( V_5 -> V_12 >= 5 ) || ( V_5 -> V_9 > 6 ) ) {
F_6 ( V_13 , V_6 [ 0 ] , V_6 [ 1 ] ) ;
V_3 -> V_14 = 1 << ( ( V_6 [ 1 ] >> 18 ) & 7 ) ;
}
F_7 ( V_15 , 0 , 0 ) ;
F_8 () ;
F_6 ( V_15 , V_6 [ 0 ] , V_3 -> V_16 ) ;
F_9 ( L_2 ,
V_1 , V_3 -> V_11 , V_3 -> V_14 , V_3 -> V_16 ) ;
return 0 ;
}
static inline int F_10 ( struct V_2 * V_3 , int V_11 , int V_14 )
{
return ( ! F_11 ( V_11 , V_3 -> V_11 , V_14 , V_3 -> V_14 ) ) ? 0 : 1 ;
}
static inline int
F_12 ( struct V_17 * V_18 , int V_16 )
{
return ( V_18 -> V_16 <= V_16 ) ? 0 : 1 ;
}
static int F_13 ( void * V_19 )
{
unsigned long V_20 , V_21 , V_22 ;
struct V_17 * V_18 = V_19 ;
struct V_23 * V_24 = NULL ;
int V_25 , V_26 , V_27 = 0 , V_28 ;
struct V_29 * V_30 ;
V_20 = F_14 ( V_18 ) ;
V_21 = F_15 ( V_18 ) ;
if ( V_21 + V_31 > V_20 ) {
F_4 ( L_3 ) ;
return - V_32 ;
}
if ( V_18 -> V_33 != 1 || V_18 -> V_34 != 1 ) {
F_4 ( L_4 ) ;
return - V_32 ;
}
V_22 = V_20 - ( V_31 + V_21 ) ;
if ( V_22 ) {
if ( ( V_22 < V_35 )
|| ( ( V_22 - V_35 ) % V_36 ) ) {
F_4 ( L_5 ) ;
return - V_32 ;
}
V_24 = V_19 + V_31 + V_21 ;
if ( V_22 != F_16 ( V_24 ) ) {
F_4 ( L_6 ) ;
return - V_37 ;
}
V_27 = V_24 -> V_38 ;
}
if ( V_22 ) {
int V_39 = 0 ;
int * V_40 = ( int * ) V_24 ;
V_28 = V_22 / V_41 ;
while ( V_28 -- )
V_39 += V_40 [ V_28 ] ;
if ( V_39 ) {
F_17 ( L_7 ) ;
return - V_32 ;
}
}
V_26 = 0 ;
V_28 = ( V_31 + V_21 ) / V_41 ;
while ( V_28 -- )
V_26 += ( ( int * ) V_19 ) [ V_28 ] ;
if ( V_26 ) {
F_4 ( L_8 ) ;
return - V_32 ;
}
if ( ! V_22 )
return 0 ;
for ( V_28 = 0 ; V_28 < V_27 ; V_28 ++ ) {
V_30 = ( void * ) V_24 + V_35 +
V_36 * V_28 ;
V_25 = V_26
- ( V_18 -> V_11 + V_18 -> V_14 + V_18 -> V_42 )
+ ( V_30 -> V_11 + V_30 -> V_14 + V_30 -> V_42 ) ;
if ( V_25 ) {
F_4 ( L_8 ) ;
return - V_32 ;
}
}
return 0 ;
}
static int
F_18 ( struct V_2 * V_43 , void * V_19 , int V_16 )
{
struct V_17 * V_18 = V_19 ;
struct V_23 * V_24 ;
unsigned long V_20 = F_14 ( V_18 ) ;
int V_27 , V_28 ;
struct V_29 * V_30 ;
if ( ! F_12 ( V_18 , V_16 ) )
return 0 ;
if ( F_10 ( V_43 , V_18 -> V_11 , V_18 -> V_14 ) )
return 1 ;
if ( V_20 <= F_15 ( V_18 ) + V_31 )
return 0 ;
V_24 = V_19 + F_15 ( V_18 ) + V_31 ;
V_27 = V_24 -> V_38 ;
V_30 = ( void * ) V_24 + V_35 ;
for ( V_28 = 0 ; V_28 < V_27 ; V_28 ++ ) {
if ( F_10 ( V_43 , V_30 -> V_11 , V_30 -> V_14 ) )
return 1 ;
V_30 ++ ;
}
return 0 ;
}
static int F_19 ( int V_44 )
{
struct V_45 * V_46 ;
struct V_47 * V_48 ;
unsigned int V_6 [ 2 ] ;
int V_1 ;
V_1 = F_20 () ;
V_48 = V_47 + V_44 ;
V_46 = V_48 -> V_19 ;
F_21 ( V_1 != V_44 ) ;
if ( V_46 == NULL )
return 0 ;
F_7 ( V_49 ,
( unsigned long ) V_46 -> V_50 ,
( unsigned long ) V_46 -> V_50 >> 16 >> 16 ) ;
F_7 ( V_15 , 0 , 0 ) ;
F_8 () ;
F_6 ( V_15 , V_6 [ 0 ] , V_6 [ 1 ] ) ;
if ( V_6 [ 1 ] != V_46 -> V_51 . V_16 ) {
F_4 ( L_9 ,
V_1 , V_46 -> V_51 . V_16 ) ;
return - 1 ;
}
F_9 ( L_10 ,
V_1 , V_6 [ 1 ] ,
V_46 -> V_51 . V_52 & 0xffff ,
V_46 -> V_51 . V_52 >> 24 ,
( V_46 -> V_51 . V_52 >> 16 ) & 0xff ) ;
V_48 -> V_43 . V_16 = V_6 [ 1 ] ;
return 0 ;
}
static enum V_53 F_22 ( int V_44 , void * V_54 , T_1 V_55 ,
int (* F_23)( void * , const void * , T_1 ) )
{
struct V_47 * V_48 = V_47 + V_44 ;
T_2 * V_56 = V_54 , * V_57 = NULL , * V_19 = NULL ;
int V_58 = V_48 -> V_43 . V_16 ;
unsigned int V_59 = V_55 ;
enum V_53 V_60 = V_61 ;
unsigned int V_62 = 0 ;
while ( V_59 ) {
struct V_17 V_18 ;
unsigned int V_63 ;
if ( F_23 ( & V_18 , V_56 , sizeof( V_18 ) ) )
break;
V_63 = F_14 ( & V_18 ) ;
if ( ! V_63 || V_63 > V_59 ) {
F_4 ( L_11 ) ;
break;
}
if ( ! V_19 || V_63 > V_62 ) {
F_24 ( V_19 ) ;
V_19 = F_25 ( V_63 ) ;
if ( ! V_19 )
break;
V_62 = V_63 ;
}
if ( F_23 ( V_19 , V_56 , V_63 ) ||
F_13 ( V_19 ) < 0 ) {
break;
}
if ( F_18 ( & V_48 -> V_43 , V_19 , V_58 ) ) {
F_24 ( V_57 ) ;
V_58 = V_18 . V_16 ;
V_57 = V_19 ;
V_19 = NULL ;
}
V_56 += V_63 ;
V_59 -= V_63 ;
}
F_24 ( V_19 ) ;
if ( V_59 ) {
F_24 ( V_57 ) ;
V_60 = V_64 ;
goto V_65;
}
if ( ! V_57 ) {
V_60 = V_66 ;
goto V_65;
}
F_24 ( V_48 -> V_19 ) ;
V_48 -> V_19 = (struct V_45 * ) V_57 ;
F_26 ( L_12 ,
V_44 , V_58 , V_48 -> V_43 . V_16 ) ;
V_65:
return V_60 ;
}
static int F_27 ( void * V_67 , const void * V_68 , T_1 V_69 )
{
memcpy ( V_67 , V_68 , V_69 ) ;
return 0 ;
}
static enum V_53 F_28 ( int V_44 , struct V_70 * V_70 )
{
char V_71 [ 30 ] ;
struct V_4 * V_5 = & F_2 ( V_44 ) ;
const struct V_72 * V_72 ;
enum V_53 V_73 ;
sprintf ( V_71 , L_13 ,
V_5 -> V_9 , V_5 -> V_12 , V_5 -> V_74 ) ;
if ( F_29 ( & V_72 , V_71 , V_70 ) ) {
F_26 ( L_14 , V_71 ) ;
return V_66 ;
}
V_73 = F_22 ( V_44 , ( void * ) V_72 -> V_54 ,
V_72 -> V_55 , & F_27 ) ;
F_30 ( V_72 ) ;
return V_73 ;
}
static int F_31 ( void * V_67 , const void * V_68 , T_1 V_69 )
{
return F_32 ( V_67 , V_68 , V_69 ) ;
}
static enum V_53
F_33 ( int V_44 , const void T_3 * V_75 , T_1 V_55 )
{
return F_22 ( V_44 , ( void * ) V_75 , V_55 , & F_31 ) ;
}
static void F_34 ( int V_44 )
{
struct V_47 * V_48 = V_47 + V_44 ;
F_24 ( V_48 -> V_19 ) ;
V_48 -> V_19 = NULL ;
}
struct V_76 * T_4 F_35 ( void )
{
return & V_77 ;
}
