T_1 F_1 ( void )
{
return V_1 . V_2 ;
}
bool F_2 ( unsigned int V_3 )
{
return ( ( V_1 . V_4 & V_3 ) == V_3 ) ;
}
struct V_5 * F_3 ( int V_6 )
{
return ( V_6 < V_1 . V_2 ) ? & V_1 . V_7 [ V_6 ] : NULL ;
}
static struct V_8 * F_4 ( struct V_8 * V_9 ,
const struct V_10 * V_11 )
{
do {
V_9 = F_5 ( V_12 , V_12 , V_9 ) ;
if ( ! V_9 )
break;
} while ( ! F_6 ( V_11 , V_9 ) );
return V_9 ;
}
static int F_7 ( T_1 V_6 , T_2 V_13 , T_2 * V_14 , bool V_15 )
{
struct V_8 * V_16 ;
int V_17 = - V_18 ;
if ( V_6 >= V_1 . V_2 )
goto V_19;
V_16 = F_3 ( V_6 ) -> V_16 ;
if ( ! V_16 )
goto V_19;
F_8 ( & V_20 ) ;
V_17 = F_9 ( V_16 , 0x60 , V_13 ) ;
if ( V_17 ) {
F_10 ( L_1 , V_13 ) ;
goto V_21;
}
V_17 = ( V_15 ? F_9 ( V_16 , 0x64 , * V_14 )
: F_11 ( V_16 , 0x64 , V_14 ) ) ;
if ( V_17 )
F_10 ( L_2 ,
( V_15 ? L_3 : L_4 ) , V_13 ) ;
V_21:
F_12 ( & V_20 ) ;
V_19:
return V_17 ;
}
int F_13 ( T_1 V_6 , T_2 V_13 , T_2 * V_14 )
{
return F_7 ( V_6 , V_13 , V_14 , false ) ;
}
int F_14 ( T_1 V_6 , T_2 V_13 , T_2 V_14 )
{
return F_7 ( V_6 , V_13 , & V_14 , true ) ;
}
int F_15 ( T_1 V_6 , T_3 V_22 , T_1 V_23 , T_3 V_24 , T_2 * V_25 )
{
struct V_8 * V_26 ;
T_2 V_27 ;
int V_17 = - V_18 ;
if ( V_6 >= V_1 . V_2 )
goto V_19;
V_26 = F_3 ( V_6 ) -> V_28 ;
if ( ! V_26 )
goto V_19;
V_27 = 1 ;
V_27 |= V_23 & 0x3FC ;
V_27 |= ( V_22 & 0x7 ) << 11 ;
V_27 |= V_24 << 16 ;
F_8 ( & V_20 ) ;
V_17 = F_9 ( V_26 , 0x5C , V_27 ) ;
if ( V_17 ) {
F_10 ( L_5 , V_27 ) ;
goto V_21;
}
V_17 = F_11 ( V_26 , 0x98 , V_25 ) ;
if ( V_17 )
F_10 ( L_6 , V_27 ) ;
V_21:
F_12 ( & V_20 ) ;
V_19:
return V_17 ;
}
int F_16 ( void )
{
T_1 V_29 = 0 ;
struct V_5 * V_7 ;
struct V_8 * V_16 , * V_30 , * V_28 ;
if ( V_1 . V_2 )
return 0 ;
V_30 = NULL ;
while ( ( V_30 = F_4 ( V_30 , V_31 ) ) != NULL )
V_29 ++ ;
if ( ! V_29 )
return - V_18 ;
V_7 = F_17 ( V_29 , sizeof( struct V_5 ) , V_32 ) ;
if ( ! V_7 )
return - V_33 ;
V_1 . V_7 = V_7 ;
V_1 . V_2 = V_29 ;
V_28 = V_30 = V_16 = NULL ;
for ( V_29 = 0 ; V_29 != V_1 . V_2 ; V_29 ++ ) {
F_3 ( V_29 ) -> V_16 = V_16 =
F_4 ( V_16 , V_34 ) ;
F_3 ( V_29 ) -> V_30 = V_30 =
F_4 ( V_30 , V_31 ) ;
F_3 ( V_29 ) -> V_28 = V_28 =
F_4 ( V_28 , V_35 ) ;
}
if ( F_18 () )
V_1 . V_4 |= V_36 ;
if ( ! F_19 ( 0x80000006 ) )
return 0 ;
if ( V_37 . V_38 == 0x10 &&
V_37 . V_39 >= 0x8 &&
( V_37 . V_39 > 0x9 ||
V_37 . V_40 >= 0x1 ) )
V_1 . V_4 |= V_41 ;
if ( V_37 . V_38 == 0x15 )
V_1 . V_4 |= V_41 ;
if ( V_37 . V_38 == 0x15 )
V_1 . V_4 |= V_42 ;
return 0 ;
}
bool T_4 F_20 ( T_2 V_43 )
{
const struct V_10 * V_44 ;
T_2 V_45 = V_43 & 0xffff ;
V_43 >>= 16 ;
for ( V_44 = V_31 ; V_44 -> V_45 ; V_44 ++ )
if ( V_45 == V_44 -> V_45 && V_43 == V_44 -> V_43 )
return true ;
return false ;
}
struct V_46 * F_21 ( struct V_46 * V_47 )
{
T_2 V_13 ;
T_5 V_48 , V_49 ;
unsigned int V_50 ;
if ( V_37 . V_51 != V_52 )
return NULL ;
if ( V_37 . V_38 < 0x10 )
return NULL ;
V_13 = V_53 ;
F_22 ( V_13 , V_49 ) ;
if ( ! ( V_49 & V_54 ) )
return NULL ;
V_48 = V_49 & ( V_55 << V_56 ) ;
V_50 = ( V_49 >> V_57 ) &
V_58 ;
V_47 -> V_4 = V_59 ;
V_47 -> V_60 = V_48 ;
V_47 -> V_61 = V_48 + ( 1ULL << ( V_50 + 20 ) ) - 1 ;
return V_47 ;
}
int F_23 ( int V_62 )
{
struct V_8 * V_28 = F_3 ( F_24 ( V_62 ) ) -> V_28 ;
unsigned int V_63 ;
if ( ! F_2 ( V_42 ) )
return 0 ;
F_11 ( V_28 , 0x1d4 , & V_63 ) ;
return ( V_63 >> ( 4 * F_25 ( V_62 ) . V_64 ) ) & 0xf ;
}
int F_26 ( int V_62 , unsigned long V_63 )
{
static unsigned int V_65 , V_66 ;
struct V_5 * V_7 = F_3 ( F_24 ( V_62 ) ) ;
unsigned int V_23 ;
int V_67 ;
if ( ! F_2 ( V_42 ) || V_63 > 0xf )
return - V_68 ;
if ( V_65 == 0 ) {
F_11 ( V_7 -> V_28 , 0x1d4 , & V_65 ) ;
F_11 ( V_7 -> V_30 , 0x1b8 , & V_66 ) ;
V_66 &= 0x180000 ;
}
if ( V_63 != 0xf ) {
F_11 ( V_7 -> V_30 , 0x1b8 , & V_23 ) ;
F_9 ( V_7 -> V_30 , 0x1b8 , V_23 & ~ 0x180000 ) ;
}
V_67 = F_25 ( V_62 ) . V_64 ;
V_63 <<= 4 * V_67 ;
V_63 |= ( 0xf ^ ( 1 << V_67 ) ) << 26 ;
F_9 ( V_7 -> V_28 , 0x1d4 , V_63 ) ;
F_11 ( V_7 -> V_28 , 0x1d4 , & V_23 ) ;
if ( V_23 == V_65 ) {
F_11 ( V_7 -> V_30 , 0x1b8 , & V_23 ) ;
V_23 &= ~ 0x180000 ;
F_9 ( V_7 -> V_30 , 0x1b8 , V_23 | V_66 ) ;
}
return 0 ;
}
static void F_27 ( void )
{
T_1 V_29 ;
if ( ! F_2 ( V_36 ) )
return;
V_69 = F_28 ( V_1 . V_2 , sizeof( T_2 ) , V_32 ) ;
if ( ! V_69 ) {
V_1 . V_4 &= ~ V_36 ;
F_29 ( L_7 ) ;
return;
}
for ( V_29 = 0 ; V_29 != V_1 . V_2 ; V_29 ++ )
F_11 ( F_3 ( V_29 ) -> V_30 , 0x9c , & V_69 [ V_29 ] ) ;
}
void F_30 ( void )
{
int V_70 , V_29 ;
unsigned long V_4 ;
static F_31 ( V_71 ) ;
if ( ! F_2 ( V_36 ) )
return;
F_32 ( & V_71 , V_4 ) ;
V_70 = 0 ;
for ( V_29 = 0 ; V_29 < V_1 . V_2 ; V_29 ++ ) {
F_9 ( F_3 ( V_29 ) -> V_30 , 0x9c ,
V_69 [ V_29 ] | 1 ) ;
V_70 ++ ;
}
for ( V_29 = 0 ; V_29 < V_1 . V_2 ; V_29 ++ ) {
T_2 V_72 ;
for (; ; ) {
F_11 ( F_3 ( V_29 ) -> V_30 ,
0x9c , & V_72 ) ;
if ( ! ( V_72 & 1 ) )
break;
F_33 () ;
}
}
F_34 ( & V_71 , V_4 ) ;
if ( ! V_70 )
F_29 ( L_8 ) ;
}
static void F_35 ( void * V_73 )
{
#define F_36 0xC0011021
F_37 ( F_36 , 3 ) ;
F_37 ( F_36 , 14 ) ;
}
static T_4 void F_38 ( void )
{
struct V_8 * V_26 ;
T_2 V_74 ;
if ( V_37 . V_38 != 0x14 )
return;
if ( ! V_1 . V_2 )
return;
V_26 = F_3 ( 0 ) -> V_28 ;
if ( ! V_26 )
return;
if ( F_11 ( V_26 , 0x164 , & V_74 ) )
return;
if ( V_74 & F_39 ( 2 ) )
return;
F_40 ( F_35 , NULL , 0 ) ;
F_41 ( L_9 ) ;
}
static T_4 int F_42 ( void )
{
F_16 () ;
F_27 () ;
F_38 () ;
return 0 ;
}
