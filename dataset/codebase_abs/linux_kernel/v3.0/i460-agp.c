static int F_1 ( void )
{
int V_1 ;
T_1 V_2 ;
struct V_3 * V_4 ;
F_2 ( V_5 -> V_6 , V_7 , & V_2 ) ;
V_8 . V_9 = ( V_2 & V_10 ) ? 22 : 12 ;
F_3 ( L_1 , V_8 . V_9 ) ;
if ( V_8 . V_9 != V_11 ) {
F_4 (KERN_ERR PFX
L_2
L_3 ,
1UL << (i460.io_page_shift - 10),
1UL << (I460_IO_PAGE_SHIFT)) ;
return 0 ;
}
V_4 = F_5 ( V_5 -> V_12 -> V_13 ) ;
F_2 ( V_5 -> V_6 , V_14 , & V_2 ) ;
if ( V_2 & V_15 ) {
F_4 (KERN_ERR PFX L_4 ) ;
F_4 (KERN_ERR PFX L_5 ) ;
return 0 ;
}
if ( ( V_8 . V_9 == 0 ) && ( ( V_2 & V_16 ) == 4 ) ) {
F_4 (KERN_ERR PFX L_6 ) ;
return 0 ;
}
if ( V_2 & V_17 )
V_8 . V_18 = V_19 ;
else
V_8 . V_18 = V_20 ;
for ( V_1 = 0 ; V_1 < V_5 -> V_12 -> V_21 ; V_1 ++ ) {
V_4 [ V_1 ] . V_22 = ( V_4 [ V_1 ] . V_23 << 8 ) >> ( V_11 - 12 ) ;
V_4 [ V_1 ] . V_24 = F_6 ( ( sizeof( V_25 ) * V_4 [ V_1 ] . V_22 ) >> V_26 ) ;
}
for ( V_1 = 0 ; V_1 < V_5 -> V_12 -> V_21 ; V_1 ++ ) {
if ( ( V_2 & V_16 ) == V_4 [ V_1 ] . V_27 ) {
V_5 -> V_28 = V_5 -> V_29 = ( void * ) ( V_4 + V_1 ) ;
V_5 -> V_30 = V_1 ;
return V_4 [ V_1 ] . V_23 ;
}
}
return 0 ;
}
static void F_7 ( struct V_31 * V_32 )
{
return;
}
static void F_8 ( T_1 V_27 )
{
T_1 V_2 ;
F_2 ( V_5 -> V_6 , V_14 , & V_2 ) ;
F_9 ( V_5 -> V_6 , V_14 ,
( ( V_2 & ~ V_16 ) | V_27 ) ) ;
}
static void F_10 ( void )
{
struct V_3 * V_28 ;
V_28 = F_5 ( V_5 -> V_28 ) ;
F_8 ( V_28 -> V_27 ) ;
if ( V_11 > V_26 )
F_11 ( V_8 . V_33 ) ;
}
static int F_12 ( void )
{
union {
V_25 V_34 [ 2 ] ;
T_2 V_35 ;
} V_2 ;
T_3 V_23 ;
T_1 V_36 ;
struct V_3 * V_29 ;
V_2 . V_35 = 0 ;
V_29 = F_5 ( V_5 -> V_29 ) ;
F_8 ( V_29 -> V_27 ) ;
F_13 ( V_5 -> V_6 , V_8 . V_18 , & ( V_2 . V_34 [ 0 ] ) ) ;
F_13 ( V_5 -> V_6 , V_8 . V_18 + 4 , & ( V_2 . V_34 [ 1 ] ) ) ;
V_5 -> V_37 = V_2 . V_35 & ~ ( ( 1UL << 3 ) - 1 ) ;
F_2 ( V_5 -> V_6 , V_7 , & V_36 ) ;
F_9 ( V_5 -> V_6 , V_7 ,
( V_36 & 0x02 ) | V_38 | V_39 ) ;
if ( V_11 > V_26 ) {
V_23 = V_29 -> V_22 * sizeof( V_8 . V_33 [ 0 ] ) ;
V_8 . V_33 = F_14 ( V_23 , V_40 ) ;
if ( ! V_8 . V_33 )
return - V_41 ;
}
return 0 ;
}
static int F_15 ( struct V_42 * V_43 )
{
int V_24 , V_22 , V_1 ;
void * V_2 ;
V_2 = V_5 -> V_29 ;
V_24 = F_5 ( V_2 ) -> V_24 ;
V_22 = F_5 ( V_2 ) -> V_22 ;
V_8 . V_44 = F_16 ( V_45 , V_46 << V_24 ) ;
if ( ! V_8 . V_44 ) {
F_4 (KERN_ERR PFX L_7 ) ;
return - V_41 ;
}
V_5 -> V_47 = NULL ;
V_5 -> V_48 = NULL ;
V_5 -> V_49 = 0 ;
for ( V_1 = 0 ; V_1 < V_22 ; ++ V_1 )
F_17 ( V_1 , 0 ) ;
F_18 ( V_1 - 1 ) ;
return 0 ;
}
static int F_19 ( struct V_42 * V_43 )
{
int V_22 , V_1 ;
void * V_2 ;
V_2 = V_5 -> V_29 ;
V_22 = F_5 ( V_2 ) -> V_22 ;
for ( V_1 = 0 ; V_1 < V_22 ; ++ V_1 )
F_17 ( V_1 , 0 ) ;
F_18 ( V_22 - 1 ) ;
F_20 ( V_8 . V_44 ) ;
return 0 ;
}
static int F_21 ( struct V_31 * V_32 ,
T_4 V_50 , int type )
{
unsigned long V_51 , V_52 , V_53 ;
int V_1 , V_54 , V_55 , V_22 ;
void * V_2 ;
F_3 ( L_8 ,
V_32 , V_50 , type , F_22 ( V_32 -> V_56 [ 0 ] ) ) ;
if ( type >= V_57 || V_32 -> type >= V_57 )
return - V_58 ;
V_52 = V_59 * V_50 ;
V_2 = V_5 -> V_29 ;
V_22 = F_5 ( V_2 ) -> V_22 ;
if ( ( V_52 + V_59 * V_32 -> V_60 ) > V_22 ) {
F_4 (KERN_ERR PFX L_9 ) ;
return - V_58 ;
}
V_54 = V_52 ;
while ( V_54 < ( V_52 + V_59 * V_32 -> V_60 ) ) {
if ( ! F_23 ( V_5 , F_24 ( V_54 ) ) ) {
F_3 ( L_10 ,
V_54 , F_24 ( V_54 ) ) ;
return - V_61 ;
}
V_54 ++ ;
}
V_53 = 1UL << V_11 ;
for ( V_1 = 0 , V_54 = V_52 ; V_1 < V_32 -> V_60 ; V_1 ++ ) {
V_51 = F_22 ( V_32 -> V_56 [ V_1 ] ) ;
for ( V_55 = 0 ; V_55 < V_59 ; V_55 ++ , V_54 ++ , V_51 += V_53 )
F_17 ( V_54 , F_25 ( V_5 , V_51 , V_32 -> type ) ) ;
}
F_18 ( V_54 - 1 ) ;
return 0 ;
}
static int F_26 ( struct V_31 * V_32 ,
T_4 V_50 , int type )
{
int V_1 ;
F_3 ( L_11 ,
V_32 , V_50 , type ) ;
V_50 = V_59 * V_50 ;
for ( V_1 = V_50 ; V_1 < ( V_50 + V_59 * V_32 -> V_60 ) ; V_1 ++ )
F_17 ( V_1 , 0 ) ;
F_18 ( V_1 - 1 ) ;
return 0 ;
}
static int F_27 ( struct V_33 * V_62 )
{
unsigned long V_63 = V_11 - V_26 ;
T_3 V_64 ;
V_62 -> V_65 = F_28 ( V_40 , V_63 ) ;
if ( ! V_62 -> V_65 ) {
F_4 (KERN_ERR PFX L_12 ) ;
return - V_41 ;
}
V_64 = ( ( V_66 + V_67 - 1 ) & - V_67 ) / 8 ;
V_62 -> V_68 = F_14 ( V_64 , V_40 ) ;
if ( ! V_62 -> V_68 ) {
F_29 ( V_62 -> V_65 , V_63 ) ;
F_4 (KERN_ERR PFX L_13 ) ;
return - V_41 ;
}
V_62 -> V_51 = F_22 ( V_62 -> V_65 ) ;
V_62 -> V_69 = 0 ;
F_30 ( V_66 , & V_5 -> V_70 ) ;
return 0 ;
}
static void F_31 ( struct V_33 * V_62 )
{
F_11 ( V_62 -> V_68 ) ;
V_62 -> V_68 = NULL ;
F_29 ( V_62 -> V_65 , V_11 - V_26 ) ;
F_32 ( V_66 , & V_5 -> V_70 ) ;
}
static int F_33 ( struct V_31 * V_32 ,
T_4 V_50 , int type )
{
int V_1 , V_71 , V_72 , V_73 , V_74 , V_22 ;
struct V_33 * V_75 , * V_76 , * V_62 ;
void * V_2 ;
if ( type >= V_57 || V_32 -> type >= V_57 )
return - V_58 ;
V_2 = V_5 -> V_29 ;
V_22 = F_5 ( V_2 ) -> V_22 ;
V_75 = & V_8 . V_33 [ V_50 / V_66 ] ;
V_76 = & V_8 . V_33 [ ( V_50 + V_32 -> V_60 - 1 ) / V_66 ] ;
V_71 = V_50 % V_66 ;
V_72 = ( V_50 + V_32 -> V_60 - 1 ) % V_66 ;
if ( V_76 > V_8 . V_33 + V_22 ) {
F_4 (KERN_ERR PFX L_9 ) ;
return - V_58 ;
}
for ( V_62 = V_75 ; V_62 <= V_76 ; ++ V_62 ) {
if ( ! V_62 -> V_68 )
continue;
for ( V_73 = ( ( V_62 == V_75 ) ? V_71 : 0 ) ;
V_73 < ( ( V_62 == V_76 ) ? ( V_72 + 1 ) : V_66 ) ;
V_73 ++ )
{
if ( F_34 ( V_73 , V_62 -> V_68 ) )
return - V_61 ;
}
}
for ( V_62 = V_75 , V_1 = 0 ; V_62 <= V_76 ; ++ V_62 ) {
if ( ! V_62 -> V_68 ) {
if ( F_27 ( V_62 ) < 0 )
return - V_41 ;
V_74 = V_62 - V_8 . V_33 ;
F_17 ( V_74 , F_25 ( V_5 ,
V_62 -> V_51 , 0 ) ) ;
F_18 ( V_74 ) ;
}
for ( V_73 = ( ( V_62 == V_75 ) ? V_71 : 0 ) ;
V_73 < ( ( V_62 == V_76 ) ? ( V_72 + 1 ) : V_66 ) ;
V_73 ++ , V_1 ++ )
{
V_32 -> V_56 [ V_1 ] = V_62 -> V_65 ;
F_35 ( V_73 , V_62 -> V_68 ) ;
++ V_62 -> V_69 ;
}
}
return 0 ;
}
static int F_36 ( struct V_31 * V_32 ,
T_4 V_50 , int type )
{
int V_1 , V_74 , V_71 , V_72 , V_73 , V_22 ;
struct V_33 * V_75 , * V_76 , * V_62 ;
void * V_2 ;
V_2 = V_5 -> V_29 ;
V_22 = F_5 ( V_2 ) -> V_22 ;
V_75 = & V_8 . V_33 [ V_50 / V_66 ] ;
V_76 = & V_8 . V_33 [ ( V_50 + V_32 -> V_60 - 1 ) / V_66 ] ;
V_71 = V_50 % V_66 ;
V_72 = ( V_50 + V_32 -> V_60 - 1 ) % V_66 ;
for ( V_1 = 0 , V_62 = V_75 ; V_62 <= V_76 ; ++ V_62 ) {
for ( V_73 = ( ( V_62 == V_75 ) ? V_71 : 0 ) ;
V_73 < ( ( V_62 == V_76 ) ? ( V_72 + 1 ) : V_66 ) ;
V_73 ++ , V_1 ++ )
{
V_32 -> V_56 [ V_1 ] = NULL ;
F_37 ( V_73 , V_62 -> V_68 ) ;
-- V_62 -> V_69 ;
}
if ( V_62 -> V_69 == 0 ) {
V_74 = V_62 - V_8 . V_33 ;
F_17 ( V_74 , 0 ) ;
F_18 ( V_74 ) ;
F_31 ( V_62 ) ;
}
}
return 0 ;
}
static int F_38 ( struct V_31 * V_32 ,
T_4 V_50 , int type )
{
if ( V_11 <= V_26 )
return F_21 ( V_32 , V_50 , type ) ;
else
return F_33 ( V_32 , V_50 , type ) ;
}
static int F_39 ( struct V_31 * V_32 ,
T_4 V_50 , int type )
{
if ( V_11 <= V_26 )
return F_26 ( V_32 , V_50 , type ) ;
else
return F_36 ( V_32 , V_50 , type ) ;
}
static struct V_65 * F_40 ( struct V_42 * V_43 )
{
void * V_65 ;
if ( V_11 <= V_26 ) {
V_65 = F_41 ( V_5 ) ;
} else
V_65 = ( void * ) ~ 0UL ;
return V_65 ;
}
static void F_42 ( struct V_65 * V_65 , int V_77 )
{
if ( V_11 <= V_26 ) {
F_43 ( V_65 , V_77 ) ;
}
}
static unsigned long F_25 ( struct V_42 * V_43 ,
T_5 V_78 , int type )
{
return V_43 -> V_12 -> V_79 [ 0 ] . V_80
| ( ( ( V_78 & ~ ( ( 1 << V_11 ) - 1 ) ) & 0xfffff000 ) >> 12 ) ;
}
static int T_6 F_44 ( struct V_81 * V_82 ,
const struct V_83 * V_84 )
{
struct V_42 * V_43 ;
T_1 V_85 ;
V_85 = F_45 ( V_82 , V_86 ) ;
if ( ! V_85 )
return - V_87 ;
V_43 = F_46 () ;
if ( ! V_43 )
return - V_41 ;
V_43 -> V_12 = & V_88 ;
V_43 -> V_6 = V_82 ;
V_43 -> V_89 = V_85 ;
F_4 (KERN_INFO PFX L_14 ) ;
F_47 ( V_82 , V_43 ) ;
return F_48 ( V_43 ) ;
}
static void T_7 F_49 ( struct V_81 * V_82 )
{
struct V_42 * V_43 = F_50 ( V_82 ) ;
F_51 ( V_43 ) ;
F_52 ( V_43 ) ;
}
static int T_8 F_53 ( void )
{
if ( V_90 )
return - V_58 ;
return F_54 ( & V_91 ) ;
}
static void T_9 F_55 ( void )
{
F_56 ( & V_91 ) ;
}
