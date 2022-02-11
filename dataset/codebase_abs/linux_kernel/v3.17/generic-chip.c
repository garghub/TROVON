void F_1 ( struct V_1 * V_2 )
{
}
void F_2 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_3 ( V_2 ) ;
struct V_5 * V_6 = F_4 ( V_2 ) ;
T_1 V_7 = V_2 -> V_7 ;
F_5 ( V_4 ) ;
F_6 ( V_7 , V_4 -> V_8 + V_6 -> V_9 . V_10 ) ;
* V_6 -> V_11 &= ~ V_7 ;
F_7 ( V_4 ) ;
}
void F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_3 ( V_2 ) ;
struct V_5 * V_6 = F_4 ( V_2 ) ;
T_1 V_7 = V_2 -> V_7 ;
F_5 ( V_4 ) ;
* V_6 -> V_11 |= V_7 ;
F_6 ( * V_6 -> V_11 , V_4 -> V_8 + V_6 -> V_9 . V_7 ) ;
F_7 ( V_4 ) ;
}
void F_9 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_3 ( V_2 ) ;
struct V_5 * V_6 = F_4 ( V_2 ) ;
T_1 V_7 = V_2 -> V_7 ;
F_5 ( V_4 ) ;
* V_6 -> V_11 &= ~ V_7 ;
F_6 ( * V_6 -> V_11 , V_4 -> V_8 + V_6 -> V_9 . V_7 ) ;
F_7 ( V_4 ) ;
}
void F_10 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_3 ( V_2 ) ;
struct V_5 * V_6 = F_4 ( V_2 ) ;
T_1 V_7 = V_2 -> V_7 ;
F_5 ( V_4 ) ;
F_6 ( V_7 , V_4 -> V_8 + V_6 -> V_9 . V_12 ) ;
* V_6 -> V_11 |= V_7 ;
F_7 ( V_4 ) ;
}
void F_11 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_3 ( V_2 ) ;
struct V_5 * V_6 = F_4 ( V_2 ) ;
T_1 V_7 = V_2 -> V_7 ;
F_5 ( V_4 ) ;
F_6 ( V_7 , V_4 -> V_8 + V_6 -> V_9 . V_13 ) ;
F_7 ( V_4 ) ;
}
void F_12 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_3 ( V_2 ) ;
struct V_5 * V_6 = F_4 ( V_2 ) ;
T_1 V_7 = ~ V_2 -> V_7 ;
F_5 ( V_4 ) ;
F_6 ( V_7 , V_4 -> V_8 + V_6 -> V_9 . V_13 ) ;
F_7 ( V_4 ) ;
}
void F_13 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_3 ( V_2 ) ;
struct V_5 * V_6 = F_4 ( V_2 ) ;
T_1 V_7 = V_2 -> V_7 ;
F_5 ( V_4 ) ;
F_6 ( V_7 , V_4 -> V_8 + V_6 -> V_9 . V_7 ) ;
F_6 ( V_7 , V_4 -> V_8 + V_6 -> V_9 . V_13 ) ;
F_7 ( V_4 ) ;
}
void F_14 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_3 ( V_2 ) ;
struct V_5 * V_6 = F_4 ( V_2 ) ;
T_1 V_7 = V_2 -> V_7 ;
F_5 ( V_4 ) ;
F_6 ( V_7 , V_4 -> V_8 + V_6 -> V_9 . V_14 ) ;
F_7 ( V_4 ) ;
}
int F_15 ( struct V_1 * V_2 , unsigned int V_15 )
{
struct V_3 * V_4 = F_3 ( V_2 ) ;
T_1 V_7 = V_2 -> V_7 ;
if ( ! ( V_7 & V_4 -> V_16 ) )
return - V_17 ;
F_5 ( V_4 ) ;
if ( V_15 )
V_4 -> V_18 |= V_7 ;
else
V_4 -> V_18 &= ~ V_7 ;
F_7 ( V_4 ) ;
return 0 ;
}
static void
F_16 ( struct V_3 * V_4 , const char * V_19 ,
int V_20 , unsigned int V_21 ,
void T_2 * V_8 , T_3 V_22 )
{
F_17 ( & V_4 -> V_23 ) ;
V_4 -> V_20 = V_20 ;
V_4 -> V_21 = V_21 ;
V_4 -> V_8 = V_8 ;
V_4 -> V_24 -> V_25 . V_19 = V_19 ;
V_4 -> V_24 -> V_22 = V_22 ;
}
struct V_3 *
F_18 ( const char * V_19 , int V_20 , unsigned int V_21 ,
void T_2 * V_8 , T_3 V_22 )
{
struct V_3 * V_4 ;
unsigned long V_26 = sizeof( * V_4 ) + V_20 * sizeof( struct V_5 ) ;
V_4 = F_19 ( V_26 , V_27 ) ;
if ( V_4 ) {
F_16 ( V_4 , V_19 , V_20 , V_21 , V_8 ,
V_22 ) ;
}
return V_4 ;
}
static void
F_20 ( struct V_3 * V_4 , enum V_28 V_29 )
{
struct V_5 * V_6 = V_4 -> V_24 ;
T_1 * V_30 = & V_4 -> V_11 , V_31 = V_6 -> V_9 . V_7 ;
int V_32 ;
for ( V_32 = 0 ; V_32 < V_4 -> V_20 ; V_32 ++ ) {
if ( V_29 & V_33 ) {
V_30 = & V_6 [ V_32 ] . V_34 ;
V_31 = V_6 [ V_32 ] . V_9 . V_7 ;
}
V_6 [ V_32 ] . V_11 = V_30 ;
if ( V_29 & V_35 )
* V_30 = F_21 ( V_4 -> V_8 + V_31 ) ;
}
}
int F_22 ( struct V_36 * V_2 , int V_37 ,
int V_20 , const char * V_19 ,
T_3 V_22 ,
unsigned int V_38 , unsigned int V_39 ,
enum V_28 V_40 )
{
struct V_41 * V_42 ;
struct V_3 * V_4 ;
int V_43 , V_26 , V_32 ;
unsigned long V_29 ;
void * V_44 ;
if ( V_2 -> V_4 )
return - V_45 ;
V_43 = F_23 ( V_2 -> V_46 , V_37 ) ;
if ( ! V_43 )
return - V_17 ;
V_26 = sizeof( * V_42 ) + V_43 * sizeof( V_4 ) ;
V_26 += V_43 * ( sizeof( * V_4 ) + V_20 * sizeof( struct V_5 ) ) ;
V_44 = V_42 = F_19 ( V_26 , V_27 ) ;
if ( ! V_42 )
return - V_47 ;
V_42 -> V_37 = V_37 ;
V_42 -> V_48 = V_43 ;
V_42 -> V_49 = V_39 ;
V_42 -> V_50 = V_38 ;
V_42 -> V_51 = V_40 ;
V_2 -> V_4 = V_42 ;
V_44 += sizeof( * V_42 ) + V_43 * sizeof( V_4 ) ;
for ( V_32 = 0 ; V_32 < V_43 ; V_32 ++ ) {
V_42 -> V_4 [ V_32 ] = V_4 = V_44 ;
F_16 ( V_4 , V_19 , V_20 , V_32 * V_37 ,
NULL , V_22 ) ;
V_4 -> V_52 = V_2 ;
F_24 ( & V_53 , V_29 ) ;
F_25 ( & V_4 -> V_54 , & V_55 ) ;
F_26 ( & V_53 , V_29 ) ;
V_44 += sizeof( * V_4 ) + V_20 * sizeof( struct V_5 ) ;
}
V_2 -> V_19 = V_19 ;
return 0 ;
}
struct V_3 *
F_27 ( struct V_36 * V_2 , unsigned int V_56 )
{
struct V_41 * V_42 = V_2 -> V_4 ;
int V_57 ;
if ( ! V_42 )
return NULL ;
V_57 = V_56 / V_42 -> V_37 ;
if ( V_57 >= V_42 -> V_48 )
return NULL ;
return V_42 -> V_4 [ V_57 ] ;
}
int F_28 ( struct V_36 * V_2 , unsigned int V_58 ,
T_4 V_56 )
{
struct V_1 * V_59 = F_29 ( V_58 ) ;
struct V_41 * V_42 = V_2 -> V_4 ;
struct V_3 * V_4 ;
struct V_5 * V_6 ;
struct V_60 * V_25 ;
unsigned long V_29 ;
int V_57 ;
if ( ! V_2 -> V_4 )
return - V_61 ;
V_57 = V_56 / V_42 -> V_37 ;
if ( V_57 >= V_42 -> V_48 )
return - V_17 ;
V_4 = V_42 -> V_4 [ V_57 ] ;
V_57 = V_56 % V_42 -> V_37 ;
if ( F_30 ( V_57 , & V_4 -> V_62 ) )
return - V_63 ;
if ( F_30 ( V_57 , & V_4 -> V_64 ) )
return - V_45 ;
V_6 = V_4 -> V_24 ;
V_25 = & V_6 -> V_25 ;
if ( ! V_4 -> V_64 ) {
F_24 ( & V_4 -> V_23 , V_29 ) ;
F_20 ( V_4 , V_42 -> V_51 ) ;
F_26 ( & V_4 -> V_23 , V_29 ) ;
}
F_31 ( V_57 , & V_4 -> V_64 ) ;
if ( V_42 -> V_51 & V_65 )
F_32 ( V_58 , & V_66 ) ;
if ( V_25 -> V_67 )
V_25 -> V_67 ( V_59 ) ;
else
V_59 -> V_7 = 1 << V_57 ;
F_33 ( V_58 , V_25 , V_6 -> V_22 ) ;
F_34 ( V_58 , V_4 ) ;
F_35 ( V_58 , V_42 -> V_50 , V_42 -> V_49 ) ;
return 0 ;
}
void F_36 ( struct V_3 * V_4 , T_1 V_68 ,
enum V_28 V_29 , unsigned int V_38 ,
unsigned int V_39 )
{
struct V_5 * V_6 = V_4 -> V_24 ;
struct V_60 * V_25 = & V_6 -> V_25 ;
unsigned int V_32 ;
F_37 ( & V_53 ) ;
F_25 ( & V_4 -> V_54 , & V_55 ) ;
F_38 ( & V_53 ) ;
F_20 ( V_4 , V_29 ) ;
for ( V_32 = V_4 -> V_21 ; V_68 ; V_68 >>= 1 , V_32 ++ ) {
if ( ! ( V_68 & 0x01 ) )
continue;
if ( V_29 & V_65 )
F_32 ( V_32 , & V_66 ) ;
if ( ! ( V_29 & V_69 ) ) {
struct V_1 * V_2 = F_29 ( V_32 ) ;
if ( V_25 -> V_67 )
V_25 -> V_67 ( V_2 ) ;
else
V_2 -> V_7 = 1 << ( V_32 - V_4 -> V_21 ) ;
}
F_33 ( V_32 , V_25 , V_6 -> V_22 ) ;
F_34 ( V_32 , V_4 ) ;
F_35 ( V_32 , V_38 , V_39 ) ;
}
V_4 -> V_70 = V_32 - V_4 -> V_21 ;
}
int F_39 ( struct V_1 * V_2 , unsigned int type )
{
struct V_3 * V_4 = F_3 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_24 ;
unsigned int V_32 ;
for ( V_32 = 0 ; V_32 < V_4 -> V_20 ; V_32 ++ , V_6 ++ ) {
if ( V_6 -> type & type ) {
V_2 -> V_25 = & V_6 -> V_25 ;
F_40 ( V_2 ) -> V_71 = V_6 -> V_22 ;
return 0 ;
}
}
return - V_17 ;
}
void F_41 ( struct V_3 * V_4 , T_1 V_68 ,
unsigned int V_38 , unsigned int V_39 )
{
unsigned int V_32 = V_4 -> V_21 ;
F_37 ( & V_53 ) ;
F_42 ( & V_4 -> V_54 ) ;
F_38 ( & V_53 ) ;
for (; V_68 ; V_68 >>= 1 , V_32 ++ ) {
if ( ! ( V_68 & 0x01 ) )
continue;
F_43 ( V_32 , NULL ) ;
F_44 ( V_32 , & V_72 ) ;
F_34 ( V_32 , NULL ) ;
F_35 ( V_32 , V_38 , V_39 ) ;
}
}
static struct V_1 * F_45 ( struct V_3 * V_4 )
{
unsigned int V_58 ;
if ( ! V_4 -> V_52 )
return F_29 ( V_4 -> V_21 ) ;
if ( ! V_4 -> V_64 )
return NULL ;
V_58 = F_46 ( V_4 -> V_52 , V_4 -> V_21 + F_47 ( V_4 -> V_64 ) ) ;
return V_58 ? F_29 ( V_58 ) : NULL ;
}
static int F_48 ( void )
{
struct V_3 * V_4 ;
F_49 (gc, &gc_list, list) {
struct V_5 * V_6 = V_4 -> V_24 ;
if ( V_6 -> V_25 . V_73 ) {
struct V_1 * V_59 = F_45 ( V_4 ) ;
if ( V_59 )
V_6 -> V_25 . V_73 ( V_59 ) ;
}
}
return 0 ;
}
static void F_50 ( void )
{
struct V_3 * V_4 ;
F_49 (gc, &gc_list, list) {
struct V_5 * V_6 = V_4 -> V_24 ;
if ( V_6 -> V_25 . V_74 ) {
struct V_1 * V_59 = F_45 ( V_4 ) ;
if ( V_59 )
V_6 -> V_25 . V_74 ( V_59 ) ;
}
}
}
static void F_51 ( void )
{
struct V_3 * V_4 ;
F_49 (gc, &gc_list, list) {
struct V_5 * V_6 = V_4 -> V_24 ;
if ( V_6 -> V_25 . V_75 ) {
struct V_1 * V_59 = F_45 ( V_4 ) ;
if ( V_59 )
V_6 -> V_25 . V_75 ( V_59 ) ;
}
}
}
static int T_5 F_52 ( void )
{
F_53 ( & V_76 ) ;
return 0 ;
}
