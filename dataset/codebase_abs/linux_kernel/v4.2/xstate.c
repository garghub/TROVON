int F_1 ( T_1 V_1 , const char * * V_2 )
{
T_1 V_3 = V_1 & ~ V_4 ;
if ( F_2 ( V_2 ) ) {
long V_5 , V_6 ;
T_1 V_7 ;
if ( V_3 )
V_7 = V_3 ;
else
V_7 = V_1 ;
V_5 = F_3 ( V_7 ) - 1 ;
V_6 = F_4 ( V_8 ) - 1 ;
V_5 = F_5 ( V_5 , V_6 ) ;
* V_2 = V_8 [ V_5 ] ;
}
if ( V_3 )
return 0 ;
return 1 ;
}
void F_6 ( struct V_9 * V_9 )
{
struct V_10 * V_11 = & V_9 -> V_12 . V_13 ;
int V_14 ;
T_1 V_15 ;
if ( ! F_7 () )
return;
V_15 = V_9 -> V_12 . V_16 . V_17 . V_15 ;
if ( ( V_15 & V_4 ) == V_4 )
return;
if ( ! ( V_15 & V_18 ) ) {
V_11 -> V_19 = 0x37f ;
V_11 -> V_20 = 0 ;
V_11 -> V_21 = 0 ;
V_11 -> V_22 = 0 ;
V_11 -> V_23 = 0 ;
V_11 -> V_24 = 0 ;
memset ( & V_11 -> V_25 [ 0 ] , 0 , 128 ) ;
}
if ( ! ( V_15 & V_26 ) )
memset ( & V_11 -> V_27 [ 0 ] , 0 , 256 ) ;
V_14 = 0x2 ;
V_15 = ( V_4 & ~ V_15 ) >> 2 ;
while ( V_15 ) {
if ( V_15 & 0x1 ) {
int V_28 = V_29 [ V_14 ] ;
int V_30 = V_31 [ V_14 ] ;
memcpy ( ( void * ) V_11 + V_28 ,
( void * ) & V_32 . V_16 + V_28 ,
V_30 ) ;
}
V_15 >>= 1 ;
V_14 ++ ;
}
}
void F_8 ( void )
{
if ( ! V_33 || ! V_4 )
return;
F_9 ( V_34 ) ;
F_10 ( V_35 , V_4 ) ;
}
static void T_2 F_11 ( void )
{
T_3 V_36 , V_37 , V_38 , V_39 , V_40 ;
V_41 = F_3 ( V_4 ) ;
for ( V_40 = 2 ; V_40 < V_41 ; V_40 ++ ) {
F_12 ( V_42 , V_40 , & V_36 , & V_37 , & V_38 , & V_39 ) ;
V_29 [ V_40 ] = V_37 ;
V_31 [ V_40 ] = V_36 ;
F_13 ( V_43 L_1 , V_40 , V_37 , V_40 , V_36 ) ;
}
}
static void T_2 F_14 ( T_1 V_44 )
{
const char * V_2 ;
if ( F_1 ( V_44 , & V_2 ) )
F_15 ( L_2 , V_44 , V_2 ) ;
}
static void T_2 F_16 ( void )
{
F_14 ( V_18 ) ;
F_14 ( V_26 ) ;
F_14 ( V_45 ) ;
F_14 ( V_46 ) ;
F_14 ( V_47 ) ;
F_14 ( V_48 ) ;
F_14 ( V_49 ) ;
F_14 ( V_50 ) ;
}
static void T_2 F_17 ( void )
{
unsigned int V_51 [ sizeof( V_4 ) * 8 ] ;
int V_52 ;
V_53 [ 0 ] = 0 ;
V_53 [ 1 ] = F_18 ( struct V_10 , V_27 ) ;
if ( ! V_54 ) {
for ( V_52 = 2 ; V_52 < V_41 ; V_52 ++ ) {
if ( F_19 ( V_52 , ( unsigned long * ) & V_4 ) ) {
V_53 [ V_52 ] = V_29 [ V_52 ] ;
V_51 [ V_52 ] = V_31 [ V_52 ] ;
}
}
return;
}
V_53 [ 2 ] = V_55 + V_56 ;
for ( V_52 = 2 ; V_52 < V_41 ; V_52 ++ ) {
if ( F_19 ( V_52 , ( unsigned long * ) & V_4 ) )
V_51 [ V_52 ] = V_31 [ V_52 ] ;
else
V_51 [ V_52 ] = 0 ;
if ( V_52 > 2 )
V_53 [ V_52 ] = V_53 [ V_52 - 1 ]
+ V_51 [ V_52 - 1 ] ;
}
}
static void T_2 F_20 ( void )
{
static int V_57 = 1 ;
F_21 ( ! V_57 ) ;
V_57 = 0 ;
if ( ! V_33 )
return;
F_11 () ;
F_16 () ;
if ( V_54 ) {
V_32 . V_16 . V_17 . V_58 = ( T_1 ) 1 << 63 | V_4 ;
V_32 . V_16 . V_17 . V_15 = V_4 ;
}
F_22 ( & V_32 . V_16 ) ;
F_23 ( & V_32 . V_16 ) ;
}
static void T_2 F_24 ( void )
{
unsigned int V_36 , V_37 , V_38 , V_39 ;
int V_52 ;
if ( ! V_54 ) {
F_12 ( V_42 , 0 , & V_36 , & V_37 , & V_38 , & V_39 ) ;
V_59 = V_37 ;
return;
}
V_59 = V_55 + V_56 ;
for ( V_52 = 2 ; V_52 < 64 ; V_52 ++ ) {
if ( F_19 ( V_52 , ( unsigned long * ) & V_4 ) ) {
F_12 ( V_42 , V_52 , & V_36 , & V_37 , & V_38 , & V_39 ) ;
V_59 += V_36 ;
}
}
}
void T_2 F_25 ( void )
{
unsigned int V_36 , V_37 , V_38 , V_39 ;
static int V_57 = 1 ;
F_21 ( ! V_57 ) ;
V_57 = 0 ;
if ( ! V_33 ) {
F_15 ( L_3 ) ;
return;
}
if ( V_60 . V_61 < V_42 ) {
F_21 ( 1 ) ;
return;
}
F_12 ( V_42 , 0 , & V_36 , & V_37 , & V_38 , & V_39 ) ;
V_4 = V_36 + ( ( T_1 ) V_39 << 32 ) ;
if ( ( V_4 & V_62 ) != V_62 ) {
F_26 ( L_4 , V_4 ) ;
F_27 () ;
}
V_4 = V_4 & V_63 ;
F_8 () ;
F_24 () ;
F_28 ( V_59 , V_4 ) ;
F_29 () ;
F_20 () ;
F_17 () ;
F_15 ( L_5 ,
V_4 ,
V_59 ,
V_54 ? L_6 : L_7 ) ;
}
void F_30 ( void )
{
if ( V_33 )
F_10 ( V_35 , V_4 ) ;
}
void * F_31 ( struct V_64 * V_16 , int V_65 )
{
int V_66 = F_3 ( V_65 ) - 1 ;
if ( ! F_32 ( V_67 ) )
return NULL ;
V_16 = & V_68 -> V_69 . V_9 . V_12 . V_16 ;
F_33 ( ! ( V_4 & V_65 ) ,
L_8 ) ;
if ( ! ( V_16 -> V_17 . V_15 & V_65 ) )
return NULL ;
return ( void * ) V_16 + V_53 [ V_66 ] ;
}
const void * F_34 ( int V_70 )
{
struct V_9 * V_9 = & V_68 -> V_69 . V_9 ;
if ( ! V_9 -> V_71 )
return NULL ;
F_35 ( V_9 ) ;
return F_31 ( & V_9 -> V_12 . V_16 , V_70 ) ;
}
