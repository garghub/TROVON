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
T_1 V_22 ;
struct V_5 * V_15 ;
F_7 (KERN_DEBUG PFX L_3 ) ;
V_15 = F_5 ( V_7 -> V_15 ) ;
F_10 ( V_7 -> V_8 , V_9 ,
V_15 -> V_13 ) ;
V_7 -> V_23 = F_12 ( V_7 -> V_8 ,
V_24 ) ;
F_8 ( V_7 -> V_8 , V_20 , 0x2280 ) ;
F_4 ( V_7 -> V_8 , V_21 , & V_22 ) ;
F_10 ( V_7 -> V_8 , V_21 ,
( V_22 & ~ ( 1 << 10 ) ) | ( 1 << 9 ) | ( 1 << 11 ) ) ;
F_13 ( V_7 -> V_8 , V_25 + 1 , 7 ) ;
return 0 ;
}
static int F_14 ( struct V_26 * V_27 )
{
int V_28 , V_29 = 0 ;
for ( V_28 = 0 ; V_28 < V_30 ; V_28 ++ ) {
unsigned long V_1 = V_31 . V_32 [ V_28 ] ;
if ( V_1 ) {
V_31 . V_32 [ V_28 ] = 0 ;
F_15 ( F_16 ( ( char * ) V_1 ) ) ;
F_17 ( V_1 ) ;
V_29 ++ ;
}
F_7 (KERN_DEBUG PFX L_4 ,
agp_bridge->dev, EFFICEON_ATTPAGE, index) ;
F_8 ( V_7 -> V_8 ,
V_33 , V_28 ) ;
}
F_7 (KERN_DEBUG PFX L_5 , freed) ;
return 0 ;
}
static int F_18 ( struct V_26 * V_27 )
{
int V_28 ;
const int V_34 = V_35 ;
const int V_36 = V_37 ;
const int V_38 = ( ( F_19 ( 1 ) >> 8 ) & 0xff ) << 3 ;
int V_39 , V_40 ;
V_39 = F_5 ( V_7 -> V_15 ) -> V_39 ;
F_7 (KERN_DEBUG PFX L_6 , num_entries) ;
F_20 ( V_39 & 0x3ff ) ;
V_40 = V_39 >> 10 ;
for ( V_28 = 0 ; V_28 < V_40 ; V_28 ++ ) {
int V_41 ;
unsigned long V_1 ;
unsigned long V_42 ;
V_1 = V_31 . V_32 [ V_28 ] ;
F_20 ( V_1 ) ;
V_1 = F_21 ( V_43 ) ;
if ( ! V_1 ) {
F_14 ( V_7 ) ;
return - V_44 ;
}
F_22 ( F_16 ( ( char * ) V_1 ) ) ;
for ( V_41 = 0 ; V_41 < V_45 ; V_41 += V_38 )
F_23 ( ( char * ) V_1 + V_41 ) ;
V_31 . V_32 [ V_28 ] = V_1 ;
V_42 = F_24 ( ( unsigned long * ) V_1 ) | V_34 | V_36 | V_28 ;
F_8 ( V_7 -> V_8 ,
V_33 , V_42 ) ;
}
return 0 ;
}
static int F_25 ( struct V_18 * V_19 , T_2 V_46 , int type )
{
int V_3 , V_47 = V_19 -> V_48 , V_39 ;
unsigned int * V_1 , * V_49 ;
const int V_38 = ( ( F_19 ( 1 ) >> 8 ) & 0xff ) << 3 ;
const unsigned long V_50 = ~ ( V_38 - 1 ) ;
F_7 (KERN_DEBUG PFX L_7 , pg_start, count) ;
V_39 = F_5 ( V_7 -> V_15 ) -> V_39 ;
if ( ( V_46 + V_19 -> V_48 ) > V_39 )
return - V_51 ;
if ( type != 0 || V_19 -> type != 0 )
return - V_51 ;
if ( ! V_19 -> V_52 ) {
F_26 () ;
V_19 -> V_52 = true ;
}
V_49 = NULL ;
for ( V_3 = 0 ; V_3 < V_47 ; V_3 ++ ) {
int V_28 = V_46 + V_3 ;
unsigned long V_53 = F_1 ( V_19 -> V_54 [ V_3 ] ) ;
V_1 = ( unsigned int * ) V_31 . V_32 [ V_28 >> 10 ] ;
if ( ! V_1 )
continue;
V_1 += ( V_28 & 0x3ff ) ;
* V_1 = V_53 ;
if ( V_49 &&
( ( ( unsigned long ) V_1 ^ ( unsigned long ) V_49 ) &
V_50 ) )
F_23 ( V_49 ) ;
V_49 = V_1 ;
}
if ( V_49 )
F_23 ( V_49 ) ;
V_7 -> V_10 -> V_55 ( V_19 ) ;
return 0 ;
}
static int F_27 ( struct V_18 * V_19 , T_2 V_46 , int type )
{
int V_3 , V_47 = V_19 -> V_48 , V_39 ;
F_7 (KERN_DEBUG PFX L_8 , pg_start, count) ;
V_39 = F_5 ( V_7 -> V_15 ) -> V_39 ;
if ( ( V_46 + V_19 -> V_48 ) > V_39 )
return - V_51 ;
if ( type != 0 || V_19 -> type != 0 )
return - V_51 ;
for ( V_3 = 0 ; V_3 < V_47 ; V_3 ++ ) {
int V_28 = V_46 + V_3 ;
unsigned int * V_1 = ( unsigned int * ) V_31 . V_32 [ V_28 >> 10 ] ;
if ( ! V_1 )
continue;
V_1 += ( V_28 & 0x3ff ) ;
* V_1 = 0 ;
}
V_7 -> V_10 -> V_55 ( V_19 ) ;
return 0 ;
}
static int F_28 ( struct V_56 * V_57 ,
const struct V_58 * V_59 )
{
struct V_26 * V_27 ;
T_3 V_60 ;
struct V_61 * V_62 ;
V_60 = F_29 ( V_57 , V_63 ) ;
if ( ! V_60 )
return - V_64 ;
if ( V_57 -> V_65 != V_66 ) {
F_7 (KERN_ERR PFX L_9 ,
pdev->device) ;
return - V_64 ;
}
F_7 (KERN_INFO PFX L_10 ) ;
V_27 = F_30 () ;
if ( ! V_27 )
return - V_44 ;
V_27 -> V_10 = & V_67 ;
V_27 -> V_8 = V_57 ;
V_27 -> V_68 = V_60 ;
if ( F_31 ( V_57 ) ) {
F_7 (KERN_ERR PFX L_11 ) ;
F_32 ( V_27 ) ;
return - V_64 ;
}
V_62 = & V_57 -> V_61 [ 0 ] ;
if ( ! V_62 -> V_69 && V_62 -> V_70 ) {
if ( F_33 ( V_57 , 0 ) ) {
F_7 (KERN_ERR PFX L_12 ) ;
F_32 ( V_27 ) ;
return - V_64 ;
}
}
if ( V_60 ) {
F_34 ( V_57 ,
V_27 -> V_68 + V_71 ,
& V_27 -> V_72 ) ;
}
F_35 ( V_57 , V_27 ) ;
return F_36 ( V_27 ) ;
}
static void F_37 ( struct V_56 * V_57 )
{
struct V_26 * V_27 = F_38 ( V_57 ) ;
F_39 ( V_27 ) ;
F_32 ( V_27 ) ;
}
static int F_40 ( struct V_56 * V_8 , T_4 V_73 )
{
return 0 ;
}
static int F_41 ( struct V_56 * V_57 )
{
F_7 (KERN_DEBUG PFX L_13 ) ;
return F_11 () ;
}
static int T_5 F_42 ( void )
{
static int V_74 = 0 ;
if ( V_75 )
return - V_51 ;
if ( V_74 == 1 )
return 0 ;
V_74 = 1 ;
return F_43 ( & V_76 ) ;
}
static void T_6 F_44 ( void )
{
F_45 ( & V_76 ) ;
}
