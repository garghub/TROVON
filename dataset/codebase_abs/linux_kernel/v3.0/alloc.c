static inline unsigned long
F_1 ( const struct V_1 * V_1 )
{
return ( 1UL << V_1 -> V_2 ) /
sizeof( struct V_3 ) ;
}
static inline unsigned long
F_2 ( const struct V_1 * V_1 )
{
return 1UL << ( V_4 - ( V_1 -> V_2 + 3 ) ) ;
}
int F_3 ( struct V_1 * V_1 , unsigned V_5 )
{
struct V_6 * V_7 = F_4 ( V_1 ) ;
V_7 -> V_8 = F_5 ( sizeof( * V_7 -> V_8 ) , V_9 ) ;
if ( ! V_7 -> V_8 )
return - V_10 ;
F_6 ( V_7 -> V_8 ) ;
F_7 ( V_1 , V_5 , 0 ) ;
V_7 -> V_11 =
F_8 ( F_9 ( V_1 ) ,
V_7 -> V_12 ) + 1 ;
V_7 -> V_13 =
F_1 ( V_1 ) *
V_7 -> V_11 + 1 ;
return 0 ;
}
static unsigned long F_10 ( const struct V_1 * V_1 , T_1 V_14 ,
unsigned long * V_15 )
{
T_1 V_16 = V_14 ;
* V_15 = F_11 ( V_16 , F_9 ( V_1 ) ) ;
return V_16 ;
}
static unsigned long
F_12 ( const struct V_1 * V_1 , unsigned long V_16 )
{
unsigned long V_17 =
V_16 / F_1 ( V_1 ) ;
return V_17 * F_4 ( V_1 ) -> V_13 ;
}
static unsigned long
F_13 ( const struct V_1 * V_1 , unsigned long V_16 )
{
unsigned long V_18 =
V_16 % F_1 ( V_1 ) ;
return F_12 ( V_1 , V_16 ) + 1 +
V_18 * F_4 ( V_1 ) -> V_11 ;
}
static unsigned long
F_14 ( struct V_1 * V_1 , unsigned long V_16 ,
const struct V_3 * V_19 )
{
unsigned long V_20 ;
F_15 ( F_16 ( V_1 , V_16 ) ) ;
V_20 = F_17 ( V_19 -> V_21 ) ;
F_18 ( F_16 ( V_1 , V_16 ) ) ;
return V_20 ;
}
static void
F_19 ( struct V_1 * V_1 ,
unsigned long V_16 ,
struct V_3 * V_19 ,
T_2 V_22 )
{
F_15 ( F_16 ( V_1 , V_16 ) ) ;
F_20 ( & V_19 -> V_21 , V_22 ) ;
F_18 ( F_16 ( V_1 , V_16 ) ) ;
}
static unsigned long
F_21 ( const struct V_1 * V_1 , T_1 V_14 )
{
unsigned long V_16 , V_23 ;
V_16 = F_10 ( V_1 , V_14 , & V_23 ) ;
return F_13 ( V_1 , V_16 ) + 1 +
V_23 / F_4 ( V_1 ) -> V_12 ;
}
static void F_22 ( struct V_1 * V_1 ,
struct V_24 * V_25 , void * V_26 )
{
struct V_3 * V_19 = V_26 + F_23 ( V_25 ) ;
unsigned long V_22 = F_1 ( V_1 ) ;
T_3 V_27 ;
V_27 = F_24 ( F_9 ( V_1 ) ) ;
while ( V_22 -- > 0 ) {
V_19 -> V_21 = V_27 ;
V_19 ++ ;
}
}
static int F_25 ( struct V_1 * V_1 , unsigned long V_28 ,
int V_29 ,
void (* F_26)( struct V_1 * ,
struct V_24 * ,
void * ) ,
struct V_24 * * V_30 ,
struct V_31 * V_32 ,
T_4 * V_33 )
{
int V_34 ;
F_15 ( V_33 ) ;
if ( V_32 -> V_25 && V_28 == V_32 -> V_28 ) {
F_27 ( V_32 -> V_25 ) ;
* V_30 = V_32 -> V_25 ;
F_18 ( V_33 ) ;
return 0 ;
}
F_18 ( V_33 ) ;
V_34 = F_28 ( V_1 , V_28 , V_29 , F_26 , V_30 ) ;
if ( ! V_34 ) {
F_15 ( V_33 ) ;
F_29 ( V_32 -> V_25 ) ;
F_27 ( * V_30 ) ;
V_32 -> V_25 = * V_30 ;
V_32 -> V_28 = V_28 ;
F_18 ( V_33 ) ;
}
return V_34 ;
}
static int F_30 ( struct V_1 * V_1 ,
unsigned long V_16 ,
int V_29 , struct V_24 * * V_30 )
{
struct V_35 * V_36 = F_4 ( V_1 ) -> V_37 ;
return F_25 ( V_1 ,
F_12 ( V_1 , V_16 ) ,
V_29 , F_22 ,
V_30 , & V_36 -> V_38 , & V_36 -> V_33 ) ;
}
static int F_31 ( struct V_1 * V_1 ,
unsigned long V_16 ,
int V_29 , struct V_24 * * V_30 )
{
struct V_35 * V_36 = F_4 ( V_1 ) -> V_37 ;
return F_25 ( V_1 ,
F_13 ( V_1 , V_16 ) ,
V_29 , NULL , V_30 ,
& V_36 -> V_39 , & V_36 -> V_33 ) ;
}
int F_32 ( struct V_1 * V_1 , T_1 V_14 ,
int V_29 , struct V_24 * * V_30 )
{
struct V_35 * V_36 = F_4 ( V_1 ) -> V_37 ;
return F_25 ( V_1 ,
F_21 ( V_1 , V_14 ) ,
V_29 , NULL , V_30 ,
& V_36 -> V_40 , & V_36 -> V_33 ) ;
}
static struct V_3 *
F_33 ( const struct V_1 * V_1 ,
unsigned long V_16 ,
const struct V_24 * V_25 , void * V_26 )
{
return (struct V_3 * ) ( V_26 + F_23 ( V_25 ) ) +
V_16 % F_1 ( V_1 ) ;
}
void * F_34 ( const struct V_1 * V_1 , T_1 V_14 ,
const struct V_24 * V_25 , void * V_26 )
{
unsigned long V_41 , V_23 ;
F_10 ( V_1 , V_14 , & V_23 ) ;
V_41 = V_23 % F_4 ( V_1 ) -> V_12 ;
return V_26 + F_23 ( V_25 ) +
V_41 * F_4 ( V_1 ) -> V_42 ;
}
static int F_35 ( struct V_1 * V_1 ,
unsigned long V_16 ,
unsigned long V_43 ,
unsigned char * V_44 ,
int V_45 )
{
int V_46 , V_47 , V_48 , V_49 ;
if ( V_43 > 0 ) {
V_48 = ( V_43 + V_4 - 1 ) & ~ ( V_4 - 1 ) ;
if ( V_48 > V_45 )
V_48 = V_45 ;
V_47 = F_36 ( V_44 , V_48 , V_43 ) ;
if ( V_47 < V_48 &&
! F_37 (
F_16 ( V_1 , V_16 ) , V_47 , V_44 ) )
return V_47 ;
} else
V_48 = 0 ;
for ( V_49 = 0 , V_46 = V_48 ;
V_49 < V_45 ;
V_49 += V_4 , V_46 += V_4 ) {
if ( V_46 >= V_45 )
V_46 = 0 ;
while ( * ( ( unsigned long * ) V_44 + V_46 / V_4 )
!= ~ 0UL ) {
V_48 = V_46 + V_4 ;
if ( V_48 > V_45 )
V_48 = V_45 ;
V_47 = F_36 ( V_44 , V_48 , V_46 ) ;
if ( ( V_47 < V_48 ) &&
! F_37 (
F_16 ( V_1 , V_16 ) , V_47 ,
V_44 ) )
return V_47 ;
}
}
return - V_50 ;
}
static unsigned long
F_38 ( const struct V_1 * V_1 ,
unsigned long V_46 , unsigned long V_51 )
{
return F_39 (unsigned long,
nilfs_palloc_groups_per_desc_block(inode) -
curr % nilfs_palloc_groups_per_desc_block(inode),
max - curr + 1 ) ;
}
int F_40 ( struct V_1 * V_1 ,
struct V_52 * V_53 )
{
struct V_24 * V_54 , * V_55 ;
struct V_3 * V_19 ;
unsigned char * V_44 ;
void * V_56 , * V_57 ;
unsigned long V_16 , V_58 , V_59 ;
unsigned long V_23 , V_60 ;
unsigned long V_22 , V_61 , V_62 ;
unsigned long V_49 , V_63 ;
int V_47 , V_34 ;
V_59 = F_2 ( V_1 ) ;
V_58 = V_59 - 1 ;
V_16 = F_10 ( V_1 , V_53 -> V_64 , & V_23 ) ;
V_61 = F_9 ( V_1 ) ;
V_62 = F_1 ( V_1 ) ;
for ( V_49 = 0 ; V_49 < V_59 ; V_49 += V_22 ) {
if ( V_16 >= V_59 ) {
V_16 = 0 ;
V_58 = F_10 ( V_1 , V_53 -> V_64 ,
& V_60 ) - 1 ;
}
V_34 = F_30 ( V_1 , V_16 , 1 , & V_54 ) ;
if ( V_34 < 0 )
return V_34 ;
V_56 = F_41 ( V_54 -> V_65 ) ;
V_19 = F_33 (
V_1 , V_16 , V_54 , V_56 ) ;
V_22 = F_38 ( V_1 , V_16 ,
V_58 ) ;
for ( V_63 = 0 ; V_63 < V_22 ; V_63 ++ , V_19 ++ , V_16 ++ ) {
if ( F_14 ( V_1 , V_16 , V_19 )
> 0 ) {
V_34 = F_31 (
V_1 , V_16 , 1 , & V_55 ) ;
if ( V_34 < 0 )
goto V_66;
V_57 = F_41 ( V_55 -> V_65 ) ;
V_44 = V_57 + F_23 ( V_55 ) ;
V_47 = F_35 (
V_1 , V_16 , V_23 , V_44 ,
V_61 ) ;
if ( V_47 >= 0 ) {
F_19 (
V_1 , V_16 , V_19 , - 1 ) ;
V_53 -> V_64 =
V_61 * V_16 + V_47 ;
F_42 ( V_54 -> V_65 ) ;
F_42 ( V_55 -> V_65 ) ;
V_53 -> V_67 = V_54 ;
V_53 -> V_68 = V_55 ;
return 0 ;
}
F_42 ( V_55 -> V_65 ) ;
F_29 ( V_55 ) ;
}
V_23 = 0 ;
}
F_42 ( V_54 -> V_65 ) ;
F_29 ( V_54 ) ;
}
return - V_50 ;
V_66:
F_42 ( V_54 -> V_65 ) ;
F_29 ( V_54 ) ;
return V_34 ;
}
void F_43 ( struct V_1 * V_1 ,
struct V_52 * V_53 )
{
F_44 ( V_53 -> V_68 ) ;
F_44 ( V_53 -> V_67 ) ;
F_45 ( V_1 ) ;
F_29 ( V_53 -> V_68 ) ;
F_29 ( V_53 -> V_67 ) ;
}
void F_46 ( struct V_1 * V_1 ,
struct V_52 * V_53 )
{
struct V_3 * V_19 ;
unsigned long V_16 , V_23 ;
unsigned char * V_44 ;
void * V_56 , * V_57 ;
V_16 = F_10 ( V_1 , V_53 -> V_64 , & V_23 ) ;
V_56 = F_41 ( V_53 -> V_67 -> V_65 ) ;
V_19 = F_33 ( V_1 , V_16 ,
V_53 -> V_67 , V_56 ) ;
V_57 = F_41 ( V_53 -> V_68 -> V_65 ) ;
V_44 = V_57 + F_23 ( V_53 -> V_68 ) ;
if ( ! F_47 ( F_16 ( V_1 , V_16 ) ,
V_23 , V_44 ) )
F_48 ( V_69 L_1 ,
V_70 , ( unsigned long long ) V_53 -> V_64 ) ;
else
F_19 ( V_1 , V_16 , V_19 , 1 ) ;
F_42 ( V_53 -> V_68 -> V_65 ) ;
F_42 ( V_53 -> V_67 -> V_65 ) ;
F_44 ( V_53 -> V_67 ) ;
F_44 ( V_53 -> V_68 ) ;
F_45 ( V_1 ) ;
F_29 ( V_53 -> V_68 ) ;
F_29 ( V_53 -> V_67 ) ;
}
void F_49 ( struct V_1 * V_1 ,
struct V_52 * V_53 )
{
struct V_3 * V_19 ;
void * V_56 , * V_57 ;
unsigned char * V_44 ;
unsigned long V_16 , V_23 ;
V_16 = F_10 ( V_1 , V_53 -> V_64 , & V_23 ) ;
V_56 = F_41 ( V_53 -> V_67 -> V_65 ) ;
V_19 = F_33 ( V_1 , V_16 ,
V_53 -> V_67 , V_56 ) ;
V_57 = F_41 ( V_53 -> V_68 -> V_65 ) ;
V_44 = V_57 + F_23 ( V_53 -> V_68 ) ;
if ( ! F_47 ( F_16 ( V_1 , V_16 ) ,
V_23 , V_44 ) )
F_48 ( V_69 L_1 ,
V_70 , ( unsigned long long ) V_53 -> V_64 ) ;
else
F_19 ( V_1 , V_16 , V_19 , 1 ) ;
F_42 ( V_53 -> V_68 -> V_65 ) ;
F_42 ( V_53 -> V_67 -> V_65 ) ;
F_29 ( V_53 -> V_68 ) ;
F_29 ( V_53 -> V_67 ) ;
V_53 -> V_64 = 0 ;
V_53 -> V_68 = NULL ;
V_53 -> V_67 = NULL ;
}
int F_50 ( struct V_1 * V_1 ,
struct V_52 * V_53 )
{
struct V_24 * V_54 , * V_55 ;
unsigned long V_16 , V_23 ;
int V_34 ;
V_16 = F_10 ( V_1 , V_53 -> V_64 , & V_23 ) ;
V_34 = F_30 ( V_1 , V_16 , 1 , & V_54 ) ;
if ( V_34 < 0 )
return V_34 ;
V_34 = F_31 ( V_1 , V_16 , 1 , & V_55 ) ;
if ( V_34 < 0 ) {
F_29 ( V_54 ) ;
return V_34 ;
}
V_53 -> V_67 = V_54 ;
V_53 -> V_68 = V_55 ;
return 0 ;
}
void F_51 ( struct V_1 * V_1 ,
struct V_52 * V_53 )
{
F_29 ( V_53 -> V_68 ) ;
F_29 ( V_53 -> V_67 ) ;
V_53 -> V_64 = 0 ;
V_53 -> V_68 = NULL ;
V_53 -> V_67 = NULL ;
}
static int
F_52 ( struct V_1 * V_1 , unsigned long V_16 , T_1 V_14 )
{
T_1 V_71 , V_72 ;
V_71 = V_16 * F_9 ( V_1 ) ;
V_72 = V_71 + F_9 ( V_1 ) - 1 ;
return ( V_14 >= V_71 ) && ( V_14 <= V_72 ) ;
}
int F_53 ( struct V_1 * V_1 , T_1 * V_73 , T_5 V_74 )
{
struct V_24 * V_54 , * V_55 ;
struct V_3 * V_19 ;
unsigned char * V_44 ;
void * V_56 , * V_57 ;
unsigned long V_16 , V_23 ;
int V_49 , V_63 , V_22 , V_34 ;
for ( V_49 = 0 ; V_49 < V_74 ; V_49 = V_63 ) {
V_16 = F_10 ( V_1 , V_73 [ V_49 ] , & V_23 ) ;
V_34 = F_30 ( V_1 , V_16 , 0 , & V_54 ) ;
if ( V_34 < 0 )
return V_34 ;
V_34 = F_31 ( V_1 , V_16 , 0 ,
& V_55 ) ;
if ( V_34 < 0 ) {
F_29 ( V_54 ) ;
return V_34 ;
}
V_56 = F_41 ( V_54 -> V_65 ) ;
V_19 = F_33 (
V_1 , V_16 , V_54 , V_56 ) ;
V_57 = F_41 ( V_55 -> V_65 ) ;
V_44 = V_57 + F_23 ( V_55 ) ;
for ( V_63 = V_49 , V_22 = 0 ;
( V_63 < V_74 ) && F_52 ( V_1 , V_16 ,
V_73 [ V_63 ] ) ;
V_63 ++ ) {
F_10 ( V_1 , V_73 [ V_63 ] , & V_23 ) ;
if ( ! F_47 (
F_16 ( V_1 , V_16 ) ,
V_23 , V_44 ) ) {
F_48 ( V_69
L_1 ,
V_70 ,
( unsigned long long ) V_73 [ V_63 ] ) ;
} else {
V_22 ++ ;
}
}
F_19 ( V_1 , V_16 , V_19 , V_22 ) ;
F_42 ( V_55 -> V_65 ) ;
F_42 ( V_54 -> V_65 ) ;
F_44 ( V_54 ) ;
F_44 ( V_55 ) ;
F_45 ( V_1 ) ;
F_29 ( V_55 ) ;
F_29 ( V_54 ) ;
}
return 0 ;
}
void F_54 ( struct V_1 * V_1 ,
struct V_35 * V_36 )
{
F_4 ( V_1 ) -> V_37 = V_36 ;
F_55 ( & V_36 -> V_33 ) ;
}
void F_56 ( struct V_1 * V_1 )
{
struct V_35 * V_36 = F_4 ( V_1 ) -> V_37 ;
F_15 ( & V_36 -> V_33 ) ;
F_29 ( V_36 -> V_38 . V_25 ) ;
F_29 ( V_36 -> V_39 . V_25 ) ;
F_29 ( V_36 -> V_40 . V_25 ) ;
V_36 -> V_38 . V_25 = NULL ;
V_36 -> V_39 . V_25 = NULL ;
V_36 -> V_40 . V_25 = NULL ;
F_18 ( & V_36 -> V_33 ) ;
}
void F_57 ( struct V_1 * V_1 )
{
F_56 ( V_1 ) ;
F_4 ( V_1 ) -> V_37 = NULL ;
}
