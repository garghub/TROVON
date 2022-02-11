static void T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
T_2 * V_5 , * V_6 ;
V_4 = F_2 ( sizeof( struct V_3 ) , V_7 ) ;
if ( ! V_4 ) {
F_3 ( L_1 ) ;
F_4 () ;
}
V_4 -> V_8 [ 0 ] = V_9 ;
V_4 -> V_8 [ 1 ] = V_10 ;
V_4 -> V_8 [ 2 ] = V_11 ;
V_4 -> V_8 [ 3 ] = V_12 ;
V_4 -> V_13 [ 1 ] = V_10 ;
V_4 -> V_13 [ 2 ] = V_11 ;
V_5 = F_5 ( & V_2 -> V_14 [ 2 ] , 0 , V_15 * 16 , L_2 ) ;
if ( ! V_5 ) {
F_3 ( L_3 ) ;
F_4 () ;
}
V_2 -> V_16 . V_17 . V_18 = V_4 ;
V_4 -> V_19 = V_5 ;
F_6 ( & V_4 -> V_20 ) ;
for ( V_6 = V_4 -> V_19 + ( 16 * V_15 ) / sizeof( T_2 ) ;
V_5 < V_6 ; )
F_7 ( * V_5 ++ ) = 0 ;
}
static int T_1 F_8 ( void )
{
extern void V_21 ( void ) ;
struct V_22 * V_23 ;
F_9 (dp, L_4 ) {
struct V_1 * V_2 = F_10 ( V_23 ) ;
F_1 ( V_2 ) ;
F_11 ( V_2 ) ;
}
V_21 () ;
return 0 ;
}
static unsigned long F_12 ( struct V_3 * V_4 , unsigned long V_24 , int V_25 )
{
int V_26 , V_27 , V_28 , V_29 ;
unsigned long V_13 , V_30 , V_8 ;
T_2 V_31 ;
V_29 = ( ( V_24 & ~ V_32 ) + V_25 + ( V_15 - 1 ) ) >> V_33 ;
switch ( V_29 ) {
case 1 : V_26 = 0x0231 ; break;
case 2 : V_26 = 0x0132 ; break;
default: V_26 = 0x0213 ; break;
}
F_13 ( ( L_5 , V_24 , V_25 , V_29 ) ) ;
V_34: V_27 = ( V_26 & 15 ) ;
V_13 = V_4 -> V_13 [ V_27 - 1 ] ;
V_8 = V_4 -> V_8 [ V_27 ] ;
V_30 = V_13 ;
V_35: V_30 = F_14 ( V_4 -> V_36 , V_8 , V_30 ) ;
if ( V_30 + V_29 > V_8 ) {
if ( V_8 != V_13 ) {
V_8 = V_13 ;
V_30 = V_4 -> V_8 [ V_27 - 1 ] ;
goto V_35;
}
V_26 >>= 4 ;
if ( ! ( V_26 & 15 ) )
F_15 ( L_6 , V_24 , V_25 ) ;
goto V_34;
}
for ( V_28 = 1 , V_30 ++ ; V_28 < V_29 ; V_28 ++ )
if ( F_16 ( V_30 ++ , V_4 -> V_36 ) )
goto V_35;
V_4 -> V_13 [ V_27 - 1 ] = ( V_30 < V_8 ) ? V_30 : V_4 -> V_8 [ V_27 - 1 ] ;
V_30 -= V_29 ;
V_31 = F_17 ( F_18 ( V_24 & V_32 ) ) ;
V_24 = V_37 + ( V_30 << V_33 ) + ( V_24 & ~ V_32 ) ;
for ( V_28 = 0 ; V_28 < V_29 ; V_28 ++ , V_31 = F_19 ( F_7 ( V_31 ) + 0x100 ) , V_30 ++ ) {
F_20 ( V_30 , V_4 -> V_36 ) ;
V_4 -> V_19 [ V_30 ] = V_31 ;
}
F_13 ( ( L_7 , V_24 ) ) ;
return V_24 ;
}
static T_3 F_21 ( struct V_38 * V_16 , char * V_24 , unsigned long V_39 )
{
struct V_3 * V_4 = V_16 -> V_17 . V_18 ;
unsigned long V_40 , V_41 ;
F_22 ( & V_4 -> V_20 , V_41 ) ;
V_40 = F_12 ( V_4 , ( unsigned long ) V_24 , V_39 ) ;
F_23 ( & V_4 -> V_20 , V_41 ) ;
return V_40 ;
}
static void F_24 ( struct V_38 * V_16 , struct V_42 * V_43 , int V_44 )
{
struct V_3 * V_4 = V_16 -> V_17 . V_18 ;
unsigned long V_41 ;
F_22 ( & V_4 -> V_20 , V_41 ) ;
while ( V_44 != 0 ) {
-- V_44 ;
V_43 -> V_45 = F_12 ( V_4 , ( unsigned long ) F_25 ( V_43 ) , V_43 -> V_46 ) ;
V_43 -> V_47 = V_43 -> V_46 ;
V_43 = F_26 ( V_43 ) ;
}
F_23 ( & V_4 -> V_20 , V_41 ) ;
}
static void F_27 ( struct V_38 * V_16 , T_3 V_24 , unsigned long V_39 )
{
struct V_3 * V_4 = V_16 -> V_17 . V_18 ;
unsigned long V_41 ;
F_22 ( & V_4 -> V_20 , V_41 ) ;
V_39 = ( ( V_24 & ~ V_32 ) + V_39 + ( V_15 - 1 ) ) >> V_33 ;
V_24 = ( V_24 - V_37 ) >> V_33 ;
F_13 ( ( L_8 , ( long ) V_24 , ( long ) V_39 + V_24 ) ) ;
for ( V_39 += V_24 ; V_24 < V_39 ; V_24 ++ )
F_28 ( V_24 , V_4 -> V_36 ) ;
F_23 ( & V_4 -> V_20 , V_41 ) ;
}
static void F_29 ( struct V_38 * V_16 , struct V_42 * V_43 , int V_44 )
{
struct V_3 * V_4 = V_16 -> V_17 . V_18 ;
unsigned long V_41 ;
unsigned long V_24 , V_39 ;
F_22 ( & V_4 -> V_20 , V_41 ) ;
while ( V_44 != 0 ) {
-- V_44 ;
V_39 = ( ( V_43 -> V_45 & ~ V_32 ) + V_43 -> V_46 + ( V_15 - 1 ) ) >> V_33 ;
V_24 = ( V_43 -> V_45 - V_37 ) >> V_33 ;
F_13 ( ( L_8 , ( long ) V_24 , ( long ) V_39 + V_24 ) ) ;
for ( V_39 += V_24 ; V_24 < V_39 ; V_24 ++ )
F_28 ( V_24 , V_4 -> V_36 ) ;
V_43 = F_26 ( V_43 ) ;
}
F_23 ( & V_4 -> V_20 , V_41 ) ;
}
static int F_30 ( struct V_38 * V_16 , T_4 * V_48 , unsigned long V_49 , T_3 V_50 , int V_39 )
{
struct V_3 * V_4 = V_16 -> V_17 . V_18 ;
unsigned long V_51 , V_52 ;
T_5 V_53 ;
T_2 * V_31 ;
* V_48 = V_50 ;
V_53 = F_31 ( V_54 | V_55 | V_56 ) ;
V_52 = F_32 ( ( V_50 + V_39 ) ) ;
while( V_50 < V_52 ) {
V_51 = V_49 ;
{
T_6 * V_57 ;
T_7 * V_58 ;
T_8 * V_59 ;
long V_26 ;
V_57 = F_33 ( & V_60 , V_50 ) ;
V_58 = F_34 ( V_57 , V_50 ) ;
V_59 = F_35 ( V_58 , V_50 ) ;
F_36 ( V_59 , F_37 ( F_38 ( V_51 ) , V_53 ) ) ;
V_26 = ( ( V_50 - V_37 ) >> V_33 ) ;
V_31 = ( T_2 * ) ( V_4 -> V_19 + V_26 ) ;
* V_31 = F_17 ( F_18 ( V_51 ) ) ;
}
V_50 += V_15 ;
V_49 += V_15 ;
}
F_39 () ;
F_40 () ;
return 0 ;
}
static void F_41 ( struct V_38 * V_16 , unsigned long V_50 , int V_39 )
{
}
static char * F_42 ( char * V_24 , unsigned long V_39 )
{
return V_24 ;
}
static void F_43 ( char * V_24 , unsigned long V_39 )
{
}
void T_1 F_44 ( void )
{
F_45 ( V_61 , F_42 , V_62 ) ;
F_45 ( V_63 , F_43 , V_64 ) ;
F_45 ( V_65 , F_21 , V_66 ) ;
F_45 ( V_67 , F_24 , V_66 ) ;
F_45 ( V_68 , F_27 , V_66 ) ;
F_45 ( V_69 , F_29 , V_66 ) ;
#ifdef F_46
F_45 ( V_70 , F_30 , V_66 ) ;
F_45 ( V_71 , F_41 , V_66 ) ;
#endif
}
