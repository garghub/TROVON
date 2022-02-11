static void F_1 ( const char * V_1 , struct V_2 V_3 )
{
char * V_4 , V_5 [ 16 + 3 + 64 + 1 ] ;
int V_6 ;
if ( ! V_7 )
return;
V_4 = V_5 ;
for ( V_6 = 0 ; V_6 < V_8 ; V_6 ++ )
* ( V_4 ++ ) = ( V_3 . V_9 & ( 1 << V_6 ) ) ? '1' : '0' ;
* ( V_4 ++ ) = ' ' ;
* ( V_4 ++ ) = '-' ;
* ( V_4 ++ ) = ' ' ;
for ( V_6 = 0 ; V_6 < V_10 ; V_6 ++ )
* ( V_4 ++ ) = ( V_3 . V_11 & ( 1ul << V_6 ) ) ? '1' : '0' ;
* ( V_4 ++ ) = 0 ;
F_2 ( V_12 L_1 , V_1 , V_5 ) ;
}
static void F_1 ( const char * V_1 , struct V_2 V_3 ) {}
static struct V_2 F_3 ( unsigned long V_13 ,
unsigned long V_14 )
{
unsigned long V_15 = V_13 + V_14 - 1 ;
struct V_2 V_16 = { 0 , 0 } ;
if ( V_13 < V_17 ) {
unsigned long V_18 = F_4 ( V_15 , V_17 ) ;
unsigned long V_19 = F_4 ( V_13 , V_17 ) ;
V_16 . V_9 = ( 1u << ( F_5 ( V_18 ) + 1 ) )
- ( 1u << F_5 ( V_19 ) ) ;
}
if ( ( V_13 + V_14 ) > V_17 )
V_16 . V_11 = ( 1ul << ( F_6 ( V_15 ) + 1 ) )
- ( 1ul << F_6 ( V_13 ) ) ;
return V_16 ;
}
static int F_7 ( struct V_20 * V_21 , unsigned long V_22 ,
unsigned long V_14 )
{
struct V_23 * V_24 ;
if ( ( V_21 -> V_25 - V_14 ) < V_22 )
return 0 ;
V_24 = F_8 ( V_21 , V_22 ) ;
return ( ! V_24 || ( V_22 + V_14 ) <= V_24 -> V_26 ) ;
}
static int F_9 ( struct V_20 * V_21 , unsigned long V_27 )
{
return ! F_7 ( V_21 , V_27 << V_28 ,
1ul << V_28 ) ;
}
static int F_10 ( struct V_20 * V_21 , unsigned long V_27 )
{
unsigned long V_13 = V_27 << V_29 ;
unsigned long V_15 = V_13 + ( 1ul << V_29 ) ;
if ( V_13 == 0 )
V_13 = V_17 ;
return ! F_7 ( V_21 , V_13 , V_15 - V_13 ) ;
}
static struct V_2 F_11 ( struct V_20 * V_21 )
{
struct V_2 V_16 = { 0 , 0 } ;
unsigned long V_6 ;
for ( V_6 = 0 ; V_6 < V_8 ; V_6 ++ )
if ( ! F_9 ( V_21 , V_6 ) )
V_16 . V_9 |= 1u << V_6 ;
if ( V_21 -> V_25 <= V_17 )
return V_16 ;
for ( V_6 = 0 ; V_6 < V_10 ; V_6 ++ )
if ( ! F_10 ( V_21 , V_6 ) )
V_16 . V_11 |= 1ul << V_6 ;
return V_16 ;
}
static struct V_2 F_12 ( struct V_20 * V_21 , int V_30 )
{
unsigned char * V_31 ;
int V_32 , V_33 ;
struct V_2 V_16 = { 0 , 0 } ;
unsigned long V_6 ;
T_1 V_34 ;
V_34 = V_21 -> V_35 . V_36 ;
for ( V_6 = 0 ; V_6 < V_8 ; V_6 ++ )
if ( ( ( V_34 >> ( V_6 * 4 ) ) & 0xf ) == V_30 )
V_16 . V_9 |= 1u << V_6 ;
V_31 = V_21 -> V_35 . V_37 ;
for ( V_6 = 0 ; V_6 < V_10 ; V_6 ++ ) {
V_33 = V_6 & 0x1 ;
V_32 = V_6 >> 1 ;
if ( ( ( V_31 [ V_32 ] >> ( V_33 * 4 ) ) & 0xf ) == V_30 )
V_16 . V_11 |= 1ul << V_6 ;
}
return V_16 ;
}
static int F_13 ( struct V_2 V_3 , struct V_2 V_38 )
{
return ( V_3 . V_9 & V_38 . V_9 ) == V_3 . V_9 &&
( V_3 . V_11 & V_38 . V_11 ) == V_3 . V_11 ;
}
static void F_14 ( void * V_39 )
{
struct V_20 * V_21 = V_39 ;
unsigned long V_40 ;
if ( V_21 != V_41 -> V_42 )
return;
F_15 () -> V_35 = V_41 -> V_42 -> V_35 ;
F_16 ( V_40 ) ;
F_17 () ;
F_18 ( V_40 ) ;
}
static void F_19 ( struct V_20 * V_21 , struct V_2 V_3 , int V_30 )
{
int V_32 , V_33 ;
unsigned char * V_31 ;
T_1 V_34 ;
unsigned long V_6 , V_40 ;
F_20 ( L_2 , V_21 , V_30 ) ;
F_1 ( L_3 , V_3 ) ;
F_21 ( & V_43 , V_40 ) ;
V_34 = V_21 -> V_35 . V_36 ;
for ( V_6 = 0 ; V_6 < V_8 ; V_6 ++ )
if ( V_3 . V_9 & ( 1u << V_6 ) )
V_34 = ( V_34 & ~ ( 0xful << ( V_6 * 4 ) ) ) |
( ( ( unsigned long ) V_30 ) << ( V_6 * 4 ) ) ;
V_21 -> V_35 . V_36 = V_34 ;
V_31 = V_21 -> V_35 . V_37 ;
for ( V_6 = 0 ; V_6 < V_10 ; V_6 ++ ) {
V_33 = V_6 & 0x1 ;
V_32 = V_6 >> 1 ;
if ( V_3 . V_11 & ( 1ul << V_6 ) )
V_31 [ V_32 ] = ( V_31 [ V_32 ] &
~ ( 0xf << ( V_33 * 4 ) ) ) |
( ( ( unsigned long ) V_30 ) << ( V_33 * 4 ) ) ;
}
F_20 ( L_4 ,
V_21 -> V_35 . V_36 ,
V_21 -> V_35 . V_37 ) ;
F_22 ( & V_43 , V_40 ) ;
#ifdef F_23
F_24 ( V_21 ) ;
#endif
}
static unsigned long F_25 ( struct V_20 * V_21 ,
unsigned long V_14 ,
struct V_2 V_38 ,
int V_30 , int V_44 )
{
struct V_23 * V_24 ;
unsigned long V_45 , V_22 ;
struct V_2 V_3 ;
int V_46 = F_26 ( int , V_47 [ V_30 ] . V_48 , V_49 ) ;
if ( V_44 ) {
if ( V_14 <= V_21 -> V_50 ) {
V_45 = V_22 = V_51 ;
V_21 -> V_50 = 0 ;
} else
V_45 = V_22 = V_21 -> V_52 ;
} else
V_45 = V_22 = V_51 ;
V_53:
for (; ; ) {
V_22 = F_27 ( V_22 , 1ul << V_46 ) ;
if ( ( V_54 - V_14 ) < V_22 )
break;
V_24 = F_8 ( V_21 , V_22 ) ;
F_28 ( V_24 && ( V_22 >= V_24 -> V_55 ) ) ;
V_3 = F_3 ( V_22 , V_14 ) ;
if ( ! F_13 ( V_3 , V_38 ) ) {
if ( V_22 < V_17 )
V_22 = F_27 ( V_22 + 1 , 1ul << V_28 ) ;
else
V_22 = F_27 ( V_22 + 1 , 1ul << V_29 ) ;
continue;
}
if ( ! V_24 || V_22 + V_14 <= V_24 -> V_26 ) {
if ( V_44 )
V_21 -> V_52 = V_22 + V_14 ;
return V_22 ;
}
if ( V_44 && ( V_22 + V_21 -> V_50 ) < V_24 -> V_26 )
V_21 -> V_50 = V_24 -> V_26 - V_22 ;
V_22 = V_24 -> V_55 ;
}
if ( V_44 && V_45 != V_51 ) {
V_45 = V_22 = V_51 ;
V_21 -> V_50 = 0 ;
goto V_53;
}
return - V_56 ;
}
static unsigned long F_29 ( struct V_20 * V_21 ,
unsigned long V_14 ,
struct V_2 V_38 ,
int V_30 , int V_44 )
{
struct V_23 * V_24 ;
unsigned long V_22 ;
struct V_2 V_3 ;
int V_46 = F_26 ( int , V_47 [ V_30 ] . V_48 , V_49 ) ;
if ( V_44 ) {
if ( V_14 <= V_21 -> V_50 ) {
V_21 -> V_50 = 0 ;
V_21 -> V_52 = V_21 -> V_57 ;
}
V_22 = V_21 -> V_52 ;
if ( V_22 > V_14 ) {
V_22 = F_30 ( V_22 - V_14 , 1ul << V_46 ) ;
V_3 = F_3 ( V_22 , V_14 ) ;
if ( F_13 ( V_3 , V_38 ) &&
F_7 ( V_21 , V_22 , V_14 ) )
return ( V_21 -> V_52 = V_22 ) ;
}
}
V_22 = V_21 -> V_57 ;
while ( V_22 > V_14 ) {
V_22 = F_30 ( V_22 - V_14 , 1ul << V_46 ) ;
V_3 = F_3 ( V_22 , V_14 ) ;
if ( ! F_13 ( V_3 , V_38 ) ) {
if ( V_22 < V_17 )
V_22 = F_30 ( V_22 , 1ul << V_28 ) ;
else if ( V_22 < ( 1ul << V_29 ) )
V_22 = V_17 ;
else
V_22 = F_30 ( V_22 , 1ul << V_29 ) ;
continue;
}
V_24 = F_8 ( V_21 , V_22 ) ;
if ( ! V_24 || ( V_22 + V_14 ) <= V_24 -> V_26 ) {
if ( V_44 )
V_21 -> V_52 = V_22 ;
return V_22 ;
}
if ( V_44 && ( V_22 + V_21 -> V_50 ) < V_24 -> V_26 )
V_21 -> V_50 = V_24 -> V_26 - V_22 ;
V_22 = V_24 -> V_26 ;
}
V_22 = F_25 ( V_21 , V_14 , V_38 , V_30 , 0 ) ;
if ( V_44 ) {
V_21 -> V_52 = V_21 -> V_57 ;
V_21 -> V_50 = ~ 0UL ;
}
return V_22 ;
}
static unsigned long F_31 ( struct V_20 * V_21 , unsigned long V_14 ,
struct V_2 V_3 , int V_30 ,
int V_58 , int V_44 )
{
if ( V_58 )
return F_29 ( V_21 , V_14 , V_3 , V_30 , V_44 ) ;
else
return F_25 ( V_21 , V_14 , V_3 , V_30 , V_44 ) ;
}
unsigned long F_32 ( unsigned long V_22 , unsigned long V_14 ,
unsigned long V_40 , unsigned int V_30 ,
int V_58 , int V_44 )
{
struct V_2 V_3 = { 0 , 0 } ;
struct V_2 V_59 ;
struct V_2 V_60 = { 0 , 0 } ;
struct V_2 V_61 = { 0 , 0 } ;
int V_62 = ( V_40 & V_63 ) ;
int V_46 = F_26 ( int , V_47 [ V_30 ] . V_48 , V_49 ) ;
struct V_20 * V_21 = V_41 -> V_21 ;
unsigned long V_64 ;
F_28 ( V_21 -> V_25 == 0 ) ;
F_20 ( L_5 , V_21 , V_30 ) ;
F_20 ( L_6 ,
V_22 , V_14 , V_40 , V_58 , V_44 ) ;
if ( V_14 > V_21 -> V_25 )
return - V_56 ;
if ( V_14 & ( ( 1ul << V_46 ) - 1 ) )
return - V_65 ;
if ( V_62 && ( V_22 & ( ( 1ul << V_46 ) - 1 ) ) )
return - V_65 ;
if ( V_62 && V_22 > ( V_21 -> V_25 - V_14 ) )
return - V_65 ;
if ( ! V_62 && V_22 ) {
V_22 = F_27 ( V_22 , 1ul << V_46 ) ;
F_20 ( L_7 , V_22 ) ;
if ( V_22 > V_21 -> V_25 - V_14 ||
! F_7 ( V_21 , V_22 , V_14 ) )
V_22 = 0 ;
}
V_59 = F_12 ( V_21 , V_30 ) ;
F_1 ( L_8 , V_59 ) ;
#ifdef F_33
if ( V_30 == V_66 ) {
V_61 = F_12 ( V_21 , V_67 ) ;
if ( V_62 )
F_34 ( V_59 , V_61 ) ;
}
#endif
if ( V_22 != 0 || V_62 ) {
V_3 = F_3 ( V_22 , V_14 ) ;
F_1 ( L_3 , V_3 ) ;
if ( F_13 ( V_3 , V_59 ) ) {
F_20 ( L_9 ) ;
return V_22 ;
}
} else {
V_64 = F_31 ( V_21 , V_14 , V_59 , V_30 , V_58 ,
V_44 ) ;
if ( V_64 != - V_56 ) {
F_20 ( L_10 , V_64 ) ;
return V_64 ;
}
}
V_60 = F_11 ( V_21 ) ;
F_34 ( V_60 , V_59 ) ;
F_1 ( L_11 , V_60 ) ;
if ( ( V_22 != 0 || V_62 ) && F_13 ( V_3 , V_60 ) ) {
F_20 ( L_12 ) ;
goto V_68;
}
if ( V_62 )
return - V_69 ;
F_20 ( L_13 ) ;
if ( V_22 ) {
V_22 = F_31 ( V_21 , V_14 , V_59 , V_30 , V_58 ,
V_44 ) ;
if ( V_22 != - V_56 ) {
F_20 ( L_10 , V_22 ) ;
return V_22 ;
}
}
V_22 = F_31 ( V_21 , V_14 , V_60 , V_30 , V_58 ,
V_44 ) ;
#ifdef F_33
if ( V_22 == - V_56 && V_30 == V_66 ) {
F_34 ( V_60 , V_61 ) ;
V_22 = F_31 ( V_21 , V_14 , V_60 , V_30 ,
V_58 , V_44 ) ;
}
#endif
if ( V_22 == - V_56 )
return - V_56 ;
V_3 = F_3 ( V_22 , V_14 ) ;
F_20 ( L_14 , V_22 ) ;
F_1 ( L_3 , V_3 ) ;
V_68:
F_35 ( V_3 , V_59 ) ;
F_35 ( V_3 , V_61 ) ;
if ( V_3 . V_9 || V_3 . V_11 ) {
F_19 ( V_21 , V_3 , V_30 ) ;
if ( V_30 > V_70 )
F_36 ( F_14 , V_21 , 1 ) ;
}
return V_22 ;
}
unsigned long F_37 ( struct V_71 * V_72 ,
unsigned long V_22 ,
unsigned long V_14 ,
unsigned long V_73 ,
unsigned long V_40 )
{
return F_32 ( V_22 , V_14 , V_40 ,
V_41 -> V_21 -> V_35 . V_74 ,
0 , 1 ) ;
}
unsigned long F_38 ( struct V_71 * V_72 ,
const unsigned long V_75 ,
const unsigned long V_14 ,
const unsigned long V_73 ,
const unsigned long V_40 )
{
return F_32 ( V_75 , V_14 , V_40 ,
V_41 -> V_21 -> V_35 . V_74 ,
1 , 1 ) ;
}
unsigned int F_39 ( struct V_20 * V_21 , unsigned long V_22 )
{
unsigned char * V_31 ;
int V_32 , V_33 ;
if ( V_22 < V_17 ) {
T_1 V_34 ;
V_34 = V_21 -> V_35 . V_36 ;
V_32 = F_5 ( V_22 ) ;
return ( V_34 >> ( V_32 * 4 ) ) & 0xf ;
}
V_31 = V_21 -> V_35 . V_37 ;
V_32 = F_6 ( V_22 ) ;
V_33 = V_32 & 0x1 ;
return ( V_31 [ V_32 >> 1 ] >> ( V_33 * 4 ) ) & 0xf ;
}
void F_40 ( struct V_20 * V_21 , unsigned int V_30 )
{
int V_32 , V_33 ;
unsigned char * V_31 ;
unsigned long V_40 , V_34 ;
unsigned int V_76 ;
int V_6 ;
F_20 ( L_15 , V_21 , V_30 ) ;
F_21 ( & V_43 , V_40 ) ;
V_76 = V_21 -> V_35 . V_74 ;
F_20 ( L_16 , V_76 ) ;
if ( V_76 == V_30 )
goto V_77;
V_21 -> V_35 . V_74 = V_30 ;
F_41 () ;
V_34 = V_21 -> V_35 . V_36 ;
for ( V_6 = 0 ; V_6 < V_8 ; V_6 ++ )
if ( ( ( V_34 >> ( V_6 * 4 ) ) & 0xf ) == V_76 )
V_34 = ( V_34 & ~ ( 0xful << ( V_6 * 4 ) ) ) |
( ( ( unsigned long ) V_30 ) << ( V_6 * 4 ) ) ;
V_21 -> V_35 . V_36 = V_34 ;
V_31 = V_21 -> V_35 . V_37 ;
for ( V_6 = 0 ; V_6 < V_10 ; V_6 ++ ) {
V_33 = V_6 & 0x1 ;
V_32 = V_6 >> 1 ;
if ( ( ( V_31 [ V_32 ] >> ( V_33 * 4 ) ) & 0xf ) == V_76 )
V_31 [ V_32 ] = ( V_31 [ V_32 ] &
~ ( 0xf << ( V_33 * 4 ) ) ) |
( ( ( unsigned long ) V_30 ) << ( V_33 * 4 ) ) ;
}
F_20 ( L_4 ,
V_21 -> V_35 . V_36 ,
V_21 -> V_35 . V_37 ) ;
V_77:
F_22 ( & V_43 , V_40 ) ;
}
void F_42 ( struct V_20 * V_21 , unsigned long V_78 ,
unsigned int V_30 )
{
unsigned char * V_31 ;
unsigned long V_6 , V_40 ;
T_1 * V_34 ;
F_21 ( & V_43 , V_40 ) ;
if ( V_78 < V_17 ) {
V_6 = F_5 ( V_78 ) ;
V_34 = & V_21 -> V_35 . V_36 ;
* V_34 = ( * V_34 & ~ ( 0xful << ( V_6 * 4 ) ) ) |
( ( unsigned long ) V_30 << ( V_6 * 4 ) ) ;
} else {
int V_32 , V_33 ;
V_6 = F_6 ( V_78 ) ;
V_31 = V_21 -> V_35 . V_37 ;
V_33 = V_6 & 0x1 ;
V_32 = V_6 >> 1 ;
V_31 [ V_32 ] = ( V_31 [ V_32 ] &
~ ( 0xf << ( V_33 * 4 ) ) ) |
( ( ( unsigned long ) V_30 ) << ( V_33 * 4 ) ) ;
}
F_22 ( & V_43 , V_40 ) ;
#ifdef F_23
F_24 ( V_21 ) ;
#endif
}
void F_43 ( struct V_20 * V_21 , unsigned long V_13 ,
unsigned long V_14 , unsigned int V_30 )
{
struct V_2 V_3 = F_3 ( V_13 , V_14 ) ;
F_19 ( V_21 , V_3 , V_30 ) ;
}
int F_44 ( struct V_20 * V_21 , unsigned long V_22 ,
unsigned long V_14 )
{
struct V_2 V_3 , V_38 ;
unsigned int V_30 = V_21 -> V_35 . V_74 ;
V_3 = F_3 ( V_22 , V_14 ) ;
V_38 = F_12 ( V_21 , V_30 ) ;
#ifdef F_33
if ( V_30 == V_66 ) {
struct V_2 V_61 ;
V_61 = F_12 ( V_21 , V_67 ) ;
F_34 ( V_38 , V_61 ) ;
}
#endif
#if 0
slice_dbg("is_hugepage_only_range(mm=%p, addr=%lx, len=%lx)\n",
mm, addr, len);
slice_print_mask(" mask", mask);
slice_print_mask(" available", available);
#endif
return ! F_13 ( V_3 , V_38 ) ;
}
