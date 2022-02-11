static inline unsigned long F_1 ( struct V_1 * V_1 )
{
unsigned long V_2 = F_2 ( V_1 ) ;
return V_2 | 0x00000001 ;
}
static int F_3 ( void )
{
int V_3 ;
T_1 V_4 ;
struct V_5 * V_6 ;
F_4 ( V_7 -> V_8 , V_9 , & V_4 ) ;
V_6 = F_5 ( V_7 -> V_10 -> V_11 ) ;
for ( V_3 = 0 ; V_3 < V_7 -> V_10 -> V_12 ; V_3 ++ ) {
if ( V_4 == V_6 [ V_3 ] . V_13 ) {
V_7 -> V_14 =
V_7 -> V_15 = ( void * ) ( V_6 + V_3 ) ;
V_7 -> V_16 = V_3 ;
return V_6 [ V_3 ] . V_17 ;
}
}
return 0 ;
}
static void F_6 ( struct V_18 * V_19 )
{
F_7 (KERN_DEBUG PFX L_1 ) ;
F_8 ( V_7 -> V_8 , V_20 , 0x2200 ) ;
F_8 ( V_7 -> V_8 , V_20 , 0x2280 ) ;
}
static void F_9 ( void )
{
T_1 V_4 ;
struct V_5 * V_14 ;
F_7 (KERN_DEBUG PFX L_2 ) ;
V_14 = F_5 ( V_7 -> V_14 ) ;
F_4 ( V_7 -> V_8 , V_21 , & V_4 ) ;
F_10 ( V_7 -> V_8 , V_21 , V_4 & ~ ( 1 << 9 ) ) ;
F_10 ( V_7 -> V_8 , V_9 ,
V_14 -> V_13 ) ;
}
static int F_11 ( void )
{
T_2 V_4 ;
T_1 V_22 ;
struct V_5 * V_15 ;
F_7 (KERN_DEBUG PFX L_3 ) ;
V_15 = F_5 ( V_7 -> V_15 ) ;
F_10 ( V_7 -> V_8 , V_9 ,
V_15 -> V_13 ) ;
F_12 ( V_7 -> V_8 , V_23 , & V_4 ) ;
V_7 -> V_24 = ( V_4 & V_25 ) ;
F_8 ( V_7 -> V_8 , V_20 , 0x2280 ) ;
F_4 ( V_7 -> V_8 , V_21 , & V_22 ) ;
F_10 ( V_7 -> V_8 , V_21 ,
( V_22 & ~ ( 1 << 10 ) ) | ( 1 << 9 ) | ( 1 << 11 ) ) ;
F_13 ( V_7 -> V_8 , V_26 + 1 , 7 ) ;
return 0 ;
}
static int F_14 ( struct V_27 * V_28 )
{
int V_29 , V_30 = 0 ;
for ( V_29 = 0 ; V_29 < V_31 ; V_29 ++ ) {
unsigned long V_1 = V_32 . V_33 [ V_29 ] ;
if ( V_1 ) {
V_32 . V_33 [ V_29 ] = 0 ;
F_15 ( F_16 ( ( char * ) V_1 ) ) ;
F_17 ( V_1 ) ;
V_30 ++ ;
}
F_7 (KERN_DEBUG PFX L_4 ,
agp_bridge->dev, EFFICEON_ATTPAGE, index) ;
F_8 ( V_7 -> V_8 ,
V_34 , V_29 ) ;
}
F_7 (KERN_DEBUG PFX L_5 , freed) ;
return 0 ;
}
static int F_18 ( struct V_27 * V_28 )
{
int V_29 ;
const int V_35 = V_36 ;
const int V_37 = V_38 ;
const int V_39 = ( ( F_19 ( 1 ) >> 8 ) & 0xff ) << 3 ;
int V_40 , V_41 ;
V_40 = F_5 ( V_7 -> V_15 ) -> V_40 ;
F_7 (KERN_DEBUG PFX L_6 , num_entries) ;
F_20 ( V_40 & 0x3ff ) ;
V_41 = V_40 >> 10 ;
for ( V_29 = 0 ; V_29 < V_41 ; V_29 ++ ) {
int V_42 ;
unsigned long V_1 ;
unsigned long V_43 ;
V_1 = V_32 . V_33 [ V_29 ] ;
F_20 ( V_1 ) ;
V_1 = F_21 ( V_44 ) ;
if ( ! V_1 ) {
F_14 ( V_7 ) ;
return - V_45 ;
}
F_22 ( F_16 ( ( char * ) V_1 ) ) ;
for ( V_42 = 0 ; V_42 < V_46 ; V_42 += V_39 )
F_23 ( ( char * ) V_1 + V_42 ) ;
V_32 . V_33 [ V_29 ] = V_1 ;
V_43 = F_24 ( ( unsigned long * ) V_1 ) | V_35 | V_37 | V_29 ;
F_8 ( V_7 -> V_8 ,
V_34 , V_43 ) ;
}
return 0 ;
}
static int F_25 ( struct V_18 * V_19 , T_3 V_47 , int type )
{
int V_3 , V_48 = V_19 -> V_49 , V_40 ;
unsigned int * V_1 , * V_50 ;
const int V_39 = ( ( F_19 ( 1 ) >> 8 ) & 0xff ) << 3 ;
const unsigned long V_51 = ~ ( V_39 - 1 ) ;
F_7 (KERN_DEBUG PFX L_7 , pg_start, count) ;
V_40 = F_5 ( V_7 -> V_15 ) -> V_40 ;
if ( ( V_47 + V_19 -> V_49 ) > V_40 )
return - V_52 ;
if ( type != 0 || V_19 -> type != 0 )
return - V_52 ;
if ( ! V_19 -> V_53 ) {
F_26 () ;
V_19 -> V_53 = true ;
}
V_50 = NULL ;
for ( V_3 = 0 ; V_3 < V_48 ; V_3 ++ ) {
int V_29 = V_47 + V_3 ;
unsigned long V_54 = F_1 ( V_19 -> V_55 [ V_3 ] ) ;
V_1 = ( unsigned int * ) V_32 . V_33 [ V_29 >> 10 ] ;
if ( ! V_1 )
continue;
V_1 += ( V_29 & 0x3ff ) ;
* V_1 = V_54 ;
if ( V_50 &&
( ( ( unsigned long ) V_1 ^ ( unsigned long ) V_50 ) &
V_51 ) )
F_23 ( V_50 ) ;
V_50 = V_1 ;
}
if ( V_50 )
F_23 ( V_50 ) ;
V_7 -> V_10 -> V_56 ( V_19 ) ;
return 0 ;
}
static int F_27 ( struct V_18 * V_19 , T_3 V_47 , int type )
{
int V_3 , V_48 = V_19 -> V_49 , V_40 ;
F_7 (KERN_DEBUG PFX L_8 , pg_start, count) ;
V_40 = F_5 ( V_7 -> V_15 ) -> V_40 ;
if ( ( V_47 + V_19 -> V_49 ) > V_40 )
return - V_52 ;
if ( type != 0 || V_19 -> type != 0 )
return - V_52 ;
for ( V_3 = 0 ; V_3 < V_48 ; V_3 ++ ) {
int V_29 = V_47 + V_3 ;
unsigned int * V_1 = ( unsigned int * ) V_32 . V_33 [ V_29 >> 10 ] ;
if ( ! V_1 )
continue;
V_1 += ( V_29 & 0x3ff ) ;
* V_1 = 0 ;
}
V_7 -> V_10 -> V_56 ( V_19 ) ;
return 0 ;
}
static int T_4 F_28 ( struct V_57 * V_58 ,
const struct V_59 * V_60 )
{
struct V_27 * V_28 ;
T_5 V_61 ;
struct V_62 * V_63 ;
V_61 = F_29 ( V_58 , V_64 ) ;
if ( ! V_61 )
return - V_65 ;
if ( V_58 -> V_66 != V_67 ) {
F_7 (KERN_ERR PFX L_9 ,
pdev->device) ;
return - V_65 ;
}
F_7 (KERN_INFO PFX L_10 ) ;
V_28 = F_30 () ;
if ( ! V_28 )
return - V_45 ;
V_28 -> V_10 = & V_68 ;
V_28 -> V_8 = V_58 ;
V_28 -> V_69 = V_61 ;
if ( F_31 ( V_58 ) ) {
F_7 (KERN_ERR PFX L_11 ) ;
F_32 ( V_28 ) ;
return - V_65 ;
}
V_63 = & V_58 -> V_62 [ 0 ] ;
if ( ! V_63 -> V_70 && V_63 -> V_71 ) {
if ( F_33 ( V_58 , 0 ) ) {
F_7 (KERN_ERR PFX L_12 ) ;
F_32 ( V_28 ) ;
return - V_65 ;
}
}
if ( V_61 ) {
F_12 ( V_58 ,
V_28 -> V_69 + V_72 ,
& V_28 -> V_73 ) ;
}
F_34 ( V_58 , V_28 ) ;
return F_35 ( V_28 ) ;
}
static void T_6 F_36 ( struct V_57 * V_58 )
{
struct V_27 * V_28 = F_37 ( V_58 ) ;
F_38 ( V_28 ) ;
F_32 ( V_28 ) ;
}
static int F_39 ( struct V_57 * V_8 , T_7 V_74 )
{
return 0 ;
}
static int F_40 ( struct V_57 * V_58 )
{
F_7 (KERN_DEBUG PFX L_13 ) ;
return F_11 () ;
}
static int T_8 F_41 ( void )
{
static int V_75 = 0 ;
if ( V_76 )
return - V_52 ;
if ( V_75 == 1 )
return 0 ;
V_75 = 1 ;
return F_42 ( & V_77 ) ;
}
static void T_9 F_43 ( void )
{
F_44 ( & V_77 ) ;
}
